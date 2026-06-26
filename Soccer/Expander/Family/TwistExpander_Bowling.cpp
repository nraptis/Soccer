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
        aPrevious = 14398395551589180232U;
        aCarry = 13109242511275539113U;
        aWandererA = 10816621720256981978U;
        aWandererB = 11364962535981212203U;
        aWandererC = 15662631226638932431U;
        aWandererD = 15753141005267604552U;
        aWandererE = 17690746425003852962U;
        aWandererF = 14387594803497842325U;
        aWandererG = 13132403789319941839U;
        aWandererH = 15263061412951505736U;
        aWandererI = 16174814933102250668U;
        aWandererJ = 11179200246960328465U;
        aWandererK = 11480819884901630293U;
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
        aPrevious = 18404928615915517781U;
        aCarry = 10961506127165604669U;
        aWandererA = 12727148945968958369U;
        aWandererB = 17011687084870384854U;
        aWandererC = 10195108954840063760U;
        aWandererD = 13845104898907890497U;
        aWandererE = 10845670606410213852U;
        aWandererF = 9823207379737900852U;
        aWandererG = 16682860868098683479U;
        aWandererH = 17887983417062047691U;
        aWandererI = 18279814894976663484U;
        aWandererJ = 12417652308871321887U;
        aWandererK = 10773993357312355512U;
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
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD);
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
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
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
        aPrevious = 18163947477753854292U;
        aCarry = 10806507871408323853U;
        aWandererA = 11950769227970302009U;
        aWandererB = 13607345351132851948U;
        aWandererC = 12954228137865379777U;
        aWandererD = 9361523786253871174U;
        aWandererE = 10889559928529417036U;
        aWandererF = 17954038208683827215U;
        aWandererG = 12348381398692316945U;
        aWandererH = 17048241136127731348U;
        aWandererI = 11728356834429936261U;
        aWandererJ = 15628881346182043136U;
        aWandererK = 15509370998326495089U;
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
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 0, 3 with offsets 4816U, 5378U, 7861U, 4587U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4816U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5378U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7861U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4587U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 3, 0 with offsets 6348U, 6465U, 3655U, 3669U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6348U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6465U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3655U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3669U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 1, 1 with offsets 2418U, 6523U, 6806U, 1412U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2418U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6523U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6806U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1412U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 2, 2 with offsets 4295U, 3071U, 883U, 8140U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4295U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3071U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 883U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8140U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 2, 1 with offsets 1958U, 1640U, 851U, 1871U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1958U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1640U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 851U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1871U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 0, 3, 2 with offsets 78U, 1571U, 113U, 1474U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 78U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1571U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 113U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1474U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 3, 2, 0 with offsets 1583U, 1592U, 1644U, 1747U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1583U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1592U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1644U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1747U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 0, 3, 1 with offsets 1979U, 1580U, 950U, 1310U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1979U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1580U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 950U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1310U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 304U, 1840U, 929U, 1923U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 304U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1840U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 929U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1923U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 3 with offsets 4379U, 160U, 2988U, 6937U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4379U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 160U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2988U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6937U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 0 with offsets 7789U, 6423U, 6444U, 2525U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6423U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6444U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2525U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 1 with offsets 5304U, 5930U, 2635U, 4685U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5304U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5930U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2635U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4685U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 2 with offsets 4044U, 3777U, 3111U, 1073U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4044U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3777U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3111U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1073U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 6895U, 8166U, 1893U, 3272U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 6895U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 8166U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 1893U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3272U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 261U, 1949U, 43U, 1653U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 261U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1949U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 43U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1653U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 2005U, 1956U, 1142U, 1949U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1956U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1142U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1949U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1983U, 648U, 1862U, 1895U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 648U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1862U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1895U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 440U, 1653U, 278U, 953U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 440U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1653U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 278U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 953U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 0, 3 [0..<W_KEY]
        // offsets: 1677U, 1265U, 1940U, 1980U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1677U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1265U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1940U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1980U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseASalts = {
    {
        {
            0xBED0B4647F4CE86DULL, 0x2C4E57BEB81E89E4ULL, 0x4C5AAA445148F25CULL, 0xC8B7698A95ED326CULL, 
            0x35432C7EAEA21112ULL, 0xA381F31E6D4F5FBAULL, 0x14780FDD266C9125ULL, 0xA0D4ADB45C74D6E5ULL, 
            0x29916C379E63A150ULL, 0xA0DDC8D9DF6BCE3BULL, 0x79EB04E38A978CB3ULL, 0x48280B108628D797ULL, 
            0xC309746DDE52ED73ULL, 0x16A2A8467C705864ULL, 0x10FC321457E129D7ULL, 0xD8BE1F06C98763A5ULL, 
            0xCE36CD5D8C9FE5D7ULL, 0xBEA609EF45E60700ULL, 0x6749A4B558B1A407ULL, 0x6F06227F0CA64F28ULL, 
            0xA8C76985FEABE9E6ULL, 0x13D9264958F2B7A6ULL, 0x6E0CE2A1BC93E106ULL, 0x5601F7C6A2BFD89CULL, 
            0xC4DE4CE920D710E1ULL, 0x60A38042E52DD3A9ULL, 0x2DCD675D376E89D0ULL, 0xD4D7246BB126EB8AULL, 
            0x283628FC692CFC42ULL, 0x9E19542D6024B8C6ULL, 0xC95870EC3327061AULL, 0x7BF1F111ED372603ULL
        },
        {
            0x034A1B72F6506F1AULL, 0x5A887A790A61AB7EULL, 0xE3C55EB7816160EDULL, 0x8087C9A9D7AEE457ULL, 
            0xDDC1DA89EFC9FBDCULL, 0xB79A1B4728D11B05ULL, 0x57B523B9458B870AULL, 0xD3CA08DD360EDEBAULL, 
            0x1A9B2740018FE35FULL, 0x4045465C09C0D0C0ULL, 0xF80CEE1FDBCAF0B5ULL, 0xEE9484FE4F776A02ULL, 
            0x25032CAD029A92E6ULL, 0xBA65606387528224ULL, 0x8C05E8FB9AF8B677ULL, 0x62BDBF455F9C66BDULL, 
            0x257300673AAC0039ULL, 0x6780915C21756A60ULL, 0xC1A93763AFBE9EA1ULL, 0xF027E5DCEA2BE4C6ULL, 
            0x940F5F3928CE8D03ULL, 0x4CB4A8DAAC25943EULL, 0x02560FEFEB704219ULL, 0x35572E981E9F3B76ULL, 
            0x6BFD1B0119FA7A0AULL, 0x7D9B28130ADD5042ULL, 0x0521F4A3EEB94A6DULL, 0xD307B06258502692ULL, 
            0xD8C56C99881142E5ULL, 0x354BD29ECDD99EB1ULL, 0x36FA46175BB894AEULL, 0x4CC4B292ECB2911FULL
        },
        {
            0x9C2F35399C1E0249ULL, 0x0611EB57B5BB1045ULL, 0x851B1A9D02DEE116ULL, 0x08F887AA4C003AD1ULL, 
            0xB93024BD33A56EEFULL, 0x8B39D9CEA2497D16ULL, 0x616875F49EAD3F87ULL, 0x4329D42036F798C9ULL, 
            0x961A16700D7D6519ULL, 0xF38E6211B16B97B8ULL, 0x2F3BA39D380600DCULL, 0x41009A4CA875596CULL, 
            0x665E1E5E259C7AE9ULL, 0x9965FD55C2267546ULL, 0x134EC3FDB8B61879ULL, 0x0090BF8E44847C12ULL, 
            0xB973A30C087A4770ULL, 0x923B8A77BFB633ABULL, 0xEE50A25C51FF9B47ULL, 0x2E7E561CD0ADFEDBULL, 
            0x0B95A4E290B38E98ULL, 0x45FC8796FAAB9BC0ULL, 0x66AA9D585146ACB7ULL, 0xB10D564E08E6BB78ULL, 
            0x14E2CC4650EBC368ULL, 0xE46BF5050CDD2C05ULL, 0x67D5C52A23E542A8ULL, 0xD151353AC9670E29ULL, 
            0x741E64EBDAE3AB98ULL, 0x902C8C9349BA413AULL, 0x3AD5577ABE9676B7ULL, 0x74B242942E766DD2ULL
        },
        {
            0xB35603D1B6F937FEULL, 0x7D9D19AD03C188CCULL, 0x9A2B3AC0BAE523F0ULL, 0xDE741FB7A3DE9EC1ULL, 
            0x1926B3AC3F802F12ULL, 0x77CE44179ACB227CULL, 0xDDA285A833296E24ULL, 0x8B3633F08DABDB92ULL, 
            0xD2F0F16DA91095AEULL, 0x0DBCA90BD7ABB12BULL, 0xF3EA177CC7885EE0ULL, 0xA06EF2038461BEA4ULL, 
            0x8D770563905A3DFBULL, 0x91E82E1D141D2863ULL, 0xE20411DF72E8B51DULL, 0x4A1EDE46B4FE08B2ULL, 
            0x5DF3D09ED46CDF0DULL, 0x81AB45304647F5C6ULL, 0xBDE18EF26C02617EULL, 0xBEE4AE2EFC242A6EULL, 
            0x4886AB3CDE680A7BULL, 0x22A0DDFB7E6D1C5EULL, 0xF62F26FD71534A3AULL, 0xDC77616E40EDB57EULL, 
            0x2149A4FC7658D2C8ULL, 0xC4A996147108A207ULL, 0xA558B466F2D51B01ULL, 0xBB26A1ED1D31F8D5ULL, 
            0xA593F4EE8BD22474ULL, 0xB91155514D5A2C20ULL, 0xE093A72C9FC36FDEULL, 0xBA8A04DF39A75202ULL
        },
        {
            0xEA4874F0F43E502DULL, 0x91C15684C2B3A0D3ULL, 0x6A0DC2121949CC31ULL, 0x4C2EB0F9AC3DE170ULL, 
            0x890FA5C6167F6FE8ULL, 0xFBEDE6DDA59ADB17ULL, 0x356762ED535A20F8ULL, 0x9C844133C07EDC2BULL, 
            0x90B6FFCB4F7B4EBAULL, 0xB3CA083A82333A70ULL, 0x338DA58A80208D94ULL, 0x808C0279AAA663E8ULL, 
            0xD4DEC4693FD21960ULL, 0x2D3D77F826C9531AULL, 0x4399A378B60D5509ULL, 0x147D272C192ADDCCULL, 
            0xA097233C0C68A563ULL, 0x6990A68F40AE0300ULL, 0xA6D9741D6213B145ULL, 0xB1A7DB8B3DBE3A3EULL, 
            0xE4D4E6F208F8C309ULL, 0xEE44CC150BCC0B52ULL, 0x95B9398E6FF06F7FULL, 0xD441B94B38866459ULL, 
            0x26EA279A5DA9D963ULL, 0xE58B96EABC6C2755ULL, 0x968CF5D521DB1187ULL, 0x18D2119A383F3FB1ULL, 
            0x2979E50DA7D7DB7DULL, 0xD13A39AF45F7AF35ULL, 0xCF178DEE05641372ULL, 0x8D7EA40AC1417C74ULL
        },
        {
            0xA09D2C076392447EULL, 0x4EC039C465443B99ULL, 0x2CDE416BFB9A4C03ULL, 0x5D8709D815F97FF8ULL, 
            0xBAFCAA803F5D9B9FULL, 0x30935CD57C67810FULL, 0xBA3CAEE302CEAC31ULL, 0xD2D3BC2FB2EC9502ULL, 
            0x57A20BBCF98869BDULL, 0xA860B6374407E979ULL, 0x8395E7909A7B0F33ULL, 0xD96AC85530E0F4DFULL, 
            0x517C0CD7081FE6AAULL, 0xFE358686F1D1FD97ULL, 0xEDBBC077DA4FACA3ULL, 0xB44931C71EE7E88EULL, 
            0x97775187BEC3A0C9ULL, 0x1C14B56669E4E752ULL, 0xC1FED31B52D86B35ULL, 0xB0AFD15EE089D96AULL, 
            0x4F2ADE3974D8DFC8ULL, 0xB8AD6CCEC2C2A82CULL, 0x81C0CE52EE5C1954ULL, 0xDAC95AF856B7FBF3ULL, 
            0xEAC7817FFCDF05BBULL, 0xD778AE293D632ABCULL, 0xE2F43AA2BB0E4B4EULL, 0xA159DFDEF03C70E6ULL, 
            0x06CD7CCC5113B8E0ULL, 0xB529A57E39858CD2ULL, 0x62626A26E00838F8ULL, 0xB7EB9478431DA7ECULL
        }
    },
    {
        {
            0x50B387759830CC8DULL, 0x3B498BA7B838B190ULL, 0xB24A4CE085603DF1ULL, 0xB2216D700D801056ULL, 
            0x3117B9EF9574D5DCULL, 0x3C638C71F422C785ULL, 0xBD4708B5174B510DULL, 0x0F43F7D525275BF0ULL, 
            0xE48456AA8ADED6DCULL, 0xB7857AC300DAADCAULL, 0xFC429A78232F50AAULL, 0x8D3570CDD9878A7DULL, 
            0x765C240433DE1E35ULL, 0x1F15CE5B7C07D66EULL, 0x54D2181A178A5D50ULL, 0x214200254C34260FULL, 
            0x3F2F374E178BFC2DULL, 0xC74EF2CA9EF12E32ULL, 0xD029AABA29AC6EC4ULL, 0x6F21E4F3B476FB67ULL, 
            0xEF05C3008C7F3DD1ULL, 0xFB774F4D6ACEA918ULL, 0xE10BA7872448A622ULL, 0x5C7C722E2E9EDD12ULL, 
            0x4E7002DBC0571CABULL, 0xC2D3388F8AD01260ULL, 0x164E02ED37D9B894ULL, 0x71A183A2642B8FD3ULL, 
            0x267243EBC5676672ULL, 0xC1C7BF02764DE582ULL, 0x1C5F193F3654F19FULL, 0x061E04158D6BA40FULL
        },
        {
            0xEC5CD83AD4ECCC6DULL, 0x5E8928393D3C7D07ULL, 0x82D211CB668D6E9BULL, 0x7F270FECA0A4695BULL, 
            0x59E885726EAB963BULL, 0x294BE4F16B920CC2ULL, 0x40CE8DB8E8BE5ED9ULL, 0xF2BB2BD3CFD59BDAULL, 
            0x87102D3AA98906ADULL, 0x0439D8601A43D817ULL, 0x0D07B8F0BCE0F13FULL, 0x886DA38A6F89FE2DULL, 
            0xD66ECEE0F9AEBB90ULL, 0xCF587D0BD0CB72B8ULL, 0x748209F30703597DULL, 0x35DFC721738334A0ULL, 
            0x26EF32FEE7C76F40ULL, 0xCFE724AC94298629ULL, 0xD2B20244E48DC8B2ULL, 0x98F3466435B2A97AULL, 
            0xE0CEC464060369D0ULL, 0x9F401CE581B7D9E6ULL, 0x35F4E1AA3E71B795ULL, 0x4B51F685AF4F99ADULL, 
            0x5540AB27B68624F9ULL, 0x5AD5910306D0BF89ULL, 0x9BB87D5CD6895658ULL, 0xF754E3854E63EC47ULL, 
            0xF7F7F7617EBEA456ULL, 0xDB316BCCE5F11A86ULL, 0x6691083FFE09ADC9ULL, 0xCA8053718EE5F02CULL
        },
        {
            0x69DB21324EA12147ULL, 0xB8EC9F7C9372F4DCULL, 0x9A3220D05B8947EAULL, 0x735572B676996B1CULL, 
            0xE452B5C3C5113DA2ULL, 0xFEAA11998BDAC3A3ULL, 0xD8B87A19F671EFC7ULL, 0x6B21BABDF2A256DEULL, 
            0x59289797903AA574ULL, 0x5572D316A85CF235ULL, 0xDC4445E42F746B4EULL, 0xAE3BBD370F45C970ULL, 
            0xE8A15C9A470CD547ULL, 0x97BB3E66D183A745ULL, 0x83886436FDFD171EULL, 0x5A959933176CDBA9ULL, 
            0xB519E58B6CD64E3AULL, 0xB6427D2EFB609BF7ULL, 0x65C7CD81ADE04B47ULL, 0x5D3BC4A3244E99C1ULL, 
            0x4C239FA0FBD08D02ULL, 0x9197D277379B84CFULL, 0xBDAB8020D9BA2192ULL, 0xAAD94006A69BEED4ULL, 
            0x880532DF89570403ULL, 0xB9EE8C1FEC862AD2ULL, 0x424EE7E3DCAC5742ULL, 0x1FD679750CB3C8AAULL, 
            0x8BEA65D7FAB79C4AULL, 0x9DB396D5F803D0B7ULL, 0x114F665DFBF12D68ULL, 0x427ECC5CBA552318ULL
        },
        {
            0x8EAE6DF90AD3DF05ULL, 0x2EEF79F56B14D7ABULL, 0x02FAA1C32448B733ULL, 0xD7C09B3925F5482FULL, 
            0xD1E9B5AD67E0E821ULL, 0x3292249EC54E9C51ULL, 0x938F253D60C520EBULL, 0x3EB58018CC11F4C2ULL, 
            0xCEE8D1807DC8722FULL, 0x3A26991C35A84CF3ULL, 0xCEE8646F0B8CA1A5ULL, 0x3B6F470124502ED1ULL, 
            0x1E5D7DC72A63DFB4ULL, 0x0DC58CAD274C3DB5ULL, 0x314BB8941819F489ULL, 0x32F78E4CC6362F7DULL, 
            0x7B00FBFE852F138BULL, 0x2AB3B5BE52FBDC76ULL, 0xB2AEF8B7A9E8A92BULL, 0x03FFF5A5836AF53FULL, 
            0x72B64E2D2AE83815ULL, 0x856FB5B9DA911B3BULL, 0x5F9739D57FC6462AULL, 0x2803DB643762BF9DULL, 
            0x98FF012DE4CF2C79ULL, 0x4C2FED7B4DE281DDULL, 0x350879E027016C2DULL, 0x3359E85F5BB7D4C3ULL, 
            0xFE4A47093A37C924ULL, 0x6DC5BE6BFBE48496ULL, 0x0926877504566D8DULL, 0xACCCE738F1B1352DULL
        },
        {
            0x9F9603F0CB0012FFULL, 0xDCFFCD0C1D29CE2AULL, 0xF9B0A4F2F0F0398CULL, 0x4547C4F728A2DAF5ULL, 
            0x5D15564C7391D0DFULL, 0x6D2713AD803BE4A0ULL, 0x3BEA5A4DA4C2A34CULL, 0xCC8EC12F4F40EF30ULL, 
            0x350A4AF6DFFED4E2ULL, 0x03095D237383D4DEULL, 0xDDB8CA7A41C7DB21ULL, 0xB30CB78F860A0B42ULL, 
            0x97D122EFE714623FULL, 0x218A77A29D6E58EAULL, 0xC96689592280179FULL, 0x226BF09FA66ADF86ULL, 
            0xD5F461BE1F736F7FULL, 0xF332331C94A4A328ULL, 0x7FF8D4B7A1AEA3FDULL, 0x6C382A383B2E2BD9ULL, 
            0x3C54D52723C8380BULL, 0xBF33075CB8E3805DULL, 0xBE2D4FC294395495ULL, 0x7C41D99CBAC16CB8ULL, 
            0xDE6B7E1B9C0D5C85ULL, 0x0FC669254F8E2C58ULL, 0xEFEF2697D5AB2A34ULL, 0x93B440845DB72E2CULL, 
            0x5310944AC66A9D73ULL, 0x3AA79D4B811FC80AULL, 0x0A01C56E978CCBA2ULL, 0x3C18A660DDAE5920ULL
        },
        {
            0x6703697A016DF2F8ULL, 0x0F7F5B9B52DABC73ULL, 0x95FC621C2E6883D9ULL, 0x2B4A5D83D36351B7ULL, 
            0x6799CFDF50154C1CULL, 0x4802F0BBFACE8253ULL, 0xF33CB4E10335B420ULL, 0xA8ABC3453C0DA791ULL, 
            0x14E8320FF1156D00ULL, 0xB5DAE730A789232BULL, 0xFDA55FD65A4930E6ULL, 0x9F045158221B7EC1ULL, 
            0x6C8D64483935CED8ULL, 0xB8F69F48C0AF8A3BULL, 0xB2094B2956294D36ULL, 0xBE44E58EF1344981ULL, 
            0xCEA4D1CF97AED0D8ULL, 0x79E6EA3E552651EFULL, 0x8B1D1D5721F75C56ULL, 0x997F353A67B36635ULL, 
            0x97D86320377AC7F8ULL, 0x7298BFD7111344EDULL, 0x1AEB650890AA9134ULL, 0xD4CB9DF677090DA9ULL, 
            0xF8249532EA65596FULL, 0x1CF05CED664A1B37ULL, 0xF53D7051376D8266ULL, 0x67599BB19D320DA4ULL, 
            0xABF368A6B0B3795FULL, 0xC1CD4BF4B190A2A4ULL, 0x507C579956F4910CULL, 0x792CEAF7C0B2FA91ULL
        }
    },
    {
        {
            0x0CF19DBDDF338A77ULL, 0xE1258369F434DBFFULL, 0x89EC11AED1C731BFULL, 0xF14B715C1C3BEE75ULL, 
            0xEA659A7629B01CBAULL, 0xD652B6CE5362C228ULL, 0xC67627CF50BEA093ULL, 0xB3FE81D9C2573E26ULL, 
            0x528CF06FD1FB0A52ULL, 0x72BEFE9E65B04DE7ULL, 0xDC6B044B6C1F2CC2ULL, 0x59472EADE2814E03ULL, 
            0x5849EF8DC581B689ULL, 0x4A9641C626DAF27DULL, 0x289992BD477CE108ULL, 0x1D53963357EF7D6FULL, 
            0x7390305021B73023ULL, 0x2F8907C05876D74CULL, 0xE35B8BE3AE900C36ULL, 0x64A2A90110C12169ULL, 
            0x807450E2D8AC3479ULL, 0xABF01C1FBD7E3E4DULL, 0x8C961A38BD75C602ULL, 0x75A1B9672281A551ULL, 
            0x830BC8D9B3B2C73AULL, 0xB1055B5B6E4F64C7ULL, 0xD578DDF1BE418EA6ULL, 0x7640276198810A00ULL, 
            0xE3F699F609F18B63ULL, 0x6D12ABF31A16E6F1ULL, 0xA618C881BAAF4326ULL, 0xD5EA77D0C30BCF60ULL
        },
        {
            0x230134AD75B0DD79ULL, 0xA89A70DE0C6BB3B2ULL, 0x8A8B3D9B3A418FF3ULL, 0x4481B981FC7E9A18ULL, 
            0x86D13AD74B0D7F05ULL, 0x0785122038C60277ULL, 0x56065F2A5387D0C2ULL, 0x49BC1B1F1A7119D4ULL, 
            0x6E05D0D28EEEFE1EULL, 0x1FD33A6106A5E4F5ULL, 0x1662D3AE6AAEE608ULL, 0xFE881CF509D0BF34ULL, 
            0x37B0CD173D24B630ULL, 0xC9A9ED35239EA5EEULL, 0xD7E9490239157855ULL, 0x9999FAD2D1E195DEULL, 
            0x44A372363C0C8FC1ULL, 0x770BB45B0A1FF688ULL, 0x809F1941854DFF29ULL, 0xDBB502CC55A1FCF0ULL, 
            0xC9517F2CFE158CD2ULL, 0x3F8FB5DC8FC73EBAULL, 0x8D44A506ECB75455ULL, 0x82551082FCDE6ABDULL, 
            0x21C50A8AA27A7E7FULL, 0x5DD7872C6BD5940DULL, 0x07990CF974959E9FULL, 0x68E4F46A7577D9FBULL, 
            0x2F08817A0D70F5F7ULL, 0x90F64E5041BD01C5ULL, 0x6D06BAE6AEE19778ULL, 0xD31E63A68022B883ULL
        },
        {
            0xFEFC58D2EF06C8AFULL, 0xE46DA9662F18ABDCULL, 0x16D69D405CB56213ULL, 0xDF8D5EAC3211C619ULL, 
            0xEB87067163C26A0BULL, 0x7ABC932D3B7EA676ULL, 0xC552B63AE93DF083ULL, 0x9D0C340ADC779215ULL, 
            0x622026D5EF9393B2ULL, 0xD8014899BDD2602DULL, 0x027A9133FA93639FULL, 0x8C884BDBFCD4FAD0ULL, 
            0xF5807A014A013411ULL, 0xA942B19FF8966BE4ULL, 0xF6B70D00F2E4A5C1ULL, 0xC84411C82A1E622BULL, 
            0xF8EE3FFBFA686607ULL, 0xAAF12A1118808521ULL, 0x98308F076B96459AULL, 0xC6C91DB88DA8B651ULL, 
            0x5342A437CBA8D4FDULL, 0xCCAF2289A2889377ULL, 0x3A361841050C3DABULL, 0x999200ADB6496EC9ULL, 
            0x5FB23BEAEB64D730ULL, 0x7E693887219C2F79ULL, 0x83C6D60760CCF826ULL, 0x16E43B6B04F14ACBULL, 
            0x4219D35615A7E526ULL, 0xE687DB704154D71CULL, 0x1BF7FD85874C15B2ULL, 0x640CFEEB0F45B596ULL
        },
        {
            0xB5C8DD494CC812C9ULL, 0x3D409FAD8B064070ULL, 0x6762C1472798472BULL, 0xEF8C35E1C5C7EC2DULL, 
            0x2326D54E6C86A0A1ULL, 0xA749730CC379079EULL, 0xA17E2BDC9DAAE5B3ULL, 0x593A32BF8FFE7DDEULL, 
            0x8B4107206DF63CCBULL, 0xA9A38A2DE22C8F09ULL, 0x19956EF6BCCE30E4ULL, 0x7540E66C1CC2E6AEULL, 
            0xBDD22E6792826B43ULL, 0xA2ECB486C7EA8401ULL, 0x17E35004B7F82BC6ULL, 0xD52000EBE0FC1867ULL, 
            0x6D9E388A08CBCFCFULL, 0xBA36798BF99F94ECULL, 0x649AD08C8F51D604ULL, 0x1C6079B145489915ULL, 
            0x9B91140D6B6A15D6ULL, 0xF2EE1C7B44E12D2FULL, 0x21EF0DB231071958ULL, 0x6380F05EFE891F56ULL, 
            0x365A70FF54E3DEE7ULL, 0x4DB2904E2666AEDFULL, 0xF78CEFE28BB6A61FULL, 0x32CF8F9D8BAC2C06ULL, 
            0x485B6AE4D595EAE1ULL, 0xE4E8272FD0FBD7D6ULL, 0xDB5B5704C96631EAULL, 0x1A40F063CA0EA73EULL
        },
        {
            0xB18181BA05F2D547ULL, 0x259891B4BBAA5133ULL, 0xD3521330470ACC65ULL, 0x6323DBA461D86A0AULL, 
            0x826488C5CE1AFEC4ULL, 0xA1A0C49A9FDFEE2AULL, 0x27D15FCE99256B01ULL, 0x7CCFDECE20AC09D0ULL, 
            0x66DFD922B65269E8ULL, 0x64744FBBB1FF2790ULL, 0x07BD8ED86042AD27ULL, 0x898FBF33B0A65B78ULL, 
            0xE2E78B1D62D4A415ULL, 0x097FBE2862F62634ULL, 0x2A99BB9CAC0202DEULL, 0xDA86C0688FF622F5ULL, 
            0x7060C0DD46CE6D76ULL, 0x987D012005DDE6B3ULL, 0x21760F880C039501ULL, 0x5F3274D7A7C979E6ULL, 
            0x636806506663A31AULL, 0x5514084601E89D18ULL, 0xA5F92E6B82672467ULL, 0x71D4EF8CB6215D23ULL, 
            0x8C106B2592164427ULL, 0x1FD0226F584DE883ULL, 0x692A03E65B507F55ULL, 0xD6DB448B0B417F71ULL, 
            0x80EBBAEB339E1F92ULL, 0xB91FB23CDF6A3CB1ULL, 0xFB659B555B4E40C8ULL, 0x030FCB2AF4A3E5A1ULL
        },
        {
            0x806E7EB8A96AF735ULL, 0xDC20E66FC1AF088DULL, 0xF4C29F168B725523ULL, 0xDB21436AB039DF28ULL, 
            0x5006074FCE5483D3ULL, 0xE7FEA5402405DB26ULL, 0x5C4C42EB3D10A846ULL, 0xF3270F58B9CD9E7EULL, 
            0xCCAE28A448D6CD3FULL, 0xAA1E262106350895ULL, 0x08EC80EDFA1D8DD9ULL, 0x563BC64646A68FC5ULL, 
            0xD08A6641B31B892FULL, 0x14D84F3E77EB9BBFULL, 0x587E984444A85CE4ULL, 0x55675FC96C779F73ULL, 
            0xCF7CB2FAFD59A03FULL, 0x8036ED344BD9A3ECULL, 0x6FC15F65DE43BC26ULL, 0x82163A89A990E8DAULL, 
            0x32262FC127C7F73FULL, 0x271B0CC02FD21835ULL, 0xC673D9C906BF3AB4ULL, 0xFE1069F368566DCAULL, 
            0x1860409886D3CBD6ULL, 0xB0158B964F1525BBULL, 0xD3BFC3EEE974B3DBULL, 0x4E45C154AD4652A1ULL, 
            0x80836C6E9538F1B6ULL, 0xC824F296F9D89FEAULL, 0x64FE1D98E93B07D3ULL, 0x0ABB757C91F50D90ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseAConstants = {
    0xF99C003233548FCEULL,
    0x3CB536D415162AC4ULL,
    0xDFF857AF9EE176D2ULL,
    0xF99C003233548FCEULL,
    0x3CB536D415162AC4ULL,
    0xDFF857AF9EE176D2ULL,
    0x53F0B043B6A92D3BULL,
    0x0803B02F3CE3B4D1ULL,
    0x0B,
    0x86,
    0xA3,
    0x88,
    0x19,
    0xF6,
    0xFF,
    0xFC
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseBSalts = {
    {
        {
            0x6AF78202FE50CDB1ULL, 0xB7948DA78D684B36ULL, 0xC17E3EA399BB479FULL, 0xE6F4805D7C466726ULL, 
            0xE485631B4A219A98ULL, 0x80E0253C1EC83BC1ULL, 0x5181017660ECF8ECULL, 0x4E44929CF885324EULL, 
            0x5987A9554B6ABD7DULL, 0x0CFF510F94CCAE69ULL, 0xBEC656BBACFBA856ULL, 0xD3BACAD2CEF82C87ULL, 
            0xD4DD61A91D020B94ULL, 0x075DFE442C976F94ULL, 0xDA457DB436F5EA90ULL, 0xC31DA8528BB191DFULL, 
            0xB9626F50920DB83AULL, 0x9E09CD55B00A8E1EULL, 0x960EB5A06A0397D0ULL, 0xBDD3D29A9EF8C7D4ULL, 
            0x397C90C2B4CF3FA7ULL, 0xE7AD3C61AE92A5FEULL, 0x56BF0771D8F1F667ULL, 0x8E2328E1050DF9FBULL, 
            0x7659B10D2DEC6143ULL, 0x99B4FACCB903A25AULL, 0xC404EF4C0CAB38C3ULL, 0xF8DFBBEE5C6F37D7ULL, 
            0xC99F9E68B7B91194ULL, 0xA670F888A012B47FULL, 0x1990F0D0326DD24DULL, 0xBB51537F978EC1ABULL
        },
        {
            0x454EBBE756EA4591ULL, 0x2045173C2D2EE4ACULL, 0x399258FA767955C7ULL, 0x04DB9EB56DEBF4FCULL, 
            0x6F2DC941BD9B566FULL, 0x4C7C62A5836D1639ULL, 0xB0BCEE8EB6EF6258ULL, 0x3FF3FF76C70A26C9ULL, 
            0xEA4D8B318CD25788ULL, 0x5872B9452D431CF3ULL, 0x986ADDA1FD799EB2ULL, 0xB8C4E8B19383A196ULL, 
            0x5C779A9E78CF44D3ULL, 0x32DCAE298088F5B0ULL, 0x6C87C7B1E072DEF1ULL, 0x888D0811C193042BULL, 
            0x768E73C7B6BE65D5ULL, 0x0474459DD4A33735ULL, 0x9473793E728369A9ULL, 0x8C224B1595170F26ULL, 
            0x47A5717E19AAE89AULL, 0x639FE6A9FB082191ULL, 0x20B54462249A42CCULL, 0xED063AAFB71687B9ULL, 
            0xEC77F9D8F0718EECULL, 0xADEFCC285284D4BAULL, 0xDECD522AE1028710ULL, 0xFD12C90892A6920BULL, 
            0x089A4CB7013AF0D7ULL, 0x9706C32A74F4731DULL, 0x748D851E18BD6007ULL, 0x65E8E5DFEC23676AULL
        },
        {
            0x08C52A765664D8FCULL, 0x1A168538F4318AC3ULL, 0x177824D941706139ULL, 0x4765B6518D21CF07ULL, 
            0x06908B1B3D941B6DULL, 0x384176238E02ADABULL, 0x7F6828DFEC52ED71ULL, 0xE1B511909758A794ULL, 
            0x193392E930D9F810ULL, 0x50AD63236DDD879FULL, 0x6AFA4FF0B0BCECF9ULL, 0x14570215D6968FB7ULL, 
            0xF5187110AC297830ULL, 0x73D6E2A3E51A6F27ULL, 0x86A5649D1AEA0578ULL, 0xBAAE5079455EF45DULL, 
            0xD772E51D44A6CCA7ULL, 0x699FB87AA168F1DDULL, 0xC3778828BB46C5EBULL, 0xB48EB66E0A1DF871ULL, 
            0x8D06DCD2CBC2785DULL, 0x54584D714DA5B323ULL, 0xE2A7A156EEDB24F2ULL, 0xEA96DA9D34C63A54ULL, 
            0x8156668DA1930D9CULL, 0xC6AB6A5EE408877DULL, 0x02E5FD92EE129887ULL, 0x6F6F670D679D1F37ULL, 
            0x574CF407F844095EULL, 0xBE742D33D9C8C1D0ULL, 0xE51E5D478E5BD885ULL, 0xCC10CAE14B4FF724ULL
        },
        {
            0xECCA602DE679D8B5ULL, 0xEF0EE6D3012AEEA1ULL, 0x8FBFBBABF7334748ULL, 0xE4AC7533ED425C8AULL, 
            0x6737DD6FD8007340ULL, 0x6E63CDFF514B5CDFULL, 0xD6CD6C34494A26DDULL, 0xC3DE54AAAD610265ULL, 
            0x4E40E823D7A43202ULL, 0x0B06A52A68238E3CULL, 0x0057F983692A5BB6ULL, 0xF6A1F941F93B1668ULL, 
            0x84892776C7F1179CULL, 0x31E47AED53217A4DULL, 0x39B462B3DFE752E1ULL, 0xD2EEC0AB0ED9AF0CULL, 
            0x11FB7A8EE3A96743ULL, 0xDC83F3D505082B55ULL, 0xE4F52D6AFD370109ULL, 0x3C68D393201B766BULL, 
            0x50356652E9905859ULL, 0x82A56F1E05207E93ULL, 0xC3ABDDC62FA1817AULL, 0x262795780807C99EULL, 
            0x5BE5EEE352D55C6AULL, 0x228C22A7C1FB66B0ULL, 0xF92BE9CF3152FDDDULL, 0xEC2EDF38DA0FB6A6ULL, 
            0x085421EDAE3837D4ULL, 0x5D41CE1A98F1067DULL, 0xE431EA70962F3ABCULL, 0xD88E3A6E08D1802CULL
        },
        {
            0xDC001AA93BCEC082ULL, 0x7DE0F17219BC80DAULL, 0xA9C60BF97E7FDE86ULL, 0x9899372C355CBC81ULL, 
            0xEB08F8A3F2949591ULL, 0x45F1D3624560E283ULL, 0xCFBD23E61854B11BULL, 0xAFE18E9371DC20A3ULL, 
            0x12D8E0216273E032ULL, 0x16735ABB785F2F78ULL, 0x62117B0DE1DF0122ULL, 0x950AB61B86C21173ULL, 
            0x5460B95DF71A186BULL, 0x3F5B522B7C9AC958ULL, 0x4F3068351A6F3D08ULL, 0x26698A0C01EFAEE5ULL, 
            0x6DA67400267F2893ULL, 0xED6A0C62688004E3ULL, 0x53D5DFBCF27AF68FULL, 0xAB6D82C0724D4F1EULL, 
            0xBFE12BE8493E663DULL, 0x2E2B1AAD5CAFF7B6ULL, 0x958C18789D6E3B59ULL, 0xC56EBAC84D3A32D9ULL, 
            0x0BEC986879931B7BULL, 0x412F50B0E9FABE0FULL, 0x9E1C03260E54706EULL, 0x519AAAFCD1B51B69ULL, 
            0x58A6D6AE4B672151ULL, 0xD7EF721B61C7A6A8ULL, 0x9C0811AEE0744E05ULL, 0x4D0B98338604BFC2ULL
        },
        {
            0xE94AF7115511B503ULL, 0x8CAFFC2F227976D6ULL, 0x04D3294308BD5756ULL, 0x44F73796869FBF54ULL, 
            0x0D9740AA5FDBF3B5ULL, 0x0B4191489EF16260ULL, 0xBB7009A615061229ULL, 0xC246E06BF5627BB1ULL, 
            0x5C98553D564C6E78ULL, 0xAA6F52E98AFF690FULL, 0x028893D7D209C76EULL, 0x4CEA7A93EE8E98C3ULL, 
            0x20E6EB2521F97DFEULL, 0x35F9C3113976DE5BULL, 0x214E40401BD3E557ULL, 0xFC371177C38135C4ULL, 
            0x357D76A9FEFA9950ULL, 0x418D1D8C8E8B4917ULL, 0xD5A731558E6ED5A6ULL, 0xF574D8A75C243149ULL, 
            0x1C66A19CC6D96F88ULL, 0xCCA3D151AFF2D848ULL, 0xA4D449CCEBF10034ULL, 0xA6C482B8F177ACB6ULL, 
            0x5F52C207E3F2BD63ULL, 0xB6DDE1D41ACA9D07ULL, 0xFE171D9375DA8E7DULL, 0x18BD9EA1FE7DF645ULL, 
            0x32C22B5931E4E62AULL, 0xEA8CE33FB3CB23A1ULL, 0x46F98685E59EF760ULL, 0xE2496A39B4B52B50ULL
        }
    },
    {
        {
            0xB8414DD71E18421BULL, 0xFA189CB8FAC36F67ULL, 0xD634FDEDDE8B221BULL, 0xD4C744B9D0273827ULL, 
            0x6808911EF3D0E4D5ULL, 0x055C85E53F0F8585ULL, 0x8EC66CEE4CDEC842ULL, 0x6E4FD6A2E3304DACULL, 
            0xFE1757430A1EC633ULL, 0x7216D74AAF67DB97ULL, 0x6A80F0C637C03114ULL, 0x435E89E50214D169ULL, 
            0x3B38AD38228FDBBDULL, 0x7E2FFE23A01EB30BULL, 0x23D040E9C4156EB2ULL, 0xB5F738C11D137A75ULL, 
            0xD12F2332306B6FE7ULL, 0xCB8E5B87262A2C68ULL, 0xB929F1436889FDA3ULL, 0xB53F25DEB7FA20BAULL, 
            0x86FE56F8944C50C9ULL, 0x039B6AFE271032FAULL, 0xB5DF948592F027A5ULL, 0x4D8DCF396563D502ULL, 
            0xACA4770DBC4043E8ULL, 0x167C8EC4EEA887CEULL, 0x76FBFF385C8A31D6ULL, 0x2A57BB256B6796D6ULL, 
            0x4D9782BEC80EFD7BULL, 0xCD07C8E1D7488EE7ULL, 0x3683BF04DCDFD5DDULL, 0x6614F0FD43955456ULL
        },
        {
            0x14977F220BBEB357ULL, 0x0B97CB6FBAC8FD13ULL, 0x86F3F3D529C98CADULL, 0x8DCE2AA11D0F505AULL, 
            0x1E49FB705B857497ULL, 0x3347429244162ABDULL, 0x5F9D18391F73D3DEULL, 0x17DDD92C2C9E6FFEULL, 
            0xAE41F397B6C05BB5ULL, 0x9F18AEB6B6DD1A41ULL, 0x678673E197E3925CULL, 0x7C78CB5543F11660ULL, 
            0x0DDFAF65E63BA654ULL, 0xA74561E6E41BBEACULL, 0x90E5EB669C0BA8A3ULL, 0xC33A9EBDA674B0B0ULL, 
            0xB5464F9BDC2F50E3ULL, 0x73D3FE33199C11E6ULL, 0x84A27C3577AB9D79ULL, 0xAC28D8DD283F0387ULL, 
            0xFFEF8DD1E207F0EAULL, 0x6785D8C1F32189C1ULL, 0x57519196B78BA7A8ULL, 0x40D445EAF98BBCBCULL, 
            0x85066226F651B059ULL, 0xE3C8C69BA25E0724ULL, 0xBD075FBA213CF823ULL, 0xC352CF592476C0D1ULL, 
            0xEFEB6A16C14E6D0BULL, 0xC65F3AF41CD7466EULL, 0x1D3BABAC123E63ABULL, 0x4EA6460035C5ECF8ULL
        },
        {
            0x2A2E0457FD16C74FULL, 0x3481C9F34CACAA17ULL, 0x37A2988F87F346C5ULL, 0xA59661337350DD72ULL, 
            0x70983518942D6CC2ULL, 0xDD035558EA5867F4ULL, 0x410F663050407D5BULL, 0x3BE5E519ABD0C0EBULL, 
            0xE71675443129F613ULL, 0xDA8DC88DEBCADB4BULL, 0xFAC727BE9ECB1186ULL, 0x57A7225D54AA7F3AULL, 
            0xFFFC5CDBB72366F5ULL, 0x90CEB7E5502D2B7AULL, 0x1A45AC300978A832ULL, 0xB01AB421B09D70F2ULL, 
            0x50815944B36A94C0ULL, 0x9F0F12CCDCD71261ULL, 0x171B658FCE8A965BULL, 0x92F3BA442E241D7EULL, 
            0xB3B4FE9520E61F8CULL, 0x409A21997E447DACULL, 0x16F9417B9C5AAA3BULL, 0x57066E93D7FFCA57ULL, 
            0xC624B39E91BD7E76ULL, 0x0CBF00B3CB362852ULL, 0x6A78EC763A23D996ULL, 0xF83BE1A394F21550ULL, 
            0x482F4751461007A3ULL, 0xBFE062909B35470CULL, 0x90A913B860AE2554ULL, 0xAACF95FB8DD525A7ULL
        },
        {
            0x0B5EA116E9A5817FULL, 0x6A464A482DF1AC48ULL, 0x77F434160A664FA0ULL, 0x842112708E07C988ULL, 
            0x34DAAD96B3E458A7ULL, 0x2DC60B63185B733FULL, 0x4C4DE5D90A0019F4ULL, 0x98B6AE62EC0CBF1EULL, 
            0x2AB72A557C977A03ULL, 0x8594592448A63B46ULL, 0x03850F0934BE4A7EULL, 0xC276B2073AE776DBULL, 
            0xDF5CC2FABFAAF299ULL, 0x06A559D9EC1D11A5ULL, 0xA39BA61D972759E7ULL, 0x8C399171972AC4D9ULL, 
            0xDF32FFDA6D38A7B4ULL, 0x83B4B21907EC9AC7ULL, 0xF491A015C5007ADFULL, 0x1A012DA73340C4C4ULL, 
            0x2E12988D2CD71F5DULL, 0x51B156450522BFADULL, 0xFA5DA48AFD70A041ULL, 0x5829F47E43E54B60ULL, 
            0x805F78C67A1C9F3CULL, 0xC6616FBBECF7A3B6ULL, 0x9B2818EE068E156EULL, 0xED288E21DC85D05DULL, 
            0x352EEC7420DF96DCULL, 0x454357B308F2883DULL, 0x513F8603A8DEF837ULL, 0x4EA706C51B25E3F6ULL
        },
        {
            0x38178BD556FE74ADULL, 0x09F053FBC09A9A45ULL, 0xCB224EC9D68730D2ULL, 0xBC4DA7D843B72E9BULL, 
            0xC2EF448609B14488ULL, 0xAE9F5DF621F0FE00ULL, 0xCE307DC74E083135ULL, 0x26D49CD2648FE77EULL, 
            0xAF22F19348A99C77ULL, 0xC5C0F5DF8774175DULL, 0xF41CD97C3D307F9AULL, 0x87EB878DED2756DDULL, 
            0xC3406C2B2CB1995EULL, 0x700EA2E13C4B2BEDULL, 0xB02EB67079C217ACULL, 0x07DC6A741C14F1ABULL, 
            0x7357DE4671AF8722ULL, 0x964629F0423530D1ULL, 0x3C427AA296928A89ULL, 0xB163B68B5687A303ULL, 
            0x42FFA1FC82121AE8ULL, 0x3761C1221051398BULL, 0xD57425067E618D77ULL, 0xE64EC6709E835DA4ULL, 
            0x345AE3AFC6296A00ULL, 0x9E8E7A6EB613DE07ULL, 0x0F029A26BCE33062ULL, 0xBF8A0EC5362AFDB5ULL, 
            0x889993496E0F48C0ULL, 0xBF066F11BDE94F2EULL, 0x9C08636F50E93942ULL, 0x519585CC8425F7E8ULL
        },
        {
            0xD2BEA41D031786A8ULL, 0x04249AAF1386EE86ULL, 0x14716DF9923587EDULL, 0x58B601DE412F8CFFULL, 
            0xAE8ED2D730F858C2ULL, 0xA145DED8DB89DBAFULL, 0x244B5D7895F69EEAULL, 0x7EDAD735BA7106ADULL, 
            0x51FCFB88277C8E80ULL, 0xFCEC9EAA2D53BBBCULL, 0xFB484D23631B9689ULL, 0x22AA7B6586E41B3FULL, 
            0x47714B42196DE90FULL, 0x26D4842A253DC27CULL, 0xE8EF2A8D3999FE9AULL, 0x529E7747B4638AD0ULL, 
            0x6B506368D9E7626AULL, 0xE5F0308012A2192FULL, 0xF4FB5FA030709FC0ULL, 0x29D5F6109DF2679CULL, 
            0xB9C33F0FFDDBC6B1ULL, 0x49BC8EBD98C0618BULL, 0x39E4716902362C8BULL, 0xE903BAA146800858ULL, 
            0x69654F83FB6B631EULL, 0x36CA40A115CAAD65ULL, 0x36B1A44C06FBACF7ULL, 0x4F01922329DBCCF7ULL, 
            0x86EA5BCD3BE617D4ULL, 0xD802D3D2E7522A12ULL, 0x072A5EF5B86A7727ULL, 0x317677A6E57A07F1ULL
        }
    },
    {
        {
            0x9F66375286DB6DBCULL, 0xFCF373E51CF58D45ULL, 0xB7E18ECB07FDEBDFULL, 0x88D8B757554939AAULL, 
            0x2D1E8C1E1D98B94CULL, 0xF3A0B10013841143ULL, 0xD33D10362FDCF12BULL, 0x708B1EDA3F059E9EULL, 
            0xB578048921FE92D7ULL, 0xADE694438FE267E9ULL, 0xD40549B5CE1F4387ULL, 0x688CF050897FB113ULL, 
            0xB3AC88A0148834B8ULL, 0x1829C93FC9055E48ULL, 0xB0A897395F2B70EDULL, 0x7F80B6D01EA5EFDCULL, 
            0x1D7C7F3A7BF1FD6EULL, 0x10B54DA8D86F86CAULL, 0xE760C840F809E223ULL, 0xF37A803BAA303DA1ULL, 
            0xF96E8FA22B877114ULL, 0xCEEA5A14C347B886ULL, 0x1F50F28F08D70FA3ULL, 0xA8E74F6344008020ULL, 
            0xF0AA97928C6B6B39ULL, 0xB5742A9312AAE08BULL, 0x282AA2E6B99C09E2ULL, 0x98B3B59C009255F3ULL, 
            0xB502EB15CBF08E96ULL, 0x6B3001345BEFB566ULL, 0x75FBB5B8E091F2EDULL, 0x391D4F78A2B5AD64ULL
        },
        {
            0x30F07E7AC0201F21ULL, 0x53E4F2DA2C879A17ULL, 0x72CAD3D18C3177F6ULL, 0xD22DBDD7AEE744E1ULL, 
            0x6D2D5BAA113588D0ULL, 0xD4CD574B03DB6E2CULL, 0x678A64ADE3271871ULL, 0xD40734ABE8F3B5EDULL, 
            0xE42F4DFB602E7529ULL, 0xCF516AC1EB1FEFAFULL, 0x1608A3684E37B934ULL, 0x072745D5B96F373FULL, 
            0x35217A94621FE245ULL, 0x4FF33F606D3137DFULL, 0x6F1B6453FCDF0308ULL, 0x1D2170090E0DFDD0ULL, 
            0xD26CB70918F53E86ULL, 0xC910A4348F2D0689ULL, 0x0B3397B866ED0D9BULL, 0xE041972DBF916066ULL, 
            0x73C2DC2A47C0D4B9ULL, 0x16F2E28F71E76C73ULL, 0x036F10AFCD2CCE0DULL, 0x764321D6302B06E9ULL, 
            0x60B09DC8C7275157ULL, 0xF3668A5419B90B77ULL, 0xEB5C336972EA2881ULL, 0xAA83E9DC4005CCAAULL, 
            0x6046A94E1C257124ULL, 0xF27FE70E185C7B3DULL, 0x11584E6DA7CD47A8ULL, 0xB7215DF1A8973BD1ULL
        },
        {
            0x75675F4F9F8D2272ULL, 0x5B75A7566FF54690ULL, 0xBB1FC34D58344336ULL, 0x720D57A1D83E65B9ULL, 
            0xC15BE3D43AB0234CULL, 0x355F32F5CE674BB1ULL, 0x00421AC55C209362ULL, 0x54095113F701B389ULL, 
            0x10930CF933E26A80ULL, 0x6C7A67AB3866AE81ULL, 0xBDE5B9B5581590C5ULL, 0xF47CFA829D45B8CBULL, 
            0xFCD956468CF47BF0ULL, 0x4634116B8B3F9304ULL, 0x41E35643B79625C6ULL, 0x5F91A7BF2DE68B85ULL, 
            0x0181E380448AF091ULL, 0xEFDFBA752682B822ULL, 0x28696FD5B3522BE3ULL, 0x406B6DDE1D7031B4ULL, 
            0x879DF6EAB3EF7A9DULL, 0xED5115A426837269ULL, 0xF634252DA2CE7577ULL, 0x850DFF348F7C5128ULL, 
            0x66C617C25598BFA6ULL, 0x5855FC107A68AE84ULL, 0x3AC4671C174B7248ULL, 0xC2E6B0B1A6B20435ULL, 
            0xFA745FD5D5C186B5ULL, 0x0E6C67BE9E7EC796ULL, 0x0E6BE3E5E30D5AC7ULL, 0xC48280B23A7A90A5ULL
        },
        {
            0x2D4FF94444FF6917ULL, 0x6E2ABF1F61119529ULL, 0x9A15D81996C616D0ULL, 0xAB3ABED8CB55CD18ULL, 
            0xC2A33A9BA7EFF575ULL, 0x254C5DDFF03BC662ULL, 0x3BC632250F993B24ULL, 0x0E98965DF99AEC72ULL, 
            0x1C37792120297EC0ULL, 0x40C02FD20D7E5DC7ULL, 0x6DB57F2EF5B33283ULL, 0x1715B56A42BC1CC0ULL, 
            0x399A1201006FFBEEULL, 0x82A9D0BF1E5283C1ULL, 0x6C0EFCECC0387523ULL, 0x471B7209A5C28189ULL, 
            0xBAA0DE1F1691FFE8ULL, 0xE6DCF12D1C05E11AULL, 0xAAB8F0620FC6CC48ULL, 0xEE0AD7BFF7F92AE7ULL, 
            0x925CCE6EA6544634ULL, 0xD5A6E81FF97FEAFFULL, 0x8DAA22EA1D3D1DE6ULL, 0x3E47192D2D7CFFDCULL, 
            0x8312B4BE8EC424B6ULL, 0xCF4810515A266B09ULL, 0x01B7C8389DF2A6A8ULL, 0xAC6FEC8C084D0295ULL, 
            0x7CD433B7589C2680ULL, 0x7F951A1BB4115461ULL, 0x088EDF8FD51B506DULL, 0xBCCD6943E9A17246ULL
        },
        {
            0x7C10C7EBD8971A4BULL, 0x1A4BF8F8787F3112ULL, 0x15650EF1A68C7837ULL, 0xA6283138C8DBFC47ULL, 
            0xF684F4C4E5EB1EA7ULL, 0x1480A5274FE1FDCAULL, 0xC3312736BF0CEEE5ULL, 0x11A3CEB13B7E73D1ULL, 
            0xAA43564122ADA868ULL, 0xC5D93E53F78F6993ULL, 0x019CE304835824B4ULL, 0xC512973BAA096019ULL, 
            0x77C053E6D1269B70ULL, 0x56106751452BC7F3ULL, 0x733621763A5121FDULL, 0xA09B883228D3642DULL, 
            0x81ABA56B3600B341ULL, 0x8F572FC2A6939849ULL, 0x2A023C714DC5EE31ULL, 0x57D41F039A3C3C9CULL, 
            0xED82EEB4749C2CFEULL, 0x3922AA638B3FF92FULL, 0x193DE637E7D257E5ULL, 0xE6B49B891D2276D3ULL, 
            0x180F0BE399382CC1ULL, 0xB41737941EB259C7ULL, 0x6084DD2F07808949ULL, 0x03DDAF44724069A6ULL, 
            0x1A18AE14BBD9E16EULL, 0x571CDBBFA04325E4ULL, 0xC2412EB4FB46B524ULL, 0xFF7BF02A64C23385ULL
        },
        {
            0x8FB3B242BEB12FBEULL, 0x283E8A452BB5E83FULL, 0xC7AF051CE307EAC0ULL, 0x8EDC5B4C11128A01ULL, 
            0x1EA807261B2B7BD3ULL, 0xE7FCCBF022EA4A58ULL, 0x258941B5CC3F95E9ULL, 0x3C292D36A5ACDBA5ULL, 
            0xE9C29F8FFE8D9C58ULL, 0xDDBD57E724DA239DULL, 0x829EB2F8459CE61AULL, 0x75C84447DF16DBD7ULL, 
            0xF2AED747C951BD59ULL, 0x9F00F0A26506319BULL, 0x1A99E3D7613817C9ULL, 0x3C1A645D2BBC04DAULL, 
            0xEAA1472178757623ULL, 0x7BE21C6CFD60D44CULL, 0x03420926EB709D8DULL, 0x7C1C13091DA5232AULL, 
            0x9C981599BAB21DF3ULL, 0x7DABD441EA747F09ULL, 0x91E5D4CA5C010385ULL, 0x52AE0C5CD97D24A9ULL, 
            0xF6161D621C9513DAULL, 0x1409E1C5FC42C2CCULL, 0x16DA6E13FAED30B2ULL, 0x419071D264EFEF19ULL, 
            0x5FAF09A91C252EF2ULL, 0x8327A78492F2D461ULL, 0xA1772042E2CB580BULL, 0xF611F3EDF08A85DAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseBConstants = {
    0xE7A3DAE2B688D8C1ULL,
    0x96751CAA13B23F0AULL,
    0xD1FAF192B6C2938EULL,
    0xE7A3DAE2B688D8C1ULL,
    0x96751CAA13B23F0AULL,
    0xD1FAF192B6C2938EULL,
    0x549023A22920BC16ULL,
    0xBD6271C2F357409CULL,
    0x14,
    0x06,
    0xCF,
    0x6D,
    0x3B,
    0x62,
    0x91,
    0xC3
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseCSalts = {
    {
        {
            0x7DA17960E488EDF3ULL, 0xD5491F92CD300511ULL, 0x179C4E0144DC2DECULL, 0xE9467035E697F7FBULL, 
            0x0725758E7EB549E1ULL, 0x96BDBAF1881FB2AEULL, 0x23CEC56A9FFA84E7ULL, 0x3D06A12365210E93ULL, 
            0x416259F0813921C7ULL, 0x2B5B2C885CE0752DULL, 0xFA79F51990E8CB9BULL, 0x6C9A171AA54F856FULL, 
            0x86D7883D8C938AE7ULL, 0xD8DC7F1BA9696E7FULL, 0x84C5D186FCEC5DE6ULL, 0xD9A7AB8124A39C37ULL, 
            0x01CAD6CCE5895B1CULL, 0x2CAB23CECFB32A50ULL, 0x13FFDC020D6E9BEAULL, 0xA79A52C81FF1761CULL, 
            0x0F66DC1ACA074153ULL, 0xE0D533A200FEB740ULL, 0x2BF0B5978F4AA6B4ULL, 0x8536929EDD3C7813ULL, 
            0xDCD8ABEBD010A117ULL, 0x976CA07EC5D9F80BULL, 0xEB4AB4ACC298CFC5ULL, 0x3B7872F02D0262FEULL, 
            0x74FB3371D1192832ULL, 0x40BCA36CA9B99517ULL, 0x8914EDE2D1E36E3CULL, 0xB3D30FDBFD8A4D0AULL
        },
        {
            0x28487AE7AF15A7C9ULL, 0x90D8A6EC2C164E33ULL, 0x7C0DE8DBAC2FFC7DULL, 0xE2756334F72BB1D4ULL, 
            0x38C631CD0AC0FC1BULL, 0xDEC011976BA50C7EULL, 0x47729A314DD762DAULL, 0xDB8579E3B17ABA46ULL, 
            0xB29F63ECFC38D814ULL, 0x594CF94136AADC33ULL, 0xEEE73FAFC4715166ULL, 0x31869AC09D4FD202ULL, 
            0x58A2AB3BF114103AULL, 0x4DC21873E7BC45C0ULL, 0x8B6AE0B329FEF4AEULL, 0xB4B0DAD5C82A5EC4ULL, 
            0xEA1AA019C143E14AULL, 0x7A6C56B01BCCA24CULL, 0x1BA54C42A4EE1E21ULL, 0x9C2EB92E4A4E7080ULL, 
            0x173E98ED34115E5CULL, 0xC8774361591EAB10ULL, 0x7F688C152173AB3FULL, 0x03066612C28797DDULL, 
            0xEF25679C8BDB94D4ULL, 0x1940BE8FF730E294ULL, 0xDC36D6BAE4A2C359ULL, 0x1F1B43FC93C516B8ULL, 
            0x1C084B7BF358402EULL, 0x10A8A1E84FA2C376ULL, 0x1F7AEB908A323481ULL, 0xFA807012A99D89A0ULL
        },
        {
            0x52E54BBC512D0ED4ULL, 0x3BD2B94B5B4D91E8ULL, 0xF03DC19012E10FD3ULL, 0x6B42A7BC37E7454FULL, 
            0xF0079DD3DC607DB3ULL, 0xF8653BEECB6CB4F7ULL, 0xBEE11C0F1C386EACULL, 0x79E7D93BD5BB6745ULL, 
            0x21A9727CDC99B033ULL, 0xE5D5AD78E9C398F5ULL, 0x58FCD40911C545D5ULL, 0x3C9ACF455FE6CC0DULL, 
            0x1C85418C8A1F66D8ULL, 0xAF10F4830AC6368AULL, 0x6A77D472941EA10BULL, 0xF1BFCA444D3B5BB0ULL, 
            0x6C1BB99F11457198ULL, 0xA8E127FF58D67905ULL, 0x577D1545F5CFA93CULL, 0x39EE5F60D0B38990ULL, 
            0x706D82AD2FABFEBDULL, 0xE5B6BDD30AC6C23AULL, 0xD62EEA86FA901775ULL, 0x48C69B2F621CB620ULL, 
            0xE434B4A7132E6BB1ULL, 0xF02BA6B8678050D1ULL, 0x6DF220142C2EF849ULL, 0x97BBA23622013E33ULL, 
            0x85EDA1092EEB90BBULL, 0x33AD2AC0F134CE0AULL, 0x700E139C4933708CULL, 0xF5279388B8406E37ULL
        },
        {
            0x83CB01E362AD748DULL, 0xA8ECBF73114DC09DULL, 0x985E296051EA5238ULL, 0x9434464045417F97ULL, 
            0x31FE7F15E960B099ULL, 0x99BA1855369248F7ULL, 0x6DCDC9AA95406920ULL, 0x0DF3AE7F636FFE54ULL, 
            0x53D719B4BBDAF218ULL, 0x1649EAF740CB3ED6ULL, 0xA9229C0A05E22B24ULL, 0x733B06F491508A5CULL, 
            0xF89B6F29FAB3AFDAULL, 0x80853B5F5E0BA686ULL, 0x98C4C76D5CE537A4ULL, 0xC25FB457A7456F41ULL, 
            0xC691F3D26AEA9DD9ULL, 0x40DB301879FFBFECULL, 0xA8FB237281301E89ULL, 0x7E2AACB47D075D28ULL, 
            0xC1487AB3A7311538ULL, 0x15E0B52A20F55F01ULL, 0x66AFE4BD531B500FULL, 0xE28921EEDAE2C636ULL, 
            0x371A43C3399E59CAULL, 0x40D396698B9D951FULL, 0xEEABC7D83BA60728ULL, 0xC724CCF67CD460EAULL, 
            0xCCE21AA03BCE3CF4ULL, 0x9B5D00ECA23F2248ULL, 0x0C5F80195D697560ULL, 0x6BFEE2A55143E8A7ULL
        },
        {
            0xD4F31A1302F97D9AULL, 0x1F78933787AC5A39ULL, 0x1EFF504F88858B8FULL, 0x5B65E5E1CC1E4CFDULL, 
            0x35DC2F94F67BAC15ULL, 0xD88059424AC2F414ULL, 0xFE318808A45856CDULL, 0xC0BB8229B3B0EEF3ULL, 
            0x31B336A963FC00E7ULL, 0x99EAFE2ED88EE897ULL, 0x015D4E46F138B717ULL, 0xFCCF0A53C600C410ULL, 
            0x4113B9F433FD7B3CULL, 0x36FE3B7B0990B085ULL, 0xF973AA6F6B1A6406ULL, 0x6531C56C88DDB9ABULL, 
            0x28C14753C2F90C22ULL, 0xF06889644CA74979ULL, 0x7C5955D5D2D20401ULL, 0x7A2BA0E26E0752F8ULL, 
            0x4C6C81C7128EEFE9ULL, 0x69CB3572A8C0556FULL, 0xB1BBB35B26280F1FULL, 0x85F510A84FC0604AULL, 
            0xC71630D96EB1565CULL, 0xFBD7F5172922F327ULL, 0xDAF67730EEADE88CULL, 0x7DA4EDFB0C287E76ULL, 
            0x2E84B4C85D9F3C77ULL, 0xBC26D920BC778176ULL, 0x4E1F5D5742D40BA4ULL, 0xBDA578CAAD188D20ULL
        },
        {
            0x25D0327CB2600415ULL, 0x00D342B2F14853B6ULL, 0x98B8DB4EE037913CULL, 0xEC614C59553ECFB5ULL, 
            0x569BDCD31050CE9AULL, 0x2F383DC576A8ED67ULL, 0x3D439951100B1705ULL, 0xA9955106FAFE1EA3ULL, 
            0xE34027559CB2A7DCULL, 0xEF1F0308401086CAULL, 0x22DCE0BD73B319C8ULL, 0x19390947B66B7C3AULL, 
            0x61CE8E9FBEA57718ULL, 0xF624D2915E41D443ULL, 0x0E3DB4ADFE57D6E4ULL, 0xF8505147F6F25351ULL, 
            0xC7C0103A5F32599FULL, 0x216A16BFEED7C2CBULL, 0x745DEB97CC2B1315ULL, 0x8D8538083C528750ULL, 
            0xA0916E2993DA47CBULL, 0x6A18526ED50DECAFULL, 0xD3C675700610D27AULL, 0xD56EC3CE1DA3DD7DULL, 
            0xA5521E653FEEFD94ULL, 0x1418DD62EEBC7E22ULL, 0x4D0AD7E99FBCB8F5ULL, 0x9FD5BFFD554CC762ULL, 
            0x717DD0A74BE0BBE6ULL, 0x89A155738BCBED5DULL, 0xD3A9217C77807D1EULL, 0x684F546B7540DAF6ULL
        }
    },
    {
        {
            0x79D7A8F98CF156DCULL, 0xACE3DBEC33150687ULL, 0xF61C3F63E638B8B9ULL, 0x1BE26AC40192C484ULL, 
            0xEDC938B29680FE88ULL, 0xE958906131B4DF0EULL, 0x3B429A10B751341DULL, 0x6736811F8D66D33DULL, 
            0x3499DE8A873B72C1ULL, 0x277DCB9DB62603EDULL, 0x1BA8494A3A68922AULL, 0xB6341F6525AC8D62ULL, 
            0xCA9B186E5EBDA86BULL, 0x42455F8BE9601B89ULL, 0x0D2E9067E15F72AAULL, 0x7029C5C7B71AB9DEULL, 
            0x0837CBCD0E14C397ULL, 0xBE10B9AADE32C1BAULL, 0x8888955B11755EC2ULL, 0x487049F617D8F7E3ULL, 
            0xD63FCB24102F86B8ULL, 0xA4CE0D01B863861FULL, 0x15EEFAE5F13CB499ULL, 0xAE8CD59C70D52611ULL, 
            0x8972ECB25F3EC4F4ULL, 0xB2AE2988FF47B7EBULL, 0xCF03C2DE1D554706ULL, 0x769D78B41B9057A5ULL, 
            0x21383A522CA5071CULL, 0xA6EC06FC702FD92AULL, 0x9D7E515EFF8FC1DCULL, 0x7BCA5F781B8482F4ULL
        },
        {
            0xBBDD14CE4051E70AULL, 0x79DCE6F8A1DFDF03ULL, 0x53182453153DDED2ULL, 0x9F2549E6ED55D38BULL, 
            0x7D4281FFF5F1F174ULL, 0xE69638C9F4AFEBFEULL, 0x3AA1C94A8AC811B2ULL, 0xC803DBAB8F29E5EDULL, 
            0x49815E291DA90871ULL, 0xE3AD539730D34FCAULL, 0x97D8B0E99940D9D4ULL, 0xD1F40DEC9E7AC5E5ULL, 
            0x59131D9A06C0ADD7ULL, 0x03535684DD30772AULL, 0x518A3B5C01905774ULL, 0x0B4D75FFB927F218ULL, 
            0xE48CC4DC454DE370ULL, 0x36E95CABD6D45CB1ULL, 0x9E4EBCB293D0E6FAULL, 0xA8C851371FEB9002ULL, 
            0x657F0F5BA2DE7800ULL, 0xE256B5A2747EB5ECULL, 0xB3214C6A9FB0F74CULL, 0xF222227844485782ULL, 
            0xAAFB5B6D9BB67CDDULL, 0xADEB7098E6BF6295ULL, 0xF7F76D9DB8EE6C60ULL, 0x9F8DC5DFCE0DC6BBULL, 
            0xBF060B945B4092A1ULL, 0xCD8157305FEFD0FCULL, 0x054D619019F9F9DAULL, 0x9B010ED4473CA78FULL
        },
        {
            0xAC9F709B529E2FC8ULL, 0x05BB87753C9E90A5ULL, 0xD394936B6EE6E5AEULL, 0x74BBC5AC4203710CULL, 
            0x301B6FFDBD1A9E25ULL, 0xD83BCDEC1D85494AULL, 0x419D0FA8CA7E08F1ULL, 0x8CA8B81F2048A85CULL, 
            0xE54F1E154A5B2100ULL, 0x495179528E8454A5ULL, 0x5B31BA1AFB2FA06BULL, 0xEA32A79E12AAF0E1ULL, 
            0xDEEAD9A8EAD91A34ULL, 0x7CA102CE5977882EULL, 0xC96A2B3CF525C66BULL, 0x15EC77DE8E9A1A54ULL, 
            0xE5F07FEEDC219F03ULL, 0xDE2060905A446A0FULL, 0x9A51D85B95FDFBD7ULL, 0xD3C9332264DE12C8ULL, 
            0x78B7DE918FBC2EFCULL, 0x07A90853BA558229ULL, 0xE32E47C68ADF2D13ULL, 0x12691664A4403FF7ULL, 
            0x9D9F9604AED3DE9BULL, 0x0FECE29D8F24F7C1ULL, 0x060FD7BD644FFBD8ULL, 0x1C77074670DA6AE9ULL, 
            0xB5333A1BE3E53AF6ULL, 0x13A54449532D3C49ULL, 0xDCD4271346D1BBD4ULL, 0x56D161CF98F2B775ULL
        },
        {
            0xD479CADC99E33459ULL, 0x96521BEE470340D9ULL, 0xC4F471B2B4444E63ULL, 0x64C59EA6D7524CECULL, 
            0x41A3EB44FD43C836ULL, 0x4A88C48F6F2588B3ULL, 0xEF702BCFE4989021ULL, 0xC1BEE08720CE68AAULL, 
            0x19F2269B13A09AABULL, 0xAD17D4441CB09DFEULL, 0x9D880FF2875247E7ULL, 0xC1323BB22F8EF1E4ULL, 
            0xEE702123509CFC59ULL, 0xA1D92948B0953719ULL, 0xB355417D72E8A48BULL, 0x789A80C7FCDCE8DBULL, 
            0x94B903A9D622D255ULL, 0xB7A60D2F8D6AD711ULL, 0x676EED2877498314ULL, 0x7B3EB2DDF5FBAE95ULL, 
            0x0F0195E0198DFD4AULL, 0xF206EE4AE3B7950EULL, 0x79A737E2B58FCD2CULL, 0x9E98594B88880512ULL, 
            0x4CA5C7987DEB5845ULL, 0xA4B7376556AB6485ULL, 0xD18BFF8F100AEF23ULL, 0xD2C73EA41B7CEAA5ULL, 
            0xC80F570FD48C02D3ULL, 0xCFBEEB57DAD6AC82ULL, 0xB26B5BF4070693AAULL, 0xBD33D31A0FE6C92BULL
        },
        {
            0x13D003BDDF1C76E7ULL, 0x86C9F79253CFEF9CULL, 0x7A59971DFEC4A68DULL, 0xD0A1AEA1933129A3ULL, 
            0xAAF0BD0DC0EA2309ULL, 0xD0D85BCE9DEC998CULL, 0x8FB872EED60D3F69ULL, 0x5616C98ABEAAEBEDULL, 
            0x45EC51ACDF8D8DB3ULL, 0xA2BBD9FF58A2F92DULL, 0x3807E7D36EAC731FULL, 0xF412178F245A5613ULL, 
            0xE0C9ECCCD0DAA630ULL, 0x14CD4423CFB6C4B9ULL, 0x8AC0940AD8796934ULL, 0x610DB471077F56ADULL, 
            0x818665A52CD2296AULL, 0x0C8EE65FAD29C7F8ULL, 0x7E990DF5BCC45394ULL, 0x12489E8C658903CDULL, 
            0x76A400C98B0EFC04ULL, 0x3915958122921FE6ULL, 0x59D9951464E42779ULL, 0x488BEB91A762928EULL, 
            0x43245D33D6343706ULL, 0xD398F40A4F479B54ULL, 0x4F32F3A6D3A99721ULL, 0x6789D49F80F2AF93ULL, 
            0x3CB94D601AC8710DULL, 0x26A24CADF212873DULL, 0x56564C0F19182232ULL, 0x53F910CFA6A70E30ULL
        },
        {
            0xF9E5408B97CB22A6ULL, 0x4BBAFA2D59188A9FULL, 0x17F658DCA5F5A18FULL, 0xD7DD0FFEACA6F07FULL, 
            0xEFFDAC2A632622C5ULL, 0x69C38B27062D65AFULL, 0x537BD8C4F5E1D054ULL, 0xCFEF8EF6856C28EAULL, 
            0x92ABBC3EFDB8EF9DULL, 0xB39EF2EFF65F5595ULL, 0xE63AB2E7EE55086CULL, 0xDDD5FEABD3399533ULL, 
            0xA274810D2686D167ULL, 0xCA265A0E55BA78D6ULL, 0x8B0519B26E6C585DULL, 0x0BDE798B7497829FULL, 
            0x525E00C8CBE472D5ULL, 0xD463B24203D5B730ULL, 0xD5DE0CFE6A8FCA04ULL, 0xA30D9EB9082F943BULL, 
            0x1A6BA5B36171AFD7ULL, 0xCF1C97C1DB1E1864ULL, 0x44C4837D608EE3C8ULL, 0xA1F04F29497D6D54ULL, 
            0x2A521A4E00E37E6EULL, 0x1116E297EEFEAF09ULL, 0x7648515AD542794FULL, 0x8485A4460174D4E6ULL, 
            0xF0BB8BBA44EA553DULL, 0xD53A9F5AFF7A67C7ULL, 0x0F159CCDC8B82453ULL, 0x86CDA68F885AEA11ULL
        }
    },
    {
        {
            0x3AA8B9025CED0CCDULL, 0xD9DFDF3713012D18ULL, 0x30F5E6521AC4EDF4ULL, 0xE8B6C90AB1CB309EULL, 
            0x79E604FD90A29FDAULL, 0x6090C5E98663F64FULL, 0xDD15D02D6EB1AF3BULL, 0xF89E213288F0A015ULL, 
            0xAE1C8CB1D94F658EULL, 0xFA9AB5F7A4B667EAULL, 0x54A5D1A1C2C88CC8ULL, 0x69D46D56CF64015BULL, 
            0x9157FD0860B491EBULL, 0xE3ED139062AFB090ULL, 0x1FF29220039D02BEULL, 0xD92F87925A7F2DC8ULL, 
            0xCF6293F4454EC445ULL, 0xBA8AD26DD7290E20ULL, 0x9882B70405DE8C79ULL, 0x3E7B70EF68B68030ULL, 
            0xE09063776BDEF4D7ULL, 0x58144616CD72854FULL, 0x81DF9E23FFBDA984ULL, 0xF07E23163F3B4251ULL, 
            0x0514A72B6BD37740ULL, 0x79E9D33742EF6AF0ULL, 0x263EDB20E3DB4ECBULL, 0xB72AC063543423A0ULL, 
            0x35E2F7C4436A83B9ULL, 0xB7FB67C1A5594858ULL, 0x90CAC904274AAEFCULL, 0x1D6384EE6BE264FFULL
        },
        {
            0xB25CF3A3BC9AB9E7ULL, 0xA01B39BD0DB4D6B1ULL, 0x292BA6D3C80A6869ULL, 0x6DDDAB378EF7361AULL, 
            0x8E1968DAB390B8D3ULL, 0x03F03706A03B00C1ULL, 0x9D64E2AB048412ABULL, 0xF87634D8125EA81BULL, 
            0x6B12DE1E6C4CA48AULL, 0xEAA87B2979B800F9ULL, 0xBBCA80FC163F70B3ULL, 0x35D7BF695AF83874ULL, 
            0xA6A4A9E28589A37CULL, 0x03F0E0DA1E6C0769ULL, 0x01DB6336065E4A43ULL, 0x9F1D5BE801F7867DULL, 
            0x550F7FE5BBFD86F9ULL, 0x43A8F5F63C3535C0ULL, 0xC3736B8D971B3924ULL, 0xA3EB2B9967742A43ULL, 
            0x09BFE4428D91755AULL, 0xCF6BA1D34DD66320ULL, 0x1ED8A18094D80A4EULL, 0x5F1148F18727B58FULL, 
            0xACAA33B5A6DB541CULL, 0xEEADADE6A92CE11CULL, 0x5C213721F1A10A93ULL, 0x3991AD0A282D7F14ULL, 
            0xAF5E933D0B013473ULL, 0xA972608C74F06C63ULL, 0x0368FD624CEC02DCULL, 0x222E7F90DED4D1A8ULL
        },
        {
            0x3C185F9A6657BD48ULL, 0x3712C771F4DAF641ULL, 0xFA824DC851AE940AULL, 0xEB6F963892E80E40ULL, 
            0x33358EC2BE593F25ULL, 0x0B4624B84141F503ULL, 0xC1119783C70BCD8AULL, 0xD08CE938ADCE1A3BULL, 
            0x078B291B1A6FA173ULL, 0x31D91C9B28C786A0ULL, 0xB23574BF23E95601ULL, 0x72AC54698ADC4333ULL, 
            0x4FF27F80ACB28E91ULL, 0xEAFB26497A43B5EAULL, 0x6152BF96560E524AULL, 0x8351627B05084769ULL, 
            0x1D119DA9A64B5965ULL, 0x0E43EC74CE081032ULL, 0x9BD692BCE9F41A40ULL, 0xA1AF62ED08F35D8BULL, 
            0xCD838562600166ADULL, 0x49EE9BFAEF9AEB01ULL, 0xC894B04A366CAC5AULL, 0x47200DCCFEC2D204ULL, 
            0x51978A10E28165FEULL, 0x0C6813EA5D48DE28ULL, 0x582205582D7DBF3FULL, 0xE32197C1D4B126C0ULL, 
            0x47E29A644B6C294AULL, 0x5A6D6E2F5E1C1052ULL, 0x6D981B14BB345DCDULL, 0x7A3BBB2B3C9EDEC3ULL
        },
        {
            0x4282E03EF0C2E1C0ULL, 0x9DCCCA4419953312ULL, 0x178FFE2BC7A0FB00ULL, 0x25848DABA14C555CULL, 
            0x768FE476AB46E3F8ULL, 0x79529C9F58546A78ULL, 0xA7D06AD0A06714D0ULL, 0x08C1938F745533D5ULL, 
            0xA67BA93C871519C2ULL, 0x5F9A3D950DEBD381ULL, 0x52532F6E41F17A7EULL, 0x5AE19BA35CC98E7EULL, 
            0x944D88B2F54FCD86ULL, 0x8DFDA6A3A1972E88ULL, 0xF47D9B3BA8E617E3ULL, 0xFB85DF5D6D9DF63AULL, 
            0x4F12D5C23EE2E3EDULL, 0xCD0B053D1769287CULL, 0x7E775B579CD0358CULL, 0xD347F532409940B1ULL, 
            0xC7C3547A127F1311ULL, 0xF8A4BBFD49F60B90ULL, 0x12A2AF6A70991C55ULL, 0xE03A2F3563A19645ULL, 
            0x48A0CA3B83C115A9ULL, 0x088B9E03CAFB24D2ULL, 0x03CB90EF8FC566FAULL, 0x80AB3FAB925E9501ULL, 
            0x79E31B4288820D31ULL, 0x9267E7D5918FDBDEULL, 0x186FCA3F23CB3B6EULL, 0x0CB6C766DB4D2147ULL
        },
        {
            0xB3663B12677FEFECULL, 0xD6A8DA942D69DA50ULL, 0xED8610AEEDE78044ULL, 0x4DF1D792302B04F7ULL, 
            0x3029E24879033B6EULL, 0x29CCBE5AA93B7584ULL, 0x72216D57540C308BULL, 0x8AFB448AFB4554D8ULL, 
            0xC58F3A96F1B22648ULL, 0xE7BF186C6C5C16C2ULL, 0x2CE4946238E121C1ULL, 0x2F5506BE15D71AE7ULL, 
            0x35C22C71D462A695ULL, 0xEDD94B6307701BDBULL, 0xBECDE43E3BD16397ULL, 0xBC99E948B63DC104ULL, 
            0xB04171AFC2438ECFULL, 0xBAA9B4A3DF7451E1ULL, 0xBDAA561E533C20C0ULL, 0x2DB26280B4944484ULL, 
            0x5AC551506F8FB5A0ULL, 0x5B1B4FC926805EE7ULL, 0x3B1C003133C8609AULL, 0xAECECA627B4560E4ULL, 
            0x9952018F1002C021ULL, 0x6D546C168B185420ULL, 0xF3D5A2250617D01CULL, 0x51D997AA8445D8D2ULL, 
            0xE6842FFBCF7C05ACULL, 0x6326FAF0744A5F83ULL, 0x643CC73AA6330011ULL, 0x7A03A7F70A91BF00ULL
        },
        {
            0xEE808C91E901A37AULL, 0x53AFF8DD5A73853AULL, 0x11CC8AA930850C04ULL, 0xAA46A7F0F7EE8C29ULL, 
            0xC00B578E625FB048ULL, 0xC6C4306CEF10959DULL, 0xE0A6441ED37C7933ULL, 0xD92FC86E88129B12ULL, 
            0x94EBE97A5A557E83ULL, 0xB497A5F7B6DFC306ULL, 0x1AFB0561A722011FULL, 0xD6F40E6125B2ED15ULL, 
            0x924781E1DA3243FBULL, 0x60D246FB34546600ULL, 0x82449FEE1EBEEEDAULL, 0xC9DA0F16326EB75EULL, 
            0xB0984065D779C76BULL, 0xB11EA82218D0D38EULL, 0x9802618ABD19103EULL, 0x49A46CDB3C5E9F47ULL, 
            0xE1DADAE8CF03DC0BULL, 0xD57CF046E7957C2FULL, 0x02F273E5C35C0E53ULL, 0x42C23FA9D67C550DULL, 
            0xFF243C9AD249CC92ULL, 0xF32432D6962B5D40ULL, 0x152D29FA08640F77ULL, 0x96DF191C1CE9AA18ULL, 
            0x5D7F8D7EB603F145ULL, 0xC28349F884603CF6ULL, 0xF7F1A10B3055DDA6ULL, 0x2379F5CC1A528953ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseCConstants = {
    0x9548ADCEFA3A1AE3ULL,
    0x7D373AA0C15A4FDEULL,
    0xB1F9CB6D48156709ULL,
    0x9548ADCEFA3A1AE3ULL,
    0x7D373AA0C15A4FDEULL,
    0xB1F9CB6D48156709ULL,
    0xBE0E331BA63AC082ULL,
    0x54B45077D2F53D23ULL,
    0x4B,
    0x90,
    0xC2,
    0xBA,
    0x95,
    0xEB,
    0xAF,
    0x89
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseDSalts = {
    {
        {
            0xC0B25F45D7B92AB3ULL, 0x393AC464681E2C7CULL, 0x1E954C1CDB98F1F2ULL, 0xEEE9D198EF89E501ULL, 
            0x1788A586EF87138AULL, 0x97520396F7C9FE2FULL, 0xE2B68263544F8780ULL, 0x2ED557D123F535F8ULL, 
            0x0CFD174F894C1925ULL, 0xCC828227235DE3B7ULL, 0x33454FEDF696299DULL, 0xAE7B7A2C82910105ULL, 
            0x3D5EAF144552FDE1ULL, 0xA60D18C037ECD8C8ULL, 0xC792203E085D2020ULL, 0x3FABB2F2555296D3ULL, 
            0x722D05A1B0AF388BULL, 0xC232801F9309A600ULL, 0x945E58F43CF24E90ULL, 0x04CE3AA44EF95EACULL, 
            0x48BF3D3250695BD9ULL, 0x1B9100E06F78078EULL, 0x62F23C276EABCC46ULL, 0x544AEFA4A8837872ULL, 
            0x5FF34AFAEEBE1BF8ULL, 0x48AF56EF78475044ULL, 0x71D23708A380E705ULL, 0xF707220ECF870C85ULL, 
            0xA10CEA35F4BC261CULL, 0x729C6B6604E64C35ULL, 0x0A56568BE0D8086FULL, 0x633BF0CBFAAFC7F0ULL
        },
        {
            0xE37E84803131EDA2ULL, 0x050DC50C36AA5A70ULL, 0x35F7BEF6C64B9131ULL, 0xBA5023DFCD4C18A3ULL, 
            0xBCA169D66203DE0DULL, 0x13DFB8C47FF3EDECULL, 0x02B8ECE2448B0B42ULL, 0x5D9B51153196208CULL, 
            0xE934D8FC36904C90ULL, 0x9AA6C0DB93507970ULL, 0xE2004D4A8AC6B7D6ULL, 0x7322E10E0A696A30ULL, 
            0xB9BA19D5E4ED5365ULL, 0xED47858F1EC39F28ULL, 0x0102749C03FDCF64ULL, 0x913580B011A41279ULL, 
            0xE7D726BE53F85DE1ULL, 0xC2E69ACAED69DE3AULL, 0x2F64214059AAFED0ULL, 0xE3200E92D9D63C07ULL, 
            0xE379BF9ADB9C93CDULL, 0x084AA5193E87FDF6ULL, 0xB2131BA8090DB6D3ULL, 0x4C5B0269A4F69150ULL, 
            0xBA0FBC8B1AA8A541ULL, 0xCEF46C410EB32B17ULL, 0xB89291A2E2AC6952ULL, 0xBB823D801C64C15AULL, 
            0xB7A1D85028C16759ULL, 0x343FD7050494080EULL, 0x980C241CB00E598EULL, 0xCB4296C18B3D09C0ULL
        },
        {
            0x3D4D8E028BA496B8ULL, 0x2AA151AF0345B9B5ULL, 0x33AC16CB2F7C7F6EULL, 0xE5B9163EFE65B41CULL, 
            0xD6DAE713BF722585ULL, 0xB77F41152DDD5DFDULL, 0x122FBC6035DD8546ULL, 0x5F8F094A45BB2ABBULL, 
            0x3DACAF51B82870A0ULL, 0x0F4FA7F82DDF46A3ULL, 0x1D96B3F430E5873FULL, 0x8A40588A62B4A777ULL, 
            0xE8ADE6D734729C94ULL, 0xE2CA40F72EE61A49ULL, 0xCB70D795E6757D4EULL, 0xED044777DA9FB477ULL, 
            0x7AE4CDC64E08EB92ULL, 0x199D2388614C7753ULL, 0x6D0CD4677A9724BEULL, 0x71594CA390FBCB38ULL, 
            0xFB74779BB8140854ULL, 0xF7450CB73D07759AULL, 0xC80D29CBC81160C9ULL, 0x403A27C4E2427E3BULL, 
            0xE91F2D9AB835BD90ULL, 0x90EE84A662E52D65ULL, 0xE79A000927B344F1ULL, 0x6FD4B7AF25160447ULL, 
            0xEDEBE620911CA0B0ULL, 0x5D5EC224EB635440ULL, 0x52E149F13BF86A4DULL, 0xCFD7483C196B5DB1ULL
        },
        {
            0x8049B172FE1DD75CULL, 0x96555A7F7C1E49C6ULL, 0xF753831652F9EAD4ULL, 0xE627216F0C49204BULL, 
            0x2E3ECA8ED2AF681AULL, 0x349E4E7FA5F534F0ULL, 0x7B6793F5F4784CB9ULL, 0x4FC01B9C5C584052ULL, 
            0xD93F7A5015207655ULL, 0xFB49C068BAA222D3ULL, 0xEBDB14F3633FB291ULL, 0xB504087128A314C7ULL, 
            0x2981BAAF57C447C8ULL, 0x39BE20A4D567CE50ULL, 0x478A3D509BD286B0ULL, 0x49A2BCC186B82CC3ULL, 
            0x4F8BCFE5E6C9F281ULL, 0x0773493A103A361FULL, 0x07FC42DC95768440ULL, 0x3C2EC6964077207EULL, 
            0x71A63FACC3195DABULL, 0xA6EF7153FA8AE90CULL, 0x560EF03331BC6C88ULL, 0x5CCDEC0F38132AF5ULL, 
            0x838B9C2D990069B6ULL, 0x1CBF518C9FC78842ULL, 0x34DA589028CD19D7ULL, 0x0C9079920F7B74E5ULL, 
            0xC443988A063F8E21ULL, 0xC1A1E20610DD3448ULL, 0x853DBF57CC628F05ULL, 0x448D6FBE4C7B5602ULL
        },
        {
            0xBC0B3005959B2CF7ULL, 0x10C6DEE55BB5D0C6ULL, 0x854F3EF86AA23A0AULL, 0x56F6B068663BD892ULL, 
            0x79761E1BED02A887ULL, 0xF443F06DC19A3C68ULL, 0xF0FA60506B906434ULL, 0x42775ED44A0E3CD0ULL, 
            0x4DB509BDF765C10AULL, 0xA9CFBBB6BFCF64D8ULL, 0x721021642D6389D6ULL, 0x16C166C6C7A1E79CULL, 
            0xB5121900691BB2DFULL, 0x2993925ED5ADE4B7ULL, 0x002F9130303300F0ULL, 0x85106CBDDA6A582AULL, 
            0x3D1C9D5546BD1FC3ULL, 0xAFA431F17B60CBB1ULL, 0x6FD986308BC46D54ULL, 0xCDAE06F7FEB2FE9AULL, 
            0x91EC0EE06952AA1FULL, 0x972C27D3398E898AULL, 0xD601E53567A8959DULL, 0xBB05A6AB50681F72ULL, 
            0x1FE03436D5E5827DULL, 0xF6684A4414B1F15DULL, 0xC62666D91E8374FCULL, 0x6F82199793CAEBE8ULL, 
            0x0BE19C7E19E7BAEEULL, 0x824E60BAF645DBCFULL, 0xB49B075BFB70DEC2ULL, 0x3482C44C1A1B9372ULL
        },
        {
            0x6FECFBE381D7022EULL, 0xEBAE1BFFF939DDA2ULL, 0xC015062E7E9D4B7AULL, 0x333FF7341E551412ULL, 
            0x74B1531C905437E6ULL, 0xDEDF5F2470A7CB6FULL, 0x33913AD62CD99D19ULL, 0x5C0DD0F6D0890268ULL, 
            0x958BFC924BF3D9CFULL, 0x13A2CF0490795834ULL, 0x1FC11C56AD9E0C18ULL, 0x9FBA2911B9218999ULL, 
            0x3047DC7020F0B42FULL, 0xF3101BD632F9E107ULL, 0x368103665465A065ULL, 0x3DB776093F379F92ULL, 
            0xD16EA7795645C0B1ULL, 0x08D5F639339855A9ULL, 0x8F2D43F12F988597ULL, 0x9426B1E865181979ULL, 
            0x4E36C9AECB68411BULL, 0x1C7F31EF5767E47EULL, 0xB1390DB0CCBDA100ULL, 0x73F29AFE2A5998CBULL, 
            0xC69D7678405E758FULL, 0xFAFFE6108070F2D1ULL, 0x43DA41F6622F11ECULL, 0xF624A276940D328EULL, 
            0x6473680CA68EBB44ULL, 0xA49ECC5AB1674AB0ULL, 0x4A47E96A6C03FAE7ULL, 0x7C019DC1E5B4EEA7ULL
        }
    },
    {
        {
            0x235AAAE43F98CC5FULL, 0x27FD44E456F35BCCULL, 0x0F202DBE50CA2D43ULL, 0x3AFA439CA29F6FACULL, 
            0x70C6A9D583F9B117ULL, 0xA70722D7D61B972DULL, 0xA73F91F13C8CCFF3ULL, 0xF1723C287BF24735ULL, 
            0xAD7B7BDD5A08046AULL, 0x8C51A9D568BECEA3ULL, 0x820A67755B83CC92ULL, 0xBBC1C21DB888A20DULL, 
            0x6C5A1C89C433082EULL, 0x34823D1D9154FF0DULL, 0x512404B8D546C355ULL, 0x4770FFEA5F7134EAULL, 
            0x2D7D0A944E28727AULL, 0x4AA7E145F786185BULL, 0x72B98BA90C6817E7ULL, 0x35C9A7B9AF8DBFACULL, 
            0xFCAF0028261017D4ULL, 0x7EF83F8703B70851ULL, 0xDD8245D880273284ULL, 0xE563B9D363083080ULL, 
            0xCD82B71550F3DBFAULL, 0x190985D13368FAA1ULL, 0x5A6A7C977D7BBCCDULL, 0x5C4E7AF39137A655ULL, 
            0x7D3CA58562A0D8A6ULL, 0x71D40A67FA267205ULL, 0x4B83A310182864E8ULL, 0x024B71ADE719676DULL
        },
        {
            0x26DBC2C1F3F98E04ULL, 0x74BB24488A7BEF71ULL, 0x09469A16E353250FULL, 0x8F1A944ADF0F6472ULL, 
            0xEFFB1D873412AAF3ULL, 0x663DEF6643D6F110ULL, 0x6C74BD12B7D717C2ULL, 0x851799413B445E2EULL, 
            0x3730B00E4D5EE9A2ULL, 0x3A2CCAF453F013DCULL, 0xCA9ADAFEF7FB2FBDULL, 0x3AE53B8D5B9E8E80ULL, 
            0x155B4A0C958E43F2ULL, 0x36DADA63AF124D64ULL, 0x77EB150E4BA23BB1ULL, 0x0848F99C38730A5DULL, 
            0x1AB7DFE33BDB6302ULL, 0x29513EFD2940F75AULL, 0xD78EC62F99FC5EF2ULL, 0x026E38E73AB664ACULL, 
            0x3CC472EF392599EDULL, 0xBE176FE4C9D9D6BDULL, 0x100FB4427DA2B7CFULL, 0x9683CAB48D60869AULL, 
            0xFFF21C28408D5CC4ULL, 0x7B2A9B7648D23E7EULL, 0x472314BCFD13746DULL, 0x7B8A377D78323DFBULL, 
            0x51EDDB5655FA52F4ULL, 0x5D123CD40147EE9AULL, 0x60BB669836A762D5ULL, 0x81BB15D721242E55ULL
        },
        {
            0x49893A7FC7A4A0D1ULL, 0x6BCAF4F924E30BECULL, 0x968C841F314B7B9BULL, 0x329A42E12EA31F0EULL, 
            0x319BB7EE935E6E6BULL, 0x3DBA86BA952C303AULL, 0x9C53CE6A7CB94936ULL, 0x8F3F00BC65A741D5ULL, 
            0x9B8EA47D843198C1ULL, 0x01FE04CC43C3D7B0ULL, 0x3ED977F9914F27B4ULL, 0x718B011EB01F512AULL, 
            0xDA7BD5BCC4FF13FAULL, 0x86F8AB34E83F9EBEULL, 0x1ECC80E0C9B531CEULL, 0xE504137D0892D1B6ULL, 
            0x52098CB31EC8B6B8ULL, 0xBA8A38EFE55205F1ULL, 0xB92475AFEC5E991CULL, 0x817B15CD86541052ULL, 
            0xF52A9F2FB58C57F0ULL, 0x1FA563E08AFCAB8CULL, 0x47F9E24986E285B8ULL, 0x8FB3887C2CB9682EULL, 
            0x9A6802FF0E185B4EULL, 0x56F87F20DC5BF702ULL, 0xD4360891DF1E15FDULL, 0x6AE8CF957D883972ULL, 
            0x0C2BAA92E1BB8FC9ULL, 0x4FF7AE9904D7F8C2ULL, 0xE81F7DE65E5A14B1ULL, 0xE7BB3647AE2D63DFULL
        },
        {
            0xA55F112F403150CBULL, 0x4DD94AA63117B55BULL, 0x4618A169A23C0615ULL, 0x76ABD14BC42F9E0CULL, 
            0x64FA5F1A41A500C0ULL, 0x897AA631BC1BC318ULL, 0xB30028FC3F4F38FCULL, 0x92ECA4E6CE35E8DCULL, 
            0xBE7F89D3AC88D967ULL, 0x8BBDABC6D2CA567EULL, 0xBCDECA6A48169B6CULL, 0x67838D4400E4881AULL, 
            0x54563684C004EFC9ULL, 0xD59824A9C1906478ULL, 0x7C2169F512C3EE97ULL, 0x353D49088DCE8DDBULL, 
            0x9986BF92D14B11D9ULL, 0x3B98DC0CE7F0C700ULL, 0x926C7096DA5AACCAULL, 0x2FC8E14BEF7DB5E6ULL, 
            0xD6BBC42FA54965BBULL, 0xA3F85ACCA9FBC381ULL, 0x6BB07E8DEF4F39BAULL, 0x0E6F8355DE1125F3ULL, 
            0x84836A227FF90647ULL, 0x105A3F45B6E5369DULL, 0xE31F1AAA7808A4F0ULL, 0x66C436C44D5B66B4ULL, 
            0x8035E6A710F36D16ULL, 0xFE69E72B888CEACEULL, 0xB0E3CFACCCD9E597ULL, 0xFF6E1A5C47704D7AULL
        },
        {
            0xFD50DBDD2BB22270ULL, 0x4EE2BBC41064042EULL, 0x2BA5FB52055F30CAULL, 0x6D731715FA9AC1F1ULL, 
            0x6D946596993CFC13ULL, 0x4BF3DA7D3B32EA77ULL, 0x6224245E3CEE7681ULL, 0x4680E82A0175AE36ULL, 
            0xBB859866C0A8E8DBULL, 0xF277EF3005025C37ULL, 0x458DC4DBBC0A75A6ULL, 0x3663117554A80ACAULL, 
            0x2CD6252B478018C7ULL, 0x295CA7E6905DE1A1ULL, 0x3EF0B2B63AE58500ULL, 0x6723632D5552203BULL, 
            0x19C196C331E578A9ULL, 0x52CF88CE626C4F03ULL, 0x68FE46974FDBC39AULL, 0xC1DBB2372894F830ULL, 
            0x18B46C004FB8A6EBULL, 0x14A54C286A1F12D9ULL, 0x0FC7A5615876C881ULL, 0xF2AC5BD153D94F25ULL, 
            0x2B84C9DAB243FB25ULL, 0xA47F2838F6F617B6ULL, 0xC39846B32FBD46FDULL, 0xCE30FCC0D5757632ULL, 
            0xEA23E4C459CAF4C9ULL, 0x76C0F4B5E5811EB3ULL, 0xE89C8AF4142EA18FULL, 0xAD694E565CD0334FULL
        },
        {
            0x58EF59E2CD524F1AULL, 0xE416EE15B72FEAD8ULL, 0x03855D85FCEDD30AULL, 0x8387FF2DFCA893FAULL, 
            0x4AF1346884FD0CD8ULL, 0x76ECDBC1058A620AULL, 0xBB5C9A0A813F7B9EULL, 0x9E99B1FB6A5B4AC3ULL, 
            0xF7C8028006855DC4ULL, 0x47DBC1E152DC1A95ULL, 0xC93FFCE044C4A13CULL, 0x2D653F4A8728051DULL, 
            0xF43467B6358C8498ULL, 0xF91F05B6976B3260ULL, 0x7E8B734D520CC990ULL, 0x14800CD3431C7531ULL, 
            0x61CDD5B7FF13F038ULL, 0x16A1FB9AD940F059ULL, 0x1219680F5921FE95ULL, 0xCE6916F967753E53ULL, 
            0xC6DC2C3F8820BB4BULL, 0x54535282E2581E44ULL, 0xECC386EC0B952AB0ULL, 0x7C40F6412C81B63EULL, 
            0xF0F6558D4FF4F5B7ULL, 0x5E12CCC3945F6617ULL, 0xACF10ED65E728662ULL, 0x3490343EB1CCC668ULL, 
            0x88F1F4D8ECECF653ULL, 0x7FB902C92922E9FBULL, 0xB211F0307B14480EULL, 0x689E26AD85F4C594ULL
        }
    },
    {
        {
            0xEAB93759DAF24806ULL, 0x5AC4244CC8C2F853ULL, 0xC0B5028FC4CFE9EFULL, 0xA07BCBBDD9877C1CULL, 
            0x2CA79375EEE8AF05ULL, 0x0A39D53F16330658ULL, 0x937FAED0F155F1F7ULL, 0xD93C201955BA7A28ULL, 
            0x7346BC1608E1FC3EULL, 0xBEB619C2376D2886ULL, 0x3CCB3512B8F6B193ULL, 0x2B4C9F72A0F7ECC0ULL, 
            0xFA7F87391ACC1E5AULL, 0xEF95156DC8C505D6ULL, 0x88BCECFD2B70B295ULL, 0x3BAFE79BACACB9E0ULL, 
            0x3A1980B33728CE48ULL, 0xE4DB448A5F2C2A7AULL, 0xC530D8B0CB5333E5ULL, 0x5EBB53D7B697CD9CULL, 
            0x80A8D69F6EE32D5DULL, 0x253105D3A83FDBDBULL, 0x89CBC09CB4951DB0ULL, 0x847FA5D0A21DA49CULL, 
            0x510746E48BE6BA19ULL, 0xDF5140361347F49EULL, 0xA963809001DCB40FULL, 0x554095277C1EFD49ULL, 
            0x44F53E7BEBFDF36FULL, 0x4EBCCA7C814A2FDDULL, 0x48457FA749927C23ULL, 0xEC35EEF5310BF688ULL
        },
        {
            0x53650FCA61569883ULL, 0xC60190B58EB469FFULL, 0xA310E40D03C1DC71ULL, 0x13B44FF5C930DF38ULL, 
            0xE47B1D2B90B7BBDFULL, 0x52C58EAF1FC06A09ULL, 0xDBD2F7DFA984C763ULL, 0x2A4AC42D4B82599DULL, 
            0xD457361880D20965ULL, 0xD82474F53A7376C0ULL, 0x6547A60944EED9C0ULL, 0xEEF3F513141414A2ULL, 
            0x7DB1C7F630739B28ULL, 0xF01AE9E539745FADULL, 0xF8F86332C6C3E536ULL, 0x3033B1764C7F35DCULL, 
            0xA057A1A9F7331541ULL, 0xD68B7C831AF76831ULL, 0x7F5DF8914C28301CULL, 0x2E178CEDE3F673FFULL, 
            0xC31E6AF69376F5B0ULL, 0xF137D729BF8FE213ULL, 0xF81ED4A5958E3968ULL, 0xB80CF012EC7A7644ULL, 
            0x4A394C9E17E4B694ULL, 0x32570D118A9606A6ULL, 0x023A2EC1D3A09391ULL, 0xF41034BC676D29AAULL, 
            0x6CC4D6334DCABDBFULL, 0x81CA65CFC3C5116DULL, 0x12A9DD84FA8B05C8ULL, 0x2B0D5E07D4A57F48ULL
        },
        {
            0x6C49D625BB32022BULL, 0x2D0AA74692555C34ULL, 0xF2D436056D86FDD0ULL, 0x093F08780C3696DAULL, 
            0xCA0780EAA84CDC6EULL, 0xEF038ED1B10C5AE5ULL, 0xF7D9C417112A3549ULL, 0x45C124F84185F707ULL, 
            0xECE58FF60E351964ULL, 0x772296FE48B0B5F5ULL, 0x2106B2FE0EC4F934ULL, 0x7269CDFA59A4C9EAULL, 
            0x38FE293C9E76AFC6ULL, 0x3A47F4D4BD88B85DULL, 0xF00B5D33058D1AE5ULL, 0x5756497011F46D89ULL, 
            0x897E1CBB0304DDA0ULL, 0x3CC034AB73EFC045ULL, 0x9503ECFD86918A5BULL, 0x9C1D8CB4E8619764ULL, 
            0x599BD180FFA6ED3CULL, 0x53C6B700E5D40F61ULL, 0xFC65E701DE6CE41CULL, 0xFF10BDC5C1483B06ULL, 
            0xEE30C8EE7D710AF6ULL, 0xEAA1D26D659650A6ULL, 0xEDDF4A236D97B03FULL, 0xFC0FA7B189B71F9EULL, 
            0x2DE22EEC43A19C1DULL, 0x90C92E4F3DA96FA6ULL, 0x4786F8749CADAAB5ULL, 0x65464EE98ADDB65DULL
        },
        {
            0xD4FD39E168CF9F17ULL, 0x8A0B0841A47BB137ULL, 0x2EB05F0CCB1AB0CAULL, 0xF5F9E2E5DB9043D6ULL, 
            0x5C0FF4553BB22335ULL, 0x4D8C8D5DFFAAB4FCULL, 0x5809D9DBB9A2017DULL, 0xCDCA19CFD3757BCDULL, 
            0x28E40A02FFD5A692ULL, 0x838485BC801A6FDFULL, 0xD578BCC3C1BEF129ULL, 0x879B8406C3B9C7B1ULL, 
            0xD561D0BEA87C2724ULL, 0xBF2AE2B68900A69BULL, 0x4B1AE0F90263F3D2ULL, 0xE7236A226954E074ULL, 
            0x2325CC26CA63F52BULL, 0xCDD1F071A5C42FF4ULL, 0x04970673F420896CULL, 0x440C7F6735C88681ULL, 
            0xC7D91F5D5059E73BULL, 0xB57F3EB51441A037ULL, 0x57DD174106E430C9ULL, 0xB58D99DADD37BC21ULL, 
            0xA93DE68C900E0F75ULL, 0x993A3E65190A60F1ULL, 0x0293221182D48300ULL, 0x51BC99A669384D4CULL, 
            0xDB65E7963AD4FAE0ULL, 0x7BEA36847510C5F5ULL, 0xC23D9DB154B27523ULL, 0xA6C5D8FA678B3E67ULL
        },
        {
            0x7BC17F0CA520518AULL, 0x8A49599B84FB66C6ULL, 0xD146994FBB50A078ULL, 0x3F280FE7CA17E515ULL, 
            0x60DD90335677C74DULL, 0x0915C5B04DE43CCCULL, 0x1C202BE18E9F4D2DULL, 0x0B1053B66FA72CC2ULL, 
            0xB9A39F454573997AULL, 0xA8FDA90FBE21FBF5ULL, 0x56EA887F5F167357ULL, 0x44FF0881C1B8FD51ULL, 
            0x5A11E99385BAD392ULL, 0x62522FFC8BD522C0ULL, 0xEC1645D109B9514FULL, 0x0DC5D9E3B5DD3696ULL, 
            0x0AA60A166FE95BE5ULL, 0x80E8081740F23DE0ULL, 0x109AFC9F817ABDFCULL, 0x1CCB72E13248B1D4ULL, 
            0xE7E151FC3112094EULL, 0x18C569E23A95D376ULL, 0x2433713650701A78ULL, 0xC10E5E8287814CB7ULL, 
            0xA7230CDAF3FB2202ULL, 0xCA0453A78D4769DFULL, 0xCDA5E991A1CA4B64ULL, 0xDD598367E6F4453EULL, 
            0x0F205DAC8BD3049DULL, 0x13F6232697CCBC43ULL, 0xFC309D2893492E3AULL, 0x37EB314325BD276CULL
        },
        {
            0x4985DF580612D6EBULL, 0x1D71DAACD3650A82ULL, 0x53EB8F9D9D5CB0D0ULL, 0x56E8D08171B4873AULL, 
            0x733A98227E64A360ULL, 0x8EFA4E6E1D39006BULL, 0xFCF3DB9DB90BA812ULL, 0x13DF014E0EC24D86ULL, 
            0xB69DC2D4988678A5ULL, 0x33B44E04C95E1DF4ULL, 0x4D1529ECFD943143ULL, 0xD61091983B5B15F7ULL, 
            0x46D1818BBBCA63F3ULL, 0xFA28C50EAFC9A621ULL, 0xD0961C531B09B57EULL, 0x129B867492D65EF5ULL, 
            0x54E649514D0D51B7ULL, 0x42C31AEFA18990BDULL, 0x9B9E882FB836BAD0ULL, 0x496BDC0AF964BF1DULL, 
            0xEFA45A557B5E766AULL, 0x8717AB245C16EDD4ULL, 0xF9CA3FD4587D925FULL, 0x542910D74E8062A6ULL, 
            0x54E4A31F4F3827F4ULL, 0x99F35221B890D56CULL, 0xD3F27DDB83066FDCULL, 0x08378672AB3FFAABULL, 
            0x76237E5E51EAB7DDULL, 0xAD2EC4BE616E7D61ULL, 0x042D90FB382398BBULL, 0x76751F6A1D126B8BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseDConstants = {
    0x4B29B111C45907B7ULL,
    0x2FF958CA54B08E6AULL,
    0x2E466CE75B5D8F19ULL,
    0x4B29B111C45907B7ULL,
    0x2FF958CA54B08E6AULL,
    0x2E466CE75B5D8F19ULL,
    0x8E780F23FFB24FC6ULL,
    0x3846BE07231501DFULL,
    0x9A,
    0xD0,
    0xDF,
    0x98,
    0x88,
    0xAD,
    0xF9,
    0x6A
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseESalts = {
    {
        {
            0x6D4633ADEE0D331BULL, 0xA5EC3C45AB218F0EULL, 0xB79DFD76005EFEFEULL, 0x1CE9D7D97BC18F87ULL, 
            0x1735CECBCCFC1519ULL, 0xF0CB6ADB01DFF301ULL, 0x0C46957BC6865F99ULL, 0x4970CCAF6C6882DCULL, 
            0x56B0FC1901713A2EULL, 0xE8B9558E2F5DF31DULL, 0x77913994755896A5ULL, 0x07CAD0723A210A3AULL, 
            0x487895628ED2E804ULL, 0xAE14ECE08A2FC4ACULL, 0x332C2285CC84A2B6ULL, 0x8C350262D94E7AD4ULL, 
            0x7965449AF6AD8DA7ULL, 0x5FEF8D9F8B9D8C3AULL, 0xD6FF2B588C849C5EULL, 0x87204B0BED55063AULL, 
            0xA0021B98494F75E5ULL, 0xAC6DD87C415BB2FFULL, 0xABFC07A91D9D201CULL, 0x1AFC8FC4C69F24D9ULL, 
            0x901E24AF97727618ULL, 0xE0F240552FFE8B2DULL, 0x9A6EF15A96D8D030ULL, 0x4260642F68B6E45EULL, 
            0x989F5442D71862D2ULL, 0xA7B06C51B34CCE5EULL, 0x938BD183D011CD2CULL, 0x0F80CFBE7EA5D4CEULL
        },
        {
            0x134F902F2288FA79ULL, 0x362E1B2417413949ULL, 0xFEB692329B430B2EULL, 0xE7BB9C789F7D6CF0ULL, 
            0x69FC31A26EE14B46ULL, 0x6D82673263C0F1D3ULL, 0x03779B4343203153ULL, 0x232FA54AA84B6BCDULL, 
            0x0939645AC7081745ULL, 0xB7E85800823D2245ULL, 0x078B1CD85745FF59ULL, 0xFE4DE9E504E3192FULL, 
            0x7C148A53F30DEEBDULL, 0xD9B0BF44C9BB71B5ULL, 0x4E238921D4FA9CEAULL, 0x99190DD77B203B29ULL, 
            0x57B47DC8B8F6B35AULL, 0xD1C2975BB1C7C71BULL, 0x02D749FB6F729A20ULL, 0x7F1BA6C4A65AE9C4ULL, 
            0x7D1FCA9319A3D298ULL, 0x142D918BA5B584EEULL, 0xAD8A0DC40DD22681ULL, 0xB35CBB2824F13EA1ULL, 
            0xCCA09539BA16F33EULL, 0xEBF435A19205B21AULL, 0xC160023CDB998BC5ULL, 0x71B6C5D3E03DAEE7ULL, 
            0xBF403B1E37518A33ULL, 0xBE022FC844D89E14ULL, 0x2F970B3BDAABCCD1ULL, 0x11F61B2EBFC30575ULL
        },
        {
            0x8620455625ED4CACULL, 0x0E7205319687F163ULL, 0xABF4E9FD36105D32ULL, 0x08E8F1620F08E40FULL, 
            0xE678A12B46D54E5FULL, 0x4365CB7FA0161AABULL, 0x1321FDD2BAB9BC56ULL, 0x946F4212E540808AULL, 
            0x666C39FF9A6804E9ULL, 0x780B7C753681AFFBULL, 0x62219C37DB4F472BULL, 0xE7AC11CF6A064D5FULL, 
            0x29E7F251EB468CBDULL, 0xE6C4A0C011CBF62CULL, 0xE4B3F5358C1CDDA7ULL, 0x10533A4F9BA96369ULL, 
            0xBB0F24F08A9A4C72ULL, 0xC1CAD8DA622B30FEULL, 0x13FDBDF9AD0BDB06ULL, 0xFF2ED6EF9602C4A3ULL, 
            0x7A513A31F40CE830ULL, 0x7AFE6E8935648015ULL, 0xEA89548E14D00834ULL, 0x41DAB3C76ABA609BULL, 
            0x59300174474547BBULL, 0xD8506DB57C2D4ECCULL, 0xCC8A2C4C86B7F014ULL, 0x73A2EC29A0EECCFAULL, 
            0xF762C2B079370F08ULL, 0xBC600788DC7206ABULL, 0x5DD745665F130D2BULL, 0x5C22D6797B6B9E52ULL
        },
        {
            0x1E96F53AB74640B2ULL, 0xE699EE551BBACC47ULL, 0x213F0029E33A2035ULL, 0xD860E49621D38A49ULL, 
            0x2E7DA4E444E523D6ULL, 0xEEB8727CBCF30B0EULL, 0xFDEE2CE9262AABB0ULL, 0x8FF83B3EDF3392B4ULL, 
            0x347F6B49BBFBEB7CULL, 0x87218E722FFE8C63ULL, 0x4A006CC7588BD09EULL, 0x6DA058E3C937DC68ULL, 
            0x78109EAFDADD7A76ULL, 0xA11494460CFFB25CULL, 0xA28DFA5D727EE5C0ULL, 0x245988C7D7E8149FULL, 
            0x7D284190E1F61C3DULL, 0xA562FAFED47A9DB4ULL, 0x6FB5EE8194CA02E1ULL, 0x495BC5E0973DDDE4ULL, 
            0x07F575B1A6CE8944ULL, 0x11D89596E156AA7BULL, 0x2C99FB6383FBC6E9ULL, 0x53EBDB7D25CBDBAFULL, 
            0x819C65291AF5F55CULL, 0x55E633D6F39AD7C4ULL, 0x6440A6C3E9A956ABULL, 0x0FB2215D4C0C4CBEULL, 
            0x537C8009E8B51E39ULL, 0xAE5323F50208DC37ULL, 0xEC764E537B39EC78ULL, 0x58BA500A828668E2ULL
        },
        {
            0x3F1668DFCC9E86E7ULL, 0xE1D3523937580BAFULL, 0x54E0B4DE7985DB1CULL, 0x7ABBFDB41EB95E0EULL, 
            0x610C4FE5DA004983ULL, 0x9B236E5BBDC6B512ULL, 0x9DD94AFABD9A0F8EULL, 0x30FACF22383EF884ULL, 
            0x63119782F721D432ULL, 0x6F5B32EBD9AE47F8ULL, 0x2D0942557F17B341ULL, 0x9E690D0C6E0B26E7ULL, 
            0xA3F48493AA69141EULL, 0x5E4DDEF3BA8B65C9ULL, 0xF6D4D94B43924DE1ULL, 0xD32C5696606C822BULL, 
            0xB30D5CA002F8CA2CULL, 0x56FE6702454D11E5ULL, 0x6B1C682FC47DB609ULL, 0x5CEF84DC7678DC4AULL, 
            0x8C989DA9A8A0ECF0ULL, 0x1D22DC2F1D275D4DULL, 0x0C65CE3D29AB19FCULL, 0xBDFE16032400706AULL, 
            0xD16332C8AC958FD6ULL, 0x8359F7EF62C287ABULL, 0xF863D069E715F3C0ULL, 0x24C21AF5C3A29193ULL, 
            0x3C099B2D12259A71ULL, 0xB54FA303D2EB5A56ULL, 0x19CF02024F2C4BCBULL, 0x0060168D95D162F0ULL
        },
        {
            0x46393D4868049B8EULL, 0x7C1F400B26FF9AF0ULL, 0x9D1EDA0F0EC19620ULL, 0x3506944101ECA78BULL, 
            0xF25E5E4C3B34998FULL, 0xD3160AAF93C5DD10ULL, 0x5DD98B0267B5B584ULL, 0xC4D861B9C8A9CA80ULL, 
            0x2D7C233590FA2622ULL, 0xCFE030FE2951DC62ULL, 0x3F49C4165F4E3729ULL, 0x852ABAC8925939DDULL, 
            0x1F72972159253718ULL, 0xE94DF94B93D8168EULL, 0xE0C0CBCDCFC67566ULL, 0x59011341CABD3198ULL, 
            0xF727BD10E21A23CAULL, 0x369612FE517CD85EULL, 0x8FE07BD525F09E92ULL, 0xB0D7D860ECFE2C4FULL, 
            0x6C3796E28BD930FBULL, 0x9320ED65C1C7ACEBULL, 0xFC595C76BAC02668ULL, 0x709DFCADBDDBA0B1ULL, 
            0x95C85BD3385B1526ULL, 0x02B9A5ABDB741C91ULL, 0xFB7AB5E291296E47ULL, 0x219DDD5A86D2C263ULL, 
            0x71743C0B991756F2ULL, 0x0776ABB3E7DAFAC4ULL, 0x9CF8E64EDC95F6A3ULL, 0x5A9CDC14F38E0438ULL
        }
    },
    {
        {
            0xD0C19E6F3E523562ULL, 0x3018E45193848331ULL, 0x41128BB5B224AA52ULL, 0x97059610118D28F6ULL, 
            0xB4263EB94EEAB846ULL, 0xB9DF3B18F48DFECBULL, 0xB7D8C53DE916615FULL, 0x1A8036EB0000035DULL, 
            0x3997A8025BF6AE9EULL, 0x7E596AC9982DFD7CULL, 0x099B851262BCB5D6ULL, 0x0185196D824C8B71ULL, 
            0x369B1774024F80FCULL, 0x396DA20EF53C0650ULL, 0x9046F0B12EFDE68CULL, 0xAC0E61835EF03FDCULL, 
            0x2C3C94F896DAE90FULL, 0x9BBB3080AD9463C1ULL, 0x116DF557162AB0A2ULL, 0xC10C5474BE25A4EBULL, 
            0x992FEE00BE034794ULL, 0x3E13167B10E26B1EULL, 0xB122AC0194E27179ULL, 0x8F16078DB72132D1ULL, 
            0xE041E6CA18F69D8BULL, 0x96D261D394316787ULL, 0x2C503D755FE60AA6ULL, 0xBA0BD99EE92A1C8BULL, 
            0x78D29CF5258AFE92ULL, 0xA05A19EC10C8D106ULL, 0x9F83672EB31EEA72ULL, 0xFD99C3859CB849AAULL
        },
        {
            0xC488FC0A5E658A0DULL, 0x9921AF5B83305C91ULL, 0xE0E6EE1FF4864A98ULL, 0xBB84D1B0826EDC68ULL, 
            0xB192A9826CF553F1ULL, 0xCB605EB95387E07FULL, 0x15DC237C593F5668ULL, 0xF4BD224BFC1A8C6BULL, 
            0xE6BEBDF9EF828E53ULL, 0x76F52BBEEE46A5CAULL, 0x97B0384B0802C589ULL, 0x3FC6F538BFD07470ULL, 
            0xFB100AC3BF681BCFULL, 0x3CE2805286C7A222ULL, 0x2C194978D0F4C1EBULL, 0x4569B4A5D4AF1D9CULL, 
            0x01A2C83562FB5911ULL, 0x89178437452CD68EULL, 0xFDC7B1805078EA0DULL, 0x5C4E7911840C44BBULL, 
            0xE1DF4D7C1AE9D3FFULL, 0xA1DE1006C6DFECCCULL, 0x26BE93CB3F4F8FF3ULL, 0x7D862FC10898BB63ULL, 
            0x6DE35316E9467EDCULL, 0x25B15AB8C9D2F9B2ULL, 0xF489FBAED650EB77ULL, 0x94171196B835BF4FULL, 
            0x53F5FFFF08C5DF23ULL, 0xCABE95A016E8AAE6ULL, 0xB380DA5911CD3803ULL, 0xD0585A3408C9E046ULL
        },
        {
            0x49F635E3ACB7B885ULL, 0x288B9B128634375EULL, 0xCCBFD6CC0496C6D2ULL, 0xC9FB6340BE70CB35ULL, 
            0x6D1281C5906EEA58ULL, 0x939EDF848A8039A7ULL, 0x2D3BC8DF399EBB48ULL, 0x5FE4BCDE8E26E262ULL, 
            0x4371C7DA79380FF2ULL, 0x65014CAE5C228B81ULL, 0x085E59FEF44C0C3BULL, 0xA92D0D51587445DEULL, 
            0x5EFAB33E272C15A2ULL, 0xD562BA52AD26A0D2ULL, 0x562E2772225B34EDULL, 0x250DA98CB63CAFF1ULL, 
            0x4E859A852922A84DULL, 0x0631046136412816ULL, 0x8599D2B50A8D5814ULL, 0x460DA17C32E64A63ULL, 
            0x623BAE1EF3C9E683ULL, 0x7FD7014D2EEDE395ULL, 0xFF41511F46F0B7F4ULL, 0xDBD4AB9B77D2B640ULL, 
            0x7860D662BE6AD133ULL, 0xF17537D2B4EA531CULL, 0x51EDCDFE2A0CB64DULL, 0xB74355F7605DC013ULL, 
            0x9D8E701FF7DDDC0FULL, 0x694611500DF0C739ULL, 0x357B856DAEAA5EF0ULL, 0x357E647F73D6CDDBULL
        },
        {
            0xEFF896ED0DFC931DULL, 0xE5F9815E934A0CFCULL, 0xAEAED35D9B30442FULL, 0x1A58F5F6B9697494ULL, 
            0xB04905EC605CA9A5ULL, 0x87929C0276B1049DULL, 0x9D231665BE741E08ULL, 0xAAD566C9683E3F30ULL, 
            0x8745CE820C6EB968ULL, 0xEB800026E3ED5B27ULL, 0x7E0CB4FA9F88F352ULL, 0x6DFDCAE9F4EF9DB6ULL, 
            0x5535745B3AC14BDDULL, 0x4F0F0FF07442BB08ULL, 0x1CB5A00124B09C03ULL, 0x7AB79C2B3B30E57BULL, 
            0x728FB96F64D6A92EULL, 0xFE21295B57BF1853ULL, 0x4313A3182F55E23FULL, 0x977ACBE4688480C5ULL, 
            0xA96156320344EA04ULL, 0x58463532EC48C03FULL, 0xB83261BA9E61A10EULL, 0xFF57A350CF5FF2B9ULL, 
            0xC0369DC1CBA5F807ULL, 0x7BCA8B09E1AC6F84ULL, 0xE11E60AAEB14CCACULL, 0x6F6BBC599530C620ULL, 
            0x61ABD3263504AB8EULL, 0x2CD2737A3476D944ULL, 0x8847252202969A17ULL, 0x3C4B677E72C0ECFDULL
        },
        {
            0xEDB08FF6E954E87DULL, 0x26CA22A0959E17D3ULL, 0xAE1D74197FB1DCC3ULL, 0x1B1AFFFA3488C393ULL, 
            0xEA38658EB92405FBULL, 0x9F5E320AC75EAF82ULL, 0xCFDAC388D3E46CD0ULL, 0x67C70DAF22E337A8ULL, 
            0x9C6D4C6A33CEE6CEULL, 0x7F5A69F3A13244B4ULL, 0x04F2771F06CD4CCBULL, 0x8FA1A250646F8FAEULL, 
            0x331F4CA2E29DBC58ULL, 0x29924503199A6D25ULL, 0xCBC841016EDB186AULL, 0x76698F4EC8AC8CAAULL, 
            0x478B74C33F667302ULL, 0xCB4638A90DB6BB60ULL, 0x4E417AA8942CCDD4ULL, 0x73EA6C906C26AD75ULL, 
            0xA3E1C77115E8E681ULL, 0x39BEE557A558D636ULL, 0x90DB5A1A654FF300ULL, 0x33E22F62027B4772ULL, 
            0x51A6A2FEAC1E2278ULL, 0x76F15AC327A245CEULL, 0xADA22BDCC361138BULL, 0x0A15745F89646186ULL, 
            0xEA75C900C1744D43ULL, 0x53936EFF89044C5AULL, 0x58CA1F0B204F4A12ULL, 0x7C2DE2A9928F6FE1ULL
        },
        {
            0x68BF34D7A96572BDULL, 0x17D7399DB67F3B87ULL, 0x6D0D48FC4D89F181ULL, 0x0D19AC25C74DF5C0ULL, 
            0xE8493372BBA662EBULL, 0x8D9430E773C42EE8ULL, 0xA540FE67ABAE20B9ULL, 0xD2F7B2BFA7815BC1ULL, 
            0x58D29DD318D4F989ULL, 0x5678593EED171D08ULL, 0x9218CD14263DCDA6ULL, 0xE1B7D77D108270D8ULL, 
            0x7E80B0E47346199AULL, 0x112B050F02BD0D96ULL, 0x2910D1B33BB7589BULL, 0x09C12161C2C52F20ULL, 
            0x325E3E5A98EC631EULL, 0x643897C20D40AEF8ULL, 0x84CF4F0731EE49BEULL, 0x8F21C2CDE23CE981ULL, 
            0x34332DDC5531CA04ULL, 0x30777524CE21FB88ULL, 0x517CA569FF34C5ABULL, 0x85995D4A07928347ULL, 
            0xA1EC43ECBD45E2E3ULL, 0x25B5991A2299094BULL, 0x66DA81F5B6214F9CULL, 0x0BEE29B76B2819A3ULL, 
            0xFB6C0B1318690363ULL, 0xBE94019036D50227ULL, 0xA64BCFE85ECD1991ULL, 0x5432D98535880DE3ULL
        }
    },
    {
        {
            0x37BFD221E4919E3AULL, 0xFE158BD657588514ULL, 0xAFA03DE3EFD2A780ULL, 0x99DA147A86DD4D7EULL, 
            0xD1A8AA9BE902625DULL, 0xB3BD06F850CB9768ULL, 0x77EA588B40BFCDC9ULL, 0xEC83D51044F84AB2ULL, 
            0x3CD685BAE6D8E2DFULL, 0xE0B4D711DCF07974ULL, 0xA973EE8418185FAFULL, 0x97DFAFC0378C2C18ULL, 
            0xF0D2B31389B60BFCULL, 0xEFA63D2B6317EBF4ULL, 0x1EE8072C9872D623ULL, 0xC077E81C907C79B1ULL, 
            0x44E592115195E662ULL, 0xD2B3341BA02C827BULL, 0x4498C06A4D1CFBA7ULL, 0x1453BC4B8CE27B93ULL, 
            0x794D146E04C63690ULL, 0x16A4DAD7E66270CAULL, 0xE7E0980BB73F2975ULL, 0xC736F37B88E3AA0EULL, 
            0x4B5F9AAA5C4B6FADULL, 0xF951A9F80867592BULL, 0xC6D7DEAAAB356F06ULL, 0xFBB6FFDBB66C560EULL, 
            0x2DB9A58B53B28439ULL, 0x553639E85D87186EULL, 0x16629661F41F702EULL, 0x0C82C26567AE8316ULL
        },
        {
            0xAA5808D454C20DDEULL, 0x29C2D69B929E604AULL, 0x1D59CE45BD49270BULL, 0x916EC715CDAD1613ULL, 
            0x3B7FEE94B5A6B5E2ULL, 0x99456B9A7E2630D5ULL, 0xB188EB511571DF11ULL, 0xB1B87D60880BFFDCULL, 
            0x7C8E596CC16FF6B1ULL, 0xD375CD2C248618E8ULL, 0xD24DBBF6CD717B6CULL, 0x195004D2550153C4ULL, 
            0xBB5DF0CE92CF2FEEULL, 0xF169CE5573EB2DB5ULL, 0x74F7B80ABC953749ULL, 0x4F61B98D00BD7E9AULL, 
            0xE18D87E586B3BF3AULL, 0xB33477DE3B527AF3ULL, 0xB234DE908DF8B682ULL, 0xCA41A5F0CE735FD2ULL, 
            0xB1E98D3C9D55C8C1ULL, 0x8EB5D04EC19EAE58ULL, 0x0DFE49350329CD51ULL, 0xFC3DA6DB3A587055ULL, 
            0x41DB82A0AEFF9A01ULL, 0xF4C8405E744C5414ULL, 0x266AA1534EB96F46ULL, 0x0BE17B174FC496A0ULL, 
            0xAD630B855D28914CULL, 0x8F1D67FC31210E1AULL, 0xB36D10E203917ECCULL, 0xE429733AB6A740A4ULL
        },
        {
            0xB80A2B8783498C0AULL, 0x892B1F677183A239ULL, 0x684B0C789E779193ULL, 0x3A92BECDEB051BD4ULL, 
            0x02ADAC24CA9AEBF2ULL, 0x400AA5CF8322C9A1ULL, 0xE8466194F70ACEE4ULL, 0xC1C81619926A7553ULL, 
            0x25D337E26264952AULL, 0xC8419A0129D61AA1ULL, 0xE0B30D0E66FA78F1ULL, 0xB0960A786B4D20C5ULL, 
            0x03B1F8F8E49B2AAEULL, 0x8D07540127A88764ULL, 0x9132EF23E4F524FFULL, 0x7EC2CAAF1441D4F8ULL, 
            0x6D83694FDD87ADE1ULL, 0x60FB7EF74E39C6E5ULL, 0x62E0F9860040A514ULL, 0x58D2454F36D57136ULL, 
            0xE45DE2BA40F4CA06ULL, 0x8F4E10A04F26C913ULL, 0x9FCDD040AAB46981ULL, 0xCCD5C09CEEE9BE0DULL, 
            0xED372A3C30D953A8ULL, 0xD39141BE628C8271ULL, 0xBD89AD623765F1E7ULL, 0xA82664B1369316F9ULL, 
            0xA331855A59065328ULL, 0x702B2E7C7B232EF9ULL, 0xF691CD7D0ED8FDE7ULL, 0x96324BF753309741ULL
        },
        {
            0x8A0D674D5E1542F7ULL, 0x0AA52F49BC742C76ULL, 0xCDBBFC6075149B0FULL, 0x5C252507C922BA54ULL, 
            0xCCBF04CB73310D76ULL, 0x6D4FA92D1E8A1966ULL, 0x605F17F6F6A41317ULL, 0xAAFE53412BFA2EBAULL, 
            0x6AC66D4038A82AE6ULL, 0x641BD3F6806F9F94ULL, 0xC87854C8C6405494ULL, 0x08C38E5657D5B78EULL, 
            0x046D07C9DE09DB58ULL, 0xA8E754F17F0B5CB0ULL, 0x7BD141FF01CBBE03ULL, 0xD5A4D400ED782650ULL, 
            0x622561B83F020AB8ULL, 0x99C7E1034CF801C9ULL, 0x61781B4EAA36FA3CULL, 0xFBFEBA4E7EA46BA4ULL, 
            0x5C0ACC7596C14ABEULL, 0xF0EF8A5693D4582EULL, 0x23B629B9C5F6CDCBULL, 0xA13A79EDACA841DAULL, 
            0xED07A763D0E45C6AULL, 0xB778C262B3EDC827ULL, 0xBBB3D0873E5E6017ULL, 0xAB694C90FAE6D37AULL, 
            0x3C7E868D0A8EF759ULL, 0x1C6846E656C032C8ULL, 0xD0A964157C93887DULL, 0x63F2CE8C7DBFAAA7ULL
        },
        {
            0x65656ABEE1D8E11DULL, 0xFDD0B9DF28919D90ULL, 0xD7034D9BCBD70693ULL, 0xDF1B01DCC2BCCE98ULL, 
            0x4F5302768318EBF8ULL, 0xA426C1257D4D9650ULL, 0x322F1AA63F8313BFULL, 0x646A783E8D9352B6ULL, 
            0x7E6F4DE71711A7F2ULL, 0x1ACCCCFB60C23D75ULL, 0x300360ED033DA9B4ULL, 0xB77D62B74D75344BULL, 
            0x26202A6EE88B791FULL, 0xA22E15982523EE13ULL, 0xF443854D2AC7160EULL, 0x1E9843E70867DFAEULL, 
            0x38DB9AA4477EA401ULL, 0xFFBD1D379551ED3BULL, 0x0207022255958C72ULL, 0x6E8C1497A36EB961ULL, 
            0xEF0B76854D09F76EULL, 0xFEFDEE558173F3EEULL, 0x3A8B29BFC7CA483AULL, 0xAAAC8755E0B1BC00ULL, 
            0xED6D8EB279DD80E4ULL, 0xCB1214D946BB43D5ULL, 0xCE2E6717C4FF67BDULL, 0x6122A78773A953E6ULL, 
            0x00F6066AD0277A45ULL, 0x31C22589BBB0A0FAULL, 0xFD34102851641327ULL, 0x1203F60D1404C007ULL
        },
        {
            0x81AEA3DE5EEBCB78ULL, 0xC4C279504E608A89ULL, 0x794B5A4A67596CA4ULL, 0xE74EF6AA79B29505ULL, 
            0x031A591CD3BA395EULL, 0x0079EA52404C9A6DULL, 0x67A08261F4380684ULL, 0x4C9F70DA65A7CA71ULL, 
            0x7261EA29D1C5CBF2ULL, 0x804764A989A622BFULL, 0x10C6D421944309CCULL, 0xFB44C929B00907F9ULL, 
            0xDF008F42EE7CC861ULL, 0x465AA076757FFA89ULL, 0x3B32030F561E2D9DULL, 0x5B554A22D46925ABULL, 
            0x1771529D3238E731ULL, 0xC5B8DE6A0316FDA6ULL, 0x754651E6E3DE1070ULL, 0xFE116D681CB6FAF9ULL, 
            0x1221A497D39DBCA4ULL, 0x2EE577E1A8FE541BULL, 0x910E4964F7EE0B07ULL, 0xF411E3C4DD693E30ULL, 
            0x55C26B365686C71DULL, 0xAA2FA465D0773F2CULL, 0xED5F7CBBC15A0B10ULL, 0x2E77C37200EFFC8EULL, 
            0x9F9674D10E63F864ULL, 0xA2576C3B65D75E04ULL, 0x1F82E122A94629ECULL, 0x1BDCE7E068793801ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseEConstants = {
    0xB5746DDD5BF06350ULL,
    0xB036EAAFB14EA748ULL,
    0xEBF3B73EAD066F6AULL,
    0xB5746DDD5BF06350ULL,
    0xB036EAAFB14EA748ULL,
    0xEBF3B73EAD066F6AULL,
    0x56F756F9D8F0FDC1ULL,
    0x9CF6AEBBB6D2F2F5ULL,
    0x60,
    0xC4,
    0xE2,
    0x2C,
    0xF4,
    0x5B,
    0x8E,
    0x7E
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseFSalts = {
    {
        {
            0xC6696F511804F063ULL, 0xFBC58885186BA31EULL, 0x2E6DAABAA960DFBDULL, 0xC8516B546DBB45DBULL, 
            0xDA66A1184787CDEBULL, 0xCF0D7A79C9D78953ULL, 0x6D0891E928908FF9ULL, 0x7B2F80DC7ADCB29AULL, 
            0x3225A4E098144434ULL, 0x4A3353EEB0F7FD24ULL, 0xFE915F3A7B4CD760ULL, 0xD327444F9BAD68E5ULL, 
            0xCAD814BD8254663DULL, 0x25AD23665DDAF35CULL, 0xD1B2D73449AB9E7AULL, 0x183BB45FFF7A0039ULL, 
            0xB4B7C5F58DC96F6EULL, 0x11927CB1CBBC9134ULL, 0xED292C921E6E936BULL, 0xCF27F84EF9CC4195ULL, 
            0xE4F8B32BD6C0376EULL, 0x0C3BC4EA5A98A3E0ULL, 0x4154AE3C95A4B4E3ULL, 0x9891B75462CDF1D4ULL, 
            0x8348B31642F46682ULL, 0x50547A54CD89641FULL, 0x6A74F9235A2958C1ULL, 0x344D97AE6B6C6471ULL, 
            0xE509706A6B7E89B7ULL, 0xCB8A19275ECD6DE4ULL, 0xC1BB7CB2B4C5C6F6ULL, 0xFE46C15DB0E766FDULL
        },
        {
            0x88A96D5F37C00065ULL, 0x48156FC23EEA805AULL, 0xCE8A164AB49F0A0AULL, 0x02D92B491EC751CCULL, 
            0x5161855F59CCD346ULL, 0x447322E5B5A45ED8ULL, 0x37F45A4237B9033CULL, 0xA52B210FCFB69932ULL, 
            0x37D40B6A47827DA2ULL, 0xBD48527253003EF5ULL, 0x07B9D1F9F22EB3D5ULL, 0xCD7B93E320FE3DD7ULL, 
            0x7C9C4155668BBEB9ULL, 0x08813CA9A80AF92DULL, 0xE3C4C8FF6CE267AAULL, 0x94D452EE394DA567ULL, 
            0x28921E8BA8A169D4ULL, 0xA29BC35B4894FDD5ULL, 0xDDD99817ED285408ULL, 0x6B526E33DB17BDCEULL, 
            0x8A6F1FB50D81AFEEULL, 0x5AA17A416A78221CULL, 0xF9152AA2C045B2BAULL, 0x3170606786131892ULL, 
            0x2D5126209AC7A0E6ULL, 0xC422329B05134F59ULL, 0x5655AB692C5F34C5ULL, 0xC198BC188932F2E3ULL, 
            0x706D5259AB23B5DDULL, 0x2DCBC3EBFF490F25ULL, 0xD598D9423A6512A0ULL, 0x3BDAAF6B27231CBCULL
        },
        {
            0x4A1E98CCDCF3CA74ULL, 0xF25C82DC3473F022ULL, 0xF350318184CEF450ULL, 0xE849B5BFD1DB474CULL, 
            0xD750BC2E6F7274A2ULL, 0x18FFDA8E5B04AE58ULL, 0x80C25CF23A1285E1ULL, 0x663E63E32D97FC08ULL, 
            0xE3C7EF3A2CAD7FD8ULL, 0xC6F19E7F507DDE40ULL, 0xB80A0898EBA7F9C7ULL, 0x9A2438762C5E36F8ULL, 
            0xD6AD30E571D80CB2ULL, 0xB79260DC747B3503ULL, 0xEDB54ECC69585A63ULL, 0xF6BF64718F3F8E5EULL, 
            0x74042BD452C73075ULL, 0x199A4CAC426F1069ULL, 0x90DFE8FE9A93A396ULL, 0x6CEC4CA53665FA21ULL, 
            0x5E462C44AC6913E1ULL, 0xDCD4BD4A8E180672ULL, 0x67B5CD33FADCC2DEULL, 0x042DABD5F56A18A8ULL, 
            0x4FF94A74217CC451ULL, 0xDF794678D54DE5C9ULL, 0xD501E7962096ED19ULL, 0x082B1668025FB974ULL, 
            0x7471D0128F6BF0CEULL, 0xF151953EAC35D00EULL, 0x493DED443A285ADBULL, 0x4A4F1D20A26D832DULL
        },
        {
            0x29D92FEC776B4A67ULL, 0x66C70949263E3029ULL, 0xD3C26F065040BD33ULL, 0xEB02EC2BD04451DEULL, 
            0xEA807C40A15E18B0ULL, 0xAD6A8F525918301AULL, 0x940132C1762CA409ULL, 0xDF88163C4F6E3F32ULL, 
            0x8E463AEE0BF59C78ULL, 0xCBF82A05AE5F2CF4ULL, 0x26145ADEF17752F6ULL, 0x1DAB03A89CACF696ULL, 
            0x9D645B2818E5ACE0ULL, 0x257E9B5E4B026CB3ULL, 0xEB7E65297131764DULL, 0xFC5AF227669728F7ULL, 
            0x51322E3EB0ED2FAFULL, 0x270142C93D81FC2FULL, 0xD3D61531CF60CA5CULL, 0x7E0DF2A898B3818FULL, 
            0x7003D7C4350495FFULL, 0xFDFD468F800CDE7BULL, 0x71AC1A3C6F5C8028ULL, 0x8023B8630361E150ULL, 
            0xFB9CA8262C903CC6ULL, 0x0E530FF4507C0317ULL, 0x9B5F21576B640F5BULL, 0xE1C5AA9BF85EC1C1ULL, 
            0xDFE6C33975368A6AULL, 0xCABB6F7A639D4C06ULL, 0xBC1D2FA79A424497ULL, 0xE3B9C11DDBA2C574ULL
        },
        {
            0xBFE983CC9D292C3FULL, 0xA61C6A5918143584ULL, 0xC344C70B5DB3636EULL, 0x0643E200105AB3DDULL, 
            0x90F45F36938C06C3ULL, 0x465D28A930A147DFULL, 0xE3AC561A2E79A531ULL, 0x5ECB2DE61184EBE9ULL, 
            0x7613989C2EA33B08ULL, 0xE3DF2A88240A31E3ULL, 0x46AFED3155ED0B70ULL, 0xE9DD179B39783459ULL, 
            0xAEB8063213C03670ULL, 0x88EC990642A8CEDCULL, 0x76461EBBA04666C9ULL, 0xE6E8D47C71B0200EULL, 
            0xC25BEF3F6B192E01ULL, 0xF3D2DA011C4AD1D0ULL, 0x081D832E8131A3D6ULL, 0xDCC0F1170590C171ULL, 
            0x4ABF0B97788EE53CULL, 0x3052CF317E855586ULL, 0xBC5EE51FCC7CBD48ULL, 0x372791A2EF937409ULL, 
            0xDA55C15F75619CBEULL, 0x8816BC6A4B706D93ULL, 0xBC6F5C69EFE5671DULL, 0x745AF8AA1E5BDE0FULL, 
            0xB477702E71C8B217ULL, 0x1D02023B86217BB4ULL, 0xAC763A4A1A5FD6A5ULL, 0xDB96FBC73B4E0476ULL
        },
        {
            0xB3D08FB7F5DC78E6ULL, 0xFCB566F3FE605E43ULL, 0xD1BBA1E2931E7F83ULL, 0x14C9934BA49E2970ULL, 
            0x8A513494F3BEA73EULL, 0x317DBE5CB83F5E57ULL, 0x742C909E6130AACEULL, 0xAF2127F803D37D89ULL, 
            0x938B6342CBBD4443ULL, 0x02011CBF031B2441ULL, 0x088D830B39673AEAULL, 0x5D14C8B007D813F5ULL, 
            0x86902E2828921422ULL, 0xFBED3B67C820DDF6ULL, 0x6474DFC371DC1D6FULL, 0xA130FC6613A52752ULL, 
            0x12228B64AA4B4F23ULL, 0x3E7E93C78EF77893ULL, 0x0BA2317E61F5E37DULL, 0x57227B57851AAE03ULL, 
            0xC9FD21E7A29F7CC9ULL, 0x0C58C8663CEB9F57ULL, 0xC15CF5CC7EEC52E9ULL, 0xEA93B90B292A3E89ULL, 
            0x6DFC0C1FE522102CULL, 0x8137360EC5BAD7D0ULL, 0x9E0B90E3ECAA5BA0ULL, 0xC3985F2CE400AE45ULL, 
            0x00ED5D0802683802ULL, 0xAD896DFFF40E4130ULL, 0xAE67DB545D4BF0D6ULL, 0x712684F6ACD61F9EULL
        }
    },
    {
        {
            0x3A7A1B3DEF28B4C1ULL, 0x936C607BFB2FA957ULL, 0x99A2AEFC5E9775F2ULL, 0x4836951BBE382330ULL, 
            0x0529FC4EC4ECC0C2ULL, 0xE573F2128AECBC6EULL, 0xB7B61073D3C9C5DCULL, 0xCCABB63111ACDC08ULL, 
            0xAF1D56A9B0E228D3ULL, 0x2576BBD6B8BD536AULL, 0x51AF9B34FB2D39B1ULL, 0x669667F2DF4D3D71ULL, 
            0x58BF0B4A31A9AF7FULL, 0x7DB477AA86C3ABDCULL, 0xADD0CDC720AE718DULL, 0x8BF5BF87127B8D84ULL, 
            0x56C3D59AE157BCB8ULL, 0x649C63AFDA6561C7ULL, 0x1D07DA4B22AFDB2EULL, 0xEF5CBE0009A21734ULL, 
            0xE9B200576B134EFFULL, 0xA970B3E15FFABEDBULL, 0x7AF0F1C93595DA67ULL, 0xD839C523A29833B0ULL, 
            0x4058BAA0CD67746BULL, 0x3EF84A2BBD66C9F8ULL, 0x3F159ABCE0F85037ULL, 0x091E24CA4DDCEA6FULL, 
            0x0E5D9BC99C30D65FULL, 0x3AC66E07D85E314CULL, 0x3CFB1820C937EF92ULL, 0x0166BA770D4FEF9EULL
        },
        {
            0x6BB92F5A029107CCULL, 0x5C3D7D163BD45E6CULL, 0xB62B596142E0A82DULL, 0x7F51118E98AEA52DULL, 
            0x6A1AF9D667B2E097ULL, 0x2B40E3578B4A4A7CULL, 0xC58B04C545BE685FULL, 0x8CC02E22B2E00064ULL, 
            0x1132EB1182B559E8ULL, 0x6A0C9FD664252832ULL, 0x3D407A59DE4AD08EULL, 0x2E91E5A60C9A4610ULL, 
            0x00F3EDB4BF2E7E16ULL, 0xAD71C7B5FE564D41ULL, 0x4A72C4ADB7413542ULL, 0x6F670A2F154DA011ULL, 
            0xB9F987B047780217ULL, 0x97FE8B11841085C6ULL, 0xA94C10DF0364A11FULL, 0x95FC68D0662DD0A1ULL, 
            0x8C4E81ACF62BDC13ULL, 0x085EF22BAA6C2B82ULL, 0xAE8453744A0D51A6ULL, 0xA925EA0CB6C62F79ULL, 
            0xBA355F960E9C845EULL, 0xFC90BEA4424E3341ULL, 0x226E82F081D82F67ULL, 0xDED5557FF830119CULL, 
            0x79ECC6D34AC5BEEBULL, 0x787B1CAF3D0F7F81ULL, 0xDF415E616B842DABULL, 0x8A7107C4773FDC3AULL
        },
        {
            0x0923EA2DB499BAD2ULL, 0xE801EBC159823C45ULL, 0x75343A7FE163E83BULL, 0xDFC27A5E61156274ULL, 
            0x47E7B699B00734BFULL, 0x9BC6F41D61C43C46ULL, 0xB00806018D7AE74FULL, 0x3784053250050A73ULL, 
            0x057BCED055EEC2FBULL, 0x14C228D7825D2339ULL, 0x9FBA3F2BA1923413ULL, 0x15659925ED0BCABEULL, 
            0x69B772977C7793C9ULL, 0x017BB524A9E313F4ULL, 0x27ACA8D828EFE638ULL, 0xA7C99B7039F46261ULL, 
            0x304204A8F3AF252AULL, 0x3C1F44B619F80451ULL, 0xF652019C109A9018ULL, 0xC36DA767D5022B4DULL, 
            0x2FE8D36F3CFBCA34ULL, 0x4188675471A82D30ULL, 0x5AEDE4AA4F992659ULL, 0xDF6582AA4F59AE5CULL, 
            0xE86CA49FDA48A1E8ULL, 0xC2724E6584585A89ULL, 0x1E6B15AC6B0942E5ULL, 0x314BB5E28C1528F8ULL, 
            0x4632E9AD8BEBA9E7ULL, 0x05D946D3F2FC5A17ULL, 0xE4EB7E1532FEC7B8ULL, 0x9CAB19446247D7BBULL
        },
        {
            0x939B71997C7CFA3EULL, 0x4B6A5B91CA234738ULL, 0xC701B7052C8F9D3BULL, 0x916A64F46BEE3C54ULL, 
            0xCCAC2ED303462957ULL, 0x88CD7A4CC943335FULL, 0xA3AC85856C8AEA6CULL, 0x22FC566B3635F5A5ULL, 
            0x6F3F60C4D6E2BC3FULL, 0x3B821F67A2F58719ULL, 0xDCB025258BE8C133ULL, 0xE9F249D65404E162ULL, 
            0x6803DAEF3D8DBD94ULL, 0x775BD5C6F36C4B57ULL, 0xB20627BE9838EF7BULL, 0xC0164B18294D81ECULL, 
            0x7F0D02B190E1F1B0ULL, 0xA41C52DF9F3B8067ULL, 0x1E7E99B7E18B8462ULL, 0xB1C1A26620D9D080ULL, 
            0x17930F474DA839EFULL, 0x92ECFC98200E02F9ULL, 0x8435232B5D72D2FBULL, 0xD58D6E02F74395F6ULL, 
            0x60C03A3AEDC9F0ADULL, 0x286ED575EEC2AA02ULL, 0x2BA8496893DDEF5AULL, 0xEA08955E13E34BE6ULL, 
            0x8DDAC73C68ABD06DULL, 0xF9744B0037D9DE74ULL, 0x634BAB34B8CDDE78ULL, 0x6AE68DB20BCC1714ULL
        },
        {
            0x0B2FE023CDDAFF05ULL, 0x6F0A6B274C6E6F96ULL, 0xF408E952B585E719ULL, 0xCB640EDF80BC21A1ULL, 
            0xF5249B67F6EEC89DULL, 0xD410BD7D07B87484ULL, 0x2470F79914373281ULL, 0x72EF8C5C91E6A530ULL, 
            0x574D31B76E2DB6E7ULL, 0x6D445E1D566F3533ULL, 0xD676D2938E4FE029ULL, 0x8603FF7F8E57E854ULL, 
            0x715BC94C5829E912ULL, 0x7687826DA457F797ULL, 0x1737FC5B7D03CB3FULL, 0xA91B6451C7F7133EULL, 
            0x37C8431AF0E201FFULL, 0xCF7CDA5761F9A77FULL, 0xC9D68449EA17EF96ULL, 0x8977EA61816DCD25ULL, 
            0x5F06F37BB5661BE9ULL, 0xAEE354F475DF7B62ULL, 0x8ACD71E387212AA6ULL, 0x4B2CBAB6CB157101ULL, 
            0xF56A58CFDE7289E7ULL, 0xABE0882CC9066E29ULL, 0x57D05FF2185F9791ULL, 0xD3EBA2109A0D1A63ULL, 
            0x73A269B2AF5F72B7ULL, 0x52D7EE36DD114FA3ULL, 0x53D4C56DBF5EC418ULL, 0xDF423E687AC35949ULL
        },
        {
            0x55D2DFE0F3A97516ULL, 0x6F775DC9D83B4F4EULL, 0x765649C83F7D42EAULL, 0x33274706716C451CULL, 
            0xF7B7865FC973AB34ULL, 0x10085C13F6E132EEULL, 0x894CC371FA58D612ULL, 0xFBB2027CE980564AULL, 
            0xE1BEBE7D857D5F2EULL, 0x204D0905213F353AULL, 0x04BF62A3BA22DA5EULL, 0x2B8BF24070D4F42FULL, 
            0xAAAE3C87D67D8572ULL, 0x311A530A4DE1257CULL, 0x177C38B81A705E91ULL, 0xF2703EAADD05136AULL, 
            0x38F3D1C7638A34E7ULL, 0xE2AE0ED2703FD132ULL, 0x9C05BE544282ED4EULL, 0x6D5DDD3319570B3DULL, 
            0xB483385AA89CAD8DULL, 0xB5F1EDC7C3A5689CULL, 0x5EA1CF6BD580F34EULL, 0xADA5957E081DFCD6ULL, 
            0xC35384EFF4FBEABEULL, 0x541DA2CC42D6618FULL, 0x9A738B5582009217ULL, 0xF1C00F250B4E177DULL, 
            0x9678F101669374C8ULL, 0x27BEF98313C93890ULL, 0x1321C20A503FE576ULL, 0xD0EF47E1887E261EULL
        }
    },
    {
        {
            0x10635A0699BB9A31ULL, 0xF03EAC4AA75C2BAFULL, 0xC34FD394F373E22DULL, 0x06A1EFC4CB3558B8ULL, 
            0x7BA244703AB0212CULL, 0x38736ACB41BEF6ADULL, 0xB3DD200BF5429DB1ULL, 0xA385286AD80A269DULL, 
            0x4D1548A02C0C4526ULL, 0x6D9A6FFB11A1692CULL, 0xEF4253E34F991DFAULL, 0xEB53FAD2C6753EF2ULL, 
            0xB128581BA50B857DULL, 0x95007B69A53D55ECULL, 0xE7052C9FB703BEBAULL, 0x4E6DCC47175E1E1DULL, 
            0x989AB8CBCA4A08C0ULL, 0xB22A42C67BA22C2EULL, 0xC014607E0EE34FAAULL, 0x0673EC259CA6A8FFULL, 
            0x766A7EA100707CECULL, 0xD6C1A8D3FEA24545ULL, 0xB9B8D54E196B95DDULL, 0x94CC481643195988ULL, 
            0xC73A074D9EAF6109ULL, 0xF4B4025D8FEC668FULL, 0xBEAB4C54B0DF16C0ULL, 0xF5A330DD91C30F01ULL, 
            0x774052648FDDDD17ULL, 0x83D9D6A6312C0F31ULL, 0xCAB53A1024D18466ULL, 0xAF06744D43B53A88ULL
        },
        {
            0xFB7368A714D46B37ULL, 0x1612C3B48E7A3327ULL, 0x6AF7020FE2570848ULL, 0xBCD2A37A8907C8A4ULL, 
            0x8DA3BF29FE856398ULL, 0x7A44D8A4282D1E9DULL, 0xC6E6CA86042A77DCULL, 0x944AB6472CE8FC2DULL, 
            0x0B24E02F7277632EULL, 0x9FBEDA99F58B1A16ULL, 0x8BE903EC3B633E1AULL, 0xBF25C1F454086278ULL, 
            0xBACD8873FE6C4E29ULL, 0x75F942B8C20EEF7FULL, 0xCD7EBEE9C5983836ULL, 0xCD810CFAE391F26CULL, 
            0x8684167DE91C16A6ULL, 0x9BB1BE6C1F30F0CCULL, 0x9F4BDF9130929A70ULL, 0x11C830CA6D60EA08ULL, 
            0x6443F12BBE5F3B1FULL, 0x1987762B290ECCCDULL, 0xE2BE44B4889841F1ULL, 0x0FF0E48A45354367ULL, 
            0x0FBF926B5F6A1C2BULL, 0xF2948EB3311A3B1EULL, 0xD74958C7F1C43502ULL, 0xB90A3B7D47D2516BULL, 
            0xA3BA007133E961E2ULL, 0xA57DA20046ABF152ULL, 0x837AA6D26E5AB3E7ULL, 0x6C5A6CA59FBC333EULL
        },
        {
            0x20C665702BD8E398ULL, 0xA44F770C422F5AEAULL, 0x406CB2EE73E6FB29ULL, 0x792E0A2CB5AF1C5CULL, 
            0x304A9531A508F300ULL, 0x322B901E2DA5E6F2ULL, 0xC2D4FF02D810A707ULL, 0x99A38A7BF324EC80ULL, 
            0x2C01625BE3E40248ULL, 0xD0ED17F564B85132ULL, 0xCF346332EBC7C92AULL, 0x55C47D61DAE55193ULL, 
            0x2330519C5F33DAD7ULL, 0xC1262C8652851276ULL, 0xA036CDDE0B829F7AULL, 0x9FA18C22D2F1FC04ULL, 
            0x28B292D06C9B1436ULL, 0xD518F9CDB69F55D6ULL, 0x32438A799FF6138EULL, 0xF5124DDB41F5F21FULL, 
            0x6554A0DBE22FFCD7ULL, 0xC95AE609CD6AD784ULL, 0xB593D88E49EAC7EAULL, 0x67E6B2FF53206992ULL, 
            0xE99F5FDF769A5C2BULL, 0xF38EA6B46B8400B8ULL, 0x99ED7709332F193FULL, 0xFF120969841B3E36ULL, 
            0xA0574B39F8E115EBULL, 0xC56112F89C740944ULL, 0x260AD940DD2E4D97ULL, 0x0799C494A520F52CULL
        },
        {
            0xF7D570EC13D51303ULL, 0x3D226B64CA4674FEULL, 0xB9411B3EBA92248CULL, 0x127905CF36CD6077ULL, 
            0x81346A7FBDE7C168ULL, 0x31800702F1796104ULL, 0x23882AE55846488DULL, 0xB023CC18D1465DA9ULL, 
            0xDB9E2F7B16D81A83ULL, 0xC2765DB1F19F6428ULL, 0xB6AC675024C11D25ULL, 0xF290CE7214EE36D8ULL, 
            0x0674B03B93BCB57DULL, 0x5A464FECD6A81ED4ULL, 0x00487182EABB88D1ULL, 0x32EAEDB71A1A3E03ULL, 
            0x0D84AB3365442677ULL, 0x94F63BDC42BAD0A0ULL, 0x8CA8A80F90184183ULL, 0xCB6162682880A556ULL, 
            0x9DE0422CBB946445ULL, 0x617BFF691F195529ULL, 0xDD0922DCC85477FBULL, 0xDD0BD9AEB4BEF7A0ULL, 
            0xD8C2F098C344DE7BULL, 0xE6DE8181D0E39BC5ULL, 0xDDDD25B2C7BAF6D8ULL, 0x5E14031DD74DBCDDULL, 
            0xF6364FB16E02E2D1ULL, 0x463B5BDDFAD2526EULL, 0x139710A534CA4B42ULL, 0x7EBEFF9502D433F1ULL
        },
        {
            0x0243D3150791CB9BULL, 0x7EB6CB5C24DF7B31ULL, 0x69860FA233A4DF41ULL, 0xFA0A159344051AA0ULL, 
            0x4BEE785586C2866AULL, 0xDA5343B96DA5B049ULL, 0xC0E818FFCC383E2AULL, 0xBE1092AEBB327D27ULL, 
            0x6F685566D3914470ULL, 0x3568AA59AB628BD4ULL, 0x4131D1DF6FE6B995ULL, 0xDDA7204110629C4FULL, 
            0x3BB186DC4FB6A693ULL, 0x1E4E16120A3869CEULL, 0x0596EF4D7FD93E34ULL, 0xF34D4AF145F14B7CULL, 
            0xC987CDBCE9A4253DULL, 0x50855958E61312E9ULL, 0xA5D6925A01E603C6ULL, 0x82837319907447C5ULL, 
            0x36641D213054E4A3ULL, 0x644082BF1346CE28ULL, 0x154E76A525C39127ULL, 0x66F42103E2A57DF7ULL, 
            0xB8C7B44A2A75356FULL, 0xA15153A0F9E17458ULL, 0xE257F9F55704DE32ULL, 0xC0E64016C17FC434ULL, 
            0x6E1DD1C3F05BBDD2ULL, 0xE052FE48168BF019ULL, 0x0BF5E4A95A4F5B57ULL, 0xC8F2DF39A2BDDC08ULL
        },
        {
            0x2DF5941A7B61DED9ULL, 0x6747AF44BB0C7EEDULL, 0x436752FAC8FBDC77ULL, 0x2374457A188B1D13ULL, 
            0xB0256825C8ACDEE2ULL, 0xD99C4BEF0F241DC3ULL, 0x97E0A921591FD3EEULL, 0xAC85E4460125FCD0ULL, 
            0xCAA27FC03DB9E683ULL, 0x2DC308136C0CE981ULL, 0xE1B7EE16F1C702EEULL, 0x5B4709F8C6CA82A3ULL, 
            0xE3E77E9F635F20DEULL, 0xD155F791D83E18BEULL, 0x0B3E24202BBA5EDDULL, 0xF348074E9EA85AE5ULL, 
            0xEFBAA15259F900F2ULL, 0xA621250A9BFD2FB9ULL, 0x34F0B1B2CB76A4CBULL, 0xA70E507FCEE062D0ULL, 
            0xE58DD86E46F0EEA0ULL, 0xD5EFD65D66D8DF20ULL, 0x51BDF6C025B427E2ULL, 0x29EDA7E3AC742201ULL, 
            0x02F3D58DB1085522ULL, 0xCDD1BA7046D51C11ULL, 0x263804A72F12D83AULL, 0x72F3A406960D9F50ULL, 
            0x5E8B79503DF2E0ECULL, 0xA6E717EDE12D163BULL, 0xA794FE8C826BA66FULL, 0x6029052998B5C7B1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseFConstants = {
    0x46DE9083673AC530ULL,
    0xF4B330C452008C9AULL,
    0x1F8428303AD79434ULL,
    0x46DE9083673AC530ULL,
    0xF4B330C452008C9AULL,
    0x1F8428303AD79434ULL,
    0xCC2ADA21DB32501EULL,
    0xA42EB4A6E11CCDE6ULL,
    0x2A,
    0x01,
    0xC5,
    0x89,
    0xEC,
    0x9E,
    0xC1,
    0xA4
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseGSalts = {
    {
        {
            0x1AC0AB9D82AFF63BULL, 0x16EBC81D4EB683EBULL, 0x7DA22295B7BDA2CBULL, 0xBFD37813031DFBECULL, 
            0x1AF12ECE12405CC3ULL, 0x1735EB2AD50FA35FULL, 0x0423ED00E4B49E78ULL, 0x7AD2DF3C49BE7564ULL, 
            0x1C1BE5CD4F451C66ULL, 0x106504FC2C96AC59ULL, 0x809E8E925BF67618ULL, 0x42C4CDDAE658B412ULL, 
            0x89E8975F370E2284ULL, 0xE35A725084A751E4ULL, 0x352400F1D91BA4AAULL, 0x06C6027A472053A9ULL, 
            0xCF6F60B4D5D726A2ULL, 0x1B13AAF1F1994E59ULL, 0xAB1639FCD4AC5613ULL, 0x2A3B90BCEFE7DA08ULL, 
            0x51F4F63720D579CDULL, 0xD8D74E7172FD2EB5ULL, 0x838CE0DE32302212ULL, 0x05EF8C20B2F7B5FEULL, 
            0x104B175E7F17B82DULL, 0x58CFE7F130EAC2FCULL, 0x5D1863C85F272481ULL, 0x2F4F8338E2994C01ULL, 
            0x1DDA5E6D13D18E7EULL, 0xA04FFEDC22206207ULL, 0x9EF548C6C0B87308ULL, 0xC2A55FEBF0942234ULL
        },
        {
            0xBAE7D431DA253A92ULL, 0xC73F139BDFF53733ULL, 0x434FF42D021359D1ULL, 0x2295A0AE22FF85E5ULL, 
            0x4031B45638E48AD3ULL, 0x3E89C69E65A45ECFULL, 0xA2CC5D2B03891ED7ULL, 0x4D5F97B7033E7FCBULL, 
            0x3ECD760650CE5325ULL, 0x5208050E522316D8ULL, 0x9F5DEEBAC033DB7AULL, 0x282B0A233D9E860AULL, 
            0x39826C6E727A0EBFULL, 0x4D8A0254AA055682ULL, 0xB1D4699BD2C37047ULL, 0x42710AA1E0E67925ULL, 
            0x429644812F675873ULL, 0xBE7E3B5C0E594ABBULL, 0xCD140985EDA18025ULL, 0xAAB32C8D6BD2464DULL, 
            0x80E6C21F70EC6C95ULL, 0xD7A354EFF999A124ULL, 0xD9B3736A8540C0BBULL, 0xCC31E732A5AAC547ULL, 
            0x25295C2FBC382B9AULL, 0x4FD8D51CFDC676FDULL, 0x7E3F50ECBFC4234EULL, 0xBF8C068EC6CE64F2ULL, 
            0x2B01623861508500ULL, 0xEB15C758CB3E2292ULL, 0x06077C41B4BF2E6FULL, 0xA7D07EDEE61C36D9ULL
        },
        {
            0x5D636D4BB16857CCULL, 0x53389EBB56240826ULL, 0x446F7E6035F86A16ULL, 0x3A154385802D6672ULL, 
            0x30C89C0F323C5DF7ULL, 0x595FE7D119724D95ULL, 0x45F905AC8C2EEEE3ULL, 0x1E1BE88A4B711D66ULL, 
            0x0F856D116C6475E9ULL, 0xBBF48C5A3B76806CULL, 0x973DC5CE84766540ULL, 0xFACBC6B4AD68E5C0ULL, 
            0x127FD1724360495FULL, 0x4ED383761784BCC4ULL, 0xDF28557BEEBE35A3ULL, 0xA37DBEDA7C324042ULL, 
            0x2EA226A6D1CC43E2ULL, 0xE550D654DE98380FULL, 0xDD5C6B0EF0E0CF32ULL, 0x2DBAEAB9114777A8ULL, 
            0x5BB543DD87BCFECBULL, 0xFA788BB4A50B8BF8ULL, 0x69FD0DDD796F0BA6ULL, 0xD54D593F288A43CCULL, 
            0x4C42748A0AF9A296ULL, 0xF1605B9D0034855DULL, 0x8E58D37C1DABCD78ULL, 0x024F0863F5B119EBULL, 
            0x4EC25A415A68937BULL, 0x8D79B79935E1F9EDULL, 0x55299FF756108A2AULL, 0x473A27C620D3026FULL
        },
        {
            0xFD9A016DC32D0A8DULL, 0x95D32743C686E40BULL, 0xAC4C40E3C48133F4ULL, 0x49A8F946172D0230ULL, 
            0x9C9AAFA8EFD029B0ULL, 0x1DA548A63EBA3A0AULL, 0xC5D20B7C1CA94BCAULL, 0x6E72A4C3C3E7AEA5ULL, 
            0xDD279014ADE1D049ULL, 0xE08EAB5A9B12FF9FULL, 0xC7E86007A55DCABDULL, 0xE641D980339AFB53ULL, 
            0xC84850331D4CEB93ULL, 0xDADEAB0EA20B4B34ULL, 0xFD31B30DA330894AULL, 0x12D87668927EDE71ULL, 
            0xAC205D734BA8A82FULL, 0x76B6911234CBA12CULL, 0x09A94F602CD29392ULL, 0xF04AA3CF1E6A948BULL, 
            0x15CB43553F1A8A99ULL, 0x49BE793FB9232226ULL, 0xDC13E679AF1EDD91ULL, 0x77F351A206047CEBULL, 
            0xA5038960F66DCDCCULL, 0x7743A963BE8B10B9ULL, 0xCEA1C47A23899836ULL, 0x38DCE1B4A132A7A8ULL, 
            0x37CB8D14403AE364ULL, 0x213E9D7FBC985A7BULL, 0xDBB44733C5501C63ULL, 0x728D9DE1F42DD1E0ULL
        },
        {
            0xC09FBF8A50196183ULL, 0xC05925BDAE7D6856ULL, 0x0D14F428853F7A73ULL, 0x55CE88084D62B637ULL, 
            0x5723793A09BE8911ULL, 0x5A72F3ADA837F1A1ULL, 0xD91A6016DAAB51C7ULL, 0xE43AFF7BAF18CB7DULL, 
            0xD567B2949BA15999ULL, 0xF0DCABF51B4FDF62ULL, 0x15399E9206425FE9ULL, 0x766384DFD6399CCCULL, 
            0xD2B9A52C69D4D03EULL, 0x959156F863A2A983ULL, 0x5B63C4BAA069A836ULL, 0xA1D0D2C4218EA647ULL, 
            0xB06F7A8AF7C42BCFULL, 0x6F383AC30D698EC0ULL, 0xC6ADDDE18DD50025ULL, 0x9DAEE13FC34F15BCULL, 
            0xDBDEAAD9BA973662ULL, 0xCD085AEF9A2263C2ULL, 0xF6039521B4DC2709ULL, 0xE9827F10A368F4EBULL, 
            0xC0336C36EA4D745DULL, 0xA05DEC780A184650ULL, 0x3B6F658F6909ED57ULL, 0x0E1916E8A130CB83ULL, 
            0xFD878775991F1F25ULL, 0xCCFD8CB9E1C00007ULL, 0x5ABC95BF1572D5AAULL, 0x182C3FED0F3D1938ULL
        },
        {
            0x1619A58E08FDE255ULL, 0xF384E49A568CD8E1ULL, 0xD8480368525582F1ULL, 0xD2B361838FE34C6BULL, 
            0xC44E9094650EEF8CULL, 0x0078239AEC8CD38CULL, 0x021F8CFB645ED51BULL, 0x80DB5F53973B65FAULL, 
            0x54A795A4D2D70C48ULL, 0x3EE6EB66BD319BDEULL, 0x118427DC7BFC455FULL, 0xA6529352195BCAA1ULL, 
            0x322245220813C7D4ULL, 0x2BECA89E4BA39C57ULL, 0x8AD63BD0C1DA98BEULL, 0x555063A5EB690640ULL, 
            0xC2B5F15634544DBCULL, 0x1E6C156D828FBB41ULL, 0x4B4571A33DF92645ULL, 0x3EA3D6835CFA6DB7ULL, 
            0xBBA81858186A535CULL, 0xD870B28EFEFC0E21ULL, 0xAAB7F6FE6A2F0B37ULL, 0xE654457F25AA72B4ULL, 
            0xC9897AF8BDC52B6FULL, 0xA2C76D71C7EA9FFDULL, 0xDE4ED58FEF4DD95BULL, 0x7A4264246895A97FULL, 
            0xB4B94BCC09D6BA6FULL, 0xCD2B31A63F341D1FULL, 0xEBD6A90C2EF5959BULL, 0x11E38BDA557444DCULL
        }
    },
    {
        {
            0x9D02BCFD49FB5379ULL, 0x031C2CCD10E068DEULL, 0x1CC70C109735A6CCULL, 0x3C522AFD21BD2558ULL, 
            0x86EB97EE44C52734ULL, 0xFBFFD32653823DA6ULL, 0x74F56EF978C3536CULL, 0x2AD9534CCFF957A2ULL, 
            0x241E953932ED516DULL, 0x09ADF705FEF4DA07ULL, 0x51068DB1A33AC97FULL, 0xA3C0D24316FD5F4EULL, 
            0x100F0812558E4230ULL, 0x4B28A3220F92553EULL, 0x273CEC07C96C1249ULL, 0xB14906EC00F95A66ULL, 
            0x9DF65650A1321140ULL, 0x06947E3D6B987539ULL, 0x682ABE1F3DBE74D6ULL, 0x518C4955994DBB29ULL, 
            0x92513E0D4E79B267ULL, 0xEC1DABE3D1AA5B83ULL, 0x9E1DF7A9B4B5BD40ULL, 0xA3D0C663CDAA6B49ULL, 
            0x36E108FF7A1530D5ULL, 0x56F8FE4AF85E2AF6ULL, 0x457CB1CF5234A16AULL, 0x8323E88AF4C6C059ULL, 
            0x28B7D576179C2918ULL, 0xDA55A71740B0DC92ULL, 0x011ABA118CE593F3ULL, 0xBEBEF0A1F88CF01DULL
        },
        {
            0xEEE6AFD8EDB34A1DULL, 0xA0CF8F815489F7B1ULL, 0xDFF4F8D67BAF5620ULL, 0x29E8001AAFD58638ULL, 
            0x6E21B709911B960FULL, 0xBACA3C43316CF7C4ULL, 0xC2DADBAC6EFC1497ULL, 0x33283B240DB7BD9CULL, 
            0xB5C41767EDFDDABAULL, 0xC75309F93E71C2C2ULL, 0xE47A40A610BD7CCEULL, 0x19D138D4F2EADCF6ULL, 
            0x556A26BAD32A3907ULL, 0x015C8A9B21DA8996ULL, 0x00B68302D5D9548CULL, 0xBBC0FEF9B83F5114ULL, 
            0x61FA7F4B3856B751ULL, 0x707C783E8D5CA4F4ULL, 0x5AB987175C312EA3ULL, 0x9700ADC987B9187BULL, 
            0x624E9551D0BB089DULL, 0xB98EB53452E74086ULL, 0xA06F158C77200B3EULL, 0x47D28B22021030DDULL, 
            0xE523FF03D64B4DE7ULL, 0xAC93431CAAC21DA3ULL, 0xA56EBBCD2F7BC191ULL, 0x060E1EB49492161DULL, 
            0x45A8CD98AF5711DEULL, 0x7B838CB9D52493FAULL, 0x9F75488B90BEAC96ULL, 0x6BCD5D47F5FE9E43ULL
        },
        {
            0x7BE39F9D79389A0BULL, 0xDAE0AD61A126D298ULL, 0x0791BE5B53CE5A10ULL, 0xB51AB2C498A55E22ULL, 
            0x73702653A8F8A6F9ULL, 0x3ED3A95FD116E3D4ULL, 0xA75D880DC31B51EEULL, 0x97B675AA2CB55BBFULL, 
            0xF1AD70719D6D0FCFULL, 0x3C4E2B99621A0EFEULL, 0x07CF70DEF6CD61FCULL, 0x4C5B6EA9CFEE1844ULL, 
            0xA751B761C0B1FE10ULL, 0x0D7CEA50FA2514D2ULL, 0xB21E62150A02682FULL, 0xB3C58D24C1396C75ULL, 
            0x75386D832DCD45FEULL, 0xF7C17EBBAF501823ULL, 0x966BEC31197E7339ULL, 0xF4BA19B438292423ULL, 
            0xCDBC8E18574A70BCULL, 0x47453356BE4F1BA7ULL, 0xB82A314AF7D5AF79ULL, 0xD5C78A4B7A42ACE9ULL, 
            0x4C35C2C13EC74FB6ULL, 0x86B7D68FE851F9A7ULL, 0x150FBB15F2FE1A68ULL, 0xC870B85E76F22638ULL, 
            0x3800D1CDB7842C63ULL, 0xE09D933635EE2D78ULL, 0xAA96DCBC717D29CDULL, 0x4AF3E99CE9ADBD3AULL
        },
        {
            0x53B7290136E5AAA9ULL, 0x8FF538185D29DD2AULL, 0xF3C2AA9C8D88A93CULL, 0xE41A83B4BBE9BB71ULL, 
            0xD5460DAF6442FCEFULL, 0xAAB9F5FDAA1914E8ULL, 0xCD5DA64C37B70029ULL, 0x8622BEB9DE7548CDULL, 
            0x943DE7E8C0475359ULL, 0xE62F36FABF78FDDBULL, 0x33DFF96DFF2EEF2DULL, 0x5F189B830879E64FULL, 
            0xA5A6C7F10F9A3A73ULL, 0x5A520533BAB09CF2ULL, 0x12B494D0FF26947AULL, 0xE0EB2DC4B0F53C00ULL, 
            0x94E170B0BEB1C466ULL, 0x1430F8EC175E4752ULL, 0x929CFFF70CB461E9ULL, 0xDDD0441F041B6B2EULL, 
            0x8F5726E63DF12C52ULL, 0x6A01E41771D9823BULL, 0xD249C75EFD94EAA6ULL, 0x5225EF1BF889318BULL, 
            0x28F2B1EC31D30F7AULL, 0x8806DD2E0206F3ABULL, 0x6D94ACB19186FAD1ULL, 0x6FC29A408C9637BEULL, 
            0x65D181168382C843ULL, 0xC97FAB6FCAF2D8FAULL, 0x1A600879B0859CF9ULL, 0xBC9811BBFC9C2243ULL
        },
        {
            0xBB3E6D23CBBEEBA2ULL, 0xC58EFA5851F719DBULL, 0x269863B31786DE09ULL, 0x6D1C68DA96C3C587ULL, 
            0x453610CF7B47975CULL, 0x8A65A93A818A192EULL, 0x0DFD8670B96EDC48ULL, 0xB048AAAA12AC15DFULL, 
            0xE178343BE19042F4ULL, 0xA675FE267C1A6282ULL, 0xBFD4AB5F06A9B425ULL, 0x2A80CD29E94AC57CULL, 
            0x2B8D050ED6E18AAAULL, 0xD1E5F242F5908C67ULL, 0xE989A142C54942E6ULL, 0x5FAF86BC5C8E9C96ULL, 
            0xF9BB88EC35EEE956ULL, 0x11B8AC1B1E8BFF9EULL, 0x058EFE68E4E8508CULL, 0xCCF89B9D1E9676F4ULL, 
            0xBE5A04DF85DBF4B2ULL, 0x796C6BC03BD8D494ULL, 0xD32DD69FF8AAAC27ULL, 0x1A5CC24E178E2113ULL, 
            0xB3A0E0F3E8361809ULL, 0x399A48750FB54732ULL, 0x1776DF6ED9973017ULL, 0x90559750E8FEA424ULL, 
            0xFFFA8ABFB6B4D55EULL, 0x8385F506613FDB57ULL, 0xBFBA77BC9A71ECE9ULL, 0x879E8292E1CD0789ULL
        },
        {
            0xF1439E720CB80C7DULL, 0x27BAB63DAC68883AULL, 0x2916E4C577F07D24ULL, 0xE2D80410C11CD368ULL, 
            0x511B1AAA1A978570ULL, 0xC4F7FF9E31D8A93AULL, 0xB04378DE14F1351BULL, 0x2546689E2A826EC0ULL, 
            0xEE99E50B9C5D839CULL, 0xA1200F929EADC045ULL, 0xE7ACFB19BDDF7E5EULL, 0x2534A6D09F77509EULL, 
            0x23D3D2D967A22AEBULL, 0xA060B37C78361ABFULL, 0x3C2152F3379C17D8ULL, 0x4B3B757543401016ULL, 
            0xA14CC00911606429ULL, 0x2EC73820546D556BULL, 0xC7D4F68968A89628ULL, 0x76C1444447DF130EULL, 
            0xB57DAF7F9D4AB1FAULL, 0x9BCB39D7111DB097ULL, 0x391C5E094A3C5DDDULL, 0x5EB27A349A6B6E5BULL, 
            0x20BB078434ACA769ULL, 0xA6ADB3662A5D8571ULL, 0xA7BB9D5AFBBFBEA5ULL, 0xA41595CDF10F283BULL, 
            0xBD0851E70AF7D887ULL, 0x2B08B72BCF8462FDULL, 0x5C4A89DD6E0E5007ULL, 0x7CAF52F58279CFE3ULL
        }
    },
    {
        {
            0x2F9163E3D11522FBULL, 0x725A0DCDD696E903ULL, 0x166A3439B16AD2A8ULL, 0x875E01826BD97027ULL, 
            0xECEF149AE986A55EULL, 0xE3D1A144B4DEE1EAULL, 0x01EE4304A2F9F22CULL, 0xAF2DEAFF04C54EF7ULL, 
            0x43ED52D8E49336CAULL, 0x84243833BB0A8DB5ULL, 0x2A1BB663124ADEADULL, 0x588DB0060A3DBB2AULL, 
            0x5BF14432E55C46B0ULL, 0x67AD172D7630AC4AULL, 0x7A05A183BC4E18FEULL, 0xA23EB7B349FDA709ULL, 
            0xC4F0D7437F222E87ULL, 0x861A8381AB1144B3ULL, 0xD08A5BD380DB08FEULL, 0x6C24AA32EE180C2EULL, 
            0xBC7EE027EAB3945FULL, 0x1D8EC7C2FC2EB3FCULL, 0xF24B386F605B5D49ULL, 0xE5E9BA5A097F3CB4ULL, 
            0x3CCF073A601AB024ULL, 0xF929D8AD1352220CULL, 0xC53C9FED4DDBB502ULL, 0x0DD391404B84202BULL, 
            0xB0B24AB9CCFDA48CULL, 0xEDE8F5F8DB053CFAULL, 0xF4DED2B798C063DCULL, 0xE368EA3048ABB242ULL
        },
        {
            0x7242FEBE37BCFA54ULL, 0xAF80E852237F95E4ULL, 0x255279D124D342F6ULL, 0x8B1B507763F84308ULL, 
            0x1EE7E3E83F2E1DC9ULL, 0xE38AB5D1301F26B3ULL, 0xD6A77B9A41A67F8FULL, 0xEBA641CCEA194B00ULL, 
            0x02FF5EC205D93BC1ULL, 0x9126645064E70566ULL, 0x2C9A9808E4CC42CFULL, 0xE03A321C3B60C653ULL, 
            0xAA0C7C8FE46EC2C1ULL, 0xB9BB9EB76B721768ULL, 0xC3876962535BF33BULL, 0x987EBBAE6DEDDEB0ULL, 
            0x2FAA82EE61B8FA1FULL, 0x1BAD588C20455A85ULL, 0xE1A3D619C5C4ACA3ULL, 0x3F58E126C7A71B71ULL, 
            0x366A567BE1278741ULL, 0x4249A2CFE4D07A7AULL, 0x0F0C5F15B23768BFULL, 0x1B12BF2BAC1990DFULL, 
            0x425E4C7EEBEEF5A7ULL, 0xD6934C77159CE3A1ULL, 0xC2201A6642A858C3ULL, 0xE0AC916AB569940AULL, 
            0xA4FFF66C6B83C3B9ULL, 0xCBD351996EBDB76FULL, 0xD512A07C172A353CULL, 0x8D31D56620206123ULL
        },
        {
            0xAD11B691551CB600ULL, 0x31F05E7C5D6ADB60ULL, 0xA56215FCBA282204ULL, 0x4342FD125C5F175EULL, 
            0x651E0EDF8D422935ULL, 0x0B48C5B2F7B8FC3DULL, 0xBF94F58C2467F0E1ULL, 0x20F7A80240922C4AULL, 
            0x523DE85E817429A4ULL, 0x4644EB15241435CFULL, 0xADD3FE4BC1888A85ULL, 0x61301AD9634BD1B9ULL, 
            0x733B8FD8852C0C62ULL, 0xD9817CA9EDFDFE45ULL, 0x64F72ED4A8877AA9ULL, 0xE1A4CBD990C578BFULL, 
            0xE1682B21DBFFFBADULL, 0x8738D69167343FBFULL, 0x71F56E5F5FDDF075ULL, 0x86FCE42FA129C1E0ULL, 
            0x1A3F4D2A34CB5373ULL, 0x16BC90B81833DC66ULL, 0x5B20E1ED8ADECD18ULL, 0xDCF2C7048A5AD086ULL, 
            0xAE67B899792E14DAULL, 0xC2F50BA3766A1C22ULL, 0xB5D2F919DBBF94F8ULL, 0x49CB217118ED6635ULL, 
            0x588CE6ACB6DB3831ULL, 0x36D8772A0930E479ULL, 0xA877ED6317FA08B2ULL, 0xFF44BC9BF942CC5CULL
        },
        {
            0x6EA3B42B1E8BB1F9ULL, 0xE5ECF73FB0451B65ULL, 0x05CF3852442352BBULL, 0x1871A4C6712B36A0ULL, 
            0x39B65D3DF163045DULL, 0x55ADCDA1FEF56C45ULL, 0xE757E3627A80A3BAULL, 0x64A234809BA84ADCULL, 
            0xDD071A94BEFF1039ULL, 0xA2274D43663BDB8AULL, 0x3F0B2974828C07BAULL, 0xDC287210E1A85B8DULL, 
            0x08588E6451B14135ULL, 0xF2FCB8615EE096B1ULL, 0x7688151E64DD24DEULL, 0x2ECE6971EAF0350CULL, 
            0x4CD05928FD8A4E93ULL, 0x7B38A496EAFBFCCAULL, 0xB8010B4B149561C8ULL, 0x85B320627F3FE705ULL, 
            0x9558AA733ED23216ULL, 0xBB8832B9998DE997ULL, 0x9C5B7B39A3EC7325ULL, 0x7DD0403B819D3449ULL, 
            0x09AA344016C47882ULL, 0xB528BC6257DA8D0BULL, 0x1BD6EC5D4990E251ULL, 0x81D05BC6688DC73EULL, 
            0xE9D3593AB703F485ULL, 0x5C5459F508BDD538ULL, 0x03A0A1D0E4B06C56ULL, 0x940F9C821B8F1C5CULL
        },
        {
            0x2F5D61208EBB6C0CULL, 0x1199B1688CB8B3BBULL, 0x2DF6132E8738D702ULL, 0x0D348A125C14A94FULL, 
            0x47D6ECCAD52890D2ULL, 0xCA76133109BD4103ULL, 0x6693AAFE61BAC5C5ULL, 0x7D5196A85E585C12ULL, 
            0x24F11CDB762464E1ULL, 0x36F9094CDC8F41D8ULL, 0x95CBE4664C1901FFULL, 0xF7009A209DF7284FULL, 
            0xBE414D50EC538BCEULL, 0x6AC1FDFB70FC6412ULL, 0xF91C269683A6BA49ULL, 0x5DBFBB1287179C72ULL, 
            0x935D27921241401CULL, 0xA0A9CB036A7FB7B4ULL, 0x0BF19EFBC825BFB1ULL, 0xB0CE861869257E49ULL, 
            0xDD16834A16B4B210ULL, 0x46F3D7DB86920E28ULL, 0x1F31589338686DA5ULL, 0x0CE4B1A4E1B952E9ULL, 
            0x59792B7FF1CCE16CULL, 0x2CA2DE8613BA64DDULL, 0xE16157D653E0B7ADULL, 0x6826B8E7036F4E71ULL, 
            0x7B152924C19D5ADAULL, 0xF57E11B3C62C48F6ULL, 0x7DCCD09D84716F07ULL, 0xEB4A13A774A2795FULL
        },
        {
            0xF5456763F7E2B740ULL, 0x452BE4AB6A3B740AULL, 0x52C0041066308F9FULL, 0x9B5BA59208EC5C3EULL, 
            0x09A37D85712E9ACBULL, 0x902018F7C901FBE0ULL, 0xAABCDDE54658046BULL, 0xBC198F0F91728642ULL, 
            0x258108094EA5D81FULL, 0xDC1FB31FFFAC8DB8ULL, 0xA9326A24C082E7CAULL, 0xCB06DE2EEB6ACAF2ULL, 
            0xD4E8FA03038CC280ULL, 0x67FB589F591A2FF0ULL, 0x36072EEBE06C162DULL, 0x52B943B7A7D5565BULL, 
            0x6BFBEBE6A45E88D2ULL, 0x888B3FE38DAB6BE7ULL, 0xDA87E4C9C56346E0ULL, 0x0D73926663904544ULL, 
            0x4AEEA745D318C055ULL, 0x35AEE93DF725421FULL, 0x5142928150D302B6ULL, 0x35095748C7C851CEULL, 
            0xBFC7BC5A4014AB47ULL, 0xDC081D87D979501AULL, 0xEEFB44C2994D5A6AULL, 0x690E5B61AFA2D88FULL, 
            0x68AFCE990F38A8C8ULL, 0x2D8A58A50C6F4142ULL, 0x7603FAE60350EB3FULL, 0xDAFF3A57572B58E9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseGConstants = {
    0x637C59E3CC80F81EULL,
    0x39E4FDCEF74FF4BFULL,
    0x4F13B7C1FB8D69A9ULL,
    0x637C59E3CC80F81EULL,
    0x39E4FDCEF74FF4BFULL,
    0x4F13B7C1FB8D69A9ULL,
    0x15F8DAA6A169A0E3ULL,
    0x9859D80243A24F7AULL,
    0xFD,
    0x8D,
    0x27,
    0xA4,
    0x1A,
    0x50,
    0x67,
    0x9B
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseHSalts = {
    {
        {
            0x3621F12979DABEF0ULL, 0xD4C1323C241972F9ULL, 0x274E429D71BC5BCBULL, 0xEDE102549B6418CEULL, 
            0x2328E0ED1C93F4F3ULL, 0x7089C7E420AD847EULL, 0xB72B7C445D1C3D84ULL, 0x9C7C6AA6461FD29BULL, 
            0x0A1FF64D00B632F2ULL, 0xBAE9A1A9D9B41374ULL, 0x40B958E46ADEB873ULL, 0x84ECFA159FBC4A37ULL, 
            0xE4738072E8799B66ULL, 0x5479093D706B0E72ULL, 0xFD12F1E60B27DB7DULL, 0x02E5FE685BA73276ULL, 
            0x9443B5B83EE66096ULL, 0xA5D989AFF7C067BEULL, 0x24ECF9AE9BFA9570ULL, 0xC81D9AFA1D6DE73FULL, 
            0x7282673BAD028E4EULL, 0xBE3F7A6AE500B3ECULL, 0x8DCA3A866AE91937ULL, 0x3AE03E1A1F5D9BD7ULL, 
            0x3C7C4B4035C23D49ULL, 0x025F970698526BB4ULL, 0x776A55E1EBC5C485ULL, 0x37D52E670C156510ULL, 
            0x2C2C70D8210C9E14ULL, 0x5F84B9D3415BA067ULL, 0x9589D92F2F37AA92ULL, 0xBF5F4F735A86B2BBULL
        },
        {
            0x65F149B954C51BDAULL, 0x38507A9A4F19A6A0ULL, 0x728BD1BDB23573FAULL, 0xE4014EBB0A62C9DCULL, 
            0x1A1424F396C9B641ULL, 0xE87D6FF256CE2D18ULL, 0xD6AFA0CAD578FEFCULL, 0x6AB534937B88D3A2ULL, 
            0x3D06D87A5C778996ULL, 0xD0588D758CF042D2ULL, 0xEB5BC5B8A9A6D8BAULL, 0x22754B66AD409F3EULL, 
            0x83DC63E982582703ULL, 0x52F7FF8B4EF1795BULL, 0xB874700AE0BE1910ULL, 0x1E1FDE1828C0FFA0ULL, 
            0x4451A8ED33C112FCULL, 0x921BFCB141A48ED3ULL, 0x6AB1DF3865F35683ULL, 0x0EAF851AA6EA9504ULL, 
            0x7DE3012CD1667509ULL, 0x0731859BE24458C6ULL, 0xD7C419764870EFE1ULL, 0xB88B525CF6FF97E7ULL, 
            0xF9F1C5591B65005DULL, 0x53B845DF279DD570ULL, 0xB7622017C668C1D4ULL, 0xE3B864DBD0971C0BULL, 
            0xE8935D4C4BB29327ULL, 0xE0A5BD5EF4457B95ULL, 0x1C74D5E356F107C2ULL, 0x8A368FE1C9432214ULL
        },
        {
            0x87589AB7B065B723ULL, 0xD3FA4B96289FC4BEULL, 0xEFDCBCF473BAC90DULL, 0x97D11679C5A781ABULL, 
            0x039F04EA1C818E1FULL, 0x489910E86EC39D39ULL, 0xC8E8633D04C5547FULL, 0xDEECF2EE2680FA80ULL, 
            0x47FBA8F6142230AFULL, 0xB10442E66984F954ULL, 0x3720C3161FB4231DULL, 0x1376421488D43E10ULL, 
            0xEDFB966437D0469EULL, 0x9B2C1CF0A39CABCEULL, 0x6EE2E80D3E5B500DULL, 0x0E19F98882A26B50ULL, 
            0xC1830831F42D96C4ULL, 0xE408CD9F6140F917ULL, 0x717AF8EE50E24269ULL, 0x7AA188819C71212EULL, 
            0x74696EA2733E1A16ULL, 0x4A7E724B13C82C39ULL, 0x038E0719A5929E23ULL, 0x37631C45B1AC5804ULL, 
            0x1E7A8D4D91FE1D88ULL, 0xDFA7CB95AB026B4DULL, 0x1BDBF777D071AC74ULL, 0x3A4A88EAB082DFF1ULL, 
            0x4214CB71BE428BF5ULL, 0xCCF6100A04BAE51CULL, 0x6704F68C66633E1DULL, 0x2EDA608B603016CFULL
        },
        {
            0x25DA8847149E12E3ULL, 0x267E3E92F550F7BDULL, 0x5477318ED93EC95FULL, 0xA50F813FABA59D9BULL, 
            0x0DB9E047F5FF644EULL, 0x994BCBFE9E59FB40ULL, 0xE5E8CE2B67EE355EULL, 0xA3378D3CE69D1889ULL, 
            0xA29490C3E84E2D49ULL, 0xF4A70C82017C5FABULL, 0xD330D198B517F615ULL, 0xBDA53825236D7C1AULL, 
            0x7171A4C46D78FE0BULL, 0xCCEB4923A44B589FULL, 0xFA51D96C1FFDD73EULL, 0xD421FEAD8882F8D2ULL, 
            0x823FEB4CD3B525B7ULL, 0x27B850612A4EF040ULL, 0xF17F40F254C3450AULL, 0x52D24E4C4DBAB4DCULL, 
            0x9A3FF6EDD977BC5CULL, 0x5152AC7D49A05ED4ULL, 0x20C3676C7CD6C3B4ULL, 0x25413E96085B2966ULL, 
            0x44FB5710CC026077ULL, 0x6A2F0FAFA8376966ULL, 0xF0796C1674E1AD77ULL, 0xEE5CF3E5D6B53425ULL, 
            0xACF746A33664F2BAULL, 0xF79C4EDC61B4A1A1ULL, 0x1FCB102E6A29FA0DULL, 0x56FF10EF32E15D69ULL
        },
        {
            0x535284DD187CCD9BULL, 0xA71D92126F775408ULL, 0xBC250728C7C09CC2ULL, 0x2DE1D0E95E1046A7ULL, 
            0xCC13BE5AA35FE68BULL, 0xB4C665F6294ABAB6ULL, 0x40B5117C8E9C53CAULL, 0x5B9E0A5C688A40A0ULL, 
            0x3B3B864C78DF0FB7ULL, 0xE901037DF2AF71BAULL, 0x40FDA5AAF296A7F8ULL, 0x98EF038F56BA3B86ULL, 
            0xD9405E5A79DE797EULL, 0xF06A30ADD093D7F6ULL, 0xB6D8B9DD4FA7EE2FULL, 0x329AA3170F0A5207ULL, 
            0x96593FB5B5939C17ULL, 0x344E045601DD8F7CULL, 0xBE6E7CB451A7042FULL, 0x30A0B05D9002E464ULL, 
            0xB36E948106FC9BD0ULL, 0x14104675ABCEEDF1ULL, 0xDA3B761BBA5C9037ULL, 0xE2C37BC6A760FDE9ULL, 
            0xBB5EEA81B318A356ULL, 0x7FD53B5E2036A782ULL, 0x8FE656378B0D2619ULL, 0x14644DFE0360356BULL, 
            0x970C4B2D05FFB6D8ULL, 0xADB1F52860042676ULL, 0x0FF412E8FED98BCEULL, 0xBF4DCE383FAF6020ULL
        },
        {
            0x9B003FD835B283ECULL, 0xA490E9742353A90AULL, 0x97C751C00C79497FULL, 0xC0F2DA17D77D4638ULL, 
            0xDF39B6C36437AFB3ULL, 0x3185C40006100A79ULL, 0xAE79946678C31F08ULL, 0x048D07744E337F89ULL, 
            0x329D4549D011ADDDULL, 0xE8AEE3FB81B86A97ULL, 0xB9EEB8170BC5B34BULL, 0xD6B85EE6C826678CULL, 
            0xD62BF28334FE1BF1ULL, 0x2890153A3C9A1A7DULL, 0xF683C43459231FDCULL, 0x660848C0DD8A6EA9ULL, 
            0x6E1E23C2C6FA1CD6ULL, 0x8887EA9651222682ULL, 0x3FA68CB76D936D78ULL, 0x42BDCD06238C2CB5ULL, 
            0x060B045BD27B4DE0ULL, 0x40297E01C2D09453ULL, 0xC439EEDB69F8E949ULL, 0x2E6EC75839FAD9A4ULL, 
            0x9969479EDD1F6533ULL, 0xC9072B546A408805ULL, 0x3B1252BDD19D2707ULL, 0xDB8DA90AB1C91B9EULL, 
            0x1F715C5430838142ULL, 0xB3598ADD2C3B20CAULL, 0xF7483A016CBCE0A2ULL, 0x88DCF53D162566AAULL
        }
    },
    {
        {
            0xDCE4BFB48A9ED85AULL, 0xC7A18B8ABB430F72ULL, 0xF4AA176F8615003BULL, 0xE153284CDB41D650ULL, 
            0x933B0ABCA09AC4E0ULL, 0x0AF5B335935E33CAULL, 0x38733BF164CE714DULL, 0xD9B094317B45AFEFULL, 
            0xC1212002AA52522CULL, 0x452C78851BE55EB1ULL, 0x81A4479F662D0663ULL, 0xD5D5E29162C7FD5BULL, 
            0x36D9271A8A01C926ULL, 0xB1205EF2A548AA57ULL, 0xA9C5507288177AD3ULL, 0x388AB7AE7838BE2FULL, 
            0x0A8ED485085F6F98ULL, 0x97C2240524E59519ULL, 0x8B018290D3324EA6ULL, 0x6064209BF959C9CBULL, 
            0x163C302929DD51FAULL, 0x79339416656033A6ULL, 0xDC8407DE16437031ULL, 0xAB0BA144F6A21B52ULL, 
            0x98B126927D26A1E6ULL, 0xD902C738FE8C99B9ULL, 0xCED18E75260CE0BCULL, 0x80791EF862DCEE07ULL, 
            0x22D01C922193AF7BULL, 0xC371ECF96B4EF73DULL, 0x1A783174FF195664ULL, 0x8A4D9D67153975C1ULL
        },
        {
            0xDEE87361A3FACEE3ULL, 0x8A4AA11140A2A7CCULL, 0x98D10C7F5930A8ECULL, 0x2D55025F2BFE8E19ULL, 
            0x6CCC602C9782EBBEULL, 0x0F87265F98D76D39ULL, 0x59069EBFCC6377C2ULL, 0x2BA13B05C514BC78ULL, 
            0xAF5971E4AC9FEEADULL, 0xF11F1DA114A46666ULL, 0x4D78BC962A987C4BULL, 0x19AD2A22900E6FC0ULL, 
            0xA85693AB2C0509BCULL, 0xD0C3D3127BA44660ULL, 0x7FFE829EAEB31CDBULL, 0x88499268C55C7434ULL, 
            0x0E48FF4C34FBD154ULL, 0x5E1DF2FE1FA606C1ULL, 0x6FD2BFF5B848FF8AULL, 0xBF15FA7C64C348C3ULL, 
            0x80E931EF58670278ULL, 0x10D3F465CF3964DFULL, 0x032E71A95BB43D7FULL, 0x087F84BB8D62C269ULL, 
            0x2FE79D4E025BDB39ULL, 0x6558F9CA270F218CULL, 0xDB2F8BB31FD41254ULL, 0x956D089178DE9DFCULL, 
            0xE1E191C9153F2BB9ULL, 0xCFE00EB4DC525A7AULL, 0xFDE61F273D93DA53ULL, 0x22A9F288135C7020ULL
        },
        {
            0xEA84FCEE37A88B0BULL, 0xB86CB05C0EA788A7ULL, 0xC83DF5868F431FCCULL, 0xDDA7CFE75867E20DULL, 
            0x6650AEBBD228239CULL, 0x187BC1AE21B5F792ULL, 0x74770C62E223AF53ULL, 0xB0E10E344617D085ULL, 
            0x72009BADEBC48578ULL, 0xF743D28D9CA6A9E9ULL, 0x538D9F7C35FDDE9FULL, 0xAB8992C740069D02ULL, 
            0xD7868BD9EC368B65ULL, 0xBB5937C47E94A395ULL, 0x71D826D23AB8C668ULL, 0x094BC9B6F12AE00DULL, 
            0x66FAFB5629AEBB6DULL, 0xF36B7D0486A48D93ULL, 0xC49F329F21642077ULL, 0x5494D4F497DA8A11ULL, 
            0xC71C6DBBCFB61635ULL, 0x45234F621ED52F97ULL, 0x24F6AECC14678C9EULL, 0xAC0065DFEFAF6FE4ULL, 
            0x948872833B6C805AULL, 0x2BDE9DC7207A3323ULL, 0x4C431E2D713D2AC0ULL, 0x630AF68A28CE6A5BULL, 
            0xEB8BF8DA02916B95ULL, 0xD0DF9EBE84FD64B0ULL, 0xBB1F11FBF630BBBAULL, 0x980CE8F20C777A1EULL
        },
        {
            0x2D9AB21B9B59C89BULL, 0x764F9CFC7E31DEB5ULL, 0xC18946D594759A0BULL, 0x9518E925FB32C20DULL, 
            0x89F22989A7A99B05ULL, 0x6174EC977F47F4F8ULL, 0x99BA5E61ACA4EE0CULL, 0x38131A252148F0A6ULL, 
            0xD05703CB66E6EAB8ULL, 0x17F8FA9F32F50C1DULL, 0x746986BC6B983CC0ULL, 0x801E46A6E0E22273ULL, 
            0x703F35D909AEB643ULL, 0xCB1FD5C1FAC42551ULL, 0xA6E84AEEB60A47F9ULL, 0x5B78FB4E753C8BA4ULL, 
            0x8A9B200F4AB9E9DAULL, 0xC464AB3C4F2F31AAULL, 0xC80F1481A339A977ULL, 0x7FA1323CF1CBB8BFULL, 
            0xD8D887CD60CA9B32ULL, 0x67C7E2BD6122EAE3ULL, 0x467010C82ABB2A3DULL, 0xB0CCC66ABE46406FULL, 
            0xB9B7C909FF7BF669ULL, 0x64694EDB5144FE41ULL, 0x7C3F2C78E889230EULL, 0xB16D3E35E90FD1ABULL, 
            0xAA72F44CBF8068CDULL, 0x3B19DCD3C4D0B4F1ULL, 0x5366BF75F9686DEAULL, 0x95A4BD394AE928BCULL
        },
        {
            0x8FB2C2E7221F6128ULL, 0x1F53262E7FF2BA44ULL, 0xDF0CADB9E5F7989AULL, 0xE77FED9C906D36D0ULL, 
            0x5DE9339D1596BACDULL, 0x6D9568F6F8BFD730ULL, 0x2EE65BBD6496BA0AULL, 0xC76E920289726690ULL, 
            0x16EFA2CF38CE8F22ULL, 0x5D6D18E3E886DD46ULL, 0xE7B431761430DDE9ULL, 0x16B62814BE250688ULL, 
            0xD99177BDD4392E27ULL, 0xDAC06F6A2FD29190ULL, 0x9550AE416EC75F80ULL, 0xE40605E7CE011723ULL, 
            0xB3191D573C78C535ULL, 0xABEF5B71291022C7ULL, 0xE7812FAA9D4D1120ULL, 0xA38A3B0D62FFE125ULL, 
            0x1766624B944F709FULL, 0xE3E8F9168088C303ULL, 0x2DB20FF8AC6BE5A5ULL, 0xEBB6BCD09CB708D2ULL, 
            0x8860A2D7965F5942ULL, 0x40AB5A07B1103573ULL, 0x02B9120D4CAA1DBAULL, 0x369DB0E310853F7AULL, 
            0x4200916B7B0228F4ULL, 0x02532E7C6D9A5DA8ULL, 0xBD9981A53DE5857FULL, 0xD06D713E30BEE3DEULL
        },
        {
            0x3FBA0229FA1A85B2ULL, 0xE3CFDE22692CE05CULL, 0xC4C9455C10267483ULL, 0xD7F108643A8C9B99ULL, 
            0xA4DC60A2EE702145ULL, 0xB408D0D5C7E6BDB1ULL, 0xC00B26FFD0B30A38ULL, 0x79D5BB4ECD82C6F2ULL, 
            0xD1DA620BB5D3C3FBULL, 0x6C1070C0836A0ABCULL, 0xEEE5AF4BDC54189CULL, 0x0848F97516C9B14EULL, 
            0xCA44F63513E41382ULL, 0x9C627D65E10911E9ULL, 0x39B11B36863895BCULL, 0x573EFE822E45B78FULL, 
            0xAC0B003ACCFC73BBULL, 0x0759FC4775386382ULL, 0x3E4161545C56CDA9ULL, 0x492B5CFD51890DD5ULL, 
            0xC96033A52B17E0D7ULL, 0x34ECA867CEAA8137ULL, 0x03B94F089A74AFD1ULL, 0x63FA638A84F9EA39ULL, 
            0x6932C572F38F92D0ULL, 0xFE9D4A27F1D117E9ULL, 0xE2FC5E188BEFC3BCULL, 0x75D6A3E0B4AC3466ULL, 
            0xFD331E344B0F4C39ULL, 0xE341218EA5C7CF08ULL, 0x368FC38B9A0D13DEULL, 0xD82B82783B02AA45ULL
        }
    },
    {
        {
            0x0498B58591660266ULL, 0x9051CB3361FB1691ULL, 0x99333CAB2D7902DCULL, 0xF6F9649E5A68A3C0ULL, 
            0xF61741D908234138ULL, 0x926C9B035BF7D47BULL, 0x0431B624F52CA4FAULL, 0xD03AA88087FCF01FULL, 
            0xF8B33CDAD0235320ULL, 0x8D52EB3EB519D7C0ULL, 0xF874253257F2B351ULL, 0x45985DC62C51AFCBULL, 
            0xAB7A9AF83AA791C9ULL, 0xE7FC16EB500E5B03ULL, 0xD33635160E1DFA2DULL, 0xE3070656A4851F9EULL, 
            0x1F30501773E8F708ULL, 0x71D9126600F2D6A8ULL, 0x740989898F00EB4CULL, 0x84AE4DF797FCDAE1ULL, 
            0x1F57679BDC643B91ULL, 0x7C83AEDE8E961321ULL, 0xAC0003E4EB4F289BULL, 0x42EB9DFC3E37606FULL, 
            0x6FFCC66CF5EEC086ULL, 0xDC4C4813EEC9ACB5ULL, 0x946F264F25A7B6A5ULL, 0x4E469CBA649608B3ULL, 
            0xAE8B2091E64412DDULL, 0xE1D105F39AB64CD9ULL, 0xB071CAF04B4C2A5EULL, 0x586B93303126FE23ULL
        },
        {
            0x9141D9F2DD8755BBULL, 0xA3159CC747D4ABDDULL, 0xB91A1B03A00CE636ULL, 0xC449E4A8A4B13BB1ULL, 
            0xAF5237D198C9048CULL, 0x41BC52FFD877B8C4ULL, 0xE08706045ACBB20AULL, 0xA1344951D6C62FDCULL, 
            0xFB585B7AD7E514C2ULL, 0xADCED75908846EE0ULL, 0xBFC14BB6A3961283ULL, 0xEA0FB05CC7BAA342ULL, 
            0xA23A6DCB837AD6FBULL, 0x1B5DF7A22CFADE24ULL, 0x42F41BE7AC7F870AULL, 0x59C2016D1061BDE1ULL, 
            0x82D46D7A966AFE4EULL, 0x6CE700626845851AULL, 0xBC757BE9771C4BC0ULL, 0x1D050DA3C716F06DULL, 
            0xF254D02281420AE7ULL, 0xAEF55176C8FAB542ULL, 0x970AC8188785F5D1ULL, 0x2483420286645FF5ULL, 
            0xA055BDF14E4C47B7ULL, 0xE2DEEA3933CFEE96ULL, 0x6766E6355D7BF617ULL, 0xBBA6652176D22AC0ULL, 
            0x9E5BC2B12B2D7F99ULL, 0x9BF1505CC70AE9C6ULL, 0xB13725E8C53024E6ULL, 0xAE71F8AA7181A808ULL
        },
        {
            0x73EF41846B9B678BULL, 0xEDE48FC54A068474ULL, 0x0066C5E264B0E01FULL, 0xEFEC1D73F30E3B7EULL, 
            0x4DCC26799448991FULL, 0x25BA31921B7F115CULL, 0x823D07E1CF54BC51ULL, 0x3C11EC5BA8DDDBF8ULL, 
            0x6A6900B3DAF54DD7ULL, 0x0439A7D75715D597ULL, 0xFC40F41865337A2CULL, 0x2CA1024EFEA8084CULL, 
            0xD72EB8413CF06267ULL, 0xD0D8B33CA636B13EULL, 0x1255DC75528046F4ULL, 0xB7DF3D05980727A6ULL, 
            0x6F1CF12CAF439535ULL, 0x7539F21E308E1B8CULL, 0x786F5BD0F54309D3ULL, 0x85E7BC225CC19B18ULL, 
            0x28C1B6F3FBFE47BAULL, 0xE0B98A903241315BULL, 0x8AF7B7C7B103293AULL, 0x9647EA7D8EE382DEULL, 
            0x1CE771931BCF8E6DULL, 0x4CE6CF9A5B67EFE2ULL, 0x39F603FB8C65EBA4ULL, 0x84D1E566BEBC41E0ULL, 
            0xE4C29C583DF14EE0ULL, 0xFA655AB8C56BEBEEULL, 0x2E38DC2BE92D465DULL, 0x857C17129EBB1AF2ULL
        },
        {
            0x2E147038D9CB1706ULL, 0xF99AA995DDC9F760ULL, 0x7FCCED6E4B013413ULL, 0x3BD35BF6C2B49C6CULL, 
            0x46831B909DCF8466ULL, 0x828CEF8FC014B6DBULL, 0xC8B2529A12955690ULL, 0x46E2B648C8F48F77ULL, 
            0x217E6882119941D8ULL, 0x998BB75B2AF8B13AULL, 0x7530E7CC01E742FDULL, 0x9DBE2C925233B928ULL, 
            0x7A752E46C1DFDFFBULL, 0x522F865B2B6C20E0ULL, 0x480B275FFD392B48ULL, 0xF3450BA527C96B4AULL, 
            0xC81C98EC36F8D011ULL, 0xED1703C3F30ABC79ULL, 0x04A61E9AB69D566AULL, 0x3E70FCD593C6F704ULL, 
            0x3F42C3E25B69655EULL, 0x6EC18CAB406ED66DULL, 0x510AD6C23364F617ULL, 0x83310DDC54265A4FULL, 
            0xD30EE9D16E257B19ULL, 0x4B6BA41A3474D33EULL, 0x4B84DC5DE82942CBULL, 0xC0B20A5EEEB6F547ULL, 
            0x493C7E632C3F0B15ULL, 0x33DD229987196FB3ULL, 0xBF32F288AF98F513ULL, 0xC0CD3D6ECF1EA2B8ULL
        },
        {
            0xEB769307770BAE28ULL, 0x417B4EF3125BDFE3ULL, 0x509B4CCB454DC4B9ULL, 0xDF64DF1F9146B3A4ULL, 
            0xBF34E45FB9FFA9A8ULL, 0xDA35E46B56598454ULL, 0x4A631196B4B0C80DULL, 0xFA46E9EE08DDCC1AULL, 
            0x780718D461A00B07ULL, 0xEEC1C56710299FF3ULL, 0xBD586A7030A24ED3ULL, 0xEC98E0F4BCB164BCULL, 
            0x2968B7B9066486B3ULL, 0x694B7903FE73EA47ULL, 0x5D93E53C8E384FA7ULL, 0x2CBE0C2C43B241E5ULL, 
            0x2DC435E9424BB2D6ULL, 0xB8D32D57524490A1ULL, 0x98676B1CF025F2B6ULL, 0x0F931A9AECF92708ULL, 
            0x83D2387BC48BCF7FULL, 0x1A93515EE99BD145ULL, 0xD005868CD42841A6ULL, 0x1949BF54B3275402ULL, 
            0x3C8930DD73F5D160ULL, 0xDD0D3EE366150FC3ULL, 0xCD2E5B350FDFA463ULL, 0x9A3B4957AE9E4F8CULL, 
            0x3CAE8AC304564A36ULL, 0x33E6D4692936D652ULL, 0xB758F6713EA84114ULL, 0x1B806ABF4E942B7FULL
        },
        {
            0x17505C872872EF99ULL, 0x04CA95F938CF9C41ULL, 0x69F5F3A7CA7AD755ULL, 0x05EAEB02D56E1083ULL, 
            0x004B3600ACB223A7ULL, 0x0098A3B2CEC9F23FULL, 0x9F8F1A3E9AA00E36ULL, 0x47FDC15560E4879CULL, 
            0x33291DD29DA038B8ULL, 0xAD52A23CE82FA1A2ULL, 0xEB15BA0E0A683AA8ULL, 0x45EF557695659687ULL, 
            0x4B5EB064765198BDULL, 0x88777CB3F3621EECULL, 0x7F575772F8712EAAULL, 0xD291D1A2E709871EULL, 
            0x85C4C15645CF287AULL, 0xE0B3D3DBCE379033ULL, 0x3F41610E59046934ULL, 0x9461CE2AE53AB957ULL, 
            0x38CDB2E8A1FB6390ULL, 0x7DB87D8D5FD23BA8ULL, 0x70F9C2E16109E04AULL, 0x3205B2137C29DEAEULL, 
            0x328E691E4AA7D32DULL, 0xC24FB121AC722769ULL, 0x26042406030121A5ULL, 0x5CCF95996980A4A7ULL, 
            0x59573F262C1470ACULL, 0x757E178B7C01B188ULL, 0x67AB7EE33DDB74EFULL, 0x0AB46695562D321FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseHConstants = {
    0x09F9BD347BA65A30ULL,
    0x4514FBA745603B2EULL,
    0xB0924393181D9D92ULL,
    0x09F9BD347BA65A30ULL,
    0x4514FBA745603B2EULL,
    0xB0924393181D9D92ULL,
    0x83ED9DD33BEB6C34ULL,
    0xD102BB3EAC5E900FULL,
    0x55,
    0xC1,
    0x31,
    0x12,
    0xF5,
    0x8A,
    0x45,
    0x79
};

