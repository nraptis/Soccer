#include "TwistExpander_WaterPolo.hpp"
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

TwistExpander_WaterPolo::TwistExpander_WaterPolo()
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

void TwistExpander_WaterPolo::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 17030171309591003117U;
        aCarry = 14879896355661489656U;
        aWandererA = 15368156705729965244U;
        aWandererB = 9730751969609361128U;
        aWandererC = 13147464193774330502U;
        aWandererD = 15021867193823987476U;
        aWandererE = 15667019899892837282U;
        aWandererF = 16030738335114709499U;
        aWandererG = 15291770762219985925U;
        aWandererH = 14652292114650831785U;
        aWandererI = 10976328104703699353U;
        aWandererJ = 14971924397381350163U;
        aWandererK = 11168063906770517296U;
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
    TwistExpander_WaterPolo_Arx aArx;
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
    TwistExpander_WaterPolo_Arx aKDF_A_BArx;
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
    TwistExpander_WaterPolo_Arx aKDF_A_CArx;
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
    TwistExpander_WaterPolo_Arx aKDF_A_DArx;
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

void TwistExpander_WaterPolo::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 13573413271990624847U;
        aCarry = 17686593248980160181U;
        aWandererA = 15519104398384217559U;
        aWandererB = 12386048740237611282U;
        aWandererC = 16779255327563962717U;
        aWandererD = 16781994033745125021U;
        aWandererE = 12636109186200402932U;
        aWandererF = 15993288878748538827U;
        aWandererG = 15574927173398184904U;
        aWandererH = 15177473838901164066U;
        aWandererI = 10737300238833643211U;
        aWandererJ = 9605365781977710835U;
        aWandererK = 10912233537177651455U;
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
    TwistExpander_WaterPolo_Arx aKDF_B_AArx;
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
    TwistExpander_WaterPolo_Arx aKDF_B_BArx;
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
    TwistExpander_WaterPolo_Arx aKDF_B_CArx;
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

void TwistExpander_WaterPolo::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD41C75212286247EULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xF5942813F27182ACULL;

    std::uint64_t aWandererA = 0xC1835B0EDB9B890CULL;
    std::uint64_t aWandererB = 0x801D2FB1CEE60947ULL;
    std::uint64_t aWandererC = 0xB65FA8E4E8BE35C0ULL;
    std::uint64_t aWandererD = 0xC7F07482DA94505DULL;
    std::uint64_t aWandererE = 0xA37A71B5A5032833ULL;
    std::uint64_t aWandererF = 0x98C7E7E464A2533AULL;
    std::uint64_t aWandererG = 0x81842041C2FB5952ULL;
    std::uint64_t aWandererH = 0x9A5B3C38456D8A0BULL;
    std::uint64_t aWandererI = 0xD8874164C935599FULL;
    std::uint64_t aWandererJ = 0xB2A7C2E0F0255384ULL;
    std::uint64_t aWandererK = 0xD154901AA8C50F40ULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneH);
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    TwistExpander_WaterPolo_Arx aSeed_AArx;
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
    TwistExpander_WaterPolo_Arx aSeed_BArx;
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
    TwistExpander_WaterPolo_Arx aSeed_CArx;
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
    TwistExpander_WaterPolo_Arx aSeed_DArx;
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
    TwistExpander_WaterPolo_Arx aSeed_EArx;
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
    TwistExpander_WaterPolo_Arx aSeed_FArx;
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
    TwistExpander_WaterPolo_Arx aSeed_GArx;
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
    TwistExpander_WaterPolo_Arx aGrow_AArx;
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
    TwistExpander_WaterPolo_Arx aGrow_BArx;
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

void TwistExpander_WaterPolo::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_WaterPolo::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 11128172546791158076U;
        aCarry = 17770825239197443110U;
        aWandererA = 15079877582767388520U;
        aWandererB = 12883774212970914799U;
        aWandererC = 16351090896695199016U;
        aWandererD = 16036323957269351675U;
        aWandererE = 9682095884360666292U;
        aWandererF = 10347074451848396873U;
        aWandererG = 12317157052488867929U;
        aWandererH = 12352249127139617828U;
        aWandererI = 13702958276129186004U;
        aWandererJ = 17557526614105059273U;
        aWandererK = 16692737958275816232U;
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
    TwistExpander_WaterPolo_Arx aTwist_AArx;
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
    TwistExpander_WaterPolo_Arx aTwist_BArx;
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
    TwistExpander_WaterPolo_Arx aTwist_CArx;
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
    TwistExpander_WaterPolo_Arx aTwist_DArx;
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
        TwistExpander_WaterPolo_Arx aGrow_AArx;
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
        TwistExpander_WaterPolo_Arx aGrow_BArx;
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

