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
                                  std::uint8_t *pSnow,
                                  int pIndexKDF) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet, pSnow, pIndexKDF);
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
    std::uint64_t aPrevious = 0xC7817B31F7E76CF5ULL; std::uint64_t aIngress = 0xE604A4F0A81A0D65ULL; std::uint64_t aCarry = 0xD0ECA4202346FDB8ULL;

    std::uint64_t aWandererA = 0xF39F615C061B5360ULL; std::uint64_t aWandererB = 0xE33867AA1446C881ULL; std::uint64_t aWandererC = 0x997E27CDDD10C71BULL; std::uint64_t aWandererD = 0x9EADCC6C2E077BC3ULL;
    std::uint64_t aWandererE = 0xE872F2E67DDF8779ULL; std::uint64_t aWandererF = 0x96FD6D967B85E055ULL; std::uint64_t aWandererG = 0x871E1684955B2CF4ULL; std::uint64_t aWandererH = 0x94A27DEBDA9F3680ULL;
    std::uint64_t aWandererI = 0xF56CCDD700E784EDULL; std::uint64_t aWandererJ = 0xAA63092D225C3C0DULL; std::uint64_t aWandererK = 0xC04955856BDD228AULL;

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
        aPrevious = 10499922825496215811U;
        aCarry = 11193713434479527254U;
        aWandererA = 15838055613999098069U;
        aWandererB = 15361552003628093702U;
        aWandererC = 12232381619941001819U;
        aWandererD = 12061478114145571179U;
        aWandererE = 9897797989152738163U;
        aWandererF = 12683029386218924153U;
        aWandererG = 10669709958370702188U;
        aWandererH = 15330570576484288745U;
        aWandererI = 17948999278238754180U;
        aWandererJ = 9820449473263500497U;
        aWandererK = 16368593350711603941U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: fire_a, fire_b
    // ---------------------------------------------------
    // write to: fire_a, fire_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::KDF_A_A(pWorkSpace,
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
    // temp storage: fire_c, fire_d
    // ---------------------------------------------------
    // write to: fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::KDF_A_B(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::KDF_A_C(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::KDF_A_D(pWorkSpace,
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
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  int pIndexKDF) {
    TwistExpander::KDF_B(pNonce, pConstants, pDomainSaltSet, pIndexKDF);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
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
    std::uint64_t aPrevious = 0xB43ADAD4C89F7335ULL; std::uint64_t aIngress = 0xA1064770354A9A3EULL; std::uint64_t aCarry = 0xA096D1C3AE7D88FEULL;

    std::uint64_t aWandererA = 0xEEAD9A9B2C2248A6ULL; std::uint64_t aWandererB = 0x9F8B6CC22B50AFF5ULL; std::uint64_t aWandererC = 0xA0CAEA95E18601D0ULL; std::uint64_t aWandererD = 0xE4DF6ECB78AFC33EULL;
    std::uint64_t aWandererE = 0xE9091105C191604BULL; std::uint64_t aWandererF = 0xBB1615EF7E1E2223ULL; std::uint64_t aWandererG = 0x9CF4D4A3BC0E1B08ULL; std::uint64_t aWandererH = 0x86E6E7711E230ED2ULL;
    std::uint64_t aWandererI = 0xA7954E228B8B6571ULL; std::uint64_t aWandererJ = 0x9ACC110A7066D1DDULL; std::uint64_t aWandererK = 0xA49D7906B6432A17ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
    {
        aPrevious = 11060790838952259657U;
        aCarry = 11913738380150142273U;
        aWandererA = 15452641669405175792U;
        aWandererB = 17814364881358536697U;
        aWandererC = 13661628925506163977U;
        aWandererD = 9627562395089425657U;
        aWandererE = 18314260775145267689U;
        aWandererF = 13500511392483955277U;
        aWandererG = 10627283754302523659U;
        aWandererH = 9691880742736423280U;
        aWandererI = 10909513378938612519U;
        aWandererJ = 12754014649970663555U;
        aWandererK = 10391961869871848169U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::KDF_B_A(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::KDF_B_B(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::KDF_B_C(pWorkSpace,
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
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneA, aExpandLaneB,  // input lanes
                         aWorkLaneA, aWorkLaneB, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneC, aExpandLaneD,  // input lanes
                         aWorkLaneC, aWorkLaneD, // output lanes
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
    // KDF_B_D kdf_b_loop_d:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::KDF_B_D(pWorkSpace,
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
    std::uint64_t aPrevious = 0xDFEF6B2FE458E222ULL;
    std::uint64_t aIngress = 0x84F5E4C8F82CA44BULL;
    std::uint64_t aCarry = 0xF19391B62C0B8386ULL;

    std::uint64_t aWandererA = 0xF885852CBCD2E6A9ULL;
    std::uint64_t aWandererB = 0x845C9CDF4DE3F01DULL;
    std::uint64_t aWandererC = 0xDDE947561CA4DA2FULL;
    std::uint64_t aWandererD = 0xA61E544D7FDD0256ULL;
    std::uint64_t aWandererE = 0xBB38EF7A53B80AB2ULL;
    std::uint64_t aWandererF = 0x9D0ECE926513B1E5ULL;
    std::uint64_t aWandererG = 0x8FCFAD21745B4B7FULL;
    std::uint64_t aWandererH = 0xE1A28F8474C89C85ULL;
    std::uint64_t aWandererI = 0xCEBEFDE79F321DAFULL;
    std::uint64_t aWandererJ = 0xBCC527A0C6DF195EULL;
    std::uint64_t aWandererK = 0xEFFD5C21BF762D7DULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB, 1);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC, 2);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA, 3);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB, 5);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC, 6);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::Seed_A(pWorkSpace,
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
    // GSeedRunSeed_B seed_loop_a:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: invest_a, invest_b, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::Seed_B(pWorkSpace,
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
    // GSeedRunSeed_C seed_loop_b:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::Seed_C(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::Seed_D(pWorkSpace,
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
    // read from: invest_a, invest_b, invest_c, invest_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::Seed_E(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::Seed_F(pWorkSpace,
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

    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgD;
    //
    {
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneA, aExpandLaneB,  // input lanes
                         aSnowLaneA, aSnowLaneB, // output lanes
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
                         aSnowLaneC, aSnowLaneD, // output lanes
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
    // GSeedRunSeed_G seed_loop_h:
    // ---------------------------------------------------
    // read from: snow_a, snow_b, snow_c, snow_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::GROW_B(pWorkSpace,
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_BaseBall::TwistBlock(TwistWorkSpace *pWorkSpace,
                                       std::uint64_t pNonce,
                                       std::uint8_t *pSource,
                                       std::size_t pBlockIndex,
                                       std::size_t pBlockCount,
                                       std::uint8_t *pDestination) {
    TwistExpander::TwistBlock(pWorkSpace, pNonce, pSource, pBlockIndex, pBlockCount, pDestination);
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    std::uint64_t aPrevious = 0xBD9FF38299C1A66EULL; std::uint64_t aIngress = 0xF544A6007626F491ULL; std::uint64_t aCarry = 0xDA4BA64DDC3508DBULL;

    std::uint64_t aWandererA = 0xE4C843B60F0A4B4DULL; std::uint64_t aWandererB = 0x9744BA79506A42D4ULL; std::uint64_t aWandererC = 0xB3BDA023F8481FDDULL; std::uint64_t aWandererD = 0xE65EF9991E97D5DAULL;
    std::uint64_t aWandererE = 0xDB18AF47CF802984ULL; std::uint64_t aWandererF = 0xAC146A6763135A5FULL; std::uint64_t aWandererG = 0x8233EB9CC4AB4362ULL; std::uint64_t aWandererH = 0xA13A86506C2579CDULL;
    std::uint64_t aWandererI = 0x8AD019DB91774A54ULL; std::uint64_t aWandererJ = 0xDF8510C36C13CC41ULL; std::uint64_t aWandererK = 0x951647E9CE7E097AULL;

    // [seed]
    {
        aPrevious = 17847668010479416184U;
        aCarry = 12159428643876442809U;
        aWandererA = 16255076102457785948U;
        aWandererB = 13363374425292660409U;
        aWandererC = 17758835105593785614U;
        aWandererD = 14047688700496762309U;
        aWandererE = 15991874347661990878U;
        aWandererF = 15893376590226588005U;
        aWandererG = 9264684725508808966U;
        aWandererH = 11647971986324193941U;
        aWandererI = 14778930053163961929U;
        aWandererJ = 15457220162485283988U;
        aWandererK = 17986275928796555341U;
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::Twist_A(pWorkSpace,
                 pSource,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::Twist_B(pWorkSpace,
                 pSource,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_BaseBall_Arx::Twist_C(pWorkSpace,
                 pSource,
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
        TwistExpander_BaseBall_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_BaseBall_Arx::GROW_B(pWorkSpace,
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
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 3, 3 with offsets 2535U, 5513U, 3456U, 7017U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2535U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5513U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3456U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7017U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 1, 1 with offsets 646U, 6863U, 3154U, 841U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 646U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6863U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3154U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 841U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 2, 0 with offsets 6543U, 1225U, 3775U, 3045U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6543U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1225U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3775U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3045U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 0, 2 with offsets 3766U, 1841U, 2542U, 336U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3766U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1841U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2542U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 336U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 1, 2 with offsets 1851U, 1778U, 699U, 1554U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1851U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1778U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 699U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1554U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 2, 3, 1 with offsets 435U, 869U, 183U, 1622U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 435U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 869U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1622U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 1, 2, 0 with offsets 235U, 972U, 1871U, 1437U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 235U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 972U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1437U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 2, 0 with offsets 1315U, 292U, 1671U, 451U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1315U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 292U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1671U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 451U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 320U, 538U, 482U, 1041U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 320U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 538U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 482U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1041U) & W_KEY1;
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 2, 1 with offsets 2719U, 7413U, 6646U, 7517U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2719U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7413U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6646U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7517U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 0 with offsets 4887U, 1755U, 5821U, 6090U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4887U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1755U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5821U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6090U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 2 with offsets 4217U, 2709U, 5650U, 7464U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4217U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2709U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5650U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7464U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 1, 3 with offsets 190U, 4587U, 1395U, 6868U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 190U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4587U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1395U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6868U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3754U, 5484U, 7050U, 3988U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3754U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5484U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7050U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3988U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1688U, 88U, 130U, 1131U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1688U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 88U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 130U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1131U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1327U, 1669U, 1352U, 1562U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1327U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1352U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1562U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1482U, 1694U, 1171U, 1004U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1482U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1694U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1171U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1004U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1440U, 93U, 864U, 414U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1440U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 864U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 414U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 2, 3 [0..<W_KEY]
        // offsets: 1270U, 1615U, 1229U, 226U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1270U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1615U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1229U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 226U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseASalts = {
    {
        {
            0x2ACCF42CEA418A8DULL, 0x18CF3C4E7E7DF587ULL, 0x583AC54348728D98ULL, 0xC9E37BDB71FD2209ULL, 
            0x00157AAFE345BAE0ULL, 0x6B5FCFD62F566104ULL, 0x64C8069BF0F7DEA4ULL, 0xA68BEBB8F69307BFULL, 
            0xE5B876DE1DF864B7ULL, 0x81085CB2DEB11B1EULL, 0xFE2FD1BB820A0720ULL, 0xA28342A620580C33ULL, 
            0xD187F1C03B460E34ULL, 0xF038902A77D0CB87ULL, 0xD9B1B6157BC97397ULL, 0xE8DC31F43561FDE5ULL, 
            0x78BA00E362AC6C75ULL, 0xC9D41244C654BC26ULL, 0x55CB1D9DAE03D3BFULL, 0xD6F5E09F9356C7F3ULL, 
            0xD62D2F73F13BA24AULL, 0x87922B251F249116ULL, 0xD6BAA6F86ABC1293ULL, 0x4EE2530DE5382B3EULL, 
            0x84B42AEAA61B6659ULL, 0x03619BFF15D5BE9EULL, 0x477E8AF8FCFAF842ULL, 0xD5E8499A4F2EEBAEULL, 
            0xCBA827C6130F819DULL, 0xD91C0499F944DEF8ULL, 0x1D95B7BEF9A67FACULL, 0xDDF383D35E40C31FULL
        },
        {
            0xEE65D2DEE45F773AULL, 0x2AD72C3D10E89F32ULL, 0xE086CAD0DF8B06A2ULL, 0x0246A64700514B44ULL, 
            0xC770C28E92CBAB8EULL, 0xFA6B4DC166FE0A72ULL, 0xF3CE06701CE9B7BAULL, 0x9D0655A7E6E61672ULL, 
            0x94FFC9B662CEA5DAULL, 0x38BBC4B75A0EDFEBULL, 0x34F3F04BAA5C9595ULL, 0xFF54731394CA096EULL, 
            0x04F22AA8242F0056ULL, 0xC03B4BB1FFDA550FULL, 0xE86750FCA6A06907ULL, 0xA33C0DF3B75520A0ULL, 
            0x25402B378F38EF61ULL, 0xCD0CCDF1697B4B83ULL, 0x14F8A7D6ADD203C1ULL, 0x9009FBDE5AABB1DDULL, 
            0xCA6778B3A756FBAAULL, 0xD5132588F6AB96DAULL, 0x7A6D2883B1D3B2B0ULL, 0x365C68793AF1F795ULL, 
            0xE97704B31EA60CF3ULL, 0x5A94D7472540BD6BULL, 0x7084676D970F81F5ULL, 0x45A6657263A0083AULL, 
            0xC44C26B5273D518CULL, 0xC34E0CE82E17459BULL, 0x80BEA00F4905AC27ULL, 0x996F7704E37D4696ULL
        },
        {
            0xAF6B28E8D9EBF302ULL, 0x8F8F3C585985463FULL, 0xB4AE4ACE5DCD4873ULL, 0x3E3165F7984DC83EULL, 
            0x433A79C2163F9F6BULL, 0xFE3BC5B0DF32E90CULL, 0x98FDE3B856213BA5ULL, 0x124EBBB47C61475DULL, 
            0xCC81B3E5F50C4362ULL, 0xAE314410F5895B16ULL, 0x4AFEF2E66585AF97ULL, 0x3C2244D800A40F8AULL, 
            0xC2C9431564252657ULL, 0x9C80701BC9965D38ULL, 0xF68796F1B219EE77ULL, 0x9873725BA963B510ULL, 
            0x474CB22B77959924ULL, 0x5EFFA1DF9D211DDCULL, 0x02249E3E3720E8FFULL, 0xEE3EBDA1B85C2717ULL, 
            0xCA34800F7FA8AE76ULL, 0x8606196790597271ULL, 0x972C9D23384E85F2ULL, 0x697D8A4A1E02A3B4ULL, 
            0xE8C58C4CB5D3C086ULL, 0x17BD3E44218B8347ULL, 0xA3914A1FE0B22341ULL, 0x493FFD98EC40EF2DULL, 
            0xF64525397A085EDDULL, 0xFE789FD642A008ACULL, 0x6510D07DC19FC930ULL, 0xA3D3C63E020C389CULL
        },
        {
            0xFCAE5CC278B936FFULL, 0x8F4573006535600FULL, 0x187781890790E18EULL, 0x0B4FBE981878D8A9ULL, 
            0x4DF986926B56BDA8ULL, 0x08E3E4256CEC59E8ULL, 0x5FA8905BAC4F617EULL, 0x46B3052A4CD84EBAULL, 
            0x3DD4A14A8AEC9CE4ULL, 0xC41D9791AFDD9D87ULL, 0x71FCA785496B5A88ULL, 0x35189821B3A8ACB4ULL, 
            0x2072806021A44178ULL, 0x4BC72FB21CF4C407ULL, 0xAAB049CA0CD58CE6ULL, 0xAD7C9D093D555B58ULL, 
            0x9082C1CD0382266EULL, 0xFD69FE81353D62B5ULL, 0x473EB3B19557A656ULL, 0xDC61C298001E26CCULL, 
            0x9DCB4AE8A6CFD58DULL, 0x866BCFE7BBC25639ULL, 0xAA04AC9C3B07FCC9ULL, 0x7E38A4897065E03AULL, 
            0xF692B2DD13E60BB2ULL, 0x676DCEFAEB95624FULL, 0xC07C288BDC47166FULL, 0x57E3D2BC38772E83ULL, 
            0x43D5D038E27B7A07ULL, 0x5336D4BA6FAF1C6AULL, 0x8BDD00CC72491576ULL, 0xB463C72D39EA4FF4ULL
        },
        {
            0xFECEA20551131EBBULL, 0xD8FA671273C574A7ULL, 0xB091E7E618B2BA09ULL, 0xA3D2EBE7A4C39B87ULL, 
            0xB731E8A7FFE47F6AULL, 0xC428919A9A094D22ULL, 0x8B4B5FEA27482B70ULL, 0x2D39D3ADE2ACE6C3ULL, 
            0xC8325F024B7FBD53ULL, 0x20CE29724FBFE122ULL, 0xE63B401DD34B12E4ULL, 0x87897388E1642D10ULL, 
            0xF5D1750DB9A0EC40ULL, 0x35DD574F43F36401ULL, 0x6905D168EDF44D88ULL, 0x8036DEDD182F5083ULL, 
            0x5E774E7E33B84C8DULL, 0x2A19E8D5B3606072ULL, 0x1012540611CCC9AEULL, 0x2B002CAFCF148991ULL, 
            0xE741A0089FE7E82CULL, 0x201D163780AB0C1FULL, 0x9AB8ED47241E2189ULL, 0x96851F21D1698F0CULL, 
            0x5801C228910694AEULL, 0x0F45212AB2A7FA2EULL, 0x937753AD631DF39CULL, 0xFCDC20985D012F3BULL, 
            0x8C5991B9B5C3FE6BULL, 0x1417698232051A10ULL, 0x96275AFE7BF5F898ULL, 0xFCD802AC150229A1ULL
        },
        {
            0xCDBC096A13DC4B1FULL, 0xC45CDD5AF1CBC333ULL, 0xBE22A26AF5089E64ULL, 0x44503B523A77E3DCULL, 
            0x646281C558BE112AULL, 0x7FCEA9CAE2529F9CULL, 0x74911660AC7157CAULL, 0xDA81F0FB1C32523AULL, 
            0x163A0057EB708900ULL, 0x827B19DDD70B11DEULL, 0x1B4DBAC1846D58BDULL, 0xC522B949D15E348CULL, 
            0x0586E746705A3076ULL, 0x2309E0121CBD7863ULL, 0xFC7423EB434B382BULL, 0x7F629A3F54B6BA58ULL, 
            0x581D36ED31090AAAULL, 0x30D87162BB186F7AULL, 0xED6555AABB9AC00FULL, 0x1F0D51F3E197160CULL, 
            0x2D143C8AA43242B7ULL, 0x0C0E56460E8C347EULL, 0x385C65F63A590D8FULL, 0x4E3B287F6DBD43EFULL, 
            0x0F4B0591F0A206C5ULL, 0x0CDB8CE65E9D1B57ULL, 0x4C9084F900F07A47ULL, 0x25D55A8521EF5AE4ULL, 
            0x619816AF54E94783ULL, 0x3E4A37C6C031E2D7ULL, 0xD102EE1F5727D762ULL, 0x22F38423D24285FFULL
        }
    },
    {
        {
            0xA1CD2DE549E25371ULL, 0xD36E8E91A7C9F5C8ULL, 0xC5DA8697C70D7DE3ULL, 0x345D9BC4E98A0B83ULL, 
            0x2F7D6D89EA464BFEULL, 0x94700DC7AFB01882ULL, 0xE66BBA7F194C0118ULL, 0x65494DBEBAD3AAB5ULL, 
            0x85BBF9373103F145ULL, 0x8310D1CD63BC8A6AULL, 0xB51CC7302C53E40BULL, 0x7BCD19901912EEC5ULL, 
            0x21C6F235F3F447E9ULL, 0xE6147492E99BFA59ULL, 0x2AB53DD19AF4DCA5ULL, 0x16F2AB3276BC77F7ULL, 
            0x564EA1F087219896ULL, 0xAD4621F68C099BA7ULL, 0x8D30D1088E2F6233ULL, 0x39591176305D1447ULL, 
            0xB1841553B2C707DAULL, 0x37A9AAA46307074BULL, 0xDA4051A0D910323DULL, 0x070BB2F94DBDEDE7ULL, 
            0xE0A958D50CA4B266ULL, 0x4E8BB35130CE67A2ULL, 0xD46BEF37CA8421F0ULL, 0x75D16AB7B062EA23ULL, 
            0xFBF1069F07594778ULL, 0xC3E0F9DBC8207316ULL, 0xA5C0AFDCAC9FDC27ULL, 0xC3E92D64C0921A28ULL
        },
        {
            0x2ED7CDF0154D86A2ULL, 0x47C484A3B55AF80AULL, 0x6618F6AE312E1598ULL, 0x8656146BF2F9BD6DULL, 
            0x2C549B40FCBF08A7ULL, 0x10BE2B91E378C739ULL, 0xC406123FD88F7032ULL, 0x230648800A3950F8ULL, 
            0x6D06B05E9B3DC5CDULL, 0x9F67FD37D4D9F644ULL, 0xB5E04E76A6859A9EULL, 0x468C0E518EF52380ULL, 
            0x7738381722E7B611ULL, 0xF976852568AF99FDULL, 0x59FCD1A0C994A95BULL, 0x5E0516E15E69B0C0ULL, 
            0xECB6DB1772B5EFD5ULL, 0x32FEA3714CFD418AULL, 0x1F5CB16046A3D719ULL, 0x3F83C2D6A419EFF1ULL, 
            0xC2F2E8F52932613EULL, 0x3F55B0790D112EB0ULL, 0x00B4104F409B9F96ULL, 0x9A9912C833DDA618ULL, 
            0xE5ED53CC7BDBBBCFULL, 0x9529E028ED40A571ULL, 0x5F70706F97B3DBACULL, 0x3142DE2CF1E75E02ULL, 
            0x04B6E7ABCBA4028EULL, 0x9EDE28B41B84E9C3ULL, 0x74B1125BD9BADEB7ULL, 0xA21BE6C882E01274ULL
        },
        {
            0xB3CDF201FF1E72E4ULL, 0x55B1EEA23B761941ULL, 0x6B040A6FB31FCFF8ULL, 0xDB25DF6821F58724ULL, 
            0x38636FE113E56179ULL, 0x20FF3835572CC333ULL, 0xFFCCEA980A0C0F3DULL, 0x9471821CA63AD2C9ULL, 
            0xCBE24D502DBF5376ULL, 0x7C66E129AFAEE06CULL, 0x372C69E2A67AC3F1ULL, 0x1BB70B958B321B96ULL, 
            0x322BC801A04A0908ULL, 0x41DE55A6E7FE7408ULL, 0xBC8A1C3A5375E8CAULL, 0x806A964A4673B261ULL, 
            0xC28520D0596FE40CULL, 0x445FF0095984278FULL, 0xFAEAEC0FF21CD7C2ULL, 0xCA7FE3911B805AB5ULL, 
            0xA44960314E16878DULL, 0x00BD6BB1DA711DE3ULL, 0xFFDC5C67A7241A86ULL, 0x8F34DC2F9E98A9E1ULL, 
            0xE76DC23205C05F63ULL, 0x1343BDCB07645FBFULL, 0x04D60CEFDDA9109AULL, 0xF50F73A2AAF6F635ULL, 
            0xD79E7B5ED91BD3F4ULL, 0x611633E701BD05F9ULL, 0xF5B34B606C39A4CFULL, 0x6582B257B64719BAULL
        },
        {
            0xC3D434E1E57FF307ULL, 0x7DD9F6A9DDDCDF0DULL, 0xF4451720F8BBD46AULL, 0xD442671CFF48587DULL, 
            0xE204432293548B70ULL, 0x2A5B916EDA726CF2ULL, 0x8F735ED1DC85750BULL, 0x0CD3F855A52D5756ULL, 
            0x2DCF47603BE8F2F5ULL, 0xA752B45EF7627008ULL, 0xFCD7FF76EF3E6F07ULL, 0x4BFEDDB4652B688FULL, 
            0x8AEF3D8D9762224AULL, 0x0A0D46DA2E18BA38ULL, 0xB5E491415F9BAC44ULL, 0x796C278439C9FC3CULL, 
            0xD2082CEB84D90A7BULL, 0x1DB9F4E6EE4F7E69ULL, 0xDEF3F2AA059BCE95ULL, 0xF3982EABBB342189ULL, 
            0x91A0700175A3F178ULL, 0xADEECD351E1CA39AULL, 0xD3E7FADF43ADB35DULL, 0x4BF274F5893040C4ULL, 
            0x48EF10D3EB7479EFULL, 0x3950C17E2C313C56ULL, 0xECA5E94BF489BB18ULL, 0xCA989CC6597E97E6ULL, 
            0x645F1902EDDB9415ULL, 0x82525A67A06FA954ULL, 0x80D38DFE4276B5A2ULL, 0x9A5716673C564E5BULL
        },
        {
            0x08DAF9FF38EEEC12ULL, 0x2B289AC1B5489588ULL, 0x56897D6B9FF77201ULL, 0x8ED049C3D304C207ULL, 
            0x0E028F6F20E4F78FULL, 0x90DC9A5EABE0890EULL, 0xCFC504ECFC63D875ULL, 0x8438665E413690F3ULL, 
            0x85C5D7AD5F544336ULL, 0x4B91DA468124D130ULL, 0x259C317E3251C961ULL, 0x5B5C6D7FBE49BEC0ULL, 
            0xC0798890788314ACULL, 0xA22D633639CDBE38ULL, 0x329B5A7E879F2ACBULL, 0x54582A30758916AAULL, 
            0x0F14BCF3074D9835ULL, 0xAF18C0EF3F29BA8DULL, 0xDC1500FA524093CAULL, 0x666C5713A50E7ECCULL, 
            0x84802BEF8068E7C7ULL, 0xCCE89E9C0105BFF9ULL, 0x4FB8AC8F7EE48398ULL, 0x3DF6A3ACCC8DEADFULL, 
            0xF1D86596974D1742ULL, 0xBA6E3118062A59F3ULL, 0x95411A6C52820BD6ULL, 0x30F259EB4CB8C39FULL, 
            0x56CA1AC5083283ACULL, 0x72A519B9676458A2ULL, 0x542449CF40CDC047ULL, 0xE57451D817164C38ULL
        },
        {
            0x516C0955EA576ED8ULL, 0x29E1B065E33B0609ULL, 0x0B483A7E92BF06EEULL, 0x1A8F6C1F17A3A562ULL, 
            0x94045B7BC129AD72ULL, 0x2514A207CA6189E6ULL, 0xF6AB69C202ECD4DCULL, 0xD8C93B308A7BB326ULL, 
            0xB548B36F4570680AULL, 0x1637387DD34B9588ULL, 0xF15F0BF4695ABCBBULL, 0x4349DB0384259084ULL, 
            0xE5FB9A2AC92102F4ULL, 0x492A1475EB552700ULL, 0x6B900C460AE34DE9ULL, 0xD08D3227459BDC01ULL, 
            0xC4AE31478B095953ULL, 0x7F9324830CB3A844ULL, 0x8655015C891CE60DULL, 0x778C90AE2D4D121BULL, 
            0x10EFA434BCC39307ULL, 0xA20AB4C540925EC3ULL, 0x08AC8C1EFE18F89FULL, 0x2A4EC861424D973EULL, 
            0xB8C5779D75DC9DF7ULL, 0xD9C6BCD386A1AEA1ULL, 0x5AF4CA401ED32617ULL, 0x2C841567EEEF0A49ULL, 
            0xFDCF00DB445E5698ULL, 0x261B7FEC2213A5DCULL, 0x9441376F7120BEDAULL, 0x570646FC6871803CULL
        }
    },
    {
        {
            0x4B858366FBB65E7DULL, 0x2439F123605DB471ULL, 0xF5FF084DCDAD235AULL, 0xBF1ABA0081719143ULL, 
            0xB4FEA3191027C0FBULL, 0xAAEC9C8634D94B64ULL, 0x6D3CDF19C35A083EULL, 0x3C756304D3E2DB6DULL, 
            0xCE64AD16C2EC0051ULL, 0xFC9D612583769C75ULL, 0x7FD29D7A35F3C385ULL, 0x02B59747FF7EFB53ULL, 
            0xB5EA60749A4D93EAULL, 0x99A417ED442D5E4BULL, 0x10068980ED1A5222ULL, 0xB21C7B6E9423E4DEULL, 
            0xAE716B095CD74EECULL, 0x07EBCBBB33456492ULL, 0x819B6462AB67035FULL, 0xF6699AD08A217D59ULL, 
            0x87A2B18EFC71C00AULL, 0x75566ED2D2BEED81ULL, 0x4EECDAC14D22FC02ULL, 0x76AABACD3E36D1B7ULL, 
            0xD3F5F4180633872BULL, 0x6708E8368B75F45BULL, 0x25360021F9D69A8DULL, 0x8F9DF50404B9B94CULL, 
            0x20FFC2372208BE98ULL, 0x632E4CEC6C349005ULL, 0x71AE8B4FB38D782DULL, 0x9CDA38AA1EAB14A7ULL
        },
        {
            0xBAB72406F50B51EFULL, 0x6114509D6B968266ULL, 0x16A5467E2FC271D0ULL, 0xAC4C8D7A4F829413ULL, 
            0xDF23F901648EDB1AULL, 0xDFD8BF88F2106096ULL, 0x4540AAAD19EB1D5AULL, 0xB86F0E57A6E2B4DAULL, 
            0x9A8042F5375DDE1CULL, 0x03968BDAD6090541ULL, 0xB6CE50495B7DFE5FULL, 0x5F8ECB8B1D2E257FULL, 
            0x9C49275C5218DC73ULL, 0x3E86E0C54EA53519ULL, 0x6B68FC4BB9D6F6A5ULL, 0x0F0065EDFE42B3C1ULL, 
            0x2909FA80A9D33B56ULL, 0x7E50E0C61C836C53ULL, 0x1A992050C9293527ULL, 0xCE470C45B13F160BULL, 
            0x878A43F68A9CB3A2ULL, 0xFF0F84A209E5E056ULL, 0x5BDD01750AEA3B7CULL, 0x279A2218BD2F302BULL, 
            0x961BE8D14D544085ULL, 0xBEB2CAEBE9BE42A1ULL, 0x7F316631F752F718ULL, 0x4E46B892127173A3ULL, 
            0xA927CD7EBD553833ULL, 0x42549BA24410B802ULL, 0x2173CD742E951B10ULL, 0x67C05B169BF77085ULL
        },
        {
            0x764CE654A04BBDB3ULL, 0x37B6D84999C6A5FCULL, 0x4D97405783598A5AULL, 0xAD7369DA68DE7842ULL, 
            0x5421267D5DEB5834ULL, 0x1E5F7093197AE6A4ULL, 0x98D24DF6DCF3B8C4ULL, 0xB2C2CF6A93FB6458ULL, 
            0xA24C805E93999E22ULL, 0x41471E19C4A7E482ULL, 0x8E48E515D4C1D11BULL, 0xF4A0B76B065F4926ULL, 
            0x0077F0352720BBFDULL, 0x3A30FE2190661A57ULL, 0x454A0BE55E26A412ULL, 0x89BFEDCE302073EAULL, 
            0x50C99F6628E0601FULL, 0x347A8D1ABC3EC37DULL, 0xB3C12A55577212F3ULL, 0x3EC6BEC778DD63A3ULL, 
            0xC3693DAE0BCD6E5FULL, 0xF6702A9D754E3BFAULL, 0x038E6973128CD6EEULL, 0xA692A6B4889EF1B5ULL, 
            0xE4C61400DB661A9CULL, 0x51D594C3D986D215ULL, 0x1F4C7463133BB5D6ULL, 0xE1A8A4D81952FB44ULL, 
            0x68E422DA9B653302ULL, 0x0B0E9B463B9C628AULL, 0x62E918EEAD312AB9ULL, 0xC99A58007FCB9B48ULL
        },
        {
            0x0CB6C02B49DFEAC4ULL, 0xE9D120DCAC26944CULL, 0xE1ADCA0A7318C5C1ULL, 0xFF036BB42203C965ULL, 
            0xF2E0151D0EF75BB7ULL, 0x2740E10633FF9A1BULL, 0xFE08934E7C39C58BULL, 0xDED60E40A92FEA88ULL, 
            0xDCD2F2070DA0082FULL, 0x3F9B9E9951E403EBULL, 0x337E7409798F0BC7ULL, 0x55EBCB1D89022E84ULL, 
            0xDFFE785D11C5E4CBULL, 0x63F00654D7204E22ULL, 0x6B3CA12939E48277ULL, 0xD05896CE3510DAE9ULL, 
            0x85E98C3FADFE6ECBULL, 0x3C147277BAF364E3ULL, 0xC7212571CB46708CULL, 0xFC24D28032A4B674ULL, 
            0xBF6B3FE761B2C92CULL, 0x615ADBD06A64222AULL, 0xF60976C3CC6C872CULL, 0x32E6A023DA3F0441ULL, 
            0xB444B67676C0B1C2ULL, 0x7DCDE9F73F953C1DULL, 0x59657063A654A6D4ULL, 0xF01E4A5F0B3DD088ULL, 
            0xA25B9A168A04B377ULL, 0x1D1F10B3DC5CDC88ULL, 0xFB93E3439D1768B0ULL, 0xE218870BDC457347ULL
        },
        {
            0xFFC665660BFF3519ULL, 0x96AA8056E9316B28ULL, 0xCC8E2BD3175D809EULL, 0x8BDD7A68D50B13B8ULL, 
            0x848F7FB82733F23CULL, 0xC39B7507600205E2ULL, 0xB81D4D67983C10E7ULL, 0x333676297855B215ULL, 
            0x7348F592A6E7CB2BULL, 0xE75FACF9363A66EFULL, 0x9D3C981F6A549836ULL, 0x701CAE2C6D237A91ULL, 
            0x6845451C54FD1D55ULL, 0x33A98B22B3FA4ECFULL, 0xBF7AA5F26B8661C1ULL, 0xC0367ED41E1BBF0CULL, 
            0x8B2AF67CAADA1DC2ULL, 0x98D914A8E4A592FDULL, 0xCEEDC5A77433FBD5ULL, 0xC67144F768AFAC03ULL, 
            0xF1D70B49CED7D1CFULL, 0x8C5CC543FF16DDE1ULL, 0xEFC6ACD06817FE04ULL, 0x76B1B6FBEDF7781EULL, 
            0x6820C5576AFAF47FULL, 0x8E5CF4A3A3346695ULL, 0x2B020ACA65F1F1F4ULL, 0x71D2F09BE0D5C2CBULL, 
            0x80E92D5D9D7D7152ULL, 0x0A8306C395E7B8D8ULL, 0xC5F1D744FFBEA33BULL, 0x61E3F24272A59B5DULL
        },
        {
            0x8DB308A1AF876AF6ULL, 0xD6E295C128B51199ULL, 0x71467E48420164E0ULL, 0x62CE26A3853D76B5ULL, 
            0xF573674F9789528DULL, 0xC2CB9C30F7A038C6ULL, 0x74CF0A27AA47E24FULL, 0xC3422D9B4A7A8CAEULL, 
            0xD7BC6915E9FF8598ULL, 0x78FD9A7C4FBA16DDULL, 0x83C7FA253037D148ULL, 0x3029711716F3380CULL, 
            0xAEAB0453880E69A0ULL, 0x89CB36ED5D0ED8B3ULL, 0x13C0B8980F92F686ULL, 0x6305208EE2636CF9ULL, 
            0x5625CD3E49ED9EB2ULL, 0xD0ECF1EEE5DF3091ULL, 0x565F85B5F367EA05ULL, 0xA3011F75E2A677CDULL, 
            0xA3E5E390C53E7F21ULL, 0xB3CB3AB3906E1379ULL, 0x41A3EDDF23AB5B09ULL, 0x94D1958053AFE6E8ULL, 
            0x0D14F16C6ED55669ULL, 0x47E1B8C02C40EA9BULL, 0x8C3C2A7EAA08A462ULL, 0xE14FF08BC46BF680ULL, 
            0xD439C35931D01E30ULL, 0xCC135E56F117C940ULL, 0x106842CFA8F07F68ULL, 0x1FE5326976661871ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseAConstants = {
    0x63239B0C8CC07966ULL,
    0x9970515B4E8A39DEULL,
    0x8C4FCAC56BFED73FULL,
    0x63239B0C8CC07966ULL,
    0x9970515B4E8A39DEULL,
    0x8C4FCAC56BFED73FULL,
    0x3334FA596FDAB3E8ULL,
    0xE05CB78DEAD691D0ULL,
    0x35,
    0xD2,
    0x98,
    0xB0,
    0x3D,
    0x27,
    0x09,
    0x14
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseBSalts = {
    {
        {
            0x261641E899CA6B73ULL, 0xEA32A024F9F9C86CULL, 0x279B0C991D84C07FULL, 0x812C12512AB52D91ULL, 
            0xE716F3A7A45172A8ULL, 0xE1FA342C9F4D87A2ULL, 0x8D5A437E37F3DD5FULL, 0x18481EA9046BFA8EULL, 
            0xB7F7DCA3D2F7A336ULL, 0x31CB45B1BC62F64CULL, 0xB9CC89BBFB11A6AAULL, 0x28C401C810FFD497ULL, 
            0xA9CEA80AD24F6905ULL, 0xD61D936B7292C443ULL, 0xA417173439795C78ULL, 0xFD6B2CCB62AE8744ULL, 
            0xBB78A42FED0041F2ULL, 0x6777F4CB951DA4E4ULL, 0x4AC967A078D38A27ULL, 0x632255D95FF58B8BULL, 
            0x668347C090D9B7CAULL, 0xACDB69C13C339630ULL, 0x3C2D63365473D09EULL, 0x79F8228AAB053CD9ULL, 
            0x1887303A1A9038F3ULL, 0x5599AD6440CDD131ULL, 0xBECDBC29EB333927ULL, 0x559A55E39546A6FEULL, 
            0x34A54D4AA6404B23ULL, 0xA6A5D297743C4F5FULL, 0x5C55C249B5A7B2AAULL, 0x165F8A906617922AULL
        },
        {
            0x599363D66A21A6D3ULL, 0x905BBF31C9D4EE61ULL, 0xF1EB592DF8334A66ULL, 0x2A6390AE5B06BA30ULL, 
            0xE1C29D561327B915ULL, 0xF2BE7F57DBA1F80AULL, 0xC20749CE643DF30EULL, 0x9AB151535407D9F4ULL, 
            0xAA443A9D926DAD28ULL, 0x557457B20C67CA4DULL, 0x3B4329E165A0BF1FULL, 0xBCB2195911E090A7ULL, 
            0xDD3C599557C9F0ACULL, 0xB665F5A089C8A68FULL, 0xAE037C3E4B15CD26ULL, 0x9A0C00DD51C5834CULL, 
            0xCD344BC9D359E190ULL, 0x28DC5D4F35CA228FULL, 0x284CCA5827BAD5A6ULL, 0x92BE8B79289A25A6ULL, 
            0xEDB8D9D11670426BULL, 0x08624C4EC0328DD0ULL, 0x02FBA09073CFD6A7ULL, 0x3BE34C9833B85CEEULL, 
            0x0845D064BFB46FC3ULL, 0x1608BDEB38E39CB3ULL, 0xA68B4784B375737BULL, 0x5C83B89B71B64D47ULL, 
            0xE552D4A2B865F261ULL, 0x1EA86E70CE69A4C8ULL, 0xD2227275F872E9B8ULL, 0x360540C3611BACA9ULL
        },
        {
            0xAD4C3CD605A813FCULL, 0x3CF8FEA55882BA34ULL, 0x4DD058B43890AC3BULL, 0x539806E4E258912CULL, 
            0xDDB82AF36220796BULL, 0x58446541E9E69288ULL, 0xCEDAEB17E8E59F12ULL, 0x6A03B907CA78119AULL, 
            0x8DAC1C5991A32DD3ULL, 0xCB994533C558F1C8ULL, 0x866981ED6EEEC735ULL, 0x363C3D2481DD5582ULL, 
            0xF44FA22E265E039FULL, 0x44FC10EA79605A76ULL, 0x6755332B721EEDC9ULL, 0x044F2AFC134846F3ULL, 
            0x397C3AEB3DDB233BULL, 0x1E90E5C6C387CE8CULL, 0x7DF0BB6C84B7C371ULL, 0xA390ED83044BE20FULL, 
            0x627DDCD1C2FE2DABULL, 0x99774D102AF6FEBCULL, 0x23AC0E44EE921509ULL, 0x14BA080DF02257CEULL, 
            0xE05EB66EFD803A01ULL, 0xE3DC252C77BA35E0ULL, 0xED51FF64549299EDULL, 0xFD36984ECA7D964EULL, 
            0xAF00B9D8393287FCULL, 0x79054DCC99FC806DULL, 0xD2844AD76899101CULL, 0x21AEC64F90DE55CEULL
        },
        {
            0x3C5FC1CEEA075575ULL, 0x324B10B173398668ULL, 0xCAE97658BA62FAB7ULL, 0xF4820C9A7D6C2B67ULL, 
            0x47B83BF016633AFDULL, 0xDF78968CC35CCF7DULL, 0x80F96A66E71E7D0EULL, 0x480275CB25A8EB44ULL, 
            0xAD615BE3B1FC8C41ULL, 0x957EB07882FB7419ULL, 0xEA7CFC0D1047C415ULL, 0x87E005D358E8DACDULL, 
            0x4D35E11AF85F07ECULL, 0x88CEC57302466F61ULL, 0x2498F69E217A6D55ULL, 0x980701684D1E781CULL, 
            0x8416FFA1540A0205ULL, 0xDACEC4BDE7B8B8B7ULL, 0x6854EAE1F9439C60ULL, 0xBCC3E447E384B6B7ULL, 
            0x3308B0D6BF5383CBULL, 0x729C96E346DBF6F1ULL, 0xBA49860E9BCD69B6ULL, 0xACBC733B57FFE7D2ULL, 
            0x1E618C370E02E9E5ULL, 0x41D005C9BC276F51ULL, 0x85A8C735765A8703ULL, 0x4CF3474011677400ULL, 
            0x3BB540B432307DCAULL, 0x33B64DD90C9BB1F7ULL, 0x7BD36E8C98AC84C6ULL, 0x74AFF1D61ED6702BULL
        },
        {
            0x4DE8FA1CBF1526AFULL, 0xE62EEE2C10D8BBE2ULL, 0xCE594DD8BC697FA7ULL, 0x4B8081B7B9DA0DBFULL, 
            0x5B903F521363C56FULL, 0x27DF483379057E5BULL, 0xDE3518E015F04D7AULL, 0x8EC328AA709C94C4ULL, 
            0x131102BFB8DF7F21ULL, 0xE145EFE335A227C9ULL, 0x99A3ABF6FBEA03FFULL, 0x982EC0E8C789A664ULL, 
            0x3D1CA8BD0F0585D2ULL, 0x506D75898F5524FFULL, 0x02081CC0B52A315DULL, 0xE24D8CF7B5F2AFDDULL, 
            0x87C69A3E7FCB0909ULL, 0x46CCE08E95B721E2ULL, 0x2E3711D87241EF46ULL, 0x5C81DABA57D2C392ULL, 
            0xB45B390410D99377ULL, 0x8EE51D7CE68811F9ULL, 0xF9B1B98BE4537249ULL, 0x99BF6CEC22041C6DULL, 
            0xBE23D45957B81CCCULL, 0x9E1F6AFD9E223516ULL, 0x972DB77F722BC406ULL, 0xB898CD78467C1F31ULL, 
            0xEADACDFC2516E05BULL, 0x3CDD99502CB4BA61ULL, 0xF46D22F0063E84BFULL, 0x86B4EC4957756800ULL
        },
        {
            0xD098CF06A5FD7374ULL, 0x2CE26E0A1A729751ULL, 0xBE86EC014658ACCDULL, 0xC20296E7A213E5BFULL, 
            0xF2331D15B28253C7ULL, 0x7DFF45D75716836DULL, 0x450ABC48977A1698ULL, 0x7BAB68C3D1F12C3FULL, 
            0x744992AAEC9267E9ULL, 0x1CE496D82E5E5882ULL, 0x04A7F2A5918191CBULL, 0xC39B0B22457FCAFCULL, 
            0xBBAC4516A0937B08ULL, 0xB69B19FA3C9A81E6ULL, 0xFE202880BCB691E3ULL, 0xFD9FB88EF1A927B7ULL, 
            0xEEC7EB2C7C1EFCE5ULL, 0x421C19DB077F648BULL, 0x2262576A7539719BULL, 0x0D58ACF68E1A6042ULL, 
            0x963B6222B8452AFBULL, 0x319226780B4981D5ULL, 0x9777E81FE8E3E378ULL, 0xD040ECFA1A2ECFDBULL, 
            0xA5177548A36B53D9ULL, 0x6216F79CC7C78A8AULL, 0x3B4DA827E6265398ULL, 0xED8354377B672402ULL, 
            0x49ADB121CD084416ULL, 0x78F6C0C60F704E60ULL, 0xB7390061C6FDD934ULL, 0x3A8E86DFFC1134D3ULL
        }
    },
    {
        {
            0x3FC5E4117ADAEBC7ULL, 0x1C1E5FC0AB546661ULL, 0xCCDFF459B83FA52BULL, 0x4463A973DEE4631EULL, 
            0xC68DD0BD8A8B2DA0ULL, 0x2B0DF78165E81696ULL, 0xCA2B4D633319A9DCULL, 0x19752A001AB50146ULL, 
            0x5CDC077A865A8758ULL, 0x53816C426831D43AULL, 0xCFD1C3229D2DF348ULL, 0x064791983412FE23ULL, 
            0x7235ED882DBEA13FULL, 0xD0FD20E300E15058ULL, 0xB6FE6333FB142A1DULL, 0x75119AFBEC8FDC8DULL, 
            0x7F4B069F086917A1ULL, 0x4BB1D41896DE9AFEULL, 0xC880473330D7634EULL, 0x3B3D38A2825E461EULL, 
            0x5BA2E7ECDA0ADD0CULL, 0xA706D58DD7FFEB2FULL, 0x494F010518BDD4E1ULL, 0x9B039A55B4D08A22ULL, 
            0x0D7B801E99457E96ULL, 0x013FF743DAE4AD89ULL, 0x862C70F39CCBB7CFULL, 0x35C4C53CE895CA77ULL, 
            0x44EC337BAB91E101ULL, 0x6E581AF4141241C0ULL, 0xECA31DBA43A379C7ULL, 0xC6D1328E73490FF2ULL
        },
        {
            0x28815E9A0FE2CA1BULL, 0x8EDF365D10002F8BULL, 0x83135958B2DACB9FULL, 0xE96DE83B8A080E74ULL, 
            0x6B7D47D6BE1E22B3ULL, 0x440B94817DD47A9FULL, 0xBC22461E8DEAD9B9ULL, 0xEE6986E2931B4ED2ULL, 
            0x2D51BAA2660ADFB2ULL, 0x1CF4E2576CCEE1F1ULL, 0x5FEE333C284F2F37ULL, 0x72A1AF2FFD388266ULL, 
            0xE80471D8276631E7ULL, 0x0EE87AB086526FDAULL, 0x0F0BA366FF04235EULL, 0x1D3C9EEBBD182185ULL, 
            0xF4C8ED70590100E0ULL, 0xB13DA13246B43035ULL, 0xF71AEAC634F89AD4ULL, 0x4B091E6F79B925CFULL, 
            0x2E6E65BE85C59030ULL, 0x976EEC5A7FFDFB27ULL, 0x2CC6CDAC428CA017ULL, 0xF6B6D4D95EF23191ULL, 
            0xB98FACADED2026D5ULL, 0xF5836CAF52B21C9CULL, 0xF70D13E33372248FULL, 0xBB67DEC20DA32C62ULL, 
            0x80A8CB781DF862E1ULL, 0x6C945B4A04C86209ULL, 0x650045FAAB599BDAULL, 0x344971A906BE7559ULL
        },
        {
            0xAE3A9A4A3CB8C673ULL, 0x924F44B1D3BD084CULL, 0x1C3FDD021486D1FCULL, 0x78C9C5CDB1587D72ULL, 
            0xF972AAD629293C9EULL, 0xE78861E6DA60F59AULL, 0xBA6DC7A20575F975ULL, 0x709EACE1B8A38D1AULL, 
            0x384B99C9147A5C43ULL, 0xA9F97BD58E081698ULL, 0xBD437E68D5FAD6DAULL, 0x9EB26F5B29654279ULL, 
            0xEBB2DC9C3A02DED3ULL, 0x2533C6CE3B420ECFULL, 0xD9AD3E406F3529AAULL, 0x6EF006D349D4A01BULL, 
            0x0434A5164A5F4F08ULL, 0x74D43BBFE50041EBULL, 0x5EEC07861165BAD3ULL, 0x18A0C890DA7B33C7ULL, 
            0x79E6924D306D34A5ULL, 0x106E4ABCA27F6C01ULL, 0xFF7233839FBDC539ULL, 0x8AAA58792014B31DULL, 
            0xE775D5576A01CF24ULL, 0x16EFAF88237C8BC4ULL, 0x21714E8E29BB7833ULL, 0xD3DF2C725BA062A5ULL, 
            0xCDFE739C9A6DE9BCULL, 0xB5B59566B55879D6ULL, 0xF91FBB2F82197D6BULL, 0x716AF1283C7B9BDDULL
        },
        {
            0x7741FDBB85573C78ULL, 0xE7FCA254A9A28966ULL, 0x2C87E904935B06F0ULL, 0xB6A1F5CFED6D3F17ULL, 
            0xA09ED30FFAEFF1DCULL, 0x41E274A0DFF56D6FULL, 0x037EC70E4F159053ULL, 0xEB55329A015F91E1ULL, 
            0xDD310B7ACF3D1123ULL, 0x4E9A9623B9F82692ULL, 0x181D81858D087474ULL, 0xD6D572251ADD541CULL, 
            0xFF8571C70724254BULL, 0x9D2D39DB98565A99ULL, 0x6A328776461D0BE5ULL, 0x51CC7D8F9879F64BULL, 
            0x051FE078B646350EULL, 0xF3F4554E6A1F2072ULL, 0x1A98F764AB4B65BFULL, 0x7A0CEE7A5A49B0B4ULL, 
            0xF3B0117E5E37962BULL, 0x188FA2649CB0D657ULL, 0x8DB35812F1074788ULL, 0x3053305FC2108CAFULL, 
            0xA2342DF173C86890ULL, 0x97131ED63B7F6D20ULL, 0x1183A221586A3247ULL, 0x10D9D966B0B095D1ULL, 
            0xD60B1D57DB8353DCULL, 0x6713606E8EC0022FULL, 0x65306D8D6A2A4E30ULL, 0x200A8C326B5944FAULL
        },
        {
            0x0131DF6888AA7B7FULL, 0xDF333C5D8454DDDAULL, 0xE355E6AE0C486EC0ULL, 0x6FF44815643B59D4ULL, 
            0xE3E99A0C6633FB78ULL, 0xB74CCC027D0ACD8BULL, 0x93C3DE94CA33618CULL, 0xF7DB68FB05EA95FCULL, 
            0x8D2B7465CFFB71E4ULL, 0x704E8BBCE1FAEC02ULL, 0x78C529A62E16AAEAULL, 0xC01F2DDFB9CB542EULL, 
            0x63CC4C5F77E9F49BULL, 0xFD6399FC06C8B713ULL, 0x0380A82B04A1AFD9ULL, 0x52FDBA64F25BE74CULL, 
            0x42E307EBF081820BULL, 0xD2C63B8106B953EBULL, 0x85F967B8A833F4A7ULL, 0x29B39ED5CFDC0013ULL, 
            0xD45695CA6C94682FULL, 0x0349ED7E46DE66EFULL, 0x11DF7400B99B4E52ULL, 0x03111F6BF2A950E7ULL, 
            0xFD3AE71AE3A8183DULL, 0x00F5B4A432B10F8FULL, 0x2DE1605AFE2E2F8CULL, 0x29707DD3E859965AULL, 
            0xD5207C2EDD41B3F9ULL, 0x080D102BED776EA0ULL, 0xAA55473D015C2345ULL, 0x94738B6D9FDED4F3ULL
        },
        {
            0x5434F3A7D41354ADULL, 0xFC5B384270F49085ULL, 0x11CEF4A04EE4F743ULL, 0x2493905E34080320ULL, 
            0xA8B173F47C7F8908ULL, 0x49E51B8CBE982438ULL, 0x89FB9A4025A7948EULL, 0xE9D834119E8AFC40ULL, 
            0xCC6E43E9A279B6B8ULL, 0x9B57CAAAA854E9E2ULL, 0x143A2D6D531CBA31ULL, 0x3616399EF7C3FB17ULL, 
            0x40F4897E502741C5ULL, 0xB8AA059076D1E868ULL, 0xFAE44DB2BCA91DF2ULL, 0x632FB52161113440ULL, 
            0x68AFE75C2A5D2830ULL, 0x3FC3387737283884ULL, 0xE56E67FA6421E8D3ULL, 0xCABC3D45B40707D9ULL, 
            0x3C910B5641FCADB5ULL, 0x7A9A5F590C5D8B12ULL, 0x5488CB8492C2FB26ULL, 0xB80AB703E5A5C563ULL, 
            0x0FEC6FBE519B16A1ULL, 0xF840E675D3B9F4A4ULL, 0x36F42B619833D357ULL, 0x73DBA50B959517E1ULL, 
            0x3E76DBD1E7177681ULL, 0x68C96009CF7A0C56ULL, 0x83218E45D1970D09ULL, 0x8EC6CD36653F41BEULL
        }
    },
    {
        {
            0xB9D8B49D020DB1B9ULL, 0x5808B14E0DFF665AULL, 0xF69C858F8AE280A1ULL, 0xF1DB291A2166C5A4ULL, 
            0xB03AFC0799F0198EULL, 0x07EA97A2A8E815C5ULL, 0xCB21A148274A5B05ULL, 0x1E3C7B13ED73A991ULL, 
            0x427B64F0CBB646D8ULL, 0x8BB3C50DC7564804ULL, 0x544BF0F939E8B90FULL, 0x3E9EC85CB72451E2ULL, 
            0x482FDD4A4AFF4541ULL, 0x2A119A9015D678D5ULL, 0x415BA52C3EA111D3ULL, 0x20F6290FF497B931ULL, 
            0xDA917AD0639C8739ULL, 0x47A854AFCFC854B7ULL, 0xEC18EBEE28B69960ULL, 0xBCD7F5D7817D7E3DULL, 
            0x903F94EA4E0AEC5CULL, 0x579B3A3DD3C59FCDULL, 0x8BA5CD5FE53D9569ULL, 0x201F98FEA0BF5375ULL, 
            0xFA2F24BD0C8457FCULL, 0x2392F8E91A1D711FULL, 0xB832BC37C295199FULL, 0xCC6192400DDE19E2ULL, 
            0xE39A6124759CD140ULL, 0xF448CF156DDC2CCFULL, 0xD337D6D7A1473F26ULL, 0x9D3ADCD36D9CA397ULL
        },
        {
            0x21CA22B17C6BC72BULL, 0x34482CFF38D98E61ULL, 0x6E0B08DB9291B7A9ULL, 0x6FE8880E7857F197ULL, 
            0x77D1796AE9B8FED5ULL, 0xA1697A28A0D8F2F4ULL, 0x8165FA6320358EB1ULL, 0x2C1CAC786A6AE500ULL, 
            0x0A9CC509A0A65C85ULL, 0x7CAF390EB256EA08ULL, 0x95CD5B88245001B0ULL, 0x0403E510A33CE5E8ULL, 
            0xADA5F2528D7B2C6EULL, 0x1B5D7718448F9003ULL, 0xEF42B6235AA423DAULL, 0xDFFBC5CE41BB224CULL, 
            0x2040F56DD2E79D79ULL, 0x6720F0A627368B2BULL, 0x4E4BB746F98E3628ULL, 0x9DB4BA3BFB76ADBBULL, 
            0x3F9EE4F639F25C17ULL, 0xDB679236248BDF09ULL, 0xFF5B39631E41ADDDULL, 0x8A9359B70F73BD7FULL, 
            0x659872FE1DF2527BULL, 0x8A8127C533FD460DULL, 0xA5D345A3D0168311ULL, 0x88CC27CC8D57E5BCULL, 
            0x1B9FA8BEB980AB00ULL, 0x77A6F1782838780CULL, 0xFED9632A6DA8379AULL, 0x4A457FB0A505CCC4ULL
        },
        {
            0xEA515A17D7785947ULL, 0xFE0057F9205C1817ULL, 0x48FB950A1A5940A9ULL, 0x4D2DE1643E0BBB2AULL, 
            0x9F30C1EBEEA85F1FULL, 0xCAB6880F5A16A888ULL, 0x0580964DE6C76A1EULL, 0x985ABBE02F8AA75CULL, 
            0x54625FF12DC1AA5DULL, 0x8B4A7B8CBD999E1AULL, 0xF6FFEC7E7D56380DULL, 0x202780350F7B8954ULL, 
            0xDEE98AE219998165ULL, 0xC9AE8DD22C5F04A1ULL, 0xD5B1EED8BB8F2855ULL, 0xF4A879120A2F3F98ULL, 
            0x0AECDF71CCDC346EULL, 0xB0F95055527E1619ULL, 0x77C216AF3CE8FF71ULL, 0x3DCDDAB6374FBA4FULL, 
            0xC5545CA4682489D9ULL, 0x3A8AFCD17BBF22D4ULL, 0xF764ED78D471FC37ULL, 0x4C0B9E327704D860ULL, 
            0x9D8C58FA26FC355CULL, 0xD1BDB945EA45FBF1ULL, 0x9D774BDB5C0910C7ULL, 0x8E84D30F12BFD014ULL, 
            0xEE3DCE301AF3A371ULL, 0xB0D58DAE8F62D320ULL, 0xCFE5C14EFDD35AABULL, 0x21113EB92F991508ULL
        },
        {
            0xFBA35A853BB6232DULL, 0x4592878B62D66314ULL, 0x9122ABDD06FAF909ULL, 0x2991E3362D438B3CULL, 
            0x1A5FB2F03365258EULL, 0xDB2BEFFC0305F2BBULL, 0x235F54CB90736D97ULL, 0x3E598F2365409D87ULL, 
            0x6EA6869F5CCB2C8FULL, 0xFBB0367F430540CDULL, 0x41B0E4255069EE01ULL, 0xF3582D1C08530055ULL, 
            0x831487104F2E644FULL, 0xBDFBA92536F6545AULL, 0x2EA0E7B2B47A793DULL, 0x1AB588833215F0B3ULL, 
            0x2357C335B0B889B3ULL, 0x2CF55DB2020C79D4ULL, 0xC1F49448E8308E95ULL, 0x4B17E87C169AC350ULL, 
            0x6DEDFD2BA2F03228ULL, 0x4B59F10BACC5E86AULL, 0xAF2FC45ABB9B95D4ULL, 0x242EC4EE63092DC9ULL, 
            0x0DA242F4F2DB4B88ULL, 0xEDC8CB4AD10EEF2AULL, 0x06F359C6E4B15A4CULL, 0x8B9D8C49D0DDB28BULL, 
            0x400AB7C8B3CBDACFULL, 0x7EA060AE56E5AC47ULL, 0xC0F62CCEFAF48959ULL, 0x1A0A319FF97BF880ULL
        },
        {
            0xCFCBFDAA719199C3ULL, 0x7F3FD22B8A5DC37EULL, 0x4217645C027626C0ULL, 0x1E1DD015E6157816ULL, 
            0xB8B13D9366E43214ULL, 0xFAB0795DAA6BC8AFULL, 0x1C779B1BC7FCD353ULL, 0x73416BF3D1B9A463ULL, 
            0xD42FB61E87D87995ULL, 0x7DD2DB9E5213B249ULL, 0xADEB511714D16B5CULL, 0xC230CB33DA994B28ULL, 
            0xB9E0301CF6091CDCULL, 0x874683E9FEF9DB4AULL, 0xA1686A6C11C03800ULL, 0xBBD150964E108A48ULL, 
            0xC4F1500BE09EB40FULL, 0xFECB98BB7FC2A788ULL, 0x6BF36CFAD562B17AULL, 0x471B45F6B47B2D37ULL, 
            0xFAA4963D10D86657ULL, 0xA8C9FE9B8D3D9B2DULL, 0x1C141F631B7055DFULL, 0x076A7DDBFECAA043ULL, 
            0x63AC00D804F8B3A1ULL, 0x511D429512BF4F3CULL, 0x21E6FB97DE211396ULL, 0x41652EBE0A71D8EBULL, 
            0xF65227A20976D141ULL, 0x5311128D3A6F65F7ULL, 0x52FB2341DE869E0CULL, 0x01763E7DA2FCF19AULL
        },
        {
            0x5509A428CD7A8458ULL, 0xE8964B33DBD9AE4BULL, 0x5044EE6CFF560786ULL, 0x1A62D1D4BB601296ULL, 
            0xE30D826D4C66A13FULL, 0x2E5E1252566A8589ULL, 0x0693E8208E79D610ULL, 0x4EDEAE914ABE062FULL, 
            0xECB6F3F231FC6F46ULL, 0x01E1CA41CDB0EE6DULL, 0xCE8269DC4EF36629ULL, 0x1590F63D5C23E95AULL, 
            0x8B7BCE2CF6F22D5BULL, 0x52966F8460FEE78BULL, 0x5AF691F28304C317ULL, 0x12E8FCC0F63959DFULL, 
            0x46BA3E29B4C1B371ULL, 0x94A4CCF96F699326ULL, 0x39E98FAA2A19D064ULL, 0xBCFB7FFA255B7BC2ULL, 
            0x10CC1B384DA5D184ULL, 0x97207297A90A76F2ULL, 0x2D2B93A4B82CD866ULL, 0x041A7393DD12C215ULL, 
            0xC9DD7473EC050232ULL, 0xB629D02245463391ULL, 0x5C7ABE6A1E7EA4ECULL, 0x9BFE52F54C30F834ULL, 
            0xC9DFB00EE2D461E1ULL, 0x052A3BCDF3B86B7DULL, 0xE0068D65C8E89FE3ULL, 0x0DEDAD45F8BFFDB0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseBConstants = {
    0xABE5DF101F0E9332ULL,
    0x0DE288A1C5299D17ULL,
    0xF11B0AF7ACF355B1ULL,
    0xABE5DF101F0E9332ULL,
    0x0DE288A1C5299D17ULL,
    0xF11B0AF7ACF355B1ULL,
    0x870276598C42E6ACULL,
    0xA2C104F7F04B0640ULL,
    0xDE,
    0xED,
    0x26,
    0xAE,
    0xBD,
    0xDA,
    0xD5,
    0x7C
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseCSalts = {
    {
        {
            0xB372F858B2377285ULL, 0x20A1ED05A3BAC69EULL, 0x71C7D06E46ACF711ULL, 0xFCEC4217C2862D4FULL, 
            0x95CD3C3BEEAC7517ULL, 0x59D0C533A6AF842AULL, 0x114FD99258CB734DULL, 0xDBA73537BF06ED6AULL, 
            0x1A7EC459615CACFEULL, 0x721B2FA654703352ULL, 0x7CB34B8B1CAD114DULL, 0x02A4BCF5B4C9B1DDULL, 
            0xFCABFF173E8631CFULL, 0x9A1A4901629B3938ULL, 0x6E0B6974749761F7ULL, 0xD9B32D91CBFC760EULL, 
            0x94DF97FBA12ACB7BULL, 0x291505B4F1C84A8BULL, 0x67DB321DBF9A335EULL, 0xACC7EC34F6AFE2DDULL, 
            0xCDBE9FE166C8E16EULL, 0xA7A394BED91F1D2AULL, 0x4F89E1F2BFA27F22ULL, 0xB22D1C2396B7E3D6ULL, 
            0x0C4DD9425D4A4BB4ULL, 0xD9F935D92C5C28ECULL, 0xEE5794B73D27FB6BULL, 0x1D973E1D32BE90C7ULL, 
            0x4DF3732E9E1C24B4ULL, 0x803A7B1DA2C3D232ULL, 0xD82D08B063AD9A97ULL, 0xD39033C4C2E7EFE6ULL
        },
        {
            0x0EFFEF03EC6BD980ULL, 0xDF22B5FCFC59DECDULL, 0x3B1B98C22841BE3CULL, 0x079C04EEED92E138ULL, 
            0xA47E3E26B3F1B067ULL, 0xCC81185B95D5B681ULL, 0xA83C1020328DA5D0ULL, 0x646F8122D90B4705ULL, 
            0xE6BB611D7CA9A8C2ULL, 0x07A2A3377EE46D56ULL, 0x04CACDBCCEACF71DULL, 0x04B5F20E5FF83051ULL, 
            0x023EF731A7241CA5ULL, 0xFB0B951C3BD0ECD9ULL, 0x13916CE3D1EE8336ULL, 0xC0293D6F5253380AULL, 
            0x6EEADEA1CE3E0440ULL, 0x234ED50B4DFEEEE8ULL, 0x5D28B56013D80399ULL, 0x3D8953A16B2D0864ULL, 
            0x12305122DE91767FULL, 0x88683F21F5F9DC64ULL, 0xED3257D9431BB939ULL, 0x3EE45005B3D03F03ULL, 
            0x12300C6819591B91ULL, 0x961B01C1690CBC9CULL, 0x1BE32D8CCC381514ULL, 0xFC00181905188224ULL, 
            0x3106F1F798DD5D22ULL, 0xFDDBC7A310043578ULL, 0x1E2A2A266FE7F67CULL, 0x8FC03A9410B5E754ULL
        },
        {
            0xE55EC5ADCCBA9252ULL, 0xFA444F8D471D818FULL, 0x09FE4925BF88AAAEULL, 0x72E1A2AF3BA77ABEULL, 
            0x269A52EF08866539ULL, 0xE9C4D939615E8951ULL, 0x57EB4C4F7114D98CULL, 0x610E3E4D4BC4D06CULL, 
            0x3F0F4D29CF129A51ULL, 0xE8AF97790F814377ULL, 0x2EFF935CB6B4D9B3ULL, 0xF19D8DADAFAB1B00ULL, 
            0xE51BB641A9D6F185ULL, 0x8E82AA3E84584A1EULL, 0xBA497AE7BFDE7D23ULL, 0x990BD02E73CAED92ULL, 
            0xAE24C220F2EEDDE1ULL, 0xECB26D1115E01CAAULL, 0x33F8E536DF8FAB54ULL, 0x9820F33213206516ULL, 
            0x6D47EAA5A930C894ULL, 0x84B2A9FAB2178C8AULL, 0xFC1BAB6A96F7B66AULL, 0xA35374411702067EULL, 
            0x072D542BBB902433ULL, 0x8107FD95E22E5B89ULL, 0x49F221A88B200081ULL, 0x9636E9B24B0F0663ULL, 
            0xB83EC565B2E00696ULL, 0xF72362BF7972AFBDULL, 0x77305704FF19FD5CULL, 0x2D9796F3220129B3ULL
        },
        {
            0xC1D42B2027DD2075ULL, 0x139FA33971B581A2ULL, 0xCEDF8D95B8634C97ULL, 0x2973AE47D5B1A939ULL, 
            0xEE686C6ADD316901ULL, 0xE8330A40A66C4F43ULL, 0x97767C01FF28B1CAULL, 0x02D4477DCEA5E508ULL, 
            0xE048B9487F86ECA8ULL, 0x6A2C76522B6AFA08ULL, 0x2EE8BBC652C4D62DULL, 0x0E1E62390F0C4653ULL, 
            0x2FD6239C462DDFEDULL, 0xBE10EF3632E41B41ULL, 0x3B2F0D6BDF728466ULL, 0xB712EF038F7B31A8ULL, 
            0x19AB498BFBD5ACD0ULL, 0x10A25F7005508E20ULL, 0xFDF113E204F040A0ULL, 0xFCB193E351A1A72DULL, 
            0x73148A691F83BEB9ULL, 0x85EB764B9ECDA03CULL, 0x35FCED765F48BC97ULL, 0xEBD03E48816CCED2ULL, 
            0x433CD26AA2698087ULL, 0x714207F8FC3F8419ULL, 0x01FCF1B7F15AED5CULL, 0xE7C1B97CF028FD67ULL, 
            0x16A1D278931737CBULL, 0xE526EDEFE3C101FFULL, 0x211C0FF46DDCA8DAULL, 0x5D3292F94C4A5F46ULL
        },
        {
            0x96ED076189D2C731ULL, 0x99520010216921EEULL, 0xFDE1D1A5A5BDE960ULL, 0xE471EE91C6F4F265ULL, 
            0xEB4B5002E5665D26ULL, 0x5609C88B5D44B6FEULL, 0xFF651912439A100AULL, 0x8F40727C00BA841CULL, 
            0x5C985527B58CE3BEULL, 0x781C2A42686274F5ULL, 0x55CBD0E6DF635F17ULL, 0x72A5284CDAE00729ULL, 
            0x47955929E7E49F36ULL, 0x1B9F738E6C6BAC27ULL, 0xB232D5F84C832A62ULL, 0xB2349FF6FE741D47ULL, 
            0xE9BF989C2B0D001FULL, 0x025293338A359C9FULL, 0xDA315BBD50B7EDE6ULL, 0xA534AD150548E027ULL, 
            0xF1E59FF3CC551BEDULL, 0x1F33F49EB562A52BULL, 0x34FD6DCCCBB3740DULL, 0xBA397DCCB52BEB15ULL, 
            0x5BA02EA3F8844E02ULL, 0x7F4501A5802557F3ULL, 0x3CA08C17823900E4ULL, 0x64EEDE89CFA838FBULL, 
            0x03F331FD45490A44ULL, 0xD6020E9ADCA38693ULL, 0xD11EDB357A17E64EULL, 0xDB5480426991BCE9ULL
        },
        {
            0x6C705D8C2B5B613BULL, 0xEA0F783B57525B21ULL, 0x40871D14AD3E7011ULL, 0x6C952393B4FB92CEULL, 
            0x5A23BDE1220AB7A8ULL, 0x1D93AFF39B9E03B9ULL, 0x5F085AC6DAB097B5ULL, 0x6F321685BF5C8062ULL, 
            0xE8FCDF95E9C9D752ULL, 0xC74550DA7CE5D255ULL, 0xFF0EFFF9601D5CA8ULL, 0x667C4E6ADF1762D5ULL, 
            0xD15306B5DAA1D55AULL, 0x2A121C0EE43485B2ULL, 0x6BE0DFA1EF679C04ULL, 0x413E7A5484DEAAAAULL, 
            0x080688667CB87014ULL, 0xAFB8A93F2B2CD374ULL, 0xE5EC1BC32657D5E2ULL, 0x49DCCE56595275CBULL, 
            0x20B1B5ABA35CF903ULL, 0x4272D599A4F7E54FULL, 0xD85B1537C8930684ULL, 0x7DAB38138DC97880ULL, 
            0xF8EE39E5FE58F9EAULL, 0x8C34516C6BCFD91FULL, 0x3C3D143A3A2FBA92ULL, 0xC46F93FC2E862575ULL, 
            0x22BF8060B15CAE5EULL, 0xD0BB122B0D7CD85EULL, 0x6C628CA82D42AFF6ULL, 0x2C35A257A12598D0ULL
        }
    },
    {
        {
            0x61FFD4BE61548DDDULL, 0xF0094ECC0182A058ULL, 0xC134BD023050CB2BULL, 0x1C6DC560F005C791ULL, 
            0xF802B7FA3E6EF75DULL, 0x00EF888282665D68ULL, 0xBB3723F92E15B0BFULL, 0x5DF973131C979ED7ULL, 
            0x6A04100181A9AC74ULL, 0x3B6E00D5ADA37B7BULL, 0x461E0A90781A332AULL, 0xF82791395C4FC00CULL, 
            0x3FEE2289188834B0ULL, 0xDD75469A5528E16BULL, 0xDA31F5B917DFB7F2ULL, 0x98034AB8A9256E4AULL, 
            0xD30BD0E6F66943CBULL, 0x1EFC98CFE4F4BF9FULL, 0xFDE2212D28DC2C1CULL, 0xC3C1CD285A7F01DBULL, 
            0xFEA0AF1DB3AC0BE0ULL, 0x4919831CD23E0D23ULL, 0xB716A1F562A2DA05ULL, 0x863A68033249AD42ULL, 
            0xC05F9D343C2035FAULL, 0x25CDE100A637D56BULL, 0xD4542E06D1E8481FULL, 0x215CCDAB4FF547C0ULL, 
            0x0B9A221663FC9926ULL, 0x061D824A581619C9ULL, 0x238C02EC7D06BB0AULL, 0xD7878BB567536B28ULL
        },
        {
            0x8EDAA835A0AACB91ULL, 0xA8B6BD31883D4747ULL, 0xC2A08004061C0D8DULL, 0x5EEDAD67481412B5ULL, 
            0xF8464312137A5624ULL, 0xAEA92130D5619BC9ULL, 0x8BF0021FF97F123EULL, 0x153ED3D6DF3F0407ULL, 
            0x0BD505F637950632ULL, 0x51D791B6E8C85896ULL, 0x357D093F6A57EF72ULL, 0x1E510BA0FA858956ULL, 
            0x3411D5B07120A6B9ULL, 0x464BF65616430481ULL, 0x3C186A9C97D6E7B6ULL, 0x6EA8230DB66ACF3AULL, 
            0x5B3B7CA1F15A3EC4ULL, 0xF3FB2561E3DBAEE4ULL, 0xD2B0DEB7F0571F2BULL, 0x184896A3C1EC37C8ULL, 
            0xB915524F10753FC2ULL, 0x57C667735BB8A710ULL, 0x4E119E07B22D7F74ULL, 0x196B7A49322CF1A6ULL, 
            0x985F08DB5F822643ULL, 0x9A8A8D1549BE30FDULL, 0x766C390E4FF98CBAULL, 0x500261EF73B3E80DULL, 
            0x75D75DF5680113EFULL, 0x3A69ECB596FBE54DULL, 0x92462B3F171938DDULL, 0xEF249F0CB55D9846ULL
        },
        {
            0xFA17346B86739098ULL, 0x8417489487813FBAULL, 0x0896379D6E15E594ULL, 0x3AF10EF12955C1F9ULL, 
            0x26F60CEA6221D911ULL, 0x16B8F381E8826E70ULL, 0x43619B5828802796ULL, 0xF54DD7F560389EAAULL, 
            0xA8EE23FBAC02DA8DULL, 0x6B08EB5F16FA3ED9ULL, 0x4B2A642E2B3DC4FDULL, 0xB372570BBC953501ULL, 
            0xF54E4229F6661BC5ULL, 0xF57F1324A5E3B3FBULL, 0xF2752F51A46E0F9FULL, 0xEFBFCCA400F07167ULL, 
            0x94D5D6774648B7B5ULL, 0x8B9C45DAFB28C087ULL, 0xFE58ECC460190661ULL, 0xF38050117D6A6214ULL, 
            0xAD76C8E3FC85D787ULL, 0x7F1EEB6CF4BBCA90ULL, 0x803A1A5D6174BD78ULL, 0x91789F731AA44EDAULL, 
            0x46A57026E39E968EULL, 0xBE25B9C1530DDB8BULL, 0x8A89DF48C3861B36ULL, 0x9B946421D1FE7912ULL, 
            0x50FAAC173AEADDB1ULL, 0x1875CA15382B5311ULL, 0x498C42A7B30C1192ULL, 0xF2F3C220E97F7959ULL
        },
        {
            0xB42BF0999BAB2952ULL, 0xE815DDE27924676AULL, 0xA3559EEC695F1DB4ULL, 0xF1DEB8F61ABD67CBULL, 
            0x5526F455241DE4F5ULL, 0x50C8DA8FE5F05538ULL, 0x1F55E4C6EFB7FE4AULL, 0xC8B8FF4E723055D0ULL, 
            0x40F16230676E046CULL, 0x0A88B233C3A480BBULL, 0x2D2B15A56B09CE8EULL, 0x8285BDC8DD5C7652ULL, 
            0xA3D91A9CAD78E821ULL, 0x35E2DA5AE5AF6137ULL, 0x0827E1F2E6D81399ULL, 0x234E87C16916E9F6ULL, 
            0xBD4803740BE83B8CULL, 0x60DA4A0DDA7E9A36ULL, 0x1060554F27715A4FULL, 0x8085F00515565994ULL, 
            0xB591C9DE6373A649ULL, 0xC432D81CF8873410ULL, 0x9BE5C4FFC8C35BA6ULL, 0xB52555F0AC1F82AEULL, 
            0x1BDA683466C7E498ULL, 0x7892F2C86FE40DBCULL, 0xEE96EE39CA846DB2ULL, 0xE3C1A9621FB31BD8ULL, 
            0xA06AAC8EFFF06462ULL, 0x4F71B0C7CDC1B4DEULL, 0x8BE2957B47B54B8DULL, 0x36C4DD4827700CADULL
        },
        {
            0x3F424EC35B1E8B6EULL, 0x1D387018A15E87D1ULL, 0x4256B743921D7C89ULL, 0xC1AB8380586D47C1ULL, 
            0x1B6B7C4C881FB99AULL, 0xE9DB093DA1D7B068ULL, 0x64D189D5B0279C04ULL, 0x08824A9997208EF9ULL, 
            0xBB9A1D63F8421D73ULL, 0xA857FC451EF4155EULL, 0x1F6F2D2735D1A169ULL, 0x84D260FDA0168D73ULL, 
            0x3B60C1B53EB8BFBCULL, 0x4555F5AD0B5A7970ULL, 0xFB6C0F5A2C636C10ULL, 0x2A61661D32CC0981ULL, 
            0xD49E730D31EB8A5FULL, 0xADEF075BC2836A7DULL, 0x9446A14AEE31E7DCULL, 0x26C0DFBCEA2EB578ULL, 
            0xDE4274683D6F6839ULL, 0xFDD8035C7C388D2EULL, 0x9987B9F04627DE00ULL, 0x5CE105714C177B6FULL, 
            0x5B743003B8F7862FULL, 0x69EED1586A23B60DULL, 0x9E54DC1F7257C485ULL, 0x36466D16DE3DF0EBULL, 
            0x5F0B1F7646DEBF2CULL, 0x4BF04ABB1116F46CULL, 0x7798D6DE5CD66378ULL, 0xF6BE14C46CE72921ULL
        },
        {
            0x5A42A4B28FE0BFABULL, 0xFFF9FF1048628820ULL, 0xE4FBB72F30FB9C61ULL, 0xD9420BFC0D5BFCD4ULL, 
            0xD42B8317B4FF5B0CULL, 0x46721B8021A4CD0FULL, 0x1107BCD8AF1C899CULL, 0xA3F81910F7999D15ULL, 
            0x47998BDA6687D5D8ULL, 0x707500EEB6667E97ULL, 0x5BA4A6D27C5F5E49ULL, 0x3668B3CCC5B9DC57ULL, 
            0x2CCAC8713BB55BE3ULL, 0x8C7D307E15EAC821ULL, 0xEB8C1D2DFFD9EF60ULL, 0xAA38343FDAB77853ULL, 
            0x0EDE3C76143048FFULL, 0x4A8DB3D0212882D7ULL, 0xA6F6B80B3D400727ULL, 0x6DB3688471133797ULL, 
            0x8AB820579D2507C5ULL, 0xE03E795C719D0F68ULL, 0x417AFFDF9BB6159FULL, 0x10A798AFB73890E5ULL, 
            0x9AD7F5EA44B166B6ULL, 0x2BBBBEBB4EF80560ULL, 0xB896749420670D5DULL, 0xB08CD7276B06F073ULL, 
            0xFDC1C84185B9AF35ULL, 0x537BADB4B21A8909ULL, 0x558FAE9A34513A9FULL, 0x9692F5C4C0554275ULL
        }
    },
    {
        {
            0xF265932234DDE18CULL, 0x1F81D31BA127FBD6ULL, 0xC3341DFB38DD9F56ULL, 0x1941735464A0D3F8ULL, 
            0x11DC7EE3894B459CULL, 0x320C4BAAD321E2F9ULL, 0xF526F1743929E199ULL, 0x770C68D63D8F48F2ULL, 
            0x52D088ADEEADA367ULL, 0x1F052BF36246D9DDULL, 0x0766F9138C1273D3ULL, 0x5281B140FC347BEEULL, 
            0xDE2341A67F6CC9BDULL, 0xEA0BD1BBF0973E50ULL, 0xFF989BD0F1996CE8ULL, 0x976DE4D8E3DF08B7ULL, 
            0x0887308CE5324FB1ULL, 0x170D3F856B430BB6ULL, 0xFE7545A5A3663AEFULL, 0x8D5401077FCF2D08ULL, 
            0x85A4D40044B167D7ULL, 0xB554408B582173B5ULL, 0x59C03CB34440FE3CULL, 0x685B327464DCE555ULL, 
            0x59EDF35BBC104B89ULL, 0xCE6665CE1A9A01DEULL, 0x1759536FAC19E062ULL, 0xC8FDF5213B67E3E6ULL, 
            0xF0177C5CEAA7E59DULL, 0xD198C0C5B936730EULL, 0x2654561A4736639FULL, 0x39D4488C670DCE64ULL
        },
        {
            0xA173111986F2A2C4ULL, 0x438F4415E02CDA38ULL, 0xB86A435955E5E276ULL, 0x416025FD8F28328FULL, 
            0x5FE6B660707362EFULL, 0x3987C44C369D830FULL, 0x726A3758F2AB741DULL, 0x4137C799C8EBEBC1ULL, 
            0xBDE21CB9D7E03977ULL, 0xC4B493A530C83F57ULL, 0xD429B6C480A5DCDAULL, 0xB63B5C4BC67CBF97ULL, 
            0x93653AAC3F7C36F8ULL, 0x6765156360024004ULL, 0xD00A2E1E72AB44F5ULL, 0x641FF0A28D049B57ULL, 
            0x4B11826505A8F367ULL, 0xC06AB92C5C2E130DULL, 0xD2D9D8CB80822551ULL, 0x5F17604E4EA5E050ULL, 
            0xA5D3EFF133948166ULL, 0xD07705FFAE7003D0ULL, 0x63B170756037272CULL, 0xBF7EA9EE7A9D793FULL, 
            0xD2E61029E0F59E1CULL, 0xB79A0AAF57C16E9BULL, 0x9BA34645DA5CB66FULL, 0xA217BA18B5FB9B6DULL, 
            0xEA7234C58F38FF41ULL, 0x8370DEC12DD00CECULL, 0x5091138DD29216FFULL, 0xDCB9BB3F3BB380F1ULL
        },
        {
            0xC5812FCC3342D816ULL, 0x5A5EB5FC7810E0E4ULL, 0x8C621C15FB8B5BEBULL, 0x55CB1F1D0DBA23D1ULL, 
            0x0ED351A263A121E2ULL, 0xF1EC03C6DB761C9DULL, 0x79254627647111E3ULL, 0x8430CDCF35780A23ULL, 
            0x3D72EE5B72ADC7D9ULL, 0xBDD3672444EC72E9ULL, 0x593A7EA931B8DAF9ULL, 0x0B65EEE9AD7C391CULL, 
            0x4BF30A6FA3F6B808ULL, 0x9949D656DD4BC14FULL, 0x4F171E8A6FE17941ULL, 0xAA1D95BE8065A4AAULL, 
            0xB7640FCB938880D5ULL, 0x9AC12E3B551109C8ULL, 0xE6E08AF0B558E8F7ULL, 0xC1CC1980734D2247ULL, 
            0x7D2FF3E3E516074DULL, 0x95236BA5C7A4FAB1ULL, 0x7EB1E1F7962D28E5ULL, 0xE025FA0C0A96CC66ULL, 
            0xB99C32756E39BA8FULL, 0xA3B00FFC0B268523ULL, 0x3701EB9AD77DB48DULL, 0xFDAE20BEBDCFA06BULL, 
            0x6BD3B35823FE8315ULL, 0x853BAF1659FEAEB0ULL, 0x497288618579DF24ULL, 0x281C6316C9B7B406ULL
        },
        {
            0xA67703DA130A6021ULL, 0xBEF232524A789B14ULL, 0xFAB1C637852603FAULL, 0x24A02D982E9FF35DULL, 
            0xA01B93A5E47FE5C7ULL, 0x173943CF891AC417ULL, 0xC032955169C936C2ULL, 0xB56337533F00D0CBULL, 
            0x663641BF5C424617ULL, 0x43029E3F57C950AFULL, 0x4437EA989A2C482CULL, 0xFC50C0D93548A45DULL, 
            0x4A87D90570BC5265ULL, 0xAF9DD686B82B3BD8ULL, 0x9133AFF441958E9EULL, 0x86DC87D79F6EDABBULL, 
            0x50AAAEDE6133BD98ULL, 0xB37737613283D614ULL, 0x88D4DA3982709A06ULL, 0x504C119CCF4805AFULL, 
            0x9152F38E94F20935ULL, 0xBCE3BC00D47B20CBULL, 0x49C478B520CB9717ULL, 0x5375DE2E8672F46CULL, 
            0xD1BCAAD963230FF5ULL, 0x938B7F8D315733DFULL, 0xD7CAE31730609EFFULL, 0x04D4D3C54A4FA61BULL, 
            0x7C3ACF896D1F6893ULL, 0x046640E06C5F1B04ULL, 0x26BFE95C15AAD460ULL, 0xF112BFB498317EAAULL
        },
        {
            0x117B956D9473AAA0ULL, 0x43DC7A62D4714AE2ULL, 0x4B3781E90F09D772ULL, 0x74043AC07C0973E3ULL, 
            0x0D9117C67E33E4F7ULL, 0x4F82007171E49EE9ULL, 0x717BF9EDCD13DDCAULL, 0x25CC6F3B618496AAULL, 
            0x0920A966DA69A255ULL, 0x8443D6A2CD197DD6ULL, 0x3E857C9844C0A606ULL, 0xE01E08FD0A38A87BULL, 
            0xCC01359DC024DBD9ULL, 0xD2D31A387B0539DFULL, 0xA01D124853167CD5ULL, 0xDEDB418BFA81A16DULL, 
            0x40727135C2C62A22ULL, 0x9593DD2E2E4BBE44ULL, 0x09195F446C22A68BULL, 0x665EE012E3F46025ULL, 
            0x607E49F06D02E1C4ULL, 0x8865591F79A91D13ULL, 0xC3F204201E604AC2ULL, 0xC18E023030E480A6ULL, 
            0x660F23AF1C3C60BCULL, 0xC94E567E6CA3BF2CULL, 0xE832499F19E4BF13ULL, 0x7448BA02901E7546ULL, 
            0x7B2304222B86B621ULL, 0xFCC4B60E0B8724A0ULL, 0x6EBFC36EB58E61B8ULL, 0x52C800AE3C1D4145ULL
        },
        {
            0x5D7024EC32E14CF7ULL, 0x9764B912C00DC170ULL, 0xC0AB1D59000A4C0CULL, 0x44050271CED864F7ULL, 
            0x81C23EE34E816518ULL, 0x9015FBA441E9D675ULL, 0x2DEF86D9CC377C18ULL, 0x92E508F7D2AD9F8FULL, 
            0x0A8717FA2D653793ULL, 0xBA92CCFA989CB996ULL, 0x97ABF2C83CBF671CULL, 0x21A6F29425FABFD0ULL, 
            0x171D20F7BA870180ULL, 0x1AE139BF7909B8ABULL, 0x579220272E0007E5ULL, 0x52077B966134669AULL, 
            0x4D59667EFB13A0D0ULL, 0x6174432167C68727ULL, 0x69325C67AA097E0AULL, 0x08CE3D2303978E21ULL, 
            0x987C1352474EB0AEULL, 0xE3A82061687DF006ULL, 0x9291CD48F3D33B08ULL, 0x34E836AF6EC0ED81ULL, 
            0x009D2CC19D3241F7ULL, 0xA444D58A26E9C789ULL, 0xAC4DF1396FB33FAFULL, 0x550BC062737DD91CULL, 
            0x3EE04C89C6392F4EULL, 0x747991328A931190ULL, 0x90205BB112EA86B6ULL, 0x00F96F6EE2DAF097ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseCConstants = {
    0x2524C491D544A461ULL,
    0xC62527E74BCED2CAULL,
    0x4CAF7D047DB989D0ULL,
    0x2524C491D544A461ULL,
    0xC62527E74BCED2CAULL,
    0x4CAF7D047DB989D0ULL,
    0x4684DA235E80FC21ULL,
    0x1D8E81E9267ECB09ULL,
    0xFB,
    0x2B,
    0xE6,
    0x76,
    0x99,
    0xB1,
    0x12,
    0xE5
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseDSalts = {
    {
        {
            0x49BF8811610A22C9ULL, 0x6B1EC743D5C647BEULL, 0x31ED4ECC13EDD55FULL, 0x371C6B431E09C1E5ULL, 
            0x7DFA96836BD4C2DBULL, 0x7FE42264A4E4202FULL, 0x5717B44DBD766770ULL, 0x77BB56FA069E22EDULL, 
            0x485C8DD8C7695D2AULL, 0x684F6A78CD1278B0ULL, 0xA1D6552E28F94493ULL, 0x7855CD3636581C62ULL, 
            0xBD82CDF118BB23F4ULL, 0xD0C2476D089DB409ULL, 0x0F63C808A4C0E4F6ULL, 0xBC71FB009D8565A5ULL, 
            0xA2889C78B96491FDULL, 0x67B92DDA93185A5AULL, 0x70047ED35DBA2E04ULL, 0xDAFFC78C4B36290EULL, 
            0x1EDD1C52AD4C8A8BULL, 0x493AA19C41D85932ULL, 0x24117D3D19E5F52AULL, 0xDB897B947620F77EULL, 
            0xBAEBF235C695D69EULL, 0xD21FB2050F4E8160ULL, 0xA1AEF7C2D23F87D0ULL, 0xE191979AB6304492ULL, 
            0x2341369B42840094ULL, 0x2C54F8B1A86879B9ULL, 0x3EE3980A43773987ULL, 0xB91DACA85378B00BULL
        },
        {
            0x310EEC61B3937604ULL, 0x62A7DC1E03D855FDULL, 0x7BB5E73C48B43756ULL, 0x2FA903B24551B2E0ULL, 
            0x555F2AFE2E0B57B9ULL, 0x8768E6CED5C6BB7FULL, 0x7CCDF6CA47E06458ULL, 0x548CFA46550DDDADULL, 
            0x32EEA316BA89C7DFULL, 0x2833427E9B7EAF08ULL, 0xA43BAF609CC034D0ULL, 0xADE9B9121594227DULL, 
            0xB27A0E2C883C18BDULL, 0x9967488083116DAAULL, 0x820DAF7CE291E79FULL, 0xDEDF8FD8C7F057EEULL, 
            0x9AE21C116E3E7305ULL, 0x10A3E37BCB1E432CULL, 0xEBC098512C3E1027ULL, 0x573ABEF8747DB7ECULL, 
            0x2D1AE5D43B00E7A4ULL, 0x4CCA4B827847A0A4ULL, 0xE61390B2BA5ECC9BULL, 0x899AF004FD495491ULL, 
            0xF416F715007FF993ULL, 0x76493DABAC00D850ULL, 0x7583A3AEC0805BC4ULL, 0x2920E13F7EDAF6ACULL, 
            0x8C7327657DB953B2ULL, 0x561FC32F41A8E18BULL, 0xA5A1AE16A1E9C8E4ULL, 0x87A729FC9F48829BULL
        },
        {
            0x21C0EC8D6C014C7DULL, 0x700A3B8B8F4980BAULL, 0xD8FC53718E64F3FBULL, 0x30CF904BA0FACADBULL, 
            0x7177236C24920B55ULL, 0x67B438E5DF587A3DULL, 0xAA68B51CEFB34965ULL, 0xC80567A568A7D821ULL, 
            0x4AAC6064704E909CULL, 0xDF53D2A48CAED384ULL, 0x299B1DA6996C1C98ULL, 0x6B457DF11A42640CULL, 
            0x0E73CE0FA0DAD5F1ULL, 0x129BFAE526655DA4ULL, 0x8EB303ED8C3E01AAULL, 0x2D5F1FE4CF26CE15ULL, 
            0xC1A694D32D29DFC8ULL, 0x853AEE4448F7AE2AULL, 0xAE42B9DC4129A0D9ULL, 0x7F0BED9E5757637FULL, 
            0x0004FA934CD72BFCULL, 0xBFA10F46A858BD6EULL, 0x6EEAF9E1D14F1092ULL, 0xFBB4C2E793310B6AULL, 
            0x8FC0E48250654EF2ULL, 0xAE3F3703D7AADB77ULL, 0xB1E24FA093A5ABF1ULL, 0x82414051E0A71465ULL, 
            0x7736D315E3598543ULL, 0x1E763D595F022B31ULL, 0x5F760636BDB91266ULL, 0xE9791D87990B87BAULL
        },
        {
            0x22EA21C558EE742BULL, 0x76C28B2EF5A9829EULL, 0x52DFA0C967D8B7D8ULL, 0x0D2B4872B42728F1ULL, 
            0x158DE5E6318D0A6DULL, 0x0FAD80A60A869A9FULL, 0xB5BAA68FF35E7DC2ULL, 0xE3FF21564DABE838ULL, 
            0x21D32D630EE8D339ULL, 0x950ED0C6C44B0693ULL, 0xEF83B5931620B586ULL, 0x7126ADC562A73FC9ULL, 
            0x52D13A371C0A797AULL, 0xD763D08E6BA24CA6ULL, 0x842D4DB0C376B3F6ULL, 0x796B9FED48C7240FULL, 
            0xE720A48FE5511072ULL, 0x0353F610CA2175DAULL, 0xFA391F9E7ABDE057ULL, 0x7172EB87CB288152ULL, 
            0x2AC133057D0967F1ULL, 0x0078710190C80702ULL, 0x921405BF0D6EC557ULL, 0xA7798968B6563739ULL, 
            0xF72608FFCB670EB8ULL, 0x6D3A11095C711D3AULL, 0x5A32BAB497D41827ULL, 0x376D17CE2B4DD6CDULL, 
            0xEAC9DB4B411A81B4ULL, 0x00E91CA7B1298229ULL, 0xF1E003E10258A5A7ULL, 0x0D4C942A0B33BDA1ULL
        },
        {
            0x0836565D0FFF65A3ULL, 0x3E616424ED7F06DBULL, 0xCD2D5722110218F1ULL, 0xC795456145DDFD06ULL, 
            0x3F84318DFDCFB478ULL, 0x3F518C44AEE344E5ULL, 0x6D9468A935F4BCAAULL, 0x351D60FC7C9C9A37ULL, 
            0x354A78935FDBADC0ULL, 0x922E8FA3F0CF17ACULL, 0x983591195EE25217ULL, 0xC99875FD5F8C93B1ULL, 
            0x18157C028094E159ULL, 0xE1A072FCB83064B6ULL, 0x07B0712E4A5179C9ULL, 0xBC648D5B66CE769BULL, 
            0x48E1E7E318E7A7C9ULL, 0x1BDE151F2892A00DULL, 0x61112EC47107B9C0ULL, 0xE074BAFF18FDBC8EULL, 
            0x72A842DDA5286DA3ULL, 0x581F24037ED234AAULL, 0x3AF60C96AF5E4442ULL, 0x9F6ECC5A0652E1BCULL, 
            0x54B19F6B33099D9AULL, 0x921623C4EC88A98CULL, 0xCDB7319E3436302BULL, 0x7F305FCEE6EABA14ULL, 
            0xE54334F31E8506ECULL, 0xBCBD29754B4E0F8CULL, 0x1854352324C59A5AULL, 0xE6F37CF2F852956CULL
        },
        {
            0xF48C1249AF27551AULL, 0xCF5873B019E5E046ULL, 0x69A50FC79CE9D5BEULL, 0x7869F7C973866E73ULL, 
            0xA68525E42908AD70ULL, 0x4036F26A150449F1ULL, 0xA0D14FC67DBF0D45ULL, 0xD330007964D0F2D2ULL, 
            0x699B2E8CC693C06EULL, 0xF055293CAA28F3AAULL, 0xDB94A72A7B6FEB6DULL, 0x192B9C6BAA1BFE4CULL, 
            0x9A7E142219DDB93DULL, 0x76395AF8FB36F3B6ULL, 0x54BE9A3E3D04EC76ULL, 0x4DF2A5BFB820FC37ULL, 
            0xAEE94D072781FE29ULL, 0xEEDE5D9BD43A1B2EULL, 0x84972D35BDD2D583ULL, 0x535237A562F59B31ULL, 
            0xEF71E7D809ECFE65ULL, 0x23ED8B9765DE6EEBULL, 0x2EE2ED96C8B911A4ULL, 0xE7A7E2C2F368EF8DULL, 
            0xBFA719A4C6AF8859ULL, 0xC3A2600C16C4DD75ULL, 0x49F2ED9FFE877C3BULL, 0xCF850D22613504ABULL, 
            0xB34D338B211FCB7BULL, 0xC48BA2DAE59264F7ULL, 0xD8DDDAF89A54AE9CULL, 0x9324B5CA70AF0D0EULL
        }
    },
    {
        {
            0x41DDA72B3A84B8CCULL, 0x03F5123D6F92CEB5ULL, 0x8044FAA2340621E5ULL, 0x7CAFC35DB76638E9ULL, 
            0xD820977EE12098BDULL, 0xB8D366EC4A09D518ULL, 0x5A483288447F43B7ULL, 0x9A01261C05624D3EULL, 
            0x5A4675567340E0E0ULL, 0x22E9E62DED650095ULL, 0xB65000E883044DA0ULL, 0xC082D5B78F18E5CAULL, 
            0x13385AC5E62EDB37ULL, 0x827AE09D611F17D8ULL, 0x70EE8D931EBC214FULL, 0x07275B1C5B53CD5AULL, 
            0xD6207B3B2540B8A5ULL, 0x0CDD0C4B57A1EF53ULL, 0x7ABD80EE127F118FULL, 0x7BBEB06DF7EA77B3ULL, 
            0xEFB8A0A78950564AULL, 0x0DCF6C8C2F48C452ULL, 0x617D80719F1D4BD5ULL, 0x9EE22384A96D8076ULL, 
            0x109234E16D95E338ULL, 0x5C239653F3F9C00EULL, 0x7FABFC2C5D4E6CF4ULL, 0x3604CCBF3D284CD6ULL, 
            0xEA5ADEBD675AA63EULL, 0xEA77D1F138C5B17BULL, 0x3EBC8FFF0CAC74B5ULL, 0x8174DE3DA2C95AD8ULL
        },
        {
            0x24EF3333ACEA2C11ULL, 0x0E5611E692D36148ULL, 0x2408828FB2CE5DFDULL, 0x5A0D94782BDB363BULL, 
            0x0CE4F68CA57E3D08ULL, 0x077E5A6999AA6618ULL, 0xDD73E670CA6ED8DAULL, 0xDFEE293895EFC525ULL, 
            0xB6B568F430B10056ULL, 0x3F452DA244770C7BULL, 0xBEF621B44E45FD84ULL, 0xAB4D99876BD20434ULL, 
            0x04B16D0975274A27ULL, 0x88A2C43D0F4F9E92ULL, 0x07757031D4D53316ULL, 0xC608F59CF53ADC18ULL, 
            0xA09C3B589337884AULL, 0xC479FF5A247EED75ULL, 0x20A091B805DE72F8ULL, 0xB835F58FAC9F71FEULL, 
            0x57CC6DA77C8D7DC9ULL, 0x48F430634F92C726ULL, 0x9130E5F6DE1873B4ULL, 0x5DEBC6314FF52389ULL, 
            0xDD22933E42C2990DULL, 0x97762F8B47012A2DULL, 0xC7D87E646DED1B03ULL, 0x3936C27DF429B4B0ULL, 
            0x540BF75EC337FEADULL, 0x03072BB9C90F474CULL, 0xEEAC2F98445B4F0DULL, 0x97E7CD26ADCF06C8ULL
        },
        {
            0x2899262622FD109DULL, 0xBBF7681EF487908EULL, 0x3D99583F2E1622F8ULL, 0x9EF162A255C211DAULL, 
            0xB13F574F4C2C74A9ULL, 0xA0933845A53FAA43ULL, 0x15198EC9CAFF1E53ULL, 0xAB58E7DA7A3FD548ULL, 
            0x502D3F651160B622ULL, 0x2B56D0CFD8D0DC5AULL, 0xFD51F6BAACE759D6ULL, 0x9F76B15589CD9674ULL, 
            0x731A1CCD5A407BCDULL, 0x5A417DDD6FE07C6FULL, 0xB392146A58A8ED93ULL, 0x67793D7412A8F84FULL, 
            0x2668F7D116BAC0D9ULL, 0x227377DFFBB57BB3ULL, 0x478B227713D6C038ULL, 0x433970BE2BB0E433ULL, 
            0x3EEB435B35CC198DULL, 0xF039BBD8F641751AULL, 0x184B3EA95D00528DULL, 0x7E3C935EF6D1C3F0ULL, 
            0xC7F6A05650985130ULL, 0x5AB595AA315C5779ULL, 0xCB978B61F92366EAULL, 0xD0D444C291FDC251ULL, 
            0x85307983176D44E6ULL, 0x316DB892AE3AB69EULL, 0x73D5416743F1AE91ULL, 0x6F3AA72FF9F83F9CULL
        },
        {
            0xAEB36B924A2159F2ULL, 0xF1B99252D86C07B0ULL, 0xF504274135D05CBEULL, 0x25AADFE0FCC0ACA3ULL, 
            0x416FF1B58F7D1BF9ULL, 0x4A0AD8E6F3B85C6FULL, 0x7A22EEA7E1100DE0ULL, 0xF3A46F1EB6974AB0ULL, 
            0x9672462311DAB463ULL, 0xAF87D5C701606478ULL, 0xA5256B7E2AEFECF7ULL, 0xDFCD195F0EE4AC72ULL, 
            0x25978C7968B86035ULL, 0xEBE923BA54E00B4DULL, 0x164E31626A42B32EULL, 0x77E70087CC556CE3ULL, 
            0x379B09E4B841777AULL, 0x64E2EBA0F0FF4AB1ULL, 0x3CE36EB0799A1B04ULL, 0x1F3425B8B52EBA8DULL, 
            0xBB34AE92FEFADDA5ULL, 0x5A99716A24BA83FBULL, 0x14E2F9274C63B3F7ULL, 0xAD2D644278E16E75ULL, 
            0x8817B8256E953BC6ULL, 0x1EF6FDDC4C32E2D0ULL, 0x9F7C1D8191D47BD8ULL, 0xA40744FDAB435217ULL, 
            0x2ECDD94EB4DB6888ULL, 0x664421FF5FDF3CD7ULL, 0x120EACB791B24B89ULL, 0xE4291C87CDE8B398ULL
        },
        {
            0x12DC4BEF46602EC1ULL, 0x248AEB818188D9EEULL, 0x51736E8180E14BA3ULL, 0x5F15B60041075870ULL, 
            0x2A4FAFE409C222ADULL, 0xA6EBB9351CBAA7ADULL, 0x73C6F58855686202ULL, 0x1F0E47D1927E73DFULL, 
            0x2E36E7FCBE52EDDAULL, 0xE90F668F76A87A7DULL, 0xCD26B3E06B0C562BULL, 0xEDDBC0F14D50A89EULL, 
            0xA82D62384645EFD5ULL, 0xB0A033223D8C4D93ULL, 0xC8261149B4F72B9CULL, 0x8269243C7DCE3C8CULL, 
            0x06D86F56E6923C26ULL, 0xA7CFD390A033EF18ULL, 0x6B6AE74D6B0C0F33ULL, 0xF7BBBEFD1EAED54BULL, 
            0x9B8F7B88E09D350CULL, 0x6E739F0A9847C9F6ULL, 0x741FA37C941709B2ULL, 0xD19E6E1B0C389D33ULL, 
            0x171498C1486A45F6ULL, 0x40A6F236EB91D0FBULL, 0xA77136A71630CD96ULL, 0x1DA8A5594EA196BAULL, 
            0xE91B9242C209F813ULL, 0x1980F989AA4A846EULL, 0x474A23A1A5251172ULL, 0xEDCE8C4CE86A0153ULL
        },
        {
            0x8312479C6D969F5CULL, 0x56F469E07297662AULL, 0x0E11B0C098AD89A1ULL, 0x51378544E5931801ULL, 
            0x05D61B7726687929ULL, 0xAB8A0450D45B9FFFULL, 0x3CA2A6181BBFE4F1ULL, 0x67E4FD8A1CF5F978ULL, 
            0xCFC4D2ABE96E12E8ULL, 0x33A9D647D4F292E2ULL, 0x4190F6A036632E71ULL, 0x438FB9F684141430ULL, 
            0x5B526FD721821544ULL, 0x047111FDE91A9B4FULL, 0x2B0DFEDE68635D17ULL, 0x74C1B2A78AFC2C1BULL, 
            0x9EF34D4631AD04E6ULL, 0xE537EC7BD4D60F06ULL, 0x8E7010F1680ED208ULL, 0xAB41C0010045E064ULL, 
            0xE7B6136C7E76CC38ULL, 0xE2281081347EA577ULL, 0xDE96BD1295433DC5ULL, 0xC15D5CB6EB516B29ULL, 
            0x989BAFC8DF987608ULL, 0x82689FA872EE8702ULL, 0xA54C87BE5185E1BFULL, 0x6E02204E02225079ULL, 
            0x9EB56461416F0899ULL, 0x0592D693009A9149ULL, 0x9D8FAA0AB63C81ADULL, 0x6F3FAD218F299F38ULL
        }
    },
    {
        {
            0x7670065799E44F97ULL, 0xAD548A775995E10AULL, 0x8A1EF0CE68A0ACD9ULL, 0x365587D06232014EULL, 
            0x86BEBB471751B418ULL, 0x7654E876253EAFD0ULL, 0x5EA46A9205D5C719ULL, 0xD2A01989AA5CB3BCULL, 
            0x831C3B478D025F3CULL, 0x7DCCB0D0618E7F56ULL, 0x411F0ACEB140CD87ULL, 0x32C802747DD902C7ULL, 
            0x61B7CCE26A852AE7ULL, 0x4C9D4EEEBA127D97ULL, 0x70C1E26354BA2072ULL, 0xC3D18969236B7195ULL, 
            0xF04235BA10F55857ULL, 0xBA5369856637C4E7ULL, 0x13198E341A55580AULL, 0x630AF3FE532866B0ULL, 
            0x8C86EB1FED03F47DULL, 0x0E04CCD20DCB732FULL, 0xC718961AEB07A360ULL, 0xCEA0ED615FA78505ULL, 
            0xAC9C411F2F1663C4ULL, 0xD9FBFE0BFF9E7D19ULL, 0x2D94D705FC149310ULL, 0xE091568A661B8088ULL, 
            0xBE5DDEDA87F2D38BULL, 0x1D6FEDDD1E26642CULL, 0x173226BFE056B053ULL, 0x3A9DF8DDF5E4AB11ULL
        },
        {
            0xE53DEE02BF53A562ULL, 0xDD2FED4E0AC32A2AULL, 0x16F4C4C1FB409A42ULL, 0x8366D932AF7B894EULL, 
            0x56DA350F51236FB2ULL, 0xBAFC6C5B261AB883ULL, 0x0992FBA7D46A596FULL, 0x037BE29BD67208A9ULL, 
            0x38817995774F0675ULL, 0x0EA23AD6F1E60AA3ULL, 0xBAFA55EB4292A27EULL, 0xD6A04DB8FB826995ULL, 
            0x479952CD11FD0102ULL, 0x52FB9AB09E4DFA9BULL, 0x01697EE09D4DF938ULL, 0x9F673088AD2FD10BULL, 
            0x085F4AD0AAA0E9E6ULL, 0xE57C1821A29DD9FDULL, 0xEEA36541AFDE505BULL, 0xF3AF8F48B68959DBULL, 
            0xFA5C625194106134ULL, 0x5DE0C9DCAA9F71C4ULL, 0x0C3DF89B996D778CULL, 0x43F5EAF83697C7B5ULL, 
            0x0C26ADCD7F0573ACULL, 0xC87C07CB540AD7D7ULL, 0x9A3EA5EBEFD97C80ULL, 0xAB876498E8CACDA3ULL, 
            0xF2486DD1DC03C68CULL, 0xF06B0B0D3DF6D147ULL, 0x1CDC7A155C5B8BC1ULL, 0x5C8355679B579B06ULL
        },
        {
            0xA096C87732C1E5BFULL, 0x61BD6AA3CA4F48DCULL, 0x2AABE6A7DFD0F36CULL, 0xA7578D30369F9445ULL, 
            0xFD10CDEFFF0A9E8AULL, 0x97CAD6652DCDBF18ULL, 0x86C0EAD7B19C8FB7ULL, 0x51C9CB6D8814E604ULL, 
            0x8DA7D0166376589DULL, 0x5016889DAEC3772AULL, 0x7141A5FCAE15BF0FULL, 0xB88309CCA70CF784ULL, 
            0x599E8FBB77AC6E0BULL, 0xC11CF8E986597F59ULL, 0x7B9E1B4B2994CEF5ULL, 0xDABEAB1C873F0BA0ULL, 
            0x3943C58711784C73ULL, 0xC679DF638A2DD962ULL, 0x6C6E6A86D589296DULL, 0x693FB359A39895F3ULL, 
            0x18B6090CD47A4B99ULL, 0xC72F256D01B7672AULL, 0x247B32C277FD51F1ULL, 0x056C09AA1F8563E7ULL, 
            0x7718747DA2483CB6ULL, 0x9A8EEC217810D6AEULL, 0x75EB22C74B0FE56CULL, 0x6A999DEBE967AC02ULL, 
            0x2836FF3480C2BD0CULL, 0xA36076CF747258BAULL, 0x1F2C696F216F408DULL, 0x410D704BB5264816ULL
        },
        {
            0x8E4F44DA19748DAAULL, 0xBF3F4FAB331BA74FULL, 0xCE87C453191D910DULL, 0x09F0B000474C1554ULL, 
            0xBD1281AEF7EC4AE7ULL, 0x8B1193249521B830ULL, 0x435362FF8EC1B457ULL, 0x4A8DD321E74007B5ULL, 
            0x995C0444B8ED6953ULL, 0x318FA276932F8771ULL, 0x8E8731648BFBC9F6ULL, 0x05E6F1FBBDE42573ULL, 
            0x0098217784D5D1EAULL, 0x28F7FE813ECFDC98ULL, 0x063D0964E20E0585ULL, 0x19336427E854EC29ULL, 
            0x0CF6586D8A5C1BCCULL, 0xC62865E371460278ULL, 0x586D83BE186E8B3EULL, 0x5952298E351F8452ULL, 
            0x4FA7A21B75783AD8ULL, 0x39A1DD32D7A826BBULL, 0x82EA87A651D8A612ULL, 0x4628C846E3D08034ULL, 
            0x2644ECD29AEEB2B1ULL, 0x57D67F90279B826DULL, 0x2A3B33DDA29449F9ULL, 0xDA65E83BFB32E921ULL, 
            0x78D67E1DCFB16F81ULL, 0x5BBD1AA1B8B2F4AAULL, 0x510750E507C293B5ULL, 0xAA204E994A0462E9ULL
        },
        {
            0x10F8B4F94DD896E0ULL, 0xB5DCB18C9C2B803AULL, 0x27C2AEF05EE98F29ULL, 0x9B3C95ECDAAAD80FULL, 
            0x1604730CEC9EE96EULL, 0xDCBFF1EC36FE8EE2ULL, 0x991BB0E279DF49F9ULL, 0xF3B575D047930ED4ULL, 
            0x19B9FF769D04FB5EULL, 0x605AE8E1168E61D7ULL, 0x30B9116A77D0C3E5ULL, 0xD13BAE222943BE0FULL, 
            0xC579C336DEBEAF34ULL, 0x88C90610182E494FULL, 0x0CD13D9DFDA538EEULL, 0xB71332C6B1ECB237ULL, 
            0x17A0978E06131003ULL, 0x242899C198B5DF61ULL, 0x8239F659700307E0ULL, 0x522F11579CFC8312ULL, 
            0xCCAC84A077BE8020ULL, 0x40A284B5E18629FDULL, 0x24A445F7D1A48C36ULL, 0x3563302056B82F3FULL, 
            0xB99564699A6613F4ULL, 0x074ED61C355A8EA2ULL, 0x995D1AC5FF936E05ULL, 0x5041D53B44839711ULL, 
            0x87E488C8CF291043ULL, 0x58A086B314CA5F25ULL, 0x25CFB8F869DF35A0ULL, 0x2A24C398B45A6B53ULL
        },
        {
            0x5102A33031CB85A8ULL, 0xF9A4F6AC9D4F24DCULL, 0x5108177A5BAF667AULL, 0xFAE81EBB3AE731A5ULL, 
            0xC1C0B8FFFA0A08A8ULL, 0x887101EA32437269ULL, 0x065FCFE412F1F53BULL, 0x9D9AFB6CD16173E2ULL, 
            0x34D5392920E76ABBULL, 0xA5EF980808A4FF0EULL, 0x2D9B0C164F546392ULL, 0x37383AB30EA766C3ULL, 
            0x31CB26E65ABCCBA9ULL, 0xF2A3B8462696DA0EULL, 0xAD1531AAC32BE6FDULL, 0xC3E54B683F5DB1DCULL, 
            0xE1327AD3AEC3A392ULL, 0x82603EADC63F619BULL, 0x66ABCBBB17DBCC9BULL, 0xA4AB8A4BDFADBEEBULL, 
            0x9588A3A601F2733EULL, 0x41B4BC8A682E8AF3ULL, 0xBA343227F9FC95E6ULL, 0x2E4A34251F46830EULL, 
            0x20B18C1335F3D3EAULL, 0xDF13FE3ACDD14B91ULL, 0xC8D93E245B52E0F3ULL, 0x80CCD5D8538C70A9ULL, 
            0x742E21B606BA58EDULL, 0xE3C63881C836A782ULL, 0xE19283ABFA705D4FULL, 0xEE41315B77EBBA1AULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseDConstants = {
    0xA48A30BA9B5BBBFEULL,
    0xC9DF83FC57DD974AULL,
    0x4EB83CA52B520DB4ULL,
    0xA48A30BA9B5BBBFEULL,
    0xC9DF83FC57DD974AULL,
    0x4EB83CA52B520DB4ULL,
    0x6E91D933454373D8ULL,
    0xCF57E1F988807EA7ULL,
    0xC9,
    0xF2,
    0x89,
    0x92,
    0xAF,
    0x14,
    0x23,
    0x09
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseESalts = {
    {
        {
            0x76B3FCC9D47ECBEEULL, 0x1246F3FF57FB36A7ULL, 0xA15A649BBB0EE2CFULL, 0x33D705B61E32B644ULL, 
            0x18460C703CE8938CULL, 0x8EC5AE8132AFCB71ULL, 0xDAAB79B3F98CEE98ULL, 0xA936959E0265F58BULL, 
            0xFA73F0A18BD2A1A3ULL, 0x00F2C9359311374BULL, 0x79CBF74A7AD8A4A4ULL, 0x1A46F6C9687BEA3BULL, 
            0x5143AD3A6B2E131EULL, 0x041F9B3A8675B04EULL, 0xA1DEE1F8610AAE6DULL, 0x790BCF12F836499AULL, 
            0x5B1F37FB72A1D6E7ULL, 0xCEE6E7EF8DBD6DC6ULL, 0xE371CED4B9AAF955ULL, 0xF42994E913EBD0C7ULL, 
            0xD17F8F8B26F8A7B9ULL, 0xA69AC285BD16D003ULL, 0xBE516A9E8E4D7815ULL, 0x33E63940E3B7CD80ULL, 
            0xE80076EE0A3B98B8ULL, 0x991501B52BBD5E4EULL, 0xF9621666099DBC44ULL, 0xA9EA1468CE899ED2ULL, 
            0xB92AA755BB3617A9ULL, 0xF9E9154F31460492ULL, 0x0CCFDE7A10026D78ULL, 0xB46E65BFD314A8A7ULL
        },
        {
            0x31DF70F7BF295A73ULL, 0x4DB5CA45620705BBULL, 0x5C23E8F580E3EEF3ULL, 0x932674C80A3EC38FULL, 
            0xED5E2B4585A97861ULL, 0x5DA1D35E45835677ULL, 0x65740F5B81FFD769ULL, 0x3C1BABB116E9EC5BULL, 
            0x572DB4F93993B84DULL, 0x223FF1EB51F493CEULL, 0x3E03AA950A8F7FF7ULL, 0x9787C7E637CDD0B2ULL, 
            0x8308DC9D5B11CD9AULL, 0x7ADB14DC1349D69EULL, 0x881205799A23D29DULL, 0x8B94DA2233E7A47EULL, 
            0xA224CA592A7A24D7ULL, 0xFD15F153FEDF10BEULL, 0xF98E28367A9EF62DULL, 0x82D91C1409C5384BULL, 
            0x93175C30434154E9ULL, 0x4AB315677BB4D78FULL, 0xAE1BCE79320A459BULL, 0x6D82F43F22B20DC2ULL, 
            0x924AC5F1FDE8B139ULL, 0x07A7703BCBB13BA9ULL, 0x511010D8E95F0AD6ULL, 0x0E610174A0C55448ULL, 
            0xD4FAD08061381C44ULL, 0x80B7FBEFEB18B580ULL, 0x10B75E07D090CE60ULL, 0xB1FC2D3677557E46ULL
        },
        {
            0xD7620E860BB34EB7ULL, 0x120724B5123CEABBULL, 0x5E0CDF6EFEE6E3C1ULL, 0x3302DAD203541C84ULL, 
            0x18F9A881093B8934ULL, 0xDBBFCEA18C0D6600ULL, 0x74A8F1D14638C055ULL, 0x82538D790874E7B0ULL, 
            0xF3DF45AE00EEE8A4ULL, 0x2C51AB47E4CD4FA2ULL, 0x5B700B68472341F4ULL, 0xAA4975BB19AFF453ULL, 
            0x26F11450E18375FCULL, 0x56811BAD5827CA30ULL, 0xBC1FA3E0B1ECE79FULL, 0xBBEB991E5DD1F385ULL, 
            0xF1A46CECC0332043ULL, 0xEEE4A83782A5D9F8ULL, 0x6B9ABD8BAF0F6984ULL, 0x8420F8B1986D634AULL, 
            0xF9542AC0853EC300ULL, 0x3BBA40A36376A757ULL, 0xE9A0A3543280F5DBULL, 0xBDD99009EDBEEE7CULL, 
            0xD7293084B591C7F9ULL, 0x2CB751985DD26173ULL, 0xCBFD66E53C192D05ULL, 0x8486CAD758DC22F4ULL, 
            0xBAF70347EE599A1DULL, 0x5BB394A17AEFE77FULL, 0xB7A46E42B5CEE8DDULL, 0x6ABC2049DA8E02D6ULL
        },
        {
            0xC84F15866E98B4AAULL, 0xFDDD0313F199EDFBULL, 0xD4C507A49A76FA99ULL, 0xCBC6C86B9BA9CEEFULL, 
            0x1BEB21D7A6B75702ULL, 0x6214CC9C26D4DB86ULL, 0x008822D932400BD0ULL, 0xC16B626A799C6320ULL, 
            0xBB428D66CA9B2236ULL, 0x5E5627E581A96B56ULL, 0x5986BC2364274B39ULL, 0xD331B3CFE1244375ULL, 
            0xC760D43294913873ULL, 0x52DBB2036B11A9D6ULL, 0x70DEDDF8984EE9E2ULL, 0x02B6F33946B29961ULL, 
            0x8E61568EC7905677ULL, 0x7C3A0B182F2E4B08ULL, 0x94D845B4B65A08ACULL, 0xE901EE09D9D3A140ULL, 
            0x066AF3AB19E6742FULL, 0x5787BFEB60C5D32AULL, 0x02260A642632920DULL, 0xFD9D824D77408D67ULL, 
            0xB1C172EB7966D4BAULL, 0x66A08A41835C92D3ULL, 0x7ED54B45D099F9D2ULL, 0x6B1522DC3D0A9578ULL, 
            0x0C04FFD2B64DEA73ULL, 0x5213BBE4AEABA6F4ULL, 0xF49B07F3F408FE91ULL, 0x5AAC7CFC87FD99F7ULL
        },
        {
            0x0963ED8B07889D24ULL, 0x537DAF088BAF4BDFULL, 0x7BBCE808DB194B74ULL, 0x9290C72273D3C618ULL, 
            0x9447EB38E0277549ULL, 0xB14BA5F2FF2A2D4DULL, 0x1E428F93DF2D616DULL, 0xECB5CFFD96824C05ULL, 
            0x56E0EF0D7F7688E6ULL, 0xCB66653DDFDB1C7DULL, 0x1E51AB6B4A7C1BC0ULL, 0x526702A19CFAE354ULL, 
            0x86E08A4CD71A1213ULL, 0x7FD6B779DAE84BEFULL, 0xCFDE125E638D6729ULL, 0xD9792B57D991C60AULL, 
            0x9BC2F8AA42996A91ULL, 0xC96D295A18918D96ULL, 0x4DB235494AE36564ULL, 0xFD8D06B8AAD27D13ULL, 
            0xB823CD80066A5013ULL, 0x72355BA52B774CAEULL, 0x8C258AA49851FF35ULL, 0xA7FBFF757E8CA414ULL, 
            0xE11322A754B05D5DULL, 0xA7B70C86AA8A27ECULL, 0x9194DE83580C9358ULL, 0x3216C61002465270ULL, 
            0xA4CC377548F26826ULL, 0xD1FA0C1392F193B4ULL, 0xCBC4348E7207736FULL, 0xCEF4DD549C9CE05FULL
        },
        {
            0x80910C2CDC93AE86ULL, 0x96CF9A7B0A8B34C7ULL, 0xCED88E79ECA17B77ULL, 0x48DD10F4BD5A4607ULL, 
            0x0B7E14BB1E38390AULL, 0x0098D9B2059AE42DULL, 0x7738D5F0B260D71FULL, 0xD2AFB130E95B2C0DULL, 
            0x87503E41E41C3BCCULL, 0x499D0D32E2FD7CB8ULL, 0xC33B9C67BCD71DD7ULL, 0xE16092747AA6D491ULL, 
            0x9156DEC59512544CULL, 0xA51ADF3DFA3CCC86ULL, 0x2A08A66FAF91A8B0ULL, 0xCAE001801E869ED8ULL, 
            0x14E5B20786A2F226ULL, 0xE714FE331D60DB95ULL, 0x028A3A6993753197ULL, 0x90C6EC725784A868ULL, 
            0xE627E27CB8437EA8ULL, 0x1C9F6A59D527C853ULL, 0x94F066A18606CFFAULL, 0x1A06DC229DD23054ULL, 
            0x35F8CB2169FFDAE5ULL, 0x5EC6BD8B1CB5FDEEULL, 0x31E0A176B46714A4ULL, 0xC497BF8F2B51C799ULL, 
            0x58211D684E38FCA8ULL, 0xA27B493DD198132DULL, 0x63DEA956E4BA0D29ULL, 0x7214A6AEBDC77656ULL
        }
    },
    {
        {
            0x184A0B2EE3519243ULL, 0x054EEF848FF98EE0ULL, 0xB4656D0AAC5212E8ULL, 0xB473E45F8C5C9365ULL, 
            0x169FAFA7421C69D7ULL, 0x06C4BE3FAAD1B9B8ULL, 0x34A40074650C1955ULL, 0x1F8007C1F3AE6D04ULL, 
            0xA2D309CFA5D50743ULL, 0xA8F29BBB272A7926ULL, 0xAD56CBC2CEB90DEDULL, 0x5D1CEDD6720C0488ULL, 
            0x3052A7534068FF25ULL, 0x2F0778F6A2DB43A6ULL, 0xC30300B51EDBF2ACULL, 0x695026A834EA3E69ULL, 
            0xD6FBFED1894901D6ULL, 0x0345810CE0A0CEB1ULL, 0xAF083CE1426F217CULL, 0x26938CFFBBE5F19BULL, 
            0xDE1CD55ADEBEAA1EULL, 0x22A5ED5D6114997CULL, 0x51BA4BCC7549BA5BULL, 0x435EBC5FDF99AB3CULL, 
            0xF10A2D4D74A97C1DULL, 0x5848021344CD2E8CULL, 0x20F5ADBB397676E2ULL, 0x90106614D7946B12ULL, 
            0xDCD19946A22DB871ULL, 0x604A3130D5C60CE6ULL, 0x8A8E159672149420ULL, 0x660E95C5AFC3258AULL
        },
        {
            0x1D8738027A8B383EULL, 0x34513043C8F49C04ULL, 0x9558808BA6B906E8ULL, 0x73741855421E772FULL, 
            0xF2BDF7A3EA5CD7A3ULL, 0x4328F27A6138FAB6ULL, 0x4249B4A332F8C99AULL, 0x358C25FEC14E7559ULL, 
            0xB6A319C0D17247EEULL, 0xE1C148696E0FF6E5ULL, 0xF9D72F3213486EFAULL, 0x0D10BE338EE9CAADULL, 
            0x9C9CA17BC39A9D52ULL, 0x202648CDCDA99294ULL, 0x974DB1BC2D70E1D2ULL, 0x3A965C93B8B04EE4ULL, 
            0x8ABCD381C4AA8ADAULL, 0xCE8C987E49685BCCULL, 0x6F8A2637C2FA8426ULL, 0xC3ED0417598D4E73ULL, 
            0x4A57AA762258FF59ULL, 0x08C103DE45432E3EULL, 0xD09F5D503E822FF1ULL, 0x588C36A20FAEE3FDULL, 
            0x73A2B8DB890AAB55ULL, 0xDDE35CD48D5E14B1ULL, 0xE1FC50381FC75B24ULL, 0x8F7762C9A9181CE1ULL, 
            0xA4F668459F043A6EULL, 0x0E83CD254612B62DULL, 0x08D3CD8E7EC2AC40ULL, 0x24F2AD2A2654110BULL
        },
        {
            0xDFA8ED96D2136550ULL, 0xB15E2459BCE80D74ULL, 0xE8F7AC185A012619ULL, 0x4C2C2033BC2DBB6EULL, 
            0x483CE18B3ACFC4C7ULL, 0x9B3C01938457D541ULL, 0x98A6DD4E390B47F7ULL, 0xC0337996DE46FF62ULL, 
            0x09C37F7012A269C3ULL, 0x42CC45717ABB63B6ULL, 0x90DCE0A6102D68C5ULL, 0x3C8CD9E5D812D414ULL, 
            0x592A750C6AB02C72ULL, 0xE582C65C688C531DULL, 0x197ECEC4DBCF5C33ULL, 0xF6B6164E751B1527ULL, 
            0x3D21796B5F08308EULL, 0x398974F64C345E89ULL, 0x2FEFC19A0E1637A0ULL, 0xF4C87FB34554F76BULL, 
            0xC5B779CD06ADD0E7ULL, 0x44B83F6031CD0089ULL, 0xBB84D37462A77245ULL, 0x153941511B2FAC8DULL, 
            0x6543C0A720BB3322ULL, 0xF0DFF6516C4E594BULL, 0xA82C535771369E26ULL, 0x3672F67CD5E8472BULL, 
            0x6F568C98020817E4ULL, 0x793E525978C84D4AULL, 0x939EFC32F73F8D00ULL, 0x6238DDC3A5C8CFF6ULL
        },
        {
            0xC664786A45D88484ULL, 0x64C3ACE8E0B119EBULL, 0x5893099C283E6377ULL, 0x83427288C3AF42BCULL, 
            0x0AE9E9BF64D272FDULL, 0xDD67A0248A88B2B8ULL, 0x49841A438BAA6FA6ULL, 0x301357FEBC832924ULL, 
            0x402ABC2281573472ULL, 0x717E47BBD1F1B5B6ULL, 0x4A64AE69BAAC9CDCULL, 0xC958EB8BDD0AA036ULL, 
            0xBFEBCECF8FAEBDBCULL, 0x7E55A875712A2FE7ULL, 0x5B24A80D5F7615FAULL, 0xEBD6CD75BE260205ULL, 
            0x70A660FE2EE77CBDULL, 0xE3FDD1D7810184B7ULL, 0x83BA60E9711B0409ULL, 0x2863DD4D8160B901ULL, 
            0x05B80DBDD723B6DAULL, 0xA9323014A9014220ULL, 0x042BF4EA8E2465A1ULL, 0x0CA79CE695B6BC71ULL, 
            0x64C0F550527DA573ULL, 0xDEA226D9390B0541ULL, 0xAE4FE5C54E0E6C35ULL, 0x84A5B0219BA71C85ULL, 
            0xF861F308C5E26057ULL, 0x7160F561399E8CE3ULL, 0x1132B0A49C034277ULL, 0x3E7889F55E209B46ULL
        },
        {
            0x7F1750B4A682D977ULL, 0x35E1DED23AEBD8F3ULL, 0x3CAB8BC724F002DBULL, 0xC3E6BD59624EB6F0ULL, 
            0xC899F458A6A3903DULL, 0xBF3360D43DE705F0ULL, 0x5F9CCF02F9940E02ULL, 0x7C1870C4CE03822FULL, 
            0x6DA99F80394ED48FULL, 0x9BCAFC51BCB9D7F3ULL, 0xE2DB9800C4275740ULL, 0x8B32C1EB72C14B14ULL, 
            0x17F49A4265DFA6EAULL, 0xAAB80F20B70D5621ULL, 0xE48E7506C67284BCULL, 0x5F6F307C4A476403ULL, 
            0x304AA74479B71666ULL, 0x72B85B052CC97101ULL, 0x38E59B1873C45992ULL, 0x1B7B45329A4D97F2ULL, 
            0xBBB0A0AE18A97EBFULL, 0x1CFBBE6B45C80955ULL, 0x168DF726CA7FB8F4ULL, 0x606B7F3831A3A286ULL, 
            0x13C0598AEDCFF9B6ULL, 0xB7E716C752B40E98ULL, 0x22C861C7BAE23252ULL, 0x63F7A50862F83438ULL, 
            0xC638E506972B6B5BULL, 0xFE2845E2CE250DDBULL, 0xCB76EC7A515E9E1AULL, 0x1EDAE35C8E2B08E3ULL
        },
        {
            0x19F405FC8D64813CULL, 0xFB865996FF213CFCULL, 0x85AE83F6373E6144ULL, 0xF6DE683F0BB803F3ULL, 
            0xC37EAAE0D71A7A59ULL, 0xDC26DCB27B578281ULL, 0x668385E72F55DACEULL, 0x3CAAF8B2A81228CEULL, 
            0x8C39588D2282BDC8ULL, 0xD949D9ACA561519EULL, 0x4E2D0DD9A8D62FCDULL, 0xCEAC237C5F6971FCULL, 
            0x2E38463C35ACA2E3ULL, 0xD6BADA27F2D09097ULL, 0x828986B75E1799D9ULL, 0x37E0BFE076A66D90ULL, 
            0x50AAC0D13E15E5A1ULL, 0xEAD860C4EDED3203ULL, 0xD8BDF0D05F068EA6ULL, 0x9D81E98F7D8D2F64ULL, 
            0xC725D54E77F0651CULL, 0x58FC5F28606D33B6ULL, 0xF64F1052D5FB2AF0ULL, 0xA8FAD8DEA7EAEBFEULL, 
            0xF6D140A3F74E99CAULL, 0x2050336080AB0EF6ULL, 0x37F51914BC3DC167ULL, 0x0F02DFE2B12C5324ULL, 
            0xBBA9685857D8AE3BULL, 0x88035D212397711CULL, 0xE5A53260FE9C3EEBULL, 0x666CBD9ADD131959ULL
        }
    },
    {
        {
            0x717FBFA3DCFEAC00ULL, 0xBE8EC7BEE614D07CULL, 0x6799E62B926EFABCULL, 0x3B85127B7731BB2BULL, 
            0x6A7F47643882DFDCULL, 0x71C968B7B64AC668ULL, 0x24FA6872D5969EDFULL, 0xAED76578B7970014ULL, 
            0x8FB6FFA936B121C5ULL, 0x4123713EABE4048EULL, 0x59036BAC5B87F354ULL, 0xCFC779FC103D689AULL, 
            0x74D2C0067DD437EBULL, 0xE769546DC2F50E68ULL, 0xCC4404D7C29EBB84ULL, 0x904AB37BD7A53338ULL, 
            0x53EA554D54DD3FD2ULL, 0x310D2CF1483AF3AEULL, 0xF34FB316B7A3CD27ULL, 0x77A55472FC7D79EBULL, 
            0xA4C2FD7510A7CD94ULL, 0x34380C957277E0A3ULL, 0x57DDB087830F5B5AULL, 0xA6BF050A8DEAC73DULL, 
            0x6BE2A46E6885CDFCULL, 0x24D79A240A0B0127ULL, 0xE6B0151E5A2E3A0BULL, 0x7AFD7DA1868F6F34ULL, 
            0x45459D54F9034293ULL, 0x4EFE3B2CEEEF6768ULL, 0x45472DE0F95EEC1AULL, 0x533C13CE2B540ADCULL
        },
        {
            0x7FF086E79A4434B9ULL, 0x64ADA62858F32090ULL, 0x784634310B165A43ULL, 0x5903F70FBCACBB13ULL, 
            0x182DAF0296FBA8E5ULL, 0x9A80FEDBC5EB339BULL, 0x0604578C38AADA08ULL, 0x0BEF66FF40AD89D8ULL, 
            0x3791AE81DA6E4439ULL, 0xFCBD33DAEA3D2204ULL, 0x02C392C6749CBC4CULL, 0xEA5FC3370980B4F8ULL, 
            0x3AB26AE13911D843ULL, 0xAF10909689B3B27EULL, 0xEEA8290E1FA1B706ULL, 0x145FE301C1900482ULL, 
            0x9DE36CDF1E784BA7ULL, 0x4C4611688C17A3F4ULL, 0xCF622D1E01C9139CULL, 0x90256342B692754EULL, 
            0xD917814EAC9818D3ULL, 0x7B6C5108E33B98E2ULL, 0xFD2EAFB7F73F8B8FULL, 0xF5BBA362677F2E15ULL, 
            0x852823665FE87CC8ULL, 0xEE48808C7DCA38F5ULL, 0xDCAEA3873629B3F7ULL, 0x7F6326B3786578FAULL, 
            0x6CE2B36055DDDEADULL, 0x4BF26ECEAE576E1EULL, 0x5F4459FBF1BDE24DULL, 0x86D45439510AF84FULL
        },
        {
            0xA99A2CB12E50DECAULL, 0x6662A99843F7E140ULL, 0x6E3FA7872F3899B1ULL, 0x8B8AB6B3F9B11D70ULL, 
            0xCD34E4D7E310A0D0ULL, 0x597BF5A2AD487105ULL, 0x7BA926B15D600878ULL, 0x19C37C2B963B4E31ULL, 
            0x7119D85896E28175ULL, 0x8691F4D499E2795FULL, 0x02F28DB344A58FBEULL, 0x6CF83AE420AFADCCULL, 
            0xFE4A8804143F7FA2ULL, 0xCF7F3C420FA40D1BULL, 0x10C9D87EB78E437DULL, 0x2B8FAB391BBECFA3ULL, 
            0x2160A82438896C29ULL, 0x406EE54DAB5E7224ULL, 0xBB50F111215E9A17ULL, 0x56FECA3F459EC55EULL, 
            0x7199970631D430AAULL, 0xEC2A7DFB35DF903BULL, 0x5DA8442538C57DFFULL, 0x6ECB49BB2FFB4731ULL, 
            0x02F88628ECB5583DULL, 0x74B680CB1ADC5B6EULL, 0x2B08F39D6C17E277ULL, 0xE43B8112311C048EULL, 
            0xEE5CE8B52957DAB9ULL, 0x79146C2F259BE42BULL, 0x04994D569620991EULL, 0x3AD168B18B0F3531ULL
        },
        {
            0xD8DE44FDFEB604A0ULL, 0x96E9D79839712651ULL, 0xFB9FC35C92F70076ULL, 0xBA92900BF544876DULL, 
            0x3089C90881EA8E93ULL, 0xF2CA2B745AC2936FULL, 0x11D15E75DE6D8548ULL, 0xC597019850B0BAE4ULL, 
            0x48A756DCAF779690ULL, 0x86F25AC3B3C2FB08ULL, 0xCE84EC6A1EFEB843ULL, 0x24F330060BF60BD6ULL, 
            0xFC69A2C9038D9903ULL, 0x9018BABC5D1EC9F6ULL, 0xC611F94C6748842FULL, 0x16A3C2ED829A8BB4ULL, 
            0x878B8BC11675565BULL, 0x8B2550D0A230D8C5ULL, 0xE9C5218F1FE763C7ULL, 0x584876E47EDE8568ULL, 
            0xD13A3537E4BECD5BULL, 0x6FC89750F75B584EULL, 0x21AD3A6E952418B3ULL, 0x8D54EC186ED7A42EULL, 
            0x2C9C3B85BECF3FAFULL, 0x431D2A6628E0B885ULL, 0x5C93EAF356E09EF9ULL, 0xF9F965AE609AB76EULL, 
            0x93CC53CD243E3AE2ULL, 0xF1B9E0F09BF1DF85ULL, 0x3B93396374C8DA1BULL, 0xCDB48E918192FC70ULL
        },
        {
            0x5A0557B9BF258799ULL, 0xC1A0CA3430D21179ULL, 0xCEF7552943962A3CULL, 0xF7DBECB14B0354CCULL, 
            0xDC0ED90AD13D100AULL, 0xC86867195E0A174BULL, 0x31AC491774FE060EULL, 0xB0B70021B262B4B4ULL, 
            0x24CEDCB64764A9D9ULL, 0x149ACC1D0E1C0E31ULL, 0xE820365F5408D872ULL, 0xDF3A1B7BD2419AFAULL, 
            0xBA0B4D228E66190FULL, 0xFAABECBC4764A7A4ULL, 0x7BD31A5262DEDAD8ULL, 0x9509885DB1961020ULL, 
            0xF6DB572191F0D2E2ULL, 0xA115BD4FE2F1AD02ULL, 0xC285E0D1FDDA05E4ULL, 0x4267277A4522B5FFULL, 
            0xABFE50753ACCE17FULL, 0xD6D70773FCF2D28FULL, 0x5A9F8070318E27A6ULL, 0xF6C63AB737E8AFB9ULL, 
            0x556AD495E1B9FC30ULL, 0x49C98E83BFB9C309ULL, 0x2DFE88A96B55DA0DULL, 0xE7F61C637F0A0E79ULL, 
            0x3EBE4DCBFC5FEECDULL, 0x9BE8D50B8AAE8CDCULL, 0x7D977500C2512081ULL, 0x1C84C440C80D1AC9ULL
        },
        {
            0x05C42236BBDE8E04ULL, 0xB13C1DA1D3BE9D2FULL, 0xE74B4DF73FF198BCULL, 0x9137361E8F6883C2ULL, 
            0x31BCA9423AB5DE3AULL, 0x69B8ABD50D222B08ULL, 0x15C66AA918431C76ULL, 0x916C2E8E0E6FF1F9ULL, 
            0x2F3AAA0B749048E0ULL, 0x03D336021D62A46CULL, 0x0895A97736B8D8DFULL, 0x88448FA916F477C0ULL, 
            0x2A6FF8EC26402E50ULL, 0x92793125FBF743D1ULL, 0x67FD41C702C3D787ULL, 0x2CEB92C49502E3BBULL, 
            0xD0DA87441916BAB8ULL, 0xC98FDE8B39A3D130ULL, 0xEBB99AD921B56478ULL, 0xD64FAA4ACA6B9A01ULL, 
            0xFA20A324F73E41E4ULL, 0xB7CA54F513C7A632ULL, 0xF5AD6171B868507BULL, 0x6DCF5BC6F8B7D109ULL, 
            0x014F4846EB8D5344ULL, 0x42003D449A93274DULL, 0x69C2F8B3577E87D1ULL, 0xAEB3F1C5C1708865ULL, 
            0x184ADE31ACFF33C9ULL, 0x6F0E0A36FD5D1A25ULL, 0xF8F0678D33BC76B8ULL, 0xB90DB2A5AF3ED5DAULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseEConstants = {
    0xE523EEC9C42F12BCULL,
    0xDC6313DD0C0D2414ULL,
    0xD22C0620A88A6CF6ULL,
    0xE523EEC9C42F12BCULL,
    0xDC6313DD0C0D2414ULL,
    0xD22C0620A88A6CF6ULL,
    0xDFD168899A8D6CE4ULL,
    0x48D7641217D32A49ULL,
    0x2F,
    0x43,
    0xDF,
    0xBF,
    0x50,
    0x62,
    0x7F,
    0xFD
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseFSalts = {
    {
        {
            0xBE0CC10C312CD436ULL, 0x0A14A37D5AE5C96BULL, 0xE6058DE069A1C595ULL, 0x40FDD850C0A8560BULL, 
            0x6E62C91F6B973087ULL, 0x297DDE974F287B5AULL, 0x140B308BE523FE90ULL, 0xF8D6F91A5CCA8CBEULL, 
            0x50A3A379C664C292ULL, 0x46E7E8E87721FD89ULL, 0x396C4E599EB54AA5ULL, 0x7099DB91090B833AULL, 
            0xCBF268800555D419ULL, 0x1E6FCC87CDCCB8C0ULL, 0xFA0F2EB495CFB405ULL, 0xB864F819C47D406FULL, 
            0x09A5C027BAB2C339ULL, 0x040D9D2F52B297C4ULL, 0x42DB79394787091CULL, 0x95202A00A17B2D8CULL, 
            0x862BA0C9CCB1C12DULL, 0x9426C933D98EAD10ULL, 0x7910DAE601B9BBF0ULL, 0x6D5145ADDD0C5614ULL, 
            0x4A83885F66CD335CULL, 0x606F1D68245183DCULL, 0x4F6CA75F14DF86D1ULL, 0x88D39FC54A988F4DULL, 
            0x17543218849DA8A6ULL, 0x6C00C1A20F8E05FAULL, 0x634F970AA873C5AEULL, 0xF14BA4FE4A9532ACULL
        },
        {
            0xEFB1AFDABE865234ULL, 0x1E2032572E684C27ULL, 0xB76E72313670D4A6ULL, 0xA3454BDAB67981EAULL, 
            0x12C80A83DF069053ULL, 0xB015F91E56AB583DULL, 0xB86745C90F21DB58ULL, 0x982B33B03817E78BULL, 
            0xA66B947A7CF87905ULL, 0x917739FB2B6C66D1ULL, 0xED8E055F9D67B037ULL, 0x7FAE1AC383CAABFFULL, 
            0x797997643F0799A8ULL, 0x5F74C52C24E11653ULL, 0x793615D71F3BC8E3ULL, 0x105989B34EFAF71BULL, 
            0x3E09EFA37C2C89BFULL, 0xAF9C4ABE6F174B95ULL, 0x0D817BFDD9907C12ULL, 0xCCFF6C01E169A7E0ULL, 
            0xF72D11B286B9B1E5ULL, 0xAE2B6F59F0DC756BULL, 0x5EC359D975DF2C44ULL, 0x993A362F43F22D32ULL, 
            0x7E909F7C4EF814DFULL, 0xF2170B02C9A519B7ULL, 0xD06A3DB2FD9467AFULL, 0x3FB9A19D5FFF1DCDULL, 
            0x07D0E89C270B8800ULL, 0xFECC2D64EBD91B6CULL, 0x6E9D225AD3A16A8EULL, 0xC556ACC3636F4A6DULL
        },
        {
            0x9A28BF929C03A025ULL, 0x80144F8C5F9A6AF3ULL, 0xC2946AA48E27E72FULL, 0xD8D1A58F1463343BULL, 
            0x990F9BA54979AB15ULL, 0xC82CB34D8059680DULL, 0x47C86033C6E308CFULL, 0xE18AA0BA5834A91DULL, 
            0xF76F920DCD3357CBULL, 0x667604BA24EBDF16ULL, 0xB2CF01ED97690881ULL, 0x12C1D076A39873E5ULL, 
            0x2D0CE27E5EFFFD77ULL, 0x85F51B4C7993F9DAULL, 0xA8DE71C1394E949FULL, 0x5EF3F0260E8B64B5ULL, 
            0xD245971CB4E7E13AULL, 0xB1E4675E5EE33E3DULL, 0xB03FC83A6719382CULL, 0x2507D714981C4326ULL, 
            0xE1DC3FF0FBF2F089ULL, 0xE3E46E39C2F6EA35ULL, 0xB7856E2EACEFD361ULL, 0x85C4AACAEDCB8E81ULL, 
            0xDE388A7A887F8F26ULL, 0xB9410E73EA2F1896ULL, 0x5C84BD2635920A4FULL, 0x64DA45D93E5532A1ULL, 
            0xFD7528A8EA9F7358ULL, 0xD23003C98F9D5EECULL, 0x49C3FA210DE38091ULL, 0x3EE5A63BE3656499ULL
        },
        {
            0xBAFEB983525BA599ULL, 0x912217B3675DBC4CULL, 0x90C35A4C4A277545ULL, 0x50BE5D314F70EFB5ULL, 
            0x2CE95EDB9AD39233ULL, 0x05F3D862C4C31F03ULL, 0x44C6A9B7C8310C1AULL, 0x39883A861D5B2500ULL, 
            0x2D948F184B710A95ULL, 0x40A61E3E1EDE7650ULL, 0xBCC3AC0D906AEDD1ULL, 0x469CBE1700CA208CULL, 
            0x66EF6EBD1F2C003CULL, 0x350989CC2166B500ULL, 0x5CA0D4C75829DB16ULL, 0x6C338DB883DDE4A3ULL, 
            0x58DBB196C953CC23ULL, 0xEEB422BBBB650D14ULL, 0x10BB3DBD3895DEB3ULL, 0xE1E1692DC3E18D6DULL, 
            0x8B9D065359D90C64ULL, 0xCABC59924196F27CULL, 0x100F851ABCBC5099ULL, 0xF4632C777B58F208ULL, 
            0x7D4CAD6E7F896C5BULL, 0x4F46C098847265EBULL, 0xA8090EBA2998A93DULL, 0xB53743FFFADE5FD6ULL, 
            0x21961C6B060511ECULL, 0xE8A2A581141A1A77ULL, 0xA1E6AD006A8A550EULL, 0x55DC8A8E3EF65EBAULL
        },
        {
            0x1597A7A149892DDBULL, 0x374813D574B2BD0DULL, 0x88994106747207CCULL, 0xCADAC0B77B6EA103ULL, 
            0x4E99035DBF0010BFULL, 0xF91261EDCBE4EF85ULL, 0x808429DC5D3E6F7EULL, 0x62DE915319DE2254ULL, 
            0x3D8444920F92AB4DULL, 0xE3193059EB620EFEULL, 0xDA8BDB51CB670A44ULL, 0xD874CCC50FB0AEFEULL, 
            0x1B43B467D0E70CCEULL, 0x096FD0C19FBAFE80ULL, 0xFEAF72E9D5E3E208ULL, 0x557430023730E97AULL, 
            0xDAD3C4B245B3C71AULL, 0x20DD084038323FF5ULL, 0xCBCDECE69D666551ULL, 0x6C475D36925C05A5ULL, 
            0x952659158E789F4AULL, 0x82560FB67377DF29ULL, 0x80F58C90885008E3ULL, 0x93AC862E5609A2F4ULL, 
            0xB400BF58A739305EULL, 0xFF92B6B0FDDF1FC5ULL, 0x4AEF8F6F82B53063ULL, 0xAD308D01B6A564C5ULL, 
            0x515F1CA0D2D700FFULL, 0x496D8020429633B1ULL, 0xD14C66E86AB3189EULL, 0xFA90C1B5C2CF7530ULL
        },
        {
            0x8D85B0EA5A706E36ULL, 0xC28FA6A7D7D3C3BBULL, 0x4000ECDDF7A2A0C5ULL, 0xC56B5AE5EDC567D8ULL, 
            0x15241F49EBB813ECULL, 0x7F21A351EA0EB415ULL, 0x2A4F476E64786D85ULL, 0xA0195C88BD55825AULL, 
            0x6A6E10C57A46FE95ULL, 0x9CDA6054B272E32AULL, 0xA336A10E43DD5FEFULL, 0x36FB0D1E71A759D0ULL, 
            0x1FD73BDA41E9817AULL, 0x63B08631C99C44B0ULL, 0xC653BAB08B80DED8ULL, 0x86D52A3C61CCDF55ULL, 
            0x5FF101C4E8C8E100ULL, 0x3FBB78D8889EE236ULL, 0x528F7E55AC1E538CULL, 0x7E4D8C4C232FAEF3ULL, 
            0xB702123DDD578FB5ULL, 0x16827E6B5A6572AAULL, 0x9EC1E9DBAA2AA037ULL, 0x5FD5586518608D4EULL, 
            0x168AB073FE0FAE64ULL, 0x70A29F128A6459B8ULL, 0x91A7E872F052EEA0ULL, 0x811AB8C58F611042ULL, 
            0x5F911872C164D14DULL, 0x2E5D07488262CE6FULL, 0x6FE28FEBC914607BULL, 0x2995F903F800899FULL
        }
    },
    {
        {
            0xB2A859B9B9DFCB38ULL, 0x9A6AC450160B0838ULL, 0x8BEE24649E009EE8ULL, 0xB4048F3C7E48A03EULL, 
            0xCA735F9578D7DFE9ULL, 0x61903F746E2D0CADULL, 0x565EDA2209D52023ULL, 0xD89F4353782CC20CULL, 
            0x9A9AFE224DC67AF7ULL, 0x5BB1F506EFF66FEFULL, 0xE16374B1CEE65D4CULL, 0x396EE1986819F73DULL, 
            0xCB1D6E4410B1515EULL, 0x865CFA39B0362209ULL, 0xAF538D8DBB415DADULL, 0x80D3B5AB861CE6B0ULL, 
            0x842D994EAA0AC4FEULL, 0x0DE623FF50889490ULL, 0x6F076931E8A50100ULL, 0xF1E51EA6D5C9AC6CULL, 
            0xA9331FE985ADDE9BULL, 0x8CF547AD32A19112ULL, 0x4346B5D8D3792ABBULL, 0xAB5333F4BD86DF7BULL, 
            0xDA379FBE65390A3FULL, 0x0C10DA7B0BE5C824ULL, 0xA0F3E5D9C9B27C82ULL, 0xADCF607E07502A94ULL, 
            0x2BFCD26F3A295E92ULL, 0x5577AEE89F44535BULL, 0x990B8EE1637E8595ULL, 0x69AD67E97A3C51CDULL
        },
        {
            0x0DAA4B6099ACAF6DULL, 0xED4F819BE5913B54ULL, 0xFAF47D931F4CD2C7ULL, 0x2F68C90AC949ECC2ULL, 
            0x052B8497DA84FB3AULL, 0x3453C3C157B51D1AULL, 0x103198E2A1A684EBULL, 0xE6D4E6D638071941ULL, 
            0xAFC7BD3A9FE2983CULL, 0x4953ABB5757D1226ULL, 0x40B697B4D186A865ULL, 0x1D2CBF645AD6E19FULL, 
            0x4434AFF583D89A7AULL, 0xC6E7B1383CCF108EULL, 0xF6E147E2460D66F9ULL, 0x89334BAF73AD55B6ULL, 
            0x7DD07D28D46D5268ULL, 0xA23D4222E0C599C4ULL, 0xD25E39368D4D4C1FULL, 0x9140C6AE8A8B81AFULL, 
            0x61C35F9E1234623DULL, 0xBEF048D9AF1BC7E7ULL, 0x75C3FCEA806C5B22ULL, 0x7E6916CCF2213767ULL, 
            0x03CF93223547897EULL, 0x18C50F3022FB310FULL, 0x6DE21B63A896AD89ULL, 0x2352E822689228A6ULL, 
            0x586A412B0C0828FFULL, 0x018AFD406FE4D8DAULL, 0x4F63C1DA5EC4C579ULL, 0xFC04B82A29D7839BULL
        },
        {
            0x76958F858FAB446CULL, 0x002F7629BE860174ULL, 0xEAF7D9DA065F7E4DULL, 0x7FFAD279AB7B2AECULL, 
            0xEE13C068F17BE638ULL, 0xAD47A128CB6A728BULL, 0x7461AB5E661A6BBEULL, 0x8BE396E34B2C4E9CULL, 
            0x69A456BDE93316EDULL, 0xA9B25E738D355AD8ULL, 0xB5199D9DBDCAAEEDULL, 0xEC57D86C097973A3ULL, 
            0x30636A2A5A19E941ULL, 0x8F875CF42F07FAB1ULL, 0x3A6B52AF482F3F9AULL, 0x656DD0666A005BB9ULL, 
            0xDE9341EC918AA467ULL, 0xB60376F41C78092EULL, 0xF5B0D5BC97D69A76ULL, 0x3E7F0172715A43C0ULL, 
            0xAB04888F1567A6B3ULL, 0x3C6737C5D7FC3117ULL, 0xC8A10210E501CE3BULL, 0x8125A067C1700278ULL, 
            0x942EFCB277C12CBBULL, 0x2CC25EA53EF1E59FULL, 0x8AEA674BC3CF8BA6ULL, 0xDB112D713CEF8AD5ULL, 
            0x6E05E702AA72BCB9ULL, 0x38CD3221574049BDULL, 0x76C1B28EE42BE13BULL, 0xCD88C5A850C29865ULL
        },
        {
            0x902B50B7DEEE71DDULL, 0x940750F77C8DA056ULL, 0xFFEC9F715FF6C582ULL, 0x1EF49B90F5E6E4ADULL, 
            0xEDF244D98A03C05AULL, 0x698955B249F2609EULL, 0x2F7A1D3380F151D1ULL, 0x4A3EDD9F5EED0EA5ULL, 
            0x26152653ABA57A0FULL, 0xD451BC0B5BEC9227ULL, 0x146B591F95EBA5E4ULL, 0xB294385107D78B75ULL, 
            0x3A36587B97D287E7ULL, 0x148278DC4A290566ULL, 0x9314847CB3678AB9ULL, 0xC9AD467CF9B3CAFFULL, 
            0x63B2A2E3A7D4FE80ULL, 0xBC5A5C921710F059ULL, 0xD5F696F3CA009283ULL, 0xE9DBF40CAE3C0127ULL, 
            0x4455CCFE65E16C1CULL, 0xD5DF84085F657B22ULL, 0x781A0F9554A28922ULL, 0xBE374AAFD2A34B4AULL, 
            0x2CA66B5AEC09753EULL, 0xA3A8659F91F65BA4ULL, 0x4E65219CFBC5013EULL, 0xA3FB84452DBD6DDBULL, 
            0x8282A1EA70F5C773ULL, 0x52F7708DAE3186E9ULL, 0x4EAF9537166A9839ULL, 0x1FB15F15C8CE6262ULL
        },
        {
            0xC7B14E1963C907A1ULL, 0xFC1EA97DD4B4821CULL, 0xF0817E40B5C2428FULL, 0xB6E66FCADF32C0F2ULL, 
            0xFF1032AAF319BA94ULL, 0x783B60C27F3E7BD0ULL, 0xE03A262D53D4906FULL, 0xC417FDD376F21565ULL, 
            0x051B13E6EA7CC653ULL, 0xAEF28571D0BE0642ULL, 0x842BDE8362B672DAULL, 0x3FFB3E87AD55F954ULL, 
            0x072E094644FCCFB3ULL, 0xDAFBCD4490A2C68CULL, 0x3CD99D6EF2505837ULL, 0xE7142BB5D456EEE1ULL, 
            0x95CA164FC421E2A1ULL, 0x880D9DDEFED18AFFULL, 0x787D172A6D879526ULL, 0x1C3ED0A3B4D6EFCCULL, 
            0xF8D7A412EE45B661ULL, 0x19337EF3B2AFFC67ULL, 0xC8286194705072BDULL, 0xB7D62F8F619D0205ULL, 
            0xAE1C6B70DCCFAC6AULL, 0xE066390A0EDA8736ULL, 0xB68819F1780DC410ULL, 0xB41AF3806EBBA915ULL, 
            0x9539AB3312D877C4ULL, 0x6624AAA1A488A6F7ULL, 0x7CD2C804EF79AF29ULL, 0x1B571F9E4A799DAAULL
        },
        {
            0x36C8B46D73E6E2EDULL, 0xF3DC6BB72B285A2AULL, 0x6D52E8B560CCEC8AULL, 0x5A2D22E3FD76AD43ULL, 
            0xAE9D86335263CBADULL, 0x6138D16C6CA699E2ULL, 0xD6309DEA16450F1CULL, 0x8741AD8E72EF062EULL, 
            0x685DCAE6CFAD284AULL, 0xEDC8D29C4ED51455ULL, 0x4C8B7C8CED7B6067ULL, 0x791067147BD21ED3ULL, 
            0x17E22DB57A6B57F0ULL, 0x1C0D3D6329C4E304ULL, 0x5473093B586AC8C1ULL, 0xE9E8C90DDF0996D1ULL, 
            0xD5476C2BB3BA52F7ULL, 0x626AA3AF2A0E002EULL, 0x03EEF5EEE603A0F6ULL, 0xEFDD4CDAAD0DB463ULL, 
            0x061795868AE98DF9ULL, 0x35AE7A8BEAF42D2FULL, 0x5F11E32D19DDCB73ULL, 0xA216555604E6DC4FULL, 
            0x692BABE450372E18ULL, 0xACE12FFF2DD4001AULL, 0x20B6F5C3DEB45BB2ULL, 0x7E3AF87B3736F5A4ULL, 
            0x4D052CC60F219700ULL, 0xF51F59CF8F6D0EC9ULL, 0x2995FD6D01F898A0ULL, 0x2E8596C702B9CEC9ULL
        }
    },
    {
        {
            0x18FC5953DD8C5419ULL, 0x03EB732E9ED160B7ULL, 0xEB0A4E1458D17FCFULL, 0xA85C0AE90D210F07ULL, 
            0x1E4B73F8CE1871FBULL, 0xE904CBD0FDE79531ULL, 0x1C6BCE43E2F0996EULL, 0xC090B6081F1CC7AAULL, 
            0xC5D9B1D1A6ED9423ULL, 0xB4628FFA73FAE2F7ULL, 0x68E670038E7E4DF3ULL, 0x3858B63F33959876ULL, 
            0x924E32BEC39AA6A4ULL, 0x8E19AC761CC1FCD9ULL, 0xAA7B80CC81CE77DDULL, 0xC1BDBF798586289EULL, 
            0xBACB0F2024B80566ULL, 0x48F65F152BD81D97ULL, 0xC1CED9E63B9F12E5ULL, 0x23FB84E26574647DULL, 
            0xF94EF3E6C19F7FD4ULL, 0x8E26FDF7824DB395ULL, 0x366D247B809AE8B3ULL, 0xB748A5E7E6D0F1F9ULL, 
            0x36BBD872A194C5B8ULL, 0x9ECE85C8817AD6F2ULL, 0x8A8AAD4BEDAA0F87ULL, 0x44FFBC3294E4453CULL, 
            0xA5C660B65AEEF9A6ULL, 0x9FCCBCBA59F62845ULL, 0xFD93BE6565576C18ULL, 0x405285D6C7C7984FULL
        },
        {
            0x1775760FAEF9966EULL, 0xD7B82BF8AE5D7AD1ULL, 0x4D0FBF027132D09CULL, 0x12DD119D718B850EULL, 
            0x340A980DBCBEAF0AULL, 0x7DA66432723D7DECULL, 0xC8B18AF1CC09ACA5ULL, 0xCB30B080847FB2C2ULL, 
            0x1D00D79B62D61E1EULL, 0x1BBC13B29BB8DBEEULL, 0x9C768429042BB143ULL, 0x7F2D1D1F1CD18597ULL, 
            0x81DD7B61F7B9387BULL, 0x072C1A0F832AAA7CULL, 0x0C425636AA50F3E7ULL, 0x2DFCC758F971E738ULL, 
            0xA9EC5A962B48E524ULL, 0x7FD9CB2DFD21AC26ULL, 0x3FD27B12C20155AFULL, 0xAFDB6C8E445E5DDAULL, 
            0x0D3F8B167451C589ULL, 0xC2E7B111730A2884ULL, 0x9CC4FE8F4EA4BB16ULL, 0x79C6940CE4F348A6ULL, 
            0x33D9CF0C801DB9FAULL, 0x2C8AF745306AEA10ULL, 0x0CBA8C4070DBE2CCULL, 0xECC9121D57A9F8D9ULL, 
            0xD75CDA0D206964D3ULL, 0x47739C5E79F9DEEEULL, 0x4E3B3582CAB30D4CULL, 0x6E94BB667B26094AULL
        },
        {
            0xE75910B393CC865CULL, 0xFE73649B836FCF0CULL, 0x3DC2770C8E1AD7BEULL, 0x752E6D539CF7E792ULL, 
            0x1EE8C8418F1FA437ULL, 0x376795995B80917DULL, 0x43F7AA9B08CA2466ULL, 0xB595B8ADB6FAC1D7ULL, 
            0xAD50DF349C479F4EULL, 0x988AB0CE3BA1E228ULL, 0x662D81387C23381AULL, 0x1FEA0B4554DB2CF8ULL, 
            0xD7D03D25A72A7933ULL, 0x70B7B32C4504BD4DULL, 0xEB35FF61DD15B086ULL, 0x25D570ECC3F08551ULL, 
            0xE8ACDF543EFF2F35ULL, 0xB72A12B9F1823933ULL, 0x59114614013477EBULL, 0x63E0A5C5C91AA117ULL, 
            0x7C50A448CE5738FEULL, 0x19A34ADEDF0E33C8ULL, 0x6E51EB93D8288E44ULL, 0x51B1B0FE97BA03D7ULL, 
            0x3CD7E05E2B413D48ULL, 0xDA7689103B02BC17ULL, 0x85736DDD02E6CA5CULL, 0x0CBFEDE9F2F75D88ULL, 
            0xB35094483391A83CULL, 0x27F5271BBDDEF064ULL, 0xD961B6F98F68CABEULL, 0xB583BEB94AE0C177ULL
        },
        {
            0x11B80CC277F10795ULL, 0xA69722C4475B4120ULL, 0x68B93085031C9B8DULL, 0x40206FDA26A16FE5ULL, 
            0x5A7D05DA93D5CA11ULL, 0xC9AB227298E59727ULL, 0xE14F13840E5433C3ULL, 0xA282D6AA32BFF983ULL, 
            0x29FE13C3815B83A9ULL, 0x90AEF7525A0F9BC4ULL, 0xD7CEB4C936FB8CFDULL, 0x51DA0FED2F657630ULL, 
            0xF4AAC791C2A5E8E6ULL, 0x94E4FAA7C98D8B32ULL, 0x7329B726F670B044ULL, 0x4EAE07CCAA5DF1FFULL, 
            0xB6F832BF04A000FEULL, 0xA31246513E854AB7ULL, 0xFD1BABB6F64F2CB0ULL, 0x6CC60A798CC4CE44ULL, 
            0xD556EA3BFA8DEC9AULL, 0x31DBBA9DF158AEB1ULL, 0x979D4547A4A222E5ULL, 0x56FA815A3577B04FULL, 
            0xF527FD709F1E010BULL, 0x7FC7F0BF569FC3C1ULL, 0xFB49293BF154D4E1ULL, 0xF33FFD00B193E8EAULL, 
            0xA120B317B5880E91ULL, 0xDBA3499E456A13F7ULL, 0xEC67DD917BB72539ULL, 0x86377BB04613A158ULL
        },
        {
            0x93C3DF0E28C7AD5AULL, 0x20EBD1124AABB13CULL, 0x0D283A00D5F62043ULL, 0xE180057E60B7669AULL, 
            0x7747D93704E20403ULL, 0x6BAE15C124CA4292ULL, 0x99D0EDA5E6E848F8ULL, 0x238459B841386081ULL, 
            0x50D2453908DF2A27ULL, 0xF88D1D2E9BDFD200ULL, 0x071513A94321CB43ULL, 0xC0250BFF83649F72ULL, 
            0xDC67AAD9947A215DULL, 0xC37F776BA3878A82ULL, 0x5D260243351B8978ULL, 0x02E745C21FF43101ULL, 
            0x6C68CEFE4997A616ULL, 0xCE2DA0E16B37E276ULL, 0x47103DE89ACA492CULL, 0xAFF03AA5228DB769ULL, 
            0x3A2836F34500C489ULL, 0xF42B0312C0408708ULL, 0x8D10B82A574A4B69ULL, 0xA7C931E4CF67058BULL, 
            0xBBE0B942C7175634ULL, 0xC9CDF126A444F64DULL, 0x285436DE64C7671FULL, 0x40EF6F22DBB4980DULL, 
            0x7EA2992F4D413A5BULL, 0x3E837F2D20CC5994ULL, 0xD6843254F3EFE929ULL, 0x6295359B2E0FAC44ULL
        },
        {
            0x70C23DD98454B193ULL, 0x7398C5EDEEBBE217ULL, 0x01D832722FD394DFULL, 0x2F17F9A24E4EAC8DULL, 
            0x4B3AD6D6F5D25BA9ULL, 0x51C6F67319B23DF2ULL, 0x367FC8BA9D61A3DDULL, 0xD4F2CD85BA253722ULL, 
            0x7AEADD6A06FE86CBULL, 0x52C143D4629D2229ULL, 0x684BD30FE99C106AULL, 0x33181976B3FB93F8ULL, 
            0x5B0871BBE2F071B7ULL, 0x9003CB43376117D8ULL, 0x6AA7270FDFA91231ULL, 0x2FB81BD89926492BULL, 
            0x3337F05301AA5F00ULL, 0x1FB16F237D5C4240ULL, 0x0DA25359B47C5E53ULL, 0x98254AF33B275ABCULL, 
            0xE2ACDF45298DF3F5ULL, 0x4C5B873DF4F0DB24ULL, 0x752E80E89D2EB093ULL, 0x98CB97141B2E0578ULL, 
            0xE8180DF41C3E5B81ULL, 0xED1F2C9CA7B9C87BULL, 0x9F524F9333BA2EB5ULL, 0x98BFBF4AFB1899C0ULL, 
            0x63CD94E2B00C58A6ULL, 0x0EAB89C4053CDFABULL, 0xC24F7953E976F20AULL, 0x4EB2979C2903683FULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseFConstants = {
    0x4416C7B1A959831FULL,
    0x95B5CD44109C541BULL,
    0x57BBC70B35B0FD0CULL,
    0x4416C7B1A959831FULL,
    0x95B5CD44109C541BULL,
    0x57BBC70B35B0FD0CULL,
    0x31886DF4ECD4B968ULL,
    0xDA390F0751BD10AAULL,
    0x6D,
    0xE9,
    0xEE,
    0xAF,
    0x30,
    0x10,
    0xF5,
    0x7A
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseGSalts = {
    {
        {
            0x235E4CD321A4C789ULL, 0x83ED068D59C68A7DULL, 0xE6F58F06172F4182ULL, 0xB2AB4F8CCEECFA71ULL, 
            0x6EFE8492F6334531ULL, 0x55D381A2370C5A8EULL, 0x3F1B1BB4ABEA8699ULL, 0x5EAC3935DAB3AD63ULL, 
            0xB284D5B29F09B6ADULL, 0xE3A787C38C18E26EULL, 0xD577076FED53B7A2ULL, 0x53057D50F174CA4DULL, 
            0xE6AAFFEAC29FF192ULL, 0x697B3FF3386EDF86ULL, 0xF56635B2DD49CFEDULL, 0xFF057E67749629DBULL, 
            0x72880DB77CD2645CULL, 0x0815CB6269FFF3FEULL, 0x7644FFB4422A6476ULL, 0xDC6A962765FB2CE2ULL, 
            0x327E5A4D32311A63ULL, 0x4562B47B3717C976ULL, 0x2F08623CF654D8DBULL, 0x137BBF5F2656DCDAULL, 
            0xB253A250475FD683ULL, 0x2B81D166FA385E27ULL, 0x1A3FE1906D6558D9ULL, 0x9A805A0BCD1FC943ULL, 
            0x6CB959DD711F2538ULL, 0x6C0E53E668552654ULL, 0x9C2989356BC75D05ULL, 0xE58F6653F5A38952ULL
        },
        {
            0xC3C67F119BFEF8CCULL, 0x94580C7D4D3E2F22ULL, 0xBBF0C0CD423966CDULL, 0xF0A62B9E3DB85E7EULL, 
            0x2E7C9212781660DBULL, 0x3EFF0D9563E6D3B0ULL, 0x6B00D61796E1BADFULL, 0xEDDE14E185569132ULL, 
            0x39975CF79B437174ULL, 0xF33F15E53BD7F098ULL, 0xC61D40DE7DFDDE46ULL, 0x3159A23D712F3FFCULL, 
            0x1F5CD79FF3B1C7FCULL, 0xCFD28E828FB51B6DULL, 0xF8D7A9409F2E7ABAULL, 0x3E01B74AD29374F7ULL, 
            0x424B5374062B34BBULL, 0x9D06EA5CA85BEEBFULL, 0xEFA19A7A234B29E6ULL, 0xA43E2C7D7F10C0B7ULL, 
            0x37D313C63B2F56FDULL, 0x10EC966115D06B47ULL, 0xDD53B7D35B7FE3BBULL, 0xCFC3CA69D5D97B92ULL, 
            0xCF11D7990331171AULL, 0xE90BD1C734C8CF43ULL, 0xD3A006057017EE9AULL, 0xFA0CBBB4D3FEAA45ULL, 
            0x1575DF7ECFE7D1B0ULL, 0x6C134AD534C0DFA7ULL, 0xA468A79D66927B31ULL, 0x6CEAAFA540567771ULL
        },
        {
            0x9921ABAA8D7D9EA8ULL, 0x7683BEC533538502ULL, 0x670B7869729C3338ULL, 0x12E02FA943958CA2ULL, 
            0x1797CF597CD17355ULL, 0x44E9AD51E96003F0ULL, 0xB2477AE915556F69ULL, 0xD42E8C3A4A9A272AULL, 
            0x6005A0F5DB5201BCULL, 0x36BF6A02E4D9CF58ULL, 0x5555226DB7D76255ULL, 0x75382DE6BAB0ED99ULL, 
            0x696167EABBFC8AC8ULL, 0x05D1F040DEBA0603ULL, 0xFDCDCE34C34A1CA7ULL, 0x917DCF045240010DULL, 
            0xB7120CBF39495A0DULL, 0x0BDDEE515743AE45ULL, 0xFB779B6487BEA031ULL, 0x70329623AEB3A2C6ULL, 
            0x950E85CF43C3A4AAULL, 0xA1D010F0638275FBULL, 0x4C196FE9DCE8BE01ULL, 0xC9711BA95BEAF586ULL, 
            0x61A5FBA9CCEA7566ULL, 0xFE1E834A660BB687ULL, 0xD1E95693DCBF9F51ULL, 0xBFC3FFD9D2BB6F85ULL, 
            0x55A4C4D31F77BCDEULL, 0x71A061D8B9A3724BULL, 0x6297D0E1B022E2C0ULL, 0xC36FBEDA77AA1405ULL
        },
        {
            0x0DFDEB77875B7946ULL, 0x8FA5F3181EC74A75ULL, 0x2915EF184FE08616ULL, 0x22F7A267C56D6497ULL, 
            0xBB710521BAEF0AC5ULL, 0x4D05DB5AFFF2AA09ULL, 0x43F1F838B83DC596ULL, 0x607658400F318F69ULL, 
            0xC5B587E59AD7DC09ULL, 0xAD1258016759FA0CULL, 0x13CC18C6B5B79807ULL, 0x85A8D6D8B1C381BDULL, 
            0xABB8075EF58B735DULL, 0x9F95286B944FAAB9ULL, 0xA25108D374A6D806ULL, 0x376E2A63D538E481ULL, 
            0xBFB288DCFB48A8ACULL, 0x6DC1E14BE74B188FULL, 0xF34314F3FCF84AC5ULL, 0x2C217E5D8676AE5EULL, 
            0x53625CE9E7344CD9ULL, 0x21D79158692335FAULL, 0x475FA95050D8A0BEULL, 0x98A5B427E2A61234ULL, 
            0xD34A365307D13D59ULL, 0xCA290E8797C7E20CULL, 0x585815C753F8E2ECULL, 0x8E5DC17535D6DE08ULL, 
            0xAD645EF60F41A5A5ULL, 0x9809E44E47E42011ULL, 0x277BF3D7A529A63AULL, 0x1664733DA4DBF58AULL
        },
        {
            0xD3F940AD5E191358ULL, 0x604D2C65041B8081ULL, 0xFA99DE330154B030ULL, 0xE496433501A4CB35ULL, 
            0xE513B2813D9626E2ULL, 0x6F41F3B57A2603D0ULL, 0x02EE5B0B4B6CBDDBULL, 0xF311533D79A2FCA2ULL, 
            0x7D41EC8EF55561D3ULL, 0xE00DF4B148CE91C1ULL, 0x5550C7025C2CF185ULL, 0x00634B1E833D30CAULL, 
            0x83D8937F9268D43CULL, 0x1956DD7079F504DBULL, 0xA6B61DBDEC682458ULL, 0x5483CE8A2DDA908EULL, 
            0x27EDCEA9E4AECE1EULL, 0x260B00FD99BEAD4DULL, 0xBDD58048732FA1DEULL, 0x7CB94890A3792E97ULL, 
            0xAD74AB0D59C30D3DULL, 0xBCAE4D7616B0F3EAULL, 0xD9B0A8D63034AE14ULL, 0x62D08858E748F806ULL, 
            0x1D935F435292B1A1ULL, 0xCFBE96DC7EB6830BULL, 0xAE83DF12BC19D21AULL, 0x679D3BB1AEDE355EULL, 
            0x96A01ADB34820278ULL, 0xA19FFD8115F30141ULL, 0x2902CD05DE673300ULL, 0x92A040EA33E682B7ULL
        },
        {
            0xE3562A9A14EFE83BULL, 0xBCDDF32DA74C0F5AULL, 0x5F368C7F2EE81223ULL, 0xB9EA1C773019F687ULL, 
            0x0BF43BADA939CED1ULL, 0x78C2531F08C7F9ACULL, 0x2B593339DC10F2CAULL, 0x7C071F6DA6394B6DULL, 
            0xA3171DF63169FB69ULL, 0x99429371504A35FAULL, 0x0725B58B62BE7EB8ULL, 0xA44BCFF453B7EF67ULL, 
            0xA3731462CA1640D1ULL, 0x43429363464D50CCULL, 0x6075FA808AAF0A29ULL, 0x27266E2039E94202ULL, 
            0xF7724D78464C529CULL, 0xE24D1B81A54E51A6ULL, 0x116EC4519493AED4ULL, 0x2731EFC1D9522414ULL, 
            0x063C01C056B75311ULL, 0x566470E945238CCBULL, 0x99F12159CE59EB11ULL, 0xABC015250A7F507AULL, 
            0xDC16EE347BAD064FULL, 0x13E311DE5E319426ULL, 0xA1060A3E268DE1BBULL, 0xEA49110503C0F479ULL, 
            0x814D18262BE9C5D6ULL, 0x3397DC2ECE05D3BFULL, 0x4335B4DF1624DEFFULL, 0xBA5CE68786437228ULL
        }
    },
    {
        {
            0x7BBB7907E52E2652ULL, 0x86B1B9050DC5141BULL, 0x805DCC56AE7A3E04ULL, 0x4C8B45E405FE03F1ULL, 
            0x8E9A4E6539870E73ULL, 0x5F758D13CF387728ULL, 0x591A7EAD94DE51C4ULL, 0x8CFB1A6545DBC098ULL, 
            0x8729732F5BD337BCULL, 0x71FC970CE8E223C7ULL, 0xDD29308AB43CFB6AULL, 0x30F7075DCB77271FULL, 
            0x4BA54B3DAE777B0EULL, 0x30E4671B59AD3196ULL, 0xEC3929B7558820D2ULL, 0xEB74641E6D606541ULL, 
            0x65DD51428066F173ULL, 0xFC277A6EE5504693ULL, 0x1EB1C9BCFCEA7B9EULL, 0xA1C8060696310677ULL, 
            0xA96BD6E5A251CE35ULL, 0x71A2462EB59D5B3FULL, 0x66B3DE9441AE6616ULL, 0x2BB47159326152E0ULL, 
            0xE1AE23BF239A030EULL, 0x751B716529C0F7B2ULL, 0xCA3467CE17BDEA41ULL, 0x82FCAB92E12FD174ULL, 
            0x2318E44BD37081C1ULL, 0xF9FDB2AAC0CD03F4ULL, 0x6A26455F3E1B080CULL, 0x845BD77C7A0A76E0ULL
        },
        {
            0x0F73B0FBA3BB6657ULL, 0x80A9EEF57FFE4EDFULL, 0xFED9D68EAC46B2D3ULL, 0x9AC98249249C24B7ULL, 
            0x6045574C9D88EF32ULL, 0x36A2933310BD8B4DULL, 0x9523B8909E92E659ULL, 0xCFABDFA886043ED5ULL, 
            0x909A7A1A4FFCDD75ULL, 0x83CE86E973FF7ECBULL, 0x6983CE796FC95F85ULL, 0xFD993C502C64B5B8ULL, 
            0x23F96F590AC86E04ULL, 0x61CEDCD452FCF34BULL, 0xEAFF7AC8AAEE14D3ULL, 0xB9468E92164F80C2ULL, 
            0x963D524C2FFC7B54ULL, 0x06AA63A47BB4FE28ULL, 0x31C494BF7DBAD471ULL, 0x7204428E47A4B5DEULL, 
            0xD01783651F04B445ULL, 0xF361EBCDFB1313E4ULL, 0xE17944904E2B7059ULL, 0x4CD7766D15FE6DCDULL, 
            0xCA5103DDF08D6F55ULL, 0x548E866316DD295FULL, 0x4A9290962FA82E86ULL, 0x3DCAFD7D509AD83EULL, 
            0x700811130935EE55ULL, 0x07A79D385439320BULL, 0x9A5AD1A073A35F5AULL, 0x5A5C026C4C3E4A2BULL
        },
        {
            0x1D2208DE690F4F8AULL, 0x991FD77F150382EAULL, 0x85291090CDCC17C8ULL, 0xD609E169C63B39FDULL, 
            0xC110CF543B621A19ULL, 0xE9FF69AF26A17EEBULL, 0x533417B34AB6CBD6ULL, 0xF0C9B0698196B3CAULL, 
            0x20DACC1F2A6D08B9ULL, 0x2CDA0765C5B83ACFULL, 0xF5ACD3F9FED1B885ULL, 0x02C1401B95CFCE9FULL, 
            0xEF59D8D58B8744F4ULL, 0xAA9755475B0706C8ULL, 0x1C0A7BB9D2181746ULL, 0xEBC5A5F7A17EF39FULL, 
            0x3DEFEC45B44E6E41ULL, 0x8B7D2BB74334BF6AULL, 0x29BEB90FFB091A91ULL, 0x306900544F9D039DULL, 
            0xA44B126E5CC2CA22ULL, 0x2AEC76DA426EA243ULL, 0x7C478F3FDB4075DAULL, 0xF592A0DEF16E0340ULL, 
            0x52B55DB3F5810402ULL, 0xA3B42078EBCA26BCULL, 0xA5AB3ABEA7DC9065ULL, 0xE3AEDA82A2B57C6BULL, 
            0x422AEF952BD650A6ULL, 0x4DF5BD64CE594598ULL, 0xF05D5E5C963408F2ULL, 0x86EADA123D77DD0EULL
        },
        {
            0xB9DF53B093FABA7DULL, 0xD3D15BCD0B54CE48ULL, 0x42A5E05E3890ADD4ULL, 0x5640EA5A3644EC4DULL, 
            0x7038058A3B285178ULL, 0x9A4D18F222EEB1AFULL, 0xC4DD93F7352759CBULL, 0xFA3DFA55BB558059ULL, 
            0x5FE9DD06352A1F8DULL, 0xCF38A402EEF32C04ULL, 0x44394784C18F6501ULL, 0x84CF0CDC46C36AC4ULL, 
            0x2EEDF9EF927E797FULL, 0xEE72875C0005E32CULL, 0x3319088DF619A79FULL, 0x3BBD02966D4C22D0ULL, 
            0xB69FBEC252366C55ULL, 0xE17A42CB621077D8ULL, 0x92686C1DA3A30609ULL, 0x4342FAFF2FAAF883ULL, 
            0x77B495C7CEE80135ULL, 0xB736B70C78C65DB5ULL, 0xF8D2C9FECF2FDD79ULL, 0x46D254FB0A1FADF8ULL, 
            0x4DA1C72409ED6087ULL, 0x2A459C22201F27BAULL, 0xA2AB94F53708299CULL, 0x4B98030526AE2B52ULL, 
            0x3E5DD3BB234F975AULL, 0x96F6BAF63CB4C6A3ULL, 0x148030A6C6DECB53ULL, 0x48E10DBBF8F2BF7AULL
        },
        {
            0xD990A9FEEC384C72ULL, 0xC2ACFB9EA73D8DADULL, 0x6B21A24A4E90671FULL, 0xE3017FB6D43E83C1ULL, 
            0x9859C9EC4DB9703DULL, 0x70182D8834FB5316ULL, 0x3A69F9C26E97EC71ULL, 0x4DF8F90D5D815900ULL, 
            0xC19678BE4F0D9823ULL, 0x728EB25F276FCAD6ULL, 0xFDE96C858953C492ULL, 0x08E8E5624EC3596CULL, 
            0x6C4AA58E0A8B22C6ULL, 0xBA2AB955255BBCCFULL, 0xEE7C6916C878D999ULL, 0x680E841648DEC1BDULL, 
            0x9F489A9E9F8C5DB6ULL, 0xFE2792D62EF725E2ULL, 0x048494E4B3F1FFFEULL, 0x0A6972DA36FEA70BULL, 
            0x82F3BADE06052BD9ULL, 0x5570B8C5FDC680D7ULL, 0x6E5392D477E96599ULL, 0x6EFF708F16DC9446ULL, 
            0x1EAA7E6BFB3B3A10ULL, 0xBF7897F8BCAAF66CULL, 0xAF89C71C67C3248EULL, 0x2CF9D407078DFA5CULL, 
            0xE799DCD9EE10C2C3ULL, 0x85B20C4548AE6F2FULL, 0xAE94EB6951250179ULL, 0x5CF260BD2CEEBBC8ULL
        },
        {
            0x6304B74ECC80A57EULL, 0xD0130BFA73E94F19ULL, 0x4F8E480DDFC50AFEULL, 0x70154FFFECCC5BB2ULL, 
            0x17D48DB444A9E01BULL, 0x2EC56488CDED5DC2ULL, 0x8ACB9A1A7BA4E62FULL, 0x80698C20FDC81C1FULL, 
            0xBEEA6E760F4ED368ULL, 0x3002A6283C2858CCULL, 0x07B6F0945C1B8743ULL, 0xF3E6E577BF13BB63ULL, 
            0xA1F78C5F587ACECDULL, 0x20AF5EC1D5F748C7ULL, 0x310F9E5955695F15ULL, 0xDE0A5AAE1D38D12FULL, 
            0x2A2046FAC2B477F2ULL, 0x7DC1C3E4D7E4317AULL, 0xF650BC30EFD0915CULL, 0x10EDEE9DAD4E1147ULL, 
            0x2F6C551EBC239F8EULL, 0x3741DF1167BF14BFULL, 0x59A573388A39D96EULL, 0x7553D4A1DBD5E52BULL, 
            0x339E3EFD3CEAE7BCULL, 0xEBA872735EF4E715ULL, 0x73CEC159926645D8ULL, 0xB1F56968AB8D257AULL, 
            0x33A9FB3A13BB691AULL, 0x0D7CA6E52DF3C0E0ULL, 0x8D5FCC48888B4F6EULL, 0xF2BA4567126B3594ULL
        }
    },
    {
        {
            0xF913E1D17FE65E53ULL, 0xB9C16AEF43A700B0ULL, 0xD6A786D44E1BF947ULL, 0xDAE151FD549951E7ULL, 
            0xF83D1CBF184CE5A8ULL, 0xCBE2F25B7C15174CULL, 0x3253E2B3983A7F70ULL, 0xD1150362EC496DFFULL, 
            0x3080B30C16BA8AECULL, 0x5883AA4EDFBA1F56ULL, 0xFEF6483B220AE4F4ULL, 0x620B680B1B61AA74ULL, 
            0x14841F15EB5CBFDCULL, 0x9FC9901EAB0138DCULL, 0xEAC3ACA651C6D890ULL, 0x410781306BCF8237ULL, 
            0x34E5D51FEA322E2EULL, 0x75E9E85295A10C5CULL, 0xBBAC523213E34AF4ULL, 0x1B890B9D3CF75220ULL, 
            0x722C4B18C90E3566ULL, 0xE642A5DD99B62103ULL, 0x4F46C970F7DAFA6EULL, 0x4C3D50367F902857ULL, 
            0xBF2B72D2E20A2365ULL, 0xE1F1F97DFA8DE840ULL, 0xEC48BC9C6467FD98ULL, 0xBA6057CC84DB9FD3ULL, 
            0xA8B2E9559B742F5AULL, 0x157B5936EB44DE25ULL, 0x6B13DD09599593DFULL, 0x8A5E9858DDB278F4ULL
        },
        {
            0x62C2BDB3146A757BULL, 0xDC52D68BEDF28800ULL, 0x95E9C7A7E04821CDULL, 0xC0526A70C8639AEEULL, 
            0x7457B31EE528CA19ULL, 0x1DAB420CB7B550BBULL, 0xC955F60383214262ULL, 0x5900105E2678821CULL, 
            0x93B438D8A454C609ULL, 0xE74B055B142F3A0CULL, 0x50E73AAD801F865BULL, 0xC623FA39F63AE3EFULL, 
            0x830EC57803547392ULL, 0xDF87D1C647B52D3FULL, 0x2B162269C6FBE1C5ULL, 0x39E4EFAA715E282AULL, 
            0x1EE42B96231AA392ULL, 0x18C67F5CF6351EB3ULL, 0x9E23419EBFA3F2E7ULL, 0x6CC115E481A47B55ULL, 
            0x531338E1F8BA4E2CULL, 0x63B9A8645A116FC2ULL, 0x822D3C387E22E6ECULL, 0xC03CA60C6D0E4835ULL, 
            0xE6089E9394EFECB7ULL, 0x1BB356ADD32D36AAULL, 0x4E65C6306AC147CCULL, 0x5B8123784EBF2025ULL, 
            0xE1D49DD92ECF23D2ULL, 0x67CA08A4ECD6C52AULL, 0x3A085EB84146DDA8ULL, 0x29CAF2FBDC20C897ULL
        },
        {
            0x8D85DF85D7162BB9ULL, 0xDC264028307E0D8EULL, 0x6DAF2609D710B36CULL, 0x8AFB07E6ADAC3A78ULL, 
            0xAC6D05248F302E95ULL, 0xE22BE5961653E941ULL, 0xF50DD017372017A7ULL, 0x0BB47D6321078151ULL, 
            0xEF6D2173C115FCD7ULL, 0x5721BCC4773CDD21ULL, 0xF76698332601113EULL, 0x286028261F6EF12DULL, 
            0x969990D42BED8AADULL, 0x1D934DA969D5E9BEULL, 0xD273D2DE7F0DE707ULL, 0x37A51894E27C2A5DULL, 
            0xB93FD8F2983AA169ULL, 0x29C128CD053F99D7ULL, 0x1C61659E57565DF4ULL, 0x55FFF349B9E9CBA0ULL, 
            0x59D07A19D401B876ULL, 0x3C48B85438F6E3ADULL, 0x36A63F420911B483ULL, 0x13FBEE272C30D49FULL, 
            0xBF6ED4A224171AFDULL, 0xF2347F7193BE8B12ULL, 0xAC48ACA1C68E203FULL, 0x5B128F697302936BULL, 
            0x52DACD0BB6FC5740ULL, 0x6E3EF46287F59B7CULL, 0x7C9939C1157319A0ULL, 0xAF84328CAEBA4704ULL
        },
        {
            0xDD8BC2A763DBCA55ULL, 0x1BC60B91E6A48365ULL, 0x0A9E3427754B674DULL, 0x1517BB8C40E74AACULL, 
            0x326938A6473A640FULL, 0x0E05E477D02CA6B0ULL, 0x94EEC648D1E68262ULL, 0x0BB1549631BC784AULL, 
            0xD69AD4B071DE4BD3ULL, 0x3D7085869F4FF17DULL, 0x260E50E0889E658AULL, 0xD17F0003620EA0B8ULL, 
            0x7549C401428A1966ULL, 0x994CDE9B0BB4F99DULL, 0x73070751DE56DA69ULL, 0xABCAA103AF8AC7BAULL, 
            0x325DE3330652C655ULL, 0xF896B5916A0FE0CAULL, 0x0933CB94211F00B3ULL, 0xD4FA6FBD6C5A34C1ULL, 
            0x3B888F809CA3EA53ULL, 0xB493868FBA1D1820ULL, 0x16507524AD7A2C25ULL, 0xEBD38CE115F677A9ULL, 
            0x513C4E85D913BB3BULL, 0x95FA8DB835541BADULL, 0x0EACA009FBA8D23AULL, 0x8550B02FC1510520ULL, 
            0x8F54ABB938D2819AULL, 0x490848AC2A1DCC28ULL, 0xC384F9A2901AD601ULL, 0xCB3CA6CFA3B0C6B3ULL
        },
        {
            0xE604C3F678B5E023ULL, 0xB6E27430CFE703B6ULL, 0x880F3CB78A24CDEEULL, 0xF6494566DED152C1ULL, 
            0x11FE2D30CDD964C8ULL, 0x7274C8835B2424A2ULL, 0xE8EC5933D395EFA0ULL, 0x3E60E087C242D51EULL, 
            0x7122236286426CD6ULL, 0x198BAAB521C80EC0ULL, 0x96E01945D08C70E1ULL, 0xC31649AD974BB944ULL, 
            0x0D2DA59FDEB43DE3ULL, 0x3B25558191867C2EULL, 0x96D6DE80CAAC5A22ULL, 0xDC364C5CFEA1AE2EULL, 
            0x24057DB3D51745EFULL, 0x7DA54904D8FAE815ULL, 0x92292FEB11BE0EDBULL, 0xB99F8CD0F177BB91ULL, 
            0x84366573839C06A4ULL, 0x48C4F814E2E20665ULL, 0x423D59A8CF4D0347ULL, 0xBC44B03FF115B6DDULL, 
            0xA49E005738F387BDULL, 0x0FA8C89C2699E903ULL, 0xD640BAE17038F79CULL, 0xC59F97E0B82F8944ULL, 
            0xE3B57DFD03DAD5F7ULL, 0x59F5265D831A609EULL, 0x348BC62A33AD5124ULL, 0xA13658C0FC59FA83ULL
        },
        {
            0xBEC88D1F6214369FULL, 0x24F7F2CAC68952AAULL, 0xE2EFAAFB1A41FB80ULL, 0x34E03AB2EC546F7AULL, 
            0x978C077AAED9429AULL, 0x7D5A8A67768F9C57ULL, 0x6A31D0B6D3EC8982ULL, 0x355ACD94BA0C3FC2ULL, 
            0xD39CE4DBC8D5DD46ULL, 0x1990992F37F26D85ULL, 0x587DF5EE53334A07ULL, 0xDEF4BD2C9149209BULL, 
            0xEE6C487CCC95FC74ULL, 0x0FFE8FA4F631178AULL, 0x60436C888FC3C73BULL, 0x6DBD04F2BFB96DC7ULL, 
            0x7EA238AF9596BF0CULL, 0x0B83FA83D4F1C9C2ULL, 0x04E3C00CD6213D72ULL, 0xFC4016E13354897EULL, 
            0x2BB4B5BEC1AC98D3ULL, 0xECFF919CBC7862C3ULL, 0xB3E7A6FD84C9ED77ULL, 0xEE7208A0AEA2F44FULL, 
            0x606C4598CB1A70DBULL, 0xF7D7712F12453101ULL, 0x108C172781B0C116ULL, 0xC7E230411A1975E2ULL, 
            0x629E10F97D42580EULL, 0x18BC59F21FA89732ULL, 0x05D6BEA1021A3050ULL, 0x76B8427679494261ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseGConstants = {
    0x1565B2B146DD82CBULL,
    0x5786CC7B6D8354C7ULL,
    0x09C5090AA17FED36ULL,
    0x1565B2B146DD82CBULL,
    0x5786CC7B6D8354C7ULL,
    0x09C5090AA17FED36ULL,
    0x769BC86B9AF6926CULL,
    0xC6379371030C68B9ULL,
    0x65,
    0xDA,
    0x76,
    0x85,
    0x2E,
    0x7A,
    0x8F,
    0xC7
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseHSalts = {
    {
        {
            0x31ACFB72B18B283DULL, 0x82DD173832642A1EULL, 0xC85E44D3D1B69B2DULL, 0x20180B0DDF3C2642ULL, 
            0x7FCD9617A19D14FDULL, 0x77927386B3032846ULL, 0xD3A94B5BE97DEE1FULL, 0xB0C2E5D0CC767AB3ULL, 
            0xA94261C5341B282EULL, 0x06B1857197071BAFULL, 0xE877BD761ED8C0EFULL, 0xBE5818F25362E34EULL, 
            0x281A6F340ECC7ACFULL, 0x670EA44C1C7D22ADULL, 0xF1FA9D82CF06675EULL, 0xE31514B2A4CC5908ULL, 
            0x683A6687FE377453ULL, 0x618792E74B0F380BULL, 0xC00CE7654773FC4FULL, 0x02044EA8F39F83DEULL, 
            0xC7DBCB59115692A5ULL, 0x4972F9A732B4C7D9ULL, 0x05C7ECD661F28809ULL, 0x07FC9769BDEC555BULL, 
            0xF1BAFD9B1479FD50ULL, 0x57F32AEF3A9856A1ULL, 0xC5AC9AF07C793F32ULL, 0x7EB5B35F4E216B29ULL, 
            0x35D0D9B2775102FFULL, 0x36680622E1155926ULL, 0xD5DED21553629CF2ULL, 0x892B2DD30462E27FULL
        },
        {
            0x17803849446480FCULL, 0x5ECAE48F0610D388ULL, 0xD17829F1189F5B2DULL, 0xBE383ECC27D9D04DULL, 
            0x09C2D0E572688E50ULL, 0x36F4CBDFBDDD71E5ULL, 0x923A7913CAE746A2ULL, 0x934B05B190FA520DULL, 
            0x71A3FDF369AFCD36ULL, 0x5A90EC2CD84B740DULL, 0xE215665D302D5257ULL, 0x2E6B0BFF1FA545D9ULL, 
            0x9DE5F29DCB0EF293ULL, 0x27696242E1B8D19FULL, 0xEAFBF437340F2B1EULL, 0x8FBAD73A62E29BE3ULL, 
            0x38D3BCA3AED23BF7ULL, 0xFB03EE513BD7C49DULL, 0x994BC789950831B6ULL, 0xDD243CA0BCFD01FAULL, 
            0xE2E6BAC9CD8DD752ULL, 0xBC14FB8336AB1F3AULL, 0xA57FF5C7EF1A571FULL, 0x66D6172BF23B1A83ULL, 
            0xD60757F4F1539DB4ULL, 0x35FEBA487B2FCF4EULL, 0xCA3EC06446E259F8ULL, 0x13F99A838032B631ULL, 
            0xF3D437CAE8E9908AULL, 0xD8F6F067673941B1ULL, 0xB8B52F9273CA0FCBULL, 0x3DB724FD61239936ULL
        },
        {
            0x910353E981C337C3ULL, 0x69D0989A73F793DDULL, 0x541A8EA8200A25D0ULL, 0x2492770CCDB325B5ULL, 
            0x864012766EE5C383ULL, 0x3C4634DD0DA244B1ULL, 0xB1EDE4318A0408FFULL, 0x2757A6E24BE40B8DULL, 
            0x2CCE5EBD1697BA96ULL, 0xC7E6F6AE3DBEA17DULL, 0xB43E678D1DE8B207ULL, 0x0879A1766A8E0121ULL, 
            0x72059E56D4FBD8F1ULL, 0x52EE1A23F53C36B1ULL, 0x4C97EDE10AAF01AFULL, 0xC32B7607CC92C9ADULL, 
            0x1324684472B72239ULL, 0x5D81DF9AC75F6B87ULL, 0x7C69C62CAF0DDDBAULL, 0xD6FBB65BE9D06395ULL, 
            0x50327776441D07E7ULL, 0xFAB0452ACD0A21CDULL, 0x5330FADE6E00B61AULL, 0x8234F4F25A2B7A5FULL, 
            0x522B1D7175D6E72BULL, 0xCD6AE0EA3E5C471EULL, 0x1BAAB3D4F48059F1ULL, 0x09A4F862D5F1835FULL, 
            0xBEE796FD8779C29DULL, 0xEF3EF9B249271CC8ULL, 0x8C5F72D7C904DCD6ULL, 0x0C1ED01BD4EDDCB2ULL
        },
        {
            0x076ABDD25997C944ULL, 0x13DFEC36C3068616ULL, 0x2693E8F72C5F23F2ULL, 0xED057FC291C7DA19ULL, 
            0xA793402F431DF281ULL, 0x3E08ABBDBA67308FULL, 0xC13F86CCA3D5A584ULL, 0xEDB03EA108E74B3DULL, 
            0x426F52270240D0B5ULL, 0x54AE7B6703692727ULL, 0xC0B31417C611D546ULL, 0x1D753D86583C3D79ULL, 
            0x1B34144D53C37BDFULL, 0x8EEB59B1CC28EF41ULL, 0x7ED85302F9C17FB5ULL, 0x2AE90FA87EFB45D7ULL, 
            0x157E874681380BA8ULL, 0x29B00E43B3F4BE46ULL, 0x8C896B3A7BE3AFA5ULL, 0x5AD8A1785E889B41ULL, 
            0x8FDA4610040FB164ULL, 0xE0DA6A2460F23B7AULL, 0x78BCEC103F6F4A9AULL, 0xDF360DA953D5BF03ULL, 
            0xFE263197AA550DEBULL, 0x064C8FD9E330B384ULL, 0x01D15C34C3F78BCCULL, 0xDAB6988C93868799ULL, 
            0x689E27EAC81BC8A2ULL, 0x90C18FDB7B1F0C54ULL, 0xBBFA7BFADB38B33AULL, 0xA26C8967D7CF4DB1ULL
        },
        {
            0x7B8E9AB56A8A8CB3ULL, 0xB1074D7B29ED4C9DULL, 0x00A0CC5172774061ULL, 0x79EEE330DE2323A1ULL, 
            0x501E4CECB2004FF6ULL, 0x9A3FC325E2261E6AULL, 0x280871D5C53778F8ULL, 0xD6249A402CA6E064ULL, 
            0xB0196A2F0DB8DEF0ULL, 0x0B85016D92A28E5DULL, 0xAA4A1811E8AEB994ULL, 0xD24958728E9E618FULL, 
            0x41310A435B10E338ULL, 0x82B7CDE4C36A8BB1ULL, 0xC7EA19237054CDB2ULL, 0x6541E391C4D18A78ULL, 
            0x3121F1CB0E45F7FEULL, 0xB1532F04BFAB7D61ULL, 0x3AB0A7C5CD6B1996ULL, 0x9B829CF5E1BCCC80ULL, 
            0xD9DF6A4FA0B9E557ULL, 0xDCA1515DE7043B14ULL, 0x95B4181DB72AF9ACULL, 0x9FFAE66BFB87FD57ULL, 
            0x0A7114AC6A00CFE2ULL, 0xDD0FF87ABD1DA00DULL, 0x2E39B32E6ECAEA41ULL, 0xCA6C443C3D073790ULL, 
            0xD20CD87D25A4751EULL, 0x1DFD7CB95CE3F8DDULL, 0x21A5CEAB86903CE8ULL, 0x478B33176E3FB2B5ULL
        },
        {
            0x4AE9310B2C606B23ULL, 0x408656D9C65B52A7ULL, 0x67B655F8D63AD0A8ULL, 0x77C962958C83C94CULL, 
            0x7991882DA1D13D9BULL, 0xD535EC496F9DBC49ULL, 0x5FC41B212E414727ULL, 0x8A0EC3FC6BB95299ULL, 
            0x2C81C6BF2B6EB73FULL, 0x81AAA14EFDC60A94ULL, 0x14E967C1E5C180E1ULL, 0x400E1F1CF9963D85ULL, 
            0xCF2B80475577769DULL, 0xF4C41FB431E1EBEBULL, 0x02BAE8BD32E93EDCULL, 0x4F2D39AFA4315309ULL, 
            0xD8D2B8AC1EBC3827ULL, 0xFE95D1CB805DA511ULL, 0xDF3BF787E3A2C735ULL, 0x7D9A0FD31BD16641ULL, 
            0x67CB7505721331DAULL, 0xA6524F60AC8AAAFDULL, 0x5B6390C783C53CD5ULL, 0x9393C51A060AAC75ULL, 
            0xD6A2A5B0B139DAACULL, 0x89E3160188A13E7DULL, 0xCC808B16D2A6154FULL, 0xB6A1F0414547AAD1ULL, 
            0x8207E0A8D8A19139ULL, 0x8754676009465F09ULL, 0x5EECDC7782DDB9CBULL, 0x4D46A5F2EF98E93DULL
        }
    },
    {
        {
            0x9E15FEF9A2E2753EULL, 0xC1532979D83140B2ULL, 0x56ACA584461288DAULL, 0xE4DFDA06E1398763ULL, 
            0x2B99AA062BE157F6ULL, 0x46E25902C301E242ULL, 0xD2E13AFC70794916ULL, 0xBF8527F759433C87ULL, 
            0x933F851E5C363112ULL, 0x1FA668A0A37CB36AULL, 0x17EA4BE481138F59ULL, 0xD602DAE8102E2CD2ULL, 
            0x67ADDA84E423481BULL, 0x14C11EAB8EDE2FE7ULL, 0xD3597C608D21D778ULL, 0x938937B48E7898CEULL, 
            0x1AB138CDFE457106ULL, 0xEAACD9E7FADF0359ULL, 0x841C3E96ED668BC0ULL, 0xB296D11A9B0D095AULL, 
            0x6E7FB4CF78A3946EULL, 0x687E572EEEE760AFULL, 0xA7BE2CC11A1E48CAULL, 0x1EF2D96A822DFB05ULL, 
            0x09293F4F4222154BULL, 0x532C782EAF1811A4ULL, 0x02F91F0911A1BD4CULL, 0x0D37313C4B8D157BULL, 
            0xA91761EE45132068ULL, 0xDCBAE1991542365DULL, 0x25641CC5FDB1B183ULL, 0x087F9D9437738730ULL
        },
        {
            0x5DBE2731760AA82CULL, 0xF2669E862B8B958FULL, 0x019CBFB8E044BE34ULL, 0x44D6F8C7A64B3AB2ULL, 
            0x2B385809DE83755AULL, 0xED2E4D0D4D1318E2ULL, 0xB395BDD99AC82F58ULL, 0xB93F78E53E6A8D22ULL, 
            0x9D5224C40C91477EULL, 0x0C4A84CE884A997BULL, 0x3DA44026B8768A40ULL, 0x3A82C787326E43D3ULL, 
            0xD059DC9EEC386AD5ULL, 0xB9083D3FA8F63309ULL, 0xB5256DA444C2ADF2ULL, 0x5E248880215BD639ULL, 
            0x71799D1D4D887045ULL, 0x19657C978E25A530ULL, 0x21DA6E4CDF3FE0D3ULL, 0x194412657B9FE83FULL, 
            0xF641FFA756546463ULL, 0x163B2CDAF39B6E9AULL, 0xD8BF799E332159C5ULL, 0x9C4D45D5E6EDFFCDULL, 
            0x43821CD471957564ULL, 0xE206BACF35CE42F6ULL, 0xD217191AB482A364ULL, 0x9662646258D590E6ULL, 
            0x6A3BDD8D38656673ULL, 0x8FEDD48A841945E7ULL, 0x5BB3459C58ED5D56ULL, 0x9C2427517D757783ULL
        },
        {
            0x4D7F8B43C2B14CA3ULL, 0x3DA7E3182AC305BCULL, 0xDDBA38CB49D42ACDULL, 0x3F44DE8D66D59630ULL, 
            0x38AD742CDF46B6CCULL, 0x6296E76ACE7A88CFULL, 0x3AD26408FE3DFDC0ULL, 0x2724C85BE275B877ULL, 
            0x2BD83830400C68A6ULL, 0x1951B4EAF4728076ULL, 0x59311D1153531855ULL, 0x954D5FD871C66690ULL, 
            0xACA97D671A2452B8ULL, 0x0A09C39565F51E0EULL, 0x7DEE52706611DEEEULL, 0xFBB836C8CB36BDEBULL, 
            0x2BCE5A2D9B467E57ULL, 0xB4346D0682674574ULL, 0x1612EDDE1D70377DULL, 0xC8BA524E28CD38D8ULL, 
            0x3897A1DC2F7114F1ULL, 0x3CB4D7DC7F497316ULL, 0x8EE325BD01231832ULL, 0xF93C12027E7D51DCULL, 
            0xEEFE14B6CB9CC8F4ULL, 0x7F1BE264CC71A3E5ULL, 0xA3E8DC7F6EF3ECADULL, 0x82583C89D3C58402ULL, 
            0xEDCB29CB11DDA0FCULL, 0xE724F872943FF83CULL, 0xC36F52CBFC8F21B4ULL, 0x71B2D13FE87AF23BULL
        },
        {
            0x0473D1AA2BFCC938ULL, 0x82695389902A44CFULL, 0x9B0789ABB26F5377ULL, 0x1252C1A253FD8B89ULL, 
            0xEF4D3B368E09B23DULL, 0xB777866C0A467201ULL, 0xEEF0E7219AA52704ULL, 0x096148A7CA7ED9CAULL, 
            0xB239B55072898033ULL, 0x7EFCCEC7AA93FE4EULL, 0x6F43BC12C54EBA42ULL, 0xEAE32610EA8C09F8ULL, 
            0xFFB6D52A2846C64DULL, 0x1922C41D9971790EULL, 0x74F5CB01466D2FF2ULL, 0x6D1404DEE0B29778ULL, 
            0x39AA3A0AC1DB5D70ULL, 0x8C3195330FFDA012ULL, 0x88AE3BA79BB28CE1ULL, 0x25722062F7A3D0A6ULL, 
            0x6B2683E5E908C3D8ULL, 0x3BC9DCD456F635F3ULL, 0x83E0F7C61A35FD1BULL, 0x4AE1E54C980BB354ULL, 
            0x6DE9FA0D01D697C4ULL, 0x23579310DDA6D696ULL, 0x82A3FC23AD4D2882ULL, 0x3BFF25872FC2F8BEULL, 
            0x470247565D5F0311ULL, 0x2DC60B65E1D6DCCBULL, 0xC5660DC7548B7D3BULL, 0x40DEC436D45B0DF2ULL
        },
        {
            0x038E6BD2FF026BB0ULL, 0x161218D7EACEC008ULL, 0xD0B5FF74321F1402ULL, 0x16258357B1DCABB5ULL, 
            0x73CAAB14BAF7F321ULL, 0xB002A699532E3070ULL, 0xF354E87D946C5C72ULL, 0xCE395BF5F6466BBEULL, 
            0xC88FACAEB181D1CCULL, 0xC5847120C1C9A849ULL, 0x0FC2B4558200E378ULL, 0x9ECB1DBB6B447B19ULL, 
            0xD7356D2A69311BFDULL, 0xCD3F4DFC067172D6ULL, 0xFA6317CFE679E9F4ULL, 0xA100F0246D617D7DULL, 
            0xEDEDF675ABDC8380ULL, 0x13143A47DE30C053ULL, 0xBC670AF5D1BF9794ULL, 0x34B909EECC3F0C35ULL, 
            0xB37EC20EA3AE84B9ULL, 0x3F9A4B0DC3105021ULL, 0x46C7934928E0B4C9ULL, 0x6181CEFD62142895ULL, 
            0xE2B66B6F324BDBA7ULL, 0xD77DF0F89CF25C4DULL, 0x13E026BF22F29FD3ULL, 0x1A83BE2D0CB84065ULL, 
            0xC6213A52DFDC5E32ULL, 0x2B7C99933C31CD3BULL, 0x4FAEB5C93232A091ULL, 0x18D7BB2E755C2F25ULL
        },
        {
            0x1572FAC59E062700ULL, 0x871EFF2364AD6EE1ULL, 0xDCBC437FE5EA5F47ULL, 0x35634D03C1C1B5F6ULL, 
            0x1139F38776E4AEA3ULL, 0xBAFD205FF9ED28A5ULL, 0x3E14049158EFF219ULL, 0x41C3ADC5F230BB43ULL, 
            0x63297EDF44BED1AFULL, 0x88D52DC9BCEC002FULL, 0x6FD9425BA120F0D9ULL, 0xD4C523652C814C0CULL, 
            0x6914D3D8B7D0DB13ULL, 0x4E295C2BE28CD598ULL, 0x529A49E2DFA60832ULL, 0x05B2E1AF06DAA6D3ULL, 
            0x6AF01B152BCB3F31ULL, 0xE6B2C36DBD6D61ADULL, 0x492E25930CCEE64BULL, 0x91B5503D37F70D3EULL, 
            0x8E29C8F945FC8AC7ULL, 0x452E6F83AF9B2710ULL, 0xAFD2D645B75D87B8ULL, 0x13B62335C8732D24ULL, 
            0xE486138781753AC6ULL, 0xCFED4DB7898355FFULL, 0x08B5A0E36F551E54ULL, 0xAA7B787AE7933584ULL, 
            0xBCBB73D227717B0CULL, 0xA54B610E4F776B89ULL, 0x44EC96F1D8027585ULL, 0x9312D63E3E929955ULL
        }
    },
    {
        {
            0x212C0F3DB94D21C3ULL, 0x4EEED4AF1B414406ULL, 0xE4CCA7CF43F6DBEAULL, 0xBB9880EAD7590263ULL, 
            0x797368CC991FD0B8ULL, 0x8ABBE07A15A77D70ULL, 0xC0CF3665904DAE7DULL, 0x39C7A5FE53790F94ULL, 
            0x7C8F2210D230FA39ULL, 0xD83F4E8695127790ULL, 0x7A74F5F14B281880ULL, 0x3DE374A7CE499502ULL, 
            0x5A1A16BB0118BFAEULL, 0x522B45597232F632ULL, 0xD1A9A25750CD23A1ULL, 0xCD53884CA98D6DC6ULL, 
            0x5B015EFA22B0DA49ULL, 0x599E04A046702A19ULL, 0x38E9C45BE3CB5172ULL, 0xC20236E6F7C47E29ULL, 
            0x157723E7B8CEC473ULL, 0xE6F1DB4EDDD00F0CULL, 0x9AF84DADA8DE56CFULL, 0x0361830DFEA64918ULL, 
            0x06E8EB5E7B618650ULL, 0x936FDB4134629C84ULL, 0x103D109068C5BD9AULL, 0x1C3356657EB0659BULL, 
            0x499ECAC9D6A17EB2ULL, 0x9B7D7F315A1C0A22ULL, 0xD6BB6B36476A9651ULL, 0x438CEF57E1719AC5ULL
        },
        {
            0x5C3F90F2E62ADEDAULL, 0xD6557DADB0E90039ULL, 0x2AFB1C213C91F566ULL, 0x596D0720649F218DULL, 
            0x7BA855DDA77C47B6ULL, 0x6E61B6D3CF99F04CULL, 0xB5FCE34BF796CE71ULL, 0x06BD3AF8C1914ADAULL, 
            0x48396A0AD22C1D8EULL, 0x78378106F7836E64ULL, 0x133C50BAF7723937ULL, 0x6F96657BD8B08C2BULL, 
            0x192B47350A175549ULL, 0xA36E7F32E41796F6ULL, 0x33D28D3DA03DF311ULL, 0x0F6482797AC339F2ULL, 
            0x8AA8CAD3CE4CA759ULL, 0x24433148472AC06EULL, 0xC7C8BF4398972D0FULL, 0x04D9BEA6825F963AULL, 
            0xD81D73F2FF6C7ECEULL, 0x4A1C4B25D1D3BB4AULL, 0x384C5DF893DE59A6ULL, 0x4873AD58C14E2DBAULL, 
            0x2115D7B6380C6FC0ULL, 0x6F6CF2B3307D917DULL, 0x93683310F5D4F19FULL, 0xF985E8CC0CA9F8DDULL, 
            0x847789822231004DULL, 0x9B59C61DA5752776ULL, 0x41B64F2A6E493AD0ULL, 0xA5759B660668578FULL
        },
        {
            0x5D36EED039750533ULL, 0x452655D3858978EBULL, 0x3903CC006C2D5DE0ULL, 0x64D377BB3FC94088ULL, 
            0x8B9EC4EB0FD6DB9DULL, 0xCFBBBB9F12EBF9A0ULL, 0x9876398B48BFD17FULL, 0xFB2A7872B145858CULL, 
            0x8F2509E9EBC37C04ULL, 0x4BEC7C1DFD2AF76CULL, 0xAABB174AC0682DF8ULL, 0xFF2755BF20969626ULL, 
            0xDCDFED1739211F2BULL, 0x2C6E117E9F787A18ULL, 0x3AB7838383F3E374ULL, 0x262832421B842744ULL, 
            0x217CBC75FFA958F1ULL, 0xF2C3F8199A80369CULL, 0x21F854E9CA026545ULL, 0xE2535D75DCE1D6FBULL, 
            0x79A39D752B52222BULL, 0x6924F9FFD60FB5E3ULL, 0x92668748EC331A99ULL, 0xFFF0AC9AD5F75245ULL, 
            0xB0A19DE8FCF3F1DAULL, 0xB9FC1876D70960D9ULL, 0xBF31415D9E53B6FAULL, 0xFBF7DE4F632ECCA7ULL, 
            0x34A664EE8E138716ULL, 0x41B8C463BD6E0FE8ULL, 0x16B43ACAA815D1ECULL, 0xC6B958748CADD826ULL
        },
        {
            0x9882825BBB9915CCULL, 0xF1900F815C1F2529ULL, 0xDB37BF5D380DD9E1ULL, 0xBDA373CF25DC9364ULL, 
            0x1FB7256F7122C4CCULL, 0x51556785AE5C3B01ULL, 0x26463875AEA5BDA8ULL, 0x089A6AA63ED92F7BULL, 
            0x703760BDE883657EULL, 0xF924104846FFF3B3ULL, 0x44DCD8AE867DF7CDULL, 0x900DFF2465413156ULL, 
            0x021D0A53F5465E66ULL, 0x69ADAF3EE0A9C0E7ULL, 0x17679E1022B9E2D6ULL, 0x135EAF3EF406F086ULL, 
            0x35D6FE9E49CFC193ULL, 0x62A3F51293905AA3ULL, 0x850DF79860A1C32DULL, 0x62F2D6D2ED4380D6ULL, 
            0x6B54A0D267979096ULL, 0x88863131F910F5BAULL, 0x0ED1B25ABE67654CULL, 0xEB7D1987CFED2AA9ULL, 
            0xD400A1B0A87E7429ULL, 0xA3BEF3D6B357F3C5ULL, 0xCA354771A18326E9ULL, 0xB8794E5D5A89288FULL, 
            0xF9162B3BF3FACD32ULL, 0xB299EF2C218E7279ULL, 0x812527E8C12130DDULL, 0xE2B8C9C9541145C1ULL
        },
        {
            0x57207C72F377F734ULL, 0x1654C2D79B850E56ULL, 0xD0BBB88B7A13947BULL, 0x88EA1658C6CD8249ULL, 
            0x3600C94265E76A14ULL, 0x2E4983ED147A23BCULL, 0x306123831E111A1FULL, 0xE6D82A12223598A6ULL, 
            0x978CC3978B59C725ULL, 0xBCB3141CB04B52AFULL, 0xDC3EC6E0D001E94FULL, 0xC3B1AEA32C4C892CULL, 
            0xE34D4C21293289BAULL, 0xC083F5205A4B2526ULL, 0x75B2D05BDE362B85ULL, 0x395FE2DC3A09F5BDULL, 
            0xB90420093D8A7AF9ULL, 0x2C34D3CBE918CCA4ULL, 0xD1FB4193D58CC0D3ULL, 0x2F24C7008B9D88AEULL, 
            0x7000CE8AF9C2102FULL, 0x2B529B9E2B952071ULL, 0x04B8646827C5B89BULL, 0x0705E0177F54D07AULL, 
            0xA3608273BC6D243AULL, 0x506EA1803A6B3973ULL, 0x293C86A418C163C7ULL, 0x29FC2E69D9EACFE7ULL, 
            0x08EB801830CA3F80ULL, 0xAF963BDD7C37A74FULL, 0x6C665FB76115371FULL, 0xAF8D96D13B2A9516ULL
        },
        {
            0x3853A9DE56F0F7B6ULL, 0x8EEA5839E8F9DACDULL, 0xBC0300729033E2F8ULL, 0x08CAC9438CF1A239ULL, 
            0xFA9BFF31B3037347ULL, 0xB21ECDB866946644ULL, 0x88BF286004E9709CULL, 0xAC0B57669CBD6129ULL, 
            0x383881F6B8B0459AULL, 0x15891DB747397F71ULL, 0xD9539FF5F218BF42ULL, 0x2489196AACE5B07FULL, 
            0x63CBCE979ADFD8C3ULL, 0x76A8CCCA2120C517ULL, 0xA8C4E29002F049A2ULL, 0xE1379D1226FBBC70ULL, 
            0xC33A9ED9CBA4526BULL, 0x9AF3A9097B1368A7ULL, 0x322D71746122FD31ULL, 0xA94035A06C4F595FULL, 
            0x9C91C5E1674503C3ULL, 0x4C4A63DED2556A07ULL, 0x88D15FC2C2ABC054ULL, 0xB6544CE4771F537EULL, 
            0xE074E41E5F5965D8ULL, 0x17E4D8846DB4B8AFULL, 0x946B187B6454B3B1ULL, 0xF316209CD23BE35CULL, 
            0xA19757771B95C840ULL, 0x07C4DF73A2C53C5EULL, 0x07E68658A9B01F08ULL, 0xC98AB5CC55149FE7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseHConstants = {
    0x776F2E65CAD90711ULL,
    0xC44701776FD38248ULL,
    0x7CD3A9AD5A6A7257ULL,
    0x776F2E65CAD90711ULL,
    0xC44701776FD38248ULL,
    0x7CD3A9AD5A6A7257ULL,
    0x2FFA7560B201C05EULL,
    0x2788C0315A806737ULL,
    0x35,
    0xEE,
    0xA2,
    0xE5,
    0x13,
    0xCF,
    0xAB,
    0x1C
};

