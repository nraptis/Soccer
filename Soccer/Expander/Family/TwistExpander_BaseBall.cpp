#include "TwistExpander_BaseBall.hpp"
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

TwistExpander_BaseBall::TwistExpander_BaseBall()
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

void TwistExpander_BaseBall::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 9307462448831111786U;
        aCarry = 14279529298427122282U;
        aWandererA = 15286657601123781493U;
        aWandererB = 15483007011307610349U;
        aWandererC = 16897423307290491533U;
        aWandererD = 17755021928122803638U;
        aWandererE = 12176715582556992161U;
        aWandererF = 15953783455689381498U;
        aWandererG = 17247186925601768727U;
        aWandererH = 13777802482623740026U;
        aWandererI = 15268270022382255532U;
        aWandererJ = 16500698807528774372U;
        aWandererK = 14930202611362317404U;
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
    TwistExpander_BaseBall_Arx aArx;
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
    TwistExpander_BaseBall_Arx aKDF_A_BArx;
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
    TwistExpander_BaseBall_Arx aKDF_A_CArx;
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
    TwistExpander_BaseBall_Arx aKDF_A_DArx;
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

void TwistExpander_BaseBall::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 14626314437189265828U;
        aCarry = 12015194703153206826U;
        aWandererA = 11974976006800851456U;
        aWandererB = 17422081702895455354U;
        aWandererC = 16823364579670119975U;
        aWandererD = 16488751401493695934U;
        aWandererE = 15891755660732312762U;
        aWandererF = 18065594182612370322U;
        aWandererG = 14001162577924344563U;
        aWandererH = 17094810123542603222U;
        aWandererI = 9289580841540366217U;
        aWandererJ = 13878472933950842041U;
        aWandererK = 13759617131619312917U;
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
    TwistExpander_BaseBall_Arx aKDF_B_AArx;
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
    TwistExpander_BaseBall_Arx aKDF_B_BArx;
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
    TwistExpander_BaseBall_Arx aKDF_B_CArx;
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

void TwistExpander_BaseBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFB4AE8B2F256561EULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xD448C2CAC0D33D9CULL;

    std::uint64_t aWandererA = 0xD9F3328A28A931B8ULL;
    std::uint64_t aWandererB = 0xF74F3AE2CD709380ULL;
    std::uint64_t aWandererC = 0xA431DF85FA1DCF6FULL;
    std::uint64_t aWandererD = 0x8769DD0D82EB776FULL;
    std::uint64_t aWandererE = 0xAC579AC74EFE5349ULL;
    std::uint64_t aWandererF = 0xB29409AD6892A624ULL;
    std::uint64_t aWandererG = 0x85D15D70A94136C4ULL;
    std::uint64_t aWandererH = 0xBE0624DB53A49316ULL;
    std::uint64_t aWandererI = 0x99B1A0831558B3E8ULL;
    std::uint64_t aWandererJ = 0xB5FCC32042FCC0AFULL;
    std::uint64_t aWandererK = 0xC2109C38E68EC731ULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA);
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD);
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    TwistExpander_BaseBall_Arx aSeed_AArx;
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
    TwistExpander_BaseBall_Arx aSeed_BArx;
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
    TwistExpander_BaseBall_Arx aSeed_CArx;
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
    TwistExpander_BaseBall_Arx aSeed_DArx;
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
    TwistExpander_BaseBall_Arx aSeed_EArx;
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
    TwistExpander_BaseBall_Arx aSeed_FArx;
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
    TwistExpander_BaseBall_Arx aSeed_GArx;
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
    TwistExpander_BaseBall_Arx aGrow_AArx;
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
    TwistExpander_BaseBall_Arx aGrow_BArx;
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

void TwistExpander_BaseBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_BaseBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 10255916417248152448U;
        aCarry = 12206265941500922161U;
        aWandererA = 11696100500119243875U;
        aWandererB = 15371735870835933853U;
        aWandererC = 10129531475999584408U;
        aWandererD = 11325881439543918616U;
        aWandererE = 9977226846378593977U;
        aWandererF = 14800963510359281194U;
        aWandererG = 10511733933483954782U;
        aWandererH = 17652032952943714100U;
        aWandererI = 15225826152175117390U;
        aWandererJ = 16862771166815665024U;
        aWandererK = 12216271908763440596U;
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
    TwistExpander_BaseBall_Arx aTwist_AArx;
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
    TwistExpander_BaseBall_Arx aTwist_BArx;
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
    TwistExpander_BaseBall_Arx aTwist_CArx;
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
    TwistExpander_BaseBall_Arx aTwist_DArx;
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
        TwistExpander_BaseBall_Arx aGrow_AArx;
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
        TwistExpander_BaseBall_Arx aGrow_BArx;
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

