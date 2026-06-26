#include "TwistExpander_Lacrosse.hpp"
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

TwistExpander_Lacrosse::TwistExpander_Lacrosse()
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

void TwistExpander_Lacrosse::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 15931613614915531667U;
        aCarry = 11669464054545285057U;
        aWandererA = 15946757221783169907U;
        aWandererB = 18094139679136214309U;
        aWandererC = 18150243828576540284U;
        aWandererD = 16010621801476473693U;
        aWandererE = 15897599716470751868U;
        aWandererF = 18017401823216535135U;
        aWandererG = 9627355268246880820U;
        aWandererH = 12931144323624267533U;
        aWandererI = 12157052763320117630U;
        aWandererJ = 11490965034556107354U;
        aWandererK = 15293884646914025416U;
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
    TwistExpander_Lacrosse_Arx aArx;
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
    TwistExpander_Lacrosse_Arx aKDF_A_BArx;
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
    TwistExpander_Lacrosse_Arx aKDF_A_CArx;
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
    TwistExpander_Lacrosse_Arx aKDF_A_DArx;
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

void TwistExpander_Lacrosse::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 9872450309181346078U;
        aCarry = 15390512319287247714U;
        aWandererA = 12281900239794643468U;
        aWandererB = 14604684874041812601U;
        aWandererC = 12370451925356087569U;
        aWandererD = 14036504662003650538U;
        aWandererE = 16888608290850690877U;
        aWandererF = 17569982078927679301U;
        aWandererG = 14393900523892182982U;
        aWandererH = 10118484652903142305U;
        aWandererI = 14360335138217759286U;
        aWandererJ = 10032801054581221359U;
        aWandererK = 10067178244294182327U;
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
    TwistExpander_Lacrosse_Arx aKDF_B_AArx;
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
    TwistExpander_Lacrosse_Arx aKDF_B_BArx;
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
    TwistExpander_Lacrosse_Arx aKDF_B_CArx;
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

void TwistExpander_Lacrosse::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAA86467E676D6233ULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xF20BB7C44EC079DBULL;

    std::uint64_t aWandererA = 0xF365C88D35B63F71ULL;
    std::uint64_t aWandererB = 0xD8623DDC36109514ULL;
    std::uint64_t aWandererC = 0xEBFDE61527C8FE32ULL;
    std::uint64_t aWandererD = 0xEAF6F5143BAD50FDULL;
    std::uint64_t aWandererE = 0xD543F0B2E25DF6A9ULL;
    std::uint64_t aWandererF = 0xE9D517E5A4719ADCULL;
    std::uint64_t aWandererG = 0xF1B6BBA56C8755EDULL;
    std::uint64_t aWandererH = 0xF1B12B9D96F547C1ULL;
    std::uint64_t aWandererI = 0xCC6CF718B4BE8BA6ULL;
    std::uint64_t aWandererJ = 0xEF1C6FE686966BF4ULL;
    std::uint64_t aWandererK = 0xF4411C356E8BFA6BULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneH);
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
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA);
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    TwistExpander_Lacrosse_Arx aSeed_AArx;
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
    TwistExpander_Lacrosse_Arx aSeed_BArx;
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
    TwistExpander_Lacrosse_Arx aSeed_CArx;
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
    TwistExpander_Lacrosse_Arx aSeed_DArx;
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
    TwistExpander_Lacrosse_Arx aSeed_EArx;
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
    TwistExpander_Lacrosse_Arx aSeed_FArx;
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
    TwistExpander_Lacrosse_Arx aSeed_GArx;
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
    TwistExpander_Lacrosse_Arx aGrow_AArx;
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
    TwistExpander_Lacrosse_Arx aGrow_BArx;
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

void TwistExpander_Lacrosse::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Lacrosse::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 12409779313178228437U;
        aCarry = 11379936739977644033U;
        aWandererA = 18065971764341297788U;
        aWandererB = 12645980428495769696U;
        aWandererC = 12538707095540917432U;
        aWandererD = 11652260853561812586U;
        aWandererE = 12833020839282546812U;
        aWandererF = 10289450573616677194U;
        aWandererG = 12001248342962627038U;
        aWandererH = 9253797312437813674U;
        aWandererI = 17247766116817539629U;
        aWandererJ = 15803639484423352232U;
        aWandererK = 10147983529674824847U;
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
    TwistExpander_Lacrosse_Arx aTwist_AArx;
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
    TwistExpander_Lacrosse_Arx aTwist_BArx;
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
    TwistExpander_Lacrosse_Arx aTwist_CArx;
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
    TwistExpander_Lacrosse_Arx aTwist_DArx;
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
        TwistExpander_Lacrosse_Arx aGrow_AArx;
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
        TwistExpander_Lacrosse_Arx aGrow_BArx;
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

