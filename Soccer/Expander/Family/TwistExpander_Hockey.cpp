#include "TwistExpander_Hockey.hpp"
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

TwistExpander_Hockey::TwistExpander_Hockey()
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

void TwistExpander_Hockey::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 9258412585881470325U;
        aCarry = 15508319720145400688U;
        aWandererA = 11873861655666667464U;
        aWandererB = 13869361678333973009U;
        aWandererC = 13614860371470524300U;
        aWandererD = 16852186574117402009U;
        aWandererE = 11474564880688693290U;
        aWandererF = 16288588114424369736U;
        aWandererG = 12128309417706305109U;
        aWandererH = 11065365267888348964U;
        aWandererI = 10698807787223850284U;
        aWandererJ = 15094967505573155004U;
        aWandererK = 17585176864867646532U;
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
    TwistExpander_Hockey_Arx aArx;
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
    TwistExpander_Hockey_Arx aKDF_A_BArx;
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
    TwistExpander_Hockey_Arx aKDF_A_CArx;
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
    TwistExpander_Hockey_Arx aKDF_A_DArx;
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

void TwistExpander_Hockey::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 16185798480929331917U;
        aCarry = 15672300747777163626U;
        aWandererA = 12447660734486079762U;
        aWandererB = 16359538067812825028U;
        aWandererC = 17574695120862063577U;
        aWandererD = 10355212689992130540U;
        aWandererE = 14860597654170901698U;
        aWandererF = 16569393734457088227U;
        aWandererG = 14505275459516928587U;
        aWandererH = 10722958898210852961U;
        aWandererI = 11958146378293523356U;
        aWandererJ = 17715557051215813589U;
        aWandererK = 13793224082096420713U;
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
    TwistExpander_Hockey_Arx aKDF_B_AArx;
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
    TwistExpander_Hockey_Arx aKDF_B_BArx;
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
    TwistExpander_Hockey_Arx aKDF_B_CArx;
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

void TwistExpander_Hockey::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA8C3AD0A6D8965EEULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xF502712384BF7AAAULL;

    std::uint64_t aWandererA = 0xEF570F3E1465E326ULL;
    std::uint64_t aWandererB = 0xB3B9B202ABF5361DULL;
    std::uint64_t aWandererC = 0xFF88AE89A90BFE13ULL;
    std::uint64_t aWandererD = 0x8CE25FC4B08D7CCFULL;
    std::uint64_t aWandererE = 0x9F361DBEF8DABDDFULL;
    std::uint64_t aWandererF = 0x8EB7269567ECCD27ULL;
    std::uint64_t aWandererG = 0xE8D0B8FAFEF8039FULL;
    std::uint64_t aWandererH = 0xD886EAD34E96E7ACULL;
    std::uint64_t aWandererI = 0xF94562B0848EAE57ULL;
    std::uint64_t aWandererJ = 0xD1EF631D6A54EA60ULL;
    std::uint64_t aWandererK = 0x86EF65F1305A8C17ULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA);
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
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneG);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC);
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
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistExpander_Hockey_Arx aSeed_AArx;
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
    TwistExpander_Hockey_Arx aSeed_BArx;
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
    TwistExpander_Hockey_Arx aSeed_CArx;
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
    TwistExpander_Hockey_Arx aSeed_DArx;
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
    TwistExpander_Hockey_Arx aSeed_EArx;
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
    TwistExpander_Hockey_Arx aSeed_FArx;
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
    TwistExpander_Hockey_Arx aSeed_GArx;
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
    TwistExpander_Hockey_Arx aGrow_AArx;
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
    TwistExpander_Hockey_Arx aGrow_BArx;
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

void TwistExpander_Hockey::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Hockey::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 10928368673721386060U;
        aCarry = 15913261036820122219U;
        aWandererA = 17616534527787494282U;
        aWandererB = 12224013983643228775U;
        aWandererC = 14222532979254044430U;
        aWandererD = 12588168742901823540U;
        aWandererE = 17173786402179521012U;
        aWandererF = 16969385366864759433U;
        aWandererG = 13081874626224025525U;
        aWandererH = 10633862248161494238U;
        aWandererI = 11072300707492613152U;
        aWandererJ = 15692024501049985923U;
        aWandererK = 14151614441234292324U;
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
    TwistExpander_Hockey_Arx aTwist_AArx;
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
    TwistExpander_Hockey_Arx aTwist_BArx;
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
    TwistExpander_Hockey_Arx aTwist_CArx;
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
    TwistExpander_Hockey_Arx aTwist_DArx;
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
        TwistExpander_Hockey_Arx aGrow_AArx;
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
        TwistExpander_Hockey_Arx aGrow_BArx;
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