void TwistExpander_BaseBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 2, 0 with offsets 7196U, 5960U, 4914U, 5792U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7196U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5960U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4914U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5792U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 1, 3 with offsets 5920U, 7787U, 3614U, 2611U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5920U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7787U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3614U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2611U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 0, 2 with offsets 3119U, 7914U, 6764U, 6814U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3119U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7914U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6764U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6814U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 3, 1 with offsets 1084U, 7536U, 540U, 536U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1084U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7536U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 540U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 536U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 2, 1 with offsets 2009U, 569U, 268U, 1635U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2009U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 569U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 268U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1635U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 1, 3, 2 with offsets 459U, 1449U, 207U, 1117U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 459U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1449U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 207U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1117U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 0, 1, 3 with offsets 255U, 984U, 2031U, 778U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 255U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 984U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2031U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 778U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 3, 2, 1 with offsets 1176U, 2041U, 731U, 18U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1176U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2041U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 731U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 18U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1548U, 1757U, 399U, 2046U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1548U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1757U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 399U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2046U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_BaseBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 2 with offsets 6210U, 1423U, 101U, 8092U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6210U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1423U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 101U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8092U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 0 with offsets 630U, 1145U, 1926U, 6736U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 630U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1145U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1926U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6736U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 1 with offsets 6591U, 977U, 5404U, 5725U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6591U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 977U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5404U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5725U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 3 with offsets 4342U, 4853U, 2260U, 1129U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4342U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4853U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2260U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1129U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 1990U, 135U, 6142U, 1932U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1990U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 135U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6142U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1932U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1092U, 1343U, 335U, 1343U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1092U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1343U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 335U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1343U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1007U, 1824U, 1915U, 1440U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1007U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1824U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1440U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1996U, 1614U, 412U, 2022U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1996U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1614U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 412U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 2022U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1125U, 1243U, 1012U, 1471U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1125U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1243U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1012U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1471U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 1, 3 [0..<W_KEY]
        // offsets: 1612U, 410U, 1008U, 686U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1612U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 410U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1008U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 686U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseASalts = {
    {
        {
            0x11E76F401B51CBD5ULL, 0xD9F0EDE07502264CULL, 0xCC25260C6C3BFCCBULL, 0xD8711C088724B309ULL, 
            0x009896C83D25A516ULL, 0x53ED560D2D27C620ULL, 0x3FD2FB3F163375DDULL, 0xDEE9A56421E6829EULL, 
            0x41BA734A7B5958A9ULL, 0x981F6CA44213FADDULL, 0x62DC7ACE11091FAEULL, 0x56ADF46883F4F5C2ULL, 
            0x5E6534667CBAC873ULL, 0xD9414DD2D031D99AULL, 0x015F9E6CBC528A56ULL, 0xCB20CD1DBA9A2B1FULL, 
            0x503A2BBB28ED3ECDULL, 0x1FDD0EFCF8B3DE23ULL, 0x74FCAE0C77F8EF3FULL, 0x774DF508A948620AULL, 
            0xBD1294744B7C2CD8ULL, 0xECE971F6934D4B3AULL, 0x51FB8F4E3B8B0256ULL, 0xF950BDBBE616FC06ULL, 
            0xECB1251E4D82BD86ULL, 0xD89084261115443DULL, 0x030CDEE85E768E82ULL, 0x1FD6E61A1AEE7CCCULL, 
            0xE973F4ED81CC6A8FULL, 0x1AB2FA79FE07A864ULL, 0x52639892F9A61E8DULL, 0x1B7960A312C55399ULL
        },
        {
            0x52FE8B16C55270AAULL, 0xA72A5BA0044B996BULL, 0x85DEDBF5174B2CFDULL, 0x85623CB57CFDD2D1ULL, 
            0xE64672AF88F41571ULL, 0x709244BC9AD87E38ULL, 0x629DB8F079FECFFAULL, 0x7BEB3DE83519F5CAULL, 
            0x594A128A66CA2835ULL, 0x2EDD906F4E48A027ULL, 0xE24518BE7A3B4E8CULL, 0xACBFCCAF56A7D3B0ULL, 
            0xB44949E788BB8632ULL, 0x72EF50B32C86BDADULL, 0xDAD6A77F58754BECULL, 0x6B3DEF25A03651F4ULL, 
            0x5F4B88E4E0A2675FULL, 0xFA1D315871F7C995ULL, 0x77BC51FD1968F774ULL, 0x2B49530E0361A68AULL, 
            0xA171F0B149DCA341ULL, 0x015929A70E305F22ULL, 0xC32EDC3D2F9B84D0ULL, 0xE52BBC034D6E6A9FULL, 
            0xC55EA6B7F4235C71ULL, 0xA374F33CA499F96AULL, 0xE7B2EC2B45F805ABULL, 0xE8A44B3C91E88C2DULL, 
            0x48010BB23073E114ULL, 0x60112BC220B2B8E0ULL, 0xFFFD0F41E9DCE003ULL, 0x592FDE9CF4B3DEB7ULL
        },
        {
            0x12F66BC710147984ULL, 0xCB1749DB7BF6FEADULL, 0x272BBA26F131B142ULL, 0x983CF80E5353EFE8ULL, 
            0xF6B9EA190B7AC103ULL, 0xFE328A21D405F06DULL, 0xE07A06A2869F9C14ULL, 0xFE62A31FFBB19B57ULL, 
            0x040BAF22C8F81DCDULL, 0xFD2786F63ADF9362ULL, 0x9A81963A8CB9E642ULL, 0x8C138F1D9C22FB45ULL, 
            0x01186425470DED08ULL, 0x8477F51BB4A11259ULL, 0xDBEFA3C67FC07A46ULL, 0xA99AC52487EEC255ULL, 
            0x45378947063E4390ULL, 0x56B54B88E17BFCA1ULL, 0xC523372C05CA196FULL, 0x6596DBCF614BD06BULL, 
            0x37D51C2822BFB05AULL, 0x7782F6EC8E5B15DEULL, 0xDF2B048BBC77C92AULL, 0xFA003F55EE9A73DCULL, 
            0xBC39D8CCAFB934DFULL, 0x345D2E8B6CA1398DULL, 0xD19CBC8F6F268E6AULL, 0xA599A14F2FC6C089ULL, 
            0x84D4389268512A71ULL, 0xC30A323B5C3C76C1ULL, 0xE901B081B14D9F7AULL, 0xF761575870D0E3F0ULL
        },
        {
            0xE9EFA92588F77419ULL, 0x1F1B958AFA4448C0ULL, 0xE4966BDB1FB61E6AULL, 0x8A5F97718787F27AULL, 
            0x1842B952705374DAULL, 0xC2FC1C1980AF0D4BULL, 0x4135FE9819D2AE66ULL, 0x640CAA0CA739C79AULL, 
            0x9EC2DD11D540DACEULL, 0x206BD0AB57536C81ULL, 0xD965DF2A543C0116ULL, 0xEA9C9D0986F69032ULL, 
            0x71A276CDA0784D14ULL, 0x9052B57AB9F3DDFCULL, 0x597C762BD8255F1DULL, 0x321E9BD5D432F1C4ULL, 
            0x8787C682A9AF63DBULL, 0xEE6F3C6451516D0AULL, 0xB2FD632796E4BD1AULL, 0x124E5725929DB690ULL, 
            0x16A13310DED3888EULL, 0xC91F6FD10BF2A362ULL, 0x95A9A69B963E3155ULL, 0x599709FE01138113ULL, 
            0x3E2DB3A6529DDD5CULL, 0xD2951A02B0A54035ULL, 0x4E7D21B8F08F97A8ULL, 0x7390A36D1062BD2BULL, 
            0x478F06700A18EAB1ULL, 0x02848128CFCB1098ULL, 0xAE23D75EBF40B7BEULL, 0xA5C639B66831F1EFULL
        },
        {
            0xBCBA2AE749633819ULL, 0xF7F1A141F7B3490AULL, 0x04CF5E918C1A31E4ULL, 0x0DF97338199B6CC3ULL, 
            0x8DB80133C6A99669ULL, 0xD0B9B9536BDC9DD7ULL, 0xB555CE24D003F507ULL, 0xAE54BFA5DD965011ULL, 
            0x7DAB534B04A139D6ULL, 0xC853998426D859E9ULL, 0x34766162F50ADD13ULL, 0xE3D3FCA566CD18EDULL, 
            0xF6BC67814F430DA8ULL, 0x2C9BC79C146D5ABEULL, 0x933C20B057F93006ULL, 0xF1B5D4C164C4C7B2ULL, 
            0x426EC076A533DBAFULL, 0xA0ECAE833725AA07ULL, 0x9FF50DFE751BD4D5ULL, 0x1C60A6C5DA71D8F7ULL, 
            0x2237AA613D6818EBULL, 0x702C1F076496A4EAULL, 0x4496E5F6E5556961ULL, 0x73A55957C52131B7ULL, 
            0xD5C05172C74E4F6CULL, 0xC1B550844F77DA2AULL, 0x93EA029288CCC599ULL, 0xF6312CA6A979C38DULL, 
            0x725B266E8176D6B5ULL, 0x71E13C5C7AE7888BULL, 0x11B2DB6CB182E4C1ULL, 0xD91E573679B298A1ULL
        },
        {
            0x75F4A7C309A925D1ULL, 0xD522DEEBB336CBCCULL, 0x58A129E2C6FBB0A5ULL, 0xC173E4D3D18A406BULL, 
            0x23EBA876DCA26B74ULL, 0xA1E8727D86D0AA30ULL, 0x1DAFA5F0F37C9F2FULL, 0x9B5E5698550497BCULL, 
            0x044B374E963C95EBULL, 0xFB926A9AC14A172EULL, 0x3C82C1F649F979D9ULL, 0x79393E328AF1712BULL, 
            0xA64326457E11AF0AULL, 0x43226873217AC5D1ULL, 0xE3B3306925D528D1ULL, 0xADE7A9797ECB8613ULL, 
            0x4E01C24FC9583F6EULL, 0x429A8E82121516EAULL, 0x246B40E3AB72CE71ULL, 0x27D321CEDE05CAA3ULL, 
            0x39D4524A616466C8ULL, 0x03630EA2C49B4284ULL, 0xE8C9C6FFB74C1D1BULL, 0xE32C7C846E803A66ULL, 
            0x84E90EF714E30C35ULL, 0x664037F89FA592A5ULL, 0x7BEE545EA3F97843ULL, 0xF0A834F46318D6E2ULL, 
            0xEFFBF389DE42C64BULL, 0xDD2643C38F297244ULL, 0x60392134E7784ECDULL, 0x804D25681830697AULL
        }
    },
    {
        {
            0xBB9552111C0BFEBDULL, 0xE01D861C6B049B8BULL, 0xC5C75ED8C0401CD6ULL, 0x2F0EAD2FC57F98F8ULL, 
            0xD2F301F1402F7FA9ULL, 0x930C723B27326384ULL, 0x15C89A963B147BCAULL, 0x1F2638C9C78E1A58ULL, 
            0x050C110F12DE9DD4ULL, 0xF6019B8578A061A5ULL, 0x72714AC7D5349BC5ULL, 0x356FDE699C2184D1ULL, 
            0x0926267F205B68F0ULL, 0xE996C94BAD297E31ULL, 0x61E44F99AAB96CA1ULL, 0x31557DCD44BFDA09ULL, 
            0x6FAEC6D4B805E53DULL, 0x58F29326AC552954ULL, 0x42913B0748E6BC7BULL, 0x88BCBFB8C13D92A5ULL, 
            0x087FAE2AB7E0651BULL, 0x47A29FDAC0DE38E6ULL, 0xD3A817EC32A5B352ULL, 0xD0112B1185AE8367ULL, 
            0x3A1BD74B160E5748ULL, 0x85E95037DD6732AEULL, 0x8D23AB4A9AEB17D7ULL, 0x428B8CB32339ECFBULL, 
            0x5E63BB6487947A0AULL, 0xF71949DFB30A1A65ULL, 0x0573EC57C6F14ADCULL, 0x4F612DC8A464A488ULL
        },
        {
            0x4338D5AB60BD1677ULL, 0x6BEC5F5D5B23E77BULL, 0x87599F114A9DF4ABULL, 0x7DE2C920A399E7D2ULL, 
            0x23829A226C0DD1C0ULL, 0xFE15BD7C0C9FB372ULL, 0xAF09DCAA567EF59FULL, 0xCE4BB30CCBCE2748ULL, 
            0xEC412F89AF3603C4ULL, 0x7BC09B20FF58C316ULL, 0x9FF51172D63E5236ULL, 0x0101640FD09FC000ULL, 
            0x18779F4F0D5CFC0DULL, 0x6C6B481E4C0727CAULL, 0x52F952DA4BE585A9ULL, 0x256929998F901D91ULL, 
            0x23870B9EBFE14C50ULL, 0x176C29AFFE8F7CC3ULL, 0x667E1E21932397C5ULL, 0xB94B73B71C4F0329ULL, 
            0x476A9182A85591E2ULL, 0x77FA3C06B69B92E4ULL, 0x26F3D61A51EC884FULL, 0x3603802CC323B107ULL, 
            0x0DC3D84D8962AB0FULL, 0xBBA9FD2604B61D55ULL, 0xB08A167932216DD0ULL, 0x0B26E5288A2B0F5AULL, 
            0xD57EBC2C394C68FFULL, 0xF9AD12E3C7A3B7D1ULL, 0x0F4CD4F7679FD69FULL, 0x4CAFFA399907BDFCULL
        },
        {
            0x56F9D4114EA0E2C7ULL, 0x119F368479DFD43DULL, 0x9A6BFDB947F90A0BULL, 0x7BF1D19B23352158ULL, 
            0x5E0C2530C478CDCDULL, 0xC359CC85D6CF5C35ULL, 0xC4668A86FB8974F0ULL, 0xD26A277485B95581ULL, 
            0x00D8EA16E969ADB1ULL, 0x3AB9F14BC98FB12AULL, 0xEFCC07088EF33B05ULL, 0x3773EE0AD9FF5B07ULL, 
            0x436C09FC2B37AEEDULL, 0x35B9E4965C3E05C5ULL, 0x30A23EA09189B471ULL, 0x9371B732BB2703CDULL, 
            0x45F14147DFB90F44ULL, 0x21237B8F0CCB07A5ULL, 0xDC93CBBB16F500D8ULL, 0x3399EDC08E136640ULL, 
            0x756491B1FEF4ACA2ULL, 0xFC339FEEFC21420CULL, 0x7BD32699254DBF5BULL, 0xF165A835DC93777AULL, 
            0x7AE208BC90778B71ULL, 0x110FD6FB010805B0ULL, 0x30CC793346EAC730ULL, 0x3EF8D850819FFE97ULL, 
            0xBAD47C7CE11EDF9DULL, 0xA338BFD660F55ADFULL, 0xFA3E085CD13DD037ULL, 0xC08711AD21B9B480ULL
        },
        {
            0xA0C946A6781D0172ULL, 0x131462C7B6123A44ULL, 0xAC7962A27B861EE6ULL, 0x5A56E5E00724810CULL, 
            0x75F512B9804B8C57ULL, 0x1DE332C47F4C1CCCULL, 0x319720B82A0FFAB4ULL, 0x0462267F778D4769ULL, 
            0x563E27BE6DB38C95ULL, 0xA623DBC48F2BCFB0ULL, 0x82DCFDA90E89250AULL, 0x1F14E9B9075CB6DEULL, 
            0x14A4D4AF11500EF0ULL, 0xA324F5663EE102D6ULL, 0xD67F205826FADDBCULL, 0xBB7C6B4B8974FB0CULL, 
            0x22AA082F7F64F75BULL, 0x8A97D900C9D324FDULL, 0x0169B496E3CE59B2ULL, 0xF61B10385E30A5E3ULL, 
            0x644C0677DEEA0174ULL, 0xC0C2FB4438A20131ULL, 0xA6552C25C4B879FBULL, 0x01C6E030CDA977F9ULL, 
            0x7A4AFF0159B65E35ULL, 0xB2F48535227A63A8ULL, 0x9376164C7F30B4CFULL, 0x7BD3512F26FFADCAULL, 
            0xBD5C1AE3A89FC3C5ULL, 0xD4F30AAA1247C3CAULL, 0x2109061A2BDAB48DULL, 0xF331E08906E15C0CULL
        },
        {
            0xA1C36DD525A235A2ULL, 0xC370AD2E754C82CEULL, 0xEEDE7EF88190B639ULL, 0xBA9035241FEAE528ULL, 
            0x6559634FD303DCE6ULL, 0xF2A11EC55FA6A27AULL, 0x28B1CBBB460AD7D5ULL, 0x0C12505166705427ULL, 
            0xAF84655B2DB43CE9ULL, 0xF8F1963C80DE5610ULL, 0xE84E38A000F26CB9ULL, 0x787B7CB3277DB980ULL, 
            0xBE73F8B5DFBFDE16ULL, 0x503806F77E8D78B1ULL, 0xAE3FFABF950CD74BULL, 0x799ADE0ED37A4B8BULL, 
            0xA93B1F4DA486D58BULL, 0xF2FB684BDE7A30B6ULL, 0xB02A7EABC327FE7CULL, 0xA899D329F30457E1ULL, 
            0xFB6CA0C49B0D2BC3ULL, 0x65AB04946A368E95ULL, 0x80D919AA36E0F1D4ULL, 0x418BBCE8C128B3CCULL, 
            0x91B16C7480C66ABCULL, 0x6548DBCEA564C40EULL, 0x0E93BA2A48C3AA35ULL, 0x3B57B90D2EFD2CD3ULL, 
            0x65116CFD4BF19F4DULL, 0x141B471D90B7F83EULL, 0xB4CBA5E814005FB2ULL, 0x20BFC5D59FE2188DULL
        },
        {
            0x201DFF75485E1B38ULL, 0x2390FF9D06BAF3AAULL, 0xE1967ED4D51C0BE7ULL, 0xD47B70264EEB3AF1ULL, 
            0xB0D73F4E7AA7D622ULL, 0xA815C52BB7609A94ULL, 0x3E547D60D775D004ULL, 0x5430D8D5AFA63218ULL, 
            0x67666EB86A7BF02FULL, 0x846A60CD2B401D6FULL, 0xAE8AA8D0A7DD8EF5ULL, 0x1B8DB7872894E64AULL, 
            0x0D299E9CC4AE643CULL, 0x31BC926FD4849397ULL, 0x095302762CAA058EULL, 0x09E981358CE58946ULL, 
            0xD71A36C1EAECA0F6ULL, 0x72F02A574541D6D4ULL, 0x916EE632E55AA9F2ULL, 0x1F5D8B4A5A7EE864ULL, 
            0x22374981AE68EE96ULL, 0xCB2B5C6FBA1723D6ULL, 0xCF62B5DB9590169EULL, 0x4A8020EB42D8837EULL, 
            0xB27FE4D4E4ECF924ULL, 0x22CFE92EBD054641ULL, 0x9590D6E938973485ULL, 0x919495320665A790ULL, 
            0x7DC03F97C5AB1DA1ULL, 0x04860337D76B9344ULL, 0x07B74CE404EA07D4ULL, 0xD3B8ABD91E8E319FULL
        }
    },
    {
        {
            0xD9D2E44E6BA4F7AFULL, 0xDFEEB63BD189CCA4ULL, 0x010AA17AD26660A3ULL, 0xFC7A36A968BFDB76ULL, 
            0x607797E909A2B490ULL, 0x18E20F00E3A22C53ULL, 0xC6873BE073E191B7ULL, 0xB0212F1888E59B06ULL, 
            0xF1330120B7389884ULL, 0xD693114F349FC02BULL, 0xBDDDF57EA1DA2982ULL, 0xBE49CC1FF364FFB4ULL, 
            0x18142B09FB6FF013ULL, 0x2EB21B47602C964BULL, 0x73F56A6E5EAE3701ULL, 0x40846B95DC29CBCFULL, 
            0x8C01840FFDB134ACULL, 0xF9AC7F02DEEF328CULL, 0xE4E03B74F813D840ULL, 0xE589F6D8091ACD3CULL, 
            0x0DBA465A2C03A04DULL, 0xFF6815F433B3A71CULL, 0xC4D271A374D499AEULL, 0x9CBB55F8A56E5214ULL, 
            0x2C078A245DB5D7EBULL, 0xF22ED52CA9E183C8ULL, 0x3D3FA44A56A9D5B2ULL, 0x9E09144A22614C79ULL, 
            0xAA0DD0C41899F17CULL, 0x438FD87333F6135BULL, 0xDE7FFFBFC7E082E3ULL, 0x4FAF0AE8F46459ADULL
        },
        {
            0x6A3A966ACE5BD4F9ULL, 0xF5753FF657EF49D7ULL, 0x44C44CE8CBB733D9ULL, 0x43FBA70E0E247184ULL, 
            0x41A54DFA0D6EAE3FULL, 0x6B71D00F6B4910DCULL, 0x27DE537CAE77075BULL, 0x29E5C0B8187C41F4ULL, 
            0x5A64EF44B8BA2DF1ULL, 0x3A8EBF104608DD08ULL, 0x42BF4FF7A03FD256ULL, 0x28DF549341A4DDAAULL, 
            0xBE74995022A5880CULL, 0x74DFC7CD14C29F64ULL, 0xB83E2E926B36151EULL, 0x26E089E6F312F4BCULL, 
            0x7E16075763DA7A42ULL, 0x70B6EC56C52EF373ULL, 0x9948745A44F937C8ULL, 0x06734DC0ED7E6549ULL, 
            0x860B646462135BB8ULL, 0x5B319C0580D2240FULL, 0x403FBD9F7154D3A5ULL, 0xD0448E3C62145EB8ULL, 
            0x67BC13BD44F49850ULL, 0x839DFF85AB77FFB9ULL, 0xAA6A2A293D84E97CULL, 0x4F1BDB87013FDA70ULL, 
            0xB8ED7B7C0012839CULL, 0x8C8A95C1D3C4E8E8ULL, 0x11C3CC8E29789390ULL, 0x93FCD769801CD7CCULL
        },
        {
            0x45A335D3748E11DBULL, 0xDC129F570C2780DBULL, 0xBC3097505D6A0E62ULL, 0xD66BCDDC8DCC941EULL, 
            0x8D96B12C01C592F8ULL, 0xA06F274293798824ULL, 0x7AEA6E0DDCD0BA4FULL, 0x39FCA5B5ABC4C084ULL, 
            0x796FB71913079CA4ULL, 0xBD8A011D777E1A40ULL, 0xBE7C551EB4480C60ULL, 0x40B80898F11BCFBCULL, 
            0xA6C731C4E31ADFC8ULL, 0x6137308EA7596D58ULL, 0xC0281D6E3C8D5F69ULL, 0xD0383E1B649A7423ULL, 
            0xA1041FF5F9C9C162ULL, 0xADBB59A3A27FFB93ULL, 0x4AF9B3060300B70FULL, 0x17D294771AF25865ULL, 
            0x12E9733E6E66B67AULL, 0x0B78863A3F79CD5CULL, 0x4897FB811AE1C6CCULL, 0xFE54EC65F20FA2D1ULL, 
            0x5447A5CB51CDF268ULL, 0x4E5FE7A9783A4B79ULL, 0x0795EE02DF996E99ULL, 0xB79446D58A54CBA3ULL, 
            0xED986C9C30C3C52BULL, 0x592B8827F3117B64ULL, 0x661097E4887CD439ULL, 0x183BE61A7E67B207ULL
        },
        {
            0x6092D50CDD03F4BBULL, 0x1CF04E354D04A3F3ULL, 0x8942ECE11DC6EB9FULL, 0xF89F27851729B11BULL, 
            0x9AD0883B57BF0BC8ULL, 0x78CADC9D3BBD3A3AULL, 0xE6632363DF104214ULL, 0xB7DF743007ECF770ULL, 
            0x74098E61D3FF8C6CULL, 0x5FDFFA9EF96F1B88ULL, 0x58EEECC2FD20D895ULL, 0x74B9D849C50A7D50ULL, 
            0x2DE06CF465E86C89ULL, 0x13CFEE0C7A776FDAULL, 0x05695C117D4B5B4EULL, 0xE19B058C40CC0A40ULL, 
            0xC3BC0EA045D82703ULL, 0xA257ED4DC1FBC5DFULL, 0x9DE0A46F01981EBBULL, 0xF21C373FCD8A7877ULL, 
            0xB5925076FAE432BDULL, 0xA910725F7295ECADULL, 0x7BAA78DE8FB7C423ULL, 0x3B40B3BE329AA5F2ULL, 
            0xD868A49CEC4EBA0DULL, 0x5C374F9FB6AE1E00ULL, 0x5A6FAABD750D687BULL, 0x9D9AA9FE8F3EEA23ULL, 
            0xA164CE446FE7FDCAULL, 0x06C89F756EEBE245ULL, 0xD4C313A0F4E44264ULL, 0x93EF4404E7A663D5ULL
        },
        {
            0xB754834197531C79ULL, 0x2384AE1E43684946ULL, 0x39DF988EADA17920ULL, 0x88C3EE1988FDB4C3ULL, 
            0xC817B1D5FFDE5796ULL, 0xC18F0F5AFB96E262ULL, 0x1887E9339DFB2945ULL, 0x90D6DF2E9768936CULL, 
            0xF9351337916F944EULL, 0x67483D61798825FEULL, 0x38423F84BEC7DA0BULL, 0x344BD4C18CFC7A6EULL, 
            0x07207C65B2C9DA48ULL, 0x13B4ABDC5DFF98A8ULL, 0xD1D35DDC0DAAE9F2ULL, 0xD0EA29BB2290614CULL, 
            0xC0DD067A2167590CULL, 0xCD70EA6B6832345DULL, 0xC26C6EEF2AAF966AULL, 0x262460E78ADE1784ULL, 
            0x2003FE177C344F92ULL, 0xEE27108F708EE61AULL, 0x5920428600B7226AULL, 0xC4DA831F645B7174ULL, 
            0x21AE7FAE9C7E4EF8ULL, 0x39FC4A82AA47C7ACULL, 0x0967F8ED1CD3145BULL, 0x11D0ACA38DB9DFF9ULL, 
            0xA85A0741317CB1D4ULL, 0x637C78F31CFFD93CULL, 0xC2BF2D110753F210ULL, 0x574D41F6DA48B37CULL
        },
        {
            0xEC15E46FEF87F5ABULL, 0x5B2E88F614FBAD3FULL, 0x191109AA5915E891ULL, 0xA6C562619AE22C5DULL, 
            0xFB255ECEF743AE5CULL, 0x18801B44FC55ACE3ULL, 0x2B3FD38AE7172E11ULL, 0xC15E334E774235B5ULL, 
            0xD4DFD9928157A9D7ULL, 0xE3BD9DBEA5F5C1C7ULL, 0x864BACF04870D99CULL, 0x2B80EB8AECB53AAAULL, 
            0x86AC74D36C826FAEULL, 0xEF9B9D5B3290B025ULL, 0x811BDC03E012DBE8ULL, 0x13F25784D6FC6388ULL, 
            0xF25ABB72448E714AULL, 0x13F709E94AE3EF2CULL, 0x8B7EC593CFB41991ULL, 0xCE8147765F6F9EDAULL, 
            0x63CF7A97CA6B1787ULL, 0xE9369A7EC5CF11EEULL, 0x861E67BBC278B05FULL, 0x68F8448F28919EBAULL, 
            0x7E22A9F9F72D4093ULL, 0x8961F02A3B1E20D9ULL, 0x85D5B203D7B83D20ULL, 0x3FEC82471ED947C4ULL, 
            0xEAD4E0820C7C6A33ULL, 0x7902DE4801D72FB8ULL, 0x1DC245D3D69E833BULL, 0x3D322C838D374378ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseAConstants = {
    0x776FF603819D682AULL,
    0x1968B0B8DF9F3E03ULL,
    0x95AC8B570EEA5285ULL,
    0x776FF603819D682AULL,
    0x1968B0B8DF9F3E03ULL,
    0x95AC8B570EEA5285ULL,
    0x3B20DBE0F5C6D5FEULL,
    0x458C9C2C5CD257C3ULL,
    0x29,
    0xB6,
    0xE4,
    0x3D,
    0xA1,
    0x30,
    0x25,
    0x44
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseBSalts = {
    {
        {
            0xD706D790B6450C86ULL, 0x598FE3F4A3E1D3D7ULL, 0x1FA8AE88A586C70BULL, 0x35864B7157DACF0AULL, 
            0x2F7403E3084DE265ULL, 0x01E1DA640FDD87D5ULL, 0x30FB064D3685B903ULL, 0x54D7CD7C5D8B3D59ULL, 
            0x3EE8627930B7F68FULL, 0xDD5A70442FF41A97ULL, 0x36D9C958DF0BFB0BULL, 0x41B89511EFFE7B35ULL, 
            0x46C2A9595FFDA828ULL, 0x2C0D8320FA7D0BE6ULL, 0xD8B13030351FB0FAULL, 0x6C1E3FFD2B30B31FULL, 
            0x59E00E856F770443ULL, 0x4340668DFB260018ULL, 0x37F4D6712DBA775CULL, 0xF609BF1B1F377F06ULL, 
            0x2433BC61D51A1E91ULL, 0xA552E11AE959097FULL, 0x0ED7F1A0D6867EC5ULL, 0x50A9FD870C9EC202ULL, 
            0x580EF9B8EBBA3955ULL, 0xCE7D802C662610C3ULL, 0xD223609F54883258ULL, 0xDE00F60F8036D2E7ULL, 
            0xA8502047CE44E839ULL, 0x1FF084C8382C4013ULL, 0xC5322FAD43AE1C60ULL, 0xEB9FCD5A278FFE47ULL
        },
        {
            0x047DE4282223501DULL, 0xA66F8E4AAA16C7F9ULL, 0x5B0A441E9879695DULL, 0x9907D113BB64BC1FULL, 
            0x9518F650ABC3D01FULL, 0x902FE7DBEAB1E049ULL, 0x745FDDD395DEF6FFULL, 0x7ABD2000B1FF2A6AULL, 
            0x51043DEE55ED0E5DULL, 0xE946C8A5C75E0B6DULL, 0x203933B2D66EBFDFULL, 0x31F527D26E70E930ULL, 
            0xD66CC70B452DF27FULL, 0x8E87AE5842A4B429ULL, 0xA7A8B64F49C268A9ULL, 0x17AD787882EBED10ULL, 
            0x38AA380ED439914DULL, 0x5E10309C45437DB0ULL, 0x17A7C559B470733BULL, 0xAC44C477660EA805ULL, 
            0x3D45DAEC9498035FULL, 0xC8E8230C3F5E9174ULL, 0x2D032E83E365E600ULL, 0xE488A336CE201F6FULL, 
            0x5116CF45EA1583F8ULL, 0x48E6C521935F8143ULL, 0x835688701A14EBABULL, 0xD8A68C4C671E6FDFULL, 
            0x62A326377CDE8B60ULL, 0x613974278E18D0DCULL, 0x75F49CBD94795885ULL, 0xB7BAB07D173FA7FBULL
        },
        {
            0x1BB6786AB3646BACULL, 0xD8F217FB72E161D5ULL, 0x1F10719AC26264D9ULL, 0xE530FED65DCFD3D9ULL, 
            0x9827B6FA10AEB2CEULL, 0xBD97319C9F0FD734ULL, 0x46669AC25791EBA2ULL, 0x808FD1F7B18786D3ULL, 
            0x29672FAC60751A0DULL, 0x3F8057953275363FULL, 0x4385B9711BB60E4FULL, 0x163022C1DB2741E4ULL, 
            0xE6EB35DCA54504FBULL, 0x56A89AE4BAD7A3D6ULL, 0x29C002931BAF5F0FULL, 0x27E57A63ECDAA845ULL, 
            0xC01F091169C9D4A9ULL, 0x4576F837D4DD4FC9ULL, 0x04D80658C8D56E25ULL, 0xEA38AFAA8B1CA7CAULL, 
            0x93F58FCA2A11E44BULL, 0xA60067EE0E4534EAULL, 0xE16B65264178F81AULL, 0x8510F663BD15C43DULL, 
            0x6213895A591E0F44ULL, 0x85DE7D433B6E6D07ULL, 0x2F21DF8691C68AD3ULL, 0x7932790E732110FDULL, 
            0x31F577E12F09656BULL, 0xC07A373B342B92DEULL, 0x10478F9D47FF3AE9ULL, 0x0F49786FA064F4B0ULL
        },
        {
            0x4AF263D5BC37FD5CULL, 0x0220AEF0F0FFD7B7ULL, 0x468069227D1D263BULL, 0x5D2C8806B647895CULL, 
            0x4C70CCBD53418BEDULL, 0x18C685A3993AE57AULL, 0xB97BA09325E1E29DULL, 0xB0BAA1376A58F481ULL, 
            0x8BFF0E8BBFEC8587ULL, 0x603B77AA20B48B75ULL, 0xD10C4982EBC407DAULL, 0xE57A48EBD21DE43CULL, 
            0x888358E1AB4367ACULL, 0xC9FC637AFF2DBAE6ULL, 0xF7109D37D9BEC39DULL, 0x376C2721F27D2455ULL, 
            0xECAF43E071EBD57AULL, 0xE755BB6D9956CA0FULL, 0x1D896D27EE276F51ULL, 0x2C26C9727790581AULL, 
            0xCA01B4F9694173E3ULL, 0x3F13717D7CE19AB1ULL, 0x547C7BB2FC905842ULL, 0x3C2EE1E97B6437A5ULL, 
            0x111CC1D1FB05327EULL, 0xAA1CE444CA022C35ULL, 0x928758796DA1C313ULL, 0x4DE2A069A85C4C5AULL, 
            0x926954A0671CA0E3ULL, 0xBA2BC84966842AD8ULL, 0xCAF177D73E1CA9C2ULL, 0x8D8526467CC7E2EBULL
        },
        {
            0x96F87CD4BD24E386ULL, 0x63B5B0AE3B389A89ULL, 0x51FF007ADB5549C2ULL, 0xA86AE1D558166747ULL, 
            0x8E919B76A9A9473CULL, 0x73D0DE07D8150F18ULL, 0x7B289DDEF31632B6ULL, 0x4B6EE588DD2A5D86ULL, 
            0xF357F5818F8E8C37ULL, 0x9F407E702CF4F307ULL, 0xF7A186D86CEFF5FBULL, 0x86CE2A561A616951ULL, 
            0xB4D54BC91B7EDD20ULL, 0x9FDCFA0A12B822D9ULL, 0xD40845E6C914E773ULL, 0x530B494E3A97F79EULL, 
            0xF94991D1F78DE3AFULL, 0x625261A519BFA0D4ULL, 0x77FD6C0ACBE9F360ULL, 0x4101E2E299FB5A37ULL, 
            0x9EC3DD18C2348E78ULL, 0xFA99A5482C999586ULL, 0x85E85A421AD0ED0DULL, 0xFA6664E68FEC466AULL, 
            0x00907B8803631865ULL, 0xE486E17ACD8D529DULL, 0x0281297559C0524FULL, 0x250A2507D567E917ULL, 
            0x9C49E0B126F10ECAULL, 0x2634BECF53F78193ULL, 0x2DF9D3B90BA11F91ULL, 0xA08DB90606983891ULL
        },
        {
            0xF306B80362FE875AULL, 0xF156B60EBCF19DC2ULL, 0xCB3CB98A37EBDA4FULL, 0x296C895CCFFF6423ULL, 
            0x73A71338225E24E0ULL, 0xF7D5667166F5C03FULL, 0x7064575EBE059B38ULL, 0x78534235142793AFULL, 
            0xD5D9CA6575691033ULL, 0x27AAD78374C6D4BCULL, 0x944ED1566A3D8594ULL, 0xF5693B0807283085ULL, 
            0xA63582D956CEC7B8ULL, 0xC3B485147E01C2D1ULL, 0x35F7475D1C8256D2ULL, 0x678ED0C90973F1B1ULL, 
            0xBF7DBCD48617A2C2ULL, 0x51ABFE16595D73BCULL, 0xEA50FBBEE1E8277FULL, 0x89BE1E634557F440ULL, 
            0x5F1DCAA6FA3211CBULL, 0x23AB58CD4E1B7D17ULL, 0x859F2097B70C069FULL, 0x12635285E125E394ULL, 
            0xAB5BF33F185BEE2AULL, 0x2B7854A26BBDF7D6ULL, 0x805C9F216AD80883ULL, 0xF6609940E77A9328ULL, 
            0x58D0A916A36D72A1ULL, 0xAC6B9F9AB4E77D3AULL, 0xB3EE9C54329C730CULL, 0x5D1FA80B8181F95AULL
        }
    },
    {
        {
            0x7BDA6BCA861516E2ULL, 0x66A9C0D8278679D0ULL, 0xE76DA8C5BCA34466ULL, 0x3A2433FA4FCEEB85ULL, 
            0x0619DDFF5067D625ULL, 0xDBF15E5AB8619DB3ULL, 0xF0E638BE4070250DULL, 0x3EE4B39DEF2B07EAULL, 
            0x71BF8A217ED7D787ULL, 0x543FBBD7D3C2A3DEULL, 0x19EE01F911A7E313ULL, 0x7D4F9929C47A6312ULL, 
            0xD49383360D222156ULL, 0x098B3794B2DC224DULL, 0x2715166914152BA9ULL, 0xA9B9C9288F4ACF57ULL, 
            0xA5E677CAFBB5C485ULL, 0x5CC7F33F18C5F914ULL, 0x8BAD0AEDAC495D50ULL, 0xC4EEE1CD31745B05ULL, 
            0x3EA58AEB2CF25BB5ULL, 0x56FE4D8544B91BDDULL, 0x9BAE036CC7D69AEEULL, 0x6CA2D1BEA040E36FULL, 
            0x39E33DACE7327908ULL, 0x5838CC3A780E3E4CULL, 0xCE23DD304474CB6EULL, 0x8F321BE8C7FE534AULL, 
            0x8E341B8C1CBADC85ULL, 0x763E05B0D3F2CDE9ULL, 0x4D18B34CAD90037EULL, 0x6237F300BD429AA2ULL
        },
        {
            0x50B8A39B1875A4A1ULL, 0x8A12B221C20A1998ULL, 0x1BF65286FA767590ULL, 0x49DD0F64A2CD575FULL, 
            0xB5EC0444D77EA3B5ULL, 0xD9FE3752B32F98A9ULL, 0xE449DF8D9B98D808ULL, 0x533A99E334D6EF10ULL, 
            0x2636A666CA680BFBULL, 0x79DDFE68A4E747F2ULL, 0x8445D8FA227176DCULL, 0x28DEBC735C730AF8ULL, 
            0x83960657AEDA0ADAULL, 0xCB12B2E9AB2790FCULL, 0x1E2D329E618465FDULL, 0x68F2105FCD129774ULL, 
            0x09642F7180B4499AULL, 0x796E5D0985DFBF98ULL, 0x9F6B81154948736EULL, 0x16C68637EABBF84BULL, 
            0x400C50469A6C5F2BULL, 0x414752A1CDDB27D5ULL, 0xE73765D3DD92EA79ULL, 0x00861E71D13EA2C1ULL, 
            0xA54F54DA91ECC463ULL, 0x69979D8E5B946B15ULL, 0xF17E1A982F4B80FCULL, 0xAE2A777AE8B585E2ULL, 
            0x1098476E0FD1AE8AULL, 0x8F583FDAD1F6585BULL, 0x8975CB99F839EF44ULL, 0x7D4734F970D8E9A3ULL
        },
        {
            0x76304FC405538F04ULL, 0x39148FBDB2F909EBULL, 0x32B73D3E823A647BULL, 0xC6597385B65FE28BULL, 
            0x62A4D86A9AEE254EULL, 0xE46B8B0074AB1158ULL, 0x06222338F5D18D9FULL, 0xC79D570634255ACAULL, 
            0x6C20A8D2763D3545ULL, 0x3E04B4815A154F1DULL, 0xC9BEE6C014995FCAULL, 0xD3FBDDE21F043C55ULL, 
            0x9FC977200FEA3FF5ULL, 0x4C7F6E13B4342C90ULL, 0xA8282C49C657D3A8ULL, 0xB6E7DBB37D2B228DULL, 
            0xE3BEF5F5D0E77070ULL, 0xF674FFCB5BEECB6AULL, 0x1F2CAF6A273C441BULL, 0x648D369B9561C803ULL, 
            0x05FCAB931A6597EFULL, 0x5A500332B3F78F05ULL, 0xC84381577040E99FULL, 0x0B0D4F4289980C28ULL, 
            0x80FE438A2063068CULL, 0x150D1066F970468FULL, 0x428FE95D22B4F131ULL, 0x3C390B7C8C24ACC4ULL, 
            0xD10411CF2766FC6CULL, 0x8E5739B23F9B8C0BULL, 0x72D0899589AE796FULL, 0xBBCD09108E771F6BULL
        },
        {
            0x4592A9CD85DB64C7ULL, 0xCA4BB81E68F44273ULL, 0x3BD3AF6845326044ULL, 0x8B8FD48792F2EE07ULL, 
            0x9EC36077AC3E3F51ULL, 0x323EFE06C5E2D71DULL, 0xA1D865FFDB1CE073ULL, 0xA6742ECA9243F40BULL, 
            0x93BE9515BD8044BEULL, 0x49FA512DBB975283ULL, 0xEB139C81BDB03D29ULL, 0x51992753B9781F8FULL, 
            0x821003D751758645ULL, 0x9142FD82FB88C8EAULL, 0x480F31014ECC8B71ULL, 0xA56B05C87307746BULL, 
            0x85CD4CF7C2587863ULL, 0x418B6628F6A64A95ULL, 0x861C548DCAA9625FULL, 0x65BC47D56D45FA63ULL, 
            0xF27B52750599CFFAULL, 0x62C72DDF8E8F74CDULL, 0xB12E0DDD37F521ADULL, 0x85698BE6BBB0951CULL, 
            0xAC531A25E41938EBULL, 0xE530D0866F1C1288ULL, 0xBCE9A453DC8CED57ULL, 0xA8DF384C14892CE7ULL, 
            0x9CD8EC58F44DBA65ULL, 0x867901148B500A6BULL, 0xDAF87E3B8800D38BULL, 0x07E34FAF362CD1EBULL
        },
        {
            0x9FFE85E1A90A6A23ULL, 0xFCEC0FF576BBDF29ULL, 0xE92F44AFCFC8CDC7ULL, 0xEC7C914723260342ULL, 
            0x903C380BD5EC0E97ULL, 0xA77E75C5D2150C21ULL, 0xFC8127C2206D5D7BULL, 0x2EBEDFA52268A95DULL, 
            0x91A1697B78FF1EF6ULL, 0xB70B8EC0F9A8A091ULL, 0x636EDAB8462C1D9BULL, 0xC2FE0E0FD9FE871CULL, 
            0x74F1A7B7BD1AF66CULL, 0x0EA01E49202F62BFULL, 0x7C0C127BC6D52FD3ULL, 0xEF37BBD755AD7C8AULL, 
            0x36B87CC23DB917B0ULL, 0xA9030011F04D2CF6ULL, 0xE4F8DB8BA9D78F7FULL, 0x4843A38751FD5DB8ULL, 
            0x008C8DD265D5EB13ULL, 0x3C493A0D5ACF0BF8ULL, 0xFB3599768FCC4F9BULL, 0x961473A0D0EDE407ULL, 
            0x9F5BF672D1C48E75ULL, 0x151E895577C60521ULL, 0x6C6C70E8BA94FB86ULL, 0x7C8A0700C7BA5690ULL, 
            0x3C1D14D822ECDB05ULL, 0xEA2EE284EB04A0E1ULL, 0xE1A780DB0D012153ULL, 0xD2A8D4E32F5E5D30ULL
        },
        {
            0x6580989AA71DF4C0ULL, 0x43A2D2008BB74F65ULL, 0xEDB11EE661F2A991ULL, 0xD531745FD2E36AADULL, 
            0x8FD9904FDCDE978CULL, 0xB6974A64139D6464ULL, 0x0B57E771BBCEDF7AULL, 0xA3F35C3ABB125AD6ULL, 
            0xF9C9120FE8FBF4B1ULL, 0x374F69C30B74C92FULL, 0xC313042D0DEA60D6ULL, 0xCEA9B66A571BD8A3ULL, 
            0x97BF66D8CF2F796FULL, 0x361B5F897DBC80FEULL, 0xDDF0018EA9B518BBULL, 0xA8F0C1C731D50E67ULL, 
            0xEF8EBA5B722D9D2BULL, 0xADD88FEBCFF68F05ULL, 0xE6AFA682764C38E7ULL, 0xFB271741D35123E8ULL, 
            0x222BA07213E7F367ULL, 0x7C79C6F8F894448AULL, 0xB15A25B0D203417BULL, 0xDEC62659DB9A0060ULL, 
            0x428FEDA4AA46684FULL, 0x4F15E3E7DC07FA27ULL, 0x4918538D1F564AF8ULL, 0x1C7A352090B044A1ULL, 
            0x3265B52BC96EBA04ULL, 0x9EB10AB614D1B38EULL, 0x727C2B762CCCAC96ULL, 0x4C4EDF1267B6BE1CULL
        }
    },
    {
        {
            0x29EA4104D1DDB2F3ULL, 0x5A93DBB886C66E57ULL, 0x57151DE20A059062ULL, 0x16F3AC3D4A30AA6BULL, 
            0x6050E369E001E50DULL, 0x82E7C01178AEDB78ULL, 0x274F6E95E721F184ULL, 0x7FDEACDB224841BBULL, 
            0x4A8565CF4B64072BULL, 0x6F672B6B745E48F5ULL, 0x63615286F7D5E70EULL, 0x18D8ADB6453A9D4DULL, 
            0x414B800A9AB80532ULL, 0xB596F95C9D83E2E1ULL, 0xA265DAC0086F1C75ULL, 0x8AA481DE8BBF11F9ULL, 
            0x931CFA341822F7C7ULL, 0x13DCE779E9A7DB98ULL, 0xD3503A6190DCD151ULL, 0xBCB40A249C60416BULL, 
            0x5C414BAA6BA4568EULL, 0xC6D7CBD554C7DB17ULL, 0xE87AAFEF7E295BAEULL, 0x83D10D221708902BULL, 
            0x2FE03D9CFDCB9DC7ULL, 0xDBC3A7ABD0DFB901ULL, 0x701BED9850F32E9CULL, 0x01471C81AF21507FULL, 
            0x588938212DCC7F7EULL, 0x72F89163033DE026ULL, 0x82E6C74D441C2FD9ULL, 0x9E62BF42494D8F73ULL
        },
        {
            0xBFEB6FF4D086328AULL, 0x722AC6FE79999E1FULL, 0x5EFEE64471372002ULL, 0x74AD46ED225EF0EDULL, 
            0x356B42935FA88690ULL, 0x1F225D1EAAB2FC9DULL, 0x965831CB1E6DBC95ULL, 0xB4840C8DE028CE35ULL, 
            0x02FB13F1071A3E2BULL, 0x122CB3C69090001AULL, 0x0FF1697E3AA67B63ULL, 0x2F2D0C49867F186DULL, 
            0x1E738FC913A2FC1DULL, 0x236E46EAB555537FULL, 0xA93988C40432504DULL, 0x65588525811E75B5ULL, 
            0x1C9B7C67D14D3048ULL, 0xF21D9BCB1C1AFE49ULL, 0xA5B7D9D7839C4050ULL, 0x73FDA684A152E88CULL, 
            0x0DE231B75D225A4FULL, 0x4A1C6395BE248A34ULL, 0x973B1B95F933E14AULL, 0xAA36299E66FA0DC3ULL, 
            0x2B22E0C044165145ULL, 0x3F44A3CA8AB84F68ULL, 0x90D731374A843309ULL, 0x29BD6958DA94DB4DULL, 
            0x1336CEC8F044FC15ULL, 0x001B761E32286782ULL, 0xD9C698C3A1C95556ULL, 0x8B88FA57BAAF3402ULL
        },
        {
            0x9EEDB4F91EAE07E0ULL, 0x952D5F27C22FBE90ULL, 0x9B401A727B744844ULL, 0x9A1FD6DA9F93E651ULL, 
            0x69C147D2A9F682C5ULL, 0xF166D7582552704EULL, 0x36606E0B37329D8CULL, 0xA8CBCC51843234DCULL, 
            0x3D5474F90B294900ULL, 0x83000FB36332DCB0ULL, 0xE72A5C1B01EA5663ULL, 0x49AB05B88CA57EF7ULL, 
            0x4950A31FBE82EDF7ULL, 0x0A67A24024C0EFEBULL, 0x5C9042B839A2EF08ULL, 0x5419A6BA06BD5202ULL, 
            0x833673DB3AA8E792ULL, 0x05A217D7B08ED596ULL, 0xD73AA2FD94C16B15ULL, 0x055B949372A71026ULL, 
            0xC7DEA8E934E065CBULL, 0x6F1316CE5DBBFCA7ULL, 0x5950016680AA9A4CULL, 0x79ED0E97BCB9A97AULL, 
            0x7677CD586AE49F35ULL, 0x0E2C16459CEB5D51ULL, 0xEF93D19EE004FBC1ULL, 0x2714826F6B72A56EULL, 
            0xEF16D7650271C774ULL, 0x62EA9BCEBF13C765ULL, 0x02E3258E4C49FE2DULL, 0x42E895C0FFB23BC8ULL
        },
        {
            0x43FD924497B8E68AULL, 0x46EDCE0DDD6EC3A3ULL, 0xC8077611B0CD7612ULL, 0x7A4E456CEEAC1FE9ULL, 
            0x98DE5F964081115FULL, 0x2D18AEA9DBAECA26ULL, 0x4560669B7FA3A921ULL, 0x2A5D3E0CB5CC5108ULL, 
            0xA3D213D2F70F1C66ULL, 0xAD6CEE25547B76AEULL, 0xF7AF97E329AF5A2CULL, 0x16663CC68668F894ULL, 
            0xDA722DFF18ECDCE1ULL, 0x7F81F4C2D2ECFEE3ULL, 0x037BADC8FAB4D229ULL, 0x3EF45B9628BF6EC8ULL, 
            0xCD0EBAA31EDA0B55ULL, 0x50475052EEC40664ULL, 0x18E71063D127F044ULL, 0xC633E605CDD4FA7FULL, 
            0x3A56A66506A9617BULL, 0xA954F2C93A34D2CFULL, 0xD0A6EBC74F6F592CULL, 0x07B3DD2BC0D064DEULL, 
            0x073BBC565D217F87ULL, 0xB1929A1908CCCEEDULL, 0x0F9CC21FFDA021F8ULL, 0x9866B1CD5B035A7DULL, 
            0xFD75A482ECB9C854ULL, 0x59B616DACF1E761BULL, 0x897D6BA0F9107DD6ULL, 0xD8E09A8C99D11C0EULL
        },
        {
            0x4CE4DA2C4013471AULL, 0xFA6725C742ADC57EULL, 0x6015D9B3E0EB0AE3ULL, 0x2D33A5609B74B820ULL, 
            0xA35C7C35B1DAFBAEULL, 0x931D3AE6787A6461ULL, 0x705F90FCA1E22BD4ULL, 0xDA3758171A7EE952ULL, 
            0xD2C43C27F7E502DBULL, 0xA4303655392B9AC5ULL, 0xDA943209F9A20877ULL, 0x7C369A5FE4A076A3ULL, 
            0xD58CBBBBEBCB3A90ULL, 0x2603D0C287091EE6ULL, 0x265935783D3B50F3ULL, 0x1FA0ABBF3C7EE4C5ULL, 
            0x89DAB661A3A249C3ULL, 0xEBEC5BB49A9DF399ULL, 0x34EEF5CC472BAC21ULL, 0x9564838C388A8DFEULL, 
            0x8FA6A1FB873982A5ULL, 0xF10BFF150E561C2EULL, 0xA57F62C048F00352ULL, 0x6E4617274736D374ULL, 
            0xA24EBBE6F0D22223ULL, 0x76B439436FD1C474ULL, 0xBACFD605F22A12E6ULL, 0x5D6562D80DE40CE9ULL, 
            0x77F2FF68F95602E4ULL, 0x49E7C9276533DC64ULL, 0x968804D751A596FEULL, 0x7893140D6B18D978ULL
        },
        {
            0xADC513E667DE7624ULL, 0x416A84B69CD5CD7CULL, 0x9C95C3A1B7CA4D34ULL, 0x4C6390DFB376F122ULL, 
            0xD905B1DEFB1F631FULL, 0x26B0F588411A439BULL, 0x233BFA778815ED76ULL, 0x4F9F5CA8AD0DE530ULL, 
            0x48093663F40AA091ULL, 0xDEF8C2FEE59C2AF3ULL, 0xBC241646DA66A0E0ULL, 0x1F6F29CA5D85951EULL, 
            0xB6E3E04E6CD22B06ULL, 0x82A42CEFF0D5D5EAULL, 0xFE9C36460C49E1E2ULL, 0x6D49656632292F4AULL, 
            0x70AD6ADFA41F2D88ULL, 0x4C45570527F10447ULL, 0x0237165FA2F97A66ULL, 0xB593E9823E4516D8ULL, 
            0xE753863A0177459FULL, 0xB291C7C19D5A5562ULL, 0xC59241B62BFB9347ULL, 0x53F132DD4516FDC7ULL, 
            0xBA0F27F15F9DCFF8ULL, 0xE8B93D697F0D8D1CULL, 0x286C33704B607FAFULL, 0xAF99180FEE1CB42DULL, 
            0xDC532FAE7020B9A2ULL, 0xDF7CF4566A39CFCCULL, 0xCD25E45CA1B35767ULL, 0xC96A4AF2814CB07FULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseBConstants = {
    0xA168561B9FF91172ULL,
    0xE9C3C5B3CF091C07ULL,
    0xCF1D4445CFE32FC4ULL,
    0xA168561B9FF91172ULL,
    0xE9C3C5B3CF091C07ULL,
    0xCF1D4445CFE32FC4ULL,
    0x948F70D97CFB4141ULL,
    0xA29EF47D8827762BULL,
    0xBC,
    0xEE,
    0x65,
    0xE2,
    0xA5,
    0x73,
    0x88,
    0x15
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseCSalts = {
    {
        {
            0xC87C9CD535D15F8DULL, 0x25AB0A6F089DEFF2ULL, 0xC05EB29318954E36ULL, 0x0C0F719253D8807AULL, 
            0x68DE8F88D46D3486ULL, 0xB8A4D0604DCAEB74ULL, 0x8F7DC46BEFAD5014ULL, 0xC0EF24E3184680DDULL, 
            0x2C71C2B65D706260ULL, 0x5964224C9E8DB0DBULL, 0x294DF9B90999443DULL, 0x147CEB5FEFA8CDB2ULL, 
            0x9842CD138ECB5875ULL, 0x54497F37C7DE5FB0ULL, 0x1750DEA63D78EFA0ULL, 0x480497C8DBA6C011ULL, 
            0xE937F6201C5283E2ULL, 0x4208C1F3852B46CBULL, 0xAFED53FEEE9AE51EULL, 0xEF5E4A9F04F96297ULL, 
            0x49B3E2E4F68E8FFBULL, 0xF13D2B5A73B327DAULL, 0xADE8AD5EFC1612A5ULL, 0x1C4184935048050FULL, 
            0x96BDF99665B78E69ULL, 0x6250286F5BB7681EULL, 0x0EB081A39047FEC8ULL, 0x5D1693C5BF571967ULL, 
            0xC0A3C5986904F587ULL, 0x4648388F5B80D3D0ULL, 0x7B58BF051FD9C789ULL, 0xC218A6F8C31FBC03ULL
        },
        {
            0xFB334C6421E2C0D5ULL, 0xDDA9920D622A2D2CULL, 0x6B0096E8AE155761ULL, 0xA72267591F0A71BBULL, 
            0x34618D6FDF77FF50ULL, 0x2421C2035AAFEE0BULL, 0x5063E50DD3568623ULL, 0x421F3F21EA1D8330ULL, 
            0xB58B0E1279D5C9D5ULL, 0x78BC9BA96A1EC1B3ULL, 0x93557CDF8D995321ULL, 0x6AE7FFC8E874E26BULL, 
            0x876D6269F57EACBFULL, 0x5B9F9A6B9C7A02BCULL, 0x1183541D53B7D009ULL, 0xB7B496E075098299ULL, 
            0x58C60F42A3A5E0E3ULL, 0x0972FE9278B9C78EULL, 0xA1C1EDFC1AAC9B0EULL, 0x561483C757FC7275ULL, 
            0xCD693ADC30F64A85ULL, 0x289125C9DAC30CCAULL, 0xF5374C26DF1C9B00ULL, 0x11F2EF9AD7FB4982ULL, 
            0xAE203697DD91A8F5ULL, 0x4C85F7A0D00F413CULL, 0xA7C7FEAC05700A14ULL, 0x46D8A4D68B79F407ULL, 
            0x570D53EB78EE7DEBULL, 0x3E0E7260DA6472A5ULL, 0x24FB19AAF013341DULL, 0xFDB94BF36BE82EBAULL
        },
        {
            0xC67C6BE27F43721EULL, 0x421A96125B1F87DFULL, 0x526A42FF522F3A1AULL, 0x5E974D5350D4FCE6ULL, 
            0xA09A193DD7604D86ULL, 0x3F703DE8FC4B4E9BULL, 0xBEEF6D24FF2CFC46ULL, 0x360736A1D76EB8A0ULL, 
            0x48B42B36272BDAF7ULL, 0x72762CC7BE5AEADCULL, 0x4C3AA89C4B84B8FBULL, 0x8114D89D8319E6F9ULL, 
            0xF7AFD8430D1BED89ULL, 0xBEC9E984F7D86BDAULL, 0x1420AA0CB91CF55AULL, 0x9BA11451CF9B09FCULL, 
            0x2098B61635F91066ULL, 0x6D353945AD9688D7ULL, 0xDF4D3B6164F1AA6BULL, 0x969CFEA082A49DDCULL, 
            0xD7645D5BB941BFE7ULL, 0x81D2A38121BF2F44ULL, 0x7EF88DCF6674BC0BULL, 0xAC2107345A14BB6EULL, 
            0x97CEECA56D16A8C5ULL, 0x66912A4102182082ULL, 0xB7C25B4771041ABBULL, 0x47F9E51B3C391C61ULL, 
            0xD63B0DCA8BB7D9A0ULL, 0x7E6C8C9A72CEA15AULL, 0x940340E812E957E0ULL, 0x24BF8784484EE84CULL
        },
        {
            0x7894144E103517CEULL, 0xF094AA43090684E9ULL, 0x58997586839BDFD5ULL, 0x54D1CF214C44F577ULL, 
            0x0E901F0C049983C2ULL, 0x15A24D10C4A1C7C0ULL, 0xF2B7807EB44A9E8BULL, 0x7B6CBCB36D750097ULL, 
            0xACEC824B47C904A9ULL, 0x959C6740B23A318BULL, 0xF4FF7DF09A7A3861ULL, 0x8DD89D2586B4DC67ULL, 
            0xA47AE3A104F62200ULL, 0xB39AEB9D4FC46B14ULL, 0x98366B69A4D7F8F1ULL, 0xEB505C3FC4FA76CBULL, 
            0xC7EBBC713D1351EAULL, 0x03DA780BBD5D2F0AULL, 0xD3B2D85D53393DFAULL, 0x2DA9D5EB4A5F6904ULL, 
            0xD881DAE4137865ACULL, 0x5D06BB0874054B37ULL, 0xFC7AC4A0AED38605ULL, 0x16AE2EE6C6DAB6A8ULL, 
            0xA55AAD1D84AF293DULL, 0x1A4161D2960CBD6FULL, 0x5FD834D247765295ULL, 0xCF60D01C2A3FC868ULL, 
            0xEB9F37F6671671D7ULL, 0x287822C77206E71FULL, 0x56AC2796CFE45027ULL, 0x73ACD8A951C03C3DULL
        },
        {
            0x6CF7D7E7672B5D2DULL, 0xBA09A991FA372E71ULL, 0x9189F43DFD932B47ULL, 0xD219C173CDEFB73BULL, 
            0x5289B9A97234281EULL, 0x9A941CA5D689607BULL, 0x7FF8172E1F8C9283ULL, 0xED85A308DDC065A9ULL, 
            0xF1C0021865A9F048ULL, 0xF9C48507615C57C7ULL, 0x36AE68729BB9DEEFULL, 0x3FB80CAC9D7E4286ULL, 
            0x9415BACEAC1BA215ULL, 0x32C782495A400576ULL, 0x090DD0ECA9A70C0AULL, 0xA41E16E531681433ULL, 
            0xE5EF529FBDB1C15CULL, 0xB808BFB492529A42ULL, 0xBC6D822DDEC4CB29ULL, 0xFE1343C078B649F6ULL, 
            0xCAF83E728A468BA1ULL, 0xEDAF21E9F36BD2DAULL, 0x614F5BAD87E0303BULL, 0xD665D274E3F49BF9ULL, 
            0x858C12514E1F2A8AULL, 0x78AB9D54985F7E8FULL, 0xF7D2DC45A6167B1CULL, 0xFED5A823E9C3E8EEULL, 
            0x1B5692C5CC5E9253ULL, 0x67133CCD6600D791ULL, 0xFACBAB282FB31A68ULL, 0xBF632F16D900DCCAULL
        },
        {
            0x29257F57FFF480D9ULL, 0x600F088DF57D57DBULL, 0xF66E6A0FFAF9CE17ULL, 0xC250DA87AA7A03F6ULL, 
            0x10B5BD808DCCB51DULL, 0x15273A264E4D4EA0ULL, 0x157AE70700111235ULL, 0x78E337F35FC646EFULL, 
            0x627FF141D4A1F41CULL, 0x6FF17C287A48F92DULL, 0x899FDF1646DD8A2BULL, 0xB4ED683075AD7DC7ULL, 
            0x02C3B17AD783BD45ULL, 0x9DFBCA21C8F060ADULL, 0xD3F7DF72EBB89178ULL, 0xBD39496C0473310FULL, 
            0x4F7DEBC3677CB90AULL, 0x696C7F26E3AE0F84ULL, 0xEE387676DDFD4E2CULL, 0xE8056D1F1C911AF0ULL, 
            0x02E61D1D98D50D66ULL, 0x40DEA625EB5CA3FDULL, 0x6DEB17BBDCAD9DF2ULL, 0xA8C9CE628FED30BAULL, 
            0x87A680A5CD0C2E11ULL, 0x33481B309CE4FA38ULL, 0x732A5DA41E4AA0ACULL, 0xF2F497E84DE94A8FULL, 
            0x32F31F18162A15F6ULL, 0x38399C6B6A749C94ULL, 0x81EA6B3487C5A71BULL, 0x9EE6403B2567EE25ULL
        }
    },
    {
        {
            0x4553CF07AFD0AA1DULL, 0x123B80C7F0BD7EAFULL, 0x5CBDEDAD89BC1EACULL, 0x9CEFFEB2E241C896ULL, 
            0xB69CC25304664ED5ULL, 0x28F6C0798C6077C0ULL, 0xEDD5B03698EB385FULL, 0xEC441C9622B24C5CULL, 
            0xA21CBACD3108ADF6ULL, 0x0FDD3588527AF967ULL, 0x0514516A2FFDA795ULL, 0x106B94C4FD7310EDULL, 
            0x316341356C273ADFULL, 0xE6FE4E0A74B8D30EULL, 0x4697DDF6705B5C53ULL, 0x964CD8E4A7A0E5A4ULL, 
            0xD6E64521F5894701ULL, 0x54D5D4842DFA7D87ULL, 0x617518B8A1CEB50FULL, 0x1F7DCC62303AD719ULL, 
            0x558A58AB3B755C48ULL, 0xCF5EE85B6668DD9FULL, 0x4244C845B9EC6130ULL, 0x5E6C0CA2C4CCA912ULL, 
            0x49739C0448126991ULL, 0x938B0975987CC9B1ULL, 0x7C9E2F9777D90E5FULL, 0x46CE525E2BD79D1EULL, 
            0xADA5DAAE4DD4DD9EULL, 0xCCCB1B3CED7E1787ULL, 0xC7F7F9478344FA05ULL, 0x972434CD803818B1ULL
        },
        {
            0xE5197FF99BF70EE4ULL, 0x29B4C67B154B49F9ULL, 0xEC4DE64E7DD3B88FULL, 0xB9B889C5E63B450EULL, 
            0x0FFDA75E6E5683FBULL, 0xF88A8D0219259FC9ULL, 0xA26D467B056228F6ULL, 0x0E803478A9F86EBCULL, 
            0xAF3C94FFEE2B5F3FULL, 0xD67F72F95BC99BCCULL, 0xB428E6D20F536B6CULL, 0x3A011400E6F92B62ULL, 
            0x03EE836EABBBA3C1ULL, 0x6A2F28785FF00E85ULL, 0xC45E1F29D5C77F9EULL, 0xCB222477E4065F11ULL, 
            0xA10AF3B5C9F7F8FAULL, 0xB9A2BF305228F71BULL, 0x4A84B18517F0CC98ULL, 0xD62459B1ACD47D2CULL, 
            0x8305D4ED3E33E341ULL, 0x2F126D87C0EE2156ULL, 0x993A99F7ED62418AULL, 0x3A42C3E66FC061C3ULL, 
            0x53D8224B189D7D82ULL, 0xDB1EA5CC528C3FD1ULL, 0x7E05BC67AA9ECD98ULL, 0x9F391BFAA51C8C84ULL, 
            0x0FAB2B2FE708E798ULL, 0x48A407402D6CC51FULL, 0xE62B38A265535B0CULL, 0x04EDF8BB915F9FBFULL
        },
        {
            0x23C267CB8E7E8803ULL, 0xA6775D8C18984158ULL, 0xF192BF667BF35399ULL, 0x7674C0179B0BA73DULL, 
            0x2408DF973E8855E2ULL, 0x65A2FA9663642A9BULL, 0xAC1EB4D9F21FEB1AULL, 0x4F6B5F595901A124ULL, 
            0xD3E449DBBDABBC09ULL, 0x9FB13AF0002A61FEULL, 0x21C0F49EECB4C59CULL, 0xB53A529618884BB0ULL, 
            0x4B23D21E85667AE2ULL, 0x8FD5F6F148458628ULL, 0x64A1C46FE34097B7ULL, 0x2F6B8AC045288481ULL, 
            0x38F718DFB9380D60ULL, 0xFD3DAB04522AA0ACULL, 0x8361BA57033F9116ULL, 0x11B6A6EBA029766CULL, 
            0x53A19104386C79C3ULL, 0x2ED350E2A1575916ULL, 0xA0CC4E21FD8E3C35ULL, 0x6EF2BAE008747382ULL, 
            0xB4A1287D837A9482ULL, 0xBBDB35EEA58F40FFULL, 0xBE2314CBA94763F8ULL, 0x033C176DB4828ADEULL, 
            0x52B539065202C0D4ULL, 0x34EE09980AB778E5ULL, 0x290E66A4532402E5ULL, 0x2168EF6EDC1E2A8FULL
        },
        {
            0x7799C6B5BE8AFD87ULL, 0x9E7FB8472230DD19ULL, 0x189E7850C3BD4832ULL, 0x9D91C2188B6F2BE3ULL, 
            0x29F4EAE3E923FCAAULL, 0xC28F37B240BDD4A3ULL, 0xF7C3ED9654C077BDULL, 0xCC70B4994FA86203ULL, 
            0x2DAADE7525924885ULL, 0xECC9F5ABF5A509B8ULL, 0x9F5DB11EA73BD5DFULL, 0x51D886CE1D4B43D1ULL, 
            0x3879DCB23EE32C09ULL, 0xE3A79D08F4093373ULL, 0xBBA8BD7763445DF6ULL, 0x69BBEF55ACA620D9ULL, 
            0x74AB962D475AE259ULL, 0xF4279DC8B8911A87ULL, 0x76F2BE8485DD32C1ULL, 0x7B85A5307E950A75ULL, 
            0x9656B217E9DAEBB1ULL, 0x80A8E16CB9F2E143ULL, 0x18F1520B832D25B3ULL, 0x860AF4132F7729CEULL, 
            0x2D39D036891D02B0ULL, 0x6E1E725E949C77D2ULL, 0x4C5B1139ECCF7A4EULL, 0x1D730E622E8A3761ULL, 
            0xA52D37F14BD88796ULL, 0x0F77F71234461ACBULL, 0xEAB2C5F2C59D5822ULL, 0x151185FD2AEDB70DULL
        },
        {
            0xA6F8ACA3C6396F8CULL, 0x453AE74EE49C57E7ULL, 0xCD46929FBFC9C266ULL, 0x48BB2F15E51C8BF2ULL, 
            0x8C53C9EB63F1559EULL, 0x1A017EA7DDB11695ULL, 0xDB3D834F87A2B450ULL, 0x422D93A7EDA61172ULL, 
            0x348CB6773040BE71ULL, 0xD92622D2FABFE80FULL, 0x2B4B02BD2B14D895ULL, 0x91D4DE1C6F1C6461ULL, 
            0x9925D36A4C9857CDULL, 0x5D8CB32CBAD9E399ULL, 0x80956A536638E316ULL, 0xD267C3D8BC9F880BULL, 
            0x9E2482AA815F3BA9ULL, 0x54A40D5D361CC4E0ULL, 0xFCE364D9218CD93AULL, 0x8539B8A22455D3A1ULL, 
            0xAF66EC82CE81368BULL, 0xB0516B0DDCF06BE4ULL, 0xD8ED4FC7F37417BBULL, 0x0EE9D46BDE44B80AULL, 
            0xF03870BBEB59DF21ULL, 0x88F3B223C04C9E4DULL, 0xFE49682B0F82EBB8ULL, 0x92255562901AB5A4ULL, 
            0xEE8CCA4A4F1D80ACULL, 0x3403C1C2F7B5B257ULL, 0x2F2844E016E6D514ULL, 0x0168FC7267F8BE92ULL
        },
        {
            0xB969B60B6DF60A6AULL, 0x5750DE3ECCDA2B7DULL, 0x4AF7C5E3D2DD27B2ULL, 0x86CA8F8D07BF84AFULL, 
            0xB337FAAFEE357C3AULL, 0x11BC4C26A0DCCA03ULL, 0x8475A7DBDAFAB033ULL, 0xF5DFD4AE23960049ULL, 
            0x907098653D629F36ULL, 0xBA5438E9EB2C52BAULL, 0xF0D392210EDBBE7AULL, 0x91F28477F0493EB3ULL, 
            0x332F596A3B6AA5EDULL, 0x48A31A38092DCCC3ULL, 0x8D789BE9A3699A83ULL, 0x4F91F9152E9F07E3ULL, 
            0xD73422A11328063DULL, 0x758E045B646EC6A4ULL, 0xB96E84A8D03AD851ULL, 0x64803A6E98BA8888ULL, 
            0xE212291715786680ULL, 0x5CF0104F7BAA21BAULL, 0x74A979B96A3DD9D1ULL, 0x3053FE8254C7868CULL, 
            0xA6B498A2527010FFULL, 0x1457E0FFD689E4CFULL, 0xE10334E75D501586ULL, 0x351682F86237B71BULL, 
            0xDF811577AAFDCCBCULL, 0x669A5EFE9CBC2780ULL, 0x6D1AB759265C07C2ULL, 0xF8E5D49479D18A8FULL
        }
    },
    {
        {
            0x50A9707F59D63385ULL, 0x0CD41C5D83C13154ULL, 0xC72D927D14D25DA0ULL, 0x7D1CC492715E8C8BULL, 
            0xCE6B9C41A71170D1ULL, 0x8B6A2B7F9257ECDDULL, 0x8BAF1639EAB9E8CFULL, 0xEDC47D734F050948ULL, 
            0x0053CADED3E9EC99ULL, 0xD2701B3EB287EA03ULL, 0xD4F240160DF04A31ULL, 0x648E079A5B766325ULL, 
            0x8A64B52039D8A7C6ULL, 0x544E706B4A7669A0ULL, 0x96DA06F241AF51BEULL, 0x794497FBEB041740ULL, 
            0x2ED51057F97D319FULL, 0x0972AFAB50EB7733ULL, 0xC9AD23940B49E62DULL, 0x05AD36BBC6536701ULL, 
            0x6117448198FD90A3ULL, 0x2AAF63E572EAB23FULL, 0x23DD044FC688F12FULL, 0x00C47A0B34D812F9ULL, 
            0x2342921746C7B66DULL, 0x652076B1E99B554EULL, 0x6736EEED306E9DCFULL, 0xECEFE114133F6972ULL, 
            0x515799F8A1EFB6E1ULL, 0xB474410E65F9FA47ULL, 0x2E904AE34FEB66BBULL, 0x10343E2CD1F3AC65ULL
        },
        {
            0x0E57BCB2B4E41BBEULL, 0xA694783EE7194CB2ULL, 0x4B0EA0DE48BFE8E0ULL, 0xA46136A7A869C45EULL, 
            0x48CB47724B3467DEULL, 0x895A9A485FC3730CULL, 0x4462D59202114B0EULL, 0xFD4B77B0CA044A79ULL, 
            0x32372079DF70271AULL, 0x437E61932AF302B0ULL, 0x9E0A4890E1DBAC7AULL, 0xD72EA1A1309F6C08ULL, 
            0x38B158783C3F910DULL, 0x3CAE2B358B8A1B6DULL, 0x12BC3E5E90F25BE0ULL, 0xCBD80058ADD4E2D2ULL, 
            0xA68A6ABD2358AC86ULL, 0x5B4952521F01A808ULL, 0x47D861FB81C31558ULL, 0xEE4A05F2AC4F6EFCULL, 
            0x29D3920EE7E6EFFCULL, 0x2E1D3B6921869FEFULL, 0x59161290BF4FBC0FULL, 0x44DCCDE0B88FA720ULL, 
            0x5945FE39D9D4B279ULL, 0xBF9E9809D95DC66EULL, 0x0CD5A6EBB66462F8ULL, 0xAA4E455B2CC6221BULL, 
            0xABA3FE33F778EAE2ULL, 0x0AAB4D60AC2388BAULL, 0x69D87CF7E040C216ULL, 0x64C99C11B5EF9365ULL
        },
        {
            0xD8585D6E003B70B4ULL, 0x2A7607BE833CD646ULL, 0x758BD33ADD0DC8BAULL, 0x0F86AD70CEDF4276ULL, 
            0x3F11D7B034C026AEULL, 0xAD57ACFA38A6BAACULL, 0xF173AAB867FED9F5ULL, 0x2CA8645616F9FBDFULL, 
            0x878CEB192B04071DULL, 0xC26021AF786A2B52ULL, 0x1B66A71B833AB2BCULL, 0xC85050A47AD84F22ULL, 
            0x39410DD2DBBBA57FULL, 0xD127FB08E64A45FDULL, 0xF7B3E76B4BD78558ULL, 0x6083ED94B5441521ULL, 
            0x6245D5E61EB79394ULL, 0xBA2923E7339EA2E0ULL, 0xFA3D4A3D07376222ULL, 0xDCA656BD7E054573ULL, 
            0xB1D91BDC776A0634ULL, 0x9C763442D9236187ULL, 0x4F7DA34A7D9872F2ULL, 0x464555FE4D734A80ULL, 
            0x2E77BB4D560D5EA0ULL, 0x07667536AE9CA7A9ULL, 0x5B33D3A22368B7A9ULL, 0x66D01428398A2168ULL, 
            0x4C5113CDA9350E14ULL, 0xBE93F6D1F8FBB0FEULL, 0x6B0019F0D16212A6ULL, 0x04FDA5A2981F6D6DULL
        },
        {
            0x006F8D3F4ED88D0BULL, 0x5842D5C8B0B852FBULL, 0x2ED9FA99D1E6C4F0ULL, 0xAC585E07DBF35274ULL, 
            0x18E422E6AF7FBB07ULL, 0xE8F3BC690B68386EULL, 0xA71D7841263F7A55ULL, 0x47DA4051B8C6A5C2ULL, 
            0xE40E0353D906D2A8ULL, 0xD2381308FB56BDEEULL, 0x65ED7D46622656F9ULL, 0xD99643DDB70F743BULL, 
            0x0A8044444BE02E00ULL, 0x89497110AE081C20ULL, 0x7CBBB5C88C737EC5ULL, 0x11A41B8239B7D773ULL, 
            0x79D6660BE725E7EAULL, 0xB086A9DACB6F6984ULL, 0xF2771A9DE09C758DULL, 0xA2E9CA142B502351ULL, 
            0xB161B3247DC80763ULL, 0xA251FDBCC11A9F28ULL, 0x8AD54090B9177173ULL, 0x16BB3059A616B75BULL, 
            0xDCE5575D1C38D2BDULL, 0xA7278BE6380E8241ULL, 0xDDC65F057295E7D5ULL, 0xE298ABA0FB41DE49ULL, 
            0x5BF71116AF6415F9ULL, 0x800BAE4FC8F90A85ULL, 0x6CD2975B880B40C1ULL, 0xC6C90697EC006C24ULL
        },
        {
            0x4971443527C72478ULL, 0xE836447E2CBDDF89ULL, 0xF4DE9DA3B0A11BADULL, 0x84CCA4BD6DBDABB1ULL, 
            0x2CE6058AF3BE7FF7ULL, 0x59F445778DD89A4FULL, 0xF3F04D8567423B71ULL, 0x2E6A785965D79E02ULL, 
            0xCC6B858ED472A81CULL, 0x8E5B44D1C247C483ULL, 0x0D586CDE8B320BF3ULL, 0xC1C96DA232E4596CULL, 
            0xDE739BA7EEAD1E21ULL, 0x781D85A9BBB05F2FULL, 0xB6CE52188666B09CULL, 0x644274A98C9AA9D4ULL, 
            0x27315C0BFBCAAF45ULL, 0x04CA8CB914EDA7BEULL, 0xFAA211682CA86DF8ULL, 0x8FD3F459333AEA45ULL, 
            0xD5EB73763F1A6B35ULL, 0xFB30B9844E67A86DULL, 0x9F2D892EF2AF7C89ULL, 0xFEF62D530426B019ULL, 
            0x4D16DF59A15E1E78ULL, 0x51220309F993E877ULL, 0x545B60D24DB4E735ULL, 0x7260FC385D8C37B7ULL, 
            0x50A274E5C8098F93ULL, 0xDE9CD52E1644AFA4ULL, 0xB0A3F9E6B699B62BULL, 0x8A436C78FC44AC7AULL
        },
        {
            0x80DB35B05E8FD568ULL, 0x19B7ED3694086C52ULL, 0x1185CE525748AB74ULL, 0x8F89B75AC3321895ULL, 
            0xD91583EB80B3320EULL, 0x08900D3BE4CD744DULL, 0xB2085FBD08DF39B7ULL, 0x5A748AE24CE6AE5CULL, 
            0x16F99D1C58017D6DULL, 0xE6D3F1F22E95CEF9ULL, 0x06F2E21489D5AF5FULL, 0xAEEC11ACE828491CULL, 
            0xB2BBFD5F04EF29A4ULL, 0x403D44FA7F75C23BULL, 0xE71D952CC5EFD826ULL, 0xB99CE5A2406CDDC5ULL, 
            0x87EA44A941318194ULL, 0x292C77436BEBF740ULL, 0x7C7CFB5FB43E027BULL, 0x5323B4910DD9EAD5ULL, 
            0x51FC8CD6E38C504AULL, 0x590A7013B5477BF9ULL, 0xB91067BE77E7E4FEULL, 0x639B61998516765BULL, 
            0x4DB12ADAB50B57CDULL, 0xDB2ADB50AA812750ULL, 0x46C1A53F00E4E0D1ULL, 0xE2D914CA475C4865ULL, 
            0x4A783BE799F58232ULL, 0x2AA22E3F1389A017ULL, 0x79EEA84FE0A6821BULL, 0xB1CE1043CB759AAFULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseCConstants = {
    0x72CAD6A84B3ADE68ULL,
    0x190AF1B587E9E607ULL,
    0xA5E46D1C3570C8D4ULL,
    0x72CAD6A84B3ADE68ULL,
    0x190AF1B587E9E607ULL,
    0xA5E46D1C3570C8D4ULL,
    0x81EF9C2E9E08A971ULL,
    0xAEECA11A0B100525ULL,
    0x61,
    0x17,
    0x90,
    0x66,
    0xC9,
    0x4F,
    0x22,
    0x78
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseDSalts = {
    {
        {
            0x93992408ADA59983ULL, 0x290709B7E21EDDBEULL, 0x364E4774E4C68DFAULL, 0x40301365898E7611ULL, 
            0x360A76D38C26ADD9ULL, 0x7EC8D4C9CD512FE3ULL, 0x73945519904C091AULL, 0x4377979E9FA255ADULL, 
            0x9D53B53FB3B76EFDULL, 0x91B5D6D49B9132CAULL, 0xC0809929B9AEBA70ULL, 0x1C29F5B28D797D10ULL, 
            0x11F6CDD3428D97EEULL, 0x5683ADCDEB90F0E7ULL, 0xBC0255613C550E1CULL, 0x9B936641FCBC685AULL, 
            0x1A6871D11A342877ULL, 0xBC11567A2F0165EBULL, 0xF5D886D3529EAAFEULL, 0xD816B1188F2E1325ULL, 
            0x0FD7324B8C7C20A0ULL, 0xD9818C3EC7297413ULL, 0x294A11FE5250C27CULL, 0xFE8322545933C815ULL, 
            0xFC8540C771911743ULL, 0x9C38179D078133EBULL, 0xF0FE0774BFEEF820ULL, 0x062F1BBE7F6A96C6ULL, 
            0x49E97BF7EC4C8111ULL, 0xCFB57AC1DFCA6F56ULL, 0x353863C3955C7D3FULL, 0x51F37BD497B40E34ULL
        },
        {
            0xF9C5D943694E0C19ULL, 0xAFCFCCFF18F99294ULL, 0x39ED2FC034F783BEULL, 0xD757F1369D5F9B10ULL, 
            0x9954B31F5523B6CCULL, 0x636965161084DC1BULL, 0x92148E423FBCF793ULL, 0x7508E7031AAEF776ULL, 
            0x22F7271EB795620CULL, 0x302CC6F1ECAFD4C6ULL, 0x8D71362165394883ULL, 0xB15A38FB043F548DULL, 
            0x553489E837E01E12ULL, 0x100A6A0C6389D65EULL, 0xDBF5215B949B3389ULL, 0xF8B32C02AA2EA7CAULL, 
            0xE6AEF9E160756054ULL, 0xA39F230ECDECC300ULL, 0x8708E0AF84221D7BULL, 0x88DDE96FA03AAFC5ULL, 
            0xE886B03AF2291431ULL, 0xF50B80A4E152E1B0ULL, 0xBAFEB854BF2F8C18ULL, 0xB41A75F4CF289A32ULL, 
            0x62F7D489316CE3CCULL, 0x49AA60F3A5F5379CULL, 0x4F9C85F919BBA90DULL, 0x05B2FA8FCC98E9B7ULL, 
            0xDDCAE277030E32A6ULL, 0x2172094595EB9981ULL, 0xA3AC7379DB5FC78FULL, 0x381044A3A2951909ULL
        },
        {
            0x922063E6980207E9ULL, 0x665E11294B920401ULL, 0x29145428BF27AE92ULL, 0x1E42D1347E259F12ULL, 
            0xC14E5AF0ECAC32D4ULL, 0x15EEAD07455DC935ULL, 0x820FF7F0BF557263ULL, 0x8B1808B198363868ULL, 
            0x3B6BD93B25F29D6AULL, 0x78981738F83B048BULL, 0xE120BB72B40CD426ULL, 0x93D63D631A7C917EULL, 
            0x04B66C24040B5CD7ULL, 0x4E93C54932A0AFDAULL, 0xB5FF4BD0C55EF16AULL, 0x0F4ACD1BFFBB9841ULL, 
            0x63DBF2A476C20A4AULL, 0xE9946940EF79DF6BULL, 0xFA4581335060B835ULL, 0x0C2D971CC639AA8BULL, 
            0x730F5F3BB9616273ULL, 0xC759C096C0DDA19AULL, 0xE9C2D694CCF9F429ULL, 0xC2ADE97980D2EC3BULL, 
            0xC7C8560E19F4D62CULL, 0x7BED7781F3B842B4ULL, 0xC44E39BB36F61619ULL, 0x09F455A97131BCE7ULL, 
            0x913F4B262899536BULL, 0xDC40DEC2E0A2BC82ULL, 0x30BF15CC930250D0ULL, 0x37DE1789EC582719ULL
        },
        {
            0x2C7DA321F9377B19ULL, 0x6D710368D437BBA1ULL, 0x12EC21EAFF0D8C29ULL, 0x5C55E681B2CBABDDULL, 
            0xD88CD840DF5E16C9ULL, 0xFA4AE467E3672339ULL, 0xF5292C3FDF2B4952ULL, 0xBB7B44F4F60B1D60ULL, 
            0x89953697B9C1794EULL, 0x47835A72DB4B1FEBULL, 0xCCC7CF0472291420ULL, 0x4D294B75A4DA74F3ULL, 
            0x114012FD4ABF2662ULL, 0xA56E777CE984503BULL, 0x19E011BE75DC39E4ULL, 0xB76DC4EC413C26D8ULL, 
            0xB47B3869E67BF0D6ULL, 0x6B0310CC0E67393BULL, 0xA1CEF78A047CAD04ULL, 0xD01F523F9A177E84ULL, 
            0xEB0ED02FC15F7471ULL, 0x32199A5FBF77A290ULL, 0x0B6E24F91A271460ULL, 0xF3D56CCF46532D9EULL, 
            0xC51EB7146DB41830ULL, 0x736C02C92520E2CBULL, 0x15BFF8B68ED34D76ULL, 0x32027D873C967B80ULL, 
            0x8F5B3E583131373AULL, 0xB8031CD16561514BULL, 0x6853F300627114E7ULL, 0x70B816EFD6217B16ULL
        },
        {
            0x5CDA9AC55AA50D12ULL, 0x5F692520BE06F914ULL, 0xB7992E720B73554BULL, 0x10FCB9BB3B50118AULL, 
            0x2B720D12F8F84C03ULL, 0xE185716276E92A80ULL, 0x48D3655200F54544ULL, 0x6D369A293AB6ACFEULL, 
            0xEF575FF869B63516ULL, 0xC72FF9BCC5808C74ULL, 0x2C926B48DCDE5C16ULL, 0x30D715D36406528BULL, 
            0x43B4ED6B862AB168ULL, 0x6EC2E85E70A602D4ULL, 0x3CD4F66730EA7CFEULL, 0xBE17AA9B5AC19A13ULL, 
            0x0F4770831BB440CDULL, 0x2D81D7530DAD3A52ULL, 0xBC4EAE4F86AEBD00ULL, 0xBDDD66254B950E5BULL, 
            0x8B01F301BF5E651CULL, 0xB7AF30C0C2E02B66ULL, 0x3C71C4C8268485D1ULL, 0x1FBD025625D1A1F2ULL, 
            0x07D020C16C5E28F1ULL, 0xACCB5B68D38B052BULL, 0x81BA1F71014B5C13ULL, 0xAC26DCE3DD0860E2ULL, 
            0xE61000E3827C5EA7ULL, 0x53E71E827F68AAB5ULL, 0xD382128133EA1909ULL, 0x69D40DE438EFE7F0ULL
        },
        {
            0x2BC067697242D96DULL, 0xDA8B21F0D3AC53C3ULL, 0xFC4F12583A65628BULL, 0xF52CDD304EA43D15ULL, 
            0xB5B2605739A14CDEULL, 0xAD6EE61F85B66937ULL, 0xEB2992E5506A96DCULL, 0x07B9B96057F11514ULL, 
            0xE2738A2881DEC0BDULL, 0x6CAC7BC89CFB4772ULL, 0x3FCEC5C0EEDD5F31ULL, 0x0580860E2152560CULL, 
            0xFBD74C35A6E0C454ULL, 0xEF423256CE277F2DULL, 0xC00DC913FEE7DD4CULL, 0x3CB7E8CB233B9222ULL, 
            0x4B2C371B06924F90ULL, 0x8F6A2E62DDD7D4BFULL, 0x7F22C44CD41D5514ULL, 0xA64D792F2B3615B0ULL, 
            0x8255EE74DDFE57E8ULL, 0xE49E3DAD51670381ULL, 0x9272E19018125091ULL, 0x3402686259789CFDULL, 
            0x89B810CD0545B140ULL, 0xD941D168CCAE62F5ULL, 0xC440C7AA95212C6FULL, 0x2CE81EDB0735FB6CULL, 
            0x9917D51F56D0FF26ULL, 0xBFE939086B4ACAC1ULL, 0x87AAB8EE2F5343FBULL, 0xEC2736BA60D76E13ULL
        }
    },
    {
        {
            0xA48E694D18122F9CULL, 0x9CEAB08FF41D8925ULL, 0x21B051DB43FF55ABULL, 0x7FBC26B9064AB351ULL, 
            0x296C351D0726F7EEULL, 0x4229EACCA72E801CULL, 0x1BC72C04303F86B1ULL, 0x5DA11E0396C53151ULL, 
            0x368E5D4596FA0382ULL, 0x5970023A705204A7ULL, 0x8013C6F75A9C631BULL, 0x14856CF6820019D8ULL, 
            0x359E6AA0C3A8F72EULL, 0xAACB027BBA741D1DULL, 0xADE67564DF2AA855ULL, 0x2753A463F67B7402ULL, 
            0x13901E2EC5D6F42CULL, 0x16F9EB1A165C2C37ULL, 0x1A5F64137E6C251AULL, 0x043B2E62D2B55B59ULL, 
            0x1152CCFDA54B678EULL, 0x4AB035C3C9EC6E9AULL, 0x3950DA4789629633ULL, 0xD76A7BCD612A21A9ULL, 
            0x76E29EF52D893852ULL, 0xDE21E394618669E5ULL, 0x0211C79A7ACC5A2AULL, 0xDF47187E2DEE5536ULL, 
            0x75B1AAFFE1EFEDFEULL, 0x4A7D05863E105245ULL, 0xA8C5B338371E9CE9ULL, 0x964F9A4C5C2EC981ULL
        },
        {
            0x2C5566C00EC50987ULL, 0xD4CE5701BB2FC86CULL, 0x481CF3E7AC437432ULL, 0x1E3EE84B415AC5A7ULL, 
            0xE642C76FF47985E0ULL, 0x3B12B062140B9C84ULL, 0x93ADB6B6C9C95654ULL, 0x8A34461AC33D839CULL, 
            0x45B4E167C5F4448EULL, 0xD3AC2CD08ACE8223ULL, 0xE366A048B888568EULL, 0x6D293065EDD2A4C4ULL, 
            0xA1E789DD62CDA85AULL, 0x4A48AFD1584B53CFULL, 0x7B91B7EF32BDA803ULL, 0xB840125C0923F59EULL, 
            0xA05BFD255E3600A9ULL, 0x067919D6008DEFABULL, 0xFA258B9D602D73E5ULL, 0x1406AE37594F6879ULL, 
            0x307B2B98D0CF1DA4ULL, 0x4866B9CD0CF55A16ULL, 0x530747D314014D82ULL, 0x04C92F89064D3019ULL, 
            0xF7F9426429333460ULL, 0x15F1B4C17C825E9DULL, 0xF7B6868CD9F7672DULL, 0x46493409FFFCB4E5ULL, 
            0x78C973BA95E254BFULL, 0x3BCB7390C6D64807ULL, 0x2D61B733E33E586EULL, 0x59E6745DA3E429B3ULL
        },
        {
            0x2E9B96FB8EBAF3FDULL, 0x40DA68F663765B09ULL, 0x2DB007F1A7370D45ULL, 0xDDC1C600F3ECD43EULL, 
            0x385168D0CAA92545ULL, 0x667B02DBB13C29D8ULL, 0x35C3C8480C169681ULL, 0x95BF290E0ECCD6ABULL, 
            0xAC476EAA19B8F0BFULL, 0xBF7A53C0569CB282ULL, 0xBAA85A6C5F5EF04BULL, 0x1B2272E000360160ULL, 
            0xC814CDC3F9DDB02AULL, 0x61D60621AEF486EAULL, 0x0AEFB84F79614F12ULL, 0xCB9E0863690C7AAEULL, 
            0xBB37147F5FF1B17EULL, 0x81284B6813E040B2ULL, 0x1E89DBBB06E74E7DULL, 0x97947479A5494EFAULL, 
            0x5724525DAA710D29ULL, 0x51A900042CE1AD3EULL, 0x62AD813289D753E4ULL, 0x8AE8DE61A96537FFULL, 
            0x562999F9B712A47EULL, 0x1414ED4F597548E7ULL, 0xC809848F62B9359FULL, 0x5D7E5788093FFA1AULL, 
            0x0EFCE4C321028E0EULL, 0xE91E0A3BDC34D4E2ULL, 0x6ED4148C572D1E91ULL, 0xEE321995C3A05293ULL
        },
        {
            0x7CC2FA446CAC968CULL, 0xB9CED3CAD67F8BDDULL, 0x9EED059EBBC87F70ULL, 0x1AE7C84FC737D07AULL, 
            0x5E907AFB60DD180EULL, 0x9421525139D1600AULL, 0xBAFB37F872290786ULL, 0xDA8A294C97E9F924ULL, 
            0x4F41225B959DDEAFULL, 0x69F280817E7CF80CULL, 0xFFDE4466C5C05596ULL, 0x1D73D21530F76A6EULL, 
            0x7E5B7C3E15AF6CEAULL, 0x7AF0CE13B05850F5ULL, 0x35880280A4724C5BULL, 0x143590D88EE91BA2ULL, 
            0x4AE5627F7C36EC0FULL, 0x050C8E8053A199D0ULL, 0x95F01F4C37532AB6ULL, 0x8CE6D31D89494A33ULL, 
            0x950DBB16CF1E9B73ULL, 0x7AFB777DD565D8B1ULL, 0x40B1D63C7F895404ULL, 0x3BEFD8F24F7FE803ULL, 
            0x72A5C952A93A26D9ULL, 0xC41EDB1BC03007D5ULL, 0xF31BD9BAE10FB5D1ULL, 0x811170C53FDAEF6CULL, 
            0xB9F091841529C760ULL, 0x5E0E64BD5F9BD3FCULL, 0xA9D0A3B04F33C7F8ULL, 0xC805EBAB28EEB2E5ULL
        },
        {
            0x7E94B124DF05BB98ULL, 0xEFC427569AE4D298ULL, 0xFEAE4C770692ECEFULL, 0x85CA97C735AEE621ULL, 
            0x12CBFBE948D01E91ULL, 0x102273E6790C13E9ULL, 0xF26C89CBD1915E68ULL, 0x51F3017BCD15FD8BULL, 
            0xCC2E279D2E612405ULL, 0x3CF3FE28743DC640ULL, 0xBADCB9B459E57236ULL, 0xC9CCADB1BF8FA475ULL, 
            0x163F9D00BD744900ULL, 0xEF61BAD296302F6FULL, 0xB0BACDF0AA05722EULL, 0x8C2293A63F154FBDULL, 
            0x5077B75351A5A290ULL, 0x82CFA8BD341AF8C0ULL, 0x73EE444E15C647BEULL, 0xDD12EF609C321199ULL, 
            0x77FBD872F1F06EC6ULL, 0xF7AEADE65C0EEE9FULL, 0x45FE8FE5B312E93EULL, 0x732CC8D5C7B19B6CULL, 
            0xA839424921331E5CULL, 0x499D44BB6C944E09ULL, 0xB5FEC4126B74CB23ULL, 0x913ACBB5E0407E13ULL, 
            0x2F5B8367AF149B4BULL, 0x29E288189980DA14ULL, 0xE555EC0AF791166CULL, 0xE9350B532C5366B2ULL
        },
        {
            0x5FCA7C8B140441F6ULL, 0xC4DF3B9004AB193DULL, 0x8491E7C13C56A78DULL, 0xECC55993B7F7C9D8ULL, 
            0xCFA8E116617FAD2FULL, 0x3734FFE275083434ULL, 0xC5CC13EF63F598C3ULL, 0x1C3234891101CFB2ULL, 
            0xF9B8A2DF289D38E8ULL, 0x2D6B2F60F36D03EDULL, 0x9BA13AB904B11A1AULL, 0x64D033DCE15C51FEULL, 
            0x99F1301C06E3537AULL, 0xFAAC281E933A8727ULL, 0x398BDA0915C3BF2CULL, 0xAFB2B7A688E482CBULL, 
            0xBA8973CF54C32D9BULL, 0x59472D5B27700068ULL, 0xC13FA26A7217B926ULL, 0x022A23E1F2C90F6DULL, 
            0xB10B73BEFDABF0A3ULL, 0x761B04838A4840E8ULL, 0x799DF248AB59249AULL, 0x3D701D63CE571090ULL, 
            0xEEDABB45CDD80013ULL, 0xDACBA6E6F728A88FULL, 0xA7189481DF6D0CDEULL, 0x0EE585534D3F15B7ULL, 
            0x9ECAED4F255D9625ULL, 0x71E33ABC689B4E25ULL, 0x71529B8934DAD398ULL, 0xAA68C2ED9B927D7FULL
        }
    },
    {
        {
            0x453A3C38699EE0A0ULL, 0xD189EE75FF4DDB0EULL, 0xD5A6CF022A0AF1F0ULL, 0x65C18843D8450688ULL, 
            0xE3A26E3ABC0EB836ULL, 0x0C5F7DFAE8419572ULL, 0xED6F847A2FF7F64EULL, 0xE8F9575340BEBF67ULL, 
            0x635106A22BC69071ULL, 0xF03C36F8FC526051ULL, 0xC6579DFDF16F551DULL, 0xA5EF34927F6BE52DULL, 
            0xA2FAB41DB0D367D2ULL, 0xDFC7A1596780B166ULL, 0xDA01D18CC83EFDAFULL, 0x3C28C88816AC37A1ULL, 
            0x016D5377BF170606ULL, 0x457E9CC84CF09869ULL, 0x8E6AAE94D9221E55ULL, 0xFB99B5E1296895A8ULL, 
            0x05BDCA956D906BDEULL, 0x887B550F7A11F1BBULL, 0xF92BB56DAE064CE9ULL, 0x0021116A164AE0A5ULL, 
            0x131D7C5F1B0146EFULL, 0xD6BA59D739410EF7ULL, 0x5A0C5EAB7FFBAFAFULL, 0xCB1DF2359512BFF0ULL, 
            0xF35C2335A08A66C0ULL, 0x6E6BB92E1B6BF7D9ULL, 0xA379B0AD6EADC0A1ULL, 0xBC8D29F2B415B460ULL
        },
        {
            0xC3180FE207A4A2E2ULL, 0x40501EFA1BA00641ULL, 0x1B5E63E5502D89ACULL, 0x44C954CD2E7CB30FULL, 
            0x44A6DBAE1760EB9BULL, 0x60C546C36A2CB52EULL, 0x5D246F9AA8B32F98ULL, 0x604F86BD569FBE08ULL, 
            0xAB4544108BBAEF20ULL, 0xABED626902C37092ULL, 0xA7B2EA5ACE8CFBCFULL, 0x4A6A73E4A434BEBFULL, 
            0xE55BAEA512FBCFA5ULL, 0x7DF551F162E0CFCBULL, 0xFD021FABD737B06EULL, 0xDDBFA7090BE27171ULL, 
            0x803F3FA028455019ULL, 0x1216F011EA5DAC21ULL, 0xED8D84F29E13BD32ULL, 0x67EBB7B6C8924276ULL, 
            0x3A93A8E5FE5CD187ULL, 0xC710ECEEE2DAF602ULL, 0x52DB6951D1F638F1ULL, 0x84EE205E8801B4B8ULL, 
            0xCE03CA8B1BFD501AULL, 0x092AFF27D05884B8ULL, 0x471624185AF725B6ULL, 0x37F030B00B3830C0ULL, 
            0xB303F42190EA75B9ULL, 0x586832B384A3C3F6ULL, 0xEDF0484F8D696164ULL, 0x99F4923B096A7E8BULL
        },
        {
            0xD451113A9FB271F7ULL, 0xC540839F02534596ULL, 0xFB139FE7FBC4AD2FULL, 0x1A11696AA2A97BEDULL, 
            0x35B72EDED14D86E3ULL, 0xDDEBB8FF3915B578ULL, 0x9CF3259A51DFC25EULL, 0xB7EDA4ABBB8AE9C0ULL, 
            0x07CF01BE54548C99ULL, 0x8F51961ADA036069ULL, 0xEA524CD09AAB949DULL, 0x244E730EAC4464D2ULL, 
            0xA85B236D99E7756AULL, 0xF71A32A751F79236ULL, 0x19098A01B9CB1995ULL, 0xC3AFBD0228AFDDC4ULL, 
            0x58F7C0DD999CB924ULL, 0x1315EBBDBC93532BULL, 0xD848B998D3EF94D3ULL, 0x0B033226B7F8BA98ULL, 
            0xF7887A51771303B6ULL, 0x0A172C3225F0B584ULL, 0x2F6B527770D86816ULL, 0x92043CCA7DA3A07FULL, 
            0x14F78E42D749CD10ULL, 0x9DD9D68EC94D6058ULL, 0xB5DF4CEEE0812C3DULL, 0x6F5B746C2968EE4BULL, 
            0xA4706A60209905D0ULL, 0x07AB02839C2B9E74ULL, 0x8C6D1A55F346EE5FULL, 0xEFD1A6B2ECA7A7B9ULL
        },
        {
            0x0F4D81908F1642F2ULL, 0xDDE7C9DE4A78D25DULL, 0x6C079699B3A0FFAFULL, 0x9AA832470F0DCA0FULL, 
            0x5164F4DF54F9015CULL, 0xEBA39E5088EFCDE3ULL, 0x946768116F875EA2ULL, 0x613641EFD4F9C5F6ULL, 
            0xB9EAFF7D1F92137AULL, 0xF1583975EE3F26E8ULL, 0xD5CCA0EE65DA3EABULL, 0x1413429E1D0E3B3BULL, 
            0xC5107A9E1B5AB19DULL, 0x1053A709C01B507AULL, 0xC1D355EF42AD989EULL, 0x7930703B88D061C9ULL, 
            0xDCFABBB85B04CE5DULL, 0x5D109D38D0A14F41ULL, 0x4986F5C9BBEE6B8DULL, 0xB3AC20DE9F887840ULL, 
            0x181C354043F6C3FCULL, 0x1CFB0E768D324BD3ULL, 0xF785F3C72BA7C672ULL, 0xCF765E9CC618925EULL, 
            0x9416F9B7C2252E3DULL, 0xA168C897F7D57808ULL, 0x7D7EC2576FDB6005ULL, 0x601B0FF77FBAE7F5ULL, 
            0x25B7A6FB112F673BULL, 0x3E64D2990CD13591ULL, 0x73CFD2A5065B84B7ULL, 0xC77F4937E197DDB8ULL
        },
        {
            0xF86D5F1541FB5877ULL, 0xFB4F18574F89DE4FULL, 0x26B00194AB7BEB08ULL, 0x63BF82E73368B44EULL, 
            0x81ED5AA6AA07C5DCULL, 0xD911B85F34DDAFB5ULL, 0x69E6DA1E1F926599ULL, 0x8561F2F9EFA9D0B0ULL, 
            0x1A94485AC7C6B718ULL, 0xDD7EABFA6B0E6BDCULL, 0x4C639E81E39A7695ULL, 0x0A2DFE9847BABCD5ULL, 
            0x4D693B2F33A0F620ULL, 0x7E87BBAB5C1A40E9ULL, 0xD709F78C753BD751ULL, 0x78527B79AF11ACE9ULL, 
            0xC6EC2D3D2856E570ULL, 0x7260857F02A217B2ULL, 0x8C7E26DA012C96D1ULL, 0x28A03A55E568E428ULL, 
            0xC9092D00623B0AABULL, 0x12D89ACE399D7FCEULL, 0x57F7EF3ABFC40346ULL, 0xA751CE0FC577B3B8ULL, 
            0xB733A010F008AC61ULL, 0x3F069710EB693EA4ULL, 0xC2C31CDD7D7FA924ULL, 0x89004198182D6741ULL, 
            0x3D8B66AC1D93CDF3ULL, 0x732CE606F48769FCULL, 0xCC7776651B5100D5ULL, 0x8CDF7663BD44AE97ULL
        },
        {
            0xCCCFAD4F49B9B28AULL, 0x9FB79F7A8AEA3B8AULL, 0x42D844AEF81DF6A7ULL, 0xDE15F396B81DD1CCULL, 
            0x1DC88B97CD9707EBULL, 0xC9C3090346D60C88ULL, 0x4361C11E2CFE2DE5ULL, 0x7841932E7AD6E895ULL, 
            0x2ECCA0D058491503ULL, 0xD3F27A59B84D6DE9ULL, 0xA45C82B181F03BB8ULL, 0x5765021648512D03ULL, 
            0xC1CD17D51D601C5FULL, 0x70A74EDEC55C79D8ULL, 0xBB42871273AAC31AULL, 0x1B0DB42FEC728AB9ULL, 
            0x153D5933C6C00C98ULL, 0x84AB71BC41A2835EULL, 0x96CD3AA2D4BB385AULL, 0x90A7EBFA36BEF70FULL, 
            0x6DE6246AD30720DFULL, 0xFB03540DC962027DULL, 0x3D81D411B0DBD64CULL, 0x55F7BE26B609E226ULL, 
            0xE837743154B79116ULL, 0xB1451355200E49B4ULL, 0x8EF5037A7620C55AULL, 0xF71E1DEB9DEC30B6ULL, 
            0x2A99798A72F835D2ULL, 0x6A47884F7D00ADA0ULL, 0xC04B89DE0C31AA6DULL, 0x0EEAC544712C3CD6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseDConstants = {
    0xDC6F67FE36501D5EULL,
    0xF8D6CECA80ED8568ULL,
    0x4D95775618ED8230ULL,
    0xDC6F67FE36501D5EULL,
    0xF8D6CECA80ED8568ULL,
    0x4D95775618ED8230ULL,
    0x6ABA70D67C7AE56BULL,
    0xA0A49950F477C0C0ULL,
    0x71,
    0x08,
    0xD6,
    0x09,
    0xBA,
    0x88,
    0x4D,
    0x9D
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseESalts = {
    {
        {
            0x724FD8263E1BFFB5ULL, 0x96042905391232CCULL, 0x090FD71AF36447B4ULL, 0xF16CE5F88CD2570AULL, 
            0x911E68F93DE3F8CEULL, 0xCFBB42AAC7022606ULL, 0x7D62BF93B0EC0589ULL, 0xF06F17FAED22FAA4ULL, 
            0x96ACEA866769A3D4ULL, 0x69FEDFB22FCF90B3ULL, 0xD8EC7BCB71EBADBCULL, 0x09747BD0DB804C72ULL, 
            0x45BB62D39FFF24DCULL, 0xF14CCBEECEA53EC3ULL, 0x075EEB1F74AADD74ULL, 0x3AEE45A543585E34ULL, 
            0x461D28C3937EFC67ULL, 0x83D9FBA977E2CE53ULL, 0x5F98FED8CCB8B535ULL, 0x37CC01C391634BF3ULL, 
            0xE67DC6C170D6FFFDULL, 0x84C62DF51DE5E467ULL, 0xA46953F89DB084A4ULL, 0xFF145EA5B152908CULL, 
            0x85E97D1347C140F8ULL, 0x06F065C51EE30363ULL, 0xA4BC94EC689E4B7DULL, 0xABC793BFED085185ULL, 
            0x201AF184F2E26E01ULL, 0x19FD3EB2EDF7F0F3ULL, 0x61B424F94CC40625ULL, 0x46309879159859F7ULL
        },
        {
            0x4533278C18009E76ULL, 0x6548E4FDAEED13CAULL, 0xEFF101FA4A6674E7ULL, 0x904D472FE2F9736AULL, 
            0xD5627D946ABD9D3FULL, 0x1CE99EFB5FD09446ULL, 0xF1EA76348DC941A2ULL, 0x6E52AF7E3694A934ULL, 
            0x4641D3E5956F33E8ULL, 0xA588756615CC58EBULL, 0x224439F2496CB424ULL, 0x2BDB7066267F065CULL, 
            0x0A773CF076778F72ULL, 0x4D7BA47D43A5A333ULL, 0x155C61690B83AA7EULL, 0x26950D0E31311B8EULL, 
            0x162F9713CD1B4F53ULL, 0xC053209914A0BBA8ULL, 0xFDDBFF7FA55F5533ULL, 0x180E7DD66CEB263AULL, 
            0x1B8102C57FAC7D0CULL, 0x7C074422842CADC3ULL, 0xEC1046B0E2004E68ULL, 0x48E94BE5A7465770ULL, 
            0x0E0932A10C8EEEB9ULL, 0x719E23B5AF8CBE8BULL, 0xE5ADF97E12390B4EULL, 0x9CA74FDCE75C8926ULL, 
            0x53B123360955FB6FULL, 0xC560472114FABCD9ULL, 0xA113C8C8FF807941ULL, 0x695C93D38B5947E8ULL
        },
        {
            0xBF5CD0230A2F974DULL, 0xBDD3403D87AD69AAULL, 0xC33C103C6B4D81C2ULL, 0xBB96CC590295B493ULL, 
            0x41117FB1C337C169ULL, 0xB7F1E411014956BCULL, 0xB6FE83AF47F39EFEULL, 0xDE6AA03C85785C99ULL, 
            0x5987827DBD4E96C2ULL, 0x1035C9852BCB3272ULL, 0xF1A45551099454ADULL, 0x213E6458588E128DULL, 
            0xF616BE0AA04E404AULL, 0x30DF37E923BD3FD7ULL, 0x74B7B5360AA38170ULL, 0x0AB4D83BE1206B87ULL, 
            0xB2F98D21B864F436ULL, 0x7C2E5AB6D1660501ULL, 0xB947E065BF5685E8ULL, 0x5E43DB03076B2D30ULL, 
            0x2E0B8BB0DF0F6AAFULL, 0xE42CD326EEBFDEFCULL, 0x0D33D0F1B324FE37ULL, 0x92A9EC689C1A7051ULL, 
            0x170E25BEEA6DFC44ULL, 0x2A4BC8833E853BEFULL, 0x2EDFA49BD5ADF57CULL, 0xD8C35D64ED923BDAULL, 
            0x43AE3503789B4F39ULL, 0x895ABFFD96457C14ULL, 0x30B84543D0938992ULL, 0x69333F8A14833884ULL
        },
        {
            0x1ADB5359DFDAF5F8ULL, 0x93B2165DD317458EULL, 0x381FE3BD4F325962ULL, 0x27A5262D1F47A2E3ULL, 
            0x32622616783C9EC3ULL, 0x880708C1EEFB0F11ULL, 0x2B612F94C5FCF485ULL, 0x9A3F5B3CCD31653AULL, 
            0x4D6FF82F6AD990D6ULL, 0x3EA4D57A2A47E358ULL, 0x7A773E6C45A3A4C9ULL, 0x83AE4B29063F25C2ULL, 
            0xEDC4A078F7F9E0DFULL, 0x36C5E74C07F1A711ULL, 0xBAC922D1E499EEF7ULL, 0x58C1399D1A0026E2ULL, 
            0x9E97CC472FE08A91ULL, 0x2E2B3B603A08542BULL, 0xEF7139B3FD155AE7ULL, 0xCEF6DD202DC438D5ULL, 
            0x91D404A96C62E951ULL, 0x447C70407542DA90ULL, 0xD38141C49BAF08BEULL, 0xBFBF0F3DE931CC57ULL, 
            0xC7C0638B37EE0BF9ULL, 0x8372077584C60F2DULL, 0x5891716A3634B89AULL, 0x86202674A3297C00ULL, 
            0x34D776AD5239A7AEULL, 0x5B6050180A8C20DFULL, 0xBDAB3B9355AFA483ULL, 0xD4344C488892B90AULL
        },
        {
            0x1FDBFB1730B99695ULL, 0x7188BA4F7E8A5418ULL, 0xCCBE1036F054A2C6ULL, 0x8312E3F0A7EDCB5AULL, 
            0x44A299F5ACA6E84BULL, 0x640042CA005004D0ULL, 0x12795AFA6BB795A5ULL, 0xABCB3CB1F5E0C755ULL, 
            0x4A122F108A124314ULL, 0x20F59609645E63D6ULL, 0x3E9E2BB0687EADBFULL, 0x4FD0344BD2DEACD5ULL, 
            0xA084F3685AEA1B13ULL, 0x423892673AA5DADFULL, 0x861C39FD0C2BFE6EULL, 0x4D08716EC089B27EULL, 
            0xDFB5D9EF3F51107DULL, 0xDB2DA016E184F715ULL, 0xBED69C8AD8DF3D84ULL, 0xC87E372257802464ULL, 
            0x6EC8B27F4DC42F24ULL, 0xC8463D84DE1DF754ULL, 0xA44553E8A017C436ULL, 0x9D303683C6697C4FULL, 
            0xD8F67CD6F8020DABULL, 0x54B97F5A88265521ULL, 0x0F87DACE8F6C6EF5ULL, 0xD35ED873593155E6ULL, 
            0xABB29873DD4E2727ULL, 0xFA330D86E7ACD392ULL, 0xC47495DD290994D3ULL, 0x5103AD4BAEDED556ULL
        },
        {
            0x64373B2F76F0C0FAULL, 0x0B7CF157D009C091ULL, 0xF27E27D64F898E06ULL, 0xBCE29C5FFB4D201BULL, 
            0xF8F883ECA8E35767ULL, 0x3875566D2F9414AEULL, 0x397967126E277612ULL, 0x8D4E3EF950C460D7ULL, 
            0x7C1EBFDDCFBF00AFULL, 0x70BA3BB89C362DA1ULL, 0x6A128323698546B1ULL, 0x3E3A1A00396D0172ULL, 
            0x175A5252B606F6BCULL, 0x85C9B95EA447D5E0ULL, 0x790E06DC5975489EULL, 0xFB756949957E6D4BULL, 
            0x1543E96B9BFCEEA3ULL, 0x2862CE9E8D9BF7BAULL, 0xCF6A75D9954AE4ECULL, 0xF033BC031882B5A1ULL, 
            0xB2C61754221011BCULL, 0xCF107287121E05FAULL, 0x7B6FCDD963AED730ULL, 0x80866B711622339EULL, 
            0xCBECD08FC9D7EE76ULL, 0x06E96A044CEA9B28ULL, 0x78EA72D0D2A61743ULL, 0x104BA86A676844F1ULL, 
            0x0AA533C06DCF28D0ULL, 0xAD7338A8C0231524ULL, 0x3C67F245927A59E3ULL, 0xD915E63776B637CAULL
        }
    },
    {
        {
            0xF937B71637B69BA7ULL, 0x39124A12691A2602ULL, 0xF50F90C2F0513B51ULL, 0x3388769DA3B07339ULL, 
            0x5B9DD51732B5BD73ULL, 0x9CB461966481EDC4ULL, 0x20133CAE96CAE735ULL, 0xB6CB5E2E03FC3922ULL, 
            0xFDE289F5CF3156A6ULL, 0xCF9D7CC23CA731DEULL, 0x59861B077758FB22ULL, 0x33697506F3D4584CULL, 
            0xFB6D979F7671B2B3ULL, 0x479CC031676B7089ULL, 0x97DD9DF57FBA6AFBULL, 0xFEAABE1F0A419421ULL, 
            0x625CC84C37B2B0EFULL, 0xB6F1D39080619C5FULL, 0x99588FBD5599D84FULL, 0x9D72510012F22C86ULL, 
            0x533A687B81947F9EULL, 0x06132035599C365EULL, 0xAE978FF8F378FF10ULL, 0xEF8699C8783E4BE2ULL, 
            0xA9D352FD40D16116ULL, 0x8E8ECC7C43FB73BDULL, 0x7296D4D8AC07F622ULL, 0xD75BC779EE2FE702ULL, 
            0x96DE1EE605C913D8ULL, 0x650E8E31F836254FULL, 0xD9FAD916ED560ABFULL, 0x730F4974FDA7DE3CULL
        },
        {
            0x60A1F7C9621771CDULL, 0x16F73C4C430F9926ULL, 0xA94BD010095E1529ULL, 0xFCCEB2CAE64B97B9ULL, 
            0x55B0E670856D59ACULL, 0xF86AEA1172692C23ULL, 0x7668B44DE3D3BA98ULL, 0x93A67603DBA9DC8BULL, 
            0xE87A9F18895D0EA7ULL, 0x72E1B316C063A6D7ULL, 0x4573D3E5AA0A3AF7ULL, 0x7DEE2A182374748CULL, 
            0x855F4C9E99F0FD93ULL, 0xDF9CC43FF40C33ADULL, 0x398C7134819139EDULL, 0x6C788831833B3563ULL, 
            0xFC95437813CDAE3FULL, 0xFE034FE4AD2CE7A3ULL, 0x8CC238BB286CAE71ULL, 0x15158A02A536E80BULL, 
            0x256DC52FE9553F72ULL, 0x3C98657C3807F13AULL, 0xAF4E566A0E1FBFCEULL, 0xADA3C51961B5D177ULL, 
            0x92C44A33E4D10C6CULL, 0x85EEA091F87F94DAULL, 0x85933501C9CDFA0DULL, 0xED39EB0C53E55FD7ULL, 
            0x0BD58CB8BC1787B6ULL, 0x9D3CFC4432325105ULL, 0x10041BED89D0D8A8ULL, 0x22D0F95F88B2265AULL
        },
        {
            0x1A0CE6B92AEDF4D3ULL, 0x1824816FA8151D1EULL, 0x69EA4E2C33E8D137ULL, 0x1DD58D25B6A29AD8ULL, 
            0x5B5163B740EEE52CULL, 0x88437E871E5A8971ULL, 0x06EE6E9458074693ULL, 0xC6EDC8F13CA0AEDEULL, 
            0xD6E5C965C037E89DULL, 0x874316AEFCF58FF9ULL, 0xA92BACF2FB3ADC5CULL, 0x114274035DAE93B0ULL, 
            0x5FC43416E488B71EULL, 0x1BC7B94FB5B26EDCULL, 0x3134C233F8EDFC29ULL, 0xBD2073773B400470ULL, 
            0x2B1A95A7D5322A58ULL, 0x3D8EDD8B4A8FC709ULL, 0x6457EFF6C5C595CEULL, 0x1CF29300AD094B42ULL, 
            0x6A6170822BF55C89ULL, 0xD9B240303E725E19ULL, 0xF141207217CD4353ULL, 0x491E1B37DEDCDC4BULL, 
            0xA116145C10BEB0FAULL, 0xB5FD87A9D51DB6FAULL, 0xCA0CA10E91440D43ULL, 0x383ECDAEA7068A59ULL, 
            0xE51DB2926DFC4A7FULL, 0xC954363BB437C560ULL, 0xF2BE53697692DDF3ULL, 0x789DF271C5B0E733ULL
        },
        {
            0xC3C02B3A9C6EE386ULL, 0x9A2182B61EE7CE8FULL, 0x52D5A125D44E6CDDULL, 0xA43C820167D39946ULL, 
            0xE5FE2168519DF2BCULL, 0x0BCCC7AC4FDAB044ULL, 0x5FA844F1C7B55413ULL, 0x1C36CB9EE5FDF53EULL, 
            0x076BD1672274BA88ULL, 0x0EFCCFE2ED263B22ULL, 0xC44AAD7269A892AEULL, 0x2322F34F63A35217ULL, 
            0xB857039DCF113823ULL, 0xEFABFB66BBF85FE6ULL, 0xF9D809E3F4944260ULL, 0x5D6EC63D14929573ULL, 
            0xE06DDE0640CA667AULL, 0xF442EFF4A43A15DFULL, 0x0FE764E510230566ULL, 0x78D201141C74DD65ULL, 
            0xE9D1FD0EA8C801CDULL, 0x6C817ADE8FE2E023ULL, 0x7E5E3A1EB282681DULL, 0x13998F09BCF2DF7CULL, 
            0x9F334D5A2890B1CEULL, 0x0EBC1C3B10008707ULL, 0x638535E7A4E877D9ULL, 0x5732C7E493EF97E4ULL, 
            0x91FCC065946DBA3CULL, 0x87095BC1473F38B8ULL, 0xE394D7AA5788302BULL, 0xF84BF9617CDBE090ULL
        },
        {
            0x309DEBB2320086D3ULL, 0x9CCCE19FCFB239DBULL, 0xECA888CE4A04D505ULL, 0xA584E9C3DB29348EULL, 
            0xBA5FD95A5F83B04AULL, 0x43201C05F4157219ULL, 0xB3DC8F6002D1A6AFULL, 0xC6B16811BE2E56EAULL, 
            0xFEE9250F3F9D401FULL, 0xCEE7139F71D355C1ULL, 0xA7B2F72AD5EEE9C0ULL, 0x80B18345137C613AULL, 
            0x0DB86A883F592500ULL, 0x9A2E7277575A7244ULL, 0x74C3A63A2DE07921ULL, 0xF9C22AC5A3FA1AC5ULL, 
            0xA29AACC410BFE17BULL, 0x6CA03744898B8C55ULL, 0x45CAD1B03744B38FULL, 0x2F26EA0D8DFD2CD1ULL, 
            0x74DE385AC1D85979ULL, 0x0AFA9D48FB9E9C77ULL, 0x649002994C4ECEF4ULL, 0x04E5C2242553B02BULL, 
            0x9E64828A74BEE98DULL, 0x0980D39D256E2614ULL, 0xBA097F98FF6F1921ULL, 0x631BFBA4E223C9FDULL, 
            0x1B11857B4F1B1E48ULL, 0x705C6C28E860C88DULL, 0x9376327769EDB1D4ULL, 0x290D8F7482FDB9A2ULL
        },
        {
            0xB2C8764CE09E8FE2ULL, 0x6B6D057E7CF35143ULL, 0x6D8D685C616D9A2CULL, 0xF318A7F3868DE151ULL, 
            0x5D36114AA6225168ULL, 0x7493CB45C81926C0ULL, 0xECFDD4AC64435AA8ULL, 0x07B2F73E0D3AF3A1ULL, 
            0xBC0E93CCC1A95962ULL, 0xE1971BA4F3E40A9FULL, 0x55944B42C60B5E63ULL, 0x196A0419D99B8A7CULL, 
            0x1F81C9BB3D1C2007ULL, 0x5B9F3684C9748A1DULL, 0x73E2F4BD08D124C6ULL, 0xF296DAB2903EB774ULL, 
            0xEF343EF69282A196ULL, 0x646E10FEAFB281B5ULL, 0xBD9DD1E9E3937434ULL, 0xA58BAD40BA49D22AULL, 
            0xAE02526EE7370F60ULL, 0x8BCD59630C6BEBABULL, 0x000445215CD2E366ULL, 0x9172C159443C4B6FULL, 
            0x64DA8F4E3FBC9D94ULL, 0x8371B47CE55A77C2ULL, 0x69378D3CE9B44481ULL, 0xD3CC57C39ECFF58EULL, 
            0xE827BF569D3829C9ULL, 0x3421E1F2BE0C334CULL, 0x4069281A1C6962E8ULL, 0xD944E44E5CEE8334ULL
        }
    },
    {
        {
            0x51E75987B711A512ULL, 0x95BFF4067AC17A4BULL, 0x713B18227F276C15ULL, 0xC723F78BBFC30B63ULL, 
            0x7C36A7658446A811ULL, 0x0E8282064617A718ULL, 0x8D035315D2017A36ULL, 0x20CE6AFF869BAE18ULL, 
            0x8FD2B702ADB6B5C7ULL, 0xE462EED0502E2191ULL, 0x681895B08FF83790ULL, 0x97FD79ED9F7640F0ULL, 
            0x2FFB15BA958156DFULL, 0xC55E72A74F7A3895ULL, 0xB47ED96234F17289ULL, 0x71670FC210BC1408ULL, 
            0x809A57EC1FFE2E49ULL, 0xFE70218343987157ULL, 0x47F884EED6873F54ULL, 0x58ED20394E68AA99ULL, 
            0xBFAB69D6A90263BCULL, 0x76DB686A67E1FBE5ULL, 0xAEB7DD8DE6D8AE34ULL, 0xC9B3B203E05DF713ULL, 
            0x8ABA6E03B1F2D23AULL, 0xACD6559850551089ULL, 0x1D3C0EF6775A8743ULL, 0x6F8994AC15CBAB39ULL, 
            0xFDC81CCEC93AA7D5ULL, 0x61CD4BF1BEADE35DULL, 0x1C3B66CFE757382CULL, 0x1DC3B4BE29777955ULL
        },
        {
            0xCFADA0260218BAC3ULL, 0x2954379B4741CBB2ULL, 0x08D95E71C06E9C8CULL, 0x54873C15FDAA3633ULL, 
            0x54A8515606B0DF43ULL, 0x8677DBDF1A128267ULL, 0xE77242CBD5E4FE7EULL, 0x08E26177FB8EABE1ULL, 
            0xCCF4EE28CC1BF7DCULL, 0x0E8AA59849503539ULL, 0xB41E7005A0A59492ULL, 0x44F48F3E77340D47ULL, 
            0x2BA77B1A258E4F45ULL, 0xB6FDA5AB130B62F7ULL, 0x649EE56FF4F7EB8EULL, 0x46E09D9C5BE68396ULL, 
            0x0ACC34503544BE78ULL, 0x3420FCCFC078BDF0ULL, 0x773AAFF9330AF57CULL, 0xB140C22DCAA9CA4DULL, 
            0x2D13728C9E8DBC43ULL, 0x3CA1AAFE0242B723ULL, 0x98B77950A631427DULL, 0x47054971618BC10BULL, 
            0x08D3D362D59922ECULL, 0x1DF227FDE8386FEAULL, 0x364D70272F4D5253ULL, 0x0F4B45CA30BD7175ULL, 
            0x792B8D31F275C8EDULL, 0xC9D818E746215CA0ULL, 0x2A2588D2ABF458C9ULL, 0x4C986290528F7485ULL
        },
        {
            0x3AECDD4A2EFA5633ULL, 0x628EB477761BC898ULL, 0x0D2DEF579905B3A2ULL, 0xEB3D774EA31C6EFDULL, 
            0x854C31F76B01407DULL, 0x93C0A752758DCD40ULL, 0x5168E5FCC66F0B96ULL, 0xF57ECEAF1DCFC9E5ULL, 
            0xFB07F1C5EA3C9975ULL, 0xA7FBD7BEBCB465D2ULL, 0xDB8AAE568B27BD77ULL, 0x683F2DA0DEE3CE7EULL, 
            0x5C78266DD97E784AULL, 0x905C25B8E0C896C5ULL, 0xF8D3E68118773E66ULL, 0x5C0AA3FA8588C34DULL, 
            0x4D7F522984D1F71CULL, 0x340F1DDA2A39829AULL, 0x8FA7C998E371D11EULL, 0x1FC8C8ED10174936ULL, 
            0x5B6516BD30E5AD7EULL, 0x3904E064C87DA626ULL, 0x2643C6BC7885E8DCULL, 0x5114D256E2895E5DULL, 
            0x230E23C01FE67B41ULL, 0x6BDF1C3D1809AA83ULL, 0x2703933D747CE44AULL, 0x8B197387B1CA9054ULL, 
            0xA72C97D6FF10889EULL, 0x897216726293C926ULL, 0x293A9C6790F5D674ULL, 0xBFA2FB4241C11EDBULL
        },
        {
            0x4BBD7D5BC8F9CAB4ULL, 0x740FCC35FE2BE150ULL, 0x23F2FDDCC5623C63ULL, 0xDF4F4BC27ABEF4F3ULL, 
            0xE80DCBB449DFB071ULL, 0xA4B950C74C065A70ULL, 0x79E40928C2A8832AULL, 0xCEDB6BBAA0F31F57ULL, 
            0xE9B3700ADBFAD14DULL, 0x1EFAC86723FEEB0DULL, 0x69051E4E7862D40DULL, 0xE8CAEF3F1521A45BULL, 
            0xBF1185B4BD433EE6ULL, 0x98DD71D4643BE042ULL, 0x0708BA16B9CD9100ULL, 0x21420E4142823077ULL, 
            0xC9434A239BD4D57FULL, 0x8E494D0B62DA5B28ULL, 0x601C47B3C3A5C210ULL, 0x429843AFB9A4A56EULL, 
            0x258E905BA92960B4ULL, 0x10705ADB23A21401ULL, 0xD85C62F020E2796FULL, 0xE8B6F02F35185E10ULL, 
            0xA7648B37F44E1EDBULL, 0x868C05F4C7B0A52CULL, 0xE1A4DF6F68C9052FULL, 0x43F4B12B4F074328ULL, 
            0x7D9C972AFE5397F8ULL, 0xDC7AE555346D156FULL, 0x888958DD189F4225ULL, 0xFEC5E5CEB63D8461ULL
        },
        {
            0x6571378FB165A9A5ULL, 0x4A744274351D8504ULL, 0x2DA3CDE96BACDF70ULL, 0x841A61CA687739CFULL, 
            0xC8C352D0A967C8C8ULL, 0xB2472FCF04833EBBULL, 0x593DAE0081534F68ULL, 0x9FD637FC37F2C072ULL, 
            0xF8155F39B8025F9FULL, 0x59FB40DEECC76DF7ULL, 0x9EF31FC341D2B5BBULL, 0xA874BCEDC90E041FULL, 
            0xBBFF52310374F1A7ULL, 0x19E68007DCA1F989ULL, 0xDC6DA2786CCB0FAEULL, 0x83DC25B974DC58DDULL, 
            0x014E51E1C954ABF6ULL, 0xD69B930639415F01ULL, 0x9C62056153A3317DULL, 0xB489D8193407DA8DULL, 
            0xAD4A680027C91AA8ULL, 0x5AA25495DD6007DFULL, 0x38B25230D5A4FC28ULL, 0x6A2BC78C49E274E6ULL, 
            0x4B37EEB814472F88ULL, 0x3D2473563B54BA78ULL, 0x4EB5706BE7F10994ULL, 0xAB54B3C23647BEF7ULL, 
            0xA83C868BB9CD6237ULL, 0x973871AD9B3BD9B9ULL, 0x23A7A006AA883589ULL, 0xE1CAB8A504CC960DULL
        },
        {
            0x6D862BB9F865B619ULL, 0x43A532379C5622EAULL, 0x1F5C5F0722450486ULL, 0x1D8FCC5BC88A3656ULL, 
            0xAF912450A4582478ULL, 0x4E238E218F423297ULL, 0xE3FED382D0995DE9ULL, 0x1C464BB76D05918EULL, 
            0xAB3AA725053677F3ULL, 0xF638D0B6EE561E09ULL, 0xAD85763BB42F096EULL, 0x3B2AE5F886FA3398ULL, 
            0x3CF31DBA6FB4B825ULL, 0x291FC2ABBCE24403ULL, 0xA3FBE018104DCA2FULL, 0x5CDE9C946D1DB44EULL, 
            0xC096F657B3DE79E0ULL, 0xDB41A6475787181DULL, 0xFF8F26094D25AB59ULL, 0x3C22DC69AB2767FEULL, 
            0xDD265B49E9B4021CULL, 0xF314065F93BAE998ULL, 0x4A58F2CA97836BE6ULL, 0x59ECE4427E17384CULL, 
            0x2F4801418EA4793BULL, 0xE1CECC4E2395ED75ULL, 0x36CD55D8F5ADB7FAULL, 0x2E0A6EA124A1B139ULL, 
            0x00E84EC78A78CDEBULL, 0xCC8461F674D35ECCULL, 0xD24D9FCA2BAA07ABULL, 0x19CDF35D4AE612E5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseEConstants = {
    0x405B6E2102FC0790ULL,
    0x15D6567869A31129ULL,
    0x2177878C7DCC59C6ULL,
    0x405B6E2102FC0790ULL,
    0x15D6567869A31129ULL,
    0x2177878C7DCC59C6ULL,
    0xD26C1806FF58DD91ULL,
    0x1449A650BB4D0772ULL,
    0x85,
    0x05,
    0x50,
    0xEB,
    0x40,
    0xFE,
    0x33,
    0x83
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseFSalts = {
    {
        {
            0x8E55161754016B22ULL, 0x4DA71D6E2AAB3A74ULL, 0xAEEEE9F3739DDE89ULL, 0x9F7E503B5F040C8CULL, 
            0xF75AF8A3B2D9508AULL, 0x8BAE8811B5437A89ULL, 0xE226991CAA0B11D3ULL, 0x4CF5B0C3DE50CBF6ULL, 
            0xD640A0B67C9FC560ULL, 0xE45D03CB2F75DA1FULL, 0x2B26200D030EFBC3ULL, 0x9E67742479EC9146ULL, 
            0x526B7BDA3BCB2DEAULL, 0xB4355EE290528F60ULL, 0xE4D2DFCF72F285E2ULL, 0xD12B13D11884E876ULL, 
            0xDE6360445711AD9AULL, 0x2603C7720AEDFE4BULL, 0xB8C182FA6A5DACB4ULL, 0x366C76161CD05872ULL, 
            0x9B2DF71CC622637DULL, 0xFB076F8C2B7EBA8DULL, 0x9119899652EFF62BULL, 0xFB045D67414AB318ULL, 
            0xF0D065620D8F63A5ULL, 0xEB0EF75D805AB8E0ULL, 0x8AB0C36B8A328AF5ULL, 0x099CFB51BB9708C7ULL, 
            0x7D45FE38E70C47D7ULL, 0x63F40DC00CEE659EULL, 0x299B1038618BE09FULL, 0x63D1ECA1F5B77027ULL
        },
        {
            0xEC884AB18185B26AULL, 0xD2F13F119978C2D1ULL, 0xA4D5E9A4F2270D06ULL, 0x41B5796DE9D15411ULL, 
            0xA28CE990FF50FA90ULL, 0x0B9CAA7608DEDF6DULL, 0x1386D85A16ED0FAEULL, 0xDE55586F4D6F176FULL, 
            0x501EA3B5892AB5C0ULL, 0x7A354D031B20BBFDULL, 0x1B17D5E2DCA41F6CULL, 0x1B67BB2EBDD1DCBEULL, 
            0xDF2438822B85D2E4ULL, 0x4069FC80598EBFA2ULL, 0xD99C9BF7B9C19ED5ULL, 0x0F8881C7209D9023ULL, 
            0xB768C8DFBA2113A5ULL, 0xC7EEADAA7551C108ULL, 0xAB3298106448E329ULL, 0x55D404BF753EAA76ULL, 
            0xBC86AA3F8499A734ULL, 0xC4955AD1B0A00751ULL, 0xD03C8C8C6663A7FCULL, 0x3C652BA5F7CEDA27ULL, 
            0x2F31A50ABA160D54ULL, 0x0DF168F93D133523ULL, 0x44BD72664DE80E89ULL, 0x306F7C0AD04BC99BULL, 
            0xE2D4314296C8E08EULL, 0x4CAC131844CCA698ULL, 0xFAF4BCC3FC126345ULL, 0x4810803E50CA0D1EULL
        },
        {
            0x779EF2797F734748ULL, 0x5C378CCD50A82EC9ULL, 0x0ECEE5BBEEEEA65BULL, 0x30CB4389FC513653ULL, 
            0xD82FD3DE8C000FAEULL, 0x8DCB0B7FCE2F2B33ULL, 0x269FC417B6B86000ULL, 0x6EC4372FAC833E2BULL, 
            0xF1F46AF6DE986ACCULL, 0x6219CA0B81E31922ULL, 0xC154E8C4A22B9641ULL, 0xB046CFB7940080B1ULL, 
            0x24156FA5A589E18BULL, 0x0D9F0FA517F4FF50ULL, 0xA1548F32FC754BF6ULL, 0x4C70EBFA7F5408BFULL, 
            0x87E161F8826E547FULL, 0x6ADE2B6845F5BD16ULL, 0x8CA98412E9512A6BULL, 0xAB9FF977036C2E3EULL, 
            0xDDD7F458A27603A5ULL, 0x101F385AF28C4B22ULL, 0xD1ED748A08E80A46ULL, 0x04034DE77E325DA3ULL, 
            0x3E9496C179710338ULL, 0x5E1220318B4F6CADULL, 0xEA0620C184E61741ULL, 0x088A3E3B79A0FA42ULL, 
            0x033F5E7705252DB4ULL, 0x8FB3F867688E108EULL, 0x27D225394DA7313AULL, 0x1A25EB1F95E0A473ULL
        },
        {
            0xEE483AFCD6F64C3BULL, 0xEF1083B76A49D730ULL, 0xD539CAD9CD0F3A11ULL, 0x6BD85892E2A156ABULL, 
            0x65EC371DB812F87AULL, 0xF8D4136E53FB2A1BULL, 0x0B3A87A83CAE228CULL, 0xA53A19D898E076BBULL, 
            0x706131C3B49A039AULL, 0xF61A47008CD782ACULL, 0x585F3C6CB40C62D0ULL, 0x3C70E8BAC3844409ULL, 
            0x25667ACE4994BBDBULL, 0x745997C058904F17ULL, 0x58530EBD06B5F65AULL, 0x8E3BE4FED384FB4FULL, 
            0xF623D42036741068ULL, 0x8A571C4FEB75C892ULL, 0xFD58A2F6B3E4B4A7ULL, 0x24CDEB1E994A120FULL, 
            0x27251BBA7C6AF409ULL, 0x11D82976BC5BA4C4ULL, 0xC0BEE586085F776CULL, 0x16457AD65FB8CDF4ULL, 
            0x7146B5F009721B0EULL, 0x4952786020265047ULL, 0x7A28D95B30DD87E3ULL, 0x33F8A6C7036B8ABBULL, 
            0x6651C7DEB69C7323ULL, 0x4442B8BA79A2D6B1ULL, 0x695445335CA2FB6DULL, 0x3B9E5C82A27E2767ULL
        },
        {
            0xDC936B332B58BBEAULL, 0x1759755A073F52BCULL, 0x3281B93AC88B86CEULL, 0x26F80DB1AA1D50DBULL, 
            0xC08388BCD7391FF3ULL, 0x02696A9E7065BBEAULL, 0x686F8AE3D668B23CULL, 0xB2D372CC13ACEA15ULL, 
            0xBFD337E19BEF1B70ULL, 0xBC55F6BCBB57619DULL, 0x7EA4A6E5036E42C9ULL, 0xD77C23C70F294054ULL, 
            0x4F94BB0E3418BA53ULL, 0x03D9F684D6E83FBCULL, 0xF69690BF2A827972ULL, 0x099AF4D314EEDF70ULL, 
            0x9E7C57B54847DA3AULL, 0x471E784A8364C65EULL, 0xC3F7A7E6FB5CADE2ULL, 0x698EBD24A63C488BULL, 
            0x21678215E7AF9622ULL, 0x115615A418BFAD95ULL, 0x475D7CB9E1EB1EE0ULL, 0x7783E0EAB9104593ULL, 
            0x9E61421D9B7EF3EFULL, 0xBD0662D13684EEC8ULL, 0x49C56F3ED8B07ECBULL, 0xCA1BEEA4E4E22AE9ULL, 
            0x70CD24F7B5E9064EULL, 0x21534BA32CE15855ULL, 0xE2125E4675253A19ULL, 0x7C7AB7F8BC1ACE59ULL
        },
        {
            0x50126A0D60D0CCE3ULL, 0xF122CFBCA4C54624ULL, 0x7D6F8156B70E7A1DULL, 0x05ADD6D1BCD88C25ULL, 
            0x56DED379C0A77096ULL, 0x8D6121B14FC0D380ULL, 0x673B9C6ACD3993D9ULL, 0x5584BC330135D339ULL, 
            0x6A64E30008386CFAULL, 0x011AB82A85ECA1E8ULL, 0xEB97A1302266A797ULL, 0xAF0ADCEAEC7E434BULL, 
            0x06D648E45AF3151BULL, 0xBF37ECFE68096C81ULL, 0x7B83681582A56662ULL, 0x604E6DFD531734A0ULL, 
            0x2F54251302A00752ULL, 0xFBA57A58959BC345ULL, 0x3B1E09E8D8D3CE5BULL, 0x645C6DACD3AA40EFULL, 
            0xE051F2E921D0C98BULL, 0x44DF613939BBD750ULL, 0xC5633BEB2675D81AULL, 0x079C994559E15107ULL, 
            0xB12DCBDC7431D74BULL, 0xB1995F9834527321ULL, 0xFB26BE95C2DF644AULL, 0x68BE7F7B537ECDDFULL, 
            0x0ACF19872E19D683ULL, 0x9C0E3284A446784AULL, 0x5BE35256D17E2224ULL, 0x592777A6B695307AULL
        }
    },
    {
        {
            0x214C5C0B328AE778ULL, 0x7F2C3C480FB09BE9ULL, 0x96A566C25AB64F7BULL, 0x40DFE71D3C3F4688ULL, 
            0x7F0B9B37E978DCA0ULL, 0xB0B90CCC66E3234FULL, 0xCB4B39D080196B47ULL, 0x1CF249BA3AC8C5EDULL, 
            0x9681176E40A07894ULL, 0xE10CA8C2F2F0FC61ULL, 0x62587111592187ACULL, 0xDEFBBE8FA74403E8ULL, 
            0xA4C9085F3C74D19AULL, 0x343938B02841197FULL, 0x2E8B0B6FDDAF7C50ULL, 0x2B6CC658A158CF00ULL, 
            0x4A00FC5FD6233B09ULL, 0x489D65DEC15420F5ULL, 0x4A830935AE71E45AULL, 0x202EF2B378128E1BULL, 
            0xD658B050232F72B3ULL, 0xB91606AC8235DBDBULL, 0xCDFC1C83C0AA207EULL, 0xD14C55923D9C3EC7ULL, 
            0xD7C8209D71566838ULL, 0xD86E2F0FDCFE308EULL, 0x54EBAED97D79412CULL, 0xC59B4042EC399CFCULL, 
            0xC2E993C4B99AB010ULL, 0xF543C51CF83B26DFULL, 0x5E7833A14AB2A66CULL, 0x51E61335FB16C533ULL
        },
        {
            0x7347649C10E6CF97ULL, 0x93C1180161001977ULL, 0x9A7C4281280749F1ULL, 0x3F5940F56D26E807ULL, 
            0x886110D6893A5DEEULL, 0xE6C5349FF9762B0AULL, 0x26697DC083A0E84FULL, 0x953EF027BF843768ULL, 
            0x6378DFBF02456F6EULL, 0x2AFD48054B0FAF83ULL, 0x94A36905F155E89CULL, 0x4734FC1F6201F3A7ULL, 
            0xABF3CB06BF085503ULL, 0x90E984796D8DDA18ULL, 0xF05360A0D5842D92ULL, 0x249B0BE3EB2045B2ULL, 
            0xF3461786273F153EULL, 0x1C576133E18C5C11ULL, 0x78FDB45601B64542ULL, 0xF842138015280CC7ULL, 
            0xDB39861CCFA2995CULL, 0x91589455E92F0F24ULL, 0x169DFF200398AA2DULL, 0xDC70B17FC7C2FBE9ULL, 
            0x3FF3F7A5129069CAULL, 0x558188FBDD65E093ULL, 0xEEBA0C9C3E5FF353ULL, 0x40EBCD6420F7C4EEULL, 
            0xE6958A35E1DE314DULL, 0x73CD81568C5F64ABULL, 0x7A5923213D69AE6BULL, 0x9879726144ADDB46ULL
        },
        {
            0xFCF85A56ABC4C9B8ULL, 0x9A374C64CD6C904FULL, 0x13C9BA031CB68006ULL, 0x4EBFD9BEB304414EULL, 
            0xE7CD669F2D189A47ULL, 0x42A470E296B472A8ULL, 0x5960CA758D1D76E9ULL, 0x448ACDD9900DA563ULL, 
            0x0FFD1C351F15132FULL, 0xE493FF62ECDC147BULL, 0x2D5FA38293192372ULL, 0x65EDC8D68F22452FULL, 
            0x735243426A1377BFULL, 0x7A0B2D5640E52CE4ULL, 0x05121A9D900E0504ULL, 0xB4E449CDF5AA25E1ULL, 
            0x8A5B382870D048BCULL, 0x8D1A73D24BA96098ULL, 0xFC65C74C155185BAULL, 0x6CE4E9BF8F4BDE2BULL, 
            0x15223B3658707F18ULL, 0x818D22E77A482FD7ULL, 0xF2B3FB19574D599FULL, 0x8267CC3026508654ULL, 
            0xFFFABEA80906BD59ULL, 0x0D0691661F179AECULL, 0x2F0F5AAAE8923F15ULL, 0x7107F092FAEF7454ULL, 
            0x2CC6F6EF304D2DF3ULL, 0xA67FE047D0824CD0ULL, 0x3CABE581D9090401ULL, 0x62E11292C52B1B3DULL
        },
        {
            0x005687D9BF8C571FULL, 0xBA3A4A4FB8918342ULL, 0x2EC112FAC3A37D6DULL, 0x92769330DE7D7737ULL, 
            0xAED2423C2F7FD196ULL, 0x17FB4E3F5F2E63DBULL, 0x893A019C06C272BEULL, 0x46ECF27A19FEE478ULL, 
            0xA3CAE21EA82D3FF8ULL, 0x372CA71AA88417A1ULL, 0x5BABEBFA0F9EA41FULL, 0xE56C7584BD545770ULL, 
            0x29747F1B8EBB2609ULL, 0xED8A235DD930AF46ULL, 0x246ACABAA790426BULL, 0x22C313EB5EB6D8F3ULL, 
            0x9649A1125A7D80B7ULL, 0x7E51FDC4E9D6E6BDULL, 0xC8A7E4ACAD3CA697ULL, 0x7ED2AB7B1084C0C4ULL, 
            0xA187B7954A38B233ULL, 0xF7DFB15EA32C4E44ULL, 0x09D094A1E8672FFEULL, 0x318DD201A774D93AULL, 
            0x0FA2FA8A449872F0ULL, 0x5053B3ECD8F25326ULL, 0x7B546FEC73E260EBULL, 0xEAE9ACE3FF63E789ULL, 
            0xE85394E4F17CAD02ULL, 0xCDE5A255475AEA91ULL, 0x195F55B084CDC0F7ULL, 0xD30189B7E0EC851BULL
        },
        {
            0x22F62077E412D4ADULL, 0x418DECEFC599BC50ULL, 0x95F102FD69280F26ULL, 0x931A1BFFC01D8FD9ULL, 
            0xE05A6B35F2023046ULL, 0x14AEB385DC2E6C29ULL, 0x4BD7A4BB7244086CULL, 0xF6596A123920C0F9ULL, 
            0x29E8C10355FAEADDULL, 0x236035EE50E37847ULL, 0x56AD2D8ED8F5484BULL, 0xC9B5ACF15F78A09AULL, 
            0x63197822FC7B4591ULL, 0x56C0B5F24EFF7FC7ULL, 0xB3EA1392D7DB54CCULL, 0x1897A32169D261BEULL, 
            0x966469A2B6AACDFCULL, 0xD08EDE967BFB7ECBULL, 0xBAF4FB53D813992AULL, 0xCCD5BD50EBA68AB4ULL, 
            0xD947E8E65E8809EAULL, 0xA542108E78CE0688ULL, 0xBFE3F6781FF10B8FULL, 0x4A2757721371DDF9ULL, 
            0x090BC6E040BE1F7AULL, 0xF34E15EE85CE610AULL, 0x14DAA4AF8C2D153EULL, 0x44A69B6A42AE2931ULL, 
            0x981F3E69306D19A4ULL, 0x97A5DEBA25B71A78ULL, 0x729CAD5C39FFD8E0ULL, 0xA76467E699692475ULL
        },
        {
            0x48C554FC841A13C4ULL, 0xCF0FA2A85FEEA29DULL, 0x398AC9CCB4E637F7ULL, 0x677B019014F61169ULL, 
            0xC5D67A60BC63D6FCULL, 0xB1A3963A0B78155AULL, 0xA7495D1CBE095820ULL, 0x37CDE5B6FC48A573ULL, 
            0x8F4DF36D43E13B6FULL, 0xE3B95E13EBAEE77CULL, 0xDCFF1A8DAE76B09BULL, 0x28547A1C456C3E05ULL, 
            0x24C17980FB212B55ULL, 0x912754E695CF435BULL, 0x687726C8DBDD56BFULL, 0xF3978F1C20B2EC09ULL, 
            0x09943C09696F0A71ULL, 0x783623BE5D1F13B7ULL, 0x96889DE2D5658DA9ULL, 0x5741664E6E0CBC09ULL, 
            0xFC42410B872E0FEEULL, 0x84B72BE4991ACA95ULL, 0x5481E1049436208EULL, 0x62E71C8A83C2214AULL, 
            0xE30E22B9149BB64CULL, 0x326C66E29EC07472ULL, 0x80FA8CC909D09869ULL, 0x006AD407C6912E1DULL, 
            0xF52DD11F9B586723ULL, 0x62950CB3865A8DFDULL, 0x37A47A0A7A3311C6ULL, 0x0B9A2FFDFCC8A40BULL
        }
    },
    {
        {
            0xD92A23AEEF43CC39ULL, 0xECFC1FEBE16DB509ULL, 0xBC7A5CD371B41F08ULL, 0xDDFAA6A991E0A221ULL, 
            0xB51C4526208B9E7DULL, 0xDCE1AA8EA4F92D11ULL, 0xAC42A0282FC783A9ULL, 0x7586C31D25F4C5ACULL, 
            0x88771E77F3F95633ULL, 0xA176CE775A25C12AULL, 0x266E156800A1CD03ULL, 0x0F4E8594520E78D7ULL, 
            0xCD2700E480245AE4ULL, 0xDE99933D876B206FULL, 0x6DDAE373358D1EF5ULL, 0x41609F18C00D4F44ULL, 
            0x7150DD9A4BD321D4ULL, 0x237E317479D29584ULL, 0x3B588BB6B9764751ULL, 0x597FF8C52FCF2A7AULL, 
            0x9074B2F2FA0BC0C7ULL, 0xC5EBC3DE026B995AULL, 0x12BAD88D4F25E564ULL, 0xDB5C2EB10B9DB87BULL, 
            0x4195CCE85C46B2FBULL, 0xF1490380E12B365BULL, 0x2A7BE18343F2E2E6ULL, 0x270680928FAC0AB8ULL, 
            0x729C1D588BD36D14ULL, 0xFF343439A63D7C74ULL, 0xE0F5B73D1851455FULL, 0x55FF1CEC1FEB2308ULL
        },
        {
            0x7548D4F873C8E398ULL, 0x036EC06F6225DA55ULL, 0x0862B6B62E77BC9CULL, 0xCC854B9D0F88F5C2ULL, 
            0x6841B726D8B8DC1AULL, 0xEC29A36E46660B92ULL, 0x492AF1DAE3114168ULL, 0x97F06789EE7D8220ULL, 
            0xC77F7F603F1D0179ULL, 0x142DA17225E86228ULL, 0x7DDEC61300DEDFE6ULL, 0xC1F0022D9CB56DF0ULL, 
            0x9E0489E504D4FF3EULL, 0x1A9435A7A63F198FULL, 0x14F3292D4092174BULL, 0xA31E56B6DF7E7969ULL, 
            0xC900FE297DFF7379ULL, 0x7651A6EB0F537477ULL, 0x182FF9CB3CF4A886ULL, 0x8BC7E3687AF79479ULL, 
            0x69D2D8BC8A491A5EULL, 0x2818B69B4A3CB741ULL, 0x0FE97A5174CD3860ULL, 0x0BA42BBE328A2239ULL, 
            0x903F0D20BE850369ULL, 0x997C21BED51EBDA0ULL, 0x6D449F79F0AF238DULL, 0x09EF4B10869F04C7ULL, 
            0xD38499FA18013531ULL, 0xE383F2C561295705ULL, 0x5ABDCC1E277762A7ULL, 0x9BF46F504A87954FULL
        },
        {
            0x47DB4146516F4B0DULL, 0xB77B1BF3B770CF50ULL, 0x0511330688611457ULL, 0x7669520D4437366BULL, 
            0x9802BE9857BEFA31ULL, 0x10838B6319FB209EULL, 0xED55AE1E2B8E458CULL, 0x931570D57B9C1B73ULL, 
            0x606E9B87DFFA1B87ULL, 0xE0544E5F64BC505EULL, 0x423B83DC3C728B54ULL, 0xB081EA4792547EB1ULL, 
            0x53687EDF05AC9A7CULL, 0x4BCB58A8599C4FB1ULL, 0x052EBBE968102874ULL, 0xEACFF72542E9B6EBULL, 
            0xE9A3B0E7ADD13842ULL, 0x8943BCF0766AD732ULL, 0x1E2BF595DAB9FB22ULL, 0x5A84C747C8915974ULL, 
            0x4967A522C4FEB516ULL, 0xD4040B2739BE913CULL, 0xB5A9BFB34E991AB4ULL, 0x4F61D4885B8BA718ULL, 
            0xF76AB03051890495ULL, 0x84AF5728DBFF3712ULL, 0xA9FA42249584D6BCULL, 0x5D2AE3806A6C41B1ULL, 
            0xB5269392E12DF5E9ULL, 0xA04B92122EEBBC25ULL, 0x64FA1FFFA705ACAFULL, 0xCD3D7645CA128343ULL
        },
        {
            0x09AA2C02023C7B4FULL, 0x2C065B46E239B753ULL, 0x5A025D44270329A8ULL, 0xB65348E7CF560B66ULL, 
            0x8BCC203A9477E1EFULL, 0xF4A7E3FBC68D7DEEULL, 0xE28015DF9CCCE449ULL, 0x478D2297CC9B565CULL, 
            0x35346D397EED4B42ULL, 0xF329F6804C8DDD8DULL, 0xCBB5BC15C5FCC2F0ULL, 0xA2931DB5BB046D8BULL, 
            0x8ED2D7117F9AD189ULL, 0x0EAAB35BA89C29D2ULL, 0x32B5D249F22C3576ULL, 0xFF6F7A27E3472645ULL, 
            0xB36F80438EAFEEE8ULL, 0xB1417897A87796B2ULL, 0x7BBC2C1F01B67A8FULL, 0xC87CC023FF08FDE0ULL, 
            0x7442087F66C22BCFULL, 0x683EE98440169355ULL, 0xAE69FBB72A58083CULL, 0x61CD7B662D7C107DULL, 
            0xFFA4F34419D1ECD4ULL, 0xF0000D75B08857BDULL, 0x79842C4F626180B3ULL, 0x08CFBE898F3B6F89ULL, 
            0x6C1E262EC192B646ULL, 0x6FCF1A83397E405CULL, 0x1D1382E742170FB0ULL, 0xF533417AA89E24EBULL
        },
        {
            0x1EA889D4876A079BULL, 0xF8D004910D3F60E2ULL, 0x653B059165B70D4CULL, 0x84CCFC22423409ADULL, 
            0x51FB9C8E3BBF49A4ULL, 0x9B72BA1CC78E3077ULL, 0x24DB9D906CA14F87ULL, 0xA1B6AFA560D7CAC8ULL, 
            0x8A2E6C5B4BEF4A83ULL, 0x54FE187828F4D5BFULL, 0x4CA0501BD21E32A6ULL, 0xD5289879755EC159ULL, 
            0x18315F32A18BB023ULL, 0xA4E93CE8507DF78AULL, 0x8525B0292560D48FULL, 0x170619480E6D2A31ULL, 
            0x21341347D8948C94ULL, 0x97A3BEA7F496F528ULL, 0xEDD7E2DEA023B632ULL, 0x146CF09ADD20258EULL, 
            0x8CF78BC9693CBC3BULL, 0x059510510E6BCB4AULL, 0x70D5118373B4F2C1ULL, 0x60196EF3BCBDDABEULL, 
            0x6314C5BA26D5CF09ULL, 0x773625FDE30C1AF0ULL, 0x5CBAEB91467AED5FULL, 0xB3FCAC5B9EA6C79AULL, 
            0x222568F2D8E7E2E7ULL, 0xC5BA4133C6F4CE74ULL, 0x3964E247F6D0372CULL, 0x622FFE0B9D96FD1FULL
        },
        {
            0x0A7D1D2AF52B355CULL, 0x4F847C726663A062ULL, 0x1E56AE620999C88FULL, 0xF1492A7B235360EFULL, 
            0x6EE09F7A8B4A813FULL, 0x782221E21176DA45ULL, 0x9E18EA2E224578FEULL, 0xB0783330181EBEDCULL, 
            0x358A432A773D306BULL, 0x52952453B4E432E9ULL, 0x6DFE497D7C7F0537ULL, 0x05356F6A37A0BC0AULL, 
            0x5351236622694DBBULL, 0xD1BB37A99DF5DC6DULL, 0xCC4A7E3A380A066BULL, 0xBF30350E5B8E44A3ULL, 
            0x20DBADAF21A3BDCAULL, 0x911464417FC2CA92ULL, 0xFACDE81F1D97654EULL, 0x38323A5D1BFF7612ULL, 
            0x2333ED6D759F8A9AULL, 0x3363B1ED76462843ULL, 0xA30E7D226BC81444ULL, 0x5DAFC8843818B92AULL, 
            0xE96F65EC7D175057ULL, 0xD5CF8C5B55072259ULL, 0x1BA77741ECD064EDULL, 0x2098831FF6FEDBF7ULL, 
            0x649E3398CEC125F0ULL, 0xE7DFDE68B20DCE25ULL, 0x2E7DE9A19506C94EULL, 0x13038D0B99919DAFULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseFConstants = {
    0x98D48929AB1CB966ULL,
    0x815543449FCFFA2DULL,
    0xEDF541F69B3A5392ULL,
    0x98D48929AB1CB966ULL,
    0x815543449FCFFA2DULL,
    0xEDF541F69B3A5392ULL,
    0xEA3C9FAB0CFC89E7ULL,
    0xA1230CDC213403CAULL,
    0x24,
    0x71,
    0x86,
    0x78,
    0x5E,
    0x34,
    0x11,
    0xE9
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseGSalts = {
    {
        {
            0x76837917F59CF9A2ULL, 0x2B27694E105B0183ULL, 0x2C799B5B6F8C266DULL, 0x69C2A53C2FC3515CULL, 
            0x9A25F598D1DC0587ULL, 0x4A28F21D8855A3DEULL, 0x0D24F84B0CE40436ULL, 0xB4FB68C58EFDAD52ULL, 
            0xCB395421471A0D1DULL, 0x40FDF369F11AE313ULL, 0x0A24E4C06D7838ECULL, 0xCC32D45EEF6C31A8ULL, 
            0xDAD4B83F97F0EEB8ULL, 0xFACC98D6F80860D8ULL, 0x16E0C46C5D2DF871ULL, 0x1EDD5CC86B3D6A80ULL, 
            0x22CDF3D677B7FCB8ULL, 0x2FA4BAAA6E70941EULL, 0x5685CA39982AA994ULL, 0x65F4756B8C219D97ULL, 
            0xAC22E19EE688B9D4ULL, 0x1F41D7278A5A390DULL, 0x16D2A7BDA1A643B8ULL, 0xD3C404E95CC70624ULL, 
            0x1DB8EBFBD8815640ULL, 0xE87506A80E94E01EULL, 0x05223D010BFBA285ULL, 0xB35BAF8B2D85F0E1ULL, 
            0x90053EDEAA4D676DULL, 0x2E42B64562BD333CULL, 0xC14940A061B86B73ULL, 0xF66F823C031F2918ULL
        },
        {
            0x94C2B00E2563436AULL, 0x0F4279DBF7028738ULL, 0xA4BCAC282C23289FULL, 0xE0E539D873A183BBULL, 
            0xDE7ED6700D6AF11AULL, 0x642106AD12DABB40ULL, 0x8C94B6C700F71865ULL, 0x9AE5FF87A51C321BULL, 
            0xF416384C63C20D47ULL, 0xE3625A11E6EDBB26ULL, 0x641E8B4E2AE0C814ULL, 0x0C08A7372698DDD8ULL, 
            0x1703605F838B0517ULL, 0xDC67E7D19D966105ULL, 0x7583334E7B6B8766ULL, 0x20BAD534D4F16AE9ULL, 
            0x22EE1B0D5385DA41ULL, 0x48EACAEE97F673E0ULL, 0x78C977F6F5857D74ULL, 0xFA8EEA9BA69A3498ULL, 
            0x859EC309E58B2ADAULL, 0x89AA93A3A61B24ACULL, 0x7C35B09D90BCC364ULL, 0x9E1C264CD39DD35EULL, 
            0x3362821D5E0CDA4EULL, 0x30CAA1B90ADF949FULL, 0xCE169ED2254B8F7BULL, 0xD120D6CA60F65A7FULL, 
            0xDBC45B2870172686ULL, 0xA8BCCAA807E95793ULL, 0x268515B7726FEC48ULL, 0xF517E0BEA557F476ULL
        },
        {
            0xC3B4142A49F83083ULL, 0x24ACEE4C8EEA9A6FULL, 0xE936EA42A15F8ED5ULL, 0xEFD9DB28A277BE02ULL, 
            0xC3A3895BD0FF99F0ULL, 0x7E335F96C79194E9ULL, 0xAC2439EBD2CAD44FULL, 0x23F0D8A74E1D5A4CULL, 
            0x42991A4D55E4F3C5ULL, 0xB6F819FCE88E7955ULL, 0xCFE30401599A6722ULL, 0xCA6548A9B64108B0ULL, 
            0xA256768C3999139DULL, 0xD53A0059F3F2A480ULL, 0x4B3D1E9F1830F236ULL, 0xFEBE940F8A081DFDULL, 
            0xD9525CE98A9176FCULL, 0x7003E2E0DFE7A71BULL, 0xB98B1342013830DDULL, 0xE71AB8BDF8AF4B7BULL, 
            0xDC902C060712079DULL, 0x0B0F69ACF963C1E6ULL, 0xC9AB31F69ED7A366ULL, 0x0FFDE55A29305B4AULL, 
            0x3E93C6C0509E3F1BULL, 0x50B7B3DB1FA2DA8CULL, 0x52A3DC008C444D68ULL, 0xE1DBE5BC46007471ULL, 
            0x16EFC376E77995ADULL, 0x4E8532DB6D916CC4ULL, 0x167648EB47533D93ULL, 0xB2147B01265B14B6ULL
        },
        {
            0x1C468C581B5480DFULL, 0x3DC18A22B2883490ULL, 0x43915BFBD190A908ULL, 0xF2264C61EC67F2D3ULL, 
            0x37DA85CE0204216AULL, 0xA08125E92F43A907ULL, 0x2A75C83983DF36AAULL, 0xB040405059326944ULL, 
            0xC07580838E7EBF77ULL, 0x3F14F2B91FB856DDULL, 0xF724D72541224AB3ULL, 0x67FF23AD763F3746ULL, 
            0x6846C5C597D265B9ULL, 0x9FFFC6A561B08839ULL, 0xF0CE2B18D4939343ULL, 0x8F6BA57C6F522B90ULL, 
            0x87694907F1D7B7B3ULL, 0x0DD8797DA2E7AF3FULL, 0xF00F8A1BC485799DULL, 0x63493BBAD32CA603ULL, 
            0xC475C0F162A561FDULL, 0x90F4F4A9C35AB79FULL, 0x34D9E0A3F74DE94FULL, 0x6DF38340F4423679ULL, 
            0x748E56E3ADFB3EEAULL, 0xFDE655C397BCBAEBULL, 0x0F8D3F40921BCF0AULL, 0x2FF553C5005AE3B5ULL, 
            0xE8661EF64596D97DULL, 0x97B054A4E01EFE25ULL, 0x85B250DF645F38B5ULL, 0xD397A64852EE93ACULL
        },
        {
            0x6A193055C22781B5ULL, 0xFFEEC5B26F24328DULL, 0x6911CDD040EF4311ULL, 0x20D4589D551E23ABULL, 
            0x9BB1F1DB13928FB7ULL, 0x9C9624C861DD9E6DULL, 0x9DB77F25A5D0D61FULL, 0x635F6067C56BA9B2ULL, 
            0x0839CBB93DBAB0A7ULL, 0xC7677268FD3CE212ULL, 0xC280C508D98D35A8ULL, 0xC243C8D71947E208ULL, 
            0x3AAAC3B31A7447E6ULL, 0xE6789F3D18A92F08ULL, 0xC09E56B0EE67E16FULL, 0x92AFC1D76E556A51ULL, 
            0x91761F7ED91F60C7ULL, 0xB96048E532DF4C0BULL, 0x3A8056EE58B76CE2ULL, 0xD888942C97FE474EULL, 
            0x3C40546CC2EA02A7ULL, 0x4E45EDA7F561E002ULL, 0x78E3FF18947BE57EULL, 0x58CFC82AA49B898AULL, 
            0x456325D623514706ULL, 0x0A4CEC5D5DE5EA98ULL, 0xA4FAFB98327C7740ULL, 0xBEF602907F5A90CAULL, 
            0xFD639A1D42DEF477ULL, 0x9E05A4556D10125CULL, 0xE86ED91035E8D195ULL, 0xDD2D865BE7305E4DULL
        },
        {
            0x24DFF1E9DB94E84BULL, 0x00198B956C102053ULL, 0x164EF3E872D953A2ULL, 0xEFD5CB385DE9B8B6ULL, 
            0x67A27D1018EAF8C4ULL, 0x9A632ED92CF316B7ULL, 0x49C77E49872F16A9ULL, 0x0C914F899FB9FBFEULL, 
            0xA5DD81EF021425D7ULL, 0xADE2FFCA29EC9646ULL, 0xD917F8276A684CBFULL, 0x96A1883D3B9C1E2FULL, 
            0xDE14B5305744F623ULL, 0xD4943247AA10823EULL, 0x7E0F8AB6E118E511ULL, 0x2E83C5FB690AE37FULL, 
            0xDCB08A3E3A7D3364ULL, 0x5109905AC361EFD4ULL, 0x29025AF2A9A3EB95ULL, 0xB39DE6FEF6D0B133ULL, 
            0x85FE9CC1136BD0F5ULL, 0x6D88F853509954D5ULL, 0x8C8E16D7D2159076ULL, 0x5B0ED3D0D7F7F44CULL, 
            0x977F819B77C47016ULL, 0x5A3525A840085A1CULL, 0xE066BE57DC4AFC89ULL, 0x78169F798E1D0AFAULL, 
            0xFB40423BD1D7EAB7ULL, 0xB8B77A8C98339D1EULL, 0x57943A8E066B1AA1ULL, 0x4B5CC7EEC00F868DULL
        }
    },
    {
        {
            0x6D2EE27B1E9F3A5BULL, 0x6FBFCA99E2558876ULL, 0x37C580D4A2114E0CULL, 0x283927B0E7820175ULL, 
            0x41B6AA7639C07767ULL, 0xD8153BF022AEE06DULL, 0x7771C8BCED524A08ULL, 0x41248A4628FA1CB1ULL, 
            0x0D5E056BA6E697BCULL, 0x947B991DD2219043ULL, 0x968D996BF65B1CEEULL, 0x1F0B24091ABFE646ULL, 
            0x63F5BBD6BA13721CULL, 0xFCE1FFD72CA5D920ULL, 0xC5FCCE7A4CB73AB7ULL, 0xD713145980552685ULL, 
            0x134B36FED2497E76ULL, 0x0CF7397D39DD5392ULL, 0x0ADA4B544AC615C8ULL, 0xB5CBAE3A44B13310ULL, 
            0x36DFDA0F88BA654AULL, 0x6409CC14B5A488EFULL, 0x0E20E82B95E9D7D9ULL, 0xC477CEAD235547F8ULL, 
            0x0C63DFB8D5BA98D7ULL, 0x6BDC6A18B3BA90DFULL, 0x5B00C9CE49090D7FULL, 0x40E572B394F276BEULL, 
            0x50405DC8BF403BDAULL, 0x932B48682B58FD7FULL, 0x95C541DD10FF47B6ULL, 0x98B2C90E862BA5D6ULL
        },
        {
            0x32DDC30B4151CB11ULL, 0x166D73723E3D176AULL, 0x8A4A1DFA349D2C03ULL, 0x6CBFA1F93D8A6526ULL, 
            0xFA984A149F61A0F3ULL, 0x9B3DAEA406CD4717ULL, 0xFEBBA2B5F3A5967EULL, 0xED34C1266E28FB9AULL, 
            0xC35F709652C7478AULL, 0xB1174FE2FCBE8170ULL, 0x29E166457D83760FULL, 0x61A444540619DA18ULL, 
            0x48091285E33D5E63ULL, 0xE3F5AD19DA26CCE5ULL, 0xAFDB124F35783010ULL, 0xF404FCDA4524E1A9ULL, 
            0x6515E307CBBECC0FULL, 0x26B81712C3F4CB47ULL, 0xF072703926386CFFULL, 0x0F3276BE6A738052ULL, 
            0xAE9C0E164E53960AULL, 0x254CADD42AABF99FULL, 0xEEFB91928416BD9CULL, 0x157D635413AC1E96ULL, 
            0x3048961E75E1CBBCULL, 0x79466C8AB5D7CA0CULL, 0xB6D58C436FD8AEDAULL, 0x83F189D1F0A8590CULL, 
            0xD9E42151ABBA9038ULL, 0x519360EFC1515C1DULL, 0x1CEB56B0A537AE03ULL, 0x2FCBA7EB9F8571EAULL
        },
        {
            0xC75688EAB9777375ULL, 0x3C91DAAF1B3EC206ULL, 0x306C246F6F02119DULL, 0xFF12A45937AFFFE7ULL, 
            0x159CB64657E458E6ULL, 0x4088D523524A793AULL, 0xE8C4FB411D4A1135ULL, 0xD8B0817611CEF22AULL, 
            0xA3236C241DCEF655ULL, 0x096B3A4C93AA6F10ULL, 0xBB552056326EFCC2ULL, 0xC6F37D0F6AF4A528ULL, 
            0x3B9712E2DDF5B976ULL, 0xE564ED6D5CFE9739ULL, 0xF1CB947F78200BBDULL, 0x8859C7808D616A70ULL, 
            0xD8BBA17B1DD9B649ULL, 0x6F716C70D1E5D261ULL, 0xB75C6AB440CBDD21ULL, 0xF562C795BBCF750DULL, 
            0x2E666254EEDF0ADDULL, 0xA51021A421907CD2ULL, 0xFE3080A38549EA42ULL, 0x34F107744F11644CULL, 
            0xC29F18899207EE2BULL, 0xFF3AABB04D28409BULL, 0x23D716F66697E80CULL, 0x7D8F63A13AC3E0D3ULL, 
            0x2288DE132BC915BBULL, 0x651B0D3D4D940222ULL, 0x29D4CB9028AE2B50ULL, 0xE2B2020B3A657AA6ULL
        },
        {
            0xCEB0C2CB46DECD46ULL, 0x00CCA9F8B89CB0A0ULL, 0x3714C6CB28EEF910ULL, 0x509DD5BD58C03458ULL, 
            0xECEF505CCFD89717ULL, 0xBD8A384D909379ECULL, 0xD4859C3739FE3443ULL, 0xBE5BDA3CAD8A6B98ULL, 
            0xF38799D9B8A105AAULL, 0x748CF28432060F3CULL, 0x36E7861710E8A081ULL, 0xDFFE27C80A7156E2ULL, 
            0x991EB50705AE2A3FULL, 0x4B76FB66291D9F41ULL, 0x4D120011CE8B37DFULL, 0xFAD468ACE0E79C35ULL, 
            0xF8BB75A1A22A1419ULL, 0xA81CBE5AF8584804ULL, 0x6022533B83EC03A6ULL, 0xAC273784751A91E8ULL, 
            0x72D77773454CACCEULL, 0xB9280440269D057DULL, 0xA73FE486DE002EC9ULL, 0xEE2685F8EA1CFEBFULL, 
            0xC8A3D4ACB2DA95EFULL, 0x1F81127D978212CEULL, 0xC8AF9A92DC6ED67DULL, 0x135CFFAE2E351F2CULL, 
            0x0C8B9B22E4C02C88ULL, 0xF08F4199FF997AA6ULL, 0x00BDC726A1900DD4ULL, 0xEF2638AE6FC9A65DULL
        },
        {
            0x3883A61BD423ED46ULL, 0x9CAAE8E4A2A186ACULL, 0x0A9F812216E31C8DULL, 0x084592774FE28721ULL, 
            0x5363B82A75ADAFBBULL, 0x62D097EEE63FB603ULL, 0xBED402A1B91E9484ULL, 0x3B8C7A681CC30CDDULL, 
            0x4FC7B872F56F06ECULL, 0xE3B12259A00078EEULL, 0xF21214F7FC93B941ULL, 0xB0A1DBCDF5824DEAULL, 
            0xCFCCECAC53E00399ULL, 0x87DE09A647449086ULL, 0xC625B4F48169DFD9ULL, 0xFE960651D1473B42ULL, 
            0xB142FFC490982150ULL, 0xB3672757944FCED8ULL, 0xAFE759542F4F9001ULL, 0x5F760FACE88F10FEULL, 
            0xAFBA93C1F536FDC4ULL, 0xE29686768FFC49ADULL, 0x7D8C7B0AC1362FD1ULL, 0xD1F100EC439A030AULL, 
            0x8FA4A9E0B7F38B3FULL, 0x010E18DD08F2B2C6ULL, 0xDFABCC8BB4F8F670ULL, 0x8585FC87E705C97AULL, 
            0xD785F36D2ED3AEB1ULL, 0xBD83EAF57AB8E1B1ULL, 0x7CD35E13F03525E2ULL, 0x8749CEE129AC1417ULL
        },
        {
            0x22E89032E83D2E5BULL, 0xA6A904F9E3120AFAULL, 0xA89E38AA0A502C3EULL, 0x316B96E412571C76ULL, 
            0x9034E108CA5AC45AULL, 0x41040DF3EDA0C5EDULL, 0x1E2E7039D76D3AF3ULL, 0x6ADBE750B4114710ULL, 
            0xC524E01EC023BF05ULL, 0xC31DCB3F6A2D399FULL, 0xB912EDA7B836FEADULL, 0xFE55B513FE4A3AA4ULL, 
            0x3E7B1E76656943A3ULL, 0x93C7EEC9724728B4ULL, 0xA3B492A5CF644154ULL, 0xAC3BD9E86A5D0A38ULL, 
            0x8F1F937F88B687CFULL, 0xC989DB4017E17315ULL, 0x945EBFA1924B8F1FULL, 0x97A8C219006954BEULL, 
            0x8014AC75D96037D0ULL, 0x1ADE169FFEE843D4ULL, 0xDD214305B5A6DDC9ULL, 0x912F268FE02866E9ULL, 
            0xF612CD62C50A0033ULL, 0xB40749884D936918ULL, 0x3441B2330E751E65ULL, 0x8A7BBBDCA99738D7ULL, 
            0x7176D457E24E0105ULL, 0xE1B300D94FC5742CULL, 0xD1844DC44D05B92FULL, 0x0B019E9AEEC87572ULL
        }
    },
    {
        {
            0x6F8E60517AE2B427ULL, 0xC55F4FB527DD7032ULL, 0x0D9733A7F6522546ULL, 0x5656D24077421D2FULL, 
            0xB97E548A038A4E00ULL, 0x1548DC4451E4B8E0ULL, 0x68B27715DD49E255ULL, 0xB60B9EAF6CA7820FULL, 
            0xEF1F257C9F819A8AULL, 0x6DC89B058F5C289CULL, 0x503432CC9B70419BULL, 0xD802E342EEF9F841ULL, 
            0x10E34F99569E3073ULL, 0x2B8244AEE0DF61E5ULL, 0x6C26EAABD316C269ULL, 0xCDABFADA88C45715ULL, 
            0x79AB7F350B63A169ULL, 0xF910AB96E8C864C6ULL, 0xFB785669F8DAF1BEULL, 0xF2555A6762C16998ULL, 
            0x7C7A23F7DB13AEADULL, 0x0DF2F26ED838F215ULL, 0x99C0AF77B4D79054ULL, 0x208AFF964974ADD5ULL, 
            0x27BA6C114AACAF46ULL, 0xEFE49D43501A3F9CULL, 0x2E6A3ABDE84FAD09ULL, 0x5EF8E7CB2C8309BFULL, 
            0x9F4B7ABC4DCFF94FULL, 0xB298D4B44B752925ULL, 0x97F736DABCCC8A8EULL, 0xE6149AF662ACE4F7ULL
        },
        {
            0x9C25235821D7B1F4ULL, 0x590143CFCCB96581ULL, 0xE24921F9DC7E2D0BULL, 0x548CE7A5172A6103ULL, 
            0xFB7BDA90D870A23EULL, 0xFD3CE72069E73556ULL, 0x38AEC668FF42193AULL, 0x95E22A6F0C5C98AAULL, 
            0xDFF565E932072A7CULL, 0x6291E4EE0630B7FDULL, 0x890409F09E58C328ULL, 0x2E7FEF367DD7CA59ULL, 
            0x7B6BB00A9FF41FDFULL, 0x8973753E0A493A83ULL, 0x68F72DCB3AFC1324ULL, 0xE4684E711339661CULL, 
            0xE2766977F2B3FCBCULL, 0x1A0632FE00A595F2ULL, 0xCAFA054CADFC6DFCULL, 0x65E900368C7C5762ULL, 
            0xB6167B92E7FB94F6ULL, 0x31F950290BD787FCULL, 0xD49DA482D869278CULL, 0x6D10A4A1D4937BA7ULL, 
            0xBAFF9378C48DEFA6ULL, 0x6F88E7286068CD97ULL, 0x6261242A12421C36ULL, 0x3BED28C38C9B2F39ULL, 
            0xBF000C9B28118D07ULL, 0x6218D22010A7BB03ULL, 0xCEA103045258D603ULL, 0x02BDCF847EB4A577ULL
        },
        {
            0x2063568FBFA00DDDULL, 0x9C74A9F18ED6D84EULL, 0x90C2BA04CEBB5117ULL, 0x198855073A36EEA1ULL, 
            0xDFF25ECEB9FF725CULL, 0x1A5863CF5354B8F7ULL, 0x7B5517416D889335ULL, 0x913F2042089C9F56ULL, 
            0x0B897FC1A1B24DC5ULL, 0xE0F0281BEFBF62A2ULL, 0x468A686A3B2BA3E4ULL, 0x228D47CC5C8B1F46ULL, 
            0x8FDCE2E5F55FFBECULL, 0x172C4516C277C9CCULL, 0x7895B417A5D4223FULL, 0xA09E16B96BB22BE6ULL, 
            0xEB0EA12CBACB84ECULL, 0xE6E9A77202B713F0ULL, 0x52A4DA6386811EBCULL, 0xA735B92CE02B03CBULL, 
            0x5E54C4B09E88BACDULL, 0xAF810C91D7688AEDULL, 0xB383B1DBC8E89813ULL, 0xD65C3B1E4CE88217ULL, 
            0x430F385BFA1FB3CFULL, 0x8A2EA801B7D697D0ULL, 0x90781822676F346BULL, 0xDC7E118434CB680DULL, 
            0x555EBF718D7A9F4BULL, 0xD6693C9C5A4832A8ULL, 0xC5AA0EEE82226547ULL, 0x9996AECB72788D7CULL
        },
        {
            0x8C82331B3D19413BULL, 0x326D02249FCEE86AULL, 0x3807FE37435B209BULL, 0x1E7B686F8470B168ULL, 
            0xFC5BC59D02B6FF5BULL, 0xFA72C5A021F58D23ULL, 0x0EF821CDA9AE47FDULL, 0x4CA3F4159F11EEA7ULL, 
            0x4D9A422A7BE70DE0ULL, 0xDD66DDB1F446B446ULL, 0x1FE71EC13D0BFE91ULL, 0xC7850A9B0A7CB643ULL, 
            0xCE50B6CBCFA2ACC6ULL, 0x0BBCA31B2BF9303EULL, 0x90270166736F2111ULL, 0x93443693550E7247ULL, 
            0xA3CEA1FF6238D70FULL, 0xD725BD04E24F235DULL, 0xFD3ACD7C91E60784ULL, 0x112AC759BB7E6979ULL, 
            0x615303F0355F199DULL, 0x4E0FF724D62AF45AULL, 0xC22B68705921273BULL, 0x7D86554401910FDEULL, 
            0xD610441F6BEEDC93ULL, 0x4A0AE1A5B919ABB1ULL, 0xFFBB7288A8543D14ULL, 0x2DEDF43FACF57362ULL, 
            0xBB8A90CBDC588CDDULL, 0xB236D535C15AFBE7ULL, 0x2770555B3F91ADCCULL, 0x0DD856A79190A5C9ULL
        },
        {
            0xF168F602A98190BEULL, 0x183F747A69CB28BDULL, 0x4E8EE2CD5E83921EULL, 0x6A25EAE14AD01BA3ULL, 
            0xD445FB3DED2C7DACULL, 0xB90AFD00EA8BC4DBULL, 0x2B556CFC85DA72F3ULL, 0xF144995A6EE6844DULL, 
            0x5F5FB8652C506307ULL, 0xA32ACC31C0508752ULL, 0xD723C74AA8ACF8CDULL, 0xE3F91CBDC4BC3DC9ULL, 
            0xCC7D10E84C2A5FBFULL, 0x68F5A05C602AD0C0ULL, 0xC1ADA225871B1544ULL, 0x27B274E1AE04E090ULL, 
            0xEF7B464D7E71315FULL, 0x5EFD6A2D4774BE5CULL, 0x87C140D00C623499ULL, 0xD286C2937166C3B2ULL, 
            0xE197413CF1E13A46ULL, 0x008B90DC62676DC3ULL, 0xD41872C9BBDD0A58ULL, 0xE6E532EE725D8DC5ULL, 
            0x1D219F589DFA18B2ULL, 0xB8BA55B837F21773ULL, 0x17FA0C94A0CBE9F0ULL, 0x66CF25CDF25B5076ULL, 
            0x90FDF3DCB45CD43FULL, 0xA521ADE744ABD353ULL, 0xDB2D8D83E501A239ULL, 0x48344A12C3D63831ULL
        },
        {
            0x0384A1AE8884B9E1ULL, 0xED17A4DE6A055194ULL, 0xE1CB041C9150F16EULL, 0x3CA03A4FD2B19AFBULL, 
            0x149ED2F886BF4010ULL, 0x8C337C69BFC8645EULL, 0x098007855F2CD876ULL, 0xD6E4E7B066E18E6AULL, 
            0x9964197F7FDCE6AFULL, 0x1E3CE6F74A88FF83ULL, 0x39D27C9331E49B04ULL, 0xC004BD4891D89453ULL, 
            0xEE27E281D2D01A20ULL, 0xBC8D154E7CE8ABA5ULL, 0x508964B93A6D74E8ULL, 0xC5ED55D224B8F37BULL, 
            0xB994F2FD76A1D1E8ULL, 0xE87C2139826D43EDULL, 0x9895D1066E5D00ECULL, 0x6F2B23EC56FC32D9ULL, 
            0xA843E7D96B6BFB7BULL, 0x3C152BB0119FE94BULL, 0x4CDA5CCAB0FE0224ULL, 0x86D357748E304E6EULL, 
            0x3CA312E489560D75ULL, 0xBE726240775DE5EDULL, 0xA9967FB65B97B3D7ULL, 0xD490E5711CC71CE7ULL, 
            0xC60C958F6CFA3BE1ULL, 0xF1B7A9373AA51EEEULL, 0x1A2983436BB96730ULL, 0x394AB1E7D1850A0CULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseGConstants = {
    0xC1DFAA58172539D3ULL,
    0x2E7569E4026E14ABULL,
    0xF59377F45C84BDF0ULL,
    0xC1DFAA58172539D3ULL,
    0x2E7569E4026E14ABULL,
    0xF59377F45C84BDF0ULL,
    0x506DA72A1C8A1BA3ULL,
    0xA448E99EF87F5480ULL,
    0xA2,
    0x52,
    0x39,
    0x83,
    0xD2,
    0x3B,
    0x12,
    0x80
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseHSalts = {
    {
        {
            0x1516B3A53F3171BDULL, 0xBF23759FD4DA1A4BULL, 0xB5837D004A978877ULL, 0x2600142C465593C1ULL, 
            0x556CF2B80A48451AULL, 0x82D782AE3C66C3A2ULL, 0x6912C0F32363DCAFULL, 0xFFCEA336C3AB87ECULL, 
            0x8963B8F2D08B347AULL, 0x81CF0D739E01902DULL, 0xA05A034281C36918ULL, 0xF4A4F014722F41FBULL, 
            0xE69619FEFB935FAEULL, 0x8FCFBD833D26914BULL, 0xA81E4C475FCEF255ULL, 0xE531CD75BFB19482ULL, 
            0xE069BA8AA90321B1ULL, 0x3A23457DA5DDB5AEULL, 0x6D7DDFA755DB8168ULL, 0xF823C91B0DFEF80DULL, 
            0x42C026DA3B1421D5ULL, 0x1600F295733C04DBULL, 0xAF34B8FB24C70B56ULL, 0xFF940A884FD48A36ULL, 
            0xC166F1588A02CEB2ULL, 0x3B81B9495D3E05DEULL, 0x608E79233D13A0D4ULL, 0xBFA4B8E9681C4C24ULL, 
            0x0A246DB762D9DBEDULL, 0xB7DF3A1FA2609A4CULL, 0x28E3CE6D6F7BB175ULL, 0xE8B9087B83F4AA07ULL
        },
        {
            0xF49380554E7D71C9ULL, 0xA0E31F870E88F1D8ULL, 0x7112AC2696E018B3ULL, 0xDD6D431191219400ULL, 
            0x74E561F62F8D2B1EULL, 0x4513DB67631E9CB4ULL, 0x4044E40618D6F2F2ULL, 0x9FFE264439D492A2ULL, 
            0x0129BF678E428610ULL, 0x5ED5E15F87B6A7D9ULL, 0x208B8D6B7DFCCB84ULL, 0x47A9F6575FFA2C39ULL, 
            0xC0ABB6D29742F4D2ULL, 0x1B8B83E26872047BULL, 0x25F8641FDF0C543EULL, 0x3E14D80E5B53FA52ULL, 
            0x7CAD6A408CCCD5C6ULL, 0xD30917D6134E9877ULL, 0x809FFDCE88E32DA4ULL, 0x06CAE4D734952F30ULL, 
            0xD18053F7CDE9F231ULL, 0x6CBEDDB24F1C77B0ULL, 0xEE35EF41C523460FULL, 0xC089A51F904D3BABULL, 
            0x72E391725739A196ULL, 0xB229A797CFEAEE93ULL, 0xCFA440F9F1FA9F8FULL, 0xD2BBDEA9E42E8461ULL, 
            0xAAE42B196E57C66DULL, 0x1C69888DB33A510DULL, 0x5466BD02F9AFFF23ULL, 0x5E66BA5F0D8850BDULL
        },
        {
            0x7FF20AA9D601D32CULL, 0x96B5E0B4EAE83A84ULL, 0x1B1426ACAEEA069AULL, 0x257306AAA7338CCEULL, 
            0x346F8F963D508575ULL, 0x4ED036F4E505195CULL, 0x8A68984EF0F2E787ULL, 0x909E9BE6BE07C21AULL, 
            0xD832505EE996D094ULL, 0x3B3B547783778883ULL, 0xA265C37A4C4B8045ULL, 0x0CE68865C4CDC56BULL, 
            0x24D2B22CAA882067ULL, 0x05199B8669973302ULL, 0x9E3FDE6E36D925A8ULL, 0x03813934EF182E2DULL, 
            0x0109F45050EA6257ULL, 0x5417BCEEEF879609ULL, 0x3A6DA096278D1707ULL, 0xBE8D1C79184EC0E1ULL, 
            0xA8B6DDFDA75FDACDULL, 0xE4D14F9425E2D8A1ULL, 0x004926BABAF5C22EULL, 0x66799DD3310AA07CULL, 
            0x7513E6F09F3A3C4BULL, 0x607379DB2F6E587AULL, 0xBF046C8048FB13E2ULL, 0xB61C35575758EB52ULL, 
            0x53AA35ECD2F3A0BEULL, 0x01002E6271AB3C80ULL, 0x1DB8056B4EC2D231ULL, 0x82D343C802B95A29ULL
        },
        {
            0xC8BBEA4EB7A38E78ULL, 0x507D89305DDD75CFULL, 0x6F77B362973BE20FULL, 0x50F1C1AAC452A4DCULL, 
            0xDBF966FFDDB559E4ULL, 0x0543E706927971DFULL, 0x2C7F62F5B0ED34FDULL, 0xE6B4266D1DEC3DA7ULL, 
            0x1559BBF8299F86D2ULL, 0xB7139F1FAD9F6AA7ULL, 0xF310A5E4BD81BEB6ULL, 0xD6A2F94538D62AC7ULL, 
            0x90FBC4099B54DEEAULL, 0xFE0F19AD674D4A0BULL, 0xE0FB526D254C1C9BULL, 0xA3286A4D1B252943ULL, 
            0x4531BB685CFC6832ULL, 0xE6C3D3E724405596ULL, 0xB104988B36E0042FULL, 0xCF28FD405B7D4348ULL, 
            0x0D68896827507F54ULL, 0x20D521A57FCB4686ULL, 0x526FE5CFA538F14EULL, 0xA472965FB883609BULL, 
            0xE0D692E50F9268AEULL, 0x244FC95657CBEBC8ULL, 0x9AC9516FB1593FECULL, 0x238D291908A9180CULL, 
            0x0A7D288D9694DD2CULL, 0xA88DCEA720A56E75ULL, 0xA28C609ED070E50CULL, 0x8BF4F3E583AB1C56ULL
        },
        {
            0xC03A51587CD9D645ULL, 0xA765EB65751159F5ULL, 0xB7E53F6D68E29F03ULL, 0x12CD8745248A31EAULL, 
            0xBB84B055976344ADULL, 0x5B59F04D08E37A40ULL, 0x0A7F0A3D6F17DB5DULL, 0xA82D81FD05F74A3DULL, 
            0xAE29414AC8204FF2ULL, 0xDBE6B4A39E037937ULL, 0xEBCE402AA124F76FULL, 0xEA0EBC6E4217D09BULL, 
            0xD96A7CA93084B5CCULL, 0xB73EE90491FEC2DAULL, 0x9F0B545DA44E3A09ULL, 0x5564A71D5F7AD54EULL, 
            0xD89F117E82F516C1ULL, 0x235B10801EB15573ULL, 0xB376E8DF9F1ADE3DULL, 0xA5164E0C1B37BE36ULL, 
            0x8D515685F40BA4CBULL, 0xA8C84D09BF0A6C0EULL, 0xE962EFAA43BC0AA8ULL, 0xACD8118C43A7C54FULL, 
            0xEE85132873AE6F7DULL, 0x762306A3C5366793ULL, 0x00F10059684D5202ULL, 0xA176C71DBB73E2A6ULL, 
            0xED31474C08AB8E09ULL, 0x7A7A83D07922BED3ULL, 0xD7E247E8E74F4584ULL, 0x41E02A3E1C014A86ULL
        },
        {
            0x982C519D6B561B01ULL, 0x18AA29E173B52847ULL, 0x999079A092597C7AULL, 0xD19FB84624547F21ULL, 
            0xA77E7FF3F2980B35ULL, 0x3AF0CB223CF9877AULL, 0xABC5B78D5098FD80ULL, 0x0A2E3477FA47CC81ULL, 
            0x31180CDA770D362EULL, 0x2924F77854BBA911ULL, 0x77515929871AB0BBULL, 0xFBED9C8E14C6C8D3ULL, 
            0x772A569CB4FD2E92ULL, 0x5C046ABFF06510B2ULL, 0xF9E74BA3112DDC28ULL, 0x258803142A7185A9ULL, 
            0xC5BCE351719367E5ULL, 0x8790A6E4B414E144ULL, 0x93928C8E293D0A62ULL, 0xBF63F4249DFE6466ULL, 
            0x2001D3F3D9185D76ULL, 0xE8CD2A33F6DB563FULL, 0x7FEA0D3D7584D7ECULL, 0x2500592F0DAFBE69ULL, 
            0x5E046EDDB6DA3506ULL, 0x697C8AE75139DCA4ULL, 0xACA82ECAFA69B4DEULL, 0x6CDBD10B72BA34C3ULL, 
            0xAB02265F9309FC33ULL, 0x9FF3D5DB553E7D81ULL, 0xAB77331E4D983140ULL, 0x10F05A8D7A29BCE0ULL
        }
    },
    {
        {
            0xB1E3FD75ABA37521ULL, 0x0F486B9E85690274ULL, 0xFE9EC5163181336FULL, 0xDEB9D10921AD4FE3ULL, 
            0x850BF8598FF7BBBAULL, 0x908B7671DF9EC10DULL, 0x374CE35245CD071AULL, 0x4FB42BD7143983B3ULL, 
            0x51D4DC45DCB8609BULL, 0xA975565852475263ULL, 0x07222C820250AE4DULL, 0x23AAE3A4C5B7D2CEULL, 
            0x361E75EB57C6A378ULL, 0x09D3ACF558A1F869ULL, 0x250699002DB00C72ULL, 0x6A8EDD5AABF1A94BULL, 
            0xB052D189F37D9FA7ULL, 0xB695C6AE5BF0C738ULL, 0x0EB3467B0E31A12FULL, 0x635AF08F1C383D2FULL, 
            0xC4C2BC6F4578D273ULL, 0x5EF9F1E570B9F821ULL, 0x3EBC01DCC0CF1546ULL, 0xF878D87088630F60ULL, 
            0xDF944CA9972ED222ULL, 0xC4B42D31999B6E5CULL, 0x3A150486772D96DAULL, 0x9E623717FCC5BC11ULL, 
            0x7EE02A17204BE6D4ULL, 0x130BE722862053B5ULL, 0x589778EB6964940FULL, 0x501E5471C05AD697ULL
        },
        {
            0x425E5D693701F2D2ULL, 0xE3689B5BA4555C78ULL, 0x60365E8D77E9EF61ULL, 0x60EEC3414EC35DC9ULL, 
            0xEF27119208727817ULL, 0x574F0B17536FF2D0ULL, 0x11CBD6E331FEC918ULL, 0x63647429F2807E57ULL, 
            0x8DF99E41E128A03CULL, 0xA8B1861C9A648AB0ULL, 0xF4C656AE937D93ECULL, 0x58FE89B07E87A62FULL, 
            0xD8FA6FB1FE3070A3ULL, 0x0285AE7D16F502CDULL, 0xBA7A4D4AB6DC4678ULL, 0x974928313C560605ULL, 
            0xF04DEA4BAB239E68ULL, 0xD8D7DC0EBFEB4FA5ULL, 0xA2234F2848D8938EULL, 0x03C5C7F74A6A2C32ULL, 
            0x79CDBD4A74A80958ULL, 0xD686D3417DA6842CULL, 0x2EF35267619A0CCAULL, 0x868E87A75AA65ADFULL, 
            0x4B380395DF360FBCULL, 0x529E076B2B80D154ULL, 0x1C92ABB064B798EBULL, 0xF3052D369486316DULL, 
            0xC1C0E98FD4CBBDF9ULL, 0xC37DF95434E9E3F9ULL, 0x075D68BA850C84EEULL, 0xAE494160EF87134AULL
        },
        {
            0x5C5199EFFD4EB4A4ULL, 0xC2D9B841E3767B44ULL, 0x6D7D91AB4442F024ULL, 0x40C082EC4A7B818AULL, 
            0xC42BE111E74667A0ULL, 0x6B55277C6082427CULL, 0xA4BE583F52CB7EB3ULL, 0x8422DD4D8785613DULL, 
            0x3EB80989F687A3E8ULL, 0xE97F2FB2CED72C8DULL, 0x8609424F647D8AE6ULL, 0xA1AD5BAB02FD1274ULL, 
            0x94A687247ACA024EULL, 0xEF50060B0965ED2BULL, 0x04DFD414D2211299ULL, 0xA4E55DE41062E19DULL, 
            0x566F1967C57EA426ULL, 0x1E547E69A9B489D7ULL, 0x020FAFADEB518CEAULL, 0x6C532B6239210635ULL, 
            0x9FE501167DC62225ULL, 0xB4E9DFE03C1D2862ULL, 0x34FFA88657E5C9B8ULL, 0x27C06720929C0667ULL, 
            0xE93239337BA2ED5AULL, 0x35571CF54B14A0F8ULL, 0x79AEB848D7272E6FULL, 0xC6A8F9BD7AB30DF8ULL, 
            0xCD4BA8AC257ED845ULL, 0xE7490CE29EEB9ED6ULL, 0xABF3EDF361306528ULL, 0x2D529DF83983E8DDULL
        },
        {
            0x53A414E6B7453546ULL, 0xFF781A73CECCF871ULL, 0xE520D8B7FAB09173ULL, 0xEB8B8BB867B8580AULL, 
            0x0DCEB067F1716C0DULL, 0x413EDB13A3C48B0DULL, 0x32B0E5E6490CA3C3ULL, 0x4981C5A1F16D9F46ULL, 
            0x7E8A4EA12304C0E4ULL, 0x5D8BCACF36827B61ULL, 0x6A8BDB49C3775737ULL, 0xBB017A23EBD08CF6ULL, 
            0x9533F927FBAA0876ULL, 0xBFFB9C29BA12E196ULL, 0xC428CD599BCC7FE7ULL, 0xDE99C7F99E9A5843ULL, 
            0x27895301CCB100D4ULL, 0x274C8A6BF924DBF7ULL, 0x6D44676DD8B7639BULL, 0x39C40D2F723A90AFULL, 
            0x1B930C5A341FAB49ULL, 0x732F06865CF640DEULL, 0xEAD9057504122A7DULL, 0xF7FE55A7819CED79ULL, 
            0x19D9F2C95106DF06ULL, 0xC93616A95FB9CCBBULL, 0x2AFE1E7519A53209ULL, 0x2594ED77CCC780BCULL, 
            0x7CC12222AD8E4BF5ULL, 0x0DF190A0345DF56EULL, 0x715348B224833902ULL, 0xCD2006F55A08F939ULL
        },
        {
            0xE99AD704CEBAFB11ULL, 0xEA7D1FD2D0F2892BULL, 0xDF15A2DD0EDF47FCULL, 0x0F6BEBCB9D088DE0ULL, 
            0xEAF8EB092C2BE387ULL, 0x8B167E55436E1CB5ULL, 0x7207A7A73B6321F7ULL, 0xC069E9DED0A59360ULL, 
            0x400117832A02E5DEULL, 0x53558B1380E12000ULL, 0x235C4EC77DA2DAE7ULL, 0x99BB6728DBCBB9C5ULL, 
            0x2E78045343BAD934ULL, 0xC288DD8EBD832278ULL, 0xA6D317DA370871D4ULL, 0x7517FBC20EF3F592ULL, 
            0x494F9CC5E0C5F7A2ULL, 0x497E7DCEB4C49D40ULL, 0x479882DE1DBE3369ULL, 0xB6B771BC8F2102CFULL, 
            0xB0FEA31E97703DDDULL, 0xD933854AE0391B7EULL, 0x2E7D2B8C098A6121ULL, 0x976F606A3E8E5D57ULL, 
            0xE73A238A049DD02DULL, 0x2D330535E30D1CB2ULL, 0x5C335A426CB90390ULL, 0x9C62ABA31C786E11ULL, 
            0x8B453C82F55F7201ULL, 0x533AE2C0EFA9C363ULL, 0xC9A11AD98BED969AULL, 0x22525DCEF034FFBBULL
        },
        {
            0x231EE7F9FEA4F9D1ULL, 0x0846531508EB0F63ULL, 0x609DDC0DE5175016ULL, 0x5F2F1C3ED999F600ULL, 
            0xBBE8BFF41E58C817ULL, 0x1104A9FEC74F5021ULL, 0x0FE8F94131D11E45ULL, 0x172014D98E1D1BD1ULL, 
            0x7E224B1A6E1F4882ULL, 0xB799F6E7E75DFD0EULL, 0x6075EDB184EA6BC7ULL, 0x77CFDCAF82A3AAACULL, 
            0x3DE637E5202501A5ULL, 0x6F0402BA0E876B25ULL, 0x3DB24DB197E816B4ULL, 0x0B4D86B6F131946DULL, 
            0xBDF50CF1DD397F5FULL, 0x91B73D0846E0CB1EULL, 0xBC646DD4ED115CCEULL, 0xC4BD21C6030B5172ULL, 
            0x215BD112EC998444ULL, 0xA13A443D95943CDFULL, 0x7E90674167B8849EULL, 0x92B87D83AE190097ULL, 
            0x04C3110B011EB37AULL, 0x4921475946451F2FULL, 0xA1E059204194E111ULL, 0x4059AE85F07FF5D0ULL, 
            0xED0F5228E8BE7F26ULL, 0x208CE64B7F5A45DDULL, 0x11D7DEE686D1A665ULL, 0xC1F02CA2A8F45A40ULL
        }
    },
    {
        {
            0x90CF0A85173DC294ULL, 0xCBA45BAB22937012ULL, 0xE3B87CD88438B400ULL, 0x6D333535B534E2C2ULL, 
            0xC6A04F2FE5D869F1ULL, 0x0960EB8FDFEA28FFULL, 0x4E724713FD5A0EE0ULL, 0x018AA03386CE397DULL, 
            0x9507E268C689B5B4ULL, 0xCA6E57C2FC2F64EBULL, 0x03BF95D6B47107E5ULL, 0x06A01696B9EA98FBULL, 
            0x316FCC7AC5FAFC29ULL, 0x3902514E102BEFBFULL, 0x67FB4C70F5361A2AULL, 0xA7D734EF1928CBD4ULL, 
            0x3F75626465A8CD74ULL, 0xEF2DDC0A953CFB32ULL, 0xAFAADF13257152DBULL, 0xE1DA6DDE8B3B8352ULL, 
            0x0E227CE9B9B81FF9ULL, 0x67B3E015CD2BD95EULL, 0x41ECE5BE4C2CC43BULL, 0x72D7EAF66C07FB7AULL, 
            0x048663A849259057ULL, 0x53B36EEC7A0C24B4ULL, 0x8BC38925BAEAFDBBULL, 0x55643CCAD04977D0ULL, 
            0x48527398C3709A07ULL, 0x33041F4C8C8430B2ULL, 0x4D5B1B3B3B71E0B1ULL, 0xFFFE8C857FA481AAULL
        },
        {
            0x52C2AD4E5A9871CBULL, 0x7425D6EB21A148A6ULL, 0x817C91F89F0CFCEFULL, 0xAAA8E3F3566969A3ULL, 
            0x9E1AAE2B467FBFC7ULL, 0xB3A0902D1462CA8EULL, 0x5F4E99768D28599FULL, 0xEDF1FBE42B66FAE4ULL, 
            0xA4B76A417F1B47A4ULL, 0x09AC99FAE923A766ULL, 0xD4721D845F983BD2ULL, 0x2E6B2BCA83F51678ULL, 
            0xE0C1449975599892ULL, 0x00BDED7C40F70EF3ULL, 0x9FFE340448DA5783ULL, 0x29EFD1BC3F4AB229ULL, 
            0x416C9D675853432DULL, 0x0AC10957B41030F6ULL, 0x074DE3B5360D5A2CULL, 0xB2D6261769F52F3DULL, 
            0xF55F711C0574F76FULL, 0xF3402E88B6518DFCULL, 0x4B6FCC909FFF78B2ULL, 0x5C2D8D01F996D406ULL, 
            0xBA94971081C2C7D3ULL, 0x7571ED4AA2B1B1D0ULL, 0xDCED8005998C35DDULL, 0x729D400AA7423891ULL, 
            0x649B8C9F962A7CFBULL, 0x15AEA5F8A28E1795ULL, 0xAFB6DE19A177CCD4ULL, 0xDEFF89293C8F22FCULL
        },
        {
            0x0086EFAE4D48AD21ULL, 0x0B3EFABE3E06C135ULL, 0x0CE6256983F06660ULL, 0x2409B678BC8240F2ULL, 
            0x4EF7AA9A4CED2931ULL, 0xE550DC899AB78132ULL, 0xB422951AEBAB676BULL, 0x618CB2B8F0B6FB0FULL, 
            0xEDBAB398F64D97F9ULL, 0x235428D95638F838ULL, 0xDE164109CC3322D9ULL, 0xD2A31611FBB9C5C8ULL, 
            0x89DC3209FB84AB47ULL, 0xE53CA0A49ABD26BCULL, 0x38139A7309E07891ULL, 0xB1AC75F63B19CEA5ULL, 
            0xFF3F1CE4AA0701F2ULL, 0xE82D3253B5DBAEC1ULL, 0x8F214F5BA23A3578ULL, 0x4695374187263728ULL, 
            0xDFDE40069E3DFFAFULL, 0x85E5C0E7409CB4E8ULL, 0x25BCEE0F82B06046ULL, 0xDB591E90E1C0A7F3ULL, 
            0xA97444C1C1D0198EULL, 0x34973A004824BCE3ULL, 0x5A888786B63236F7ULL, 0x73A97CB08713A79BULL, 
            0x83AC7490785C2570ULL, 0x1BC447AF55764EBDULL, 0x9DBD6B1B05C559F0ULL, 0x6E73CFFBFF533AE1ULL
        },
        {
            0xDE6E1BE9AF9968C4ULL, 0x09D67AECD1AB1F67ULL, 0xE16ED4DA9A9D1517ULL, 0x9A073135E8F663C5ULL, 
            0x42D076DE3C716E05ULL, 0x9BDBC98E5B303E52ULL, 0xADF4CE9DD4AA073EULL, 0x41017FA7BBEB4605ULL, 
            0x8BC1792B4DFB4375ULL, 0x84C8BEB47058595FULL, 0x94004CCA4BDBB235ULL, 0x2817F2E62287970FULL, 
            0xBF7832005854E664ULL, 0xD4C6314D061556ABULL, 0x51104C6B0AEAF856ULL, 0x9F72BB0D92DA117DULL, 
            0x73F64B45D88098CEULL, 0x454EC6B54FBAE180ULL, 0xA0896042805AF5A7ULL, 0x552339E33494D5C2ULL, 
            0x99088FE00BE28CF0ULL, 0x986BDE779264CD40ULL, 0xFFACBD80106AA0DEULL, 0xA956EB774E9636B6ULL, 
            0xA11A17BA97457E0FULL, 0x451F84134D138B2AULL, 0xEAAA092F8C2BC01AULL, 0xB51486675F040DFDULL, 
            0x929281F2FBF10243ULL, 0xD78F74FE1AB39E5EULL, 0xE6E7C584F8B4CE1AULL, 0xF17892B3C5AF6ED3ULL
        },
        {
            0x0C4ACF01D7211845ULL, 0xD7588D484747EB90ULL, 0x48FFC9F1F2AEFD36ULL, 0x01E33A0D50EAC38FULL, 
            0x7A7145419E7224F0ULL, 0xA4C1DB09A440280DULL, 0x91B27CED05A69470ULL, 0x706F11EEA05FA161ULL, 
            0x56C89981CA9519C9ULL, 0x795A1EBFEF105011ULL, 0x1B0422F22E5C450CULL, 0x7FE8A5FE739A5D4AULL, 
            0xBA71A5F87FA12EABULL, 0xB4B5EBDA98C28DEDULL, 0x3D651675205645EEULL, 0x5249B5AA007992F8ULL, 
            0x36F60963744BB758ULL, 0x1B179E785AC68C18ULL, 0x2A38D0B96910B7C4ULL, 0x7C1C5985A7CEAD43ULL, 
            0x995E0744D4EDE667ULL, 0x56AFBDB06BE66116ULL, 0xDD21695E850E8CDBULL, 0xA457CBECBD3D16ACULL, 
            0xD473B8685B692A40ULL, 0xEB5ADEC2A471B461ULL, 0x4A4B7D9ED3F78D16ULL, 0xCC4435D88951B961ULL, 
            0xD02872DF4F64298AULL, 0xFFEA2D7670D63856ULL, 0x3B31DB39E32FFC58ULL, 0xCBDF111F91C02AF8ULL
        },
        {
            0x5ED4843CCC921E38ULL, 0xE9EEB6858D6E0D0EULL, 0x7B7812972C839509ULL, 0xB858ECD4364C2265ULL, 
            0x47949D84B53920E6ULL, 0xEF40AF25D538DFEDULL, 0x23DCABDD3DC9BA87ULL, 0x51BFD9CEDD591DC5ULL, 
            0x6C3FD1C9A72F5649ULL, 0x51C60530B407205EULL, 0xE899FDD1B56B8136ULL, 0xA1D0D939D5D01228ULL, 
            0x2BD9EEC400EF5F79ULL, 0x0765809CF4051E8CULL, 0xB3E9F57E84F24549ULL, 0x2A245E62E14D6A67ULL, 
            0xE69FDF65F1D6251EULL, 0x131F5B7F3752CB8EULL, 0xE21494D0BF15896FULL, 0x3F0F211FDCCE7EFDULL, 
            0xDEC74A0431C51A62ULL, 0x8DFEDFD855130766ULL, 0xC7C0FF673584B8B9ULL, 0xE8D03F264F529CDFULL, 
            0xFC91CCF289B75C9CULL, 0xCE8E95D33808CF7AULL, 0x688F52A259CD69B1ULL, 0x1B55DA28D4134D78ULL, 
            0xF1C2F0CCA09B8D80ULL, 0x958875B3DC2C843AULL, 0xBE986D51131C7784ULL, 0x41CCBDD0A3B7C0F9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseHConstants = {
    0x2BE50E16B6C8DFCAULL,
    0x7DF3D8CCAC0C0C55ULL,
    0x1629639BB7B6BF84ULL,
    0x2BE50E16B6C8DFCAULL,
    0x7DF3D8CCAC0C0C55ULL,
    0x1629639BB7B6BF84ULL,
    0xE698D3C6456555EEULL,
    0x9E000EDE2643AE50ULL,
    0xF9,
    0x6E,
    0xBF,
    0xC5,
    0x11,
    0xE0,
    0xC8,
    0x58
};

