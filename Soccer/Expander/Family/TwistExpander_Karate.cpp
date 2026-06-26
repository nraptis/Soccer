#include "TwistExpander_Karate.hpp"
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

TwistExpander_Karate::TwistExpander_Karate()
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

void TwistExpander_Karate::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 9580245550357668601U;
        aCarry = 11228992514584451998U;
        aWandererA = 17154224242829543402U;
        aWandererB = 13882237661409641709U;
        aWandererC = 9565939054667934476U;
        aWandererD = 13100656030030609645U;
        aWandererE = 14141479500265711583U;
        aWandererF = 13608903482684359439U;
        aWandererG = 9545227600162205556U;
        aWandererH = 14693103353322830670U;
        aWandererI = 14599829889177112460U;
        aWandererJ = 11381172776960629924U;
        aWandererK = 13569119174361119101U;
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
    TwistExpander_Karate_Arx aArx;
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
    TwistExpander_Karate_Arx aKDF_A_BArx;
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
    TwistExpander_Karate_Arx aKDF_A_CArx;
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
    TwistExpander_Karate_Arx aKDF_A_DArx;
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

void TwistExpander_Karate::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 12236344424884480636U;
        aCarry = 10475836451773230577U;
        aWandererA = 12683589567063189115U;
        aWandererB = 12071275848585953124U;
        aWandererC = 16093584329272259656U;
        aWandererD = 17525203698973471949U;
        aWandererE = 16967629257251330538U;
        aWandererF = 16050556144596113735U;
        aWandererG = 16849861565422281455U;
        aWandererH = 16993874090265810724U;
        aWandererI = 15404758278546816840U;
        aWandererJ = 16865762423745915660U;
        aWandererK = 13150336543552932104U;
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
    TwistExpander_Karate_Arx aKDF_B_AArx;
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
    TwistExpander_Karate_Arx aKDF_B_BArx;
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
    TwistExpander_Karate_Arx aKDF_B_CArx;
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

void TwistExpander_Karate::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCB0CBEBA43DA0397ULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xB1249DAD02D63C68ULL;

    std::uint64_t aWandererA = 0x90F3733811CF3155ULL;
    std::uint64_t aWandererB = 0xC48108A4453DEAD7ULL;
    std::uint64_t aWandererC = 0xDCFD3DEB16A140ACULL;
    std::uint64_t aWandererD = 0x932100B62D7037A2ULL;
    std::uint64_t aWandererE = 0xC2DD8C38B82A0F70ULL;
    std::uint64_t aWandererF = 0xF0FC152EE09C43BDULL;
    std::uint64_t aWandererG = 0xB03CE251993A8EDBULL;
    std::uint64_t aWandererH = 0xA370C71EB138DAD6ULL;
    std::uint64_t aWandererI = 0xE1E77D2280F96B93ULL;
    std::uint64_t aWandererJ = 0xAAD6E17A68782006ULL;
    std::uint64_t aWandererK = 0x97381FF04404C1F5ULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB);
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistExpander_Karate_Arx aSeed_AArx;
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
    TwistExpander_Karate_Arx aSeed_BArx;
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
    TwistExpander_Karate_Arx aSeed_CArx;
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
    TwistExpander_Karate_Arx aSeed_DArx;
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
    TwistExpander_Karate_Arx aSeed_EArx;
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
    TwistExpander_Karate_Arx aSeed_FArx;
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
    TwistExpander_Karate_Arx aSeed_GArx;
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
    TwistExpander_Karate_Arx aGrow_AArx;
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
    TwistExpander_Karate_Arx aGrow_BArx;
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

void TwistExpander_Karate::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Karate::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 14649377756828041543U;
        aCarry = 17837772675176087479U;
        aWandererA = 12342107696905491401U;
        aWandererB = 14626924822487498593U;
        aWandererC = 13559412801324142826U;
        aWandererD = 15738664307545938868U;
        aWandererE = 10228787616002380964U;
        aWandererF = 10136203836796951196U;
        aWandererG = 10013700257052235958U;
        aWandererH = 12981734011754278254U;
        aWandererI = 11643457421581015590U;
        aWandererJ = 12305689930117371179U;
        aWandererK = 15113715427908724359U;
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
    TwistExpander_Karate_Arx aTwist_AArx;
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
    TwistExpander_Karate_Arx aTwist_BArx;
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
    TwistExpander_Karate_Arx aTwist_CArx;
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
    TwistExpander_Karate_Arx aTwist_DArx;
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
        TwistExpander_Karate_Arx aGrow_AArx;
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
        TwistExpander_Karate_Arx aGrow_BArx;
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

