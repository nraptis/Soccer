#include "TwistExpander_Badminton.hpp"
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

TwistExpander_Badminton::TwistExpander_Badminton()
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

void TwistExpander_Badminton::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 15432906377719276656U;
        aCarry = 9614830725078539207U;
        aWandererA = 14587173142337475070U;
        aWandererB = 15807999938120101508U;
        aWandererC = 15753890984835293733U;
        aWandererD = 15375768083946425620U;
        aWandererE = 17932756937817813351U;
        aWandererF = 18105759905490751884U;
        aWandererG = 11657266513297610582U;
        aWandererH = 10437562689024693183U;
        aWandererI = 15652200357193784972U;
        aWandererJ = 17939241976499852401U;
        aWandererK = 15731612142466027308U;
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
    TwistExpander_Badminton_Arx aArx;
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
    TwistExpander_Badminton_Arx aKDF_A_BArx;
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
    TwistExpander_Badminton_Arx aKDF_A_CArx;
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
    TwistExpander_Badminton_Arx aKDF_A_DArx;
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

void TwistExpander_Badminton::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 16421006504435365586U;
        aCarry = 13941935906622304079U;
        aWandererA = 11540773304613810496U;
        aWandererB = 17661258218920724827U;
        aWandererC = 11123541022291594908U;
        aWandererD = 13752766116377818365U;
        aWandererE = 17082243391187258876U;
        aWandererF = 15031169115806539792U;
        aWandererG = 16395072167649030759U;
        aWandererH = 18102251230073779688U;
        aWandererI = 11884574741369416261U;
        aWandererJ = 10387571738839339976U;
        aWandererK = 9744651770855215249U;
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
    TwistExpander_Badminton_Arx aKDF_B_AArx;
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
    TwistExpander_Badminton_Arx aKDF_B_BArx;
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
    TwistExpander_Badminton_Arx aKDF_B_CArx;
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

void TwistExpander_Badminton::Seed(TwistWorkSpace *pWorkSpace,
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
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD);
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
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD);
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneG);
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
    TwistExpander_Badminton_Arx aSeed_AArx;
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
    TwistExpander_Badminton_Arx aSeed_BArx;
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
    TwistExpander_Badminton_Arx aSeed_CArx;
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
    TwistExpander_Badminton_Arx aSeed_DArx;
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
    TwistExpander_Badminton_Arx aSeed_EArx;
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
    TwistExpander_Badminton_Arx aSeed_FArx;
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
    TwistExpander_Badminton_Arx aSeed_GArx;
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
    TwistExpander_Badminton_Arx aGrow_AArx;
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
    TwistExpander_Badminton_Arx aGrow_BArx;
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

void TwistExpander_Badminton::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Badminton::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 12529378473255848549U;
        aCarry = 14095695928969333528U;
        aWandererA = 11247778430862407002U;
        aWandererB = 9468713667003038092U;
        aWandererC = 12262140022161298435U;
        aWandererD = 13639038695808027969U;
        aWandererE = 9243957571152486241U;
        aWandererF = 16141310603406820314U;
        aWandererG = 17394432079855155270U;
        aWandererH = 15912636437482593729U;
        aWandererI = 14482232315748240772U;
        aWandererJ = 13042611125201452148U;
        aWandererK = 9875149680072451043U;
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
    TwistExpander_Badminton_Arx aTwist_AArx;
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
    TwistExpander_Badminton_Arx aTwist_BArx;
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
    TwistExpander_Badminton_Arx aTwist_CArx;
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
    TwistExpander_Badminton_Arx aTwist_DArx;
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
        TwistExpander_Badminton_Arx aGrow_AArx;
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
        TwistExpander_Badminton_Arx aGrow_BArx;
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

