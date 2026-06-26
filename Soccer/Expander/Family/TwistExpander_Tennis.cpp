#include "TwistExpander_Tennis.hpp"
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

TwistExpander_Tennis::TwistExpander_Tennis()
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

void TwistExpander_Tennis::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 12417038082292968978U;
        aCarry = 14218285686831230793U;
        aWandererA = 10748550905443606513U;
        aWandererB = 14627270991879424885U;
        aWandererC = 16731749061955727216U;
        aWandererD = 11610958222513977078U;
        aWandererE = 14892308454430837539U;
        aWandererF = 17496902635393401896U;
        aWandererG = 16465408698703797407U;
        aWandererH = 14007544415540134527U;
        aWandererI = 15732202888444046890U;
        aWandererJ = 13414904855868907735U;
        aWandererK = 17648112928698737794U;
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
    TwistExpander_Tennis_Arx aArx;
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
    TwistExpander_Tennis_Arx aKDF_A_BArx;
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
    TwistExpander_Tennis_Arx aKDF_A_CArx;
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
    TwistExpander_Tennis_Arx aKDF_A_DArx;
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

void TwistExpander_Tennis::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 13903287684648030763U;
        aCarry = 12112165421764611425U;
        aWandererA = 14682698624207773517U;
        aWandererB = 12921035202820593233U;
        aWandererC = 9913701246106615638U;
        aWandererD = 10349785218291402982U;
        aWandererE = 11723951805974899192U;
        aWandererF = 16863013501306869469U;
        aWandererG = 12209019207116411443U;
        aWandererH = 13459826360563898420U;
        aWandererI = 12448322893692188547U;
        aWandererJ = 14024675797363698350U;
        aWandererK = 10797215034459026521U;
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
    TwistExpander_Tennis_Arx aKDF_B_AArx;
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
    TwistExpander_Tennis_Arx aKDF_B_BArx;
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
    TwistExpander_Tennis_Arx aKDF_B_CArx;
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

void TwistExpander_Tennis::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x97DD34FB4671D366ULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xE43F3BD7A6E4E7E4ULL;

    std::uint64_t aWandererA = 0x97AE9FAC6898E066ULL;
    std::uint64_t aWandererB = 0xA378D2AEA9C76E72ULL;
    std::uint64_t aWandererC = 0x8D253566F71E37F4ULL;
    std::uint64_t aWandererD = 0xC7551BB417686A29ULL;
    std::uint64_t aWandererE = 0xE743C0791B5C7322ULL;
    std::uint64_t aWandererF = 0xC9599DB2B511BB45ULL;
    std::uint64_t aWandererG = 0xD636A21AFA730B25ULL;
    std::uint64_t aWandererH = 0x985053C986B89C06ULL;
    std::uint64_t aWandererI = 0xB067DC6981B473C1ULL;
    std::uint64_t aWandererJ = 0x8A13B24B6FBE5323ULL;
    std::uint64_t aWandererK = 0xCB2A5040DA0AE80CULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneB);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA);
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneE);
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistExpander_Tennis_Arx aSeed_AArx;
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
    TwistExpander_Tennis_Arx aSeed_BArx;
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
    TwistExpander_Tennis_Arx aSeed_CArx;
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
    TwistExpander_Tennis_Arx aSeed_DArx;
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
    TwistExpander_Tennis_Arx aSeed_EArx;
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
    TwistExpander_Tennis_Arx aSeed_FArx;
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
    TwistExpander_Tennis_Arx aSeed_GArx;
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
    TwistExpander_Tennis_Arx aGrow_AArx;
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
    TwistExpander_Tennis_Arx aGrow_BArx;
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

void TwistExpander_Tennis::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Tennis::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 14816409828727576743U;
        aCarry = 9408251174985960077U;
        aWandererA = 17771432368313469785U;
        aWandererB = 12377634694670350996U;
        aWandererC = 13450298437867431279U;
        aWandererD = 13364768538504496832U;
        aWandererE = 16222644348611120376U;
        aWandererF = 17285243577864715921U;
        aWandererG = 15985047749645642739U;
        aWandererH = 13161443297888315258U;
        aWandererI = 13361207866954280272U;
        aWandererJ = 16396189164804580107U;
        aWandererK = 10978807640578655284U;
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
    TwistExpander_Tennis_Arx aTwist_AArx;
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
    TwistExpander_Tennis_Arx aTwist_BArx;
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
    TwistExpander_Tennis_Arx aTwist_CArx;
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
    TwistExpander_Tennis_Arx aTwist_DArx;
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
        TwistExpander_Tennis_Arx aGrow_AArx;
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
        TwistExpander_Tennis_Arx aGrow_BArx;
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

