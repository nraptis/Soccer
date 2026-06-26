#include "TwistExpander_Rugby.hpp"
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

TwistExpander_Rugby::TwistExpander_Rugby()
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

void TwistExpander_Rugby::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 18383963531502431277U;
        aCarry = 12164798122636231935U;
        aWandererA = 14084293611426433127U;
        aWandererB = 16822666884749351758U;
        aWandererC = 13161465585212262606U;
        aWandererD = 15610439946426181360U;
        aWandererE = 10747749770463421226U;
        aWandererF = 11322722962473467049U;
        aWandererG = 12544088870715611770U;
        aWandererH = 17518294361627747967U;
        aWandererI = 12320387366943215330U;
        aWandererJ = 9462501842676408700U;
        aWandererK = 16962042696355124103U;
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
    TwistExpander_Rugby_Arx aArx;
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
    TwistExpander_Rugby_Arx aKDF_A_BArx;
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
    TwistExpander_Rugby_Arx aKDF_A_CArx;
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
    TwistExpander_Rugby_Arx aKDF_A_DArx;
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

void TwistExpander_Rugby::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 13833568486646454164U;
        aCarry = 16596173155977477471U;
        aWandererA = 14419437833029128299U;
        aWandererB = 10095224561505605433U;
        aWandererC = 13694270275191811496U;
        aWandererD = 14246395971361017788U;
        aWandererE = 15205931304754233034U;
        aWandererF = 17341646360940806476U;
        aWandererG = 17517701478420306839U;
        aWandererH = 10865420364714707062U;
        aWandererI = 13592191697186470086U;
        aWandererJ = 15533794437766696332U;
        aWandererK = 10252724889238077380U;
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
    TwistExpander_Rugby_Arx aKDF_B_AArx;
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
    TwistExpander_Rugby_Arx aKDF_B_BArx;
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
    TwistExpander_Rugby_Arx aKDF_B_CArx;
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

void TwistExpander_Rugby::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE89E6057F4E5E7E1ULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xC98F24D576194B23ULL;

    std::uint64_t aWandererA = 0x870ED42267F7F56AULL;
    std::uint64_t aWandererB = 0x9C993AFAF7141515ULL;
    std::uint64_t aWandererC = 0xFDF2F10D8E7B8D2EULL;
    std::uint64_t aWandererD = 0x99CB7163575F7652ULL;
    std::uint64_t aWandererE = 0xFE80F3B50C9C42FBULL;
    std::uint64_t aWandererF = 0x8EB8D4CD6123D24CULL;
    std::uint64_t aWandererG = 0xBAB410170C281A79ULL;
    std::uint64_t aWandererH = 0xB6B8D6C04FC3C386ULL;
    std::uint64_t aWandererI = 0xAFAB6137E2300B95ULL;
    std::uint64_t aWandererJ = 0xA6F6FAA7F3EB511FULL;
    std::uint64_t aWandererK = 0xAC93316B5B884053ULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA);
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
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistExpander_Rugby_Arx aSeed_AArx;
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
    TwistExpander_Rugby_Arx aSeed_BArx;
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
    TwistExpander_Rugby_Arx aSeed_CArx;
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
    TwistExpander_Rugby_Arx aSeed_DArx;
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
    TwistExpander_Rugby_Arx aSeed_EArx;
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
    TwistExpander_Rugby_Arx aSeed_FArx;
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
    TwistExpander_Rugby_Arx aSeed_GArx;
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
    TwistExpander_Rugby_Arx aGrow_AArx;
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
    TwistExpander_Rugby_Arx aGrow_BArx;
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

void TwistExpander_Rugby::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Rugby::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 16192229368252031508U;
        aCarry = 11910267607775736260U;
        aWandererA = 12858723327083710297U;
        aWandererB = 9837860388676991022U;
        aWandererC = 13762470484026243024U;
        aWandererD = 9817220265747210480U;
        aWandererE = 12753556547316004130U;
        aWandererF = 17552989669698236294U;
        aWandererG = 9744956166213634579U;
        aWandererH = 10706131515207078725U;
        aWandererI = 16422821556084686436U;
        aWandererJ = 16567261410253009508U;
        aWandererK = 11636958294872273674U;
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
    TwistExpander_Rugby_Arx aTwist_AArx;
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
    TwistExpander_Rugby_Arx aTwist_BArx;
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
    TwistExpander_Rugby_Arx aTwist_CArx;
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
    TwistExpander_Rugby_Arx aTwist_DArx;
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
        TwistExpander_Rugby_Arx aGrow_AArx;
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
        TwistExpander_Rugby_Arx aGrow_BArx;
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