void TwistExpander_Badminton::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 1, 2 with offsets 5110U, 1080U, 5412U, 5093U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5110U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1080U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5412U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5093U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 3, 0 with offsets 1809U, 1161U, 1062U, 2346U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1809U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1161U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1062U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2346U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 2, 3 with offsets 7267U, 564U, 6513U, 7609U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7267U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 564U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6513U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7609U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 0, 1 with offsets 5306U, 6048U, 3886U, 5970U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5306U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6048U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3886U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5970U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 3, 0 with offsets 1140U, 622U, 1169U, 817U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1140U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 622U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1169U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 817U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 2, 3, 1 with offsets 1585U, 1959U, 1176U, 1666U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1585U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1959U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1176U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1666U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 2, 0, 3 with offsets 178U, 563U, 1876U, 1993U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 178U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 563U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1876U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1993U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 3, 0, 1 with offsets 1048U, 523U, 781U, 85U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1048U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 523U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 781U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 85U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 223U, 336U, 706U, 128U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 223U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 336U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 706U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 128U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Badminton::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 3 with offsets 4283U, 1055U, 8085U, 727U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4283U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1055U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8085U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 727U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 3, 2 with offsets 3107U, 3666U, 2397U, 1620U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3107U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3666U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2397U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1620U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 2, 1 with offsets 3929U, 2747U, 1696U, 1975U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3929U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2747U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1696U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1975U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 1, 0 with offsets 1624U, 2439U, 249U, 2023U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1624U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2439U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 249U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2023U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4903U, 2555U, 2788U, 960U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4903U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 2555U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2788U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 960U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 100U, 915U, 48U, 692U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 100U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 915U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 692U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1386U, 1988U, 1920U, 490U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1386U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1988U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1920U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 490U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 862U, 1487U, 980U, 116U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 862U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1487U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 980U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 116U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 753U, 1603U, 1697U, 1550U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 753U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1603U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1697U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1550U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 1, 0 [0..<W_KEY]
        // offsets: 588U, 1966U, 832U, 781U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1966U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 832U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 781U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseASalts = {
    {
        {
            0x231D9223BD0A268CULL, 0xA9DBFBAFEB4CEF6CULL, 0xD689CCE685ADDA1DULL, 0xF6FC144C16AE33FAULL, 
            0x471B5C9CB9899EB4ULL, 0xF6CA174F135FDE68ULL, 0x0B2DBEDE1247893FULL, 0xFB492E1C274523A9ULL, 
            0x9D438380E7863AB0ULL, 0x8CDCDD18B679AA33ULL, 0x7ACC7CFAB645F3F6ULL, 0x183894655772E59EULL, 
            0xA506D472E33E4944ULL, 0x974FBBBCAD077A4DULL, 0xEEFF3154674C77F0ULL, 0xBA6BA493FA727F43ULL, 
            0x3352358A375ECC19ULL, 0xCCB6B1C384154EFBULL, 0xE7F2287F1FB74C90ULL, 0x2BCB475D521E8103ULL, 
            0xF80DE9FDD235C2C1ULL, 0x8323FC822349B638ULL, 0x577A14387A905DF2ULL, 0x7B0D851840595588ULL, 
            0x5082941056889F16ULL, 0x757B2E96114F954FULL, 0x5660B2C4B9460C7DULL, 0x18CE4A4164F81946ULL, 
            0x4DB661C7DE1210B5ULL, 0x1AA9D2F9105E316DULL, 0x80B71D09284D1BF8ULL, 0x4648758733EAE425ULL
        },
        {
            0xF5E013BA9988D176ULL, 0x1E5E51543FE6C4B8ULL, 0xED8DB20C971B3239ULL, 0x360ACFD0B413A3DAULL, 
            0x7BF1B3E35DD866D3ULL, 0x9711123AD1D5A7CAULL, 0xBFC58484B7D6F589ULL, 0xD31C4C8AB2130128ULL, 
            0xB2BE974771E66829ULL, 0x04B22C0B4471F7B5ULL, 0x6DA3E9FEBE810D92ULL, 0xA531B741BD2FC86EULL, 
            0x0CA8D7DC7A337E37ULL, 0xA7BB61B2EBAE420BULL, 0x5902771746B8CF85ULL, 0x137D28F1E2394E55ULL, 
            0x4526D744F287FAF2ULL, 0xEF23DC150B802EE0ULL, 0x422AC59EC8CA1BC7ULL, 0x0F7CD909CF4FC663ULL, 
            0x3993A309D01B2E85ULL, 0xB1BFB70155551DA4ULL, 0x0E841BA52B8E2F9CULL, 0xEFF7263D1014D64FULL, 
            0x9A6A50801DF93995ULL, 0x88037D51F7506E33ULL, 0x483A23F19E2E77EFULL, 0x99DDF809FB38990EULL, 
            0xAD28D97BD8229A2FULL, 0xFC3914982BCD399EULL, 0x50A4454DB32766C2ULL, 0xC8E671A133A1EFDCULL
        },
        {
            0x9E687F61570E5169ULL, 0x35242D1BFA6FD275ULL, 0x2DEEC60FDE086E40ULL, 0x30CDACCC76A487C0ULL, 
            0x3650698DF1523BF7ULL, 0x1131D099C85D4D4AULL, 0xE3E47BE8D9B1F27DULL, 0x2AEAB52CD81FFF81ULL, 
            0x32C20B40D9950C73ULL, 0x5D1E351B916BB51EULL, 0xA4B0BCAC3C600CE7ULL, 0x3F71031809441434ULL, 
            0xF1EFF56F1E568F35ULL, 0x6B3D3B1F00BFA071ULL, 0xD303605D1BE9D091ULL, 0x6F37B42B9F57B3D4ULL, 
            0x0082F7D33B56C640ULL, 0x07B59B6C34280245ULL, 0xAC4509DFACBDE68EULL, 0x4B9B58A645161D36ULL, 
            0xDE30C50191740B91ULL, 0x7915B16446CC3F46ULL, 0xD18ABE68BA0D077AULL, 0xEB2236CBC12E682CULL, 
            0x5EDAD13DF7366119ULL, 0xE6FD3379CB96544EULL, 0x8236AC83D3C103EEULL, 0xF14E4734A9624487ULL, 
            0x54D6699749A266CCULL, 0x9FF6BFACD9AF71A6ULL, 0x56D50752B14FBECDULL, 0x680CF7AE971DE5FFULL
        },
        {
            0x4A9CB532B11C0159ULL, 0xB761560FAFB8D869ULL, 0xE528EC1636E47080ULL, 0xC4FF759F5DD409B9ULL, 
            0x3918C3A389AC2151ULL, 0xA19CF13947C4691FULL, 0x7CED99AF2C22AF2CULL, 0x26B145969A78E260ULL, 
            0x514F8932F2361263ULL, 0x8E5109A0C5F77779ULL, 0x4610C1CE68173512ULL, 0x052E62FBA2B53E9CULL, 
            0xE95107BC5F3B2077ULL, 0x358887FBBCD8ECF7ULL, 0x8EE84930531D00A2ULL, 0x72D236A607AD2828ULL, 
            0xD09DD27460D33505ULL, 0xCE06150A7D8FC4F6ULL, 0x1AD602FACD4836C2ULL, 0xB9FB21CA621DEE11ULL, 
            0xBEB86C4B35F77BF4ULL, 0xD00C20FE47F92F88ULL, 0x8ECDBEAF4D692465ULL, 0x5C1B5B03EDDF7669ULL, 
            0x79B904A58D32341BULL, 0x470A575840BCEE1EULL, 0x48CD4BD5FC0FB811ULL, 0x7D388564E71B0028ULL, 
            0xBC9C68BFAC6AC20BULL, 0x2E5AC55714286536ULL, 0x3E638F7E6E498DCBULL, 0xD6DDAA225E9BCE55ULL
        },
        {
            0x7C6D4967C1C9568FULL, 0xF39B6552B3906A5DULL, 0x74F4C83BEC29396AULL, 0x5572D2BF337DE94AULL, 
            0x285F1B75AB9C0818ULL, 0x5457B6546AE7A88DULL, 0x3AC13CEAA28D6212ULL, 0x7151D19B95CB196EULL, 
            0x3226444D6151927FULL, 0x5E3B28DBC94A7EB5ULL, 0xEC3A7EBE19B4AA94ULL, 0xD5DF9B70DE9B48B6ULL, 
            0x45CFD6995B49318CULL, 0xF6DA33433B06E6C9ULL, 0xCF69DD97E3792311ULL, 0xE6C4DACC9726ED1DULL, 
            0x287D30FF0EB4C74CULL, 0xCD98CEEFB563BEAEULL, 0x1FCEC47B8651819CULL, 0xCDC8A2CC787E428AULL, 
            0xCAD24EE40A184AE5ULL, 0xC8D86E9AFA7F5536ULL, 0x0BC767CBE968C92FULL, 0x0ACCEA14BA5E885FULL, 
            0x336DACA98C5AE903ULL, 0x6AD26793090D45DAULL, 0xC77C939747C5322CULL, 0xBFDC18DA27D41328ULL, 
            0x68783E75D69690B8ULL, 0x9C8B839FBD224D92ULL, 0x31055BF7BD8FD266ULL, 0x889C3B1236E97680ULL
        },
        {
            0xBD3D85FF5B7861E5ULL, 0x7BC2C237DA1B3F81ULL, 0x21D604573E755AC1ULL, 0x072B1E47F30269D9ULL, 
            0x503329F3ADC2921BULL, 0xE207AA6F21644A21ULL, 0x390C9F174E3EB21FULL, 0x5661FB5B1BF59E76ULL, 
            0xE50F1D2B471EE78DULL, 0x2F59F233644E6655ULL, 0x8A7FDF142C0E7A81ULL, 0x2AE9CEECC5358470ULL, 
            0x63F40453CE969538ULL, 0xBD6E3F77A4A14F72ULL, 0xA003888E6D7642F1ULL, 0xEF9C92F518C9879BULL, 
            0x9E1E6A8C7633E455ULL, 0x2949B0F3B5260739ULL, 0xD43C28E8A90460EAULL, 0xFC6C4FF2DD0F357AULL, 
            0x3D700B61C866D0BEULL, 0x865F806678439376ULL, 0x8ECB658DCAC3976DULL, 0x4A70267B8E5EB75CULL, 
            0xB78CC578945E0928ULL, 0x9FE252D6F5429E7BULL, 0x1AD9FF66F20133F5ULL, 0x033A2507492D3395ULL, 
            0x13354C8FA9FED711ULL, 0xF1494DAF6983A845ULL, 0x68B7FE33926F7909ULL, 0xAEEDB372CF660B4AULL
        }
    },
    {
        {
            0x572806E075DDF8E9ULL, 0x1B00230847B277CAULL, 0x9FB6A076878C8461ULL, 0x6671B083B2A4F667ULL, 
            0x8DDFB96114C171EFULL, 0xB24B5AEABC642DB8ULL, 0x8FA773F46440CCDAULL, 0x96871F39503A3847ULL, 
            0x223DD143DAF84912ULL, 0xD4E0A0E4BC7D34B1ULL, 0xB3C6A05A36085BE8ULL, 0x8A3D2A0233792E3DULL, 
            0x95C920AAEF82DA9EULL, 0xE56D83AB3AEAD93EULL, 0x705372592EB39B2DULL, 0xD57952E7198F5867ULL, 
            0xBB7D0E6AA2E9C25DULL, 0xD2F74591D36D055DULL, 0x980E6181CC4769A0ULL, 0x2A1EC3C53DB2177FULL, 
            0x6D60C506DAD40E80ULL, 0x66645597817D154AULL, 0x500EA4053846F9F7ULL, 0x79E4611431B37E92ULL, 
            0x65777416CBDB1503ULL, 0x6A5F7D6EBF93BC6DULL, 0x706D206723352F6EULL, 0x499A4BAEBEC74D15ULL, 
            0x850B724D4D97409EULL, 0x2CD5D7EF09B3B2F4ULL, 0xA357EF699D469C90ULL, 0xFB618E7B21C036EAULL
        },
        {
            0xCB4C7D9A918AA793ULL, 0x5EFA34FC292A3D05ULL, 0x2A067AF411C13827ULL, 0x0C6C2AF6A5F4B0B5ULL, 
            0x69BFB7E2D094C9EAULL, 0x7F5A00D0193A6AD7ULL, 0x0F341AF409980DF9ULL, 0xB608FDDD04DC5A60ULL, 
            0x63EB2D5FCEC0C718ULL, 0x8D47248A08721AA3ULL, 0x5D7F5AD87EA51DCFULL, 0xA3EFE00627F19251ULL, 
            0xCEEA85AB54EFF245ULL, 0x7D0DCEDFD5C653DDULL, 0xB159EF9988FBE0AAULL, 0x900A12D724A94A36ULL, 
            0x0011E4C24BD2F8C5ULL, 0x37E16958ABB31A13ULL, 0xCC59626876AA44E8ULL, 0x567ACDA66EA13B20ULL, 
            0x7993EDFB7C937650ULL, 0xA32ECEEEA9218CECULL, 0xECE02D10C0ACE4CCULL, 0xD6B58B11DF81DB77ULL, 
            0xFE8E2E6D9E13B53DULL, 0x396CE5F29AAA11B0ULL, 0x8D5997D199A01740ULL, 0xEF9F62CBD2995035ULL, 
            0x77CA2D37746C4165ULL, 0x501B84A05B801DB9ULL, 0x7A50DC82C29BF4EBULL, 0x5177FE379A62DBCDULL
        },
        {
            0xC41AC26032FB9650ULL, 0x022A2BF4EDF57C48ULL, 0x183D8D8DA7A2A04EULL, 0x7B32DCBC18C3746BULL, 
            0xD198BC243EF58B99ULL, 0x129554E9468AE8D6ULL, 0x4E5161BC8BC61EF5ULL, 0x13EBB16B6DECC22AULL, 
            0xF95987B89401A389ULL, 0xAD1C264033F58C94ULL, 0x121A0614C1F57BA5ULL, 0xA53488B72E651B37ULL, 
            0xAAB34F162D0C959FULL, 0xA96D2905BBAAA378ULL, 0x92F5718FD8B79DB8ULL, 0xFFC83458B61EBA19ULL, 
            0xA5B9DFC42980713BULL, 0xE483D18C9E470930ULL, 0xEDA69CE3701DDE24ULL, 0x11C6BB17FCE23F02ULL, 
            0x53433BFF5C985649ULL, 0x8639142052D66C47ULL, 0xE8F8AB3A3DFC9727ULL, 0xEFA7C2C0ABC128E4ULL, 
            0xAB53D66ACC7A31B4ULL, 0x2E99FAAEC60E52FAULL, 0xCABC2F30922A49A9ULL, 0x7C64B5220C5954D1ULL, 
            0xE7C514D51AD24E81ULL, 0x57F0F9466F0BBC7FULL, 0xF592DA36A205EC25ULL, 0x6F01FD8EB04C65ABULL
        },
        {
            0xD6D1E47B3C5DD05AULL, 0x2061F85836BF3E1DULL, 0x0847C9D75A023E0CULL, 0x04B8AF66CC875F22ULL, 
            0xF245C2639570EB2AULL, 0xE244EE8D7DDEF8E2ULL, 0xDCA21CE5A8215B52ULL, 0xF97F66E81B22A0E9ULL, 
            0x33E277E5C7AEFF8EULL, 0xEB324CDB1E4F9461ULL, 0x2A09B9F634B99835ULL, 0x405F6F1FAC865E7FULL, 
            0x9C03CE4AE9700C76ULL, 0x8B9DF91E19F50F8CULL, 0x9FF0DE05BF8C7AEEULL, 0xAD34564B6DF6564EULL, 
            0xD190ED3E7308824CULL, 0x9E7C39A877AEF902ULL, 0x0C7A8D8D6E082DF0ULL, 0xD9647DE94738C995ULL, 
            0x8A1C35B04D56A7EDULL, 0x6AC77D882F560AEDULL, 0x3DF7228F7D07C024ULL, 0x0AB3CC90BB8A4E87ULL, 
            0x74E5640080B1C038ULL, 0x90E088502F880725ULL, 0x79FBABEBECD799AEULL, 0x6BCA8ADC3694DDEFULL, 
            0xC3EC58932E93AD17ULL, 0xF440CBD68AF16A8DULL, 0x85FCB8EB886B945EULL, 0xB2EE1BD10BA675F1ULL
        },
        {
            0xA595CD58FD255A37ULL, 0xFECA5BC204146383ULL, 0xD5B40485E5043094ULL, 0xB840FDF913FB313CULL, 
            0xB831E1FE4E903741ULL, 0x19FD84A4BA455E5DULL, 0x0B1EE35225013985ULL, 0x518165584E2DE37DULL, 
            0xC710ECC9C6D1F2E3ULL, 0x68B9ED2757C48A83ULL, 0xD85ED9ADE52A690AULL, 0x33E82FB06738065EULL, 
            0xCF17AFF6D93CDA80ULL, 0x1434FA003263CD23ULL, 0x5F2509F486D91F4FULL, 0xA52C8ACDBBA0B279ULL, 
            0x6E10F0E36680FAE7ULL, 0x0DCBBA6741391C63ULL, 0x3B50855353D65EA6ULL, 0x4DEDC6787CFFE90EULL, 
            0x0B7D502C9ACA3A55ULL, 0x4BFA3B31C2223823ULL, 0x5FCF9050E70EB18CULL, 0x8974F21F1FE5F3ACULL, 
            0xC2C1A35AF6F2D12CULL, 0x096C84C30FD38461ULL, 0xA52521A72EA02426ULL, 0x98DD68E4B7D02FA2ULL, 
            0x4BE075EAC755A8CAULL, 0xF945D78CF38FB6FFULL, 0xEB3D530D3354B6DDULL, 0xD8E79F02496A9F2EULL
        },
        {
            0x2FD5BCF4E7077D56ULL, 0xBC05A54AB8FA36D4ULL, 0x249972C7EBF509D6ULL, 0xA7D4A5BD2A319DE1ULL, 
            0x842C728B3814CFFCULL, 0x305882114661D148ULL, 0x1530064718FA3479ULL, 0xB92AA4CD3CC09982ULL, 
            0xCEB27FF4AFA40448ULL, 0x36699604D5AB6A69ULL, 0xC65183B73070BB5AULL, 0x4C054A397BC5344BULL, 
            0x3B7557E46957FE0BULL, 0x7CF455B768664588ULL, 0xF99C53DDF25778E5ULL, 0x60B35411EC6EA04FULL, 
            0x8C53068E30BA9373ULL, 0x2F6D19C100489C59ULL, 0x4F74850F37A22410ULL, 0x07A23D76C9B42E36ULL, 
            0x8C91BF37ED8898F1ULL, 0x50E535C0C9B74C99ULL, 0x593B99182F5D6F50ULL, 0x76A8645D34A8990CULL, 
            0x3CDF68BBFB6696A7ULL, 0xD1A3AFB312DAAC09ULL, 0xA66EF2851D8186CBULL, 0xCF6716CC10438732ULL, 
            0x3A7346D0E499DD24ULL, 0x310D87209AD7B398ULL, 0xE0506D4312F28E86ULL, 0x7110BA20E033D060ULL
        }
    },
    {
        {
            0x32782C88787D002DULL, 0x3BB98C36B959A7C8ULL, 0xD19EF29BCC97EC2AULL, 0x4C15BCBD0FF4ECDEULL, 
            0x7E3C7D91A47220ABULL, 0x7DE6907A78A096F6ULL, 0x77AC70CA2EE2FEC2ULL, 0xEB88D69610D2983FULL, 
            0x82A7018E6FA06158ULL, 0x8796AD5E8D816D3CULL, 0xE9EA49039BA40EADULL, 0x58DCAEF89378325DULL, 
            0x8164C5A7DFE3B3F7ULL, 0x2B2EDC7BDCB77074ULL, 0x72AB2CB3BA28B6C1ULL, 0xDF313361FB02F7BFULL, 
            0xDE13CF5762AFFAB7ULL, 0xA4D478CABA41AF21ULL, 0x912E9E2316E058B7ULL, 0xEE0E060D968A0C4AULL, 
            0xB1F27748129AC87BULL, 0x92B26AC0D2AE8F5DULL, 0xAAB2631F441E8035ULL, 0x83EB81D23ECE1DD4ULL, 
            0xBA1B8323C025757DULL, 0xE9A62ECE8FEB2363ULL, 0xBCE32E9296F8613DULL, 0x1DF422651C6DDE68ULL, 
            0x9BA4C06A864FFE2AULL, 0xAC4223FC7D839B4FULL, 0xB32EEB0EC0352DCDULL, 0xC5A5DF72E6903FFDULL
        },
        {
            0x8EE76028DB0CC710ULL, 0x29EBAF8E7FBC529CULL, 0xA041769EBA926827ULL, 0x09707344B933833FULL, 
            0x7C1C0CB1F901C4B1ULL, 0x970F3A5AFCB23C7EULL, 0x8A9153B24B44F2ADULL, 0x878737D74C22EABBULL, 
            0xE322E3AC9403A8ADULL, 0x32692B14D56F9C6AULL, 0x8F7ED89FF04801F3ULL, 0xFD7B63E521C7AD62ULL, 
            0xD338359879A74D76ULL, 0x234C87F52EAE8A85ULL, 0xF578E628B67985C0ULL, 0x4CD7F2A588CC392FULL, 
            0x03722F9739AC664BULL, 0xC68043BD6538A0E6ULL, 0x2002EC0D74AD158FULL, 0x5E660C36AA417ACFULL, 
            0xDD83BDB4AE788719ULL, 0xC03EB74DBC8630A4ULL, 0x5E5A1824B917DB77ULL, 0x05376F777939C388ULL, 
            0xC0B92F5B859128C5ULL, 0x769D3ACEE0CEF729ULL, 0xEDD0620D32F003A6ULL, 0x5C1FFB3AA0FDA3A9ULL, 
            0x962058431EDCBAAAULL, 0x0CA0FF3D03550799ULL, 0x2C2A42AFCC9B1502ULL, 0xC3C30F8095796495ULL
        },
        {
            0x4907AB715AFF0281ULL, 0x5FD9228992F37C40ULL, 0x8534DF590B4A4102ULL, 0xD3893AD1593CB034ULL, 
            0xD85741F94E4E7F85ULL, 0xB1181C79C01081BDULL, 0x3E9014F3C00E60A5ULL, 0x12133E35C1B0BE8BULL, 
            0xBD06A3EDDB85D142ULL, 0x871E557443A196FAULL, 0x38645D9850D28DBFULL, 0x4104A6F025475E77ULL, 
            0x1A22C89CCD36A0A4ULL, 0x8E7741A9F00960EBULL, 0x4E34EFF0A469E6F8ULL, 0x26C28209ABAF60B6ULL, 
            0xFE762A41D045093DULL, 0x084C3E0CCA30554DULL, 0xED846E56FA82A802ULL, 0x030319B9E4E28F47ULL, 
            0x094E878EF451ED3EULL, 0xA48D04D3BF7663CDULL, 0xAD1BF739BC78AE6FULL, 0x22BC39FBEB4A3F58ULL, 
            0x7887E29117D7F2F6ULL, 0xC5AAA41555FD789AULL, 0xD1F2ABBB9AE0F62EULL, 0x76A6296AF1103881ULL, 
            0x3256C68EDDBCB2F0ULL, 0x100E53C9CA4E973CULL, 0x701580AF337C11B6ULL, 0x850EDE232AB1BE31ULL
        },
        {
            0x1A03542D8052875DULL, 0xD57272EBBB23BA4FULL, 0x36B930DB4F084E9EULL, 0xFE117A336150932CULL, 
            0x88E76ABB70C506AFULL, 0x30F6D78D3CFCD1B8ULL, 0x4EBE70A53C1F6255ULL, 0xD2E9AECB89F65574ULL, 
            0x2C370D5CC2274868ULL, 0xC6D907BFD146DADEULL, 0x0E71ED5E303B3EECULL, 0x52EA2A3F1C36B4FFULL, 
            0x7D62EF705F574361ULL, 0xB045AB3173E20DD3ULL, 0xB62C906E4E9AF038ULL, 0xABF46CC4F1AF88E0ULL, 
            0x81D000A5765817AEULL, 0xA9126734E72C661DULL, 0x75EB291425819B6DULL, 0x8B4F9FB448FD3512ULL, 
            0x7EC64E7CD2034BF9ULL, 0x5251EA2F067EA3F3ULL, 0x868BCE3F091DF407ULL, 0x4278259787015F69ULL, 
            0x6A534612F48F8130ULL, 0x64B5A9DD9FDFAB98ULL, 0xAB821E985041BC9DULL, 0xF484481A00D9D6CEULL, 
            0xE34FDD4E562B330CULL, 0x38ED7BBD6DBACBFBULL, 0xD8155E9AA9534092ULL, 0x566651D97F753829ULL
        },
        {
            0x6E8388839202BAB7ULL, 0x4474D94BAD2B3331ULL, 0x29DC21CA752C302AULL, 0x7A650A36ABC8909BULL, 
            0x49B774DF56BFE70AULL, 0x7866B8DFEC01CE71ULL, 0x457025638416EA2BULL, 0x022AE045C36F6857ULL, 
            0xA1B15810E06D7565ULL, 0x4258185002E06DDFULL, 0xA3935179396FC790ULL, 0x8E59A3EF6341E556ULL, 
            0x0D0EA3B94D8FE255ULL, 0x69CDEFB9FB36A13FULL, 0x76FE8BDE302A224AULL, 0xDD422A1B8AA987D6ULL, 
            0xAF7B3C85F12C43A1ULL, 0xFFC98C6E6AE999DEULL, 0x68752AB5E1958541ULL, 0x98D48CC3EF2B52DEULL, 
            0x562F596A1EABD3BFULL, 0x159D240A67FCE5BBULL, 0x863F7A14E49F9704ULL, 0xFA20C7125DD6754EULL, 
            0xAB9FFE64C27792A0ULL, 0xAB3D1022AD702A2CULL, 0x18A80DD08A02195AULL, 0x517BF425C6F34AEFULL, 
            0xC982E726F39F5645ULL, 0x77301BF1644C50F9ULL, 0xC2A68F5AA1439B8EULL, 0x84B91123B19733B9ULL
        },
        {
            0xEA4DF12A7A4CF286ULL, 0x0D1FAF8E4679C35AULL, 0x0459EB461C9B1756ULL, 0x6A13C5FA92472EA0ULL, 
            0x4C4D9FF72D12026CULL, 0xD5B47E004AC78C2FULL, 0xE8F94036D1FBE7E8ULL, 0x21FFAD4141E11342ULL, 
            0xADC640948BDD1E09ULL, 0x2C11D6B6448DEA03ULL, 0x2ED4D537DCB66348ULL, 0x957FC847A2FCAD7FULL, 
            0x6932E852166E1F27ULL, 0x9187D28BBD01B1E9ULL, 0x18B1134A83FCBE1EULL, 0x348E226EE67767DDULL, 
            0xB60EF97872300879ULL, 0xA76A56EB122C449DULL, 0xBB6264E0E37DCF21ULL, 0xB62200C7F68F05E2ULL, 
            0xA57B2FF9B5080146ULL, 0xDB69CC88EAF1D495ULL, 0xCA7665987211906EULL, 0xA7FB247FBBCA8087ULL, 
            0x9E2734900E08D419ULL, 0x7DB6209B44601B25ULL, 0x79E65CA4137D6A7AULL, 0x6ACF2394EE54EABAULL, 
            0xB66B2FD87399B690ULL, 0x505A453E687EF366ULL, 0x029DB643F9991CE9ULL, 0x0B3E24ADDDB45FB3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseAConstants = {
    0xFCF43D7C35E8AC4CULL,
    0x3DEB5009F495B9CDULL,
    0xD3546FB43DCC3265ULL,
    0xFCF43D7C35E8AC4CULL,
    0x3DEB5009F495B9CDULL,
    0xD3546FB43DCC3265ULL,
    0x9A73EBBE5F5B20F6ULL,
    0x4899E47ADCDDEEABULL,
    0x1E,
    0xD3,
    0x37,
    0xB3,
    0xFA,
    0x7C,
    0xAE,
    0x5F
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseBSalts = {
    {
        {
            0xD59544190752006DULL, 0x3F438A4607BB5638ULL, 0xF87A0B24DA4BB469ULL, 0x9D5BFBAED4846D3FULL, 
            0x0E41AEB124756444ULL, 0xCD89C4E3EB57231FULL, 0x781B7B871F114964ULL, 0xD90FC29CE0E12287ULL, 
            0xAD04D78062DC4B00ULL, 0x7EDBAFD24203F6D7ULL, 0x656940A7DB0E8E1DULL, 0x31D6C93DA137BACCULL, 
            0x88C501C2404B2B77ULL, 0x625AC39DBAA062AFULL, 0xB801088AEF19214EULL, 0x372120B8855D4F27ULL, 
            0xF34A8DD65AD69B56ULL, 0xABA0CAF982991CC2ULL, 0x9B4A6FC76A0773FBULL, 0xCDFBA924C6ECD40FULL, 
            0xB39639B80591FCC2ULL, 0xE47F06B420D66258ULL, 0xE07BDC4630EC88FAULL, 0xAD78BF3CCE298F48ULL, 
            0x1F1558A677109B37ULL, 0xD7EB89C22325AF79ULL, 0xB6D0925468BC8F89ULL, 0xCEFF0C889CDCA00AULL, 
            0xCA6B96EFF1B0FB1FULL, 0x087F30BD3B9F7ABFULL, 0x1ECDC22F7923E058ULL, 0x591899D192E0660FULL
        },
        {
            0xE396DA1A1D1BC23FULL, 0xF5AC101A9F870722ULL, 0xAFA9D3848659424DULL, 0x765604735B1D1158ULL, 
            0x07255B8EEDBA426FULL, 0x2B5B2D66093A8EC8ULL, 0x5CC1279183BB8F68ULL, 0x3BF5CACC328E9B8AULL, 
            0x555855875A4EF3F7ULL, 0x760F81F62B2FFFC9ULL, 0x09B86F1F7280191EULL, 0x9F2319E843B5FC37ULL, 
            0xC576FCD7AC6181D0ULL, 0x2FD0F1A91B6700A2ULL, 0x71DF043F647BCB55ULL, 0xB27D8C03B937E725ULL, 
            0x651E9C697F93F13DULL, 0x2A2CB7B30EDD88CAULL, 0x9430E28699104F62ULL, 0x408E4E39ED3739BEULL, 
            0x71CF08388D71FA22ULL, 0xBB428D2F4FEAA1E2ULL, 0x5B75D885E7517644ULL, 0xBA1EC0F72A339033ULL, 
            0x07008C23A10A3381ULL, 0xAFAF1709BC7A55D6ULL, 0xBDE54821C1D08855ULL, 0x28C45A0275AC8A36ULL, 
            0xC0E5D70A17AC250EULL, 0x25C27E1DBDE90D25ULL, 0x0865ED19CAA52001ULL, 0x39EE29AF72FD7D32ULL
        },
        {
            0x96337C4F38763FB7ULL, 0x4E7E214916D82FF1ULL, 0xE174D9AE28B5F48BULL, 0x12EC89C2EF28EAA4ULL, 
            0xB079CA036D73E30CULL, 0x7D04FCA297B27FAEULL, 0xE96FF61B6E2710C6ULL, 0x26F0FE2E4C9E7509ULL, 
            0xEB2BEA8A65F929A3ULL, 0x33352AB559B125B1ULL, 0xF72E3CE0B175AE0CULL, 0x48871BEAB79C5549ULL, 
            0x72DBE02E054F8F81ULL, 0x1A7F65D5E503FCE0ULL, 0x8814C9FD114E8669ULL, 0x9DEDD32E93C75583ULL, 
            0x5A7807C13FC36984ULL, 0x407F1BCC24D834C7ULL, 0x419263B1C536FD8DULL, 0x40CFE1BCA294EC50ULL, 
            0xEEA7B37F4B83AC1AULL, 0xA5481A254BD5E66EULL, 0x730AD2B9E9F3AAB5ULL, 0x6822C08401153F99ULL, 
            0xB2CDB61C8B8699E9ULL, 0x2EC3A05B28DCD656ULL, 0x141A2C8ED459A5E2ULL, 0x763CB8780AC0E3B1ULL, 
            0xC16F6C3839E28EE2ULL, 0x7CF1886D40EBE301ULL, 0x26A80B32645B617CULL, 0xA111411D71430639ULL
        },
        {
            0x06032FC43F8042F4ULL, 0x5DC2E802C81F1323ULL, 0x3385660B17A9C119ULL, 0x3DC4D5448179ECF6ULL, 
            0xDF973FBFE0C67FDAULL, 0x327F0688DAC730BEULL, 0x3350F2ABC788E752ULL, 0x9342E762B606752BULL, 
            0x4FC2AE8405821E3DULL, 0x06D6D7BFD353FF52ULL, 0xD102B86942C2ACDCULL, 0x916A229F3B73AE5BULL, 
            0x47C91BA740F7BB29ULL, 0x315D7C52FD0BEFA2ULL, 0x4B918C199A460993ULL, 0x952E9096AFBDAC5AULL, 
            0xD43344FD2E88AD0BULL, 0x293625B10DCA32D9ULL, 0x91F8B8FE32CFFD05ULL, 0x80CD67E078BECFD5ULL, 
            0xDCA8235915A95608ULL, 0xFAA45B745D4AB61AULL, 0x5D2016E92C8F317FULL, 0x862E8B1D1678DE7EULL, 
            0x6A1E580D675E428EULL, 0x8211517721BB4FB5ULL, 0xE8876847ED4853E0ULL, 0x1B37BC0E090E3000ULL, 
            0x7AFA2F4C1154D52AULL, 0xEA1FA8E7191F89A6ULL, 0x23027B497567FD8EULL, 0x148094A471D62379ULL
        },
        {
            0x99F17766B36AB789ULL, 0xCD41F970359B86C3ULL, 0x4933CD41E3A32C87ULL, 0x0871C8DCBD37F35BULL, 
            0xBFA8723CC79BB009ULL, 0x28F357DB0F074230ULL, 0xA8A97F7BF4F01BD4ULL, 0x01F3E6A9D044758CULL, 
            0xB1F942F6AAC60233ULL, 0x8BC43EAFC2676309ULL, 0xD345016D1113A728ULL, 0xCB14FB1D8A85B094ULL, 
            0x9823F1A7076DA6F2ULL, 0xBD07A60F1B282D9CULL, 0xE007AC04F9FE7EECULL, 0x5176D3839CE3FB9EULL, 
            0x0956AB6F02B3D902ULL, 0x84B5C65F56063501ULL, 0x850F34107BE40F95ULL, 0xBE81FE072E3F257BULL, 
            0xC2BB3D6A2F502279ULL, 0x5085F394219F7D89ULL, 0x7033E1390BE9B5F1ULL, 0xC2B4368ECDD334F7ULL, 
            0xE7A1C3280AA87204ULL, 0xD8ED4D790C661F71ULL, 0x45BC66117CA3DC6BULL, 0x205F518B5791074CULL, 
            0x7AEC5E0CB964E550ULL, 0x41004B51718B1A65ULL, 0xC4C8570036F879DCULL, 0x595097D5B869D8D2ULL
        },
        {
            0x653445FE0D86566BULL, 0xEF9DCE88CB188DA8ULL, 0x72D440E4787FAEBDULL, 0xB183578B6C151FBBULL, 
            0x057FDC9353667EBDULL, 0x8B2D3F04E05BD6BAULL, 0x7A6938669692F279ULL, 0xB63D2974FCAFD351ULL, 
            0x891F9B8C368F9F05ULL, 0xB19DDB66F57EC7AEULL, 0x74C04EB7054F6D56ULL, 0x0C7B62F8818D0D9BULL, 
            0xD0B486EEF4B1ED44ULL, 0x6C7C3A197A623A5BULL, 0x2EAEBB8E387593FFULL, 0x16EBD3276CD726B6ULL, 
            0xAD9C6060A2685C97ULL, 0xB78B2623F5A8865BULL, 0xFA86CC04ED8B2927ULL, 0xB058D542DFE172C9ULL, 
            0x4E35432EA6D75D68ULL, 0x3DC71A596F634E96ULL, 0xE08883B86564161DULL, 0xD4BE6BC927F50BC5ULL, 
            0x2E32B28BF144890BULL, 0x80FC6A8C436AE131ULL, 0xF39843782807B339ULL, 0xAD39C2632D669AE2ULL, 
            0x558312CD1B7EF084ULL, 0x471FE39AD9F521CCULL, 0x871D9160EF70512CULL, 0x0855488D0C90F31FULL
        }
    },
    {
        {
            0xE1384FE279CF38D8ULL, 0x50062BCA8CD280AAULL, 0xE54092F48BF6E108ULL, 0x488F71B97C450503ULL, 
            0x88B46AEF0D8F1200ULL, 0x69DD3A7EEAD7A537ULL, 0x5603699A87C373C5ULL, 0x2F2BE7B8A6A673C0ULL, 
            0x195AA2307A0DED9DULL, 0xA22A14EA44BA7EEBULL, 0xFB5716977888CFCFULL, 0x0EA92CEA3D18659EULL, 
            0x1AAC3DA9542D008AULL, 0xE2B7DFABB770C8AAULL, 0xA9E20DAB5A09EA66ULL, 0x776A833CAE4BA5A2ULL, 
            0xF20F2724609E8006ULL, 0xC1037072E11551E7ULL, 0x4A628989ED51F34BULL, 0x0718172A1BBE0C47ULL, 
            0x39D8675CC91EAA7EULL, 0x15DAFC16CA6F328FULL, 0x6BD1922DB49ED60CULL, 0x62B78D699270F6B6ULL, 
            0x063796FBC87ACF7BULL, 0x3A4D205109696616ULL, 0x72A480A42BA28C9DULL, 0x84CA192680D9CF0AULL, 
            0xC96C8FF8C375AFFCULL, 0xB0222C6E3CAD6D80ULL, 0xFBF14D9BB901B084ULL, 0x018852798365CFEEULL
        },
        {
            0xD6F1F614CA7597B5ULL, 0xE862E7771EE2158CULL, 0xB3D17C8C434F7C24ULL, 0xA063ED441DB05A1AULL, 
            0xE6CBF1A6B262D60AULL, 0xF0B9E5D075B54952ULL, 0x6C31FB9D84D327F0ULL, 0x4446A705113135CEULL, 
            0xBBB38D52DAD2BAFBULL, 0x496F81542421DBA7ULL, 0xB01667C851365596ULL, 0x22891943FB4C982DULL, 
            0xEADA27970DCC1404ULL, 0xCC0FC4AE3D5F1E4FULL, 0x75F21B51D8AF344CULL, 0x2213088FAF924EA2ULL, 
            0xA39C9AEAD91C6A8AULL, 0xED73C4F506D759CAULL, 0xC2F37970E3A7F117ULL, 0x48D4C49651C8EF3AULL, 
            0xCA88ADD3831A1B7BULL, 0xDAC7BDE13ADC6E13ULL, 0xAEA0BCFB3D80B34CULL, 0xF4F871BC588CB674ULL, 
            0x8CC1E1FA90782867ULL, 0x4193A1F1C6A42E85ULL, 0x4BBF851B81E20201ULL, 0xFD33620B923BE987ULL, 
            0x340FF570AD8A19CCULL, 0xC4E4032F61B4D1BEULL, 0x5B66D349DFB15F05ULL, 0x744F9A882328C1DEULL
        },
        {
            0xCD83F57B4ADB8DE4ULL, 0x6FA03F3B9F29552BULL, 0xE097350CC029A44EULL, 0x70D2BCFE3EDC1EECULL, 
            0x15A8E06ADE8049BFULL, 0x6A4172F7E158A7D9ULL, 0xA1778238DC2981C9ULL, 0x9E2D0CDC31D1E4F9ULL, 
            0x0798D58B33CD240CULL, 0x894B8227B679D1D8ULL, 0x672E95617347511EULL, 0xD2043858105BEA90ULL, 
            0xD3C0A1480C4C0A9FULL, 0x2A905E982E8E1CBBULL, 0x056EF237AF80AA92ULL, 0xFB1EA26A25AB92AAULL, 
            0xD61E9FABAC1D5A8FULL, 0x9D08460360317A2CULL, 0xA9053A2FB6ADC75AULL, 0x0F78471E498B09D5ULL, 
            0xEE1594B995740E3DULL, 0x8E706FB52593492AULL, 0xD1C3EF971BCE5C2BULL, 0xB782B8735DC9E023ULL, 
            0xC475C22E19AD0EE8ULL, 0x83296315003EC51FULL, 0xAB49B9EFC6B5B309ULL, 0x1C537B56BC15D97EULL, 
            0x4D05949BD1D46E2AULL, 0x5B31A4BD3DF2CF10ULL, 0xA88A69509F227C49ULL, 0xA25AF2DA97940E62ULL
        },
        {
            0x8282AFD148F15706ULL, 0xB77352A5AC176987ULL, 0x7F11072ACE507038ULL, 0x7FFAEFFD0D50A3F2ULL, 
            0xDCF7D6D755726654ULL, 0x70787B40C5B86D7EULL, 0xA270C8E8C82CBEA7ULL, 0x927E5374D816D903ULL, 
            0xB2337885E95D0164ULL, 0x1CE4479CAA13FC9EULL, 0xD7C91605C0BC3521ULL, 0xD0B57F6C904D79CBULL, 
            0x06C528F295A89E17ULL, 0xE20CF2A0E6167D8AULL, 0xBAB2B26EB9749F83ULL, 0xD159CD9115314B3AULL, 
            0x0E102BABEC1677F7ULL, 0x222C38D0712907D4ULL, 0xE616204330B38219ULL, 0x860EA53B77C6C62BULL, 
            0xBCA087AE8A6A2FFAULL, 0x788D343B6C8EEB91ULL, 0x225AEA222C2D3075ULL, 0x89EF908995113AE7ULL, 
            0x85CEC85ED7A1F41EULL, 0x81F0E4C0AA6E175DULL, 0x426D99359DDE10D4ULL, 0x432D915AAFABED6EULL, 
            0x34D718B48BE3F649ULL, 0xB23A56F5AE957C5EULL, 0xF5B51B0CB352BB3AULL, 0x97E32BF7B2EECBAEULL
        },
        {
            0xB6CBF50B3B8ECF5FULL, 0x82C7719D4C3C7E56ULL, 0x331AB9CC34A97432ULL, 0x80EFCF4FFE9BDF7EULL, 
            0x0D94218E99DB7984ULL, 0xA2E27E3A3ADEA154ULL, 0x9411C1531C6BEB43ULL, 0xBE988F5C9727CA37ULL, 
            0x490D6C88530B0DFDULL, 0xCDFA41F7691B6013ULL, 0xA85EEEAA64CBCE9EULL, 0x4667E329EF4F35D4ULL, 
            0x46B214E02CBE95B6ULL, 0x79AB85BD180F531DULL, 0x176F3E58AC12AB70ULL, 0xC5BA3C898974F139ULL, 
            0x12F4A552873C7340ULL, 0x099C2ED23566A1C3ULL, 0x1F6FC08D7CA6B6F7ULL, 0x1407AD6EF9CC0D00ULL, 
            0xE46179756F501807ULL, 0x5F95E7F8E26F24A9ULL, 0xFBB3462C2984CE36ULL, 0xCB7351FFA55FF7D9ULL, 
            0xDE207E36E67DA90FULL, 0x948A38411980F96CULL, 0x9FB6D1CD3F244631ULL, 0x6EFD011C8B110B79ULL, 
            0x7C592721A263607AULL, 0xA83EFF93266C41FFULL, 0x6F647CBAF6EC8DD9ULL, 0xDA1EFFF91B907818ULL
        },
        {
            0xB77604AAF66BA4F3ULL, 0x2C35B600825CD5B5ULL, 0xA397BDE902291072ULL, 0x81C8B6277503A7D0ULL, 
            0xFAF794659EB7090BULL, 0x9B4F51EAFE989D72ULL, 0xA2EEB2B4F1144572ULL, 0xAC30384B33157182ULL, 
            0x52296B8640CF3CCEULL, 0xB53101D222D622F9ULL, 0xC4405981B0D60253ULL, 0x079493B8405B6718ULL, 
            0x5D7E35EBB125B82FULL, 0xF0CEFDC74538D03FULL, 0x8F3AF56CCA829EABULL, 0xF2B9A599447F0B3DULL, 
            0xBF1ADCC361D4EFB1ULL, 0xF82E6B77A25A38E7ULL, 0x17C27B8DE8048C88ULL, 0x590628DE73F892D0ULL, 
            0x0AD5DAF5C847ABCCULL, 0x0419CE13D17EB103ULL, 0x54C3385B65DB4C12ULL, 0x8129D92F7D631BE4ULL, 
            0x504131BDF1A7B4C0ULL, 0x22B08A9B03C770C1ULL, 0x54BBDAAB844D7A21ULL, 0x5C8956412B439257ULL, 
            0x5BD4F401A0060FC5ULL, 0x2022BF2C820F9EB7ULL, 0x0B61FD86E9DF9DACULL, 0xDC49A594B3442B78ULL
        }
    },
    {
        {
            0xA09B98F3B8BEA7F8ULL, 0x68F310D5F8B652D7ULL, 0x9D7FD1C5F82ABFEBULL, 0x1D4936BC4DF40F3BULL, 
            0xC427F8524A1B8077ULL, 0x259AFE97526CF3EBULL, 0x5D24698502BC2AEAULL, 0xE4A9FDF9CEA0A7A4ULL, 
            0x73242D59C83F9188ULL, 0x6E6F0EDF054DF09EULL, 0x31AEC055303B6DEEULL, 0x4B94F0CB91E9F616ULL, 
            0xA25E3E647CACF295ULL, 0x837DE8C5DE42BED0ULL, 0x5608BAED40D6A7D7ULL, 0x019AAD3DCF122E53ULL, 
            0x42F81AA8D2B4C8E0ULL, 0xD201CAB3B5DCE08EULL, 0x899B7D5557115D8BULL, 0x2545CBED78DC03B0ULL, 
            0xBABDD6D1F2746E39ULL, 0xF975573D95D8299AULL, 0xEB6DE4B8E9B49962ULL, 0x67BF0E90D817133DULL, 
            0x746E62CC83A67F0BULL, 0x7CDDFCDE434DA627ULL, 0x881999127AF03E6FULL, 0x587F67879973620EULL, 
            0x5ECC1438F1D18551ULL, 0x62A38022E1A9E05CULL, 0x5E7F27D874A3BC24ULL, 0x22F6871C96AFA0A1ULL
        },
        {
            0x25D38DF95DB70E18ULL, 0xB3CD37C3C2F8C0D2ULL, 0xB8EB9E11E2943671ULL, 0xE684160DB09CFA66ULL, 
            0xEBBC5F7CD3FF6F75ULL, 0x4E1E3D4D466C4B31ULL, 0xD0ECD6BD097D20F3ULL, 0xA0EA0882C509D8AFULL, 
            0x67861545F4AE7AA9ULL, 0xE1EC8D53C43A746FULL, 0xF5DABE6455F2E146ULL, 0x4131FDE79D5792B9ULL, 
            0x0BB574571644424CULL, 0x64993D2CB5B843B9ULL, 0x8A192B9F0DFCA4ACULL, 0x1CB2CDE22D5FE5ECULL, 
            0x138DFAFBE147D8A3ULL, 0xC8F6BBD222DED8CBULL, 0x2FE5850D7A1B2385ULL, 0x341E3125F602DE70ULL, 
            0xA5532275D7186BCAULL, 0xBF3DE13C4C12DAB6ULL, 0x6FC38B7C38E117E0ULL, 0x330DA1AA59B440A8ULL, 
            0xB2A13E2B199B326BULL, 0xACA49416035484F3ULL, 0xB971235E55016CBCULL, 0x768833168565A7BBULL, 
            0xCBD4FD3FEC2ACB21ULL, 0x2884C789758FFA1DULL, 0x73F4464959F87B4EULL, 0xCE1F40B99790E5A4ULL
        },
        {
            0x9DA3522C7044CC9AULL, 0xA53629C986BAD8B3ULL, 0x9290F0728292B9D6ULL, 0x4A78F566BB85D970ULL, 
            0x49E62B380360DB54ULL, 0xE6029A21CB9FFADCULL, 0xF8DBB89D5A44B71EULL, 0xB1B11A0589ADD26CULL, 
            0x0238DB8E15819BEEULL, 0x2045D338A3AA3EEFULL, 0x1CB7EB03ADED86CFULL, 0x7AC34BA9B052F5C7ULL, 
            0xD4ABC299EEA5D4ABULL, 0xF5131B14A8E71394ULL, 0xA3B1F624133ADC72ULL, 0xED164CB3B80A54E5ULL, 
            0x32EEADFEB3960580ULL, 0x074A682373C9F84BULL, 0xBCB663980F793726ULL, 0x905645A988669736ULL, 
            0xCD4DE5DB6F766D39ULL, 0x5EBBCFCACA9762F6ULL, 0xC8F1FCF9ED9EF0F2ULL, 0x20297CF5E7091013ULL, 
            0x5F7E253E9E059FB0ULL, 0x8926E39F07F47DA1ULL, 0x2E1966CFBEEB2526ULL, 0x82D7FB33A565364BULL, 
            0x0DA647A23F2B72FEULL, 0x4A76D83E35C7DFD9ULL, 0xC38C0BFD20849A20ULL, 0x8E2424D03EB36195ULL
        },
        {
            0x931120567B842956ULL, 0x58600F9654392457ULL, 0x867FAEA23EA5CE27ULL, 0xA3C3109A6847870FULL, 
            0x810D4AE5A47E3EFAULL, 0x18498592916713E9ULL, 0x1D5C116106ABA7D2ULL, 0xD35E98260AB33360ULL, 
            0x54E59A32BE65ADA4ULL, 0x4B27DE1BF06D7F33ULL, 0x7BDBD8BD001EBF08ULL, 0xA37A926394B38E48ULL, 
            0x80DE937E744DA079ULL, 0x62D2CD56C6BB7CC6ULL, 0xB715D3BAB7B1909CULL, 0xDB23CAC128348644ULL, 
            0xC90A7529BB1FE24FULL, 0xB8E97D800B2F3F59ULL, 0x3D46ECB634EE4BA3ULL, 0x5B4F759904FC50A1ULL, 
            0x408B4C6989ED743DULL, 0xD384676B159E8EBDULL, 0xBAC5B9030E51047CULL, 0x016BDE9F5E94E072ULL, 
            0x571952E7854466DDULL, 0x1FC3D0D7D18DEF42ULL, 0x50FD2A3F03919F46ULL, 0x2C462E1E6374566EULL, 
            0x56FB5DC0B3D68C04ULL, 0xDA1E7CB682189591ULL, 0x6062B5980458AAE0ULL, 0x407113C360BDE8E5ULL
        },
        {
            0x27EEDF7AAD58CB54ULL, 0xF9FF444473346049ULL, 0xB950CF393D36DF13ULL, 0x2B64BD79EEF79EF2ULL, 
            0x2051A3785C35A4DFULL, 0xAE556ABD760D9A23ULL, 0xB6519C0686B4EED4ULL, 0x7FB30DFFADD7EB82ULL, 
            0x2DD33ABA8921E5D4ULL, 0x68DAC99295D54E24ULL, 0x3CDDAEBD12C0BF5EULL, 0xCD0D3CDEF7D9C563ULL, 
            0xE55E543F730997A2ULL, 0x15FD0DFC8B53622FULL, 0x628FB803B06624BDULL, 0x50A64812A87AAD38ULL, 
            0x7408FD8B7A7FC368ULL, 0x17F4AF547BDFB5DAULL, 0x16D2A9A8F8FB952EULL, 0xB90AC70F48AFB6E5ULL, 
            0xA5887806037B85B2ULL, 0x1F473EBA542D4FC6ULL, 0xBD0543DB7082563BULL, 0x260A602C87AE921BULL, 
            0x374D3725A5290EA2ULL, 0xC81E3F9FF081F00AULL, 0x7B717D36D992C06AULL, 0xAE3D9F3461FF4DE5ULL, 
            0x557338AF4F190F0AULL, 0xE467884FA30FFD5FULL, 0xCE990D8AC051187EULL, 0x9FD525490F80AEE6ULL
        },
        {
            0x522455711CA5C57DULL, 0xE06868B1F58C39BCULL, 0x6337138FAA71139DULL, 0x7F545F81AFC58B38ULL, 
            0xD5875B7B43B50331ULL, 0x932DDC8724C41D71ULL, 0x0E65378F82B2DCB9ULL, 0xD7A3AC7841FE14BCULL, 
            0x073CDC721E465BB0ULL, 0xE98790E2F59E610AULL, 0xFA95150AC2F1D371ULL, 0x368DB4A9C646D2D2ULL, 
            0x89F7226804DAD7FBULL, 0x053E01EB2DB5F061ULL, 0x03662887DD7CD81BULL, 0xB2117A9ECC97E2EBULL, 
            0xE3E3C828196A7549ULL, 0x3F04529D465DCBD1ULL, 0xAE3C638C619EF98AULL, 0xF4D203B3C42E76EEULL, 
            0x7DD7965A9566DF81ULL, 0x8E82257CDC4B025CULL, 0x9514A1F69926A274ULL, 0x77440855EB3B0A33ULL, 
            0x4910726A219C819BULL, 0xC83F1BCC7A72A943ULL, 0x5B971097807521FCULL, 0x4C9B562C3B638FFFULL, 
            0x18CD671D430CC8E5ULL, 0xBD8C80BF5EC60913ULL, 0x8F328397409D5D66ULL, 0x03768A2DAAB1C3C2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseBConstants = {
    0xC6A65F579F53AC3AULL,
    0x5A8687635B15DF55ULL,
    0x9C283FE229148B70ULL,
    0xC6A65F579F53AC3AULL,
    0x5A8687635B15DF55ULL,
    0x9C283FE229148B70ULL,
    0x412C02F8A2E3F715ULL,
    0x0657F6D6D5135612ULL,
    0x4F,
    0x68,
    0x49,
    0xB8,
    0xB8,
    0x02,
    0xCC,
    0x3E
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseCSalts = {
    {
        {
            0x9A26695E5260501AULL, 0x2000D5572EDA5B37ULL, 0x0ACB8E1193D32146ULL, 0xD638F3866D196039ULL, 
            0x3CE04F0C5C66B792ULL, 0x909B99F505715B2BULL, 0xA311B29E19C53DA6ULL, 0x7D264C917F178934ULL, 
            0x6461B0B85B682E42ULL, 0x11B3EE72FB2B245BULL, 0xA28B07DD906CFEA7ULL, 0xFCCB8A9C496CAF0BULL, 
            0xDFCC1E64BBB08250ULL, 0x74C73590EFF38D19ULL, 0xA13DFFD98D6C328EULL, 0x70BE4945A6E473CCULL, 
            0xA8534A589499D614ULL, 0x62FC002A28379E97ULL, 0xCFD6A2738D01A1AEULL, 0x8F32AB9907EA8647ULL, 
            0x710FE4E5A43FD9A8ULL, 0x84AC22304F71DDD4ULL, 0xA1577A26ACC0AAC5ULL, 0x1D07F6D557A40844ULL, 
            0x71BA11395CC31D62ULL, 0x5616979058CF4A40ULL, 0xBE7C20E3D772FBF7ULL, 0xC04B9CA5EEA6B020ULL, 
            0x50D7E1AD81F83B61ULL, 0x3EE14C113C7FE198ULL, 0x22038B2BDEAA7896ULL, 0xBFB8060730D27D76ULL
        },
        {
            0x0E5727120BDF92B3ULL, 0xC2E85E0F96CD0187ULL, 0xC22B1F82CCB89098ULL, 0x983632D7A850171EULL, 
            0x5CF793EF308CFFF5ULL, 0x225E223A6FAF5438ULL, 0x04863C761F3F2525ULL, 0xD6555BC430AE9550ULL, 
            0x3FB04A520C26A354ULL, 0xA8B2363F8B60587CULL, 0x82230EDF20F1ED0AULL, 0x9CF7A7EDF66C5917ULL, 
            0x14EECA1B3C465C43ULL, 0xB731E82BE9DDA257ULL, 0x37E520EE8B3069A9ULL, 0x5B6EB23EA26CEE3FULL, 
            0x202384BD68B15C63ULL, 0xAA063AA1D4F468B9ULL, 0xE2A068C0816B556EULL, 0x80F71174D2E0533EULL, 
            0x083A0A63A331A8ADULL, 0x022B4496DDE22997ULL, 0xFC0B17058DF43855ULL, 0x7CC76D32C1CE305FULL, 
            0xFDB5099A700D937FULL, 0xFB95904AB8236256ULL, 0x1353AD61953F0CC8ULL, 0x0FE6860A56E997ABULL, 
            0x3C2F4598FDFE4600ULL, 0x07D2D0376821BF09ULL, 0xF332CBF6F7D6530BULL, 0x5783AF18816B136DULL
        },
        {
            0x40ACD13764BA9EDFULL, 0xE4DF13FBC962C10DULL, 0x21C2ECF1130ACD57ULL, 0x40A7456B3DCD61A7ULL, 
            0x0C3B29666A5F3613ULL, 0xFEC0A1593D3553B5ULL, 0x6280ECB6A258554AULL, 0x14EE3210C4771178ULL, 
            0x49EFC92859C9B381ULL, 0x37C23A7CCC9A5EDCULL, 0x2963703FBD7FB654ULL, 0xB7C56BF7B0595F9DULL, 
            0xF260C2A4F3D57EA1ULL, 0x58ECDBBE3E6A6968ULL, 0xFFE28E94D66A20C4ULL, 0x59E95E39A7F9DC23ULL, 
            0x95DC319E6E2F73DDULL, 0x7C6CA97BC4D8D44AULL, 0x1F25D4D614FECF88ULL, 0x597A6569527647A7ULL, 
            0x6A89BEA4B2C64703ULL, 0x813E2B62A56D4EB5ULL, 0x156FA7DA510841F4ULL, 0x31A2EDD418B2CBBAULL, 
            0x4AAD6DA25F9E5929ULL, 0xB82A0FD57FA78413ULL, 0xCCBE75D391279271ULL, 0x7D68D41E64406A4AULL, 
            0x61D85159C83C86F7ULL, 0xF1114C2EDA60C763ULL, 0x20EFFE3E488703B2ULL, 0x2606A28033069F93ULL
        },
        {
            0x9F1053285423E60DULL, 0x6436D833D5A9C74AULL, 0xF6487AD1D8233081ULL, 0x2C78FD66AAE14942ULL, 
            0x4C4A17A05CC2A03DULL, 0x7CBA789F184AE240ULL, 0x3D4CF854DFBBC508ULL, 0xECD6E315503C644FULL, 
            0xE1BE5A65E8DD30A5ULL, 0x754C1A5A0C394D5BULL, 0xA8570D972BDDCF60ULL, 0x6139BDC913966C9DULL, 
            0xE3DEA8AE7DBE4E9AULL, 0xDFC383F766317ADFULL, 0x14FB65CB6307F7D4ULL, 0xD44518FC55728590ULL, 
            0xF99E52AA0A83AF5CULL, 0xB7CBED97767E8340ULL, 0x802A967639E67A64ULL, 0xD8A63FB9B34A2832ULL, 
            0x2E20F93A760C5CE5ULL, 0xEA5763DCB7655234ULL, 0x65A7A0C2EF72861EULL, 0x20E10C379C96BF59ULL, 
            0x35C8031AD3B35EABULL, 0x40C70215FFD0000FULL, 0x6D68BD5B64EF7A4AULL, 0x4516DA0D20EBEE7DULL, 
            0xF68DAB29679D336DULL, 0xFC03CF86AB070403ULL, 0x2C43BB569795428BULL, 0x25A1778B68B74826ULL
        },
        {
            0xD1405E3108FA688AULL, 0x77817B898784ADFEULL, 0x18DBB490E745263DULL, 0x5753E062E1B6566EULL, 
            0x8D7B37C36482CCC9ULL, 0xF28E5F74278A707DULL, 0x932B215F5B543633ULL, 0xE6CA6E5620E00CC1ULL, 
            0x355FA1066EABA6B5ULL, 0xD4C6CC421A0C4C2BULL, 0x31314F2C297E3773ULL, 0x1409FFED37ACEBC6ULL, 
            0x6A8D672DCB023023ULL, 0x7A7A5D5197BDC7C9ULL, 0x4F5D18DAB7E72D73ULL, 0xA05D3F0D6A9F00CAULL, 
            0xF94E8D22C61F1A9DULL, 0xB7C7139CC638B519ULL, 0x32633614F03CC344ULL, 0xB7B3F011419353C9ULL, 
            0xB884BB8BC0168630ULL, 0xB8F6F5B8CAA2232EULL, 0x6D460E614706E3AAULL, 0x89597A33C03EF7A2ULL, 
            0x8E2C28381B42601CULL, 0x3FC313BF02997AA7ULL, 0xEF67C9926854157BULL, 0x33662C9973127FB1ULL, 
            0xE47695FFF28C25D2ULL, 0x4BB46080E4CD4886ULL, 0x9FE51F8381986013ULL, 0x65BAA1896B6AC3A5ULL
        },
        {
            0x29568A9D1D46D977ULL, 0x94128FE00FC82A95ULL, 0x2B854142E896E0A8ULL, 0x626ABB1D81866082ULL, 
            0xB7C4A0E4ED5C1B63ULL, 0xDDB3C235378DF666ULL, 0xC8110370BA80CFF2ULL, 0x135317E820A1AA45ULL, 
            0xE7431FA9CF0C721DULL, 0x1CDC46C2F7CA9FDBULL, 0x0E95E8CE48ACD4D4ULL, 0x5FD3ECD1D7D85AC3ULL, 
            0xDA4995CE33A8B6C7ULL, 0xB90B3581E1C099C6ULL, 0x92A8C11A03DD70E5ULL, 0x5CD7C95584B5CD58ULL, 
            0x180157D0C21446EEULL, 0xAC00FD649D669629ULL, 0xB12E746D9EDA252CULL, 0x0E4E8212F3D88BF9ULL, 
            0x713232CD5309C969ULL, 0x7AE2263292F7C9B7ULL, 0x59A7786FE900C1C9ULL, 0xA243B26F3AA5B9EEULL, 
            0x54D2F38958B2C6CDULL, 0x6CC832B25F1E3671ULL, 0xD423F544D635314FULL, 0x305DA353D6BCBA9EULL, 
            0x6B1C12FF7656E1C7ULL, 0xBF46DDF3C77FFB11ULL, 0x1F0B7D3C1308B4ADULL, 0x35E75E357040EB5BULL
        }
    },
    {
        {
            0xEEE172140ED1B242ULL, 0x74AF17DB16F69BDEULL, 0x3BDDD3F4050D74EBULL, 0x87A95BD73AA5B8B8ULL, 
            0x723C801004B0419BULL, 0xA010DE459B704590ULL, 0x0B8DD88C46FA00CFULL, 0x171CBB6FC82A4E8AULL, 
            0xC1267DE507A3E04DULL, 0x8751FA878FFBBFB3ULL, 0xBED2F59199F9F052ULL, 0x6619C7BCE51179F0ULL, 
            0xD82C91DDF49D00BAULL, 0x3AF043BD936DD2ECULL, 0xA0727F06E6BC1DF7ULL, 0xAD016B19976CBD98ULL, 
            0x6952F779641D59B8ULL, 0x43A65273D9E5C455ULL, 0x3E3E3ACE12EC00E1ULL, 0x016B5B809528F7CDULL, 
            0x9F8B157326163179ULL, 0x78257B0465914C61ULL, 0xCD926AA5D0F38ECDULL, 0xF3B79777E6542D88ULL, 
            0x4BBC5E9354ACFD55ULL, 0x04DDDABE90CAD032ULL, 0xA8880D14BD9AE240ULL, 0xEDD73492F96263E9ULL, 
            0x74257DB9DDEF120CULL, 0xA626C3F02BB7976CULL, 0x4B77B160058D155BULL, 0x63A92421022CCC49ULL
        },
        {
            0xEDB50A8C06EE53B5ULL, 0x66B9A59A9E5CD2AFULL, 0x5DF43DB4E267B7D1ULL, 0x45DE23CC5C4C601AULL, 
            0xFFD2E881DF9453A9ULL, 0x0CD28B14DA527F06ULL, 0xD9ABBB1FE630C6BDULL, 0x1AB1B79B5665155DULL, 
            0x660A41BB6525B576ULL, 0x80E8F8C6932DE5D9ULL, 0xD2932EB3E7E91FABULL, 0x6050E1B048C3EFB5ULL, 
            0x1A0B433715464459ULL, 0xBF950BC134C6BD98ULL, 0xA883F25C1B75F43AULL, 0x20EC0F7BA88051B6ULL, 
            0xDE715504DB76014AULL, 0x1F2F5B1F48C24C14ULL, 0xFF45DB61D3A218A2ULL, 0xB6566E27F62C7DCDULL, 
            0xFD2BC30A73A228B4ULL, 0x57F12BFF95BB3960ULL, 0x002B24E41EBAE7CDULL, 0xAE69E3B8644EA0E6ULL, 
            0x93F50640C65EC2A5ULL, 0x696E6CC645058C0EULL, 0x948278DCC4DA7536ULL, 0x0A9C54CD42C9B5FEULL, 
            0x869B1046FA37EA86ULL, 0xF921C9C2EDA9E575ULL, 0x93130F243B37ED49ULL, 0xF617AFD413C44B4AULL
        },
        {
            0x4F08410D78BE1CF0ULL, 0x8F9462A7963D84C9ULL, 0x437829722485E01DULL, 0xD0C937887C5DBF95ULL, 
            0xF95D4EE98EE47449ULL, 0xE0E466B00BF1517BULL, 0x004AC82FFF95EA19ULL, 0x35CF017B09AC47E4ULL, 
            0x44F9491E33C7CC6BULL, 0x9CDB99CAD8DD3CAAULL, 0x1FCB5F783AEC2D49ULL, 0xC566951764168B12ULL, 
            0xE6E93060E5B6BD12ULL, 0x6BFF718CB2CAA4B9ULL, 0x0055029D4FCBFBDBULL, 0xE0ECD10CC7E58CEBULL, 
            0x5ED8A7580BA81BEBULL, 0xFCDDCAD1FB17024EULL, 0x4E29C6399988E016ULL, 0xB87E2EC620508748ULL, 
            0x1D8B6E211CB1F11CULL, 0x7D1BA1555A94A9ECULL, 0x6443E54549969548ULL, 0x3D482F7DD3DD729BULL, 
            0x016E585E561565E4ULL, 0x24C39291BCCC202DULL, 0xB4234D7C82F959D8ULL, 0xFC39200B1A4E7C6FULL, 
            0x7206B09AD6274379ULL, 0xF42F0960546C7E7FULL, 0xA47DB49CD73DE54CULL, 0x1577988FFB066C67ULL
        },
        {
            0x12CF2EA8F30E9831ULL, 0x6612340ED1A6DDD3ULL, 0xD7E390212C745743ULL, 0x5C2CE1740780F766ULL, 
            0x16A87369C76995ACULL, 0xA959FEF798DD63C4ULL, 0x7B803804E3B324ABULL, 0xFACB7CFEC60BFF58ULL, 
            0x6821B9F6E683F55EULL, 0x47E991B7C4B10281ULL, 0xA76F30BDFE66021CULL, 0xB4EAF697A0D4F7B2ULL, 
            0x1D11254C624FB4A5ULL, 0x9C455D6FA707B2DAULL, 0x1B21BF8CB6B38135ULL, 0x71BD0D6084A3B945ULL, 
            0x977EBD00A4FE2F13ULL, 0x928181B4CF1EA4D4ULL, 0xB1F656760F9DED98ULL, 0x9234A35CC5D8374BULL, 
            0x9524555B3D2D9B0BULL, 0x449E7016BF5D3DD8ULL, 0x79A3E3BF34F91B5BULL, 0xAB6AA092F451DDFCULL, 
            0x98958B88AE4F8C6FULL, 0x0A7BEDDD932E14ECULL, 0x3E50D9CD5962214AULL, 0x076A989D42AE5585ULL, 
            0x3712981DB5C0EC24ULL, 0xE5E53251A0DA4127ULL, 0x0CE73AD1EF376ECBULL, 0x962E61507F4962E3ULL
        },
        {
            0x341F2BE6DA630BD0ULL, 0x69F86E7D998588D4ULL, 0xB20CAD311DAF1990ULL, 0xEDE39F5E2774DC3DULL, 
            0xB8056B0BBAC8858CULL, 0xB0DA558B3A536F5AULL, 0x0EFEE90C50C85DF2ULL, 0x18C14A6F2744ACEDULL, 
            0xA1F7196885CC90E6ULL, 0x812604D8BDFE2FEBULL, 0x93EA1C1A99911F85ULL, 0xB61180960413D761ULL, 
            0x3DB7D2F0E1184D82ULL, 0xED15CA51E4163104ULL, 0x03D11B90C09C7B1BULL, 0xB1CCE8F46116015CULL, 
            0x2E3403B67367DBA4ULL, 0xB3C0BCA791780269ULL, 0x8B809A350FE59146ULL, 0x61CCAAC802A8A165ULL, 
            0xE51591C9BBCAF51EULL, 0xA3DAAA8FF9C3C06FULL, 0x2E75B5BB1B9A2F6BULL, 0xF06B20622F2FC4E2ULL, 
            0x9A4274D4DF71A21EULL, 0x1C1E506068431267ULL, 0x2786618C709047BAULL, 0xEEF826F5C788D12AULL, 
            0xD682648F177EBF88ULL, 0x6D704B3362646F61ULL, 0x62BC132651821C74ULL, 0x4D0EEF4D699DE607ULL
        },
        {
            0x9450111D6E8036AFULL, 0x34F3DDB708AB53CFULL, 0xC523BCD40F6688F9ULL, 0x0EBA17F988B9365CULL, 
            0x239381816AAC9BA5ULL, 0x287F6B4DEFC13F33ULL, 0x010F862108D9D476ULL, 0x63A93235C4F69CFCULL, 
            0xD1637090565BF5CDULL, 0xCC80BFB3430A6079ULL, 0x823D5D285170E227ULL, 0x8C07D20A1E295BC7ULL, 
            0x9EDEA241CA3F2B6CULL, 0x5EA90F840C0ED35FULL, 0x435F24A9FDED7F40ULL, 0x0802043E1C9C398AULL, 
            0xBBE025AD120F8534ULL, 0x51B9280B095620D9ULL, 0x401759D9E47BC6B2ULL, 0x9194235C70B4A345ULL, 
            0xB084ADB750A5745EULL, 0xA89265B533EE839FULL, 0xEE52EF5D1750F157ULL, 0x5AE988FD49F8FFA8ULL, 
            0x9CFEFED062FFE121ULL, 0x41C80EAE3DE74273ULL, 0xE2A16D877ECB26CAULL, 0xAC28E9B1CE2AEFA6ULL, 
            0xCF04E3B785CFE8BBULL, 0xF5A3B4E16E19AFD0ULL, 0xE10ED8ED094FE0FAULL, 0xC7C02C95B64E7E24ULL
        }
    },
    {
        {
            0xB5179981AF6E4289ULL, 0x9A7500F9DE4A2DB6ULL, 0x3BC913FCDBACBA0DULL, 0x4AD51CBA002C5DDCULL, 
            0xF6718A8AC5D69D3DULL, 0x07389B5431484D56ULL, 0x8F399DEF62B19593ULL, 0xD0F6610972A92CA0ULL, 
            0xCF59BF642A1C8A61ULL, 0x518FD01FB39DA7D8ULL, 0x52D0D10479CCF3F0ULL, 0xCE91ADA20AF0CCC2ULL, 
            0x41E14D4950E2FA79ULL, 0x8B639EF29B12D42BULL, 0xA0AE685DE4AE861AULL, 0xF52C7F43ACDE9592ULL, 
            0x40309AE496228922ULL, 0xE4620DA9FBE4DC83ULL, 0xB1F3401F80A089D8ULL, 0x1A262C5EF0803D0DULL, 
            0xEFBDE9E6CAF090F0ULL, 0x57704FAE0D3D89A4ULL, 0xD371C2B77D00B4EFULL, 0x8BA3EB04BDCBCCF9ULL, 
            0x48A95A935469E48EULL, 0x9E5EB771C62AF02BULL, 0xFE6C9E55283B0EC0ULL, 0xE102A16F82C4B0BBULL, 
            0x460E7CC1DF73ABE8ULL, 0x0518B41D4EAD46C8ULL, 0x014380BC5F2C965CULL, 0x2486ABE8E07471F8ULL
        },
        {
            0x12782DE589324498ULL, 0xAE51F5A8846A5584ULL, 0x6245A92364E6A45BULL, 0xE5CE99A315504BAEULL, 
            0x020C78CBB827883BULL, 0x78C4819BB4C87299ULL, 0x8D210C25448EC85CULL, 0xF077843EC3F00272ULL, 
            0xF7C1F4E2D2F2CECFULL, 0xC58D9F8DED575EBBULL, 0x55DF78AF2550CEE3ULL, 0xCB8B96D18B7D60CDULL, 
            0xDAEAFCACA960E9A6ULL, 0x5E8B37445AF97AA7ULL, 0x6F3E853FA12E7A03ULL, 0x6D8C77CF2521EED5ULL, 
            0xCAA83F6DCCA49297ULL, 0x74A76CCEDA008519ULL, 0xE3B75A7D6049A537ULL, 0xE275AE788C583E8AULL, 
            0x2FACD6A1B87F72D7ULL, 0x61BEB78CDBDA5B92ULL, 0x9878768A1D473F65ULL, 0x44EDA0665BF099F9ULL, 
            0xF98C72458778B364ULL, 0xF03DF7FB6E5C6184ULL, 0xF268483CBC7BABDBULL, 0x349DAB5700A8EE58ULL, 
            0x3D9D94A637BFACC6ULL, 0x1F90B7FA334FEA58ULL, 0x681EA45E269A4058ULL, 0xF1A498267348DA24ULL
        },
        {
            0xC7BDEF78147E029FULL, 0x147FA018F8C72011ULL, 0x5D60594957A63175ULL, 0x77F018D3117CE59DULL, 
            0x7AE9DD353891F7D6ULL, 0x8F320268643959EDULL, 0x90180C5C4DAD4A5DULL, 0x468392D363E1EFE7ULL, 
            0xDDB1258FE249F605ULL, 0xA435DC432B3D0999ULL, 0x5F97E7D678E8957CULL, 0xDCE2337586B918A9ULL, 
            0xEEDDBEAA089CD7AAULL, 0xA6B7DC6BF4CE30CBULL, 0x2457EA37A1D8249AULL, 0xCD75774C60A9254FULL, 
            0x6C8590CC383CC224ULL, 0x33F413D916726FC7ULL, 0x1AC6911C28F4007CULL, 0x0E4BC314C3165CACULL, 
            0xF70E05581247918CULL, 0xD310B66A18741589ULL, 0x80140F5160AAAE3AULL, 0x1F04DF913DC9B0B2ULL, 
            0x2ED5565DD9FF0033ULL, 0x8F9D5F7F5180C877ULL, 0x7575D84E7B89CF66ULL, 0x28D24B386A6A5521ULL, 
            0xC98C2ADC69ADA01CULL, 0x272EDCD516D8125FULL, 0x5267947620912DBBULL, 0xB3C8C4DB5408DE15ULL
        },
        {
            0x570DA2A062ED0AC4ULL, 0x74E62AEFC984E69FULL, 0xA6F00F6217407507ULL, 0xEACD1080315F889CULL, 
            0x0219D15BF4B5FF83ULL, 0x756218F04A74E66BULL, 0x5DD9A337C00D52F3ULL, 0x2ACC68696E8C47C8ULL, 
            0x0A3C77CF7BDE1E87ULL, 0x47453547723B7348ULL, 0x9AE50EFA86AD86BBULL, 0x1F02E1C7294B8BB8ULL, 
            0x1E01EB5F82106DFEULL, 0xE723AE5293A42648ULL, 0x6F8F72083B89C27EULL, 0x4F408B6A8A611C7CULL, 
            0xA43CBF9F35869B2AULL, 0x506E3AA7148BC704ULL, 0x7E12B25B979B7F2BULL, 0x8B9AF1059F716111ULL, 
            0x1F7834D55C2F50B8ULL, 0xB0A27F165D4EEED3ULL, 0x8911928693BD4ABBULL, 0x605550DB0A927E79ULL, 
            0x5BC7863ADF5C0521ULL, 0x61109D31AA4FE01FULL, 0x70725310B6CA4F17ULL, 0xB3755481DDCDE728ULL, 
            0xE7F93630C347F909ULL, 0x3FF56C01AE9AF22AULL, 0x4E746CB99843ACACULL, 0x8041CB636288D17DULL
        },
        {
            0x6ED20E1AFD92C940ULL, 0x717DAC1EDE83E431ULL, 0x64AC2672C77BFBF2ULL, 0x59BA98C20EF1AF3CULL, 
            0x3C7E2B6E36692947ULL, 0xACFDB605C6D9DD57ULL, 0xAA66429B66B5F7D8ULL, 0x02FB5CF37FF18B1DULL, 
            0xA97F65F1942234C8ULL, 0x2B80C86C9C68F6EDULL, 0xA9783D47BD9BE8A9ULL, 0x444F55F413DE69A6ULL, 
            0x062C4D391AFE51B7ULL, 0x9A08F02FB0D91D8FULL, 0xFAC913281DA714D2ULL, 0xDE5408E7256C02B8ULL, 
            0xDD5951F3881F745BULL, 0x1515A7721E1C31B9ULL, 0x1177FB275C90857DULL, 0x320D358C56723FAEULL, 
            0x28C3C84131F69733ULL, 0x787D123737219D0EULL, 0x843BC8CE043EDBE6ULL, 0x243362EA68ED8EBFULL, 
            0xC544DBFAE1464CE4ULL, 0x6C9C1061EA51E5D6ULL, 0xCF903B0646F5D752ULL, 0x20144D2916F5B6BDULL, 
            0x350C70C3E831ACD6ULL, 0xBD7EC206425BAC95ULL, 0x82EE16F582588CA2ULL, 0xCE37149914FEC3CEULL
        },
        {
            0x681186858FBFE85DULL, 0x243E15574A51B81AULL, 0xF7AB98BA6CD2FDCAULL, 0xA8EDEF6DFB7DF839ULL, 
            0xFADE7F3C69CDBF1BULL, 0x444D13C9599FB646ULL, 0xF3383598FB3531F5ULL, 0x3ABB905443974B1BULL, 
            0x9474CBF4C3ED7D97ULL, 0x31238DF40CD7A209ULL, 0xEB23A6AF248125B8ULL, 0x7EAE440561D219D2ULL, 
            0x8B6AEA5558E48F3FULL, 0xCA7E79150EB24197ULL, 0x1ECC3C329D869D5FULL, 0x48CCF475BB2E1A97ULL, 
            0x4E1B5A116528C58EULL, 0x01428218057C0086ULL, 0xF58080E733E9A6A7ULL, 0x4DACE8FC959BEA6AULL, 
            0x8AEEEB2F5CA119D0ULL, 0x76D8CAFFA3AC10D5ULL, 0x4179FE9EF63F6F5FULL, 0x72DD21F342875E74ULL, 
            0x940B7D8A8F02895AULL, 0x0BAFADB12F5A4159ULL, 0xD4B69BFA7757E9D0ULL, 0x17EE4D3AF2EF0937ULL, 
            0x4AB8F42C52C1F171ULL, 0x6760F0B604BA8851ULL, 0xF01AAABAF6B476CCULL, 0xCBB409C73CFD2022ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseCConstants = {
    0x46130DF9F83C3FE1ULL,
    0x5F9BEDD3D73E5491ULL,
    0xB232132360AF5F0AULL,
    0x46130DF9F83C3FE1ULL,
    0x5F9BEDD3D73E5491ULL,
    0xB232132360AF5F0AULL,
    0xAFC7B86D749E4431ULL,
    0x71C2D0FBA6DBC15AULL,
    0x81,
    0xC5,
    0xE3,
    0xD0,
    0x75,
    0xC3,
    0x8E,
    0xB4
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseDSalts = {
    {
        {
            0x2EC3BB0FA32C0B08ULL, 0x23094E64D6447C49ULL, 0xD7CD56610B6220CAULL, 0xDBF8F2C8ABD463CBULL, 
            0xB2B48110059A21DFULL, 0xB45CC3334E7D9CADULL, 0x78A66E6BFEDC8A5BULL, 0xF81E63302EC21441ULL, 
            0xA0207FEB67DAD733ULL, 0xF4F1E7D156AFFF2FULL, 0xBD9E6E49E766D30AULL, 0x2B409EDFEA84E8D1ULL, 
            0x4971819903164FAAULL, 0xA605F7DA6AFCEE5DULL, 0x75C75AEFEE890923ULL, 0x13B3BEFF6CB13BD1ULL, 
            0x12CFF396DEE7FE48ULL, 0x6420AFC12D8A5A7BULL, 0xA477DA35C70EBDE3ULL, 0x022E16A25B3D0DACULL, 
            0xA6369EFAA93D3BFBULL, 0xA4B21DFC79F4EE95ULL, 0xC31B801568593BCBULL, 0x8BFEC973EA50D751ULL, 
            0x26D6BE104612270AULL, 0x29F01B39A4646C20ULL, 0xF7812FEAFC363412ULL, 0x05100A63F90D7886ULL, 
            0xA87E09DBC29CE50FULL, 0x6BECB5F7758B92C0ULL, 0xA0391B12F1E5D625ULL, 0x4EF2ECA59415184AULL
        },
        {
            0xD849A35139FF6A47ULL, 0x0AF1BEA91D0047A1ULL, 0xBF8A678EED52A533ULL, 0xDCF4EC32DDDFEBE8ULL, 
            0xED4C37F6DACA9FE8ULL, 0x312F8DDB77857C93ULL, 0x1D9211EBD8235D8CULL, 0x8830143079FE2282ULL, 
            0xBBBD73EA45B3687AULL, 0x48F68E247154F990ULL, 0x69744660EEA5F453ULL, 0x622EEB1A483916EBULL, 
            0xC71C2339EA53B327ULL, 0x3DC6E7279053C09EULL, 0x8F3C478AD5FAE4D6ULL, 0xFC1EF52B1A58E26BULL, 
            0x77F428B5BDC0C84AULL, 0x2FAE0B7DF35919A8ULL, 0x9D14D7E29082C5F8ULL, 0x67BB0D836461D00FULL, 
            0xAE10556CDA5602E5ULL, 0x52111F65755D9C04ULL, 0x52D4B5A61786E5E9ULL, 0xC3D320F2919AD764ULL, 
            0x397D319D9F8329C0ULL, 0x8F6C4992A660092FULL, 0xE13613D2E14DA3F2ULL, 0xD1AB6F5EE11DFAE2ULL, 
            0x947D577B521B53CBULL, 0x2ED902A05AB683E7ULL, 0x72BA2F25EB6C10AEULL, 0x1061EAAC2036A535ULL
        },
        {
            0xBAC36764C75D8357ULL, 0x24EFC0A5B7001CC6ULL, 0x875E09862CC8EE0CULL, 0x5C7157B6380985D3ULL, 
            0x788FDA6775D84765ULL, 0x420A265F2D3C5281ULL, 0x82C3ABDB0F789C67ULL, 0xA2F49D9A7A1B46A7ULL, 
            0x3A20CAFC496EAF8FULL, 0xD83CE79953E2E390ULL, 0x65385AEEAFE83419ULL, 0x3E465E5F16ED0EEBULL, 
            0x42996118D105E22CULL, 0x4B6708EB749A4E2AULL, 0xF4634EC6225B6C72ULL, 0x3EA8B4E671DDA463ULL, 
            0xE9B56EF1F018EC6DULL, 0x1790541682DDC301ULL, 0x1BFEC9D122C0CA44ULL, 0xCF8B6BB72BFC354EULL, 
            0x172848F97212D313ULL, 0xB92EA409CF2E48B4ULL, 0x2EE1B5EE915301A2ULL, 0x49FBBA78F9A43AACULL, 
            0x3A164E06608B2D03ULL, 0xEA892EF13A2B3A87ULL, 0xF446F1038A7FF6D0ULL, 0xD0396D0DC8E12EA3ULL, 
            0x65C9D691CC4E0D39ULL, 0xBAD7A7C23E3E2485ULL, 0x6BA8D92AB2F658BEULL, 0x1199D0F84571ED97ULL
        },
        {
            0x0F2D0A9975D4A478ULL, 0xB89DADA518BF80DDULL, 0x700EDDE9663D40C9ULL, 0x16206FA27EE010BDULL, 
            0xD91703C96888D66EULL, 0x81B5A922858949AFULL, 0x0EB9CEC8190B58D7ULL, 0xA4721026557DCCA8ULL, 
            0xBEC40723BED3B938ULL, 0xAE97D2C887E58C08ULL, 0xF5BC647D4EA036A2ULL, 0x0260EC156CA0EE0CULL, 
            0xC1CFE2C1D8C782C5ULL, 0xF936F7C6494B83A4ULL, 0x3C83B28DCA569499ULL, 0x72CEA7ECD2CF2B8DULL, 
            0x511960EB2F459D9EULL, 0x2F6E6EB8D83B4D78ULL, 0x0F30BFFD119CAF1AULL, 0x7075894905EFCC5BULL, 
            0xAFE1A98AFA3ACD88ULL, 0xFE17795A9C73E533ULL, 0xE368C27C65AE102EULL, 0x47D310246092505AULL, 
            0x5688A224E02C8AE2ULL, 0xCB24C0A5D612CD33ULL, 0x18FD6B9C9CA14915ULL, 0xDAE596436C8E753AULL, 
            0x47F1007F85845A64ULL, 0x66B1595A28E7B706ULL, 0x2FEE88DD1B11D3E8ULL, 0xB094CD1F4263155BULL
        },
        {
            0x4AED53B3F1804FD0ULL, 0x58DC7AB37CBFB1DFULL, 0xD3AF7BB2E78747CDULL, 0x301C87796E7E0207ULL, 
            0x0281DCAF1A2A10E1ULL, 0x3147B9593FC3132FULL, 0x6B8B063FB9979009ULL, 0x21B9656893CB7DD8ULL, 
            0xB4D36FD8CFD7B4CDULL, 0xF0E1C61FF62D6766ULL, 0x3A3CDE43D9D878ACULL, 0xABE73225DBF00042ULL, 
            0x5C1D13CD77DA7CE4ULL, 0xBE972156DAD8FCE6ULL, 0xE69942DE19C7890FULL, 0x6F5DDC660B0709D6ULL, 
            0x7A2D81B6F648E2F2ULL, 0x363D2C94CDB4EF00ULL, 0x265BEC8E461A9EFEULL, 0xA156D77E77C80BF1ULL, 
            0x1AC9BC1B719663A8ULL, 0x0BF054B692A84B9FULL, 0x9855EAD3A4C90AB5ULL, 0x2E9FE1F7A3FEAACEULL, 
            0x067EAADCCE404F81ULL, 0x6BE26043332205FBULL, 0x368E6AA52C6EF83AULL, 0x1A199B0280BC60B7ULL, 
            0x848ED4DEA7681195ULL, 0xE549C32BF8BC999FULL, 0x33FB08E423EA3CA8ULL, 0xE9AA8F702F89E96EULL
        },
        {
            0x1E58B3D3C95EC99DULL, 0xFF48C721491B529BULL, 0x974342EB1197D521ULL, 0x0768D2795A36542DULL, 
            0x92F2F5C7B2D4F351ULL, 0x5693EF53B65CF987ULL, 0xED504EFBC5ACF73EULL, 0x2B788B0FFA6EC40CULL, 
            0xE1F7E21807560496ULL, 0xA87831E155AF1A34ULL, 0xFDFB3D475B1D8683ULL, 0x4C0068E30087FA1FULL, 
            0xE770DA68D93DA491ULL, 0x477C0CC87BDDE615ULL, 0xBC0A5436773388A9ULL, 0x55D54BBF6DE8D921ULL, 
            0xB6C3504B5F4F5A98ULL, 0xE3A91914D57DC93EULL, 0x229B880435840825ULL, 0xB2271B6AAC4A5AADULL, 
            0x6A1FF07E83279014ULL, 0x11C815CED2D5A79AULL, 0xAC199BC0F1D544C3ULL, 0x6A3D9DD03164058BULL, 
            0x51E4B42B34A8122FULL, 0x4634CF876DD2EA0FULL, 0xED2B1FCF356860E6ULL, 0xE4D5BD11C0B2F9A2ULL, 
            0x798D5D6C88707154ULL, 0x0C4A1CC5B5373549ULL, 0x30F3009F29694C63ULL, 0xE5D44348666BA4BBULL
        }
    },
    {
        {
            0x0AC0E4123FA70744ULL, 0xE4086A02CC972F6AULL, 0xE89AE4F7C53D7815ULL, 0xB3421B7B7F3AC596ULL, 
            0x09ACED4DA4EB596EULL, 0xA5361BDF784108F1ULL, 0x4EE11C5FBA037A0EULL, 0xA535F5A4ED15E0D3ULL, 
            0x76704DC35171CF72ULL, 0x74A7A22D3C7260C9ULL, 0x92BA2644B6FAD659ULL, 0x8367C477498AF9A0ULL, 
            0xF9705EF4BA92C3DFULL, 0x858D3F1777860C6CULL, 0x50016038A9596C09ULL, 0xEB9410AACED919A8ULL, 
            0x5975FB057BDF144CULL, 0x246D56E558D0EF35ULL, 0x5C98778B2F49955AULL, 0xDA0F880DFEB4BD4BULL, 
            0x49473BD26DAC20CFULL, 0xCFC6303BA8999DCCULL, 0x744C7624E6B28400ULL, 0x1BCE6DC3143E865EULL, 
            0x410233B48E23ED6CULL, 0x0A0D059D4AABABC6ULL, 0x09C9DF95BB885563ULL, 0x481B4DEF4BD2778FULL, 
            0xD7B593669DBE3FA8ULL, 0x62BFD095C1441303ULL, 0x35A7362A2A18262EULL, 0xF6235B673276D74EULL
        },
        {
            0xDB50331BF9EF4CEAULL, 0xD5D7373C36B76EF2ULL, 0x76AE544B37133F8BULL, 0x4720FD1D2D1CCFEFULL, 
            0x5D8617D85182D7DAULL, 0x0B826F87C1B0A9DDULL, 0xD05A7A1E6DF82DA0ULL, 0xEFF8B0AED0D1A457ULL, 
            0x3E2920C486160A9AULL, 0x7EFD8065281FA458ULL, 0x511A4DCC6074D464ULL, 0x00E865F77ABF8F3FULL, 
            0x30AE39C92E8A8A17ULL, 0x00128EC258FE1D0FULL, 0x8B155050906298FEULL, 0x43739433B3BE4635ULL, 
            0x3BB898A9F2913277ULL, 0xD9EE2FB3B8E869E7ULL, 0xD1F0CB298CE42881ULL, 0x8667905AD5E66E06ULL, 
            0x655EFA1136D19FD9ULL, 0x4FB9AF7F712A5151ULL, 0x05A3E71ADF7065D9ULL, 0x733F2519F33CDD5DULL, 
            0xFBF35E35EF32EF2CULL, 0x885F34CA816A6174ULL, 0xD11A81FC9344F29EULL, 0xFB8397DB5D5CE677ULL, 
            0xC77DEA7CCEEC7BC6ULL, 0xCB8C17CECAD47411ULL, 0xFFFDBC8222A30A0DULL, 0x09F6EFEF61FFD973ULL
        },
        {
            0x4F7BA0F6DF28B3F5ULL, 0xA17EF54B59EE77E0ULL, 0xCFA4D55C592B0FC1ULL, 0x21070DF52FB187E2ULL, 
            0x1AAD38A8C10F877BULL, 0xD8E3BA8FF604C94DULL, 0xF7C2F312F7661D1BULL, 0xA5B6C413C8A89B3BULL, 
            0xB21FB4005DD7BF72ULL, 0x416A18CBF4E1F421ULL, 0x700C6AD3EE529FB6ULL, 0x9CBF6D8D27C67789ULL, 
            0x36791E2CADB72E34ULL, 0x3D674051E67EAA41ULL, 0xE7A3D101DBB96B54ULL, 0x255FBB7AC941A9A5ULL, 
            0x33194A1726419F98ULL, 0x4F0821386B1831B6ULL, 0x5EFA56AAAD7720F8ULL, 0x446B336641B84308ULL, 
            0xA872C8AD2784E505ULL, 0x4ED45AF55B40A542ULL, 0x9CF701DEEFA50976ULL, 0x66097D70C8526D2EULL, 
            0x72F6CB8FEFC7B81DULL, 0xEC2B2D45A5852582ULL, 0x8AA1AD0E9D64D8DDULL, 0x77586584C97060AEULL, 
            0x57CD5BFCBC289333ULL, 0x77C68C8CE16FA87FULL, 0x5722EB9F5DEB662AULL, 0x43D72822E03CFEA9ULL
        },
        {
            0x5555A5B4A1FDE2D2ULL, 0xA3775F50BEDC8BDDULL, 0xEE3CB4BCC8D09217ULL, 0x1ACD9948B927D812ULL, 
            0xB6492697592D4C39ULL, 0xA0702319554EA3CBULL, 0xF454AF7E2702EE1AULL, 0x6E181E487554866DULL, 
            0x7FE91B76D325D2F5ULL, 0xB44A77E98DDC93C7ULL, 0x764204A34F754370ULL, 0xD644A629AEC1B069ULL, 
            0xB6C11CDDA1DABF4DULL, 0x4EEF68BC06C09237ULL, 0xE303112878549082ULL, 0x066489CB83ED5B08ULL, 
            0x7D1BD0A44330F364ULL, 0xF90CB3846B500B31ULL, 0xEA3C97425BB11F68ULL, 0x9B8B0315B579B6D8ULL, 
            0x1BFD809D699BAFE2ULL, 0x2F0A9164A1B375BBULL, 0xB9D0063DFF9A2C37ULL, 0x6E5D9DBFBA5CF9B2ULL, 
            0xDADFE1D61F2331A1ULL, 0x3D2A074C81E6E167ULL, 0x219DDB5AFA70D2E3ULL, 0xF4EB237A69E1FA57ULL, 
            0x09BDB609501319CFULL, 0xCC0CF30934A602F5ULL, 0x76D63A7555A2D38EULL, 0xFA29632D57E951A5ULL
        },
        {
            0x219E7A61B48C217BULL, 0xC5D9876C18D50AB5ULL, 0x47ECA39FD20235CFULL, 0x4931002AEA283895ULL, 
            0xCD533B1EE0CB2D90ULL, 0x0B68C16D53EB631BULL, 0xCAEEC1A34DCD1FBAULL, 0x5215D6D81899ED3FULL, 
            0xD2EABC611DE14C18ULL, 0x626C1A0F1C6375DAULL, 0x568A78B2F72DE5C9ULL, 0x82BC05EBCD892FD3ULL, 
            0x4D571ECA33D1B5E8ULL, 0x87AD60A47ED3F8DCULL, 0xEB1B48D10B380373ULL, 0x5B5A3CDAA8CAB115ULL, 
            0x363C460F3DD03C84ULL, 0x5760EABC0EE22B6AULL, 0x3AF1AF1B9756F764ULL, 0x44B6F026C83D3C8DULL, 
            0x8463179B17B47FFAULL, 0xF07E2901C78F453CULL, 0x38246E079208F98AULL, 0xA397F11453436210ULL, 
            0xF6E37991DBA7663CULL, 0x6E73DE54798D6771ULL, 0x3EFF5ABF0FFC82F2ULL, 0xFDE8119DC9297E36ULL, 
            0xFE39352849B41AEFULL, 0x27237BE931A60A71ULL, 0x9AC9F09AE1216D63ULL, 0x9E076DFB19344212ULL
        },
        {
            0x2276085B480B905AULL, 0xCB6E26D8B3553CC1ULL, 0xEF0A129D55E85A51ULL, 0xDCCDD58279FB7768ULL, 
            0xEB7A231639485B61ULL, 0x7E342F60BFA1BBCAULL, 0x9DF2CDBF9D96F55EULL, 0x379D64F57BA09844ULL, 
            0x215405B5F27BA8DFULL, 0x8C2303A4ABB85B63ULL, 0xC72A993ED8330421ULL, 0x2D69A6BCF290FC68ULL, 
            0x30CA1C8FE9C17F18ULL, 0x43B20EE3EAFB8ABAULL, 0x696D28F58D9E25B0ULL, 0x29F0EC31F986E4B7ULL, 
            0xBB594346082F3017ULL, 0xDB8D8B4840CDD85BULL, 0x4CABDD74EE10EDD4ULL, 0x3DCD5EC4FD267DA5ULL, 
            0x8DD360B7037A2663ULL, 0xA1C0850440E2FF4CULL, 0xE6DAD3AB5BD7D4D4ULL, 0x605390986EFE29AEULL, 
            0x8D725CFE0E47AFCCULL, 0xB9E4F0B931BB865EULL, 0x6C852ED596AB7428ULL, 0x1D0A0A0C1C17C577ULL, 
            0xA35BCF43D60532BEULL, 0x535C4EE68CD086C0ULL, 0xF18A2C57E33DF398ULL, 0xCB76E81A32CE5D06ULL
        }
    },
    {
        {
            0xD3CD96832A936FF5ULL, 0xD0369ADE4C601809ULL, 0x360709B5D253C7D4ULL, 0x7076222EB62CB29FULL, 
            0xE1883F079F53E85AULL, 0xA7D377E95448917FULL, 0x61071E40084AAD25ULL, 0xEF57AF9C0BE6B729ULL, 
            0xB1E3BBC3AEE51698ULL, 0x0DAA130AAC65BFEEULL, 0x8B72B9A4349341FEULL, 0x36961C8F186FE204ULL, 
            0x3F182A6F7A2F32ADULL, 0xA94859AE30B4C988ULL, 0x2AAE9AA4D07ACF6FULL, 0x506C03F4BEC36795ULL, 
            0x80616B27015A9D38ULL, 0xF0FFA5C05DF07AE2ULL, 0x3864C3CCC325E4F3ULL, 0x0E0A4B7A0FCFA413ULL, 
            0x6378844337E8E3DCULL, 0xDA15730D6697C7DFULL, 0x472554C5B1F9F911ULL, 0xA9777B1738AB3701ULL, 
            0x439E32F7A06DACC8ULL, 0x88E8372B2FEDAB54ULL, 0xE6D1BCB10C45CD07ULL, 0x4060F246523872E6ULL, 
            0xEAC81DAB540EB2A9ULL, 0x8ABFCBB1F79E70B2ULL, 0xCAAA89A1D4E382EAULL, 0x11721EAACAE22663ULL
        },
        {
            0xB42BDD0105FDD7C3ULL, 0x7696D138C5A8EC5CULL, 0x56C1DCBC90D9A6CAULL, 0x19A4A46FCBD2DDE1ULL, 
            0x707D20B102A8C1A6ULL, 0xA698F06D1DE411EEULL, 0xB5DB77DE5A0686FBULL, 0x72FAA408977F6211ULL, 
            0xCAA7E11B13C8F351ULL, 0x655C938A63BBC6F3ULL, 0x8B9A277CDD87D209ULL, 0x3CBE07E078109625ULL, 
            0x654CC250DC804F3AULL, 0x301B9C18EE9010A3ULL, 0xB988B8967469D6B9ULL, 0x02CCF519D6BFF5CDULL, 
            0x2CE9446297302431ULL, 0x5790FA59B38D2B2BULL, 0x494062F1D4DD2D38ULL, 0xB3EB2E80022158F9ULL, 
            0xFDF7F3C796C8801BULL, 0x603DBC1EAA5EDAFFULL, 0x8661078383BBC158ULL, 0x4E946BB16B6D3E9BULL, 
            0x5D3F9DAC76D2EC12ULL, 0x825AD764D9A25879ULL, 0xA5DA5CAC012B632CULL, 0x84C5B6FD9503CACBULL, 
            0x522E241156976CC0ULL, 0x72D7927B9D91896EULL, 0xDA5C3E4B28FD6F58ULL, 0x21DAB37185B06021ULL
        },
        {
            0x6B44C6BF8BDB0AAAULL, 0xAA941726F64ADE6FULL, 0x42F8FCBB129520ABULL, 0xA2A998456815F11EULL, 
            0x12BC39AC3F422C38ULL, 0xDFF56196F52ADEFDULL, 0x42369FAEECCB9DF9ULL, 0x2E5ACC1BDD6D2CA9ULL, 
            0xB33963FFEB899431ULL, 0xD278E9FD3CE9DE51ULL, 0x75451EA25ED37691ULL, 0x497856EDE446EE39ULL, 
            0xCB425E14D04394A0ULL, 0x504467DB102BDAE1ULL, 0x22DD7A24F745885AULL, 0xDB6335DDE43902B4ULL, 
            0x8ADCAD337070D364ULL, 0xDBED28603532DAB0ULL, 0x6DCA8BAF707E4618ULL, 0xC34E85044F65298EULL, 
            0xF528F6B348D274E3ULL, 0x9B3B8FDB1305AFC2ULL, 0x83F33BB16D79FD31ULL, 0xFD51472459292E18ULL, 
            0x16E22927EEEA53CCULL, 0xE6C4C9D4E1270663ULL, 0x31A5E98DFCA02ECDULL, 0xABCD251B249ED999ULL, 
            0xC7B4E7672D38F4C0ULL, 0x72B9670BC6B5D4B7ULL, 0x90EC6468F4758428ULL, 0x09C9CD566E279F13ULL
        },
        {
            0xBAD61ED4DA1801C8ULL, 0xF1203C695AB8118AULL, 0xB58353F538230A1DULL, 0xF98E57D417BADD5EULL, 
            0xA0F9BF7D962C1D92ULL, 0xD6C1D99ED2959FDDULL, 0x98BEC32005D2305DULL, 0x15F335BE5732621FULL, 
            0x312CDD67C26E9208ULL, 0x213B29ED049821FDULL, 0x4D50CB489252BCD4ULL, 0x0251335F86A57051ULL, 
            0x40D6827CF4C78067ULL, 0x289F720C6462AC85ULL, 0x5C81E0B0952FBA77ULL, 0xB292EAB568CD3311ULL, 
            0x1F919307343B16A9ULL, 0x50B6273346A892D8ULL, 0xB55664EA41D7E8F3ULL, 0x45A468F81B21EF43ULL, 
            0x593826566AEDA0BCULL, 0x99CFD65DC75E6472ULL, 0xE33F94F65E52B94BULL, 0x139B403C7032156BULL, 
            0xBBD76F9B7E317DFFULL, 0x58CC02B8F198EC9FULL, 0xF2BE4903EFFE2C7BULL, 0x2A3186DBB9483830ULL, 
            0xBE34D0CF70DFCC05ULL, 0x7636122DEB66BEFBULL, 0x4B1B8D6B2BD0849FULL, 0xB5529FC561152978ULL
        },
        {
            0x82B9B89A2CA827CFULL, 0xF668D5F851F2385FULL, 0x183B472887204D31ULL, 0x420AD1559126B22DULL, 
            0x15A182E8663733DEULL, 0xE73D9DF3BFEF0797ULL, 0xE20D323B5B5CABBEULL, 0x1E6E6D3D2598130FULL, 
            0x46E344821732CD3CULL, 0xE066CDC95D4BF884ULL, 0x098A962AD72BBCE0ULL, 0x5EBA4C47FEFF47D6ULL, 
            0x344342A26125DFDAULL, 0xDCECA7CCA9C8E8B7ULL, 0x263CDB5434A0D2A0ULL, 0x97596650A63B7C66ULL, 
            0x065321503890EB7AULL, 0x85C1C6A16DEC200FULL, 0xBCC5AF825598B508ULL, 0xEA33C245000B25CDULL, 
            0xD3287253D6FB53F8ULL, 0xDA8CD2960941D29DULL, 0xEF75201632871B6CULL, 0x2267C303E1DB9F78ULL, 
            0x9188087FE51DA6C4ULL, 0xB9EE7FB47CB4C00EULL, 0x7228C9D5F72378DEULL, 0x7497FE6E0CFDB76FULL, 
            0x1B15ADDF9059FF1BULL, 0x04829FCBEF39D22BULL, 0xCFE6DAD564FCFAE0ULL, 0x2869EF93F1A3DDCCULL
        },
        {
            0x85E260003EB2C3D8ULL, 0xBAA884B6B00A7988ULL, 0x1D23C03284389F4CULL, 0x14B9764C5CAA3845ULL, 
            0xA06C7CB6FDA4462DULL, 0x002CFA3015C8C475ULL, 0x701488D63DD7F9B2ULL, 0xC7FEB6FBE621D4FEULL, 
            0x6F34ADFDBDA55009ULL, 0x4A579B366EB8AB4FULL, 0xB5FF931B46DB6623ULL, 0x4E70D1DC48C00081ULL, 
            0x08B1A89BE179C769ULL, 0xD2AC2C05750035E8ULL, 0x8D304DD28C974678ULL, 0xB87B337BE771B50EULL, 
            0x97983D0B3CF0D6FBULL, 0x220E5EF19EA3FC5CULL, 0xAD973CF3BEE14E0EULL, 0x3E25C2F55E89A521ULL, 
            0xAC094590957DDB41ULL, 0x8A2953057426EE03ULL, 0xF93FD9DAA5600FFEULL, 0xCE5DF34F29225C35ULL, 
            0xBFECA99BB0A9A68EULL, 0x8194BBDCC065AEC8ULL, 0x98C05E558BBAEB0BULL, 0x0C600A401B88C961ULL, 
            0xB988E75CE8DC8DA8ULL, 0x6EDAF47E63F15ABFULL, 0x0FC0FB7C9E211A02ULL, 0x479171E66377ECFCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseDConstants = {
    0xC178A721D83F40B5ULL,
    0xA8A04D7A3934D92CULL,
    0x1553D16B4CCD1371ULL,
    0xC178A721D83F40B5ULL,
    0xA8A04D7A3934D92CULL,
    0x1553D16B4CCD1371ULL,
    0xF3DDBE64A36CDE79ULL,
    0xE75EBC87176881E6ULL,
    0x03,
    0xB0,
    0x94,
    0x9D,
    0x80,
    0x8F,
    0xA9,
    0x97
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseESalts = {
    {
        {
            0xBE068B3F50ED40A2ULL, 0x55242A7892D560E9ULL, 0xD784F42A659F2981ULL, 0x65F394A7B899ECD0ULL, 
            0x7EC0ABCE6DCE1326ULL, 0xF92627CE1AFCC603ULL, 0x7625D9F9EBF5A993ULL, 0xA984681CD276A93DULL, 
            0x54235865C899B40FULL, 0x4369CCC192DF870DULL, 0x6AEB561AB0BD7F68ULL, 0x878FCFFD4070CFFFULL, 
            0xC19BB5441F805AE5ULL, 0x7DC40DF57161C7A0ULL, 0x4BCB78E62B291DDCULL, 0x6F57530C97243F76ULL, 
            0xC641D18F3FE93234ULL, 0x6E0D4E850F86C371ULL, 0xB42EFFE5EA9B8439ULL, 0xABD24DA1E9ACA656ULL, 
            0xC0BDA7E8AE7CD835ULL, 0xA540AF87413E059FULL, 0x528377379721A075ULL, 0x2A570AAEE3443FDBULL, 
            0x2F82782D99E320D1ULL, 0x3C51288A4C227266ULL, 0x52BF05AAD4F4495BULL, 0xBBA29CE86C264491ULL, 
            0x6C6E1E6D110D807EULL, 0xBF55530C6C75DDECULL, 0x372A4BFE9983D600ULL, 0x93343929C083A256ULL
        },
        {
            0xA9CB3B9A628F9746ULL, 0xFC5A8AFA36332002ULL, 0x43943C8CAC5D1B7AULL, 0x14EE30CCE26A6244ULL, 
            0xC64C24B2FC316C35ULL, 0x67FC2F32B017F566ULL, 0xF818F90DD1C709B3ULL, 0xC83DF16065F31001ULL, 
            0xD544A5BC557C558DULL, 0x58453E79D3CC8755ULL, 0x30383F18FFE5594BULL, 0x5119A3333E06F1EDULL, 
            0x26D0F362C882C889ULL, 0xDB90A8EDEAA33615ULL, 0x1C9345170000373DULL, 0x54DF60E534BFCF0CULL, 
            0x32DFE9444950E3C1ULL, 0x01A847AD50EEC82EULL, 0x902288807967779FULL, 0xF93AA5C2599F261CULL, 
            0xE744444B79ADCE00ULL, 0x1F5FD939AF155271ULL, 0x971BBAFE92947460ULL, 0xB442FFC36962F368ULL, 
            0x2CAB2D1F2F5A3BE8ULL, 0x54F247E2A6C60F00ULL, 0xFDF932DDC2CC6A61ULL, 0x926B5CA85FD5686AULL, 
            0x6DA0116BFE127593ULL, 0xBECA0D9A81545140ULL, 0x240C3A1354279F6CULL, 0x389B116DCF819860ULL
        },
        {
            0x7E8A1681A05AA130ULL, 0x63B957135A346D95ULL, 0x32CCEBF3426A6CA8ULL, 0x7FB0718824BE67C1ULL, 
            0x9B68EFBEFFD971BDULL, 0x2A7FC54992005E80ULL, 0xE7D71F6CC0E87589ULL, 0x181BED3F3263B8DFULL, 
            0xC9F24B9179DEE8BCULL, 0x63E391D59346B0ADULL, 0xD0965A37E3AF7291ULL, 0xDFC90A6614D37AB9ULL, 
            0xE0CAA568D61B3CFFULL, 0xEB9B7D7781BAC97EULL, 0x8ABA84632BD50814ULL, 0x2276B7935BA02913ULL, 
            0x2AA213A3BD08F587ULL, 0x988B885DE7A0B23DULL, 0x27E18FB06E75C41BULL, 0x0A6D4253AC76195AULL, 
            0x760EEF2640B6D71DULL, 0x657704701DF406AFULL, 0x7EEF8EEA29E65F6DULL, 0x3ED2AAAEDD11437DULL, 
            0xA3E8AF24C6AA958EULL, 0xB50F57A06A7A880FULL, 0xD95C70CFA30CEA7FULL, 0xC0F15C5C118444A3ULL, 
            0x8F2FFE1D250AEBB7ULL, 0x2157E46E9FB6A61EULL, 0x784D34337CC47ABBULL, 0x01D157CF9147BCECULL
        },
        {
            0xC55E96560F0AF54FULL, 0xD8CC09D18B75C8DDULL, 0x00854350C65D3E95ULL, 0xF8B8458F08D2FC26ULL, 
            0xAE8D02A0030BBC75ULL, 0x309CFB67F26B7D6CULL, 0x6B3B0D14B21DA67DULL, 0xAC7DA1089A7E4ED5ULL, 
            0x55E44E316C10D496ULL, 0x384271EB810F9397ULL, 0xB2EB27FD915BA48AULL, 0x08C425A80DF4B752ULL, 
            0x61A0F15B1102B2CAULL, 0xC6089425CE9A05DFULL, 0xB46317AF78BC203AULL, 0x5BEE098442BDCB57ULL, 
            0xFCDD9C6DD3C43183ULL, 0x7AC163CF5DDE9E35ULL, 0x1303B5B753FF97FDULL, 0xBF3E1764F4689E89ULL, 
            0x5773D63A6FEEA169ULL, 0x0310F20F336F41B2ULL, 0x1D34419303191503ULL, 0xBD87B44785B5B11CULL, 
            0x7954BD2BD0319CACULL, 0x129CA794D2DD776BULL, 0x7A19D4CB54AC3D41ULL, 0x5F946BE7F33EE34EULL, 
            0x2BD40B3B69987B04ULL, 0xCA7E9F9EF4D1537EULL, 0x9F7EE9947A0D356AULL, 0x18A170FABE7BF557ULL
        },
        {
            0x4ACA1A40DEA61DDFULL, 0x732D43B64A20B0DCULL, 0xC359695975D61DACULL, 0x8C8C8548683F0566ULL, 
            0xB44FBE26A1C138FDULL, 0x5AF0105CB5C00AF0ULL, 0x5163AB677A59674BULL, 0xFC936A5900C45675ULL, 
            0x3E75DF36399DFA18ULL, 0x6493A5451DB698EDULL, 0x6332B2334AD1F477ULL, 0xFB5B407B520E5EF7ULL, 
            0x254BED1079D7CB6EULL, 0xB828AC05DD59162BULL, 0x5B000F5ED2755337ULL, 0x439E7D28F597B301ULL, 
            0x854E5D10FDF386E2ULL, 0xDD91D9D868E9DD74ULL, 0x45BDD19AD1CE739EULL, 0xBFEF7B800D2DFF8EULL, 
            0xFF79F375313C5611ULL, 0x2ABFE249D2C06585ULL, 0x9B36549A409B2AFDULL, 0x718657B8EFC2CF73ULL, 
            0x83C75F6E39BAF1EFULL, 0xF758BD5242AA817AULL, 0x81E8C010A07C5AC6ULL, 0xA833FCAD31CA1D1AULL, 
            0x25BAF9DBDAA938B9ULL, 0x4C065213F4D020B2ULL, 0x2C1462E395B9E04CULL, 0x372376FA3A7A852CULL
        },
        {
            0x055EBB35915FF125ULL, 0x3FCC0FC68788FE52ULL, 0xF48FDA415CFBEC26ULL, 0x0172DACEC90943BAULL, 
            0xC51877F748CA31CEULL, 0x6BA01F75F984EC5AULL, 0x6D0D1604F7FABF99ULL, 0x09E01E383C0650C6ULL, 
            0xD820BD0D4B0C7D05ULL, 0xC4EFBB3C66A34204ULL, 0xF28817581B25F455ULL, 0x2326F094CA267853ULL, 
            0xC0244D841338AAD8ULL, 0xB6135AED50631BB7ULL, 0xE69C66C3F96C439FULL, 0x76EC736331B75B0AULL, 
            0xB3B97B3F3DDF0C33ULL, 0x75ED0DB5D13F3778ULL, 0xCB1E2D59CB9C9BABULL, 0x602F030F4A05E7CEULL, 
            0x54666A4DF7C6F641ULL, 0xD565151192CA015DULL, 0xAAB9F7AFF0783FD2ULL, 0x4962C1222A51F0D7ULL, 
            0x40F2D801E287A9C5ULL, 0x5C0C367EE0B02B2AULL, 0x21DE5BBB9D43233FULL, 0x188FB55DCC6C4C07ULL, 
            0x404E5E4831B59344ULL, 0x9DD0EDDF92932F06ULL, 0x24A16221B4798EEAULL, 0x3D5F126685B08F4DULL
        }
    },
    {
        {
            0x7407CE0407035D2BULL, 0x70803BF1AD8487EDULL, 0xEEC1CB03157DBF9DULL, 0x47A9906F07403110ULL, 
            0xE816FCFA61B42CF2ULL, 0xA401A1DAA3E3317AULL, 0x58E03C23078DAB4EULL, 0xBE371D9FB18074E0ULL, 
            0x6377BF7126C1828DULL, 0xB3CBDCB2511A9347ULL, 0x91B8C213B38DDFEFULL, 0x585115031A80D6A9ULL, 
            0xB2FE3EC84948D666ULL, 0x66C4B8EB6DD2971FULL, 0x8C5598FE0406CED9ULL, 0xD02DD3E8DBA2EB11ULL, 
            0xF60EEAB73C15A631ULL, 0x4AE83E0D89CF7253ULL, 0x304E3E6A9C90FD60ULL, 0x0EA1823520073FF5ULL, 
            0x252DB4C684581865ULL, 0xFC15CBCC8EC2396FULL, 0x91977C746CC6A851ULL, 0x2D001E02E100E9B6ULL, 
            0x9E990BBA6992B761ULL, 0xA1E4364D3DA830E7ULL, 0x5587BF7F24AE0FE6ULL, 0x358EE2D9EA7D1151ULL, 
            0xB6D4EA7D8C941FF1ULL, 0xDAD31055166B9259ULL, 0x08F68EE57C3D5CC2ULL, 0xAD68B395FD89114AULL
        },
        {
            0x573136A656234083ULL, 0x2CAFB7A24F2BC08BULL, 0x4962E409E86A41E4ULL, 0xB381DAB7C7944D47ULL, 
            0xD333FCBC38D3A1BBULL, 0x2DAAC97065ED0F3EULL, 0x76193A18DACCFACAULL, 0x10D04B346FDAAE06ULL, 
            0xD86A31C11CD9B738ULL, 0x8FE5A485721F7668ULL, 0xB23E9316F02A456CULL, 0x0A270A76AADB7979ULL, 
            0xA9D024EDE6889217ULL, 0x09DC624F2196E299ULL, 0xEE4807E8B95947E6ULL, 0x9AF2484F5E7D217AULL, 
            0x76FCC10A5F6DA952ULL, 0x6D122A3C13F13303ULL, 0x12B18329486215DDULL, 0x1A52F80DC600A163ULL, 
            0xAFCA98F60EB3AED8ULL, 0x95B69C41753240B3ULL, 0xDB4AB3F5E5202841ULL, 0x9418F4F3AACE6F6EULL, 
            0x27A65C0A3ADDDD85ULL, 0x1F537F363563185FULL, 0xEFDCBFE9C4BC60EBULL, 0x37AB8B0209B2F54BULL, 
            0xF72605E3DF7A8F1EULL, 0xC167D49DECC76CBFULL, 0x5377994BBF35445FULL, 0xF601B03B52732815ULL
        },
        {
            0xEDDCCB631BAF6481ULL, 0xED5790A221EAFA33ULL, 0x15412845FBF28018ULL, 0x1DB60B65F5DB328AULL, 
            0x21BE6AC08833BA1BULL, 0x9182450B4ACA52E4ULL, 0x0DF00113BAAEBD8AULL, 0xE925B5ADBC6B3FFBULL, 
            0x1FF727D9DA9FA1ACULL, 0xE367629A09A95DBFULL, 0xEBC3CBB9D2F4C9CEULL, 0x08BDDB58F376ACF6ULL, 
            0x7AE8BE38144D274AULL, 0x57AF07A450750D89ULL, 0x8ADABB04565A46A8ULL, 0x08475401B3528B1BULL, 
            0xAF6D109177C06A68ULL, 0xDCC1390B196E247EULL, 0xF17F938865BE30FFULL, 0xBFBD45BA8BCAF129ULL, 
            0x7343E6263FD039EFULL, 0x4608D0A6C9F1CFE1ULL, 0x0AD4638B3BF0D738ULL, 0x046D8DEC130F9714ULL, 
            0xBADD7BFFC1F49AD7ULL, 0x11A465F5A0CED3CBULL, 0x413B546C9D7238F2ULL, 0xD58B8C5CD26556F5ULL, 
            0x9FA12830A9A60CB1ULL, 0x6E69749BE14F1EB9ULL, 0x722CCC2D0E12EB47ULL, 0xD1E3F23DDEACD387ULL
        },
        {
            0x9FE5866BD65A5906ULL, 0xB1CA0974A60C5E02ULL, 0x1A6EB7756B1343A7ULL, 0xF1AEAF157D58496CULL, 
            0x5397B6FA26B82AB9ULL, 0x59A00A8395D90069ULL, 0xC83B0D87B9A4D69AULL, 0x57E4EAC5B3CD209EULL, 
            0x4247FF1D146D3FBFULL, 0xCB4CE3D073438967ULL, 0x1D59AAEF276ADDC7ULL, 0x17149255AFEDFB42ULL, 
            0xAFB026E586393812ULL, 0x37ED673AE0985FEAULL, 0x517131AA35BCB1D2ULL, 0x915B989A89437A54ULL, 
            0x9D1168568DBDD466ULL, 0x5B979897EA6C7A22ULL, 0xF29CA3C1EE1AB687ULL, 0x43818AC002E32FBFULL, 
            0x658369ED0411984DULL, 0xA88545E741C26EDEULL, 0x41C15AF7EA4CAC26ULL, 0x71E1676C23D85749ULL, 
            0xC55BD1483FEC8557ULL, 0x8B2473401140B7C4ULL, 0x0E15028DA5FDFCB2ULL, 0xF42D5DD67F9961FFULL, 
            0xE3D4DF8418AA1E1CULL, 0x85F6B11F4D96EF15ULL, 0xEADA54C84AEBDE5AULL, 0xA633C8A8A42FEB0BULL
        },
        {
            0xB2EFD3A1B0FBAE8DULL, 0x1DABCE9482774CBBULL, 0x966135979524D2E1ULL, 0x691BF379162D576DULL, 
            0xD4A6FD0208DB5B53ULL, 0x1D219310047C9ED7ULL, 0x8BCA82099A9A8245ULL, 0x95943CF4B3B54D91ULL, 
            0x62A77B124CD5D42DULL, 0x3B84A86C11C8B64CULL, 0xB9665176E751E611ULL, 0xA70D8FEC16AE76D8ULL, 
            0xCFC7C128EA87DE20ULL, 0xC4BF224D2C4B00EFULL, 0x5BE928BE2E32D682ULL, 0xE525C9FDA36F1583ULL, 
            0x8019704C3685A638ULL, 0x8F76696AE022E590ULL, 0xAD73966064F9BF09ULL, 0x64D308883BDB7F47ULL, 
            0xD8433A71C8B6F229ULL, 0xF83A50EBF6A03A14ULL, 0xF6E7A03A113DA739ULL, 0x120A7BC8AD555E59ULL, 
            0xF3BC5503F17221DCULL, 0xF7E5BB15BACBAA54ULL, 0x1F74F864D674C717ULL, 0xC8ACF76CD2500634ULL, 
            0x2D9980D9136BA638ULL, 0xE1B391F1FAB5A674ULL, 0x03D84D644296A47FULL, 0x7A9E150C362D1473ULL
        },
        {
            0xF76454E6C9A0CAC3ULL, 0x6A8C6891DFFFC8BAULL, 0x2D8E6D961F38DB2AULL, 0x7DF0C79CD217A883ULL, 
            0x624B2E768A34C69AULL, 0xC16769D4DB47F241ULL, 0xB4928BB6352C25A6ULL, 0x2F25167C3A1C0F02ULL, 
            0xCEEB2EDF94F870F3ULL, 0x9EE125CFA74FBACEULL, 0x367144186ABFBCBBULL, 0x774C2E60D416D42AULL, 
            0x447032F0997530A6ULL, 0xAEBEB0E7112C7AFDULL, 0x4595F54C6B4EB7E1ULL, 0x403875AD85AB0CCCULL, 
            0x48461BBB2016DF43ULL, 0x11918E1F3D27093DULL, 0x8ED45CC002658016ULL, 0x558C26DC938E66ABULL, 
            0x312E73174A333242ULL, 0xDE7EC109B550E03DULL, 0x899F6FBB92FF302BULL, 0x2FE30A213925E7F7ULL, 
            0x0AE3A30F9428D569ULL, 0x05B300FC4390655EULL, 0x13A1884BB1971AF0ULL, 0xD9F4C14E59B84CBAULL, 
            0x522D2FE0A488E70DULL, 0xD4213F16CBFB630FULL, 0x2B227F11E61CA36FULL, 0xEA48C6FEE4D73EF4ULL
        }
    },
    {
        {
            0xF38120314844F8F2ULL, 0xC960F420B0308264ULL, 0x6BF55985EA4912DFULL, 0x42CACF99450EC850ULL, 
            0xF072E43927CBBD71ULL, 0xC4D45C5218B51BD0ULL, 0x0BFCD7919AE12B2BULL, 0x4488A204DD757927ULL, 
            0xC0BF3EACF402992CULL, 0xB7044C12E21B4289ULL, 0x232103C3F52D6197ULL, 0x1281029D39A51FFFULL, 
            0x7D24EE8CD43821D7ULL, 0xF812F0B392BCCE83ULL, 0xEB2A93246C88664CULL, 0x79E53A34E7FBD985ULL, 
            0x60372F73E79A8A9AULL, 0x61EF9F93DDD8B3C1ULL, 0xE2703EA4F51F1E14ULL, 0xE4FADD94F4C05EDBULL, 
            0x95069F598B0803E3ULL, 0xFDA17E25A2B33920ULL, 0xDA4A71BC9E9F20C6ULL, 0x1CB4085EC1BDC26FULL, 
            0xC9B49C072723DD46ULL, 0x3F89F1463A333AAEULL, 0x70F1A218606FFD8AULL, 0x44E13ACED85AE3B9ULL, 
            0x13A5FD0E4ACEA0B5ULL, 0xD427215A6B6651A6ULL, 0xC933DF80EE5AB021ULL, 0xC9A42BCF9E3C0E0EULL
        },
        {
            0x47D37EB3DD9E5D74ULL, 0x927867ECC2448FE7ULL, 0x1913001388715E5FULL, 0xBEEDC639FBA4DBE8ULL, 
            0xA36F34D3502F775CULL, 0x5FD2F9525A896411ULL, 0x41990F29864DAF5BULL, 0xA8FA61CA30E4CB56ULL, 
            0x562AC2E821F4447BULL, 0xBBB432D856C8A4DBULL, 0x7839516145D6392CULL, 0x36FC67CAA91825D3ULL, 
            0xA31D127B7DC04179ULL, 0x51346C7928C9EA03ULL, 0x0843828FE13BA5FBULL, 0x5CB75DCA89FB599EULL, 
            0xD989894E06D6E632ULL, 0xAC67E91319EA0975ULL, 0x321A13AFF3E29D01ULL, 0x9827D3E8281790F9ULL, 
            0x549614EAD32E4E1AULL, 0x319BB47D33E37C25ULL, 0x5D238AA23A126FBBULL, 0x9CC8044887DF1D20ULL, 
            0xF1856E0E13D4E822ULL, 0x02AD2986845ACC6DULL, 0xE31E7126E61D4D09ULL, 0xE3A7FE6F650C91B0ULL, 
            0x3364C1F47DE12174ULL, 0x1EA2730EF1C04939ULL, 0x6DD012FEFC3A507BULL, 0x3A69D417843EADC5ULL
        },
        {
            0x216601A7C1F1EDEAULL, 0x2B089FF03063AC2FULL, 0x3CF131CBF685C39AULL, 0x7EFEA8C927F9D1D1ULL, 
            0x103CF10A16150595ULL, 0x211B6A3F177CC1CCULL, 0x48904BBDB2205122ULL, 0xFD42EDFF6ACF532FULL, 
            0xF80EFFEBF043345FULL, 0x32D0F7B9BA80A887ULL, 0x8DF2BC296A1FBD08ULL, 0x3CF8752755A568D4ULL, 
            0xD222A4EB8526CB42ULL, 0xF1493C10B470000DULL, 0x3B44407D012F441EULL, 0xB3FE1C23E09A0CF6ULL, 
            0x9E69EC5044FE5A09ULL, 0x6C6C955D5A36887CULL, 0x8D1A449A75E33873ULL, 0xD8124068B718BE8AULL, 
            0x0BC563F9A4501314ULL, 0x83398E124F3B7188ULL, 0x2D475DE8A7D2C203ULL, 0x8623C4770110EEE9ULL, 
            0xC0DB879A790CC9ECULL, 0xC15F753EC32630C3ULL, 0x3345E6751EA591DEULL, 0xAA084C1EC6B8B1B5ULL, 
            0x09BDC496E772CD09ULL, 0x05A79E7CAC4A5EEDULL, 0x43A938441A5ECDECULL, 0x66267B9509182FEFULL
        },
        {
            0xBB5896146D643AD0ULL, 0x232DC3DB0C0BE40BULL, 0x5059566D64920231ULL, 0x768971474CFC378BULL, 
            0x0B2D101E396FCFECULL, 0x65FEDA6757AF393FULL, 0x27354A9258EE3FB1ULL, 0x3484593EB943E26DULL, 
            0x259E34EF65518468ULL, 0xD92CB8E71CABC6F3ULL, 0xAEEDDD2B3B0F8A5EULL, 0x41BCE73845DE9600ULL, 
            0x70594E66C4CC4ED4ULL, 0x38FD248444768AD4ULL, 0x82C372E9BD55EF0FULL, 0x5566E98782C9CA0DULL, 
            0x728A07E2FCD6AFDAULL, 0x3915F225AEC9EB8FULL, 0x6EFEB128D5EAB1E7ULL, 0x219A117811CD017AULL, 
            0xE4AC9D667ABD4BC1ULL, 0xE2DF437652BD27A2ULL, 0x615F99589D8F3A4AULL, 0x4A1598BADD7FDED1ULL, 
            0xFE59A83201297E33ULL, 0x8027E16C02B31491ULL, 0x27C91E6D5064CA02ULL, 0x712E55B2AC72CFE1ULL, 
            0xA4C5B2488803FE1EULL, 0xF4E06B72BCC8C1FBULL, 0x4FC8A9C246569E35ULL, 0xAD4794DC8A7CD183ULL
        },
        {
            0x76B040BCA8EF94F1ULL, 0x04DFAE0DAE795715ULL, 0x83B576B78F447BA5ULL, 0xE2FAB75FC0217D0AULL, 
            0x9728EF0DDAFBDD09ULL, 0x2E986175DEC1D3A1ULL, 0xCE1075FF1DB96D0AULL, 0xC8751863F697F666ULL, 
            0x18B4A55654F0E5BAULL, 0x902B5FFD0F26711DULL, 0x04D63907B307FB68ULL, 0xBD0A4158266AB5F0ULL, 
            0xBDFAE494231C6C0CULL, 0x9E84D9FDBC5DACE5ULL, 0xF3CB7BA3633D8488ULL, 0x9AB2E5A1B763CA61ULL, 
            0x86A74664E35479DFULL, 0x26F775A8CE017A8EULL, 0x7B88AAC442878BBAULL, 0xA4E75A383C6208FBULL, 
            0xE542C54D2E171DB9ULL, 0xFB9CA9C3127B141CULL, 0xCE07CADD32031A72ULL, 0x158B0566044D5E99ULL, 
            0x58DC9C1C56B22EF9ULL, 0xEA3B6B3921A1577EULL, 0x296E84EFEC5521CFULL, 0x23A1B3A60CEDA86BULL, 
            0x992B8357F1FA2D25ULL, 0x067054AF4E4578B0ULL, 0xFED4F832B8881BD8ULL, 0x8B0AA1B08AC75651ULL
        },
        {
            0x09EAE6AD2EEA464FULL, 0x42CAF798F85787F0ULL, 0xFA2E546D2E2941D2ULL, 0xD66F9A6BA360B83DULL, 
            0xE5433ECD7DD270ABULL, 0x59F8CFF6E539109DULL, 0x0C66B2CFF2489A3AULL, 0xC77DE378488CEE79ULL, 
            0x261E808E8F2F58E1ULL, 0xA31383A9084BEF27ULL, 0xC3F4F93BC5621383ULL, 0xA3CA628F21771514ULL, 
            0xAAAF422CDCB83E71ULL, 0x8054951542308D74ULL, 0xC2B44346A9DB6A1CULL, 0xE921C5312C232421ULL, 
            0xD9E3678D96F505CEULL, 0x00FD18F1D4E23461ULL, 0x4EE908D3C6014975ULL, 0x302E9AC2F635F7BAULL, 
            0x9A7BE151188DDBD6ULL, 0x91095086C3072B89ULL, 0x1A5C51EF96667991ULL, 0xAA194DF8BA3FF903ULL, 
            0x3DF0CA6543FCFC4EULL, 0xE6D2090B66BBDE4CULL, 0x8760DCDCD5EB36D9ULL, 0xEEB958775379CCCDULL, 
            0xD556243DA90AC589ULL, 0xB4C80FEA221BB162ULL, 0xDA9D4B567F069E13ULL, 0x1ABE4203A768AAC8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseEConstants = {
    0xACFCC6CBAC2DAE76ULL,
    0x96209F205BACC5A2ULL,
    0xC6509C56667BD66DULL,
    0xACFCC6CBAC2DAE76ULL,
    0x96209F205BACC5A2ULL,
    0xC6509C56667BD66DULL,
    0x6E877C4E4959EBCDULL,
    0xBFD40C0ABCB3CCF7ULL,
    0xFB,
    0x39,
    0x1E,
    0x7A,
    0xE9,
    0x9D,
    0x99,
    0x55
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseFSalts = {
    {
        {
            0x6E77D00F19A44E4AULL, 0x79B7497BF72F3A76ULL, 0x83DAC48B1AB5AF7BULL, 0x606F3AAFC936A4B1ULL, 
            0xE62A557DDC2CDC69ULL, 0x7024D3E88BE4D7D2ULL, 0x164342A4403ED56AULL, 0x9905E157AD34D9FEULL, 
            0x69E2C93B049E525EULL, 0x59918FBDC30BAC48ULL, 0x498116824D6F39A2ULL, 0x995FEA961C666863ULL, 
            0x623F88C6A01AD712ULL, 0x462EA3074D441B03ULL, 0xCB732FFB121225A3ULL, 0x09D3122F55D2BB3DULL, 
            0xCCFD219686EBBF27ULL, 0x92D7CE50CE4EEB50ULL, 0xCFE710916311364CULL, 0xEFF239B4C5547EEDULL, 
            0x7AA5250EB7DB5863ULL, 0x95CEBD9D72A9DA72ULL, 0xC57E1C0A3507C3AFULL, 0xFBA5E9ECCB923B0BULL, 
            0x05FDC87954D02EA9ULL, 0x6259E1E179F1D9AEULL, 0x9079607066754665ULL, 0xFB2D3B1156298A45ULL, 
            0x24C4024314EEED09ULL, 0xFA69116E8B2CA36EULL, 0x0EA83382660B39E0ULL, 0xE0155608CA58F829ULL
        },
        {
            0x5B572F7D203DEA01ULL, 0xCE080D26C4DB7C6FULL, 0xA7E86C5E16BC8065ULL, 0xF35B0F86D40179B6ULL, 
            0xC6CE445465E7E4EFULL, 0xC211E242D3A8D202ULL, 0xBBB12FABC93D4140ULL, 0xF157766BB06AEA99ULL, 
            0x9227C6688621448DULL, 0xC4926F94D38F13F8ULL, 0x2D99FF90881134B7ULL, 0xA39808F36BDA7775ULL, 
            0x28CBB0E1727E8C8EULL, 0x72DC55A06815A148ULL, 0x72D24A5FC873432FULL, 0x9E1713640BF749BCULL, 
            0xB5479029B8F295E1ULL, 0xD80EF16B8CFC32D3ULL, 0x07074C30579A6789ULL, 0xD13583ACF2076F29ULL, 
            0x231033076D1CEB69ULL, 0x9CEDFB2A06D69FE1ULL, 0x594AAA6781B700A3ULL, 0xFB651753DCCB3ABCULL, 
            0x542914B0F6ED2871ULL, 0x00C2ABE0004AD277ULL, 0x2C4FF4CA90455472ULL, 0xCA58B587F4035B0CULL, 
            0xFBD99BD648B41476ULL, 0x19635AEF182E7AF3ULL, 0x9D3FD1BF21624978ULL, 0x575C830717FA1658ULL
        },
        {
            0xE77044DB10B3ACFDULL, 0x67E2DEB862F91FE2ULL, 0xF7626602CEB04384ULL, 0xB8B195FB2048C127ULL, 
            0xEB944B439FB6BFA9ULL, 0x32C7BB6C692BBC50ULL, 0x1E1FE5EC32C8ED01ULL, 0x7C4FF56DDE029F21ULL, 
            0x31896D78133EBBF2ULL, 0xA088186E9651407DULL, 0xC251195B8FB1B1D5ULL, 0x22FF87EF7B13DFF0ULL, 
            0xA8B1708511ECA3C1ULL, 0x9ABE303017CF03DCULL, 0x4F76C14C1FD5188CULL, 0xC10863620134E551ULL, 
            0x68C7945A3FEA1726ULL, 0x5061AB1BA4882D73ULL, 0x8D97EB3EC364E3E4ULL, 0x3EBF5069E9383A62ULL, 
            0x7A42E8A152256B33ULL, 0x0B648661CD015E5BULL, 0x874302DB6B6870F1ULL, 0x6582F9BEF873A47CULL, 
            0x9CCAFD9EA5C7059EULL, 0xDD8DF18053659741ULL, 0xCC067406C8334FDBULL, 0x0F4A6248D9DD0602ULL, 
            0x936DFE2C85014FC9ULL, 0x62831C69A7585A44ULL, 0xFE34DAFB65497EEDULL, 0x764149751BA1B070ULL
        },
        {
            0x4E8CA276B2732FA0ULL, 0xCA494EB315D826B6ULL, 0x99F3E8D6B3DED375ULL, 0xC0F6D491E840C3AFULL, 
            0xD722BF25B80465B5ULL, 0x4550B1B979D25CAFULL, 0x39CEDCCF9D7F3D21ULL, 0x1968C7EEA020AB15ULL, 
            0xAE0E9F4A7A482F43ULL, 0xD6EEA059513A2583ULL, 0x18EA68C8D44FFD23ULL, 0x03BC549ED191F6AFULL, 
            0xD04F2DA345E09B57ULL, 0x02804FAB9D512805ULL, 0xC1072C9C43F221ECULL, 0xBE4B025F98331D31ULL, 
            0x3321763C2EE929F3ULL, 0xFCB7EF25369DA523ULL, 0xA48ABFDA648AB2D4ULL, 0x191DB4CC70D71BE4ULL, 
            0x97D17C0A47C6EFE9ULL, 0x9890F0DE8A827156ULL, 0x5464503CF9DF3A54ULL, 0xA0B8E6459CB88E87ULL, 
            0xD8DBB973A8D3B3B7ULL, 0xCF6CCDD4EEB798EBULL, 0x9311B1A8CF3073B6ULL, 0x114E62072898D9F5ULL, 
            0x0DF1014588D3DD51ULL, 0xA98E0E4A871C844AULL, 0xF8CB6A2D8845D585ULL, 0x9870ACBB2E464DB9ULL
        },
        {
            0xFD819964FE6D7817ULL, 0x66C51D5076C529DFULL, 0xECB8C706D213B71FULL, 0x3E89E35E299D53DBULL, 
            0xB348F44711B9EBD9ULL, 0xAC637F66ED800BD8ULL, 0xF711D38A7043EEC4ULL, 0x4F54BD38CB62EDA3ULL, 
            0x84A840356A4263ACULL, 0x41345204860DFEDFULL, 0x1608600D1A85FF8EULL, 0x74D78E9DE873077CULL, 
            0x3A5A21740F3CCF3DULL, 0xE4F69D0056A7F38DULL, 0xFFD00AF4F87741BFULL, 0xE7F4D8F714E0E0CDULL, 
            0x536B02AEDD11622CULL, 0x7851148E9423C7F3ULL, 0x7CF9BB6BF1D7E223ULL, 0x163948F737069D93ULL, 
            0x3426193360769996ULL, 0xF72B9B2110B1279BULL, 0x953B868598AA6C4DULL, 0xFBB71883DB70611FULL, 
            0xD8AED057AFCB2AD2ULL, 0xAF56A891D435265FULL, 0xBE7DF744E9B7F0FDULL, 0xC1505EDE280D1A60ULL, 
            0xB97C16618C799BA0ULL, 0xA7E91D65A663796AULL, 0xDB459788B9F9362CULL, 0xB889D97CEEA40099ULL
        },
        {
            0x72BABBB267E48537ULL, 0x9058E719261F6987ULL, 0x0A03EB5564CFB9C7ULL, 0xFDF737F077A1951BULL, 
            0xF15ABDB9C833D35CULL, 0x7DDFE7568BAD4220ULL, 0xD3DD1912E4947D93ULL, 0xB684C6399861C028ULL, 
            0x89E91E7196454BD1ULL, 0xBA8AF5DFA4107E86ULL, 0x9A0A718548EB990AULL, 0x26A566563C69094DULL, 
            0xACD335D46E83794AULL, 0x7DC3DDDECADEE975ULL, 0xB1E8549EBBC23F36ULL, 0x054E938A34428FA4ULL, 
            0x70120E9D996198FBULL, 0x072098CF98FD1A4DULL, 0xBD51A10087C66A9EULL, 0xF81BC50C3DD985F3ULL, 
            0xD590DAB408C2B2EDULL, 0xC39C7EB70EC0426EULL, 0x13C0785B90B853BEULL, 0xC5C8BB9F59A317C7ULL, 
            0x0C0FC0C6676A4BD3ULL, 0x73AE01DDB512A6BBULL, 0x3D45BA8B001E9F64ULL, 0x318B40CAD79B7F6DULL, 
            0xABA51BC40987F79EULL, 0x5AA80B02929978ABULL, 0xAA359AE3F85262F5ULL, 0x6D68BA964F653A72ULL
        }
    },
    {
        {
            0x0A8394F98A6F7019ULL, 0x603ADF8349B57E51ULL, 0xCF88FE372C2F86FDULL, 0xA1E68DB34DE35E18ULL, 
            0xC66E9701BBD15A95ULL, 0xB0685B460FBD886EULL, 0x6CBB09747A4A5081ULL, 0xE3BF09E59F7D1BE9ULL, 
            0x81EE20F425DDAF0FULL, 0xE6A349BA74E04B44ULL, 0x8A1C4E58368268F0ULL, 0xDBE91F9106865CECULL, 
            0xB01AEF54B43CB7E4ULL, 0xB81C58A2204211C8ULL, 0xAE04B205506157D2ULL, 0x203AC904DCCF154CULL, 
            0xBB8329226DE22596ULL, 0xADF798836D3C96E9ULL, 0x288456D050DDEE29ULL, 0xA51852B5EF8FF167ULL, 
            0xE70ADEFE1F0A19C7ULL, 0xB92B81A7E61469B5ULL, 0xEE7AEB19E04AD018ULL, 0xA1F6087CA3406318ULL, 
            0xD6FC6D89F147E3F2ULL, 0x3E9F383DF27A166FULL, 0xAEF9AD891E81BD6FULL, 0x9A5DBA71AF64B151ULL, 
            0x037D0127F7EFF79FULL, 0x82B9B1979332FCFAULL, 0x98160664839D3277ULL, 0x0EE764E9DC5F7717ULL
        },
        {
            0x153E74E35FE5CC7BULL, 0xA2077D1D34AF2D8AULL, 0xF9007F6277F6B903ULL, 0x14F156FA597FB7EFULL, 
            0x9104F78F561B8C78ULL, 0x1B37DC51DECB9705ULL, 0xA6D32F5BD4B5C61BULL, 0x7C492A6C8323AED1ULL, 
            0x1A2CE6778299B4C1ULL, 0x20122B59B7CBDC46ULL, 0x1A36E78F379895F5ULL, 0x5CBA0C2328420F29ULL, 
            0x21563D399F1658CCULL, 0xB257F2D6B9188937ULL, 0x3253E3E4CEEBA83EULL, 0xD7D2C53BA95DEEC7ULL, 
            0xEEDFE94449ACA8F0ULL, 0xF5CE0C4442987B56ULL, 0xE05D646E79CCF7ECULL, 0x37954A52981A2112ULL, 
            0xF2453274F392A469ULL, 0x3DEB883549D5EEE7ULL, 0x7DF9D709F654425CULL, 0x17C94151A4AE4FBAULL, 
            0x7C93F64ADF4BE01CULL, 0x8E65C29175506272ULL, 0x218C1808067A4BC7ULL, 0xF29621E9AB249EB9ULL, 
            0x594FF2838B845608ULL, 0x1558F10F83D7A84CULL, 0x5D519D02CD8A72CEULL, 0x318E46C73950516EULL
        },
        {
            0x3DBB5BDA5178B8C0ULL, 0x099C8817ACD232D3ULL, 0x4949FFEBCAF19D21ULL, 0xBF33D40B7313DD2FULL, 
            0x6A16EA09FE7AB856ULL, 0x21E665E59870287CULL, 0xE5808081EE3E9B52ULL, 0x80A88C3568F665B8ULL, 
            0x5FE1BF73455A3A46ULL, 0x8FAB94CD377ACA9EULL, 0x99552316A4F1C539ULL, 0xAECB0FB30B059422ULL, 
            0xCA8273FB7048BACDULL, 0x8DB391DAC9936FD6ULL, 0x0977A8C346945E28ULL, 0x32BF1EE3029C2AA5ULL, 
            0xD5098B4C4C9AB0A7ULL, 0x0B2F423FD555DE17ULL, 0xED7000E2BF0A4317ULL, 0xB639E05DBD3CEA4DULL, 
            0x041A413A4F834E2DULL, 0x47FEABB1E5EF3F8AULL, 0x9FD32CD36F7918EFULL, 0xA914BF9E86B9978FULL, 
            0x8E7A80110D78F15DULL, 0xEF5BD806730E2317ULL, 0xE8CF773610B50977ULL, 0xA350ECA61E92F587ULL, 
            0x4C5A0730A2E78D15ULL, 0x2A2F8FEDAB91FC2BULL, 0xD00E141807BC22E4ULL, 0xF7CFD4C3436A31A4ULL
        },
        {
            0xDCDB5B0F178147AEULL, 0x298FDAEFBDDCE80DULL, 0x6108843DE2710D6AULL, 0x8745C00D642B3355ULL, 
            0xE29015E8C99B6BB0ULL, 0xC4B300FFEDA00D53ULL, 0xE445646B7E75F0B7ULL, 0xB15CE4BD743E3629ULL, 
            0xAFD6918DFD28BD6DULL, 0x26E775245C87222AULL, 0x28B63A670C264792ULL, 0x5C4B2CA918CF4B96ULL, 
            0x128C407976BBC77CULL, 0x750D261B45846944ULL, 0x90F63A3868E7A275ULL, 0x22EAC2E6D332BBFCULL, 
            0x51540DDD6069BA4DULL, 0x755801FB208899F2ULL, 0x8C3EB562CE2EABD1ULL, 0x0DBF80A253EB5A0AULL, 
            0x6DF3C39D53A35AF8ULL, 0xF1EAAED30684C2F7ULL, 0xC8BB4C3D11EDC9FBULL, 0xC2A9C78210706380ULL, 
            0xCB2E02D7D6695736ULL, 0x22D79B8130046BB2ULL, 0x331AF8BD19891D25ULL, 0xC817421D84F7A361ULL, 
            0xEAE337D2A961519DULL, 0x62FE38DD289E142FULL, 0xBACFBC13307FD59DULL, 0xEFE1D55020D45AAAULL
        },
        {
            0x16F702ABB62CBD7FULL, 0x0C4E3372C17387A2ULL, 0xC89EAC7B27FD4496ULL, 0xF102B925976EDD22ULL, 
            0xE670C1E4931AC644ULL, 0xC09B933435074EF0ULL, 0xAE80EE3AA95E6D6EULL, 0x6704234C5ADE194FULL, 
            0xE02D801BE427F625ULL, 0xC14B48CA42B3726BULL, 0x60CCB1835E40FA2EULL, 0xAB0F4C6AD2884A7CULL, 
            0xCF5CBB8C87FA8A98ULL, 0xFFB6E5E451D5D0B8ULL, 0xCABD4B2C08BB4614ULL, 0xCDE859778BEEEBBEULL, 
            0xA84F1F6F363745BBULL, 0xD6334AEB91A440A6ULL, 0x973C5B36604B3E99ULL, 0x27E11FD01F4A2E7DULL, 
            0x3469853FB5090B21ULL, 0x18D1B0215AB6DBA2ULL, 0xCF714CCF6AD43A17ULL, 0x6B42A777FFE20445ULL, 
            0xC290C9236F662779ULL, 0x4B1E74CE17661505ULL, 0x370DE60425B24940ULL, 0xAD4A4B7A3F36D255ULL, 
            0x0687321332183ED8ULL, 0x9704A7FF3A6B7092ULL, 0x03361314A8E6E0FEULL, 0x2282BDEBA2F18BA8ULL
        },
        {
            0x52C2002074CB8B92ULL, 0x3952F284D07E652BULL, 0x07D2AA1B4B0AE6E0ULL, 0x545ABCEE9AC982B5ULL, 
            0x99505562A62F42E2ULL, 0x120A1B9AA562949BULL, 0x93EAFA2CB096571CULL, 0xD3344DD3E14AAC2BULL, 
            0x0C6AA85F1AD2CC68ULL, 0xB7C0DBEE07A6C979ULL, 0x5A315D6B70D7BAB4ULL, 0xF8E59265BED4329BULL, 
            0xF847DB25D89A23C5ULL, 0x1E741BC196ACDF97ULL, 0xEB7AEB2AF603AF3BULL, 0x37139D1BDFAA79BDULL, 
            0x4784A13406A0BA51ULL, 0x9E369DB89917391BULL, 0xF34491F0F659382EULL, 0xCD497171F15B2D0BULL, 
            0xCEB4717215CEACB4ULL, 0xEB8778A3696922E3ULL, 0xD94097445A5564FCULL, 0x248FD59370818492ULL, 
            0x475F61604812F684ULL, 0xD993A523018D8A73ULL, 0xE74A403B3B5E54D5ULL, 0xBD6353F21B4D10B2ULL, 
            0x2F86F6771F191011ULL, 0x62659A4D6C3F5EC0ULL, 0xCE7C319AFE1AF1CBULL, 0x77A4E344AD675FC5ULL
        }
    },
    {
        {
            0x8E5D5B0C236A5940ULL, 0xAB4F771B23CD7978ULL, 0xC77F0555C0C81121ULL, 0x5DB147D52541D452ULL, 
            0x726F9AE81E2A189CULL, 0x629F1622C6DC56D1ULL, 0xA493CBD9296B28D1ULL, 0x80F5C3FB407A97D7ULL, 
            0xF5B923EA3D25619EULL, 0xC8ACEDBE1C63DEAEULL, 0x337DC7024FF9DACBULL, 0xB8CAB2669B2FD4B5ULL, 
            0x44494E079CE6EF9EULL, 0x93EF400D2772847AULL, 0xE2F8D6EBF7445B58ULL, 0x8455BE8B3C271FB8ULL, 
            0xD0CF24DBBD599AC4ULL, 0x31E5156B66535DD2ULL, 0xF153E01A299B920BULL, 0xF6953ABCBFB03B40ULL, 
            0x09E7496600FAF9B2ULL, 0x374B7E61826AC725ULL, 0x5C9AC00FFAF92285ULL, 0xBDBFEA75F86159B4ULL, 
            0x07ECE32A82F107ECULL, 0x7E4B264721E5BE64ULL, 0x6D632721CC374F87ULL, 0xEEC5C4F4C39D6148ULL, 
            0x2BA13760C4BADCC1ULL, 0x146B2E63CD43CE57ULL, 0x1C39DBD7555A72D7ULL, 0xB35F1F79F43ABD6DULL
        },
        {
            0x88E0F90F6C78820BULL, 0x45D0DB9B784E8867ULL, 0x00B0CA7CE016B2D3ULL, 0xAFB38BBA9E4CF14DULL, 
            0x84572F90C548EA9EULL, 0x51F9735887336FB2ULL, 0xF5958768D35D25EDULL, 0x5A8B715C625716A4ULL, 
            0xE9A0F101687724FEULL, 0x7002477F048C85CBULL, 0xBBFAE35DEFD8C5AAULL, 0xA9C1134883BFD774ULL, 
            0x975F4FE7E193EF65ULL, 0x7322061E2D70EBFEULL, 0xA6EA271F35C02199ULL, 0x32CF0AAD0E897199ULL, 
            0x3FED1DF156DD6BAEULL, 0x051F5798CCFE7DECULL, 0xFC1A4E4E28A3ECF2ULL, 0x2013C7CEDDC15A29ULL, 
            0xB9561AEEFA69A4AEULL, 0xAA173366E24D1FEFULL, 0xF63BCB413A5FCA54ULL, 0x03EC625B0076AE1EULL, 
            0x8C6990286ABEB4C5ULL, 0xD4E3D8E9336C26F0ULL, 0xED5E206DC17B5970ULL, 0xCD5595F3FF564367ULL, 
            0x24BF74E16314E255ULL, 0x645EF5DE673110DFULL, 0x8EDF9CB42290E4E1ULL, 0x061F54CB8DBC49BAULL
        },
        {
            0xED6E0E8A6F352CC9ULL, 0xEA0AA666545B3ABAULL, 0xC8E066EF238B25E8ULL, 0x587E28D4FEB06815ULL, 
            0x108DBEC3AE738918ULL, 0xFECFA69F8582646AULL, 0x58C441DE792D3E6FULL, 0x015AB67C1A9BCB8CULL, 
            0x7BC6D0F82AA968ACULL, 0xE6040504CD27CD19ULL, 0x2003D252CBF396BAULL, 0x1833DFDBB3B4714AULL, 
            0x4D0218FDCF3C1AEEULL, 0x9EED4F4D948247CBULL, 0x34F37B336DC6ED24ULL, 0xF205EF0222B2E94BULL, 
            0x4B10CEF04AA75F3DULL, 0x011DB5551674C89FULL, 0x3B50E334DB7FBF59ULL, 0xAE091B918578F87CULL, 
            0x959C4522C9DBD7B2ULL, 0x4E5043B6A4216116ULL, 0x7190D92195783241ULL, 0x90BE39365B7D4CCFULL, 
            0x2404B5AD7A7DCBC8ULL, 0x1C61370607CA5977ULL, 0xC0A630D75C029A2BULL, 0x682BC74E12F4E553ULL, 
            0x326B510A734D776DULL, 0x54D6956F83FB58DFULL, 0x2B8D456AB5F4077FULL, 0xACE65A30D0385472ULL
        },
        {
            0x4E0421A166A7E8F7ULL, 0xAABB0A641CDE2876ULL, 0xEE90D75715F7E205ULL, 0x446B51055F549D77ULL, 
            0xF7B58EE5057EBFAFULL, 0xEEEE9C8063B4EEAFULL, 0x5C840E04E13636ABULL, 0x18B112B31B72ED65ULL, 
            0xBE54D45876E2A702ULL, 0xE3845DCF4EDECCD8ULL, 0x3C0487AE491BF4A2ULL, 0x61F87E6D8AA1001FULL, 
            0x74374072DC45B580ULL, 0xFFE44F5815F7D0E1ULL, 0x574EC2F6BC22B65CULL, 0x5A62326E8D456353ULL, 
            0xA3336B16A2DC9A56ULL, 0x4B3B6C130937B02BULL, 0x0313ACBC3DF8D257ULL, 0xAB67B438EA0A7931ULL, 
            0xA845F92376905B00ULL, 0x44BC75641FA7E963ULL, 0xE64D3675B9AAA46DULL, 0xF550D9F687E924C4ULL, 
            0x6DB20D62C33AC3CFULL, 0x65C216D24308CBFBULL, 0x9DA00F8C10C06474ULL, 0x625C482B79C7233DULL, 
            0x1B25ED11BF0E3BE4ULL, 0x4374CC16DC20D6EBULL, 0x10092BC61CB8A68FULL, 0x722996BC7649744BULL
        },
        {
            0x7BFD2A20FAF3631EULL, 0x2F3CE41CA6D4C4E4ULL, 0xBF3871CD8A9497DCULL, 0xAAA9E7DA67D98622ULL, 
            0x8DC4C58FED931B0DULL, 0x47ED29F881F6C525ULL, 0x80E232A9D342913CULL, 0x8CBBBEED7FC8EA41ULL, 
            0xFA75900BC8B473F7ULL, 0x76CA21DC2913B362ULL, 0xDBD21FB57200A40DULL, 0x919B29FEAB9CDB27ULL, 
            0xD08ACA718ED829D8ULL, 0x6639FF3FCC6CAD0FULL, 0xFAE6F4B138B761C4ULL, 0xE2AB3BEA584C4CD1ULL, 
            0xE2CEC3E022F4643AULL, 0xD22BBB8AA8474EC1ULL, 0xD5D8B98341D2DB18ULL, 0x63DBB985C5F86106ULL, 
            0x320A0E769B3B291CULL, 0x12FDC5D403E504FFULL, 0x5C083071F2D2D006ULL, 0x0E88200D5193C3AEULL, 
            0x3A6684C1688EF8FFULL, 0xA54889F02D7B4580ULL, 0xE9BEE1DCE67E0FE6ULL, 0xAE969631B5E5E30EULL, 
            0x471210472D286C98ULL, 0x4F37A7778EC4D8B6ULL, 0x3BC32BA949D80E5BULL, 0xB6BE299BDF0D5FDCULL
        },
        {
            0x426FFC8C2A637511ULL, 0x7418D909BDB2D902ULL, 0xFC6925A8FB66F22DULL, 0x111B77FF151049CCULL, 
            0x7092038CC1C9F699ULL, 0x3181F8D57ABF6075ULL, 0xE8251B0CFCD232D8ULL, 0x448483575ABDCE88ULL, 
            0x4579CC8D6B661072ULL, 0x50F466BF288AD79FULL, 0x6EFDFFCED0814C6BULL, 0x5BE8FF9968BB10B3ULL, 
            0x1D847F1CB8CE79C3ULL, 0xDEDA3AC5092D9F1AULL, 0x28B4E600F17C7C12ULL, 0xF321B58F0C4ED87AULL, 
            0x3C9B153672E13364ULL, 0xF6CCCF314B60605AULL, 0x1359B36C830B0A97ULL, 0xE9B166B349391C5DULL, 
            0x6377DE1FAD110183ULL, 0x13A054DDA6BA098DULL, 0xF61912CA81EF6A17ULL, 0xA16AD1F5AF3C3D53ULL, 
            0x1BC296E1CECDABD5ULL, 0xCA20E51E723759F2ULL, 0xA011668E4768933DULL, 0x3726F282E3421E87ULL, 
            0xDF93E10158F59972ULL, 0x468A5C253F9EAF31ULL, 0x9439E40879E9F478ULL, 0xB147944EC7D66D71ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseFConstants = {
    0x3FF0A8965DE9E57DULL,
    0xE6F4BDC7AEF2AE61ULL,
    0x0BA0E86F2B67A08EULL,
    0x3FF0A8965DE9E57DULL,
    0xE6F4BDC7AEF2AE61ULL,
    0x0BA0E86F2B67A08EULL,
    0xC1DE7E11F7469929ULL,
    0x7C9079031286E4F2ULL,
    0xD5,
    0xE1,
    0xB4,
    0x63,
    0x86,
    0x56,
    0xEF,
    0x93
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseGSalts = {
    {
        {
            0xA3A8685E1A00AEB3ULL, 0x1231A27DE3E2E58CULL, 0x6B621DE4DF42D9C3ULL, 0x5A51C2D1B22449D2ULL, 
            0x29A44B003E5499C4ULL, 0x47A64AAA69E1562DULL, 0x6DD325161556A3C1ULL, 0x09A37D6B99A30A30ULL, 
            0x81C8F0889D77BFC9ULL, 0x6ED11D6DB37D84A3ULL, 0x4B637A1A6A7664A2ULL, 0xBAB8406101D86C47ULL, 
            0x8309DAF4C6D1AA0EULL, 0xE499320496DECBC7ULL, 0x2E89CD6B80C89220ULL, 0x43D0848AF5DEC190ULL, 
            0x0B31B5AF261E1F9FULL, 0xA9B0343D80B3C8A1ULL, 0x035B7025DED24E16ULL, 0x73396C6B4026006CULL, 
            0xCFC9DF66A17A463BULL, 0x95A2059694294C75ULL, 0x23A4E23DC342762CULL, 0x094566A1538A7114ULL, 
            0x7688AC3C87B27CD7ULL, 0x721FAAF3D03C5056ULL, 0x1E227FAA053CECD4ULL, 0xBE8EB5FC2C7B12C2ULL, 
            0x2CF406952917E3C1ULL, 0xD84CA43CFC201225ULL, 0x30BB979D889E4292ULL, 0xA13127EC9A7A7D23ULL
        },
        {
            0x1C0572C2801F76A1ULL, 0x5ADB7905F0A0FA2AULL, 0xD58231530E707EC3ULL, 0x01CC6BE1C5A46D56ULL, 
            0x5BDC62BAB1CE7995ULL, 0x6891E647F1E8B62EULL, 0xB4C0A5B4A18EB5EDULL, 0x94E99356A5CAFE6CULL, 
            0xFEC2B512344EDB14ULL, 0xBDE54C916F0968FAULL, 0x7AC74C2933276F97ULL, 0xBFCE93AAB3B395D3ULL, 
            0x64E80E96EE9B331EULL, 0x56FA35382F99A638ULL, 0x50A82BDF4F660952ULL, 0x73985B0339BC1B65ULL, 
            0xF0F3026A2ABDA55AULL, 0xEAF1F21E7579B81CULL, 0x23E6C44E7351FF6BULL, 0x8D282CE21D128B59ULL, 
            0x1414EDBAEE9BD2B2ULL, 0xBE57F27BEAB74E58ULL, 0xDE8090949B4A2679ULL, 0xE13B367E4142D242ULL, 
            0x247AE527D56EBA23ULL, 0x2B89C3ED6EAD86C3ULL, 0xB861CDAA18699129ULL, 0x388C8D46CA19750EULL, 
            0x316B654C07A9F2ACULL, 0x83708B9926C2976EULL, 0xC46A477D00FD2B04ULL, 0x208BCD37487590DFULL
        },
        {
            0x38DC416EEBDB8333ULL, 0x47EBED72BD376E94ULL, 0xA1C3B42EB737EB5CULL, 0xA0F9FDB11F7F1661ULL, 
            0xB3F82AD52B268C79ULL, 0x60543186BE0104BEULL, 0xE774ACDB79E9E08BULL, 0x0E1FEC9C0D579FA4ULL, 
            0x1B06BAB73BB408EDULL, 0xC97E946705B0DF58ULL, 0xD2A1FC1470337D20ULL, 0x4B28175CC62D28B6ULL, 
            0x0B67F05A013053C4ULL, 0x8D9D5C4ACA0ABCA5ULL, 0x5AF3E758662E0993ULL, 0x09C7105BB313605AULL, 
            0x8A22AA05464FFA56ULL, 0x6E0D2DC725E6CBD2ULL, 0x637E4BE023B4255FULL, 0x24709DF0193EC15EULL, 
            0xB9CB9ACBD8C8F43BULL, 0x106BA064F02FF6A4ULL, 0xC40622D5F7CD904EULL, 0xD2F33687A54B3C45ULL, 
            0xE36ECCA4A7D8D350ULL, 0x44D9006546B8673EULL, 0x252188B2BB6539E1ULL, 0x84FC6AE7E38ACE64ULL, 
            0x3977BDAF6EE023F5ULL, 0xACA3E21D11C31B84ULL, 0xFAF1C57534310737ULL, 0xCB64B5E822A1C702ULL
        },
        {
            0x0BEB2083F2B6D33BULL, 0x31028B5D798D00A7ULL, 0xB6656D333680DDFCULL, 0xDA6BDA39171F06DEULL, 
            0x2EF0563B2DF41116ULL, 0xB420D18FEC2B76A4ULL, 0x2DB8FAB90C3F5697ULL, 0xA1DC4E279A0B7FB3ULL, 
            0x5A97A651CE13D087ULL, 0xDFDB6B699587BAE4ULL, 0x4065F84F1A6BC724ULL, 0x775665951BD61134ULL, 
            0x26AE11C6D22CB485ULL, 0xE9C563846FD2B263ULL, 0x571A0F74A4C25A0FULL, 0x42D3C62FEAB689B6ULL, 
            0x50D5BE7D9CF89782ULL, 0x8F5E04E44C0FB0F6ULL, 0x7C33883C1660A2B5ULL, 0x5785A8200A3BAEC8ULL, 
            0xFBA9D8D9818E7452ULL, 0x35A2FD4CB980FE33ULL, 0xFDD345527DC353D1ULL, 0xF40792A697ACE2E2ULL, 
            0x157F755131D79DB5ULL, 0xC6D2A523E72CB367ULL, 0xA2C4CA34470E3550ULL, 0xD899E7FA1EECBA56ULL, 
            0x96F88D9B6DA102E0ULL, 0x522EB02D977A1A06ULL, 0xEFF3D5DD8A00CB6CULL, 0xAF7F9D2B742AF040ULL
        },
        {
            0xF06E727C6D8AC4FEULL, 0xB08EC80392446543ULL, 0x12CAB8E80553F78BULL, 0x11873ABF20674BEFULL, 
            0xDA2EAD59AD3A6A6DULL, 0x5E1CBB5605A1E052ULL, 0x0B6E6F3BFB94F11AULL, 0xE40723562F688929ULL, 
            0x076117A27F5412ADULL, 0xA69A408B328B299FULL, 0x6E4EEF5C0722941DULL, 0xF1AFC97E940C9066ULL, 
            0x510064D6399D15C8ULL, 0xA645AB265A04F310ULL, 0x1572C2AFF5542899ULL, 0xCE4CF2AACEF110ECULL, 
            0x620EBAC0407FB3A4ULL, 0xB7C8FAC91E33F7A1ULL, 0x0D66F3161BE1F13CULL, 0x78987DE2FF6C60BCULL, 
            0x86148A3195AD9371ULL, 0x07DDBF6BFFB702BCULL, 0x96AFB0936E8BAEB7ULL, 0xBA636CF40AAB0D59ULL, 
            0xF6E1D6C5AF9A2780ULL, 0xC200E342F60656BFULL, 0x17A65FD15799959FULL, 0xBFB0722526C1662AULL, 
            0x6BCAFF4957BFAF7FULL, 0x593F7FF5AD1C5D86ULL, 0x89AB0A85EBC2E802ULL, 0x32F7EE6BFE764500ULL
        },
        {
            0xA50D84ED9567CEF1ULL, 0x3FA9F0B2BB786BE1ULL, 0x6A3E1A491A013BD4ULL, 0x051981906AD89F15ULL, 
            0x31A5938AF2CAD82CULL, 0x59A30E3531A76E31ULL, 0xF9C9E65D1FDF2FE7ULL, 0xABBA0DF694D066AEULL, 
            0x7946694796AB732CULL, 0xDDEE2F1E75A4EAAAULL, 0xA7890A5BD863FD5CULL, 0xA2FA4EB11105174BULL, 
            0xB9C7B7ACD52F9A73ULL, 0x1E753F5B5D5912CEULL, 0x90D762D8BDFAAFFFULL, 0xF529567E944F5339ULL, 
            0x1621D1653E47435DULL, 0xFDD5C65DB5205491ULL, 0x01652C7E6B6960D2ULL, 0xEF7434B753FB4154ULL, 
            0x4DC5211411AF1D84ULL, 0x1B47D9BC4859C28FULL, 0xFEC428BCDDFE7B15ULL, 0xCBF8B0E2BA2DC073ULL, 
            0x83F8B41A2384CFACULL, 0xC277A8B51E435D9CULL, 0x0A68492212D5934BULL, 0xFF770C8738E0445FULL, 
            0x3DD526E03E699F37ULL, 0xA8A91649EF76C34DULL, 0x185A3510FFD8B270ULL, 0x88B092FBD4990BD3ULL
        }
    },
    {
        {
            0xB14EF87F55E8214DULL, 0x17CC18493C340BADULL, 0xE409E7F5CAAE8D4BULL, 0xAFF9A7DC42129A26ULL, 
            0x2BA8D37FFFCCB96BULL, 0xAB28AFE4C7FE272AULL, 0xA8223D58AB35022DULL, 0xF338FE681A40521DULL, 
            0x5F27E30AD0FE7A2BULL, 0x3C53BB59AD5EC8EFULL, 0xC5DC34C97BF70649ULL, 0x972FB2A926E45926ULL, 
            0xAE6673CF227B445BULL, 0x0B8B4C5FBA950747ULL, 0x00BA9A477CD5DE93ULL, 0xA4AFCE643389CBA8ULL, 
            0x8CBE075C9BE608ABULL, 0x22B62D01237FB7EAULL, 0x4CCF24364081E087ULL, 0x23F7D26E50D491FAULL, 
            0xE0DF293FB4F8FC58ULL, 0x95FA8EDBA6DDDE99ULL, 0x19F1CD57D00B1A43ULL, 0x7D34A880B7F4C9B1ULL, 
            0x3DB953A0FDA0B770ULL, 0xF17811515EE93477ULL, 0xBEF5F1C67FFA7740ULL, 0x6E54511C9EB2625CULL, 
            0x92BBCDD2F921A5E3ULL, 0x62396A13B21E22E6ULL, 0x5F7A6A75D5795023ULL, 0xABFCC8A31C42D4D5ULL
        },
        {
            0x350CF1736D6E0837ULL, 0x814157AB301CD589ULL, 0x63C3B6247C5BF0FFULL, 0x6B9ED2BB41484659ULL, 
            0xC91123DD6C1442BDULL, 0x93A497CFCBB3D318ULL, 0xAE026FCEAC6FFD02ULL, 0x81E59CA4AE17F915ULL, 
            0x431981311E5357F9ULL, 0xAE7E243BC0B05C0DULL, 0xC51A5A6977D5B65DULL, 0x6E11DA23CB55B193ULL, 
            0xDAF0F52B7C9F50CFULL, 0xD80A10F2D7FE1EF9ULL, 0xEC33190F24184452ULL, 0xDE4D8AA798004C29ULL, 
            0xCB842D708A1CBECFULL, 0x2F17107D9D1E3975ULL, 0xC343ECCC143B8AFAULL, 0xF03E434E5B227FD2ULL, 
            0x6BBFBA557240A2D7ULL, 0x077C28CB240E0409ULL, 0xE06907E7C7B9442FULL, 0x5623ED39CE2494FBULL, 
            0x627A5F76F0255148ULL, 0x4EC715F97FF808ECULL, 0x6F2A5F61116027C5ULL, 0x221D12347A8C42D6ULL, 
            0xB62931B8B8262CEFULL, 0xDF394CA2A35CF096ULL, 0xFC11C9CF4509F9EAULL, 0x646B103293DE061AULL
        },
        {
            0x52CB6B1FFDA99BB1ULL, 0x75B0FEA75F28CBC5ULL, 0xC271D624A02576D0ULL, 0xB687710337E329B1ULL, 
            0x367034E33FAB9142ULL, 0xD00FC3DC2F48427EULL, 0xF803215C92C88FD5ULL, 0x44129022C5E526FDULL, 
            0xA20CE80265410351ULL, 0x3EE11719790257B6ULL, 0x2D64A00C6A7F53FBULL, 0x6A63F7C477415BCAULL, 
            0x98C9EFDAF58A5D0DULL, 0xFA79671260E3535BULL, 0x387D4E6D4E73D2A5ULL, 0xCDE97D65237FF075ULL, 
            0x9FD4128F3B779F1AULL, 0x67A580C933A75A66ULL, 0x53FD940FB66C4A47ULL, 0x3790893A2B7D10BCULL, 
            0xF7882623DECE6713ULL, 0x9C8EB4C72E2EA314ULL, 0xF46827A4AD38B71FULL, 0x25AA0690A29A6417ULL, 
            0x2FCD5B7DA1D27C13ULL, 0xB772C151F11E6C1CULL, 0x526F8406E81C5AFBULL, 0x0D0B2FBE6EB82DDAULL, 
            0xB85D2FB49D8B3983ULL, 0xCE5E2D1067DC33E9ULL, 0xFEEA2257650B674DULL, 0xB0177D003183CBBBULL
        },
        {
            0xF3E84CB241EBFDA0ULL, 0x7E3F3D6BD7D076F0ULL, 0x21E2CCE73CD1C9A4ULL, 0xE7B93319504F4C91ULL, 
            0x47C62157E76BDDD7ULL, 0xCCD2D0A0CCEB8FD4ULL, 0xE018F65319DB6AE7ULL, 0x69CE7CA14CFA78F8ULL, 
            0x1C05EBE7C37B21ADULL, 0x06B298C5AD3F7705ULL, 0xB6B9405A18BE4ED1ULL, 0xC87EE85DFA33C4D9ULL, 
            0x13260250E378067BULL, 0x62EAE9E010B8725EULL, 0x5B76001C1FCB5678ULL, 0x57E4E3BBB51A2B5EULL, 
            0x28E3731CAEAF08F8ULL, 0x6BC41834B926482DULL, 0x953EB28B81B6345DULL, 0x14AA3E1E13E1679FULL, 
            0x704540319CBA8A27ULL, 0x976B4AC4799507F8ULL, 0x9A4F6BAB843EF306ULL, 0xDF5DCCA60450F409ULL, 
            0x7BB165F37DABD1A2ULL, 0xC73447B5C276AA8BULL, 0x16091F3A0CF8CEFBULL, 0x8B643712C6F83E9FULL, 
            0x114C6F990F57A9CEULL, 0x08B32C00C29C9F94ULL, 0x47D392314BFF7EFFULL, 0x9F9D7E73233201E9ULL
        },
        {
            0x9F127D972DFE225CULL, 0xBA81E52AF61B1330ULL, 0x9ABE83C20B22198CULL, 0x93679B2DE757C7F1ULL, 
            0x5E2102C4C6B914BEULL, 0x49E7E4917298730BULL, 0x4117E50B085F5BB7ULL, 0x7D0EC49C54D6A13BULL, 
            0x0E2E5689F8D0FD64ULL, 0x16C479823DCDE455ULL, 0x476446D108BE47CDULL, 0xE318538B1789F88AULL, 
            0xA70959DB3FE60396ULL, 0x5BD7FD1DEB68977EULL, 0xD9268BE8F5CF248DULL, 0x7622EF45875164DAULL, 
            0xB8FB8E1BB07C6CEDULL, 0xFE4519802F56B763ULL, 0x4BDFBFC4487A01EEULL, 0xBBCE16A457D73816ULL, 
            0xF31A2B89FE9E1FDAULL, 0x17AA6A829187E28EULL, 0x5D2F5B85FCB6741FULL, 0xC6680422E60B6596ULL, 
            0x80FF352BCF365D52ULL, 0xC6A5E8FADF47D11BULL, 0x5556F3F988EFBD38ULL, 0xF7C8E65EA8B26103ULL, 
            0x6440211C1E5EE4A9ULL, 0xA950586552D7AF57ULL, 0x18D66AA478D55CFBULL, 0x96BB921C04D1FC5FULL
        },
        {
            0x0C3C9BF18A5F62B7ULL, 0x498081BA7D4E766AULL, 0xF6CBBC2B1D5879F9ULL, 0x359B9116FD1CA997ULL, 
            0x22E7142B5AC7626AULL, 0xE08E43CDC4C281D8ULL, 0x594CB5D872FD2324ULL, 0x0F164A0723A5FB02ULL, 
            0xEC193DE873E2B87DULL, 0x9C337F0CA6DB558EULL, 0xBB825B5DA7A89D85ULL, 0x60108D148A317A53ULL, 
            0x486EBE48E38D7014ULL, 0x4EA4B59C1D44B5EAULL, 0xDD7E3F5757647AD6ULL, 0x52E6FC1E3F75A150ULL, 
            0x110B5AA87F76FD8AULL, 0x982CE65C152AC243ULL, 0x526D75B2B90EC9D4ULL, 0x89982E7C0B3C3DFCULL, 
            0x54CAC9720D28B560ULL, 0x3B13A3E194BA298BULL, 0x85F37285E2BD02CDULL, 0xE9B89CCF2320B810ULL, 
            0xC6D081D6702DC18BULL, 0xA161E31AFC58A4CDULL, 0xED78A1138E32869BULL, 0xA47B9B3061D80ADDULL, 
            0x67260F6C5A4B4D32ULL, 0x6941F15876A2B52CULL, 0xEDB2410ACB0ACCE6ULL, 0xC958758C344F3729ULL
        }
    },
    {
        {
            0xC52AC8817DFEAECEULL, 0x8E7DEE689766E113ULL, 0x0C0493D803A30AD4ULL, 0xACE66C648F83E937ULL, 
            0x6D51622ACCB8801EULL, 0xC969BFB842394BC3ULL, 0x5C370CD8DA80D534ULL, 0xD7C85725C0033946ULL, 
            0x847B95F28459D692ULL, 0xE04006C34B8F8901ULL, 0x85F3BB12DB44C486ULL, 0xFDEAFBBD917F2C1AULL, 
            0x8ACE41C8F6471AFAULL, 0x53AA069DC09E2DDDULL, 0xE057C8C893BB6093ULL, 0x74B8CE0EEAD8D632ULL, 
            0x037DDCFCC7050343ULL, 0xE3186BC54797F04CULL, 0xD585598613C0E731ULL, 0xD2CBDE688B0FE372ULL, 
            0x1DF5F4F8292FEE2CULL, 0x9A47579C9120E770ULL, 0x030EF2C5C2A7348DULL, 0x747DE542E194D108ULL, 
            0x1D4396FAE3C827FDULL, 0x249A19C25617B7E3ULL, 0xF8C3C20E576A1FA6ULL, 0x5800E9868D6537C5ULL, 
            0xDE784374C89F1473ULL, 0x20024CDDE39360E6ULL, 0x657EC1065CA46FB5ULL, 0x74B3F43A4CF79F0CULL
        },
        {
            0xB17345D1EDB042ACULL, 0xCFCD08445CA30BA0ULL, 0xD237F1BD1DF0AD2EULL, 0x6E1FCB2022BB742FULL, 
            0x39C099C2A49D7744ULL, 0xD58BD8A410075F60ULL, 0x231B628A9AC9C04DULL, 0x62ED708602C06D54ULL, 
            0xD2129EFC50B62930ULL, 0x0C710A2FEF936AE7ULL, 0xCAE0FE22C11C63F7ULL, 0x19714774AEFB8658ULL, 
            0x60D47C678DC3A6C4ULL, 0x3AA5256C208F3BA0ULL, 0x1BE2AC22230CD655ULL, 0xBB639A3A0963A971ULL, 
            0x09B62B4E7D738DE3ULL, 0xD4CE998EEBB40284ULL, 0x7AFC8DD3AA77FCE3ULL, 0xE03B563E7DFEEB65ULL, 
            0xF0006F11A4B08B6FULL, 0x85F0DFC8260E50F9ULL, 0x935A6DFE4A738CB7ULL, 0x6D69D6544FA88A3AULL, 
            0x2A9D38D6E013ED82ULL, 0xADD357CC1F27066FULL, 0xD656AF20F31B3461ULL, 0x2511174A70C39CAAULL, 
            0xD4787E9F53AA674EULL, 0x78D06F5AAB21B99BULL, 0x0A25EED6715E080CULL, 0xBEDC1FDB2B861D71ULL
        },
        {
            0xC1D2989F7EA74CA7ULL, 0xA5A038C45652EB77ULL, 0x7493D9CD36A0F1E2ULL, 0xF7016FABDDE3DDC3ULL, 
            0x716D5D0792F3D861ULL, 0xE76F61CAA00F933AULL, 0xB1C52ACCFEB9D8CEULL, 0xD597C460E41B7397ULL, 
            0x73403929F133AD11ULL, 0xD267ED5725611749ULL, 0x76CA78204F2A855BULL, 0x6B05A6B6D3A4A7D9ULL, 
            0x15E4000EACC94729ULL, 0x3133329A851246BDULL, 0xF0A42D4B77FC2906ULL, 0x33906A3CC9982AB1ULL, 
            0xC7B476577A44A933ULL, 0x46A26C1C36A3C49FULL, 0xA9C5FDAC605212DAULL, 0x92ECC06E072326ACULL, 
            0xE47071FBF2EA2CD4ULL, 0x73CEDB0E560E53F4ULL, 0xAEF427E8A7B33064ULL, 0x9400C2ECBC3BDB65ULL, 
            0x652637412D02CE9CULL, 0xA2C45381F1459C12ULL, 0x69C5EAC3B877CB03ULL, 0x0D720420C632E733ULL, 
            0xFFDFE01D842DC82DULL, 0x7C730E1CA4D5F19EULL, 0x798A37F6677A70A4ULL, 0x728A2E868D9439E2ULL
        },
        {
            0x48A5D2C89211ABE4ULL, 0xB3EB7CD005A0F7DFULL, 0x297BA48F3D6CF783ULL, 0xA4ADB5316451B056ULL, 
            0xEEC03D4D456B5E9BULL, 0x4A6569BCAD36EC42ULL, 0x3DFD384DE6CC2831ULL, 0x985166316BC37430ULL, 
            0xAF792CB28D1D6734ULL, 0xD9113782C1264C8AULL, 0x3E0A5F32A95A4B24ULL, 0x3F642D8C03E0641BULL, 
            0x54E0C65C8A211B45ULL, 0xD28E6C16E12AADACULL, 0xA3390F48579C9A86ULL, 0xF9516598CF773010ULL, 
            0x4F3D53891BE8082CULL, 0x4273F437378A2396ULL, 0x2C9AF26547A630DAULL, 0x314478BDEA111871ULL, 
            0x1B32B41D6246D680ULL, 0xC0C34F9081DF96AEULL, 0xA6CD0D858D0B7807ULL, 0xF4D9059DF9C40301ULL, 
            0x15AC4CB96C8E8D43ULL, 0xE0D066BD4F7A0064ULL, 0x9CAB496A155C6922ULL, 0x023529266C088F00ULL, 
            0x7EC6016923E1073BULL, 0x26D14F5B250D0DDDULL, 0xCF985FB500D77D10ULL, 0x1BA109B8002D96E3ULL
        },
        {
            0x3A6A98CCDD17818EULL, 0x2791E9E7CECFDD5EULL, 0x47AEAEE14995EC31ULL, 0x1A67F0CBE67D7697ULL, 
            0x0C77A16731040944ULL, 0xABA3179A4E3D174BULL, 0xC79801A93E356DC8ULL, 0x452F3EB58457D436ULL, 
            0x7A81F6FC37216267ULL, 0x42E565578E3F40D4ULL, 0xB9584CB5B9E28A32ULL, 0xC374A6805FEF443FULL, 
            0xEBA1DFD944AEE7D7ULL, 0x0F411C030ED22BFDULL, 0x2948FE81EC876523ULL, 0x60BA45D2F82699E7ULL, 
            0x7CEB68069F8C08EEULL, 0x8921ADF2BE4D05BDULL, 0x8ACFBBE53984A064ULL, 0x2CC5147A4B9F56F1ULL, 
            0x04ADDCADE6C2913CULL, 0x3EB34A7D5905C27DULL, 0x109E3D91F190965FULL, 0x05171CA646EAC375ULL, 
            0x8D122A70D32D73CCULL, 0x1ECCF6DD99F2575FULL, 0x43FD9840827685A9ULL, 0x78D7EEAD1304B4DDULL, 
            0xDF72380F336F874AULL, 0xDCBD410A59829CC0ULL, 0xBDC2715CDEB93EB2ULL, 0xB47052CA326F5AA8ULL
        },
        {
            0x0E686E7A69B4D469ULL, 0xC56D3900F6045B56ULL, 0xA40B6A32A4CC75B6ULL, 0xB879F664CD1A8B76ULL, 
            0x96AC6A64900F5EB5ULL, 0xFE7A3C521C189077ULL, 0x6D05BA6B6FFCAA22ULL, 0x9CC310765170C972ULL, 
            0xEA308F236C1EF895ULL, 0x7F26281E10A4523BULL, 0xB239F8A3AA97E517ULL, 0xF6C415DD11572D3CULL, 
            0xE246220D68B1F1A5ULL, 0x3E7D36B1F1D11178ULL, 0xDD01E8FC16FDAB03ULL, 0x07DC0F145DF1C5C3ULL, 
            0xD50D76407A5675B9ULL, 0x8E6A95F09ECA925EULL, 0x3C77FD08DC5F0FD3ULL, 0xF8CADA1F5D75B29EULL, 
            0x64CB71FBCB1769A6ULL, 0xDB932B5DB5BA2219ULL, 0x7AA1921949FC7BF7ULL, 0xC390461117C37939ULL, 
            0xDCBC4F9D43BBC34EULL, 0x9E28BFBEB4C67E9DULL, 0xF1DCEDE348267BFBULL, 0x878CBDE0549F4C49ULL, 
            0x1B02CD228858CF4AULL, 0x0A70BC3C06CFE448ULL, 0x9A3F57123B66F270ULL, 0x8A19BF90BC846438ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseGConstants = {
    0xEA25EF1E9C5CE552ULL,
    0x0F47E566E816D951ULL,
    0xC7875CDCB22B5A3AULL,
    0xEA25EF1E9C5CE552ULL,
    0x0F47E566E816D951ULL,
    0xC7875CDCB22B5A3AULL,
    0x47E2EA8B2BE1129DULL,
    0xD31AA419095D3F6DULL,
    0x3D,
    0x08,
    0x56,
    0x24,
    0xC5,
    0xF6,
    0x09,
    0xD7
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseHSalts = {
    {
        {
            0x53658797A76A2A20ULL, 0x93AF51574174FFACULL, 0x9C5BCF481963F54BULL, 0xE636EDDE3C5A0320ULL, 
            0x5772B9E41D26D1CEULL, 0xA9370A19F02485AFULL, 0x3FDCD7F3D995B24FULL, 0xC9A048F132F14959ULL, 
            0x1A9DD8E9FB8A8E42ULL, 0xC186BD14F1274169ULL, 0xA21783DF160BE866ULL, 0x5CC98F5868B54C1EULL, 
            0x0C95436DE858B360ULL, 0x2DA7A8705AEAAF72ULL, 0x9BA0B828E25EFCB7ULL, 0x27AD9E5D8FB22B85ULL, 
            0x93380CB48CC99993ULL, 0xAE8F1FEB6329F4B6ULL, 0xDC57B7B004D83D59ULL, 0xD32C7B07245D5677ULL, 
            0x28483BF4A53F0A91ULL, 0x077D0517991C81A7ULL, 0x9B16D6521804B36EULL, 0x30F4F3AAD1B253F1ULL, 
            0x21BA115A85708927ULL, 0x283E1139A065585EULL, 0x400EA9D2D6CBD952ULL, 0xE1D54C36255DEDA2ULL, 
            0xF4CE64324D6FEE01ULL, 0xEDC703C65B2562C6ULL, 0x6F0AD2491675F3A7ULL, 0xE7E18358D3F845BEULL
        },
        {
            0x398F9AD0BA8A8FF1ULL, 0x9158CD4D1C79EA05ULL, 0xB33DE8B9DC480B76ULL, 0x2928BA7AA106AA01ULL, 
            0x3F2CE510AC16B25CULL, 0x43223475D8F9C72EULL, 0x6CA509CDE87C0D20ULL, 0x2AA6E7A4A7AA520AULL, 
            0x4C6EA30DD205C3A0ULL, 0x2BAFB792F5A091C3ULL, 0x8E6AAF6BF04762DCULL, 0x417A742B7E74050FULL, 
            0xE4E6B4E8B97F1189ULL, 0x0706B662928A48C3ULL, 0x8FE021FCA85D2DE3ULL, 0x3EEAA87F2E56F7E5ULL, 
            0x251918CE98500451ULL, 0x787384839EDE5062ULL, 0xFAC5E3886A768297ULL, 0x238A80DDF6CBE02AULL, 
            0x89427ECE0B8DA9DAULL, 0xB6A0031B3753FAA1ULL, 0x4A4C66A610EDF7CDULL, 0xDBE4CDB31974D05CULL, 
            0x9F99603B09FB0AD4ULL, 0x5DAB7AB4011A8861ULL, 0xFA359723BA9CCA6AULL, 0xA41019259A4149D7ULL, 
            0x61C91837E9677170ULL, 0x9EF9FA8AC40C31C1ULL, 0x6C10C29758CFC6E8ULL, 0x4ABA9E19F70C0016ULL
        },
        {
            0x2E2EDAC563ADA253ULL, 0xFB93690BE1D65B34ULL, 0xD70DBD57FF9BA5FAULL, 0xFB4C61116E6A0819ULL, 
            0x1A5D2D3A017C0327ULL, 0x66F4364A1155E487ULL, 0x3FC8E25FA98A6E43ULL, 0x49A7B569485A876FULL, 
            0x660C65234C1CF0C2ULL, 0x0F436194EA7F5A3FULL, 0xAA238E26276834D8ULL, 0x9EFF83B173D633B1ULL, 
            0x7200A6A129FE9E18ULL, 0x24E7AD57E06B58DAULL, 0xA92F2E24A6AA5AA2ULL, 0x1492ABF9F237FA03ULL, 
            0x9DF90A1A68CB8B9EULL, 0x284525B221B4F402ULL, 0xCAEA84C1D7BDD207ULL, 0x4ABF9EE29C02EE28ULL, 
            0x26D5293B624413F3ULL, 0x46F252EC1AB8AF81ULL, 0x8254D438F472F375ULL, 0xA48140898AE1A2A5ULL, 
            0x3C803C61C1B69105ULL, 0xBC232BBB32BDA6DFULL, 0xDC3EF948676F17E2ULL, 0xE8FE9767E4D588A1ULL, 
            0xD0CDC645C0D00CD1ULL, 0x6EDD10CB3FBD4F0FULL, 0xD6D8DC3EA4C0AA63ULL, 0x8B4D8C393F428914ULL
        },
        {
            0x7CEEAC7FF726AC1CULL, 0x6681FD511F2D62EAULL, 0x653FA45A10BC92EBULL, 0x5164BDBE7881B009ULL, 
            0x170A1BCDB0B9CBA8ULL, 0x25073FAB2CABC2AAULL, 0xDCD2362B11789BC3ULL, 0x5FE96CC6E41EF278ULL, 
            0xEE49FEA3C6253E12ULL, 0xE3AB8E7FF5BF5E6AULL, 0x8243CE9A9A34C454ULL, 0x68C730A1DA7FE560ULL, 
            0x408F0013B5CEC491ULL, 0xA8F67FE8B23D03C2ULL, 0xD1DA69F399DB1DDBULL, 0x945AFA4B095FDD6BULL, 
            0xAEF543569B8F65C6ULL, 0x2577ED7B61305C50ULL, 0xD5593D8486CC935AULL, 0x783953EE67ED03F6ULL, 
            0x22755F02798F0AB8ULL, 0x03109E9D069F864CULL, 0xA574D18EE1898131ULL, 0x24360302C9BE0192ULL, 
            0x851B25435E9762E7ULL, 0x74BF53E44D65B575ULL, 0xCF89A32EE3069306ULL, 0xC40F51AB8A40D350ULL, 
            0x8B046B76F0573757ULL, 0xC52EA0FAA66FD436ULL, 0x13D2B6F6EF9FBC29ULL, 0x305CB12FCFA896C0ULL
        },
        {
            0xCC18B847967BC56FULL, 0x96A47ED26F4E32ADULL, 0x8804A86A60F85944ULL, 0xD76733452F0AD3E3ULL, 
            0x9EDA301997BEF97FULL, 0xCD9D34BEEAD690C9ULL, 0x8F4F43C9C305A1CDULL, 0xD40F8D93E2533346ULL, 
            0x1A728E77296ABCA7ULL, 0xCF4444A9140AE2C8ULL, 0x2956B580086DF808ULL, 0x4D51A06723EBC145ULL, 
            0xBE2005C4C356E617ULL, 0x997E1211CD2078ACULL, 0x206134D4213D7BBEULL, 0xDDD7DC66D157DA80ULL, 
            0xD54E92B50A279508ULL, 0x506BB9967E9B3B0BULL, 0xA75E4EE65A457166ULL, 0x0CEFBD513D559A76ULL, 
            0x962E37243A099998ULL, 0xFCAD2664C5653165ULL, 0x819AE0A28634C885ULL, 0x4B195C1E2C0FBCBEULL, 
            0xEE258E29EF1B9CD7ULL, 0xE27822B1CDB9C602ULL, 0x5EB246A4D6B92A9FULL, 0x51AE6DB2BE245AC3ULL, 
            0xBAB5955FDEFAB64FULL, 0x7E2AA531705596E9ULL, 0x0CA638218308D141ULL, 0x48DE7A1372B40802ULL
        },
        {
            0xF415B619AB9A4646ULL, 0x1F7F06AE67292DF4ULL, 0xC7AD1AF634BB0056ULL, 0x01B0B2606297CB8FULL, 
            0x835841FAE7ABCD1EULL, 0x1CFBA812B66D58B3ULL, 0xA5182270C243DAA6ULL, 0x672A451FAEAED96BULL, 
            0x1B6C7E3A2CB7D95EULL, 0x21395B2813CE4250ULL, 0xE94E963A5D67F5B0ULL, 0x077234011FA2BFA9ULL, 
            0x6093CC303984E684ULL, 0x0F9F67324F5DB699ULL, 0xCC4A3AEE574977A5ULL, 0x4F93092518AD59EBULL, 
            0x3E7C25E0686E657CULL, 0x2A260D645791B1F5ULL, 0xE5D9A654BDEE1F36ULL, 0x1FDC4D018786D124ULL, 
            0x870756C08C1A53F8ULL, 0x6A367DBE453BF30BULL, 0x39CC0F5E1B07900BULL, 0xF98F0CA3A5B5F267ULL, 
            0x5F6E29F90983C02DULL, 0x29AF113BE13C9716ULL, 0xEC1169DAF5996AE3ULL, 0x30B62C2F0C24C270ULL, 
            0x56FD14F88D8E7270ULL, 0x201E9A2C33DEE2D2ULL, 0xD7A27D53AC96231EULL, 0x948C631FCFC00080ULL
        }
    },
    {
        {
            0xE4A0297900FA958AULL, 0xAFD6C10004119AE6ULL, 0x46E2A87D0F6C5ECEULL, 0x815277A3A230C873ULL, 
            0xFF77AFF270B4098FULL, 0xAB5215E379818E77ULL, 0x5A2499C593AF0385ULL, 0x7687E62F81EAC580ULL, 
            0x92FD01E0B79753EDULL, 0x5A80436BD074BB0EULL, 0x70004224A0C8E178ULL, 0xE32C66B2996759F5ULL, 
            0x6E64AB0A0F8F0283ULL, 0xBAAB36F9144ABFE7ULL, 0x658395E8DC29BADAULL, 0xABD7D521CA86D7EEULL, 
            0x9EFCCBD78971E0FAULL, 0xF5CC60190A957651ULL, 0xC9B3C1678F78543AULL, 0xC0749601463C9258ULL, 
            0x44E34DC00E4ABA24ULL, 0x4721160F2AFA5768ULL, 0x1FDA2D9703CEDEF5ULL, 0x33A560D2569401AFULL, 
            0x72704C2480D0CC8FULL, 0x7488C5B4CE7BDE60ULL, 0x6D151534D2F236F2ULL, 0x56E2A03E520BFD9DULL, 
            0x2815BF38E1F26092ULL, 0xADCDADCE02BADA59ULL, 0x52DB782CADA9F536ULL, 0x4304E03F326152AFULL
        },
        {
            0x3009A84596663263ULL, 0x75AF51462D7138FCULL, 0x272B819AE3BEA858ULL, 0xF4A1271F15F45043ULL, 
            0x280AC2E79DE3AEE5ULL, 0xDBDB85B1F6926439ULL, 0x1ED5A5DDE2DE3D57ULL, 0xED13E55002E09101ULL, 
            0x8FE806FFF5B24FBDULL, 0xEEBB9E5AB53D6A89ULL, 0x7A9E2677B1624885ULL, 0x855F9152903FB1A0ULL, 
            0x8E4FB23B6C18325CULL, 0x6C9A98700DA250B7ULL, 0x50753F9BCC2EF148ULL, 0x0D1339BFD322C2E7ULL, 
            0x8CFF14B7BCD53944ULL, 0x48266F1423004F5BULL, 0x8C7E3BE8875249A2ULL, 0x07D0BE4918FAE067ULL, 
            0x88680DD24916F260ULL, 0xC567617F1D2FC943ULL, 0xF9B3535123B65332ULL, 0x0D30A66A526A9D19ULL, 
            0x7D8BF6429017FCE2ULL, 0x5E24A1BFFAF27B33ULL, 0x1CC01F78F7C76227ULL, 0xF7F25AFD2FF0AF77ULL, 
            0x63D0C866881F3EBEULL, 0x8580DD7109EE177AULL, 0x08BD1F8D033DBFF3ULL, 0x624829E584A6BCA2ULL
        },
        {
            0x02F3A2C05A1655CAULL, 0xEFE7EBCEFF0014C0ULL, 0x17185A104BDB10B3ULL, 0x21BD4B690F65AD53ULL, 
            0xFA35ED832CE4E91FULL, 0xDCE727146BD470D7ULL, 0x890B38E5DA856027ULL, 0x4982947D8170655FULL, 
            0xC8440A3A6E283DFBULL, 0x82CB354B6A8454F0ULL, 0xC3ABD16336EC4518ULL, 0xD9F80E29B844B110ULL, 
            0x04917D918CD05182ULL, 0x084BEB5452B13163ULL, 0x10903D1185D3A307ULL, 0xE92EB7F1C002BC48ULL, 
            0x2F1B87862E070360ULL, 0x5CD749F7BFA85478ULL, 0x1049C5B87116C867ULL, 0x92AB0739E1020235ULL, 
            0xBDC14CDD24FB66BEULL, 0xB400E0A2B93B9A1EULL, 0x3C101B877EB4B23AULL, 0xBE245F7CC1192220ULL, 
            0x692F23B225BD1303ULL, 0xE7FB94B9E264D534ULL, 0x739386B45821055CULL, 0xED44C8E955ADDE68ULL, 
            0xBBA34A94242B5B02ULL, 0x68F96405266B653EULL, 0xCD80D929A0D17F50ULL, 0x88B5F47E46E8DC7AULL
        },
        {
            0xE6270681CACF7CDBULL, 0x1FCA243DFD48F109ULL, 0xBD83F901F569D7D4ULL, 0x4787DE50A644C7DCULL, 
            0x05593C14917D2079ULL, 0xEF9083BE0A3101BAULL, 0xA459705BBD8C1D91ULL, 0xFE6587A7AAD05118ULL, 
            0xD929B816EC7AF03BULL, 0x72B93BA5BF6EE8A7ULL, 0xB5DB7F5B35A2136DULL, 0x84E92E63AC609E1AULL, 
            0x5AACC2907338ED11ULL, 0x5BDC6746E465DF7DULL, 0x6160F1DB7D6D3857ULL, 0x2E11FAF0AEA73EDDULL, 
            0x02D4A28EB4E53BD8ULL, 0xA2EBA7D659DA1EE9ULL, 0xA97E537BC3436E69ULL, 0x07BCEE2F266E8001ULL, 
            0xF0CCF530B76787AFULL, 0xA6BBDC1819445702ULL, 0x13A42707A8B8AD11ULL, 0x3AE4EF495F079946ULL, 
            0x0E0708E2C187217EULL, 0x7885C72EDE0AC727ULL, 0x6B27623E64F184B8ULL, 0x635D0BC77131F6EBULL, 
            0x05E416E222824DBAULL, 0x3EB345F3F9506F96ULL, 0xA73624CCC6C824E9ULL, 0xDDEF49165D25E239ULL
        },
        {
            0x38012E9B790E3541ULL, 0xC5030A27CDF490E3ULL, 0x000AB2B7AE81D971ULL, 0xF09678B51E273E3EULL, 
            0x73DC2C3486C61583ULL, 0x45E8A3760209DED8ULL, 0x7AEE83802DDAB65EULL, 0x7FDFCCE2AD69796EULL, 
            0x12B7A140CFFBA1C1ULL, 0xE680BDB6B86B9093ULL, 0x118D523B1A1BC169ULL, 0x76CE1297BAFFD223ULL, 
            0x0F17AF3978852B23ULL, 0x6BBA8142853D0D96ULL, 0xA1D658F5F45D084AULL, 0x35643E7D279943F1ULL, 
            0x78C3B9E4D6D991A2ULL, 0x8E00995DE102006AULL, 0x895E0FAB955C962AULL, 0xB088FAE0B4BC2463ULL, 
            0x4509DC3BD9404803ULL, 0xF6C7AEC903CB2F19ULL, 0xC3B1EEE065131442ULL, 0x886906B783DC439DULL, 
            0x4A1C6028810401E8ULL, 0x02966C81FC2E0593ULL, 0xE1585E4DE6A64E75ULL, 0xDF3A3691474AA3DEULL, 
            0xCB786372A0A4BF1BULL, 0x60A1956E6B10FE33ULL, 0x262E967AEFC0C0B6ULL, 0x3B6E37EFD9FEC46EULL
        },
        {
            0x25FC81B5B901DA57ULL, 0x71D33CB43CD76A0BULL, 0x8B5F21534832104BULL, 0x5A28FBE145E5A5E0ULL, 
            0x8543762A7BC32756ULL, 0xA552C73283159495ULL, 0x2A05313260269E0AULL, 0x6780A28737E5ED85ULL, 
            0xCACC72D549E3592AULL, 0xBEC67AD16438CA74ULL, 0xA63EFE85FE9CC205ULL, 0xF5CB1C252E393F08ULL, 
            0x7F755B69E2766217ULL, 0xE4A71CF06F6202BAULL, 0xD018C6188D50EFF5ULL, 0x2FBE18F6AD7AE50FULL, 
            0x3D0F9D2B9EE2FD13ULL, 0x4590993EA4210B17ULL, 0x259DD1558FDAEC9AULL, 0x603F17D5FC4D418CULL, 
            0x4238BA0DA7D7DD30ULL, 0x34393A9932A0B1E9ULL, 0x1F04FCEFC13EAB9AULL, 0x6C4D6F13F81CCD38ULL, 
            0x7EC20D75353686AFULL, 0x7ED8CDBC2ED83621ULL, 0x8C24D65B1A95168AULL, 0xFE717204D19D2B89ULL, 
            0xB0A7148020996242ULL, 0x3AE2BC24D65D05D3ULL, 0xC42794D577E1C7D7ULL, 0x9A85CD4D0A32B1DDULL
        }
    },
    {
        {
            0xCC6C237FAEB23362ULL, 0x22C917A397951F68ULL, 0x7D898CC1EA19438AULL, 0xE891B72AC463D990ULL, 
            0x415B31250E41E73EULL, 0x93B106D566BE69DEULL, 0x272216A8305F877CULL, 0x205A02A4DB31424DULL, 
            0x093C6E050A41739BULL, 0x77C80AD9E3EC27B1ULL, 0x23F031D231E2025BULL, 0x25A024B38E402BA7ULL, 
            0xE5069B56541C06E6ULL, 0xB0247DD2C93ACC36ULL, 0xF68F1B018823AD66ULL, 0x98BB6B6D67DB801DULL, 
            0x556DF5E2F0705C16ULL, 0x8563F0A3BAF51C7BULL, 0xB2AA933BB5C933B7ULL, 0x897E952ADAD1A90BULL, 
            0x997617D62378F441ULL, 0xBA2A214CAED4F77BULL, 0x9DF45465668DF582ULL, 0x11007E795CAC3EC5ULL, 
            0x5CAC718758993D0CULL, 0xD1F258AF922C0012ULL, 0xED23DAFA9DEB3F91ULL, 0xE18C1F7D8DB25D24ULL, 
            0x663BB900BDC02B09ULL, 0xEA8CAC0431559C1BULL, 0x339F241D5FC378CEULL, 0x51D67CB61C73AD81ULL
        },
        {
            0x7BEB052206F4A789ULL, 0x907BE1F29FC783F0ULL, 0xA1989D336E901E38ULL, 0x2BB1FAC715134C6AULL, 
            0x8780099E9E443E4AULL, 0x141CCC37507DFFDEULL, 0x0A2A9060658F223DULL, 0x4760F34BF57AEF79ULL, 
            0x892263798900855CULL, 0x8970B7B357FCBBE5ULL, 0xD958BF53329FD295ULL, 0xE330C758829D66ECULL, 
            0x9FF1DD6159938599ULL, 0xE247EFE016091EC5ULL, 0x20A156C815F4722BULL, 0x881CDD892F86C130ULL, 
            0xB296D11D51359E8CULL, 0x3512E2C0C853892BULL, 0xC2B4D12909C620EDULL, 0x31EDA127AD75A2C2ULL, 
            0x5251CB9A94EDAFB6ULL, 0xCC732ABBA8462283ULL, 0x5216DCA16D65B258ULL, 0xE6A93B9D6D8243D5ULL, 
            0xEE49DAD2C7E34413ULL, 0xBED19E8820DA6C3FULL, 0x52A214852F5358F5ULL, 0x5BD1EF1450F0B643ULL, 
            0x04C6113FADF6AF01ULL, 0xAC994047FA568ACAULL, 0xE5362BE3B3220D16ULL, 0x946857A3AA4FAF3EULL
        },
        {
            0x3FF1342493E723C5ULL, 0xB2E5ECB0A7EA34DBULL, 0xED0B8894C63FD331ULL, 0x329C0B4027508E74ULL, 
            0x10B9A00186BE8C4FULL, 0x19FE0770E810BC9FULL, 0x8362325D31A72034ULL, 0x56C37518338F603AULL, 
            0x1EF864C09EE49C8BULL, 0x372A24E27608A8C6ULL, 0x18CF1B3835CBB4C4ULL, 0xD4B793DDEA2489E8ULL, 
            0x81CD06B2D79CE40DULL, 0x4AFD7C4369A8639EULL, 0x5F32500EECE6A97FULL, 0x1C03BD2B16F9E1ECULL, 
            0x0E4D9C68BB7225D7ULL, 0x8CAC8E66CB28904BULL, 0x75D407206464E55EULL, 0x5CEFC3DCA3FC3AC1ULL, 
            0xF9D8AF76CB6E909EULL, 0xDA644644945BC058ULL, 0x1065C76F499C8EA0ULL, 0x53C4D55DC181168FULL, 
            0xB22EAB5B65C9FAD9ULL, 0x91CA14C9B033AE68ULL, 0x394577EB9927E829ULL, 0xD7283CC8E3E8AC9CULL, 
            0xC792DF5A2B7BA482ULL, 0xE0676511F7D17F44ULL, 0x8264CD8F09B52A20ULL, 0x0BB93C417592D8DBULL
        },
        {
            0x293209FA414E2EF5ULL, 0x022E40FAF40A82E8ULL, 0xEEF583B292EF4EA3ULL, 0x619910FA001959F6ULL, 
            0xE3E2D6E7A23C363CULL, 0x12642D51F7717019ULL, 0xCCA11A8ED3E27A96ULL, 0xE849EE5C4717CA32ULL, 
            0xFDFF1C99287A7DB4ULL, 0x181940548036741FULL, 0x2B166860493593BBULL, 0x65A0549246D6A088ULL, 
            0x8A718CD08EE6C0DEULL, 0xF28B056739BA73F5ULL, 0xA2A11FEF57F89E0EULL, 0x396EC2C4D02B0DC8ULL, 
            0xD0CD5AE3A7021B6EULL, 0xF60A395C111DC6E2ULL, 0x0DB16C3E3A718491ULL, 0x1065EB793A465EBFULL, 
            0x8E474BA42ECFF16BULL, 0x094996508754A6E4ULL, 0xBF77CCB35BFE1F2EULL, 0xA456C83941F31E49ULL, 
            0x5505EDF19AF4FCD0ULL, 0x4DA4D2AAF18A51D6ULL, 0xC7B5477A2FDB1ACFULL, 0x159F49B6F1988919ULL, 
            0x968F424080765983ULL, 0xA72B92E6D94F7BE2ULL, 0x0E3820B2286D7E12ULL, 0xB35851EED4AE62F2ULL
        },
        {
            0x81FA62941D8ED0C2ULL, 0xEF9602DEA154B22DULL, 0x8B910B96C9034A23ULL, 0x4E3756410DD62875ULL, 
            0xB785DE6FB5B3D96AULL, 0x1DE947FF952E5D59ULL, 0x2734510DDAAB30C9ULL, 0xB278CA3BF15C189CULL, 
            0x6DC23E8EAF2C15F3ULL, 0x7067E2B71FB44E2CULL, 0x5354EFEE7AA8BD85ULL, 0xE7AD8AD6500431E4ULL, 
            0x0B8EDD3CA4D824E0ULL, 0x78C229A8F7FBCF61ULL, 0xC213927A765E8367ULL, 0x8746220865B70FAAULL, 
            0x45AEFBFC98A6E49FULL, 0x18FFFD7C848679ECULL, 0xBD78949C135A38A2ULL, 0x5FDA0412F229788BULL, 
            0xE5288F10E5C2A6B3ULL, 0x90341735EE9565A7ULL, 0xDBC700A2C5EC22F2ULL, 0x06AB66324E7DC364ULL, 
            0xD15FC9F17670B17DULL, 0x4459642FAAD2E3ACULL, 0x1F476F4AAE6CA2EFULL, 0x19EBF3964B30196BULL, 
            0x84DF87FAD4C861BCULL, 0xB77D2622CD5543A5ULL, 0x1B7B793B2B3746F6ULL, 0xA53FB2346F158497ULL
        },
        {
            0xC1548FB5F2E583BAULL, 0x944E8F575F69CB02ULL, 0x7FFAEE44F0D47FFCULL, 0xD1CB75987E2A3478ULL, 
            0x818172D531BC48F6ULL, 0xD5393660747AB569ULL, 0x0998A23EFAA1A5CCULL, 0x240E259FBE3F95BFULL, 
            0x229B74B50AF3AC10ULL, 0xF7BFDDA3FB705415ULL, 0x11688FFB39B195D8ULL, 0x50FBF30EE4AD865BULL, 
            0x9EC73A522E607B3BULL, 0xE72CBD697B4DF767ULL, 0x8D98AD3933211D38ULL, 0x807B121926DA881AULL, 
            0x8F8C5E005BE16173ULL, 0xD9926764281EF2FEULL, 0x50B6DE0E2296B07DULL, 0xE679D350F60C4540ULL, 
            0x2667DB3CC437D3F5ULL, 0x62FF87D810DBAD02ULL, 0xD266699FB67D75EAULL, 0xD8BCCE7D4059DAFDULL, 
            0xF7DF5FB4E5438591ULL, 0xC72BD4937BF4043AULL, 0xB0C5A98920674BA6ULL, 0x3BE8950D327881C6ULL, 
            0x347254FAB239E9DBULL, 0x639B1B3063F36F39ULL, 0x0292D7C14DDE80D5ULL, 0xC4DA412B06607CB1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseHConstants = {
    0x83759C63312D06B4ULL,
    0x0D79FED12F5A6CCAULL,
    0x7C176EB681E12321ULL,
    0x83759C63312D06B4ULL,
    0x0D79FED12F5A6CCAULL,
    0x7C176EB681E12321ULL,
    0x1ED5C397ED17282FULL,
    0x0D3068966EDF5065ULL,
    0x77,
    0x2E,
    0x6F,
    0x73,
    0xA9,
    0x29,
    0x7C,
    0xA2
};

