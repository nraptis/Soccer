#include "TwistExpander_Bowling.hpp"
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

TwistExpander_Bowling::TwistExpander_Bowling()
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

void TwistExpander_Bowling::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 12082880689505785864U;
        aCarry = 15364303143784884958U;
        aWandererA = 11073514010758328972U;
        aWandererB = 16432343754985149738U;
        aWandererC = 11036441830129985393U;
        aWandererD = 15484522450783728851U;
        aWandererE = 14647476114215751810U;
        aWandererF = 10313345706310685557U;
        aWandererG = 16103766081462649768U;
        aWandererH = 17783823423521474030U;
        aWandererI = 15328106470112210249U;
        aWandererJ = 11211749885989674376U;
        aWandererK = 11918877171718797823U;
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
    TwistExpander_Bowling_Arx aArx;
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
    TwistExpander_Bowling_Arx aKDF_A_BArx;
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
    TwistExpander_Bowling_Arx aKDF_A_CArx;
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
    TwistExpander_Bowling_Arx aKDF_A_DArx;
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

void TwistExpander_Bowling::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 12107672198032734981U;
        aCarry = 15650606419964556776U;
        aWandererA = 10890986606352147002U;
        aWandererB = 18157050610418459233U;
        aWandererC = 14976587911151990176U;
        aWandererD = 16156686772630649686U;
        aWandererE = 15147415145122301447U;
        aWandererF = 12478115849242584525U;
        aWandererG = 10233352613079604634U;
        aWandererH = 17146980834880370115U;
        aWandererI = 15430865797287831335U;
        aWandererJ = 18041470032081571611U;
        aWandererK = 11177343655216304750U;
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
    TwistExpander_Bowling_Arx aKDF_B_AArx;
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
    TwistExpander_Bowling_Arx aKDF_B_BArx;
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
    TwistExpander_Bowling_Arx aKDF_B_CArx;
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

void TwistExpander_Bowling::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBF4EB407A7DD667DULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xBF179C46709CA448ULL;

    std::uint64_t aWandererA = 0x98A2C49FD9A3469FULL;
    std::uint64_t aWandererB = 0xD29853EEF479B341ULL;
    std::uint64_t aWandererC = 0xC49BC1A0D3205296ULL;
    std::uint64_t aWandererD = 0xF618D87CDD68621BULL;
    std::uint64_t aWandererE = 0xA861FBA047B37D74ULL;
    std::uint64_t aWandererF = 0xAA8BD3E9BBD84697ULL;
    std::uint64_t aWandererG = 0xB59DD75365F0F963ULL;
    std::uint64_t aWandererH = 0x9B6096D7B23BBB02ULL;
    std::uint64_t aWandererI = 0xB1F9E776FF62EB12ULL;
    std::uint64_t aWandererJ = 0x9360BF91491278F0ULL;
    std::uint64_t aWandererK = 0xC60B7D9EF172DB38ULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    TwistExpander_Bowling_Arx aSeed_AArx;
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
    TwistExpander_Bowling_Arx aSeed_BArx;
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
    TwistExpander_Bowling_Arx aSeed_CArx;
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
    TwistExpander_Bowling_Arx aSeed_DArx;
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
    TwistExpander_Bowling_Arx aSeed_EArx;
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
    TwistExpander_Bowling_Arx aSeed_FArx;
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
    TwistExpander_Bowling_Arx aSeed_GArx;
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
    TwistExpander_Bowling_Arx aGrow_AArx;
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
    TwistExpander_Bowling_Arx aGrow_BArx;
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

void TwistExpander_Bowling::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Bowling::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 11707231865328335720U;
        aCarry = 17514654520359258175U;
        aWandererA = 9534816523712972112U;
        aWandererB = 13508215774742986423U;
        aWandererC = 9906059959953144828U;
        aWandererD = 17631973043618912594U;
        aWandererE = 9765895754478670330U;
        aWandererF = 17687216387526447941U;
        aWandererG = 17072491926383009879U;
        aWandererH = 9588660320497587340U;
        aWandererI = 9757061565319605073U;
        aWandererJ = 16330460799821905605U;
        aWandererK = 10872631289306440529U;
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
    TwistExpander_Bowling_Arx aTwist_AArx;
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
    TwistExpander_Bowling_Arx aTwist_BArx;
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
    TwistExpander_Bowling_Arx aTwist_CArx;
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
    TwistExpander_Bowling_Arx aTwist_DArx;
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
        TwistExpander_Bowling_Arx aGrow_AArx;
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
        TwistExpander_Bowling_Arx aGrow_BArx;
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

