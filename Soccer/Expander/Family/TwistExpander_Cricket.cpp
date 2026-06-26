#include "TwistExpander_Cricket.hpp"
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

TwistExpander_Cricket::TwistExpander_Cricket()
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

void TwistExpander_Cricket::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 14834715879172716631U;
        aCarry = 11034798943697091693U;
        aWandererA = 10410710364787830392U;
        aWandererB = 13578276220831072032U;
        aWandererC = 13248809250569399101U;
        aWandererD = 11971189423768156925U;
        aWandererE = 18029429653541339265U;
        aWandererF = 11471036055143981682U;
        aWandererG = 13052565549246871631U;
        aWandererH = 13035342066909519396U;
        aWandererI = 10610481867576662779U;
        aWandererJ = 12502019074993662025U;
        aWandererK = 16078576048022202252U;
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
    TwistExpander_Cricket_Arx aArx;
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
    TwistExpander_Cricket_Arx aKDF_A_BArx;
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
    TwistExpander_Cricket_Arx aKDF_A_CArx;
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
    TwistExpander_Cricket_Arx aKDF_A_DArx;
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

void TwistExpander_Cricket::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 16333403018704039968U;
        aCarry = 9873082387346990427U;
        aWandererA = 9956011000740402586U;
        aWandererB = 17758805061960698595U;
        aWandererC = 12233934036021816570U;
        aWandererD = 9411032822089083265U;
        aWandererE = 11170276683095621375U;
        aWandererF = 15963626696355785618U;
        aWandererG = 16618480937797761223U;
        aWandererH = 9316345593535824428U;
        aWandererI = 10450269058750401467U;
        aWandererJ = 14424781884747653657U;
        aWandererK = 12811257462700304136U;
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
    TwistExpander_Cricket_Arx aKDF_B_AArx;
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
    TwistExpander_Cricket_Arx aKDF_B_BArx;
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
    TwistExpander_Cricket_Arx aKDF_B_CArx;
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

void TwistExpander_Cricket::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFA0AD3CF78305E3AULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xD56B14E758F8997EULL;

    std::uint64_t aWandererA = 0xEC0BF21D5399A59FULL;
    std::uint64_t aWandererB = 0x8519821F5FBA8071ULL;
    std::uint64_t aWandererC = 0xF57B413C433688F1ULL;
    std::uint64_t aWandererD = 0xD877194CEFD07E28ULL;
    std::uint64_t aWandererE = 0xA0F11D0125D7C336ULL;
    std::uint64_t aWandererF = 0xB5557DF6EEE544FAULL;
    std::uint64_t aWandererG = 0xAAD5895ECCA08F75ULL;
    std::uint64_t aWandererH = 0xBEF1926C0B912677ULL;
    std::uint64_t aWandererI = 0xA08FBADA014341C6ULL;
    std::uint64_t aWandererJ = 0xBC56B5F45705BF29ULL;
    std::uint64_t aWandererK = 0xAB3926C51F4955ABULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneE);
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
    TwistExpander_Cricket_Arx aSeed_AArx;
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
    TwistExpander_Cricket_Arx aSeed_BArx;
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
    TwistExpander_Cricket_Arx aSeed_CArx;
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
    TwistExpander_Cricket_Arx aSeed_DArx;
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
    TwistExpander_Cricket_Arx aSeed_EArx;
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
    TwistExpander_Cricket_Arx aSeed_FArx;
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
    TwistExpander_Cricket_Arx aSeed_GArx;
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
    TwistExpander_Cricket_Arx aGrow_AArx;
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
    TwistExpander_Cricket_Arx aGrow_BArx;
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

void TwistExpander_Cricket::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Cricket::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 11582881515881501807U;
        aCarry = 11150470208892553556U;
        aWandererA = 14327597523942580285U;
        aWandererB = 9889943623572119187U;
        aWandererC = 12621652145812567212U;
        aWandererD = 10835841220552184286U;
        aWandererE = 13769559502730569815U;
        aWandererF = 12142964736504526491U;
        aWandererG = 17710972807506908256U;
        aWandererH = 10669267939667194976U;
        aWandererI = 16702467303801472826U;
        aWandererJ = 10978178534305356767U;
        aWandererK = 10018914092165819616U;
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
    TwistExpander_Cricket_Arx aTwist_AArx;
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
    TwistExpander_Cricket_Arx aTwist_BArx;
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
    TwistExpander_Cricket_Arx aTwist_CArx;
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
    TwistExpander_Cricket_Arx aTwist_DArx;
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
        TwistExpander_Cricket_Arx aGrow_AArx;
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
        TwistExpander_Cricket_Arx aGrow_BArx;
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