void TwistExpander_Lacrosse::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 1, 1 with offsets 4034U, 3706U, 7234U, 6083U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4034U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3706U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7234U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6083U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 2, 0 with offsets 6515U, 5189U, 7625U, 5387U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6515U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5189U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7625U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5387U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 3, 2 with offsets 3684U, 7459U, 6465U, 1966U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3684U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7459U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6465U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1966U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 0, 3 with offsets 3709U, 7707U, 2206U, 4655U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3709U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7707U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2206U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4655U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 0, 1 with offsets 776U, 687U, 1540U, 1732U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 776U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 687U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1540U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1732U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 1, 2, 3 with offsets 2033U, 748U, 707U, 1345U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2033U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 748U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 707U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1345U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 3, 1, 0 with offsets 2003U, 45U, 650U, 1381U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2003U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 45U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 650U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1381U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 0, 2, 1 with offsets 563U, 838U, 1788U, 1189U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 563U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 838U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1788U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1189U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 913U, 109U, 1182U, 497U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 913U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 109U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1182U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 497U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Lacrosse::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 2, 3 with offsets 6832U, 1577U, 1025U, 2083U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6832U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1577U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1025U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2083U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 2 with offsets 4731U, 1683U, 3115U, 6070U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4731U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1683U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3115U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6070U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 0 with offsets 1796U, 7286U, 7150U, 7555U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1796U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7286U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7150U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7555U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 1 with offsets 3526U, 1075U, 5994U, 5993U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3526U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1075U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5994U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5993U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7445U, 3477U, 502U, 326U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7445U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 3477U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 502U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 326U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 485U, 636U, 1222U, 82U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 485U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 636U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1222U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 82U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1458U, 651U, 863U, 53U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1458U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 651U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 863U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 53U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 980U, 1258U, 1361U, 2009U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 980U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1258U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1361U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 2009U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1864U, 1297U, 1551U, 91U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1864U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1297U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1551U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 91U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 1, 2, 0 [0..<W_KEY]
        // offsets: 1822U, 1447U, 1008U, 964U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1822U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1447U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1008U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 964U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseASalts = {
    {
        {
            0x31D225DA8B3D0B04ULL, 0x8BAC4948D2813032ULL, 0x8067638A0A4EF63BULL, 0x20CE733BC44BC187ULL, 
            0xC26435A4EDE90778ULL, 0x61BFF059DD293C10ULL, 0x3D00532AF11A970AULL, 0xBCB144711D31E3E9ULL, 
            0xB72455FEA94BD854ULL, 0x8B8B8E029BF5BB1DULL, 0xC5ACF0577A71442AULL, 0x18097FD6E492BA14ULL, 
            0xED53A6EEA8F7E95FULL, 0x4699FA38E61B4158ULL, 0x8A869DB5D3513CFEULL, 0x5D81349DE09A7CCFULL, 
            0xEF1D4C044757EAF1ULL, 0x3BA4432C2F525962ULL, 0xB4CCBE8E536CCBE7ULL, 0x6EF7000F7852C579ULL, 
            0x110B0AF647EDED77ULL, 0x9BD91E06439843F8ULL, 0xA462B728A995A069ULL, 0x98F11E7DFFD2D178ULL, 
            0x7141AEABB0764812ULL, 0x4828E3070EBB8B8EULL, 0x3E6B88F623317BBCULL, 0x297C780131F8922BULL, 
            0xD3C4AA2567E1A5D3ULL, 0xCEFA0161EC999F12ULL, 0xCBAFDD6CBB6B0935ULL, 0x4DA666178221A7FEULL
        },
        {
            0x749D0AA540C7563AULL, 0x5EE39DD1CB49C6B3ULL, 0x1B33241F31775724ULL, 0x1E33D1B260330616ULL, 
            0x807B5E2B0C691F07ULL, 0xC9750BE15886EE0EULL, 0x01B9F7962BDEC58BULL, 0xEB02D9BB0EA013D0ULL, 
            0xFC9E5C0DF118E10BULL, 0x374225A9B0F33BD7ULL, 0x7D2D7157CA80773DULL, 0x9D631B24866DAE7CULL, 
            0xFBD6B1D54E0FF2B7ULL, 0x5617FDD37174339AULL, 0x02590878D0EFFF24ULL, 0x5F6E11CE0AAB4DB9ULL, 
            0xCBF1354EF81C9A89ULL, 0x719D4060BAC68DC6ULL, 0x8FAF38A84E772B0DULL, 0x4A0C4EDC557136E0ULL, 
            0xC4B3C4A32DA46E80ULL, 0x4BD7B0E8FCB72D42ULL, 0xCA165673D4F26AADULL, 0x1B01973A3D7D5DD0ULL, 
            0xE3C5294D8B1B822EULL, 0x008733E9C1FC36FAULL, 0xFAA872BAC90317EEULL, 0xCD2D081F8B490DCAULL, 
            0x8B721FDD91C8C8A1ULL, 0x0DAB8044C941155AULL, 0x2D34A2B1E7337FC6ULL, 0xA3419C961B1ED453ULL
        },
        {
            0x40B2438274ACCFB3ULL, 0x8C635B888B1A3CFCULL, 0x0074657B8ACAA7A0ULL, 0x6FA3417EE9E9EDB8ULL, 
            0xE200B464B457DDA4ULL, 0x61EAE1E8845C4F80ULL, 0xC57725E891C781EEULL, 0x059FC6CA775023EAULL, 
            0xF1FAF883C39E62E8ULL, 0x84B2239937975C76ULL, 0x32FD25FF2D137772ULL, 0xC735D2166A4F69C4ULL, 
            0x98EB3A84F12136F6ULL, 0xDF8897A0C1B11350ULL, 0xFB15AD74BC958868ULL, 0x1255A431EEA641E7ULL, 
            0x74D84435711E7880ULL, 0xAD1C3FCB7D85DC5AULL, 0x6071D0E46D5A6B6EULL, 0xDD053CE4C5CBF5DDULL, 
            0x02FB354F2468C960ULL, 0x182767EA73371FD7ULL, 0xAE1792F710111DE9ULL, 0x834376526C2DA362ULL, 
            0xE5C11BE1D6BA1C1DULL, 0x1A90E1015A0C3BFBULL, 0xDCB4F356EC7EB4A7ULL, 0xDD6AA00245F0BA61ULL, 
            0x2A82D19EE9835FB4ULL, 0x4F5B5EEE2AB63AF8ULL, 0x7EF1A2CA026DA4B5ULL, 0xFA28FEC38DC2DBC8ULL
        },
        {
            0x5442A69C49E4D487ULL, 0x66E56DE2E44FBB86ULL, 0x9A3F5EEADD48691DULL, 0xDA29EA3011F93EA6ULL, 
            0x8E7B0A7B8037FE56ULL, 0x3DB401886A74A30FULL, 0x8D83B78A10DC7736ULL, 0x664C6EE2B4CC12B6ULL, 
            0xD7F6954CA632242DULL, 0x70721174CC8A21E8ULL, 0xCDF871595083816AULL, 0x41932BA1470B0BB0ULL, 
            0x7756BFC4553F13C1ULL, 0x95CFBE6532FDCFBBULL, 0x42C3D6FB87695D81ULL, 0x25897C191CB2D0EBULL, 
            0xFA0BFE24A52E1792ULL, 0x6D595665D9C2C474ULL, 0xE4CA481A051D74E1ULL, 0xC908A3563A988405ULL, 
            0x95BB9DF031A03291ULL, 0x7A537AE1B6822B27ULL, 0x7374587647E0C91BULL, 0x4F7031335361D94CULL, 
            0x313BF8E03AEDEF28ULL, 0xC0EB15F40ED63790ULL, 0x605090AF41E66EBEULL, 0x9EFE79DB4643FDEEULL, 
            0xF0F3FB6F1EF92339ULL, 0xD79989B07F434433ULL, 0xE5790F78A0AC67D5ULL, 0x67C91FC551ED6856ULL
        },
        {
            0x3142EDA29303D31AULL, 0xF0DB7D0035161B22ULL, 0xD747222B23D03559ULL, 0xF733A041246A2067ULL, 
            0x2734207A8C0F66E7ULL, 0x5E0989916F9C4401ULL, 0xC121C1D5A72CA39BULL, 0xB365790C93BABD7FULL, 
            0xC88E73C0D9628694ULL, 0x47BB6E505FAB61E4ULL, 0xBF95D5FB63853F1AULL, 0xFDB21D7BC7D39C51ULL, 
            0xF10024E2E18E801BULL, 0xC36EF7049F718573ULL, 0x610896764FCC8247ULL, 0xCEE15036960F27D2ULL, 
            0x694152B0801E224EULL, 0x0532ED9ED635DF4AULL, 0xE64C727B02448367ULL, 0xC09AAD15AF6AF521ULL, 
            0x53E043726D1F7D24ULL, 0x4C13DB63EE0FBFFEULL, 0x9F00B4A8D34B7A4CULL, 0xD8DC04FA70601259ULL, 
            0x43D5454A6B9C551FULL, 0xCA39679F574D3CB8ULL, 0xDD8D0F949F216B88ULL, 0x62E4D2F1FF58D4D9ULL, 
            0x71FE4510998FB303ULL, 0x3F5966B1CBB50AE4ULL, 0xB35D868009D3948EULL, 0x75B8E987388BA3ABULL
        },
        {
            0x94283FC2E8819900ULL, 0x508490DEE41E7143ULL, 0x9D5F9B6C51DC53C0ULL, 0xCAC5DA6B22CD8835ULL, 
            0xA1FC33EC150B5F19ULL, 0x5EDF6CDEBB05D3D8ULL, 0x824A0F2FEFBFB49DULL, 0x64BD6920DF7A004BULL, 
            0xD6EBED7D75E010A4ULL, 0x1D893D9978EDE98DULL, 0x221964B7949932C4ULL, 0x0206B1A94822B5B8ULL, 
            0x7991030922154377ULL, 0xF133E6F420054975ULL, 0x49E21130B39E958EULL, 0x56558639C38491C8ULL, 
            0xD8556BEB76BB142AULL, 0xE39595615E115B81ULL, 0x6845F142D79E5E11ULL, 0xF93AA230F16D345CULL, 
            0x7F83AE3768743A00ULL, 0xED90990D4C6C1E26ULL, 0x48CB473B9EA0BB1DULL, 0x13AC2AF4B1824216ULL, 
            0xCCA50A52DB89AC8BULL, 0x65BC912A738E2F68ULL, 0x6A6B4E45C431138EULL, 0x611995B8FC41B7CAULL, 
            0x37848C601B22EFFBULL, 0xF16CFE50EBC91352ULL, 0x42BFD939AB069B59ULL, 0x9884FD9B7D360678ULL
        }
    },
    {
        {
            0xF088044411714301ULL, 0xA51C76BB78489954ULL, 0x191A6BF178FD67D4ULL, 0xFCB53DB56CA4C036ULL, 
            0x4B01AC39C6B36E85ULL, 0x3C027D6C2EE3767BULL, 0x937A95077B88A185ULL, 0x64358BD5E5BA3B66ULL, 
            0xA449FA6257D27C6CULL, 0x48A5DF8348A13877ULL, 0xA3AF4F8EE39728FEULL, 0x621037FE94D60988ULL, 
            0x9DB5DF01267C06E9ULL, 0x19BFF66751043D8AULL, 0x5BE5D1CE67A61B75ULL, 0x6B79695F1A49FB94ULL, 
            0x7412932C0228ED10ULL, 0x786250C16AE054DBULL, 0xEAAFA20E2903F4A8ULL, 0xA206B6660F084DCFULL, 
            0x65A47F5C244F44F0ULL, 0xF5EA7ACF1036B1FFULL, 0x110860A5E8D94FA2ULL, 0x399CCADCE224AD87ULL, 
            0x076E9CAC473972D9ULL, 0x74662F18F268E3C5ULL, 0x0701332060773C8EULL, 0xBF569443F4F3BE8EULL, 
            0x0F5830DD55389CC8ULL, 0xE5BE701858A185D5ULL, 0x1DCA3B16791EB856ULL, 0xC59AFB46B25D2C2DULL
        },
        {
            0xB9FAEC86E7B69EADULL, 0x7E6ED217B6817CD7ULL, 0xD70E0915B60614E4ULL, 0x3DDD7EA5D56D9287ULL, 
            0x20FF8BE53A3C9A47ULL, 0x5FADC27403A2176FULL, 0x899D44E0B62BAD2BULL, 0x24A8A3A7E88996C9ULL, 
            0x174F3CD03C4CA99CULL, 0x0BB180D76BD6FE31ULL, 0xF13E2904082F8245ULL, 0x7517C1219D7D66ABULL, 
            0x8E59B77799D8CF50ULL, 0x1FB0D4982E56F2CEULL, 0x5038683E4D85B78EULL, 0x1AF5833700D4BCB4ULL, 
            0xF8B63209F0183AB3ULL, 0x6F8E49DCD4F3E09AULL, 0x75AD0557FD84C8E2ULL, 0x52147993C504F8D2ULL, 
            0x18527069AEC38271ULL, 0x9AC3EB9C1AF088C5ULL, 0xABB95EA4A4079B97ULL, 0xA7124E11FBDF2E83ULL, 
            0xFCA3646DB5F33F3BULL, 0x248262C88D46E152ULL, 0x495D27B63BCFBE32ULL, 0x6B595182398804C5ULL, 
            0x51990FE0E2FFE1ABULL, 0x85AC4382735E1A18ULL, 0x1BE7E619FF434C0DULL, 0xADB0DE4BBFE478AAULL
        },
        {
            0xF9F00B085B86221CULL, 0x994292C903DFBE54ULL, 0x8DB074592F213DE9ULL, 0x51888AB2D13B4F61ULL, 
            0x976ACCDB353E5935ULL, 0xD60608BE35A31473ULL, 0x94E61F421978B5BFULL, 0xCC42CD4B2470441BULL, 
            0x6955FEF759DE23C3ULL, 0x409875657DF3005CULL, 0xFDC9D7FDF1A7A23CULL, 0xCBCDF9334A2CA961ULL, 
            0x61A10710A531DBC4ULL, 0xD41239CBF4AC0128ULL, 0x9DF015B3F19B30A9ULL, 0xAFE4789D567B0163ULL, 
            0x9447BFCC82AB3904ULL, 0xA561255D032A40FFULL, 0x97FF4EF295C57863ULL, 0xA983AE13CD99BB7AULL, 
            0x50E9BDFBD55C5DAAULL, 0x8BEDE7332C172AFBULL, 0x9B64E9149D5CB0EDULL, 0x6C919418E16CD31AULL, 
            0x3A6F38FABD337409ULL, 0x32F1C2A893283624ULL, 0xB40169770B651A80ULL, 0xB62FE508EF70B6EBULL, 
            0xD5C52C417FA56641ULL, 0x08300A0B7598BB48ULL, 0xBFCEF56F6A5D6B60ULL, 0x1426D7C20ADD116AULL
        },
        {
            0x7CC0470986D65A40ULL, 0x704FC577EBC388F7ULL, 0x15A3EBB38412EB4FULL, 0x9F23CCCD0BDDD7CDULL, 
            0x3E72A1D73E350108ULL, 0x1A12F8CFB35530E8ULL, 0x0DDD08DA9E9CFADDULL, 0x963B72E83DC0F8B6ULL, 
            0xBE87493B2EB039E7ULL, 0xC6098CE9DA915C7EULL, 0x1DF853E89DA719E9ULL, 0xCB0994FB424B318BULL, 
            0xD75B47A9915D2BECULL, 0xDE0FED815D827E2BULL, 0x02A5C4E314CC753CULL, 0x50D5FD7B7EFF0763ULL, 
            0x7622EB241E307383ULL, 0xC1535EF23DA19AA7ULL, 0x50CFD8DC7BFD87ABULL, 0xA94626FD0EBBC170ULL, 
            0xFFF180E9DF47F249ULL, 0x12B4C96DEAD6A76DULL, 0xA83BBB4933369118ULL, 0xA98437E8A0A86A97ULL, 
            0xDF6B1CF6511E97BCULL, 0xEC8984DD293AB308ULL, 0x8C2F84FA52C9B9F0ULL, 0xD646048B8D3DCDE7ULL, 
            0x0BC6AC39383A7AA9ULL, 0x118A081B32F33CB8ULL, 0x59E2B5ECA5E1A259ULL, 0x86526B461C3B7AA9ULL
        },
        {
            0x66E4EF1479EC4D48ULL, 0xD035EB3A58A9822EULL, 0x8B90389E7D49258BULL, 0x8081BCCCDD5681FDULL, 
            0xA4B171B9F5711B3BULL, 0x5B49C0D5E1E0A373ULL, 0x1685ECFE2FDF5C99ULL, 0x9F1F31D4DEC877A6ULL, 
            0x937C16B5DC10F122ULL, 0xFB67AC53BEEE97E2ULL, 0x365C32E29D0F5A1BULL, 0xE090B2F5D7974764ULL, 
            0xF2C2CF051458DEB1ULL, 0xF2A2971CE2C7CB5DULL, 0x2BA79E2D9B134E72ULL, 0x33C2D5B5706E778FULL, 
            0x953347A891A983D4ULL, 0x4630E131F5F1CC03ULL, 0x45006AB7704F8D40ULL, 0x15858D025933861BULL, 
            0x45A9BA742C172A5DULL, 0x80F8A96DDA172EE5ULL, 0xF259217DC2388AFAULL, 0x44F7204822067523ULL, 
            0xAB294FDD8DE4F265ULL, 0x8FD43C59276F07D5ULL, 0xFFB1080908534735ULL, 0x1ED201D364DAE04CULL, 
            0x30F183D1BD861DAAULL, 0xD77F24018ABFBBC7ULL, 0xE8323BD46C342D12ULL, 0x8374E875183954C0ULL
        },
        {
            0x50E8D196137D26F4ULL, 0xA79F2EDA1A29533CULL, 0x6330A3FF5F1F0DF4ULL, 0x85E62D038F1943E1ULL, 
            0xF4BC80011F1779A7ULL, 0xF3B4DA4CBC069E63ULL, 0x9C61855A917B5A4BULL, 0x66936CC6D8AB1EE8ULL, 
            0x5B6F3BC61C46B574ULL, 0x12BE4709BFAD98F3ULL, 0xBCAF2428D6C6F4A9ULL, 0x59016C83F2857ECEULL, 
            0xAA6D4FB8D66CE2CEULL, 0xB0B3F17A83FE6F2FULL, 0x133A5AAF8854738EULL, 0x537933DA275A6AB5ULL, 
            0xB5505FC62A58E7CDULL, 0x078FF6D3398E881AULL, 0xB7E0187C962E3E3FULL, 0xBC346967C0F5CABCULL, 
            0x1F16CCD4C7243D2DULL, 0x97AECC73EB1D7F38ULL, 0xF9D2FE6C2A427F39ULL, 0x767C5A27AD4EFF5DULL, 
            0xE76BBFD54D95E3E3ULL, 0x9F80392360FA3042ULL, 0xFF25C8472D100EB4ULL, 0xCB7923A6DC318EF2ULL, 
            0x616F25DBC34AD606ULL, 0xAA29A5E59A0FFF14ULL, 0x6003ABD5B41B4250ULL, 0x80E500011B474003ULL
        }
    },
    {
        {
            0x695058FFC54E33F3ULL, 0x19E7B71DF7E07E0CULL, 0xDEB48E540BB6EC9AULL, 0xAE7F066F76E37DC2ULL, 
            0x28C5923B1D12B536ULL, 0xE6A703409AEE9978ULL, 0x550432CE78A8E5F5ULL, 0x258410DA30C96601ULL, 
            0x11306F651EAA7BC5ULL, 0xE03D423967BD7546ULL, 0x1021DE5B6362B996ULL, 0xE1AC188F387A70B1ULL, 
            0x9880D25C0675EC0AULL, 0x5E7E0503B5F6A820ULL, 0x2DFC1856CBB45500ULL, 0x33009CDED9CE4C0BULL, 
            0x23867749B5523454ULL, 0x961525D11025D779ULL, 0x8BA952FCE811C43AULL, 0x0A2F2819114C9C58ULL, 
            0x834C3CA3C8FB0946ULL, 0x0522462BABFAD171ULL, 0x0F3A367E0D4A9A56ULL, 0xFBF09EC58FB703E8ULL, 
            0x1F0A19501BACA1B0ULL, 0xF1643E67AFFC4552ULL, 0xFE97AE17287577F1ULL, 0x6474E876AA3C7E9CULL, 
            0x86A101CCA87C3C25ULL, 0x005504A48747E673ULL, 0x30260609FE856CA2ULL, 0xF7276FA39E7FD3FBULL
        },
        {
            0x43062BCD6FFF03C2ULL, 0x142BA8E0A2CA7F0EULL, 0x918277B75F3528B2ULL, 0x9C3DCD683E304B4EULL, 
            0xE85753E868C8C7E3ULL, 0x5116F7E2A6B46812ULL, 0x52722F956BC8AD2AULL, 0xDD1CDC719CCF480AULL, 
            0x484D5DE18C9036F1ULL, 0x0BC761E6CDAFEB12ULL, 0xCC35580E50F5C3D9ULL, 0x02AFC62F799BFC37ULL, 
            0x4A74DCFD02A2BED1ULL, 0x9C3D1EF23C9B761CULL, 0xC2D842A909F720A1ULL, 0xAB8F0D7485B9DD5DULL, 
            0x70CEA087FAC4F556ULL, 0x2F4D42A8BC9ACC7BULL, 0x982EA4153681A40CULL, 0x02038A676B60EC08ULL, 
            0xD08A86BDF76137D5ULL, 0xF79B92A06B064279ULL, 0x369DAC749F9752D0ULL, 0x483B821F100FDAB4ULL, 
            0xA04E34CB1474F505ULL, 0x30884F3BAB9B112FULL, 0xAAC1408C829CD6C0ULL, 0x11778A509E75E2A0ULL, 
            0x482F37923FF61546ULL, 0xE9B5DC8D63297350ULL, 0xBED50FE5CECD0BF6ULL, 0xF88509E5198ECA16ULL
        },
        {
            0x3068B107FE271796ULL, 0x4F2CF5C3E74642EDULL, 0xEF18D9386E98AD68ULL, 0xC77F1F18766637B6ULL, 
            0x9E59DA89A94D7C00ULL, 0xED0A269F4458D843ULL, 0x857B472173C39C31ULL, 0xAD69011ACEE11206ULL, 
            0xB7A05B8EF617AB32ULL, 0xF19E866DF62D49CDULL, 0x6BDA359EEF602C9FULL, 0x7F7CB107CEEEF0FCULL, 
            0x92A44752553F7247ULL, 0x9FB6022E69A9C909ULL, 0xF8818D9E9F92CA1EULL, 0x9FC93B9C27F9613AULL, 
            0x896F8AA8C20AB3DCULL, 0xDC12A0B3F61543CAULL, 0xE64B0A92E4EC71DDULL, 0x9F9495E1A8D44301ULL, 
            0x5EE2D47AFE1977BAULL, 0xB06A653A3251797EULL, 0x8F63272E1D5FD692ULL, 0xDBD3C4C40030EB15ULL, 
            0x344CEF9D2A5A9F76ULL, 0xD41F4932EF70675BULL, 0x98E4D30C1E71AFC7ULL, 0x4EBF1D7B47C468DFULL, 
            0x91C16E5CF47F4AE3ULL, 0x76F7F263BEF6F4A9ULL, 0xF91C520652B0C145ULL, 0x38F6899E49D76E0BULL
        },
        {
            0xBC6524F7246FFA53ULL, 0x56865EB307B8BA69ULL, 0x4DAB73E83FC60D3BULL, 0xB8B9D2137067E59FULL, 
            0x9F2CFA55F86EB87EULL, 0x547A2C52E34767B8ULL, 0xBA189065A7814E74ULL, 0x70AC25A479BB4ADEULL, 
            0xC1FD75215BB4B8B0ULL, 0x86007EEADCDBBA19ULL, 0xE72ED793B6097A45ULL, 0x165522E31D9CFC8CULL, 
            0xB3799EEA22EDE343ULL, 0x6FF0621224B5DE8EULL, 0xB8EB42AA9364339DULL, 0xA96BFB497510554FULL, 
            0x9BB9F84B5E1C9C5BULL, 0xFA8A37B905CBA01EULL, 0x38A91F59DFADD1FEULL, 0xE4E2A89E5F15981FULL, 
            0x2732E9D5888F544EULL, 0x3895A57567CC4682ULL, 0xE3B0C6DD104CC01DULL, 0xAB0107099A9D5947ULL, 
            0x3BDA909CDD315EE2ULL, 0x5FF0627E4F87E506ULL, 0x0B9113C4ABE72FC4ULL, 0x2E811E5681431DACULL, 
            0xAE7F85501A4B3C13ULL, 0x964CFA41CCE596C4ULL, 0x056ED89442C66EB1ULL, 0x58C6E4356DD6FF93ULL
        },
        {
            0xDC9B66710AAC861AULL, 0x6FC4A64A9E2B5271ULL, 0x3769C13676396C3DULL, 0xE3FD9F59D4CD20F4ULL, 
            0x19C49EDC9B666C00ULL, 0x3E3B1A247F10AA3CULL, 0x5A3F3867AD52BB0AULL, 0x1194C8EA7A084AEEULL, 
            0xDAEDB9928703A665ULL, 0x36BD6597617F51AEULL, 0xA2D7507BC3EC78BEULL, 0x336C69F4251A725AULL, 
            0x0926BDE4CD789D60ULL, 0xEAB612D9F79577D6ULL, 0x6E1B5CA781B478F0ULL, 0xF7DDEC6759A282A1ULL, 
            0xBF6B622E2F9E80DBULL, 0x6702960DBEE5DB6AULL, 0x669537B867D88852ULL, 0x86A43C9A437D732BULL, 
            0x9E59BDA5160F536DULL, 0x61321FDAD1B2B320ULL, 0x51A71B5F8424B99FULL, 0xF77E82183627E766ULL, 
            0x411EA375CC5D9DA9ULL, 0xF6CEAC147DB0833AULL, 0x7ED98E76E70DB015ULL, 0x5738C8DF6A142814ULL, 
            0xDCA3C2350378C718ULL, 0x126F5EFCD6821ADCULL, 0x5B3BD34739E89975ULL, 0xF5E6388BDC54DDD2ULL
        },
        {
            0x3A1123539933B039ULL, 0x1A6D90A9E30CF5B0ULL, 0xDA6C5F25CDBE1A45ULL, 0x3B0394FE97D5EF5CULL, 
            0x00258EA5E814BA02ULL, 0xEB9990CE29CA717EULL, 0xEADE255E252455B5ULL, 0xAFCF73E902486078ULL, 
            0xD6BFCD7B5ECDC853ULL, 0xB37D83F6680FF537ULL, 0x861CAA51D95E50F7ULL, 0xFD787221B0A702F1ULL, 
            0xD37677C8F9FB3979ULL, 0xF413BE68D1E13D18ULL, 0x539CA8609FCBC9F0ULL, 0xD74EB6923723A29AULL, 
            0x46ADF06EC8EE092CULL, 0x128446A79079E8D2ULL, 0xEFDDF7DC6849F6E7ULL, 0x83F7128D109FE183ULL, 
            0xCDCB356748A2231FULL, 0x7FF3B77AF0FF66E5ULL, 0xE422C3DACDE3763CULL, 0xF7D6874B0EBFB7E3ULL, 
            0x9315C02004B5E561ULL, 0x752706C4F747CF1DULL, 0x5F85A0BC12D93B32ULL, 0x930F0F717749E5E7ULL, 
            0xB5B6C67454A0E37CULL, 0x162C7CF16E90ED49ULL, 0xBA77BF834DC3CB02ULL, 0x61C126B1D2ECBEB4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseAConstants = {
    0x43EA324847C45D80ULL,
    0x27AD4CA26476232FULL,
    0xC6A104B8D665B85EULL,
    0x43EA324847C45D80ULL,
    0x27AD4CA26476232FULL,
    0xC6A104B8D665B85EULL,
    0x6A1831324FEE33B6ULL,
    0x8C0D7F66FBCC9808ULL,
    0x7A,
    0xB6,
    0xBD,
    0x41,
    0x29,
    0xEA,
    0xC5,
    0xB1
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseBSalts = {
    {
        {
            0xE30429E1DFC2A6FEULL, 0xDD45DEC2398D6A77ULL, 0xA40F74FDB88D0DFBULL, 0xBE9FCD0BD0EB02C6ULL, 
            0xF5AC600F452D23D8ULL, 0x69345F76B912F52CULL, 0x74322FDDBEAB4AA1ULL, 0xA2F95BDF3E9FDA83ULL, 
            0x973CA94ABFBB4BCFULL, 0x50E8777E3AE51969ULL, 0xE3F8765B1C3B3A1CULL, 0x8548E53159E3B2A1ULL, 
            0x00E1B4C47F1A8D96ULL, 0xF4E8CB1E22662DABULL, 0x3BFBBDE37284D2C5ULL, 0x1F762389285387EDULL, 
            0xBC56E5312D648627ULL, 0xD0DDC2FA78884EF9ULL, 0x6D74C74278887B3CULL, 0xDF53ED4D5187C0FFULL, 
            0x3D3846F78E86B47AULL, 0x15E1D78FEC6EB335ULL, 0x7AAA533D4C48FE98ULL, 0x98D384932283CAE3ULL, 
            0xC306F2B0925FC98CULL, 0x7E2BE02415433DEBULL, 0xED6EAE7704581741ULL, 0xA63A2E112F5466F5ULL, 
            0x4DF81D11408E9547ULL, 0xDD583A32539BDFEDULL, 0x31291220FCF2AC75ULL, 0xA1E4BC59FD297582ULL
        },
        {
            0x0F2B7A2634A468D3ULL, 0x9F9FDB3F7FA511F7ULL, 0xCD406CC7A7199992ULL, 0x63440EF4A15AFBACULL, 
            0xFAA44C986A5C3FF4ULL, 0xA4C741ECE1B432EEULL, 0x9154275DB251EE7CULL, 0x555BAD61CF50DF20ULL, 
            0x158A8CCE1DD2EF51ULL, 0x072863835984BEADULL, 0xB01115A34EEB767FULL, 0x90F919B30A0A5DEDULL, 
            0x76C85DC48BA25DB0ULL, 0xAF3EE25E4B3F5686ULL, 0x89D014E27E0284FAULL, 0xBCF69F3915F2AFDAULL, 
            0xAA849D7F568913D8ULL, 0xBD884BFD52C931E0ULL, 0xAF6146A7CC8C90B3ULL, 0xE5C5F1D759B57FF1ULL, 
            0xFBED62339FE84C3CULL, 0x955D8E8BF6956ACFULL, 0x5B7B2C1CC1A72C11ULL, 0x71F3C3AB8716B24BULL, 
            0x9F7C99EC022B7637ULL, 0x6E5F650FEE289CCAULL, 0xBE08D6476338074CULL, 0xCED4AB77DD7B589EULL, 
            0xF3C6DC1DD0839510ULL, 0x53FF9A1DF369DCE1ULL, 0x22FD54A141D99E80ULL, 0x0546A0B7E03E2232ULL
        },
        {
            0xD491D85226A13307ULL, 0xD3D7194B5D64D14AULL, 0x8C08F2C72168341BULL, 0x3DF8F5C7155FB4BAULL, 
            0x14C6A9FCD44B82D7ULL, 0x5B356C6B2CAE1EF8ULL, 0x4D0C872527628CAFULL, 0x6FF81B99CC9DAC52ULL, 
            0x22455CE75E87A434ULL, 0xD39DEB2D8769106BULL, 0x0DAE5C90F834B56DULL, 0xC594155EE6948D34ULL, 
            0x5FCF9DB597534644ULL, 0x601A15A035FECC27ULL, 0x9D41D6D66ACE3863ULL, 0xD631E90BBA8274AAULL, 
            0x5BD61830CF5D0408ULL, 0x41E5B2809E5BFDF7ULL, 0x81D048477B13F248ULL, 0xA8D45E34C1C564B1ULL, 
            0x7AE142F003A3D1C0ULL, 0x37A2903DF91383F4ULL, 0x0C84422042D66C12ULL, 0x654EF259FA3535C5ULL, 
            0x1689D7233D198528ULL, 0xEF58643A504BAD13ULL, 0x05BE02AAF7BE6CD3ULL, 0x347D8AB033632754ULL, 
            0x4A3DDC328A4FBD46ULL, 0x77551D874E3D3364ULL, 0x5BF976E24574C1C9ULL, 0x4C0B03BD106F3705ULL
        },
        {
            0x0B48733CD69E2F19ULL, 0x0B9777AAD2197032ULL, 0xE9C75B952D1859FDULL, 0x740190572BE3C3DEULL, 
            0x68A71361D74E8A4FULL, 0x94F6E77C6283B234ULL, 0xCC97B3F1DD9B2CEEULL, 0x29CE92A15E2279F9ULL, 
            0xEDA4B6426E0057C9ULL, 0x8872A1346569C6D8ULL, 0x8AAA20680C31676EULL, 0x751DD883ABBE3F0CULL, 
            0x03A30DAF2E6629B0ULL, 0x494C3164E832D946ULL, 0x72B8912AB8CD7642ULL, 0xC6E753589CF10905ULL, 
            0xDCD92AEE99F16875ULL, 0x70715958FEF7E9A0ULL, 0xB5A90E1176DF226AULL, 0x147EDF101D417542ULL, 
            0xAFFEBF153079E180ULL, 0x4406DF71D5FA1A36ULL, 0x37AFB32CE93EC3F6ULL, 0xA4FCD1A01246567CULL, 
            0xAEF532B94A15456BULL, 0xDA3211CCFF048696ULL, 0x4ECB240B289480F2ULL, 0xD67B62DB6DB599B1ULL, 
            0xD57436894AA11848ULL, 0x4A2C11DED810F44BULL, 0xE245F4670F9C555AULL, 0xB7CEF2CF46149B8DULL
        },
        {
            0x74F3227F17A03F1FULL, 0x5BBA3356A908CFD9ULL, 0x30D989EF972FDE35ULL, 0xDF2790CF479F14D1ULL, 
            0x567252FD35D6EA0CULL, 0xA366C2A6CA0AC162ULL, 0x648CBB9CED13CB79ULL, 0x7BDF73416A3A810CULL, 
            0x2C33DE8BF32B6343ULL, 0x4745225C2886FC55ULL, 0x93F01ED967FC9D57ULL, 0x729CFAFCED47B68DULL, 
            0x3DD52D08A24D6C08ULL, 0x39C4ACF3624BA319ULL, 0xE6B1A51519050712ULL, 0xB5172970523512D2ULL, 
            0x972542E04AC3705FULL, 0x8A7D4BBF6EFDD01FULL, 0x7309817F4D87B07EULL, 0x9FE05001A3640C1AULL, 
            0xB6E71BEFF658D72CULL, 0xC6124D96AF76F6D4ULL, 0x1FDBF7271792E097ULL, 0x7C4B9E506756DEE5ULL, 
            0x0B3DAED0F0FD4B3BULL, 0x7FEB0D7C8CAA3F8EULL, 0x0D4DE47FDEE9DCF2ULL, 0x5EA6165CAF272088ULL, 
            0x2CBC38DA303C969DULL, 0xDEAA356B8A726D39ULL, 0x39F1FF462E13A20DULL, 0xA797F76862FF87BAULL
        },
        {
            0x399594EFBD19FF1BULL, 0xA422F688B5EE8BC7ULL, 0x48A120018888EB27ULL, 0xBC5DAD6E6912FB63ULL, 
            0x67A886CBF9BAB34EULL, 0xADCC6D56A60F8F79ULL, 0xA3C28AF93E635D45ULL, 0x389649E15547657BULL, 
            0x0908DDA3ACDB2290ULL, 0xE4A6BF609318EE73ULL, 0x365FD2C44D06CA30ULL, 0xF11B500CAE188405ULL, 
            0x48178662754F7E53ULL, 0x3F26E8375B4BFB6CULL, 0x743C12A2C04EA4BEULL, 0x5CFBB06434863386ULL, 
            0x501A1544175CC901ULL, 0xF479D0395F1D9E9BULL, 0x6DFD4463F55B366FULL, 0xD4BA18F48DCBF412ULL, 
            0x1545E72AD7283326ULL, 0x35C56F89450049D4ULL, 0x337DB40B846565B4ULL, 0xF2FD70BFA03AC478ULL, 
            0xBE7ADC50483D3152ULL, 0xE015D5EF575B3B5CULL, 0x9A0CC113F176C8B4ULL, 0x3B1978D753EB7302ULL, 
            0x28321012C0F2AE85ULL, 0x905B06AC7162E5BFULL, 0xE9D28B437282B887ULL, 0xAD48790B646A52ECULL
        }
    },
    {
        {
            0x686C0F2A85895D92ULL, 0x46691C13BFA0782DULL, 0xCB42C60CC65617B7ULL, 0x9C01CC3A6156A87FULL, 
            0x29170778439825EDULL, 0xBE548B337476AE1CULL, 0x25B879D27FEBA818ULL, 0x1CA3ECB11B4105DBULL, 
            0x97FA558B16662CB3ULL, 0x9B5236372B6BB563ULL, 0x2F7392846A410B54ULL, 0x865AA4B95A35D2B3ULL, 
            0x27E4A37E43549875ULL, 0x713EE0739F7AFFB5ULL, 0xD1B2B11C829951AFULL, 0xF2FF8B756A105A60ULL, 
            0x8779297D7C7A54B6ULL, 0x3677DC7B71BAFEDCULL, 0xE2961AEE2DC24CD2ULL, 0x2B8E89CC21BCA524ULL, 
            0x7F27670EFB2C0F86ULL, 0x34EF6F32AF5AD763ULL, 0xFDB8D8284C53A7CCULL, 0x748AA7F8738DEAA1ULL, 
            0xC6F8F5CE3FD573B6ULL, 0x93C0B47A243E8617ULL, 0xB2B329522E8C8975ULL, 0xDF508357B9E48DC2ULL, 
            0x4653B243D7A86B9EULL, 0x3377369DEC103DEFULL, 0x3A9A056D16379550ULL, 0x0496C38621909F90ULL
        },
        {
            0xEFCC05C93414184CULL, 0x048A934782BE3838ULL, 0x1BB1BC0BADD44289ULL, 0x70AE1D47A1226C04ULL, 
            0xE70AA6513924B0BBULL, 0xC77B3FBF7F4022BEULL, 0xC2AC9C9344AD8200ULL, 0x5A5426ECF65DCCA0ULL, 
            0xD5600877EC3DE954ULL, 0x20D76D6CAC1262FBULL, 0x0D8962063E895C5DULL, 0xFDBE80A3195A182CULL, 
            0xC60A135A037225CDULL, 0x26A6EB38D35ADFD6ULL, 0x6649CF6C6650F830ULL, 0xB1B80A61F6B23221ULL, 
            0x3502ABE71AB32187ULL, 0xBEB261EC9EF0793EULL, 0x87A34475E329CC00ULL, 0x50B80BA3B1FD9B0FULL, 
            0x287976C87905A689ULL, 0x8ECD4909F56065C8ULL, 0x1D3C863D3DCE5F0CULL, 0x986C6568BA70D42AULL, 
            0x7D007488D5021C12ULL, 0x41A232D77DCBEBB3ULL, 0x80BAD80FA5E63CAFULL, 0x09E8D91E8F58A5B7ULL, 
            0xB075130824001620ULL, 0x0F0525BE78A31CFAULL, 0x2A73E2C955819EE3ULL, 0x1FEFDBED6674AC23ULL
        },
        {
            0x780A5DF399A21905ULL, 0x696DA7DF63A2DF9EULL, 0x96CEC2CF8A17F6A2ULL, 0x233F7D02523C1E1DULL, 
            0x6503E175290B0824ULL, 0x2140F2EF1A90369CULL, 0x1333BF81E89BD3E8ULL, 0x5C04A82C435D120DULL, 
            0x99B38A0C24FA72FCULL, 0x1834F87870D32426ULL, 0xE988BC5F23DDC746ULL, 0x1AFD7785A3D21A7AULL, 
            0x44391C6619A9D5E4ULL, 0xA4DFD1149D7BE075ULL, 0xA5C3B9F9C0BC7C03ULL, 0xDEC4DE31F7127DF9ULL, 
            0x10BAA13EA75762D0ULL, 0x1EBEDDCEB0C014D5ULL, 0xB07BDF432FB51265ULL, 0x06A3F8ECBDF09F9FULL, 
            0x25A6E1D96B95A934ULL, 0x2BC1D39DB404A042ULL, 0xD746EEF29BEAE30DULL, 0x2EE3A4D8774F8BA3ULL, 
            0x0AB6340D7082677DULL, 0x85236C17B3ECB773ULL, 0x5AF9EA5DA679C4F9ULL, 0x9015B8A2633E1A30ULL, 
            0xFB929ABE2606B000ULL, 0x8C5D870A4E42E7E6ULL, 0x885D6C3D8E146743ULL, 0xB93731B04F270CD3ULL
        },
        {
            0x4B3A82AFD87995E4ULL, 0xF6968E9DFB37039CULL, 0xC5A17805DB4E46A3ULL, 0xE43BAC332ACF1C3DULL, 
            0xE187AEA8A06C2CC3ULL, 0xDDAC714E5BCD5180ULL, 0x84FB654B12AC7328ULL, 0x843FDA8F595FA77CULL, 
            0x8078C00C1EC362CEULL, 0x4FF5CB3F43779C48ULL, 0x618AE9A01E35A1ABULL, 0xB6D35854872E4481ULL, 
            0x54E0375B090E3995ULL, 0xA585F765F43410D6ULL, 0x80BCCBCF530924C9ULL, 0xD17DECC9976DFC14ULL, 
            0x6B00BD31CE54C5D3ULL, 0xA993010429A65A72ULL, 0xE37A12EA1F11A9DEULL, 0xD173A149DB4361D5ULL, 
            0x66B7284BA96CCA7AULL, 0x2013882243E1C573ULL, 0xD0D97E2751A0361BULL, 0x026F111D451FD92AULL, 
            0x972CC99251F012F7ULL, 0xC8505403F3DE6698ULL, 0x37EF58DAAF7A29C7ULL, 0x72330840CE215CA1ULL, 
            0xE3BC62B40E3B465AULL, 0xC7938A0E9ACA3ABDULL, 0x3E56DEB9E16CB404ULL, 0x14D38769263C80EBULL
        },
        {
            0x4FF9EBAE7617348FULL, 0xD647231CE8724645ULL, 0x7AFFAD7B6D8BECD8ULL, 0xAB9E75D7B2EFAFE0ULL, 
            0x1AA2FEDD3F4971C8ULL, 0xAD95292F85487319ULL, 0x65DFBF7646B6F0FCULL, 0xBD13E643065E0E18ULL, 
            0xDC7E5D39DA74C93EULL, 0x143BD65510B71BDDULL, 0x9D2B1AF141415E57ULL, 0xDF804D0E6743E6ACULL, 
            0xEC03E2603ACD267EULL, 0x59C8A973B49DF96CULL, 0x2776710550081D50ULL, 0xA6C790A83606F233ULL, 
            0x34FD6D1E16106AC3ULL, 0xCAD72A3A8B5AD0DDULL, 0x1092B6E1D0C15B85ULL, 0x63B45D8918D96445ULL, 
            0x81F8B68CD52CE62BULL, 0x6F4755E501D7C731ULL, 0x444601A56DA11A1CULL, 0xF444114D2E8FC7A6ULL, 
            0x423B74E776B2CAF4ULL, 0xB0E213A901F6FA39ULL, 0xC39663E2EA074EDFULL, 0xD94C4237EE6E3CBBULL, 
            0x3F80F974E2AE0968ULL, 0xC616DFE1E42046C2ULL, 0xE4D5F37FA37483D0ULL, 0xE6AE24A315AA2838ULL
        },
        {
            0x124AFAFCE160BAEEULL, 0x56BDE24B6B6FC93CULL, 0x7FAC223517400323ULL, 0xB2A7D05EFEF8A06CULL, 
            0x3065C876B532E227ULL, 0x315D8EBE3F2808C7ULL, 0x196164C945BAD11EULL, 0xCB831D66C10447C3ULL, 
            0xD90921D941AC1E73ULL, 0x339FCB6D0B81AA9BULL, 0x83E40C5B16AF8930ULL, 0x81749DE0108C2965ULL, 
            0x4EE988AE75DDBB50ULL, 0x29C8976DFAC5F515ULL, 0xA3A78BF28B6476CBULL, 0x4724ACB388A0FB7FULL, 
            0x5E06CC3AFA1B12B3ULL, 0x69E1CB639FAB1E00ULL, 0x0C15F3ADC36C063BULL, 0x05A2F2D1D148F471ULL, 
            0xE22345F8650FFCA6ULL, 0x66E0B45990365229ULL, 0x2DACDD137FA9F3F6ULL, 0x03EC500855AA344AULL, 
            0x25AE93DE621FD9A7ULL, 0x765D3A5D91BC0776ULL, 0x06C38157FACFEAA7ULL, 0x6E001B4D8C82501CULL, 
            0xFC575807DC764F63ULL, 0xA93DD1AEE13C849FULL, 0xDB34317976B93F9FULL, 0xDB5092AC21856676ULL
        }
    },
    {
        {
            0x1C0F74C3BD43E7DBULL, 0x6D972C1FB5A6A1E4ULL, 0x4A3CD626BC4AE1DDULL, 0x8A125A266CAAB8B2ULL, 
            0x9F87B4931AE5EAAAULL, 0x75531E9B6DDB5708ULL, 0xF341B34F5D941EDEULL, 0x74F1F9A8A40F6576ULL, 
            0x8BD22307B03952BCULL, 0x609AA756C8E42C32ULL, 0x020F29A07E6EAE59ULL, 0x5B2B864BB89CC00FULL, 
            0xBB71C11AC64DB2DDULL, 0x360661442BF51203ULL, 0xBC1E03253112F621ULL, 0x756ADB53139A74A9ULL, 
            0xB138CBA130BDC490ULL, 0x0E100C40FFA9A8D6ULL, 0x78D1601A5C96C646ULL, 0x8AB8E4AB6E76EB32ULL, 
            0xE1B802B86DC90CB5ULL, 0x4A31AEA4E299BF7AULL, 0x2732602CA8FA7FC1ULL, 0x1079282B283F0452ULL, 
            0x0D5F865F15DB0B2EULL, 0x226C443EFF21C257ULL, 0x91A6730576A25AE5ULL, 0x4F18F472936BB538ULL, 
            0xDBC114BD65BBEA71ULL, 0xF03C387CD6F021B3ULL, 0xDD3C0AC27966594BULL, 0x3E30B0433C14064FULL
        },
        {
            0x62AE079B7878AE8BULL, 0x7B73B32F8CFDAAE6ULL, 0x0BDE96ACDC973B66ULL, 0xB447B5431DDA55BDULL, 
            0xD89CF4E73C8549D0ULL, 0xD9E242BF0B14E07BULL, 0xBD2AA07ABF7ED411ULL, 0x7BE8ED39E744C21EULL, 
            0xD0FB192AFE71CF66ULL, 0xCC6BFFBF772C987AULL, 0xCCED71CB4EC8C9E9ULL, 0xA31D5EF9A3DD83EDULL, 
            0x001BA2FA44F91DADULL, 0xAC303BA016D080A5ULL, 0x7289CAA3B0C78B13ULL, 0xBB96D49266AC938FULL, 
            0x3E17C34D299CC027ULL, 0x2078D714CACF37D8ULL, 0xE13E7983E83277A3ULL, 0x3569ACC96D445B36ULL, 
            0x117F4D61117B6361ULL, 0x7BDB3D6B515EA3CCULL, 0xD4BA1972913DD5E9ULL, 0x0191646E7D458C8EULL, 
            0x02E7C0194258D4F1ULL, 0xA1EBED8C29E24576ULL, 0x1D8E8B48CF58A46AULL, 0xBE0461A43CB2EB17ULL, 
            0x52334B00D1AA51A4ULL, 0xB1ACA168FA5D92D1ULL, 0xC97E099410BF8AF6ULL, 0x8A291869BCBD16FEULL
        },
        {
            0x31BA5AF242C0BF08ULL, 0x585122D6141F3FD4ULL, 0xC3B71200AB5EA7B4ULL, 0x194DC3D73D1573D9ULL, 
            0xD05EDB214391F4FFULL, 0xB5D171A4BDE0E8F5ULL, 0xA3B3D4E8B49C93B9ULL, 0x3915C86E1C1CCD38ULL, 
            0x6559199F89387A32ULL, 0xBC04E67A42767145ULL, 0xAC40A4661758C2F0ULL, 0x03B3779275D9B333ULL, 
            0x6388AB5654CE91ACULL, 0xE6A8D659F19DFC65ULL, 0x153697B1985F08A4ULL, 0xBDBCEE7BCFD6DDFBULL, 
            0x3234F6C65F5F9021ULL, 0x8EFCF7C4192A4C91ULL, 0x1ECB86A920B61DE6ULL, 0xC798EE7FDBC75299ULL, 
            0x9531A99C050A932EULL, 0xE6720A0EACB2F901ULL, 0xE217782415ACAC2CULL, 0xE85678828C403422ULL, 
            0x03AF7F550151E764ULL, 0x3ADBC710D0D1D0F7ULL, 0xAD391AED973A067CULL, 0x218325A5F864DAC1ULL, 
            0x880E402843E3AF4BULL, 0xCDA260AA0657CA21ULL, 0xB10DD890FDC5C0C1ULL, 0xD8B41F419B1049AAULL
        },
        {
            0xCBD69C4AB90BC44DULL, 0xEC3B2C0CAEC6AA66ULL, 0x1B18FF0E48420366ULL, 0xB940D54D6E4576AEULL, 
            0x22ACF787C35BEA24ULL, 0xA028EFBFDDD43066ULL, 0x09E6722494312CFAULL, 0x461CDC8EA1BDCAB6ULL, 
            0x1C1FCFECE3CA5B5CULL, 0xFD2B98CF1B9DE691ULL, 0x3CE15052B8D63C1EULL, 0xAE3B4A4F4D97DC3CULL, 
            0x8036FF0D730C8072ULL, 0x79654FBACEC3E32CULL, 0x6E11AAC1E744C348ULL, 0x3C58F1B1B4BB466EULL, 
            0xEF0B750B90D0040DULL, 0x83EF5746F9A5949AULL, 0x48862A1066B5713DULL, 0x78E7EDE4335A3EDDULL, 
            0x834279857F943E14ULL, 0x1AF4A9F0F41FA5C9ULL, 0x16A65096AE7692FDULL, 0x75B524F6B17B88DCULL, 
            0xB817EFD31BB31207ULL, 0x90FD579819FB84C1ULL, 0x9A07FF159B63097CULL, 0x88E89A255EDA8424ULL, 
            0x971CDC979B56284BULL, 0x519DBE2FA746D5A5ULL, 0xDA78F31A12640ACCULL, 0x0430F03AAA6E1DCDULL
        },
        {
            0x64A3134534E31BF2ULL, 0xE46D7A6B66A79F93ULL, 0xDF5438BE53DBAFF3ULL, 0x3227CE6D342528E8ULL, 
            0x5DA79140AE711E9BULL, 0xB6FE96111051302AULL, 0x7628489BCE93406AULL, 0xF29B2D7D9A68B6BDULL, 
            0xBA9708373FF87FD9ULL, 0xA89E9C7FFD9A6E60ULL, 0x997E297D8F58E3DCULL, 0x4DDA572282F9BFE8ULL, 
            0x37F1A39E23FA8CDFULL, 0x6C7D6B620F073FA8ULL, 0x550A3DA4DDAB37E7ULL, 0xB2FF30B55EBD9E92ULL, 
            0x566AB58524ACC85CULL, 0x3AD2CE1317330F21ULL, 0x6D3FF1F1343D7891ULL, 0x4A11D79CA6C9310CULL, 
            0x1638CF97FD700E31ULL, 0x226D3015B41A1FA6ULL, 0x93079AA6C69328E7ULL, 0x04704FDE72B02227ULL, 
            0x713EE1E68F215EF4ULL, 0x32319D1BABB25788ULL, 0x7404809D79D9473EULL, 0x31B5D393C64D22CEULL, 
            0x02EC08417265E793ULL, 0x2F5EB46A5780A10EULL, 0x8587BBF5A12AF8D1ULL, 0x81A7EC3C69D70417ULL
        },
        {
            0xEAB387C684908D2DULL, 0x2363591F6BF65C92ULL, 0x0429D600EF6D4407ULL, 0x8B56AB824B8CE649ULL, 
            0xE72F9F04872570B3ULL, 0x62B71C81514A5E96ULL, 0xDD27D52AB84FD3D3ULL, 0x99E06B340374507BULL, 
            0xBC82BE6F799A5465ULL, 0x6D6CD302FD7BEAB0ULL, 0xF5221F1E877214F4ULL, 0x8D9F774C9ED492E0ULL, 
            0xA752BF78418A98C6ULL, 0x146643D3B5A05424ULL, 0x95166AE679BC0DEEULL, 0xD73FC1D3866D34C8ULL, 
            0x2C495C33385AEA40ULL, 0xB76A28D1E1DCD416ULL, 0xE5828DC8ECC96A04ULL, 0xBDBDE2FFE3966FDDULL, 
            0xC2A38899448F27E5ULL, 0x73ED3212BEF8B35AULL, 0x81E57DF5545CBD16ULL, 0x3E1EF78AC82D5D1DULL, 
            0xBD5F272243C855A0ULL, 0x7FC7FFBFD12C5A64ULL, 0x3E577EAD81041B65ULL, 0x3F720A230DD1275BULL, 
            0x24C08D1CEBDFEB95ULL, 0x86DA71D8D4C8F2CDULL, 0xDF48BE618D562F64ULL, 0x5B24ECDE14507ABFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseBConstants = {
    0x6E86A4F13C2294ADULL,
    0x1E66AFD3AA381CD2ULL,
    0xE19170909F945839ULL,
    0x6E86A4F13C2294ADULL,
    0x1E66AFD3AA381CD2ULL,
    0xE19170909F945839ULL,
    0x3820F501531C83CCULL,
    0xDF25A719199F511EULL,
    0x15,
    0xAC,
    0x78,
    0x37,
    0x07,
    0x6F,
    0x0F,
    0x79
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseCSalts = {
    {
        {
            0x19A55BEFEBA7C262ULL, 0x19434D6088341533ULL, 0x986FBA385A1148AFULL, 0x167306D55EE9D402ULL, 
            0x21B3552D11C97191ULL, 0xC1595DD0E4446B21ULL, 0xAAAD2097269E84A9ULL, 0x3E08F25A637FAF67ULL, 
            0xFD0A962EE7571137ULL, 0xE880D7C5061C3750ULL, 0x457A3F1464B9886CULL, 0x0A9403B45ADCF2E0ULL, 
            0x06199961DE9B2C26ULL, 0xB9D70FCDC884380CULL, 0x4712548E495A0D78ULL, 0x8692C2A7C48D9569ULL, 
            0xD7B128664D640E9CULL, 0x940DC153EEBBE94DULL, 0xBC41ACAC6519097CULL, 0x3586D92D4FAF1815ULL, 
            0x08DCC489BEA7FE2BULL, 0x5375D5C875633D18ULL, 0xB6FB546E3B01C13FULL, 0x2F5EA89699E6C851ULL, 
            0x446E136A960A15C6ULL, 0x9090C5CB27DB378CULL, 0xCB6043C369402251ULL, 0x35F99753A28C3007ULL, 
            0xC200D9E5C8B1B636ULL, 0xCADA87BB4205C48CULL, 0x33323E1026F4FE78ULL, 0x4A84E17CBB644D1EULL
        },
        {
            0x5607DE31D392C55EULL, 0x0328C45469D3B094ULL, 0x40F3D0A26C2E9C4AULL, 0xADB44966940397ACULL, 
            0x1CF33B2BEA0C4C17ULL, 0x2447853340555B60ULL, 0x60FEBE2C9F870352ULL, 0x27F8C646F76D1024ULL, 
            0x84CDDD75E0C2CD1FULL, 0x579670ECA9791E2EULL, 0xB5461B38DCB76A41ULL, 0x95AE54317054E1D2ULL, 
            0x25EBFC8016A14C46ULL, 0xE43FC1ED614A0F1DULL, 0x0A5F5AB227A97DA6ULL, 0x98E2E2EF27306917ULL, 
            0x9AD5E7A43BCCF526ULL, 0x7E596E24BB350AE0ULL, 0x58C640FEA6BBAE3BULL, 0x98ED72027C81E4A8ULL, 
            0x5CE19337E74D01C0ULL, 0x4EE8214F07E7C354ULL, 0xAA0657D365A60810ULL, 0x358875BCB6384967ULL, 
            0xA62356661DAEC31BULL, 0x47AA0EFCB8B530AAULL, 0x81E35A72B12DE909ULL, 0x6EB50C065DA034DAULL, 
            0x080B5A114E4C411BULL, 0x19DD667D13A9CB6AULL, 0x662E16F6AFBC27CAULL, 0x4102C28AEC402F6EULL
        },
        {
            0x7A36FD3A546D3141ULL, 0x7B23F9EAE82FAD41ULL, 0xC4835CE1D4EF8F95ULL, 0x2564DB343447F890ULL, 
            0xBF072377F6CEA4DAULL, 0x67BCDF0FCEFB40F7ULL, 0xC0F58579007CE91BULL, 0xE5CA206F16A9AC11ULL, 
            0x05A1F5365AA23003ULL, 0xE52495FD9002144EULL, 0xF79EACAFF03F003CULL, 0xB368F112226D9489ULL, 
            0x5B417C5B9951CFDDULL, 0x88A057230831D5A9ULL, 0x523FE59F87AC9ABEULL, 0x6DE879950CB53ED7ULL, 
            0x8D1A50B1AC279888ULL, 0x5136C841176E992CULL, 0xF79376D2E9112B64ULL, 0x349C8E36C1032F26ULL, 
            0xDDD95E29210C4808ULL, 0x2551E10FD50617B8ULL, 0x25498EB4A17C1BA5ULL, 0xA6DFF6EE647400F9ULL, 
            0xDFF60016439CA664ULL, 0x16F5CB0F9ACF9B9DULL, 0x29A51D54F931AD84ULL, 0x93AF6DA47EA128E9ULL, 
            0x7680EC1C72882C49ULL, 0xE5B5A3B07717637AULL, 0x575463D69AFC13F3ULL, 0x201DFAB0831BD8C5ULL
        },
        {
            0x7503DA077648E0CAULL, 0x66479EC37DE9C431ULL, 0x4B1B5EE3AD8B3B0DULL, 0xC6E48656F5A8C3C1ULL, 
            0x7E0D5228D8A04B8EULL, 0xC930BAA877F4E067ULL, 0xA3E29B5CC99DCC84ULL, 0xCFA61CD9F417E885ULL, 
            0xFF217FC88C3D2C15ULL, 0x1A82067C340E94C3ULL, 0x850D77E8741B2F4AULL, 0xF39A8D8A44C888B3ULL, 
            0xCF97F8B17393789FULL, 0x75D0E26DBE6BA4CEULL, 0xBFF54CCE69B9D4A1ULL, 0x4672574F54CB1725ULL, 
            0x6DDF443DD09D1B0EULL, 0x8B1BCB88DCD7F050ULL, 0xDFF077295DF8F8A8ULL, 0xF9E8BAFE3322A730ULL, 
            0xEF296665335D7E83ULL, 0x7AFA9734027C79DBULL, 0x352475AE90063AFCULL, 0xB9DA80F6AEA318B4ULL, 
            0xFA9FA0279511A1B8ULL, 0x8600881CBC324B4FULL, 0x54F716349495437AULL, 0x8C0B52A0D00013DDULL, 
            0xD066B29DF3411664ULL, 0xE29901D83614FFE3ULL, 0xF1A804120111483EULL, 0x76081687DF5BE1ABULL
        },
        {
            0x6EEE029364EABD27ULL, 0x4C2FDFD8714CCA7EULL, 0x2E3975680EE092FCULL, 0xE0B676D4B40F1AAAULL, 
            0x8EB9BC6E69F895DDULL, 0xA62EB78314A77112ULL, 0x54E223E7BE5A2D28ULL, 0x91093D157470F74EULL, 
            0x18A55069655E3F69ULL, 0x332B6C52915E68BFULL, 0xAB2D556B4C60C76BULL, 0x5559E4192CA43813ULL, 
            0x404586099629F598ULL, 0x827254A04A3F6480ULL, 0x00FD47506A5A9EDEULL, 0x6EEB2A35FCF59583ULL, 
            0x97A1995E2A3CBE03ULL, 0x2FEF9AD741A6EE7CULL, 0xAE374FCDF65CF45CULL, 0xE24E894C7739636CULL, 
            0xE6934B47EAF6C3C4ULL, 0x62F6CFE9E64405DAULL, 0x023E00F52BA943B8ULL, 0x81CAE57799963A62ULL, 
            0xD3351F1304403A56ULL, 0x87AC925A2D42AB9BULL, 0x235665E4E6296374ULL, 0x2C7EEDD22C374C08ULL, 
            0x924818455ABD65C9ULL, 0x448B468B9D8F925EULL, 0xF39AB782D496E2DAULL, 0xD2676F079EB686F0ULL
        },
        {
            0xAF86934DCD2921E0ULL, 0xA4B161E650FB0DBFULL, 0x7B7C0886648EFA60ULL, 0xFAB78FD28B837F61ULL, 
            0x08F500FECAE1C0ACULL, 0xC404D86906D7E334ULL, 0xA02921FB74CAB349ULL, 0x6AB1AEC155808C4DULL, 
            0x24CE0F63226BF71FULL, 0x919F90D1B2AB8492ULL, 0x11AA3D06256A055DULL, 0xFDFA9523F433941AULL, 
            0xDA5026AB82E997A7ULL, 0x3181E01C0D57F7ACULL, 0xAC8712D4CACFFEA2ULL, 0xB20728D9E1043994ULL, 
            0xFB930DD16C7295A7ULL, 0xB6212C6645343793ULL, 0x374455B1F7DD8C2FULL, 0xCE9D2A6258BBA3CFULL, 
            0xEFFD2202B50DB38BULL, 0x7A59985E84475F7EULL, 0x23FC62694E95C522ULL, 0x20E1F1E1AB41259FULL, 
            0x83133AE19F7436B9ULL, 0xD2D934C0A95A5151ULL, 0x4298C67D1C8BB4CDULL, 0x337395D448F148A8ULL, 
            0xDA336E30794597E1ULL, 0x3808B3EEAF96A410ULL, 0xE7048F4BFAF25405ULL, 0xEBC7E6142B67630CULL
        }
    },
    {
        {
            0x8FF952DE6BA24D11ULL, 0xB519B7F6F77BB010ULL, 0xD746A1361F717501ULL, 0x3C03500D7DDDFE75ULL, 
            0xD745C94336DE6850ULL, 0xBA5F98F16A349140ULL, 0x9C43AA1773A4756CULL, 0xD187F20603A158DBULL, 
            0xD2AF9028A6629B18ULL, 0x433DCFCEF7A3A781ULL, 0x0A836139B8EBAACDULL, 0x919A6BD6BD2C7B3DULL, 
            0x99DAE6963382A722ULL, 0xB0F65A30E67226C0ULL, 0x924A673C1C8635C3ULL, 0x557A34DA63CE898FULL, 
            0x098DF0ED98D2FD3BULL, 0xCB9CF1D2D76D995DULL, 0xC0EB5C7BC3E35621ULL, 0xFD7F9126873E66F0ULL, 
            0x762AA6BBD30B88A2ULL, 0x8ACE177C16FE19E2ULL, 0x5618037D87276C52ULL, 0x71321FFDDE2140EEULL, 
            0xF54CA82F494FEC6BULL, 0x4D21333CCB8B2D30ULL, 0x707DE0B274244536ULL, 0xAEF5048561D91E2DULL, 
            0xD0E4186D4916929AULL, 0xA68516600E4BB9FBULL, 0x2E2DB51BE6650C19ULL, 0x846ABDB22FCB6A7CULL
        },
        {
            0x0138563578FF3907ULL, 0x923FEA86E081E49FULL, 0x159C2D8DC9F14219ULL, 0xCB82D3D6C6038156ULL, 
            0x2A3C960BB3A93831ULL, 0x516DD47B16D9169AULL, 0x55C1A7311E44A7D5ULL, 0xCA80E7A4BD5F287DULL, 
            0x3C270A3C9924A690ULL, 0x80CE29F4E7C2B48CULL, 0xD9A4F5AE70A23CC1ULL, 0x40F9A0B24BD3D754ULL, 
            0x5BE05D53CD25E07AULL, 0xD0FCF64697776E2DULL, 0xABCCF98DFAF59245ULL, 0xD225386FD644E58FULL, 
            0x4A4217868CDF34F4ULL, 0xCE5D414183FF9702ULL, 0xDA9BB3762DF46EEEULL, 0xBD22E2B1AE4706C4ULL, 
            0x88E8AE4ED0AFE5D4ULL, 0xA733C13A4E2C99B7ULL, 0xD245CCB401ABF24CULL, 0x127E6B42ACBF110DULL, 
            0x039D7DFF6A2C9E85ULL, 0x506EBA590F90BA24ULL, 0x8219CC0F223BACFBULL, 0x6341D24EA216E5CDULL, 
            0x8960A864D6856F39ULL, 0xF1E46FEBFD47F9C7ULL, 0x7B27BB448DDB9AFBULL, 0xEE51E3523D45780FULL
        },
        {
            0x24CE1B1802151A52ULL, 0xD6F4E9BB2492B8F9ULL, 0xAE8311A33A878D56ULL, 0xB1E6108942C0D0FFULL, 
            0x8BCA6FB26F1F3E7BULL, 0xB15E2C43A9BBDDB9ULL, 0x447319EAB8EAF329ULL, 0xDB74FE83C28E29A3ULL, 
            0xC27425FD11849484ULL, 0xF2E5AF2D0BF33AFEULL, 0x24200CC119424BAEULL, 0xE4E3796A8E040CD8ULL, 
            0x1D65953EA3A39B24ULL, 0x28B52622B81515A5ULL, 0x8B677DE9E859E9AEULL, 0x86EFA79D730F3A20ULL, 
            0xF9E9E28FE165187EULL, 0xB21BA47F09B387B6ULL, 0x6309E59336B99B16ULL, 0x476CD9C43BE913B1ULL, 
            0x85CF19D587B2AE40ULL, 0xD166DE81F58A6725ULL, 0xE6EEAFF15CF432C0ULL, 0xE8CAD55F8A8262BDULL, 
            0x454BD663489C165EULL, 0x3F416FB325910881ULL, 0x29CB60609F481010ULL, 0xE68E18F905E7A296ULL, 
            0x5398E7BC1D99EEFDULL, 0x74DB1D889844E3B3ULL, 0x191DBAD5D7AA8550ULL, 0x6D494D2CE0B9549EULL
        },
        {
            0x919ED01F97D62072ULL, 0xEADF604BE90CC140ULL, 0xA9B002837617C712ULL, 0xEFEF146DA1416217ULL, 
            0xEF307273CA6D70B3ULL, 0xDC3DCFC2619B513DULL, 0xF6BED0A62D3B96C3ULL, 0xBC856A7A6A082EF3ULL, 
            0xA471EC109534B01EULL, 0x1C7C6C8741C26A9BULL, 0x937CE62570B44A44ULL, 0x72ADB79BECDABBE0ULL, 
            0x1A6234200452236BULL, 0xA328772EFE1C695EULL, 0x8F14A255193BEAEAULL, 0x2239D148686EC1D5ULL, 
            0x13C113A055E95C28ULL, 0x24A3CEED1246AF1DULL, 0x89E8C5C9AD583489ULL, 0xEC50A6475B40D2B2ULL, 
            0x2F93F9A9C6B1342EULL, 0x486157C430BC08AAULL, 0x737DEFA1484C293DULL, 0xA4FE04D10EFD7B61ULL, 
            0xEB0F6ACB24A88D07ULL, 0x8329C4795DE55987ULL, 0x75EEDB190AD38B9EULL, 0xE43F0C6A458E9F77ULL, 
            0x751784C877919C21ULL, 0x4F5566AA3E059B61ULL, 0xBDCCC243931A3B74ULL, 0x06F6B9E2CEA387ADULL
        },
        {
            0x78C0C49E932075C8ULL, 0xD0AFA0211E8B133CULL, 0xA7A8F7BA1446A6AAULL, 0x403BB532F4E5154DULL, 
            0x4C05E7D5503447D7ULL, 0x122056A7CBD15303ULL, 0x620E5239CC9A3FB3ULL, 0x490C9EA53F8B0B31ULL, 
            0x84EBA23D4FD25AA2ULL, 0x37284AFCF1A390C3ULL, 0xFD756C376BCA435FULL, 0x3C1942FC3A914382ULL, 
            0x1055EA0880DEDFEAULL, 0xC9EB5CC704DE5A8CULL, 0xF52C4C4E8F1115EAULL, 0xC4E4AFF0BCD7B7A1ULL, 
            0xC8D1EA57324FDBB5ULL, 0x37873667F0D4157BULL, 0x07144EF44A499B95ULL, 0xBA3BADFCADF44E28ULL, 
            0x1E4F23687C90A3E3ULL, 0x69946BFF37265559ULL, 0x483CA2A6F36DABB8ULL, 0xB98B9C39F1FB9620ULL, 
            0x3407525A8C9C9652ULL, 0xFD90FC645265A1DAULL, 0x5B83CB1690D5CCE2ULL, 0x4BDE09AA52E941A6ULL, 
            0x2CE830506F97AFFBULL, 0x9EB0067A00E3E62AULL, 0x81DF6478E51BC09DULL, 0x0DBE8AD5D33CE837ULL
        },
        {
            0x6F724825C2FFCAAFULL, 0xD77E31B692B51686ULL, 0x876A12BB0CD7BC52ULL, 0x25CC8AF92D793887ULL, 
            0x19AC9A143BEBA5EFULL, 0xD7CAC024A9BFE6EBULL, 0x38A239B2FAA824B1ULL, 0xB26647917328810EULL, 
            0x778E7B6266101C74ULL, 0xE3BC88A5694FE81AULL, 0xD66A35A9A330E88DULL, 0xDBEAE58D1AD03446ULL, 
            0x83FD832DC59B3E90ULL, 0xB27EA041D37B7708ULL, 0xAF3A28A5CB2B0F9BULL, 0xE4B2346EEA4646A4ULL, 
            0xB97BD866F5742112ULL, 0x9AE8883C72071805ULL, 0x1FDF535AEE1EC2BEULL, 0xCED04E11FE9A6CA8ULL, 
            0x8BBB866823042FD0ULL, 0x78564B4DBBFB61A7ULL, 0xF8445B9DA322DC98ULL, 0x808ED43CC09F9605ULL, 
            0xE2AA5ED8FE7F951FULL, 0xB4CA2190C644C638ULL, 0xA7E4E00A4370AEF3ULL, 0x1814590BC5937672ULL, 
            0x714558C49BF6884AULL, 0x9C9132ACA7AFA257ULL, 0x04067DACBC90D7E7ULL, 0xBFB2BB233818BF42ULL
        }
    },
    {
        {
            0x1154B79FB3B813C8ULL, 0x50FE90BF2C1088B7ULL, 0xA26652CE2FD04C0BULL, 0xB68074A38BFC755DULL, 
            0xDD9C6EB2D22425A2ULL, 0xE90A203119C94443ULL, 0xAB810522521EE53DULL, 0x6E8D586AE15C3E51ULL, 
            0x5B09009A034D108DULL, 0x72EA418B1A4D9AA6ULL, 0x8D541E2B997F9DBFULL, 0x701B4DCF82EF9946ULL, 
            0xCFB7CFC1208F59DCULL, 0xE445DB49FFD3E225ULL, 0xB93D21874559B447ULL, 0xFE999D6F1AE1500CULL, 
            0xF4FA60F735CC84C4ULL, 0xC43A8B31F2691321ULL, 0x3C1D394D6E9DC652ULL, 0x64E3AF7DE68CF20CULL, 
            0x11ED0F9032F902B4ULL, 0xD00B77F153A87E44ULL, 0x837589F56A7BB1F2ULL, 0x43A20A01AD881455ULL, 
            0x40D74A13971E9DDDULL, 0x5A9BE70F59C2678EULL, 0x39164A055D82149AULL, 0x889FE1CC93750910ULL, 
            0x36CAC1EF42C4DB84ULL, 0x46456BFFCC56F9A7ULL, 0xB0665131D7EF52FBULL, 0x9EE4DB7D2020579CULL
        },
        {
            0x18493A7BBBA7D456ULL, 0x8244EF0E2955E0EAULL, 0x59BB3AEC8FC48B71ULL, 0x58E542984FB39F3EULL, 
            0x4AD5DB924C027742ULL, 0xC1C0832ED936959BULL, 0xA2BAB8089082BAF4ULL, 0x8DD2DC9061BA8EC1ULL, 
            0xB45142ECA5304F5CULL, 0xF6FCE14F09964913ULL, 0xD33A63356E31BA60ULL, 0x81BDEB5B57DB3AA1ULL, 
            0xF7F761697378B455ULL, 0x406F2C4EE3925831ULL, 0x9675D944AC8D4A97ULL, 0x241005B148F03139ULL, 
            0xA82C0F05B129C070ULL, 0x436F3808E2321F00ULL, 0x3BB048DDA286D8A6ULL, 0xED39F5845D2B89F2ULL, 
            0xE9249EE59F7E61B7ULL, 0xA5646BE76F683457ULL, 0xB0E665D87C2E403FULL, 0x01E01BE10076C748ULL, 
            0xC5B269CF90305D73ULL, 0xFCF536D5FCBECB48ULL, 0xD18BA45DAA8EC646ULL, 0x57B1B08FD564B236ULL, 
            0x1629C90ABA31DB32ULL, 0x6FAD8EAF3434EB13ULL, 0xC87AFE99B44F4D30ULL, 0xDE3F27B42C3D2502ULL
        },
        {
            0x60951D820BBAFC6EULL, 0xE665145F9F23D505ULL, 0xDE00BEFEE940C75FULL, 0x682E0D5A64286606ULL, 
            0x95EE4FF4B5483DE8ULL, 0x3AF4C9A4B3C9945DULL, 0x6FF27F946668F991ULL, 0x9939D39C6E20852CULL, 
            0x6C167F1F9105649EULL, 0x6CE7167BE1F7EFB3ULL, 0x7C7196269ACBA09BULL, 0x71645B697C870B11ULL, 
            0x7BD79A5C1BA8FF71ULL, 0xD3D33157B79623E3ULL, 0x9777CB64BCE5AA82ULL, 0x66ED39377279AB8FULL, 
            0xEA7D8F38E8B9C9B0ULL, 0xD27DF958CE557F26ULL, 0x71E1A01A8449BB78ULL, 0xB88A5BFFB797530BULL, 
            0x6A37F869D1DBF8CBULL, 0x75562C3C86B4EDF1ULL, 0x73A73B783DF68623ULL, 0xD5349438A8171F49ULL, 
            0x5DD7A3F28A6C59FAULL, 0xBA83A7D74608CAB3ULL, 0xA7F26CE44CF51493ULL, 0x68FC70AA34E64C32ULL, 
            0x79BF9A029B6F52BDULL, 0x13B3A8E7AE0DC285ULL, 0x130BCAF3E6033700ULL, 0x909826ADDACD73A6ULL
        },
        {
            0x620AE0EFC7015891ULL, 0x40C61EDD0DB3B673ULL, 0xD5E1464EDE11F1ECULL, 0x2BE6BA596ED8A7B2ULL, 
            0x5826F361F0284F59ULL, 0x6C17113ED928FE07ULL, 0x49BE05874398CFA1ULL, 0x3B55B7D749F289A9ULL, 
            0x4A4900A966874FD5ULL, 0x4DFF2504D76C8A54ULL, 0x803BB5570303E567ULL, 0x80CA7001E15FDFCDULL, 
            0xE50C61A9989D1A5AULL, 0xF6430FBB2E543725ULL, 0x8A761F06C7EC2EE6ULL, 0xD4E37A2FCCBF897AULL, 
            0x55B6FB15C09AD265ULL, 0xD0AE03A7F50577E3ULL, 0x9BC7BE7BD90B3779ULL, 0xBD5246DC7D8926FAULL, 
            0x5DAA1CD5AA8EF909ULL, 0x7602AB782D32D851ULL, 0xD4B9ECBCCCB8DC65ULL, 0x363749C13950161AULL, 
            0xAF46F17D4D1AABF1ULL, 0x8340E356A8BFA023ULL, 0x7906408C27993216ULL, 0x1490ACC7C3354BE5ULL, 
            0x0E539831795922DEULL, 0xA85CAEF5E845ECACULL, 0x8EA23BA29F064E65ULL, 0xC98D60821BD57494ULL
        },
        {
            0xB4C2615468E7E277ULL, 0x29D309D68A87F3C2ULL, 0x246CCD4F622D4407ULL, 0xCCF8860DBB8DC96FULL, 
            0xCDF724209B10E400ULL, 0xDAD07E0CC5F6F986ULL, 0xA14057E6EA0AB4A8ULL, 0x56DD58517704DBDFULL, 
            0x34DBAA57DC60319FULL, 0xD6B102EC3118FACFULL, 0x504B83E4642F9ADFULL, 0x2F726CBD405A538BULL, 
            0xFDEEA35314B11235ULL, 0x16887D661CF5E55FULL, 0xCD74A96B3E3A7FDDULL, 0x2AF932BE1A626877ULL, 
            0x27E307E40F2AC97CULL, 0x4B46289D720C9F64ULL, 0x26105A5DF51A3799ULL, 0x6C01A875C32C102CULL, 
            0x8D7B49F591E6FD1DULL, 0x789007A39822D340ULL, 0x002F74615D313D18ULL, 0xE089CE1B21304436ULL, 
            0x361E3D43364E2698ULL, 0x2CB777C880E120F0ULL, 0xAE46098AE2F7B677ULL, 0xB019EFCAB6314EC9ULL, 
            0x502C76B9D954FA2EULL, 0xB7A79C4972ECCFABULL, 0x400E1A09833249F1ULL, 0x087831B3F699B7CDULL
        },
        {
            0xCE32852E2EF14BEDULL, 0xBB0C5622C64D5E3CULL, 0xCF308E46DE649D5FULL, 0x59A3BE545BFBCB85ULL, 
            0x355497EBFD55B6EAULL, 0x88A815CAE840BFEFULL, 0xD4273A8E03251034ULL, 0x24BAADD3FB6550EDULL, 
            0xA16167A0BB613F7CULL, 0xD9A3DB38490DB09DULL, 0x2F0C724E411D1B23ULL, 0x11A59F63B031A83DULL, 
            0xA86D2A98A65BF480ULL, 0xE8DF461C8DAA85B8ULL, 0xCFC5F317D1C8C063ULL, 0xAA4912DBE8662C65ULL, 
            0x6F571B4672AB7844ULL, 0x8CA0107940D23903ULL, 0xECF0AECB36EC9198ULL, 0x332AC07C7C65A6A3ULL, 
            0xB56033E0005B795DULL, 0xAF83C30C71D2D231ULL, 0xB04D1895999BBB40ULL, 0xBC0E8626B1EEC070ULL, 
            0xE54B797D50165BDFULL, 0x20329BD31D3F4D21ULL, 0xC0A334D73F6E4FCBULL, 0xBAC7A3EB1F0B42B8ULL, 
            0xB6BD0E507F25260CULL, 0xCF66E0BCC7E27034ULL, 0x65FE92CE57B2C9A7ULL, 0x479B2D0E0F1FF13BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseCConstants = {
    0x4F23986BF7E7EF5AULL,
    0xDC03F7B5C46DA5DFULL,
    0xA710237DF7DCFCDCULL,
    0x4F23986BF7E7EF5AULL,
    0xDC03F7B5C46DA5DFULL,
    0xA710237DF7DCFCDCULL,
    0x846DE980F49926E7ULL,
    0xC3353FA1F43C97A9ULL,
    0xE3,
    0x7D,
    0x9C,
    0xAA,
    0x52,
    0x10,
    0xCB,
    0xA2
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseDSalts = {
    {
        {
            0x082C954E9BFE6A60ULL, 0x7D95A36936EB0652ULL, 0x6458580D321CDEF7ULL, 0xE2E2BAF96878362BULL, 
            0xE625BDD8E7C6E3F7ULL, 0x2B1B52D0F5E43F66ULL, 0xE230A2C846286BD2ULL, 0xE77D5137AE408CE1ULL, 
            0xF5E593A5CF210175ULL, 0x29D1C394163D5D4FULL, 0xC5AE39A44B587C76ULL, 0xE2AFF1BBF170CFCEULL, 
            0x8164CE1AF7DCF84FULL, 0x215926874551265EULL, 0xCAEB86B3A6A496A0ULL, 0xC100766E16AB7DF5ULL, 
            0x8A48C98E609EC6BBULL, 0xE1AFA750F107050CULL, 0x48223612171516E6ULL, 0xC3178FFD61437F6DULL, 
            0x91869F90986E0271ULL, 0x14DBD6D371B7640CULL, 0xC91C04D297158EB4ULL, 0x96500E5BB9910131ULL, 
            0x2F1E5643864F2B65ULL, 0x0BC85FEC42C680E4ULL, 0x6DF40F0D27C80742ULL, 0x100DFE6093D4D63BULL, 
            0x3A0513F5F1EECDF6ULL, 0x0FBF6900A5AA57B2ULL, 0x4A5AACE91C88CF21ULL, 0xC4A8DB0CED766D5AULL
        },
        {
            0xC3C66E76D7D5CE4DULL, 0xD8808DF478CEF5ECULL, 0x9C22F791E24FC973ULL, 0x79AC5B99D8913C90ULL, 
            0x36F50748C92CD9AAULL, 0x9F2C7758F719D0E4ULL, 0xDF7AFEB33EED0FBCULL, 0x1566D15FB50F68F1ULL, 
            0x9E2A491F3D80AD75ULL, 0x0325027EB3D2A48CULL, 0x6CF507C67E040021ULL, 0x2FF601B1AD4BA71FULL, 
            0x2ABCDC41DFB6ADD9ULL, 0xB15E7F21C3C86DDDULL, 0x9BDAC0AB93803498ULL, 0x750485077D0C0797ULL, 
            0x0843408C2982588DULL, 0x16DCB83CA6901782ULL, 0xCD78CC7623DC10E4ULL, 0xD3EE50BB05087378ULL, 
            0xB7E161198009D99AULL, 0x86FA1A2AA16405CFULL, 0x827E582A22DD2529ULL, 0x349CF6CB718AE86EULL, 
            0x313C2976FB0A65DDULL, 0x29FEDE77A6619E3BULL, 0x0C5F5377C67BE2A2ULL, 0x3A6A233311427113ULL, 
            0x3A7A2CD2B2A2968CULL, 0x328DB36790DAEF10ULL, 0x2F88E9E1C8C2CC29ULL, 0x4AB1D3D29B60975FULL
        },
        {
            0xD38DF43D3BD098CBULL, 0xD5604187DA3B9833ULL, 0x1ADFD0C0DC78BAA0ULL, 0xA77A4D11F5E824D6ULL, 
            0xA63C2AC529866A06ULL, 0xF813AB869E13FBC2ULL, 0xFB405FB11F007B4CULL, 0x1BC9EAC08E2E6977ULL, 
            0x1691368EABE020C3ULL, 0x07CB368011C10FB7ULL, 0x4C420682501E3C0CULL, 0x0275F707A2AE0963ULL, 
            0x4003E0C778B7FF15ULL, 0x694F13343074192AULL, 0xA8B3DC23AAB22EB8ULL, 0x4B1B731DEB182F27ULL, 
            0x0DF5EABEC5F9D13AULL, 0x85BDE7D1B8DC05CCULL, 0x9FBBFABCEFC2AA9FULL, 0x5179D8EAFD6028B7ULL, 
            0x3A4EBED50CCE6802ULL, 0xC84D3279601BFBE3ULL, 0x188871E84A07819BULL, 0x54AC24B9E87866E9ULL, 
            0xE254F0AB495B4FFAULL, 0xD19F0866AC2D888BULL, 0x696606D0BD97DE82ULL, 0xA4AFC38C045F6296ULL, 
            0x6A3E674442738CBDULL, 0x3F42A977EDEAE1F0ULL, 0x3BA093246B4F5C9FULL, 0x6E18076BFBE29CB7ULL
        },
        {
            0xFB85812DA9CD68F4ULL, 0xD77A2049E4F20D65ULL, 0xF098855845207C1BULL, 0x9415DD44974F6E1BULL, 
            0x9F8CE0BC066C78A1ULL, 0x1981082992292A75ULL, 0x9A6B4231F3317134ULL, 0xD944112DD63F95F5ULL, 
            0x9456D63797D2933FULL, 0x050BAC4DE06AA1F4ULL, 0x16A80F14337619F3ULL, 0x588D60C5A17DE8C9ULL, 
            0xAFD247C6D787C904ULL, 0x35BC3D44D26F63C3ULL, 0x8D270A0F3BE7A0FFULL, 0x9ACF4C1F4A4C5222ULL, 
            0xEA24FE953018D260ULL, 0x8B388ED53A1C701BULL, 0xA7CDBDED02D5E9CFULL, 0xF52E73A8448333CBULL, 
            0x8362115FFBC6CC8CULL, 0xFA659D86E3C51C15ULL, 0xED79FF852D9CD8B6ULL, 0xC65F5BA58220DB9FULL, 
            0x1223FC8F1D701C12ULL, 0x512BD15F856CDCAAULL, 0x8C20853EFAF88B6CULL, 0x265FCE688E248AAEULL, 
            0x2030B813E640E3A7ULL, 0x07F077DA9645C663ULL, 0x8E8F3DA9CB37C992ULL, 0xFDBE47F2FD13C395ULL
        },
        {
            0xFA7FC7B4F48AC3C5ULL, 0x813033888943E599ULL, 0xFA3510630270EBB8ULL, 0x0289D4AD2EEE6FB0ULL, 
            0xA69D18CA174FDBE2ULL, 0xC7E39CE25416873DULL, 0xF578635BAFDE9910ULL, 0x875490AC758F815AULL, 
            0x40EC1B363DED9006ULL, 0xD41E7A9658672913ULL, 0xC6CF2982EE8E0328ULL, 0x591D09D7291099E7ULL, 
            0xBBC9B4ED12CC2084ULL, 0x6DA477587F684BBFULL, 0xDFF3B3E04FC60698ULL, 0xE5456C9EA68A5786ULL, 
            0xAE569A6EED07BA03ULL, 0x91185C3FEADF8FEFULL, 0x3162F1CC6A9F545DULL, 0xFD3BF294E1B2BBF5ULL, 
            0xE696B4D30649A2E1ULL, 0x51E1A8C28E08AA35ULL, 0x7C348136FF1BF9FCULL, 0x395766E8949B027FULL, 
            0x6796453B4DAB3878ULL, 0xAB8A96BF49ABAA52ULL, 0xACFED804B0DC1386ULL, 0x61D79D3B6F2C3F14ULL, 
            0x5E7418D08FD36C04ULL, 0x52FA3C87966F1031ULL, 0x6D49806699434116ULL, 0x47E86CF87C243605ULL
        },
        {
            0x15741B7B53143173ULL, 0x656EECDD85079D20ULL, 0xBCD497A7E652A5E5ULL, 0xC2D63A2DEFE9F891ULL, 
            0x4323E538FEB8439EULL, 0x1659BE53CB7B432AULL, 0x777AD994DBF05153ULL, 0x4F5A1B3F58F3CD37ULL, 
            0x1CB9662F95507EC3ULL, 0xBC3EBBB9C7315612ULL, 0xBBC2589A33E63E67ULL, 0x81952A12E1253365ULL, 
            0x8C4660DBBB552E62ULL, 0x39097CEE53115998ULL, 0x7262EA8E76A86038ULL, 0xAABB8DE993318695ULL, 
            0xB6610334547FCEF8ULL, 0x0E97498BC7F132D6ULL, 0xE7C99656C43D0008ULL, 0xB490129A8AEA8D71ULL, 
            0xD3136E015463C9F3ULL, 0x904B79F8F2C3369EULL, 0xEB0629D178243F14ULL, 0xABCA6CD6435D23F3ULL, 
            0x609AC043CC904F67ULL, 0xEA8BB7EB8997255EULL, 0x9EA442710AA3EAF8ULL, 0x27B7DE996254F1BAULL, 
            0x7CCAFA7B958D4B00ULL, 0x40D615112CD2415BULL, 0x7EC13A9EF93ACD06ULL, 0xDBBC1360B833F848ULL
        }
    },
    {
        {
            0x81DF639C8B5A0828ULL, 0xB89EC172A0DBD43DULL, 0xAEFCD5C76CF55034ULL, 0x3F60DF93D4BCD24CULL, 
            0xDD10BE75DC0F9FEBULL, 0x6FE919CCBC5BC94CULL, 0xFA20CA4FB9559659ULL, 0x9727EEBA5CA7A021ULL, 
            0xB206F8F7013611A5ULL, 0x55ADFC0098BF630FULL, 0x9FCA3797BEF7E9EAULL, 0xC051146368A3C7F4ULL, 
            0xF274766F9C303E80ULL, 0x9B1D42851A8925E0ULL, 0x81CE3FB1A306DC87ULL, 0x2BE3A2F77C816326ULL, 
            0x0790985E17721DA3ULL, 0x6EF562D047F1236DULL, 0x5B503AB8EA134C18ULL, 0xC0313A4E51C31600ULL, 
            0xE21CB367EB9F7BD0ULL, 0xFE338E5FBE9B4E6FULL, 0xED054CD42020ADA3ULL, 0x65656A2B865FB45BULL, 
            0x4525708EC5EF3457ULL, 0xD8F3AEC2A66C5EB5ULL, 0xA375F50762F36654ULL, 0x6D6367F407F4AB1AULL, 
            0x2E700D8174ED1C7DULL, 0xFB65AEC50381E65FULL, 0xC777B476C2232820ULL, 0x65D80264FCE8FB90ULL
        },
        {
            0xBC46CC228CB17A73ULL, 0x8B04F1915AFA2C83ULL, 0x910A5BAEAE1873ABULL, 0xB160F2339A98FC9BULL, 
            0xA6D0E3EC8109A3E5ULL, 0xA3112C5E1FD7B7F2ULL, 0x434479F740D49CDFULL, 0x955EBECA3CBCC14EULL, 
            0xD1A4A08C636E9AB7ULL, 0x8358B916FB5A865DULL, 0x3E34D6DEFA7D7DC3ULL, 0x9E72A80F123FEB49ULL, 
            0x5B3BA7E75331D787ULL, 0x2F912C06B6A8D4ACULL, 0x720B04320280D0F4ULL, 0x7C5F40B14AA09EFCULL, 
            0xDCD0D54B146BBE80ULL, 0x760CDF502418C805ULL, 0x608C317241DF71A2ULL, 0x85255BE4F28D74CAULL, 
            0x18F02AE75FF1D7C1ULL, 0x0990C173B0EEE5F1ULL, 0x87A30E69803F7016ULL, 0xDFC30CF0D1A87B37ULL, 
            0x6A75E05373A613A3ULL, 0xD5901B189BC7DF24ULL, 0x6E5B56DCBFA6B66EULL, 0xAF37FA8AB092D9EFULL, 
            0xF926E30EB716A8B1ULL, 0x2A0C7EDB411330D0ULL, 0xACCF6FB2FE550FBEULL, 0x9B8CA1320BF09423ULL
        },
        {
            0x8FB94FE410882345ULL, 0x5362F34627D680A8ULL, 0x22A8CC3491F5A5CDULL, 0x5FD425C581698D6AULL, 
            0x4F6E1C0DA36C6E8CULL, 0x391EBC406DF63FC5ULL, 0x20617B546BABFAC6ULL, 0xF407FB8E700EF976ULL, 
            0xC355BF33273571B5ULL, 0xF1B68558A32240C6ULL, 0xD668DB83DF981D43ULL, 0x1480DDAE1C1E5F71ULL, 
            0x7988E1AAB24D5E67ULL, 0x0B79DAE94F593EC3ULL, 0xE8D12A5C24290732ULL, 0x3E71D6C79E7DBDEDULL, 
            0x5A232ABD01236260ULL, 0xDD5ABEBDACE0AD71ULL, 0x273B3579C9E0B73FULL, 0xB1D6C477E25486FEULL, 
            0x7BAEF35F22008266ULL, 0xD5FEBF579FA48100ULL, 0x37F036947CED7D9AULL, 0xFED1F10935D6E061ULL, 
            0xA45998AF46AF54BDULL, 0x6B4ED59058862F14ULL, 0xEA0864496D00C169ULL, 0xBBADE9544C97E99FULL, 
            0xFD400225A85C5D91ULL, 0x0318E6DC120505E4ULL, 0xBBE6B8D86C4A6724ULL, 0xD267B0A616B41E49ULL
        },
        {
            0xE3DF882BE5F42581ULL, 0x7937FBAEDCFCF3A2ULL, 0x2C543D5286B55270ULL, 0x445365DEA63EB642ULL, 
            0xF993C4023DB04FC0ULL, 0x4637370DD60A85A3ULL, 0xFCB2321F39D9A9C7ULL, 0x34CA04315DCFF62DULL, 
            0x0F591D86AC3792E6ULL, 0xE56D5C73DEBA1D4FULL, 0xC766D18EE41AC835ULL, 0x7EF5A4140AAECD5EULL, 
            0xBC884CA327ED4B9AULL, 0xE16E47BB6F005B38ULL, 0x511263E23BFD10C8ULL, 0x9042D83D8BEF707FULL, 
            0x8D99E724451384BAULL, 0xB193DE42EDF6D8F7ULL, 0xB73126BAAAEFD034ULL, 0x46686B823DB17BFDULL, 
            0xB7FBC255AC26D283ULL, 0x0CFC7B06272EDC90ULL, 0xA0D2C6EDE238796EULL, 0x1E4C98731592523DULL, 
            0xEBF15CCB4AED4CA9ULL, 0x940563F63DA28FABULL, 0x7A612C62F240090EULL, 0x9AE091D0D9839300ULL, 
            0x71ADCE8860155724ULL, 0x89E41EF3A051E6D2ULL, 0x03FB72BDD0C0F994ULL, 0xD957C511169F9566ULL
        },
        {
            0x0C2206E269743686ULL, 0xF0F4B7EB85FBD8AEULL, 0xB950D2805309E157ULL, 0xC6B8D3F9537868DBULL, 
            0x86473AEDCAA53779ULL, 0x412C9035F6DE8B17ULL, 0xE83D01388C1EA023ULL, 0x0BDF64B4D0802036ULL, 
            0x4CFF04718E925840ULL, 0xED42BA27ED4A4F20ULL, 0x604764379B57D0F7ULL, 0x607D60F78DD7BDEFULL, 
            0x0F2F3F36C8803846ULL, 0xA64A3C96F878CB90ULL, 0x8C6AB0F69E8C2747ULL, 0xE9DC9B10A5968802ULL, 
            0x3A17E29580A50204ULL, 0xFE57574A93AF07E1ULL, 0xA1FAA75379470A85ULL, 0x7D4BEB06D8600539ULL, 
            0x9B0F788CEEA13A40ULL, 0x2F1083F7E2FE57B2ULL, 0x8013E088D4FAFD29ULL, 0xB6C70546AEF11F86ULL, 
            0x3CE77E20A73EE1D0ULL, 0x187FAC5EE3B6C7D7ULL, 0x62E88D338210BC12ULL, 0xEBAFD48CB28C73F7ULL, 
            0xC385671DF9F80F2FULL, 0xA1E9809A4FC683B9ULL, 0xEF847F17BFFC7331ULL, 0x109D4334FD46B7E5ULL
        },
        {
            0xAF23CBF329C38EACULL, 0xD7E387E1FB3B6B46ULL, 0xBB328A79A6188598ULL, 0x8B66A4DDBDB47D47ULL, 
            0x85DD540B7BF1EF01ULL, 0xEBD8FD1ECF020652ULL, 0x083478BE8BF88239ULL, 0x4C683110F2112137ULL, 
            0xC7816CCB8E0E008BULL, 0x43C6ABE2A0E96701ULL, 0x3CB094F732FCB623ULL, 0xCD0C2051CA027FECULL, 
            0x8AD0E4541637B9CDULL, 0x0A10A7AF1D5E834AULL, 0x6E6A7C53D073ACC7ULL, 0x62075C7E20A6DC28ULL, 
            0x4F508B052F820F45ULL, 0x64DEFDAAE6292642ULL, 0x9043439EE4068F96ULL, 0xDE0FE99958EA084EULL, 
            0xE2C0C9DEA53B979BULL, 0x98B8198234707CC3ULL, 0x98683B77EB071EBBULL, 0xE9B52CC9F09CA1A2ULL, 
            0x2482905F5E82919DULL, 0x6767CDBAC28EC4F0ULL, 0xDAE8334B3B985A91ULL, 0xFDEDC4C383AEA935ULL, 
            0x3F80D3E8AC667E38ULL, 0xDC4A01A7ED323E5BULL, 0x5106AB22ABC5D439ULL, 0xC139E36D8ABFB220ULL
        }
    },
    {
        {
            0xEAB596AF33D9E63EULL, 0x6A4551ED6912F825ULL, 0x59801F9759E5F82FULL, 0xEDFAF0AFDEF51587ULL, 
            0xCA1AC3CFA229C9C6ULL, 0x4108200476E2017EULL, 0xAAD415B7D3B12A9BULL, 0x2D31B7E36F17451BULL, 
            0x94577EBC3B5C8B7FULL, 0xE1ADEB3D8F316E0AULL, 0xEE706D82F044CC41ULL, 0x1AC3E2E0B4B24779ULL, 
            0xD9D60CC1C576DEA0ULL, 0xB09BECCD73A89E0FULL, 0xBB442CBCAF37F955ULL, 0xB10D284B51459F3EULL, 
            0xB867FF21BFA6AE4AULL, 0xD3C37F3F2EBB7989ULL, 0xAA6539FDE268E96BULL, 0x142A859DB7D214D8ULL, 
            0x6D58961B9799CC63ULL, 0xD2DDF6C820792A2FULL, 0x20335E50D8E42B52ULL, 0x1D5C198987A14FEDULL, 
            0x3FD8852D24454023ULL, 0x8F825537BD2D659BULL, 0x20C76272347A52B5ULL, 0x094067DCEBA4C33FULL, 
            0x964ED7298B89BC0DULL, 0xE480B66056388136ULL, 0xAA11CAEF7A60C6F1ULL, 0x1AF7054677AE1B45ULL
        },
        {
            0xE5C0F302C16F4C33ULL, 0xDF16A348A0D7C341ULL, 0xE7CF61AE9C28E210ULL, 0x23E4775C1C68F3B0ULL, 
            0x40AC2C3539D2309FULL, 0xFF93366D97D00354ULL, 0xF999C7721BA17AB9ULL, 0x8E104672F85FE430ULL, 
            0x1D91C3E505A2F9A6ULL, 0x30559B94A215A8A6ULL, 0x7679FC87F3E2EEEDULL, 0x53DBC9B7F215E846ULL, 
            0x3C5B6DEB3FB0917EULL, 0x4993FA48FA5E6DDEULL, 0x4DBE510AF7E94C1AULL, 0x1A79E213208F7D69ULL, 
            0xF92C9B3F4505F8A5ULL, 0xA08BAB3202FE920EULL, 0xF3B6B3A9C772ECCEULL, 0x8DF9A2A7C5B3B952ULL, 
            0x9C3E6D475BF031FFULL, 0xE93AA37E29AA5FF6ULL, 0x1554C15B1E8B6B4DULL, 0x0BD1693903427531ULL, 
            0x70664B405329DFCFULL, 0x3468FD0B5D214238ULL, 0x425B170C126A2836ULL, 0xC80CA7594624235CULL, 
            0x44975BD4B731E381ULL, 0x50F55C4E59428701ULL, 0xDFCDC1A57C3915D1ULL, 0x0CFAA18F03B26B79ULL
        },
        {
            0x196D88907BD2CADAULL, 0x8E633AF38F12F1F5ULL, 0x6720DBF03E779CDDULL, 0xC554F63EE2B817E1ULL, 
            0x54D74297552A2AFAULL, 0x1755FEB3128EDA40ULL, 0xD91B24DD4CBA3A49ULL, 0x6EFE02D48E68E022ULL, 
            0x190768AAD92DB6ADULL, 0x941732E93C18DBFBULL, 0x0EDA59ECC5375EA4ULL, 0x15642D14E5F378FEULL, 
            0xD9CB2B585F8099E6ULL, 0xD618BF4CA680D9FEULL, 0x04C8F4DBABB0DDE6ULL, 0xE5E9FED01CB5704BULL, 
            0xD77C279F284B284DULL, 0x9867CDEFB77F21CCULL, 0x942B957DCEB42AE2ULL, 0x10852D2E441B3AADULL, 
            0x1CC7DEB82AE63388ULL, 0xDBA129ABE39E234AULL, 0xC354E26C94D9F6D1ULL, 0x9D6C618A82319A6CULL, 
            0x6D21789E66ABBFD0ULL, 0xE95C34707D3F89FBULL, 0xE2E1A8BCC19EBD4CULL, 0xA59917DD431498C0ULL, 
            0x0CE44FDBD853C68EULL, 0xD570DF8E4B78AFABULL, 0xA5783DF0331D81EBULL, 0xC34023297FB1A423ULL
        },
        {
            0x18CD101F6DEF348CULL, 0x62E2CEB1F8551D27ULL, 0x85ACFAC06DE8E0CBULL, 0x75B7CCDE90A5DD63ULL, 
            0x57BEDD678396C8FBULL, 0x6ECAD2FB4814408FULL, 0x553F89FE73A8ED88ULL, 0xBA3EA4F2657B725CULL, 
            0xDBF08F6FA05A307DULL, 0x947FD569163610E4ULL, 0x718F9F3C39E487A2ULL, 0x3456CC43572E7C0AULL, 
            0x543BF79C2A138901ULL, 0xD652E3C9289D31CBULL, 0x532C3AC29BC599F0ULL, 0xE58B42D01DE473ACULL, 
            0x0187336D3B21A03DULL, 0x57ADBBD94FB8D769ULL, 0x6EC1B6DEE9D89B9EULL, 0xDB0D579F114723D8ULL, 
            0xFF740FDD6D033A77ULL, 0x57B6FE8089E80129ULL, 0x5268B281A4334164ULL, 0xDF91E7ED647CFE35ULL, 
            0xD9427897147E8C0BULL, 0x7B26BA142A1091C9ULL, 0x1B574DAB1A9E19B8ULL, 0xF191F397205CD8C4ULL, 
            0x4B105C869067F112ULL, 0x89511ED814858EFEULL, 0xD8807C85C651305AULL, 0x4AC1AB37B7BCF154ULL
        },
        {
            0x58875306CC425056ULL, 0xCDED0AA9C2190F9CULL, 0x412F10D5CA441945ULL, 0xDEF7072611034462ULL, 
            0x81F849B0546DA70AULL, 0xA0A1AC2BD507900CULL, 0xB4F017B6F9AFAA79ULL, 0x74596A31F0F33246ULL, 
            0x97DBDEF82102751BULL, 0x312B5F722C6D9524ULL, 0xB8F6D2B918DAF32CULL, 0xF7F0675D5C2EF9EAULL, 
            0xDE0294C4C84C5CE7ULL, 0xCC4C4AA2566DDFC8ULL, 0x7A5FE8BBD9C19EC8ULL, 0xEE28CC24BC513333ULL, 
            0x19F3E6D645E6683BULL, 0x20E7E31B2DD6ABE3ULL, 0x5AEF9653F7855A8FULL, 0x5F4988D3379195F2ULL, 
            0x4B2AB70354A9E558ULL, 0xB9CEE4AE8DEDA1AEULL, 0xECCAA2968D1935D6ULL, 0xEF470CCACFA8D0C8ULL, 
            0xE90CE3134E172D18ULL, 0x5413C91D9BE304F5ULL, 0x940230E7DAF3C15CULL, 0x64A32D27D31773A0ULL, 
            0x2DEEBD78E23AD4EDULL, 0x1D6C5F957503303FULL, 0x93361302E3A324FCULL, 0xDA3F156622D299F4ULL
        },
        {
            0x2AA8B983303624CAULL, 0x4FBE552558CB7CD6ULL, 0x215F8C132222EE3AULL, 0x7C90CEDB4CE802FEULL, 
            0x38BF2A6E19DDB43DULL, 0xD041E013869C5616ULL, 0x0CE0E60F56479423ULL, 0x459D34F11585A226ULL, 
            0x65B8A787035E04B6ULL, 0x4C4ECF0E44A8D046ULL, 0xD4EE4D46052D108DULL, 0xC0265C23271CF068ULL, 
            0xB5E24EB517BB9E17ULL, 0x9D50403C1480AD53ULL, 0x74D66FF9A2585CE4ULL, 0xA08ED75E96E6A86BULL, 
            0xFFF33B8C3DE5A01BULL, 0x509DEEB47A921C25ULL, 0xC5211625E8BADC5EULL, 0x1F35B4803E499B08ULL, 
            0x3FD742A659D3D4FFULL, 0xBAC40B289573CCBAULL, 0xA780BC3C3FE07276ULL, 0xD6AC22CAF8786AA4ULL, 
            0x314D9579D6D9E6E6ULL, 0x36D06BA246B553CDULL, 0x2BA0621A4AEF7FB8ULL, 0x65E39163F8DDB694ULL, 
            0x5B2DE9546A2D7493ULL, 0xF32661CC4F7B8F8FULL, 0x216251CFEA2951A0ULL, 0x6AF3A0B99F04B40FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseDConstants = {
    0x6413106F93A53791ULL,
    0x25FDE02FAB82CF96ULL,
    0xD54FBC0BDEA5CD31ULL,
    0x6413106F93A53791ULL,
    0x25FDE02FAB82CF96ULL,
    0xD54FBC0BDEA5CD31ULL,
    0x95D836DEBFFA9E23ULL,
    0x2FE3802A7E9AFCEAULL,
    0xCC,
    0x76,
    0xE2,
    0xEF,
    0x97,
    0x33,
    0x74,
    0xAD
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseESalts = {
    {
        {
            0xA93CED8CCD62340CULL, 0xCF2261D6FD03CBB6ULL, 0x293AF1E1452BF05FULL, 0x23C3B15727B4CE8AULL, 
            0x85CC00384353245CULL, 0x69C5C610675BF2D0ULL, 0x75F73151EBBD5C07ULL, 0x5F709D22F66F8E9FULL, 
            0x80403100D4A73042ULL, 0x365DCFE611542EAAULL, 0x6165C7C3CBAD6C8BULL, 0xE5D6A64F5AB38116ULL, 
            0x839525522A2E9FDDULL, 0x56768AA75DB71BD3ULL, 0xE5450B5521FFEC9BULL, 0xA8F2D03CAA5BC4FEULL, 
            0xA4D1D298635E9A21ULL, 0xDAFEC3227FDC31FFULL, 0xD5643A483EBE8F10ULL, 0x2AAB3462E36CA248ULL, 
            0xCA568F44166334B7ULL, 0x0001DAF67A376BEAULL, 0xD19EF0F000B5A235ULL, 0xF6E90E9B4B4AAFA1ULL, 
            0xA51541E17F05727EULL, 0x8AEFA727BBA50AACULL, 0xD8FE0719F64D5365ULL, 0x2125B96AAF8D5D8DULL, 
            0x23FE84087343040FULL, 0x5A3BC1B600988B3AULL, 0xBE8CC5E6CF999BF9ULL, 0x8A4ADD4F6B5C3E7EULL
        },
        {
            0x13395036D659CC92ULL, 0x5A0718B5648D75FBULL, 0x1B5B223597B88954ULL, 0x833F1924FCB7506FULL, 
            0x0961147483321065ULL, 0x8F247FAFB6DA69D4ULL, 0xE83AB2D64D0B087DULL, 0x29FEA3A42622558FULL, 
            0xDB24EF6C15629040ULL, 0xA13684B9286C44BFULL, 0x3B6460751EE88978ULL, 0x006A7BEE467A66C3ULL, 
            0xF26E890C760F5A66ULL, 0x03AB86FD1C6F897FULL, 0x726069B5A6B5D410ULL, 0x3D8400D28BD165D3ULL, 
            0x1FFBE57FB131ED0AULL, 0xCEE1296EF5A22815ULL, 0x9BB6E07A09439999ULL, 0x38517F91C1AA6D20ULL, 
            0x4C29F0BFE5E59568ULL, 0xEAC6ED0AA2C97FB4ULL, 0x1CD32C7E44D8D7D6ULL, 0xFF08633D1D6407ADULL, 
            0x5C909F4D0769F601ULL, 0xBF8C949142D90D4CULL, 0xC96001F6C5073CEBULL, 0x20BAD2B7A2B20221ULL, 
            0x9902D9DFDA75CA6AULL, 0x03CA2DA297C6A462ULL, 0x5CA3518877D73882ULL, 0x66D692FEBF5F704FULL
        },
        {
            0xCAD7C3D0ED788699ULL, 0x4B9F1BAC630D7D0CULL, 0x3B23AFDB422151F0ULL, 0x0AB2FF64B68DC0A8ULL, 
            0x353EF147BCF78F50ULL, 0xD863AE10C8FF2EA7ULL, 0x59FE0DDA663F1CACULL, 0xBF1B14E52C28BE7DULL, 
            0xA894D749E09D39EBULL, 0xB483FEDDEDEFD50BULL, 0x5ED315D2C020EB88ULL, 0x5F8B1B06A2795FA0ULL, 
            0x45F10D4B47EA488DULL, 0xE540A5771CCA19CCULL, 0xCD5782B3F594FC31ULL, 0x8914EC1DD5FE7249ULL, 
            0xFC79EBDDC329863CULL, 0x123DE7580615AB8BULL, 0x494E4AA0DBB1E4E2ULL, 0xBC00175DCE5E93D2ULL, 
            0x5B07113CC75DEB2EULL, 0x20EED563A1385A8BULL, 0x44E36A6E15E472BCULL, 0xE7BE61D44FCF04CBULL, 
            0xCABA37C3C02DC942ULL, 0x7D4F92A23E082E86ULL, 0xB91AD780805984F2ULL, 0x7727B99CBA7CD30DULL, 
            0x6FB7AAE54E88C18BULL, 0x03194022B7EA4BFAULL, 0x5D03A60E1552ABCFULL, 0x4AA7C0121A4B023CULL
        },
        {
            0x4D7B9095E9DB3F3CULL, 0x2244939A4FB36653ULL, 0xBF490746F601D118ULL, 0x16E427D97E737CBAULL, 
            0x9DE13B29C3D76190ULL, 0x4B2B60EE1FDB627DULL, 0xCADF04A180FF75E7ULL, 0x5A932DB2864EF4E2ULL, 
            0x12551A5BDA40BFF4ULL, 0x31D3BEF5206F3823ULL, 0xC735585FA2C2F176ULL, 0xE391DDD2ABECA491ULL, 
            0x0D40BF132F5E83A8ULL, 0xE531E4E2F3599442ULL, 0x87EEF727950FC16DULL, 0xBA79B752CABD4E78ULL, 
            0x2F8A4E4F477462CBULL, 0x735A38C9D7B97DDDULL, 0xA4DC12D3220D583BULL, 0x9E5B69170D23FA05ULL, 
            0x5F2325CA2D59908DULL, 0x911E71ACD9ACCF45ULL, 0xF7B89AE4EDB60DEFULL, 0xC70A629510077A86ULL, 
            0xA94D35EC7DA1A222ULL, 0x79E514378ED7FC6CULL, 0xEE2B5E1777A233F7ULL, 0xCD2E9BFD4BDBB5FBULL, 
            0x57660FC5D444E289ULL, 0xDEC8DCCC79E19433ULL, 0xE294E1CD7A39094BULL, 0xBA757D22E710E6ECULL
        },
        {
            0x8B5E4C4538E8D736ULL, 0x99BC95E4E55A705CULL, 0x8C24F42B72D4BA56ULL, 0xC12E086CC9386796ULL, 
            0x2E84F3309188D30EULL, 0xFE73E3DB57874EC7ULL, 0xCF4F4637710BB9B8ULL, 0xB7E2B8BA6BAB97CCULL, 
            0x385DD90BBA4D0B4EULL, 0xF63DCC0ED7E5D649ULL, 0xC88032CB5C7EE723ULL, 0x94EC6BB3E6495420ULL, 
            0xB0640DDEC2605300ULL, 0x6323354EAE49DC94ULL, 0x9381E14987D09F9CULL, 0xECE3F3214845DEC2ULL, 
            0x816AAA36EE00BEF9ULL, 0x82050E0393A1C020ULL, 0x6E46DC62ABC7B15CULL, 0xAAC1B30BBFE801FEULL, 
            0x309C67509C6B9062ULL, 0xCC157580CD4341A7ULL, 0x0AA617CE8D81F0B5ULL, 0xA8F495F12223BFA4ULL, 
            0x54230C2ED1AD26CAULL, 0x4FA9B1A87E0024CCULL, 0xBBAAC38FC523FABCULL, 0xDB374F78D7218B58ULL, 
            0x384FA7F67B326B2DULL, 0xCF4C4D7A6A2AAD93ULL, 0x86301F6F6CAC2DD0ULL, 0x07E20969E27D54CDULL
        },
        {
            0x794788A1A5D5AD55ULL, 0xC5965CCA8DA6502BULL, 0xC6B11EEFB067410AULL, 0x906CEE471F8B0784ULL, 
            0x38402C8C487E1529ULL, 0x670F57F34044FC90ULL, 0x0F1EBF50BC6821EBULL, 0xFBD4E2442F4D6033ULL, 
            0x08A7F282A693A453ULL, 0x3948CF54FA131382ULL, 0xBD277E236BEE1DFFULL, 0xDC655801AE75C90DULL, 
            0x8ADA784A8E27165DULL, 0xA211C953B64FCE7AULL, 0xB995C1025470714BULL, 0x7D7A0A3D4B390830ULL, 
            0x74D8F35888B0065DULL, 0xE614AF2816762DB8ULL, 0xC0FC42FB6A514F4DULL, 0xCA139FD2E9E728E8ULL, 
            0x70BD23C7868CAFC0ULL, 0x9B76631609FFF540ULL, 0x515E03E6CAC8D4BAULL, 0xC2F273C7EA14EE07ULL, 
            0xF28AEFDDBC1392A1ULL, 0x0BB41FDFF1F8CEC4ULL, 0x6AA8362BB7F5CD2FULL, 0x860C5513DF678218ULL, 
            0x0477AFB051002C4BULL, 0xD56B2FD7CB2164FFULL, 0x24F727E2074A436DULL, 0xB3303B73475A7787ULL
        }
    },
    {
        {
            0xD587B598430F3F07ULL, 0xC52D076E7DE639ACULL, 0xCEBFF91C94A565E6ULL, 0xB3851C2F9A09FC36ULL, 
            0x78FE96B93E46FB8DULL, 0x43B7C4CB1D337E6CULL, 0xD44225B96AEFEBB4ULL, 0x1BA3D4B76D76D6C1ULL, 
            0x36FF45F58493FE6CULL, 0x53F4170CA380FB6FULL, 0x86658BB32D9CF4E6ULL, 0xC5FF3176F69E6CF7ULL, 
            0x2B017265E9F02FA0ULL, 0x241FC658FB94AA13ULL, 0x6A3BA573B69E0F03ULL, 0xA0A4A917E440C7E6ULL, 
            0x2A4A8743B7218CD7ULL, 0xCF3D31CEAE46762EULL, 0xEC433B99D9B59C2CULL, 0x08A1EC1E51C33D54ULL, 
            0x34324A6469A03D07ULL, 0xF7212B976A70A4B2ULL, 0x73221E257BFE75D1ULL, 0x0F5B9B72846B6706ULL, 
            0x1AB9110672682F95ULL, 0x0B5E6A90E903E68EULL, 0xEFD1E9773FC7ADAAULL, 0xE4B542131D6511FBULL, 
            0xF34F1D6008076DE9ULL, 0x0BE36E2DBB58917AULL, 0xC2805656B987F7D1ULL, 0x19F71F9B6EF1161BULL
        },
        {
            0x8C6FEE4739B8D897ULL, 0x20D801163A5959FDULL, 0x45C246282D1EEAA6ULL, 0xC3D12E818CFA7F88ULL, 
            0x19988B80FE9835A7ULL, 0xB8A1D88F402B1E8FULL, 0x0BFBCC39FDF30BF0ULL, 0x22BEFEAEDD2E8C72ULL, 
            0x11CA57DC3A6D18AEULL, 0x7A9086F43B00DB37ULL, 0xFC198E21C035E6AFULL, 0xA3C07C5823F87AF2ULL, 
            0x8CEC1E22B693CCB1ULL, 0x2FCA558B0F28EA4CULL, 0x5C3ECC4439D62184ULL, 0xE4327A44927FDF6DULL, 
            0x8C61AF7AF8A046BDULL, 0x3EBF23E34294855BULL, 0x4721A3CF7E05C984ULL, 0xDE42954898A13B0CULL, 
            0x93434794D0828827ULL, 0x530B7EAC0F0C85BDULL, 0x8BD61658AD0BF81DULL, 0x8BAEA97AD4A37B50ULL, 
            0x53A31CD8DE007BB8ULL, 0x95C3C52D11CA416CULL, 0xCBD08D44E2820576ULL, 0xBA8A9E9088D6F2C1ULL, 
            0x6A3A2A99C8ED7D15ULL, 0xF0A9A7FEB105DF1BULL, 0x22BBFA9356709ACBULL, 0xDFC27B94C7892A07ULL
        },
        {
            0x641A1CF79E774619ULL, 0xA0A5F4DEB9BEA929ULL, 0x5CAE632548F7A4E3ULL, 0xC828307E3130F47EULL, 
            0x101D92E3DA70AC40ULL, 0xD9282F6C929DAA5FULL, 0x22AA63D264B52C13ULL, 0x6B70FAC5FFD1F272ULL, 
            0x8326381C09EB69F0ULL, 0x4095216869C5B8DEULL, 0x7965C7D488AA8257ULL, 0x54B1974E14616A93ULL, 
            0xEDF9685D242D2EADULL, 0xAF53B18593A236EEULL, 0xE584FD9FBF16F77CULL, 0x02D02EB9028E434AULL, 
            0x42B06151C09FE561ULL, 0xF91A71E1E533ED08ULL, 0x7F5338AB724EECA3ULL, 0x15EE504101D7D6C5ULL, 
            0xF1F734844CC9E0CFULL, 0xA01A934ABE4E9182ULL, 0xEDDE1E399D930FF9ULL, 0x313E141D5F433ACDULL, 
            0xCE5B56BDCE7A643EULL, 0x17C22CEFA453BDD2ULL, 0x3B6A75931D95E6F4ULL, 0x912A3095C927A4B7ULL, 
            0xD8D475714262767DULL, 0xF25462F990DD33ABULL, 0xE79F535474ACEA35ULL, 0xCFC17DC7A1AFB25CULL
        },
        {
            0xCC4F42F88F5CF9F9ULL, 0x2487D777280DCA7AULL, 0xAA4B38207BB3D4A9ULL, 0x7BD590BA13305743ULL, 
            0x0BEFD5001F4BCA34ULL, 0x5637E1B2E91DD080ULL, 0xD4ACB035B88565B4ULL, 0xD9B24A962E319494ULL, 
            0xFA788A7B3A15C846ULL, 0x3EF093D37CC93D96ULL, 0xA8DCA8D90AC9B89AULL, 0xC92A12F68E495E6EULL, 
            0x5EF31E210A31290EULL, 0xB1E7B32055BA2139ULL, 0xBD612C53BC872CF5ULL, 0x4E74FBFB814FCF29ULL, 
            0x88F2D189FFE2C787ULL, 0xD5D7E271304605ADULL, 0xD6FCD5FEBEBC72F6ULL, 0x4E90F735E43E3A82ULL, 
            0x29CB8772DE0270F5ULL, 0x63621A33385C1325ULL, 0xCCE395C05DEBF035ULL, 0x44B193A092449A7BULL, 
            0x9CFF9C6D5E4A343BULL, 0xCBACCB1C194B367DULL, 0x8D2A894BC7CC153AULL, 0xB2B213415A850B5BULL, 
            0xA3649BADC1629FE6ULL, 0x88520DB2AC1E6B07ULL, 0xAA8C7E64DC49F453ULL, 0xB6100EC734681F20ULL
        },
        {
            0x6D30C81FAA76CA83ULL, 0x9C3B937236DC57D4ULL, 0xC1E2979EABA9110BULL, 0x0FEB1C9DD465C765ULL, 
            0x8A7EC2CF0F53AAD2ULL, 0x6EF4BE297776AAE5ULL, 0xEE17AE73B0F23241ULL, 0x5455A1416FC42A14ULL, 
            0xCE83ED9E08F34024ULL, 0xFC0104DDB5230251ULL, 0x73F3D224EB0D44F1ULL, 0xD46D44149B3DC6D4ULL, 
            0x35B64F3D78626D87ULL, 0x21569C3D77657191ULL, 0xCC9E8C85EC0ADBC2ULL, 0x4E416CCB9FDE12C1ULL, 
            0x2DCCEBE50B6099E3ULL, 0xADA3624CC2C87F1EULL, 0x4BBCCACF02F44675ULL, 0x44B54AFB57972B25ULL, 
            0x7997090807AFAD2FULL, 0x7039D63946416556ULL, 0x6A28B33E5122E29FULL, 0x8B79585200659092ULL, 
            0x9469D42024F3D4AFULL, 0x436541BE0D351DC5ULL, 0x49A823056DD1FA51ULL, 0x43BB7041F8DA22B7ULL, 
            0xE46001E9D0A70E43ULL, 0x52FEB31D10332BEDULL, 0xD13A145911D22393ULL, 0x1E68774A76552B9FULL
        },
        {
            0x3E1506D33C798789ULL, 0x9D8C7F9B78165EC2ULL, 0x8E26F014470DFC06ULL, 0x4F06B7258E9DD9FDULL, 
            0x9D1D12B02CBCEF01ULL, 0xA1485EC5566A76C7ULL, 0x2FC642EF381217B7ULL, 0x520A47C4DA775039ULL, 
            0xBE86BA7FAA6ABA86ULL, 0xBC97DFD5A890FBBCULL, 0x7E2938C05FBCA8B8ULL, 0x0D0AAB8685A7B5E1ULL, 
            0xBB205992FAC7CF89ULL, 0x7BAA7B3EB7C01A83ULL, 0x05CD17716C5C66CFULL, 0x8F8593CF8491B153ULL, 
            0x144BDA4D83D9D5B5ULL, 0xB67F9B9B209ADE80ULL, 0x253C8C1215E1EE26ULL, 0xEC4F8FB2DB8C6663ULL, 
            0x97BCC60490DD41B1ULL, 0x4E296C4D2DFC8DE9ULL, 0xC1BFF55649CCF648ULL, 0x530590CFA7E02263ULL, 
            0xD38F75D1A31489CFULL, 0xC9CB728DA0C220E4ULL, 0xB2599D640FDFCB1BULL, 0x5519766756765CFAULL, 
            0x2F53C71186DB7312ULL, 0x0F1A8DB190569CF8ULL, 0x589E36FC3DC13F6AULL, 0xF99DD50B482354A3ULL
        }
    },
    {
        {
            0xE08ACA802654DE47ULL, 0x15A8AFA9035A89C1ULL, 0x88266F03D1551567ULL, 0x95E10C684181E047ULL, 
            0xB27AC4D532F2ABFDULL, 0xC50FD6D11DC8F85BULL, 0x43D3AF35ED1706B2ULL, 0x957BA83D2E0ECE02ULL, 
            0x9A72C5780918EFD0ULL, 0xD4C51BBB58B3AFE6ULL, 0x04517D64BEEBE3E9ULL, 0xAD465D6C7FCA7E4DULL, 
            0xC15667ED7967A24EULL, 0x65142741BBBFAA3FULL, 0x67556372789FD1C4ULL, 0xE04C572C894F8988ULL, 
            0x07705A2459369FC1ULL, 0x39F5E558F2E23258ULL, 0x4453E5FFD06340CDULL, 0x3B4A2A6EC16CC591ULL, 
            0x970D795012BF4345ULL, 0x1DDE550CF63EFBFDULL, 0x115008C3EDCD04B8ULL, 0x087A160A74D6A207ULL, 
            0xE71A443EFF95A0E5ULL, 0xDE1AEEAE9253260AULL, 0x6F052EC9C520355CULL, 0x9FF2FBA367759A6DULL, 
            0x908F5DB5ED793B66ULL, 0xCC1ECD89ED5FD6E1ULL, 0xEC33D7F6373EE5DBULL, 0x1B854AC8D8ACCACDULL
        },
        {
            0xF3964686DBCB1610ULL, 0xED30C317686978EDULL, 0xE3E661A95F4B53E4ULL, 0x5BB60F71E02FBD46ULL, 
            0x704A4421F65D0FCCULL, 0x00C78DEE881C60A4ULL, 0x91A35BDC7A47C698ULL, 0x7CD812EF5AB2667BULL, 
            0x53D1CBF3C0BF6B8AULL, 0xF96B665DF035B875ULL, 0x626E993E27A50086ULL, 0x7CB8A0D9D1429EB4ULL, 
            0xBD3CE32F8CBCDEE8ULL, 0x4484B29364B4370CULL, 0x428AD83B155550E7ULL, 0x1F579FB2FCD1A0D1ULL, 
            0x5954C2CE0237D8CFULL, 0x1D330464A9B3E0C1ULL, 0x5713117F3D68B16BULL, 0x195610122809117AULL, 
            0xCF5AC7E9654D95EFULL, 0x6547BCD4F3CDA718ULL, 0x1385574C237A7EA0ULL, 0x31419530124403A7ULL, 
            0xF1A350B7C7EEDF3BULL, 0x0DF63CF01B8247CDULL, 0x845A6A10C96166A6ULL, 0x31858A0C3FC8F2AAULL, 
            0xD3F8A1E67D3C19E2ULL, 0x3C5520A9605EF8E9ULL, 0xEBBC8F620E5874FEULL, 0xB6A56F0F1471BD39ULL
        },
        {
            0x902A37498153AA37ULL, 0x78064C6D5E4ABEF4ULL, 0xDE9B58E5E243434CULL, 0xCC1CEF7CC2B67AACULL, 
            0x12F79ECF5A8F5D1EULL, 0x25CBC8DF6A9F7918ULL, 0x52D19064652C1FDEULL, 0xFFBFCE4931C0C2D8ULL, 
            0xFE6F4D253C35BE91ULL, 0xA297714015FDBBB1ULL, 0xDBAC2AB9DE9D9CFDULL, 0xB84DDB57DDC8D5F7ULL, 
            0xE314ABA9CA68CEB4ULL, 0xA87890C11EF4A366ULL, 0xE121CA0F67A6E6E7ULL, 0x63BE84E417FC63D6ULL, 
            0x4232533AD7350429ULL, 0xAA3896CA0ADD8572ULL, 0x5797953A26F097E1ULL, 0x968C901DB5A64904ULL, 
            0xEC51839AA5BB6E00ULL, 0x77B1AC276754C4E8ULL, 0x3BAFDDFFC710B63DULL, 0xB98C8CED81A31187ULL, 
            0x4F44175DF8B099A8ULL, 0x7BC924615EF4B59EULL, 0x2B2FC55ADFB831A6ULL, 0xF9C3A2C67CE800BFULL, 
            0xD669DDC562702BFFULL, 0x0623DEB5442A6FB8ULL, 0x78EA6AD102114F66ULL, 0x416A82ACFD3E6C8FULL
        },
        {
            0x7732017DB2AF1DD3ULL, 0x008D51C65297B659ULL, 0x586B869893EEB7DEULL, 0x2B364C3788D8FF6DULL, 
            0x1737200AFCFCFCF0ULL, 0xD78A8E3A6AF99E1AULL, 0xE05A7163E70C4D9BULL, 0x4A851550281BE8EBULL, 
            0x4BDC5830E3AE32C2ULL, 0xDB79069B37B591A4ULL, 0x4322EED5F527C660ULL, 0x0ED341402F429AD8ULL, 
            0xD7DDAB1463B68273ULL, 0x97BB80E228A1CD4BULL, 0x430526D6DEE78C37ULL, 0x9EC8D85E461B4792ULL, 
            0x3C475EA43F6B092BULL, 0x4B509E86F52FF46CULL, 0x3472465615A94C96ULL, 0x823E43BF6AE29A75ULL, 
            0xAC7DA4CFD2581B77ULL, 0x5F3E49CE999091CEULL, 0xA497DC9FE312B9B2ULL, 0xE59669D0D293ECD0ULL, 
            0x6A8D11EE6717B70BULL, 0xFA0A7AB6AE749EC1ULL, 0x69A435A08FBD8A66ULL, 0x2B174E533119767EULL, 
            0xA6B1E8515CA93810ULL, 0x54B9547B41C073B0ULL, 0x8D049FD8A178B953ULL, 0x74F9F7CFBB49C997ULL
        },
        {
            0xD5F816256C2BE914ULL, 0x508FB426FA91D887ULL, 0x3D67209A419390D2ULL, 0xBCF7DA48609B9E02ULL, 
            0x416C20A0EB89C0D4ULL, 0xB9FAD893BACD2641ULL, 0x7F95CF937DC923A1ULL, 0x3C330442EB5602B8ULL, 
            0xCD53BEE37F231D70ULL, 0x2FFEAC62BD7DABCEULL, 0x82198E19D9B4B516ULL, 0xD213A578F9815A51ULL, 
            0x5AB2AA9001C09F39ULL, 0xB89B11D5029FCDD1ULL, 0xC123FCED634321C9ULL, 0x26CEA2189CAE6CD9ULL, 
            0x4E0C95C0D5E097C7ULL, 0x242363DFDD6B84E7ULL, 0x0ED8BBF758EAE96CULL, 0x50244F6ACD2894CDULL, 
            0xF04923FBF942B1A7ULL, 0x33F314A266908929ULL, 0xF894468B53B0B2A1ULL, 0xB2BC7C1E74E6C9DCULL, 
            0x6A1378EAC21F1235ULL, 0xB9FDCA86F217E3A0ULL, 0x343C48741DE96312ULL, 0xF2FCABE44E1A1259ULL, 
            0xB39CAB73DCB3937FULL, 0x959D106619DDDB4BULL, 0xEB0142D4588543CAULL, 0x6FA904E63382ABA4ULL
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

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseEConstants = {
    0x25CC737E0BD0D5AEULL,
    0xDFC5D553393CC16AULL,
    0xC913A8E67DDECACCULL,
    0x25CC737E0BD0D5AEULL,
    0xDFC5D553393CC16AULL,
    0xC913A8E67DDECACCULL,
    0x69C20FB8F836CD82ULL,
    0x8D1D1E7B4393CBFBULL,
    0x59,
    0x19,
    0x53,
    0x46,
    0x5C,
    0x82,
    0x60,
    0x27
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseFSalts = {
    {
        {
            0x038A025A25A5082CULL, 0xE2504E84D563682DULL, 0x75CC6BBB85ECF09AULL, 0x467BA26AEA554DAFULL, 
            0xEBF5B2242284F4B5ULL, 0x52200DF390E2F72EULL, 0xC6CA5F4261D40CA4ULL, 0xF88C192BDDDA2E51ULL, 
            0x0FDFC59D0ED30852ULL, 0x1F136F5206155957ULL, 0x816B2E83D8682CF5ULL, 0xB44BF8AD381E0A46ULL, 
            0xA9B9AD48D41C5242ULL, 0x1BF446876C9B71C7ULL, 0x9DF0C37B58AEF21DULL, 0x639096A0B67813B3ULL, 
            0xDDEA17263F80EE0EULL, 0x49674DFE873457A2ULL, 0xF9F354AA431701A6ULL, 0x837B25D30553B536ULL, 
            0xBE915B50847934BDULL, 0x46B2113B08E77033ULL, 0x1914C392F0A2BBE5ULL, 0x8A36F4D8CC9F51FAULL, 
            0x31655D937BDF6F20ULL, 0xF1627D881FEC3085ULL, 0x190CBE938B2363C4ULL, 0x637241B785513392ULL, 
            0xEAD00E094AB6996BULL, 0xF24E89D09FBC29F6ULL, 0x02ED7B56B2CAEEF8ULL, 0xF40F401820369D49ULL
        },
        {
            0x195163B9317B30DEULL, 0x7EDB2E5993F163CDULL, 0xE28AEB0D1820F449ULL, 0x79BBDC6C2EAAAD85ULL, 
            0xD53A79DA773C5AA9ULL, 0x7B5C492D28241379ULL, 0x9E2A51B248549841ULL, 0x990DBEF401555D71ULL, 
            0x3B67513B513D553DULL, 0xA916275CB96B798FULL, 0x8B8EC6A11451F7C8ULL, 0x6D23D13ED85D4C85ULL, 
            0x0E50620A5173AE50ULL, 0xEDFE2DF98D24E0D2ULL, 0xB34476E888DB597CULL, 0x66550F29DD199B99ULL, 
            0xEFB2330D7E1E80F2ULL, 0x90CBEFB6C9D54AF0ULL, 0x38AD09D19AC0875CULL, 0x9F55B2883667AFD8ULL, 
            0xAD042647A69311A3ULL, 0x893749112759EFB9ULL, 0xD3D663E9F341FE71ULL, 0x79EFC3E32D1BFAAEULL, 
            0xB52AFBF4362A7657ULL, 0x9B99B99750248DC4ULL, 0x6165A619565C6411ULL, 0xA42EDD8A757AB59EULL, 
            0x7C6E1C4375601685ULL, 0xD9588C77AF8C20ACULL, 0x3F8AC447DD18700FULL, 0x387D3D3EAA1C00A6ULL
        },
        {
            0x91EFEE7F6BF1F72CULL, 0x452C18C237FE14DBULL, 0xD6928464F80EC6A7ULL, 0x4086AB2A557BCAFFULL, 
            0x23C376BB5CD4C315ULL, 0x571023486C27A46DULL, 0xEB1D7C117027B1D0ULL, 0xE1F6D82F9D73194BULL, 
            0x9B72BAC66A2474FEULL, 0xB6731634B57A3372ULL, 0x90CEF53022A9E360ULL, 0x84E2B76E02A3AF9AULL, 
            0x1410F37897151567ULL, 0x60BB3B49F9E05857ULL, 0xEE39C3A0CD91A404ULL, 0x180812C77648FAB5ULL, 
            0x7737102BA8C20636ULL, 0x4F9073F57F72FFC8ULL, 0x5AC1E0464A5238D6ULL, 0x74DFC91EDD2CB5ADULL, 
            0x57724664575F5E37ULL, 0xEBDF1A0E823155BFULL, 0xFA742BF018B2A4A8ULL, 0x1232FA8FCB8B4115ULL, 
            0x831320B0BE7576CBULL, 0xD02F241FCE621E3AULL, 0xEC336577018E7D52ULL, 0x06B36FDA9DDF7A4BULL, 
            0x054C98A086C0592EULL, 0xA15A3D2D443D2157ULL, 0x1CE06A79391C9201ULL, 0x8EDE591B6519D3F3ULL
        },
        {
            0xE705B0D2B2D79CD2ULL, 0xD7061BC4B67D9A0DULL, 0xD741895E3A3FA633ULL, 0x9FE88595088016E1ULL, 
            0x24D402277CF40826ULL, 0x909A2030295A7803ULL, 0xBA0981C81439F8FEULL, 0xE23C8D9CE8059B30ULL, 
            0x5AB20A3ED354D607ULL, 0xEFA9430CC7D50176ULL, 0x0B9AA1BBBC3D9DC0ULL, 0xAF4E636A0CEA5F52ULL, 
            0x65F4EA01910403A8ULL, 0xCC0300C249E68D60ULL, 0x2D6F36E3777B87DEULL, 0x38F43B8102445E48ULL, 
            0xE6C972BB91E7589FULL, 0xFEA6C6A2D612B310ULL, 0x4CF82FF01DF8E623ULL, 0xA73EB8E096D04504ULL, 
            0x888F718718E96A95ULL, 0xB5033B8C68FB0164ULL, 0x4C34FC4486ADF6DDULL, 0xE85AF4F9A126C280ULL, 
            0x4D59C3CE697314B0ULL, 0xB465E22DDEE8FAF5ULL, 0xE44766E16239924BULL, 0x28C8BB514AE1B1F2ULL, 
            0x195F59801D0183FDULL, 0x80846EA9AFF3C3C2ULL, 0xD8652E62D5CFF43AULL, 0xF19061426387A0D4ULL
        },
        {
            0x0201C81B01B41CD4ULL, 0xC11D45D261312BFCULL, 0xD501D94D3C7803FEULL, 0x155819C941D9D1F8ULL, 
            0xA9CBC8BAD296A00BULL, 0xF018C1A7D172526AULL, 0x295AA8C46C40B8CEULL, 0x3D574A208F603D18ULL, 
            0xE7D3C771AB367988ULL, 0x491E69A7B2D77218ULL, 0x93CC1FA1EA45E9D6ULL, 0x0CEAB2F2AFAE701AULL, 
            0x52F5326A350D1615ULL, 0x75824FEE71D5FD26ULL, 0x9B300FB1C19B7B71ULL, 0xD3ABEB5C4A82EE4AULL, 
            0x0E04FD423C9651B1ULL, 0x8BE076AC5BCE6ABCULL, 0xDE5E80BD72E8F9D2ULL, 0x72D4E9E56B0D2931ULL, 
            0xB75F5A4C54682E70ULL, 0x61C6455AD091711DULL, 0xE65C260DE1B1E3B1ULL, 0x49BB20C9F5F8332AULL, 
            0xFFF4F2A43E9FDDA5ULL, 0xC5D97DACC28523AFULL, 0x34EA4126823A43EDULL, 0x2B19C8A61CF4AE25ULL, 
            0x7E83A4567F88686CULL, 0x7B814AE24B98B591ULL, 0xCCDE7115F339DDA1ULL, 0xB47F2916B6F7D07BULL
        },
        {
            0xD4CDB0F68322FAD7ULL, 0x318583A409DDBF71ULL, 0x315FAB64AEB79CCCULL, 0x65463D797B120692ULL, 
            0xDF95D9EA6D794A78ULL, 0x87451001E29A6D47ULL, 0x4E069EE896257B6BULL, 0x52015BA3CDC864E9ULL, 
            0xDD21EDC1A7B86D4EULL, 0xF3BA712FDA3EED72ULL, 0x4594B14A65039C0EULL, 0xD93AF6FEA163C73AULL, 
            0x4806632D39D5EEBDULL, 0xA3C1F5E4052C9CC9ULL, 0xF172197D121C195BULL, 0x3C5C98A7FFEBFB45ULL, 
            0x3B07CE7161E78261ULL, 0xFF706BE83119DE95ULL, 0xD3EBC77D5A18CB76ULL, 0xD411089017AB7FDAULL, 
            0x449666FF7A0E7377ULL, 0x8204ED840BB5CF8EULL, 0xAB460FEEE8F6C560ULL, 0x46801DB71E347974ULL, 
            0xA74DD179A67B74AEULL, 0x6F5CFAF2377AD328ULL, 0x8261DF7E9CE746A1ULL, 0x16CB1800065CD507ULL, 
            0xF3F3B92924A994D3ULL, 0x2CAD33192A37D8B8ULL, 0xCA9A72369B06B564ULL, 0xF756F008F868670DULL
        }
    },
    {
        {
            0x001BF2CA6EF49739ULL, 0x9998267D6978ECA3ULL, 0x40C30870448CF157ULL, 0xB2D0B5C527BA07FEULL, 
            0x94A3A8660260811CULL, 0x5BF41D02DC25DC77ULL, 0x1E0F94176046705EULL, 0x6C39BDB2CEB5C6A5ULL, 
            0xACA74551865577B0ULL, 0xC6FDB848158F0148ULL, 0xF49602551EC7799EULL, 0xA5DCDF939AD11F8AULL, 
            0x0A4FDF3801127B2AULL, 0xA54176E13F90189BULL, 0xEE686683ED5B6905ULL, 0xEB2AF7D75E6CCAA5ULL, 
            0xF1A85D430231C7ABULL, 0x0BD7DC89F2A46471ULL, 0xDDFD5D66554FB015ULL, 0xF66C67CB4E84FC3CULL, 
            0x6DE28AA736393EABULL, 0x560B8AE88045C55AULL, 0x6795D217759A75B5ULL, 0x66975B9AAEA4E5F9ULL, 
            0x771E3790E44342CBULL, 0x8EF30E60B650A40EULL, 0x3E4DF2E1C005BA65ULL, 0x55BC94EB26249559ULL, 
            0x7D925BA27691D30BULL, 0xC0789D0DA5B41F42ULL, 0x0BB2C9781783B724ULL, 0x982E430F504CBEA5ULL
        },
        {
            0x6C43D0349C639017ULL, 0xDD11D8DF1A3E4CF2ULL, 0xB7352CDB640CD593ULL, 0x891C09DC1BCEE0E1ULL, 
            0x27BECDD4DB5A71E7ULL, 0x2C5651943B9E2B1EULL, 0xBD0AB34CC5334E54ULL, 0x28FA3900FE011005ULL, 
            0xE4303C515BC59396ULL, 0xCE5C52BD8BD677B0ULL, 0x2B0FFE3EA76B33D4ULL, 0xF3BC95D5E174F690ULL, 
            0x523F299EE336DA89ULL, 0xB6B0901976E11D2AULL, 0x602C442CFD0D0AEFULL, 0x7EA52065265B2360ULL, 
            0x3199061ED6FD158EULL, 0x7E2BA62B80B457EEULL, 0x93665365A0D750C5ULL, 0x36DD0955413C505DULL, 
            0x2529C9586273EEB6ULL, 0x8DE68477E28A22C9ULL, 0x765A0093A0A40B0EULL, 0xE292DAC2CBF85501ULL, 
            0xCEE344D2E60E8D57ULL, 0x98A906F8F067138AULL, 0xFE696BBEEB8756C1ULL, 0xAC2F3DC5FDCC7B8DULL, 
            0x3877676310F41D59ULL, 0x08EBAAAFADD2374CULL, 0x4BBDE67150A73D66ULL, 0xB297EEA703AE2ECCULL
        },
        {
            0xFF43BB1C3DDABB31ULL, 0xBAB313F774F4E1FEULL, 0xB2638146F31AA01FULL, 0xAF9DF506812F9979ULL, 
            0x84CEC9948EFFF23FULL, 0xFB640ED5230C16C4ULL, 0x1F7C2A7ED7013083ULL, 0xF43A357B0D9AC684ULL, 
            0xCCCAFADEAFF670C6ULL, 0x2CA081BF7F6F1880ULL, 0x6C79A37F32909219ULL, 0xA080F588EA17C753ULL, 
            0x30A36B6EF742B965ULL, 0x2553C1189C193C3BULL, 0xB78872193152F649ULL, 0x1879F627E5F01A57ULL, 
            0x9DB8867D2A9C9438ULL, 0x06EBA2C401E9D297ULL, 0xAD41573958A317ECULL, 0xFA68E5065AFF7A92ULL, 
            0x88B9043169F3AB21ULL, 0xE37A178A81DADFC6ULL, 0x803754E26C8A95B7ULL, 0xC11A2F5A233ED96EULL, 
            0x19858D849C5CDCA7ULL, 0x07BFA153FE4A8C61ULL, 0x8B7F37845EFFA332ULL, 0x4A3578A6F5B9C57CULL, 
            0x248870737EC5BFB6ULL, 0xEFEC416B2F121528ULL, 0xA1D7FEE93750426CULL, 0x8F4179673B6D9F1CULL
        },
        {
            0xBCF88C6B4F341405ULL, 0x8A27148A803B3509ULL, 0x565A537B98A422C2ULL, 0x911641161A6E0CB9ULL, 
            0xCCF17DA1DF3E45B3ULL, 0x012210D83A1313D2ULL, 0x7B6DEA034EAC6E65ULL, 0x8840C0A1CBBC70ABULL, 
            0xD4886813352AE38DULL, 0x2C131701D7148DF3ULL, 0x33400FCC936B1277ULL, 0x978DFB71F25F61B9ULL, 
            0xBB0F78861D82B987ULL, 0x21861BC3B9458AF8ULL, 0x96178D3107801763ULL, 0x29E5E9DDCE028A97ULL, 
            0x05BE31A2F6377697ULL, 0x26AC540E2618C02AULL, 0xB5E75BEF0397537AULL, 0x38D3B47C30DA77AEULL, 
            0x0964C275BCBCC0E2ULL, 0x17EE2B96E7FD11D4ULL, 0xF08818BA0B727E61ULL, 0x6700B0A285ABF3BDULL, 
            0xC177705017FD15C8ULL, 0xE8E57242D2A04D09ULL, 0xB171A4C7B81AC4D6ULL, 0xAD637CFA59E69E53ULL, 
            0xCA493A4F5F19F960ULL, 0x4B5AFEA2DA11D516ULL, 0x22003F6740C6BA1BULL, 0x3D32711920FE5413ULL
        },
        {
            0xE514EB5EC4BC10ABULL, 0x91267783B626B578ULL, 0x41B128AA6C32906BULL, 0xB4C220DB85190D01ULL, 
            0x87E740FC94ABC930ULL, 0xB975152F66CEF204ULL, 0x7E22F2C69B71ED54ULL, 0x9F6BBCA65A281225ULL, 
            0xA89135EFB6C808F7ULL, 0x5D03CB7D0FDAA17FULL, 0x9CE93524C7AA51A8ULL, 0x2E6E7E646FF45DE9ULL, 
            0x1E6B70869485ADFFULL, 0xBDAD88D0DE88932CULL, 0x25A836E55EE1529AULL, 0x0B7E98E18079AD3CULL, 
            0x7AC293C9C00446D5ULL, 0x94DBD50A862A2A9FULL, 0x0D3C5507C9CD2784ULL, 0xCA6BE5D4ECAE63C2ULL, 
            0x4D7494A86885FECFULL, 0xABFEA1CFA131A4BEULL, 0xA3EAAC0B00614771ULL, 0x6572B6332F1016B0ULL, 
            0x76D089AF017A2BB4ULL, 0x55B01AA3E487F38CULL, 0x2EEAB175C16EB674ULL, 0x6201E9C6346CE42AULL, 
            0x6073A16F85985D90ULL, 0xC7F8234C5436A9F9ULL, 0xC414FB7DC8C532B0ULL, 0xAF4D5C47E110651DULL
        },
        {
            0x4071C17A4C9F76F2ULL, 0xE47FA008BA8CBFEAULL, 0x21770BF7BEEEC07EULL, 0xBF568F83C3C1F48AULL, 
            0xC0FAC1781FF84870ULL, 0x951A1C1C289809E8ULL, 0x39DC5EFECDC32C5AULL, 0xE511207C5D0EB94CULL, 
            0x1CC247C3EB352541ULL, 0xE41FBF6DF210A322ULL, 0xF931E58233DE5F91ULL, 0x24923C119CD0EE27ULL, 
            0x4172F442E228BD13ULL, 0x3C9081930B0D9A03ULL, 0x1A15BA647154B33CULL, 0xC64C5767383D0C4CULL, 
            0x2F6E5F5CB4F9CBB1ULL, 0x78C03281DE2CF288ULL, 0x28C1F87BB1E8EC42ULL, 0xB556DACDE89D15E3ULL, 
            0xA5D52AB712F7E162ULL, 0x6F667A75480A8AE5ULL, 0xF43CD05C88AD621EULL, 0x6D3B42BD538197E1ULL, 
            0x2E153F6223108F1FULL, 0x507C2DCBC94FB364ULL, 0xFE048BB3FF364EE9ULL, 0x45B1351D42FD0A65ULL, 
            0x74B2A644A1C26786ULL, 0x8C64B13CB4CE7CA6ULL, 0x4BAF2605748D8528ULL, 0xE573BA5E5804553CULL
        }
    },
    {
        {
            0x86EF8C29BCBD1438ULL, 0xD11DF6ED32189ABAULL, 0xF0A7B27FFFAC855BULL, 0x4B780F112B67BAA8ULL, 
            0x3E50BAC454C15D60ULL, 0x4D5D91452D2A6BA1ULL, 0xF669FC6F10289F9DULL, 0x8741F7B45E3097AFULL, 
            0x4B3F5B353FB19CC5ULL, 0xC0851123CE3ED59EULL, 0x362A8FB4A1F40387ULL, 0x3E5BA5579077250AULL, 
            0xF23408E580AE06B9ULL, 0xFF5F0B847BB69455ULL, 0x947F36E3B23A7783ULL, 0x234A170597BCD74BULL, 
            0x270FE0167F614CA7ULL, 0xBA0D979D0120A47BULL, 0xD9E5EE53E26D77F6ULL, 0xE27E4389BBCBE981ULL, 
            0x494508F3B47FE326ULL, 0x844C5E91E8DF3EE9ULL, 0xE927EAC72F2011B7ULL, 0xE5E1274EAF34E7A7ULL, 
            0x7BE033E57BBEFB11ULL, 0x7253A0E3A6BDDB8EULL, 0xB269FC3E5E1F33F7ULL, 0xE38FFC157983AC54ULL, 
            0x154374184754DAA1ULL, 0xF58B247A7094A3CAULL, 0x849B1592050CC96BULL, 0x5C266AA21889FEADULL
        },
        {
            0xA80D4A04F70B4F3AULL, 0xFCD1D10213B0215CULL, 0x8A3DE4E015D77A4CULL, 0xB191F23EF2C91137ULL, 
            0xF0DDAF03476D6B37ULL, 0x269A7AA87BEE1CCEULL, 0xDE815C98298C8955ULL, 0x73DEB72C52D07B9EULL, 
            0x01B2860AB4CBDB34ULL, 0x3882F739A1B2F018ULL, 0x4F976FFC5AC8E23EULL, 0x6E7A70BB4D78319CULL, 
            0x6DACED7F32817C4FULL, 0x52F06C0BD2903D51ULL, 0x8FA165E739638E87ULL, 0x4AEA68C308DEC322ULL, 
            0xCE0CDDDEBF7175E7ULL, 0x83640C0163B21BDAULL, 0x8740E875B4EC0D9DULL, 0x820451991CDD7C93ULL, 
            0xCA4C674DC84BE66BULL, 0xBB31F82E9AC45AFCULL, 0xBBAD6DEE3244BB68ULL, 0xF139E38003FD476BULL, 
            0xC484FC51708B685DULL, 0x46482FC27CF26124ULL, 0xE56068D1349899B9ULL, 0xAF60D380FA3BE696ULL, 
            0x565F207F818D0ED7ULL, 0x7DD7CCB7728D341DULL, 0x6FB753DDF1978A4DULL, 0x73B0F0047E1AA8C6ULL
        },
        {
            0xA998AFE9F7F4637AULL, 0xDEE66642107BED87ULL, 0x78320DB5B42E5791ULL, 0x533CE64689FDFAF2ULL, 
            0x90E9CBB81783B186ULL, 0x151B427ECAC4AAE8ULL, 0x766EE6F7DB485112ULL, 0xE6DA6BCA9E609CCEULL, 
            0x9ECDFC8863B45D66ULL, 0x379B2066C53A63ADULL, 0x25F0882537B0481AULL, 0x6DF0E9B5F8CFF285ULL, 
            0x6635124DDB136A18ULL, 0xC7590CECEC0493ADULL, 0xB35430C03F6B40A9ULL, 0xD976851AC5D86D58ULL, 
            0xB761268FF379F0E8ULL, 0x5F9A5DEED4B5DF5FULL, 0x842A73EBDC854B72ULL, 0xB406553A86C95C5CULL, 
            0x54FE2FEDFEF5EFFFULL, 0xEE020B3493BBD8AFULL, 0x95A1A7414B62FB03ULL, 0x128C5153CC85B718ULL, 
            0xC0EF268A8F41E6F9ULL, 0x6DA73B4A0091C061ULL, 0xF864CC00FBF955FBULL, 0x0E59968C0EC21FBAULL, 
            0x4AC08543FD2D4322ULL, 0xB74596AC5A445B00ULL, 0xC850A866F9216970ULL, 0xC6847E8DF70E4ACBULL
        },
        {
            0x03C6A08FFF24FA62ULL, 0xC38D874419F12AB0ULL, 0x6CD3A14F0C31AD7AULL, 0x76E4C130BF10FA11ULL, 
            0x43C7B1222B4EF09AULL, 0x2D916D0101565CE9ULL, 0xC4432C2841399B39ULL, 0x18DBE29141EBAC12ULL, 
            0x5D48D0CB7BF74304ULL, 0x28DE4D6BFF54C2FFULL, 0x8FBAC97D23E849CDULL, 0x04DEABF220E21E95ULL, 
            0xF9DA0ACDD5D0CFF2ULL, 0xD92ACAAA830343C7ULL, 0xECB7184711270CFAULL, 0x6803D1530D5A8827ULL, 
            0xAEBFC01864DC2A20ULL, 0x82068FCC7F4419D7ULL, 0x9588066B7F79F1BDULL, 0xFDCEC1E4D1A6CDBEULL, 
            0xE14267E16482E127ULL, 0x0AD8E19B9A4FC8F0ULL, 0xEF1E9BC7520C867FULL, 0x6F2A3A747B30A977ULL, 
            0x906D00B1CF935050ULL, 0xCBECDBB5D048DFB6ULL, 0xF609FE512397BC74ULL, 0x465D2145258E6798ULL, 
            0xE606907BDD478E6AULL, 0xCDC2EDA7C16B968DULL, 0x5BD42B114507C34BULL, 0x98FD5455A7BAEC46ULL
        },
        {
            0x2D5B64D6EA95EE5AULL, 0x18B8FDAA94A99E72ULL, 0x5C151922C35D0580ULL, 0x6F470E31C6B272F2ULL, 
            0xE31AAF225015D9B0ULL, 0x8809ED73533CD58DULL, 0x982D8D397FFAA0B6ULL, 0x01A0C4DE71964AB8ULL, 
            0xA18A7CD40971ED0DULL, 0xA6AA6A5BFC968DB3ULL, 0xA3B9A50B37F1EEECULL, 0x1A782C85852E1D7FULL, 
            0x4029EC83BD0A0B79ULL, 0xD6F715A45FD1D9D3ULL, 0x44D469D61C869DE8ULL, 0xA025F0C1E5806576ULL, 
            0xBC72CCDCFAD97BA6ULL, 0xAF45C620DD74627EULL, 0xC27633ECC1498C8BULL, 0x5DB70FC4085683A2ULL, 
            0x69E96340A6731B76ULL, 0x70C3C0FCBE41E487ULL, 0xF79731601B4F3560ULL, 0x4E5D6281F63F1635ULL, 
            0xC87097A1EA138324ULL, 0x7F43DC991D07BD3DULL, 0x383032C80232FD4BULL, 0xB2D3792673397B17ULL, 
            0x916EFD6917CCE1E1ULL, 0x74883C5F6833A63EULL, 0x38CEBF55260E1AC7ULL, 0xC98C01D44974C009ULL
        },
        {
            0x419D2429E5041570ULL, 0x056127F97021FCFBULL, 0x55F312CC81BE6A5AULL, 0xFE4EFFBCC8E37B9BULL, 
            0xE1B117AE86F44FA0ULL, 0x0B814BCB45B3BB7DULL, 0xB39F79DE8F3E421BULL, 0xCE21C50EF20649CAULL, 
            0x3F9B047B13F9951CULL, 0x39905B25F2568AB7ULL, 0x56E0512BD76664A7ULL, 0x09790713D73E7FCEULL, 
            0x9643E9B96020F46DULL, 0xA7D6F3480D0E5158ULL, 0x3B23EB6AD214B85FULL, 0x76B346A94FDC25E7ULL, 
            0x49EE700A0AB8100DULL, 0xD899FC58ACC09D35ULL, 0x408B1EF573984279ULL, 0x5F7DED782FF359B5ULL, 
            0x47F34B363F66A56FULL, 0xB3B48D00E1387E84ULL, 0xD37651FDCB1FC7F0ULL, 0xB7853C1A96D3C3C5ULL, 
            0x736A1A7AFDEC3DA1ULL, 0xE98A1CFE4CD9B85CULL, 0x7B400D29A45A3CE8ULL, 0x655C2FD439CFFEDBULL, 
            0x4EA7A6D039EC749BULL, 0x33653DF4AE15F041ULL, 0x388B7B3EC41635C1ULL, 0x3DD3105634ABEB15ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseFConstants = {
    0xD01C40D2965F1129ULL,
    0xD129EE28F217C799ULL,
    0x83846C299690D94AULL,
    0xD01C40D2965F1129ULL,
    0xD129EE28F217C799ULL,
    0x83846C299690D94AULL,
    0x16158CD4BE3351C6ULL,
    0x40095B6F7BD312FCULL,
    0x49,
    0x01,
    0xA3,
    0x09,
    0xDB,
    0xA3,
    0x22,
    0x34
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseGSalts = {
    {
        {
            0xCA5CEE1917EAF897ULL, 0x1BF429C6BE86C02BULL, 0x82218902CB13A9C6ULL, 0x55439DEF834105FBULL, 
            0xFF689C17F01EA701ULL, 0x0939D0FB7144F99AULL, 0x33793A11EDFC0108ULL, 0x85EBD42B4A17E0BFULL, 
            0xFF5AAC38BF720F36ULL, 0xDD77E7CF09AA88F8ULL, 0xB2BFBB15E4913995ULL, 0x8038152724E6517AULL, 
            0x67521BC58B060B74ULL, 0xF447D180E471ABF1ULL, 0xE20A2F6EC08BA690ULL, 0xC0F4BEE771981E66ULL, 
            0x09F457F8F1F47A75ULL, 0xA96F4E76DBA10EBFULL, 0xBA0C6D80605EAC47ULL, 0x9A96A88AF98B80B4ULL, 
            0x1CA893AE9BCF3F34ULL, 0x6B06E1B68012BC23ULL, 0xD56600AE652A067EULL, 0x5B070947F4A45732ULL, 
            0xAFAF4CA60A69128AULL, 0x4964432F613D5B7AULL, 0x745B9E3759FBB852ULL, 0x1FDF5EBDB6039371ULL, 
            0x7366163CEA9D221FULL, 0xE9D371C1CD19BFAAULL, 0xEE52F6F2D01E635DULL, 0x22C1EE12492C9426ULL
        },
        {
            0x6DEE65FB624C80F9ULL, 0x657B8F45EBD71425ULL, 0xF0D540C75F7C4CAAULL, 0xBDBFFA8F1E0DA9CAULL, 
            0x6988EBE816551102ULL, 0x5B5911DAF947056DULL, 0x163414AD01107483ULL, 0xA594E14B2676A4EAULL, 
            0x1D5BCAB1D2669421ULL, 0xDFA8B1111060AD90ULL, 0x31EB1E2E1DCCEA5DULL, 0xAF04F5006BE63474ULL, 
            0xA182840EB0779D43ULL, 0xC9DC15795DB07B76ULL, 0x1AEF02892A99F86DULL, 0x081187A1EF8B2B14ULL, 
            0x440332E7C7D2B914ULL, 0x96EDC4EF59CFC1C4ULL, 0x6F6F2B08BC8FFDF3ULL, 0x0DF90032C154D40DULL, 
            0x75C51D053B7AA3FAULL, 0xDEC902BED6E69DA0ULL, 0x0B1BBE31E7937D53ULL, 0x15CA9F59084E67CFULL, 
            0xC0412D067A285D8AULL, 0x8F78E3315E41ACFBULL, 0xAD6D32CB0B3D5922ULL, 0x2B445E6556222687ULL, 
            0xF11864CFAE83538DULL, 0x15DC6781BB445491ULL, 0xCC045563E6AB03DBULL, 0x4B285F9C1FBE2E18ULL
        },
        {
            0x7E2EB4E02754C64FULL, 0x58EBE9C90EDEF22CULL, 0x9ED41AE6D3C00215ULL, 0x607DE9C62ED9DB82ULL, 
            0xD0507C94C3EDC0BEULL, 0x235A12031CEE0F96ULL, 0xAAC3943E4A7AE6E8ULL, 0x73722D2D5282A1FFULL, 
            0x864DD70205A02541ULL, 0x28A3C97014481767ULL, 0xC4AB49162AAD65B0ULL, 0x1958C180D17C0562ULL, 
            0x8886C549CBBF3461ULL, 0x16D42DAF71E3B24CULL, 0x523C9530D809FCF9ULL, 0x19BA06062202E4E2ULL, 
            0x02F1E65649F98918ULL, 0xEBCD7CF72A88C32EULL, 0x5233E9B4707F2EF9ULL, 0xE1DFC72EF82BA02AULL, 
            0xEFEDA69671FFD47CULL, 0xEB5C82D92FEC415EULL, 0x4D0AC3130E998A61ULL, 0xB7852EC3C3ABAFCFULL, 
            0x0269D0AB7A2A8121ULL, 0x8BE4734839411FCBULL, 0x8E226166D8768FD4ULL, 0xB69D943ADD477615ULL, 
            0x01EEFC5246425F84ULL, 0x1C7E398BA5F7C765ULL, 0x91F10037DADA0F73ULL, 0xD5FBBF58A40DC367ULL
        },
        {
            0xF4C4DD600C765E13ULL, 0x832D8D90AF95EA5CULL, 0x3391BF2D699D41F3ULL, 0xC88588750DF46012ULL, 
            0xFE979E4AE7EE9A5EULL, 0xD12E59FB40A4F492ULL, 0x8D1473D133F91470ULL, 0x8A3B903FAD7F494DULL, 
            0x8954CAA91CAF26CBULL, 0x702D8523554F8984ULL, 0xA35ACC86EBF43218ULL, 0xC2C672BBAF806D1CULL, 
            0x4663CCC5A4A7F4BAULL, 0x2A5F8A900E63AC96ULL, 0x503F39B9BB0023D7ULL, 0x318FBC581053E256ULL, 
            0xB9C98A42AB8CA89BULL, 0x75DB73D84C8199DCULL, 0xB32B8DD22945EC90ULL, 0xD2CB4AE74E143C44ULL, 
            0x323CC65E2078E6DAULL, 0x442AD0AACC218804ULL, 0x8C215FFECD87D8DDULL, 0xE5BED4284E17DAD6ULL, 
            0x93E81B35BE790A2EULL, 0xE158032AA8B12E88ULL, 0x681CB16F9A1B2C89ULL, 0xF33480D04B61F959ULL, 
            0x3826EE3D70C75A18ULL, 0x6E9EA57BD97B8F10ULL, 0xEAC6A9F391D1EC4CULL, 0xC2206D1FF4A937EBULL
        },
        {
            0x3515187B4E015C1CULL, 0x97FD69D90F9162B8ULL, 0xDD5C8D78FBF12506ULL, 0x6F7E488DF4DB0B21ULL, 
            0x6DC8927405587AC1ULL, 0xD276D77830DE5DDCULL, 0xF20A934E15A85F6AULL, 0x0C4715F6DD398818ULL, 
            0x17321BC6DC992AEEULL, 0x45D9523A64C36393ULL, 0x015EB9A4EBEDE7CBULL, 0x7E8F63D6D545F0D3ULL, 
            0x696905BD477537FBULL, 0xF31C357552B11CA2ULL, 0xA5BB42FD6C29E179ULL, 0x803CE22C8F1288B7ULL, 
            0x4B17DD62691B9129ULL, 0x7E85012EDFBC7D20ULL, 0xE06A1A0507E9E486ULL, 0x42224A4531824032ULL, 
            0x5289D9DD97F6F509ULL, 0x45348F87F7679C80ULL, 0x05CA0BDD9C44F325ULL, 0xC7A93987EE892F83ULL, 
            0xD206EF59E0AE7E44ULL, 0x111CF802C3319699ULL, 0x5E7D1ED19B19AF5DULL, 0x2FD8B0387B1C58F0ULL, 
            0xF362F88619946DFBULL, 0x44440C31D5691A4CULL, 0xB6B28B831B0BB70AULL, 0x0484C5EDCD6911F4ULL
        },
        {
            0x1AEE22CD3771B61EULL, 0x686EF1B846827101ULL, 0x5F515F0F081B8380ULL, 0xCC6FD2D2551C8EF1ULL, 
            0x5E23597CC3A2F81BULL, 0xBB34B6FD6C349D77ULL, 0x2FCC601C27974711ULL, 0x49202AD869A13FE6ULL, 
            0x3E5380895462BD71ULL, 0x1E0CC2B3CD2D925FULL, 0x6A8DF68E3A8BB456ULL, 0x30E14D20DB236B63ULL, 
            0xAB6217D889EAA464ULL, 0x783C28EAD821C7D6ULL, 0xF2B6A85859E28DE6ULL, 0x8980F53FF7BC03C9ULL, 
            0xDF7C38FFC33E30E3ULL, 0xC7DB706493BDAE59ULL, 0xB0B22155143EDD69ULL, 0x5E7F95E3B0B8261CULL, 
            0x7CAA415311792FE4ULL, 0xEBF3DE85E2444C20ULL, 0x89994167A9A0463AULL, 0xB9710D430EE3C100ULL, 
            0x10FAE4B956ECC6C9ULL, 0x1EB1A76B3198977EULL, 0x9506409F7C5CC2C6ULL, 0x053288996F3AC795ULL, 
            0xBBAF813EE623709CULL, 0x24C6F5577CC41BD2ULL, 0x9EDC4D4E6D9B1E3EULL, 0x072E9751F90911BCULL
        }
    },
    {
        {
            0xB8D96494FA8328E3ULL, 0x137A192E8B33B934ULL, 0xB674F6231FCA8E08ULL, 0x42EDBCDCC2C7F50EULL, 
            0x8CD28B27F5005E3CULL, 0xAFE11B9F10CD5F10ULL, 0xC429551D11DCEC58ULL, 0xD3A323F9BF65E76FULL, 
            0x4A1D39CC6FA2FA6BULL, 0xD7D45EF1DFC76BD9ULL, 0xEE6FFBF07B892765ULL, 0xAEB7DB26285DBCAAULL, 
            0xC62A277AF2BCC4B3ULL, 0x9E32D4AECF6EDEC1ULL, 0xD4568443F791326BULL, 0x8E4464C8EC85476FULL, 
            0xA8607C8115280D52ULL, 0x80A7382FE1A21BD4ULL, 0x85AE5184736B00E8ULL, 0x65C58A1D1BE404D8ULL, 
            0x1AAAEA9FB3259454ULL, 0x85A46B97FB30CBCFULL, 0x0EBDFDBA1C6B9EC9ULL, 0x63DB9F093E581F43ULL, 
            0x823B4A79A054FDEDULL, 0x3B590A8095DD3A24ULL, 0xF130387FB39EEBACULL, 0x549EF8E6D53C2C64ULL, 
            0x5B550C929C3657D7ULL, 0xB2F4B94FBE5A057CULL, 0xFDE8F6FE2709D646ULL, 0xC1129F2CC86C0199ULL
        },
        {
            0x15E30E1BCDF6B487ULL, 0x7E2C56B1F77812AFULL, 0x252AB04ABAA9FA16ULL, 0xE7104D6B41D5C369ULL, 
            0xB36A36F80B58FD72ULL, 0x0F377C36DD2C78D0ULL, 0xE505848EBCF1227FULL, 0x57CA01DE7F69DF29ULL, 
            0x0EAC1E652F72E148ULL, 0x02A89D88B264767EULL, 0x5753BB3B04CDC4F2ULL, 0x4207CF7F40AC0801ULL, 
            0xC79297796928069AULL, 0xE8DEDA3DA5DD8399ULL, 0x0C5B87EBDA997D8AULL, 0x4EF36A1407926836ULL, 
            0xE50DB1976E5F3C01ULL, 0x7610833E5DAE8B13ULL, 0x8622CC6BA2FDFDD8ULL, 0x658359108AF1608FULL, 
            0x5682F950076A6043ULL, 0x2AA9C3E13B85CD46ULL, 0xBB5DAB8EEC0AF243ULL, 0x7C958948A6946534ULL, 
            0x5F4C71E0E95838DEULL, 0x129AF4145043F253ULL, 0x1EA07CC6AB42CEC5ULL, 0x0FCCB7781B55E161ULL, 
            0xCA280269086434AAULL, 0x85C18F70C600F72DULL, 0x32393F492E82C7CDULL, 0x832AB3FF12C45B21ULL
        },
        {
            0xE98F1FF1E2F3127AULL, 0xCA19A7E899D98D7EULL, 0x906C20CACFE90592ULL, 0x8B394F856EAAF154ULL, 
            0xB5696CA52B635A8BULL, 0x6827B8D8603AA979ULL, 0x9F130BC07F408747ULL, 0x10EDBCC37D5254C4ULL, 
            0x072750D5482EF1E9ULL, 0x5F19D4D71C2B3DF5ULL, 0x80E48ADE295E160CULL, 0x4E1FBD044A58BEB4ULL, 
            0x1B1EF4C78C269EF4ULL, 0x0349884401EF56D5ULL, 0x616A30032A9014CCULL, 0x0D716621CD8CD68BULL, 
            0x0EFE7071C3F0C316ULL, 0xE0DACE12421DB70EULL, 0x6E90C149E616320AULL, 0xAC93FB2CC79A9C82ULL, 
            0xDE0274F515D1A6E1ULL, 0xF712739ED9BD85A7ULL, 0xACE5B60F21A5C366ULL, 0x971983E03B5B443FULL, 
            0xC2F37DF16EECB89CULL, 0x5B5C32CC285A3029ULL, 0xA38C454147E92433ULL, 0x82037A5B5052E18BULL, 
            0x09F6B3A8C262FCD3ULL, 0x78EF594277CFCECAULL, 0x3F47187FAE1C8FF5ULL, 0x16674018DF43D6CCULL
        },
        {
            0x3B5A34E43B2D6B5AULL, 0x1D95F7D5B4D7BE26ULL, 0x562C31A5B925DF0FULL, 0x5478E58AF1938E14ULL, 
            0x969FAFB15106A392ULL, 0x0C2629827D02F53DULL, 0x333255C893CD8D91ULL, 0xD4F9C2D8AB950391ULL, 
            0x6842545ABB5E99E2ULL, 0x4F900180D5BFD0A7ULL, 0x330A606453BF99EAULL, 0xEAC9BD008754A238ULL, 
            0x1FFCBE231964B24EULL, 0x0213CA36E92FB0E4ULL, 0x2DB3D6A58489D9D4ULL, 0xF10A3C39AABF3A4EULL, 
            0x054F0486F3ADD965ULL, 0x41D215FEA5108C76ULL, 0x9719831595FBC44CULL, 0x9107C586CD19A73CULL, 
            0x55BCAF504F7C0EF1ULL, 0xC032452C058272FDULL, 0x6B80C6486EB59D46ULL, 0xBC860CF01D66AE89ULL, 
            0x599E7D2EB967BDC8ULL, 0xE5686E929B2A37E7ULL, 0xFF9C99FBA3CD7B84ULL, 0x79F8DC62BC81BC41ULL, 
            0xAD3A720618776C79ULL, 0xBBEAF84928918029ULL, 0xD6636564F888CE13ULL, 0x999D8E4A6E8BAFA9ULL
        },
        {
            0xE6D55EA037C136ADULL, 0xA6E0E07C36D93C37ULL, 0x3044C38A38A2D649ULL, 0x7F07C6AE4A586ACFULL, 
            0x3CB4BCB42C89E153ULL, 0x484E5098B1A5116AULL, 0x14661622BF9F45C4ULL, 0xD8868F7126D47D66ULL, 
            0xF071F92328D3EA02ULL, 0xFE4DC5204E10CCE5ULL, 0x501E6DAE2DDE14B4ULL, 0x522973EFB3DC824BULL, 
            0xBC0402C8EEDF4DC4ULL, 0x044C53F7D3D43CBEULL, 0xA6864F8BE3E92122ULL, 0xF6ADAF5C1DCA1A8FULL, 
            0xDBAD6C71B36155C1ULL, 0x5C87B5333F3DC239ULL, 0x11749914D1E89928ULL, 0xF176EB2A3D84A75EULL, 
            0xD9516309C39E7CC7ULL, 0x62BFC14E9F086E83ULL, 0x317D45A5747AAE21ULL, 0x03874D24394BCF39ULL, 
            0x185E3932D5F6448DULL, 0xBF08B95F4E89F379ULL, 0x53FEA218E4D5D3E4ULL, 0xA783A4C1F7C88430ULL, 
            0x52496F8528B07850ULL, 0x45F0928C48C16FC2ULL, 0x7281B8C96C907B22ULL, 0x6E243EA8ABF53A46ULL
        },
        {
            0xDA4C328B7C909846ULL, 0xC6D0A56E1666092CULL, 0x536F202779456025ULL, 0xA2291E45FABB9BF3ULL, 
            0xDBC40F3CA670DF15ULL, 0xF3DF7F73929A84B3ULL, 0xD3A1BB5876B246F8ULL, 0x42785D600362BEC9ULL, 
            0x5C72A71FC42719F7ULL, 0x3F5529C6D059A921ULL, 0x274DD53CFD2F283EULL, 0xEC985E43A181E0D5ULL, 
            0xB4191B8E4B91CAEEULL, 0x89530566309E501FULL, 0x1D6EA6FDFE42FC4DULL, 0xD587E0812BCF2380ULL, 
            0xC88C490D7CC529ABULL, 0x264AE8DE06BB3305ULL, 0x59E8A77E678F1313ULL, 0x304F208A7639956EULL, 
            0xB51F055B134DA074ULL, 0x515E5AA714CD1D4EULL, 0x3FD53DE81A91E71FULL, 0x5ABDA88AFCEEE442ULL, 
            0x8824E8B922920D47ULL, 0xE8380E5EC4D53289ULL, 0xB685F9FC7E392112ULL, 0xB674E4707A9E99CAULL, 
            0x1E09568923FAE018ULL, 0x4AA1E1A6B4DE50B8ULL, 0xAC11CB2E8DDDFEDFULL, 0xEF4FB4AC4E8CD4EAULL
        }
    },
    {
        {
            0x9D70F4843C521479ULL, 0x7C1E1192330FF12FULL, 0x784E585F978F3287ULL, 0x7F9BD17F64840A23ULL, 
            0xB6AD1CB40A68D153ULL, 0xCF32A2184F611088ULL, 0x1C61FF101147C72DULL, 0x9CC77D19C89D400FULL, 
            0x8540B37C76228EE4ULL, 0xCA54D3C049F64108ULL, 0x7F153BE730F0C5A7ULL, 0xECBA73ACF38FE363ULL, 
            0x75959F2CBF439733ULL, 0x7FE38D2860F608DEULL, 0xF5B11BD778E67F64ULL, 0xBB784B20A07434C2ULL, 
            0x8D95F0562D7894CDULL, 0xF8DA9B184CF7CD07ULL, 0x55DE63A594FF6013ULL, 0x1153BCCF67340E4FULL, 
            0xE42D2C5C04B88F39ULL, 0xC3FC4DDF53F53D4CULL, 0xF8B4522308C53E85ULL, 0x0A1E4CC4F6F1E56CULL, 
            0x5AD168FBEB5C14B7ULL, 0x2E04BEE34EE4B5A0ULL, 0x37B76031104EA84CULL, 0x787A40B5D8B584DDULL, 
            0x31987A2B2E5822A2ULL, 0x582D837157EA6869ULL, 0xCEB3A802E29DEBADULL, 0xADDCEF71FEE1780FULL
        },
        {
            0xED59E3D76B758FD4ULL, 0xEA204856B69968F1ULL, 0xF9B7FA507173FC31ULL, 0xC34EB550339B6476ULL, 
            0xE82F4532AE821A29ULL, 0x6E4C6A8387B9204AULL, 0xFF912401AE9200ACULL, 0x618693211FD57D1FULL, 
            0x402182F3CC6A7F1AULL, 0x0B8A46AA17AF328AULL, 0x9E34DF2019A49335ULL, 0xD5C8EB57F9588A2FULL, 
            0xC3581912C7430704ULL, 0x76D7F4302B7E1CE8ULL, 0x1B625A8F5B4AA022ULL, 0x756E6F7129B373C6ULL, 
            0x9C74BF9363E56452ULL, 0xEFA7EFD06639A797ULL, 0x46B8E220C9527639ULL, 0xD1872751A6A048BBULL, 
            0x7EEFD2E3237AE3D6ULL, 0x09E28A0B286D1918ULL, 0x340A36733C2C6E98ULL, 0xAED33E82B3D36339ULL, 
            0xF128FB90E195FE2CULL, 0x0A9EE08A1D763445ULL, 0xBD9D01AFF9BE3C6DULL, 0xB6C0DDAEB28D0867ULL, 
            0xFFDB5BF9BB345521ULL, 0x0699120A0051FAE9ULL, 0x99C47D2319D2DB99ULL, 0x360979E01F4C8A2AULL
        },
        {
            0x29B2171AA44F37F3ULL, 0x8F4B2AD3423972ADULL, 0x59B02E2BB6B7A3CBULL, 0x54DEEF242C0FBEE6ULL, 
            0x1B7D37190757D777ULL, 0xC41872B301C4091FULL, 0x67AC7C02507AA5F7ULL, 0xA68B50A2AD3F0629ULL, 
            0xE552CE78BBE6D7F4ULL, 0xEAC2B5E97EFDA8A2ULL, 0x194865BB257D8628ULL, 0xF20CD7746E407730ULL, 
            0xC997793609C48B37ULL, 0xEC08C413B24DC785ULL, 0xB5C34439CA65FECDULL, 0x8CC15BF799A60B23ULL, 
            0x48E36B0BEFE69B56ULL, 0xAEF78D1D44190586ULL, 0xC4A3DC4253CF2A4FULL, 0xEDB0DAC856212620ULL, 
            0x28208B0B7C8F3E8DULL, 0x7F47FBB10938745DULL, 0xAA7B7D82B6CB0B66ULL, 0xAEA3B176D0941BA4ULL, 
            0x005DC8A00CC8CDCCULL, 0x784F7B1586A07F48ULL, 0x4ECDDC8A3CEBB294ULL, 0xF8DE497C90C079A3ULL, 
            0xE0E9645E68404BF7ULL, 0xFCD365054B630BD9ULL, 0xB104D23C92B3BD02ULL, 0xBEE8B068411F2161ULL
        },
        {
            0x18D60FBE7C0D0941ULL, 0xC2DED0ED9DD42496ULL, 0x0ED9E62C01D2DA40ULL, 0x4718268DDD91E326ULL, 
            0x2A262E13742E57F4ULL, 0x4228759C4872B115ULL, 0x68D8CDB0C82509E9ULL, 0x5EDD883F7C2D8BD3ULL, 
            0x0B7E7D3F72013048ULL, 0x9AEA4D8B25A2398DULL, 0x1D42179C33353AF7ULL, 0x2E5256DC13910A32ULL, 
            0xD5F54DD4D463B55DULL, 0x0E848C79D78CD571ULL, 0xD6DFEC83E9888BB6ULL, 0x0AB528A1CA706488ULL, 
            0xB010B71433621077ULL, 0x6B9A7C1485E079B7ULL, 0xC8326C6781BAE879ULL, 0x306EDF7D1A64A289ULL, 
            0x8F4BF3BDDC7EE6D4ULL, 0xDC0A8947E884A5CCULL, 0xEBAF04492BBB113DULL, 0x58A8BBD27F29578DULL, 
            0x03C7D283C435AAB2ULL, 0x86CA61C2C919D6F2ULL, 0x8C4DF1F892FA90C4ULL, 0x6296AF912CE10573ULL, 
            0x8F30A6EA6B0D11D2ULL, 0xF254B38F8E6E4C4EULL, 0xAECF42BFBA9E17A0ULL, 0xFC089F03705C2D9BULL
        },
        {
            0x4947F6495CE8F213ULL, 0x2888B9F250D95959ULL, 0x450C49DCE904A02BULL, 0x18DD7633340E7A4AULL, 
            0x3EA84EA2E554778DULL, 0xDDFADBD02379A9DBULL, 0xCDE2FE0CBCCA5385ULL, 0x81F5DB061309D239ULL, 
            0x7CB783C992F49618ULL, 0x02B5F4D109882776ULL, 0xD6EC5EB46AB20CBCULL, 0xFF0902037B2C352BULL, 
            0xCE200D64B38DCF3EULL, 0x134B58173D3F9C26ULL, 0x8943742AB875A03FULL, 0x8770BF9499AE11EEULL, 
            0x6399C0B852E0124EULL, 0x20E3FB3FBEA2DAB6ULL, 0x55F43680AA40E2B9ULL, 0xAA22CF4A948AD941ULL, 
            0x418512BE7CAB2A16ULL, 0xFB1F83E040E6A997ULL, 0xACE37A039600E22FULL, 0xAC1C99CB99B200E5ULL, 
            0x74938B04BC08ADECULL, 0x2F290B5B341D17D8ULL, 0x4A98DE3CA3A1DCA6ULL, 0xF23CDB6DCA10ADE2ULL, 
            0x03733F661D7DD318ULL, 0x95B26095B17AB736ULL, 0x58400B41D244C2ABULL, 0xC066D785A2F1D888ULL
        },
        {
            0xAA79011D8AF66D66ULL, 0x0DC0416A8D2C5411ULL, 0xE7737082A9CBEF23ULL, 0xCC15DDD754057DE4ULL, 
            0xCEAE85CD6098700EULL, 0xFE476F42002C0EEEULL, 0x70F473B555B9F2A5ULL, 0x180B987C2FA26B51ULL, 
            0x740F5005F3AEA0CFULL, 0x7154C3800BE79EF1ULL, 0x3BF00A85A823AFECULL, 0x9B2CB84F1A0FBB1CULL, 
            0xE4A1A3E856907295ULL, 0x4F2B1E5664E57522ULL, 0x68956E36E055C810ULL, 0x66D1A5FE81765F19ULL, 
            0x3200963AEFC599B6ULL, 0xC7A4B3878CF45C80ULL, 0x57B91F55C20EE67AULL, 0x1EFCE1CB8457CED1ULL, 
            0xA0ECD69ABA1A0B4FULL, 0xA0004EA9EED9FF84ULL, 0x372C332A0CC4F87DULL, 0x6267A1A329621AF4ULL, 
            0x8DBB173B48230987ULL, 0x347744D24C67238FULL, 0x435383EBD20B3A20ULL, 0xFDC3050BB5346812ULL, 
            0x80F5115BA70A2780ULL, 0x059EECBD0F0CBAD7ULL, 0xDBCE20DDCC04301DULL, 0x17962A8C4BAF0790ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseGConstants = {
    0x3184DA2A8E8B48F3ULL,
    0x42E075C65120F947ULL,
    0x1E81BEFFA89DA184ULL,
    0x3184DA2A8E8B48F3ULL,
    0x42E075C65120F947ULL,
    0x1E81BEFFA89DA184ULL,
    0x2DD30E86E2D8BB12ULL,
    0x900D403D6CB2ED2EULL,
    0x04,
    0xED,
    0xD1,
    0xD9,
    0x9B,
    0x6B,
    0x15,
    0xD5
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseHSalts = {
    {
        {
            0x195A477BB11B18CDULL, 0x73A5CF780C7D1297ULL, 0x49E53638D1D2959AULL, 0x62C08437CCA6A06AULL, 
            0xE22A9A38C30CB375ULL, 0xC306857EB7F65357ULL, 0x9DAA952040E27C4BULL, 0xC0D181649A372EA3ULL, 
            0xAAAE3CE977FF171EULL, 0x0E0E18D6B60A39B5ULL, 0x484E1AD895FF3FA0ULL, 0xB4CFF40686B0CE8FULL, 
            0x29257DF180047BD6ULL, 0x73862B09A7B55CF5ULL, 0x57008EDF06B9C98AULL, 0x0F7933277093DA23ULL, 
            0xED0A8D5FD609E897ULL, 0x77B441D3D6BB0D3FULL, 0x5439E9122D567E81ULL, 0xE1995F096ADB671AULL, 
            0x429FF2A6A2D66B1BULL, 0x304AAAA316B3314BULL, 0x79E90861334AAD17ULL, 0x4676CA2BD124E3F5ULL, 
            0x5FF2312633ECE5D1ULL, 0x9C008D7A9825C07BULL, 0xCF7254A237EA1B23ULL, 0x9A75A931B2953324ULL, 
            0xF8323DB095DB56E2ULL, 0xC4CA958B50F629ACULL, 0xE84F43E9853CB190ULL, 0x00A0E5F375E618AFULL
        },
        {
            0xAB620AEF72E4A850ULL, 0x7D9F090479A6B5A3ULL, 0x0740140008F06478ULL, 0xFE6AE98FAF799F19ULL, 
            0x3DA55768CCDA105FULL, 0x8E98DDAB4C9C3FC4ULL, 0x7B79373DCD79983CULL, 0xBE1E916585B51F60ULL, 
            0xC3EA4F01FBC5FB51ULL, 0x37260C9464E09A5AULL, 0x94980931AE7696A5ULL, 0x58D7A1340E0AC580ULL, 
            0x10BBB576ACC142D0ULL, 0x158655CB38F9040CULL, 0x07401C9E4E3C9FCEULL, 0xE9B9D3F5A3B5A201ULL, 
            0x00DEBB64D580BE0FULL, 0x0D9715720F6F25F4ULL, 0x8B9F686677294763ULL, 0x16BCD8DEF0793F3DULL, 
            0xF08D656391CEE50AULL, 0x5B9CDC635FAA4E45ULL, 0xF931474D90B05C21ULL, 0x617D847BF95F2057ULL, 
            0x69B9152B71F44D5BULL, 0x36FF6272442C42F2ULL, 0x399AF0F66D35E82CULL, 0x2CA3F5BBF8382C0CULL, 
            0xFBBCBD4BBDE6A246ULL, 0xE143ACAFE173CE53ULL, 0xB223E3A33D403A8AULL, 0xC1E274EFFF346239ULL
        },
        {
            0xD0F4739ED5B7BFDDULL, 0xF1D139E9A68E567DULL, 0x6995F9D4D075BFACULL, 0x7C7B37139EE4F7B4ULL, 
            0x6E3BE8A3B71DC518ULL, 0xD183CC6A28D8A546ULL, 0x8BF88920B28300B9ULL, 0x61A47205492168E8ULL, 
            0x9A6B2C91A654F891ULL, 0x7BEC16D9F93496D9ULL, 0x103B29190517CF5FULL, 0x5BFEF9FD79EF1AEDULL, 
            0x7865E869ACF74165ULL, 0x1D5958F49D9EA65DULL, 0xF6A31775674463A9ULL, 0x20431AC6EABD1081ULL, 
            0x45EF285C08E56357ULL, 0x534FF7DB0E0776DDULL, 0xA854F26897FA7A52ULL, 0x720EBC9BE4FEB46CULL, 
            0x5E635AD52589D83CULL, 0x01D1B9899B6B995FULL, 0x72EBBC739B9F8701ULL, 0x54192FAB60A59FC8ULL, 
            0x0C9A18A11757893AULL, 0x7B7CBADC1D756496ULL, 0x1F43CF67F3F6A731ULL, 0x1E774C521A6CE919ULL, 
            0x43CA3D85469E6352ULL, 0x8DF6636480519A15ULL, 0x1F2BB2F5125B6390ULL, 0xBD8DF7E4B7BB9210ULL
        },
        {
            0x41CD661A5F4AF309ULL, 0xBFE0A0216E1C8EA4ULL, 0x78B6E8ADBA40205AULL, 0xD737464A3213A401ULL, 
            0xBFA9A8E6C82680C4ULL, 0x3C81798C635D84A7ULL, 0x146E7EB40CEB0FEAULL, 0x328C953E860D8FD3ULL, 
            0xDCDA4A994060064BULL, 0x341078D6AD09B9CCULL, 0x16265C6C4244C70AULL, 0xE6395D7026953AC8ULL, 
            0x96ECB8BBBE76250AULL, 0x2CA1211BCB168635ULL, 0x85E7BEF7BD68D0E0ULL, 0x489E85BCA00C2E3DULL, 
            0xF695E7C22FCEF91DULL, 0x2EDF683D3C6FA343ULL, 0xEF0A110CFC5F712DULL, 0x6843946F2E2CD697ULL, 
            0x0989986356D03F14ULL, 0x53886BC4C67A6FB2ULL, 0x2EA495759B721FBEULL, 0x121E7288D8910141ULL, 
            0x8FB266A8E47E08ABULL, 0x1D978CAFB90A3C8CULL, 0x56ACA68DD1D0E1CFULL, 0x0396503BB62D5BDAULL, 
            0x1D1EC69D98C3D0F6ULL, 0x17E5546D490F05B1ULL, 0x3421E75F75946DDAULL, 0xDDA69D253B64F958ULL
        },
        {
            0x2880E1E1E9E66092ULL, 0xEAFE0C1B597A8CD7ULL, 0x74238BBC297356A8ULL, 0x97BB17BB16649CC7ULL, 
            0x38C7EBBFA9E0E946ULL, 0x181638E86A14FDB6ULL, 0x0796D872A8F07826ULL, 0xD38E9EA607373120ULL, 
            0x4F73185AE2B434F2ULL, 0xAA5B3FC14BA61F1AULL, 0x44FAD4CE8F69C140ULL, 0x47C83C994273033AULL, 
            0x43B192EB3757D379ULL, 0x0F1BB588712FB980ULL, 0xC858EC1999587752ULL, 0x7A8B873DFE869977ULL, 
            0xC7174B7BED6122A4ULL, 0xCD3C5FBB3C6C6733ULL, 0x57640FEFC37F753AULL, 0x5A2F8124BCAF0E5DULL, 
            0x810C4AC23EFD77D3ULL, 0x4BE51FBC0B2E9579ULL, 0x7FC8363B8EDE1F66ULL, 0xD6F9307F4F232DDAULL, 
            0x9FFE362D7556C55BULL, 0x58F66B66125A112AULL, 0x3BA673E038BB8530ULL, 0x371D811E8B946A95ULL, 
            0xE459B2E9DF45C680ULL, 0x8FC38B8C51D3CD01ULL, 0x089D0B93ECBFDAAEULL, 0x90D2680FD6264E48ULL
        },
        {
            0x1B95F37E6A31621FULL, 0xCB419290D3D5D4AEULL, 0x4442DFAA2FC76B2FULL, 0xEB767D372FBC4364ULL, 
            0xD8BD53AB55AEE2C4ULL, 0xA883E7948A6DC042ULL, 0xCA735E48962A17EBULL, 0x36376CE2F037B4ADULL, 
            0x1B9C3679E9DAD884ULL, 0x5FE62DD959683BC7ULL, 0x11D903B6D1D6A334ULL, 0x0ED25C324D660CDDULL, 
            0xF06E343593349E6BULL, 0x1FDF66C3593954B6ULL, 0x5A5DE7915630AF90ULL, 0x83558CC03F7C0897ULL, 
            0xF3E27F3801F661CDULL, 0x1255CE48B359FF82ULL, 0x5D53FE91C5A123F6ULL, 0xCD7BA4B692279E8FULL, 
            0x26A9C1D6F186DBFBULL, 0x8B83AC4672D38370ULL, 0x32925F5ACEA42EBEULL, 0xFDF53C5CB3C0C712ULL, 
            0x85515A94439B9A20ULL, 0x018880CBCB58830CULL, 0x6EADC706105CF685ULL, 0x3C4D84BE2452C17AULL, 
            0xB4FDF5C993FCE560ULL, 0x2578FD4121F1507BULL, 0x81FF975F181F6571ULL, 0x60DAB428187F83DDULL
        }
    },
    {
        {
            0xBF198B9CDE77E129ULL, 0x589814C046332726ULL, 0xE15084343606BC5DULL, 0x234BA779EEE1DFFCULL, 
            0x109DB8F86EF53A33ULL, 0xCDB319254B80D13CULL, 0xA8FA987EBAF7CEA2ULL, 0x7688A3BB90F78153ULL, 
            0xC2975EF78C22DCB4ULL, 0xF8F981C413F4FEC6ULL, 0xF4CB1A997E93A444ULL, 0x5F6A61108D7263B1ULL, 
            0x4BC02487D2E9F672ULL, 0xA7EE6DEAD3F08CCAULL, 0x7CFB6257C70C6EB1ULL, 0xE7BC1EBC6974DEBAULL, 
            0x857F083999450126ULL, 0x939096CEA9A083D2ULL, 0x94641BCB8EE41310ULL, 0xD51481C941B4E442ULL, 
            0x11C521398E2E3D01ULL, 0xB3E20E9716A0D859ULL, 0x31D31A94ED2A929BULL, 0xFF6C5ABB2C21ECFEULL, 
            0x1A821B323DD36653ULL, 0xC5F25EE029D06E45ULL, 0x27786D98EAC606ABULL, 0x17E3998F47CB0DEFULL, 
            0x493AA84ECE0B18C9ULL, 0x31CB3CF1C097AEB8ULL, 0x56C50F8986491E29ULL, 0x3DEAA99C06B8BAC6ULL
        },
        {
            0xD2A56BF02D9BB928ULL, 0xCFF68477DF9E7246ULL, 0xC36C25121E172225ULL, 0x071B3330160712A3ULL, 
            0x573BFEFE89DE2DD2ULL, 0xE3DF47AE7C42F74EULL, 0xB4CAC46994891D78ULL, 0xA97BC814BCAC8F61ULL, 
            0x63BA2FE6A5A51370ULL, 0x77E333721A7A0FD9ULL, 0x2839B4A78F4FCD27ULL, 0x32EB330A05C79B1AULL, 
            0x5083344D74993210ULL, 0xF9CC8BA2F878ADBCULL, 0x2E39508702C332BFULL, 0x8EC82F3DE73B59CCULL, 
            0x244E54A2FDD71379ULL, 0x38A6E40641AC8901ULL, 0x28F399CF9B19582FULL, 0x1F1924E44D282015ULL, 
            0x511B7E7AE7AC50E4ULL, 0xEB27E1A15890A6ADULL, 0x78455DE945FC491DULL, 0xC5F36E107E4FFCB5ULL, 
            0xBC3AA4DB31604A2DULL, 0xBB3C5FA9A1C111D8ULL, 0xBEDCA028B192E77DULL, 0x32EF678799BB6D68ULL, 
            0xBA5C7D3C39C97DA9ULL, 0xA23E62EB24CD9F9FULL, 0x2533889C3AFFA167ULL, 0x3A4BE520417CFCCCULL
        },
        {
            0xB56A1BB032D82D3DULL, 0xE62FF26A20D9B48BULL, 0xE847A83AF8D6F473ULL, 0xB2E35E0B968D149CULL, 
            0xE3CA8422D51C08C7ULL, 0x5E85F54683D1BB94ULL, 0x4508D64E747497BFULL, 0x29C00A465CA1B26CULL, 
            0x3E31EDB8C722BF79ULL, 0xDCDC085E2C08AB11ULL, 0xE3F591F789A4CA44ULL, 0x6B5EA85BCC92263DULL, 
            0x88FDE8D946377299ULL, 0x858274F0CF49E766ULL, 0xB08BB127856D7137ULL, 0xE77833AB721C4D10ULL, 
            0x0738DE307CEF5A19ULL, 0x811780F7DCBB9D56ULL, 0x5776197129F31949ULL, 0x34B9B8DA7B8922E0ULL, 
            0xBDC59D347B165A27ULL, 0x5D86D4E1CD32B311ULL, 0x1D0E5238C1F66A9EULL, 0x1922AF2E3136BFAFULL, 
            0x3F5BD3DD7E932C2BULL, 0x21D5480487BD55D8ULL, 0xC6C045E1F750975EULL, 0x1A2D51CEFED1E7A8ULL, 
            0x0FCEC8EDACD30CFEULL, 0x6AB3488A9C0AC4E7ULL, 0x58834FC29634118DULL, 0x6283A487FA3C4499ULL
        },
        {
            0x49D171AD067FCA94ULL, 0xD3E3B0AE2759A615ULL, 0x7B61D2CEE6A60975ULL, 0xFE8B6488C3F7D50BULL, 
            0x4A2308724074E023ULL, 0x61C773D74E2E30A0ULL, 0x48AC46DC74EA0A07ULL, 0x9619EE964DA40893ULL, 
            0x0F05A35D261B06FAULL, 0xB6B990F80A39F6C4ULL, 0xA0F30464F50E4344ULL, 0xA42924728637E989ULL, 
            0x6820F95A25390E89ULL, 0x3A317A97F061E165ULL, 0xBAF999AD380EC5A5ULL, 0x66547AD65D6101FBULL, 
            0xC18F3A968DFB7ECAULL, 0x42ADC2A16EE9609EULL, 0x59643FE1C2020B3BULL, 0x59262E53F571F1C6ULL, 
            0xC3173D39333A9E0CULL, 0x537D0BE5300FD3D5ULL, 0x9867A4D14F5E91FAULL, 0x7E3E6643D0CFEE3BULL, 
            0x2BDC3F824AA34B14ULL, 0x9636A9BE442CE77CULL, 0xB6054AA700C63E5FULL, 0xA071A2FCCE7AB7C8ULL, 
            0x577DA86A9B4F82EEULL, 0xDEE7E4FBBF3937F5ULL, 0x7EC49EFFA9197050ULL, 0x7F80BBE634BCC68EULL
        },
        {
            0x3BD7E50C1C2890ADULL, 0x22B63A4D4EF02C7BULL, 0xF7858B0A22518CE6ULL, 0x43774715B5211D2BULL, 
            0xF74BE9E1D5EDB717ULL, 0xEBDE8FE2FCAAFF58ULL, 0x884FD60C85E662F2ULL, 0x500C59D12B6AEA24ULL, 
            0x54565C7C67A6743AULL, 0x4EB7B989225234BCULL, 0xBE98C0812F626D99ULL, 0x63F88A1CA428C538ULL, 
            0x7C1294D87F34F691ULL, 0xB6CCEB1584BE0610ULL, 0xFFE849EBD2D33FE6ULL, 0x45145FDCABBBC089ULL, 
            0x493C3E8D4291E34DULL, 0x25D51F7A3270A381ULL, 0x0CD705BDA7426B87ULL, 0x5A6FDFF09ECF71C3ULL, 
            0x3B415D426B993C33ULL, 0x33EE6C84C9B3CF94ULL, 0xB91671D07EEFDA05ULL, 0x51A70A8E57E56BAEULL, 
            0x4387B2B5C992FBB0ULL, 0xE3BC4BD9A3564BBAULL, 0xEFA15CF48A4E5BC5ULL, 0x1FDA225A52A135D6ULL, 
            0x0181745A97EB5FD0ULL, 0x9DC95AA7CC24942BULL, 0x30F2BAFE35E6261EULL, 0xBF72D577589A077DULL
        },
        {
            0x5A5FA130C49476E6ULL, 0x9624902C85A9535CULL, 0xBCB8FD6B3C7DC08FULL, 0xCAD1C59A6238FC41ULL, 
            0x99CFD920B8FC2A8AULL, 0x20C0725779CA0AB8ULL, 0xB62DB4100F8F7E09ULL, 0x433ADD1D73742CE7ULL, 
            0xDA5EDE9F5B5A4C7AULL, 0x791D8969B4AB5F4DULL, 0x84D709AA988E61FBULL, 0xC559C0704C2CC67AULL, 
            0x851D611950E264D5ULL, 0x7DA6393DB4B0273BULL, 0x8D8321E99EE6FC52ULL, 0xC04F31099F3B3CF8ULL, 
            0xFB550EB6AEB2AE2EULL, 0x951C6126D5957B2CULL, 0x4C3A2CB2B70B53D3ULL, 0xAFCCD27CDCC8AAC7ULL, 
            0x23D889061905A7C6ULL, 0xB062E52C7CFABBBBULL, 0x1D0482D33265AAC1ULL, 0x51FF724C654C6861ULL, 
            0x0CE208EF05AD29F6ULL, 0x0C3027F7464AED85ULL, 0x28A18014616EFD05ULL, 0x9577396AD9311D90ULL, 
            0x2FBB92D4F8A71903ULL, 0x1C88142FA8D42732ULL, 0x1CB731C659BCC9DEULL, 0xFD6BE3520F656503ULL
        }
    },
    {
        {
            0x955233CCC70834BAULL, 0x7AEA086FAE7A95D3ULL, 0x7AABAA94828214FCULL, 0x98506428F9F7D1FFULL, 
            0x30CEA836E8F7A42CULL, 0x084682CC083A2B04ULL, 0xB95F6D532F078E04ULL, 0xEBDD3FB099DD83E8ULL, 
            0x6C96ED287055EF67ULL, 0xB9188D55B19CB7BBULL, 0x2F6E1DC518D9C2BBULL, 0xA95BA3D6CDBF3C72ULL, 
            0x1AAB0FA0D7A59A02ULL, 0x93B8CFCCA0309BACULL, 0x6CE3F5B1BD0CDC6CULL, 0x8EA92B09D1ACF126ULL, 
            0xF7F20DC855610DC6ULL, 0xBE5C2E0DF1AF1931ULL, 0x848E75082F6E3B93ULL, 0x9E2520C7FF367822ULL, 
            0x36D9D3C8BDB638A0ULL, 0x1B3F580FF68EAC42ULL, 0xF780B469F3BDFE0AULL, 0xAF0ABC7D572CA775ULL, 
            0x5DCC2A351BA9A803ULL, 0x720FB3FB7528C5BDULL, 0x6B69229F485FC31FULL, 0x5485E420485E9617ULL, 
            0xDAA32CCA99601DB1ULL, 0x29AD5283BB51A7CAULL, 0x6BC8E27445E452A2ULL, 0xDEFC74C18C66E222ULL
        },
        {
            0x7B8A385EBA082DBCULL, 0x6C8B605F05B3C910ULL, 0x54C906A1D6E0A155ULL, 0x03E7A8ED0E52AB1FULL, 
            0xD0931A58B8181F06ULL, 0xBE360137EA1A6C43ULL, 0xDECA3C15310C784CULL, 0xF672F6F82D8FEE9CULL, 
            0x225CC33C67D8B34EULL, 0x143609AE3D916976ULL, 0xB227862B4BA78665ULL, 0x8E12A39D99941071ULL, 
            0x70D5F601F98A6B3BULL, 0xEF8EE6F1A92CA89EULL, 0x7614BCBFC06E55BBULL, 0xB1F2511C8AB78C10ULL, 
            0xD5278F0DD3C07EDFULL, 0x02A4ACF820BD39C2ULL, 0x66A1E405A7B38B27ULL, 0xA4966BE8BE4DC0A3ULL, 
            0x5BCA5DE08A2E4D64ULL, 0x375976567F073193ULL, 0xCF945F8B4FE7A8F1ULL, 0xD3FD562C1F26FE6EULL, 
            0xE0E454E8FFCC3D04ULL, 0x55CB90F107888999ULL, 0xD81586E20403F01EULL, 0x6B58AD039ECDF9B3ULL, 
            0x0179D3C4C3F49D8DULL, 0xCDB563ECDCBA4EE6ULL, 0x3D977D876FC17FF2ULL, 0xE1AACC420994D949ULL
        },
        {
            0x6C4A30F34ACE6F12ULL, 0x745FA8DA5C42EB6CULL, 0x58D91F96E534F9C0ULL, 0xF2E0E1B351D05400ULL, 
            0x5A68022232CA06B0ULL, 0xF91BCA5E7450537DULL, 0x062B9A962A440FC8ULL, 0x5C2AB1ADF6667062ULL, 
            0xF56F892070BD61C9ULL, 0x552363F10C237E51ULL, 0x725B9CA9B1F1E398ULL, 0xA02951359C30E206ULL, 
            0x567C7ABF328ED551ULL, 0x18B0E22B25288291ULL, 0xB3F41A69177539E2ULL, 0x3B6BDD2776A8FB2AULL, 
            0x4953CBE61F56C25DULL, 0x20AB18849F625B0DULL, 0xE020F285259EB5D4ULL, 0x27CC9E09D25E3BE6ULL, 
            0xB9D16DD19C1FB41CULL, 0xA2404C47F8D33C07ULL, 0xA426E8D0FB844632ULL, 0xC8AE84DB1312F7F5ULL, 
            0x9638DF71FA472684ULL, 0xD885E4197ED486F8ULL, 0x4D293FC5779DA177ULL, 0xD86F5166B18F4381ULL, 
            0xD76FC554FD6A9E0AULL, 0xAA77F8AF59C784BCULL, 0x10061DEEFCCB946CULL, 0x4A0AB6A1DAEE3E1BULL
        },
        {
            0x23E3E447659F9C4EULL, 0xF615F690B3E091BBULL, 0x7322A19BFA9958BDULL, 0x9066E8AC8791CEE2ULL, 
            0x4B60DE5D17A16BEEULL, 0xBBECFB1518292C86ULL, 0xC40B4F04767DF32CULL, 0x761235E4BE29C004ULL, 
            0x658D4620AF480361ULL, 0xFFCD523F1A0A2053ULL, 0xD51BEBA8DA3697E8ULL, 0xF06ACBFD4B41C814ULL, 
            0xC60059BE42EE2915ULL, 0xC3D0CC4ADA3EFAF0ULL, 0x88E3F00697F721E7ULL, 0x8A551CAF6E6E6F9EULL, 
            0xEE4D317BB479E0FBULL, 0x86FD08476355244BULL, 0xF3A01FDD0571401EULL, 0xC05165B16B55048AULL, 
            0x8221D93058316372ULL, 0x0F2893F5CCC1BF85ULL, 0x3EECD2F41BC0683EULL, 0x143D019B00059924ULL, 
            0xFB848C38FC96DC53ULL, 0xCC0F7B1AD3D37077ULL, 0xF30C21B3C43B68BEULL, 0xC7F250EE00D91932ULL, 
            0x054D2E4D0CEB8DFDULL, 0x3E157F996A399610ULL, 0x7D370D2D2DC77082ULL, 0x52FF02802E4BA2ADULL
        },
        {
            0x3E030A1FCC62EAC2ULL, 0xA7DB77250670A633ULL, 0x65247B5942180FCEULL, 0x89E82DC3224C8EC8ULL, 
            0x3FC67CB5DE732FBDULL, 0xA34A9CDD3F1EAC35ULL, 0x4532AE335156A802ULL, 0xDFE6137B642386E1ULL, 
            0x5B7D3DE1984F6C2DULL, 0x1B3E29496E5AA374ULL, 0x058C7E37A0895B89ULL, 0xDA4169A0698EFB25ULL, 
            0xC1505B9704D399D9ULL, 0xF322F4122347786FULL, 0x69BB27AD79A94BD8ULL, 0x387E873160D0FD89ULL, 
            0x2E827CB23D476442ULL, 0x9AF99005F97F118BULL, 0x9E58606BB1930F08ULL, 0xF6E339376E9D8D54ULL, 
            0xFC6B612C89CB407CULL, 0x0D63C1EB32C7C136ULL, 0x39DBF102899F08E8ULL, 0xE979015CFA034B6FULL, 
            0x8736F3B4F6C4A4BAULL, 0x9A8614E63F696736ULL, 0x941852F2DB0A56E3ULL, 0x19F9A7E4AF11FC9EULL, 
            0x94FFD56E4E6BF07DULL, 0x834E58D7D28F8D0CULL, 0xD4ECF5023DFF94D2ULL, 0x8DD748F01BC44BC8ULL
        },
        {
            0x66FB9A5CD30A21F6ULL, 0x24F8D91FE11D0F3CULL, 0x98A76B06AAE07FA8ULL, 0xF8F70AA903183FDFULL, 
            0xB3A45146DE521E34ULL, 0xF95A1570F057A1EEULL, 0x21AEDDEA1A2D742CULL, 0x4E7A4A61A2E9171AULL, 
            0x5697A8DE5E4D159BULL, 0x359E422D9F6FFEC4ULL, 0x4264B41535C07F59ULL, 0xAE19147FB8CABFDBULL, 
            0xE1A3489281D146AEULL, 0x1B387B6025EA191AULL, 0xA3C6F8E1E7C12C3BULL, 0x3BFFE5350B4FE576ULL, 
            0x2DAFC3750F9EDAD9ULL, 0x60748C5C1A8FD455ULL, 0x77E2EAEE9913A57CULL, 0x99DB970249196291ULL, 
            0x449F9FC7E083CDEEULL, 0x3AB0E0B2BB9AB929ULL, 0x94E8AC386BF4E9D6ULL, 0xA065A6DECBDC8815ULL, 
            0xA65DAA847720DA79ULL, 0x72547F472B8DB76DULL, 0xAD1A5B92EFE5D4E1ULL, 0xE16DBBD5A324E16EULL, 
            0x0AEF220C2E33AFBEULL, 0x7DFF58E07DF417CCULL, 0xE6792D7CFA8A0564ULL, 0xCD3C12453040213AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseHConstants = {
    0x411C9BB7421217E2ULL,
    0xE867E212E7F64747ULL,
    0xB07DCEB99986C26BULL,
    0x411C9BB7421217E2ULL,
    0xE867E212E7F64747ULL,
    0xB07DCEB99986C26BULL,
    0xEF1A4EEFAB96943BULL,
    0xB8D45DB398938A1EULL,
    0x0C,
    0xEC,
    0x15,
    0xDB,
    0x52,
    0x98,
    0x2C,
    0x4C
};