void TwistExpander_Tennis::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 3, 3, 0, 1 with offsets 5222U, 5010U, 4893U, 7284U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5222U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5010U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4893U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7284U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 3, 2 with offsets 6695U, 3848U, 1861U, 686U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6695U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3848U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1861U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 686U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 1, 0 with offsets 1123U, 5026U, 4984U, 3657U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1123U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5026U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4984U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3657U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 2, 3 with offsets 1024U, 602U, 7740U, 4836U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1024U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 602U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7740U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4836U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 3, 0 with offsets 1965U, 1496U, 495U, 1749U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1965U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1496U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 495U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1749U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 1, 0, 3 with offsets 780U, 1081U, 451U, 1881U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1081U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 451U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1881U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 1, 3, 2 with offsets 342U, 1579U, 1805U, 1087U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 342U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1805U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1087U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 2, 1, 3 with offsets 488U, 1485U, 1478U, 1829U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 488U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1485U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1478U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1829U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1200U, 486U, 1069U, 1522U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1200U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 486U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1069U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1522U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Tennis::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 0 with offsets 4463U, 4796U, 3778U, 341U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4463U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4796U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3778U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 341U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 2, 2 with offsets 8015U, 1500U, 3203U, 6118U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8015U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1500U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3203U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6118U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 3 with offsets 444U, 442U, 1719U, 2849U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 444U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 442U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1719U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2849U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 1, 1 with offsets 3654U, 7331U, 72U, 6499U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3654U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7331U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 72U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6499U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7401U, 6968U, 2101U, 7704U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7401U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6968U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2101U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 7704U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1777U, 1212U, 1323U, 1868U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1777U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1212U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1323U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1868U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1476U, 14U, 929U, 774U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1476U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 14U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 929U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 774U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 938U, 159U, 1347U, 1390U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 938U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 159U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1347U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1390U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1507U, 719U, 1299U, 2008U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1507U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 719U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1299U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 2008U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 2, 1 [0..<W_KEY]
        // offsets: 1571U, 36U, 387U, 1206U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1571U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 36U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 387U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1206U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseASalts = {
    {
        {
            0x01C25B7DECF733CFULL, 0x7DB2893D853E6FB4ULL, 0xBC42A5403E9924EDULL, 0x92F63B4A66E28391ULL, 
            0x7DFCE5D688E6C4E8ULL, 0x7AF34C1C7478CAD8ULL, 0x2C50037D6561FC00ULL, 0x380201D7D6DAEECDULL, 
            0xA3C832CDCA1F3B35ULL, 0xF4147ED3D063BD10ULL, 0xB2BFF72B5FB40B5AULL, 0xB3734430536B43AFULL, 
            0xA055662CF0A6EBC2ULL, 0xA311CBB220EC7826ULL, 0xBE84DE153716B9B9ULL, 0xB86A77485AAA4D6CULL, 
            0x29E0C9BF504ADB95ULL, 0xC4C33C2C247B5AE9ULL, 0x6B09BA3DC25DA509ULL, 0xDB89638BAA0079D1ULL, 
            0xDB0F799909571940ULL, 0xA2E34D7BBC974FADULL, 0x3747A595823C2832ULL, 0x1D05339EAEF7A341ULL, 
            0xB5F97167AB100301ULL, 0xA91EE02ADD48F222ULL, 0xD0786904FFABE75BULL, 0x75E339178FBC144CULL, 
            0x0EB86EDFB3D42AC2ULL, 0x32B139262616054FULL, 0x0689CFAD40DC8B85ULL, 0x69C2C21B9C668DDCULL
        },
        {
            0xD65457ECE2D27085ULL, 0xF6AF9CBA8239FE21ULL, 0x9F338CA1D8AD0DEAULL, 0xA705800F5E5C2859ULL, 
            0xED1B4248B837224FULL, 0x79032867FA5C3BDAULL, 0xB174D2EB97286C29ULL, 0x53A7547C46C337DCULL, 
            0x0536E4A383297039ULL, 0xEB05E80AE1BF87EBULL, 0xCEA36C50A80489BCULL, 0x66CA53A27C77A631ULL, 
            0xB9DFDCCDDCEE0EEDULL, 0xA4166C99A7602A23ULL, 0xF763204D1595D007ULL, 0x600A91760AE93038ULL, 
            0xFC6DBD23D6C31CBAULL, 0x148CA981190BE844ULL, 0x5CA176305AFED107ULL, 0x3C4E8CE9A0A44F0AULL, 
            0xBAFB2CC53FD16E31ULL, 0x1C249AE96E188240ULL, 0x7B7910780B8D1FF3ULL, 0x4E4EAE0958243BE0ULL, 
            0x89B9D1800118E4CDULL, 0x1C1AB526C786FE89ULL, 0x79FF75D23A5586A5ULL, 0x1C7F97E74863CAE5ULL, 
            0x73D70CC8E3D38A8CULL, 0xD7F00537517B3347ULL, 0x6E1B899A96DED094ULL, 0xDD98297F0235DAE5ULL
        },
        {
            0xDD88CFD4A83E4592ULL, 0xC562C3A3FB73C184ULL, 0x5A458CE3AB0F6CD1ULL, 0xC64DE5F0A52A6FC1ULL, 
            0xB326B40B89DA33E5ULL, 0x1043C944CD5D0DBFULL, 0xB15D76DAFAD77592ULL, 0x7D6382485EB910ACULL, 
            0xF7FED7720A91CD1CULL, 0x0B0FABE708B97BE0ULL, 0xD0727644A4982C80ULL, 0xD1E72F111AEA8015ULL, 
            0x0CC90A4F202A4B02ULL, 0xFE7BE45A2EF536C1ULL, 0xEE71988BB1447501ULL, 0x617E6DC443009873ULL, 
            0x3A47C626E4EAD112ULL, 0xB677A4712BBE54B1ULL, 0x91C15FAB4C4716B0ULL, 0xA7F9CDC728EFFC07ULL, 
            0xA54782A0AFB36A47ULL, 0xC86598844E613F46ULL, 0xA023FE551EF4E2B9ULL, 0x7CB012D8D36B22F0ULL, 
            0x23922AA5A0AB68DCULL, 0x39C7A6F64B0D0AE9ULL, 0x814F486398553422ULL, 0x86D82059B6F21654ULL, 
            0x7BE0A419AA15F517ULL, 0xDDDDF2BB9C20EF1AULL, 0xE39F1D8EB8E56356ULL, 0xE025E21F8AC3548CULL
        },
        {
            0xDB1DC194420027BFULL, 0x8B39158FCBE557FCULL, 0x6B375875C02482AEULL, 0x371AA7CE13C6F829ULL, 
            0x8A9671C9C82FE817ULL, 0x41BB05E440A1A51CULL, 0x2C0109A06E58D94FULL, 0x59E5F19AF9FADB8DULL, 
            0x9A0029C9968D0357ULL, 0x019239668B79027FULL, 0x0D4D1735695D0A44ULL, 0xB42CC245881DCDE8ULL, 
            0xBA4317F3ECB55B5FULL, 0x824E69B2129F2BCEULL, 0xCCAAA0A70993C0BEULL, 0x09A1D34B6DD9159CULL, 
            0xBB6C66CC4ABCD16AULL, 0x289DEFB5B9384D48ULL, 0x8DAC978A1EC5FA32ULL, 0xAA7DC7ACB1D17F0EULL, 
            0xF68E6988B63C12F5ULL, 0x50FFCDF75EC58290ULL, 0xFC70221B8860E298ULL, 0x6C3BF52B3A711F58ULL, 
            0x5D6D566DEC7BFBB2ULL, 0x9B2F08B46527935AULL, 0x617801BB4A4B4681ULL, 0x50F4DE04C7CFEBBFULL, 
            0x0FF0AC721F220CB0ULL, 0x57E9231B84462A6CULL, 0x4BC09301278DA84FULL, 0xF8E8659928C2B872ULL
        },
        {
            0xC21B905FDB6ED080ULL, 0x26F6128AA017D8A2ULL, 0x6E9590CCD06A0FDDULL, 0xCC4C079195443874ULL, 
            0x278E255EDCF04F72ULL, 0x8962893121733BFEULL, 0x9133C73401E0C53EULL, 0x43133A6A67DC7FC8ULL, 
            0x1341CAD7070B2699ULL, 0xE7ECE63B23B06C2FULL, 0xA77223B1E2D95C4EULL, 0xBC1532BBD2A7ED18ULL, 
            0xB11A019BFE314F0FULL, 0x172B2EF372E6C780ULL, 0xE5DBCD17B9DAADEBULL, 0xCBD2E64FCF4093AFULL, 
            0x9575729B793E7A32ULL, 0x2DAD3F93545FEC28ULL, 0xE2A21BC4E716A9ACULL, 0x746C447603A0D0A0ULL, 
            0x2AB5D6AB5B0A16C8ULL, 0xE745B20BC00AE415ULL, 0x2AB17DDBC15C7392ULL, 0x47D9FB2D6F6A0376ULL, 
            0xA3BCEDFC8164BECAULL, 0x6D5CC5C4F227A154ULL, 0xCD13EAFE3FF9EEE0ULL, 0x2C5EB5D7C29EF5B6ULL, 
            0x227A569F96D1D227ULL, 0xD2CD3D6AC75B7E2AULL, 0xA0814AFC5EFCDED0ULL, 0x544C4EB21CD55224ULL
        },
        {
            0xABF8E1CBD7CEE90EULL, 0x2F58131A190F7D17ULL, 0xDC7FDF8CCACBF62DULL, 0x3FFB79551958A7D9ULL, 
            0x1F36157C01EF0CAEULL, 0x4F27F6500329977BULL, 0xA982C0599D4684EAULL, 0x7EE5C0795518FF10ULL, 
            0x631F32E7FD9611C9ULL, 0x266C7876D808C2E6ULL, 0xC43F0987C6F9E4E2ULL, 0x88BA18C61FB3582EULL, 
            0x3BCD44C8C94423FDULL, 0xB29485C9BF320BDFULL, 0xCF30EF9487427155ULL, 0xFB202CF961FCBE42ULL, 
            0xC2FDCBE45BD5D4BAULL, 0xF476D220AD8F734EULL, 0x02CC266C3E942859ULL, 0x3C3E74C31E5A2177ULL, 
            0x4DF3ECA2C1350B2FULL, 0x2EF3CA949A3ACB6DULL, 0x9B8C417870D27439ULL, 0x53B0C616DABEF945ULL, 
            0xD61022CEB1E09F17ULL, 0xBD0BAB902EC24783ULL, 0x77866E1C6C9F1674ULL, 0x98DC8F9F3239F3BEULL, 
            0x6C3248B786665CFDULL, 0x11A82EADEA07FADCULL, 0x102FEE313798288FULL, 0xC8904548E04EB31FULL
        }
    },
    {
        {
            0x8C02202F598061B1ULL, 0x276284324DF745ABULL, 0xCD21039E465EB785ULL, 0x175B91AD871CB92BULL, 
            0xDEDCA0C1A0354B1CULL, 0xF0BDDAB92EC271B6ULL, 0x2AD49AE1381454C6ULL, 0x35297FEF9A73175BULL, 
            0xEF4B15F2A7C4D630ULL, 0xDD01D1424342E72CULL, 0x9B8216231BE6FA7EULL, 0xAAE309D304C5F261ULL, 
            0x51D9C41EE6CA7823ULL, 0x040161CBE94EA7C8ULL, 0xA9AA60343AB50701ULL, 0xA33418F99D04D33EULL, 
            0x56F47D5A3A519B4CULL, 0x628221EDC5C471A5ULL, 0xD43F90E45E789ADBULL, 0x7205E6A90AD8E509ULL, 
            0x439C66209146EAFFULL, 0x89F8C8EF67F4C186ULL, 0xE56367228BB12527ULL, 0x919E7482965BEEFEULL, 
            0xC48A694363B635A5ULL, 0x07707004BCF323CCULL, 0x396BD3C2AAEF6DCAULL, 0x742A0278DBFD2CA8ULL, 
            0xAFC2C597344A8625ULL, 0xB2007E163B2C5F7BULL, 0x6D6C55A4961EBBFEULL, 0xE137E11080EF63A0ULL
        },
        {
            0x0A85D23172E0ED9CULL, 0xA383F0B328CDE34EULL, 0x8E842F7D05D1B842ULL, 0x8E682D7AB429DE62ULL, 
            0x36D511E5E387DAC4ULL, 0x1BE4E39AA6BCF081ULL, 0x5CC3F7ECCBC732AAULL, 0x8A55918583553117ULL, 
            0x8D8935BDD57DA1ADULL, 0xF77F89116AB2AB2DULL, 0xCC137DCDE502CA8BULL, 0x6FD2B0C306A9B656ULL, 
            0xBD209F708770C5CDULL, 0xF9B3D097DD8E4C0AULL, 0x683189ED58FD566CULL, 0x5FE423F979B002C1ULL, 
            0x902C92A1FE25C556ULL, 0x2EFABDFCC583AA90ULL, 0x5668E1D05BDF0581ULL, 0x7D671FA5C3BD20F4ULL, 
            0x41774DEA675506BCULL, 0x51042A709AB175F6ULL, 0x43E78B87A493647AULL, 0x2E52F8C4C9A8C564ULL, 
            0xF7157F44E1962959ULL, 0x6F3112DFF7FE2958ULL, 0x3CA333E3F2EA1B4BULL, 0xFE68D209B332F3FCULL, 
            0x9F6C53C63318F39CULL, 0x43D902C9F7BF97B3ULL, 0x5ADEEEB8922D1F1CULL, 0x05EE5C9AA4F87405ULL
        },
        {
            0x21E77BD47A773562ULL, 0x9AEC7D9DFCDBE700ULL, 0xDA8C3BE32B5649FEULL, 0x5129BE952A3C9C54ULL, 
            0xBCC2BD43F8897741ULL, 0x93034D42C22BE2C0ULL, 0x5122B025708218B3ULL, 0xAB6FCC0C4FA2508BULL, 
            0xC2B795EDE6286EEDULL, 0x9451681CE3BF0BBCULL, 0x4258D665B9EF15F4ULL, 0x7A166B06B507B055ULL, 
            0x250FE0E12B6AAB9CULL, 0x70D27E07B0A2766DULL, 0x8809BDAE0E716616ULL, 0x5ABF43902F6AEB7BULL, 
            0xB30D946C848DBC4DULL, 0x8732B97F3B296F0AULL, 0x0613BEE4ECBFC757ULL, 0xFB46C721EEBCFDD2ULL, 
            0x73D9372A4D0591AAULL, 0x6119D91F972B15C1ULL, 0x79FFF6E95B34D9E2ULL, 0xBA337D3079D7BC72ULL, 
            0x3DD3B77A0BFA6ACFULL, 0xEA597C52C6F49B7DULL, 0x1D88E3A8F6C0BBE1ULL, 0x5345CEC2ED8FB6A0ULL, 
            0xEBF800BC3D5CB7B7ULL, 0x54D338504FB4BF31ULL, 0x9D038FE7BAFEEA9CULL, 0xA1CA7A167D689081ULL
        },
        {
            0x16FE93FB212FD383ULL, 0xB9C37CE339D31570ULL, 0x0832B5DD3BC7EA20ULL, 0xA32018F2B838DA8DULL, 
            0x32D065A5DB184806ULL, 0xAF65C8B13A6D8B8FULL, 0x3B7D5F103CFCB0B6ULL, 0xCEB8AB3F44D87D02ULL, 
            0x258FFFF49674E895ULL, 0xBA2258DF8378BEB0ULL, 0x04F9449B1ECBE8F1ULL, 0x2E30F38F371E5429ULL, 
            0xEFB2D6B47CD890E0ULL, 0xC9FE572F6C3163D6ULL, 0xC451971A4D18AFC5ULL, 0x9CA9A822366AB9D3ULL, 
            0x3285D003E83984CBULL, 0x3FA4E37817D1FAAEULL, 0x31B5762567264665ULL, 0xF78B699C87EDCE5DULL, 
            0xC1D2147D0F1B651EULL, 0x7D53D8133E8E5E21ULL, 0x6368BD75B97248B4ULL, 0x7E51C88DCFFBAEB5ULL, 
            0xA86A9C05D221270DULL, 0x06A2D02BB4CD2EADULL, 0x65CD1C846939EF37ULL, 0x1F608443E99B9F6EULL, 
            0x6A9CC76C65038C9CULL, 0x662171F57AD209ABULL, 0x094A5784154761E4ULL, 0x129737559E164CE6ULL
        },
        {
            0x3B563BD52155A5EFULL, 0xE59BB0A185738E8AULL, 0xEED4EBFBBAFE95ACULL, 0x2DBA86A0EA83C758ULL, 
            0xDF490BA9B7CE92DEULL, 0x4F9E44C4CC3C777EULL, 0x582AE77EE24540E2ULL, 0x8502C0638096DB03ULL, 
            0x1AE30289A2C12A78ULL, 0x9934BA4BF6B72694ULL, 0xA92760F5B8883357ULL, 0x56AAB42723D0D08AULL, 
            0xC84D24151AF5720AULL, 0x22B1723657505824ULL, 0x1AC3B611BD617496ULL, 0x11DC208ECDDD5889ULL, 
            0xEEA312549A0DE806ULL, 0x73DDAABB31DB7DC6ULL, 0x851FF170ED542491ULL, 0x85E4077DDD83CF87ULL, 
            0xB57DF2C3FB06B09DULL, 0x9BE4A4B230B16F77ULL, 0x9CF41029E9BF0CDBULL, 0xA86FEAEFCD829B40ULL, 
            0xFB2624C96FFEB0C2ULL, 0xC263677DFF9504D9ULL, 0x96C2F2E8EFBC231BULL, 0xB70A867E7BC06321ULL, 
            0x5A192F8419F959DAULL, 0xF534DD321FF6730BULL, 0xDC35511C7A036677ULL, 0xFBDC7C606EDA71F9ULL
        },
        {
            0x5C1AC1CDA0BBDB92ULL, 0x0AB1ABB98B0BEB85ULL, 0x2D8D8E8D4575D105ULL, 0x6E20E54134F8F1B3ULL, 
            0x11F666889E51DFFDULL, 0x478EA5664F087A8CULL, 0x893CE92E74180A0CULL, 0xE43F52CCAA09020CULL, 
            0xA604D80CDB3396A4ULL, 0x407AB3D270DA077CULL, 0x9AB7888B91E1AFC2ULL, 0x59B1CC133725CFC1ULL, 
            0xBB7B00CA5E7F470FULL, 0x013C126B30B5BD44ULL, 0x815177B326EBF1F5ULL, 0x7ADCD6D8791507A8ULL, 
            0x021DFEEDFD511C3CULL, 0x648EDA50095664B8ULL, 0x98B99DBD3A50E856ULL, 0xB43677C5E9496C49ULL, 
            0xB3A81BF2274E5F79ULL, 0xB82CB0ADD95406F2ULL, 0x2E5409DA6A9DB3BBULL, 0x1386B0FEB8F68D96ULL, 
            0x3F97B1F035D0EBE2ULL, 0x66808B450160EBD6ULL, 0x288D4EB8D1358CF3ULL, 0x65659CF60945AE7FULL, 
            0xE3BAB80DE3EBFB5CULL, 0xBDEFBF4FCC2CAC57ULL, 0x143820FE30C6E496ULL, 0xB6A24B63F1C71AB2ULL
        }
    },
    {
        {
            0x29196F6DE1BA495EULL, 0x940FE625A60D9141ULL, 0xBE9294027094AFEEULL, 0x242C83F2445B49ABULL, 
            0x8552748499E5ABA5ULL, 0x7B0C0066E448B263ULL, 0xD5BA4D5CE30B32CFULL, 0x59C3F4C4EA8FCDA5ULL, 
            0xE46FA694C5E840D9ULL, 0x86BF4E93DDC42C12ULL, 0xBD88638C0CCEB14DULL, 0x84C6E7E2B1E38360ULL, 
            0xE6EC1AE628A5A1FCULL, 0xCEA164001FA06BF7ULL, 0xAB99B4602032510DULL, 0xC16ECFC55293F8D9ULL, 
            0x402D4B5ACD20E85EULL, 0x93551680643867CBULL, 0xDB0B5D93CE0AC12EULL, 0xE771D0235007D2CFULL, 
            0x1E2EB1E5E7CD0F79ULL, 0x45E8CD97B1586C1EULL, 0x711E47F6F4EBBE3AULL, 0x1FDCF3EC2260EAEAULL, 
            0xCCC49A35F4ADF0B6ULL, 0xE2AB12E4F8652800ULL, 0xC1048716D4D0203DULL, 0x00BD9658E671FBF1ULL, 
            0x453D0AEEB75260FEULL, 0x77388E3FFFD18FE8ULL, 0x112683557ADC9806ULL, 0xED2D6A7FD3C2DF44ULL
        },
        {
            0xAEBFB53056161F40ULL, 0xC266DF0EBA1914C4ULL, 0x5E001AFE7479E910ULL, 0x27AE5CD1592DD16EULL, 
            0x4FBE68AE11F164D6ULL, 0x0E86E5559C1B01FFULL, 0xEDF476E93CA3FD89ULL, 0x7E04CD2C0C7C0F39ULL, 
            0x710CF3A64450EA13ULL, 0x32D7C412ADDECA29ULL, 0x9D7ED90982AFA72CULL, 0x1D938C5D02F29466ULL, 
            0xCA78AE4A40572170ULL, 0x74449549F0279847ULL, 0x88C4D58001C1B534ULL, 0x4F809F9A749C1267ULL, 
            0x245F7C5BAD45D071ULL, 0x6FE284E936189985ULL, 0x1A53CD75BB83E7A9ULL, 0xB0336EDBFCB854C1ULL, 
            0xD2F393A4AA9716A6ULL, 0xDC8EBE860CDAF83BULL, 0x239C343A0B9888BBULL, 0xDD463FA25C3323FEULL, 
            0xD5C745164929DEDAULL, 0x34C112030A2C6F94ULL, 0x5C8FDC8F59AD4547ULL, 0x2304A56F48A56279ULL, 
            0xD558DB9B7C1DFF68ULL, 0x2A68B95759D19253ULL, 0x4C0FF4D9BD8D4887ULL, 0xD119018841A7D124ULL
        },
        {
            0x5974883556A86A34ULL, 0x9602AE70CC397997ULL, 0x9B50B234AD2925BFULL, 0x65248E4FC4C51595ULL, 
            0xE27648B849780CB6ULL, 0x3CA03CD073C52930ULL, 0xEADDAF777C38FC25ULL, 0x5F1795A5D94FF57CULL, 
            0x9A4F337E9D3FFCF9ULL, 0x29D90AAE3DF37281ULL, 0xF3AF5B6AE1E78A82ULL, 0x256D02323F1F958AULL, 
            0xD12B5F601A58D046ULL, 0xAA0CB8AFF1FAAC74ULL, 0xF3456165A41EA886ULL, 0xB6A198C870E1C56DULL, 
            0x4C9380608ACBA367ULL, 0x6B56DE2B4E357B13ULL, 0xEDE903B28920EE89ULL, 0xA2FE8B345AA0E3E8ULL, 
            0x630F46D3B22515E7ULL, 0xB57B8BDCEAF38F80ULL, 0x71AAAEC9C117C51CULL, 0x7C87E4812DE42805ULL, 
            0x05162A57AAE113A7ULL, 0x5D68A08509FBF9E7ULL, 0xC77AD8D987D9435DULL, 0xA7B34F7D5D8963A2ULL, 
            0x7ED313B2920ACD47ULL, 0x47514E1F05B453A3ULL, 0xB1EA4932EBD9540FULL, 0x02ED59E5B698EF3AULL
        },
        {
            0x5B222CA42B9DBAE4ULL, 0x77A44DE151620C14ULL, 0x9258DDC66D2A3647ULL, 0x86AE7372261EFB40ULL, 
            0xCF9289F9763722AFULL, 0x95D0A2D30EFE74ECULL, 0x160E88239225655BULL, 0x9DDD85007E5EB984ULL, 
            0x07BC724023B42903ULL, 0x3C94C6E3D3ED5EB2ULL, 0x3F2A722C452F8CECULL, 0x765D93D9BCA0E4F8ULL, 
            0x369613A4481C34A9ULL, 0xBC3B0B08D2786240ULL, 0x44BD08A287389666ULL, 0xC9B03975783562E8ULL, 
            0xCCDF5E6B652CB2A7ULL, 0x7BF35BFB29770764ULL, 0xA075A4A9BD97D501ULL, 0x622F5C4FDDABCFF7ULL, 
            0xF03E1C32B5DC488CULL, 0xE69D0A72E601F178ULL, 0xB16DCB663C1FF8B7ULL, 0xE6E5EF61CEBF65E0ULL, 
            0x30EC8FE0B1DEEDB4ULL, 0x2F6AE8EC2FD0882DULL, 0x8D6F96EE10DFE6F0ULL, 0x4631344208D2E30BULL, 
            0xDCB70AC9CD33166AULL, 0xBDE2EDF764A4317DULL, 0x10BADDD69F8D3CBBULL, 0xC2E34423B7699215ULL
        },
        {
            0xD033247202FFFB69ULL, 0x7BE938FB6C834133ULL, 0x3C9115C4532B0B7FULL, 0x55D6A7D387A161B8ULL, 
            0x0F19148766433956ULL, 0x50B37F6F84E22E6DULL, 0x1BCBB31BCD5BA15EULL, 0xF72F2C7FAF7F6F6FULL, 
            0xF27B07140CA4650CULL, 0x3E6EF6CE4340C064ULL, 0xC17461B542ECAD08ULL, 0xD2ADCBDD56F9703CULL, 
            0x32436249D2E0B39EULL, 0x5B460C319ADC555BULL, 0x3BEE4DA83EC8640EULL, 0xB70979219CFA7032ULL, 
            0x156FE6D479F8D967ULL, 0x6532161B874FF6B5ULL, 0xE33867E5E0D10A5CULL, 0xA319900002D2ADCEULL, 
            0x4584AF187453A152ULL, 0xB7D118BCFD4210EBULL, 0x72D4C5D0B37B8492ULL, 0xCD6802A12046C28AULL, 
            0xC16CA02535CD4340ULL, 0xA06671E7D5F16158ULL, 0x9931D641E355D12FULL, 0x0AF26BF14F7004BCULL, 
            0x8826AEBDF0BD615AULL, 0x4A9D42D5E76C6854ULL, 0xC5D42BA34385147FULL, 0x1536B53BDC19F5BDULL
        },
        {
            0xDDF03349BEB74BC2ULL, 0x9A1050B6879BEDDBULL, 0x68EA6CEC0B150488ULL, 0xE795E6E5C5B4868BULL, 
            0x616D098053FB7B8AULL, 0x323AEC61CBC92F7CULL, 0x8A5E3984EF1F84B3ULL, 0x6245C4B7ABA0B800ULL, 
            0x713F2F2FDC94442FULL, 0xB940CDB9FC73804DULL, 0xFEC583220C39EA86ULL, 0xFF57FDAA822B34F7ULL, 
            0x2CC79CD11184ED07ULL, 0x59ED1CF738EF2023ULL, 0x3242EB76E01E9E47ULL, 0xC349D2E8949065D4ULL, 
            0xE5FB34DF5AF2FFF0ULL, 0x4185530D1EFFCF7FULL, 0xB71B71985B78E957ULL, 0x03F9F7CEF64CEB9EULL, 
            0xBA90A1B121968BFEULL, 0xE23DC470D78E305EULL, 0x2FBF675DF9843316ULL, 0x849330B33E77EAC0ULL, 
            0x6B2F7ADE765DD64FULL, 0xB7C32F12D50558D0ULL, 0x4D66F0395404A022ULL, 0x39AFBF01FDA3DA0DULL, 
            0xB74AEFB85D858D48ULL, 0xD5BB7583AB6039C5ULL, 0xF30FA640CB7410ECULL, 0x8E21A87D527EC8F6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseAConstants = {
    0x6DB7256BC248623CULL,
    0x462F0675F31E1657ULL,
    0xA4CBA71F073FBAB1ULL,
    0x6DB7256BC248623CULL,
    0x462F0675F31E1657ULL,
    0xA4CBA71F073FBAB1ULL,
    0xA6302B89815E719FULL,
    0xE5427D8273E2F16FULL,
    0x2A,
    0x42,
    0xBD,
    0xA2,
    0x0C,
    0x2B,
    0x53,
    0xD4
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseBSalts = {
    {
        {
            0x12930B3C34E5B18BULL, 0xF916024236242221ULL, 0x74B99686536DBCF3ULL, 0xB76D3E0F6F55B9CAULL, 
            0xAA6C42CDB7F12767ULL, 0xC2913EBBE08BDF20ULL, 0x39D01AD197A8860AULL, 0xC1D3AE7584E7E72AULL, 
            0x8A7169CAAFAF429FULL, 0xA3F5C166D3CE7B4FULL, 0x99879B845032F006ULL, 0x0B0AF7BA7961DB29ULL, 
            0xF53636151A40A590ULL, 0xC33EBE853E8D14C4ULL, 0xC8CE1A1C5631D5F1ULL, 0x573F161559AA57ADULL, 
            0x0450D4C831ECA276ULL, 0x8C872632BC96AF66ULL, 0xF5413218ACE58047ULL, 0x77E901A04E592600ULL, 
            0x468765309B834EADULL, 0xA25D0AFE85AC7A98ULL, 0x0FD8613D2C695049ULL, 0xF7433ED39858CF4DULL, 
            0xFD398BEB434B6536ULL, 0xB7A67D4B3281457CULL, 0x4CD3B3C3F0EA30D9ULL, 0x68AE2D9C8EED261BULL, 
            0xB168B4C43627757FULL, 0x5D00527E0FA9559CULL, 0x1C94B001A666CD40ULL, 0xA7B22CE49F2D1948ULL
        },
        {
            0x9DA14EC4A1661DD8ULL, 0x943EB154DA267A12ULL, 0xC8FE2738C0C1F8A8ULL, 0x1C04EF027A67250FULL, 
            0xF9BAF6E3B2FB286BULL, 0xBDBA44AE998D0587ULL, 0x1FFECD07008935E1ULL, 0x783011FE5D1CBAF6ULL, 
            0x0F07DAD2275CFA70ULL, 0x7632006F97050965ULL, 0x299511733E7547B8ULL, 0x7A27709374EF03E3ULL, 
            0x9BCFEA51A076F2EBULL, 0x5F8BA19DDE372957ULL, 0xD25D1F36B7C05D53ULL, 0xBD039C5240733928ULL, 
            0xC9CECEBB19A5AFB1ULL, 0xCCFE25BFB7DFFDE3ULL, 0x5A497C515BC38BCBULL, 0x2B9D4C4A440227AAULL, 
            0xD9CDF83C0BBC4722ULL, 0x7A4F1E14030F0992ULL, 0xA6556AF9B2072376ULL, 0x24ACABCDBC8C4CF9ULL, 
            0x69C90D3ABD8F8111ULL, 0xEAE6C5B8F195AFF2ULL, 0x65B116723313480FULL, 0xA7494EA4D1E13949ULL, 
            0xD233C15172094F5CULL, 0xF53065D2696A80F6ULL, 0xD85BA1DEFCA2E7C7ULL, 0x52D118E2CF66BB3EULL
        },
        {
            0x673DF4CAEC70DFC5ULL, 0x674AD61A01EE66BBULL, 0x2B9C90113A52044AULL, 0x728FEC503A0178BFULL, 
            0xE703F8AA8F0666F9ULL, 0x1969584A7F36C90BULL, 0x8D4F958513F13CD7ULL, 0x47640AD9053B3D55ULL, 
            0x58DD94A955FB1503ULL, 0x101ED3DE2E78B6F7ULL, 0xB8B288016AD9B861ULL, 0xB616DFF3B07D31F9ULL, 
            0x72779F4478D83CC2ULL, 0x17F81CEB40C8D133ULL, 0xB81E9818985E5045ULL, 0x1B9B75102CC6329FULL, 
            0xB7AD6C979A89675DULL, 0xF402E57274B6E714ULL, 0xFC191CD51C9153D8ULL, 0x03F66B9B774BAC2FULL, 
            0x5357B68204C8130DULL, 0xFC242A1637E90FE2ULL, 0x116C657EEA160E30ULL, 0x6A3725084E8FF8DAULL, 
            0x128D9E16DD5C2335ULL, 0xFA28BBA301117214ULL, 0xE58BE5FEEB01D3ECULL, 0x2C5986FC13B36409ULL, 
            0xC193A32B5E218A24ULL, 0x0BC8CB89F33B5537ULL, 0x2C4311D0E3BFEFACULL, 0xB7139C6FB4229832ULL
        },
        {
            0x881BCADDED06D5F8ULL, 0xE4C2F08D9A0103CDULL, 0x1823480A5E281AEDULL, 0x4AAECFCD4EA0867AULL, 
            0x5C3FFCF2EF48DB72ULL, 0x9FF9A742347FE99FULL, 0x9823837B9D14ED3EULL, 0xA5B051C68A263AB8ULL, 
            0x36B5DEE064A536C0ULL, 0x135B25575477DD86ULL, 0x83C9512BCCCC2576ULL, 0x076A9F9EAED58706ULL, 
            0xAAF0BA63FE9E3B6BULL, 0x329F6D3EAACC5124ULL, 0xC8053AD71863FBF7ULL, 0x5105C97ABC8F3E07ULL, 
            0x4C61B8291ACB8819ULL, 0x8653D7A84AC5DC89ULL, 0xDD35DFB72BC4A39DULL, 0x9D701CE1BF6A7F4AULL, 
            0xC2458BBC788C5AA6ULL, 0x4655FF8B7F698905ULL, 0x1EF0501D08C4DA6EULL, 0x940921DC6F1A9B38ULL, 
            0x20E011C9B19E1AB4ULL, 0xFD03A62F79A8AC30ULL, 0x8BC5DF45FAEBA21EULL, 0x2F30F03569EDBC69ULL, 
            0x51E95D77ADCD4226ULL, 0x248546DD3FC22DFAULL, 0xC57435F62697DDF9ULL, 0xCF9D3EEE3E054AF9ULL
        },
        {
            0xC78F79EA8D0AFF66ULL, 0xC0C1D7C59779B4F3ULL, 0x66CCA23C1E93A0C7ULL, 0x840BBE1BC16EF534ULL, 
            0x14D1D081C63B1B10ULL, 0x4CA346D2A95EA458ULL, 0x87FCD14871131D51ULL, 0xD233EE76024E59F8ULL, 
            0x44C6A986B002014DULL, 0x39F19D496FEFFD53ULL, 0x796B64DB0D5E977EULL, 0x9D0250565AE1C586ULL, 
            0xAD46DC16624F092FULL, 0x68F0462AA90E55FDULL, 0xD088CC9F1BE71682ULL, 0x38F118F1944E8898ULL, 
            0x6A2DE832795FDD01ULL, 0xAAE8DBA29BDA139CULL, 0xE892E7EE9FD8A206ULL, 0x62A298324F06C03BULL, 
            0x4100BF83E906EE4BULL, 0x11AFB17F52BA8F8EULL, 0x1223D6F4C40FD16CULL, 0x914D2F12C054A59AULL, 
            0x66B31E6D61257913ULL, 0xE2CC517DCB6BCFF6ULL, 0x806647E451437C36ULL, 0xD29730C64A4DFB85ULL, 
            0xD512B1F8E4A983C7ULL, 0x5EE66B5A05D5B519ULL, 0x2BC8748F3C8F05F1ULL, 0xEF6E40EFF39D92D0ULL
        },
        {
            0x48701C03593CC827ULL, 0x0486580B095795B2ULL, 0xC5ACEF6E825FE64DULL, 0x22CDB33B2286F8AAULL, 
            0xA8C0AE9306FD302AULL, 0x743C59D681761671ULL, 0xA61484A0D97520D2ULL, 0x1F876673B1A64F2DULL, 
            0xFB367E6037F9B0E1ULL, 0xCED8347DC006C156ULL, 0x6677DA888DD2F31EULL, 0xB82F9CBB48FE10CAULL, 
            0x5919B0CF9034CE0CULL, 0x6109C7C7C9A0D5ACULL, 0xF33F130BE3FEEDC8ULL, 0xDAA84F1F7DA5B785ULL, 
            0x4D3DF868106BD970ULL, 0x1E937369EABD2C53ULL, 0x9D15859B1A3A8E62ULL, 0xB256679711F9A27EULL, 
            0xDE23957327F721ADULL, 0x6FAF7ABA2B3EC9D1ULL, 0xF1AE554A97DB3CB9ULL, 0xEC96819EC788D499ULL, 
            0x1D611B78DC4E7D32ULL, 0x98120AF4A37AAB61ULL, 0xA010FA38361C7C37ULL, 0x87ED95C90093FF56ULL, 
            0xA8477D5BBB12A610ULL, 0x5639C0822B65BF1AULL, 0xD420CC5298611E2BULL, 0x43285605951D1C3DULL
        }
    },
    {
        {
            0x762970128E7603ADULL, 0xE04275FD885A62D9ULL, 0x5523454E553C645CULL, 0x1681428F5C949F3FULL, 
            0x8CD7C1C98BE7AA28ULL, 0xF3486AB446C06D97ULL, 0x98A0B2865EF7CE41ULL, 0x5B067AB59C72D103ULL, 
            0xA1DF1DFB0B74CE73ULL, 0x68C07B41947B92EBULL, 0x37E13F150B4A7A5AULL, 0xD6D9BD9DE5A345B8ULL, 
            0x65173D8091AF6FCCULL, 0x917EB81D89DA5F99ULL, 0x33893ABD0BBED220ULL, 0x7266D7B6F4468E51ULL, 
            0x3B50F9E8B3CC3FECULL, 0x149B8C4BEE9653DFULL, 0xB1C4DC1E3BB94DCCULL, 0x29FD808557E9C3CCULL, 
            0xD29CE4C369ECE35CULL, 0x611E7ED118A98A1BULL, 0x733E6AE4FD89E1B8ULL, 0xE2F8584510199597ULL, 
            0xA856468DDCFD139DULL, 0x2A4C2D7EC48C61E9ULL, 0x5E68F7B6FD78D98EULL, 0xA54CC75402BC411AULL, 
            0x28697DA23D4BF69BULL, 0x0AC027F9C8D92084ULL, 0x6D4AA5189A0F460CULL, 0xF73711693B2D7267ULL
        },
        {
            0x593E1524BB8186F3ULL, 0xDA32481E61749E06ULL, 0x239811E8F60B003EULL, 0x06399A2BB5314BC0ULL, 
            0xD1B1F83DE882144FULL, 0x38F45C801FCF00B6ULL, 0x7EFA7E879620BCC4ULL, 0xA8F13CDC238F3547ULL, 
            0xD42C353D64908D6BULL, 0x835414E7FE0488D8ULL, 0xE6ED94ADE6100782ULL, 0xD4735C0CDC0B35D2ULL, 
            0xBED47CE15B18C7C2ULL, 0xF9D5F85E5563C419ULL, 0x40A8BE9D3E5E1C47ULL, 0xFD04F5FFDDC065B4ULL, 
            0x42E3A4488585FE22ULL, 0xAFCAD0717E3F9C4AULL, 0x319065B1F81AD769ULL, 0x4E3F18F2FE6CFD7AULL, 
            0xE087B9D1BD54DD54ULL, 0xF8C78DFEF03FA481ULL, 0x258316677D38C79AULL, 0x2344540AC3C6C767ULL, 
            0x5C6F7A0171EAE008ULL, 0xDE84591E835A5407ULL, 0xB7F4D9C02FDD319DULL, 0x6DC23CE3B3F63093ULL, 
            0x2CC614E90F38FA50ULL, 0x0295B2321230C0EFULL, 0x9DCA49458962448DULL, 0x599C3E8DFBA21743ULL
        },
        {
            0x9C6087B0C40CB3BEULL, 0x17857149563B3B16ULL, 0x2AFEC5BCB1AEBFE0ULL, 0x29F6C93B388858FAULL, 
            0x664A0646566B637BULL, 0xF98AC43F5F33D742ULL, 0x8FA7F822C3EBCB42ULL, 0x0503149F0C733264ULL, 
            0x5027EA71B1AB392EULL, 0x98DCC6B97FAE396FULL, 0xD07E62BCA4A1BE2AULL, 0x21BE260A6BCBD7C6ULL, 
            0xFBC970AF89704FABULL, 0x48F27C463B5A7F7AULL, 0xE968E83C9E304331ULL, 0x51A96735ABFF68B7ULL, 
            0x7651E2770D3E68ABULL, 0xB7E6B029821FC4B0ULL, 0xE37CFAAA512EB62CULL, 0x87694C960C8CBF32ULL, 
            0x543CD1FA3ED63751ULL, 0x29B5741B4CBB1651ULL, 0xC0AA79AAD70358F2ULL, 0x9A33ED866E79E870ULL, 
            0xFA9BFB1A3B67737FULL, 0xD9EC21648340B85AULL, 0xF17ABA6916E06780ULL, 0xD4339543BD906CB1ULL, 
            0xD5AB1A398B455915ULL, 0x13E43336985BB471ULL, 0xCDA5636026939E84ULL, 0x43FD8727ACA091BEULL
        },
        {
            0x9CDBA7BBD4A93EDCULL, 0x8BF4D3238924D60FULL, 0x8CB4A0C1E96509C7ULL, 0xF7E9F52016B87963ULL, 
            0x8E4B56AAAFC69582ULL, 0x01378AC88647ED1EULL, 0x3FA04898F7732AB0ULL, 0xCAAFCE82EDE90ED2ULL, 
            0x5ED60DE9CAF93780ULL, 0xC7A1B83C94717A3FULL, 0x2F75E6DBA023DDC3ULL, 0x4633DE9D6DF8FA70ULL, 
            0xC9F6E3A30F2508B3ULL, 0xB8793E1BC98A7F75ULL, 0x98A1EDAAE790E613ULL, 0xC31D6C83BD3DB21DULL, 
            0x7570C8C4E9871EE2ULL, 0x288162CBB2001CBFULL, 0x8A7326756FE0BFD2ULL, 0x68B28D01C5C7176CULL, 
            0xFF3A16578B68A521ULL, 0x5C731C40322393E6ULL, 0x158C7140250991B5ULL, 0x8B62AC5FC02F9462ULL, 
            0x8D1ED7FB3F64E883ULL, 0xEF94B844F138EAEAULL, 0x74FC95CEA1A67184ULL, 0x596352362296BBC7ULL, 
            0xD52CBEF445710F53ULL, 0xDB586EF172E696D2ULL, 0x20389670FE892197ULL, 0x7DDD8811EDB4C8A4ULL
        },
        {
            0x558760727F3A1263ULL, 0x003037F720265024ULL, 0x38B4D1BBB1723271ULL, 0x172CCF4C4B1DEA75ULL, 
            0xEBB425EA29086B7FULL, 0xF7ED5185C4D16302ULL, 0x2A2BC871DA5EA858ULL, 0x08BDB3A83DCEFD74ULL, 
            0xA2CD76134E3C4AABULL, 0x50E03F722CBAEB7EULL, 0xF121392669FEAC2EULL, 0xB693BC577F56FA6CULL, 
            0xB5BD4713E58BDF7BULL, 0x44D5E8750C0DC02DULL, 0xAC98598FE1B5B534ULL, 0x9DBD0129A792E02EULL, 
            0xE2D1BDAEFB369621ULL, 0x556D1EF0E56FE52FULL, 0xC9495DB2CDEC92F3ULL, 0x85A442FE2CDCE70FULL, 
            0x86D6C8ACCDA8646CULL, 0xD377020AE46DA0FDULL, 0x1113F402DEE84817ULL, 0xB125C725F10FD9A9ULL, 
            0xC8C162B7C3121B04ULL, 0x8CC59BF7F18D3879ULL, 0x01F5DAD87F2FD747ULL, 0x6D6D79FEB2AC9A4EULL, 
            0x7F2977D43EEF4ECDULL, 0x87CEEF0EAE3C32EDULL, 0x6B289DA92D28B97CULL, 0xA50B1E331014EC12ULL
        },
        {
            0x16A4FA7FC6908EE8ULL, 0x1B919DC39BA0CB07ULL, 0x4740C256AF86BDA4ULL, 0xB86C2800F287C05DULL, 
            0x0BC98290C99C14A9ULL, 0x26B9E1CE80D87266ULL, 0xA7E4EF039B7C2334ULL, 0x2C6998C6D7FB83DAULL, 
            0x7DD242A94EA72A90ULL, 0x0DAF1DE01F8C9882ULL, 0x619749C8865D7E90ULL, 0xC1D39B37A032492CULL, 
            0x5CD98ECB62FF944EULL, 0x496B59FCED1C438DULL, 0x0F3B29910654D425ULL, 0xA3E5047763414CCBULL, 
            0x8890900D9203CEA9ULL, 0x1F6BACB020FC08B7ULL, 0x550B92E1424EEAF8ULL, 0xD31EAA545500B139ULL, 
            0xC56CC086F0D84D7AULL, 0xACBF406BE4B7B7E8ULL, 0x2CC6BBFA555FF9AAULL, 0x0049D6AB3D9B7EF5ULL, 
            0x0C8CB9E9DB4A31DCULL, 0xA99886A7D8BE59A1ULL, 0x76084E0E213E49CAULL, 0x17AFC2D6A7D3E060ULL, 
            0xF453871AAC3686E1ULL, 0xD67D972198A617E7ULL, 0xE1EEF4D67B15DDDCULL, 0x090929CB6C93692EULL
        }
    },
    {
        {
            0x9158B818720E4353ULL, 0xB2F9B56C34E07DEFULL, 0x676E022D743C6428ULL, 0x04E8D3BD6352DB6CULL, 
            0x9CA7ED6286B515E7ULL, 0x1C75B2DDCBE3569FULL, 0x348819C696565857ULL, 0xC6D9D0715E604886ULL, 
            0x5DC3532DE24EBF36ULL, 0xF94BAEC5D7FE184DULL, 0x7B977454AA9489B4ULL, 0x015D9B94E4D2309DULL, 
            0x16B07F9468057DF6ULL, 0x4213414FF5A2C74BULL, 0xAAA60A2463884CC8ULL, 0x7065BA653A004D9BULL, 
            0x6634C1F390F1AF20ULL, 0x109D5BB32631F45FULL, 0xDF3F4A26E783B29BULL, 0x8ED18E98060A3E2BULL, 
            0x92AE63261AC540C4ULL, 0x33371ABFDAB65DB2ULL, 0x4362A6B21A5C89DFULL, 0x0C722165013F048DULL, 
            0x0B5A36EED9E56BBDULL, 0x6B8E2D385FA6AD97ULL, 0x4D841FC4CB6818E0ULL, 0x09082C8A863C73B2ULL, 
            0x5C4C9E54B9125DF2ULL, 0xD8C8B5CFF27890C3ULL, 0x6CBA1FA5DE7EBCBBULL, 0xDF261ED1E0A390D5ULL
        },
        {
            0xDB0452CF9733B0DDULL, 0x6B7232F096944F99ULL, 0x1F0AA2489A3B3756ULL, 0x79FAB1C41A428D9EULL, 
            0xA13EBEC7410118C4ULL, 0x165C9276B3CB5805ULL, 0x090C5DEF9EEE43C4ULL, 0x8DDF2CAC9A7674AFULL, 
            0xCE4DFDCE16BA800DULL, 0x629EC6AB487B140CULL, 0x158C8C979E125655ULL, 0x5158876745A18BC5ULL, 
            0x2542DFDF4224E761ULL, 0xE53CC3718C6595F4ULL, 0x09B00F64D5B00CCEULL, 0x4C65C9D097DE7FBDULL, 
            0xA9C4D02382703C07ULL, 0xC2A40ADE147C11FFULL, 0x29E4A9FF688BC189ULL, 0x5987B15E04A25FF0ULL, 
            0x56F255D1A96D2B47ULL, 0x0D2AB18C68325C18ULL, 0xDDA64EE7EDF00E21ULL, 0xE9989C8E9B720CE6ULL, 
            0xF413763709095089ULL, 0xBB27D0D5B6DF52F5ULL, 0x97737F8F03B17CBFULL, 0x830B4B70882E72B4ULL, 
            0x8A32140EF6D14806ULL, 0x3FE8CB991474F2FAULL, 0x8FEF25A23AACA930ULL, 0x5A5C1BC5AA6E170BULL
        },
        {
            0x87989C48FCB21A31ULL, 0x58F60146D7A25D14ULL, 0x6FB6188573829D76ULL, 0xABF8461E3645105AULL, 
            0xC131138EF0EA9C35ULL, 0xAE9E48986B7EA0A3ULL, 0xAC79E10123644DFEULL, 0x920570BD54F14403ULL, 
            0x9292DDF0BED509FBULL, 0xE5DD6D936CA719B5ULL, 0x491872FA121F36EEULL, 0x55F1545E099FDA0EULL, 
            0xB999643E92606504ULL, 0x8AD600EAE82E525CULL, 0x0CC1C2703BF0A2CDULL, 0x546F2540A95537FCULL, 
            0xB7F68F0C0EB2267CULL, 0x2E6648AE96EB964DULL, 0xF45E70948A8F7776ULL, 0xB37903A85C38534AULL, 
            0x25ACB0AA35BEA69EULL, 0xFA935627807035C3ULL, 0xE09FC9F380F5973EULL, 0xA9CEAA158EEDD70AULL, 
            0x3703AC64808A2C9FULL, 0xCAA85E6A797E246EULL, 0x9F4F89CBBA459B2CULL, 0x6C5E32B04D1386BFULL, 
            0x01381C89F6EB9739ULL, 0x576107092169BE11ULL, 0xFFDBF6D36786E5C7ULL, 0x28D821FFA73AB941ULL
        },
        {
            0x8B2FF98A0DCE76FDULL, 0x2FFE9BB8CBB8C524ULL, 0x15AB54C76153BF12ULL, 0xD0DD9C5779EFFBDDULL, 
            0x5DA40F36DEF127AFULL, 0xCB3D43D088EB7A19ULL, 0xDF7262200A2A2360ULL, 0x8B651D541118ACF1ULL, 
            0xE403D2DFFB1CCE5AULL, 0x114C2D0D249B515AULL, 0xD9B67BA40536D16BULL, 0x6BA1FBBD60F616F5ULL, 
            0x044826FA4FBBEAC8ULL, 0xE8C844CE89F59828ULL, 0x764BDACE1B7D1A0FULL, 0x864D94CBAEDD691DULL, 
            0xEAD60C74E180AB39ULL, 0x934ADCC4DB0F7C53ULL, 0xB1C52E315377F6F0ULL, 0x4085264E667919D5ULL, 
            0x32A86BDFD4263EE0ULL, 0x649A6337CFD6E9D7ULL, 0xA5210F1867C43FB7ULL, 0x4C81EE3F028784DDULL, 
            0x6B4F0E76D15D4E8AULL, 0xF61DC68DB41D9E80ULL, 0xF7053F66A8A66922ULL, 0x3090363810B5672FULL, 
            0x910C87B6750E41F2ULL, 0x3092B0CC815D9F37ULL, 0xC0F2E2DEBCF17C13ULL, 0xD6F110ABE50C8B16ULL
        },
        {
            0xBC2C844EA71AF77AULL, 0x9CC21FCB928FD78AULL, 0x0A1204509F446E09ULL, 0xF845AD0BABF8CD57ULL, 
            0x870604FC2D0CC791ULL, 0xDA7BE9A512F50933ULL, 0x7378394A70B02993ULL, 0x4D1F62BB5F17C93CULL, 
            0xEDF3D69FE80FC221ULL, 0x50C77467B9C677EEULL, 0xD0D6F6E497666DC2ULL, 0x2FD0F70797D06451ULL, 
            0x748D0B0BED24E346ULL, 0x76976BCFE81CA8A3ULL, 0xFFF0270F78E227BDULL, 0xC5D2B4123BAF7C59ULL, 
            0x8ED5C292215878B8ULL, 0xF55FFAAD0F68B2C9ULL, 0xA7F4E8E44C821241ULL, 0xFD230B887048C524ULL, 
            0x2618B6E0BF25C669ULL, 0x60D7395C1FA0B640ULL, 0xFB70A2CB79368B74ULL, 0xA759A55263D04DCBULL, 
            0x0530E7FE03F9ED13ULL, 0xC0AC203E9B2D3B73ULL, 0xE6188C67487FA8EEULL, 0x15ECB735A590921BULL, 
            0xB342746C9E9F5284ULL, 0x43A7F86B499192B9ULL, 0xE1A9B1000DFF25DDULL, 0x06D5D811EB520EF6ULL
        },
        {
            0xE11A59F8F1CB87C9ULL, 0xF6137808E89C7BB3ULL, 0xDD5675900B15E1B3ULL, 0x26B92855D79BD009ULL, 
            0x1386F5E9935051BDULL, 0x7CA901B68B9DB993ULL, 0xDC85341086A32ED4ULL, 0x0375A50EF379E667ULL, 
            0xD631A17D5F8ADB63ULL, 0x21FCD39051FD86C2ULL, 0x5BC24E1A0FA359B8ULL, 0x05E7EF71A20A6358ULL, 
            0xD1F6F548E1E01F70ULL, 0x4F3DAD417E22A555ULL, 0xBADCF41BBEBD28F5ULL, 0x2FB7E4635F718FE6ULL, 
            0xD2AF0AD9CBC475E5ULL, 0x697EA0CE0BDC33B1ULL, 0x8EB8D0D8FD6B22D7ULL, 0xE1C85A3BD1CE82A2ULL, 
            0xC1A5E8E35081BCB2ULL, 0x60FE7575E7481A2DULL, 0xD5959FCC5CCFEC69ULL, 0xC6880FC2FC15E357ULL, 
            0x56E95BA1BC2F77A7ULL, 0x57D330141342D32AULL, 0xB1B7A9EFA9B4BE1CULL, 0x9D4C92D86891277CULL, 
            0x2BC58AC0F86DD4C6ULL, 0xBDB4406730BF9B4CULL, 0xB42ADF9231DD3F9DULL, 0xEE69E374789A2740ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseBConstants = {
    0xFFD0427101A64B25ULL,
    0xB65AA4657B4FD048ULL,
    0x33E45555280B772AULL,
    0xFFD0427101A64B25ULL,
    0xB65AA4657B4FD048ULL,
    0x33E45555280B772AULL,
    0x132A14EF07198086ULL,
    0xA98AD834000353E1ULL,
    0xAB,
    0x45,
    0x7D,
    0x87,
    0x64,
    0xBE,
    0x62,
    0xAD
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseCSalts = {
    {
        {
            0x09C9EA4A1384E874ULL, 0x221C457126229D7CULL, 0x776F89D7F68D0DE5ULL, 0x2DBE1A01DDC82ACCULL, 
            0xDA539329E5DA1B0DULL, 0x12D334525991A7BAULL, 0x200E7F48CE23B874ULL, 0x98D011916FDBDAA1ULL, 
            0x5B3C7CF0656E2D3EULL, 0xC634E79CA947C73AULL, 0x8A97470CB32A2405ULL, 0x116D108169F8F4ADULL, 
            0x3354975E6CEDFC0EULL, 0x657DEA58A5DE849EULL, 0x141D66EC481B4687ULL, 0x8F3F3E99BFD702DBULL, 
            0x530A99991B4434C7ULL, 0x8E3C08DB56A1EB39ULL, 0x913ABBD50128C107ULL, 0xE38F5B9B3D207919ULL, 
            0x2F14687B955558D7ULL, 0xD52EC8D5F56EF23BULL, 0xDCEA4A9CC68E889CULL, 0x14AD42059679C378ULL, 
            0x2BB4B49482C93258ULL, 0xD5D40EC0D31187E9ULL, 0x23AF2BFAD5EDDBBAULL, 0x6A0075C11572B917ULL, 
            0xC932E1575BFE5493ULL, 0x9A8FB2BA3284FD80ULL, 0x43CE4242BC8DFC1EULL, 0x783B73FBEB32FB01ULL
        },
        {
            0xB7889C17C9410C5FULL, 0x700A257C5B0749C8ULL, 0x57383C7A2EF3332AULL, 0x734472A1E84C122CULL, 
            0x1F6380F381C3AC0BULL, 0x39A168A1F8480DA1ULL, 0x0870F3B755EFC098ULL, 0xB87A33A4BD5D0861ULL, 
            0x68BBB6D6C6A7359BULL, 0x05B7DA65A399BAA5ULL, 0x880B0C9AACB13789ULL, 0x447DC552EAAC8231ULL, 
            0xA0721B099FE4B01FULL, 0x0B96955E4DA2421EULL, 0x6737879B86941D35ULL, 0x0AFAE4C62C6578E8ULL, 
            0x77F552593B728F76ULL, 0xF1472D18092A668EULL, 0xBB3896243E0C3807ULL, 0xD0CCDECC4E8AB72DULL, 
            0x9B8E11A95D4E5D97ULL, 0x5E47E4FE76020A40ULL, 0x9CFB22059D6CD514ULL, 0x6E62DC210C6B225AULL, 
            0x79D83021FE8F5A67ULL, 0x69238E387E16FFB4ULL, 0x1942716CE8B3245AULL, 0x388DEF34166F5906ULL, 
            0xDAD63079CC6AE3CAULL, 0xECC3CFDB05642DFDULL, 0x1C6FA9549242C759ULL, 0xA1114A879157F126ULL
        },
        {
            0x071A0F5BCC2A8F85ULL, 0xADF4DA55CF94FB33ULL, 0x2401DFC947784575ULL, 0xE7C4E707577F8AE8ULL, 
            0x614A232CB1671042ULL, 0x0B386D393AD69525ULL, 0xF19BF485BCBC9011ULL, 0x785EF148C690BE7FULL, 
            0x1E4A1873A77FB433ULL, 0x9E142687622AAD8EULL, 0x6697FC4E180501BFULL, 0x41E1AC0157355A37ULL, 
            0xE85284C3DCEBB2BAULL, 0xDFC8CDC5AF8F38DAULL, 0x82D6061B1BD60D12ULL, 0xA3519711CC3A237DULL, 
            0x4DE77C205A00A504ULL, 0xAFF24D82414331B8ULL, 0x046AB74C0345BFFEULL, 0x9E77039E8AAF4881ULL, 
            0xC965EAE672D1D1D7ULL, 0x5CC6A602EC88EC45ULL, 0x5D1AF2F1AC0EBC18ULL, 0x400AC5E8ADCCA80EULL, 
            0x004AE709970914DFULL, 0x1EADB0186B13508BULL, 0x990EEA3E83339B29ULL, 0x8E4CB7950D474F30ULL, 
            0x692F6D6D0F87B0C2ULL, 0xCAE370BD525F8405ULL, 0xA08D18249B3827FDULL, 0x92DCE8447860D820ULL
        },
        {
            0xB5D521CDA16CC9C5ULL, 0x77DC6726F13BF1DBULL, 0x6D96018C9B808E17ULL, 0x7908ACE30973BAF7ULL, 
            0xC44633B759295714ULL, 0x3F1FE6DFD462E702ULL, 0x2D2CCDBE05B140C2ULL, 0xBAC411342A09C765ULL, 
            0xAF0D306D15079A96ULL, 0xBF52878FDA994C82ULL, 0x342D7755EC9724E6ULL, 0x3FF852B2869A57B6ULL, 
            0x1FEB6A88E32DACBAULL, 0x3EB61736AD58B10AULL, 0x938737375E1DAB69ULL, 0x73C72CCE201CB1E0ULL, 
            0x33BFB86E16CDE434ULL, 0x54FB79A1303E48EDULL, 0xE83215E99B97BECFULL, 0x35D0BF664AF82C29ULL, 
            0x8B373F6A52F014BFULL, 0xE4622E73687FD74AULL, 0x33328E7267B95A64ULL, 0xB278196874565B75ULL, 
            0x6D4358D9ACF0A700ULL, 0xFAEF30DC1C01EF5AULL, 0x790D052E98BAE6F9ULL, 0x723382B28ABCAB0FULL, 
            0x6293509647028627ULL, 0xC1047168EB81B672ULL, 0xCE5C53D92FD52517ULL, 0x45F0A7B41EB35C2AULL
        },
        {
            0xCBAF198BE34B5A13ULL, 0xA356DB23459E175BULL, 0x33AE5B51AA57BA13ULL, 0x97C82BBC89697FE3ULL, 
            0x0D9C2D4E8F077D6BULL, 0x36A8F53B61B2F2D5ULL, 0xE4409D9EDDA25804ULL, 0x349FEC67711B89B8ULL, 
            0xB85E4EB185567ECAULL, 0x785F4C35366F19AEULL, 0x729EE12942012BC8ULL, 0xA6C28D27A3726851ULL, 
            0x572BE1DC4C873728ULL, 0xAD00D11DF58E9A69ULL, 0xE5A083AD57BC80B3ULL, 0x730D2CDBE1EB4C50ULL, 
            0x2F3B79EB00E3F7EEULL, 0x3C9FB391DFA22249ULL, 0x05239671D6F7BD41ULL, 0x6EF593757BC77881ULL, 
            0xACBF2208B88155DBULL, 0x3201EB57604F0A90ULL, 0x3FF6FC5FD6F3CB2DULL, 0x677D992DFB1B9F6CULL, 
            0x927DB9501DC57331ULL, 0x68D166DAA5043401ULL, 0x5B90988636B65CD3ULL, 0x78B6F0C4CE7F9DEBULL, 
            0x7F16787BFD14AFA2ULL, 0x85678206549540CBULL, 0x6DB027DF2AF9CD12ULL, 0xEF24811A7E615A24ULL
        },
        {
            0xA07E6DF662A8B8EBULL, 0x456A20FB71EB1511ULL, 0x9A4423090F6C77EEULL, 0xE5A8234585E5F715ULL, 
            0xB69F7505C15D0D5FULL, 0xA33E3882D77C3613ULL, 0x802FF7376F6167E5ULL, 0xA9E360CFEEBAAFBDULL, 
            0x222AF18E0D8EE30CULL, 0x22DB75DF19DBFFB8ULL, 0x5FF5F9206999FE18ULL, 0xE4E2BD65811D5828ULL, 
            0x72C9A578D9A9B4B8ULL, 0xC9CAB3A38641E541ULL, 0x0208113BF70F166BULL, 0x91EEC6870887E181ULL, 
            0x8511F316EDC9AA7AULL, 0x79D283C7D93AF4C0ULL, 0x09278F0E105835B3ULL, 0x841235F024325CD4ULL, 
            0x79E933F7640618D0ULL, 0xB4857335BCACC399ULL, 0x312FFD8A2F3EDE2CULL, 0xEC9FEB10C9691227ULL, 
            0xF136F73EED68814BULL, 0xD547E6DDB0144908ULL, 0xB9F460D8DD66FB15ULL, 0x7642ECE2477C5722ULL, 
            0x15AEF8A5FEB366ADULL, 0x4243AC425C3DC6EFULL, 0xA2FA1E8BA6EC3733ULL, 0xAAC946AAC9B10E7BULL
        }
    },
    {
        {
            0xE353FA621A900A1AULL, 0xAAB31CA7DBDCBB29ULL, 0xF970624AA8FB0CA6ULL, 0x8E3ABAC1BEB95D12ULL, 
            0x18702BCBF2DED2BBULL, 0x230E3728AB13210DULL, 0x142CCA2605909020ULL, 0xD45710A159FEABDCULL, 
            0xCF1B51A901D940C7ULL, 0xF7BAA43F96A67F5FULL, 0xC484D6227BA69EE4ULL, 0x4FF0E9B12DF6137CULL, 
            0x1ED7326F150E655DULL, 0x96337BE297C7822DULL, 0xE295D0DDCF4DDD45ULL, 0x47688D9E14106314ULL, 
            0x633ED57D4E388990ULL, 0x303FBBD3FFFD1B87ULL, 0x4984BA040822F90BULL, 0x736F75D0F526ADBBULL, 
            0x76B982E68CA649A8ULL, 0xDD15F28E7D9344EFULL, 0xE4638132F1805B50ULL, 0xE21CBD4EAC8A084AULL, 
            0xF800EE8A1AEC175BULL, 0x19151BEB4EEB785DULL, 0x1CC96FBAA0E4313BULL, 0x840CDE8F6C024D51ULL, 
            0xAF7BFE7DD4F5BB50ULL, 0xE904941F100DF2AFULL, 0x186B717EFCCA903AULL, 0xA444979801071B58ULL
        },
        {
            0x7EF7D72C0535B054ULL, 0x533B856465664D46ULL, 0xD8CAE81E98679AD0ULL, 0x4B4BCD89E3A4CB21ULL, 
            0x8784D00267954A5EULL, 0xB4BD9F17503B2C82ULL, 0x270A13A4C6E325E2ULL, 0x485EF86584F38ED0ULL, 
            0x7B2272644D72DA51ULL, 0xCAA6278DE58C0FA5ULL, 0xEE95031CEC3B4EEBULL, 0xE9E68369CB9BB91CULL, 
            0x64BF565AC714EDE3ULL, 0xCFCC22F8BBDDB545ULL, 0x76957AEADFC9D6BAULL, 0xDEFB8BAAEE08E73DULL, 
            0xC4BC56FE84F9D43BULL, 0x850A092C95E4441AULL, 0x98C3A6F9E3563280ULL, 0xFF3A670DB9E31F1FULL, 
            0x5B0EB93E7C84F94DULL, 0x939C151460C8DEDBULL, 0x5B7F0D796BA4463BULL, 0x04485AFFA8CCF2A2ULL, 
            0x94B6E056E4ADC970ULL, 0x0D004275A6AAE423ULL, 0x3A3FE50429276758ULL, 0x4E649D512AAF7BEEULL, 
            0x24D6FBEF57107EF5ULL, 0xC082E6ABCF58630AULL, 0xCFC7C77C768131D1ULL, 0x5E4F3FB7BC92F3E6ULL
        },
        {
            0x80D72277D4933CBEULL, 0x2E2344E7498C1698ULL, 0xBD07566EA0F4C998ULL, 0x8636020A45567B3EULL, 
            0x515CDD3DEB090148ULL, 0xF5F2E1EF2FDB9AB4ULL, 0x81CDB6D9DBCEB998ULL, 0x6D8D76DBC1606580ULL, 
            0xEDE614AB4080368CULL, 0x9F36B61800D20E86ULL, 0x3F371BF924A4C3E5ULL, 0x94D282AD7E4C1FF1ULL, 
            0x872BF5DD4A8E9358ULL, 0x832E3C089747C6EAULL, 0xE371AF10AB313842ULL, 0xFE33EFAD334465D1ULL, 
            0x2A2E743DD933F967ULL, 0x80B94D59ECE8188DULL, 0x9223B8A83DE3922EULL, 0x446E6D766A343D61ULL, 
            0xA5B142C14DD81447ULL, 0x14A4F222D60C93D9ULL, 0xF2224107F132AB32ULL, 0x09135674A1FEBD25ULL, 
            0x02D80ED80ADB140AULL, 0x6926174A404E66ACULL, 0xB8336FC4EE94C075ULL, 0xD25EFCFAF485CE6AULL, 
            0xE0DF75A4D33A7DE8ULL, 0x1C3AFA931FC87174ULL, 0x12A17435253C32C4ULL, 0xF3004694735C58E8ULL
        },
        {
            0x02A032E4475E5E22ULL, 0x3EDC405161E61D85ULL, 0xE0E431F5D58A6353ULL, 0x277E267F2BA9557DULL, 
            0x068BA88544A991A7ULL, 0x66D5D43F21E64E8FULL, 0x0F436D6FA3744880ULL, 0xDE8F8E65F78A9859ULL, 
            0x0B673810A5D6BB9BULL, 0x2C5187BB634875D5ULL, 0x915342E6F56BB1CDULL, 0xBFD7E03F32550373ULL, 
            0x577449D4396E3CDCULL, 0x3E8503EE4B4F9055ULL, 0xD31AC53DCABE4163ULL, 0xBB52B8612746AD94ULL, 
            0xDC3EF90DA6C78218ULL, 0x7A487C4E8A44602FULL, 0xF5BD4EC15C449E1DULL, 0xDF8F9170CA50F358ULL, 
            0x8F1039C1A972FCE1ULL, 0x04C44804D241B59FULL, 0x0987AAC0F5B63C7AULL, 0x5664662915FD3058ULL, 
            0x06FB0761A82F4967ULL, 0xDBDA3903291632AFULL, 0xDF33BA76CC53C9B7ULL, 0x2B749C1EFBC0D862ULL, 
            0x645E139318FCFA25ULL, 0xA77AF1C8EEB3A629ULL, 0x9B509597D8FD6158ULL, 0xF764091002C2BC30ULL
        },
        {
            0x0D23735BBB57DC47ULL, 0x6F24A4254DA70101ULL, 0x09EF2447A9E88AEAULL, 0x4EE33AE52B2434C1ULL, 
            0x2406D837D746F05FULL, 0x66F5E80386D4D543ULL, 0xF1ED99DBE0FDBB69ULL, 0x7919918954E9829FULL, 
            0x9ED5B94DC19484A5ULL, 0xE6BF74B07928A705ULL, 0x9696D15E4CDE0070ULL, 0x795592C317C7B592ULL, 
            0x63DA273E620FC0FAULL, 0x29CFC90E789238E7ULL, 0x4301207FDAF4230BULL, 0x158F5B1F0A16CA71ULL, 
            0x7BB4B4DEBF3DE2F4ULL, 0xDF1569395C96B14BULL, 0x5062232EF2BE33CBULL, 0xBF3C32E03EF7606DULL, 
            0x278D23023219269CULL, 0x1412D36BF9FA5A30ULL, 0x7E900795EB668ADCULL, 0xB45B29804FB5A306ULL, 
            0x689B4EB3C977ACFAULL, 0x9100D726A52E4D1BULL, 0x08B5FEA4B7B102C7ULL, 0xCA7FE723267915F2ULL, 
            0x5553F8260AC1C296ULL, 0xA8F2B85147D9BA9EULL, 0xE767A3D01A7A4219ULL, 0xDA43EABD9696BC00ULL
        },
        {
            0x27A28B37BD22F87DULL, 0xB850FBE2D3B06528ULL, 0x1962BB7F560F3524ULL, 0x094988AD43CB9877ULL, 
            0x8035529DD4F7D304ULL, 0x5918381C8E1BA3AEULL, 0x28C868395913E042ULL, 0x4F70CE247F60C88CULL, 
            0x8D2B14BB5DC29733ULL, 0x570128C471072657ULL, 0x4EF98876211C6C1BULL, 0xDF6CC69FD812E939ULL, 
            0x4CBEC20D6F0939A8ULL, 0xFF09D2F303B35905ULL, 0x10FD0A073B777AAFULL, 0x10C77B6C767F9862ULL, 
            0x80B30D968CC823FAULL, 0xE6DCF38279A09DF0ULL, 0x4D2282C13C67C813ULL, 0xB775CA0509A5541AULL, 
            0xC942600B301143A2ULL, 0x89B92B2A5F966370ULL, 0x677708BB9D7C2C4CULL, 0xD028AC791FA8E1F4ULL, 
            0x64D78C534F0D974CULL, 0xBD885C216E105EF4ULL, 0xE827E632F75A70C2ULL, 0xE9004D221EDD59E7ULL, 
            0x8CFF09193972F345ULL, 0x0708567AE8390D9AULL, 0x520F56AAF3F8B1DCULL, 0xCFE71755C898726CULL
        }
    },
    {
        {
            0x2C9FA93E7530F794ULL, 0xDB14563A3299EF97ULL, 0xEE4A32CCB4705A9DULL, 0xD5B2D709F4E223D1ULL, 
            0x8DF73526EEAAEE19ULL, 0x61C8C16EF8F6D154ULL, 0x8861481FA2D0DAD9ULL, 0x58D55222901D8090ULL, 
            0xCF315F5045CF06C2ULL, 0x4830EE91F805CBFEULL, 0x7FE88342E7B6FE31ULL, 0xC71EA3A5D5E37124ULL, 
            0x74B58CA0634CBDFFULL, 0x1CEF7A39A5197FB6ULL, 0x54A01E0F9C6483B6ULL, 0x1DDE0BE0DF693499ULL, 
            0xEFA9D82ED8326FA1ULL, 0x0E33E8AA7EB0D473ULL, 0xC93E46AE7B7E2494ULL, 0xE36373D58DD386B0ULL, 
            0x64E1E1C8BEFE24B3ULL, 0xF62E10502F68AE6CULL, 0x93483F5CC8CAAF77ULL, 0xA23407599E17C19EULL, 
            0x7AA9C84EF54EBAE0ULL, 0x88A181A300B3930EULL, 0x7EB08444E59D2008ULL, 0xF8593189D6CD9AABULL, 
            0xA48FB527A1E3BB6CULL, 0xE8D1AB2333ABCD60ULL, 0x8E1A4298224D82B7ULL, 0x9F3D43710DF849A9ULL
        },
        {
            0x4F73E5239C4ECA6EULL, 0xE50AC771DFF53E89ULL, 0x3E01D98DA31CFEDFULL, 0xF4D4009320C6624BULL, 
            0x22C7FF5D03F18A03ULL, 0x1C8DD2FBC9C0A588ULL, 0x728B964837F422AEULL, 0xFBE273817823D583ULL, 
            0xDC98246C9D753A11ULL, 0xB404DC91F9B4BD12ULL, 0x934E9711A4C41BF8ULL, 0xF23F7690B4832EB1ULL, 
            0xC1E02E4C55922AB4ULL, 0x96486F90CE1F929EULL, 0xECD45129C15BF200ULL, 0x1B36C1E691F2EF91ULL, 
            0x16A63BD1CCD0E950ULL, 0x7E0D2F91A9D7B500ULL, 0xAD982498587E319FULL, 0x9C3A47D641D2DC2FULL, 
            0x5B76F62C156D90B4ULL, 0x792A81C800FE94F5ULL, 0x3A54225ED19086B0ULL, 0xE36AAD0BD7008805ULL, 
            0xBA8CC379F7A72C5CULL, 0xF0897753B0B1A884ULL, 0x8C49CA18F1912A70ULL, 0xDB9EDE9CC831AED0ULL, 
            0x7E411EA8615B5C06ULL, 0x013CC66DDA5F8F4CULL, 0x48BCC8FA9389ED11ULL, 0x66A56AED64F0C969ULL
        },
        {
            0x848460CFD1ACFDA4ULL, 0x4630974E8E33F39DULL, 0x366D4312E41F0C88ULL, 0x0D0723146FB19BAAULL, 
            0x1BC4015FECC3BD45ULL, 0xB9A4597572C09BA1ULL, 0xAC33EE61E5404F93ULL, 0x52F40B4E9A866132ULL, 
            0x618276A1903CC387ULL, 0x75CA47DFB0707042ULL, 0xA35BA0EA1034AB1FULL, 0x0E9950BE5F952F1EULL, 
            0x01C7863E0FC129CFULL, 0xE3C1C4A9F58AF419ULL, 0x9EF1D0AE223B6AD0ULL, 0xC5227EA2F299CC91ULL, 
            0x79920E9A011366E8ULL, 0x369F1FAEE3043D97ULL, 0x11C2BBB378BDA90BULL, 0xB8DADC1D937E5F02ULL, 
            0x4FCF0BDC92BEA66FULL, 0x3CFD1AF436D1D2ABULL, 0x28317357EE61124AULL, 0x488CD6114008D21EULL, 
            0x413969630493CC1AULL, 0x74D1D6043B9A2D56ULL, 0xA16111DF48704376ULL, 0xAC4FDCD966856B10ULL, 
            0x8F6B5479588E11A2ULL, 0xCB342422A50BBDE0ULL, 0x79980A77555CDB8EULL, 0xE14938219D51F8F4ULL
        },
        {
            0x51682ED37B817D69ULL, 0xB5D30D8ECEB5809DULL, 0x06941657D6C49617ULL, 0xF5CC315754A7AD14ULL, 
            0xB66270619DD7A88EULL, 0x6601EF5892C76701ULL, 0xDBAF13DFCD9B2B8EULL, 0x6B71A93BE18DE635ULL, 
            0xD88BBEF93E8DAD82ULL, 0x8D05C3E6CF512BE2ULL, 0x5777B7F42EBD358BULL, 0x16859F2A1744AD6BULL, 
            0xCABB928F87DD76BFULL, 0xFE9FF467B597047DULL, 0x80F03CE440CAE814ULL, 0xABA3F2B80485E066ULL, 
            0x88FDE0DF6F0D8543ULL, 0xECA9B05332322609ULL, 0x5BFAC5DB2BD12067ULL, 0x780D78BE6E064579ULL, 
            0x86D9F9F3810087C3ULL, 0x1D6D4F416C90D2FDULL, 0x505907CDD594A743ULL, 0x1F0C2DA196B3EF40ULL, 
            0x75D59B0A19102CC8ULL, 0x7CB69D1E806611E0ULL, 0xEC71854BCA6F3491ULL, 0x53DC37ED73676F9EULL, 
            0x0B84D358736FFC40ULL, 0xA42A6727767C943FULL, 0x2D4D2B851A218F9FULL, 0xE94E316F894D767CULL
        },
        {
            0xD31FD3053C26C476ULL, 0x24EF1CEA9495DFF9ULL, 0x4C30FEB434FE4F5DULL, 0xA4E7642ADA624AB3ULL, 
            0x0AA47982DEE5C8F5ULL, 0x00D2A2A3D113BA49ULL, 0x40E665D03EA60759ULL, 0x48AAA8457158A5CCULL, 
            0x3CD8CDDEE5C1630AULL, 0xF4375E178AD8E5FDULL, 0xCFED68044EE72722ULL, 0xDE46A6534ABA98AFULL, 
            0x6F51382286E61F16ULL, 0x1A41173701BDC5D8ULL, 0x0D42975E988B8528ULL, 0x25C102ECEACC82F7ULL, 
            0x51E936D8C3B63F64ULL, 0xDDE1D6F611B215E3ULL, 0xC5B42A98158B4690ULL, 0x97CAEA75E4065103ULL, 
            0x5501CC249A858EB0ULL, 0xDC8FE66EBF7967BAULL, 0x1A1C933790C9E85AULL, 0x74D59C972C1EFFC1ULL, 
            0x40529CC3907E619EULL, 0x6651868135E75F8FULL, 0x485F3C7A7AF0B46AULL, 0xBD5E72CDDAD2986AULL, 
            0xA8CD6E9339E7D4ACULL, 0x0397E8605C4AFD0FULL, 0x19E6B424E8428000ULL, 0xA5EE187DDF54CBF2ULL
        },
        {
            0x7DD697E06596CB26ULL, 0x64EBC922D4251DDAULL, 0x9E4A6A690BD59D91ULL, 0xBEAA86494E15386AULL, 
            0x89D235B43107AAD5ULL, 0x417E75BE0D34632AULL, 0x49EE495CC5315A6BULL, 0x8093A512A7E4A019ULL, 
            0xC6180C6BC66884D2ULL, 0xA22887CE339790EDULL, 0x82A06931B30A96A4ULL, 0x7EEF7517F8604F6AULL, 
            0x8845DA07DDEC12ABULL, 0xE85EADB2D0DA9ED4ULL, 0x012AA83FB6181D30ULL, 0xCE37A14BF68DDC74ULL, 
            0x62018584E66E152EULL, 0xD6224E2C3BC80244ULL, 0x32B712A6652D3053ULL, 0x028FA7F6B9345849ULL, 
            0xF493818269347CC5ULL, 0x9AEF387C6BC4834DULL, 0x5E46D1B8E033268BULL, 0xCEE5882411340DCEULL, 
            0x5EAF85125B01A030ULL, 0x7FD6AD68C8208C02ULL, 0xAC0A4ED0A602C692ULL, 0x5404F17D8A6DE1B8ULL, 
            0x2CB2DAA3437123E8ULL, 0x552BAFAA438D60BBULL, 0x008F739FF138A699ULL, 0xCB2ADA0E0BF1FF24ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseCConstants = {
    0x63F0FA5880DBDD45ULL,
    0xF1A6EAEC4B039573ULL,
    0x2B764DA873E5C537ULL,
    0x63F0FA5880DBDD45ULL,
    0xF1A6EAEC4B039573ULL,
    0x2B764DA873E5C537ULL,
    0x1383C529D30B81AFULL,
    0x26FAAE33BCBCBAE6ULL,
    0xE6,
    0x1C,
    0x4A,
    0x96,
    0x51,
    0xAE,
    0x05,
    0x1F
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseDSalts = {
    {
        {
            0x330F5458FA6932C8ULL, 0xA7AB993C6E23DFBAULL, 0x2D473228888B3941ULL, 0x2B5EAC1CD87E221BULL, 
            0x14D2A07040587C3DULL, 0x67290EE81BCE878AULL, 0x3D6D05B0FB8BF6D1ULL, 0xE277584B873E10D8ULL, 
            0x34C200F4B1B63C5FULL, 0x229013A8E4BF45D0ULL, 0x099F77C15CE4B9D4ULL, 0xF776153E00D8093CULL, 
            0xBB6A2E328EB588C2ULL, 0xF6F525D8DA6681FFULL, 0x3ECF3E8C1C0FB6B4ULL, 0x354DC66E1CD74FB7ULL, 
            0xCFD434C8F3347189ULL, 0x74D3F6A4BDEF5014ULL, 0xAF333560C2D334ACULL, 0xD06AFCA526924868ULL, 
            0xA89CF878848C0FD3ULL, 0xAAC29D691F74859FULL, 0x267BB51E8291C731ULL, 0x0F1A914F24D9C558ULL, 
            0x755537F32DC1E727ULL, 0x5B329E4DE4EBDA58ULL, 0x1A3071E00F709F04ULL, 0x146018E18D00765EULL, 
            0xFFF2D94E10A12192ULL, 0xE3C3B8FA3C0F9D9EULL, 0x0AFD19B199800CE6ULL, 0xF18E403FD64347ABULL
        },
        {
            0x0C86BCBE2FD71B43ULL, 0x7A86B302D099AE3FULL, 0x5FE3C3A587B67956ULL, 0x9C504E32CD7D948DULL, 
            0x986D5432B5C42BD2ULL, 0x503A231C1CCEAEDAULL, 0x7776FAD63D60C245ULL, 0xECFBCE8FD2D9CE15ULL, 
            0x0C03073F8517BEDAULL, 0x7E8C63BB8B8E50D0ULL, 0x054FB0FDC7E551F4ULL, 0x8552757692B34B59ULL, 
            0x286DE3EA63A9B9FDULL, 0x6A26060AFB51EEABULL, 0x529A0456EDC9BCFEULL, 0xAD765D3C625E3FD7ULL, 
            0x66D2B13042AD7FCAULL, 0x422C293159B80E6DULL, 0xDEC5CDF799BB8EA8ULL, 0x9A2A7D038A9FB832ULL, 
            0xCFB637C9222AFA70ULL, 0x465BCFF64E16EF76ULL, 0x176A7E1F1AB964A4ULL, 0x0130457687763812ULL, 
            0x2ECB0F8382E05D92ULL, 0x048858D990F75977ULL, 0xA1116A02F77F67A6ULL, 0xFCC1B18ED29AD5FDULL, 
            0xCC0919C2213E8E56ULL, 0xABAB50586DFFB328ULL, 0x0F9B50C6AEDEEE4AULL, 0x5776B73C09DB125FULL
        },
        {
            0xF8D1DDD4DC0727B0ULL, 0xFD68F342AC7F733EULL, 0xAA6D43CEBF731AF8ULL, 0x43D245C079F8601DULL, 
            0xBB67C79635A94D3FULL, 0x2D3FC9E13949EA96ULL, 0x0DA5E1B39309C06BULL, 0xF3B18537CF8DEFD2ULL, 
            0xCC61951124E07DEAULL, 0xA6C8ABB39368D7CBULL, 0xFE5F4CD5C3BDD393ULL, 0xDEA270AF4E434D65ULL, 
            0xADB48FAFDF60289BULL, 0x7DE0A4EDE2882EE8ULL, 0x2914916D0D2CCC81ULL, 0x9AD26DE8622C4125ULL, 
            0xEB2C0C8CA6D92DB7ULL, 0xCE1234336D1EC5CEULL, 0xDDCBBF6DA8A2EF4EULL, 0x64268135913593CDULL, 
            0xDEADA8A2B586EDDCULL, 0xEAC6465356B2CF8EULL, 0x063F336ED1A229EEULL, 0x842434043981DAD2ULL, 
            0x8212BDA89C99F8E2ULL, 0x473003D8B34530C9ULL, 0x4BB362F20E69C21BULL, 0x60061FA4CF2B108BULL, 
            0xCBDBE22D4EDBD791ULL, 0xAA273C36820364D1ULL, 0xDDAD5B206607F0C2ULL, 0xBADA8B7EC662703BULL
        },
        {
            0xA7E03912097F9E0EULL, 0xB01D409144D67760ULL, 0xADE1934F7450DADDULL, 0x28883C0B249730BBULL, 
            0x7B5F77D532E2B4C0ULL, 0x65BC93F56D77990EULL, 0x431F101771A04CA8ULL, 0x566FD2D42E977555ULL, 
            0xF246DBFBC61D2555ULL, 0xC6679748B246BC3BULL, 0xB455795650C061AEULL, 0xD5AE4E0D3D9E8997ULL, 
            0x2E1E7BB72C9AFB5CULL, 0xA4F34BF7A18C0863ULL, 0x469380B43FE7AD6BULL, 0xE3478A87BB375541ULL, 
            0x625A3A08C7569E17ULL, 0x05FBCB6B7ED78A72ULL, 0xE1F94E8A1178FE55ULL, 0x68AD086FB14A06FEULL, 
            0xEB1D748DB9CF7988ULL, 0x69B7AB4073652CEEULL, 0xE4DCFB62EDAD8FE9ULL, 0x3E6EB51468C6C141ULL, 
            0x13297576E3A078C8ULL, 0x076821F51702D192ULL, 0xF6057C31C35454EDULL, 0x62B69E68C23498BDULL, 
            0x611C000CE69AB301ULL, 0xD7747F992D30697EULL, 0xCDADF23912898998ULL, 0xB2C25C346D627AA6ULL
        },
        {
            0x63684F2E4AB9F276ULL, 0x2D8915A049B57E7BULL, 0x3D8F430CD6544A23ULL, 0xE485A03AFB3E1F9AULL, 
            0xF95882E60CD772C2ULL, 0xE682C71DABA6216DULL, 0x0C82E130B3EE63A5ULL, 0xAE8E9F0A4F9659BDULL, 
            0x154AEB85568CC5B9ULL, 0xF5775DB536A2F1A3ULL, 0x27C2C4D1F4032CB2ULL, 0xD57E8124226F4EE6ULL, 
            0xAE100E7B10BCD298ULL, 0x93DAEE00DF2C39B6ULL, 0xAE7372ECAF33B17AULL, 0x8B94A63138D0A1AAULL, 
            0x429CAC730ADCD693ULL, 0xB70699EF0CA568ACULL, 0x580EF7E1DC6CAD20ULL, 0xA6CC373BD6CD4FA3ULL, 
            0xB47D4F6C3F870938ULL, 0x8BCEFFCD07D771F6ULL, 0x0168C19A3724C517ULL, 0x2B0FF13E9554169DULL, 
            0x41B3BFE0E3F80873ULL, 0xE7643B7A37566FABULL, 0xC0E6F3A08043EE7BULL, 0xB138843B5970A929ULL, 
            0x727B2C514E0B842AULL, 0x152A277C7682D8ECULL, 0x72B4C0783C2A5193ULL, 0x69E52EDB63891B38ULL
        },
        {
            0x82B4AA7A98F44342ULL, 0x43041B8610314B7CULL, 0x71E66256E21B7932ULL, 0xA10CFC9A17FF7F02ULL, 
            0x27880550BE945181ULL, 0xCA957996309CD4A1ULL, 0xEFC7C9EF7D41949CULL, 0x4E1E5D326ED7FBC2ULL, 
            0x6077BE117F9FA413ULL, 0x55801B2E6E18E7A7ULL, 0x88EAE0C70A6DE30BULL, 0xDA016932BC982697ULL, 
            0xB9A8B4E019D615E4ULL, 0x8DFE77AB8D54E58AULL, 0x637A903767ED966BULL, 0xFD120B6FD4ADF4F0ULL, 
            0xCB1B2D1DD0CE3F69ULL, 0x69EC59CE79134099ULL, 0x33E2C45634B0BA44ULL, 0x71C4C5DD376647D0ULL, 
            0xD246523966EF76FBULL, 0xE81777A4120034DBULL, 0x2460E0F7BEE38DCFULL, 0x7ABAB433D6E1E592ULL, 
            0xCEC91C42378AB298ULL, 0x244251ECC870AB6AULL, 0x80764024083A60FDULL, 0xA998BF0D3071B37FULL, 
            0xDA8E9CC65C7CA776ULL, 0x4578601E3AB1EB7AULL, 0x06347E431A8B891BULL, 0x0E5820A6A955A620ULL
        }
    },
    {
        {
            0x6FBCAB76CACBA2AFULL, 0x8E9643FD79E8B36AULL, 0xE1C013844BBF1D7DULL, 0x231F6F0DCDDCCC6BULL, 
            0xB5AAEAE79713F7ABULL, 0x5C908856D20C68A8ULL, 0xFD69B9FA4C8F4395ULL, 0x8EE43997FCD3BBF2ULL, 
            0x649E02241738092DULL, 0xD8ABFC59B7C2E412ULL, 0xB6703A6860AC96F6ULL, 0x34439E85847505C1ULL, 
            0x034EE22CE54CD8C8ULL, 0xE276FA8DF609A81FULL, 0x524EAE6758B86B62ULL, 0xE2EDCB9FE9A8C177ULL, 
            0xDBBA5CEBE9BDCB8BULL, 0x3C7DC8890311A3B5ULL, 0xEEF2D7DB2EEF33AAULL, 0xD1FD04774D77EE6FULL, 
            0x578C54F607451CC3ULL, 0x363620D6305094DAULL, 0x0BBA23F0790C7300ULL, 0x5F5E47EBB53AF88CULL, 
            0xB6E7D14AB575144FULL, 0xA1B52D839A6976A8ULL, 0x214FCE1A63CFA10DULL, 0x066633253135519CULL, 
            0x6496BD80DD6EB279ULL, 0x2DCC8E0CC8D0DDB9ULL, 0xBB48C307062FEF52ULL, 0x4BD6B4818631E677ULL
        },
        {
            0xEE6D964FB2F42E27ULL, 0xB57E2D755CC7A661ULL, 0x8C53067819B63CF9ULL, 0xCF10835367625E86ULL, 
            0x3470F189F63B3FA6ULL, 0x9C295C5B6A9785D4ULL, 0x0D82F19AAFE5A210ULL, 0x4D01AFB9E053D74AULL, 
            0xABBEE5D97900AA7BULL, 0xE4CE75695C506F86ULL, 0xB3BECB6C59F13814ULL, 0xA18A77ACC99E9491ULL, 
            0xF178D1930AA021CFULL, 0x19453F3B44518755ULL, 0xF63BF14BDF9D9964ULL, 0x47199CA26BECC0CEULL, 
            0x6679AC9F3B76D05DULL, 0x4006AACB2909EBA8ULL, 0xF2247BD65B999D6AULL, 0x1BB73BC9C5280D68ULL, 
            0xD0D203E91B056275ULL, 0xB37B953C71CFE793ULL, 0xD3F99E73B74DFED4ULL, 0x2622C6BD74DD4EE0ULL, 
            0x5DE221FF972CB429ULL, 0x8C16CF780673D469ULL, 0xAF072B045FF2A705ULL, 0xCC2755EB1772F240ULL, 
            0x72CF61F21BD8A3B7ULL, 0xA595869E26620144ULL, 0x450600511043B665ULL, 0xEFB3AFEB513F2198ULL
        },
        {
            0x28E92000B4BCEF31ULL, 0x5ECE70A342B2156FULL, 0x48AF0D3A3F8CDB61ULL, 0x8EE6A464103E4D36ULL, 
            0x53F6315C966F0689ULL, 0x888F50491B0C2192ULL, 0xC892652E802B65F1ULL, 0x95169AAFFCF0E4ADULL, 
            0x0680486036C22C12ULL, 0x4E462517F83BA952ULL, 0x6C18CB2D5D49BFB2ULL, 0x8D8E24DBC5000885ULL, 
            0x6FA01F00C18E66D7ULL, 0xEC40D0A25A7FA5CAULL, 0x48177F630E4906F6ULL, 0x7CDA329F50A41DE7ULL, 
            0x09E46E0F4030F9C2ULL, 0x65EEC8DDBD116912ULL, 0x6EB72E314B60DE93ULL, 0x7A4DE7045415AF89ULL, 
            0xF2EF59852D7178E8ULL, 0x8C42DD1218CD9DFEULL, 0x6FF4489C4A322C33ULL, 0xB5BCF46EB38994DAULL, 
            0x7BFB61AEDFB7994FULL, 0x533898AE3F041015ULL, 0x59B15C9B09098F72ULL, 0x6BCFBD3D18AEFF5FULL, 
            0xCE7FA2C4CD734909ULL, 0x7D511BD8F4B0D07EULL, 0xC716670C1BE13C17ULL, 0x18D5180F6A7A79EBULL
        },
        {
            0xB9A27491236111D8ULL, 0x8F7760B6EABDAB5DULL, 0x0C6E1CBC005DCEBDULL, 0x1CC1B064E5A1E499ULL, 
            0x6D549499205DC817ULL, 0x07708C0260B99727ULL, 0x5C09BB0650B8DC3EULL, 0xED394D48075B7D95ULL, 
            0x8A49F89ED7BAF4D2ULL, 0xC8856B3920E8F36CULL, 0x2305FAA35E8E0764ULL, 0x27B4250CBAA0A36AULL, 
            0x1CFD74D35EBEE700ULL, 0xEA2D1B6D26D6FA6AULL, 0x89F4B6F83342A7ADULL, 0x1D921060E3FF9D69ULL, 
            0xEB0EDCA7AB3BC41DULL, 0x63CE993D027083F6ULL, 0xD0B3603FAE7CDA48ULL, 0xD8B0BA8368C003BCULL, 
            0x3EEDDE710BF764F4ULL, 0x5E1A198708D6885AULL, 0xA38678236936753AULL, 0xEB63A0467C12F02BULL, 
            0x25E3659659E39459ULL, 0xB7993E3CAB9F41B2ULL, 0x2E1AF3865F69ACB2ULL, 0x32B208E85DABA524ULL, 
            0x3AE80DD6C1869667ULL, 0xB573E36ABC3F3BDEULL, 0x0BF1569ED50487B6ULL, 0x8D88D9BB3F0E08A3ULL
        },
        {
            0x6B9333FD121C71E2ULL, 0x4B8A9BA8AA7572E1ULL, 0x3EEC1FF9C7A20FD2ULL, 0xE7053B17B4714550ULL, 
            0xF9E88E78663F8A60ULL, 0xAF1655582C42942AULL, 0xBF8FBF79310F4557ULL, 0x8EBC0A75E7377F5AULL, 
            0x34DD4C5FBDFCB02BULL, 0x38241B8FDA9537FBULL, 0xD6248664E848E4B3ULL, 0x9AC99EB555F739FEULL, 
            0x5EEADF25B9A79389ULL, 0xD7AB6B443CA15E7AULL, 0xBFE7C09E090E4195ULL, 0xF401453409F37F20ULL, 
            0xB271FBE9EA252C75ULL, 0x61D107260D6F72E9ULL, 0xF8E7229AF661AEDEULL, 0x228E210182A069ECULL, 
            0x5F330258321C6B10ULL, 0x9C4FE56250111600ULL, 0x5FB0AEBB934A592CULL, 0x85726E05985F3740ULL, 
            0x9BC6C8C5A1120D12ULL, 0x4AD31C0B5CC85EADULL, 0x7D986683BE84F68DULL, 0x1B46783E8A8279CCULL, 
            0x5B88675FD659B410ULL, 0x17EEA94AA17150F2ULL, 0xF008C5C0144A47C5ULL, 0x00F22DE710590D53ULL
        },
        {
            0x914D82A906074A43ULL, 0xD0B5F36A776DDA85ULL, 0x9B93EEB50CD9C660ULL, 0xA432B9C292EEC809ULL, 
            0x2DA968C9050337C2ULL, 0x7477762917650FA5ULL, 0xF8B3B554EAC4A32FULL, 0x493AFF226B8ADF90ULL, 
            0xBF2A9357EBB69E05ULL, 0x15563246D7A17C99ULL, 0x44A28B364D2D3F3DULL, 0x3BC25FC4DCE83F88ULL, 
            0x67FDB9201353DE8AULL, 0x63DC9A00EA42B9ABULL, 0x7ADC2235F43D5480ULL, 0x29959C16BB116D19ULL, 
            0x7DAFC3F144855E94ULL, 0xA812869270AB5D06ULL, 0x8D997F2B8C60F80BULL, 0x05DC7766031A464FULL, 
            0x551025D866B6D434ULL, 0x3D8164BC89358E25ULL, 0x0CE06F1D6B52F270ULL, 0x65C0D7FDF7F293CCULL, 
            0xAB7201A4859B46DAULL, 0x07D7EF13044E164BULL, 0x1E2BCF6153B7DF17ULL, 0x8084578A49B4D9F3ULL, 
            0xBC12B51B8D2A5B1FULL, 0x3F669D5352E27E85ULL, 0x248AFD1862463200ULL, 0x9066D55C293AF826ULL
        }
    },
    {
        {
            0xC964EDBC9DB9A9B5ULL, 0x32D0F461F08AA4C8ULL, 0xD9D155CB95E6BA70ULL, 0x46B5BFED9DD034DDULL, 
            0x6AD33810037D6DD0ULL, 0x532DC6B2268866C4ULL, 0x716E63A951B76A5EULL, 0x35E95CBF569BEAC2ULL, 
            0x61B4EDD1C8689DD0ULL, 0x06380D32B8049032ULL, 0x3E2D6590F60AE18AULL, 0xE5021EFFAF07F883ULL, 
            0x50D1E1C1600D5731ULL, 0x3EF72C5AAA8490F3ULL, 0x019620CEDE86F864ULL, 0x2D321D9614627F27ULL, 
            0x72A936ECB101D06CULL, 0x1349D229F5FB4DF0ULL, 0xD2CADAF74212BEAAULL, 0xBCF15768FBC601F4ULL, 
            0x1498373D398AD1B2ULL, 0x0755A4BB28DAEF92ULL, 0x39EAE0DD654660D4ULL, 0xE4699E638CAE2E1BULL, 
            0x4D697F4E52675E24ULL, 0xDF34E78FCB176DAFULL, 0xBC163538059BC46AULL, 0x672799EC63BE60FAULL, 
            0x142BE9E6ACD6B6E3ULL, 0x4B224061A7CBC7A1ULL, 0x1B9177F651C2F32EULL, 0x9F08E4FD89C66A28ULL
        },
        {
            0x0F6C01B85E275F93ULL, 0xB928ECDE4188CC43ULL, 0x54510F0C32E5592BULL, 0xEB0CDA2189DCB6B2ULL, 
            0xF5CCFD887644860EULL, 0xFDFB33163C7CD846ULL, 0xE831970B5E87ADC0ULL, 0xAD6BB634149AE4BAULL, 
            0xF7EC3C42DACE3DF3ULL, 0xE600662D64B1EC67ULL, 0x4FFE4F400557DFD2ULL, 0x27751CFAE240C3E2ULL, 
            0x96C592320A8CC901ULL, 0x06384A13B0684B9AULL, 0x0C292990AB2A5354ULL, 0x755DA9366D6EBDB4ULL, 
            0x66C20DF0D5B0439DULL, 0x17299A7556BD1224ULL, 0x6C5C91E1854FCD9DULL, 0x0FBE9405E5C3AE30ULL, 
            0x5279A1FC94DB5ADFULL, 0x820E879FE3D84E65ULL, 0xB88C9DBB272445D3ULL, 0x56848744AFE6A6B6ULL, 
            0x1C6F99082B486EEAULL, 0xFCDB2ED0A8A29B55ULL, 0xFE589BDFA812120AULL, 0xA507DCBB7E508E9BULL, 
            0x4A2EF725317FF3C1ULL, 0xD597281BE01DF92EULL, 0x4B50D93B96557451ULL, 0x5FD9E4F11C43FACAULL
        },
        {
            0x7D387D6F052D3378ULL, 0x07EB7746C875E11AULL, 0x602AA85A5C47859EULL, 0x1348FF956DEB656CULL, 
            0x2B81B55950773EC4ULL, 0x5088B1FF96A44834ULL, 0x7F367E1699FBBD9DULL, 0x0FD3E430DB70809AULL, 
            0x4808DE9F514C7063ULL, 0x1978324036E614C4ULL, 0xDFC8C053A278D664ULL, 0xEA0A70B0AC61EFBEULL, 
            0xF0707AF3685DEDF6ULL, 0xF7C303EAA112FC7DULL, 0x6FD53C0095256328ULL, 0xF6F2D333ED11FC6AULL, 
            0x25E1BAF82DFB9944ULL, 0x16E9276D66A61A8DULL, 0xA14CFA79BE2CA3A7ULL, 0x33F0F3B387624429ULL, 
            0xEAE90D380D16A945ULL, 0x5684834D4E9C8FB3ULL, 0x8536F44179AF969EULL, 0x762932A0CAD18F45ULL, 
            0xE17261A3F95A6B35ULL, 0x178D3601B6578AC3ULL, 0x892F3A64EBD47BEEULL, 0x71CF33BB18E10EECULL, 
            0xF955589C43E6F806ULL, 0xA9F73A83419B1DB2ULL, 0xA9A5E68E46824769ULL, 0xAA0862DE317A6AE8ULL
        },
        {
            0x1FE9184E1D3B2E50ULL, 0x8DC164ED20A09E6FULL, 0x3B71726149DA7D12ULL, 0x68C8C7CEC6045B96ULL, 
            0x6A8C0283BFA795C1ULL, 0xFF0B5792FE774836ULL, 0x43E001DCB41ACF92ULL, 0x5927A0A497A9FABCULL, 
            0xCA655979AF06BD2AULL, 0x8FB1D09E2B967F26ULL, 0xD158938B0B66FA1FULL, 0xAFB6CBB8275275A1ULL, 
            0x6D6C4C79F502E870ULL, 0xE7CC7055BA0A41D8ULL, 0xCFD9FCE3EA62EE73ULL, 0xC370118F08F9F2B4ULL, 
            0x16257EF3812F0D49ULL, 0x8D2F77CC75EB4C30ULL, 0x7CC5508AB89452F2ULL, 0x9E1B701CC1E8AE6AULL, 
            0x2A6B463616C4792FULL, 0x34BAB22550D12379ULL, 0x8726E8375688161AULL, 0x8A2B6995EEDB7E92ULL, 
            0x570DE7E1E1C502B2ULL, 0xAF94677062CD3A64ULL, 0xC6E8D5606DAAB3F4ULL, 0x90324DF93F922E14ULL, 
            0xDAAECB70D3CDDDE8ULL, 0x46472E417BD0B9A3ULL, 0xCBA0F419126D8460ULL, 0x078E00EE2D0FA2B4ULL
        },
        {
            0x774810743A62CF00ULL, 0xF4BFEB899BDEB1C0ULL, 0x05ACA377833523A7ULL, 0x4F17F498E2AE251EULL, 
            0x4DF0C706A4440DD1ULL, 0xFDDC990709FE0988ULL, 0x02223DCB09BACD17ULL, 0xC2B1987DF8D69E7DULL, 
            0x4F6BE6431E739D8DULL, 0xFB77010966CC0373ULL, 0x4807091AEFA4FA98ULL, 0xE3BA6ABAD3D56BFBULL, 
            0xA73C5A499130233EULL, 0xD8D2D678B208A010ULL, 0x490C661E0905697BULL, 0xC9B730577CB74D45ULL, 
            0xC03C0F38564ADB0FULL, 0x0B86E9ED05726FF6ULL, 0xD333015C660894F4ULL, 0x4137BF4B56E943CEULL, 
            0xF634FC5554605F90ULL, 0x1DF9EBCBE855E483ULL, 0x8DB719535B469569ULL, 0x638D11C047ED2267ULL, 
            0xBC01F14EB0FA2646ULL, 0xD2AD43B20C44C2FFULL, 0xBE4F70C8155661C1ULL, 0xAC7443BB42B46EBEULL, 
            0xBA81D2E5928482AAULL, 0xB40EDE8D195D16F7ULL, 0x3EF6CC99ED37FEF4ULL, 0x5BC55ABA3D1FC3BFULL
        },
        {
            0x11AD2D1DE5525EC5ULL, 0x6548173AB2FC1932ULL, 0x35F5765BC1C73EF7ULL, 0x4F6359D272DD886DULL, 
            0x889A5FF8756ECA15ULL, 0x7AA77502D16CBA33ULL, 0xFFE6750EB6AC94A9ULL, 0x92AE65E6C7C09588ULL, 
            0xDE4D3C609CDD26C1ULL, 0x80D99C434DAB2166ULL, 0xA3E11B105EFA362CULL, 0x3494CB518554579FULL, 
            0xF0774CD8D1DE823EULL, 0x4F3ABABE909FB0ADULL, 0xD3BAE215F1E80C96ULL, 0x2B6C14FA3D8C5A3EULL, 
            0x6E16D9971ADEA41FULL, 0x2F0EB787BE9430CDULL, 0xC6346839EB147235ULL, 0xE4555329B2639A74ULL, 
            0x787F31BAF4A2939EULL, 0xC95E50BD3928DD8CULL, 0xE1AB3004B157A7EFULL, 0x33F71170709B01BDULL, 
            0xB11F9E1DF5D9E5A8ULL, 0x4AB39DA85736952DULL, 0xBF19F4315B55E1FBULL, 0x6A30DBA16254E6A0ULL, 
            0xFE71993BACA9C3E5ULL, 0xDA4C3856D8A50627ULL, 0x6F1696AEC3C1795CULL, 0xAC476BD3A06FFE11ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseDConstants = {
    0xBE2DB33F9A6CCFF3ULL,
    0xBB063D9142DFED20ULL,
    0xAF01E04AD5E40A53ULL,
    0xBE2DB33F9A6CCFF3ULL,
    0xBB063D9142DFED20ULL,
    0xAF01E04AD5E40A53ULL,
    0xC0A1C1E6BD6BF58BULL,
    0xCB2E4726325A870AULL,
    0x0B,
    0x69,
    0xE3,
    0x1E,
    0x85,
    0x2C,
    0x0F,
    0xF7
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseESalts = {
    {
        {
            0x82986FBEFAA1FB06ULL, 0x35C3D1A61146AF31ULL, 0x6AC1B552F5B75571ULL, 0x966BF0FA515F070CULL, 
            0x87893158E351C57BULL, 0x787CA37B9C6B43DFULL, 0xD0C36021A0CEFD9DULL, 0x9BBDE834396294A2ULL, 
            0x65F26CE3BE2E8C89ULL, 0xE28CFCFDBFA09F29ULL, 0xDB83D046615CC503ULL, 0x381CAAC5E2B4AD47ULL, 
            0xF5119699E3248F79ULL, 0xAE35EADF0EB91C6CULL, 0x051308CF32FF7FF6ULL, 0x5052BF4BADCD4EACULL, 
            0xC97FD1DA35A751F9ULL, 0x4148C8830E998980ULL, 0x41D7D8A3897E87C1ULL, 0x2E4E8D30A1E4C48BULL, 
            0x8488F3332A2B6446ULL, 0x4C3BC5480A754B11ULL, 0xBF3CDC71938BCE12ULL, 0x1016673547548742ULL, 
            0x7649F2F4EED2E272ULL, 0x7242C56015861966ULL, 0x71EC6FD5F14E92FAULL, 0xFA77A09F45F4BACDULL, 
            0x9CF0CDC9A6B8DC78ULL, 0xE33AED954677E2C6ULL, 0xE17CEBC55B7ABE1BULL, 0xAE3DCA0225D65139ULL
        },
        {
            0xBB170A5019F48668ULL, 0xA0F1FD1112CC511DULL, 0x10B926C0A98FB94DULL, 0x0FB4FF18F3CFFB4BULL, 
            0x0079909757440C47ULL, 0x6F31109B79F06209ULL, 0x9B4B7AF4CB771BD4ULL, 0x054360CBC93A9F2AULL, 
            0x55479FD85304392DULL, 0xA050087A745E4C91ULL, 0x3D8D495D64A2DE5CULL, 0xC6A0660A98E6C51EULL, 
            0x7A3D0944E4EF9637ULL, 0xB68E5C02C9FD6D9BULL, 0x22B08EF332E7F861ULL, 0x4DF9ACDC7D9F282DULL, 
            0xC14C1A9C3DBDAA9DULL, 0xA2896F3E78F4022BULL, 0x297D3EA76E3C354BULL, 0x741867CAED402382ULL, 
            0x7048D07978446BC8ULL, 0x48083EB6BA6C3FD0ULL, 0x14107F95B426DF0DULL, 0x445EB8CAC5DCC076ULL, 
            0x95B13ED95F5B40A4ULL, 0x8E7C15EC06DB7961ULL, 0xB264EBC15B9BB18CULL, 0x5495FF6B32990097ULL, 
            0xF7127C5EDAA7FD42ULL, 0x6C0281992D80300AULL, 0xC9F8125F919A1181ULL, 0xAFCC81E73011E4D3ULL
        },
        {
            0x7628B7BF2F46A9A8ULL, 0xA36A13E09B3669C6ULL, 0xDA1334B9ED7F80FBULL, 0x33FD14C55045C568ULL, 
            0x6ECAE465D72ECF16ULL, 0x505C895D1675D72DULL, 0x5EF2A69E671F93A4ULL, 0xDE879EB27ED47CF8ULL, 
            0xC2A285870A9FBF12ULL, 0xECFB2A14B7B23E2DULL, 0x369D60685466ABABULL, 0x82A0AC21417B7E5EULL, 
            0xCDF73CEBAE1AD739ULL, 0xBB4A3603A41A3AAFULL, 0x118AECBAA48A0EB8ULL, 0x37F8A55BD9E5F25CULL, 
            0xED64715A699A05E0ULL, 0x07C07C7F03CDC7EFULL, 0xC01DFBB927FA4766ULL, 0xD9F2ACD0053E3D0BULL, 
            0x721665F1E373FEA2ULL, 0x1D3AEE7694526BC1ULL, 0x544576B5C7DC5143ULL, 0xB189B78A8EA0C1BFULL, 
            0x0264635C11B80519ULL, 0x1B797D8EFD06FBD0ULL, 0x25C06799ED9E23ACULL, 0xC65ED7A5274403FDULL, 
            0x3879738BBAF11DA0ULL, 0x55287F87623D843CULL, 0xC63ABFE2F9500D1FULL, 0x464A5E75E4901445ULL
        },
        {
            0xA58755376C0CA6A9ULL, 0x0F8F1518F6CE4C28ULL, 0xA3BE5D17FEBB2B5AULL, 0x1FF3DE38EBDED0DCULL, 
            0x6DB039C15F787658ULL, 0x23DB0EB1793842C2ULL, 0x14F69ADBE8BAFBC4ULL, 0xC7EF961C1450E43EULL, 
            0x196D841EC797D0DCULL, 0x838C9524A38D9509ULL, 0x29385A8787BEF759ULL, 0x8F1192A1C09C7DBDULL, 
            0xA369EE9EBD24D441ULL, 0x922C6B06DCBD0954ULL, 0xBCD9FAA48AC465CFULL, 0x146632A446DE8CA6ULL, 
            0x4344D2054AF543EEULL, 0xF2ADA06F9D358815ULL, 0xFBEB5C748EBD07AEULL, 0xB19D22E92545B1ABULL, 
            0xA1A1119A21375361ULL, 0x6A1ACA56BCC00A68ULL, 0xCE52BAFDC5189F08ULL, 0x9595F3D361CC399FULL, 
            0xD0794795C323B71CULL, 0xB3AD43E7CF892DACULL, 0xAF39704AB9296E70ULL, 0xF2F0E46B4234BE0DULL, 
            0xD42C7B7133D7292FULL, 0x2CA8FB9E9DB71457ULL, 0xA3B4481BD40CF5BCULL, 0xE2099BF87554E3A3ULL
        },
        {
            0x30E6CB5DDEDB043AULL, 0x3D475B7FA7107F57ULL, 0x7890A775577FC14EULL, 0x209ADBB136301A1CULL, 
            0xF6DE691BA9CE17BAULL, 0x18CD3DEF3DB1EEDFULL, 0xA901077896B14F43ULL, 0xE0CCD7B908AB9190ULL, 
            0x3998CAAAD672D8F7ULL, 0xC2F64BBAD226F08CULL, 0x8DD19227E626CEE5ULL, 0xBCFA5700177E5E2DULL, 
            0x202C0FB1431CCDD2ULL, 0xA625D62EE772DC4BULL, 0xF28F1EA12D7C6B19ULL, 0x0699F1655B73849CULL, 
            0x419FE56799B5D545ULL, 0xB33E97823EB204F2ULL, 0xE51E9EE30338120DULL, 0xEB7411CC7BA5E576ULL, 
            0x2C0B112225D77824ULL, 0xF47015C345C3F46EULL, 0x27000496E244C4EDULL, 0x34D312400CFA6E58ULL, 
            0xDDF55B7AD9790501ULL, 0xEF1433481FD32A8FULL, 0x11D17FFCD468ABBAULL, 0x5618750DFBCED96FULL, 
            0xF947F568A2E77F1DULL, 0x31C7CEF9F93EDFCBULL, 0xCB914B14A9A4E99DULL, 0xFB74F92CC05F3D1BULL
        },
        {
            0xD169FE09E2B33FBFULL, 0x40D0FCD16C137434ULL, 0x94AC0C0BE1ED2A1AULL, 0x5B9AEA663898A88DULL, 
            0xF46DE603D5C6887BULL, 0x0E3C1B84EF19411EULL, 0xE23860DE3CC3E932ULL, 0x313BD9D7501A9CDAULL, 
            0xB96C2DA64C702156ULL, 0xEB76AE9DB7BC6195ULL, 0x0D721223CF4FF2D6ULL, 0x3C5FC05EA33E6187ULL, 
            0x1F82B2E71116B966ULL, 0xD662E12C10388434ULL, 0x61C6592276CA4559ULL, 0x1D63BE6B6C1012ACULL, 
            0xD551CF16B7A2A034ULL, 0xB8F137C0428362B9ULL, 0x50B59BDEA0E42C08ULL, 0x4C264E0573AC080FULL, 
            0x67AFCBB8567F1A15ULL, 0xE0F85E5D49D69461ULL, 0x183EDB707CFF17C8ULL, 0x424189E372DB109EULL, 
            0x8E3A003BDD32A47DULL, 0xEB53859608221B59ULL, 0x0B3B528194AFCD6BULL, 0x995CE4F782AD5723ULL, 
            0x1E9E784DEC37E621ULL, 0xE84955172A629226ULL, 0x495356608D217752ULL, 0xF950DADC3842B0CBULL
        }
    },
    {
        {
            0x85ADE11370DA509EULL, 0x64365399923CF289ULL, 0x5B1CEB713DBBD6EBULL, 0x9A5166A443592309ULL, 
            0x81FB83FB18C666F0ULL, 0x41FB071EB940AE1BULL, 0x9A8B96031C9D437EULL, 0x788F9BB27887F783ULL, 
            0xA3ED3209D5442E75ULL, 0xD31A9D2A9807E5FDULL, 0x693D23F1000B0868ULL, 0xBE9651AFEAC340B2ULL, 
            0x0A21EA21BB3A4F74ULL, 0xDF045489C1FB59FDULL, 0x9823CDAEF3EFD7C7ULL, 0x0ABF59177AA098F5ULL, 
            0x10748C257646EA35ULL, 0xAEA00419FFF34436ULL, 0xD9B73B4D8081B36BULL, 0xA3DDBF474ACBBE24ULL, 
            0x6F01C35EB052E2BDULL, 0x5CCC1C3BFC5D4CCBULL, 0xF1A9FBE241B3E54FULL, 0x7EC8409B0CCEE4CEULL, 
            0xAFA197D8FA77FF9BULL, 0xEABDC84F8B882FADULL, 0x4087C49BF450F181ULL, 0xD5C8234FD035417FULL, 
            0x1008F4F93268CFEDULL, 0x9754C6D2DE7AFF6FULL, 0x754DF086DACC4D84ULL, 0xE25C797FFB09616FULL
        },
        {
            0xE987E2571B73BFCAULL, 0x012B7CB2ACC527D7ULL, 0x87BE4D360F1F0529ULL, 0xD418BA17CF60E3A9ULL, 
            0x855AD8BE5ABFB19CULL, 0xF86E4F5A5708055BULL, 0x2A9532566C9E9A7DULL, 0x93E3EDA7A240CD2DULL, 
            0xAD80B5651E375330ULL, 0xD8644E6BEE497662ULL, 0xE9709F1A1A28D63AULL, 0xFDBD7C52F27A94BFULL, 
            0x0E6085219F814BAFULL, 0x282D5D2AD0919BA5ULL, 0xEFE5A0571DBBE272ULL, 0xBF3C56679CF56765ULL, 
            0xEAB0D55FEA83DD01ULL, 0x8C178700B6555724ULL, 0x9B14A6EB1CD3A89EULL, 0x20300BD2834C555EULL, 
            0xEAFA366254096456ULL, 0x1316D9EF826B2625ULL, 0xA207368F53D38308ULL, 0x58A4B651A7ADCF3FULL, 
            0xA2A7FB64575B7636ULL, 0xC953C170F27B66B9ULL, 0x605113D4BE671DC1ULL, 0x886528F737BB2E7EULL, 
            0xC13A0E227DCC69D4ULL, 0x510B215CC17360FFULL, 0x43D41D0739D13BE2ULL, 0xA6CFE847F507A511ULL
        },
        {
            0x1E175B14CAB55416ULL, 0x03379CC1148EF6BEULL, 0x7A930AC906DF080EULL, 0x8E1EDE6CD57E2DE0ULL, 
            0x8CAD0A9D07F3D573ULL, 0xCD1A80000BDF1998ULL, 0x772520919C6F0BF4ULL, 0x3E4C5FED2FE71F5BULL, 
            0x22D138013779A30FULL, 0x73D0AD11317213FDULL, 0xFA02F89C9759C186ULL, 0x959F13564BFEBCF4ULL, 
            0xC8947E9BF46D8BEBULL, 0x921AF0A3D0456116ULL, 0xB3DF889EB0E4E719ULL, 0xAB6313A28946A490ULL, 
            0xDD705263B6414C11ULL, 0x4432C39476C2710EULL, 0x990BE464AE90EC82ULL, 0xC5FAAB7B2CB81A08ULL, 
            0xCC2CF8E06AE880A2ULL, 0x0CD292DB93521C92ULL, 0x3399E92E5099FDA9ULL, 0xC545209CCA9801CDULL, 
            0x839F48D39DB6BEDEULL, 0xA772C45CD24BE59EULL, 0xE0C5A4E08A39E7CFULL, 0x6459FF39EACB1BE5ULL, 
            0xD30F22739EC6D6F2ULL, 0x4F4726A9647079A4ULL, 0x57953B9332ABA0AAULL, 0x7C21BC8CC3AE9120ULL
        },
        {
            0x2CE68692C3386647ULL, 0x5E75138E1F395408ULL, 0xB1C5EDB0AD680048ULL, 0x454680F9B86DEAAFULL, 
            0x15BDDDB843B80E08ULL, 0x905D9A9B3D3B5FB6ULL, 0x6A1A41DF26627181ULL, 0x216514B98F99595FULL, 
            0xC0FE026E848F4C8BULL, 0xD771E1C1CA246D0BULL, 0x18B20A8D4F4A9BCAULL, 0x611A3A072D95088AULL, 
            0xBFE002CEF5B4B57BULL, 0x408D1086DB86B808ULL, 0x979DCE7227049D8DULL, 0xB74BBFB72894960EULL, 
            0xF0C9ADB586BE0B46ULL, 0x521FE4A06EFAD10AULL, 0x59A89855951AD721ULL, 0x3013F56CAFD846D3ULL, 
            0xD2262E67CEFD13E3ULL, 0xD0576BC7AAA11BE0ULL, 0x3AEAF606EEAE3A67ULL, 0x3E0620056722DE29ULL, 
            0xB7FBA830235D6C44ULL, 0x06F161F03F1A61FAULL, 0x23C21E1AFA4D3023ULL, 0x91CE5C79B134E35FULL, 
            0xBFC5F3122C8B1CD2ULL, 0x972AF233EA81A7DAULL, 0x1B47171CB555DBF0ULL, 0x52A54CCDCDB8CBCFULL
        },
        {
            0xFDFD4BAAB61ABBFEULL, 0xDD5FF293D4FB4E69ULL, 0xEEF4D73F721CA281ULL, 0x0D191FDE4664C587ULL, 
            0x5704D33AC446E9D8ULL, 0x9548B6AEE9B56B81ULL, 0x6F7C6926BF0F0F02ULL, 0xF12ACA01186656B3ULL, 
            0xCE03F2F2FAB9E4CBULL, 0xA328C5E5D06458B4ULL, 0xA6D3EC06A34590F5ULL, 0xA1D72ADB4B953561ULL, 
            0xB65752EDA2865A31ULL, 0x952DCEAE5AE97FA1ULL, 0x9261FB9692CB0E55ULL, 0x123BABFDDF5AB934ULL, 
            0xD3EC6323135BEB56ULL, 0xBB1DBEF8EBA6F68DULL, 0x078ED9F02B5672C2ULL, 0x3FE62A6D8B36EE62ULL, 
            0x04F54A85DDBE87EAULL, 0xEBCB5C83D3089622ULL, 0x392CDBD68CB5CDE0ULL, 0x51476771BC9F3863ULL, 
            0x653E95F286068CC5ULL, 0x5ECB4B543350B5DFULL, 0x2AFD2F1F458E2A08ULL, 0x16EFA5FFDEC579EAULL, 
            0xB555FD202EC20679ULL, 0xE60CCC4A0C1F2506ULL, 0xC6DFF8B560DCE069ULL, 0x8C5247C86E91D5EAULL
        },
        {
            0x8CF00E64FAD61AD6ULL, 0xCD8036175DF1F58EULL, 0xC1DFD7A5263A8240ULL, 0xBEAC252C85D86EC4ULL, 
            0x4BEC16A7960E4A64ULL, 0xB7FE9D34C7CD174AULL, 0x463AD0DB6F7BC4A3ULL, 0x54D3553178B896BAULL, 
            0x95E21780C7973507ULL, 0xD6BAC3E8D5269BD0ULL, 0x2F2A0F0D0268DD53ULL, 0xF54EDBFC63255E72ULL, 
            0x444D50DBBAB24294ULL, 0xC3A3CB1339285018ULL, 0x436B89580536AEFEULL, 0x23C027F47179C673ULL, 
            0xE0F612FE42000DF6ULL, 0x50AE8BA1ECDC7183ULL, 0x1E49A5F657CF623FULL, 0xBDE59F4FC4A2A806ULL, 
            0x72A635A1CC5BDD84ULL, 0x12324D1BD8F4F29AULL, 0xBE04BA7536FDFBA7ULL, 0xA15C4AEB0AAC75EAULL, 
            0x6ED7D38B2DC036A0ULL, 0xA9009D81A98F05A2ULL, 0xD827EF348098D861ULL, 0xFE7FC40D1CC3C4D6ULL, 
            0xE7228BA69B1CD12EULL, 0x12742BDE2D9212DFULL, 0x4C8DF23C03D541F9ULL, 0x1C0E400407E8C6F1ULL
        }
    },
    {
        {
            0x4D8D0BBD726A9886ULL, 0x4D36A2C949D94D5BULL, 0x1B29F864CD95506EULL, 0xAA6934F24D3FF8ACULL, 
            0x8F513AFF6863599AULL, 0x22CBC64ECB0E1A4AULL, 0x6080F44C30BE1E2DULL, 0xF20D369D3850CB34ULL, 
            0x3593499055151454ULL, 0x04E23104967E9818ULL, 0x6EAC374F4D35AFFBULL, 0x8F3315B9B513FBF0ULL, 
            0xCE7AA1B13D226C94ULL, 0xD52A93A606B4150BULL, 0xB9A017B0D12F16FDULL, 0x485A6A82289C8773ULL, 
            0xBC230AF5DE146BE8ULL, 0x090C771D3FE48D9EULL, 0x751CF3E5963FF28EULL, 0xE6306B8E0E25CE65ULL, 
            0xE4EFEDE88682BC1FULL, 0xEFF9D73406A72DBEULL, 0xD80ADDCACCD82A5DULL, 0xF1B24C91792ED8D1ULL, 
            0xFAC14DE0DCC73F5BULL, 0xA3A558DED1442ED2ULL, 0x5795C834AC15D3F3ULL, 0x431B80DDC5DCCF79ULL, 
            0x40513E9D911B5A57ULL, 0x5B6437600501B314ULL, 0x0045C8DA27F82683ULL, 0x1CE22903FB13ECFEULL
        },
        {
            0x438EBA76CC63A277ULL, 0x2B73105F5C0F2DD1ULL, 0xCCAE2D8F09293C49ULL, 0x182F61780E6D150AULL, 
            0x3747C50F67086943ULL, 0x2CE0588896FFF9E8ULL, 0xF2292FF34E94A285ULL, 0xAE14F2FEDF0832A9ULL, 
            0x870992C027AFDCD7ULL, 0xD66BCC4FF66F4BFEULL, 0x1F90D6034A2DFF6AULL, 0xEF5A40FDAC693BF7ULL, 
            0x6E5A7695C7673D66ULL, 0x445F1B1CA28B8752ULL, 0x903DE7833E4699CDULL, 0x3D3EF6BA24795350ULL, 
            0xE50AE75DC734DB70ULL, 0x63D1DC2CDAD2F2EBULL, 0xF29818AAF45AC50FULL, 0x26FE7F51DB9078B4ULL, 
            0x189BED9D9A8C2DEBULL, 0x1669229B5DB9C79BULL, 0x648998BF337C1850ULL, 0xE39877D43240B2C2ULL, 
            0xA680F1B244CC6919ULL, 0x213C899C34E36E70ULL, 0xFD5C0E4C03C8BF1EULL, 0x41105DDB7E17DE4CULL, 
            0x0E18923BE587D29CULL, 0x8981D30F86835508ULL, 0xAF06E618333968C6ULL, 0xE3A5CE7816DB12B9ULL
        },
        {
            0xE5EEA66F456134ACULL, 0x8BB3A6DD55EA2885ULL, 0x6AA01F02B60CE908ULL, 0x01FF6A60B5673185ULL, 
            0x152A55012A2BD9E3ULL, 0x537A482FEA6FAFB6ULL, 0xE18C173EBD44FB8DULL, 0x8A912DAFC7552A23ULL, 
            0x53207E5801832A8CULL, 0xBAAB7D48FF7C96F0ULL, 0x1F94ABD600A72CBFULL, 0x2F224278DDAF6F99ULL, 
            0x2072F219C27C2E3BULL, 0xC77934B12469C315ULL, 0xBD32A4ACA4E60688ULL, 0x7D2F4D620136564BULL, 
            0x294C58AC89475DCAULL, 0xEE1E5CDEA51FFBB5ULL, 0xBF972954562B705EULL, 0x00BB5F2AE13FF1B8ULL, 
            0x1FED475086ACAD32ULL, 0xD7119114B1C5137FULL, 0xC060B561E53B6C81ULL, 0x7CD5155596DC9D37ULL, 
            0x543AB15663197409ULL, 0xA84EA427ED2CEE24ULL, 0x4E5FAFF75A883544ULL, 0xACEEC0C02CAC644BULL, 
            0xC9499C88DCABA40EULL, 0xF84AEE518DA7FA51ULL, 0x90246EE61045DAB6ULL, 0xFD88D7098D0E116FULL
        },
        {
            0x663A49373F249247ULL, 0x8FA7A587B1C6CF9EULL, 0x990AD98C92566A82ULL, 0x4B63384C1B4345E4ULL, 
            0x3EE708AE07D87C7BULL, 0x7EC80A3351EE7A45ULL, 0x3B3D44657B35F90EULL, 0xAB8F225A10B3BA78ULL, 
            0x1A31C776945359A3ULL, 0x1EF8667526A52DB9ULL, 0x5E322924907AD22BULL, 0xE36B8C79161568CCULL, 
            0x777586D43B51A1C0ULL, 0xFB1C36F236D36AF6ULL, 0x6D560FFD92B665A9ULL, 0xEEA2499EB62FC70DULL, 
            0x783D402285C20389ULL, 0xA1D07553082C6245ULL, 0x4CB6F5AAD39F8BA7ULL, 0xD8F2925155A4DF57ULL, 
            0x13BD34F9BCBE9720ULL, 0xD769859A7187CD15ULL, 0x8452FE43E741625AULL, 0xAC28A165F43293B4ULL, 
            0x07D45069B6B2277DULL, 0xCF8ACA8FB56C769AULL, 0x1F52AB771FC12786ULL, 0xB63476D39852300EULL, 
            0x5B684BDA3CE57439ULL, 0x80C27C692D11A189ULL, 0x255071B7F87FF77AULL, 0x1BF0B19F9EBBFF2FULL
        },
        {
            0x6BEC55BB3D8CEB18ULL, 0x60A6BEE0F0C7DE49ULL, 0x4F1F29926C9C56AFULL, 0x304A03C924477E46ULL, 
            0xEFF5B699EB41A8C3ULL, 0x57F8BFA219B3BADFULL, 0x6DC825DDE7D2CDA6ULL, 0x828A7BA9CD831BB9ULL, 
            0xCC14AEF3959E840AULL, 0x9ED3F8E73EE57A00ULL, 0x7F7E25D851119AE5ULL, 0x463CAC6DAD726C64ULL, 
            0x5C9C743A417E39F3ULL, 0x6CE9EA1927C372C0ULL, 0x3453FF13C8CAB269ULL, 0x7AF54C5ADA3ADE35ULL, 
            0x8655D3FD6892388FULL, 0x86BBF408235794C1ULL, 0xD5441437036F47F3ULL, 0xF112B4A616A2994FULL, 
            0x9F409FDCB7B44B8AULL, 0x501B8BEBC5EAEEC6ULL, 0x809E4851D31005E5ULL, 0xBA8C73642BEF55CBULL, 
            0x607325686A6506B5ULL, 0xC7C0C1DC5FDCE1CBULL, 0xE12016F72F861742ULL, 0x8C527F8FACB5E6C2ULL, 
            0x5B2A27CB63CAC067ULL, 0xD4AACA8C4010491CULL, 0x408A89F5AA88E274ULL, 0x27FB92550370E335ULL
        },
        {
            0xA9255F099EFB43C5ULL, 0xA6B5947B3991E39CULL, 0xE21E7F1059D9E2AFULL, 0xEBE362FC9EE69C84ULL, 
            0x6F115F10F433509FULL, 0x52284003245C9EEDULL, 0xF6FE743B8D2C1897ULL, 0x571F589F43B8E991ULL, 
            0x538393EE1B03D115ULL, 0x67F33C477554C913ULL, 0xB8A469B1777D99E8ULL, 0x0ECF3704812D9DF4ULL, 
            0x4C69125DD538D7B7ULL, 0x66AEBC4450D2271BULL, 0x68E62197A779ACFCULL, 0x68ADCB9FE460E6C2ULL, 
            0x6D34DDFC08D7D4D0ULL, 0xC6F69242CA14C977ULL, 0x2AB8F05E1336E53DULL, 0xFACAAF8709E37B9CULL, 
            0xB93C2FE0F0368410ULL, 0x939122314384F053ULL, 0x6E3C680A640DA990ULL, 0xB9B5891A70A01AE1ULL, 
            0x635D6DCFBF59AD22ULL, 0x60FE45E9CA7536E7ULL, 0x3D5D70B37AB97FFEULL, 0xEDA324CFE60952DFULL, 
            0xC37D9B81755343B4ULL, 0x690F95DED4FA1BC4ULL, 0x2319559D0636D121ULL, 0xD01DFC6612FE3ABBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseEConstants = {
    0xB16DAC265AFAC8A2ULL,
    0x1DE84DFFE161354CULL,
    0x877A0426ECD7E7F0ULL,
    0xB16DAC265AFAC8A2ULL,
    0x1DE84DFFE161354CULL,
    0x877A0426ECD7E7F0ULL,
    0x94FBC22526EB390DULL,
    0x0E605FE042580920ULL,
    0x4D,
    0x20,
    0x75,
    0xFC,
    0x63,
    0x89,
    0xF4,
    0x64
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseFSalts = {
    {
        {
            0x2B8A53F47B571943ULL, 0xF0417C40798594BAULL, 0x9DBA16AE534DBF9AULL, 0xAB56EBC4F5B44251ULL, 
            0x1FC416FD10882BE2ULL, 0x8DAE5CCF5C8AB778ULL, 0x610CD6217F392EADULL, 0x7BF77DBFB55CEA8CULL, 
            0xE557AEAA399E43BFULL, 0x2CDF983C9D63F352ULL, 0xF48C9B4136B8D497ULL, 0x8ABE0E29DB58EB86ULL, 
            0x3D2FBBDE44EC8A94ULL, 0xD758CCF33D768725ULL, 0x9935746F653CB5F3ULL, 0xEC67BE07F1212B95ULL, 
            0x8E6C7EF749F97184ULL, 0x9809A8277A0A28EAULL, 0xD1FDF05D9E7A63C4ULL, 0xBDA829C56AAEA9C8ULL, 
            0xB20931B62E0A7B5FULL, 0x0295697E78B88FD1ULL, 0x1A08AB93D26266A0ULL, 0xF94A1A31B3E8E53BULL, 
            0xF4A5C3479A01C5EFULL, 0x619695DF45B92AF9ULL, 0xEADD27BF4E8CABF2ULL, 0x80F80B8B043C76CEULL, 
            0xF4CFE051B925B540ULL, 0x8BC3822C873533B6ULL, 0x3F3D8CD5E7D7847CULL, 0xB3E39EC5697E3013ULL
        },
        {
            0x8F33E4010C3FAC2CULL, 0x0F1AEB89109E3E5FULL, 0x47C93E337DA9AE8EULL, 0x66FCA261CCBCF382ULL, 
            0x8581C78CD2576489ULL, 0xF078CEB1D894B579ULL, 0x26CCE6D2D76DDB5BULL, 0xCDBF36DE907FFCF6ULL, 
            0x45487BC26780E5E3ULL, 0xDA6CAB6A9A222246ULL, 0x4B3C0DD64B73D7C2ULL, 0xF73913FD52E45F2AULL, 
            0xA82B5882CBD41981ULL, 0x8A09A85660E8EF22ULL, 0xE87293057960232EULL, 0x3D731A9CAA9378E2ULL, 
            0x59B695613C4AE1CDULL, 0x21CC1931191643D6ULL, 0xF73C3128858192C3ULL, 0xD5DF58CEAE345A61ULL, 
            0x7C2F074E3F3F36EFULL, 0x05C0776CE93EB816ULL, 0xC3DE8C76BF68CC93ULL, 0x725C21E36E65112EULL, 
            0x87789827AF8421D4ULL, 0x272BFFBF904737D9ULL, 0x539361DF6AFA193DULL, 0x52B8B4ED42E68B84ULL, 
            0xAA4A87EA16C7AE41ULL, 0xC5D7CE2D567B2DA4ULL, 0x5D3B8750CBEF1B48ULL, 0xE6B28EC59C5093FDULL
        },
        {
            0x5E9C4995B9BA76A6ULL, 0x15478624DB61F4D2ULL, 0x810CD1977AC07162ULL, 0x421CC9955A39B282ULL, 
            0x0390266920CBF70CULL, 0xF60B032683311D3DULL, 0x7F1BE30E2D81603EULL, 0x0D4F575D54BB0174ULL, 
            0xAA381C05F4B5504FULL, 0x5F15BAFBDE956933ULL, 0x86D4E857B2178236ULL, 0x2B1E1E150EA9EC2DULL, 
            0x4BDE12FEDD3C8239ULL, 0x28AC01BC113F5993ULL, 0xB951FECD56C19FABULL, 0xFD9EBE91364BFC85ULL, 
            0x5EC30A8C40293147ULL, 0x940E787EE52DAF51ULL, 0x2D6FC0190383D053ULL, 0x9AF205C8DCF2D5B5ULL, 
            0x3E1C7AF551FED835ULL, 0x7C1809AF322044F0ULL, 0x78188C7F8DE0E7B6ULL, 0x46D9F9F4B500B1CAULL, 
            0x202D328A7C366F49ULL, 0x818632D2AAA6E21BULL, 0x671C4592998145FAULL, 0xDC6F3449935F915AULL, 
            0xF77B64C0CA485461ULL, 0xA75A5357C48279C4ULL, 0xC482BFE27E8E5E7FULL, 0x57DB695986E99556ULL
        },
        {
            0x16DC8F4F88A5A200ULL, 0x25904699A569466BULL, 0x67549DC876AF7827ULL, 0x728208C5857BA399ULL, 
            0xA03D13FCCC71DEC0ULL, 0x889FFC447CD7D8F5ULL, 0xB2D067789434366EULL, 0x70E08B26D9B5E8A4ULL, 
            0xD71956C0D4C90CF6ULL, 0x7A6B261964C3574DULL, 0xB7B0CE6612CDD0BFULL, 0xA14DC75F7123E142ULL, 
            0xB1C950E1989690BBULL, 0xDD321EEED490FCA6ULL, 0xFD45FC5C9AA7FDB3ULL, 0x64DE24E387D6009BULL, 
            0xF21A72001F480D45ULL, 0x9C3DF2BD381F2544ULL, 0x4161FE9C645D1581ULL, 0x22AEE9415BBF41BCULL, 
            0x0F6F9698E186355FULL, 0x5C22AFFC04DC58E8ULL, 0x780A4CD9A3F52FD2ULL, 0x1CE7215FB89F8C46ULL, 
            0x43C1F51EE649A7DFULL, 0x8438F1C52390DBEBULL, 0xCFA0DE447E662DB0ULL, 0xBF014DC2D4B00823ULL, 
            0x6008F77478627E76ULL, 0x3498E483477E97F0ULL, 0x21B11088D0095A34ULL, 0x113F5B50E6EA6855ULL
        },
        {
            0x9273268FE70341DEULL, 0xF2258D66CCA31295ULL, 0xA3AFA67C9143BB70ULL, 0xAD0FDF3C2E7DEBD7ULL, 
            0x08404DD9F6EF8E9CULL, 0x5F0440BE7F78E3DEULL, 0xD09DEF42FDB9D2DDULL, 0xD4F5ABE3EDC51A1AULL, 
            0xA246E5BCDC3B2929ULL, 0x003BA438D5151D94ULL, 0xAC40EA9827158FB9ULL, 0x19DBA294875C0E2EULL, 
            0x0C9EC94A6466D02CULL, 0x2B4412643417374BULL, 0x427AE8CEC0F9D364ULL, 0xEFD1578D878A8C35ULL, 
            0xC38B5DFF9A368C42ULL, 0x3435B0C61049D783ULL, 0xA857A0EFD489F0B2ULL, 0xC6B7F4627865BD30ULL, 
            0xFDFD0E3BCE777047ULL, 0x69155BD2116251AFULL, 0x37BAC7FBB8BE72EFULL, 0xB956FF6B8813B1E4ULL, 
            0xB3D41F60149AD0D5ULL, 0x6E36C037807B5038ULL, 0xBD46B9F2F01509B1ULL, 0x3CB8918CB4BBDE09ULL, 
            0xBB5AD2218DF6BCCAULL, 0x500FCBDA2FADAEFCULL, 0x7801585D013E1484ULL, 0x3CEBCF32A0FE432FULL
        },
        {
            0x31321E4B19D58499ULL, 0x96A369B3022C15D7ULL, 0x75CC489A83E860B0ULL, 0x195416739AAD5FA4ULL, 
            0xACD9395EF042DCFEULL, 0xD7FDA9404C8ECB6FULL, 0x8D172ABC1C539F17ULL, 0x2072DC26415FF55EULL, 
            0xC4588F21251597B9ULL, 0x81961785DBCEA3ECULL, 0xF2747618EAEB8BF4ULL, 0xDE3CD009FD7D4839ULL, 
            0xBB270BE74D2793F7ULL, 0x88070E2BA5CCBF09ULL, 0xCBF03DECAD94E779ULL, 0x78753428A24A1972ULL, 
            0xB7DFC95C3DE7BAABULL, 0xD458B7F3EA140F90ULL, 0xFE5598548026CA12ULL, 0x65978AB833B15F31ULL, 
            0x35D0178BC69935A9ULL, 0xE67C28B7F0A8E452ULL, 0xA7DC2B2D8EBF883BULL, 0x5640DEE9474CA73DULL, 
            0x8FC8019AF9271A6BULL, 0x9DB03F324EFE62F3ULL, 0xB44EDC28072E1D90ULL, 0xE6E56E265509401FULL, 
            0x2A2981FA77A90FF5ULL, 0x314C672578C26CA9ULL, 0xA2E7EE125ADA840FULL, 0x31D7633E7949E2B4ULL
        }
    },
    {
        {
            0x5D3E45560891BD34ULL, 0xC18CB4B221E57153ULL, 0x7E33068ED093BF7AULL, 0xA409FFBF2252DB24ULL, 
            0x74F818A1300BFEDAULL, 0xCDB5B6447A61023EULL, 0xECE37A11FC495EFEULL, 0x780A4F8A0C377AC4ULL, 
            0xF8F0EC23257C27D8ULL, 0xC62B699C1223D652ULL, 0xD2BAD461FF698977ULL, 0xA28468C3F4C0B751ULL, 
            0xD019132568D4BB40ULL, 0xAD5C4A3046CE2CABULL, 0x7137778A4EB58BAAULL, 0x3634B3281AC22E79ULL, 
            0xED694362C68D2457ULL, 0xB3B26B4D6A167497ULL, 0xFD8B4B8753ABA9F3ULL, 0x4182D320124D8C16ULL, 
            0xF8A8C5D0EAF2FDA2ULL, 0xF3B9456E592D6D87ULL, 0xAEB5C96F436FCF4BULL, 0xF134E4A5AFD18341ULL, 
            0xF4C5EF4A47965078ULL, 0xF38D436314C7B2A6ULL, 0xE71F9AEE476BC83BULL, 0x53460E7CFFCC6419ULL, 
            0x4588937CB13A331CULL, 0xECBECE243C31559BULL, 0xA7F7D7453EF487ECULL, 0x65C8C94AF330C245ULL
        },
        {
            0x97ADA8C0CCE52E61ULL, 0xA1C48DF662DBDC06ULL, 0x6D8B4474B4B06CC1ULL, 0x34EBBD9C602BCFDEULL, 
            0xDC53A82A0D6C123EULL, 0xD9C7B060C05EA40CULL, 0x11D486DDE3FA82A2ULL, 0x6F6B297B3DE19336ULL, 
            0x14439A92FF06067FULL, 0x304920D414635343ULL, 0xCCA183C5EBBA62D8ULL, 0x3C1FE986B47198A7ULL, 
            0x0C9BA82AE31AA88CULL, 0x6D9E648A6FEEA276ULL, 0xB9DE96A6D7C2BC1DULL, 0xBDDE6692690B86D3ULL, 
            0x44E178A08DEAC9B4ULL, 0x34CB0C6BCB127176ULL, 0x5ED77451851BC4FCULL, 0x6B31986437C4B257ULL, 
            0x26E18B06DCBB5ED4ULL, 0x3521BF8C704B2B5CULL, 0x8EC5331414229962ULL, 0x07742197182091DBULL, 
            0x9C1AB450AE47C6B4ULL, 0x4E397150FBAFDBE9ULL, 0xEAA2CFC9CA1FF6A4ULL, 0xE79D68BCC31604F2ULL, 
            0xE585E4D54C8D41C3ULL, 0xE9E5638B31C0ED9AULL, 0x9C9BAED278F91043ULL, 0x99B2BE953F2079F8ULL
        },
        {
            0xB86C733432F62290ULL, 0xC126FE83BBB0B973ULL, 0xEB8680881036BCBCULL, 0x04F736ED555AE23EULL, 
            0x7D12BD566A1805CAULL, 0x9F43FBCE624E95EEULL, 0xD39F01AB7C4765A2ULL, 0xCD108CD7857AC216ULL, 
            0xF681A8F95D0F6867ULL, 0xA4B853FB625951D0ULL, 0xE8EECB9850C60DF5ULL, 0xBFD5C83FEA24A050ULL, 
            0x5611FDAB97D1CFA9ULL, 0x64948F2458C2313CULL, 0x0CE80A27B6A2A4F9ULL, 0x283FC159C4E7E0BCULL, 
            0xC4707CD21462784EULL, 0x60AF78032418B3DCULL, 0xDE0BD33ADEE31421ULL, 0xD00B09479E8DB406ULL, 
            0x837BD041F3BA1BC1ULL, 0x419FC6F38A48DCE5ULL, 0x22F1192E345545E3ULL, 0x314CC4D82D88D457ULL, 
            0x0CE73AC28AD39C97ULL, 0x054763EE4AF94F79ULL, 0x75A9BCDB0920EA07ULL, 0x29F4791DFE796591ULL, 
            0x943A7578B46C8D39ULL, 0xD9C3532984BB7400ULL, 0xC7091F6002D40C26ULL, 0xCD4FE87D5B1A195AULL
        },
        {
            0xC9837A8074D6BBE1ULL, 0x2479B1BDA5CC58DCULL, 0x309705786919AD4DULL, 0x1D8F76872A7E2794ULL, 
            0x37588FB814F33F1CULL, 0xE32A2FD90480604AULL, 0xB0B206F5163453B1ULL, 0x7DC3C0FC5DB1FBAFULL, 
            0x6DC16ADB303B5F1AULL, 0x9A06E13FAF595052ULL, 0x05DEA9C0FA960DBEULL, 0xA89A3B40CBB345E0ULL, 
            0xCE55FE2D729EE354ULL, 0xE02977B2A0F0C563ULL, 0x760D3449342E14F8ULL, 0x2AD269278D2BC2FBULL, 
            0xB96A956A1ED2576CULL, 0x0958B1E95F08110AULL, 0x37FFB81563306C78ULL, 0xE1DBB953781F51BAULL, 
            0xC5BEE50E2430CEC6ULL, 0x52725860F2439E5EULL, 0xF09160C32235C3F3ULL, 0x28B4BA8F9386B956ULL, 
            0xF3CA3719F9716EE0ULL, 0x919C2A282AFE5A10ULL, 0xC6483CCE212FF4F7ULL, 0xC431DC362F7CE03BULL, 
            0xB094AC67537AEF6BULL, 0x46922C6582586596ULL, 0x9826003E1B561200ULL, 0xFE3092BFB085CC9AULL
        },
        {
            0x16F8E5AF8D08DAFAULL, 0x65EECB696405D1AEULL, 0xF629172F5492B58EULL, 0x77F333A44566A2E5ULL, 
            0xA8236445C61954A9ULL, 0xF28F50597770620CULL, 0x3E55A29534A47EA9ULL, 0xDCB4C52EFE1AD653ULL, 
            0x65281027DE972EF4ULL, 0xA0E37B9C12A0333CULL, 0xEBC9A497520A90F6ULL, 0xBEFF4B30997CE218ULL, 
            0xD5774FBC72ED17E1ULL, 0x14CAA72D4E65CB30ULL, 0xDB70526FDBE1EEACULL, 0xEC9013ACDC7FD103ULL, 
            0xCCD76D3842A144DEULL, 0x7F9B960AFD03311DULL, 0x3A102A30704A639EULL, 0x5B9DB73AA3997A4BULL, 
            0x53E581BA876C4E38ULL, 0xF0E601B4AC648C8AULL, 0x42CD4E9A1401ABACULL, 0x1C5931D004118CEEULL, 
            0x2D869E9BCA1CFD63ULL, 0x12489F9498884410ULL, 0x36299DCED5DB1429ULL, 0x0CDF4D2A4157F8D6ULL, 
            0x286F438EA7DE49F7ULL, 0xB25E5FA2D2C33C50ULL, 0xA07AA4170587A16BULL, 0xBABB925B80E4B43AULL
        },
        {
            0x0960576FFEF2A029ULL, 0x6460D0B19C2B0E45ULL, 0x3C4747BB7D2152BCULL, 0x9D5BA575DA11E56AULL, 
            0xD79B7B86F127129AULL, 0xC5A45FE3972AB9AEULL, 0x060A03FF32B841C8ULL, 0x4D05CE902B00661CULL, 
            0x21EACBC1C6D9A71EULL, 0x5FAF5B5B1E6CD757ULL, 0xD193F43F34D368D8ULL, 0x63204BF45A60BC98ULL, 
            0x253A3F5D72711DD6ULL, 0x9E7367E398CBA524ULL, 0xF03B3AB5AE7B90D8ULL, 0x4C5B74538DD02FEFULL, 
            0x2CA813D47A74F2E4ULL, 0xD0D28C5D9F6AEA6EULL, 0xE981509C7FB41C0AULL, 0x96443F77B6B6F8B5ULL, 
            0xBFB42699400E36BBULL, 0x90C97005BA7A283FULL, 0x07D9EA114A700686ULL, 0x4726DD28BC913503ULL, 
            0x7A880859485B7059ULL, 0xD82D433AF85C7769ULL, 0xF7F5138DA767ADEDULL, 0xE4971F066502BF7DULL, 
            0x3447DFD3D347D3C5ULL, 0x873CBA8629BB42DAULL, 0xE529A8EE32C3017EULL, 0x9EC7EF8493F07B0CULL
        }
    },
    {
        {
            0x61C20D15E1DE7723ULL, 0xB49B71FBAF282CC8ULL, 0xF2B350C272A1EF56ULL, 0x1451712A9048ED70ULL, 
            0x4FEC751D88629847ULL, 0x6FD0C9710BFB4761ULL, 0x094828E4D5C4CCCBULL, 0x0E5DF9F90DA29951ULL, 
            0x26799CCBBEB63D3CULL, 0xFC7F013D9FEDCB6CULL, 0x39FFFCA176D57FFDULL, 0x6672C71013DF1564ULL, 
            0x55AEC439BFC3CDADULL, 0x69A97CE5F9692416ULL, 0x17B2E66E4D8FE6FBULL, 0xB9DEB9A7C4BE9F10ULL, 
            0x2BB6EA5EE925AD75ULL, 0x050FE2446244E35CULL, 0x1C038B44B64346DCULL, 0x47EA1C4060BE4080ULL, 
            0xC4AEA94D189AE5DBULL, 0xB261637EF55F1866ULL, 0xC8C5FA7BCF1D95B8ULL, 0x44A047B076A6E2A7ULL, 
            0x46E4A78544581BA6ULL, 0x4C0CB7E4A919DC06ULL, 0xAD8C7A6FEE5B7325ULL, 0x2A03B1E0FF716736ULL, 
            0x7C5F9FE17326E6E5ULL, 0xC83DD9E576055A60ULL, 0x01A9C91356D79BFDULL, 0xBDDBDC96E05BAAB6ULL
        },
        {
            0x74F14B9F800B5CF3ULL, 0xB27783D7A2CC6E69ULL, 0x092D77DD9FC055F9ULL, 0x64E2BCCDDEC0C87AULL, 
            0xA86FB0FA97D00C4AULL, 0x1482636FCADEDB69ULL, 0xA7A3C161FFE6D78BULL, 0x834B8717D2E7E8E2ULL, 
            0xDB99796272EA4A7BULL, 0x686AD5FBF2AD4E29ULL, 0x3D480B1879339C14ULL, 0xDA5FB293DADF1F78ULL, 
            0x9FC070A8096638FEULL, 0x3D2C08AEBC1FE11FULL, 0x93E34CF0C351369AULL, 0xD01E1FEB62EFE945ULL, 
            0x73D4E4FBE723FBC4ULL, 0x0B267AF1361A56DCULL, 0x3CBA0FDA6BAF633CULL, 0xE21D40EF78983665ULL, 
            0xF471E248574CFA1CULL, 0x92CCC527D8FD4A37ULL, 0xEEDB80A556A35E46ULL, 0x3A7EFC6DD052F104ULL, 
            0x9EB313799B404076ULL, 0x19C2FF736B7A5D48ULL, 0x16ACFCBCC3CCAF2BULL, 0xBE275E532A00D5FAULL, 
            0xB3007C07A7E21C01ULL, 0x0E30F57BDDF75847ULL, 0xCC4014356487C3ABULL, 0x74F4C2D6D715D18AULL
        },
        {
            0x533B3D4A3EB08016ULL, 0x53A2007110AFD895ULL, 0x8CDAC55C38E0A1BFULL, 0x1D62C3D8837905A9ULL, 
            0xFE0229BA32993973ULL, 0x1ECF30326F7DC58DULL, 0x69FD621512024B06ULL, 0x78ECB06F6002D4E3ULL, 
            0x6FDD89651E924601ULL, 0xB923F27F9B4CFBE1ULL, 0x54DA45F251A5C24AULL, 0x47C125ACB3543DE4ULL, 
            0xD0C1F6ABE803B240ULL, 0x58097116EB3C5E14ULL, 0xEEDBD7CC92D66D7BULL, 0xEAFCB4314CE6C040ULL, 
            0x8E8D07F82B3E6C27ULL, 0x91773A4FBF278F05ULL, 0xE56F9899B31DAEB3ULL, 0x265F5C59DDBD8DEEULL, 
            0x2B6F7CC14CD0796AULL, 0xCF284F5857BC96ABULL, 0x58650B4061A47A32ULL, 0x0B4FC39E369EFC4FULL, 
            0x5CD7000C0E37049DULL, 0x8589883B2A90075CULL, 0xA8104FBA8AB0F466ULL, 0x3C205E1A0E35007DULL, 
            0xA1C26961458B7D58ULL, 0x567962AD9423F525ULL, 0xF76FC05B747EE8BDULL, 0x99CD1E622FA83F09ULL
        },
        {
            0x7554B55662EEABD4ULL, 0xFE33840F8BA6E3F8ULL, 0x8BECBCA44A3F7D67ULL, 0x0AE3E80F623D14D9ULL, 
            0xF5716F74E178CAEAULL, 0x8BF473F3D38324A9ULL, 0x63719BC3E39379F7ULL, 0x05469B700D385B35ULL, 
            0x328D5551826948C2ULL, 0x904999524EA37B12ULL, 0x3C76E3C156C65E80ULL, 0xE787522B762B2C82ULL, 
            0xFCC5AF4A252BC1B6ULL, 0x11A2BE4D03475925ULL, 0x97CBC43EF18412F4ULL, 0xF61E326C8934E391ULL, 
            0xDF99A120EB880196ULL, 0xC6230EE2D303DA1DULL, 0x05FEB4A3C617823AULL, 0xEB7F4180C7BCC20FULL, 
            0xE4851337C2CC572AULL, 0x850C910F2A7121FDULL, 0xDE731E77C6EC20DFULL, 0xE9D931D6CCA7AD63ULL, 
            0x7A165461C89BB473ULL, 0xCAF71F9086E0EB78ULL, 0x736E2583122A4126ULL, 0xDC7D63C6FF566F5FULL, 
            0x6DD23FF838A3D0DEULL, 0xC5BC6ED3B519FE5FULL, 0x0E7A944715D67EB5ULL, 0x6613441AFBF54C29ULL
        },
        {
            0x3AB6C6A6C3B39DF7ULL, 0x1A8436433B49740BULL, 0x8C0E0F17652EDDE8ULL, 0x0A3D8EA81EB4D3DAULL, 
            0x9EF49E8CB324D8D1ULL, 0xD5C2FF0CB5CAF69AULL, 0x0FA0B41BB930A40BULL, 0xA95EA2E98284A9C2ULL, 
            0x87FE40D7D656E666ULL, 0x16AE142CDB4FC87CULL, 0x8E9AFF3352D91C45ULL, 0x582C45408F6122C9ULL, 
            0x6D0036B4038C7D51ULL, 0x41989DA251C25A77ULL, 0x9B9EF5B42D74CEACULL, 0x7E9E529572419EDAULL, 
            0x7B0E3B5F81DFF8E6ULL, 0x20FE4A2EB8773683ULL, 0x32C1F4619766914AULL, 0x4D212812E49F1B1AULL, 
            0x3E129A8679B9A2ECULL, 0x1D3AFB7C8B9629B4ULL, 0x5FCA976E04E44B9CULL, 0x7C9ADA89CB51F0DFULL, 
            0xC11BE0D3686AD4FAULL, 0xAD3F18066D48189AULL, 0x2926F115E7873EDAULL, 0x49F37AD653A9B998ULL, 
            0xEB3F1060CEB8659EULL, 0xB73C9BC550CA31FFULL, 0x5E7D7CCFE4FC8B7CULL, 0xDC1779AB185F909EULL
        },
        {
            0xF3487AE12C31685BULL, 0x0BD2313A3236F305ULL, 0xF264A40C18D50561ULL, 0x86AEBB5F943FC0C8ULL, 
            0x231AC3A1265E78EDULL, 0x7A102748E4E493B3ULL, 0x439A3FFD688C9FE3ULL, 0x990AAB76C4D523ADULL, 
            0x948D8C7906F887FDULL, 0x15AC0353ED006E33ULL, 0x4B3B79E996DB2F2EULL, 0x9FFDFBB03A9FEF2FULL, 
            0x48CD5F8D177316EFULL, 0x9B7A951DC58DBDB5ULL, 0x508243554FFD5821ULL, 0x3EDA7A6CD102FC2FULL, 
            0xF14753EADEA57157ULL, 0x50A95DEA45B46FC1ULL, 0xD090A091433D93A0ULL, 0x2E134ED92BFC47FAULL, 
            0xD3E9E7F8A3FB1189ULL, 0x13167A9A0D294B61ULL, 0x066EFF9D7E8CE7BDULL, 0xF9D71F2D02C30408ULL, 
            0x3F88664AA0DE0986ULL, 0xFA29361A309155BDULL, 0x55382BE1E92099ECULL, 0x58219310EF1E9326ULL, 
            0x84A351C9F00BE276ULL, 0xC2E2D0BEB284682EULL, 0x5631CC04EA4123CCULL, 0x78D12B353BD7AC91ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseFConstants = {
    0xE438E77674398324ULL,
    0x7DF5602232062745ULL,
    0x4EA299B6605DF511ULL,
    0xE438E77674398324ULL,
    0x7DF5602232062745ULL,
    0x4EA299B6605DF511ULL,
    0xEAA5F723F72A65F3ULL,
    0xE6CFB0BBD3B2383BULL,
    0xDC,
    0x0A,
    0x9C,
    0x4A,
    0xD3,
    0x77,
    0x3E,
    0xEC
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseGSalts = {
    {
        {
            0x05D9B152FAD241B0ULL, 0x95CE38F29003F4BDULL, 0xBDF609FCE0891EFDULL, 0x0C425CD8E6D2641EULL, 
            0x2334591639DB7E6FULL, 0x66DB20A431D166C9ULL, 0x4EB67CF46E8DCEC9ULL, 0x6B54A64313A6102EULL, 
            0x17255CDD737BF099ULL, 0x00F57A0BB8299434ULL, 0xB4986B121581C7D0ULL, 0x005E97E1F760D869ULL, 
            0x3B41E4D605987149ULL, 0xAA4E93A98038288AULL, 0x5A464866ABC7E336ULL, 0x0756D2B67774AEA9ULL, 
            0x61FE4B39510A004BULL, 0x53E663264F4E05A1ULL, 0xB26D25976609AB22ULL, 0x7290D3C9ABB3A046ULL, 
            0x2F6347A617E17148ULL, 0xDA88C0A3745F5572ULL, 0x42A8925212F11461ULL, 0x2EE1A7D30AE38DD4ULL, 
            0x04C77B418291E0FDULL, 0xC53FDB7D2148648DULL, 0x71C84868900187DAULL, 0x1C95C8548C013BE0ULL, 
            0x8F769F2EF3EAE36DULL, 0xF71FC2AACB42391BULL, 0x18D4226BF6B5800AULL, 0xAF94CB8207A91D38ULL
        },
        {
            0xB030EF925C059EDBULL, 0xDF835D99B0DA4B5BULL, 0xA04A253CB7F03B9CULL, 0x228204B6279C338CULL, 
            0xDC22CE92645344D7ULL, 0x07D58E31A9825C68ULL, 0x410D14ED089CABDFULL, 0xAA6A3695DDB73674ULL, 
            0x62C770004DC2E96CULL, 0xBA1177E3122FE45FULL, 0x11657CC3F7CE489EULL, 0xC42BD55DA5E64CB2ULL, 
            0x2C15E092B190E914ULL, 0x45403152180D8CD7ULL, 0xB952ACC5EF4ACD00ULL, 0x2461C07C7D931CCAULL, 
            0xAEFF223B60663501ULL, 0xC377A03B3BA004DCULL, 0x7943791441D95D9CULL, 0xD2E4F5BF75F14B8CULL, 
            0x2E5A731A9A4A4A99ULL, 0x2A0D81BD0662DC44ULL, 0xEA6031375ADD717FULL, 0xB6FADF88244103F6ULL, 
            0x30F1CD51BBD66A24ULL, 0x478E867BAC139116ULL, 0x5B4C55FF49E3FA72ULL, 0x43A6A471C350CB38ULL, 
            0xBD43D3207125FCFBULL, 0xAAA17900B648FCD8ULL, 0xFBD1D0F0644595EEULL, 0x3DF8FC876F0392FDULL
        },
        {
            0xD54BCE61D20039A3ULL, 0x095AE052A493EEFFULL, 0xC2B7EF99A06D4A69ULL, 0xFAAFFABF4E11F228ULL, 
            0xD77785D8FF02A8AFULL, 0x288C0F0122C74369ULL, 0x25EA7C6B63937169ULL, 0x1F33443F6E3683E0ULL, 
            0x8B95300F2403CBFDULL, 0x57564EAC4F34C7FCULL, 0x6B77FCFB1B054FC0ULL, 0x815575EB52F80C05ULL, 
            0x66E6BC3CA784BE8CULL, 0x05783ECBF4ADB236ULL, 0xBCFC0B12EC9B10C7ULL, 0x5CFC4FE444DA5567ULL, 
            0x448343F49DFD989BULL, 0x885519EE1E1367CBULL, 0xDA306DBB40C17CA3ULL, 0x49416C95A0B15D96ULL, 
            0x35F372B7F528F14BULL, 0x3AEF429D044BE18AULL, 0x0B5A425838DB4B3DULL, 0x91EBB39DCC563A60ULL, 
            0xDE43DD5183581232ULL, 0xD841169EB15433F5ULL, 0xC680E202CEC6EB68ULL, 0x95067588813DF3E6ULL, 
            0xF3C8C7632F00ED2AULL, 0xDAC089A399C62B4AULL, 0xC0FF4E431C15A135ULL, 0xCD4EFD1E7E1A8C63ULL
        },
        {
            0x8013A9B2B9F49FB4ULL, 0x06C1D8D6195EB5A7ULL, 0xB27C1AFBEB4D6043ULL, 0x474F110E9105A82AULL, 
            0x4680470C3D25835BULL, 0x5FD3E2EF5DBB600AULL, 0x4B3F1CB446088EBBULL, 0x0DD0755E8E7767E9ULL, 
            0x3AC46FF65636B0D2ULL, 0x6236BEFF007155A7ULL, 0xC9DB4A49046EC6C4ULL, 0x67732E656F10BE64ULL, 
            0x33437C43DC89459AULL, 0x1046EF526C86C675ULL, 0x94EF0A74BF541065ULL, 0x854A4CC6977F0CE4ULL, 
            0x4AF74EFAE1AA6AE2ULL, 0x932C085C751AFBD7ULL, 0xFCA3897D33CFBEC4ULL, 0x211EB92C0101B7DEULL, 
            0x7791F6772A7BFE4DULL, 0x9EFED9DBC96426A1ULL, 0x97B6DDFA08414D5EULL, 0x88D51E14EDC417F3ULL, 
            0x357FA64E0E1212A0ULL, 0x0225F750F6AB1326ULL, 0x17B3CB8B71E63F54ULL, 0x54937DD0765EA6F2ULL, 
            0xD5DF6A0CA4FBEAAFULL, 0x08902A751835EE22ULL, 0xF77D8C094B7DD04BULL, 0x0854028321880A8BULL
        },
        {
            0xC59913190FCAADDDULL, 0xA76AA85392FE34B7ULL, 0x2460D907270DF27EULL, 0x48E39871080BCBCDULL, 
            0x314E13055A5FF9F7ULL, 0x371F2397A7CFBB65ULL, 0x4A0B50D2ADBF4A38ULL, 0xECEC1DB513FAB85FULL, 
            0x2F345AC9ADC42840ULL, 0x1E4114FABF7D6152ULL, 0x969D1075C61CB13DULL, 0x6C93FBEFF626F7DEULL, 
            0x735D4B790E814E72ULL, 0x04A746086412367EULL, 0xAD16579CA51434A9ULL, 0x6608038EAEA40867ULL, 
            0x98C7887CF4170504ULL, 0x1B39D089CD09C155ULL, 0xEA511DB762FC793EULL, 0x7CF86955674ABAABULL, 
            0xE8BE979A42DA8E43ULL, 0x51883DD80FBB807AULL, 0xD24AB4C3479AAAF4ULL, 0x955538FD664F5402ULL, 
            0x1B6E9CEE974ADEEFULL, 0x8447B13B92DAAA53ULL, 0x7535AEA5FFB5CFE9ULL, 0x37E09A57EFDCFC77ULL, 
            0xA9339C7DFC90BCC0ULL, 0xC259AA50BCE35F0DULL, 0x02AD68CEB03697C9ULL, 0x3FB9637575E584E9ULL
        },
        {
            0xB67500EC03E0E5ABULL, 0x33A191A935CE68C3ULL, 0xF1B233AEF041B8B9ULL, 0x202B85C7A8DD8B73ULL, 
            0xF2A26CBC9214EDEEULL, 0xB77B6A1F5E3065D5ULL, 0xC5F92DBA4F06A775ULL, 0x809915B77BDD3C27ULL, 
            0xA4751AA224CC5AA6ULL, 0xA98C8BD972A3E852ULL, 0xFDCF944289F34C24ULL, 0x832B1B6B5511C7A7ULL, 
            0x83993035DB5BCB9CULL, 0x83A82234BC6C5E22ULL, 0x497DF81CF61A38CEULL, 0x2CAFA162A3482559ULL, 
            0xDC9EDF05BC22B9C5ULL, 0x9D75F01FA6E02667ULL, 0xF62645463EA3B5D1ULL, 0xB6F501863A4DD5EBULL, 
            0xBA89BF6771247F5CULL, 0x2842C5AD63BEA012ULL, 0x78BBDA3CE94358F4ULL, 0xE8ABB4605AEA0156ULL, 
            0x803F8541D0EE9FB0ULL, 0xCC5C3C4099E8124AULL, 0x592C55927DEB6850ULL, 0x25104C757E88A63AULL, 
            0x9F93F9DB4DEB4CC2ULL, 0x1E11C0A4320007FDULL, 0x8CC9167A9F4245EEULL, 0x751365C598C46C41ULL
        }
    },
    {
        {
            0xF6ED41022A5CE4A1ULL, 0xC52367610D9043E3ULL, 0xC60424D1054A8FFEULL, 0x6E52968DC4FB44D7ULL, 
            0x308FECC457EE30BCULL, 0x826A29BA6A42A2E0ULL, 0x3803AC8A1C62A0CEULL, 0x9D66E4200721AE30ULL, 
            0x2E59393137DBB04FULL, 0xD5D2111421ABF3BBULL, 0x3042F6D30E7AFB46ULL, 0xF43F4BF2D24B30DEULL, 
            0xAF8AC5E82D58CC25ULL, 0x9D83B49AF0FBEB08ULL, 0xAB5C7DDF6969906EULL, 0x76A448A75BBD41F1ULL, 
            0xD30768B0F577E9F1ULL, 0xD87F17E49761250FULL, 0xD97A207EE43E3E14ULL, 0xDC17F9DFC44A54B0ULL, 
            0xF8E743AC5FD6776AULL, 0xE420D353C5A16678ULL, 0xF3C752324555A918ULL, 0x6B797C72FDEB065EULL, 
            0xB85B6CDD4F3383DEULL, 0xD9AE2EA0B3F38BE9ULL, 0xD016F9E88F1E12D7ULL, 0xF1F78779E2C0A913ULL, 
            0x23278A5836BEEAADULL, 0x67D20A73BFD4AE4AULL, 0x2D28B2CA8065117AULL, 0xD8BC056C5CA714EAULL
        },
        {
            0x50DC8C14FBF6DA40ULL, 0x05F54418D7785B7CULL, 0xFE36348B339C5EBDULL, 0x783BAF7EF0892BF9ULL, 
            0xC6C057533855F120ULL, 0x16A60213C03F556AULL, 0xB64CC4B875EC90E4ULL, 0x7DDC7D6DA6ACF1C1ULL, 
            0x4C6736AACD82E4D2ULL, 0x1D917EFCA986F1A4ULL, 0x7773445CF30BC0F2ULL, 0x79EAF49FE7481ED0ULL, 
            0xB3B57694F125AF5BULL, 0x834719A7FC321E8DULL, 0x5AB33B72D1A2264EULL, 0x7149E27B50551BAFULL, 
            0xA2612FBF93965275ULL, 0xAB45411B7716F17BULL, 0x0DBA3E6AD3FFB946ULL, 0xA63AD26515AD8A55ULL, 
            0x21451441E19D3249ULL, 0xE3315E03F1F266F8ULL, 0xFE251922C87202DAULL, 0xC58A050DBE636E5BULL, 
            0xD8435802F10C7F02ULL, 0xBC8C9FEF182B2E8BULL, 0xDADBA2A0A445386AULL, 0xB78B3E87F3149823ULL, 
            0xF6F1ED3563363BE8ULL, 0x3ADC7EB22853194AULL, 0x52B6EAE38F591A42ULL, 0x66B7697E7017D3C9ULL
        },
        {
            0xD38F8FD4ED1B824EULL, 0x61E38372445E509BULL, 0xED6F29204E8826B9ULL, 0xD99B4BB6729D7678ULL, 
            0x07731A2EC7141DB6ULL, 0x3FCF9D8EE631D803ULL, 0xFDB02B24F0D22A40ULL, 0x4316C9A688C4F68CULL, 
            0xC1934616FD0B3AB0ULL, 0xF1E48CE731FEF107ULL, 0x88991596D96497B3ULL, 0x08CA192433885575ULL, 
            0x79D9B03645A1A212ULL, 0x1B42D521F13169EDULL, 0x6B28C61314FFEA72ULL, 0x4C5AD14F10B1BB22ULL, 
            0x056E795AC8EFC0A3ULL, 0x1210169BFD99A98EULL, 0x4771EB97CE99137AULL, 0xC1B5415C939E8FB5ULL, 
            0xBCDFE25AD224FEEDULL, 0xFB063B41D5265000ULL, 0x9487BD122C620833ULL, 0x4B5B33EAD76E74D7ULL, 
            0xF904740966980AECULL, 0xDF9FFF3DCCA93A80ULL, 0xBFA155D9024A3A80ULL, 0x31134E88666229D9ULL, 
            0x86D529BF52167D90ULL, 0x7AF4D86C10799ADBULL, 0xBE2F7F961F4B8192ULL, 0xFD3531FF59F1A1CEULL
        },
        {
            0xA4BEC4F1F75D9EAFULL, 0x854DE405F5EB310DULL, 0xBF7FD2A8EBBB76F4ULL, 0x369CFA2E93CA61B7ULL, 
            0xF5E4EB010128ACE4ULL, 0x98922E7485783830ULL, 0xD2C70F898B902B4CULL, 0x7E0D0E9A360707E6ULL, 
            0x2DE34AB8906F7A5FULL, 0x640A4332C764F5C7ULL, 0x3BD02C31B917FD6AULL, 0xB9B7E21923B863EDULL, 
            0xB822F62896793DE9ULL, 0xFA5279D9C517BAE6ULL, 0xA762E8C3B5399413ULL, 0xDB204CDD7B49F803ULL, 
            0xC6F8A0AEDCE3EF6CULL, 0x8C75FFF3BE4B8DC4ULL, 0xE58451697DB690F6ULL, 0xCA2311A4837C2393ULL, 
            0xED9526C6389023CAULL, 0x04020E5ED23D6CD6ULL, 0x74D88C9E9B2C711CULL, 0x03B43C8E026E92CBULL, 
            0x055936DB232F4432ULL, 0x7ABED2091D129676ULL, 0x136C5A8C8712E52CULL, 0x048A9FBBE0D907F7ULL, 
            0xD3AFFD74BF1D0557ULL, 0xEE8E5053FCA1568CULL, 0xD8BBD3A2EF962A7EULL, 0x27C77FF795590EC1ULL
        },
        {
            0x9F532C8822461ED4ULL, 0x2D7B089A8C721FB4ULL, 0x4CD7132445182F80ULL, 0x9B552D63F66136E8ULL, 
            0x0CB821CBBE097866ULL, 0x06456E02AD0623E5ULL, 0xCC63CA7B1B4CF241ULL, 0x9B95355F0D1C72F9ULL, 
            0xC2662C6A68F36D3FULL, 0xD7BE6A9979731207ULL, 0x92EA813028CA0AC6ULL, 0x6A7BE87EE6B1CDEFULL, 
            0x8DDF425170862CF2ULL, 0x871B804DAF421EAAULL, 0xEC2E6BD71994B4D8ULL, 0x660AA88D23A375F5ULL, 
            0xCDE00B4AC4C0A1B2ULL, 0x35559C4EA6298094ULL, 0x61F6745778A639D2ULL, 0x850A76079053409EULL, 
            0x2F18B1C693B4B966ULL, 0xCF7B9A4AAB9D8042ULL, 0x4B7D9F4FD968C489ULL, 0x4363649A8C9F8FF4ULL, 
            0x749A7D646A07B071ULL, 0x46D1ABDB3BDC8EECULL, 0xCBE760126BE9EE0CULL, 0x2005F248AB8612E6ULL, 
            0xA07D9B0A8CA351F0ULL, 0x022522EBE1DF87CAULL, 0x832415D3C76F69BBULL, 0x0FE7BB6B6F315133ULL
        },
        {
            0x03A128A400718A40ULL, 0x9F4DA8CC25D3756DULL, 0x99823EC7AD912EBAULL, 0x2E14E0F4C20AC113ULL, 
            0x90D6E58B424D2268ULL, 0x1934431A1B51D5C1ULL, 0xC5D12D78CF8A2417ULL, 0x777EA8E39F5E675DULL, 
            0xC406E717C8DC143BULL, 0x10C8ACF2890211AAULL, 0x10DFB213EC9333DDULL, 0x14ABCCD7D00BF37AULL, 
            0xDF1847972DD95FFBULL, 0x821BB67AD06D52B8ULL, 0x2FE02CE7D48A1B01ULL, 0x4BC5B024F85D4250ULL, 
            0x87EE503D2B1178A5ULL, 0x5063485D0F6FA8E1ULL, 0x214D5DF57A76A21BULL, 0x46111FD474FBBD62ULL, 
            0xCB98942F04136F71ULL, 0xF71478EC2676A2A1ULL, 0x6E7E7E1BD85708DCULL, 0x193CFA42C91948E1ULL, 
            0x93DA8ABB6E557BF2ULL, 0x2ABCA36E2844DF78ULL, 0x0A99970B924CC244ULL, 0x49183B564155855AULL, 
            0x70536D0D32136DC7ULL, 0xBCAA42766F35B87EULL, 0x75744C912C4263E3ULL, 0x11B3A2FC8431B47EULL
        }
    },
    {
        {
            0xDAAFBA5A5EEF4478ULL, 0x4269184D824C30FBULL, 0x8951407926A1B22EULL, 0x57E115AEB41C5BB9ULL, 
            0x207076BB84D67E19ULL, 0x5363413E6274E9C2ULL, 0x314867837D80A724ULL, 0x3F5994A11DB38EC8ULL, 
            0xDC781551947E1F62ULL, 0x635DE43B1134AEEAULL, 0x3C45A839C74E5F9FULL, 0xAC0BDFFFBB2662F0ULL, 
            0xB39D64A33C754455ULL, 0xFF088A5A988D03F5ULL, 0xABC986BDE63643B7ULL, 0x38499559BC57C4F5ULL, 
            0x5D8C7903E211409FULL, 0x2BBD8CA0892114CDULL, 0xD6C9114EBFBDABE8ULL, 0xA4271A338E41301CULL, 
            0x669EE14415809F3DULL, 0x8862F0FDF39CB335ULL, 0xC62868809B3EBA7CULL, 0x149D280046E527BCULL, 
            0xC09AE5DAD8E4BB29ULL, 0x671230937D448945ULL, 0x104B3A737683E888ULL, 0xC899FE1AC861D0BCULL, 
            0x940D89EE1508725CULL, 0x9A64A9C62047A096ULL, 0xF759CC1A20FB4BB8ULL, 0x6961AD731544A729ULL
        },
        {
            0xDE069EBFBAB75DB1ULL, 0xA57E323931352286ULL, 0x90F3E1C05948D566ULL, 0x4EC67A30BA895146ULL, 
            0x4B77A2B510D77D4EULL, 0x3D77736461FFC312ULL, 0x233A1CD854D9C07BULL, 0x11EE32625FD00D9AULL, 
            0xB1FE615DFF319F50ULL, 0x79629F70D4615B1BULL, 0xFB4C8F220869D71BULL, 0xBE2C98CDD845C730ULL, 
            0x3796803EC1E51677ULL, 0xA461AA948F7027D9ULL, 0x44D8B2632EE7F421ULL, 0x4B5BC4CA2F112E41ULL, 
            0x2B430B39625E14A3ULL, 0x20D049F77AF3E09EULL, 0x16F9C02E913803D9ULL, 0xAB7F1FAEF9E9D417ULL, 
            0x03044BFB75392B03ULL, 0xC7D28D8CB9E41B9DULL, 0x25995F5C517A0BAEULL, 0xECAB791C2B580C6CULL, 
            0x55146E36CBC13BE3ULL, 0x6011569636CE7911ULL, 0xC3B3C2D2DCA107C7ULL, 0x3B621944DFC8A315ULL, 
            0x2A2130AF6B29FC64ULL, 0x96E1F7378E7F038FULL, 0x9937CE3FC3D986E0ULL, 0x295CA202B87DA9ACULL
        },
        {
            0xAB80704AC96E188FULL, 0x44B076DE77A4DFE4ULL, 0x69ABCE748CD26163ULL, 0x48D78132DC6E651BULL, 
            0xF05BF05EF4DEA201ULL, 0xE93E39D6C0FE5474ULL, 0x62243788A05E0C22ULL, 0x881346FF5B5A62C7ULL, 
            0xB42B9ACBD64AB3B5ULL, 0xE13FF82A510223E6ULL, 0x8264740FE81B24A0ULL, 0xD01E9C6F50502CA2ULL, 
            0x7BD43A32EBF03FCEULL, 0x2FEAED3E98D95F8AULL, 0xAD56F60FB03C44C4ULL, 0xE7FE86CD0DC83F5BULL, 
            0xB7F718B220D30E81ULL, 0x093C35324C60F07EULL, 0xB0468B09A76BAC35ULL, 0x6A301C9105F54A5DULL, 
            0x24B8071AAF584D0EULL, 0x2909EF560342E259ULL, 0x61727D072C732437ULL, 0xBBCCC586BFB5F38EULL, 
            0xA7B2D85A8026F46BULL, 0x42A70EF37F53F401ULL, 0xC4F2F319A6AADA3EULL, 0x97480BC1BCA85CA8ULL, 
            0x5ACD1E6C3D9B7306ULL, 0x104AD5B3D572232BULL, 0xECBDD8FB25D994DCULL, 0x010E1DD662272275ULL
        },
        {
            0x2138A1FF78FFB236ULL, 0x3FB74E55D95BD1A0ULL, 0x508416C3FD24498BULL, 0x2B11BCCD94A1849CULL, 
            0x795C7330080C4228ULL, 0x2BC5F35B4BF68696ULL, 0x8203A6C402CEED10ULL, 0x9BD4BC0FB7F3F11DULL, 
            0x4DE2C403B1D56EB3ULL, 0x6115CC30F30FCB74ULL, 0x21ACA7A7D1D19E9AULL, 0xBFFFE4E92525B5A5ULL, 
            0x045E59E65A9A6B38ULL, 0x440201789264D7FFULL, 0xF164E81A2B621D38ULL, 0x10C1827CE7B12E0FULL, 
            0xAAEDC07585E09D5BULL, 0x559D0824B327F90FULL, 0x8A245E1F9E6BD3F5ULL, 0x7A760B7B52B06C3AULL, 
            0xA4A606FB71D474D1ULL, 0x08D88A4528E15327ULL, 0x5DF1227F47ABDA68ULL, 0xF9170F903AF1085FULL, 
            0x373DE2879423E9C7ULL, 0xFB95D89279CC8917ULL, 0x0CCD623001BD849CULL, 0x6D10E0B9FB53000CULL, 
            0x0C680E62DCE4269AULL, 0xD411F81F141B96A0ULL, 0x9C4F87A99A0592C9ULL, 0x7616F99D18F80551ULL
        },
        {
            0xBCF4B421B4410912ULL, 0x5B0DF5649AE4FDBDULL, 0x9860653DC721F32DULL, 0xAF70026D8C95EC79ULL, 
            0xC057C99D6F6F6489ULL, 0x5BCD57BE791C85D1ULL, 0x527931EA3FDB8E24ULL, 0x80C6341E46884160ULL, 
            0x4376FBA47ED72176ULL, 0x7D407BFB8D01C955ULL, 0x7E3014263C8FC1A4ULL, 0xB4E0049C26B164FFULL, 
            0x4875841513DA7560ULL, 0x9B22AF25CA0B8DA8ULL, 0xA138457D823D1A98ULL, 0xDA3F4B9E729074A1ULL, 
            0x9669EFF3F2CB2D30ULL, 0x1E4A5F83BA92E723ULL, 0x71FDE525DD10A28FULL, 0x09DBA13417684B51ULL, 
            0x3E95DB6B482CF928ULL, 0xED0C6BBF88E39448ULL, 0x0A4708E3E4CD123FULL, 0xB6523F52693958E5ULL, 
            0xA03683248D9CAEE6ULL, 0x06E871D4BBF572EEULL, 0x0EAFC35BAE80A5DDULL, 0xCFE6C872DAEA6561ULL, 
            0x23E594D8175F5EF9ULL, 0x4E5AD39C958F7934ULL, 0x7610B4F469E92DB2ULL, 0x653B72F72511AD4EULL
        },
        {
            0x80F3E32E1131C700ULL, 0x6DBC193243013E07ULL, 0x14D71B4D6F483295ULL, 0x944DA97CE85CCFD9ULL, 
            0xF46B89A366F4B72CULL, 0x955ED39EB30403A4ULL, 0x284B01DE62CC3140ULL, 0x16E75E1361FC9A1DULL, 
            0x39F6CDEE9C11329EULL, 0x0748C7DB1C74EC01ULL, 0x6ACB2BE11AAA9A7BULL, 0xDBD51A2757401D7AULL, 
            0x994A99A47A17D0F2ULL, 0x1D033A299A475820ULL, 0x5DC17C49DBA404CAULL, 0xDC04180EEE11DAE2ULL, 
            0xF59C19775793217CULL, 0x4DAA6E2D2AD9ADE0ULL, 0xE9855C09FFD5EF8EULL, 0x62C508DCADBA975EULL, 
            0x210E171B341244E5ULL, 0x80F48DA77D666C88ULL, 0xCAB17FE619531E82ULL, 0x2D0B6B326C4DAC77ULL, 
            0xDC986B2765518EE3ULL, 0x3C59CAD8FD30AF60ULL, 0xD1A33ED323367383ULL, 0xEA59E344D38AD9EAULL, 
            0xE45E340E84ACE6B6ULL, 0xB091BA596321D999ULL, 0x7B29763DE161D0ADULL, 0x67E0FAAF1612206EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseGConstants = {
    0xF724A972D41833A5ULL,
    0x7D38E731B3A7EFE7ULL,
    0x6E1B3F3CEE0FF071ULL,
    0xF724A972D41833A5ULL,
    0x7D38E731B3A7EFE7ULL,
    0x6E1B3F3CEE0FF071ULL,
    0x0AF9AA39E22E2478ULL,
    0x8AEC6650A1727705ULL,
    0x3A,
    0xA8,
    0x53,
    0xAA,
    0x80,
    0x0C,
    0x8E,
    0x41
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseHSalts = {
    {
        {
            0x590CB5E1BD0FB325ULL, 0x0DA7C46F7D8492B1ULL, 0x18405027FE70D29BULL, 0xD32379821D9E0DC8ULL, 
            0xD8F0CFA2BC20A405ULL, 0x9C08CC3EA52FE55CULL, 0x19EE0E708EED6A30ULL, 0x01F8877D7DC3214FULL, 
            0x1FFA86CD44A1F434ULL, 0xC5D09FB56732D425ULL, 0x0130C832656C70A5ULL, 0x63DBAB496D153307ULL, 
            0xD1441C804548C07AULL, 0xB18624BF15B105FBULL, 0x3C50884ACBDDE217ULL, 0x06CAC592E7C69F94ULL, 
            0x4109DB4D09775263ULL, 0xA0CBBC13DA1A8938ULL, 0x24B945E126D2789FULL, 0xB6636944FE6AF682ULL, 
            0xFDB48F781B348FCFULL, 0x7EF4C5893960F579ULL, 0xEBD629F8047489AEULL, 0x2654B2C84A66FF46ULL, 
            0xC8F9EDEA97F4DBEAULL, 0xA909799028401B88ULL, 0xD38D8E20FCBD888DULL, 0x68436FF73EC1AEEAULL, 
            0x88A9B3EBB5DBBE25ULL, 0x38E0FC9E04CED591ULL, 0xE17A9A34C6AA7693ULL, 0x59CE2F4C0308B1E7ULL
        },
        {
            0x90C6F49146B0F47DULL, 0xD735F8FEE89F8E72ULL, 0xDCAAA28402CEA971ULL, 0x0EDCAFB4938AEA4EULL, 
            0xD8FC36F252CACE5EULL, 0x400671C39AE0E07DULL, 0x99ED5C36244CBF33ULL, 0xED9696519F60B9D5ULL, 
            0x01158E427A8C635FULL, 0x78740ACA02EF6236ULL, 0x1EAAE0C5D66BA627ULL, 0x022E89E2E66DD33CULL, 
            0x1877A330011991FEULL, 0xB2672EDE46B71470ULL, 0x78DB1F8FF0256E33ULL, 0x9CED276BA1F3ED92ULL, 
            0x2AA56C55EB2B1BCBULL, 0x10A78FCD2AE6F9B2ULL, 0x35EDB7F73657BEA3ULL, 0xC64BB8F4B6A387FBULL, 
            0x168EB0821A8DE152ULL, 0x8B826BC9B862FDE6ULL, 0x5C68299AA4CA8671ULL, 0xDD656BBF66EDC57CULL, 
            0x2DA56DF27DB6BFD9ULL, 0x8C02CC45FC1FE1B4ULL, 0xF24D2C07F2B9A2E2ULL, 0xB0F82C09454A6B49ULL, 
            0xA5AEA143C9D09E86ULL, 0x0D732A504C37C6B0ULL, 0xDA2E83905A2FAB12ULL, 0x020BC894F0C88C74ULL
        },
        {
            0xA50C203D79B5712AULL, 0x9ECE35F6F21958F8ULL, 0x19D928F04A7AB55CULL, 0x9BB0D0DCC80265FEULL, 
            0x54D4E379C234DA76ULL, 0xF47302CDBEFF3DDFULL, 0xC6838BB6A6EEB151ULL, 0x6EC6621BD864F021ULL, 
            0xCE4930B8E135112DULL, 0x23CAD10616C3ED8FULL, 0x9CF781D99F8C8FFCULL, 0xC421DB95E60447FFULL, 
            0x90122AE2E3A8B0DBULL, 0x40E8AC20AECCAF9EULL, 0x39369A506A776845ULL, 0xC80CBF388A72BAEDULL, 
            0x5D6A0CDDAE3A8080ULL, 0x7F97B5DDC922F7A8ULL, 0xCBE1DA57653A2FE9ULL, 0x81EEFB607D8F1351ULL, 
            0x969F28D525F779D4ULL, 0x77E45D7FC4261EB0ULL, 0x3113DF041C5941B5ULL, 0xC9FB252C86738A43ULL, 
            0x9314903F872A4747ULL, 0x390A93FE4BB7627DULL, 0x914B8D0A1F25D459ULL, 0x5E64FC9405F034ADULL, 
            0x33D021FDC27FD78EULL, 0xFA148EC2DD3C33D1ULL, 0xAB82939690D78867ULL, 0xC250522ECF1B7595ULL
        },
        {
            0xB4CF8FAD963B6E7DULL, 0x3F2C34CF6799CBC9ULL, 0x3B3C8D73934C8C7CULL, 0xD80781A34C52307CULL, 
            0xA4D7A671E5820C72ULL, 0xBBCAA81694AC10EAULL, 0x9E048FBD76FBCEA2ULL, 0x4B0D1398F429B82BULL, 
            0x13A12B23C2D0088EULL, 0x2EED141B894F69F0ULL, 0x72A9EA8921F7FF04ULL, 0x90D720250E42BC50ULL, 
            0x0FFA08EBECEDBFD1ULL, 0xEF96CB0120B94721ULL, 0x98D4A75F9155658DULL, 0x12FE53A4B0890CEDULL, 
            0xC89D789307F6509EULL, 0xDD6D261B6A2ADEA9ULL, 0x0D1232357A40C309ULL, 0x4EF1BADC0371A5BEULL, 
            0x6CED20B669A24C20ULL, 0x054E090EF52E0AF1ULL, 0x63D142D7BFEF51B4ULL, 0x67B82C3908371C0BULL, 
            0x135A52EE883FAD13ULL, 0x96AA29961743DA04ULL, 0xFA19116AB7F7B077ULL, 0x8265A8400B0FA46FULL, 
            0x1574D98197F9A57EULL, 0xD1D1471C9026207AULL, 0x184B98CE543C44A2ULL, 0x1A7875C04A57650BULL
        },
        {
            0x03C7C6151AD95EF2ULL, 0x7DAEB567CE201C46ULL, 0x677F699CE7FD44AEULL, 0x70D60103FDB4F683ULL, 
            0xE59DCFC3D4D0640CULL, 0x2AB5659ABE3A9625ULL, 0x0F82F2405A870CE0ULL, 0x9A1C3C9F7F04C979ULL, 
            0x170BC94EA1FFCA86ULL, 0x0CBCC4D8A7DD3CDDULL, 0xCEC42408068434A5ULL, 0x1D7DA36C9330AF72ULL, 
            0x2401724007EAF1B9ULL, 0xD8515DDE8DFF574AULL, 0x61ECE4108B56E1A0ULL, 0xC222699B509B689BULL, 
            0xD96ECFBA881E8B1CULL, 0x2B25677BDD503622ULL, 0xE664FFC28C3076EFULL, 0xC63D526E5248CB68ULL, 
            0xB37A01FD06DCC503ULL, 0x55258E52515870B0ULL, 0xE5BDBAE154B4C68DULL, 0x2E45B454F8C57B09ULL, 
            0xF59EBDFAD980D79DULL, 0x87D1C36A8B22B0CAULL, 0x28E0D597280EBC3EULL, 0xCAE2D757200F3118ULL, 
            0x52D28CECFC217F22ULL, 0x54CD3504274B270DULL, 0x27559883839D6687ULL, 0x40D996BCBC8FA0F5ULL
        },
        {
            0x3B2890656F9DF4C0ULL, 0x0C654413ED8832D4ULL, 0xCFB82C86C881F355ULL, 0x91B63B5A34783365ULL, 
            0xA87ECB26A9AECDF9ULL, 0x14A7E6F4FB333C56ULL, 0xDCE1F5361ABAE6EFULL, 0xBD2D8858F3D7C288ULL, 
            0x110B24A6DC8A2C95ULL, 0x293BC27FE4F7A9AEULL, 0xAE9AC271134A1F37ULL, 0x3A4C74DCDC736F5CULL, 
            0x99AA89B2DF712E5AULL, 0xEADF5BECBB93D83EULL, 0x4AB106D8CC5041A2ULL, 0x4AA4E0EB8E4FC2A9ULL, 
            0x71753438B1918B7AULL, 0xC207C6B7D7E161CEULL, 0x20C76FD25621B197ULL, 0xE396AEBF239E376BULL, 
            0xBF19DFBB3E86C670ULL, 0xA62BD1B01E6D5846ULL, 0x0ECF6234A58CBCCBULL, 0xDB0B9C77DFE3BE94ULL, 
            0x4FB7D246DE2FB007ULL, 0x4DE5FBB2E5327CD2ULL, 0xD13D10524CB88B8CULL, 0x8AE5DA07A50C3639ULL, 
            0x0CFEFAE5CF99C80BULL, 0xF92F1E1EE1F01312ULL, 0xE4017F887A3B301AULL, 0x8E0092640258C406ULL
        }
    },
    {
        {
            0x1C60853334C7CC9CULL, 0xABD94A141587191FULL, 0xFF606D1D165B7EFCULL, 0x4ECEA4E8B8A4CB94ULL, 
            0x72DA36E771980636ULL, 0xD6D92E60F7D1D5E6ULL, 0x20074FB778D4DC4CULL, 0x33C3325DBCFC9FCDULL, 
            0x2D42435C3E1FEFDCULL, 0x7E3B045B4AC0D05AULL, 0xA4D2429CCDCCF4C9ULL, 0x585D201542F6D75AULL, 
            0x96B16F2FE5B99AFAULL, 0x91C367F9497B85FEULL, 0xC69B133EA53BE5F6ULL, 0x732991954D060CF0ULL, 
            0xFC7F38F57E49E411ULL, 0xA247CCADE106EED5ULL, 0x81D5569452273348ULL, 0xFF129A469F1DB3E2ULL, 
            0x76B63C2D5AE8EE36ULL, 0x35EE50CFA3A27B12ULL, 0x14ADDC22B558C01AULL, 0x9BA7BE5CF5C13F24ULL, 
            0xB962A53570A44D6FULL, 0xEF689A6E26E0C227ULL, 0x7D0486C1C365A1A9ULL, 0xC62A0557403AE91EULL, 
            0x833A78B8BF0245FCULL, 0x7D38E53A227FDC3DULL, 0x1BA90418145FCB83ULL, 0x1417D2BDC9148142ULL
        },
        {
            0x7836478EF3EF3AC5ULL, 0xE15381D6FE1D9D02ULL, 0xC769A148F020479AULL, 0xE9C5AD1EAC669AB5ULL, 
            0xA1FAE48854299E59ULL, 0x99B0FF1FB2CFDC18ULL, 0x3286722B4850DF94ULL, 0x1BA82BD8B982CA98ULL, 
            0x1DD1E42CC13786F4ULL, 0x9E95C04FD73FBD81ULL, 0x48957A43A7BC3325ULL, 0x890E9D7D8B04A206ULL, 
            0x580E36DC6296832CULL, 0x0E2695DBE6A2CED1ULL, 0x6634FC659C4FB69EULL, 0xF433AA3CA21F9BE3ULL, 
            0xE19838C9107D13E6ULL, 0x48F48C84DB4A30C2ULL, 0x823E9C13D977C241ULL, 0xB7C6927B6D8EB08EULL, 
            0xB13B97018B9603FEULL, 0x1727D60BDB56F842ULL, 0x4F976878B7D0EF8CULL, 0xE28E49100C2A1480ULL, 
            0x46C1CC2A80108407ULL, 0x6060177ABEFD4E26ULL, 0x1670D6554FEC5F0FULL, 0x45D7BD371D436B08ULL, 
            0x86FB8FA6A3E8364CULL, 0xD5D1520889EE18E7ULL, 0xAA9E60472CE25593ULL, 0xF1C55B2C3EAABD11ULL
        },
        {
            0x2501D59611E2CDC0ULL, 0x4994F3C324F92A7AULL, 0x50824754F01B1BD1ULL, 0xA9D72E2C75615C1EULL, 
            0x3C2584ACDEAFF1CBULL, 0xE22FA3D3432E5806ULL, 0xBF2301B56E6147DCULL, 0x5E15B4352993971BULL, 
            0x7DB0252869A8A9EFULL, 0x8932758820FEC0F4ULL, 0x74E6999C7F8275ECULL, 0x9CCD53AF9161E4BCULL, 
            0xC08F0C6EB76C6CBCULL, 0xE11EBB3F7BBB4962ULL, 0x476A44C38375CE97ULL, 0x6A13C9EEF0B25361ULL, 
            0xD2D415EE66B27100ULL, 0x260FAE445783B9EBULL, 0x40F293B4763215DAULL, 0xFB7E508DF44C0046ULL, 
            0x971D03C4570D87DCULL, 0xF6EEDFD9A5D27BB1ULL, 0x3C9F522E7A0F684FULL, 0xAFBC0171329F1343ULL, 
            0xCB08BC5ADAC2750DULL, 0x54410456333BBCA8ULL, 0x91986EEE927721EFULL, 0x3EAAD54E4851C0BBULL, 
            0x723A080E9600F6EBULL, 0xBD25D01676BA8CADULL, 0x16E07AEA8191393DULL, 0xDB5ACFE25F6B5D5CULL
        },
        {
            0xAC5FE2E8975B9A5FULL, 0xDBB19974C1A67E7AULL, 0x682055FAC6F7C956ULL, 0xBB489D5F1914A4F6ULL, 
            0x02D4DC3D592FC9ECULL, 0xD3E2F789810E773DULL, 0x26B6D108F782E6F3ULL, 0x585093C500FD8A5DULL, 
            0xBED57BDB857944C9ULL, 0x4FFEE4B4958B978BULL, 0xADA910B315710369ULL, 0x11AACC75E3E457FFULL, 
            0x4681870DEEF6E45BULL, 0xBC9F5D2D0145E029ULL, 0x4607C8B13F185D14ULL, 0x3933EA1C36DE63D0ULL, 
            0xA53D8972B3FC9E09ULL, 0xE1E8699055A71F69ULL, 0x55B60BAE24DC1679ULL, 0x92CA4831B72605E3ULL, 
            0x6690DDA36EE90633ULL, 0xCB69BF4474452ED5ULL, 0xB56C3BCAE3F64B70ULL, 0x4B6CFAE54EC3BF7BULL, 
            0x6801AD3A72414D0BULL, 0x02AC1E0DD3A3DD73ULL, 0xC36671FD45FF7BDCULL, 0x764710F146F116E7ULL, 
            0xC45FCF199F15EBEDULL, 0xC55B625A828D02E3ULL, 0x76393354FF4583F0ULL, 0xE835283D2D414547ULL
        },
        {
            0x9EBE8B7B7AF62619ULL, 0x1A7611EC79EB5AF6ULL, 0x4CADE36D89629AE8ULL, 0x779FB18EE0FE6105ULL, 
            0x5D12F00BAACD7CC6ULL, 0x7F2867F7855693A1ULL, 0x78085BE1A2C927DFULL, 0x699F176D3FD6DFA1ULL, 
            0x088603A2673AC1D4ULL, 0x2C4F48BDB16E6619ULL, 0x4950837617ACFCDEULL, 0x5B6AAAF525661E8DULL, 
            0xB982C1DF9C0E9D96ULL, 0x7764F432E9E8978EULL, 0x49B604938ECE518AULL, 0xFDAD80BB81F11A9DULL, 
            0x84F0CDF66595DD52ULL, 0xB3E995F6C3C34EECULL, 0x14B6B32D25DDBAA6ULL, 0xDAA91416039913D3ULL, 
            0xDA8048319D79D2A9ULL, 0xEDC7C5BCBA730E22ULL, 0xF526AE89CEA51AE7ULL, 0x0AFBD0194024AC50ULL, 
            0xAAB4D4E93B9D4375ULL, 0x599FE81C09E580F0ULL, 0x12A1EF764BE25B37ULL, 0xC1D0A190061E8D65ULL, 
            0xEF1DD2D4EEF22B12ULL, 0x216FD352E67CD73CULL, 0x02BF1F2A8FF083D0ULL, 0x067160CA89F439CBULL
        },
        {
            0x15213F50BBEF47DBULL, 0xB9AF39E533F4F04DULL, 0xC1EA7CB043CAE2FDULL, 0x817C580EBBD0D229ULL, 
            0x7649E105634C6212ULL, 0x50F80A5D17C18DD9ULL, 0xA6F7FBABBE6DC1EBULL, 0x27EE1C34CAFCBC0EULL, 
            0xF3180EA493DE5CC2ULL, 0xE8E67C23CEEA82AEULL, 0x14A49D70944BC321ULL, 0x876F69915864EA1CULL, 
            0x822DCFC70BB92FC1ULL, 0xA7B45CA58E403C13ULL, 0x13AA1C322CFECDB9ULL, 0x346798B7761AA398ULL, 
            0x295812CD93B838E2ULL, 0x245B14D139F456B3ULL, 0xC5167449ECD44372ULL, 0xE82CB9DB7A9F1726ULL, 
            0x32CA649CB5A66F14ULL, 0x21D04E9792AA2FAEULL, 0x2453BA6B9FCC29F3ULL, 0xCED15AC2E305CCC9ULL, 
            0xBA6B565EFC9F8A1BULL, 0xEECDAEEADBC24447ULL, 0x6B162CF3AD952C6EULL, 0x07A94109B78A7955ULL, 
            0x05FF031746E73F93ULL, 0x352CCFA356B9E01CULL, 0x2DBC358BA56670D6ULL, 0x365089C7990151C3ULL
        }
    },
    {
        {
            0xB10355BC2E5AA825ULL, 0xDCA71D2C3A9AD955ULL, 0xC7E845887D4A2451ULL, 0x543503FB204CF747ULL, 
            0xC7D1AB17BE732855ULL, 0xC7F3F704F0E95D21ULL, 0xBF92F23F8B285366ULL, 0x97A825CB04555CEBULL, 
            0x64D09B51B0870C17ULL, 0x7E5F2423227E7E61ULL, 0xB361BEE335EE4638ULL, 0x86FE05B03F4B6D0FULL, 
            0xC7F3084B8BBD13ACULL, 0x9F74A62290ED48C3ULL, 0xD6EAF4BAA844E522ULL, 0x9CB33B78350F668DULL, 
            0x8BC2C7137DECC54BULL, 0xD4CBD3F9BAE5F0EFULL, 0x860084D047B0ADA7ULL, 0x307D81AE30C75628ULL, 
            0x853FCE21D8114945ULL, 0xDF6D845905284B59ULL, 0x2611D68C4145F758ULL, 0x11F2F1FAB7EA7BE5ULL, 
            0x2A74A1B291C4C113ULL, 0x1BB337D43B1E15EAULL, 0x5B1D56A405A1F658ULL, 0x7D0E02B491C3CE45ULL, 
            0xE6A0DF4B2E88102BULL, 0x82EF510547CFB789ULL, 0x7BEBDC97E8B0D5FBULL, 0xD4AAD105EDF9C11FULL
        },
        {
            0xC18F0D8B76C27D0FULL, 0x562DC579867598ADULL, 0xB7399FC4AB469DFDULL, 0x66CF0C50FF489CE2ULL, 
            0xB5F3F2A8DD7C57FDULL, 0xA9BC079FA7925C1AULL, 0xFFF64C5508C0D587ULL, 0xF4E8DAD664FFF5E2ULL, 
            0x451EEFC9B77D0444ULL, 0xFCB5AB0F56AAC0B6ULL, 0x6BF96F43E44E9EC1ULL, 0xFF6AFF8BFA2D63BDULL, 
            0xA5294BA75C265D9CULL, 0x1EB755C5E40C59FFULL, 0x88DBC23A7502E88DULL, 0x9A232BB2669458F5ULL, 
            0x292D87EE426B7574ULL, 0x189D7DD9AAF25E0EULL, 0x6342A57527FEB1E8ULL, 0x20E3B46302AADACDULL, 
            0x980B913AB190CBF0ULL, 0x99B9768933B33C05ULL, 0x2C5D40139C406A87ULL, 0x4CC2B1F14590F273ULL, 
            0xF961D4AFAC3DFDA0ULL, 0x8C1EE981A49F2762ULL, 0x9A02D03E137B5716ULL, 0x11037F9A252A2123ULL, 
            0x731C48A56D4DF57CULL, 0xF12161C0DD8A3838ULL, 0x2A4919887029B2CFULL, 0x947ADF53DC7606ECULL
        },
        {
            0x281372F6A6517539ULL, 0x5F6AD60A4A12C663ULL, 0x0E9FDE869C2B147BULL, 0xEA5C90ECC56440EDULL, 
            0xBC10383F1D8EA0F8ULL, 0x6B098E0F24B769C3ULL, 0x11C7FDFFDD78A671ULL, 0xCFC093977684C4DEULL, 
            0xD28AC9D832409EDBULL, 0x7E7A043C8044E179ULL, 0x5B45514749D1ABD5ULL, 0x77AE1E6881CE63B0ULL, 
            0xE37CC2FD05B47521ULL, 0xBE4E93AE3501A0C7ULL, 0x78FF1466F6FA2440ULL, 0xD52DF85A6557EE42ULL, 
            0xDED84C14C4A8097BULL, 0xBA0418607133CE2CULL, 0x3238A3ACEE6D350DULL, 0x32D3DA4698FF5D34ULL, 
            0x5CD92D792E48AA6FULL, 0x3FC76E21BDEE19C7ULL, 0xB667D3C750363B33ULL, 0xBE0B980C1560AF12ULL, 
            0xB3BA26F98B45AB04ULL, 0xFDC934AF635B459CULL, 0xBFED507A64953E6DULL, 0x5688B5A9554BF8D1ULL, 
            0x247683AFB1C0B5C3ULL, 0x61DC697988D0AFABULL, 0x33FEB3BF5F4756A5ULL, 0x0C0830AEB1554B6FULL
        },
        {
            0xE797C015A1CE37C3ULL, 0x77D7A956FDA46060ULL, 0x9C83015F5447A152ULL, 0x3B98F85799F55D7BULL, 
            0x222C176B422EE5EAULL, 0x2A7F164B77EE1947ULL, 0x7107A98EB2AC4F62ULL, 0x64360CB181FD9B5AULL, 
            0x66FF0FE449912015ULL, 0xCE98E28B2CEC64E8ULL, 0x3FABD9C4689F645CULL, 0x76B976841951B8ECULL, 
            0xEFD7CF2AF59464E4ULL, 0xE90765B3A45CDE05ULL, 0xBEDD9CBFE9033C30ULL, 0x7DB2BA4107DA4796ULL, 
            0x8F120A41317171CBULL, 0x5D0F6415A4CE18A5ULL, 0xAB8D27255EF54615ULL, 0x4F339E219B58EB89ULL, 
            0xAA125C83750758A8ULL, 0x60017331DCE0F8F7ULL, 0xA19A920A900C5DDDULL, 0xA54E40D1F4B4B1F1ULL, 
            0xB0E66A4E84FC8249ULL, 0x1A713C0AD2DE58F4ULL, 0xD394DEC35AEC80A8ULL, 0x947C215DFFB760B8ULL, 
            0xB211CE798651F33EULL, 0x24663D4881DA4173ULL, 0x881FAECC1355981BULL, 0x3293133FC06BF2BBULL
        },
        {
            0x025FA8ADF8E403E3ULL, 0x2AF93461F0D8674DULL, 0x81EA2C6EB83780C3ULL, 0xE6F39D11A7CF83F6ULL, 
            0xA977428F1D930576ULL, 0x16DD48AF675C1EC1ULL, 0x442160EFF9F89A2FULL, 0x1E85864832C54B07ULL, 
            0xC214302504417C98ULL, 0x912092A321CCC472ULL, 0x60A9BF8287F7D0BDULL, 0xFAEF02FC4A672F9DULL, 
            0x41B29BAD39B364B9ULL, 0x7DBABAEE791F3D77ULL, 0x4E4EB40844974A7BULL, 0xA80047B266F1CC08ULL, 
            0x22FF781F26AA3611ULL, 0x880D8E6A081D5008ULL, 0xE9A9F460C8BA1E5FULL, 0x269CF80C8A2577D2ULL, 
            0x736622C9ADC4FBB5ULL, 0xF11730FEBF5C8AE9ULL, 0x2A160CE4BFB05F5CULL, 0xEA686B680D656E1FULL, 
            0x503CA3BE9EE763A0ULL, 0x035B5E3A2DA81AEAULL, 0x4324F9B8C8D737C4ULL, 0xBE804956FBF24C00ULL, 
            0x70780EF18D908D04ULL, 0x1A4B212353E1FE1DULL, 0xB685E64AFAFF604AULL, 0xB14E4607ABF13C61ULL
        },
        {
            0x91D758B97709BFBFULL, 0xC6A1048FE9724885ULL, 0x6FAD05FAB711E514ULL, 0xBCFB73E31586D3CAULL, 
            0x842F2C283FEAFCA2ULL, 0xA70F55C5D43C697FULL, 0x316E8267FB870D3DULL, 0x4D7122A1B4335254ULL, 
            0x3EBA2BE97E4B4D87ULL, 0x85B841BE77FBD570ULL, 0xB9F906A7255E1CB7ULL, 0xEDE8190B1EE0CEFAULL, 
            0xF508DF1FCC83AE20ULL, 0xAC3FFB0814ED8777ULL, 0x45F866D107332C00ULL, 0xCD605E27030F6225ULL, 
            0x8A1B476C97B76E0DULL, 0x0C4952AFC922630DULL, 0x1E2679B178875949ULL, 0x7535E822B1A7516FULL, 
            0x5722D27070C10CEEULL, 0xAD2F80DD74AFB79CULL, 0x48B89FFDB24DB44CULL, 0x1339A3E336761F2CULL, 
            0x1E5538BC9D286335ULL, 0x84FC801677C28234ULL, 0x663FC27D6088B53DULL, 0x4426EB1B67A04C14ULL, 
            0x279C4421FB6D113BULL, 0x1AFBEACEE72256B0ULL, 0x1692B623FDBD19C9ULL, 0x60E4D55DE73039A2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseHConstants = {
    0x823BF919B1A2BFD4ULL,
    0xEBAE52E53940398BULL,
    0x9EED4376EB49191AULL,
    0x823BF919B1A2BFD4ULL,
    0xEBAE52E53940398BULL,
    0x9EED4376EB49191AULL,
    0x093DF7EC222417E5ULL,
    0x2505958E7BCFA826ULL,
    0x94,
    0x6B,
    0x27,
    0x98,
    0xDA,
    0x20,
    0x4E,
    0xA8
};