void TwistExpander_Cricket::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 0, 1 with offsets 5126U, 6992U, 1771U, 540U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5126U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6992U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1771U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 540U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 1, 2 with offsets 7250U, 1081U, 1405U, 4344U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7250U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1081U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1405U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4344U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 2, 3 with offsets 6792U, 8073U, 5214U, 1254U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6792U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8073U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5214U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1254U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 3, 0 with offsets 2506U, 4656U, 1868U, 250U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2506U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4656U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1868U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 250U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 3, 0 with offsets 986U, 2036U, 733U, 743U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 986U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2036U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 733U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 743U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 2, 0, 1 with offsets 439U, 1007U, 1416U, 285U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 439U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1007U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1416U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 1, 2, 0 with offsets 389U, 1829U, 920U, 1961U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 389U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1829U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 920U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1961U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 1, 2, 0 with offsets 2008U, 543U, 1220U, 1332U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2008U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1220U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1332U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1437U, 312U, 1216U, 1329U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1437U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 312U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1216U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1329U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Cricket::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 2, 0 with offsets 8090U, 2947U, 6818U, 7544U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8090U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2947U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6818U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7544U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 0, 3 with offsets 7626U, 533U, 6187U, 4832U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7626U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 533U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6187U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4832U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 1, 2 with offsets 6691U, 7086U, 1910U, 4303U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6691U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7086U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1910U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4303U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 1 with offsets 3393U, 2029U, 6680U, 1500U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3393U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2029U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6680U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1500U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4408U, 3343U, 2520U, 2364U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4408U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 3343U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2520U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2364U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1955U, 1074U, 1888U, 777U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1955U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1074U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1888U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 777U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1111U, 1527U, 259U, 400U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1111U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1527U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 259U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 400U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 982U, 69U, 1358U, 1474U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 982U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 69U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1358U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1474U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 557U, 862U, 1942U, 230U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 557U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 862U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1942U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 230U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 3, 1 [0..<W_KEY]
        // offsets: 1347U, 2040U, 76U, 768U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1347U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2040U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 76U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 768U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseASalts = {
    {
        {
            0x8B4E869B5676DDC6ULL, 0xD4F709842E352D02ULL, 0x21AFF16D163BF41AULL, 0x7D8F8972185437F8ULL, 
            0x0FBB96653D783165ULL, 0x2675B89D4C0211EDULL, 0x385DCC5CC52528C7ULL, 0xC3894CF511BF173BULL, 
            0x687D7EA3F0CADD42ULL, 0x4B19542337A7D227ULL, 0x08CE5CEC6B56169EULL, 0x2FAB986391EC60EFULL, 
            0xD798AD6017EE1500ULL, 0xF61ECD56F4E9111FULL, 0x8E1F6D623581499EULL, 0x92FFDD21AD3A2A21ULL, 
            0x1BB1D780DB478AE3ULL, 0x10A37EE5BD3485FBULL, 0x4785ED8725667BE7ULL, 0x8E3935C036FCBD89ULL, 
            0x3FB7006DC19AFA9AULL, 0xE80A315715513BA4ULL, 0x8AF81586E8066E97ULL, 0x08A4C60206FCFB14ULL, 
            0xDD1CD95566406F3FULL, 0xBA1B1019BF936049ULL, 0x4AD18CDDB886364DULL, 0xFD9E8E2F2845E758ULL, 
            0xA38E1B1ECA45B2D7ULL, 0xF917238CC8598683ULL, 0x3CC6FB4F7AECE67AULL, 0x8B8DEA65C15F242BULL
        },
        {
            0x1F6ACE09713AF59FULL, 0xFF37F1D5937CFFF9ULL, 0xDDB4F1D7E001E315ULL, 0x5D1681A8D159E90DULL, 
            0x60513A184AE405BCULL, 0xE690B54B053FE2F8ULL, 0x6F67D075E6883492ULL, 0x4D9790E3CBEE11CFULL, 
            0x976315E1CE44CCBBULL, 0x9962B82ACE357287ULL, 0x432294AE1850AD94ULL, 0x039EFFA496791F3DULL, 
            0x8FEDA5D6E5DEA44EULL, 0x99C34E06884E367DULL, 0xDA7CCAB7BB722BBCULL, 0x92D17A8D07CCE85DULL, 
            0x07E8D1E7D48ABFF1ULL, 0x9EA0BC8C7855F550ULL, 0x068C406FC6E6F2D7ULL, 0x3BAF681A87043E16ULL, 
            0xC5928FC19CD64331ULL, 0xD32E7C25D3E0FB36ULL, 0xC92343BB1F301093ULL, 0x38AD13A41837CB9DULL, 
            0x938A6B1797C333D4ULL, 0x065DD008AB6F5404ULL, 0x296B008FDE307025ULL, 0xA6480A3A9DFE42A2ULL, 
            0x2FF5A243E51682F3ULL, 0xF89F0643621D3EC0ULL, 0x5FEB9AFAAE2C861CULL, 0xB8971C9BFEF749C2ULL
        },
        {
            0x5AABEA790DF48802ULL, 0x936584A52533795EULL, 0x38D3D12DC843A48DULL, 0xD5EBE7F224725131ULL, 
            0xC7A3FDB04D44384AULL, 0x60AC3BD4BD56806BULL, 0x2EC2134A6D6BAD2DULL, 0xA7BC4DF53C0CBCCEULL, 
            0x61FD5C859A4C8B82ULL, 0xFFB0D256DF912E98ULL, 0x8B9DDFC7AD528D91ULL, 0xFEC0A1509BDE9386ULL, 
            0xC7B9EDFECBB50C80ULL, 0x79FCB1E3DF07BFA2ULL, 0xE96BD16A546A396DULL, 0xD591A090CEC404A5ULL, 
            0x4E29A71AC5A2A3F4ULL, 0x35C0C07E3F084D31ULL, 0xC5DB82A67E8D7C7EULL, 0x90F7D564AC28E7EFULL, 
            0x860F35D1A60DF06FULL, 0xD803B6A2DA29F4A8ULL, 0xCB406749A967407BULL, 0x1821AFEAAA1263E6ULL, 
            0xD40512265700AF26ULL, 0x65E37D9ED1A41B57ULL, 0x5B53752CCAF7B88CULL, 0xB3F4BD3DC2AD7E09ULL, 
            0xADC44503B670E6A6ULL, 0x1E8436F4C334B2FAULL, 0xC5FD90686B479B28ULL, 0xAD728F9061130035ULL
        },
        {
            0x881F036DB4061CA7ULL, 0xA6A266300E1FF31EULL, 0xA60914B09A73DBB0ULL, 0x2B04B9B53802F1DAULL, 
            0x8531025E9485C136ULL, 0x08327381953706BDULL, 0xD4E768613FFE5910ULL, 0xD6D50EEE930BEA63ULL, 
            0x1159820ADC53B9A5ULL, 0x54003B316405F409ULL, 0x8ED22877E9EA7AB4ULL, 0x679794D954A97048ULL, 
            0xE0309DC0FA9821EDULL, 0x4E51FD023A59F4D4ULL, 0xB2C82A9E5B7BB2D7ULL, 0xF4B367E43A960D90ULL, 
            0xFDFD7DA7107AF281ULL, 0x137DB2DF0EA1D760ULL, 0x2BB96D9751272300ULL, 0x0F26745464EB4D4EULL, 
            0xC3FFB6E205E7E816ULL, 0xFA116874C11C2F06ULL, 0xEEAD17EC8CD38ABCULL, 0x7A6D0E6FC6E75D10ULL, 
            0xD28151876C6FE44CULL, 0xF06D5269B190B03CULL, 0x7C6494FFF743916EULL, 0x04C041CCB2AB6916ULL, 
            0x0B1569414DE9FCE3ULL, 0xDCCAE214A407542FULL, 0x7606FF0AB7A4FF30ULL, 0xC82722B6979BF413ULL
        },
        {
            0xEFF8477E2993E202ULL, 0x997EC13EFAFEA2F1ULL, 0xA755FFC7CFC20008ULL, 0xD91D55B8FE48006CULL, 
            0xC7C0A6E6B5312FF9ULL, 0x07B18726D9D0D305ULL, 0xBACDBC5AA03BDE8DULL, 0xC2A811010E29DAEEULL, 
            0x9556A4D52B33251CULL, 0x2D0F6BACDA9A0751ULL, 0xB907F662A8A5CDA8ULL, 0x69A254508EBBBC6AULL, 
            0x8B9FC1A21E41E75DULL, 0x06AA20BA6D6BB6D5ULL, 0x43F50E933591E702ULL, 0xBDDEDE4BFD7F48A2ULL, 
            0x5F22679721B4D693ULL, 0xC3723F1061F4DB89ULL, 0xBF47198F8E250795ULL, 0x57D6358ABAA5E0C2ULL, 
            0xBC3CC0414A156A7FULL, 0xB14BD97FC551F38AULL, 0xDAF602398DBBB9B6ULL, 0x5D8B9F6DD6042E8CULL, 
            0x6D8E3C4FD9ED9D2AULL, 0x371E595EDE258306ULL, 0x79DAEDAA23CAF372ULL, 0x6BAA32A3D627EDA5ULL, 
            0x717794FF8CCB1C55ULL, 0xD33BCE42B639E515ULL, 0x7AA908A507F2E936ULL, 0xDC825744CA90F93CULL
        },
        {
            0xD791B0779901D02FULL, 0xDBA98437274734BBULL, 0x62CFA469B1452D20ULL, 0x637D7A022A04956EULL, 
            0x8B91C0E81D7E927EULL, 0x9DACD7E6F84014A4ULL, 0x2F891177A85A4342ULL, 0xAF7768A56E8B3954ULL, 
            0xA98D07AF73E7A049ULL, 0x264267554FFCE4F7ULL, 0xDF0BD82C8BDD220FULL, 0x546C3F3EBE417E2BULL, 
            0xCC9D778BF7BD22C9ULL, 0x859692864FFF9DE8ULL, 0x955E33A1C04F59CFULL, 0xB91CC809FD460597ULL, 
            0x5FF029FFFC42DC5FULL, 0xA8156D0A8528955DULL, 0x7ADE8F0CBEC91A9EULL, 0x0779CDE862AF1EB3ULL, 
            0x66C9BC20C1D3ACFFULL, 0x3856FBA80F21AFDFULL, 0xCE93174EA27467DEULL, 0xB0B4775C01883084ULL, 
            0x4B59DA8AC693457AULL, 0x50646513BF29C2D3ULL, 0x96D125C1B0DF4ADAULL, 0x1624E135F0C0B334ULL, 
            0x3AC6E688C160D32EULL, 0x59F0CEF4202EE7D4ULL, 0xA2564EBE7E308B5AULL, 0xF5D4F08F9055AB2BULL
        }
    },
    {
        {
            0x685448E90ED732D6ULL, 0xEDBE2153745D4D1AULL, 0xADB86038B9035068ULL, 0x4D1D93257DE79063ULL, 
            0xFD7BB8FB73B6A684ULL, 0x6B58153404BA1909ULL, 0xE960F54A79AE6AA8ULL, 0x6294DFB150FC5E53ULL, 
            0x5C9C6085380D2767ULL, 0xA97A0F43E2F670F9ULL, 0x53CD0E0930A44D4CULL, 0x30986F898DE8354EULL, 
            0xC3E837D11AD19640ULL, 0x292ACF8B14A72465ULL, 0xC40D6C263B725F2EULL, 0x9B65B8A26464FEE2ULL, 
            0xC46CA0862B3D3B26ULL, 0x4AD2E1CF222A9885ULL, 0x37CF57E623B3E109ULL, 0x14022CF2AA177815ULL, 
            0x3A85E2CB0E7356CBULL, 0xEDDF476CF395FDA6ULL, 0x72A6F401208C4612ULL, 0xCCDB947D41D0EBD6ULL, 
            0xD09C907C1355A6F8ULL, 0x00BB8AB7CB128BB0ULL, 0x63F5B41968AC9314ULL, 0xBEE657C22A4BFC47ULL, 
            0x66217F0DEFC060FBULL, 0x13ECD4A22A72E599ULL, 0x5FD568139A63EA10ULL, 0x3C16B40C10D8C012ULL
        },
        {
            0xBF909181C6997884ULL, 0x4652E23BC7DF91F4ULL, 0x8F64108AC9B27687ULL, 0xCDD42C92B9759269ULL, 
            0x7104A20999EEE64DULL, 0x1E996FBF9A2E74D7ULL, 0x7D04E80599EBBB1FULL, 0x78B9AF1F617259F8ULL, 
            0x4B348E277EAD4392ULL, 0x527414E1C9818A26ULL, 0x2000F342172914B3ULL, 0x197B10C2BFB5970CULL, 
            0xFDF906784D0D96ABULL, 0xFAD1799DACFE6579ULL, 0x39A8AC4797718746ULL, 0x02EC3C724E7ED4EDULL, 
            0x2307AA140AF7AFFCULL, 0x1A7FA183C225F2D0ULL, 0x8B0070D86EDE0CC7ULL, 0x4C6FE18E519B52C1ULL, 
            0x8487AB4864D2963CULL, 0xD7CB5873D7DA46E3ULL, 0x27AA6B03C56A8F35ULL, 0x697108974B53B6E3ULL, 
            0xC556B5A7E691BE1DULL, 0xAB80FAAAEA5E8208ULL, 0x7F010E0A33FA31C2ULL, 0xE4883BCE95D69117ULL, 
            0x46EF16205F363237ULL, 0x9B1C13C211706D40ULL, 0xCAD65D6D33A501F1ULL, 0x5D32C589AA2D9D2BULL
        },
        {
            0xA773555237B1D7F8ULL, 0xEC7FE7661F443466ULL, 0xD44ADC0766875296ULL, 0x4E0506F592827D81ULL, 
            0x30FC2F22827D2573ULL, 0x0A3E733EDA8D3547ULL, 0xA7AE2F80E29F7569ULL, 0x0FBAA06CF7326455ULL, 
            0x503885AA398D2DA7ULL, 0xF90716800D51570DULL, 0xA3B13434567AC5EEULL, 0xF61F9CC940E1DF0DULL, 
            0x8D9A2D42D9D8C991ULL, 0xBAA4D2AD86416005ULL, 0x4E1D9874F0F00D5FULL, 0x7F5C48FDA8F03232ULL, 
            0xB19D69D9F9606C6FULL, 0x49C433A8F9CB1FDFULL, 0xCC3507039A8FEEEBULL, 0xD5ACF397F2DFDD53ULL, 
            0x10A7A51449F3C6A1ULL, 0x7F649AE21701FDD2ULL, 0xE3BF8D662925AFB3ULL, 0x5920D28D5E7A2AE1ULL, 
            0x42E41823A0D70757ULL, 0x436C384BC190BD9DULL, 0xA2D768BCD4EA2D02ULL, 0x0E5DD3DE130CC069ULL, 
            0x14772CF666824564ULL, 0x8CF578E2903812BAULL, 0x5420A96C75DFE7E4ULL, 0x517CBCEDDAE3F5BCULL
        },
        {
            0xB287FAC49A700625ULL, 0x25E584ACB0F3C05AULL, 0xBC5210ED24D9432DULL, 0x7E012C9599403000ULL, 
            0xB10F716D8B9B3482ULL, 0x4BD687B2EB8F1246ULL, 0x4ED53CB33940AB50ULL, 0x89DFA942F47CBB85ULL, 
            0x9486C23423DF2E19ULL, 0x4F26728140CB6841ULL, 0xB6FBA8FFE54B344DULL, 0xF57ECFEFCA2592D2ULL, 
            0xCCFFDF3CF5A4CB17ULL, 0x6285C5D21D171BADULL, 0x1856C8C4CF4D97CFULL, 0x5BDBED6BF621D410ULL, 
            0x7D1933AAA6FC5F3DULL, 0x4438836CD811F28CULL, 0x646FC7E8BBCA6833ULL, 0x13FE7A9C0AB790C8ULL, 
            0x4B04BAF22C52336CULL, 0x21A7FD94263A5C0EULL, 0x28EF0D82932D9EE0ULL, 0xB80C857999C8DCDBULL, 
            0xBC1890763A441590ULL, 0x9B5DBA62D85264FFULL, 0x75FDADFDA3F0CC82ULL, 0xB5B9E64D16FCA2B9ULL, 
            0xD4D223653D045184ULL, 0x5515800031CACE93ULL, 0x4422D10FD922906BULL, 0xF1EDAB57A17DE67EULL
        },
        {
            0x2930447C938EB2DFULL, 0x17810724543F8CA4ULL, 0xC0185BC1C67CF310ULL, 0xF26290C0482D1C1CULL, 
            0x3D67C07D500C4888ULL, 0xE0A554F6687541BAULL, 0xA1ECCFBF8021A70DULL, 0x43E19C46F847FF04ULL, 
            0xF3B8E53319301C1AULL, 0x1F5B8F300A23EC9EULL, 0x835095CBC20FB042ULL, 0x256249AE9A22DAE5ULL, 
            0x5F62259E4184DCCDULL, 0xB6B71BDA9FC22F68ULL, 0xD5CDF172D9AB73A3ULL, 0x8E7E1C85A124ACA0ULL, 
            0x0A5B44AF331E386EULL, 0xFF274B3684D2C5B7ULL, 0xE35313C003228F77ULL, 0x4229B06E286D2708ULL, 
            0xA88B4EF869644001ULL, 0xC0187D7271F56844ULL, 0x94573F1AC1D75AA9ULL, 0xC8A7543C31A7F81BULL, 
            0x03887591C1AD77BCULL, 0x589E3D97FC99AD21ULL, 0xF914E1924AF32504ULL, 0x9DFD50FD10FC88FCULL, 
            0x4752321EA7C93231ULL, 0xCF2A4E95906020A6ULL, 0x1889D2598FD6C197ULL, 0x822919298F4AEC79ULL
        },
        {
            0x2D68905529DFCE9BULL, 0xAAD5B43DBD8C00B8ULL, 0xB2AA4A6621BFD14BULL, 0x06E7A20183E2DAF4ULL, 
            0xDEFEDCC0F0929EA7ULL, 0x8A18927825017EB8ULL, 0x10A32F07AEACFF1CULL, 0xA1D2BB2D20FB6CC3ULL, 
            0x2533F16241CF96B1ULL, 0x8D6AF7651AFB33DCULL, 0x48B4905E296C5E22ULL, 0x8A868285D85B0F9BULL, 
            0x48666DB3D9E98221ULL, 0xABB6AC2F6D448BAFULL, 0x8207DE4CA911EAA4ULL, 0x1FCCC90FF16223C3ULL, 
            0x1DF480182F586B20ULL, 0x1BCFD896DFC3259CULL, 0xF571A3C24F346280ULL, 0x645E42DE22B0EECFULL, 
            0xF46BFFCA60F26CA8ULL, 0x8077D8284B1FC679ULL, 0x104FC0847BBAC731ULL, 0x6ABF07D45AA79FD2ULL, 
            0xEA1A187A357C2E87ULL, 0xFFE1EF3185CCCE11ULL, 0x7E9FD268D3B675DBULL, 0x921EFA5677399D0CULL, 
            0xD9D9BEF41606CB7FULL, 0x0D9591F99C9674A0ULL, 0x29BD2983E21592AEULL, 0x6F15D5CC754B2D9FULL
        }
    },
    {
        {
            0x43BA21E37F591C04ULL, 0x3F184B4A9674DC44ULL, 0xBF3A78AA9B408276ULL, 0x4E841BCD97AEC050ULL, 
            0xE48E626766E569F5ULL, 0x83B7FD4151B33425ULL, 0xA766964DBCD2AA94ULL, 0x6F14A55427DE2B95ULL, 
            0xD26AF890497F75CDULL, 0xBF823AE2F55ED8A0ULL, 0xD3A3AD58DF90AE5EULL, 0x8FFF3C263FFB55D1ULL, 
            0x09D5AB227FC25544ULL, 0x382457B9B6021A6EULL, 0xCA72EACD85A8DFD0ULL, 0x5DFD444EC381DBA6ULL, 
            0x85BE83EAEB421164ULL, 0xA8D5B2BB00682C0CULL, 0x1362BCD0C3575B75ULL, 0x52E17A3BBC875921ULL, 
            0x79B4BE222E5A1087ULL, 0x085A01A07A168BEBULL, 0x795B000EC2E39850ULL, 0xAA183C2777E5C7FFULL, 
            0x71DC3BE563055248ULL, 0x29510C15AF5E83A1ULL, 0xE9E9C9110A4ED67BULL, 0x1AA296C9D7D838CDULL, 
            0xD732857878DCF594ULL, 0x2E69C91AB4040C51ULL, 0xD9FC523DC2A62078ULL, 0x5F2698D41DAA7EF7ULL
        },
        {
            0x2BF52BB3305BC0D6ULL, 0x14906E3CB2BBEC08ULL, 0x9A528A635838FB61ULL, 0xDADD3573A1E8A0D6ULL, 
            0xB43A02ED226CFE3FULL, 0x09495E959AAA5E05ULL, 0x58220E8D2D132A36ULL, 0x1A94339D57EAD33CULL, 
            0x53B6BAFC9709FDF4ULL, 0xF4D1642C06D132D5ULL, 0x11E6B356DD3AEB3CULL, 0x4A98200AAB412FB0ULL, 
            0xC980BF283057A658ULL, 0xED60229F7053BFA6ULL, 0xEE78A984980D26ABULL, 0x6149EA81BDEDE166ULL, 
            0x74E9C9E09EE23951ULL, 0x0123A6FCC97F240FULL, 0x5BD2A224BC643D2AULL, 0x1EC00926FCB16D7BULL, 
            0xD8A577A0D5F51C68ULL, 0x8697FD8BA9EC4644ULL, 0x53309177A7316D58ULL, 0xB8FD16C4932D2AB0ULL, 
            0x99B4A7DEC643D0F5ULL, 0xFE611CD2C7A99784ULL, 0x81F8C9B4C1817C14ULL, 0x5F2E5EB1D3862971ULL, 
            0x25C1C76C95073B13ULL, 0x033184DB5E5B6B7CULL, 0x99ED6B8D4ABD28F4ULL, 0x28CD77316FF57E29ULL
        },
        {
            0xB2BA58005F2D837BULL, 0x7421F9B3A8B662C6ULL, 0xB3619DF11ADA261DULL, 0xF017B537601043E8ULL, 
            0x0CADE1FB64714EA5ULL, 0x4FBFA17AAB06948CULL, 0x70B4D833ECED8085ULL, 0x5AB1BC89854B1CF6ULL, 
            0xD0683584613FED5AULL, 0x389EF8F4FCBAD169ULL, 0x771ABF1AE183C364ULL, 0x0BE41E1E153F56CFULL, 
            0xA3D9C95816EF76BDULL, 0x8CBF1F5DEA8F46D7ULL, 0x966803217961C6B2ULL, 0xA1C20333A6B18EF3ULL, 
            0xC1D5AF9C017800B2ULL, 0x367C2CA62D7C8174ULL, 0xBAAF910C07F5A89CULL, 0x5FACE983C46DB129ULL, 
            0x4767A04407D6B380ULL, 0x2CE9AB9713C01D4BULL, 0x263F468590318D59ULL, 0xB1F9B06AF0B93C74ULL, 
            0xAFAAE9AF9D76FE72ULL, 0xBD3120336DD7EABBULL, 0x06564E68CC3647E4ULL, 0xFD62A72AB7F63A3BULL, 
            0x75793139ACD9F61BULL, 0x286F7563AD53B1C8ULL, 0xCED2BAFA680A4D5EULL, 0xA474932DC8AF26A1ULL
        },
        {
            0xC7E8974D6702AE3FULL, 0x21B1AB1EC1888A7AULL, 0xC3BFE4AA2A570127ULL, 0x8FD4A93B3D028483ULL, 
            0x2052B02FCD5FAE89ULL, 0x4B74A47F7911D49EULL, 0xB28D246A33CD37A0ULL, 0xFC39B62D79AF9FBDULL, 
            0x723EC4466D7515C3ULL, 0x5E55CCCFF2B92F90ULL, 0x4BEB72CF59A274C6ULL, 0xD800F48165FF6ED1ULL, 
            0xD567923AA7F9CDCCULL, 0x35F8E8443F8D256AULL, 0xBB28F53A94DEC01FULL, 0x061EEC69389DEEA4ULL, 
            0x9A8E1F53EAB584EFULL, 0x7E14FF3112724B5CULL, 0x2E41A4B735983C8AULL, 0xD801BCA9CF9C2FB0ULL, 
            0x4DEA783C96F39520ULL, 0xDFF4B0A032FC1E04ULL, 0x7989D2BB9F58E223ULL, 0x0F29EF38AB99A3FCULL, 
            0xEF194290E633D5C0ULL, 0x9F3E83EDB4A63A1BULL, 0x03FDE2664958200AULL, 0xB3B3F6042F48806EULL, 
            0x49095489BC89D21DULL, 0xADF9F6B547613037ULL, 0xDFDC1ADA7412028EULL, 0x86D89BD34DFB9D44ULL
        },
        {
            0xCFC218429D3E7753ULL, 0x6A0F84EF47B3C8C9ULL, 0xAAD101818E049336ULL, 0xF8554559AF0165BAULL, 
            0xA319160B0B231349ULL, 0x69B77FB371E6320DULL, 0xBF63297D5178B04EULL, 0x0EB2B7227162F0E6ULL, 
            0x22294E262E47F4EDULL, 0x44E6ACE31470A361ULL, 0x0B2B6FF331DCDA29ULL, 0x34DA80C526A7A521ULL, 
            0x3E79C99FFD3E0BB6ULL, 0x08A77522679D2982ULL, 0x81449AC66F943DB6ULL, 0x7FA38C833274B038ULL, 
            0x85D8E14DB504DB67ULL, 0x5E57B0529F2B750EULL, 0xC84B19B235AC38C3ULL, 0xF376C53621A362A1ULL, 
            0x890D45348E96F7BDULL, 0x91CC35F04513B40DULL, 0xFBFA52F4E36CFB76ULL, 0x167417E1F75712A6ULL, 
            0x6EE7965559A00EA0ULL, 0xF5F2F4274846E55DULL, 0x49EFD55FB41E9895ULL, 0x61B2A12A8A216E7FULL, 
            0x6ED7F1B7C0B3A653ULL, 0x11C4599666724D61ULL, 0xFD45700AFB482C53ULL, 0x18C5D39C59D01279ULL
        },
        {
            0xC6AD2F143EB13D1AULL, 0xC53CE26D0F42E78EULL, 0xE8EAB58AC38F5242ULL, 0x32919C40B919A54AULL, 
            0xFC2D2D3E37585EBCULL, 0x802DC0972C76B42AULL, 0x3BEEE40758BBB21CULL, 0x310C569CFFC984D7ULL, 
            0xB6615BA9F818199BULL, 0x48D106AD7CF0EA7FULL, 0x384166727DBE91B6ULL, 0x6D6F6EFE75D77D1AULL, 
            0xA6C9AEEC60E6A255ULL, 0xD212D741254F29CBULL, 0x435A4E2CAE51BE83ULL, 0x446BC6F067B5BA23ULL, 
            0xF7DDB520AB22040AULL, 0x37E641D7ABE32217ULL, 0x72D8AD2ABB3F9FD4ULL, 0xC9094C9D98165067ULL, 
            0x24EB220BB92A1B73ULL, 0x1D1A9725C80CB119ULL, 0x73B9721936D4C228ULL, 0x3547C68D3DA4A0F1ULL, 
            0xF06C22B999B208EBULL, 0x7BA6D2FD83D92A2CULL, 0xFBDDB2E214E82557ULL, 0x89F108B2B42F22E7ULL, 
            0xD0B530E4996AD38BULL, 0x2B4556BEECE3EEF7ULL, 0xFE3BBCE2F834A5BAULL, 0xA047FCF3E379C450ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseAConstants = {
    0xD7A4F09F26404ECEULL,
    0xBED676B50851A435ULL,
    0x4BFC6CD7C4E7425EULL,
    0xD7A4F09F26404ECEULL,
    0xBED676B50851A435ULL,
    0x4BFC6CD7C4E7425EULL,
    0xDABEBAC5D80DA25CULL,
    0xEC02439F2199F51DULL,
    0x47,
    0x7B,
    0x69,
    0xEA,
    0xFB,
    0x30,
    0xBD,
    0x14
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseBSalts = {
    {
        {
            0x3F63EF6AFBCD5A47ULL, 0x6383B2C79EC15035ULL, 0xC1AAA90F716C0DCDULL, 0x705DE3AF769DD5CFULL, 
            0x2D71314E97DB71AAULL, 0x4D5816A089766D1FULL, 0x01542EE8D6BB0204ULL, 0xBBE536065FD44EC3ULL, 
            0x02A2E7EA253B6709ULL, 0x3CF195FA74FC54D8ULL, 0x90A34D79AC7AC445ULL, 0x3D2F09D971DB85BBULL, 
            0x6DCA7DCC7ADA9837ULL, 0x7E1EC3337B561BF4ULL, 0x9F49649D70EE70C0ULL, 0xD3A2483064D2FD2CULL, 
            0x2300AFA48E273FB0ULL, 0x04FC04F583387D8EULL, 0xCE7C568152832A7CULL, 0x3731381B8BC85629ULL, 
            0x03269D818626F90EULL, 0x2EBBA7D1EA1259F1ULL, 0x04124536BAA930F0ULL, 0x0BC8C036165B176BULL, 
            0x7C36CD3AF69D4468ULL, 0x17E0F749796D2A06ULL, 0x08869364175DC1DFULL, 0x3D3D8D898F4A99D7ULL, 
            0x1D6B728DBB304C36ULL, 0x540E09DCEAD6579CULL, 0x24EE7AC2A0F3348BULL, 0x86A07EA43EFF7B3DULL
        },
        {
            0x29006B488599320AULL, 0xAD71F22E1FE97520ULL, 0x4676D3DA82B12864ULL, 0xC774091005CF8EF6ULL, 
            0xF10B85D2B37A2288ULL, 0x971BCF279EF10D85ULL, 0x1D975CA47F84B21DULL, 0x20198708F946004AULL, 
            0x5361A29B57FAED07ULL, 0x1D90F331AF6F6C66ULL, 0xCDD554E92CA7472BULL, 0x0C752B5F121C1C8EULL, 
            0xB26142E3E5F1B03EULL, 0x999C30530233F51EULL, 0xB1E5F5CAD8590D08ULL, 0x5D9A36A15649981DULL, 
            0xFA13E5A2587D2B1CULL, 0xBDE82404F080A2D2ULL, 0x62EF331C1D2DA82BULL, 0xBDCD61C122A432DCULL, 
            0x668520CD3F9FA863ULL, 0x33AE403C55B1494BULL, 0x763CC84F840C1F43ULL, 0x3DC42317BC2B5E73ULL, 
            0x2E7268470B3E80E5ULL, 0x13C9C4ACF6C5FB84ULL, 0xF69BE6B93AC9509EULL, 0xBB37C19C94360E38ULL, 
            0x6EB0501E55E1DA82ULL, 0xE85D3DE5F3B2D0ECULL, 0xC7C853A9CB030E28ULL, 0xA2A72303682E5264ULL
        },
        {
            0xAB11EE0A34815E6BULL, 0x658840FD9739F5C8ULL, 0x3C5C5CBD4AAC5154ULL, 0x2560D23F7E890967ULL, 
            0x5EF45BDB84527400ULL, 0x76CB4F2FB836CAB7ULL, 0x97222AF84C504636ULL, 0x3F3F3FB12EF90F0CULL, 
            0x69D471FDEED3D43CULL, 0xE091A5C677713FE3ULL, 0xBD800AD640AECCEDULL, 0x07EFEC99704E62ABULL, 
            0xAC24F66A12E046EEULL, 0x60DF7032D900A6C0ULL, 0xCBC9D161890CBD43ULL, 0xB37B7C6FCD554F1BULL, 
            0x2C79EA35084D789EULL, 0x296593C7BFE3BD90ULL, 0x1C46C7D1D28C00A1ULL, 0xC14B4935305611A1ULL, 
            0xACCA5522628CA4D6ULL, 0x0FCA0A95A41E04D3ULL, 0xB8F0432DF0E9EBF3ULL, 0xEF9D20D94664818AULL, 
            0x343D1D28F7C920AEULL, 0xE7A144ABE5EC708AULL, 0xC704328A1CFAFC9DULL, 0x635514F935F723F4ULL, 
            0x480426581FB2C6FBULL, 0xDBD8163054F4A311ULL, 0xE7D00D8B692F25D6ULL, 0xB3A628126FED395AULL
        },
        {
            0x13CE4DFD7CC2E555ULL, 0x0AC2C158CA162DF6ULL, 0x901D323B84D8BE29ULL, 0x630027003C37CDF7ULL, 
            0xC3851E127DACB2F2ULL, 0x0BC08EC72E261515ULL, 0x91BD398C9390CA65ULL, 0x1FE01F67432829DAULL, 
            0x1B8C60D046DEEBF6ULL, 0x4F2363CED438D1E9ULL, 0xC6385D899F638FF2ULL, 0x1BEDE9D2EC430A7FULL, 
            0x0A8D154E43001E39ULL, 0xF502BD6E1570680AULL, 0x09EAF1FB443CCE8BULL, 0xD575DE0E82F0BA73ULL, 
            0xEE1663FE7AD6A958ULL, 0xCDF95FBB2795F4AAULL, 0x8736897717FB613DULL, 0xA6AED896EC80FCA0ULL, 
            0x0C60A77F6E378BB4ULL, 0x19A190D5DAF93A31ULL, 0xA1E12A35C287BAF0ULL, 0xBC445072B3300D58ULL, 
            0xE4D9417B8422447BULL, 0x6E338BA4CE861F72ULL, 0x2517A93764BFCB31ULL, 0xF14D6560BB0FB1CFULL, 
            0xB534CD817D91B980ULL, 0xB1CDFFE36D127A27ULL, 0x6CF9C57C7E0A104CULL, 0x5047BF54B6577BF8ULL
        },
        {
            0x4E44B3C3D465502AULL, 0xCDC32BDC76BAD759ULL, 0x81FA7F34903AE58FULL, 0x8169A9BC6DD34B9DULL, 
            0xC5968EFB515782AFULL, 0x55D6346E30E713ADULL, 0x0876CE1578225D28ULL, 0x66123B8CF31E21A4ULL, 
            0x07F7EEF423F9B6A7ULL, 0x57BFBE0EAD5C75D7ULL, 0x7120FECA4B10787CULL, 0x7FF275DDADAF4765ULL, 
            0xE0091F8B57D22D93ULL, 0x54E282B88370C715ULL, 0x4217BD228B91708EULL, 0x0BCFC393E2EEB479ULL, 
            0x461BB9437A212B77ULL, 0x6D43018E9A0B6E5AULL, 0x8510E94D4F1F0981ULL, 0x7AFE131925EAE694ULL, 
            0x67F30B6E1D93BE94ULL, 0x1DB172834F5429B7ULL, 0xC88A4551EC80725DULL, 0x3130677AE83BC81DULL, 
            0x5EF265DC0416F3A7ULL, 0x394A645BEFC10A0DULL, 0xF309403FFE6F5F2AULL, 0xDCA81293041C07B6ULL, 
            0x7EFACF1908211C54ULL, 0xC960CF31EE4D100AULL, 0x18FCE295DE6607ADULL, 0xC37CFEFEA614BD69ULL
        },
        {
            0x9DDC799B76DD8F3CULL, 0x79588862033AB92DULL, 0x0091479E7C515BA9ULL, 0x309A22A73D19944BULL, 
            0xEB1CF64B276F76CDULL, 0xD61CF2E61B0FD99BULL, 0x6931C2D025AF9580ULL, 0x95A9135ED8B73EF6ULL, 
            0xC7F9F85A7ED6622BULL, 0xA459708B7332BF13ULL, 0xD256AA5A10241369ULL, 0x8A369E083C56C5B3ULL, 
            0x532712D7AFF7ACE9ULL, 0x5D93BD6ED9BD81D2ULL, 0x923C5530AE1AB984ULL, 0x5FF01EA3D85AE3D3ULL, 
            0xB7E6E03D0CC867E2ULL, 0xC44C6F71D743CE4AULL, 0x34E147F7FDBEA003ULL, 0x2E3592703A4E73ACULL, 
            0x1DFDD6C08898265EULL, 0x51411A8B62C6134FULL, 0x6A345561C83E241FULL, 0x6E98E8BFA2619D03ULL, 
            0xA605569B3F453F51ULL, 0xE73DBB0D0A898774ULL, 0x19CAA79BC6D23B20ULL, 0x6D91067D04DB61D3ULL, 
            0xD70F673EA8858AEAULL, 0x193AD429343B4EBBULL, 0xD4A956FF61695FBDULL, 0xAD785449107C1308ULL
        }
    },
    {
        {
            0xEA69B9BEDB9E5E88ULL, 0x60B796C9954B2767ULL, 0x42DCAF316EB81D19ULL, 0xA9C6435FCF1FFA4AULL, 
            0xEC7336DE697E97DFULL, 0x023996CBB0267ECBULL, 0x01A6464476C946B9ULL, 0x34CF0203622BB86DULL, 
            0xC4E21889F6FD6033ULL, 0x3B43565BF62FB439ULL, 0x0CB51C75642356F4ULL, 0x6D1DCB5C00397662ULL, 
            0x58A18943DDD09E7DULL, 0xC301AABA0793A1A7ULL, 0x0F36C3335A0F0B94ULL, 0x4F1202F4CAF92668ULL, 
            0x109CF36E0923CABEULL, 0x9DAD54B0D3967A7BULL, 0x5A3DFF05DF19DFCEULL, 0x7CB0646EE40BC5B2ULL, 
            0x9B16C1A1384E8A84ULL, 0xE54879669BF52FB2ULL, 0x5B4694F233899246ULL, 0xFA02F357F0711F29ULL, 
            0x3A146B25178E10DEULL, 0xEE6F84F1FAD0F68AULL, 0x9C733AD263238652ULL, 0x938440EFCB7DB92EULL, 
            0x9945F6B71857ACB4ULL, 0xBC2EE84774999AA2ULL, 0x188816B913F4E44EULL, 0x4659C52C11347320ULL
        },
        {
            0x956CBFA1774A4195ULL, 0x914451459DCD3966ULL, 0x83E6B4F12D06E224ULL, 0xCED5A9B95AD06C20ULL, 
            0xFD1BC76381858A0BULL, 0xD724CBAED5DA9F20ULL, 0x69839CDEEC91535CULL, 0xCDBBFBADA5960A95ULL, 
            0xACE6BBB586E7FE92ULL, 0x0394B3B71929EF17ULL, 0x807AA56CABC42097ULL, 0xD8A6B8143D8CC8B7ULL, 
            0x4C520981BEEC6FA0ULL, 0x32E4FC1000DD2F38ULL, 0x0F90F765CA5816ABULL, 0x9DB729F85957D965ULL, 
            0x3AF32DBF084E0845ULL, 0x772BE1B4180040DCULL, 0x0EEE05B6F1DF7C19ULL, 0xA6E638FD29335120ULL, 
            0xC7AA213DFBAE40CBULL, 0xF2CA37083246E5CFULL, 0x1BFEC23BF28463A9ULL, 0xE28F796C0667CAB5ULL, 
            0x0B664F956B069686ULL, 0xFBEE58EDF7917C48ULL, 0x197A970D97C081ACULL, 0x137B5327DFBDACA0ULL, 
            0x3C0B6E4487784BFFULL, 0x411F96A63F2E77B5ULL, 0x589D0629DF397175ULL, 0xDCDFDB6D64685E53ULL
        },
        {
            0x068CAFD22245CF74ULL, 0xAC1A89F8EFAEEB79ULL, 0xF88A94958D6D4DFBULL, 0x7D4E797B9CFA809DULL, 
            0x79107DF17E83CA8AULL, 0x047CE35A3C6C9A30ULL, 0x0F0B0D65163750F0ULL, 0xC6DA9FD9BD3F123DULL, 
            0x2BF73D0176E184ABULL, 0xB1D09D610525369EULL, 0xFDAC2F5E0D6A0FD9ULL, 0xBC23404F35C14801ULL, 
            0x5C49D5C51AADFC52ULL, 0xF3EE2258FAFD4C92ULL, 0xFFF7F9FFF128C4B3ULL, 0x24FBAA191FDAEF5EULL, 
            0xCE8F7701AF08A981ULL, 0x2AD196ADFFB96769ULL, 0x8488DCCCF1910EEAULL, 0x541350F95389FE3DULL, 
            0xB1447C12C5D21A5BULL, 0xE69ABAC586D1A6E0ULL, 0xCF983E8A274388CFULL, 0x9AF05292FE32B287ULL, 
            0x2E9370DC7531CEBBULL, 0x8873EFF2351F58F0ULL, 0x65A215EB611D646BULL, 0x8D9B6E551724EAACULL, 
            0x72685C3A39D8EF27ULL, 0xF9EDAA51C50CED79ULL, 0x959F814804B966EEULL, 0x9413C025DF4AA193ULL
        },
        {
            0xCFD62F774BDEEA30ULL, 0x3740258AD7A2AB21ULL, 0x56DB1E86879F0484ULL, 0x093B191AB33569A1ULL, 
            0x348F2D5DCBE6BC59ULL, 0x5C7E675B5D8EC378ULL, 0xAC7B22842879711FULL, 0xBD5DB425557AF858ULL, 
            0x42E8D2511E47C5E3ULL, 0xA16C8BA7CEFF2901ULL, 0xB1CAEF5F7E8E1961ULL, 0xF4FA87619F3CC59DULL, 
            0x545EC248EB946ED8ULL, 0x24BFF45666394FAAULL, 0x6480BE676BE3F4CCULL, 0x2A50C60182466338ULL, 
            0x236FD9ECBC09261EULL, 0x6F9AEB4358A088F7ULL, 0x8E9E64E0DBDA5E48ULL, 0xE68777A2051B379BULL, 
            0x81A18EAD1B6765F3ULL, 0xF68551225F612D0CULL, 0x184A3199E77A36F1ULL, 0xB2771701CAB6EC49ULL, 
            0x02D0F6E76C39C589ULL, 0x06DBDFC2AD3997CBULL, 0xEFC8940530F96549ULL, 0x6EEDBE9A9F380CD5ULL, 
            0x3A67D28592AF1D50ULL, 0xEF1D33120B83DE7EULL, 0x5B5E2EB13B32970CULL, 0xF98C1B9E803CFE71ULL
        },
        {
            0x271A0887E6A57A51ULL, 0x5128F94C33EDDA5EULL, 0x6449825470B707E1ULL, 0x05608F66BACBF39AULL, 
            0x6DA1D7B13E64D58DULL, 0x2F18E656CE9FC32CULL, 0xC3502B5E8A4187A6ULL, 0x1165E6F1A5D3DDC8ULL, 
            0xAF547CA82588EAB2ULL, 0x7ACEBF6D7ECC3526ULL, 0xE60CA68E62EE4147ULL, 0xAA6E58A504904D0EULL, 
            0x41451C1526ED24D4ULL, 0xBA805C9A1D0CCC87ULL, 0x289A0C075963F5B5ULL, 0x7848998FD1CB00CDULL, 
            0x7207BE3B2A392EBEULL, 0x9F8AF3C23333F597ULL, 0x5A99FB870D607401ULL, 0x3667691ED34D1E0AULL, 
            0xF6A45CC67F306130ULL, 0xC8A75FFD15B36D30ULL, 0x342F45DF81054215ULL, 0x802B99002D7AF7E1ULL, 
            0x7B1828461D3A5486ULL, 0xC67BF5EE3A8337D2ULL, 0xB5BACF1325A88A95ULL, 0x1DC728849E6313CDULL, 
            0xCA0E4F861088B09DULL, 0x89FC1CD59A4CFAE8ULL, 0x49B25211BB39BFE6ULL, 0xA9061D8968E90534ULL
        },
        {
            0xD2C6D9B16E7CEAE4ULL, 0x03BE7654476AC484ULL, 0xDD84F28CF886B317ULL, 0x27C3A0670B782207ULL, 
            0x75E364E6FCF38985ULL, 0x57770B5CA0640663ULL, 0x093A427D69A789FDULL, 0x87BF2ED07609538DULL, 
            0xE6A457B3269A5437ULL, 0x7F4C59CA24342165ULL, 0x5A3213C7827768D0ULL, 0x3CE8D3C1125F566BULL, 
            0xDE4FF7D8427B3EFFULL, 0x47B385E2F1C7D692ULL, 0xBFEB26464CA8A4B4ULL, 0xB89E5B2CA2DE7040ULL, 
            0x62C0D21658BD3338ULL, 0x97CB5F3F0322A63BULL, 0xA7DAD36B828DEAA9ULL, 0x9E80A510871D32E1ULL, 
            0x01F959701EDE1328ULL, 0x52C00A605942927BULL, 0xBFA862E64E0BA9DEULL, 0x14BD7224A5E85C6CULL, 
            0xAE0FCB6BA2CB4F78ULL, 0xD7D5EE34B37DB651ULL, 0x984364A1CAB9E7D5ULL, 0xA7AD09CDFF4DB967ULL, 
            0x132DC25F079900A6ULL, 0x6845C1515FDEB9D4ULL, 0x16F639B2B5A1CDEFULL, 0xAC012875FC5C93BBULL
        }
    },
    {
        {
            0x7F1B07E5EFBE4CB5ULL, 0x6D532ACD2D6E64BCULL, 0xE7634D0311D6BD5DULL, 0x30381FF122E5F8C0ULL, 
            0xBEEE335210CCEF89ULL, 0xC7D919962D3AA949ULL, 0x38E32C2CE85CC9FAULL, 0x84EC93C92765C2EAULL, 
            0xCA5F5D00A201C2F2ULL, 0x01849966AD6FEE7BULL, 0x922C6D613003AFF5ULL, 0x9DB7665AC44FAD10ULL, 
            0xFC1555B84979AD39ULL, 0xFFE1E5999C52022BULL, 0x000027A2ECD76AA8ULL, 0xA84325CF91CAA218ULL, 
            0x5132A707A995B565ULL, 0xAD2B03EB5627CA79ULL, 0x738A248BA2AD5126ULL, 0xF08F96EBC01CA0B3ULL, 
            0x71B02CD6A2E7F107ULL, 0x38015D524D7E6E72ULL, 0x5F844A9109C8ADAAULL, 0x5E0FBEB71E7B0F70ULL, 
            0xF11A7BC2792D6AC9ULL, 0xF3D67A87554F9760ULL, 0xB2D9B237B92A4D34ULL, 0x92EFC3ABFAF808A3ULL, 
            0xA73B34C66BD998C3ULL, 0x409CE64527CC4408ULL, 0x78738D9E8306B769ULL, 0xEB7821A828618E6DULL
        },
        {
            0x5F00EA07B1E3FB30ULL, 0xF233A8B35ED8793EULL, 0x14E2902441CC4EC8ULL, 0x3A06F19E809F95E7ULL, 
            0x4FE9C78938609D75ULL, 0x5D6CC2775FE7F784ULL, 0x34E406237036E97AULL, 0x359DEF532B11DEF6ULL, 
            0xA3FE81FFCFBA8F70ULL, 0xFEDAF3C2D1920713ULL, 0xE5F601268EF25FD7ULL, 0xE86248F9E6ED5658ULL, 
            0x3766DD4B5C89F910ULL, 0x52B2D0EB972D15EBULL, 0x9D06B9E3911F79B2ULL, 0x34DB92A6DF1BA72FULL, 
            0x561AECECB6CECA3EULL, 0x3B24788A96E69FC5ULL, 0x2E127BF321E23A09ULL, 0xDA2A249E54F870CDULL, 
            0xA534DAB1C18532F0ULL, 0x0B3F56D33327D296ULL, 0x80EAFE0F55EA1152ULL, 0xC3645EAEE57FA4EEULL, 
            0x9A082A2873FA368FULL, 0x2EB8A348096C4D41ULL, 0x236810F1B9FAEE53ULL, 0x480DE18A9F852E1FULL, 
            0xFCD5CBED7D2297B0ULL, 0x5C0C0124D50AC259ULL, 0x16E0115724E01F73ULL, 0xF8A3E8E8A4631C1CULL
        },
        {
            0xA7E52040C39D5DE9ULL, 0xBF34976B5B5BEBA6ULL, 0xEBBBDE36AA0B19E1ULL, 0x9594869A6568154DULL, 
            0xD1280BA42F1BA62EULL, 0x472D6256123855EAULL, 0xBE74CB5C92101FE1ULL, 0xC77469F72860C05EULL, 
            0xB5D9884A45797687ULL, 0x28B2BE1A6CC58C0CULL, 0xB50AA2466F51E37EULL, 0x937F944DF7C26295ULL, 
            0xD767EEAA55AF675AULL, 0xC412717EDA38FC33ULL, 0x78FBA769EF49298BULL, 0xA2A5DBE09477ACB0ULL, 
            0x5FDC7A9E89903742ULL, 0x9F03385A153E4317ULL, 0xFCE97C7B37B078EEULL, 0xD9E7FFA56D203F96ULL, 
            0x8E5696B328408294ULL, 0xB84AEF2EE0B35177ULL, 0xC4D0C521155902F6ULL, 0xCAD0CAFD21B29B62ULL, 
            0xA12DD25A443DA45FULL, 0x1C311EFBC0007497ULL, 0xEEE58A0043876DFCULL, 0x1CDE6DB2F4848104ULL, 
            0x94B7B30C950D4552ULL, 0x6700CA1021CEB2C2ULL, 0xEB6AA258179F19FCULL, 0xCFBB82F556564B0DULL
        },
        {
            0x1C8A8FE6F5CE3640ULL, 0x10D7244FDB15FDC0ULL, 0xA16D7B3CFEF68F14ULL, 0x9E17C340470CC4C0ULL, 
            0x9BF57B9E031D1829ULL, 0x43886108048C9F6AULL, 0xC69B2E0D134EF45DULL, 0x2C6DA33221529C28ULL, 
            0x4E4EAB0413C67E86ULL, 0xE3ACDD1124072BB1ULL, 0x606580CF43AC9653ULL, 0x33BE8034DF929CEAULL, 
            0xA4B3FCC2A0ACF7C1ULL, 0x3E80764CA8A0CBE2ULL, 0x3F96151EF98EC627ULL, 0xAA8A8CA0E3B85637ULL, 
            0x43E46B74C177FD44ULL, 0x0E7A19CEC4CBE6C5ULL, 0x14EC62C2BB548031ULL, 0xD1F4AD96FCF4517CULL, 
            0xCFE017B423EE0169ULL, 0x6170B4AA55D07B62ULL, 0x8639A50ECFC8BFFCULL, 0x7A8AEDAB4CA9D0CCULL, 
            0x694DDDCA3644018EULL, 0x740922ED6F1FF814ULL, 0xB276CB76B789D71DULL, 0xB987B8499D00D6A1ULL, 
            0x80FCF6078B4F1713ULL, 0x54F1AA2767AAFBC6ULL, 0x1FD5E08394DF076BULL, 0x47A5CE9F4A8AB11EULL
        },
        {
            0x71F292F1CD7AAC42ULL, 0x37373E0AC3A09BB3ULL, 0x71EA5118AFB5842CULL, 0x5CD655C6BC41B85AULL, 
            0xA515444A5947DE39ULL, 0x266BAD218456160AULL, 0x9AB204E89D6C1C28ULL, 0xD07250CDC88D9E89ULL, 
            0xC3E2E8630249B9C0ULL, 0x00BCB4E33379CE69ULL, 0x32AC66306391ADD2ULL, 0xE31E4F0E9B82C77BULL, 
            0x4896F02D0F46FBE7ULL, 0x35FEADE95FE653A2ULL, 0xC7FA33EACD0DA15AULL, 0xAD91E01602954882ULL, 
            0xEAD5DF3EE55079E5ULL, 0x710DEE1739DD8295ULL, 0xFFBE3C1D1B40C6A0ULL, 0xA6249B0880BC82D8ULL, 
            0x466AECFDFE5BBF32ULL, 0xCECAA2BDCFB53EC5ULL, 0xFD80645BA4CCE6F4ULL, 0x4D22841C93DC7586ULL, 
            0x7AEA190BEF26E611ULL, 0x32B0654D6A1BE816ULL, 0xFBA45FF66AC81254ULL, 0x0D5149BC01C60D4FULL, 
            0xA07C1C8339FA9611ULL, 0xE7A0775CCD61C055ULL, 0xA961E2FAB7336E43ULL, 0xB4BD22247D6EB424ULL
        },
        {
            0xA50C373B3FC2DFC2ULL, 0xE215B8D878F5342BULL, 0x88066FF2BFA1B55AULL, 0x9FBEF749795563AAULL, 
            0x90A80C8E5C08F484ULL, 0x68DDF7B7E688CC3FULL, 0x808E13C2B43C8501ULL, 0xB9A9587DC782E794ULL, 
            0x47B1D2A582C61527ULL, 0x5E3FEDB756422D30ULL, 0x707F53BB7FC90061ULL, 0x3CFD1C36B1311E1FULL, 
            0xFFA589EF4C43A869ULL, 0x69BA3232DB36C885ULL, 0x930EDC96473BCFBAULL, 0x47301FDBC7C03BC0ULL, 
            0x5F255C61626E66ACULL, 0x7E51D9502A4F8351ULL, 0xA43BE091DD757ED1ULL, 0x91D7EF5C41EA5675ULL, 
            0xB06B069EF3A148F8ULL, 0xE933BA2781ECA223ULL, 0x8297700892E5A4E2ULL, 0x0D47BE449269ED3AULL, 
            0x5184687CE227DA36ULL, 0x9A92BC1D142DE81AULL, 0xE00C777A9CA73EDCULL, 0xF7E0F0A03BD04ECDULL, 
            0xB4B21411E96FB9DEULL, 0x56C4887060A7D53BULL, 0xB929C585E832A886ULL, 0xBCC5AE342CBDFEDAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseBConstants = {
    0xA9FA4CFA2851D143ULL,
    0x243025B428DE6D83ULL,
    0xF2A489578CDCCD8FULL,
    0xA9FA4CFA2851D143ULL,
    0x243025B428DE6D83ULL,
    0xF2A489578CDCCD8FULL,
    0xD789D2C3EF9030D6ULL,
    0x4E747A17B6B08E15ULL,
    0xA9,
    0xD6,
    0xBF,
    0x99,
    0xF1,
    0xC5,
    0x93,
    0x32
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseCSalts = {
    {
        {
            0x25FE6BE97C85EDDEULL, 0xA9D794729E45FC19ULL, 0x367832D80243ED3AULL, 0xC069BC344F80DD11ULL, 
            0x06E1752FE3F62771ULL, 0xDB8F41BF0E2FA952ULL, 0x456DD8DD31CBBD7AULL, 0xBF41DCE84BE51EDBULL, 
            0xF3E88FBC42650FEFULL, 0x7D92D21686E1C90AULL, 0x551783CF274A34EBULL, 0xFCD9CCE798433186ULL, 
            0xD26C1693FC7AFDA2ULL, 0xF10DCDDB23503BFCULL, 0x234B57CBA4AB6A8EULL, 0x16DFEDE67BDFD947ULL, 
            0x5621A54DA1FE4EDCULL, 0xA547EFE5FA6917A7ULL, 0x715B83290C70053AULL, 0x9DB8E23CA6BD27FCULL, 
            0x36797F3A38607116ULL, 0xDC8CBF9FD01A1511ULL, 0x106A17B64141BCC9ULL, 0xED015E1E2CBC9CA0ULL, 
            0x62A9B5672EC27AD0ULL, 0x646041968B2BBA6DULL, 0x6435399F62992502ULL, 0x98D8C5A87BF0433BULL, 
            0xA55E938600725B62ULL, 0x66D3F3A8B5ABA9BFULL, 0x14677BE3C890D2DCULL, 0x2D4E0E29A3B49412ULL
        },
        {
            0x4B563FE40B2A9381ULL, 0x9177CD901A9483B4ULL, 0x7F77C2FBE4956E21ULL, 0xC68ADC4821415421ULL, 
            0xB74EBCAF888055B1ULL, 0xD0158C45875999F2ULL, 0xA178607A51010107ULL, 0xECC5AC6A75229174ULL, 
            0x0F809655C709DD96ULL, 0x76912CFF6836ECF2ULL, 0x087369094249A544ULL, 0x1329B1081BF68018ULL, 
            0x655319A6754A15CEULL, 0xE600E568B6C8E423ULL, 0x57A013609D20B473ULL, 0x2EB00616F9F7D1EAULL, 
            0xC5DDBFCA8C7F594EULL, 0x860A0010D26BCAE0ULL, 0x3CFB83BC6A2B327FULL, 0x1B4496B7D9F437C8ULL, 
            0x150369D0EC9A12FFULL, 0x5B0E2AE0EB086B0BULL, 0x223BF7F78D5BFC13ULL, 0x23526D1C5291F75FULL, 
            0xFC3DC7DFF1E57C36ULL, 0x9187A96918120483ULL, 0x903C253B3B333C37ULL, 0xB8D0C78FB9CBD275ULL, 
            0x27C8E6293256E65EULL, 0x21012165AF146C44ULL, 0xC85933E58B793053ULL, 0x47ADD571C62CA4A6ULL
        },
        {
            0xCDF260B0024C2DC0ULL, 0xCF4202CA0F6968EAULL, 0xD5009D725BEBC021ULL, 0x16C369DA7E36D7F2ULL, 
            0x2324580FD0CD2D3DULL, 0xBAAE4080CC0EBFEBULL, 0xDED33332B3EB7CD8ULL, 0xB1D2AA80AB92E9ACULL, 
            0x7EAFD7AB38606F52ULL, 0xDAD7ACC451D0E464ULL, 0x38D8A1C48F71EF1FULL, 0xC5B62D18F26943EEULL, 
            0x4A0124A5A90977C9ULL, 0x4E04C59D5586BBE2ULL, 0xBF4BE130BFAFF325ULL, 0xFFFA6D0EF379142BULL, 
            0xD1E0F284A1E6BD2EULL, 0x08981529FB9E1157ULL, 0xC5903F996F2567E8ULL, 0x8AFB87942F602B57ULL, 
            0x1A2FA921A052DBBAULL, 0xB4E326A1BE4F5843ULL, 0x26FB805522CC97E5ULL, 0x3C26A4DEE75E200EULL, 
            0x8EDACF121D2BB2DDULL, 0xDA028858C2C0A999ULL, 0x55340939704AF137ULL, 0x220F254ACF62249AULL, 
            0x44303CC55F75D079ULL, 0x233C956B7F560718ULL, 0x4BE47D70CC0F44ABULL, 0x2A7951024E464D7CULL
        },
        {
            0x41F93AB4C61E4CB1ULL, 0x2AEC203F8540B0F4ULL, 0xB4D60AAAD50A37B6ULL, 0x33E048CEBD3E721CULL, 
            0xC67EAF44A0441286ULL, 0xB1762E65D1D411ACULL, 0x961270FFFF252FE8ULL, 0x804FE44E9609F382ULL, 
            0x03ED12E24D3B4806ULL, 0x435D4A8615823CB1ULL, 0x4D22F1031B6F54EBULL, 0x3ED0C98404F313B8ULL, 
            0xE954CDC1836010B2ULL, 0x805C2B58131AB372ULL, 0x5E0C4A239EA20577ULL, 0xDE3D48B4DC75C836ULL, 
            0x01BA92555105DBBDULL, 0x09141D4E01266102ULL, 0x7DA7E00DADFDD9A6ULL, 0xBB904C3A25FADD87ULL, 
            0xDA29AFC529F9511EULL, 0xCBEBCB4319E3EA44ULL, 0x2AF59F9760742A1BULL, 0x7A94FEBCB7A61F6EULL, 
            0xAAD5B0EB55BCDA4CULL, 0x77A68AF8879734E4ULL, 0x04C51BD543DCC5E0ULL, 0x4EB5F10CF892EB5DULL, 
            0xE486C7D00894D6D5ULL, 0x61B5B52342365350ULL, 0x7D57CF9806D6509BULL, 0x4C3CCCE1C99C7DF4ULL
        },
        {
            0x7AC37B7ABF3B3D1FULL, 0x0E83472B28229FACULL, 0x88D0BFE33A9402A3ULL, 0x0D08406F23A38A4FULL, 
            0xD6D8B20B88359804ULL, 0xCF4DDC607F5DDB83ULL, 0x94CDEEEAEC38ACEDULL, 0xA65FED22B28FFE51ULL, 
            0x67857F1CCA0501B0ULL, 0xBF7A27E3D358543DULL, 0x63176B5E2A032A33ULL, 0x921189E69E332253ULL, 
            0xEE28573814007FDCULL, 0x57274D7107D3493DULL, 0x9243057A65270A38ULL, 0x2AAFCC06755319E9ULL, 
            0xD55B56BE9E9B4D50ULL, 0x0F4E5643CA5A2D86ULL, 0x42BF6C9DD147B4A0ULL, 0xE9B323D0CB6BF525ULL, 
            0xEADFDD872F6AC138ULL, 0xED776DBCB69D10F2ULL, 0xDAE8E4965E3A8386ULL, 0xF1450F333A9472DFULL, 
            0xFCA72A75FCAD7568ULL, 0x43DEC87AD29CBAA6ULL, 0x390AFF401A417853ULL, 0x65AB759C6D6D9875ULL, 
            0x2BA51F5B121AB400ULL, 0x97124032884DCC85ULL, 0x60B3D1E861C7AA9DULL, 0xBDA58E8B06510ECFULL
        },
        {
            0x4BBE487727E3C4B1ULL, 0x733122A5427AF16AULL, 0x9E756B100D07C81BULL, 0xFC13DDDDD9248DEAULL, 
            0xC48F1B31E9159823ULL, 0xBD0B9786592D9CEFULL, 0xDD411B37B19DBC13ULL, 0x5F1363FEFEA2B3A6ULL, 
            0x606EBA06D2557CCFULL, 0xB6676BADDC0703E3ULL, 0x75F842FA7FCA2E3EULL, 0x52F53660685344FFULL, 
            0x86FBE3440F29A7C7ULL, 0x7B2FAB00474A970DULL, 0xE32554D69211907FULL, 0xABA539CB31D756F2ULL, 
            0x73E37013D44750B8ULL, 0x546B9134BC814873ULL, 0x3B6049958F0B1A77ULL, 0x531FDE8272CC5C7EULL, 
            0x412B8BF55B79AE97ULL, 0x9E744E3529A1FD57ULL, 0x95E33F34D6A7334AULL, 0x1D53BDB870BC5222ULL, 
            0x56F627F790CEE590ULL, 0xBA947D07912551CAULL, 0xAB420564D04B2DEFULL, 0xA223711BD9C7356DULL, 
            0x3C3205F87B76C486ULL, 0xB7C3AE39483DAE84ULL, 0xD4C99C753A464507ULL, 0x6DEB5BF2FFF3203DULL
        }
    },
    {
        {
            0xF5CB8126BCC9A486ULL, 0xAADD04F009D9768DULL, 0xB9A32376D01E4455ULL, 0x52CA617DFF40E53EULL, 
            0x4CDB7E241D0A58DDULL, 0x77CEBC755532A93FULL, 0xDACEE8B429A92917ULL, 0xCFA520EA44FD6831ULL, 
            0x290DE96EAA17C8ECULL, 0x5536B59B7E3F2C53ULL, 0x26A169FAA49A8880ULL, 0x87C496B20115CC85ULL, 
            0xF1467AC3EE00C10BULL, 0xF307B0CEADF474CEULL, 0xDA3FF4510A9F356FULL, 0x85A67DEFD29745C3ULL, 
            0x6B66E88A23F1FB81ULL, 0x1120930CE9BB2B34ULL, 0xE69C83BF2C523A31ULL, 0xD90E29C4EC4BF6C1ULL, 
            0x8E434AAC431E282EULL, 0x7C9CD2D8B3B46215ULL, 0xC5C1720117416267ULL, 0xCBB1604B9CCE8EE3ULL, 
            0x68DEC96E38BEFC70ULL, 0x73D254876D65057DULL, 0xBC24A322E5566410ULL, 0x57DB011FC930D5AAULL, 
            0xD5D180206FE8EB5EULL, 0x5A22BC1E335C666AULL, 0x258BB3AA90338E7FULL, 0xEB8AC1A8A6CEBAA5ULL
        },
        {
            0x58CB61810FD5F3BBULL, 0x1AF802963F059F5FULL, 0x9B6D86DC2EFEF40DULL, 0xE8E603A95AAA3F3DULL, 
            0x74FA732DFA66123BULL, 0xD232DFB96847211DULL, 0x372B8323E60CDE5FULL, 0x1338DE7CB7934FC7ULL, 
            0xCC8B1A575A86B93BULL, 0x82B5D3992A48EED2ULL, 0x8FE2BF8E5578304AULL, 0x3DA9FDBD1690EBB9ULL, 
            0xCCD33C06DB1022FAULL, 0x73DB8874746058DFULL, 0xD13E033AD627AF6DULL, 0xBD926C722CD82AB0ULL, 
            0x4F1C7EE59E1011ADULL, 0x610B964C46CF16D8ULL, 0x5E700859E69732DCULL, 0xF9A8A15D81352C42ULL, 
            0xEE1A03CCC87A4ADCULL, 0x9990D28982F325EEULL, 0x6368501A19A6623BULL, 0x5D5D9FF959F3C43EULL, 
            0x7A19EDFC1F64CCB2ULL, 0x111C7AB8F2C7140BULL, 0x9FD53395E4317EC7ULL, 0xB5CB828FD7107C4FULL, 
            0x7B3EB7428121D124ULL, 0x2A4F2B388CA4D2BAULL, 0xE1A9F406C4574B87ULL, 0x4FBF7E9085F142BAULL
        },
        {
            0x46419C68BFB61080ULL, 0x300931CF360342B6ULL, 0x5907C4367B7AE35BULL, 0x5F28226287A4B0E0ULL, 
            0x16E097D3B85D60EEULL, 0x4BDCCFA24F338B77ULL, 0xF960FB4916B09711ULL, 0x638E75C6F144B40EULL, 
            0x2D28B4123EAECA95ULL, 0x19ADF233A9E8AA98ULL, 0x5F1E9F9B8A02A441ULL, 0x075FC26D3EA2CAC1ULL, 
            0x95C57418C788348CULL, 0xDE58CED2E997B113ULL, 0xA7D1243B0E560326ULL, 0x71F9D1C7A913BDC9ULL, 
            0xADF3DDA29478061CULL, 0xEB400CD30E7A0BC7ULL, 0x5B40B069490FCBD2ULL, 0xF468DC3CC0AD555FULL, 
            0x78CEC6BF0FAB81ADULL, 0xA0B82C71B0ACF778ULL, 0x1D5564BEB09C82C3ULL, 0x4CE3E9DEB1A9D151ULL, 
            0xEF0562353E65410BULL, 0x659E1616C9A1C0F3ULL, 0xA70A71FB900AE337ULL, 0x2D55F1DE631BEBA9ULL, 
            0x7C6B6F862EF28FF9ULL, 0xA63D5BC2AF5463B3ULL, 0x4A3828CCD3203360ULL, 0xDAAC51D013537F16ULL
        },
        {
            0xF7CFC0AD18E723C1ULL, 0xF91027CF85AA8874ULL, 0xF8387E93E1EDEBD4ULL, 0xD1A4BE69175D7050ULL, 
            0x4F8DDC27B8DDCEB5ULL, 0x630F08D2DD5F2ABAULL, 0xA98DCBA9F7B5B68DULL, 0x898E0BB87D97987FULL, 
            0x408DA68B4712EF26ULL, 0x983D1C542B502FAEULL, 0x901A295D4D85C4BDULL, 0x565CB91FB4AFE4D7ULL, 
            0x4DF2F5FDDCBA631BULL, 0x6D1044A2C95E43CCULL, 0xFA8E4A29D6069FAEULL, 0xCF83ECBDE0DE06AFULL, 
            0x0839B954B92A8390ULL, 0xE97430BB7A23C2D7ULL, 0x334F368A36F24DBBULL, 0xF94D0C9871D1DF67ULL, 
            0x4DCD3A226718AB71ULL, 0x37C0EBB6591C11E1ULL, 0x8A263CB6E5E33031ULL, 0x3F036B26AEC3A382ULL, 
            0x58C7A3F33F7B3111ULL, 0x062FFDEDAD40A09DULL, 0xB7A62DDA04C09EDAULL, 0x1A1AA69AEFAE5E19ULL, 
            0x658A225E4105C1DAULL, 0x5338E4894E5DE2D1ULL, 0x2E978E0F110CA59EULL, 0x54413B7FF5D48166ULL
        },
        {
            0xA4396B0FC48E248DULL, 0xD887377E6F955B21ULL, 0xA385083E2FA84F30ULL, 0x421E54F9AEDD5869ULL, 
            0x9E4106AFB26496ABULL, 0x02F07A39D61519EBULL, 0x7C6EAA9CA347CF2EULL, 0x89519DDA516BBC5BULL, 
            0xB1E83D8DFF8E4435ULL, 0x422CDE91D2D9E28EULL, 0x702A22124D6C38CAULL, 0xDCA4B92F373845DCULL, 
            0xB06F68EE601244EAULL, 0xAB597709248AC29CULL, 0x177F8A846A8CDF7FULL, 0x3D3F762C03124B69ULL, 
            0xF3108FD03F5C82DFULL, 0x144A7FD80D2C38E4ULL, 0x5FA507CB810B7C61ULL, 0x6DB85A2B721FA853ULL, 
            0x7F024959753745BAULL, 0xC2A88AB2FB44DF17ULL, 0x8C5864C8CB346B7DULL, 0x1E0F65F2B03B54D2ULL, 
            0x346953DA4BB1EE94ULL, 0x1708E92D622DC5C0ULL, 0x61A1D2C56DEFADE8ULL, 0xA68055422EACF474ULL, 
            0xCEE92979F1EBA8EBULL, 0x5BE53DFAFF78725AULL, 0xD57AED0FDED53CDBULL, 0x6B2C93ABE770F6D3ULL
        },
        {
            0x1C28699023069212ULL, 0xE6BA89B6E943EB35ULL, 0x33072D0D80BDCA3FULL, 0x2BA64CE79BD73CC1ULL, 
            0x8AFDDC4B5B8B60E7ULL, 0xBD1512B55E80AA26ULL, 0x5F09F2B84552F9C2ULL, 0x8ADEF54D460403ECULL, 
            0xABE1DE1228AF31FFULL, 0x18866CB4C4B58BC9ULL, 0x7A1FBDFAAF7EC5F4ULL, 0xFA0FC518E8268087ULL, 
            0x2DD81E475509ECC8ULL, 0xE44098C4F280834EULL, 0x77E656488304DB9DULL, 0xC202ACE8F26477BEULL, 
            0x2174EAD0C9401467ULL, 0xADCE00107D4F77E0ULL, 0xB24FE6E3C71639DEULL, 0x095E340D89CF5901ULL, 
            0x44181A6818B40E57ULL, 0x096D0CABEFD47DADULL, 0x575EE4D2C5EFD655ULL, 0x354ABEC55B09699AULL, 
            0x4BAD50DCA308F95AULL, 0xBF7EA250431BDF0CULL, 0x8CC84CD280EFE0F5ULL, 0x95C72E631854FAB3ULL, 
            0xBB29DA68E881D915ULL, 0x215846D87FF46272ULL, 0x56992C0FF1EF6A39ULL, 0x2448A3D664348053ULL
        }
    },
    {
        {
            0xB6FFCA17BC3CF470ULL, 0x2A0E4851719BE307ULL, 0xE81CE99636F920C8ULL, 0x897F45B8AF2B649CULL, 
            0xE414AB05BE69FFF7ULL, 0x8AA1DC4CAE0565CDULL, 0xF80E3853C9735235ULL, 0xB9C06B679CB63912ULL, 
            0xC3C4BB4552107261ULL, 0xA6A9AC6D20BEFDA8ULL, 0xC63780A23184D7C5ULL, 0x369CB7E675AE3C56ULL, 
            0xB7973A7BC1C9BE1DULL, 0xA403A49FD60C759FULL, 0x85DFDD636736E67CULL, 0x269B8A605BD1824BULL, 
            0xD6115552D565F045ULL, 0xFC419DBE3BB97098ULL, 0x6006419A628D699EULL, 0x53EEB4D33C68830AULL, 
            0xE4CE78D8B4E97DB6ULL, 0xA8BD5F49605593F1ULL, 0x91F9BF83D27148C5ULL, 0x90C17A6E50F3E492ULL, 
            0xCD2FD88A8A2E1798ULL, 0x70A6B702F2BB04C5ULL, 0x3C1444CD33FCECEDULL, 0xAE82206974A0FEF8ULL, 
            0x379C4A71E050F724ULL, 0xC419E967CA265226ULL, 0x6BC92648C59013F8ULL, 0xCBD9381AEB0BFA56ULL
        },
        {
            0xB2875FDACFABBC73ULL, 0x30FC1138F3562DE6ULL, 0x68997867D675DD0DULL, 0x72CA14CC4D2FB189ULL, 
            0xF6C784BFFC3DFB86ULL, 0x4D836811435DD103ULL, 0x30A9D64016744B8CULL, 0xA8559EFC683ADFAEULL, 
            0x0C837B929088BD50ULL, 0x2C476A847C343E8FULL, 0xA361819482B8A131ULL, 0x5D540146490BC262ULL, 
            0xCD3C349C9F1BB304ULL, 0xC0296BF1558DE298ULL, 0xDDD0638AEB2E25BAULL, 0x2B7A106563FC95DBULL, 
            0x803FE9462B356501ULL, 0x26F31596AEC24A1CULL, 0x796839F1069BF21DULL, 0x218AFBADACF12EB0ULL, 
            0xE6FF22345D2C8818ULL, 0x34D626B5A787A1C9ULL, 0xCF983F332454D384ULL, 0x37051781D5427E3BULL, 
            0xFD84E4CC5F288FEFULL, 0x6E8B48C67EA8D6ECULL, 0x9A5B0CC6D4FCF45FULL, 0x56E9E68302F4BB83ULL, 
            0xF6CA9EAD74A2DC4DULL, 0x74B80DD17B1674D7ULL, 0x497B54E548706075ULL, 0x4E500397DD1856DFULL
        },
        {
            0x097FC1BEE5982428ULL, 0xC448B943FB862A31ULL, 0x15FD2975D2AC5E11ULL, 0xDA63228E367F9FBCULL, 
            0xA87ED48322DC3450ULL, 0x0E4D0DE1C675696DULL, 0x07D10F94687E3A5DULL, 0x8853BEED59981056ULL, 
            0x256D6A9A93D7A7F3ULL, 0xED49E8BF2F858A85ULL, 0x71BCDC95CDF5B8D7ULL, 0xBCA38F4543B78F64ULL, 
            0x90E7701261C52EF0ULL, 0x1F1120DB0FBF01F3ULL, 0x80A45577C283B23EULL, 0xC5CF94A4665630CCULL, 
            0x7D4747BFCEDF735EULL, 0xF22537C569F7BE4CULL, 0x0C03DFC537875D8BULL, 0x3E8E48B781509C55ULL, 
            0x721AC61E77E9F3FBULL, 0x616A6D62C4244499ULL, 0x5272BBB3794E7F87ULL, 0x78DE77FDD21AEAB6ULL, 
            0x85E5D9AA470D6846ULL, 0x396BCA9279F69AA9ULL, 0x9C0665448708658EULL, 0xE1EAEE00E721A0CAULL, 
            0x9081D1E49F8218BEULL, 0x639098935540E1B9ULL, 0xA262618A7ACE6FBEULL, 0x42F8C2FD2A29A2EDULL
        },
        {
            0xAA79F2F3AD0F5C7DULL, 0xFA1377FFA0D9095FULL, 0x6994E27169CFC27CULL, 0x85F61083D54349B4ULL, 
            0xA619FA1CE7FD65A8ULL, 0xA36266680417AB62ULL, 0x44020FC3F269334FULL, 0xA588188BD7602DC5ULL, 
            0x77AA4B62B38DDF10ULL, 0x4D919FEB28289D9FULL, 0x957B573B0222FA82ULL, 0xD6C404EDB7343441ULL, 
            0x445ACB9A20A41730ULL, 0x5BDFFAC7A266E668ULL, 0x00BF1EE46D369231ULL, 0x19115004940F2C80ULL, 
            0x5C3C42C6E99EC202ULL, 0x95F5F3663A51A153ULL, 0x6C5B0D38523A3F00ULL, 0xCA8287F92797CAFFULL, 
            0xEE5173FFCF2BA4A0ULL, 0x8751375A057A5962ULL, 0x18F974840695A182ULL, 0xC5A93DD0F3EC4A3CULL, 
            0x19D2AC4E7FF9BAEFULL, 0x36CB8168AFCE4454ULL, 0xBDC9FAE5817EA8E3ULL, 0x09C6F3F449E4B868ULL, 
            0xAA46D67BD4BDDFE9ULL, 0x4B43867B4C07E045ULL, 0xF53D790E221554E4ULL, 0xB78724400FFFC845ULL
        },
        {
            0xFE10CD61C18C809FULL, 0x4309B60DECB54A4CULL, 0x7DFF7FA73CBD89B5ULL, 0x2F495AF1FB4FD76BULL, 
            0x8F9BFF195E4A2417ULL, 0x9917B0C9672C0C8DULL, 0xBD6E0BB2D7445F2FULL, 0xB85428532E48111FULL, 
            0x75F2B917771647A8ULL, 0x1E694A9F00DD7C7BULL, 0x155DA38392D44628ULL, 0x3D6D0F40BFA9B96FULL, 
            0x71A57F38EDB0C479ULL, 0x6EB059E760C76EEFULL, 0x1618BE4FE3F51697ULL, 0x52A633D1B7F92411ULL, 
            0x58CC8AAB3656813CULL, 0xA8EF533A1DA158E6ULL, 0x4E77B72F8A4630CAULL, 0x2462A5AF39DEF27FULL, 
            0xF7D5E449596797E8ULL, 0xDF6D29DF4B0002A8ULL, 0xBEDB9DF097CE47CBULL, 0x79729A722A54E747ULL, 
            0x66E31F40200696F8ULL, 0x0CB94489803ADB0BULL, 0xFE36BE37BA880A41ULL, 0x57FEAB226980BC1FULL, 
            0x538EC3CC680A3808ULL, 0x22BE19E3AD764E25ULL, 0x471CB7E4FA6E4010ULL, 0x3952ADDB6C3ED17EULL
        },
        {
            0x3303178B471A1E50ULL, 0xD6DCB8FD0D239154ULL, 0xCC3F093DEE858677ULL, 0x0519427E020043ECULL, 
            0x3813A148CCDB0233ULL, 0xB688C0D6200E56C8ULL, 0x85BC77DC179A7CA8ULL, 0x7C02F07A31958933ULL, 
            0x41E90B8EC88C7DC2ULL, 0xA8993E0C5242C5D9ULL, 0x6BFB0D367A793FB5ULL, 0xA22D134ACA508723ULL, 
            0x88CEAC30CE4F890FULL, 0x777AD1A477AD49E3ULL, 0x3A64DC8B3294749DULL, 0xB37EF30690193A1DULL, 
            0x9B4DCC94B6F11D9AULL, 0x5F76BF50FB78A64FULL, 0x83723B0523F0078EULL, 0x414683BE3CC36D30ULL, 
            0xA5B3A0DFE7614C71ULL, 0x69F7FBD83537DB59ULL, 0x1628D5D451DA5628ULL, 0xC326C2A0ECBF7905ULL, 
            0xAF13EEEE200781AFULL, 0x570204ED66FE27DAULL, 0x71D5B6D410D7E2B2ULL, 0xB33C79E5F145C83EULL, 
            0x2ABC8B89D1F4D4A1ULL, 0x7C0D9BD36781ED22ULL, 0x8BD5CC0C37ED5D8FULL, 0xE5C03E2A90FD7DCDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseCConstants = {
    0x017E460DC2A5265DULL,
    0x9152C7B1280D0A34ULL,
    0x0D32395DA5D079B5ULL,
    0x017E460DC2A5265DULL,
    0x9152C7B1280D0A34ULL,
    0x0D32395DA5D079B5ULL,
    0x394F18DCC9938FEDULL,
    0xEC5875133FC37152ULL,
    0xF3,
    0xB4,
    0x9B,
    0xD7,
    0xFF,
    0xA9,
    0xA3,
    0xDA
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseDSalts = {
    {
        {
            0xE5ADB1BDF0B33157ULL, 0xBBC7A0F98B71A905ULL, 0x1DC2A420536D1396ULL, 0xE25FD6DB0C1CFCA5ULL, 
            0x5909628DDF190C59ULL, 0xFBAB1C471FBCB901ULL, 0x6DF99B05FAD368CBULL, 0xD06F7B360DEEF18FULL, 
            0x177F2C6F805FD796ULL, 0xB39696C9B321432CULL, 0x69408D8D394F5179ULL, 0x3EAAC2CF8A0216EBULL, 
            0x9BF3E5DA545769B6ULL, 0xF8AF1269C6C3E675ULL, 0x66E3EC68F1077433ULL, 0xA0584A388BF704CFULL, 
            0x1AE93DDF23F9C5FDULL, 0xB221C34CC8877092ULL, 0xD23266CD7EB55F43ULL, 0x670020040D58B842ULL, 
            0xB24AE20D95EFC9ECULL, 0x6E6968CDD3D098ADULL, 0x90C0A3A1D58D0BBCULL, 0xDBA139F60CB469FFULL, 
            0xCDD0466BDEE6A3B8ULL, 0x19ABA4766F886625ULL, 0x2DB609CB69D2F83DULL, 0x2EE32B397AC54C10ULL, 
            0x03B81F3A32DCD632ULL, 0x0047BDA372287AD7ULL, 0xD6E5A77D5E038BE8ULL, 0x7B6AFB79909946ECULL
        },
        {
            0xCC73BE08C611C018ULL, 0xB68BD2FD817B238BULL, 0x1F05435DEA69BBFAULL, 0x92BD24CADF2D8B04ULL, 
            0x9A22DABD4587ACF2ULL, 0x5B0A835DD15030B0ULL, 0x913D3A73B25C6207ULL, 0x57680AEFFFF52A62ULL, 
            0xDDDDA810C83DC80BULL, 0x92579CD153D0D95BULL, 0x38250112DC5AD35EULL, 0xFE205C18AC2ECEE3ULL, 
            0xF3C71D584461095FULL, 0xD01622029721C935ULL, 0x6CB9CDE4094F7B24ULL, 0x55ADE0CA425DF1E6ULL, 
            0x4A557A0E4E388F3DULL, 0xAC75778020A87C64ULL, 0xFB77D0761E96953BULL, 0x08D01F3C63399E49ULL, 
            0x1FA165470C2A13F8ULL, 0xF79BF0961D4370CEULL, 0x1568E4CA0B782113ULL, 0xE133311F22C5D776ULL, 
            0x6F82EAABA584D11EULL, 0x3A33EF07DD08BCC4ULL, 0xAA6E2B65B649E3BAULL, 0x940061A8EF70CDD3ULL, 
            0x4E3291EF4F8900F5ULL, 0x48AA88C10A5285B0ULL, 0x6A47B270DB708EF6ULL, 0xFF4C58B69BABCAEDULL
        },
        {
            0xD904A19D78DD9C87ULL, 0x990AC38A12B253D9ULL, 0xD0D642C02DECB905ULL, 0x0B47CFFA162A157DULL, 
            0x4DD96B1216DD6D01ULL, 0x50752C11E3FDAC11ULL, 0x5EE615CCF21E13EDULL, 0xC9E5F4C224DE88C5ULL, 
            0x371FA75E50F4DA64ULL, 0x38588409E88D39E5ULL, 0xCC07C94CFFBFAD2AULL, 0xB18AABC38AE0B6ABULL, 
            0x7A8E77C4EA9DB7FCULL, 0xD501ECAB590A8D87ULL, 0x1D5101D9E96C4A84ULL, 0x2C37376DB4713A33ULL, 
            0x3177B4FAE6EF7425ULL, 0x83F55F117B6B9EC4ULL, 0xFAF707962543C41EULL, 0x1E89EEE2559077BFULL, 
            0x2AB0D524D9EAC1D6ULL, 0xA9B163215845964EULL, 0x9F77EF9DEAF65608ULL, 0x79C647EFBF7DE969ULL, 
            0xDFBACF94F79B6024ULL, 0xBFDDD40686534D21ULL, 0x91B53054D18A2E08ULL, 0x3314A36FE7B37B4CULL, 
            0xEF728172F0855997ULL, 0x49E4F10EA053CB32ULL, 0xA13F6BD719867370ULL, 0x8B7C37065A5642A6ULL
        },
        {
            0x0F7DFCA4AC687458ULL, 0xC604CF4142BDD776ULL, 0x947A3D2E5865E247ULL, 0xF9337485D8DFCF1AULL, 
            0x540C81F6DB33C698ULL, 0xFFA35C242D8BF3C3ULL, 0x6FC8AD03BEF6F508ULL, 0x73046EAF2E1E5251ULL, 
            0x43AF9E5051CA7981ULL, 0x9D539310BDC849BCULL, 0x0B9C7AD70C3268D5ULL, 0x9E2C83DFC73411DAULL, 
            0x0612E95EA1821934ULL, 0xE3E217A0E919B5FCULL, 0xD4B69674B5889877ULL, 0xBA32F331F99B28E4ULL, 
            0xE0F275699010A5E5ULL, 0x6ACF5424BC8ED26DULL, 0x5EC26F3BEB13D719ULL, 0x388E63AA414E9BB9ULL, 
            0x32E20EE2F439B172ULL, 0x56AF372D68BC9A49ULL, 0xD9236A415D10853BULL, 0xAF9074F55F03B6A6ULL, 
            0x0B5512132A3D7FCBULL, 0xA5005EFEB951F797ULL, 0xA5B4321AE930E47CULL, 0x8914E7AC8F48BBA0ULL, 
            0x3144582033665939ULL, 0x4553ABED1DE74231ULL, 0xC800F9D325A14A74ULL, 0x407E76060F6088B0ULL
        },
        {
            0xD4344CF8D8DC6157ULL, 0xD8A361A70AED3782ULL, 0x738BF0A51B0D74EDULL, 0x795171EDA1CA2709ULL, 
            0xCD1C203906AD3849ULL, 0x582F7F439F7EBB1AULL, 0x733832A26AB799F8ULL, 0x0379718DC16480C6ULL, 
            0xA5E6D61E30B3B586ULL, 0x978EB79BDB7D4C36ULL, 0x5C53D5CD846D997AULL, 0xAF23C2CE09C585DDULL, 
            0x95840A3D94C1079CULL, 0xCB8E76F95A9DDD33ULL, 0xD6A3BE389812EA47ULL, 0xC6C9E0AF567966F2ULL, 
            0x8D012B3494FE51D2ULL, 0xE89A85770169BC12ULL, 0xC7D69894574C8578ULL, 0xF35EA7C24A00F91BULL, 
            0x5A3FA19A7C44649AULL, 0xD66B901EE83CAF08ULL, 0xD73A20E5422E8C25ULL, 0xCF8669A0000233ADULL, 
            0xE105E22C41CDCACBULL, 0xBC1008E4527F148BULL, 0x657BB3C45C0F2B74ULL, 0xE73AD2E582DEDF7AULL, 
            0xC048D83BCA98C2F1ULL, 0x5FBAD518E76E6C9AULL, 0xE2DF396A37B04683ULL, 0x2578962DD8F89728ULL
        },
        {
            0xA40E26CA0C305C03ULL, 0x35DE63948D3C6EFDULL, 0x35757BA67A9197DCULL, 0xF60059E6A96F54C8ULL, 
            0x419549B1DB18487DULL, 0x43FBBC9C7264A2B0ULL, 0x46A5E03C132619B8ULL, 0xAA8FCF84E267CE43ULL, 
            0x503752614A876C36ULL, 0xE37D75C9B66E748FULL, 0x27AE2A3FD20DA513ULL, 0x29C3DC1EF1BFA5C2ULL, 
            0x6D7B26971ABC24CDULL, 0x1735D737EAEE3987ULL, 0x801805DE43A07F9CULL, 0xBFA325246631B5A7ULL, 
            0xBAD1D16C4B0B2B26ULL, 0x143C093A2B5AC4D3ULL, 0xDC047E54863C21EAULL, 0x4CE420BB0E98A618ULL, 
            0x77D6AC94419AE17CULL, 0xD631F58AAFA2070FULL, 0xB0E6CAFFCE772525ULL, 0x524E219825D71B1BULL, 
            0x8F974D8D7CE508C5ULL, 0xCF59D62150418665ULL, 0x04443A4C7E82A932ULL, 0x76B4251D409174BCULL, 
            0x5E401B87B5213236ULL, 0xAC70FF1E617C190BULL, 0xE188310A7F44DF7BULL, 0x3B5FD6DCEDF68260ULL
        }
    },
    {
        {
            0xAFF4AF02DF241D3DULL, 0xDBFD8FA2DF0F85DEULL, 0x0B8894D7B5399661ULL, 0x5A32F2FD0AFBCB76ULL, 
            0xA370EC50F2A949CEULL, 0x2E9349579893A37AULL, 0x79E363E32B5464BAULL, 0x6888ACBA9290BFFFULL, 
            0xB9C39756E91C6B1BULL, 0x5CD1F973C361FCBEULL, 0xE4FA08F4F531C53DULL, 0x61A90B87427BCB75ULL, 
            0xF9023D03B3EE052DULL, 0xA2F1579B82B525F9ULL, 0x2F055F705F5F241BULL, 0x8A6C2D8D566ED607ULL, 
            0x484BD0F0C6CCC7DDULL, 0xE16D437270FD9504ULL, 0x05840DDAD798B8BFULL, 0x66F7711CD90B8073ULL, 
            0xA122668DE070CE92ULL, 0xC26EC08B364E80B0ULL, 0x760B6C7B22669205ULL, 0x244EDCED80B321D6ULL, 
            0x33220B4B1628676BULL, 0xAFB64C207605E75BULL, 0x9B9222A4111C8526ULL, 0xF55EEB1D9B6E075BULL, 
            0x36E100366EF8A8EAULL, 0xD0407E4CA11F5F2CULL, 0x830412DAAB73F738ULL, 0xFE67D8582BCB2847ULL
        },
        {
            0xDBCCF1585261EE17ULL, 0x6135F3E3B5B83308ULL, 0x58D3A082F94EA213ULL, 0x62EC3AC975EE691FULL, 
            0x9F870DE3ABB3C174ULL, 0x3992CD4D55FF27B3ULL, 0x7B4F9C346F038CEDULL, 0xCF4FD3B34D5EFB8DULL, 
            0x8CE1A770265C2909ULL, 0x365C31408E952EDAULL, 0xA4FFC1466EE9AEE5ULL, 0x7A90EA0FB7AEB65DULL, 
            0x531FECBC480E91DCULL, 0x98F38CBC322C360DULL, 0x1EA1F1870840D06AULL, 0x3CBAE00E567F04EFULL, 
            0x9B55875D9D2FD42BULL, 0xFA3747BC665F40B2ULL, 0x19F5D1235064E077ULL, 0xF73F1911C2084EA6ULL, 
            0x3412FF5D0CF44539ULL, 0x2761C2822CA4981CULL, 0x8A187625B87BFF24ULL, 0xE9EB632F24F34EA9ULL, 
            0x11A4BC5EAED2DDBBULL, 0xF45EE8BFF05FE752ULL, 0xF7AE360AE523710EULL, 0x758039D4071B4563ULL, 
            0x09B5E62153C662ADULL, 0xB7BAC2796D188AE8ULL, 0x4320DAC41D5E6CC6ULL, 0x7BEA33E72F4FE18CULL
        },
        {
            0x3D3D34F6B0227178ULL, 0x3F6C30193F048190ULL, 0xAB057B510544B5ADULL, 0x6019A305A72EC3D4ULL, 
            0x412D9BB5D4E2A6B6ULL, 0xC93C08EE1EAB3B26ULL, 0xCFF469BCDA2ACF4CULL, 0x47499F6B8DF0DC54ULL, 
            0x7F85931301185A87ULL, 0x59A54B350D926B17ULL, 0x40DAEB0FCAB5C046ULL, 0xA6AFC1C1AA78A135ULL, 
            0x213E251B81C6042EULL, 0x3D4B673AACBA4826ULL, 0x44EF33390D23B275ULL, 0x10904983173E214CULL, 
            0x506B5DB96313E9E6ULL, 0xDDCADACFDB54D36DULL, 0x4C3EC4391AC51276ULL, 0xC470713069FC86A0ULL, 
            0x6EFC1A7FCDB572DDULL, 0xB6789E249D68B89AULL, 0x6EE8DC41C66DA7D4ULL, 0x3A329B6DB3E3A8E7ULL, 
            0xDA0F0373490C0AF3ULL, 0x4500D163EE42C01EULL, 0xC10991C84D598EE7ULL, 0x8BC5BB29755479E1ULL, 
            0x0BBEC1E847243DE9ULL, 0x99408C0908BE37ACULL, 0x24E41DCE20E168D3ULL, 0xE5E3B788E7437C2BULL
        },
        {
            0x41071C096D6EA3BCULL, 0x9C574716EB0DF101ULL, 0xF3FF640D0ADB8169ULL, 0xEE2EC42C7B855258ULL, 
            0xB0BB20094C4D8C59ULL, 0xEA4AC6FC6A564926ULL, 0x4702ECC0B14EE263ULL, 0xF0B9CA1B62EB1948ULL, 
            0x63A855182A73F4BDULL, 0x29672A98BCA95E9DULL, 0xA7FA8B2E895FEB17ULL, 0x8329E46173350684ULL, 
            0x0C71BE7444FD253CULL, 0xEC3B4472248E0FE0ULL, 0xD047BD4B4E4864BAULL, 0x1469E6368376D5C6ULL, 
            0xBA70488A8035AB1AULL, 0x156E2D2C27F9870AULL, 0xF326C034DEA0CD97ULL, 0x07FC2456D16B3C44ULL, 
            0x9B593CD0DF10F360ULL, 0xBB1CA4F9B442E342ULL, 0x5ADC1ECC24BCBD0EULL, 0x679A0BA8FE4D5FECULL, 
            0x7E4488F4CE2CC3F2ULL, 0xB8DC1FCD695ADCEFULL, 0x9CE0C43F2DCCD4FBULL, 0x4AF9D1C75DDF104AULL, 
            0x1A04FD7CA9440C98ULL, 0x0E4711F053541473ULL, 0x81C702C16C498078ULL, 0x90A68F0C441BE7DFULL
        },
        {
            0xA31F5122AF659FE7ULL, 0x514697332D190972ULL, 0x2FAC2D350911C47CULL, 0x70431D9AF9870E34ULL, 
            0x0ED5939CC778D49BULL, 0x9DB591DE3B77EB9CULL, 0xDE110F49DA58C9ECULL, 0x3F1217D13F44407AULL, 
            0x748A4B85544CC3FBULL, 0xB55F7FFF1CF0EDCBULL, 0xA04CA9E0610CCFEDULL, 0x57EF14173985665BULL, 
            0xADFA830C3EB165BBULL, 0xB6C80B19A0ED9448ULL, 0xBAF085257A09E546ULL, 0x3D3521C1F37ECBD3ULL, 
            0x429210338443E3C1ULL, 0x8F0CAC7360690C07ULL, 0x80E1C2C539CA7C6AULL, 0x429E887E2F1332C5ULL, 
            0x0684275F03A11F5EULL, 0x21BCBA30AEDC660BULL, 0x1AA2F67BD20674A1ULL, 0xEBF9EC77B32BF04CULL, 
            0xFF4B28F0DCC96BB4ULL, 0x8F9D668B669F0197ULL, 0xDD30B8718084EB84ULL, 0x959E362BEC21F02EULL, 
            0x8497766EC25C2CCCULL, 0x4680AC06BA58855CULL, 0x5FFEEC56D1D0291BULL, 0xA805D76695AED776ULL
        },
        {
            0x5C19E2BB2EAB5218ULL, 0x2965B8C2436EA91CULL, 0x40E4738A816E508CULL, 0x47E68F50FAB49C59ULL, 
            0xB69C7484D6B6134CULL, 0xD0F1090625B4F9E2ULL, 0xCA6E5F09F2567AE3ULL, 0x24C73AF1E99BE858ULL, 
            0x28A9C3296CBEEEEEULL, 0xB05252988818916EULL, 0x2E14B0F5F7FEADBAULL, 0x7FCD1241D262FA17ULL, 
            0xC9D00256198DAFC6ULL, 0x79D91E256B4A6485ULL, 0xE1629C3C854EAFD5ULL, 0xC21A24CF53FDBA10ULL, 
            0x057900A3383B6E02ULL, 0x733A6A9813D0F4E4ULL, 0xABB3EC1F4C1133E9ULL, 0x4095EA161F2F4AA3ULL, 
            0xEA636F97BFF8B69AULL, 0xF544693215722AEDULL, 0x0A23199C22D927FDULL, 0xC34715D7CFA2789DULL, 
            0x52EEF944FF9F25EEULL, 0x051E75006DD9A1B5ULL, 0xAC239A5E662246AEULL, 0x465BFD8DF065CA9DULL, 
            0x61556F333B9B7307ULL, 0xCC4AAAA45DCA0CC8ULL, 0x81FB3E481EF37646ULL, 0xB98BAA6BE008D900ULL
        }
    },
    {
        {
            0xC7B315F2A00D9FE4ULL, 0x9DE5DE30C8A9B786ULL, 0x6FA7DB5F7072F895ULL, 0xBDA74707ADFDF40FULL, 
            0x6095E6CE3E16906DULL, 0xF90E7B21EEA37514ULL, 0xA9EBBF8C347222B8ULL, 0x86FFCEA64BF2DF20ULL, 
            0x5C128AFC26530CD7ULL, 0xADFEACF5730C9717ULL, 0xC310E741E50ECBA4ULL, 0xBEE53AB0219C3562ULL, 
            0xD113DC0C5A5D539BULL, 0x38F9AC92C86D0326ULL, 0x19C02B9B02B59DEDULL, 0xF45CFE0074E66A9DULL, 
            0xE952BC7E42A566D3ULL, 0x4DE46745F1D1CA58ULL, 0x3FD4994C19413D88ULL, 0x87B83D60566A4BE1ULL, 
            0xC0BB40372EAD47D4ULL, 0x520769621D986A60ULL, 0x67D46EC373BB25F4ULL, 0x018BF7A5E8773D27ULL, 
            0x02C2B7384C365FE3ULL, 0x86D9EBC51421DA0EULL, 0xCE09124D1C8B4B24ULL, 0x5E4578349F6F7C99ULL, 
            0xDEDC2E0E9C55DF03ULL, 0x197992A577C9EA82ULL, 0x5516347ECE5BC7D4ULL, 0xCE7B00849D2AD9B9ULL
        },
        {
            0x9A6FFFB89304FA2DULL, 0x0D7192313BB03FC0ULL, 0xA9328C7A05963C15ULL, 0xEDD8F9FEE77BF022ULL, 
            0xBAA81B075399C1C7ULL, 0xB5B54449889C9F8CULL, 0xE0BA397321C9AA0AULL, 0x83B4E12EA1B6AF57ULL, 
            0xCED0A0B1A6708887ULL, 0x54BDA568AAF8732DULL, 0xC72F1B20A92CEB88ULL, 0xA81AE0A839DAA738ULL, 
            0x2C9D27BA541A3B5EULL, 0xBB36194B8DAF6878ULL, 0x44EA12B4FDFFE9E4ULL, 0xC19E6C937122D36FULL, 
            0x1B272AD4E11558D4ULL, 0x5A353AE0FC43085BULL, 0x9917AB37405E9814ULL, 0xF33C79D7A51AC44EULL, 
            0xF0CA72323A344EB5ULL, 0x2124953B4783A1D8ULL, 0xBF51F536A515C72FULL, 0x457FD9A93C6DC19EULL, 
            0xC11E1522BDBFDC9DULL, 0x99B37DF41EA3E004ULL, 0x82A4E02EE9265302ULL, 0x540E8980609AB9CCULL, 
            0x17D1D90A5F1B3D5BULL, 0x4BD71619A016D250ULL, 0x691DF0ECF5AAD616ULL, 0x02728A39FA7F8799ULL
        },
        {
            0xA33915BEFBBA2DA9ULL, 0x18F637E07DE05693ULL, 0x0CC4ADB5D72CFF4FULL, 0x9942886D92984689ULL, 
            0x5B2E37159BFA10BEULL, 0x0B660050C2CFFED7ULL, 0x1D5AF9D0CECD10DEULL, 0x9C443A28F7177570ULL, 
            0xD787F3FD65A5F7CFULL, 0x19085BD95AFD3320ULL, 0x94671941A036F23AULL, 0x630010A349D16057ULL, 
            0x76A0EEB138595D00ULL, 0x5297C69DA40C752FULL, 0xD790082FC1521AE4ULL, 0x89A8544F60502463ULL, 
            0x44E0760FE0AD43FBULL, 0xE762B0EE81A3202EULL, 0xCE80FA599F68316AULL, 0x13964E3ACBBB78BFULL, 
            0xC7E9C7FB50C17402ULL, 0xF1153F0A0D41A100ULL, 0xFAF27F9387C95BA2ULL, 0xDBA66BDDBCCEA0E5ULL, 
            0x303FCB4C5592A4E3ULL, 0x919CA92137EAECAEULL, 0x37246CCC4D6A30BBULL, 0xEF62F2852AC29812ULL, 
            0xD189EC67B05EC543ULL, 0x8BA5C223E0683842ULL, 0xDE5853093E9C925BULL, 0xAD75D0ABF7EC5A27ULL
        },
        {
            0x644567C811F92E26ULL, 0xEDEEEE02923A4C10ULL, 0x38214319FEC1BE19ULL, 0xB873684C4FD1D43AULL, 
            0x7D3153A0C9A452D1ULL, 0xD1A360EE5872585DULL, 0x9189F5B9B58EACB1ULL, 0xA0CE128C5B42358AULL, 
            0x07E4A5F0070C9D15ULL, 0xBE70462A4A366207ULL, 0x221CF31F916F51B8ULL, 0x10BA94DCDAAE0036ULL, 
            0x12F7F022626A60F4ULL, 0xAE2C922D7BFD1FE1ULL, 0x08B8DBE655EB88B7ULL, 0xC795F87F2D077437ULL, 
            0x89E3DED0D938CA94ULL, 0x95919E5F54330B56ULL, 0xE80FAFBB67173768ULL, 0x3770012B481E451DULL, 
            0x3027A715EBD721A4ULL, 0xAF4A920054758F51ULL, 0xC6696C099C2540A9ULL, 0x6C81D1A3E4FE51DDULL, 
            0x91903D63C2CF0C89ULL, 0x004418443B416145ULL, 0x88E544074AD78B9AULL, 0xAF91803F1CC6E34CULL, 
            0x7B82069D43C66D75ULL, 0xCD9607637C379938ULL, 0xB9816E790FE7F440ULL, 0xF72CC94D8E01E1A2ULL
        },
        {
            0x190BF3873DC690F0ULL, 0x99DCF4E9DE89BEBFULL, 0xB7E1CE75219E1B24ULL, 0x6B7BEE71845BD384ULL, 
            0xDB3604D4037DE4EFULL, 0xEC26B2336620D4E9ULL, 0x39176D9624E4BC10ULL, 0x0CEB1C6E78156975ULL, 
            0x0E11E00DC8A1233CULL, 0x3B9AA8DA651538CAULL, 0x1EAD0940C718365CULL, 0xCBCE97BB829B5E7AULL, 
            0x27BB8A792D2F509AULL, 0xF9991E364A022723ULL, 0x76F3B17669F93C71ULL, 0xDADE747D7EAB94D0ULL, 
            0xE8B90C9B2B0CBC95ULL, 0x9C698627ACBE534DULL, 0xABCA49D5E163BA07ULL, 0x9B966608E4B08C94ULL, 
            0x695D02A80F0172C9ULL, 0x6C2F477780F2C9CCULL, 0x82B35AFA37A4180CULL, 0x85918C29D6DD4B75ULL, 
            0x6CE735192A3A5633ULL, 0x0A83E87BDA650E37ULL, 0x514AE07CFB3290F1ULL, 0x522888A7F69B3DCBULL, 
            0xD31A71C093503F18ULL, 0xF153772419743F51ULL, 0x0E856846F107506EULL, 0x37950C2A4A630599ULL
        },
        {
            0x531EA95D90E8EFB4ULL, 0x89710FEE273B6578ULL, 0xDCBF14BDA08B5740ULL, 0xBECBED992BD2084AULL, 
            0xC596DA711ABF953EULL, 0xDFC52FEAD475D141ULL, 0x470CCDA7E4F2B092ULL, 0x569E21EA2B88E822ULL, 
            0x32A893BE664F8EA1ULL, 0x3D2B14597EE8BE1FULL, 0x812AD9C9A83E772EULL, 0xB313A03825F5C257ULL, 
            0x5CB2A6DD529C0C57ULL, 0x28A7933797D68ECBULL, 0xE9BD8A1252E688BFULL, 0xB3F40469C94D90BBULL, 
            0xAFF8502F2D9A241EULL, 0xE6EC9F806B779D92ULL, 0xE2F3D86BF50B85E8ULL, 0x4E367FA37A2D5A2CULL, 
            0x86D1E203E6A4A6AFULL, 0xD011F41740AD1CB9ULL, 0x992DF5478F73BB3AULL, 0x4536C974636925C7ULL, 
            0x0C2DE52A4FB8E454ULL, 0x95F73406C3F6ED68ULL, 0x9C918A6B5F2C811CULL, 0xA1A461FC2A67937FULL, 
            0x70B7899CC14775FBULL, 0x409765318A1184A2ULL, 0xFFF2A0BA79A170FBULL, 0x2240D9BA40D0B982ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseDConstants = {
    0x4AE0D42BDA569DBEULL,
    0x6F09E6B3E980E818ULL,
    0x0DA7C79375444114ULL,
    0x4AE0D42BDA569DBEULL,
    0x6F09E6B3E980E818ULL,
    0x0DA7C79375444114ULL,
    0x2AD5F85C5AB3E7CFULL,
    0x7EC61D8549498029ULL,
    0x62,
    0xC6,
    0x53,
    0x7F,
    0xFB,
    0x99,
    0x7F,
    0xE0
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseESalts = {
    {
        {
            0xACD1217EABAB2712ULL, 0x9DEC98E4FA13C69DULL, 0xCFC88F48847D356BULL, 0xDB010C1B60071F45ULL, 
            0x4E654037E0C602FFULL, 0x10070C8FD93CFDA9ULL, 0x969BE6FA584AB3A4ULL, 0x211229AA98ECD94AULL, 
            0xEE1065F0D3564C7CULL, 0x1876EFD46DCC4597ULL, 0xBEAB031202A813CCULL, 0x554C0FFC559D0D10ULL, 
            0x050827B7FB29C570ULL, 0x5376CEB3A038B70AULL, 0xC67B8D6285B5632CULL, 0x79CE8B0BEC0CF7F0ULL, 
            0xD2F401A010AB44E1ULL, 0x3E8590D992B8C9A2ULL, 0x4FA2ABFA3C802E2CULL, 0x69D3FB9FAFF0A8FEULL, 
            0x257ADC87A600061DULL, 0x38DD8FC2AC94121CULL, 0x67517889566F0D6CULL, 0x17AD95F9D0A4FD60ULL, 
            0x276B950B847A213CULL, 0x8BFE7344EEBEF53CULL, 0xB64EF6E8748010ACULL, 0x6C4AA69F23BCF535ULL, 
            0x927131584360FA59ULL, 0x6CBC21CEE3F38F38ULL, 0x87C2E55AEC29976EULL, 0xF8CE16403A8DD70BULL
        },
        {
            0x31A39F91A0867D63ULL, 0x24D430FA907A5631ULL, 0xAFD7F0ED0BBAB68EULL, 0x7D000046FD177325ULL, 
            0xB3DA87D769686932ULL, 0x1678B0F052058950ULL, 0xC91A030CF7F4EFF2ULL, 0xE49AA3D2A39C0158ULL, 
            0xC387CD42F2108943ULL, 0xCFE8F1EAD8DD7560ULL, 0x8E5982EE79F5BC66ULL, 0x3A880D98BC78C56FULL, 
            0x452EBD2C19367EB2ULL, 0xCFAE2A099733CD1BULL, 0xFF0DD832816DE22EULL, 0xAB123AC45A4CED6EULL, 
            0x159F81E4258ADC91ULL, 0xC98FE1AA5B31809CULL, 0xA3D3F86D1AC33980ULL, 0xCA044826EA50F0C1ULL, 
            0x0045B903C7DFEC38ULL, 0x83962DA93D2DB9B7ULL, 0x5DFA440820BC0395ULL, 0x9AE8B61F9F5D72A8ULL, 
            0xB98B2E18C91C3C33ULL, 0x90FA4524948B9C7AULL, 0x01254DE91D879F6FULL, 0x9B6D0E53DC902DE9ULL, 
            0x2B2D5FA712DA9899ULL, 0x638A7AEFAF41792FULL, 0x84D5A9C328071715ULL, 0x76AC4C2FD3D0220EULL
        },
        {
            0x72390CEF6A15A3DAULL, 0x9D3FE980B31220A5ULL, 0xF0322FE438D13407ULL, 0x3AFF93CE5574E748ULL, 
            0x4002F528B1596907ULL, 0xF9A4E6C1DBF1C3A0ULL, 0xFAF8DA4744F5C1FCULL, 0xC450A5279C22C0E3ULL, 
            0x5F75DE8C169D1B51ULL, 0x87AD4C9FD91360B3ULL, 0x22AC4CC10B993310ULL, 0x84250A1ADB4C54C8ULL, 
            0xDBC2C678C84CD613ULL, 0x9AF53BF1DA92C839ULL, 0xB4CF2A9DAC284F2CULL, 0x3F4CEEFE1DDAFD25ULL, 
            0xCA91A573FEA31C8FULL, 0x848B060FC03F3EE2ULL, 0x3455CDB14BC12F93ULL, 0x76690D8FD65762E7ULL, 
            0xBB5B1940F32A262CULL, 0x34E074EED6840CD3ULL, 0xEC89AAD44F0927ADULL, 0xA9DFBABC8920A4B9ULL, 
            0x1DB7412358B2BF05ULL, 0x1708F9831827BE20ULL, 0x0A6216F073E7C8A7ULL, 0xC40DAA6F0A012F11ULL, 
            0xEEA68F2AE9D9667DULL, 0xC0F177EE64644886ULL, 0x4BF241EF0860060AULL, 0x83F7AC1093CA3B4FULL
        },
        {
            0x4832C34C76D6F39CULL, 0xA98650DED86CF63CULL, 0x0DC385513F50DAE0ULL, 0x985F996B2B6EE79DULL, 
            0x2A51BB4DEF43C840ULL, 0xCDF0AED3E7178C43ULL, 0x000BB53C54AFF3BDULL, 0x34E499919ED0FD66ULL, 
            0x19854F6F8DC34418ULL, 0x782D402FF50EEDB5ULL, 0xF3970D74A848AF4AULL, 0x6B3A5533849119BFULL, 
            0x4E00F75F3F2CC143ULL, 0x3504137E9A5AF80CULL, 0x44449135670FDFCAULL, 0xCACB542FD41BE577ULL, 
            0xED650F6827CBB032ULL, 0x556164A7F8052139ULL, 0xABFE34BE8FE898C6ULL, 0xF415B99405583DB2ULL, 
            0x26BDDF796D12EDF0ULL, 0x6D625BB7736C6A5FULL, 0x1C3A3EF48A0BB0BCULL, 0x3FBF13D96968ED77ULL, 
            0x49241B21AA5B640AULL, 0xE0D586646DFCB008ULL, 0xA181CDF1A4F9EA82ULL, 0x57233AEA253D4718ULL, 
            0x220F87498C0E3BFCULL, 0x3C1B6A17B35E6EF6ULL, 0x6067BDA14AFF0555ULL, 0xFACC287C94592348ULL
        },
        {
            0x9B10CC9677ED7FFDULL, 0x807FDEEB34B069D7ULL, 0x6D6FC92FF28329DCULL, 0x141A89808E22C94DULL, 
            0x854F950CE8541247ULL, 0x9BA6496BB1809B8BULL, 0x68180D629F28AFAFULL, 0x7A90C9F7525BF7D6ULL, 
            0x2EDF08877909CEE9ULL, 0xC4F26FA8DE2A3C20ULL, 0x61D4DF4D4BF7D173ULL, 0xF35136288723769FULL, 
            0x7473BB82C7B65DC0ULL, 0xAE19C6992421DB67ULL, 0x229730A925F82A37ULL, 0x1243367D94BEE4D0ULL, 
            0xF29F911C09626925ULL, 0xDFA92617BDD1CF2CULL, 0xEFD92B1B8F3CC90AULL, 0xC4690DA5B3D2ED8CULL, 
            0x864B4EBBF6B832A2ULL, 0x1C3A12BE779C8D4FULL, 0x167D71280253627DULL, 0xE2271F1EED4ACCDAULL, 
            0xA95A27AD7611A586ULL, 0x56556C4EB2C687C4ULL, 0x1271A921E15CBF4DULL, 0x734B2F6D92DA554AULL, 
            0x8D67C2E558CB4270ULL, 0xD9F12E67FC9A6898ULL, 0x951A3A10CDCEDAEEULL, 0x01B8EAAFBBB9F484ULL
        },
        {
            0x548FB8D35C4B3913ULL, 0x269CE0FD46CE46DDULL, 0x9C974AAD9EBBDE27ULL, 0xFB2C4055323F4F57ULL, 
            0x670A71211938F2BBULL, 0xAE9FE0B270218DF1ULL, 0xDDC503C9C1515720ULL, 0x9D81345189196132ULL, 
            0x54DD10617BB7B95AULL, 0x489B7E6C75C7521CULL, 0xC62848817BC5B74DULL, 0x346CA2BEF05BEE56ULL, 
            0xDAC6B7F344E204F6ULL, 0x30431AF45C1387F9ULL, 0x0104F1104DE03AE0ULL, 0xA0DE0C3F34C556ADULL, 
            0xEDB1691AAA357643ULL, 0x88B478368D74DA54ULL, 0x81CCC812F3635007ULL, 0x2F8E05AC17670B92ULL, 
            0x97BFA8FDB4A515ACULL, 0x9856E9BC21CE57A0ULL, 0x4E0A6F423890EBB8ULL, 0x3093574372E6DBC2ULL, 
            0x89841A94385B5B6AULL, 0x10A5EC8421938524ULL, 0x97543D7E4E425838ULL, 0x715FD4CB756730A3ULL, 
            0x76651F1B76421E8CULL, 0x063F350C926581AFULL, 0x8C3500C3DF5199C3ULL, 0x18AE2C905A2FC262ULL
        }
    },
    {
        {
            0x7BB2DFDF32332DA1ULL, 0x6BBEFF696EA30704ULL, 0x9141EC6F370E58CEULL, 0x5BDC0C7521B6B4EEULL, 
            0xBAAFF1687583BFDBULL, 0x595E52BE77FCF7A5ULL, 0xE6D93B128929E3CEULL, 0xE882FB895F8C1873ULL, 
            0xEA3D989DBBA886B8ULL, 0xCA1BABC66A44ECF3ULL, 0xB42887330418E9B8ULL, 0x5CC46CF2935767A1ULL, 
            0xEE55EA4F90FFB941ULL, 0x3CE85C74EE3D02E8ULL, 0xF25627D3EF58212AULL, 0x627794FA9FAACCFCULL, 
            0xBA3AA17C13438CAEULL, 0x847C4A9C6F5DDABEULL, 0x5DD8419127CE9CA1ULL, 0x3E9E141A91076EB5ULL, 
            0x62021D980BBD10B9ULL, 0x8F6AEC2B25297DBAULL, 0xFDC18E030A3AE3EAULL, 0xCDA9B0A52B2432ACULL, 
            0x043FBF5FBF445132ULL, 0x923CA0799702AB95ULL, 0x2F76E99DFD065721ULL, 0xB9CBC31D1D4085AAULL, 
            0x8BA5274652A31EAAULL, 0xF69B563B59CB9795ULL, 0x2F9C97A01014C4C1ULL, 0x43A58C0460BA3916ULL
        },
        {
            0xAD05D749436C39AAULL, 0x529F89D97E0774D8ULL, 0xFC2E3C930BCACC10ULL, 0x9B69B329E9697DA1ULL, 
            0x5DF84F87B7AD2A3DULL, 0xF290143BD4DE87B7ULL, 0x0C4BFBB67B3A78ABULL, 0x75A5D28C18CB8AB4ULL, 
            0x040FA84EB9A17212ULL, 0xEA98E088AA3D92EBULL, 0x509A2A2758447590ULL, 0x470BC0E2AA6280EFULL, 
            0xC57BBDC9EAA0CB52ULL, 0xA69836C677BAF7D6ULL, 0x14BDAD6FB767EF1AULL, 0xFE9007E534B79A1BULL, 
            0x0AC617BF1CAFEED4ULL, 0x3AE5EE8CDC073502ULL, 0x1BECC2D45885A011ULL, 0x8CF8E79653D04C2BULL, 
            0x49FDD227EE3E3D81ULL, 0x4B714271A36FA992ULL, 0xCE4D137C6522F65AULL, 0xAAD216DFA403FC52ULL, 
            0xAAA2B8BE3DDC4CDFULL, 0xD0460DA1141396B4ULL, 0x037505A47071E7A7ULL, 0x396946AB31CD7A5FULL, 
            0x2A393EE739CEE19DULL, 0x46A3E794C5536917ULL, 0xA26AEAD0B31C2AD4ULL, 0x2B6A58E350EA5CC0ULL
        },
        {
            0xC4BE99D15A1A5B70ULL, 0x42D6EB55D67CD3A1ULL, 0x67B9D5385AF93902ULL, 0x59E959AA9D1FB67EULL, 
            0x16B3D2777898AC14ULL, 0x8594F145C45CF0A5ULL, 0x744B3E8166096217ULL, 0x92C3B5838488BA89ULL, 
            0x1479191E7088601AULL, 0x2BB7BEAFB38AA29EULL, 0xD7A69F74DC319588ULL, 0xAD695FB307FEEC56ULL, 
            0x0398B89C9CD06D2DULL, 0x36DAD7F8EF49D649ULL, 0xFE7768782C3AE91DULL, 0x496A634B0ACFF684ULL, 
            0xD4A7CC05458F225EULL, 0xEA11B68C85B7301BULL, 0x93DC69CFE11BAEACULL, 0x61855AA5B482535CULL, 
            0x70D66376CADD386AULL, 0xBBD51AC2B1458F4EULL, 0xDC654366C637E260ULL, 0xF09C2CC17B899376ULL, 
            0xF63B304FD2AD764AULL, 0x966AC4866E1A987FULL, 0x3A21E64047418F9EULL, 0xE1C3805391F94104ULL, 
            0x275F189061F87F72ULL, 0x61980D390CAFE81CULL, 0xF41641F85BB992AFULL, 0xFC3BE4B2B06B6F57ULL
        },
        {
            0x0CBA46A893B11876ULL, 0x50DBC81D68CC4AAAULL, 0x1403790489A8BBCAULL, 0x1D6E75C9961DEB3AULL, 
            0x71D5C23AC3D3CAD8ULL, 0x7C48D0AC2713D7EDULL, 0x15626923EB42850DULL, 0x9631F8B8D11232EAULL, 
            0xCCD8734D6679B6BFULL, 0x72782A06AFC137A5ULL, 0x3FEDFEBF16C75422ULL, 0xA19EEDF332FBEC76ULL, 
            0x8D0BC4CC9974DFCFULL, 0xF9F39623D0339EDFULL, 0x663EFC46F2116CD9ULL, 0x8E9BF453344EDB59ULL, 
            0x63343AFB862EC22BULL, 0x60D1C9B84153E296ULL, 0x81FFD911E5A50475ULL, 0x2955389B3A026EC6ULL, 
            0xA7F2960EAB192D7FULL, 0xF159581BE4003C2BULL, 0xC12DAEBA546DDF7AULL, 0x16E4A23665E2584EULL, 
            0xB53D29173CA08BE4ULL, 0x52AF7D2DEF9C784CULL, 0x5E81484EA80869A0ULL, 0x659C5101B103459FULL, 
            0x6C6892FC1389D69EULL, 0x98787FBA672EAE10ULL, 0x011FCDD62DFA657AULL, 0xD11406CB93E03AB9ULL
        },
        {
            0xFB2564664256C018ULL, 0xAFDBE76DAF7F1D6EULL, 0xCFC34F8343B4D079ULL, 0xE7DD12232DC30CD1ULL, 
            0xB0E797B0E998B2EBULL, 0x7E918F96E6DE3F86ULL, 0xFDF3B72AE35D1EF9ULL, 0xF10451A428602B1EULL, 
            0xFE6C63CCD00BA2BFULL, 0xEDF7036B38533C83ULL, 0x61529773D1C807CEULL, 0x9B98F22F088CDD63ULL, 
            0x04C38596FD6253FAULL, 0x3428AF81A4E502D1ULL, 0xDCA1A2E8F56C47D7ULL, 0x97978FA0193809B7ULL, 
            0x8E91161A770E62B2ULL, 0x274FAD923A9526DCULL, 0xCF844D15C632FD67ULL, 0xCD6BD55F92A01B36ULL, 
            0x9DF992B1937EAE43ULL, 0x05D3066902CFD8DAULL, 0x30898FCE2CA03B59ULL, 0x8A2ABE7952AD58DBULL, 
            0x7C334F86C599F5FAULL, 0x537CC53C0371D591ULL, 0x28F581DDAF86E8EFULL, 0x1F7003E78CB3AB18ULL, 
            0x11FE3EB1B1A5543EULL, 0x850877297ED2711CULL, 0x03981EEB684004B6ULL, 0x096F67F0878FDEBCULL
        },
        {
            0x0BA19C750CE6EC45ULL, 0x35164129B08C70A6ULL, 0x1897DAC5C5D7636BULL, 0x87C9D733121B4951ULL, 
            0xBB5B53A6546D3485ULL, 0x8FE8C66E8C047838ULL, 0x2FFDE7D610AE9C62ULL, 0xB76B6D0B9B1BCE81ULL, 
            0x08B6F7F387817767ULL, 0x93F14120747A9373ULL, 0x03CB67D7A9EBC9D6ULL, 0x07112CD4AC5D8587ULL, 
            0x5FA85319F8956C8AULL, 0x97E8A307598A1D81ULL, 0xE557F2EFC4B63417ULL, 0xD82BF6BAB45A3728ULL, 
            0xBF8C3ED45246D7A7ULL, 0x76DCBD34D51CB465ULL, 0xF9A9C001E6D5B9EFULL, 0x472B51BB21092D44ULL, 
            0x87FC9092B360CBBDULL, 0xF9FA86007D7364CDULL, 0xE1F2CAFF11F298CDULL, 0x9022362B151796F0ULL, 
            0xA0D8422A86A8A943ULL, 0x1D3FDA901CB55128ULL, 0xA71C29C28C329461ULL, 0xA0F3978797F03FD3ULL, 
            0x0048E9DD38BF5098ULL, 0xCAF30547505F7708ULL, 0x4532787D47313382ULL, 0xBDFCBC250ACFB0DAULL
        }
    },
    {
        {
            0xEC2F95FE2B39B09EULL, 0xFCE86398B13B48D9ULL, 0x949075154D3B7A9DULL, 0x5AB5BF3E3A62C935ULL, 
            0x97F02DADA6EE6444ULL, 0x5C9B481379A1D673ULL, 0x8EAD250B700097F0ULL, 0x4D385253C4246BF2ULL, 
            0x46F864A18FBB9434ULL, 0xA613C3E0379E4408ULL, 0x2F33BE5F423D7FCDULL, 0x43697277186A8A0DULL, 
            0x229720867F45B273ULL, 0x41DE930A46A9F88EULL, 0x6DFAEBC50A405679ULL, 0x1D61A286B51EE0ADULL, 
            0x537855868B6E488CULL, 0x615D5B3771A79C44ULL, 0x7C913A0265CD9F3DULL, 0x81109A3BD5CB50BDULL, 
            0x8B1147409DEF3BFBULL, 0xBD36F15A2EED3107ULL, 0x288BC575F10C5FE3ULL, 0x6C857D2DA16E4CDAULL, 
            0xBB9DFBAF0C1AB91FULL, 0x74FE254CDD89AE7EULL, 0x5FB832BEEBA90965ULL, 0x6DF5D69B103989DEULL, 
            0x79E7D04455759F50ULL, 0x9BF1145593E27C6EULL, 0xF671DD961E80130EULL, 0x1E29D3FA9763FE62ULL
        },
        {
            0x299FC8D58786CFC5ULL, 0xE98BA1F70FF69160ULL, 0xB0DD7072597DC795ULL, 0x0BE06CA46883312DULL, 
            0x6039280E29052497ULL, 0x1A463459DAE9259FULL, 0x5ECE811C2444F3E4ULL, 0x5399E924570098EBULL, 
            0x4BBD6E2239E38434ULL, 0x1BDF01142FAF3303ULL, 0x750080C99A20AF2AULL, 0x351D23EB2BEBBA9BULL, 
            0x771D38CF66EB2E25ULL, 0x63B6C4341A54EB49ULL, 0xC5DF32748E76B047ULL, 0x3DA93E65DA1C32C5ULL, 
            0xE4FD00F9AC582159ULL, 0x0E957A23326A1D6DULL, 0x17C92425DCE56319ULL, 0x652B8D45638C9EC3ULL, 
            0x134C377E0A3BBA59ULL, 0x6B7E2D8E0F867AB2ULL, 0x29118F91696E3D60ULL, 0xFA6DA16018659B44ULL, 
            0x7F25A454FA8262E3ULL, 0xDB67FC8E3ADE380EULL, 0x290833A9064F5A19ULL, 0x339A89FDF28FA7A2ULL, 
            0xD80A603608D291F9ULL, 0xBF62D0872E9DCD5DULL, 0xB79C2EF5742FD8BEULL, 0x9CB6460FAFC9D24BULL
        },
        {
            0xD71718EB4236DF70ULL, 0x351516D6D2EF9BC4ULL, 0x3BA5995818249A20ULL, 0x6ED64EFCF785C356ULL, 
            0x2B3142EFFBFB541FULL, 0x299C21422F82C633ULL, 0x68218B033AAC163DULL, 0xC9EFBEF17ED4540DULL, 
            0xA7ABFA0682F30CE8ULL, 0x658A71A690211902ULL, 0xE8C2C0A54040EE2CULL, 0xFEE9B2DD3C093D6AULL, 
            0x6180209647E46B63ULL, 0x6C27088FC191A53AULL, 0xE3C2CD8BEF8C1909ULL, 0x4B8B5DE7D01FF5C1ULL, 
            0x588AEFFAD9386C01ULL, 0xF1C256B57874CCF0ULL, 0xA335BBC4593CAB53ULL, 0xEE95771691FD8C1FULL, 
            0x9DCA9885BDDC977EULL, 0xF2AE24755B68907FULL, 0x2FF7F43C93BBEE5FULL, 0xBDBA78345D897E10ULL, 
            0xDD0794F780244C54ULL, 0x5BB959FE37B8FF7FULL, 0xE962261F3D33EA31ULL, 0xF342B9842949DAB6ULL, 
            0xF3D46505067A421EULL, 0x76032C3595CD7B85ULL, 0xD91887AA29CF8151ULL, 0x35C689D2DE748A8CULL
        },
        {
            0x9F5CC6C56D76613CULL, 0x34EB26A6F69FEC8BULL, 0x989ED39CCC6BA02AULL, 0x1E51B98A62EE5692ULL, 
            0xD84839D640DDFF1DULL, 0xB77381DFD6F614C4ULL, 0xCBF164F167F2FB64ULL, 0xBC340C1FD6D6C4FDULL, 
            0x01CAE8D16914ED88ULL, 0x3B6BA7CB90290D24ULL, 0xE8EC8BE54562DD1BULL, 0xD2DDAFA760AC0A1AULL, 
            0xAC0386AF9CE925EFULL, 0xFC85BEE5D8DC623FULL, 0x779C9021E91EFFEFULL, 0x9297298775C9E0BBULL, 
            0x2828CBC62DB25BA9ULL, 0x27182D5A79F3EC6DULL, 0xB890AE7ABEDD4970ULL, 0x345E9743536C15E9ULL, 
            0xFF6B1B81A2BF13F5ULL, 0x6669EBA4A543F8A8ULL, 0x69993239C83E3C5BULL, 0x9F138ED6C7FF68A3ULL, 
            0x5C96053DCC654A38ULL, 0xFB57CEEC0516178FULL, 0x05F65B455D86FED9ULL, 0x6F8F67B1AF17F3E3ULL, 
            0x0847074E8D1C7181ULL, 0xBD1A9FA3FA92003EULL, 0x6D48A0C2BECACE92ULL, 0xFFA32BFA722CCCD8ULL
        },
        {
            0xEA132D94A65EF523ULL, 0x271BC1F917C97168ULL, 0x411E6563015AD529ULL, 0x7C6C320C18BDF429ULL, 
            0xEE0BCBA0BB14F69AULL, 0x810B3940BE1842A6ULL, 0x80316F8C148C7F37ULL, 0xE192C1F248D3B504ULL, 
            0xFBDA1FF3E9E2F360ULL, 0x676237E2CE81F21DULL, 0x83DCF95DB23FEACBULL, 0x41B9447358AA0A8DULL, 
            0xDBEB6A59739A3185ULL, 0xF47C82117EEEE246ULL, 0xA0F6E1F029261206ULL, 0x8F8F7A8C37664C92ULL, 
            0xDD1CEDF1284326E4ULL, 0x39EFBC13B481EE5BULL, 0xDF6C2AF2A0C9AF88ULL, 0x5108290AC879D814ULL, 
            0xE89E5BDC1ED740C5ULL, 0x8C941203CB92E79FULL, 0x2F73240227D9E71CULL, 0x79E14BB81393CBC9ULL, 
            0x3AD6A362BE3EB7B5ULL, 0x4ACA0EEEAD17A3C0ULL, 0x173695C16456192EULL, 0x21BF59CFCA8A9CB9ULL, 
            0x64E6932226B45D87ULL, 0x2FF7011300CA4C01ULL, 0x6F84BE6A79B1AD31ULL, 0x0CC56562B717144FULL
        },
        {
            0x171A0ACC928C49A0ULL, 0x89B22C35E2036BAFULL, 0xF9002AF17E399021ULL, 0x2DECE4E2F3893C48ULL, 
            0x51A1A1AAE5C8EEA9ULL, 0x50D10671D554B814ULL, 0x97E0894E8D918EEEULL, 0x9DF89BFBCCFC1487ULL, 
            0x3AD79A2F77BC697DULL, 0x54DD57F582BA3677ULL, 0x3DF32496D98FC551ULL, 0x4A0D6CEC4DC6CE1DULL, 
            0x75A3951F6159B651ULL, 0xEAFD69C26B392CA5ULL, 0xE3D4B27CDD6E9573ULL, 0x6C0F25838B70B97DULL, 
            0x0482DB1D11C97F64ULL, 0xEEE3088D079FBA46ULL, 0xDE639B7E049F4EA1ULL, 0xDACCC248D3B8FCDDULL, 
            0x188BCA7AC4496C8DULL, 0x66A2C2DDD83BD620ULL, 0x2E4046FF6176599EULL, 0xCB8FFF81CFC3C627ULL, 
            0x47020F038A78B0CFULL, 0x59A7D9AC59A08A93ULL, 0x6484D47EDBA724B0ULL, 0xA87D342E2FD65BD7ULL, 
            0x66C9B13131F5C06CULL, 0x62D22A8DFD57E909ULL, 0xD9117A509A9BFB8AULL, 0x9F4B0918DA50B705ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseEConstants = {
    0x0169F7717AC5EB4EULL,
    0x68EF7FABD455FCCAULL,
    0xAF19E9556535A41FULL,
    0x0169F7717AC5EB4EULL,
    0x68EF7FABD455FCCAULL,
    0xAF19E9556535A41FULL,
    0xF977EF8161BB12AFULL,
    0xDE784CCFC16BFB0CULL,
    0xD8,
    0xDC,
    0x8F,
    0x92,
    0xBF,
    0xCF,
    0xD3,
    0x94
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseFSalts = {
    {
        {
            0x2E37FA848696DE90ULL, 0x99450DAC374C4831ULL, 0xFF3F53E9CB8D55A4ULL, 0x5BC7308CAD17ACD6ULL, 
            0x029B1A1A5683E909ULL, 0x1C8BA157F7623264ULL, 0xBD32FEE92A4D7027ULL, 0x57B0798C9DD24E90ULL, 
            0x46C7FECFEA45233FULL, 0xD7888A0285ADF947ULL, 0x403AFD49E10F6103ULL, 0xA4BF474B46E46675ULL, 
            0x6BE8EECB35C8E5EEULL, 0xEFDD638AF30C6EFEULL, 0x1C8BDE58B7720ED2ULL, 0x813F2FFC626BB306ULL, 
            0xF15F4D8518ECE628ULL, 0x91DF621625121F20ULL, 0x75288F1588D4020AULL, 0x6ECA8A94F7EAD9D3ULL, 
            0x73B15001ACAFF3FDULL, 0xA125A9B294051033ULL, 0xB06E0189584AA562ULL, 0x9094E31B8D1BCE7EULL, 
            0x33C4846C96460725ULL, 0xEB62C250583027ECULL, 0x6025D7593E17C130ULL, 0x795D28EF6EDAA847ULL, 
            0x9AB18B0D981EB057ULL, 0xE61DE97EC5B5B6BBULL, 0xE111B1D0657AA8E5ULL, 0x1B2D7E06AC5D8A35ULL
        },
        {
            0x11C5489700BDC894ULL, 0x7E8DB882A7FE2D8CULL, 0xDEEE6E2C8E5C30F6ULL, 0xDE956C44EBB4B9C0ULL, 
            0x6621B3FEBD1EC355ULL, 0x5D056C1094939281ULL, 0xDC050D477D7D1DD5ULL, 0xDC347EBAF8B91409ULL, 
            0x5BD87F5B2FDFD93DULL, 0x044E31A3ACF03503ULL, 0x6157D13EBFB79F98ULL, 0x9F74F4265DAD60BFULL, 
            0xCC37D0550C8F0332ULL, 0x67F6994489450222ULL, 0x4A2B3FCC71478228ULL, 0x0064717D3D22011AULL, 
            0x1169EBE5B53B38F6ULL, 0x6EC33856CAE13596ULL, 0x60E4728487E2CCB3ULL, 0x008B713DD1523307ULL, 
            0x185C69D033BC46E0ULL, 0x31DCE26FCAF67B42ULL, 0xA31F40A2BBED7433ULL, 0x25DC82B2D42E04C3ULL, 
            0x67E9C66037EDBAC8ULL, 0x9E381CE6C9FB563DULL, 0x2773A2B59649C0C3ULL, 0xC8EFCA3C931E714FULL, 
            0x176E9B1826EEF3A8ULL, 0x5F1AB894F417A0FAULL, 0x3C341BBB41942436ULL, 0x1D368227737831D1ULL
        },
        {
            0xA9F8FCAAB48BBE45ULL, 0x5095091CDC71C449ULL, 0x8DE7683D24D8B733ULL, 0x003736C3D02C2075ULL, 
            0x9777BA428DA5C142ULL, 0x224A5B92DD712BEDULL, 0x5D541A2ED662D49EULL, 0x7713DE33D8E1BCECULL, 
            0xFE5CF7073677B13FULL, 0xE09C2FFBAEC09DB3ULL, 0x60940171F3F883E8ULL, 0x2DEBF532E47B651BULL, 
            0x326F1D99E2E60B49ULL, 0xF117A397C1B82A76ULL, 0x0F67528A8922B863ULL, 0x3D21E884556EFE82ULL, 
            0x1464EFA68E177A66ULL, 0x5E593D180517F4F0ULL, 0xB9B6BF81D8C10C19ULL, 0x9A0CCF2626BEA520ULL, 
            0x8BDC6F8CAF1E04F1ULL, 0xC410FC1E35C8D5E0ULL, 0x8743B90035D82A45ULL, 0xBDBC012CE951D746ULL, 
            0xAEFFF67E2213CDB7ULL, 0x0AFE3B00AC5D26C8ULL, 0x470629D9DA178BF3ULL, 0x70412D87586AF011ULL, 
            0xBCADADA635E3FF42ULL, 0x1688C0BAFFE4CCDCULL, 0x9C4CE30A80A623E7ULL, 0xEBE6563E7BF6E7C9ULL
        },
        {
            0xFBA07A31E8240FA9ULL, 0xD291A1885D25F3C5ULL, 0xBB547C00C2F46A88ULL, 0xA3DB1B8BE9569BCFULL, 
            0x37DCFB6DB4F103B4ULL, 0x3552EF2E5DCC0DE1ULL, 0xD077A6F9CB900121ULL, 0x63940AADFF0A23CAULL, 
            0x1E8036F4708A94A1ULL, 0xF87631EFB37E80D2ULL, 0x9873AAD5A16D2D71ULL, 0xD1B33702A5F4D172ULL, 
            0x8DF0ED1DB1BE3373ULL, 0x9F45BA02C09510B1ULL, 0x7C3B821A3834822CULL, 0xE3B957D6AFE5D80BULL, 
            0xF4ECE79658AF6689ULL, 0x86A0673D6D2F02EBULL, 0x2E4A664F9D207479ULL, 0xF3711487D9FBF7DFULL, 
            0x149AF162074E806AULL, 0x3534CA27912704E0ULL, 0x1D6D25FED967B17EULL, 0xEDD4B1113A76BC04ULL, 
            0xCA050538B33F2CEEULL, 0x893741E9A48F505FULL, 0xFF5756EEA6C1D35BULL, 0xE972327BD4D22876ULL, 
            0xB64856DFEE2ACEF7ULL, 0x43D51192C6F8BC8AULL, 0x24B0AE4C4BECACCAULL, 0x925AB3EAE4F5E2F2ULL
        },
        {
            0x83ABF36EDB41288DULL, 0xFA44A89019D9F933ULL, 0x5859DDF26958B9D8ULL, 0x76B4E232683B3D65ULL, 
            0x467664E8690472F1ULL, 0xEAD477E00999FCC5ULL, 0xE2EE6F0D18448548ULL, 0xE09DA2AEC4DD141EULL, 
            0x9C0986FAB654B239ULL, 0xEC5DB7A2ACD88100ULL, 0xBDBD2B1627B394F6ULL, 0xE227CBBB288E1DF0ULL, 
            0xAB601C2E671B8517ULL, 0x6E15322DE7CC02AEULL, 0xC9014CDFC0016FD6ULL, 0x0A87CFF97E207995ULL, 
            0x3D92FB234ABF0A2FULL, 0xA6D8BE8E7238F370ULL, 0x639BEF72D8530E7FULL, 0x3B3BC6AAB2A034E4ULL, 
            0x8CFDC30E3E5F6AEDULL, 0xF4C5E018A81C44D6ULL, 0xA838150A2EBDF88CULL, 0xEC7AAABEB27A13E9ULL, 
            0x9545045C62FCAD83ULL, 0x68D6C618E4C6BCBAULL, 0x19EB1DF568D2F5C9ULL, 0xC14908A3E6D6AF3FULL, 
            0x69A42188D630C120ULL, 0xF40E5D8E213B5791ULL, 0xF596029FAFA79DACULL, 0x63422689DAA8A227ULL
        },
        {
            0xF14580EB577D7765ULL, 0x267E78EE6872BD0FULL, 0xD2ADA6912FF37134ULL, 0x842FB9A48A969995ULL, 
            0xD4CD1353260F8E46ULL, 0x7D87C9A1A94E11A7ULL, 0x8B1864098CAF7CA2ULL, 0xE95F6BE44E905458ULL, 
            0xA3F17C7FF82D2256ULL, 0xE60219FF2E94B5B7ULL, 0x40AE0F86AD6E8DEFULL, 0x9B540F752164C6CAULL, 
            0x3DD73893C2A62524ULL, 0xB25DA63A2F149719ULL, 0x450A7C7232E0A2F2ULL, 0x69ACB400A03A652BULL, 
            0x4C1D807F38EED1B3ULL, 0x006705127E9679DFULL, 0xE327655975267727ULL, 0x8D8CF1C2560F4834ULL, 
            0x6C38B21B607A6104ULL, 0x763596004712D3B6ULL, 0x49E1A92F244519A5ULL, 0x6B984F2D47398B0EULL, 
            0x09969AF4BDB08D80ULL, 0x87AF331612153027ULL, 0x2A138369C79224C0ULL, 0x3546CF876A316266ULL, 
            0x50CEF24481587BA8ULL, 0xFD399356D3E57E63ULL, 0xF21D67DD1494BC66ULL, 0xE4F8AA85A78671A6ULL
        }
    },
    {
        {
            0xC5627BF8D5B21D99ULL, 0x46482688DA4AD8E6ULL, 0xE6140647FE868DC7ULL, 0xFCA11F472DB57050ULL, 
            0xA373E09F267A3290ULL, 0xCC46295B6F4A13C0ULL, 0x123058CE28999653ULL, 0x249D95BCE71B05C9ULL, 
            0xBF7405FC6CBEEDE7ULL, 0x5806907CCD0806DBULL, 0xD5E166857263FE01ULL, 0xF2C6CD39BD5622A3ULL, 
            0xFCA32E0D9FB81178ULL, 0xDA35F411805FA6C6ULL, 0x4ED98EC1A0937E4DULL, 0xC959C65F6410E4CAULL, 
            0x9EA77CAD6BC6F197ULL, 0x8582D60EFA13DF6AULL, 0xA7A32D276FE89421ULL, 0xB4F7DF58C7F2F999ULL, 
            0x28C267521A7AC6D1ULL, 0x5B1B35DE66D1AA57ULL, 0x2BA9CEB60B1F208FULL, 0xD15590203DFF9200ULL, 
            0x16E85A290F3F3A6FULL, 0x53185F84673075F0ULL, 0x4E58357D30BF283FULL, 0x6AD44970F0A2B004ULL, 
            0x77A798383F0E1522ULL, 0xED66A138FCDF42B8ULL, 0x83D2C160056412F0ULL, 0xA24914271278BA34ULL
        },
        {
            0xA1C5D478CEB3F51EULL, 0xD34852979C9EE22AULL, 0x4A4CA1B85044F552ULL, 0xC09DFA08A8C04328ULL, 
            0x493CB15286613C20ULL, 0x7D276C1CB8BBA286ULL, 0xE9BB7A179AA1A68CULL, 0x26117013BAE6467FULL, 
            0x4170EA3415F4F475ULL, 0xBEE87D58FADA4D7FULL, 0xBC6C9C1B3BB8F1EBULL, 0x34CDB0751D722FEAULL, 
            0xC46FB23E1CF74464ULL, 0x14EC3699A5F1A12FULL, 0xCC0B8F237F96AAC7ULL, 0x5F3B3A0124EF5063ULL, 
            0xDAD17905D3852EB9ULL, 0x24484941050C0ACEULL, 0xE351FA92270E3687ULL, 0xEF6137A39113C254ULL, 
            0x38210BC3D2374AFBULL, 0xF5A967F6557CD7F0ULL, 0x69A2FF0F092BC3E7ULL, 0x9B37114B3F0F080DULL, 
            0xE9674710A4B5B749ULL, 0x4A41B95D4FC86EDEULL, 0x773F42ED2099B26FULL, 0xE298DF976000669EULL, 
            0xD870DCBA046B7BC9ULL, 0x617E54FD7528564EULL, 0x8F3E8FF448C0AD68ULL, 0xFB899D660B5E5A77ULL
        },
        {
            0xD1466A2857E6FD85ULL, 0x3B1BC9A8D87CBF76ULL, 0x40C05F9B51DB888CULL, 0x5A5DB3AAAD9A275DULL, 
            0xB2511A5D590E18FCULL, 0x57DF5961ECA68378ULL, 0x776C614B61EE16C4ULL, 0x9C8422C8F1805E83ULL, 
            0x0A9E102FB32CE45BULL, 0xCF406405CE749B51ULL, 0x49C56693544519DFULL, 0x04A679535CCE9A24ULL, 
            0xB84DA6ED9518B162ULL, 0xB160AE01522161F3ULL, 0x1BBEC854844E2AD8ULL, 0xC65FE9EAEE16002FULL, 
            0xDEE168898B989DFEULL, 0xD4477A106ADED613ULL, 0xE651DC895A80D817ULL, 0xE05AE993984EF62CULL, 
            0x3F9DC4196376DA48ULL, 0x6FB6A78DC076A94AULL, 0x5DCFC5050448E79DULL, 0x94E70EC53134AB7EULL, 
            0x60078C5D5BE98745ULL, 0xACFB54A01C364D9BULL, 0xCB67E654DEC1AF16ULL, 0xD2FAC2BB3CF46FE2ULL, 
            0x97D1B0A41046445CULL, 0xBE137B6AB6580933ULL, 0x57A50CF34D278D84ULL, 0x8D434A3617866B7EULL
        },
        {
            0x31037C54EBE01D06ULL, 0xAE794237B3337E9EULL, 0x2A686F038CB89437ULL, 0xC2687E01E7DF0100ULL, 
            0x4988D8E58E352D7AULL, 0x468A0F3268BD97D3ULL, 0xC9E3FACDD40F8A2DULL, 0x2394AA0F9DAEAA62ULL, 
            0x425C73CA6479AB0FULL, 0xB8DF012967AB2917ULL, 0x6B6AA6B3502AA721ULL, 0x25BCFBDF531C64B3ULL, 
            0xBD6047B1A05F019CULL, 0xF8A013790FF771CAULL, 0x51411CE016761712ULL, 0x1795CE4EF3F4F049ULL, 
            0xC1822D8941DCD402ULL, 0xA2A457B9D92F71F1ULL, 0x42F80EA0871BC11FULL, 0xAA1E3E8B56DAF478ULL, 
            0x31C3D015B5AF59B7ULL, 0xB6BCC0088262097FULL, 0xE1A12CF0572AA566ULL, 0xA8FA644F138CFBC9ULL, 
            0x896E32A3CFD40F0DULL, 0x0C24E04688FAC4FEULL, 0x86C4D46EF59FCC01ULL, 0x4F5689BABC3CB6D7ULL, 
            0xA564618A448E2B86ULL, 0x7BD20BF41892DEF6ULL, 0x6CD46BCCCF8CA4F0ULL, 0x15439BB22242453FULL
        },
        {
            0x0A5F86623A5815AAULL, 0x0A904091E2B35A17ULL, 0xE68F8548D6C13876ULL, 0x3E1CDB7908AFA084ULL, 
            0x077DB5CD01938B27ULL, 0xCE58FCA28A95697CULL, 0x79A1C7C0748E49FBULL, 0x41A7F2A847A504E4ULL, 
            0x766D219046229FE9ULL, 0xA6D26050A303E813ULL, 0xB364A36B3136C278ULL, 0x3CF2E28157A7BDEDULL, 
            0xB9C2A33B36339BDBULL, 0xBEF76D6A92794FD6ULL, 0xE4C3FAE583B6094EULL, 0x5945BD92CCABEAB1ULL, 
            0x4F87E40C23D39741ULL, 0x95F272601382F0B4ULL, 0x3C36F81754BE3288ULL, 0xEA6AE0A04B0D239EULL, 
            0xA0641F071AAA4FC0ULL, 0x7FCAA3B9622D2054ULL, 0xAD49E23DDC26A5EEULL, 0x2DB78C2FA8997035ULL, 
            0xD5321A7C178D69AFULL, 0xC1DBB8B7B867DAA9ULL, 0xFE5B36DAAE4D3FFFULL, 0x47849F6EF7CFE203ULL, 
            0x3DAE3EA73060608CULL, 0xB91B8492A4F7E1F5ULL, 0x392AE7A238B26E3AULL, 0x677076830E5B15A0ULL
        },
        {
            0x7FD1A752DF04D078ULL, 0xB22641F0304F0A9DULL, 0x0A3113615262C572ULL, 0x087ED027584D8B2CULL, 
            0x8C2CF88D5A70E2E4ULL, 0x5E39830B5AD3F211ULL, 0xC19D49D8C0695909ULL, 0x85289C477D596278ULL, 
            0x565EE39C710BAC2FULL, 0x8D0B662CC7B24656ULL, 0xDE0AC089BDF2CD72ULL, 0x1A6D28EF5B1F8BB6ULL, 
            0xD98EA28C0B792864ULL, 0x10F3160375E825C2ULL, 0x5B9B42951623CFA3ULL, 0x0D7BE4103A3C2AE7ULL, 
            0xB9A0B857A69D1362ULL, 0x4CC9A5922DB9E4EBULL, 0x32C3A5E71B7BCD87ULL, 0x95C2983195E095BAULL, 
            0x867858607A477902ULL, 0x975CFB1C3F41390EULL, 0xF7CD8CE45A5DC1C9ULL, 0x6DE522F67E57A27CULL, 
            0xA3F4FC74D33B06C5ULL, 0x840E4ED6847AE5DFULL, 0x7C6AC90240E80183ULL, 0x3B7A87A284096CC5ULL, 
            0xB21E85D9228F5FAAULL, 0xED7B85061FC25874ULL, 0xE6CDC7FB5F17CA46ULL, 0xDC3D503217BF507AULL
        }
    },
    {
        {
            0x5265ED51D4DE9B9EULL, 0xA648C7AFB5E14F87ULL, 0xDB15A507A3B558D9ULL, 0x701AF6ED65A6FB42ULL, 
            0xFB564C3DA0C9207CULL, 0x31E961EDAD8112AEULL, 0x34870CC74B52B89AULL, 0x68610EA23A66451AULL, 
            0xF0CF6ADAF22F2B32ULL, 0xE076F453F50E1C12ULL, 0xA7E4FB1E4F613AA9ULL, 0x7873D47527939E08ULL, 
            0x1EAAB9322EF6CF4CULL, 0xFEAFB701B3806F88ULL, 0xA02C4474462A308CULL, 0xE6F34975CAB24E77ULL, 
            0x2362C2728FC9D188ULL, 0x16F03D0AEE17E81DULL, 0x033F279872910A01ULL, 0x89F13957DE15F4B9ULL, 
            0x2548E1BFD177CEC5ULL, 0x8DFEBFE3629C2921ULL, 0x7A54DDBD284D3639ULL, 0x856E54F934FAD012ULL, 
            0xA2375D0D6E6F199CULL, 0x533B7E5F76D59847ULL, 0x56EF3561003E8CB5ULL, 0xE485D0B74B680636ULL, 
            0x46A38D56203CF2F8ULL, 0xEE794685631E5871ULL, 0x0C6C7273F9F5B3D2ULL, 0xEEFBDC9600E1C664ULL
        },
        {
            0xA5BE8137A0C3797AULL, 0xCDDF43C8837D904CULL, 0xD6066BFCAAD5AE8AULL, 0x8E0D69A7EF17A5CBULL, 
            0xAD05FE1122403EABULL, 0x603379C99967FA6EULL, 0xA0949B9D8841DC52ULL, 0x93AE0FF8E6ACAC62ULL, 
            0x6CECACA4932FC30FULL, 0x16F3F7EA12290AF5ULL, 0xFE71654987882871ULL, 0x65101587871AEEA7ULL, 
            0x0ECAA4FBB9C204F0ULL, 0x188815D07474FCC6ULL, 0x8C32EB7D8A36709EULL, 0x616F4C6E942DA5B8ULL, 
            0x6C10340C0C395F50ULL, 0xA24F531F553018E9ULL, 0x7AB0F0163316B83BULL, 0xD53C76735300619CULL, 
            0x62A44AD419D048E5ULL, 0xBC6FB2F2C94FD2EEULL, 0xA70A38CF03D0FDE8ULL, 0x00139576FAB66677ULL, 
            0xE4A38C384DE23615ULL, 0xA030FD91F3C1F001ULL, 0x2BCB7F780B7733DCULL, 0x07BD917FDCC013BCULL, 
            0xB4C0E00D9D4152A3ULL, 0xC64B63EB36C9AF48ULL, 0x5CEC9C820E617116ULL, 0xF25DB97526004009ULL
        },
        {
            0x147846F5E93AA4AAULL, 0xD2FA2DB7038F9FFBULL, 0xA7E8BE80888581D4ULL, 0xA3C5FB9884E9573EULL, 
            0x49ECDBD57810EA18ULL, 0x97F657CFF51B04A5ULL, 0x01170B5493EC0C10ULL, 0xD943BF67005EDAE0ULL, 
            0xBE7C4232491B744EULL, 0xFE28F01E37A6EB2EULL, 0x11D24EC0106997B4ULL, 0x923A02084F54715EULL, 
            0x8CB65E5614FCCB76ULL, 0x2B4F57A8E64E928FULL, 0x1B59D1304F206892ULL, 0xA292C4F35159129CULL, 
            0xD0DC9C011C49786DULL, 0xD14D3575054801A7ULL, 0x1C3D80747B307C0DULL, 0x002E8A70165F3C64ULL, 
            0x86AD0356EFD8393DULL, 0x20F36B0CCAA55235ULL, 0x7739789FED45C225ULL, 0x960AD499BE48C856ULL, 
            0x5990CC9FC899144BULL, 0x02A030951F947C47ULL, 0xA77F6115975D5CDAULL, 0x7671383DA07D5B4FULL, 
            0x1417B5709ED99360ULL, 0x63C0BE06C6DD17EDULL, 0xA43F53BF45E36714ULL, 0x26A3756658517D0EULL
        },
        {
            0xE4C40D35E0168859ULL, 0xEDC25ADB80C6FEBEULL, 0x0550F2DFB07CB911ULL, 0x8241CDACEDF3F697ULL, 
            0x58F01C58638E4B8BULL, 0xE92727BDD20CC6A1ULL, 0x766DD68D782B1112ULL, 0xE7547053F8247A09ULL, 
            0x7BB639E2BDFDBB6BULL, 0x46D81BFBB57A9CC1ULL, 0xC49BA67761839239ULL, 0x47EDBA1E9EF5342EULL, 
            0x62D9886ECB82127DULL, 0xA28E9E979AAD8C8DULL, 0xD77C276355EC8008ULL, 0x7E5AB49429245905ULL, 
            0x9F5EC844037A0EBDULL, 0xD1D669A71527FC89ULL, 0x612AB7DD45A41D83ULL, 0xAC50D82DA68D2413ULL, 
            0x550313070EE2A60EULL, 0xF77347E95491E258ULL, 0x31C5395E6E3159E1ULL, 0x663C1CC356BED84BULL, 
            0xD6ADF816390A79D3ULL, 0xB0CC92B067D318E8ULL, 0x2D17B795F471C0F2ULL, 0x7E36E174A601FDDCULL, 
            0xF172D0F9E60E6B56ULL, 0x1F80169BBBB51796ULL, 0xFCC100BE2BC5E6B5ULL, 0x2F6472DE25CF26EAULL
        },
        {
            0x70E3D6782285DE54ULL, 0xF1851E7C5A3C0094ULL, 0xD43DE0710904861FULL, 0x568E54587927809DULL, 
            0x07069C875A029AC9ULL, 0x24A71C76765D933CULL, 0xF683A09EFA7FC91FULL, 0xDA8C81591EB14925ULL, 
            0x2B4A1465B389A614ULL, 0x746972766DBA200AULL, 0x5538BAF6C517C408ULL, 0x66E64D4F3F2EC09CULL, 
            0xAA66D4BD65FE876FULL, 0xC572FA156CB59923ULL, 0x6C64637DFE8B7EA0ULL, 0x533E81F620A3D0D0ULL, 
            0xA789616D37F8855DULL, 0xDE9586CE0CE8B034ULL, 0x4FCA2FE88FBA734BULL, 0x54DF407290814726ULL, 
            0xD22DB94930E4270EULL, 0xEDE0C07D1DB45D32ULL, 0xDB63961ECA28466CULL, 0x1C3C8D924608A346ULL, 
            0xC912864FD87B9E03ULL, 0x8708F486175DD70BULL, 0x2732B16A262E570FULL, 0x951892A2FCACF922ULL, 
            0xE6E6164BF4D91677ULL, 0xEEC0CEC55732AC33ULL, 0x7EC7F22F6285B6B7ULL, 0x6E7A440A31AF6D27ULL
        },
        {
            0x62932D0FA09DC1B2ULL, 0x57B640E3DAC3E4D7ULL, 0x562BCDEF8637A42CULL, 0xDA6E6CDC4DF1C1EAULL, 
            0xA81986972A514BC8ULL, 0x388E6ABB86CABEE0ULL, 0x51EF7FBEAFAA4A09ULL, 0x03339F512E4A58E2ULL, 
            0x4FFDFD87FAE3284BULL, 0x0840DEB4F729120FULL, 0x30B74AF97CD2CDF4ULL, 0x6AF91D7FA99558EDULL, 
            0xAF7A6D73CB2E9A8BULL, 0x3E27ED6DFEFD3BB5ULL, 0xFD56CDA68EA40B46ULL, 0xA9C14CB0AB5BFEDCULL, 
            0xC9B545D5C1FEAA36ULL, 0xF9864765F7D29C76ULL, 0x56E1F42D64AE922AULL, 0xDFB45E19EDDC18ECULL, 
            0xA24249BA62FB8E47ULL, 0xB6BEC7A5B4E3D4E7ULL, 0x0FB761473C83E048ULL, 0xBE045932B486745FULL, 
            0x1BCF716BFC769F62ULL, 0xEE478005D29676A3ULL, 0x921E401417C912D2ULL, 0xA07F4670F8F653E0ULL, 
            0xD793C2D9DA99996CULL, 0x260C454464EE1E08ULL, 0xD0B1EF2D847DD862ULL, 0x36C28A5A0892AE64ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseFConstants = {
    0x13502AB980AD4E98ULL,
    0x4CB7CF9597713CBFULL,
    0x85A0596BF8AC0C93ULL,
    0x13502AB980AD4E98ULL,
    0x4CB7CF9597713CBFULL,
    0x85A0596BF8AC0C93ULL,
    0x4EBB0F2B443AC674ULL,
    0x6AC2BB2AE30779A2ULL,
    0x6F,
    0xDF,
    0x8B,
    0x5D,
    0x95,
    0x25,
    0x81,
    0x89
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseGSalts = {
    {
        {
            0xA4A04655EF176079ULL, 0xC34F98D78524D23EULL, 0x02CEC7A4055E4B48ULL, 0xCFB52BDE05B5783DULL, 
            0x4F2D3B1C323861E5ULL, 0xB9BEB036D6B817C8ULL, 0xC1A7704FBDE582AAULL, 0xBF2D4A94F32B34EDULL, 
            0xF981932A368CD519ULL, 0x4CE88A161DC471F4ULL, 0xEC47702596604D49ULL, 0x13F6B6CA9E2555B9ULL, 
            0xB95A895938C6E2CFULL, 0x41ABCDD91901AC27ULL, 0xBC4951BC8A5259F4ULL, 0xC08DDD167363C9C2ULL, 
            0x627F81AEA2828655ULL, 0xEE67E1EA7A26C88FULL, 0x0EF5F7582C481E00ULL, 0x72ACE90E8F545D77ULL, 
            0xDBCAA7214A640852ULL, 0x819693B0F8A2E9A8ULL, 0x899DA007696450F1ULL, 0x30B996294B3EC904ULL, 
            0xD8150B4E42950F48ULL, 0x6A6AC498D2A6C47EULL, 0x656BBE39CC70DFE0ULL, 0xD66AE5DFF936A6DDULL, 
            0x388138A34D3FC792ULL, 0xCD876D412AE61D4CULL, 0x0F955D4831C5F340ULL, 0x3C084AE278598177ULL
        },
        {
            0x2FFB58396DD3C9AEULL, 0x679C968C10459F2AULL, 0xC366290CAD861D88ULL, 0x9DBF246FE4A6F5F6ULL, 
            0x1B8059B98B7BCD00ULL, 0x2FF587AE6120B92BULL, 0xC3A9108C44B562F5ULL, 0xC6464E8534B01783ULL, 
            0x96DA7999FC7F643FULL, 0x2B4A20A94348ED26ULL, 0xD3F79C06A749B030ULL, 0x9DC8E4E7EE1E7332ULL, 
            0xFFEEAC8CB2239CB8ULL, 0xF57227E699AD161FULL, 0x5647E13BBF3541E9ULL, 0x2B37BC3118D393B7ULL, 
            0x245481DE37C68B96ULL, 0x310AD6850DCE4E47ULL, 0xB9657FE9B9F8E22DULL, 0x8721C72AC91FB175ULL, 
            0x9BD3295FC5589C68ULL, 0x5450EF6A70FA3395ULL, 0x3655E0CC978933E2ULL, 0x3D941400AB9E7707ULL, 
            0xC6DA7CCBF7873513ULL, 0xC137921832C8FB9EULL, 0xE97667AEE3542643ULL, 0x160F16F0FDDB764EULL, 
            0xB4BCF5ED8CBFA596ULL, 0x74D89B65384C9FBAULL, 0x07BFCFCBD66259CEULL, 0x9EBBA97870CC7568ULL
        },
        {
            0xA2821C7F4C506B85ULL, 0x06802F26F284BB2CULL, 0xE16810C260B674E3ULL, 0xDFE6F9056B93FCA9ULL, 
            0xB186A4D14B2DAF87ULL, 0xDC8A91542C1923DDULL, 0xEFDD26DC7D46EDE3ULL, 0x3C19C81739166EB3ULL, 
            0x4946683D1DD5A72DULL, 0xDBC98F6E5D732740ULL, 0x18C381B5C1DE0E91ULL, 0x7D2EA0BA40643DEFULL, 
            0xEFA639683077E290ULL, 0x305173175DC5A461ULL, 0xC345A788E71C86CDULL, 0xA9653E3442921684ULL, 
            0x468E6B09924967D6ULL, 0x19DECDC09D7B1E38ULL, 0x83B15399A85AC2E6ULL, 0x0A34B803F875741FULL, 
            0xF264F9FCA7D66808ULL, 0x1D68550D87071A53ULL, 0x6E48781074DCBB24ULL, 0x0D8B9E3AC735F54CULL, 
            0x1ACC52BE1A62EEB0ULL, 0x3186B40EB4D546B8ULL, 0x90FFD6190E97E7E3ULL, 0x3FB997634339B682ULL, 
            0x02675C5D9657486BULL, 0x76E3DD55040FBF49ULL, 0x3A321948F0184932ULL, 0x38A2F072B26DDD63ULL
        },
        {
            0xBA78F0DE309A6601ULL, 0xA4CEE0E48FDF69C2ULL, 0x6335B8183384F999ULL, 0x426E852715A816E8ULL, 
            0x7456B106B4709834ULL, 0x89134729095DFE29ULL, 0x9AA27ABCAE6D3FABULL, 0x1090EC4015158DE2ULL, 
            0x7285DE9CFD2A5B71ULL, 0x7CFFFDF5E4289192ULL, 0xE74E7539CF5E3DB1ULL, 0xB98D5B1DE6F3C751ULL, 
            0x038F3F8E99EDE391ULL, 0xF2D85DD8B531F94AULL, 0xD9BB55041DB5E9AFULL, 0xB8DAB328A413EF45ULL, 
            0xF89D85BBB7E4532EULL, 0xDB9E58C4BC46F19BULL, 0x2DC040AAE2EF06A8ULL, 0x9DFCEDF24ADA0210ULL, 
            0xC8EB5015DED33796ULL, 0xFD87BAE4C1479D32ULL, 0x624BB087FD2E9064ULL, 0x33D9D2CA61E1CF96ULL, 
            0x0C608FECB3C9A11CULL, 0xD8D098DD03BBEF48ULL, 0x2D3667B690C4ACE3ULL, 0xBF3D5CC174C6EEA8ULL, 
            0x91BB9224EB7AC216ULL, 0x0E09364825B25B8BULL, 0xB5D4705C4589689CULL, 0x1F3FA816C91F3F0BULL
        },
        {
            0xB468B9E02E37B0A5ULL, 0x085AC41AF47FAB7FULL, 0xC77944185AA82AF8ULL, 0x34A65763AC54A4F1ULL, 
            0xED1333A44C78F4ADULL, 0xB742FE248BF65026ULL, 0x46BF1EF6CFCEF3CCULL, 0x013CB96F6333F485ULL, 
            0x83F3D92BB4ED2197ULL, 0xBDEA838B3A4C5DDBULL, 0x9B523400FA4B9D05ULL, 0xEEB5D67459800E22ULL, 
            0x77E6679A720984C7ULL, 0x28759B6F965294E0ULL, 0x89C2EFD7AD85E18FULL, 0xCF323408ED65D834ULL, 
            0x0C226D9ECACD15D5ULL, 0x7DC8026567275CBFULL, 0x6D34271E5A00238AULL, 0x9044863BFD031E1FULL, 
            0x63EA22A852F88497ULL, 0xF22894AE5F5661D5ULL, 0x67C59A50C4EBB8CDULL, 0x53D03D6E2C3B3C46ULL, 
            0xA2DE1FA641C62B0CULL, 0x03C7061CAE175800ULL, 0xEB6276BF9E2B89A9ULL, 0x4B729425083215ECULL, 
            0x297C3075991B72CAULL, 0xFE7514CCDAF0D835ULL, 0x9ABD78731C23970DULL, 0x544731A4D87ED736ULL
        },
        {
            0xCAEE282B3B74DA39ULL, 0x6B691B75B978E69DULL, 0xE491B2CBD736C83FULL, 0xF2493C5319E66002ULL, 
            0x55C0F15B18F18424ULL, 0x6F755BBCC8E67671ULL, 0xB940553B1A88FB3FULL, 0xCFB1AD9D5C282B19ULL, 
            0x130F0432E7AFA257ULL, 0xCDABBA142298128AULL, 0x7B147394DF9F41BEULL, 0x5E65B51559B8BB30ULL, 
            0x6C4BE5516337BCE2ULL, 0x6AB807819F1B33CDULL, 0x528CEEDEAAC1C83AULL, 0x8467CCF1B66D84EDULL, 
            0xD8DA953D301A0E5CULL, 0xF3A8AB3A5C3DF589ULL, 0x529BA6C81AA82A93ULL, 0x53C410F6BA4C43B0ULL, 
            0x9ACEF259A5DFA9BAULL, 0x7811D9B063363EABULL, 0x05802885A19076F6ULL, 0x6AF266416AD2580DULL, 
            0xBB91FFFC46B56439ULL, 0x3984974A55DD892AULL, 0x952D2D40D72E3D44ULL, 0x080AFA95155BDBF1ULL, 
            0xFE823953492570C3ULL, 0xE181980B82CFDE66ULL, 0xDB33BD4A0099E864ULL, 0xA9836EB054BA7398ULL
        }
    },
    {
        {
            0x817B1AB8B3453394ULL, 0x800E30E488C494D5ULL, 0x65E4E04AA75A49FDULL, 0x729ACBD73E959F1EULL, 
            0xA7C3B8062449C424ULL, 0x62FAA76916927BF1ULL, 0xFD3DA77F1BA0F6B8ULL, 0xCC138AB1018E304CULL, 
            0xB4EFCBA6F1995C21ULL, 0x4CD1B07754BA0EC7ULL, 0x06A5FB5AF8C32699ULL, 0x4C89D24C0C53FA60ULL, 
            0xC75638D35A982317ULL, 0x2B0244522321F7DAULL, 0xC849F1A8E9A81F45ULL, 0x6D23796680E25581ULL, 
            0x072F29589DF868BCULL, 0x1CAAB6928C47549DULL, 0x250A4E2720E80222ULL, 0xA5772734BBF6A5CCULL, 
            0xA20CD4DA1450E107ULL, 0xFB1F096D58F03288ULL, 0xE2CAB05EAF0FF1A1ULL, 0x38B573FE8C9385ECULL, 
            0x64952ACF59B55F7BULL, 0x46FDB8C598A86F94ULL, 0xA607756D379E38ABULL, 0x44A36E1E577EE5E2ULL, 
            0x885549EC552492A0ULL, 0xABA2842C8B0F7535ULL, 0x43D67F613552884EULL, 0x289B2E82F64E85D1ULL
        },
        {
            0x733AC85B7BFB3920ULL, 0x0637C39AD8C4E2A5ULL, 0xAC924ACAEADDAA60ULL, 0x58EE0C632582C7BBULL, 
            0x8590B08FEC8D60C2ULL, 0xA2154A1190900123ULL, 0xC6F5D72E2647C69FULL, 0x9F25614120CE6677ULL, 
            0x930EE63EDFEF9944ULL, 0x384D44FA705FC1F1ULL, 0x5A75C02384B187BAULL, 0x46270B60DC93F284ULL, 
            0xA31EC49465593E08ULL, 0x3D4886F65885942CULL, 0xCB277BD63AB4AB55ULL, 0x67438B78F44EF97AULL, 
            0x0118D03A8C2E4494ULL, 0x667AB9BFDA7AB4DBULL, 0xCD2C51E9EE7F1A2CULL, 0x716CA1EF9E9DEE46ULL, 
            0x0CD3C306CA043AA5ULL, 0xB4387A565F3B221CULL, 0xC60CF1F46C791EA9ULL, 0xB941505CE1467BC8ULL, 
            0x26CF3F73C550C095ULL, 0xE535F8D42D89281CULL, 0x0A1BBE3801D2DB42ULL, 0x7E2335853D83E58CULL, 
            0x374EC7EE5C775CD5ULL, 0x63907666BF367028ULL, 0xAD6F01AF7D09A82AULL, 0xACC4C6CF55056392ULL
        },
        {
            0x8904AFF40F2FEF92ULL, 0x670A1D1B4CF4BF82ULL, 0xB6B12A8B16CEBFCCULL, 0x4D55049C1271D1D3ULL, 
            0xCF6CAD460ED864ADULL, 0x1CCA027F465882D5ULL, 0x524F5862C6589FA8ULL, 0x56662A317B664485ULL, 
            0x581DB994CEA0CCF8ULL, 0x7C263CE6C5B87700ULL, 0x82CEEFDE0040721FULL, 0xD177242E26325925ULL, 
            0xB34734C183CF0D04ULL, 0xA01CFF06881948FAULL, 0x88466A348F2437C4ULL, 0x7DA90F382B1F948FULL, 
            0xCEA6B590BE0FF8A7ULL, 0xDE17E3DEF996904FULL, 0x5D9CD10BF296F0E7ULL, 0x2ADB33BF3249B5A8ULL, 
            0xB4358B36496D0D5CULL, 0xDAB68808A8212875ULL, 0xC3C3C8512C7BAB5DULL, 0xC51A4457E498B8A8ULL, 
            0xA03C766F8199E584ULL, 0x74F008ABB82F5668ULL, 0x31C892B49CD5EABBULL, 0xD94CF766EF5F9DACULL, 
            0x7015CAFFCFF0451AULL, 0x5BE75860F6B7E04DULL, 0xF47BF5C2140F4E5CULL, 0x19DD85FCAF5ED94EULL
        },
        {
            0x6A4AE6C91B651291ULL, 0x121558FA1F384F00ULL, 0xE302101CACF255CBULL, 0xD6B20D3107097F57ULL, 
            0x2A2ACEE7A4DBED49ULL, 0xB00197C4C700692FULL, 0x5028B288BED5BE47ULL, 0xF74B1633DDDBD6A3ULL, 
            0x775C7E69E4291033ULL, 0x7A63EBF1A167CCBDULL, 0x72453F52DD93B58FULL, 0x343BB644B9B569EBULL, 
            0xF7470AB3808D9A66ULL, 0xF7DC644C9B6FFA1BULL, 0x20495AAB0F561B14ULL, 0x32057353251A1367ULL, 
            0x574C21363C08CA9DULL, 0xD990F0A5BE51E9CBULL, 0xBADEB59F43500EC8ULL, 0x572A523837F46CFFULL, 
            0x0A5B410102800FCEULL, 0x6FB6CD575FB5624CULL, 0xCE3680CD624C3121ULL, 0x41599F6309153858ULL, 
            0x3DAA735AB0BF2254ULL, 0x6EA0B87DDF0EFFBCULL, 0x72BE680653A6D72EULL, 0xC8E0A9A188F51B9BULL, 
            0xB26A3E035C20804CULL, 0x0B60069AB6CEBA38ULL, 0x101F4C951CF8FA34ULL, 0x39887B0069D9F45AULL
        },
        {
            0xE27705A52D781695ULL, 0x6856B6E612C80445ULL, 0xE64701BCDA17B621ULL, 0x3E1547E3056E78D4ULL, 
            0xDC18B2DE34F16CDBULL, 0x394B415DCA683A91ULL, 0xEC7DE42C4967C837ULL, 0xD7544DC2808683C8ULL, 
            0xDD105B26F0308908ULL, 0x7ECA39092088791AULL, 0xF00DB0DAE3685DB6ULL, 0x1935934E9166AD94ULL, 
            0xB0CF478837A4214EULL, 0x1D86A78AD8BB98B4ULL, 0x545E35D42DCA2FA2ULL, 0xEF920EDA1A28286FULL, 
            0x4FCAC2C7C6405BCFULL, 0x3AE0C5B3B69B5F79ULL, 0x87CF7E264278DAC1ULL, 0x257DC2934B876921ULL, 
            0x3FFBD53EE22D3DDFULL, 0x63E0F6EC3F2EACADULL, 0xEED31D69FE29B917ULL, 0x192B437EE3F11EA0ULL, 
            0xB8156993B66B56A3ULL, 0x3184C918913D7318ULL, 0xD19D094CCAEFFB46ULL, 0xAAE2A4A2EAA90CCDULL, 
            0x84BB19BB956C785CULL, 0x7261E041210A80A6ULL, 0xDFE9E5DE51BF03BDULL, 0x13843F8CAF58D89BULL
        },
        {
            0xB6186B35938BE4ABULL, 0x1BCD1D40BAA125EFULL, 0xBECB3F460A26F312ULL, 0x0012368E33939757ULL, 
            0x621797CDA66B5051ULL, 0x871805179390654CULL, 0xD1CFBBB45654CE95ULL, 0x4897DC50599BFC68ULL, 
            0x314FD5E7A546B09CULL, 0xD08C933CA693A54BULL, 0x796989DFA7E98162ULL, 0xE4A37979513463D2ULL, 
            0xA18DD1A2B9D898FBULL, 0xCEDC05533AFA34D9ULL, 0xCD5DCA0346352A4FULL, 0x8C54C6E07E642C5BULL, 
            0x691A9DA2F4163CE1ULL, 0xFCC41B9967F3C8F7ULL, 0xE9C026B6E660DF8FULL, 0x2F8DA37B56BB7154ULL, 
            0xE3C5094061529689ULL, 0x6A9C9E644A533C01ULL, 0x8B9C139CFF959049ULL, 0xA0B143AB2E0D8C1BULL, 
            0x3EC26875B76071E4ULL, 0x13EA61ECA6AA0C4CULL, 0x58BE2D6CD2A8AE63ULL, 0xDE3A4058A0563849ULL, 
            0xC78B9609EF365F97ULL, 0xD827F55BF977D400ULL, 0x65FE7B5B2B6DFB20ULL, 0xB212CC6608452370ULL
        }
    },
    {
        {
            0x82CCFB9ADEF3437BULL, 0xA669A5A37E600AD5ULL, 0x87E9491B2E2AE5FBULL, 0x0A2AFF6F52AB2026ULL, 
            0x4EE76ABD0FBD2051ULL, 0x4DFCC2E5851B7FB1ULL, 0xB1F383A5CF7CB12FULL, 0xB0777E4FC9FD685EULL, 
            0x0B840A10E638FCACULL, 0xA61B5B40A428C763ULL, 0x6BB5318ED24FF2DAULL, 0x8E3D09A5E5002A02ULL, 
            0xCB5BE6C9ED644199ULL, 0x0B247CF173829840ULL, 0x8B15E92899DFA59EULL, 0x4C738FAE20E045B0ULL, 
            0x0015A99DE919327CULL, 0xDE4B70E7A50E4FEFULL, 0x98518F699C0E6A78ULL, 0xCD8C089ABA078E7AULL, 
            0x536079BDFA4BBFB7ULL, 0x21421DA7A6C07412ULL, 0x65AB16AD09F20785ULL, 0x0DC76A0BB9D7037BULL, 
            0x38E2BD87172DC626ULL, 0xDE6DAD3AC09FE7E4ULL, 0x2A4CF4C80575B363ULL, 0xF2B1304AC0B65450ULL, 
            0x6444EE8FFD296C5BULL, 0x21391B5DAC634B90ULL, 0x81D32298E4A3BDEAULL, 0x61E2D0E73727B01BULL
        },
        {
            0xF6F785B2E6038D0EULL, 0xA15BCC046C252419ULL, 0x7C27D15EA57F3B91ULL, 0x667E602E3E1EB9CCULL, 
            0x649E08802E693F0FULL, 0x8279B80BE39F1557ULL, 0x24F41C54E1A966F9ULL, 0x5B9A4B219262E858ULL, 
            0xF4BB94B03DD7E93FULL, 0x0617BE0C638A6C59ULL, 0x316CC9EC83FDD41AULL, 0x3D28939D190E1738ULL, 
            0xB0FC2D7F70A33557ULL, 0xE421916DA432998EULL, 0xC2CA47E9DEAE1A83ULL, 0x2D25F20DD665D9E4ULL, 
            0xA8308BCD7AECF221ULL, 0x1C4DA690E0E6C041ULL, 0x6D8C9F1D05713E96ULL, 0x013A9779632ACCE5ULL, 
            0x892F8C47E3EE3EA3ULL, 0x3F4D3DCBDBE423B2ULL, 0x2B01D09BC726F6C4ULL, 0x67F4C13E583963EBULL, 
            0xE6CB891807BD7B60ULL, 0x170E49C31CE49642ULL, 0x6B1D9345FD169674ULL, 0xE0D95D3AE82A068BULL, 
            0xBCEC54496D927784ULL, 0x5E598D24EA9B1F98ULL, 0x0C404CFB8499C468ULL, 0xC38CA501D608A0DEULL
        },
        {
            0xD88D2492835FAD75ULL, 0x605687AD74D0ED64ULL, 0x7405B2961EDFB32AULL, 0xEE58C0263E5670A4ULL, 
            0x968090E23AC60FEAULL, 0x17D7DDEABBC7983CULL, 0x6BB0685BB93E07F3ULL, 0xE9EF9BEBC3D25CBFULL, 
            0xDEE4ABACC627CAACULL, 0xA7BF6B17CB4438E6ULL, 0x39AC34E5AD86B02FULL, 0x9B8D4357C5643D39ULL, 
            0xEB4C61965C8E1AA7ULL, 0x7772B490C8BAAD8DULL, 0xDAF5FFF0445213BBULL, 0x570D7CF4E2305A66ULL, 
            0x4534C5AFF914520FULL, 0x273529F6D44C1C6AULL, 0x9B057955406EB9DAULL, 0x77C02BA86259B79FULL, 
            0x5EC6463CF08D86B1ULL, 0xBB5BF89200AE5A70ULL, 0x8C9E00BB00CA8C66ULL, 0x2D641F29439B8C80ULL, 
            0xB44D0BF2F8FA153EULL, 0x9E0797A367FB724CULL, 0x968C5B46FC2D7D52ULL, 0xEFCB980D83AD7C39ULL, 
            0x1525CA5E26116C6EULL, 0x758854C05E9AE518ULL, 0xBB1EC1151306D7CBULL, 0xA937D7025388394BULL
        },
        {
            0xD3452812422CBB8CULL, 0x7706C12EC4BBC20DULL, 0x232849965EC49B37ULL, 0x333CA298B4BF9447ULL, 
            0x2F40B5B8F73F4C95ULL, 0xA954EE272D28473BULL, 0x2E13A240737FA1B9ULL, 0x25653FD97F774D34ULL, 
            0x19DC9E0218DADBA3ULL, 0x57790031D1D9941CULL, 0x1F11F8C6BDF49A38ULL, 0xEB52BDEF56F34D64ULL, 
            0x6C26E20F20A30F75ULL, 0x4142FAD274209E53ULL, 0xE4DF594059C22DBFULL, 0x819FD8C2022391FEULL, 
            0x11954CFF5DC5FD8FULL, 0xAFA6D90B2870AF3BULL, 0xCE0E7B78EF74DB08ULL, 0xB3D50199E48AA23EULL, 
            0x83B5F4ACD6B7A17AULL, 0x128C0115CB67BEE3ULL, 0x57DACF4A77077566ULL, 0x9CE978540665BF5AULL, 
            0x5E1886E541276F06ULL, 0x481C534A596B9A74ULL, 0x66CCF0DF691099ADULL, 0x361DDF5EEC64A16BULL, 
            0xC350A4423605DAF0ULL, 0xEA9A86937AF6046EULL, 0x8B15FFB92B4F4143ULL, 0x199BB55D446872BFULL
        },
        {
            0x2BA64F41918EED78ULL, 0xF8516D457F1C6582ULL, 0x9358E0CA3BB20A81ULL, 0xA1F423CF9C5E5352ULL, 
            0xDCA8C08B7DFD2227ULL, 0xF588DF5E9499ABD6ULL, 0x950FB0FB7DC2FAABULL, 0xCA6D6A7294D6CA43ULL, 
            0x7C64880E0CBAA84EULL, 0xBF0F66C65B03E148ULL, 0xE53E9EB95A5541B9ULL, 0xB465CC1D0E3E9390ULL, 
            0xC2883EC0C7EF559AULL, 0xBBF0D249C0575CF6ULL, 0xDD2753672FEC067CULL, 0xA1E8BE18E92FB65EULL, 
            0xBC9A549B9DBF4D36ULL, 0xBFA522604E7078F7ULL, 0xFD091214B006B11FULL, 0x420F3018490E3767ULL, 
            0x5BA6D4EDFA50C6BCULL, 0x920290D34C04FA93ULL, 0x8B59E2D0960E68C5ULL, 0x3A96008ADFAE5F87ULL, 
            0x3557D9D8E7A7B004ULL, 0xFB36FEC0142637E9ULL, 0x9131CCA2DB3F2159ULL, 0xEE94CD3022FB89F6ULL, 
            0xD57A2D2EEFAA662CULL, 0x22FE417EC4571C88ULL, 0xA5A3D78759DE6457ULL, 0xE4C3984C8D814DE0ULL
        },
        {
            0x99B578AC9177B4DBULL, 0xA4DB29F12F81C117ULL, 0x0A9C491C720A214DULL, 0x63C6E7D99D4D1668ULL, 
            0xAA25C2D35C9691F0ULL, 0xBFF0CB708FF24041ULL, 0x59F29A824E1E7795ULL, 0xE6BEAC27AC59B6C7ULL, 
            0xC6971ACBD8B28C5AULL, 0xDB7FAED3C8869313ULL, 0x20BC62A820A57B92ULL, 0xA68C26108E2208F8ULL, 
            0xD166C5F6CEF5FD80ULL, 0xF0F8084EAC17D406ULL, 0x15081BB3FDE84E2FULL, 0x21430A81D88D29F6ULL, 
            0x20383D29C64A6CC4ULL, 0x45ACDFB5130A2691ULL, 0x5AAAA6276F9950BCULL, 0x5C242169A15D2D73ULL, 
            0x9B37E9BB514AFD49ULL, 0x48B58CF20B44034FULL, 0xEAAB8E568D3706DDULL, 0x07467C51B45C59CBULL, 
            0x79873D894F11638AULL, 0x88A8D2E62EAA8FBFULL, 0xBBEB3ABFDA0A7CFDULL, 0x239DAC47DADA547DULL, 
            0x0E372339D30E75EDULL, 0x48155E621CE05039ULL, 0x741BB86A60912420ULL, 0x8ACD07C63DC30180ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseGConstants = {
    0x76BEC30AEC38BBECULL,
    0xDE4EB4D7A003FE48ULL,
    0xE74864AA2ADCCB1AULL,
    0x76BEC30AEC38BBECULL,
    0xDE4EB4D7A003FE48ULL,
    0xE74864AA2ADCCB1AULL,
    0x0271AEA1B5FFFBBFULL,
    0xAECEF72050599AA8ULL,
    0xB8,
    0x87,
    0x52,
    0x2D,
    0x66,
    0x9D,
    0x55,
    0xD7
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseHSalts = {
    {
        {
            0x6829F2B0D1C73404ULL, 0xEE37CE04A71E255BULL, 0x38BA57E25C784E97ULL, 0xF21B5D9BD41D43D6ULL, 
            0x5E70D2BF68EC146EULL, 0x7D2BD09B0A6D44AFULL, 0x650D2BF87CFC8C16ULL, 0x02BA121AC131F331ULL, 
            0x2971BCEB83DD5DB7ULL, 0x37CE7D3B50CC10C7ULL, 0x415412B10455A01FULL, 0xDCD65E25C8E7051CULL, 
            0x53ED5DDD07C82B07ULL, 0x486EA24E2BCB98EBULL, 0x7B5658028C932A99ULL, 0xAAD3B846F363B140ULL, 
            0xC8507FB31B8720F2ULL, 0x8787AE192512F169ULL, 0xA5C4118EDC8DB2CDULL, 0x044F70CBF503121EULL, 
            0x90F13DBC715847F8ULL, 0x2B21B4C41CE38E57ULL, 0xC01B342A2F974854ULL, 0x9B81C5B5EF9DE302ULL, 
            0x3DD2C4C29B172C8AULL, 0x8956DC8086C32DA6ULL, 0x0943145930D20219ULL, 0x1996410F1902830EULL, 
            0x4CEC8C2B7D88A7D3ULL, 0x95303AAEE8356BF3ULL, 0xAA701D45A4AA0C07ULL, 0x89A3D59EE063C64AULL
        },
        {
            0x52F3334C386E3E9BULL, 0xC24E68CF382954D7ULL, 0xBCECD4B43002C9FBULL, 0x3DC72B87AF6192EAULL, 
            0x588231F07D6E642AULL, 0x4794F142F6E8643CULL, 0xBAE908E2A48D3310ULL, 0x8589E2CC0B51B4D8ULL, 
            0x2933B715B106D9C9ULL, 0x7ACF9961C2DAEE92ULL, 0x0BD833FAFA1DEDA0ULL, 0x2B398CDDDBBC9A34ULL, 
            0x4C9B5E8CEBA76251ULL, 0xD9AABD28E64126AEULL, 0xF9B66EE26C368FE5ULL, 0xC7F1DBAE10B25FDBULL, 
            0x87078F3D4EBACCB4ULL, 0xB8808B9C51E87445ULL, 0x91508BB1D31CF895ULL, 0x0FAC30B92FF7D125ULL, 
            0xD4D1067E6C17B054ULL, 0xF4E4C246F5AAC6D7ULL, 0xAAFFDE5407B7C4A9ULL, 0x97AFBD8946AE02BDULL, 
            0x345BF767453E6C4BULL, 0xBDA5D04E1F1264F3ULL, 0xD4270B3A37DB9C5FULL, 0xF73C51F96F9253DEULL, 
            0x59CE25AD132D9023ULL, 0xE25BD53E3103F644ULL, 0x46A79B0323F7FF60ULL, 0x2B591006A365D49DULL
        },
        {
            0xCCB5435260B969C4ULL, 0x6087379011C868A5ULL, 0x9B5156A6B86CB3E3ULL, 0x3D9965E60A1C3397ULL, 
            0x2789BBC83E1CBBF7ULL, 0xC9C3E67F68E86A45ULL, 0x171F78CE35C06F71ULL, 0x2DC19227FBE31F85ULL, 
            0x269E467B594860E1ULL, 0x0616DCA75CAE6EACULL, 0x055F4E41BB1E8408ULL, 0x848D47622608C20FULL, 
            0xE67D073FDCB119F2ULL, 0x4367C6E24438DACEULL, 0xC876EEDC83A9DB5FULL, 0x8B3435D50AC1B4FCULL, 
            0xFE03BFECABB72EA7ULL, 0xF11801926902C0ECULL, 0x689CC2232F828B0EULL, 0x010576E6A3BFF56DULL, 
            0xCDAFC5B0848D7C07ULL, 0x76E5667A90F6E188ULL, 0xC1FCDEF39B532EDAULL, 0x2A299048F4C0EF2EULL, 
            0x86FE00F807CC7D8AULL, 0x706DB83E1F72E43EULL, 0x580843C1C2E4A524ULL, 0x4F3EAA773699B002ULL, 
            0xB41A42B424D459DDULL, 0x07BDF6B0781776C1ULL, 0x78A88C15D6C3942EULL, 0x3BC6B50A4D346744ULL
        },
        {
            0xF5B90BF805426AAFULL, 0x19B261CD5B5A1B44ULL, 0x5F95BDB8A8866652ULL, 0x3112C4EDD57E4439ULL, 
            0xBBFE45D964159AA1ULL, 0x6F8274D97984D954ULL, 0xEA2436C820BA895EULL, 0xEE97F78CF2362C33ULL, 
            0xA744E030B4A62AE9ULL, 0x1BF60F5F1339849CULL, 0xE02D849E7A5B2392ULL, 0x29EC1153BDE36C3EULL, 
            0x295ACD0EBCBC356EULL, 0xAC86EBD839720073ULL, 0x8F9897D5D0E8634AULL, 0x24A291B4E0C3E819ULL, 
            0xD915516FEC114136ULL, 0xACC235068CCC9CCBULL, 0xC304B1E50CA2DACBULL, 0xCB1147B21334400BULL, 
            0xF09E7DE2CC421B21ULL, 0xFA9B579B60C47F37ULL, 0x68AAD780FB9A6C79ULL, 0x56C86093FF944B47ULL, 
            0x70CCA0467822B03DULL, 0x24709CAE93BF873BULL, 0x2366A13C6F0D3CA0ULL, 0x9ABA6FFB1E0590DFULL, 
            0xC17E83CE66893940ULL, 0x2D611F90BFFBF188ULL, 0xB9F3F61DB3F767C9ULL, 0x0973A9731FF1DB15ULL
        },
        {
            0x71354BA88C27A7D7ULL, 0xCC032596CC042172ULL, 0xBC9F32BFA5825E7FULL, 0x5923CE2DF6B1D2B9ULL, 
            0x538145E7F888A7B2ULL, 0x2E611ADE84B316DCULL, 0xB1C5770F98CD54ADULL, 0xB322EFDAF5B1968EULL, 
            0x33D03125013CF5EDULL, 0x1D190E7D1796B746ULL, 0x9D2F1A4F14AD94E6ULL, 0x90A556267F68A609ULL, 
            0x263AD4935A59ED98ULL, 0x9E15D84F909CB396ULL, 0xE2D47689A76CE4AAULL, 0x589BBDC54A58BB39ULL, 
            0xE5C1FC6CA43BEFFEULL, 0x757B3639320A5AE9ULL, 0x9A3938985A39B2B9ULL, 0x0C8EC4C48ABD2D5EULL, 
            0x2670D7629CEAF627ULL, 0x2F770ECD5C9522CCULL, 0x3684B20EE3FA0D5FULL, 0x9AB357903D802635ULL, 
            0xFF258409F2D1936AULL, 0xB39120F49E330B2FULL, 0x13E4455B268CBE28ULL, 0x58771303C3B6126FULL, 
            0x48BC783BCACD2A42ULL, 0x31820BB1B08ABD32ULL, 0x9C5E8D86CCDC6102ULL, 0xED362EB7368C1FB1ULL
        },
        {
            0x49507C93144473DCULL, 0xE130B87B7F273162ULL, 0x171E8C7F0DDDC958ULL, 0x74D3E3B9CBE2C52EULL, 
            0x4097C47E4DE79604ULL, 0x32DAE9D914CBE24EULL, 0x5765F18B5465A890ULL, 0xE04F0F1373F55C00ULL, 
            0xE7BBAE963B0CA2D3ULL, 0x09927B240DDF1A26ULL, 0x2F40BC72A63748DBULL, 0x0ACB2552E434005AULL, 
            0x08E0DBD4976D3DEBULL, 0xF0DB9217393B4DC2ULL, 0xA934048C866A0358ULL, 0x49D1206C505A1C2DULL, 
            0x477DFC3F40B2D02CULL, 0x4FCD44030F7F0AE4ULL, 0x595805AED9CDFE1FULL, 0xA79DB04EFA23E9B3ULL, 
            0x8BCE3863984188F3ULL, 0x9756B9A055D87479ULL, 0x6A0A7C98A2B7FB8CULL, 0x156C94CA336C4963ULL, 
            0xF5CC6A67326F004AULL, 0x6496C3463F15EA87ULL, 0x3C3BA1602AA4EE79ULL, 0x6F380B45E1DB28A0ULL, 
            0x6656DCF1F5F6378CULL, 0x76AF4E3042199138ULL, 0x05E41E9DF27044E8ULL, 0xD622823C5FA798D4ULL
        }
    },
    {
        {
            0x1AB433F7E74E6707ULL, 0x145A1DEF9683ED28ULL, 0x2A09F26959374187ULL, 0xBB89AE51DCA0A370ULL, 
            0xC9C3F1BB18FB02E9ULL, 0xEAB7C07A03B1F043ULL, 0x150C8B1351ED4892ULL, 0xB90A041E05A538CFULL, 
            0x74E3071650C8360AULL, 0x1810BC7958C867BCULL, 0x894FC6D6DAA812B7ULL, 0x169C61E0303B5C10ULL, 
            0x0EF993537A1F33FDULL, 0x74978EB777768D8EULL, 0x6B9D8D07FF2B8F0BULL, 0xB92D2A8AF9D540F0ULL, 
            0x6079DB0683DB57B4ULL, 0xDA372630E88D4967ULL, 0xE8612F77B324E9B9ULL, 0x8ECF8EC8796DF1FCULL, 
            0xA2653828FA05906FULL, 0x193C2978714A0C34ULL, 0xDE929EBE61A0D939ULL, 0x1045EAEB6021BF5DULL, 
            0x7D274E0F847B52D0ULL, 0xF3BFE3D6C491DCFCULL, 0x392B8FDE098DC074ULL, 0xBC191E04E674A959ULL, 
            0x0DC05FDCCC35BF0CULL, 0x7DD4F3B990DBE352ULL, 0xC07AD2E7C47900FFULL, 0xB54C437BDCE81AFCULL
        },
        {
            0x011BF08A44B1923DULL, 0xF43910316326391CULL, 0x90F760D6A7A5C24AULL, 0xBD04DB8203035B3AULL, 
            0xEC411DFA455E66F4ULL, 0x1C45B6D06F6C5B08ULL, 0xCF5359E61902F8C2ULL, 0xDB3009ED3FE2A6B4ULL, 
            0xE1D4BF12AF3D505CULL, 0xE9E1BEA9B5930580ULL, 0xAC5D021A5B7D2448ULL, 0xDBB67C633597DC0AULL, 
            0x8C3F4EC009CBD22BULL, 0x1D707E3AFA5E7FDBULL, 0x43ACCC93C8FC12A7ULL, 0xD3EEC980B3D3B601ULL, 
            0x62244A8002D18DE6ULL, 0x4728E59882D45ECBULL, 0xF51CB27D63287BC0ULL, 0x19DA5CEA0A3C9A08ULL, 
            0x0052852DA580D269ULL, 0x6213BE43ED345BDAULL, 0x277BA46F6C21E585ULL, 0x8F83F71373B3801AULL, 
            0xA84F975583699873ULL, 0x4634EAFE91E36F8EULL, 0xC11A598FCB59CB47ULL, 0x78D10BEF403236B0ULL, 
            0xA3F66CC0CE2E26F5ULL, 0x52A0B717BDA248BAULL, 0x430FD97E58479918ULL, 0x578C4BCEFC6896C0ULL
        },
        {
            0x0FA28975D69DA008ULL, 0xC9B8A1B80094357EULL, 0x3585C434AD28AE09ULL, 0xAF24B1D0B33E0CB3ULL, 
            0x2A49BBC9AD7E1D96ULL, 0x22A89F7E10F3EF68ULL, 0xEF1FDA1D8F61C326ULL, 0x2D823EEFBE31B939ULL, 
            0x906FD840CB084C84ULL, 0xA5DBDC0CD7A0E09DULL, 0x5FDE1B67A08AA18EULL, 0xCFE41713AED033F9ULL, 
            0x705C9CA02ADC8D8FULL, 0x4D9A554E97A82EB4ULL, 0xD7F40308CB027F79ULL, 0x71F5CB0CA021DBC3ULL, 
            0x8AC18EEB74AE8749ULL, 0x7524FD4841EA1A9EULL, 0xC6359C8F7C43B3A2ULL, 0xDB1CAFB06067D10AULL, 
            0x11A6A9FDC420E782ULL, 0x964C50432AF05379ULL, 0xFEA77C3FCC75B258ULL, 0x3B54F7D7289398AEULL, 
            0x68C106F7BCF3202CULL, 0x65838412699E6AFFULL, 0x661A8B0C425417FCULL, 0x69B510F815A86C28ULL, 
            0x94C829FD8925477EULL, 0x8CC42A09E0E5522CULL, 0x47E4BD46FA1B9932ULL, 0xFDA7DE75830AD235ULL
        },
        {
            0x8ADA00F9A4189B35ULL, 0xCFE5428EBD901727ULL, 0xD0AE172A9D4F919AULL, 0x3D98664C2B091264ULL, 
            0x9104B7CB1190427AULL, 0x71A684199AA99871ULL, 0x42852FD1B85E73A0ULL, 0x58129D431FE559B8ULL, 
            0x6CFF43EEABAB452FULL, 0x4505BDCACC70FCA1ULL, 0xFBFC20DCCA4EB8B6ULL, 0xF48ED228A8DD3EDCULL, 
            0x602202D40C97F19FULL, 0xB5FEDDF8D59773BBULL, 0xF0B362879E884F94ULL, 0x8BA6CA55896B3E14ULL, 
            0x3F667158C65C3C74ULL, 0x85429428A6AD857AULL, 0xE9CCC645FAAACBA3ULL, 0x3E2492F01EC35B5CULL, 
            0x424C3E5F621601B0ULL, 0x8EB5BE366B73143EULL, 0x6A6AB158B9783976ULL, 0xF8DCC05B41985859ULL, 
            0xBAD394A37CB7345CULL, 0x244A84C1C5A877DBULL, 0x449247C1A43EA7A7ULL, 0xF1D96B937A0AD382ULL, 
            0xD8418648F012F3CFULL, 0xEA39AB9B15873B80ULL, 0xC416A8204A4759F7ULL, 0x2561E853B806EEB0ULL
        },
        {
            0x4268785564211716ULL, 0x9507332A23FE8499ULL, 0xCB1CD37E2CC73DBCULL, 0x8121B55EEC0AD791ULL, 
            0x3AF03CD7D3CC3041ULL, 0xCFC9E7786F99E972ULL, 0x519F3393AB961B18ULL, 0xA8C7DADF22D5781EULL, 
            0x8A4E927A1CABFFC6ULL, 0x412BAE97F2AB4764ULL, 0x94411EF0C0055139ULL, 0x4707AA377AA7895BULL, 
            0x86E4C28AF08B8997ULL, 0xDDCAAB4FA8BD95F3ULL, 0x1CE706AA350B03CFULL, 0xF57D019C4DBE38C4ULL, 
            0x7C97AEB2D56618D3ULL, 0x0AC46054FB8452DEULL, 0xB76023E356195EB8ULL, 0x90093873E0A58142ULL, 
            0x00379240FAD98A1AULL, 0x49E132E4EA49D927ULL, 0xA446AE67BE201934ULL, 0x6752656EAB7EB965ULL, 
            0xC529A12C54B4C464ULL, 0x0F5174C43483CDCCULL, 0x60E4595D9CA478CFULL, 0x55019AAEE1BDA03EULL, 
            0x256E69CBB0CE4882ULL, 0x8D5EF69C120F6627ULL, 0xF1A433DDB07E0227ULL, 0xADDC3189FCFDE0BFULL
        },
        {
            0xAABA3B94E25727B4ULL, 0x7B11B416179E7068ULL, 0xF55EAF1199FB120FULL, 0xE57B011001981865ULL, 
            0x8D8FEEEE3732C7A4ULL, 0xB8F08E1BA30678CAULL, 0x08289784F14FF974ULL, 0x8ED242C95DD64234ULL, 
            0x7ACE0B99625DC82AULL, 0x6F7F20AB402B3B65ULL, 0xE1479F5E44E2A130ULL, 0x863FCADB8A45CDECULL, 
            0xC00A973BA8940D3AULL, 0xAA44296EEC0931B8ULL, 0x82F34896996C7182ULL, 0x08DB8D4A0C6CF68AULL, 
            0xD306B87DF10284D6ULL, 0x5323874AB9CA4EA4ULL, 0x9E92BF3356B67473ULL, 0x94ABD07F4B0A9E94ULL, 
            0x877F4ED742EA5EDFULL, 0xFB28156ED3AF3425ULL, 0x3F15DB2B16948F16ULL, 0x06A454957154BF0AULL, 
            0x79A82F2A67739491ULL, 0x945F8485443A9D39ULL, 0xE787E2A8221D5DBDULL, 0x5BAD043E86716502ULL, 
            0x3959D267213EFA62ULL, 0xB1DF479D88411E70ULL, 0xA2E718B3659548AFULL, 0x735E0837A353FDAFULL
        }
    },
    {
        {
            0x77E1E1E17EF828B7ULL, 0x0E9AA6FAFF523CE6ULL, 0x79991AC6A6C7D73FULL, 0x5AC75354FADA23FEULL, 
            0xA497F2544FD33B5CULL, 0xA610F22E2D988FB5ULL, 0xDAF3372618EFFDE2ULL, 0x143B9EE6BB52D575ULL, 
            0xDE989C3F09E36178ULL, 0x35264956E99DA2B9ULL, 0x5B659A2B7C045B01ULL, 0x43A82D39FD3CE097ULL, 
            0x2AB153F3650F7543ULL, 0x57B29E8D3A157FCFULL, 0x6EB07CFBD04A297AULL, 0x78EB75A1B04490D3ULL, 
            0x17C96C859FDDA638ULL, 0xA497B5908769BD94ULL, 0x3DC565F966F881D4ULL, 0x63F32853A644067AULL, 
            0xF3DCB33F40770346ULL, 0xD0BC00A20C8D9403ULL, 0x2DE1742493CF00BFULL, 0x2F3BC78678F94170ULL, 
            0x5B01AA4657052619ULL, 0x1456FEF37312EC00ULL, 0x62B93F6B096A59B4ULL, 0x7FBBD5858A403E0CULL, 
            0x6CCFD5A5215673A2ULL, 0x0DFB963398396D02ULL, 0x2C2E06BE4019173AULL, 0x6E73FCDB5FA67F77ULL
        },
        {
            0x6FA8CBA65150E260ULL, 0x4E5D959579E13B34ULL, 0x20228D5F148244A2ULL, 0x66FB18037AA39DE9ULL, 
            0xBACFC34AFECE12ACULL, 0xDE7E03EDCF09DB7AULL, 0x6758F8586F605DC4ULL, 0x98D5077A14900C71ULL, 
            0x3236F2D6326C251DULL, 0xC5CB3E9C9E91BEA6ULL, 0xBBD0E32604B53CE9ULL, 0x3AEAB7E9D85F175DULL, 
            0x6A99212F5643B144ULL, 0x55FC634F3627A176ULL, 0xD994447628660E5DULL, 0x9DAC0B53D3AA2CCEULL, 
            0x38CD71FDD247859BULL, 0x9D6F214B7771F76EULL, 0xCA8A78F7219158B3ULL, 0x878BC64C756ED69EULL, 
            0xA754B018B2A9DEADULL, 0xF8B75AF350F6664DULL, 0x86C68D8A934501EAULL, 0x141245566CC981E8ULL, 
            0x0A3D3AA0DF2B1DE5ULL, 0x34EBEFF4C9B8840AULL, 0xFC4408B5819250C3ULL, 0xBD90EAD34789EA0AULL, 
            0x894057037F0CF499ULL, 0xD55704E089A9AAF3ULL, 0x33A526DAEFB0634DULL, 0x8491F2A605923059ULL
        },
        {
            0x1AF258BAAB910DF4ULL, 0x381DA3E739D3B5C5ULL, 0xFAA9AE7507D7A193ULL, 0x8DB70DE4915921C8ULL, 
            0x6D0A2E67415787C0ULL, 0x3144F91064DCC809ULL, 0x041F2DD34F14F225ULL, 0xD628B1479FCDA1BEULL, 
            0x9D7DE76E19E79CDAULL, 0xAF90044EFB95198FULL, 0xDA5289D2345F892CULL, 0x49640DFA73FC1530ULL, 
            0xF8949504E98F3126ULL, 0xF150F19BB63809C0ULL, 0x49214CC9EDF36195ULL, 0x9343CC50D6181DF4ULL, 
            0x5E8FD20AFF1378FEULL, 0x22219644C2F70E10ULL, 0x53EDB611C54DA9F5ULL, 0x2663080CD3936F16ULL, 
            0xC7A4506C3A614C71ULL, 0x32ECBD8C00B1FEF1ULL, 0xE667B202D77916A3ULL, 0x71EB17543C9578E4ULL, 
            0x2D1F689BE137495FULL, 0x7F8644D88541D0D6ULL, 0x3EC4D651C1B87394ULL, 0x622592500B35E525ULL, 
            0xEB9A7BC14B7599DFULL, 0x91423820DDD027FDULL, 0x3E52AE0DF145D0D3ULL, 0x970180DD9DA531F1ULL
        },
        {
            0xF5F8C7A694731D58ULL, 0x2F647025243C4F89ULL, 0xBFB454B344A7F2BFULL, 0xD5F050CC5E75FFFDULL, 
            0xF38B3CFE93E77C69ULL, 0x5A00236FC14F50A9ULL, 0x5CD396AFAEA8539EULL, 0x1121E93286BBF9F1ULL, 
            0x6349BC4F7A681060ULL, 0x74939E365A13014DULL, 0x5ADD0F92E04ED2EDULL, 0x279A693C586DD53FULL, 
            0x599636B56CD807FEULL, 0x9CCABFCF42B51649ULL, 0x46B83E20F229DA4AULL, 0x63AFB4A655A4B2B9ULL, 
            0x3F99963D50DF76ACULL, 0x172790BB68E393CAULL, 0x853F3406AE4D3CA9ULL, 0xB353B68B2790580EULL, 
            0x61F6BB8E479191CAULL, 0xB0E7B4C912672B15ULL, 0xDFAA4D8B16D86B47ULL, 0x8BDFBDB7B1041124ULL, 
            0x63B2975D5846B9A9ULL, 0x9A695F103CB71EF1ULL, 0xD28FFDED73B1F668ULL, 0x6F9EE8892A45F15EULL, 
            0x319BABEF918B4C54ULL, 0x9254919059299C21ULL, 0x3E56A294003775CBULL, 0xB704B8C16F1C501EULL
        },
        {
            0x019F74AF7F7C4399ULL, 0x214484FFB4FD9242ULL, 0x24EAC9F15A5F0FBEULL, 0x6BFAEA89D6AD98CCULL, 
            0x48F0BCC1219E9044ULL, 0x59A18272C11CECD9ULL, 0xC5CA38175F444C1BULL, 0x317B3D90A7A24DB0ULL, 
            0xE5AD52925DA422BEULL, 0xC3A7CF3640B901E2ULL, 0xD251755672E2224DULL, 0xBA8F248347084BDBULL, 
            0xF47B30F7D1BA1622ULL, 0xA8F3FA2918325BA6ULL, 0x9E5F37A6E0E6E6A3ULL, 0x2095FD6BFF47712FULL, 
            0x82D349B5E80E5606ULL, 0xBC512583A373AB22ULL, 0x7BD8A1D0FCD3946CULL, 0x4867255852CAD61BULL, 
            0x05D7A569191FC543ULL, 0x6DC2752E0D43D2F9ULL, 0xC3FE70F89C176313ULL, 0x5A30D9A5CEC27B96ULL, 
            0xE4BD6DE5C60F09D1ULL, 0x8FF3F32D71339DEFULL, 0x3B029C2696BCEDDDULL, 0xA302219F71DAB4BFULL, 
            0xD3AB8BC573E72B34ULL, 0xA7E5768BBB22AE36ULL, 0x5222136BF149B960ULL, 0xD2849C66891CDC7CULL
        },
        {
            0xCAA10706EA1718D6ULL, 0x92499149346472CAULL, 0xD241EDD7789CAE7AULL, 0x3412AB9D9DA19197ULL, 
            0xF0CC589093EABD67ULL, 0x81326B03600F9B9AULL, 0x014D20D2CD3EFD40ULL, 0xEAD910C6FD770EFAULL, 
            0x4A3AA8689328ED5AULL, 0x11B8FCC5C0FA3838ULL, 0xC9A972E5A61BD19BULL, 0x836D4FFC4AA7234BULL, 
            0x07476DBEA11E959EULL, 0x6C5EB9C9A3949EB2ULL, 0x1790A9954A810785ULL, 0xD6563080873263A2ULL, 
            0x30B23505B615E2F9ULL, 0x7B817E5BAA278771ULL, 0xEC05DEE85EA494BBULL, 0x30706C2F820CAA4BULL, 
            0x0723A7751C8E4B50ULL, 0x2863D4195B9A42A0ULL, 0x86A5ADE2AF008C6BULL, 0xF26215BCF74687D9ULL, 
            0x29B3FE4239BD353FULL, 0xF5A3CF8DDB87DDE7ULL, 0x80922AB35353BBBFULL, 0x840E640AD06B4FBBULL, 
            0xDC4206184BB02AB7ULL, 0x48A9C6A1FA639EC2ULL, 0xFDE506FF3AD501B6ULL, 0x9D4638126EA06260ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseHConstants = {
    0xAF612C22E72FDBE6ULL,
    0xA5012965FFF84A9FULL,
    0xA44F9D57C34D016DULL,
    0xAF612C22E72FDBE6ULL,
    0xA5012965FFF84A9FULL,
    0xA44F9D57C34D016DULL,
    0xDB8E18273919D624ULL,
    0xD5ED8098CB8284E1ULL,
    0x29,
    0xB9,
    0x3B,
    0xC8,
    0x9F,
    0x46,
    0x35,
    0x26
};