void TwistExpander_Bowling::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 2, 1 with offsets 5246U, 7476U, 4704U, 5724U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5246U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7476U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4704U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5724U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 3, 0 with offsets 510U, 3291U, 5984U, 2800U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 510U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3291U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5984U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2800U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 1, 3 with offsets 826U, 3349U, 4184U, 1888U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 826U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3349U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4184U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1888U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 0, 2 with offsets 258U, 3008U, 5443U, 7866U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 258U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3008U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5443U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7866U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 1, 0 with offsets 1966U, 1879U, 692U, 1835U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1966U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1879U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 692U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 1, 3, 0 with offsets 1568U, 144U, 1973U, 1359U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1568U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 144U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1973U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1359U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 0, 1, 3 with offsets 1625U, 892U, 1616U, 1833U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1625U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 892U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1616U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1833U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 2, 0, 3 with offsets 2042U, 796U, 1648U, 1218U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2042U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 796U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1648U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1218U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1142U, 1608U, 344U, 455U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1142U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1608U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 344U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 455U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Bowling::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 3 with offsets 6909U, 3527U, 4771U, 3929U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6909U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3527U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4771U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3929U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 1, 0 with offsets 4892U, 2804U, 4027U, 5118U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4892U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2804U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4027U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5118U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 3, 2 with offsets 2161U, 6203U, 4120U, 979U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2161U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6203U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4120U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 979U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 2, 1 with offsets 4016U, 1091U, 3485U, 4496U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4016U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1091U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3485U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4496U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3311U, 5723U, 6208U, 7744U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3311U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5723U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6208U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 7744U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 520U, 244U, 371U, 907U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 244U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 371U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 907U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1436U, 1393U, 1928U, 1879U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1436U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1393U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1928U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1879U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1469U, 280U, 1075U, 549U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1469U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 280U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1075U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 549U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 910U, 188U, 765U, 892U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 910U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 188U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 765U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 892U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 0, 3, 1 [0..<W_KEY]
        // offsets: 8U, 220U, 180U, 468U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 220U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 180U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 468U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseASalts = {
    {
        {
            0xC0AC40E60E6ECA15ULL, 0x7C95F8EC0000E92DULL, 0xD1E4C12762634962ULL, 0x1C2C02875AC5D153ULL, 
            0xAEB88B4EF30E3D4EULL, 0x5C954A61D3E36D04ULL, 0xB70BBC3000C874CEULL, 0x00F46FF89AEEE30AULL, 
            0x7734E6A36E5E040FULL, 0x773B24E4D5A588BCULL, 0x361B505D40572D65ULL, 0xD929FC40E4B98523ULL, 
            0x170AC6564A024E8AULL, 0x8C6FEF1516ED4D3CULL, 0xB35FD440592C9801ULL, 0xF8E8E978899A8C67ULL, 
            0xB83E5B9E23C5E531ULL, 0x767A60CC5ED45FA2ULL, 0x97655B661B56589CULL, 0x844E6D683B0BA920ULL, 
            0xB3240454CAD2CBD0ULL, 0xDA1593475AB12648ULL, 0x775A86170FAFF97CULL, 0x99BE8314B0144D48ULL, 
            0x11176D22A2A42226ULL, 0x8408673F86709B77ULL, 0x4B99C2615F879678ULL, 0x0300F8A3E1A76451ULL, 
            0xEE148600FF1E54F8ULL, 0x560CFE7B1F289F51ULL, 0xB9747F3AAA6C7950ULL, 0x01C3C62168866D8EULL
        },
        {
            0x151770A617620BAEULL, 0xCAA67975CE44C30EULL, 0xDC319CFB8C6C47E0ULL, 0x8BCDC4F081A3319BULL, 
            0x9E224DB5A3B799E7ULL, 0x9A82340B2A15EF14ULL, 0x627CACEF7FA4DD12ULL, 0x72D9B2F824829E7BULL, 
            0xB87632E31E652DD1ULL, 0xB1A555AB24241667ULL, 0xBA8EB49B88C31A1EULL, 0x08923D2CF4F5F594ULL, 
            0x703CC40684734AE2ULL, 0xBA64DBF8657A203FULL, 0x2BDEA73D2B5F2288ULL, 0xAB19E8BEE1C37402ULL, 
            0xF8FE0ECBA2DCAE47ULL, 0x28B9C22AB9A90D66ULL, 0x98B56C7E6012D604ULL, 0x1ABBABDBECC5A8E5ULL, 
            0x3901EBFCCB1ADE17ULL, 0x5254119BD118CD7DULL, 0xA30C9E9CED42CDFEULL, 0x23D8C3529DB24291ULL, 
            0x61EE20074A385D56ULL, 0x5FF29433C3423A78ULL, 0x6EE545943BE3F150ULL, 0x66FBB5D99FADF443ULL, 
            0xF04E6609E0DEDA0AULL, 0x84DA7A478A04547AULL, 0x8C00C51F440DF879ULL, 0xAE63BBED3BABF2F4ULL
        },
        {
            0x81ECA36F0E5CBFF7ULL, 0x1F47486C82653CE7ULL, 0xBF0F378FB5607EC2ULL, 0xD81F4853084FA5BBULL, 
            0x794701E701177AA8ULL, 0x3A92A9F3EBEFC66BULL, 0x9D7B1EE52540BFFDULL, 0x35A976C30A9D62AEULL, 
            0x37A226DE8021FF43ULL, 0x5D2E42EF3102C9B9ULL, 0xE13B866A71E87D17ULL, 0x89FF3C2C1E95BD32ULL, 
            0x3D2700AB21AADBAAULL, 0x8C0A360B294EC08FULL, 0x27A9C75F49D56DD6ULL, 0x1639FDC3C53125A0ULL, 
            0x5759A5AFBB06A1D3ULL, 0x7BEAB26BCD615359ULL, 0x7032D8EBC16B4E50ULL, 0xC277451138D5D16FULL, 
            0x20690C293DF33B2FULL, 0x0A8B384CBD5B5ED0ULL, 0xABF14A30433620FFULL, 0x391597BCA7EC7F01ULL, 
            0x8FBEE0219528D8B8ULL, 0x0C6081B76279A6E8ULL, 0xE9BFF62C8E10D36DULL, 0x3901EB523B05023FULL, 
            0x03986D82EDD0D99DULL, 0xF0FF2D1342F399E2ULL, 0x8D23C88651B0FF84ULL, 0xEE060867E79FC0C2ULL
        },
        {
            0x1B7C728467E31396ULL, 0x0516FDA995FF01CFULL, 0xB8F36B03235B7DA8ULL, 0x6D126A4154DEB91BULL, 
            0x386084589AC5B978ULL, 0x1C59A440F1A365D5ULL, 0xA7946809EB4D0036ULL, 0xF414F15DC2B0C443ULL, 
            0xA2DC43DB1CDDE537ULL, 0x55BAD92DD53EE160ULL, 0x08CE2D6D2A8CE4E9ULL, 0x24D3AB2A1BFBBB24ULL, 
            0x32AC622E4E147387ULL, 0x98D425348A585AE2ULL, 0x54F4411D7DCC714AULL, 0x3A26138314854213ULL, 
            0x1DEAFDDF46245640ULL, 0x0311E52A458B3723ULL, 0xA2C825A6EB8E47D3ULL, 0xB96E64D935B63085ULL, 
            0x9A468E8DDBA57019ULL, 0xCFE85A1045100EB3ULL, 0xC2E9B2E6D1DA1034ULL, 0x30DBFC5DA97B864AULL, 
            0x06F9CEF380115329ULL, 0x1DFE9FA25B391D75ULL, 0xE005EB3CBB7E567BULL, 0x20763987D8571143ULL, 
            0x791FDE774DD0651EULL, 0x93C5B867E5524BAFULL, 0x9F0EB665EEB0BF20ULL, 0xD1B399C6784C5EBCULL
        },
        {
            0xA17EFFF5C4FB35A0ULL, 0xC230DE7DA494C03FULL, 0xA0E1A00A3BBD3F0FULL, 0x7C9070AFACCD52CFULL, 
            0x8536E1650EC8B5A4ULL, 0xB9B276080D72BA72ULL, 0x58B2D08E79EA4998ULL, 0xA53382EA7F2B62CFULL, 
            0xFD88237AD67F35FFULL, 0xC24590D4D3F336E9ULL, 0x1A1552B9D272900EULL, 0x882D612ECB2AE4C6ULL, 
            0xBD7DF6734EA5E7F4ULL, 0x1A55980FF34E0DF7ULL, 0x0DE280364A082BF1ULL, 0x411A6DF7C9B7B639ULL, 
            0x4738B509DF150FD3ULL, 0xA721AC596BE2906BULL, 0x076888A60FE42CE4ULL, 0xE671810B79EF60C7ULL, 
            0x6975197C296931A9ULL, 0x663F68FBEB863FEAULL, 0x86DC07D853477671ULL, 0x9BDF43D08B4BB999ULL, 
            0xCCD8A42F88DC9381ULL, 0x60EE891C95CD11C2ULL, 0xC45E8403EF66D271ULL, 0xBF3E53A336A67FBCULL, 
            0xA37DE266EA61BD4BULL, 0xC0C77607FEBEDCC9ULL, 0xDD8909841A86EBA0ULL, 0x6D3B67B34FE12D1CULL
        },
        {
            0x91BF7A17707A0C4DULL, 0xDDC0E16F1EA87A61ULL, 0xCD4350D0FC612B91ULL, 0x5A4E86045BDA2CAFULL, 
            0x5F3ED2CABC9B1D53ULL, 0xB6E67B2D437AED7DULL, 0x3C30E9B5380421CBULL, 0x6AA6992FF4BE9BF5ULL, 
            0xD7AECA95DC2A161CULL, 0x323049A3EB38A37AULL, 0x7451DA72C7DF1B71ULL, 0x0D2895A1754F16C6ULL, 
            0x1BCC0437E3962670ULL, 0x13D4060C864B7A7EULL, 0x5012274903FACCEDULL, 0x9E01B4DF104E358CULL, 
            0x0498AA2E78B20D59ULL, 0x7E3A191677C43A79ULL, 0x9503CA8785FEA6E5ULL, 0xA6DD2C4D7E76A3CCULL, 
            0xD8BC3627E3A960FFULL, 0xBDF6BEF7BFEE8DCDULL, 0x63D41DC3CFBE1756ULL, 0x006084F7A8C02BE8ULL, 
            0x72C035142D531AD7ULL, 0x541A9A02E1CCB146ULL, 0x106C54CD09F46DEBULL, 0xBA6FC72356E8CA99ULL, 
            0x781CDF3DA83747A4ULL, 0x2F072854D3107D99ULL, 0xD80DB26937A4C030ULL, 0xA89CBC97D43487B5ULL
        }
    },
    {
        {
            0x16876B74A9562D81ULL, 0x3B9F4DCF81CA0006ULL, 0xE344F7E05190BEE9ULL, 0x4495BFBB57434752ULL, 
            0x0C380C196A40ACECULL, 0x7F11931EDE4C9B3CULL, 0x936B44A97D6AAB86ULL, 0xBC172129C41A1B90ULL, 
            0x3ECD7E33603A90A4ULL, 0x6C049D6F51073086ULL, 0x2E0E9D7BCF60D5F0ULL, 0x7F1EE14428D0A55CULL, 
            0x6E018943F91B982EULL, 0xF547B807D18D371BULL, 0xEC8FB7C88AFCA1C9ULL, 0x098BD1A32634190DULL, 
            0xDED663F5FD95675DULL, 0x515423727003B0D6ULL, 0xDA4B804EBCBEA069ULL, 0x0F5DE777C417822EULL, 
            0xE0C745EE11531C32ULL, 0x3E20A1F22B44438AULL, 0xC3B78156E6E985F0ULL, 0x867D448A3BA29F54ULL, 
            0x81ED44F5008B8B97ULL, 0x52ABEA36765501D0ULL, 0x932FB43B38C800F7ULL, 0x09626C7DBE36A385ULL, 
            0x9FDDF9C79E38B0F7ULL, 0xB48778B2DCF3D13BULL, 0xF55DF2462FAE3FCAULL, 0x204B1405335478EEULL
        },
        {
            0x8F3D123E03CBF75DULL, 0xE8E07A39FB488AAAULL, 0x21B51D5836E616E4ULL, 0xD9B22E21B4A90363ULL, 
            0x6F0264D914A589BCULL, 0xC647D784CFB2B530ULL, 0xB923F1B983E293EBULL, 0xDFCB1C9BECF74CBDULL, 
            0xAF06C6988112E5E9ULL, 0x7C3801192C4BC11EULL, 0xBDA0CE7B3204A46DULL, 0x9CCE8F401E3D30EFULL, 
            0x2C99D249BB49910AULL, 0x2424567F8991567DULL, 0xDF9CD6093AE40681ULL, 0xAEBF5A049442E7CBULL, 
            0x412DB9C48076854DULL, 0x77C531F7DBE4B883ULL, 0xD40931DD4355E1BCULL, 0x5DFEC5672902C6F9ULL, 
            0x870DFD443748074DULL, 0x21053ACD1839B063ULL, 0x7CCE6B34E5E78713ULL, 0xC7BDA52499CAAB15ULL, 
            0xD9D026162F9047D1ULL, 0x1928B7BB4519DF71ULL, 0x6BA3BAFCF0F05D27ULL, 0xA4629CBDAA7FE18CULL, 
            0xB2B17DB685599C2FULL, 0x2B37B445D88E9157ULL, 0xB4B8CB735CA0D44AULL, 0x0CEB444F53A34AA2ULL
        },
        {
            0x19129BAB8EE9B36AULL, 0x02B565DA93AF2C1BULL, 0x97190AD3E0BD0327ULL, 0xE009F1141CAC4A8DULL, 
            0xE995CF3B6CE9E423ULL, 0x59EC9B0284B7D0CAULL, 0x012ABFB986E03D95ULL, 0x603B28B5787148CEULL, 
            0x03DFC1122B2466DAULL, 0xB11B40E114F3569FULL, 0x3102A4DF11B613A8ULL, 0x4BB5BA1FD3005909ULL, 
            0x05F14BB62339A22CULL, 0x4BF275C00786791BULL, 0x4E65C5282A905307ULL, 0x5DAC744275C3B3EFULL, 
            0x5E3D4922CBC80440ULL, 0xB6CEB175CC598F28ULL, 0x22E1E43AB82288A1ULL, 0xE03932799C48B081ULL, 
            0xAF3BE379AD590354ULL, 0x7356BB3595F5175FULL, 0x37252B4B174797D2ULL, 0x418CFBFB99205D7DULL, 
            0x54CC17B235DA3A1AULL, 0x7339457B80EEB364ULL, 0x159B6990B00C0EA1ULL, 0x3C3E7514826B579DULL, 
            0x4F51A33FD1A8ADFAULL, 0xEF95E04F158C67A2ULL, 0xD7F4E199314974DAULL, 0xFB273FDE897F212EULL
        },
        {
            0xF7764212FE4E4514ULL, 0x852672E8982DEA75ULL, 0x429EDB1B6F45B0E5ULL, 0x5D458821208A745FULL, 
            0x4EEF142EAE9D5781ULL, 0xF1BA301C33023CA7ULL, 0xEF4B01CE27ACADC7ULL, 0xFF80AB5A527A4E17ULL, 
            0x04C05C3FA30FF1C4ULL, 0xDA64F55FA43EB6AAULL, 0xEE0B8C562BAC8133ULL, 0x722A54D47B2AF56BULL, 
            0xA6A9DD91A86DD657ULL, 0xC50D2E6032C45A48ULL, 0x14ECBF824DD7C84FULL, 0x19CD57F5C524A3B5ULL, 
            0xEB869448DF86F46AULL, 0xDC48405D12EE9459ULL, 0x69625119CA5B59F7ULL, 0x946390EE904EFD93ULL, 
            0x10BDDF983AD469BEULL, 0xF3EBC319FD84CA19ULL, 0x15578FABB5BFFF33ULL, 0x9FCC6934AA3F84FDULL, 
            0x2C21D5ADFE80B3EEULL, 0x090F72D0BE2DFE42ULL, 0xD5F126DA250BC26EULL, 0xEC882BE305AAE6C3ULL, 
            0x67BED65B4EECAB4AULL, 0xB549E0548966DF83ULL, 0xEF511082FC91D6D7ULL, 0x0951E8DAB2462CCDULL
        },
        {
            0x5F1E635F39450399ULL, 0x7F0498FE0859726AULL, 0x2C92A531C189C80DULL, 0xB7A7A2CC94B5EE27ULL, 
            0x6CEE0547302A9F9BULL, 0xD418C74633FBF3E8ULL, 0x2B18FA7544014F17ULL, 0xC2227F21AC7612E0ULL, 
            0xB8C31F1B6FB13053ULL, 0x8B9842EB78D8706CULL, 0x437EEBA34E803F34ULL, 0x538021728EE474EEULL, 
            0x5476BF9EBEEBC19DULL, 0x4D13E36A1BCC152DULL, 0x07EA2E938DDF6451ULL, 0x8B006044DA51F54DULL, 
            0xCC5FB8EB32E0C94AULL, 0xFC7E248E0886D65BULL, 0xABD27420F0760918ULL, 0x1E03FCD20092136FULL, 
            0xBE009B27A6996931ULL, 0x634FC2575821EFDAULL, 0x7E0DD362B6AB21DAULL, 0x2656FEDC4F19F164ULL, 
            0x337A3992FE376105ULL, 0xBB8F40E65FCE3610ULL, 0xC1DF51A24BBCBD61ULL, 0x77F3CF0F5EE37842ULL, 
            0x9F096FB42F63EA3FULL, 0xC040B509CDF7D4EAULL, 0xE4954259BBCDD592ULL, 0x8D34BDA6C46FEB17ULL
        },
        {
            0x40E4DAEEEB9C8543ULL, 0x037065D622C16B59ULL, 0xA7D94D674E9AE669ULL, 0x4BF36DB2DF5850CFULL, 
            0x72BD88CDD5461544ULL, 0xCE4269EB89BE3662ULL, 0xFE731116C36BC2EDULL, 0x2927A3CF12118F0BULL, 
            0x7FC37F4B65CDDB03ULL, 0x35DB0358E1CD3134ULL, 0x2A9B65905CB3C06AULL, 0x46F0F08194D5A0DCULL, 
            0x2BFFFF009BCEED3FULL, 0xE9FC578A767ACD42ULL, 0x624B5EB9C1426382ULL, 0xDC731A14D82E76B1ULL, 
            0x91F8256205A9BE9AULL, 0x688E5B0836991AACULL, 0x0933C294CC4C374FULL, 0x7AC6225F12912C36ULL, 
            0x0037B18DCC064105ULL, 0x93BC4A375C7BE40EULL, 0x0EFDE34D71EBD840ULL, 0x6EFF02B6ECCB0D8AULL, 
            0xB63A654D3D5C0BD5ULL, 0xA4927C2E14D3EEAEULL, 0x2952EE6C14B5A91EULL, 0x235D4B4BDAECD282ULL, 
            0x1C9AF844BD048D39ULL, 0x322FC49B29290769ULL, 0xDB1EC4447B9F8F01ULL, 0x2616F5764537501CULL
        }
    },
    {
        {
            0x9798F98122EC2B6AULL, 0x9FB21FF5FAEFC611ULL, 0x55FCBDA5475F22B7ULL, 0x67B0354B93960E77ULL, 
            0x90C7778D7F1D5445ULL, 0x7D1741CA58D571F6ULL, 0x1874E1BBB969C896ULL, 0xE09D5D0A9867E98CULL, 
            0x94FA94A0A15FE79AULL, 0xA5B0E4DAFECAE1C8ULL, 0x92CA99404692CCA2ULL, 0x86ABD7B57BC8CA9BULL, 
            0xA4D2740714BC331EULL, 0xBA2252EB7F45BD55ULL, 0x1D8DA28D41BB7BBBULL, 0x28FFB17A604E2692ULL, 
            0xC11361346612D4B8ULL, 0x96DA29FC63727868ULL, 0xB3D372E1FE1E2143ULL, 0xD7B9BC3A5ABA4849ULL, 
            0xF491AD4E6C32CFF4ULL, 0x748B3B44E3B90EAFULL, 0x1BD4191F60730FE8ULL, 0x3E64C7DF42EB9500ULL, 
            0x454F86E253E5D406ULL, 0x606ABEB283D506B8ULL, 0xE936A9941F5F06E4ULL, 0x140E9A89B96BF44AULL, 
            0x32E605DBE6B8BBD9ULL, 0x227CD39BB8AAE92AULL, 0x25B2F927A0C07BACULL, 0xD0531E4B6CB5B042ULL
        },
        {
            0x4380618265311369ULL, 0x9C7EE0C0A5F6A42EULL, 0x3D85C9DEF98D0F10ULL, 0xF45E45BE1B6E39EBULL, 
            0xABB4D9492DC99709ULL, 0x1AED4FBE5D347CAEULL, 0xFCF5603A39808878ULL, 0x7F4BBF877D8BB4B6ULL, 
            0x036E11D0035BF954ULL, 0x44850024E6BF5B52ULL, 0x395020A689C5C785ULL, 0x1AAD4361E36AD651ULL, 
            0xF9E54C2C255C102DULL, 0xCA2088CCC026A3D3ULL, 0x78CE55EABC07B585ULL, 0xF2D611E659F86E16ULL, 
            0x37F3DC9CBE89821EULL, 0x62C4389A5F20FC73ULL, 0xD7513DFB0F94A75EULL, 0x0C316C8DE3729CD2ULL, 
            0x3D94D74AF328603AULL, 0x64CB013096322E5DULL, 0x0C503D0BE5E386F2ULL, 0xB1377735F17FE261ULL, 
            0x8247AEE887624C54ULL, 0xEAAE7ADEBC358DF6ULL, 0x86F9CC603F19776DULL, 0x23FF8477608723F7ULL, 
            0xA7E7F6BCC5B03DCBULL, 0xB02BE2FF9187BA18ULL, 0x8383A0C81E27FF69ULL, 0xD3B74EACB287DC92ULL
        },
        {
            0x40C8E4FF0A08797BULL, 0xC8BF2E28DF7882C3ULL, 0x91761AF43DE494E2ULL, 0xF3E70AD9C5719DFFULL, 
            0xAB2F8831AEA8E972ULL, 0x41C9C0A6E7113217ULL, 0xD100D46BC5460AB9ULL, 0xC6CB849BE013ACE5ULL, 
            0x24CC4FFDB7C65C6EULL, 0xBCAB9D386A3674A1ULL, 0x571067FE2C39AEC0ULL, 0xAAE07C2E23680969ULL, 
            0x820CC035A5432FEDULL, 0x2DAAD50EE46E7BF8ULL, 0x0D44CF6F450B8FE9ULL, 0xCD91454A3189F0A4ULL, 
            0xB2C6E8EC52761C77ULL, 0xE1ADFF2A761FCADEULL, 0xE9AD5B3EC46168D6ULL, 0xE19B130E1DD57D65ULL, 
            0x0AC7027D84110A90ULL, 0xE53902F269141EBDULL, 0x64765B8AEC1F1A0BULL, 0x11076B65162A1447ULL, 
            0xC048F6027B7E9DA3ULL, 0x20402CED26F06074ULL, 0x71CBA4B4E4096393ULL, 0xEF4FD57770F9FDD3ULL, 
            0x6A88E659D02E5BF6ULL, 0x10AB1EF9837E4551ULL, 0x41FE5196F50CEB05ULL, 0x9511AAA342036EE5ULL
        },
        {
            0x32B0E94902CF97EEULL, 0xCB70161BFDF8D652ULL, 0x5CFAAB4E0B9C9A41ULL, 0xF25459CBACCA4131ULL, 
            0x96453F791240E3B6ULL, 0x0D33DDBE14B5DD02ULL, 0xFB2E554D3C343110ULL, 0x8322465EE9A13F85ULL, 
            0x15D950BD7CB59005ULL, 0x730985CD2FCCC6CFULL, 0x324A4653211EE67BULL, 0x06828405C2BFA97CULL, 
            0xB1AB9162557E7FE3ULL, 0x32EDBFAB1A429ECDULL, 0x6550EAA1875A972CULL, 0x3E942E1CDC259751ULL, 
            0x13F3D8DF0D6E37A8ULL, 0x6F00F037B4635A95ULL, 0x2D0B1AC78AB7CC57ULL, 0x4DDF6CF97CFB18DAULL, 
            0x535FFE9758A190C4ULL, 0x55EE94342C1A3CF7ULL, 0x8E0269723BE837F1ULL, 0xFFBF4A95F8A6F692ULL, 
            0xDD6283E764591228ULL, 0x4D8F68B5A273C5B3ULL, 0x220786DEB547FE5CULL, 0x0729054E5F693D76ULL, 
            0x04C69A4098BD335EULL, 0x714EDA9FCA2677E1ULL, 0x6F4E74F0A42117C5ULL, 0x5C5A64D1EAFF1EA6ULL
        },
        {
            0x2AEE7C51BB22F972ULL, 0x9BC78A3833AB0D8EULL, 0x6EB2E46B6C0E123DULL, 0x473B97F512066CCCULL, 
            0x3391943AF29CF507ULL, 0xE93638ABC879BD7BULL, 0x7F88D1305F6929C6ULL, 0x2FA4A6B7D775FD74ULL, 
            0xCFFB09710168204EULL, 0x548358619614E73DULL, 0x90B192FC989E9D1EULL, 0xFA561F7A2B949F2EULL, 
            0xF004D8DB3218D9ABULL, 0x0951668E64B3387CULL, 0x519B5CEEB40941B3ULL, 0xC46C8122C38A307AULL, 
            0x68EE61699D67FE56ULL, 0x23D5CCDA8591B805ULL, 0xD5AB9FC0206A83ADULL, 0xFA9B4C8FEBF5C9FEULL, 
            0x5E4A92FFCB419F29ULL, 0xA94F35EEAFB4DC77ULL, 0xA376CC4C47CCAA5EULL, 0x3D9DA1E20C6467A7ULL, 
            0x3F5D369838E43234ULL, 0xC1F6821B30870B6BULL, 0xDEA1BA1230963B15ULL, 0xD25E4F094514E1F9ULL, 
            0x00C23A734D17AA00ULL, 0x227908005311D0A9ULL, 0x0303D5EF13369156ULL, 0x9DC2299D1EE142E1ULL
        },
        {
            0xC96A0DE01F3699FEULL, 0x4818983981B7AC5DULL, 0x28191469D664CEDBULL, 0xA2CC8DA461BB2D61ULL, 
            0x50DD4D2F9450D61DULL, 0x74CF84C63A9B7114ULL, 0x1089968EF11B2198ULL, 0xEDBF3E5792F614B9ULL, 
            0x9B2278E3197368F1ULL, 0x9C9104FE3C5D2C92ULL, 0x562947ADFFC8AD86ULL, 0xB13427F595228850ULL, 
            0xE5C9A17C8D0F0EECULL, 0x696B5603EEF0A3FBULL, 0xF2A018C5290470CAULL, 0xC378B98C5C4E928DULL, 
            0x59F020CA3F8E0305ULL, 0x8901C4FAC1CE13B3ULL, 0xED2A49268C4C04F7ULL, 0xB81CDA9CEB56C97EULL, 
            0xFCC06021CF5368FEULL, 0x4398092E60AB3814ULL, 0x03C96E4DB7BA3E81ULL, 0xF6AF0C33F80DDE91ULL, 
            0x64CD6E610C7278DCULL, 0x67B4B015EB403A94ULL, 0x1FD7AD1B4DD198C3ULL, 0xEDDB4C5D59C24BF5ULL, 
            0xEDE916B06C36E5D0ULL, 0x6674576D81ED7C46ULL, 0xD43799A5F0D5EC16ULL, 0x52A533E44E647EFEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseAConstants = {
    0xFAB3B9CAA965501FULL,
    0x7B1FB85942E8CDA6ULL,
    0x41B9D9F768FA59CEULL,
    0xFAB3B9CAA965501FULL,
    0x7B1FB85942E8CDA6ULL,
    0x41B9D9F768FA59CEULL,
    0x15916115F14A9AB2ULL,
    0x8FD0146A29E7258DULL,
    0x6A,
    0x9D,
    0xB3,
    0xC1,
    0xEF,
    0x49,
    0x71,
    0xB8
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseBSalts = {
    {
        {
            0x7751F7DCA1AA2264ULL, 0x994A01F91F5E4653ULL, 0x4BDD658CABE9E5F8ULL, 0xEA1DE6F3E71698D7ULL, 
            0x9C885009DB133DE1ULL, 0x78AB39E2615F52C3ULL, 0x4EB71085967C4C02ULL, 0x3E6938BA828DC171ULL, 
            0x7BB31C449A9D3641ULL, 0x2ED0E63346C11AE8ULL, 0x2277889A4E890044ULL, 0x14E105474F956CA8ULL, 
            0x18D7FD00CA9E8A8BULL, 0xFCFFA6E0459D519DULL, 0x25456D12679A1017ULL, 0x8A7C0F069FDAD8D7ULL, 
            0xA424FA81B5884356ULL, 0x13F6FCD2B55C2321ULL, 0x2333EA6C9C88879DULL, 0x7934AE01DD6F3346ULL, 
            0xF6FC63A7530C9089ULL, 0xE019B79B9BBCB2F4ULL, 0x5BDF8F673DDA2E74ULL, 0x873939EACE47A445ULL, 
            0x46E42C1F2EA17452ULL, 0x9BF2C72E32B85C6AULL, 0xC77EED90BD620478ULL, 0xA8CB09EBF713D5E6ULL, 
            0x944E0F5D1DE9A758ULL, 0x9D96B48E0127231CULL, 0x4DBA4419155C4FDEULL, 0x414EF984CBB26E4BULL
        },
        {
            0xBD981501F3CC2288ULL, 0x6217D4254F908DD1ULL, 0x05ECDACCD40BB108ULL, 0xC974690A1451B48FULL, 
            0xA418AF00CA60F00FULL, 0x20107727AC30BDD7ULL, 0x5DBCF49BC1D29C92ULL, 0x08EBDE06FA816BB5ULL, 
            0x44FFEC89240F7A22ULL, 0x02BE0C522A34BD68ULL, 0x1D43F352A579C4FAULL, 0xEFFA99F43C44FBAFULL, 
            0x16A332F9FDB5F088ULL, 0xCF47217D677F2BD0ULL, 0x170FE6C3D9830B31ULL, 0xD2E0E0C7A663345FULL, 
            0xD1C25BD23185774FULL, 0x4A739BAE41BB559AULL, 0x920824B4F5DE1958ULL, 0xB569924FC29B63F9ULL, 
            0xD001348CF434315AULL, 0x9814430FEC7DF192ULL, 0xFC3539148C7C9F1AULL, 0xA2EA531BC6046DB6ULL, 
            0xCF0105083246DAB3ULL, 0x5C1A0E6CF7A2AF15ULL, 0x8F0F5CF4383971A8ULL, 0x1B5C3456C7E6ED8EULL, 
            0xD3723F11F1BED38FULL, 0xC29B2D9B1E5BA868ULL, 0xF9B168D506DBA038ULL, 0xA4009BB80237E78CULL
        },
        {
            0x2EEAB7076406A305ULL, 0xB159232EF45EED86ULL, 0x301551A3359EBDBBULL, 0x7CA0D3F5B51D531FULL, 
            0x5147E03355FE26A1ULL, 0xF6085785CB47B04BULL, 0x00F5EF5BD61860CBULL, 0x4183547E4856B955ULL, 
            0xE4D6762D95F373CEULL, 0x902933AE2E5807EBULL, 0x3CA786F1340290A1ULL, 0x6598C33A51B00E57ULL, 
            0x646A0BC61FEE8707ULL, 0x9AB9A706CEF1BBB9ULL, 0xF80B4EA3E9568D8EULL, 0x859C61D4AD8F7F2EULL, 
            0xE1AF1079F6116DA1ULL, 0x07A70E81C73C5035ULL, 0x6BA60B462B351C88ULL, 0x7868287E39413713ULL, 
            0x5F22F117A4CD52C0ULL, 0x93295AE775B3BE84ULL, 0x80A77A08B0172EC7ULL, 0x6461005126FBE5ABULL, 
            0x5AF164E3410767CDULL, 0xEE83CB870C83BE83ULL, 0x8F54836AD51D15CAULL, 0xD171A0E287E50609ULL, 
            0x64060580870B689EULL, 0xF5E9F7962704FAEAULL, 0x94A672FA199555B7ULL, 0x0F87C4BFF9CC2D2BULL
        },
        {
            0x70C171F19830EAFCULL, 0xE7E6FF9F45A57E3AULL, 0x342E06A3F2E5C0C9ULL, 0xEFCEA1A9E36D0E44ULL, 
            0x4F3ADC04D33D51E9ULL, 0x5AEE4AD1E046AB56ULL, 0xAB10CED19CFBD64AULL, 0xA3CA348D297C20C0ULL, 
            0x534AD3ECE21F9EF7ULL, 0x87520C7237DDB5FBULL, 0xB45395E408653052ULL, 0x98D147909B6DB3F3ULL, 
            0xB5DBA9B5FC94C066ULL, 0x8BD3565CB64E4314ULL, 0x24F4755B04B91F26ULL, 0x2E03BD6270F90F36ULL, 
            0xF3AFE78509A04DCCULL, 0x975477865E6BA5B3ULL, 0xA6F1BD21001924C7ULL, 0x9DC089BAD3EDCEBCULL, 
            0xDF26B8FBBAB983BBULL, 0x6300BFF8996C0F3AULL, 0x3F467CFE8F234D8AULL, 0xCAD7B9EC0940A3DBULL, 
            0x0E5513388A821AEAULL, 0xB4BAB6F28BE8CF68ULL, 0x7C389238B1C9C136ULL, 0xBB8E28D83446531EULL, 
            0xADE902CC51EC83D6ULL, 0xC35FF9C61BE9622AULL, 0xDFE268D4DDC0A337ULL, 0x583B780EC5AC865DULL
        },
        {
            0x7C4F9578AC0C3144ULL, 0x46F95A51971F2A4BULL, 0x48FDDB96162B8C0CULL, 0xEE302629EB0D12A5ULL, 
            0x6B7C782C5896A9C6ULL, 0xDCCBFEF77DC57E58ULL, 0x095BC720BAC2CA96ULL, 0xD2F0C7C6F4D88C83ULL, 
            0xFED81F34031299DBULL, 0xBA03479B1182EB40ULL, 0xF18931003E7DBCB5ULL, 0xEDE11591D08E08DAULL, 
            0x6FB8190A4AA90206ULL, 0x33C2987FF472A3D7ULL, 0xDC9857512BAE1C96ULL, 0xC771419A2DF5738BULL, 
            0x5201FAB7649E558EULL, 0x332A07A4EC748419ULL, 0x736873AB41B5D037ULL, 0x95D31AE7E7E0A9A9ULL, 
            0xDFA270E60E01053AULL, 0x215A9E6B9F9D5239ULL, 0x1E4AEDE715616565ULL, 0x8874E26914CC085CULL, 
            0x1ECFAB4AA049EAD4ULL, 0xC318D48EB812ED1BULL, 0x8868A3037EC987DCULL, 0xA72F87E451574E5EULL, 
            0x75736E1011BEDDABULL, 0xAB9C2A807CB1344AULL, 0x7EEB8C1ECDB07757ULL, 0x40A4705EBCDD3797ULL
        },
        {
            0x8AFAF3AE23A5ACF8ULL, 0x2A4BA292E1915870ULL, 0x227F1AEE5E489DE6ULL, 0x40700E8832DE3E90ULL, 
            0xC6C3EE128490B1CFULL, 0x70F3045B9C37DF7EULL, 0x5A6DAC41814925C8ULL, 0x99A8A90431FAB318ULL, 
            0x77AD8D790A7B3DF8ULL, 0xA52CD501782BCDB9ULL, 0x528A0EA9CCE0DE3EULL, 0xB22BD6F0FE071047ULL, 
            0xA2B24EC54864FAC4ULL, 0x57ADE3DC3D9329E4ULL, 0xBFD486F26DD7BBB1ULL, 0xA3254BA2E3DDEDA2ULL, 
            0xE0D72BA4C57BB311ULL, 0x67BDCE746418DE5DULL, 0x17688097A9857707ULL, 0xF2A41078089BF200ULL, 
            0x3B48159E23306496ULL, 0x63EA909A12532AB9ULL, 0x00C9978FD6603E6BULL, 0x08D68CD6934D093BULL, 
            0x3E5A87EA56F8749FULL, 0xEF0961ACF371A293ULL, 0x2F54BA6D5DE1C68FULL, 0x21DB335C6A30E8C9ULL, 
            0xE88ECC332CF5B3BDULL, 0x8ED787125489A199ULL, 0xD3ABA54D78A2A556ULL, 0x8759F60490DEC4E4ULL
        }
    },
    {
        {
            0x926C9F675B79123AULL, 0x0446D9D6C9C153C7ULL, 0x572DE21BCCCB1F70ULL, 0xBAF2AAAFBFBAD1D0ULL, 
            0x31F92B7C4F0C0D5BULL, 0x30AE7FFDFE8855CCULL, 0xDA4FFE48766049AEULL, 0x9A8D757BF4F1C6ECULL, 
            0x28B69C4214D3127EULL, 0x8E77058FC66E7288ULL, 0x402DB022D0CFEE1FULL, 0xF4E70CFEACF3D729ULL, 
            0x19A2CCA705B99151ULL, 0x6254D7C82D4575DCULL, 0x8F541822057E9C55ULL, 0x6B73C11441579783ULL, 
            0x3C171378C180F0B4ULL, 0x5F8CBD01B87BD633ULL, 0x9960F52B8C350064ULL, 0x9A03415A23B3D72BULL, 
            0x9AD6327278BDDE9DULL, 0x62D6E3BB4BCFA942ULL, 0x948EC10CDBBAA75FULL, 0x3B177A75B8AEFE60ULL, 
            0x5F13F1652165B6EEULL, 0xE6F7255AE3577975ULL, 0x052FB63DB8D34339ULL, 0x6AC047A711A6B8A3ULL, 
            0xCED12675404E42D7ULL, 0xEEF3F159F9578CECULL, 0xDDA421F1A97FDFB3ULL, 0x9190ABA10AEE0EC1ULL
        },
        {
            0xA65DC0004A28E9B1ULL, 0xC76455551B7B017CULL, 0x7F9E951E65A80948ULL, 0xC65DC33541100143ULL, 
            0x09DBFB46451CA4E1ULL, 0x5326A5430B3087D9ULL, 0x8D3C27F7F45BD278ULL, 0xBA85A82A5F40CA60ULL, 
            0xDC7759F19FC6D0F0ULL, 0x6D0116D09AEF9BE3ULL, 0xEABCBFD7D51CEC4AULL, 0xF1670E66B1EEC534ULL, 
            0x8F54D4B3D1B1BD12ULL, 0x77B15E6AA4061351ULL, 0x0DDC640D5B8A456BULL, 0xB87821009448C002ULL, 
            0xAD76D02DCEB7BDA2ULL, 0x4572B36F8292A7CBULL, 0x34B6132FC09C263CULL, 0xCDF4CF509F147CDBULL, 
            0xD530B7FDCD78E45DULL, 0x08563416A87E9300ULL, 0x1AF90FB827FC1957ULL, 0x2E73674926E3C88CULL, 
            0x485E6F61443A8B12ULL, 0xD7A91766B189C2F6ULL, 0x023437001C11B2EFULL, 0x58BCD9718C99E5B8ULL, 
            0x01050C957C1E3578ULL, 0xD6A4E3E45DFD694CULL, 0xD9AB982B3F08E780ULL, 0xE80DC0470847DA04ULL
        },
        {
            0xD41F124AF795D551ULL, 0xFE181D1FB32AA6AFULL, 0xDA9D89E6F07E3870ULL, 0x04D5CADB4E0F566CULL, 
            0xCD6D6B8F4182BCCDULL, 0xCBE16C71A0A18334ULL, 0x277393AEAABFC1F0ULL, 0xEE5AD8AB5EC6906CULL, 
            0xEB0BDA49A5BEA0CFULL, 0x5D92D4554B343F16ULL, 0x76FA33DB90E6FAF1ULL, 0xB438BEC4A60504A4ULL, 
            0xCE5BD75F0731EA6BULL, 0x4B60EFA0384F4354ULL, 0xAD493DCEFB96CDA5ULL, 0x08EE633D8384D0B1ULL, 
            0xCB8AB30F2CF100C7ULL, 0x786D2420BB552626ULL, 0x2D9AA1EF6019E23BULL, 0x03E6908546212347ULL, 
            0x28E5BF5B396CA7C0ULL, 0x965B1DBA745F4521ULL, 0x0EEC66BB7E56FAA1ULL, 0x8D75455A7A960F6BULL, 
            0xB2A11981450C43D2ULL, 0xADF3D5B7CDE48A7DULL, 0x198D6879210A809AULL, 0xFF00716FD4E20EDBULL, 
            0x35191DB6C36BC108ULL, 0x54C3F60942DC2554ULL, 0x2C684A07082EFC92ULL, 0x2E6E7C10FBBEC93BULL
        },
        {
            0x27981E576C971B2BULL, 0x4B2027A9F8093604ULL, 0x13D7659816CE23D7ULL, 0x0268904516285A88ULL, 
            0x2E30E0FB8C9E1B17ULL, 0x6D554BC759115C96ULL, 0x6B93A285FB388955ULL, 0x4A82C31306E5B583ULL, 
            0x295C74A87CDAABF9ULL, 0x7C448DC5030E8170ULL, 0x76AD44E473EBA102ULL, 0xD421162B9F01F4A5ULL, 
            0x0EAB02A69DA4E100ULL, 0xBC297E747C20D273ULL, 0x534B3ADCB0E3E1EFULL, 0x39772A720FB8B0EBULL, 
            0x9ABC196072FA8FCDULL, 0xA62C2AFAC07DF5EAULL, 0xDC4376C904CB42A7ULL, 0xFD12BB5DE7A8C593ULL, 
            0x58E29BDD30285F94ULL, 0xA6926F7F9095FDDFULL, 0xEBD4C6E4EC2BFF1FULL, 0xABBBC2E76448CD91ULL, 
            0x76C3B2CB11B9E187ULL, 0xCC6A893CCA2F23E9ULL, 0x201F2EA0437883B1ULL, 0x4F705C6B664C3229ULL, 
            0x6CE000268C0AAF4DULL, 0x6FF515EEB63B6B21ULL, 0xD3A979C3A1E27046ULL, 0x2ED53186BEF5EFA4ULL
        },
        {
            0xF3A0432909D66993ULL, 0xC463089C8207BC35ULL, 0x8F2FEF88DF613462ULL, 0xB50D3937003F96AFULL, 
            0x38E0F214FCD3E9CCULL, 0x95D9E421C1DCA69FULL, 0x353777407E871A87ULL, 0xD06B26559953162AULL, 
            0x7CBD98E9473B1AABULL, 0x93670E04F2D7C8FFULL, 0x4928E56F906357C8ULL, 0x7A25EFCAFF7280B6ULL, 
            0x25635B22363B1B0CULL, 0x3C39567677F5E841ULL, 0x9A6289A51316452BULL, 0x9DE67C89D2AB8865ULL, 
            0x9B24FB6144D7C283ULL, 0xA264857187F5546FULL, 0xA12B4CCEEC9D8772ULL, 0x0D25E8F6C578FE36ULL, 
            0x80910F8667E2ADEEULL, 0x8CB4495C3F41A806ULL, 0xB0136DB0B392DB02ULL, 0xAEB33971A1EB0342ULL, 
            0x4AEF19A90123B415ULL, 0x7ADC959E6CC633F7ULL, 0x18DB8D89B57FFF29ULL, 0xB11F0A5095AC8FA8ULL, 
            0x826EAC8323A5F32FULL, 0x386773EDAD011E56ULL, 0x1C528E1444B3FD51ULL, 0xB5857BD161858D8BULL
        },
        {
            0x4FB8A691E93AA882ULL, 0x4DADBBC42D79D0CCULL, 0x9A55ABDA89158A67ULL, 0xE8FBB82DFC7143D2ULL, 
            0x45311629A089BE0AULL, 0x7E64B6A515A34FDCULL, 0xF99FE554FF6A0FDFULL, 0x96F8D2AD56BB0A47ULL, 
            0x549A21CE742A33B0ULL, 0x5FEBA22EC81DEDEEULL, 0xEC3FE52EB4A66905ULL, 0x06AD7F981A3D5A1FULL, 
            0x6C5BF3F15B8BDDEBULL, 0x1EFA362DB6480C66ULL, 0xFC88694BC7770A8BULL, 0x26E852B0B44E1DA8ULL, 
            0xF259E531CCC3A58CULL, 0x3E4915634317F9D6ULL, 0xC79AF97A963E6118ULL, 0x5694DF6F7736D8C7ULL, 
            0x2F2F87C0E1F2F076ULL, 0x7F8BBFABB70E93EAULL, 0x5F0B7EFA3917F4F4ULL, 0x77697A6404E0F6FCULL, 
            0xFF6C248EBA2F1CADULL, 0x9A943A6C09141CBFULL, 0xA4B1B4CFF51FF504ULL, 0x32932E38E195BCADULL, 
            0x6FF6D96256ADB2CBULL, 0x779CF22258949681ULL, 0xA38BAFD651981523ULL, 0x1863CB4F1CD52B05ULL
        }
    },
    {
        {
            0xCEE2EC11D7D1AE30ULL, 0xE04046D93A3D1C99ULL, 0xC0656F3F6B0B2D7DULL, 0xC51E818DBB2BC7F6ULL, 
            0xB590B0931064F22FULL, 0x58620D60749E2A6BULL, 0xC0AE9A01B3A5523CULL, 0x0A8665DA147153FCULL, 
            0xD71FC2C050840D47ULL, 0xD26DF12132D3976EULL, 0x427D2599997D2D93ULL, 0xC58D0CD98FEFC3E4ULL, 
            0x662DBB6C6D876C3EULL, 0x7810A0A2A5397A6CULL, 0xF02F03BBABBCB0F5ULL, 0x253085E0C933D810ULL, 
            0xC836198620036F72ULL, 0xD550A229BC172BB4ULL, 0x33350DB1DE32E1D0ULL, 0xBA6CC94248EB5E9FULL, 
            0x56218C30AC5773A4ULL, 0x1DD4C4913173D27CULL, 0xE156C18E5AEF5F51ULL, 0xCB5DD2778BB53AFEULL, 
            0x1B1BB12664C803D3ULL, 0xC84FC607F714D30BULL, 0x13E9CA5211CA1D57ULL, 0x9A3171C5EF2A8D66ULL, 
            0x0F580983B4D95B4EULL, 0x31B99803A1A59E80ULL, 0xE7FEF8F02FA2B53EULL, 0xEE8A775AE4129338ULL
        },
        {
            0x6CA30E5DBBEC4C3EULL, 0x3FB0EAE715A82327ULL, 0xE94018EE1D332E05ULL, 0x2828E6DC165A2948ULL, 
            0x6F47E9B076B80C2EULL, 0x586644392191940DULL, 0xE6A8A2B4DD5C57CFULL, 0x58E5DBFF646A40C0ULL, 
            0x473BB57E329A9F7EULL, 0x6210409B524BA109ULL, 0x286C0F384837029CULL, 0x3094D11D5D154AEDULL, 
            0x17316E49B6562395ULL, 0x3069CCC7899C55CDULL, 0x614A3872775B4F74ULL, 0xEC8897891C633B6CULL, 
            0xA34DE62B6AC9BB17ULL, 0x5D230C901F1182E3ULL, 0xC27CA0668F0D7878ULL, 0x177AF97F2A3E8112ULL, 
            0x0D75A96D6CF6EBB8ULL, 0x47804B535D6EA8E3ULL, 0xE0F95F3992404353ULL, 0x9F36FF7A9EEA7C39ULL, 
            0xC76B588A93235B31ULL, 0x4B558B49AEB24EF3ULL, 0xD7ECA28235123998ULL, 0x610E9D3B0C9121C4ULL, 
            0x00F51E178643A4AFULL, 0x33E54F8EB52DCF00ULL, 0xEB537DC587CDD1F3ULL, 0xC803B629C6C2713EULL
        },
        {
            0x08A782A76E46A1ADULL, 0xFBE8FC70A37161D4ULL, 0x1FE94EA0F19C09FAULL, 0xDF6A13B0CE889D8FULL, 
            0x4101AC3DA477C632ULL, 0x9DA80D40204A9556ULL, 0x3DE525BE3A7EB10AULL, 0xF35A3D14E0F3EC92ULL, 
            0xF21DB44281A28E3BULL, 0x503421E2A0EBBCA2ULL, 0x47826A12E8FD7293ULL, 0xD9CA2402EEE655C9ULL, 
            0xDBEE8A43BD0F6BA1ULL, 0x10C7E684E1ADE8CFULL, 0x5A0501B8164D2A64ULL, 0x8434BA4D1F5CD145ULL, 
            0xE15A1F0116F464F0ULL, 0x8716D14FD67C1146ULL, 0x34B940C246A0E65DULL, 0x397AB1271880FC47ULL, 
            0x9DA69E276F734B60ULL, 0x49D1C575FA7F7EF3ULL, 0xE604BF720D3ECD94ULL, 0xEA3DB83D58DA688BULL, 
            0x491CD36FABE7D070ULL, 0xDD56B6DB9D281133ULL, 0x10AB9CEFCDA7967EULL, 0x45943D67DC028AB9ULL, 
            0xDFAB1A3E62337975ULL, 0xF9D0FA393485A06FULL, 0x20E233C9A92FD5FFULL, 0xDDA667EF031ED7DCULL
        },
        {
            0x0D8794B162A7D8F5ULL, 0x3D6362DD8010ECC7ULL, 0x01517004AFE96038ULL, 0x2025B770C6EC28B0ULL, 
            0x68E5B05FC6C6F19DULL, 0xBF99910DB3247876ULL, 0x3C6580445F6930F1ULL, 0x4BDF57AA8A962FFFULL, 
            0x5371606EAF065565ULL, 0x417B338A75823D8BULL, 0xAC03D3071B2EC5BCULL, 0x6926249C09EFD0E0ULL, 
            0xA172A1839494E2A5ULL, 0x5F222EB665803B56ULL, 0x5922AFB574527D78ULL, 0x6B290994D2A0846EULL, 
            0x0C8751D475D17E3BULL, 0x40A35EC8550A1A88ULL, 0xA62A225082996574ULL, 0xB680DFC64EB73354ULL, 
            0x282FCEC313C27CB4ULL, 0x704E3DC066604AFCULL, 0x9EFAD7B66494DBBFULL, 0x552221687AD841DBULL, 
            0x28EFA3EA59B68800ULL, 0x7AD5462E02F5B62FULL, 0x8C9B7A13965CF192ULL, 0x20215714B571065EULL, 
            0x38ED9AB222995246ULL, 0x6F7B1C8282F71565ULL, 0x8579023E58BAB604ULL, 0x7DF0BD77B23CD8E8ULL
        },
        {
            0x1D026F87061165DFULL, 0xC09A9FF64C2E748FULL, 0x52895CB8099EB3E8ULL, 0x5D8E466EC0EA7077ULL, 
            0x26B7707AFEC34F1EULL, 0xBB8A22E0A33A8483ULL, 0xA6F26ED9AE3760A0ULL, 0x5FB120B2E67A4ECDULL, 
            0xA290A203C084AA87ULL, 0xE73973088C66B4A5ULL, 0xC50F367D9357D667ULL, 0x7C4B9D6CFBBE34B2ULL, 
            0x8D3B564FE78C76A2ULL, 0x6BDE7319C1F7B3C4ULL, 0x469D087B7FF4FD9DULL, 0x34BC7EF2EA2AECB3ULL, 
            0x86500A9F5CD9480FULL, 0xBEDBC6B4422B8F8AULL, 0x856D0FE44B7F8C6EULL, 0xE349C0A57D2DC75FULL, 
            0xF8081C380CAA6784ULL, 0xA3A828E84292C287ULL, 0x102A73875A859DB6ULL, 0x95770D3875D74080ULL, 
            0x5394040F6FBD5F9EULL, 0x88FD3C5ED8770AC8ULL, 0xF1EE293955BED23FULL, 0x7AE5A428F5D4A353ULL, 
            0xA3195CDD8D501619ULL, 0xC3AF91ACB49F0EDFULL, 0xB4A71FB19881B575ULL, 0xEDC6DD31303570B0ULL
        },
        {
            0xA59B8A763A1E7BEAULL, 0xD8C8B0496709383FULL, 0x38802EF5FDF6E0A6ULL, 0xA6977E370C0C7695ULL, 
            0x0C4ADCD3D6F4B8F3ULL, 0xADD8CF7F05E94631ULL, 0xEF4B28450CD54561ULL, 0x4022C9A43D966BD6ULL, 
            0x9277D082306D57E6ULL, 0x78D151491F395391ULL, 0x3D32B899807B1885ULL, 0x7CBA716BA1741F25ULL, 
            0x57F6207E14D7BD53ULL, 0xE619F9340F6BC52AULL, 0xC72DC6391DF987E7ULL, 0x1F61CD2F4E926085ULL, 
            0x6517072301C9F20DULL, 0xA047624A65B374DCULL, 0x3DA14E7382149D7DULL, 0x8304D1788D1994B4ULL, 
            0x0EEDC907574514DFULL, 0x3AE5DF36876D6E70ULL, 0xCD6C46536705EE67ULL, 0x4E0C93BED00703E9ULL, 
            0x0B9AE35CF3E6EDBEULL, 0x818569E502B20598ULL, 0x6857C4347EB65DD9ULL, 0xE8A0E4F2EC435570ULL, 
            0x6017639695A552A4ULL, 0x37B24D1B76DFEA39ULL, 0x5691B3AEDE97934FULL, 0x276B5059E74D7748ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseBConstants = {
    0x607E49FF5EF48699ULL,
    0x0BA41EA65A775A33ULL,
    0x38A4D1F7BC8DCF75ULL,
    0x607E49FF5EF48699ULL,
    0x0BA41EA65A775A33ULL,
    0x38A4D1F7BC8DCF75ULL,
    0xD816D189AD81A12BULL,
    0x22D78D75B2E25FAFULL,
    0xC6,
    0x49,
    0x17,
    0x19,
    0xF4,
    0x1F,
    0x29,
    0xD3
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseCSalts = {
    {
        {
            0xA56A9BD64BF68F32ULL, 0xFED9BA0D0A9CEBB2ULL, 0x7C07EF14E3F503FCULL, 0xE207A8505DC9986CULL, 
            0xC5E168D2AE65C076ULL, 0x1880ADEE50B2CC0CULL, 0x5343361497DA09CCULL, 0xA88174C967776FD2ULL, 
            0x8E3D626127C089E7ULL, 0x627D9CDA6BC979D2ULL, 0x4AA33F8131BD31EFULL, 0x28C3848D47882D51ULL, 
            0x6C64B05808B66933ULL, 0xE2E343ED7444E58DULL, 0x6D803B6F4337C851ULL, 0xF3E9B455E4E0A50CULL, 
            0x2455A902A95C163EULL, 0xFFACF63C3CA82DA8ULL, 0x117FBF241ECD98DDULL, 0x01AAFB445ACBCAF2ULL, 
            0x852513B32F6DB895ULL, 0xC24D5E997A980835ULL, 0x414FA053698E0CFBULL, 0x7E61E9A4B6F63D64ULL, 
            0x69B88AE7AAC3877DULL, 0xB56F3148EE372CAEULL, 0x9D3D719238D2C9C2ULL, 0xCFBA2696E602FD50ULL, 
            0x078E395D00157434ULL, 0x120BF2FB178058D3ULL, 0x9708179F316C816CULL, 0x95FF232938C0BC34ULL
        },
        {
            0x9B32959728C36621ULL, 0x1B438289ED1817FCULL, 0x5142DB152F9C0C84ULL, 0x0BB6644E1B9012EDULL, 
            0xE892271959F0C560ULL, 0x79D5A257F904CF62ULL, 0xD86A97A0ADABDAAAULL, 0x8431016BB1BE4A58ULL, 
            0x8BF585C5A3479A53ULL, 0xFD89DBDE79DD754EULL, 0x76928AF87030256CULL, 0x6DC370233D66535DULL, 
            0xBE040CE748717BA5ULL, 0xC3ABA8C87A2045A2ULL, 0x4DA7C12FFB37B6B7ULL, 0xE2490AD65E2D58FEULL, 
            0x539711FA3BCB8FE4ULL, 0xC4081B1CDA1E21F0ULL, 0x019822601445C3A9ULL, 0xE7E4F322D02B4148ULL, 
            0x5D119E803F486571ULL, 0x90C78347187512BFULL, 0x5312C888AD9D8A1AULL, 0x763144F6B8902401ULL, 
            0xBBC7003D16334595ULL, 0xCF0C658A18888FEFULL, 0x9E50817CB0D76E6FULL, 0x17CE0DA37B839B68ULL, 
            0xAD34FC94C90070FDULL, 0xD4CFFA74E3E111CDULL, 0x09F5582F80C84909ULL, 0x95FDEA718DB0ACDEULL
        },
        {
            0x4A9B59BD2C1A0A59ULL, 0x8EB81CB0472508A9ULL, 0x6C7453494C267AEFULL, 0xA30E223266B8AB60ULL, 
            0x33CCE4C8FF3B8C7CULL, 0xFB16610A2CD5398EULL, 0x22604386BA4FAF88ULL, 0x2A30A93025FBD16FULL, 
            0xFE37CF52140FA646ULL, 0x2984870B76147BAAULL, 0x3BCF9044517669D4ULL, 0xC399E30D3777EB5CULL, 
            0x20A4C90364E1387CULL, 0xF4AB7417156750DBULL, 0xED9F99F03E4D0747ULL, 0xD4CB3A3A82FBD0A3ULL, 
            0x294C3515A0E055C9ULL, 0x441FAE2DE9B7B572ULL, 0x9689B7F5232BE4B2ULL, 0x3E2FB04EAF6856A2ULL, 
            0x18E525C77458DBA9ULL, 0x789D8C351D45A23BULL, 0x366D3781ADDC767FULL, 0xE2309063DCB45C25ULL, 
            0x0C31123862A5F475ULL, 0xB96FFEDAFF20F02EULL, 0xE936D3B9F6C0CCE8ULL, 0x353E2234DEA0F784ULL, 
            0x16C606F7BCD2934BULL, 0x21F5FD07D505E172ULL, 0xE8839892E9EF0D9FULL, 0x90BD5C0DF7047CC7ULL
        },
        {
            0x3C60F13AD128368FULL, 0xDB9113F08FDD7851ULL, 0x15FC63021801F2C7ULL, 0x909E2B93C408AE4EULL, 
            0xD0D15AEEC322C5EEULL, 0xABDEDAA1CCC999F0ULL, 0x79D8E2E7B61D1120ULL, 0x26279D9BCC18EA62ULL, 
            0xF9BC3EE5423EC950ULL, 0x9B1D93F0E4E511E5ULL, 0x3C4DC17242BA32FAULL, 0xBF909FA766D07840ULL, 
            0x94FDBC4652D860E2ULL, 0xF96A34A5BE31E12BULL, 0xA042B553C287E919ULL, 0xB88A50E8C05DF28AULL, 
            0xC7BAA2304D6080AEULL, 0x75063F0606DD8FE7ULL, 0xD5E0941A05788349ULL, 0x723079B7C808FCF4ULL, 
            0x9C20AAB56AA04646ULL, 0xECA5B20C808A46BEULL, 0x870F3F4D1BC7F741ULL, 0xDF5181B0DBE06B1EULL, 
            0xC6C6D96D3D992ED9ULL, 0xCA3E2F9CBFA3A2DAULL, 0x3F0E07985B402568ULL, 0xFA963C667055BD40ULL, 
            0xC81F70565BADE22EULL, 0x58BC077841650BA0ULL, 0x2E45E80CB9EBBA5CULL, 0x56E16DC64B31E037ULL
        },
        {
            0x1EBA6F7C48AEF95FULL, 0x5C1EC9CA3A20511EULL, 0xEFC96CF7A9E1617FULL, 0x50EBB7185F4B98C0ULL, 
            0xB82E600A959D5CB7ULL, 0xFE8142748BBF16E7ULL, 0x185B85DAB5CB7E6AULL, 0xA821520A2C0EC451ULL, 
            0x428D78A46FA338AEULL, 0xF8097D5BB9E8F68FULL, 0xAD960AE47801ACDCULL, 0xA3E74CBE0F9BE9EFULL, 
            0x2ECE76CF922617F9ULL, 0xE719CB6E7B3F0B21ULL, 0x1020597F538E2322ULL, 0xDC71C47C73A0B088ULL, 
            0xE3267074EBF7BE74ULL, 0xC002BDCC5EBDFD25ULL, 0xF7D9FA42E3DDEABBULL, 0x04F97A8820DC2EB0ULL, 
            0x77EE43BC7E63F373ULL, 0x62793040617830D4ULL, 0x0B726F4C70D1A55DULL, 0xEF5E2CEB137C2C16ULL, 
            0xCFDA1CBFF2D15B13ULL, 0x11DCCADFFD898B53ULL, 0xF852500DB34373CBULL, 0x43B95942F4210300ULL, 
            0xC47B7FC5AA0E5189ULL, 0x02A28A02306B4F99ULL, 0xFEFD52E494999EF8ULL, 0x4D4AD28E3F02D474ULL
        },
        {
            0x20E54A716EC71729ULL, 0xCCFF82E2CF5F94E3ULL, 0x9D57BAE4672E0180ULL, 0x5C9F2778259BEFEAULL, 
            0xD11FBEB5E6BEDDAAULL, 0x758C27FE55FC7564ULL, 0x6890CA1A0B73AF16ULL, 0x54CC4107212AF4D4ULL, 
            0xF6D62B3C1245E24DULL, 0x24FFF3AF0540540FULL, 0xF73F5DF9679AAB3CULL, 0x34BBBADE5DCE295EULL, 
            0xA6A5846D2036376DULL, 0x0F5ECF65B8F7F45FULL, 0x260A19EA003B9F6CULL, 0x1DC1F4E22BD34C6BULL, 
            0xAA0A2EB24E096B3FULL, 0xA41C893683C9598DULL, 0x2C66827244EA6D69ULL, 0xA497186C5C48118CULL, 
            0x28DA9FB107907852ULL, 0x085972583B4E2CF0ULL, 0x5ED7567F783A1AB2ULL, 0xFECBC40C8C596B31ULL, 
            0x8A0F59FAD442066AULL, 0xBB6A787CE3603D44ULL, 0x7545CB388BC82828ULL, 0x0351BE67A2A359F0ULL, 
            0xC40610A0110B2299ULL, 0xB38B2F8A534EE195ULL, 0x632FBB3ABA6DBC3CULL, 0x238D05184A5AF636ULL
        }
    },
    {
        {
            0x42A32B1A0B8CF19AULL, 0x75904FF8BF3901A5ULL, 0x2417F0ED997746CEULL, 0x631FBC200A867396ULL, 
            0x2F7A2EE920BF5A9AULL, 0x0CD712083EF47535ULL, 0x53520A453D01FD36ULL, 0x56395AE13A557C14ULL, 
            0xA578438504EFDB38ULL, 0xD47102AD51540625ULL, 0xFD54A83FF57222D7ULL, 0x012354238D5C7E7CULL, 
            0x87B13B146117CEC4ULL, 0x37B1661DDC62A098ULL, 0x6130B60CA26DFFFBULL, 0x91528CC1997335A7ULL, 
            0xA406CCEAF22EC51BULL, 0x78672163DEE6E464ULL, 0x46EB3B53FC2C15CDULL, 0x37DB927C657D162EULL, 
            0xC8B1FEC24A6EC71FULL, 0x1569BE5867B7F4CFULL, 0xDCD404986D9409ADULL, 0x53C93EBF2B991543ULL, 
            0xF7BEE6BDDD09AE41ULL, 0x63A278FD0DED6764ULL, 0xA2C4DC39F9D86DB6ULL, 0xE065A84A9D4F0F0CULL, 
            0xA0F25066572185ABULL, 0x59C838FDB4258815ULL, 0xA2B85680D49E81EFULL, 0x9B65CF3E9A1E15C4ULL
        },
        {
            0x232E5B43853807F6ULL, 0xCEDA14464F804D38ULL, 0xB1BA7C2D4D4BED4DULL, 0x7E1AFAAB296726C1ULL, 
            0x443B60C808406E13ULL, 0xC09297460A6EA63AULL, 0xEADEDC1381D897D3ULL, 0xF1E5CA96CDC02D86ULL, 
            0xF549D3D44855409FULL, 0xCCA375E695651149ULL, 0x71EA723F5855732FULL, 0x3623138993308E13ULL, 
            0xFF24B9035D744F32ULL, 0xE4376DF933F170DEULL, 0x412004858D3E72D9ULL, 0x1609E06E73970502ULL, 
            0x09C5C569CD8F84B8ULL, 0xFAB4B4AA23B01D17ULL, 0xF7D67B249D56399CULL, 0xFF36FC3CD2C3A828ULL, 
            0xBF7946E479F2A84AULL, 0xAD0D5589A9F2D613ULL, 0x8C6CE928F8D4BCEAULL, 0x272D9DFF7FD73F55ULL, 
            0xFB29C6FB556B0EA3ULL, 0xB9755B544C9624CFULL, 0xD6064C01BF94EBB9ULL, 0xB50B2D06C1E15D9AULL, 
            0x1A2820DD7952EB2FULL, 0xFF5D90176593A322ULL, 0x7E47539E3A36BD88ULL, 0x57DB82B1825A8A20ULL
        },
        {
            0xF0AF91F617112DD2ULL, 0xCEE204962A474BE2ULL, 0x9398421A2A93E55DULL, 0xAF96C5FD3136E035ULL, 
            0xC7835737EBD6B775ULL, 0xCF6A05A36A59C412ULL, 0x90504C08D5C28705ULL, 0x9B8FACF52A3D3116ULL, 
            0x5572CA3917564BB2ULL, 0xCFC120EB1415E7A2ULL, 0x91C908CF3FB12CCCULL, 0x19F9581B8B6E6671ULL, 
            0xE2316D08D3FD5237ULL, 0x2B5C251CA01E2474ULL, 0x5039A06095A2C962ULL, 0x7A1C8A1E11159ADEULL, 
            0xFCB0149A1B761BE2ULL, 0x7ADEE0BAD7688BDFULL, 0x8D2CEF5A363F43F4ULL, 0x7296801DD8A2791AULL, 
            0x575239A85F717224ULL, 0xC79F6DA2FBBA7C64ULL, 0x14B31B5A20D80291ULL, 0xC8EE6324E3619C92ULL, 
            0x81AA819AD42DE901ULL, 0x458C1996FC71CED1ULL, 0x850CA661422BAD07ULL, 0x770043D59F8D807DULL, 
            0x7795AA23D96C092CULL, 0x59555D83B4A580F0ULL, 0x6F9212CF13DA06C1ULL, 0x6F51664FC7AA65E8ULL
        },
        {
            0xE0DB9FF7A2EED415ULL, 0xC61444994330F12EULL, 0x0D712B3092F69C13ULL, 0x94BC174336A0DD1EULL, 
            0xDC1A7B64296CCEFCULL, 0x2A6125BB69A46BA1ULL, 0x9A4CDDAD5D2CAB3CULL, 0xB0464B767797DFFFULL, 
            0x441BE5194B94B7F3ULL, 0x596D6FCCAFC86EBAULL, 0x5F033765E3DE395FULL, 0x079837B8D1581303ULL, 
            0xDD8857F50E5E2FE6ULL, 0xE1C2B9729F3CBB13ULL, 0x84C776D4A377949FULL, 0xBF0C36063C107204ULL, 
            0x4FE0485BECF309F0ULL, 0x190D026B616DB69AULL, 0x5B7482D7C6942BECULL, 0xFEB7D7D9A52B7919ULL, 
            0x434D257A6C931894ULL, 0xC4B39CC60238DB30ULL, 0xAE1A1ACCD8B79B58ULL, 0xA92E1DB58C7A1C11ULL, 
            0x6D3D6B21B826BF8DULL, 0x07D2A14A6A2EC7B2ULL, 0x1A3B1CE73D5D8854ULL, 0x8ACE2F7A448FA793ULL, 
            0xEEB04BE113728E3AULL, 0x03B21FF0001377A5ULL, 0xE13A9DE281A69B9FULL, 0xB57FD47C6CF7CA41ULL
        },
        {
            0x65FEBB39FD43F103ULL, 0x2179FEFF3FF1A318ULL, 0x79FEC0B99B1F4CC6ULL, 0xC3CE10BBA477836AULL, 
            0x3FC7A7BD220385C5ULL, 0x9374AF229DFFD6AFULL, 0xFA285D70E814893BULL, 0x2DA26BFBC16EE4E5ULL, 
            0x1F8D9D276EBA0137ULL, 0x35521F089E049E56ULL, 0x97F86B14589BEF54ULL, 0x2D2B92318ECB9B6FULL, 
            0x3356622DEAD880C7ULL, 0xC5FDFFC0DA40B208ULL, 0xF28C99F62FDD5508ULL, 0xA8560F6D6E16C476ULL, 
            0xC4C7153AF978732AULL, 0x0619FE55AE9202A4ULL, 0xEC024BDA3C2F91C0ULL, 0x3CE7E76BDE95B018ULL, 
            0x8C571B7D7BBB9955ULL, 0xE65DE1EA5FE25177ULL, 0xEA2B020E55C4BFA7ULL, 0x18EDFDA3433BA39DULL, 
            0xCDBDD12B497A2325ULL, 0x2815BEDE6DC93E91ULL, 0x9F5FEA8FE2D020E3ULL, 0x3D9337DFFCE161E8ULL, 
            0x7129C162086A1404ULL, 0xDD5B4ED3124BA607ULL, 0xD2AD8F32EA9A0EB8ULL, 0x9BB43697E46DD32DULL
        },
        {
            0x4B9FB5DD72CADAFCULL, 0x8553C9E68DB83D31ULL, 0x2D4B84DD5ED82781ULL, 0xE607AB1CE783026EULL, 
            0x891B4E29EBC56149ULL, 0xF69B53E293772590ULL, 0x00E0ACDDCC9D747DULL, 0x43E510A06E99891AULL, 
            0x9DE754C19706CCAFULL, 0xB2FF4ECDDA5FAB5CULL, 0x14C75ADBA5F9E773ULL, 0x632786F83A4CCE8CULL, 
            0x01AA65F2E7150664ULL, 0xB7ADB3028F2F496DULL, 0xA6A0F39DE64893E1ULL, 0xB7BC86207B536422ULL, 
            0x4AD0468F1D42E04DULL, 0x3ACF85114CD9A09FULL, 0x94FF13FAC4446047ULL, 0x10D921D5CACDA72CULL, 
            0x13A7DFF7670CD61DULL, 0x938C2F34B686589FULL, 0x5D76C483740E06BDULL, 0x8E17F2730645A32FULL, 
            0xEF7462CE37DDCA20ULL, 0x915BB3C23A845F1BULL, 0x9E6FFB4386E24307ULL, 0x927DCD530D3C7F30ULL, 
            0x89745BAB10270D56ULL, 0x0018D7C71EF92E16ULL, 0xA1ED054CED6E2124ULL, 0xC78E2D475EEC8A83ULL
        }
    },
    {
        {
            0x77CCFD7267B85970ULL, 0xE78EC21782D3D3EFULL, 0x0BAA0E47939FE2AEULL, 0xDCB784EA9EB958A0ULL, 
            0xEB8763AEF260B38EULL, 0xAF5212AC1B2B440DULL, 0x76EF006CF9A288C8ULL, 0x3ABB4736AFE4A690ULL, 
            0xC756388BD57280FAULL, 0x53E30DDB3747BE22ULL, 0xE8B26CAE77366BA0ULL, 0x485E58B3A790DE17ULL, 
            0xB387480B1B41A10AULL, 0xC37146E137018A5CULL, 0xC8F6148AB8A780B3ULL, 0xCEC3A762B357B589ULL, 
            0xF63A38ACEADB48EFULL, 0xB925846A11B2FA05ULL, 0x360A1178030DFA24ULL, 0xAEF030D39CD6F70BULL, 
            0x625F9D8EE69D8606ULL, 0xFD25CC3D061401A2ULL, 0xB35AF80E5ECF3632ULL, 0xA8155775D257E14DULL, 
            0x04AEA534070E6FD9ULL, 0x38E318F0160060D0ULL, 0x1D586B8C6C00C0CFULL, 0x16B1CBF9D066BECAULL, 
            0xC154F56F605E4F67ULL, 0x4CE8EAD919FA860CULL, 0xC320E12F52E54099ULL, 0x1997EC8701C15F67ULL
        },
        {
            0x8CA7469F287A31D7ULL, 0x86C587011D6D33E6ULL, 0x972DE13B87A61909ULL, 0x477D85B01CD0B407ULL, 
            0x6D4743A542071291ULL, 0x4BA5F3163A5EB14BULL, 0xC3C56C38727F9404ULL, 0x6896FCAEDC301A0AULL, 
            0xE2534F3AD0773619ULL, 0x924BD913CC2FCE9FULL, 0x009E9A05BB375495ULL, 0xB27DA2630B59C2F2ULL, 
            0xCE6EE7647B44A41CULL, 0x146F6A1561096A5DULL, 0xC5C80EB78526DA30ULL, 0x3922C3D763604E4AULL, 
            0xB879CED8196BBA8EULL, 0x95F7E6CBCE5541D0ULL, 0xD0CE4DF9CF49CB61ULL, 0xF7C48CBEC3E8CC7AULL, 
            0xDC7B02B70553D3C5ULL, 0x4DCA02D0BBCC0594ULL, 0x6D9D356EF1904EADULL, 0xE766CEC91814E721ULL, 
            0xF700A50AB3624DC4ULL, 0xCDB984707DB347DEULL, 0x358048B7A60AACB7ULL, 0x540EC9254059BC8FULL, 
            0x0A17DCED133AD2DCULL, 0x45B612E85C1D3161ULL, 0x28DC32D9FBCC4621ULL, 0x9E419A35E1220227ULL
        },
        {
            0x5A87883693318DF3ULL, 0x1A95B4E8A5E2EDF4ULL, 0xD66867065B9A72F5ULL, 0x0E9A27FAD2C3DBAFULL, 
            0xEDA6FC56FD0AECF1ULL, 0x3E1186BF9BF61AD5ULL, 0x32A84462E8D7D9B4ULL, 0xF74A06D162045DBEULL, 
            0xC5017D4B04CBBCF5ULL, 0xF16E46032A3BC71FULL, 0x949451990E3615B7ULL, 0x3A76AA06D73201F7ULL, 
            0x3D797A41C359F157ULL, 0xC251062983607090ULL, 0x51A6422F9B7D8CADULL, 0xFB66B15C956621B5ULL, 
            0x8875D461CD0D69A6ULL, 0x422943BD453B23CFULL, 0x21D7D7633CB79EBCULL, 0xBE7BEB4613F0EB56ULL, 
            0x79C0A0C964143B32ULL, 0xE264117F30046BF3ULL, 0x471FD8EC4C182EC3ULL, 0xB84371502668B7A8ULL, 
            0xAC2A7F56C3D6E143ULL, 0x8B0B9236888CAF7BULL, 0x8561FE3B36D404DDULL, 0x929247F5BCA62E6EULL, 
            0x464D0EA29C6B9186ULL, 0xFC737B2046B78FCBULL, 0xEA38CE4205209FE3ULL, 0xB89BBFE97FA855EAULL
        },
        {
            0x398EB7167388A8EDULL, 0x3F6660B8F8B7FE04ULL, 0xF3D8BF0C161790E4ULL, 0x5AF0993373FF3783ULL, 
            0xE7925A8BDF73F95CULL, 0x4A883EC7368B6B7EULL, 0x1C6AC46B7CFEE986ULL, 0xEFF55FD19C615690ULL, 
            0xC104F6F4ACCB9D2EULL, 0x7545F2FDD1435286ULL, 0x8FD68A08AA01F8E7ULL, 0x2E306DBD41CDEDEAULL, 
            0xE8C260E8066F2712ULL, 0x82508EEE99EE9E08ULL, 0xA2D9C052AB39828AULL, 0xE8847A418F907422ULL, 
            0x494A38F09769D347ULL, 0x661127B571F3AE68ULL, 0x783989F1A3A2C671ULL, 0x92B3A8F4039E9F4BULL, 
            0x1E7437F1EB8D9DB6ULL, 0x8D5D0674179FC47DULL, 0xA1A889316C77A574ULL, 0x11D34056AA65E8B7ULL, 
            0x1AD54071428020DEULL, 0x4AC22BD8ED8F120AULL, 0x9484F642E8F93F7BULL, 0x0079288CBC51B368ULL, 
            0x2C5DA11D2F583270ULL, 0x5DA9A2D4305EB6D4ULL, 0x6028B001336F78A2ULL, 0x90B74FD85E7A57CDULL
        },
        {
            0x71DBCFEB4880A3B3ULL, 0x5AB99A1655755C45ULL, 0x12DF9759CB85A887ULL, 0x9B5E785376B500EDULL, 
            0xE4005C38C188FF4AULL, 0xCC5D34C00D397B2CULL, 0xC2A83F7CCAA7DFB7ULL, 0x7690CDBB830FB3D4ULL, 
            0xE890654FBBE8F112ULL, 0x08BD4A2B82D811BCULL, 0xC28D49D884608F7DULL, 0x667C359E90D6389CULL, 
            0x4F936E16D19BD724ULL, 0xEC685121037CC2E2ULL, 0x05F67533123A19ECULL, 0x57DE2857123BE3C2ULL, 
            0x488E3F655EA5E783ULL, 0xCF17B4AA3EA79653ULL, 0xFD627FD21170010CULL, 0xA3CEC4734C672273ULL, 
            0xEE40958B02609303ULL, 0x02523A5FA12B050AULL, 0x59D751FC4B406F04ULL, 0x6D464EBAE0746506ULL, 
            0xEFCB2E71BB623193ULL, 0x1BB260632F71A2E8ULL, 0xC627C4A42E79C6AEULL, 0xA1E8A83D610E0326ULL, 
            0x3C9D87F1860DD567ULL, 0x11BB6ED1AD888D80ULL, 0xB875FE0C6558C5EFULL, 0xDAD51524162D55B6ULL
        },
        {
            0x4978206A5B529A5AULL, 0x7E4E78AF3AA4F321ULL, 0x5B7D1B31BCA001EBULL, 0x2F3F43C216CB3C55ULL, 
            0xB7A925CC8B85CB9FULL, 0x5BFD088991B9917DULL, 0xCCC13627CF48DAF2ULL, 0xBC5DF284F7AD6F4CULL, 
            0x668E7820F5E04F39ULL, 0xA1E1AE57AAED84C5ULL, 0x2204302D3812534BULL, 0x8CE7F0669BBA75A0ULL, 
            0x0CF8533A78CA2AD5ULL, 0xC1903BE12C8A39EDULL, 0x7BFED0CED5622653ULL, 0x140383B8AB230F37ULL, 
            0xBAA9F52A7AD4850BULL, 0x1DD29683BDD0716CULL, 0xA0BD8C00B5EE5A45ULL, 0xB057E7D64DD0A33BULL, 
            0xA511164C3C1DC800ULL, 0xBD5C5C33EA89183BULL, 0x8DF41CC9B3BCC754ULL, 0xE555DE434CABF5CAULL, 
            0x8B5D69E4411CADE0ULL, 0xD6E58DC0F70C6BB8ULL, 0x71473F8ED0A681E1ULL, 0x01271A1533A4E69FULL, 
            0x2144094488C8C84BULL, 0xB168A3A40A3C17E2ULL, 0x9DEF4EA185480294ULL, 0xF9F3117ACC5E03D3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseCConstants = {
    0xC2496BB9D7644B2BULL,
    0x87CD50CB6E934907ULL,
    0x8898B5EF94F0D260ULL,
    0xC2496BB9D7644B2BULL,
    0x87CD50CB6E934907ULL,
    0x8898B5EF94F0D260ULL,
    0x3ADAA7ED589DF9D8ULL,
    0x9AD45F5A369ED239ULL,
    0x25,
    0x90,
    0x50,
    0x1C,
    0x02,
    0xD1,
    0xD6,
    0x1E
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseDSalts = {
    {
        {
            0x0A32078A1E369BB3ULL, 0xD951BCD53FCCB031ULL, 0x9C00EB910D242FDDULL, 0x864A71FC6926D5F7ULL, 
            0x953A9929C839B6C7ULL, 0x06434481857D480AULL, 0x307CEBB32AEA4BA6ULL, 0x97D9E5C9D9C59F8DULL, 
            0x314EB5E43154B91BULL, 0xA76718AA5036D517ULL, 0x34B66D98A3AF5FF2ULL, 0x634DE261D4AD8279ULL, 
            0x0AC739BE14093BD2ULL, 0xC4817109757EAC87ULL, 0xEF343F730E9AD72DULL, 0x904994E2FFC56D30ULL, 
            0xC5A6DDC234AC7D32ULL, 0x0F713C3EA8B7D038ULL, 0x183FD5567DFFF8CBULL, 0x7FF01428F766DDD3ULL, 
            0xB6DFC4714D4BD930ULL, 0xFB8115F6E2C00A39ULL, 0x20F0944932444E7EULL, 0x3C9B5C0BFAE7B252ULL, 
            0x8267D5BB36523DDDULL, 0x20D2D082B8234E03ULL, 0x3867E8E6BD8BBC85ULL, 0x1BADFF8448E2152EULL, 
            0x272ECE6BC941EC7EULL, 0x022E0944FFAF001AULL, 0xCB8F6EA508CCD050ULL, 0xDB1A8240A59048DFULL
        },
        {
            0x4D146B521D68CF60ULL, 0xE4DD6E2351C39B83ULL, 0xB84C15E623554933ULL, 0xB4475A4EDA6CF254ULL, 
            0x79250EE0BC2E085AULL, 0xEC515CF35044CD6CULL, 0xC88BAAD3314E9693ULL, 0x9A9AB031C7AA17D4ULL, 
            0xA375997DE4AB5288ULL, 0x7FF1924303EA6FD0ULL, 0x790ADCF53B9E2C62ULL, 0x7FA0B39BC167DE25ULL, 
            0x737FE7AC9DE99397ULL, 0x148C35BBA2CC2A0CULL, 0xCDAEA9FB64F7DC86ULL, 0x32E128A54A3EBF94ULL, 
            0x42940D56A23E894FULL, 0x96642A7B4DE9C63AULL, 0xB0ECB04F59B9C81CULL, 0x201A9085949FAF40ULL, 
            0x8D64FBB5FB1370C7ULL, 0xD68D135E31AD6D40ULL, 0x198731CF99ADD94DULL, 0x161858BA6C0DF3C0ULL, 
            0x70BF6BC9D59CAF36ULL, 0xF421070FE82506E5ULL, 0xF5EB174569BF04C3ULL, 0x3EA18FA7AEA85432ULL, 
            0x755A52D701B3373FULL, 0xAF2404B304E8FF87ULL, 0x5D8842A0F1FE9047ULL, 0x1001654489033C44ULL
        },
        {
            0xD0792715C198E3A3ULL, 0x38424DFAF961C619ULL, 0x8ECD4A36B05CF1DDULL, 0x0CE8739DB7D63D7AULL, 
            0x283AD698DEBDF4B4ULL, 0xF347CC018E2402E9ULL, 0x05E0842AD9146FE8ULL, 0x76D037FF3BCC2B89ULL, 
            0x4CE7EF9AEDA06BD1ULL, 0x0AA5EAB932FB43ACULL, 0xB195E2468DB68D9BULL, 0xD58E470C68C15A32ULL, 
            0xBCF14AF11006DA98ULL, 0x0927B137C671AF2EULL, 0xF2D9DD0D508EE7B3ULL, 0xF45CE19FF583D010ULL, 
            0x29596F5AF845705AULL, 0x72E3FDB4561C8355ULL, 0xA4F017E3C4CC9C1AULL, 0xA8F49A8C83293BCAULL, 
            0x85227FE9B3D74C4EULL, 0xF22971EC622E2D31ULL, 0xB192C878BC0B6D50ULL, 0x917CFCCAC43B7577ULL, 
            0x3206315BF9CA659AULL, 0xF09D8A3319C5767BULL, 0x20EF8ECF0353E5A8ULL, 0xF356475086F39C6CULL, 
            0x1C4E7F7F9B7913D1ULL, 0x1510C4F1BDE79836ULL, 0x751127238405C694ULL, 0x9515F3FF7D3515BBULL
        },
        {
            0xD75B1316A8507B85ULL, 0x25167D588DDB16B8ULL, 0x448C2215E7CB4B9EULL, 0x2F67DCB580049133ULL, 
            0x1AAA38060824D79EULL, 0x18D6332E4483085DULL, 0x97DE7459732F2AF7ULL, 0x0B3334341FC7E6C7ULL, 
            0x0A5167DE6E581077ULL, 0xF7631826991ADAD4ULL, 0xA05DE5B5EB2C26EAULL, 0x076BEBD93541C9A4ULL, 
            0x145683B5C5A2761EULL, 0x8E308D913EC77CF6ULL, 0x68E1607F2CC286D9ULL, 0x2BC043774377F4CFULL, 
            0x875C89747B24914BULL, 0x57F959D1372D43F0ULL, 0x1E4BBCE32D96A5C7ULL, 0x0831AF0D66D7B523ULL, 
            0x67EF7184311F2E96ULL, 0x6C584F609DDC09F4ULL, 0xA509B76C18DD4F05ULL, 0x6C2E4E12F1987FDFULL, 
            0x67E8568BCB1EA2B2ULL, 0x500A52F92B5C2C39ULL, 0x77AC19F2698E6147ULL, 0xF5AA437DE13F5115ULL, 
            0xBE501B46FB27B73DULL, 0x92EAEF05BBD7A20EULL, 0x7C5B7275A71CC294ULL, 0x68D442F21DAAD3A5ULL
        },
        {
            0x20AB23B9BC936246ULL, 0xB586CE8542FF3D49ULL, 0x5222C5D22313489AULL, 0x9F78A54FF9A48893ULL, 
            0x3EB4E8EFCBDB01B2ULL, 0x8C84AF423BA4BF42ULL, 0x9D96F538C243819EULL, 0xF987122C71FECF02ULL, 
            0x35E7282F760D0E3DULL, 0xE2A7D699C0425080ULL, 0x4F00209714F0E9B9ULL, 0x983FFC71AF0FAB05ULL, 
            0x67E10DA1B16B8BA7ULL, 0x9CF95A02CCE0EEE6ULL, 0xC640447F50E39B27ULL, 0x4322D082C6AF61A2ULL, 
            0xDD7227421C6A58DEULL, 0x40FE53501455AD44ULL, 0x0C794F6E6F071067ULL, 0xEA73FD8C49AB0EFCULL, 
            0x40E0EF0813ACFA28ULL, 0x0C8BE7D36D1451B6ULL, 0xAA255595DED1E7BCULL, 0x129D0BB85F786336ULL, 
            0x875FF3045A8A7E29ULL, 0x2C02382D739ED389ULL, 0x6A455C1006FDAFCBULL, 0xF4E79BA6F8D31717ULL, 
            0xB112C164C48E75C8ULL, 0x41AF855649841059ULL, 0xF8691BAAC684FCD0ULL, 0x81B31FAE0F4C5743ULL
        },
        {
            0xDE9A55DCC05B15F3ULL, 0xFDEDA1C0C72E8F24ULL, 0x54CE14F57E93F859ULL, 0x235EC1AED0EDE6C4ULL, 
            0xF0D260C68276A24CULL, 0xB1F07E68BE05A299ULL, 0xE7A51F296C7AAED2ULL, 0xA0BADC2B0497DD73ULL, 
            0xD9A95FD3FC1A8D27ULL, 0x5FE531C0F930EE94ULL, 0x1B2EAD5FC7C14B0DULL, 0x91A9BEE539964D63ULL, 
            0x9FBA84127F75830FULL, 0x7559F7BB7ED3ADDCULL, 0xB13E43B843BC8587ULL, 0xC83603BBB979199AULL, 
            0x5275B98A1C70B6D1ULL, 0xEFD4297F7A698E89ULL, 0x7927DE61F538B0F4ULL, 0xAD653D6BC5BCEC72ULL, 
            0x6633CDC5625CA65FULL, 0x1A1AD682C674FC8CULL, 0x4EED63B6F574E8D6ULL, 0x2D7A1CA0FCA844C8ULL, 
            0x085C9D1132BEF468ULL, 0x7CE1DD1A7306755FULL, 0xE3DEA0802309DF5CULL, 0x959F9E30AAC750D8ULL, 
            0xC3D583FB25F36812ULL, 0x39083504ACB35515ULL, 0x241DC936B18385DCULL, 0x86AC2F97F300DBC3ULL
        }
    },
    {
        {
            0xED6C524F7F1B529BULL, 0x3B2D9F42080558AFULL, 0x23C205C74A066CA9ULL, 0x71ABE65EAD3E421EULL, 
            0x759BA3A7D5A2BA31ULL, 0x4A8E440B8D8AB2F0ULL, 0xDC64B5F27947D4E6ULL, 0x779D5C3581DCBF26ULL, 
            0x8F5A7882F71E23F4ULL, 0x1393F1145D1A65D9ULL, 0x5879B58D691D2CF9ULL, 0x5D82197BFE7DCAC1ULL, 
            0xDDAF2B3013329FF7ULL, 0x2A4155CE261FF3B3ULL, 0x9BE2466885CCAFE2ULL, 0x72BB320AC27EE12CULL, 
            0x859975B807F91920ULL, 0xB9814E4E98E36C88ULL, 0x88369616232A9F63ULL, 0x5DEB6A4C57F4117DULL, 
            0x013D96258735ED64ULL, 0x3D1D8F18F8F37734ULL, 0xB6F56AE6DCBCC1D6ULL, 0x0D053E98F7CFF2CFULL, 
            0xC450CAE5046131D5ULL, 0x98E16829F7E685CAULL, 0x57F27D58D86348A4ULL, 0xDA61EDD1BDA40542ULL, 
            0xC855A1E58DDE93E3ULL, 0x3D7067ABB3A30FCDULL, 0x61D71A9354403E13ULL, 0x4C0999920C86D055ULL
        },
        {
            0xCF08D424FB834938ULL, 0x0057FC7B2716E166ULL, 0x7854264C33603240ULL, 0x1E7D3CE0E602677AULL, 
            0xBF1A716A06C8D7B6ULL, 0x8CBAFF98AFE9B427ULL, 0xA3422353B60569ADULL, 0x9B66632609E60F3BULL, 
            0x6310B6A8D3526043ULL, 0x07948EDCF23A6512ULL, 0xC77279A1BDF69EB4ULL, 0x3B544A5AF3EA7805ULL, 
            0xD56C3E926C1FD8D4ULL, 0x8CD00B005E2B5DD1ULL, 0x1695B651409A0B6BULL, 0x50019896F4C4B5A9ULL, 
            0x6005E48B70C19CCAULL, 0x8866C1D4C739A7F1ULL, 0x758453393D413C95ULL, 0xF592094F6C3422ABULL, 
            0xE68E2A5A4AB69223ULL, 0xD82F45C2E4D2F75CULL, 0x69C5F03FE3A244D2ULL, 0xD44567B5951FC414ULL, 
            0x6C5CB78209E2D3C1ULL, 0x80CAC3A9BB170141ULL, 0x70C8D3E1DD518EC1ULL, 0xD0B5429B5C654471ULL, 
            0xA0B6FA7037252AEFULL, 0x1F88664DFF8643B6ULL, 0x04E2EE541BF4938CULL, 0x614126B7704AB547ULL
        },
        {
            0xADFDF6371B73C747ULL, 0x44DB5D80E8C94664ULL, 0x3550DBFE52C254A5ULL, 0x4F82A201895A682CULL, 
            0x4D9D840E9D610DA7ULL, 0xE54AF2FF5D3A4105ULL, 0x46BB27A2C5F81763ULL, 0x367623DA5D00E863ULL, 
            0xD4724D548BCA47B3ULL, 0x10103D595A9A1398ULL, 0x94BAF5BA42D88DFDULL, 0x41E797588ED26654ULL, 
            0x5A516F5C51BCBE76ULL, 0xC457B3D62234DFDFULL, 0xD1001D46B8E39927ULL, 0xE3F25E531E235F6AULL, 
            0x599546CBE0FEA0CDULL, 0xF6979647D916AFB6ULL, 0x0304B0BBC3E3A024ULL, 0x9A5AD0A741316B51ULL, 
            0x5D14B00DB6F4AE8EULL, 0x9BFA0D2C725E2CA8ULL, 0xFC9B8046574C6BD0ULL, 0x70DD9B720AB0B475ULL, 
            0x283128D45FEB3640ULL, 0x83A9B57334027D7BULL, 0x8BAE002B93025830ULL, 0x43B7572F491D1647ULL, 
            0xE184E01950ABF62FULL, 0x18EE039207D5D6FFULL, 0x79054FF650554E24ULL, 0x83DFE7E68339E0A4ULL
        },
        {
            0x0A8552C38079B37AULL, 0x14F0FDB9D12CFCA2ULL, 0x19AFAACD0878E97CULL, 0x8885E910D7213AFFULL, 
            0xBEC6936FBF0D31BDULL, 0x261E3B313385F3C5ULL, 0x7D20AD35D0616A29ULL, 0xB7830CE56E93B982ULL, 
            0xAE499F46BE0B44EEULL, 0x8B50CD251CAABD03ULL, 0x59D41FAE3F063213ULL, 0x3DBA52B2AE074FEEULL, 
            0xE8C29AADDA8F56C7ULL, 0x975D2FBEC5FA436BULL, 0xA9A8B38D22D25663ULL, 0xA10CD00D0336EEE6ULL, 
            0xFDB260B462ED9376ULL, 0x303CB5C2F449B59BULL, 0xED027038816F16A2ULL, 0x321FBE80B267385BULL, 
            0xB03416C5BB905F84ULL, 0x3171582B8BB53786ULL, 0x35CF3870414113A2ULL, 0x219B8EF71C660685ULL, 
            0x08112BEC29166C6AULL, 0x1EFB7D49C21FDF69ULL, 0x7B328FB89B509964ULL, 0x89F83E90A790ED84ULL, 
            0x8487C5F15662913BULL, 0x3AC880300586E5A8ULL, 0x488780D885297973ULL, 0xFBA3A828E8BA4558ULL
        },
        {
            0xB9385B207CC4F15CULL, 0xCE7AA28173F61D64ULL, 0x5D63904F523DE8D3ULL, 0x8A005359EAF11BC5ULL, 
            0x58BFC60168CCF9D4ULL, 0xFFB1DAB604A741A1ULL, 0x21CAD0BBF05B1787ULL, 0xCF112652FDAB765BULL, 
            0xB434AE64887D4943ULL, 0x8C1823569E1BDAA3ULL, 0x89E9D8B1FDA7C338ULL, 0x2B12A87A0D9501ABULL, 
            0xDEDD4BAC498638B2ULL, 0xE0C0C4869025CE80ULL, 0x34CB8CCCEF29E2FEULL, 0xA8AEC1B48B5C1C35ULL, 
            0xA03771AE4D1117B7ULL, 0xDE216C7533E4ECD1ULL, 0xD4B7B5323F587786ULL, 0x374E9471016D4A1AULL, 
            0x79D167BD82DDAB7EULL, 0x3EB61C6FD35E7123ULL, 0x798E6C7683181797ULL, 0xFD451A868F850114ULL, 
            0x32F762CEF1B98873ULL, 0xEFA992547F8422CAULL, 0x37D7890D91A60D8AULL, 0x1FD548FFC7A0AA2FULL, 
            0x10F8136DF0B7CE64ULL, 0x9F9D47426C8100B0ULL, 0x5EE6E1892CA38B00ULL, 0x66A1EC7D3DA78DD0ULL
        },
        {
            0x5446EA66C7CB5075ULL, 0xD4B791ABEE400E47ULL, 0xC0358FF2EFEF5B7BULL, 0x59AE129E03FA0FF9ULL, 
            0x3336B2E2E68C08C1ULL, 0x78CD5103D9E1DC59ULL, 0x51D5A958110A7419ULL, 0xCEB838C1766BC8B6ULL, 
            0x8FC9926AABD6087BULL, 0x88F643D4F8CE7E14ULL, 0xE366F0B9E0722016ULL, 0x583ACDD3FD517BF5ULL, 
            0x25D4FD904D657F7BULL, 0x1A6AF976BEF634F5ULL, 0x421E8EFF89D614ADULL, 0x12C3EB4DF7C6D28AULL, 
            0xD5DE94552C82B6E3ULL, 0xC5019FC553869CFEULL, 0xF51DB319E539BDAEULL, 0x80FAA8B585EE7E9CULL, 
            0x7FB2473A01875DACULL, 0x6CA29443D42840B8ULL, 0x2684E8EACE1D915CULL, 0x56F7083D7428D078ULL, 
            0x4CFB5DA2911F0588ULL, 0x88F3EFBE8521C3A8ULL, 0x8578281733F1937EULL, 0x25136C80C1035F0BULL, 
            0xC47C2F4A9042301AULL, 0x5390E855D4C07495ULL, 0x4B4E6C21D6516E47ULL, 0xB59EA19B1E1755BDULL
        }
    },
    {
        {
            0x72C8318731165830ULL, 0x53446BC5A20F0177ULL, 0xA7F46686455F8DF5ULL, 0x6A2A5FD64E1EFC7AULL, 
            0x354178E175B1AF10ULL, 0x84BDF90D07FE95BAULL, 0xF530EC3301C09D33ULL, 0x45F73572B321DE08ULL, 
            0x28199855537FFBF8ULL, 0x96BA575BF13618E8ULL, 0xBC59AD1D0ABA38B6ULL, 0xBC6252640D4472DCULL, 
            0x945E0A6A846F373AULL, 0x56BD2AAE07B89034ULL, 0x2064E8E475F647FEULL, 0xDEA47D770F3B232DULL, 
            0xC34C977015D5899BULL, 0x09B66F4E1E64BC11ULL, 0xD507E531B70E8DD1ULL, 0x7B87903E262AC314ULL, 
            0x149212423E38B9C8ULL, 0x885BD2511B19F4BBULL, 0x853FFC6F17576D19ULL, 0xA0FECCCDC73F81F5ULL, 
            0x26CF9005DB54DFABULL, 0x0657BCD6334DAD18ULL, 0x5DEEA614DFE43A0CULL, 0xE4689222639D6FD3ULL, 
            0x5435E4CA217E83BCULL, 0x8FEF188B47548CABULL, 0xA241769E18BCD85BULL, 0xC152685A32A49916ULL
        },
        {
            0x311FCF6ABFA8274BULL, 0x8C629DE0E2E53054ULL, 0x5A57AC0C553F1319ULL, 0xDD6E0A8CDA1C4A02ULL, 
            0x4AF611A231B89028ULL, 0x12FCF4DBF7CD86E6ULL, 0xE10688D118F4AABCULL, 0xD1BEFBB46166FA6CULL, 
            0x4BBF968E1F910F96ULL, 0x259C08EB5135EFD0ULL, 0x2D062377F3887893ULL, 0x8823A2FD6747049EULL, 
            0xF1A3E4B60684AE20ULL, 0xFAAC37C60FA33B70ULL, 0xEFC58078EB5E29C9ULL, 0x7D7E074FFB40C3C0ULL, 
            0x32158ED1BD0E6884ULL, 0x180FF4E44AB9B7B7ULL, 0xE269BD5CEED45262ULL, 0x0365C50FFE533F81ULL, 
            0x9D35BA00375005E9ULL, 0x93186C8C1D36E773ULL, 0x53A8700E9AEE0A5FULL, 0x09E4EB9F69E4EE49ULL, 
            0xA8AFDAEE78EE1392ULL, 0xD022EB4E6363EE40ULL, 0xCF271A1F8D21E912ULL, 0x249F0BAE2DF2E43FULL, 
            0x1E6A9EBB5365ECD0ULL, 0x6863FA993000DA54ULL, 0x922E1769A7C8DDD3ULL, 0x5D593DEA31D1281FULL
        },
        {
            0x73740244577DCCF4ULL, 0xDB23D3D0B3059B52ULL, 0xC685B47F5115E4C0ULL, 0xA31B773453CA7D81ULL, 
            0xE811F0F7B657F5E5ULL, 0x2929F3F05E8FF1A1ULL, 0x96C2317219A7C9E9ULL, 0x0577F27C025D45D2ULL, 
            0x2CAF40600D682D9FULL, 0x8F2E3A977C449EEAULL, 0xF0E84DE32B03C98DULL, 0x985EB63EB0F4CAA5ULL, 
            0xFEBE2CE7A6A87A19ULL, 0x3E4D779A2EC9A54CULL, 0xDA17E33CB4F6D5BEULL, 0xAEB3B2B29F40E756ULL, 
            0xE4E926682AF33521ULL, 0xF1DAD47068598A0AULL, 0xA4906EC88D9B15DAULL, 0x0FFAD7C14F72DF1EULL, 
            0xC4505035E835E2DDULL, 0x81B4E3BF392EF0F3ULL, 0xFFDB7FB22CB463CAULL, 0xE62F8BCEE5EC2D74ULL, 
            0x4BAEB55EF02FF7A2ULL, 0x61FF9AD3C230D5A0ULL, 0xE1AB9FA3CE0FED9BULL, 0x7865FE565850D427ULL, 
            0xC2F6F8B21AAD7576ULL, 0x459B246FB4CDCE72ULL, 0xF75FAEFB18D627D0ULL, 0x801C69B904792D46ULL
        },
        {
            0xA0D95E0E9C2D1B1EULL, 0x6066C2A4F24C865DULL, 0x5DD79FF1B246F7ACULL, 0xBEDE1C015CC28A7CULL, 
            0x8C5E7C446C01EF5DULL, 0x56FCF067CB33526FULL, 0x0DBF7AF04367638EULL, 0x80D83EEB6469B10AULL, 
            0x5157D3906B5339FAULL, 0x4A9C3B170FC45081ULL, 0xCDED6088D34CBB9AULL, 0xDA2556DE4F46DEF6ULL, 
            0x1160D3D14A69B549ULL, 0x9EFFF392562020EAULL, 0x7EEFE1F9DFD97F47ULL, 0x83FE8A107387DA65ULL, 
            0x5C7B80622509CA8CULL, 0x56CACFC61C9CC049ULL, 0xAF63327887E973E0ULL, 0xCC418DE87CB5C0BFULL, 
            0xFFA1358551A16089ULL, 0x27A2B55118A0DCCFULL, 0x9D12752E22B4189DULL, 0xD302ABC1411D34E5ULL, 
            0x728DD16DCDE26B3BULL, 0x669ED4531D161888ULL, 0x2D43DC206EB5401BULL, 0x771F75033A81CA27ULL, 
            0xD481043A7D36A0C4ULL, 0x3E5A260770AD38A5ULL, 0x0A16B19705EC6B75ULL, 0xCD67AAA7D60FCCB8ULL
        },
        {
            0x918DC065EB5F2246ULL, 0xFC59DACBCEE220FCULL, 0x1BF8C1DAB23368FAULL, 0x3B2A470738A51E43ULL, 
            0xF8EFCC2007C1A440ULL, 0xCD4259B0B3B926B0ULL, 0x3664B8BA00CF7C2CULL, 0x43D03E08EEB5EA88ULL, 
            0x33507060C5752F00ULL, 0x2A10A2DE48CECB49ULL, 0x3B31D608543CEFB9ULL, 0x928063D6E1D796F4ULL, 
            0x9CEDAE90109CA0C6ULL, 0x8D5990CE1932D100ULL, 0x26232E32B49B4F5EULL, 0x38B223B9FDF14E5BULL, 
            0xE0C70DFB45B41855ULL, 0x7068F294BBA2416BULL, 0xC038C2F4B4595D61ULL, 0xC6B19857AB0DED96ULL, 
            0x4466723B675E1122ULL, 0xA2A69FEC13D41DC1ULL, 0x1723363A63DA7FF8ULL, 0x8DDA4006673C46DCULL, 
            0x12A39246CE0647F2ULL, 0x1E798054C6B0103AULL, 0x3C563D69F8474DF8ULL, 0xF18A55B8485C6A65ULL, 
            0x51B50A292D240331ULL, 0x05C2F92242242BB3ULL, 0xD0345FD1C5A7D942ULL, 0x801AF4D47FE3CEE1ULL
        },
        {
            0xC081DDAC45F4834FULL, 0x4BB5C6DA9BCD957CULL, 0x9DFE1784D8D6B3F8ULL, 0xDB65120BA7CE1771ULL, 
            0x179F55735ADC660EULL, 0x686256D661BF07C0ULL, 0x58C910BAEBF60F22ULL, 0x72769F8D5D94F93FULL, 
            0xAD90903F3EF70D44ULL, 0x459DB0FBCC4743DAULL, 0x5F6880912A1D2693ULL, 0xA413702AA4338F10ULL, 
            0x32B25AFE1F170EB9ULL, 0xDBE32214B54E8015ULL, 0xC4C5B7A89B6282DAULL, 0x73D025C763E97B8DULL, 
            0xF46B863BD0D2A079ULL, 0x486F7676DA92CC54ULL, 0xE3B493DEA1C90390ULL, 0x6D46EA91293B9226ULL, 
            0xE2534EC544CE03A3ULL, 0xBC2B8495A9A9229AULL, 0x2A2A1F4E6E0600AEULL, 0x26EA12DF6A2872E1ULL, 
            0xDB35A81DE5C678F4ULL, 0x8BD7789616770CE4ULL, 0x0A56F5E64955D117ULL, 0x411123F2F4767480ULL, 
            0xEB12F256A7D26E3BULL, 0x5ED46DF56A491519ULL, 0xB3FB9C00B181D936ULL, 0x133C8E7CE6028790ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseDConstants = {
    0xD5CF329C2F1AFD39ULL,
    0x82A1AD5E14376DF2ULL,
    0xE67357527933BE08ULL,
    0xD5CF329C2F1AFD39ULL,
    0x82A1AD5E14376DF2ULL,
    0xE67357527933BE08ULL,
    0x9FB9DBF9A64B25DBULL,
    0xCADB83A0C5520C2CULL,
    0x14,
    0xAC,
    0x49,
    0x5E,
    0xEC,
    0xA3,
    0xA8,
    0xE1
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseESalts = {
    {
        {
            0xE33D0CBAB11E1EB2ULL, 0x43EF994D46318BD8ULL, 0xE69FC1EA85898DF0ULL, 0x1FEA835E1432DEECULL, 
            0x9F725FF6292D7824ULL, 0x82EF083BB589B881ULL, 0x58E0546155860AB5ULL, 0xFE44C5D9A4778245ULL, 
            0x7E6C347EE7968CEAULL, 0xFC16F5A691F10FA4ULL, 0x7C4669D5E175C855ULL, 0x1E27D48DB12CF949ULL, 
            0x84457B01F6919040ULL, 0x7447EDC301E4A5F7ULL, 0xA0C470109F804748ULL, 0x9F5F51625DA2544BULL, 
            0xF1D5196B7570DF77ULL, 0x7B7E67CC7B7828B1ULL, 0x13E53E5385818AA4ULL, 0xEAFCE3D638A5FDF8ULL, 
            0x2170C3088FAB34C9ULL, 0x9DDE05E24A80C89FULL, 0x9240742E327DAF6EULL, 0x332F7DC79376DD26ULL, 
            0x35912FEB55DE5D07ULL, 0xA7312EDA9B930167ULL, 0xE3D40F140E3F5884ULL, 0xF9B843D3C60F01D1ULL, 
            0x0893E3E5894B419AULL, 0xCBD0C81CE953F4EEULL, 0xA4AE3DE778D3114DULL, 0x82EE29AC833D6E45ULL
        },
        {
            0xCC66D3291576971AULL, 0x6C6D43A4227EF708ULL, 0x084F275109E47AB9ULL, 0x81DA0DB6754C1506ULL, 
            0xB5896A89BFE78C50ULL, 0x1362DFCD28CAA408ULL, 0x1E96C9D9AB1567DDULL, 0x241170869B6632BAULL, 
            0x2AF27A6C2BF280FAULL, 0x7DFCE25537484FA1ULL, 0x68E2E795B9609A67ULL, 0x9304B0F956EEE5D0ULL, 
            0x25385E7074F8C3A4ULL, 0x6554C98BF9FEA07FULL, 0x18E418949B180731ULL, 0x607252E0147329E9ULL, 
            0x9CE1998D4AD91EE5ULL, 0x6A544293300E2DBBULL, 0x50B6AE8D65269A9DULL, 0xB01A61265CD61311ULL, 
            0xF35C9F4251D0CF79ULL, 0x1167263E9E4F027EULL, 0x2D600616380556C2ULL, 0x71C2EEFBE5AF2BD4ULL, 
            0xB34353F992C8C543ULL, 0xA905C8B941AFB70AULL, 0xBB7A4019B3CE9238ULL, 0x0F361D051DF58701ULL, 
            0xB3DC74188F9E9582ULL, 0x572B8BE807AB409FULL, 0xB14BF97641F0DAF8ULL, 0x8933D8627807DDE2ULL
        },
        {
            0xEA020F76E7B3061AULL, 0x1868A10585E368B5ULL, 0x52FDBF2F54479303ULL, 0xEA3688C8BEEA346FULL, 
            0x2C7CC7319C5FD4F3ULL, 0x3E6289803B00BAD9ULL, 0x98B6D76C95A95A2FULL, 0xB2742B5C0E731EFAULL, 
            0xD2CC9CE2E282B82AULL, 0xD1D58F3D9A7D70BBULL, 0x2ACBB289859F48B1ULL, 0x93BB7846E3576D0CULL, 
            0xE96641C2571B8F90ULL, 0x54987D43DACDEFB1ULL, 0x67EB6829D528828DULL, 0x83E51DCE120767D4ULL, 
            0x0D6B7C9B5C84EF3EULL, 0xA4FD2C86862F22BCULL, 0x1BA6D26F984F09CEULL, 0xE92F4DDE051742E3ULL, 
            0x4BADD88D2CEB7A4AULL, 0xCE11B039AA4D5317ULL, 0x50FB6027A931B746ULL, 0xD1CC50FC56BD0B17ULL, 
            0x8D59C62274186D88ULL, 0x847F20AE73DAA935ULL, 0x2AE71F1300FEBE19ULL, 0xE2DDD1AFB78ABAF8ULL, 
            0xA1C04F26EFC92F83ULL, 0x63681DC98769D858ULL, 0xB259B48EF3B32F5DULL, 0xAB6E6CF089AE10B2ULL
        },
        {
            0xF950B7C1114F8F9CULL, 0x255E589978B039A8ULL, 0x27D7177529B2BF27ULL, 0xFF1AF57100C3E77FULL, 
            0xF50DA1B3DDA1E659ULL, 0x31B951335B608316ULL, 0xBC87D2486F311229ULL, 0xF8F5F7E75F44476CULL, 
            0x9A3D1ADFA003EFF3ULL, 0xB3B5B2ED63498D32ULL, 0xFFD41C057D8A6751ULL, 0x4738431947A47119ULL, 
            0x6F345DFB1810BA84ULL, 0x0DAAE9E678796361ULL, 0xB34DBA1D89A52E50ULL, 0x78C68609D4E49076ULL, 
            0xF93B3A803093C565ULL, 0x34E5A489852DE440ULL, 0x6692FCA76EFB2D9FULL, 0xB9510912BEE4487CULL, 
            0x04BA47D8D0D59FA5ULL, 0x026EED2AD0C56805ULL, 0x119165AF42273680ULL, 0x6E089CD77B65ED11ULL, 
            0x7B5E0F2A1181A09AULL, 0x3E6A472B48A202FBULL, 0x14626EE283024924ULL, 0xEC4FD24B3C7209C9ULL, 
            0x3DF7DAC65AD4A3F3ULL, 0x97A30BC9EFFBC494ULL, 0xD3F1C57A9D950F3FULL, 0x053CEA6795208639ULL
        },
        {
            0x3F1C47A9AE5C728AULL, 0xA2F2F77CD9043AFFULL, 0x83F87881A2A5FEA6ULL, 0xA3120CF575EAA718ULL, 
            0xB29D9A83AEDCE238ULL, 0x58184CE2029129C0ULL, 0x93F34C60810D0F8CULL, 0xD04008FACB83E95CULL, 
            0xAB77A8BB78A9E6B0ULL, 0x1F4F5B7E47EA0313ULL, 0x865CD706300E83ADULL, 0xDAF2D0CD807DC6CCULL, 
            0x7F8828F357191858ULL, 0xD7FB3792CD1B3389ULL, 0x6AFCB0545157BE7AULL, 0xA37705DCE5DAF1A6ULL, 
            0x5117B36E1EF693B2ULL, 0x181B054E7970EB8EULL, 0x70C90752071F37A8ULL, 0x757274F52CBF1359ULL, 
            0xF4E252538C1ECBCEULL, 0xF082A153011CD64EULL, 0x07FF374E6FCCC9FDULL, 0xD20AFC8E7E393194ULL, 
            0x8CBD655B934919A9ULL, 0xE08E189005E610A9ULL, 0xA0206B70D3EEEEF1ULL, 0xDB6004CABA4CDF88ULL, 
            0x6907275C65A3E334ULL, 0xC608474183FF9307ULL, 0x1163A7D8D99F47BAULL, 0xCF06896F0EBE3DB0ULL
        },
        {
            0xF108901714DC848FULL, 0x3E8879160A2570F4ULL, 0x0ED234051AB7C2CAULL, 0xF1FB447CC0CA1032ULL, 
            0x1E03B0E7C367F7CDULL, 0x2BBD87B0BC1024B1ULL, 0x51C7D5404757CEE1ULL, 0xCB1C1B7EF09978E1ULL, 
            0x817A72F24B6A1701ULL, 0x1F7AC4A039ACC409ULL, 0x7610254C7610C322ULL, 0xD9158A058AEC7BBBULL, 
            0xF5D6F128790CA633ULL, 0x73D8F636CA18DAFEULL, 0xCBF8082349A3CFFFULL, 0x04F4300202CB9D79ULL, 
            0x08BF6BB7F3B9A3D5ULL, 0x2F04237B00BFB25FULL, 0x6D32FD2E47B324C5ULL, 0x07CA553D1B10C322ULL, 
            0xC620F9F0CD42AFEAULL, 0xBDB232428CCD681DULL, 0x913E7451343B26CCULL, 0xAA663B735D9B869EULL, 
            0x0BFCDCB2CBD375CCULL, 0x0B51789568563C76ULL, 0xA8294D1F4FF7BE2DULL, 0x5E7858DEADBD9B2EULL, 
            0x540394F3F8DD21A8ULL, 0xC72DDB9E5E193B44ULL, 0xD9C91A9E0C887707ULL, 0x0B34FA0D62281A32ULL
        }
    },
    {
        {
            0x24D7949728CEA42FULL, 0x13A8F6653B8E1CE5ULL, 0xB5514FAFC23E3E00ULL, 0x40D7D770032B4F52ULL, 
            0xE395D702EE191B06ULL, 0x9CD0FB1DB9D28A48ULL, 0xD20AFEA2B8F2F542ULL, 0xFCFA408199EA0AB0ULL, 
            0x2F6A80AB9AFB89D6ULL, 0x041908C98586EA5AULL, 0x9094759AD094CA34ULL, 0x6FF83090F999DD75ULL, 
            0x583086FD081C89B6ULL, 0xAF1708E19375C43FULL, 0x76CC60AD60E76C81ULL, 0x503AC2C177C9F920ULL, 
            0x52277E685D0EE7F8ULL, 0xD2BCA07D5B7BC15FULL, 0xE13E1AB3908F5469ULL, 0xDA37101D32EF9F19ULL, 
            0xC566298C6A06EF4EULL, 0xD8C4CDEAC78957C6ULL, 0xDD42DCE46F2C9E3FULL, 0xC4A0EA98386D94FCULL, 
            0x73D460F4F370036FULL, 0x954322F8E3A517B4ULL, 0xB7AA10B4051B6938ULL, 0x6651532D50D021B9ULL, 
            0x07EAF9A3FBA472F8ULL, 0xC29C6912F632FFC8ULL, 0x775456FEDAE92BD5ULL, 0xDE222EE7F5463399ULL
        },
        {
            0x074CE3BD0A5BBFE4ULL, 0x785A67776BEBBF57ULL, 0xC498DC2F0460360FULL, 0x68709C9B71A0F4A3ULL, 
            0xB53FEE4054F58E69ULL, 0x4E72AFC88126E9A8ULL, 0x8F3779472CDF8313ULL, 0xAB8374DE5FE6CB80ULL, 
            0x5BBF9D95FD079875ULL, 0x6A361B4869E1490AULL, 0x53B93DA9FFE66F5EULL, 0xC97EB93E4DABF145ULL, 
            0x8DC1F10265C67259ULL, 0xEAA83ECF0D3B6B19ULL, 0xFBB36AAC11776DDCULL, 0x62FF728267F587E9ULL, 
            0xB75032EB15F6A7ABULL, 0xF5B6EEF904C86A0FULL, 0xB9907DEB2042C16BULL, 0xF739F9A10937F06EULL, 
            0xAB10B292A33779D5ULL, 0x9DB22DF64B73D4D6ULL, 0x2B9BCC803680DA40ULL, 0x28A74D6332936DD2ULL, 
            0x38BBE19F0F7E682FULL, 0x5FCF72D73B80E863ULL, 0x93017F66096E69ADULL, 0x64DF7E494686CF66ULL, 
            0xD0C8C6FC7E9BDFCDULL, 0xC72FA0BCDEDACA65ULL, 0x18BF9F5CD37FDF21ULL, 0xB659719E7CD32C91ULL
        },
        {
            0x38368B05EFA93E74ULL, 0x449BBBFA8510A8E3ULL, 0x644D44C6C9267ABFULL, 0x0C976A68FEBF5E97ULL, 
            0x358A519F445FF11FULL, 0xC9E6646029D6AC99ULL, 0x12029699B3C93886ULL, 0xA3FBBFCC4336B3F7ULL, 
            0x1C31BCDBC67E9590ULL, 0x1A7DC4534D6D9A2FULL, 0xA469FEB38BB03FF6ULL, 0x5B80A1EFAAE6A62DULL, 
            0xE29F9FC7B392F062ULL, 0xF7775FE8FCD35969ULL, 0xE163FD171282C11BULL, 0xFEFE985CABF44C84ULL, 
            0x3F13D4188BF0F74CULL, 0x2C116A2117D395A6ULL, 0x84BD37C0740BF88CULL, 0xD8B4E71BB192B00AULL, 
            0x36C798C0F5BA90D3ULL, 0x14E87B80AA975EA7ULL, 0x6F79A9374BB7CE54ULL, 0x8915A688A0B4A226ULL, 
            0x11B9F1042B369E11ULL, 0xA471ED02D15F70ABULL, 0x862F6C3A14025265ULL, 0x5F29515F30F50BF3ULL, 
            0x1FF424F9206D0C6BULL, 0x1C843E07938D3FEBULL, 0xC31D774A8EA9F31FULL, 0xEE4A0F4D532826C1ULL
        },
        {
            0x4C3F9CC2876BC4C4ULL, 0x4ECF0DD5B00EB575ULL, 0x64086169BCE5EEE7ULL, 0x854C120389DB24A8ULL, 
            0xD871774AD259164AULL, 0x616A9787A234B48CULL, 0xFC69698B37BFC50AULL, 0x63798935C6FBCCBFULL, 
            0xED7CD04B77E368A3ULL, 0xA8B589A639E5B017ULL, 0xD07B9C473EEA3189ULL, 0x874DFFED11D00328ULL, 
            0x74B972883458F1D7ULL, 0xCC6192E0FC37D889ULL, 0x6FF7F9F4CCB76FECULL, 0x8B75BABA7675D17DULL, 
            0xB695E9EAD455BD2AULL, 0x51164C1B6927F456ULL, 0x4C973854DB8874E4ULL, 0x04B22BCFAF81AAF3ULL, 
            0x114DC252EE6ECD94ULL, 0x534706F6562F7505ULL, 0x19C18E1DBD753C8DULL, 0xBAB1385B1353D2F3ULL, 
            0x8564D52BBE2CE8BEULL, 0xDA867B04059FB1CFULL, 0x08EDB4E7963620FAULL, 0x89E4B1D67F934A11ULL, 
            0x6482AA5E65B5CC0CULL, 0xC08FC415B04A0A9FULL, 0x9D5C3E5FBFCAE4AEULL, 0x1D19849730707791ULL
        },
        {
            0x895875FE7A28FA99ULL, 0x3BD365F767979A36ULL, 0x5BB366081FEE0CB3ULL, 0xF0BFE493EFA494C3ULL, 
            0xB82210FFE50CEE0FULL, 0x343572FE5142BCFDULL, 0xCD4FD1DE67C5BB5BULL, 0x658AE12409A8E10CULL, 
            0xD61D8150A7667C67ULL, 0x576330E32FE1E821ULL, 0x4035754B94B96F82ULL, 0x7D06C5E40F8758F6ULL, 
            0xEDB9F3DBD200DD4DULL, 0x0EF5A5DE1426725BULL, 0x6E57A322A5240302ULL, 0xB948F47E42422A3FULL, 
            0xB575D0B88EF516ACULL, 0x9497820D3A54E9EBULL, 0x8C604304924D0C3DULL, 0xB96C2730AE7C323DULL, 
            0xC5A7D6E093CFB819ULL, 0x70404C40EE5C46B8ULL, 0x544E23A43E3B14ACULL, 0xD2F4652DBE00B08AULL, 
            0x6EA3DCC415D198F7ULL, 0x32493554D6CB0784ULL, 0xC26C87BE4A9163C4ULL, 0xCC928E4749623C81ULL, 
            0x92BDEE6FCBEEB261ULL, 0x91C70BC1F8F0A8EAULL, 0xA8D83DD2EABDE1EBULL, 0x268F5AC644222C74ULL
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
            0x3FDBAD5A26997990ULL, 0x5B658868A7153141ULL, 0x4008BF1BB1F2ABF8ULL, 0x409482EC5296F347ULL, 
            0xA73AFDCCC411BBF4ULL, 0x54564D60EF659F8DULL, 0x0E4E74F616C3E821ULL, 0xFB424E195EC5539EULL, 
            0xE84915EABFF16891ULL, 0xDC33DE47E19F1E90ULL, 0x48C82DE50DE535B1ULL, 0x9B589B0A02850B59ULL, 
            0x07684CE16084E0EDULL, 0x400DE598172DD16DULL, 0xD74A4DB8905F3D1BULL, 0x69D9C3FE0B6FDED0ULL, 
            0x848017545549F567ULL, 0xBE1F53F36EAEB43CULL, 0xD4CBE48DF871E539ULL, 0x66387245FF6A710DULL, 
            0x67C6D6C31D338542ULL, 0xF23B0800DE74CA01ULL, 0x6C3708776097729BULL, 0xE5582EEE1E6BED1BULL, 
            0x6DDD028EF462C958ULL, 0x34DA1B105F9ED276ULL, 0x72CE3505E71C0E0FULL, 0x5E3E5575C3FE4748ULL, 
            0x95DF626FAF259AE2ULL, 0x49DE5F4A517CF0FBULL, 0x3AE30417FB0B8B30ULL, 0x78E98051804A74A5ULL
        },
        {
            0x0C9A691CF510027AULL, 0xED5EC11847B1DC49ULL, 0xF0D550D8AEB4731BULL, 0x14B49009F94F6760ULL, 
            0xBF6DD8BF36BCE256ULL, 0xE62B4BB63D1E0D03ULL, 0xE43FE22D5FF9E2C6ULL, 0x3E800A1CF42D29EAULL, 
            0x45A445D2DF668480ULL, 0x68829627AC54AC53ULL, 0x9BF8424DA7702B18ULL, 0xB067792ECD82AAD6ULL, 
            0xBCED0269D6E645C1ULL, 0x19BBB7FBC25299F5ULL, 0xC77788AE884EA938ULL, 0x97F3D4E5A795DEA1ULL, 
            0x27AA860C85973C56ULL, 0xAE7FDB956ADD4151ULL, 0x8D643ED1E07E9D43ULL, 0x4B532AB91299D740ULL, 
            0x8A7D955CC2A64427ULL, 0x69CB2B65F92DA958ULL, 0x1B4C355CBDF3BD59ULL, 0x2098E373433B51C8ULL, 
            0xD65DA18552F7A694ULL, 0x0B21280E1A466D02ULL, 0xF04A02FFE9CA1402ULL, 0x5A8606F77DEEE313ULL, 
            0xCE33A6F4FC57A0BCULL, 0xE9D37DAB3AA00E09ULL, 0x3344DD7B7CFB8670ULL, 0x0D48E3B5AF4F1236ULL
        },
        {
            0x9CCFCFC29236CF35ULL, 0x5BAD0D5BC052B22DULL, 0xFDD856B76C2D2FFCULL, 0xBE57C1D26CEE6AC3ULL, 
            0x0E015701085F8E08ULL, 0x41DF3D03311DA341ULL, 0xE8D5EE5BAAD08C81ULL, 0xE1AE00E09D402CD6ULL, 
            0x20775EEAAF0E1A12ULL, 0xD47D0A45520951B1ULL, 0x47BD23FB447FCD60ULL, 0xBFA7449936B3D784ULL, 
            0xC47890F9A4704CF6ULL, 0xCF5466BC2F2AF608ULL, 0xA58C32FEC2F4AAAFULL, 0x40E6CC56999606CCULL, 
            0xFA11BF0E6DB368C9ULL, 0x5E92EB7717DBFE29ULL, 0xEFF26DBC6AFFB7AAULL, 0xE8C7F634515E5C46ULL, 
            0x441D920E446934ADULL, 0xAD432EFA22522E0EULL, 0xD1D939160524EB75ULL, 0x4F8EC1147C19793CULL, 
            0x91B5AB3C817AF736ULL, 0xEAD95743EB664A35ULL, 0x8DC3668B1CEE2D00ULL, 0x7DFCFD760391AC4CULL, 
            0x8A674EE4031DBFF8ULL, 0x819E1BDB75140949ULL, 0x342890888DF32310ULL, 0xAFC5343440B967BBULL
        },
        {
            0x01EB132EAA420758ULL, 0x54DC3DEBE2528352ULL, 0xAF703306A3F633B1ULL, 0x63D8D782B6FC7E45ULL, 
            0x0716986AE6D6F296ULL, 0x81E9A182FB66C862ULL, 0x0CC348730D64D892ULL, 0xB67164E876FF78F0ULL, 
            0x16321B3AB02BDD53ULL, 0x66D70F7C357094A6ULL, 0xD0CEE1B785EB6108ULL, 0x31E96F233A3A5646ULL, 
            0xDCCC033020B6E163ULL, 0xDA9C69B331F6E576ULL, 0x2B3D2999CFFFF713ULL, 0xFFE7652F35881623ULL, 
            0x0C767307EC3A0ACFULL, 0x5F1B51866F251C45ULL, 0x3419CB3D932C8EFFULL, 0x2D9F998428DA1AEBULL, 
            0xA4FE9157BF903203ULL, 0x5D39FFB8CE1D84B9ULL, 0x45E23E7A07BA93FFULL, 0xE6CE4ED923FAD076ULL, 
            0x543711F8E4881472ULL, 0xDFEE0312D24F1840ULL, 0xF2F7DFA20ECA5057ULL, 0x2AD8C93A35E6651AULL, 
            0x634E90A32C32A872ULL, 0xC421E821FA348DD4ULL, 0x7D4B823D86298C02ULL, 0x4E3434124D35F1CAULL
        },
        {
            0x9B3669D46FDAA004ULL, 0x1AD250C5ADFA44A5ULL, 0x78B4E9E1D06542B7ULL, 0x7FE0DBA514B4A3BDULL, 
            0x01C07EDAC2009DA2ULL, 0xD561358C5B85D66AULL, 0x5AD62A6ADFDF1C87ULL, 0x8FCFE176F578F808ULL, 
            0xC565BB757DF2A2B2ULL, 0xC06879971A4D6D66ULL, 0x1205DC201D3F7224ULL, 0x16107DAD02D785A4ULL, 
            0x45B86EFE17E8B08EULL, 0x0F74B358373DA4F4ULL, 0xCA8571E66E61913BULL, 0x744F933E0F1A8E1BULL, 
            0x5E019E7E6DEE17C0ULL, 0xA52D34C18E542DDCULL, 0x486B8779D28B5FA8ULL, 0x72C73ECD1E7010F3ULL, 
            0x83909B59F59D2D5BULL, 0xBD05E514FDE310A8ULL, 0x8999EF161AC40E96ULL, 0xC1DC0FB1BA543026ULL, 
            0x4F69E5E277637DFBULL, 0x9CC0500092BB558CULL, 0x12F6571F73F55251ULL, 0x8DCDA1D873CA297EULL, 
            0x7691CFE108F1C681ULL, 0x26F2232056C98900ULL, 0x62F8E98EB7B15DE6ULL, 0x3693398B7B856575ULL
        },
        {
            0x335A9D06F0FEB95AULL, 0xEFC7C9798D4BABCFULL, 0x0E0E8C3731D5113AULL, 0x3B3B476282F42D3CULL, 
            0x3FB7F1C86A4B3F8CULL, 0x7D92F098809A223AULL, 0x469EE1092E70570CULL, 0xFE65FA57D2DE0558ULL, 
            0x2989FFE36AD03AC8ULL, 0xD5B19930E1510400ULL, 0xF6BEEB3070B39CD5ULL, 0x044A360EF978393AULL, 
            0x6DE7E6EC552C75F9ULL, 0x1E7F4668B50B4842ULL, 0x9E666A7E3A1AD98BULL, 0xB64E72352AB44CC4ULL, 
            0x09D9DB74DC97BD78ULL, 0xEEC596EFBE6D4B10ULL, 0x27780E6742EE9F18ULL, 0x3ED9F59EB3F8B321ULL, 
            0x9C6AA0E558DD27A2ULL, 0xF876D07B3859C7FAULL, 0xC2B6A77F2F7E75B2ULL, 0x2ACB36D85991C47BULL, 
            0xDD743E5A2F347818ULL, 0x81FE0A566C442257ULL, 0xC81FAD9209E6C86BULL, 0xAE19B6A1769A7092ULL, 
            0x35C24DA51D5DFD3DULL, 0xBEA6EB6E74F1E5CEULL, 0xB41E92F049FBF68FULL, 0xA640BE8D51917BA2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseEConstants = {
    0x7CB80A95217802A2ULL,
    0xE5AE30DED83888DCULL,
    0x618C71CCFD704503ULL,
    0x7CB80A95217802A2ULL,
    0xE5AE30DED83888DCULL,
    0x618C71CCFD704503ULL,
    0xAD1B95F61EEEF106ULL,
    0x82743F0D26F7987AULL,
    0xB7,
    0x20,
    0x44,
    0x26,
    0x33,
    0xF4,
    0x4D,
    0xA6
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseFSalts = {
    {
        {
            0x79C2C22269524189ULL, 0x154ED33A800B8336ULL, 0xFDCD82C7935C66F3ULL, 0x9FF69E1A463A2958ULL, 
            0x6F93F70444574E64ULL, 0xD4C6990E610C1A27ULL, 0x32A2C361DBCA1D5FULL, 0x42BF3E8883F8DF85ULL, 
            0xC2EBE8287DA9AFABULL, 0x08965F83C781998FULL, 0xF922C11A1F54A246ULL, 0x9B2BC381807CCD48ULL, 
            0x7A5AA55683B69C78ULL, 0x0D1648887AF2CB36ULL, 0xEE9E999D4DCA20C9ULL, 0x063FBECBC75A0149ULL, 
            0x93EB7124C391594DULL, 0x7A48BBA3629D0891ULL, 0xDA5B6B69C6F645B8ULL, 0x35E3B7AD4A7DE1FAULL, 
            0x304D23DD282EFB6BULL, 0x885A0A5A022B7560ULL, 0x1F6042BFD8DC617BULL, 0xDFD7E19EC3536A13ULL, 
            0x36599A020A37BDCAULL, 0x50DF3A98D191A469ULL, 0xBFFA1C97B6D71922ULL, 0x339965112010F9BDULL, 
            0xC7EA883A6EBEE189ULL, 0xF9DF75444AFEBC86ULL, 0xE8629181EEA43567ULL, 0x843A534834D78F4BULL
        },
        {
            0xC20802C33E8F58C0ULL, 0x3DC55F7D23CA2BB4ULL, 0x0D7B52E9A3B57741ULL, 0x1C6192E2AC183ED0ULL, 
            0x1FA9B1EDCDEFC71EULL, 0x0D8A62F6962F8B30ULL, 0xB1443519C50FCB19ULL, 0x370859C8E7B87F14ULL, 
            0xEF8FDC38BE544D6CULL, 0x1E8638689B35BD31ULL, 0x36017E0C460B2F66ULL, 0x914F6644596F415AULL, 
            0x906DA67A8CEB456EULL, 0xCA953434961F6557ULL, 0xB692F65C16659609ULL, 0xE72842709FD08F9BULL, 
            0xAA472F47DB28F2E9ULL, 0x364727F74C11B37BULL, 0x48A17E9840BE9E43ULL, 0x85FCB4F5A53A8F69ULL, 
            0xC9C7E386101A9FD7ULL, 0xF452731F9D6947E4ULL, 0x64E2B4F47EDAE9F6ULL, 0x1C3AF823A58D7C25ULL, 
            0x7D5DCAD9C8E2DB69ULL, 0x75C52BBDA0678B94ULL, 0x9A932E1867908B05ULL, 0x7A826C3CE95BDF56ULL, 
            0x79B9B46AC277B571ULL, 0x51F2D7522889B362ULL, 0xC4774F1040A8A1ABULL, 0x7A1AE243281D8709ULL
        },
        {
            0x6B9C1330DFBF9165ULL, 0xF6D8DFF67D65176DULL, 0x6FB92ABECE6A4D09ULL, 0xBBB947488362EE12ULL, 
            0x93BD4EB840089ECDULL, 0x75C5E7AE99DBF887ULL, 0x99683AFEC37CEDBFULL, 0xE46196B3796914A3ULL, 
            0xD435F6FC1E17E6CCULL, 0x81B91DE8171F105FULL, 0x6A7A012C72DAC8C5ULL, 0x01A1C0C0B52497B0ULL, 
            0x775D0C24BF170D59ULL, 0x505785533D551214ULL, 0x668B2E6518E16B0CULL, 0xA0C429783321C71CULL, 
            0xC3B5B8A6EA3E9CD1ULL, 0x814166E4BA9949B9ULL, 0x45A241C3CC5AEEC2ULL, 0x5D38C00464C0B7EBULL, 
            0x7149A85CEA5F5D9CULL, 0x1747F16F0BE25DB6ULL, 0x8909F729543CE7F8ULL, 0x7FC4FADE95E1337EULL, 
            0x47B62880EE3C4A41ULL, 0xBDD69F86D1DB6A85ULL, 0x23DF38D54F011DD7ULL, 0x02922B55AB61820BULL, 
            0xD051536A63058B66ULL, 0x9212BD292EDEA149ULL, 0xD3C00176AF2F149BULL, 0x547C68ACF3B360D7ULL
        },
        {
            0xB1C5B5A7805B91B0ULL, 0xFFA7D600BC8DB43EULL, 0x76950C4C3C91416DULL, 0xE99281DC340CDE33ULL, 
            0x42D1B19D7A15CD5AULL, 0x2D11B32DF71C2018ULL, 0xF97D65D496D49745ULL, 0xACF413F8CE47722CULL, 
            0x667736BFFEEE36BFULL, 0xECE822105CB9B509ULL, 0x0DD027EAE748D6EFULL, 0x4A89EAD0A5C09885ULL, 
            0xD83461BD3E54AFA7ULL, 0xF12366A8B87799F3ULL, 0xA2C86E119DB1A160ULL, 0x348E4BADAE6AEF1FULL, 
            0xB4FA257C2687E2E6ULL, 0x48C1C54BE57D3C44ULL, 0xD8C030A131DF73FEULL, 0xD1D31109C48D2D52ULL, 
            0x2EB19AA3BAF7ADD9ULL, 0x611EF01157A4B766ULL, 0xD56124CC898335F2ULL, 0x6C0186B116F7B65FULL, 
            0x9EAE8B0D4BCCEFFCULL, 0x2A5202DA3F8C4904ULL, 0xBF859A0E55011F30ULL, 0x211B42CFF1388272ULL, 
            0x7EB378973C0AC60FULL, 0x5EF0F34F502DB9AEULL, 0xC695B60C5EDA2786ULL, 0x87DB060B0D63B161ULL
        },
        {
            0x953AA32C389E088CULL, 0xCCDEFA8FA45069E1ULL, 0x705FB7B03819CFFCULL, 0x0F56692567EE8ABAULL, 
            0x0BAAB9D96B32D345ULL, 0xE6C5A1DCC1F0E3FDULL, 0xDA594C57C1660A35ULL, 0xAB316786E12007BDULL, 
            0x562CA7E805072794ULL, 0x3EDA2258529EA698ULL, 0xE3B0EB01DFC06EE2ULL, 0x319E9D9AF6D0695BULL, 
            0x151A263B8F28E0A8ULL, 0x5980764A479E7911ULL, 0x8236A73390313D93ULL, 0xC614EE8E00D5F7B8ULL, 
            0xEF07F847F28AE22BULL, 0x448099C21029DF97ULL, 0x93BECF383F6F6CF8ULL, 0x86EE26A08FE3FAE2ULL, 
            0x30619FB1557D3188ULL, 0xF2B51641C0F1B19BULL, 0xA7D7864DE14C616AULL, 0xDED70EC36D1A059AULL, 
            0xB91B86A6B33D1BC1ULL, 0x34ABD2A135984D0FULL, 0x69962F8288252FE6ULL, 0x3737304B14E8EF42ULL, 
            0x213A2FEF08183585ULL, 0x0035A79DCE17A2D2ULL, 0x79BFF644B7B7A10DULL, 0x96AC1D83567C63A2ULL
        },
        {
            0xC1FAAABAC14A5A61ULL, 0x49E6B04A4DC41967ULL, 0x8E18355E06224C91ULL, 0x0C6393BEE9495288ULL, 
            0x417194B251245C23ULL, 0x30BEBB3054ECE63CULL, 0x11AC9F2FFF309B21ULL, 0x4844B9214EE029C4ULL, 
            0x05D7CEECEF265BF8ULL, 0xEEF2C67BEDBDDDF5ULL, 0x98CA3C32FF7C8EB5ULL, 0x877892B4B6F7AB41ULL, 
            0xCA69FF306C3E0C50ULL, 0xA255E26A96575E36ULL, 0x3250243E144E558FULL, 0x412893CEEC845E04ULL, 
            0xC855681E2EE59607ULL, 0x0E36717BAABC552DULL, 0x4B9905815A38EF87ULL, 0x119C0B8BD2DA1CFFULL, 
            0xACEA372C6EA3FEB0ULL, 0x9B4D510B3CA54936ULL, 0xD666D434858B76B6ULL, 0xDD119BB7805F69A4ULL, 
            0x1164BF1EEC298E0CULL, 0x975CE4E67F8A5082ULL, 0xBD38535ACCFB2A1BULL, 0x36BB34C770B8EFBDULL, 
            0x587A4980B53EEA38ULL, 0xCBB40138604A9C78ULL, 0xA15894B8C3EB6D67ULL, 0xAEBB4262EF88A367ULL
        }
    },
    {
        {
            0x400511380CEA73C5ULL, 0xC4C741501B25622BULL, 0x2A7A7EBF984A1325ULL, 0x9F88C7354B76F061ULL, 
            0x64A5A70D8FE07B5FULL, 0x31D77E2C58DDC52EULL, 0x09F18770F9C8AC1DULL, 0x4DB3650BE96B5059ULL, 
            0x8E2E3954AC3F54C9ULL, 0x9217B345578D5943ULL, 0x8483B205652F4B98ULL, 0x7C86C51C290B44D6ULL, 
            0x17355CBA2612E00CULL, 0x9D00844554B5391FULL, 0xBAF9B4734B80CBAFULL, 0x565643C6799DFBFAULL, 
            0xB30951D507061B6CULL, 0x6B8613F1D5DEE948ULL, 0x7EFA80994F20567CULL, 0xB790EFE06462467BULL, 
            0x55AD893B1BCBAAC9ULL, 0x31EC59C4CE574556ULL, 0x89A72668F5A30068ULL, 0xC7B8E617CC1DBA16ULL, 
            0x7499BCA89E11B5BAULL, 0xFF1691FE5B2B5667ULL, 0x2A27365EC1097E6BULL, 0xE64F4C66829A05C8ULL, 
            0x5E001D54B2D63080ULL, 0x94A9062ADA98BE21ULL, 0x7CC3B94F02B5E9DCULL, 0x56140778B8AE32F7ULL
        },
        {
            0x6A485D6901A0C802ULL, 0x7A0541F0759DA016ULL, 0xE537337FEB060875ULL, 0x6C1E154F77F31B5CULL, 
            0xF3D9AF9C5AF9DFC3ULL, 0xC035C04BEBA9028DULL, 0x6E339DF2AB334111ULL, 0x8635C6F24A4A99A1ULL, 
            0x59FDCC520E6A56A6ULL, 0x2068450E31D0AD2FULL, 0x9AB9E6DA74EE3E08ULL, 0xBC75B691A68897F5ULL, 
            0xB95AD60A7F96E837ULL, 0x75258FC719164FEAULL, 0xB35B8D1D0699FDD8ULL, 0x7A245BD02030092DULL, 
            0xDEEA7831CBE82CEBULL, 0xB564F07F7DC2BA2FULL, 0xF89A70C2EAFEEA1FULL, 0x220E41876690D9C8ULL, 
            0xC061559F7F6A5096ULL, 0x6EBBC226D3303B92ULL, 0x81D71B4306D4499AULL, 0xDF5BAE38FF0096CAULL, 
            0x411EF5290C2D411DULL, 0x0731D674D5E9B993ULL, 0x3C5BBF10D43F6F88ULL, 0x7C0CDE69E433FB32ULL, 
            0x18827DC7DC33F1DBULL, 0x464DCDDFDCB46088ULL, 0x231D35DB1679B556ULL, 0x3C8180452D099875ULL
        },
        {
            0xFE530F2ECE3E2627ULL, 0x0B738659E220197CULL, 0xD6E1D31150D13FDCULL, 0xE2F3A2FEA616699FULL, 
            0xFDF793EDF7F48F43ULL, 0x8A17C9BD29D97CA7ULL, 0x745FF6554C8D6C0EULL, 0x7E8B7557593F8209ULL, 
            0x6D60F42259CA5B38ULL, 0x13C2440AD7AAB16BULL, 0x9B8A47B71CFDA2DBULL, 0xF2002376C8FAE995ULL, 
            0x869DE3D14C7E3838ULL, 0x3227556A3C6E82C1ULL, 0x3B186513C2971CF4ULL, 0x21A12F8863E534BEULL, 
            0x46C73E43596540CFULL, 0x71CFBA06C6D4151FULL, 0xED9709DE1BF25841ULL, 0x41FF3C0899A0DB25ULL, 
            0xEA799DB0CF8DCF9EULL, 0x803359BFE30BFA0DULL, 0xBCF802504B7F7E65ULL, 0x627EFAAC75C93EE8ULL, 
            0x9C268BAF93BE020DULL, 0xDE122B96A9B2ED87ULL, 0x09ABD289083A438AULL, 0x623DF2ECFEE97269ULL, 
            0x98E7905BEE7136BFULL, 0x52A10E1D0A67FBAFULL, 0x4A056F4630BE042CULL, 0x5F937F15B6BB16D4ULL
        },
        {
            0xADF3CE62CDC8C90BULL, 0xCA5418EF86E460D1ULL, 0x335F69BC7D48F5D8ULL, 0x9A4BB01068797A7EULL, 
            0x47FAA8BE461C1358ULL, 0x4FE6ADAAF46803D8ULL, 0x78299E1BEC857628ULL, 0x5245B72A126E0455ULL, 
            0xB28E673CEBB336AEULL, 0x37099F758D33FB99ULL, 0xED2CDE42DAEBD4D1ULL, 0x9FA7C66F6502EABBULL, 
            0x7028BE0E7A9F3F34ULL, 0x4616BBFBB64A06DCULL, 0x5DC9FA19BC45B4CFULL, 0x993E4AF7C0554522ULL, 
            0xA6E45AFE871C78DDULL, 0x18BC392BA5B208C7ULL, 0x0E01B5F4B0F75920ULL, 0xB92BE40DA1215FD6ULL, 
            0x3BFC913D2A4DA666ULL, 0x2A3E538FF0612BCBULL, 0x6CC425139923CC9EULL, 0x12191CC3AD6063A3ULL, 
            0xB84923ECC4E5A9D2ULL, 0x4023092FB2ADD896ULL, 0x74A6A1A5D0B68D39ULL, 0x762D5F5F98CFF6B4ULL, 
            0x4EEAC0288D7D06DAULL, 0x0BAB1552475AAFCEULL, 0x213E8C7B225E04F5ULL, 0xC4B1029E48256BC2ULL
        },
        {
            0x2013E3A776936584ULL, 0xB25209143C538F4DULL, 0xB4E921989B7629F3ULL, 0x2FE87F6F114BD443ULL, 
            0xAC8259D303707C93ULL, 0x7869C88B2C24DF6EULL, 0x1F6986A84706361EULL, 0x27E3F66377E635FCULL, 
            0xB11CDAE4FD31498BULL, 0x0F60AACB2DAFD448ULL, 0x9463A80A2032D5D5ULL, 0x423BEC95B9202BBEULL, 
            0xA588AB6652B63244ULL, 0xCFE7EC45D392AD4EULL, 0x05E815F4D20089EBULL, 0x82073209E6DBA4B0ULL, 
            0x53FDB8933A20E7B3ULL, 0x80CFD06CD1B3067CULL, 0x2BF779B85A892A6AULL, 0x77F4E5DCCF1836B0ULL, 
            0x7745B5741E26DC3EULL, 0xD3243D45D2A1E56AULL, 0xF35CD66E0C63FAA4ULL, 0xD43064EC6BE1C421ULL, 
            0x494CA5B14959CA00ULL, 0x42EBC7F49B1C63AFULL, 0x6EA7F4EBA4D31A9EULL, 0x56A250D522E53F63ULL, 
            0x66B4026A5BEA8D8AULL, 0x2B66C52F283A94E3ULL, 0x711C70D0862BE00FULL, 0xB5097088CC6F8F9AULL
        },
        {
            0x880CC30927C80B4BULL, 0xD267D5E5C235F829ULL, 0x5043409E1D8CAC8CULL, 0x784D12454A5E2CF4ULL, 
            0xAD6D9C9DC8CB5C0DULL, 0xDD5248AB46C3B45DULL, 0xBE5B271F92854482ULL, 0x73ECC35522983EDCULL, 
            0x7F27E6EBCBD3BB6CULL, 0xDE547062CB21CC42ULL, 0x6E7588F5D4F40E11ULL, 0x6CA596862287AE54ULL, 
            0x51CDB5EDC9C49EC6ULL, 0x600E092E27615ED7ULL, 0x9859D865ED7C9818ULL, 0x4BB1227C67927A0DULL, 
            0xA2A627CF13AEE0DFULL, 0x10E459AC767661CCULL, 0xC712991E13DB3279ULL, 0xEC8FA2183A305CE3ULL, 
            0x0FB5C44D05E002DDULL, 0x5FFAAB5CC760CE68ULL, 0x785726C527D8E05CULL, 0xB3E95829251FF9F9ULL, 
            0xFA25E8BCF4E6EA38ULL, 0xDC97DB76D7425E7EULL, 0x983790803CEE2C96ULL, 0x97B2E6A1C6CC91B0ULL, 
            0x18FAB67C31AD0EB6ULL, 0x6BFF834279F1F9A5ULL, 0xD951D4F370F2E6DEULL, 0x41E38565C7CFF0BDULL
        }
    },
    {
        {
            0x3E007BE64EEBB957ULL, 0x20C102DB6079B7F1ULL, 0xA642C1BBDED4A88EULL, 0xBF5DBB48FA763D15ULL, 
            0xF75702D41AC93857ULL, 0x3B05484AE9E81D06ULL, 0x033C8B448E21A1D1ULL, 0x25414E1F7F872829ULL, 
            0x7C97AC3BD91C7AB1ULL, 0x134B44A5EDD9568BULL, 0x8487583E28E63D43ULL, 0xA3B9EEAFB0956F0DULL, 
            0x36025F94DA7D1A5AULL, 0x7ED7FB2A6EFF86E0ULL, 0x9428FAFB064A1935ULL, 0x5B5E15447C1E3251ULL, 
            0xAA958B3BFC05526DULL, 0x7B34C24AE8F4394BULL, 0x68703452E8AF00D2ULL, 0xF10BF9D68F210A91ULL, 
            0x76BC78324FBB2388ULL, 0x52FB815435D95E64ULL, 0x0DA3F78C636F527FULL, 0x1FBEDE21FDAF3879ULL, 
            0x83FAB82F3ED7F6CAULL, 0x2FEE4B0F1E325849ULL, 0x65C21F4A7B097742ULL, 0x8EF7575926B3523EULL, 
            0x7EEC99FF9970F600ULL, 0xDC0D1A2E853F441CULL, 0x2AAB114AD2AE97C4ULL, 0xD7E805D1EDEE094AULL
        },
        {
            0xDC36F42D1758B7ADULL, 0x853A351572274FF4ULL, 0x7ECF0CEAF96FCB90ULL, 0xB5DB197485791ECBULL, 
            0x4868941C97FC085AULL, 0x73BB122A2DAF9220ULL, 0x1043088B4121AD4FULL, 0xC33786F0FD9C2954ULL, 
            0xAEA60E631EF5ABA5ULL, 0x46008767E9BC6A91ULL, 0x327EDC8EC0374C38ULL, 0x5F89E579F7EE8FE3ULL, 
            0x76891245BA6CD66DULL, 0x9BBDD4FDFE720C05ULL, 0xBF72143E8F9807D2ULL, 0xAABC9E992FD8E9E9ULL, 
            0xDEFEF017CE45037BULL, 0x00F0CC319A523DDCULL, 0xEF3354BFD4FCBBCFULL, 0x9BA2EBE96E1BD066ULL, 
            0x0E031AFDEDB61DD8ULL, 0x8C6881218B95595DULL, 0x2D44092A660EC69BULL, 0x18DC316975B5E75CULL, 
            0x43AA9D06D6D52647ULL, 0xF57A5BC425E4AA0BULL, 0xA3407FA07A0FB5C9ULL, 0xC4157D15177730EBULL, 
            0x054FFD317EFF4F2AULL, 0xF32F7D98DAAC45DDULL, 0x0D964F9DAB98A191ULL, 0xC6B26F02EADCB8C4ULL
        },
        {
            0x98403005BBFFDE03ULL, 0x09A43526C5507609ULL, 0x2C1F3C9916A00699ULL, 0xC7E9D463966FF0ACULL, 
            0x0127A9C6C9EBCCBAULL, 0xC43FD5CB672A530AULL, 0x1022D4168F2ED4C0ULL, 0x3E2EDCF4FC2B4E0EULL, 
            0x2317998D205241A0ULL, 0xC61D1B1B1C708F35ULL, 0x6DB632B5799AC56DULL, 0x188C96248F14B199ULL, 
            0x41C0B72A3BF9E12BULL, 0x134DCBF58B60C61BULL, 0x0618563D0522D12EULL, 0xC15E1CC1B89E9B65ULL, 
            0x87199FD553B2A717ULL, 0x3358532E10693179ULL, 0x190CC7796D79B0B7ULL, 0xE68632EA2653558DULL, 
            0xF835B74112CCC07AULL, 0x4BC59274C4065EB7ULL, 0xF84D6421459DEF52ULL, 0x910D4EB4E4509A6DULL, 
            0x052F5A28B2A48E34ULL, 0xD47F561FD3792BCDULL, 0xFBA06200C0436DCCULL, 0xA92F708C2BE47981ULL, 
            0x9FFF5C9B8ED4551BULL, 0xC6660FBD72A1C3BAULL, 0xE29F033D9956500BULL, 0x84360BC608103FE0ULL
        },
        {
            0xBD6E1CF74EDFBFD4ULL, 0x46142D6152C2BA49ULL, 0xA3C0B0D613E1FAEAULL, 0xF2A05E9A41243FD6ULL, 
            0x59A20275994DB955ULL, 0xFCD444E0CE4167DDULL, 0xB50170150DA10A1DULL, 0xDC81125FEFEFF606ULL, 
            0xE68D667C5707B4AFULL, 0xE01A2EE9D09BC5BCULL, 0xEE6165EDDA96CD6CULL, 0x3BC6EE3667826A83ULL, 
            0x565088CD2B9D5BD8ULL, 0xED90A8DA0AD3C93CULL, 0xEA3470360292125AULL, 0x7C7155BE01425895ULL, 
            0xD8E427E1FAEDE7C3ULL, 0x90A779AB93F384B4ULL, 0xE5B26EF5A62EF2EEULL, 0x218644751D266321ULL, 
            0x831E9CCC74746C6EULL, 0xB131CAE8B8E874EFULL, 0x5476D8265B7823DCULL, 0x683633E7C8A928A3ULL, 
            0xC3845211BD85E6FBULL, 0x72DF416DE73998B4ULL, 0xE757C7FA10AD1139ULL, 0x1824E9F29F7B5B44ULL, 
            0xDD485ECD497EDA9EULL, 0x8E1BE6C99983A664ULL, 0xFD2D9D4C51767A4DULL, 0xEAD5594785A3A745ULL
        },
        {
            0x746E8705CF9B994FULL, 0x2889D06E09D388A1ULL, 0x55E2FEDC67D76792ULL, 0xEC07D7DE220FE3F1ULL, 
            0x1B6E26143A75D21EULL, 0x81B659C460A190A9ULL, 0x138082CDDAB161E5ULL, 0x30519EC44F2AC71EULL, 
            0xA31EF8D0B526A6A8ULL, 0xF8706DE6A78EBFC0ULL, 0x29B76C4B102C2598ULL, 0x6DBED94C42386978ULL, 
            0x5377E74D59D8026BULL, 0x9A258DAEA408D720ULL, 0x965CD6E2D123A327ULL, 0x2E4DCA6602A604DEULL, 
            0x2B3A8FBFF17F086CULL, 0x22DA32FEC82E5153ULL, 0x2CC2890223B2299BULL, 0xFCB3DAAE64B2D4F6ULL, 
            0x3A41B18A8EEBBA5BULL, 0x9841A4D0B988088EULL, 0x47715D678B9A5998ULL, 0x27F19AD10FFB6D0CULL, 
            0x569694615B2B80E6ULL, 0x47C0D4CE2EFAC88BULL, 0x762EDA01B2A6DF6CULL, 0x8E4B54AB85B505D4ULL, 
            0xA7F967DDE4978B98ULL, 0x95F2BEC3E603FE95ULL, 0x34E0E14DD761940DULL, 0x9F9C92383F21F6CFULL
        },
        {
            0x1F85CC514A1C8DF8ULL, 0x001933986538FEC4ULL, 0xAF8A6110D48C0CCAULL, 0x1DA66636E3317290ULL, 
            0xF64A26860FD96BF6ULL, 0x07F858F79EF6DD70ULL, 0xE80A8A3E3914E52DULL, 0x527220B17569DE33ULL, 
            0xE9BE93BCAE5663E5ULL, 0xE87CDD6CA1C97E15ULL, 0x5EBF5292A6C1C38BULL, 0x898768DC39949BB3ULL, 
            0xFDF6FADEDAC6C160ULL, 0x2694F6EFC7DE4CFDULL, 0xA354B68BFD52767AULL, 0x296080F16614848EULL, 
            0xEC7A730F553D89C5ULL, 0xD226C02A7BDF8543ULL, 0xD614071874A4C63CULL, 0x0486C2D676F520F0ULL, 
            0x96769EC092518B94ULL, 0xD4CD650BEAC72D2BULL, 0x4A8C16B8F4467964ULL, 0x1C516982665220CEULL, 
            0x0FC20E146CB9EA40ULL, 0xD02B2A4E654FDD8CULL, 0x0567FDA8A407960AULL, 0x3CAC3C5B4A5BAE6CULL, 
            0x70A687AE51FD0992ULL, 0x017F09BC7FE31CCFULL, 0xBB914BF88E99B32DULL, 0x796A374B9A00FFB6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseFConstants = {
    0x028454A44B0C3F74ULL,
    0x3ABDB6D7289C165BULL,
    0x85AE97DB8664EE2BULL,
    0x028454A44B0C3F74ULL,
    0x3ABDB6D7289C165BULL,
    0x85AE97DB8664EE2BULL,
    0x31A8B140E8D94606ULL,
    0x2BCD1A443AA67712ULL,
    0x0D,
    0x51,
    0xAF,
    0x4C,
    0xA2,
    0xB6,
    0x32,
    0xBF
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseGSalts = {
    {
        {
            0x834079CBBD4C0F0CULL, 0xA6938089D09674F5ULL, 0x7C12D5C7A4DC898DULL, 0xBF2C843B43146830ULL, 
            0x86D68E8272CAD02AULL, 0xF3A5D34F03DEF05DULL, 0x2EF8115711F5DFAFULL, 0xFF8AEFF2DB65A57BULL, 
            0xC19B7EEF0CFFACCBULL, 0xC5B28CDF749DEFE2ULL, 0x4338554469690596ULL, 0x8054F50C718F0954ULL, 
            0x254CAC9DDC6FE6EAULL, 0xD4EF4F43821CC097ULL, 0xD6940FE39D4E276AULL, 0x3A5AD275EA6498E3ULL, 
            0xDB1FC346CCA91650ULL, 0x1F72A9CCE430A863ULL, 0xAFDD9B342A0B9A08ULL, 0xC0DA798C2CD8F449ULL, 
            0xC50260CE471F74D3ULL, 0xB76703DDD8A1F0E3ULL, 0xBEF8D9F8096A9268ULL, 0x6598F49722202FD8ULL, 
            0x98FFC51773048ED9ULL, 0x6A3E586E8E5448E0ULL, 0xDBFEB3B0CCB0D3FEULL, 0xD07E18602A659000ULL, 
            0x0C40B0F3B8379CAAULL, 0x9F180C0973222AB7ULL, 0x571044CAD95BD037ULL, 0x3720D709F0CCE6F8ULL
        },
        {
            0x6F92D99006478334ULL, 0x29F1A0112FEDDAE1ULL, 0xB0737375A1957EB0ULL, 0xFE0271A26AB0E79BULL, 
            0x4753DDED68D174F6ULL, 0x587E647D8F96B974ULL, 0x4A9AECB1316B4B5DULL, 0x27CD1A87B9A2B559ULL, 
            0x5E9ACD23B0F86D3BULL, 0xE95CB7C7E902AD83ULL, 0x6C010EAF9E1B54E0ULL, 0xD1950D932DFB3296ULL, 
            0x7BE42E2E4D83D0BFULL, 0x05E1CE9B387BE216ULL, 0x87814475B2CBA241ULL, 0x2943BC290158AB70ULL, 
            0x5CA0044D4E9D022DULL, 0x18518DAF5ADFE8E1ULL, 0x2A6363D03CAA765BULL, 0xCF01B88035CD8A98ULL, 
            0xF2E5E8EBDFCC3341ULL, 0x5CC4FF7F64485DD5ULL, 0xDC8D729BDE2AA431ULL, 0xFDB204C5440D9D82ULL, 
            0xA4A82862695AFB4EULL, 0x68CFE4CC2A223BBAULL, 0xDE6076A3477D32D0ULL, 0x7E7A24EE0D943331ULL, 
            0x48220D1553FFF1A8ULL, 0xBCF4D6264E74B543ULL, 0x91E121EB58E838C7ULL, 0xA594B9C79D55598CULL
        },
        {
            0xFA3A626FB8E5C0BCULL, 0x3300E0138E1C493CULL, 0xDACBD88AF0F4E4FFULL, 0x457296CC47A2358CULL, 
            0x7BA919D881FF4DBCULL, 0x957065B8C36545B5ULL, 0x59F687338CFB9DC7ULL, 0xD69AC80BB0001129ULL, 
            0xDC1E2505B4665AA2ULL, 0xADB9ADC042D68622ULL, 0xFD730EE1B9097C16ULL, 0x1884934AFDDBAD28ULL, 
            0x895865E3BC96A9CDULL, 0xED88BDAF096F3912ULL, 0x8F9CE681D6F86E57ULL, 0xA6FB3E43956EAECEULL, 
            0xEF31492C3B053958ULL, 0x93E3D736D286C0BFULL, 0xB91CA5AE9DB8388FULL, 0xF6FBA6288739B21FULL, 
            0x013F6E020B603CCCULL, 0x90E41AA9D3261849ULL, 0xEF0C069544D370DAULL, 0x61E53915FB99B401ULL, 
            0x60F5A841A9DB6726ULL, 0x9B23E12BE7E32CCAULL, 0xA4B7BEE31F2F17AFULL, 0x39C8858CB13B55F2ULL, 
            0x80558876E4425E16ULL, 0x80EEF428BAB15403ULL, 0x3A71EFAFE0F46BF9ULL, 0xC582D2695824F6DDULL
        },
        {
            0xB6E9AF14E9317F6EULL, 0x80BDC209E0BF50A0ULL, 0xF1C774416EA492DEULL, 0x154126BC8A88764CULL, 
            0xA2AE6F55DB997F87ULL, 0xBAA10BE1509CF29CULL, 0xCF932EB7B069B6E5ULL, 0x104F7F6EB4C0487FULL, 
            0x446062425FE41C14ULL, 0xDAC1037175816825ULL, 0x5F35B30EB1B91D1AULL, 0x3D8241C82B9E28ECULL, 
            0x66C345D4F42F69AFULL, 0xF6A5D21A26081D32ULL, 0xAB162541EAA50AAEULL, 0x03F1831A4C81F381ULL, 
            0xAC63C3DD8B9FC590ULL, 0x777419C3B69B4F46ULL, 0xB600FE7EF7A61A47ULL, 0x6BDA94F954BFB6E6ULL, 
            0x542BDA313428F2CEULL, 0xBCA7B2DD8610950AULL, 0x4FF43FD889AF704EULL, 0xE8D58AD58E72C431ULL, 
            0x1195DDF3AAC1BCD3ULL, 0xAFBA0D39DA1F8B24ULL, 0x50E2717384452CB6ULL, 0xC1196FC7C9B4E8A4ULL, 
            0x3217945D77F044BDULL, 0x0F8B5D65CA6F1B9AULL, 0x2A99ED7EB2F6EF9EULL, 0x54D2AA91F2B265CDULL
        },
        {
            0xDFDF317469621EBAULL, 0x66A98F24687375FBULL, 0xF8250B7DC8DCEFE0ULL, 0xFF3750AFC10FF3F6ULL, 
            0xD1BBDDEB04C644EEULL, 0xA4064B4F43799CA4ULL, 0x181B30BAEA332D42ULL, 0x808ADDDD9A95DB3BULL, 
            0x311CF16B027F917CULL, 0x5F77DBAA6E39F904ULL, 0x014364EFC21048B8ULL, 0x7B6B25D631AD8B38ULL, 
            0x13AFCC390B848E52ULL, 0xF5FB0025F9295377ULL, 0xD49356695FE74B3EULL, 0x145D0E399DAA9158ULL, 
            0xC1A25C004DDFA9BAULL, 0x80886B39A679CACAULL, 0x349FB523ADACF8B7ULL, 0xA082E462B2D806BFULL, 
            0x8B84CD15B4199388ULL, 0x4E600DBD08E55250ULL, 0x82E9F1B5A2B7DA60ULL, 0x6E6BAB72EEEBF387ULL, 
            0xD259BA493356C586ULL, 0x3865B9C0EA3CF9CDULL, 0xFAB9A4A7BD2738CEULL, 0x5422E9575761DA9FULL, 
            0xD78E79D489133FE1ULL, 0xC4017BB6CC03C509ULL, 0x0DDE6D003720842FULL, 0x90960A7A52BB0315ULL
        },
        {
            0xB30223B7AD48C034ULL, 0x256D0BEA3CD92FF0ULL, 0xB1B5712EB08BA925ULL, 0x71CDAF82EF2CB332ULL, 
            0xF6DA6F8053CD8D0CULL, 0xF453E9798F011659ULL, 0xB723C77DB5944D6DULL, 0xF2C3083154882FF9ULL, 
            0x46A8CA1F5CD6E45DULL, 0x40043F52EE906927ULL, 0xFE4982EF844A4D80ULL, 0x3D95D3EB95B0B5F8ULL, 
            0x97B9DD38DDAA891FULL, 0x2B75AB1E6A31EA4EULL, 0x38A42D06A55F04B6ULL, 0x1CCD25B21FD047FDULL, 
            0xADEB158B02343DC4ULL, 0x6CB3956173055277ULL, 0xD35B1CEFD462D7B7ULL, 0x59AE92FDFE30F8A4ULL, 
            0x1058CCBBC51749CFULL, 0x9294516848EFBA3BULL, 0x4023BAC6B5C8C652ULL, 0x8617FDBB2EE2CF2DULL, 
            0x0FAEE711830CE922ULL, 0x311F7FB1D1AC153AULL, 0x3622E54DFE72BEE7ULL, 0xAF7ABC516F0E48C5ULL, 
            0x44112872FAB39EB5ULL, 0x9C9E8F1992AAF475ULL, 0x7AC76D58049DA8B4ULL, 0x40AA4FBA5872206EULL
        }
    },
    {
        {
            0xF6CFE19833D0AF4DULL, 0xC76304645C2820C9ULL, 0x8CEC0E4A22B69835ULL, 0x885EBF57E88B16B5ULL, 
            0x1B597FE4BA812E00ULL, 0x370DD9F5B942BC43ULL, 0xB9A2232300BEEA4DULL, 0xB2B3E608B8E63623ULL, 
            0xE1F46801757E443FULL, 0xB9A7CD5C97FF0F74ULL, 0xA2E02966485D30B2ULL, 0x994CF8C8E79AF904ULL, 
            0x89F56D32663D5642ULL, 0xE5FC2B62D0D5A9C3ULL, 0x6542AC76E4A21088ULL, 0xEFC4238B621F7F90ULL, 
            0xD21C2C61412D15C0ULL, 0xD8F1CD1A93FBB32AULL, 0x3431FD77C24855A1ULL, 0x9D41F15F5B2C0B5AULL, 
            0x4F6EE6D68B47708AULL, 0x01A1B3914B8B51F6ULL, 0x464877D49CFFE25CULL, 0xE25F044A799757D4ULL, 
            0xAAA8341154600924ULL, 0xD96107C2E65AF742ULL, 0x8944541C0237F865ULL, 0x0CD1CACE49D109E5ULL, 
            0x26DBB4EB932E118DULL, 0x39BDC6D6CEDA288AULL, 0xF8D7B122F6C82DC5ULL, 0x690A5066D87D5FDEULL
        },
        {
            0xB320BE537202CC66ULL, 0x7D2DDBB3D5259FFAULL, 0x56FE12030D90EE0CULL, 0x156067F060642AABULL, 
            0x659EE404DD9076D9ULL, 0xB20E933AEE4D0836ULL, 0x10FDE846802ECABEULL, 0xC6C909A1899312D0ULL, 
            0x68193022F84501BEULL, 0x57F9759FD71B8570ULL, 0x93F9A29B4A6AD73CULL, 0x615DC9578902209EULL, 
            0xC40184957C83126AULL, 0xD18F0AB7FB8E767CULL, 0x9941213A7F354C3FULL, 0xE6DD788327812B97ULL, 
            0xFB323843E329D2CDULL, 0x5045648E69B8FC88ULL, 0x4F6DD6DA60E4E1BDULL, 0xB256E5522B7C05C5ULL, 
            0x425361A6E05568A5ULL, 0x3579D4F7CA9DEB58ULL, 0x68A4F75B1E363A2EULL, 0xCF347917AB8306F7ULL, 
            0x8B27DDE030C73AEEULL, 0x89CEF756397E9552ULL, 0xB248F4C49E1674AAULL, 0xBD399DCB04322FD4ULL, 
            0xCCF26FD602AD414CULL, 0x107CA5D8CC8B6B8FULL, 0x3E55A9978C3109FBULL, 0x3AEAA74A70F218DEULL
        },
        {
            0x2CB7A1A2C6478393ULL, 0x4373423C26BF9649ULL, 0xE51B6A2D57633B2CULL, 0xE88D079FDD594EA6ULL, 
            0x8737A62D5F054CE7ULL, 0x6F84141A27B6C7AAULL, 0x330D053FC8A59A66ULL, 0xA70713D6F25865ADULL, 
            0xB062F9D7885689F2ULL, 0xAA7AD7EF00105792ULL, 0xE74AD0837879E0D3ULL, 0x14B806DCD5677266ULL, 
            0x22470E1D8806616EULL, 0xC9D77E7119D752F5ULL, 0x77B1A6D620B5A7E1ULL, 0x225B49731A78B461ULL, 
            0xED935843FA528244ULL, 0x96152D4942ECD28DULL, 0x277B0F48088BA2ADULL, 0xAB733F9875270C22ULL, 
            0x8953236C85F08BCFULL, 0x55C11ED545CD2B67ULL, 0x75B7765B889D7DABULL, 0x8B15A88C4C5928C2ULL, 
            0x321C55C1CCFF910AULL, 0xAFD3ACB2C70D0DB7ULL, 0xD7B27200B9225397ULL, 0xF8BFB9E7B22C8108ULL, 
            0xDFC85F177F5F0388ULL, 0x3625A5E18047710FULL, 0x65A76F4F0EB4B758ULL, 0x4AECD26F4D8DAB3CULL
        },
        {
            0xF7F33BFC743DC5E0ULL, 0x612E90A494316F00ULL, 0xC47696B3EC5AA527ULL, 0xE7EBEE5BC0BF4AE7ULL, 
            0xCA87BF029D4C97BBULL, 0xABCE32F304A7F1D8ULL, 0x5BA12C2F9244AD35ULL, 0x4FD70DF6C212E91BULL, 
            0xD1B8EB4ED4BFD129ULL, 0x25206068E9A4AB26ULL, 0x441BA78D607DE6E9ULL, 0x20A3E41AF02C86CAULL, 
            0x1E62EB830E8942C5ULL, 0xACBE6E7009782B44ULL, 0x54E056AC6DCC9ED4ULL, 0x090B9283D8DCF909ULL, 
            0x8EEF2CF082D66633ULL, 0x8AC30E2278EE20DFULL, 0xDB56636B3E990A7FULL, 0x347A40E01DB831DFULL, 
            0xE9CAB20E6ACD6E5EULL, 0xD037D8BAE10A607DULL, 0xE1FEFFD99D716471ULL, 0x301239061B8D5852ULL, 
            0xEA7695575C7958E5ULL, 0x3C8A947A786EE200ULL, 0x8582655DF1243790ULL, 0xD466112C99509D23ULL, 
            0x84BC1C632B94241FULL, 0x2AA083D63C264456ULL, 0x81D71BA7F6C42DD5ULL, 0x592F5C7ECB88C312ULL
        },
        {
            0xE65D00BDAC4F1871ULL, 0xF9911FA8CDD75136ULL, 0x30AE03153DF118EBULL, 0x5279A84F03CD15B6ULL, 
            0xF44D664E44ED5EC5ULL, 0x4B5E280336FE858EULL, 0x860142395621284FULL, 0x442D2C88F6D9F313ULL, 
            0x68E66DF797A00317ULL, 0x2C51502E2B78F1ACULL, 0x4BDAD98AA63B92BEULL, 0xD0276133627D131FULL, 
            0x5B2E3016139338FEULL, 0x34D3E0022E3B4595ULL, 0xB0AC42F63B3810A6ULL, 0x596BE26F652D0B15ULL, 
            0x0614B397B401B548ULL, 0x73B7B04E3FC1F398ULL, 0x368D4A6C23ABF29DULL, 0x46585543698FD64DULL, 
            0xBF10EA473BCD041AULL, 0xD13B46A4808E6146ULL, 0x2AD70FB4300F91AEULL, 0xBD0B67A84E18E2E3ULL, 
            0xA17818BDFCFC493AULL, 0xD66ACA3B15A76314ULL, 0x9E1C7A2AE7C84925ULL, 0x20595846AB2300C0ULL, 
            0xFF9E506D89759E5EULL, 0x9B0788E4860AFBEBULL, 0xCA7248F687063779ULL, 0x17EC78015D4958B9ULL
        },
        {
            0x389245F522A8047AULL, 0x89E600D68B56F5AFULL, 0xEF9F649D0E87E8A2ULL, 0x217F255DE6368086ULL, 
            0xD307099FB0417D6EULL, 0x6381859104B87077ULL, 0x27610D8AF34A30C0ULL, 0x9D14F3B173AAF7EDULL, 
            0xF56C8AB6CFDE9F21ULL, 0x1D51B9F67E1893D3ULL, 0x1DFB3F6B664331A0ULL, 0x948E03BF72A45347ULL, 
            0xE62BB26946728800ULL, 0xEA02A4A2BD35FC28ULL, 0xC37BC2D7329AC8F6ULL, 0xD516EE1B6127A500ULL, 
            0xF80089D7C58D1D08ULL, 0x0DBCF60D2A1B76F7ULL, 0x612397552FC1CBA2ULL, 0xA91147F269623144ULL, 
            0xB40C06F4FDEEC694ULL, 0xAA25F918BCAAC312ULL, 0x37911E10EEB4B6D3ULL, 0x8587F6704733EAA7ULL, 
            0x496ED5BB0E787ED5ULL, 0x4EDE404FBEDAB971ULL, 0x0EC18DC46E54EFD7ULL, 0x21E269D19229CCC2ULL, 
            0x18D8A9A5154F1B98ULL, 0x41C4F2814292A60AULL, 0xD2FFDCAC9FBBD4AEULL, 0x46A3CA400B80D290ULL
        }
    },
    {
        {
            0xC1C8FE443A6D2662ULL, 0x618982B272292FD7ULL, 0xE048655865278C60ULL, 0x71539957D94438CAULL, 
            0xF8B0F6F78511AE6FULL, 0x362BCC2287351BA4ULL, 0x396EB07C2D833360ULL, 0x22F4C909A16D6C5EULL, 
            0x5244D6B3BACE89A7ULL, 0x26E9E6BD2E1159F5ULL, 0x7B158B096057166DULL, 0xA41555D6D90FEDB3ULL, 
            0xAC6089B4CEF9833AULL, 0x28F28016C212ED48ULL, 0x668B5C916C8C0592ULL, 0x31FE198F51B9E296ULL, 
            0x44C5910E7F04419AULL, 0x95D289A3F9389944ULL, 0x256E9857E62B3F3CULL, 0x00F84E21001B952FULL, 
            0x766B657F4BD59BCCULL, 0xD18F53473AE5E499ULL, 0x9A48D8429C52698BULL, 0xC96F11C3C3AE7BB4ULL, 
            0x69020DA9BA1C2A23ULL, 0x15749A375DBC245FULL, 0x8BB30261E1D4E2C9ULL, 0x167E0C034F5B8CAEULL, 
            0x6889DF069DF6C406ULL, 0xD068E4AB6054ED83ULL, 0xF13A672C4D397156ULL, 0xD5D74F8F58AAC2C3ULL
        },
        {
            0x9ECB5607D422581AULL, 0x741EAE5563C54EFCULL, 0x139DCD929D913459ULL, 0x2966498631A8EC09ULL, 
            0x9CC071709B29C519ULL, 0x96968DB357BB641AULL, 0x629A5B148D03AF56ULL, 0xEC2950ADDFF8D8B2ULL, 
            0x4D0080FC6E037C3DULL, 0x3A26FDD039504C56ULL, 0xC457D5F51D66E427ULL, 0x3C4308C47EAEC052ULL, 
            0x2C92129215D18AD9ULL, 0xD6E28B1B88643AF1ULL, 0x672847A104725D52ULL, 0x7629489A0035A82CULL, 
            0xEA86FA746A2D3116ULL, 0xF0FCFE7F5D134A84ULL, 0xDAD971F65D6B172BULL, 0x7279C90AC4C608EDULL, 
            0x9AEF0B81C42D3B65ULL, 0x76BA1AF4B9919EA4ULL, 0x5E4B7FC1934DDB6CULL, 0x50A2C98BA7383764ULL, 
            0x44B8805BC10E433AULL, 0xDC08FEA09C884738ULL, 0x3B2A05D0C1C2D9A5ULL, 0x85D7C0F63BA51E16ULL, 
            0xAF58F6A86E233CA4ULL, 0x0E6BFDC20C7F9C9AULL, 0x781434D2FBC2DEECULL, 0x55CE10B73CFE2B6EULL
        },
        {
            0xBE1BC74FF176920FULL, 0x8C371B8C29440FBBULL, 0xFC156C34A04A1E01ULL, 0x20C1E23FDFB5B166ULL, 
            0xB9DD53240DF1F6F0ULL, 0x33728817F81AE385ULL, 0xD0FEABE798A9B2BFULL, 0xAA88E39421F304A6ULL, 
            0xF08988B3662870F0ULL, 0x708B0F21D25FD7EDULL, 0x86BFDD1146D09977ULL, 0x0392230C8F232E6FULL, 
            0x6C5DAF2A632CF598ULL, 0xAD84E2C31AA68961ULL, 0x9829922B1E027E63ULL, 0x0881AAB4FA7A1E34ULL, 
            0xCC307F6511D8B1A3ULL, 0xD564D09E6A63073AULL, 0x3BAFD9D2048E6968ULL, 0xFFEE57EDA25A7638ULL, 
            0x70CCC45730ADAC21ULL, 0xCB6DA2348AD03418ULL, 0xAD166B6B7D77CE9FULL, 0x12283F509D9C2727ULL, 
            0x3C292B56085385E7ULL, 0x9A9A3173B618B300ULL, 0x47F43DA7C4C936CAULL, 0xD3C8DD566778D3BEULL, 
            0x0DEDA1DC1F06FB39ULL, 0x223D5EC0F365F2ACULL, 0x71E35A388058AEEBULL, 0xB18CD2B48FE58183ULL
        },
        {
            0xCCB4D9CABF8CD3ECULL, 0x16A6AE9FAD34FCA8ULL, 0x03C0E182DF7BDDACULL, 0x3230BC4B4EE8E80EULL, 
            0x2F1FB40A9AC9A626ULL, 0x9F1A82D0434A59C7ULL, 0x047BCBCEA9A036BBULL, 0x6570BE8AAE07C5CAULL, 
            0x1800148535858F61ULL, 0x81E71C57C8D08189ULL, 0x22DA85D33DD7B2EBULL, 0xBE57F3FC0985DF25ULL, 
            0xE782679DF6581A21ULL, 0xB6A818CF8E395DE6ULL, 0x783FE31594EB6FF7ULL, 0x57C9EB039FF96B06ULL, 
            0xBBBC7787555B921CULL, 0x30E08A6E925BE202ULL, 0x684A790539F49EE9ULL, 0x5C6EDB32357D3AE1ULL, 
            0x729A4916322F91F9ULL, 0x51880CA0F4ED16D4ULL, 0x77A6C11F133AB9D6ULL, 0xC6D49A8F92DAC989ULL, 
            0x00D408D4C0C172A9ULL, 0xB07B7591D4EDE54AULL, 0x08AE86B6CBCB36C2ULL, 0x76925F9621EDD685ULL, 
            0x80E63F3317249570ULL, 0xA826F6CCA70FCED9ULL, 0xD9F8B319A9045658ULL, 0xED86D33E75AD9584ULL
        },
        {
            0xC3D11DEB8312CEC4ULL, 0x74DBC1C039990976ULL, 0x50060ACCF86A24E4ULL, 0x642FBC987FAD5EDAULL, 
            0x74CF1BB9EF208DBBULL, 0x0B235A199EED978EULL, 0x31520FCE103545AAULL, 0xBFF0271CC62CA487ULL, 
            0x950E5F3B9A33EF41ULL, 0x7542B716F9732BA5ULL, 0x6033450292FB150BULL, 0xBE7BA6AE0ED75B54ULL, 
            0x5695B4C9B9B1E42DULL, 0xD787AE90FC5E17E2ULL, 0x87929B682167EDB3ULL, 0x75E75ECD8D73982DULL, 
            0xC571DFF36FFC62F4ULL, 0x14B3548F862A54EDULL, 0x7E4F71BDC79CBF24ULL, 0xE47CFC6B62918784ULL, 
            0x487BAB93C0899095ULL, 0x20EA47281C6980CAULL, 0xFB835085C33C202FULL, 0xC85A757C20EE2BA1ULL, 
            0x449BB18CDD7F655DULL, 0x3E55563DA2A39E7DULL, 0x92E5BDA967658570ULL, 0x99909C7247860821ULL, 
            0xDD651024B3775CF5ULL, 0xED7EF48A3946D463ULL, 0x7BBA1516FE65629EULL, 0xD61D29EEF38E2BC0ULL
        },
        {
            0xAA60507AA3AA3BDBULL, 0x14195C84F330A04FULL, 0xDDC19A0F06451EBDULL, 0x3601AAF7301BFADBULL, 
            0xA72BD963BB4DCB77ULL, 0x2BED824FE4326A03ULL, 0xAD7C2DE7E69353FFULL, 0x05B8BB61AF84A934ULL, 
            0x11791682A046F5C6ULL, 0xC7983B192BE29B1CULL, 0xFB4989C5784944C4ULL, 0x14BE70A9DB45C966ULL, 
            0x0E28091F2799DA31ULL, 0x50D7D85DDB70C6F5ULL, 0xD01BF4A39C8C222CULL, 0xD4058D881805DD1BULL, 
            0x79C8B24C525F021CULL, 0x89CD409A4CCA9E47ULL, 0x712E0541BDC3B53AULL, 0x5EF2C7AA0D7786F8ULL, 
            0xCA9299C29CC6EB53ULL, 0x1A7ED207FCBF0EE5ULL, 0xFDFA9F9B75159AA8ULL, 0xEB64CA3A51E02C15ULL, 
            0xC5B4ACF8251536A0ULL, 0xD2054CB6FE47E3A7ULL, 0x4E01EA7AF5BF08A5ULL, 0x759AA7833B35F87DULL, 
            0x18DF6861511F5280ULL, 0xE54B373C4AF7DE52ULL, 0x09EDB6CE8B815834ULL, 0xF7D7F083DF6331D0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseGConstants = {
    0x1B4286442369F288ULL,
    0xBA2140ADE26F4399ULL,
    0xD819E2179FF4C753ULL,
    0x1B4286442369F288ULL,
    0xBA2140ADE26F4399ULL,
    0xD819E2179FF4C753ULL,
    0xE4C910A0DE806B39ULL,
    0xF2EC0285CC9F292AULL,
    0x9C,
    0x30,
    0x65,
    0x51,
    0x9B,
    0xA0,
    0x2B,
    0x70
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseHSalts = {
    {
        {
            0xE1B306C7DFD37E2DULL, 0x1C20871C1B0ADA2CULL, 0xDA11166CA1BA153DULL, 0x2A6713BEBD994B89ULL, 
            0x89AEF80BE0EFFFC3ULL, 0x756C04E33CBB9DDBULL, 0x5E9150870741F803ULL, 0x69832C8ABBE305A5ULL, 
            0xDE092B909B287457ULL, 0xF0A0188941722DA5ULL, 0xB21E6E7C8FA38033ULL, 0xA6A641DB57E09054ULL, 
            0xFCA5BAB18119A899ULL, 0xD67D58DA0BAFC295ULL, 0xE35AD9B33C6A353CULL, 0x7DF4B43193B77F1FULL, 
            0xD47BE915D2209F45ULL, 0x922BCFED110209F7ULL, 0xE93815EECD7BD65DULL, 0xCE7C9EF594F3FCAEULL, 
            0x972484473A8EDC18ULL, 0x13F7EDC51BF10F30ULL, 0xA6FA6F021C3EBA36ULL, 0x17124F86C82896E1ULL, 
            0x3E12B6C9F8F33F31ULL, 0x01418B5CE97AC37CULL, 0xE8ABEC6F9A85457AULL, 0x60351BB5B998A1D2ULL, 
            0x100B21B657C2CDF8ULL, 0x90B0AD127F4CE797ULL, 0x509DA84447AAE411ULL, 0xAC791FC1467AAFABULL
        },
        {
            0x38388DC45D8EBADEULL, 0x6E652CD2361FB6B9ULL, 0x17B9FB8385ABA2EEULL, 0xC5352D8515717DFEULL, 
            0x4CC103067E3B927AULL, 0x91A643D84CEC1B4BULL, 0x8D1495F5EF4FF25DULL, 0x322EBC11E823AAEBULL, 
            0x0E8F85EBD3C9D730ULL, 0xE9003B31505B2575ULL, 0x4DF0C702F8EB270BULL, 0xA84570C450EE98F2ULL, 
            0x2AFDF7CDCC81BEF2ULL, 0xDD9060BF9AED4E65ULL, 0xC07964BBC59F31E2ULL, 0x5705FDA85A73ECC7ULL, 
            0x3BEC2176C097D642ULL, 0x69B5AD7678F43E08ULL, 0xC85EFF9E3A0C8188ULL, 0x3EDC53F78EB06575ULL, 
            0x9D08E6D4E79D4719ULL, 0xB3E53B77DA27F63BULL, 0x79E2D148F23AE5E6ULL, 0x9F1FA8E46E9EDCA3ULL, 
            0x4D65CEBAD476464CULL, 0x07AEA2308D493CECULL, 0x8A825895F052A464ULL, 0xE57B1AC258E1A6C5ULL, 
            0x930CD22BF2DEFE2FULL, 0x3CF3EF339066CA96ULL, 0x1E88A977BEED0024ULL, 0xD9437EF7C55A14A3ULL
        },
        {
            0x26A8F99D5FDE1C24ULL, 0x412FDDC785FE4BD2ULL, 0xD199BAFA797B52ADULL, 0x5E55E4E5AE62A47CULL, 
            0xC95E3DD8442D4158ULL, 0x6FAE51E734EE4B72ULL, 0x14E8CD9552F2ED89ULL, 0xF96FEC9B6F27929AULL, 
            0xAC9C196A69EE75FEULL, 0xF13D9EA7E0C2A1ACULL, 0xC1CBD3C466A6E8EDULL, 0xEC7F1C9623BB1961ULL, 
            0x6A32D7929976173DULL, 0x71D7B44778D90E15ULL, 0xC10B797794C683E2ULL, 0x28D7FE3E86AF946EULL, 
            0xF659843DF5196C91ULL, 0xF1D324CF22181EBBULL, 0xF3FF12B6C35F8F87ULL, 0x18A782E7D472C616ULL, 
            0x10401EA3A9440AA3ULL, 0x834CAE3C1817BDBAULL, 0x2CA437C8ED186B81ULL, 0x1B50811206E3B706ULL, 
            0x87EEAA43F7DF83C1ULL, 0xE616D90BA7ED16B6ULL, 0x982ED53989F693EEULL, 0xDB4A725AEEE423DFULL, 
            0x07FA8C81EC8FA315ULL, 0x430D3BB1A7D23ABEULL, 0x0E0D391C06DBD582ULL, 0xDADE49FAC06453FAULL
        },
        {
            0x01D821A7885CB6FFULL, 0xA847F8EF88DEC24AULL, 0x502E4E5FC6A0D982ULL, 0x94214DE00EB13D45ULL, 
            0x7D70DD94065D87F3ULL, 0x96687B3A43200073ULL, 0x468673CA86B5AAE5ULL, 0xCB84B4D31331AD69ULL, 
            0x7F7D19B35ABBB520ULL, 0xCE169773285C730CULL, 0x41941D7E865D0E83ULL, 0x3B528383F0143A6DULL, 
            0x000F1743BF3ED912ULL, 0xFA7D9A4ED0F13FD9ULL, 0x5F2485076D2D91B9ULL, 0x6EBA155FC4217778ULL, 
            0x38B9E24E9DA8B591ULL, 0xCE5FE3EEDF2FCFB4ULL, 0x3318BF1079B55ECFULL, 0x1ABD9D4EFB2C9C3CULL, 
            0x26BB4679E1F9C375ULL, 0x9288EE3FF3FFB4DAULL, 0x6034E816342F299DULL, 0x4BD00B38B2303CD4ULL, 
            0x57D200A3C54438CCULL, 0x1E0CF641107C6B71ULL, 0xE562E4A64D60D024ULL, 0xB075897E3D6729BEULL, 
            0x24D67118A6C11CBEULL, 0x48B95CDF16F874D3ULL, 0x7E526A11BABC1C8AULL, 0xF727D23EB4DD9B68ULL
        },
        {
            0xE4A7BD911EE4DB05ULL, 0xA60A724157D7C023ULL, 0x882BE787F499C56AULL, 0x9C05647489DC02B0ULL, 
            0x56D3D9A74AA4E969ULL, 0xF72EA87FC6BCD52FULL, 0x8131F59D1275CDECULL, 0x6ED98699ED0A0A13ULL, 
            0x8907E200E9D8F207ULL, 0x77B86FAAE7EA9BE1ULL, 0xB548874E2D7B1544ULL, 0xDE13C2BE2582F481ULL, 
            0x5478D721639E4190ULL, 0x88E745D1A0F923D6ULL, 0xAC8C9020AC95A786ULL, 0x1EF347C66806218CULL, 
            0x69095EE0ADEE6EEFULL, 0x092900D94DADF8ADULL, 0xE5861A5F8D384405ULL, 0x62A8528869D6B9D4ULL, 
            0x138E9A9DE9D34507ULL, 0x06C44C4528F7F331ULL, 0x570C318611F8CE76ULL, 0x5F5E0A860D95C4D1ULL, 
            0xBDB83A75828BC049ULL, 0xF6410DFE28E7E823ULL, 0x7B91EA9FD2CF4D95ULL, 0x169772DD6A83375DULL, 
            0xD4565B0B0230D0D2ULL, 0x55292645DBC499ECULL, 0xE42760CD862EEACDULL, 0x6A981A9061C3BE5DULL
        },
        {
            0xF49FDD22B1F2FAACULL, 0xC51E4FE5F635AB88ULL, 0x809C459F769BC3B1ULL, 0x65278AE8E7093CE3ULL, 
            0xD88D644D1FEF2E60ULL, 0xC4022F0D235E5346ULL, 0xCDAD1986A1CE1F89ULL, 0xA12DD36126F12819ULL, 
            0x1A9EE7D1FCE58927ULL, 0x42BF29B016B11059ULL, 0xBA60C79994CCD8C8ULL, 0x2B99313A9441A53BULL, 
            0x96632E92F838C7C0ULL, 0x43C05FBAE8A09108ULL, 0xB26D92A6010D70D1ULL, 0x22B2E038E2446EA1ULL, 
            0x661EEDBA87B78902ULL, 0x10E6F1B373B78A8CULL, 0xB84F1CB2F151A3A7ULL, 0xC3F45175D8DD56C2ULL, 
            0x5A09ED6BD950F8E7ULL, 0x62A7283E86D21307ULL, 0x6F20FB209F289830ULL, 0xC2ED74E7E3A4BAF1ULL, 
            0x40F921A64F7F0F6FULL, 0x80E2FD487100C25EULL, 0x24276F1852B7AF2DULL, 0xBDD21F4DAA37B840ULL, 
            0xB63ACABD6775112FULL, 0x5DC1E8C7EBDABB1FULL, 0x3718267AADF5170DULL, 0xB9D6082F36CE1127ULL
        }
    },
    {
        {
            0x89E11A5D055C8B2DULL, 0x669F48EDD0A59D86ULL, 0x846A54428B300C67ULL, 0x0194A68A8693261BULL, 
            0xFC7F939DFC077BE8ULL, 0x6C03B860024E5FC0ULL, 0xE2508D82815DEE6CULL, 0x3674017E5B776D8DULL, 
            0x2C357C5447036F33ULL, 0x88B55792346401F5ULL, 0x04391CF07BE56DE2ULL, 0xF17E7D6329186D5FULL, 
            0x846F345E18012C35ULL, 0xADF5E04BE606C567ULL, 0xB8311F4473172533ULL, 0xC65D4B59ED089793ULL, 
            0x24C5D247A4F5E4C4ULL, 0x18D560E6133BBF7FULL, 0x97CAEFF30D8A54C4ULL, 0x525EEC9A8E3BC52CULL, 
            0xB125771B41B3F9BAULL, 0x7ADEAFAA294ABE65ULL, 0xB2FB1B25BA07BA09ULL, 0x0FCBEC06FF7ABF82ULL, 
            0x15205C5CD81AB2F4ULL, 0x2B674CF52536168CULL, 0xD29552AEE725AAA4ULL, 0xD431E544AB9EFFADULL, 
            0x0A5B769E119022C1ULL, 0xCBC7BCD6AC014DE7ULL, 0x4F6B5719CFF28F5BULL, 0x9D7F4C83BF505F72ULL
        },
        {
            0xB7D211B5504457CFULL, 0x0C21E2C953F80D5DULL, 0xCF567590F8328D63ULL, 0x8FD2A760F2AA5FA8ULL, 
            0xD6DBF809EB799DB6ULL, 0x1D4CA4E1D5E2A828ULL, 0x602F50622F0383B1ULL, 0x0201557A949817DEULL, 
            0x7CFBF4E3019E35ECULL, 0x1E31EB1E15C85915ULL, 0xC920CA94BCC9FB55ULL, 0xD310B3D74D087622ULL, 
            0xCF77B322EDDD02EFULL, 0x48468EAAD8ABE6DFULL, 0x4908E7B4521C4B5AULL, 0x52B33C0B23C1807BULL, 
            0x6C243B581407D8A8ULL, 0x8608488DD67E34C7ULL, 0x8DFD71008840E04FULL, 0xE7D6F43D7F9007FCULL, 
            0x08E7F934A88F872FULL, 0x0B17226639F70431ULL, 0xFB69DEFC8518F53AULL, 0x78DD1844B27292FFULL, 
            0x25EF03317238261EULL, 0xB1EEE6499F28DE2AULL, 0x70F5726510E4A61EULL, 0xFD46A224277D9D0BULL, 
            0x0FD5557BB0F9FF91ULL, 0x55A1A5A0BD583F00ULL, 0x09EC921BBDE26864ULL, 0x991EC1D6CEA20C36ULL
        },
        {
            0x1C27D31F85876D13ULL, 0x7FB7127362DADA78ULL, 0xBE23EE1EF35A7B6DULL, 0x8F8282C2F920AD70ULL, 
            0x7B5BB426F27236E5ULL, 0xE86EDB8DE7CED900ULL, 0x345A0495364332E5ULL, 0x070F6E8BF00C87C5ULL, 
            0x43F501C2DB31D7A4ULL, 0xA5A0C16EFBBD5E4AULL, 0xD548EC22502D08FAULL, 0x379CFCC7750EA256ULL, 
            0x2D959DED5A0DA0C9ULL, 0x2EE383C42667F7BBULL, 0x217150E35444DEF0ULL, 0x96ACA6D0C831F78AULL, 
            0x4D2810E70F910719ULL, 0x01BDE3221CD500E1ULL, 0xA6DE860A3F00FA11ULL, 0x48052DCED495B52FULL, 
            0x18DECD8B76768206ULL, 0x330907C4AA62B2E5ULL, 0xA7FCA37B24227D91ULL, 0xFE5B4761D9F9BF94ULL, 
            0x3E72AE4BC34ED019ULL, 0x45EDFFEE3009A69FULL, 0xC61A9B3996B17F99ULL, 0xA9F2A46475954089ULL, 
            0x5A7B086E8C71E541ULL, 0xFB3624151194C372ULL, 0x29021803C54C7EADULL, 0x65FC75656D51F5C3ULL
        },
        {
            0xC09DF556147EA0ADULL, 0xA220EB0BC0E29990ULL, 0xF5167FC3DB8DB237ULL, 0x029B58E312FC1290ULL, 
            0xD3B193096E228B89ULL, 0x12EECD992AD10C39ULL, 0x02913075B294763DULL, 0x6D3A9D4F548CC128ULL, 
            0x909137F7343E372DULL, 0x7869C1310030D429ULL, 0x16B96808636E2D5EULL, 0xDB1DC878949C6E19ULL, 
            0xF8C21EC7439ABCACULL, 0x2F9ACC3146F37D6EULL, 0xD70C17968E7A44D7ULL, 0x88C4B11DF3DAC646ULL, 
            0x95C99A9249D23AADULL, 0x280E9F0EBD154156ULL, 0x889A4346F8570845ULL, 0x8A2452228EBF6B8AULL, 
            0xDB60EB765FA7DF9CULL, 0x36D77CAC0257005CULL, 0xB256FAA1E48A5FE0ULL, 0x5D5D22639E1FF6CAULL, 
            0x9DC43862172A97D4ULL, 0x9A29699BFC8BFB5CULL, 0x6C0BCEAC82B4AC50ULL, 0xF53CE6577D5FBEECULL, 
            0x79808E5EC88F975EULL, 0x4FB0763029E66426ULL, 0xB3F4E3825BD0FF46ULL, 0x1078CB493F639948ULL
        },
        {
            0x11DD57352EF21513ULL, 0x095B3BA4A38EF835ULL, 0x3334CF3A2157BE4DULL, 0xEF68C00D2C03A3A9ULL, 
            0xB0AEA5A2210F5AFBULL, 0x3B2B915AFDE6454EULL, 0x028ABC198C815CC4ULL, 0x22306284322BE06BULL, 
            0xB26A50393AE0D9A1ULL, 0x058FB68955B4C0BBULL, 0xF5A7AF93D8305060ULL, 0x1126A2FA7EE15D78ULL, 
            0xFFD6400478E3E536ULL, 0x8C86CFD501833098ULL, 0x4ACC91801AA629A4ULL, 0xD7F9A08D827AF1DEULL, 
            0xE2A7384461162FEEULL, 0x503D009AA76262B2ULL, 0x6A9CC1FB51839BD1ULL, 0xB50FA292B326F652ULL, 
            0xCEA4D88A3E089213ULL, 0xD809B5720BFC3416ULL, 0xF9E5B8ACE8404786ULL, 0x96579EC2B7B4CDC4ULL, 
            0x1E763B8FA414981DULL, 0xBB824E50632824D0ULL, 0xD8342C2726123F93ULL, 0xEF88C7760BEE6C33ULL, 
            0x5257E72636D9D719ULL, 0x14A4D823B2997AA3ULL, 0xD09522BDE9D11643ULL, 0x634B58E8BE676BD1ULL
        },
        {
            0x40B6EB011773EC6FULL, 0x2DCBEEAA09DA2905ULL, 0x7D5D57CFF121432DULL, 0xD4619B1B3EA3B6F3ULL, 
            0x330F5C526434FE69ULL, 0x6A273D89B0199C0EULL, 0xBA41DE808C873CFAULL, 0xE2A10D455C8201C6ULL, 
            0x6DAD99F737B1C5BEULL, 0x008B36F3EAE7DBF0ULL, 0xB089D3C7537916BAULL, 0x3B24EAAD57B7951AULL, 
            0x46A4254606E52E39ULL, 0x641717DFBB6F1FABULL, 0x5CFAA64A40D4D526ULL, 0x6E56DBCD9B7FE60EULL, 
            0x046B7A305DB1FE1CULL, 0x992719EAA7933132ULL, 0xDEB970636F245CCDULL, 0x09DD55C89E69BDB3ULL, 
            0x22C7DD72B3AB4754ULL, 0xE464DB9A9F2CC833ULL, 0x2DB0FAF3785CBA76ULL, 0xA21938959D22A160ULL, 
            0x86C408CF59A598D0ULL, 0x4CBC317DD2B9B5B9ULL, 0xB57A3ABCD6011AE2ULL, 0x3F72F7C6340DF6E1ULL, 
            0x9D75BF7298A16C43ULL, 0x976F3C1DA7F5D1A8ULL, 0xA76743647EEF0A78ULL, 0xCEF6D7C4A1659518ULL
        }
    },
    {
        {
            0x246FB8860DE01C48ULL, 0x635C6836D53E75C8ULL, 0x9084014948CF0211ULL, 0x6D15FFE6F79734FBULL, 
            0x66CE5852D17AD900ULL, 0xDF3D8EDAAEF87725ULL, 0x3330170BE75FE731ULL, 0x3428D2555A85682BULL, 
            0xB7785685D32F14DBULL, 0xF715138CA995B8BFULL, 0x46CB65CF803A3F53ULL, 0xDFB47B616ABDAFC4ULL, 
            0x3C031AC11F63C93EULL, 0x0B976798F9F2B44FULL, 0x6BFBA75BB7F65FA5ULL, 0xF734441C3AFBC4DCULL, 
            0x7040AE358F643E7EULL, 0x6CE2EB87CF6D5930ULL, 0xB234B6DDBDA6BB97ULL, 0xC42B0B9185382070ULL, 
            0xB9244B8B9FD0676EULL, 0x29764DCE1DE839E0ULL, 0x6CD88B9353932254ULL, 0x910A20BD9353F930ULL, 
            0x489A30618F571501ULL, 0x15CC38A96588E3DAULL, 0x11E6F5D441BA7AA1ULL, 0xE01133DBE08644F7ULL, 
            0x0C4AEA28A111A331ULL, 0x492E57B2895A72D5ULL, 0x3EAD2ECC8CF03651ULL, 0x5098993BFAF179FEULL
        },
        {
            0x293F197A49DDADCCULL, 0x04BC8C8EBAA042A3ULL, 0x0BA0358C92E9E5C4ULL, 0x8FB2FC687E567D4FULL, 
            0x816378E23D0D7BEAULL, 0x49E4A74218133847ULL, 0x1959C873F021FD9FULL, 0xE37DC8CDF1A5E8FBULL, 
            0xA2E648DFED4F0340ULL, 0x762B5E2746AAAD92ULL, 0xB7F6531DC7F956F2ULL, 0x1FD7940A63A0E12DULL, 
            0xDC365452C52B076CULL, 0xF84A0F06FBB7D979ULL, 0x139C84B0C09FCB5FULL, 0xEB3C79E52EFEB9D5ULL, 
            0x9895F779E1DA0DAFULL, 0xAEBF41FB2FACBB20ULL, 0x144EF99729E61426ULL, 0x0C4E45CDBC4D3B62ULL, 
            0x0B2A58D93DACF770ULL, 0x0FCF183E9716E680ULL, 0x3EF4BD7C0578565BULL, 0xD0B06699EB96F9C4ULL, 
            0x42E0A579525AABDBULL, 0xC95BD741D863DA84ULL, 0x90F8EDA7B075C524ULL, 0x9804A01BFBA83469ULL, 
            0x63D25E31C712367AULL, 0x4E4255AB921554B3ULL, 0xD83BB7812B3DFD92ULL, 0x0F75BF4EBC3F088FULL
        },
        {
            0x62FE9853FB325AEFULL, 0xF3B2732A6296943FULL, 0x60FD47832F45C2D8ULL, 0x161DFB2D53233EBBULL, 
            0xE9D09497DED1766FULL, 0x0D876813994717FEULL, 0x7F6B2949126E1239ULL, 0x7E03620EBEA1C531ULL, 
            0x30515EC32019BCBDULL, 0x085BC1203A3B600CULL, 0x54BE604783D4B69DULL, 0xDBF3A4EB370B0C6DULL, 
            0x9596BA14813AC3A0ULL, 0x328713AFA493A21AULL, 0xAC88D7AF8F10469DULL, 0x9FECF3CC6C3FA119ULL, 
            0x82DCD54E390DC71CULL, 0xACC92AF18777A306ULL, 0xD3C51611CA3A7EA5ULL, 0x2146411598853A33ULL, 
            0x1A22F09ED4CC13EAULL, 0x24EDBE785806AF8AULL, 0x364537EE44F71E1EULL, 0x2AF980EFD0875669ULL, 
            0x6F0630306F237492ULL, 0x73BDC6B4637993D0ULL, 0x0C2F55964A4A2067ULL, 0xA7F190F45E7BEACCULL, 
            0xBAC3293C298F2D11ULL, 0xDC45C066492C7829ULL, 0xE2FA54A4BD4A4F8DULL, 0xF9DD7689CC3ECDE5ULL
        },
        {
            0xBE541F893D05B9B0ULL, 0x6FD51F6A50B64A01ULL, 0x29793948CD57A2C0ULL, 0xA2F0DE2D9065B6F2ULL, 
            0x63FFCC43A83D9E86ULL, 0xDE8F13778E2A8001ULL, 0x765A5131E2B9649FULL, 0xAE595EB29C62331DULL, 
            0xBD1C1B97C08E5B95ULL, 0x67810F59A49F4660ULL, 0x4E0C06B2E6657067ULL, 0x0EF07AD8C1DB6353ULL, 
            0xB7CD175BD230EE51ULL, 0x3346D75A5600716FULL, 0x0BDC545A0C5C0E89ULL, 0x522522A179C16434ULL, 
            0xCB41410FE1BBF4B1ULL, 0x773C585451AE37FFULL, 0xA87E05E71C4EEB39ULL, 0x1920938130D1BEFBULL, 
            0x0A5B593DB0313EBDULL, 0x14317ABF9E253E59ULL, 0x9970E1F116ADE7A8ULL, 0x1313C9941BF34EF9ULL, 
            0x774B71E0255CE72FULL, 0xD1BC2328C91EABBFULL, 0xFD16B38FA5E0B306ULL, 0x70651346D2E8D507ULL, 
            0xFAB8034980A7E63CULL, 0x98A4C5E17DA14511ULL, 0x230C2DE806388A11ULL, 0x9FD1A5B0D8994BF0ULL
        },
        {
            0xD67975381F1BD916ULL, 0x39865BAD8B1A4CDEULL, 0xD862422A46E82BCEULL, 0xE968B680986ADF92ULL, 
            0x7B0B8D3427D36BA2ULL, 0xECA10F817CA676B1ULL, 0xE75F928DE2C958E2ULL, 0x5BB74A499BAF9F49ULL, 
            0xD967B69FEE5FB481ULL, 0x5A4C34BE45407E19ULL, 0x5C792E4558DA8491ULL, 0x3941B74A9EA74FC7ULL, 
            0xED2E70EA08435645ULL, 0xF4E21F8F35241DCBULL, 0xB7347B9E06BBA737ULL, 0x8E12E48101AB78B9ULL, 
            0x830830506CEE338BULL, 0xC418C640C7BD90C4ULL, 0x6DDD3F4B5047206FULL, 0x355DBD3D8B5F3CBAULL, 
            0x657D7B17C02F8D6EULL, 0xA4569063D49423CFULL, 0xEB2925FB254FAD5AULL, 0x101B0EF0E7B09C64ULL, 
            0x0269F0A8FA8464D3ULL, 0x5DCF60DBF3612733ULL, 0xE085E9DECBC31B08ULL, 0x1E6EB3C688080216ULL, 
            0x0FA7E8367DE50668ULL, 0x6CF71F76AAD7F86FULL, 0xE89ED36379F0DB9FULL, 0x30EFD272E0DD2A59ULL
        },
        {
            0x4293820D282C79EBULL, 0x45D7AAEFAEF968DBULL, 0x93FDA0DBA9CB9002ULL, 0xB2696350C66A0B73ULL, 
            0x6D175D0DE153CC2BULL, 0x982AAC4BF42B70C8ULL, 0x0881D314912AC38DULL, 0xB5F6591E6C125D4DULL, 
            0x839DB7F3E8F1BAF0ULL, 0x41BB274762548942ULL, 0x80C41440A852F95CULL, 0xFD0D34D0F9577450ULL, 
            0xB4B5D203C5698084ULL, 0xBB015EAA129BC08FULL, 0x6DD8E506B5F7C279ULL, 0x399ED1913DEF167BULL, 
            0x661EE33A45EA937CULL, 0x62170F2FF3A6CFA0ULL, 0x001C512BB7CA88D2ULL, 0xF002CE45D553DB4CULL, 
            0xDA0B97D792A4A802ULL, 0x5F9D85174A857623ULL, 0xEDE8D3D0AEC504BDULL, 0xB8116A776133EA1EULL, 
            0xFE6C9D2F6B9DA94CULL, 0x86047365337214FEULL, 0xA589DF8ACEA15C38ULL, 0xFB1E2D5B490FE665ULL, 
            0x0C9CDA48F91F31B3ULL, 0x97237BB457D6D53BULL, 0xF8669146A4B35B09ULL, 0x45B3FCCA4A898BBBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseHConstants = {
    0xBE0B2658FF19ED52ULL,
    0x6A31D61B205060B2ULL,
    0x8309359E17B87DFCULL,
    0xBE0B2658FF19ED52ULL,
    0x6A31D61B205060B2ULL,
    0x8309359E17B87DFCULL,
    0x1B10876FAA3A5984ULL,
    0x8819DDC8AEDBB39FULL,
    0x7A,
    0xFA,
    0x76,
    0x18,
    0xDA,
    0xF5,
    0xD5,
    0xDB
};