void TwistExpander_WaterPolo::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 1, 3 with offsets 4896U, 6027U, 1309U, 5864U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4896U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6027U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1309U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5864U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 3, 0 with offsets 1073U, 307U, 6926U, 6926U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1073U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 307U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6926U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6926U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 2, 1 with offsets 7283U, 4209U, 6051U, 5858U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7283U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4209U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6051U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5858U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 0, 2 with offsets 4058U, 617U, 6110U, 6274U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4058U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 617U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6110U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6274U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 with offsets 1686U, 483U, 1415U, 1544U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1686U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 483U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1415U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1544U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 1, 0, 3 with offsets 422U, 111U, 1471U, 1958U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 422U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 111U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1471U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1958U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 3, 1, 2 with offsets 1691U, 1970U, 420U, 1057U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 420U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1057U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 3, 1, 2 with offsets 1915U, 773U, 109U, 996U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 773U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 109U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 996U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1964U, 1972U, 729U, 1727U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1964U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1972U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 729U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1727U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_WaterPolo::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 2, 0 with offsets 4867U, 4743U, 1082U, 6158U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4867U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4743U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1082U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6158U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 1, 3 with offsets 5313U, 2540U, 8104U, 5523U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5313U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2540U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8104U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5523U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 3, 1 with offsets 7289U, 2859U, 2013U, 2699U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7289U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2859U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2013U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2699U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 0, 2 with offsets 7387U, 1884U, 7499U, 2158U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7387U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1884U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7499U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2158U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 255U, 5775U, 6259U, 5235U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 255U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5775U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6259U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5235U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 983U, 203U, 1947U, 141U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 983U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 203U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1947U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 141U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1328U, 1889U, 77U, 251U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1328U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1889U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 77U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 251U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 122U, 1386U, 1130U, 1620U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 122U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1386U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1130U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1620U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1129U, 1817U, 1471U, 310U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1817U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1471U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 310U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 2, 3 [0..<W_KEY]
        // offsets: 1362U, 924U, 749U, 62U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1362U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 924U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 749U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 62U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseASalts = {
    {
        {
            0x6E185164A5B44E40ULL, 0xD1C76070729B4D49ULL, 0xBF95A1F508B0C00EULL, 0x5E9DE8173C391AD7ULL, 
            0xCA46E0B82B35B600ULL, 0x04810388F0EEBF58ULL, 0x92613AEAF1193CCDULL, 0xDF3E163333612B42ULL, 
            0xD4AACB31DF5FF174ULL, 0x4642B82D52DB6BFAULL, 0x1A403D888006FEFFULL, 0x65EAEA33ECF5D2B4ULL, 
            0x4B8BF20AED2A496EULL, 0x1BEF1266725B840CULL, 0x2B61362617FB4A5BULL, 0xEB64D87CFBB3A49EULL, 
            0xAFB70AD9EC5C912AULL, 0xA7AC080AF07CCBB2ULL, 0x80EBE79C619DAD32ULL, 0x3DEE7393CAC5879CULL, 
            0x50A38B317699EFDEULL, 0x7AD2E6A7005BEC91ULL, 0x3FDE0C8A8780C00FULL, 0xE3E77EF4409B3EFAULL, 
            0xA77950DACFD8510DULL, 0x47160D2719E77F40ULL, 0x0AB046A4A3434C7FULL, 0x6F0AD914A71E6222ULL, 
            0x447D05783589494EULL, 0x486C04839EFCE13CULL, 0x291812EA72005679ULL, 0xE8F919A4731EDEDAULL
        },
        {
            0x16C2069EA8173E2EULL, 0xE61BEB094FA5F973ULL, 0x4A9276DA3A3FA76AULL, 0x3FA7D515A6D52BF4ULL, 
            0xCDB94D1958F6DC6EULL, 0x7D85B2461B9FA0BCULL, 0xE5D9FA726A290E6CULL, 0x15C7D5A67428EC9AULL, 
            0x830132D38A736F1CULL, 0x62718504707BB421ULL, 0x5D6756FC1B8C6E90ULL, 0xDB710058E3934204ULL, 
            0xD14D44294D5E1161ULL, 0x5F32A61F4750A039ULL, 0x96BCD33D7287F951ULL, 0x73E97A334CA0550AULL, 
            0xFD29E754587C0457ULL, 0x06BBBA90F8475F09ULL, 0x064CACC2D5DF1CA8ULL, 0xACFDFEBE33F41C2DULL, 
            0xDBCF440716B0C7E9ULL, 0x7E7350170DBC1BC2ULL, 0xB6AAA20448C88C44ULL, 0xBB64F453FC5BD935ULL, 
            0x4F47106C37C9197EULL, 0x556F634229CC089BULL, 0xDC255BDF2FDB5BA1ULL, 0x47E1E99525923948ULL, 
            0xCAC0ADD7312FAFA2ULL, 0x2C21717454B786E9ULL, 0xC2558132E67B7607ULL, 0x6957E1D98CD619B1ULL
        },
        {
            0x41BBCE0678860E22ULL, 0xC524B81A3761C5ECULL, 0x78C2D7DBFD984EB2ULL, 0x8D4E6D4AF8E96792ULL, 
            0xA3040535FCF78EF8ULL, 0x5B22E9B4568BD09AULL, 0xB1DA1B615B63D3E8ULL, 0xD2C5DFB8D262EFB9ULL, 
            0x0C4C9461D87ED13EULL, 0x9EB65AFD5710DC8DULL, 0xE0112FD77BB8072CULL, 0x4FF78F845BE19C06ULL, 
            0x89E3EEC137A8D705ULL, 0x972DBBD2759BC300ULL, 0x10F3683B03032926ULL, 0xB6B250D7504B4558ULL, 
            0xD6F2D9C60CF648C9ULL, 0x5261A97DE66EA5F8ULL, 0xB08F438A47AFB370ULL, 0x7CEECB075BBD1C87ULL, 
            0x6CBF55F2D215A805ULL, 0xE9831817B7464F09ULL, 0x37CA524957062B85ULL, 0x9CABD9D5A8D0EE6AULL, 
            0x6576A6BB24B906CEULL, 0xF0BB1136931A5AD9ULL, 0xC47A28CF59DAA40AULL, 0xB0831D998023F430ULL, 
            0xE07764DE4138D73EULL, 0xAD4345FBF6F93DA0ULL, 0x254A71770DB54DB1ULL, 0x778D117C579A4114ULL
        },
        {
            0x67299CCB4B86BD12ULL, 0xB734A96AB6377979ULL, 0xCFBE315AB833C852ULL, 0xA861A2DF6AD2847FULL, 
            0xC60C94E483DA6C05ULL, 0x23DDAE0C0B6497DEULL, 0xF03F1A1A8B8382A9ULL, 0x69221E2EEBCDD110ULL, 
            0x066C9AE94108D3BFULL, 0xB1C4641823E88522ULL, 0x8C6F8D1A6E4EAB69ULL, 0x24D5B8FD1EDB8753ULL, 
            0xD5938851492DA231ULL, 0xAE2B6D8A65EDF090ULL, 0x3064819704E1DF70ULL, 0xB3CC542123C44663ULL, 
            0x30D0442A529E271CULL, 0xADDF81EA1308018AULL, 0xD72D1AD8612A10A3ULL, 0xDCE741364969236AULL, 
            0xEE382BE3BA991920ULL, 0x677A1A47240AF2E6ULL, 0xB479910472094279ULL, 0x87485330F8004548ULL, 
            0x0CE2F39B19373C3AULL, 0x78D2F5AC36774694ULL, 0xD28E0E6A25AA8E0CULL, 0xD0215C81FBC40AEBULL, 
            0x19CE63EDA900F456ULL, 0x7854A4C2BBD9C685ULL, 0x65AAE95E62D7C623ULL, 0x02A5935FCAB0873DULL
        },
        {
            0x31D24763ED4A0FE7ULL, 0x2AFB8B33CB1CEC78ULL, 0xE5540529CA0CCF4DULL, 0x4C2BD750D3748D4AULL, 
            0x1DC39B238C41A7BEULL, 0xCD6EAF98BA1F3D33ULL, 0xB80F70745012AEBAULL, 0x4815EB35FAAA5418ULL, 
            0x78D12B2F84F155B9ULL, 0x655A1BCBC2FDEA7FULL, 0xAAFC4762A106C93AULL, 0xBC9FBC724276FA4CULL, 
            0x6F1BC551D83BCA9FULL, 0x0AAE0169C37D9B5AULL, 0x962F73B27FE5574AULL, 0xF62254F9FAA470C7ULL, 
            0x080A823927221346ULL, 0x37694EF2798D51B6ULL, 0xD06EA3C5A546ED3CULL, 0x4FBCBB7895E69233ULL, 
            0xAA609685AF8542C9ULL, 0x12B64CFF2200B662ULL, 0x425598EB5B0DDD83ULL, 0x04FDC07EAFD048F7ULL, 
            0xB54BC94DB710CCB3ULL, 0x988D105AD2A59D0DULL, 0x9FF193423678E71FULL, 0x6A054F2FE3599B57ULL, 
            0x8F7641F8BD85F62BULL, 0xF830C07979CB3BB5ULL, 0x18BC809685C305CEULL, 0x57E4314362A95D0BULL
        },
        {
            0x4AC11C178BB3DF3EULL, 0x4A531B4294072083ULL, 0x18176C28383023EBULL, 0x94CAD6AC4A9376B5ULL, 
            0xC7B25C7DADE19336ULL, 0x2DCDFAB3937F960DULL, 0xA0A47275B9113268ULL, 0x8EAE2D8EED686459ULL, 
            0x909E05855F38A7D7ULL, 0x680C790F0C8FC468ULL, 0xAD872F848BED75E0ULL, 0x507683930AD7AEF4ULL, 
            0xCC159708D36CE9D0ULL, 0x1BBC0BB06BDCF9C4ULL, 0xAF6F1AB4674A8D30ULL, 0xF882C0DE819DAAECULL, 
            0x3436D39CCB677210ULL, 0x86893A7A6415FE00ULL, 0xD050B1A0D03C5C32ULL, 0xF7AA2344B5ACFDDDULL, 
            0x6FDF17C39D644CD8ULL, 0xB5F86BC19C516A08ULL, 0x9D96453F4B2651A2ULL, 0x64448DF726FD2C9CULL, 
            0x608B4491F1078A7BULL, 0xD11B399AD6DDF08BULL, 0xD7B9F5C05D9BB0B6ULL, 0x1E9DF50E5C795AE7ULL, 
            0x928504AC680E3A7DULL, 0x6C02BB8E917D7D8CULL, 0x969EAE95DAC90A2FULL, 0xE3BE299925AE2E0CULL
        }
    },
    {
        {
            0xA959FD1DFC77B76DULL, 0xEAD744FDB41E31C6ULL, 0x223C224DD63E590FULL, 0xE6F4E714A2F5AE4AULL, 
            0x0BD3FB97BA37A411ULL, 0x6D2F8EEBCDAFD9ADULL, 0x2D1DE3523C8EF127ULL, 0xD5A48780F6DA0A93ULL, 
            0x94B1D695495341A4ULL, 0x6B46D7C80F5EA6A7ULL, 0x1E4359D81E90181AULL, 0x69D83CD69FF036F0ULL, 
            0x1B38BDCFC1D25707ULL, 0x6DF607009537819DULL, 0xD7DD0B4A815DF7C9ULL, 0x8E8A113CBDF87F65ULL, 
            0x9627CECE4ECA2D9DULL, 0xD41786A5E61E2D24ULL, 0xC058F610AB106091ULL, 0x6EE843271B8F6BC6ULL, 
            0x1450F7204817562FULL, 0xAA21936A014B467AULL, 0x64863A23104F1FE8ULL, 0x8F13AE7E4B5CD85DULL, 
            0x267F502C2A09A7FBULL, 0x7B5E1C992E663F22ULL, 0x6B0358CE3090DE43ULL, 0xF9AE892CFA55CCBDULL, 
            0x1E6876EEC06BAD06ULL, 0xAC157757157CCE1FULL, 0x2D1DA10B47CBEBD2ULL, 0x485A4918B6D2D5F8ULL
        },
        {
            0x48D9D0DC3071D9FCULL, 0xE89E00C08035149EULL, 0xE56E3B1FB0590795ULL, 0x9856C0A840E601FCULL, 
            0x688A2CA027DE02E8ULL, 0xDF7F7FE7D7A45793ULL, 0x516AF4B9E7AE0F97ULL, 0x2FB597B49501A4C7ULL, 
            0xBBC71CAE6E456C41ULL, 0xD2BF55BA31085379ULL, 0x3740E4D00DE6D20AULL, 0x77E3FE94512A80A9ULL, 
            0x40C4FE6CF7FA18C7ULL, 0xC0A6DD14B23B87A3ULL, 0xDB4BAE3955831E62ULL, 0xABD649BB5B033E7FULL, 
            0x5BFE32B5D5152600ULL, 0x48864C9CD05C7437ULL, 0xADA31AC0D941AA7BULL, 0x74D56373EADC1386ULL, 
            0xB2DF182EC47792F5ULL, 0xFCAF0191B2EC7862ULL, 0x86415CA47275AFD3ULL, 0x2563A6C657B8A667ULL, 
            0x76AC963855281CF6ULL, 0x60C3AC6806443F11ULL, 0x893DF2A7DD45AFDFULL, 0xDBA281FF64A89527ULL, 
            0x8F1B28ECF0CCFA8AULL, 0x7F8BAE0FF90A2A5FULL, 0x939DE58D27152F9BULL, 0xD4D202FE587F9C77ULL
        },
        {
            0x9C754D5F7DDD1E49ULL, 0x30CE1687FA0B3075ULL, 0x8C161000FD45EC30ULL, 0x289633692A79E509ULL, 
            0xC23735C2609C1C7BULL, 0xDA99BA85D4C3C0DDULL, 0x04302F630A9BEE10ULL, 0x542B7A5A71F15B8EULL, 
            0x017CC0ACAE831CF9ULL, 0xAE26604DA86C142FULL, 0xF597781F5070DE16ULL, 0x12B58EBE88937F82ULL, 
            0x9FA0C466CD287207ULL, 0x2D9A1AF67519896BULL, 0x36999BCF3DB79EF6ULL, 0x3CC41AB1ABC3ACDBULL, 
            0xFB700ED07ED0A5FDULL, 0x7723DE8CCE82352EULL, 0x8020C8FCC30EDD1DULL, 0x9D77A7AC4065585AULL, 
            0xFA62867BF8688B88ULL, 0x52D04D787F8F7B06ULL, 0x412E05A5D07575CBULL, 0x2AB28D2AB09AD839ULL, 
            0x0673033A66BF0C32ULL, 0xF3C22FAE9E554B80ULL, 0xC4B23EDA86D3A68CULL, 0x4FE2ECD354668A89ULL, 
            0xF8F71E896D3B1809ULL, 0xE7D83ADDE6F233F3ULL, 0xE5FBC552B4AF84CBULL, 0xD9DA04E1641DCF3FULL
        },
        {
            0x642DEA1EFF4A207AULL, 0xEA0B716A73AA7C90ULL, 0xE57D94B8187CF78BULL, 0xA58FB81FF85CCFFCULL, 
            0x57D8B12F9A90D471ULL, 0xC047470C5498A69DULL, 0xEDB1E02192DB1790ULL, 0x0EF59F66D98CD270ULL, 
            0x30AA38BB27C11331ULL, 0x7EFC08F8B87CAFF4ULL, 0x535F8DAD4FBF0F81ULL, 0x9F2E7C88E3F04E27ULL, 
            0x5E90F0FA086833ADULL, 0x129ABE3C280168C5ULL, 0x2B1E0F7642192783ULL, 0xE565CE0E75AF0A01ULL, 
            0x206E4CF69BCD071DULL, 0x455780A50450CA65ULL, 0xFA712FB14E2BADDFULL, 0xA1F3936ED800D536ULL, 
            0xD58A97120EA024F8ULL, 0xFE8754AA32D836ECULL, 0xDEE6FD46792144DEULL, 0x2F5283890C1C40D1ULL, 
            0x8CA83FE45B026848ULL, 0xA2DE289CD192E562ULL, 0x0D12C96EC4FBEE7AULL, 0xD470FA998B94A5B1ULL, 
            0xAF0183DD39E4BB61ULL, 0xA35282DDC1197602ULL, 0x42A4D8F4C4AAF979ULL, 0xE85451CAD83DB90BULL
        },
        {
            0x51933FD99B09AEABULL, 0x83E27E552BCBD0AAULL, 0xB1477FE0E33BE14FULL, 0x35F2364A38C9E9B2ULL, 
            0xE580A3A3AC0B581DULL, 0x2332B62A39102663ULL, 0x51CAEFEC467D3C16ULL, 0x3104AAC3F7DD320BULL, 
            0x3481356A5B5D4874ULL, 0xDB5B4CC6F6E991AEULL, 0xA4AC0DB33511BD9CULL, 0xF10791AE3B927411ULL, 
            0x7F43FD0972B67055ULL, 0x79BED19E157EC5F8ULL, 0x5973F848D8DDE362ULL, 0x32D76B59C8F96864ULL, 
            0x80CF80EE6825D2AFULL, 0x034435B92C0F4CDCULL, 0x385E37FB5CE324DCULL, 0x6ADA9438AB86395EULL, 
            0x32E77F62A7BF50FEULL, 0xAB30BC1A1C62FC06ULL, 0xB65EDDCAC1C737B2ULL, 0xF0115A32B91F00A5ULL, 
            0x46B45E7FDA503C4DULL, 0x0C812B3E56B0780CULL, 0x3B2EDFC3ABF2D8F7ULL, 0x45426069FF791773ULL, 
            0x87897181D9213AF7ULL, 0xD3903408FAE561B3ULL, 0xF59AD29600967697ULL, 0x7921D3D9867DE945ULL
        },
        {
            0x8A8B04A22F8F4D28ULL, 0xD98361EB513279F7ULL, 0x241FB4E329E02B6CULL, 0x2B464AFB2C334A72ULL, 
            0x3FDA440F07742FD4ULL, 0xA650C4BC263AFA3DULL, 0xF372DEE74778E08EULL, 0x556504F64F0D4BB6ULL, 
            0x5462931012CB3F6FULL, 0xFA0137936BA2DFC6ULL, 0x6B1BF2712BF62AD0ULL, 0x10A0E469F863D0F6ULL, 
            0x80DC3F955D4FCEBBULL, 0xF5692DF40C56F73BULL, 0x6CBFA9B582695156ULL, 0xAF37508C3E1A4C58ULL, 
            0x4D8B03A955DF413CULL, 0xEFF4DC8FCB8B1A26ULL, 0x2EDB5E1CF9C0DB30ULL, 0xD4F6DD087923E004ULL, 
            0x2C41D588980DE379ULL, 0xC734EB04D6A0AE98ULL, 0xFF6546AB06515752ULL, 0x9A31E0F53C821549ULL, 
            0xC8AD096D40D053D2ULL, 0x7D04073704696CD0ULL, 0x93A33D04882CE640ULL, 0x813DE888B0D750DBULL, 
            0xB512ACB3161EE334ULL, 0x4A1BE9A34827EEE0ULL, 0x0B1DF3C2DBE41EB7ULL, 0x08BBE83579D051FEULL
        }
    },
    {
        {
            0x9EBBCF98FC995C36ULL, 0xB5C7C14D5DA61E9FULL, 0x9520CD8A847832B8ULL, 0xE7BA7CD930A7782CULL, 
            0x489D709AC2D9C0A9ULL, 0x10C250C42559524CULL, 0xC997D6B5D9753385ULL, 0x2CABB93A913E5EFBULL, 
            0x4906268395B49A98ULL, 0x40328FF456F8B67CULL, 0x6309F66C0543D616ULL, 0x185E0E0CA5DDC421ULL, 
            0xE442D2426CA0D680ULL, 0x6953EB7AE0D64AF7ULL, 0xD12FB1F9F8DD30D3ULL, 0xC71ADB7C40F935E6ULL, 
            0xA2CEEF7964FA2429ULL, 0x3575D11691752711ULL, 0xB58EBAA93320EC27ULL, 0xAAD3E9E9783AB525ULL, 
            0x55BE07F078C5D5A9ULL, 0x75FF5951F7A9C423ULL, 0x9AE49001C66C43C1ULL, 0x9E0461C2F60DBF41ULL, 
            0x3C94C62A19DA6DBBULL, 0x92620365CA1B68B7ULL, 0x2D6D2953A1A595BAULL, 0x69135C7C6211BCA7ULL, 
            0x5C179DBAC0B5579DULL, 0x534778124FBD67E5ULL, 0xAAA3EEA39BA58232ULL, 0x7459954F90B2BFE7ULL
        },
        {
            0xE1984AC2EF0FD1E6ULL, 0xA51AD6700C400A85ULL, 0xA456483890D16AB4ULL, 0x40B12BA86C459693ULL, 
            0x5124CC4BD5CEE85FULL, 0x2224F7737FBDB970ULL, 0x01CC6B9CCCB9520BULL, 0xD9681B176180741CULL, 
            0x84F0BF3125E0CFB7ULL, 0x0AA5B68CB4594F6DULL, 0xE8B88218565ABB54ULL, 0xEE1246A8B8A0DD7CULL, 
            0x9B466F5CCE1789F5ULL, 0xE7A6EC54BB215D49ULL, 0x7D8FA05CEF39C6C1ULL, 0x68D9BDC173AF35F5ULL, 
            0x41C1C9627E5312D3ULL, 0x27210935E2EE3FC5ULL, 0xE0CF9D71C088F0B0ULL, 0x2FD36F266FBB3072ULL, 
            0x739B97902D3EFFE8ULL, 0x17B4D0AED516150EULL, 0x13C96CD734D3F95FULL, 0x15515564F0CFBB97ULL, 
            0xF3ADFF16A7F379E9ULL, 0xF49D5137922B5C93ULL, 0x72A5089610047658ULL, 0x89F2068BEED77CCBULL, 
            0x12108F2BBB1E1128ULL, 0x4B815E39A5BF3173ULL, 0x33F3AC64B8FD50CDULL, 0x7B2DE4268A2249EDULL
        },
        {
            0xEACA358A84A88F44ULL, 0xF0B30F76475A6DC4ULL, 0xC8FEC9367F95FFB7ULL, 0x9E23C131DC00064DULL, 
            0x6551ABED95AE5156ULL, 0x51C7422070BF0667ULL, 0x846D762902547D84ULL, 0xD52B8EF9E0D3AA25ULL, 
            0xE6505679BE6AF7E8ULL, 0x927F90BC63A62C41ULL, 0x9D9565BCBE427DA5ULL, 0x66DF81D45056A536ULL, 
            0xD902124614FEE065ULL, 0x961D6C5D81CC4B6BULL, 0x6E767FD27B7F7703ULL, 0x49E6F7D667F276D4ULL, 
            0x0751346741CEBF17ULL, 0x127AC3281A8AF01FULL, 0xB18D394126688EDFULL, 0x3A7BD6A722FC60A1ULL, 
            0x6F62A93E797BB030ULL, 0x1EF0BB6DD93975F4ULL, 0xE1F1337D8AE57B43ULL, 0x231F62E09E5A5725ULL, 
            0x8AC88AE29DA9F757ULL, 0xC2239D99CED1789BULL, 0x62E8B472ECCD895AULL, 0xA173BD9E2613DFC0ULL, 
            0x040C359F10445820ULL, 0x9B9699FFD14DA639ULL, 0xDC3F0A683007E406ULL, 0x35543592C6EF2168ULL
        },
        {
            0xA77A754C81FADFE1ULL, 0x5DD8A107F2230A0BULL, 0x323C06975FEFC1CAULL, 0x8887E871FF59CA34ULL, 
            0x1A996D7D465B4C23ULL, 0xC6C9573F4C4E53F1ULL, 0x9E195C2C9EC52FBCULL, 0xFDAC7AC0765822CDULL, 
            0x825A1C4D49E80E26ULL, 0xE66D6E2F17806E96ULL, 0x28C1AF75FAE0AB35ULL, 0xF775E92CBA254DA0ULL, 
            0xD8DE000199DFDCF6ULL, 0x52E30369A82BAFBCULL, 0x1E9239299206090EULL, 0x5660F7E5765B2EF6ULL, 
            0xB67E07AB197D39B9ULL, 0x493C24412D30393DULL, 0x9AD56EABC51E4E75ULL, 0x2D88C66A66A46EDAULL, 
            0x11E5837BAE89026BULL, 0xB882A2BBB386E7CCULL, 0xB8932E6CDB83C8EBULL, 0x5D616EB97F56FAF3ULL, 
            0x8C4C86EA735FB89CULL, 0x6615F22FC724C589ULL, 0x23C6DF9C8EBD15B9ULL, 0x0E138FCCE3827122ULL, 
            0x2AE73D98609A0E33ULL, 0x4A8DC3F03854C746ULL, 0xA18B0ECC77113CF6ULL, 0xE40EFE821B3C3B3AULL
        },
        {
            0x0E571C9ADEA47A2FULL, 0x6469E6EEF6640A3FULL, 0x0DB0A693E6D058ABULL, 0x6325660CF07A52ACULL, 
            0x8BB82585E6BFDA44ULL, 0xED33208DC89E35D1ULL, 0x50460DE25EF99553ULL, 0x4475BEB9D84D11A8ULL, 
            0x830A796518E93410ULL, 0x8FD1148ABADC2704ULL, 0x79B1FD7FEDBD8E92ULL, 0xE1094C78EC9D6C23ULL, 
            0x4EB416867FC9B030ULL, 0x91929A7E6C884848ULL, 0xA94FC38DEC88B540ULL, 0x19EA16BB42466B56ULL, 
            0x58834FA617F368C5ULL, 0x7586E479FB6BDB91ULL, 0x344835216368786EULL, 0xAF40A76CE699E61FULL, 
            0xFE6DB99908A5E7B1ULL, 0x13DE558F9C8157A5ULL, 0xCCD6E5162F6D19F1ULL, 0xAE10A662ADED9CBFULL, 
            0x1AC27400C3280DB6ULL, 0x33AC638EB7DA2717ULL, 0x1C30B0E9D828B734ULL, 0xEEA3DAEB712299B8ULL, 
            0x99CB59AD65C917F3ULL, 0x9663B4C9C245BBA1ULL, 0x02A5E43FBF681D4EULL, 0x596A6BF4C3F7CF63ULL
        },
        {
            0xF1E497AF9690B2A4ULL, 0x78F8AF91A0F7FD41ULL, 0x6EB36DDDEBDBF6B2ULL, 0x20CDB0E26BD0F5E2ULL, 
            0x469C130362BB6BD4ULL, 0x8C277CB734CDEA03ULL, 0xC3D17E4E4FD8A667ULL, 0x8D5AB4C26B2840E1ULL, 
            0xCEC8BCEDEC64AB0EULL, 0x1176276B195E6127ULL, 0xAE1513938B54D82AULL, 0xC592DFEF2D578686ULL, 
            0xE0BB367EDEC787E2ULL, 0x27DE58641DA2A5EDULL, 0xCD93F19C57F360D8ULL, 0xA6C5B7C7BF99086DULL, 
            0xEB2B0F6DABE29583ULL, 0xFFF6E0B2CF4E6D2FULL, 0xD3C86B2EE7295B2FULL, 0xD406941127DF4F0DULL, 
            0x657643C407C31834ULL, 0xE7FA85DCC0705199ULL, 0x022BE449802FE0DDULL, 0xAF7E717BB76A6154ULL, 
            0x1ACF74F40F33D546ULL, 0xC42EADEA9C747551ULL, 0xB78F838761532E92ULL, 0x2E47DA1E5B65C226ULL, 
            0xC504A6A2E6B401F4ULL, 0xC8BE654EAA98DB76ULL, 0x13782B9B8C2E867BULL, 0x4D816E533DCAAC13ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseAConstants = {
    0x1DD90E3081F84FCFULL,
    0x5E53088A62BD30BEULL,
    0x99648BC338B357BAULL,
    0x1DD90E3081F84FCFULL,
    0x5E53088A62BD30BEULL,
    0x99648BC338B357BAULL,
    0x73B991582E4BC936ULL,
    0x7629E86056430521ULL,
    0x70,
    0x7D,
    0x41,
    0x63,
    0x1B,
    0xD7,
    0xA4,
    0xD8
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseBSalts = {
    {
        {
            0x59CF9E014866832CULL, 0x436C1DC1A401156EULL, 0x85E8C49E40D36B27ULL, 0xE8F422922234D622ULL, 
            0xF707232A62909881ULL, 0x355B847583974A8EULL, 0x23B2E4C94E10C837ULL, 0xB3AF36D2CE8D615EULL, 
            0xA51588F8A2FF5E18ULL, 0x632EA3F97FFE4B0EULL, 0x41F916A439C68AE3ULL, 0x6682437F303C1BE1ULL, 
            0x0E63A133002FC635ULL, 0xEB07A7700DA45445ULL, 0x9617C01957C71866ULL, 0xE7B5BB856783B00EULL, 
            0x46D40D81BC3E834FULL, 0x2DE5651187C0CEA2ULL, 0x041BBDCC98004471ULL, 0xD1B3EF7F2C8F2FB4ULL, 
            0x1DE8E0305D7E5406ULL, 0xD4D564816F94252FULL, 0x7E69BABD9B95564CULL, 0x92E6D55279D13449ULL, 
            0x543EF33E77284461ULL, 0x0343942F01C56C8AULL, 0x96822AEC5ACDBCD4ULL, 0xD6BFF2BD6D823DF5ULL, 
            0xB9E8C4361137AEE9ULL, 0xC1AE809980ACFEFFULL, 0x8C2434AE1A9E5373ULL, 0x0C15B6A227F8A3D8ULL
        },
        {
            0xCEB4E67E67EAED93ULL, 0x756AE58232A7EA7DULL, 0xDB28EF7753A5C30AULL, 0x0E9DB58C5B8F5F1AULL, 
            0xDBF2CF93ACF27094ULL, 0xB24A55046F314069ULL, 0xB751C121A8E1E2EEULL, 0xB19E6BE54FD6AE44ULL, 
            0x626ACCA882DA847BULL, 0xA2166C6B9BDDD934ULL, 0xFACCADD9118B6872ULL, 0x226142BBF0B0F585ULL, 
            0xF88FFB821F49A974ULL, 0xB44337AE1F2AB353ULL, 0x852268010C6DA3E5ULL, 0x1257FA087E7BB053ULL, 
            0x6A384C611345C744ULL, 0xADB18F3230E7D294ULL, 0x0069ECD0D274393EULL, 0x770C99C483036BE4ULL, 
            0x98378033477E8779ULL, 0x9EBADB7073609CC8ULL, 0x0F30619A54CD443AULL, 0x7B7600B3FC5B415FULL, 
            0x0A3998B0E90DBB61ULL, 0x38E65075CED21571ULL, 0x341F61C35DB61946ULL, 0xC8E1C3B922FF8C15ULL, 
            0xB25D8CCC88F0CC74ULL, 0xF679DE3800D2DCC4ULL, 0xCD4D49BC51BA1ADCULL, 0xAD7C0CFA42176588ULL
        },
        {
            0x84A113004F59D3ADULL, 0x0D6D0DF4D534EE3DULL, 0x8A81053077BA8E70ULL, 0x9087229F91AE17F9ULL, 
            0x97C3F7607216AA30ULL, 0xAA454FFFFBCB9673ULL, 0x9E2885B03C90980FULL, 0x4E90E6F7EE9DA6D1ULL, 
            0xAEC9F1E5E64759DCULL, 0x7BBA3F958EE7A805ULL, 0x6D55201319F35E9DULL, 0x7E3A7BC384F50ACCULL, 
            0x27BB3B54E8CAA62DULL, 0x01CB1F95BFB99EA7ULL, 0x97A693FA97F60C36ULL, 0x1AC8A53283F6D9B0ULL, 
            0x498A8D1B38A7624CULL, 0x5C4901BF09AEEEFDULL, 0x0FD661FDF08C11D3ULL, 0x2439A7F2445A26F2ULL, 
            0xD924FCB1DE0B68D2ULL, 0x1A940FFC177FB8B6ULL, 0x86DD82AF0CAA42CEULL, 0x86F36D1058A98AE9ULL, 
            0xE1CF53DAEF2CFA58ULL, 0x8FA77C395929D0B5ULL, 0x0C1D13B3EB7814D5ULL, 0xAE15388C49F5B952ULL, 
            0x6ABFEEC544B266E6ULL, 0xE67105F958F96887ULL, 0xD4C223A16485AF24ULL, 0x98B8C000A1681542ULL
        },
        {
            0xC482B2B02D413D08ULL, 0x0C13A068AC9776CAULL, 0xF56CC2DAFD2FC49DULL, 0x4FE3DF11E9AA5E38ULL, 
            0x19DA56B49FF344A2ULL, 0x01CEFA7517A295D5ULL, 0xCF504F8530C2B5A9ULL, 0x5E9920B743EB9412ULL, 
            0xA5C3B43EBB452516ULL, 0xCE5B32FD5A416D91ULL, 0x7E9289439D6EBDC4ULL, 0x807F59F87A543574ULL, 
            0x401BD63D08A227E9ULL, 0xF19EF4C2C26273AEULL, 0xBA3C9DA73C584028ULL, 0x43F03D688012B7E3ULL, 
            0x8B6161922DD3EBCCULL, 0xA5E78FC863D0E59BULL, 0x66BE284BD90225B3ULL, 0x41BF4B034B2B1174ULL, 
            0xA668D32856DD32F2ULL, 0xF97973E5D74603DFULL, 0xB371F03B254C58B5ULL, 0xEC1A4FB9E3C45B6FULL, 
            0x6A50B6AA769AAF4CULL, 0xA3DA8E7709C798F6ULL, 0x8A7C953886420023ULL, 0x716DDF90E75BE9C7ULL, 
            0x03C954DC7B176E2EULL, 0x165679F25CD405CEULL, 0x5A53463C2B7440B3ULL, 0xCC43544E28E0DCCCULL
        },
        {
            0x028430C21119138FULL, 0x9354046A490AE6ABULL, 0x0F2EF502140DB36AULL, 0xF349C77B16780D71ULL, 
            0x7561C1D1F0F56967ULL, 0x0F45B1B69DBD0EEFULL, 0x644F4DF9C839804CULL, 0x7B6B4F2281A88854ULL, 
            0x7FD34A30550A947CULL, 0x8C246A409271EDEAULL, 0x53C092D9DE0A0072ULL, 0x3BF6C63EFC300BE3ULL, 
            0x0F2BF22C19227771ULL, 0x638C4B6875469D20ULL, 0x0EBA4E762D9D1A80ULL, 0xE6A004E7B6A374D5ULL, 
            0x74F0D23314DBC07CULL, 0xC22A5BF734C054D9ULL, 0xC6DF129BC0BEA843ULL, 0x86832C7AF604E504ULL, 
            0x67F1B29D4FB814A8ULL, 0xF727745184D5F023ULL, 0x66F119E191B0F7B5ULL, 0x627799AFD7ECCBCAULL, 
            0xF90364E5BD8C20CBULL, 0x16D5E11B9C2FF51AULL, 0x1D8E31AE97CC4D5FULL, 0x71F097BB9442FE30ULL, 
            0x83AB4F13B246C6FAULL, 0xE13A7120713E9002ULL, 0x77A69AF7555299F4ULL, 0xC7261BAD91EFD873ULL
        },
        {
            0xAC1BD4BB985C1F81ULL, 0xC693FF733765CB68ULL, 0x0787CE0E96D350BAULL, 0x0F31D6FB30A51B0AULL, 
            0xB83369D0E3CF3281ULL, 0x57817128FCC0345DULL, 0xAA2901F026D64623ULL, 0x07B103A2C4DF8560ULL, 
            0x87672200F2F03315ULL, 0xE95222F06BF23E7CULL, 0x8DB12E8E28C6E6EAULL, 0xFFE53840BC96E953ULL, 
            0xD223A62D139BB5C7ULL, 0xAAB94CB3DD89D62BULL, 0x61DDF1C8A617BEF0ULL, 0x14A28778E625E1EFULL, 
            0xAEA1D90CC6973510ULL, 0x77B6AD1D6529DAF7ULL, 0x6E52CEAFD56F788CULL, 0x933ED186B7187534ULL, 
            0xBFC18EA117DF417AULL, 0x7D07FFCCABEBD118ULL, 0x931410CD566E7E9FULL, 0xA14959A2F9D5F9D5ULL, 
            0x5B6634AC64D3EADDULL, 0x77E461A469D3BE57ULL, 0x2D996443F6C5C865ULL, 0x4F68F705F7FC92BCULL, 
            0x91314EEA93276910ULL, 0x1E9930A50E325133ULL, 0xA31FD61223068821ULL, 0x61E74CE2ABA31409ULL
        }
    },
    {
        {
            0xE88BDD2A6DA2BE40ULL, 0x7884D82E6A039A38ULL, 0xFBCA88E5970A389DULL, 0x1E6D4FE094C69834ULL, 
            0xA0EA38111D1E8F7DULL, 0x8BB78F7A0664721AULL, 0xD16483C09E94AFFBULL, 0xDE3A930AED8120A3ULL, 
            0xB1818884AC863B7AULL, 0xFA789BAB7C9B0FDBULL, 0x3CFF1253A62F3389ULL, 0x1A4F2873CA14B24DULL, 
            0xC05EBE848928807EULL, 0xAD6B7C05103A8239ULL, 0x931DF83772C7CF3FULL, 0xF1CF59108EBCEB24ULL, 
            0x779A615E6D46C184ULL, 0x1906ECD4AE7C2947ULL, 0xA726FFF7B0D82923ULL, 0x7DE7A72972E0BD3BULL, 
            0xC4E515AFB8591961ULL, 0xFDC12ED2CDC98A49ULL, 0xFD2A82572704AEB3ULL, 0x2C1CEAEC71E20606ULL, 
            0xFA07DF67575BE57DULL, 0x9529014F82F58578ULL, 0xC4EC1073F66930D3ULL, 0xED3AF7A5EADACFEBULL, 
            0x2746311215A5B2EEULL, 0xB20377CBEFEFA3A2ULL, 0x33355E55C4104943ULL, 0x2C15B87616D80048ULL
        },
        {
            0x3204703FF106B7A2ULL, 0x4263F1D84FCC9561ULL, 0x48D469478E877AA1ULL, 0xCC57284C4E68F793ULL, 
            0x455A7538901BD0FBULL, 0x479D1ABB6FEDD4D2ULL, 0x11D18AC3B26789EFULL, 0x1DC91BFD7FE11F44ULL, 
            0xC169E09379E56D30ULL, 0xA99A54351C04DD31ULL, 0xC8311ECE1C5D45C5ULL, 0x7EC8272FECC257C1ULL, 
            0xF5686D78F0ABEBD9ULL, 0x9E95975457E10DF2ULL, 0x47A126D10FE6A7B4ULL, 0x3B26A59705AF50C0ULL, 
            0x2A5F59CDD0A870B8ULL, 0xA549ABB8E5D92A81ULL, 0x1A2725FDCE63E829ULL, 0x0164941B881CDF03ULL, 
            0x6A86C1A30F7DFBC9ULL, 0x2AD8903F34083285ULL, 0x1704AAE8A9F42C00ULL, 0x6D74AA78323E9559ULL, 
            0x188B48D2FCCE83ADULL, 0xEDB1A72602B5A9CAULL, 0xB3F85CD35C921AB4ULL, 0xD841026DF6BBA978ULL, 
            0x24AF773D138AE4ABULL, 0x389DE123442C685DULL, 0x06531094D631F37FULL, 0x39FD6BDDDF2D97E4ULL
        },
        {
            0x65201F378AAB191FULL, 0xB65C8F01D21DD22FULL, 0x5EA410B84D89E2D4ULL, 0x846275406B7F087BULL, 
            0x9D013D7F66BB57F0ULL, 0x410FE7F7CC2AD967ULL, 0xF12FD055248376BCULL, 0x7D1A822D2F802410ULL, 
            0x1FA83AB0C98A0D9CULL, 0xB59E2AEF64B2EBEDULL, 0x37A6616D242CD63DULL, 0x93E63A1C7E1D38FEULL, 
            0xA7A87584BEE25E7CULL, 0xD14499B5B2F1ACD2ULL, 0xDA2C13BC3DE86DD8ULL, 0xBC4558E942137080ULL, 
            0x31AED14C95561BA4ULL, 0x81CC7D04CCEFD22AULL, 0x3FEBCAF18CFBF9A9ULL, 0x5E29601648489273ULL, 
            0xFB509BB3A2BB59A2ULL, 0xC87C96EE62E637CFULL, 0xA943FB68101CFD4CULL, 0xF83236CFA3CE3F77ULL, 
            0x900B7D5AD893AE2CULL, 0x9D191EC54FD9FBEBULL, 0xB850B4A03132EA7EULL, 0x53EC3BA3DE839575ULL, 
            0xE2FDBE8156D407E5ULL, 0x565D067369122726ULL, 0x2CF311E145F35EEDULL, 0xA076C0880AF90393ULL
        },
        {
            0x656D690A175A9BECULL, 0xA1B7FAAF89CCC281ULL, 0x32BAFE2228EFFCD9ULL, 0x1550A939B5D31673ULL, 
            0x330040E98E7484C7ULL, 0x92093214418931DAULL, 0xC144C24C47AF3174ULL, 0xE3811E8DE49F5110ULL, 
            0x8A60C66D0DA3238AULL, 0x0F54629F1F7CDD09ULL, 0xF2D03503554A2D98ULL, 0xC19EC6B266554D98ULL, 
            0xBCBD849B9E8B4CCEULL, 0x7C5650C29ADC7B82ULL, 0x594C3711A9D6AB4FULL, 0x097FB9528F3D344DULL, 
            0xEDAD2A4DC242E2EEULL, 0x2FE320A21F2AF697ULL, 0x490A678FB84A423FULL, 0xADCF2DDDAF943422ULL, 
            0xBF7B3551171CFAC3ULL, 0x1E577DD5073F28AFULL, 0x0103714D896FD825ULL, 0x940404992D13B7BDULL, 
            0x387BACEBB871F148ULL, 0xD503EA35DB7805F4ULL, 0x65447F916AEAF37DULL, 0x228D972D4E51E56FULL, 
            0xF2BC0792AAA6950AULL, 0xBEA22C330A3CB274ULL, 0xF3764C1AE42E16E6ULL, 0xD8D76E13CB33F100ULL
        },
        {
            0xE5ED8921309504A5ULL, 0xE32931DE88417204ULL, 0xCC751F305A5AB18AULL, 0xA8C3A786F7F4696EULL, 
            0xF7A6F3939CB15034ULL, 0xD6984330555EB327ULL, 0x173650DAA43E15D7ULL, 0x5E6996F8F18CFB61ULL, 
            0x41B8FDF10F232B80ULL, 0x87543AEB6A0AF56FULL, 0xC7AD9877DF7342DFULL, 0xD2E45B02F328022FULL, 
            0x512B62ED314EF247ULL, 0xED25A89E8E98B716ULL, 0x3865536E087E192EULL, 0x26F0A17C7992E7BFULL, 
            0x1465DFE26F12CDFDULL, 0x8B6EE66B62E77043ULL, 0x80AB3A170BD65784ULL, 0x9EB4CC9E699CF360ULL, 
            0x32676A2B2046E46EULL, 0xF2C5489D3273FFDAULL, 0x56A9603130FBAE37ULL, 0x1D497959F2F62AAAULL, 
            0xBC8B3191D3376016ULL, 0xD062371E78F78BAAULL, 0x49125CE46A42987DULL, 0x387834E7BB1E2722ULL, 
            0xD527E1CBBD2AE43DULL, 0x4D9738FAACA3E384ULL, 0x0AA0EC266B2A23FBULL, 0x4223C7D97351A7D9ULL
        },
        {
            0x355072FA01ED1996ULL, 0x7DF85A081E126983ULL, 0xC3BF49416FE706B4ULL, 0x2ED7484BE4308E9EULL, 
            0x7D72E8480404DABCULL, 0x7E9A6B00EB37550AULL, 0x1339FC5AA1B2AE0DULL, 0xEFE278550D6ED80AULL, 
            0xB74188E9D585CC59ULL, 0x1354E7715DE3A728ULL, 0x6B489E8B6D47B358ULL, 0xC5A27482FCBC3545ULL, 
            0xB01087166183E1CEULL, 0xA1290D883C10A5EFULL, 0x0FA344EAB58174C5ULL, 0x23FD2575481D07B6ULL, 
            0xC3C19FA04F097B53ULL, 0x0D7D16553764D412ULL, 0x1D1559C5D7C31E5CULL, 0x1E462D2BFC497BFAULL, 
            0xC5C8358FF801E605ULL, 0xA81DE0DEA9294E7AULL, 0xF323CF5E8F86348EULL, 0x02B5A0683D2C0972ULL, 
            0x8B3A25E0452B6D3DULL, 0x2EC8E661E9630932ULL, 0xD1F2A5895E727F4AULL, 0x2BD500390ECAFDB4ULL, 
            0x720C1144A4076B0EULL, 0x86F0B55F1BBF1F2BULL, 0xAEC325415B806E0BULL, 0x0D77D44910B7D763ULL
        }
    },
    {
        {
            0x9AA8554D39C7318EULL, 0x7D2ECA890DD07F6DULL, 0x8ECE38459959DDC0ULL, 0x206BA73B0E7761B1ULL, 
            0xBD1F6B7DE499FA99ULL, 0x0B405DC37BA7E25AULL, 0x11D9857EBECD8A5CULL, 0x1217F8ADB722C00FULL, 
            0x24BC98F2BCECFBD6ULL, 0x32C6C630B5D3F907ULL, 0x8843707F55543C7CULL, 0x6841BE771C0DCCEEULL, 
            0x01F78F06B80118C2ULL, 0x22884C464818035BULL, 0x60B0ACB025BDCA80ULL, 0xFD607B23D6DCEB09ULL, 
            0x3891F63EBD02894BULL, 0x5F72DF86B1EE8563ULL, 0x44458FF2B085977AULL, 0x8A80D1F27AE5DF2DULL, 
            0x5F3B79A7EFAC6724ULL, 0xF41094D1FB54C18DULL, 0x3D743F21BD7A513EULL, 0xBE95EAA74DCB198AULL, 
            0x46DB7F28D1ECF157ULL, 0xF2D3B970FCFD5175ULL, 0x6C09E3DD7D8C06D7ULL, 0xF0B130B591FF805CULL, 
            0x707E1DFCB2944699ULL, 0x7B4236AE3393862BULL, 0x78A9A4D31A3DCDB5ULL, 0x6045009BD4D622AFULL
        },
        {
            0xB0F1A420AF635E11ULL, 0x58CA233EE3027061ULL, 0xAC0CB4181CBC4FBFULL, 0x5BC3B55B045826DDULL, 
            0xE8B07ABA6E4EF5C7ULL, 0x26DBFDA171EDB9D4ULL, 0x4002CB77165E2DC8ULL, 0x58326820854436D2ULL, 
            0x3235C7705CBDAF80ULL, 0x3DF9E33E4C1E4FCAULL, 0xBE23A06EDCCC2846ULL, 0xCDBDEE38A7B9E742ULL, 
            0x2849F5B99FA4311DULL, 0x139F69594CBC631BULL, 0xD2068CCC60891F4BULL, 0xB8A5C06CBFBA0329ULL, 
            0x04B3DFCA9987ADD8ULL, 0xE24613971044DFA3ULL, 0xD7BDAB5F745AE716ULL, 0x6EA7270F237DA2FEULL, 
            0xDC53FD0DFB745EC8ULL, 0x27B27CFA46095A9BULL, 0x354E83509F1EB38BULL, 0xA1B32E9CB48175C1ULL, 
            0x417BB20242E3A26BULL, 0x07852C49693EE841ULL, 0xD06239655EBAC428ULL, 0x06BBE1FAF08C3FC6ULL, 
            0xCB63968F52C94981ULL, 0xE076F207F14487D4ULL, 0x19C8BB741E6756A5ULL, 0x0AF388BF56B19A2AULL
        },
        {
            0x5BBA88A57855F6AFULL, 0x752F63CB123DB00CULL, 0x479CE292570C525BULL, 0xC032C6DAAA404D07ULL, 
            0x4018666D53299E4DULL, 0xC7F7BC6BB0F59B06ULL, 0x82B6CBA27752C4A0ULL, 0xD22F6F3938E9E334ULL, 
            0xE372943E4CAC8A18ULL, 0xB75DE8F919D1DE35ULL, 0x9C3926DA448BCBFFULL, 0xA586004FB3248AB5ULL, 
            0x31BFA73761C67972ULL, 0xF0A082366E696AEAULL, 0xE9E65B03E2BF3A7EULL, 0xD07C312D3F3B9738ULL, 
            0xB715CFD1215F8500ULL, 0x03FF2CAE31FBB7F5ULL, 0x8F2510B0C902D2A7ULL, 0xDE5516ABD69767DDULL, 
            0x1765C7292E5E1DBDULL, 0xA3A79510129B4AC7ULL, 0xCCA9F1C36C65C0F2ULL, 0x9A82493DF29EC8AAULL, 
            0x74FCAFEE80D96D41ULL, 0x6F18DE5DE3136B26ULL, 0xE5272DDEE00F3F19ULL, 0x65D7B5F19A6F52CFULL, 
            0xDC9192E4477C230FULL, 0xA0DF1D753AE8611BULL, 0xF4FC4C31DE95D560ULL, 0x186B9AB8632D7733ULL
        },
        {
            0xB21B4C262A7F98A6ULL, 0x746C7CD47BB7F6FBULL, 0x1035D8B5AA72F89BULL, 0xC722C1970BFDE147ULL, 
            0x2D4534508EBB35E4ULL, 0x8578ECE1B8C8110CULL, 0xF208A49CE41AB710ULL, 0x01FD962E7B40F2C3ULL, 
            0x1E1E08C96DE7B984ULL, 0x1953FC5748A20134ULL, 0x36FEFC22C7636860ULL, 0x50A4696C1BD3A307ULL, 
            0x43140D6354BAB418ULL, 0xB0E6312D0BBCDCF9ULL, 0x3C32B27B3C5B7019ULL, 0xCB065AD7705FA350ULL, 
            0x49F456D23112DF9FULL, 0x09EA9402FA860823ULL, 0xB32DE7418A3A5595ULL, 0x7E2312CDCCA658D2ULL, 
            0x7286AA5DA44B5F60ULL, 0x04DBD55CE50A2F2CULL, 0x370805BED38029CDULL, 0x2B79ED40BE2C2EB5ULL, 
            0x6022D00497B25672ULL, 0x491494C055810D1DULL, 0x137271B9CAA71CDFULL, 0x70A20F9EE7544EA5ULL, 
            0xED53510AF853301BULL, 0x7DB61C587D079CCAULL, 0xD61F4685BFBFB5BEULL, 0xAF271A98181C4638ULL
        },
        {
            0x96A74F6FC9DD5459ULL, 0xA574B1303DEB82E6ULL, 0xC8ED47BDEDD0925CULL, 0x596B29CC3E8BED23ULL, 
            0x34CBDFEE51793A54ULL, 0xE81D3A0F20B54933ULL, 0x274A48B6E0E34DA6ULL, 0x9518DDC0FC3B6726ULL, 
            0x3F7189B11672E3CAULL, 0xE61D6A33DE1F92B5ULL, 0xD954C8B0C872ECE5ULL, 0xBED6E23A3AA283E6ULL, 
            0x0F7CDEF8DFB54EF1ULL, 0x1C2EEE3F7BC83933ULL, 0x99F61BAA5B724B07ULL, 0x461A1B3C7918921EULL, 
            0x32386015725A4B32ULL, 0x7D2B46C7150FBACDULL, 0x7E49EAE387619BD6ULL, 0x91C5483DB59463E4ULL, 
            0x53387FE071AD39AEULL, 0xCD79BA8B39D3C1EFULL, 0xE3F39EBB8B06383AULL, 0xC9E4D508B6E92F6DULL, 
            0x8B1EFC8617323B47ULL, 0x40CC8D0D5D9A607BULL, 0x7581DD8B1A246AD9ULL, 0x1A389F42E560BC1DULL, 
            0x3BA2E38FA62A6E26ULL, 0x78E3106DAD508C12ULL, 0x327E0BF2AC38BFE1ULL, 0x9C7D051BB17C38CFULL
        },
        {
            0x83CB47704ED3E9A5ULL, 0xB5650EC67055D7D2ULL, 0xDA30927EFC27E7FCULL, 0xD4344144E4798008ULL, 
            0x6898FAC76BD52D2DULL, 0x1C35CEADD75DBB5AULL, 0x285EFB6B5A6F8D91ULL, 0xDB8D374B1D14845CULL, 
            0xF6C868AC1759CC72ULL, 0x7F2D49C642FDADBDULL, 0x3E071E8AEFE65D48ULL, 0x5EDC8F0B92F5A9B0ULL, 
            0xE229EBFC8F18A20EULL, 0x280AE2565B5DAAC5ULL, 0xEC39FD2E166FDDBCULL, 0xEA531F523ECB0487ULL, 
            0xE78592AE8EA2F5A6ULL, 0x41499EB9687AAD6BULL, 0x4CC03E9EF754E877ULL, 0xBF5295B1E970FD7FULL, 
            0x6F7B78B10BC2B548ULL, 0x1A7290E268F15E33ULL, 0x1054D52ABE919B30ULL, 0xD7E2EDCABD75DA21ULL, 
            0xBE4154DB62B23952ULL, 0x93E3064213430715ULL, 0x801DF10A08262781ULL, 0xD331F9826CFFEB2BULL, 
            0xCC74143C949CFDFDULL, 0xC9704B2EEA8C3766ULL, 0xB22EE82B97742A54ULL, 0x1D895618B30F666CULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseBConstants = {
    0x4D3D5DF1CECB6A4CULL,
    0xC1409FF8C92274CAULL,
    0x007C18D942508754ULL,
    0x4D3D5DF1CECB6A4CULL,
    0xC1409FF8C92274CAULL,
    0x007C18D942508754ULL,
    0x0AD177742F80B0B9ULL,
    0x9F15662D3AF6D388ULL,
    0xEE,
    0x63,
    0xCB,
    0x69,
    0x44,
    0x7E,
    0x81,
    0x2F
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseCSalts = {
    {
        {
            0x0C764F07BFE4A48BULL, 0xFD65C10EAE3A0808ULL, 0xEBB5D3EE495FD94FULL, 0x5F62CD908046358AULL, 
            0xF88DFC8461AFF743ULL, 0x19FD66C593D37E64ULL, 0x580ECBF451555930ULL, 0x60421B9AA3760E06ULL, 
            0xD0C3EAFBB1FE5A56ULL, 0xA798D27CC3CB94AEULL, 0x5C165BD3F736FA56ULL, 0xE694DC0C6EDC694AULL, 
            0x73D9E095478AC1C9ULL, 0x37B43D3902EF1D72ULL, 0xA1C08F9B8EFC0306ULL, 0x30A1186D15C99AABULL, 
            0x703A8FA84A2EF909ULL, 0x436A351D0C7F299BULL, 0xD56C1B47920B926CULL, 0x6EA01169AA22ED2DULL, 
            0xEAB04564A6D2565CULL, 0xEDEAA9B06ABB1866ULL, 0xDA433CB10B153F6BULL, 0x61B9F3F7CAE77681ULL, 
            0x8FF18CB9E11EFE59ULL, 0x849A95A045B9F502ULL, 0x93D65BFB05B820BEULL, 0xD385B3293910D4A9ULL, 
            0xEC5CF63AA49AD00CULL, 0x152E6AB0D822E633ULL, 0xC0AA9631CA775524ULL, 0x0058E10BF740922EULL
        },
        {
            0xD4E9D0AB57A87851ULL, 0xA2E76DB3FBB3357AULL, 0x58AC035F033DF64DULL, 0x16216725027C720BULL, 
            0x32834378C20A2DAAULL, 0x8D3A02C52C62E7FAULL, 0x4F8B631CDE1F19DFULL, 0x19F8ABC4D4118D70ULL, 
            0x0D18B3B010C37506ULL, 0xC4477036D0D3CFEEULL, 0x5A50B8329662C692ULL, 0x9E3EC90DAB5A81D2ULL, 
            0x9D526A12EFF16A7FULL, 0x8572533DD66E044FULL, 0x0F22718C96419ADBULL, 0xE8BA88B21E4C721EULL, 
            0x7A8163581DF4F80DULL, 0xDF12C6D108D298E4ULL, 0xD9B3892DB4E32797ULL, 0xA444E6D04F78D113ULL, 
            0xCF83BE81E7AF2CC6ULL, 0xF2EF15C9A4E85C53ULL, 0x97B95D653A44E55AULL, 0xB3BD23080AD220EBULL, 
            0x273790656B283485ULL, 0x306A628A221DB04EULL, 0x553C85B4DE161A23ULL, 0x9CF510FCAD7EEFF9ULL, 
            0xDAB7F74B339F9C52ULL, 0x3E70984DB154041AULL, 0x4A1E4F8FEBF7C089ULL, 0xEA246BE9B23A2556ULL
        },
        {
            0x6DA60CE0E1D946FBULL, 0x5CEC05FE04784DDFULL, 0xBE7A2FE5BC7277E4ULL, 0xDEBAD7688D8ED4D4ULL, 
            0x63CE7547F024EBA4ULL, 0x6B78DB0D08D77E7CULL, 0x4820B8E3B94E76BEULL, 0x7B23CC7674E43E3BULL, 
            0xD202D3AB7359500DULL, 0x08E70F013795793EULL, 0xBFE90ABC66AB1966ULL, 0x936C721ED5EAEE07ULL, 
            0x8042B3504E14B5B8ULL, 0xD851CF5CEE63B630ULL, 0xBADDA881B44BB474ULL, 0x37DE0F642784B24DULL, 
            0x1C8699A0124B6C12ULL, 0xF23EFCAB6FDDFAECULL, 0x9947F03158575220ULL, 0xE1EE26F20E233396ULL, 
            0xC12CBB4BA568F817ULL, 0x6D9D3DD48D184DFFULL, 0x768C5DF80951D285ULL, 0x6274D3E7EF84968BULL, 
            0xED3E7FE121D11278ULL, 0x7C20B3DEF07710F2ULL, 0xABF0B139E97C9BECULL, 0x73985C390627BFFCULL, 
            0x97E5645197B92A2EULL, 0xEEBC1B3442579945ULL, 0x41533EAC6F1F131FULL, 0x6CE2117FA876B8C6ULL
        },
        {
            0xDF79C2A1A1DE57F4ULL, 0x166667A8D16C9568ULL, 0x976BD35C3054B4BCULL, 0x7F64223A7C8B4D7BULL, 
            0x8FEAD9E2AD174D6FULL, 0x969015AAE981CEE3ULL, 0x6EC7E8558E083FB7ULL, 0x3B19DA7909A6FEB5ULL, 
            0x603C4EF0DB2B18E6ULL, 0x1F59BA7051952B4CULL, 0x20C56BD243331233ULL, 0x76A548BB08F38DBFULL, 
            0x4EC4770E5CB3F678ULL, 0x0364688389952FCFULL, 0x524C5AA2E8D994EFULL, 0x05680DB0702A39E1ULL, 
            0x1B22A97E2DEB9CD8ULL, 0x9ED82CB4261956DCULL, 0xA34DD834A6AFF6DDULL, 0x8527A5D5D3F55B7EULL, 
            0xC6EA91000C9F36ADULL, 0x38BCB88C6DF1A668ULL, 0x9C8B5BB72A383EBEULL, 0xF5D99DA86C36E42FULL, 
            0xB9991FA8F8AAFB0AULL, 0x0EDFA51A8766B18BULL, 0x84CD9F99CB6335B1ULL, 0xAFD3E2501E522F16ULL, 
            0xEC5816B2B29FB706ULL, 0x2B41065885E9ED54ULL, 0x7EDF6E5920C9FE54ULL, 0x9EB5C2AD3D147018ULL
        },
        {
            0x3D6C78DAB2A4CB3AULL, 0x7A1A2310615A6678ULL, 0x6D3D92130F9DEF3CULL, 0x4A064EB5F92D816DULL, 
            0xEBA5AF4FF3DDB96FULL, 0xBFCE7E0E2CCE17F9ULL, 0xF2D6D881C2424D74ULL, 0xE431354095717C7CULL, 
            0x8B482CA697F63D6EULL, 0x16FA872C0F9EFAA7ULL, 0xEEA7AB74CA69E7CBULL, 0x1A4D1420565BA9F2ULL, 
            0xA7743F2CF97DA8C5ULL, 0xB5926A7864BFA853ULL, 0x4C6ABA6F754FB221ULL, 0xA4D0B4D8E32AA141ULL, 
            0xADAB4217B0CD67F9ULL, 0x7D6A0C0A41DBB851ULL, 0xC482B57A4790862CULL, 0x63BA1D9395EB83EEULL, 
            0x9C0B5B076808A2D3ULL, 0xBE9F8E4DAC677618ULL, 0x78856C80EEBC8050ULL, 0xBFAFF3C50B006B19ULL, 
            0x09E3D8F3D1F3F624ULL, 0x0B2B7A12B71AEEF5ULL, 0x07B47754BCCD0DBAULL, 0x5FC54E5C3BC48BEEULL, 
            0xDB76901AA11C2E54ULL, 0xE2514CF110354FBCULL, 0x9F70CEB3FA472207ULL, 0xE7BC3094E18BEEF8ULL
        },
        {
            0x4FBE7E280B4815B0ULL, 0x566A589464493411ULL, 0x53515C29904C9232ULL, 0x8DF65C9974109D5DULL, 
            0xFA6C45E45EB562E2ULL, 0xEDD4194A119BDE89ULL, 0xA198CE1360EA2821ULL, 0x9207F5123E692F24ULL, 
            0x87B4159AE21A79D7ULL, 0x440ADC47A32B62CAULL, 0x38217168CC2D4C6FULL, 0x887D2844F8C3CEC8ULL, 
            0x80085AFE45E636E2ULL, 0xEB4433A82942383DULL, 0x644C6917D2BF256CULL, 0x6D8702165105C4F9ULL, 
            0xEE7C4F0E6AAC5076ULL, 0x07F739D52F4AEFB8ULL, 0x1A9C989C749F11F0ULL, 0xB8044B7B57FDE768ULL, 
            0x9DED4551EB328A1FULL, 0x78BF39C5B6EBDE8DULL, 0xC8BDA6A3000C38BDULL, 0xFDADFACE08058566ULL, 
            0x4F292F08C618495EULL, 0x6475062A42740E03ULL, 0x75F6B101F069D492ULL, 0xBE723BC33CD9F7D1ULL, 
            0x4B4BBBED19E20F35ULL, 0x152C4FBB573C44DCULL, 0x6ECFA27F0150FEF2ULL, 0x559CAD67DB0A4207ULL
        }
    },
    {
        {
            0xEA099EDA8B4E7EEBULL, 0xB7C3A0D9CA0FA9C7ULL, 0x45AA22535A345817ULL, 0x088CEC19AED2FCA7ULL, 
            0xDB2D8E02F50479F1ULL, 0xB445EF6CB0DFAEBAULL, 0x924FA756EFA2187CULL, 0xCC0BE110587F57D6ULL, 
            0x405F6808E81E0A10ULL, 0x9B7CC02D894D9AB2ULL, 0x8FC1CED7787E9CC9ULL, 0xD6FF196608D7947CULL, 
            0x7268A990328ABEECULL, 0x82FDAEE60C6AEAC0ULL, 0x9B4C8A5A52DD94A8ULL, 0x2E6A073B2AB9F2ABULL, 
            0xAF08F91C6145E684ULL, 0xA2C57CAB1DA1D3E9ULL, 0x91259DACB6AC9602ULL, 0xA6488279A65E5FEDULL, 
            0x102E7B91D9F8FFAEULL, 0x728671C38E49E3B5ULL, 0x353FB77D7ED54083ULL, 0x3F3788CD5712B5AEULL, 
            0x4D4C6963F737C8D6ULL, 0xA609DFCB62002EC5ULL, 0xF1B5DDE845A9F2D5ULL, 0x06E95D2813D404EAULL, 
            0xA79DE98A57D9780BULL, 0x332453D2AF56BBABULL, 0x9FD54092FC4EB9BEULL, 0x57B84F5AD21781EDULL
        },
        {
            0xCE5ED0BE0A774A53ULL, 0xAE3F5991C568F25BULL, 0x2DE4019F3C66B508ULL, 0xF600D4AC4302E0DFULL, 
            0x8BBF3B90BAA6141BULL, 0x47A28FDBB321FEF3ULL, 0x711E5E32BBA07BBEULL, 0x4A2991C3EBE74686ULL, 
            0x0406652A088EEB6CULL, 0x89B0227E3F77046AULL, 0x7B1BF5029FA6C715ULL, 0x62505902F82F1EADULL, 
            0x9F1DD686A7F0D87DULL, 0xA226AA841A3413BCULL, 0xA16B2FBED280D685ULL, 0x096E06C7702EB79AULL, 
            0x3D73554979C36BDFULL, 0xF59A42AA9910FFD2ULL, 0xD669BD5A2146B664ULL, 0xBA15FA0322D1E3BBULL, 
            0xC5E7093D340A262EULL, 0xF181969C13A57EC7ULL, 0x485180876583316CULL, 0x0101092E80B5A063ULL, 
            0x684CE8D7266661C9ULL, 0x2421B1594BCCA27BULL, 0x88F5CD079940DCC4ULL, 0x40E058D3E6519A5EULL, 
            0xED4BCCA9A92924F0ULL, 0xD0BF7C7047989C82ULL, 0x80C70CABF8B9BA2CULL, 0xF359AAD765C59EB0ULL
        },
        {
            0xB2524D836C903200ULL, 0xCCAFC0ADAD133DF6ULL, 0xEB4F1AA9FD030B85ULL, 0xF3266BCD8771FD9EULL, 
            0x7D2F14204A80B303ULL, 0xBAA61EF5C3129E00ULL, 0xEBFD6BFA533C8C7BULL, 0x6A3A6DF42E5A0F21ULL, 
            0x142DCA1C46184FC9ULL, 0xB536CDC54FB56819ULL, 0x606889FA4AD5542DULL, 0x97832F8A16DBF1C4ULL, 
            0x36684680C486F13DULL, 0x342DE8E5DB5DC218ULL, 0xB1249E5D47123AC8ULL, 0x5BBC642DD8820DE3ULL, 
            0xE2FC7045FB3CD6B0ULL, 0xC228F9F0A86F4A36ULL, 0x063F3CD2E228AA33ULL, 0xF6538BE24FFF7E79ULL, 
            0x02559B0B55A2D068ULL, 0x5D063E66BB24B265ULL, 0x38071FD2BD040AB8ULL, 0x0A30B58944FB76F7ULL, 
            0xE9C180A59A3F1426ULL, 0x6D1E9DD8E1647E7CULL, 0x3F15FCD601AFF607ULL, 0x12996CF4B555EBBAULL, 
            0x521132D814C1EE6AULL, 0xF0615A9D79645146ULL, 0xA695B0F506F45B1BULL, 0x27FF4DC3DCE92C6BULL
        },
        {
            0x6F6CF9B2957F92E4ULL, 0x24DF948860B7E626ULL, 0x1410FDF450E02800ULL, 0x8C3424A73DB0E252ULL, 
            0x9EDFB565042C678EULL, 0xC7291EA9F6869511ULL, 0xE2040DA56C89BF1CULL, 0xD231DC83E27E5333ULL, 
            0x9CA78A2CC6736FBEULL, 0xCED9952B7FCE6141ULL, 0x09997A6B8D8D63E3ULL, 0x44F9CD426514E28EULL, 
            0x33EA84BAAC8A5409ULL, 0xDF0403B7DDE4F2F8ULL, 0x519056847EBFF206ULL, 0x2F64F6D1B6C8F077ULL, 
            0x7AFC3CD4A9EC65F0ULL, 0x9E0EBFF6868ED3F4ULL, 0x8151556380F292A9ULL, 0x73B535CCEB7CD89EULL, 
            0xC0F35114C1F92FDCULL, 0x34343A7BB5BF0711ULL, 0x7D6902B8E294B18CULL, 0xFE4A1994E4CAFE1CULL, 
            0x75197282B40D703DULL, 0x79254D3EDBB38CAAULL, 0xD2DD1B3B0C95A586ULL, 0xF99CC17F04BAE03FULL, 
            0xF86A85EA4077F7B7ULL, 0x035093274916CD2BULL, 0x890AC1B201747779ULL, 0x2E16CE70FA775E90ULL
        },
        {
            0xA4223415100A0352ULL, 0x1C22B7330807688AULL, 0xE1AC3F97E42A3786ULL, 0x4EC340AB2F501C69ULL, 
            0x895C9D85A54A0634ULL, 0x4F672003A16EB1FBULL, 0x9B2ADDC4D2A3431FULL, 0xFC7B6CCB4F01214DULL, 
            0xCA1E9BDB6CCE33AAULL, 0x7948974F0094D0BEULL, 0xD339696A7B36E0E4ULL, 0x155B4A6F047198ADULL, 
            0xE48B7252A44E0435ULL, 0x27833EEF2B36B39BULL, 0x692FB6DFB4E24187ULL, 0xC948FBCA8EE0F5BAULL, 
            0x4083EE6E9D7CA1B6ULL, 0x42EF57A2346D49D1ULL, 0xECD5BBEBF411C0D0ULL, 0xA80E165126D5CC2FULL, 
            0x10FFF2665E467B1AULL, 0x55716AE22B5628F2ULL, 0x922AC4B5217F50C4ULL, 0xE32E79206D0C1974ULL, 
            0xA25DCD1CC224E928ULL, 0x271A9B143736FE25ULL, 0x8A1BE913A46E73A2ULL, 0xCA92E323EBBFEC67ULL, 
            0x8AB3916ECB59705FULL, 0x7FF8D2D3909DC91EULL, 0xEB3BC09BABA362FAULL, 0x3B41E95B5FBEF6B0ULL
        },
        {
            0xA4A26CC11FD33C0CULL, 0xA87B5118AEA14DBDULL, 0x168EE40C823ED0E7ULL, 0x63A1042564DFCA58ULL, 
            0xA58447C4B55A84B3ULL, 0x07316DEFFA7B6144ULL, 0xE594843E08C7167AULL, 0xA165030EC634C206ULL, 
            0xAA3DE2D74C0D547FULL, 0xEBDFC038AC6755DEULL, 0x803983953422DF74ULL, 0x7557BA51815C8782ULL, 
            0x36F1B859AB46A153ULL, 0xA8349246315F40E2ULL, 0xEE1A6B27491DD133ULL, 0xB834C0F098EAFDD0ULL, 
            0x665F9CC466B78B11ULL, 0xD51DF9B0218B6E0CULL, 0x186AC9F1A15DD31DULL, 0xBCAAD626BE678CF5ULL, 
            0x29877477A02B3525ULL, 0x89E80366DA0CE331ULL, 0xF8E4CAE01B9AAED8ULL, 0x3A035ADA40C2B60AULL, 
            0xC09632932032E2DCULL, 0x05A274F83A84B3F8ULL, 0xB2DC6F7432A7C095ULL, 0x62171094C59CFB91ULL, 
            0xFBCD4435C662E3CFULL, 0xC381179FE8AE6FE6ULL, 0x492B3E7EB662EF8DULL, 0xBDCE614118908EA8ULL
        }
    },
    {
        {
            0x83EDD40D896AA89CULL, 0x0F3E1F264FE858D7ULL, 0x9A10C84E30E3D946ULL, 0xF937A66357797973ULL, 
            0x4C8666DC1E9FDFB3ULL, 0xAD41AD5CAB4A20F2ULL, 0x26554E6287B84F60ULL, 0x17E9E7AD24F82598ULL, 
            0x1F0FBC07D25ACD44ULL, 0x426B24C65CCB7170ULL, 0x93A90AF75AA1A887ULL, 0x3E2FDD816A944BC8ULL, 
            0xA41F1A24B45498D9ULL, 0x45ACA280CB2341D4ULL, 0xCCEA1F19CDE85E24ULL, 0x5044A5CEAD5EF209ULL, 
            0x5B8376A0F066F059ULL, 0xDCEF2AA9C4FC2E22ULL, 0x4EDA7C02540314C4ULL, 0x83B4ACD43FCC5AB9ULL, 
            0x6919C85A6C2E46FBULL, 0x8AA39583263910CCULL, 0x1E3E747D79CB42A0ULL, 0x7AEA9631CE79CF77ULL, 
            0xE073803EF32A8E10ULL, 0x72EFB684EFC8B4A7ULL, 0x615E655B18AA5B83ULL, 0x46B0819F67BE8339ULL, 
            0xD803E7DAC99AA270ULL, 0xDE0126B8E7CB2582ULL, 0x3FEA3E482FF3D329ULL, 0x41DA01C75D502F4CULL
        },
        {
            0x588B1071C12BFE98ULL, 0x2B0F707C3FD1C982ULL, 0xDF56B2BD09EA18C2ULL, 0xC544A5FC90794656ULL, 
            0x956A3AC65680EE75ULL, 0x73F52A124CC51E44ULL, 0x89EFD98FCFBC2ABBULL, 0x5DB1BD9482E35F87ULL, 
            0x3E53E5A5677508FAULL, 0x58F5F3A36FB6A7A0ULL, 0x78B6822740003C23ULL, 0x0A7F85053AE685FDULL, 
            0x8FBAEC2B871A146CULL, 0x0C555FEF6A84CCC5ULL, 0x3C710ED38FBE1CA0ULL, 0x04DCC3775A500103ULL, 
            0xC1C06D35E30C90CFULL, 0x3D092B5B7C691C7BULL, 0xAC93440201D00565ULL, 0xE090A7DE35C07BB2ULL, 
            0xFE47FA1422D63D64ULL, 0xC0493DF998E5AD94ULL, 0x0C0ECCB74BAFAC75ULL, 0x601EE0BBD9DDB94EULL, 
            0x08DDCD9C205F5359ULL, 0xF45D0463DDA59151ULL, 0xD0AFBAA69975BF92ULL, 0x066F3B16AC113F7AULL, 
            0x2306FCC05900942EULL, 0x8C72D46FDAD60DEAULL, 0xDA9E163BA155ED01ULL, 0xA4105DEB293389D1ULL
        },
        {
            0x9AD10C379CBC8F01ULL, 0x754D6A506B105E87ULL, 0x7D0CA3880A29515FULL, 0xE58548DB8FF19425ULL, 
            0xCB3735C6B8289704ULL, 0x6FCD140D0D07BBF0ULL, 0x4821A537C6B238F4ULL, 0xA1E7653606F15349ULL, 
            0x381511BD3670C06AULL, 0xF2998DBC0F7E7F67ULL, 0x5795EF73D8493256ULL, 0x8D4CADC224D5FE9CULL, 
            0x54CE7A79AB9986A0ULL, 0xB036075AC6B44E81ULL, 0xE7F0E222A277C021ULL, 0x8F108FD81E7B0007ULL, 
            0xCE52E63B5FDF6E35ULL, 0xA2050A0E262A5EDAULL, 0x44324868C4CE5CBBULL, 0x1ED241D812449AC7ULL, 
            0x69E93FA60D72957AULL, 0x0197FC30DF69ACEEULL, 0x007299B5C4EBEBC4ULL, 0x17AA037BF96A6C8DULL, 
            0xE65343A13B66259EULL, 0xFCF0CCD14689E904ULL, 0x7B1D1D8EB39A665EULL, 0x78D3CF66E9EE4E68ULL, 
            0x2D872ECE81B2F441ULL, 0x6EB90198CBD62906ULL, 0xEBDA76045DF67CE7ULL, 0x499F4A716B7A8031ULL
        },
        {
            0x9FF812D91368851DULL, 0x684ACF29D0F35B04ULL, 0x035F5A6861D8C3B5ULL, 0x620326DE87281B2FULL, 
            0x987F7E61FDBAD52FULL, 0x298384D749A81DCDULL, 0xA616410F778C84A2ULL, 0x0F4838B17B417625ULL, 
            0xD34F58BA27BF992BULL, 0x1810201CACBAF0E3ULL, 0x629D30898AB9C2A9ULL, 0xB587F773C4F99674ULL, 
            0x5D580C6F177C2C73ULL, 0xCAC302D03E3DCAD7ULL, 0x896044D89FF6BAF3ULL, 0xCB1903D66123DE08ULL, 
            0x5F9E282B6B0D5508ULL, 0xABF81A05E36F3F36ULL, 0x5EEB82F0E820EDCAULL, 0x4222BF904111D9DFULL, 
            0x3772DD59E3FBDBCBULL, 0x7105C93B84095065ULL, 0xA484D82A7BF040BBULL, 0x9A3E631848B317FDULL, 
            0x1F065CDD00E18030ULL, 0x308AE2092FD9F3C3ULL, 0xE4804872B502F974ULL, 0xE2F417500BE764A5ULL, 
            0x0E86B6BAEF47B8D0ULL, 0xD1B0AB01A67522A5ULL, 0xB57E63A36E07AFF0ULL, 0xDEB042B177C33426ULL
        },
        {
            0x6249C08962088FEEULL, 0x59F662EAB20AA73BULL, 0xC536CAA978FEA299ULL, 0xA54ADEB6AAC62DD3ULL, 
            0x1A0ACBB041C00F7DULL, 0x67D2BAB352ED2D68ULL, 0x7D80C470900C990DULL, 0x06EB55583832335EULL, 
            0x7801C30A1F3BF5F0ULL, 0xB07D4FE628CA4E7EULL, 0x5A1FCC64A8773A70ULL, 0xAFC6C5CEC8F828ABULL, 
            0x4B789BACAEF54B69ULL, 0xA4A2DF0E2C2CF3D1ULL, 0x8C44563BC0CD80C3ULL, 0x855F11DB88E761A0ULL, 
            0xDAEF11C07CCB531DULL, 0xECFB911FB617A460ULL, 0x1DCD2303B082B738ULL, 0xD62CC37E89393170ULL, 
            0x2D85581FFC643FE0ULL, 0x5B6357D3A14F586EULL, 0x575232A763BFBD96ULL, 0x1A114C3113B5B803ULL, 
            0x1E5E942D26C6A57CULL, 0xD7E01F58519BD08CULL, 0xA722E0A67A2EC02BULL, 0xC379900ADD19626DULL, 
            0x5FAF8EFA75D37571ULL, 0x7641347DA35C4786ULL, 0x118559DA766332D0ULL, 0x8A26092C142A1D01ULL
        },
        {
            0x2B4148D2A1A5B67DULL, 0xB3B6E63DB19F1F25ULL, 0x4BE4746C61D06173ULL, 0xC208501EC58AD245ULL, 
            0xA4C95076AA201755ULL, 0xFE8A4B133F546897ULL, 0x854E8781163A2395ULL, 0xE621C706895A251DULL, 
            0x781B825FCB71BDFEULL, 0xFE621D4E5C370995ULL, 0x82341CDC8F022753ULL, 0xF14BE1026C5C0963ULL, 
            0x09C1B5767C185010ULL, 0x8560A8521BA3C2B6ULL, 0x2417F521356D9936ULL, 0xD3A0E48153E4173AULL, 
            0x88AF30A3656CAD7BULL, 0xDDD615220C22D85CULL, 0xD87E6C6E05098407ULL, 0x689C93CBF103F12FULL, 
            0x3456100A27D2FD21ULL, 0xD2A33A443AD3825DULL, 0x5390EAEFA55286B0ULL, 0x33431B8EA19FF5FEULL, 
            0x8E435918090E374BULL, 0x31A3A5FD27413A24ULL, 0xE2E9A861255B5EA3ULL, 0x5CB9B99FAEF3A671ULL, 
            0x997B3DF9A7525734ULL, 0xE67A267724C30BBCULL, 0x41D48284F512E099ULL, 0x2FCE7944460338A0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseCConstants = {
    0x44D87AA26C9E8B20ULL,
    0x6F462A020923E54AULL,
    0x480641A6EA54F8F4ULL,
    0x44D87AA26C9E8B20ULL,
    0x6F462A020923E54AULL,
    0x480641A6EA54F8F4ULL,
    0x67A43C1AF06DEDDAULL,
    0x1B4C4732ACD54407ULL,
    0x09,
    0x2B,
    0xCC,
    0x25,
    0xA7,
    0x9F,
    0x1F,
    0x37
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseDSalts = {
    {
        {
            0x91FA126615E26D93ULL, 0xEC8B42F24F443223ULL, 0xFD9C35BBFBDB6B37ULL, 0x707DDBA365119521ULL, 
            0x56FD2F77C1856795ULL, 0x01D469849097CD20ULL, 0xD4D903095844B8D1ULL, 0x42E02D8D42E9CBFBULL, 
            0x6F2055095A31BD72ULL, 0xA52818668F936EF3ULL, 0x512197713544DD86ULL, 0x1BC44080B934C9B8ULL, 
            0xBAAB2A823781E485ULL, 0xAAC04C12973ED680ULL, 0x58EB85084B0F96F7ULL, 0x75CD527D8DA38D2DULL, 
            0x5FBE51DC320C4B13ULL, 0x69B83A07479CA3F4ULL, 0x9D347DF6640D2AB2ULL, 0x31BA35955EA15017ULL, 
            0xDB585AF666B9B096ULL, 0x959FDB8E6EDA011BULL, 0x582BA015B3F58AD5ULL, 0x43FC9514E0727605ULL, 
            0x320C9BB3E9AE3126ULL, 0x52F75668C514D552ULL, 0xD0D02C86DCE8C04BULL, 0x2EFC22B83FFFAB06ULL, 
            0xB4BA6C15A963792EULL, 0x32019FA48253714FULL, 0x940AD20F1411EB87ULL, 0x640BB60F1F6FDFFCULL
        },
        {
            0x1379F84D04989688ULL, 0xA31DCADDCBA0FF4FULL, 0x1E4C4020C2FDA055ULL, 0x6BB6C79DFB963CD4ULL, 
            0xEB2C68C4F93A6625ULL, 0xBF7278446CDE6C1AULL, 0xD38AE54EBFB113E3ULL, 0xF1DBCAE6A3E30491ULL, 
            0x50FB260291DBFE98ULL, 0xE2CA797DBDACA983ULL, 0x474D11B44C5791E3ULL, 0x2637C861F3717F7FULL, 
            0xDA9D792889023129ULL, 0x25381C9B374B9A21ULL, 0xEC5F58783D31D950ULL, 0xD6958A723107959DULL, 
            0x0B2F6E1A18ADB4A6ULL, 0x66F51FB132B15635ULL, 0xC331DFB636C7B2A3ULL, 0xB694591B9845350DULL, 
            0xDC28067AE7CE90F1ULL, 0x65D6005338FC9AE6ULL, 0x0B771C41E7CF8154ULL, 0x9044CEE6A94FE554ULL, 
            0xE4654D619BB2AC9AULL, 0x8926D709D9F9E37CULL, 0x4DD6E16515257308ULL, 0x36E9A7FF8A7ACF29ULL, 
            0x4E7CAF4596885DE4ULL, 0x111BAD3E8A9B3130ULL, 0x232481AFECA12A2BULL, 0xF8FE1C9880D651D5ULL
        },
        {
            0x22B64093D4B6AD13ULL, 0x53A5074EA1E0CDA9ULL, 0x264DD210F48BC9BDULL, 0x52AFB4E8DDA19E1BULL, 
            0x85FCEC19AC6D1A45ULL, 0xDAEA348F00BB7DA3ULL, 0xB7A2CFD9DAA5470EULL, 0x0EDA18112B9AA8FEULL, 
            0xC37CB72EA7D4E642ULL, 0x01504209625D3F5FULL, 0xEC833D86F481F881ULL, 0x37C3F26C08422A57ULL, 
            0x8E2B7946E9D35DE5ULL, 0x34BABA4A62F5CC0BULL, 0xE09B06B8EC91327FULL, 0xAF4474247A76CE06ULL, 
            0x91699DC2C7B4AD4BULL, 0xC3EB5C601795D196ULL, 0x75FF0B079031AF6AULL, 0x3104202BD4B58364ULL, 
            0xCC27D6D954B58D8BULL, 0x69A52D55B9E6ADEAULL, 0x3E0A3C832489C5F2ULL, 0x2061CC1B39360FB5ULL, 
            0x3D9DBEB9C45991EEULL, 0xD475EB14AC6FF2D3ULL, 0xAE4A90EB25817FF7ULL, 0xD1FBE5BE8B8819F8ULL, 
            0x3052FB67C12F22F7ULL, 0x5A3811C800360883ULL, 0x9374A760CE674350ULL, 0x3322E7E7161A71C6ULL
        },
        {
            0x078C57F2E4DF61E7ULL, 0x96E3D663105A0C17ULL, 0x26F8497C8AA69CB9ULL, 0xF653B32FA81F5553ULL, 
            0x5C8F2D28570F9AABULL, 0xD7C1E63AEF930F3FULL, 0x7112AB44638950F9ULL, 0x21635D9C56BD0748ULL, 
            0x0EED8D7A4689D197ULL, 0xC7E3BF8E3A0B55E5ULL, 0x395292BCD55FD6FBULL, 0x637F34134154619BULL, 
            0xF5F31F8981422FC5ULL, 0xCD597DF4C88DEE53ULL, 0xFE7B790522AA8C77ULL, 0x5B3B4B1BF31F856EULL, 
            0x887C26CD96F940C2ULL, 0x00FAB9A262A7BAF0ULL, 0xD52532C8CA4DA2D1ULL, 0xA769E906BBF2BB06ULL, 
            0x0161279E5B2F2CAFULL, 0x6038D1458FAD7D9CULL, 0xC525B09E994A509EULL, 0x4C7F4D62180DFA9CULL, 
            0x0CB955986066BC10ULL, 0x79B7555AFC494498ULL, 0x36D32FB1EFBB3D19ULL, 0xC986060C1329746AULL, 
            0x35E20CCAB3722407ULL, 0xE893E478E2B4436FULL, 0xC79AA46FE48E664EULL, 0x48539BC2C19FD746ULL
        },
        {
            0xF0BC03F3E58A94D8ULL, 0x7127B7B7A64CAA1AULL, 0x19CE6E0BC4BAC685ULL, 0x78731213431D7488ULL, 
            0x5C47BF8956226649ULL, 0x5E71F3E34E2A4D33ULL, 0x1A582A254DBDD593ULL, 0xA676D148A737D1B7ULL, 
            0x8F62247D98869CA8ULL, 0xBB68519CD040D040ULL, 0x1B2CD454D1D7401CULL, 0x897DFE35A395EC49ULL, 
            0xB1BAD4DE55BABF24ULL, 0xB489ED3F63BF22B8ULL, 0x425FF206CE08BE88ULL, 0xDAA6942981C4657FULL, 
            0x750DC43C1BB2A048ULL, 0x2C43A977CFA70751ULL, 0x196BEE73D7498624ULL, 0xC19A25E8D7D22690ULL, 
            0x5E8B716BDA164671ULL, 0x4163C80236FF472CULL, 0xC86E4F0C58B08FF2ULL, 0x714D56780A0DDC1AULL, 
            0x74AED47A8D469C56ULL, 0xF8C0CAEA84308E90ULL, 0x13BF2E23CF9E490FULL, 0xA9891098A42F61A3ULL, 
            0x2C007C8A79754E3CULL, 0x9B7730DBABFDDAB2ULL, 0x3074B95771D35BC6ULL, 0x28EE63502F078C54ULL
        },
        {
            0x1480EDDCEC5F1F87ULL, 0x7E568B48609B4918ULL, 0xE8F0955B9375023CULL, 0xC70AF611E6F3DE7EULL, 
            0x1AD4D2D79A37662BULL, 0xA18C7A28030B815EULL, 0x420C2E1B22CE39F7ULL, 0x55DE90158B42C81CULL, 
            0x68169782D96DDAF8ULL, 0xFCE3E47CA2BCD608ULL, 0x469C08E70CA90303ULL, 0xE9EB122B2E14BCCEULL, 
            0x46DC128D72982D85ULL, 0x7FC2EF655C0C9EB7ULL, 0x18AD1E67AE5B6DC3ULL, 0x2FE4EC9AAF658783ULL, 
            0x09C73574DE65FB8EULL, 0xEC5FCEEC0CE7F484ULL, 0x1D9DF2014EEFD15CULL, 0x313F5967317A0230ULL, 
            0xF2D739A3237231BAULL, 0x82CA6DC516C25B90ULL, 0x2A2356D2651791CEULL, 0x8287FAF4171F9331ULL, 
            0x3F7880EBFE7B59D4ULL, 0x291A3CB27E349906ULL, 0xE46A5C6742BC1A8EULL, 0xB3507522A773F567ULL, 
            0x7764EA6C1C89E8B3ULL, 0xD075A74534269DF1ULL, 0x96E1FAB5F4F047BEULL, 0x7D591816D2EDA562ULL
        }
    },
    {
        {
            0x5C63022705F70B4FULL, 0xC526B4822C05723EULL, 0x4C81084097989E1FULL, 0x171352FE224A9ED4ULL, 
            0x679CCA95A42D4D13ULL, 0xE403E8FBC5E8F423ULL, 0xEA9D64DF202CDE27ULL, 0xB645D345FCF4A803ULL, 
            0x9B77B50FC23CC62AULL, 0x8A7DC6F8A75B077CULL, 0xC38312BF65476EFFULL, 0x04054954016B292FULL, 
            0xB962F0E2B8E538BFULL, 0x73BC8A0F4005FCE8ULL, 0x56A0DC68F860C825ULL, 0xC26B02E093ED2EA3ULL, 
            0xA2590AA5C68D0379ULL, 0xBFD3459C63E3C9A2ULL, 0xD7C0928E632A6E59ULL, 0x17AFE3D80653BF92ULL, 
            0x1FD8B75AA441C00CULL, 0xBE5E0EEB5A73671BULL, 0xD468EE26FDFEC754ULL, 0x43165C9D261136A3ULL, 
            0x6E1EF7C506810EB3ULL, 0x1678936BB23F1B67ULL, 0x19924C6C0E435662ULL, 0x9382776E329B8C5AULL, 
            0xFDC2DB65C0531452ULL, 0x918DC1EA3C2E7909ULL, 0x9F3098D580A35496ULL, 0x19F99BB92894C860ULL
        },
        {
            0x8F8BFD60FAE3CF07ULL, 0x8D6414B5ED38C475ULL, 0x60CE20CACE5FF63EULL, 0xBC5AE8293F487B35ULL, 
            0xF93D55D3AC3196BEULL, 0x7B01D7B14D94050CULL, 0xC20AB38B9A81D3BBULL, 0x424C01188E417B93ULL, 
            0x529361FE8802EEAAULL, 0x797DA5E7D7FEA066ULL, 0xB34D81553F95E9E6ULL, 0x27F5AF75BFE102B0ULL, 
            0x8C2D1F298D0E2A64ULL, 0x603DBC130A727437ULL, 0xE66BC6C7AF9202BFULL, 0x5D7EC0AAF6B0127BULL, 
            0x15D984CAA044180AULL, 0x45015C7ECAF6DA9DULL, 0xE3BA15BDAC9934DCULL, 0x513EA72D6602504BULL, 
            0xA8EC0451B2E9A746ULL, 0xF13B2835A2688C9BULL, 0xB436EE3D4E7DBC1BULL, 0xE8E5C6957ACD57FDULL, 
            0xCFF537AE2621568DULL, 0x0B2362F141DD4E7AULL, 0x1DD0B5F6F96BC8C1ULL, 0xD3DFBED8223790B8ULL, 
            0x233D600041A4225BULL, 0xD43EA55BEA5E8741ULL, 0x28DE0AC91EC96F8CULL, 0x791295C8181E42F4ULL
        },
        {
            0x9659A149A4784963ULL, 0x98995BA6B758954BULL, 0x59B781DA379C7736ULL, 0x148CF192BE2CE7F8ULL, 
            0x835429DB94882EFCULL, 0xC4D6228D232C4F1CULL, 0xAC3F07A43A1B780AULL, 0xEC3A618DF50F4E4FULL, 
            0xA5BF0A696087216BULL, 0xE432D72381240106ULL, 0xFF5B528B7368D141ULL, 0x9382FAE536C8FADCULL, 
            0x7EA6069CA88F64E8ULL, 0x87C1D9133D293D91ULL, 0x578C6C14F00AECDAULL, 0x66966D19522ED149ULL, 
            0x52D819BA85EE861EULL, 0x10E4FA70DF5BB6A0ULL, 0x64E983263B339E86ULL, 0x6E402ECF27CB710DULL, 
            0x9B250A0CAF29EABEULL, 0x8F422F1EB4DA27A2ULL, 0x743CB2C77360EC00ULL, 0x5C5E617F363B02A9ULL, 
            0x8E77373C88CC1CD3ULL, 0xC7F434380FB4266DULL, 0x66CDDD0D4180918DULL, 0x648F0BC905F6F1A5ULL, 
            0x0733B2A55D3F44C0ULL, 0x012F1C692F87815DULL, 0x41014E762436FDD6ULL, 0x799D1B41AE38D1FCULL
        },
        {
            0x9F44FBA89E4D4729ULL, 0xD36BB75530699230ULL, 0xA19483451BC9AF94ULL, 0x4E30265F869F6C4BULL, 
            0x24FD392B45FDBEA9ULL, 0xCB43B54817BCB262ULL, 0xFD9C2037FD6F154AULL, 0xEA0F7E79CAE6C9BCULL, 
            0x327123C04661F1A1ULL, 0xFBDBD0565F273A71ULL, 0x0361B24F505848FEULL, 0xF197A855BEEA2525ULL, 
            0x2F93168427D449FDULL, 0x1BB629500C6CD577ULL, 0xF74899B1F0A6FCDEULL, 0x274F6B5BC0C6EA14ULL, 
            0x52CDD800FA803227ULL, 0x24AA02D24103E921ULL, 0xCB2BA4C26C798BF8ULL, 0x3AA2A960DE139536ULL, 
            0x3A67111E7DB8E725ULL, 0x26CF7832C86CB67CULL, 0xB2BE772A6A0FBE90ULL, 0x3A7A572DD0E144DBULL, 
            0xA9867F4388F00CE4ULL, 0x2DB78BE8D3D0F9F4ULL, 0x9C5929212AED6ED3ULL, 0xB8AB685DB845D04EULL, 
            0x0E10F612A7776A15ULL, 0xEBA18A37220D4BBBULL, 0x6B5913CC3C81E4ECULL, 0xA08FB55AA8BAA014ULL
        },
        {
            0x34AC5DF7FAD67789ULL, 0x8BA2E1FAB9E33C01ULL, 0xB5F3E4DD1E10365EULL, 0x9ADFE8A5468C0F8DULL, 
            0x2273593ED4C667E4ULL, 0xD5431F621AB42947ULL, 0xDD627BBEE581DD0BULL, 0x9ACF5D3C7582A651ULL, 
            0xD71EF60FD27564D4ULL, 0x7BEDC1FE9E6566FDULL, 0x86EC74021E029CE5ULL, 0x07C7156C79451777ULL, 
            0x0200C4A834ABD031ULL, 0xD50B42988B3EEA10ULL, 0xDFBB598B08E00BE9ULL, 0x6E21C472847EE1D0ULL, 
            0xA619826CB542E65EULL, 0x0C94C997440DAF60ULL, 0x3C4AA9C5DD67C8C6ULL, 0x14FC04AFF6A6B0BCULL, 
            0xEAB6844871C2CB4DULL, 0x21FAC7E0CA6095FCULL, 0x1E486F01EBDF1A39ULL, 0x45522D8822E64F75ULL, 
            0xFA4853B57706AC5AULL, 0x3CC0EE4AF9D77487ULL, 0x5CA3701585E2FB3AULL, 0x370F21EEB40C6BF9ULL, 
            0x7671043C8DCB4CB5ULL, 0x00A53D254452ADC1ULL, 0xB1EF2A79F554CDBAULL, 0x51A13B0C83120E3AULL
        },
        {
            0xFB90FA5FAC9D3AD4ULL, 0xD95004B3FCF3F98FULL, 0x5FA1EC3333BF8C17ULL, 0x72A615A5C9107C54ULL, 
            0x6CEA058F979F5408ULL, 0xACC9D7B12363E288ULL, 0x504C7BDF6F8457C7ULL, 0xF9451627626A0E0DULL, 
            0x25E0A3B653DC1957ULL, 0x4D9AFF2B1A3C4C33ULL, 0x43351016D688C4D7ULL, 0xD0561EC882BC8094ULL, 
            0xD122B8C2AF18F0B2ULL, 0x35352301C0A4DA4FULL, 0x2D21BDCCEBB44C50ULL, 0x6F4F468193756315ULL, 
            0xEE033BFCEED1445EULL, 0xBA07B82B3DF00B8CULL, 0xF10429233829BAB1ULL, 0xAE7E796F4A6C19CCULL, 
            0xB70182C0C6315DBFULL, 0x939E1DFD81017010ULL, 0x3A786D0D87BAF656ULL, 0x0A24D990A204BF6DULL, 
            0x1ECBF732074E74AFULL, 0x948B7808ED88CCA3ULL, 0xB6083BBF83953DB8ULL, 0xB292E75AAECB99E6ULL, 
            0xE9655D0CEB964F73ULL, 0x933F8903177FA966ULL, 0xB51B61327CD6BB1CULL, 0x2CD165CF1CBE1E1DULL
        }
    },
    {
        {
            0x592609654137A4AAULL, 0xDABF28E1ED025B9FULL, 0x27CBA50583C2317CULL, 0x0FED1C0D311B8A91ULL, 
            0x2933B2FC8CF71E4DULL, 0x82A9248DFA4796DBULL, 0xF6B68F623A168CDCULL, 0xBB541C9687E5DD62ULL, 
            0x33F59A139B7D3114ULL, 0x4C664E96F9346562ULL, 0xD395FE6DF3BE6C6FULL, 0xC9D1112DB55F2B81ULL, 
            0x2A3A99CA61BF8057ULL, 0x64DF138607669DB4ULL, 0x40AA0EDCDA037F97ULL, 0x06238820F7A2CB8CULL, 
            0xC6B27597C4ADF9DEULL, 0x56135CF7F932FA27ULL, 0xE5E80E7ADCF39289ULL, 0x17A4CEEA507FAD6EULL, 
            0x20E5710FA20E1ACDULL, 0x12231896109A44F1ULL, 0x2A111589CCBEC7B9ULL, 0x4F2F10A7C80C9169ULL, 
            0x9C711A3C7ACEB620ULL, 0x466B56B011326411ULL, 0x00F17FC458469CC9ULL, 0x3DAF83E397F2DF85ULL, 
            0xCDF652418A2D0B43ULL, 0x5C8862601CD5587FULL, 0xEFF413C1D59480D2ULL, 0x18D21ED47F5951F6ULL
        },
        {
            0x64E1C035DFC5DD3DULL, 0x20FB15823DA0313DULL, 0x27380F123E333A01ULL, 0x17DE9F4BAC648FA9ULL, 
            0xDDF5AFE031F8F25FULL, 0xC5BA57359D08A184ULL, 0x15F9355744C1D2E1ULL, 0x3F5B750F4AFA1861ULL, 
            0xFEE6005EBBF8C171ULL, 0xF29B077E19A9F6AFULL, 0xA72EBA262C2DC86FULL, 0x0F2CC20E1CF47A78ULL, 
            0xEA7341E0885649F3ULL, 0x2A1F4D93597886DBULL, 0xA908749ACC6CF6D7ULL, 0x31AA458A0C1F82F0ULL, 
            0x3A898189AE20BA0FULL, 0xC3D034D7697C0230ULL, 0xF039EC352EC87B7CULL, 0x7644C83033B93F95ULL, 
            0x15886222102DBFF2ULL, 0x3355B51198D79D13ULL, 0x549D8CE5F8A6D84BULL, 0x18FFA1E167711D19ULL, 
            0xE9128EBA551C8E9EULL, 0x8345FB9D59610A4FULL, 0xBFF39534DFA94C50ULL, 0x5AD1CC2CAA97F451ULL, 
            0xFF6C788A63352397ULL, 0xDBBBB23914A9C135ULL, 0x099C37C0EEF7D727ULL, 0xE49F69FF35C22AF8ULL
        },
        {
            0x9F8FB09B4EE837C9ULL, 0x945078DB7FDAEB4DULL, 0x931291E91A5A1FCEULL, 0xCA9E2CF659443F8AULL, 
            0xD5612D536500C902ULL, 0x00EB5C37A297CA67ULL, 0x41CC7F700911C28AULL, 0x4D855C5D0033F0F8ULL, 
            0xC9B9138E3570A325ULL, 0xC6B71FE9057E87D6ULL, 0x86EF2DB4E4ADB027ULL, 0xC112D1A8AE747410ULL, 
            0x1770010CDE86914FULL, 0x0FED6B48A9AED6A4ULL, 0x109AC039191EA264ULL, 0xF2B1B95F05CC50B1ULL, 
            0x5D5A2541F31566ACULL, 0x687A32360775294EULL, 0x22DDA3C5C75CEE7AULL, 0xB3A2C66A6E58DCF4ULL, 
            0x03A9F046B083D70BULL, 0x633981243B43BCE1ULL, 0xC5E241B1DFE3917DULL, 0x5BC38EB22CCA7432ULL, 
            0x8D31B2B3A3151083ULL, 0x1A8618C7EE7FBD1BULL, 0x612587292B96BF1AULL, 0xDBDB7180C38309D0ULL, 
            0x249511076903E4F6ULL, 0xA61DAB8B5F5F7F1BULL, 0xEE7CB26B756731E5ULL, 0x4C95C7855015B980ULL
        },
        {
            0x17DFAAD46040163FULL, 0xBD889E855D814273ULL, 0xE097737AF3FF7DF8ULL, 0xED5DF7982E7312F6ULL, 
            0x6E7185451AC14602ULL, 0xB7EF45825F2FF71CULL, 0x5D59F26ED863B521ULL, 0xA20BF392E0FA58BCULL, 
            0x711F0A8014991DD0ULL, 0x1320B5F70F6BC13AULL, 0x5FF48644BD066E65ULL, 0x9D1BE48031F74420ULL, 
            0xA247C6069D52FA8AULL, 0xC8C3A5370774F34AULL, 0x34F2753C4A028F62ULL, 0x10F8B457EAAD9F33ULL, 
            0x866B03A63055BD1AULL, 0x029044693729BE49ULL, 0x74FAB191DE936937ULL, 0xA5110C1D87E645E9ULL, 
            0x8ED2B2C67E912300ULL, 0x2E95D21E2087F8C1ULL, 0x82EDB229039E27A4ULL, 0x95EDCE77552DD832ULL, 
            0x31D1514C0FF79046ULL, 0x22CB1B735B9BED90ULL, 0xE7D440E4178C9D15ULL, 0xCC66E36BB5B58387ULL, 
            0xA252AB588AC20C03ULL, 0x0D509A45F54BDEE5ULL, 0xBC7357A3F5A3F4DEULL, 0x20E13D0B7684BE0FULL
        },
        {
            0xD985145E723B47D1ULL, 0xB5D37FB833A0E45DULL, 0xE69143241532C7BAULL, 0x72A709740A46BCF8ULL, 
            0x028612EA5D35A279ULL, 0xAC75FB2D6A3E37A0ULL, 0x8E2E2DB0091DCC16ULL, 0x5BADA1773614590EULL, 
            0xE81B7D751FF57D08ULL, 0xF909346C4AF895C3ULL, 0xDFD45958BEC8A593ULL, 0x0D8C5F4677CFD3D9ULL, 
            0xC0C79DA5E2E1F1C9ULL, 0xD267BD3C124F4224ULL, 0xBA0FCA59124812F1ULL, 0xA96328E6CB5AC2DDULL, 
            0x898C4EE527FDCCADULL, 0xF36D3A330300301AULL, 0xBA31A25928B75B36ULL, 0xD46DA721B630C4B4ULL, 
            0x88D77C59DF5DA4BDULL, 0xAD93FAE1379D69B3ULL, 0xDD42A3A1137C2CB0ULL, 0x6D53FDC84A0FE9F1ULL, 
            0x5A77B3DF9162428CULL, 0xE36037F820CC02E3ULL, 0x12EC47555A187642ULL, 0xE7C7B686B301D569ULL, 
            0xBE8509DE9966B535ULL, 0xE15E647FB8D66FB0ULL, 0x546521509C32D59DULL, 0x5F1F333406ED02F6ULL
        },
        {
            0xF7E22049B60597C2ULL, 0xC31CEAA1493A0AEBULL, 0x527571A7F9BB1E2BULL, 0xC873CF28D346EF2EULL, 
            0x7CE008672CB3C148ULL, 0x3DE27529954BBD9BULL, 0x0532EFC8C2E441B9ULL, 0x9A64687ECAAF642CULL, 
            0xE359486CA49E187BULL, 0xA56519BA8BBD185EULL, 0xC80F8AD11E884A01ULL, 0xC356E3E6E63F0FD9ULL, 
            0xC2F9C099B458F7ACULL, 0x4BADEB0A94AD7119ULL, 0x6B2FD5B50F71F8A9ULL, 0xCA74F402D8559FA3ULL, 
            0xB5A91282E25591D1ULL, 0x5929883C65DB0DF0ULL, 0x28A558277D2C432EULL, 0xFC59924A63C95E3AULL, 
            0xAA0BDC7FD7FEC3C0ULL, 0xA66C999911BA2046ULL, 0x37BE4BFB7FA00CF1ULL, 0x4FE42DCF2BB0D085ULL, 
            0x8F415978FBCC8766ULL, 0xACF280A8F9DFB4ACULL, 0xA008A0DD2F270816ULL, 0x3EACDE832747EF01ULL, 
            0x472C7AD755C9C09AULL, 0x8330F6C2633512C8ULL, 0x4F1B28C59FE331CBULL, 0x09AD58ADB8A62735ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseDConstants = {
    0x5FDC9BAAB6BB1605ULL,
    0x6C9B22072E0049BAULL,
    0x9F7D01F47EFCB43BULL,
    0x5FDC9BAAB6BB1605ULL,
    0x6C9B22072E0049BAULL,
    0x9F7D01F47EFCB43BULL,
    0xFA04A79B6E4047BAULL,
    0x728CE03EFA44A0CCULL,
    0x65,
    0xB9,
    0xA2,
    0xD1,
    0x26,
    0xAF,
    0x33,
    0xA6
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseESalts = {
    {
        {
            0x9465C90F6E209D3AULL, 0xD758E32438C1F95BULL, 0x40F7ACFCA7A10184ULL, 0x6DBD19FEA64E0F69ULL, 
            0x3CDDA9F8EFE902BBULL, 0x81B03A2E5EA30658ULL, 0xE84189D13B431A03ULL, 0x9B0128B7704E7667ULL, 
            0xB4ED5846800B056AULL, 0xFE8D8FEE7885BA09ULL, 0x91C94C16864CA9D9ULL, 0xEBA65133316B199AULL, 
            0x8337FB9E23B6DB81ULL, 0x6C8E4D26AFABFEF4ULL, 0xAE49E21B5EA140F4ULL, 0x6157A00E12092202ULL, 
            0xEDE07116A7EA2EC9ULL, 0x3BCFF3691A39F303ULL, 0x99588BA82ABAED55ULL, 0xD622375D84B01F6CULL, 
            0x07A778B5201222FEULL, 0xD623454F74DFBE7AULL, 0x798225CF6D7FD38AULL, 0x28766235A24618D9ULL, 
            0x26DDD17DA19B5087ULL, 0x97BCAB89DA1FA28BULL, 0x68E9B38EFD6562EAULL, 0x79F1D58DA4646B62ULL, 
            0x2A05036647D2A5B6ULL, 0x1EF7A283A742D071ULL, 0x5CDC477C99CD1AE8ULL, 0x931737EC39008FDAULL
        },
        {
            0xE98BEAD15E830BBBULL, 0x880514A31D02E95DULL, 0xCFF9EC19C0420FA2ULL, 0x246B0ACD5D3CCA87ULL, 
            0xA1FB6EFBAF65A51CULL, 0x94B1BE719598DDF8ULL, 0xFA666D9D54B849F6ULL, 0xB0915E60A70C7ECAULL, 
            0x34D3C74321CAC1DFULL, 0x81EF131DB1F16C23ULL, 0xE6FDC7E262F36F1BULL, 0xF465017EE69C15F3ULL, 
            0x1002AC67FBF79FA7ULL, 0x1EF85BF29B5DF14AULL, 0x6D0A471D9E119496ULL, 0x6A1A21D52A20F23CULL, 
            0x7D3F8FCFDA573DF5ULL, 0xD95B27F148F62F13ULL, 0xC010F6196E37ACFBULL, 0xF214B9CAC92D9E9AULL, 
            0xEE7264F3C502CE5DULL, 0xA5228D5C3FB2CE93ULL, 0xAA017F135CC04A1CULL, 0x2A48F10FB89648CAULL, 
            0xAAEADBECC01209BBULL, 0x52F6ABABFD843CB4ULL, 0x2AB399B5CA2B81F0ULL, 0x8A73CF6CDB3A8B48ULL, 
            0xC3FC35BBCCB782C3ULL, 0x24D4DB9FF5FC3E1EULL, 0xAF38E51E01909031ULL, 0xE6945317FCA06A46ULL
        },
        {
            0xCAEA66FD344E0E6FULL, 0x09E3B045565A3BF6ULL, 0xD09E9C1ABF608101ULL, 0x378880DF25C5BFD8ULL, 
            0xF7F500FFDD991D16ULL, 0x8F460F55F3580371ULL, 0x4BEBCB61C2E288C7ULL, 0xDCC9CC52FE04BC87ULL, 
            0xEBD2406B9AF488A1ULL, 0x8C6C6A44C98DEE0AULL, 0x7CDC6D40A6FC90EDULL, 0x3AE3D206BCF674CBULL, 
            0x7A2AA77C7A8DA579ULL, 0xA3E257936465EC15ULL, 0x3D416C60EC9F7610ULL, 0xA11FF6B8B519BFA0ULL, 
            0x2F43BA6E1EE4AB4DULL, 0x29C748A25B6ABEC7ULL, 0x74F624E888C140A4ULL, 0x2A91F1F390C8D98FULL, 
            0x646439C3905BECDBULL, 0x4F31105649C57E7CULL, 0xF2FAFC539F237B3FULL, 0x87A6F0387975984BULL, 
            0x3B615FAF9159407FULL, 0xCB892F5612743C4BULL, 0xDE3207CE98455086ULL, 0x311105AD28537B59ULL, 
            0xFE3FAB15CEFB17C8ULL, 0xF9E5F8399B541798ULL, 0x74985629DE0CBB50ULL, 0xCD6C6A0AA3B3DAEFULL
        },
        {
            0xBC7FE1E863FCA300ULL, 0x82B8C361366339BFULL, 0x9E55562BE549DB7FULL, 0xFD0C7FBB66CA80CFULL, 
            0xEBA9C858A49EA710ULL, 0x5E6C3AF4835DE1E2ULL, 0x5CEE6FDF3C5C6B8EULL, 0x94F9239A53DF7451ULL, 
            0x6A7A3960D8D43AEBULL, 0x978823BAF71442E6ULL, 0x73AEF660A94B6E2AULL, 0x23EB0D887CB319E4ULL, 
            0x1FC4DED1B3D8D36FULL, 0xFC4615FED407234CULL, 0xFE0539163EE2BAD6ULL, 0x40DF3F1692CF4C39ULL, 
            0xB2B4EC69F41E9762ULL, 0x94EB6D4A8F20FB24ULL, 0x3B764E0F5BEBB2A5ULL, 0xB44A629941E1A40EULL, 
            0x94C52CA05F460E81ULL, 0x4033CF8C14341276ULL, 0x8A6F52C32E0CDDA9ULL, 0xEB467B3A6C1FAD68ULL, 
            0x454D76BF44499FA9ULL, 0x2E361F5B0058A4DEULL, 0xB0509C62B1F1712CULL, 0xBA66E025187294DBULL, 
            0x45740DCB042C768CULL, 0xE16D5C31F9239412ULL, 0xF0FEABD88111E28EULL, 0x2D794E7AA484E561ULL
        },
        {
            0x0AA75E4F883FD787ULL, 0x4CE44F9779A86CE7ULL, 0xA642840B842193CFULL, 0x7C611BC826DD85FAULL, 
            0xE87EA547208874EDULL, 0x95A80DF5FAD30FD8ULL, 0xD3BBFD0135DEB945ULL, 0xD65CE5AAE49C0CA0ULL, 
            0x908AA9234286CCB2ULL, 0x8A4E78C36378BAEAULL, 0x5F7C5A38C80B1811ULL, 0xC1F2A8EDD3900A98ULL, 
            0x0CA6F1AAC2695A5CULL, 0xD1BB1F0AB5372B9EULL, 0x0C1752703755777BULL, 0xE0ABE77E6E98DE82ULL, 
            0x9A2421BEA801680EULL, 0xD61FE4901D043B05ULL, 0x9C7BBFCDCB0297F8ULL, 0x1B69F79947510D56ULL, 
            0x2D683A7400A70F27ULL, 0xCF5AD2CF816325D9ULL, 0xAC9CF4D313B2AD2AULL, 0xE93787B6E8158CF8ULL, 
            0xF424C3F2E0E6A1E4ULL, 0xE079BC8518AAE577ULL, 0xC4073DA5B699E8C3ULL, 0xED0539DC761F2154ULL, 
            0x6C8D61FD5F52444EULL, 0xFD658DED09E568CFULL, 0x94C97C4EE1304275ULL, 0x1D4A027C6147275BULL
        },
        {
            0x569FAC1361D6A76FULL, 0x7A4EC20B40FF2EEBULL, 0xF59DD3D0D7FF942AULL, 0x8CA4D035910A246CULL, 
            0x688AA453B31E4916ULL, 0xC83127923AE066ECULL, 0x06D15A48AAE58570ULL, 0x37908B387905F347ULL, 
            0x17E7FA598970C888ULL, 0x88E9956D2D2DCC02ULL, 0x9CB0D4F2E839EC1BULL, 0x36DFE20C3E3601ADULL, 
            0x81A1C007595CB7B0ULL, 0x422B05BB11B2AF1BULL, 0x0562D258074E8F19ULL, 0x78991C75487895A5ULL, 
            0xF3438A97B6E80591ULL, 0x0A5BA6E7D78E16E5ULL, 0xFD0146927EA8B81EULL, 0xCFAC3291092923CAULL, 
            0x808846777C130040ULL, 0x1876A02BC1522E54ULL, 0x29116A6FC2AF81A7ULL, 0x7A9999F1821DE4B1ULL, 
            0x293357CB2057BF46ULL, 0x6694580E4FED8483ULL, 0x19072F4CCC5A6A27ULL, 0xD564D5D59CF28AA2ULL, 
            0x3D58BD040B938CDAULL, 0x7D176612EFED4BFCULL, 0x319382F54A6F2C70ULL, 0xF4AAA23756DBE061ULL
        }
    },
    {
        {
            0x2A78FEE745B3B1F6ULL, 0xE24A766ABE6352EAULL, 0xB1C698CCF63CA825ULL, 0xBFD42C8EE0E2BC90ULL, 
            0xDEECA0B3B227DE7EULL, 0x6EA05914DEBDD412ULL, 0xAE08E89F1D6077C6ULL, 0x79B0EEF342692B43ULL, 
            0x6176023F8F25AA2EULL, 0xB4C89511AB215982ULL, 0x1312F5E73BC324AEULL, 0xAFC3574603470CF1ULL, 
            0x136C131EE2BFAA5FULL, 0x0DA2EAF3DD7905A7ULL, 0x0CC4FF7F6F6CD39FULL, 0x858B7EF11814425FULL, 
            0x8A030A06946640FFULL, 0xC59A62F1A330A946ULL, 0xE6455652EB2910D8ULL, 0xA1C83D8C5C559DB1ULL, 
            0xA66B869A1B926AC9ULL, 0x99A5ECAB830AC971ULL, 0x686FEC9DCD3DEFB0ULL, 0x1D3D8DB36E65DADCULL, 
            0x6724602E73B97659ULL, 0x77C01AB0CEE7FD4AULL, 0xB72CA25C21A14358ULL, 0xE8BEC836DB37A5F7ULL, 
            0x79688036B66EB0BAULL, 0x26B31F26817E35E1ULL, 0xBC5261CB0D49ED04ULL, 0xD52F7A1DFC2DA5E9ULL
        },
        {
            0x1B5BF624A37AEFACULL, 0x8CDB6FC09DAE1D72ULL, 0x9008F7FB4FCEDEE2ULL, 0x2382CE0C64AD6BBBULL, 
            0x9796778AD161F1CFULL, 0xEE2F441A97387AFCULL, 0x62E9AFDB48C73BF9ULL, 0xDC8FC2A50E5387CFULL, 
            0xB54B52D2430745CBULL, 0xAB842E5A53E58DA7ULL, 0x17EB33A3B8D72D55ULL, 0xDDA07D91A465A3D4ULL, 
            0x87CFB531653C796FULL, 0x796D55D472661EB2ULL, 0x28836650EC29CDE6ULL, 0x6BCE2FE3B1D81721ULL, 
            0x9C67EEF00798F310ULL, 0xA9BBACE4399C6AD2ULL, 0x10C1BC003C174299ULL, 0x8B401066E7F9071AULL, 
            0x5ED1AA678B6C5D6DULL, 0xFFA7EFDD99B5AF4EULL, 0x42BA7D4E8E952037ULL, 0x95FF37C886661290ULL, 
            0xB10E929977386F70ULL, 0x4A1BD88BD1DDD207ULL, 0x4862B311660D221BULL, 0xB1D8DDAE739390AAULL, 
            0xB92C6186B1E1D2EBULL, 0xCC8B5A45DABF6990ULL, 0xA9446853EA0682E6ULL, 0xA5B18D842C97D42AULL
        },
        {
            0x5890DEC7B327A3FFULL, 0x12E7FD3FA4BDF471ULL, 0x743DDA30E3DA9110ULL, 0x13CC8338AB8F3F76ULL, 
            0xE3E97758D46B72E4ULL, 0x49351301B51ECD69ULL, 0x2B0F8AEC4315FA2EULL, 0xFEBE6AE7A32E8598ULL, 
            0x9A15F83BC7204749ULL, 0x8BDC325F01110957ULL, 0x0C8CF9AC7A325066ULL, 0xB1BBDA942DC93F13ULL, 
            0x187CCD83E095D44EULL, 0x9D0AD69AAA7413C4ULL, 0xA7FD02AD707F933AULL, 0xA758F18C0F321353ULL, 
            0x78529AF710F2CEF8ULL, 0xBFFF973E3FD67F4DULL, 0x6FCDA7C9D80FFD9FULL, 0x49E03ACFAAA7919AULL, 
            0x0291A004831655DDULL, 0xFD5F73AC72D2C099ULL, 0x1533ABD8D044A718ULL, 0xC8AD87B9D625F6C0ULL, 
            0xEA82A54356F90E27ULL, 0x64432A055DD4F6D7ULL, 0x8EBE3049E8371A0BULL, 0x808A12D848EA5FD2ULL, 
            0xCC32EC32FCFE5B17ULL, 0x2E6DB1EEC9669D75ULL, 0xC61A6A133DB32DDEULL, 0xC6E3DAF9665DBC37ULL
        },
        {
            0x43EB2E736772994BULL, 0x65134ED5CEA57680ULL, 0xFDE0806BBD6349EBULL, 0xE44BE4F2E2FF0717ULL, 
            0x70568BA5D31B68CBULL, 0x9058B907F5BFF2D4ULL, 0xE83B6804D2B75E44ULL, 0x61DBD0520DCDC334ULL, 
            0xE1426568F5923400ULL, 0x191C8031EC2DF987ULL, 0x515C4F2511E8D25EULL, 0xA5386535C8F2F848ULL, 
            0x85D056D3473B5025ULL, 0xA503E2BF99F0C403ULL, 0xABB1955D4B2361A0ULL, 0x4D96EE94CA3E86FBULL, 
            0xE8B50F22CEA17578ULL, 0x0E4AC5FAD55A4852ULL, 0xBC4AA5C66884CBB9ULL, 0x7811546D92958605ULL, 
            0xD25DA94009DFC79BULL, 0x6F659E0247658237ULL, 0xFF3B41B8D9B90D1DULL, 0xA58678A74CFE3065ULL, 
            0x5845AE591837E33EULL, 0x5433FD808AE00355ULL, 0x7C263400E7E39179ULL, 0xD02B7F56CAC2DAC3ULL, 
            0xEAA82CB32D4BD49EULL, 0x9EAD7FA880A15336ULL, 0xA74836B320240F6CULL, 0xFD42B5DC2561EDE7ULL
        },
        {
            0x3CF4CCD36E8FCD1BULL, 0x7AFB58B9A6FCA0F4ULL, 0xBE5BEEB304C937B4ULL, 0x2495D487692E7CE5ULL, 
            0xEAE0614CCC134B64ULL, 0x458EB48791B68425ULL, 0x2E98A6BA1E6AD315ULL, 0x6A16826B3FEDBDAAULL, 
            0x6C7129CFA9FA5BABULL, 0x1B5E5461A728F8FCULL, 0xC7CD4B437C606BC5ULL, 0x97442F12526953DDULL, 
            0xEAFC4AA62C219D81ULL, 0xC9000E176B29D031ULL, 0x2FF96C086ADC848BULL, 0x7B17E2BDA979FFCAULL, 
            0x0A992CAED945B03CULL, 0x0F3CC9C4C36E2502ULL, 0xDC02922EB4713C26ULL, 0xAE40E375B5800C2EULL, 
            0x581957409C0F23F3ULL, 0xF1F7F2BB22C99A2DULL, 0x0EC5EEC3A96E6D37ULL, 0x54850BE0CFEAEF2DULL, 
            0xE3B59674219F6BDDULL, 0x1FC9CEDDC3AA9AAAULL, 0x71BB588EFD98D02EULL, 0x89DD306D8A591620ULL, 
            0x4BF4B0CBE9AA15CCULL, 0x55F6C26DB376887FULL, 0x30E8110793238E37ULL, 0xF8BECE767AA05EA8ULL
        },
        {
            0xBE5ED1A118BC514BULL, 0xAD2D350FF37FC98FULL, 0x2FC0D2BEE9699DF4ULL, 0x711A2FD5231018DCULL, 
            0xED8ECA15F4823770ULL, 0x604230C4FE22E62DULL, 0xDCC66148C7A255F5ULL, 0x1FDAA4BB8DD98D60ULL, 
            0x0CBD08EF605C3201ULL, 0x5E8B891467B7E654ULL, 0x27A7CFD4C9BBBECCULL, 0x12EBBD9C4593D76AULL, 
            0x69DDF86619AFF2D7ULL, 0xFEFFC2420976859FULL, 0xE6E083FB8738656AULL, 0x03A3CEB0FD97FEABULL, 
            0xAD77E8F92DC3C431ULL, 0xF13EAAB8922C7B5EULL, 0x166CFABB70256001ULL, 0x4CBF3AD87D186D16ULL, 
            0x9CF5A75805588C06ULL, 0xA2511625F383BFEEULL, 0xA7EB00024E8B1A8EULL, 0xDF023D81561B22BDULL, 
            0xD8034D60FF56C9B2ULL, 0x7E4603A5A9E727F2ULL, 0xF9BDA72DAA3E604DULL, 0x3D3E137071F2C661ULL, 
            0x958787125E87310CULL, 0xFCD587F83D969F87ULL, 0x29FB3B83AE79AB9EULL, 0x9BF6E8E5AC1DCCDDULL
        }
    },
    {
        {
            0x906BD8BA973CCE33ULL, 0x40B4E0C5F9B2998AULL, 0x4534DD618B389F86ULL, 0x3A4C4A39E7EF2348ULL, 
            0x8E474566945558EDULL, 0xE54DD4F156E0FAD7ULL, 0xD4E52DE519E71731ULL, 0xDAD999007159031CULL, 
            0x3F814775737B5C8EULL, 0x451A4DED07840C6EULL, 0xB498C073B62CAEFDULL, 0x57A658134EEDA1FEULL, 
            0xDA641C10A20E0FEBULL, 0x37A1C1CA1CCACF05ULL, 0x5F5961BA0EFDA036ULL, 0xB71EBC305C59199BULL, 
            0x5BF4C49DD4E8E7CAULL, 0x5D78F46B4DD80311ULL, 0x724CE77C376CC094ULL, 0x3BF8CED219B8EFA0ULL, 
            0x77F5695F2FD01DF8ULL, 0x8980D1E678799ADAULL, 0x1E070A085B1751A3ULL, 0x315E6A147E2F5528ULL, 
            0x23783CC2912EFCF8ULL, 0xE69D9BACA880F7FFULL, 0xD6ACABD9DDC3D2A3ULL, 0x803449024D225EC6ULL, 
            0x3FE3DCEF97512277ULL, 0x99C3B85F0D0EDB9AULL, 0x847CC29AF71B598EULL, 0xADA19C47D106D817ULL
        },
        {
            0xB18479D5910AB894ULL, 0x49E5C21C40C64D6FULL, 0x15FB99E35C2A7412ULL, 0x245171672193D965ULL, 
            0x316F1585BFC3B50FULL, 0x1F1EBA6C28F9099CULL, 0x539C6FA2114869B8ULL, 0x9C9816E4B324DB3FULL, 
            0xE7AF9FECEA3D7B80ULL, 0x53F74852DA7D3A48ULL, 0xA89CAE4C4AD78447ULL, 0xFC0F9C543AB2A96EULL, 
            0x17DF521109C06916ULL, 0x07FDE717DB21D4A6ULL, 0x52FC26F376A50775ULL, 0xC6EC4E92D34D6FD2ULL, 
            0xB715387D401F3EF7ULL, 0x0C48C40796FDD218ULL, 0x65F2FF35F1728FD6ULL, 0xBA5C60353FECD25DULL, 
            0x4CBA43284EAC4930ULL, 0x87EC50A8D23E690DULL, 0xC87D17A70F83D79CULL, 0x0F88FB94764DE633ULL, 
            0xA10BDD673A7704B6ULL, 0x2D76A068691CFF1CULL, 0x14D102F4EFF915CBULL, 0xAC78211AB72FE291ULL, 
            0xA7610B8F310D23A7ULL, 0x56443B93FC982F9DULL, 0x2ABEFFEF4A85F0D1ULL, 0x8C3DA5B6BADB3904ULL
        },
        {
            0x9AFA4E719D4F109AULL, 0x01CCA9DA9E063F73ULL, 0x6E3D4B9CE1840C5CULL, 0x87C8D93C4C1D174BULL, 
            0xFD7BCBE4298D26E0ULL, 0x491309D2D5C79834ULL, 0x99929DE1E48EBA41ULL, 0x6696D6348B3A0ABEULL, 
            0xC4C255EB934581D3ULL, 0xD0B1851E8759577DULL, 0x92752B9681D22FADULL, 0xCCAA8156BD8C4467ULL, 
            0x1AF7AEAA79084654ULL, 0x2094E27CC2F9D916ULL, 0x0999DC620AECE0D9ULL, 0x95E67BAD82AAC47AULL, 
            0xAD2ADA8201E572F2ULL, 0x679BBDA4427D40F7ULL, 0x6C7F63BB62D105A8ULL, 0x1BABAF092844245CULL, 
            0xE25A72F2868A40E3ULL, 0x4A603CB273B48B68ULL, 0x72FEC0D26DBDCDBAULL, 0xFFCB7246AC6C582DULL, 
            0x3FB82E9BD45DB409ULL, 0xD7A1C12201737FA5ULL, 0xBB875C435C3DB7D1ULL, 0xFA661D1D45DB0D87ULL, 
            0x75E2FE7853FDC001ULL, 0x043B9CFE37C1F795ULL, 0xAD5247FB6BBB1DD5ULL, 0x055C270149F732F6ULL
        },
        {
            0xD003E37BC037741CULL, 0x92279979315DB12FULL, 0x5DAA885AFE3DF56FULL, 0xB2E0FF6463A1FE80ULL, 
            0xB7CC57368AD12ADDULL, 0xD6CF60771105A6F6ULL, 0x9B3FDC2C7BE121D2ULL, 0xD4D99D76BF7B1D21ULL, 
            0x01476B7D44A7A19AULL, 0x6DE6784CD2257672ULL, 0x0D798418986401FCULL, 0x0FF52A354C04CFAAULL, 
            0xC1C51B34BA078270ULL, 0x1A111FEF5A5783C6ULL, 0xD39817DF5B4F8722ULL, 0xE3D6E1DB89B1E8A6ULL, 
            0x493C60E1ABDA3DF6ULL, 0x12E89DF7A3C33B0EULL, 0xC7D0E6162F671B66ULL, 0x6F2862E96BBC00E2ULL, 
            0x04C50280D941E8A2ULL, 0x83656E678B2B00B7ULL, 0x09A98BF174523CFBULL, 0x4B98C0BAE4FA2133ULL, 
            0xFC4382AD0539FE60ULL, 0xE460E313D291A323ULL, 0xBE8D7FFB374B6420ULL, 0x2E4544F393F8BC58ULL, 
            0x4B7CEF6EFF4A7A75ULL, 0x72FD8A8343AE9BE1ULL, 0x173AD78B18B345DFULL, 0x0AFA06F2B5A682C2ULL
        },
        {
            0xE29B685E1C14B4CBULL, 0xBBBCED2C9472E115ULL, 0xF89FA04F1905B645ULL, 0xF234ED6DAE9A98F1ULL, 
            0x5D743AE613AA59C9ULL, 0x981C50CC2333C1DAULL, 0xBC2762A008EE92BFULL, 0x838A3FDF214AB9D3ULL, 
            0xC7B39A6EB129EB01ULL, 0x4BB414BA4AC46152ULL, 0x75375EF320D70AAEULL, 0x477384AB6D11D37CULL, 
            0xCF059D445EC5CA84ULL, 0x860A2B13743EB3FCULL, 0x67952610AE5E9E8EULL, 0x50E60F217D621D97ULL, 
            0xAA12B9253C66AD88ULL, 0xF2015837844F3294ULL, 0xA274572C54A314DFULL, 0x51B875E292EAB198ULL, 
            0x1027A123B94DBE44ULL, 0x1616FBEB9FF72381ULL, 0x583CCD5D6FAC79DCULL, 0xAD210AC4892F81A1ULL, 
            0x3682BC46E9EFB951ULL, 0xC7E4E3C017717CB8ULL, 0x7A751E2E402E88ECULL, 0x41FBD07D848563A3ULL, 
            0xEC738D0D460D0919ULL, 0x7CF2B7FD144EAE6AULL, 0xD6D7CF54404EF930ULL, 0x999A56A1803D443EULL
        },
        {
            0x9D04548CAEA0ED3CULL, 0x95E3F96B33F8BA83ULL, 0x278A51765B754CAFULL, 0x6CDFBA4324C535CFULL, 
            0x5D26DBDD5D183D8BULL, 0x2C0C49FA838E510CULL, 0x89B44B2915388042ULL, 0x4949D20BEA2EBBADULL, 
            0x203D432855D08BA3ULL, 0x12832014C1160C13ULL, 0x8DC6AA3CC0176CB4ULL, 0x8D7ED438B443691FULL, 
            0x1D2545C4FB1F099EULL, 0xB5E1457804F78B88ULL, 0x6680BF4D5A452BB5ULL, 0x088E833382D655D1ULL, 
            0x86364ECC7D2178A6ULL, 0xE234C3D7549BA8C5ULL, 0x55B9D35B9E164176ULL, 0x39271D3E5335A410ULL, 
            0x9399F22C5E720DA7ULL, 0x8332553B81AEF6EDULL, 0x557330B763012543ULL, 0x1F2134F8EB51C0B2ULL, 
            0x325167EE2790AACBULL, 0xC4C74B75C028E31DULL, 0x70B75F290BECAAA6ULL, 0xC7D17EBAC87BAFB7ULL, 
            0x9E7A283198F9F211ULL, 0x4F5E9EB2A5E65407ULL, 0x39736708DEFBB7C1ULL, 0x603BBD9D789463A1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseEConstants = {
    0x941BFB11F7584E03ULL,
    0x7DC1ACB1B36695D7ULL,
    0x1C9B525CE2915E90ULL,
    0x941BFB11F7584E03ULL,
    0x7DC1ACB1B36695D7ULL,
    0x1C9B525CE2915E90ULL,
    0x96F3406F49966ECFULL,
    0x45AD0A2534B86633ULL,
    0xE9,
    0xA4,
    0xAC,
    0xEF,
    0xAB,
    0x56,
    0x30,
    0x22
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseFSalts = {
    {
        {
            0xA41027ECF440EDE0ULL, 0xDF17C7AFEF3106D5ULL, 0xFDFFB4B43E7401AAULL, 0x9CF488DC94651029ULL, 
            0x6DEB5755151616A3ULL, 0x58F15218241B8E97ULL, 0x45F1917935ECAA27ULL, 0xA76275BD542F0D8BULL, 
            0x6F8194080D1D9811ULL, 0x4E8548D4455F3711ULL, 0x131680DFC928D1E8ULL, 0xBE3D541A2F2DFDE3ULL, 
            0x25D96EAD44EE8201ULL, 0x545EA64737E99FC1ULL, 0x50E32D7ACFA206FEULL, 0x54D9D9578122E713ULL, 
            0xB16DED48B52B6920ULL, 0x105FDD81EBF467DFULL, 0x301685EFBA4755AFULL, 0xDC264CAE366C64BBULL, 
            0xD861E84F9E00CD10ULL, 0xA0CFE212BB89A869ULL, 0xBA79E415BD85D612ULL, 0x02480D23F7490659ULL, 
            0x4D0969BF10EF2078ULL, 0xC038194020E81C47ULL, 0x7FA666E1EAC11BC4ULL, 0x91CE8042ACAC27FAULL, 
            0xF4823007F32CF77FULL, 0xA1342BC6683E4408ULL, 0x044689050997719CULL, 0x0BF78AA2CA3CCDBEULL
        },
        {
            0xCBBF28374B2AFD61ULL, 0x6CA59767AE6B99FDULL, 0xDA5BA6C7D0D17402ULL, 0x1E1ADD4846E90A69ULL, 
            0x711249177FC6D8CAULL, 0x69E78107CC51249DULL, 0x8A2758B82B37A5D5ULL, 0x89565AF9BEC397D1ULL, 
            0x7878AE8F3C973CFFULL, 0x28964AE5CA907993ULL, 0xC52F52A62022221EULL, 0x3CB7B0263B823C01ULL, 
            0xC6FE66BCA9B367EEULL, 0x2FA82EB250798E99ULL, 0x192BA6C37C3A0F53ULL, 0x95C112E31BAB3E9EULL, 
            0x228FF595274C26C2ULL, 0x50C08F415BC3B818ULL, 0xE68416CA76717D4BULL, 0xF90A39AD8AEE8689ULL, 
            0x433ADEABDEC25F66ULL, 0xDF3AA3868FCB3BA4ULL, 0x4F1AEA3FB64B8946ULL, 0x65AB3214B74C1F55ULL, 
            0x81DB5A77A9E9E0B9ULL, 0x19ED0F7404B35A7DULL, 0xE27B30DDFAA13CA5ULL, 0x348EA8A8ECAF05C5ULL, 
            0x587199C5D7501F07ULL, 0x9E3689AA10E5DAE1ULL, 0x140B8E0C8DA221F4ULL, 0xA30E7692DFEACF0EULL
        },
        {
            0xEEA5A4F3CAE94AB9ULL, 0xD6AD2D923828D82AULL, 0x9D252E7377114C1AULL, 0x7FD15B52A68E6CA8ULL, 
            0x479BD9A8A25E829FULL, 0xD60046DCA416F76FULL, 0x47B015CA793C13CEULL, 0x7BB5130970301D85ULL, 
            0xCAA19865BE1D727AULL, 0x754C4AF398ED9FC7ULL, 0x64D4CB27222F4A55ULL, 0x20A62CAB493B6200ULL, 
            0xB56B4C81E55C9853ULL, 0xBDB444D3BA01ACACULL, 0xF1789948E297FDEFULL, 0x8605C0DC01024B37ULL, 
            0x7723DDCBA606E345ULL, 0x26E200E61BD6BBDBULL, 0x44286F2FC74D983AULL, 0x9EDEAB20FD7F9BC4ULL, 
            0x51C8AA3D3F074B52ULL, 0x953E75D886D487ACULL, 0x5B8D18B9A3415AF3ULL, 0xE206AFF0E056D84BULL, 
            0x8E246E3CA47F3121ULL, 0x8D2C7AF4BB3356D2ULL, 0xE9D2F3319AFDE9EBULL, 0x63B02F05FA6E06F2ULL, 
            0x7E449AC2BE1221A0ULL, 0xAC59B1F863EBD6E5ULL, 0xD0A60DE912265AA0ULL, 0x7E3DE34BCAEF4C56ULL
        },
        {
            0x69A889C327C4AD8EULL, 0xB44C2FBEDAEFBEFEULL, 0xEA19DEB7F6CBA587ULL, 0x6B5527997F222C9CULL, 
            0x7BC401A29A113AADULL, 0x5FB9D98DB30372F9ULL, 0x158CF55CAD53AD24ULL, 0x4DEA4EC465B1463EULL, 
            0xC75CA90376D6AFACULL, 0x7C770EDD8D503492ULL, 0x04B6B84C5643D051ULL, 0x2DE5B8515828F9FAULL, 
            0x768C37284734F31EULL, 0xE2314C3C4328BFE5ULL, 0xE52049D09D19F09DULL, 0xF0D72A2AE8FC2711ULL, 
            0xD5BA071CBB915243ULL, 0x8765700360A8BFCAULL, 0x1D285B6D1CFB686CULL, 0x681A8FCC48846A8FULL, 
            0xF7CF3B728469027AULL, 0x452E949B6236D76DULL, 0x28645E21A7ACB623ULL, 0x2571A48521F733E7ULL, 
            0xA2415C9D2C6ECB2EULL, 0xDB208368147F2E5DULL, 0x9D4E775203359864ULL, 0x52236AD4C192E217ULL, 
            0xDADAF061F4500063ULL, 0xFD5D943908DF3BB3ULL, 0xEAA7751EB8EC3DCEULL, 0x33D3CF12E79B2DF0ULL
        },
        {
            0x0BD0018CB615DAD4ULL, 0xB435683B8C0A7C49ULL, 0xE7CA8829CA35EA09ULL, 0x793FC76A343DF5E3ULL, 
            0x8E006563E78A1EE0ULL, 0x862D9D9A5C791F60ULL, 0x7C0475CA7E629170ULL, 0xC92755B1A3FCA046ULL, 
            0x500CE48620199B36ULL, 0x8FD79572C5AB2821ULL, 0x5F8374AA03CCADC5ULL, 0x69366177C2011CB8ULL, 
            0x3D42C2638F392BDAULL, 0x7FEDB26CDFE70634ULL, 0x2AA9A71E066BA97CULL, 0xDE33ECFF7F1ED9A0ULL, 
            0x7051290BDD7D1F69ULL, 0xF462F46A2ACBFDC5ULL, 0x45641172D5AF18D6ULL, 0x218FCD9C291A0B13ULL, 
            0x3D636D16A13080F9ULL, 0xEC8C3A19008E0AA0ULL, 0xEFF5CA1BB09D0B43ULL, 0xD8CDD2C9E30DEBFBULL, 
            0xF5233D8CD868E41CULL, 0x521E82E3320C03A1ULL, 0x8066C43719B02C9AULL, 0xC7E54275DF136BB0ULL, 
            0xA550B618E41C6AE7ULL, 0x22B218A74853145DULL, 0x241A93538A29D7DCULL, 0x07ABC8FD270CD0D9ULL
        },
        {
            0xD2B27D825BBCAA74ULL, 0x07A71F1F8C062BA4ULL, 0xFE7AC20DB795CC62ULL, 0xBF3876E2543C94C1ULL, 
            0x5798968EB0C5495BULL, 0x78F97E5447EA65EFULL, 0x44C43FFDEF3FFAB3ULL, 0x6D9BAB0387B287E2ULL, 
            0x6F78103AEBB0158DULL, 0xFC125B106F847754ULL, 0xFCD63D4C74E27CCBULL, 0xA2C0F9D0AF3C137FULL, 
            0xED2F4E21E8E8626AULL, 0x9F4A9DCCF8304CE4ULL, 0xB7717A5422DFFE5EULL, 0x5E2FD507B8488835ULL, 
            0x8AFFA993F925704EULL, 0x0A665F2914B69D66ULL, 0x4D65D5E42467508EULL, 0xDC8A0F6C95E1B311ULL, 
            0x2EBA957DED7DEF80ULL, 0x29BFA4869EE6CF33ULL, 0x3AFE8BA18AD8E787ULL, 0xC3E5264460D0521BULL, 
            0x4B05782BA0BD4D5EULL, 0xF216C600C39B755DULL, 0xD7AFD0D0ED80315FULL, 0x9ACF94A2C8955A32ULL, 
            0x9D2A63D696E8837EULL, 0x012FBE6D8532E7F6ULL, 0x0F4C715B3E3C26D4ULL, 0xFCCF6C8D0B39BC76ULL
        }
    },
    {
        {
            0x9AD112165F5F89A9ULL, 0x1A81F0202C2A3818ULL, 0x98009FC08DB06037ULL, 0xF1858FE4AED19FFEULL, 
            0x7251787C4BB7EFC8ULL, 0xCEC2F1EEDE990195ULL, 0x88D65C68584FACB7ULL, 0x6AB70602A85FCBA1ULL, 
            0x64434D7775A0303BULL, 0x06B9A4C3E11426B6ULL, 0x0319C546F00BB039ULL, 0x84B8D8B435C2C6D3ULL, 
            0xC501893BB41EE3D6ULL, 0xDDB0230277079962ULL, 0x1497AD7B96F87AD9ULL, 0x37B8782822117B2FULL, 
            0x547F7A6E6D78D972ULL, 0x42818515BEC9442FULL, 0x38FA4293A753FCF8ULL, 0xD1F23248B185D8FDULL, 
            0xA009246B9E60B0DDULL, 0x322CD8D85C843E30ULL, 0x1DD17B77F354E71CULL, 0xF475C8E3B5564EAEULL, 
            0x446EEAD7E820FD20ULL, 0x16010B5DFBDC873CULL, 0x8B09A0AA157B0181ULL, 0x4C50E517E4C2C781ULL, 
            0x6671A6D05A3E3E88ULL, 0xB3B14CF70E2A38C3ULL, 0x1D8C24530B55CFC9ULL, 0x664901D211CE0EDCULL
        },
        {
            0xB19E4E8ADBDFAE46ULL, 0x9EE743C21D3F0FE8ULL, 0x6F9B16E6FC25D54BULL, 0xB19C573D7FF81917ULL, 
            0xDEE948EEDEB21240ULL, 0x5BD2DE7B18765082ULL, 0x20FC925659FB3284ULL, 0xA72E51D4B1631839ULL, 
            0xC337D4AA5954D0D7ULL, 0x8CB6DA31DA4FE92AULL, 0xFBC16A20B9039C25ULL, 0x5704E18238BEB0B0ULL, 
            0xF67F1D96D217B5BAULL, 0xDF59AAAD7112D06CULL, 0x9B68251606603225ULL, 0x5DDBB38BA15393EAULL, 
            0x17B434464CF875B4ULL, 0xFD1E18325416415BULL, 0x76B27E3DA9A4E212ULL, 0x3932435640146088ULL, 
            0x5E5F3E3DA082E2A6ULL, 0xF2E820E415B3ECD4ULL, 0x06AF3537C57A591BULL, 0x8E7D449CBE54B2E6ULL, 
            0x71959DD7B937627FULL, 0xA4C6D599ACE721C8ULL, 0x0C78487259DDAD28ULL, 0xCA6C0370491F75E9ULL, 
            0xE6C602FB4E18AB98ULL, 0x8A290E929F083BF3ULL, 0xF6523A87FCEE8D24ULL, 0x9B5F8D396FB2ABE7ULL
        },
        {
            0x4104FAECB5704A5AULL, 0x1A65672B1A3EF5D1ULL, 0x778042759F1C565CULL, 0x6A13F64021B37168ULL, 
            0x78311017B40D84ACULL, 0x0E5036A87F860C98ULL, 0xA0668546FD629FAEULL, 0x13A4F81B858D8B11ULL, 
            0x9ECBD81F34B18D73ULL, 0x70A253FD79BF396AULL, 0x1013593C5DF53755ULL, 0x9D5FFDEFC444816CULL, 
            0x39C0BB3E85903F86ULL, 0x76ED4ECFF38460E5ULL, 0xEA257BFB72431D9DULL, 0x7B0A62620A0C5D43ULL, 
            0xA6FFEFEDB93594ABULL, 0x9F4F9BC8E747B227ULL, 0xBBC61010000869FDULL, 0xD05B1280ECB7D947ULL, 
            0xD2E17E218C51CAADULL, 0xE9AD0518AFAFAF3AULL, 0x890793B98CD7DF1CULL, 0xA5F4B8A3FB498D0FULL, 
            0xFE868002081F0160ULL, 0x819179503AFC4467ULL, 0xA4BEFDCF20FA6E6EULL, 0x19C9A0D0B5A26F76ULL, 
            0x255F93788B99E8C8ULL, 0x76AF6C2455FB9F13ULL, 0x4860311E22201A3CULL, 0x6956FBA9B1D5D468ULL
        },
        {
            0xBEAC474883B4DCBEULL, 0x31276C1FBAEBA1D6ULL, 0xBD7FAC66C500A890ULL, 0xA87927A393E085B7ULL, 
            0x5564640C256C0E50ULL, 0xCEF4519589C248BCULL, 0xBE42E88B393D8E17ULL, 0x8EE46E34035268C8ULL, 
            0x505BA8992071D12BULL, 0x1D42C60BF80A37AFULL, 0x483B9869E3868717ULL, 0x31F3E5B5F52F44CFULL, 
            0x2E0C183102680F0DULL, 0x48245B771B8CAA8DULL, 0x66B4F8C990DCC24AULL, 0xB65559F5460F33AAULL, 
            0x3E04234BC05BBF70ULL, 0xB1275F91FCFD73F0ULL, 0x0F378EB64E005CC9ULL, 0x846C9881DBAD0005ULL, 
            0xF3B2F1C9102A64BEULL, 0x564213FC2419502FULL, 0xB0ECDF521EF5FABBULL, 0xC5C914256C260D02ULL, 
            0xF937532D9CF3F4E8ULL, 0xC5362867F882D97BULL, 0x3DDA4A385EF16516ULL, 0x75044AEC1E680A9CULL, 
            0x6E32AC6F89FF346DULL, 0x5D656B43797DC0D0ULL, 0xE8B739B30ED23BABULL, 0xFF20522CC6310742ULL
        },
        {
            0xC9D66297AB8444A0ULL, 0xCC48090DE58D697CULL, 0xAF1E0EBBBDA292B7ULL, 0x018540A1D3EFE7A2ULL, 
            0x83E889BA48493E98ULL, 0xFF338D6C604D8008ULL, 0x1C29203429E2B60CULL, 0x76123CDC21CFE3C1ULL, 
            0x3C0C56DD9C25BD34ULL, 0x62C7E7FABB5930D5ULL, 0x3B2D7B656A3A75F0ULL, 0xA005C54BEA36DFC8ULL, 
            0x2AC54A7B5A3345B7ULL, 0x91ED989D05BF3C99ULL, 0xB197D2E96E26F080ULL, 0xF7C7699AC65EBC5DULL, 
            0xBE980D3B0D828559ULL, 0x6AC3D80256EFC0B7ULL, 0x6CDEBC8B72B2B032ULL, 0x9279203FD10A9781ULL, 
            0xB1CD0ADDA693701FULL, 0xECE5795BCBDD208BULL, 0x571A67FB48EA652CULL, 0x4C7F33F38085FF95ULL, 
            0xD70394706D827202ULL, 0x1D1C97E36249A88BULL, 0x36DAEA9FA371C2FDULL, 0x2DF584D07C22399BULL, 
            0x27066D7920105260ULL, 0x379F018526013C59ULL, 0xE3E1BAA76A7529EFULL, 0x38B5A967087EB5C7ULL
        },
        {
            0xEB98D5ABCF1F6DAEULL, 0x5D3CC7E8EE2BA20BULL, 0x8D7F98A76E4AEC98ULL, 0x59B4A2918341F259ULL, 
            0x8772CA50AEE9F85DULL, 0xA4EF5D3F2DCB808EULL, 0xD895FCCECF22E904ULL, 0x4EF44CD806D927E6ULL, 
            0x7EBCEB602F033A5BULL, 0xF07A793305DF8AC5ULL, 0x077C7578AF559851ULL, 0x50F38C0093DC9799ULL, 
            0x1F66F5712BB69866ULL, 0x0829A20FD365E2B3ULL, 0x736D527F1CEAD5A0ULL, 0x44344B4B7BCAA9AFULL, 
            0xD0095ACB633EDDC9ULL, 0x50E53B7DF5CE8EE8ULL, 0x8D1E56F0BD6232F0ULL, 0xA2F3AD271BFA16C6ULL, 
            0x769187A88E7F122AULL, 0xD2B82DF795B08085ULL, 0x5F7EBD04B70F74B2ULL, 0x832DDB52137C4A56ULL, 
            0x5064224999E759ECULL, 0xC4FD68B6B9521CE9ULL, 0x606E8E402690F8D0ULL, 0x28A45186723FB5F4ULL, 
            0xDA7466C3AD545FAFULL, 0x5723774A54C8C851ULL, 0x22E19D0A2A816D7AULL, 0x4D0BAF738BC60EE2ULL
        }
    },
    {
        {
            0x971811B67282E4FAULL, 0xF9B99AF7E1CE16FFULL, 0x36D538A7373813D6ULL, 0xF5A267EC0361DF4AULL, 
            0x80755E08DC2DD0A4ULL, 0xAE8682FDD3C323BEULL, 0xF500FC0945D35D06ULL, 0x69489E36F64EE397ULL, 
            0xC22F89EA83180DB3ULL, 0xA1F019679ABC1626ULL, 0xE8F3745FB78DB7AFULL, 0x40C3D25189706819ULL, 
            0x2AD572D7C8409E9DULL, 0xDFED07F48439DA08ULL, 0x1A60BC510C5DFEF6ULL, 0xED79C62261E65DCFULL, 
            0xFF4F3C5B09E74C44ULL, 0x80105808571837E4ULL, 0x4CC6ED0809D6F5F4ULL, 0xC632DB84771C049CULL, 
            0xBDF5A18E9402D4DCULL, 0x7F46A229C347078EULL, 0x3AE302A90BC16E8DULL, 0xF7D5E055374901DBULL, 
            0x7F2DC479222FF96FULL, 0x23C5E4030AFCF2D5ULL, 0xBF437AB63FE4112FULL, 0xC792B415A7A1CD61ULL, 
            0x6AD3F711835A2C4BULL, 0xD8320917B9B972C2ULL, 0xA1CA14DF2D4FC115ULL, 0xD3CF3443249C88C3ULL
        },
        {
            0x71D3680F315439EAULL, 0x4902BFAC74D4D411ULL, 0x88D67EF25FE56A99ULL, 0xBC4D10C443D276C7ULL, 
            0x66068C5B9B46975EULL, 0xB5DEEEF0F58D5274ULL, 0xEBED37E6E711FA7BULL, 0x627F789490D5D308ULL, 
            0x5F4E984475CD0AD3ULL, 0x39F04B89DB8D9364ULL, 0xF67E415F9F8DFDB2ULL, 0xE449DBD7C9BB3D27ULL, 
            0x3B932DB90FC30DC6ULL, 0xF0F34CCC1124599AULL, 0x369173519E4FB93DULL, 0xA7649444990627E2ULL, 
            0xE3AFCFF1B6C3BD8AULL, 0x8C90B84B2261F889ULL, 0xFEEAB55C12B07D0FULL, 0x038896D9BB86BFF9ULL, 
            0x4E406236E0105CA7ULL, 0xEA20F13FD5C9CC2FULL, 0xA0DC7D760D2BB58AULL, 0xFA6329274AB7D32AULL, 
            0x3E741B0AD129617FULL, 0xB6201E433FE5BD4FULL, 0x7990D20764D1EDBCULL, 0x9942C3898AC708D6ULL, 
            0x0030A91FD26BE626ULL, 0x54B85205FCDF17F2ULL, 0x58C348F0B1A97D47ULL, 0x71DE7D504E0388ABULL
        },
        {
            0x0B6A39B5A31EBE67ULL, 0xB15CDD156920AEB7ULL, 0x4200146D93A09DC3ULL, 0x1E91F44A82021582ULL, 
            0x300675E1BDCD22AFULL, 0x6D483846CFC70E83ULL, 0x267F7B5271AF0B20ULL, 0x8366A111AE81DCC2ULL, 
            0x652F2E70B2D4765DULL, 0x9B4A2702B14C55CCULL, 0xC517B93DD3300146ULL, 0xC00BDE0B388EAC07ULL, 
            0x141B8CF3517205E6ULL, 0x78282FBF2CDB2196ULL, 0x85A8A056BAA5CF02ULL, 0x10137A221F240265ULL, 
            0x7FD9CE45830D466BULL, 0xA36494D77664424DULL, 0xD4013403B73AEE45ULL, 0x7C0E8143E2B50FF0ULL, 
            0x54E7D7CE121E1933ULL, 0xA007B1396D32D968ULL, 0xECD31B364FE80DE2ULL, 0x7605D6FAE64DECCCULL, 
            0x4BD6BA2289841CE8ULL, 0x0FF320B65BB118AFULL, 0x92DE2C5FBCB45380ULL, 0xA30B1EA263881C2CULL, 
            0x49222E66DE9A5D93ULL, 0xB1CBE8BC1750EF42ULL, 0x7385F7AF2E81E174ULL, 0x6F472B4F0A843B15ULL
        },
        {
            0x2D49FE6EBB3332A9ULL, 0xACE425E0343BC960ULL, 0xCB57EEB5954C5A0BULL, 0xB73B4C78F497631BULL, 
            0xD5DB28D118B173FAULL, 0xEF31F6966261B0C2ULL, 0xBA353A1C8551A931ULL, 0xF9197DB1B2216163ULL, 
            0x5D9B2D06D173C1E1ULL, 0x485EA2AF7C5D32C5ULL, 0xF8B2877BBE7AD8ACULL, 0x970E27D6DF729260ULL, 
            0x7D0349FBFDF90DEEULL, 0x2E22C15AF2930327ULL, 0x243D16A1017B1CF6ULL, 0x5A1FDA65D194698FULL, 
            0x590CCF652FDBE6CDULL, 0x98F9A80EA2C41E08ULL, 0xA277D76486038A17ULL, 0x72BFC395C7213EF2ULL, 
            0x34DED7D59FFB9CB3ULL, 0x66A670FE3A105AAAULL, 0x193E41F1A535462FULL, 0x03E138A486C8D846ULL, 
            0x01833B5F963F0268ULL, 0xF29115C2FEF4C0D8ULL, 0x547C54CAF15D7F88ULL, 0xB5622DA992175A62ULL, 
            0x98D7E8FF0986AB57ULL, 0xF17F48CFCBBC6B7BULL, 0x2C9E9EE279DC694AULL, 0xDBDA414B245AD19DULL
        },
        {
            0xFD33A0ED7DF47364ULL, 0xE630DA0D21813512ULL, 0x040B7AD36AAD1A40ULL, 0x8690D3757E700AE9ULL, 
            0xC20897A01178CAD6ULL, 0x53E795B63CC1F266ULL, 0x9821BABDF9D3180AULL, 0xB26125885DBFCA71ULL, 
            0x82289747AFC283C7ULL, 0xFB80F093EFC973C0ULL, 0x2A597F048DDD1016ULL, 0x92B13A0D61515191ULL, 
            0x4C54CCA4271C6DBEULL, 0x41C1DD0101F5F3D8ULL, 0x66589BF7EB7BEAF5ULL, 0x9C88062F3600DF8EULL, 
            0x6D0A463727DD1722ULL, 0x2FE4A0EFDE26FF49ULL, 0x6BA9D15FC288FE80ULL, 0x998A8D3EABBBD213ULL, 
            0xEC61583FD8FF0246ULL, 0x3A56A875B1DC0FDAULL, 0x69DB6AEC82B876C7ULL, 0x51F720338C3E7202ULL, 
            0x8409F949F55DE501ULL, 0xB45D9CF5C61D1AB0ULL, 0x5759B82B5E41E986ULL, 0x82084C1270DFF53DULL, 
            0x3DBF2A5A5621CF28ULL, 0x63E54A6A69768529ULL, 0x4C33C2EC89C03B7BULL, 0x7B80FA60A062E6CBULL
        },
        {
            0xD4A9B9366F3B4404ULL, 0x73DAC3B3AF2168F3ULL, 0xC544A3A46717ACD5ULL, 0xBF29BEFE90DF7267ULL, 
            0xB0C994E23BC5CF04ULL, 0x8905CB47C253CA40ULL, 0xEA4FBD7D04B8993CULL, 0xB1F329F9E1D78D62ULL, 
            0xDA9CABD0F7F69F4EULL, 0x19A6B256212EDA19ULL, 0xBBF7249F6AEF30CBULL, 0x71A40FACB4C8239FULL, 
            0x15D242B65DD5F620ULL, 0x85643C9FABEF02E9ULL, 0x2A4ACE48B223DD87ULL, 0x709D9CA95B0F4D5DULL, 
            0xF048ADF4B115F882ULL, 0x4F53D236FC33BF43ULL, 0x0DCD5251A985A02FULL, 0xAE3405AC4BADB5C9ULL, 
            0x454B5D79E81AB01AULL, 0x3F127424DBC8EED0ULL, 0x74F67D914972D1AAULL, 0x4ABF0AE5F6F6774FULL, 
            0x1A9AE28F426A87E3ULL, 0x24DA8F9EDA772767ULL, 0xFF586E4A2DB339E8ULL, 0xED9420BC1EC0E03BULL, 
            0xB0F984E9BC629B8FULL, 0xE1791903DC30DD40ULL, 0xE85A111DFAE0FE28ULL, 0x1EAE802F4FF5C432ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseFConstants = {
    0xA44A95C0CB44BDCFULL,
    0xE3AEE489DC89D22EULL,
    0xA3956C4EAB9E0068ULL,
    0xA44A95C0CB44BDCFULL,
    0xE3AEE489DC89D22EULL,
    0xA3956C4EAB9E0068ULL,
    0x4C2F72AA81900771ULL,
    0xFAA80EAC76DAC914ULL,
    0x84,
    0x73,
    0xAB,
    0xAA,
    0x50,
    0x2A,
    0xBE,
    0x2E
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseGSalts = {
    {
        {
            0xF2AEE230BC763A49ULL, 0x84B7CFDDB6144EC0ULL, 0x7EB2D9A1C00766DCULL, 0xD1C0BD5A66DA8163ULL, 
            0x29E2CD3CC4A841FBULL, 0x1AD859BA4EF1B260ULL, 0x4DBCEA754FA2D1E2ULL, 0x97C5B80C0C112227ULL, 
            0x1912D6B2C8E65A4DULL, 0x7FC6351BB7CC26D5ULL, 0xCF3E2C1654BDB802ULL, 0x3C358CEB77145BB3ULL, 
            0xD7ED98685446B024ULL, 0xDA31CCED520580EFULL, 0x2F57870CCF037D9AULL, 0x73A1517C6FD80BB6ULL, 
            0x5C287AE826CB40EDULL, 0x128E9482347716F0ULL, 0x1ED9531C0A2ED774ULL, 0xFBBBEDF65A7314AEULL, 
            0x3088A30DAC38F58FULL, 0x1F18B1D80D661D63ULL, 0x03E1AEBD23B867A5ULL, 0x34E0BC5A68699551ULL, 
            0xB7F668112F42B2B5ULL, 0xDB0BA1AD9B5B037AULL, 0xA9DA9BAF1B61C8D7ULL, 0x5E3581CC22E10F1AULL, 
            0xA1441668337A4594ULL, 0x3B49364427154413ULL, 0x831070DD8C4EBF51ULL, 0xBE413FE1A40D020AULL
        },
        {
            0x0E9948FF672A7A94ULL, 0x249F06C9DB8FC77FULL, 0x69B982BA125C3933ULL, 0x46887908A6C722FEULL, 
            0xDEE229161005D463ULL, 0x2318CB4C8CC4209AULL, 0x24321E5F6049C9BFULL, 0x53FC9AD803ABA324ULL, 
            0x734DB10F5EFAD659ULL, 0xB6364D85804A576BULL, 0x2892659FC865C8D0ULL, 0xBF513769FAA30305ULL, 
            0xD38E44B8223C5DFCULL, 0x574D5964F890540FULL, 0x15CFD943EB324CDBULL, 0xF358D65D71EADB90ULL, 
            0x51882A516ED2DB7FULL, 0xA64E007D1199705EULL, 0xB7744FB4943245C5ULL, 0xE4872695BDC3C6F1ULL, 
            0x06E60BD0656F4AACULL, 0xF0673BFEE9BDDCB9ULL, 0xBD6DE2F55D92DD15ULL, 0x283CC8CB8531331DULL, 
            0x4F90032F343F77ACULL, 0x6CB2BFDA2F172B59ULL, 0xBBA8AFED1F276C6CULL, 0x2E5C6E9A6DEFC31EULL, 
            0x58EDDFA41DF59139ULL, 0xFFFCA04A1219BF46ULL, 0xF6228252BD8FCD65ULL, 0x9A397FDC301FD83AULL
        },
        {
            0x4403BF8CC655810AULL, 0x2DBB10E630C7CFF8ULL, 0x7FD3BAAA2B120C54ULL, 0x4B66BF727B3893A9ULL, 
            0xFB9231980F6FF75EULL, 0xA7B76ABA6D7F963DULL, 0x0BC7C58D7B33B26EULL, 0x7AA60A756FBF92C7ULL, 
            0xEA2D8327EF0E6D29ULL, 0xB3B7272DB64E945FULL, 0xC67A29387682B88DULL, 0xCE20D136F947AC79ULL, 
            0x6BB853367D4AB7FCULL, 0x1A09A56D14EBE6C9ULL, 0xD4384136927EE660ULL, 0x720A6334430C88E5ULL, 
            0xB62BF54128AF6F6AULL, 0x50E6BBE48F06AC24ULL, 0x4599777DA0E49A64ULL, 0x4AF8E695412F7FD2ULL, 
            0x479C00F8FB61BF7CULL, 0x069A733E7EB33E55ULL, 0xFF88259C95D96A10ULL, 0x5A2E70DBF6375E06ULL, 
            0x1B201A47AD49C8E4ULL, 0x2F05D10D18C66D4EULL, 0xD2AEC9392EFBAAD1ULL, 0x3F844C3475ABA731ULL, 
            0x3F0A706E45BF11D6ULL, 0x9A71A637F34763D0ULL, 0xED66BE92A59F4655ULL, 0x8474A0C137A9D432ULL
        },
        {
            0x5578FDD0FF1051FBULL, 0xC305A1D1D645260BULL, 0x8B4E75DED66D3407ULL, 0x2FEB2B45CDB3F8C8ULL, 
            0xA57D428DADF8DE6FULL, 0x9CCC2575D5D7EBECULL, 0xB2C15AE813F87585ULL, 0x15F570F99FC3C73CULL, 
            0x8377DA95C8F53C2EULL, 0x0386687B78C9DF47ULL, 0x80CCD7C66B0FD7B0ULL, 0x32EBE186EDAC18F2ULL, 
            0x61AF19AC62621D7CULL, 0x3D0461041D025B4BULL, 0xA52BA5A3B700262FULL, 0xBEC5ED491221DBD3ULL, 
            0xB14EA8B6D678724AULL, 0x6C96887B76F1287BULL, 0x2A32B52BA3F6E4DBULL, 0xDEB4ADB91EC4CE52ULL, 
            0x813C1EF7F857A3B3ULL, 0x9E57AC9C6A6551C2ULL, 0xCD39DFD784549522ULL, 0xE1ACFC325B1DADE7ULL, 
            0x4EF8970A70E552D8ULL, 0x71D2770928AF8807ULL, 0x18B39BFB168A8B84ULL, 0xD5285A663D5F4E39ULL, 
            0x648DA1AF572FD902ULL, 0x060F59237BAD3371ULL, 0xBA1A5B7056602FF7ULL, 0x420E125A24D7CC3DULL
        },
        {
            0x4B2F40251C46F962ULL, 0x1DDEDFB7DE556044ULL, 0x12320E3CA666F68DULL, 0xC325A8BC9053DB88ULL, 
            0x7C4D767D286F41C2ULL, 0x2816153CA2B8F59EULL, 0x7780482CE00BC29DULL, 0xBBADF37C7355E391ULL, 
            0xDD40F3A3A8A53C30ULL, 0x627B3BAF3314B0F7ULL, 0xF65ECBAEE1D58447ULL, 0x268BA0A7B8751EA7ULL, 
            0xDE0089B082BA1810ULL, 0xB73AA91F8BEC851AULL, 0x733B9EF5F03784B8ULL, 0x4267A1D8C9E539FEULL, 
            0xBCCF636F9C92809BULL, 0x084115B86A768DE1ULL, 0x5BF59FFF8BD704B6ULL, 0x0EBEB60E7F8FD3EFULL, 
            0x2A2E9718086D9EC1ULL, 0x700DCFE669BBF659ULL, 0xA9ECDEA2413902D8ULL, 0x50B3220B313E880AULL, 
            0xB2791C6987A1EC5BULL, 0xB8BF14DCD3F3E808ULL, 0x0FC02C044600D687ULL, 0xC1AE72E53735971EULL, 
            0x021DE41664EAA056ULL, 0x4AB85201F2F769C0ULL, 0x98B38D817DF607D6ULL, 0x4AEF702455C7CFA3ULL
        },
        {
            0x253398A5E8CCB0DCULL, 0x8BE4E4A48B838CE6ULL, 0xFD75EC85BF8AA537ULL, 0x6D2DC3B02EF0ED6DULL, 
            0xB3497B1A01AF6988ULL, 0x1A430B68E64F7C87ULL, 0xC902539C413DE50DULL, 0xA0518DABF8355363ULL, 
            0x0F8A1091DD0449A9ULL, 0xF709F7F8A31650A1ULL, 0xB6BF737A41C026F4ULL, 0x43F540BD131FFAC3ULL, 
            0x3E34CFDD5703911FULL, 0x2401F02FD7CBCB3BULL, 0xE4A2985BDEA6A881ULL, 0x6A75912D1054480AULL, 
            0x4BA890DCC6903AD2ULL, 0x4CB8AE6C03260609ULL, 0x9B5B3DBB6D611CB2ULL, 0x27C5F1B5589C9CA1ULL, 
            0x46E7545CD58F9BD9ULL, 0xCDCEEC2B0DD7C9B4ULL, 0x942C41C61F7CB97FULL, 0x0BE6BA27DFBAECA3ULL, 
            0xA560E0D4F0357F52ULL, 0x6C98E57B1E3A5ABEULL, 0x8EF91EDD0934246EULL, 0x3075CDA889103701ULL, 
            0xDC0770B42D70DC20ULL, 0xA510143A791989EAULL, 0xEE375B15B3A75CA8ULL, 0xFFF06EF37CFED89CULL
        }
    },
    {
        {
            0x7A219F7B22FB6A2FULL, 0x7097864570B1D6B9ULL, 0x36960EF5833B0A71ULL, 0x7E096F086615D31CULL, 
            0x1F1F6EC1E17A8F72ULL, 0xB406A1532EBDD870ULL, 0xD07A564A4728516FULL, 0x3B1C19453D90C27AULL, 
            0x3AAEDDC4B32EBC21ULL, 0x44F52F9100F94D6FULL, 0x73FDAC2A3D3EA242ULL, 0x8CC503140E2EEAFBULL, 
            0x2548CA7358E06FD7ULL, 0x72229DE17335950EULL, 0x6042203EF624A57FULL, 0x1B72AAF2DC975F37ULL, 
            0xDD86F91AFF2ED5ADULL, 0xCC4A636B223E79F9ULL, 0x79212D7C1D56D68DULL, 0xA14804DE7BB16FDAULL, 
            0x6CCBD060F454BAA4ULL, 0x0D6BC55B3C27EB78ULL, 0xEAE185CF878E717BULL, 0x2D174F52BC1398D2ULL, 
            0x92B7E7AFCF1A5DBCULL, 0x07F688E809F8275DULL, 0x967673DD501745B3ULL, 0xB853E0D5E8B200B4ULL, 
            0x504CF097C0BDE7D0ULL, 0xB0291A1CF214F951ULL, 0x5197B99C5DB0C1B4ULL, 0xA368DCF20223F957ULL
        },
        {
            0xEE09453BB06A47FDULL, 0x8B0E75D48B704279ULL, 0xD784E8D214C4D6CCULL, 0xE414429B8DAAA363ULL, 
            0xD32EA6F9EFBBCBDCULL, 0x280F780555AD7C31ULL, 0x0F566E7D540AB65BULL, 0xEF6BDEB5F16E87B7ULL, 
            0xAEEC570A8C710C8EULL, 0x4E8544544C9EAABBULL, 0x73392F7A71B77083ULL, 0x9755C1A2AECE870CULL, 
            0x01ED3B2D9FA1B7F5ULL, 0x72697D6AEEBE988AULL, 0x348887AE7C54F4D8ULL, 0x3F5F032E7CAC5CE9ULL, 
            0x7D0DD77C2E3B49C7ULL, 0xFEA88CC8C9431377ULL, 0xED0E9A9BB14264FEULL, 0x4CFB53954CE06170ULL, 
            0xA0C4A9F6520EE072ULL, 0x16F81B19F7B11680ULL, 0xEDCC9D6DCDDA44ACULL, 0xEA882D9C4E2A4910ULL, 
            0x2221514F3E79BC1FULL, 0x3DD4F3CBE857E48AULL, 0x805D08826F42E86FULL, 0xE73851D18FB587F7ULL, 
            0x110C117875394256ULL, 0xE51F96EDF3716A56ULL, 0xD15B1C246E073474ULL, 0xB86D11CEF348A4BDULL
        },
        {
            0x999BBB2C97EB6968ULL, 0x72F36EE754F44A98ULL, 0x529F460F34C7C2B8ULL, 0x4772C2A2F61617C7ULL, 
            0x2FA05E82DB3F78D3ULL, 0x10DD640E8ACE98F4ULL, 0xEAA03D7B24DF037DULL, 0xB0AF691A92B6D3FDULL, 
            0x9A03A2E67D5ED8BCULL, 0x53F73A48F420469BULL, 0xF3EC907E2021CA0AULL, 0x24400852CD20936FULL, 
            0x82559A4D605DE462ULL, 0xCEDE5C5C495F2B84ULL, 0xCA1BAAF0945BCFD4ULL, 0xDCB891E1B7AFC34CULL, 
            0x6E67286318DB8F49ULL, 0xE5322CAC0F84F22CULL, 0x0A92E8F63B7ABB89ULL, 0xAF231E87269200EFULL, 
            0x71134B35F788D9B9ULL, 0x69DB8B12D94222E7ULL, 0x09177654A7DB94A9ULL, 0xC98384676377B058ULL, 
            0xDA95E5A81E386743ULL, 0xC1F25D5AB8E6A64AULL, 0xC9EC824114F0F6E1ULL, 0xE1CB5BBCA2D1E627ULL, 
            0xD95A767939357A84ULL, 0xCF39D786630AA295ULL, 0x09072254FFFEB7A9ULL, 0xABF15D513B15298FULL
        },
        {
            0x5CCB2CC448EC95F9ULL, 0x4C1D6D3722BBDB8CULL, 0xBA5BD442768D9A2FULL, 0xC626B8E6F58C003DULL, 
            0xA3E463DEB6D3FC39ULL, 0xCC1D74698BD64976ULL, 0x521DDB16EEC5D070ULL, 0x376322984CDDD28DULL, 
            0x1B14418891C8107FULL, 0x74E4881233D5A085ULL, 0x0914D29231B8F534ULL, 0xA9C648B0B2FB7ACCULL, 
            0x08902B928113EB66ULL, 0x2D11B795D30F933BULL, 0xA06E5A02F913F70FULL, 0xA80DA63691F02B55ULL, 
            0x3C37ADB390D587EAULL, 0x436FEFC586FF5A6DULL, 0x71AC1706B169CF1CULL, 0xF8C92226E397DFA2ULL, 
            0xADEA3E6142A3C541ULL, 0xA4D46087F0BC14F1ULL, 0xE09A391344E1B4B4ULL, 0x306852C23BB79C8FULL, 
            0xEFE5A84133E9D170ULL, 0x29D1CBD704E43BA8ULL, 0xCB1B9D865019F292ULL, 0xB60F0E2B7BEA2F05ULL, 
            0x148603B70BEF5F7FULL, 0xDA5616F589BB8AB8ULL, 0x37C2C4E67AD46138ULL, 0x67D4AF7CC25CD12FULL
        },
        {
            0x4CE68CB12E67A093ULL, 0x239CE69E7050FB21ULL, 0x5FE7FEB4606CE51FULL, 0xA2918F82046F690BULL, 
            0xCE4ECAC13C0A5258ULL, 0x1E2FFC5C81EB4E3FULL, 0x58719B1F7B87746DULL, 0xF71163AA5B591641ULL, 
            0xE1CF366DD64BBB82ULL, 0x799DDD0E9322F606ULL, 0x5C1C0DE58A0CD303ULL, 0xEF8A8A64A40116FFULL, 
            0x1CA423B614852A0DULL, 0x4B0C4D6BF59268C5ULL, 0x60BF17FF249708C3ULL, 0xCFFC8FA7D71BA219ULL, 
            0xA233B9A22E4F0F1AULL, 0xE5122FB6CF6DBF60ULL, 0x1D121D487632B94BULL, 0xC71CF334F8353650ULL, 
            0x48ED7CC7CD9F2553ULL, 0x4A34056A1A953C8EULL, 0xBEBEA36D277E733DULL, 0x1DA4523BC1A9736EULL, 
            0x0EBDA6CC6D8BF29EULL, 0x850B901FD76BB0D2ULL, 0x738EA8241E211C98ULL, 0x4FEAF086871B2FC1ULL, 
            0x64F531368F325B97ULL, 0x02A15CED8C1C6CBCULL, 0x918B87C12C06CB97ULL, 0x7D7ED1C3A7317E9AULL
        },
        {
            0x37957A68838EBA3DULL, 0x30AB1FB7378C5446ULL, 0x0D5BC4F644DE5585ULL, 0xFF2ADE43418F337DULL, 
            0xEACFCD6A58EB0C23ULL, 0x83CDCB189CC2D406ULL, 0x86C0AC6E1D3613BAULL, 0x9EFBFF1D1BA28E73ULL, 
            0xEEB6981AC033E6E6ULL, 0xA79959D79ED3D21BULL, 0xAEE86183498272CFULL, 0x017E940274838989ULL, 
            0x7DE47540EE9C5FADULL, 0x5AF6232F1C4FAD59ULL, 0x97352D51E7970C8AULL, 0xB82BC50372818997ULL, 
            0x262240D4DC7946AAULL, 0x97FC54F9AD525F4FULL, 0xA9AEFA279541ACB6ULL, 0x6AAAE0574D40022EULL, 
            0xC4C2679060CAD7DFULL, 0x7BAC2A439FE9FE6EULL, 0xB91F1C5C35072166ULL, 0x217CD06A8A4237EAULL, 
            0x474970AE4D518980ULL, 0x5353DCAAC9715F8EULL, 0x802B4654297FF174ULL, 0x49C3046822091AABULL, 
            0xC135F46730B8B79AULL, 0xABE8F327A3FC842DULL, 0x4E7D280B2AADEFE3ULL, 0xCC79B035AFCAB051ULL
        }
    },
    {
        {
            0x241064FB37B58A22ULL, 0x3E369179E833DFEEULL, 0xF8E79C832A20B964ULL, 0xC9E21F5C65867FE9ULL, 
            0x3B6618CCAFFD3C28ULL, 0xED749F88DDCBB175ULL, 0xA8D9F8FC77AB7256ULL, 0xC27CF5CA31EE8223ULL, 
            0xCA7B954E2091F4FCULL, 0xBE93719EAE97696FULL, 0xD073C58DD90C77D2ULL, 0x80F8B4282A74E56AULL, 
            0x09611B3AE291816CULL, 0x212BF55D4980C79BULL, 0xE0516AE768A5C589ULL, 0xD963CA0BB3652C75ULL, 
            0x0BBB5C65F1A84041ULL, 0x4C2F452468F1F451ULL, 0x18E2A47DD0E8527BULL, 0xE456FA776EABED98ULL, 
            0x718A21233EDD5356ULL, 0xBD5F3F45E6DE1FF6ULL, 0xC3E5086699F8C50EULL, 0x3D41CF30AECFAED0ULL, 
            0x9A4A9F077C8AAF17ULL, 0x39DCF72935708940ULL, 0xF8783E509B36FBABULL, 0x3ABF9B2BDB0FE582ULL, 
            0x13D17BE3E8C74E26ULL, 0x8E24199EA3C39524ULL, 0x65307421598A2895ULL, 0x22637D0CF7235763ULL
        },
        {
            0x8610465DACF1897AULL, 0x55490DF3F2757E11ULL, 0x4F359641ACCF272BULL, 0xBF6C66D0D1BD7770ULL, 
            0x50F789B2D90DF20AULL, 0x0D58A003C1060214ULL, 0x91B92FC9FD352790ULL, 0x1FF4089C8F4322D8ULL, 
            0x4CBBC124C1942956ULL, 0x318774F76CD0F4A4ULL, 0xF3144475DBEFBE82ULL, 0x6221B3A453ABA69FULL, 
            0xDB5FF90F52F06BDCULL, 0x34204DCFC9C0D27EULL, 0x5248ED5FE6FEB700ULL, 0x16F9573444454C25ULL, 
            0x798DBAEF5C21C970ULL, 0x36C28A105C17A23AULL, 0x3AE2A5E877E0ECDAULL, 0x947C4E3148765810ULL, 
            0x094212F217CCEAE6ULL, 0xAD02B79577352836ULL, 0x2BB5D232E9B0E5D1ULL, 0x8184B06A95C40297ULL, 
            0x16546A3A86085FEEULL, 0x088B5B1012C42145ULL, 0x6442FD0C9621039EULL, 0x3ED170317B1F63CEULL, 
            0x6AFE464692642E14ULL, 0x7933F571606AC911ULL, 0x7173C4F77D912863ULL, 0xCBA735023E530ABFULL
        },
        {
            0x9D1CCE22D1A4EFD1ULL, 0x6E6FF81E09BDF33FULL, 0xE107480B330A95EBULL, 0xA13EAE58F242C596ULL, 
            0x5C7EB2DEB42AA144ULL, 0xA4138FF0802CF6B6ULL, 0x0259EA3D430A3A53ULL, 0x1BE4983BEEE5D792ULL, 
            0x6C4D38B5C7FA0CADULL, 0x04DFDCD3C8172642ULL, 0x1C07DF10232F6D2FULL, 0xEADC92450D623878ULL, 
            0xC683A39AF41160ABULL, 0x179D054D6085A3B3ULL, 0x172D0F61B2A70C5DULL, 0x45655FA05516491EULL, 
            0x69864E3BD040775EULL, 0xBE12EBD93C57387CULL, 0x0AFF789EEDE5DD71ULL, 0x2EB01FE2FAAC2392ULL, 
            0x2E9602787D082E73ULL, 0x5C99EFF6E5FCBCE7ULL, 0xE71E06B05E2EF9C7ULL, 0x4DC1709768EE95FAULL, 
            0xC9E117573A6BC12AULL, 0x2F8FD060A5C2B462ULL, 0x9C944F83555EA0CEULL, 0xD7008A5C497ABC9EULL, 
            0x1D977FF63C184605ULL, 0x09642847BE211CDDULL, 0x91C96DBB21019959ULL, 0x0BF1F37EBE0881E4ULL
        },
        {
            0x64E1836DBF34C745ULL, 0x867CAD4295F10653ULL, 0x53F808DFC093B723ULL, 0x8D77B318C273F118ULL, 
            0x94371865D8DD5B8DULL, 0xB389868486B6CF08ULL, 0x536E57BE5C75A3D5ULL, 0x4BA30D5464334A53ULL, 
            0xC23E9392272E80C0ULL, 0xD44B05695F4AFB31ULL, 0x98ED07A0B219589CULL, 0xF2BC461F745EE402ULL, 
            0x67DF122804BFAF45ULL, 0x841C1FC5A85A2363ULL, 0xA613CFD1221CBB36ULL, 0x301442E368166A91ULL, 
            0x484F1C4849780BD9ULL, 0x7660DA3A48F5E1D6ULL, 0x9120825F1EADEEF2ULL, 0xB1E9A4F88526ACB0ULL, 
            0xB23C886FEDCE27BDULL, 0xD5F5F9441E7F3938ULL, 0xC97E2E53535B69A2ULL, 0x65E671DC71390114ULL, 
            0x10B0F648B99654EFULL, 0x278515921CA9AE92ULL, 0x7AB4F85F95CE30F4ULL, 0xD89D77F2CF1ABF92ULL, 
            0xB96C28B5BC50B18EULL, 0x1C4E44800E28C5F0ULL, 0xF9D6425D486E9107ULL, 0xA92750B2AC5088BEULL
        },
        {
            0x12AFF93D12737CD3ULL, 0xBB3A4E07E9917E43ULL, 0xC94D064F1EC11C0AULL, 0xA8AB5E66CAC4050DULL, 
            0xFA679312A177EB72ULL, 0x0F279D1FCEE0E27AULL, 0x05740748B8C0BD11ULL, 0xB0D3FEF24BFC4851ULL, 
            0x62BDF3372E7D5572ULL, 0x0B0A804611C6D269ULL, 0x8DF1A94E730979C1ULL, 0x588FA5C9B8EE405EULL, 
            0xC0878629BCAE5BE2ULL, 0xF50071EB644C6540ULL, 0x90975B3EED06C29EULL, 0x3457CA6A8B62C625ULL, 
            0x04203FA3F49B9B9AULL, 0x4FC974995E328FFAULL, 0xEBB6B4E861746CD1ULL, 0x6568F9B29F9D7047ULL, 
            0x1655B4967D1D998DULL, 0x84EB03DE9AF853EFULL, 0xD22320B67D6D3A9EULL, 0xAB726705E9651975ULL, 
            0x019ED78F676BEE27ULL, 0xA010BE9232BB316AULL, 0xCDAEB06E1D1A330EULL, 0x14DA848E92091B59ULL, 
            0x0941D1E9AE8A6549ULL, 0x801FBB46E472B4B6ULL, 0x845B1D9DFB969210ULL, 0x609DFA0750424821ULL
        },
        {
            0x16B0F187B141D4E3ULL, 0x43874C8D8F7877ECULL, 0x794EA765B8994F9DULL, 0xB84EDF88A8C27489ULL, 
            0xAF9D80F8212A3BFBULL, 0xA76BEF01FDD61D32ULL, 0x834014251ED680ECULL, 0x0203F33A2A0F37F4ULL, 
            0xCF1F142B4B48B76EULL, 0x67160656F2F8E162ULL, 0xDDCCC87EFE9AFAF8ULL, 0xD9992E70A593CF50ULL, 
            0x37396AB57F495987ULL, 0x863DC931C0B751E3ULL, 0x592F6AFC9A9503D2ULL, 0xACA915074ABE0036ULL, 
            0x377A690400B5997AULL, 0xB9D0C15644D22E45ULL, 0x6FEC9005FBED0FEFULL, 0x8C01739F57C287BEULL, 
            0x87F0E5751F3DF3B5ULL, 0xB28B135AC93AC2D7ULL, 0x09E3381B8D72C62CULL, 0x5955585AB4885EC7ULL, 
            0xFC37262A20121730ULL, 0x81BBAD09F2A6B9C1ULL, 0x2D023A48ADE001EDULL, 0x23752B72E53AF28BULL, 
            0xE2B21A1C8A4035E0ULL, 0x637243FAEC6E3947ULL, 0xB3A76246F50C8747ULL, 0xA6B50740C369FCE0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseGConstants = {
    0xC5B8C6E8DCDCDF8DULL,
    0x78076A7DA36DA782ULL,
    0xCEA8AF870FE1EBF1ULL,
    0xC5B8C6E8DCDCDF8DULL,
    0x78076A7DA36DA782ULL,
    0xCEA8AF870FE1EBF1ULL,
    0xB48BB2B2060E474EULL,
    0x627611C065C1D038ULL,
    0x90,
    0xCD,
    0xBF,
    0x92,
    0x7D,
    0x88,
    0xCC,
    0xE5
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseHSalts = {
    {
        {
            0xB601A8FC8AE37F0EULL, 0xD23396C9E24F52BCULL, 0xD27F943A6CA62E36ULL, 0xABB3381A8B7B2C43ULL, 
            0xBED6433522D616C6ULL, 0xBED5EB531E90671EULL, 0x6D17C651779F6653ULL, 0x494B6B51BC9F4F74ULL, 
            0x79FE7B2070331B84ULL, 0x7F0E0A5D86D36939ULL, 0x6A01387757DC3BC5ULL, 0x7D4F73DA1478C5F0ULL, 
            0x22D1139B85870818ULL, 0xD0472D91EDEE41C2ULL, 0x8AD0FF9573B916F5ULL, 0x389E9E6A43DD5ACFULL, 
            0x5BB9DDC3AE118786ULL, 0xFA7E95F6603067C2ULL, 0xCE138C3565B3139EULL, 0x3880DF05619B602BULL, 
            0xAF5C069833EEF22EULL, 0x6E9593D42138ABF2ULL, 0x5B581D918FF4B8AEULL, 0xF47A33F3CC5230A1ULL, 
            0xCE0F39A7DADB706AULL, 0x0D7D02BAD6F03938ULL, 0xB2FF2FF56C1D7B86ULL, 0xF1ACFCBCDF5752CDULL, 
            0x0E69B08780A408D2ULL, 0xCE61ED83AE478C40ULL, 0x4479269053700629ULL, 0x1D1EB4406305AC49ULL
        },
        {
            0x653553A7B965F07AULL, 0x948D0E97042222E5ULL, 0xBC850B24E4CC7C64ULL, 0xD67871BE082C51C3ULL, 
            0xBB9403C7F0A35B75ULL, 0x3CA80E6B175817F9ULL, 0x6134455D93883588ULL, 0x47F215D041927DD0ULL, 
            0xD3D36C1690D3F811ULL, 0x199398B5A9451A02ULL, 0x730051E853F35E72ULL, 0x81FDFEEAAB584F5AULL, 
            0xAC51E4C09E3E773FULL, 0xEF6E57AF1593DE49ULL, 0xF0754B89BF3FB7CDULL, 0xB43987FA7855A747ULL, 
            0x6C3FB26C64CD8883ULL, 0xC364FCC59C6EBD72ULL, 0x181AC201EB199766ULL, 0x96FA8E2B26938E26ULL, 
            0xA48456339127AC17ULL, 0x3FD0B9D4A2D3AD53ULL, 0x47D6D7F0B5BD4BE3ULL, 0x29E9C646358CEC04ULL, 
            0x0065DCC535E92AC6ULL, 0xD4D568BEDE2D481AULL, 0xE70189534DE45ECEULL, 0x58D3E2D3258BBA00ULL, 
            0x9C4115966940AAD5ULL, 0x12B289A39595501FULL, 0x95B60185733BA369ULL, 0xE6588FE7A21C3D1BULL
        },
        {
            0xA47505F6A8EFF2EFULL, 0xF978EE813F73CC90ULL, 0xC84002953A35642AULL, 0x6BE841537A62D4EAULL, 
            0xBB299C01A474530EULL, 0xD98B62EBB156A8A8ULL, 0x748F8D70778D99EEULL, 0xA95731AEA13CB826ULL, 
            0x72D2F5C845C8299AULL, 0xF4024B6CEC7AFD4DULL, 0x9E359C7300EDDF7DULL, 0xBE225E7FBEB80537ULL, 
            0x28C7032D52F6B22FULL, 0xF887D4081ED781B2ULL, 0xB3D09FBFBE8130F9ULL, 0x715294FB4276A4E5ULL, 
            0x95C70B736ACBF654ULL, 0x42124266238DE054ULL, 0x07A324A7F9CDA666ULL, 0x5AABEF80A6891D52ULL, 
            0x050280FDF4B8FC44ULL, 0xF137073E4EE3F56EULL, 0x134A6DBE8A71C99FULL, 0x24290FCAE6846657ULL, 
            0x3663B58AFF78E750ULL, 0xDAD09106A66300BEULL, 0x50E2CE33DEDE2C5DULL, 0x41939DC2A5E93C05ULL, 
            0x4B25BDFC9AE9A616ULL, 0x0FA66FF7CC22C045ULL, 0x95C3B7EB4F2380A4ULL, 0x1D257502993327A8ULL
        },
        {
            0x3417265419F16052ULL, 0xC727050D45E3B3E3ULL, 0x1014F3F362E221EBULL, 0x261237EB9C0894B4ULL, 
            0x3C43E442F085EF32ULL, 0xC2DA3BF562482C37ULL, 0x7169D41C50CCDC8DULL, 0x9645067A1D5E253EULL, 
            0xC2135D4C6AAF5434ULL, 0x2560BE2108EAF69BULL, 0x1221F9C0F2CF907CULL, 0x748C5D15E3160DF0ULL, 
            0x96F2D62FAB47E82FULL, 0x48195A1EE96E23A3ULL, 0xEBE62684097628E1ULL, 0xEC826473B6B20D45ULL, 
            0x70F0A316B0B33837ULL, 0xD39FA3F652A01E1AULL, 0xED55E6D77432703FULL, 0xD45A70D0632771DDULL, 
            0xD856E46B1330849AULL, 0xB03419B56FBBAABEULL, 0xA4CE9EF918F6895FULL, 0x5E74E366C115C33DULL, 
            0xDE68FE4237B2044CULL, 0xD9DCE91654B674D8ULL, 0xAB4843449B22890CULL, 0xDAAA21199C1A0FDDULL, 
            0x61AF1F9F05F077E0ULL, 0xDC128A01B5D70021ULL, 0x1F4BCFFB3FB4438CULL, 0xF9E62115BC54F898ULL
        },
        {
            0xF63E96E406EF8C95ULL, 0x694CB92DB2AF128FULL, 0x6A67B4F5AC7E215AULL, 0x64042E416DDE9995ULL, 
            0x700E2F4136407DE6ULL, 0xC623E559AEAB2D39ULL, 0xF953D4F96AD5A816ULL, 0x8923009C8CAA438CULL, 
            0x69F3B4D84F628D30ULL, 0x68FE0238E6494346ULL, 0xB0C1AC3289C3B0F2ULL, 0x3604DADDD922C197ULL, 
            0xEDF132D93D95452AULL, 0x02C9B89AC15C3019ULL, 0x730B5791A07CCADBULL, 0x26717E23307335B2ULL, 
            0x36180C7679061707ULL, 0x249359B14A31F1B2ULL, 0xDD38D05BF934E0B9ULL, 0x8E96DAC74711BB86ULL, 
            0x37312CB7FB6D1D99ULL, 0xECC0AC260FB0EC0BULL, 0x0306C05DC2BCF19EULL, 0xF2C95BE3A62E99B8ULL, 
            0xA189369EBD974387ULL, 0x480C2067DA4D7D3AULL, 0xD7F2A393AFAE48FEULL, 0x6AA0DF41DA74A932ULL, 
            0x9EDF89A609357D36ULL, 0x27513E81003200E0ULL, 0x0E2AB8E436C42103ULL, 0xD1C5833BE830EAA0ULL
        },
        {
            0x4CFFCD91CF814683ULL, 0xE17E6147256B9C0FULL, 0xB3E6E9E2EA935986ULL, 0x700FAE368991A35EULL, 
            0xC2B4B901ED95E3E4ULL, 0xBAF137493896A57EULL, 0xF1E5378EBA10BDACULL, 0x9CFD3767B33C8B60ULL, 
            0xEE3778FB21538C5EULL, 0x7B0F3F24EE1B99E0ULL, 0x39D3869459B315ACULL, 0xF6FE1A3F250CBCCBULL, 
            0x11380CF44F4C3DFDULL, 0x79617AF3856BFC49ULL, 0xC65CB1F17CB62E51ULL, 0x02935E94CBADD60AULL, 
            0x6B3CFD43AAB5C45FULL, 0xF94E7BC3E197707AULL, 0xBBBE8FEF85BDEE79ULL, 0x8D6CC921A3458FC2ULL, 
            0xF9BD9267B3906879ULL, 0xEE541E2FF0FD0464ULL, 0xCC3234FE4EC9D972ULL, 0x589D3EC19F854289ULL, 
            0xD48F57BF327154B1ULL, 0x7CB81336CC10D9E8ULL, 0xB6E919606F8AF34BULL, 0x5EE74B4199F0065DULL, 
            0xEEF8ADE48EF09210ULL, 0x15DA33826F9F1778ULL, 0x60AA261E28E75366ULL, 0x055905810125D207ULL
        }
    },
    {
        {
            0x49EEFDA882FF3661ULL, 0xF305AA9153481290ULL, 0x1D22087FD78CFAA1ULL, 0x429AEFC42FC612D6ULL, 
            0xC57E898910B463B0ULL, 0xC2F18856278FBC40ULL, 0xCADB8F9938427B9CULL, 0xFD2F0AA0A820D93AULL, 
            0x599A5E1FE6EF5886ULL, 0xED4D3F2519EAAA3CULL, 0x23C1F1C27ADCE9AEULL, 0x3CB815861E77B518ULL, 
            0x3BACCE1BCA50E05FULL, 0xB1ADBCC8D41334ABULL, 0x9369ECB22710F8E7ULL, 0xB6C0401A6C577058ULL, 
            0xB43ACAE377F1E1EEULL, 0x3F00F0A5809D18B6ULL, 0xF6C85A4FF44D362DULL, 0x36B87BFC0AB1AEA4ULL, 
            0x7EBC78BEC3C88975ULL, 0xA3CD948FD841CB64ULL, 0xCB7AA08BF14B8732ULL, 0x825D0C2640B6F949ULL, 
            0xC5710EEDF9DC7CF6ULL, 0x0BD9094420B278BBULL, 0x458157BA4BAB400AULL, 0x430686F80E31E625ULL, 
            0xFDDA5A2B9159B75EULL, 0x90D2F14178762435ULL, 0x5F9200E196C559C2ULL, 0xAE95827DA9635197ULL
        },
        {
            0x416798BBDF172905ULL, 0xB5FF898E58E1E8DAULL, 0x76BA48723895E66DULL, 0x485879217D2FD48BULL, 
            0x880875FC6B8C31A2ULL, 0x11818DD702D39DBAULL, 0x12F5597DCE69F558ULL, 0x911929476B36DCD4ULL, 
            0xAE9B4E6BA8A0498AULL, 0x508E98F53B281267ULL, 0xEFE251A29969FABCULL, 0x1D63B5178D2F3327ULL, 
            0x5700E5716C5C1324ULL, 0xF7B6117970338EC4ULL, 0xF4757849736E9CF9ULL, 0xDD5A8222488173FAULL, 
            0x39D2ED973D715255ULL, 0x19CA2DDE13A6A917ULL, 0x3F239A9CEBAF2737ULL, 0xA73744DF4A997C9CULL, 
            0xDAA74FB2BEDEB371ULL, 0x68AA60AD639D6DF1ULL, 0xA0F97C5753E96AC6ULL, 0x0B97B7AA120FAE7DULL, 
            0x502519BF7609950EULL, 0xDCCE0345125DEBE6ULL, 0x5D5CD7BC59E167F7ULL, 0x1646B680331FC660ULL, 
            0xCE193A29EE87B7F2ULL, 0x8796E3C014A9FBB8ULL, 0x746126981A7FA335ULL, 0x33918AFCD769FBCEULL
        },
        {
            0xDC44B421ACC67E54ULL, 0x978FA009CB254BA1ULL, 0xDCD1582BCDB8BD4DULL, 0xDBE81E64A54A0193ULL, 
            0x88596D1F6AC232A9ULL, 0x58DAB46D22A89B80ULL, 0x6617C5A27FE2BA02ULL, 0xF1DCF57B22BDD215ULL, 
            0x707F44E990A18124ULL, 0x785536D2C371E2D2ULL, 0xE46D70EAE27D0855ULL, 0x4C3B9D6ADDC51B98ULL, 
            0xA92BE70F0A47C247ULL, 0x5D97123044680C70ULL, 0x0AB5D0E6337E321AULL, 0x72F92537F63A78A4ULL, 
            0xFBCE9C09DDDC2E47ULL, 0xA380CD3EA128937DULL, 0xFF87B038C929998AULL, 0xA9039AE7602B828EULL, 
            0x3935A4F401AEC6DEULL, 0x68C290F588F6BA9AULL, 0x1B0F0291D7748E36ULL, 0xDE57AA668B4FC53CULL, 
            0x335ECBE2FD991E40ULL, 0xB83568DACF88B041ULL, 0x1E4E61FC9447A45AULL, 0xFD3918E210EA0C52ULL, 
            0x58FAB014308C4E31ULL, 0xC65546D9500BEDC8ULL, 0x455C81E81C7C895CULL, 0x2EA067EB83EC8C45ULL
        },
        {
            0x72BEA6827302024AULL, 0x87B178B6402E3AC0ULL, 0x49EC6E9F5E49D64DULL, 0xF860DFDB26326AC6ULL, 
            0x85DC2B029DAD9EEDULL, 0x0CCA4C98BBBDB75AULL, 0x1CD3BBFB4728AB17ULL, 0x612E1708ACF236D3ULL, 
            0x76602959DCC76066ULL, 0xC6A00F027DD181C3ULL, 0xA38EF6D46E33B3EAULL, 0x7E6B64B54B94F6C1ULL, 
            0x273588C1748BDE3BULL, 0x57B90A0A6438992DULL, 0xD30BA4C8602A30A3ULL, 0xF14A03671E54494BULL, 
            0x6411C67FBD44A66FULL, 0x6F92E1F834F75FC4ULL, 0x4DAF8CAD6C79E403ULL, 0x744930EAB3BEA185ULL, 
            0x527542AF6688DB5DULL, 0x4991231E0E116557ULL, 0x4D2D303514E64604ULL, 0xBD0050F3C8DD4995ULL, 
            0x30BAD811B40176B5ULL, 0x5F51098B849E93DDULL, 0xBEAAA3EC07F949C5ULL, 0x7E81F9785421693FULL, 
            0x92F8C25A151851A4ULL, 0xA61AC8A56C3018DBULL, 0x362716D2A29D1AC0ULL, 0x3D132E094269EF61ULL
        },
        {
            0x24F93E1FDE19CCFEULL, 0x2B0E562E9AA9E3BDULL, 0xECB2C3BC6257D576ULL, 0x7D884A8A2E2B6225ULL, 
            0x230687738D6F890BULL, 0x9620CAEBB9298C59ULL, 0x45F6AB8ACADBADC8ULL, 0x3D893BC48475F245ULL, 
            0x3F68A3892EDEE5E5ULL, 0x55C47BFF876AF475ULL, 0x47CFF2A122EFAACBULL, 0x31B16FA0E43F2540ULL, 
            0x75020C9CA351386CULL, 0x7B9A42D6D1B5FFF1ULL, 0x2E688998B393F54BULL, 0xC85661E9AA340FCBULL, 
            0x09EED2B52F8CAD2CULL, 0x5BA3BB39601F419FULL, 0xFF0A2D305F289D92ULL, 0x67823982828D5B14ULL, 
            0x35F813AAB0FA9DC6ULL, 0xF0253BD6E98C9D3AULL, 0x3920A899F9E8A388ULL, 0xEFF59CDA86A74DE0ULL, 
            0x7BFCCF585248CE2AULL, 0x366AC10CE883A00BULL, 0x96DDD3C37CC4EF4BULL, 0xDC6F8A56BF9D8853ULL, 
            0x3BC7B0FC4C02C526ULL, 0x8A08CF7B464FE308ULL, 0x602B1C767F527459ULL, 0x55F6F27B95619575ULL
        },
        {
            0x43884DF98245E243ULL, 0x648F166DB2A20A6FULL, 0xA8C3E527C274BDD9ULL, 0xA831F33355E4519FULL, 
            0xCB5F3D1AF3008AF7ULL, 0xA2BA1D2A35F92CDBULL, 0xA2290704FF7BE3EBULL, 0x2000E169D10FC7FAULL, 
            0xADB018434F896378ULL, 0xD408E80E62C1F241ULL, 0xFCCF164397CA3B09ULL, 0x09A93101A020BE86ULL, 
            0xFD8F878D17786E57ULL, 0xC0F26FA0AD735B85ULL, 0x1BC2F547B6F76911ULL, 0x308A98518C2743F0ULL, 
            0x742DB15762580E06ULL, 0xC788B8702B4D920DULL, 0x455027454411E4B8ULL, 0x0ABED0CFD7EC5784ULL, 
            0xF8DFE8A810F9C717ULL, 0xBA3EA66536855FC4ULL, 0x3A32B93D92349811ULL, 0xFC526F7CD1578C16ULL, 
            0x78B501F65DD22CFAULL, 0x119C0FA716EB5672ULL, 0xB98E85569CA44839ULL, 0x99DF79E2B7A46623ULL, 
            0x9E6E166FBFB417ACULL, 0xBE4FAABAC5CF110DULL, 0x9F0B1CD5226AC845ULL, 0xF5E2DCF1E4CEB317ULL
        }
    },
    {
        {
            0x1CD666412AEB91B1ULL, 0xBBD512D66C8916DAULL, 0x59BAB08EBB1069CDULL, 0x3240A47132E319AEULL, 
            0x4A00C4BD7EFF150DULL, 0xE27B017A2F55BAC0ULL, 0x7360A715F0996DBEULL, 0xE49CBDE97D766FF8ULL, 
            0x64F39F1EDC02B753ULL, 0x60D98D7A913FA2E2ULL, 0x494BA5A5478CDA39ULL, 0xB453A0A62AA9D7FFULL, 
            0x263677CDAAD11D45ULL, 0xD3F3A6F500A99CB8ULL, 0x0F02A016262B019BULL, 0xEDBD6A85DB1FE90EULL, 
            0x97D952C5B8C1C5CDULL, 0x2E64961ED7F91D88ULL, 0x93516D64EE77ACBBULL, 0x90C9AEE75DE470DCULL, 
            0x9C75EF39FD94B550ULL, 0xF28CE54D1136B9AAULL, 0xFF05259D045FB40DULL, 0xAB1651C94384C05FULL, 
            0x74DCAA11C98841DEULL, 0xD98009B788772383ULL, 0xC6237A0828E1BF49ULL, 0x7E6F33B2A1DDE8EAULL, 
            0x22B73F33F54A8E24ULL, 0x7A944E4858D3B89EULL, 0x2BD80C92F1D0DC23ULL, 0x2144F1EF2DA0D30EULL
        },
        {
            0x72E308F8216C09FCULL, 0x074C89C19886D310ULL, 0xBD8E5ECACBFB5BB7ULL, 0x5C224F630192AE51ULL, 
            0x6E0F47327085FDC6ULL, 0xA8253DF2F205DEB5ULL, 0x85006CBA8F4C6A19ULL, 0xCCF0AD63490BD200ULL, 
            0x4170D0DD60449F4DULL, 0xC748165679D4CAC3ULL, 0x176BB4353750A2FCULL, 0x22FC740C5C055E6AULL, 
            0x14BCD8E08224C7A4ULL, 0xFDCCB222C5307C7FULL, 0xD04CE68705CBDD6AULL, 0x5755E1492CA60561ULL, 
            0xC2168B466773B73AULL, 0x913D68A03A7A66AEULL, 0x79FA230002A45550ULL, 0x569C81509ED14B4EULL, 
            0x14A69C2EBBAC935EULL, 0x138EF66F25202785ULL, 0xE3932AABA7DD1C7FULL, 0x5DAE7EA67F4D422BULL, 
            0x3A874A69711F7654ULL, 0xC2798125E04BF9ABULL, 0x0E06B6A91A732FC5ULL, 0x83A15111F43FC475ULL, 
            0x5D2DD81E9601897EULL, 0x5DA0F05D65920C0EULL, 0xE1FB1C0214093E72ULL, 0x335B48ACED70F3AAULL
        },
        {
            0x12F7BD657297DBAFULL, 0x12EF34F86E8A4189ULL, 0x4E2B53CAF6DF6F49ULL, 0x137AB6E80152C6F0ULL, 
            0x68000EE0D5973C06ULL, 0x4ED9BFC3BB1C1034ULL, 0x5B49D2BF966E77B5ULL, 0xDC7070BE5A907721ULL, 
            0x76FB8A995358FD46ULL, 0x3658BA0A4E150F52ULL, 0x5AEDD1D2A7A08012ULL, 0x01FED7F4306F4BF9ULL, 
            0xFAD968A3A2D92543ULL, 0xCAC6D883600AF300ULL, 0x3C400295105AF889ULL, 0x0DB45D5020E36B32ULL, 
            0x641D1E9FD1D3B122ULL, 0xAE1DB90F411A3B68ULL, 0x4AC25B9795D747D0ULL, 0xF572AECE835F9B06ULL, 
            0x10433F4A02755A3CULL, 0x56401FBD7416B68FULL, 0x1900D88B593F88EAULL, 0x70D48656CDAEC18BULL, 
            0x94668B0F2F74139CULL, 0x6A69BF67088BF301ULL, 0x507A52ABCF03D79EULL, 0x375265C7B007265DULL, 
            0xDA463BA396CECDBFULL, 0x9FE7CDF6FB82EF57ULL, 0xEC65B2542EAE3BAAULL, 0xA0B43273577CE829ULL
        },
        {
            0x17CD99E696FFFCCEULL, 0xF8322559F0F6D9FCULL, 0x83B62F9B2251AF3EULL, 0x403FCAB364ABA29AULL, 
            0x6E001673BC720EA6ULL, 0x486C1E0B14B0C57AULL, 0xF310BCF06500AD93ULL, 0x5478CE7038C016AEULL, 
            0x328451B61E9B2EA7ULL, 0x97ABBCD9AC0BA486ULL, 0x723AE99A4FED7E17ULL, 0x68965411CC89866BULL, 
            0xF3FA711D8A4205AFULL, 0x8E18C78C2406A7E9ULL, 0x074326F6582C7DD1ULL, 0x919E7CEA60E27211ULL, 
            0xE5E5C0393827CA83ULL, 0xDC7C4955FA8C8C19ULL, 0xA361D560867D2B9CULL, 0x1A03AABCD591CE6AULL, 
            0x6167B8C74166E246ULL, 0x7C2F194F12D70D82ULL, 0x4C4895C7B16F8ECFULL, 0x8BD0ECAA118C5CCBULL, 
            0x1F6FCFC1A5910B1AULL, 0xD45B9575A5E0A4FBULL, 0x1B4AC2DD31D9B79CULL, 0x32B2C1F5D61F0200ULL, 
            0x567B5B9143759F7EULL, 0x4BB007E21E704F6BULL, 0x857B42B7399ED210ULL, 0xE370348D07B020ACULL
        },
        {
            0x3A2A5DE1DB5C990CULL, 0x38C50FC24B355F58ULL, 0xD983C409F75A4AC6ULL, 0xC701CD31EED4FD17ULL, 
            0x2133D365F47FD5A0ULL, 0x537F4B45D5569F34ULL, 0x0CBAB1446C791ED9ULL, 0x3D11DA93C5D0E919ULL, 
            0x374E0C9EA3471AEDULL, 0xB201CE541D762938ULL, 0xCCE1F1AB0579B2CFULL, 0xBFEA029584EE184BULL, 
            0xBF7D1DFC4093E5DEULL, 0x5DCE5B5B7A3D2CA9ULL, 0xA9CCD9548C72C6FEULL, 0x74D9781A301B6723ULL, 
            0xB02BE45547E686DBULL, 0x648833CDC8C46339ULL, 0xD60B6D37E99E12A7ULL, 0x5CFC2D2BCCE01C9AULL, 
            0x82BB6F05C1B9C603ULL, 0xB3CC2F6BB1FCC905ULL, 0x12E195C8364594CBULL, 0x3AE3B1AA70A9E5A1ULL, 
            0x0D232580CAD3D722ULL, 0x6766DFC92901CDD0ULL, 0x88DB00B2D711934DULL, 0xBEC9F6BEECEE987CULL, 
            0xE518A0721A6451FAULL, 0xE1476E8275667D5BULL, 0x4DBDA132396953ACULL, 0xE85B09EAAC482823ULL
        },
        {
            0x52F0930D8EED8424ULL, 0x6FCC4D950646B81DULL, 0xA2C1C5600441C634ULL, 0x45727F560D69BA7CULL, 
            0x2E6A6BB505866D0AULL, 0xCBB96BDC1AEE2F2FULL, 0xF07C14C34F48014AULL, 0x665830A374543A25ULL, 
            0xA639F9E2FAC5194BULL, 0x87D97860BE6CBD9FULL, 0x40C03BB8EB697204ULL, 0x6DD073A37D292096ULL, 
            0xBA62128C84A85135ULL, 0xBF14C3634DCB748EULL, 0xD842459929EC86BCULL, 0xEAF718F9FAFE97F8ULL, 
            0x27C5EAC1555F2760ULL, 0x02F8700A845B144EULL, 0xAA9A872469505AA2ULL, 0x84A29F285B24CBDDULL, 
            0xC92D977A16B0FF34ULL, 0x1C145F2739EFEB42ULL, 0xF63200DDAC09FD11ULL, 0x715709798E88B344ULL, 
            0x6C2BE01BA30019C1ULL, 0x939307CB85149992ULL, 0x88E3E7BA0C5C6DEDULL, 0x7258D31504A4EA15ULL, 
            0x2B993310113F7FD6ULL, 0xAEFE1C49521A9B31ULL, 0x2616F45CE725755DULL, 0x683D6881A0104F2BULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseHConstants = {
    0xD0EFB2E29B96C940ULL,
    0x83D9599F5F29ABF8ULL,
    0x6BA2304AC6B37CA0ULL,
    0xD0EFB2E29B96C940ULL,
    0x83D9599F5F29ABF8ULL,
    0x6BA2304AC6B37CA0ULL,
    0x5E5CDEDBF2942DBDULL,
    0x40152210724A5EDCULL,
    0x54,
    0xAA,
    0xFB,
    0xA6,
    0x3E,
    0x41,
    0xD1,
    0x48
};