void TwistExpander_Karate::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 0, 1 with offsets 2617U, 963U, 7311U, 7500U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2617U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 963U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7311U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7500U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 3, 0 with offsets 2684U, 1307U, 7338U, 6472U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2684U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1307U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7338U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6472U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 2, 2 with offsets 3175U, 1291U, 3457U, 8076U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3175U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1291U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3457U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8076U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 1, 3 with offsets 5510U, 6891U, 6830U, 3066U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5510U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6891U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6830U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3066U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 0, 3 with offsets 1390U, 682U, 1021U, 1302U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1390U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 682U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1021U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1302U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 2, 0, 3 with offsets 599U, 831U, 1416U, 630U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 599U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 831U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1416U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 630U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 3, 2, 1 with offsets 297U, 156U, 1720U, 1617U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 297U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 156U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1720U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1617U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 1, 3, 0 with offsets 1037U, 1158U, 928U, 523U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1037U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1158U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 928U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 523U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1947U, 368U, 1870U, 978U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1947U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 368U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1870U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 978U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Karate::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 3, 0 with offsets 8072U, 5625U, 1582U, 4375U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8072U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5625U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1582U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4375U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 2 with offsets 4913U, 4587U, 1461U, 3594U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4913U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4587U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1461U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3594U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 1 with offsets 3622U, 1748U, 3902U, 4066U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3622U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1748U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3902U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4066U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 2, 3 with offsets 2157U, 136U, 2655U, 2008U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2157U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 136U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2655U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2008U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 2374U, 4415U, 5772U, 5144U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2374U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4415U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5772U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5144U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1799U, 1620U, 825U, 856U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1799U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1620U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 825U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 856U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 2010U, 261U, 1457U, 1885U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 2010U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 261U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1457U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1885U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1288U, 252U, 245U, 1881U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1288U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 252U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 245U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1881U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1566U, 1965U, 1985U, 60U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1566U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1965U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1985U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 60U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 2, 3 [0..<W_KEY]
        // offsets: 1086U, 1121U, 1963U, 505U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1086U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1121U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1963U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 505U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Karate::kPhaseASalts = {
    {
        {
            0xD4545F50717CA5F5ULL, 0xBEB0EEEBE0B34425ULL, 0x59E6D965AFFD347AULL, 0x9A8CF0E7DA3840B9ULL, 
            0x0D9AE834FAE7BF35ULL, 0x73FD9D06FEBB2539ULL, 0xBD97492CEAB19897ULL, 0xC6B33CD2B49C9DDEULL, 
            0xB4888A89ECE7BFFFULL, 0xFBD8B32139D406A7ULL, 0xFFFB756F422434D2ULL, 0x7D8B8E4ECBFB7113ULL, 
            0x331C0F56B0953150ULL, 0x7131C7064E4B3E1AULL, 0x19A49B48CFD8BF5CULL, 0xDEA22BEF7E013257ULL, 
            0x75722E366C7A198BULL, 0xCAE7231AAB0BF34BULL, 0xA86EF7947184E2E7ULL, 0x9E4A17256857B978ULL, 
            0x38C5D9FBCD5AC901ULL, 0xA56208BC02D60D08ULL, 0x9EF07F6961F232ABULL, 0x2190220D8040AF38ULL, 
            0xC198E8658433A0B0ULL, 0xA6BAE311AA82B2A5ULL, 0x1DA44D37708904BBULL, 0xF11B03B91A8B0B6AULL, 
            0x27A929D008FB57B7ULL, 0x63D175C0A12949B3ULL, 0x7C887617A4977B52ULL, 0x106D44E95AC42DBFULL
        },
        {
            0xB0A20CD37E18B9F2ULL, 0x2C0DD4983BBF8941ULL, 0x16C4D03863C3424CULL, 0x96277538FD15D549ULL, 
            0x46258C98BC6A3607ULL, 0x683F30C4F3606047ULL, 0xB21106EFA7429BA2ULL, 0x1BF72D38FC359112ULL, 
            0x15180CB8D9E33CA3ULL, 0xB0E119D418B19E94ULL, 0xEE02DE3FC75A991FULL, 0xDCF543E97B863E0FULL, 
            0x4DDAD050139B1509ULL, 0xC6D1116D71C6A9A2ULL, 0x5173E564CBB4FAABULL, 0x832D0312E91F4EE5ULL, 
            0xAB650D3D60C68254ULL, 0xF2EEA1ED900ABDADULL, 0xFFD5CD5684BFC793ULL, 0xDE55CD75E37F249CULL, 
            0xDB14152D3BDF551AULL, 0x5C5669A4DF234BCFULL, 0x47659981BE5E31FDULL, 0xEC8FF1DD09E9FA8DULL, 
            0xC7A386A288E04537ULL, 0xC8DC442CB7EC83DCULL, 0xBB2C4691D4D670BCULL, 0xE2F5375FFE7493A2ULL, 
            0x517BB4D85D3FCD22ULL, 0xC707DD5D0A61B396ULL, 0x68A08246693EBC14ULL, 0x6C0001E3C0483B9EULL
        },
        {
            0xE9C86969FD1C61DDULL, 0x124AC6450DDA5515ULL, 0x9C1632251214BDCBULL, 0x15CA701C2627E426ULL, 
            0x12B9B36E06B397D3ULL, 0xE94DED26E3A2F1EBULL, 0xC27BB7A80792D352ULL, 0xC6128B2D00C928ADULL, 
            0x5A21E5861B43F026ULL, 0x27D4A92A369871F2ULL, 0x97FFEF99FE069658ULL, 0xDD6E1D60A9765439ULL, 
            0xD4A81F584F8EB911ULL, 0xD9D250D859FA5B3AULL, 0x5FD56A314A5A5626ULL, 0x3D836A1A459F3952ULL, 
            0xFEBADB76C39A09ABULL, 0xE777E18E8CA0F0F2ULL, 0xD1428A5360F34EB5ULL, 0xF4BA38E5A8854B87ULL, 
            0xB27C7232C1E17E07ULL, 0x8C31FBBB234E43D8ULL, 0x3DA82DC9F52A955EULL, 0xE022C60F08180DA4ULL, 
            0x8EB146874F8156A0ULL, 0x71F5C8276BDB314FULL, 0x103DDAED57A20D0DULL, 0xCF8D7A1451C95ACBULL, 
            0x35F67EFFA1661779ULL, 0xACB549C20FE467CDULL, 0xCBEE2F2A7158C8CDULL, 0x9F49AE65DC004AD1ULL
        },
        {
            0x6A419B3F4756DA11ULL, 0xDBE5FC3717C2F43BULL, 0x315BCA995BCDC558ULL, 0x4DA6D026ED86648DULL, 
            0x44F565426D78DC71ULL, 0xB6376DE3B9CE8F10ULL, 0x55E01DBE1C295D05ULL, 0x7CA92BBFDB2683E7ULL, 
            0xFDD244E8383CB04EULL, 0x786F7AEEDD7688FBULL, 0xB72DB40FF9A84ABDULL, 0x07093885732A3BD5ULL, 
            0xF8CD69101CA3CEDDULL, 0x62B7632ABB74082AULL, 0x2B837E7E3C4366F8ULL, 0xE1D532007C62DC9DULL, 
            0x81E41B8DAF564CCAULL, 0x2BA351867C6DB7BDULL, 0xF32C5B526C82FA64ULL, 0xC2F74D29CF96F392ULL, 
            0xDEDD4475BA2E1163ULL, 0xA1E129C33903464FULL, 0xF57F1310E2AA2A30ULL, 0x939CC72CD2F6D37FULL, 
            0x0AABFBC68E735293ULL, 0x8D49256A41CC701DULL, 0x65ABDE65C119F039ULL, 0x9C9DE82F82C6EA98ULL, 
            0xD4C215F1D6375697ULL, 0x7FDACEADB83A5019ULL, 0xD33A2D90BA3E31E6ULL, 0x34C72C398F94FC87ULL
        },
        {
            0x79138D2633EE7AE8ULL, 0xFDCCDD15D65895A4ULL, 0x6042F5C9EDE6D489ULL, 0x77A6478E4D24CD7DULL, 
            0x249E76295F2FC146ULL, 0x663D1F9633AB18F3ULL, 0xEDE19C608CF3D3E6ULL, 0xF5E53D66EE6A5D2FULL, 
            0xC70A2258DBF62FE0ULL, 0x2FAFA4E042C00DA7ULL, 0x06A92C3C2CABC39AULL, 0xB70DC38B066EADD9ULL, 
            0xD314CBD1F14FC0B9ULL, 0x219F098DAAE0B948ULL, 0xF1F9173CBA3F3054ULL, 0x48190E7BFA61F18BULL, 
            0x105355ECED9762E6ULL, 0xCB0FE2B18DCD733CULL, 0x1A15B95E4379C2F1ULL, 0xB081E8E2CF7BF24BULL, 
            0x60FCCD3751D08955ULL, 0x23822BD43E1F94B9ULL, 0xED7A25A7C834FC89ULL, 0x412DD8EABF334EFBULL, 
            0xA8B8E285FCE65585ULL, 0x85709E68C13A5AE8ULL, 0x96A8C09CEA729BD1ULL, 0x1BC8B0DAAE45440EULL, 
            0xB4E3C90AA2CFC31FULL, 0x057AA93F09D31EE6ULL, 0x192B80398CF8126EULL, 0x2EE9EE8A3783BEAFULL
        },
        {
            0x0C203A62F34C989CULL, 0xB6FA25C3764F2025ULL, 0x37C4D8080ECCC341ULL, 0x3C30072BBC1601FBULL, 
            0x64ED91B3042B04C0ULL, 0xD44254D03FB3220FULL, 0xF770551B08DAA666ULL, 0x92337DE62EAA32AAULL, 
            0x36AC0BB8D4B3F157ULL, 0x60A2ED6D147737E2ULL, 0xFD6350EB2F2E1FE4ULL, 0x601C708EAF77F90AULL, 
            0xB2005B00198733DDULL, 0xB36C31668F6D6E8BULL, 0xFCCB1E5F2E9F2F3BULL, 0x18A71A928E8B45F8ULL, 
            0x014090CEDC3F88BEULL, 0xB39E4590DD1DD014ULL, 0xC6A0F3BE5E0F1D8EULL, 0xC07D6372288618F3ULL, 
            0xC103393B68FF2F01ULL, 0x6D3ED7A02FC53C4BULL, 0xB31F8B73107DD0CEULL, 0xAF1EF9C11274362AULL, 
            0x1DA955EBFC858022ULL, 0x0F29FCA3E5984800ULL, 0x5AF7A584C176CAD7ULL, 0x16D9B2FCF070D1D0ULL, 
            0xB809BF441E33A17EULL, 0xDB043FE1D4A314BBULL, 0x4F7594F726438D8EULL, 0xED1F0585678F3B6FULL
        }
    },
    {
        {
            0xFC1FE646AD7CF21EULL, 0x7C78F1B7036F6521ULL, 0xF9F25D4C747CABE2ULL, 0x0F799AA0DB84B913ULL, 
            0x6112F4098B288837ULL, 0x7C247F5741DBA7C7ULL, 0x80616F73B5CA666FULL, 0xFB2188A389438AB0ULL, 
            0x48C596386D332B64ULL, 0x7F299DCA76E06113ULL, 0x5B548BA6A05FC3E5ULL, 0x3CFCF72EE25B13B7ULL, 
            0x66A313BF40C9AB22ULL, 0x025FB04CAA2C9C72ULL, 0x500228CF2F7C25F5ULL, 0xEC1399742B847F68ULL, 
            0x94C1FC7AE849388BULL, 0x85C1CBF386E09F4EULL, 0xBB6701B5FC6640A0ULL, 0x94D06975084EB26DULL, 
            0x916EBCD254638B41ULL, 0xA80581E29DE3DA5FULL, 0x3CB89A124F043FBEULL, 0x42516D70F7DA3B74ULL, 
            0x8FA9E5DFB4C9B036ULL, 0xBD7369134C7FEB34ULL, 0x2EE21142B06BE950ULL, 0xD39ACC1AFDDD655AULL, 
            0x9CAD86F6475E25AFULL, 0xF0E1BAC63831B85AULL, 0x40D4C86CE81DC012ULL, 0x3DC733F7BD281736ULL
        },
        {
            0xC4525F35D89C8D59ULL, 0x15C4EA41FA0EA4C9ULL, 0x75B65845DF2E1982ULL, 0xEE8FF5AA17AC380CULL, 
            0xF28661B5001370DFULL, 0x3CDC4422DF68C9C8ULL, 0x32301AC10E22FD28ULL, 0x1522CFE31B400396ULL, 
            0x0FC713EEA5338BDAULL, 0x099620D2DC7F94B7ULL, 0xCFF683FAB97073BBULL, 0xCCEC8A96D6AA3CE4ULL, 
            0xECF0A50F78C6B496ULL, 0x6F45689587C2198EULL, 0x74D458D20331760FULL, 0xB44D2E6DABE17109ULL, 
            0xBAEC12275B4DF77CULL, 0x72A46FBEE83254BCULL, 0xA39FA9A321BFE30FULL, 0x6E62F32F103EF465ULL, 
            0x5015F5578723E90DULL, 0x5DE9EC575D893039ULL, 0x6B4A54B738A03761ULL, 0xAFFB70BE72E2DE07ULL, 
            0xFD239FE2F733FD1EULL, 0x5EBCF972734BF3CFULL, 0xD7843315EF260E50ULL, 0x7CE3DF10D1F0F7EFULL, 
            0x3E11D2D126B1C5DAULL, 0x7E3367828E28D577ULL, 0x6AD6D700FB588D57ULL, 0xD6D44EFF87DFC862ULL
        },
        {
            0x6E89ED9B2E3C6BFFULL, 0x8FE95F6A4F50016FULL, 0x4F7EE7F698C70C6EULL, 0xB315BE300C409721ULL, 
            0xA72964F6007F271FULL, 0x50C7AC2953AD29C5ULL, 0xB5DAB546F7784096ULL, 0xC683479A611E5739ULL, 
            0xF67169733735EEBFULL, 0xD483482D00D4FFDEULL, 0x7BBE33AE6CA6BF8FULL, 0x5F4AC534E425C6A9ULL, 
            0xE33BC7040FE01AEEULL, 0xEEEB037C584DD491ULL, 0x84C06EAA8E67B1A3ULL, 0x7D4DA8E6BF7D7791ULL, 
            0x55D2B457F48897D2ULL, 0xDBB8F647EA7C796EULL, 0x717A1D06777094A3ULL, 0xDE864E5A716AA5ECULL, 
            0x09169D4D257F39A7ULL, 0x451A35B8D8747E15ULL, 0x7183AB39FF863F28ULL, 0x9ED1CC9AC5E5B469ULL, 
            0x9F0851740814A598ULL, 0x5FAA121B7EB8A125ULL, 0xFFFE01D4FF73D92BULL, 0x27ACEB8448398BA6ULL, 
            0x941AF49243FCEFF3ULL, 0x11CE5CAE9640CC92ULL, 0x58AC6C5FE294C91FULL, 0xEC18D09B9C39842CULL
        },
        {
            0x6E1A801698C27908ULL, 0x542A43253BFC6FC0ULL, 0xA16304414A9EB325ULL, 0x85A62CC441CEDF09ULL, 
            0x91FFD8E062FF8EE7ULL, 0x1FB3E70F24F96E58ULL, 0x4F11865E632025B7ULL, 0xCF1461208BF82479ULL, 
            0xE351588A7FA6D423ULL, 0xFF53DE12322FB73CULL, 0x10482078233621EDULL, 0x152DB18F08A3F76FULL, 
            0x5BCCC607F599DAB7ULL, 0x657BE4DD259B919CULL, 0x1DF35BACC9321B7FULL, 0x285E376AB51E4383ULL, 
            0xF1FF3FAB967E37D7ULL, 0x6E1C84FDB42870DFULL, 0x61EAB827B75B50C7ULL, 0x6086957978D7CB40ULL, 
            0x6E0FB574F0565646ULL, 0x9D3540C5A6D7EA47ULL, 0x2324FB32C920F6F3ULL, 0x2F32439C34522D3BULL, 
            0x08E5BCA97F65ABFFULL, 0x333054EB0D7B5BCEULL, 0xE55C41A172DC1DF1ULL, 0xA4A98E69F6617126ULL, 
            0xE59BFC5C7B8140DEULL, 0xACFCA5A8720042C0ULL, 0x4B46D3A663949012ULL, 0x813EC73AA8EA1F00ULL
        },
        {
            0x61CF06BFC6C62653ULL, 0x06D5AD67520A0FDFULL, 0x29A5FF2A615B86CDULL, 0x0EF291F09FC3A54BULL, 
            0xAD916B840897CEB3ULL, 0x02AC8A65B0C043B4ULL, 0xE4E2F011FE2D9D54ULL, 0x58E7900891A70129ULL, 
            0x9DAFDD9C0686300FULL, 0x524DCBF1D382AFBDULL, 0xD3381CD14F010F76ULL, 0xBA1742E7A2CFC9D0ULL, 
            0xAC1DA61429EC5F36ULL, 0xD18C9053F47FC560ULL, 0x98A7C9D99E670CCCULL, 0xEF5D90C52E2BAF9FULL, 
            0xBF4224C93975D067ULL, 0x04C61D73F435335BULL, 0x46D5AFE129BF24CCULL, 0xD2B502D3B7EEEAD1ULL, 
            0x6B041276F3D37FEBULL, 0x318BAF81C360BD23ULL, 0x48FEA8ED3D4AB4C5ULL, 0x790A4783B371E372ULL, 
            0xF0A820A8BE9204A5ULL, 0x38080228EC5D34EFULL, 0xA4E279235DF289BDULL, 0xE7D95F1DB4EEC0B4ULL, 
            0x27AEEAFDFF63D0F4ULL, 0x876B3C0DA71D4DE4ULL, 0xF9BE80DA378B012EULL, 0x2302CC978615DB93ULL
        },
        {
            0xF919812F6B9DC8F2ULL, 0x3A4CB5649DA093C6ULL, 0xF12B282629C1659BULL, 0xFACF3C18D542D689ULL, 
            0xB951878317C0E904ULL, 0x3291CC7900E6B15AULL, 0x3B4D59E61BADC386ULL, 0x3B70BF6193CF94D6ULL, 
            0x37225E5A837E31CFULL, 0x33EDD78E67B02E98ULL, 0xB72C36963B8FB734ULL, 0x62C4235E11F67624ULL, 
            0x3B4FBE1134BEE623ULL, 0xAB657C005BBE4D3CULL, 0x98C2A183B798AD28ULL, 0xD2C8B132E1DCE5D3ULL, 
            0x539DCA6AB2C9D207ULL, 0xA83808172F1A384CULL, 0x1B1525DFF4FE1EBDULL, 0xF0259F028FBFCCFDULL, 
            0x00D764600B73C850ULL, 0xB94E71FE75DFF92CULL, 0x81B667EC6D56B3CBULL, 0x9707DD9245AFE836ULL, 
            0xFE80F6A43ECB59DDULL, 0x84CF249A92EA2B74ULL, 0xDB79109D6533FCA2ULL, 0x022F97967208D4F7ULL, 
            0xEC2BC975FDB7E31AULL, 0xCF772733686BC308ULL, 0x5A30BFCCF3708A5FULL, 0x5C580AE615AB161BULL
        }
    },
    {
        {
            0x73BFE09C4DB990B3ULL, 0xA439DBE3667431ACULL, 0xAE32D4E95CA5F131ULL, 0x65C711BE815D0820ULL, 
            0x7AA08F8B16F23ABBULL, 0x7F554D8C03AE343CULL, 0xAC2D2BDFCB4EE118ULL, 0xB6002F2D7F75CF41ULL, 
            0x34B4E38F416A57C1ULL, 0xC8D975FFF8185B50ULL, 0xE3C647FF8EFFA878ULL, 0x85F32D4B6FACB0F1ULL, 
            0xAC27B9443130ECB8ULL, 0x5D0F759E8D8255FDULL, 0xB2CE7FF782086C82ULL, 0x3829353F8CB06389ULL, 
            0x3664C6C8E0989352ULL, 0x40BAC8ED7FEE8F6EULL, 0xE08806753585D62AULL, 0x6111344467C80AF1ULL, 
            0xFE611BBE4664B410ULL, 0x46093B593ECF3BA3ULL, 0x381D115D006750F6ULL, 0x03316BEF41822F3BULL, 
            0x052B50587AEEE428ULL, 0xC04FB434DD7A969FULL, 0x9EE82067FF01E6D4ULL, 0xF08F3E637B3FC32AULL, 
            0x28637EC7D10B68AAULL, 0xBB02601B63EBF5D8ULL, 0x6119762720EE394EULL, 0x4AB19B641547AB67ULL
        },
        {
            0x34F0992B48DEAEC9ULL, 0x78221FA412847ED5ULL, 0x7F542FD7CD3D7B6FULL, 0x95EABFBFA5EAD57FULL, 
            0x4956FAE260662615ULL, 0x120857844097B7C7ULL, 0xDE0CC7F940D51824ULL, 0xEE4C04AA8C434771ULL, 
            0x372562F02C1A591BULL, 0x5C366F736ECC9DE9ULL, 0xA5D142670F9029ABULL, 0x15AE4E4BFE0C56A9ULL, 
            0x743F4B6DB0729C2EULL, 0x731B02C9EFD7BFF1ULL, 0xABCFD8919D683300ULL, 0x7B91F9DC82D4759FULL, 
            0xC8D9EE26A24770AEULL, 0x275939D4EDD2FFB2ULL, 0x0017DD4EA9D7E016ULL, 0x2DF510C1D3AF7EE9ULL, 
            0x8AF59DB0B796FFDAULL, 0xBCDDC4EA987FE8E2ULL, 0x34BDEA25DE002021ULL, 0xFA03E5AFB47736F4ULL, 
            0x01C4FB00836C6486ULL, 0xCEC6BC8284FAB52FULL, 0x520EC1D036D8715CULL, 0x7F8465F97FFA7D34ULL, 
            0x0C3FCA084FD51A4AULL, 0xAC84F37A0B2726FAULL, 0x4DDDCD5307E290F5ULL, 0x06AC700B26338CEFULL
        },
        {
            0xDBD77733C7D66BB5ULL, 0xB2CFC7D2A6C5514BULL, 0x4641A2CE7CF49A51ULL, 0x4040C59468088F59ULL, 
            0x1B09C91E32D6791EULL, 0xF76C8DEB5E6C51E7ULL, 0x9BE8243CF2FFE61AULL, 0x7195B7147C24DE13ULL, 
            0x2344D772F6DFB90CULL, 0xA7BA57A8E803802DULL, 0x0EF35585D025BBACULL, 0x4E29BE49A2BA0F64ULL, 
            0x407DBB3968F5226CULL, 0x11DDC963B214967BULL, 0xEF514E50153059EDULL, 0xAD49820A91AD90F8ULL, 
            0x33062FC9CEC794C9ULL, 0x341A3648C9305C6FULL, 0x71761C53560EA83BULL, 0xEF70EBFE4F6CF63EULL, 
            0x016BFA42681F5202ULL, 0x3C237C45A598B20CULL, 0x429681E81D254588ULL, 0x35B3025BB2FBDA99ULL, 
            0xF9857BD00C2660F8ULL, 0x3CD495AEF2BF53D7ULL, 0x50D9C5515DEEB1E2ULL, 0xFB4A09BC8A517D09ULL, 
            0x9697D08F199EEC56ULL, 0x3D6B018267ADF600ULL, 0xB44F3235A5D0F910ULL, 0x07711B0F53DCF5FCULL
        },
        {
            0xCCADFF0853CA9C12ULL, 0x6E1FAF5D1935DFF5ULL, 0x09FE67DC483A380FULL, 0x0E193662DCA72F06ULL, 
            0x616F2A80B6F130F9ULL, 0x68ABA2CF8C79A566ULL, 0x64697AF7A0CF6E8DULL, 0x5E5F46604BBCAD0AULL, 
            0xF87F27693BB6AF55ULL, 0x4046016B10ABE573ULL, 0x0DEA3621120EAC1FULL, 0x4B25D26F14EC725FULL, 
            0x590BD9E3600BC81CULL, 0xA609467D8B27101EULL, 0x3796A88DEFDC5913ULL, 0x5AA39B6FAD0C6745ULL, 
            0x1CCD01590502F925ULL, 0x75A1FFAA4B63CF39ULL, 0x83F6DE98FDD73B15ULL, 0x971393B9167E06FCULL, 
            0xF5E95E231155C226ULL, 0x76FA78D5F0D5D284ULL, 0x331882824159723EULL, 0x234C9C6985B40078ULL, 
            0x8A96E375FABD949AULL, 0x18D3E5111F639C43ULL, 0x677CFB7A4B68BA2BULL, 0xF48AB000D327DB85ULL, 
            0xD0C030857986C676ULL, 0xD429BCC0F0BC4499ULL, 0x24DB439A5A66595FULL, 0x684F4B681C34402FULL
        },
        {
            0x2880B9F76970633CULL, 0xE37D58F4B9DE24C2ULL, 0xDCBBC6DAD2A0CCA4ULL, 0x27104B73517E4F82ULL, 
            0x0E687E965F3328E5ULL, 0x695B89CD4ABB7F42ULL, 0x407954A110207D5BULL, 0x6C275DB56B99562BULL, 
            0xEBA8AC200285A6DDULL, 0x6DB155822B475448ULL, 0x3110385A30B3AAEBULL, 0x3BE3F10EA17B0705ULL, 
            0x05ADBD05FD2A82F0ULL, 0x606BA2791B92B3F5ULL, 0x39CF44CE6E4241A9ULL, 0x0156C02F833282F8ULL, 
            0x7722242191E35292ULL, 0xEDD173DD60CA12FAULL, 0x9B94B6373378C06CULL, 0xC97ACC935DB2CA3DULL, 
            0xAA15ADC3FD9E418CULL, 0x0E405C1E4E1C687FULL, 0xDDB95F9BBCA8CE52ULL, 0x319BAAA07876E3CBULL, 
            0x936215A1E97936E7ULL, 0xEB08C2E2E2F8609DULL, 0xF3C66D29C1B98AF3ULL, 0x0B8068ADE6322A6FULL, 
            0xFA8FC5FC26701774ULL, 0x24E41AB3E9BFA522ULL, 0x894B245A63A0802DULL, 0x689342A5E9D4796EULL
        },
        {
            0x6EDC4EB9B0F15290ULL, 0xF12E25B155809E48ULL, 0xAD503C1C653FCE09ULL, 0xDCD836FB02946AA1ULL, 
            0x9E6EAA151467FA4DULL, 0x28F1E54A85D5E877ULL, 0x1F6D3A25A3D2629CULL, 0xF9179BC250CB6885ULL, 
            0x6754518694F5F055ULL, 0xD4960529E2B097C5ULL, 0xBD98CA8D63F3DE6CULL, 0x3826BC562C0F3958ULL, 
            0xF35424B552C1A9C2ULL, 0x1F498D7DB3309FF3ULL, 0x3B3811283B6CB939ULL, 0x731D1AEB245B2705ULL, 
            0x6107A274A75B1EEEULL, 0x56E13001073D94E1ULL, 0x719705095B9AFB5DULL, 0x0A1D6A29D1FFA653ULL, 
            0xE1F0425DDF99A74AULL, 0x3F3E828095989B9CULL, 0xCE410E818F961B3DULL, 0x4185640E1A8E73A6ULL, 
            0x3072D4D7FF7B6EB7ULL, 0x9A411244613525AAULL, 0x10635A18BCE81513ULL, 0x729E3E643664FF75ULL, 
            0x63007433E3187EAAULL, 0xBB8A01192DD3A6CCULL, 0x5A653B863F492880ULL, 0xBCED2E793BB5E6BBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseAConstants = {
    0xCF47C5D4EEB73601ULL,
    0xC5B8B3205C518EB6ULL,
    0x4D635E9D2742D70AULL,
    0xCF47C5D4EEB73601ULL,
    0xC5B8B3205C518EB6ULL,
    0x4D635E9D2742D70AULL,
    0x5DB247C42552769CULL,
    0x56D4859EC520F0F4ULL,
    0xEF,
    0x93,
    0xF1,
    0xAA,
    0x37,
    0x85,
    0x3D,
    0xF9
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseBSalts = {
    {
        {
            0x70FDB06F43554C7BULL, 0x58438EECD042D857ULL, 0xD10D8CFC90E8CB1EULL, 0x2FD749133CA2D18BULL, 
            0xE69C52D00612ED42ULL, 0x926EEF36EC9CBD87ULL, 0xD3400B1C16B58B66ULL, 0x24AC4D3507912075ULL, 
            0xBE5C007ACD6EA687ULL, 0x6E459278F006E7E0ULL, 0xD6BA1C03A831B02EULL, 0xB28D5C22AC98CDC4ULL, 
            0x446E0F4E9BE78298ULL, 0x7D2033B514401AE6ULL, 0x097E9A4E750FC05EULL, 0x008CAF421A3456FAULL, 
            0x2DAB9B461D68B6C7ULL, 0x5E4136986A22CDDFULL, 0x5320E55B1A114137ULL, 0x25E8D2C9C67E3796ULL, 
            0xDF2256C49A804D00ULL, 0x05C96FF0A2530300ULL, 0x4558DD2008485054ULL, 0x279BF0AD08805A1AULL, 
            0xDE2B89EE3E60A9D8ULL, 0xE51B41BDCB376015ULL, 0x2A751EBC96E4850BULL, 0xEDAE1A79E0FF8A23ULL, 
            0x61170D0BCC7AC019ULL, 0x281B659F5265E596ULL, 0x9C93019828F7A3A0ULL, 0x50ACB3921868795AULL
        },
        {
            0x8B8387FC6B967815ULL, 0x9996AE95588B2087ULL, 0xA7E6F2D2E83F3EDBULL, 0x18C8E2195E12E784ULL, 
            0xDBE1D050171A4FACULL, 0xF5EFA33B7B77F302ULL, 0xC67789C9C4326BD2ULL, 0x4AEE1BEC2FA6C9ADULL, 
            0x71B7972BB011116BULL, 0x70A54B7A2799CF99ULL, 0xCE635C2196B63FEBULL, 0x91E5BDA1E57F4A41ULL, 
            0xE9082818A68BCFEDULL, 0x59C2D93D095EFD1DULL, 0x6044C377EDBCB938ULL, 0xC8BC38C4C111A772ULL, 
            0xD7AF6370A36B7EF3ULL, 0xBC531381DF3B6B97ULL, 0x9E6922D85AC75CBBULL, 0x1213C4EC489BD5F1ULL, 
            0xAC25386E937516AEULL, 0xC82DBF0FA888ADC4ULL, 0x8AF9DB980F4B1076ULL, 0xA6B26338EFFF2A34ULL, 
            0x25CE22B269A3D2A3ULL, 0xB92D11A7BF87C80EULL, 0xE143591F52124272ULL, 0x9F4940F4D47190C8ULL, 
            0x5D42A0135DF9A489ULL, 0x6E1DFCEBFEA97894ULL, 0x30B21AFDCA430B78ULL, 0xFE0A1B27D987DB2AULL
        },
        {
            0x26D634484C24F42CULL, 0x383942FCE9CE9A82ULL, 0xA172D25E84F2D9E7ULL, 0xB7084EE36327E25FULL, 
            0x4C9D7BB90DD11FF0ULL, 0xC534A32F75C3765CULL, 0x4F3C22C222F071E4ULL, 0x58CE8468E76FB955ULL, 
            0xDE084ADFEA895DA9ULL, 0x8F24072AB2D78146ULL, 0x562E59E48885BB0DULL, 0x21E4FF358F2905D3ULL, 
            0x5D0E1563279CD272ULL, 0x625FD21038C9782FULL, 0xF5AE1FE1EBE9322EULL, 0xF0C36EB7E39EB2A4ULL, 
            0xC275A72FD69A48EEULL, 0x90B19B4F4363DE41ULL, 0x9D3C98FB91C912E0ULL, 0x3141633A8A0622FBULL, 
            0x56521DDA03227DA4ULL, 0x2D62C9C936F06DB7ULL, 0xD4998D93E31F249EULL, 0x483CBFB68CA6636BULL, 
            0xF718817087BD60A3ULL, 0x09EB42C937015C75ULL, 0x35A0072EC678BC6DULL, 0x46B533AB8CB561FAULL, 
            0xDAB2361324688071ULL, 0x51803ED169DE07ABULL, 0xEC89FF75D1609159ULL, 0x392C094A9A0A1E9BULL
        },
        {
            0xDD3831100015AF56ULL, 0xC79D2BF4E5AB392DULL, 0x566A78A5456BF6FDULL, 0xBE3BC9CC9DDB18A9ULL, 
            0x77163609BE653A4CULL, 0xEF907F90FB234D3FULL, 0xEA83AB2FA41EDFA2ULL, 0x01E0F0180ACCAD9EULL, 
            0x15C3FFE1E1946117ULL, 0x36847FDE090707ADULL, 0x9A3755C194003BA1ULL, 0xE0D583708F58FC40ULL, 
            0x2D70EBBB4E486F17ULL, 0x691DB35DE92E53C6ULL, 0x3DAE72F5895E7B2DULL, 0x44249D4C8241DF21ULL, 
            0xBE38CEFD66608038ULL, 0xC5B33A3269931AF9ULL, 0x584C0E6BADE1E87AULL, 0xE69694A780928C23ULL, 
            0xC37069D0C6758D5EULL, 0x2147A3ADD8F67AD1ULL, 0xB9ED0072A687FC9DULL, 0xB323E21CF9B44E3FULL, 
            0xCA2A17FA7EA68240ULL, 0x349567F5D127DC77ULL, 0xCDD140A93F7B6D01ULL, 0x6F33C5F01595F251ULL, 
            0xB5087D86BB0D7FFBULL, 0xA759AC31291ECEEBULL, 0x8B26D4F643D6D53DULL, 0x9654F84F4F3B7255ULL
        },
        {
            0x6DD7D6F5C6C8173DULL, 0x8F15759DF1F6F06DULL, 0xBCA732016D7A7D3EULL, 0x4DD758AA51DE6BDDULL, 
            0x387B8FF6710D9DCDULL, 0x9B3CB526C98434A5ULL, 0xCBAE8F47F1946DFDULL, 0x32FFDA53A2B3B1F6ULL, 
            0xD7011F3100DAD7AAULL, 0x64E12C7AB6D5A536ULL, 0xC6D316BE303DA282ULL, 0x1FFDD246EA329772ULL, 
            0x9BB37EDA0ADF439FULL, 0x4A794F30B0469D39ULL, 0x8B718CA84EAE88A7ULL, 0x03E104166CB1CDA7ULL, 
            0x90934FFF9C53B0EAULL, 0x80FEE54CB8266FFCULL, 0x21044D062A8F9690ULL, 0x6966FC6CA6400CD0ULL, 
            0x395BA2F41A44FC08ULL, 0x0C1022913CB34F8DULL, 0xD7CA7C6B4D8DC311ULL, 0x7F482F52B92A3FBDULL, 
            0x87A37A4DF180F002ULL, 0xBBF2EE839C0EA6F2ULL, 0x7FBB60C9560995A1ULL, 0x220DE8DFD4086751ULL, 
            0x52093F29CCF41B2EULL, 0x2898AB9FCF5C36A7ULL, 0x358E50669F1026F3ULL, 0x6EB577A01BA5FF68ULL
        },
        {
            0xD8DBFE115194D77FULL, 0x476D0778CEE24474ULL, 0x62612A045BD35A0CULL, 0x05A7FA8A90169514ULL, 
            0x99320B56D4C08F8DULL, 0x1B8382077A49CD1BULL, 0xDF61C722CAA14578ULL, 0xE8225962C25AAAA0ULL, 
            0x36DE5F4509FCB730ULL, 0xED5B09D32CC14154ULL, 0xAEE01FC78F3AB83BULL, 0x8D3319908CC001C8ULL, 
            0x47A7083119059405ULL, 0x277E488F800C555AULL, 0x29E3A53353A37405ULL, 0xE5D419F6EBFC6989ULL, 
            0xB7C1267CDD5584B7ULL, 0xF239349BAD23AD34ULL, 0xD09C3993E0B1F830ULL, 0x395F6189D6B2B76AULL, 
            0x12136AD6317515EDULL, 0xE063A8FA32BB8194ULL, 0x83156FACC01D84EFULL, 0x9625AE983BEF10BFULL, 
            0x4F0F600108E8A4BEULL, 0xA8AEDB2314D47683ULL, 0x0F2EBD162DA42CFBULL, 0x01E040F93D1A8BCFULL, 
            0x1EF0FB7A7A6A4C98ULL, 0x11432043E7EF433BULL, 0x12A56DD7E85361D6ULL, 0xB9EE101A1A9577BBULL
        }
    },
    {
        {
            0x00C8DCC4C79D4460ULL, 0x60CEA1BAC45292FDULL, 0xA5952D54272CED47ULL, 0x9E102F79D7506606ULL, 
            0xEEAF293CD14F4F0CULL, 0xD3D1868423FDBE76ULL, 0x6A8237AC2BA9C347ULL, 0x559057083AE863FDULL, 
            0x3F40D0C8409DAFA3ULL, 0xF457313CB4A720C4ULL, 0x79F8C2317BF41CC2ULL, 0x37FDA0F9C1E23B01ULL, 
            0xDD38CC41307F8F2DULL, 0x4D57B7606E95FCC6ULL, 0x09388B29C88464E8ULL, 0xC74A98CBEFE93A07ULL, 
            0xF7121180477B8FB6ULL, 0x014BE7DAD866B3EDULL, 0x61C5DBF268904F17ULL, 0x4627A93FD39A0436ULL, 
            0xD88ACA04919A0225ULL, 0x6A45D6825F56E97EULL, 0x33D4580BA911A743ULL, 0xF4387D1C6B47878CULL, 
            0x3BC741E813050113ULL, 0xA1EF8036BA9C7EEEULL, 0xD3D5BDB7DBC27230ULL, 0xDD75247647D45549ULL, 
            0xF9307318FF4B8267ULL, 0x8D2C4507A10AC0EFULL, 0x76002059235593DBULL, 0x6A3F98DA04C9EC88ULL
        },
        {
            0x0C09856C8A22E6E8ULL, 0xDCBB07C23421015FULL, 0x0713520074656D85ULL, 0x734A55ABCD7A229AULL, 
            0xD477C11D7DEB5E43ULL, 0x731D02068E5F1F7AULL, 0xEC63F4E83FAD0FFEULL, 0x6A0D2D250D2C8213ULL, 
            0xB9D605D3E2B3FD7BULL, 0xD8E0D996E1FB517EULL, 0x6624A69AA896D105ULL, 0xFBA373C6BA59E9CAULL, 
            0xB0CD7D542EB56EE5ULL, 0x827E4DF32B4A2CA4ULL, 0xAAF3C3D187B26A18ULL, 0x7B595CCE0B4EDD7CULL, 
            0x777CDBC91B1F0478ULL, 0x5C31605A7A4B3871ULL, 0xCD400D773AA296CCULL, 0xDAA7820320894A25ULL, 
            0xA5949FADDE3FD316ULL, 0xC27D1B4E7E56569BULL, 0x7A61F5F8A55950FAULL, 0xED890A211459836AULL, 
            0x9EE51304EDB43E45ULL, 0xFEB2154FFFB96A75ULL, 0x2C47FB11ADC322B5ULL, 0xDD5AD8B673E4DDDCULL, 
            0xDC73CF0B91096A51ULL, 0x24ECE1BAEC4613B8ULL, 0x75E0EA046ECA4F27ULL, 0x1CF2BEB83E9D4FA1ULL
        },
        {
            0x095D559A854CEF17ULL, 0x3924D4FCDE67F228ULL, 0xABFC1769E9BC5172ULL, 0x2008BA95B58D0620ULL, 
            0x5E0AF52CF90716BBULL, 0x9279080BB537EB44ULL, 0x3E4E441A3B4156D7ULL, 0x1371D04AA1B1B2C4ULL, 
            0x1E50445BFFDE1E8AULL, 0x13081CB129440BAAULL, 0x4D70656EC44E3D02ULL, 0xA2FFDF83614AC434ULL, 
            0x66A5B4C1AAA49503ULL, 0x6F0712A24BF50578ULL, 0xFEE3B8A6C41D84ECULL, 0x11BD68418137B62FULL, 
            0xE3DB7250AA9D72BDULL, 0xA26F9B6F06BEB9E4ULL, 0x1424F65E7BAF4558ULL, 0xC53C42BCAE116957ULL, 
            0xB22EA9869BE51808ULL, 0x2EBBFBE2C3B08561ULL, 0x89CCD6534A8CEC88ULL, 0x8C1C81F8E42994C1ULL, 
            0x401119207D96E2F2ULL, 0x0B3892E851823523ULL, 0xA40F09DF215BB1D4ULL, 0x36FB1E576D85C21EULL, 
            0x5F6022CF9D9F3A2EULL, 0xDF24AE67C242F1B7ULL, 0xAE3F56FC1515C061ULL, 0x81B08FB546809DCAULL
        },
        {
            0xDB12D430485ED691ULL, 0xEC5146409645D1CEULL, 0xF22D1186BA66C3F4ULL, 0xC56E72B639E60946ULL, 
            0x5A143DF9A48A472FULL, 0xC7446154B2E333D0ULL, 0xDE61BF66FA04D9C2ULL, 0x5DE78CDEA08194AAULL, 
            0xCBB55D269D25CDA7ULL, 0x51C945C12F1882C8ULL, 0xCEC88275B082301CULL, 0x2D202383457A7D3EULL, 
            0x178290DD10EBE598ULL, 0x56EA1B7B1492341BULL, 0x272BEA8F6D360035ULL, 0x08C995264523B99AULL, 
            0xEDAE531AD0359BE6ULL, 0xEA393D3BB05C6418ULL, 0x75908FE0E2FF416DULL, 0xE79419B9ADD55DA0ULL, 
            0x8F1C13C460567806ULL, 0x1A6D726BA24C6913ULL, 0x93A66CA6F1283100ULL, 0x99AB500B8DB848F1ULL, 
            0xBF403AA86A7F7A99ULL, 0x3E0961876EA4766AULL, 0xC11D5B65EAF10B80ULL, 0x1087B2A46F903D6CULL, 
            0x5AF757DC2055D35AULL, 0xBF041699BE470E9DULL, 0xF4D13B063BB9C1F3ULL, 0x8AD372313046CA69ULL
        },
        {
            0x56E8716E35ED4881ULL, 0x68678CF637BE3667ULL, 0x3AD32E0D86BF666FULL, 0xFD0389B254745DA3ULL, 
            0x770F2B6278F32672ULL, 0x32DA2F7E14705CDDULL, 0xA52A5B942DC1062CULL, 0x59ECFD23E281CF1FULL, 
            0xF986B460D74D4C1DULL, 0xCBB233822D9FD7CFULL, 0xDA000350FD8F777BULL, 0x4C1D1307FD3D3D91ULL, 
            0x396B6B0E03B27DB5ULL, 0xED48D3211DFF06F3ULL, 0xFCBAD1A044F044A7ULL, 0x41A13F2A9CDFB527ULL, 
            0x2D656484F8936DE5ULL, 0xF5B2C27F1C371908ULL, 0xCC36AC227FB471A4ULL, 0x1CEB85AEE78BFA71ULL, 
            0x3E9FCD6559902FF3ULL, 0x416F220F24142033ULL, 0xCC20667C16EE2974ULL, 0xB8140F2D4CC9B6BDULL, 
            0x63FD421D6770146DULL, 0x6F567BF309001B85ULL, 0xDF7544275ED6929EULL, 0xF12EA3014F0039E2ULL, 
            0x7345F38CDE1522F1ULL, 0x2D0DC2168EDC4EE0ULL, 0x77D86854601D74C8ULL, 0x096500AA2713C409ULL
        },
        {
            0x3585CED56C12AEC2ULL, 0xA3677A3F4346458EULL, 0xFE028EE18B01A889ULL, 0xE4EF65972D4E56D8ULL, 
            0x034DFEB2E5C4ACABULL, 0xDDD88970640DA0C2ULL, 0x43F97B399B5F7543ULL, 0x109008010164C9D0ULL, 
            0x99D41F314EC7A122ULL, 0x27C15C80704E2C50ULL, 0xDD048E4F061FB02FULL, 0x5630B9667DD8C037ULL, 
            0x398286ADE3E4C87EULL, 0x30E349F4D38064DCULL, 0xA5BD00CFDCBD7AB6ULL, 0x3AA7C687C3755440ULL, 
            0xB21423265EDEF287ULL, 0xC167E7DDA331102DULL, 0xF94E59592304C8FEULL, 0x3F3EFF3C8E8347ACULL, 
            0x390217E83510F70BULL, 0xC4E8C3F0C9E3ADA9ULL, 0x1915E760D6B63D78ULL, 0x25C601C59748E7D2ULL, 
            0x7BD36B0BD9D50C11ULL, 0x382BD57B55B56655ULL, 0x3F47824CFBBBC796ULL, 0x9F3BCBA58E7F27EAULL, 
            0x0EC24C1DC4C5D4F6ULL, 0xBFB485D8351DB693ULL, 0x8876BF7B4E09D82FULL, 0x17982777F09D47B7ULL
        }
    },
    {
        {
            0xB35AA7D5DA83F147ULL, 0x28816BCA93CEA1F2ULL, 0xA26F43076D0D4E9FULL, 0x1F80941138859059ULL, 
            0x3B7033DF7F19CBD0ULL, 0x68A1FE5015BB040BULL, 0x67ADA813D54CB37DULL, 0x3B3199C34E9B4D0CULL, 
            0x1893C42F44FA4DB9ULL, 0x526512A7EF2C32F3ULL, 0xF3EDE2193E6E9C1BULL, 0x412DE856F64019EFULL, 
            0x4286CC4F9E1AA25AULL, 0x0602D7ACCE8CF82DULL, 0xEE8A65B305BDA9EFULL, 0xB13D187356AB1A69ULL, 
            0x730AFE3A60A58A18ULL, 0xA7AF1AF6C85B5E4EULL, 0x0F167FFED5E06BB1ULL, 0x36B772EB523581E3ULL, 
            0x47D107B0D5A90F91ULL, 0xEF2E403B006F0C76ULL, 0x43153693ADC13D51ULL, 0x5FC10782CC3AE953ULL, 
            0x6C80DDBE3B7F3785ULL, 0xDECF576C51E8393DULL, 0x729F7EC0D8E6C32DULL, 0x217F0301AF783BC6ULL, 
            0x19B8FBE4A99C9BCFULL, 0xC804DD9A954166FDULL, 0xAED1746CE7D25A60ULL, 0xED834CD0A3A1FEAAULL
        },
        {
            0x0FD5300869FE068CULL, 0x1C6DD3E48E0A22AAULL, 0xA85E3602FB8DC47BULL, 0x920AB7C4084F9448ULL, 
            0xBE406301BB72CC50ULL, 0xE9B15636BEC8DAADULL, 0x15AE123DD5FA9109ULL, 0x79CBD29570A8A9E8ULL, 
            0xF31E4E390A17A200ULL, 0x545943B620791123ULL, 0xEF8177486F56B172ULL, 0x2C0003BBB25757DAULL, 
            0x34FE5A53DD01CFB4ULL, 0xA1BE25BCAA3EC5C7ULL, 0x4DFF484F46AD3413ULL, 0xC47F5B8BC971CECEULL, 
            0xB18E7C4EAE7D20CDULL, 0x893AABA59C559F67ULL, 0xB292425D6259BF2EULL, 0x78A16631AF197963ULL, 
            0x4DF8B02880EE1719ULL, 0x0E77E0C0EC53DECBULL, 0x0F68DEE79DB5A7E3ULL, 0xA4B775BB6C7554B0ULL, 
            0x068FD2EA7D507500ULL, 0xFA11E07AE5ECF87DULL, 0x0D7007423C8B25A1ULL, 0xE87FC954E4A4D9B1ULL, 
            0x0321343A33260E49ULL, 0x3C305B0748CD4495ULL, 0x4389F6ED80C588A7ULL, 0x24282819D13D13C3ULL
        },
        {
            0x3916192E2281180BULL, 0x4FF0E268BFB28234ULL, 0xF84CA2B2D402DCD9ULL, 0x739ED7AEDE880B74ULL, 
            0xA64CA3511F673C77ULL, 0xF197179784927C9FULL, 0xF9C1B41C33957C04ULL, 0xEF28131988EEE927ULL, 
            0xAB7612FD99612BD4ULL, 0x12B6C6C8229FF8EBULL, 0x4F8536D3ED4E0581ULL, 0x72BAFBCF6AEDF9BBULL, 
            0xED6C44ABA063EE53ULL, 0x317CF577AF30F394ULL, 0x59C21F1E2615A53EULL, 0xE0E5093E0BCAA69EULL, 
            0xF8167A050C967177ULL, 0xE28FA1FB2467B3FFULL, 0x36FB2963220A2A1AULL, 0x3F9230C5BB8320B8ULL, 
            0xFA340E201A58EB36ULL, 0x93CB2FE40176E9ACULL, 0xF1CA63826FD5B361ULL, 0x6ECF365F31F139D7ULL, 
            0xE7245E3C327D562AULL, 0x4E2FE19D6795967DULL, 0xC1B90CB5C5983144ULL, 0xDC212A7FDD744717ULL, 
            0x0AEB484620E2B502ULL, 0x0FA5956987BC0BC4ULL, 0xE31910BCDA30CE62ULL, 0x12723F932509B20EULL
        },
        {
            0xF3A0674E226728ADULL, 0xC933D44F47C70CE2ULL, 0x2928BE9E23D6B61CULL, 0x63FBEDC0D862FB90ULL, 
            0x4069947B49FEE40EULL, 0xA072E44604AEDE77ULL, 0xE18F865F6368883CULL, 0xED21B2DF1BF31704ULL, 
            0x223C815607E4068BULL, 0xAFAFE8289E59FFE4ULL, 0xC6E5ADEC4F4DE677ULL, 0x653C9B17B1FA157CULL, 
            0x0F7F8AB7D003902FULL, 0x50B690D14FBE6336ULL, 0xB3D0E5FD27964740ULL, 0xE12A6BE071B958BAULL, 
            0x73D53AB6A99F4D63ULL, 0x43E8AF6457F45ED0ULL, 0x7B1976573D05B8C3ULL, 0x2B16AFC5EA670596ULL, 
            0x3CD0DBF9CE663B19ULL, 0x9D944042AEAF5405ULL, 0x3F5F7430864D92D2ULL, 0x0589166089EDC8EAULL, 
            0x1BDD6E82F370B5DDULL, 0x3B55895E25410D09ULL, 0x6B051709B74D4CF9ULL, 0x0929A89445B32D1EULL, 
            0xFE675833145B8A0BULL, 0x806E4656EE6A62D9ULL, 0x872CE46A6DA1D73DULL, 0x73A6E1A2FF1DE68FULL
        },
        {
            0xD6433319F50A37ADULL, 0xCBACC7946CC67C4CULL, 0xDA6D14ED6D4B91CCULL, 0x05545D20BF9623B5ULL, 
            0x45AC1D4EBC839C89ULL, 0x4F9D7F3354453DF8ULL, 0xF10818B712B143F9ULL, 0x915080B3AC41D5C1ULL, 
            0x214F6FE91CC9FA0CULL, 0xBD55A8BD5DCC19D8ULL, 0x1E5B123F268CE26FULL, 0xD5D122C6D80AF415ULL, 
            0x432C1A252912EF9EULL, 0x00C28B0AA6B76F50ULL, 0x900C43F0A771D851ULL, 0x7090ADF7C77CC48FULL, 
            0x37E1A5BB631140BDULL, 0x857A9A4D0BF5054BULL, 0x2BEF5461EE134DCFULL, 0x3FF19EDB8CF5D9AEULL, 
            0x9C331F3EAF5D001EULL, 0x90A77A8415482AD4ULL, 0x2B36F876CCA01645ULL, 0xDD426B04C7A204BFULL, 
            0x88CD2D6217509A6AULL, 0xB84CC3F5CB19F2C2ULL, 0x2DBA9D2712BCDCADULL, 0xAFE0F6974912CBA9ULL, 
            0xBD95B9B1A7159BF3ULL, 0x9960DBE09A459AD4ULL, 0x0D78D740226CA2C2ULL, 0x4C9E9AB6DC41CBBCULL
        },
        {
            0x5A7BDF87D3C1B597ULL, 0xEFBD7B3D81CB1106ULL, 0x56CEE69AB86931DBULL, 0xB4EE6F948B535EC6ULL, 
            0x10EA60714F8ABB91ULL, 0xC785AB136F83F046ULL, 0x90F7F316CF576626ULL, 0xC5B279AFE868874DULL, 
            0x5595A9A6971E199BULL, 0xE894821D42F2ADE9ULL, 0x507DF9CB85941222ULL, 0x2431FD6495907EEDULL, 
            0x0C7ACC7FDA4F81FAULL, 0x3B0CC1E862EC5E52ULL, 0x5459B2867AE86051ULL, 0xF62DF28384CF7D1AULL, 
            0x5C5E8CE3047E0154ULL, 0x6A020E0D98BB497AULL, 0xC244AF2FB406F28EULL, 0x24764BD01E90CA37ULL, 
            0x485422EE7AA616D2ULL, 0x1104A0C7BE49AC31ULL, 0xB6F620C57F27BBCDULL, 0xD2A84EB75CDCA755ULL, 
            0x06241D7AA7A567D3ULL, 0xCCF4F40406E14A35ULL, 0xF6929000F05DF81AULL, 0x9476EEBE9357217DULL, 
            0x31BBF22236025C2AULL, 0x6E08895F0123F335ULL, 0xB9944081A85982B9ULL, 0xF56EC7AF1683B3AFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseBConstants = {
    0xFC273FE200F57530ULL,
    0xEA9F3FCF6CB6C5F3ULL,
    0xD0C359F53E86516DULL,
    0xFC273FE200F57530ULL,
    0xEA9F3FCF6CB6C5F3ULL,
    0xD0C359F53E86516DULL,
    0x27140C1AD8D34B49ULL,
    0x771B2B414BB0A615ULL,
    0x05,
    0xFF,
    0xA8,
    0x4B,
    0xB8,
    0xE0,
    0xB2,
    0xA1
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseCSalts = {
    {
        {
            0xF939CD6504D1AB21ULL, 0xBC54ADDD9E605548ULL, 0x35CA848F46280990ULL, 0x60EF22D594A0F32BULL, 
            0xFB16FEDCEF760676ULL, 0xF044D52C3822DD0DULL, 0x94E0B68FF9AF5775ULL, 0xCF00D3B9953BF792ULL, 
            0xB6D7799B01ECFD34ULL, 0x60AA77FCC4CF4978ULL, 0x52DF3F83BD0FB926ULL, 0x4354957AFCA7A9A3ULL, 
            0x92517C6F652F3B6FULL, 0x7EE27F62B207D0D3ULL, 0x24F2F5F801C34664ULL, 0x99C36F41C1CB2A62ULL, 
            0x77E893A14754849EULL, 0xF2E615B12C2F0655ULL, 0xDF49BFB137CB5E09ULL, 0x1DF09BB1E87DF913ULL, 
            0x917B1007904DBC87ULL, 0x1B40598A0C6CF91EULL, 0x6E462DAE89B58879ULL, 0xE942268D17D5B674ULL, 
            0x6287482E8AD4B460ULL, 0x7C279A2D19436101ULL, 0x611E144AE3994093ULL, 0x583BC99E15FF41A4ULL, 
            0x1E4F7E5E1756929AULL, 0x5B6869A09EBF706EULL, 0xF6B05D7BDBFAE6EAULL, 0x8D3302D7E8D42949ULL
        },
        {
            0xA192AA7D95D92C77ULL, 0x08392C4F8C22A92CULL, 0x34B56093271949FEULL, 0x59CEAD01E008BADBULL, 
            0x9742095E4CC6DF4FULL, 0x9A2BEFC1C73E5032ULL, 0x8F5FD2C4418EB8E1ULL, 0x8748A804D3A03E78ULL, 
            0x2FA304353F5B1C36ULL, 0x6449CE1649EA1988ULL, 0x97E8E8EE624E746FULL, 0x1434E03BCF7EEA1AULL, 
            0xE0FE0F0C5161F2CFULL, 0x130DD7B26A2F8AD1ULL, 0x51C42ED861D0F7CDULL, 0x23EB132B31841DA3ULL, 
            0xFF551EE378E318C6ULL, 0xE609364712C95E79ULL, 0x6F4C13266D68FE7EULL, 0xF9C6196632C3AAECULL, 
            0x65669A9DCBFE5421ULL, 0x54AD635283AC8CCEULL, 0x61351FC9B89A064EULL, 0x580BAB1F88C71230ULL, 
            0x9FCDF90D70685378ULL, 0x851D5910CE7B1615ULL, 0x98F9AD1EDA83003CULL, 0x41C38E422C0DE109ULL, 
            0x7A7146B7B8C3B188ULL, 0x38ABE0ECD62CE78FULL, 0x3859F80F7F64904AULL, 0xE2E4A20F7EBA27F4ULL
        },
        {
            0x1CA0E960B2A1B27DULL, 0xC2AD291E05965CBEULL, 0x260F17C467C6087EULL, 0x36D9817ECCD74F36ULL, 
            0xF152D3625BC04C78ULL, 0x2BE76F5F39411FA9ULL, 0x71F3413C1D77E476ULL, 0x93DF0467B811C551ULL, 
            0x3938DEDFF255EE56ULL, 0x7F2D67373421FDDAULL, 0xD7A3A5A4E0DC8790ULL, 0xFA6366B91F46A498ULL, 
            0xAE160747BE564DEFULL, 0x91B296246737E005ULL, 0x9DFD6969F357CF93ULL, 0x48B02D9B5E7C7BDAULL, 
            0x79A11606AC575A85ULL, 0xB64F88AC628F8440ULL, 0x6F556FB1179C36E5ULL, 0x729A2034C38E6FD1ULL, 
            0xACDB0EAFA511D108ULL, 0x51C46336559054A0ULL, 0x19E781173B08B63DULL, 0x4483DF153A5194A8ULL, 
            0x129751EEF29245FDULL, 0xC2AB22D683D00B66ULL, 0x6ACC0355A43A7307ULL, 0x8AD2391420088390ULL, 
            0xD9B35052923DE1EBULL, 0xFD25F486CE01E431ULL, 0x816E9B8BEC99E45FULL, 0x0D37D8B5BA98221CULL
        },
        {
            0x259FE819FC180458ULL, 0x66464AD62B116835ULL, 0xFF204DDD4D4F117BULL, 0x5977725A6C08B6CEULL, 
            0x91E6EE811C77FD2FULL, 0xA2D92A5A55B06580ULL, 0x3B68960B3850EBABULL, 0xBF5B85C19C04982CULL, 
            0x980A4CE4A9454940ULL, 0x3F39D78AB3B12102ULL, 0x046B05A152439C6BULL, 0x11AE9A5B04DCF620ULL, 
            0x112DD5650C59EDF4ULL, 0xCC3CDF728FD94A2FULL, 0x847595DB364103D7ULL, 0xD7F3CD05C9B033D8ULL, 
            0xB397DFC1EA1E270EULL, 0x7312E6E6BEDDAC02ULL, 0x3EAEC22C17C85CC0ULL, 0xABBBAB63C662A1F1ULL, 
            0x3BEA251DA9DA1286ULL, 0x85B860A841E31C33ULL, 0x7DF34ED5B0FF595EULL, 0xF7566B8BF2175434ULL, 
            0x583F22CCC3F95CE1ULL, 0x4CFB76B2C25D8B6EULL, 0x87E7284F0C07208FULL, 0xBEB5042D4C9AEC18ULL, 
            0x3F9616228A5BA8F2ULL, 0x60A42CA1AF0E0274ULL, 0x7B3D2D3911941A64ULL, 0x2DFEE98C6B415D9DULL
        },
        {
            0xAA89F5D2E38E02F1ULL, 0xB45BF3DF796C3C06ULL, 0x2F86729BFB046F5FULL, 0x9FB2AD0DCC42748CULL, 
            0x539AEF412E473195ULL, 0xE51A4835E27063A2ULL, 0x8177AD40D1F7CD62ULL, 0x6BBE4DF1D88D87E0ULL, 
            0x83D308A781D10DFCULL, 0x07D2BD254C12F60BULL, 0x3EE5DA5AF2A6BDADULL, 0xEE240427C66D6FCCULL, 
            0xC008FD369E651B4DULL, 0xDDA577D2AA315D0FULL, 0xB2C8D2E6F3DCA4D7ULL, 0x169CCEABB47775EBULL, 
            0x3CFD4A9E7E086A3DULL, 0xD08A8E42427CCD17ULL, 0xEB429118A4550E10ULL, 0x10A703D0B36583A5ULL, 
            0x2E9B3AD566495953ULL, 0x491AA442D7FF2A2FULL, 0xE70577CCFA97C1E8ULL, 0x832297768845BBE5ULL, 
            0x1CAD0BC892DCCACBULL, 0xEDEE8316677C1150ULL, 0x6D1B7D4C388CFD3CULL, 0x53CD142E0C6040B7ULL, 
            0x7B89222BC9A3009AULL, 0xC6A11640C61A5DDDULL, 0x8F96D90697869577ULL, 0x39514114413DFB67ULL
        },
        {
            0x30B1F548797A9CFCULL, 0x6F72EC3907840BADULL, 0x02C2512C9A1B7C52ULL, 0x281C3DEC545BA25BULL, 
            0xBACA9D9C90FAE658ULL, 0xDA298CC98854A6E2ULL, 0xE51716765CD20356ULL, 0x2551FEB2FCC9D20FULL, 
            0x3DD093DAF04F92A0ULL, 0x9EEFB67A29DE1497ULL, 0xF8E9FFE9325F072DULL, 0x4CF0BEC9D1F2B580ULL, 
            0xB3A0AB7FF8BA35E2ULL, 0x039138028EFEBC71ULL, 0xEA17DD1BAF5DA9A7ULL, 0xF140675378ABEA7AULL, 
            0x495FCD68D0DA2E9BULL, 0xFF2C1591A41A2471ULL, 0x79B70AE297E2C0BBULL, 0x0A08F7ADD37750EFULL, 
            0x7B52C244BD1C1156ULL, 0x6727FA9B0DC8814FULL, 0x1F0F6176B46E0027ULL, 0xBABD173FEE85F809ULL, 
            0x540E6E9DB94C8667ULL, 0x895A31F4B9A77D35ULL, 0x3950B4D4C87E73BFULL, 0x339C5D90A105A5B6ULL, 
            0x63F71A587A011BCAULL, 0xC52553E8D4244AF2ULL, 0x89B1D52936D15AEDULL, 0xC894120D8906F18CULL
        }
    },
    {
        {
            0x160153EC8031C3D1ULL, 0xEAA2DA90B7F9DE8BULL, 0x29EB10BF36FE6A36ULL, 0xE58111464B37ED2AULL, 
            0x8080F5732E3FB77AULL, 0x26059A226FA1D8BCULL, 0x602011FFFF3AC766ULL, 0x00B3E3C2BE545707ULL, 
            0x6A36EE69E113987EULL, 0x26295087167DF017ULL, 0xA21546C9EF252AECULL, 0x8F0C393AC1724CC9ULL, 
            0x204E5903D58A3EDAULL, 0x42277C4548A36154ULL, 0xBD16736FAFD4D48DULL, 0xE8CCFB7C1D9D1ED1ULL, 
            0x744039F42764E3BBULL, 0x080E81E6C004A61EULL, 0xFAFA353EC6F901AAULL, 0x1111EBEC98730975ULL, 
            0xABF6E1B92161DD93ULL, 0xBE47A8E56883E7B9ULL, 0xF1F18AF88FD6805FULL, 0x53DD398F886A9412ULL, 
            0xC3214AB0C97BFF64ULL, 0x54500DC05BFA44D8ULL, 0x9E111A3265A81674ULL, 0x0668AB7B7C4F982CULL, 
            0x66694524F8E32594ULL, 0xE2DC5EF0751C1049ULL, 0x59FEEDD711F9899BULL, 0x8E43B39C43563341ULL
        },
        {
            0x636258B4727CC817ULL, 0x53A07062E043E3ADULL, 0x44F0249DB6111416ULL, 0xB2B356D9F6E6594BULL, 
            0x0661A19F7D04B048ULL, 0x7F7FED72AB856001ULL, 0x75549986DB9F6A54ULL, 0xC4B3D09901C4837DULL, 
            0x8949B26ADFCB445BULL, 0x2FA0344E61EEE1D2ULL, 0x20499F94E322AA91ULL, 0xCF526DF04F3FB22BULL, 
            0x9260691D442D1C8AULL, 0xBD54D1944F03DB54ULL, 0x723273F57F9045A5ULL, 0x5543CAE2B070FAD9ULL, 
            0x96BA94D0C47C7A42ULL, 0xC3E141A1FF7674CAULL, 0x6C38B5050DB64886ULL, 0x498D69DE08F5DE7FULL, 
            0x3B107FA9DA5AAE1CULL, 0xDC685B6D2ED1F8A0ULL, 0xA8DDB9245BDFD4F0ULL, 0x6FECFA6B6344B1A1ULL, 
            0x1CBDCD0DF2DE52C2ULL, 0x17C32B0ED0D42286ULL, 0x63CE8C6DF1469C87ULL, 0x035D98013A47EBC5ULL, 
            0x6BD55D2EB9E9F2B4ULL, 0x598096AB73EF4475ULL, 0xFB5FFF5E1DF63C3CULL, 0x1E60A2F863577A80ULL
        },
        {
            0x928BF6BDACE0051BULL, 0xA132C51B8C84020CULL, 0x1FB7642A62513B7EULL, 0xBCC0A84215BCF30CULL, 
            0xEF63F434B11899A2ULL, 0x31FD0A5F9EE55338ULL, 0x3793B17D486CF57DULL, 0xA8FACC64A444CEABULL, 
            0xA87F0D8F3D04B4AEULL, 0xEA995B2AB682FB6EULL, 0xC77AECD29B147859ULL, 0x43EA604634BF4F07ULL, 
            0x3D58726E2D868936ULL, 0x1B20740C4A2CF287ULL, 0x74DB77F5E9123A4EULL, 0x2DA387D1A0322F30ULL, 
            0x141B86D13E45E1C8ULL, 0x06E06D2A96A4CACEULL, 0x8D0EFED8A9196490ULL, 0x29411F38533D6260ULL, 
            0xDCCB491F240F3B7BULL, 0x6859298889D7F50CULL, 0x4012961C9B7CCD13ULL, 0x87CC1733A5742265ULL, 
            0x83F645182514A093ULL, 0xE1E72F87537110AAULL, 0x5FB26BA8620837C0ULL, 0xC211A28D63EB340BULL, 
            0xD077E4B6F9D21859ULL, 0xB065150D48AA5008ULL, 0x7A379094FCB347EAULL, 0xF97735E88D0A1466ULL
        },
        {
            0xAD4018DE2D3F4FAAULL, 0x9AD61B87820CB418ULL, 0xD7E8249F31A35008ULL, 0x867D0ABD04555223ULL, 
            0x69A4BC64F6F8BE9EULL, 0xCD1FF3BDFA18AC1CULL, 0xE13CE8E0386420E6ULL, 0xD8AA15F1A8E7C930ULL, 
            0x09AA071A917B10FEULL, 0x4829165381082FE9ULL, 0xA3262149EF7C55BFULL, 0x62A38CBE5C50C4E4ULL, 
            0x41EA9348D7582D84ULL, 0x70389E3FC184FA79ULL, 0x96ACF294B6FC4BBCULL, 0x9BEF1E37333D19F3ULL, 
            0x98961796955A5856ULL, 0x2045FE9E212C181AULL, 0x185A3A61608320AAULL, 0xF4EB336B514E3253ULL, 
            0xF11ED45699C6E3F4ULL, 0x3935992150CF5711ULL, 0xF95E1E7A6FC0483AULL, 0xDDD21E43F770ABFBULL, 
            0x4A4F564FE031C8F0ULL, 0xCC136298D6AE95C3ULL, 0xC0D92134C9E15494ULL, 0xAD80C0AF198242CEULL, 
            0x830AE3A5DADEF9AFULL, 0x66AF9FDBF0BF4BCFULL, 0x939B9A294751A7FCULL, 0x6E48C9270BBA75AFULL
        },
        {
            0xADEBD4F0ED8D93AAULL, 0xFAAB0239DF39120DULL, 0x1E226008708AB4D9ULL, 0xC68113F386F0AC50ULL, 
            0x9EEAAC31DD42629FULL, 0xC4DC45505C2FB322ULL, 0x2DD8D4FF25749728ULL, 0x631267F3EEF15651ULL, 
            0x045AB27BA9BD187EULL, 0x0CEB02F3D6E0C84CULL, 0xBF71872071006BB9ULL, 0x72AEE734D8884A05ULL, 
            0xF790A74A22752645ULL, 0x3730B541805857E5ULL, 0x4CAE2E57E185F292ULL, 0x2C9BB3F1889610A9ULL, 
            0xCD14372E610C39B9ULL, 0x62B7E3F957B1D863ULL, 0x035055DE36552678ULL, 0x1CDC33B8B85B776FULL, 
            0x51822ACFA2BEF586ULL, 0xEB8D7EDDB8DCB250ULL, 0x9F073BD3E5A8AFC7ULL, 0x3F16C2C2C6ED0F0EULL, 
            0xB9E30D641CEA2B12ULL, 0x6A3A8E28C9C82DC4ULL, 0x0C55C24FE739CC6CULL, 0xF48311025215ABC5ULL, 
            0x1640FAF461515EB9ULL, 0x7B12E6A466F8A1B5ULL, 0x6B40A2C6C9913477ULL, 0x9C584DBB1B3D4ECDULL
        },
        {
            0x298861978037A1ECULL, 0x67387A18C713BC68ULL, 0xCF124EA16A44FFDBULL, 0xCFD23671C8DB6E31ULL, 
            0xA9642DC394603860ULL, 0x892029092E9292C5ULL, 0xA4E168DD53EBE7E4ULL, 0xDC178AD7528BFE75ULL, 
            0xEA238FA260125D1FULL, 0x13AFFDDEB0A04C66ULL, 0x3669D76C8C167F4BULL, 0xF2F8692C5616D050ULL, 
            0x52D9705D14A6F984ULL, 0xF7BA566FC4D6BD97ULL, 0x5CD3515232125ACDULL, 0x75335AD319656AB0ULL, 
            0xA375369298811807ULL, 0xFDA65BFFB0D9651CULL, 0x29770913EBC76E64ULL, 0x5577DB68F1A6F168ULL, 
            0xBF4C210918CC601BULL, 0xB0C8F1BB14348CE9ULL, 0x9B7F7DDE85B2C9AFULL, 0x65084B635E4C2E87ULL, 
            0x1A43E2C1777E1CE8ULL, 0x3417D98971A719DEULL, 0x4F084C09224101B1ULL, 0x838C26D6F3FB91C1ULL, 
            0xA306DF2C2950E7B6ULL, 0x54C6C75E2335D9BCULL, 0x3E527209B95A7FA7ULL, 0x21271956E199B61FULL
        }
    },
    {
        {
            0x8D62EC2366DB42C2ULL, 0x90C486265CD45B0AULL, 0x0CB37E45C838A554ULL, 0xAFE27925C0081AF0ULL, 
            0x376C94E228AD7FFCULL, 0x3C326C62E2D6DBDDULL, 0xC288B3E4201681BCULL, 0x7EB642D884734A88ULL, 
            0x49430D9D6D168651ULL, 0x0581A507AE147907ULL, 0xC1F421C7CD239B78ULL, 0xFA49F997F51D1DC4ULL, 
            0x27E7862EAFB853E5ULL, 0x681B61154F65F5E6ULL, 0xA79537A6D3989D28ULL, 0xBFC937E8650C7BAEULL, 
            0xD06315C916B93471ULL, 0xB178B0F40F3D2204ULL, 0x206C09B5494AE57AULL, 0x5EFB3E7B5A85666DULL, 
            0x3DE1E85E4529E84DULL, 0xFDF5E283C2446FE2ULL, 0xA932B5A75909B5E0ULL, 0x81A62280742CC0FBULL, 
            0x8BA1EFD10F34C6C1ULL, 0x53E57BA802977D81ULL, 0x3D188EAB92C8B372ULL, 0xBDCDF194666B0BBEULL, 
            0x46179B650EA04F3CULL, 0x4FDFF92A39F7DCFAULL, 0x2AB2D5D56752D108ULL, 0x35666EC4F5BC8B4EULL
        },
        {
            0x6997C3D9819910F9ULL, 0x4B79DF3587F5C8C4ULL, 0x8E53ECAEBD70C7DAULL, 0xC9E083D8A125DCBAULL, 
            0x0D77E759358191FFULL, 0x4283C94C2FA1F9E6ULL, 0x83CB60FC99DA7A47ULL, 0xF1973473F5CC1239ULL, 
            0xA814A4FE4A024B96ULL, 0xB0E2A008CD7F3B34ULL, 0x603F7A2B5F9C878CULL, 0x03F28A2A50C6DBE8ULL, 
            0xBEC93D1EB26E7240ULL, 0x03865D3C0C07C455ULL, 0xDE5F8D7DCBA3E42CULL, 0x61C02D5FD78EE143ULL, 
            0xF10632F8087460A4ULL, 0x3F1CB2FC6C0A2C58ULL, 0xD9E3345829D098BCULL, 0x7667BE4B475CEFB7ULL, 
            0xBF8334DC700FE1A2ULL, 0x2BA2888F49D13233ULL, 0x0698AB6E5EBD4EDEULL, 0xE1295DFBB0FE18BEULL, 
            0x1D72D6F932FF95EBULL, 0x5C1E7F6BE22CB4DAULL, 0x2BDBBDD154F50DDBULL, 0x38A9CC5176D5E995ULL, 
            0x3ADCF3FE337F4115ULL, 0x05E9BCDD5864916DULL, 0x783049ECBE9996ECULL, 0x33E6F119D4A53FBFULL
        },
        {
            0x36863D301183B341ULL, 0x0B308D5F4682229DULL, 0xEB8A0B3C629CB351ULL, 0xA6EF8C0B2741CD62ULL, 
            0x3674541C63903C69ULL, 0xF38C322CAD4700A6ULL, 0x301AFD357A603A28ULL, 0xDB8F567611DA46C1ULL, 
            0x27F65CEEC1C55DAEULL, 0x0DABA316B0E26B28ULL, 0x611CE0DB0D2ED3F1ULL, 0x106A770E12D589BBULL, 
            0x4A685683C1FE9206ULL, 0xBB5002B48462B544ULL, 0xBE5D2CD4D3E2408DULL, 0xB1A7A5A09A7EFFD7ULL, 
            0x67C366EA158C9181ULL, 0x9F72837302F31C46ULL, 0xB81AC3033B84A2C9ULL, 0x56FC2667DE8C157BULL, 
            0x95068AABFD143033ULL, 0xE0371C8C1220AE7CULL, 0x36C66437EFCA5F40ULL, 0xBA32861E41434C04ULL, 
            0xC2BB31162791CBFBULL, 0x65DC6CFA14A7AB34ULL, 0x42F54502C0BB6F57ULL, 0x8E4B9D788EE2EAC9ULL, 
            0xECEB385921058257ULL, 0x339F76FF43C109B4ULL, 0x5CE5816DD2C8C98DULL, 0x4438681594DC510FULL
        },
        {
            0xD6FD2995A6E36BF1ULL, 0x3D9F8023EE6D06F9ULL, 0x7798D48323CC17DBULL, 0x9340FA066ED385DAULL, 
            0x7759A79DB421E088ULL, 0xFAF56570737D7C7AULL, 0xC98338A67EE58B09ULL, 0x37F668823D97CAF0ULL, 
            0x723AB007DD28D7E0ULL, 0x56698E9109E29048ULL, 0x17E4A5204C9D8515ULL, 0x2A87B3E7C9BC82E4ULL, 
            0x50BE7E4AABAC8A5FULL, 0x107D59BC621C2119ULL, 0x31E2029353F3B6C8ULL, 0xD73941E9ECFAB047ULL, 
            0xCC3DD5F9D713F235ULL, 0x49C5599C5CA8557FULL, 0x34B9B2D09B77EE8BULL, 0xEBB8C4804AC4D49CULL, 
            0xBCE56C2AF134E25DULL, 0xB0F0B9E95A3FBAA6ULL, 0xE0C5DAC1926CBC4DULL, 0xDB2FCDE0ED6D51E7ULL, 
            0xE37A95C7B81FA513ULL, 0x04502378FC62CFC2ULL, 0x00BBA2DE0CABA9B5ULL, 0xE46CF414AD65D308ULL, 
            0x6237D39664045A6DULL, 0xF4080BC870CD9D11ULL, 0x64045E572BD3FDEEULL, 0x69B658772F2F49A3ULL
        },
        {
            0x14A9D508E9E1A58CULL, 0x4132B7AF6AB9CF41ULL, 0xED6988CE966B07D0ULL, 0x28BFC6186D80B885ULL, 
            0xAE89904980F1E6C9ULL, 0x9D80521ED023F1AAULL, 0x669A3BA23A080030ULL, 0xB6404206702CDABCULL, 
            0x428A3691C242762BULL, 0x6311C5D8B66243ACULL, 0xFF1E2D64E425FC26ULL, 0x9755077926117205ULL, 
            0x50AE170274F8C1BBULL, 0x0D0E376C5F14D481ULL, 0xC33E5FFDA2C44914ULL, 0xAA7D5CC66C936A70ULL, 
            0x1008919EA3E17313ULL, 0x0B3FE1C4BC030281ULL, 0x698915DA867DDB37ULL, 0x523E79CACBAA5C66ULL, 
            0xAB46AADDFAACA295ULL, 0x7144C9F1A6A496DEULL, 0xEA7072020969333CULL, 0x6CBD8F5952D879EAULL, 
            0x5923D6AB2AD11AC2ULL, 0x69AB12DAC8E2386BULL, 0x7AA575DEFBAA89F0ULL, 0x90499573B9898643ULL, 
            0x379B00818AA23F27ULL, 0xD01D04019C3B21BBULL, 0x9CD69472593EC08CULL, 0xC00C7F3BC0657A9AULL
        },
        {
            0xFBE9494D7A1C8F43ULL, 0x3322AC33DE3B1B42ULL, 0xB7342A09B3E2DD62ULL, 0x8FD457399351F522ULL, 
            0x99DA5EAD4665D66BULL, 0x0E6518CD81BB1E4CULL, 0xD4019B6565110B79ULL, 0x02725E88D10E8ECBULL, 
            0x250E06CBC225B594ULL, 0xB48B9B57D0B38C83ULL, 0xFDEEE5D85A171018ULL, 0x6D3B49F91477D9FAULL, 
            0xBE1C221A4F8103D7ULL, 0xA171769521AEF277ULL, 0xB7FE6CCC74932E4DULL, 0x70347451117DF27EULL, 
            0x80072C71A8C865DAULL, 0xBA52B86FF25748CAULL, 0x0475550E258D317FULL, 0xC180FB76FD975A74ULL, 
            0xC6F7B2D93B90A9EBULL, 0x50052037F22EBE2FULL, 0x8C1D6A7CA4D91CE2ULL, 0x203FAD81B0F2F88BULL, 
            0xD994B04FC3A8DFD1ULL, 0xBE241FF0E02D5319ULL, 0xA9FDE714EB091964ULL, 0x3B8CCDFFC7E89106ULL, 
            0xE28D192C41B86B2EULL, 0x9E47CDF63979D7DCULL, 0xFF1D572296494979ULL, 0xDD428A6960CB86A6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseCConstants = {
    0x688A01BA42E32A0FULL,
    0x638BC750DFC1D55FULL,
    0xF55FBC6BA04248FDULL,
    0x688A01BA42E32A0FULL,
    0x638BC750DFC1D55FULL,
    0xF55FBC6BA04248FDULL,
    0xB710F1B4938246ECULL,
    0x52070C55503E49BAULL,
    0x16,
    0xCA,
    0x23,
    0x91,
    0x34,
    0xCB,
    0xAF,
    0xF6
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseDSalts = {
    {
        {
            0x764C2EBBF398910BULL, 0xF96A2CB8FBFE94E4ULL, 0x309DF7DD1DF90CACULL, 0xF00466B3DE8F0CFBULL, 
            0x05F48FA0C1C26566ULL, 0x446D9D17A3923185ULL, 0x29A3AADDA5D9DAF0ULL, 0x58E543713F842F8AULL, 
            0x5098694EECEA1B13ULL, 0x4AE5941381EDD40EULL, 0xEB065411C58BA1D0ULL, 0x2159169A37D759BCULL, 
            0x2FCC9E877DDDC670ULL, 0x1B3433CBE65E456AULL, 0x5CD387F93C7C7596ULL, 0x3D34C05EF8E80775ULL, 
            0x2633F6BEC585BDF8ULL, 0x65500C505C19A1F3ULL, 0x3F4004FF8460BB99ULL, 0xF972697F7B9E717BULL, 
            0x18721FA8AEC58F3EULL, 0xCF5D46CD9C75D4E3ULL, 0x8D3E19A25F4E16EEULL, 0xD0A135A334E53776ULL, 
            0xD38721882393A031ULL, 0x27429D4B5B6EC60AULL, 0x31206BF8D36CCD1FULL, 0x23CDC0C6CA096E31ULL, 
            0x2555A168FF1A8E00ULL, 0x8C55405491E42DDDULL, 0xCB68D1FE9509C6E5ULL, 0x690AC7C4F41AE008ULL
        },
        {
            0x9EF21BD3973F6297ULL, 0xA4617A5E7F7A948CULL, 0xD321E2DD16942883ULL, 0x858783574CD7F2CEULL, 
            0xD49EBE08C5E99542ULL, 0xE816A6D685ED121AULL, 0xFC6503DE58C95D9DULL, 0xF1C26B2158727C4FULL, 
            0x713E77ED10476076ULL, 0x8002B9BDE5BC614DULL, 0xF563E683E9ABAC90ULL, 0xF4281CB94A99A0F6ULL, 
            0xC0D7F9C55558E746ULL, 0x8A575DA06F36D5AEULL, 0x6B8486F58B1465B0ULL, 0x28B41116B86BE8ADULL, 
            0x0E180B1415B8C6DDULL, 0xC635517D1D1458CEULL, 0x49C8825E2F853195ULL, 0xE65179402C61A0C5ULL, 
            0xB0348795454E98E5ULL, 0x3A4B49A6EF0E1944ULL, 0xC2DF217D17E9E562ULL, 0x64D09011DB64DFDDULL, 
            0x557EAC9FB0D3DF6EULL, 0x8BE74B3FF528CA9CULL, 0x6401E07283DA02A3ULL, 0x91154A6A86A1E314ULL, 
            0x118C2E290B23C37AULL, 0x68F5F9735C3837ACULL, 0xF3CFC18DDDAF9AF6ULL, 0xC421CFE00F529960ULL
        },
        {
            0x663DDF3839FA2B76ULL, 0x3E779148A86BC83CULL, 0x1C38848879A25C54ULL, 0x6D453DFF6819BF06ULL, 
            0xE8A510C43F24C06BULL, 0xB8CB89A9CA661ADFULL, 0x8D9E8E335493EAA4ULL, 0x0BFA0B2216D91345ULL, 
            0xE0E774AD64C3D354ULL, 0xA0E728D8E6AA3ABFULL, 0xBDC60A9C3E13B038ULL, 0x73BC2EF5CCCAD597ULL, 
            0xC219F6D585AB86F6ULL, 0xBCDBFF8D4B922E91ULL, 0xBCA850984C613978ULL, 0xCCF92E7B08179BD3ULL, 
            0x80D7FE24F76841BDULL, 0x30DAB186575DBD4FULL, 0x03D8D029D496EEE6ULL, 0x928F296FBCC71ED4ULL, 
            0xB776A374801B04C6ULL, 0xC479A49E5DBCAE74ULL, 0xBF6B007847DEB07DULL, 0x876692668E98B1C4ULL, 
            0x695EC4433F35D933ULL, 0x2E0F980C33F3517AULL, 0x6C0BD90A5B690763ULL, 0x06481FD1838FB530ULL, 
            0x1AE4B94F188464A4ULL, 0x5F8F66AA899F3701ULL, 0x3853013E0DD15FFFULL, 0xDC104A97E3BE6483ULL
        },
        {
            0x4F64247FA212A0E4ULL, 0x2BBE9CB41E259461ULL, 0x4E423FE733FDB4EBULL, 0x2DFDFDB61A318270ULL, 
            0x413E26FC19A57423ULL, 0x0AE52939E7B1F524ULL, 0x5CA3C43FA89C2822ULL, 0x45E1922BA8070227ULL, 
            0xFF0DC6154F1D8EA2ULL, 0x22AD1A704C27B94BULL, 0xAA7FDF5941814D2AULL, 0x896992B226229F45ULL, 
            0xDB494287F4808780ULL, 0xDE067C424030712AULL, 0xD173FFBE8EFDB717ULL, 0xCAA147A3BD107A08ULL, 
            0x9607CC668F77DDDEULL, 0xAB15C432A5C31EEAULL, 0xDAEA25B874F272B1ULL, 0x0939B7565B17B5EEULL, 
            0x57AB9A6AB7F3F7DFULL, 0x584C0950820F5578ULL, 0xC4BFD37925175DC4ULL, 0xB1A644230D554497ULL, 
            0x3AA7B3ED0E00A48EULL, 0x8B9891FF3BFAF33CULL, 0x09A8A3CE061A0882ULL, 0xF02A9CC51F025E12ULL, 
            0x6F63A42DA1C5EA0CULL, 0x0CDB64658BCE35CAULL, 0xEB78133C08FBF7A3ULL, 0x3F53814AE5C29F88ULL
        },
        {
            0x89C7A86DD5D557DFULL, 0xC55D86DF8DD35946ULL, 0xE62C25247D7EA028ULL, 0x507222ACD4495FA2ULL, 
            0xA9C564B9DA5C50D6ULL, 0x01742D95240EFB8AULL, 0xBDECDF7C04422AD3ULL, 0x899D2EE74CA9A38AULL, 
            0xF9C3A154113C929AULL, 0xC50187AFDF58FCF5ULL, 0x31295395413B1008ULL, 0x7706FA6BF9193A2BULL, 
            0x842B3FA05A79EDCFULL, 0xA1304C8891692A9BULL, 0x8E740B273543FAEAULL, 0x3B24ED7D3E5F0E68ULL, 
            0xE59B40FEFC14E8D0ULL, 0xB9663CBE107385A0ULL, 0x550B0D60C1CB88A0ULL, 0xF681A4D654F11793ULL, 
            0xB42CF795EAE53A28ULL, 0xFA79C1C5CB53683BULL, 0x7474E4ABDC9150BCULL, 0x9261C30C58CDA7C1ULL, 
            0x31CC8C4054371FD4ULL, 0x44C70F6D9E9B2436ULL, 0x50F4AF9AE1916906ULL, 0xEA76D698FC17FAAEULL, 
            0x550DE3C94D67B887ULL, 0x5A9277026B056980ULL, 0xB3AA42BE1764D984ULL, 0x43315C7B7C4DE44EULL
        },
        {
            0x276C84948E799058ULL, 0xB84A9D604BD3F9AAULL, 0x5CC327B3E0B47B64ULL, 0xDB3301B4F36C06C5ULL, 
            0x0A4AFF2951867781ULL, 0x7B632EE2B2BDC040ULL, 0x355E3ADCB884276CULL, 0xAD68E9F5F8C208ADULL, 
            0xDE1D153F248546B3ULL, 0x1F7213D208C88062ULL, 0xAF8E595533D995EBULL, 0x1419FA1198DAF31DULL, 
            0x0018B9D35BEB2964ULL, 0x7DF30F13AE75B7B1ULL, 0x67BD544195D0DFAAULL, 0xAC01FED73CA4B982ULL, 
            0x29EF811E904090DAULL, 0x9DA8A67E84D31053ULL, 0xB12F44A1AACD21F0ULL, 0x0CC37CD2055F45BDULL, 
            0xC878B3E5C54F72EBULL, 0xBDABC796B152D6AEULL, 0xF2D8E6971A7A6DA8ULL, 0x84C57041B2D490A4ULL, 
            0x2CED52F8A0788FC6ULL, 0xBCF80A14E628B174ULL, 0xB5F37CFD0E6EFA13ULL, 0x8ECAE8FE8CCFEF47ULL, 
            0xC455B55711AF88F8ULL, 0x4EB7144E9D559D92ULL, 0x63A02F5297898DFFULL, 0xFF5E54061A500A41ULL
        }
    },
    {
        {
            0xC4705C4F4EAC86E4ULL, 0x372AAC8F0E1E89F1ULL, 0x50271908739E3107ULL, 0xAADA4DA00257E5C0ULL, 
            0xE27720546FE75975ULL, 0xEFC3C6C2A416F27FULL, 0x528D1081F20557D3ULL, 0x04905ECCEFD851AAULL, 
            0xCB83CF4355F1BE93ULL, 0x73E59313F8255833ULL, 0xB5E98E04DDDA83D8ULL, 0xB0A4F5F10B9701ECULL, 
            0x19DA10E9F66D7EE6ULL, 0x0479378A2F25DE31ULL, 0xFC4C59920304C349ULL, 0x24614B75C3C3EAEEULL, 
            0xAC3B554FBF720A21ULL, 0x3874643C568EB5BEULL, 0x2FE7185260231F6FULL, 0x248680D8F65E1C1DULL, 
            0x4F9B2B76701AEA05ULL, 0xCFE3744AC87ECAD7ULL, 0x6B2FAB9E34B5467EULL, 0xD5A2A3CBE10A2116ULL, 
            0x9269A5694B7BCD2BULL, 0x930451F229D97A4EULL, 0xC56895065E1C2B76ULL, 0x6013CA3F41A4997AULL, 
            0x7445706A05A7D9A9ULL, 0xFCC2596183D8555EULL, 0xB71FB8F96826881FULL, 0x547D164F29FF6C18ULL
        },
        {
            0x7E3CA05916A61895ULL, 0x80E4AF9F77D80C6FULL, 0x785D1723CB28174DULL, 0xD11DF1E390E10ACBULL, 
            0xE7705F8B1930F46BULL, 0xCFC7C472B961F0BAULL, 0xD7BD25713F156AD7ULL, 0x241D608BA9128301ULL, 
            0x411677EFE2E289F4ULL, 0x67B0AA1F388A83FCULL, 0x1C948BAACE0CA327ULL, 0x7069830AF73304DCULL, 
            0x7E407060F966CD90ULL, 0x1CF4A002B450EA33ULL, 0xA63B2F54B6912524ULL, 0xF32CB20A87A0D376ULL, 
            0xD954C30553B1808FULL, 0xCA0CB111AFD4B3AEULL, 0x8E10F0003A1D6CBCULL, 0x801F0471A74F6782ULL, 
            0x59BFFED26E1A5AE3ULL, 0xFBA63EC23B95C31AULL, 0x91F439393450505BULL, 0xC496810DA6387963ULL, 
            0x58BCB1D24A8784B3ULL, 0x068BD26BE9FA3957ULL, 0x22D1C9C2F4019F7AULL, 0xE7CBAB72659CEF40ULL, 
            0xD0B0F7476BC45AB4ULL, 0x88D42ABAA5C19209ULL, 0xAAAE05BB4C24E27BULL, 0x2606591B657C37F7ULL
        },
        {
            0xAC21C317596F1C1DULL, 0xD10D899B6C33E50CULL, 0x74A72451D73C60D3ULL, 0x038F75D7AE3BFC4EULL, 
            0x440B90369491ACA9ULL, 0x76E8FBAE80FCB53BULL, 0x31B0706524064F27ULL, 0xA4F93017AD38CB58ULL, 
            0xDDE63A197E91F503ULL, 0x4E800E10139457C3ULL, 0xCA03104934FB2083ULL, 0xB0235ED765553F6AULL, 
            0x89ADFA14A94DE744ULL, 0xADEC455D879DA298ULL, 0x225CB9CC0A7A8F4CULL, 0x06FA3149511735ACULL, 
            0x9E0DAA868701F07DULL, 0xBAEB2D88036AA5AAULL, 0x0CEA0E96EE8A3DCBULL, 0x0D2DAF1E99236235ULL, 
            0xEE874A8BA39321F9ULL, 0xA647CE858CA3989AULL, 0x0279639769912A89ULL, 0xB9B74971736B761AULL, 
            0x174C0B85DFA7FDB5ULL, 0x7920ACAB717E1BE7ULL, 0x1C68D26761170A02ULL, 0x499590627E55EAD7ULL, 
            0xFAFE593C57F1B4F2ULL, 0xCF73F20AAF5297E3ULL, 0x119F4E42D90804E6ULL, 0xC040830349748749ULL
        },
        {
            0xD1B13213C3C4D481ULL, 0xBBEA2989EB6EA434ULL, 0x6578BE1729C83930ULL, 0xBFE8E713E5E621E9ULL, 
            0xCC7F5F6A17AE1DDFULL, 0x523EA52A1C12B8E7ULL, 0xF660A4F2DB002B70ULL, 0x192D73726FFD8DFBULL, 
            0xE73871EC36DA803EULL, 0xA3C6A2652DD1BEBDULL, 0xC426B11F03E3D4BFULL, 0x8EE13BDEA0B37895ULL, 
            0x729CDDEC3D7BE855ULL, 0xD98262D686858AE3ULL, 0xF22911C7958EA324ULL, 0xC60CD3E7F5FA2909ULL, 
            0x0A59CE2F1F797A83ULL, 0x388BEF60E4A20C6AULL, 0xD9C0B9568A51A3ABULL, 0xD62A00D29E456BC0ULL, 
            0xFD5A2C162FC4B631ULL, 0x9485DEDD797168F4ULL, 0xBB7FBEFA21FD444FULL, 0x1AC0695693BB7581ULL, 
            0x12EC4FFF6C01877AULL, 0xB8FB312DF09B6221ULL, 0x3EAB9975565A142FULL, 0x316508785CC4FF6AULL, 
            0x0874158C8E50806FULL, 0xD1D3629FBC7BAB3EULL, 0x18BDE6A22EECE619ULL, 0xA6B945DB959AF29CULL
        },
        {
            0x76BA86F7D816149DULL, 0xA00597CD55F84E9EULL, 0x11FFA840D254B580ULL, 0xBBB53F0336C08554ULL, 
            0x663ADF4C8FD85A4DULL, 0x99328EA4EA5AB997ULL, 0x1DD4EB2AFE2B0F0AULL, 0xAFF215C4CB0B671BULL, 
            0x30660B0652F35AEBULL, 0x855FB17A14877A3BULL, 0x5E0167AA2E40B1C9ULL, 0x76EC2382B092BA4CULL, 
            0xDF1A16A9DA49DDA2ULL, 0x032A03C418522587ULL, 0x07D849ECCA09CFAAULL, 0xBC8472B20C6BFD74ULL, 
            0xE5236DF423F9CE72ULL, 0x72EBD7EBF278F916ULL, 0x481021177A2295DDULL, 0x6D58C81BD3A1058FULL, 
            0xC18B160DD601D2FFULL, 0x686BA06D75789465ULL, 0x40522307EDB49C74ULL, 0x138A75B9182B966DULL, 
            0x506D26387444344FULL, 0xF1D12867820F9128ULL, 0x7B467452E490A6C5ULL, 0x605D37F049650FB2ULL, 
            0x4499E59C98220E3EULL, 0xC9140521D2F90A00ULL, 0x29E552B4FBEEC8C7ULL, 0xB1E4F60410F37101ULL
        },
        {
            0x96B117DE24796B76ULL, 0x3C93C66592314B1FULL, 0x23804008883FFF6CULL, 0x1FA1DA36E83A3F04ULL, 
            0x3BFB01627F8DBE1EULL, 0xE2D93ADE003D2A01ULL, 0xB458C300252BEC88ULL, 0x07630C33CEC470BBULL, 
            0xC95D3359E971C99EULL, 0xA724E7E5C9BFF5ABULL, 0xAB1028DB244D3D7FULL, 0x12270E5ADDFE0A00ULL, 
            0x6109B880350C6102ULL, 0xBED71B5B20556CC7ULL, 0xDF818771D59573BDULL, 0x86D609DB9B87930CULL, 
            0xB7395FCFA4F2C35FULL, 0x37D88AC0A2A6793AULL, 0x2384397D7A32A06BULL, 0x36481C60B376BC4BULL, 
            0x5723CE15DE927C1FULL, 0xFAA29507CE418FD4ULL, 0x3A3E4AA49DD0A721ULL, 0x253456057A2DEF1AULL, 
            0xDA1359C85AC7327BULL, 0x19694A8850BB4674ULL, 0xC6BF3F52CCBE967DULL, 0x0690DC79B09760DFULL, 
            0x20809AB927667274ULL, 0x567002056253BD17ULL, 0x484C091DC7D2FB04ULL, 0x4E91D21E8DD9A8DCULL
        }
    },
    {
        {
            0xC913A79099CED428ULL, 0x1C763E82F0FE7287ULL, 0x84EFC4AD52E9BF26ULL, 0xCBED33B9C7591DAEULL, 
            0xF9558D8C919F126FULL, 0xCC88C099CE35552DULL, 0x1C8A41410377D345ULL, 0xF0B51B0F868C4A4CULL, 
            0x00AD01473CC7CAB7ULL, 0x2CCF82383246C4C2ULL, 0xD3E4C86172910472ULL, 0xCF0A5E9A73CEC2ECULL, 
            0x0A6818D62E0146BDULL, 0x878B14CF070748D4ULL, 0x14E47B7E6A372C2FULL, 0x6D4F8F58E841996EULL, 
            0xE064F07905D25908ULL, 0x9DED3425E7FE1860ULL, 0x788C599C0056CB00ULL, 0xFC1FBA6AE8ECDE7CULL, 
            0x3D4D72FF52C03872ULL, 0xB08AA255F8E7FD1FULL, 0x2320DE638DF0B3F2ULL, 0x8A67BBDF41F28C2FULL, 
            0x5478CC17F65E22A1ULL, 0xDB5D0B6ECCBDC5ADULL, 0xEE3ECD7AA0CFE2E2ULL, 0xB15B7D7B76100DF3ULL, 
            0x2B49F48344A72A4FULL, 0x19A911980FDAC20DULL, 0x74585EA30AD03055ULL, 0x55B96BA443425DA6ULL
        },
        {
            0xA127B14785795A1DULL, 0x4BD28AB17F337E4DULL, 0xC6F695B40F563183ULL, 0xC92E6DB2F8B8C344ULL, 
            0x9609B3B30B5DAA0FULL, 0xD297BD91702C3D8CULL, 0xCE8329B807330B57ULL, 0x3CD76CD05F955FD6ULL, 
            0x37EC2AD84C3DC46BULL, 0xB9C9879311C57A5EULL, 0x96398C38A0D30427ULL, 0xE6416F09A6D9E658ULL, 
            0xC7D979C822009B61ULL, 0x9B3E9DBF42A1FE34ULL, 0x4E4C969D26D0798FULL, 0x87C914553B07D397ULL, 
            0x493A4AA0B7D04B29ULL, 0xA547A5219CD50A95ULL, 0xEF98E3C92B88E1D6ULL, 0xCB6B6C5199CC3128ULL, 
            0x46067D05031FB186ULL, 0x38EB0E3E01F63102ULL, 0x4C6C6557E8C49072ULL, 0xDDAC985F4CF776C8ULL, 
            0x0BA76BAB9ED20AA0ULL, 0xEFC581DD8AFF37CEULL, 0x3DFDC797D630A5DDULL, 0xFD68A1EA5E54D3A5ULL, 
            0x1234ACE1A51BBCCFULL, 0xF935B149148156D2ULL, 0x132FD7E061D5E5A0ULL, 0x22D0A70DEDD11928ULL
        },
        {
            0x0ECB27545DC0B49FULL, 0x19393C43B30C0369ULL, 0x897B545D8014EADCULL, 0x3435AD30333192ABULL, 
            0xB9155ED56423D78CULL, 0x5B189064C1ECFFAAULL, 0x4F40FDCE4278E27FULL, 0xF07274A8107CCE09ULL, 
            0x91A95DD22DEF9687ULL, 0x204A5A2B18033ABBULL, 0x4EADA06CBD45FEE4ULL, 0xBB585BB2AA75040FULL, 
            0xE5FCBC64C04FDBEEULL, 0xF7A268DE8CD1307FULL, 0xD1E8AB7520234F12ULL, 0x3E401D3BB249C2B8ULL, 
            0x9809BD2B52E8DEF7ULL, 0xBFE4B729704E8C81ULL, 0x317A73D2F75217C0ULL, 0x446CA96802161968ULL, 
            0xA6484EE2BD5E26AAULL, 0x3410F036A3B66C49ULL, 0xF43E9EE2C9B22B0DULL, 0x6DBAE9BD0E94285CULL, 
            0x33E6FDCD33FC60B4ULL, 0xBCAB9857C973FC4EULL, 0x5D1F4E3F26ADAFBFULL, 0xC9D2CDF6DAB289D3ULL, 
            0xC83EEBE15BA8AF13ULL, 0x4903970C3A4680DDULL, 0x5F5CEF97CD3109A0ULL, 0xE7F539C51A1BD53DULL
        },
        {
            0xA5B36E4A07D0B813ULL, 0x4FB709B3E639D145ULL, 0xC2BF7AF73DBD0916ULL, 0x74742666E0F70970ULL, 
            0x51711CD33D508B2EULL, 0x399EDC717C6FE70BULL, 0x15127FEC8EAD7421ULL, 0xCE1FF5B253D70AE5ULL, 
            0xFDC2391776BA6FCFULL, 0x3AA73E3A6A00AAF5ULL, 0x7589F0398F4A809CULL, 0x0514A7649882367EULL, 
            0xA45DF8B1377DF7CFULL, 0xA439E70C5B204692ULL, 0xD074065D17A74613ULL, 0xF799116FD6D7099FULL, 
            0x8C9D69ABEECEBB9BULL, 0x9DA3ACC7D0D3B584ULL, 0xEC410937239A869EULL, 0x6B386453D535A310ULL, 
            0x1A3F3FE3A055EED9ULL, 0x71F3BFBD514C7EABULL, 0x6A577F738CD0899DULL, 0xD467A1200FAF65FCULL, 
            0x8C3FFC171FBA57C0ULL, 0x1835106C386251FCULL, 0x90DF7D50DE3A2C01ULL, 0xA50420135C9F47ABULL, 
            0x19AB2F152D5E25CAULL, 0x27F04C1935AE2528ULL, 0x99E6E674506BE1D6ULL, 0xB02DFDF38A9CD946ULL
        },
        {
            0x8401859C63827D92ULL, 0x475CF131BD7D1B4AULL, 0xC58FE0444F938AEDULL, 0x9987F80B2BC13F9EULL, 
            0xB996B8F12497FD81ULL, 0xC9497B19A0259E12ULL, 0xE9E7D43918182434ULL, 0x832087ED6070B318ULL, 
            0x542507392D42687BULL, 0xFD5D721233336A49ULL, 0x9E9756CCC6D51414ULL, 0x269FD77DFABBE13FULL, 
            0xC3B9FF69A3A98789ULL, 0x1EFF65E0BA5D68FCULL, 0xA6875E1D497E8BB9ULL, 0xEC5DC92756B08E4CULL, 
            0x3F803036B3F13757ULL, 0x0639E2A14E5E35D0ULL, 0xFF5705BD0E9DA033ULL, 0x2ED62575A90866A5ULL, 
            0xF03FE61E2012B18BULL, 0x6B8F539485C2CBB2ULL, 0x3DD9358EC88BDC8EULL, 0xEE75B03BE33CC596ULL, 
            0xF22036E6C81E16E2ULL, 0x155BA3D84B18AF1DULL, 0x1CB3269E5DAAC63CULL, 0xC2B909ED77E07502ULL, 
            0xCBADACA986294EC8ULL, 0xAF7A717BB84739B9ULL, 0x858EB9D4C51F44AAULL, 0x124BF81389734E82ULL
        },
        {
            0xF6A0CE84D487A7FEULL, 0xC352AF160D74B238ULL, 0xA34523D9AB4D8649ULL, 0x1F68BF32230276A6ULL, 
            0x280E8CEA075558D9ULL, 0x134D4AB9364FB6C9ULL, 0x5C2A94375EB78CB3ULL, 0x189A4C2921962F2EULL, 
            0x59ED0C961F02B791ULL, 0xC05F4082C177883CULL, 0xB1ACEB78CFAED4D0ULL, 0x33A2124A15622C6EULL, 
            0x3DEB909F6082564FULL, 0x5B0AB23F227EE414ULL, 0x8EDCCA8A642E6116ULL, 0x41563A85F4B49571ULL, 
            0x3839131FA8EAF72DULL, 0x2AEE0546708EF745ULL, 0x21CC19724B6FDD54ULL, 0x763DFCE49B5ABEAEULL, 
            0x1555B62916657EB6ULL, 0x6C7DD3CE832B9D07ULL, 0x9AEA085578E4A236ULL, 0x196630E0C718FFD5ULL, 
            0x8DDABD62E9C37B92ULL, 0xD6C1E0076D36C62CULL, 0x2D61505510E8D4FAULL, 0x7B078F4F30DA9D5DULL, 
            0x4E54F1EC4C73DF15ULL, 0x775BF5D8F36D5D87ULL, 0xE5CF2853F005AC49ULL, 0xFB1C92132D4EE6CDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseDConstants = {
    0xD052D229F4B5F5F3ULL,
    0xE40CC1878C1771F4ULL,
    0x20F4BE8F981D1703ULL,
    0xD052D229F4B5F5F3ULL,
    0xE40CC1878C1771F4ULL,
    0x20F4BE8F981D1703ULL,
    0x8441E2350C1D3C77ULL,
    0x8255B6F32D55B60FULL,
    0x82,
    0xC4,
    0x5E,
    0x1C,
    0xAE,
    0x2B,
    0x25,
    0xB6
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseESalts = {
    {
        {
            0x71D6AA63ED69F997ULL, 0x3F9E95A31D417C52ULL, 0xD44C7B6D1691ADF9ULL, 0xC1DE2437324070CAULL, 
            0xF056820CD675715FULL, 0xDD7B6C434C76CD4CULL, 0xE43C8A04A01E320DULL, 0x0E81FC64E9379418ULL, 
            0x83522209A282D07AULL, 0x73523166CBD1105DULL, 0x30A129DACEF23FFAULL, 0x7B475F68048A1F7CULL, 
            0xA27EC6426E367CEAULL, 0xCA232C456E64D17DULL, 0xC57A4C596A9558A2ULL, 0x8C254EC40371284BULL, 
            0xAF9A191ED9B36C61ULL, 0xD17C4564E16FB9F7ULL, 0xDE6E415D5F2BEC21ULL, 0x9BCF67D3F5C8F80BULL, 
            0xB61A11A84FEA0B64ULL, 0x74633692D96384AFULL, 0x5B3C612B9E3C71C2ULL, 0xB7D3116597D08CDDULL, 
            0xC5FC0F29CCD2C811ULL, 0xEBD9ED7986258B3DULL, 0x62F290FD6459212CULL, 0xF862F673A6C213E4ULL, 
            0xE34F40568C634C56ULL, 0xEF44676CE882EA68ULL, 0x9C5ED57FBBD886CDULL, 0xE74D1CF5DE9FC36BULL
        },
        {
            0xAA544A668B1FAA3FULL, 0x57143C97B43C9D6BULL, 0x83C626280E03949CULL, 0x2E68047A3F76856DULL, 
            0x7B391F2BA4917E93ULL, 0x673B286D209EC056ULL, 0x5CF1B4AD00059C46ULL, 0x012B213191D4CB3DULL, 
            0xE20631BD628144CDULL, 0xFFA48C6AF60AF955ULL, 0x5FDE3438BC5006B3ULL, 0xF3C7CCC8339A63BEULL, 
            0xB2D9FA4A868A7A21ULL, 0xBC8E1C03173D098CULL, 0x68249A9355A0ECC7ULL, 0xE105C40213797A43ULL, 
            0x6C7A64CB30B1BC02ULL, 0xEE9954651B37C855ULL, 0xAC59D1AC6EC78C43ULL, 0x2CC9844DE08508AEULL, 
            0xE27DC90F46AA866AULL, 0x57C760620EC5EBC6ULL, 0xAC9389AF8CB13BE3ULL, 0x0ACC5D0B4A12E9ADULL, 
            0xC09FEE53A9F99404ULL, 0x479B69C55BB9ABFDULL, 0xAFF4DA396DB888E2ULL, 0xA23266FC7EC48FF7ULL, 
            0xC117C467474E7096ULL, 0xAA32D15999DF91D3ULL, 0xD779E9270E4CBD98ULL, 0x72FF0972861A3BC6ULL
        },
        {
            0x50C1430059BAB4FCULL, 0x39A4D6B3C492E20AULL, 0x66A9FA7B545F6380ULL, 0x16131FEC708F4532ULL, 
            0xCA659708641EF7F3ULL, 0x6451EF2566C2B7D6ULL, 0xDB263BFA455383E1ULL, 0x982B7CC4FF0B331EULL, 
            0x599C6E1B02E805F5ULL, 0x857AAB65D2FA0EFDULL, 0x42D59BD67910EA2FULL, 0xA2AF0D55784DEDF8ULL, 
            0x462829F50CA2F24CULL, 0x38F6F2E37B4B0047ULL, 0xEBC2044CBF694ED4ULL, 0xDE9C3BCB60115E31ULL, 
            0xC5B4C74C6B8DDD02ULL, 0xC5A37C1348BD492EULL, 0x8B795E8651DD438EULL, 0x9B52D5FFE7CB0A8FULL, 
            0xDC5749A647ECDEA0ULL, 0xC7E13955F4218D55ULL, 0xE8DF8B7D120FE3C0ULL, 0xEA0AA82164A206CEULL, 
            0x2A238C7F6B3FED1DULL, 0xECF2498FFD0A2C8BULL, 0x50A562A9C0A8A587ULL, 0xC1A431E62B6EC691ULL, 
            0xFDF830C57C4EE5DFULL, 0x14C86C5ED4E8E3C1ULL, 0x44D1BA0AD6F5463FULL, 0xF1FE564DE8E87637ULL
        },
        {
            0x8F5694D22641D3DBULL, 0xAA0D6C596B369F1BULL, 0x844D009283A58844ULL, 0x0E39EF346FB58A29ULL, 
            0xB1C9CFDFCFB0F732ULL, 0x88F4BB2DCE7C5DBBULL, 0x91B864CC16B66628ULL, 0xF72D20E3832466C2ULL, 
            0xE6AE483CF99BFD93ULL, 0xDC6DCEAA7D163BDBULL, 0xD98E97285F0AA8EEULL, 0x59844E82F2FF635FULL, 
            0xBB633DD7F7DF1C1FULL, 0x03DFF2928E7557EDULL, 0x7DE1597A72F55782ULL, 0x7CB48EE96789B00EULL, 
            0x40E52F679656CB68ULL, 0xA881FA3BDC3DEBBAULL, 0x8E838CBE70126EC4ULL, 0x55C290AC678EC902ULL, 
            0xAEF67B1261C667CEULL, 0xE06E32FFC18CD50BULL, 0xF018ECEA02B94DDEULL, 0x221BFCA149333E74ULL, 
            0x71F9C90F4AFE0AE9ULL, 0xF9DB6F2853527038ULL, 0x919D116647D33E22ULL, 0x3EB511DC10DAAFB0ULL, 
            0x3B14D34823F1F8F9ULL, 0x138C7247F6577969ULL, 0xFA16AF7B12B51BDCULL, 0xFE3EF1A40704B93EULL
        },
        {
            0xB6F8C0A9C52112F4ULL, 0x242DF314A6529EEDULL, 0x1695822882A1F376ULL, 0x0F27F01E3B1CB1E2ULL, 
            0xC8511941B40DA5D4ULL, 0x9D1A1AF279AA745EULL, 0x2A41A22A02BDBE15ULL, 0x06F4466F8324AEAAULL, 
            0x187C77EDE05FF0DDULL, 0xAA134874C73F48C6ULL, 0x9ABB3E2ADF3CB1D1ULL, 0x1258795C282B0DC5ULL, 
            0xCB51BA09062A370DULL, 0x60612087B4E3A1B7ULL, 0x4B6CFAA187C6E4D2ULL, 0xE2B82C4AD656CC1BULL, 
            0x63E41DED3AB0AB36ULL, 0x55CABB269F7F152BULL, 0xE7252D2B66DD4C60ULL, 0x8FA5E25DE63378DAULL, 
            0x00CAD7B5013193F7ULL, 0xFB52C2BF1255CBE8ULL, 0x28AAA7F6D3711DA7ULL, 0x63856CD9BC168263ULL, 
            0x8F45C454F341C355ULL, 0x9047EA1CA45AEC4EULL, 0x5502092A8BDA7AB2ULL, 0x70F922CF9B950ADDULL, 
            0x9B3B9DF64FCADC7CULL, 0x58070597CF4A714DULL, 0x8700A6B844970131ULL, 0x1FC2EDBEE3C99888ULL
        },
        {
            0xD3230A5DCD4916C7ULL, 0x7C6D5B901AFAFFD2ULL, 0x434574A24ACAE03DULL, 0x26EE6B4556FCB954ULL, 
            0x4C733DD63F5C417FULL, 0x79D0C86EC1C27316ULL, 0xD47C9EEDC65A3A68ULL, 0x9FDB79F17372C999ULL, 
            0x34376F1C037013EDULL, 0xD5AFC90029BD58CCULL, 0xFDB154CA3007EE21ULL, 0xC386B8247CEC14B7ULL, 
            0xE2B452495440B741ULL, 0xA28C598556CCC92AULL, 0xC2929CF9858F8BE2ULL, 0xF01E6BE25B316E2BULL, 
            0xEFFD3B29EA5EC3E9ULL, 0x18B9E34BD8A99663ULL, 0xFE635F1B4A16E83FULL, 0x72344CB34103CE51ULL, 
            0x74B659AD64E85E8DULL, 0xDAE081D0C4378FEDULL, 0xD562C9BD371422CBULL, 0x2E15E0B5F10F7E54ULL, 
            0x746458427850451BULL, 0xA7894B55EAFC90EAULL, 0x624F5E22EFCAF14AULL, 0xF3BD21C0DD07926BULL, 
            0xDA72444DF497AA55ULL, 0x705D0DFBA0BB3BC9ULL, 0xCF09032B5853829FULL, 0x4CED4F49F4109151ULL
        }
    },
    {
        {
            0xD7C0B50AFFD4A980ULL, 0x4A9CB87DE57D7791ULL, 0x729FD5F7DCABA8EFULL, 0xAA0247F374CA6C17ULL, 
            0x46AA75F5072A6012ULL, 0x99C6560981C907E1ULL, 0x0CB736B422CC1CC1ULL, 0xE0C30FF4A48B6A54ULL, 
            0x2242EEEF9A218613ULL, 0x23062C532D45C993ULL, 0xAA1B2A2BAFC07EA2ULL, 0x5DC711ABB23BF5C9ULL, 
            0xD7F3641B74CDBB6EULL, 0x9CF16CD79948C18EULL, 0x4A1CE16525126289ULL, 0x5EBDF40C5148AACAULL, 
            0x0BBD879A364F3DE2ULL, 0xB975A083D2DADC96ULL, 0x8EAC9575A60F9D27ULL, 0x78B3DE195E60248DULL, 
            0x5F5C834DFD391D6EULL, 0xFD50FBED97D48929ULL, 0x0696734D19327D15ULL, 0xD428955A54A79FDCULL, 
            0xB0518CEA776FC5A0ULL, 0xD64FE3F981156534ULL, 0x8851814F3BE1D984ULL, 0xCDEC51567ADDDC0CULL, 
            0x075BE6AE5326B985ULL, 0x05150F68CCFB44A2ULL, 0xEF99E5F05CDA61E8ULL, 0xFBB784B25C8D3888ULL
        },
        {
            0x69CC645AF9FDCA4BULL, 0x101CBA1B48BA0E6AULL, 0x2B7C8D61BD2C4537ULL, 0xDB77F2A922F98124ULL, 
            0x06AFFF417A46CE97ULL, 0x4F58651CE0780F1CULL, 0x07CF5792F9D11EE2ULL, 0x525EC8A662F5FE00ULL, 
            0x77997E5B2FC5E684ULL, 0x823850D0734E98E7ULL, 0x4562CC8127F07CE4ULL, 0xB87A14DF8BC3714EULL, 
            0xE6C5CDBE8B651117ULL, 0xCB4C5F5492ED4E7DULL, 0x346D6368E169B52CULL, 0xE20CB56160802BCCULL, 
            0x19E437AD9F5E49F3ULL, 0x97791ABAD998963BULL, 0x3143349BFCCFFBCCULL, 0x21D2F0849915C507ULL, 
            0x22862D826D9B84F1ULL, 0xC577559C9DDAECC2ULL, 0x0D0AF441E07B5DC4ULL, 0x781437848BDA1C17ULL, 
            0x0219C02A57A50671ULL, 0x0AD19CB2B6BEF810ULL, 0x62D415C1D965F226ULL, 0x8EEBA614F8ADFC8EULL, 
            0xD2045D21F805809FULL, 0xA15915190BF5909CULL, 0xB829E3E83E593238ULL, 0x3A87A8D631F4EA8DULL
        },
        {
            0xEA776C5CD86CF5C6ULL, 0xFA684B98823A4779ULL, 0x7944B17D95BCF250ULL, 0xDC819A3A6C68849FULL, 
            0x7CFFF015C9AED26CULL, 0xEECC1A4DC631C4B4ULL, 0xC6829289D2C3F0C1ULL, 0xB0254C00EB4A03E6ULL, 
            0xC57932E4DDDE0518ULL, 0xE7346388ACC5F471ULL, 0x01E2F0BA046374BBULL, 0x91910206013C80DFULL, 
            0xAB38C07F7187C461ULL, 0x6A0A26BE54D4BED2ULL, 0x3CDB5FCFD1844F94ULL, 0xED92AD9150B7D2C8ULL, 
            0xEC10A5B85B070097ULL, 0x0871F3A0C1F8A6A1ULL, 0x9774DE8451224DBEULL, 0xA1C42CAE0B672148ULL, 
            0xB0DB2B384DC4947DULL, 0xE435235DEA79FE27ULL, 0x5F197C5562A372C8ULL, 0x9ACEAD5CA1D6503CULL, 
            0xD0A4F613353A85CAULL, 0x4E6AF3FA69C457CEULL, 0x6C3D57F8508E1993ULL, 0x0E8680D6069B1DADULL, 
            0x08210B1A9EF58209ULL, 0x50BB78488802FEC2ULL, 0x8C483737E56607E2ULL, 0xA93D2DAC7F84AE50ULL
        },
        {
            0x908C856C29BC5981ULL, 0x5BFE7274E0ADDC30ULL, 0x192EF78382F8CEDDULL, 0xE36B83BAF846551EULL, 
            0x7105CBF13B76947CULL, 0xAB59A006B015CB6EULL, 0x68DF29A5CE44D685ULL, 0x9F6493881FE52650ULL, 
            0xC938B30466E3635FULL, 0x8E8BE8821BF93ACFULL, 0x3666D752D3BE50EFULL, 0xAA167E577145C709ULL, 
            0x99E61B1534784DF5ULL, 0x19485DCAD417511EULL, 0x8D3DBA6A49172B7EULL, 0xAF7CEAA28B6EF7EAULL, 
            0x71EC55009393FFDFULL, 0xADD77205FC9F2BA6ULL, 0xFEA2C8902C2D47E4ULL, 0x03E426C94321C1A7ULL, 
            0xC9F328196F7A7CFEULL, 0xF0F87049239D9818ULL, 0x74EE00C98A266B31ULL, 0x76F28E7078E09ADBULL, 
            0x8F7CD10CE55CC4E3ULL, 0xFBD8B7BBF6946135ULL, 0x015CA59E89669AD2ULL, 0x742A252C7BC3C29EULL, 
            0xDC4BC9516BE8A976ULL, 0xBBBEBB1C4209D752ULL, 0x22240F259ADAC422ULL, 0x843557B340423E26ULL
        },
        {
            0x4C3FCB5B430062F2ULL, 0x3A3DE3D339FFEC8BULL, 0xA63D2BE3176CF96EULL, 0xD866421D40FC9E62ULL, 
            0x04C4AF3443BF71B1ULL, 0xD8F909E1469510CCULL, 0x80CA7968AD8A5534ULL, 0xD7A89AD8A18A66E1ULL, 
            0xEB8DDA9FD729F4FBULL, 0xE4EB3F28D9C68179ULL, 0xCB688C9AEA7D41F9ULL, 0xDB606B9ECFB6A34CULL, 
            0x2B9BB9893F3EF588ULL, 0x2E96E9DFCDA3D84FULL, 0xD06A20BADB4C856EULL, 0x3C3C221D2E0C57D6ULL, 
            0x4016F531CA527CD9ULL, 0x4DD3F8702FAC655FULL, 0xBB0DC0041552768BULL, 0xAC8B23E7E62126ADULL, 
            0x893C320328780732ULL, 0x332D0C2676F1E444ULL, 0xA0F8DAFCC24F5091ULL, 0x1CBF7C054784295AULL, 
            0x8C2371CBBBE7AD55ULL, 0x568F38EA2F4DD6EBULL, 0x73F7A112E3B9E4A2ULL, 0x69390CE0DFF31F93ULL, 
            0xF5C579C661FA40AFULL, 0xA4F011AA32EFAA6EULL, 0x143E7B33A6059EFDULL, 0x7D9C04C46E703141ULL
        },
        {
            0xDE75004AAC3AB2E2ULL, 0x2B45E309B5715D9BULL, 0x5191C9E366C5513CULL, 0x8671A3CC6BD91110ULL, 
            0x200EFE8870F0082FULL, 0x75C44C286584D40BULL, 0x8809E352B42F9F81ULL, 0x1E7F596B62D3878AULL, 
            0x2DDEBD0E9E9F3FF7ULL, 0xF937B34FDFC0B42EULL, 0xD511F501373AF7ABULL, 0xA355853F4DB4D655ULL, 
            0x61C94DDC8C1B91DAULL, 0x61769A527F087E58ULL, 0x1CC3826EF888A03EULL, 0x4003E5F00D61F788ULL, 
            0x5B2DDFD182EBEFDEULL, 0x0B1827E0E18DCF86ULL, 0x0EC5E4E4ADC2BD46ULL, 0x8830392C87CEF27BULL, 
            0x7F2B607B6499E212ULL, 0x78D1B6B83C0CF1D2ULL, 0x3EA552EBC5A8319FULL, 0xA0F4BB44B8B0D759ULL, 
            0xA7F469EFC93F055EULL, 0xC38A7ED6AC7CE885ULL, 0xBF2EFB06A109E263ULL, 0xB260E2D4140DF1A4ULL, 
            0x1DE56858265A97B1ULL, 0x13EB719C8DF428A4ULL, 0xEE08B8CAD903B01FULL, 0x61D311554BBC09E2ULL
        }
    },
    {
        {
            0x23B2C32A2EA0F0F6ULL, 0x4117D28073B1B971ULL, 0xBCF41D73A490CC45ULL, 0x143D12F4F28D1A72ULL, 
            0xFBB87A86ED4D20F0ULL, 0x3E18596C596384E5ULL, 0x8F3FA525E637E994ULL, 0x6557DD8EFC28038BULL, 
            0x4E88D695C4483F2FULL, 0xEE8D5DD5DDE7A7C0ULL, 0xD862EE06D676680AULL, 0xFDB6D2004022CC75ULL, 
            0x850D82E5C35720DEULL, 0x796855B24F6EA95CULL, 0xFB8B8E8E3F9CFE4FULL, 0x24007D9D22F97032ULL, 
            0x628A78D7442EB829ULL, 0xBDB40BAC2D8AEFB7ULL, 0x5EEA3E865D306C44ULL, 0x91CEFD94764C11A2ULL, 
            0xA45DF4023F716BE0ULL, 0xD883466A17407424ULL, 0xEFEBF2010DD0EE2AULL, 0xF7A001E9AF002731ULL, 
            0x59869E77CB01C5A7ULL, 0xF636CDBB87FE7CFBULL, 0x019CE5E1CAB6C395ULL, 0x61B2310C80ED8929ULL, 
            0xBBCE99E81F88F0FDULL, 0x84A77CF9EFCBAFF4ULL, 0x71DAAC83D174CFEEULL, 0xB88B8E090389ED64ULL
        },
        {
            0x5A521FAB0E929D2FULL, 0x9324D78013E75B14ULL, 0xAC83A74D93D643E5ULL, 0x03657948BBFEE78FULL, 
            0xC20401B34DC41E47ULL, 0x0E5F387B6102D4B0ULL, 0x073468977D8F08F7ULL, 0x616DD1B77700632DULL, 
            0x496F0DE07DAD2420ULL, 0x17DA8D3724124AF6ULL, 0x2B17CA7F0615C420ULL, 0xC5D377557DB16540ULL, 
            0xAE8136B903CEE0ACULL, 0x6DF08F124D44DBF1ULL, 0x93676EDA288D1F42ULL, 0x815E278C3963C7BCULL, 
            0xC0EAE20260DA25F9ULL, 0x81465AEA4A3EA6F5ULL, 0xC4760F8744896EA6ULL, 0xF7BDA219BEF41813ULL, 
            0x0800D94068D1FAFAULL, 0xEF9D38352191F887ULL, 0x224C7B4A86D4410FULL, 0xE96795CC8DFC08AAULL, 
            0x48BDE158AB2C6D60ULL, 0x1D3C28DE5066AB3EULL, 0x5DC3219E41FEF89BULL, 0xB0D8F2895FD9885CULL, 
            0xD42B72CFA7028681ULL, 0x69C61B909A0A9E27ULL, 0xA0924FF8907D6B95ULL, 0x92B6EB61712B7162ULL
        },
        {
            0xFC71CFA3C3CB0846ULL, 0xD982721D6FBE9E5FULL, 0xEC8243988A739678ULL, 0x2F38CD5E8FCB2C13ULL, 
            0x0A1B14AD3B27C4E7ULL, 0xFD358912EFB1B2F5ULL, 0xD6E3F59EB4CC22F5ULL, 0xE06BBEFE1F030184ULL, 
            0xE0C906344ECF4E41ULL, 0xA8D5D6C25C61033AULL, 0xE80C48B3B8E98F59ULL, 0x77D3328B6A44D26AULL, 
            0xD1DAD21E14EA0258ULL, 0xE74BBC08D1F48EA2ULL, 0x84EC0C21AE5993C3ULL, 0x832479B72DDA41E7ULL, 
            0xEC3F6B759A98762DULL, 0x96845A34B4521826ULL, 0xE0F26ACF65AE96A7ULL, 0xBB59294EF311D919ULL, 
            0x388925A8657399C3ULL, 0x5C46621A326212F3ULL, 0xBB993D006A5D4BF5ULL, 0x7BC0153303C1B1ECULL, 
            0x771D4CECAD425946ULL, 0xC9DDA66E8F185732ULL, 0x348FC2885A6BD8E2ULL, 0xC96D031BE472E623ULL, 
            0x504427983F2FE204ULL, 0xD2302720FCC302B0ULL, 0x3298C1D1E6B20397ULL, 0xA6E3A3B53BA0DCF4ULL
        },
        {
            0x87CA19BEBFFFB796ULL, 0x60C944C39355D44AULL, 0x249A158594285E21ULL, 0xD1C1FD7D523D91FAULL, 
            0x8A1A9B1B0A319664ULL, 0x6FDC07CD3C8E94D1ULL, 0x44A94888AAF9A47FULL, 0x0288D605CAE03E8EULL, 
            0x82CD3E1E4C2E16D5ULL, 0xAFCA683B6163ECB1ULL, 0x7304FA8CA56674C9ULL, 0x3BE7052893942B87ULL, 
            0x7507A22850067BD9ULL, 0x135AF2D96BDA53C1ULL, 0xCA69EB5B5AAD06FDULL, 0x8CC31404C4989B1AULL, 
            0x5A9FEF7359F0D44FULL, 0xCC867ECAE1351CCFULL, 0x84E9E32129999D39ULL, 0x0608C7570B5D30BBULL, 
            0x92A05A13DD02BAB5ULL, 0x4DBBC380782553AEULL, 0xE98EB5F6D0C350C6ULL, 0xAA37A30DF8207EBAULL, 
            0xBF30C1C714CEA784ULL, 0x1F5A92000FC02C21ULL, 0x291ACF5C11A8C97FULL, 0x289488BFC49D0AAAULL, 
            0xB5D306B5A5D80B6BULL, 0xBFF64ACC0C4D56FDULL, 0x4F779BBCE275BC9EULL, 0x2194D68C834FEBB9ULL
        },
        {
            0x118B7C2747B2EE6EULL, 0xF2287162B7A1351DULL, 0x43F53827410EFF17ULL, 0xCA51BEC3A47D5941ULL, 
            0x1D5D51738A28653FULL, 0x931ACB7C80F7E004ULL, 0xDA592C367CCF86DEULL, 0x94B93C82F8B477BBULL, 
            0xCA941D228A5FC7EBULL, 0x227210C17EFE7038ULL, 0x300DD5B3364FC874ULL, 0x2293A32E3AFB6A52ULL, 
            0xF170EDBB062196DFULL, 0x93DB0745995C15EDULL, 0xC43FA8267433CB51ULL, 0xC32381ED873ADA5FULL, 
            0x54326BAEC91BCCA7ULL, 0x3BFA1C3B33D02446ULL, 0x433BD18110C27778ULL, 0x58C58881FF7F4CD9ULL, 
            0x51E6A5D80F9B9A4CULL, 0x10033EA1DA07E182ULL, 0x33BEBE578D7515EAULL, 0x97516379B5BFE118ULL, 
            0xB412A30F9E0BCF02ULL, 0x362A5DD983EFF851ULL, 0x5C67B6E0EC84E8D6ULL, 0xB3EB9BD2C49D36E2ULL, 
            0x1776C8FBB654CB3FULL, 0x3BB9C7E052661D16ULL, 0x6ABB3CD5E964096BULL, 0xDE8B9FF196800FA3ULL
        },
        {
            0x1DCEF066468C9E2EULL, 0x27204A123DE2A114ULL, 0x42E58E3614ECCE2EULL, 0xC3BF2289390C4750ULL, 
            0x4D3FDDB6F4E11362ULL, 0x0F0D29314A96A9FBULL, 0x4C226B9106C98BE8ULL, 0x0E28F3847492314AULL, 
            0x38D7B1D719BC4726ULL, 0x0F307254C014827EULL, 0x3A768461BEB99F9BULL, 0x21F4FC017A8BC044ULL, 
            0xB6577C9995BD2228ULL, 0x3E11E0F148AAE5D4ULL, 0xAFDE23045684678AULL, 0x136F352048292A53ULL, 
            0xCAC10EBFD9934C76ULL, 0xFA8D8418DB0353B7ULL, 0x4C4D8279A360F0DEULL, 0x9FD7162E46E824BAULL, 
            0x0EE953FBA65D5E59ULL, 0xD55C372BE05E0EA6ULL, 0x5C151978F6398651ULL, 0x95F6F164674D94D9ULL, 
            0x06E020D4BEB03A06ULL, 0xF37CCCE1044330BFULL, 0xE643E6922663F6A1ULL, 0x7C26A3C02BA067C8ULL, 
            0x0275DDF46B153CAEULL, 0x1CCDB870ED14E626ULL, 0xC069B51B683BE5C9ULL, 0x865023D4A4C89288ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseEConstants = {
    0x2E86AC9694E2F2E9ULL,
    0x4C8F946FAA9A7A81ULL,
    0x100C80A18D58A90DULL,
    0x2E86AC9694E2F2E9ULL,
    0x4C8F946FAA9A7A81ULL,
    0x100C80A18D58A90DULL,
    0x324EDEB936144E36ULL,
    0x087855148E7EC626ULL,
    0xE3,
    0xC7,
    0xEC,
    0xB6,
    0x2C,
    0x17,
    0xEC,
    0xA1
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseFSalts = {
    {
        {
            0x3BBE9B79CE0BFDA7ULL, 0x6FF944E13B0E9D77ULL, 0x324F79C5B2679BA6ULL, 0xBEBFEB7253328617ULL, 
            0x5BCBC2DC3A102D2DULL, 0xB956D3020FC8E651ULL, 0xFAEA77E3F4578A81ULL, 0x7A20B1F716314BBAULL, 
            0x78DA4A39E5792ECCULL, 0x7DA2F8050816A6BDULL, 0xE51AC81BE5843826ULL, 0x4D159F5B9E46DAE9ULL, 
            0x745BA0F16266264FULL, 0xE361B2B5104ADE19ULL, 0x4343CA25A1C1C3D0ULL, 0x44115B4BB35606DEULL, 
            0xD3763B462609DB3DULL, 0xDE544739648E3C5CULL, 0x6B8B6A3D7E44331DULL, 0x0E29553CB6E6C54FULL, 
            0xD67B22D5BD6D5D74ULL, 0x049A890EAED3F462ULL, 0x76DCAA03768E5444ULL, 0x6BFE95ECD075A042ULL, 
            0xDB6E384027A78C59ULL, 0x19EC620A1DE7993EULL, 0x77466F37CDED1962ULL, 0xD878FE6CFB422BFCULL, 
            0xA33F68955CE2DA22ULL, 0x30D43692DDB3A976ULL, 0x9554D3C56E518421ULL, 0xF0A2B14778A3B93DULL
        },
        {
            0x53F6ADD871D88E21ULL, 0xC7FFA7FF28C7F9EAULL, 0x14BF90F3FCA214DCULL, 0x246B595102F2021BULL, 
            0xCAAFFFF9E27911F6ULL, 0x6E9E6BC1C148E981ULL, 0x0D8DBCE0B2BCC377ULL, 0xC07B11C3BBE39473ULL, 
            0x216BAF2D4D5AF9BCULL, 0x3241015AAC2F3074ULL, 0x7E666011F06B88D1ULL, 0xCD4B76FC2F816C56ULL, 
            0x8F6FFF9F58553FB9ULL, 0xB892734BAA6416DDULL, 0xDA2795EE82B074A8ULL, 0xFB80E2671BDA3E3FULL, 
            0x2A8513D81E7A62B1ULL, 0xCB0B9DAF7962C51CULL, 0x30FB55815D875DDFULL, 0x9DE3BA828651A63DULL, 
            0xF5C4913E7CBBF370ULL, 0x90D7959AA3C6BF34ULL, 0xB957DDC2FC4B6380ULL, 0x1A07EC99942DE796ULL, 
            0x7DFBCFE3A72A5192ULL, 0x6E26733C086DE85BULL, 0x2A36FFBE4DE5E22DULL, 0xBC1F7F9A409E6037ULL, 
            0x26283F5DE1E05A2AULL, 0xFB0B55156E8A5ACDULL, 0x91F697967500CC4BULL, 0xFB13D604E098F3D9ULL
        },
        {
            0xE6ACE513AE715E2FULL, 0x65DB1C1364AC4EA2ULL, 0x46086EA0378872F7ULL, 0x12711144641B9408ULL, 
            0xC06F55F95CDCBDC7ULL, 0x7C04521D988BE0DEULL, 0xF2591DA32BE3872CULL, 0x70FCD864E294E85AULL, 
            0x285C709985A86C1FULL, 0xF32590C06AF3321BULL, 0x138D4E7F7697983EULL, 0xAC22BA53F8860416ULL, 
            0x2BA8C728FB0E0323ULL, 0x2E6BD28BC1321922ULL, 0x1B34BCEA070CECB7ULL, 0x7964E4D7D72AD408ULL, 
            0x15420BF11F508051ULL, 0x65AAA2519F4B60FEULL, 0xE1575FD907EA92A3ULL, 0xC32E532E50E5A1BFULL, 
            0x05867C6C679C8F9DULL, 0x5BD4318967DF2D53ULL, 0x3C53BBA33F896A8AULL, 0x1B07CE6F596E01F3ULL, 
            0x06A3998259F1A4D9ULL, 0x5E4DD81EB26A48FFULL, 0x2D8B18568745BA08ULL, 0x8D62E5183BEE0023ULL, 
            0xE41D1BE647989E02ULL, 0x9A8A9E18EBDE7864ULL, 0x65722BA6EC7EAFE0ULL, 0xD20F95A474CB56B7ULL
        },
        {
            0x8884A1A6536EF646ULL, 0x42A20EA35ECD0B4EULL, 0x234C2BF545928E03ULL, 0x8DC972E505E38872ULL, 
            0xFD3555416F2B0D6AULL, 0x4E6CE64509E03A17ULL, 0xCDAE3C195CFB2C53ULL, 0x88A08BB8C3E8CE20ULL, 
            0xDE581397E6064D7EULL, 0x3DF88996E5921504ULL, 0x956D04008540F553ULL, 0xA3BE16B14D5FF0B3ULL, 
            0x2C6E1EAA81ADDC2CULL, 0x64A74C431DB0DBE4ULL, 0x3EAD0CE15835DF36ULL, 0xD39F72A9EDD527ADULL, 
            0x2FEC1AEC30D715FEULL, 0x4E27B9683F563BD0ULL, 0x144202F44E088D07ULL, 0x93269E94B5F73563ULL, 
            0x1BBBAD5EE5D1EE09ULL, 0x025E248C19CA7802ULL, 0x0EC7E3F7C450C48FULL, 0x0894FBACEB5F0E0BULL, 
            0xD8E65C5E2DEB34D3ULL, 0xC0E9D0278F4043D0ULL, 0xB10B75EB31BAC8F6ULL, 0x5153163D6083FCACULL, 
            0x6051A7353802E250ULL, 0x66C97822AA1148D0ULL, 0x88B769B135D16842ULL, 0x37D7126C54B315FEULL
        },
        {
            0xD495E14F7160A51AULL, 0x94186C96F14DF0B6ULL, 0x2AFB6751A8BA5C3FULL, 0x3E1CAF66D2DF252BULL, 
            0x91B937AE70146418ULL, 0x4B6FFDAB50C0004EULL, 0x838D3823B6376BF9ULL, 0xBF6BC92A0D3E1A9EULL, 
            0x0B41413767D486E4ULL, 0x1EF3C39D224CA1CEULL, 0xD6AE14008B1117DAULL, 0x8049D515F7D94495ULL, 
            0x1CEC13DDFC074648ULL, 0x6C38ED065DFFE638ULL, 0x537796B1F2A59515ULL, 0xC8F4BB2EB9A72F35ULL, 
            0x70887280C8420E9EULL, 0x87DB3E993A412C9DULL, 0xCC12766600EE6365ULL, 0xE24DEF9E64DA665BULL, 
            0x32E91611EA76472FULL, 0xFC69EF8CE6F18B84ULL, 0x0934C215329FB880ULL, 0xBFBF9E5AB34A41C3ULL, 
            0xF2D60846EB4B4BE4ULL, 0xCE026324FD29A520ULL, 0x7261F01785CBA8A8ULL, 0x6F11907C2137386AULL, 
            0xF77E5EBA0054CC7DULL, 0x44C39BC47C77FC86ULL, 0xD46DBA54D089133BULL, 0x2F3A8B4D384827AEULL
        },
        {
            0x3B6EEF80398C51E9ULL, 0xF51EA34A08A29CCAULL, 0x94AA8DD210ABB24EULL, 0xD1FAFDE14EB8E6C2ULL, 
            0xBC85DEFD7CD2BE70ULL, 0x661C7FDF4FBB83A3ULL, 0x502EB85AA53F69D7ULL, 0x7CB6E732EEF0423AULL, 
            0xD20CCDC69534D3D1ULL, 0x9493C5871C39F7F6ULL, 0x07CD49D80FAE33D2ULL, 0x39FD015AD058C8A9ULL, 
            0x9D0821BDD72BC60DULL, 0x5D1298646D3600F6ULL, 0x58135C16B0078A8CULL, 0x499E8F8603C9D144ULL, 
            0x8A64900CF904DFA0ULL, 0x2A120A742EB8E48AULL, 0x28191444E97BA73BULL, 0xD2C8676BD1416380ULL, 
            0x1F40858D03983005ULL, 0x7D06FCF1EA6485C2ULL, 0xB39139385299486AULL, 0xDE3666DF03C7EC82ULL, 
            0x00562F6815C52CB7ULL, 0x57B710BC53979D92ULL, 0x35935CDDD805BC91ULL, 0xB17B6A0278338874ULL, 
            0xDD07C01CC61AD301ULL, 0xCA08B9200FC9CE15ULL, 0x7706B8B7671C8EFEULL, 0x59DE229C2596FA18ULL
        }
    },
    {
        {
            0x688B60EC4298B160ULL, 0x3577FC6809F500DDULL, 0xB19517C055F3F2C3ULL, 0x2BCB83A45480E55BULL, 
            0x4E4909F2F90598C5ULL, 0xFD66D10FC10D7054ULL, 0x9F0523500BEEFAFAULL, 0x344371E0CD913CD8ULL, 
            0x6619578D68DC8A6DULL, 0xAC9458C872CECCB1ULL, 0x8DA818B6790D4D4FULL, 0x62C025F6258810EBULL, 
            0x40A14DE9BD51CA69ULL, 0x4927E7D739D1B644ULL, 0xBB07D90EB84ED6EDULL, 0x395AEAF54C18CFE2ULL, 
            0xCE91B63B06C6DA45ULL, 0x3BB6E40DE5104BB0ULL, 0x5820F1564A91CC66ULL, 0x7B9ED1A8E389AC8EULL, 
            0x47427C4BD85CEC34ULL, 0x025C767EDDFD9183ULL, 0x7A769C4A0C00B5E2ULL, 0x3CD5E91A7F2DE56FULL, 
            0x9C9A5D31635FD674ULL, 0x8712C881E1769F3BULL, 0x85A0A2B1EDB18868ULL, 0x4F9F940C9AC00388ULL, 
            0x8034F715874E35FCULL, 0xE470FAFBD6C26995ULL, 0x4BED084C5D411A17ULL, 0xF8F601F685DD8CEBULL
        },
        {
            0x3959BA5505EAF7ADULL, 0xED4335E9381FA1E3ULL, 0x6FF3B5CE6878DDEBULL, 0xFA2C93264017AB51ULL, 
            0xF2E9A716EEFB4752ULL, 0xEC7B459324241884ULL, 0x9A459AD81032760FULL, 0x333F57441C400BD7ULL, 
            0x9D8BEC68F7A3962DULL, 0x7C17F70D1CD4CA59ULL, 0x9F2535465DA1ACD5ULL, 0x84CB649020717E66ULL, 
            0xDA28958F7AA0461BULL, 0x4AA4DAC7BD92210AULL, 0x21F4833963FA1A69ULL, 0xA394570C4859FBEEULL, 
            0x122F3DCC12769E1EULL, 0x753B524E2B0F218DULL, 0xE3BFBC4648AD52C6ULL, 0xF3E679D3AAEE07BCULL, 
            0xFA28BB406625DEDEULL, 0x79C2051BC85B3916ULL, 0x664C5DD560EEE6ADULL, 0x9D81ED3FDA08576EULL, 
            0xB7052B0FD61EC146ULL, 0x31D9D64396AD394BULL, 0x0DDDE052DC3E7B92ULL, 0x9174D3E886FE8618ULL, 
            0x6FE917EFE5AF4570ULL, 0x89C2FB129100AE99ULL, 0xADBE28F9F8D2A078ULL, 0x7EEB74EE3C4F3C77ULL
        },
        {
            0x18FF3791BA91E660ULL, 0xA3EC3A12ED248082ULL, 0x265AECE7A70E08E1ULL, 0x54CD04654FA2AB67ULL, 
            0x296D0BCCE051D8F4ULL, 0x6CF7BC6AA97F800CULL, 0xDA7FD048DE40F465ULL, 0x82FFD24D10244A83ULL, 
            0x94818A6F2187D11CULL, 0x4D3327B34F2EC1D2ULL, 0x77F3B1B3163B47AAULL, 0x52D87AA4383AC6CEULL, 
            0x2CD52EC991AFF237ULL, 0xB04ED097558FB28CULL, 0x79C2387E927EEDF0ULL, 0x14594A8ABCDEA0F7ULL, 
            0xA966FD54E2B81661ULL, 0xFF108A3A5553ED75ULL, 0xB38D04E9C088A1DFULL, 0xE20C113D86F5E205ULL, 
            0xA8BBDC55F138DB1FULL, 0xBD16AF3A5B2996B3ULL, 0xF08A2A0F7B0E011CULL, 0x5CBD28230AFD93F1ULL, 
            0x4D5FDA4960843D73ULL, 0xB4E384B6F20562B6ULL, 0x3E97163845B39228ULL, 0x38265864836D49D2ULL, 
            0xDCCE299F838F5F1BULL, 0xBD20337A86BC4253ULL, 0x1928D4ACDA49DD16ULL, 0x85149BA4CD8354FFULL
        },
        {
            0xF28B147EAD287B92ULL, 0xEE120D5D37B5F6B7ULL, 0xDFB9C923FDA5D39BULL, 0x5B72B33E737D6963ULL, 
            0x125784445B84E486ULL, 0x889488451C54BD6CULL, 0x46C308CBB032A039ULL, 0x9A257C96F34A0E50ULL, 
            0x6E89C0B02361B5AAULL, 0x6A5516DE2E1CC949ULL, 0x56A4FF619C0C212EULL, 0x183A91FDE21808C9ULL, 
            0x59BE05C707D3A047ULL, 0x1705DD69B3D2E2B0ULL, 0x750221A4667A60AAULL, 0x99F6302BE91C17F1ULL, 
            0xEEC95AC0C269C067ULL, 0x370952071EB50FD1ULL, 0xBE525A5789633813ULL, 0x5D954B078311C16FULL, 
            0xE2F76C3DA93E9B0CULL, 0x34C7104B9C5A307BULL, 0xB0AF6DE4E8AF88ECULL, 0x601E6DDB3FB71BC6ULL, 
            0xCA0D0DEE6DFC1FCFULL, 0xE049F7E7FD9BBF78ULL, 0x62C3A07A36927EC0ULL, 0x1FFFDADCFB8D914AULL, 
            0x75566DD284BD3EADULL, 0xEEB751740CB1153FULL, 0x1B3B3ABFC7190D38ULL, 0xE65FDCD610FDCCECULL
        },
        {
            0xF2A6A433F7612C69ULL, 0x17E54A08ECE4AC2AULL, 0xBF215787DD3BD71EULL, 0x37CF065EB74393ADULL, 
            0x9A35B01C634E6695ULL, 0xD3A4DAED9FD2CBFAULL, 0x986B996F027CF39BULL, 0x9CECE6F3DE787C11ULL, 
            0x8617289E8ECCD344ULL, 0x8C0E5EB458C6F0C3ULL, 0x1172754B5F53F639ULL, 0x20DFA558630BF962ULL, 
            0xD2F9C1730BE18BF8ULL, 0x992384AD1CC3D333ULL, 0x625A3E97A7F35584ULL, 0x01DC62D37C7932D1ULL, 
            0xB8C87712A56B4CCEULL, 0xD397526053B13434ULL, 0x62FBF6BBA72BB596ULL, 0xB500B6D3A90B7ACAULL, 
            0xBAEF8A4E5702CE76ULL, 0xAA01F65495FBB8AEULL, 0xDE5FCE8AF273138FULL, 0xF1F9E63F34B17B01ULL, 
            0xD89C96976CD5057BULL, 0x09B02B2B5EC64A82ULL, 0xDADA1257FAC5F8FEULL, 0x5CAEC8CAC726F2F4ULL, 
            0xE7134BFCE00A603DULL, 0x07837A9A5C213E58ULL, 0x457F0F549E69092AULL, 0x81EBD285AF28C357ULL
        },
        {
            0xDCA9EFBFE16B5729ULL, 0x3E151E89AF430D14ULL, 0x2FCEFCDBB95B866DULL, 0xCC43DB8ACAB86D4BULL, 
            0xBC39368CAAAB86BBULL, 0x9D67BA67FF0964DFULL, 0x8512D5513C2D6C23ULL, 0x7A7FD1C8575F1E97ULL, 
            0x2CCEE900809E123AULL, 0xC95AA40868B95A68ULL, 0x0C4E03C4CCFE7819ULL, 0xAA9A3C1ED91CC186ULL, 
            0x599A6C40516F8897ULL, 0xB80142EBC4DB0A80ULL, 0x4133CBED8EC3150EULL, 0xA2014CF91E3FDDAAULL, 
            0x90D922EBF622D663ULL, 0xC09C025565A3FF00ULL, 0x2FD2CF601A67528EULL, 0x970D5C53B09A15DAULL, 
            0xA977B74F9410A130ULL, 0xFF4F9C079A856561ULL, 0xB086E3BEA091D02FULL, 0x2EE823D8D596052BULL, 
            0x902F5BAF2B0DF7CAULL, 0xCD6EC6D2EABE9688ULL, 0x332C43A88016EDDDULL, 0x966F7796201C95F1ULL, 
            0x71AC9146FDC3D0C9ULL, 0xAE16CF9B5965452AULL, 0xBBDFF14E3C2BEF09ULL, 0xCD93ED8A98F3CD1CULL
        }
    },
    {
        {
            0xA56B6C2D3F83DDA9ULL, 0x65805EC7E5B9B83FULL, 0xB301FD629C5A7A95ULL, 0x2FFDD81B67F559CAULL, 
            0x5233FE93BA90868EULL, 0x5E47035C30B77B9FULL, 0xAE4D4BBF2FB8E485ULL, 0xF815735697A890FFULL, 
            0x147098BD55F18AA5ULL, 0xFF4F7D02422EFC13ULL, 0x48049EE1AC2D2495ULL, 0xC7CBFB1BC333129AULL, 
            0xBCD4842E156ABADBULL, 0x1F916D36FD9126B2ULL, 0xED149922516224E2ULL, 0x6E2BE65B2E31DF88ULL, 
            0xD5E0D572ADBDAEF2ULL, 0xC283D2190360DD5BULL, 0x27F723B08488712FULL, 0xFFE89BB2D5151990ULL, 
            0xCFD5C1D0EAF157E4ULL, 0xB6EE274DC94D62DEULL, 0xC841896ACFB8E6B0ULL, 0x6B6E6DE71C2BE313ULL, 
            0x3E5BF0926678DD7DULL, 0x027A3F56C6C6D4A3ULL, 0xC4F2F8A8B25558A8ULL, 0x19F46213F7EB484CULL, 
            0xA94DDFFD997652A1ULL, 0xB048C3278B518E28ULL, 0x715CFACF404C39D2ULL, 0xF08E892BB99CED0CULL
        },
        {
            0xF2F1A79576826C5CULL, 0xC11D37239516B0C5ULL, 0x4F697798DD9B2D8BULL, 0x501E37399B17B4EAULL, 
            0x7F31426AAA8E1086ULL, 0x5A1CA11B246F180EULL, 0x4BE5BB5F0FAD98FAULL, 0xFE86C50F47A99FE0ULL, 
            0x966B6D38CCD60B38ULL, 0x46B944BEB63B09BEULL, 0x9140202E61D6A330ULL, 0x7B29796D7227DC4FULL, 
            0x3F5C6266203DDC8BULL, 0x57A3831C2E613348ULL, 0xA1716D8A19B37CA1ULL, 0xA8116DB2EC0704DFULL, 
            0x971CB4DF151FA65CULL, 0xE93E963C04A4555DULL, 0xF8FDC3F6DA297A76ULL, 0x6C588B0D51B0958DULL, 
            0x8F337A7BC78C0935ULL, 0x51E444C06C092094ULL, 0xBEADEFCFB071BB11ULL, 0xE789323B29A10792ULL, 
            0x1C9872548F166B9AULL, 0x8F04E25AEEF44AA9ULL, 0xECD4F5224520CAA0ULL, 0x751343534A233EC1ULL, 
            0x5F1E461203F04B2EULL, 0xDA2A84AB717856C6ULL, 0x9621A88A7F26D724ULL, 0xC584DD8436E41793ULL
        },
        {
            0x50F0F601302EC808ULL, 0x61B23F1B8C3C0267ULL, 0x98D3DBA7813870AEULL, 0x2A826D35F28AAF3EULL, 
            0x6599769F5E51331CULL, 0x359A211B98857746ULL, 0x267E50FDAC0704FAULL, 0x6029E2D3C60FF775ULL, 
            0x89954DC086041799ULL, 0xB479DE693FB5B506ULL, 0xBE654DAE5AD259C2ULL, 0x6E5DE65B23D92CE0ULL, 
            0xAD5F55155B8385F9ULL, 0x434CD60966A6831BULL, 0x759114453DC920DBULL, 0xB873C41AE88C24E1ULL, 
            0x7A08B74AE3493132ULL, 0x363E26FDEC0D831AULL, 0xE5A21A143E52F778ULL, 0x5C7CA1FA22C0C519ULL, 
            0x12E024A7322B9850ULL, 0x00E7E6A14C762006ULL, 0x3A8F755D67520F46ULL, 0xF8D8224D087A3412ULL, 
            0x4B33B39BBF366F87ULL, 0x6D18C6E7D08277A0ULL, 0x19EC2A8DFB4EE354ULL, 0x4E3AD43D9E227807ULL, 
            0xD557A027EBB89D6BULL, 0x30E42E0ABD4ACEAAULL, 0x6D42D74905A7A596ULL, 0x11C167BD2E5DDAB7ULL
        },
        {
            0xCCF79F4374D78759ULL, 0x0D655A057BC0789EULL, 0xCD971062C610175AULL, 0xE0F372CE338EED23ULL, 
            0x7E51A385CCB287E0ULL, 0xB523DF6A5D3E49C5ULL, 0xE0BF1DA82E929B56ULL, 0xBA4FBEDD2C95CABFULL, 
            0x0526408D2CCADB10ULL, 0x0055C69CAD876478ULL, 0x317C70F2FDE63277ULL, 0x008833926C7D22AEULL, 
            0xDE4F2471BA5CDF82ULL, 0x6E31012EA4410F27ULL, 0xA91B6DAFE7430801ULL, 0x10703DD0AD184FC9ULL, 
            0x9886773823B4ADFCULL, 0x130873B5B788258CULL, 0xB64DAD2B6678149EULL, 0x43B47D2CA554C848ULL, 
            0xB089B1ACF9370138ULL, 0x5B76A8CA91927B8AULL, 0x9F7B70D18ED9DDA5ULL, 0x6FE90D4F5A681F95ULL, 
            0x677C7D37F9CE0B90ULL, 0x9DCE68C4321E8937ULL, 0x1CBCB423FF4275DAULL, 0x70D07452430ED50DULL, 
            0x9F38BE44070DFC3BULL, 0x7035544A85E0ABEBULL, 0xE8AD2881BD138768ULL, 0x003D39A6F35CCCB4ULL
        },
        {
            0x05B8EEF1CC0109FDULL, 0x258385556E7B856DULL, 0x171883A77E9C1405ULL, 0x939EB3FF83935D38ULL, 
            0x0178FE5359CCC470ULL, 0xB4358B1669CF83A0ULL, 0xC7A9DB106D59D1DDULL, 0xB438996FD7ECF01DULL, 
            0x91AFC80253DB5351ULL, 0x30F69563D8DD730FULL, 0xFBCCF44BDB94FDEEULL, 0xC1D81F48DFB661CBULL, 
            0xA670D58810FF0D66ULL, 0x9162F0F7357C5A4FULL, 0x2AD53E187537253EULL, 0xC87ADA7FB3157905ULL, 
            0x6C89564FA901CA48ULL, 0xC18DB0A064E774EDULL, 0xD8E4676209EC4D2CULL, 0xB92201A743A39772ULL, 
            0x904332B8981EC622ULL, 0xFEB0BC22825BE453ULL, 0x95D8DC5B41B3DCBCULL, 0xDC499BBE046717B8ULL, 
            0xA8E7679D5EA9725EULL, 0x278273980C376766ULL, 0x37835306B2838220ULL, 0x6CAA2360D6600131ULL, 
            0x1BAF4101428CA2E8ULL, 0xD1019E1473A57C8EULL, 0x8EF810775C998E3DULL, 0x44D87B5DD39B7C8CULL
        },
        {
            0xBD93927A312B3AC8ULL, 0x45631A263045DDE7ULL, 0x2BF34B5FDCB96ED5ULL, 0xAE4C20E366A87BB4ULL, 
            0xA95541A34B5CFFE9ULL, 0x2464867831B45897ULL, 0x9F1F86C7F868BBC6ULL, 0x867814F9D2E7BEEDULL, 
            0x50CBCB18324605D7ULL, 0x201A94DAA8D63FA9ULL, 0xC5FFD5C84D743DB3ULL, 0xB61E08180A0AC007ULL, 
            0xEB1098E8515EDD53ULL, 0xC9361FE3A886FA73ULL, 0x4DC4A94A0911597DULL, 0x6A3AE75A719249ECULL, 
            0xE72AAECDE6FCB7B5ULL, 0x35C545A17A48F2B9ULL, 0x485895CE4555BFEEULL, 0xB8C087C299205195ULL, 
            0x446B565A1A99F79FULL, 0xD4BC17DAE4D73614ULL, 0xACFBAC025BB2C8ACULL, 0x46D1672077FC4A57ULL, 
            0xA023DBEF8963D9B4ULL, 0x0A0A653E7FA5B931ULL, 0x29E07980DB04071EULL, 0x1D15270E570CEECAULL, 
            0x1E13CFD71742BE0EULL, 0x0AC6D7B00F11A515ULL, 0xA09104926C3654A0ULL, 0x13C23156E8FC2B01ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseFConstants = {
    0x5BABED5302F26AD0ULL,
    0xEE6416007F355FECULL,
    0x39D175B4CD5D510BULL,
    0x5BABED5302F26AD0ULL,
    0xEE6416007F355FECULL,
    0x39D175B4CD5D510BULL,
    0x926B871602689F97ULL,
    0xA028CBBA0B6B8A5AULL,
    0x8A,
    0x8C,
    0xA2,
    0x8A,
    0x0F,
    0xD1,
    0xE4,
    0x13
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseGSalts = {
    {
        {
            0x6E6C8745A45CA7CDULL, 0xD90B07D13C7A0F3CULL, 0x70B2CB72862363D6ULL, 0xDC0C271B7D0B6E04ULL, 
            0x5EE09E0EBB12571AULL, 0x7B5F1727E4D021BCULL, 0xA8DCDD2C9163F759ULL, 0x60422B7354DEAF76ULL, 
            0xA97B18450EB785CAULL, 0x2C5BF60812FA5704ULL, 0xB70D3E0C55B22E1DULL, 0x89D9C67345C082E4ULL, 
            0xC982A96A0CECE5F5ULL, 0x58FFBB14C517B689ULL, 0xED6A4722C3F30C6DULL, 0xE63DBEE62E3220A9ULL, 
            0xAC08D1EB6DE0614AULL, 0xBBD72364A1C5EC1AULL, 0x68F59E497869F0C7ULL, 0xCFE099437866EABFULL, 
            0x8502F356D2AC3B6FULL, 0x044970065158677BULL, 0x4D25AE8F1E114F6CULL, 0x0A3FE829A661C22BULL, 
            0x89ED36864BAE8336ULL, 0x050D7BD651E4EFB4ULL, 0x9769E77FC94ED9AEULL, 0xE71A596E2E3FB241ULL, 
            0x36AD611AD218F169ULL, 0x1DF1CEE025EA27C2ULL, 0x3914A40F2F84E385ULL, 0x405FB0C0EE23B176ULL
        },
        {
            0x5F22629DD6A5BF4CULL, 0xEF4BDADA06B3FDABULL, 0xD0378A202F23EE3DULL, 0x7111F1ED5901C4C3ULL, 
            0x513F786A6AD0DF4EULL, 0x3566B78602BEF678ULL, 0x9729C81C93924483ULL, 0xA55FEF36D3121FA1ULL, 
            0x48575792908458D3ULL, 0xD5E3DECE6013D0C7ULL, 0xCA4B00FA79F43BCFULL, 0x1CF0FFBBAFA1AFEEULL, 
            0x2C21B41C42C9E23BULL, 0xF3D2B8DFAB0E08ECULL, 0x4A44BD70A053A09AULL, 0xFA039C0EB82F9561ULL, 
            0x209C2ECF2FD22768ULL, 0x05A5CBD178E3C509ULL, 0x81AC48AA472A8B15ULL, 0x61AF39DA09D6F37CULL, 
            0x016697B4C03E206EULL, 0x26314A23B897A16EULL, 0xCD2F3098442148C2ULL, 0xD9DC9A28079245C5ULL, 
            0xAAD403E22B35C569ULL, 0xA05C88EB20373639ULL, 0x0C9FA89BD402CA7CULL, 0x1AA9A055F42027F7ULL, 
            0xCAD33CA04205660BULL, 0x0A45C70F2F93F06AULL, 0x2BBDC93178776CB7ULL, 0x9487070EE3EFF490ULL
        },
        {
            0x83C7FCDB8E84875DULL, 0x09CB08BC8C69B7A6ULL, 0x58AF3017E742A504ULL, 0xD232D3131C3A9B71ULL, 
            0x7F720041F0E2E6F1ULL, 0x0751C6FA57AE17DEULL, 0x7D61500304CDC274ULL, 0x26B0AACD61EC92DCULL, 
            0x5A225DA1885FD02FULL, 0x4D2B4BA9CAC9A692ULL, 0x362DEA125A25FE73ULL, 0x67FD85C5AE0C4396ULL, 
            0x64617797264F534BULL, 0x42BAB8F2067D4312ULL, 0x7E21FAE01BB19457ULL, 0xB0B28E77C71457A0ULL, 
            0x7BCFA07FC005881FULL, 0x557BBF415DAC0ED2ULL, 0x40408A34BA6F9489ULL, 0xB4A6060A076FBDD3ULL, 
            0xDDF2650025FC89DAULL, 0x041809FC66CC3926ULL, 0x85B05336180654E8ULL, 0x96CD8088EC0BDB7BULL, 
            0xDEE49C136F82FBA6ULL, 0x4DDA5DBFA69BF36AULL, 0xB7C6AB03E27B2C6EULL, 0x410CA909E0F8A033ULL, 
            0x52AA84D06626C508ULL, 0xBC0FD05864FD0782ULL, 0xC41F0CE5A464099EULL, 0x2275357553190126ULL
        },
        {
            0x7EB69D294C5824A3ULL, 0x1B891417A6509D67ULL, 0xC6AEE601B6B9702AULL, 0x2FDD9F81CEBA5F3EULL, 
            0x5C72E1EADD79910FULL, 0x29A3012DF9833811ULL, 0xF7D9342774567995ULL, 0xFC57B3F761EFF53CULL, 
            0x40B157B113BCC11CULL, 0xC5EE084467A5D699ULL, 0x4A18910F67F45695ULL, 0x6FAE57ECC5390096ULL, 
            0xF93D8DEFCFDDD716ULL, 0xC47928558D78F21FULL, 0xBBDADC61D6C3D857ULL, 0x42D823C016909367ULL, 
            0x80C856F3F53101B5ULL, 0xF2AFB585F9665715ULL, 0x2A40E7E5439C30B2ULL, 0xEBC3E71C0782AF59ULL, 
            0x3583F931537123BBULL, 0x9429206711CC3A3BULL, 0x5A7CE52A8F1DD712ULL, 0x627D7BF179714476ULL, 
            0x287A64706E66FE15ULL, 0x67EBCB92EC60F8B9ULL, 0x399FFE7C51122441ULL, 0x3489CA9D467C75F0ULL, 
            0xDB628291C1337668ULL, 0x072C1777E90A3A44ULL, 0xC840683A93B627B0ULL, 0xD6B3255930852BF8ULL
        },
        {
            0x3DEC5929FC12DF1BULL, 0x57DC8FF98F1EED47ULL, 0xAD90D9E5DF220FABULL, 0x4F472EA06CA7EE94ULL, 
            0x71753BBE7684C6B4ULL, 0x9DAD2F2B89721A8CULL, 0x23A6F4EE8DB7247CULL, 0x001782761831C614ULL, 
            0xBD637073120944C5ULL, 0xCF36C31CC82DBA22ULL, 0x475AB009BC2DED37ULL, 0xE0A0C2642D2B8A1BULL, 
            0x9C39185CFF60DB1EULL, 0xBFFC4AF336AE8395ULL, 0x890F6536CEAFD3B0ULL, 0x8973B9DAB85B5157ULL, 
            0x0D71163738917DBFULL, 0x04FFCE9C619B5303ULL, 0x0BE2F1FC92191BF0ULL, 0x4DD80CC2E83F08EEULL, 
            0x5B619F9C8D4DB758ULL, 0xE9D84BFFCD5C0D78ULL, 0xAB8745F07DB32050ULL, 0x7A6079E4205E05C2ULL, 
            0x41A244EB6F4D8EACULL, 0xFA1CF4FC06CF49F3ULL, 0xA55E5970E31C9A15ULL, 0x2F20AFAAA430F505ULL, 
            0x7FBCDC951C19ED44ULL, 0x0C62D2244754C258ULL, 0xF00A97D56A5E04C5ULL, 0x57654A4A75710416ULL
        },
        {
            0xE67DA6BB8B208D8DULL, 0x10A902780597DD06ULL, 0xCF8DF02ED62E2E39ULL, 0xC950D45C9DD232F4ULL, 
            0xCC587BA36EC5D553ULL, 0x0E561A28AB0EA87BULL, 0xE4F13F0B870DBA92ULL, 0xA0D8FCBBBB07B682ULL, 
            0x046C4E31C3B59F58ULL, 0xFECB03CADF25AC98ULL, 0x085D18820BE7498DULL, 0x9A88E6B14359F650ULL, 
            0x5E9DE647A2300029ULL, 0x7C78BE45A1D0C824ULL, 0x16AAE31B86DBD97AULL, 0x9937BDFBDD3EE616ULL, 
            0x05B3BAC41FF8F9C5ULL, 0x1F47E4528AF4D472ULL, 0x13E22442D2819690ULL, 0x4AC1E852C7E7278EULL, 
            0xB8C3CDD8516E479CULL, 0x01F9125AA4DFF96CULL, 0x14F5FB8503FE9E03ULL, 0xF36B35BB7401239BULL, 
            0xE787B63B42231D44ULL, 0x3E25F1DF54ED4780ULL, 0xFBFCD914B24D3E84ULL, 0x4AB958483CB16C73ULL, 
            0x1D340045A387B40EULL, 0xCD0DAED74FEE1CE6ULL, 0xFD2B148DEADF9239ULL, 0x146192C56BD61555ULL
        }
    },
    {
        {
            0x6BDBAB9CBEBBD000ULL, 0xEC15BBCB23AB28A1ULL, 0x8F1B8561F9F5A429ULL, 0x46E2F75F71DFCF90ULL, 
            0x6E372DBE6F819FE8ULL, 0x17CD5C17AA6C23A6ULL, 0xECF31B88838271A7ULL, 0xCC9D92B28897D8B3ULL, 
            0x380B92651FF4DE90ULL, 0x04CB334D01DAA644ULL, 0x5750FC7F89869452ULL, 0x352CFD7346123200ULL, 
            0x623806EAC91F9A11ULL, 0x4751E9CBC7B76E53ULL, 0x101780DC620E03D1ULL, 0x7B9B3A998DBA8062ULL, 
            0xF87C3B5328351322ULL, 0x4F61637E2EEB25F9ULL, 0xAD169AE3D16ED35DULL, 0x1B0F4ABDE6B8205CULL, 
            0xBACE44047E86567BULL, 0xB3172A229EBDCF93ULL, 0x650EF34A874DA664ULL, 0xAC6CE7DBC4199BF3ULL, 
            0xFD3B68A46713AEF6ULL, 0x3EF43102334C1367ULL, 0x5D0B51C0A957A568ULL, 0x0973EED6B00A6B44ULL, 
            0x08E3B9D970BEBE70ULL, 0xA4B51144D2C24790ULL, 0xC960399DB2974A16ULL, 0x76A71B122BF7C820ULL
        },
        {
            0x283075F3F509B62EULL, 0xA6AD54F7BB3EF4D3ULL, 0x483E99C73CB1DEF5ULL, 0xCF149132A3E9FCABULL, 
            0x9280BD2C8275EB4BULL, 0x263FFF15C4A30227ULL, 0xB031922F5BD77B14ULL, 0x37BB1714DB5BE794ULL, 
            0xE197D35FD007B7E7ULL, 0x1DDE1F3329DB19FFULL, 0xE4F2A313FDECF84DULL, 0xD5DAE52C075C3D1DULL, 
            0xA8DBD65841E44E7AULL, 0xEEE46BCFB3BDD6B4ULL, 0x35AE628737F1A00CULL, 0x360D4A86C4CC13F1ULL, 
            0x5C31FB9E09425F40ULL, 0xAD6FDBF103D25735ULL, 0x1647BC466851421FULL, 0x4EF3A51ECB95DB1DULL, 
            0x34D0289244A2E044ULL, 0xBCC8F1FE1D21F214ULL, 0x4443B36F24CE55B4ULL, 0xB4C574ABA00A30DCULL, 
            0xA165F533A8C08FBCULL, 0xD1A7F7C9A1D5D479ULL, 0xFCE5EACF6B587B14ULL, 0x3FD0C3CA63AB0457ULL, 
            0x5544E3C6EEC73E4BULL, 0x49F219F17529B355ULL, 0x3B0DB43EC559FB72ULL, 0xC602B612066F88A8ULL
        },
        {
            0x403889C4B854BBCCULL, 0x2FE361A3C4E0F5FBULL, 0xA6099C805CF85931ULL, 0x36B07183C3135D13ULL, 
            0xE4BDFDF25E189046ULL, 0x5C6F154601B03ADFULL, 0x89853BD69CB71FDDULL, 0xBA8FF9E9B5DE6CCFULL, 
            0x009337FAAE219738ULL, 0x95D8DCCABF1630ACULL, 0x126F3863DE402B22ULL, 0x94BA79CBAA3BD2CCULL, 
            0x93831DE4DF5E6DB9ULL, 0x09C21094558B5A1FULL, 0x4DD8B7F71E23AC1CULL, 0x85961EE2F551986CULL, 
            0x3B0E4C32D73A58F6ULL, 0x6E15ABE44602CEDCULL, 0x75279427D9705149ULL, 0x7FD65F2C5F5DB02BULL, 
            0x8FF5924ADB86E4E4ULL, 0xB406856FE3CFA6C3ULL, 0xBF40FE4AD847A001ULL, 0x332480BFB25C4551ULL, 
            0x23C7CFC2ADE816EDULL, 0x8DB2F0EF08ED184FULL, 0x9FD9396276CCD596ULL, 0xB00161C9A4002E9AULL, 
            0x57B69DC6C851A36DULL, 0x1ACBA7CEEF41F367ULL, 0x28A414E9FE1FD28AULL, 0xBB22A115E02D970EULL
        },
        {
            0x9218FD1C1443347DULL, 0x9827B8EECD49F535ULL, 0xD6524C7BD91B3A1DULL, 0x478C414A146F2B1BULL, 
            0x21F38CBFF61DABD2ULL, 0x81E2006BA8F2B7E5ULL, 0x5E888602B34A7347ULL, 0xC83BF5B557C6B148ULL, 
            0x5CCDE5CEE3BD7145ULL, 0x5890DEE92381B514ULL, 0xF26ADDAD7AE45CB7ULL, 0x749DB75578F6A596ULL, 
            0x6844C1B88B2065F3ULL, 0x655C853CB94BB5DAULL, 0x324A8E971DC352E5ULL, 0x095D34684197401AULL, 
            0x1DC98DCCC3911DBAULL, 0xC73460200C364DACULL, 0xF120BCFCD107AB2DULL, 0xDD8914F7C02548F7ULL, 
            0x1AADEBA7D79F2B07ULL, 0xF48DE0012BC94176ULL, 0x9590CEDF99409386ULL, 0xADA5B26CA50FF76AULL, 
            0x84EEE0E606AD3C45ULL, 0x8E680F61678EF536ULL, 0x7BD1A5B573418CC6ULL, 0x51B7C59B9BA8E916ULL, 
            0xDF34DE1392C949E4ULL, 0x63311F0FE4BC7C8BULL, 0x4E989D3B1069927CULL, 0x80C6F177CCD7F1DBULL
        },
        {
            0x5EC99EB40C150021ULL, 0x0D10BAD1140E7074ULL, 0xF6F56755D6D79B35ULL, 0x76B0D1BF7191A9C5ULL, 
            0x5185106876E6454DULL, 0x00B703898E8AE758ULL, 0x0FA7BE0A3224F361ULL, 0xC16AF0A0A4290D7BULL, 
            0xED7E329BA78F2277ULL, 0xB40F9605876694E0ULL, 0x7AAA1596CB164544ULL, 0xC0C8719E1E39E5ACULL, 
            0xE2A14FA620BDE826ULL, 0xFD356A5F8E48475EULL, 0x519CB0D2FC4A8DD3ULL, 0x6BA62FC7118B0E84ULL, 
            0xB49C73FAEDD53390ULL, 0x1B2695D8B49DB1EFULL, 0x97C1551FFC02211AULL, 0xE723333BF2C6D606ULL, 
            0x606180429D6007BEULL, 0xBB8EE4DE4033C06DULL, 0x029D66ADE976D6ABULL, 0x01DE966170A85106ULL, 
            0x93B21ABC4111ED15ULL, 0x9C2F4D52047B1C7EULL, 0x5E257AEA6E9B003BULL, 0x284734084018E5D1ULL, 
            0xF0740EDB9ECDD662ULL, 0x22E06316D3451E5CULL, 0xC7F4B0C72EA2833CULL, 0x7BD8821B1B65053FULL
        },
        {
            0x97E675CE3CFB562BULL, 0x034B3F14F8025922ULL, 0xCD5CB427F3B24711ULL, 0x1F8CE131BE9D35C3ULL, 
            0xC98DE70F1FB22441ULL, 0x9311A70B5A3D0CB5ULL, 0x9BE9B0E29FCEE00BULL, 0x2A7D6C612BB7446BULL, 
            0x49729B006BDB0C1DULL, 0x5E43CC76737F7C10ULL, 0xD996EFF0136D01BEULL, 0xABD881F2C529DE55ULL, 
            0xAD34C6BEBB87EE1BULL, 0x81D31F1B95274411ULL, 0xC798F8C558EB1F4FULL, 0x1A21352C162BD106ULL, 
            0xA2713CBEAE00EAF6ULL, 0x661D2F068F2CE5C9ULL, 0x33D0C971F8FB1C53ULL, 0xF588D23BE8FDA50FULL, 
            0x16C7BD7AD4CA85B8ULL, 0x9CEF8C635F6D2B72ULL, 0xD504185827AE20A0ULL, 0x5F478951828688DDULL, 
            0x566D3A7B53E85C25ULL, 0x8D6A50862C6410F3ULL, 0xE29125BE18DB0EA9ULL, 0x856353509A0CFC4FULL, 
            0x3FD939BC4AE7827AULL, 0x59B6A36B62D6AC39ULL, 0x1E268350DC38D636ULL, 0xFEE0C887833F9292ULL
        }
    },
    {
        {
            0x76C2679BD033994AULL, 0x2E805E38458D03ABULL, 0xA58E31E6BAF23DBFULL, 0x078CFBCD9466C245ULL, 
            0x6FF4A78BDEF76718ULL, 0x845F9283EC5B0BF5ULL, 0x6F21C47B1CFE2F77ULL, 0x1C27F1D0A82B4797ULL, 
            0xB21E2A6731EC1746ULL, 0xB2CC67D87406BA0EULL, 0x749B030B1700EEC6ULL, 0xB8B1DBA555D8E409ULL, 
            0x01FAE332172B226CULL, 0x69DBE52C77EBB44CULL, 0x1B5AF53E5F17184BULL, 0x2DD6CFF24782DF77ULL, 
            0x8AEA283D3E6927D9ULL, 0xA235AE4CAA36B9D8ULL, 0xAA943245A2271A76ULL, 0x21215B76AB3F1B4BULL, 
            0xD6F7EA9210A98E8FULL, 0x29F387FE5FE323CAULL, 0xC5B79C2D78D173F3ULL, 0xCC0D625CADE372B7ULL, 
            0xC9C93AE41519A52EULL, 0xA1BD334F1568EA17ULL, 0x729BB13A4D487C91ULL, 0xAB4C829F172B8374ULL, 
            0x88D3DC5BA4AE3ABBULL, 0xA25E459917079F2CULL, 0xC1F0CE4238F07E8EULL, 0x49404B294B95FB1DULL
        },
        {
            0x0AF30BBA0417DCA5ULL, 0xD4B9158DE782B925ULL, 0xD328F5DC5E2CB3F2ULL, 0x6A207099F01964CCULL, 
            0xB08D82EDB900B364ULL, 0x5B8A2D206E2A35A9ULL, 0xA304BDCF66C5F2B4ULL, 0xE23FE40BF5B9B520ULL, 
            0x0A6DB91FF8EBA0F5ULL, 0x62419FE0AD3EC3FAULL, 0x73E66E65EC908125ULL, 0x36806B361858256AULL, 
            0xAE49DA628C29ACF9ULL, 0xFF27C294FA39EDB5ULL, 0x3BEC196F86C0D732ULL, 0x83F88118BB766409ULL, 
            0x9C7A630A20D7DB73ULL, 0xE9140C397324143DULL, 0x4AC6CD8089E180E9ULL, 0x82260761F36CC213ULL, 
            0x27729E9C5F3CBB46ULL, 0x36A8B13AF882AAD6ULL, 0xAFCF81DF03016A1FULL, 0xEFBA3632AA997388ULL, 
            0xA01CCFA9D6180590ULL, 0xE28AF508CCE3BD26ULL, 0x75DB4C66F0B81B64ULL, 0x70DF70AE53546B83ULL, 
            0xB855B7263D029253ULL, 0x47678A1CE19677FCULL, 0xCDA1716F8673EC14ULL, 0xF47B3C93826F97A8ULL
        },
        {
            0xB4BBE8E5427F8840ULL, 0xE34FC577622E7B65ULL, 0x2B007350E24CD9DDULL, 0xEE9A75D7021C1F97ULL, 
            0x69374F14454028B6ULL, 0xC4CF6FE94052E681ULL, 0x32A269FCEEA58DDDULL, 0x0ECE8326DBC266C3ULL, 
            0x8EA0AA43FFD9DA1EULL, 0x3ED82E9A2E5485ACULL, 0x3877F11F070F2D00ULL, 0x67B9543EE515E011ULL, 
            0x87984FAC17A0B835ULL, 0x9D1EF6B1B32FBAC5ULL, 0xE568C3EDA4D58F68ULL, 0xD19B2F5F87D93CB4ULL, 
            0xA6E79228747E217FULL, 0x6BC2661FB62A56C7ULL, 0xE44D25154B127409ULL, 0x76222F1EFFDE1B02ULL, 
            0x346FEAB640220072ULL, 0x99B82020707FC106ULL, 0x52B7DE1502E15571ULL, 0x18F1C387A49C405AULL, 
            0xC42A0913A143AE60ULL, 0xC1B4E65B965813A4ULL, 0xCB8246F340D66D6FULL, 0x8DDD835B7922800EULL, 
            0xB5F47DC25675F497ULL, 0xBEA8630BFBB99688ULL, 0xB99CDB67C4094640ULL, 0xC2174A34E6C61771ULL
        },
        {
            0x15380FC02A8D4B09ULL, 0xCB482A0DCEF6D0BDULL, 0x3F3A91BA988E7D09ULL, 0x4C94456D2497EB16ULL, 
            0xA9E480855B9F686AULL, 0xD256C86BAB9B6236ULL, 0x188D10DA0D9933BCULL, 0x7017A2BA1F53D407ULL, 
            0xA4DE11E29344BE99ULL, 0x3867612717DF075BULL, 0x408FFCFAF2736857ULL, 0x7DD00FDB9077AF90ULL, 
            0xB703738BA929D033ULL, 0xD8D19520D97F65DEULL, 0xDF02E52827D90134ULL, 0x3DA25F30E850A78EULL, 
            0xCA76B7FB4D26B136ULL, 0x869A2AAB33CDF776ULL, 0xA182174CEE210DBBULL, 0x781AC81731EEAAD5ULL, 
            0x9110166CA7877E0BULL, 0x132613C6C955480AULL, 0xE9ED212D93EBC120ULL, 0xE65C048342F6306DULL, 
            0xDDC75DB6E2F50290ULL, 0x339580162178B2B9ULL, 0x6BAB8959277E409BULL, 0xE1DE330A24086BBFULL, 
            0x5C34D75CA44581F5ULL, 0x65372CA5D15E5E5DULL, 0xCD90AC73DB42E42BULL, 0x3B2789F2EDC3206BULL
        },
        {
            0x5496F2F6F9CAE6E7ULL, 0x7E17C45815EA5B14ULL, 0x4F49E7467B93B9CCULL, 0xA255ED9B0B41011CULL, 
            0xC30BC4AB2C59B96CULL, 0x8CA5780F04949411ULL, 0x632AF709E879A4E5ULL, 0xC633BE399736749CULL, 
            0xB39B1D60A1163AC2ULL, 0x30F2D6FF13DDBA94ULL, 0xA45E50DE8D8A9299ULL, 0x642026C144CFC72EULL, 
            0x8523AFA3BFB5969EULL, 0xC8E8B3AEFDA1A6AEULL, 0xDDD77513B3C0205AULL, 0x61E53F8EA137B32FULL, 
            0x232C17E1825EF0DBULL, 0x00B05791705ACFDDULL, 0x0A45B9C8E4360A78ULL, 0x20949ACEEDA1A99CULL, 
            0x54CE2AEBC4308A86ULL, 0x5A02D7460FDF2AE8ULL, 0xAB34DD50BD2B1B55ULL, 0xE798E6893BF9E2CAULL, 
            0x97DC9D5DA5497149ULL, 0xEE1B901693CF9CFFULL, 0x4D0A093E520BE56BULL, 0x9D557A2B5EB2819AULL, 
            0xBBB574634F285A1CULL, 0x160FEE2AE5CA20F4ULL, 0x2569B8735D9163D0ULL, 0x3DC4DA879EBCA741ULL
        },
        {
            0x5FFE084697269054ULL, 0x6EF1AA5F7E6DC4C5ULL, 0x810F3279D79F9DBDULL, 0x32A58D0D5252560DULL, 
            0x20BA5CD5BA8A28EDULL, 0x2EC873840858470AULL, 0x75622D152BC3EFECULL, 0xD2ADFF7F93370BD2ULL, 
            0x6C45067326248E39ULL, 0x18B86FBCE91512E5ULL, 0x3E7F326E8403DFE4ULL, 0x812A14419975E334ULL, 
            0x14B2FA29D8EEC1D0ULL, 0xC6EC4ED08DB03226ULL, 0xD372EEE5D68BC5E5ULL, 0x2389CA17B6736271ULL, 
            0xB2E4891A3D07FA69ULL, 0x9BE70C01749641EEULL, 0x99F7BCC85865D201ULL, 0x25BCDE32CBCA448DULL, 
            0xB6E8A3A1B9503900ULL, 0x097413F9A842338FULL, 0xD61CF318982E6F53ULL, 0x8D90683418E0648EULL, 
            0x4A04E2DC076801B4ULL, 0xBED8835453386859ULL, 0xB9CBDEA21770F3C2ULL, 0xFC47D8A02C8B5C4EULL, 
            0xAB07990E5A2EE3CCULL, 0x505F3A1287F478A5ULL, 0x159B8AB3EB154CF4ULL, 0xF9DDBF9754F0529AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseGConstants = {
    0xEB925C0B158585CCULL,
    0x05D3E1F258938582ULL,
    0x24FD700661B824F8ULL,
    0xEB925C0B158585CCULL,
    0x05D3E1F258938582ULL,
    0x24FD700661B824F8ULL,
    0x025A8D9666AFA4F6ULL,
    0xD816A011FC6ABB75ULL,
    0xC8,
    0x48,
    0x11,
    0xAD,
    0x65,
    0xB4,
    0xE8,
    0xB9
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseHSalts = {
    {
        {
            0xBB4C0904635E45C1ULL, 0x6A7F98FAF180BB3CULL, 0x81B73FFF97E6B0EBULL, 0x417C050950D31B5CULL, 
            0x41BC162A6C4392E2ULL, 0x87DFCB5F0D8A1CAEULL, 0x09B6E53DDCDCA239ULL, 0xE02A481F2F59FE7AULL, 
            0x031002A8B110DCA9ULL, 0x3C532295072F9258ULL, 0x541B4FEFE07126FAULL, 0x165E15588C386CA4ULL, 
            0x4D03F624E365A892ULL, 0x38BA45B6D6D00835ULL, 0x68CFFBB7D4DD5855ULL, 0x51E1797F2F5A00DAULL, 
            0x341DB493600EB423ULL, 0xD659C9F7228834ADULL, 0x1F7A396E505AC4E7ULL, 0x09B05EAAB39AB334ULL, 
            0xA5FD7B2FEF15B7BFULL, 0xED532728DF512EB7ULL, 0x0A0815D4AB7C0C2FULL, 0x324F0E334D332FE8ULL, 
            0xAE2252F5010E7991ULL, 0x131A5EA3BD567794ULL, 0x99C1DDA96C5558E4ULL, 0xF16E72CF9D35F55CULL, 
            0x14BB42EE718693C5ULL, 0xCC885D5115744D14ULL, 0xC2C9E8382738AB58ULL, 0x08D9AD297FC280DDULL
        },
        {
            0x4C2B9BA0FBA7B226ULL, 0x299FD069797484F7ULL, 0x2C74CFDE5A020AC6ULL, 0xE63DEB4357822F9AULL, 
            0xCC37492B1525430EULL, 0x7781851F11E152A5ULL, 0x3985AF08C615950AULL, 0xEA2ACCB33301A25BULL, 
            0x57C0C61B9BFEB9E4ULL, 0x3F417626DE01689CULL, 0xA8A2026583A6D059ULL, 0x66A5D9ECDEBC960BULL, 
            0xFD07CD695DAADF3DULL, 0xC9D8BF422022AF90ULL, 0x41FF95F580A85393ULL, 0xA22768B38E85604AULL, 
            0xAD03375094FD9CEDULL, 0xEF68BB75F76D08C0ULL, 0xDD4E1D779D6F3DCBULL, 0xF16768F63ED6296CULL, 
            0x9BA7C7EEC097C030ULL, 0xFC83510F9879EF49ULL, 0x371B38C0C7B9115BULL, 0x7ECCD0EA2861D7F7ULL, 
            0xB43F9B6DF995EAE2ULL, 0x47E14A74FE688F13ULL, 0xFE1943CAAA6D6C5CULL, 0x5E7D631ED6E1B7DAULL, 
            0xB7A7F02BBFA74C64ULL, 0x82B19260913F5EAFULL, 0x77302C95E11570A3ULL, 0x8D0F1C6FE1CDEBCBULL
        },
        {
            0x222C9576D650762FULL, 0x6E70157A5804C3F0ULL, 0x728392441BFFB642ULL, 0xC6EC4D045858EA02ULL, 
            0xC3E32ED7DFB272E8ULL, 0x8508A79A011BF23FULL, 0x7DC9656425B97154ULL, 0xD8A18BC740543792ULL, 
            0x9F53C6D41F532AD8ULL, 0x2B0BDA27A7070DC8ULL, 0x84107465FBF75652ULL, 0x408924A686085B5AULL, 
            0x875FA3C24D075AE3ULL, 0x8120F5A6ADFE3219ULL, 0x229494696A2574E2ULL, 0xA55EE85946363489ULL, 
            0x8FEA96241A3E3DACULL, 0x0D465C01A97D2674ULL, 0x7A16F0C54D9D0B51ULL, 0xC033D15C7B74B6A0ULL, 
            0x918F7CB94DEDE270ULL, 0xF59BB36F0369112FULL, 0xDB1980411975E032ULL, 0x79318AFFE2E4AB75ULL, 
            0xF562CF749A28296EULL, 0x44C275F5D223776EULL, 0x09D6EDC8C1EBD473ULL, 0x5E144011C8CF36EAULL, 
            0x594FCA1598B5CBFEULL, 0x8477D376325FC29AULL, 0xC42FCFDD4D635AB5ULL, 0xB1FF7FBD4B4FFCC9ULL
        },
        {
            0x5E12768ACF343012ULL, 0x4EC892B0A714EB78ULL, 0x731B8AEB23DB68A2ULL, 0x5A775FED32002741ULL, 
            0x45FBD154C2AAFE75ULL, 0xAF606AD72A1F7549ULL, 0x80D9FD48F9C58E98ULL, 0x53D31B27903C5D57ULL, 
            0x0532487C1ACC7F72ULL, 0x36210C212EAB8906ULL, 0x47E75B71ECA6CDB0ULL, 0x071C9FC88AAFA25CULL, 
            0xB2C481F580E77F1DULL, 0xBB5D53E4CD374095ULL, 0x6CA32BFE66E544D8ULL, 0xDDC87F9C09BDF126ULL, 
            0x6740C19E3AF23B58ULL, 0x4C0C3A47746EBD03ULL, 0x6B6722D72B8DCF86ULL, 0x817604DFB0870E14ULL, 
            0xBF17F071A1FC68B6ULL, 0x3BA01A51C6D99B15ULL, 0x5ECB3BBCBEA9454DULL, 0x1C4B16EBB226DE30ULL, 
            0x5D9724B7E48514A1ULL, 0x6CB8465BA9D36567ULL, 0xC699BA45AD744CA5ULL, 0x50B0D9027F71ABE2ULL, 
            0x3DC74F28152030F8ULL, 0xFB5393DC65006902ULL, 0x9DD635B387161AE3ULL, 0x463C4F6EA94D4587ULL
        },
        {
            0xED1A5C65C15F3B77ULL, 0x13AB442F86ABDB6BULL, 0xABA51280487B05A0ULL, 0x53A3F6C4E95CE899ULL, 
            0x028D19FE9A556221ULL, 0x96B51C5D938A3B35ULL, 0x6D1817654445D121ULL, 0xF49B60FFA02357CEULL, 
            0x2BE0884C8D5ADA98ULL, 0xBC2A121EEA734C02ULL, 0x707E7B7CA1792BF5ULL, 0x7F2D849492CBAF1AULL, 
            0x0A04A67A17FC363BULL, 0xF074815D2D5ECAFBULL, 0x750B69997E4D6CC7ULL, 0xBC2BB84E052D5D65ULL, 
            0xEF42BF07099B7FA6ULL, 0xF7876394BE7BBAADULL, 0xCCEB5A4CC10302CBULL, 0x64D926A309AA4A44ULL, 
            0x47BDBF6DDAFB9BDCULL, 0xC50326E56CFE602BULL, 0x87488FA5A4578625ULL, 0x0EF1919E6C129F9BULL, 
            0xDAF2D5C4E566BF08ULL, 0x89D1CC0C3BE6D671ULL, 0x5998FDD173912CBDULL, 0x5E9F941C94B11655ULL, 
            0x13833EFCF60F512CULL, 0x0A63B685C63D4182ULL, 0x81A9746A8FE88EC1ULL, 0x2E3EEFEFCC456C98ULL
        },
        {
            0x361C1221A876663DULL, 0xB232DF356B9C9E18ULL, 0xD34AA1448E292D08ULL, 0xC879301E56365A43ULL, 
            0xB3BE5930EA6719A8ULL, 0xE6A97D375D4E2BDFULL, 0x522AA607DEA277B7ULL, 0xA046F8ABD5525325ULL, 
            0x4AE5D719CC458D6BULL, 0xE6B2550BC0C68C68ULL, 0xE398C6C49952D17EULL, 0x58DCE7C36AA0C49BULL, 
            0xEBE8BAF726CE95BEULL, 0xC43E43050566DEE9ULL, 0xEE08FB8F09F88105ULL, 0xB2EC983E220E702EULL, 
            0xC9D4F50C954E09ECULL, 0x5476963E66A99601ULL, 0x640C279F99A03B7EULL, 0xF093FEC8D6C92A4EULL, 
            0x596B814BBE484C86ULL, 0xC3102011BE2DA9C8ULL, 0x5FC9A7F4491A9CC3ULL, 0xD0F882AA3209DBA9ULL, 
            0xB600626D3995E8D4ULL, 0x91FFBE642A605BE6ULL, 0x9D227B27702E2EC3ULL, 0xFF299B5365A307B8ULL, 
            0xC8AF233B0C7B364FULL, 0xC685690C00C233DCULL, 0x1A18CCBE8963E4C0ULL, 0x502D3384AD7E7D8BULL
        }
    },
    {
        {
            0x83EF39C443704B10ULL, 0x6FB68FF804583EC9ULL, 0x70D9D3B654CEEB7BULL, 0x744119C45D2330C5ULL, 
            0x75EAEE57ABE51FC6ULL, 0x22863E782B0790A4ULL, 0xCAE1D8A61CCE794AULL, 0x873DF8005E80C496ULL, 
            0xD5A0238643514F60ULL, 0x163C672177A44D1BULL, 0x2934733AC0DB198BULL, 0x66A4171ADD0C65C6ULL, 
            0x80BD4B39A0EE6D00ULL, 0x31678A5E6CA1C830ULL, 0x40C68A68B4BC5CA2ULL, 0x026E6AADE6F7A814ULL, 
            0xE83CAFE8B04CC4CBULL, 0x3AFD1E961CA8F6FFULL, 0xE60F670DE154DBE6ULL, 0xEFC77760D164D0B5ULL, 
            0x0DB33CE1DBBDA8ACULL, 0xA250F52468E48E2AULL, 0xA6EEA134FC5062DDULL, 0x4C5109A49F84ABC1ULL, 
            0x3E92CF4113ADE22DULL, 0x61AE7788ED2E48C7ULL, 0xB06871159D15CBCEULL, 0x022693590F4A1701ULL, 
            0x46FAF6EAFB29BF23ULL, 0x83A0195D15B0822EULL, 0x864478893BE50B58ULL, 0x410291BB7DC70B11ULL
        },
        {
            0x5876D00CDBB96BFFULL, 0x9CD1AFA88B54B3FAULL, 0xA84F35B5C9061465ULL, 0xCC58E3AC1F6659F3ULL, 
            0x6E62E5DE871396F8ULL, 0x606901B625AA9F59ULL, 0x411C91119FCA18F5ULL, 0x23CA0AC7CFFE2720ULL, 
            0x62E3B4DCCDC510FFULL, 0x79AC6DA587055B98ULL, 0x55CF6C11BA9DB003ULL, 0xEBEBBC338382A7DDULL, 
            0x7A4C471DD830ADDDULL, 0x6AFC5BE4FFD7FCDFULL, 0x9BF753E6277ECC75ULL, 0xCD7A88499CAC2A52ULL, 
            0x576FECD4B1A39BEAULL, 0xE78FE80EC0D2E348ULL, 0xF4C2A889CA96E53EULL, 0x2EBDD9EE41A4EDA2ULL, 
            0xA7B3E91D19817410ULL, 0x919011988C6D9404ULL, 0x68204D037EA6C1B2ULL, 0x6CB6C6AF25B87D1EULL, 
            0xC8B404DD6036F1BDULL, 0x72C3086CF07E2F57ULL, 0xB81E5B732745D927ULL, 0xF061E3EC7C0B57DFULL, 
            0x39E1046D3BB2D338ULL, 0xD8AF4AEBD9304174ULL, 0x966B00608473C7B6ULL, 0x828ACBAF9DCA30BFULL
        },
        {
            0x502AB549B7034D1EULL, 0x87D23CCF27AD7E58ULL, 0x3F63F08F749888E8ULL, 0x29B7298B27F8E42EULL, 
            0xCC51D7DE01CD36EBULL, 0xE690B36A8E95BC0CULL, 0x64CFA5DA3564C168ULL, 0x6B3DD4309CA1D832ULL, 
            0x86A653A95B2D2EC0ULL, 0x168459FE86F819CCULL, 0xA6C66D1C94FD36DAULL, 0x213E80FA9CC0732EULL, 
            0x83053C86C9054A14ULL, 0x98C20A8C38CCF44EULL, 0x553D0ECFDB983820ULL, 0x0E16998E2D2A4AF3ULL, 
            0x8F2425F6FBDE4EF8ULL, 0x83D554A760F798B8ULL, 0x43934FA09A6A0A89ULL, 0x341E98B6E3A0053AULL, 
            0x720E69BDB27B245BULL, 0x2FF7485408F44682ULL, 0xAC49B3AE06800C71ULL, 0x1E06A5CA9C875386ULL, 
            0xB01A3D31213DCBA3ULL, 0x671A7E9DB4124DABULL, 0xA878B3AF72A08618ULL, 0x9BBFBE29CA948FFDULL, 
            0x6C2080E132C80177ULL, 0x0BCA03C9E93F9796ULL, 0xDB509D3A7A6C3E35ULL, 0x355EEF43DCC56EF7ULL
        },
        {
            0x2889314AC870D606ULL, 0x2A5BE10102EB9BB4ULL, 0x121A6C8A047A8A8DULL, 0x40042A2102C7980CULL, 
            0x3421A47198F452CBULL, 0x74237A431FDB7699ULL, 0x0EC471D2181230B3ULL, 0x055FC9F0D1756541ULL, 
            0x57068778612DB41FULL, 0xC18DAA4FCA83DEE4ULL, 0x425C8775184A767DULL, 0x84CBCCD0C33D95AFULL, 
            0x2AE3465378C2A08EULL, 0x44E676DB604770DAULL, 0x623600172E81BAE0ULL, 0x6A967095EAF85EAEULL, 
            0x61A6D35404CDE15AULL, 0xACDCDF3C3B3A36D0ULL, 0x99D7669F693CFFB2ULL, 0xD655732BE62A6113ULL, 
            0x4AC40009FA83D46CULL, 0x852E7E06CAED9DA6ULL, 0x2109277575CD2090ULL, 0x67E8A523E8484C8EULL, 
            0xD7EAC8A838AA2EA4ULL, 0x97AC3E583AA7CFA3ULL, 0xD5E069B88FA0D418ULL, 0xCEF905A3B4147C36ULL, 
            0x5885AFBF4BA1E65AULL, 0x4BA46C2558894032ULL, 0x0E9E4D8BADF684C2ULL, 0xD8F1A1DEB537A144ULL
        },
        {
            0x16A56D1962697B1FULL, 0x9A8C53D03E583D03ULL, 0xF083F685725A2255ULL, 0x1A2F99A5F27BE598ULL, 
            0x26C534881813F53CULL, 0x47A08C530726AA64ULL, 0xE1879E6CDB335E7DULL, 0x6B0F65CAB1DC514FULL, 
            0x93D63B8D03954932ULL, 0xDA3D928BC1F5A6F5ULL, 0x74CDC0AF2935D990ULL, 0x6DFBED1027F1073EULL, 
            0x9CFBB7ADE616AD4FULL, 0xCE106394D9AF47ECULL, 0xFB1A0CEF64C3C03BULL, 0xAC95E5064C8B70EEULL, 
            0x20B1CAA0129B300CULL, 0x457A96FD3B674655ULL, 0x8AEA705ADF43BCF3ULL, 0x6DF5ADD28C97D488ULL, 
            0x6FD894C9C4F0C885ULL, 0x4DEFAEC506822FA2ULL, 0xA906203C493FB661ULL, 0x30802C668A8A6AB3ULL, 
            0x9E6B3777DDEF319AULL, 0xE1065383D0BC9D73ULL, 0xDCBDE12CD8F64797ULL, 0x35182DFEC0B0AFD4ULL, 
            0x6557BD19C4AF31F3ULL, 0x5F7CB8CA0FAE9EF8ULL, 0x3F6F1663E3FB84A1ULL, 0xEFE7BCAB9956751AULL
        },
        {
            0x4EF0DF5329D72149ULL, 0x9DDF12CCC98AF0DAULL, 0xB574C01E14BE3354ULL, 0xDFF0E7ECCBB64390ULL, 
            0x5B95D4CA4C8C75C8ULL, 0xA8DFE7349E2CDA51ULL, 0x587AB5132166C893ULL, 0x7B04C9E9BD9BE009ULL, 
            0x6542C6B69EFE1EACULL, 0x08C1690B6A5A1E29ULL, 0x9FB65D5C1BA4BB79ULL, 0xA5D17BEE34924A26ULL, 
            0xC009F0CAEE805B7FULL, 0x84BAFAD3AFACF28CULL, 0xADB0A66885A8603BULL, 0x8A4FF9A275F65D27ULL, 
            0x7A9C2E64EEA85B39ULL, 0x7E0202734E97FB92ULL, 0xCFF79C949BF23E7AULL, 0xBAF75CD219DAE09CULL, 
            0x5CE4D6966522F7F5ULL, 0x14E54FCDF46AB130ULL, 0x2301840145AC26FFULL, 0x1A10CDFACA8D4EB1ULL, 
            0x5EEBF1540B5ED9BDULL, 0x0B0F4FA953699F91ULL, 0x4805544B9B63077AULL, 0x70B0A8B123C9EBA2ULL, 
            0xD211D302E85BE9B0ULL, 0x5B29C8BB95F7046EULL, 0x97CE667593BDFB50ULL, 0xD4A89D2DE7A129B2ULL
        }
    },
    {
        {
            0x30347C5FDAD6AE09ULL, 0x9A8957C1229BA663ULL, 0x2A809BBF4EA0EE4CULL, 0xD9A7089DB99F913FULL, 
            0xCBD94CA627E7F66EULL, 0x56273D6C57E31AF3ULL, 0x329F153232DE3DFEULL, 0x7BA4F7FB8A8F0229ULL, 
            0x3666A3069A30401DULL, 0xA236ABF036289D40ULL, 0x3F1091E4F4710FEBULL, 0x6C6B438BF9CF0797ULL, 
            0x6C3696573A1ED40EULL, 0xE675A3C386625676ULL, 0x364ABF6B5921F715ULL, 0x43EB8C50890765CDULL, 
            0x025997B94D7C9B2AULL, 0xF302347F87D1A711ULL, 0x07280AA6FE397E66ULL, 0xD6327B424528EA38ULL, 
            0x16CFE53781387318ULL, 0xD848E41AD6DA9086ULL, 0x3BD05B4D8A14367CULL, 0x149B7736409D3F0FULL, 
            0x1F583774EBF37B0EULL, 0x1D82E3197CB1EACEULL, 0x3E991AB001475A4BULL, 0xC0CE7EB25882F454ULL, 
            0x6866F8A841B4D756ULL, 0xE7BA2C878DFB6A60ULL, 0x91A5124C0091F10DULL, 0x034EEC57F1B6268CULL
        },
        {
            0x8683F6BFEC7A67E0ULL, 0x3531F37AB7CE2661ULL, 0x011ECC0493B997D0ULL, 0x1C1C7F56C554C000ULL, 
            0xAC0583D9547B6353ULL, 0x8A9957426CA2EFABULL, 0xC8B0F3983BDDAB29ULL, 0xFBCF48AEA0ADC5C2ULL, 
            0x0E51C404BD60D2F0ULL, 0xA327FCD603E693BAULL, 0xFF9A6804395537B1ULL, 0xBFA0F45F2877D516ULL, 
            0xFF1B820A0CE2903AULL, 0x9C33964F69C3B91BULL, 0x8D222973A461B880ULL, 0x1E1931D45B90AC01ULL, 
            0x5EE9CAD2C08DF3C9ULL, 0x6A30F5792E2035C2ULL, 0xE7675E578D61EF6DULL, 0xB480D749781F513AULL, 
            0x39A82ED5F6264D1FULL, 0xE98D6F4F3B05E35FULL, 0xC1F16B0353A694F0ULL, 0x47164097785D6095ULL, 
            0x14D1E8F3299A5358ULL, 0xF56CACEAEF7B6FD9ULL, 0x9AC9052D1217D0E3ULL, 0xAC3CC44B8E02FA3CULL, 
            0x3954BA532B5A5FC2ULL, 0xEB628BEC3492B54AULL, 0x1317CDE9B579FBA8ULL, 0xACDE15B271B29BA9ULL
        },
        {
            0xF0760E34AFA85D58ULL, 0xA66A117B38ED8AF9ULL, 0x3D4FAEB50E5DF4B2ULL, 0x554CB76F9956E584ULL, 
            0xE2064FEC733DBA2EULL, 0xEB91DA585E0EF73DULL, 0xA647011378A3ABEEULL, 0x93F1C86372B6EE3FULL, 
            0x6239E4A639AE6C2BULL, 0xD63D857C3E0FE1D3ULL, 0x2104F21DBB0AAE31ULL, 0x6681B11A52D1A23AULL, 
            0x26C55F6A0BD4DAF9ULL, 0xD11A3ECB81EA04D0ULL, 0x91424EBE55E6DFB8ULL, 0xA5858FB54F745196ULL, 
            0xF4619437B2DC8E54ULL, 0x0398CBE76666413CULL, 0x2D4457421FBF32A4ULL, 0xED53660905C3B04FULL, 
            0xF149947A7086C95EULL, 0xBAB9AFB81FB99224ULL, 0x58187C4098AE4700ULL, 0x748F6753F12E4B42ULL, 
            0xA1BDBA0399B9A4D2ULL, 0x3587EB454A5DAB9DULL, 0x76E3056B718B582CULL, 0xBDC69EA6FA8EBFD8ULL, 
            0x8C26AAC3114D07C3ULL, 0x591E6D39DA78A6C7ULL, 0x034E3EFE0888EE24ULL, 0x74FEECE21C248B14ULL
        },
        {
            0xA85221C8ABEA76B8ULL, 0x5BB74E9670D52470ULL, 0x5692AD3547AFFB1FULL, 0x6728625E47B9FD7DULL, 
            0x83D3F59F7A9D8DD2ULL, 0xE1E8F9CE60605284ULL, 0x7141E28FC1BA7CAAULL, 0xAF83304D296A061AULL, 
            0x1520DAA3A2C37F3FULL, 0xD672750C00A41B1BULL, 0xC484B32DB0E797ACULL, 0xB2969F7BE69CFBE5ULL, 
            0x5898D0D57E76E217ULL, 0xCD9F14F448C6CA20ULL, 0x9E12A71397A68933ULL, 0x09A92E17753C6FE3ULL, 
            0xA766C0112F852BCCULL, 0x602E54817A4F1575ULL, 0x004CD93D6CB3D795ULL, 0xF8422B83F3D8DD14ULL, 
            0xA0E091A6B8CE34D5ULL, 0x3212611FC7FA1DDFULL, 0x4D6C408958200A2BULL, 0xD4CF0872AF7E6D42ULL, 
            0x25548C1794C1A8EAULL, 0x31201E22956E19CDULL, 0xC3543AD4D06A9539ULL, 0xBF01D2AF9032F174ULL, 
            0x772E0874490AD378ULL, 0x16AE7C5D581750B1ULL, 0xA9CD1BB5B7FC7E9AULL, 0xB1E3F67AC0A10022ULL
        },
        {
            0xEA5E20256D146C72ULL, 0x62474660ED3D6C5FULL, 0x42489574AD0D2E4DULL, 0x894AE96FED881A00ULL, 
            0x57E0B6A248758B61ULL, 0x95E06C85E7FCC5E2ULL, 0xADA214D12EA791D9ULL, 0x9A13EDD0C4D929E0ULL, 
            0xFD8996759C3EBE23ULL, 0x828C594FB66ED909ULL, 0x5653EE0A75730FA5ULL, 0xC371237F0FB75ACEULL, 
            0xDC1EB679ED95FFCFULL, 0xDA3446E554C0F01FULL, 0x8A018C6301C20193ULL, 0xCCB287AB3F62A37EULL, 
            0xC68265171660FD22ULL, 0xF1BB80EE6EDF227CULL, 0x8442B7E79A416318ULL, 0x1B31DD0E092BCAEAULL, 
            0x63CE76831C57D1BEULL, 0x5B6E9C3C19C1F4B9ULL, 0xA46254E4C7C2B460ULL, 0xC911462400137C52ULL, 
            0xABA061DEC94B320AULL, 0xD8A05BA0F3AEC429ULL, 0x17BFB880D690CD57ULL, 0xA229559B9D660502ULL, 
            0x628889B135B0CBC9ULL, 0x772FC7640AAA4294ULL, 0x256DB791AB592C92ULL, 0x78C159BB79AF02ECULL
        },
        {
            0xF358E1DF2E17C2F5ULL, 0xF5A45BA229F0C1ACULL, 0x8692A9CE75FD356DULL, 0xC425D92B839FC07AULL, 
            0xDDF7080984DA9F50ULL, 0x2F39949A6082B1FDULL, 0x0F4E09781963950BULL, 0xB5888E01B852BEC1ULL, 
            0x8EBA0FEDA0096FF2ULL, 0x3C0BDAB4B8C74FE4ULL, 0xC073FD49A0BAD9AAULL, 0xF547A12957B3CCFCULL, 
            0xB8819DF11A74B1BFULL, 0xC9B56BE52BA01AC6ULL, 0xA6127409B08B6313ULL, 0xB5EC095A21FF624EULL, 
            0x9E0A26435D0E0D0BULL, 0xAAFDAE7C33084E52ULL, 0xF47FE2AE21F3EDF8ULL, 0x819C22F50C5ED689ULL, 
            0xBB37579BFEBB7A8CULL, 0x90ABE5A0B94A4613ULL, 0xA069324DAC86F88EULL, 0xC7EC70A74C270D18ULL, 
            0x6ED0C8072110CB01ULL, 0x183BBDF6690FE2D3ULL, 0x877C55766200FACAULL, 0x7EC87CC8984003CAULL, 
            0x754DC6CB4B694362ULL, 0xD42ACD98E54560ECULL, 0xDE9A4112FE62DE09ULL, 0x50630C6F70DB2450ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseHConstants = {
    0x179647EFD3A88EE9ULL,
    0x72F80EBDE27BFCA0ULL,
    0xCBB7C7DF0589D5F6ULL,
    0x179647EFD3A88EE9ULL,
    0x72F80EBDE27BFCA0ULL,
    0xCBB7C7DF0589D5F6ULL,
    0x99F60FD313271C91ULL,
    0xFC861DF91DE58954ULL,
    0x9E,
    0x11,
    0x1A,
    0x18,
    0x3B,
    0xAE,
    0xFE,
    0xDF
};

