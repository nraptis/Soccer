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
        aPrevious = 11957432251248477133U;
        aCarry = 12018057018242691369U;
        aWandererA = 11132148310746523064U;
        aWandererB = 11496974446969126877U;
        aWandererC = 14675883777098109089U;
        aWandererD = 12645012951582131498U;
        aWandererE = 11889547110109367785U;
        aWandererF = 16036255637871789543U;
        aWandererG = 9350141521624143360U;
        aWandererH = 9318539478244423897U;
        aWandererI = 16224159128792036723U;
        aWandererJ = 9642504257595740876U;
        aWandererK = 16139074775822595598U;
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
    TwistExpander_PickleBall_Arx aArx;
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
    TwistExpander_PickleBall_Arx aKDF_A_BArx;
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
    TwistExpander_PickleBall_Arx aKDF_A_CArx;
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
    TwistExpander_PickleBall_Arx aKDF_A_DArx;
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

void TwistExpander_PickleBall::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 15291511564279770960U;
        aCarry = 12963608818465907869U;
        aWandererA = 10890529163619988015U;
        aWandererB = 12753712411750079615U;
        aWandererC = 13639818686281806172U;
        aWandererD = 18271904144788391275U;
        aWandererE = 12498447334956282400U;
        aWandererF = 12841899698005406469U;
        aWandererG = 10978127651296181272U;
        aWandererH = 9559307584042394628U;
        aWandererI = 12535300116754812410U;
        aWandererJ = 12259592294397104440U;
        aWandererK = 15986713710622523880U;
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
    TwistExpander_PickleBall_Arx aKDF_B_AArx;
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
    TwistExpander_PickleBall_Arx aKDF_B_BArx;
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
    TwistExpander_PickleBall_Arx aKDF_B_CArx;
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
    std::uint64_t aPrevious = 0xDB86B74F6627DF20ULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xB4EED7C9BEC6A3EBULL;

    std::uint64_t aWandererA = 0xB922F08C5D1FA001ULL;
    std::uint64_t aWandererB = 0xDF3D3F6AF5707581ULL;
    std::uint64_t aWandererC = 0x8DCC74D19FA71B87ULL;
    std::uint64_t aWandererD = 0xDCED069E4AE38DEAULL;
    std::uint64_t aWandererE = 0x8001A72FC249B9CAULL;
    std::uint64_t aWandererF = 0xFF80B88B5E1E2F87ULL;
    std::uint64_t aWandererG = 0x945B1C349F98D821ULL;
    std::uint64_t aWandererH = 0xFB4BB5A7222658B1ULL;
    std::uint64_t aWandererI = 0xFAF64707C1F3763CULL;
    std::uint64_t aWandererJ = 0xE5EF3C6BBF228089ULL;
    std::uint64_t aWandererK = 0xA12DEE5993BD47EDULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB);
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
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneB);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    TwistExpander_PickleBall_Arx aSeed_AArx;
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
    TwistExpander_PickleBall_Arx aSeed_BArx;
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
    TwistExpander_PickleBall_Arx aSeed_CArx;
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
    TwistExpander_PickleBall_Arx aSeed_DArx;
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
    TwistExpander_PickleBall_Arx aSeed_EArx;
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
    TwistExpander_PickleBall_Arx aSeed_FArx;
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
    TwistExpander_PickleBall_Arx aSeed_GArx;
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
    TwistExpander_PickleBall_Arx aGrow_AArx;
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
    TwistExpander_PickleBall_Arx aGrow_BArx;
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_PickleBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 10625526980102511109U;
        aCarry = 12151898485166561333U;
        aWandererA = 11346075079517764538U;
        aWandererB = 17212039958601776821U;
        aWandererC = 15083345370053346392U;
        aWandererD = 16736160286117164133U;
        aWandererE = 16196623377545104147U;
        aWandererF = 10056064515272630496U;
        aWandererG = 9780510166355407357U;
        aWandererH = 14022830110534943076U;
        aWandererI = 16826243024114083403U;
        aWandererJ = 17690130889040879242U;
        aWandererK = 13961273296513817913U;
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
    TwistExpander_PickleBall_Arx aTwist_AArx;
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
    TwistExpander_PickleBall_Arx aTwist_BArx;
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
    TwistExpander_PickleBall_Arx aTwist_CArx;
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
    TwistExpander_PickleBall_Arx aTwist_DArx;
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
        TwistExpander_PickleBall_Arx aGrow_AArx;
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
        TwistExpander_PickleBall_Arx aGrow_BArx;
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
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 3, 0 with offsets 4233U, 7418U, 1936U, 3040U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4233U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7418U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1936U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3040U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 1, 2 with offsets 156U, 7975U, 3747U, 1944U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 156U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7975U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3747U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1944U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 0, 3 with offsets 7509U, 7752U, 5906U, 5217U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7509U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7752U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5906U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5217U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 2, 1 with offsets 1311U, 6446U, 1548U, 4578U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1311U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6446U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1548U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4578U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 2, 3 with offsets 1470U, 1303U, 608U, 1426U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1470U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1303U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 608U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1426U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 0, 2, 3 with offsets 1470U, 619U, 246U, 1975U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1470U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 619U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 246U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1975U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 3, 2, 1 with offsets 958U, 587U, 1400U, 1474U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 958U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 587U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1400U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1474U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 1, 3, 2 with offsets 1414U, 439U, 1734U, 1373U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1414U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 439U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1734U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1373U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1216U, 1978U, 1706U, 1884U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1216U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1978U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1706U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1884U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 1, 2 with offsets 2828U, 5936U, 1396U, 5799U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2828U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5936U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1396U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5799U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 3, 0 with offsets 5257U, 947U, 5139U, 5422U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5257U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 947U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5139U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5422U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 2, 1 with offsets 6843U, 7052U, 790U, 7676U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6843U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7052U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7676U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 0, 3 with offsets 6621U, 4342U, 2188U, 6366U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6621U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4342U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2188U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6366U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7107U, 5215U, 7419U, 2289U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7107U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5215U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7419U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2289U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 338U, 321U, 1894U, 735U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 338U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 321U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 735U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1792U, 308U, 475U, 1292U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1792U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 308U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1292U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1452U, 1930U, 1353U, 1942U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1452U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1930U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1942U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 825U, 1645U, 1010U, 1565U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 825U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1010U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1565U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 2, 0 [0..<W_KEY]
        // offsets: 1376U, 450U, 1668U, 1802U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 450U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1802U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseASalts = {
    {
        {
            0x737918DA7651D83AULL, 0xB1269C4BBEA95742ULL, 0xB30D5AE578CB1CA8ULL, 0xE65D940D4B0666EBULL, 
            0x2235CB41AA9E0065ULL, 0x0ED1B24905093528ULL, 0xD9D2DAC0A5FFAF08ULL, 0x6A60414C4D126C6AULL, 
            0xBE84F1F61751E27BULL, 0xBBB20702093A33A5ULL, 0x7EEFB16EE3020C33ULL, 0x23E058F9173A62E6ULL, 
            0x190E53AC959025B0ULL, 0x9C7091B808B66597ULL, 0x213D3D4FF28D89DAULL, 0x44F08DDFBB38F878ULL, 
            0x740A3DD23B912604ULL, 0xF17DD6F17809E2B1ULL, 0x834EE9D7009386C6ULL, 0x2E6ABCB463D2CECBULL, 
            0x9562932ACFC887B2ULL, 0x91F4FCD832820618ULL, 0x9244ABA810AE7F17ULL, 0x3EAB871FE85FF77CULL, 
            0xBB0FD46DF1AC9409ULL, 0x20ACFF72CA4D62D6ULL, 0xB1439E966EA11375ULL, 0x89F4C8BBC59F47C5ULL, 
            0xD65116E614333E72ULL, 0xE115CD76F78F9792ULL, 0xC931685524AF2C72ULL, 0x62C253F21B3DF144ULL
        },
        {
            0x35BF4DF7396AAEA2ULL, 0xDE8854A3B50A909AULL, 0xD520CBDEAE66D385ULL, 0x3B2F36C97FCECEEFULL, 
            0xBCBBC34BB3133319ULL, 0x89F23EFEB34FD3EAULL, 0xB85CAD56C88D4AE5ULL, 0x5B37BBA81767395FULL, 
            0x7D828BC78DA3DB0AULL, 0x67C574D479BE06D3ULL, 0x0113CCF10348853EULL, 0xCB75610D221B5B1DULL, 
            0xDA7BB864309B4D9FULL, 0x7BEC9F833F381349ULL, 0xB3E7AFF601849B97ULL, 0x9290FBBF00610078ULL, 
            0xE67156D797DEFF5EULL, 0x847F1C6D01E66237ULL, 0xCBE258380B8001B3ULL, 0x7B771719D4699536ULL, 
            0xA62697D716555F67ULL, 0xE746C268C79A5D82ULL, 0xEBBC5C6694562B4FULL, 0xE4EF70216D6C447BULL, 
            0x5A63C80B76E9A21FULL, 0xA02387462490B9E5ULL, 0x3F4A7CE1123ACBB9ULL, 0x2BB08E2A7CB48B17ULL, 
            0x3AB2B82D47C2FF29ULL, 0x5A0E9D9434E0B4EDULL, 0x9D1A6938E76CDB6EULL, 0xB8EE215E67CE263BULL
        },
        {
            0x4A8BFE0093EDBADEULL, 0x22B559F23F3AF360ULL, 0x4102E2B21FBFEE65ULL, 0xFC4B269F882C4B8EULL, 
            0x125FB34DA9F08EE5ULL, 0xB67B53BE96C706BFULL, 0xE66C868B4E3E2712ULL, 0xF29CCA4F520C5CC9ULL, 
            0x4A9005516C61E07EULL, 0x78865188F8A92017ULL, 0x2F2558C3959F6573ULL, 0xCD1A4EBE2B2FCD5FULL, 
            0x1B4412D2AA96C73CULL, 0x8F71A4EE0AFD16F8ULL, 0x4A766D4ED29AE90DULL, 0xCE9CCF20CF812DCCULL, 
            0xD42CF216C0977181ULL, 0x156971A3BAD18DCEULL, 0xAFEC5ED9F4F75E50ULL, 0xE1E44495C0DDD3B9ULL, 
            0x4E1406C7C20281C7ULL, 0xD328DBC8D8F75E9BULL, 0x0E09E999BCA3D44BULL, 0x5377306D6DBD243FULL, 
            0x60B7AA2307BE621DULL, 0xD36602204905022BULL, 0x86DF64913CFE74C2ULL, 0x1FD1D4FE3095D922ULL, 
            0x58B25A2EF89FF3E8ULL, 0x7D4A74EF942A923EULL, 0xCEAECE17285EBE91ULL, 0xC8634411514A127FULL
        },
        {
            0x318EBFC21372AFA4ULL, 0x2BFF5653502F8139ULL, 0x5E7EECE737D0714DULL, 0xF2620969A461AC46ULL, 
            0xB01FCB8DC910DC19ULL, 0x0C4073067B90EF85ULL, 0xAEAC6C9C7F5506B6ULL, 0xC8F361C1E2C903A2ULL, 
            0x7A774D3F08794B3DULL, 0xAA48552E31D5D57FULL, 0xE3600C43B11D8B40ULL, 0x614CE52D6187FE38ULL, 
            0xA5BA1456E35B77BAULL, 0xAE1CE3778AF4D1F3ULL, 0xB16F394516234C20ULL, 0x843655C8DB95DE36ULL, 
            0x87C1DEA489F44427ULL, 0x38104A3B02431705ULL, 0x0B42A438FEFD16CEULL, 0x814F2F8833D8E35AULL, 
            0x7C05CDE9EBE996D3ULL, 0x0B2064C66F671755ULL, 0xB6A7738D6DDF607DULL, 0x070ECEAAAE864913ULL, 
            0xE36DAF7691A98253ULL, 0x223688C920DD4E05ULL, 0x38E98E714C792B09ULL, 0xBFE5E393C4B20178ULL, 
            0xC0E7D08D8E7C12BDULL, 0x35E06B7F2C8E3773ULL, 0x245902F13ADEAFB5ULL, 0xE768911F330A973DULL
        },
        {
            0x15D3DB3CE5D3B9B5ULL, 0x214445A505508CC4ULL, 0x399FE96F8E87A15EULL, 0xC0829E8551A82647ULL, 
            0xBDF9BE4263D77002ULL, 0x7F93B608C096FC10ULL, 0x0FF1ABD8B16079F5ULL, 0x6AEF019E71D4C172ULL, 
            0xE04ED70A6D664B18ULL, 0xCDEDEE09109B0D91ULL, 0xCED714A147BA6E87ULL, 0xFCE3CBB925C97C5CULL, 
            0x03D49FEA3929F8FBULL, 0xCF8F0DF583D47184ULL, 0xB8EBCA2BBAB2D409ULL, 0xFF0D65AA35376060ULL, 
            0xC1D21F61945F1FF2ULL, 0x77107DBAB411BEE1ULL, 0xF00D49A6D030526AULL, 0xF2BDA1C5CBB5B44FULL, 
            0x140B03D3E47FB2CBULL, 0x8AB2B343336194ABULL, 0x82D9B0D581E1304AULL, 0x8323FBA4E44CA30BULL, 
            0x9134368472A7EA43ULL, 0xA72A63A30D9A7C7FULL, 0xB142BBBCD93CB0AAULL, 0xC5A1993DAC8682BAULL, 
            0x09045A5D5C3D1118ULL, 0x835D4D304F6A4445ULL, 0xD3D1568D95208480ULL, 0xD88A6077B58FC355ULL
        },
        {
            0xC5433394C221E9F3ULL, 0xADC23DEBCB500394ULL, 0xB9572095AC126FC7ULL, 0x8B04CAE98897D202ULL, 
            0xC376FFC57EDA23F8ULL, 0x96CB7A72068E5A45ULL, 0x7A15F4E5448D9B29ULL, 0x5B81D5C030FDC27EULL, 
            0xD19E95C2B0A9A310ULL, 0x69621490F3259AA8ULL, 0x551454D92B2CF71CULL, 0x7DD529BA6B1D16CCULL, 
            0x13D18516766625F1ULL, 0xF51873C372B8DC77ULL, 0x973B845F2581AF6EULL, 0xB7CEB3DC9A1A514DULL, 
            0x2C94A3656D7895E1ULL, 0xD023337784B26606ULL, 0x880CB7A5E395ACFBULL, 0x0D91BF414C08EF7FULL, 
            0x5FDECCCD34F593BCULL, 0xDBBF2D9501D0715AULL, 0x7E9D67FFB6C94F7FULL, 0x8F9D2C6FD466DB1BULL, 
            0x82469B980053B3AAULL, 0x26ED74AEBF9FF7C7ULL, 0x898C7CA74D6316E7ULL, 0x218D36809B7C8997ULL, 
            0xF74C82FB2084815BULL, 0x61364DF4E8B61D2FULL, 0x5AFEE916C905673EULL, 0x87E82A07043F7792ULL
        }
    },
    {
        {
            0xA77364C456E0F232ULL, 0xB725B7D7BEF752F9ULL, 0xAA1048547E3D18C4ULL, 0x74D317A92077BC42ULL, 
            0x0B212A4EC1187C84ULL, 0x2A3D8E5CA237F2AFULL, 0x8A8DAD8BEEB4809EULL, 0xEA09AC9ECA5AA515ULL, 
            0x36AD07C5BDCD3B07ULL, 0xAD129D404CB02C15ULL, 0x3158B37A2DEC5C15ULL, 0x2434A7E5092C4E74ULL, 
            0x55AB695E860066B6ULL, 0x5F212858B1A5A2DEULL, 0x0D454D2F7622B77CULL, 0xA906CACEF256395AULL, 
            0xB5E4C31220553EEBULL, 0x751748B3DF758ECEULL, 0xC75D2470C5E6CDC6ULL, 0x8E447280CD095A94ULL, 
            0x89175BF750787734ULL, 0x5A156E274A180D2AULL, 0x14FB181749D650DCULL, 0xE552D52CBF1DA126ULL, 
            0xA2255D1C0A51D88FULL, 0x64B564233FECDADAULL, 0xDCB11F197A9075DAULL, 0xD107107AFE528BC2ULL, 
            0x2E0BBF3A018B7F15ULL, 0x6ADF7B0C1D3B549FULL, 0x0F1638B6CF471A06ULL, 0xF1BBB59B99F50B1AULL
        },
        {
            0xB5CE5B5232260E12ULL, 0xC9B527C03DCC9C95ULL, 0xB33849E7EF33EB87ULL, 0x42CB40BC36B384BAULL, 
            0x2A986AD260651011ULL, 0x4A4C1571F5ED158EULL, 0x44D00D2F2FD25DC7ULL, 0x4772A9D1D0CCE463ULL, 
            0xCB5BCF61B6B6A42CULL, 0x150143FF1BA6D32BULL, 0xBFC56B7F7C736A4FULL, 0x331B4BF0A7A06D9BULL, 
            0x4058429F469B860AULL, 0x84E3DE4270358118ULL, 0x2F5CE30ED48C88C3ULL, 0xAF06A104A40F10EDULL, 
            0xE17CF4161C1FBCB8ULL, 0xA0B6A480BC64385CULL, 0x20DA1906791F6973ULL, 0x54807336930947F6ULL, 
            0x4D5F1696FC08ED5EULL, 0x548F6E4E973484EBULL, 0xD1801FD1F24FF62DULL, 0xF60CD04B4BFA37F3ULL, 
            0xA6FF799E37F50102ULL, 0xCCA4D5AB008059B4ULL, 0x45CB990028F76C9DULL, 0x81DE434048A22623ULL, 
            0x38FBFB087EF75827ULL, 0x8C9499954625870CULL, 0x61620BF1D9FEB837ULL, 0x4DE0D91B3DF68A9BULL
        },
        {
            0x6A61CD5084218D6DULL, 0x18EBCB9109314392ULL, 0x151A75491DAE3E69ULL, 0x9C5CA1A6401D7DCCULL, 
            0xE42DD41F88A9ACA1ULL, 0x1F9EBD21DE9F6485ULL, 0x21BE497EE62AB5FEULL, 0x3807C9F489FAEFA7ULL, 
            0x8071D659280247BCULL, 0x60D79D58EDA120BCULL, 0xA824975720718021ULL, 0x9D7C73507033E58CULL, 
            0x5DB4E357E506F712ULL, 0x1966B00BC87810C1ULL, 0xFE83B5D1B43AC1D5ULL, 0x1A5E1686A20FCA92ULL, 
            0xA4944A04F5F5AE45ULL, 0xCC945F13C36576E2ULL, 0x61F1176684B228E1ULL, 0x60C26F9B6654F84BULL, 
            0xFEAC852A0CA9017FULL, 0x1D1AF012392E8665ULL, 0x12D66239EBDCE4B6ULL, 0x6A7ED2C11E29690FULL, 
            0xA863B2E84BBD3E8DULL, 0x501EED2A7EAB2CE4ULL, 0xD2261736CCA848BFULL, 0xE50CF098A51C085EULL, 
            0xE68C9D408A37FF1FULL, 0xFB7F7334864FD933ULL, 0x8B0D787D8DEA0448ULL, 0xD83671561804C7C2ULL
        },
        {
            0xF3E2120C7AA3A76EULL, 0x4DAA341BB71235A0ULL, 0xC753844AFEEF2C60ULL, 0x0C3D57126EBC64DDULL, 
            0xB63A247D54AF7B02ULL, 0x8BC92B8D189D2026ULL, 0x2FC266B99B0CAD8BULL, 0x98BF95C59B92FDF1ULL, 
            0xEDED36FF4F96E23EULL, 0x240153633BD56721ULL, 0x08A2FE215ED3AD1DULL, 0x42B7DAA0B80D6EA5ULL, 
            0x5F49E94A957B9668ULL, 0x5064129325128F86ULL, 0x0131F60F15018822ULL, 0xD5244F214BBF85ECULL, 
            0xA929738FC3BEABE3ULL, 0x0E444F854B13ADE0ULL, 0xDC8B87946D548C85ULL, 0xBF4CD28C213C1979ULL, 
            0xFC409AA54B28292BULL, 0x3F4D07FB83FA7D4FULL, 0x4173E1C7C60DE891ULL, 0xE76323311FD266AFULL, 
            0xBDBFC415848330B0ULL, 0x5994B0BA599A4181ULL, 0x37D04A720F3797D4ULL, 0xB88A8FC376343C6EULL, 
            0x16E2FA1CED28E9F4ULL, 0x7D1E72A5634B8C70ULL, 0xD8333364EF2DC0EFULL, 0x414C10C952DF6311ULL
        },
        {
            0x20751AC2DFE04986ULL, 0x6E298C9C2B0287ACULL, 0xE4A5FE47BE12133DULL, 0x30222E00730D2E3DULL, 
            0x3B6FF6C5F761F2BFULL, 0xF85040E6C7A0A93EULL, 0xB935370FC41B4E95ULL, 0xF66A7AB84C066D9DULL, 
            0xAEBBC7A0E5F6E4B8ULL, 0x4423E9810D493F40ULL, 0xF449C46602DC015DULL, 0x768D64C66F51C681ULL, 
            0x4F001618F75970CAULL, 0x41FB7DA15F243C0EULL, 0x5F4388831D370AFEULL, 0x135CEE6FDC42563EULL, 
            0x264B389528823C84ULL, 0xAF697071CF6D3A57ULL, 0x091A6929EBC3D241ULL, 0xEA085035FD9DCC93ULL, 
            0x07EFDBBE8EE3353DULL, 0xA9C0928444227AF4ULL, 0x5E04DED84828544CULL, 0x08DA07B0B1ADFC49ULL, 
            0x48C6AEE5E86C575EULL, 0xC584306DBB783346ULL, 0xECC5134461F43C82ULL, 0x0246638C8B95D8E6ULL, 
            0xB1A8F4492C0928D2ULL, 0xF4B5CF8B11707FF9ULL, 0x21AF8DFD1F4AE34AULL, 0x97129F46DC3189AAULL
        },
        {
            0x82EC5F036D8BC868ULL, 0x4568A6B4700239DEULL, 0x586EB9653AA06CDCULL, 0x93657950F6712E9EULL, 
            0xF0387833C2F0B6A8ULL, 0xDE96F652A538E8DDULL, 0x90FCC38F6D9FBDC7ULL, 0x0A95E952E5A020B9ULL, 
            0x3A79DBB8EA3DF2CEULL, 0x980DCBC793BD79B1ULL, 0x0404B2BE879F6CBBULL, 0x24DC1A6546F82CBAULL, 
            0xB85164198F5060FFULL, 0x737A962CD8620DCEULL, 0xCF20325A0304B1E3ULL, 0xFCE9D5CEE0220846ULL, 
            0x089441B52F5D9471ULL, 0x7071F724B8E508B4ULL, 0x7B39C169209B31D7ULL, 0x842EB59971399C67ULL, 
            0x8FB59FE72537506EULL, 0xC35E836E5CB8C9E1ULL, 0x9AF2CA15686399B6ULL, 0xAC3767E9D261465DULL, 
            0x7B1351E0AB131098ULL, 0xD6D246AFFEBE119FULL, 0xE11F80477F4A7F36ULL, 0x08758FF5EDD21060ULL, 
            0x0256167A74AAC2E5ULL, 0x1D663C8232D88C9EULL, 0x9D5D5FDF4A1EEE70ULL, 0xC53E02BAF6A0BFCAULL
        }
    },
    {
        {
            0x136A6DE5425933CDULL, 0x6586A471301B8BF5ULL, 0x581580F627B426F4ULL, 0x45AC71C29334039BULL, 
            0x57AD968A94F42820ULL, 0xDABACA6DBFF75B14ULL, 0x0F7A291C00B2AEF4ULL, 0x0EA8AD3F482E6FF2ULL, 
            0x7F52B4832A30EEA1ULL, 0x096AD8EB8D89DF8EULL, 0x47476932CA2094DAULL, 0xE3452A6F3AB51BF0ULL, 
            0xE239327F88B28C9FULL, 0xBC1B71F6A49104CAULL, 0x10362F2349E8C5B9ULL, 0x2C0B80484B1C1836ULL, 
            0x3F7101AB8ED1636EULL, 0x376617EB14338518ULL, 0x2871EFADE9CEBBA4ULL, 0x39C7613BE02198E5ULL, 
            0x6050A810100E4336ULL, 0x8CEDD720DB4EF359ULL, 0x6F270569CA281B9AULL, 0x401164C80A1D0D68ULL, 
            0xA453B85489C80EBCULL, 0xE8DA6AD19F7BCA7FULL, 0xBEFB332992FCD903ULL, 0x1045982C969A329CULL, 
            0xFA09463D994A7570ULL, 0x6F48FAB6AEAAB983ULL, 0x6FC4BC563A9DEE01ULL, 0xE3FF677F3A774B62ULL
        },
        {
            0x35BDE808573C3D25ULL, 0xDF262DCFD35CDF0BULL, 0xE0BBC6C0A952DE98ULL, 0x1BE2F2009A6B77B0ULL, 
            0x9BC86F56BF6F6D0EULL, 0x00419753D2EC6D58ULL, 0x813F37CC39CE5F20ULL, 0x7ECE6C8A22AB8D0AULL, 
            0x67E6C8C2C6270DCCULL, 0xF59B592FD536E491ULL, 0x938BDFD85A5D87C5ULL, 0x677F2E31CC650C03ULL, 
            0x598CF56B3FAF3B0BULL, 0x5154FF328B0A34F7ULL, 0x3EF6041E5BDD7688ULL, 0x65F26AF6614DB4ECULL, 
            0xA318121F7520590FULL, 0x8D647514DFDF608EULL, 0x29743DFC1610E832ULL, 0xCD029A6C383BDD10ULL, 
            0x1CB2F322DC0F4C1BULL, 0xE4283DCB5B81B7BCULL, 0x42A7A7C557101D24ULL, 0x75AEF4E4DFED1A42ULL, 
            0xB0DC51B153E66DF9ULL, 0x0C515FE018ADDDEEULL, 0x1362048AB63F2EB9ULL, 0x851BEA52FABFB866ULL, 
            0x5A16E630CF4C5DF2ULL, 0xB433B1636A8829B5ULL, 0xE839A502D554B3DBULL, 0xAC365DA6870FA7A8ULL
        },
        {
            0x8525B50E5FFA6B77ULL, 0x7416BDAC460A6118ULL, 0x0232224E4950B550ULL, 0xFAF5E95DF02A92D6ULL, 
            0xB9A9A52F72D828A4ULL, 0x73D77C9FADDF7BC3ULL, 0xC8454966BBD3B288ULL, 0x2D53790A34C3756DULL, 
            0x01F0F0D81A97890BULL, 0x471C388321137EA6ULL, 0xCAF4F74602098E01ULL, 0x484D4596A8D231DAULL, 
            0x23209C8501B81643ULL, 0x635F9906C7976BD2ULL, 0x11D08C5B74DD6F88ULL, 0x2C0D6B3B39560637ULL, 
            0x36ACF5F2B22B297FULL, 0xDC50D0ADD15C5767ULL, 0x100AB8107A03B691ULL, 0xCDC843D93575DF54ULL, 
            0xA2F25C2B7869207BULL, 0x369A9A1F1BAD74D7ULL, 0xF1288F3253349F28ULL, 0x22722D69B20CD2CAULL, 
            0x29643ABD7FA69906ULL, 0x0DA5CEC2FD396318ULL, 0x0D710617D102BBDBULL, 0x644C99D7CAB7BF72ULL, 
            0xD02CED3AE8E26583ULL, 0x78CBFCC7BB8F4C15ULL, 0xED7A96412B4C0365ULL, 0x3889E897065C9008ULL
        },
        {
            0x327987DD0166EB9DULL, 0xDBD672D334A5C30CULL, 0xBF5CA3577EA677FEULL, 0x0B9BE5E02A99963DULL, 
            0x457C13AF70548037ULL, 0x2351ADDD0068D087ULL, 0xE5CD11D9DA18A7ECULL, 0x7D34974462F47ADEULL, 
            0x4CF71287B93BCB1BULL, 0xECD5F587BED0CB11ULL, 0xB0EF822C59E02D28ULL, 0x6B2820DDA9481150ULL, 
            0x71B0B5976DB7D689ULL, 0xA55EF9A977071241ULL, 0xDB615836FACC4676ULL, 0x3ECA02989F4E3D7CULL, 
            0xBE7962DE0810F075ULL, 0xEAF5B4580BC7C074ULL, 0x62596BE701B1AA62ULL, 0xF7A5807D8A7800F6ULL, 
            0x1FA1DB38B96DF7CEULL, 0x7392ECD586EC4B4EULL, 0x187BE317D738C58AULL, 0x11D0589235000A67ULL, 
            0x4BE91D3C83CF052DULL, 0x9A546F4E080DCD72ULL, 0x5F1630E8D76F7225ULL, 0x7E9B94CD09135AF9ULL, 
            0x9ABF7097F377660AULL, 0x5DE764F09B379CCAULL, 0x2313096015261EAEULL, 0x6039C5BEA82F83FDULL
        },
        {
            0x56B6FAB82FE06032ULL, 0x54CA1C34337091BEULL, 0x432C470DE6EC4E80ULL, 0xFE5FF1553B115F3DULL, 
            0x51663F846DC59CACULL, 0x91C20159894A4211ULL, 0x9C37A70E48A4A839ULL, 0x12E9233A46C6DEE4ULL, 
            0x408F8AB09C2E2EC2ULL, 0x6E2630C512ADB2AAULL, 0xEFD6A924CAB19DEFULL, 0x2DA022F5AE818FD9ULL, 
            0x3FE75ED1ED321195ULL, 0x62D8BF183133EED2ULL, 0xECB6DE6272C29ABEULL, 0x053359F191A88CCBULL, 
            0xE7D8F7D8DA7C0314ULL, 0x9FC860EA72FE4019ULL, 0x31811727A346916FULL, 0xF5137BC25CFEB333ULL, 
            0x5C4B643280A091C9ULL, 0x712481DF8E72A54AULL, 0x6FE11DCD4D007A07ULL, 0x7B465600191CFE3BULL, 
            0xB8E1975317BF5C87ULL, 0x92419A3E41E191F8ULL, 0xB5F8B2103B2AE5DAULL, 0xF916EAF64B4194E9ULL, 
            0xD5844C1BC9F1AC6EULL, 0x9DAC2631DDE62476ULL, 0x454248DF346B984CULL, 0x3C9B227059D0978DULL
        },
        {
            0xD27DADD6C742D648ULL, 0xBE0D692906FCFEAEULL, 0x2B7144774304DB11ULL, 0xD5E338CF8B934813ULL, 
            0x9DEF1DA379144E88ULL, 0xD277D86FA47CE1EFULL, 0x6516935D7CFD328BULL, 0x9ADF41F88B6890A7ULL, 
            0x41C11F497D59E681ULL, 0xFDAF8E55375B94D7ULL, 0x4EF97145632C316AULL, 0x92B79947700A3E17ULL, 
            0x98FAFD9B05A1C6DCULL, 0xAA0E43FC7DDBCD79ULL, 0x1393D063C5095FB4ULL, 0x089C2C323CE8AB2DULL, 
            0xE0797CC7203C110CULL, 0x5052A4525CEC019FULL, 0xCBE8B193B3061D49ULL, 0x6E83FD30E5BD4A31ULL, 
            0x9E83EC9C20CE7EDDULL, 0xDF94FBCCFC302845ULL, 0xF6A1CC7BA0CD8090ULL, 0x3A5770B4F5C7202CULL, 
            0x5908D33D622A07EFULL, 0x51B15FCA63237F70ULL, 0x82A2E1DCDD5A4D7DULL, 0x8CD6CB4295AA8741ULL, 
            0xEDD1DD0BEAC24AC4ULL, 0xA5134F1326704F0AULL, 0x19B01C4E3486FF57ULL, 0xC3CA347A3FFA55E1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseAConstants = {
    0xB6481E789DA623D2ULL,
    0x702521613FA428DBULL,
    0xE10FB3AEDCBA6883ULL,
    0xB6481E789DA623D2ULL,
    0x702521613FA428DBULL,
    0xE10FB3AEDCBA6883ULL,
    0x5F3D1966303BE189ULL,
    0xCE65455EA79FB7C0ULL,
    0x5D,
    0x3C,
    0xD5,
    0x3C,
    0xF9,
    0x74,
    0x86,
    0xAB
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseBSalts = {
    {
        {
            0x71994CA72C1990F7ULL, 0xE624676523046465ULL, 0x2ED93AF5107CBC95ULL, 0x16CE1BFE15645CFDULL, 
            0xE630A90273F97F65ULL, 0x657B219B5790E755ULL, 0xF6C0D5CD4809964BULL, 0x107F6350278B9512ULL, 
            0x62DA1BEAA2DE8B01ULL, 0x0D1544B565C7CE49ULL, 0xA2F8C3D763D21545ULL, 0x0CD7B41DDC29AFA0ULL, 
            0x628573ABCEE43D23ULL, 0xED77EA80B40CEFC4ULL, 0x4992191854AC1897ULL, 0x7987E1B313CCFC46ULL, 
            0x0E4585621B8A196FULL, 0x4F540796E55F9C52ULL, 0x7F017D339B229312ULL, 0xBFB57250256F132CULL, 
            0x553EC02D7B34161CULL, 0xB978D5E6F3BD5298ULL, 0x15B7231E1062EF0DULL, 0x71E59CCDEFD369E2ULL, 
            0x7F84C924538469F7ULL, 0x56418175F27F0D0CULL, 0x5B27A9E0D639C0CFULL, 0x83F48340E283AF07ULL, 
            0x10A9A9348D8F1013ULL, 0xE49A2C38D66A23E8ULL, 0x9C7F27B02C6C2172ULL, 0x30981BB7EF18C640ULL
        },
        {
            0x571F09CB6F005984ULL, 0x71AC980A18F4FF8DULL, 0x056463629A488F76ULL, 0xE646132A9716304FULL, 
            0x2A8BC73B0A3F1FA6ULL, 0x0F754C0F30FB7016ULL, 0x2491A9546592BB48ULL, 0x66E718730D31713DULL, 
            0xF0F145CD7283FB50ULL, 0x1376A9A9B59305D9ULL, 0x743F2DD330A90472ULL, 0xE9C0995DCC69C803ULL, 
            0xD7E9BC6975C8BC44ULL, 0x25C36BDF44CBD7ECULL, 0xEC6C9EBA2A5AAB22ULL, 0x72E038A9AF2E15AEULL, 
            0x81B51F84940C7772ULL, 0x7F58440293CB79C0ULL, 0x63E98AA425E51286ULL, 0x23B1F1207F580BEAULL, 
            0xFD1649104A7C285BULL, 0x7CCBE90EF85E96EFULL, 0x8B823A4312898480ULL, 0xE2BC902B964F3386ULL, 
            0x7E68BDABF1E29DEBULL, 0x31A9447E5C069C1AULL, 0xC5F0232E8AD4579CULL, 0x101BB55B2FF59C71ULL, 
            0x3899B0D08A85B7FAULL, 0x8DC281BE490857CBULL, 0xA658369675DF05BCULL, 0xF14B619823071F6FULL
        },
        {
            0xE71FE7FB8036AF63ULL, 0x2E086AE1FBCB2DE4ULL, 0xC3AF49A2F9E65570ULL, 0x538524BECC1C79EDULL, 
            0x7DD79A4AD9EBA5E8ULL, 0x3FE01A47F82BA22EULL, 0x26372CA3B90D1C68ULL, 0xB0A946E8C4C3F378ULL, 
            0xDFA36367EE3FD617ULL, 0x053338E1EAF61A17ULL, 0xB38047689D318F47ULL, 0x4B96E2CBA86DF4BEULL, 
            0x0C4BF6BEEB601CC2ULL, 0x948E628EA5B90422ULL, 0xC2E164590ED4F19EULL, 0x8507667F7188FCA2ULL, 
            0x491F349626AD8303ULL, 0x5F9F69612BBA59EFULL, 0xAACB8D97B7279B2DULL, 0xEEDD1D33052A5394ULL, 
            0x8BF952E095295184ULL, 0x4065371D34BE4DA4ULL, 0xB36FE8715399B44EULL, 0x7581C2AEF9BEA28AULL, 
            0x85E1F471869F72ACULL, 0x3B0E12613785322EULL, 0xB72B273EAC302A1EULL, 0x40BF159A94D09510ULL, 
            0x2E81B50528B71465ULL, 0xEFDC5C963D9770DDULL, 0x7AB52B38E684A23FULL, 0x39311FE9F27C245AULL
        },
        {
            0x28923372EDE405D8ULL, 0x4BEEE86AF3B072ACULL, 0x3F39318519EB034FULL, 0xEF42B943F7BFA6B1ULL, 
            0x08F90DB50454D645ULL, 0x2DC8CEF6A63C2FF4ULL, 0x1F91C0762410BBE6ULL, 0x0FDFC8C246F7A63BULL, 
            0x1234AD003E90E2B0ULL, 0x40D23D5B7F5B6717ULL, 0xC1C720FFA6A15ED6ULL, 0xF20755EE8CDE3507ULL, 
            0xA3341F47824B5F9FULL, 0x7BF7735144D1659DULL, 0xB1AE0AA2D6D9DDADULL, 0xAE3ACFF959BF5CFEULL, 
            0xA8B7A2B3E7C4C14BULL, 0x867DF8EEA535D7C1ULL, 0x8080CC140158050FULL, 0x8A81DF5BCE411DD8ULL, 
            0xE1E070D121E0FB8CULL, 0xA0AB795AEE8BF53AULL, 0x93B31B03D36B45A3ULL, 0x2E5040DF56D141A6ULL, 
            0x4578361588B2507CULL, 0x8E91F3617B37F01FULL, 0x1644C5E5F3280080ULL, 0x41ECFCF07930E9D7ULL, 
            0x78B3B9004DEC9B26ULL, 0xB10074AA91B25340ULL, 0x812B3891E43EBD91ULL, 0x524AFDA40D928041ULL
        },
        {
            0x51A2EF368F596A4EULL, 0x638DEEA8288FAB4AULL, 0xFEFAC6177D803885ULL, 0x442237AF92901B54ULL, 
            0x75E3E40A3FD71F3BULL, 0x7D6107DCEB749E6AULL, 0xF0AB1CC7C5CAC69FULL, 0x617BE0646A5D5AA4ULL, 
            0x67C7BE11D0AC5566ULL, 0xC292FAB7F1F69E1EULL, 0xC7D7FE24DE88A1CCULL, 0xC08E8DC8044F2C28ULL, 
            0xC1BE92DCE14774F9ULL, 0x21A370612E8442F7ULL, 0xD6870FB96A2F17FCULL, 0x966B5AF61842339EULL, 
            0xDC8D05D311248D84ULL, 0x271FE2BD2146243BULL, 0xD7D6F6BDC08F145BULL, 0x2FC6BC2420D97717ULL, 
            0x50421169DBDA45ABULL, 0xC43EA3633351AA30ULL, 0xB51495C9B9B17AC1ULL, 0x38FE06F3FE98174FULL, 
            0x1D705E159DF58E86ULL, 0xDEEF6B6DF2D604C2ULL, 0x9B2C817014DD8442ULL, 0x288FAEE66C5953C1ULL, 
            0x7BCF5C2F5D43F491ULL, 0x7EBD30D05C16A7E8ULL, 0x7742718265AE912EULL, 0x1B337E328C966F99ULL
        },
        {
            0x86B8B371C9BAA42DULL, 0x8AA46CBBD95790F8ULL, 0x40ACE65672C7BC45ULL, 0xE20A62688F8190CDULL, 
            0x08C06ACA55271C50ULL, 0x6C91A2DB88E32FC3ULL, 0x0A58819B6907AD0DULL, 0x18D3BFB0E7D9A5DEULL, 
            0x93D449E95CDB33C8ULL, 0x2C9262422C0B1A21ULL, 0xE2F29C62B02AAA23ULL, 0xCC003895B391EAE2ULL, 
            0xDEA2F18B10A9BE7AULL, 0x8F8774FBAB86280CULL, 0x95F65535502B229DULL, 0xB94C51D9C29EB9C6ULL, 
            0x2241629EE23DE773ULL, 0x436CC7AB74942D16ULL, 0xB219DC1304CA3B49ULL, 0x87E614304F37EF39ULL, 
            0xF6155E4507DF9637ULL, 0x3659D9EA8E996631ULL, 0x2FA17AF5E710C945ULL, 0xD91E27BD1393A3BEULL, 
            0x364C81EA3D550244ULL, 0x7C045E9D85BFDB7CULL, 0xE9FFC44528BBB893ULL, 0x15EA3EE10235F3CCULL, 
            0x98DBEC270B47BA72ULL, 0x13DADD4D681AA0B9ULL, 0x49E155E5679E3AAAULL, 0x46054A650A0269FEULL
        }
    },
    {
        {
            0x48A7951418D69585ULL, 0x48D381237DB0C4ACULL, 0xAD37853B7EBEE0A9ULL, 0xE6A2FFA33841CF39ULL, 
            0x492B53F491507D81ULL, 0xFBA71A26FB975ED5ULL, 0xD402865715D3EA49ULL, 0xFDED098B32398091ULL, 
            0x66839C595BB0A328ULL, 0x5AC33439B9C0BFADULL, 0xB51EBF62F57DB562ULL, 0x0F83FE285A19B5BAULL, 
            0xA419135DCDD075ECULL, 0xE22893D8216BF598ULL, 0x3518199C52666636ULL, 0x53B4DF9A6A4A503AULL, 
            0xFCB29FAE09E3A3B6ULL, 0xA14B984044C861EAULL, 0xA05F979914911D45ULL, 0x8B24980182174014ULL, 
            0x0416854FD8E16A95ULL, 0x7B6BCB28A6A62963ULL, 0x311B7B71778577EDULL, 0x264E6C898B1702E0ULL, 
            0xC147F9BD3B195640ULL, 0x7F3E3D2C05E6B855ULL, 0xB380A22B62C29E59ULL, 0x22872BB72D8C4C4EULL, 
            0x35FF838F1D1F4A73ULL, 0x7B7AE154B0FACC87ULL, 0x586E62190B019CA4ULL, 0xBC0B1DAD64BEF832ULL
        },
        {
            0xB525A75A7191FE62ULL, 0x239F36735B7542B3ULL, 0xAB2D4154FCDFB7C6ULL, 0xD4507FACA923EFDBULL, 
            0xAAFA68D4C20B7376ULL, 0x451697DEDD24DAC4ULL, 0xF08ACC65FE97B9EFULL, 0x13C063682C3FEF62ULL, 
            0xC637C269FF1CA91CULL, 0x04C368D98DEA8495ULL, 0xDBE638137510B602ULL, 0xC0ACE596A34D1826ULL, 
            0x6AA48D5AA2670FE8ULL, 0x30E202D13E43FABFULL, 0xC59ABBAAD56B9FBFULL, 0x6CEAB9D26B876427ULL, 
            0x6199804945938427ULL, 0x452BF5973E83B70EULL, 0xAA1234DE09F31606ULL, 0x03D9C5A402AE0B74ULL, 
            0x8294C406ACC451D1ULL, 0x5C3F693F41DBA600ULL, 0xB1B7D0E560BB71CFULL, 0x5BCCF3B3EB4EDFABULL, 
            0xB1391F1B695EB416ULL, 0xD059562C7FF69B53ULL, 0x993DDDF50B809A14ULL, 0xC5B8FAD453929E9CULL, 
            0xC909CDBFFD56B6DFULL, 0x00DC51627CA781D6ULL, 0x7BB888EE8582FF80ULL, 0xF2C2F6D0D15EED28ULL
        },
        {
            0x7E1BB2352911DCA5ULL, 0xE0EB11179A864072ULL, 0xFB32518D1DF0CEFEULL, 0xBDFD3DAE77851223ULL, 
            0x0A5DE35CCE0D6874ULL, 0x89646CFA6680C82CULL, 0xBC429BECCB04DD0CULL, 0xE4C9473682006694ULL, 
            0x36EC898808D93732ULL, 0xF3161F8A5DCCE429ULL, 0xBE37D6A9B6842E74ULL, 0xDC9C06597C42596EULL, 
            0x16DBED4A32837AEDULL, 0x0A06EA141781348FULL, 0x7A3EDC66EE922FB5ULL, 0x456EBAE82565A30CULL, 
            0x1AA47DDBE80DC6B0ULL, 0x9D794BFD7C4607E1ULL, 0x1FF6A2FE76323028ULL, 0xF4D306151D9AAC77ULL, 
            0x319499528EF2B4E0ULL, 0x803DE1536A2D6D12ULL, 0x8B208FEA4DF79F1DULL, 0x0FB0986F27683B7DULL, 
            0x93BCD300980F36CFULL, 0xCB209414F04B6DF0ULL, 0x200E378169FD703AULL, 0xA4CF18F0DD07259AULL, 
            0xDAC877AB9BFBE44FULL, 0x9ADBF5EB083D183AULL, 0x96035F10359EA4F1ULL, 0x9A8FA846DB81EC92ULL
        },
        {
            0x58A9D44E9FE466C7ULL, 0xF43D0CE3E93505EEULL, 0xBBF5EB83BAAD73C9ULL, 0xF5818168285DDF39ULL, 
            0x8CA5F253C95954A0ULL, 0x3B9229A5214192FFULL, 0x02DD26DE632F905DULL, 0x23247B5AE64B1F73ULL, 
            0xB1DFE831843DF57EULL, 0x6B45802B1528EA60ULL, 0x692C77D68D9D133CULL, 0xC939B587BF5BDD29ULL, 
            0x1BCB03A887271EF5ULL, 0xBBCA2BD651153126ULL, 0xCFFDAEB7146DA980ULL, 0xD8AC1CCD7F24F29EULL, 
            0xBD7796F293394E55ULL, 0x314AD93F39069FDCULL, 0x55238BAC513E12F4ULL, 0x1307C3AB4C04DF8BULL, 
            0xE37D0F16B4FFC329ULL, 0xBE582E99E984F653ULL, 0xDC28D2A35E8DC334ULL, 0xC87F0EACBA32511BULL, 
            0xF04634A97380FCE8ULL, 0x092222548074393EULL, 0xD656E0E0AF8C9439ULL, 0xAB1395AC1877BA09ULL, 
            0x269E7A98DC2947BBULL, 0xE83D9D29DE7D6A8DULL, 0x5D42821368036521ULL, 0x03ABF4C8F6AA9645ULL
        },
        {
            0x5694C3FADEDCC6DCULL, 0xEDD3786D60F50123ULL, 0x0991EC85E13AFAE7ULL, 0xA67C7696C5DC589DULL, 
            0x793E7D97D01C4C2CULL, 0xF3D1B3ECDCEFEBF3ULL, 0x479DEAD7DAE455D9ULL, 0x10CEDE9CEDF1102DULL, 
            0xB4DF3CE41AA33507ULL, 0x44F5D22A9187A616ULL, 0x5B107CBC0019B467ULL, 0xAAF26450F58BEB96ULL, 
            0xE5C6D2B4674EBFB6ULL, 0xF5E1C94D24C8B800ULL, 0x3487943113580999ULL, 0x2DB02231D0DFFC61ULL, 
            0x60F15B19EC45B842ULL, 0xFA4866778932F79DULL, 0x40AAB5DF849EE7CCULL, 0xE4C5C2F92A0BB6B5ULL, 
            0xD9CD7C7DF0ED509EULL, 0x57E79676E5BDD3EBULL, 0xB5CC35270F45E3F2ULL, 0x58BE4FF712AD2859ULL, 
            0xB507E52543192785ULL, 0x9B18645D976774FCULL, 0x4FAB14BC2BCC7979ULL, 0xE8A4F67F086C9C38ULL, 
            0xF4881D010E59E2F1ULL, 0xFB44E7B6CB336F00ULL, 0xDAFE22C79CDC4D2AULL, 0x80933BB90B060B40ULL
        },
        {
            0x8786BCC7D32205C0ULL, 0x4FE520B09B3E3018ULL, 0x8CB86A58100A92CBULL, 0x87F81BE1E5510985ULL, 
            0x2950C272623941F2ULL, 0x5174A247CCA8C53AULL, 0xBCCAD247BE10610DULL, 0xC98337C8559E541AULL, 
            0xC7B8E672F69362F8ULL, 0x78E5656B9A232420ULL, 0xD6906C6BC30112ACULL, 0x80550B04389FF7ACULL, 
            0xFABA4A7095E4ADFFULL, 0x50F27D03EDF58EC6ULL, 0x64417FF352E3D724ULL, 0x43CFA42B811D9A3EULL, 
            0x388D69358C12B7E4ULL, 0x489A48366B85896BULL, 0xA93B2AC97184477BULL, 0x479251DCB037680CULL, 
            0xF5E50E4669375981ULL, 0x5E53E2247DBDBADAULL, 0xE2AFCE7230D787C7ULL, 0xA9FAD7812F073239ULL, 
            0x3EAE8B64A7B19BA9ULL, 0x544464A63F7B3C45ULL, 0x7B2F85990FC39934ULL, 0xC23C786FFC485934ULL, 
            0x36473B26C36686A7ULL, 0xBF527D82CD12D8D3ULL, 0x3CDC837C6D6D308CULL, 0x5EEBEC72958A420DULL
        }
    },
    {
        {
            0xAAD7BED4686945B6ULL, 0x724865C48F1BD94DULL, 0x8382B0BB1B53891CULL, 0x2C980C5CF476E9B0ULL, 
            0xC5DB9BD4AF84DB8EULL, 0xCDEB5466E0DE04F4ULL, 0x917F6B1CA075B2DEULL, 0xDC2D7F3EA4B7CEC6ULL, 
            0xB47BF78C472C081DULL, 0x07DB42E83410C4F0ULL, 0xCB8A4C4BE5551CBBULL, 0x98A7F48666F9462BULL, 
            0x946A0ED884688682ULL, 0x0586A5B0B5068712ULL, 0xE9C96463AD90D636ULL, 0xCD6039A78FCDCDC9ULL, 
            0x56B4039CFD549AAEULL, 0xBD9935BF5D78D783ULL, 0xBC9BB368167FE33CULL, 0x13870030415C5387ULL, 
            0xF25DB852F223BAB6ULL, 0x951502EC32239899ULL, 0x3637A18D8904A960ULL, 0x120D01A5CAD050D1ULL, 
            0xD3E691C2EB51EEB0ULL, 0x61A6747DCDC7CA6FULL, 0x3705DC728143D460ULL, 0x1647C9716AB9412AULL, 
            0xA7945CCC73297E11ULL, 0xA02581524AB16342ULL, 0x3C272FADEF45F759ULL, 0xE870B5AFB42301B5ULL
        },
        {
            0x7E2A1F3E042D31CEULL, 0x7402EDEEEC670FFAULL, 0xB473E0371197DB3EULL, 0x848439C901290FD8ULL, 
            0xC50A5450E9A9E43EULL, 0xB39474F352FCD1B1ULL, 0x90D1305462768AFCULL, 0x18820A32ACDB8A07ULL, 
            0x5620D54B345DD2EDULL, 0x9B486CAB81FCEA62ULL, 0x4F8E221A186A6FD2ULL, 0x604B88D9B81926DEULL, 
            0x1AF75FCA8CD742F6ULL, 0x8D80C889178416A6ULL, 0x04CBA614AF6C9630ULL, 0x6921A9CDF98105F7ULL, 
            0xA33AF80BDB696B78ULL, 0x4991BC9128A6B053ULL, 0xAF5DDB854E46ED4CULL, 0x80CD37A1DF31518EULL, 
            0x384767FB4D615895ULL, 0x7079372E971E695EULL, 0xE8F9CE21F9897415ULL, 0xCB3DA9EBA9641FA7ULL, 
            0x767E10CEC03EF6ECULL, 0x2D91EED0C6449F29ULL, 0xF7B263CC68440D58ULL, 0x62ECA4A79AFB787BULL, 
            0xB5A598FFCBE051F8ULL, 0x75E97A032E769715ULL, 0x2409351067FA8E6CULL, 0x4E7C1EC0E36FAD3CULL
        },
        {
            0xAAC663EE6F2465C6ULL, 0x81D32FDE6915C82FULL, 0x66FF0FC5C907BFCCULL, 0x3C3CFA461F477437ULL, 
            0xC5A09D1392DBB533ULL, 0xCEA61F6982BDF060ULL, 0xB6BC9BC40D403B8EULL, 0x6743DB1F2F218139ULL, 
            0xE19856DAEE17A9FEULL, 0xDEB2FDA26F7C5298ULL, 0x2561A90467FA1381ULL, 0x926CDC842959EDA3ULL, 
            0x8960D77DEBC631C9ULL, 0xF7E4C9BA2A0F24CCULL, 0xEDFF17A9666F359CULL, 0x5551EDD9D2D9DB9BULL, 
            0x1031EB673C7D1C08ULL, 0xC922B3EA222530CEULL, 0xB29569F0BF3B0CADULL, 0x6A3457DC5DE933FAULL, 
            0xFEBB971344CCA219ULL, 0x15D9E16789784EF8ULL, 0x234D16EC67EDDF9FULL, 0xC8CA7EECD370C62DULL, 
            0xE1E296690A6B3634ULL, 0xAFFB6B04619F5A26ULL, 0x23FC274C1B4C62F4ULL, 0x6BB3DB36EE95CF0BULL, 
            0x7E4F95535C70E409ULL, 0xB7A5CA8D9C724CF7ULL, 0x242E1CA8DF5E6C0AULL, 0x9B665F38907BFC2AULL
        },
        {
            0xA570AC04AD8491DDULL, 0x366E35E569F4681AULL, 0xADFBE40310EDFAD6ULL, 0x5FE70264AB2EBE75ULL, 
            0x8603F78ED4C9DA55ULL, 0x8201B6644ED69DEDULL, 0x12B643E67A9BFC92ULL, 0xD5F3A49C37C1BC3DULL, 
            0x7F8A4139854204B4ULL, 0x0A38C9F0F739C1D6ULL, 0xF258303298442914ULL, 0x8C128240D936A65CULL, 
            0x345A121789B4F215ULL, 0x8E78EAA696B4A591ULL, 0x3882E775E0F9AC3BULL, 0xDA02F2859043BC2EULL, 
            0xF441A27F8413343BULL, 0x1E27E03E2D98D993ULL, 0x869349C578DC2319ULL, 0x6B909CE4E38CF469ULL, 
            0xA6A36E7890E0DABAULL, 0xAEB048CED667B910ULL, 0xD79CB64CF44B1083ULL, 0x3DEA5AB511A02D9CULL, 
            0x5EE9DFA035A1FE1EULL, 0xB26935CF61E50AA9ULL, 0x1619EB800157A389ULL, 0x3492FF30D6FFA01AULL, 
            0x83FBD91AD6860654ULL, 0x6F00FD8062AC3E5EULL, 0x9A6B6029538147E7ULL, 0x17480C10FCEC9055ULL
        },
        {
            0x5F8ECAC6531FEEAEULL, 0x1C719DF93188D840ULL, 0x44C29CD00E042DA5ULL, 0x6AF030F990407F8DULL, 
            0xA2A4B8675664934AULL, 0x6B70A1FD919C853FULL, 0x45B3776AE4A91F98ULL, 0x39BAC9AFD42DFFBEULL, 
            0xEAC63A7A9A346747ULL, 0xA090B8F1826CFD50ULL, 0x938C194A37EEAFCDULL, 0x7EF69B4B3EB79D8BULL, 
            0x1143221A1F308CBBULL, 0x52C9E4DE8F4912EAULL, 0x12F097F2A46D20B1ULL, 0x6FFE5BC3CCD3512DULL, 
            0x8E2AF8DD8ADC089CULL, 0xF26904BD16E6A987ULL, 0xAC2817E0277BC0D9ULL, 0x4E3C4D79C15E426CULL, 
            0xE5B7003432161A23ULL, 0x3CC9035FE9565180ULL, 0x37C9B710EC1E4380ULL, 0xA7C4DE0105BC0E96ULL, 
            0x99A1DF8B6C3D35D7ULL, 0xDDA2578D692AD9BCULL, 0xC51A550A29B4070FULL, 0x9303237A7257B210ULL, 
            0x1CDCEA63E1D64956ULL, 0xBE4CDDD249AB88D9ULL, 0xF2E78152E91454ABULL, 0xA6B8997C1E90670AULL
        },
        {
            0x00A8E4D193160ECDULL, 0xC39615CC2118741FULL, 0x884F9A121E57665FULL, 0xE3F51BADF92F3E70ULL, 
            0xDDD4644A5945602EULL, 0x5F2C6EAAE0D2CF72ULL, 0xBB66F4128A365DB2ULL, 0x6219DA2ECB0E3809ULL, 
            0x68B4D9E25F439299ULL, 0x0C547035B60C33C5ULL, 0x2C8B85CB7B6681DAULL, 0x00E7988D97AAB6B1ULL, 
            0x79ED27938C841540ULL, 0x70EFEC22F5CE45EDULL, 0xF49D5BCEB5C86DFFULL, 0x794076D7BEC252CFULL, 
            0x644EB185D4B54A9FULL, 0x44CB1DF8BBF3DE2CULL, 0xB16FBAB2F033EC72ULL, 0x38F46B2E56BA6497ULL, 
            0x951DEE1D07D8468AULL, 0x914F99AF09F1E5EDULL, 0xEBC527A8B1D83F3BULL, 0x082B5B0122086DFCULL, 
            0x1E9445FCE2358062ULL, 0xEC103B460D676284ULL, 0x90122974CFB8238EULL, 0xDF6E6DA870287E5AULL, 
            0xBB7DC9A3716DA2B8ULL, 0x1B7FBD883891D263ULL, 0xE4E709BDB4A8EE10ULL, 0x85E9383B79590044ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseBConstants = {
    0x3AB909D089B4ABB5ULL,
    0xC48AE0A90FFDD677ULL,
    0x2F25E309CF2D3D39ULL,
    0x3AB909D089B4ABB5ULL,
    0xC48AE0A90FFDD677ULL,
    0x2F25E309CF2D3D39ULL,
    0x923B94E007A2E0CEULL,
    0xA7F7EA4CB4C2E760ULL,
    0xE2,
    0xBB,
    0xA9,
    0xFE,
    0x71,
    0x53,
    0x4E,
    0x20
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseCSalts = {
    {
        {
            0x055E38BE592A46DEULL, 0x2D67FB5CA0707480ULL, 0x428786481FB870C0ULL, 0xFE22B5FABE4B88ABULL, 
            0x25DCD571899C383EULL, 0x3BE392DF9D32C7DCULL, 0x33D221BBB39420EAULL, 0x9C635882F41A5EE2ULL, 
            0xDB1901B3832B0234ULL, 0x4505B23D24E8D5A5ULL, 0x512616498C2A3D00ULL, 0x1745BD318CC411AAULL, 
            0x88BB25F1122942D7ULL, 0x33CBD28688DC3231ULL, 0x100141DF787F794BULL, 0x74EF5911432AE4F3ULL, 
            0x711819CA808C85E2ULL, 0xF6B9980A0CF0AEFEULL, 0x1F51A54EFC91109CULL, 0x3206FADC43D18C85ULL, 
            0x47CE51B228CD1CD8ULL, 0xC8639EA5A8175D0FULL, 0x2E1E90666F27AB3CULL, 0xEEFA127B75B9B6CDULL, 
            0xFBEB23484C0EE527ULL, 0x9B4C79DB396978E9ULL, 0x9391F6923D66CE3AULL, 0x1B349B9B4562A426ULL, 
            0x83D32C4D57508DBAULL, 0x80B3D7EC23546AE8ULL, 0x756D3C69BD742284ULL, 0xDEFF44E57AA090A6ULL
        },
        {
            0x6E2D5F4BA49650F2ULL, 0x137F6AA40D03094EULL, 0xAC99F833C2DE82EDULL, 0x4DE57CB024899792ULL, 
            0xAE4859C79FF7547BULL, 0x9C75465A0684C8D0ULL, 0x711AFC0CDF40528CULL, 0xDC75EBC125DAF6F4ULL, 
            0x892D1055C83DC361ULL, 0x4706500911FA97AAULL, 0x187E768B25212E74ULL, 0xF1137F336C536ABEULL, 
            0xE92B9712A3127065ULL, 0xD1B9F023C33DC06EULL, 0x5A316DB574D7F0B3ULL, 0x134CD40A050B3BBCULL, 
            0xDE23DD7DEB2DF2F2ULL, 0x78390171DFC1A7FCULL, 0x87FB4CAEA0627FD6ULL, 0xB03280BF57B4DD49ULL, 
            0xF451637F1DA5637CULL, 0xA479C449DAF320C0ULL, 0x9FACD9107402D2FDULL, 0xB7A8422D69A5F54BULL, 
            0x7ED15B88BEDEC514ULL, 0x6F6202314B864760ULL, 0xD45865207D4AEEECULL, 0xE8DAACD6198DAE64ULL, 
            0x0738894130063A61ULL, 0xE3FF66FDE37B4B6FULL, 0x0FD0B48C9644AC8DULL, 0x8DB306286D57D7B4ULL
        },
        {
            0x43DA8ECF2FD3AD91ULL, 0xB6DE2ED698BF8FF3ULL, 0xD69FE0F09829FCDDULL, 0x15755AC98124A99EULL, 
            0x226FAF421C520B58ULL, 0xB0E43943644D242DULL, 0x96D86A0AB69C75E5ULL, 0xD464DCC18874EB73ULL, 
            0xCC2FF05E84B355B4ULL, 0x475B28BBF9966319ULL, 0x53EF450EACF57C3DULL, 0xEDD0698E5E1EA01DULL, 
            0xA03470AC499381DBULL, 0xCB924B4FE27F350EULL, 0x3B192D63257155B0ULL, 0xCE26668367181819ULL, 
            0x33BD9163684CE785ULL, 0x96649508F5D4CCAEULL, 0x8D18072F9E47B1C3ULL, 0xC78FA0038829B1E8ULL, 
            0x10C828A922D9E58BULL, 0x30E34A1A57240C34ULL, 0x319D33D397BD4B28ULL, 0xE3F4BFE4FC6D66E0ULL, 
            0x4647AEAA07A27EEBULL, 0x3B79DA36D88FA247ULL, 0x5162C9353B6142AAULL, 0xF112684BD845701CULL, 
            0x67A74222B047C40BULL, 0x43E673A9580E46D3ULL, 0x6C1211BA311190AFULL, 0xED2CD766378D0445ULL
        },
        {
            0xA6D62C9345E7CDC1ULL, 0x149CEAE19B0ADE9FULL, 0x1AF23337E27E9E32ULL, 0x1A00461ECB0DC1C4ULL, 
            0xE7F453236DB5522CULL, 0xA576E0C76A55A272ULL, 0xC60954446459114EULL, 0x7640C3A5BFACB38BULL, 
            0x30DE2998596ABEAAULL, 0xA2DCDC7C6967A950ULL, 0x875DC63A4761C7EFULL, 0x68DFC8D9D73FC2BBULL, 
            0xE88B0FE9DF96B1E4ULL, 0xC4FB929D886C07A9ULL, 0x843482BB2EC2678DULL, 0xF0F49DFA0FB79960ULL, 
            0x80A6D9337EBC77C5ULL, 0xA103404DC77673D6ULL, 0x02AF890E91788F86ULL, 0xAF0FB4D20BFDC07FULL, 
            0x025E4DD51AC799DEULL, 0xBFF859EF7D215F11ULL, 0xD35E0E571FE3713BULL, 0xCD926153DEF65C09ULL, 
            0x7FDCBB399FC65A7CULL, 0xB4E11C92B3AD1A1EULL, 0x7C8BED7A0F942C4FULL, 0x7CA91C0328EFD6CFULL, 
            0x7197A49BE145D111ULL, 0x29B5B26364DA9148ULL, 0x655E08A8F3EF2303ULL, 0xF5D11F9290B9FE71ULL
        },
        {
            0x683A96720EEA7D96ULL, 0xBF5A8EB024E103A3ULL, 0x27074A3A8F710302ULL, 0x12A01A37302A6293ULL, 
            0x5D5AF779D42D8A46ULL, 0x3A144E5E14471D3BULL, 0xB36F26E67D95DAD1ULL, 0x3FA9CED22F7C6265ULL, 
            0xF4D29DBDD897AB12ULL, 0xA8004DAAB9223172ULL, 0x111869B66FAA9AA1ULL, 0x8F6370BDDA94D7B5ULL, 
            0xFF943A8B59E54582ULL, 0xEA889A0725892E70ULL, 0x67C54D4CC38B9DBCULL, 0xBE2BCB919CAA96DEULL, 
            0x4E239CE34C5B4AFAULL, 0x4AF9CA2B82DBAF5EULL, 0xAECE8632CC92E6ADULL, 0x7216BFAD86EC7018ULL, 
            0x449E05BA2C7E9111ULL, 0x5CDB8D8747771FABULL, 0xAF06BAF94816F4B3ULL, 0x21781A9ADFA2080EULL, 
            0x0DD39DC776D34F16ULL, 0xD6CA7B2C0C187385ULL, 0x1BB3F3A22841F86BULL, 0x26DE07502A0D1203ULL, 
            0xBF3DFA9812B9D837ULL, 0x2C2A83340612548EULL, 0xF2030EE471258FE9ULL, 0xA7B7A6420FF26936ULL
        },
        {
            0xAB926FD60B1517E4ULL, 0x113E1D5CCA083169ULL, 0xEA4A3A80FFA09010ULL, 0x0192B6FF9D6CFDF0ULL, 
            0x94F18BDC63BCDF20ULL, 0x20139C5A7E64ABAFULL, 0xFC82C84035B836F0ULL, 0xB74C04BF473B2022ULL, 
            0xD25EF36F97CFEBB3ULL, 0x2E2A04A639DCED9CULL, 0xA6093DCD5AAF3E4CULL, 0x3C4F21AAF1CC7AEAULL, 
            0x96075BC9C8963F0BULL, 0x7EC36FAB7F59AE35ULL, 0x88FE4E4D05D0F7EEULL, 0x9952129110BDA110ULL, 
            0xB62BD4CBBF5F505BULL, 0xBD43B032CA994B93ULL, 0x107C1574E56A0027ULL, 0x80A6D96CE2705B33ULL, 
            0x574ABC374C99D99CULL, 0x385027EE22A56610ULL, 0x33CD0F68A51FE006ULL, 0xCEDDAAC79D16A471ULL, 
            0x4B14ED43F355CC3BULL, 0x2B4FCCA4540B6CB9ULL, 0x3AFB0731B0D08BA0ULL, 0x7C17142FF0F0E767ULL, 
            0xF944D46DEE8B7981ULL, 0xC5923F947D35B4F2ULL, 0xE1E0044103E34CDCULL, 0x13FEEFC39701BB38ULL
        }
    },
    {
        {
            0x2BFA62A835572992ULL, 0x450A3C81850479B2ULL, 0x3C8D11ABE9839D02ULL, 0x23F8E1CBCABBB2F3ULL, 
            0x18F7511A71BDBF9EULL, 0x2283F94C1408DE72ULL, 0xE6F696FBCDD7998BULL, 0x4D12FF34F4623FB9ULL, 
            0xA2AA43B28711B437ULL, 0xB3B23885ED665646ULL, 0xC0EBB27A34F00DBCULL, 0xD86F9CF4B750B5F7ULL, 
            0xF19A133C7DD7D7BDULL, 0x371FA883DBF4CD81ULL, 0x642453D8D0B04B41ULL, 0x9CA923419E646960ULL, 
            0xA4A6B6805CCAB1DDULL, 0xEB6C8FE08C901F47ULL, 0x6F83CC1129BE3FCFULL, 0xBE4A9E37FAD25110ULL, 
            0xEA62748DB5E416EDULL, 0x3777DF1D73ED7258ULL, 0xDE97846CA0A36E16ULL, 0x116AD5C3C6F960CCULL, 
            0x4BFBA525574E8ECDULL, 0x72D9594183FFC43EULL, 0xC18EE51FB2FBB3E4ULL, 0x333B24C8716CF749ULL, 
            0xE0A30A6253BC936CULL, 0x77802CE9E2A5C731ULL, 0xBE29FA8DB8DC9A0BULL, 0xF9F2E29075219251ULL
        },
        {
            0xBD21386986B09D05ULL, 0x7AF6E7B975005190ULL, 0x61A6712C4BC288C7ULL, 0x0B0353ED868CDD21ULL, 
            0xEEF453340A83A3F0ULL, 0xC1B44BE1076BCB30ULL, 0xB19869C449660887ULL, 0x1D6347785788AE59ULL, 
            0xF2FF3755D66C9572ULL, 0xA383E9439A04D4D7ULL, 0x9D942C15173EED31ULL, 0x4215F6FAE0ACC485ULL, 
            0x8290CD802AF24F5DULL, 0xF258887A57A5449FULL, 0xBEC987B320C8FBE4ULL, 0xD5BF43435B24883BULL, 
            0x9083EAD7614939D0ULL, 0xA45A0DC2B5A4EF35ULL, 0xA418EA52157CF0FFULL, 0xBB948077C126AD1EULL, 
            0x5D62F4302073DFC2ULL, 0xABEB648F36678C34ULL, 0x6CC106CC6CCACCF1ULL, 0x06C1994FCC67B876ULL, 
            0x2F5460D3BBBF56B7ULL, 0xF359A37615BB0D65ULL, 0xB972260B5709C914ULL, 0xB130E369C2E233D0ULL, 
            0xA65E869F7A134199ULL, 0xE4EDF349E23EA706ULL, 0xEF92AAFE0614FC0DULL, 0x979BE8E8889B4CDAULL
        },
        {
            0x0860FA236F5394B9ULL, 0xCD8B483797B5566DULL, 0x910D48C73CAD5D60ULL, 0xF11C7CC7D385E5B3ULL, 
            0x4E69173BF6DFF2AFULL, 0xB9E4DE7DC1643F3FULL, 0x33D60DBAA259DD28ULL, 0x9BC4059B38B9B958ULL, 
            0xD587EC4B39570DA9ULL, 0xCA65E37997723490ULL, 0xB3B09DBCFB1C029CULL, 0x0BE2BB48136771DDULL, 
            0x8876A5C868308229ULL, 0xEB2F383A257E1F57ULL, 0xB0BEF06499F7E97BULL, 0x1CC20F4E22DCB11FULL, 
            0x6CCBA8EAC8DBCA26ULL, 0x86708DAE6BD7916BULL, 0xCCE4A83C0B06ECFBULL, 0x6F984ED96A20CBA9ULL, 
            0x82B41B9467CA0684ULL, 0x9E707AEE2C222D3CULL, 0xA5B6EDFB2B90FAF1ULL, 0x2BA098136EA42C29ULL, 
            0x1140845712CD3C6FULL, 0x5C1BCB82292B6617ULL, 0x7529DAE5DF3CB19CULL, 0x13825EC97D76DD3AULL, 
            0x5CAC2834E9C654CFULL, 0x05D708AA147D452AULL, 0xE1822F1C2D9B40F0ULL, 0x0D98C52554A3E0F5ULL
        },
        {
            0x6C02D146D4110F71ULL, 0xB37FBDC1693FFC3EULL, 0xEDCCC834A5520B7BULL, 0x2750F091A87B4E9FULL, 
            0xC40AC4ECB463DF28ULL, 0xCC7CA5A9AB4E668AULL, 0x4D192484AE872E13ULL, 0xC992595822DBEF05ULL, 
            0x52B58AFAAAA6671AULL, 0x69E36251FEE51288ULL, 0x293BC31C5DDB78F9ULL, 0x1B6A2095B382BB28ULL, 
            0xF34F12A39ED171E2ULL, 0xC45370CE735C7831ULL, 0x6AAA8FA7F066007CULL, 0x223323DF0D423500ULL, 
            0xD2F262235D8F287CULL, 0xFAF25C9F631CE05CULL, 0xFBD24F401329F0AFULL, 0xDCC9D668A82E09D3ULL, 
            0x701CA2D6688C2B3AULL, 0x01A0260FA4276EC4ULL, 0xD1D8F4482DA03A4AULL, 0x1163FB1908065C45ULL, 
            0x0336FF6D8A9F5F7DULL, 0x8724430823270243ULL, 0xBDC474153EF0E7EFULL, 0x8BCB71D8424C7897ULL, 
            0x58A87AD87318230CULL, 0xD42BB51D80EC589CULL, 0xB118B464F364EF74ULL, 0x29C2B43770A6E5A9ULL
        },
        {
            0x62E8EBF9BA674706ULL, 0x0F62BED982FA9202ULL, 0xE40AAEE529C1D542ULL, 0xAB0A4F962000487AULL, 
            0x8C6AEE270DBF0E5BULL, 0x9617FCC43AD85A97ULL, 0xE4F13DE0B84E5907ULL, 0x154FEE6B3C8B666AULL, 
            0xC585955B6CE15F36ULL, 0x16B3BB31AFADEC13ULL, 0xDE7D5D92F7581DAFULL, 0x2AEEEECB33D89DD3ULL, 
            0xC93D53FC4089680EULL, 0xDCF48C391C66D3C7ULL, 0xC76522DD8564F060ULL, 0xBE8CB693EB269CE4ULL, 
            0x49760313086AB1ADULL, 0x2A806294367F0B0DULL, 0x1006E9D413423E5CULL, 0x00539FE97B621534ULL, 
            0x95C1E4F60F54E881ULL, 0x97008116D48ADBF6ULL, 0x3CF439118F733014ULL, 0x9DC3F1A8478985F7ULL, 
            0x6FB1AAA88DF96B4BULL, 0x82299ABA2E6D985CULL, 0xAFDE55C5641EF16DULL, 0xB5C71757E0BD3931ULL, 
            0xEB977CF48D616909ULL, 0xB7AE388F8F5215DEULL, 0xD06B69987B1F57ABULL, 0xA1C127E642FA379DULL
        },
        {
            0xA16DFA2BE2DB2DF2ULL, 0x2FEC4280CBF49959ULL, 0x5F2556652C285F3FULL, 0x576D56F0C54B39A0ULL, 
            0x1BFAA60C637B54BCULL, 0x1BBCE330401573BDULL, 0xCF2BD8DD09A05934ULL, 0x9D54EA515D6E5E57ULL, 
            0x217798460902C197ULL, 0x7857C24486E70B7CULL, 0xE84AD333E4F745D2ULL, 0x59FC60A367351A2AULL, 
            0x6F130178607332CBULL, 0x29FF3FDC93F9C768ULL, 0x4782BDF6F09A2A5CULL, 0x59AC2A4945C226C4ULL, 
            0x647A75CF2CB177A9ULL, 0xC1F73306EE6F2CC4ULL, 0x7C7A141D065111DCULL, 0x91C85BAB7EAC2216ULL, 
            0x0FEF952C8A2AE11DULL, 0xEB71B14E54CAC9D6ULL, 0x83DE5CE14D2C8536ULL, 0xFF86933CE9543920ULL, 
            0xAC0F8FBC185F3805ULL, 0x951BDC3E93D02058ULL, 0xCE300B520F91E435ULL, 0xAA3AC5F9F4BD3EE5ULL, 
            0xDAE5B37DF58D937DULL, 0x8C12692023AE05F2ULL, 0x4DFC33D6D802F60BULL, 0x6966C58F3EDB5BDEULL
        }
    },
    {
        {
            0xF6D542C7780A8FDAULL, 0x5B0B0A698069C12BULL, 0xEE87FFE85F2428EDULL, 0xEA6E4962290CAAD9ULL, 
            0xA2C1B6EE5C618B89ULL, 0x08C891F936348932ULL, 0xF9497BCABFCF4842ULL, 0x62EAFE06AA36DDE6ULL, 
            0x48D28AFCAA2ABD53ULL, 0x406705F139FCEE88ULL, 0xC8B3B182E1C60778ULL, 0x1CB800DC0C1C5B7BULL, 
            0x62175D53768036DEULL, 0xE5534C14F8A8A57DULL, 0xE109BFD0FFC854EBULL, 0x56A5836369A40CAFULL, 
            0xDB8B047B74C5C7E2ULL, 0x898522C6D3801E75ULL, 0x1C384C25940974D4ULL, 0xA79D081C3B372F5FULL, 
            0x617B899D6DEC8A52ULL, 0x90CC2CE22E2D7CD9ULL, 0xE03EDBBBF18F4C66ULL, 0x18B425DACA83ED32ULL, 
            0xCBEF6F985F037DF6ULL, 0x5305B676590B7437ULL, 0xA2D96EF85F370093ULL, 0x9967BFCB1EF8FC6AULL, 
            0x101514965BF06F6AULL, 0x8BCB46174C632D4DULL, 0xD128B7A0D90D81A9ULL, 0xBE216A4B1327558BULL
        },
        {
            0x50F20D9279F1C91DULL, 0xF3101371CE2679B7ULL, 0x5E3C982011056269ULL, 0x513AE8722EB8365AULL, 
            0xDE515D85EAC111EBULL, 0x0E32BFCBB9B5C5B9ULL, 0x2C79E77B1F80CF07ULL, 0xB5E06E32870200E6ULL, 
            0xC7527C45EBDB68F1ULL, 0x33372CC17BA9C6CCULL, 0x0BA0DBF42FED12F5ULL, 0xFD5574FE758B1B17ULL, 
            0xC764216341264A0EULL, 0x436067ECEC96711AULL, 0xA4C76BE685EB812DULL, 0x89F3BCB4532DE20DULL, 
            0xD76D0B561127CD3FULL, 0xCC1A5995957BE3C0ULL, 0xB6D0567EA9B789B7ULL, 0x0164FB4EF612EC10ULL, 
            0x4E44A67DD89C920FULL, 0x54C5804673D292AEULL, 0x134B6B4983F7C6C1ULL, 0xF8861F3311954267ULL, 
            0x55AA911087378486ULL, 0x996E6EE424D4AD43ULL, 0x0F607532A949924FULL, 0x2CCF1780AA1A4D48ULL, 
            0xE5135DD6E93C49BBULL, 0x1C404390C26C2A8BULL, 0x9D59A940C4F8946AULL, 0x46E4E6CD24CF426CULL
        },
        {
            0x9A019A96B1C97AB8ULL, 0xD097664FF6C9851CULL, 0x614DD8D55194667CULL, 0xD3881A396EAF40E2ULL, 
            0x8A69456F097FC58FULL, 0xBC1ADE80A21DF69BULL, 0x59FBBFBC3D62C9B8ULL, 0x6EE3B55F04AFCA1AULL, 
            0xDC90469743CE4866ULL, 0x2B7D04994AA27669ULL, 0xCA24A7056EA78C29ULL, 0xAF86199EE6187BECULL, 
            0x1BF9348EF27E64DEULL, 0xA55FAEE0B82210EAULL, 0xBD2B491315445597ULL, 0x4005A2953AC7D5A1ULL, 
            0x73D5A39DF4D68020ULL, 0x9968819D6D0F425BULL, 0x295BE1FDAC26CE2FULL, 0x44E504C6BBC8C59BULL, 
            0x2971017B0811E300ULL, 0x2B73720198B9275EULL, 0xE801BC955D02D77FULL, 0x30D38B3C557B1AB8ULL, 
            0x0CA3F5DE76EC79AFULL, 0x8D9FE63DC0593338ULL, 0xB41F924EC6EE90B5ULL, 0x5A9315FBCB31941DULL, 
            0x9127BFE128513B99ULL, 0x7B73EB4A21C1B95DULL, 0x93F2B6E5CBF0B5ECULL, 0x5C1D21EA57FF70AFULL
        },
        {
            0x4BE7FCB1F230D200ULL, 0x321F38E327D489E0ULL, 0x4E1A7089F7F90E09ULL, 0x01E333DD51C31A9AULL, 
            0xCA6158AE0D1A880FULL, 0x1B2D117DAD74DD5DULL, 0x667284984946A99FULL, 0x24B98066EF7D8F95ULL, 
            0xBF2A77E6F1ED97B4ULL, 0xC5C2B8A1FA0D7BD0ULL, 0x4FBF1F50267B09B8ULL, 0x7B8E82908644F9A8ULL, 
            0xF333E0DFA2EF0618ULL, 0xE740D218E3507D99ULL, 0xAE8C5C44F591143FULL, 0x3054A49948AE513DULL, 
            0x0854A8ED753D9871ULL, 0x0ECC4D998CA4C305ULL, 0x3AF7FC36113699DCULL, 0xEC577BBB4E9CFE9BULL, 
            0x68E2955A3C85B25DULL, 0xFB4DACFF16D0727FULL, 0xCC8ABCD1AFFDB52FULL, 0x408173596152543AULL, 
            0xC870759B1930B893ULL, 0xCD093C5203D354F1ULL, 0x43B67B5FD436FC0AULL, 0x14DA91D5CEDBAB7BULL, 
            0xB16FB68D536009B1ULL, 0xAE671B1FFE4DD18AULL, 0x576B86891E0863DDULL, 0xCD9B2D9177069DE5ULL
        },
        {
            0x7091442D8E4B0E1AULL, 0x5D147694183723DBULL, 0x0D35857574C1BFEBULL, 0x0C0A9E7C05F8E02EULL, 
            0xA42A39CC69181B7AULL, 0xE0587F25AB4F3BB5ULL, 0x0DA121FAA9270F01ULL, 0x1586A436316CA9B3ULL, 
            0x626E48EBA83DF961ULL, 0x231B5AE536308E40ULL, 0xFEEFB7F4A6D98760ULL, 0x42F893A61694AD47ULL, 
            0xD1D995A5D3E94F4BULL, 0xEA76B10A8D70DCD0ULL, 0x8872AF62549B28E3ULL, 0x3F1F38BC0D403578ULL, 
            0xDDE355AE1275DD2BULL, 0x80641DE8DC3622E7ULL, 0x01EB3E39CDDBF746ULL, 0xBD0FBFEA79FC9CF9ULL, 
            0xC958A92E8B6BB2AAULL, 0x61E6BC8E2DC362D6ULL, 0xC94F5B37EBBEEDB6ULL, 0x84C961D888FCA849ULL, 
            0xB3398D9BE84567D9ULL, 0x262B3FD4BE6A2477ULL, 0x1F0CB95A82D44E77ULL, 0x002BEF0528DFE3BCULL, 
            0xA8DD989E78F02C4FULL, 0xF76DA5046AFE1BE7ULL, 0x62B318B678149EF8ULL, 0xF89EF2EF3300BEB4ULL
        },
        {
            0x3179F602716FED19ULL, 0xEA94F3107B24470DULL, 0x2B7E6AEA4CD1A34DULL, 0x20F5CA2D2AF96F54ULL, 
            0x06BEA96200000710ULL, 0x198C4D8BC756673FULL, 0x48FADC388A42ABA4ULL, 0x6EF395F0B5851FF1ULL, 
            0x350C3C00D651A940ULL, 0xCC578F7B98317F0BULL, 0xB6AA8DF200FC72B4ULL, 0xBCCB8A41B4079CF0ULL, 
            0x94AB0F209028C209ULL, 0x9B5C7FC701D97A5CULL, 0x5D29EABF3C8B45E9ULL, 0x3E2914FDC59E9A24ULL, 
            0x169C59156AC583EDULL, 0x6D8A8FBF278AF49FULL, 0xC82F430604F1C61DULL, 0x371451DFA523E6C1ULL, 
            0x94B4A7B9870CB08AULL, 0xCFBCF9BFCBD19438ULL, 0x892860149EFB207BULL, 0x939021B372726BB8ULL, 
            0xA3B447698DDADFDBULL, 0x450C805B87D583FFULL, 0xDA1F9016CE79D745ULL, 0x91818825EE30C314ULL, 
            0xCFFE5723A715BB74ULL, 0x3CEB35A36BF3D4D6ULL, 0xD8BE5BF1BDC1F082ULL, 0x6F0D46EA83B3FF44ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseCConstants = {
    0x70999C343C89AA6CULL,
    0x24DCC00776BF7A08ULL,
    0x163007C0AA1CA711ULL,
    0x70999C343C89AA6CULL,
    0x24DCC00776BF7A08ULL,
    0x163007C0AA1CA711ULL,
    0x74D1C08FFBA09C2DULL,
    0x89E667D7598EB6F6ULL,
    0x6F,
    0x30,
    0xFB,
    0x0A,
    0xED,
    0x87,
    0x6D,
    0xA4
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseDSalts = {
    {
        {
            0x311643962852A22EULL, 0xAC674E8E39E637A3ULL, 0xC6AE45CA065F1AB2ULL, 0xECB1167894D91778ULL, 
            0x03DC0C525CDC5A42ULL, 0xC571DE516F4487E3ULL, 0x9F8CB4AACD1E971CULL, 0x68373C359E02DE25ULL, 
            0xDC3A6D9C1732DED3ULL, 0x66743C563329DFABULL, 0x683CE514853E3CAEULL, 0x2EF2FF3D3D198222ULL, 
            0x750A498EAEB5245AULL, 0x71CFB399E1B6F3CDULL, 0xFCDD51E2DE9ECB39ULL, 0x72F63DF3C0C7063BULL, 
            0xEC5DC52D1D00902BULL, 0x3B62D86726A24A5DULL, 0xBCDD57FDB9826E52ULL, 0x0CF570E6EBD5A224ULL, 
            0x9BEA75E468F8CD9BULL, 0xAF19A82870F72C82ULL, 0xFAF08AA25ECEBFBFULL, 0xD9EDED1D30949B18ULL, 
            0x218F5A2275CEE366ULL, 0x99D981393820A5F0ULL, 0xCEA665BD4F18B0BDULL, 0x2548DEDE04CD6056ULL, 
            0xC8E1751A27DFB44CULL, 0x78BC74B9304C6550ULL, 0x3C7380E842209BE8ULL, 0x67B2B22459E839A1ULL
        },
        {
            0x33E59A3F5846BEC0ULL, 0x486DED57B6504DC4ULL, 0x1626593783854B35ULL, 0x923F45F43AC3DABDULL, 
            0x18BF1FD105BC2038ULL, 0x20687D9117E135DDULL, 0x55137ABFFDA612DBULL, 0x09AF384A7F55A6C8ULL, 
            0xAB3AD688683D42CCULL, 0xCC58BC9246A5AE61ULL, 0x27362AC9D36E3397ULL, 0x48A35C2D4C2301F1ULL, 
            0xFE197C4074C7F4BFULL, 0x27C8037EC4277CD9ULL, 0x06139C042760838CULL, 0x1D487F01BF6BDF9DULL, 
            0x143B9E4F67A964FCULL, 0xF9729FA46E58B499ULL, 0xB5A78DD4DA1B1BD3ULL, 0xD6AAC541014C2045ULL, 
            0x1220154D9DDDA81DULL, 0x6070707A3CABBEB1ULL, 0xAB163283FDA27C75ULL, 0x70FD91F710C6C55FULL, 
            0x7C20EF1EE33D7B15ULL, 0x83A1187CB6C979FDULL, 0xAD030CA81E12B7ABULL, 0x15691610FC52A417ULL, 
            0x53036CFF80022569ULL, 0xD0FBFA16E97EBFC2ULL, 0x7F35A7939B241F16ULL, 0x0D6E56B271708187ULL
        },
        {
            0x33F601E2943B1816ULL, 0xB5D56A3192AF253CULL, 0xD45773AB4B1BE99CULL, 0x014A99F1A9C9EDA3ULL, 
            0x4E630697FACA4F8DULL, 0xAC4C362AEBDDAB02ULL, 0xA6729EE8EB9DAD42ULL, 0xC3BCA514BFEAC32AULL, 
            0x43F8BFC0C1E94CF9ULL, 0x28A48C311690648DULL, 0x8D3DA67288C881A1ULL, 0xD85016792E88E302ULL, 
            0x0C90AF32CFEFF98FULL, 0x2629AA076A10D9AEULL, 0x62895433D1B9E704ULL, 0xE478A26934458F25ULL, 
            0x23731F064697F2B3ULL, 0xC839699A2BB83FC7ULL, 0xD1A175D8FEC57734ULL, 0x8760100EB0FBDE6CULL, 
            0x6967E3BD4FF443C3ULL, 0xCC56F30F67295C71ULL, 0xED51477AD21EADA8ULL, 0xAD80CC658EB7010EULL, 
            0xAE5252D474E68045ULL, 0x017C2D316DA2F3C4ULL, 0x5B59E2293C1BDA46ULL, 0x94E628A753A3C7C4ULL, 
            0x95423DDA2E39653AULL, 0x5E27DEFEEEE0A788ULL, 0x01EFE8B21890B511ULL, 0xEF468DFFCBCB726DULL
        },
        {
            0x49A868E6BBE7FB30ULL, 0x6145C5BE99B9D6BFULL, 0x75C625EB18F0ECD2ULL, 0x585134F7A2777139ULL, 
            0x42E7A4470FE01DD9ULL, 0xA0B57BF80A024884ULL, 0xDCCBF5904822F2C8ULL, 0x242C79C3E3DE4D65ULL, 
            0xFEF26918863CCBF1ULL, 0xBD2F9676BB871918ULL, 0xF202017010B9E0A9ULL, 0x966BAEA713A59B6BULL, 
            0x97764BCEE6DF9557ULL, 0xC9A326AC3064F90EULL, 0x7A1F04495BB67ECDULL, 0x659DE70B65C5BD40ULL, 
            0x535D0752BCA47851ULL, 0x0CB406006F5A9EA1ULL, 0x9ECAF94741DE0210ULL, 0xF9FD695AB24101D5ULL, 
            0x2D209A6696F658DBULL, 0x2AC96BA8028CF900ULL, 0x5495B4DC25304BE5ULL, 0x8C309B00C8303752ULL, 
            0x8DB23BF4806254DDULL, 0xAD27CCFD4D14F2DBULL, 0xCC5056E8A5525DF9ULL, 0xDA78F6D95B8B26C1ULL, 
            0xC47384D0D7182AF1ULL, 0x002FD3478152DE5AULL, 0xD9126DB95DC88908ULL, 0x4C30B413F8E220AAULL
        },
        {
            0x84B2EB305DB7C216ULL, 0xEC7634BE12C6A091ULL, 0x5866BE801409ABD9ULL, 0x93498C9DAE3C4487ULL, 
            0x408460D0C954ADB2ULL, 0x61D14AE458EBCC09ULL, 0xBB7DA240913D0023ULL, 0x73F95B35AAF57B91ULL, 
            0x1EA015088585F669ULL, 0xB17290FE18D9173BULL, 0x34D41A1244AB4897ULL, 0xAF7E204486DE6C2EULL, 
            0x3031CBDC4C3CB6D9ULL, 0x38865FBBE929F1C9ULL, 0xE115AE1C1B236108ULL, 0x367E3ECA21445896ULL, 
            0xB9A70EB440B6465CULL, 0xF43B8643E24CB4ECULL, 0x5F040B687B6538EEULL, 0x279713F9CB13D75EULL, 
            0xF196410EA6C88F89ULL, 0x99A364CC58F05B14ULL, 0xCEC1D4BE068A5175ULL, 0xF88F3EBF8719110FULL, 
            0xBC77535636CA5108ULL, 0xEA523017D1DF443BULL, 0x3605B906D674E1E7ULL, 0x060C3D8A6F2371C9ULL, 
            0x4DD6FC727B9E96C0ULL, 0xF429E1B632CD1108ULL, 0x2F5595878151D89AULL, 0x0B23D2EACA98D584ULL
        },
        {
            0xA7A5CFE346814094ULL, 0xAFAF4DA0430DAA84ULL, 0x6EB79F439B34CDA9ULL, 0x7095881840FBFE04ULL, 
            0xFA8C17CF1363083DULL, 0x49337A66B7366254ULL, 0x567C44B0868AC4EDULL, 0xFEE552D35BFF6440ULL, 
            0xE0E6572AAB5213F6ULL, 0xBBC6075DC691BD76ULL, 0x2AAD2986A224C436ULL, 0x4A27A06593644044ULL, 
            0x0A792DF013C6D854ULL, 0xD6C441C44BE02179ULL, 0xD7834D5A5AFCA5CFULL, 0x081F92D11E7BA0B4ULL, 
            0x00D976528967A177ULL, 0x0F44F546B1E45B58ULL, 0xD9F470E46916EA26ULL, 0xBD72D6B50572BCE0ULL, 
            0x15B3FDA31A0D6AEFULL, 0x07802984CBC470ACULL, 0x69AE070C037678C7ULL, 0xE777988039EDBBF3ULL, 
            0xD27E380AA10E189AULL, 0x08043A40A9C6EB62ULL, 0xCFE25C3256916914ULL, 0x17707D16DD9EAD50ULL, 
            0xD5571D9B6C11C80EULL, 0x30497820D579A33FULL, 0x77516E2700C6BE2DULL, 0x7BC2F6F1C661E77AULL
        }
    },
    {
        {
            0xB56E6920B6567C83ULL, 0x90372E545BC8C44AULL, 0x560AC2680D3990F1ULL, 0xEC15D4B3D1278074ULL, 
            0x47781F21877FBB11ULL, 0xC0CBFD5E960F6F9DULL, 0x8984857EA37F3F94ULL, 0x8A9ECFD8C3856703ULL, 
            0x381ECDF0803731D9ULL, 0xF02F9E4D731F8F75ULL, 0x35AD5980D6129509ULL, 0x9DD30F5530362164ULL, 
            0x61EAEE771ED94082ULL, 0x6D76AE23D3EB73C1ULL, 0x08AAB59EABF18316ULL, 0xC77B5B018C54CEC3ULL, 
            0xC683D3BF6D9A28A2ULL, 0xAEE8543E5CCAC7FBULL, 0x454E66989F053130ULL, 0x9DD31CF7E9081A3AULL, 
            0xDCD306726996388EULL, 0x7B23A92FE8E225CDULL, 0x87C011FEB1A542CAULL, 0x1A9142927B00A8CFULL, 
            0x5611EAEF9B84AED1ULL, 0x846371DC0B5DAD01ULL, 0xAA0142FD7D63BF1FULL, 0x5A1A48FA54021719ULL, 
            0xFC7CB7ACE934B639ULL, 0x956307B77B5F5EACULL, 0xB148A5B928713A07ULL, 0xC3ED5FF9F8B75AFFULL
        },
        {
            0x6B6A7F8FE46B6210ULL, 0x58DDB1189FEFAD8BULL, 0xAFFEF09C0FEE71B8ULL, 0x814990A1F9F911D8ULL, 
            0xCC815A30D276056BULL, 0x0A0BD183A0284379ULL, 0x35B654F6368F9A80ULL, 0xF67F6E3F1634C8CEULL, 
            0x8769B72042EBFE58ULL, 0x36D2F5CEBBDA484AULL, 0x5958ED003791A368ULL, 0xE28EC73CEB67E7FCULL, 
            0x863D3A2801652C98ULL, 0x88BC1BD2B4B06A18ULL, 0x498FB8665F27377EULL, 0xA3381D97EF1B4C81ULL, 
            0x1AA9799B7D3F9156ULL, 0xE3517D1034B5963EULL, 0x5BCC674300786893ULL, 0x772CB173A44C411BULL, 
            0x0E8B5682CF84DA5BULL, 0xB711A5E340C78C53ULL, 0x2A59D51D88391702ULL, 0xF18F470593675F5FULL, 
            0x0DE23AD1304D7443ULL, 0x9FBF99EBB01EEB8AULL, 0x2F857F52A5C3CDD9ULL, 0x976B279153C296D2ULL, 
            0x79E323C24BE06D9DULL, 0xD72D2C4AEC57AD43ULL, 0xA43FC601E5613D13ULL, 0x37BA3674965ADBDBULL
        },
        {
            0x9C7B9A8DFA5CB9A8ULL, 0xBD95C9FCC439BA24ULL, 0xC0416CE938B0DA4EULL, 0xB9A83F54AE7D9BE2ULL, 
            0x95F9D9FADC8D0DD9ULL, 0x2399A21842320837ULL, 0x06D9FA8F54606C8EULL, 0xDEBC33828C4236E4ULL, 
            0x5508ACEDE1B3D807ULL, 0x843B9A8C7662348BULL, 0x54FA416F3FCE0F61ULL, 0x4362127F1B079E85ULL, 
            0xAF4F2DD5B8DDCBA8ULL, 0x1DC97F3F21293F45ULL, 0xD78F3B5C1E606D1AULL, 0xC437A3812C3BA42AULL, 
            0x8576445007F1B52EULL, 0x7F3EF4ACB69E349BULL, 0xF282B853DC1A052CULL, 0x688E4E7BB6144B8BULL, 
            0xD0216794FAB7049EULL, 0x59B1158B9903A5D8ULL, 0xC7AE6CF0ED4D6251ULL, 0x18AE6F42FB5DC41EULL, 
            0xA183C4FEAECB79B3ULL, 0x69334D5FA9D4306DULL, 0xFDE8D9C5DF4143B0ULL, 0xC4E53F30FA6AD3F5ULL, 
            0x53595A0BCD0417DEULL, 0x22E8CEFDFA98A966ULL, 0x7ECA7C6A7F4F9AE7ULL, 0xA49994FE6B9DB82BULL
        },
        {
            0x7BDF441272FB1DD6ULL, 0x3F90CA6E0D874FADULL, 0x1980E87AEED359D8ULL, 0x74B4C1750F3A12E4ULL, 
            0xD05928C315A8ED07ULL, 0x5649CB054ED3C1B0ULL, 0x87FBD098A170870EULL, 0x2D73F1936E3575F5ULL, 
            0xA01179A4C6919E7AULL, 0x42381D7CDA748491ULL, 0x5E3E8FF8BD3FA083ULL, 0x0E527BAD33637364ULL, 
            0x0BAD56140B31D597ULL, 0xBEADC277D9931584ULL, 0x1C02DCC5D7F1F455ULL, 0x552E807CB0E3A5A4ULL, 
            0xB1343E0148E7B959ULL, 0xDC033A80A6FF2073ULL, 0x6A56DD1A0CB9B5D4ULL, 0x4C7BECE4895D6A10ULL, 
            0x9F169E6840BAC04DULL, 0x57537A539C1B847EULL, 0xA7C02C9FD0E768A7ULL, 0x0EB6FD59FC0E5EE1ULL, 
            0x7C5F4548E1AEE48DULL, 0xCA4053FF6E3C67A8ULL, 0xA4F886D43E6D3858ULL, 0x6D10DCEAF16ADE3EULL, 
            0xBC8BF5CD7A0D2AE9ULL, 0x0312E7284E6DEC34ULL, 0x1BDC1F999C2A3DD8ULL, 0xC38BE4D94D2D4D5BULL
        },
        {
            0xF51A9361C3D3118CULL, 0x6B5EF9AC937CDE39ULL, 0x5DB19EFE564B0EC8ULL, 0xD7DB0D19296BC098ULL, 
            0x5AA8D0C63FAC286FULL, 0x10AF209C430DEA69ULL, 0x0D1DC7D238F31711ULL, 0xE948FE104E35C46DULL, 
            0x48CC8DFB9BCD9E50ULL, 0xF2415E97A4CD39F9ULL, 0xEB21B0F516FAD151ULL, 0xD631CB4718EA4DAFULL, 
            0x6336FDE09AD16059ULL, 0x25C1C9EE0C1B2525ULL, 0x74E2480171452CC7ULL, 0xF9CF5A37D17586EDULL, 
            0x7E7E4F72296DED55ULL, 0x4B5D4930671B7373ULL, 0x112FEB89E702552EULL, 0xCF0BDA52833A23B9ULL, 
            0x50DE795266778691ULL, 0xE2FE42F4698DD1D7ULL, 0xDDFC5A097035A811ULL, 0x1561B78CC7B66539ULL, 
            0xC9BF08940F0C95BDULL, 0x0938E029BF94A9BCULL, 0xED3B13E6DE7D404DULL, 0x2BAE5A90D0A11483ULL, 
            0x4510E83AD9A689A5ULL, 0xEAB4B9503796FB65ULL, 0x9FCE5A1453D7EE32ULL, 0xA1E7BB433BBA277BULL
        },
        {
            0x80E2CB027343A228ULL, 0x86A92B8E8121C20DULL, 0xA0DE4BFAB32032E9ULL, 0x12FAD02EDC99D070ULL, 
            0xF1768B42AC218A5DULL, 0xD5AC3D121B52F3E5ULL, 0x3C6B7A65568531FDULL, 0x2D987E5597240DE4ULL, 
            0x37ECDAD44156D90CULL, 0xA8D7998B42A15A4CULL, 0xC70F1EECFC5EA2C0ULL, 0xA1442191085F7802ULL, 
            0xC414A8E77A14B1C3ULL, 0xC7082A04DF59AABAULL, 0x4C8ED2DD49D62FBAULL, 0x42B2C558F8EC3B87ULL, 
            0x03C7866938DA96A1ULL, 0x2D64C27A408765CAULL, 0x289D1DB1EFCFD622ULL, 0x9ED7F24044C05DF2ULL, 
            0x5E4396106FAEBC76ULL, 0xB6B90DDF599E61BEULL, 0x69C99D79029117CDULL, 0x6029FCC321A4ACF8ULL, 
            0x099FE597EDD04D24ULL, 0xBE83551EF7FFF6C8ULL, 0xB2FA0854496EC247ULL, 0x135367C45109F85CULL, 
            0x6B2074595D08E9DEULL, 0x40BEA162436DABB4ULL, 0x8DFCFF4392B1C11EULL, 0x2A531B96FE8DAD67ULL
        }
    },
    {
        {
            0xFF8B0DC1B44A0A21ULL, 0xBE0F15977032D436ULL, 0xC83F6A3CEA3B017AULL, 0x8185F71C7570A88AULL, 
            0x7EDF0FF8B2749323ULL, 0xA3DA6B1788303DF4ULL, 0xBFB6584B0A0BD693ULL, 0x966C81F55D1DFE09ULL, 
            0xD5D473EEE0A6AC54ULL, 0xADFE9D416475A635ULL, 0x4F1097E2FEDC3C97ULL, 0xC80B3B9221E6B0AEULL, 
            0xBCD418F68714D17BULL, 0x629F74CF013A317BULL, 0x3764EB465E029C16ULL, 0x7584877586A66338ULL, 
            0x40C2439401EF5016ULL, 0xF0CE905DEC21AA2FULL, 0x5606E0273D2226DDULL, 0x1F84CFD222B52012ULL, 
            0x40631429318D8CD7ULL, 0x8E22EF53FB3CE768ULL, 0xBA32AB6B2652A96AULL, 0xA13EEE49094F6D46ULL, 
            0xFA07BBDD7C67394BULL, 0x1B58A501F251D115ULL, 0x545E908B395C5298ULL, 0x719DD5F9A1AA4039ULL, 
            0xB71ECC2F9E4A74C1ULL, 0x14EDB1E5E16EE0BCULL, 0x6AF092C7AC160F88ULL, 0x8DC633B3561E4C92ULL
        },
        {
            0x45EDEB6AACA9CBBEULL, 0x3DC35F4C733D94EEULL, 0x1CFF95FEBE562260ULL, 0x8C626E6ACBE1DE17ULL, 
            0xB52224FA4F58BAD6ULL, 0x7B5017AC33FC78DEULL, 0x75582211115B9EDBULL, 0x4CABB3F822E8905FULL, 
            0x96EE62E621D63DB6ULL, 0x5552E2D2AC2CE04FULL, 0x563D3840751757F8ULL, 0xD6AE79310ADCC93FULL, 
            0x030781B9843C7E3FULL, 0x23C3C03641D37348ULL, 0x047DB26AFEE6D35BULL, 0x59897A16CC19CD02ULL, 
            0x8DBC92FFA0C94E5FULL, 0x0B3D9FC2DB6D8AFFULL, 0x497EE75293316F36ULL, 0x8F53A4C284C58AD6ULL, 
            0xA93E83A7EE5CDE16ULL, 0x3A5B32D884629F97ULL, 0x550D173872682F64ULL, 0xA864AD73431E19C0ULL, 
            0x935389ED6072926DULL, 0xC7692E046EC641BEULL, 0x63E86525850A7B66ULL, 0x051F053176F7FE8BULL, 
            0xB19D08680F9D64C8ULL, 0x3700E38BF271E45DULL, 0x2C4B69C5C63CD2CBULL, 0xD7575100587B5576ULL
        },
        {
            0x1E171E188401542BULL, 0x3D66558D47EF41E0ULL, 0x0C424946A96C271AULL, 0xEE4652F3C0C1B81EULL, 
            0x832C5EEC9B21351BULL, 0x1B40F06E9651AEBFULL, 0x0B8984E4A1573A84ULL, 0x37EBC78BD1A791C6ULL, 
            0xEB54D93B1A3263CCULL, 0xA20625A0587131A8ULL, 0xBCA5E68C2D83ABB1ULL, 0x2028427CF5417606ULL, 
            0xA7F1378E8E5C9C5EULL, 0x9C8BC22D36848E43ULL, 0x4280796C295A4D20ULL, 0x0669593B3119D190ULL, 
            0xF8E96EBD833C0CF7ULL, 0x51B7616BD5B74F60ULL, 0x0A0DC3C9D7DFB15BULL, 0xD268172C0A0FCDC2ULL, 
            0xC5A795921A095519ULL, 0xF97F7678C06EC981ULL, 0x2125E8EEA5D32AEBULL, 0xB5F9ACE4DD9B306AULL, 
            0x2A053EF4DC5354CCULL, 0xDF80F277B0257FC3ULL, 0xC5A57DB5E0B9EB4CULL, 0xBDCB1102C7B7D2FBULL, 
            0xD6A0C34506D18CF4ULL, 0x42A90BCF9FC1661EULL, 0x0C05B1A7BA8E56C1ULL, 0x67CE34D3A671B265ULL
        },
        {
            0xB996E0CDA7EC8C1FULL, 0xF4913E4993D1E096ULL, 0xEE5B15297AA57998ULL, 0x7D725C95E5920587ULL, 
            0x922DE0830F2AA25EULL, 0xDC0E23622990AEC9ULL, 0x47F7BDB9E2BA9217ULL, 0xB95711DD2151C035ULL, 
            0x56F61808CA5E85E3ULL, 0xA599E438F9963628ULL, 0xCD46AD1A20568FF7ULL, 0x2512F0336C86D3F2ULL, 
            0xD29D62673E7F92A6ULL, 0x73AFD701C1F9E7D8ULL, 0x2347D5514B695974ULL, 0x736CC0BD2824F6BAULL, 
            0x37A4AD3C2BE93E4BULL, 0x3368BBC54320EF28ULL, 0x63F30D00C48854B9ULL, 0x34C62DEEECC24FE7ULL, 
            0x0B714335596BB49FULL, 0x48DA3FA6C0B5D242ULL, 0x28D9CC506F99250EULL, 0x374AA6194E3512A9ULL, 
            0xBFC142F2CE224160ULL, 0x1AA246F29F658A22ULL, 0xEBF9F62BBE4AB47DULL, 0x1B3C5EB6F79E1D55ULL, 
            0x92E218A7D9254488ULL, 0xD3772681E3D44C62ULL, 0x2E985DA9AADC6FC2ULL, 0xE9725ABB7C6790C0ULL
        },
        {
            0xCF656E43941D28C5ULL, 0xC172C378819C0969ULL, 0x4ED23E1EDE4B6C95ULL, 0xB282A91040B9149CULL, 
            0x1236B06D8EAB2BFCULL, 0xB5E76DE33463E155ULL, 0xAA5C4E3140765C3BULL, 0xC7BFDFB48E898A25ULL, 
            0xD9D46D4449C6073DULL, 0x6A71A5A5C26F69E1ULL, 0x56AB642AAAD9E273ULL, 0x6ED3876D93F939B6ULL, 
            0xC5F07620DAAB96A6ULL, 0x49A0F35FD2986D87ULL, 0xD1CD181B0306DAF0ULL, 0x65F9021D9572C0FEULL, 
            0xC1E2914F9F5A6B07ULL, 0xAD2CB239D41FE12CULL, 0xF42A9265AEB322A6ULL, 0x71C64DC4267FD6A0ULL, 
            0x7BBC540232BF382AULL, 0xFF1B6B2B684F93A6ULL, 0x7BA2A94F1461805BULL, 0x0C1CBB97B43E9071ULL, 
            0xE3919E96B7F3BE33ULL, 0xD23861DDB4B23DA5ULL, 0x7CA2F235115BB397ULL, 0xC5EDCF6ED53D19F0ULL, 
            0xF98CE9313021296DULL, 0xE8AA324FE80DF424ULL, 0xDCB882A14E2B2645ULL, 0xEA662D3F5EC07CCBULL
        },
        {
            0xCBBCD91FA1C2A96EULL, 0xEC2AC9FB8E5DB569ULL, 0x5D6738BD11D98120ULL, 0x93C6EE2EB6697FEBULL, 
            0x809E7614484D3C5AULL, 0x82C3B5D9656874ADULL, 0x0C1EFE7420F2A3FEULL, 0xD1E94DEFDC45A458ULL, 
            0x61E78447BD3673FFULL, 0x7BD19B0394241917ULL, 0xCE07CAEDAB91C762ULL, 0x692B9B720D329756ULL, 
            0x71FAA8DD9FE08C1BULL, 0xBFDF458C1CA9C856ULL, 0x305A494346934D0DULL, 0xCA0339276B58DD5FULL, 
            0x7F5D139DAC1B4D5BULL, 0x2BE04ED09E1DA83BULL, 0x92442A6B7B8B6CEBULL, 0x3E8875E9D91977C0ULL, 
            0x76274F85CBF345A7ULL, 0x7273655C28ABA2B0ULL, 0xA9D5D84DDAE8A1E3ULL, 0xF4C4A3BA9E7F9F20ULL, 
            0xE68FAF392A267866ULL, 0xF5C4A0D1EA46F285ULL, 0xA94F8AAF95183DD6ULL, 0x23497E64EE6A7445ULL, 
            0x95D546E38D676A8AULL, 0x4C5273BAD0969DA0ULL, 0x8D656DA2CB9C2C73ULL, 0xC9A495B382CB1404ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseDConstants = {
    0x5F13D6872F4D0649ULL,
    0x37ED619172390020ULL,
    0x1844BA40E2340184ULL,
    0x5F13D6872F4D0649ULL,
    0x37ED619172390020ULL,
    0x1844BA40E2340184ULL,
    0x6DEE1135F4F3F2C4ULL,
    0x4A91B5C00077AE46ULL,
    0x91,
    0x8F,
    0x87,
    0x62,
    0x0E,
    0x13,
    0x80,
    0xD5
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseESalts = {
    {
        {
            0x518BF8C71BEC392EULL, 0x705CA8706827DD34ULL, 0x85020134B411FDD1ULL, 0x9A378783493972CCULL, 
            0x4FD29E9B3A734635ULL, 0x6D4B342114DBB03FULL, 0xE880CA324FECBF3CULL, 0xDA5BAD2ADE63CBC4ULL, 
            0xB2CFE63BFB8F80FEULL, 0x0E16F8512726FF9BULL, 0x664345222AA35740ULL, 0x140EB0B72A22AEAAULL, 
            0x91BCBBF40D947282ULL, 0x9E7787B6347F0363ULL, 0xAE6357AAEC06B002ULL, 0x5EC27810FE9D0A35ULL, 
            0x98E3E47A445B21EEULL, 0xEA654D85FE62AA71ULL, 0xDF84E09E7F663073ULL, 0x6D44EADB52DD8D00ULL, 
            0xE2FE6B770D1E2C1AULL, 0x70A64E7D500A709DULL, 0x7E61A110D270A7B3ULL, 0x17B3139891905AEFULL, 
            0xB6CDC72A1D9570C6ULL, 0x2A2B3A67D5BCE7C1ULL, 0xA72AB707219C398EULL, 0x1CBD5D8BA2DE6E5EULL, 
            0x7F9B34E926BAD008ULL, 0xC5848ACE37D985BEULL, 0xBDA19FE972220AE9ULL, 0xB047F122AE34F638ULL
        },
        {
            0x264217488F844F0AULL, 0x2CEE0F1C6595C9B4ULL, 0xA06F9BA3923A126DULL, 0xE6CE51166A07AB2FULL, 
            0x15BF6F2901880273ULL, 0x9D16E20E7F276A28ULL, 0x021BB3A7FB0900E0ULL, 0x0A5A6BF21D11C2C5ULL, 
            0xB113349C9C05E76DULL, 0xA2C42ED533C9F71FULL, 0x435C1CED229D84E7ULL, 0x6AE1065DC46AFA60ULL, 
            0xC7732544CEE55956ULL, 0x0F5C8748C2F0C01DULL, 0xB449268B511E94FDULL, 0x8E8F949F5B102292ULL, 
            0xE1A7B58257E61A7FULL, 0x6FADA78A16D2B8E5ULL, 0x8EF44BE0AC44113FULL, 0x1C358FD9D2E168B3ULL, 
            0x90D05D41C0F7B293ULL, 0xE54D87014DDA0BE5ULL, 0xCF5343F98D98BFB5ULL, 0x9A5E6F12DF50D0D8ULL, 
            0x4D9886FDBD695508ULL, 0x3BEB417A1A8B19D6ULL, 0xE604F8A77E6B5227ULL, 0x8F1347438C1B9D04ULL, 
            0x799976B99AF67A28ULL, 0xE327A8AB65C15386ULL, 0x83666180700F5039ULL, 0x410DA17C4570FC62ULL
        },
        {
            0xC3C5FD21B1D0263FULL, 0xF2E44E69665FC294ULL, 0x0373673F5D5AB097ULL, 0xC22BA6E06F80CC11ULL, 
            0x8B94D9E296A555C0ULL, 0x96EFBC54BC4F75FAULL, 0xBF96D9FA411B076DULL, 0x80CD186D270344B9ULL, 
            0xBA030607B020762DULL, 0x7CBB2AEE6C7A60A6ULL, 0x176918A77497E189ULL, 0xC6CB8A5DA2B6983BULL, 
            0xE0A0CA493C226363ULL, 0x8261536DDA51B5AEULL, 0xDA3AFA6E53AC7C55ULL, 0xD9046A62C36383AEULL, 
            0x7DB632ADE18D1351ULL, 0x9DE972F99C053B0CULL, 0x458AD54314F3A3D5ULL, 0xFED787008D82F707ULL, 
            0x617127D2222FA2D3ULL, 0xB390034FA3284E0BULL, 0x5B62AA2EC4F39554ULL, 0x19453D8D008B7BF8ULL, 
            0x6EC269CD25FA4D26ULL, 0xDBC60B56452F6EB0ULL, 0xED446F503AAD02A4ULL, 0x642106F4B23D451CULL, 
            0xA4EA5AEBD9619510ULL, 0x662B324DDF3C3B4FULL, 0xFC5C28C2A2123CFAULL, 0x7B589AD8F9317972ULL
        },
        {
            0x5DD53A73D8873023ULL, 0x49C6D1F927B4DE21ULL, 0x11ADFC59FDC1F776ULL, 0x7E2E8724F69E8F0FULL, 
            0x44A39DEB653B005DULL, 0x69B09F6A865FC103ULL, 0x1C29E19A812DF8A5ULL, 0x57BF0C0BA838F4E3ULL, 
            0x07EB7B54B2550DBCULL, 0xC9E225FB2303F95DULL, 0x0C114720FB4C6D42ULL, 0x50F6D56041C63757ULL, 
            0xE37D6F9DA86C513CULL, 0x885C70B6F65E3EDCULL, 0x58B58C889C385918ULL, 0xE8111D7F87856A48ULL, 
            0x052C794443938D62ULL, 0x919A351D3230059CULL, 0x115DC9B737808B8FULL, 0xA8BE7A28B8E2DB3EULL, 
            0x84587F9B0CEC6263ULL, 0x21EB65109DB839E7ULL, 0x6C2C6D39481649B8ULL, 0x95CCE129073D7E5FULL, 
            0x3591EFF6CE8D9C90ULL, 0x83D3820609365A22ULL, 0x995EF081E2419115ULL, 0x03D7F594426F45A8ULL, 
            0x01AC1941CC5932F5ULL, 0x20C01AFBEC3F796DULL, 0x709F63A73C11EC83ULL, 0x7810E5BE2519A14CULL
        },
        {
            0x917C2354BC56416BULL, 0xBFAC09610E22E12FULL, 0xE088C6E36A1E54CFULL, 0x38C77ECCC4FBDF04ULL, 
            0x0046CB02A7E93C7BULL, 0x5AE0240DE66A3B38ULL, 0xAB155971014C7DA1ULL, 0x880CABCF56CB53D1ULL, 
            0xA9F6F4E56E923887ULL, 0xF4E9579C3C2A3601ULL, 0xC8DFC8642EB2AD10ULL, 0x07A181AF2EEA1D8FULL, 
            0x9E9B8E22DFEA2022ULL, 0x107438F741F221D0ULL, 0x71D56AA1221A8BDDULL, 0xABEFFA0B6D67AF0EULL, 
            0x09EEC60E386B4414ULL, 0x948478486D02351AULL, 0x73347A91C792080FULL, 0x963382656A4B60E8ULL, 
            0x2E99611FC7CBD294ULL, 0x289E28F3B5AE894FULL, 0x2D759B9DA4BC8754ULL, 0x37C669CAAFBF4794ULL, 
            0x5D23C78225A69F00ULL, 0x19888BF0D6C0C65CULL, 0xF5D77DF94A55D362ULL, 0x9CDA949C75C67C34ULL, 
            0x84329BEEF6F69C48ULL, 0xC44B5808D0DA39CEULL, 0xE0685598DDD62AEFULL, 0x3729FB151F70EB55ULL
        },
        {
            0xC6B0613D2536086AULL, 0x1FEFD6C8771E95C2ULL, 0x11DF84B685A8B352ULL, 0xE883F272C3B68C85ULL, 
            0xE217207E27853E88ULL, 0x123CC8DBE592A92DULL, 0xA56B56C8C199609AULL, 0xF7FB778BCD0007DBULL, 
            0x1FCAAFAA9FDE25C4ULL, 0xE2860FB7EFFF81B8ULL, 0x04B08551FBF206A0ULL, 0x25CF6243B3CE15BEULL, 
            0xDAD24969490DA4B6ULL, 0x1E9BB025735491FFULL, 0xEA42F222A35B903EULL, 0xB11E9373958FFA9CULL, 
            0x68BFC928CA646853ULL, 0x23281AFC294FEBDDULL, 0xCE6D7CD1145764BAULL, 0xF88965C37A34B272ULL, 
            0xEEB8BA95F9D4CE47ULL, 0x4DE3E0C69EB062D0ULL, 0xEAB28E43A959A0C9ULL, 0xCDED322C3C6FEA37ULL, 
            0xE171997C0F6B7A38ULL, 0xC4D820055643E147ULL, 0x4BCAE43272825B7BULL, 0x8885B00D5C4F08E4ULL, 
            0x44DFE5E573B4C25CULL, 0x3B3BD501F27D9D0FULL, 0xAE742891592D37FBULL, 0xDB31DB7D0DA4396CULL
        }
    },
    {
        {
            0x6520B400F455E51CULL, 0xE20175D55631D18CULL, 0x85DA81097DEA5B11ULL, 0xA791F69228DE5E1EULL, 
            0x0A0F27580FE4E9E6ULL, 0x58854D03E3C2079DULL, 0x5C877C128480972BULL, 0x751F4A0916A4EBC3ULL, 
            0x3EF4C51E92E55848ULL, 0x7D1B6FD1DDF7307AULL, 0x8B2BB124B6163AC2ULL, 0x1436EAADB219ED9EULL, 
            0x3DE1535CDD456BA0ULL, 0x3E3720D608235221ULL, 0x68CDB467A52673BBULL, 0xC7C3DB8D44016DEAULL, 
            0x157E3584A4ADEB12ULL, 0x907B96444D8FD333ULL, 0x79B017BE098AA917ULL, 0x1B7F8972AA2624FDULL, 
            0x82D573C6F866C5F9ULL, 0x856AEA18415444E8ULL, 0x234493D76BB3276EULL, 0x06062CEBEF4A60BEULL, 
            0xE62C8D5693066228ULL, 0x0509120FB08C395BULL, 0xCCD2111BC17C91FAULL, 0xF9005A0B29EFECBBULL, 
            0xE1B6DA800181CEF4ULL, 0xF7CBD965C6A6AE46ULL, 0x2399EB3E25F48F2DULL, 0x82ED6654BD7C5CB1ULL
        },
        {
            0x37B4E4848E39E457ULL, 0xBDD13323CC23A760ULL, 0x534361C7E94585EAULL, 0xEAA6415442925556ULL, 
            0x7A329F853F3119CCULL, 0x6667A082DFE37796ULL, 0xB8E22275F1B06D07ULL, 0x6BA097C1C546DF88ULL, 
            0x566583F668A5C81CULL, 0x55AA8865290F1978ULL, 0xFE794A966D6089DFULL, 0x42525915556A5D75ULL, 
            0xCB1DF971744FBAE0ULL, 0x87FA85113CAC11FAULL, 0xB0752422F9813DA8ULL, 0xAF42F0E1E1598B2AULL, 
            0xF083FAB007073AFFULL, 0xC2E9D4D7259AF8DEULL, 0xACE7E266DBB56915ULL, 0x283BA0637304E874ULL, 
            0xADCDD836CE131CFDULL, 0xC23DDF9FE0342B5BULL, 0x1EB09CD4D2A13C72ULL, 0x2EAA3C3C78E7BEBDULL, 
            0xFF0C07C998670143ULL, 0x32B8B0D6ACAD092CULL, 0x21815D9B8E0B9A37ULL, 0x2CFD1C037BE53379ULL, 
            0xAEDDF9F0BB8C5C13ULL, 0x66561023F4905575ULL, 0xC5B7495E4F211DE4ULL, 0xAA58620CA4C5B762ULL
        },
        {
            0xA5C6981ED5076BC9ULL, 0x50A2A494F5DF1132ULL, 0x3549B66CB8DAD7DAULL, 0x4AC4A13A0A1A3B64ULL, 
            0xFCB5F12129296A50ULL, 0x905C772EF2D019DDULL, 0x4EC0D9905497CAA9ULL, 0x4717C77C415766EBULL, 
            0x82C69D38AEF415E9ULL, 0xFC059A166CAC94F4ULL, 0x8923BC6500F4EEDAULL, 0xADD1FFE01510E5E6ULL, 
            0xF2975D2FB4E31360ULL, 0x747A3822151A91F4ULL, 0xD41590E82742F334ULL, 0x2828E6796E345CF7ULL, 
            0x92089AE7CCDC396DULL, 0x2DDD20016AF4BB0CULL, 0xC5963BC7DE70F731ULL, 0x2FD32970F08E46B7ULL, 
            0xE49DAF57169FDE9EULL, 0x750B527B4015FBCFULL, 0x9475D4BC47E7F5A1ULL, 0x1FE5C01C5EAAC74CULL, 
            0x5A92C68FE0A0145DULL, 0x0E5D2A0D1E4607F1ULL, 0x6D51CE7999F65623ULL, 0xE28835929D31EE9EULL, 
            0xBA20112B76CFC2D2ULL, 0x46A634DDFC8299F7ULL, 0x714F50F03311DE62ULL, 0xB951598F894DEC43ULL
        },
        {
            0x85FD5BD455EBDAD5ULL, 0xFD2C3E2E59424DB4ULL, 0xE20760ED8375CC89ULL, 0x5B32EA3BDC5B1B61ULL, 
            0xB290E5D72B476A4BULL, 0x65AB9BA6867C3B13ULL, 0xE6C6F58F58CDB7E0ULL, 0x70FDBCD279B728B8ULL, 
            0xEDACDF6AE9E57080ULL, 0x4DB9AC7C937269AFULL, 0x182B10DCC8643F3BULL, 0xDB8AA0FEB8EFE869ULL, 
            0x369500AA7AFC1577ULL, 0x955E399E9742655FULL, 0x0D62D0A9504E9A21ULL, 0x196DBB88FC960394ULL, 
            0x21A76E6E7946353FULL, 0x16B9B7CB1293600CULL, 0x5B935D8D105D4814ULL, 0xF69CD09A2999BB30ULL, 
            0xF0EFE0E834C0C176ULL, 0x3CF8C31D1CC6D6D1ULL, 0xE13A15C9B2811653ULL, 0x811E11C6A3892F7DULL, 
            0x784BFBD31016A992ULL, 0xC0E0A5D8E8FB8F32ULL, 0xA8F36663E31D7997ULL, 0xDE2CB1FFBAED92E7ULL, 
            0xBF935288B99A7597ULL, 0x2D96375A249CF140ULL, 0x55C6DF772AF7EE9DULL, 0x80F56443EABFA826ULL
        },
        {
            0x123F1E812A4A21E6ULL, 0x7826AB3BD5CA5457ULL, 0xEE9CE6604B609E74ULL, 0x8E5027266CA0FD04ULL, 
            0x2EDAC9CAE6DB2922ULL, 0x975589B3BDE45926ULL, 0xBA2B304EBB9C5B30ULL, 0xB492C716384F7A0EULL, 
            0x02D2CA53CF74972FULL, 0x5930D67F34C23799ULL, 0x353D1455F241FF03ULL, 0x6761F9CF61AD3E58ULL, 
            0xD6E1802137292D06ULL, 0xC2BAEAA942B43404ULL, 0x832772E217352193ULL, 0x160EB049A07A1209ULL, 
            0x660DDF2163741895ULL, 0x5BBC4BA34904833EULL, 0x80D850A1A3EFAB67ULL, 0x42409549ED0D0E9CULL, 
            0x2E1B040E04D73E09ULL, 0xBE8D221AB37279F3ULL, 0x58E17A979FEB0244ULL, 0x0A63644CBEF40136ULL, 
            0xC1152CDFC6FE44A4ULL, 0xBEFBA3A15BAB3A02ULL, 0xD05DE53577073A4BULL, 0xF3827729F98BB6C9ULL, 
            0xD5293F935E6D21ACULL, 0x65D98A1278380422ULL, 0x9693F3B4A4C7164AULL, 0x1177465A926B4855ULL
        },
        {
            0x6B884F7AEF995880ULL, 0x90AC92D66816C933ULL, 0xAD4D55FB6C80D4B4ULL, 0x1F1EFB7AC08A80EBULL, 
            0xFDAFDF45F9FD7D18ULL, 0x40E536CF6157467DULL, 0x8EB0060F42F2B2F5ULL, 0xE4AB521898AEA505ULL, 
            0x07272CB4A353D3E5ULL, 0xBC05CA4598FBF1EBULL, 0x57FAFB17CEC79DE2ULL, 0x57B9D5CB985E7387ULL, 
            0x7AF8CEE1A1B7F9CBULL, 0x00184542DBF78E65ULL, 0x934A3154954220E6ULL, 0x3EAD04BD728A7CD9ULL, 
            0xA8FE0B314D594D6FULL, 0x9D5B584B3F50854CULL, 0x8BB8F76A68B30388ULL, 0x2B3306EF5CE3DF5DULL, 
            0xF53C70CE2192B0E1ULL, 0x2CD812348F89C5B1ULL, 0xAA4ADC722406CBF3ULL, 0x54F850224A6BA805ULL, 
            0x0C98E9CB4D9EC09DULL, 0xFD7E968193CA1F7DULL, 0x7AC426C6D01EBF75ULL, 0xDDA047FE7BBE0227ULL, 
            0x6BE823BA3D13BAD8ULL, 0x0C9D1F5465E6305AULL, 0xFCC3FAD2379456F7ULL, 0xF14B47392A1E04C0ULL
        }
    },
    {
        {
            0xC01D1E1CC2FFF57FULL, 0x149ADF3CAD05E5BCULL, 0xC99BA34F80FE9E3EULL, 0x9609D21959BE3C3AULL, 
            0x5BFB247E0B51BC47ULL, 0xD8D674311E41DBB9ULL, 0x1E56E0E8BC1C907EULL, 0xA5EC3A2ABFFF5578ULL, 
            0x4C1561DE263B1680ULL, 0xE3AA82F14C559252ULL, 0x878DB3A66EC9731EULL, 0xD402962B5A4B1E38ULL, 
            0xCEBDA8C5AF70DCBCULL, 0x27843FFC5B5006CEULL, 0x3FC033C208CCBE24ULL, 0xBB523FECFD867D1BULL, 
            0x084AA857FAFC99D0ULL, 0x84EF69675414D008ULL, 0x90F1D05D22DEA284ULL, 0x6B69E42E891180A9ULL, 
            0xA3AE0274D7F3B3AFULL, 0xD99CAF8E822F81D0ULL, 0x1B537FDFFB3BB40EULL, 0x2955DCBD20FE77FBULL, 
            0x31EBF04823CE9358ULL, 0x398ED54C89FF6B45ULL, 0x328997E303D38872ULL, 0xF1608D2BD8D717E4ULL, 
            0x91DC5B1C3EFEAF49ULL, 0xB0BE9A1F367919C0ULL, 0xA2CD8D7ED25ACDB6ULL, 0x3CF751B4219191EDULL
        },
        {
            0x004C0830CED011CFULL, 0x72D05F0F4F73D08DULL, 0x557109A3D425CA5DULL, 0x0F23F3A3F777EDE9ULL, 
            0x67D1B32576E88B82ULL, 0xA57A1543542749CFULL, 0x89A61A9E91E6A8C4ULL, 0x78614235A1BC6114ULL, 
            0xE11F3A2DF41A4CA9ULL, 0x856A0BEC711423AAULL, 0xC9A64834EC8B55EAULL, 0xAB2910B125A4613DULL, 
            0x5D9E68515A109D5AULL, 0x5CC2F6CEF1476054ULL, 0x3B72D7F52DBD2653ULL, 0xA0AABC581FD2E8CCULL, 
            0x16C230CD08525104ULL, 0x5C3581C965AB6E30ULL, 0xC5FE97E0D84EB23DULL, 0xE5FF6DB78DE002B2ULL, 
            0x31E5D78EC81E27CAULL, 0x1D58AEDF6AE7F9C2ULL, 0x0C24DB20BB19D5C5ULL, 0x91F2A6494E0A6F33ULL, 
            0xB98334683BA02C18ULL, 0x29CDBDFD2AC7990EULL, 0x8AACE913D8CE4498ULL, 0xAA135121E922207FULL, 
            0xD0E1A2E03D9BDCACULL, 0xA60F66CF9084A1B6ULL, 0x4BCC87C07D93D4E9ULL, 0x6AD85E828070E511ULL
        },
        {
            0xDAC7362ABE85F18CULL, 0x4420FD1AAC61F251ULL, 0x3A219B16F6DD8CC6ULL, 0x28F73BFAB1A12186ULL, 
            0x1A3EC9D0A181E9D3ULL, 0xC16AAAEA90334A7DULL, 0x762E27A235BFCE2EULL, 0x16C30DC12461F660ULL, 
            0xB83111B8A0D6D28CULL, 0xE7F1A0B5158D486CULL, 0xBCB4E68A925C9521ULL, 0x1302E4CAE003C816ULL, 
            0x7759BFF3CC137C38ULL, 0xC32F16ADD473C18EULL, 0x6E7A63669B9037F3ULL, 0xF8694F70F7CAB406ULL, 
            0x1BD3BD3C1EA8E907ULL, 0x5B8504F9580BD2D8ULL, 0x91E582958FD2B6C0ULL, 0xF7D64BA623B6B796ULL, 
            0x03A096EC4F752034ULL, 0x97DE73713157324EULL, 0x95B20ABC4C620242ULL, 0xDBD6F5ED2BA0A484ULL, 
            0x9E8A55007255262AULL, 0xD7B5E21E0ABB5C93ULL, 0xFD5121D14FD7D5EBULL, 0xC6A444209BE07D3EULL, 
            0x247DA19BED109428ULL, 0xAFAA5CB21195C78CULL, 0x678A42C04DBC970AULL, 0x65472E2E52360260ULL
        },
        {
            0x971D72DD9F5AD5E9ULL, 0x9F260C0E0AA879E6ULL, 0xA1DB528BFBB8EA21ULL, 0x6F6FAD82E649FC7FULL, 
            0xF61C7964C8D1CEF8ULL, 0x4BD0B96CBA7F2E45ULL, 0x21B94C12D92BCDE2ULL, 0xDF5E9294C09FA139ULL, 
            0x594010DBB1E10EF3ULL, 0xC1359462DD352F55ULL, 0xF717DD7A602AC932ULL, 0x4B9771C0F73A3B87ULL, 
            0x3C831EAAD13A2B5CULL, 0x87CF1B1C6CC8C89DULL, 0x8B759F09674624E6ULL, 0x54DA515DFBB81482ULL, 
            0xEC328DDDF136D601ULL, 0x6BBF4C84DE2C37C6ULL, 0xD149259664F9B891ULL, 0xB2A1AA62C96B0399ULL, 
            0x7D113683790F495DULL, 0x9C6A5128D5AE88DFULL, 0x7091B8D902B36526ULL, 0xAF4656B55E8D3D59ULL, 
            0x47A44B31B76FA4B3ULL, 0xE524BA3C5F180D0AULL, 0xC422838E240B2F23ULL, 0xE147A09720758211ULL, 
            0xA2D9EDA21164215CULL, 0x28D935792B329B93ULL, 0xA64E7D96D6631217ULL, 0x89E943F5BEF4F2A7ULL
        },
        {
            0x092578B917FAF641ULL, 0xA917B4C66511D293ULL, 0xBC95AFBFD28A7089ULL, 0x3517271C3756BB74ULL, 
            0xD45CDB2BF9950CC7ULL, 0xE36983CD60BF031CULL, 0xD6E2498A13638E98ULL, 0x4257CF078627DF36ULL, 
            0x74B67FB0511FA2C6ULL, 0x4D7E26CB3252A8BCULL, 0x8EB0E3E26C88FE96ULL, 0xF10312EDB22F3BDFULL, 
            0x79A7351866A71170ULL, 0xC12CD997BA1B13D0ULL, 0x9477F349ADE2CFD7ULL, 0x6FE228568AC0A13BULL, 
            0x1DFFD535C0DB9EBEULL, 0x6F48FEED4C84C2B6ULL, 0x7087D4BDE7F8FFE1ULL, 0x5B40FFA231E29BB9ULL, 
            0xE29030E1A12DFC3EULL, 0x0511A9152D27D87DULL, 0xC1E6869D44158CC2ULL, 0x4E45FC25A487A462ULL, 
            0xDE6F666006C9667CULL, 0x605D897FA582AAD7ULL, 0x60BE6037EE98D6A6ULL, 0x99AF39AF2A75172CULL, 
            0x4088B31C7554E1AEULL, 0x20C70260CCD13F68ULL, 0x7A73DDA6E8A85430ULL, 0x3554FAF796E8809BULL
        },
        {
            0x27B0E0BF9E8C838FULL, 0x4BD8279AE2C5C90BULL, 0xD3DFFD2E414FEA46ULL, 0x3B78EB33EFB4A4B8ULL, 
            0x1C72C0B3C395DED2ULL, 0xB8517E475A272740ULL, 0x104DEE832ACCE884ULL, 0xCF76D14EDCF7532AULL, 
            0x63D6A38B13B33AF9ULL, 0xFE684AABCF49F972ULL, 0x5940AA7D74F6E02FULL, 0x78A39D5E1E239DCBULL, 
            0x494DA231DF3D7ABAULL, 0xF42AF38F254335BDULL, 0x554EC1EE71A48625ULL, 0xFCE35E557507A684ULL, 
            0xC8901E2E596A58C1ULL, 0xF8F4154D75F1163DULL, 0x0C4B015EA00EFB37ULL, 0x4D2BAC1F37A41DA7ULL, 
            0x9291441C6455EFFDULL, 0x7CEA8AD5A44BE57EULL, 0x664C63E2AABE54F7ULL, 0x8F00394E3CE15225ULL, 
            0x150AD73C872B8014ULL, 0x0EB27EE8D53083EEULL, 0xD7F046742B13CA71ULL, 0x851FFA90A0E47C09ULL, 
            0x940247D4F7D84F29ULL, 0xD5EEE907268D1753ULL, 0xAC20BED3D4E25688ULL, 0x8D40FF44401B675BULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseEConstants = {
    0x5FA9EF10B9A8BF88ULL,
    0xF33D393B4E860F65ULL,
    0xECBF851EB598339EULL,
    0x5FA9EF10B9A8BF88ULL,
    0xF33D393B4E860F65ULL,
    0xECBF851EB598339EULL,
    0x143C9A554F7FCAA2ULL,
    0x496EEF905D144023ULL,
    0x36,
    0xD8,
    0xB6,
    0x2D,
    0x22,
    0xC6,
    0x35,
    0xC7
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseFSalts = {
    {
        {
            0x64411436090724F8ULL, 0x84805935E77A2E6EULL, 0x4651AC2E090D7DF9ULL, 0x50C647EC390DEB5DULL, 
            0x8F5BFBD47629EEEBULL, 0x72F4E87389CFB9DCULL, 0xDC34D915DB48BAC2ULL, 0xCF743EC8915911C3ULL, 
            0x1BC31DB86D277A02ULL, 0xD8B2ED5C2F635023ULL, 0x429752EF6FC6AE4BULL, 0x8E22D6EC387CAA78ULL, 
            0xBAB5A786402C1509ULL, 0x109F0525566E22B0ULL, 0x9516924AE5418D56ULL, 0xECCC608C628AF684ULL, 
            0xF9F4688C32890878ULL, 0x7C66E58A27290541ULL, 0xBCD854E1BBADAC41ULL, 0x8AF0695EA8B90FFCULL, 
            0x4A4FAC06102099F8ULL, 0x8E29DBE0E319D87AULL, 0x85F685C2197A5ECDULL, 0xF85385570DC7F441ULL, 
            0xDB468E5A3986EA6BULL, 0xC66911375533BB4DULL, 0xDBEDD958ECD534D8ULL, 0xC0DB2DEAFE69206EULL, 
            0xA09C3C577CF7FBB6ULL, 0x65194CBF3F886C0DULL, 0x582761903B18B6CDULL, 0xB03F433C36EA6D98ULL
        },
        {
            0x73E28AE406DAE6C3ULL, 0x2386893D036B53CDULL, 0x14C6C6168E58102EULL, 0x44A05ACB7859A494ULL, 
            0x21B210CDEB4E61A1ULL, 0x88FCEED9E7746DF0ULL, 0xE15DF0CF65BBCA71ULL, 0x031944FAEAF4DA49ULL, 
            0xA7A17A406B862EA0ULL, 0x9F3DA0B22377C892ULL, 0x8BF841BB98CB3A5DULL, 0xFD31BC3161B858ECULL, 
            0x4E890E06CD5681FBULL, 0xAB3DCD8675E38E91ULL, 0x73FF1F5A585392C9ULL, 0x3C03D4449B05F6B9ULL, 
            0xF9BC03A4B0CFF23AULL, 0x3AD4FFE0440D5589ULL, 0x69E7F46B81D75C81ULL, 0x78B0DC51A26ED39FULL, 
            0xB01CC89522986A50ULL, 0x6C2944DDA3AD0C78ULL, 0xFF0D03979EBA7592ULL, 0x5D927EF34D46DDFBULL, 
            0x3BB5125019C1C307ULL, 0xBD239D86B1C3B1DAULL, 0x9C972A6357C457D8ULL, 0x99086191D9D48970ULL, 
            0xFDA3015912AF1275ULL, 0x7C6A036308CFCD6EULL, 0x0BA8E60D8E5C0F73ULL, 0x5A79BC97C1E27F2EULL
        },
        {
            0x0C56B65D910073D9ULL, 0x0AD68D44E849503AULL, 0x4B8BB4A4C4D97BF8ULL, 0xA0500544AEF8AF39ULL, 
            0x55EFE8932843FCB1ULL, 0xC5EF4EE8DB0AF200ULL, 0x53CC3ADAAB5DB1ACULL, 0x9C0A6FA5B1EA31DCULL, 
            0x03C0EA4AB3024A4DULL, 0x6B13B56D3D6F9C38ULL, 0x0DD8A9D0A998FF75ULL, 0xAFC1C397810E315FULL, 
            0xD392BFEDC4C7BBE1ULL, 0x9ABCAED2358540E4ULL, 0x07A72FD78F857D0AULL, 0x4087CF47D37B0A56ULL, 
            0x0FF31E90DA00DE3CULL, 0xF43D3D8E8D00D06FULL, 0xA0941E45BB15E280ULL, 0x71840CCB215D2332ULL, 
            0xF11BEF141BFE1A13ULL, 0x31E9B0F4CD6D0890ULL, 0xF9AE1ADAE312506CULL, 0x736E7736618357E6ULL, 
            0xE1D44AEDCBADA5CEULL, 0x78D1EF7CEEDAA347ULL, 0x7C52BAD3C333EE19ULL, 0xD269ACDF1098E040ULL, 
            0x309B786D248DBA7FULL, 0x258BF5017B7B4B4FULL, 0x93535E45AEA9B180ULL, 0xCD76B4706A13E7B4ULL
        },
        {
            0x565D0AC8B97E142EULL, 0x60EABB6F90A2ACBAULL, 0x0094F9BDCD78D3A9ULL, 0x7BFA6243FBCF5350ULL, 
            0x9D8C7AB83A7A9353ULL, 0x999F23F4FFA5F9AEULL, 0xCE095C8A6A9C6EF9ULL, 0x7025AA6F43278773ULL, 
            0xC773CDB158F45E04ULL, 0x0C4840FC392A4F5BULL, 0x9A2C943594A229A8ULL, 0xF723837FD18E9017ULL, 
            0x01CE6B152C22AC3DULL, 0x51C16CE4CF48A08BULL, 0xB38F68E3C1B3C5C9ULL, 0xB9E9E9FE54083491ULL, 
            0x990EB921A2FC6688ULL, 0x13CD90E945AA2994ULL, 0x95932042DE75E20CULL, 0xCF02158404ACA0C5ULL, 
            0x748AE035AD4759C4ULL, 0x4B736D913D633665ULL, 0x9EB121445B15BFA0ULL, 0x638212C948F1B3E1ULL, 
            0xD4EDFD1A92C038FCULL, 0x6EECA24953863066ULL, 0xB318E169563C3464ULL, 0x33F7232FFCCBDE57ULL, 
            0x64EFB415DFC61008ULL, 0xBC438418419D3B46ULL, 0x0659CE1B3EAF6221ULL, 0xE94D8D36D024D4E8ULL
        },
        {
            0x6AD3AC8AAC49A054ULL, 0x61E157B9274F391CULL, 0x5E2EDC41F45592D0ULL, 0x9020BE310D8B58ACULL, 
            0x5E1533DA753ECC2AULL, 0x9DDB4A872DF321D9ULL, 0xCED8485A18948BC9ULL, 0xC3AC5CEC934C440EULL, 
            0xBF012976B24A89E7ULL, 0xF92330E2668F4A34ULL, 0xC817A6D19E73F39DULL, 0xBDA3281C145468DDULL, 
            0x277FAEEF2FCA1FE5ULL, 0x1CD6E29ABBA3D286ULL, 0xEEF39F65F96E95EAULL, 0x76E342C511960C2EULL, 
            0xBF436775B93AB508ULL, 0x103C06E76C043812ULL, 0x46848D6F74AE6223ULL, 0x4B78DFB15D6977E1ULL, 
            0x5AF3629BD05D99B5ULL, 0x27C932796FEF3039ULL, 0x6973CCB603BFF6BFULL, 0x340476832E6545A3ULL, 
            0x0ADA5A4BC4225A73ULL, 0x2F7D969ACA189675ULL, 0x5625A6C2330D92B3ULL, 0x648201F24C3DA026ULL, 
            0x464FBE77F6CCB056ULL, 0x557C159FBDE613A3ULL, 0xF8F780A7DB1B617DULL, 0x2C9686AEA42828A3ULL
        },
        {
            0x632AC34DDBAE6F70ULL, 0x3B385AE863AF98ABULL, 0x1E8A2EF67484482DULL, 0x6BAAA0583A26F25EULL, 
            0x729EF1AEA18B4E92ULL, 0xA29553D81124481CULL, 0xD2D76610F628E6D1ULL, 0x8D9EA16977EE3C2EULL, 
            0x694DF5144574292DULL, 0x46230326AD32F2E8ULL, 0x697DEEE5CB6F8396ULL, 0x430F7D59A8991C89ULL, 
            0x503FF879A8808600ULL, 0x096580FD3C4C05AFULL, 0x23ED4665E8D05C64ULL, 0xC67FCD7830BF4B9AULL, 
            0xBF5118A565E2F259ULL, 0x86B8BD5779D5DE5DULL, 0x85BC1FC7309B62EFULL, 0xCFCDD15F8ED44107ULL, 
            0x8C4E676930AED761ULL, 0xD300341E329BDD78ULL, 0x7B686F18506D8C0EULL, 0xCFF0EA860124B1B5ULL, 
            0xAF4FBFBBA034C17DULL, 0xEE8AAC968EC1153FULL, 0x5E308734C20FFBEBULL, 0x4C0C00D7DB7FA5B1ULL, 
            0xE1319B008B41DC6FULL, 0x7C9A25DA7FCE5FCAULL, 0x0214B706BC4DA93EULL, 0x164C8C79A9F96018ULL
        }
    },
    {
        {
            0xA5BD1E60A53C6D78ULL, 0x81DA28087D7BFF62ULL, 0x7A1248CFC7F837AAULL, 0xA075367C4EF39E92ULL, 
            0x1EE015134DF71088ULL, 0xAA502EE9A054F859ULL, 0xEDEC167B81E959B4ULL, 0x713494A89B3E39B7ULL, 
            0x74AD03FA7FAEFD7CULL, 0x387C0681A273E063ULL, 0x510F285707CFBF68ULL, 0xD87C775136B82787ULL, 
            0xAF134BE691625B15ULL, 0xE3C7A2B3CD0AE0F3ULL, 0xEC2DAFE6A87C1BBFULL, 0xF20C56EADAB59AA6ULL, 
            0x00A78F234654709FULL, 0x50BA5EEB1CB3F9BDULL, 0x23672A928E9C5C77ULL, 0x99AADBAE0282D412ULL, 
            0x0520190B8F5F13A0ULL, 0xC3E5A257EE14D8F9ULL, 0xCA1FE1B43BBDF76DULL, 0x4D8701C1DC6FC579ULL, 
            0x599040D0E4CD95ACULL, 0x40649D1A4CB90128ULL, 0x5A8BFCE49C62C1A9ULL, 0xC20542735C8160D5ULL, 
            0x77F58373588DCFFCULL, 0xC4774A7D877CAD1FULL, 0xF6B4477B1F44CE65ULL, 0x17AF6EBB8033F6D7ULL
        },
        {
            0x429BDE3646C2BD30ULL, 0x1AC325D5FCD3189AULL, 0xCFD5BB4C8C96E30AULL, 0xFFCD721DAD2F2D62ULL, 
            0x34E2B54BF7988425ULL, 0x42E2FE0545A04866ULL, 0xB58934296FDE36FDULL, 0x72574CFE1B2653BEULL, 
            0xA9DD010FB52E634BULL, 0x724F4DA83B3BC6F2ULL, 0xE625C690E79AB530ULL, 0x8A0848760370FE10ULL, 
            0x75000EA15815FC01ULL, 0x00782D52271A9243ULL, 0xE7DCADE1E42FD921ULL, 0xD25BEB41338F92A7ULL, 
            0x4A4EDC13BEE959EFULL, 0x138F44A5A8F2ECF8ULL, 0x6E0FEFDC7282BA1BULL, 0x4E611A6954A1D20CULL, 
            0xEE0542EEA077D568ULL, 0x63BA460476ECDA1EULL, 0x5F81612A1D1BED62ULL, 0x8EED353204ABED7BULL, 
            0xF624D5D06173B8A4ULL, 0x2C6AFC8943B951C9ULL, 0x190A88A67F64B0B2ULL, 0x17416B3DF2E9B24BULL, 
            0xA9548EA2D9C1E8BCULL, 0xB6FED7174355850FULL, 0x724C9F12003B32A6ULL, 0x94EA503B4CAF6D9BULL
        },
        {
            0xE2305F989D28C63AULL, 0xA3F8F4D927F65517ULL, 0x65B03A22E1C2FDBBULL, 0x2B8376071D41E3D1ULL, 
            0xB08EB641A3DDA67AULL, 0x29C3F813A23C859FULL, 0x1F234BA293A52955ULL, 0xC65C5ED1712F0066ULL, 
            0x0010C06D93E5C65FULL, 0xA06FF99FE6913BECULL, 0xDCB4ED316FDFA145ULL, 0x1A44EF357112E749ULL, 
            0xE31634843ED58E34ULL, 0x885A3D0B125AD10CULL, 0x93B3E9B77DF76080ULL, 0x0F41D11A44145E1AULL, 
            0x8FB4AB5F40DAF486ULL, 0xC9E648636BC94607ULL, 0x09243F2B02577ABEULL, 0xA3678FFD48B32CE0ULL, 
            0xF672AA848787E78FULL, 0xB45988DF525EB500ULL, 0x4BE844E998BF93D8ULL, 0xA498C4E3793AEB43ULL, 
            0xE74FD6281279D760ULL, 0xFDC4B869C9C4041DULL, 0xF611E1C8AF8E60D0ULL, 0xFCB2D0C9014AA8D2ULL, 
            0x45A0D38A1ADB4195ULL, 0xCBB2FF1AA70A9A7DULL, 0x11922F1930103B7CULL, 0xF4E49C82A50CBF88ULL
        },
        {
            0x71F6E8D3952B060DULL, 0x47CF4063293BFB93ULL, 0xACDDFA656CF54E0FULL, 0xE53967D9E1D9434EULL, 
            0xF98C020A60546A66ULL, 0x5E96450836D3A5D8ULL, 0xA9BDBB39BA2D78A0ULL, 0x145B8031DABC4CE7ULL, 
            0x14355A77713ABB98ULL, 0x32F0541DF54B9A2AULL, 0xFC5EB6239C2E30CFULL, 0x60C8E0C884346A96ULL, 
            0x37F2D5666BF53CF5ULL, 0x41AE4DA7B37B0D5BULL, 0x64DB90268BEB00C1ULL, 0x4926EAA06D3FFCD9ULL, 
            0xB816A1CC9827E405ULL, 0x93465B81E4841519ULL, 0xF59AF0673D63E5ACULL, 0xF0D52B5AA56D22B9ULL, 
            0xC9F919F3610FD41AULL, 0xEBBCD2ECAA32E9F1ULL, 0x4D1072AF36DB0EA0ULL, 0x56F3EB9DB39D3345ULL, 
            0xEDAB474F728BC674ULL, 0xBBD5657528725703ULL, 0x1D7DAB0A9DC68833ULL, 0xD6BAA4930F3A987BULL, 
            0x75FFAECCF1C801CFULL, 0x647101DD9164A428ULL, 0xDFD76E75620C15CCULL, 0x8BE3205B6E6A9985ULL
        },
        {
            0x708BB2CA63B5CBDDULL, 0xA77EBE2C9CF9BF71ULL, 0x8030678F1C433166ULL, 0xBC4F8BE0C251A2F0ULL, 
            0x3AD4176103879971ULL, 0x489AFCBAB84841E4ULL, 0x96C1104142706844ULL, 0x47710662DB7C2A7FULL, 
            0x86ED9D8B71B9AA3CULL, 0xABB805DDE6AF91EDULL, 0x1AA3242585DD8066ULL, 0x45FF0307592279F9ULL, 
            0x9FAC688192F4340AULL, 0x8182ABBA5AF48D98ULL, 0x238A44B51BA387AEULL, 0x527150665DA489B0ULL, 
            0x99F9762085D521DDULL, 0xAE0A8A4287328974ULL, 0x4CC1E2FEB88924F7ULL, 0x73B356F17BDA739CULL, 
            0xF69FCEC4334F761FULL, 0x174921F849B39672ULL, 0x039099411CDBF337ULL, 0x81C8D0D2420089F8ULL, 
            0x027B9400866E2C31ULL, 0xC353706F0E755A0AULL, 0x47400388C352ED67ULL, 0x4CF38A6ADB384FAAULL, 
            0x8BFAA902251DB6B7ULL, 0x47584AFDBD39ECE0ULL, 0xEBE9107E64E43396ULL, 0x4DBEACF7F8B5CD05ULL
        },
        {
            0xA445571B361039E5ULL, 0xAAFA8911BF01A04DULL, 0x2453A3797C5ECE68ULL, 0xF442567CF92C705DULL, 
            0xE31EA2BD45021DB0ULL, 0xEC4FF6B4BA31EAE8ULL, 0x0DD26AEC79D7646DULL, 0x326EAA8B6A2D18D3ULL, 
            0xD118C4EF2FA13CDCULL, 0x2162332B60424624ULL, 0xF1F99157612716CAULL, 0xF80AEFB97389EA4FULL, 
            0x24073C11226B06E3ULL, 0xC37152498E8235ABULL, 0xA6F35BBB495C3641ULL, 0x7D07664E44F0904EULL, 
            0xD13C06301E11F29AULL, 0xC2ED431E60615EBAULL, 0xC6506CB7D48FEA22ULL, 0x93CB44C9D4BBFBF1ULL, 
            0x58785D66421A68EFULL, 0xE2166EED9601FF0FULL, 0x691ACD41AB75399BULL, 0xCF27ABF96DE6F82CULL, 
            0x41BB311FF998FA5EULL, 0xC6CC26F2A17CF58FULL, 0x70232BC0C0D07821ULL, 0xA7DD3D7D83B21999ULL, 
            0xEC481FBD096EB20DULL, 0x87871139EBE0A00AULL, 0xE089851692594139ULL, 0xCCC50B2561EEE141ULL
        }
    },
    {
        {
            0x3E503C6ACB724AF0ULL, 0x54EC766DC66DBC3EULL, 0x61ACD0AB94F32319ULL, 0xA9C1BA60D4B6B014ULL, 
            0xFDFDB26DE056C526ULL, 0x0683DBFC3E21FB5DULL, 0x3D37D9D0CF1EE3BDULL, 0x167A0E1FE35435C8ULL, 
            0xEBBBACA95CDDAE12ULL, 0x23DB47D756EDB263ULL, 0x266D109866C2D916ULL, 0x009C20B52760E825ULL, 
            0xBE6009C7BAD30B45ULL, 0xC476333AED68FEE0ULL, 0x7AAD6240EFA55DEAULL, 0x1317C8272350F00CULL, 
            0xD8AF1612C5B91D87ULL, 0xE102742D658F43E8ULL, 0x83E0342BA538AC68ULL, 0x46E3E0339FC49512ULL, 
            0x394E6B9D8259E109ULL, 0xFB724E6237FEE009ULL, 0x6169A628D1996A1BULL, 0x17D4D9772F0D25FFULL, 
            0x45CB467C3328EFC8ULL, 0xCADAC58DB9669EEEULL, 0x24182615445EDDEDULL, 0x0D5F6CF47C3552FAULL, 
            0xCA1CCA8AF1962159ULL, 0x3E79C2BDA5C6CE10ULL, 0x15DA791AF3D26F05ULL, 0x8506F368212A41D9ULL
        },
        {
            0x300F300098EE7C2BULL, 0x8738969A251287FEULL, 0xFE06B72E5BC6E3DBULL, 0xC6FAC49A6A8A896BULL, 
            0x2567B9AAFF6AF036ULL, 0xF4F2F3BEF2BD4811ULL, 0xE7D7965CB660C198ULL, 0x0CD04148FA3F6227ULL, 
            0x50D60E7EEBBA3EEAULL, 0x48FB5AC575BC6A58ULL, 0x9AE0AEFDA7F5098FULL, 0xBBE491CCA22E0FCAULL, 
            0xD286115CE7ADDE6EULL, 0x8D69F3D4244D7418ULL, 0x410364880649DEB9ULL, 0x1343AD25EC50FDB2ULL, 
            0x13F8FB7F9DE6A42EULL, 0xDA1CDCB08DBCF399ULL, 0xD8204F563C9BAF48ULL, 0x60705EC099A11745ULL, 
            0x25CCC4403B3AFAB2ULL, 0x66012D4C123AD0B6ULL, 0x626A1919A48C9DA5ULL, 0xF93AF1C18203710CULL, 
            0x04CC9FB01D32116DULL, 0xA4BADCC42F93788CULL, 0x45DB4258692EDFA6ULL, 0xB721828716808226ULL, 
            0x2BEFF59E9E842455ULL, 0xB030FA013FBED378ULL, 0x9925A7AA3806FAD1ULL, 0x8D1A893B98393C8EULL
        },
        {
            0x2C73D86672452B8CULL, 0xDA6E43AA6B2CE459ULL, 0x9416AD30127AF327ULL, 0x5F87BC310355B609ULL, 
            0xBD459D566A7CDBAFULL, 0xE05EED60C608F8B7ULL, 0x6DBEF50085276D1DULL, 0xD53EFA9632A96FCFULL, 
            0x1BA779EB9CA0DE49ULL, 0x14488CC444262590ULL, 0x089936541F7A3CF3ULL, 0xA97C9B64841F942FULL, 
            0xD6A9EA9B25E58D9DULL, 0x1BE096C8C3387978ULL, 0x0D04325ECA9B3A89ULL, 0x067934CF3B3D155BULL, 
            0xFE4D38A929AFB8B6ULL, 0xE618CA4C20FA5ABEULL, 0x67039FD4D937FA2CULL, 0xCBD12E0BCC912163ULL, 
            0x83207E465E785189ULL, 0xFE84D6BCBF344D9AULL, 0x0D70A5BDDF32E16DULL, 0x9EE61779237927C5ULL, 
            0xF4DEE592C69C132BULL, 0x16070066E87892B5ULL, 0x2CB55286449BD896ULL, 0xCFC58E07E402AFBCULL, 
            0x342F1958FC958AE1ULL, 0x0BD1989323C0AA25ULL, 0x852F9F6E0D6C6DCAULL, 0xA01D2B3BBF1F3041ULL
        },
        {
            0x82BE3E00BEBFB0BDULL, 0xB2A32DA6B3B86647ULL, 0x2C5EE6DD73A98900ULL, 0xCDFE3DCFB490CAACULL, 
            0xE638816236B76708ULL, 0xCF07EE3849A50C79ULL, 0x4C230D72201206E1ULL, 0xA071B5287FF66EEEULL, 
            0xF823B9977FC6D82EULL, 0xCA4C6D19FCB6430AULL, 0x7CBA11590700CE33ULL, 0xB9DAAD67969BF2BCULL, 
            0x9BA909525C3383D2ULL, 0xAF4A9DEE1139948CULL, 0x15D848FEECD8EF67ULL, 0x9D621B02C4C9EC0EULL, 
            0xFC0C62EE39530A04ULL, 0xE129951C4AD6C23FULL, 0x379E187B8AEC154FULL, 0xC9A8D0D5EAA9E58EULL, 
            0xF2682E618795A543ULL, 0x28B99C60AAEBA4B7ULL, 0xE3EF966561BBF41AULL, 0xC96AD6B4AF0CBECDULL, 
            0x6CC354235345BF90ULL, 0x4D170A458F0FF5E5ULL, 0xBBF9EC81827F961EULL, 0xF57476ED49C8191CULL, 
            0x8658506080C8FDB7ULL, 0x5711F19C4C2EF861ULL, 0x0F14411506C2F33CULL, 0x9747240249059017ULL
        },
        {
            0x82E25FBF0D00657EULL, 0x3CAC910CD01B4960ULL, 0x49F9EA5FD47B5599ULL, 0x3BAF8C7A3729936AULL, 
            0xC15B0F07266A4E5DULL, 0x0848D3E5623357DEULL, 0x156264208FECC600ULL, 0xA6D38C6D1054BE16ULL, 
            0xE757F96FBD8FE6DDULL, 0x0C50F248BB878BE6ULL, 0xBBB14851021B87C3ULL, 0x0DFEB86BF94019E6ULL, 
            0x9856DCB22A988327ULL, 0xA9F616FC825497E4ULL, 0x22DEFA7E53F7103AULL, 0x12F5C76EE4E1EA99ULL, 
            0x26C6A883B83D2DA5ULL, 0x08F8327AE6474D7CULL, 0x9FD64D254969DA5BULL, 0x0C43A2E48F94A70EULL, 
            0x2DE198C28B4596ACULL, 0xAF2B50F8F33E2BDAULL, 0xFF235CBA5F766BF0ULL, 0xE2FC8864BE6AA2A9ULL, 
            0x2205FEC2B5593646ULL, 0xEAA9C0E1BB58EF2DULL, 0x326F5F5041F81E7BULL, 0xB2E618BE416DB684ULL, 
            0x2E50C0F8237EAB3EULL, 0x22380831B74ACC25ULL, 0xBA169AD3278B71B4ULL, 0x7C82DC773B9CD39AULL
        },
        {
            0x94991198EE485003ULL, 0x923EF2C78CB8434AULL, 0x2A03FFF54B04D92CULL, 0xDDCD50CD3916461BULL, 
            0x7C5FA3451F06F0F1ULL, 0xA6CBD97A36383328ULL, 0x4E4FD3DC87B08C41ULL, 0xA5CE526F251A6B49ULL, 
            0x238ED16254DE87F3ULL, 0xBBF2E7AC50149739ULL, 0x8049F25BC6461208ULL, 0x39D63E1E768B083AULL, 
            0xB5D575081681AACEULL, 0x0DB7A7860B11E325ULL, 0x6DF0EDD562D714B5ULL, 0x70BD370333E6D191ULL, 
            0xB02F3782E5E00794ULL, 0xFFFB1C6B98922D20ULL, 0xCA4E1C47CF74A619ULL, 0xEA62A1E9306C6A14ULL, 
            0xE49D87ABC995BCEEULL, 0xA24BCB5445B3ABA9ULL, 0x16DE639FD5CE1F4BULL, 0xB9A09F16492BB3D6ULL, 
            0xB6FA8693DCCED62AULL, 0x9159429CE5E24109ULL, 0xA56AD3D91B8AA3A2ULL, 0xAC48027D44EEB586ULL, 
            0xFD1460EBA1AA174DULL, 0x34E23A918C2CBBEFULL, 0x819A6C71EE395130ULL, 0xE215F4B35A638D8BULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseFConstants = {
    0x9B7A3DC3A4A68604ULL,
    0x1B833D4633EAF0C7ULL,
    0x49D803EE82F49D61ULL,
    0x9B7A3DC3A4A68604ULL,
    0x1B833D4633EAF0C7ULL,
    0x49D803EE82F49D61ULL,
    0x075F3726D0FD03F9ULL,
    0xC3712633AEB0E04CULL,
    0x05,
    0xD4,
    0x16,
    0xF2,
    0x9A,
    0xC7,
    0x5C,
    0x5A
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseGSalts = {
    {
        {
            0x30D79A8600AFA2A4ULL, 0x263253D072C9004EULL, 0x68234B32DCC7D624ULL, 0xF9273EC8BB21D8CEULL, 
            0x20C7316EAD1DA8DBULL, 0x61CE6FB2A09F8088ULL, 0x79B4E17C5956B1B5ULL, 0x78FBBACC51082B8FULL, 
            0xA40D7E526B5CDF9CULL, 0x90B8F43776BFD587ULL, 0x437D6FDBBF67DBAAULL, 0xCD838EDCABAD0B33ULL, 
            0xBEB9C94EE2B067F9ULL, 0xE51B286D1445A563ULL, 0xF6E947B50EBC38D8ULL, 0x483AA0393DB1133CULL, 
            0x19122867F1286739ULL, 0x64880CD5AA1DDA00ULL, 0x73370A0855A8F947ULL, 0x45B1B97858CE3E05ULL, 
            0x69266702E9A4CE81ULL, 0x416620C4A54C5DFFULL, 0xC0EB4D41841C24FAULL, 0x374973B6537DB6BBULL, 
            0x82AFF56AB9742BC6ULL, 0xF6FF6716B893323CULL, 0x6643AAA1D2E46F34ULL, 0x6A6995F4D2E75C62ULL, 
            0x01C88FBEECE4F9BCULL, 0xAAE2DAF4A060DCE7ULL, 0x5F46ED23FA88978DULL, 0x0B39D0C32B428DF2ULL
        },
        {
            0xA2D3EFC6CE5CCA5EULL, 0xB28EC9D776256A37ULL, 0x07033DF73AC98DB1ULL, 0x158D9AC28B292EEEULL, 
            0xC8FF44E3B05BC572ULL, 0x074C072FDB1C6088ULL, 0x43C3B2A9DE6B7190ULL, 0xDA2BB7227B1454FAULL, 
            0x9C4892B31ED9A5D5ULL, 0x148C2DC4E173E10FULL, 0xA7BF8E74FB463520ULL, 0x727796A6F58229CCULL, 
            0x99891B1A168BBE26ULL, 0x5482C819925D0146ULL, 0xC18ABE39DC05396CULL, 0x70B39205519392B3ULL, 
            0xB59F9641CE875C90ULL, 0x7E33C44149725903ULL, 0x76FD0817C50DF284ULL, 0x94EFBBC5A4EDFBA7ULL, 
            0x4D600078CFFF07ECULL, 0x1FE0E193C4B08DDAULL, 0x4A3088C2CDDA9BD8ULL, 0xE5AD2E96A314DD8CULL, 
            0xF3BACC3E0F60DFBDULL, 0x1987E60D22D7FA54ULL, 0xAADF9C380B677F41ULL, 0x6205233E3EF29509ULL, 
            0xE2408A64BE095E95ULL, 0xC7C26840F7473A95ULL, 0x02DEA303BE83003FULL, 0xEBF426ABB8E8EC96ULL
        },
        {
            0x26C3208921366A2DULL, 0x83EB2EDDC755C3B1ULL, 0x3B1FBB5CE5AEA8EAULL, 0xF39F845E0C3E6DB1ULL, 
            0xFDABF06D2C77AE95ULL, 0xD26B8D556D1E4CE8ULL, 0x9D296A314BF3218FULL, 0x368495BA7B05F614ULL, 
            0xCA323AB435A3BFA6ULL, 0x7D6E51DE37AF22A3ULL, 0x535AA050D649B3B6ULL, 0xF7E9469223665EABULL, 
            0xF242B7E32673A98CULL, 0x5CE7794201FCC64FULL, 0x6B22210DDD7E526EULL, 0xE763D4227C82F7E8ULL, 
            0xA82E8DC15A212DF3ULL, 0x5FD597775D717C14ULL, 0xC53C014E43D5B102ULL, 0x3ABA3221551E02F8ULL, 
            0x5B4727A9CF57FC98ULL, 0xD5523FADDD005BA7ULL, 0x599B0ED2C3EE0BA9ULL, 0x9B6BC8D0A7EE6F2CULL, 
            0x6F3832B1390AA23AULL, 0x2D44FBF5EA6AB1A6ULL, 0x2C3233CE163B2BDFULL, 0x7E36D497E6732A56ULL, 
            0xE76608445A65C868ULL, 0x580927EB3B5C587AULL, 0x5D88330B9AA12312ULL, 0x09CE782624D271B0ULL
        },
        {
            0x9F6FD02B0CB43E0DULL, 0xDFABD75610166C8AULL, 0x463379CC40995234ULL, 0x7918B451C860D182ULL, 
            0x3BACF9E734F3E14DULL, 0xFB885AE0CF3ED8E2ULL, 0x1678F2479F33EEC7ULL, 0x3BC2EE86B4E9F5D8ULL, 
            0xEA9BB456925B5E2BULL, 0x4BB25A61B5AFDFE2ULL, 0x73E866B31CBF172EULL, 0x6B273BA487576AC8ULL, 
            0x39686DECF640C178ULL, 0x12F3EC2E34439161ULL, 0xDB5635FB19D47972ULL, 0xE6A7603393E5C357ULL, 
            0x371B690DF3BC2F98ULL, 0x9030B3AF50E61680ULL, 0xF3AE026AB772E6FAULL, 0x7D5C80709A9AEFDBULL, 
            0xBA2D8B2DF622C5B2ULL, 0x5F10D1145AE1BA39ULL, 0xE4E82186240623E8ULL, 0x68E58EAB32F687CCULL, 
            0x7BEE18000A0F7E61ULL, 0x7810405110EF6CC4ULL, 0x6C23BED950B8E486ULL, 0xD21834D7CB18DAEDULL, 
            0x71AC19E07D5720C3ULL, 0x4E29744E2EE8206BULL, 0x6957B2FD637CD9C4ULL, 0x0CC4B744793A7681ULL
        },
        {
            0x1854B118B8FD858AULL, 0x147A825AEE551EA8ULL, 0x3EF556C9B4DE4241ULL, 0x05F1A2A66722912DULL, 
            0xDE97E4F8EEC3A07AULL, 0xC155AF575C02BA60ULL, 0x316110D72274E8B4ULL, 0xA5F625774840DD79ULL, 
            0x31B9214203BD20CDULL, 0x21E3E024B8083084ULL, 0xE9FF1812CA6AC311ULL, 0x0A3358F973B3ABACULL, 
            0x6CA2D1E32A37C6A0ULL, 0x192FF0A8C8BDECF2ULL, 0xCCB0786264E1B956ULL, 0x6FF0C6C445010850ULL, 
            0x7925734342C5DD84ULL, 0xD26A57BFAD3995CDULL, 0x6743697CBB017DB8ULL, 0xA678747C599CD8FCULL, 
            0x0C4691BB274A6B8DULL, 0x2A5A713499FDCAC7ULL, 0xDBE34DE47D035A27ULL, 0x44B0214442C91487ULL, 
            0x73F1D505E1FF54BDULL, 0x64345347316E5549ULL, 0xDCF4BC08E093576CULL, 0x1E04907827C3DCB9ULL, 
            0xAD53348827543D96ULL, 0xFD4C70D3837E340BULL, 0x18B8A94C99980A18ULL, 0xD769901CB9D4508CULL
        },
        {
            0xC6E102945AE18CA5ULL, 0xEB8CAF3DF5F2D81CULL, 0xFD6D1BAAD513504AULL, 0x1DAB160E8E7F8871ULL, 
            0xD869328537B94866ULL, 0x7AE7D1BF696905ACULL, 0x5CFA1A5FA32D86E4ULL, 0xB3B0937AD01CE1EEULL, 
            0xD7DC9754500EBAC3ULL, 0xE98293005E0A1257ULL, 0x578BB49EFEB8E67BULL, 0x00EA9BCED73BBBDCULL, 
            0xDF06031E8AD6EE58ULL, 0x3D357FB5CCBB0990ULL, 0x43E029BAB02FA2FAULL, 0x418B8FCB8C7D69B1ULL, 
            0x1387C6F17AA1B16CULL, 0x73F08ACC15CF2B1CULL, 0xE482D70E5847277DULL, 0x9CC9878A5CC51A9FULL, 
            0xD1B44FDF722D1445ULL, 0xEE1FF79DC8DBAE13ULL, 0x21A4C26B36B7877EULL, 0xE5C19E0CD7F6FF77ULL, 
            0x6D9364B8EBF05C0CULL, 0xA9DBF4B9B60F1D9CULL, 0x850BE11ACF65713FULL, 0x54785C6C482D21E7ULL, 
            0xF58D471F9F9469C0ULL, 0xBB610F36268DD1CDULL, 0xF9FE2CCC6517D845ULL, 0xD565AE83A8D79A2CULL
        }
    },
    {
        {
            0x5E163D971D53C76BULL, 0x899851CCC9A07D35ULL, 0x53C0F8B5668CF88DULL, 0x3C2FF3D215671B8AULL, 
            0xD5480B78D6DD208FULL, 0xAA774BDEB3EA72BEULL, 0xD56518262DAB7288ULL, 0x37AD113900831896ULL, 
            0xA595B39A86B46DB7ULL, 0x8EED3C7C7C27B1FFULL, 0x09AE469394E3C818ULL, 0x0497C95386F17BBCULL, 
            0xF0F3AFD332F2CA98ULL, 0x73DBB4EFBCE37C77ULL, 0x86F9EE2ECC10E062ULL, 0x52BD219DA7377DB5ULL, 
            0x3894B38DA5E7472BULL, 0xFC06D90E56268753ULL, 0xE01E2FD81D307933ULL, 0x86EB1DEBA66E0E0AULL, 
            0x9EF62E1100A81C65ULL, 0x92FDECD437943912ULL, 0x2B1C8AD9C614F0F1ULL, 0x746E3BFB02F6FB03ULL, 
            0x0DD47542ACA619D3ULL, 0x589213BC88F6E65CULL, 0x1FA391E5FC0EC392ULL, 0xAB2F0913578E1381ULL, 
            0x1354823CF8EF0ECDULL, 0x0662F00E92A00BB9ULL, 0x8B22D401EC184342ULL, 0x1B601086FF8358E0ULL
        },
        {
            0xC74BB39776820B9CULL, 0x69963D7350079B41ULL, 0x3CBADCD8A197DB38ULL, 0x70055D999CE186DAULL, 
            0x946281DDEA636328ULL, 0x46DD77F7F67D177AULL, 0x3071ADB31D4D528BULL, 0x43033FBFD19D737DULL, 
            0x4FC89D9224D39933ULL, 0xB48FA31CA3EE4D09ULL, 0xEDAD7B7B6DBEBEDFULL, 0x78C0A6DC659D43A5ULL, 
            0x84007E9BD5739C7CULL, 0x1A9A2988A2BCA772ULL, 0xE6DD006F00CC2D3CULL, 0x38490BFEDCDF7BDAULL, 
            0x1D9C81A98A3B4DD4ULL, 0x53344764809079FEULL, 0xC52CD0751BD9D8B8ULL, 0x905A369748B354DAULL, 
            0x37833B469F5D44CFULL, 0x19324A146469FD15ULL, 0x8A132F3B739B239FULL, 0x2404C44CF87CAFDAULL, 
            0x4672D90FF8D0E2C4ULL, 0x98CF32CB8F6B4D89ULL, 0xCE6608D716D4BC22ULL, 0x433F746EDA794910ULL, 
            0x857175BC9A90EB69ULL, 0x7E7928C80450A638ULL, 0xA61A247DEC5B94EAULL, 0xD5CFA1E49FD6C006ULL
        },
        {
            0x899688413D30C491ULL, 0xBEC92DD4B01908D0ULL, 0xCD62F1C9F547E875ULL, 0x1C5FC4C5EF76E150ULL, 
            0x69765AA1283EBF22ULL, 0xBB30FF47F30B19BAULL, 0x2482D6657F52406FULL, 0x477AABEBE1818806ULL, 
            0x3D3207361FD4D47AULL, 0xFD52E8A9F4CBB3ABULL, 0x0591F40329DC3EE5ULL, 0xC3C1E59549FB82C5ULL, 
            0x2E1ECBE3E67518D6ULL, 0x761D3C91FF06D294ULL, 0x4E4C1F7B4E02E9F7ULL, 0x79D41D5470253D2FULL, 
            0x6BE1DE26DDF68816ULL, 0x2932F423053658A9ULL, 0xE6D0D0082A62C5D6ULL, 0xF78B9B3BFC905A7FULL, 
            0x045A5E652DA80034ULL, 0x217615ADB93F2B39ULL, 0x1A3893E8F6C491ACULL, 0x29966411BDA8F775ULL, 
            0xA58C8220CC953390ULL, 0x1D380FB20D3C1BC7ULL, 0xF0FBEAD5738D79ACULL, 0xDF3501E76EAD6A94ULL, 
            0x526EBF10A46564F7ULL, 0x1E6133637631404AULL, 0x7A3F05954DA588EDULL, 0xF3CAB68B22B88DA5ULL
        },
        {
            0x837F220F0F76A03DULL, 0x41B0F50E2F6ED5DFULL, 0x479688C8999E9B3FULL, 0x6E40EA993032D12EULL, 
            0xB7F103F4F753960CULL, 0xC71AEE666DFB0EB8ULL, 0x15F0CE1CDEF42D33ULL, 0x8E935DF1CB312D77ULL, 
            0x0302CC4154F7F47EULL, 0x69BDDD1B75A0CC37ULL, 0xAAF858405EABC459ULL, 0xD57F64FECE458E02ULL, 
            0x5C6C2070F650AF7AULL, 0xC53A317CA0332306ULL, 0x645C3AF6B12E488EULL, 0x1E257D4A60D9F0BAULL, 
            0x739627C73C17C039ULL, 0xEE2B5360AF4EA350ULL, 0xB71904DA3F44714CULL, 0x5D2651C54E7E5F0BULL, 
            0xCD1F243155DA63F7ULL, 0xB66CD03CDCA50531ULL, 0xB776F529F6A70D82ULL, 0x45522603DEE499E6ULL, 
            0xB2AD1389E7A4F26DULL, 0x73C4B21E5B0E1907ULL, 0x67CBB76C17411346ULL, 0x5E0B357A80ACE104ULL, 
            0x45F439424821463EULL, 0xD7DE2D67041039B6ULL, 0x3417C8E54742F2A1ULL, 0x8427F9B55658884BULL
        },
        {
            0x88B7F13BBA722610ULL, 0xFF1A96F76B82F37CULL, 0x011C34FC7C90D3F6ULL, 0x5C69D930FADCD3E4ULL, 
            0x39AA54865046C8ECULL, 0x0CDB221FD8DAA7DAULL, 0xB405C1FC832D7584ULL, 0xF18D1291E5178EE2ULL, 
            0x4E7A5457269BDF8CULL, 0xC5037A82C100E259ULL, 0xA7B2783B8DDA71F1ULL, 0x93CDC31126B05A0FULL, 
            0xC4E4EBC9B7EC7F2FULL, 0x1DBB16B5120545A9ULL, 0x51B1600BE93FB7F2ULL, 0x8E5FD135DC6C62E9ULL, 
            0xCE190E331B2CB9B5ULL, 0x46D9BBCED0CE5F5FULL, 0x3A63299DBBF50ED2ULL, 0x640672E6D75829CBULL, 
            0x385F5470ACF36857ULL, 0xC5831D708664CF24ULL, 0xAA00AD2F15B47554ULL, 0x5EC6B6EFADC653BAULL, 
            0x1BD837C640BAAC35ULL, 0x0196BB9DFEF125F0ULL, 0x6F46E72C76F1CA68ULL, 0xAF609F12D5757D20ULL, 
            0xD23483622998DB84ULL, 0x93B4495340F93808ULL, 0x64837D8A2D759453ULL, 0x9C46DA895B066256ULL
        },
        {
            0x7FB6D2F9E660BEF4ULL, 0x1CC6E389A757FC29ULL, 0xC980C9BA59E36988ULL, 0x1EBF5940CEB25C7BULL, 
            0x286324BEE28433B0ULL, 0x4CBC83861F3628C2ULL, 0x00EE7F2D496D19D6ULL, 0xD4B5C672A54AEA49ULL, 
            0x4E4444BB61187E01ULL, 0xC22E247577E64EFEULL, 0x06A557AC504D7613ULL, 0xA316354D0C1CB090ULL, 
            0x29F26BB7F1524AC4ULL, 0x6B862A2BAFF725C9ULL, 0x03C708C5E25EB10FULL, 0xEE08BC5F1807F266ULL, 
            0xEBEB495568E976EBULL, 0x7F0C45E66261A666ULL, 0xA8482F015DF480DEULL, 0xE7F2EA48A37DA8FFULL, 
            0xFA3571F2A044E435ULL, 0x380077C88F4E42FCULL, 0x9FB3918C2C30A607ULL, 0x41A093485648E284ULL, 
            0x5F406996C04D4024ULL, 0x88D609661C31D4BBULL, 0x48844CF419FF0A57ULL, 0xFB1298727A0AC4DDULL, 
            0x8A0FE0B447534F8EULL, 0xEEA05411B85B48C0ULL, 0xB29ED7BAB1CA9AE1ULL, 0xA207A082D161DA49ULL
        }
    },
    {
        {
            0x243C2680D4589090ULL, 0x0C19B97FC06E04EBULL, 0x4D9CB3CFD10938A9ULL, 0xF3A2F2150E32C9ADULL, 
            0xD754C4659D14C4E4ULL, 0x7A1DB635E5592EEBULL, 0x870E8561DE79B4B4ULL, 0xD3EB80F10A6AA5D3ULL, 
            0xCCBE37BADC62EE96ULL, 0x5EE2288832E0442AULL, 0x218E26A5F3464A15ULL, 0x7EE4EC655D92203FULL, 
            0x9FA7A26385BB2BABULL, 0x30FED2FBD103F945ULL, 0x2DCB334B69C1B9DFULL, 0x29CDE7F1E0CE75DAULL, 
            0x03C4D2CCB2EDE790ULL, 0x8FEDDA70991203C0ULL, 0xC45F1607C7AD1BEAULL, 0xB4BFE7DF4A8ED7ABULL, 
            0xB1292F1A37607B8BULL, 0x2CE9DBD9B8E5EE89ULL, 0x68C9C3DBA63D293DULL, 0x3B1A03E15977CAF1ULL, 
            0xC412AA02E5E42026ULL, 0x8E9EBC591C90F175ULL, 0xA30B5CC702800FB6ULL, 0x6229E32FD5837F81ULL, 
            0x66EA7C925C5579B1ULL, 0x7C14C72A7AF89E01ULL, 0xE02A496502AD1D05ULL, 0x8987B2A251086C1CULL
        },
        {
            0xE0CC2229BFA7BB32ULL, 0xBF0B8A41CE1107E9ULL, 0x5DD6997F9F644DCBULL, 0x3E2AA3FC8C7D94AEULL, 
            0xED881256A83BFE81ULL, 0x8DDB2127AF1952C9ULL, 0x99233B923F16A5EDULL, 0x66D005BD5F5598FFULL, 
            0xBCA79AC8B4A33DB8ULL, 0x340893F53D335310ULL, 0xCEF134BE10C80585ULL, 0x78A4527534CCC938ULL, 
            0x8D66EE59E9C74461ULL, 0x6BF3895BC4722DAFULL, 0x31AB3DC25C4C3EDEULL, 0xA344270D8DBF97EDULL, 
            0x32EDF559ADEB2A5DULL, 0xF6F1DD06C67DB969ULL, 0x65EFB7B041941252ULL, 0x3469C5B85D411F26ULL, 
            0x8BC0FF2801DD7360ULL, 0x2613AD5E5A88935AULL, 0x716EFAFEF721042DULL, 0x62BC7204AACC1E70ULL, 
            0x7C30C01B96F571B5ULL, 0x92FD96423BED3276ULL, 0x16C505AD411F0E41ULL, 0xE03F2E9DAAA4A29DULL, 
            0x4F4270A82817DC95ULL, 0x9027A0F42CF3084DULL, 0xA8F7734901B4E63EULL, 0xB159F0247CF05508ULL
        },
        {
            0xD789379DB7C33968ULL, 0x5781A47F0B922C89ULL, 0x1E0DF9A33B403598ULL, 0x3DF281FFC703EB31ULL, 
            0x57D6C396DF4F0F62ULL, 0x3C4A1FE0F9BE0864ULL, 0x04B03A2AC2DD4561ULL, 0x4A95C42503EE960EULL, 
            0xA63BA00E85807733ULL, 0x8DF6D00034A4B437ULL, 0x72B8055F5EAA231AULL, 0x6FC85FE0A74BBDE7ULL, 
            0x0BE1950D409C0127ULL, 0xF4C1A6326933851BULL, 0xFD325DDD73F9FE48ULL, 0x7384BCBB9C34FFD0ULL, 
            0x28C2942D9D2603C7ULL, 0x2E24732F704B2806ULL, 0x5927F034D218F64EULL, 0xC827D1A21B2F8E53ULL, 
            0xAA2CD3D0B0194949ULL, 0xB0FC8584C6E6CDEDULL, 0xA1F6608D07E6BA71ULL, 0x1E8E4DB937C2D412ULL, 
            0x195DA509C0115A2BULL, 0x8E8926C9CDB9F630ULL, 0x06CCA843FDCB720FULL, 0x1334EAABD8D51C32ULL, 
            0x1AF8F361B3A0AB58ULL, 0x61141302A8A74D9FULL, 0xE571E7A5E99B9CB4ULL, 0x8D104F7D55EDA387ULL
        },
        {
            0x52F4B8B7DF494876ULL, 0x39DB1A398BA40E36ULL, 0x9F7FB0427B8FBAE7ULL, 0x8DF4DD0EE86E454CULL, 
            0x1DA812D763D6ABE1ULL, 0x06CE5821E2F48C3EULL, 0xE8F5730E4440C0CDULL, 0x065C30B425D2875BULL, 
            0xCEE045A9C26747A4ULL, 0x34AAC3AD6AFC5D4DULL, 0x7E40A1A363260305ULL, 0xE33D0CFBE03E37D2ULL, 
            0x4A36DBAEE37AD53AULL, 0xF2661CEAE1C37B0FULL, 0x93B52C09D060089CULL, 0x8806A7CDEDA76F14ULL, 
            0xC7662114F772CE13ULL, 0xD0E422DF0C9D7BB1ULL, 0x8E76257CA6AF9A0EULL, 0x58F16E5435AD7AB9ULL, 
            0x47C0290363FC8C8BULL, 0x100AF511CE9DE3BAULL, 0xF4628F92859B7060ULL, 0xE241EF61E74D1FB3ULL, 
            0xD21CB0665F00E1CCULL, 0xC14CE385E8455687ULL, 0x3C798AFFAF055AF3ULL, 0x85497CFB3B3B0E6AULL, 
            0x8EECFAABA7DE4AEEULL, 0x0ED98374E458145DULL, 0x134C957DD861A8E4ULL, 0xE94215D82CC14348ULL
        },
        {
            0x169224175BB6ED49ULL, 0xF5F8B602F9C85B3AULL, 0xB111F4A807F3BCB0ULL, 0x2563DA0182DD90FAULL, 
            0xDBC57EA99DA877AAULL, 0xDFED8422DC84B010ULL, 0x34BBF6E80700D567ULL, 0x2C70799BAEC53B71ULL, 
            0xB582500BC3939CFAULL, 0xF461A8FB1E1DF47BULL, 0x2DAE1342A5F7131DULL, 0x964B3D952CDF16AAULL, 
            0x0F2E3DA058D34FC5ULL, 0xE95EB1535C7D47BAULL, 0x00AE812FC80FEA04ULL, 0x3FD73A1EB8D674AAULL, 
            0xAD1058A961328950ULL, 0xE2D7D4BA7863E054ULL, 0xA8781E87DA7531CFULL, 0xFEC79AD09FD67696ULL, 
            0x44ED98BEBF976F61ULL, 0x51F88E720136A0B6ULL, 0xD93A4599DFB8265BULL, 0xF3E79671188A5509ULL, 
            0xD035C6FF39E87CA7ULL, 0x091249B998EA9BE3ULL, 0x52F801EF790EF63BULL, 0x3A5A32977346A18BULL, 
            0xEB7331FA1F31206FULL, 0xFEF80F12C9DC0388ULL, 0x076FA2CA31969E18ULL, 0x83B7579815BC5850ULL
        },
        {
            0x2F70A6E4C4860869ULL, 0x2F76D341F89EDE71ULL, 0xEC59F380D6FDD03BULL, 0x34FA7A2BFE2C29A6ULL, 
            0x396A594E0F191815ULL, 0xFF8BE5150D455BB1ULL, 0xE45C40D6428821C0ULL, 0x0C3B30D0166C2D06ULL, 
            0x931F29DA912A9CD3ULL, 0x2B6CE32E3906BB57ULL, 0x7A9DFC0204EECFCCULL, 0x6FE4C887B5882116ULL, 
            0x1D3AF97109CF6B41ULL, 0xE2235DC3D1708577ULL, 0xD0AD13CA05236B60ULL, 0x1874C84207642AFAULL, 
            0x7D6FCE33E3A5C0C5ULL, 0x3914D0FB089E468FULL, 0xE44A75D94C344955ULL, 0x49010B07D993A639ULL, 
            0xD6F336ABF1D6CC32ULL, 0x050ADA5B9448F7CDULL, 0x77605620A7D4CA53ULL, 0x410449FE6C2B36CAULL, 
            0x1EB93A1EBF736265ULL, 0xCAA837326A9B941EULL, 0x2861F60E52142BD4ULL, 0x8E00F7BF8B510BB4ULL, 
            0xF38AFC390CF7A5E7ULL, 0x8AA5CA1BB08B53BEULL, 0x72C480E7C6532A40ULL, 0x3C87C46D43A05A14ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseGConstants = {
    0xEFA4FA8ABF805FD4ULL,
    0x2A753081455993D6ULL,
    0xA89D6E9CC3BD7AC7ULL,
    0xEFA4FA8ABF805FD4ULL,
    0x2A753081455993D6ULL,
    0xA89D6E9CC3BD7AC7ULL,
    0xAE3B9F22104A1166ULL,
    0x95C801A3F0684644ULL,
    0x64,
    0x87,
    0xBF,
    0x67,
    0x18,
    0x22,
    0x2C,
    0xC1
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseHSalts = {
    {
        {
            0xD9E08BE266250806ULL, 0x052E8C753C86DA3FULL, 0x918E9FB81E08E8C2ULL, 0x223575B66C061B32ULL, 
            0x3E0455997CC2136AULL, 0xB104A4C9BA61C51FULL, 0xD0BD73669011ECEDULL, 0x3B93D5754BB2F00CULL, 
            0x099AE0BD14062409ULL, 0x10A31F51589711A3ULL, 0x636023F93240EE32ULL, 0xDA5CD451F44A0767ULL, 
            0x0C461EC747808BF2ULL, 0x535299C230399826ULL, 0x17C0957FB64EB695ULL, 0xC72D6B48181A198DULL, 
            0xA6899C07E49A3037ULL, 0xD55770A50080B851ULL, 0x5B392DDC52D5017EULL, 0x6B49494CC442E36BULL, 
            0x4F4C95EE645A60E1ULL, 0xBAC245E9A94660DBULL, 0x0308B11AA5E2BF8AULL, 0x6E436D5D8A947EE6ULL, 
            0xD33D8026E98EF257ULL, 0xC350DD0A648FE47CULL, 0xB11CCC8676FD7E7EULL, 0x0089FE774CE5DAFDULL, 
            0xE25494DA6D1121F1ULL, 0x8FDCA4500646423AULL, 0x99571C08247D1B12ULL, 0x84947FF4CE2CBBB7ULL
        },
        {
            0x20A213A8C70228C0ULL, 0x59B6B2135E7C7353ULL, 0xE1CE451AF4FE0A0CULL, 0x1CEA0E53ED9C6B37ULL, 
            0xBCF4B223E78C0A42ULL, 0x9E5199DD804611E1ULL, 0x1A2366F545B667FFULL, 0x11345DB4A0207FE1ULL, 
            0xFEBAD7804CE31845ULL, 0xAA2EB8444B454722ULL, 0xAD3FCDDE7F675872ULL, 0x271D20E87A6BE77EULL, 
            0xC4AC425FE41EE272ULL, 0x6D0097D1D7D0E31AULL, 0x7873B57499AF00D8ULL, 0x7EADE28A3EF5F9E5ULL, 
            0xEEF3F231E994539CULL, 0xC250ED7BA2C40EE3ULL, 0x6DAEEE4E6430C595ULL, 0x6255B6978147BC01ULL, 
            0x5174296B6230C8F9ULL, 0x36DD4DB5031B1D79ULL, 0x55CCBD9A61A90BAFULL, 0x84CD2E2E29AE95B4ULL, 
            0xE51ACFE011379CD8ULL, 0x842B2D56B104B849ULL, 0xD6A0545CBF56B302ULL, 0x7EFA8985CD974F90ULL, 
            0x8372CA72F437FE78ULL, 0x54FE817830D7833AULL, 0x04EB7C4E85E0FB37ULL, 0xCA094882C6153010ULL
        },
        {
            0xA535D772FD8135E0ULL, 0x32B73646AED8C1DBULL, 0x367992D622F523F8ULL, 0x2E1A07380309C0C4ULL, 
            0xDCC7FCA5C59BBBF6ULL, 0x83777D39C6999543ULL, 0x460B1B18C889E7AFULL, 0x26B23E205ED9D09DULL, 
            0xE6864CDC4B2AE7E4ULL, 0x0BA5E8C505B3616DULL, 0x37B30696DD9E6689ULL, 0xA6AD293FE9A73794ULL, 
            0xB2E98DB743BBCE15ULL, 0x2630931FAFE25D38ULL, 0x9AB0E331E6CB8065ULL, 0xA1CA9700E601617DULL, 
            0x51359722AD003095ULL, 0x9682FB5EB824594EULL, 0x99606ECF45F212C5ULL, 0xC1A25BF2C8569CB8ULL, 
            0x7E29F1ADDC7F4D1EULL, 0xA77134B549DB15FFULL, 0xF54DDA6345D94F28ULL, 0xA33659F25669A8F7ULL, 
            0x865743961D0032D7ULL, 0x6F25010693026C57ULL, 0x94A71CA1F8BC7E38ULL, 0x8C99F78B728FF36CULL, 
            0x92F8B9534CA82854ULL, 0xDF12EA2D758C6EC8ULL, 0x2913F3F682FF2EADULL, 0x000D4E943491C828ULL
        },
        {
            0xC5873F3EDD48FC37ULL, 0xB769C4D1566B1F13ULL, 0x6C0E52FA2634C908ULL, 0xE74B1758A5EE44F8ULL, 
            0xF8554F60A3C12492ULL, 0x5BB2E4161252F01BULL, 0xBC4B0CD32492EF94ULL, 0x91BB03DA858FE2B0ULL, 
            0x331FF0D04A838B7FULL, 0x036035A14F8F6CE6ULL, 0xE41CCE76A4043EB6ULL, 0xBA745EE88DCEA78DULL, 
            0xC7DADBA9F4BB15DEULL, 0x09BE24A719C35C6EULL, 0xA2B25F68DA507D47ULL, 0x1B96BD55DB7A6B36ULL, 
            0xA118719633769A0BULL, 0x42CF3EFC324CFFB0ULL, 0x2DC7CA3A6B0F232FULL, 0xB63B1DE5EBD853A0ULL, 
            0xEC24117E4B6E188FULL, 0xC30131C0550D2D4DULL, 0x0941437AC56C8A40ULL, 0x80E8E6EF1C00FBCFULL, 
            0x32D8EAE15D4A5F46ULL, 0x47E794519D9F433BULL, 0xB2DBD883499858A8ULL, 0xDE02F423BB6184E2ULL, 
            0x58D9C665F7C9F354ULL, 0x5D929801677C4AFAULL, 0x4F59BD1E4A8DD26DULL, 0x79A3B6197F0376B8ULL
        },
        {
            0x224CFF9663CB7956ULL, 0x39AAFBF65D1DF3D6ULL, 0x9A6303071B139AEFULL, 0xD2795D2AFC49DF1CULL, 
            0x289F40492CF30871ULL, 0x1BABA1EBA3ABB8FCULL, 0xFA5A57435F227731ULL, 0xEFC6CE9D81A652AFULL, 
            0x7D55718879F06C59ULL, 0xF43B4C26C8164C0BULL, 0xF51C1EC34537D891ULL, 0x1452CE05411B57D7ULL, 
            0x1A1BE5A807012255ULL, 0xE9D61BE9903F821CULL, 0x1703EB0FBA376D8EULL, 0xF920A97692A4AA62ULL, 
            0x16C78511AAFCAD76ULL, 0x357913EB0DE1A7D6ULL, 0x6B2AAAC7D5104BF7ULL, 0x30FCC89B7E17C475ULL, 
            0x906CFFBD0F9F26FFULL, 0x632561E9DA1562D9ULL, 0xFEDA1AD0A6760888ULL, 0x0F54CACE13BF6390ULL, 
            0xA3B058E7D942FD67ULL, 0x61892737364033D1ULL, 0x750B0C99BF0F4084ULL, 0x1B19DEDAD175C99EULL, 
            0x32262FB07F78642AULL, 0xB3144FB5BF476C34ULL, 0x21B81C557C443A2DULL, 0xB16DD31D3901EB86ULL
        },
        {
            0xC73EDC033E0F2518ULL, 0x6AAEA07FA80C1D31ULL, 0xD3BECA0CB060D424ULL, 0x414DE94BFF759A75ULL, 
            0xFCB00E671B00D9A9ULL, 0x78627C8390C82C9FULL, 0xE85B73298AD493C4ULL, 0xC396921BEDB45879ULL, 
            0xD50ED89A30829BD8ULL, 0x174D020B1006910FULL, 0xDD97F05CEF1C74B4ULL, 0xE0E711ED6E383185ULL, 
            0x49BEF270EDD2ADE4ULL, 0x44CEBD20EEB12A1EULL, 0x5BB77D2F5DC82559ULL, 0xD3E6FC892BBF2903ULL, 
            0xC3583A97BB5A0CC5ULL, 0xDC4CEFB723175D42ULL, 0x24094989A06C0585ULL, 0x89D06784E7D40149ULL, 
            0xC4FB12F98983FF2FULL, 0xB078D15F3B4A5A9CULL, 0x35979CAE4D89FCF8ULL, 0x91FFD4605DC38730ULL, 
            0x4280F870E4BC2C31ULL, 0x55D11B19B91BED01ULL, 0x808A8B238DFA9531ULL, 0x59FF83812483B27DULL, 
            0x63BF2ED8874FD383ULL, 0x53D2620E837944A6ULL, 0x4B081B1C6F27EE36ULL, 0xEE8FF88BA6D3C3E9ULL
        }
    },
    {
        {
            0x7F3AADF2AFC88314ULL, 0xB45CEAC7471516EBULL, 0x1BA8A1DD835F1C56ULL, 0x3A7F7F21DEDD018EULL, 
            0x04FC77E110232575ULL, 0xA44D85C89CEB24C0ULL, 0x69DE5191209D4D3FULL, 0x0E72A4B7E9EF335FULL, 
            0xD14D2631E4AA9EC1ULL, 0xE3C26C1AD776FADFULL, 0x540C10B000F1DCF8ULL, 0xF03187439358267DULL, 
            0x8EF2A081E5783D67ULL, 0x8CF869EE7E0D960AULL, 0x6FC1C6D1AF964A7CULL, 0x2CCD27AC3F3D4B35ULL, 
            0x19C8809806229558ULL, 0x71031721B1B86D0AULL, 0x9B65410223C1EC08ULL, 0xD4831984FA023890ULL, 
            0x33DCC7D83D270D71ULL, 0x5960CDCEAC554D27ULL, 0xDAC56DE01D27FD1CULL, 0x76F067188AD489EFULL, 
            0x551FE5C8AAF945AEULL, 0x87F09AC10305EB09ULL, 0x35FAB98E1A8260F1ULL, 0x55281CDC0A0460F2ULL, 
            0x66C093E84915215BULL, 0x66F1773AC73AF9B5ULL, 0x6EC0FB71D689C424ULL, 0x8EE25B4E2002BBC8ULL
        },
        {
            0x582CB2ED56426E23ULL, 0x16696154811303E8ULL, 0x988459111FF25BECULL, 0xDAE434FF01EB4F72ULL, 
            0xEDC7F440EC0066DCULL, 0xD72FD4579E5175C5ULL, 0xC9C61219D52F6245ULL, 0x39C691B0279A13DDULL, 
            0x25649F576F1CBF92ULL, 0xAC2C15720FC05397ULL, 0x9D8DCA50598D1216ULL, 0x4BC8962960405C3BULL, 
            0x1C625E468666C6E3ULL, 0xEBB43533B8D7D358ULL, 0xB349CDF4E35A8AB0ULL, 0xC57188F48D1E24D4ULL, 
            0xB3388BDFDED6A644ULL, 0x1CAED2ACEC28F1D6ULL, 0x8BE3884AB0E1F928ULL, 0xEABE9A88214D513BULL, 
            0x8A22D6084DF81FFEULL, 0xF45671BE39EC6ED5ULL, 0xC898ED1F7547B64EULL, 0x65DE22565F88FDD3ULL, 
            0x07069820E548AAC2ULL, 0xAC91773751D5DC23ULL, 0xAB1748E7A07FA63FULL, 0x3573821C99FFB669ULL, 
            0xEF0D586CBAA29255ULL, 0xDB232F6D29FB7A57ULL, 0x81846F10D334CB63ULL, 0xA4818F5F529D8044ULL
        },
        {
            0x9B270BD2BB1FEF8BULL, 0x4ABEE1333B244904ULL, 0x0E41AA4A5B028C32ULL, 0x8BA9F66297B92BA9ULL, 
            0x9E98A2B248A203FFULL, 0x506EB0919A78395FULL, 0x348BD4D4FA50F368ULL, 0xA607D82876F5D60EULL, 
            0xFDA10D8736ADFCF7ULL, 0x434DB31F7E968E19ULL, 0xC2A2874548CA792FULL, 0xAB7739BE0F742079ULL, 
            0x2E07131002D4F11EULL, 0xAFA50148543FAE11ULL, 0x655CA89F26FF3E7AULL, 0x505264DC936506A5ULL, 
            0xC5E08573DCACD5CEULL, 0x50E04F69D6196B90ULL, 0xA67D0B7FECE96526ULL, 0x0BB44AC6379D83EBULL, 
            0x1E5A8568CFC3B59DULL, 0xC96FE453B079EE18ULL, 0xDC6DF12FEF642D8FULL, 0xECAC94F58CB10B7AULL, 
            0x429F7B67E0312BD6ULL, 0x431754C08A8AB3D1ULL, 0x2BAE46E34AE4966DULL, 0x20EDBE060BCFE1F5ULL, 
            0x006932DBD2C5AA61ULL, 0x67A16889B58B0E3AULL, 0x09BACA3ED9465F03ULL, 0x79438169BF9EDFEAULL
        },
        {
            0xDA32BD7EE68199D6ULL, 0x5EEE005D845A27F1ULL, 0x5B9E68806FBA8A62ULL, 0x1114A2BA43E15D72ULL, 
            0xFD7F405083626B98ULL, 0x15B7CA3B3ECEFBDCULL, 0x824E60DBB7606DC7ULL, 0x70AC2FA81A0BC94FULL, 
            0x343BCE4FC9483270ULL, 0x2291320FD349930BULL, 0x9B9102F91A138C07ULL, 0xEC9C69742AB66E6AULL, 
            0x216329C448E906D3ULL, 0xC75A54822E861379ULL, 0xF8C7CD6ECD20A9DCULL, 0xE98CEDA933AC96ACULL, 
            0x7DCBE54FE010DB9AULL, 0x6802FEB42433F5B5ULL, 0x3400315A7B103BE9ULL, 0x8B6EE93756475790ULL, 
            0x792ADA601F44A31EULL, 0xBE0BFAB75FF2BC52ULL, 0x40EA2F04BC290418ULL, 0xBE912233B3D6A0FFULL, 
            0x1733AB238E1799B5ULL, 0x44672777D522EA0FULL, 0xA8BC8A2E48F50891ULL, 0x4F7BA641BBEC9854ULL, 
            0xC6A8D3CC677D081AULL, 0x9F9FFE9005B4FD16ULL, 0xDE6084EAFBF5042EULL, 0x54657DCE5DA847C2ULL
        },
        {
            0xC38B8660C2678690ULL, 0x7111486F7116E849ULL, 0xA4B75BE7378E73CEULL, 0xC5455967BEFAFC27ULL, 
            0x93D1E2D68CD3E9A5ULL, 0x7F1025A97FCF703EULL, 0x9D949A99CB1E3628ULL, 0x1956AEA6AE17DAD4ULL, 
            0xAED93618F1A1C912ULL, 0xCD9BF779271BA5B2ULL, 0x40932A97FF503922ULL, 0x05B02A114B6B369FULL, 
            0x9B35F3DBEAD547B5ULL, 0xAF23671B389E45C0ULL, 0xF5E30EF9B14BD085ULL, 0xA97A3C57D14B63F0ULL, 
            0x51587EF16A69D7FBULL, 0x09CF0D1F6FB00A4DULL, 0x531CEDEA47C22D92ULL, 0xF706B8ED1A37136EULL, 
            0x8BFA6E67BC1C2DF6ULL, 0x89F16A6B1814B978ULL, 0x87627ED13A052145ULL, 0xA6D82DC5F4408D5AULL, 
            0xD5DF15390F6019E9ULL, 0x632D6228BD94A057ULL, 0x067368A66BF152A6ULL, 0xAB45B5865CDB43FDULL, 
            0xA39FF30965516AFEULL, 0x473F1E2B7DEAE688ULL, 0x9A35BAEF5662973DULL, 0x731B2253496229C1ULL
        },
        {
            0xA42D0AD957C1CA78ULL, 0x2A4237A9438FC683ULL, 0x8E53571F83794E66ULL, 0xE22458482FE3D9ECULL, 
            0x22CA5B346F48C34FULL, 0xD42978C78C477D7EULL, 0xC0D2C14F96BD1B06ULL, 0x971334F8C03320BFULL, 
            0xAAA4FBEEBE7355E2ULL, 0x06D9DFCE34EBB360ULL, 0xEA156B44086DAD19ULL, 0xA2BA9F448ED086C5ULL, 
            0x494CCA30D4AFA411ULL, 0x5DD5192397EB656BULL, 0xA13B0F206CFBEC7EULL, 0x2375FB9772084FB7ULL, 
            0xAD4B8D0EC35F5644ULL, 0x32A1FF120CE619F1ULL, 0x15DC55AB666E65ADULL, 0x78B6A6466D68FC51ULL, 
            0x210283334FA763D3ULL, 0x7EEBB9C6D9689CE0ULL, 0x93D9569EB3F10024ULL, 0xF83A04466F360052ULL, 
            0x9BD24A42368F6E6AULL, 0x9B5A1ED375D52578ULL, 0xD0DC7C57E8BD9FA5ULL, 0xE70E5E3E82970E41ULL, 
            0x4CD9F4E0B30E20A6ULL, 0xB070D13598E94805ULL, 0x63FF35B6ECEFF841ULL, 0xBF5A830E83ADEABFULL
        }
    },
    {
        {
            0xEB9C33A4A62E42DDULL, 0x87CDAD9E73192FA6ULL, 0xA7085E552E39D3E3ULL, 0x3C4714459518D33FULL, 
            0x91A88AA969472F66ULL, 0x6BD433747D217377ULL, 0xA13CF9D32215FB20ULL, 0x5A6A1EB86EB5CEFCULL, 
            0xE61AF66E65265E79ULL, 0xD20C9E18BB20AFBCULL, 0x91BA4F8107E3AE63ULL, 0xEB3B945749E2DF0EULL, 
            0xBA32D52C472A0023ULL, 0xB8A85645A1E0F565ULL, 0x27FD0D4E394C3D95ULL, 0x2478650674BA1B44ULL, 
            0xA52F42D1060FC4F4ULL, 0xBE065AA9BE193FACULL, 0x424C9DFE43484AA5ULL, 0xBD1BFD7851E51EB5ULL, 
            0xE4E54B7C9C592F2EULL, 0x89CFA4986BE139DCULL, 0x80F09104F5B9BEFCULL, 0x152723B203C4490AULL, 
            0xBAC7EF3512E91DD3ULL, 0xFE3C2AD876CE9456ULL, 0x54D9DC86AD7F5B3AULL, 0x170D8A9134422E5EULL, 
            0xE1636C550D690CF0ULL, 0x099D80F77ABF7033ULL, 0x56E2E15CD8055032ULL, 0xDA5FAF57C90DE101ULL
        },
        {
            0x23E86A9DC3BE8C7BULL, 0x09A839E7F058DE58ULL, 0xCBD692AAB3250A37ULL, 0x535141885AF2DDA2ULL, 
            0x81EC5E198ABAF93DULL, 0x3D55F18943A5078DULL, 0xEED030A92A56A4BAULL, 0xCD77C9E57C51FC2AULL, 
            0xC768018409EB44D1ULL, 0xC62DA55093FC17A6ULL, 0x18008F6F27A9B77CULL, 0x828FB88F22C7C865ULL, 
            0xAFFFC658EDDC230FULL, 0x42658714705D04BFULL, 0x620CB4EABFD90A47ULL, 0x2559EBD26C7F747FULL, 
            0xEA6AF76D749D9840ULL, 0x7CC26A2E763E6704ULL, 0x5BBF326ECD71B960ULL, 0x9BADE759D0E8FC92ULL, 
            0xF44A479EA1C20DE1ULL, 0xBB29A2589A34310CULL, 0x8A51B3D8E2B06354ULL, 0x7FBEB962CA5CFA48ULL, 
            0x6F42C4CAF87860FDULL, 0x0095576BA1D1AA62ULL, 0x74CCB994A5C55FB1ULL, 0xE12189EDA66A174EULL, 
            0xB4DE4284A3041690ULL, 0x7FBFFFACEFD40242ULL, 0x8DFC942F620756AAULL, 0x7126AE0613F78E96ULL
        },
        {
            0xD25CF9D1D0D72DCDULL, 0x2C47A718D10244EEULL, 0x799C715FA250B21DULL, 0x38A9B2A6BB2D9064ULL, 
            0xDBCAC957F3B9111AULL, 0xF54B24909F80A1B9ULL, 0xA7D9356DA407C0F0ULL, 0xC3AA790025875EECULL, 
            0x2E0D3AF63AA7B76AULL, 0xF7A3D7CB47E61A7BULL, 0xEF64705DBFBD45A0ULL, 0x367116B8F64EB82FULL, 
            0x807825AFEA6B4828ULL, 0x423D42222F3E0C04ULL, 0x431A34B82E8A6A23ULL, 0xEA01CF32C3A0133DULL, 
            0xB00AC3FBF0AEEEC5ULL, 0x28A5417B7E0A5C54ULL, 0xC7CF962EC694DFB8ULL, 0x99E39B71046D2FECULL, 
            0xED0F178B0628AF00ULL, 0x2B455DCD9B121A95ULL, 0xAD76161669CD213CULL, 0xAF2E325DFD655905ULL, 
            0xF475A3DB0CACBA3EULL, 0x08FFA3B5F4975BFBULL, 0x9D4E5508B72DAC6EULL, 0xA373FD6DEF3828EAULL, 
            0x1AF45FE3E86F4190ULL, 0x924D0408E599DAF5ULL, 0xD45DD8FD382920EFULL, 0x4A8B5F41CE5732CDULL
        },
        {
            0x47998A1C6415969AULL, 0x26E88314D2B76DFCULL, 0x68A74BA70E65287DULL, 0xEDB0E1D1AE131E1CULL, 
            0x9304500561D33399ULL, 0xC62FBA04916B6714ULL, 0xCC32F370B5DAA7EAULL, 0x1C0F7BA05BE042E4ULL, 
            0x26DC24FC35034476ULL, 0x6645E0D5C18969BDULL, 0xBC30EEFC0CBCFC96ULL, 0x3346C41CC6BAEBA8ULL, 
            0x9BE548AA44A02937ULL, 0x2AFA0E3F711C9961ULL, 0x6F1604DBA4D814E0ULL, 0xBE3706789AFAD04AULL, 
            0x3EB0C76AE62C4277ULL, 0x261EED48313F8EE5ULL, 0x6482F90D1DEBEB60ULL, 0xF1445A5513534971ULL, 
            0xFFAB2F11165DEFEDULL, 0x8AA61F767BDEAE27ULL, 0xF29F34B81850E8B4ULL, 0xCD1690973F2D7A87ULL, 
            0xC1C97F7B624C48BEULL, 0xC06BFAB55975F439ULL, 0x3147964204D0E7E0ULL, 0xBFEA3F9DDDE1892EULL, 
            0xE4C2E2312641EADCULL, 0x43CE1671C986B177ULL, 0xED3DD60B7F041FAAULL, 0xE247E4148AF020E0ULL
        },
        {
            0x273631FC56AEBBFAULL, 0x6BC1DD06E87966D2ULL, 0x7D5E690C4E9EFD7BULL, 0x1636BE19C1860A19ULL, 
            0x413F7BDDA37C0203ULL, 0x967716F372BBA5E2ULL, 0x6686632C1B0F1BC2ULL, 0x7837E16FB91293BBULL, 
            0xE41E89DF83F6A2EBULL, 0x69B8F551E105E828ULL, 0x76F56BA5A1E56B71ULL, 0x6079BCB6FD939DADULL, 
            0xE64D90BDFDF254CFULL, 0x6B0CC2C345023DDEULL, 0xCD29BACF3F42AAAAULL, 0x440CB3CF08AA9152ULL, 
            0x90B32358BB58ECA8ULL, 0x2567CF1FDFA65DCEULL, 0x0F33A59464CBCEEAULL, 0xAA05E0A4D57D730CULL, 
            0xFA22EF5AAEDE8D3FULL, 0xCBBC88F95F290FF1ULL, 0x918CE728A4258E4EULL, 0xF1BDE84CC2897DC6ULL, 
            0xF8B69E9FB2F26C7EULL, 0x7B5B521A35AFEF50ULL, 0x8ABB66E8F9E244CDULL, 0xC389A042F42D4F2DULL, 
            0xAB79356827D854B7ULL, 0x7EE8C2E8D5BF059EULL, 0x3FB2A47F4D7EEFC8ULL, 0xC9A611CA2009E3B2ULL
        },
        {
            0x6379B8ABC9474966ULL, 0x6B25DE4FAF211AD9ULL, 0x8CC845B48B56E700ULL, 0xD9C1A2FCE37FF095ULL, 
            0x410177A948F5B663ULL, 0x80A02460BF3A6D11ULL, 0x68330A5401D608FEULL, 0x4C3A617343945055ULL, 
            0xA39ECCD5508888FEULL, 0xA29A096539E69687ULL, 0xDDD6B74030D64A70ULL, 0xB3AB85E9E194A079ULL, 
            0xC7C77E4713941B6AULL, 0x43C45CBFCAB89713ULL, 0x1EB2BC8F1BF47F93ULL, 0x0C122A745DD1C051ULL, 
            0xB81F11FAB299B01FULL, 0xEF337EB7028E95FEULL, 0xC1C6CE789B15E669ULL, 0x0E4F00C09F8A2350ULL, 
            0x5D929D23A0E6C547ULL, 0x93B4ADEA4C68C1D8ULL, 0x61B4AB06BB4F198FULL, 0x2169773662105C4EULL, 
            0x4C10AEF37D63F543ULL, 0x0E8936487143CB6BULL, 0xFA78103CE9790328ULL, 0xE0B7A4BE9143E247ULL, 
            0x9229DE6F0DB9C452ULL, 0xD5177B7DA979B3D3ULL, 0xF6A31F17FCE1608BULL, 0x38B0D0C04797BD7DULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseHConstants = {
    0x8609589AA83F2AFCULL,
    0x055C6B9B3F49CF24ULL,
    0x34E41DA819F9D00CULL,
    0x8609589AA83F2AFCULL,
    0x055C6B9B3F49CF24ULL,
    0x34E41DA819F9D00CULL,
    0xF41C98E4E054C900ULL,
    0x2AA8224DEDF2E9B3ULL,
    0xF6,
    0x72,
    0x4E,
    0x22,
    0x07,
    0xEB,
    0x91,
    0x22
};