void TwistExpander_Rugby::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 1, 0 with offsets 1931U, 4311U, 7379U, 4727U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1931U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4311U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7379U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4727U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 0, 3 with offsets 3324U, 4261U, 199U, 3326U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3324U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4261U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 199U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3326U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 3, 2 with offsets 3984U, 5857U, 3504U, 2070U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3984U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5857U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3504U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2070U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 2, 1 with offsets 4408U, 7768U, 1186U, 7985U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4408U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7768U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1186U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7985U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 0, 2 with offsets 109U, 554U, 139U, 41U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 109U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 554U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 139U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 41U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 3, 2, 1 with offsets 327U, 1550U, 813U, 892U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 327U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1550U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 892U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 1, 3, 0 with offsets 196U, 1350U, 1849U, 31U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 196U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1350U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 31U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 1, 3, 0 with offsets 1064U, 1002U, 1378U, 190U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1064U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1002U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1378U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 190U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 437U, 197U, 354U, 310U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 437U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 197U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 354U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 310U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Rugby::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 1 with offsets 7005U, 1782U, 4929U, 205U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7005U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1782U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4929U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 205U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 1, 0 with offsets 7116U, 4507U, 3633U, 2996U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7116U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4507U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3633U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2996U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 2, 3 with offsets 7662U, 4694U, 2943U, 7070U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7662U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4694U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2943U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7070U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 2 with offsets 7203U, 6896U, 1852U, 2490U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7203U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6896U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1852U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2490U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4364U, 5358U, 5588U, 7582U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4364U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5358U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5588U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 7582U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 576U, 518U, 519U, 1502U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 576U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 518U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 519U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1502U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1178U, 170U, 2010U, 1654U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1178U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 170U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 2010U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1654U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 46U, 1534U, 1268U, 17U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 46U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1268U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 17U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1227U, 1627U, 130U, 1989U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1227U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1627U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 130U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1989U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 0, 3 [0..<W_KEY]
        // offsets: 987U, 1015U, 1108U, 111U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 987U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1108U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 111U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseASalts = {
    {
        {
            0x596F473C54773B97ULL, 0xD9D03A765FA2EDB5ULL, 0x532B25BF2A6D79C9ULL, 0xB30AADD813FC698AULL, 
            0xE1C6FFDF1B4B860CULL, 0xB59ADE0201B1B3E7ULL, 0x4FB93C71656C23A5ULL, 0x2FAEA2540F0B2CACULL, 
            0xEE85BD292C40B69FULL, 0x6459970430950FCFULL, 0x0FD8D3A53BEFE129ULL, 0x783ECEA0F70263CBULL, 
            0xA576E16618C5051EULL, 0x45EE4B74F4952C9DULL, 0x43E5166992323C0DULL, 0xB870A5A754AF21B5ULL, 
            0xE96095989373463AULL, 0xF87D9701F615386BULL, 0x9C6D8123E0A47496ULL, 0x1E057A7B6C5C7248ULL, 
            0x96E065389E38CE19ULL, 0x7C32D005DC461172ULL, 0x98A1FB8D48599E42ULL, 0xB8F8C93517713358ULL, 
            0xF63744E378DDE2D9ULL, 0x763E4200996EAB28ULL, 0xE68838840E816418ULL, 0xDE9234763E33DD97ULL, 
            0xB92E3B0507FD18EAULL, 0x61A9917E86533E64ULL, 0x4A58E9DEC9BDD1F6ULL, 0x84382EE82E22A7EFULL
        },
        {
            0x9D73F1602D49A971ULL, 0x08EB05308CD822C9ULL, 0xD787489C60E75495ULL, 0xD23BAD17542260CEULL, 
            0xDBF224E0772B7B33ULL, 0x794C651DCE91A20CULL, 0x1825AD457CA33983ULL, 0x648704C1DB9ECEE3ULL, 
            0x6DD6413CD37B991CULL, 0x47E3B8FB185BCE2DULL, 0x5ADDD16A86CACFABULL, 0x59F5684E833F5A5EULL, 
            0xB13AE4C9C7611B35ULL, 0x47BC1EEBE3A5A5A2ULL, 0x8F73A38D614F6868ULL, 0x6CF217CCA8D8FF07ULL, 
            0x486FD06024BB25A6ULL, 0x78A12B4814CA000EULL, 0x615E99AF210ABB9CULL, 0x529D9C6D5C9EAEC6ULL, 
            0xC42DD875B8302DA7ULL, 0x8915BFDFBD426EF2ULL, 0x181AD8D1DD42258EULL, 0xAE749BB17B98FB05ULL, 
            0x59270C9B8970C9B0ULL, 0xF2216157D3863938ULL, 0x44DF9DBD76B41A47ULL, 0x5A91EF12DC216E08ULL, 
            0x5BE04C80CAC159F8ULL, 0x3F0A8DE303727A9CULL, 0x047E33117A11F999ULL, 0x5ECE0F1A1F3125F9ULL
        },
        {
            0x9D302C998BCEC903ULL, 0xF2BB3C20C4C3091AULL, 0x8ED422BE75B63075ULL, 0xE5E39EA7E85655FEULL, 
            0x9AB7924E9FFAB613ULL, 0xD8BF066BFE98238EULL, 0xAC80AD9BA83C38F0ULL, 0x86AE0D5218979652ULL, 
            0x1EA540A407A8B846ULL, 0xC8CD9C68108A362FULL, 0x242CB13BF920BF3AULL, 0x2CD0469E57AB17E8ULL, 
            0xB18F31DC8649A882ULL, 0x3E3FB25537C0E54BULL, 0x8DC17E869BA5F56DULL, 0xE236BE0368977461ULL, 
            0xC8F08372F300D77EULL, 0x00511CA25B006DEFULL, 0xF7301969BB36776EULL, 0xE5EB986150EDA14EULL, 
            0x09DDF8BBB9D3E4D2ULL, 0x5174C33112A8805BULL, 0x1F281B8F5B3C307EULL, 0xF5890FA1D8C1C90BULL, 
            0x64F87AE5EAC25506ULL, 0x4A14A3B55BF2D048ULL, 0x78E1BA594E1893B7ULL, 0x30EE9F3E17133D7DULL, 
            0x321491FC991DBC48ULL, 0x052301C0E215768BULL, 0x449B69ECA352BD89ULL, 0x03A79626B195FED1ULL
        },
        {
            0xD7234806DDC73FBDULL, 0xD86D22FFBCD76836ULL, 0xD081D33848835512ULL, 0xCB164533C07E3C9EULL, 
            0x240351E910074962ULL, 0x63E09A063CCE769DULL, 0xE66A750407FA4163ULL, 0xFB16E2D7E3CAE2D5ULL, 
            0x9BECEE5AA05BFAE1ULL, 0x467CF718170E53EAULL, 0xADE0BA64C1FC0813ULL, 0xD100FE03E6288EF6ULL, 
            0x87445F888E7C6B08ULL, 0x1100F08DDB45C5F2ULL, 0x7B964BA9B6125D6DULL, 0x2AB179470A07E671ULL, 
            0xF7E212997268CDA7ULL, 0x6A35FE0FCC5C7AA6ULL, 0x5BF3A856D02D7D3CULL, 0x4087048B4A7EDFD7ULL, 
            0x3EF4E4DF414D6570ULL, 0x2F314AAD38DA2435ULL, 0xFE0BE59C83BA2BB1ULL, 0xC88430376D15EACFULL, 
            0x2F7038F86B62934CULL, 0xB2BF41E4735068AFULL, 0x82DDF127AC77F45FULL, 0x0C52CD95D525CBF6ULL, 
            0xBCF84F077702BC39ULL, 0x81A63EF8A07B4479ULL, 0x97125B0FFFA30CB0ULL, 0x8EAAE8AF7E201767ULL
        },
        {
            0x087623D424052F2FULL, 0x266AE9D043C75C6FULL, 0xDBD5FFF95A9650B5ULL, 0xD849134F948B6AF3ULL, 
            0x924E2F3799D6CFCDULL, 0x276148E06B8586C4ULL, 0x2C49D7AEADCE8C64ULL, 0x101289704D045B84ULL, 
            0x81CAF5F6D50858F4ULL, 0x0737035B1506176EULL, 0x43BB359077BD757BULL, 0x8BA754F9CBE5A46AULL, 
            0xDAD0985AAFD5E3DEULL, 0xA3D958F733C1EC2DULL, 0x42C44F6D71539931ULL, 0x1136DDF22CD7D093ULL, 
            0xC3DFE0023BF90608ULL, 0x9E98D3466441DAADULL, 0x877AAEB055E1DC73ULL, 0x63BE726EC6D63EE4ULL, 
            0xF712F7ACFA2DECEFULL, 0xE3026976AC07B001ULL, 0xCCAD0AEC8283F7E0ULL, 0x9B371788CF90FBEEULL, 
            0xCA6200498CC624CCULL, 0x99977D7F12CAB896ULL, 0xE95AECFE413ADCE2ULL, 0x33D2D65D13260414ULL, 
            0x644F6C18F14FF6EAULL, 0xD7B8018DBF09FCDBULL, 0x37AB4FC28DC249F6ULL, 0x71B0A77E1E53B7C6ULL
        },
        {
            0x2A0372E1AC049267ULL, 0x8A931994AC61DFEDULL, 0x9CA37D41AC67103AULL, 0xAE52542EF703AA3BULL, 
            0x7CCA21E715DAA69BULL, 0x5FF8FB767077ACC5ULL, 0x873CCA8E0BA4BAE0ULL, 0x4A58658012961DA1ULL, 
            0x1CA4B5D98EB33F82ULL, 0xE72FE407B4321C5EULL, 0xA2C9E7062FC65C42ULL, 0x496BB0BB1A59B2EEULL, 
            0x5C4C8DD6D19BA336ULL, 0xEBE2F27B5C21BEC3ULL, 0x9AD42C2272BDCEC2ULL, 0x514EA95BC52AC13EULL, 
            0x186DB9CD750AC1E0ULL, 0x02C9282B5C483638ULL, 0x9BEE847A4BC9348EULL, 0x9CABD91F69B7E2B1ULL, 
            0x851E0FD11D131105ULL, 0x00DE85780E710DC9ULL, 0x0DBA98DA33161FC2ULL, 0x227EBE6E4AC6EF76ULL, 
            0x5E1F694A32A2B1E5ULL, 0xB16C59A40BF7DE12ULL, 0x45EFFDE3B8A06E69ULL, 0x11145970B3FFCAE5ULL, 
            0xAFB5AFA1DC07743FULL, 0x76581F3FF1384DA5ULL, 0x694F9E6AA57A7114ULL, 0x19D3C8312ADA0FF9ULL
        }
    },
    {
        {
            0xF2DA4C2B6868F61DULL, 0x761CF8B97DBEC2FBULL, 0xF3321C86BBC8D597ULL, 0x499CF6448F753B5CULL, 
            0xFB435CF08A90DDAFULL, 0xA4775E3963D9E40FULL, 0xA869031D78385680ULL, 0x359AD57D99598F2BULL, 
            0xC4B818AE8A4FD770ULL, 0x49836A9E49678EB2ULL, 0x9019FBA0C6BE4B3DULL, 0x13A4E7411434DC42ULL, 
            0xBF107806A0E82F47ULL, 0x89C8FECDE8942470ULL, 0xA7C835CFB6F907DFULL, 0xBEF4D77EE59F696DULL, 
            0x7B8B12366ABBDBB7ULL, 0xF1AC23B5563E735BULL, 0xBD9AB6C994EC9122ULL, 0x48126138E60430DDULL, 
            0x58E5CF16DE1E8E0CULL, 0x9E3A8D8DD6CA0CC4ULL, 0x2F979F84131F0654ULL, 0x7621696691A0CA25ULL, 
            0xFC91C675475CE46BULL, 0x6134B6E4C9005B7EULL, 0xE46BC295864216FDULL, 0xF5F8684C9D1B0239ULL, 
            0x1FE9DE43163F010FULL, 0x00B13B259C3F6EFBULL, 0xDD37E0189FC31AFAULL, 0x595F525A3BA50D05ULL
        },
        {
            0xA1BFA516C7C4CE64ULL, 0xCE733EE9DFB3C0CEULL, 0x56BA3BCBDB5783F9ULL, 0xB1BD5C17D4400560ULL, 
            0xDB803012700D3B15ULL, 0x39466869471DB1AFULL, 0x0ABBF7811EDAAC3EULL, 0x34E3804660EB9069ULL, 
            0xDF3C87B6CC188699ULL, 0x55F18A744F9E4790ULL, 0x3289DED727EF4CF6ULL, 0x8B8A7147DBB90388ULL, 
            0xEAE6D7A39DA11E22ULL, 0xD4A35F988673F97AULL, 0x7FDB99A0DF97A543ULL, 0xCD8181FF309EB820ULL, 
            0xC70654CB2836CCB1ULL, 0x9A568C7FA0C614C5ULL, 0x63E01654DD81BC07ULL, 0xCA5BD78C072F09F9ULL, 
            0x630F60E50AD51FA2ULL, 0x56743F843A0A778BULL, 0xDA8584C099EDDF73ULL, 0x98FC44390F74F96AULL, 
            0xA0A6F7C459D274A5ULL, 0xA79349B84BEAA6F0ULL, 0xC4D4BC03CBA66797ULL, 0xC8F7E4D3D7D6000CULL, 
            0xD218628218E6BE36ULL, 0x7DDF0C2B15673CE8ULL, 0x3284E9B99DDBE74DULL, 0x3F844973CE400AC2ULL
        },
        {
            0x6E68E017C5BF9098ULL, 0xC2B538D49C6083FDULL, 0xA64953A798D0C80DULL, 0x03B857C97D7C27F5ULL, 
            0xAF2544719C908923ULL, 0xF90D9B741089B13BULL, 0x13E7B8D2CBF0F898ULL, 0xAF22FD278D2C25A1ULL, 
            0xA249AB2307F6BADBULL, 0x52E8504DA2481168ULL, 0xC14F1A6C2029C6DBULL, 0xE6EBF67615F02CE3ULL, 
            0xA89B1D05CECAF6DEULL, 0x177DA8527862DAEDULL, 0x5414F32EEEA0B737ULL, 0x404EFCB0D7B1378FULL, 
            0xEE5BBF7882E67D8BULL, 0xDAD220B561CD7BCDULL, 0xE954AEBEAA4922E9ULL, 0x05FF6E50A09D9D0EULL, 
            0xEDD6F94BEFBB6449ULL, 0x49933CE8A178AFE4ULL, 0xEE330848289E0287ULL, 0x5640293AC77331D4ULL, 
            0xDDB3FDB4DEE6E2A3ULL, 0x550E586D6A5A49FEULL, 0xD0FDBCE2D2D256A5ULL, 0x1141BF2E6EB2FF97ULL, 
            0xC5A512705A043F72ULL, 0x5FBFA90D8069B3A5ULL, 0xA2EBDEBB72666A14ULL, 0xA71D4C4EB5DAF25EULL
        },
        {
            0x13EF95A7ECB055D6ULL, 0x5530BDA68B236CBBULL, 0x9B6F78008B79A8D8ULL, 0xEA6749580C4FB612ULL, 
            0xA6F6EDC971E6EC3FULL, 0xADAED5B3D5DB84DFULL, 0x8956D0E94C06F072ULL, 0xD113330B38FA60C4ULL, 
            0x6D2C7EC2D6103ACAULL, 0xE0809FD05D9FF73EULL, 0x8E2D07E45409388AULL, 0xBA449F283B9743A3ULL, 
            0xB340D3250569ABFDULL, 0x49D16020B9698DD4ULL, 0xD648943BB3C88DBAULL, 0x50C9B9655B926439ULL, 
            0x368DB783F834DF89ULL, 0x26ABEC1D754B4F5AULL, 0xA24453E3B7EF91A1ULL, 0xD42893A38A1EB615ULL, 
            0x989A3598CDACA3F4ULL, 0xB441E43BA6B35798ULL, 0xDF781CFA6DE899DDULL, 0x7FE09DA60A8A021FULL, 
            0x5A8060E7CACAA194ULL, 0xA22C0409891835B5ULL, 0x9366D28D98BE7F64ULL, 0xDED22C0008DD3362ULL, 
            0x65AF96DEFA765FE8ULL, 0x53EB5A574C0FBA89ULL, 0x3F77B71DC3FD327EULL, 0x85EB2CDBFC02DB17ULL
        },
        {
            0x6F4F33841DE830BAULL, 0x886466B98B511288ULL, 0x38119F8D7F930186ULL, 0xB7A7E07582C33261ULL, 
            0x05A14481824AE5CAULL, 0x58B67B3F0BC10FBCULL, 0x62C43AEC1A68A042ULL, 0x587BA60DA5FAA6BDULL, 
            0x30C924DAE3BE755AULL, 0xB6D9C76DEAF067BFULL, 0x28C55BDB5A8026FFULL, 0xF49C16D7AA0C505CULL, 
            0xB3CFDD703D9BC068ULL, 0x285D024E9E1FA9F3ULL, 0xAE5F0AC8436619D3ULL, 0x2BC82FCE2343DF65ULL, 
            0xAC01F29B15EB7858ULL, 0x2B6CE5A04AB8D38BULL, 0x67A3794DAED2F73EULL, 0x6A910E1FD5155F2EULL, 
            0xC80A15F86F8573E2ULL, 0x574471C14263B95DULL, 0x9235ACB075D821E6ULL, 0x4840FA2A4AEE79BFULL, 
            0xBDAE9FA3423F4BF4ULL, 0x2970E8BB3F4FE1C2ULL, 0x3C55C6FCDA488B7BULL, 0x436E42D6A3FC5135ULL, 
            0x675D9DD004596D6BULL, 0x93CAA48052DAFBE3ULL, 0x64C1486694F3CFAAULL, 0x884148151D37863BULL
        },
        {
            0xAD6853063AACCA2CULL, 0x23822816D76FA0C5ULL, 0x57DCF8ADAECD54ADULL, 0x7BFC36AB6EA3E876ULL, 
            0xDF1AA05F9856E124ULL, 0x87108B649E13E1D5ULL, 0x37595EA0DC7DCCC1ULL, 0x70AF0E78D1322150ULL, 
            0x05E95E1CA14785FDULL, 0x0978131EFE597338ULL, 0x651A39087BCCEAC3ULL, 0x3BFDC7D40F0669D5ULL, 
            0x2F96C90830C5EEA2ULL, 0x4839D28E105D73CEULL, 0x1B29AC20B4630FC6ULL, 0x699E03550C9BF077ULL, 
            0xFBAE380218841FCDULL, 0x6033793D401908DDULL, 0x6E4BA6A144E226A9ULL, 0x7AD5283EC060254EULL, 
            0xDC1BE9BDC0118715ULL, 0x1DFD9E682A797782ULL, 0x4756815BC261B4E8ULL, 0x48AAFDF6947C27ACULL, 
            0x6FA65C2FAFE7CD75ULL, 0x87167D4FACEABED1ULL, 0xEBEC979B1EB33FC9ULL, 0xF3D547E7865B42A8ULL, 
            0x8BD22C12DB8F91DBULL, 0x908DD0D7AF068824ULL, 0x618354DC7FCA29BDULL, 0x581C2AFB7D1C779CULL
        }
    },
    {
        {
            0x5C37BA25E1291565ULL, 0x9BE0A7FCE69A8C62ULL, 0x566DD86100216CF7ULL, 0xD5170D5DBF79D42CULL, 
            0x7E73FDCDA8530111ULL, 0xB480347E8E23BACCULL, 0x4CE8CB11802B690FULL, 0x9417BBF85277544FULL, 
            0x62E5C4FA65289D84ULL, 0x93DB2EBA6F08B661ULL, 0xD54385B87FF38EB1ULL, 0x956A7715C6683CD2ULL, 
            0xD87127F7817DB5BEULL, 0xC3340FF413E9E6A3ULL, 0xE3CDF5533C312160ULL, 0xBC6B7955F50ABDECULL, 
            0x55BAD1D61A27755EULL, 0x8C5B8BFF6C42336FULL, 0x571DF3424FCE13B6ULL, 0xE1E7E1A0A38F3F51ULL, 
            0xD8F7726C8505EB4CULL, 0x624F1B75989563CAULL, 0x5F4C5175123FD216ULL, 0xD5B294C6AF54740AULL, 
            0x2BEA25F91FA5F513ULL, 0x9B90700986EA8DB0ULL, 0x19692C73F0B7D827ULL, 0x3634D7D1E15AFD53ULL, 
            0x14B78F8AE15ED027ULL, 0x64CABEB9984A2C8CULL, 0x32C9A62404F728A9ULL, 0x2F77C248F5BC9146ULL
        },
        {
            0xEEC899EDBCFE6F6CULL, 0x10AF8B546E2D5C75ULL, 0x0D88DDFA525DC487ULL, 0x86717E07A2CFA2FFULL, 
            0x7DEB9CBD7045FCF6ULL, 0xEEF8907E27711A11ULL, 0x9DBCAC5F829CA7A9ULL, 0x7ED5413B6369DE5FULL, 
            0xEB48703B23088434ULL, 0xC05F374825EB79ECULL, 0x25A9B15AE09BE7CAULL, 0x982E225B1F3F82A8ULL, 
            0xD395BF0EA1C81EFEULL, 0x47BCDD5AE35BF925ULL, 0x25F029CB7021A254ULL, 0x5502C6F3760FD97EULL, 
            0x6FAD27C016F6CD93ULL, 0xC0844A9AC726225AULL, 0x8EDF01E98415E7D8ULL, 0xF0BD3BFCB1FE411BULL, 
            0x33E66060786DFC99ULL, 0x7C464FCB19036F09ULL, 0xDAD8FB78C6041E7DULL, 0xB77F93A5C3BD79D1ULL, 
            0xF6C336F57FDB4A65ULL, 0x02F6CEA4563D0C26ULL, 0xC0CC0C15E7B5FF6BULL, 0x09E95C8E035534F4ULL, 
            0x9B374DBAC87E68B9ULL, 0x34481CE783715DD2ULL, 0x56ABE077F07C209EULL, 0x61A1FF2AD0260D73ULL
        },
        {
            0x41720712F1A6AADBULL, 0x01A95BA7404FC607ULL, 0x308C726A5AB03944ULL, 0x769248AA720CE4DBULL, 
            0x47830DD225C4A4A0ULL, 0x727E26CAB6C8FA8EULL, 0x816CBE77B2421602ULL, 0xAA794796FFE4C9E6ULL, 
            0x691A3F9E5309016EULL, 0x70E527D8ABA473A4ULL, 0x1AE89B00A79C1501ULL, 0xD27F7BDA0D7DABE0ULL, 
            0xCA5FAE39403618F3ULL, 0x2770796F10200B9AULL, 0xAE1C0B33CFF501A7ULL, 0xE911866ECF09177CULL, 
            0x651B7CB0919FDA49ULL, 0x8D19755533D4288FULL, 0x1CA7969EF85B91C1ULL, 0x24C5DBDE06CB7209ULL, 
            0x2A6BD5E0D59CE964ULL, 0x80E77BA4283CCF3BULL, 0x75A320A90023599CULL, 0xB4E44F7FF5F05389ULL, 
            0x06677B4400E98389ULL, 0x5A79DA3473CCD2AFULL, 0x9AB964AB619812FBULL, 0x7669228F38D543D1ULL, 
            0x9AB921C8B1B9C3B1ULL, 0x908566D7A8B1320FULL, 0x8E7FBF59B1072C55ULL, 0xFC156DF4156659F2ULL
        },
        {
            0x526358FDCB0869BFULL, 0x65501CBE92444D50ULL, 0xD1B5E421AA211008ULL, 0xD5461A41E94B82D5ULL, 
            0xADE313F806AF58BCULL, 0x803245D5DE2E7908ULL, 0x43ADD4725E27371EULL, 0xB5C7E1CF3A43046EULL, 
            0xF9D2F14E029B8BAAULL, 0xFB03F6E0CF53B5FFULL, 0x6AAB4ABA216200B9ULL, 0x8536CCB0DFFFB093ULL, 
            0xC3E8D5225426AAEDULL, 0xD9F917B66097EF64ULL, 0xC18AF25FF6FE12AFULL, 0x06E3AC5FDA207B41ULL, 
            0x7C41F97B6AC3D5D6ULL, 0x70630551E1ED2ED9ULL, 0x945C6284AAE63D89ULL, 0xC082D3FF505AA555ULL, 
            0x9ED22E32BF9F0B56ULL, 0xC0FAAD3D9C76E7F3ULL, 0x49C004B426339808ULL, 0x51D8808BD3E294A4ULL, 
            0x5F334B722C2CCD36ULL, 0xCC3D5DCE038447CFULL, 0x15B1F4745628B520ULL, 0xFAE6492DF1BFB36BULL, 
            0xCF2FA5D491214C38ULL, 0xC9772F9E037D4827ULL, 0xA7147DA9D2BF7FCCULL, 0x1855AA2AFB0C9B99ULL
        },
        {
            0x3C23D724E2F3B73BULL, 0x4061EFA65E21FCBFULL, 0xBC0312F5B66918D2ULL, 0xF559DE092E9E0CA4ULL, 
            0x61E2B28A91C71455ULL, 0xCB7CC1BE4B0F045EULL, 0xDB8E8F88D830F1AAULL, 0x94C07F053B816450ULL, 
            0xA5670A57F3A6F10BULL, 0xCC015A70ABE7508EULL, 0x5DF33FAC1FD061BBULL, 0xC88628495EEBC4CFULL, 
            0x93F7B4BF46D07D19ULL, 0xF4F6E8FA438047C2ULL, 0xD91E4211546571BAULL, 0x26CEBB19E7F6BD0BULL, 
            0x178CEE937E57C2D7ULL, 0xCC13420F81FC657DULL, 0xE762BD6F04E39949ULL, 0x818214D6055F01E9ULL, 
            0x1DDBE21C18F5D309ULL, 0x5B6563783C1A607CULL, 0xE239D70872888790ULL, 0xA84607B629C0C4D6ULL, 
            0x786FE6E159B14E34ULL, 0xC80C04CD9051D6CEULL, 0x489D2E07243F305DULL, 0x68C81CE48DC88584ULL, 
            0xFE8E587EAEA40309ULL, 0x62DE425DFEF823B9ULL, 0x1B02468703010828ULL, 0x117465D3E5F56530ULL
        },
        {
            0xBDE5319B1C51CE0DULL, 0x69CEAD324D4BE41DULL, 0x740D255CA644AD91ULL, 0x987FAB292CA46DD4ULL, 
            0x7FDF160C57CA7CC8ULL, 0x9427ECFF12DDC0E3ULL, 0x0EF222B402F89638ULL, 0x80B90AEB3644A2B9ULL, 
            0x09F16BFF06D27436ULL, 0xFFE86D3368217D36ULL, 0x5EA5B1DBF8AACB93ULL, 0xF54A95479DD36C31ULL, 
            0x844337C177444576ULL, 0x732D535DC588ABDFULL, 0x7B350766142273AAULL, 0x52325272A76FEE4DULL, 
            0x98F5EE1806C8282FULL, 0xD1EBD93963D5E992ULL, 0x140F71292A346221ULL, 0x2B8003E93A7C0DA5ULL, 
            0x4F3D8248EBDCB6ECULL, 0x43EF017275FE56BCULL, 0xABE30E7DF3FA003BULL, 0xF903931D177000A0ULL, 
            0x7B13CBE56DBFBF6BULL, 0x07EEC2D24228B4D3ULL, 0x06737D2C76768F8BULL, 0x4CF1C2568BFD5FE9ULL, 
            0xD8D6910E898C66D6ULL, 0xA84412D936037142ULL, 0x49C53547FCA7CA55ULL, 0x0632ECA4967D0A89ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseAConstants = {
    0x1ACB2AAE342D570BULL,
    0xADEF3942D05F193CULL,
    0x6EDBBF2B493A1556ULL,
    0x1ACB2AAE342D570BULL,
    0xADEF3942D05F193CULL,
    0x6EDBBF2B493A1556ULL,
    0x3961191CFFA6DD73ULL,
    0x763646B6F073C354ULL,
    0xB1,
    0x4D,
    0x32,
    0x2D,
    0x46,
    0xAA,
    0x47,
    0x55
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseBSalts = {
    {
        {
            0xDAAD9DA72E7D1EF3ULL, 0xF9C308BD1B140F23ULL, 0xBE1267B6EB03BE8AULL, 0x76E646C442D680AFULL, 
            0x5111E9E845B520B5ULL, 0x1E30237604AA97F8ULL, 0x2E01FAD93F436A98ULL, 0xA870F3502D058626ULL, 
            0xA88D3C8B78721E0CULL, 0xB24000052417C058ULL, 0x3C7785BCBB24F016ULL, 0x876C300FE20FC710ULL, 
            0x0F691DA0E2E36CAEULL, 0x8B971E9F12C12A0FULL, 0x59770BAC80476355ULL, 0xB4C9C16700545869ULL, 
            0x57FACA19AD6F95E8ULL, 0xC793DCE18B5EFB60ULL, 0xDB3D582D025B866DULL, 0x98104D4E01C620F7ULL, 
            0xC3CA00D5A609B9D9ULL, 0x1595C5EBE5198245ULL, 0xC6807DF5CF9815C2ULL, 0x48B20478C5A392BAULL, 
            0x0A2DE61868479786ULL, 0x6763DE3445CBD847ULL, 0xFD411D4F68E946FAULL, 0xAF540222BDBFEF01ULL, 
            0x328B8C5E83269115ULL, 0xF709453ECC4F3926ULL, 0x137F09121B73D343ULL, 0x335FB9AF4F7A80C6ULL
        },
        {
            0x9C9084293501A307ULL, 0xBCEA8B39D7A0443DULL, 0xA44DAFB5921BAFE1ULL, 0xBC498483D6D121EDULL, 
            0xE1CF0CB05FBE2150ULL, 0xDECCB0D2A63000B1ULL, 0xDD19720B2A254B68ULL, 0xEDF41AE55768A4F1ULL, 
            0x5D6BD9E9187F2A3BULL, 0xEC8ED7671F8EEA40ULL, 0x48DBF8D8D3B7FEE0ULL, 0x4AC074A135388B0CULL, 
            0x6645BA00525141C6ULL, 0xE84C21065864B076ULL, 0x7745823865D0BEE0ULL, 0x8E8AC67651C52364ULL, 
            0xBE881962A9A72259ULL, 0x727E31F4F4BBB78AULL, 0x11883FFD4EDB3A56ULL, 0x3661F2201A960479ULL, 
            0xC692C44E7D796BCFULL, 0xA122B8AE9DF0F873ULL, 0xB9C6F0A5E34E2D61ULL, 0x90D7C2912C0B6337ULL, 
            0x51630A45A15E46D1ULL, 0x003BA9806CD849CFULL, 0x87C0AD789205D99BULL, 0x2FCEC7F39DC708CBULL, 
            0x8F90B9CF4A24882AULL, 0x42F90B11070AC8A7ULL, 0x9C9F0114F7087F16ULL, 0x6DCB7D2B6D827D19ULL
        },
        {
            0x08C0C9E8BA0272A8ULL, 0x0942AFB2FA7197EAULL, 0x4162F26CA6919174ULL, 0x9754EAE26357ABACULL, 
            0x414294992B182F29ULL, 0x18165DCCBB5D8F22ULL, 0x9F333DC5A0396121ULL, 0x10AD193FB7D211BDULL, 
            0xAEB887508C541629ULL, 0xFC00EE33DD340D68ULL, 0xDC187301C24C5AD9ULL, 0x631CD4DB9525B3A7ULL, 
            0xE2EA435815962A15ULL, 0xB87018296A7D9FC0ULL, 0xF687EBA7D5E714A3ULL, 0x1946F4665DEDEFFDULL, 
            0x0CD0BFFAFE093764ULL, 0xFD082ED95DF6BF27ULL, 0xC69D138545FC78BCULL, 0x9F18ABBC6F8E892AULL, 
            0x4C64E2BD4E829437ULL, 0x9E18E2961915A15FULL, 0x8C531FE890A603C9ULL, 0xA206714E02722877ULL, 
            0xDD41F14005FFCBA0ULL, 0x447DEF0C803CE296ULL, 0x97F2AA8FEE8BDA91ULL, 0x6695FB8DDED24EE9ULL, 
            0x6D97E76AE01C4375ULL, 0x3F112B78983A077FULL, 0x60DC170451F2DA1EULL, 0x5B6FB51FF089147AULL
        },
        {
            0xC708C672251F4951ULL, 0xE08DE03345FABB43ULL, 0x35618AA01F0E0A73ULL, 0x35C3AFEA0D85FD9CULL, 
            0x3BF0B6BE638B9081ULL, 0x6246BEFBDECF2EE0ULL, 0x50C9518B40E4C5CEULL, 0x56078BF4A8EF7C0FULL, 
            0x43E09E98A0211890ULL, 0x8C8B65DD8A6656D2ULL, 0xE225BFE02DF2F578ULL, 0x48EF5F7DDC895A94ULL, 
            0xBCFE9EC5088B8B22ULL, 0x11F84317557DD13BULL, 0xBC2C7CFCC1031F4EULL, 0xD009ED3634A791A0ULL, 
            0x2BE27C910A5FA383ULL, 0x25789865B8FA4830ULL, 0xAF164347FDB88F2FULL, 0x4B43F14AC000A64CULL, 
            0xCD2362A236DA5973ULL, 0x417DDE7A5EBDB447ULL, 0xB7B12FA044232E21ULL, 0xFE33CB6796BDCB9AULL, 
            0xEE0DD41B2A9D4755ULL, 0x7F64FD66CCFA0B44ULL, 0xBF4C6ED03D81110DULL, 0x1C793F66633637E0ULL, 
            0x2EEA7A617A4596F0ULL, 0xE09D65CD8E41970EULL, 0x638A70FFF6492799ULL, 0xB7D1919DCBC28481ULL
        },
        {
            0x0CF0608698411A0CULL, 0x70647E733B9B6339ULL, 0x017A53FA21988085ULL, 0xFE5BA50038D173F7ULL, 
            0x687ED8C2353ADC07ULL, 0x6B905A434F0010ABULL, 0x35836301AF9EABEBULL, 0x139974C0CE2D5012ULL, 
            0xE3B5106827155F45ULL, 0x8166AE82344F64E5ULL, 0xA993B2A85528D0CEULL, 0x87184A0B081B6BD3ULL, 
            0xE471E8D3B19275C8ULL, 0x4C03BD5C8CD97366ULL, 0x7EB2C3D3C2F4F005ULL, 0xE3D74C6F9DC70977ULL, 
            0xCAD37C6B7D359391ULL, 0x213723C50A34AE16ULL, 0xD17E3AF3A195BAE1ULL, 0x08C00C406A8FE88FULL, 
            0x4F921D9C2425CE2DULL, 0xF111065D1D250D45ULL, 0x3A6BE6A88AA83263ULL, 0x69870727B02433BAULL, 
            0x11DD92152BA714DEULL, 0xA0BA286A37A42052ULL, 0x3D50A17CD71E7397ULL, 0x9E6B2C89E7B2DF9EULL, 
            0xB7D92C3C4B0A7A6CULL, 0xAA6943A2D8ABC0DAULL, 0x3E03861FA24F6217ULL, 0xC4B0DEA9D4659B8EULL
        },
        {
            0xABED967AD2E92EFFULL, 0x4C24E03F6E0FA5E7ULL, 0xDD09F6BE5A56A2D6ULL, 0x4795524F5C1A975DULL, 
            0xD7C5FDB5A07D8F47ULL, 0x3D0A8AD0EE65E88EULL, 0xF7A85F319EC1AA29ULL, 0x741AAFB1BBF6CA9DULL, 
            0x886DDD679E5D279FULL, 0xC6E7FDA69A86F873ULL, 0x7FD926DC9E2A4AE5ULL, 0x34F435D14170B6AEULL, 
            0xBB3C427B293C5CFBULL, 0x84125F7FC4F94BC9ULL, 0x39F81BD1F8B62372ULL, 0xA75B92CD805AB158ULL, 
            0x3DE993C95B58AF14ULL, 0xCAE627BCD9C1F686ULL, 0x98ECF7D9C9029C09ULL, 0x2A0DF9FF712B3B7CULL, 
            0xA603EC53A828CEB5ULL, 0x4025EDD113C6F11AULL, 0x716CC380AAFC7365ULL, 0xB67F6A3D76163D76ULL, 
            0x0CF3E9902AB0A281ULL, 0xD8847E5A1722911BULL, 0xFF560DC271ECFD4FULL, 0x100571AAB266EF87ULL, 
            0x1AC34D5F4BE90F8FULL, 0x5778E11592FD454CULL, 0x881756AF9A48100BULL, 0x4C39485E7FC2A396ULL
        }
    },
    {
        {
            0x46F3BD20238B8B50ULL, 0xE3B82E9507938C1EULL, 0x15D318066DA134EAULL, 0x7B635BBB058BA613ULL, 
            0xA12EDCC66B43DE7CULL, 0x82F0816BC50737DBULL, 0x816A6A6637B440ADULL, 0xC380CCD4A31D31B5ULL, 
            0x201C15F9F0F9E217ULL, 0x9E4892019D757A41ULL, 0x0659BA47B6A9E0D2ULL, 0x4FA1D38DC7A764F7ULL, 
            0x02CD666416B02CEFULL, 0xB48A0DB2EE66E312ULL, 0x6D2BA3B4B82C5537ULL, 0x17CD32E05F0B44F0ULL, 
            0xDF93A1ED85DE1CEDULL, 0xFF073E8D6489A067ULL, 0xF7F008279426ED3DULL, 0x9ABE68EDFD0E1585ULL, 
            0x09A33AFFB2EEC6BCULL, 0x0F32C72006C48056ULL, 0x7AFB2BEC0A53B0ACULL, 0x41851E51306EB9D0ULL, 
            0xDAB9826F59BB8071ULL, 0x4C2AC2387CFDBB48ULL, 0xDF41A7F54686DFC7ULL, 0x0A00C17488686F20ULL, 
            0xD63B0708C6D4B05BULL, 0x124BA18C61BC9555ULL, 0xB0C1514DBCAECA1BULL, 0xEA10D57C67AE6895ULL
        },
        {
            0x46B52DE26F1681ECULL, 0x58320BAF6B74663EULL, 0xBBA79E52262C55EDULL, 0x4904ABBF1002A81BULL, 
            0x0C828A8F44A3BBDEULL, 0x10F228E778716870ULL, 0x4E80FC9A2CE0888EULL, 0x9E86538D072E1EE9ULL, 
            0x0CEEC8EFF550530CULL, 0xA70F544752275584ULL, 0xC2D2B48C7DD74B2AULL, 0x78FF5C400C7E2F17ULL, 
            0xD0796CD88C2F8731ULL, 0xF9C152E2D8310387ULL, 0xEE9EE5BC226CBCCDULL, 0x7A76D024BC93A3D7ULL, 
            0xA15EB292404DC208ULL, 0xF34BB03579F244BFULL, 0xBE61EF95C1ABB562ULL, 0x2FA42C3EFFBA0693ULL, 
            0xC1D170CD255AA6D4ULL, 0xDC40AD2B58BB7826ULL, 0x21AE5B693E190523ULL, 0xB3A7F84557BC211BULL, 
            0x777E4F332FA5DC74ULL, 0xE522B7AD98A568ADULL, 0x549BFA01781F0987ULL, 0xAFC208DB48E16953ULL, 
            0x73A80FF7D6D6E372ULL, 0x400FF707DCA49987ULL, 0xB9C4A8E9B4048BDBULL, 0x3D67515684A88972ULL
        },
        {
            0xECC4F2D0FA0D3EAFULL, 0x1511D8C3A2EECA90ULL, 0x5ADE0ACFFDB5684CULL, 0x644CD8E0E23777CBULL, 
            0x0C53E96BA0D36EA3ULL, 0xBD1F1BD318825516ULL, 0xFD199E256AEECBCBULL, 0xB8F97E2F0651AE80ULL, 
            0x7653AF3DF5943135ULL, 0xAA45D15496E6CB33ULL, 0x62898D28219A1F2AULL, 0x20CED6A72181968EULL, 
            0xC4C0FC5F2CE4D40DULL, 0xC95E8CC9A0363145ULL, 0xD9D42A4DE806072FULL, 0x799A820B4D4026F9ULL, 
            0xD9226AC7DFB59E76ULL, 0x127F115CF50E30ABULL, 0xFD4F1D362C05F888ULL, 0x3DB71DE3FB511B25ULL, 
            0x56E61E2BCFC92EDEULL, 0x3BDC0C180FFD791CULL, 0xFC2261CAE3EF192AULL, 0x502B9619875EADE9ULL, 
            0xB38F942EBDA2A3CFULL, 0x5EA305903DC65EC4ULL, 0xAA6AD0FBE6DAF72CULL, 0x77FF3DF742F0A0A7ULL, 
            0xBBE3D9436D29AF29ULL, 0xC8708D1341995AD2ULL, 0x6198ECDFEEB888A7ULL, 0x05A7AFB9959A4410ULL
        },
        {
            0x14E345FCC3CFD0EBULL, 0x6C1AD9233FEDB85BULL, 0x740AB9043AD680DAULL, 0xE1E44D9EE5CA7C74ULL, 
            0xE5AD7D01285BC05CULL, 0xDE333F46A25BCDB7ULL, 0x958B1D2870934C7DULL, 0xB1363859A6FE905FULL, 
            0xA32296EC98287729ULL, 0x70291357DB7CB2E4ULL, 0x354EB0BD83936F53ULL, 0x0EAC07B94A1844B4ULL, 
            0xB5A207B9DA3C2DC0ULL, 0x3D469CB8A8C3F4BAULL, 0x8BC5144326875522ULL, 0x8AF035F57051CB73ULL, 
            0xF1396D4098F8E5CDULL, 0x65337FB932990A3AULL, 0xD51CF65F77D064DCULL, 0x127D9952C4937FE3ULL, 
            0x6167F5EE385E5892ULL, 0x44574DB9C6D01D2AULL, 0x0FC54EC19A7D161DULL, 0x8631386748E110E2ULL, 
            0xBABC492187513638ULL, 0x0A88982D453A138CULL, 0xD4625F2FC57DAA58ULL, 0x11724A73B972E909ULL, 
            0x7CD53D471BDC8BC6ULL, 0xC38BF16CD912370CULL, 0x4B5F4532370AFE82ULL, 0xF014B361DEB47BE4ULL
        },
        {
            0x268DDB32BD89D25CULL, 0xA4C488BE9095F4B2ULL, 0x9EEE8A72CF3063CBULL, 0x33F8444A3A9BE2C8ULL, 
            0xE0E0CA23F237B53FULL, 0xE9180C646E087ABAULL, 0xAD9A7F1232E68406ULL, 0x2AEDEA1141CEC9F2ULL, 
            0x9A00DDFF6091554CULL, 0xE5B8587F86F4FFEFULL, 0x2096BA5E1656D3A5ULL, 0x274092F1637CD33FULL, 
            0x4EDD2C8DF20A2205ULL, 0x859791004A012056ULL, 0x82AF54FE7ADDA0A7ULL, 0xDEC20DE5339E8C74ULL, 
            0x97FB875D823F35C4ULL, 0xEADB48AA445722F1ULL, 0xEAFFBE2A6D5A48EDULL, 0x6AA4D37B5FC110A2ULL, 
            0x3E89DE72896DFEEEULL, 0xB954A0145B3EF865ULL, 0xD997B913E576F92CULL, 0xA582B15D6873ADCAULL, 
            0xA8EC10A0638C096DULL, 0x4EED89A644CD93D4ULL, 0xF0426FDA352836C7ULL, 0xC83FD7C21F0EA3E3ULL, 
            0x552ABFD458663AA6ULL, 0xC8B6097755C597B5ULL, 0x3538C484E7677398ULL, 0x63F8ACD5BCDC85F9ULL
        },
        {
            0x4C3F38E7427FC4ACULL, 0x73E416437F05F23BULL, 0xA499A3E52518F23BULL, 0x4E2962FFC84E119DULL, 
            0x6EFE00414B434FC1ULL, 0x12078EBACE682D55ULL, 0xBF6B37E1A52148EDULL, 0x4E67B0308D313094ULL, 
            0xF038E7B82B7B01EBULL, 0x65B86E1E5E899918ULL, 0x061CEB6825F3B46EULL, 0x29E5740BB61B979CULL, 
            0x8390F9F3365C0665ULL, 0x71288BD129EE4A9AULL, 0x3A5E2920B6D4C2CBULL, 0xDED2B4D7A3A255ABULL, 
            0xC25EE61CBBC44A02ULL, 0xCEAF6188D165D066ULL, 0x942CA0376F99CE99ULL, 0xE4CDF180B55A6F9FULL, 
            0x1EA8A16D1A08803AULL, 0x53A13A9144258B0BULL, 0x5CA4E65418DD7452ULL, 0x137BAB9AD4907943ULL, 
            0xEB5A3D4E781270FBULL, 0x2192806BAD79610EULL, 0xACEC44097501AA4BULL, 0xBCCF485B8E1E4D9EULL, 
            0xFB39349AD59DB6CBULL, 0xDAE877F0EA5D75FCULL, 0x7AF3015EA4F17F64ULL, 0x42BB0E063652013BULL
        }
    },
    {
        {
            0x6F5CD47DA9758583ULL, 0x92E877B9619C7CBAULL, 0xFEB304541BA40C8EULL, 0x6D93BB1535CED673ULL, 
            0xA7B3552C7666F118ULL, 0x88B49975BCBD92D0ULL, 0xEFA68EC01DD16822ULL, 0xEA6ED00BAA6205FEULL, 
            0x5FADF171DA9E6EABULL, 0x6766F2339EB94F15ULL, 0x8F9EDB0BA849A39AULL, 0x81D3DDA1140D767DULL, 
            0xC190905D57CA973FULL, 0xCD1C2235927EDD85ULL, 0xF7DDC087C3AAA3B2ULL, 0x67BB0211C23E3068ULL, 
            0x6C2536DC9A354132ULL, 0x2E8084103BDD4CC4ULL, 0x04578E6C0748AE9AULL, 0x8C0D68C23703BD6EULL, 
            0x56B3DB539469F4F0ULL, 0x8FF401D757BD266CULL, 0x9686D1BE50CAE649ULL, 0x1E400B663D34C7FCULL, 
            0x6229483AFA774C4CULL, 0x21DA2BFDC41968B5ULL, 0x854396309363DC72ULL, 0x2CF2177CEF6DB352ULL, 
            0x8B624BED7A6CAF6CULL, 0x144ACDF31EABAD51ULL, 0x7103B0A8FE941358ULL, 0x81B78D25A106A615ULL
        },
        {
            0x1E70FC5A31387E7EULL, 0xD2576728F3B7367CULL, 0x9C17E55E8C323FE9ULL, 0x70F2349FAB5C85E1ULL, 
            0xF0874FD036890D93ULL, 0x8312383C00E958B0ULL, 0x0C299691BA0CF51EULL, 0x70F6F144CBF170B5ULL, 
            0xF81B269064A0257BULL, 0xDD62866ED00DFCFCULL, 0x6E71D00D922E81FFULL, 0x6F7433EED67091BEULL, 
            0xCD7C60D6E2740096ULL, 0xA6B74DCF8EDD9E53ULL, 0xBCA992C609F686E8ULL, 0x894F5374EC8C94D2ULL, 
            0x0B3AA1BBA166C165ULL, 0x9957670A4BB45AD1ULL, 0xDECAAF7809718F41ULL, 0xC7B3FBB2DE44F6C0ULL, 
            0x73A0587DDF5818FAULL, 0x0DEEB0E22C4C46D2ULL, 0xB6F1A4CC1589596AULL, 0x2A9A1E28846E8C86ULL, 
            0xD1CCAA262E506408ULL, 0x462EAE21421BEDDBULL, 0xEA1838EA8544DE29ULL, 0x539984778CA63FFEULL, 
            0xC6BA863B9C34B7D0ULL, 0xDD4C820A682BE223ULL, 0x2849999D9B36476AULL, 0x5603A3AC9D16CB4FULL
        },
        {
            0x2405A6833EDC1A34ULL, 0xE7440B3C394F1D1FULL, 0xFF24ACC680051722ULL, 0xC3BD46EC2AB0B236ULL, 
            0xCD3B12548EB305CEULL, 0x2A33EB0F6144AC55ULL, 0x22E90AE90554E880ULL, 0x16C5297C421B10FBULL, 
            0x0540C573E00AD591ULL, 0xCE0C9A9F159E3E88ULL, 0x726A012EA23F2562ULL, 0xF9483E7B048B2C6AULL, 
            0x0FB6232BDC3EE13FULL, 0x1D78ADC3BF6A5908ULL, 0x4F33593802352E39ULL, 0x630496E0F7E4AE09ULL, 
            0x751C767580D28FD7ULL, 0xDE72C3B14B28A7D5ULL, 0x1E793F0127C5BDCEULL, 0xD67C620A92DF09A2ULL, 
            0x9E14DA5E6D08D242ULL, 0x599A42CFC0F34058ULL, 0xDC6F071A723BD126ULL, 0xE7E0F7B7810274E4ULL, 
            0x032D2460E4481979ULL, 0xA8FF174404FEA41EULL, 0x91662D85F679D494ULL, 0xCBC45763C8CBEC5EULL, 
            0x068D8D45341E7C30ULL, 0x956DFEBFAA6166FFULL, 0x1A89E15FC69F5D5DULL, 0xD4FA4BFFBCA17825ULL
        },
        {
            0xABE1A104BBA6FF71ULL, 0x95AB6B871AA8D843ULL, 0x6EA3E4A781389B4FULL, 0x799ABCB93905AF4EULL, 
            0xDAC492F1EDA4EABAULL, 0x6EDDAA5EFABF14F6ULL, 0x2CAAA95FDFBA5021ULL, 0xE2F88E6191ED499DULL, 
            0x9638816508D82CF3ULL, 0x54D7E354AB12D694ULL, 0x562F6F6E932BA36BULL, 0x08BC88C369A4B410ULL, 
            0xEC4C2E3F522574FAULL, 0x0C3BE533B8D0E273ULL, 0xCCF5E248F6FA17B0ULL, 0xF322AC7EF39C6D7FULL, 
            0xF933658D200BA3DDULL, 0x595C3DA02B2C0C69ULL, 0x5918F92ED9C92E1BULL, 0xEBCDC5B832789AEAULL, 
            0xA016A69CE6A39B4AULL, 0xC3D87303331E75C9ULL, 0xC67D08B25B4A62E3ULL, 0xA88C5BA0F322D532ULL, 
            0xDE05B50D6F462A98ULL, 0xDF460D00A4E816C6ULL, 0x7623DB0344F83854ULL, 0xA7F4B5D7A8E1AECEULL, 
            0xDD3C1EC2FA9374D5ULL, 0x4280197EE658CEF0ULL, 0xD199804B4154EC41ULL, 0x288CC3F7079DA6B0ULL
        },
        {
            0x60B4E0BB35806468ULL, 0x7D20A29305E88FC0ULL, 0x7A98ABEE5E086701ULL, 0x5067C8487642959AULL, 
            0xE65A18787A848FE8ULL, 0xE99056404EB5F51BULL, 0x374D7863472AC1A2ULL, 0xE615BBA0C784658AULL, 
            0x039D793C2D2AAC90ULL, 0x7484E2084461291FULL, 0xDC0E183DFB6D4D7FULL, 0xB93F265586ABB3E6ULL, 
            0x206E0CC36A106039ULL, 0x05C1C6A38256B406ULL, 0xE1704D9DF8281DA4ULL, 0xC850CE5BF76699ACULL, 
            0xB93CB63122DB02B9ULL, 0x05784F91E9CD6900ULL, 0xEC59B3BD705586AFULL, 0x6570FFA36E25DD2AULL, 
            0xD00160961326CAADULL, 0xD6C9515BB75DB21BULL, 0xFBA540F28D7EACC2ULL, 0xA800052C06CE3298ULL, 
            0x835D9D24BFD38DABULL, 0x6A155D44263D51C4ULL, 0x5003D0E2B1959249ULL, 0x86DEC3E3FC4A94FFULL, 
            0x1215BC96EC3BED5DULL, 0x7600EC5D26C2C49AULL, 0xED08A3AF1B0CB62EULL, 0x1592560B451836AEULL
        },
        {
            0x650A1FF3F1FBEBB1ULL, 0x28433C651133D171ULL, 0x999D989265E497DCULL, 0x91B96DCCAF0AAB59ULL, 
            0x165821AB4C0249A1ULL, 0x850A7462A64D68CAULL, 0x7CE81AE6051C9F68ULL, 0xD66E76F00F384482ULL, 
            0xC90C9277F7B78810ULL, 0xABA64CA20C8D035EULL, 0x244FBB7D95E440FDULL, 0x95C713C1A995099FULL, 
            0x772DAD1612B0A5DEULL, 0x8FB59E004C25F4BDULL, 0xA4A0DA691535F322ULL, 0x522ACC78D7E63E1AULL, 
            0xD1C0E6886DD8905FULL, 0xBD1C9BD1BE358F72ULL, 0x080D6DF9F603441EULL, 0xCB5D4C9D36DC2088ULL, 
            0x7835FBD158AB6EC4ULL, 0x2F90157CFE5FA4B5ULL, 0x6FE9873657AF8EC3ULL, 0x7F106A911624B68CULL, 
            0x5716B56674CE4B1EULL, 0xAD71527AF125C503ULL, 0x50F6F4F70B579FBDULL, 0xC22C4BE79DF03100ULL, 
            0x9C2CAC4AA88C84A6ULL, 0x9BCBEBDCC51A85ACULL, 0x876A0CFFF2067CF1ULL, 0x7EA515CB7E821BF7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseBConstants = {
    0x24E825ECC73DD7CFULL,
    0x01173ED7CB523BAEULL,
    0x15951C7C23CAD889ULL,
    0x24E825ECC73DD7CFULL,
    0x01173ED7CB523BAEULL,
    0x15951C7C23CAD889ULL,
    0x92238D8F393976C9ULL,
    0x88DAC44555AD11A9ULL,
    0x38,
    0x54,
    0xDE,
    0x64,
    0xB9,
    0x95,
    0x2A,
    0x62
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseCSalts = {
    {
        {
            0x081D99176362A917ULL, 0x8E3E299FFA612434ULL, 0xB2977BA375BE2254ULL, 0x313FA05B97CA8580ULL, 
            0x17BB4339932AD435ULL, 0x3CEA51E81E9A2924ULL, 0x2070677116317ED9ULL, 0xD442ACA7C6B459A2ULL, 
            0xE275122EA3C7D0B9ULL, 0xC908817C14890DB4ULL, 0xA329570BFD8170E1ULL, 0xAFA780BF6473858DULL, 
            0xB633B95C00DF2F03ULL, 0xB2937DDDE26B6539ULL, 0xE33BA866413095D6ULL, 0xC1D6CF2FA63806FCULL, 
            0x185372AF48F19D15ULL, 0x07BFD5BEFE932463ULL, 0x2C35CD572073AAF6ULL, 0xE696A5622D0A5081ULL, 
            0xF0CA17CDA32FCE3EULL, 0xA9256260E877FACFULL, 0x5A918C2E15BEB30BULL, 0xF2B0CA4A31237BF9ULL, 
            0x52E5B658901059ACULL, 0x997558496CC7D1ECULL, 0x6686F0FCC556227EULL, 0x842E68E575F74267ULL, 
            0x4E88D29A989DE014ULL, 0x153C31E83F33008DULL, 0xA36C6A8C056001B0ULL, 0x83CD7DE1F7C60AD5ULL
        },
        {
            0xF3029B86649AB4C7ULL, 0x395A7D4F543BA068ULL, 0x40483A7273157EF3ULL, 0xED20FA776AE47F83ULL, 
            0xBBF702C0866502CAULL, 0x6C1A4B1322324FBCULL, 0xC1E91761F1AE7F37ULL, 0x32B8EC9ACF089035ULL, 
            0x6FD449682D27A2B2ULL, 0xB42269FF27FA862AULL, 0x2FD242D4CCD1C87BULL, 0x9607643A2E6E483CULL, 
            0x0293F3ECCB1BDB3CULL, 0x7EE78B05940966DEULL, 0xF26A679B49370428ULL, 0x7CFBFFD814015214ULL, 
            0xC66CFD40B70BA4B8ULL, 0x267105CC46DF5AFBULL, 0x0107BBD302C8DA0BULL, 0x75627F07AA3AF1A1ULL, 
            0x8072739CF0D63D40ULL, 0x6BAF2D310A3C4CFDULL, 0x80E3D902CC2CF9A2ULL, 0x04C746B0AE9F3A77ULL, 
            0x504E8183518C2BFBULL, 0x2F8EBC6400965845ULL, 0xA5827B7C28668ECBULL, 0x57D705BD5D41E5B2ULL, 
            0x2EBED58A182C6A20ULL, 0xAB949742830BD4D3ULL, 0xFA45614E46182EC1ULL, 0xC766795AD42E450FULL
        },
        {
            0xCE8CE563106DE722ULL, 0xB25BB4FC9E7AA98BULL, 0x072CF92ACC64643AULL, 0x94EA1625A4256A30ULL, 
            0x3972AD52461C0BC7ULL, 0x52662D57D825ADB1ULL, 0x5A0A55C30C461AE6ULL, 0x76675A810E7CFE6BULL, 
            0xBB4B62BAAEFBD121ULL, 0xC61B07ED3DEFA05FULL, 0xFD6F6C0383F7FCF0ULL, 0x0315401F86C34EFCULL, 
            0xD67D94CCC7E4B486ULL, 0x9530FE3080445E83ULL, 0x05F4B5F7A751245CULL, 0x04E7E8AE37378238ULL, 
            0x504CCBF8F4257851ULL, 0x4BB8F44BBA15A8C0ULL, 0xBB942D10FE0F5A0DULL, 0x56136CF9D501C2CCULL, 
            0xFA30D93248A361BDULL, 0x4704F7AB2EBB4349ULL, 0x09FF3497F8A611DDULL, 0x002B40D4B50AB519ULL, 
            0x46993713D184CC56ULL, 0xF394B239B11644CFULL, 0x05E5D435C2B266DAULL, 0x3F07DA1F427DFACFULL, 
            0xFF4ED73BE40769ECULL, 0x0C3F86F1F8DA0ED7ULL, 0xAEAF28C852A71662ULL, 0x9AE7354CB7B1C7ACULL
        },
        {
            0xEEA171CCEECFEAE4ULL, 0x111031C7CE742FACULL, 0x3B2607338135B385ULL, 0x5FD288F7F9283188ULL, 
            0xA4194078F537BAEDULL, 0xCE9E7DAC10CA131BULL, 0xAC88A369B7E2231CULL, 0xC00B2707F4703678ULL, 
            0x86569E3563394499ULL, 0x5F0F9FDA34ED7F94ULL, 0xE719052572119DFBULL, 0x138BECE699AF46F7ULL, 
            0xFEB4AB1FE38ED0FFULL, 0x0793DA06C188F276ULL, 0xEAF99862A5655FD4ULL, 0x11D2BBBC6FE2B602ULL, 
            0x3B6AB0BEC74ADB7BULL, 0x778BC467BFE1DC6BULL, 0x1BA8E8304F401AE9ULL, 0xEA2DA4F7D4DCC21AULL, 
            0x8FD46C54F833DFBEULL, 0x0A2BFEC61F6C70B3ULL, 0xF76E1E8C02162D40ULL, 0x40421506396EB1F9ULL, 
            0x969790346D6C9428ULL, 0x1BE19EDA953C5BACULL, 0xA2A6333DFEF4E43EULL, 0x9917C0A761D3AE42ULL, 
            0x83FEE2FE6CA33C8AULL, 0xB1A852402DC018ECULL, 0x7882242D297B526FULL, 0x6715A55C4CC9A97CULL
        },
        {
            0xF026A91BA1B2FE6DULL, 0xD40F314D17C91D1CULL, 0xC7553736AB5FE8D1ULL, 0xC15F9F73F1F8143CULL, 
            0x66F492EB58DA1547ULL, 0xE4A1A7984CF6127DULL, 0x73404C9F0923FF00ULL, 0x2E51FB5577D6147FULL, 
            0x2396F0A65B8646E5ULL, 0xE943404CD4BFCF6FULL, 0x968BB23134395400ULL, 0x151DF10F346B0375ULL, 
            0x1B62EE7A4E546CD9ULL, 0xDFB886DAF7A6AB3DULL, 0x74069DDA1111B639ULL, 0x28190A39E5DF05E9ULL, 
            0x477ED068920A3685ULL, 0x287C2B14EC0844EDULL, 0x853B0E47B5AE1549ULL, 0xF65F08CB5DF57F15ULL, 
            0xF551E44EE28F330EULL, 0xCB2B0CED0E940F4CULL, 0x21EDEF85BA549694ULL, 0x7D592E3A0A22E267ULL, 
            0x9587C83EBA73EC28ULL, 0x1ECFFC67CEE6FB14ULL, 0x9B9E63507DEABE30ULL, 0xA3FDB1D58522CBE6ULL, 
            0x9C921CFE209CFA56ULL, 0x4BF75948ED788C64ULL, 0x4741737E2CD05254ULL, 0xABB02C982D67ADB2ULL
        },
        {
            0x48C16AE23A9A0BB2ULL, 0xD3990C8C36665407ULL, 0x8A26C21CEB7A1A92ULL, 0xFB9FDDE1ADD72F9DULL, 
            0x0E9D4824EE5D6EEBULL, 0xEC34D7BA17C65609ULL, 0x569C6FE876042CEEULL, 0xA400C8627C4C5CB3ULL, 
            0x0752729C1EFBE423ULL, 0x9D36E90426AA88C4ULL, 0xE859EC98C5D3B952ULL, 0x952611157A1B512CULL, 
            0x8016FDBF29FF2BB0ULL, 0x7B7DA5DE3FE92DE5ULL, 0xF0E6269054B8242BULL, 0x7DFF4B5474660908ULL, 
            0x53885D5DD7887957ULL, 0xC971DD7F460258ACULL, 0xDA2FD7EFCED9F94FULL, 0x861E07D686FE9E3FULL, 
            0x0595A23CD4C2E757ULL, 0x7690769EBB0404AFULL, 0x95A9AF6B817FD771ULL, 0x7F5D0683CC2DACF2ULL, 
            0xA008DABEA858FBA5ULL, 0xDEC440DDA7C8ED72ULL, 0xB87BB3E742BCD681ULL, 0x7ABA7F9C088B2E07ULL, 
            0xD130DE4F3BC14A65ULL, 0x535DD174017155B8ULL, 0xCAC5651E816E6263ULL, 0x87CF51FF81FCCB6BULL
        }
    },
    {
        {
            0xC167A9FB37FF15A5ULL, 0x5A3309594BCE14BBULL, 0xB63F74C885845387ULL, 0x86DD50AB36A5C753ULL, 
            0x68D9EA60B8807568ULL, 0x4FC15799F7490B4FULL, 0xBEB2CCA20DE8F2B8ULL, 0xC584A4238870DC98ULL, 
            0x72324D899E8E3B47ULL, 0xCC6FE8A286D611A6ULL, 0x1B2EB9D16808A332ULL, 0xCCB288D2CC512E09ULL, 
            0x84A9657C10262EA8ULL, 0xAA1CC9B07A848DD7ULL, 0x6E0F56095EEE9410ULL, 0x7D2EEE52E699A86EULL, 
            0xB9BE0F11EF19592AULL, 0x6068AEA571288FA0ULL, 0xDE450EC4676C9D2BULL, 0x572C803E894D91A2ULL, 
            0x41E00D88AC36C5CAULL, 0xCD7C98F767D8A0C8ULL, 0x1937BDD73C57A936ULL, 0x40384EFD65D642BDULL, 
            0xBC9F8686D1DA3000ULL, 0xC1531E29302C1827ULL, 0x6FB19F15EC29497FULL, 0xC24C16A038D2AB39ULL, 
            0x169E569C9E4A00EAULL, 0xB62149CB2D78AB90ULL, 0xF89AB22FB349AD4DULL, 0x5DA4AD07977D460BULL
        },
        {
            0xEB5746D5E3FE9BBEULL, 0x89C463338340A1A9ULL, 0x58762C39FDE68DB8ULL, 0x5F26D606C3CF630DULL, 
            0xD66343918AAB64C9ULL, 0x7E50345FD23C56A8ULL, 0xBFC4584EDE67FFB9ULL, 0x2590B9B4EE6D21FFULL, 
            0xCED068A7A439EB4FULL, 0xC99A40686BED7059ULL, 0xA5AC997E09BAAB4AULL, 0x5C87A8510CDF053EULL, 
            0x6CE057A06DFB1D66ULL, 0x943A477E094F8ED2ULL, 0x31194AB5E2F1645CULL, 0x217302DD09E0326FULL, 
            0x12A2CB9C4B660D38ULL, 0xE983E6C96F788921ULL, 0xB7138DC2AA54583EULL, 0x443BEAD66082B132ULL, 
            0x4BF4B6306868BC7FULL, 0x328027782D35834BULL, 0x92B19553D8231574ULL, 0x02A6823E8977B19BULL, 
            0x7350AAE0FF32693CULL, 0x69298304BC70A08BULL, 0x0AA527C469005C0CULL, 0xEF0743A774052741ULL, 
            0x73CD30B865265049ULL, 0x4B042B6B9BE87394ULL, 0xDDA7A0E142B76919ULL, 0x9086C59620115A7FULL
        },
        {
            0x24D989BE9A85CAC7ULL, 0x472ADDC52736EC07ULL, 0x5DD65474F20527D0ULL, 0xF7353E42E2F9E083ULL, 
            0xBFC47BF2B84B0B98ULL, 0x937D626FADF89B62ULL, 0xAD7E5FF22DFABC26ULL, 0x1EE833E381542DAEULL, 
            0x24580C3DFA8C9BDAULL, 0x70E2506BE9EA246BULL, 0xF07E057BF06BC960ULL, 0x6DAD4E74313BE12EULL, 
            0x2FFD9AFFB122D656ULL, 0xD1D93F6BEF46F77DULL, 0xA02893EDD18E25E8ULL, 0x26AF66B8A4EE589AULL, 
            0x7C2ED6423CD00A45ULL, 0x5E01E42631B7A12CULL, 0x68742D978917062BULL, 0xE7E91A920180AF74ULL, 
            0x8A5AE07E7E416728ULL, 0x3D98BFC31A665B3EULL, 0x0BA61DFCEE8C0044ULL, 0x53964EE3B814D05AULL, 
            0x40F1C761CE851771ULL, 0xC00F90C933EF1E26ULL, 0x5A49C56A04654CBBULL, 0xD6AB5450DF821B9EULL, 
            0x291A485C0521C8A5ULL, 0x7F543391AD3E0D97ULL, 0xC9C090E7D4A46CB2ULL, 0x71A4A67E231E842DULL
        },
        {
            0x21E7040FE6B20B3BULL, 0x8CD9DE97B315D955ULL, 0x9795C066D9663153ULL, 0x04B971E1160740BDULL, 
            0x511BF3DE73D94B4CULL, 0x5AF0CE6A33E28AF1ULL, 0x90C22D87A08C659FULL, 0xF43672F889055AFCULL, 
            0x6AB0134C793F5517ULL, 0x93DD7843AB3F11DDULL, 0xF1519F447BF608C0ULL, 0xF1D28DBDE8DD62F5ULL, 
            0xBFF257A1BCDF5A98ULL, 0x7905F385F8230E10ULL, 0x2F197764995D220AULL, 0x19BE3BFD503D5EA2ULL, 
            0x1D0908EE148D8AAEULL, 0x326BB11EC6091971ULL, 0x9B859795EDE6D8C3ULL, 0x3DC155CA4BBFF5B1ULL, 
            0x0E73E15413A42C6DULL, 0xFEEC8AF497D81F0EULL, 0x3115F3DA3FB110B5ULL, 0x7EE877E14DAEAD10ULL, 
            0xC8EEC8C31CFB4AE2ULL, 0xF43EBE42358E1674ULL, 0x4F1368D32B1DF8CBULL, 0x508D5558589A0407ULL, 
            0x414B13C4D0255A67ULL, 0x0BD1EEACC8B0A4EEULL, 0xFA47E8B86A3EA6D6ULL, 0xB71505E7CBE4F548ULL
        },
        {
            0x0AE96C13F4BC259BULL, 0x194694CD7C39CA1AULL, 0x19BFB0F2AE8A410DULL, 0x414EBD5342927CD9ULL, 
            0x6342793063EF0AC4ULL, 0x6FD6E375E0A2D005ULL, 0xE3121E52A8B3ABA8ULL, 0xE54CB88115D0CCB5ULL, 
            0x707125C89D365936ULL, 0x6B74E88801FA0E45ULL, 0x7AA8B4B4E9D93905ULL, 0xDBF801591755E622ULL, 
            0x57973F1B134B71D4ULL, 0x0CE6ECE9C3E0A6A9ULL, 0xDB701C03FF371941ULL, 0xAEC5C7E697C4D40EULL, 
            0x0A6DD68E07B418FBULL, 0xA6C2C2E51D773EFCULL, 0xBAFED6292972C8DCULL, 0xAF2C8D8867456A6DULL, 
            0x14766D61DC9A1325ULL, 0x8307E6AE6E59F37DULL, 0xF4A357007AFE64B9ULL, 0x3DD92B0D01D64A4DULL, 
            0x9CD599F08D0EED51ULL, 0x11220C8A942E6699ULL, 0x7B308B8A7C3BD504ULL, 0xA8E4C02AEB903774ULL, 
            0xD11FA80710283610ULL, 0xD5B34212AD22968CULL, 0xF4034B5DCA18D400ULL, 0x284E990B72FFB144ULL
        },
        {
            0x2CFE39DD48B1E4ABULL, 0xD5E46BCB9ABA354FULL, 0xC36378F1709B84E8ULL, 0xABE94EF94C4F573DULL, 
            0x1100026103ECF01BULL, 0xFD1162902D8F0AA8ULL, 0xB9DB1879C4DBA335ULL, 0xD38954CEFA0615B0ULL, 
            0x249E7DF6061D9720ULL, 0x5F3D5B7166429819ULL, 0xB6EB58B9C7B5E8D5ULL, 0xFEB03620145BEB35ULL, 
            0xD0CD0CD93B8C1B35ULL, 0x0418215FB9F967D7ULL, 0xE0A01A032DE1783EULL, 0x16A5EB02881057B3ULL, 
            0xDDD46282BCB38CE7ULL, 0xF4382AC9B2D3F1ADULL, 0x9343960F6E2F9E82ULL, 0xA4A9F2A3CA36036FULL, 
            0x7745E288A84DE4D9ULL, 0xC77D047150FF1158ULL, 0x4CE457DADD4E1385ULL, 0x2A25312992EACA5BULL, 
            0x59ABD33F9ADBC9D8ULL, 0xDC99A6C19DE00051ULL, 0x5C52A0AD8137F1B1ULL, 0x8CA90E4558B5B320ULL, 
            0xC013A565DE824FD8ULL, 0x6D7592B8C91E549BULL, 0xF7059D51D503A3B9ULL, 0xFC3740EDE6D5BFA8ULL
        }
    },
    {
        {
            0x12B0A60836ED9D03ULL, 0xB15B879FEE911E6CULL, 0x05445D19A12D0925ULL, 0x113F9ED46557EE85ULL, 
            0x3C667D402F223D92ULL, 0xF42E4DAAF9F85309ULL, 0x9A41E4B83D330F3DULL, 0x878B328446122E9AULL, 
            0x60563E56601D5522ULL, 0xD798E4D4E50C0E66ULL, 0x8A29F6BDDBBC31ACULL, 0x59764AA187813B0EULL, 
            0xE9648B6F2B77711DULL, 0x065F84BD313A47B6ULL, 0xE29247E98A7B0D07ULL, 0xF11648833A461624ULL, 
            0xD65DA171460353CEULL, 0x61BE21A4B469E181ULL, 0x0A99ACD165EB95B0ULL, 0xCD094B41410A38C2ULL, 
            0xAF3BFB3994112B86ULL, 0x06C42BAD80EA115FULL, 0xA01A02E7509CDA1EULL, 0x32AB03220773934BULL, 
            0x022ADDC584E5637CULL, 0xD9B936C3887FFE7DULL, 0x7EBD59A7CDD28E6BULL, 0xCE5C8A0CA55F1682ULL, 
            0x5BACE8A8FDE29C6DULL, 0xD9C5389DF2B53297ULL, 0x7A5C986C00343643ULL, 0x5778A4966ADDF8F0ULL
        },
        {
            0xA76BAFEEBC703801ULL, 0x076EFDDC74B76205ULL, 0x4C215640E81BB5B0ULL, 0x248362645C7D603CULL, 
            0x92BEFCE67F70EECBULL, 0x0DE898492BC2A90FULL, 0xA860755A0945A475ULL, 0x9D83464AD884DA4EULL, 
            0xD2DF1A832D5D6F83ULL, 0x5ACC2229E50C1CEAULL, 0xAFE09EE36360F238ULL, 0x655E339ACBD23DB2ULL, 
            0xC2CA46D3E11437EDULL, 0x0AD8FDD5B7B1C1D1ULL, 0x4130CD654DA6A134ULL, 0x2B5081B583C96F31ULL, 
            0xED06CA9CE647F24CULL, 0xBB035871823E88B6ULL, 0x0C0BC810E676530AULL, 0x9B1BAA0767FC49EFULL, 
            0x2256ADEBF8A28175ULL, 0x9B8FA6975F09DD9DULL, 0xDA7ED63CA8AD8E99ULL, 0x3C4547209AEA1969ULL, 
            0x2AB1E4E1D844D9FAULL, 0x48EFCFEBDB5E6BB3ULL, 0x3AC4B5EDC6225B29ULL, 0xE46D3BEA0D906847ULL, 
            0x2781D862A122FC5EULL, 0x2F97F2A52EC1D925ULL, 0x9BA1C009AC55A541ULL, 0x7A48DD65A62F90F2ULL
        },
        {
            0x60408CDA001DA014ULL, 0xA1A9F8BAD6357BCEULL, 0xDAD30AFA99BB9E3EULL, 0x908132930FB17640ULL, 
            0xA9F3E04FCD879CA9ULL, 0x590B65BCC6E79451ULL, 0x0F98291DCDB28BD9ULL, 0xDCA77D3B84D93708ULL, 
            0xE80E1569570F80E8ULL, 0x94BF27ED274E62CDULL, 0xB0AD7E9FC16E1AE8ULL, 0xD67FA85810C1EA93ULL, 
            0xA7CCC7725A96E8E4ULL, 0x0B7B381D0F9B6B6BULL, 0x37B075AA14621D44ULL, 0xD989DF6075BF576CULL, 
            0xBC4AD3BC27DE4BC3ULL, 0x614B151A1D1E0630ULL, 0x048E39ED8E154D39ULL, 0xB8A5253EEFE1DD9CULL, 
            0xBE4F680A821DB90EULL, 0x1A0CA28A15C41FB5ULL, 0x3ECF933E0F89DF0EULL, 0xB0581205497F7AC5ULL, 
            0x2F423D07A0F50FF4ULL, 0x1DAAA722D93A9680ULL, 0x8D2988C7825497CCULL, 0x435FDEF1DE285F65ULL, 
            0xBB0EA42E5EE30C93ULL, 0x31B15B5C20D2E4D4ULL, 0x23096C76C777ACD2ULL, 0xBF4B6D6C63A28E17ULL
        },
        {
            0x83B87114742BA5E7ULL, 0x684AE24365551B9BULL, 0xF4D87390D8C35779ULL, 0x63A27201859C7ECDULL, 
            0x603F653DC5EBE7DFULL, 0x83FB4CF80DB19804ULL, 0x56C84B4ED4790A07ULL, 0x68F7EE4CF65C0191ULL, 
            0x0968F58904C766FFULL, 0x1B4E576566D88502ULL, 0x16815347D3679FE3ULL, 0xDF6AC4FB76352F7EULL, 
            0xFD9B945C5D7DFFB8ULL, 0x7F10536313F3E8F6ULL, 0x61B6ED9CB71BB31FULL, 0xB2499B57823DE6E3ULL, 
            0x3E9B504EA6663DFDULL, 0x6C8F1117744DBE16ULL, 0xEA1FB37F56C9128BULL, 0x77BA4761C68C0ACAULL, 
            0x5830503073E4FBB4ULL, 0xA7F155D8C2B3F2D4ULL, 0xD4952A81E437CEADULL, 0x93C44CC31F3436DAULL, 
            0xDDFC20A8E679C108ULL, 0xE378BC4CAAAFE09EULL, 0xA2ACF29B9EB25F68ULL, 0xB0EC18B3F673F567ULL, 
            0x81D4EF6830DA81D7ULL, 0x48275169D4F53E4CULL, 0x8D28D7394BFCFF6BULL, 0x806CEB44D9C53060ULL
        },
        {
            0xBAA36877EF5D4F73ULL, 0x345FFF6412B3F48DULL, 0xFC6E81017DDEA9B9ULL, 0x3AEABDA49D397CB7ULL, 
            0x9DCEB262C51F606FULL, 0x212C51431DDB3E73ULL, 0x8DAB36B81C768C6DULL, 0xDD480C9B3A242263ULL, 
            0x53123416F8E5A55DULL, 0xC13B45656825E52AULL, 0x22E6E19197FD1EE6ULL, 0xF588F48DBE35D2ADULL, 
            0xE2196C48D8140440ULL, 0x735B95256BCB4686ULL, 0x030E943DF41BACFEULL, 0x639D0D958040692DULL, 
            0x238DE514AB94C9BAULL, 0xD007DB1A1106FC8DULL, 0xF15FF53DFF46F219ULL, 0x9DF388CB92DBE625ULL, 
            0x735AB87DC47B3739ULL, 0xA23A2CD19240E01AULL, 0x6B67F285CC3FA84EULL, 0x395E635283D5EEE1ULL, 
            0x38B9AD0E7A37EC91ULL, 0xF0FE37F534859DC9ULL, 0x5A2DFDF8EA4B4A39ULL, 0xA2BD98DD6AE24CCDULL, 
            0x2590C4E99944DC13ULL, 0x2D13559EDD7B025AULL, 0x282CF7C47F32A9E8ULL, 0x81F840B6AE45FF1AULL
        },
        {
            0x4572FB6E111FC8FEULL, 0xFAFC8D73BC46D2DEULL, 0x698CF499BCC9D528ULL, 0xB5E66FA103FCB2ECULL, 
            0xF024B771CC3B8FC1ULL, 0xF7C64B94C167F221ULL, 0xAB427385A99EEF6DULL, 0xE7B606B69589701FULL, 
            0x6C7AC9C6D7E95A18ULL, 0x260EF3DD5FD3DD6EULL, 0x228DF494A7CF22F2ULL, 0xCCF9235321C4DEECULL, 
            0x4F06C0BD6FA9DD17ULL, 0xB91E1112F335C540ULL, 0x292C2C4B21B6CE4DULL, 0xE59F14CD6EBCF71DULL, 
            0x2B06A9E4940E64E7ULL, 0xABA15B5157B231BDULL, 0x33493623AFE3ECFEULL, 0x25D0ECEFA68F92F1ULL, 
            0x482B4F7432E2771DULL, 0xD24797C4EBE77A6AULL, 0xC5FE3668A9902918ULL, 0xB53643BDEE4D22E8ULL, 
            0x491BF20CABF2D15FULL, 0x26C40336D4A7346AULL, 0xF2CE43428A6DD2A9ULL, 0x0D5F27D4988A8387ULL, 
            0x5BA1821017CB9336ULL, 0x4B09A88EBEF03133ULL, 0xA272D88BCE07FA97ULL, 0x205F2BBEF99AC508ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseCConstants = {
    0x1A049ED0F6E73471ULL,
    0x18DC8FA99A413DACULL,
    0x1A93BC502A224CF1ULL,
    0x1A049ED0F6E73471ULL,
    0x18DC8FA99A413DACULL,
    0x1A93BC502A224CF1ULL,
    0x8C385961DD0D12F1ULL,
    0xAEBB825863E97D55ULL,
    0x62,
    0x8D,
    0x34,
    0xD3,
    0x08,
    0x80,
    0xA6,
    0x2F
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseDSalts = {
    {
        {
            0x3A863412C444C07FULL, 0xDD929B3B582559E8ULL, 0x9101254AB4C381D5ULL, 0xDA9C76972E79B295ULL, 
            0x829CE673F9CE68D9ULL, 0x790DA5BA09DAE43BULL, 0xC0E02656419540ABULL, 0x09A467073B0465FBULL, 
            0x313A630A576153ACULL, 0xA59D6A98FAAA8C7BULL, 0x656B382F8A17D676ULL, 0xC5A7737C02122630ULL, 
            0x10FD871545DB19BDULL, 0x724EF1A18A067DE7ULL, 0x3A2149CCB7C5509FULL, 0xF8FB9F6AA6ECA520ULL, 
            0x9A19FF25F4B5C3EFULL, 0x0C6B4E865195C204ULL, 0x276C2A13C89ABAA6ULL, 0x4872DE4D8EA1D5A0ULL, 
            0x23897FD3701A4E04ULL, 0x15EDFB4AF2A51B36ULL, 0xC80C110E43238CB2ULL, 0x0863C8719226AD22ULL, 
            0xEF4A5B35099F5A0AULL, 0x9B948488BDA6EB4CULL, 0x0889FF209D348C00ULL, 0x9626BF77183539A1ULL, 
            0x8AB5FE99B7ECC5FEULL, 0xFE31B048DEA0A652ULL, 0xAA93FE4E6549219EULL, 0xB3FDCF578FF2F50EULL
        },
        {
            0x11FBBB4A36F82380ULL, 0x9CA432BD5B097B81ULL, 0xB17F5371C75ACD2FULL, 0x7C605BD13E1345CFULL, 
            0xDEF732DA9689CC3AULL, 0xC9A441AE5E7E8317ULL, 0xE0E226DBAAEE6387ULL, 0x994ACF5137029D1AULL, 
            0x290536956F02E294ULL, 0x247CDABF0C547BA8ULL, 0x9F77131120BC9E30ULL, 0xA1CAE12E3554E52CULL, 
            0x8545524635F8D0C7ULL, 0x03881021B3042A2DULL, 0xF9B891EC50589885ULL, 0x78EC146421A9F281ULL, 
            0x270A7DEDB09F63B6ULL, 0xCD80234A611DDC41ULL, 0x1980BA9A937B49E7ULL, 0x92CD3B0D119BFD9EULL, 
            0xD6FD79D01CD560BEULL, 0xD44D6BB733569458ULL, 0x3F5FBB7651C3C5B8ULL, 0x691B1C975234C2CAULL, 
            0x9E21CE055A23E081ULL, 0xD4BBEA491641F3D1ULL, 0x060466D86AC845CFULL, 0x199E5DB0F6823C36ULL, 
            0x3EF3FCBB35C3C84EULL, 0x7C53BC607B6D6561ULL, 0x166288F806633A54ULL, 0x035755A9988DCAA4ULL
        },
        {
            0x16B6E39684B57C87ULL, 0x35939B20131CF3FDULL, 0x4DFFD7BA592F4E27ULL, 0xF8373AF8DF93017CULL, 
            0x158173737BBDBAD8ULL, 0x81A272F1CA56F983ULL, 0x326C76111BA66C45ULL, 0x94995E7EC2054C00ULL, 
            0x03BC5F243A5947DFULL, 0x81B4E86776B59F64ULL, 0xCC117790AF51468AULL, 0xBE7653EA34F1DAC2ULL, 
            0x5BEAD08A1F83FF34ULL, 0xBDB59B536529A1DBULL, 0x539B78A2307D0249ULL, 0x186E65D610DDA64DULL, 
            0xF7752351E63E9383ULL, 0x97CC323102EA8BB1ULL, 0x8744E8597F56E58FULL, 0xD37458E68D398BFBULL, 
            0x78AF6FA4C4A99A24ULL, 0xD2FFA9D2BFB9D1B4ULL, 0x733A6150099BD470ULL, 0x6BD7765BEFBAAA59ULL, 
            0x50CF900718E59565ULL, 0x4EE11CB821749489ULL, 0x8CE0D6224A4B841BULL, 0x78EA75F28CBE2849ULL, 
            0x61BDC8CEF811AA2DULL, 0xAFDCED7610FCB50DULL, 0xABC94BDFB5BDF1B3ULL, 0x6B068F6C04883F3EULL
        },
        {
            0x2FA6DA5B5CA82948ULL, 0x900C00DBB6E67FF8ULL, 0x2DBB624AA3DB50C6ULL, 0x90FF6BB2E6A902C2ULL, 
            0xD32EB9D2DA6A42B7ULL, 0x06E0F9943250741AULL, 0x76F5D9230267092EULL, 0x1E600D7DFB796CF2ULL, 
            0xE35D8991536F5D07ULL, 0x97EA83F5648CB437ULL, 0x0A845A665221BA0DULL, 0xE3EC02A223C0DE54ULL, 
            0xF42FEFB1CE56E882ULL, 0xD804EA1B4D8A2C6FULL, 0x72F27CFDA9D6B8B6ULL, 0xA83835F07616D54FULL, 
            0x6D3F58228A3C857AULL, 0x8B1DEA08FCFE8676ULL, 0x53DCCD8A444CACD4ULL, 0x32F552F2A85940E5ULL, 
            0x5062078D78729D1CULL, 0xEBE6BB56BDBE6AA3ULL, 0x355BA586E3F79768ULL, 0xBBCE46A796D092EBULL, 
            0xD2287E331D3C5821ULL, 0xB98F3C12A4DEBA68ULL, 0xF0A6AF593A821729ULL, 0x68DD9B34EE1077F6ULL, 
            0x6CEB875262B17840ULL, 0x3A6D0BEE89E93859ULL, 0x7F4340B25CA3C416ULL, 0xAA42F4B00B1DFA0AULL
        },
        {
            0x27CF4D365EF5CF1BULL, 0x4A32C421C066C0E5ULL, 0xC6B47B6C7FA9F9D8ULL, 0xE9FA3F7A057FB2D1ULL, 
            0xDBA215E1187F8599ULL, 0xB86337B2ED5EE72BULL, 0x00C72D1027F7ACC2ULL, 0xE6757BCC89A56FE1ULL, 
            0x9D6FE013669218CAULL, 0x071C3D8E555307C9ULL, 0xE82307827A20EE4AULL, 0xFB16E638E147AD33ULL, 
            0x193D6760AA079EC4ULL, 0xC4851A2940A6E7CFULL, 0x7B87E6981D5EA964ULL, 0xB4C586828D40B137ULL, 
            0x7AE97B145B071AF1ULL, 0x88371146E6AB0E22ULL, 0xCB98DC2195289914ULL, 0x024BA24148C61B6CULL, 
            0x94651FBACBA2E8D3ULL, 0x2793BF93F136473CULL, 0x96BEB36434B6F599ULL, 0x8A714C9B837D9392ULL, 
            0xA46487C03A2C9D41ULL, 0x884175003AE153CAULL, 0xFCC9ADE69F18A9A3ULL, 0x25D3651A8B295E89ULL, 
            0xF7246A86E2FB53B0ULL, 0xBB02F871DDEFB964ULL, 0x9AC748D4C88E6A59ULL, 0xD381567FAE92484CULL
        },
        {
            0x84DA070612603937ULL, 0x04AE7CEEC0814CFFULL, 0x5DC766695855896BULL, 0xDBC7E4891166D6B4ULL, 
            0xC234F2C26680BB31ULL, 0xB1E65578C49E2F73ULL, 0xB73528C8CB8EC4BBULL, 0x39DF727FAF2C63BCULL, 
            0xDE941CC675EB5F1DULL, 0x3D6436B52DBB0B14ULL, 0x79B3A724A2341537ULL, 0x1E9E5F0DF52FA020ULL, 
            0x88FD41A6CB99B803ULL, 0x49E26EED671C12BCULL, 0xDB75303109AF1D94ULL, 0x0C3B419B1B514113ULL, 
            0xF299042F99ECF276ULL, 0x21047D565CAF59ECULL, 0x57380EAFFE8637A1ULL, 0xE4A1B5110CD1BED7ULL, 
            0x698885DC1EFC9609ULL, 0x5258988F224F3ECFULL, 0x248CACA700705BB1ULL, 0x607FDD0BF25FA8B4ULL, 
            0x703ECB9E893C6688ULL, 0x3F9974E4E940B4A7ULL, 0x721A499D1B61C542ULL, 0x7C0D06B448865B26ULL, 
            0xEF84782129C47B23ULL, 0x8F9947F86529D49CULL, 0x382D538DE21EDEDBULL, 0x0AFED7E93105771CULL
        }
    },
    {
        {
            0xDA737B30F2DB268CULL, 0x0E7AD70CF4DD85C9ULL, 0x9B1C9FA84E170533ULL, 0xBC88A022B0FD79E5ULL, 
            0x1DE5844666BEF462ULL, 0xCF12C8FC687F346FULL, 0x7AA53B8E2D9F8D03ULL, 0xD249F9BC24F23838ULL, 
            0x7695EB32B881BFC9ULL, 0x067617415C4BAF8FULL, 0x4B38F1478AB3FA0CULL, 0xD9E7C79022593701ULL, 
            0x0DDB29B1041FC6A6ULL, 0x97F866D11B51D73AULL, 0xFACDF6BB87C4E673ULL, 0x5348B1D0EFB02D92ULL, 
            0xB69B4453B28D46A8ULL, 0xA8C97308CD0B95F2ULL, 0x85C4C5D6FEA7E0CEULL, 0x83BC93CB92AB83E3ULL, 
            0xD83F13E65B1CA1DEULL, 0x2A11BF9E7E283BF2ULL, 0x237834A12F693435ULL, 0x8F1FEBCE09374D1EULL, 
            0x4F4E5BC2BACE7403ULL, 0x8B374D0652829E84ULL, 0xE913043009461F32ULL, 0x2C1F957B1A4FB393ULL, 
            0x0A9DAB9AFCFD2122ULL, 0xCC3556E6929F7EE2ULL, 0x6E004E460308B792ULL, 0x9027830859E541BDULL
        },
        {
            0x82F367CBC3062914ULL, 0x5AB5A4009DCF626BULL, 0x4777027F98178D8CULL, 0x9390E315923EA669ULL, 
            0xABE024FB0C5A1E2AULL, 0x4378594B90969CEAULL, 0x397ADEB72740F8A4ULL, 0x3333D9916861CD6FULL, 
            0xA3BEEC6C4F20552FULL, 0x980E37032748A639ULL, 0x283DEC0384513853ULL, 0xAA530C24AD2ABC2AULL, 
            0xC75386B66B1F4166ULL, 0x37170B03E0436B6DULL, 0x7273BA7CCC9461E8ULL, 0xA26F681724695B49ULL, 
            0x766D005AC5486838ULL, 0xECE042AE17710A37ULL, 0xF96D5EA0C4746931ULL, 0x82D5540D1299F49EULL, 
            0xF0639859FD837649ULL, 0x5F10FABFAEF4369DULL, 0xD5465B32718FB4FFULL, 0x70CC4320498139D6ULL, 
            0x2D42804AEBF29BA1ULL, 0x1A40237B6F1AD4CAULL, 0x83C6115FA8069C15ULL, 0xEE40563ED5980644ULL, 
            0x8518019D56F5F9C4ULL, 0xD0F953952E3B8BE5ULL, 0x59546E1C44433DC7ULL, 0xBCC09BD5C1B9C2AEULL
        },
        {
            0x8695FEF5B67230DBULL, 0x5317C49B11B99078ULL, 0x30F12DAD5D1EB6BCULL, 0x717B5DEC0E632FEAULL, 
            0xA2BF812B76B0CA32ULL, 0x241EECCF7F712DF7ULL, 0xD9613A7E09D1CA22ULL, 0xD0A18CCBB164B1B7ULL, 
            0xBED036A6FF4A6F8CULL, 0xAE5BCC3262ECA178ULL, 0x4805DE3A8E0690E9ULL, 0x29AC21E65D3CA167ULL, 
            0xF969B1564E537619ULL, 0x20532543BD5E50FDULL, 0xEA8FCC1A68FCBEE6ULL, 0x54DD3113DA5FA7A3ULL, 
            0x3B579972CC3F25C9ULL, 0xBCC7824B1D94AFDEULL, 0x76CD582512672DFEULL, 0x9A9BE15A6B0CF4E6ULL, 
            0x9A1912EB6C70CEDFULL, 0xA096FC3281659F03ULL, 0x7176A63EDCF3D071ULL, 0x91DEC0803F7AFF2EULL, 
            0xC5AF77A298670631ULL, 0x76661EE3D644CEDBULL, 0xF5ACC79A57857FE6ULL, 0xAD400F9FB61CEEF9ULL, 
            0x1042EBFD9ED35191ULL, 0x22E073692968DA9BULL, 0xB318B8CF22A652DBULL, 0x2969CF28675F7D98ULL
        },
        {
            0xB76852D85C2D0F83ULL, 0x6BFED817AA0240D2ULL, 0x17DA288C07175FA8ULL, 0x0700E26EE5C8BFE8ULL, 
            0xA45945595B25DD9DULL, 0x762CD0B9364F4786ULL, 0xE442BC26AB38780CULL, 0x152DFEDCADA4B376ULL, 
            0x3B4F0BDBBB53F185ULL, 0x456D3AF79A9A8F42ULL, 0x35B7E5994C6C4348ULL, 0x4F2296ADE5021963ULL, 
            0xFF088C74AFC0FAA1ULL, 0xA5F5151D01567A9BULL, 0x20E41EE27E42A771ULL, 0x8F8D6B6D69F615B8ULL, 
            0x376900803D978141ULL, 0x30B8D32A7DDB1C45ULL, 0x9494D755ADDCB4CFULL, 0x160CBCE835BB6328ULL, 
            0x24D726D64E22FEE3ULL, 0xD9A43B409A520493ULL, 0x185317E0ED73D1F1ULL, 0xEA2F90C1EFE3A204ULL, 
            0x41F356B9117CBA34ULL, 0x58C56B877A35A41EULL, 0xAF46AA25F009564AULL, 0xAAE3CC305D3163A0ULL, 
            0xD9EB359BE590C7DEULL, 0x6DEC2CBC2E5B6B14ULL, 0xF8BA9FDED1CBD1F9ULL, 0xFA2A268B85B61C10ULL
        },
        {
            0x011D754687124787ULL, 0x728EC9149FD41211ULL, 0x2618B41D5B4C1215ULL, 0xAA275A6FBE7615AEULL, 
            0xDAD4716BE6592FDDULL, 0x8D92EEBEADA0A44FULL, 0x93370739FBE793A3ULL, 0x1CA1684DE0701F50ULL, 
            0x75567C927770F564ULL, 0x23BADF4030B5AFE6ULL, 0x340B4E1E1E233806ULL, 0xF36F984EC322295EULL, 
            0xDC13D7DC3FCA3885ULL, 0xB0E7813EE17CB72BULL, 0x0D14238B4C0104C5ULL, 0x2A542B15577C37D8ULL, 
            0x070ABFDD3A5DE140ULL, 0x1C93C12A3CAC166EULL, 0x19214545140DB71EULL, 0x7021179BBA860F56ULL, 
            0xB3ECB4BC40F67137ULL, 0xDB4FF6F3FCE31EDBULL, 0xD4E53344A8A5A7F8ULL, 0x76F1C44D28C4F34AULL, 
            0x9C3A9AAF67C99D23ULL, 0x5A79E61E4B4208EDULL, 0xE8754182D84F80EFULL, 0x3B3B47A9F3ECADD0ULL, 
            0xA83C679B3A0CD543ULL, 0x66663E70B0121BC9ULL, 0xD738C6DFD5197D7CULL, 0xC315CAE69EA2193CULL
        },
        {
            0xD3CB8168B5164E01ULL, 0x09FCD801B7F891D4ULL, 0x05C106100C65C043ULL, 0x76ABF4A521F5F44FULL, 
            0x487037028E55EB6AULL, 0x17A7D7E8FB07B1AEULL, 0xD6FF9F3BE877A50CULL, 0x71B01D82BB309E50ULL, 
            0xFC0211B012F78411ULL, 0x84BAD4B13D09AE3BULL, 0xCB09E180FBA19CC5ULL, 0x45E71123BF3F366FULL, 
            0x61C926A94A317CE4ULL, 0x97F405F66301A948ULL, 0xBBAFE23896A125F3ULL, 0xFA2E589EFD332FAFULL, 
            0x1BE5259DB02D07B7ULL, 0x0AD05262372D9005ULL, 0x594964F91DEC6706ULL, 0x4F54BA2329306D93ULL, 
            0x07F3A217BF60864BULL, 0x9DDC7B2C9A871EDEULL, 0x6A597DBBED6EAC2CULL, 0x7A80D1638347E441ULL, 
            0xD306A37C538DB3C3ULL, 0x2849C5DEDF9E4298ULL, 0x2E35602E18544837ULL, 0x77E501D430F519C5ULL, 
            0x11244712AFE9EEF5ULL, 0x16928C0938AA4626ULL, 0xCA696C5A1A1E999EULL, 0xDF0C163E334FC323ULL
        }
    },
    {
        {
            0x24E302AE6473BEA0ULL, 0xC41A27D08741006EULL, 0xB997EFDDED466BEDULL, 0x8730CAD532F82586ULL, 
            0xD30E5CDA698895E3ULL, 0x2C70960E530FE281ULL, 0x1A9A640935485337ULL, 0xC5ECAE052F47A91AULL, 
            0x61C3595D6EAD354AULL, 0xB8B5C88520438E15ULL, 0x787E4B128BDC0894ULL, 0x5D838C62EA2C27D5ULL, 
            0x17801BDC2A1EA014ULL, 0x6058588C915A7DACULL, 0x89F53A7C85D8518CULL, 0xDD617A074CCBF574ULL, 
            0xBBB734931648FF84ULL, 0x5AF5BA5C9169C8E5ULL, 0xE8E661B42F39009FULL, 0xF4EAC2CB1AFE2357ULL, 
            0xED7F0330977BFD29ULL, 0xF5096BC88D08F827ULL, 0xB981566304786337ULL, 0x0EE0B43BE218F4E0ULL, 
            0x72413CAC5E59E1C6ULL, 0x05D72442FA10C6F4ULL, 0xC92C0CFDDFDFE170ULL, 0xAB50BCD8CDF9ED88ULL, 
            0xB44324B6E7A16B15ULL, 0x243E9469BEFDC431ULL, 0x4927A6FDC34AB418ULL, 0xC8B75BE075BBD191ULL
        },
        {
            0x33D9633998FA1749ULL, 0x93090B96AFBC0FCBULL, 0x5FC5ABA1E21F4587ULL, 0x7863165B69F7C1DAULL, 
            0xF7F44C6CC319CEE9ULL, 0x0017A1190A79EC69ULL, 0x184659764F976373ULL, 0x45E4358A798E343EULL, 
            0xEC8ADC197539A07DULL, 0xFB56C58324891911ULL, 0x9C8F84E9233079A0ULL, 0x53771C19B283C081ULL, 
            0x9D33ECB886FC22E3ULL, 0x3D0B11645FD1CD18ULL, 0x324FD164EBAB4C0AULL, 0x610813B2AA14C592ULL, 
            0x176E28709A1362F9ULL, 0xA1875B02039557D7ULL, 0x24E670297FCE8D68ULL, 0x382E8E0055822806ULL, 
            0xBB28CE99E28F50ACULL, 0x1847C959B18B90A8ULL, 0x81492910158769CCULL, 0x9C869D489DF4EFA9ULL, 
            0x710FCA61E7CC243DULL, 0x11F95345FA742033ULL, 0x0DA9ABEA3907CFA7ULL, 0x3D1C81C61758046BULL, 
            0x86EF4A0E044F97C7ULL, 0x2415D710D9E781C7ULL, 0x8D67B747FFDEC48DULL, 0x4C1BFA5D9BF7EB79ULL
        },
        {
            0x92FA3991CB19D2A8ULL, 0xD42DE02636D70FBBULL, 0x40A5A69862EF4A93ULL, 0x40746C42E838B851ULL, 
            0x13593E1157884BADULL, 0x19EAC2D8DDD602F5ULL, 0xC4ACCE5E9DD26189ULL, 0xEEEF8AC4DE525DBEULL, 
            0xF62C2AD7F1853AA6ULL, 0xDA1F57D484712086ULL, 0x9CF613EEFAD48B83ULL, 0x77BA5D72325E510AULL, 
            0xCD8CDABA21A13D48ULL, 0xBCCA76A8CC82F0D6ULL, 0x1FE4186E2D726317ULL, 0x676EA5DA3BC4D288ULL, 
            0x183A9278EACECB8EULL, 0x11E47BF0811303BFULL, 0x2FF6FEE0F90FB369ULL, 0xF3AD3F79153D65B0ULL, 
            0x2DAE879DB211F74CULL, 0x0286A0C9D55EBBC1ULL, 0x3F5F49456C3617E5ULL, 0x622136242F6A5E35ULL, 
            0xC1577E7E9102B3A6ULL, 0xFECDB4789B8B5AA4ULL, 0x62CB2A84963B313DULL, 0xF0572ECD1EFBDC1FULL, 
            0x89EF35826033A2A3ULL, 0xB9CF4F66EADB3C34ULL, 0x25CE132ABD1299E5ULL, 0x308066D13248D2B6ULL
        },
        {
            0xF51A2A5265B85E93ULL, 0x9A2F889B9CB36AE0ULL, 0xD2669D9F10C73D34ULL, 0x79C9FDE9E2DC7576ULL, 
            0x2CBEFE4C3FD77989ULL, 0x5DF4EE5172521F92ULL, 0x754FA4AAEAC0A8FFULL, 0x83B5FD7E70FFCC9AULL, 
            0x220499C8E9F7EF26ULL, 0x5D4ED03967A05245ULL, 0x8C82CE5E9136ACD5ULL, 0x1D3D4567EE17DA9EULL, 
            0x99A15670E1725854ULL, 0x065E0A4EDD352928ULL, 0x15CE5448632F6838ULL, 0x2FE65BBFB91C2918ULL, 
            0xF584C33B09EEFBACULL, 0xB333BE2FF5A2DAE0ULL, 0x36A9558D0A27E9F2ULL, 0x9AECB7B5F75E9084ULL, 
            0x061AEAD95797F7AAULL, 0x05DA07C8CC8B3182ULL, 0xF4666D26ED39DC0EULL, 0x7EE589BAC73A5B51ULL, 
            0xD0C6E5D7CC054145ULL, 0xE7F2EB2D7EA347C6ULL, 0xBEDB1E63FDDDB9B8ULL, 0x884C6FB366184F5CULL, 
            0x2A056A69A24B00BCULL, 0x5A3CF092D9AEB75EULL, 0x7FA6D1521AD2A8DCULL, 0xFEF6975F6A3A0D19ULL
        },
        {
            0x0BD42EE68016995AULL, 0x46B8A820622C2188ULL, 0x2BF70196FF2F7841ULL, 0x50B32524EF827DD3ULL, 
            0xCC69A8798B7D90A7ULL, 0xEF4BD7114C60574FULL, 0x011EC2CF0DE18459ULL, 0x0B62923A24904BBAULL, 
            0xA491D6CDA134BB5DULL, 0x2D6D43117EF75A80ULL, 0x958C3095CEEC5662ULL, 0x33EC23E5859A1236ULL, 
            0x3070AA75BF5DFB29ULL, 0x03408CB6EADC95B0ULL, 0x33CB04F51B37F5B3ULL, 0xD21C18F5ED9E44FBULL, 
            0x308BC0444C3B1EA1ULL, 0x1DCD77BEF86F397EULL, 0x38B06FBA2536D519ULL, 0x0586FF81D11D6A9FULL, 
            0xA2F1C9D062B6361CULL, 0xFD33AD2A542EE84FULL, 0xBEBFFFE8CCEB76FBULL, 0xCCF8166CFA05CDAEULL, 
            0xA8E7437A9FA958DBULL, 0x113B5620A0D6CFD9ULL, 0x1AD7E25E936738EBULL, 0x4E517C9E9535692DULL, 
            0xEE8EF610691F04C1ULL, 0xAD53748B9BB1B4FAULL, 0xD7D3224EC1C67008ULL, 0x58E176EE7875FAD9ULL
        },
        {
            0x29093ABED92294B6ULL, 0x60C82839D6D0E8FFULL, 0x90D0F157CAFE3962ULL, 0xE6F561CA6F8735ACULL, 
            0x7B1D048CC45DAA91ULL, 0x23E5ADFC17130982ULL, 0x95B03F9128D2D1EEULL, 0x1D34AE699F69809BULL, 
            0x0646126385DF288FULL, 0x5A826A7FEBA1A067ULL, 0xB0BA46DA9417C82EULL, 0xFA489148E9DC0E2EULL, 
            0x4ABF9621C80DFB2BULL, 0x3B007CCA01C5B2FEULL, 0x4594E43010B34A4AULL, 0xDEBF3EA5E73EBDE1ULL, 
            0x74CB7FDA5CF13182ULL, 0x8BCD4905197C252DULL, 0x55404D753B6A4C03ULL, 0xCD7988533ECA6BD0ULL, 
            0x7AC7BF80101C4891ULL, 0x4D5F7C339B6214C8ULL, 0x6C94C6D258B7C531ULL, 0xA74B7D5B03CFD2BBULL, 
            0x8B52820B9A19AC61ULL, 0x6310CE4A0AF81925ULL, 0xD18657276700ABD3ULL, 0xCC832B89D00F7CE7ULL, 
            0xCF84662FDCC743E0ULL, 0x63D6E4E2F84CE452ULL, 0x6ACCA7652373FD88ULL, 0x0D170381F602C969ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseDConstants = {
    0x0272B7F69A65A77DULL,
    0x9B7089324BF63A86ULL,
    0xA7CF5C2ED862E19DULL,
    0x0272B7F69A65A77DULL,
    0x9B7089324BF63A86ULL,
    0xA7CF5C2ED862E19DULL,
    0x888739D192601C55ULL,
    0x567ECD5137A5B21FULL,
    0x59,
    0xC2,
    0x0E,
    0xB6,
    0x7A,
    0x8B,
    0xF7,
    0x7B
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseESalts = {
    {
        {
            0x0F8E6B950D955328ULL, 0x0CA1FE05B0302732ULL, 0xE9035BB7E900CBE6ULL, 0xFD6152F9AC4F031BULL, 
            0xF134793B25F24661ULL, 0x86A5DE9DE915A707ULL, 0x31E201F8973B6647ULL, 0x8D783A23733CACA8ULL, 
            0xE51DE2948A6F4EFEULL, 0x1B576149543568E7ULL, 0x883EC3B952C8A18AULL, 0x0E31A81796B1EB31ULL, 
            0x0B6130FCD8DB4F4BULL, 0x229DAC46004E6D92ULL, 0xFC55056936576A25ULL, 0x965C6BC236D7DA0AULL, 
            0xEA60A11763581C4BULL, 0xF1D61B5958AFD65FULL, 0xF0E4B51AF075F5CBULL, 0x9D6651F576B88D3EULL, 
            0xE9952C134BB4C202ULL, 0xFDAF9AD4A14499B0ULL, 0xB2545515AF09DA06ULL, 0x8024C9B584FB6DF4ULL, 
            0x5EE3245C75AB3100ULL, 0xC0C2CE8E0E48222DULL, 0xC1F551350CE6E151ULL, 0x4F5B01F1420B3B37ULL, 
            0xDC195F3477D32531ULL, 0x54A2D2AAC0BF38CEULL, 0xAFB9547D30DDF004ULL, 0xF8A849D32D5C4EDDULL
        },
        {
            0xE9FD429A32740EB4ULL, 0xCF9DA31E54018520ULL, 0xAC69E8BF0E7E4DADULL, 0x78F9C61F5A5EE6AEULL, 
            0x175A4ACEE5A41B20ULL, 0xC5C5D26BF83F26D9ULL, 0x5F0AC11A489961CDULL, 0x94249D0A50C7ADC5ULL, 
            0x118EB5172107F162ULL, 0xC8057C7CDB279713ULL, 0xB2C66FE8F5B3A84BULL, 0x40F8E3659558F75FULL, 
            0x8AB6CF89953D66C9ULL, 0x7DC8F8CEBAE6C9F2ULL, 0xABD73CC153DB0288ULL, 0xFAF170F47C265F08ULL, 
            0xA58B7F8E0EC8589BULL, 0xE48B1FB35FEE9C18ULL, 0xA6F7A75E113AE1E8ULL, 0x3462773219077C43ULL, 
            0xFE14638C73F0F5BFULL, 0xE59CDE74C08707F7ULL, 0x9FB3587E0B0F4C77ULL, 0x0717F3B5DAAB6F8AULL, 
            0x4050F8025538A882ULL, 0x58B16D43EF0BCD08ULL, 0xA2FE9FBA8B0E2AF7ULL, 0x22E963D81BF10190ULL, 
            0x70CB3AA6E4105488ULL, 0x389C683716E19FE2ULL, 0xFF90E2982AE179E4ULL, 0x98762B136A50E352ULL
        },
        {
            0xCFB38805C5208E90ULL, 0xB2B8C6916D7DD7E3ULL, 0xB5046DBF6F99EA83ULL, 0x0715D11C2257DF89ULL, 
            0x5807B6DD20131ED5ULL, 0x2DE16762FF925FE0ULL, 0xE064BFB853F81640ULL, 0x06890181C5CB01BCULL, 
            0xC9CE5A8037F0A457ULL, 0x09C82C9156C9D42EULL, 0x0652D694591A0589ULL, 0xEFA3A8ACA8E8DCC8ULL, 
            0x2B57CDC4B168613DULL, 0x8D857A844FD70204ULL, 0x00F353604B107E03ULL, 0x5AC7F1113E47A63EULL, 
            0xE54E8AB8396546B0ULL, 0xEF3E3F5EFC538B75ULL, 0xE31C8FE8A57BB9EBULL, 0x37E5DBC6E753243CULL, 
            0x03BFC13E32605A9AULL, 0x78A2AAB38BC19A28ULL, 0x63AA589A850B2388ULL, 0x5171CC08BFC11A6DULL, 
            0x189AB534DB93BE8EULL, 0x790AD163E6EDC3D8ULL, 0x3377E094E6C1296DULL, 0xB8E94BDB8114DD6AULL, 
            0xF7F74417E593F299ULL, 0x2744A3B6BC22A8E2ULL, 0x76D486B3435B0BFAULL, 0x50DDBF14996866C9ULL
        },
        {
            0x1989EF896AE00C39ULL, 0x4506201C294A4D1CULL, 0x1DA29270B7ECD8C2ULL, 0x374D62A9B992FE6EULL, 
            0x032CDCEF1C46D6F8ULL, 0x9E8ECF41F81E580DULL, 0x3A7D3BA5469BAE0FULL, 0x09E78FBF2CA4C745ULL, 
            0xAD5AE674B8F0196EULL, 0x8EC7202EC6246474ULL, 0x59EF12D9D231F746ULL, 0xD12E8EDE905BE68CULL, 
            0x89CC9AC646BBE481ULL, 0x4D54C64F462CEE94ULL, 0x4C2DDA0231AF3A11ULL, 0x71F6E2F4725BEC85ULL, 
            0x93ACE9E6CCBF14A8ULL, 0xC2B729F4223BF826ULL, 0x99EAF99E84C2361FULL, 0x89F0115C0F56C626ULL, 
            0x7C2BC9AE3384A706ULL, 0xC694BFB195CE4416ULL, 0xC740F978283070ABULL, 0x73157B48A33A7075ULL, 
            0x475A0D47BAE4212BULL, 0x0321F4E60B2B776AULL, 0x1361A3D59C43A1D0ULL, 0xC333606AA5A89AEDULL, 
            0xCE2E310980EA7DEBULL, 0xAB9F9BA02DEEFF27ULL, 0xE36B02F53B6179EAULL, 0xB90CD0636A51DFC3ULL
        },
        {
            0x167E50C9957D5CAFULL, 0x258BB3EBCAAC0DF0ULL, 0x00EC581E1F4E21A9ULL, 0x9477FC06611B033AULL, 
            0x961BA3860B353A8DULL, 0x3FE6142504DBEA1CULL, 0xCE37A0802ADE212AULL, 0xAC033B413C9ACA22ULL, 
            0xA6B9A0CB1F63D613ULL, 0x0F4B637C02C383D8ULL, 0x91490F5A5C6C260DULL, 0x599456809600B152ULL, 
            0xFDC23048620023D9ULL, 0xB690C849355A6FBAULL, 0x19C59E72A2B85289ULL, 0xE818C1B1144FCB57ULL, 
            0xF1B3D721B6D3B25EULL, 0x3341BDFEB8D97294ULL, 0x1301387F68E6FCACULL, 0x49068710BF41E51DULL, 
            0xA900A648649C8429ULL, 0xFEAAEF368BAEB573ULL, 0xCCBD0FF7365556C8ULL, 0x9BE62180E226B4ADULL, 
            0xB2E33E02D0AE77FAULL, 0x79B1F698792DC6B7ULL, 0x547C5544AF4307F9ULL, 0x3C3C2DACA432CB1AULL, 
            0x180B7DA374F61F02ULL, 0x929CE1EAC69709BCULL, 0xAF70A7D56CB00D59ULL, 0xD0C2350EC117DB4CULL
        },
        {
            0xFEA29CAE08DD5F1EULL, 0x02C579AEBA9FC4F8ULL, 0x448E2F130FB87D66ULL, 0xE9D6C02690AC0EB1ULL, 
            0x4A09F2B38EB60FBBULL, 0x428F59D9AF4D7AEAULL, 0x9146378FED04525FULL, 0xBEC00BFF3678D459ULL, 
            0x24A2500CD16E4152ULL, 0xAAA675E6A48738EEULL, 0x54312A99A09AB2B7ULL, 0x6AFAD561A39D786AULL, 
            0x8F4358D83F1678FCULL, 0x64D5CDAA9A0F15A6ULL, 0x75DC02792292A2EBULL, 0x1C01F9C49C270C46ULL, 
            0x0AB3CC9E99765351ULL, 0x5F0692D673E11B9DULL, 0x86D535D3A7CF8951ULL, 0xAEBE40627D49E44BULL, 
            0x5C2D609ACDFB816DULL, 0xCABE93F768DED4B9ULL, 0xF873DF2776EF5694ULL, 0x788778BE4ACD599CULL, 
            0xC48482526C812CC7ULL, 0xFB1274228050F6C5ULL, 0xC8FC3160710383A7ULL, 0x08B28026E4731C1BULL, 
            0xE190D2E1E7FBEB4AULL, 0x0D65CE91B66357E4ULL, 0x8F9E0E142173F444ULL, 0xF9F963F9C8CAA1A1ULL
        }
    },
    {
        {
            0x368C62D67BB9A898ULL, 0xBF3D48F5A69F4779ULL, 0x638DDA7B011D6ACCULL, 0xB86C548C86197EA9ULL, 
            0x76EDDAB8B69BCE5EULL, 0xA209A678744A211DULL, 0xA88C5E71A8A10ECBULL, 0x058DA6D2124DB316ULL, 
            0xF2264D3276B62E84ULL, 0x6C406DBCB562FE1AULL, 0xCA92975F0FEAA13FULL, 0x5490AF9CFE347C76ULL, 
            0x04E4C0B4DB706E0AULL, 0xD486C3D335BA1517ULL, 0x8A4C1B3AEAA0747FULL, 0xCCCC949A822A514EULL, 
            0x906B242E44046E10ULL, 0x6589D7A67762DEA8ULL, 0xEAFD57A73E5F051DULL, 0x0AB2CD673560D9EEULL, 
            0xEBCFEA1ABAA512BFULL, 0x4C2579100B540A2BULL, 0x8B09EA12975A0D3BULL, 0xE047332E22781B4AULL, 
            0xBF43A7E1F6F446DFULL, 0xE837782CC14CFD3AULL, 0xA0247431FAEA97B8ULL, 0x32A6F543011F9A47ULL, 
            0xE0269CBF1A264532ULL, 0xE54C5FE6D2006520ULL, 0x259B31476D85751EULL, 0x60FEDEFF15DA4A78ULL
        },
        {
            0xF0DF08AED6AC6655ULL, 0xB03648194DC19ED6ULL, 0x4B53115272CEF720ULL, 0x0A9D3F56DD068C3AULL, 
            0x8EF5358D4FDAB24EULL, 0xED6133D188582F04ULL, 0x941D1A6F05EA98A6ULL, 0xF7A66888638983B3ULL, 
            0x39081EA5BEFB94EDULL, 0xB0BD1F6CE08FB4B9ULL, 0x12F79520D9C3E05FULL, 0x24BD036DC1A0DDE4ULL, 
            0xB56C0E39B4FBC7F7ULL, 0x6A839614C0DF4125ULL, 0xF9CF0C6C8D35EF74ULL, 0x5C002BE84E68CFBFULL, 
            0x91BDB258B9535D83ULL, 0x78CEF5D938A3253DULL, 0x5AF8CD43C539BDB9ULL, 0x2A1780922AD7C6DBULL, 
            0x1BA0FE8232A7A766ULL, 0x61AB173D6001CF09ULL, 0x2267E4A32721B3ACULL, 0x685E619C6E99C9C2ULL, 
            0x0D1CC41EB51C3686ULL, 0x442915E39E5220B2ULL, 0x80DD27B93A9085FFULL, 0x68D920E70289CF95ULL, 
            0x6AE7742955A34242ULL, 0x3FC692350DB118E2ULL, 0x378A4A508CEAC023ULL, 0x0FEB8B6E00E6ABA6ULL
        },
        {
            0x0228256B0C814275ULL, 0x6762916CE09FB1DAULL, 0x5D538FAD4F926592ULL, 0xD4B21108BEA27D29ULL, 
            0x7095CFED61BC0F41ULL, 0xE3A82B98742238D3ULL, 0x76E249E595DF9A36ULL, 0x5619551A83628BC1ULL, 
            0xF5C2D9DBE9DC5F37ULL, 0x3A60EB754BB722BEULL, 0x50930DAE6D0B575DULL, 0x410B88EA3233C018ULL, 
            0xCEDE12E048C7E29CULL, 0x148EE57A29C5A04FULL, 0xEC2C3F561D8CD5E1ULL, 0x713146B4A36E6E9FULL, 
            0xEB675BA52A48D9F4ULL, 0xB7566B0EEEBB47F5ULL, 0x21DAD381CB7DE11CULL, 0x035707CB9765B6B8ULL, 
            0x84990C5D78E12B65ULL, 0xCDA87E29D10288AAULL, 0x39DEA4110C41963FULL, 0x3B82235E19D957C3ULL, 
            0x72722A5DB32D945DULL, 0xF18C0882C45D8DBBULL, 0x00A88BCD744161E4ULL, 0xDC627ACE3B102089ULL, 
            0x5CA57CE002DCFABCULL, 0x4A34EB2C690F2A40ULL, 0xFAD5DD6EFDE3DE1CULL, 0xB419691A29F8D61FULL
        },
        {
            0x61B49CAA809E988EULL, 0x3B26B705F3977FD1ULL, 0x3687098850A2DD7EULL, 0x47080BAB1FEF1CBBULL, 
            0x78A1C0EF674451ECULL, 0x5948040EEC604014ULL, 0x25CDBAB00714BA7FULL, 0x93C6DAA616C01640ULL, 
            0x84972BC6142B9C14ULL, 0xD2EDCD5EB38965F7ULL, 0x2BEDF0C8E4E16CA7ULL, 0x49F6A905E50A434FULL, 
            0xCD1ACDD9AA1C627FULL, 0x0B0F11CA59662436ULL, 0x7FB79FD0839CA0ECULL, 0x790D021DEFA37209ULL, 
            0x256FD0F1F821CF72ULL, 0x2C48509C5F4E1068ULL, 0x8DE5E9E9DDE8941CULL, 0x718B7B54F29B2A47ULL, 
            0x95EC02D35090E3CEULL, 0x405F924A97000FA5ULL, 0xF46F8E52C1823DD4ULL, 0x331DD6F4BA42F9D0ULL, 
            0xAB2A6AFBCDDE787EULL, 0x3B399C0C9655C182ULL, 0x379503F512C3DDB7ULL, 0x70384DA2E14328DAULL, 
            0x1C1771966892527DULL, 0x1D60FBDE08920A15ULL, 0x4E19FB2E237536E2ULL, 0xA2F070A640D7403EULL
        },
        {
            0x43E3ADD2832D0469ULL, 0x3E4A1D79BB6B8EDFULL, 0x65C07885B76211A2ULL, 0xE21BA063205A50B8ULL, 
            0x0879D29AFD0AA902ULL, 0x6841BE1943622FB2ULL, 0xA06B26CFF9EF3F02ULL, 0x11CD0F3C8A26F319ULL, 
            0xE14182377E1F05D1ULL, 0xD54D8A09CED25151ULL, 0x6937E8B876DA2A02ULL, 0x96135C5FAA35B953ULL, 
            0xBFFF7A7BB857E219ULL, 0xC48047E10C770733ULL, 0x6ED5BA1E9C1B1347ULL, 0xB968C8CCC6A2A0B1ULL, 
            0x4FAE7908C235ADB3ULL, 0x3A16E551C27EEC49ULL, 0xF9B5A709E0EB476BULL, 0x040A6A0F4B9B2A75ULL, 
            0xDB95B1D04AD67F84ULL, 0x9A97AC361BD4CC12ULL, 0x70C93504B8D88CA0ULL, 0xA93F4D7B3B2A13E0ULL, 
            0xF1B70366AFC7E253ULL, 0x11C2706D2D3BA4F3ULL, 0x237542BA487C7A89ULL, 0x9079A9D486253475ULL, 
            0xAEAC5A25F4723E6EULL, 0xA57E6A2BB586F87DULL, 0xD4C366DE54BFD40BULL, 0xC92811C7611937CCULL
        },
        {
            0xB78E9D00949B97D2ULL, 0x12CD4C6F8D6DE311ULL, 0x8F772B5E26A421BAULL, 0xB9B14B0AA5BCFD1BULL, 
            0xE2925B0CED532B95ULL, 0x03EA6EEB1CF018EAULL, 0x6F608A67BA76CCD0ULL, 0xC2CC73FD47E1FA9BULL, 
            0x7ED1306CF50C0381ULL, 0xE1ECFE769DEAA064ULL, 0xD9E4420263B6DBF3ULL, 0xD1EF3D027A59F9E5ULL, 
            0xEDE3BB75EC55D1D2ULL, 0x3F09EAF293F216E6ULL, 0x20A220B5E0BF5ABBULL, 0x9B837C866DEC296CULL, 
            0x5192C494D852621EULL, 0x32BFB50D971FB14FULL, 0x33D888AB8C995478ULL, 0xF18557E3536DA3DCULL, 
            0x22F3202F8609C125ULL, 0x723B2F66676B303CULL, 0x8296CDAF068FD3F6ULL, 0xD5A07704FF6ED073ULL, 
            0xAA3DE77523893090ULL, 0x7417C1C75F9B8852ULL, 0x2BE97FA317594BAAULL, 0x491262DB146E7E9AULL, 
            0x6E1C4C9E62E989D8ULL, 0x912481F52807852DULL, 0x59A4BCD86B21FC6CULL, 0x979EBC305DC1CC78ULL
        }
    },
    {
        {
            0x2E48F5C69A70AA32ULL, 0x2EFDF19F07EB1FE9ULL, 0x092B0B6D7A4C99D9ULL, 0xFA80641FFECB1CDAULL, 
            0xE6B5382D8220340CULL, 0x88212AD9285401D6ULL, 0xA38159D36B30033CULL, 0xFFF1D18275EE03D9ULL, 
            0x3ED8F11912C517FEULL, 0x29BCAB071B98A376ULL, 0x6E4076880A7C0E83ULL, 0x9EBBA8B30AEBF881ULL, 
            0x819BA201682EE147ULL, 0xE3D74DA4D2175987ULL, 0xF734597E63139B94ULL, 0x6CFAAE0ED96BEB20ULL, 
            0xEE8597045F355850ULL, 0x23B113747A62BC23ULL, 0x75458814E563EC74ULL, 0x05B752170AE0171EULL, 
            0x12C303A09FDB1819ULL, 0x5817B79F50C36BAEULL, 0x51AE93119F07689DULL, 0x2F423F463994B140ULL, 
            0x2589ED03D535A6BFULL, 0x24329C41B03CD296ULL, 0x2F1EFD8D06BB8A78ULL, 0x1079538247EDC0DFULL, 
            0xEC5681587352FD3CULL, 0xE9189534FF711896ULL, 0xDBC94EFD8A4DA817ULL, 0x10404ADA3C01EABCULL
        },
        {
            0x744B03DD8DCC05AAULL, 0x0518F634930F1D03ULL, 0xCA0647ECAAF72A44ULL, 0x8A8C1605C1026B49ULL, 
            0x87E32C144CC5314FULL, 0x2E661595DF7BA44BULL, 0x1D5C2282EAC0EF6BULL, 0xF7EBF4F3E71B66D5ULL, 
            0xF96B820BEF598FDFULL, 0xDC0C59BBCFCB1BFDULL, 0xB2202F2DF779F017ULL, 0xD9B177B16F5C55E3ULL, 
            0x37B0B4CF0EC1BA60ULL, 0x30B6C3E1B59621CBULL, 0x3E0B73BAF2434F85ULL, 0xFF1BB7F0C4CA49DBULL, 
            0xD0A303509002153BULL, 0xF2E50FF8864794A2ULL, 0xFCD9B32C753D03A6ULL, 0x6F6BB8340F5E1330ULL, 
            0xAE8C6BD755221188ULL, 0xEC86D209DC0EBBB2ULL, 0x4EBC7CB846C53FEAULL, 0x74FF9E898E2C68FAULL, 
            0x051880DC853CBB57ULL, 0x82A81ED77EAA8C18ULL, 0xCC2E306E7FB40AE8ULL, 0xEF3500D0F89DAABFULL, 
            0x50E74155A0955E8DULL, 0xF9676364B1F790B7ULL, 0x8BB3A0D5AACAE173ULL, 0x0957650CD5885FF5ULL
        },
        {
            0x7214CC04C1768D29ULL, 0xCAE7D118A05C0CC7ULL, 0x501E8E5C70D86634ULL, 0x365FAAD900C7BD13ULL, 
            0xA498D650525502EFULL, 0xB2B76D50343B2C90ULL, 0x738683EF598279A9ULL, 0xC3299567EFD89226ULL, 
            0xC875800D2A95E6ADULL, 0x78956813A3337219ULL, 0x36C032B5FC83B603ULL, 0x7BA160781F4D8678ULL, 
            0x4A1C60EDBA74CC3AULL, 0xD8CFA2C0A74CC2C4ULL, 0xAD24D832BD620F78ULL, 0xABE1CD68937B3BB1ULL, 
            0xA9B510CC0714D703ULL, 0x0A0D31C3D5DA4093ULL, 0x3253E5839EE56751ULL, 0xCEAC25ED27231265ULL, 
            0xCCBA76E0410576D4ULL, 0x7BF437F94EF0245AULL, 0xF8C14845D147A648ULL, 0x411811F988C3919FULL, 
            0x5B5B98CFD9438CC7ULL, 0x02EC07C26C8828B5ULL, 0x5E8795D346D9F619ULL, 0xDE4CC2A10C45094CULL, 
            0x53E1D00DDE38BFB7ULL, 0x233510046FB72BF8ULL, 0xA1E62F9FCA468967ULL, 0x70C210E07CBCE46EULL
        },
        {
            0x21B43E45F11A8780ULL, 0xE88DFFF35449C212ULL, 0xF477C560AA4889C7ULL, 0x851A37E48098E3D1ULL, 
            0x87820BE4DE72BB4AULL, 0xE2703F26F4F5CFA6ULL, 0xBCBD4E0FF9506A3EULL, 0x6D139A0CA50EE784ULL, 
            0xF3D3B630F74FFDCCULL, 0x99476B07694BFF47ULL, 0x1C46E24235E5496BULL, 0x91345F0739DB4969ULL, 
            0xDF74D077F6F2E7FFULL, 0xB479ED7DBE28B764ULL, 0x9A97B84C43A0075FULL, 0x28735BA75A45ABDEULL, 
            0x5693C4C1D482422EULL, 0x6A703CE9D6123E18ULL, 0x6DD217AE913C6BF1ULL, 0x48B9464895A321C6ULL, 
            0x9D0E5BEF1CCBC9A6ULL, 0xC0EFE8BB223E925CULL, 0xE13328A9B6871ECBULL, 0xC33B84579707A871ULL, 
            0x9FAC8A9CAD16DE2DULL, 0x0302458020BCCD75ULL, 0x10E98A4555E9EB64ULL, 0x0FD49AF40C20A7DDULL, 
            0x72DA4E9D7E6CAB4CULL, 0xA327EF24ED83D6E9ULL, 0xA0F637C1A870015FULL, 0xF27897AAF66A0D1FULL
        },
        {
            0xD72D5DE27D42CB75ULL, 0x05AE432D97E122E6ULL, 0x954C5D24B0FCB9F6ULL, 0x049AC940EC9810F4ULL, 
            0xC7407B6A6377BF83ULL, 0xDAAC2A85CBD0C584ULL, 0xE51655DD590AD2EDULL, 0xE7C5D71958E5D522ULL, 
            0x3305E139D6513266ULL, 0x05E448A495D6E9EAULL, 0xE62BFF9E8B73F4EEULL, 0x6502776DF3A39F17ULL, 
            0xB6DF060972D8C2F5ULL, 0x6BEAD794C802D1D5ULL, 0xDE67B3C72CBF05C3ULL, 0xA741E6DAC9E963B1ULL, 
            0x411BB68A2EA96913ULL, 0x6138354489BD1480ULL, 0x1B2288A4D031C9E7ULL, 0x1C220B4D02D67E8DULL, 
            0x368C6770C3AE7F25ULL, 0xBEA5A8D2CE3696E2ULL, 0x6D1F786B141EC47BULL, 0xF8CCBAD6970CA4E3ULL, 
            0x13322094A922C9C7ULL, 0xBC5483189773053CULL, 0xD1D1D3F24C24419AULL, 0x30091AB51A958E2CULL, 
            0x4241EC277093F867ULL, 0x48FF15A4E572C36AULL, 0xED59B49A61CA0591ULL, 0xFCCB38F7F3C42D8EULL
        },
        {
            0x2DF948EA2D5B8800ULL, 0xA73565A7E40BCC12ULL, 0x79D27152E1C1AAB0ULL, 0xB8F31AF6B0256232ULL, 
            0xA38BADCB7A36B4EFULL, 0xCFF246BA404D8708ULL, 0xD62B31FA7B6B84DBULL, 0x6A2F0DD7404729ADULL, 
            0xCB95D28AD99F7478ULL, 0xFD6EDF6C2D8094CDULL, 0x4F98F66DB100F098ULL, 0x30AB278F40106DC1ULL, 
            0x05D4FA693FC91F25ULL, 0x54BC9DCE863C786EULL, 0x1CBCB6CC4971E851ULL, 0x5BB27ACE70F03664ULL, 
            0x5E2767AAB22550AEULL, 0xD8FE3F0FF56F40C7ULL, 0x7530461F83C323F9ULL, 0xA611E4BA786EE802ULL, 
            0x5E82CD3A26C4A739ULL, 0x1B872AB6A75AEC86ULL, 0x7ACF043C6FF84E1BULL, 0x48CA2C9177642467ULL, 
            0x59544A7BA1A14A83ULL, 0x965CD1B03C731CFEULL, 0x72A02C3A73DB2F13ULL, 0x0D135F7DEDB04DD6ULL, 
            0x03398D324D63B414ULL, 0x28E3A890935B5F4AULL, 0x9ECBC6F13F61191BULL, 0x8301414EF8ECB25DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseEConstants = {
    0xFD6507633078DD1CULL,
    0x90DD4D342F880713ULL,
    0x03079F683B0D6F54ULL,
    0xFD6507633078DD1CULL,
    0x90DD4D342F880713ULL,
    0x03079F683B0D6F54ULL,
    0x9A14D2EF4810B551ULL,
    0xA2EC5CB0A4692807ULL,
    0xAA,
    0x03,
    0x44,
    0x36,
    0x53,
    0x95,
    0xA4,
    0x57
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseFSalts = {
    {
        {
            0x9D66977088312A89ULL, 0x0C545B2E4A21C1ADULL, 0xFDF9D76E465E025BULL, 0x66CAC0D381747B13ULL, 
            0xC7B9039D9FA6EB36ULL, 0x44EAE416C6E61E7EULL, 0x15C35920C7B1BDBCULL, 0x3C06E4F7A29AE8E0ULL, 
            0x6C09A7D300AB55DEULL, 0x899EFE0776B05E0CULL, 0x314773728DD822ADULL, 0xE08B3B37DFEE9FDEULL, 
            0x11FD58CE29F7AE40ULL, 0xA9E7E35EBA7E960BULL, 0xC0042F05366FEB8BULL, 0xC96D081CBC37DC99ULL, 
            0xE607B24732B6389FULL, 0xD159C004A3FC660CULL, 0x7D7C2EEF6993A6F9ULL, 0x38FD06384E0E3337ULL, 
            0x5704D5F25BB08A42ULL, 0x44FEFD859F7AA106ULL, 0xC8E2551C094472C1ULL, 0x9D3BB60F167B6875ULL, 
            0x7B38C28DBA4F4B73ULL, 0x1237EE643763FCBAULL, 0x8A417F38670DEF94ULL, 0x2F3B4C1AA19FCFD4ULL, 
            0xE20C18409561BE78ULL, 0x63509E7E9B169B5CULL, 0x1E82C2787932A728ULL, 0xD44F3BCF98F63F14ULL
        },
        {
            0x3D7137BAFB9B0449ULL, 0x3F079FBEF2F89004ULL, 0xB2AD2A9D441528BBULL, 0xEE6D114C00B18F08ULL, 
            0xFE0294BE7C9E2EB7ULL, 0xEFDBE5134D143CD6ULL, 0xA9844F7654D4CBBFULL, 0x5284B47932A00A8AULL, 
            0x84D51B11BF9CEEE9ULL, 0x8A87B5B6F0B188F1ULL, 0x599433D84BAF5B20ULL, 0x843589D03DB990BBULL, 
            0x1C74934757E5E787ULL, 0x48F54F78BE0E6CB0ULL, 0xA24F6345656C29B3ULL, 0x6B0F67E1A3D64C4EULL, 
            0x496DCB6828F983CEULL, 0x5202CC333EE982A8ULL, 0x7B62EF6217D605ABULL, 0x7D31D0D3DB0133A4ULL, 
            0xAB544440755D96D8ULL, 0x7143FB781002A562ULL, 0x4773C1A1CB5AE455ULL, 0x5BAECA818CC6DC9CULL, 
            0xF1980CAD16C06D60ULL, 0x4EC170F59406C5FCULL, 0x3F0D26A05511AB56ULL, 0xB51EAA0F81933270ULL, 
            0x75570FDF7163831DULL, 0x7996C70A9B63604AULL, 0x02E6DD623799502FULL, 0x188DA80AC05A98FEULL
        },
        {
            0xF9AB488A7243E6E1ULL, 0xC5D8E9A87B6BFFB5ULL, 0x132582EC10A25104ULL, 0x67E2CB7F33BA688CULL, 
            0x128349AE67E04E7AULL, 0xE9E8E71A4E797772ULL, 0x802EDF92EB356298ULL, 0x1154D3E0992335F4ULL, 
            0x761E6D90D7666B6FULL, 0x3E86AE67B72242BCULL, 0x1BD6388C52BE7641ULL, 0x6C67A24699A075DCULL, 
            0xF7D29A1FAD8747FBULL, 0x655E1A3C08EA97B4ULL, 0x74A0291F86603559ULL, 0x06F37002BBEA3131ULL, 
            0x7FA3AEB04255682FULL, 0x6CE6CEDBFA4C29E2ULL, 0xCC7D1C80F462353CULL, 0xE1185C78D3461E79ULL, 
            0xC6133EFF5B0B1F72ULL, 0x854910193EF8CA9BULL, 0x14683FB099B866D4ULL, 0x931FDB40A9B921D9ULL, 
            0xD082006DAFD7EA0BULL, 0x7922F60D05362412ULL, 0xBF4EE9C89173B950ULL, 0xEED1BA0E7284D077ULL, 
            0xEBAAAACC7FA6F73CULL, 0x07B174F5A5D70581ULL, 0xC59FACBB0F2EC91AULL, 0x79ADB138B7179AD0ULL
        },
        {
            0x646C5207B58F878FULL, 0xF2C88AC3769909DDULL, 0x8847B566A708C304ULL, 0x7F4AF9F700E3C272ULL, 
            0x22B87EDFC35E09E8ULL, 0x12F6544C0B5239E8ULL, 0x6179FE2A4398EBBDULL, 0xC4FF3DE97EA31A5FULL, 
            0xC08ECA9E2D5B67B4ULL, 0xE71B0464F85ACEFDULL, 0xDEBE5C78DB7B2943ULL, 0x8C041BF136695F45ULL, 
            0x5696C136C59C9661ULL, 0xB2094E15E253E15FULL, 0x5F18D47BD99930D6ULL, 0x638CCC60CBC46A71ULL, 
            0x18F3AAEDA136219BULL, 0x386254799644CADEULL, 0x31D294F2F6736BA6ULL, 0x8FC8085564771C6FULL, 
            0x9439F38B4D602341ULL, 0xAFCCDC0EBE399646ULL, 0x391C389175B3FC1EULL, 0x3B89FA54C92A0552ULL, 
            0x47D33832EA42EE45ULL, 0xDF936869E6AB15DFULL, 0x08ED8D9AB339B4CFULL, 0xD93AE8D6310D8006ULL, 
            0xE7C7E30AD4EE7948ULL, 0x62CB76744CBAE3D6ULL, 0x84AC58D33D092620ULL, 0x55F55F81663D43ECULL
        },
        {
            0xB2C95708EE820E0AULL, 0xAEA314682ACAD308ULL, 0xE53BD7398FD85E80ULL, 0x5DF4A317D1E49572ULL, 
            0x68C37AB48BD9C034ULL, 0x1935BB8618375EB7ULL, 0xA152796DABEEC6BAULL, 0x218ECF2A1108CC7FULL, 
            0xBA20AA4E457F00E8ULL, 0x308D215807AC6674ULL, 0x4E53E881EFFB8142ULL, 0x912B6B4E2448C8C2ULL, 
            0x016D042FEAE5AEE8ULL, 0xF9C9298EAE2B21D0ULL, 0x407A17EEA2EAFB50ULL, 0xC72DBE30FA2BE26AULL, 
            0x82854845E129DF07ULL, 0xE3E419E71534CCA3ULL, 0xFA0D17726C5E0E19ULL, 0xD4E7612EE718B5EEULL, 
            0xE84B1B5581356B30ULL, 0x6A045010960C63EAULL, 0x5F1CAC439EE3B2F5ULL, 0x583EC930C37D6292ULL, 
            0xF4952434B1E06D63ULL, 0x73CCE62F83073FC0ULL, 0x8D40007493678744ULL, 0xF4C94BCCA761BB27ULL, 
            0x432EC28ED622577EULL, 0x4256F2FCC2F54AB0ULL, 0xCF9D469789F1B458ULL, 0xFB3FC5ACDD0DE6FEULL
        },
        {
            0xED1FB39E1F15B56EULL, 0x3844402A93F7230AULL, 0x6070AB38A9B0EB03ULL, 0x868DEDB712F2270CULL, 
            0xDCF3AB2C231BDE68ULL, 0x62892E8ED89674FBULL, 0x77F24DBC85C5A9CFULL, 0xA6544059FC3E1F50ULL, 
            0x26BCFBFB9D0C3B69ULL, 0x7E89972C9AC84D94ULL, 0x97A7D90F8B958DA7ULL, 0xB933D53B0C246609ULL, 
            0x9317E28F65024B50ULL, 0x90EE7927B7E90E52ULL, 0xE5BBE2EF67D896B9ULL, 0x7F500ADA0A262D63ULL, 
            0x7139F8FF4623741DULL, 0x4FE953F3DA760D05ULL, 0x2C2071D25B947582ULL, 0xA12507FF0CE27D23ULL, 
            0x529C0B498D2DD71BULL, 0x0CF8AFD8D7A50E32ULL, 0x578B14DAD99A6E2DULL, 0x4C29D7292FA150A5ULL, 
            0x92823E489D777F96ULL, 0xFF70F80773E62586ULL, 0xCA6970618A7E927BULL, 0xBA6DF251A68AC6FFULL, 
            0x750F3B629FF3F021ULL, 0x4998DB3DEC900C7AULL, 0x08C92663F2A44FDCULL, 0x03626D6F59F86E14ULL
        }
    },
    {
        {
            0xA323D65AA8DE71BDULL, 0xA4F4D7121C6E706FULL, 0x8A22CADFC508B047ULL, 0xE8BCCC7FF930D9F0ULL, 
            0x184520781A11FC7CULL, 0x950924F7AE8BEEE5ULL, 0x293B21B40517B11AULL, 0xBA189A246F3F6937ULL, 
            0xE2D033CFF49F8A97ULL, 0x1829EB1C34AB1547ULL, 0x1DBBA082562B7E20ULL, 0x876CC6C85478D4D9ULL, 
            0x9BECADDDB18BC0B2ULL, 0xDB3D5152432794FEULL, 0xFCE1C3384374CD77ULL, 0x02804B5FE32F5F49ULL, 
            0x4D2A54E660B18E58ULL, 0xA2F2B4E798B1BB30ULL, 0x5CC6AF4DC7B1398AULL, 0x2BBE5D2204317430ULL, 
            0x52CF6A8321543BDBULL, 0x4AA80F80B36FD150ULL, 0x8AA434F27E84712DULL, 0x1A157B83A9863AF1ULL, 
            0xA1FBD7A9323CCDD7ULL, 0x020FA6BF5F9A9AC6ULL, 0x4BBBE1F86EE3E769ULL, 0xD3CC383EC4A98D51ULL, 
            0x9BD32D5E0EBB9B9AULL, 0xAB961817A4B4D1A8ULL, 0x1D0FAF07740D426AULL, 0x61BD907215292365ULL
        },
        {
            0xFE879AD321DA5151ULL, 0x03B9517498068719ULL, 0xA698496C29268E8CULL, 0xBD6BF8DB851BB4E8ULL, 
            0x445D75B484C16409ULL, 0x96DA21AEA7A56543ULL, 0xC7FDBD6891223681ULL, 0x199EF524BFC9C332ULL, 
            0x882C5BFB577F3F60ULL, 0x4993A5E3A2085CB7ULL, 0x35F338C243909351ULL, 0x9EE02DD365B17180ULL, 
            0x9BE15149881A3662ULL, 0x955A2D2DA8B4762CULL, 0x11B1785C872AAF9DULL, 0xD8CBD093A389FF63ULL, 
            0x89D06C4069F04ACDULL, 0x12BE720AC870AAF1ULL, 0xF24F3BCCE8829E1CULL, 0xAE8CEE7255A08C44ULL, 
            0xD98EF94BAAAA6DD1ULL, 0x07459C4090856822ULL, 0x79FA0CF5DC9BE0F2ULL, 0x3DA6EB262AB9B258ULL, 
            0xC91A0E562D88BB1FULL, 0x5EBAC45247657D04ULL, 0xAA18F7DCB9B5B008ULL, 0x817995FD9DD6B0F3ULL, 
            0x077D95E77E9BD6FEULL, 0x4A43A69BB517BB7DULL, 0xC1C6B678B25ABAFEULL, 0x0925E54522134363ULL
        },
        {
            0x68C7BBDEDE4AED12ULL, 0x774C5C160D9F19E8ULL, 0x72039A67EF6C0EEEULL, 0xC07872FD946BF223ULL, 
            0x4D5FC59CC5C97BB6ULL, 0x76B487090483DB6CULL, 0x8C82648258B1E82FULL, 0x25574D94B68C6A53ULL, 
            0x9F54AAABE0163591ULL, 0x46144D436A524050ULL, 0x3CB624D85C239E96ULL, 0x7F7D91F8BDE0BB88ULL, 
            0x9E4EB16255639D45ULL, 0x4602432F6FE1A6BDULL, 0x764F6236AFB0B8E2ULL, 0x9E1254F945F6A21AULL, 
            0xD8DEBA5E429D49ACULL, 0xE4456257757A566BULL, 0xA1B96166A61EE6C3ULL, 0x53B0BC4C6F466C51ULL, 
            0xBF22755BCB227A19ULL, 0xFF22FBF76ADD60B8ULL, 0x2AFDF590B35FFFEDULL, 0x1A443FCE47400A09ULL, 
            0x1E833C81D5725BD1ULL, 0xC10550682E89A5C8ULL, 0x01790EBC8F45D8D4ULL, 0x3D8475BC14D022A9ULL, 
            0x5BD64C3F683089F6ULL, 0x2202E483CA227AEFULL, 0xE801B51980368D10ULL, 0x3B20ED88B13FCE14ULL
        },
        {
            0xC469A54D7673DC5DULL, 0xCE87F6A572A6BA74ULL, 0x39963DF891F1B8BCULL, 0x1E5AB7934B694E9DULL, 
            0x4D34133E17A82F01ULL, 0x3E6369CE182397D2ULL, 0x746E675B772954A1ULL, 0xE2D3D56E866647ECULL, 
            0x6EB21805A4626ED4ULL, 0x3B667C5E0248D319ULL, 0xE3CCC29A97FD86C2ULL, 0x17F1B2ACFB3774DEULL, 
            0xD782E908D11B345DULL, 0x5783D1112824E9DCULL, 0x7C395357D8E1CD65ULL, 0xC3F4388085656EC2ULL, 
            0x4582066E53ED08EDULL, 0x780EC53D3A2A3D09ULL, 0x46E0097F78588860ULL, 0x1F26CE93E2704522ULL, 
            0x5271C05660A61A71ULL, 0x1475B8EB8F5F96C4ULL, 0xC6334E829593098BULL, 0x14070FC19465A555ULL, 
            0x0A92F186A01C3FE0ULL, 0xB8D8EA143A0796AAULL, 0xF9CDE94F19AAE584ULL, 0x02191C872A7446F3ULL, 
            0xBE67E76FE06A38BEULL, 0x48837F4B68AA4B3EULL, 0x4E8B0656BC4F3F54ULL, 0x2DB634A71532AF5DULL
        },
        {
            0x81D6C538A9B216CBULL, 0x6BAD993EECACDC9FULL, 0xF89DCD31BE911680ULL, 0x308890569EF9D3D1ULL, 
            0x5F3BA65B56A3E644ULL, 0xDB486D732A4DE16DULL, 0x9D173C973B976C7FULL, 0x0246F315F59697B1ULL, 
            0x36780120F9EE5C99ULL, 0x16DA9060B38DC5D9ULL, 0x487C3E6682023CB3ULL, 0xEE4387B2A0A78763ULL, 
            0x112F9BA22B280A42ULL, 0x93641EEB38F788E9ULL, 0xB315ECA910E5EA0DULL, 0x1EE541F7141BC535ULL, 
            0x34701A286ED39B10ULL, 0xFD235E2AEB713C0FULL, 0x9ACB4EA8FA6BAC8DULL, 0xE552FDFB80AAB36EULL, 
            0x7F69BB2519372CE1ULL, 0xA9D5EC0FF128FBEDULL, 0x5AE215CAD8AA54A1ULL, 0xBEC3BFD7ABF13A29ULL, 
            0x31BE4FC702C716E2ULL, 0xD0160499926090A1ULL, 0x0116375206F2F0EDULL, 0xE9580F9FAB632E77ULL, 
            0x4B3979F85C9A5D63ULL, 0x42BB5DFD1BD6C6D9ULL, 0xCB078F3301AD06CBULL, 0x6F7173F92D4A6624ULL
        },
        {
            0x57381B8F2C9E6160ULL, 0xFA761EB0945DEF19ULL, 0x6DCD8BD2C92A4CBAULL, 0x3A0A3B412BE12BA9ULL, 
            0xAD86BAB294ED89A2ULL, 0xEAADB6FFDBC02599ULL, 0xF1DBC321E76C1CBCULL, 0x11FCEBFDA81C6F50ULL, 
            0x9D85772233EE81F6ULL, 0xF54985B08B5AEF51ULL, 0x36775F667BDC9B2EULL, 0xDD41ACEE284EC900ULL, 
            0xCF34A8040E1BAE4EULL, 0xF4923A73DC8C9233ULL, 0xDB62D8F19942BBBDULL, 0xE9A6DF3B518B71A8ULL, 
            0x9C39207A0A312F06ULL, 0x92DE98801D65E9A9ULL, 0x30E15F1C33964B5BULL, 0x55170BA94ACF0026ULL, 
            0xBCA590E09B6B42B1ULL, 0x37835213831B669AULL, 0x0979780A52F5EB4FULL, 0x72536EC44F627C45ULL, 
            0x3812DF9AD1488BA2ULL, 0x87D3D914C08387EFULL, 0x0DE4C08E3782D690ULL, 0x6EE1627E03F24D01ULL, 
            0xBB7F349196E5C514ULL, 0x0891DBFC281BB9EAULL, 0x679E59B22C8AC1ACULL, 0xDFEBB7CD3B08A902ULL
        }
    },
    {
        {
            0x9B94A6B11AABE824ULL, 0x6A47B7A3471A6B80ULL, 0x314A6D6A9AF96E54ULL, 0x9601BCA3535A3BE4ULL, 
            0xBF67B531A7A39D9EULL, 0x074CCD6A081BE83BULL, 0x2026716A5D165DB2ULL, 0xDD8FEF0E0EDD3D09ULL, 
            0x68936B7C319D7050ULL, 0xDC23333566844C5BULL, 0xB64CAF8D736600EEULL, 0xC9D91D8D017618A7ULL, 
            0x0A9837E5496A23F1ULL, 0x1FD1DC76361EA6A2ULL, 0x640559FFF2EA8695ULL, 0x133930F098FA214AULL, 
            0x6162F4BDE172114BULL, 0x8F26EEF68C134657ULL, 0x84924DBFD014A8A9ULL, 0x009A66586FEF93B3ULL, 
            0x46901CF284E2D4D3ULL, 0x6AB5D2F894F9445EULL, 0x7C6C92925F904B28ULL, 0xFD79C23A0214F136ULL, 
            0x30235D6DD3E32FDCULL, 0xC7987039A68C9190ULL, 0x4BE8C15F2E29A99AULL, 0xE9329D2851338D21ULL, 
            0xAECBDF1FE125D599ULL, 0x59373EE014AB8B74ULL, 0x8DB789EC336747F4ULL, 0x14000EDB45E55BD2ULL
        },
        {
            0x9083A9E6332329E1ULL, 0xC03E057B01A7397AULL, 0xE551BB452546E2A9ULL, 0xCA95073175AFF1A3ULL, 
            0x3A63870DC87B54CAULL, 0xBB457C97E0B95559ULL, 0xF12E0B38109AAA1AULL, 0xC99EB233D7E5E845ULL, 
            0x460D8685141C4F66ULL, 0x06E2FF3EF6A59CC9ULL, 0x382D8201AF3385BEULL, 0x1F863F0D8501B4C5ULL, 
            0xB0BEBA322AA55AAAULL, 0x1536D8AD5D4F702BULL, 0x1EF192E20D8A771FULL, 0x510A103AD075B384ULL, 
            0x7C9E5814CD4D3F13ULL, 0x897C1B6872A0C823ULL, 0xA66B204AE5C14CF1ULL, 0xB952EAD4F334099EULL, 
            0xF46DD80C5175EAB7ULL, 0x436315822587BD4EULL, 0x2F1152030EF20519ULL, 0xA144A6CDFD6A3242ULL, 
            0xE8196CAE2B74DD0AULL, 0x9C2FED25C42FDC73ULL, 0x1613261CAA6C28CBULL, 0xBFA508ACD978FDD3ULL, 
            0x3AFC4D0E07FA599EULL, 0xF0606FB9EA41D5ADULL, 0x5C9535E374BA1A50ULL, 0xFEBB012C6CAC710AULL
        },
        {
            0xA55821C935C7A64AULL, 0x43BEF1137EA638F6ULL, 0xCB447C2EED1B4204ULL, 0x21D235CAB3037087ULL, 
            0x9FEA92E389C5BEC1ULL, 0xE31E630D50D9BC39ULL, 0xAFE709C25D75AEA5ULL, 0x5BEBAF576CD784BFULL, 
            0x3348E99292251445ULL, 0x48150A566C1817E1ULL, 0xAD851B3F756EACDCULL, 0x5BAA2D73C9B0EF04ULL, 
            0x662FFFFC0E26E0A8ULL, 0xAC7666095A01A06CULL, 0xBDA86EFA6F021206ULL, 0xAC0B84D2D99246ACULL, 
            0xCD9AF0D1BF8F1971ULL, 0x2C1D69E27A6A76F9ULL, 0x6405CF3F0F92F129ULL, 0x1BC12886F2271F8AULL, 
            0xFD919A0B1D634EA0ULL, 0xF92D044569B6FCD4ULL, 0x0401CD1976FC8F7AULL, 0xF2297B2C831DCE2EULL, 
            0xBA09429BC653B35AULL, 0xAD9C999A8B9461FAULL, 0xCA541A26BFA815B4ULL, 0x2F314B5DB9AC0705ULL, 
            0xA491C5D07A2C6F91ULL, 0x8875D96F6DD01063ULL, 0x52362F5B8FE06482ULL, 0x467E1C2B418CC833ULL
        },
        {
            0x7362812688402686ULL, 0x74AEDA0394DE2323ULL, 0x4CC3D57DB14CFC53ULL, 0xE965146A31AC24D8ULL, 
            0x7382178F39AADD80ULL, 0x81E9E8D54E0A51C6ULL, 0xEC67ED188485EF79ULL, 0x223AAB0C10E9675AULL, 
            0x27E5F63C37AF93D4ULL, 0x09BC49FBDE2AD4D4ULL, 0x52D2C98B8FBB72F3ULL, 0xB031D9E1923F601DULL, 
            0x8F9692ED6E80C34FULL, 0xE6D4B70A70EB2CE5ULL, 0x4F85524E31E14E66ULL, 0x47BFC709431C65B6ULL, 
            0x574A6AE85303027FULL, 0x35BDE169E5E0EC1FULL, 0xA1F17886AC99C716ULL, 0x8B0B3FCE751B6673ULL, 
            0xA0C9BC1280657031ULL, 0xEC88B4AE425F416EULL, 0x381C50D2E6B9C3E4ULL, 0xB44639F5E2F30140ULL, 
            0x83BD0EE6B7B8F6FBULL, 0x1838FB7001D99727ULL, 0xF0F499E705C5579DULL, 0x4390F37F025422C6ULL, 
            0x49283FB364B1B525ULL, 0x41A43143F3296867ULL, 0xA74C0067B1E565D2ULL, 0xAAF4AEB973DE693BULL
        },
        {
            0x94DA56305A4A413DULL, 0x8CAEC8E72FFBEAD7ULL, 0x1AC76C050A4EE30DULL, 0x09A104DEF4FA34D0ULL, 
            0x7DFBA49FD1B27D0FULL, 0x1A74C19043058FCEULL, 0xE2DDC00A4AB33364ULL, 0xE99577E38A4AB3D0ULL, 
            0x87652E687BFEF65FULL, 0x2497604F913B68CEULL, 0x64F4895AD70B0A9DULL, 0xF5F8599B96D1B1ACULL, 
            0x40B5E7D2012985FBULL, 0x74D07205CCC3D023ULL, 0x0481352BBECFBBFFULL, 0x073FF52F19E5B60EULL, 
            0xB4AE5E6D9B6A18B2ULL, 0xB55C823025024D7BULL, 0xECC87B781D1245FFULL, 0x378926A2C510396FULL, 
            0x7DDB5826F4A93F29ULL, 0x65DDDBC3C0A82528ULL, 0x4B387AEC3177C5B4ULL, 0xD9F21FD6C0CEF7C4ULL, 
            0xE0221AE1BB937495ULL, 0x0A96CF03C0732313ULL, 0x7AAC5172CFBC5C4AULL, 0x2667A629A208897DULL, 
            0x30185DED10870B53ULL, 0xE4E0B7D0EC7C4A87ULL, 0x4945BCC3EAF5D1A8ULL, 0xF7FB5ED02FEF0BBFULL
        },
        {
            0x1B30042C5ED70390ULL, 0xC9046944B6B34E9DULL, 0x5A4E5324B3B4BE40ULL, 0x236587BC332F047AULL, 
            0xCDB582F23C2C9D04ULL, 0x45EFF2978CACB92EULL, 0x5E2AD14B12CFAC30ULL, 0x26B1AE6365A75BBBULL, 
            0xAACDE1D0E0EAF9E6ULL, 0x9C547AD53CED9CCDULL, 0x014282518D995028ULL, 0x06C913769997F8F8ULL, 
            0xAC5A971114144208ULL, 0x9886A6AFE3701B1AULL, 0xE6CEC940ADB4CED7ULL, 0xF48355EC2EDD43CFULL, 
            0x99915B5008BD052BULL, 0xAB4B8C0CB06BF9FDULL, 0xF8DBE2FB45C7C22DULL, 0x36BDBE9C8E33D572ULL, 
            0xF0D785C6CC920C36ULL, 0x76488DA7733B6391ULL, 0xF308FF09E2CC564EULL, 0xCD1A966E27962881ULL, 
            0x8A44151C517A111BULL, 0x989ADE5948369D3EULL, 0xB204F114A3283F53ULL, 0x8D4414684FFF5FA8ULL, 
            0x36D8BE4C2D5EEF9CULL, 0x608E2B1729F244F3ULL, 0xEFABC5FB57051A7EULL, 0x192C6FBB2E8885EDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseFConstants = {
    0x2B1A01CF29E7C8E4ULL,
    0x95462F626ECFAEA8ULL,
    0x651939D7CF599CDFULL,
    0x2B1A01CF29E7C8E4ULL,
    0x95462F626ECFAEA8ULL,
    0x651939D7CF599CDFULL,
    0xD19EE7B750773B05ULL,
    0x4AAD4DD2F93A036CULL,
    0xAD,
    0xEA,
    0x8A,
    0xB1,
    0x1A,
    0x1E,
    0xB8,
    0x84
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseGSalts = {
    {
        {
            0xDF19ACD509F6D0A9ULL, 0x9A4741A5E04BF571ULL, 0xC062861B15B264BEULL, 0xC530F67FFB5E2130ULL, 
            0x22EDC130C38FB726ULL, 0xD03028427184CF7FULL, 0x753C04383E9D8D8BULL, 0x4C1EE5CE99952D26ULL, 
            0x3CAD5FA81C70E88FULL, 0x137D69629CE66312ULL, 0x9E05161C51DD44C9ULL, 0x800F31FE38BAEAA6ULL, 
            0x3C8BBEA042A6E9CEULL, 0xDF1A806538B157E7ULL, 0xA61F296A81958CE1ULL, 0x385467AD243DD83BULL, 
            0x281C195C7715DC57ULL, 0x02AF9B71767FCCB1ULL, 0xF5F80A5690B1EE9BULL, 0xEE6AE076CB26F4B3ULL, 
            0xA01A209D2263B50EULL, 0xF5CF75061FAABED9ULL, 0x8DB38E15E7CBD615ULL, 0x747A28A5A22F8BA1ULL, 
            0x79185A8292F1267FULL, 0x3A237B1E7CF43786ULL, 0xADFFDB6AF1487747ULL, 0x133F45BA969D9097ULL, 
            0x365C9016D25CAC50ULL, 0x5B440DCC9E1C0CE1ULL, 0x41A889DBDEC9FCC3ULL, 0xE384E81624383C88ULL
        },
        {
            0x5CAB74D87B1B2B63ULL, 0xCE6A15ED0495C6CAULL, 0x07B7FAB8B0D9EA5EULL, 0x79ED3539D4815CBBULL, 
            0x7A381D89DE6F4730ULL, 0x22A4C2F1FC320B3AULL, 0xBA5E5154628EF009ULL, 0x9C41EF3E3FED5F2BULL, 
            0x2F22B62ED0D0836CULL, 0x75513BCAA20CA2CAULL, 0x4FEE139D6FB58F09ULL, 0x508568F138C4DBD6ULL, 
            0xAE04A882E4842F14ULL, 0xF9A582F3726E10E9ULL, 0x1C2E5B62285F869EULL, 0xDA64FBA2962E8ECCULL, 
            0x12BDCD5038854CE1ULL, 0xAD4D255C7264611EULL, 0x622295184AFDC9E8ULL, 0x60E74E94616A63CBULL, 
            0x5FC9648F0E96D37EULL, 0xB0E7CE66F7D97794ULL, 0x77B24CB54D3167B3ULL, 0xB646961F98BCB4C4ULL, 
            0xF9548583CEF52052ULL, 0x409E4F750255C078ULL, 0x98DDC8CE3B3A526AULL, 0x83A5CF4A54F28552ULL, 
            0x6D6CFB52DC1BFF70ULL, 0x38699C833C1089BAULL, 0xE027B02FE5E5463BULL, 0x0B732892564A3A95ULL
        },
        {
            0x5B8C0A7858758F9CULL, 0x40637CD214B6AB64ULL, 0x62F359F2AF020156ULL, 0xD03354FAE61CAEF5ULL, 
            0x6304E50E50E8F084ULL, 0x0B37C25AD92C94FCULL, 0xA96483D5437F5315ULL, 0x481B9FB352CBD520ULL, 
            0x71E4662F28671170ULL, 0xB5F54FAF24EC5B4AULL, 0x0248E3DC26039C68ULL, 0xAAE7B2A759FA54C2ULL, 
            0xCAE3D6D929E87E84ULL, 0xA1B25E6392C8CD66ULL, 0xD1B60C1949491371ULL, 0xFA35D3116366C5BBULL, 
            0x6A5D425AF129F254ULL, 0x6E110F06A008711CULL, 0x2DE683B79BE65073ULL, 0x810647CFBA985624ULL, 
            0x3269856DEAC57BD9ULL, 0x54BB6F3192620352ULL, 0x51A73E4739A55D34ULL, 0x879EAEA43B249D83ULL, 
            0x6DA871D6D8BC4F33ULL, 0xF7E555285A6ACE0BULL, 0xC063B4D12861E1E5ULL, 0xC070E4985BFF1E4FULL, 
            0xE5C1347FEA040F72ULL, 0x0C42CB6D0E167D43ULL, 0xC8E140C6A85CF87BULL, 0x5C3277406F07667AULL
        },
        {
            0xC905AA0CDE4513E4ULL, 0x82F88F6DE9BED2C3ULL, 0x4153362F9C757E68ULL, 0x66D1BF5A8229DB83ULL, 
            0xAE61556B450433A9ULL, 0x6DA15066B319ED08ULL, 0x9189BFE26C0DDE16ULL, 0xD032D3ED39A84827ULL, 
            0x91833650565FC670ULL, 0x717E9521202664B4ULL, 0xFA536C01144D154CULL, 0x88CB92648DCA4F4EULL, 
            0xF04694A63A05CF28ULL, 0x1C3F07F8389CD8FAULL, 0xBD8CAA44E5C2ECDEULL, 0x169D17B5C2388526ULL, 
            0x25EDB1E1497472AAULL, 0x18307EB707F6FBDFULL, 0xBECBA0E7BBE43951ULL, 0xC9282FE200F50DFCULL, 
            0x86E6C51FB37C9A18ULL, 0xE41660C6E291C07FULL, 0xB52EC1EBA9ABE693ULL, 0x70DF609C058F0F71ULL, 
            0x5D0E0A9C218DA893ULL, 0x7CB7AA60B3AAAEABULL, 0x9529401923141986ULL, 0x3C80A33C92DC9BE9ULL, 
            0x800812A9B1FE3BAFULL, 0xACE5B14B328ABE90ULL, 0x07C713343F9B047BULL, 0x768908F254FA527FULL
        },
        {
            0xD01A747C31000642ULL, 0x518479DBA047F18DULL, 0x4422F21BD97C0742ULL, 0xEB0F9C177B5B5A1CULL, 
            0x26EBE7127C324BA0ULL, 0x718D0FE918E27144ULL, 0x63E7E44E4C656045ULL, 0x4398163EA313B637ULL, 
            0x282EF2CF06659536ULL, 0x876E940934D409AEULL, 0xDBA69F50A70BD47BULL, 0xA03CB88EB09473EEULL, 
            0x3FD3AC63E6D519A4ULL, 0x3D4301DD9FA4DDE7ULL, 0x6C79A07B4E27D94CULL, 0xC5A943D6CE430E77ULL, 
            0x349544DD911F1AEAULL, 0xAC289495663E33E2ULL, 0x136B4C6B855CC917ULL, 0xF01F68381515FA31ULL, 
            0xBD8ECF0496CDFAD7ULL, 0x8CDB317F55F121FEULL, 0xA34C1C1DB40DC119ULL, 0xDADA26869E9B162EULL, 
            0x82EC92BF9CD3AD0AULL, 0xBB3EA26991804F3EULL, 0xF3369ECDADD1A919ULL, 0x55F6BECD40C3520CULL, 
            0x3B8D44D7132B7909ULL, 0xB4947CA6BD28F5BEULL, 0x679DEB0318A3808BULL, 0xCA99BBC09984C051ULL
        },
        {
            0xE01710AD2998E033ULL, 0x8598AA7D53A7AF74ULL, 0xDD70906376A4DF96ULL, 0x5D7D42A9EBA267AFULL, 
            0xE7E0EF38080C5528ULL, 0xBD564B15D9896424ULL, 0xAFC3786981A9B4B3ULL, 0x966CB91BA186AC66ULL, 
            0x7E926C79F6CA6EDBULL, 0xD451BACABA87BDE4ULL, 0xD3D098A1FDCCDABCULL, 0x55879EA924B7B30FULL, 
            0xE484336E56AC6B38ULL, 0xA6E924E5F2BF9C62ULL, 0xEE18F9003F7A9F3CULL, 0xF46105B94814E501ULL, 
            0x0D2CD8C51488648BULL, 0x5066416B9723751CULL, 0x86CD8D5162056474ULL, 0x5926166413FA4DAAULL, 
            0xB80CF6597A616152ULL, 0x6C48AA13813EF16BULL, 0xD688CF9A6F031C2DULL, 0x406D6738A34EC6FFULL, 
            0xDBFAC788FDF7D866ULL, 0x7B75F76C962B7DD5ULL, 0x46EFF7CE266CDB7FULL, 0xA0041B17A1FC6A10ULL, 
            0x8C3680A1893B4AF8ULL, 0x9D736ED227909003ULL, 0x3F0FA6EB9BF997C4ULL, 0xE8E185E4C0076F83ULL
        }
    },
    {
        {
            0xDC7376B1A62490FCULL, 0x65B3A19AD5A2328AULL, 0x3412E665CBD6D7EEULL, 0xA8DACEA2AF2B44D2ULL, 
            0x1FF7EDEA1B38FC00ULL, 0x4D278128DB03643BULL, 0x00F2B4EEA753C558ULL, 0x537D78EF721E3AB5ULL, 
            0xEC17E729BE3B1BADULL, 0x3CA31E0D730019E7ULL, 0x67ACE3F40307CFA5ULL, 0x91FFCD805B3B2161ULL, 
            0x4D4A825663E0944DULL, 0x7656782A89EE36A2ULL, 0x352D8984969BEE54ULL, 0xEE12E6BFE28FFFBCULL, 
            0x8F7F012B6BCC5B8AULL, 0x0A6F6503BC48896DULL, 0x30E7EA37E33DB345ULL, 0x1FB54580208B687EULL, 
            0xC031EE1D7BCF5026ULL, 0xF872B1920FD94E3AULL, 0x0E9469DCF9AE695FULL, 0xB1F0ADE4EFDB7A75ULL, 
            0x93624B722E0B904AULL, 0x55DFAFBF7E2C290EULL, 0x0A367101F23BD582ULL, 0x505096E8E542ADC3ULL, 
            0x785066A41DF80FF0ULL, 0x90BA48D922A0CBEEULL, 0xD0FF9A53145B7346ULL, 0xA319E447829979A3ULL
        },
        {
            0xB448851385FAED01ULL, 0x1B73622AC308DA3AULL, 0xFD1AB98851129131ULL, 0xA6BF78A110C103E4ULL, 
            0x8C24BE81D235F5DFULL, 0x30E95B983FFD8067ULL, 0x0F019E54798E0781ULL, 0xD8BBD8E49FF79DF1ULL, 
            0xE55AC3A147622B3FULL, 0x7FE120AF6A207EC4ULL, 0x47A3FDD7FE633A36ULL, 0x1C2E9F403AAFF7ABULL, 
            0x1093EAB65C66AAC8ULL, 0x6F68BAE99690D140ULL, 0xB1A2A064EBC20024ULL, 0x193B098B8C257BE3ULL, 
            0x82F78E9D33ADC7CEULL, 0x8E3A90FEB330DA79ULL, 0x207B7F1F7FCB80C8ULL, 0x9B34031EA536D636ULL, 
            0x905FFAAC10EABB12ULL, 0x4AD64AC68A7A808DULL, 0xBAD0CDF9E93F3B48ULL, 0x209B2B6AE2EBB330ULL, 
            0x0087C84CB049850BULL, 0xC56559AD3C970634ULL, 0x10F3B7ACDFFE7532ULL, 0xB605ED4BE72C99FFULL, 
            0x1D72C0D81C7D04B0ULL, 0x5489520E29670054ULL, 0x1775642F0EC8A6EDULL, 0x46BF6358244115FFULL
        },
        {
            0x46435C4F71B3F036ULL, 0xAA3777EEC1CA3B58ULL, 0x2C4BAEF710C6937FULL, 0x49D1B2E2C1F88180ULL, 
            0x04C9E2035126CF92ULL, 0x29798ED25775FE7EULL, 0x3B0E6E2DE6E655BFULL, 0xA9BB698D9AC50716ULL, 
            0xE1D6361BE4BD2BBBULL, 0x792F43AABC4AB7BFULL, 0x50DFDB57C9C8281AULL, 0x1D3CFB1591E7C8A8ULL, 
            0xE0E97BC2118632CCULL, 0xD61C78DD0FEBB4DAULL, 0x6E6B383FCD6704FBULL, 0x2819D484F74CFAD4ULL, 
            0x82D3511E13D4528CULL, 0x4C9463ED36E3AA18ULL, 0xB9F155619AA28580ULL, 0x3356D7C88781DAA2ULL, 
            0xF75EA112290828C9ULL, 0xA73C7B2118383B05ULL, 0x0C091B42495B4385ULL, 0x7C7EB1F325A85E0FULL, 
            0x4DB2EAD9EB445D84ULL, 0x18C2E4712A213DA4ULL, 0xB2B57D155AF0343CULL, 0x4FA3145452418B47ULL, 
            0xC1406C885C1C85D4ULL, 0x9C6AB0EB19A5D034ULL, 0xFA895C7FD345B36AULL, 0xD47A60341E1E10C2ULL
        },
        {
            0x4A94D52422E781FEULL, 0x3FB8C29D2F74CFB2ULL, 0x44F2EBBFA304BB26ULL, 0x05D6FE9A7AF9B1E2ULL, 
            0xC72ABCDB985A69A4ULL, 0x99EA213FB2EC700DULL, 0x13B2DBEA65A649A2ULL, 0x84BD3CFDACE821AFULL, 
            0xD94D7AF6C33CA1ADULL, 0xF03684A79F0AB3F9ULL, 0x230239D79CEDABDFULL, 0xAD60E3ED6D6EFC5AULL, 
            0x579BE9F0F3F4BBC4ULL, 0xD01178B0718B7BC4ULL, 0x755246ACACC153E9ULL, 0x187D7865535B0BB0ULL, 
            0x08CA1CBC67686363ULL, 0x20E7A2C5743E4F96ULL, 0x94DD13329AE051C6ULL, 0x8E358B160C732F5DULL, 
            0xA0FC7233C28AFE6BULL, 0x8EF0E99CA280F53EULL, 0xB52260990329A98DULL, 0xFDBFA00959F440EBULL, 
            0x9A7885DAF6B50B27ULL, 0x2918B33565B1F805ULL, 0x9DB0EB0885E3A0BEULL, 0x345B26F04B958617ULL, 
            0x05E9F7BFF96D8AF8ULL, 0x435A04EC31928E5CULL, 0x95D474793C49631FULL, 0x8FE1BE81E13B81D9ULL
        },
        {
            0xC5B6A5E6F34FCBDFULL, 0x2FFAAA15C95FEC78ULL, 0xAED2877A5E92B650ULL, 0x8AE0C5024B9BEF84ULL, 
            0xBDC1424CB52215D6ULL, 0x0EAB5C975940987FULL, 0x58DB20572DBDD4D7ULL, 0x1571CE4797658A6AULL, 
            0xE73B5DC259572610ULL, 0xCF5DDC23CD09C21BULL, 0xC8E3DB30D254C035ULL, 0xBDE07D01791B17A5ULL, 
            0xF1D4A27EDFB55083ULL, 0xD583AA77D077E84BULL, 0x7EBF85E58F8CC816ULL, 0xBC8D2647C473C008ULL, 
            0x5336D94AAA1C7583ULL, 0x4B90088CDB719982ULL, 0x9AFF0F4B7376F400ULL, 0xAB7388A643AA4D26ULL, 
            0x979C319E3838537CULL, 0xAF9D01FC13F01E32ULL, 0xCF27E7ABB8115D17ULL, 0xACB053EC884FD4B8ULL, 
            0xB3205E64829BDAD0ULL, 0x14981E3561EA38FFULL, 0x7D71D8BCB3B7341FULL, 0x431BF8B45C60484AULL, 
            0xCC74189F5FD8EBA2ULL, 0x774DB027C720B851ULL, 0x4E87AAA8EF70B26AULL, 0xF591411F86ABB241ULL
        },
        {
            0x647C0207D3B7809CULL, 0x35B778BF69A384D0ULL, 0x7930DD51CF12CEADULL, 0x2C2171463A77B59AULL, 
            0xC5310E9B2B374CBFULL, 0xFCBCF16ECA8700AAULL, 0xA92AD941248F4139ULL, 0xA55FF887623EE411ULL, 
            0x2D9AD92667F70F78ULL, 0x496AD02067B5C99FULL, 0xE4C1F6685592C7C9ULL, 0xF2AE5DF4DBA4D405ULL, 
            0x750342106FF29EE1ULL, 0x5317CE2D7E201177ULL, 0x5178AA360BC397C1ULL, 0x6590B05BA8F6936DULL, 
            0x6AC1B6AC1559E38AULL, 0x9E6B684E0233DBC6ULL, 0xFF51EE4DFA1626EBULL, 0x9DFE5816DD387A2FULL, 
            0xAB2050935307F90DULL, 0xAF182A6DFF756B6BULL, 0xF2A7896622D3074AULL, 0xB644FDFA8CD2A31FULL, 
            0x81022277D760E15CULL, 0x960F991AB3845D19ULL, 0xD03060452E1B3525ULL, 0x04D39869CDFB66B9ULL, 
            0x4C86EDE1CB35D3FDULL, 0x80150DE52B60BD78ULL, 0x32424413F19228DFULL, 0xC22F38C98798665DULL
        }
    },
    {
        {
            0xEB6B2529B0A36FEAULL, 0xF0CB188E7A2BF783ULL, 0x62C80538C3BB8C68ULL, 0xC468A8245AC1B707ULL, 
            0x278E500741180BBDULL, 0xB7FD01D2594C2DC9ULL, 0x6BD4A74A367D5EF0ULL, 0x4D6AFD588CCA9C97ULL, 
            0xA285ECCC1B5C04CCULL, 0x5973AB6C60E51A6DULL, 0xBDD2B8E85651EF44ULL, 0x28B3BFF4F23F7CF5ULL, 
            0xE7D0BAB80765162DULL, 0x877A4E5BD34ED95CULL, 0x04A0F36C594B34B9ULL, 0x3DF34FF1A8661DADULL, 
            0xAFB97605ED5A631BULL, 0x6E4EE74E87CAFD2EULL, 0x84619211EA56BB17ULL, 0xCF4437C5DFE9A05DULL, 
            0x026BE00467071194ULL, 0x37AA26E79FECE50AULL, 0xB868D13FBCA41A9FULL, 0xD1CAF94387299D91ULL, 
            0x4C5A1FAFB6727C47ULL, 0x2B50BB766CC6E75AULL, 0x76218DDBBF295522ULL, 0x8869DEFE4670D94EULL, 
            0x5FA9F6BA9683C50EULL, 0x6B56D08AC773C899ULL, 0xDF42582A2EDBA553ULL, 0xAA2FAC684085D1E5ULL
        },
        {
            0x6581FDABC815C825ULL, 0xF6630A044FE270D0ULL, 0x135B3AC5B4F64266ULL, 0x5E47619CB56169D0ULL, 
            0x31D974A294A5A767ULL, 0xB5F4C39C48392C18ULL, 0xF613A059E2FCCD40ULL, 0xDEB6005B2B96F293ULL, 
            0xA9DBDA59117FB511ULL, 0xBC54252B1E121622ULL, 0x090D2EC7CCED633BULL, 0x49FF6E368D0D1A5CULL, 
            0x8F54CCD62BBB77AFULL, 0xE609B114FFDDAD75ULL, 0x9EBF49795F183A3EULL, 0xE8746DCA207F511FULL, 
            0x651AB6F0065561EFULL, 0x25CC22E9D63E4E5FULL, 0x3FFDDBB539105EF4ULL, 0x65327BFE8D5DF7EDULL, 
            0x212C457E14502AFCULL, 0xA0FB3872A5EC4AB3ULL, 0x708CCD3D6F569D03ULL, 0x7877CD28922FAEDEULL, 
            0x4370807B15BADE17ULL, 0xDDFF885DB428F9DAULL, 0xE986FFF27449129FULL, 0x6BA3F514380EC2F2ULL, 
            0x88DCC64246F74134ULL, 0x3C2EB020507E270EULL, 0x4C8F64238D73C255ULL, 0xF4D5C4075FF9920EULL
        },
        {
            0x0E5E1115A8F9F4EAULL, 0x16ED44BA212A5358ULL, 0xD21EC4156204F956ULL, 0xB7531F20E3F9FF46ULL, 
            0x336717E91B9EC661ULL, 0x1EEEEDD54D937E48ULL, 0x2AF88A6D231AFC34ULL, 0x3551794F9608CA3DULL, 
            0x0BD7D48D19451894ULL, 0xF678ED5F81364052ULL, 0x7BD936719B72FBD3ULL, 0x333BFD44EE530FD9ULL, 
            0x1249AC288FE11029ULL, 0xF646195964FD8FADULL, 0x9507364A1A2D0F0BULL, 0x4A9C834793108469ULL, 
            0x73EE6F70A074B038ULL, 0x6582905F1D42EF76ULL, 0x1A6B27C37A0694AAULL, 0x2F50687BDACF5C48ULL, 
            0x28CD5375A04CFE76ULL, 0x894AC674E59193E7ULL, 0x63898BAA1C8207EFULL, 0x7F5D930CD8925C3DULL, 
            0xC8EB9ECAD1A183AEULL, 0xBE1CAA5C89C57D40ULL, 0x6CACE745AE708352ULL, 0xF4049285E1104D7EULL, 
            0x1D316D562807496BULL, 0xE15FF3AD7F8B5C54ULL, 0x6F6A23F73E38A785ULL, 0xB1B739005CE02F85ULL
        },
        {
            0x5E32CE8340863603ULL, 0x836609C0FA12A96BULL, 0x69FA89336ADE9236ULL, 0x672E1000988B89EDULL, 
            0x4ADD51DAF761E785ULL, 0x4D82C2257B710BFAULL, 0xBB501BE68FD75EA7ULL, 0x9F645CA8794E6286ULL, 
            0xB9B18A2BECF72311ULL, 0x2BCCCB1AC385A5D0ULL, 0xE6FEAED7770B50A2ULL, 0x9A2E6AF6A2972DD0ULL, 
            0xBB3BE0469D52EB30ULL, 0xC4C5481031FF5651ULL, 0x35FB0C1D599A2450ULL, 0x53535CCC34438487ULL, 
            0x0DFA8BCDA7AE40B2ULL, 0x2223604A26BCF243ULL, 0x95BCE125640F478EULL, 0xCF3C5D648B2909D1ULL, 
            0x7E5D414058F7DC3EULL, 0x987F903128C6518DULL, 0xE3EA02C1D080584EULL, 0x9F76B0EA7D615343ULL, 
            0x11D662A29463B44CULL, 0x9CF0E90E2A8B0675ULL, 0x48E2651803391E75ULL, 0xDDA10FAC0183848BULL, 
            0x95C5D484249EA810ULL, 0x2E9A0649F82AC144ULL, 0x2C4ABBCFB01AF1DFULL, 0xBF2717ABCCD42E18ULL
        },
        {
            0x4D1E3D99CD7C54ADULL, 0x821C3AE3AD86A6F1ULL, 0x86F80AB56DF9D70DULL, 0x60E6EE62A717725CULL, 
            0xDDCA9BD6F9E54FE7ULL, 0x80B6E011C1AEF5A8ULL, 0x91911933D498F338ULL, 0x8051BA5587CCC05EULL, 
            0xC7AFB03A05E997EBULL, 0x74CA48D208AD5279ULL, 0xA1CC00014D4F5E1EULL, 0x5192B5E988C15751ULL, 
            0xECAD9381F4164C97ULL, 0x4A3159043465D45FULL, 0x01D18DCC2BAA7A2EULL, 0xAE1DD2DB539E3024ULL, 
            0x29C1EEEFDEC512AEULL, 0xD3EED9B9C46C08D4ULL, 0x2D76CD3300D6482FULL, 0xD2E2A31ED5F410A4ULL, 
            0xAE39A142310E766CULL, 0xF91C250BEE276F1BULL, 0x23378AD24CA77A79ULL, 0x9EAC4F22FC520D9CULL, 
            0xE2CE920E78C5DCD7ULL, 0x77EC381FB7AE9C54ULL, 0x39A1149CE2D1060FULL, 0x2E12EF16654FF6E6ULL, 
            0xD95AFDC7DF33C94CULL, 0x9CC66DA1C4796A1AULL, 0x119F2EEC182A7032ULL, 0x510FEB8E3843E739ULL
        },
        {
            0x21466BC0149EC0F9ULL, 0xFC17C4B482A206FAULL, 0x10797A09691DF296ULL, 0x670465D4E8D1987CULL, 
            0x7CEE8A2A2F7D2450ULL, 0xB6FB42DB48D2FAFFULL, 0x6B40611134B1C16EULL, 0x2A1F6A4E04EB6D01ULL, 
            0x031EC5B0EE885605ULL, 0x21BA31BC2A379E03ULL, 0x1F8492AD2B290D60ULL, 0xBAAA50B86E5537BBULL, 
            0x48F388CCE78FA673ULL, 0xD921885C63C1C58EULL, 0xCEEC1D6C355F36F2ULL, 0x7C7FDE683700E62DULL, 
            0xC0E1BC0BF15BFBB3ULL, 0xB1CCA076EB31332AULL, 0xC4F5A2DCD29CA083ULL, 0x495F798D6D40F234ULL, 
            0xF42B775EE1C20383ULL, 0xC2EB181A7C39B004ULL, 0x39A1003820BB2D7AULL, 0x2399C865285ADCCAULL, 
            0x128877F781DD0985ULL, 0x038C474E50682C81ULL, 0x01B0050839FBCBFAULL, 0x38ED4F210DEC825AULL, 
            0xE4F072911C03A424ULL, 0x7C8A6A217C68E756ULL, 0x79A557F1FF080760ULL, 0xEEB439CB0F447544ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseGConstants = {
    0x19ED58DED9F094C1ULL,
    0xD2E4613DC3956B9AULL,
    0x5DF9BAA048B764F1ULL,
    0x19ED58DED9F094C1ULL,
    0xD2E4613DC3956B9AULL,
    0x5DF9BAA048B764F1ULL,
    0xF16E6386B156DF89ULL,
    0x28809BA27836D7E5ULL,
    0x04,
    0x85,
    0xC2,
    0xF9,
    0x7F,
    0x7F,
    0x77,
    0x3E
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseHSalts = {
    {
        {
            0x01EBA015449CD8EAULL, 0xDE0B4F52CAB595F7ULL, 0x21C03924DD291F9EULL, 0x1B8DF5F2C650EDE9ULL, 
            0x83BD602611FD2EF9ULL, 0xDAF239907BC8B56FULL, 0xA52B4D9AAA6D08AEULL, 0x6324980725FE9F91ULL, 
            0x88F6A0AE3D349D13ULL, 0xF991B3A5D284C243ULL, 0x405BDA9D45AC40ECULL, 0xFA342304F2D6E8A4ULL, 
            0x54F2F78F7DB839ACULL, 0x11DC96EC28BD5022ULL, 0xA9E68179EB0B178DULL, 0xB965EE12C0795F7BULL, 
            0x0159D69908C560CEULL, 0xFD660597759470CEULL, 0x577EA0346D2691F1ULL, 0x8065324A4501A6DEULL, 
            0x082F04FE48AC2796ULL, 0xAA3AA367EA8F7D1CULL, 0xBA805B82C4DD57BBULL, 0x85FFA1A9F9FC70CEULL, 
            0x03CBD9B5ED921600ULL, 0xE8DA7541FA9055E7ULL, 0x1C71FA1697CC59FDULL, 0xECCF09E5A029E01BULL, 
            0xCFC3CA22C6129020ULL, 0xC2C56870C16A1C69ULL, 0x148B22EF8DFCC9F9ULL, 0xB3C18DDB6E6F5246ULL
        },
        {
            0x5A265E0806853A09ULL, 0xB2C1B925919E50D0ULL, 0xCB951BBF0D3F66A6ULL, 0xC215426ABD1E98DFULL, 
            0xF59EB2F9BBC401B5ULL, 0xB8AF4CE733A4D0CDULL, 0xB7DB9763863BBD6CULL, 0xD28D69DFD55ADB0BULL, 
            0x514C8470A3313AC5ULL, 0xBAAE20F48D26BB9FULL, 0x1D6ED46D9F2811CEULL, 0xFCE1DFEDD70039ECULL, 
            0x3A983FFB101FDC7BULL, 0xDD913EEF74AE031DULL, 0x47091113BF788DB1ULL, 0xD30E3F36F46A5F27ULL, 
            0xF9C27BBECB92EA48ULL, 0x66D5B0D3881B1058ULL, 0x4E54AB5673D093B7ULL, 0x79594C5ADB21242DULL, 
            0x39B7BDDB645CABE9ULL, 0x5A7CEFBED99C5426ULL, 0xD43265420435BC79ULL, 0x3F004CC3B7070204ULL, 
            0xE2EEC49A7E991207ULL, 0x747F8799E932068CULL, 0x96EAF21C6F3F63A1ULL, 0x9BC99C5CFC1F1DB4ULL, 
            0xDCBF1A8B95E4CF54ULL, 0x0318E68FF164616DULL, 0x33F7A8C55CE6B220ULL, 0xAD93013CBDC64A73ULL
        },
        {
            0x7BFF951C773AFF94ULL, 0x296A365A2AC4DCBDULL, 0x059B0D0474A8E1B6ULL, 0x7E03BD634EEA4755ULL, 
            0x3D64DF2B8692B629ULL, 0x2482D780D077D7E9ULL, 0x6716CFAC0AC0E062ULL, 0xC96F5C50B4623895ULL, 
            0x2FB685F175960958ULL, 0xBBCA09C43F2DDFEEULL, 0xB1C846FD325904A2ULL, 0x3C9B66C846D0CA05ULL, 
            0xE1BBD4FB4304116FULL, 0x4A05B7059FEA6ECEULL, 0x9796A717C12B423BULL, 0xBC4AC394CBC3CA28ULL, 
            0x7AC899726001CB1FULL, 0x1DD4244A03B5F5B5ULL, 0x3D8779CBA1940964ULL, 0x680494626183FC24ULL, 
            0xD3D8940EDCAD66D9ULL, 0x97D1B2F078D3615BULL, 0x520F22F17A9679FAULL, 0xB149C87D4AD36DAEULL, 
            0xAB94817032F25F8BULL, 0xB09A63806623BD73ULL, 0x4C02A5F172EC82B9ULL, 0xAAEC0E32C79983F0ULL, 
            0x65A64F2E9C3B1C9BULL, 0x3A781874E3A98CB3ULL, 0x81972592D00CF1E6ULL, 0x926648B826EAC8ABULL
        },
        {
            0x352ADDAB052B77A1ULL, 0x0B3F0D951E3F376BULL, 0x3F24FCE8B3759633ULL, 0xBFCACA39E1E1E7BBULL, 
            0x71756D6FEFAD998EULL, 0x19C766D6538AEEE4ULL, 0x00DD222D3759C71AULL, 0x2BCA495C02E681F8ULL, 
            0x14EB8E4DB4419396ULL, 0x8694A1FAEF74C6F8ULL, 0xB9F4BDCF646351C7ULL, 0x3CFA2CE31DCB66C9ULL, 
            0x2C0430882BE55B85ULL, 0xC7391B631C8A7002ULL, 0x59AF1AB35D23B889ULL, 0x88FF0019D5EC0388ULL, 
            0xF991BDC147F50401ULL, 0x8A00C600F2A70F7BULL, 0x65C740652037F614ULL, 0x74C326A6FE43CBA7ULL, 
            0xD509D8C93110BB81ULL, 0xAB145EBC92185E99ULL, 0xFABE516B68B585EAULL, 0x271C8DD62FC812B0ULL, 
            0x708D13029B7B7BD3ULL, 0x4D5EF7A725C38AF7ULL, 0x78AE89D966FA5E67ULL, 0x000915862DBD6E3BULL, 
            0xBC64CE49E58D8B80ULL, 0x7002727E9B6FB4DFULL, 0x68EFBBCCD919A8B2ULL, 0xA44B7AEC4659113FULL
        },
        {
            0x588C4C5482AD3B1CULL, 0xCCF0FF0FB24CBA2EULL, 0x0EE13F104461617EULL, 0x7FB34834DBFDE928ULL, 
            0xABFC500C5740922CULL, 0x3C987549AF0E8248ULL, 0x034FDCDB32DF3A21ULL, 0xC578C5BD2821E125ULL, 
            0xB98727801CF41BBCULL, 0xAA3942A767DB0B81ULL, 0x9A457BBD7EC8B719ULL, 0xA39381421F0E7502ULL, 
            0x063AB4978C3C1BF8ULL, 0x43CD33723DCD21FAULL, 0x29BAB742B40ACEECULL, 0x75800831B29FDB4FULL, 
            0xC3D3AD635279F699ULL, 0x319B158F561D5CEAULL, 0x77DA9B9B4DC7FA05ULL, 0x56D8B7972770580DULL, 
            0x5EF26A5E57C7DF2FULL, 0xDC0B16062D12EA6FULL, 0x029E2427AFD1075BULL, 0x2642CE74C71E9BC4ULL, 
            0x3F98BF89B5A0883EULL, 0xEFB27515ED0BAE30ULL, 0x1E9C8D3D219284ADULL, 0xF364F5125DED3D2AULL, 
            0x40FF3E42CD2876BDULL, 0x3F08EE0C3E9D9ED2ULL, 0x04F6BA9684235A22ULL, 0x1FD6DB0C00C723ABULL
        },
        {
            0x018FBF4E094C9658ULL, 0xF124571BD5E513A3ULL, 0xC89C9091843A88C3ULL, 0xF75C76A2147C7F01ULL, 
            0xB0C8C21EA583BB04ULL, 0x41E9A6FFA3122CCAULL, 0xFB154402A6C538EDULL, 0xDE0590B9B9F685D0ULL, 
            0x84333920C2BE2E2CULL, 0x8E16A9DA9ACC9529ULL, 0x25C26FFBAE98FA6BULL, 0xC1CC18832E6AD954ULL, 
            0x1EC1DE4295F4C628ULL, 0xE4CECE383DC20441ULL, 0xCC6E0312B829A1ECULL, 0x0D077CDD01DBC2B0ULL, 
            0xE43908DDF39DC2A1ULL, 0x5CE3322EDD293FA8ULL, 0x594B002D6A0CC777ULL, 0x3C9B1C46107F2109ULL, 
            0x48ECDA3CB7CEFFF1ULL, 0x7763A059998F5BA0ULL, 0x24B4564A44519C99ULL, 0x2ABA49A52154E462ULL, 
            0x8164CB5188BFAA70ULL, 0xEBCB053B4396A018ULL, 0x148FE63942D29904ULL, 0x6157078F5D46E203ULL, 
            0xA8FF47A282CC23D0ULL, 0x2B6B925192D63902ULL, 0x67708D8760E116A2ULL, 0x03F2A3B742AC270EULL
        }
    },
    {
        {
            0xCE3D5B1F0C865CA4ULL, 0xA7873838BF93C000ULL, 0x22903CAAFE14640FULL, 0x685C9FA7B1F25BD3ULL, 
            0x7D9854C9427E8BB6ULL, 0x251A5CC47D24ABF1ULL, 0x7E78306DD96E5D74ULL, 0x2C78385209C61F5CULL, 
            0xF63997B09150BC9FULL, 0xA21019183F547188ULL, 0x4F0CAAE4910968A1ULL, 0x0B692EC43CAD5F15ULL, 
            0x5D5C26ADEFF07565ULL, 0x0D379B77A954A600ULL, 0x73EAD2AB644E1C91ULL, 0xA5EB6A1BF70BB02FULL, 
            0x4F711AA57A7E1AF9ULL, 0xB4CA4862CD41233DULL, 0xF353B5DD5C212B86ULL, 0x3F9690F9BCCA5E14ULL, 
            0x2F984BB5E2705B0EULL, 0x1B51A264E8D250F4ULL, 0xAEA237AD25888A53ULL, 0xA17888CD8089220DULL, 
            0x4F10AB9AC7AC3CC2ULL, 0x964D1E3F7684CD02ULL, 0x2BE9C79C4EE5BEE0ULL, 0x5D47B994FC349B34ULL, 
            0x1D2D0168564EB1EEULL, 0x7AD313221D532673ULL, 0x5408B0592947EBCCULL, 0x465EF1AF4D1FC0BAULL
        },
        {
            0x50EBB4FE41567F70ULL, 0xCDAD11E466149D53ULL, 0x1427B1339E0E541BULL, 0xDF8216D89349FDA8ULL, 
            0xABF8A7344419CF87ULL, 0x942D13661512EA53ULL, 0x109BAC9AED693B09ULL, 0x46EF6CB6FB639861ULL, 
            0x38658BB9C2F2B15EULL, 0x4C40E8219E648AD8ULL, 0x911E63AAA7DCC91EULL, 0xF108D0C51FA52E9BULL, 
            0x6937FFEC3A4A3C74ULL, 0xC1DE5011E72EF073ULL, 0x894721DE09AAF83EULL, 0xAE7DF2F97A49919FULL, 
            0xA85724CFCFD3D9BBULL, 0xB38F6AD80D9CAC45ULL, 0x9677C4F98B477072ULL, 0x57557E3E6C9BAE50ULL, 
            0xD38BE1969B5B2BD9ULL, 0xF17CE53F7047F2B3ULL, 0x66E6AC19F80FA14CULL, 0x4131BA9994BA9D2EULL, 
            0x10AFEAC88386F68BULL, 0x9A668FD7E7D511D3ULL, 0xC67696E8F89EB80FULL, 0x519C3EDC6438D89AULL, 
            0xBE162A090E60CEA0ULL, 0x3D1A1F69227FCBF8ULL, 0x13A36CF3E9B45589ULL, 0x1D19F022AE8E4795ULL
        },
        {
            0x653CF9C8DBFA5A31ULL, 0x09DA297147B36EC3ULL, 0xA7F58828AADE3B44ULL, 0x28259E5FC380EAC7ULL, 
            0x6EB83180DB2D4D4FULL, 0x171E19C1856D1111ULL, 0x5F1D3438E2E2BA26ULL, 0x8441682C0AE98EC9ULL, 
            0x2B8B7112D0466DA8ULL, 0xF31599AB4CAB5D71ULL, 0x0F87C7E208EF61D2ULL, 0xFCEE1D05D7DE0755ULL, 
            0x111D051FC8FBCEC0ULL, 0xEC09F97AEF95A146ULL, 0x440C1313E1D52B1AULL, 0xF5E9C09A7572BCC8ULL, 
            0x548AC4574C70985EULL, 0x2B825C68F6BF7C3BULL, 0xDCAC9708D4B7AF08ULL, 0xFE05D9E6E3489DECULL, 
            0x7972C10CEB9F97E6ULL, 0x065935F118427C7BULL, 0xA6AF735193430700ULL, 0x4FB70BAE37CD1037ULL, 
            0x1CB050A791210F9DULL, 0x2CF527C3B5D90D28ULL, 0x5A4AE03C7D1AC4F9ULL, 0x230C8D8B270A25EBULL, 
            0x19EAF912EF593A9AULL, 0x00965BBF3C60FD73ULL, 0x839EC344FCC0E94DULL, 0x3139C88B90EAD417ULL
        },
        {
            0x78430068A8044A40ULL, 0xB370072C177A550EULL, 0x81CD58EEDEC34362ULL, 0x2CB14FF345AB52F1ULL, 
            0x809D81D7575D4EE3ULL, 0xEA78C6CFCCA7DB83ULL, 0x97D65FD1509E5D21ULL, 0xBF7C1517D0B1DCB1ULL, 
            0x2D8779B5164D9DF4ULL, 0x3D580DBE1436D0C0ULL, 0x833F00B795CE70ECULL, 0x137443C9FDCFB9AFULL, 
            0x99C9E8FEA7A2C659ULL, 0x6997E2D1B210D443ULL, 0x925FB5DFACB7D5E5ULL, 0x4C55993C591CDC0BULL, 
            0x386D4F16C45C9615ULL, 0x5FDBDE6647C3B250ULL, 0x89F1E1E8712A07B0ULL, 0xC721FB5B88F394E6ULL, 
            0x07AF30BE2C9C63A5ULL, 0x0618C869B1ADA46AULL, 0x53E0E946E5615AB3ULL, 0x7B5CE7B7709B78BCULL, 
            0xE375C0B9D67B308FULL, 0xBF55BB620FF40FC1ULL, 0x5D96F8ED5DBDD2F4ULL, 0xA4FEF21B037B7C67ULL, 
            0xDC28F109B429BE6DULL, 0xABF7925A937C21DFULL, 0xD3A23C62A6121329ULL, 0xD5026910573A84A2ULL
        },
        {
            0xDD63FD3EFA3678F2ULL, 0x5943DF80EA8BAC39ULL, 0x8ABF10F5055ECFD2ULL, 0x6F0C70B149C34BB5ULL, 
            0x79F1FE530168F32EULL, 0xD0F8D4D0819307B4ULL, 0x2EDE54E4E4E1EACFULL, 0x7B692D27AF19F92CULL, 
            0x236960598A95CBC4ULL, 0x2CC9EEF48BD48BC7ULL, 0xE725D0215F88171BULL, 0x6187D02C64CA40AAULL, 
            0x0CAE21908B989B7CULL, 0xDDA5392FEDD55BE8ULL, 0xB1A515F73CCE6BDEULL, 0xA1489F8EA327C1CDULL, 
            0x9A4ABC8557F9C43DULL, 0x7E062F9947453D49ULL, 0x51F457DB087EE2E8ULL, 0xF1F33C4AB603F6C8ULL, 
            0x4519134189CB329EULL, 0x511C5D958076CF13ULL, 0xA1FD4574EB0EED71ULL, 0x8466DC0983D14C31ULL, 
            0x0921A1E0F4CACF01ULL, 0x330875484572F28DULL, 0xFC3F99D38AC8FA84ULL, 0x9458BDC18B0FD673ULL, 
            0xB9D53DC87E5559F3ULL, 0x0619937581C45B43ULL, 0x1D8CCAEDC6955C42ULL, 0x1DD1716E508DF1C4ULL
        },
        {
            0xE03B701EC123E093ULL, 0xB051E0B381DDE012ULL, 0x6E326FD8C77711C1ULL, 0xD20BBAA7CAB060F6ULL, 
            0x54616B1933A5189FULL, 0xD0F126430E275390ULL, 0x60B3DB2294FBE33DULL, 0x0FAAE8505BF86E19ULL, 
            0xDBD4D967395F5C9CULL, 0xC892AD05330C59AEULL, 0x4E6F8AE35BB89879ULL, 0xAB583F986A93EE4FULL, 
            0x0732B4DB874F97B7ULL, 0x8E004D5694B70DAFULL, 0x9883C65526678C7EULL, 0xFDEA52836416057EULL, 
            0x10A4744AA75987BEULL, 0x92B859A38F22AAD4ULL, 0x91CA829E363DA9F3ULL, 0xC119CB79A89E85F2ULL, 
            0x7C6B65260B8C7EE5ULL, 0x48998E12E503418CULL, 0x7BBFB064E379796FULL, 0x2971F816D3D9ECCFULL, 
            0x743E52A768780886ULL, 0xBF8580A2FB5D3C19ULL, 0x852F442C67503C59ULL, 0xB87330E472BBFF9AULL, 
            0xC0B9E527E0E139A0ULL, 0xAD47CD9A612DA0D5ULL, 0xE7825918A83AF89EULL, 0x76FB2DD09287B576ULL
        }
    },
    {
        {
            0xF29B53618297D565ULL, 0x60FD1CD211D0BE9CULL, 0xF624FB5955A88C72ULL, 0xE7F9BB3A49340FF3ULL, 
            0xC1FBC9A45D1F6660ULL, 0x0C73FA7FA8BAB45FULL, 0x090104E18C9011EBULL, 0xD8A5D231A33D760DULL, 
            0xDF74B4CCBC787F9AULL, 0x80BAEA880E116212ULL, 0x4BD7063263B862A3ULL, 0x574B8F97E03F261CULL, 
            0x047D40BAF97302A5ULL, 0xC6E61C1C6421DE86ULL, 0xB087325F03E6EA87ULL, 0x670EA23CB326956DULL, 
            0x02D999BDFAB49526ULL, 0x45D85AB4938A3B94ULL, 0x1D56AB14E55E87FBULL, 0xD5DC3969C592E76BULL, 
            0xDDB38FD1C7C865F3ULL, 0x69C3DC7D0DB27819ULL, 0x7A866E6393E1F21DULL, 0x4025DBE521F37D07ULL, 
            0x57023DF7A6F3BA00ULL, 0xA46C52672102A33DULL, 0x05DE68ECC880BF46ULL, 0x7693B944FD241DC7ULL, 
            0x3E8326C2A5D93780ULL, 0x20630281940652F0ULL, 0x7AFA0B647F8ED569ULL, 0xF3FBE5CEB7268A1AULL
        },
        {
            0x702411809695A8E3ULL, 0x7807EB017C5F29F2ULL, 0x81ED32C9053B0F11ULL, 0x64A62665A885E166ULL, 
            0x050C0584CF1D28D4ULL, 0x89068E495731B96FULL, 0x2331559123A91EC7ULL, 0x6C97B5E6F2ACE596ULL, 
            0x4EDC5FABEC142FC0ULL, 0xB4E40009FD25240CULL, 0x4C6E44E1B4A4B127ULL, 0x5C303ACE8067FFB6ULL, 
            0x84E2E2A6DDC64F0FULL, 0x1BD59F2524D1CA10ULL, 0x918CB7829F3570A8ULL, 0x3BEF27C4FD7F2098ULL, 
            0x005D8AE9121373E5ULL, 0x73E576FAF60B4534ULL, 0x4625A1EB7395CD82ULL, 0xD722E2DD54DAE242ULL, 
            0xB36831245FE960A3ULL, 0x78975287EEAAF4B2ULL, 0x740240372319D6FDULL, 0xB4A93FA0FB919CB2ULL, 
            0x0C9DAEAC80C47AA6ULL, 0x90064045812BDF48ULL, 0x34A1A2CE4362CE76ULL, 0xC8CE3C931354C96DULL, 
            0x868ED25C6EFF7212ULL, 0x40A78FEB2821DFF9ULL, 0x84C7479D70ACCBAEULL, 0x9E12A9A1F853B469ULL
        },
        {
            0x1AEB4298A99FAD95ULL, 0xE23E0A4AB2577FCEULL, 0xA5E840C97209C6C9ULL, 0x076EF2B1FFB02071ULL, 
            0x5C9A9230BE5D7251ULL, 0x9541824A32B35192ULL, 0xA5C0C74CD2A520E9ULL, 0x0F943C5A95610DBFULL, 
            0xB40A6498E3B5C2BEULL, 0x6640747AAE4686EDULL, 0xEFCA4CF668CCD72CULL, 0xDAD0FA97D896DBEFULL, 
            0xC9B595A5E338B6E8ULL, 0x592BF16426D39BB9ULL, 0x971C32ADBCB933CDULL, 0x4B6B6E02A583154CULL, 
            0x5B9404CAB2B5E8F6ULL, 0xA49FD4F958355E07ULL, 0xB233C87C864DC5F0ULL, 0x2CF298E2BE402099ULL, 
            0xF14449F8F7664147ULL, 0x74D6F2D56F5A3E4DULL, 0xD92BDBCE63EB0E09ULL, 0x3713C0A0D6A5ABC9ULL, 
            0x01915B2306B180AEULL, 0xD091FB5A46D002CCULL, 0x34F1B9B06D31B090ULL, 0x1EC56005544C8655ULL, 
            0xFD58198B1C8A2E52ULL, 0x8330BC88906F8D6CULL, 0x8B5EF5C390CEFBFAULL, 0x529FBF8097FB6A57ULL
        },
        {
            0xB4114FA16A927D46ULL, 0xE5FF34F821FFC04BULL, 0xAD2A89BE16F60107ULL, 0x2ECCB2B17A01247EULL, 
            0xCCE1538272A679ADULL, 0x1A5541F554EB4990ULL, 0x89C5F3C04A6170CAULL, 0x1D4729C027CC12EAULL, 
            0x78D287C56765D3EFULL, 0x2CB1F68495D44A98ULL, 0x4D40DDF786E2F6BDULL, 0x92044B37AE14DED1ULL, 
            0x50B740A4717F276DULL, 0xC6ACF343DE89A1B2ULL, 0x4C5AC6E6D9AE2DC0ULL, 0x234A62E75DA07ED7ULL, 
            0x51A3B2450D01D55EULL, 0x6F8E8D90FF8C0515ULL, 0x83B0830D94166A2FULL, 0xFD69BA4CA7E1A5BEULL, 
            0x24E1FDCFFC27F128ULL, 0x682CCB3EF5956EAEULL, 0x200F7B6308464056ULL, 0x2B25A4D6D67660FCULL, 
            0x2A2E9E05F71E9BC3ULL, 0x35B6BAC587C2D442ULL, 0xCFD81825455A4DBCULL, 0xFF705763D20A17E0ULL, 
            0x8EAD952C79F8EAACULL, 0xEB9E9146FBEE993CULL, 0x902B829710EB787FULL, 0x3523E9A42BB61A7EULL
        },
        {
            0x97550291C24F545FULL, 0x0919840B2254CA05ULL, 0xDEB6E9BACDC23702ULL, 0x5EC17D4BCD91D0DCULL, 
            0x5F50D9732B336E0CULL, 0x75D86A8951FE94E2ULL, 0xD79BC6F7E5E6B128ULL, 0xDCCFE1346450231BULL, 
            0x8B49D645D945666BULL, 0xA839B2CE47C6F523ULL, 0xBD6EB3A5BB81752FULL, 0xB6C9AE142769C7D3ULL, 
            0x8E4C848A3AEDF79AULL, 0x4788A1E9756511A1ULL, 0x8833D792A100AC77ULL, 0x3991865F4F50A666ULL, 
            0x6CEF9B2925F58E36ULL, 0x18FDF5305B6A648AULL, 0xA5CB88E68F5BEFF4ULL, 0x8BA9A67A189063AEULL, 
            0xF9B2B907FF5339E4ULL, 0xDD2A2D6442D00569ULL, 0xEB98F51EDAA76596ULL, 0xCA1B06323F8F82A1ULL, 
            0x9E45D0083D0373BFULL, 0x8D7671C1759A92D4ULL, 0xE89EC1711BF06A8CULL, 0xC9086870616F9354ULL, 
            0x4EFDEC435480A4A4ULL, 0x8AFB5B9497AD0CD4ULL, 0x775A99AF231423AAULL, 0xA5FB4E2D10ACE3AEULL
        },
        {
            0x4EFA300317BD11F0ULL, 0x101301F73F5D8D10ULL, 0x781C2F7DE8A2131DULL, 0xF1AB3F4EB6C22B37ULL, 
            0xF30B3C29AB80C717ULL, 0xB299B3BB90608BAFULL, 0x4435C549ADAB6D10ULL, 0xDE2E0C88425B0D53ULL, 
            0x11C68C4D0C68FA33ULL, 0x9E1D063FDF7B9932ULL, 0xE53C0DBD0C90C8C5ULL, 0xB3865A52BFF33326ULL, 
            0x929CB8C09D6EE2F1ULL, 0xA3C649EE6F012A64ULL, 0x0840E8012BDDBD01ULL, 0x11495CE3351B2447ULL, 
            0x3E11F23B3833BB6CULL, 0x9A48EF242F8581AFULL, 0x8C5489C6BA51DE91ULL, 0xF6060FDFF629A2DAULL, 
            0xD8095B4559F0812FULL, 0x1CB20039BD01F252ULL, 0xA5A934C033FB958AULL, 0xD0BBD5E2F588520AULL, 
            0x093466AA8DD80192ULL, 0xF9A980D8F173198DULL, 0x09487EC6F91A0554ULL, 0xF72AD1CCD27592D6ULL, 
            0x19644C703C262479ULL, 0x248355BB04664090ULL, 0xF1DE6B80D78E4A0DULL, 0xE4BEE5ABAB8714DBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseHConstants = {
    0xBD011A185793AA5CULL,
    0x62E217CA8112BFAFULL,
    0x64B7B0A28FC92202ULL,
    0xBD011A185793AA5CULL,
    0x62E217CA8112BFAFULL,
    0x64B7B0A28FC92202ULL,
    0x4CE47E1E3AE6CE52ULL,
    0x4E797FF73C6822BEULL,
    0x5B,
    0x90,
    0x6B,
    0x79,
    0xB4,
    0x8F,
    0x46,
    0x8D
};