void TwistExpander_Hockey::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 0, 3, 0, 2 with offsets 5178U, 7200U, 89U, 8056U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5178U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7200U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 89U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8056U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 3, 0 with offsets 6835U, 6261U, 5539U, 2255U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6835U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6261U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5539U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2255U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 1, 3 with offsets 6415U, 1738U, 6038U, 1792U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6415U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1738U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6038U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1792U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 2, 1 with offsets 5684U, 6511U, 3256U, 1155U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5684U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6511U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3256U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1155U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 3, 0 with offsets 1728U, 776U, 1221U, 1283U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1728U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 776U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1221U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1283U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 1, 2, 3 with offsets 807U, 904U, 930U, 1633U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 807U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 930U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1633U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 2, 3, 0 with offsets 1969U, 1986U, 1919U, 1874U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1969U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1986U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1919U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1874U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 2, 0 with offsets 1983U, 120U, 524U, 1894U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 120U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 524U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1894U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 5U, 1431U, 69U, 792U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1431U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 69U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 792U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Hockey::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 0 with offsets 6924U, 1471U, 4358U, 4181U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6924U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1471U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4358U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4181U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 1, 2 with offsets 6609U, 5672U, 3495U, 703U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6609U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5672U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3495U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 703U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 1 with offsets 2501U, 7294U, 7002U, 3428U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2501U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7294U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7002U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3428U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 3 with offsets 4342U, 6143U, 4661U, 3060U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4342U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6143U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4661U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3060U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 6316U, 4251U, 7330U, 4753U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 6316U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4251U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7330U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4753U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 263U, 887U, 988U, 854U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 263U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 887U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 988U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 854U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 109U, 780U, 951U, 456U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 109U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 780U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 951U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 456U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1857U, 1392U, 1590U, 353U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1857U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1392U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1590U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 353U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 977U, 195U, 233U, 1895U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 977U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 195U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 233U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1895U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 1, 2 [0..<W_KEY]
        // offsets: 1126U, 1428U, 1823U, 1852U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1126U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1428U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1823U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1852U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseASalts = {
    {
        {
            0xE6B460D0C5D7A442ULL, 0x38D63A703FAF1DD3ULL, 0xF0672D47D5DEFE2BULL, 0x4586501A76686D90ULL, 
            0xC92BEAE707DF5CC1ULL, 0x7F2D0E1B2FC07237ULL, 0x20B63B3DD2C85228ULL, 0xB971CC7E626141A6ULL, 
            0x7FCF8CB6B798C7A0ULL, 0x6A9A448DABD313F0ULL, 0xC1C19F49C87B5711ULL, 0xAAEFFE69A781959FULL, 
            0x065D8B04BE04E02CULL, 0xC6A6566117A2436BULL, 0x0E362AD4B021A724ULL, 0xE2589DFF249DD5EBULL, 
            0x42197E036E7B40D3ULL, 0x6420D4339E4CFED3ULL, 0x3EE6EAA81D65A71FULL, 0xE26FAC6B730871B9ULL, 
            0x5B46F19B108F13C2ULL, 0xC1CBF5B9F86AE661ULL, 0x64ED13BDFCDE72F4ULL, 0x10BB48D356C8CBB5ULL, 
            0xFAFB7AF7F1D97491ULL, 0x9BFFAD2B48615FC7ULL, 0xD8289008354C23E2ULL, 0xC2BC6E2BA44754CAULL, 
            0x5D2DF85B94CEA2C3ULL, 0xDC71083AB33CE29DULL, 0xF87C1DA985266AEEULL, 0xD1E0C763291CFA51ULL
        },
        {
            0xA9480E748A86BC54ULL, 0x1C4D3F7810EF95EAULL, 0xAADD132CB17D22E1ULL, 0x30CDE31043E944E4ULL, 
            0xB4D4C3C6A8EF2A66ULL, 0xD6A65376621502F6ULL, 0x04A5F1969DEFC57AULL, 0x38E1BE7E3A2D39FAULL, 
            0x9490772DC4DEC658ULL, 0xE87698A16D0D5BB2ULL, 0xC033EA7E6277BD18ULL, 0x37AE45D13471CD78ULL, 
            0x1AB3A099451D8A8DULL, 0x98F8D50FA4FADE8EULL, 0xE0E62A150F811B99ULL, 0x8C760D5ADA0BEF05ULL, 
            0x29C11B1C05BF08B7ULL, 0xD7CC6D566D700784ULL, 0xEE9984F74E2B8BABULL, 0xC719518507D485B0ULL, 
            0xE18595F15EEC5E0FULL, 0xA42EF0320179F04AULL, 0x10AF52EC38F2FED6ULL, 0x449EFA59FA8580CAULL, 
            0x63D842D1678BC583ULL, 0xE1A49142DB2D274AULL, 0xDA7052F7A4F28A17ULL, 0x9CFE07200484FEDAULL, 
            0xDF167C8CCE107C0AULL, 0x1137EA40F3707031ULL, 0xC58A70FEE9398042ULL, 0x2335ECA13B1F3C19ULL
        },
        {
            0x38B1303E1C3DF57AULL, 0xAFBE4B77A2C78DE7ULL, 0x98EE6A0245E5FA25ULL, 0x08730575F19CA7B7ULL, 
            0x2DABD8C6D47CDD9AULL, 0x4CCDBFFEF3701A0DULL, 0x1CEF122F24654E0CULL, 0xA4FEDF9EB4C56917ULL, 
            0xBC76D5EC89375A83ULL, 0x8909035380F296D6ULL, 0x8CDCB7C52D5ED17DULL, 0x137DE2C56DEA225DULL, 
            0xE67F73DF212AD8FAULL, 0xDB9DBED14C2A1E12ULL, 0x38D25C11AC498DB5ULL, 0x5F5168D93309F4F7ULL, 
            0x43662BCCB1E9A7C5ULL, 0x28C915DC4661D1A0ULL, 0x3B1EACE5E53AF587ULL, 0x4B27254C72F45889ULL, 
            0x2686C112C86E4E61ULL, 0xDCB00604074ECEB0ULL, 0x4E82BB9F1F80E066ULL, 0x2026A1C0EAE138A5ULL, 
            0xC9648F6726CCBB99ULL, 0x659D6445897EEB15ULL, 0x22B53CAEACBD8C4AULL, 0xCDADF65607B5B19DULL, 
            0x49CFB0770B874037ULL, 0x88889B7943C7D196ULL, 0x71648819194D8F4EULL, 0xACD3F8B99194BC1CULL
        },
        {
            0xD1D5E35A34F0D2C5ULL, 0xBE90252EC0FF0E51ULL, 0x44470576EE949F4FULL, 0x2FA26FC9DEFE7FF2ULL, 
            0x44466C8E70BFD7EAULL, 0x12A55DA82A9BA415ULL, 0x97DD706054053587ULL, 0x110BA91DD97882BFULL, 
            0x91F1DB0E7FEC8139ULL, 0xE7E30A9F35DF9D52ULL, 0x7E371CACC94A8102ULL, 0xB5258D984373E74BULL, 
            0xB2B41110D74A7922ULL, 0x6E91056811C3B966ULL, 0xF65062C0D19FA311ULL, 0x6D5A9C7A23255E7FULL, 
            0x729CA0A46000C63AULL, 0xED1CD42BF57FBE2EULL, 0x64264273766D4FE7ULL, 0xD7173B56ABC49139ULL, 
            0x304768DDA5664E20ULL, 0x5A96B2BF7914CD19ULL, 0xB621A96697667412ULL, 0x78D54D8D1ABAE157ULL, 
            0xF7DE19280A33673CULL, 0x9A9FB97935363660ULL, 0x55A6159AD0677C94ULL, 0x1B0C9DC83841778BULL, 
            0xEEB6B67123D2FB37ULL, 0x1CEB665D7485F161ULL, 0x554DE775F0E430E4ULL, 0x0CD779173E6E4A7FULL
        },
        {
            0x0A6E46104ACA7418ULL, 0x0C026D3B401021DDULL, 0x0104B6872E28B705ULL, 0xD0CA03BBE0FA96C3ULL, 
            0x3830169389C8A915ULL, 0x6379B8F0A4675A56ULL, 0xD204EB7F5EA1DB87ULL, 0x49654F02540E3BECULL, 
            0xDE452730BCC34853ULL, 0xB246BBCD68921361ULL, 0xB2E85C220EF095AAULL, 0xB9F91D669790E6C9ULL, 
            0xAC8664CB9160B571ULL, 0x7574B117155B5EA1ULL, 0x1A7CD4B2E65ACD67ULL, 0x2470A5D6BE37CB12ULL, 
            0x7771800C292EB682ULL, 0x505A5B4248C72B46ULL, 0x6E3F09C3E707A8C9ULL, 0xD30622D5A4566F37ULL, 
            0xB956F50CDBCAAE45ULL, 0x86A3351E5A19D97AULL, 0x2B664514DA19FC2FULL, 0x286E30039ABB4BD8ULL, 
            0x11BA7CAE9E846DB8ULL, 0x93C045F03F3B4C90ULL, 0xB935697E2BF8D604ULL, 0x9CC9A721D3231D54ULL, 
            0x53B4E930C3841134ULL, 0x60B7B883AAD6BA67ULL, 0x1AC9C9A73D4AD01DULL, 0x2A44D21BAAB23B40ULL
        },
        {
            0x2C5DE5507232FAB8ULL, 0x352BD4A6069CEB0BULL, 0x249598E6905596C1ULL, 0x41A2E724AF2C1651ULL, 
            0xFF516A2E58A9414AULL, 0xD6E7D9712F54F024ULL, 0xEA1D7467274E3370ULL, 0xCFA2A5AD089D33C4ULL, 
            0xBA7DF2657FB89267ULL, 0x250D9BA817FC92C9ULL, 0xBF4AF498338E7031ULL, 0xA7BBBBDB15CCCF1FULL, 
            0xDB252F93872996D6ULL, 0x1620492A0483C05FULL, 0xD849D3FB5C6FA46DULL, 0x089D9BA3FDF92826ULL, 
            0xFDF6F7F0C56D7A6CULL, 0xAE76E329365EC661ULL, 0x5E4E4883F52C701BULL, 0xF44CB09CF8E09583ULL, 
            0x0C52CA4012C182E0ULL, 0xE8C45AFF7BE15AB3ULL, 0x7BE10F3090085458ULL, 0xD56A7C1E0BBB2B1BULL, 
            0x3F010EE821854E85ULL, 0xEB56ED6A7B369EE8ULL, 0x0F62FB79E27012DEULL, 0x049F9A195288C3C6ULL, 
            0xC691D929F6B6E95FULL, 0x0A0CB7DE7BDE2E0CULL, 0x94BD5DBC1083509CULL, 0x42D44B3577EE89AFULL
        }
    },
    {
        {
            0x50E24AD6A842C179ULL, 0xB10067F8AF0ACFCCULL, 0x9EB19FE52CCD3FCDULL, 0x8CC61E41A4AFA2ADULL, 
            0xF950DDDFE0D7F923ULL, 0x2326FE9DFB5224D5ULL, 0x5A4912C5D9098295ULL, 0x5CA9234EF0F5E373ULL, 
            0x2672A5F53A4CA559ULL, 0x926979A3118DA96EULL, 0x23791E299287F822ULL, 0xBF5CA8370684EB9AULL, 
            0x0A4CCA440C14C5BEULL, 0xB35B0B74B42C28A6ULL, 0xFD83579C40C89225ULL, 0x608FA6AD29D675D3ULL, 
            0x3CEEE3A0360BC95AULL, 0xBF99EEFA07EDFFCCULL, 0x884C001BDDB847FAULL, 0x3878C5690A644E16ULL, 
            0x2B1622C138EA5337ULL, 0x4530A18BF8750180ULL, 0x7A84E6D1BE44B1E9ULL, 0xAE11CDA590A62A1FULL, 
            0x70D9976B161FCDEDULL, 0x52D3DDFFEF9F1667ULL, 0xD273302A8253491CULL, 0x94A8EEE00D871A3FULL, 
            0x10F90C4546A86215ULL, 0x2C3C2C18BF24B2E9ULL, 0x82AFD054351B0875ULL, 0xC3CB8C9FD71FEC79ULL
        },
        {
            0x9BE68AED000738AEULL, 0xAAF424EC4500D283ULL, 0x1CE0DD74FAC5BE5BULL, 0x3CEFDFB4BC7A370EULL, 
            0x0A1D9A7279AE7AADULL, 0x2AE6D07572880905ULL, 0x495FA39B08F92C87ULL, 0x2A9D28D4E431BB83ULL, 
            0x295FB44E752135F2ULL, 0x9E146A78010483FFULL, 0x7EEA3EF3290732B9ULL, 0xBE17DD780BAA6279ULL, 
            0x90F04F95D2B5CDA8ULL, 0x84FBCF758D57E2D6ULL, 0xD5D3EB43B0A56E1AULL, 0x16E5295797831EE5ULL, 
            0xA72C796A1345D072ULL, 0xEF34EF28A93E906DULL, 0xF93B2B77D85C1742ULL, 0xAC9631DDAE5C26B2ULL, 
            0x0D23497882D969CCULL, 0x5A25026853D8830CULL, 0xFA326940A861C5AFULL, 0x819FD4DC862A45AFULL, 
            0x2470348A64758914ULL, 0x84C5E8268ACEAC96ULL, 0xA31A2070BEB7F304ULL, 0x35A77D2484D25DB4ULL, 
            0xEBF9037C228C8D46ULL, 0x9DA2956DE2E50B9FULL, 0x202E22D568DFB1A7ULL, 0x6E72CC21A44D7742ULL
        },
        {
            0x442A369D9BB5AE42ULL, 0x86DD9EEC089672D5ULL, 0xFFA83EB94FC504EAULL, 0xA59503BB07E50F71ULL, 
            0xE2D2463FE7B2A2F3ULL, 0x43C9BC9C109A97F5ULL, 0x5D0E443E45B1877CULL, 0xC3C571BCC74935F2ULL, 
            0x00EE3791DF399DD9ULL, 0x0EBD463692EA19D7ULL, 0x3274EF6B1F58B438ULL, 0x04694E9E0CDEE218ULL, 
            0xEAB3FCC03DB6D040ULL, 0x9FA7726852BA8A0FULL, 0x0A5832EAF7C1792FULL, 0x9678E8232A32FCAEULL, 
            0x4855437D47B2C87CULL, 0x44FAD435D9677EA8ULL, 0xE8A0580730AEE061ULL, 0x1BC79F8BF5EAE243ULL, 
            0xB4244BCCD2EAAA31ULL, 0x393A35BEC4BE5130ULL, 0x708873FB5C643B08ULL, 0xE5613741215E6455ULL, 
            0x8E511A403AFAC545ULL, 0x227FB7C5DAFC02ABULL, 0xFF5ABFBC2DB7987FULL, 0x1C4DA1F9322DD00BULL, 
            0xB691EAA89D580581ULL, 0xC258855BD2D554A0ULL, 0x847B5490FB0A6DB3ULL, 0xAB34710144B43A3DULL
        },
        {
            0x60196FE77B10D1C4ULL, 0xC88FA145BECDE2B5ULL, 0xE495F2270432C9C8ULL, 0xE040DF0C1C83CE20ULL, 
            0x98659EABC04CD7E6ULL, 0xA4E6698112ACDCBCULL, 0x54CFFBA297C786B6ULL, 0x69D3FFEBC538D393ULL, 
            0x65F756FE2FB87A58ULL, 0x27224A10DA2163F7ULL, 0x8CB813A738F82A52ULL, 0xC61A5B74DE67C560ULL, 
            0xF2864C858C8F37E4ULL, 0xC2E1CF12EDD13E66ULL, 0x42CD27B631AAADF8ULL, 0x3395F071C10EB814ULL, 
            0xF5BFEFE38A142587ULL, 0x6F4B14A1E465EC30ULL, 0x20F39C3EED473F1AULL, 0xF745B58180322191ULL, 
            0xC7DC89128C6DE117ULL, 0xBE2BE28484F6E56BULL, 0x90B8DE7A459D0533ULL, 0xD4B9C599AA547171ULL, 
            0xDB47CD012140CE7CULL, 0x94BA8BF6332D7DACULL, 0x6C2F8487B0EB4743ULL, 0xEDA98E811E942BB0ULL, 
            0x665021DDC8B3CB12ULL, 0x94312E7FB8D42ADEULL, 0x492B38305A7135ADULL, 0x408BC9EB1FD2DBCBULL
        },
        {
            0x1930C41A15999F76ULL, 0xDCD1B39FB8B1AFB6ULL, 0x3CF4EDACF1CA566EULL, 0xD45661EB8F1F08CAULL, 
            0x95DC4B65497BFEBFULL, 0x411663843924FA20ULL, 0xC379C6A656B6E938ULL, 0x72F7C80B5AD1929DULL, 
            0x4333A2BB33131DDEULL, 0x3FD758E2944E0545ULL, 0x3B63A8E3866C9437ULL, 0x81BF7FE641CCCAD7ULL, 
            0xB12F4C5EBA351BA7ULL, 0x70AB1AC5917A0477ULL, 0x56D9DD66FAC3B31CULL, 0xCA90858DB0365B1DULL, 
            0x19A7FC8129587C04ULL, 0x3757449BCA49EEA5ULL, 0x03BD729207A39E64ULL, 0x3857F2FDF8BCC573ULL, 
            0x094AE16BDEA62EA0ULL, 0xE6CCADCBFF5A68C9ULL, 0x0F5A255FC81BCBDBULL, 0x8059F60A148FD948ULL, 
            0x87C07E5AE923E381ULL, 0xE46C7EC71109881DULL, 0xB462606F299D4DF0ULL, 0xA02D9C79F9661C0BULL, 
            0xED3F4B0B616AF600ULL, 0xF261C097B0582A7DULL, 0x0E652689E4DED72CULL, 0xF93E0B769A78EF3FULL
        },
        {
            0x1B8B421052ABC536ULL, 0xE13566E7C434296EULL, 0xDB51B0BD9FBD1514ULL, 0x5A27EBABC6AB03DFULL, 
            0xAA49D2DBE1262600ULL, 0xB440A8D1076D26AAULL, 0xFF4CA32950C8F82DULL, 0x34A562629FB9EFD5ULL, 
            0x4CF6FA8AFFE9277DULL, 0xEE346C2FB997E68AULL, 0x1D78DB8C28519E21ULL, 0x30CF27B7CC79BCF0ULL, 
            0xDE7509EF7097BAEAULL, 0xA5FD96BE85679F47ULL, 0x2D44CA9BDC9B50F8ULL, 0xFB5CB128108A1E39ULL, 
            0xC4FEE1EBADB91152ULL, 0x982DB036D95071A9ULL, 0xD85112A520596866ULL, 0x03182578C676D91BULL, 
            0x4D498875AC1EA9D3ULL, 0x73410913EFA85061ULL, 0xFB9D59BA8F3C343CULL, 0xAA3FC753C54A2A47ULL, 
            0xDCC02B721AF29E90ULL, 0x287BABA69496BF2AULL, 0x1D4A0C12BEAD1F47ULL, 0x55DB4EC311678E78ULL, 
            0xA164CA69D0AACD26ULL, 0xC294A6186FE193C5ULL, 0xAF058315F8428E0CULL, 0xC43A67F662213C1AULL
        }
    },
    {
        {
            0x4840E54341354FC2ULL, 0xDF0A1C12FD713FA5ULL, 0xB5559BFE140A6B81ULL, 0xE8114E06202FF6F4ULL, 
            0xCDDA9CD10EEF2072ULL, 0x9914F3FB23CCDBD0ULL, 0xFA8B959EF679CCC6ULL, 0x9A1FEC44CC8BCE01ULL, 
            0x55F007D830C9C07BULL, 0xA7E62724E86D3D91ULL, 0xF7885B74845008D6ULL, 0x56BC79E62E9A1433ULL, 
            0x413D471653E3BA98ULL, 0x7522FD03C78FDCC0ULL, 0xF2130ABB59A68CE9ULL, 0xE9708EDDEBED3B79ULL, 
            0x1CC4809015B34D08ULL, 0x653F1AE9D5226728ULL, 0x298E4F95F02C3F1FULL, 0x598240EE84303BF8ULL, 
            0x5A7DC16620677716ULL, 0x5EB4457114B73C32ULL, 0x7762572E201602ADULL, 0x664342A29CD326B8ULL, 
            0x47400DC19576F676ULL, 0x7287F39F808DAD65ULL, 0xC98F04A5A9D0521AULL, 0xD34DF1F42EEA6967ULL, 
            0xF259822E460DE38DULL, 0x3642BE8DE0399446ULL, 0xFC34B8FAF776EBEAULL, 0x70E446BDC30F8618ULL
        },
        {
            0xF5F8206C78D4B4A9ULL, 0xB6F4FDE3D22D2FF1ULL, 0x0375B74F17E32FB7ULL, 0x8B420A157AF0D2ABULL, 
            0x8420B09F8A15B582ULL, 0x517156D0D82607F9ULL, 0x66A7B93088536520ULL, 0x42D88269249A5ECDULL, 
            0x1F322AE364A24434ULL, 0x5CB1FDA730EC8F97ULL, 0x9F139320D15F3815ULL, 0x3D8CAB7899A3C2A2ULL, 
            0xC37D47723FFD7DCEULL, 0xF5B6387E3DC6A97CULL, 0xFAEED5430A4A7876ULL, 0x9F9CC942127F8D04ULL, 
            0x18BFA97B4DEDCC69ULL, 0x0DC20630F301ABDEULL, 0x015F4FDF4B1ADD04ULL, 0x86B6CD440E78E882ULL, 
            0x4429A44765A23379ULL, 0x391DE38782C38DE3ULL, 0x235760B867212483ULL, 0xD6F37D76C707A7F1ULL, 
            0x38EEA78EA00879DBULL, 0x973D754E0F6D67D6ULL, 0xF9C4AC486DB4C5D8ULL, 0x04BC9791964C3F41ULL, 
            0xE2CF8F93EB9A8BAEULL, 0x002AE540373341D5ULL, 0x955297860075675CULL, 0xA56E9B8F70DB5151ULL
        },
        {
            0xC23340247B031A42ULL, 0x9D8897E27FA1A0DDULL, 0x6002502A9B9B586FULL, 0x2640F926E9E6B000ULL, 
            0x9A813C365D016FD1ULL, 0x2698E4B2781AFEC1ULL, 0x262FE1B2DB4A4B1CULL, 0xC75E5369679FA15DULL, 
            0x98EA1EE9E658999FULL, 0x47CC342D417396E8ULL, 0x63A339828E70C8D6ULL, 0xE7AE00BEB067041AULL, 
            0x92926EA441DD7452ULL, 0xE470F3A1FBC6D03EULL, 0x2B961FC1934DD42CULL, 0xE587FEE92F07B798ULL, 
            0x73449F798CFB0AA6ULL, 0x886F291C08D5E75BULL, 0x4DC97CEC07466945ULL, 0x227A2600F93E0423ULL, 
            0xD5DBC933B70A8BDAULL, 0x36E3D30ACD9A3116ULL, 0x8ACD62276C92EBEDULL, 0x7BFAB6EBD0903F3FULL, 
            0x26907F24B34F9DB2ULL, 0x76A1EFFE0986D701ULL, 0x41F1FBD4716EFB0BULL, 0x43F7F88410973E63ULL, 
            0xA421D8596A6E873BULL, 0x98419D266CCC2094ULL, 0xBF3DFAF3281E7A45ULL, 0xE286D87A586728B7ULL
        },
        {
            0x41C3F9219BF17456ULL, 0xB2E7182923CDE79EULL, 0xD7F5DA9AB9B9E6D2ULL, 0x6B267DBF6AC537D9ULL, 
            0x186F7125D1D459C3ULL, 0xEEF0DBBFA453C642ULL, 0xC946F2BB98CE571DULL, 0xB35E7761DB4A2B90ULL, 
            0x0439F730672192CFULL, 0x97E8665E91CB9BD8ULL, 0x24A56FE1FD7AAF16ULL, 0x71B5FD4DBF684F81ULL, 
            0x1A680C1AB09D9946ULL, 0x66027416B272CF68ULL, 0xFC55382E44E6891BULL, 0xA113FB6A927C919CULL, 
            0xEFDFCBD4E9BC1BE9ULL, 0xA51D457B1710673BULL, 0xFC2E442DB4C49D2CULL, 0x31803DDEBDFA1807ULL, 
            0x40484CD1844FA5C7ULL, 0x0DA23E2442F11CA9ULL, 0x70666CC9441E9533ULL, 0xD098328304F589D1ULL, 
            0x2969798491082A33ULL, 0xDCFDDA7DB34AA11EULL, 0xDC0EA3C7E13BA561ULL, 0x9D71B89626D5D481ULL, 
            0x7F988C9A09E41581ULL, 0xC51BB189CA450F65ULL, 0xCB9CE16F8B07155CULL, 0x6B4416994B2A03BCULL
        },
        {
            0x80BD455CF0994D88ULL, 0x1E88ADC4642DF5C0ULL, 0x462E023916AC05DBULL, 0x5A6A6E34FB65FBD5ULL, 
            0xD9B9531C3CA928E0ULL, 0x06963FBFFF772207ULL, 0x99C0B34A20998B91ULL, 0xE358CD7C8C749B86ULL, 
            0xD8B109A8FF95F48EULL, 0x82331069E1501B71ULL, 0x3B5825422EA3AF97ULL, 0xA878ACCD5072CAC3ULL, 
            0x8E5A43C031F69E04ULL, 0xB94AA864F1BD9B35ULL, 0x7881805C0A2A0DE1ULL, 0x073403A8DD1B8B2DULL, 
            0xA011FE0509E5B085ULL, 0xF7220A09E37663B0ULL, 0xC48DC6E03F467EBFULL, 0x57710BD46A3885B4ULL, 
            0xCB6B3FA5A4D9788AULL, 0xC2A2EB4D8BDD2BD8ULL, 0xF9F0569FFA337E83ULL, 0xF111288173BB5B68ULL, 
            0x5F13120A40CB5B98ULL, 0x407299A8512A961AULL, 0x43D5561248D2FAA6ULL, 0x9768E810B8B0F9C7ULL, 
            0xEB23E6C3B7FB7F05ULL, 0x4854FBE66C401BDAULL, 0x274063D2760CFB73ULL, 0x751DBE302BC2ACA7ULL
        },
        {
            0xB862B71F995A4842ULL, 0x69E8DF06705EDC25ULL, 0xF23156E403423C20ULL, 0xA78C16009F6CAF3FULL, 
            0x68320B832CB0D83BULL, 0xCC8874008C5BAFC0ULL, 0x9C75CC6573FF5293ULL, 0x2E55E235BC66BBAAULL, 
            0xCF0659F8A45F7980ULL, 0x8AD02B093A1BC51FULL, 0xFCDB276EBA10CDD4ULL, 0xAA8D362841E927C6ULL, 
            0x2252A83812A5E17FULL, 0x3D33159959B492EBULL, 0xCC045965852260F0ULL, 0x052073F7B201BD7FULL, 
            0x9D7146130E6A597BULL, 0x56BA47E90852FBEFULL, 0x13945C3EBAD0923BULL, 0x09C1D25A88F7E999ULL, 
            0x5946A3B7F1543334ULL, 0x7637A117814D77BDULL, 0xF3F361A18BEDB2D8ULL, 0xAFE58A0B4BD9528AULL, 
            0xE7F06AC9C1A9F021ULL, 0x8245C7892F89F907ULL, 0x73FB688DF2B286EEULL, 0xCC536C8F42B310D4ULL, 
            0x360045AE4A6C1A2FULL, 0x93E1DE0A5EE41010ULL, 0xCE8C3BA717FBEEE0ULL, 0x0A70E87FB2E526D8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseAConstants = {
    0xFA9E451377425624ULL,
    0x73F36B05BC06EDABULL,
    0x400B087DAFF41899ULL,
    0xFA9E451377425624ULL,
    0x73F36B05BC06EDABULL,
    0x400B087DAFF41899ULL,
    0xC3BA25AF399BF755ULL,
    0xDCD7F49A9135A3C0ULL,
    0x5C,
    0xB8,
    0x3A,
    0xD4,
    0xCB,
    0xAD,
    0x98,
    0x62
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseBSalts = {
    {
        {
            0x835A62AD4766EBD3ULL, 0x5F91BF7D8DD74502ULL, 0xE91743A5E9DFC77AULL, 0x02A25BE3840E8646ULL, 
            0x1AE1BFF8760042AAULL, 0x87656F411A48D741ULL, 0x4F1AF630F9AC92CBULL, 0xED82AFAB7D7FE09CULL, 
            0xF6FE863C10AB1D5EULL, 0x08A1139A9F5E6BDFULL, 0x6614B4C2A8701EA1ULL, 0xCBBD489B20D08922ULL, 
            0x5C9493069BE9C26DULL, 0x3A40FE1752DCE3CFULL, 0x0475CD0B63117F6FULL, 0xE0C897CEDE60D63BULL, 
            0x9E1A2B9927F2BC58ULL, 0x9D43F022E4C93ADBULL, 0xA32440CB43B571AEULL, 0xB6323D7970337C74ULL, 
            0xC069167D388A1317ULL, 0xA175B0FABC21DE6EULL, 0x21DB58C7C5185650ULL, 0xDB220E377FFAD8EDULL, 
            0x23033273C6F72C34ULL, 0xC4ABCEA9BE10A86FULL, 0xDA723249A24BF5C8ULL, 0x91B69630F05E257EULL, 
            0xBBDD9C3C5735012DULL, 0x810A964D5EEBEF5CULL, 0x81B78A147BDF4379ULL, 0x40572B0C888CDCF3ULL
        },
        {
            0x6EF8F64BC2D8FE3CULL, 0xA06F6CAD75522E74ULL, 0xBF49E8266D03B64BULL, 0xF8B19139BE19A66FULL, 
            0xCEEB663C2FCAFD45ULL, 0x9A57A595A416EC68ULL, 0x0ED9D7A41E9AD474ULL, 0x9FB5EF9F641A237EULL, 
            0xC627323FBAC357A3ULL, 0x340E7C7FE1ECC7B4ULL, 0x14764D922BD7958CULL, 0x4D38681A5AD52148ULL, 
            0x46FB9ABECF9C2EA8ULL, 0xFE23D550C6C20FE7ULL, 0x9188329221B7A6F3ULL, 0x78E8121FE1ACB965ULL, 
            0xC12822E7A93F035DULL, 0xA7016EBE7532130CULL, 0x88307128508353FDULL, 0x33319E8291FE54B4ULL, 
            0x98563A6CF83939DEULL, 0xD736BFA5B04890D4ULL, 0xB46E6235DB4D5F1FULL, 0xBC8F32A6747E46B0ULL, 
            0xC144A019635A3603ULL, 0xD310FD6D95FD6630ULL, 0xFF9477BCAAEA1AF1ULL, 0xB4F8DC61301AA3DEULL, 
            0x988BD7164A028DF7ULL, 0x0552FA8FF60CE75FULL, 0x69883488E2D91F07ULL, 0x91A1A643011A6ED3ULL
        },
        {
            0x5D2B46B799373647ULL, 0x191445E0605791F7ULL, 0xB0F106C0525CF6E9ULL, 0xE45BB8E6684D89AFULL, 
            0xD69300C8BC15D7CFULL, 0x8F8CBAD3BF31DB9CULL, 0x20C7A385FEC84B83ULL, 0xB33081C18DF307F2ULL, 
            0x79BAC8C40D427978ULL, 0xD42C7AD50337A2E1ULL, 0xB7D2BEF8F35EFEF8ULL, 0xA3C11F54ECC41D05ULL, 
            0xD0E2160E73D0F086ULL, 0x11B65B8081547E79ULL, 0xDF25B19F58FCA790ULL, 0x465459E0A9921B44ULL, 
            0x6B1E3C8DDDFF0965ULL, 0xDC648CED6881D5CEULL, 0x1427743405B9A7C2ULL, 0x94A302A779E7BFB6ULL, 
            0x3D68F8BA0F31DF0CULL, 0xDFBCC260C2D4EA40ULL, 0xD1C997C27511B1F8ULL, 0xBF92AD9EBB71B5DBULL, 
            0x4E6B46420097493DULL, 0x74DCB6AD5E9E77B5ULL, 0xC4EC23120FD36035ULL, 0x15029C78EC63969BULL, 
            0xC0B3D4AB9FF02021ULL, 0x3294C053243B016BULL, 0x937E8E260B376C84ULL, 0xE929D01FE9A4DD36ULL
        },
        {
            0x7CA6A008C77002FBULL, 0xD2BB9D0CA7793DB3ULL, 0x962B4976CA1F2188ULL, 0xFFA9A4690E2437ACULL, 
            0x67C8145DB4961E09ULL, 0xFEE8A50F8D35A52FULL, 0x258B69AE223A62F4ULL, 0x332280A3D96C416DULL, 
            0xC696594D0C350224ULL, 0x555ACF5C0973501BULL, 0x81E8D880E3F2DF80ULL, 0xDE2C84818F726D99ULL, 
            0xD35ABD6B0C930EBAULL, 0x15F1D7ADA559638FULL, 0x5443B90CCD9F1577ULL, 0x865631EA43E439C5ULL, 
            0x8B06FDF0FB4CC8C8ULL, 0x300EC38D3D2786DDULL, 0x73B935BEBCD23C00ULL, 0x113CEDF38F629E95ULL, 
            0x803B8C4BEBF5BA1BULL, 0xE00080A93DE99C18ULL, 0xB40AAA88EDFD4A45ULL, 0x75EED04E1A2E5E06ULL, 
            0x3DF6D97BFEC18CBAULL, 0xE176F5F7CA8ABBA2ULL, 0x5E1D20A912828BF6ULL, 0x2D832DB63983B3B2ULL, 
            0x897E72CC7A893166ULL, 0x47A1C8D52385D250ULL, 0x67A21D721A342668ULL, 0xF559E7ADF68DA53EULL
        },
        {
            0x84E5D9A3111D5544ULL, 0xA8EF8A3E795837FCULL, 0x1D104F2589C0E360ULL, 0x1B7F39273EDE2135ULL, 
            0xF6A4BC5C3518A326ULL, 0x5D1ECA7CC81BDABCULL, 0x46B349C7C26AC857ULL, 0x1CB28C4E119F54FCULL, 
            0x7FC76931920CC2DDULL, 0xE8F3B61EE8F40013ULL, 0x7D5134B0B5309AF2ULL, 0x69909920348BFEF7ULL, 
            0x31E45E1D81A34EF8ULL, 0xF66FC9070269E6E5ULL, 0x10E3F7BC644EC2CAULL, 0x0F1AA8C995D55D4BULL, 
            0xAA1213F6A6F7508FULL, 0xDB178881DD842031ULL, 0x2F3706B5728BB3DBULL, 0x4279A49D03E6E392ULL, 
            0x69B80E70793DDB67ULL, 0x5444554180C5C28BULL, 0x8D1E31417DF88822ULL, 0xC4FF28B53D67B852ULL, 
            0x75E562C5D6EC9955ULL, 0x65308D9AC0244AA8ULL, 0xCD276E221F91F318ULL, 0x151BE0C4FA75094FULL, 
            0xE3276864BAE40883ULL, 0x6ADD5A18B4383376ULL, 0x4EAE2CF94BFF1E1FULL, 0x427573C4C3446762ULL
        },
        {
            0x11309E9FBD79B8E9ULL, 0x5FF383220EDD91BBULL, 0x063A6EAEE9F8E043ULL, 0x6DE3F6108DFE2EEBULL, 
            0xF56A97AF5C149420ULL, 0xE62FC3A58AD6EB31ULL, 0x86FAC61D40BCB97CULL, 0x86145A4FA859DA30ULL, 
            0xF1A65EEAA08D190CULL, 0x33E1913AA788CBA3ULL, 0x2EED6C545710F6E9ULL, 0xF7D98F1C8CD0998CULL, 
            0xD71D3AA1E068474AULL, 0xB1BAE3A6B33481BEULL, 0x1EDA9B1C92F80D3AULL, 0x579A1DD40359706AULL, 
            0x108DDFF76EA209BFULL, 0x6A0CD4CB2D35E470ULL, 0xAD63601DE4870DE4ULL, 0x2EC0BDD05A45F78FULL, 
            0x9A82A6CBE1266658ULL, 0xAA1C6FD0D59BED38ULL, 0x5E11E5B2CDEE62DAULL, 0xC3120C6ECEE54807ULL, 
            0x78DAC861160156C8ULL, 0x9C6ACC7071AF5A88ULL, 0x689B986CCAF66C21ULL, 0x0E060C0F9AF99B5CULL, 
            0xDF62A361DDE23CEEULL, 0x82322D115DE743D5ULL, 0x4B0C09A9DD1E57DFULL, 0xD94643B1D230A6D4ULL
        }
    },
    {
        {
            0x88566535CDDD4858ULL, 0xFC4466ACFE794E81ULL, 0xF462849211486353ULL, 0x173EA54D526F99EAULL, 
            0xC6DE4CDAF4B5CD6AULL, 0xB9C8DCBA56505E5FULL, 0xC2E88494EF793544ULL, 0x829F5F91AF1AB4AAULL, 
            0x28777242C31C501CULL, 0xC6905545A7698567ULL, 0x9FF59A6E4321D116ULL, 0x92CD7F750DA38BCDULL, 
            0x3B7E6ABE27332FEDULL, 0x7D9BAF41CCA192F1ULL, 0xAF021B15FE0FADE7ULL, 0xEE3BB16BAA3E95E4ULL, 
            0xAA77C06ED6F1B3FFULL, 0xB83ACB1E8A5DD4A3ULL, 0x24384D96428C65FCULL, 0xCC9CD79A29CFA702ULL, 
            0x1ECACD5828A75052ULL, 0x15C7F5722B9D19F3ULL, 0xC25A7F9B1F1C3F0DULL, 0xAFFC51BF7C468845ULL, 
            0x7F511C0A2F6018EEULL, 0x56C265ACBE90CF3AULL, 0x4DDD07A67A0D0A63ULL, 0x2C32F3FB854125B1ULL, 
            0xA299D330A875498FULL, 0x233D5C1546DB5392ULL, 0xAE2381BC9E1C7375ULL, 0x5A58C524685C3BBDULL
        },
        {
            0xDF0369E754F29199ULL, 0x24080934F1CC5E1AULL, 0x4AEA5298B4008506ULL, 0x62C82E6FA38FBA82ULL, 
            0xF13BD471BE69B79BULL, 0xA90B942056037372ULL, 0x85197DBDB42665AFULL, 0xCE48BAFDD03A4F16ULL, 
            0x27832CA56DE4D830ULL, 0x840C160DB6D524AFULL, 0x0B91D7079C8C2C3BULL, 0x99CACF85C23354BCULL, 
            0x3D21FA1ED0227D98ULL, 0x2467C2B1AC203414ULL, 0x4AA9451D65F21458ULL, 0x69B73B6B27E45319ULL, 
            0xA11D05D6B6995F74ULL, 0xC0BD17EC9716966CULL, 0x7A7D928C7B5335B9ULL, 0xDC2FF6B859F6D103ULL, 
            0xE1B414AAF5C3E11CULL, 0xF26D57CF1D698DC7ULL, 0xEA59A91554E485F7ULL, 0x04EDAB211A6A8A31ULL, 
            0x0E931F5BEDF49E8DULL, 0x8467D672B16DE69EULL, 0x7A4BA69C8DB390D7ULL, 0xEAFD2DBFD63CAD8AULL, 
            0x9589B0D85E9A5542ULL, 0x9013FAFA55DCC89FULL, 0xBB8A6215A6A3A8AEULL, 0x5DBC5E36981DCD28ULL
        },
        {
            0xFD10D757A785F6B3ULL, 0x9A562C674A4B31A7ULL, 0x94477E4201A33859ULL, 0xAEAD762B01349B8EULL, 
            0xC4930AF3B5C6743BULL, 0x27F8C8EFA80CECEAULL, 0x59C045130D1BFD9BULL, 0xFAFD44574ADCA4CBULL, 
            0x74A63B6DD656718DULL, 0x844923E83DC749C2ULL, 0x66F6A47A8B001236ULL, 0xCE9E5B2E19CD0C6CULL, 
            0xA653C7D47DFBBAEFULL, 0xF6F0A4326AE9AE96ULL, 0xE46C9FF38822235BULL, 0xB112B4D17351A529ULL, 
            0xFB6C67BBAE6CB09FULL, 0xDD30D554CB8368D4ULL, 0xC711E544E4B7F92DULL, 0x691DD788E96F02D0ULL, 
            0x85955F259F45BEBFULL, 0xE08E923BC8438CE9ULL, 0x23E349EA71539617ULL, 0x20A6553F0CC718CCULL, 
            0x4DE7208A61155A28ULL, 0x2B2AF2E37E14D555ULL, 0xE149B8CF2CD275B0ULL, 0x53BD86EC9531E16AULL, 
            0xDF8D7F64F8EB47ADULL, 0xB2F9077BFA587EE8ULL, 0x23A69A344A0A7D8BULL, 0x0A6A43A8B975B96BULL
        },
        {
            0xE3B1833412CB868BULL, 0x75437D7EDEE34D48ULL, 0x75AE5291AE6D309CULL, 0x49F26EA965F7528CULL, 
            0xB353D217CD75ED59ULL, 0x75B3879EA35E97A5ULL, 0x5ABD56CFA094F5A0ULL, 0x12BF106DBD2620C0ULL, 
            0x56024EAD4C7F1FD6ULL, 0xCEC46C2D946B4E86ULL, 0x0D973E856080729DULL, 0xC90E531BFBB241CDULL, 
            0x6238EACB7E9ABC3EULL, 0x8890575B1812BEA3ULL, 0xCCF892B145A14CCBULL, 0xFB15DCE8CE4D1453ULL, 
            0xFCBF4C5A917CDF40ULL, 0x38DD6580A55636B5ULL, 0xAB71CC982ACF30B6ULL, 0x86B7F41DD900E67EULL, 
            0x9DBA553224AE9290ULL, 0x70D6B204A8C0C29EULL, 0x8FF44CB86E789B9AULL, 0x69EF0BC9065FCACEULL, 
            0x6FEC9E04F984BC10ULL, 0xEFC8C6DE24DE2E0FULL, 0x669896AEA09F2C1EULL, 0xC08185CE41967B09ULL, 
            0xAF1897473690E414ULL, 0x69AA295FEDC03B1BULL, 0x502BE4B976B1630DULL, 0x17C11E7260F782ECULL
        },
        {
            0x215608A60804FC29ULL, 0x80926E8CF22B82DDULL, 0x622532CCE050E0E0ULL, 0xE64B27172F5A1101ULL, 
            0x790FF5D6053851A3ULL, 0xDF70FF90D006BBF5ULL, 0xB7D005042087E266ULL, 0xA557D815BE72D693ULL, 
            0x8894A81B73A70079ULL, 0x4CC03CF0B39D4F45ULL, 0xE6EC997577662D7CULL, 0x26388602A1F985DFULL, 
            0xCCDE50CFCD8FBD3DULL, 0x42248AD7D7E3A266ULL, 0x1FDFABEA28ED527CULL, 0x031EA555FB71FBEFULL, 
            0x7EC9FEE0BCD8906BULL, 0x476D27E0BB640FA2ULL, 0xCED7FD67F9F50F1BULL, 0xA0849D22872AB88AULL, 
            0x37F068B0736DAF43ULL, 0xFB2B4656600A0F5BULL, 0x24371736555D495FULL, 0x8E2831DCA16A7F1AULL, 
            0x2EFE934A41CACEAFULL, 0xF3E780368BE2030BULL, 0xD902AA2E4FE99729ULL, 0xC59A78F4D5E64165ULL, 
            0xEBDD9999EAFCB54AULL, 0xDFF49E9585E02A12ULL, 0x45DC97C6DA2EC5B9ULL, 0xDF76C63544885663ULL
        },
        {
            0x16576C67AFF23B43ULL, 0x02012515DB6E6C5BULL, 0xA590BC159D227EEEULL, 0x42BB45A3C714F1D9ULL, 
            0x5D5A5E5A8A5388FDULL, 0xA4E1E1FB27C5A965ULL, 0x164D8361CD4B35BEULL, 0x679275F2EF712252ULL, 
            0x0B8BCF0E1A367C17ULL, 0x47E26075C7E599E9ULL, 0xA7EEDDE2900A314DULL, 0xF1694385FBB43D72ULL, 
            0xC0335D265754107EULL, 0x089E91892185C3D4ULL, 0x4DA4BD100002DFC0ULL, 0xF6C80AB92E94A3E9ULL, 
            0xAD1C3FA8262177CAULL, 0xD4E830C8AF4A6FB8ULL, 0x8C3D235AC164DF3EULL, 0x1EED6901F0C7EAD6ULL, 
            0x8E158ADE71F88DC9ULL, 0x5A26D694AF40FE81ULL, 0xD7DF6312421B35E2ULL, 0xDA6E30BC963A9B15ULL, 
            0xDBFD52A628FE4155ULL, 0x185E4009D3F1CAD0ULL, 0x112E8D20A6F7F699ULL, 0x144A3502449FC01EULL, 
            0xCDF7440B745A5C93ULL, 0xC5B3D4953FAE1DF8ULL, 0x881691F3B9C3A180ULL, 0xC1960F4B11868DA1ULL
        }
    },
    {
        {
            0x7EA89ED4476E2B0AULL, 0xBC09DDBFB701433DULL, 0xA42343CF6EA75262ULL, 0x94D6AC0E794C82BEULL, 
            0x36CA31216F57653BULL, 0xBA8A2BDEC675D9E6ULL, 0x1DACB4628A1B97A4ULL, 0x3A4975ECDE3B5872ULL, 
            0xC484AD952E1FDB18ULL, 0x5079AAF904443AE1ULL, 0xCFD979A36D0BB6A5ULL, 0x40D135254FE94FC0ULL, 
            0xE3711CAD6E48F381ULL, 0xAD18B50CF67CDB6DULL, 0x0F751EE0D0D732DDULL, 0xBFB4A9EBEE65E9BEULL, 
            0xDE87568095C996B6ULL, 0xC2C462AF916C9131ULL, 0xC3C2BE1F361ADA1BULL, 0xC3E341F73187C5F4ULL, 
            0x8D79679A585A3B36ULL, 0x5B45C34195EDF80FULL, 0xF136F01D0338A0C1ULL, 0xA648D99CA0338374ULL, 
            0x41C10DD6FE78C608ULL, 0x923E87A84011B565ULL, 0x593C8E9EEF96E282ULL, 0xDB348B73DDF3E7ADULL, 
            0x093F4E0320A83C04ULL, 0x309CD0B74A74E21BULL, 0xF4AD63EE6AC6C7F0ULL, 0x29DB5662A2347268ULL
        },
        {
            0x0E5D2F0DBF512E4EULL, 0x0C499C283FF30C5AULL, 0xF5A2A3759D6B6197ULL, 0x12ABD6A71DE13C17ULL, 
            0x2935A8CDAB1FA900ULL, 0x84A0A0112D220441ULL, 0xE3C4F7B0A103B9CAULL, 0x92A963E60A4AEE43ULL, 
            0xD949997564ECF436ULL, 0xB3F5A5B3FD826122ULL, 0x9AF897303C3B135EULL, 0x7BD9ECA2CC4DD476ULL, 
            0xAFF78BD465BA377EULL, 0x16DD54DE4955C0E7ULL, 0x822112FA7F204CCFULL, 0xB898807DEE94FDCFULL, 
            0x2BA4A74B4A230CCEULL, 0x91005B0717B09535ULL, 0x73C14C5973B1B93BULL, 0xE1AE14A5A52DC0FCULL, 
            0x3D14142785F9BDCAULL, 0xDC28F8F441FDA52EULL, 0x5426273658C09F55ULL, 0x43490BB068D3AFBAULL, 
            0x66C5B7F5169FE5A2ULL, 0x2885B4DDB60AFC42ULL, 0x7AA917AEDCD1C930ULL, 0x5CF45C0FAA7BAE64ULL, 
            0x216C33D5F523EAFEULL, 0xF4934F6F13A834A5ULL, 0xACABBA1AF1853E3AULL, 0x8C2FA7994F6C5A0CULL
        },
        {
            0x5693C7203F66B6D9ULL, 0x98FD7118EE689E36ULL, 0xDB185B7F173E4D87ULL, 0x9064164D9E5EBDEFULL, 
            0x591E9BC9FE11DEFCULL, 0x01FD884BD7AA1088ULL, 0x3E309CE4E0307EBAULL, 0xB695A501555EDFF3ULL, 
            0xE9AE95ADF1DDC07DULL, 0x78EEAFC96A482EA3ULL, 0xCDFE029BF298FE6EULL, 0x29116807E80CDD43ULL, 
            0xEB27C7768216DFB4ULL, 0x2967AA4052BD88FBULL, 0x406AF86060C28F00ULL, 0x26B242B9B8A144FFULL, 
            0x79ECB749E671DBB8ULL, 0xD35C7694E501D0A8ULL, 0x7C4E352679CA5D1DULL, 0xFB7B2864C40A0834ULL, 
            0xCE8D70ECCFB70059ULL, 0x4BF673C2F4D74FA4ULL, 0xD55B086ECD26CBF0ULL, 0xA89AB8034D67D44BULL, 
            0x6E52F6B977FA0E4EULL, 0x5D1D1782203C8568ULL, 0xD2CEDE1D85E9BAC5ULL, 0x8CC1BD22143979F3ULL, 
            0xB3A0A494A851A65DULL, 0x2F66C9AD1EAA022CULL, 0x78941F3305719EB1ULL, 0x10A796A51FE67768ULL
        },
        {
            0x227742BBC7B77A5CULL, 0xE3B72C429AA03024ULL, 0x7E2A4CF2601EFBA5ULL, 0xAD652B7C5B2B7808ULL, 
            0x39248D548884C8A1ULL, 0x97409C7FB4597253ULL, 0xFDD83A28FA5FDA39ULL, 0x8239D85CD94BCAB0ULL, 
            0x13D94982EFDDA13DULL, 0xC0BF21B49C23A521ULL, 0xC50F7E9D42EF307FULL, 0xBC5F5855A9190E74ULL, 
            0x2F498B57E3CC0F01ULL, 0x37A10E2DACDEF6BCULL, 0x0A8188DA956620EBULL, 0x6FED92393C1C161AULL, 
            0x58ACC065B2AD853AULL, 0x56840E1C34621401ULL, 0xEEB4DAC169EDE523ULL, 0xC4344CAAB470A9B7ULL, 
            0xBC8DC26D59B81E52ULL, 0x3F9316A2994D7A1FULL, 0x14B877F02D895C09ULL, 0xEA06380FCBB073E4ULL, 
            0xA1F57034808225C0ULL, 0x4DDBA944F6DD3843ULL, 0x3CD7911802574843ULL, 0x211DC338143C4223ULL, 
            0xC7FCE78563C51092ULL, 0xC260C98347084B66ULL, 0x0537AF361AD63226ULL, 0xBB9A9138DC48CEF0ULL
        },
        {
            0xF35092F8B112E881ULL, 0xCB480DC00945B0D3ULL, 0x84B399E79566A106ULL, 0xA5B6515457C5F343ULL, 
            0x4676E6462ABBAC2AULL, 0x5862C37812574F44ULL, 0x84BABBBFEE6D7674ULL, 0xEB5B27734BAEE001ULL, 
            0xE392132B1646E52FULL, 0x3F941E501B9B944AULL, 0x96E3114A2DBF1234ULL, 0xA7F056FCC8F1BEDAULL, 
            0x3B580652E5FD6A59ULL, 0x608A6BE53531B44EULL, 0x4369553C1330797BULL, 0xB36031AFE4EA58A6ULL, 
            0xCDB37BD3A0391F62ULL, 0x4B51A998ADE3866DULL, 0xBBE35A16A6B265E7ULL, 0x03DB11D419DA35ABULL, 
            0xAF5342E3BBB0BE46ULL, 0x68133AD8F84DFDB7ULL, 0x20A832376D8B0781ULL, 0xF2218588E3278925ULL, 
            0x853A3C57107582B7ULL, 0xC287AB43B5BE37D2ULL, 0xA03368451E1B25EDULL, 0x5212D3ACA03BD87FULL, 
            0xF288E82BBC7EB251ULL, 0xC325DB23C4B1063BULL, 0xFAB5BF696619DB11ULL, 0xC5BDA73A41026B5BULL
        },
        {
            0xDEE1BBDE576516CEULL, 0x5F5702EED43A52C4ULL, 0x1F135B03AD78F9B0ULL, 0x15EA37242EAACF0BULL, 
            0xD903E41B9FC580A0ULL, 0x1F809EFC2CC70CF2ULL, 0x4394E7829E7BD2C9ULL, 0xF971A3DE171D4312ULL, 
            0xB65578034F4CA5D9ULL, 0x6330D9AD822CA70EULL, 0x56E02A44C4B649BEULL, 0xE8374E1325047E8CULL, 
            0x7DB097B858844408ULL, 0xAF3D8D3F8F7091B1ULL, 0x42045425C59B39B1ULL, 0x305A9FC3084CFEF6ULL, 
            0x04C199B79D9FBE72ULL, 0x06E0DBBA7839CFD4ULL, 0x313C3EFBBD66BB42ULL, 0xBEFCC149A66EB1DBULL, 
            0xDD76AF3F681B0C95ULL, 0x55A1CE8EE709B184ULL, 0x10E5B266930A7A82ULL, 0x8B88FB55D56A32C5ULL, 
            0xA62A6715D197E15BULL, 0x41343164FD25B231ULL, 0x9F51990CF4ECDFE5ULL, 0x63DBED8157EC381AULL, 
            0x91F8006229046D15ULL, 0xEEF35E85FF4F49F2ULL, 0x90A7655746433B03ULL, 0x079DBC587267CFD8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseBConstants = {
    0xF6E5EC78DCCD3276ULL,
    0x76FB2EC479DEAC3EULL,
    0x94AEF5F23FF47568ULL,
    0xF6E5EC78DCCD3276ULL,
    0x76FB2EC479DEAC3EULL,
    0x94AEF5F23FF47568ULL,
    0x18F5F2039B864061ULL,
    0xD84039C5329D18DDULL,
    0x57,
    0xD1,
    0x84,
    0x58,
    0x76,
    0x78,
    0x9F,
    0x3D
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseCSalts = {
    {
        {
            0x4F4F9114F01B0E28ULL, 0x778CFEA2B2A39DCFULL, 0xEAFB2DE9CB1EF7A4ULL, 0x06FEF4D573E17B0AULL, 
            0xC65BBC1CDBE9CC37ULL, 0x3E9C7543CA039A67ULL, 0xFF848E7DAD029FF4ULL, 0x7C8A0C04854C16F0ULL, 
            0xEB461A52A126EE9AULL, 0x62ED25DFF3D38541ULL, 0xA4EAD46BFF279401ULL, 0xF7F71C57CDB2EFEEULL, 
            0x98EF8249C8574CBDULL, 0x207FC9E65F736DE9ULL, 0x7C587A3738EE66ABULL, 0xE1A02938A15C2BE3ULL, 
            0x7E294DF751375B0BULL, 0xE03EF4A46403087EULL, 0x36D8F94C5680351FULL, 0xD5912DA828B3B54EULL, 
            0xD1AD476720E9454CULL, 0x08A980B28CA2CEA0ULL, 0x379324B1B5FFEBCAULL, 0x58044E0003F4C9FAULL, 
            0x04435B7348DF319DULL, 0xC742300A58FD33EAULL, 0x267D6A0FDBAA68EBULL, 0xCA85D9B5BA906582ULL, 
            0xD03673E801572AF4ULL, 0x5E2AC0CCC4E16052ULL, 0x67577BC3554B46C2ULL, 0xF294DDAD61A5D834ULL
        },
        {
            0x9B27AFDCDF154FA8ULL, 0xCE93EA469F42F9D7ULL, 0xE32CC313DB3996D1ULL, 0xC3EBDCDD9CD6FB79ULL, 
            0x49E0AAEF880B281FULL, 0xC1CFCF1AEFD0D8CBULL, 0x1C739296FA8E8862ULL, 0xD41DA44FD1A0FD75ULL, 
            0x75F7FA808899A3C4ULL, 0x678C5EEDACC2D6F9ULL, 0x33AAC1F564639D6AULL, 0xA2EF66E47D06A0C1ULL, 
            0x8F9BC09614DF4758ULL, 0x95E36C8644F9169BULL, 0x1DEF8D699DB0988BULL, 0xA6F401DD7594352FULL, 
            0x530A9CBD7509E1E8ULL, 0x9A284B13BC4213F6ULL, 0x74114CB8A24489B3ULL, 0x6640AB6D9BA74DC9ULL, 
            0x0360EC9F52B09204ULL, 0xF1C1DED33D98A70AULL, 0xA5B39F1F189D2EAEULL, 0x145AADBD05F9284CULL, 
            0x7DE21703989E4D13ULL, 0x4EB501B12287D98FULL, 0xF7FB76518B216BDDULL, 0xCABA436A54F34469ULL, 
            0x74B11A9B656298DEULL, 0x7A1F091E0CD90E56ULL, 0x469C1342364B8100ULL, 0x8B59FA1B45CFAB6BULL
        },
        {
            0x2738EDCDE7E4EC75ULL, 0x65936391667028E0ULL, 0x44F93A8C3237B7BFULL, 0x381DB66EC72C3110ULL, 
            0x40A27C42874E33ADULL, 0x652CA6D7E7610F2FULL, 0x7A55F93236AD6BA2ULL, 0x331CAF3A9D2AF0CFULL, 
            0x90FC48E54D2E95D6ULL, 0x5335DF276B10FD55ULL, 0x436478AAEE3A23B4ULL, 0x10DC394CE1404049ULL, 
            0xDEE9635FE1B10561ULL, 0x02B714E3296ADA2AULL, 0x860050010BC02869ULL, 0x04C7092AE0E71F69ULL, 
            0x9790623519C7BD8CULL, 0xE3F6A7D3DC2573ECULL, 0x686A5D89CB06C471ULL, 0x7E58DD2E7C77B8C9ULL, 
            0x4A002B51929BBDBEULL, 0x031584FE61F4B674ULL, 0x766DC19DF7FC524FULL, 0xEC89E4C3977A58D6ULL, 
            0x9FE23FFF72E595C7ULL, 0x3FD0C725E0042CE6ULL, 0x6A5E456701E1213CULL, 0x98E707DD852F0A62ULL, 
            0xBAE915F1E70335A3ULL, 0x0ECE41FDBDB0A63DULL, 0xBB02D0CEBF504E58ULL, 0x90D86360754DBF33ULL
        },
        {
            0x1EFAB9343F4842CCULL, 0x866B094E6C5F671BULL, 0xE5EC4CE36CACA623ULL, 0x8303D6D7E472BA32ULL, 
            0x82A4D57A7A52B391ULL, 0x633721B93717D29BULL, 0x6A52CBD9F4F2C2D6ULL, 0x61783152E9E30BC7ULL, 
            0x9059F5A9A978FAA1ULL, 0xEBA45CE020BC207BULL, 0x21DDFD258E44EC2EULL, 0xA2E72DA4C6563D36ULL, 
            0x12F10B0CC5B05DF8ULL, 0xECAEAA48C1192D4FULL, 0x0C68F436B1DFCDECULL, 0x200A7783B4983FDBULL, 
            0x0849585A86233D28ULL, 0xDB3F147DF5570D93ULL, 0xDDA326F1FFA8E7D5ULL, 0x95852D3859B13D2AULL, 
            0x4D2513825A02C2CAULL, 0xA807D56AC717575BULL, 0x2D16CA9432CBD425ULL, 0xDAC7966F655A6232ULL, 
            0xDA375E2635AB18CCULL, 0x65EE39B56BEAA48EULL, 0x629E752D9C75549FULL, 0xABE8D6FE92B3C65BULL, 
            0xD071EA293F74FE6EULL, 0xDE43A2A41284D264ULL, 0x74E7E2857C4D756DULL, 0x42B85A9BBF3BF03AULL
        },
        {
            0x711269304A34D776ULL, 0x3E113BD5DB6578F7ULL, 0xA9A578644BA01545ULL, 0xC499BEFCAB786C25ULL, 
            0xEC7F61FE8CD3F1FFULL, 0x63E396C360C40127ULL, 0xA908327482F74327ULL, 0xC86F067501579FF9ULL, 
            0x88D599B7EE8F7661ULL, 0x945B89CE45AFDDBFULL, 0xE164B788F4DA7734ULL, 0xBCE4D4D2B5656D56ULL, 
            0x867E2CD0630A0F80ULL, 0x14A9A4C8DF4311E8ULL, 0x615DE0FDFE11A84FULL, 0xCF58D90F9782F48CULL, 
            0x2AD7B73231ED210CULL, 0xB3D3ED4D3415F5AFULL, 0x928EF3E0B1E901B1ULL, 0xC76973232E5B07F4ULL, 
            0xB09E2CA81C25DE66ULL, 0x5FF61C44E3E11EC6ULL, 0xABD35C3CE0DC69ECULL, 0xC1DBE95360D8920BULL, 
            0x8A6D0416AB11F49FULL, 0x1052E6B0CDB0EE39ULL, 0xB184B6EA5D02DE3FULL, 0x333639047F4653E9ULL, 
            0xBB2D7782363BA747ULL, 0xF7C2E979461BA78FULL, 0xFA01D5695239C9F0ULL, 0x68898F8F39B68A2EULL
        },
        {
            0xCE2BA875F2B147E0ULL, 0x5F56C2C4010B28E9ULL, 0x3E1DD04711D73714ULL, 0xB95D120279F282D7ULL, 
            0x2F5FECBE31E3CFF7ULL, 0x4AD5EFCA9DF1CAE8ULL, 0x446272FDB6747C67ULL, 0x85A67975FE6C66DEULL, 
            0x15AA2BAB91031841ULL, 0xECBED9FB5820AECCULL, 0x93D761EED5A790D9ULL, 0xDBD99782F28F1501ULL, 
            0x5CC29309F07A062DULL, 0x001DA5F00C0D3FB6ULL, 0x0653D83395D03731ULL, 0x0643E24809319F6CULL, 
            0x0B677BDEA66B0C8FULL, 0xFFFED5D0FDE00448ULL, 0x4EB22D934435323DULL, 0x84C392CDFEDCA63FULL, 
            0xF8FE967825ADEB44ULL, 0x6376A01D0531BEA1ULL, 0x6B7CC7051EDD26B6ULL, 0x7342CE620E83B2B5ULL, 
            0x3B6718F959F124A5ULL, 0x94ABEA80DFD0EE47ULL, 0x2B7F359241B959F2ULL, 0x6D40CE0AC04BD76DULL, 
            0x1387382C160D0366ULL, 0x7423D0884522E690ULL, 0xC6D326DFA13A313FULL, 0xFFCDE2A7B9E60641ULL
        }
    },
    {
        {
            0xC6DCC14C1CBE7717ULL, 0xFBCC9AB397E12F96ULL, 0x9662F3F1FB4FE8CCULL, 0x5B52F9108C19C0EEULL, 
            0x37BD085FD07B4DBCULL, 0xA05A267A5FC97C31ULL, 0x0AB97FA4956CEAC0ULL, 0x28F6C5EFE17701F2ULL, 
            0x38510F0B69B926A3ULL, 0xB72BD0AC0D774001ULL, 0xCCE5D4155A0AF2E8ULL, 0x7537E466A0BB29C6ULL, 
            0x93F792E8E06E13BCULL, 0x70D1F80041378276ULL, 0xE6CB5E37CA2FAE02ULL, 0xC62B66551A0AA814ULL, 
            0x3E81C133A7106A96ULL, 0x79AE2F558FE34564ULL, 0x796597E6919AD5E4ULL, 0x6F5E49C0903823E0ULL, 
            0x0EDD018E42A57B65ULL, 0x055840F80DBCA0FAULL, 0xD4F87895F0D107E1ULL, 0x4960774BF526F11DULL, 
            0x8D2668CC58AD3E50ULL, 0x397075E43342B0AEULL, 0x73B9E2E640BF00C8ULL, 0xD0779C1DBFC447F4ULL, 
            0x368DBBCF5C64965BULL, 0xCBE92979284DCB7BULL, 0xEC798F7DFD2F86E8ULL, 0xF238D76DEE94AFDBULL
        },
        {
            0x7CCC0A484CAF2631ULL, 0x1B710C0F6D373F80ULL, 0xBC906FF59E343C6CULL, 0xF695A015961B9D45ULL, 
            0x3355327F819AB30DULL, 0xCB59E1E1D0B7EB2AULL, 0x785A7B9B5713A2E3ULL, 0x36C6D2D2AEC2A0FBULL, 
            0xCCB3312C8CDD6A36ULL, 0xB6146407C5C5D03EULL, 0x0C97C1C941E42C65ULL, 0x9818308F29EA9B76ULL, 
            0x271BC0A3D45E0602ULL, 0x5B53D3EBBF5F0B84ULL, 0x81FBEF83D5900F7DULL, 0xE1ED85FF626587E7ULL, 
            0x6E1A414CD76DB703ULL, 0x147D7EBDE0649AC0ULL, 0xD60309B9F5C41583ULL, 0x1033FEE9E8810A4AULL, 
            0xB19BE5D6E3E6B214ULL, 0xB8805AA25C7B86B3ULL, 0x0E46D9E270DCE19EULL, 0x1157709674C702E5ULL, 
            0x3D2B9CAEA9B78071ULL, 0x5EC5CC4F907DE7DCULL, 0xBBEEC68710F09DAAULL, 0xCF21746A91C18CE2ULL, 
            0xD47B32AB0DA39FB1ULL, 0xAA0E665BB4A5F7EAULL, 0xEE35570F0E4C2B53ULL, 0x4F3EADBB629242FBULL
        },
        {
            0xB68D91DB46B5DF19ULL, 0x6A2B50D57B591574ULL, 0x5CA8B07AC91624B3ULL, 0x397E30F440DC32EEULL, 
            0x0DA265ECFEFA6E79ULL, 0x9B033B92CF765B64ULL, 0xFF812B479B49A148ULL, 0xD957030E64EED7CBULL, 
            0x56388BF4847B5645ULL, 0xABF0E24218DB05F6ULL, 0x5227A63A9F7A23A4ULL, 0xAC4FA00F6D74A424ULL, 
            0x07ACE4E23132576BULL, 0xDB2B26492198B6B6ULL, 0x7A6109BC156B6D28ULL, 0x2F2860F054DFB725ULL, 
            0x62FDE12CA93F1499ULL, 0xDBD964781FE5ADE0ULL, 0x0E485835977DEE62ULL, 0xD409D0C1B5C4DACAULL, 
            0x01A7300004E85FBAULL, 0x64D43A4212688B85ULL, 0x2F6E6B7C0ABBAA7FULL, 0x304183E727BBCDE0ULL, 
            0x1E29E2323B9A335CULL, 0x292E6DF287285C31ULL, 0x21FA54729688D563ULL, 0x9E0A1832BFF71730ULL, 
            0xA76167CD5342E847ULL, 0x5E77D7AAF2D7A785ULL, 0x56F89E77C5C12599ULL, 0x180060891DEF3ECCULL
        },
        {
            0x01C278AE8404CA9DULL, 0x9DAE89B453D7C6E9ULL, 0x67AFE3F3BD257553ULL, 0x94320DA266B1D256ULL, 
            0x504E1362CC66F89EULL, 0xDE4FC65A83F58166ULL, 0xB5CFCA10E51F6998ULL, 0xF0030A7F9239757EULL, 
            0xAEE21AFDBB5CDAA7ULL, 0x19B50B8C2B215D2BULL, 0x1DF673D1A012ABFFULL, 0xE95DFF95490E4242ULL, 
            0xF7B08E0E7ED0576DULL, 0x38D2FF3C8DCC4F1BULL, 0x1BE3DFDFA2D8E421ULL, 0x4723877F99538B40ULL, 
            0xD55589754FF6F12FULL, 0x6246B9B8617C5DC3ULL, 0xB6C37C6542EDCE31ULL, 0xCA45748D90464FE7ULL, 
            0x555B20807754E3FCULL, 0xF5D2E100F20ACDB5ULL, 0xCEE9D1021F21E0B1ULL, 0x93BA416CDD85A62EULL, 
            0x247A08F1F05327D4ULL, 0xD6DD806A16757C64ULL, 0xF75D2B9264F8AD1FULL, 0xDECD78FDBDF83DB6ULL, 
            0x3B89EB4DA03B46FBULL, 0x5A329A18528776A9ULL, 0x2AB5F454E1DACF49ULL, 0xE9631A16ABD4DE73ULL
        },
        {
            0xEE6E3E2DAC8ABB6EULL, 0x558B9824C3B7F0BFULL, 0x6954D0038A5F7D1CULL, 0xF3393BDF45938A9EULL, 
            0x8C5109F2E3A93D79ULL, 0xD626149C8EE227DCULL, 0xB854251820FFC12FULL, 0x2BB867821CDF9EA9ULL, 
            0x11AF97A1E3C7DA98ULL, 0x5F255725C9262690ULL, 0xA4CC1BCC2F272E11ULL, 0x06796B002080332BULL, 
            0x611BB309F1C73520ULL, 0xF35311C72CF9B1A6ULL, 0x91CF3512603A506FULL, 0xC96058BD5F416406ULL, 
            0xF39DABF3C606D3BFULL, 0x3AE6EE52C4499CDFULL, 0x83E6CC0610CE1FB2ULL, 0xC4B28A379C815CBEULL, 
            0x164D2DEE6A87107FULL, 0x2A6D1579F105A6F6ULL, 0xA82EB2A5B35478A6ULL, 0xB471B6F43FEC4EA1ULL, 
            0x849560C65C0435A6ULL, 0x3A0F90059C1F1641ULL, 0xDD9FB8BDF174E6B6ULL, 0x2864E14758801BD6ULL, 
            0x0096C5817B5CBE99ULL, 0x9A2B3B6CB1C36526ULL, 0x257F3AB13AED4A70ULL, 0xBAB0F90300C40B95ULL
        },
        {
            0x507F49A6902087BAULL, 0x8349430B54CB4D50ULL, 0x9599F8C08CA7FB54ULL, 0x3EF1DAF42AC68EBEULL, 
            0x8EE3FDEF87855425ULL, 0x06018FF3837AF7E3ULL, 0x8288CEAB252035FCULL, 0x879AE6D38DFB7431ULL, 
            0xDBE20EB03D4AC056ULL, 0x13B40304F1EE4472ULL, 0x5228E8E4276CEB6AULL, 0x0D5A48A918353380ULL, 
            0x91395C63BC8834F7ULL, 0x3A81CFA68E643811ULL, 0x98BBA56378E2845CULL, 0xC2C65395A6DC089BULL, 
            0xCD690E611E36B20AULL, 0x39785F7C47A11C50ULL, 0x77C1946C2FC4853CULL, 0x7C72C623C4D4690BULL, 
            0xE03E8A1D7CDF5499ULL, 0xC2F5CB90CF678B1BULL, 0x603B3CB29CF3DC94ULL, 0xDE6F0FEF352C6CA1ULL, 
            0xEEA12353B2E1B998ULL, 0xAF1AA88EE3DFD410ULL, 0x0E219329152951DEULL, 0xE047111CD64AB59CULL, 
            0x5C405DADF8386506ULL, 0xE5CA908092856B32ULL, 0x15674DDC8183C3D8ULL, 0xCB38DB32DB57E599ULL
        }
    },
    {
        {
            0xC9515BA5D58A85D8ULL, 0x1DC4FBB739F27D68ULL, 0xE7702A2EB05B111DULL, 0xF2B6F4C067E034E2ULL, 
            0xA4ABDEC61A4AC2E1ULL, 0x2DB40BFCB8462DDCULL, 0xE9DFB3015BD0F983ULL, 0xEA004F10D0EF79E0ULL, 
            0x19DDABF278B5EF2FULL, 0x6E9418565B8F803BULL, 0x546F12E289C647EEULL, 0x4A2C56BFC466CCC8ULL, 
            0xD052C29F2696E2EEULL, 0xD47EA30B8C0C2DC2ULL, 0xFAFD94844C94961CULL, 0x757303486803D6F9ULL, 
            0xC2C02C3B75562B95ULL, 0xF1EFD108F37DCD46ULL, 0xE80573190367F406ULL, 0xABEC5694A7B13E89ULL, 
            0xBD0630A3B1CCA424ULL, 0x59611910EAD6C3E2ULL, 0xBE769B7CE84DB81CULL, 0x78C529952FBE3076ULL, 
            0x9B999660279BAC2DULL, 0x93C5D5EBE4429547ULL, 0xB017E10C8BE82951ULL, 0x73A1BDB5C69F828FULL, 
            0xB6EA5A1222161CEFULL, 0x826837D370ACDC24ULL, 0x622E10744B528EDDULL, 0xA59FCB4C33859DD7ULL
        },
        {
            0x8559CED9F2061A5BULL, 0x0EF0E4F3238ECA85ULL, 0xA4E3771B90C00089ULL, 0x88FC087DC0BD42D3ULL, 
            0x7E4EDDDB1EABC3B1ULL, 0xAB954FF373597BFDULL, 0x7DAA3A89F9D0E52CULL, 0xAF05439E5C473BFEULL, 
            0x225EB9F4D7A7E55EULL, 0x1769B15436AA2DBDULL, 0x1E3F1A5055DAE69AULL, 0x71B7D0A733CA04ACULL, 
            0x6D3957163AAED76AULL, 0xC6FB598398AB6255ULL, 0x89E28294E488EDE5ULL, 0x88DB19B266CC51DBULL, 
            0x6E834BE21290D701ULL, 0x23D4E87E43037C00ULL, 0x3AB76EBFA3C00497ULL, 0x24B688A5D6DA4433ULL, 
            0x37C33DA616546547ULL, 0xFA5E8FDA604D86EDULL, 0x0EDC72D6B5C21C9AULL, 0x2EA7E7AB2896DF00ULL, 
            0xB76D8D6972080A70ULL, 0x2EFCB175AF1ED307ULL, 0x91BA421F68079CADULL, 0x43C978688C31F042ULL, 
            0xA9704F0AA2821C25ULL, 0x41BA38D20083A584ULL, 0x2C80D523A1EEF5CBULL, 0x39A8E21D575F903AULL
        },
        {
            0xF9BBDDD0D3C9D9F4ULL, 0xD7F6902570535216ULL, 0xC8A25C5C4C7BE5C0ULL, 0x0746C7A285532AB9ULL, 
            0xF2C1188C7729946DULL, 0x0F351DED90082922ULL, 0xD32562EC97FF7693ULL, 0x8784F8D58B56ABB1ULL, 
            0xAA34AF8A769A964DULL, 0xDB2890052DD3A7E4ULL, 0x6BD866E699C3D310ULL, 0xB1FB2C92969EF363ULL, 
            0xCAB397DF5A37EB17ULL, 0x3F350518D4132DF5ULL, 0xC090A500EF677062ULL, 0x862C0FEDF31D494AULL, 
            0xE741C3598560FB71ULL, 0x29D054ACBC492A85ULL, 0x988A92013F5126E1ULL, 0xEC57A14F2D8E6B44ULL, 
            0xDE7221B6C61CA069ULL, 0x0817AFF5476D8189ULL, 0xFE450BB2355ADBDBULL, 0xC7AABF5317F262E2ULL, 
            0xB12A30424B109B33ULL, 0x99E0407AEC1A9D41ULL, 0x76E5F7037749BDE9ULL, 0x0FF15E744A2C9C26ULL, 
            0xB103A92D1FD62144ULL, 0x8B8D4E1528F373E8ULL, 0x85B7C7645E307EE3ULL, 0xC90DDE907973C85BULL
        },
        {
            0x015DC024FA80F326ULL, 0xA6F0DC0382C9FD3BULL, 0x36EA1AFD5FA05269ULL, 0x5C2D8C2C4A9AD988ULL, 
            0x97779C77EA30A06BULL, 0x746A182AFE010C13ULL, 0x3BAA222E6772FF07ULL, 0xCA68EF4B1AD50E99ULL, 
            0x8BC0ACEE3861A689ULL, 0x74AC2990FBEE05DEULL, 0xC46FD0CE8700309FULL, 0x0C5549E9501A99CDULL, 
            0xC5C833BB971E0471ULL, 0xFDF6467BD6FDA9B7ULL, 0xE2E3701B4850020FULL, 0xEB90FE689E8EB7C3ULL, 
            0x9E0583C3D91DB2BEULL, 0xC9524E025F1D4EE1ULL, 0xD5CF604071F1136BULL, 0xD621563DDA5CDB2BULL, 
            0xEFBC6562908DD742ULL, 0x8092B5E4DB0F6545ULL, 0x91E9796303796FFFULL, 0x80D43AB903ECD8DBULL, 
            0xC9F97F0EB91D7330ULL, 0x9F0A0B31C529928BULL, 0xB1A1E3DA5BE48B03ULL, 0xD2C2223487965C12ULL, 
            0xF3FB17FCDE6C09C5ULL, 0x22CA7AD169C6F3C2ULL, 0xCD350D760F24A6A8ULL, 0x722F8143DF7A44E2ULL
        },
        {
            0x419889CC1CBCDBAFULL, 0xDF81EE4DDFA4F6EBULL, 0xB539FD1D005C71B6ULL, 0xF89751E3735869BEULL, 
            0x8201A3C863F8E372ULL, 0x6A9F7245A3E4377FULL, 0x21B2A2F85941A9A3ULL, 0x251EC409B87FD544ULL, 
            0x92C9316459B4D83CULL, 0x94DA82733DCEC9EEULL, 0xB6AA81E560782C70ULL, 0xF7E51F297C947CF9ULL, 
            0x4F4BEDA7EB523EDEULL, 0xB9CD527F7DAADDD6ULL, 0x00B96705803D58CEULL, 0xAEF80775BD424BF1ULL, 
            0x59B3E50E022A9D10ULL, 0xCDAF6D43EB6188AAULL, 0xD3F1A0A18E750F51ULL, 0x7583D6D27A8F3BB2ULL, 
            0x9C96F2149C945388ULL, 0x12F7928D38C2B226ULL, 0x747F7C3A381CAEC9ULL, 0x53B8A899E969BCDFULL, 
            0xDAEE0E008A1B14CCULL, 0xDFF1B9CEB63F1C6BULL, 0x9827FACBC78D14ABULL, 0x5A930B18FF8E8209ULL, 
            0x38F8AC2521CE33AFULL, 0x393212FFD3B24564ULL, 0xB8E374231F32AB8AULL, 0xC838AFCA76C15AD7ULL
        },
        {
            0x7958C561BAF5E7B8ULL, 0xBD294BCFDE37264CULL, 0x4694369A7AF62B80ULL, 0xDA828FD21CC6541EULL, 
            0x005423517F69A69BULL, 0x7B8FD4701D9EE69AULL, 0xA499AB0CF2C549C0ULL, 0x9D40F05A649F3D71ULL, 
            0x1CC39587255B2991ULL, 0x9D967AB6AB73270CULL, 0x844123A0392EEDF6ULL, 0x24392CE8F01C7093ULL, 
            0x8902DD1FBB083309ULL, 0xADF6837CFEE1955EULL, 0x08A469BC147D6AF4ULL, 0x8184B6626850C8B2ULL, 
            0xAFD15F1F3C1C86FEULL, 0xA569953A453CECCBULL, 0x561EBA423BD327B0ULL, 0x63403B9D4CAF8C59ULL, 
            0x32D0007107953A01ULL, 0xE9D65F53D702E305ULL, 0x4B93138F8848C979ULL, 0x5EA9AEC05D294AD6ULL, 
            0x6D2E67877DB9D990ULL, 0x834D48AB96BEC065ULL, 0x1C627ECEDF86A934ULL, 0x2092468F0D214204ULL, 
            0x788F72B1C6B30DCBULL, 0x4EA9187B4C5A8BC8ULL, 0x7DFE7588FEEAFE25ULL, 0x6D0F5CD6D1AEB78CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseCConstants = {
    0x953C1CEFEC6E79ADULL,
    0xD550E593F523CFB8ULL,
    0x9102197871C59A75ULL,
    0x953C1CEFEC6E79ADULL,
    0xD550E593F523CFB8ULL,
    0x9102197871C59A75ULL,
    0x138997A4093927FCULL,
    0x780D64210EA550DEULL,
    0x0D,
    0x1D,
    0x0B,
    0xBB,
    0xDB,
    0xB8,
    0x9A,
    0x21
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseDSalts = {
    {
        {
            0xB9F456EAF1AF538EULL, 0x8DA1488C4704C5E1ULL, 0x28CD3B77FAC91B87ULL, 0xB881FE4E338DD4BDULL, 
            0x971ABFF8B8277C05ULL, 0xCE697268B99EA1F9ULL, 0x0B67AED6E961CFAEULL, 0xA091FFC411E91F91ULL, 
            0x889C118C5CCB65CCULL, 0x45F0AC94199D6EBEULL, 0xA43024FD4C04D6DCULL, 0x0595924D5EBB55B6ULL, 
            0x6BBD047CE37C7B5AULL, 0x3EA3AB2C5884A4F1ULL, 0x5A7C96A040E40866ULL, 0x87A2279549F55B57ULL, 
            0x772EEE46CEC07C48ULL, 0x2380BDFF692C231FULL, 0x70064158C91A680FULL, 0xFADEB962FA8907ACULL, 
            0x1DC0504964AD46B9ULL, 0xE32D278E118C6293ULL, 0x7DD9933134485059ULL, 0xD6DB8CD6C030BB44ULL, 
            0x5730D014C78E303DULL, 0xB80C96AF3448DCF5ULL, 0x0EB6C1CE55F5F576ULL, 0x5795C09CD9AA2448ULL, 
            0x1CA91FEB395E6378ULL, 0x32299915B283105CULL, 0xD5124539A73E9F7AULL, 0xC00E01867EDACC4BULL
        },
        {
            0x89BD6DAF98C63EAEULL, 0x1E7155501A2ABE55ULL, 0x8076D24F7FCA0898ULL, 0x0E751C4CFD4085AEULL, 
            0x827CE68BF61298C7ULL, 0x7FF3819BA5EEC1D0ULL, 0x760CB02AB5F5271DULL, 0x7908A8B1744478A4ULL, 
            0x5D0BB4E3CE9B678FULL, 0x145C545458A411BCULL, 0x5DCF9FC0FCE16E34ULL, 0xF33C1274DAA007FDULL, 
            0xF1A7E95447C210EFULL, 0x15ED7CCEF9AA4AFAULL, 0x70146C30AF788024ULL, 0x4A5D39E40C740A38ULL, 
            0xC9388C17DC3895A8ULL, 0xFB2ECF865D0124E0ULL, 0x3D05A4A11453C61CULL, 0xD64497AEE4E92235ULL, 
            0xD2DB5C06EE65DC31ULL, 0x10263604F59D1332ULL, 0xBBDB0BB551F1DD9EULL, 0xCC61720BBE433FE6ULL, 
            0x65005FECEBDD5306ULL, 0xC2D53B6E8551372FULL, 0x468347C249C89953ULL, 0xFEA558B62A2EA811ULL, 
            0x3AFCE8E0B8376F5DULL, 0x27C5E4B9E5D505FEULL, 0x779D56A38CC91CFAULL, 0x0708CAE449BD61B1ULL
        },
        {
            0x5337FBC3E0CD95A3ULL, 0xE380E383AE5CF6EBULL, 0xE6044DC6EF3625D4ULL, 0x9111055891608A79ULL, 
            0x0E0281374C26404BULL, 0xC534D5A3A9466A8CULL, 0x7CDC00D3ADDBE568ULL, 0xFE25A7251ED4FDF9ULL, 
            0xB5ED3345173E21E1ULL, 0x1A01940DF9C5862FULL, 0x01C08F41F4E965B1ULL, 0xC3966F096CA97BF0ULL, 
            0x1A54B94605289AC0ULL, 0xA6C603F65E5E22F2ULL, 0x571AD9F20C748A06ULL, 0x39C81A32970F6A76ULL, 
            0x54D9FBDD9062B527ULL, 0x45B2B3130FB69BA8ULL, 0x1F82F1F39792A3B4ULL, 0xA4CF06FC449C0893ULL, 
            0x2B3F3B79D57AD60AULL, 0xD612D8E698BBC368ULL, 0xC8D1BE76FFE8766FULL, 0x4BEC4A8F7883744CULL, 
            0xDF2171350A3D32A2ULL, 0x22667872BD18886BULL, 0x17D8B46A5E88EF95ULL, 0xBBED025BE5FEDF6AULL, 
            0xB9CA0FB9FC23321CULL, 0x175E9C59210F34A6ULL, 0xF7E19F48E7413E51ULL, 0x9B133196A01B16C6ULL
        },
        {
            0x81ACDEB29A73432CULL, 0xAC75A3C8FAA9B570ULL, 0x5EA59594A7D64C41ULL, 0x24CA840C91A0BCF4ULL, 
            0x456D3DF786141574ULL, 0x9F54F23304387999ULL, 0xFACA0B3AD3A7C39FULL, 0x283CDA4C4E24A5E1ULL, 
            0x24E03177F783CE8EULL, 0x2D4AEF36CB5C3A60ULL, 0x212D3C4C6E09465AULL, 0xB984408E2AF861A9ULL, 
            0xAE3E55BFB1DAB434ULL, 0xF932B538F89C0CFFULL, 0x81ADD07A37BE9BA0ULL, 0xBA529BEDCB778885ULL, 
            0xDD58F78D3770F60CULL, 0x314A7F1CF296519BULL, 0xAF902095804344A0ULL, 0xA47D1EBCD67D5286ULL, 
            0xAC47230184D418F3ULL, 0x211C30EDA4F9A025ULL, 0x4A3DA876780D00F4ULL, 0xF4C3A05C99B28EF2ULL, 
            0x701F2D36D1C7108FULL, 0x2B2CF71E0A09C865ULL, 0x58533CEAAB7380AAULL, 0xAB6B71B974599C7EULL, 
            0x02A19F6A6BD6F7ACULL, 0x21D0437AC6FEABA8ULL, 0x988306AB866C694AULL, 0x045D8E3656CF356EULL
        },
        {
            0x4A025605CC148B19ULL, 0x75C4A1C060A87274ULL, 0x2B84532EC1D6BEA4ULL, 0xF1CD31AE8B7729ECULL, 
            0xA911DFB0FB105107ULL, 0x75358168B9713179ULL, 0x2E72466AFDDDA8DCULL, 0x84EB2702E41D8F6DULL, 
            0xCEF14297817668D2ULL, 0xBD107DAEE9458E03ULL, 0x5D2098FF68280CA1ULL, 0x3D36C451F2F0B244ULL, 
            0xC53195B85BE15B3EULL, 0xE113D075CF80B114ULL, 0x56027F5694EE7C39ULL, 0xD2DB3928EEC4B7CAULL, 
            0x0D722A90F26EC19EULL, 0x12BACC078C6F6D3CULL, 0xE8A5A8CF6E03FAE3ULL, 0xB1A2098C75B39344ULL, 
            0xEB1681CF625AB6D1ULL, 0x7A800E212D46928CULL, 0x5FD79D6926F26C80ULL, 0x96C707C489216C82ULL, 
            0x094CB94AC0282564ULL, 0x0C77E3BC133404EEULL, 0x989C1B6B54A4B56CULL, 0x9DE5107755BF361FULL, 
            0xC2E2E5D3B1DD513DULL, 0x65E9037B88730EB5ULL, 0x04C7B4B26BBF851DULL, 0x7312B605C71646C1ULL
        },
        {
            0x4ED4C30CA0AA6BA1ULL, 0x542A68783F297DD8ULL, 0x6F27A3A1834BCC1FULL, 0xE016A79EF14ABFA9ULL, 
            0xE741CC19D5C6DFFCULL, 0x4EF79AFC80C47D43ULL, 0xE690D48F68853395ULL, 0x8D5382EA772386B5ULL, 
            0x198B5E76376166CBULL, 0x2BF76D4C65F9266EULL, 0x760598552E33D7F4ULL, 0xA8CB7B582A266F74ULL, 
            0xA737583AB21CED11ULL, 0xDA5599C4220AECCBULL, 0xBF41D03F5600A6DDULL, 0x5973659EE3C55E8BULL, 
            0xC5251BED6EB8495FULL, 0xB26F79FB76D935B6ULL, 0x92B69BD9FB1D90D7ULL, 0x86D866BC3E22A6A4ULL, 
            0x95E34A6D23B5F6B5ULL, 0x3F777685B6340220ULL, 0x189F22A3BB7CA74BULL, 0x4F2CF45D57229D62ULL, 
            0xAE268BEEA7DB161DULL, 0x91B60DFA1424C3F7ULL, 0xCC13575C5300F7FAULL, 0xD8BA5D99FDB4FF5AULL, 
            0x428F903CE6A7BF84ULL, 0xDC16C2EF86A1FD63ULL, 0xA2CE535FDFCFA240ULL, 0x5B0B59A1BA02484AULL
        }
    },
    {
        {
            0x5FAAD9A7DF870457ULL, 0x9F16DA921E9BE043ULL, 0xD152CA137AEDF320ULL, 0x275E75CC0E979A96ULL, 
            0x0B0BAFEEDD58CD45ULL, 0x3A730574A88FD312ULL, 0xC27B4B6CC577D6FCULL, 0xAA54CEEFA82D6932ULL, 
            0xE0910FE4E1FDBC9EULL, 0x47B8EF8F00E3527CULL, 0x6A9A6BC33C6E4FB6ULL, 0x87BCC1C003681B9AULL, 
            0xB6C34FAE36CD9D08ULL, 0xCCEAF87FC520EE33ULL, 0x481BD32A7D253D2BULL, 0xE421103FA2B7D0B2ULL, 
            0xC14E0757A2DBE56EULL, 0x5F151DA2CB4E453BULL, 0xF499B25D6C41AE4EULL, 0xEB1A565F9E00E61BULL, 
            0x8B37D2B0EA64685AULL, 0xDB1F5FFCF058E48BULL, 0xB470B6BD61962121ULL, 0x0207F7D284E11123ULL, 
            0x3054484B40F65A92ULL, 0xF751CA9B520EE035ULL, 0xFCE0458FB9FE0FF5ULL, 0x9FA53D24C9430B0DULL, 
            0xE7AF337B82153F73ULL, 0x6F19C556027F57D5ULL, 0x538F122189767B52ULL, 0x8C7F570D71DD14A1ULL
        },
        {
            0xBD140287EE18C1F0ULL, 0xB4602DADEFAC68F1ULL, 0x4C68E4822151E48AULL, 0x8A17F8BB1A07D81DULL, 
            0xFC3C762E9940DC84ULL, 0x4FAFE0FDBD1B1B86ULL, 0x1A4D37B90F0562B9ULL, 0x8A8FA96E6F7FD366ULL, 
            0x15CAFFA6E443EC33ULL, 0x8A1DE38CF6710B5EULL, 0xFF0A0CE9ED78A9D1ULL, 0x3CA651197417C875ULL, 
            0x31D59F7B943FA584ULL, 0x5DE3D752451E1167ULL, 0x6C275FA703555131ULL, 0x368A59FE7657B239ULL, 
            0xE231EFC70F1C2789ULL, 0xF6E8FC27906F9F71ULL, 0x01503322C9517ADDULL, 0x2B577BF390D91C04ULL, 
            0x7D2CC93AEA089C31ULL, 0x5677B00F1901F048ULL, 0x9C47FDD033DD4C1AULL, 0xE36DFE7A4D9A7393ULL, 
            0x4439103996699C34ULL, 0x745EAD68594FE10BULL, 0x4F41428856DC3E20ULL, 0x5F14215A794FBD33ULL, 
            0x4A761273951FC1B8ULL, 0xC38A1D4BA7A1D463ULL, 0xE73F2666901EFEA5ULL, 0xCD153326A52F1EC4ULL
        },
        {
            0x904BDE3BF3D8E671ULL, 0x9B58585A4E9C8958ULL, 0x653D54E232EDBFB4ULL, 0x540A9CD995C3219DULL, 
            0xD96E681C3E7084DAULL, 0x6FD5DE453358D5ADULL, 0x1D105BD2B9036CD0ULL, 0xFB173EAC8AD202C1ULL, 
            0x06EE49C7F7CD7836ULL, 0x8D2664FDE85F2AE4ULL, 0xA930E7377E5C6939ULL, 0x7CC446CB96329BA2ULL, 
            0x42E862885AA808D9ULL, 0x82C212E5BD748BEEULL, 0xA5B66E02ECD2A444ULL, 0x653C57C8E93313C9ULL, 
            0xE17FDF68468C0683ULL, 0x3B6A62EB443D2C16ULL, 0xD16434F24BD1FAA7ULL, 0x8149903B54F38DD4ULL, 
            0x7440D63FE7A6C1AEULL, 0x3601B5116F6767ECULL, 0xC8B7D6AA463FBCFAULL, 0x30A50C6206A3FE95ULL, 
            0xCEBA7ABB9E0C22EBULL, 0x2F686E8DBCF654A0ULL, 0xD1412E6AA4774BCBULL, 0x21BA12DA80BFFF8BULL, 
            0x2BEF858FB1A8F757ULL, 0x51AF400962A74190ULL, 0x5DBB2C63AC134A1BULL, 0xFF5E078110BBBA08ULL
        },
        {
            0x8122754E388F8F88ULL, 0xCA446FAF3DFAA02CULL, 0x430CA3306346B27EULL, 0x67E00A7FFC3E464BULL, 
            0x0F8E196A3DC696CDULL, 0x6301A4704F1C5563ULL, 0x2070CB87A9D79D9BULL, 0x4C8EB25BB418267FULL, 
            0xEF596E97C359B1FBULL, 0x49CF6E8FD0D2F3A8ULL, 0x156EE52CC4DC5C68ULL, 0x89E9B151168DC5E4ULL, 
            0xBF148C76475B1AF4ULL, 0x978025BAFF917F43ULL, 0x9E6B912A1625F4FEULL, 0x2DB3E5C7404E63E6ULL, 
            0x77C4F829848C2839ULL, 0x71FD49CBF94B60D4ULL, 0x7654DF76FB5E0EBDULL, 0xB5E98C6BCF179669ULL, 
            0xDF54D02A17017128ULL, 0x91A72FE8235D2B6CULL, 0xE3A858F0E0A90E73ULL, 0xC3186B187128B4DCULL, 
            0xCEF5F09D52EA607FULL, 0x3CD271E84AEBE8C0ULL, 0x5F6FEF2FC01EE600ULL, 0xD866A682631DBF26ULL, 
            0x08F2D4E69CEB67E4ULL, 0x4BF97C848B494B68ULL, 0x3CE95242F09D77EBULL, 0x28D1C74477683187ULL
        },
        {
            0x58E41C4ABB4BA82CULL, 0xB81077C0291EC3F9ULL, 0x4154B2CC7378C4BFULL, 0xD541C63D5DD2289EULL, 
            0x6FAAEB87EA08455BULL, 0x60EFA5D5DCC9E45AULL, 0x4891934E0FE7B3B3ULL, 0xC28F07F2A3AAFDA5ULL, 
            0x755DF23DBC4F48B8ULL, 0x67A383538A26C742ULL, 0x83BF5D0F2A2E92AEULL, 0x314A69391701EE91ULL, 
            0xC986DE08F614AB86ULL, 0x151D99136D7B018CULL, 0x6E0BA24BCE840B60ULL, 0xA8C33E3982C78E18ULL, 
            0x2094D3C6D1B72556ULL, 0x3B074CD4283FA139ULL, 0x2EF42198D2F6EC89ULL, 0x2CE7710AF8155BB8ULL, 
            0xF90A1C5BD4B4AC8EULL, 0xC56E5DD532C47FD3ULL, 0x06D5DBA45CB160EEULL, 0x88976D44C231D4B4ULL, 
            0xA57C02FC5A9846F0ULL, 0xA466B27DB63E7923ULL, 0x0AEEE3C52DE521ACULL, 0xFE8A161AEC96695BULL, 
            0x1F440E08CD862346ULL, 0xA99C24C2F5BEAD96ULL, 0xC0D463CE22A95BAAULL, 0x7C1933FFC520B8A0ULL
        },
        {
            0xC5DA2F317C7A4B77ULL, 0xDABF8FF641D7B667ULL, 0xFBBCEA0A2A7CBBD5ULL, 0x086BF6B48B8A79D1ULL, 
            0x70411E16F3A17257ULL, 0x3CF2218972CF762DULL, 0xD8117F03344EE393ULL, 0xA8508C667EA859FDULL, 
            0x13BE20DC61531BAAULL, 0x066A242282DA725AULL, 0x48590EA5A6602C43ULL, 0xA7F36AAC0F09B586ULL, 
            0x063498F48E2FAE4AULL, 0x78C033B7EB72434BULL, 0x48BF204D6D602E6EULL, 0x722776E2296C1D3DULL, 
            0x2EBCDC79D3717A09ULL, 0x63181406624D5EB5ULL, 0x29D6B04F3F80765BULL, 0xA84199C954FD82C5ULL, 
            0xA3E34416A66135DAULL, 0xD5EEEAB17B6CD9DCULL, 0x102BA465C075FD66ULL, 0xE0D9583B17CC0CFAULL, 
            0xF740A9344A37FC54ULL, 0x10F82421FCCC0A2DULL, 0xFC1D1F0FC8536581ULL, 0x5DF76B26D8ED1508ULL, 
            0x4C16AE471A3C20F9ULL, 0xC2A28F54CD079C59ULL, 0x50333B7F48FFE624ULL, 0x1367B220C046674BULL
        }
    },
    {
        {
            0xC15AF21B69FCF028ULL, 0x32A4520955BAE10DULL, 0x46C612C44F098190ULL, 0xE6613DEF45897076ULL, 
            0xA20A12B908785F56ULL, 0x946519D6924132AEULL, 0xE804FC1B003179A7ULL, 0x80EAB114932A1031ULL, 
            0xA3747B0306969415ULL, 0x9D72504772EDC998ULL, 0x0EF62B4665C5EFE8ULL, 0x59D4AE04BFC92FDFULL, 
            0xCE92ED6B407019C6ULL, 0x2340933E95C83E81ULL, 0xC61A2953903357D0ULL, 0xEE84794E90874488ULL, 
            0x91C413261654BDAFULL, 0x5356CBCE7B65203CULL, 0x17D0DA6F84DF97D5ULL, 0x65DC7AD8B4A07C97ULL, 
            0xB7BD3BEF6235C604ULL, 0x8BE90FC029C66605ULL, 0xA6608F3264FE4C9FULL, 0x00D73F9240F1048DULL, 
            0x4CA6AB1FF2D2B49CULL, 0x2A24FE635A2425FAULL, 0x26926B7DAE0A8D24ULL, 0x35AF6A5513200547ULL, 
            0xCD89C2303FD33D07ULL, 0xDB7FDFFE26D10302ULL, 0x8B4F85E00E7220B9ULL, 0x4B7E6ABCB6675517ULL
        },
        {
            0xDE3FC655ADF40D59ULL, 0xC59B1620D7FCED7FULL, 0xB9574807C2189467ULL, 0xDD430F31E7E67F43ULL, 
            0xF1A08358E2AD18B3ULL, 0xF7DAFF8F658B0EC3ULL, 0xC69AFE681282737AULL, 0xE28C82A4B0300226ULL, 
            0xBFBA1AB0FCF4E8AEULL, 0x8212F12BFA4E5676ULL, 0x4AA9D8BBE9E0CA12ULL, 0x421AD21A651B278CULL, 
            0x619B80F060BC65B4ULL, 0x66A55EA2B97644B1ULL, 0xA5DE24BDAFB0AEBDULL, 0x4BF28DA4C660001FULL, 
            0xD283E7532EB54F1EULL, 0x7C75BC25BA6EF67BULL, 0x10F7811605C6DEE2ULL, 0x951ABDF8259F797AULL, 
            0xB290C315DB112709ULL, 0x205374B057683D57ULL, 0xAA79BEF8A7C3164FULL, 0xE2C0F22A104BBF87ULL, 
            0xCDA77ED40AEF624EULL, 0x9509937A0211A755ULL, 0xA5A55D946ED244B0ULL, 0x6819A5B8B9DC6C4BULL, 
            0x775C4EA286CDC0DCULL, 0xB99CAEE1CD91C979ULL, 0x76710FD5AB8627A7ULL, 0x8BDDEDB561B2B6B8ULL
        },
        {
            0xDD65735248E67539ULL, 0xF7369C7DCA70D003ULL, 0x3B73EBAE1AB8CC27ULL, 0xA0D3F7A5FBEEBBAAULL, 
            0x070C029582F6C1E7ULL, 0x26EE571F9C942283ULL, 0xBF34446115AA83D1ULL, 0x1DFB3F57BD6CA584ULL, 
            0x728E1310CCA16E1AULL, 0xB05C69CF475CD96EULL, 0x95F4046C363FC3FEULL, 0xA5CBB3310F92A64EULL, 
            0x5091218E1CD11AFCULL, 0x15E74D06C3E8BE38ULL, 0xB8A586AAA5D21B87ULL, 0xBF2C3D08844252F6ULL, 
            0xE721E6AE55F5B89CULL, 0xDED85190417FFD6BULL, 0x8CF405645B6150E0ULL, 0xE2EDE5876C3E0132ULL, 
            0xFA5B0F8988122C42ULL, 0x1599922CEE6A25C6ULL, 0xFCDD944AB4A7A686ULL, 0x176C056E8425556FULL, 
            0x337F9D4E7A90FE14ULL, 0x07886BA916099C37ULL, 0x174B4F55D95CEAEDULL, 0xA5E739D6AA14B455ULL, 
            0xD7C413414C86623BULL, 0x0D2EC5311E74E265ULL, 0x6DA20081D99B547FULL, 0x29F84F48E7BF8097ULL
        },
        {
            0xD4C64A3F29655B4EULL, 0xF9FBA428C3EF30F9ULL, 0xD6655760D0F94D20ULL, 0xD328566EB7860A62ULL, 
            0xDF9493EF0514B68CULL, 0xEF3ECBE980BDF31EULL, 0xBB33A6BE485635B2ULL, 0x464AB4B197AE5EF9ULL, 
            0x4DD3DBFCA6FBE052ULL, 0x85B8560C6E3DF7E9ULL, 0x5B64FD0E3FCE71ACULL, 0xAC3FD3998BB4A888ULL, 
            0x119268A75782552CULL, 0x47626EAA540C5006ULL, 0x3B9965F4F81C2E91ULL, 0xFFFC092C6BBD6DBFULL, 
            0x60F957B114B8BB26ULL, 0xB40E0C8D91FFE7ABULL, 0x599BB88D80EB7D07ULL, 0x0E03EA6CC75073FAULL, 
            0xF79EA276C609950FULL, 0x61E2034EA53CA66DULL, 0x3244BAA8708788B4ULL, 0x35B9B8998AC8F57FULL, 
            0xB653525F4EE282ACULL, 0xA837A9EC81D83878ULL, 0xF4C03C3288582EDBULL, 0x87F94B914E599DC1ULL, 
            0x99582DCF2B5A8C11ULL, 0xDFAA8CEB8570EE95ULL, 0x4B013B8B98E73DD2ULL, 0x244B85FDEFD24393ULL
        },
        {
            0x38249188F8A9506EULL, 0xE7D8940638813A17ULL, 0x4CB08687C6B4BE33ULL, 0xA55A7C23FFC37EEDULL, 
            0x4CF5B4D6AFE4FE72ULL, 0xDAAC350BC5B3B8B7ULL, 0x2C8652A7EEB8F83EULL, 0xF6338B78D7327E30ULL, 
            0xAA5F495905D4CC1BULL, 0xA4D8DB50E6C4A3AEULL, 0x687DED9B439F17FDULL, 0xAF9E82AE8B3EFC3BULL, 
            0xD8B2C0DCD137FC89ULL, 0xE222B6D6BFF23AA1ULL, 0x0D2FFF8EDF67134DULL, 0x5F2EE041CE3C4691ULL, 
            0x2D7B2633E148D12EULL, 0x39A8E1AA261AB64CULL, 0xD25AECF07B2847E4ULL, 0x7F214E38B476EA8AULL, 
            0xC6A329E1D112645EULL, 0xE8A758776F9D4C69ULL, 0x8E5949787D3D35D8ULL, 0x5F34AAB1FA37AEF0ULL, 
            0x84CB5F3F1B33BD7AULL, 0x08B3C1ECC03FC416ULL, 0x73316DB63A069639ULL, 0x47BB8AC7275EE0ECULL, 
            0x0034D19F7157EB93ULL, 0x9A8FAF8E5B5F0932ULL, 0x07CB497FE4B47A8AULL, 0x8AEB77B4BFC9CFFCULL
        },
        {
            0x5ECD832A13568420ULL, 0x04633C260B1904D0ULL, 0x17B4D734468C6AD4ULL, 0x10A94B1256F91A83ULL, 
            0xCD9386D8C30C1F0DULL, 0x0F7E8A25B59446BCULL, 0x5CF4DB4A7F94F445ULL, 0x094E3DB4EAED030CULL, 
            0x1EB9EA72281828D8ULL, 0x7004067FDF5EE085ULL, 0x389354D0F35F9AE6ULL, 0xDFE9A48A9BC1263DULL, 
            0xD7B06896E96F15AFULL, 0x4BD52F952B62D54FULL, 0x5FFAECD82ECCA2A5ULL, 0x37D8E6C08DE7EFA2ULL, 
            0x221EC098D2688996ULL, 0x8523B5B4AD7CF3C0ULL, 0xC4CF4A288B2F1E35ULL, 0x3936731377BBD492ULL, 
            0x07FB5B59F8713F0FULL, 0xEE998328BEBD5D2FULL, 0x25329A7A1E8523FCULL, 0xDFB534347FC15D0BULL, 
            0x0BA426145D781B48ULL, 0xDA911BA559A8264EULL, 0x8362222C8213C5DFULL, 0x791D1E8560DE86EAULL, 
            0x7A3E76112E0E2403ULL, 0x1CC9E9123A3E798EULL, 0xF92A7E0EDCA0F1DEULL, 0xC0CF0C280D8F3B5BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseDConstants = {
    0x93CA41ACBC438CF8ULL,
    0xB1E9036559256500ULL,
    0xAE2708B63D9D030CULL,
    0x93CA41ACBC438CF8ULL,
    0xB1E9036559256500ULL,
    0xAE2708B63D9D030CULL,
    0x2D44902650EC2A45ULL,
    0x7732EB5FF4930A76ULL,
    0xAA,
    0xD1,
    0x2D,
    0x6A,
    0x1E,
    0xF3,
    0xFA,
    0x4D
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseESalts = {
    {
        {
            0xD4540FE406A03489ULL, 0xE1EB70BE264B3EA3ULL, 0x9FAB34A7D8A5D893ULL, 0x97AC0ABA14A88A13ULL, 
            0x36A3202FFCDF2AF1ULL, 0x4AC72BA4F6F6A41EULL, 0xBD1F66CAE734B41AULL, 0x23E8F1CA08D36472ULL, 
            0x625B9DC61FA16B0EULL, 0x4185D4D7AA591A44ULL, 0x6EAB09DE0039D52BULL, 0xEF4C1AF313B12272ULL, 
            0x7FF7CB24CB89FD10ULL, 0x435B5BE1C9DEDDDCULL, 0xCBAE8DA36E15E10EULL, 0x5427C4D8A6D1D1CFULL, 
            0x6373EB1C0AF60B8DULL, 0xEEE510DEECCDA41BULL, 0xF8617B4ED4AF8CB2ULL, 0xC3095B607E2ABE03ULL, 
            0xC659E4D63C843C93ULL, 0xE7659C15C5C69041ULL, 0xF7F9512779D0E5F1ULL, 0xE6D5BBE773DEC24AULL, 
            0xA44166BB3FEC0050ULL, 0x00D09173A5B23937ULL, 0xEC2608E7A1615D4BULL, 0x6888CE72FAA09786ULL, 
            0x2BC69C0BDAF52CC0ULL, 0xEF1E52193EE018E3ULL, 0x45EC967DEB79E0D8ULL, 0x7D21F2C8521DC037ULL
        },
        {
            0xC5DBE254C9EC9FB5ULL, 0x2C0ACE400555D307ULL, 0xE9B21A658C42236BULL, 0x1E97423AA24C0FA6ULL, 
            0x44E20574497AE5E4ULL, 0xACC177DB1BCAF823ULL, 0x95DA2AF0754E5168ULL, 0x24D93552FA26E2E1ULL, 
            0x8DB0751CB96021D2ULL, 0x5338BF2A6C1E412BULL, 0xB5EC11B5E85F3699ULL, 0x59FA54769CA55135ULL, 
            0xC5FC9EA30765A745ULL, 0x36FD21238AE2103FULL, 0x1289C4CDD39F8AC8ULL, 0x2AA5FC04467EEA92ULL, 
            0xCA5688C743BE57B0ULL, 0xA3D4E35670C30B95ULL, 0x1C59E147EB8E9DD8ULL, 0xA0D703FCE28A5984ULL, 
            0xE1096D0A6FC1EDC7ULL, 0x85A32F3638DEB685ULL, 0xC287CF5A69253EB0ULL, 0x1E9E918D82C0A501ULL, 
            0xC76FDDEBC4FDF7C6ULL, 0xC260209C0822C622ULL, 0xE62A167C8D6C5742ULL, 0x574A7D732183E9A0ULL, 
            0x9CEE1C85E2E471D9ULL, 0xF53BA41E50A96E9EULL, 0x30C4530313834141ULL, 0xCF3C975DBB766278ULL
        },
        {
            0x1F7D567BEB36EB8AULL, 0x5E2863A7E8CF48ACULL, 0xADA49E852C57DBC2ULL, 0xDCAC5EFFB72CFA2EULL, 
            0x0A19C73A7AEEAD3AULL, 0xF6CC61E115DC968CULL, 0xFFF8F5329A49ACD7ULL, 0x7D323FA0EB51471CULL, 
            0xC527FAC5B48169C4ULL, 0xC74C1A5E9610AD91ULL, 0x3227C7F4C6CD89AFULL, 0xA53E2DAAFBEF465BULL, 
            0x507111C6CA41929AULL, 0xA697B89F0756D6F7ULL, 0x8CD1C509A84FB0C3ULL, 0x34C8BC7ADF7BAB3DULL, 
            0x3616A9047B40F50DULL, 0x8760B0E83A9F1B9FULL, 0x2237FE0468946385ULL, 0xDA19FDC5FE7D4533ULL, 
            0x8DEE15BD0A63712BULL, 0x859722CD6B0CF4D7ULL, 0x79AA95D5F17EB6D2ULL, 0x2A502B7C9CCB6F51ULL, 
            0x2E51F16EA4207D37ULL, 0xD85092C7E78E2876ULL, 0x4DE758F34EA6112AULL, 0x7AC4121D8A3837C2ULL, 
            0x71C2200255003783ULL, 0x4272FB8903F78530ULL, 0xD7D8B3F83E6A05A1ULL, 0xA58211B73562A6E3ULL
        },
        {
            0xB26489072BC0B23AULL, 0xB75D6410DF3BA323ULL, 0x444278E5BB639996ULL, 0x9C4921375AD6A275ULL, 
            0x4C6DBFA019A4DAC9ULL, 0x9173E36CDD126BBEULL, 0xF9B3D682C4C5C31BULL, 0x31CE9084C84CA7B6ULL, 
            0x5313E6063C564F14ULL, 0xB31831353ABE6667ULL, 0xBB0B31082BE615D6ULL, 0x36A9FF65501F38D3ULL, 
            0xC3543D046615836FULL, 0x3880D0C4D8041870ULL, 0xEC54A7634A9AA849ULL, 0x8CCA22FAF70E3605ULL, 
            0xA55850E9E7042C68ULL, 0x51CC728D58CAC948ULL, 0x503F722779B53FD6ULL, 0x3A8F2EB0168B0A6EULL, 
            0xC13CEF8AF3507C80ULL, 0x7F737A3EFDF78BD4ULL, 0xAD291AA787BDF368ULL, 0xA4E171D8A61B52DBULL, 
            0x15A738FA7796A11FULL, 0x788F43A1C8049B2BULL, 0xF7828ECA03FA8987ULL, 0xD0AA0F11758442C3ULL, 
            0x4E98873A2FED078AULL, 0xE2CC7573A3F6DEBFULL, 0xA3B1A8902FABDB35ULL, 0x0DFE2BCE6663D4B9ULL
        },
        {
            0xE39B32916DACB661ULL, 0xC7ADE01EC8231CD9ULL, 0xD5C5BF2BA426FD6EULL, 0x91B9768DC66601F6ULL, 
            0xD2B447B0E66F5362ULL, 0x62B82059E014804FULL, 0x2EC4243156FA8CEAULL, 0xFF2A3F22427CBB10ULL, 
            0xCFFE7E29D1168726ULL, 0xA8D8589E900620F4ULL, 0x065AFC51BBB028F2ULL, 0x18B265CD5EB44E7BULL, 
            0xA58B41A50B9FA3DBULL, 0x686221AF6EC2E4BAULL, 0x38429FE33A683F87ULL, 0x5AC28D3FB2633242ULL, 
            0x3F5435973621781DULL, 0xCB11D545A354E6BFULL, 0x0BEFC900EED737B7ULL, 0x2189E840B4053AEFULL, 
            0x008EEAAEB36E9689ULL, 0xBA4AB8A63106235FULL, 0xE6F804039FA2EEBEULL, 0xC0802D4399D30CD5ULL, 
            0xBBF172DDABA8A76BULL, 0xC45233D6ECDD9149ULL, 0x25E11EC3F21E370AULL, 0x117D07B6C1FFA0DDULL, 
            0x707078EE7F80B85EULL, 0x186A21A8644F56D5ULL, 0x23F472B0623FB383ULL, 0xE02E2F5F152EBE0AULL
        },
        {
            0x3AE805199BAFCCE7ULL, 0x255EA8A3454BFEFCULL, 0x73E66A00322D07AEULL, 0x0BF31D41DD7DFD59ULL, 
            0xFE8ECB0C8AF1EDADULL, 0x658C9D3F271181F5ULL, 0x367068269B9FEDFEULL, 0x704ADEF3A1A54C55ULL, 
            0x53397A243F7299F7ULL, 0x0E6EE8A3402CA15BULL, 0x0F2632034D252180ULL, 0xE9DC885845FA11C8ULL, 
            0x57E2EA87AF99494BULL, 0x741C0F98A749C793ULL, 0x91A53EDDC868A8CAULL, 0x7C7A3F72F0E4FE04ULL, 
            0x2FE8057C6E55065CULL, 0x524612651FB5F97BULL, 0x7EBFFB8ADB3AC5C3ULL, 0xEA97F85577E802EFULL, 
            0xD9316D5F4C8A7B8DULL, 0x0C71EFD024E5CBE9ULL, 0x38933AE141084D12ULL, 0x17CF59D28FCB9867ULL, 
            0x4EEBD42E1EC50FFDULL, 0x297DA0735AAB9B53ULL, 0x9CDB500BC990E521ULL, 0x88C4EFADDB7D1396ULL, 
            0xE3F4BBC72BF37463ULL, 0x0B76DC43900583AEULL, 0x87B01AF403DDF585ULL, 0x7ACE5D24675503B1ULL
        }
    },
    {
        {
            0x717024B18D8C5406ULL, 0xC54121FB22066751ULL, 0xC8769501F50FE3A5ULL, 0x7008CD0BAC9B7F8AULL, 
            0xB09B59CC8B4E96C7ULL, 0x07730BBB55A68056ULL, 0xD44CB1807414C209ULL, 0x311FF6C918561EF9ULL, 
            0x73C8052EFF62314FULL, 0x68C750A3AC0785C7ULL, 0x5A0459FF4B3E1C34ULL, 0x52D0CC30B5C95010ULL, 
            0x357868BF86C9F435ULL, 0x04522BCD8F51FD0DULL, 0xB6E0F68ACE92E9B5ULL, 0x310E010FFCF17722ULL, 
            0x477E1D2ABBC9C065ULL, 0xBEF9321E4C469C97ULL, 0xC5FD96B1CD33A190ULL, 0x195B9CAE38C56CA5ULL, 
            0xD96183646C34B8E8ULL, 0xA23CA9B6A104C563ULL, 0x31C1157515ED6812ULL, 0x2DBF16E95F3A5EE6ULL, 
            0xBC52F85FC16A8543ULL, 0xB14B4DE77DA0C5DBULL, 0x5AC065DA42FDC49DULL, 0x0114F40DDC407C26ULL, 
            0x27F16D7AEF7DC1FAULL, 0x2A81166F4CA5623AULL, 0xE1E8327925734D2BULL, 0xD31294973133329DULL
        },
        {
            0xF2B1E1CC7A8B4A20ULL, 0x13C4531F353D4EC9ULL, 0x16F4AD8BDC5FA41EULL, 0x6FF713738A90AD72ULL, 
            0xE094E9C52BF8B1C2ULL, 0x389D85C6BE2F40D7ULL, 0xE43B3E4B62DC61A3ULL, 0x303D6BDCD04F3CFAULL, 
            0x153C0886755BBAA0ULL, 0xE3EF8E025D6D1F77ULL, 0xAE492ED5476603B7ULL, 0x00EABC8633D099D6ULL, 
            0xB07A7CF083C0DDC4ULL, 0xB48C1E79BE10AA42ULL, 0x288A4FD09A6E8BE5ULL, 0x6999B7BDD86DDE0DULL, 
            0xFFC644CA16C973D8ULL, 0x9C7FE87B43F5F87CULL, 0x644A4FBC3BE539C0ULL, 0x71414467157DC3D2ULL, 
            0xEBCFED16AECE3941ULL, 0x498DA209DCAC4DEEULL, 0x11324CD1DA0B6F4EULL, 0x9B6DDFDEB06834F2ULL, 
            0xD86322F736A512DFULL, 0xF59AAA1029ADE704ULL, 0xF2B87184B40BA289ULL, 0x6FF26A120E8BF990ULL, 
            0xC2A18B7A9E39015AULL, 0x0BBBAB4FC02C9DA7ULL, 0x65E714E176989EA7ULL, 0x772D5CE066070B94ULL
        },
        {
            0x6E06032BA4D23783ULL, 0x23BF58A77A0A216EULL, 0xF9C526E26E57D49EULL, 0x1A2102DF0059A05CULL, 
            0x2294335560305F26ULL, 0x199C75E2270A7B4BULL, 0xF43C77C1CA93B2BEULL, 0xFA431AD2B9362B2BULL, 
            0x8128C94DD62B60A5ULL, 0x768E333677F73058ULL, 0x29C16286E9D63A16ULL, 0xF01C56A1786D071BULL, 
            0x55DD7551267F5AE0ULL, 0x0E2FF7DB2B4B5339ULL, 0xA939B9C5A7FCCA37ULL, 0xEFA8A36FD0DF3706ULL, 
            0xC15F3BDFC852B389ULL, 0x51853FBD6EAE7D71ULL, 0x45C1F5B18F15CE8DULL, 0xB2A089BB32C843F6ULL, 
            0x1EC0755F9F850BBFULL, 0x0269004B6E109447ULL, 0x750CFBA52F8AD80CULL, 0xEA51E13CC7AC978EULL, 
            0xC2CF52FFA0B1868AULL, 0xDEAA6F8E9B7FCBC8ULL, 0x9A3F32DAB0F16CBFULL, 0x8FAC71B0A2E66F69ULL, 
            0x409848751C05C105ULL, 0x753E9257245EB456ULL, 0xA56793F01348638CULL, 0x3BDBA9FF9289165DULL
        },
        {
            0xA3C30510104B9838ULL, 0x019189D2386585F7ULL, 0xB456C1048E70A6E6ULL, 0x6993E4B6B935179CULL, 
            0x62140C16144B770CULL, 0xC55829C60FA749B7ULL, 0x0125C4BC78B19691ULL, 0x9B923E1F250F77DBULL, 
            0x1E2C9FA8C2A647ACULL, 0x5409A8EAAE941571ULL, 0xBFA7878A4823DE53ULL, 0xE163F998B615A51CULL, 
            0x1C044719AA1E3DABULL, 0xB75CF29D861D78CCULL, 0xF8C0445E97615687ULL, 0x83CCF211E52F654DULL, 
            0xF126D5318828F188ULL, 0xF913EEF814FA4A53ULL, 0x97839E1212C23F58ULL, 0xDFAF4D1D6FA63F8BULL, 
            0x93D06DC17E39425DULL, 0x9327BDD1E0456441ULL, 0xF5FDD6625DC0D449ULL, 0xB941C5554C985E6CULL, 
            0x4C6F77E2644A2862ULL, 0x3015B5A94902B1BCULL, 0x731318F43CEDC527ULL, 0x9D6613F0A80BCE12ULL, 
            0x7049C80A5129A85CULL, 0x3EA432CF26F5EA1BULL, 0x3CE2ABE52D618CEEULL, 0xC83205762F225909ULL
        },
        {
            0x2D2FA5483E043071ULL, 0x0CFE26864309C1E7ULL, 0x10F8073AE4CB7DE8ULL, 0x84EB180AAA5BB8E3ULL, 
            0x51FD0CC3000F15C5ULL, 0x00E14B1F07A7709BULL, 0x4B8E9651D80F23CCULL, 0x529F634709A773AFULL, 
            0xC0ABD090B5ECFA26ULL, 0xFDBAB6673B178047ULL, 0x7FD29AFACDD57138ULL, 0xB430B60B30556119ULL, 
            0x214E58F5F094C1FAULL, 0xB780A4E651F14AA8ULL, 0xB776E1F76C9936B9ULL, 0xFE3FB31749DBEAA5ULL, 
            0x10595E5FEE75C1FFULL, 0x2D01B15416FA1423ULL, 0x606D638286FCA444ULL, 0xA67F7DDDC3D331D4ULL, 
            0xBBEA950CD1AE9989ULL, 0x6491352B04D3230BULL, 0x93C33AD28E56DCF7ULL, 0xDEF3D1778948C1D7ULL, 
            0x5DDD5BDCE24080FEULL, 0xF4BB51417554907DULL, 0xBCA7F8A6EB9AA23EULL, 0x6E21F667F192D05FULL, 
            0xB922CFA762460841ULL, 0x1BB587E741FE32F8ULL, 0x194A3181128C3F37ULL, 0x0F844B0A7C0DFD88ULL
        },
        {
            0xA31E31C78596B9A7ULL, 0x5F1730F31B27D3B6ULL, 0x48C23E851B27830FULL, 0x2EEDB0D4E9180A8BULL, 
            0xC89412DFE8F05A7BULL, 0x86A5B15CEB3D0E1AULL, 0x7E64A6B4EBBB8DDEULL, 0xA9558EFA53913B19ULL, 
            0xB1B2804DDC398844ULL, 0x2E9C504A8D1A4C41ULL, 0x0FAACC5F80057EC5ULL, 0x5EA16A6118A50C93ULL, 
            0x302A9EF4E0AF7D2BULL, 0x4595EC66B2BC4357ULL, 0x586D05E3C744E6ABULL, 0xC2378D5657C05421ULL, 
            0x07E10BD6A4ECF2E0ULL, 0xBF098DB0BCB9614BULL, 0xB7A0DF7F4103F476ULL, 0xA03357A9C3B0BB7CULL, 
            0x4FD2EBA7DF7DB6D4ULL, 0xCF32ECF8280F66D9ULL, 0x8B254C4F356526E4ULL, 0x79512DBC2BF82635ULL, 
            0x37DAD6871147F466ULL, 0x20F00B18A793B98DULL, 0x3EE4B556A1584EB0ULL, 0x73F4D1C03F50FD7FULL, 
            0x18162708D728F86EULL, 0x96BABFB71C358A98ULL, 0x9A80F20D9A2998CEULL, 0x2F1CDB9E15CA6B84ULL
        }
    },
    {
        {
            0x2F81D99AC00F0D1DULL, 0xA8C351D4DDB26987ULL, 0x06E8406C2AC5C2EBULL, 0x61E4DBEBA6A97111ULL, 
            0x68780EB87AD2DA48ULL, 0xF33C8A08694865C1ULL, 0xE64BF5CBFE2457A0ULL, 0xD7B3582C419D4ECEULL, 
            0x8D23E976B0A37496ULL, 0x4CC8B8254AB3AC6AULL, 0x31E8DF713546570AULL, 0x812961BBFB1691CEULL, 
            0xC1B91DE47C14B531ULL, 0xB9A29A1B3223F685ULL, 0x68AAE51CC56320E8ULL, 0x8EA27DBD29DB40FCULL, 
            0x04D28B1A533E810AULL, 0x3C300B26596D66B1ULL, 0x07CC59F9A570DD04ULL, 0xF84BC26748F5405CULL, 
            0x16D928BFD46BD9DDULL, 0x1BDB6645A43A435AULL, 0x7E62AC6CA414D4D2ULL, 0x09CB9A037B2AA5F5ULL, 
            0x7025C2918D95FBA9ULL, 0x84053DD72389E057ULL, 0x3D375D4724826DA4ULL, 0xDB8571F4B89943A8ULL, 
            0x8314963B5366F1E4ULL, 0x122AA4908F7A2DFDULL, 0xBF084EED492104CDULL, 0xCE3EE097EFF6DBECULL
        },
        {
            0x497BA39D0E48F856ULL, 0x0222BBED76957B33ULL, 0x0A00A07CF7168AB4ULL, 0x1252FC5AB8060661ULL, 
            0x44AC517E2C11E857ULL, 0x66DDC4F48E0B17E6ULL, 0xCC45F67C866EF1A0ULL, 0x5EBA956BD26B9800ULL, 
            0xA15CEFC3019510B4ULL, 0x2A71269A3927C68AULL, 0x5E027EF80D8794F9ULL, 0x387B0F4A9A3684B0ULL, 
            0x1CA5221DADFA75F8ULL, 0x64E8663575AE3B2AULL, 0xECFEF4A0E4B7115CULL, 0x60EBF0F526276221ULL, 
            0x5D54055E2C744A17ULL, 0x680612A380E43DB7ULL, 0x645569756CB8A4D1ULL, 0xE7AC959B079E8D5EULL, 
            0x8DA04DC199B0EB43ULL, 0x3B92C9541B9E8AAAULL, 0x39019C0465C05D46ULL, 0xDE97E93889AA75E7ULL, 
            0x533CCF8A4ACFA4DCULL, 0x32A795CCD0A12DBCULL, 0x34C018CF820B7EAAULL, 0x5D6A91115051B0E6ULL, 
            0xAAD99B0D7C2BA856ULL, 0x198C4E75139D1E9DULL, 0xDA258AB0F0E1BE70ULL, 0x5C7ECCAE26115FD6ULL
        },
        {
            0x18CB643FEF6AE67CULL, 0xF6CD28E8F588447EULL, 0x8A181C5642976A96ULL, 0x6AE759191952874AULL, 
            0x514971822CA6CAA8ULL, 0x176F1ADE6BC250D5ULL, 0xB10D808BA710AE91ULL, 0x6CCB6847CB8E85DEULL, 
            0x8BE6AA2EFDEBDF37ULL, 0xEB2E8B446E7E0186ULL, 0x1EED98B144CF9EC6ULL, 0x750C0BF9A76B1F73ULL, 
            0xA291A5542B1DCDBAULL, 0x2799861E6F3069E4ULL, 0x1ACB1AA438128291ULL, 0xF8E97D927758369DULL, 
            0x5D4B9517F5E0B105ULL, 0x66D9A3475651B350ULL, 0x02918C28D233A0D9ULL, 0x2E23C90FA1ED077CULL, 
            0x5E5DC234A6E5F90CULL, 0x05485AC80892FF07ULL, 0x5A90F85B507A6781ULL, 0xB47AB8C424DAA7BFULL, 
            0xC0EEC0D574825A5FULL, 0xD8433DA3D7360DABULL, 0x31A8F480F9F7AAC7ULL, 0x29E9253354639906ULL, 
            0x3C37E17865434094ULL, 0x67D82A06080F175EULL, 0x6646404E7F958047ULL, 0x6EDBA23A88D386EDULL
        },
        {
            0x3A7C46E07CFA4240ULL, 0xCE6F96859936F4D8ULL, 0xB4140E4E2798E5B8ULL, 0x6CF7ECB2E64A790BULL, 
            0x622D0032FAD40854ULL, 0xF57EB2EA8FC471D7ULL, 0x6597B8D3942604E0ULL, 0x82FAD62266E23CC4ULL, 
            0xA9F67E83CCE61E78ULL, 0x08F537C37ED2E490ULL, 0xD4906025F478BE3BULL, 0x694C624F1D2DE410ULL, 
            0x10E57E6307F5629CULL, 0x895DC7BCBAD2A54AULL, 0x253ADF4C2E416848ULL, 0xC1E7C5216F412CD3ULL, 
            0xE5C3A1B3FC535332ULL, 0xC74BF5F3969EB50EULL, 0x54A3B9ED6044532BULL, 0xF30AEB91A815A037ULL, 
            0x99B7CC21B87D6AA0ULL, 0xF93F04648F5BDA6DULL, 0x326CBDE9BAA07609ULL, 0xB8AC21B8BBDF61B5ULL, 
            0x0B9F24064BDA5238ULL, 0xFD781AD0327D07D0ULL, 0xC339995F85324576ULL, 0x0077D76FA777D82EULL, 
            0x48CA8DD5E08FD70AULL, 0xA8927D822899149DULL, 0xB693F105CEDD098AULL, 0xF6BAC0BACAD75389ULL
        },
        {
            0xDAF6AF291107C4C7ULL, 0xF3DDEB4670B3C156ULL, 0xA53E042282D096BCULL, 0x27557B71C83C70DFULL, 
            0x3E7DE9A7766ACEE7ULL, 0x2724261AA7A27805ULL, 0xDAC45779507BAF52ULL, 0x0F85280567782EC5ULL, 
            0x58405A6A0CD23C9DULL, 0xF927ACCDABBD9B2EULL, 0xE7E1787D14DAA645ULL, 0x7B062F32C9CB95C0ULL, 
            0x08C504865C62FF4CULL, 0x79705E36421A9F53ULL, 0xE3E09AC0D629E597ULL, 0xC353D1E8C1E9482AULL, 
            0x7DB0858208B7ED8CULL, 0xE75B927068C1D2DCULL, 0x0BC8CCBF988C9836ULL, 0x3275E6ED6D5ED24BULL, 
            0x382C4C4D9845B723ULL, 0x8FC82767452D3029ULL, 0xAA9B28C93352399BULL, 0x8CBBF84BD3334272ULL, 
            0x2644077957D2B946ULL, 0x845436F9C4857CFBULL, 0x2F60B61884BB0610ULL, 0x35E29B5BA5EE68BBULL, 
            0xFDC4FE535CE193DDULL, 0xBB67E3F095A31B8BULL, 0x7F64FF09304A9D5BULL, 0x4B327099F3F0EFAEULL
        },
        {
            0x2A9C4DD4AD499DDCULL, 0x455CDF18F65A13C4ULL, 0xCE9F67281D53FA6AULL, 0x5B74A38CB0045492ULL, 
            0x39CEC55B5FFE3A13ULL, 0xA8E5B37129B26E21ULL, 0x5E165ADF66985AD6ULL, 0x5AA891CB6C86C72EULL, 
            0xD1CE10CAEA3351BFULL, 0x8525F5F45E24A7D7ULL, 0x5F3D58EE646D297BULL, 0x8D6E15B8C9C83B05ULL, 
            0x27BB55518DA5D026ULL, 0x443F55858FAD7E26ULL, 0xEC231C4249FB9868ULL, 0x05972F2DAFDE6A2DULL, 
            0x0805363156F9A425ULL, 0xF0D1CE3AB8A225A1ULL, 0xFD5E09008CDA6C37ULL, 0x1CF6AEDCA77C78B4ULL, 
            0xD04DCC6FC48DB451ULL, 0x9E4817174B873B97ULL, 0x1AE164AA091B28B3ULL, 0x7732590358AACE48ULL, 
            0x5624DB3548A21D09ULL, 0xD91F6AF76C694786ULL, 0x032E723EB9ECD8E8ULL, 0x304FE772DA24E5E3ULL, 
            0xA99A8F548DC045E5ULL, 0x0BA08DCF5A0C6112ULL, 0xBBD9DFE94A6CC047ULL, 0x9EE6B7B35117E2BFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseEConstants = {
    0x0502461AE19B705BULL,
    0x159D88E6FE93B97FULL,
    0xCA1A77D45F389B44ULL,
    0x0502461AE19B705BULL,
    0x159D88E6FE93B97FULL,
    0xCA1A77D45F389B44ULL,
    0xCB9D06BB8A7AB6E4ULL,
    0x063F8114C16D56CFULL,
    0xC8,
    0x82,
    0xC1,
    0xC6,
    0x26,
    0x45,
    0x86,
    0x16
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseFSalts = {
    {
        {
            0xEF4D17D81B9DCB02ULL, 0x0D1CDEAD94A0F612ULL, 0x67A5ABBAAF2C4D08ULL, 0x5312763EA42BA8B2ULL, 
            0x1781156D2979B7DCULL, 0xCFF1919E56E70FCDULL, 0x9602D53A56516CA0ULL, 0xCF9DA4D43376912FULL, 
            0x4B405269CF800001ULL, 0x3CDBEDE5CFDD31CEULL, 0xDA24C38163E491DFULL, 0x1E0D1DA72F8B98DFULL, 
            0x6E85A4FEA7E834BEULL, 0xDB3780E12FC0AD4BULL, 0xE8B294D97B7C0542ULL, 0xF0282460A1DA4817ULL, 
            0xCF5EDAE4EC4D3E94ULL, 0x4CD884BD9566270FULL, 0x8A97A4621BC92940ULL, 0x2B029ADA427CDB2DULL, 
            0x9FF3F10E05DAE6FAULL, 0x25248C9510B40706ULL, 0xC531C5E2EF9D056EULL, 0xBD20E4EF2BC757E8ULL, 
            0xCDA6C2FB92D1795EULL, 0xF6549F84BD857CFEULL, 0xA8ACCC6F00C9FAC7ULL, 0xE572005D3E78ACC1ULL, 
            0xAEA81BD83311CA9DULL, 0x7C9E98519F100C46ULL, 0x549609B7DCF2E10DULL, 0x15BD8E6848B8C021ULL
        },
        {
            0xFCC9734B4AB9169DULL, 0x728F4AF581302A69ULL, 0xC3863853C2180618ULL, 0x7E40BA0191509BFEULL, 
            0xD2A75E99AE61B74CULL, 0xB1ADAD7863D232FFULL, 0xED250325569D3D31ULL, 0x59691AB208ABAC1CULL, 
            0xB7E97715A27D1907ULL, 0xEF69250798640BBBULL, 0x8C5AFAC073966C6AULL, 0xFE82991C0C28EC2CULL, 
            0x378471FFA337A4D9ULL, 0x9952D92998274D7AULL, 0xD0C35E6D519F2B30ULL, 0xBE9BD6453BD8AC4AULL, 
            0x8ADF993CDA6431AFULL, 0x933EAB1E1E61D0CCULL, 0x47B34F31B5CE25AFULL, 0x0BB027E7ACB9EBC5ULL, 
            0x6EA4780CBBADC3ECULL, 0xEFF6BA362B80D91AULL, 0x209DF56B7E5FBF9CULL, 0xB0754FBE28679242ULL, 
            0x5F3D89EFFAB365D6ULL, 0x874D3A66B0427437ULL, 0x02A58EC0A63FA6C5ULL, 0x8918CDC74020F281ULL, 
            0x69CC8B638E37F364ULL, 0x0CF024EB54B8E6D9ULL, 0xDD3C44EEF152A227ULL, 0x9ECAE6384C08F371ULL
        },
        {
            0xA3400E503E998618ULL, 0x93191A395B83EC6FULL, 0xE84D7B315463FDD1ULL, 0x8740134A9D57E01CULL, 
            0xAB6FE4E68C43F9D7ULL, 0x7E9FD1564EC650AAULL, 0x5CFC79815D75EAC2ULL, 0xE61BA2DC4295B2E6ULL, 
            0x3786EF4E650430F8ULL, 0x94985F5201D03394ULL, 0xF67770AA07EE23FCULL, 0x6A9844589BB33209ULL, 
            0xCD1D7A2EA06E3DA5ULL, 0xBB7138BD8218D069ULL, 0xFE4657F84DCC1E5BULL, 0x60ECEA1A0CD7F532ULL, 
            0x4544AC97F6CC5639ULL, 0x03383B3C5568EDDEULL, 0xAD84395ED5A211B9ULL, 0x0EFD242192FE87F0ULL, 
            0x24BC67F16642ECBAULL, 0x84DE99BC030D7DE8ULL, 0x1B6287FD30DA2753ULL, 0x450EB5AA86F4D2F6ULL, 
            0x60A5324EF8B15C77ULL, 0xEF20DB4F49FA6118ULL, 0xD886B02D5F01B80BULL, 0x9AEA4089C4B1903DULL, 
            0x2D394EAB5451156AULL, 0xCB46FF26FE95A510ULL, 0x6CD0E1DE43191F6CULL, 0xEBAC484634C8073AULL
        },
        {
            0xB96D9A3DC87B505EULL, 0xF1FCE4967CDFB09EULL, 0xA155B77CE54726CDULL, 0x3AFD08B9AEEA20FEULL, 
            0xC8D651CF0D441351ULL, 0xB854338DE2FDB8A0ULL, 0xA8891A1769A5084FULL, 0x86DA915637F289A6ULL, 
            0x839D5A77A98A5B93ULL, 0x8DC274103CB8BD54ULL, 0xF83066866A48C694ULL, 0x4D925B5CE0559D68ULL, 
            0x59BD154270F48996ULL, 0x2681F646665AE7AAULL, 0xDF22334F2D61A4E5ULL, 0x39B06487929BD829ULL, 
            0x7C6E795E3AC13BA1ULL, 0x4AEAC1E6171519D2ULL, 0xEAA0B0D128B61702ULL, 0xFF11719147387635ULL, 
            0x018A74820361EA1EULL, 0x848A23793F77D51FULL, 0x1311BA216AC84EEAULL, 0x105476E98CDDAF2EULL, 
            0x5660F57F075B0F8BULL, 0x0BD72CA55C175BACULL, 0x969E111E57B64803ULL, 0x2F7484456487B9B5ULL, 
            0xCD8DA1F22237243EULL, 0x0A17E55102C64D77ULL, 0xA8B9783820F43CD3ULL, 0xF95175F450B60ABFULL
        },
        {
            0x134C7D1A42A1FC32ULL, 0x3B5647E570F95DDDULL, 0x79F7D7827FB914CEULL, 0x0423B2FEDED619EFULL, 
            0xB132C7C1CACCA447ULL, 0x86AC3D1E3417C11DULL, 0xBB4590ED6F785189ULL, 0xE2AAA98C5CEC16FDULL, 
            0x17FE3B9D31783B82ULL, 0x5E47E69A8047A00FULL, 0x9A0198B801135A65ULL, 0x5CC37C36DE603B88ULL, 
            0x6058869691791D6AULL, 0x9F96A2F422501BCCULL, 0xEF74AF113AB193AEULL, 0x40DCABEF6B66D867ULL, 
            0xABEA2230BBD3B246ULL, 0xF22CC8DC26D87F41ULL, 0x89E0A9CE980C16AAULL, 0xA776E81556982C00ULL, 
            0x2A633CAC5CA924A7ULL, 0xE3A5D16890AD8B39ULL, 0x39F5DDCCC898EF4BULL, 0xBBF86C5F3244F61FULL, 
            0x57A4E0D3E70866B2ULL, 0x8567ECDAB9CCF134ULL, 0x54117FC88A508EA7ULL, 0xBC1BF80981CF0168ULL, 
            0x4D7DAEA19AC7D9D7ULL, 0x4909F4F64CF2A2BEULL, 0x22FFA66E2BA257C0ULL, 0x354AC68C07F1435EULL
        },
        {
            0xD186647A828AEC0BULL, 0x1B988F433F3C7505ULL, 0x44B8ABCFCDC9799BULL, 0x94B0A6E3BC4818C9ULL, 
            0xF0A35650F202B7E7ULL, 0xE2660F0CD2921155ULL, 0x7C533B8ED2AD6D11ULL, 0x3D93FB9B577021CDULL, 
            0xE328ADCA02E18209ULL, 0x4C771ED96679CE0EULL, 0x51F478577B7E903AULL, 0x9D34F7A90DF9CDE0ULL, 
            0x0E300D50B73A0B3DULL, 0x79216F715364C16EULL, 0x6D9A02CA0E96ED70ULL, 0x4821C05C4703200DULL, 
            0xCB91B6033A6CDC9CULL, 0xDD0930D32BAA5613ULL, 0xF8010872AE754456ULL, 0xC555F59BACF4E5D0ULL, 
            0x08EE161C88BD1947ULL, 0xE100816700A8EE00ULL, 0x216F0F17848A7BB6ULL, 0xBC28E9BE69A6B557ULL, 
            0x91123D06E49E10EDULL, 0x54D24939CC5EE667ULL, 0xFB031AE5BE4E07BDULL, 0x7CE1A8FC883E1580ULL, 
            0x306BB3FA20950E6FULL, 0xE723CD88BC355BCCULL, 0xFC4E109B81A9B764ULL, 0xAC2CCEC7DF71CFB1ULL
        }
    },
    {
        {
            0x5239671993662E58ULL, 0x743E01A9D7E5ABF3ULL, 0x8EBB0BCB1A017C20ULL, 0x928EAD05BC844FEFULL, 
            0x972F3922E27F39E0ULL, 0xF3EDCCB85074593FULL, 0xE0AE6FDCCE0693E2ULL, 0xFD08E7DD0EC2FEB4ULL, 
            0x874D45725F71A6F0ULL, 0x0CBC2D2E5230A4D2ULL, 0x7C19835FD9560D92ULL, 0x0F8F579B153FAC4BULL, 
            0xECBAC038C7CA90CEULL, 0xA6D42CA040213B8CULL, 0x88A6273914114004ULL, 0x2ED233C1948D1803ULL, 
            0x588080A78E85F81DULL, 0x955FBF18FDA92742ULL, 0x7F2C780E9974469DULL, 0x039A67914E210C62ULL, 
            0x2EF0C48C3569EBC5ULL, 0xFBE53D0A8C9C4528ULL, 0xDEAC5CDE2A91506DULL, 0xEC0504240088EBDAULL, 
            0xD879696EEC1BA68CULL, 0x6D28A48064249FF6ULL, 0x6BF585464F57C891ULL, 0x7E97CC8E4D908777ULL, 
            0xE265189C12280EB3ULL, 0xE06D4D1F62451642ULL, 0xA43A06C895A126D2ULL, 0x22CA9BE3F95E7322ULL
        },
        {
            0x1B63220BFCB9531EULL, 0x70C63B41289F281CULL, 0x8081EF9A642DCBDBULL, 0x708A8235819F90F7ULL, 
            0x46C35E458118F35AULL, 0xE2F9C0A450558B0AULL, 0x2C3C1DEF9EF58D5AULL, 0x65E6568393E9128AULL, 
            0x885FE6F73764EBD3ULL, 0x88ADCD3CD89B1BFFULL, 0xBBBECA14FCF21035ULL, 0x1BA85069ED0E4795ULL, 
            0x94F4E1F0F1638DC7ULL, 0x8A2A84674EFD1017ULL, 0xB681A34DB11B38C6ULL, 0x1092CD519E7530E7ULL, 
            0x9A90C680CA52CB80ULL, 0xB7ED3E0741E59BEAULL, 0xA03DB5BB67AE994BULL, 0x0B335639A3423517ULL, 
            0x84622FA3F71D0C74ULL, 0xCEAA039945C2A8FFULL, 0xCC6A67059FC971C8ULL, 0x62C3C8D71E31012DULL, 
            0x3242FBE8719B94DCULL, 0xA5CED331AF359BBDULL, 0xE04F1624D4A5612EULL, 0xC24CEDB4F315E2AEULL, 
            0xD8E591A7ACF6A5CCULL, 0x249B0C45250D2FDEULL, 0x7E761C946597DC06ULL, 0x6E5D8E4EA98D88A3ULL
        },
        {
            0x0D3CB53A6A13F362ULL, 0xA36EA62679960E2FULL, 0xBDAEEAF73AFD8ACAULL, 0x2F8DE89880AD4462ULL, 
            0xA0D4581D9B2036A9ULL, 0xCD2EEC7BC8FA7363ULL, 0xBE1CA25A8E1550D6ULL, 0x0F17B8512ED07957ULL, 
            0x2A2B0C74EB1DC817ULL, 0x497CCC7F0A7DE91AULL, 0x0347064418AB6AAEULL, 0x6B5391D31A5AC6D3ULL, 
            0x74329E1521C1A24EULL, 0xDDF622D50C331026ULL, 0x1810A7818169B35BULL, 0xAEFCC3BDF978DF9BULL, 
            0x96A0510CB0859B86ULL, 0x7D82378B94097093ULL, 0x355A53035816A75CULL, 0x13EDD419616C17AFULL, 
            0x68D21C93258707AAULL, 0x280313AE1B15319EULL, 0x2894DAF046CE88BAULL, 0x8B60C2E922BCAFC7ULL, 
            0x0DEC3709AB0856B0ULL, 0xE19278E71B186E9BULL, 0x172373D2F89BA817ULL, 0x13D20E4623902473ULL, 
            0x010FD5FB2911DD5EULL, 0xB73275DABF7D4220ULL, 0x6D5C36AB83409519ULL, 0x062F31B0C3E8448BULL
        },
        {
            0xCED8E787891197DFULL, 0x96A6959E8E6A061FULL, 0x981C870B6CB243F5ULL, 0x1AD23730F72BDEA1ULL, 
            0x92CA920088BE19E8ULL, 0x2E933B39C1F16E83ULL, 0x64F4A479676487D7ULL, 0x812BDA9453AFB49AULL, 
            0x0773B5D161D6CE7DULL, 0xBD714298D6B94933ULL, 0xA29BC98941FC5773ULL, 0x4B72D058856623CBULL, 
            0x9023BF98D6A847D5ULL, 0xC150BE0BE27B7574ULL, 0x39483BC0839E421EULL, 0x8467B2CE65F7E8BBULL, 
            0x55E4A03AE83DB6DBULL, 0x81C933B0B4AAB726ULL, 0x4C3607D884A5E398ULL, 0xBF155FFBF3B3B134ULL, 
            0xA4DFC0A8835428CDULL, 0x87CAE6669FE98519ULL, 0x4EFBA97B167B29B4ULL, 0x3BCB3C4FD184A66CULL, 
            0x4120DA47E4147764ULL, 0x6C4201CF71E2A9B4ULL, 0x843963CC2A304E0AULL, 0xAADD3E3903BAEA5DULL, 
            0x2C3555F54F3CF825ULL, 0x11C5D01520C4D2CCULL, 0x1C73851BCFB201A9ULL, 0xF183FBDBF3D4535FULL
        },
        {
            0xC360C3C33CC74A50ULL, 0xED988D37C15F9754ULL, 0xD4A487DD589596B4ULL, 0x768FD4089F20EA4EULL, 
            0x793250DF2DBCBF94ULL, 0x2078F54B42306BCDULL, 0x8A3279BABE97967FULL, 0x7F491E564C133370ULL, 
            0xFA0BE115E6EF22FBULL, 0x05D0520EF882D621ULL, 0x47FC78B076D77FD7ULL, 0x0E1D55156EC27943ULL, 
            0x6BFED15BD70D4A0CULL, 0x7179AA53E24CFAA8ULL, 0x645200675E34695DULL, 0x74890AAEB3D6EF6BULL, 
            0x6652BC1B738F51E6ULL, 0x042F406AB5C3B213ULL, 0x81859485B03BB7C6ULL, 0x7FB4752A1BC201A1ULL, 
            0x788A34648CED69D5ULL, 0x50E66B6DB44FDA46ULL, 0x5148341BDB4DF04EULL, 0x91F63205EED70470ULL, 
            0xA309EED2EE59FAD2ULL, 0x64E01345BFD20693ULL, 0x995CEC84FAFD8D21ULL, 0x6C48282D1C11B531ULL, 
            0x0B4C750987418A66ULL, 0x422A7A6705D928F3ULL, 0x31FE2EDCD8865A86ULL, 0x88FD3F9CDD8278A0ULL
        },
        {
            0xD732FA6E33657AF1ULL, 0xD339F38AF7C07BC1ULL, 0x75E2028C59EF5F55ULL, 0x51814F7BA7463B78ULL, 
            0xC64D1523C72EBDA1ULL, 0x27E7048F76F95E0FULL, 0xBA62B7E632D70AD3ULL, 0xC41B4F5E9B6C5FD6ULL, 
            0xD95701610ECBAB8BULL, 0x320098F6D66B6D44ULL, 0xE8DFDCC0790160ADULL, 0x820DE09A4DF5661AULL, 
            0x2092BC6739E6591FULL, 0x2D3DA694EF1FF39AULL, 0xFE84F6761E6F128BULL, 0x8826C6C148200323ULL, 
            0x0B91FD68B3EEB27EULL, 0x14674A39AE1ACC3EULL, 0x20D600DCD7E5F6F8ULL, 0xD5E637CBD4E043CFULL, 
            0x096F5379B27C5CBCULL, 0x27445832C088B0E3ULL, 0x387687C908013A77ULL, 0xFEE605F081340D0DULL, 
            0x53BF210BDBD87529ULL, 0xEB442929426BA42EULL, 0xF637D37F3F4D50CAULL, 0x4BA8C7E0516BF2F9ULL, 
            0x2017C94E4FD33DD7ULL, 0x63CFDE4B8AA10A20ULL, 0x98030F3C52F9FB78ULL, 0x314B9FA3D2376849ULL
        }
    },
    {
        {
            0x5EE1FD5D0D507FF4ULL, 0xB41DA71FD290D06FULL, 0x31F45CD7CFE39B61ULL, 0xBDC7C430B2E6522DULL, 
            0x4FF9554B85381BF1ULL, 0x583889C10988CAE9ULL, 0xE10C7C3B46A86CDFULL, 0x51F839E98C6B8EF4ULL, 
            0xC6B44D879AFD283BULL, 0x83380C0235586167ULL, 0xAE053A6FA55042E6ULL, 0x53725DD5148E30D8ULL, 
            0xC36AFC45C9C1F375ULL, 0x17F2B33DEC0CCE18ULL, 0x8D3D9B23BC40B7E9ULL, 0xF10DB433224A35EBULL, 
            0xED5CDF2FF8F84202ULL, 0x1FF0FC4566810036ULL, 0x5FA517390983C2DBULL, 0x73E8A4E472893C0AULL, 
            0xC78ADC9D524496B1ULL, 0xAE5A1457406CC3E8ULL, 0xC0848ADE61971359ULL, 0x1E6C06F71D99EDBBULL, 
            0x4820A19093BCF38AULL, 0x0ADEEBEFC83B34DCULL, 0xC36E48E6D411E26CULL, 0xEF35CD4642ECDE0EULL, 
            0xD34BDB33698362B9ULL, 0x7322594DC9653571ULL, 0x85F8DB240F1DBD41ULL, 0x181F6F609252748CULL
        },
        {
            0x4D579038F9B9F825ULL, 0x030B351E3D1FADC8ULL, 0x37721C5D3F5002A0ULL, 0x62551744688ADD2EULL, 
            0x39EF5144CEFB8096ULL, 0x2BAD8E0B2925C18AULL, 0x816934B52FC66271ULL, 0xAEF20F9B33DA5051ULL, 
            0x6E3A27A9BD81EBE0ULL, 0xFB1BACE06E575429ULL, 0xD4ECD64B186320C1ULL, 0xAC0CB78A0A0076D8ULL, 
            0x3337B893642E19F6ULL, 0xFA791A147FB1617AULL, 0x4DCA32540E6B7FC9ULL, 0xEF751A71758A0593ULL, 
            0x78C70EEB3D1090F5ULL, 0x6149F6060EF85EDEULL, 0xE70AB359C9C9A257ULL, 0xE2DF450F3D8582BAULL, 
            0x0AF25C9AA41A6B26ULL, 0xBDAA4FD5BE73D361ULL, 0x3FEEF8F1350380E3ULL, 0x7184543A89561C1BULL, 
            0x177CC2240B8ED35DULL, 0xF50CB9F7C139CA1CULL, 0xAB8DB1414B5E9C29ULL, 0xC12B7582B126EAC9ULL, 
            0xD037964895A46E16ULL, 0xBB49129740EAB9E8ULL, 0x6E676287068C7BBDULL, 0x27E10C18A47866A7ULL
        },
        {
            0x6EA1E13D352FB7C7ULL, 0xEC4B255E06932584ULL, 0x151E47A98911FEBDULL, 0x0F649016F3E037B6ULL, 
            0xDD2BF78629662E53ULL, 0x39AD0730D1FBA399ULL, 0x61C85B8D6331F45EULL, 0x02F570E62254339EULL, 
            0x8B6D26DC80958789ULL, 0x0B319A63E0D42A20ULL, 0xAE3AD70078E16AA5ULL, 0xA52151168856E926ULL, 
            0xF89CCAC2960FEAF4ULL, 0xAF1F1934B4E711EBULL, 0xDC60B6DA1CAFC391ULL, 0x8A26E3D388270391ULL, 
            0x90B7E148C4E272C1ULL, 0x3918BC2EDC392161ULL, 0x399C1A86E9960540ULL, 0x2C20E6355EDF9124ULL, 
            0xD62BFB06ABAB57FCULL, 0xD8D7D592439A4D00ULL, 0x3C62D49AC0580E66ULL, 0x4ED57A2B4F773CB6ULL, 
            0x01CB1DBFD62AC443ULL, 0x121D2EAC30D1007AULL, 0x5ED30B3AF1ED57A2ULL, 0xD87F0F14726D81C8ULL, 
            0xD49CB096ED35E96AULL, 0xE023EA3EFB651477ULL, 0xA830154DC2D48E38ULL, 0x2CD736BA233FB8B6ULL
        },
        {
            0x4537581F7E9E6152ULL, 0xBCFDDB7596ECA6EBULL, 0x7C52F239A72528ABULL, 0x60CA39A9C2EC847DULL, 
            0x830F92C90EC20BAEULL, 0xEF71A19F16A6B1B7ULL, 0xA70C12124F3F72D8ULL, 0x82EFC1EAC1435465ULL, 
            0xFBA8D938D6D2162BULL, 0x34E43BA787A2EDD4ULL, 0x08933C3DCB4C43AFULL, 0x1E707361C95D0835ULL, 
            0x8B14A2E2AC1B4DB8ULL, 0xDC48B1BB4BDDE102ULL, 0xEFF3C899BB54561FULL, 0xF389968CBC58CF86ULL, 
            0x9C7195FC18CEEE57ULL, 0xC0CF39E22B75BCF3ULL, 0x316059A948A99AF7ULL, 0xF874C5E01E58089CULL, 
            0x989112A83EC7E7EAULL, 0xB79A9D66B8637B03ULL, 0xD9E7F8B0FA70ED93ULL, 0x9328C005CE8AD0ECULL, 
            0x1C6F648AB822DADBULL, 0x82E0E55BD3B4F881ULL, 0xEBA7E23F4AC6007EULL, 0xC30D9B2A617922AFULL, 
            0x30DA40743921C01BULL, 0x76F983B29C32E04FULL, 0x4742E9822615910FULL, 0x01F44EFE8FC61D2FULL
        },
        {
            0x25DB38FA69727684ULL, 0x9FDDC419C333F324ULL, 0x958BEE23A781F331ULL, 0x9720C7EF0DF190D9ULL, 
            0x9FFCF0DB9CF92D59ULL, 0x156ACBCA7CF02226ULL, 0x6AA28DDD2715BF68ULL, 0x48DD73FA18C14BA9ULL, 
            0xC986F3D860C0620AULL, 0x4ECB9F4E348EC216ULL, 0x85883BC50D1F777AULL, 0x4471F48CF24E6C6CULL, 
            0x5811761C75D0ED6CULL, 0xAFC2F150A3447DDFULL, 0x192FB3D9B2FE867DULL, 0x75C51971F035B73FULL, 
            0x072D12421F18F2ECULL, 0x867861DDAB8AF80AULL, 0xE4E0EE97FF925806ULL, 0x3149E9C2BB52A0CCULL, 
            0x06665B4E97797A3DULL, 0x2D1D02858BD15D88ULL, 0x45758F949CF65D58ULL, 0x0D96902A2C0E9DD6ULL, 
            0xB7AC17837417389CULL, 0xA2966D2ACCC3E0AFULL, 0x2799DC064B21E54DULL, 0xEB63D86848D3F500ULL, 
            0x9006A926E4291949ULL, 0xB487E6833665F13BULL, 0xA4EBE9C2C43C3014ULL, 0x8DFADBEC2C7F74EDULL
        },
        {
            0x1A035DFD355852CAULL, 0xBDCFF6535C2BC784ULL, 0xBFC246CF1BE33773ULL, 0xA1A1E5F0BCBCF4E9ULL, 
            0x9CAE7D3E1085B177ULL, 0xE1AEA41D32CAC7A4ULL, 0x9283B28F098BF3B6ULL, 0xE17B017ABBBB126EULL, 
            0x144E9AB5B3288F4DULL, 0x6634D63489866C40ULL, 0xF03D949D18D5D708ULL, 0xF14D930CA686A291ULL, 
            0x69CC9E49B21E7371ULL, 0x67BEF103317DEDC4ULL, 0xABE5447980758C7CULL, 0xCF06DA80B71AC51CULL, 
            0x68AB7C93850746BCULL, 0x0B4668139ADFC3BDULL, 0x0C8E5AA5DE4F88BCULL, 0x8FE246799814914EULL, 
            0x760B7CE1AA0F3D6CULL, 0xB0FF2997162CA2DFULL, 0x67D514D06537D4E5ULL, 0x677B407C2CD91028ULL, 
            0x130D832BCA83EE96ULL, 0x91D5CC1FE1745B52ULL, 0x643645CD0EE31AF7ULL, 0xCA5421FEAD957961ULL, 
            0xEC178EB423D7120BULL, 0x6FDB724C819ED29EULL, 0x8A4C2BBD8A56BA01ULL, 0x6EE5F2E127A4DC63ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseFConstants = {
    0x4B856C3A46C90A9EULL,
    0xB524179263F7B812ULL,
    0x707FDEE10F1321F1ULL,
    0x4B856C3A46C90A9EULL,
    0xB524179263F7B812ULL,
    0x707FDEE10F1321F1ULL,
    0xDFEE893C550A2782ULL,
    0xBF38905F58EE62A1ULL,
    0x5B,
    0x78,
    0x8F,
    0xF1,
    0x6A,
    0x92,
    0xCA,
    0x63
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseGSalts = {
    {
        {
            0xB3FA2CA45321F6DDULL, 0x9D36CC778601682BULL, 0xB7F10292AE81C5C4ULL, 0x7E74ADCEF4299883ULL, 
            0x5AF5BA26A7692972ULL, 0xFBA3909C182F9170ULL, 0xB911E3C7B1C3F661ULL, 0x30057CE36A39BE94ULL, 
            0x4B682EFC8AC219CAULL, 0x76201EC6845631F4ULL, 0x623007D2BBEFBAFCULL, 0x7CDDD45556F03506ULL, 
            0x1EDF317A7F601C1AULL, 0x4C186B2F0F62F916ULL, 0x574DFF0BB901B9D9ULL, 0x76A15AA875AC6ABDULL, 
            0x257C9B44C348A929ULL, 0x6C03DE2374186514ULL, 0xE7069222448564FEULL, 0x66EBEA06F8AF5A7BULL, 
            0xE53497B8242F619DULL, 0x85624FCA157EA81BULL, 0xD7406E780980D2BDULL, 0x422112BF04AF77B5ULL, 
            0x292E4B6DBFFE3D86ULL, 0x4BE501C7A7E95578ULL, 0xFF937BA0487AEE54ULL, 0x1B17DFA4F0DEBDBFULL, 
            0xBBC71BF4355DF9D2ULL, 0x20E1CC3B3D6712B6ULL, 0xDB8F03E81442D6C1ULL, 0xDA1B35195DAF386BULL
        },
        {
            0xFC956DA7A9DC06EBULL, 0xA8E45CC61E1E015EULL, 0x7D671B87B16C44E8ULL, 0x063699CAB777335FULL, 
            0xD492D538D34D72AEULL, 0x2172DB13E11F824BULL, 0xCF6BEE1B8C4ED248ULL, 0xBEA1AA8E34DDE0C1ULL, 
            0xFFE1663B3FDDAAD9ULL, 0xDEB89590F50F7930ULL, 0xB25A54479DFDFBE9ULL, 0x29161F0E474C3B2EULL, 
            0x8C461978671F4A80ULL, 0x696BCEEF2092D5DBULL, 0x67935052AA525A1CULL, 0x1838A737A9E90807ULL, 
            0xC69951FC2A2CBB0DULL, 0xA1A71A47E3FFBEF4ULL, 0x74D1CA681F304AC2ULL, 0xDAFDF4CE78CDA94BULL, 
            0x4171C40F159E607BULL, 0x6F073AC3F1BCD47AULL, 0x4CC9192ECE1DCB16ULL, 0x52983DED62DE2F58ULL, 
            0x53B022970E79F8DDULL, 0xB97A586CF3073863ULL, 0xC7EF220E6B56028AULL, 0x1C78ED710A62F01BULL, 
            0x41DCB31AE8B27ACEULL, 0x3B28A88D3584439FULL, 0x0A48E4EB9788C4F8ULL, 0x3C9DEB79BA1F84FBULL
        },
        {
            0x773018B2C044BDCDULL, 0x65E2155F3D1F3B8BULL, 0xFE22264EB00872FFULL, 0xF60A9DEF2FB922F2ULL, 
            0xFD2FAF8A3D09F400ULL, 0x4CC0A8EEA206ABACULL, 0xB86EFD2EEA0563DBULL, 0x462486066FE73FD9ULL, 
            0x6EB238AA04CA805BULL, 0xA0F929E2FE5218B7ULL, 0x55082A60B29F010EULL, 0xD5771BAB7F5BA578ULL, 
            0x15CB9839FB72E74DULL, 0xA799AC1AE06C868FULL, 0x857DDD39DAB10E3CULL, 0x0D0ADF6C66B8FF8DULL, 
            0x711B8D3ABBF83406ULL, 0x6CB087B8B950235FULL, 0x0B9987FFF88B668AULL, 0xB20F65C6E35031FAULL, 
            0xF4A5C3B4B2B3C545ULL, 0xDB742263357704BBULL, 0xAF6F94C667ADA3CFULL, 0x3A4C31AE9BF5281EULL, 
            0x6F0EA989845EC30DULL, 0xCB29DD69C2F419CEULL, 0xC8F69E119FB6B2A6ULL, 0x74345223F94AB497ULL, 
            0x4AB7237C22C2B506ULL, 0x84B71554F4158D08ULL, 0xA25A823F4CAB23D3ULL, 0x47F45F9D1785D307ULL
        },
        {
            0x11F0B320DFB2572DULL, 0x7E35E5BDB45264ACULL, 0xC40C2D360228ECFAULL, 0x466121BEA1576E41ULL, 
            0x1E8DC881C623AD04ULL, 0x79E76DA008A75C1AULL, 0x56773E63296CE3E7ULL, 0x60116CA826C8D445ULL, 
            0x1F9F9221FECD737BULL, 0xA523377C4941A712ULL, 0xF5D64A4CCBC2B71FULL, 0xFAF2499D5D2F54CFULL, 
            0x9E72A327329462D2ULL, 0x95026D9B5C87D534ULL, 0xD2BD8340FEB4CADBULL, 0xDD1572E30BA4AC14ULL, 
            0x8E959EAB15E52C7FULL, 0x2078DC8F23C17F50ULL, 0xB90EA19758195656ULL, 0xC4C1C871894515BAULL, 
            0xA972F99E184269E7ULL, 0xF5C16F7C3F39DD2FULL, 0xA15C40E1833AD4FDULL, 0x00CAD419FEED1E41ULL, 
            0xC785DDB95253FB0BULL, 0x0905116F022125DCULL, 0x0BE7A724F5135F64ULL, 0xEC9B7D6E2C1DC9F5ULL, 
            0xF98231553495D45CULL, 0x8CF5C08D37A8A4E3ULL, 0xB208165CE5A35BD9ULL, 0x1D73CFBD41BF3FFAULL
        },
        {
            0xCB2C6157B55BD871ULL, 0x7B80B2374279C4F2ULL, 0xB7B7C13DAF475BEAULL, 0x5CBE870ABF36FB9EULL, 
            0x8163F2C8EB3E90FBULL, 0x6FFFB2B8C4E6451BULL, 0x7F43E698E033963FULL, 0xF19E950E3F938533ULL, 
            0x0676CB9DF973B727ULL, 0x53A81712E8DD8C52ULL, 0x9414DBCCD02E037BULL, 0xA2A4EFD378903D69ULL, 
            0xE1AB69113EC0BAF0ULL, 0xD6B9AA7D605E3564ULL, 0x05A23FCA3D401A0FULL, 0x4230D8863BEA8C19ULL, 
            0xA0C981D4F141F65AULL, 0x8C816BDE47CB938EULL, 0xD40091936EE6288EULL, 0x9DF3D24E2B4A7665ULL, 
            0x30C742EB7DB11516ULL, 0x1248CDE7A727F499ULL, 0xBD402F55A9A20576ULL, 0x456B807D86852106ULL, 
            0x4A7F628F0F76CD32ULL, 0x3AC1026FF373C9DEULL, 0x6119FE984D1E8001ULL, 0x62283D37909547C1ULL, 
            0x5BD2EB66E17B2A44ULL, 0xC3199D1B01ED8789ULL, 0x4ACEEE78C8BD95ADULL, 0x215D1D291A3CEA5EULL
        },
        {
            0x767CA0A57FC0BAF6ULL, 0x7593F7F1EB09219FULL, 0x6A0A0E1379EC193FULL, 0xD35C6CBB9282F975ULL, 
            0x0626AC3A635F3BAAULL, 0x39DBC95FD96BA44DULL, 0x5609675B1540073AULL, 0x627846203A0BB040ULL, 
            0x185C1198431EB37EULL, 0x37FF36A898F4C498ULL, 0x92E670645C5AA2CEULL, 0x27BA639AF70F980AULL, 
            0xE05FA5652DA710D3ULL, 0x6163A39EA6302BC6ULL, 0x3C67761A6216DA70ULL, 0x5F3ED5BEDD5824DCULL, 
            0x27DF988DC4BD4DA1ULL, 0x885D5C653B4C1915ULL, 0x1BC003DAFDAFF493ULL, 0xC0A4C45796C1FD75ULL, 
            0x32F1CC4266B04A35ULL, 0xB5EF427A8ECB679FULL, 0xC249D62278092A39ULL, 0xCB4881B2D1AFA5E4ULL, 
            0x0C2A0609D4F00356ULL, 0xCBBAA1693B105533ULL, 0x5E1FBD76700274B1ULL, 0xAEB46E22A337079AULL, 
            0xC92DBAB96097DEECULL, 0x4182029F8820A534ULL, 0x7E3A8C19AFED0A26ULL, 0x4561EB36ADABB8C7ULL
        }
    },
    {
        {
            0x48FA0E993AFC6C90ULL, 0xC0C68D7801102F88ULL, 0xFF51E9642F8224F9ULL, 0x248C9854D6E407D0ULL, 
            0xEAD11FE672066C7BULL, 0xC93FC19C68754E34ULL, 0xDB78166FD1775E5AULL, 0xF7C76A1B70B13DDEULL, 
            0xF3B795698BDA3F13ULL, 0x1400F9B2B9B2EC9FULL, 0x2DD4879FC0809FF0ULL, 0x79AEBEEC05205309ULL, 
            0xF59906997A671512ULL, 0x2F1F617F668C1135ULL, 0x4454526815E4F895ULL, 0xABF8E70A806FC808ULL, 
            0xEC5E7F70F49B3AE9ULL, 0x1A8412D3B7FE7DA4ULL, 0x33C4BAA6CEA04159ULL, 0x14765D0C9D5B553BULL, 
            0x9F1D128A5158338BULL, 0xA9C4868E7B8ED041ULL, 0xE924666E29400DD5ULL, 0xEC5E15A3F7448D66ULL, 
            0x8F44254016B39474ULL, 0x96F6815C9AF4EF50ULL, 0xFD381EF517D09377ULL, 0xCF8DA777882AA1D2ULL, 
            0x159F2A1AB3928303ULL, 0x45D6274996761F62ULL, 0xDD0207FBE056BFE6ULL, 0xBFD2C134DF0535E5ULL
        },
        {
            0x3AA441910D9EAC6AULL, 0x376898EE89B42D7CULL, 0x3F632F4A846A5845ULL, 0x28F171251E1AD1F1ULL, 
            0x3B756726603C647DULL, 0xA5D97B99EB0B352CULL, 0x3B4F8F9A886E006DULL, 0xACDFBB681C032CC8ULL, 
            0x265D81A0B2A990C7ULL, 0xDFD2ABC18CB1CE70ULL, 0xDCBFD6479DBDA5E6ULL, 0x216F88F4D706C40CULL, 
            0x3CDC23480F5997C3ULL, 0x96F8572A0A677F60ULL, 0x5D15A7AA6954EE88ULL, 0x015FC60BCD2B20F4ULL, 
            0x277E3A1CAF23BB1BULL, 0xA989514232EE0DF2ULL, 0xD738FFBB353200F1ULL, 0x1AE8C8EC21E009ABULL, 
            0xECD08AE0F87F8ED0ULL, 0x3F8D03060F7397FDULL, 0x71CA0F14EE180C13ULL, 0xCD4D05A9D39B72FEULL, 
            0xA2CEE15A46C13332ULL, 0xAEBAA2F388DF5104ULL, 0xB3E6AD4D0FF436E2ULL, 0xF4B620B983DC8641ULL, 
            0x187D5B650AD16AD9ULL, 0xF079A66937F81072ULL, 0xAA9064E3D553F059ULL, 0x228A51BF88001DBDULL
        },
        {
            0x7166C30660D63210ULL, 0xECA47D1A926DF632ULL, 0x3B21A4CD3E1B3134ULL, 0x0898848C555C5FACULL, 
            0x1CAFB23E7F67B349ULL, 0x7ECD40AC14C72139ULL, 0x4CA8D577D8EE4BC4ULL, 0xC84E2D60AEF58616ULL, 
            0xD7D0A095199949E3ULL, 0x790530DB117A6F15ULL, 0x299BA1BF3E1713B8ULL, 0x35B91278D8247E31ULL, 
            0x0CFEECBF12798B4FULL, 0x25AD70A7E619A91FULL, 0x04F12AB1C532A9C7ULL, 0x7251E45B13BB0C7BULL, 
            0x8B3E6CD69D78DC01ULL, 0xB0D98736DFBBD2E2ULL, 0x9B1CF02939DC2E26ULL, 0xCBBB32DE5D59AD0CULL, 
            0x1FFB586CF0AC2A8CULL, 0x90AD726CE2EB3E39ULL, 0x228D5DE8A3B28D32ULL, 0x050057B70729A44FULL, 
            0xE0BF391B43D4F8AEULL, 0xC7885223C550B4DCULL, 0x66A9DE553466438BULL, 0x9B172E5B255BF761ULL, 
            0x0780C826F83EB712ULL, 0x13521CB33C341904ULL, 0xD415E8A7B825A926ULL, 0x5802B7657D96BA03ULL
        },
        {
            0x65C14A492760838CULL, 0x9DAF25883A6CEF9DULL, 0x780CCC29D72D1BB9ULL, 0x79CB5FA4946B5E81ULL, 
            0xC5FCD73276468E4EULL, 0x1B91DDA76101858AULL, 0x1F1817FF86541898ULL, 0x26D615394D1D02E3ULL, 
            0x29C2966B136C8E5AULL, 0x926EB1E140BCA2E5ULL, 0xAE75B0B891A4DD77ULL, 0x96C591B71951D4AEULL, 
            0xD4C5BFFBC7139A5CULL, 0xC3B46C6C9C6C5A1CULL, 0xCDEE7735341A7C3FULL, 0xE2FAA264F7777F92ULL, 
            0x29F51EB5AC54D2B3ULL, 0xB7D88471D2FA28E8ULL, 0x94308D301B71B597ULL, 0x76F4884FC8E0D035ULL, 
            0x81AA4A28F3D2E205ULL, 0x5C9297379CC6CED5ULL, 0x3606D19CA5DCEB92ULL, 0x71C549290BAB4C8FULL, 
            0x84440E19645BD636ULL, 0x6986EB419F4600AFULL, 0xC90F1AED63556EA1ULL, 0x39F0FDB7E78C71F4ULL, 
            0x1D861D496404F981ULL, 0x0158CDE2B07A4D99ULL, 0x3DA90154BEFB91EEULL, 0x4AE03DBD7575D165ULL
        },
        {
            0x7F6459828181DC69ULL, 0xC68A93F2BFBEF90AULL, 0x051BFED1348FFB30ULL, 0x421879B8AB386719ULL, 
            0xFBF2247CDA8DF644ULL, 0x7672560DE1D6A3F2ULL, 0x6F8C111D67354C4FULL, 0x286876BEBB223565ULL, 
            0xEE362A2459E58EE1ULL, 0x1DEAEB5CD4C2B417ULL, 0x7C366829024FEA56ULL, 0x99A83C0AE33F6884ULL, 
            0x10D819A762D9A3A5ULL, 0xFCE729A0DBBF64A2ULL, 0xB2A33A7D9454FC7DULL, 0x50C2AFE7D09A50A3ULL, 
            0xB6E8E880A9745853ULL, 0x4F55082126C7FF1BULL, 0x1725D7A1456F8636ULL, 0xD994A65393175157ULL, 
            0xB1D79CFB9089C5E6ULL, 0xA5FC2F788E7DCEF4ULL, 0x6F91EA7DFFCA1848ULL, 0xE31414786505FDB4ULL, 
            0xDF09D0CC12241125ULL, 0x26653C2EBA3DA445ULL, 0xF3D5A9DD7D67B279ULL, 0x8C48BDDDC2D9566EULL, 
            0x8FC7440564D692FAULL, 0x8BDAB38839660FADULL, 0xA40814E7391B8217ULL, 0x844ECC1F16F08D16ULL
        },
        {
            0x7D4579C500E32FD2ULL, 0xA969CC7C4800E0C4ULL, 0x4261793734FC3743ULL, 0x7FA197CFEB6812E8ULL, 
            0x0CD2DC56FBDCA55CULL, 0x05E3D63E0EA617D7ULL, 0x74B20582A83D752EULL, 0x361944BF1C1B4DEDULL, 
            0xDC2B820548116B2BULL, 0xEFB09EE47DE0C4D2ULL, 0x1D43107167A36D0FULL, 0x34C5BD5B664D8CA5ULL, 
            0x80CDE2207222C665ULL, 0x46485D901BD10199ULL, 0x0885464319AA0DF7ULL, 0xE245AEFE44058FB7ULL, 
            0x823F22FDFE8D357EULL, 0xEBE8F8EDA867B8AFULL, 0x96C0FD72BA9E9A53ULL, 0x38F598608660B53FULL, 
            0xE6D46CEB6F2A1757ULL, 0xD40BEF7026497A8BULL, 0x86F4747BFE3ABD7EULL, 0x775E4D71F3AD856FULL, 
            0x207FA601469FF7A2ULL, 0xE5E72FD22359DA03ULL, 0x5ED4655A5104E6B9ULL, 0xB86FFD6992BE0E8EULL, 
            0xA443E31ECAAA80ECULL, 0x289F8F6511EDFDC3ULL, 0xAD2A07CD8B0ABDF5ULL, 0x79EE8AEDEC6F1C54ULL
        }
    },
    {
        {
            0xE7629571EA659BCFULL, 0xFBE241CFEFC25F9CULL, 0xFA805086487E8FDFULL, 0x8B2AC53E3BC0BF66ULL, 
            0xCDCD4EDF37D7FA2AULL, 0x1146CCE98EDA7F35ULL, 0x6CE01FCCC84A2B30ULL, 0xDD48DC44EB50519DULL, 
            0x48A9BC37F00E7276ULL, 0x92273DA021056BDBULL, 0xE1C6475F0A46E11DULL, 0x9EAD37E455CC7DB0ULL, 
            0xD3E85F26A5BFB130ULL, 0x198B5C3119055551ULL, 0x55D7893BEC975F3DULL, 0x180CA41B88131E72ULL, 
            0xA5E5D08FA63F07A9ULL, 0x118F56E0A78E40E0ULL, 0xE39BF05727892DB8ULL, 0x67C4A4B6ED2BFF28ULL, 
            0x56D6FA1F9F7793BCULL, 0xA23679051EA427EEULL, 0x198B3109E57A1267ULL, 0x55A520F6F24F35F2ULL, 
            0x9B83B5BDFA87BBDEULL, 0x97A8F62A754B35BDULL, 0x1D3D0DC21DA3CF67ULL, 0xECC5EF6BF50DFBF7ULL, 
            0x6327485E12DD332CULL, 0x261FBD207F6F240EULL, 0xFC09EC069D2AFCA5ULL, 0x629AB66A8A01BA02ULL
        },
        {
            0xCED360C88445F467ULL, 0x23366E9C65ECDAE8ULL, 0x735162B1624F3505ULL, 0x734BF211F09BAB04ULL, 
            0xB02751CF34590BCCULL, 0xEAF7EE5248A4B5E8ULL, 0xED783A1DA60A4ADFULL, 0x46954202926854FFULL, 
            0x7FEEDED1231A0259ULL, 0x090137CB207504AEULL, 0x7056990F46BD375FULL, 0xD4187C8DF13CC464ULL, 
            0x10BB619AF4EFB6A4ULL, 0x1FC92D4C4BD5A833ULL, 0x5C75682E0D75A6CCULL, 0x619A0F7BC34438BCULL, 
            0xB7B5172144C6D98DULL, 0xD8E4444641BC5B8AULL, 0x91352294017FD8F5ULL, 0x91961399ED55B268ULL, 
            0x8B410933FDFC9D25ULL, 0x494B7EB730D55191ULL, 0x2F85642EEED6CF91ULL, 0x2B4493C34C05DB6AULL, 
            0xDBC29B6BAE425A96ULL, 0x2F81204FCEDB4340ULL, 0xD88A6AE6D7666EE0ULL, 0x2BD760F11A7EEF18ULL, 
            0x437351824B0CB56AULL, 0x05B84890799F051EULL, 0xAE1C885E02AA61E1ULL, 0x2C3763DDB1F96B2FULL
        },
        {
            0xE817F9B1E182605BULL, 0x3F005963AFDC62E7ULL, 0xCF4AB91A73F402C6ULL, 0x326E1B72D3562543ULL, 
            0x3358A5DCC020F6D1ULL, 0x40DE768BD631394BULL, 0x73F86EBC3B26CB65ULL, 0x76F455D003486015ULL, 
            0x38EBE41F143147A0ULL, 0x59C2BDB43AD34C38ULL, 0xB984CD2136064DF5ULL, 0x98D74F77EFF0B456ULL, 
            0x29FC1ECE8AE87BF9ULL, 0x5C6B482196FEFAFDULL, 0x773311A25E0936C5ULL, 0x6666B0C1EFC03DBAULL, 
            0x96D37B48B8D2BC58ULL, 0x39D15BF8F63E192DULL, 0x5018D51BF2D85FD5ULL, 0xF1C0BB127D71FC8DULL, 
            0x08287A95FAFC86DFULL, 0xE19016B132E75D4BULL, 0x7B6C848B7AD41C72ULL, 0x2C8B08111E95D067ULL, 
            0x32DA971744A0AB18ULL, 0x69746DF1B4D24900ULL, 0x1E47F22C676EC558ULL, 0xED31E51FEDDAD3DEULL, 
            0x2B2A73768AC73FD5ULL, 0x3D7B3EE3647F1059ULL, 0x516C56EA87F0380DULL, 0x68ECEE33205FCEE7ULL
        },
        {
            0xF5BE4FB999740CF0ULL, 0xF5838C3ED05CB72FULL, 0x34474F321C04E903ULL, 0xC69BD0BD9E3D5B39ULL, 
            0x5355AE19CF9E7112ULL, 0xDFC3D94AD26B1C7AULL, 0xFD00099E1418D2C2ULL, 0x131B27293714B7E6ULL, 
            0xA46AE80866BA78B2ULL, 0x413F53456D638FF9ULL, 0xF62863F0E46528B6ULL, 0x7C0E05E21B3E635BULL, 
            0xFE28BE10040BD823ULL, 0x2179728542447478ULL, 0x269293247F953D7AULL, 0x1282D0314ECC7288ULL, 
            0x46F4B3098A2B0E0CULL, 0xEC288A9FB05535A6ULL, 0x4221FAC3B4D0EA1DULL, 0xFF9CA9A0A2882323ULL, 
            0xD7669BC619EABEEAULL, 0x14316031804115ACULL, 0xA84A3337C4190D47ULL, 0xA03868DAA1A5A369ULL, 
            0xEAF29839543EE027ULL, 0xEE058D26EC139CE6ULL, 0xE14590EFF07EF4BAULL, 0xDD48C9B327F53E2DULL, 
            0x9E9402F45AA43B47ULL, 0x6C61D40B6CF4213AULL, 0x45D5C22E0F94ED52ULL, 0xA02635F607905EB2ULL
        },
        {
            0xB1575E39F45FC28AULL, 0xE37ACD87359EC25AULL, 0x08086CE0F1070EADULL, 0xC13038876BDD5AA6ULL, 
            0x41B698BB89574F59ULL, 0x5836463412356244ULL, 0x8182FC77D347FADDULL, 0x5D2FB733B988A49DULL, 
            0xF38E279C91C2CF59ULL, 0x71F528A662A53789ULL, 0x0F18066E00C93468ULL, 0x9FC2F2670E7B9F48ULL, 
            0xFA7BA62BABB35BD9ULL, 0x903C7D28976C914DULL, 0x9BFDE60E5AA010E6ULL, 0x6B890A29172FC395ULL, 
            0xB746E26F4FCD0495ULL, 0x58118FA8EA6EE1DCULL, 0xD14CAF180CBF2567ULL, 0x610D0FD6BC21762DULL, 
            0xE444BA244AE504C4ULL, 0x384779C2B61512D9ULL, 0x43810DC6534ABAF1ULL, 0x603351647E70DC2BULL, 
            0x4D2F60153CF6266FULL, 0x5D1F216715FEE9E3ULL, 0x622D3D214FDB4552ULL, 0x626C7D73AED9F34CULL, 
            0x60AA13EB5A4EAC8EULL, 0x5184CE410C1B4EFDULL, 0x1E07B2C532D5F2C4ULL, 0xE74DE3EE83014895ULL
        },
        {
            0x24953541AAAC8865ULL, 0x0524136FA54A6C88ULL, 0x98543A637184DDBDULL, 0xC283A11D80921F39ULL, 
            0x8FB80EA919545618ULL, 0x5D1CDA3D17DFADFFULL, 0x50FEB9B138B2249DULL, 0xAA42B11FDA0D5AACULL, 
            0x89DEDFB1EF88F550ULL, 0x461F63C49D146C08ULL, 0x43714DF4D563A906ULL, 0x919F92F1D730B54FULL, 
            0x2F555C8ED916ACE2ULL, 0x4CD92E7A8EA3B3D2ULL, 0x163A2D1F65A86DDCULL, 0xFA5F648E8100A3C5ULL, 
            0xBD485F37D99FD9FBULL, 0xBC07FB2B0D71284DULL, 0x356C4CC261DBC0A2ULL, 0x7604D990103D36E8ULL, 
            0x8F93414F1D414D88ULL, 0xB98D9103D686EBB1ULL, 0x091AB5768FE0B4B6ULL, 0x3ADAE9D554BA0E9BULL, 
            0x16EF907710AEB615ULL, 0x76478478F0C34E6CULL, 0xAFBA9109416076DDULL, 0x42789EF2DA00A389ULL, 
            0xA13D7B114AD95191ULL, 0x8B769A37B4A6D552ULL, 0xB1AE096961820EC5ULL, 0xBBFEA71539008CA1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseGConstants = {
    0xDFA710773E9FFE7AULL,
    0x003DF77B09813F99ULL,
    0xB3B36BB1A48C0415ULL,
    0xDFA710773E9FFE7AULL,
    0x003DF77B09813F99ULL,
    0xB3B36BB1A48C0415ULL,
    0x42E98E177BE54885ULL,
    0xA56E19343655F1BBULL,
    0x0C,
    0x47,
    0x47,
    0xDD,
    0xD5,
    0x41,
    0x0A,
    0xA0
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseHSalts = {
    {
        {
            0x61079E381433767DULL, 0x1312D2C8C04B0EACULL, 0x0E704075C56C358CULL, 0xC91A6BF660B8AEECULL, 
            0x83B45E4AC91E978DULL, 0x71E18AB0787F0B42ULL, 0x86595738903C2EA2ULL, 0x4C643B97AFC915CBULL, 
            0xA2DC00C1B8F362D5ULL, 0x2C0199371F1D9DBAULL, 0x82BD1632937118E8ULL, 0x39BB4B9215036398ULL, 
            0x955A63B658535FA0ULL, 0xF78E95A3A516A2B5ULL, 0x1855E1BE453A675DULL, 0x631572A3198B4EFCULL, 
            0xFBC9A055506477D9ULL, 0x5D1AE7F8F79938BDULL, 0xADF2A6400CC51118ULL, 0xC52277465E7A8D2BULL, 
            0xD69C009D9C3D9D21ULL, 0x143BC482744B69D3ULL, 0x264DC88B890F2948ULL, 0x00F713F96400A64DULL, 
            0x99165BF8720ECE5EULL, 0x4C9F6333872E85B8ULL, 0x001ACFD0F02EB2C6ULL, 0x14AC37FAE03C4189ULL, 
            0x97BB9AB5EADB2350ULL, 0xC78987DEFCA148F3ULL, 0x0BBA8E44100FAC24ULL, 0xB4B74C52751C445EULL
        },
        {
            0x39502392E1C9B2CAULL, 0x0017ADD1D6B0807CULL, 0x626FEE4743CD6479ULL, 0x3F95449D7429C075ULL, 
            0x08404ADF6481528CULL, 0x10D2BC7FD9188D68ULL, 0xE0D8B9A0007AAF1FULL, 0xFFC72B731C872FEEULL, 
            0x1923A59AC9D6A896ULL, 0xE1280981B667AC1AULL, 0x07D89DE6F8EC9F21ULL, 0xE7542D6F915AFD9DULL, 
            0xEDE7099B78A5C362ULL, 0x37694AC6266B4D43ULL, 0x3F3B844BE3EFD7B5ULL, 0x2075866DAA88D568ULL, 
            0xDD1A56BF9B85B1E5ULL, 0x315E3407AFA23F15ULL, 0xD08FC88F0540C6D1ULL, 0x4CD3EEDAAE010CB0ULL, 
            0x842E11DC4069DEE9ULL, 0xC235C35473716333ULL, 0x429BA36526FA22FBULL, 0xDC5C7BA892922E98ULL, 
            0x2E69D791A26A46D9ULL, 0x39C35FA75CBE2AE2ULL, 0x035FB433E8A9E2E2ULL, 0xB54764DC0566A730ULL, 
            0x170B480011479213ULL, 0xAF23808791EA36D7ULL, 0x482A177CEAD8A13DULL, 0xA8C1D3B8A101155AULL
        },
        {
            0x7A5EA8323C285831ULL, 0x0F9BF2BB2FAEC83AULL, 0x40D41D115C88144FULL, 0x02B2A77B5F2E1943ULL, 
            0xBC463F24A9AFAA4DULL, 0x19A2A0BCC68E22CCULL, 0xF73E841899E5CA89ULL, 0xD3723D33B730D447ULL, 
            0xB649969F6A358C07ULL, 0x4267BD97E5193E74ULL, 0x6D247141FC4AA27EULL, 0x64D1D21A7990788AULL, 
            0xB0329887C204646CULL, 0x2B79815EED1A6A66ULL, 0x3E2EAF0C00807F95ULL, 0x352D67B8BC861198ULL, 
            0xAA33396F70CD7C54ULL, 0x50780A9D24361A45ULL, 0x48352F7F84E6011BULL, 0x51B4D15A508492F5ULL, 
            0x0F51C0C488A567D9ULL, 0xBB13645612DCB067ULL, 0xDEE505E8A8F830B0ULL, 0xDCA2FEDE5AF2B9DEULL, 
            0xD378E59169795C6FULL, 0x63D37E9AB05A002CULL, 0x4DF31BEF06C6CDB0ULL, 0x4688513C90E803E0ULL, 
            0x5D3BF3440E359960ULL, 0x5CA45202F8E6BD0DULL, 0xBB9C4AEEBFD562D7ULL, 0x3797D49A7D7CED8BULL
        },
        {
            0x64CB45A42B1D29D6ULL, 0x7663BED5B84E71B1ULL, 0x07C71977A0D44B5DULL, 0xFD26D432A3B264C7ULL, 
            0x1309529C8FBAF2ACULL, 0xEEC12B46D69512ECULL, 0x5153060EDF195890ULL, 0x1DF4C088B632BE2AULL, 
            0xC00290B5A3CD735AULL, 0xD49F919DFA578B6AULL, 0x043658C12D712E2BULL, 0x74D5AF6CA950A5BAULL, 
            0xF0C89E7E24DF5191ULL, 0xBDA6EF13250F870CULL, 0xDED09699E9B36253ULL, 0x454BD03D4E69562EULL, 
            0xBF8907D0D6E95978ULL, 0x39D574F726DB997EULL, 0x7687DA6A97D8C5A6ULL, 0x2CBB3F62D9E5B8D2ULL, 
            0xA272A803658ED48FULL, 0x23E3CD0D6E20257AULL, 0x257DE37BBC021043ULL, 0x59BCF7B4D3FB7131ULL, 
            0x353A9A63C2EBB7F8ULL, 0x4A72A601C019A29BULL, 0x478A0D3219CD76B1ULL, 0xE1FCE913EF0954C5ULL, 
            0x5EE5F09A7C27C5A1ULL, 0x2A57A52972D91120ULL, 0x830EE61C88C0CDBAULL, 0xC613497F0BB0AE17ULL
        },
        {
            0x7255818291DE7371ULL, 0x79218B5FCDCB208DULL, 0xE0EC5DE504D297CEULL, 0x6E5CE2107F26B8A8ULL, 
            0x580AFD1E7BE4287FULL, 0x4E2D9DE3D17C66DAULL, 0x8DDB21DECBFC6E23ULL, 0x5A88C1E2ECB45258ULL, 
            0x88B64426EB17C9D0ULL, 0x62B7F159DD3A7CBCULL, 0xD00665E2B1D5BEBFULL, 0x0F89C8EBE4EF983DULL, 
            0x0A9183C404050D8BULL, 0x86E8050A7D2F2B51ULL, 0x61F5FCC8C1CAF015ULL, 0x389464C0EF6435B5ULL, 
            0x5C30A87959D97B5AULL, 0x93B4A91D72E81AADULL, 0xAB49D78F1FC2EF8FULL, 0xC124E75742BCA297ULL, 
            0x15F39A7FB61D8F74ULL, 0x56E4966AE041F4E6ULL, 0xAF5676B9DC549D83ULL, 0x64E9961DCC876E12ULL, 
            0xD88E4888C1AE3608ULL, 0x5DC7A711B1AE2A62ULL, 0x6BB43F63DB88E940ULL, 0x4835D58B0B8EC7FBULL, 
            0xF3C93B4E14FDE97FULL, 0x5A03495A746BD87EULL, 0x4CDA3D752F6E27FCULL, 0x13E3EBDE922653AEULL
        },
        {
            0xA0DCB582094B89DEULL, 0x157DA93E89F3CE70ULL, 0x8EE10FB9BE972070ULL, 0xFDA8038E94697149ULL, 
            0xCA61226BB5122858ULL, 0x39BE52C51291BD59ULL, 0xC0CF38CC6AD5D452ULL, 0x3848A8615E74F7C4ULL, 
            0x39E8B9FD381D5771ULL, 0x5A81055FF2D66FD5ULL, 0x2B0999507465555DULL, 0x58E557BE46422148ULL, 
            0x796E11F3114D0DA1ULL, 0xED4D7AF8FC364A64ULL, 0xA235B25DE6582000ULL, 0x60F96B8E374C239EULL, 
            0x6A32FC372B887E58ULL, 0x44FB98C0E4BA6357ULL, 0xA160482489BF53F8ULL, 0xB689F4D15FC29AB7ULL, 
            0x7326F7A23AEA44C6ULL, 0xEEA9BA56646FC480ULL, 0xFEDA105BB2D2AC09ULL, 0x69B25CE80B6B30C6ULL, 
            0xC2821DA94AE6EC39ULL, 0x059FFF6CFAFF9C5EULL, 0x84F2B1463A4BDFAEULL, 0x0F2DCE6E93A44D54ULL, 
            0x8743E8BF9741EF79ULL, 0x305DDC2D27F22D0EULL, 0xE55D65CC4357FEDDULL, 0xD026298DAF59270BULL
        }
    },
    {
        {
            0xBFE2EEB2A62E996FULL, 0x4A3439755633D397ULL, 0xE62A407850179EB2ULL, 0x18318818132545D0ULL, 
            0x08BE47EBEF9EFFE0ULL, 0xA5547245AE08E7A2ULL, 0x4C8BACF3B3DA0218ULL, 0xF801718FDB689FB4ULL, 
            0x47C3172CF9C0EC6CULL, 0x7E3C4ED4067E621FULL, 0x473CD17B5CC15076ULL, 0x7FCC1FA3F882081CULL, 
            0xF1A7B3214E74095FULL, 0xFCAA598C6A5483D8ULL, 0xE29B674FDAF16224ULL, 0xB6FE4F3B999944C2ULL, 
            0x2149297C0B1300E2ULL, 0x199AAB23F2E41512ULL, 0x52CDA3A3F8C30535ULL, 0xDC1A4F5AF0FCDA9BULL, 
            0x518D772A7EF036BDULL, 0x05BED011365923D2ULL, 0xD7185F3D00225371ULL, 0xF7B5342678B43845ULL, 
            0xE7684AE93CCBD2E8ULL, 0x79904F6A79FDB5C0ULL, 0x59D47BD2D88A018DULL, 0x82A6C324AE160AEBULL, 
            0x760FD578A8555977ULL, 0x7A9DF0FDC1F6E740ULL, 0x3BFC06390C8261BAULL, 0x06B34193A9CC9285ULL
        },
        {
            0x47A5EC7694553D6AULL, 0x1E7A6A646D6E3B7DULL, 0x05A3A4E402BF1FD6ULL, 0xA287FF2021E22389ULL, 
            0xD9D400D2E09985B4ULL, 0x3764A7E5FD3D8F33ULL, 0x08D1D01385842E4BULL, 0x93EFE04B4EA62F5AULL, 
            0x66CF5B4A0E55479AULL, 0xFCF469D20CA700A5ULL, 0x0BEBE7D1296B48FAULL, 0x7EB1325B41063439ULL, 
            0xCB98F588772643E8ULL, 0xAB54D7018936616EULL, 0x9F378DC517812F7CULL, 0xEA1307E64DB8704FULL, 
            0x083633EAD84D2EBBULL, 0xCA5B00A9BE398FB1ULL, 0x403D31BF59B02E3AULL, 0x1C05371ED2E396E1ULL, 
            0x36BA8D045BC9995EULL, 0xAB9D7DF78ABE62B9ULL, 0xAE925E1D4D382F9EULL, 0x2FBF61D4E781B13CULL, 
            0x210E9B3DE13873A6ULL, 0xB3852F72C451DC73ULL, 0xA15CC667133AA569ULL, 0x96DC3E1AC95BCC55ULL, 
            0xD99A29745F9F938AULL, 0xD38426972C9D2CFFULL, 0xF225B8A475DEE669ULL, 0xCA67488259011C4BULL
        },
        {
            0x92C57C0F09698B33ULL, 0x55D4F15642E9C1F4ULL, 0x4EC8EAA8609FBC92ULL, 0x5E1D6499412D0FBEULL, 
            0x5EC4277845E9280FULL, 0x4BE8409441011398ULL, 0x7C1B1073376E6DF9ULL, 0x72CF7B74F48C0423ULL, 
            0x7D87787B47EE2A27ULL, 0xD01278EA369800AEULL, 0x516DB1BA982969F5ULL, 0x7254D8450AE19085ULL, 
            0xF8B5DA101BD0D981ULL, 0xA732FC65D2B8066FULL, 0x82F39C8B87F61DC5ULL, 0xE7789C24A2E94E2FULL, 
            0xA3D2CF9329D472F7ULL, 0x5544551B0F02EB0EULL, 0x80554AC5A0219479ULL, 0x26BE545A3F369124ULL, 
            0x2C97ACC7481A33EEULL, 0xA3D6FF7A801A89D6ULL, 0x9389BC26828ABF57ULL, 0xCC4BB6267E302E35ULL, 
            0xCC375C5595483050ULL, 0x30DB54416128C50EULL, 0x46A996AAFCB9D9D6ULL, 0xDFA1719BB0C79E3CULL, 
            0xB460EF625C803797ULL, 0x7B4530D7E9BC2D6FULL, 0x8CBE22FD1B55D6D0ULL, 0x1E7E64BDB95FC867ULL
        },
        {
            0x6655643D58A56F19ULL, 0xE2A645FB9A43130AULL, 0x701D5C4018D1C14CULL, 0xCD0A39343019DDB7ULL, 
            0xA5216EA5BA3B96EEULL, 0x6955E2B7A8D49CF1ULL, 0xD0B3CD42F26D78F0ULL, 0xF3E2148D65076F83ULL, 
            0xA0CA82A9A032C2BFULL, 0x2FC7BEE7A2D7B064ULL, 0xEDF16C3D9C27E5ACULL, 0x22B782C9B9321506ULL, 
            0x054A04AD9D1E11CAULL, 0x8C8962A7A977E44EULL, 0x47492CFB0E20983DULL, 0x7CEA7C6A8799A436ULL, 
            0x62660800936F2AEAULL, 0xA9DA40D8874C2233ULL, 0x67315E3B815132A1ULL, 0x4FA77D731D5BE482ULL, 
            0x2528ABA36B202940ULL, 0x3BD9334994070011ULL, 0xD8DD2F82BDB4C96EULL, 0xBA8D3B4D21E5B5CBULL, 
            0x4BAD074915D88E18ULL, 0x94DCA7E8E1218879ULL, 0x3D44709379C348E2ULL, 0x64888C99418F5DB1ULL, 
            0xAD8B3874B0C1C207ULL, 0xB19E7C70E35BE465ULL, 0x4FA13D9DAD6444AAULL, 0xA3131D72FC84567AULL
        },
        {
            0x614BA91DECDABAB7ULL, 0xC23BF9EB1EF83228ULL, 0x6FC1EEB3E517F3C0ULL, 0x1691029B129344F3ULL, 
            0x89599B70A60B15B3ULL, 0x77834B652164821CULL, 0xCF78E047C2C8B879ULL, 0x197E3E76C12F54F4ULL, 
            0x55477045BEC3F1E0ULL, 0xC42C18018368CAD8ULL, 0xB77082FC112C66D1ULL, 0xB49F525FA18CBCF6ULL, 
            0xB0C5D2B2724EED98ULL, 0x3107AE8B19AD94B9ULL, 0x861F7B293C040ADBULL, 0xD0DB73FEBBBFA0A3ULL, 
            0x30F7BD92A306136BULL, 0xFA841B839D5B07C5ULL, 0x6FFDB60E20A8E88CULL, 0x259F244BF0713573ULL, 
            0x2B4C186E265A0B89ULL, 0x1C298CA49269250DULL, 0x6E3D848B55BB887EULL, 0xCA85331FFD88E0DBULL, 
            0x545E49C20F6EA71CULL, 0x9182F1CFEF3C279BULL, 0x0509A4A85630118DULL, 0x376ABA0DDB7AAC2BULL, 
            0xB417B9D31825FBF6ULL, 0x6F7C5D78C9EB847DULL, 0x497F23089AE1F5EFULL, 0xC52903C6A1514E20ULL
        },
        {
            0x790CB0B3064D8B86ULL, 0x02D554256D939E91ULL, 0x47E22857EA0C42F6ULL, 0x2BF327810F63FAC4ULL, 
            0x54C69601B28A8EFBULL, 0x014F8B2670F4A749ULL, 0x394EE4AA083ABBD6ULL, 0x095C9E851D53479DULL, 
            0x70B8589D90CE75B3ULL, 0x48E0F0D977D295F7ULL, 0x72496422E959C5EEULL, 0x6F5EE2E9505841DFULL, 
            0xAC0B416142620CA6ULL, 0x58BF553B550A9877ULL, 0x55A1A7781DE46B10ULL, 0xA5A5DDA1EF783EDDULL, 
            0xC1C421DC91B58BBEULL, 0x4ABA81070AF979BBULL, 0x34E196990DFE6B51ULL, 0xE732A4471455E65AULL, 
            0x58D15A2F075D3849ULL, 0x276EA4E489E4AD2CULL, 0x06728EAB5B3519C0ULL, 0xAB9177CC47E03731ULL, 
            0x20C4878A331CBE05ULL, 0x4F93CB3A813F2BFAULL, 0xF2A5D546C8F67170ULL, 0x22ADA5951E07BD62ULL, 
            0x608CD7CB1A32925AULL, 0xE083BACD2DF9ED88ULL, 0x01C468222DF0679DULL, 0x65D437859837D15CULL
        }
    },
    {
        {
            0x988DFEE67F3CEAC6ULL, 0x9B17D7B2B1B7625EULL, 0x5B694A53A2FDDAEAULL, 0x1FA64666531C6408ULL, 
            0xCBAF77119762833FULL, 0xE192B3B0D51F9AC5ULL, 0x514590CDF12390F5ULL, 0xED5057547CD9107DULL, 
            0x3896323146C0391BULL, 0xB5B7B5A1CB75E25FULL, 0xF5E40854E02C1F68ULL, 0x6C0AA9AD03DC2B22ULL, 
            0xB8F74F5D5505BA1EULL, 0x17C62509E6E91CEEULL, 0x45A58D3EA33F599FULL, 0x05B607E998E6FAF7ULL, 
            0x9ECF9C8DBCD3E5A5ULL, 0x67A42E7E5C439A54ULL, 0x3A097596C8C1949EULL, 0xD96AA4D72F9189CAULL, 
            0x21A957F81B97374BULL, 0x242F6916B2E0890DULL, 0xB2BD99F3E3C6B51CULL, 0x4B9FC33A2FBC544EULL, 
            0x57258DA997605009ULL, 0x120210D423427ACFULL, 0x17A1615373CA8191ULL, 0x1C3141556031AF0EULL, 
            0x17CC9756D0AD2A1FULL, 0xDE28EAAF478DA583ULL, 0x282111F2ECB49643ULL, 0xD9BE7FED82A060FAULL
        },
        {
            0xA756CCFD98CDD593ULL, 0x598DA708DFEAFD40ULL, 0x5C89DBADA830A477ULL, 0x37D1B89CB8E5E357ULL, 
            0x3320C813B657FA5CULL, 0x03956829C4C330ABULL, 0x13D348DEEA3FC135ULL, 0x0236F0D259E4EB0CULL, 
            0x92ADB00C62A6EC6AULL, 0x2468923683A8BEFBULL, 0x69F0291ABB3BF6C3ULL, 0x97907413E7DDF09BULL, 
            0x8CC03C62777FAA0FULL, 0x5935FDAC88DEDEA5ULL, 0x70F2A721DF938CBDULL, 0x6A9F70874F231F0CULL, 
            0xC214EB0C5A557E1BULL, 0x81D67E2437D1002AULL, 0xB3220CD6BF7777B9ULL, 0xFB7547C70245A1E1ULL, 
            0x6C6CE766C08C9A27ULL, 0x440C06551CADDD17ULL, 0x0DE3E6A99A5F61D5ULL, 0x001C2607FA4994DFULL, 
            0x8E0E5C8FC0C0AFF3ULL, 0x0A00D49539F80983ULL, 0x44C23999E7A735EBULL, 0x3EABBE17A058FD9AULL, 
            0x1D05570C078740D8ULL, 0x48419668D7E9399FULL, 0xF11B753349A2F8F8ULL, 0xDF1DBDEFD82C292FULL
        },
        {
            0x21FE9B9FCF98CECBULL, 0xF5660610A6383623ULL, 0xD24B16B52E07926FULL, 0x075D0B383625A479ULL, 
            0x0A66FCB29008C118ULL, 0xEF11CAC515783192ULL, 0x5F359AE4100821F4ULL, 0x0BE5DC0630F0AB11ULL, 
            0xC9672DBEBC74863EULL, 0x76433970A9C31CF0ULL, 0xDCDC28F629E3FA4EULL, 0x37B59251A9F340CCULL, 
            0xBE531ADB11117B59ULL, 0x2A02A2E5072946D9ULL, 0x8AA1B2CD609C902BULL, 0x723839145B2F5305ULL, 
            0x6B4BF03D1045DFAEULL, 0x78D5C598A6A5C2F1ULL, 0x54D082BD474422C2ULL, 0xB3A6F858B54AC19DULL, 
            0x507DB7CD6F5A9402ULL, 0x3210FB0A3D193589ULL, 0x7E899921B5A91E68ULL, 0x01859BE42AA8F83CULL, 
            0x0964040BAF9FB339ULL, 0x62B96582520DA4DCULL, 0xC717862A5B131B28ULL, 0xED73B44331269851ULL, 
            0x525D408A362F97F7ULL, 0xCE2E4686BD285DD4ULL, 0xD6332F5ABD457DD6ULL, 0x3FDEF57751729073ULL
        },
        {
            0x4517D2E1C2B8FFAFULL, 0xBA205CD4884D640EULL, 0xFDA5A78CF1AEE4FEULL, 0x804421C0CDA17438ULL, 
            0x6FF8F431B77CB8A6ULL, 0xB5BC84FA67FA25DFULL, 0x74E22978A04B86E3ULL, 0x4E029D2637194CB8ULL, 
            0xE322E6677225CFFFULL, 0x2E93E286E38658DAULL, 0xF16D0B4A1F4E4996ULL, 0x27B417D4030FAA45ULL, 
            0x9261DE874F85FF37ULL, 0x5261A1A6F40C71D9ULL, 0x5BF3BFB1E8AE2D01ULL, 0x0EA7C1EE9A8F6B92ULL, 
            0x578176B47F6E91C9ULL, 0xFEC604B887904994ULL, 0x76C869EE7F6BA3F8ULL, 0xEAD3E1F79FE8DC6BULL, 
            0x1988E712EBEB5BEBULL, 0x404C7806EB0EAAB3ULL, 0x2451067CCF7447AFULL, 0x7B9AB8BD84BA483CULL, 
            0x7E272034DEA7070BULL, 0xE3A8337057843863ULL, 0x6BDD3F0AA344278BULL, 0xC0FFC57CBB12E903ULL, 
            0x7D8FF0EF4FC9698DULL, 0x88700008F16A9D31ULL, 0xEFA4932A0A1F8E17ULL, 0xA784295A9D945BC6ULL
        },
        {
            0x159125D211648ED5ULL, 0x1EBC7F51E69F1AA3ULL, 0xA9EF3AED03E6B61FULL, 0x2006B70648E33801ULL, 
            0xCD02EF2FF0ED4BB3ULL, 0x5D4F53D5B3DFDC2AULL, 0xAEEF53D05DFE6248ULL, 0x49FA639C5A90437CULL, 
            0x096D6280037A5BF3ULL, 0x5E3E00B1FEECAAAEULL, 0x5F042025D32A26F5ULL, 0x649344AEFFE095F6ULL, 
            0xF18C743A2D44A569ULL, 0x502D1A686A681B17ULL, 0x4DB192B14AD1C592ULL, 0xAD586965904035C8ULL, 
            0xA5AFDDFD1611510CULL, 0x9DE735057E10E124ULL, 0x8EC208BAF150B48FULL, 0x3473BC9F6818A467ULL, 
            0x7708299E888E8DCDULL, 0x6FA3AB1215FC19BCULL, 0x8E86A612D93FE666ULL, 0x0140042F3820225BULL, 
            0x9D4932FD2BD0555BULL, 0xCEF3E7B93B7B3548ULL, 0x0759E779F3F1B310ULL, 0xF890A85498107304ULL, 
            0x3E235F73B1C76156ULL, 0xC189570AA82EDC09ULL, 0x7B9D23CB696BF732ULL, 0x42C74F5CC06EDFD7ULL
        },
        {
            0xC0455458F4119041ULL, 0xC0F31167E2EEFFBAULL, 0xF8E1D2D7E4AB3B07ULL, 0x98E00A61E3A0781EULL, 
            0x3C43032CC4A9BF71ULL, 0xB67E8548A351BCA5ULL, 0x409B8606163DC823ULL, 0xDFA005961B872B96ULL, 
            0x545C7E954A6F6950ULL, 0x0C54F02D55FFF85BULL, 0xB551C6C054BFE47FULL, 0xE089EE20CEAAEBDDULL, 
            0xEDB603C194C25421ULL, 0x027D0533629545E8ULL, 0x4A1E18B5936D2E79ULL, 0xB01DEE24FB8B2CAAULL, 
            0xC93932C71CAF7A1FULL, 0x8A2381A5A385995EULL, 0xB3AB61E19D3669DBULL, 0xB3388C24C3BDFE9DULL, 
            0xD672AC12C6DB2C8FULL, 0x406547B8DB978475ULL, 0xC93A48959549AF30ULL, 0x02835CC3DD2B0F99ULL, 
            0x80397A195EAA414BULL, 0x7961C3688A3F3D30ULL, 0xE09FDD214B812700ULL, 0xD3547AEDC2B338A6ULL, 
            0xF68A6E7839722B50ULL, 0x876A6C4A8C6DB217ULL, 0xA6EA5E1F51551012ULL, 0x928E4FEB03CF0E32ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseHConstants = {
    0xED95CBF8D02E5E0BULL,
    0xF7CF88CBFEBA7C41ULL,
    0xA640704E84335990ULL,
    0xED95CBF8D02E5E0BULL,
    0xF7CF88CBFEBA7C41ULL,
    0xA640704E84335990ULL,
    0x2EC81B9EA526E684ULL,
    0xEACDD6ED440D2C9AULL,
    0xE6,
    0x9A,
    0x92,
    0x57,
    0x44,
    0xB7,
    0x66,
    0x46
};

