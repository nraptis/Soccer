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
    std::uint64_t aPrevious = 0xEB102D26B0FBE337ULL; std::uint64_t aIngress = 0xB829A8530DAEEC76ULL; std::uint64_t aCarry = 0xC50B0174A10FB35FULL;

    std::uint64_t aWandererA = 0xB46F150C6FD73E4FULL; std::uint64_t aWandererB = 0x844C049185BA5ABDULL; std::uint64_t aWandererC = 0x89B1173EFC76B92EULL; std::uint64_t aWandererD = 0xC95344511EBAE98DULL;
    std::uint64_t aWandererE = 0xC928591568BF2C30ULL; std::uint64_t aWandererF = 0xB5AA9AA90F71C23BULL; std::uint64_t aWandererG = 0xFD80CFB54EA8A1ABULL; std::uint64_t aWandererH = 0xFA3A2F34E427B1F1ULL;
    std::uint64_t aWandererI = 0x8B9D1D1CE1E2B0ECULL; std::uint64_t aWandererJ = 0xC231D9CB96B7F729ULL; std::uint64_t aWandererK = 0x989F2733F18DE21CULL;

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
        aPrevious = 9268984549761173109U;
        aCarry = 18289286998740775964U;
        aWandererA = 14020223272294314388U;
        aWandererB = 17074685828850717742U;
        aWandererC = 18377458338858945127U;
        aWandererD = 17141899996733393465U;
        aWandererE = 15423938638053457235U;
        aWandererF = 14092646817386971790U;
        aWandererG = 14382188373589040465U;
        aWandererH = 10935694337771160964U;
        aWandererI = 14495558772130360510U;
        aWandererJ = 18027569901860152789U;
        aWandererK = 11339442464505487840U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: work_a, work_b, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    //
    TwistExpander_Hockey_Arx::KDF_A_A(pWorkSpace,
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Hockey_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Hockey_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Hockey_Arx::KDF_A_D(pWorkSpace,
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
    std::uint64_t aPrevious = 0xCAF10C8D5FC1CBFDULL; std::uint64_t aIngress = 0x94E34945CA51C706ULL; std::uint64_t aCarry = 0xBBBA6A8FA9AD20E5ULL;

    std::uint64_t aWandererA = 0xA4407DC12A5AE12BULL; std::uint64_t aWandererB = 0xAF938C00568FFF6CULL; std::uint64_t aWandererC = 0xCDA6D96F036DF7DFULL; std::uint64_t aWandererD = 0xBC5C5C1C5A77F808ULL;
    std::uint64_t aWandererE = 0xDFF2FCA0BAAE66B6ULL; std::uint64_t aWandererF = 0xA77B404EB61B0BBBULL; std::uint64_t aWandererG = 0xA0380578597A51D5ULL; std::uint64_t aWandererH = 0xED5D270AEFD1AF92ULL;
    std::uint64_t aWandererI = 0xE0E3198A63AF5CEDULL; std::uint64_t aWandererJ = 0xB17470C0D98BF482ULL; std::uint64_t aWandererK = 0x8E1DAE9BE6F86D4FULL;

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
        aPrevious = 13073521399043221164U;
        aCarry = 17803775580005649569U;
        aWandererA = 17595780504224600791U;
        aWandererB = 14871908594837469081U;
        aWandererC = 17988323105664408248U;
        aWandererD = 16971610259820392539U;
        aWandererE = 17676752117034673445U;
        aWandererF = 11301823351338680689U;
        aWandererG = 15265671128699124009U;
        aWandererH = 12983996300391447729U;
        aWandererI = 15693086342672357729U;
        aWandererJ = 12586838568851270483U;
        aWandererK = 12189487020796504871U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Hockey_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Hockey_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Hockey_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Hockey_Arx::KDF_B_D(pWorkSpace,
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
    std::uint64_t aPrevious = 0x82991BF1559043E2ULL;
    std::uint64_t aIngress = 0xBB3FEB1E3CE9F84DULL;
    std::uint64_t aCarry = 0xCF8B8A39F352665EULL;

    std::uint64_t aWandererA = 0x86F3799924183DADULL;
    std::uint64_t aWandererB = 0x99102A2634FD833CULL;
    std::uint64_t aWandererC = 0xDDED5E9CAE84D294ULL;
    std::uint64_t aWandererD = 0xC0C8410EDFCB8F42ULL;
    std::uint64_t aWandererE = 0xA9C449C0E3E81FD6ULL;
    std::uint64_t aWandererF = 0x80F38C6F7B5CA282ULL;
    std::uint64_t aWandererG = 0xF05B9DE503354057ULL;
    std::uint64_t aWandererH = 0xDB53C84A216C5CAEULL;
    std::uint64_t aWandererI = 0xF41C88BF2899BE8EULL;
    std::uint64_t aWandererJ = 0xD63EF61B058E167EULL;
    std::uint64_t aWandererK = 0xF52F70C062E1780DULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA, 1);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD, 3);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB, 4);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA, 5);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
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
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD, 7);
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
    // temp storage: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Hockey_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Seed_B(pWorkSpace,
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
    // write to: invest_c, invest_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Hockey_Arx::Seed_C(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    //
    TwistExpander_Hockey_Arx::Seed_D(pWorkSpace,
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
    // write to: fire_a, fire_b, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Hockey_Arx::Seed_E(pWorkSpace,
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
    // temp storage: snow_a, snow_b, work_c, work_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_c, snow_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Hockey_Arx::Seed_F(pWorkSpace,
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
    // temp storage: invest_a, invest_b, invest_c, invest_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Hockey_Arx::Seed_G(pWorkSpace,
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

        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Hockey_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Hockey_Arx::GROW_B(pWorkSpace,
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Hockey::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEED531315A236360ULL; std::uint64_t aIngress = 0xCAF9F49E6864F3F1ULL; std::uint64_t aCarry = 0xB1858010F47E27F9ULL;

    std::uint64_t aWandererA = 0x97331EDEC79EAEB6ULL; std::uint64_t aWandererB = 0xEB5024AFFC33EF48ULL; std::uint64_t aWandererC = 0x8C65FDDBFE4DE704ULL; std::uint64_t aWandererD = 0xDA58FC80F6F8720BULL;
    std::uint64_t aWandererE = 0xE0D7091AC0CE8248ULL; std::uint64_t aWandererF = 0x86B7F86C398B4152ULL; std::uint64_t aWandererG = 0xB3FF7E5B5D7E59DCULL; std::uint64_t aWandererH = 0xA655CB5796F76A71ULL;
    std::uint64_t aWandererI = 0x874D88DEFA175BF6ULL; std::uint64_t aWandererJ = 0xE2556CFB8BAC92E8ULL; std::uint64_t aWandererK = 0x8A3402490EB34DD4ULL;

    // [seed]
    {
        aPrevious = 11619926430773818334U;
        aCarry = 14160428999533135990U;
        aWandererA = 16256850877972380146U;
        aWandererB = 17263773577296782509U;
        aWandererC = 17398850450756755667U;
        aWandererD = 16256585005564953480U;
        aWandererE = 15250575545106535646U;
        aWandererF = 12139861444280111390U;
        aWandererG = 16418903165148594561U;
        aWandererH = 14301733975722675675U;
        aWandererI = 17471544821194314227U;
        aWandererJ = 15531142766586074255U;
        aWandererK = 17458737325719440281U;
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
    TwistExpander_Hockey_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Hockey_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Hockey_Arx::GROW_B(pWorkSpace,
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
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 0, 3 with offsets 5039U, 2826U, 1322U, 5206U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5039U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2826U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1322U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5206U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 2, 0 with offsets 7649U, 7349U, 6299U, 4807U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7649U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7349U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6299U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4807U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 3, 1 with offsets 7875U, 5915U, 4730U, 6268U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7875U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5915U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4730U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6268U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 1, 2 with offsets 6737U, 1062U, 3094U, 5730U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6737U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1062U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3094U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5730U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 1, 0 with offsets 857U, 770U, 441U, 1839U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 857U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 770U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 441U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1839U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 3, 0, 1 with offsets 298U, 815U, 563U, 1632U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 298U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 815U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 563U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1632U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 0, 2, 1 with offsets 36U, 334U, 1028U, 906U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 36U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 334U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1028U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 906U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 0, 1, 3 with offsets 1028U, 582U, 2019U, 1066U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1028U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 582U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2019U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1066U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 848U, 490U, 1929U, 1498U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 848U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 490U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1929U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1498U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 2 with offsets 6666U, 1242U, 3097U, 7588U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6666U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1242U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3097U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7588U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 1 with offsets 7052U, 4306U, 3690U, 5219U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7052U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4306U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3690U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5219U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 0 with offsets 3718U, 1533U, 2687U, 3908U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3718U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1533U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2687U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3908U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 3 with offsets 3038U, 7680U, 1074U, 1628U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3038U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7680U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1074U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1628U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 2517U, 6234U, 869U, 7277U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2517U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6234U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 869U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 7277U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1670U, 434U, 889U, 34U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1670U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 434U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 889U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 34U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 112U, 1175U, 1258U, 1630U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 112U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1175U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1258U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1630U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1382U, 1278U, 312U, 21U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1382U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1278U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 312U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 21U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 986U, 1909U, 1793U, 648U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 986U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1909U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1793U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 648U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 2, 1 [0..<W_KEY]
        // offsets: 1923U, 288U, 1230U, 1541U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1923U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 288U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1230U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1541U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseASalts = {
    {
        {
            0x952F6A2B177BF338ULL, 0x36639D713A68A0B6ULL, 0x755D8C0AB10CC0A6ULL, 0xB07BAEA0561365ECULL, 
            0x992D562432A4A942ULL, 0xDFE8C61050A51DBEULL, 0x3912526A1A094683ULL, 0x1CA40CE7C4AB2360ULL, 
            0xD396458FA749E01AULL, 0x6F2BE2AE9A47D3CAULL, 0x7A76698D62ADAE94ULL, 0xA47B46084D3D627BULL, 
            0x6679626C7432F2A3ULL, 0x403B70B879C39177ULL, 0x9B00575672052EA8ULL, 0xF57A9EC961C25439ULL, 
            0xA5DD2F7BF488F348ULL, 0x0E05E74A3B200735ULL, 0x322B53A451CCB0BBULL, 0x8665B70122307601ULL, 
            0x3245789F6FB77440ULL, 0xE41845D879B5D58CULL, 0x8349139AA1D1DCFCULL, 0x6027B46CC3BB695CULL, 
            0x02D097AC206AA1CBULL, 0xBC3F7A2F359A1CCFULL, 0x376B651BE3DAF3D7ULL, 0x5F6FF83FF65A79C9ULL, 
            0x0C143DD9D36E5A53ULL, 0xAA9380CA98B7508EULL, 0x5053BF92E36FCF93ULL, 0x8333B9E4B9201F10ULL
        },
        {
            0x945D71D445A34CCEULL, 0x286DDE1076D6F590ULL, 0xF9D9F690FFA748F9ULL, 0x10468C04C126286CULL, 
            0x053C9160C3FC42B3ULL, 0x313ACE80C91A06E1ULL, 0x3A4330D9EAF17DC1ULL, 0xC8AD7274AC28D9BAULL, 
            0x313C16B56444E1F7ULL, 0x2D351F6A3597B35AULL, 0x8D6B8A8F74F82A2DULL, 0xB17EA97F8036A4A6ULL, 
            0x8EF62F8A5B0C258FULL, 0xBEAF55540D6ACD84ULL, 0xA1B2609C6B6FB51BULL, 0xE51B1011347AF72FULL, 
            0x2FC3A13EFF28648BULL, 0xD0D594166A4E1022ULL, 0x0CA967138C8BC414ULL, 0x1B6E81B20922B8CCULL, 
            0x084F0F1104F25851ULL, 0xD74B0E9513664F1BULL, 0x35452FFE51ED972AULL, 0xA0350EFF454C7D52ULL, 
            0x21BC3C1EF83CC7DEULL, 0x0FEEDA66F53F8209ULL, 0x521A55CBFACB766EULL, 0xFE6DA6B0721B56EBULL, 
            0xAA53729307347583ULL, 0x2B0AEFEE3F739302ULL, 0x5F27390D624D40EDULL, 0x696D5CD4C30E01A3ULL
        },
        {
            0x1B063CE00B125B64ULL, 0xA524532C77FEA2A6ULL, 0xC1CB53B52630A54AULL, 0xF822D1103EE16BDAULL, 
            0xF4A466DB459DE4F2ULL, 0xEDA31338C2ABEB79ULL, 0xC75B01D8CCD5BAD8ULL, 0x1D9FE2BF1CFCA361ULL, 
            0xA51A770847FEF060ULL, 0xCD258C8B5C3DC932ULL, 0x3A7D1E10C34CE314ULL, 0x69383BD9D08EA4D1ULL, 
            0x0150DC0E22402AF2ULL, 0xEB2CD448D09C9B21ULL, 0xC564B4AA194207E3ULL, 0x88EC683CCEB702DFULL, 
            0x1D4A360DA45E1DA1ULL, 0xFFADC4375CB04E70ULL, 0xC60C9CB50C8B8F0DULL, 0xBBE8E0128FB94AF9ULL, 
            0xCF6617864A57D40EULL, 0x6458F76A71212331ULL, 0xC4EF91B639B96375ULL, 0xDD41B2945CB7A12DULL, 
            0xA6BF55CEE5390310ULL, 0x107A3F32E9411CC7ULL, 0x6CB534046159AE53ULL, 0xEE5774FAEB612FB4ULL, 
            0x612A89D0C9D46BB7ULL, 0x27FA0247D6D2B0AAULL, 0xFF37B081F1E5117DULL, 0x0362D9C68366B23EULL
        },
        {
            0x70A90966AF79CC0AULL, 0x3EBBBDB04FF813CFULL, 0xCBCC25AA9185F3B3ULL, 0x187013F910E8F646ULL, 
            0x1429DAEC0D00F5B1ULL, 0x639C8A42DDA53106ULL, 0x1D7E0102BCC45823ULL, 0xEB1A34E8E8450E2DULL, 
            0x027C6C1F273FF5BAULL, 0x0AF71730A82AB697ULL, 0x61005A8AE8EB08B3ULL, 0x5C38A28753EF01D8ULL, 
            0x496A971D6A32FD1BULL, 0x7CC4A81BA92D4295ULL, 0xEFEB591699DF5B53ULL, 0x2A52306D19E4AC2DULL, 
            0x9A47F58F843D2FE1ULL, 0x207EE4B0611F9520ULL, 0xDF5635603379F2E4ULL, 0x6F7A098E7B2A0D12ULL, 
            0x8534174DB5790E9CULL, 0x02860E410206D455ULL, 0x88E427E1854F1833ULL, 0xB3A8916183677143ULL, 
            0xE2559D77FB009D4AULL, 0xDB2AF483652E9ACCULL, 0xC40EEFFE7D52631FULL, 0x166BFEBDFAA931B1ULL, 
            0x721247EBD6D1F479ULL, 0xCBFE9C4BE8E9FEC1ULL, 0xF3847FD7596DDA1DULL, 0x25044E8D5D761DFCULL
        },
        {
            0xD7A3A5E5D6641BE9ULL, 0x350A0E7EBE8B89D4ULL, 0xD72E63F2305BB33AULL, 0x80743CB7B441A060ULL, 
            0xF959A0A41B70E897ULL, 0x7D67B75A291B71DAULL, 0xFE6353CEC95DDF7FULL, 0x41BFEE92FA72610CULL, 
            0x9FB917319CF9D799ULL, 0x9CE13EA4D4326886ULL, 0x2FE35C989A102E0CULL, 0x93814185B45AFC29ULL, 
            0x0452723A6BDD5EAEULL, 0x64FD64B6776EA40AULL, 0x89A804727AE2C559ULL, 0x0FC7C8D5CECD9AEBULL, 
            0xF151693F7C074C66ULL, 0xF607FD99274639EEULL, 0x266C2DD7386136A2ULL, 0x5AEC2FAC6F0C8122ULL, 
            0x0C8330575817C5FBULL, 0x7496EEF586D40632ULL, 0x1AA785550A06DB81ULL, 0xAAA478424B9B1653ULL, 
            0xF32A96FF97CF8BC4ULL, 0x37C8B1EA45BE5D02ULL, 0x800E1AB5D8B45759ULL, 0xB3E2BD022ECF6949ULL, 
            0xA729186A5CFF65D2ULL, 0x0334967CAAA37894ULL, 0xD74E6EA46400BC4EULL, 0x31F0561573EEDD24ULL
        },
        {
            0xE740FEC588ECD1F6ULL, 0x5D8E795966BA2CDCULL, 0xF1D774FE23F8AFFEULL, 0x40AFA2AC9BD0E3FDULL, 
            0x2C0FB47B824009D8ULL, 0x8EB7EB284E3ECDA1ULL, 0x67FE939E97BE021DULL, 0x2DFA2946662DE8C7ULL, 
            0x66BFEF166973E504ULL, 0x6233010ADF016F66ULL, 0xEF7591BC74071264ULL, 0xDCF4107A804487B3ULL, 
            0xD6994F0C4222B7B4ULL, 0x07AF8059277C23E8ULL, 0xB6502A18036F4C0FULL, 0x482D78F8B0C6F208ULL, 
            0x2351632651E62E46ULL, 0xD201A18951437BEDULL, 0xCA5838CE6D482D50ULL, 0x32E745042E628ECCULL, 
            0x8BC415FA7F17F8BBULL, 0xA957681D3C39679AULL, 0x121292F7DC399930ULL, 0xF1C19475FFCBA90BULL, 
            0xD44B3A8013A4B5ADULL, 0x9D641B6FDA82DEAEULL, 0x9A440D4A4A4CB3A3ULL, 0x89ABA1395B396789ULL, 
            0xE79D44A3B085448BULL, 0xAC6CE3F0DE84605DULL, 0x8A17C1934357E6D9ULL, 0xC56A0A5175135443ULL
        }
    },
    {
        {
            0x796E1000A1637365ULL, 0x7D8133E15D9AF64DULL, 0x165B5DEB83B3FFDFULL, 0xEE4D14F9217227F3ULL, 
            0x80DD915B703265FBULL, 0x4166AA5BFFDCD28EULL, 0xD2F6B7369B62D340ULL, 0x48F85967C37A5B97ULL, 
            0xB64C6C1B81E8FED7ULL, 0x5F59220E845E5F43ULL, 0xB160223EC37687FFULL, 0x93C4287044E4446BULL, 
            0xCDE71D5C9A7BC7A6ULL, 0x9DF738A2D8934031ULL, 0x516A7ABE3A6794AFULL, 0x5D4948350924D0DDULL, 
            0xD9931B1145E68185ULL, 0x6E00FFB8E69DCFF1ULL, 0x6C1A01DDECD59922ULL, 0x5110E0DF4DB7CCB5ULL, 
            0xE5EE57B7E576B2CDULL, 0xD0CB8D2B14920BBEULL, 0xE136E16C7B82EAF8ULL, 0xF356FA23353B27C0ULL, 
            0xF3848DA03BBE8A16ULL, 0x6D14C39E61B812F5ULL, 0xCBCB62C9DA58C002ULL, 0xE11A13C9A19244DDULL, 
            0x0066119F8781CABDULL, 0x02F4509AC5888D48ULL, 0x9A806D7E9A9EB153ULL, 0xDA6F9740C8D98C97ULL
        },
        {
            0x44EAA5F03D2F0D8FULL, 0xB782BE543221DA66ULL, 0x4C5FF50122E6DEEAULL, 0xC065CD11A54EC644ULL, 
            0x705C5E88900FA3FFULL, 0x7E5928C012DADDA9ULL, 0xF8E217E7F1E04975ULL, 0xBC712B230BF680AAULL, 
            0x7A82DFA2EB7B4BB8ULL, 0x70DA8A07D6DE7B05ULL, 0xD1AE9BBA819F0B54ULL, 0x3864EC6251B54475ULL, 
            0xBAB3B003BF0A17AFULL, 0xF1DDF8EB7F47A057ULL, 0xC70DE28E3156DB35ULL, 0xB11DCBA7AD3E38C9ULL, 
            0x6C44FD15C841D9EBULL, 0xC8AA38F622B9108DULL, 0x7DB4E1784B0C795EULL, 0x08A949E6BFD31AD5ULL, 
            0xEF228D7D8D0EB290ULL, 0x0078AC3EABA4C808ULL, 0xE5920696230330C8ULL, 0xA5E757180B5AB103ULL, 
            0x18B110746B01DEE3ULL, 0x2DD206B049FB37DDULL, 0xEDF69211005E888AULL, 0xA60E172CE21FBA9BULL, 
            0xF962F34F48991170ULL, 0x730FD0934C1BF60EULL, 0x8AB96CC4E0ABE538ULL, 0x3144C539DA834B46ULL
        },
        {
            0xC996B98D5680826EULL, 0xD9C920E284A98882ULL, 0xCB49A89A5D82D44DULL, 0xB4FD8CF988BCD770ULL, 
            0xF7D33A5471BF9784ULL, 0x2145D5946C2EB390ULL, 0x96130E43AAB01CB3ULL, 0x76DDAFFA15C2EEB0ULL, 
            0xCA09B43789F445EFULL, 0x93C32A512C713D36ULL, 0x0174E8F9F3EB4DCDULL, 0xB51718095E9976CBULL, 
            0x79AE5E3617E30313ULL, 0xCC9A74B26D4A851DULL, 0xFCB12DA5EAE2F8A9ULL, 0x3F380F1F7DB07EC2ULL, 
            0xAE80E8551EACB95AULL, 0x35B4697EF6583484ULL, 0xEF62FA841A082FE1ULL, 0xFA6F19A78AF2F827ULL, 
            0xB4E54C506AC64E42ULL, 0x82E9A923335BB1FEULL, 0xD66AB6D8B2F9DB23ULL, 0xB2035991D8F75E57ULL, 
            0xB6F78C5114650453ULL, 0x1F696188A6F52CEFULL, 0x9C0E141472907D93ULL, 0xA636714BFD3177B6ULL, 
            0x3C36DFAD4CF30DECULL, 0xFAE819FB277D35B0ULL, 0x01BA2E2D291E6500ULL, 0xC1BFD2BF785F6D48ULL
        },
        {
            0xD93562CF64AEB716ULL, 0x281A66FD3DF65B21ULL, 0x2E64D68D83835A04ULL, 0xC2C6262742097CC0ULL, 
            0x8643D2CAAFE036C7ULL, 0x9D5417740253B8C3ULL, 0x32F03141AFD38AE3ULL, 0x0F78C819F978D02DULL, 
            0xEA955399CB1F6B2EULL, 0xC66DDC931223E30DULL, 0x21108B598DEDB091ULL, 0x6BB12810D681280CULL, 
            0x2E597153C6E352F9ULL, 0x2F2E567490768892ULL, 0x1C0F5CE3A56EB2F9ULL, 0xC15A30BB4FBDE073ULL, 
            0xAE8C43F37092D8E5ULL, 0xFEDA65C9E188BCBAULL, 0x4493ABE2E683A130ULL, 0x5F1C4E4370DC21D7ULL, 
            0xA0E9261C3E006ABBULL, 0x07837134860D59E3ULL, 0x8BD345ABCC75EEEFULL, 0x324DF15E4B7F1425ULL, 
            0xDA1EA2D1BA3628EBULL, 0x6979398BAD015EB6ULL, 0x0860E1BF89844B42ULL, 0x78064766BA977485ULL, 
            0x66629D5DCA5ECFEEULL, 0x1572808E9C2686EAULL, 0x7E2A19772DCCFBE0ULL, 0xF5094364DBA8DC82ULL
        },
        {
            0x204CE46BE70FE654ULL, 0xA1FBF29DDD4AFD4BULL, 0xE507E14A3CD5ADC0ULL, 0xC97AE165A425A847ULL, 
            0x631613970E5E260BULL, 0xB207A7ECB61BC1B4ULL, 0xCDC652ACC4D05295ULL, 0xD817906BB5320F2FULL, 
            0x3F1E8B7BE86F4208ULL, 0x987EF2F368317252ULL, 0x027840A7EB3F683BULL, 0x7E40CA084636C91BULL, 
            0xAC2F792549DB0963ULL, 0x84FF5EE664BE12A0ULL, 0x6D956EC6359A56DDULL, 0x3C8A274CCAB018ABULL, 
            0x17D6040A8EBD7AF7ULL, 0x7B5B576BC65BB1D3ULL, 0x67A82768E4A2D0F8ULL, 0x71E319AA2586A82AULL, 
            0xF0614557469B211EULL, 0x33F351833F54C88FULL, 0x9B29EB104AAA8089ULL, 0xB83CD3CF6C8CF457ULL, 
            0x9B72EE8828DAE39AULL, 0x65A369BC11957548ULL, 0x88B8786006B6DC93ULL, 0xE170F2B07A069309ULL, 
            0xD5DB2097B95BF1A1ULL, 0xC084D382D4C6C9BFULL, 0xCDB0506B49D7935AULL, 0x4FD1E433D202FC72ULL
        },
        {
            0x63111440E76B1EC2ULL, 0xE957D09F116B939BULL, 0x359EEC985643D40BULL, 0x6EA76B0818FAB762ULL, 
            0x46876C451C4BCDDBULL, 0x4CE3B9833341EE7AULL, 0xF823E3BD9F18A6C8ULL, 0x90380CE5BCEE9CD4ULL, 
            0x4E98ECF217CDA369ULL, 0xD562F67FAB92C96FULL, 0xD8741F9FC154130EULL, 0x1579CC3BB89CC0B8ULL, 
            0xFE67C7198B37D807ULL, 0x1E3987C295433BC1ULL, 0xEC6A1FFE25575478ULL, 0x084A127FFB04AA4AULL, 
            0xE1F9105591261D77ULL, 0x5E521246BC18F3F3ULL, 0xA7D0693E586654E9ULL, 0xC32321EB3D9A0123ULL, 
            0x89FF9F3E6EB8A46AULL, 0xF68E4E3BF9281276ULL, 0xC35112FBEDD6B06BULL, 0xF1459999A71E4B84ULL, 
            0x4EA2F1261FA0D557ULL, 0x9E643EC2C32A9F47ULL, 0x32E01A49B95FACA4ULL, 0x907215D8AF646304ULL, 
            0x75A5602CF480BB7BULL, 0xAD14E14B72CE65EDULL, 0x4FC1F41A170121F8ULL, 0xA211EAC978F7BD1BULL
        }
    },
    {
        {
            0xA1F80B19748001ADULL, 0x827926B6FDC232DBULL, 0x12D8D08B2C8E352EULL, 0xE8351A7DFCE7B2BAULL, 
            0x50A69565816EADA0ULL, 0xE5704D371DDA7A8DULL, 0xEF16A73941A126AEULL, 0x6DBD2109C2163AA4ULL, 
            0x7870EBDB7286B9E2ULL, 0x3922A035A58378D6ULL, 0x765EBBEB98CF6C2AULL, 0xAA1B5A6BDAEEA294ULL, 
            0x594C8CB8ADC5457CULL, 0x182931598645E685ULL, 0xDD1961F4A926F63DULL, 0xF4734D2B57840749ULL, 
            0xE68CF389A8CCB30DULL, 0x7FA707669B31900FULL, 0x4DB307633BC61B0EULL, 0x2A0DCD78A0170C47ULL, 
            0x3AD30A7F5AAF71D7ULL, 0x135B0F4374A2424FULL, 0x090212FC3945ABFEULL, 0x7FD1F3A019BEA660ULL, 
            0x1F85EB10201D5C98ULL, 0x522E09A341A179C9ULL, 0x9B19A453E7B773D6ULL, 0x4D6F53E0C1647171ULL, 
            0xC513745C75F871C8ULL, 0x836AAED60E550861ULL, 0xD9CA81016431E328ULL, 0xBF2A1555A7C7C75BULL
        },
        {
            0xC6643B4E10CD3EDAULL, 0xD9E9098C3A5CEE13ULL, 0xEE12F6F021E47D6DULL, 0xB6F5EE4EF582B111ULL, 
            0x5CEEA6FEDAEF08E1ULL, 0xB05A9E2848999C7FULL, 0x5490E28CE5DAF8C4ULL, 0x0E592A8FAFD50925ULL, 
            0x6E9182BD9E311432ULL, 0xA3886BF9AA30C2EEULL, 0xEA2C749AF64D8492ULL, 0xE6B073349B2D8EE7ULL, 
            0x3BF5D05CF282D72EULL, 0x963F606C68AF75E2ULL, 0xF9F4532C9BFA44E9ULL, 0xA97E6250942EE1A9ULL, 
            0x1ED07949E264ADB0ULL, 0x69D299719ECF3C85ULL, 0x08DB259D4A720286ULL, 0x5BCA6AFDF5A9A0D2ULL, 
            0xDF62270062555AC1ULL, 0xBF64A874A62272A3ULL, 0xC11C270FF5B2B4A9ULL, 0x578F686E996C1973ULL, 
            0xE38169A1691D282BULL, 0x93D058CC53D8490FULL, 0x8E62D7A65AF73FA1ULL, 0x4A09D9B08CDA1CB1ULL, 
            0xD5A84F34B3C2F546ULL, 0xF8787791BCCEFE53ULL, 0x264FB9E5505191E5ULL, 0x05534176B4A17FB4ULL
        },
        {
            0x95A0A9CAE5EB1ADBULL, 0x1C1C3CF3A5D4964EULL, 0x743D67A19823B0DEULL, 0x971C608AB4752BDDULL, 
            0x25A15602EC738156ULL, 0xED42C3FD4FFF2FBEULL, 0xD361BF5384309ECAULL, 0xCBE80A7206486568ULL, 
            0x4423721A860684C8ULL, 0xDE6045939B3835A3ULL, 0xD16DB7C3436BA3F1ULL, 0xD21D663E8B025713ULL, 
            0x75AA712E9501EC5FULL, 0x9B00757E7FACA9D8ULL, 0x1D93D2304B71B9ACULL, 0xFBBDDA1FA1944D6AULL, 
            0x0A14900A21E6B469ULL, 0xE88830D209D5066FULL, 0x0A9EDF9C86FC490EULL, 0x80EDF9B0903AA565ULL, 
            0xA68D69D6D00C6A44ULL, 0xBE48FB38FEA45F57ULL, 0xB4E5E90CF1324314ULL, 0x06F7B53A3EADC0D7ULL, 
            0x103CA08D4EEF556FULL, 0x46F316D799364487ULL, 0x33C1C3E9D3CC663BULL, 0xBF04B58C2A505278ULL, 
            0xD179607C5C9116B9ULL, 0x764F96AFC73F5E18ULL, 0x94A689B9FD3D79F3ULL, 0x34647E1ABB859965ULL
        },
        {
            0x46CEA99B5A9C24BBULL, 0x108CF8B529970EA1ULL, 0x7A8F681882A4A708ULL, 0x64C1E2A8CAE39B28ULL, 
            0xD89C74F42893D13DULL, 0x5E663A240BD1E111ULL, 0x530542ADAAF27079ULL, 0xCF51D0468EA42DE7ULL, 
            0x9449AB62B24011E7ULL, 0x88E73A1BAEEB94CAULL, 0x6D395F739C289CD9ULL, 0x928745C94237927CULL, 
            0x0803B4D265F8AEFDULL, 0x0C4D475071D08DB3ULL, 0xE065E180E5C23C60ULL, 0xEA0EE1DE77C78314ULL, 
            0x88BC559FF91EC484ULL, 0xB64B59BF075A2675ULL, 0xE66FB55F52A53E20ULL, 0xB2C4BE7189E6D0ADULL, 
            0x3B7EF7322D4CE696ULL, 0xA1CF23F951956573ULL, 0xC21D2523C9FC22B3ULL, 0x7FBE813E8D5C0FC9ULL, 
            0xA59416AA236BC21FULL, 0x81DF9F158DBB3607ULL, 0x9C54CB3D8EDD6469ULL, 0x339840C9E4726306ULL, 
            0x27D37A79EA034E10ULL, 0xC5F91E0AA5F47CBDULL, 0xB4841F8658CDB9ADULL, 0x5A8BF43ED92BDF95ULL
        },
        {
            0xE72F80A10B0CFA8EULL, 0xF259E4D09DFCCE80ULL, 0xEFE1BD296B91A22CULL, 0x7CC7E16D87EA2A24ULL, 
            0x6BA288578E585B03ULL, 0xC258627892666C62ULL, 0xE278B302B797158EULL, 0x1F4C59DD5C6067C0ULL, 
            0x5A69AD13F6B98F8FULL, 0xE7B1FD9F980C2E7DULL, 0xCBF2AE00EC2EFAAEULL, 0x7224DF25D35E0725ULL, 
            0x80B2FA7B7F4F3A1AULL, 0x7ADA78E0977B93B9ULL, 0xC5943133F3E7C166ULL, 0x848DEDC5B770E3E9ULL, 
            0xB1BB7C78C874551BULL, 0xDF2508058429021CULL, 0x528445B318F55C3FULL, 0xDE2B202272ABEF7FULL, 
            0x4BAAB03BC9047299ULL, 0x9502EE9D2A393B1DULL, 0xBEDEA5640BBE34ABULL, 0x6EBF8124CD14F8E5ULL, 
            0xD76483F76F8900C4ULL, 0xA5E2B3E3631832C2ULL, 0x5428B9D8EFFD8ACBULL, 0x4B282A1A00CCDB55ULL, 
            0x829286E94766366DULL, 0x028671B1A5014CF1ULL, 0xB4EBE42C543D25D0ULL, 0xA49AA7703F856801ULL
        },
        {
            0xFB75B44437D9DD33ULL, 0x7EB487D7FC25CDD4ULL, 0x5832C126BA2C01EAULL, 0x608573E4DF267176ULL, 
            0xD3F54AFC46C20C10ULL, 0xF643380927D06A60ULL, 0x9DFDAD9DB2CE5932ULL, 0x5AC73B9CAC74154FULL, 
            0xE60D0860A44E800DULL, 0xF01DFBE2ECF0953CULL, 0xD0C5F952354C1676ULL, 0xAC14246C3D168413ULL, 
            0x4A31043C33C822B6ULL, 0xCD00C02BDB8E16D8ULL, 0xED3EBC0E65BC92EBULL, 0x7C5CF644090661FCULL, 
            0x44C2B6298EBC11ECULL, 0xC9CB1B3B8A74DEBAULL, 0xACF9A85E8AC55D55ULL, 0x67BB99E3902339BFULL, 
            0x20AFE808A29FE5E2ULL, 0x130DE365A506101AULL, 0x5B6BFF810F140E29ULL, 0x2501B7EDC992F966ULL, 
            0xF9649F4345A4F131ULL, 0xA6652CB748A88965ULL, 0x649B04F5B66D53C9ULL, 0xFACEB57436F86177ULL, 
            0xC433F135A888334FULL, 0x2EBFFCBE6C6C661AULL, 0xDE125702860B2BEFULL, 0xE66712BC0330E740ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseAConstants = {
    0x1BAC0EE689B7521AULL,
    0x0C0162EBB4BC1023ULL,
    0xB79BCF0B7AD46346ULL,
    0x1BAC0EE689B7521AULL,
    0x0C0162EBB4BC1023ULL,
    0xB79BCF0B7AD46346ULL,
    0x1631EB73F8241589ULL,
    0x3E209247EB0F52D0ULL,
    0xF6,
    0x43,
    0xCF,
    0xCE,
    0x1E,
    0xBA,
    0xD2,
    0x4E
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseBSalts = {
    {
        {
            0xC90D7866BACB87BCULL, 0x0989F64FC8CED7F2ULL, 0x1C4B06480E98F668ULL, 0x2737B0DDA94268E9ULL, 
            0xFF325E5A77A1C94BULL, 0x70D645D926877B64ULL, 0xD841E249B21C89DCULL, 0xB0ACFA696B86B55FULL, 
            0x6BA508B8A1B8F574ULL, 0x60AF5D660F97C1AAULL, 0x8532AE781C1DD059ULL, 0xD004CB41ADA465C8ULL, 
            0xBEECC141203347F8ULL, 0xC0FF64A3CE16CFEFULL, 0x8881DE1747E315BAULL, 0x4DA283A470AE7239ULL, 
            0x6DA3832671A917F6ULL, 0xFC5BE12CFC3DFA32ULL, 0x4F3606AED4DCA501ULL, 0xB32DCC4349555526ULL, 
            0xBB9BD83DA59D6AF2ULL, 0x769A9A6784B137C1ULL, 0xB6C456341DD256F5ULL, 0x1966BD22C084245BULL, 
            0x071665CBBC3B9958ULL, 0x6C49C47B70A95053ULL, 0xBF81CF77A307B173ULL, 0x9499D81C6B767DF1ULL, 
            0x22FEBE3D59450731ULL, 0x7565B3754B45A0A1ULL, 0x2DA7380A514548E0ULL, 0x0CB36F9D01DCDCC2ULL
        },
        {
            0xED814A5F8246126DULL, 0xAB27205AB712A9EAULL, 0xEA5E9F915F2EBEB4ULL, 0x662856B25DD991BFULL, 
            0x1E38CC59CCDB617DULL, 0x698CAF52494802B8ULL, 0xF0B1360D2C44EA1DULL, 0x58F1B729B55F9386ULL, 
            0x308A7596EB83BC10ULL, 0xB93C640232F4A673ULL, 0x6013B9AD740C0B81ULL, 0xECB73B6803DC03AEULL, 
            0xD41C7A8D177E3D8FULL, 0xF0395E5281CCE087ULL, 0x4476E12D2480755DULL, 0xFDCAD2D574506CE9ULL, 
            0x87C5D90819E77701ULL, 0x33A3D3AB314FDD01ULL, 0xC79C42DBBF056730ULL, 0x26DFE416FAACEE15ULL, 
            0x62D3C70F82B387D8ULL, 0xBFBFB9A2011C6250ULL, 0x93ED38A0E40BCD2AULL, 0x863B6FD58BDF6FFCULL, 
            0xE93B4AF11278CCDFULL, 0x95B243D7962E1BCEULL, 0xAA19E41CB6C9E775ULL, 0x0D097DF7A2CDA843ULL, 
            0xCB34B28F368BB397ULL, 0xDB5E0DCBAE26B5C6ULL, 0xCE187A9180C8A992ULL, 0xAA4259C6CF0DE372ULL
        },
        {
            0xE7F5E6AECA7D8E37ULL, 0xBA90F3556767A811ULL, 0xF2F3B665127CCBF1ULL, 0x10A64EA61F66A6C7ULL, 
            0x3546B40AF504ACE5ULL, 0x4B40487616259FD8ULL, 0xD5ACE6F476E625BBULL, 0x1FFA55B79C247CE3ULL, 
            0x57E94349C84C0AF2ULL, 0x8219483D9E687C1AULL, 0x66C8882017DDF38AULL, 0x0846B4EBB32DFA32ULL, 
            0x21F506CB198E8B5EULL, 0x1E3911768C0FC9D1ULL, 0x2464156205F1D1EEULL, 0xC8A50233D9430689ULL, 
            0x28804EB0B5F103E1ULL, 0x5FF7EA603A07060FULL, 0x2EEE19313818E7CFULL, 0xDFF7637A0D49E497ULL, 
            0x2E116AC468A0D0B4ULL, 0xDB963F2DCF6C8FC0ULL, 0xE0D1607982F75E1DULL, 0x38C3A879CEF3E7E9ULL, 
            0xA1A3CD654ECD2945ULL, 0xC0268262A16BF955ULL, 0xE7CC254F00043A81ULL, 0xC70C0A1E6C419E60ULL, 
            0xE09133A0FFDE0F7AULL, 0xFD09FB1E9CF7003CULL, 0x113D63A9A9EC124EULL, 0x30AB817DD2B21B90ULL
        },
        {
            0xA7A30A2E62E93C8DULL, 0x87091356F21B6CDDULL, 0xFD002A9AD4AEEE7FULL, 0x040E151AF042291AULL, 
            0xB8305A5CE90B1049ULL, 0xD81627514EAA2C8AULL, 0x14C9890B83C7633DULL, 0x39C0B569C6ACB2E1ULL, 
            0x54BF9D7C16F46DD6ULL, 0x955EAE788A7B8524ULL, 0xF12F0A9C05D256EBULL, 0x0B2C01128B1838DCULL, 
            0xAF5329787271A2D3ULL, 0xEF57319F6B214457ULL, 0xB93CA9402B1B849EULL, 0xFA69B469B554B872ULL, 
            0x8FCCFAE46E1E3E88ULL, 0xA1CA6163670861A9ULL, 0xE6E6562D5BB68A96ULL, 0xDB025A46CF6B6C58ULL, 
            0x770A083F6ABB158EULL, 0x3C180A4F9AFDCFDAULL, 0xFA73C40648EE3DFCULL, 0x55C49DAA5993205DULL, 
            0x9A763284717D37A4ULL, 0xA3536F9BD29A2A07ULL, 0x7CC02FAFBFFEB3E4ULL, 0x4833917518E22DD9ULL, 
            0xFB9081C8FBAE58C5ULL, 0xCCF4ACDD91B437A8ULL, 0xD59B7D34078A9389ULL, 0xAAF4822E17A48816ULL
        },
        {
            0x258B0ADBDC1AFF1DULL, 0x3F7A8094B41BADB3ULL, 0x7275CC5EF278C5B3ULL, 0x2995CAC0F29C7D72ULL, 
            0x589BAA4DEB3DC929ULL, 0x96A6DD91DA79A8C7ULL, 0xAE5634496F7031EEULL, 0x7DA9470C7B1A638BULL, 
            0xEE665DBEADF50DEBULL, 0x8F81A7B68C4D6BA8ULL, 0xB8011E6429FFAD8FULL, 0xA96DC4D83B35673CULL, 
            0xC68FB24EF0EA2EA6ULL, 0xE1E2A63F77640E38ULL, 0xAAE7E7385A5E6F44ULL, 0x0B0628D1EC4D8594ULL, 
            0x1DD3DD252E1A0344ULL, 0x0CDEA109647F5F53ULL, 0xB1B8C6D2F27515DFULL, 0xEDF77D85DB2DA1F3ULL, 
            0x9E14022E3F73CF68ULL, 0x0924534D69611E7EULL, 0x21D1228DEF4CF5C7ULL, 0x8DCA7C2547E9E6F4ULL, 
            0x8A0E4AE1F066A096ULL, 0x6A966EF1A2EC68B1ULL, 0x8B3A170DC82F5EB3ULL, 0x9841E78F612F52D8ULL, 
            0x3962BF232F798A08ULL, 0x1D494C6AAC4D3BB7ULL, 0x73E4E0FAC7A8862FULL, 0x0370C0000A23CC53ULL
        },
        {
            0x57174AAF18C51D15ULL, 0xA59FF4FA0C30AAFBULL, 0x9E7BB55F3032BE97ULL, 0xC7D902A9C0481582ULL, 
            0xF12F01A63733EE3CULL, 0x269F975AEA133C60ULL, 0x4C9DC4127FCF2AE7ULL, 0x768F641F8403B832ULL, 
            0xBAD7A5E54254F9D4ULL, 0x001C7F89216A459AULL, 0xF699B278C22E6C9FULL, 0x00313E5462625B9AULL, 
            0x9EF8DA278CE359B1ULL, 0xA66E26A07A5BB119ULL, 0x556BF5A94BB2F433ULL, 0x8FDD06F1E9E62945ULL, 
            0xF48DA3C996FDCBE6ULL, 0x55B3B115C8C34E9CULL, 0x7AE5189E3EBED55FULL, 0xE9F27728A2BBE075ULL, 
            0x9D2816A40F8ECD04ULL, 0xE4CEBD4E4618F38DULL, 0xEA39CD6EDBD94EBCULL, 0x0D484FF75AF67F82ULL, 
            0xCDA1FAECC110245BULL, 0x2108DE4A975266F5ULL, 0x49282BF1F4022FD5ULL, 0xE2A22C22DAD44A66ULL, 
            0xD995B60A3997F842ULL, 0xC2436DE947810842ULL, 0x47D6F2963164D1BEULL, 0x47D770A97816B4E1ULL
        }
    },
    {
        {
            0x3F7B1FC2462C904AULL, 0xA48EA741AAA08DCEULL, 0x9A079781B5B403EDULL, 0xDF19BCEF5E20CDF1ULL, 
            0xC7A470666C141A77ULL, 0x6CE9663448D5E8C4ULL, 0xFB0884B02DFF7C18ULL, 0x28D19B4132180852ULL, 
            0xF05E78487C3405FBULL, 0xB8A2C9871EE87D01ULL, 0xF0B909FAF83AC0A6ULL, 0x9FE8FE5A23A147DDULL, 
            0x293C4948AB520CB5ULL, 0x626D5C6A63787989ULL, 0x083F1F4453F106A2ULL, 0xD3B7C4C2240AA76EULL, 
            0x35CF39E62341B81FULL, 0x421CE41E2F8C19DFULL, 0x3666B602E1A1BD67ULL, 0x4DCA033E7809BC2EULL, 
            0x55A707423ADC6DCBULL, 0xBBED35FDC8EABF01ULL, 0xF0BC127EF9DDECDEULL, 0xA7B60EE15017EBBBULL, 
            0xBA2D7BB43B25C41BULL, 0xBD0E9F2F4E96B347ULL, 0x83C936391449ACC4ULL, 0x29CB3F48712CC3BBULL, 
            0xC818C4B0F5BDFF29ULL, 0x661C51DE4536F6FDULL, 0x0551A7EE70D7EFDBULL, 0x3846AF73DC8BC8EDULL
        },
        {
            0x27CCEE450A244395ULL, 0xFAB2437BF6CEF285ULL, 0x052AB50C170C1179ULL, 0x17A411DECB88A677ULL, 
            0x46A8A60F1B70BECBULL, 0xCB599ADFFDAD0311ULL, 0xCD0734CEBCE00ACBULL, 0x9354C57B80C32D10ULL, 
            0x94D0216491B7F2BAULL, 0x3618EC5BE0491987ULL, 0x427C9EBED80FB2E4ULL, 0x58739EFD49F164E4ULL, 
            0x32106BA28C9BDA0CULL, 0x52A921C2D59A6985ULL, 0x90D2A97075CCB832ULL, 0x97F7A9C5A9CA6315ULL, 
            0x013320683FB32F65ULL, 0x66B00FD180F08A30ULL, 0x12B87AA590F42887ULL, 0xA7BCFE0CD31BFF00ULL, 
            0xE2412B7EA60FC737ULL, 0x576F798956D06AEEULL, 0x125B4B3F2E58B2F1ULL, 0xEABC8869FE370266ULL, 
            0x551BF9926E36976CULL, 0xF64A0319C69E63A8ULL, 0xB92B00133D64453BULL, 0x01CD531C7EE5DE68ULL, 
            0xC7604AE59E1E0D1DULL, 0xB73A0CE5BD9C9572ULL, 0x91CBE6A937FC87F1ULL, 0x1CAD6708166FFEE2ULL
        },
        {
            0x5F982DE74FDD9810ULL, 0xEC3F860C2788EEACULL, 0xA097E33458C89CEFULL, 0x2D9D60EE0D67ECB0ULL, 
            0x7ABEB369FD7758DFULL, 0x7794F95AB29538CDULL, 0x2D7341CE6D016D03ULL, 0xCB18074C57B80DFAULL, 
            0x14EA13308604FB15ULL, 0x814EA8AAB1061E1EULL, 0xBF1B0C61D2FDAB69ULL, 0x3DD4A778FC25D645ULL, 
            0x4BA4EBD1CF836A88ULL, 0x89692B6A82A5EF18ULL, 0x26A0E3C858A0D997ULL, 0x4D63AA84E63F0E7AULL, 
            0x178915FC33296C1BULL, 0xA73B5B894B0C3887ULL, 0x221B24930F546228ULL, 0x4702797D25B3E4D2ULL, 
            0x4E589FF1D0B8461EULL, 0x6C848CBA2C90F289ULL, 0x82A26E0F0BDDC4B1ULL, 0x9799485E25B7EF11ULL, 
            0x34F7BDFF1F8462B7ULL, 0x92F203FD26023F80ULL, 0x8B2A2DF55FE61742ULL, 0x2ABB4342C2C03548ULL, 
            0x371BF36A549C2F3CULL, 0x4EC890F3E0789368ULL, 0x26EC931F7BE905B1ULL, 0x4F908722E11B1E82ULL
        },
        {
            0xE6480E64ECB00776ULL, 0x5CEC69C09A187DA3ULL, 0xD56222EDEA7F00F4ULL, 0xF002A19872410003ULL, 
            0xBCF740FED3E8C9ACULL, 0x0BD48019969BE93DULL, 0x50A4C978DEA3B592ULL, 0x4ECBA6D195BAB933ULL, 
            0x7A4A0841E8F9C8ADULL, 0x39BDE64CEFBDF925ULL, 0x49A50D20ECF82FB0ULL, 0x8E547927404B4518ULL, 
            0xF5A3A0C784AFC353ULL, 0x6119C066A509DAB6ULL, 0x9305586B2FA6DCEEULL, 0x9F3BBD247851F495ULL, 
            0x4CE8F8DE7939A3DCULL, 0xCDB3EBC59806D689ULL, 0x5623FCA81137FEECULL, 0x4772305338B5ECAEULL, 
            0xA4EB2F49F9AA978BULL, 0xA9700A2468A3B9B2ULL, 0x2099033A6A255370ULL, 0x3152DAACB18C4FBCULL, 
            0x250DF944C28CC49CULL, 0x597B419948013081ULL, 0x9A7542C257F55A79ULL, 0x3D91732691CCE1E6ULL, 
            0x667FA7E60B197EA3ULL, 0x3F73217DE734E1E3ULL, 0x2926EE31B771D700ULL, 0x341C2D7E682814C4ULL
        },
        {
            0xCF903DAEB81F4642ULL, 0x453BF4C190B60821ULL, 0x795E985432FD0C0CULL, 0xB3B0A35C5F88FC3CULL, 
            0x07A2E9BE3E43EC35ULL, 0x8474DB5914BCC470ULL, 0xADC36CC3E1ECAD02ULL, 0x6132599E0EF77F5EULL, 
            0xC9873D54626DE793ULL, 0x3E7BF35AC1E566C9ULL, 0x483DED239B38FA1BULL, 0xD1E875176535CFFCULL, 
            0xB61F4C4A51351DD4ULL, 0xAA307885EA571CAEULL, 0xC1C94E6A1B3B141DULL, 0x30069580645AAE1FULL, 
            0x92FB19277A438591ULL, 0x852C12D36345C3F2ULL, 0x036A9C61B425174BULL, 0xA5AD2B6E4149998BULL, 
            0x20DCAC3229141EDDULL, 0x1F18C20D583D1369ULL, 0xD0CD292BC85F8CFDULL, 0x584A864E2E599B45ULL, 
            0x6EE4EB40F7F83E37ULL, 0x0BA1F393EE74C231ULL, 0x452A8F84E312035FULL, 0x3D5D1276DB59AA06ULL, 
            0xB950A3AE661284B8ULL, 0xBCE3501E1BDD5883ULL, 0xE51CF3D7CBEA2ACEULL, 0x88F02B4621BCF01AULL
        },
        {
            0x0946AE5F90AF009CULL, 0x716E8A7DE8F679A6ULL, 0x9611F64B408F84E6ULL, 0xFF059317A9A91229ULL, 
            0x64715159228C239BULL, 0x3FBBB5876DFF7C74ULL, 0x1D18C25B17ED509EULL, 0xC0AF4F41977E4EC0ULL, 
            0xBA70CBFA4A9EF517ULL, 0x3AF1A68DBCA9777EULL, 0x8D2D315DFA9AE6AEULL, 0x1357C5B17E673170ULL, 
            0x3113521015A64302ULL, 0xBEB96F563ADF72EFULL, 0x99AFEC76EA153D15ULL, 0x6695E1352676FD88ULL, 
            0x564EFB5279B011C4ULL, 0x541B7A7B75221ED6ULL, 0xBACCFE828C8B0544ULL, 0x6D6EC0AF14CFEFEDULL, 
            0x8FFA397978AFC789ULL, 0x0405F5A723FC2ABCULL, 0xD2C8489553B1220FULL, 0xCD47E3AB3AB0195AULL, 
            0x4D523940FDBBC6B6ULL, 0x4DF62D408DC8ABEEULL, 0xE449C35DA577E542ULL, 0x3BA83B052B37B06DULL, 
            0x5B658BFE49ED2400ULL, 0xFFEC84D776D7E091ULL, 0xE067EA2F65F7D65AULL, 0x3F05D0B8378B1C71ULL
        }
    },
    {
        {
            0xF6F6655FED28A613ULL, 0x87735AC1C97B1C58ULL, 0xA2F16B1050F4BDF0ULL, 0x5A7491C7A9B7FA8FULL, 
            0xA6E1DB0D3E1A0948ULL, 0x3B427CD473EE4FF0ULL, 0x6517F3C201A09CCAULL, 0xA7E6A9B84C3EDDD6ULL, 
            0xD55BD3D5B25D4B33ULL, 0x1686DA9909FAAFABULL, 0x8A5E2A18620B8A8EULL, 0x652F668C34DA035AULL, 
            0x3DB751D31609BDD9ULL, 0x8B6CCAD5D4A89A4AULL, 0xC1202E593336E006ULL, 0x241715C0B4034C0AULL, 
            0xA87AFEB8BAF3E110ULL, 0x23E0C9F46D3952F7ULL, 0x487C5B5F71ECD391ULL, 0xE1A1D5017B8DC57EULL, 
            0x437DC689599DD42AULL, 0x159DED24EDA6FDA5ULL, 0x4AA98C0E2D9235A7ULL, 0x329AC2B1D70BAD85ULL, 
            0x3FC4AF3BDC2F90D2ULL, 0x70A6F0BDDD7AABA9ULL, 0xF757B496A84F3AE7ULL, 0x64B887D0E6FC4291ULL, 
            0xF650E2A9A14C1065ULL, 0x1C2D10E293BDADF7ULL, 0x943065D760E22782ULL, 0x8DFB1EB4868E51FEULL
        },
        {
            0x6DFA8148D46588F6ULL, 0x040D1259E742F0A8ULL, 0xC9366FE3D8E4DE11ULL, 0x82C177869C71AADDULL, 
            0xFEB47A6AA0724548ULL, 0xDCBF132A7B08BE00ULL, 0xFE9632CECFF5E366ULL, 0x6E454C9252749FECULL, 
            0xBDB05B36B6B79EE6ULL, 0xA50785A548F740F9ULL, 0xA29BD58822A923AAULL, 0xB6088361319E26D4ULL, 
            0x5DDD8803B942D93BULL, 0x5892EACE5518DEF7ULL, 0xD07014EF3ABD9305ULL, 0xD3C0D0AE5D79B228ULL, 
            0xEE9E871AE66F26D4ULL, 0x0C59E97964F8BA1CULL, 0x82C84356660558C1ULL, 0xC03082AFCC992278ULL, 
            0x0E51E6EF0548E059ULL, 0xA3FF67B3ABAF1382ULL, 0x3ACFCD8B715D9870ULL, 0xEE79EA355558A16EULL, 
            0xCC345921151D346DULL, 0x94EA1AD53E433BEBULL, 0x9771D8443498BC26ULL, 0x0A1AAB285A726D95ULL, 
            0x0BE5CBEC91CA79D3ULL, 0x2923BED9487F96DEULL, 0x5D4BF43EFA42FF49ULL, 0x589C495727CA0502ULL
        },
        {
            0xB16911BC98A4DF0AULL, 0xF92038E126E556B7ULL, 0x3EBCF7D85D629636ULL, 0x8C0FCEFC85EE50C6ULL, 
            0x8441D7A24BD1460BULL, 0x90EC47792AE62181ULL, 0x73282447E6D2D650ULL, 0x3E1D6DA87D0236E5ULL, 
            0xF34647F536CE442DULL, 0x6F8A2FB440D206A0ULL, 0x9B0B299F5B408A07ULL, 0xE9243DA9268C2041ULL, 
            0xC1DAD0F75F6599DEULL, 0xF58F08EA0C752EEFULL, 0x96880016EE636268ULL, 0x9970DF564431158EULL, 
            0x88FB68A6007027C9ULL, 0x8BD22D5071E78166ULL, 0x16BD37CB12CA80EBULL, 0x6AD075F7C83F21C2ULL, 
            0xB8B6E4E4A4F6E518ULL, 0xEEC04DCE94082225ULL, 0x30F9D51833B8795DULL, 0x0F7F2A54E8BC920AULL, 
            0x8CFA22E4364026A1ULL, 0xD945CF4438DC8DADULL, 0x9CC5C64E3179087BULL, 0xAE7BA4A189AC85D9ULL, 
            0x660093BA08E0FD84ULL, 0x82F0925C2B6FE42AULL, 0x482614EFBB99283DULL, 0x6113CC910EB853AEULL
        },
        {
            0x961F626C33C8B02AULL, 0x00DEE5176A970D73ULL, 0x4F010ABA09AE1C31ULL, 0x2D61C28BF907748AULL, 
            0x4B64269E3B58E702ULL, 0xA89203FEE133AFB8ULL, 0xF309D98B5537999DULL, 0xA7B90C8F8987882FULL, 
            0xB122CF790905844BULL, 0xD92EEBE15C1EE0FCULL, 0x71C6644658251CCFULL, 0x0DCAE30A9C684356ULL, 
            0x0FF0080541C957BFULL, 0x99F49B15DD46A3DCULL, 0x25BA10926242AFB1ULL, 0x1DBEE41C839FD46BULL, 
            0xC6A09BE7D6473296ULL, 0x308A1B0F4B54C9C2ULL, 0x1B0D7DF9F6455766ULL, 0xA35F7CD76CAA331CULL, 
            0x0EA6144CD59FFC49ULL, 0x050F63F8D68CD132ULL, 0xDA6E0A89C8A5F021ULL, 0x880688A06476DCD7ULL, 
            0xEA3739EAA2947D95ULL, 0x116466754AAC019EULL, 0x175D4363850D10C4ULL, 0x8DB4073EBE24AD94ULL, 
            0xBD30052A0C4BD794ULL, 0x5ABEE2E796B0C255ULL, 0x32E9778FE16390B3ULL, 0x6EC7BAA301FFA841ULL
        },
        {
            0x8C706B5651B6F79AULL, 0xA0E25878B762A1D9ULL, 0xC568C483F2B51D81ULL, 0x034EFE75CB218EB2ULL, 
            0x7510177C884319C4ULL, 0xD63C2A8BFF6C297EULL, 0xDD5F4FD2C5626A96ULL, 0x2F7B38C4D6F912B4ULL, 
            0xD889843C58DB31A2ULL, 0x9513C494021861B2ULL, 0xDA67C8B58BEB28BDULL, 0x714A3776D0E11BBAULL, 
            0xA07C581072F6B0C9ULL, 0x22426E341C2F94CCULL, 0xFC47EDBD1796D5EDULL, 0x70219DD9E7A4187EULL, 
            0x274CFBC0DE99871AULL, 0x7B5A942AA13C1285ULL, 0x28D3BE0FF2CBC953ULL, 0x3CFBD64672C8FC6AULL, 
            0xB4DC0CBD5E0E69B4ULL, 0x5C0753FED70017D0ULL, 0xE7935C6DDA08CC03ULL, 0xE62C83D78F41B288ULL, 
            0xC9C92A5B580408ACULL, 0x47519E4EFB6A32FAULL, 0x01DFFB0A2949E848ULL, 0x19518E4A0BE5CE15ULL, 
            0xD07B3A6DF81C68DDULL, 0xB94AFB433C5F77C9ULL, 0x7A2D862BC2DB3C34ULL, 0xBC0777034515F1D8ULL
        },
        {
            0x942E905F593708FFULL, 0x6C8405063F751682ULL, 0x4A2C9AA92419AEEBULL, 0xB627B491C4779E9DULL, 
            0xA66D713288A843A7ULL, 0xB3D44B62596D0DEAULL, 0x28D86072CF2AF4C2ULL, 0xB88EEAB364AE9981ULL, 
            0x54047DCC24970108ULL, 0xCCFDE394D8BE07DAULL, 0xBC9015826E638F59ULL, 0x811F296008AD3302ULL, 
            0x1CE2058237400E7AULL, 0x4245A2F05689041BULL, 0x05C55919ECAC1AD0ULL, 0x0EB027239DB7DD1DULL, 
            0x1B2596D3D4011C64ULL, 0x4775653FAA61F73EULL, 0x50AEF1E280405968ULL, 0xBF4AE933AD10B9DEULL, 
            0x426B4999FFE5D760ULL, 0x8973EE08585A74E9ULL, 0x6F6F376889EBD18FULL, 0xEAE27019EF08C64FULL, 
            0xCA2ED465546ED425ULL, 0xFE97994CAF1D2346ULL, 0x60AB13574CA26979ULL, 0xA673320335B18D60ULL, 
            0x002103E2999E6A94ULL, 0x58FB9230E2A1E769ULL, 0xEA9DBFABA8B41D40ULL, 0xB21226EC2B74E420ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseBConstants = {
    0x3A5E6D0A46D3780AULL,
    0xED7FC2607D127A2FULL,
    0xABB5269D7690F1B8ULL,
    0x3A5E6D0A46D3780AULL,
    0xED7FC2607D127A2FULL,
    0xABB5269D7690F1B8ULL,
    0x84BBE175975709BBULL,
    0x27AF3751EFFE9771ULL,
    0xE2,
    0x88,
    0x84,
    0xD1,
    0x7C,
    0x9D,
    0x9D,
    0x49
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseCSalts = {
    {
        {
            0xF48506BAB5D21AE6ULL, 0x6D9A5BB2E0A23EF8ULL, 0xBDD56B24635ECD5EULL, 0x67F7B2FAA4B3432AULL, 
            0xAA3A56DE5F491A8CULL, 0xACC7F66B8B563EF7ULL, 0xB3F7747E6977A466ULL, 0x0364C12E59B66750ULL, 
            0x0FB7D286477A7FCDULL, 0x835F471C540230BCULL, 0x9F46634F3225EFB4ULL, 0x545D9F9EF9E11CC3ULL, 
            0xB4B0B2C6698FD8C8ULL, 0xC8CEE2421B3C9EAAULL, 0x7F0F0B1E40B87D13ULL, 0xCE1D0A5E967F32F6ULL, 
            0x4633CC17AE5A7763ULL, 0xE356303E73B7B88EULL, 0x601465A61A79D104ULL, 0x9D2A0F1AD69F6EADULL, 
            0x4ABE3F2481656D04ULL, 0x80A82D6312EED685ULL, 0xB48955392209E690ULL, 0x73D7A01036BD3339ULL, 
            0x8A8DDE6E3F2DD88DULL, 0x0125F4D1851D7A52ULL, 0x5FAF1C63509556F9ULL, 0x109F3F33AF93A276ULL, 
            0x8DA33EAD354E6164ULL, 0xE55BB2D9B554C663ULL, 0xD8440FEEBE5704F9ULL, 0x3F3AAD1B64FE57DFULL
        },
        {
            0x6C539515EDCE967CULL, 0xB8CF64E60950E0C0ULL, 0xAF17513BE64CCECFULL, 0x7FEB21650F2E7943ULL, 
            0xF348BCD52CB8CF80ULL, 0xA26DC7FFF5BECA5BULL, 0x21F1FF79EAD61BD7ULL, 0xE9B4048D959B7AF6ULL, 
            0x44A728523F569183ULL, 0x96B73451C7935AE6ULL, 0x075E348DEA87905EULL, 0xFF921EED595DC17CULL, 
            0xFE1D0A5D34DE07BBULL, 0x1D9CDAE4F9AF315BULL, 0xC456FB9DC8738A02ULL, 0x87195575DE15D5A8ULL, 
            0x8F8B02589E791B01ULL, 0x9F90D71E0B987C48ULL, 0xD297C511E48DC209ULL, 0x1B64A8170863B5FCULL, 
            0x208B8D8F0B8CB341ULL, 0x5A5F3535FADD33C0ULL, 0xAE169870B806DC47ULL, 0x2B95E7514AFB7D32ULL, 
            0x5B914B080EB68861ULL, 0xF3AD719A91646B44ULL, 0x307FDA2AAB747D51ULL, 0xDAAB099C734F7F26ULL, 
            0x496418C598317F02ULL, 0x93B329847D4B7C26ULL, 0xC778274EFC91B071ULL, 0xE2561B071105796BULL
        },
        {
            0x5525713F21828F29ULL, 0x7DFAC1ED1F9D1C56ULL, 0x1634C93B19C6FCC5ULL, 0xDC83BDFA1CF41C22ULL, 
            0xBE3ECDDE8ABA13BAULL, 0x5E708502A8650D64ULL, 0xC8A5AEDECD65F659ULL, 0x1710F54C40E53D1BULL, 
            0x2C78470E3179CDABULL, 0xC12C62F088B2AE0DULL, 0xC6DF4B1C61F8EB85ULL, 0x0CFF06F50BFE8D44ULL, 
            0x2FC1F41AD9875646ULL, 0xC1AD4B2CF90FD9BBULL, 0x9AD8B2BF11D5162DULL, 0x771012686C961434ULL, 
            0x4EBF2FF265D2A403ULL, 0xA82D6B29381BA1E9ULL, 0xD00CC8B6972DF8C5ULL, 0x3B91509E0771A79EULL, 
            0x68EBB930E1BC640BULL, 0xF3B793D03DDD5AE2ULL, 0x782650C509012E79ULL, 0x5D5FD2FAF90C394BULL, 
            0x27B23653CA9C3269ULL, 0x5DB9A9CCE8FD6505ULL, 0x171A7FEE04FF08F7ULL, 0xF4D0EAD268CF6006ULL, 
            0xDE873E204560A52FULL, 0x939D424168A423D2ULL, 0x6D7418D3F4BFF4ACULL, 0xB0F82CBD1FEFFE7AULL
        },
        {
            0xC8C6C85F7CA019D0ULL, 0xADB999704FA6596CULL, 0x882D61FAC1935509ULL, 0xA293793A54761EB6ULL, 
            0x5C550428E812F269ULL, 0x6AFA1D85256016BDULL, 0x9959637B4316245AULL, 0x4D9DF7C911D72815ULL, 
            0x52B52ED303708BA5ULL, 0x30D27AF7E57796D4ULL, 0xFD65A5426C4320F4ULL, 0xFBF6532F507D445DULL, 
            0x12E9C7B1E1DB7588ULL, 0x1B968D5ED3F631F7ULL, 0xCEB24ED24A02F071ULL, 0x5533017918BEAEC5ULL, 
            0x5AE6301823A8E0C1ULL, 0xECCA006BAFFA6099ULL, 0x17E301DB1AB831C9ULL, 0xBE57F241204F0FA6ULL, 
            0x9EE3E69537A5AC28ULL, 0x25DFFFACC1E61F07ULL, 0xDCF5D683F2755F0EULL, 0x0D1EE7C891765358ULL, 
            0x03D61A566BDA0F4CULL, 0xED47E40AD16D67F2ULL, 0xDA9DD5A58075BFFFULL, 0xC090119418B0BBD8ULL, 
            0xFE998EA9A4951E96ULL, 0xEA42D4DDEEC4F415ULL, 0x1795009AC1C3B3B1ULL, 0x26E1EFFB27B0720BULL
        },
        {
            0x199F3617B1DDECC4ULL, 0x3322B556AC0479CBULL, 0xB09582A694A5F4D1ULL, 0x03D31809EC4A3220ULL, 
            0xCBB190FF189731A9ULL, 0x982376E4853F7BE2ULL, 0xBD91BB56106D65D3ULL, 0x4FD208B2BBC957EBULL, 
            0x567505C4197005CAULL, 0x140AE5C174D8B0F0ULL, 0x673FC38D753FB222ULL, 0x4CBFD38831FA32E7ULL, 
            0xB1713072DEBAB591ULL, 0xD5DB0649FBA0F210ULL, 0x0D26CA1A05C328B4ULL, 0x5014D6EC02738A4AULL, 
            0x9876996551BB2B9FULL, 0x027C282F5640C37BULL, 0x9B0BE8D45DCE70E4ULL, 0xA7F7BFB4A056E9F2ULL, 
            0x53AA9210CAEB6A4FULL, 0x4E9B4D0383A948D9ULL, 0x34B71C3D8B8594ABULL, 0xFC9685A241281728ULL, 
            0xA098E68BDED63C4FULL, 0x5C1381B1763AB396ULL, 0xB19B635B60B25B44ULL, 0x8189DBB73A49E60EULL, 
            0xF4AC9D2F46554988ULL, 0x217FA70AAE3D544FULL, 0xEC6DC4EDD17988C1ULL, 0x3CF0C7E4B5225088ULL
        },
        {
            0xAAB971A2A5148EA8ULL, 0x2FC7F4A38F20380FULL, 0x4AD49D36FE4F204DULL, 0xA9F7FF5ABBB58878ULL, 
            0xC2C17CD6DBD92FBCULL, 0xB5508B64A155C871ULL, 0xF5AF4400C22666C7ULL, 0xA445A13F742B8CB0ULL, 
            0x5961152BB882D315ULL, 0x85E19584C180B226ULL, 0xADBAD49956ACDED0ULL, 0x56FF5B2A2789B614ULL, 
            0x09381BE8BA4FA323ULL, 0x5993CA7D41411759ULL, 0x660B00CC70AB7400ULL, 0x6BD244D6043F9B91ULL, 
            0x9DC4BB81B184761FULL, 0x55C55539C4280C16ULL, 0xF1622A03C2A0024EULL, 0xF98278F9CA4BF3FDULL, 
            0x61856C2916748E9DULL, 0xF2494CFBE8BB228DULL, 0x761D8391FC0368E1ULL, 0xF1E2EC6C636CD96AULL, 
            0x2D9F510609A9F4E9ULL, 0x97493891C066EDD3ULL, 0xAB76545F44905172ULL, 0x83EEA43D6D9033E1ULL, 
            0x05B292B98530EE3EULL, 0x2BFC9888826A96AFULL, 0x004BC55B4A23A8CCULL, 0x35E095B6C40FF1C0ULL
        }
    },
    {
        {
            0x00DF9F0CBDA75BB3ULL, 0xBAFA4D089FDB2CE1ULL, 0xF7E9F124202CB22FULL, 0x065A5B16860F73BDULL, 
            0xAD96D469A8891C4CULL, 0x84A9CAA7379B8B0DULL, 0xA6D90C20693D24E2ULL, 0x2E07C76DBB42052CULL, 
            0x8239AF3BD089198DULL, 0xAA604C5C8B81D752ULL, 0x21D63EF9FF331B59ULL, 0x048BF36C7B5620F4ULL, 
            0xEAEDC1C286F3B6EBULL, 0x4DEA3CDF3841C1A4ULL, 0xFE0131AA7D6D246FULL, 0x0998788F82131924ULL, 
            0x4A8CCD5B6AD3F4D0ULL, 0x4FCDDDDB23D7390CULL, 0x986F3DB79807C2DCULL, 0x7972A84C04B5C171ULL, 
            0xACBEDA481A4FC5A9ULL, 0x2A4544A0025AF274ULL, 0xF0F119C471C18D0CULL, 0x295446639F530CD5ULL, 
            0x5300C83B9836E120ULL, 0xADA66D28B328D9BDULL, 0x2A0796787A7EE6DEULL, 0x60465685CFD222CEULL, 
            0xD4B87C6B77A342CAULL, 0xB7DC990E68A98FB9ULL, 0x3A18786B675D7C2FULL, 0x25C0C043AF765884ULL
        },
        {
            0xD8EB99F90DA3B1C6ULL, 0x43CF88C704E428C9ULL, 0xF89B87018D0892C9ULL, 0x1B943F5B5E175438ULL, 
            0x2FE7227AEBB7F8A8ULL, 0x4B1B512038ACA862ULL, 0x0925FA2BF72F97C6ULL, 0x3ABBB0DED6A5FFA4ULL, 
            0xB883622A81B434FFULL, 0x0FA73B0F6219A003ULL, 0x1DED47E2D0209C7DULL, 0xA18D53D38CE46C09ULL, 
            0x62AA54BDB0E609F7ULL, 0x721911942690312AULL, 0x1B6E76271F60BF99ULL, 0x5E407186D3E647C7ULL, 
            0x60FC525509690455ULL, 0x4AD5DD304840CC2FULL, 0xBB84AAA47411A001ULL, 0xDF5C80244EBA9327ULL, 
            0x9D9D22F2C937FCF7ULL, 0x6D7565A5A6FA047FULL, 0xDFE01396EE42FAC1ULL, 0xDDB9A1C6C303022BULL, 
            0x85FA0D7DDDA18DA3ULL, 0xAAB0FAB8F83F758FULL, 0xF0474214F62C4BE9ULL, 0xC7F6C3291A0689B8ULL, 
            0x1A2A1A0B1094F6D4ULL, 0xEFF4427FC88CBD72ULL, 0x4BF6ACFAB06FB05AULL, 0xD455953BE93A4CEFULL
        },
        {
            0x4949F2626CE6F596ULL, 0x94F03A3FAB89CA2DULL, 0xF56359B50599CC86ULL, 0xA0BDA3E6A927D7B8ULL, 
            0x3EA42E4F414A8FF6ULL, 0x17B9ABCE019C4EBCULL, 0x936325631B8ED70FULL, 0x1B940CB4EC3E722FULL, 
            0x70DAE6A8615FCBF3ULL, 0x0CC09616513A4A9AULL, 0x7FEF4D7FDAECB330ULL, 0x9416D7C9FBB5A801ULL, 
            0xD6E58A42ACDA08F7ULL, 0xC7A98BB48CCFC1CFULL, 0x67100CD59766E396ULL, 0x937B54B3BEA0D5CBULL, 
            0xEF79834E57784979ULL, 0xEF29653ED8443FF8ULL, 0x1C03A4BF00F7CF43ULL, 0xB8959756A1C21A24ULL, 
            0xB42EE4D0868839A3ULL, 0xEB4B57EE4684C855ULL, 0x78376749F0984DB3ULL, 0x7FDEDAEB0BB57FE6ULL, 
            0x6C6ABBEEF05A9978ULL, 0x2385D13FD69E1799ULL, 0xCF8F4656F8E23E35ULL, 0xDEB52BC85DCD2C41ULL, 
            0x480AF979258922B8ULL, 0xE3A460061A36C6E4ULL, 0x048CF8D1EC089366ULL, 0x13C99A330F9C3769ULL
        },
        {
            0xBF216AD48221C125ULL, 0xEE32BEEC06B5149EULL, 0xAAFE65A4AED54A3AULL, 0x6142FCFAB57768CBULL, 
            0x1EA3264A57C3A9CFULL, 0x5BA062431ABBFD21ULL, 0xD85FFAF58D748575ULL, 0x2E2D4031F0F70A9AULL, 
            0x72365A9FE0F363E5ULL, 0x6FA0D635AA6495DEULL, 0xC14AE884149D9A0DULL, 0x7E6AA5B2182D7B84ULL, 
            0x188613EEC88B509AULL, 0xFE9BB8CC2844BB31ULL, 0x21EAA4B39AA698D4ULL, 0xA2DB5304CBE35B60ULL, 
            0x8D538D0F899F1584ULL, 0xBE2C9127EC0685CFULL, 0x6CBA96F808D1F9E9ULL, 0xBEFD7918015414FCULL, 
            0x6BA628F4EB036597ULL, 0x5799B7315D5A27AAULL, 0x9148050B2EF0C83FULL, 0x3C26A3FBC671A348ULL, 
            0x065A67680AB63158ULL, 0x6EF2BE842BC3994BULL, 0xA67F2731A9E9EA6CULL, 0xA131B23A3259F3EAULL, 
            0xDB2D762D44D29578ULL, 0x586D1FEFC9BC024FULL, 0xE2EE1C3842FBC4D8ULL, 0x6289C6CC155BDE11ULL
        },
        {
            0x6334BC314C90E9E2ULL, 0x44BD4E59D4191629ULL, 0xC77EE17455B5B03EULL, 0xDBAB4BF2038ECC00ULL, 
            0x2BBC29F13689F417ULL, 0x83224A470B219ED6ULL, 0xA8AB8150CB356FEFULL, 0x3E69EEC4C80B944FULL, 
            0xCE46DF8AF8A57589ULL, 0x46F4F239C16F97DFULL, 0x4C3A470FA7394795ULL, 0x9F98E2CA1A08A914ULL, 
            0xA510B35C5A5484A3ULL, 0x24D7D628EFA24F36ULL, 0xB9E777942B8F8B90ULL, 0x6EDF5243D51BA164ULL, 
            0xEDEA9A1405CA06C8ULL, 0x1D895690FB880F4EULL, 0xDB89CD8A91C94B47ULL, 0x4AB437E4674041BEULL, 
            0xB4C2609236CE9D4DULL, 0xCD3C8C2540C83130ULL, 0xBBC2C340FA57EA37ULL, 0x55F60B97B308D031ULL, 
            0x28FBFF355005348AULL, 0x5C9130162A67E92EULL, 0xBE502409B72A6ABEULL, 0x9F7BB9C96F20CBD5ULL, 
            0x56EF2A25C0FF33D1ULL, 0x306FF4BE3E933B17ULL, 0x358E21F9F1A4894FULL, 0x3008381EA4CC031EULL
        },
        {
            0xB86A0C0001855E32ULL, 0x2AA5AE2ED5E37868ULL, 0x13C709D181B7E198ULL, 0xC481422462289C10ULL, 
            0x3C31474B86B28B1AULL, 0x1AC3267726343687ULL, 0x0F12A172586192CDULL, 0xDF1AAD3548AB58B2ULL, 
            0x5193F95ED384BDE3ULL, 0x062D475E755F590EULL, 0x147C35881CDCC53EULL, 0xE3BE88FDE013E607ULL, 
            0x629E44FCFF211339ULL, 0x819687E528965CA4ULL, 0x44A0C4DD10E8333CULL, 0x95D8D23A53EB0A0AULL, 
            0x4BF09C6322028583ULL, 0xC8D5162CF3F28930ULL, 0x31879D86224B0DF3ULL, 0x74F22E57BB1D9EAAULL, 
            0x80E186FD900F782AULL, 0xDAB33A87A51F6313ULL, 0xA7E77F90170EC6A5ULL, 0x93001A8984622625ULL, 
            0xCB754DD2649679EDULL, 0x3FBF3E8723CD51F3ULL, 0xB2E56C6219D2E1C2ULL, 0x073AA6FDC91F05E0ULL, 
            0x608BC06C8D8FDCAAULL, 0x3BA6C4DBD737DB10ULL, 0xE3C026C31D4461FAULL, 0x54FA75300B2F68EFULL
        }
    },
    {
        {
            0xA5486FCF16440A64ULL, 0x219FD588FA70EEE5ULL, 0xDE2BC3359720597BULL, 0xC3FD6D0142E3082AULL, 
            0x96515F132451F921ULL, 0xFE14CFD7FE9C79A0ULL, 0xEF8FC82D7DA15439ULL, 0xD69A7BA83F58C4F0ULL, 
            0x1DD090391ECCE34EULL, 0x343A1181936AB738ULL, 0x69904F79BD43DFE1ULL, 0x0A52CF4D0D302DE3ULL, 
            0x0207DC12C2285300ULL, 0x1E08D872AACD8D7FULL, 0xE5B4F512717620FEULL, 0xABCDDA47954CEC06ULL, 
            0x12CFC7FE3FEC5CF1ULL, 0x864A9A9815DB289CULL, 0x794E9EFBC43849C7ULL, 0x8DB9DEA03A417481ULL, 
            0xB0B82BDEC243CC31ULL, 0xF31D094853BC952FULL, 0xCC1A547A96DE6D5AULL, 0xB92B97AAC1942E7AULL, 
            0x3E977E5C093DAAA9ULL, 0x32E685664E7A7F0CULL, 0x82AF36D9AA848EB9ULL, 0xE496D3231CA2ACEBULL, 
            0x65683E62066573BBULL, 0x97B3F86F56CAC008ULL, 0x097D07E83EE7F80CULL, 0x9F9B0AE1A7634E26ULL
        },
        {
            0x747771AC6CDFE03CULL, 0xB3747859313927B2ULL, 0x25BD4AADB53324F0ULL, 0xD82F6847FF6EC4E4ULL, 
            0x9371950D1542DFA5ULL, 0x8F4392322180D49EULL, 0x978E9D143B2795F4ULL, 0x39FFA76531F94A8DULL, 
            0x357C8E6E32ACC4B1ULL, 0x53A3CBE6DC908410ULL, 0x0414F2DDC2BACFF9ULL, 0xEAA9DAF8ED4E3FECULL, 
            0xF0284BCA1719885EULL, 0x0725D6288946C4DBULL, 0x0A826988036B56F6ULL, 0xA184E30D09199BB0ULL, 
            0x81B7AECE781F9305ULL, 0x05BCDDC351DD1032ULL, 0xD609DE7269F03C2AULL, 0x171A902A0D3377D8ULL, 
            0xAEEDE59B5D78EA27ULL, 0xCCCEF35582B31F88ULL, 0x6438A4D0D63579E6ULL, 0xF32768FA1898A80BULL, 
            0xDFBA34D20FB76705ULL, 0xA4F12F72B0E89902ULL, 0x2675DB53F8B0B88BULL, 0x7F0514A953A63B15ULL, 
            0xBA5CF6E42B4F4F0AULL, 0x8838D915241D65ECULL, 0x8041D6B04463F991ULL, 0x246F5EAA441EE31EULL
        },
        {
            0xD5B31D962252A5C9ULL, 0x97AED9520CB785B1ULL, 0x92193629B6310F5AULL, 0xCA1DDDD59F8DC6CDULL, 
            0x3CD5CE275E3137D8ULL, 0x7067E35317483E6DULL, 0x6D0781A6F0888F16ULL, 0xE1BE09E132235C30ULL, 
            0xED4E4587257DC7C8ULL, 0x41521623FF7A8E20ULL, 0xE4742C17C174CA8DULL, 0xA87ED31F4CF984E9ULL, 
            0x85CAEEE92FBCA899ULL, 0xE449DE07F89DBAAEULL, 0x750E5D2ED9D01547ULL, 0xCE1E1041568806F3ULL, 
            0x00683FB2017EAA42ULL, 0xFF47CA57C7094E94ULL, 0xB22E8F93ABE23F43ULL, 0x60A0EF0FFD11E31AULL, 
            0x76582CCBA172FB5DULL, 0xE6B259864BF623B6ULL, 0x524F68F257BA4BACULL, 0xEC99521788FBF528ULL, 
            0xDCFE48EC44BE8DDBULL, 0xD0453E30B82E869AULL, 0x725CC968E4AAC36CULL, 0x89817C0926404036ULL, 
            0x6C97B51E6BC5E9BAULL, 0x1DEDA42C9BBEDB86ULL, 0x1D8E03E2156A8942ULL, 0xC8EF37A6E5466619ULL
        },
        {
            0x56E6DB7788E7F08BULL, 0x279FC6B8F93B2782ULL, 0x4FA2AD192E894751ULL, 0x7D6C6CFF7CF74697ULL, 
            0xB0F482B4EE529EDFULL, 0x6336EA68A2DE8411ULL, 0xEBDFDADE26AEFAC7ULL, 0x9F8AEC1BB92EABE9ULL, 
            0x7F99EFD1E9FDF012ULL, 0xB3D817BCD033D8A7ULL, 0x6452CA69CF808AEFULL, 0xDCE9351E472971C4ULL, 
            0x27337E34BF3544F3ULL, 0x8F72AF3EC50059B8ULL, 0xD5B87213BF82F092ULL, 0xB5867F3CA44E0BF6ULL, 
            0x9A0359403509BDFDULL, 0xD0B72A628C788769ULL, 0x491EB8005064E302ULL, 0xE885B26906DC13BEULL, 
            0x1CCB558FB91AE4C8ULL, 0xE45F35D67EA6229AULL, 0x3B90397443DB0910ULL, 0x26F5529799690C65ULL, 
            0x6FA19064B94CA5D5ULL, 0x4B937F4AA9136335ULL, 0xD7460AC6F7A97C48ULL, 0x108E1CEFD85FA678ULL, 
            0xB1FD60FF3B59F0CFULL, 0xEA3521DF620672ABULL, 0xB13D3E4208FB83C9ULL, 0x159AE7C93FBA3BC9ULL
        },
        {
            0xD1D4782E8BB4151BULL, 0x96A7EED49201D050ULL, 0x7BFAE84D37D3B444ULL, 0x08D2FCEBB04E95A5ULL, 
            0x4392CC8DACF8A9C6ULL, 0x0F3CE838605BF4ACULL, 0x509D856CA90D810DULL, 0x86B6A50C15D23ED4ULL, 
            0x8628BA67934BB6C7ULL, 0x12CF9731DE06F2D5ULL, 0x7437488D88716868ULL, 0xA86E54B34FF30DB5ULL, 
            0x5D0CBE894EB69D6CULL, 0x9DCB04B55F0BF5F2ULL, 0x088D222D41C92888ULL, 0x2C63A392C8A6C607ULL, 
            0x5048149622EDCB6AULL, 0xAD94BF6454403603ULL, 0x76F25A7C789FC8A3ULL, 0x33E227FE28778F94ULL, 
            0x4EBAB42D3182DA64ULL, 0x8C1508F87FCE0BE2ULL, 0x5143391C1A98F258ULL, 0xB03007A29879FECCULL, 
            0xE6D790D3C4769B79ULL, 0x98C727531056E54FULL, 0x90288AEB58510FBAULL, 0x832D5EE7F5E6A493ULL, 
            0x25A3FFDC3C59B8C4ULL, 0x062B6F73AE0DFBFDULL, 0x6BA2D6824838919DULL, 0x1CB7193195697FD4ULL
        },
        {
            0xD465CD0BCCDB8E27ULL, 0x43CEBB65CEF28C6AULL, 0x2946EDD77158A4E0ULL, 0x240F1BF2D4BF0F61ULL, 
            0x83B1118E78D34716ULL, 0x69766FD11CF5A520ULL, 0xF1F395E9484C5D85ULL, 0x49712411274C7202ULL, 
            0x50C42876E9C30657ULL, 0x4C51207FA93E61F3ULL, 0xEE6ECD66CFCCC80BULL, 0x3959FC9AA7EF2F8BULL, 
            0x6A95F7D231B248FCULL, 0xE978B642EA98BAA0ULL, 0xCE7C39F1C3241409ULL, 0xB4D46286F9451B4EULL, 
            0xB458266BA3F1B8A1ULL, 0x8429FC14F47A666EULL, 0x2BB4E1111071E7B5ULL, 0xF82AE980477D462EULL, 
            0x95A7CAEFB1527B7CULL, 0x472BE63ED90C58DFULL, 0x12217AA79583C7FFULL, 0x2FB18822A366A0E8ULL, 
            0xC6D69004B4ACF308ULL, 0x6F0575B9EACCA7BDULL, 0xC09175CBA11A9C89ULL, 0x987180E43DFD4DA2ULL, 
            0x0F8D96DF4B56E084ULL, 0x54D0F0EE91FD4DEBULL, 0xA02A600ADA12BE30ULL, 0x39574E9F218FC11AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseCConstants = {
    0x60E398693018544FULL,
    0x6AD5D0647F893380ULL,
    0xADE8D71D516B3A67ULL,
    0x60E398693018544FULL,
    0x6AD5D0647F893380ULL,
    0xADE8D71D516B3A67ULL,
    0xA07F104E00D3D167ULL,
    0x00B620ABD6514E43ULL,
    0x3E,
    0x11,
    0xAA,
    0xA6,
    0x5D,
    0xE1,
    0x2F,
    0x44
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseDSalts = {
    {
        {
            0x5CD9012DD3EE9CA2ULL, 0x68C22917A84A888AULL, 0x611A33452BA3E644ULL, 0x25C56FABD251D142ULL, 
            0xFDA8FC079765DA6DULL, 0x071DE16832228C22ULL, 0x890458DCF24144C7ULL, 0x4C8D21F7B8549A2EULL, 
            0x7C896D20FF5F5981ULL, 0x96CCFC3ED8656A8BULL, 0x4384301EA7548D14ULL, 0x03219E1000F5010DULL, 
            0x810AC578915D9E11ULL, 0x0DF32D596ECDA5A6ULL, 0xAD3793B608B74438ULL, 0x3EB691A42990A42FULL, 
            0x09A5477DF5CFCF17ULL, 0xDA471CB64A905468ULL, 0x408E66E09343C110ULL, 0x1788527EF4DB7DA0ULL, 
            0x88BCFA8FF12B8E9EULL, 0xCD91C0F174AAABFCULL, 0xC105CA508AE43010ULL, 0xE3B8F4B2A843A1F0ULL, 
            0x886F306148951074ULL, 0x65C9925A017B5C00ULL, 0x2670574B2F255C2AULL, 0xB4A0C54613E8F2EEULL, 
            0xD20F8B8B08E41536ULL, 0xE9A8FFC9040439F2ULL, 0x48352A4997BF1029ULL, 0xB8A143DA46FA5080ULL
        },
        {
            0xBF8B994A19071DA1ULL, 0xD7CD5D876B61A864ULL, 0xAE9E6ED9E57C665BULL, 0x318F9D8A0D601C13ULL, 
            0x2BAC8D4547D11E3DULL, 0x79A8B409206887EEULL, 0x8DFD19144E55182BULL, 0xB32C9C50405FD46EULL, 
            0xD8347D0EF7E33E83ULL, 0xEFBF4ADBF018A95EULL, 0xD8169B2808796684ULL, 0xC7F825FC4732E733ULL, 
            0xCE6DE97D9921FAEEULL, 0x41C99BCC346EA4BAULL, 0xB7331A20EAAE584AULL, 0xA922EE3636B70C88ULL, 
            0x8F16D7AEA6370473ULL, 0xDFC56B3AA206E439ULL, 0x182B015EFEFE09FCULL, 0x986428F3A6E57C07ULL, 
            0xA58A3C9689B34248ULL, 0xA7C5167B387BFE38ULL, 0x0CA5397BBBD4F9E7ULL, 0xA5A43E210340896DULL, 
            0xAD43A65CD5127023ULL, 0x9C4B786626823DACULL, 0x9C33049FECE98955ULL, 0xF4CE87590DABE983ULL, 
            0x136C1E5DF3266519ULL, 0xB5F4647944C67547ULL, 0xAD58ADFD8DC8B7D1ULL, 0x87852276022E30ECULL
        },
        {
            0xF1730BF6B057E311ULL, 0x8F67C810DC5737F6ULL, 0x606F1D70D3C2F2C8ULL, 0xC7D7BDA04770820FULL, 
            0x56B171D3BE415C95ULL, 0x3EDAF05910E721ACULL, 0x388975E3E8793AB8ULL, 0x1142F06BAB3C8ED1ULL, 
            0x5116376BEB5ACDF8ULL, 0x445FDD32CA86D810ULL, 0x7A1F57F057D4692DULL, 0xD13677F39722248FULL, 
            0xC7C6BFC56A3992ADULL, 0x61A5F5E443AEE498ULL, 0x694F72CC42D226A1ULL, 0x4C9255932B889814ULL, 
            0x8D43E022253D9F3AULL, 0xF063A4BCAE2D5314ULL, 0x31A458ED12FFA093ULL, 0x89B088C08E244B80ULL, 
            0x79B27B19C65BBC87ULL, 0x44BFCCD9104F62EDULL, 0x1C11F3F9CE821FDEULL, 0x0FE521E7489043C6ULL, 
            0xFBDFEDD3F5FB0186ULL, 0x8D838EF4FA7EE862ULL, 0x344765F7B6B7356BULL, 0x616F2187191BEF74ULL, 
            0xD564C1105FBDA3C3ULL, 0xE100709DCFBB10F5ULL, 0x7A49AE44F4E6B9E2ULL, 0x9B146BFFF09463FCULL
        },
        {
            0xB01761A3AECE0067ULL, 0xA8B388CEEB24D1B4ULL, 0x1FC8EC51C4F425A9ULL, 0x53DDBBC8AC981354ULL, 
            0xA3A92890B3B27EE9ULL, 0xA48E98E30DB27491ULL, 0xAF1419376D1846BEULL, 0x7C468172D14D415BULL, 
            0xC1A954A258C8211CULL, 0x9A9F166F3D91EA47ULL, 0xC0796E1C44C8247AULL, 0xA1E82E7BF10AC844ULL, 
            0xBA8B509C425E0174ULL, 0x460B18C63EDB891EULL, 0xF72523CCED967CE1ULL, 0xE12194D1AA1F1248ULL, 
            0x2B84B78CEDACB1D6ULL, 0x11292C3DC8305040ULL, 0x6FCF975C3D5133C5ULL, 0xB86BBA9281FC10FDULL, 
            0xE4D5B7172E9C8933ULL, 0x2F1F4B7C4A6FA074ULL, 0x438DA9CAC35A1135ULL, 0x49705C90A3802F8FULL, 
            0xAB12E787FC9D0966ULL, 0xFBD4D2712D408B12ULL, 0x050D89AC62A8D52EULL, 0xDEBE22B5674102ECULL, 
            0xAFEE15A661BA0B93ULL, 0x8C0D1B43C5EA020EULL, 0x8912D586AB4FEACCULL, 0xAAC563EDC8D724CDULL
        },
        {
            0xF9C708F663799928ULL, 0x910BCDEEA7511249ULL, 0x7DBBD5AF2DB5D5F5ULL, 0x66E16EE69D827712ULL, 
            0x430A52ADBC8FE2EBULL, 0x29AA83D93F1B3926ULL, 0x91AE3B5FB254B456ULL, 0xE0F4738E18C8CEA9ULL, 
            0x9C707A2FD7626395ULL, 0x5FFB748E233BC90EULL, 0x4B4C8D5679BB0DF3ULL, 0x7F34A5652081D3D3ULL, 
            0x84C4152CDFCF3BBCULL, 0x1C0C91B6E2825E24ULL, 0x111702FE580A0156ULL, 0xD3577312D6668DE4ULL, 
            0x9412F8401562EAAEULL, 0x9B4E0CD4217FAF0DULL, 0x4946E8E4F752A02CULL, 0x715A38B6F3C5D51FULL, 
            0xEE4FA6AA5F4E1032ULL, 0x8826D0EE4DB74888ULL, 0x83899D7AB3EF9B02ULL, 0xD125DE1D5329DB00ULL, 
            0x16D5BC7E85D4EC2BULL, 0xA8A2B63473F78927ULL, 0xC2FFD09C7F4FC82AULL, 0x8B2A6D9DC71E06FDULL, 
            0xCA6E4A5DD8283F71ULL, 0x0C86E9C4786B7D95ULL, 0xA13D4362F2D4FB91ULL, 0x3DD34C0B491F8C2CULL
        },
        {
            0x6D63D9DF95B0FB19ULL, 0xECE926CBA8514469ULL, 0xFC0BD83D0580E2A8ULL, 0x9516DCA6E705FA3BULL, 
            0x0273FBAA7F3F57E7ULL, 0xB4A287397E87567CULL, 0x865D64CC3A27B2DBULL, 0x1F72C366CA62B0B3ULL, 
            0xFD98F52E830D03A8ULL, 0x703D6D6B9E6F341FULL, 0xF2FC8E550C2CAB09ULL, 0xF14BAFCBC6B125D1ULL, 
            0x8FCA6D83FD7AB3E7ULL, 0xB501DDF15085F432ULL, 0x8DC4F3BC08D10598ULL, 0x4DEA330045B7F967ULL, 
            0xEB6477BCD2E66377ULL, 0x86CDAF33952FD10CULL, 0xB1F7FBA59E59399DULL, 0xA4C9D4F88D57971BULL, 
            0x07B868A1FB18A4C8ULL, 0xCB3BB651EC2E6DF1ULL, 0x0D2BD8B546ADC343ULL, 0xDA31BFD994A5432BULL, 
            0x07846BEA627C8238ULL, 0x0CB89ADB119353AFULL, 0x4BA638435E852DA3ULL, 0x84D7D45434DC025BULL, 
            0x029C853D7F6F60AFULL, 0x8863DA5D9020334BULL, 0x5F877041077546A4ULL, 0xC0E39679600BCB43ULL
        }
    },
    {
        {
            0xCD58A0807218E5A8ULL, 0x75F5011BDAC3EFE1ULL, 0xB14BF618103BAD32ULL, 0x68F925D64E1CF779ULL, 
            0x04DEA6B665CFEE9EULL, 0x8D41EECB7B174354ULL, 0x9426B100D74C7AF3ULL, 0xDF5315F942A07917ULL, 
            0x78205FFDFDAE5664ULL, 0x454C8909A15E72F1ULL, 0x2F585858EB682F34ULL, 0x23888419543760C8ULL, 
            0x1FD6EF14DAE2EA3DULL, 0xC7CF91BD87A8C7EBULL, 0x492ECA760E5E28CEULL, 0x67BDEC9DDA236A19ULL, 
            0xD886E90AB599C01BULL, 0x5C0E947EF821B737ULL, 0x13ACD7242C693B14ULL, 0xA75DF92C85113DCDULL, 
            0xCBAA4239F66838CEULL, 0x262A0C2BD18D10D1ULL, 0x943D5ECC29CD2325ULL, 0xB8CC2F9313CFA243ULL, 
            0x44A03FF158B9BE47ULL, 0xB2ED36F41E1DB351ULL, 0x886CE906BDAAF3F3ULL, 0x431A5CE98FC220D3ULL, 
            0x6FA1C2E7586F0161ULL, 0x59640AB0532EEDC2ULL, 0x24E55364E9F28551ULL, 0x496719203CB78F97ULL
        },
        {
            0x726084ED989E866CULL, 0xAD496F3A76F85B61ULL, 0x5B3C6A0B7400F071ULL, 0x649D26C5C428DF8FULL, 
            0x0108834F7DCC645EULL, 0x079DAD67D8047235ULL, 0x75AF7069E92E2024ULL, 0x8194F103DAE431F8ULL, 
            0x87EF32C763F96768ULL, 0xBF03A249639BD3ECULL, 0xABA08FF9EF0833FFULL, 0x0D5662B02CFAB7DAULL, 
            0x65743093109CD691ULL, 0x885FF028B5D4F2DAULL, 0x81E81C1E906516FFULL, 0xCDEA63F34AD4FF74ULL, 
            0xDC3E91D2297D2E82ULL, 0x231EC07F56FE6D0FULL, 0x3B74D2406D978624ULL, 0x011DF25FFE401A9FULL, 
            0x9C041E42CD04BE73ULL, 0x03EF09A10A70AF8EULL, 0xCE3D339FBBA85C60ULL, 0x58D3D57A4269917DULL, 
            0xE7170B8F779FBC1CULL, 0x661221DAE2FCB402ULL, 0x6CDF2B9CFD99CA21ULL, 0x566FAD0421418D0BULL, 
            0x4C40661140710F37ULL, 0x55AB3F9DFF8EF8D7ULL, 0x825E901A4954857BULL, 0x1FD00596F3EDE250ULL
        },
        {
            0x50F286491B336992ULL, 0x8E7ACF082CA5993AULL, 0x5A6FEEAFF2076889ULL, 0xF0CD704637FFB12CULL, 
            0xA82B317B13CBB9EFULL, 0x91982814DCBEDE59ULL, 0xC8FEF688FB5BCDDFULL, 0x2371EB49F7748388ULL, 
            0xB15D83FC4ABDF69FULL, 0x4B484545EC09E3C8ULL, 0xB5752C647D5F495EULL, 0x590692F5380EE756ULL, 
            0x6B7659FF56EE56A2ULL, 0xEE406AE838956575ULL, 0xB66CF06172FA3A72ULL, 0x1178D0B9B5CB9B06ULL, 
            0x095031BFE8D85989ULL, 0x2B93BFFDC2E18677ULL, 0x81DC81A69B0B4945ULL, 0x9A0866D95D72838FULL, 
            0x662745AF5C6845FEULL, 0xC6870B42BCCFFB11ULL, 0x815704A8C65435C0ULL, 0x4E19BED6B78FE45EULL, 
            0x6DC8A1B2ACF5935DULL, 0xFF42EE1829A4BEB7ULL, 0x07297983F5B23519ULL, 0xE01DC913F2E9AEDEULL, 
            0x817675AC73DC17D1ULL, 0x90F241F3D77F47A1ULL, 0xFE000B1F0843344FULL, 0x899749DF2E96255CULL
        },
        {
            0x0C8F52D126F9079BULL, 0x10CE2BF9019F6F4FULL, 0x649E8A7675BA87B5ULL, 0x0C116215E3E74E05ULL, 
            0x6310DD8FDE152501ULL, 0x911A640E2CCE1102ULL, 0x5FA4AC16F7231D87ULL, 0xDEB33A4AEB753845ULL, 
            0xBF442E64CC4F9F08ULL, 0x512F1E296186F5B9ULL, 0x98B30D6181464F62ULL, 0x070DC9EC9574427AULL, 
            0x1AA6C60B21B4FA47ULL, 0x8479DA0D31E279F4ULL, 0x7776DBC7C6AE18DAULL, 0xA2609F2ED2B50419ULL, 
            0x2B72B4DE88A189FCULL, 0xAE7193A629CFCA0BULL, 0xDDD7E2E270AAC22FULL, 0xAB9F6302EAF2A08EULL, 
            0x01D0E641D3D33B67ULL, 0xA28074EF8DA49806ULL, 0xBA3BD6971C9711BFULL, 0x04EB5210B9ECB8E8ULL, 
            0x15686F728BD94F29ULL, 0x66A875B9CDEEF431ULL, 0x3C8AA7F4A1BA4CBEULL, 0xE482689AC583C80CULL, 
            0x62E26E450769761CULL, 0x0E1DDB11416FF7F2ULL, 0x60EF8ECBD39405FAULL, 0x6804D34BE2A99A45ULL
        },
        {
            0xA3DDC1DE22C29BC6ULL, 0xA2E2F04B31A91997ULL, 0x93F2882D87F13A36ULL, 0xA55AF06FAB1C6319ULL, 
            0xEC895DF9EAD19FF5ULL, 0x9BB56776EACB1C11ULL, 0xB4276281A2EC89C4ULL, 0xD14789BD4F31BC78ULL, 
            0x40186B4ABD238058ULL, 0xA77D5E4C63230F0EULL, 0x10B94D3DF399F348ULL, 0x59CC1D434685822DULL, 
            0x6A9FFABA773C615BULL, 0x17434BA8F184D59EULL, 0x60B58025F141F622ULL, 0x52ADCBC72AC67BD9ULL, 
            0x1D7ADCC04A39FA75ULL, 0xC9AAA5D6F8834004ULL, 0x95A58FE2F52CDC8FULL, 0x7EBBA0894C22809AULL, 
            0x6294074B32CF2A89ULL, 0xDEBF09E186816364ULL, 0xE43453CF381ADB79ULL, 0xCF3326435E03A53EULL, 
            0x89A31FF3F46FA72CULL, 0xCDAC423ADBDE13A7ULL, 0x9293FD2D885C1A2DULL, 0x890FB5FEA3A94690ULL, 
            0xA86575B8584646D7ULL, 0x9E78E5DD63A405BFULL, 0xF859DA9C19CC3661ULL, 0x4C51BA7FF3381DA3ULL
        },
        {
            0x6DB65ED05061F8DBULL, 0x533475845727746FULL, 0xA2D1099C68584B0EULL, 0xC3E5907FA5811B70ULL, 
            0x7F2D65F065508C7DULL, 0x657CF4217337403BULL, 0x6A6D996073B57011ULL, 0xE148F0B7D2115140ULL, 
            0xB6B5001C8D33396FULL, 0xB972D101E0993146ULL, 0x32FDAD368D22A5B4ULL, 0xF7F41FF8B617C670ULL, 
            0x17703D7CB142CFC0ULL, 0x759504A94DD27E74ULL, 0xD98412DC39F84F14ULL, 0x3DD2FED72A9D0A9BULL, 
            0x6B12DC8221CFC9F1ULL, 0x05917199CC12DFA4ULL, 0x6B16BA42BD35C6DAULL, 0x11FE37F51BCA0F3EULL, 
            0xC223BD7287509E70ULL, 0x04DCF6A63FEE7433ULL, 0x6862FBFFA2EF0280ULL, 0x72EC4307CC51E39BULL, 
            0x8660CFAE5E5EC2D3ULL, 0x118288E14C9F8D99ULL, 0x865BDB185F2E0A30ULL, 0x15185D43DA575A0CULL, 
            0x3C3B0F2B6AB1A31FULL, 0x6A74667C82B98FA7ULL, 0x2F11BDF3ABCE5A40ULL, 0xFA5E25F8B6F6C3D2ULL
        }
    },
    {
        {
            0x44A781DB1F422709ULL, 0x934EA33ABF504361ULL, 0x6F47D2C7843AFDACULL, 0x3BFEC8A6DB1BC983ULL, 
            0x0811695C9AE45553ULL, 0xCD2697DA98B04282ULL, 0xA9738DF6C4EBAEBFULL, 0x3A0314C706B438A5ULL, 
            0x24B732A12A63C6A3ULL, 0x537A81675D9C8A15ULL, 0xBA73AF003FAF8A23ULL, 0x93A5CC5954605ED0ULL, 
            0xA7E98D659E00D1D8ULL, 0xB25750A948DF8581ULL, 0xEB1F5EA761A8F965ULL, 0xEA4BF9F9401CAAC4ULL, 
            0x9EEBC99F05F46A00ULL, 0x33630F63D16C995DULL, 0x85C3EBBCD1E39474ULL, 0x60A0055B9FCB8285ULL, 
            0x32356AC0E1115B9DULL, 0xFB0C0F99F6D1745EULL, 0xF12420B1927D1094ULL, 0x88E521CA836B7C18ULL, 
            0x880A34868D041A3CULL, 0xB4FEB021A72D75DAULL, 0x2406EC19CCC6EC16ULL, 0xB3E922C5DF25A790ULL, 
            0x0D88FEEE4F91442CULL, 0x67C027154F5F29D5ULL, 0xDFF54BAE60159FB8ULL, 0x367CE5E3AFEA7288ULL
        },
        {
            0xC41510FD43834A0EULL, 0x5B4392EA51EE2D39ULL, 0xEEA6691A4DD2B6A1ULL, 0x448610B15C44855EULL, 
            0xFAB22E266C35D222ULL, 0x4F8842EAC42A2825ULL, 0xF32041B3436B3324ULL, 0x9B4719503CC7BABFULL, 
            0xD29A7EDBF2EC43E3ULL, 0x0C946B9222FA4F11ULL, 0xE05D7376414595BAULL, 0xA9A170299E475E34ULL, 
            0x09FD94BCEB28D987ULL, 0xE098FEA76F895A69ULL, 0xE6411791304E41C3ULL, 0x8A3B88751EB85C05ULL, 
            0xCAEAB2C0A5C99D96ULL, 0xD7D82AD588BA5816ULL, 0x14AD2A2072917EB9ULL, 0xBE3E741331152EDDULL, 
            0x7AF02113CA1D1F79ULL, 0xA8E0A8D82F2D54D9ULL, 0x026091D838729AA1ULL, 0xBB17B009DBAFB8DCULL, 
            0xD736F22283CA744AULL, 0x675877FFC6078B1FULL, 0xA44D1E2E024BB8E1ULL, 0xBA6DA195DFAB5EAFULL, 
            0x53ABF6B234D30549ULL, 0xAB75431FB2C7B04CULL, 0x84EBB7572AECDE1AULL, 0x59BD77A70E345303ULL
        },
        {
            0x311BC477D99F65D3ULL, 0xE44B26EE7AF744A6ULL, 0xBBA2F2650B65378BULL, 0xFA3BC73B12D4D339ULL, 
            0x3DFF0DAD37AEABABULL, 0xDF2D6311416126D5ULL, 0x0798A300A78EAC05ULL, 0xBC8374D154405D7DULL, 
            0xB7438574DEEF251DULL, 0x6C386F94E1285012ULL, 0x6CCD3ED35B758C8FULL, 0xD411E5F82FB1F7E4ULL, 
            0x6AC53653C19175F3ULL, 0xAB296A573854AABEULL, 0x72BB2116CA9D660DULL, 0xA4169BC5D542D8EDULL, 
            0x86238FFA70788618ULL, 0x28051D61BE7C3663ULL, 0x934C11AA4D345AADULL, 0x1E690C4730C9090BULL, 
            0x09F6327CEA5CC116ULL, 0x4951866D084676F6ULL, 0x28F28F675722FCB9ULL, 0x382D151B8D8B6299ULL, 
            0x9E13F0D02804E940ULL, 0x7DF0DEC3A51A558FULL, 0xC2EAAE6F972E63DBULL, 0x108F918F1880F87CULL, 
            0xB85B5B4E901930D7ULL, 0x8CDCD2AE92480A8BULL, 0xDE18DDCE4112A409ULL, 0x7B03F0720A074923ULL
        },
        {
            0xFD667DA9D2FD83E1ULL, 0xF1F47D6F9D3AF798ULL, 0x2513C694845E4820ULL, 0x156C0AEED5ED38D3ULL, 
            0x22C624BC7A823733ULL, 0xD0D7BFF679BF7074ULL, 0xC6FBA8A136768169ULL, 0x78035D1B851A960DULL, 
            0x57B67410F7ACBF31ULL, 0xA4D6B89FE3C17CCEULL, 0xE8E79462D8CD7A27ULL, 0xAB7D45D9130443B3ULL, 
            0x46483C3877A83D9CULL, 0x88194FC2413C6683ULL, 0x4F65A00744DF883CULL, 0x98AEAEAEE97A949CULL, 
            0x18C1E903FE3CA7D4ULL, 0x1AA20938EFD27D8FULL, 0x2E130F60F9AF1038ULL, 0xBC0BE478EB2FE2CBULL, 
            0xA3D02C6D9896FD66ULL, 0xB84D5BA1AEFB0556ULL, 0xD12B0127BA906764ULL, 0xBCED5C1BF491E7F3ULL, 
            0x4E11AF7DFD7C0D69ULL, 0xC505EAD7BC9D79D1ULL, 0x0DDEB50C68B4725EULL, 0xE04C6CC3ABBC07ECULL, 
            0xF4A31256901C192DULL, 0x060E4EE96DAC7226ULL, 0xFF83C23B4FF5C735ULL, 0x539030B921AA1C20ULL
        },
        {
            0x2646525EF4ED538AULL, 0x9168C42738F8A492ULL, 0x1C6EE6B789E95E4AULL, 0x80681BC0519551B9ULL, 
            0x44F711CC8A723341ULL, 0x606D1B9F71CFFA31ULL, 0xC4237FA049C3412FULL, 0xD15904D69BD2AAFEULL, 
            0xBED1F2B8A5A175D6ULL, 0xDA7138422F944278ULL, 0xD75AC12083ECC4E2ULL, 0x393EA8AEC4A396B3ULL, 
            0x26BEB0ACE6C37708ULL, 0xF64ABCD7EF2D21F3ULL, 0x10495D38B5D83BC8ULL, 0x3E124647FB05B7F5ULL, 
            0xCD00A988DEA7CBAFULL, 0xA6B762273879B012ULL, 0x7CCA92E5453CF57FULL, 0x7095B21BDCA4EE4DULL, 
            0x39037A1ABA0CFFF4ULL, 0x51AE63DA58A07EE7ULL, 0x3F74507348367FB8ULL, 0x50C2000FD649AB3EULL, 
            0x6D7100CC832AC9AEULL, 0x84AB992479768141ULL, 0xF2A3FD4421B56215ULL, 0x8600BBF0679A462BULL, 
            0x44C3DDC8C8974991ULL, 0x4A3793204CB4189EULL, 0xA70197CD9B2A0554ULL, 0x66FBE59AB1F3D252ULL
        },
        {
            0x98FE772A3CD4B400ULL, 0x5CBA0F5C8FBE89FCULL, 0x535EFF7A51C942D3ULL, 0xE54C0F286A05F6B6ULL, 
            0xC52D6A256C14DFE6ULL, 0xBB30426EA8BD8B1DULL, 0xD155DDCB278AD01FULL, 0x4ACAFDF491A9F769ULL, 
            0xFA21D3C5BAF8CE7EULL, 0x75B0C286B5662B25ULL, 0x11103CBB2551BA7DULL, 0x07F119275C552AE6ULL, 
            0xAA3E4A7364C3DC2AULL, 0x31036CC0BF0F75EBULL, 0x3B4E3BFC873FDC53ULL, 0x8D87A2A4C3BC8812ULL, 
            0xF6E8296B070CEF2CULL, 0xE38A9C61343B8381ULL, 0x0889D88427515BA7ULL, 0xD6212310F512FED8ULL, 
            0x3040B18E903A7C42ULL, 0xDAD16FBBC967BF0EULL, 0xD0F6ECEB6CB4A412ULL, 0x8952717D38C9E5F8ULL, 
            0xC9B6326E6234B85CULL, 0x119CC5B5385D084BULL, 0xC66EF49DFBE3358AULL, 0x52E880DB70E7EF65ULL, 
            0xD10D24F7C26E8256ULL, 0xBF72F9A102A7CF5AULL, 0x70AC3F93EF348635ULL, 0xFC4F96DDB8C44B4EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseDConstants = {
    0xE80CEAD61DD1A20DULL,
    0x0E85654FC97DE83AULL,
    0xA1B620ADB643E255ULL,
    0xE80CEAD61DD1A20DULL,
    0x0E85654FC97DE83AULL,
    0xA1B620ADB643E255ULL,
    0xB0572B806D98CE22ULL,
    0xBE830D6BF1ED464DULL,
    0x05,
    0x86,
    0x6D,
    0x4F,
    0x65,
    0xBA,
    0xAC,
    0x9A
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseESalts = {
    {
        {
            0x88AB525B11FA57EBULL, 0x4B2E5A9E109CC023ULL, 0x7501217987F894D2ULL, 0xAABFB9B7E68C9939ULL, 
            0x8B2D341651059C06ULL, 0x844516162647A85EULL, 0xE0DAB0877AB679F1ULL, 0x344C5D7520D49F96ULL, 
            0x065826FD68B8A5BDULL, 0x16A8BE7F4DE39273ULL, 0x24B4A9186D16555AULL, 0x9B177F81F16928EFULL, 
            0x627ACDDB83DFE137ULL, 0x22EA6C8E2453784FULL, 0xFE55AD3E2A0B04EDULL, 0xAEE12E2CB0660CAFULL, 
            0xF090DF202AC7E05BULL, 0xAE0DDA81AF0017DFULL, 0x194D00D2A174BBA5ULL, 0x2382337A63D9934BULL, 
            0x163DCC042A9D1A58ULL, 0x1728FEC3CE9186C8ULL, 0x3370BE9698503F87ULL, 0x8E5C10807DF19807ULL, 
            0x3DAF093BD82A7E0EULL, 0x0BFCA41F6897AD08ULL, 0x380C3578FC985914ULL, 0x38A09BB50B5757E6ULL, 
            0x95594A187054BE35ULL, 0xC733220B5B7C6CBEULL, 0xB1C086F32FA09072ULL, 0x540D27351A033190ULL
        },
        {
            0x53ED69569B6366C5ULL, 0x3E232D07964272B4ULL, 0x8E09AF9DD4F93852ULL, 0xA3C060F8139D35BEULL, 
            0x4B79C6D9D5DC5FA9ULL, 0xB46801F669770EB0ULL, 0xFC5EC112082A030AULL, 0xEF9180F947A81508ULL, 
            0x2AAADF2AB7FCE90BULL, 0xCAD0B8BD3E1FD54FULL, 0x0713C5F9C8D2EDC3ULL, 0xAE37A0B87952BA53ULL, 
            0xA188D53F41B7172FULL, 0x0F7CE3FEF2D9F482ULL, 0xA410A4DE71FDC568ULL, 0x59F3963AF7723830ULL, 
            0xA071E0A15063F934ULL, 0xE2BCB59DD10F4857ULL, 0x1B62D5BB7FB71507ULL, 0x5BE2DCD7944A3A58ULL, 
            0x892DDF1F6C57B429ULL, 0x83B86915352196C9ULL, 0xFBEB22684ABF7CD2ULL, 0xCD4BEE9A14C1C764ULL, 
            0xAFDEBF0644F1CA02ULL, 0x61FC3A1BC1B62705ULL, 0x919D61261371010BULL, 0x438F56145E51F9D1ULL, 
            0xB08739A3D014BF1EULL, 0x88563AA4D70E55B1ULL, 0x011BDE0BAB01ABDBULL, 0xA08C7385EA79F462ULL
        },
        {
            0x49CB747709B6FB4CULL, 0x1236355FF75CDB4AULL, 0x2E5A9DD2C20BB6D5ULL, 0xD1B61E85CD3101D5ULL, 
            0x53257878EE4B851AULL, 0x03F7F833DBDA9494ULL, 0xE4EDBB551285F32EULL, 0x5E09483D47326BD3ULL, 
            0x2769B8F4DBCF3345ULL, 0x280AA1A39A7B00AAULL, 0x8F4ECD2E9D0DCCF7ULL, 0x5CC36C15E6166487ULL, 
            0x4490FF4D0C4EADE7ULL, 0x74728389EB951E28ULL, 0x0DFD503CC0398D1BULL, 0xC274C10ABF16B5ABULL, 
            0x1CEE583704022B4AULL, 0xFECB1EE018C3CB37ULL, 0x720E20ADD4E89203ULL, 0xB87E2C339AAC6E64ULL, 
            0x5BE1F8FBBF4A8F21ULL, 0xB7277A3E046390BBULL, 0xB0945AE829BBEBCCULL, 0xC29EE92A0DDE40ADULL, 
            0xF221C86ED8C5FA71ULL, 0x920EE4495A7EBA41ULL, 0x08838787F46D5C37ULL, 0xFB754C575BA4C67AULL, 
            0x6C750003181EDBCEULL, 0x21C26F70F8C13B66ULL, 0x592C6BE74E026E24ULL, 0x3D02F1B5F779898AULL
        },
        {
            0x9F1F81A1E1E13B0AULL, 0x64CC6EB494B13B4DULL, 0x371DDF0DA8180F6BULL, 0x3355560DA0497B9FULL, 
            0x31766BF8ACEF5597ULL, 0x29CE9105D946EF07ULL, 0x9D04432DF332B46CULL, 0xBAF6CDEDD1B5C7C7ULL, 
            0x95416B07CFAE342DULL, 0x20673D7E3700BEFBULL, 0x0633371AF587237AULL, 0x4A12A98FB2D76B5EULL, 
            0x60E79FD6AD4B0A40ULL, 0x539B9FDFF1E9306DULL, 0x423132ADB294AABAULL, 0x0C7DC7E57AFD9AB9ULL, 
            0x1479C87D10F45C17ULL, 0xFDED721D5431B2B1ULL, 0x827C25EA60C3C4A4ULL, 0x3B346E508CE89DD0ULL, 
            0xA1F839376837CE1CULL, 0x023C2613E283061CULL, 0x111B7E9DDC61EED9ULL, 0x03B204FB999A3880ULL, 
            0x6F6DF3BBDD894BABULL, 0x58C1C6F114ED5541ULL, 0x47E49FE799686D6FULL, 0x039DEF6838AE691EULL, 
            0x5AA373B91C32DDBCULL, 0xEEC6CDB8C369FC28ULL, 0xCFDFDA2739AEF03EULL, 0xAE647EB07698B79DULL
        },
        {
            0x5CD1E9EB62032488ULL, 0xE7A29D09BCB0559EULL, 0xE2A9CE212F07C8C3ULL, 0x0767766FAADCAA30ULL, 
            0xB21FDBE0F829F45CULL, 0x5F66454DAE34720AULL, 0xB3BD9771C1B4F471ULL, 0xB7ECB2D8587F6797ULL, 
            0x54BF275B1F73C913ULL, 0xF73606AA84AF2865ULL, 0xA9CE1E05C00928A8ULL, 0x535D39BE0A89E6E9ULL, 
            0x226280B9C512FE19ULL, 0x2178F9CAE9BEADEEULL, 0x3C9EA274FE8B5FD1ULL, 0x391F0037C0C2F2A5ULL, 
            0x62A8FEC8B23B8796ULL, 0x48511A1FE0E74201ULL, 0xCDC9713168F5FC04ULL, 0x94F2B0BDC99117A5ULL, 
            0xE40EC2415F6CFD6EULL, 0xBDEB8A623BDFE3F7ULL, 0x3632102824593BDBULL, 0x309A77B1483CCD92ULL, 
            0xDF9F4A269C2EAF6CULL, 0xB5376F157D037F95ULL, 0xF9003173EB4ACA0AULL, 0xE9F9893910014D98ULL, 
            0xBFE582F3D24D541BULL, 0x64C860B94A7ACD97ULL, 0xB316366B9FD7E17DULL, 0x7FDF43C3303647EAULL
        },
        {
            0x870D5F2047F2BEF0ULL, 0xD8B73066BD04CEB3ULL, 0x6ECC44DE7EA6DDDEULL, 0x811373E00FDE4DC1ULL, 
            0x4EBDC0E2B4DCA20CULL, 0x9EAB574E82552AF3ULL, 0xF52CE31C6E781600ULL, 0xDCBB8B1BEA35C1C2ULL, 
            0xABCC41BB5934E44DULL, 0x1CE04C51D246E02DULL, 0xD33809C2200A3FABULL, 0xAA929FF211DE69F4ULL, 
            0x65CA14344CFF810AULL, 0xA488BD94D39E83A2ULL, 0x0B90890525D0CB7AULL, 0x68AA04BA24BED8BFULL, 
            0x1E4120815530EB2DULL, 0xDBF32526E6C2759CULL, 0x8A4D133A13697804ULL, 0x99FAA07BDF652A64ULL, 
            0x6A8375F7A2DB57C1ULL, 0xEBA9FE8DB44374DBULL, 0xE7DD3ECF6D225890ULL, 0xB42B7846A9D83534ULL, 
            0x2B073F15ACD333ECULL, 0xBE9552FD9551CDD5ULL, 0x9164A6A71CD5F5C3ULL, 0xA602585F14E4110DULL, 
            0x28781082FAEBFFC1ULL, 0x81F4E6273B6AAC5FULL, 0x15971D77F1796A17ULL, 0x2DC3817160EF85DDULL
        }
    },
    {
        {
            0x56E5ABA6CAD160DFULL, 0xBD65BD2C776F6609ULL, 0x3C1280EC276ED06BULL, 0x52010632A9243571ULL, 
            0xF4809CB8CEEF6649ULL, 0xA5B50CC36C466EE5ULL, 0xF89BFEDB5C506DE0ULL, 0x825A8C5D256C5715ULL, 
            0x243ED607232FDDAEULL, 0xD5D41A40B4E875EBULL, 0x8290EA3602C7BECDULL, 0xCD20E89F4842FC71ULL, 
            0xC095A4658993C8E2ULL, 0x92A2F57B534F19CDULL, 0xF6E4583866C71A1CULL, 0x20E7CC5E7C210778ULL, 
            0x70AB6D99DC2FB6CEULL, 0x9CAFF93C9DF1C2DAULL, 0x7572E8685615F7D3ULL, 0x64E34D495981B5CBULL, 
            0xCB71B39292A85AF6ULL, 0x76885752042A7745ULL, 0x56313BBE5E05EC94ULL, 0x8223E76279EB636DULL, 
            0x139181187CE13FB3ULL, 0x36B0BA3B928AE95BULL, 0xF59F27498E4E492FULL, 0xA34093147C3C4D94ULL, 
            0x4F2F1E7E63E6F6C0ULL, 0x01B1D832791EDB2CULL, 0x12335AFCD5B0E3C3ULL, 0x515C56A2409694FFULL
        },
        {
            0x4D169CA661D5EF3DULL, 0x3288E7D76B6468CBULL, 0x0ABBE6C8D17AC7CDULL, 0xDCEF54D269894F23ULL, 
            0x74670FE4E697C3AAULL, 0xB118E6AB40C4FC0EULL, 0xBE7429572E242A5EULL, 0x249C18D3960F816EULL, 
            0xCF5824F662730587ULL, 0x4A23683D5A1D5BE5ULL, 0xD3A9A11C282EF733ULL, 0x3337A75F74BF09C4ULL, 
            0x8F8555BB78555AE7ULL, 0xAB305A04484C0560ULL, 0x31895C9F8B87086AULL, 0x26D55D7985F2874FULL, 
            0x7E3C4160D693946EULL, 0x34FACBD4DC81D628ULL, 0xFB68BB73FE37C317ULL, 0xC4C9AD8646F652A8ULL, 
            0x4ADE54973F956E41ULL, 0x33BD577325FB0C7FULL, 0x59D243B3F0C34FDAULL, 0xBA315236A4E91900ULL, 
            0xEAB3CF05153AC39AULL, 0x1F493872117E527CULL, 0x27CFD908993D723AULL, 0x15ED5F10FED3298EULL, 
            0xF08CE648B4F5D89DULL, 0x112AD78349111BF0ULL, 0x957A81591675A5E7ULL, 0xBFC3FD5C361BD79DULL
        },
        {
            0x0C6637C9039C6188ULL, 0xD2E9036977EAEFBBULL, 0xA04C5853B471011AULL, 0xF3F83841DAF92BF6ULL, 
            0x3E4907D28DB43F21ULL, 0xE25D2AE5C68B1ADBULL, 0x59FDCD79169F1BBDULL, 0x48C614E4BE005074ULL, 
            0x84A036ADE99021BEULL, 0x80A268018C8C7F80ULL, 0x6F02D6D67095E165ULL, 0xAF7984888D12CA6BULL, 
            0xA474A517A7FC15A3ULL, 0x9AE37CE07C925FE2ULL, 0x4F6237CC7F5A8CF2ULL, 0x9B996E80F584B417ULL, 
            0x07A4F934AF31BC93ULL, 0x4396A5ED115964E0ULL, 0x1ECA5B4A8E18B7BCULL, 0x829AD5F0ABEC70D3ULL, 
            0x040AAEC440784732ULL, 0x0BC765DF8415EF99ULL, 0x2A3C010E8DD1EC7AULL, 0x8DAA6C4176FB4F75ULL, 
            0xA1DEFF176B40B518ULL, 0x34B8ADA21D59F801ULL, 0x7ECD8E1B71C58EA2ULL, 0xF6BD9838C99E7B3DULL, 
            0x042E638550E58915ULL, 0xBDF29873F7ACE41EULL, 0xF4989C47BF993062ULL, 0x5CF1CE5915027215ULL
        },
        {
            0x2F3C41DDF786C9EEULL, 0x3ED34213B0965773ULL, 0x2F6F052038A1DE18ULL, 0x50056C3013839609ULL, 
            0x55A04877BC9B09A3ULL, 0xAAD1EAAB54258E7BULL, 0xA094F636443D9484ULL, 0x540C3CDCF7396183ULL, 
            0xE4BDC6E5B0F3BF64ULL, 0x0FF1099A01EF6AABULL, 0x1EECADA170D0DB33ULL, 0xE7A20FDB334663EAULL, 
            0x01CDA2995AFBA51EULL, 0xEC3D28195423432AULL, 0xE96CF01BC5B728B4ULL, 0xC2A72159A92C9EBCULL, 
            0x1C0E66B623EE6054ULL, 0x87974799FEA1F69DULL, 0x28146E1C300AAC2FULL, 0x3969046C8EF2507AULL, 
            0x45DBEADEFBBDC189ULL, 0x270AB60A996DBD0BULL, 0xD6249EA5F4566E47ULL, 0x29B02BC9ED0467A5ULL, 
            0xF6CE06E3C7E47ECCULL, 0xF57036526ECA8737ULL, 0x41541B46BA42435DULL, 0x149E5413BFA3294CULL, 
            0x75D455B12784066BULL, 0x514933E294D76E94ULL, 0x061F49188410D5A9ULL, 0x213AFCDE90E08C1DULL
        },
        {
            0x782549E2413AE26CULL, 0xF3AE8D7D26EA3A74ULL, 0x418F74C5D66B7A94ULL, 0x1DF57EA1E5F86A4FULL, 
            0xC4796FD79D594BBCULL, 0xC91D5613EA8B6953ULL, 0x509F647E8A132A25ULL, 0x1A1DC3C880436B82ULL, 
            0xC240A4729317A0A0ULL, 0xC084F46CF454A36CULL, 0x0A121628B97F35F9ULL, 0x7F75FAAD0CE4340CULL, 
            0x1D08B2432A708086ULL, 0x02E839D80CAF616AULL, 0x23D9027217B67323ULL, 0xFBF785D9006252E1ULL, 
            0xFA119DDB58164E77ULL, 0x9AD9E841CAF7D74AULL, 0x7F382B30E86BEFA5ULL, 0x991686AED0EACBF5ULL, 
            0x0D896C38BAA746D4ULL, 0x54BAB0C8938E2EEEULL, 0x2A9413A65B49759FULL, 0x1A57298C4819AB64ULL, 
            0x48609406C608506FULL, 0x8B2A335AC6C83B9BULL, 0xE90A8932071C32D6ULL, 0x08D4029672EC6CDFULL, 
            0x7783A07C01C6E121ULL, 0xD4EC8C32207BF0E5ULL, 0xCB142BD64B9AFE27ULL, 0xA51D5F7E10C5014FULL
        },
        {
            0x645607C43A165179ULL, 0x3E93CA9187AC6839ULL, 0xF207E2447864600AULL, 0xEBEFECB962849813ULL, 
            0x6B4F9C2F37CAB9CCULL, 0x6B135F5833DDE572ULL, 0x9D4D73C4C557860DULL, 0xE62B2ACB43FFB645ULL, 
            0xC1C5A0DA745F6853ULL, 0x705FE6561B9836C1ULL, 0x4E973EC747460C20ULL, 0x5286C9E2B2F272E3ULL, 
            0x82CC7818FC4FE875ULL, 0xE57977BC4FD630C2ULL, 0xF91A276FDC2D3AC4ULL, 0xE0039DE1940F2FD3ULL, 
            0x4D0517EEFBEB54F2ULL, 0xF74D904CC8FA8FDEULL, 0xA0C29700B4749157ULL, 0x15BD0482C6ADB538ULL, 
            0xA0CDCDD70E7D6AE5ULL, 0xEDA431E9603FAB99ULL, 0xA42EBEB6DB215650ULL, 0x33A84BF7A881B5A7ULL, 
            0x1AC8F7455934970EULL, 0xB611B00967AEEA28ULL, 0xA368EBD7BF655275ULL, 0x5C8690F08B6D9A7EULL, 
            0xF7BDCFF2BD03B0ECULL, 0x76109A5CE730494DULL, 0x533BDFC724C5D8F8ULL, 0x9B28E5A21EEFF64BULL
        }
    },
    {
        {
            0x4DD70A52B41DEA49ULL, 0x0FE247A025DFFDDCULL, 0xFE173B146CA1752AULL, 0xFC1E05A2EB9176F7ULL, 
            0x9BC2EFD94297B684ULL, 0x83BA0536B3A28C9AULL, 0x7D6343F596F2BDE0ULL, 0xF4116D7818F7E05EULL, 
            0x8EFB6493B9BE6B83ULL, 0xB143B886C2966E11ULL, 0x8B722F1438D9BF2BULL, 0x98D9C51737B7948EULL, 
            0xA03B53DFD60BE174ULL, 0x92B80A0CD190D243ULL, 0xBD3EBE43306C4CE8ULL, 0x5D4895478FC051D4ULL, 
            0x9041C65D621A3266ULL, 0x1F400AAC2874BCADULL, 0xCDF6F10E76CA0446ULL, 0x799A3FCB773D1087ULL, 
            0x84EA4DED4531BEA4ULL, 0x8012067391F23E70ULL, 0xD13FEED8E3D07F9DULL, 0xB27589DF1DA129D0ULL, 
            0x6FB0E5CBFA09FD9DULL, 0x86ACACDAA6455AE1ULL, 0xFCCC51C6C0B26041ULL, 0x6EC854386DFD2B1BULL, 
            0x4C7AAF1147002FB5ULL, 0xDCAD06CF0DF3AF36ULL, 0x02FD1ECAEDAE208FULL, 0x958579509A43E081ULL
        },
        {
            0xCB4C27230B98EC55ULL, 0x684E051BC44C79EEULL, 0x6ABADEB6E416DBC6ULL, 0x061E4730F8635700ULL, 
            0xB91F4A7237957F0FULL, 0x9329CFF357EC223AULL, 0xE2E1E3D5A216175FULL, 0x9FE9032C885D0E35ULL, 
            0x1CD236106844C8C0ULL, 0x532E8130371B6072ULL, 0xC764398C5EA8D317ULL, 0x2E19B67BD4B9DC0FULL, 
            0xFD175C2B68BF7352ULL, 0x9697F7DBCA62D45BULL, 0x7EBAFFC02B86AD5EULL, 0xB411D91512A03AE1ULL, 
            0xC49452DA82B5461EULL, 0x324101A40CE86753ULL, 0x28DE2445CBD1DF93ULL, 0x0C12F10A7B5C0BB9ULL, 
            0x91B29CA9BD160AE0ULL, 0xD991A5D50CF47518ULL, 0xC88D14B72F43A16EULL, 0xF39978E558F3B8DFULL, 
            0x2CC71C9E9DE1E54BULL, 0x5490C006DD903A3DULL, 0xAD904EEC56983C81ULL, 0xCD7440DD8DDF2833ULL, 
            0x71CCBF348FFFC34CULL, 0xDBF1FC3143B78801ULL, 0x7F1F32D6B992623DULL, 0x7FA88545B1981587ULL
        },
        {
            0x1B2371B914D50820ULL, 0x848DC796089DF195ULL, 0x437A095B078C0BA0ULL, 0x012B9EFB5B0FB750ULL, 
            0x774D94C7CF681F5EULL, 0x78DBA1F6BE78A83DULL, 0xB899F3C05214432DULL, 0x417102799B78890FULL, 
            0x15E45B31CE0CA8F2ULL, 0xCE00FC2256AEA2B5ULL, 0x8AB3E1C90C7919ECULL, 0x8DB6B403247F389FULL, 
            0xF8294C25E1FA53D2ULL, 0xFB024D25C04EAF95ULL, 0x5F91D7466E914171ULL, 0xA662C9CA8DD2BA4EULL, 
            0x6C210D4BDC3F9ED7ULL, 0x3D891E3223AC2E7EULL, 0xEB5C022F8DFDA47CULL, 0x60BCC005C939CC56ULL, 
            0x5BA839161FB64813ULL, 0xC4DB2E123904EB23ULL, 0xD86C12436CB7E0A6ULL, 0x2AD983AC18E7526FULL, 
            0x8471C5311375A15AULL, 0x9CFB3E34D5B04932ULL, 0xD3B3A80A19364A85ULL, 0x574DBC576A0593D2ULL, 
            0xBE22932D4D15D81AULL, 0x9FEDB88DECEA7EB6ULL, 0x4E8B5119FC25B631ULL, 0x1F3D198876CEE852ULL
        },
        {
            0x53F00BA84918AAF6ULL, 0x5B12B9B335643659ULL, 0x1F6DA7F1E301D1DCULL, 0x6A7BC41EE6E6EC03ULL, 
            0x2BCC620EE44B9FF6ULL, 0x1ED1152DC0A9B277ULL, 0x1B0B49D5FC7D4237ULL, 0x26129907488857E8ULL, 
            0x0BD2400F2E38665BULL, 0x1EF1648332EC9ABFULL, 0x9A49A6A40F2CD36DULL, 0x8B7CE6D6FCF4452DULL, 
            0xEC51D2C72C813FE2ULL, 0x58982B8391364380ULL, 0x35FCBEB8314542E3ULL, 0x025EAF7B8E1DCAC2ULL, 
            0xD3EB863B3D7243CDULL, 0x8084D11CF341E7D9ULL, 0x5390ACD2F1DC64A6ULL, 0x8D9E407F7DF1922BULL, 
            0xFF3B2B2B9F6888A4ULL, 0x61DCD1B51BA373AFULL, 0xFBDF82881C956BDBULL, 0xF0899F072E421D23ULL, 
            0x90DC8E51ADFA9DBEULL, 0x6E97901B8F79842DULL, 0xED59B6CCACA7265AULL, 0x497944A1E8FCB55FULL, 
            0x0E390BE97A4DC34DULL, 0xB7D4D7E0E32037F0ULL, 0x5B7E3EBF1FA04CBFULL, 0x1785C4D6275C0A68ULL
        },
        {
            0x799786262DD0F416ULL, 0x4A66FB86E260B88CULL, 0xAE1488554AF56A5AULL, 0x3EEF12308673237FULL, 
            0xCE327ABD0D160A50ULL, 0x5A779528088A2BF2ULL, 0x0AC623FA5A1198B4ULL, 0x4A66E2991D644108ULL, 
            0xF3F7C1DC37A35A79ULL, 0xB6F99F853A070FEEULL, 0x7C0D61D1A640944DULL, 0xE9F9B09F9D3C386FULL, 
            0x75CA9D0C91956BD3ULL, 0x6EC5488D3CB252D1ULL, 0xD051D9110E81777BULL, 0x69EED40A4B373973ULL, 
            0x0540A7205EB980E3ULL, 0xD2C72B6BD6D3C5A2ULL, 0x5ABB61608AEECAAEULL, 0x7252260C7FE9C716ULL, 
            0x9FC3D214D3EBD596ULL, 0x61A4FD8AB1C7A7BDULL, 0x45E64820459D29D8ULL, 0xC5A3FB7F0C417A92ULL, 
            0x351B75EA4448E4B7ULL, 0xD29E784E2ED9FE59ULL, 0xE6EEC28C8CFD2DC0ULL, 0xBA8597B3EB960BD7ULL, 
            0x0B42C9A22BE2854FULL, 0x560FF3D0C090BD8EULL, 0xAC839A027E6C0F0BULL, 0x6BA81BD8F1B0AF41ULL
        },
        {
            0xC80AC75D8BF50F39ULL, 0x8BCE4EEA8C10C4D6ULL, 0x69444B6EA3C764B7ULL, 0x2FB638ACD2D785C4ULL, 
            0x1BFC91C108603F21ULL, 0xEBCE4707B2CF8A00ULL, 0x2EC55412F3FA6232ULL, 0x41CFDD3DA48DED06ULL, 
            0xF55DB256472200CAULL, 0xC37D23D573A04B31ULL, 0x65D380E7B7279EA6ULL, 0x3D23B00BD4D32788ULL, 
            0x4B81619C00C98A4DULL, 0xF08527BF18394677ULL, 0xF78D902BD1C9F7BDULL, 0xCC6440868ABCBB5EULL, 
            0x4E71E04CAFB3C4F2ULL, 0x976A8FBC5A3F992BULL, 0x9858398A837DB5BCULL, 0xD9A69BAE3B4484C8ULL, 
            0x4925DDDF231DE4AFULL, 0xA66D497F1128D265ULL, 0x94047065D8EB8BE3ULL, 0x6E6A32E7FD23721EULL, 
            0xD1FE59F9B3F919AAULL, 0x8D6B2B2A13CBE792ULL, 0xD346AE6D040264BEULL, 0xA2FCA99259D89758ULL, 
            0x180E61EDD11D78A6ULL, 0x55455B7C0BA5B256ULL, 0xF7E276BA2951997AULL, 0x0466D31191932E02ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseEConstants = {
    0x615C74E9CE452D3AULL,
    0xDF9E8E7165F036C6ULL,
    0xE0D5EA6832BB476EULL,
    0x615C74E9CE452D3AULL,
    0xDF9E8E7165F036C6ULL,
    0xE0D5EA6832BB476EULL,
    0x75E29555F44FE2B5ULL,
    0x904B4FA265C3F30AULL,
    0xE0,
    0xB8,
    0xA4,
    0x59,
    0xA5,
    0xA0,
    0xD1,
    0x35
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseFSalts = {
    {
        {
            0xF355AEAF65BD8306ULL, 0xAD0A95EDA195252BULL, 0x044167B2B1E8BD22ULL, 0xED1D4F1C41BF23C9ULL, 
            0x9CCC481EDDD20F9CULL, 0x19CC4329D63A9DB3ULL, 0xB6324321E4C976AFULL, 0xA49A73AA6AE340CEULL, 
            0xBC40FB2EA71E91E7ULL, 0x09E83193CD43B233ULL, 0x19E5A827B1C99945ULL, 0x64D3DE5868AC09A8ULL, 
            0xFAED1BAAD254CBDAULL, 0x35F4F7E62EDF8381ULL, 0xD885351095463D16ULL, 0x788532DD12B1ABDCULL, 
            0xE84B995E5AA2D65CULL, 0xAEC85CB3CD6ABB67ULL, 0x8EEE7FF78C8DDB62ULL, 0x5464D72E831D5B62ULL, 
            0xF83439DE60512235ULL, 0x923D4F375C4222CBULL, 0x0E16439D6AF866E5ULL, 0xBB938D4B35DDB6F2ULL, 
            0x97D92DC5A3F87698ULL, 0x7616C1E09F97D8BDULL, 0x9100D0243CDDC381ULL, 0xB903015951C380D5ULL, 
            0xB0A70960D7C12A69ULL, 0x4303B112B4B53CEFULL, 0xA0F518E686040DB7ULL, 0xCA8018D5C9F4070CULL
        },
        {
            0x1A202A42D365B451ULL, 0x4B3CCCA54FDB65DAULL, 0xEB0E43D00B63812AULL, 0xFCD8B69562B6A266ULL, 
            0x4433874E0E70A912ULL, 0x53BCCC559B1B5B8AULL, 0xBA52238FF110EAB7ULL, 0xDAF41EA26A237046ULL, 
            0x26067A42614D5ECDULL, 0x7BBF0678418BFFE9ULL, 0x72BD5D2A10098451ULL, 0x5482CFF4FF8239F6ULL, 
            0x70970086F28BD48FULL, 0xE9872C163F80D7E1ULL, 0x7E6FCBC946DA03A4ULL, 0x76A82D9D3EC3E47EULL, 
            0xB0AD4A5EC4EDB5C3ULL, 0xAE6C18A25C7E9D20ULL, 0x5A8118A619519404ULL, 0x6D47001C087ED88BULL, 
            0xCD947E1BC2D451C5ULL, 0x882AD435D8038100ULL, 0xAD42530F97D77117ULL, 0x0F92501022D0DBBDULL, 
            0xC38DE2C89C8050C7ULL, 0xE94E91841E78A0CDULL, 0xDE60554DDEF11CA6ULL, 0x15F7E7909F6D3699ULL, 
            0x3DD7343B67FC192BULL, 0x2940179C1DDC109AULL, 0x1A23840BDBF5B247ULL, 0x60730EF39C559FF5ULL
        },
        {
            0x60468A35AC56CB17ULL, 0x251FF375BE13BFFCULL, 0x91FDCC565F8AEE82ULL, 0x606B59E1A6A8D2C1ULL, 
            0x375B6D54D2609ABAULL, 0xF679B0EECDAC0140ULL, 0x61A914AFBD914587ULL, 0xED529ACEBE490E83ULL, 
            0x251BEB0EA2412B33ULL, 0xBB7EF0E7A71ECF20ULL, 0xB7E3A4FECE83049FULL, 0xE7D3D9A784D6208DULL, 
            0x8DBD91283BFCF0EDULL, 0xBC82580ED1F93B92ULL, 0xCB11A8FA75C5A663ULL, 0x5FB1EAAE407440DFULL, 
            0xD994EC94909E9500ULL, 0x3B42E96D97733533ULL, 0xB1A67EC0747A802FULL, 0x6A3F6597CD8675B7ULL, 
            0xD36BE3DE5885BD2FULL, 0x32579AE12CFA54B0ULL, 0x2BFB3D9CAF7197F6ULL, 0x548F2CA4112E8600ULL, 
            0xEF824AD64ABE7FA8ULL, 0xAC0B37144BF629FBULL, 0xCC1125111297D58EULL, 0x57A157D15EEE4704ULL, 
            0xBDB43459603728CAULL, 0x7EFFFEE391D1DFE4ULL, 0x21C74FC5F0818E38ULL, 0xE4C8CA3C9AA7305FULL
        },
        {
            0xA40F01CAB2E87DECULL, 0x39B6067B1F4F85ADULL, 0x80EBACE6EA47D7CFULL, 0x7013423AD3C138CFULL, 
            0x0F2362EB9771F577ULL, 0x8A8C2A92ADF95FBEULL, 0xBF7C8C972C5E3454ULL, 0xEE5B6C53D83D8F01ULL, 
            0x214BC55F1ADDED93ULL, 0x631DB2CE8AC5EC34ULL, 0x6C81F46C458D51FBULL, 0x59834F2A1E46F40CULL, 
            0xAC986284A4E4797CULL, 0x046E1458E173038BULL, 0x5AB156C53BB7FD0CULL, 0xD8C5C30708965554ULL, 
            0x20D7E3507B8C2CCCULL, 0x3E89827AE82B4D30ULL, 0x47819E5035174C7CULL, 0xEFBB4BF6531D2972ULL, 
            0x7F68A6F2AB7D5A3DULL, 0xBA8A04156DC1ED1CULL, 0x33B2EC57F72E0748ULL, 0x53900D884BBB5E8FULL, 
            0xB90A4935A1D66BD3ULL, 0x10F21F97E1C884EDULL, 0xDDDB0682F46553A4ULL, 0x59B18442D1D3B72BULL, 
            0x5625AB94CB5D1995ULL, 0x8406A0BF68D2794BULL, 0xB45E5B1FEE5A215EULL, 0x9D623EAD23C67A94ULL
        },
        {
            0x83BDB0CBBCC66D6DULL, 0x20FEBA578CA99839ULL, 0x1120667CD78885F9ULL, 0x4524178149B95EB3ULL, 
            0x7676ECC2085E7C6FULL, 0x145C3848B14CDD97ULL, 0x79EBE8268D9B14DEULL, 0x56A04A958B845FADULL, 
            0x411122A786A0DD9AULL, 0xD617C29801AE555CULL, 0x34D80E8150EEC4E6ULL, 0xF6A7A4630B2AAE8CULL, 
            0xFC95F741CFF691C0ULL, 0x882B6A124E6EE481ULL, 0x5DB9E454ABFB91C8ULL, 0x1D24C514BA167A77ULL, 
            0xA17F45D6F171F084ULL, 0x84DD19BE98B1B865ULL, 0xB0E86492A95F510CULL, 0x1856D8CA760ED151ULL, 
            0xE10B75EE061F63D4ULL, 0xEF95295CD9EDD83BULL, 0x88F04BB38078640DULL, 0xDF3FBEFDE2787C21ULL, 
            0xECE5B7B01D000FDBULL, 0x38B5811B9EA91297ULL, 0xF730093DBE0B4CCDULL, 0xD9BFF7D85D1E8E31ULL, 
            0xC0B6F57B83F2CFB1ULL, 0x2B4A7C67F50324CEULL, 0x696385E95CCF4AC7ULL, 0x62CECED48254DBEFULL
        },
        {
            0x6FF439467774E26FULL, 0x8527174EDBD1F3ADULL, 0x54515E10050BAE40ULL, 0x5FFA09BFF7BCD87CULL, 
            0x1A44B6877D2B9C6BULL, 0xC34704965BC7AC44ULL, 0xE932DEB82D709496ULL, 0x9160D2D8769DBFD7ULL, 
            0x2FC7B835B939BCA7ULL, 0x486953ADB2436250ULL, 0xA2EEFE93FC1C9DDEULL, 0x8831233FFAAFC5B8ULL, 
            0xA1E3BAE3F7383A1FULL, 0x88CD9FA7D969E73DULL, 0x742188B19DEA288CULL, 0x29FE5B862F858843ULL, 
            0x06F5DD6B4AE7B26FULL, 0x790C8BF2CA4B3E12ULL, 0x6AE70C29D5289DFFULL, 0x0010FD6EF0FD1E95ULL, 
            0xA6E22456C273FF82ULL, 0x4AFE8BB270E6A564ULL, 0xC8439A9A81AB3A29ULL, 0xEA9E4C937AC9771DULL, 
            0xB7B24E5EC6DF18C6ULL, 0x2FEACA392EEC4801ULL, 0xA50740DB8549BE1DULL, 0x2273D43F4852010DULL, 
            0xB5E848F2962963E3ULL, 0xBCC5A269AF3F4A03ULL, 0xF7A6A3BE346D1C23ULL, 0xE489F6000656347CULL
        }
    },
    {
        {
            0x24093C5E1022D1E5ULL, 0xC3FCB64F013402FFULL, 0x8E11F8397C6C5F75ULL, 0xBF3EE9E70A7E2940ULL, 
            0x586AE3ABF4949E7FULL, 0x2537D093A03C665AULL, 0xB99E4ACD942E60B8ULL, 0x58583F711FFBBA65ULL, 
            0xE0868BBAE9B89442ULL, 0xABB1C05085E0ED5CULL, 0x9C3981A72CAD42D5ULL, 0xDF63FF627BDA8564ULL, 
            0x279CC3C89BF38202ULL, 0x388F99CAEAE8282AULL, 0xD9C760E7E42E575AULL, 0x5A3323169CE03E2BULL, 
            0xD803B3FA40DF1472ULL, 0x9BFA4C090B0C26C0ULL, 0xC407C0B126005C35ULL, 0x67B54138F772555DULL, 
            0xCB95550F0BC8D58DULL, 0xB385B41B6CA9A6B2ULL, 0x3972603606243522ULL, 0x75BCFCFF64C51C18ULL, 
            0x3BCBA60AFCB72D0FULL, 0x891408DF88F0506DULL, 0x4F71A5605015ED8CULL, 0xA6EEA57460D45875ULL, 
            0x6B53A2AAFF55510AULL, 0x96EE2A446CA31B5BULL, 0xE90ED0AC8FB07879ULL, 0xAFFD43E7882C6C1CULL
        },
        {
            0xE7BD2F9C6AA21C47ULL, 0xF01E39BFFF4FE923ULL, 0x30D9A583864EAC3DULL, 0x8E310F63F9EAA91DULL, 
            0x638BF4C2E3FEEAA7ULL, 0x56DAC76D2B432F09ULL, 0x90889D7C0768A671ULL, 0x1F18F468A21294B3ULL, 
            0xF5B2711E189EE9ADULL, 0xD15A5BDD3786AE3AULL, 0xC572CAF335727FD7ULL, 0xF48A1604E317616AULL, 
            0xB98E70DFD38A5467ULL, 0x6CEDAD555C10E226ULL, 0x9879C5CD487D2C5DULL, 0xBA572DD6C1FD687DULL, 
            0xDC6813D8D0161432ULL, 0xFD2D0F65671AB1F3ULL, 0x2B14E608657AFE8EULL, 0x29A8BCDB5DB88890ULL, 
            0x9715D87210C4CD62ULL, 0x3164DBEF9A45512FULL, 0x0FC90116B48CCA55ULL, 0x63F335D8E0F03C05ULL, 
            0xC61538E7773FAC90ULL, 0x587D942083BFE042ULL, 0x7C052F5DA558CD31ULL, 0x2E5C1CEFF1115BB4ULL, 
            0x296B894761A051E7ULL, 0xA944B5740ECF56DEULL, 0xA3374B80D1E91C6AULL, 0x34A44552831180CDULL
        },
        {
            0xDF48625961D8C334ULL, 0xDF0884FE8642FFB3ULL, 0xE9FDF674E926FB7EULL, 0x2BD87ECBEA3CD67BULL, 
            0x41C020FF68360E77ULL, 0x11DEA67DE0F347BFULL, 0xA77B3DE868530491ULL, 0x506C5C22A561DCA0ULL, 
            0xA6C8E2BF6D61CE59ULL, 0xB99464108F70A5A9ULL, 0x8E326F1C8C9F19BEULL, 0x1E99A1E960B96B45ULL, 
            0x4A699AC2338DA706ULL, 0x884FC09C91873BCAULL, 0xA7B98E825AEEA715ULL, 0x3B64A9F7B2C787CAULL, 
            0x39DAE80D1C1BF4B7ULL, 0x38F758F4F4FB9452ULL, 0xD3FA88F6C35ECF6EULL, 0x225E2A50404B8E09ULL, 
            0xB5B19D3E9B073B55ULL, 0x7B6718009CA708E8ULL, 0x24B06EA38B30D4A0ULL, 0x6B6F1ED0F0D6FEC5ULL, 
            0xB41CB26F06F7E6C3ULL, 0x059AD3ECEF9D6EBFULL, 0x7A7F5842B62BC489ULL, 0xAAF60716FD169404ULL, 
            0x74EFE4A861D37F14ULL, 0x8531CFFAC41C6D20ULL, 0xC0E5514A4AF410EAULL, 0x782D5393C0903A31ULL
        },
        {
            0x048432FD0CF985BBULL, 0x5A84E8A5D1A0136BULL, 0xB53AB8B20D6C41C1ULL, 0x7A8A8ED0C7AE19ADULL, 
            0x9506CF7C0ADA5857ULL, 0x9D13FC5C345595F1ULL, 0x422147898F6E940BULL, 0x494AF2C0FDCD46F8ULL, 
            0x658258E8DBEB27F4ULL, 0xE1A28837E4C20363ULL, 0xC29DFB245903D93CULL, 0xAFE047048D2DE4B7ULL, 
            0x177B0798998B4E48ULL, 0x22D8D0645FB1F7C6ULL, 0xE3D75ABDCBDD3A18ULL, 0x4A78BCEA7DA0AB4AULL, 
            0x5D4DD3539A46F1C8ULL, 0xDAEB413BDC7B10C0ULL, 0xD90FC79F6ECF4DF2ULL, 0x1AAD714A86442B0EULL, 
            0xBD4C02EDCC879D8DULL, 0x5E3C9A3DFC8B2E82ULL, 0x12F58330C4E4447DULL, 0x77C57B52A048A895ULL, 
            0x61114B6D1E399523ULL, 0x26FFAAD4179F7F86ULL, 0x670E7B7F86C17DD8ULL, 0x59C52019DDF14B18ULL, 
            0xCC3F6B064C275720ULL, 0x95656934633A03C6ULL, 0x9AA5C8D6235422A0ULL, 0x01B0E0227AD0A4AFULL
        },
        {
            0x9BF724A20F96156BULL, 0xF4E24E67E4C990F3ULL, 0x132DD5F2EDFBB078ULL, 0x91D621C95AD30E98ULL, 
            0x14C224B761D7498CULL, 0x27286D8B718BDC88ULL, 0xFB61E75EFBE3C852ULL, 0x8BBE237ADC48175EULL, 
            0xC474C2C9C56132A2ULL, 0xEEAA55DEB9A22799ULL, 0x60E048CA60804836ULL, 0x0EBACDB35CCD94D1ULL, 
            0xAF14DAA58BD9FE96ULL, 0xB2464C539F901062ULL, 0x8A4AA488E9092EACULL, 0x531002220F369352ULL, 
            0x232DD9590CBA4665ULL, 0xB2AE04B7216A0988ULL, 0x2536F84DD1C278BEULL, 0xF11AA6EBCDC168B2ULL, 
            0xD747CBDC9104D791ULL, 0x1A7EAC24FDBC9002ULL, 0xF3225C6D91105F6BULL, 0x1C4C03DD48D93911ULL, 
            0xD747CFF5D5698469ULL, 0xA35E35F581FC49CAULL, 0x54D9D269D415B23AULL, 0x5D012A686DE6204FULL, 
            0xDB84AC73EBEAD8F8ULL, 0xD117C5ED729C2A5EULL, 0x6293E363801A9E8DULL, 0x919304A6C816A44FULL
        },
        {
            0x13C4B33801A3EFDCULL, 0x725AE3F66396C7F4ULL, 0x920A10178C3658FBULL, 0xD830B33286A348ECULL, 
            0x6C0DB335ECDB7D2AULL, 0x65B7AF94C1D528EFULL, 0x57270D589AC0D71CULL, 0x79DAFD3320C8C386ULL, 
            0x44CC6C6D1838025CULL, 0x6F8FBB19727BFB54ULL, 0x5F9A5D6A04EBB2E3ULL, 0xB332040BAAF53412ULL, 
            0x550CE7BDC9460B75ULL, 0x84F5AD7B17B75635ULL, 0x8E7957C505C4991EULL, 0xC6DAFE5931CDFAF7ULL, 
            0x7CE4B0E20B23E586ULL, 0xB385EC35107D0B86ULL, 0xE2462D2876EDE852ULL, 0x2CA060384ACB4ABAULL, 
            0xE39771FD7AD8AE3FULL, 0xE7EA03C0BEB50718ULL, 0x476EEB2A4DC4EDAAULL, 0xA878FB87708B0833ULL, 
            0xE22BEFBD8566404BULL, 0x10BC9E099FC526D8ULL, 0xFA3FB766D64A8B34ULL, 0xDC042A5586D1774CULL, 
            0x25FC32CA3F680896ULL, 0x10ABFCDE5891116EULL, 0x03DA99C83DD37253ULL, 0xBF10DD6C21848721ULL
        }
    },
    {
        {
            0x55E410B1E47EE9C3ULL, 0xE4755C2ABAA98AF2ULL, 0x6C33F2044A2CD124ULL, 0x1BBEFB6B0D351574ULL, 
            0xED62FACCA910F2CDULL, 0x00FCDFA18E835C48ULL, 0x80A588EA72104B5AULL, 0x6643259E326E17CAULL, 
            0x38C7B7914DAD759AULL, 0x0B00CEC82D3CA610ULL, 0xD660536081857927ULL, 0x06B3212A2DCFA04AULL, 
            0x05FFDDAB1316D13AULL, 0x0346742A6C6D5F1BULL, 0x50485C41A99A3347ULL, 0x79CF53F457437AD9ULL, 
            0x4C3C778A6A2466B7ULL, 0x6D7255E378E2D7EEULL, 0xE71CC43A02EE02E6ULL, 0xE79CC9388074AE15ULL, 
            0xED1D66AF775B55CFULL, 0xC4842EB0A8DE9E53ULL, 0xEF72D3EE875CFBADULL, 0x076454C02AEF50ABULL, 
            0xED8CC2BCBE432F26ULL, 0x9FCC704F48D597B4ULL, 0xD511244DF0D28815ULL, 0x317919601904DA52ULL, 
            0xD11FCA0AAAC8597AULL, 0x50710E19956B0DE7ULL, 0xBAB2669D8E7BFD53ULL, 0x6A37D2CBCEE34A1AULL
        },
        {
            0x9807C4EE528B7C13ULL, 0xFED3B79FDE007E51ULL, 0xF0F018C77082705DULL, 0xC436132305C7986DULL, 
            0xAA8CB302D420C457ULL, 0x7ABFA7B66E2E6A15ULL, 0xCE1D179BFAC47257ULL, 0xB894381CA7939784ULL, 
            0x5A2F427D6D3BB698ULL, 0x91F56574430C791AULL, 0x3DC7E05ADFBD460FULL, 0x632809A2346CDFECULL, 
            0x54D70F5260489726ULL, 0xDC1198EF5DDB2F9DULL, 0xCDCC9A10552EE228ULL, 0x79A25727B5AEC4B2ULL, 
            0xC9B01FA771076DFBULL, 0x6829BF25AC2F8994ULL, 0x22956B910AFD67FAULL, 0xC08D029C56E8F89CULL, 
            0xEF7CCB118456A4ECULL, 0x705F709E5AB11040ULL, 0x0D4C878DA166A527ULL, 0x1BFE2D3D92DB9577ULL, 
            0x44F689297755B8B3ULL, 0x1AEC7F077DA36D78ULL, 0x99C5703968787A82ULL, 0xB2BD3873428C9B49ULL, 
            0x3A9FEB5DFDD4B8F7ULL, 0x6A0AC2938A92EF68ULL, 0xFA5265E83EBF3A2FULL, 0x4043BA74117DA1A3ULL
        },
        {
            0x2E5B109C2C6477CEULL, 0x83857E6A7DA2E406ULL, 0xBFFEFCE0AD50415BULL, 0x8EB5AE4B06219E7AULL, 
            0x7E78EE6D00CAC01DULL, 0x820E542BBD06B94CULL, 0x27A0AE4EA9CD4E0FULL, 0x973C14405E825148ULL, 
            0x3EDB2D83E1888DA5ULL, 0x95229216F39409E2ULL, 0x34B2573EF705B739ULL, 0xEB963FA17FD91151ULL, 
            0x2B85157152328580ULL, 0xC559F9499C9D3AC8ULL, 0x29F8D4634044BC48ULL, 0x3CB1FB3FCC6BB60DULL, 
            0x2A6FCFEE90F8875EULL, 0xA5AE27B02C5AE72AULL, 0x69143656927BF1F0ULL, 0xFBF03535266F562BULL, 
            0xC5BE423E37039FF3ULL, 0x722667DD693C68A6ULL, 0x26C9D4E193246134ULL, 0xCC85CC123F76EFBBULL, 
            0x76CD6DA3745F0B23ULL, 0xA1D07D3FC1B1A5A0ULL, 0x20D4154840406364ULL, 0x017D5BFDEB994704ULL, 
            0x418E5D7753FE40A0ULL, 0xB9A7CBB9BFFA15ACULL, 0xEC5C9A900FFF4965ULL, 0x5D006D3C3DA0C172ULL
        },
        {
            0x15A50D9A6D8BDE55ULL, 0xB3AB59A75DE9B0B7ULL, 0x98B9AB092D34B54AULL, 0xDFA40B4991C761F7ULL, 
            0xD3250DB49D2332AEULL, 0x29429BE9E0A5F079ULL, 0x97F1589DCE0CB73FULL, 0xD22AC2AD314A306FULL, 
            0x9C5D8BCD0F581175ULL, 0x70EC4D4A92E65F50ULL, 0x1313FB80BC1C8BD1ULL, 0x12E5AE6A712861AEULL, 
            0x91D53EBB931ACAFDULL, 0x584F29CB0688A1B1ULL, 0xAB6C614A12D5B38CULL, 0x78FD714C21CA8CA2ULL, 
            0x366B5727AD2179A9ULL, 0x0928EC06B24B27E7ULL, 0xC12F687A4AB8A26EULL, 0x17F5A08A8899A109ULL, 
            0x252E026F2E487E33ULL, 0xF035415579B101B5ULL, 0xAC228844A4C1875DULL, 0xF7EF8AF4BA8D299EULL, 
            0xD0A07C8263DD5718ULL, 0x464FCC62057B99FAULL, 0xEE4BCD982CCB0EDEULL, 0xE31EEFD9151C830EULL, 
            0xB2A99D7C1C3DA1D3ULL, 0x63673A6D825B3B73ULL, 0xE372E3570E8ACA5EULL, 0x01349AD0A5742AA3ULL
        },
        {
            0xDA3692BAC64EF444ULL, 0xD946C6F6E6A82F68ULL, 0x28A87FB40277240EULL, 0x5857C6D0BA3D4EB5ULL, 
            0x319C011AA2F214DDULL, 0xC9AA36656331018DULL, 0x0F00F2E2EABAAED4ULL, 0x2C4821BA887BEB63ULL, 
            0xD947E90C0338A2AEULL, 0x26E662C7FB17CF92ULL, 0xAB16D59470172161ULL, 0xBD8A66E3CB5044F5ULL, 
            0x3A8D43676CBEE319ULL, 0x3C94C8636A02C44EULL, 0x7D90552747B6F1A8ULL, 0x3FC233C2875BA068ULL, 
            0xE4422918BDE44D9FULL, 0x62B66F683D420A01ULL, 0x485C0F938AE0958CULL, 0x3A542AA4FE0E2A27ULL, 
            0x791600396F74B368ULL, 0x6C7925C1F72187FEULL, 0xB0A69A45288D3003ULL, 0x6E296BEC7B4E4519ULL, 
            0xC2B4EBB134ED34C2ULL, 0x6EC809AF1F10D39FULL, 0xAFC9C364F222A5D9ULL, 0xBEA33DB3D813BFCAULL, 
            0x3F39535A2D153390ULL, 0xAAA033715C429A58ULL, 0xAF123536FB2C657EULL, 0xEE18D435988D4510ULL
        },
        {
            0x812E09C2527C61A5ULL, 0xC3AFE52B0DD61373ULL, 0xD151597A0034B2A2ULL, 0xD175C3B2D448759CULL, 
            0xAB92B85391A8D37CULL, 0x07918C29199E23C5ULL, 0x1E0BDE7BDFDDD0AAULL, 0xB3B5A110CE7BBC61ULL, 
            0x9267C979454A24C4ULL, 0x88520C6D1E4BF3E8ULL, 0x19813C1D4128D1ADULL, 0x5A7A3011D054A5DBULL, 
            0xE705A022EA8D4BFEULL, 0xC624C391FFD7F843ULL, 0x586A4434421A0444ULL, 0x077FFFB7EDAAC0AFULL, 
            0xFE80CCAF61102EF5ULL, 0x59ABF20BE2714F00ULL, 0x7A99DD69101CE8B9ULL, 0xE309E9C4E7172AF7ULL, 
            0x6147389E3D4EFC49ULL, 0x7B1782F567704120ULL, 0x1D12D65B58221604ULL, 0x882AEB890B6C4CC2ULL, 
            0xD485B474AAA07013ULL, 0x369C555B836A8B41ULL, 0x0C19F1B637823564ULL, 0xCE0791DB9CB80BDAULL, 
            0x76A8D0E9FA2B4BE4ULL, 0x966E1BF586AC3D84ULL, 0x2D702CE9B2EF3F70ULL, 0x0EA613055E30645BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseFConstants = {
    0xE6CE4FDF8FB7AD62ULL,
    0xCB255F9D2FE81893ULL,
    0x956A44A67693F6B8ULL,
    0xE6CE4FDF8FB7AD62ULL,
    0xCB255F9D2FE81893ULL,
    0x956A44A67693F6B8ULL,
    0xA86603C5D90F8DB9ULL,
    0x3CAE804F70E5314AULL,
    0x7C,
    0x3C,
    0xAE,
    0x66,
    0x55,
    0x0C,
    0xCF,
    0xCF
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseGSalts = {
    {
        {
            0x063A02F98F5E7B5EULL, 0x218E470CB3DDF30BULL, 0x114947A76A8A7247ULL, 0xABAFE33D70720E4CULL, 
            0x4CC595912079404FULL, 0xA06799DE9A3738D8ULL, 0xC81DD65BB281A643ULL, 0xF32A6B79656A6062ULL, 
            0xE5DD560EFA7B3F3EULL, 0xDF351FE9E2C49195ULL, 0x80507381F8B24EEDULL, 0x5FB93E51EBC90E53ULL, 
            0x46C05EB89E7EFAEFULL, 0x703AFF80A589B8A9ULL, 0x3FD2F23826B6B6EAULL, 0x6D77F290832CA614ULL, 
            0x2BC94BFA37E4C49DULL, 0xFAE85372D7A93D74ULL, 0x4CD02A3BA70DFEBDULL, 0xC0069CDE3B094431ULL, 
            0x57118399A8420404ULL, 0xBD7AF37D80CA367FULL, 0x552BA8982F8DC186ULL, 0xA60D82081272EBF4ULL, 
            0x821799CCBC94D869ULL, 0x2514EB038241AC00ULL, 0x23D285292CA6916DULL, 0xCD7A3DEF807DA656ULL, 
            0x87EEA11DA3535F66ULL, 0x8FE9B549204FDA28ULL, 0x0B976F1892145B7FULL, 0x3642244D0F05A7D5ULL
        },
        {
            0x2CDCB4973BD17A21ULL, 0x0B7FAEFCF7D8FC6FULL, 0x07695BE4BC0B5DCDULL, 0x949D3D3DBFECD354ULL, 
            0x74A2FAA5C2935833ULL, 0x0F8C4D7D8DA4A2EFULL, 0x62033A08B1C1E35DULL, 0xEDDA16DC5723C3E2ULL, 
            0x823B1BB268C51D1BULL, 0xC770C5B32173EA04ULL, 0x7DA276B48BC8130CULL, 0x459167B1691FE23CULL, 
            0x740AF9B057FA941CULL, 0xFB297608C25636A8ULL, 0x47653E113C20C685ULL, 0x7FA0ED11540BE0BEULL, 
            0x2EF2C7BC18D4F933ULL, 0x3F943C17EFD4BB63ULL, 0x8EC1D4AAA48CE515ULL, 0x513C8467ABB14737ULL, 
            0x9028540558F7ED27ULL, 0x9A86AEC12C61D460ULL, 0x775D369FA483CB4BULL, 0x85102E7BCDDB3237ULL, 
            0xC1C23158DA8D1292ULL, 0x876E6730AE2DEABEULL, 0x197CECF64313DAD3ULL, 0x545FE91356E285E9ULL, 
            0x3014ED0B55A3CC20ULL, 0x8EFA61103AC94545ULL, 0xF5EAB52B025C4AEEULL, 0x10D09F500CD3C9FDULL
        },
        {
            0xE7535C81B888808EULL, 0x60B8651B123607B1ULL, 0x313016138858C625ULL, 0x56DBAFF9F54A9140ULL, 
            0x0D201F7978CAE259ULL, 0x4FCF35652029745DULL, 0x22DF9530555CCFD2ULL, 0x9333D8305EBB970DULL, 
            0x093891E417D5E601ULL, 0x059AFFE4C2E8F9D6ULL, 0xF7A3F876A9D3D7DEULL, 0x58CA2C013BD3E03BULL, 
            0xF2371B18DB43AEFCULL, 0x1EA4BFBCE134AF84ULL, 0x83593F4135AD5BC2ULL, 0x2F4666FCD9FC63ECULL, 
            0x946A1D742A5FED7FULL, 0x1F988B9D841E8DDBULL, 0xE981A8CE7094577DULL, 0xF9A5C4D01167B0A2ULL, 
            0x957C0FEACC6CB86CULL, 0x687D53BE965D23FAULL, 0xD035F0A7B6DC2C20ULL, 0x3D109B2D6CAFACA1ULL, 
            0x03050AEE4313B9EBULL, 0x5DB4AFC0707B4DBEULL, 0x355E7291F6F73F05ULL, 0x86639F7F8AAEEF3EULL, 
            0x0A4F1643C5D3CDEDULL, 0xDDB3278741F3826EULL, 0xC3F11F8E0C1721CDULL, 0x7985AEEAD824E7EFULL
        },
        {
            0xD92FB312A1C6D7E3ULL, 0xB4D802E164BAEEDFULL, 0x27A70D4A1212067CULL, 0xC7F04025E4B64252ULL, 
            0xAF872F1E1AD5D4F8ULL, 0x18E8410AFEB0E996ULL, 0xDABD888A8AE676B3ULL, 0xF332A7513001B173ULL, 
            0x04315AC19F35A6F3ULL, 0xD39B90593925E608ULL, 0x95622DC96EA1B388ULL, 0xAD79DF92C8ED310EULL, 
            0x2A197793ECA97325ULL, 0xC3F3E3D8D04CB918ULL, 0xEE9B72092D353552ULL, 0x1DD01B380B224BBAULL, 
            0x8B684D5177BD2FA9ULL, 0x72B3453CE0533881ULL, 0xE9F6A22B9A89A316ULL, 0x351B7A155DDDD509ULL, 
            0xF8D91FC118D456D9ULL, 0xE84ABC064B2F562EULL, 0xBA7B863BDEFEB4A2ULL, 0x4F463ECB5A7AE601ULL, 
            0xDBF33117083F963AULL, 0x05D61A86B46DE402ULL, 0x4111EAEFBB1DAFB5ULL, 0x9E4CBB13340699E5ULL, 
            0xBEB732604DAE1D22ULL, 0x048D10FF27C9431CULL, 0x1A8C812DB379D00AULL, 0xD232B4543C2A4E0FULL
        },
        {
            0xC6AA1E739EE07D94ULL, 0xF79BFACB48EF788DULL, 0x170C621AA19B0D47ULL, 0x7BFBA32A4E36436BULL, 
            0x5588238510D1A6E0ULL, 0xE31CCB6A5E38C9E7ULL, 0x587B58F053F8677FULL, 0x6874F6063F22B36CULL, 
            0x67875B0BB2173074ULL, 0x6F7991CF9C115302ULL, 0x65520A9FE726657DULL, 0xE10F83EA7336F205ULL, 
            0x55CF3DC87449A586ULL, 0xFEC2761F1224D462ULL, 0x8D3653B3F7E21ECEULL, 0x45919A9F810B0536ULL, 
            0xD95A7E95AB02945CULL, 0xFF6C4BA45EE2221FULL, 0x80ED29F4F2E49E16ULL, 0x7BD24B61A3420738ULL, 
            0x3969BBEC306CAFDFULL, 0x7810C3150D1AB752ULL, 0xD3E0BBBA41C86DF4ULL, 0x99B8D93D227B242FULL, 
            0x57BA4655D2B5C254ULL, 0x5E518FD4FCC61DBAULL, 0x3A5F1864C0769CA5ULL, 0xE68B4827CC3EFB54ULL, 
            0x462DC3A060625D2CULL, 0x402205518E676331ULL, 0x41E717C12D501646ULL, 0x9FD1C201905EE2E2ULL
        },
        {
            0xAB2AB685574C54BFULL, 0xC8F315F52C3AF49BULL, 0xA75B1B8E845B998BULL, 0xE38D91A670938860ULL, 
            0x6659AED0DC3CDFDAULL, 0x6084EFC66D697893ULL, 0xCD87066E599DFD2BULL, 0xC7FD3A3730E26D54ULL, 
            0x76D167EE923EB462ULL, 0xFD76A7AC0A5EC76AULL, 0x5197E1E4F96EA8ABULL, 0x3A99DD4D7C9D06B1ULL, 
            0xFBA067E5263299CCULL, 0x380D5442393AFF4AULL, 0x5000AE3E170F7483ULL, 0x3BAC538C958952B3ULL, 
            0xEA19D9F1F2731C76ULL, 0x2EE1C3D1E43B62AFULL, 0x27DB545E9989D9FCULL, 0x04E8D025177E0FCEULL, 
            0xA24852E5563961F8ULL, 0x427BECC284FD6D57ULL, 0x57028831CE1A3219ULL, 0x2C02E89C7C0EE7CBULL, 
            0xA7A4C33D72B4E0FAULL, 0x7C3965C927755FEBULL, 0x77449E207E93C5D2ULL, 0x4465B01221989965ULL, 
            0x49BBCBD30161903FULL, 0x69F02CDC6C2BB7A0ULL, 0x4E0349C856166550ULL, 0xA6441DDAC2946C96ULL
        }
    },
    {
        {
            0x842CA47433D6A345ULL, 0x3D31C3461A217B13ULL, 0xC56EB2071C0C8F8BULL, 0x711FAFF975F82AECULL, 
            0xE202AA832D8F2344ULL, 0x436080252D60003DULL, 0x3C3A1A20AFFD597EULL, 0xA5B45AF6CB9AEA72ULL, 
            0x607E4CCAF57AFFD9ULL, 0x451A810C6113D804ULL, 0x0AA3DF74D40BA3C9ULL, 0x2F3D7068820EB7D3ULL, 
            0x1C4447447C751663ULL, 0xC78087AE9972733EULL, 0xBF77A69122D53E89ULL, 0x1A6FD11875295617ULL, 
            0x88FCCD2029480E54ULL, 0x3FC372B291D4D6D1ULL, 0x3C0341DD6C5E9AC9ULL, 0xD7FCB33CDCB8BF2CULL, 
            0x7463607B96E8363FULL, 0x9FB3751D4C0C8000ULL, 0x0CE539673FD9193FULL, 0xEFB0AC3AEF3D6184ULL, 
            0x41A0598381EF0775ULL, 0x002D86228FA31B7DULL, 0xB87EA3E05472C368ULL, 0xB3109CBB8B4D436BULL, 
            0xEE887AE475633FA6ULL, 0xB4DDE00A871553FAULL, 0x2C058CB935AE3E9BULL, 0xC3ACFBA3EA260A58ULL
        },
        {
            0xD1E7D821D1BEBFE4ULL, 0xF3F8E455C0EC37C6ULL, 0xE40513F36E7D0516ULL, 0x053C08FE3F59298BULL, 
            0x788581AA4EA8A38DULL, 0x0696E0C6D460F126ULL, 0xAF22F046BF6AC07CULL, 0x7DAD30B769014C3AULL, 
            0x6129AD132455CFD2ULL, 0xCBB12E4A9CE0191AULL, 0xA5F6A514E1A2F94EULL, 0x3AFB3A8E3C078A71ULL, 
            0xB5153FAF9688CE66ULL, 0x699BAAF3122B8405ULL, 0x72CB1E7C4DB6AF44ULL, 0x1130F8488BCA9BCFULL, 
            0xA419D25C7843F8A1ULL, 0xD0E04DCD07263E74ULL, 0x70B4D08A18D42DC3ULL, 0x05C06EF303012667ULL, 
            0x6E0E5AA72F02400BULL, 0x3803CB2F604CD0F4ULL, 0xE3F01147FC5CFCA6ULL, 0xA38076FD25B2D2FDULL, 
            0x11A7F1A929361CCBULL, 0x48DC10C52EDDAD89ULL, 0x46620B39A84C604BULL, 0x69305D8FC71CEDDEULL, 
            0x0B3A400C8613BF21ULL, 0x26C87FB228DA3D29ULL, 0x39989ECFB8C9B3F2ULL, 0x33F0C512A3148320ULL
        },
        {
            0xB39F3EDD3ABC272CULL, 0x56A2E1A87E43FC38ULL, 0xC87D10CA8C159E98ULL, 0x23DBCC5909302014ULL, 
            0x644DAE19C24A591AULL, 0x57DB12C960FD6ABAULL, 0x380EDF2A15A06736ULL, 0x3BDCAC107612D262ULL, 
            0x82AB6A159DA622A5ULL, 0xC60C6D3FE89CA860ULL, 0x5E0C7344538FC33CULL, 0x676B8A15AEFED087ULL, 
            0x81EA702D641EB001ULL, 0x30AA659C870B20BDULL, 0x0185F363671F5717ULL, 0x7F64B1610C7EAD71ULL, 
            0xDCA175621E188A84ULL, 0xC8C6FF56A938930DULL, 0x93DDA2EA2F87DA86ULL, 0x3E535A29A4CDA520ULL, 
            0x702C67BD32EFC3F8ULL, 0xB14CC7A6F056098EULL, 0x2767F2BF38B26E31ULL, 0x88BCFA4F439523AFULL, 
            0x5DAC94AC3D0235DBULL, 0x0A77144B0CD629D9ULL, 0xB4B9B573E186C97CULL, 0xE0E86E2D4DD2ACCCULL, 
            0xB3FC5BA8B4B94296ULL, 0xED5CC6106ADFA394ULL, 0x7E3F8F0EDC2C1EFDULL, 0x0FAF62320993A1EEULL
        },
        {
            0x5DED79AC293615E0ULL, 0x5A409A49FD3E42EDULL, 0x9CA6DF3AD2A208FDULL, 0x0193BC390A34D08BULL, 
            0x947FB23866EFBBB4ULL, 0xF62E6F7298AA4A64ULL, 0x1273191AF8DCE1F0ULL, 0x2E483FBB00AB1822ULL, 
            0x7939D99DCB80C0A7ULL, 0x1B047845186010BCULL, 0x57C068979C254E68ULL, 0x8C5E30224FE278BAULL, 
            0x62FEE0F450DC7234ULL, 0x457FD2A35F53188FULL, 0xF8AA8D7266189F21ULL, 0xB762A493BE0B0B38ULL, 
            0x8984EB86F1CAA104ULL, 0xD0EAA2F5E3E6169FULL, 0x513CB6C88BB6385FULL, 0xD89795F45D11CBDAULL, 
            0xFB7385E31815411CULL, 0x837EAC39522A617DULL, 0xBFC0E0DB32EE5691ULL, 0xCC5F6B08EDFC5BC4ULL, 
            0x52E133C019B80B34ULL, 0x2B57468F854C6319ULL, 0x3CCF8282130367DFULL, 0xA8CE02C3CE2C28B8ULL, 
            0xAE277ECC9DE22B45ULL, 0x18D933F1EC4845FDULL, 0x68EA6DBA1E09454FULL, 0x752AEDB497E1883EULL
        },
        {
            0x8C4F768C27AA3E43ULL, 0xB95472E15BDB9FB9ULL, 0xC09901B9B8005820ULL, 0x16E41CFDDD76139FULL, 
            0xF8C7C9CC54B7230AULL, 0x32C32557C9A5A6A1ULL, 0xE25C54DA874DC5C1ULL, 0x31622ED5175BFD1DULL, 
            0x263608BA50815426ULL, 0xD7D0A6866EFD01A4ULL, 0xA28E7658B3934CDFULL, 0x0CD6D659B131B353ULL, 
            0x4E3E91BFC8757581ULL, 0xB92D5E38ADF3FFE1ULL, 0x817DC74AFE8CDDFEULL, 0x9534EEB2D0C24D1FULL, 
            0x572BD4F5B4CE6FC2ULL, 0xD51715248CAEBF98ULL, 0x54522E3BB0815EDEULL, 0xFBC74768F986D7B4ULL, 
            0x97ED9D21DB44EC05ULL, 0x8891825A477E77A9ULL, 0x10DC14FF30A8F1E7ULL, 0xF8B6B2785BA13BC5ULL, 
            0x1F55333DDD218965ULL, 0x501F1A0360E92C72ULL, 0x3207B8E0BA2BDB59ULL, 0x199A4BBE0700A6E0ULL, 
            0x6B4D65C03F187B6FULL, 0xBBE4E99197A695B8ULL, 0x3EBCB4949F55285DULL, 0x9384AF0361A0EC74ULL
        },
        {
            0xD0709558F0EEC45EULL, 0x3AF523E45EE517FAULL, 0xF33267DF34DDC08FULL, 0x6190C68B7C1B5CD6ULL, 
            0x35523A01FECA897AULL, 0xECD28C96166F3B25ULL, 0x9EDF388381F74221ULL, 0x9358706E254F26E7ULL, 
            0x8ABBF1026F74ED26ULL, 0x31BC5071F3DF3F5CULL, 0x28CE8659E2A9AC3DULL, 0x3C3714B0BAD2424AULL, 
            0x55BF01C7C7D60EF3ULL, 0x8F625F8AC2FD303AULL, 0xBF384187882F02B8ULL, 0x5E343ACE784C3CE1ULL, 
            0xB3E4EF35C5556533ULL, 0x760FEBF280757ADCULL, 0xF568E404287EC1C4ULL, 0x14F6FFD262A0FF6FULL, 
            0x411EAA2149883024ULL, 0xBAFDD34AAEABBDF3ULL, 0xBFD191F9EC2A7E75ULL, 0x50241C0786391BBFULL, 
            0xF1C90E054FAA26A2ULL, 0xB53CA193E3ECAF65ULL, 0xF81E1145ECC219F7ULL, 0x9BFA338E3114672EULL, 
            0x6A2B23FA76EE8668ULL, 0xF92734EE32A1B9D4ULL, 0x8A3EDF30F9008004ULL, 0xB73F27C4759C50B6ULL
        }
    },
    {
        {
            0xA25A63905CD88EA6ULL, 0xC39DDAC272897536ULL, 0x106D8C9B8CFF72E4ULL, 0x4DAEB1A963EB7050ULL, 
            0x91BE21930606EE32ULL, 0x8FB5191325D0F59AULL, 0xB83C5C6BE273AFA5ULL, 0xA9D086BDA1F9F345ULL, 
            0xF16EEE64667AC022ULL, 0xA31B4B5EAE955E80ULL, 0x8E0DDDB3174053F5ULL, 0x9A8F06C4A99249A1ULL, 
            0x4398101C87D988FBULL, 0x47E1601CD92CBCCBULL, 0x83B3152C6A7F6BA9ULL, 0x2C86EA3426CDAE69ULL, 
            0xCA7C6CE54B339C4FULL, 0x703C56693C22ED75ULL, 0x07ADB155EF0C0385ULL, 0x7468E75DDF9E3189ULL, 
            0x775E443A1EF3CB33ULL, 0x90DE4842EF762A4BULL, 0xBA933AEC3C53C68DULL, 0x4665C464CA5FD192ULL, 
            0x868858AF314C25CEULL, 0x902FD24D19889737ULL, 0x7F92F72F1BC07E6AULL, 0x3047973A80778F9FULL, 
            0xFE5BE2B50489D610ULL, 0xD296A2EDBA0FBA67ULL, 0x3DADC2720B31E9D6ULL, 0xAC12B4C0F6EE0858ULL
        },
        {
            0xEAA6EEC6439E27A8ULL, 0x6FB941511BBA12C8ULL, 0xCE5446D625BB2706ULL, 0x6DD9B5ACFC098305ULL, 
            0x8E0C49AFB609FACFULL, 0x62EF9E3C4DED9FBEULL, 0xD300E142281134ABULL, 0x7E57C2C966A06D01ULL, 
            0xC66B5945237CBCB1ULL, 0x0D3415E386AA36CCULL, 0x0166CE90AA35C6C3ULL, 0x19911AFFF0B06D6DULL, 
            0x9A8DD5D2E07169BEULL, 0x5F8920E6C9BE56B3ULL, 0x8E579ACC8C8B1324ULL, 0x66D1729253F438C1ULL, 
            0x8826B772B37DCFD4ULL, 0x1444A23FDD9CABBFULL, 0x12D998D56822B2CCULL, 0xF11A70CB19CAB9A3ULL, 
            0xD7D89152D07C7470ULL, 0xB92CA2B3B7472835ULL, 0x0054C19D45712F29ULL, 0xFFEF737C91390343ULL, 
            0xC8A20409AF43ED61ULL, 0xDCBE6A883F257D64ULL, 0x46011CD4A124DDB1ULL, 0xF8774CE5B6E06B1BULL, 
            0x0C9DB135F2C5899FULL, 0x842CAFA7F05461ABULL, 0xA725CEC8FAC2176BULL, 0x791E3F6AC8B075BFULL
        },
        {
            0x3EF9A57979491B3DULL, 0x38BA37092017AFA9ULL, 0xFE9604DD1DC23105ULL, 0xACFB7CE9E59FBD13ULL, 
            0x0874811D210084F1ULL, 0xC87E8DE67B40A4FCULL, 0x28933EFE9A502F61ULL, 0x99DAA40FCBD0CD48ULL, 
            0x72A1E65401780A69ULL, 0x2878AB5C2CEA7E31ULL, 0xD0DC45B67BE061B2ULL, 0x0C32E473E2E37B47ULL, 
            0x123BABC821DF3F37ULL, 0x374F0E28425728C0ULL, 0x86A23D57160FD69AULL, 0x45778235C2715AFDULL, 
            0x9D644025D1C1A260ULL, 0x74085A2B457D7513ULL, 0xC0C3E8FDA066264BULL, 0xB059FE2D93BE68C1ULL, 
            0xD50ACD8B3A1E68B5ULL, 0x8BD0B1EC514E361CULL, 0x276EFDA04EE8FF71ULL, 0xB9E801D573C53AB2ULL, 
            0xC70C9BB11C42D90FULL, 0x118CBEAD7F7BF658ULL, 0x76B04EA89AEC0118ULL, 0x9AD832D38DDCFBF1ULL, 
            0x99E7D7663BA9C13AULL, 0x4427FABB93D77EABULL, 0xDCD863AF68D7B4ACULL, 0xAD697FA86507E4B4ULL
        },
        {
            0xEAF58BFE9C6D340FULL, 0x12E5AB3B98F90024ULL, 0xA02FAFEE173BEF22ULL, 0xB482AE335F7D7016ULL, 
            0xF4DB28209E747409ULL, 0x8644FED7D1FD5A52ULL, 0x859C81C9381FC692ULL, 0xE59341D09D152B2DULL, 
            0x1FE5E4723E2A8D7EULL, 0x45F09FB0CFC380D0ULL, 0x8EDCF7ED15ED1A8EULL, 0x8A4794DB381EA09FULL, 
            0x4508F3801D8141E5ULL, 0xF65E662FD121B5A1ULL, 0x66072CE8C575AA35ULL, 0x51A6ACE4F78A591CULL, 
            0x2CAFFBC2CACA780AULL, 0xAE8CF86A28C37A2CULL, 0x62ECE7333A6FC793ULL, 0x4FE17F11BA486782ULL, 
            0xE8AEA3C88DCBD5B2ULL, 0x9572782139DDBEA8ULL, 0xC29EEE0820FA6FC5ULL, 0x347B294AA3D725B9ULL, 
            0x5EAFDAA27B5CB76FULL, 0x98B328B46BC4BA04ULL, 0x16B3701952D8F25EULL, 0x2A091F6815971510ULL, 
            0x071902BDEDF5F1DEULL, 0x4CFB68A4DE3DB035ULL, 0xE92B3A55DC97EC6EULL, 0x0D71E13E28071430ULL
        },
        {
            0xF9224D1E01806B40ULL, 0xC5551DE37819C515ULL, 0x00305145FAB9C19CULL, 0x0AEA810344A6CC2DULL, 
            0x7965CEE3BD68A996ULL, 0x8EE251A4F1F46DE7ULL, 0xE45BA27572448815ULL, 0x8BD126617709DDE5ULL, 
            0x8E20578CCD4198E3ULL, 0xD47CE97059AFC14AULL, 0x402B9A25DB2FDBBEULL, 0x4240541E2B40B499ULL, 
            0xDD566B0D88A6DB00ULL, 0x5847B9B8F0B3ECACULL, 0x2046C26A567047E3ULL, 0xBCA5D630813DB201ULL, 
            0x140D75A4A322F466ULL, 0xB0F5784B6E26A521ULL, 0xD3A91F8C952C105AULL, 0x12FB02D36D926ADDULL, 
            0x86E140333A94F17FULL, 0xFE9E7CBF9A20495FULL, 0x1E50728E5A44B680ULL, 0x4EECF269A1C78C59ULL, 
            0x3A38003A00544A6BULL, 0xD5F3595E76862812ULL, 0xF8741614DA6B2DF9ULL, 0xFF972CE97E8E04C2ULL, 
            0xDCE9ECB3302A1F5CULL, 0x7E182912969C0A57ULL, 0x52ED1605967A68BCULL, 0x66342ACD88E891A9ULL
        },
        {
            0xCEED51E4F271020AULL, 0x1B2218972F9D67A4ULL, 0xD4CF6D5AA64AC152ULL, 0x7DBF17B6E77DA607ULL, 
            0x9C5495BC1F39F5F2ULL, 0xEBA0342C7A856A6CULL, 0x808FDB271130405FULL, 0x1CD487B5ECBB6BD3ULL, 
            0x97D0116746F2D235ULL, 0xED9DC1ACC9A3E490ULL, 0xE33208CF3AE3D6F5ULL, 0xC072D4084833B8D1ULL, 
            0x80FCA63B8DD59BC6ULL, 0x0CA6DB6471AB3F6AULL, 0xA0E76301C66F3A16ULL, 0xDE63E31D421653E6ULL, 
            0x431342FE165B2885ULL, 0xBDDBEFED1AB29281ULL, 0x1596C67A04ABD491ULL, 0x8B3C7EE3019CB4FAULL, 
            0x3A998908009582A8ULL, 0x70DA0EE4EA4DF24AULL, 0x917DC0FFE6F9CE9AULL, 0xB84367D9EE7E84AAULL, 
            0xD663C2AF1282E61FULL, 0x6D565614D7C506FBULL, 0x2DB5C49FA90467B6ULL, 0xD0113ADB3223B919ULL, 
            0x49B536345C98205DULL, 0x8AF627B84668D60CULL, 0x74EAC0AAF7720C3AULL, 0x1A9043012318E002ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseGConstants = {
    0xA58D164AE4553427ULL,
    0x787C8590450BFD72ULL,
    0xFB9C7BE0235C1340ULL,
    0xA58D164AE4553427ULL,
    0x787C8590450BFD72ULL,
    0xFB9C7BE0235C1340ULL,
    0xFCC878B675A82B5BULL,
    0x4AB60D6EB07332A3ULL,
    0x17,
    0x93,
    0x64,
    0x64,
    0x0A,
    0xD6,
    0x9D,
    0x99
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseHSalts = {
    {
        {
            0xA7BFEFACCC963FD4ULL, 0x592A924CEEAB24C6ULL, 0x16E13A9014CA073FULL, 0x0B6D6737306E4F38ULL, 
            0x1B9A6A1657B5E01BULL, 0x212871DD23B1A495ULL, 0xDD24B440321AEA00ULL, 0x721B32207D0B292CULL, 
            0x295C1B7B5946FAB3ULL, 0xC85CCCDA7F6E8A64ULL, 0xAE659F9D082F240AULL, 0xEF92923960FB319EULL, 
            0x8E289E139F930BFDULL, 0x098531AE3FA5D7D7ULL, 0xD63C130EE5F05A0EULL, 0x938DE6C17ED793DAULL, 
            0x52AF26AFB24049E5ULL, 0xAAC6109AD437B629ULL, 0x84AE714EDBBE27B0ULL, 0x11E387D582C3AC71ULL, 
            0x2EAE6F03271C0CCBULL, 0x9D5A88B818DE890AULL, 0xAF9DBF1E80C15E24ULL, 0xDAA1351F1C7306CCULL, 
            0xCC3DDA25830647EEULL, 0xDF4FA3903F242ACAULL, 0xFAA0F267326D9D23ULL, 0xC86FAE879FFEE806ULL, 
            0x0E88C2CF1D482072ULL, 0x0B9D6BECCA756C87ULL, 0xE638FE310D50C1D7ULL, 0x771BDD2ED6B3A98BULL
        },
        {
            0xEC5E327CB0379FFAULL, 0x9B48878ED26BC46AULL, 0x46818AFDF227AB01ULL, 0x9E532CBF295F74F9ULL, 
            0x76E403F8632E5C14ULL, 0x9E53CFB9BB538733ULL, 0x62D9EA566E96CC94ULL, 0x3E43925ADDEAF4BBULL, 
            0x57C4B3B25D73D18EULL, 0x7793F221633C30B1ULL, 0x38D46C618356CAB0ULL, 0x6AB89517DBE0B832ULL, 
            0x6C1BA45AA1C374EBULL, 0x6A056EA66B3B4217ULL, 0x74E347DE4F534F4CULL, 0xDAB47579244109E9ULL, 
            0xF532D80D7A901585ULL, 0x7986728DBE36BB64ULL, 0xCF1D59025191E9ACULL, 0x9AD32F0EDF44F9D5ULL, 
            0x28774C9E21A9C851ULL, 0xA511AD1FE4A98CC4ULL, 0xBEEA164B09C90C68ULL, 0x7317FD0778D117FBULL, 
            0x5321723524A04824ULL, 0x8ABC0E882677A2FDULL, 0xB00FA8FB30E604CCULL, 0x0C18D3748414E50CULL, 
            0x88505462426BC323ULL, 0x3C530574BE2B353FULL, 0x5E97DF37E6821272ULL, 0x268CCA2477584A8CULL
        },
        {
            0x2CB8C8564C656696ULL, 0x6B872C8C44615B5EULL, 0x3A501D6AD44CB1AAULL, 0x9C7BE4AF1AE3972CULL, 
            0x51EFE57CDC5A8765ULL, 0xE977DF240AE00415ULL, 0x3592701A7AE03202ULL, 0x0BB3DA6E6B81C687ULL, 
            0x53DF3D19F117E59EULL, 0x47B7669802EE2E04ULL, 0x35493A922B4E7981ULL, 0xE1D7A72AD559DF9FULL, 
            0xA7A0D17ACB359907ULL, 0xA15B8550A4DD6C20ULL, 0x46A58B2BB692598AULL, 0xEF8692505B6705E3ULL, 
            0xED85A324B1C9EDDBULL, 0x50542FE9D2FF65C1ULL, 0x582D9B27506E6AF7ULL, 0xA0311D3CCB6DDBFBULL, 
            0xA93B3959744E2015ULL, 0xC5D363C328DC0F93ULL, 0x724F9E49AB5723F2ULL, 0xF942009097BED7C4ULL, 
            0x1CADBCF53E41D33FULL, 0x8F32E2A1AA788028ULL, 0xFFCBB55673B99433ULL, 0x005019C5F9DF7B38ULL, 
            0x463CB435AAA019F2ULL, 0x7BFDDD1C009E6FE9ULL, 0xA60530E9570A35A8ULL, 0xBE9061B329FB1895ULL
        },
        {
            0xC415839247C21A4BULL, 0xA2776151E49E5F79ULL, 0x539EA23B979D3C0FULL, 0x7AC63D1F34D66CCAULL, 
            0xFD5775A6C15F1B9FULL, 0x9598CB9EA694E697ULL, 0xB8F2EF6D6BBC68ACULL, 0xDD21377258F87581ULL, 
            0x603933893ED384B4ULL, 0x7DF27A1D93E6AD27ULL, 0x35F0DCA199DECE34ULL, 0x98FBA2A61641F706ULL, 
            0x153C6A816D2B39B4ULL, 0xB2133175D152E1D7ULL, 0x6CC20728568B0C98ULL, 0x0B941E4EAEFE5B05ULL, 
            0xF28A37DF9797E3A5ULL, 0x73DB28FE09DDB466ULL, 0xBEF5BE019FC4CAF5ULL, 0x2A7F96AAD2DCEEA9ULL, 
            0x8A729876C09E4F59ULL, 0x7DA2034296F3F826ULL, 0x1E9B603CA987A289ULL, 0x1BDF38B8CBBF808CULL, 
            0x6B941812986C8814ULL, 0xF597CF1AFC2C2E85ULL, 0x486BEDC6954B428EULL, 0xA632EDD3D3FBC71CULL, 
            0x0DB48D93646CF075ULL, 0xB0D449601C2A3EF2ULL, 0x1FEFF5ED38D9ED46ULL, 0x81277CDB842C7E08ULL
        },
        {
            0x4A87EFCE311AA06AULL, 0x391A92037423F072ULL, 0xD87141539EECDA1BULL, 0xDAEF8F76E460F485ULL, 
            0x0622054DD8DEBD01ULL, 0x7832EAED64D51929ULL, 0x3C190A78ECAEC5D1ULL, 0x56648CB7741C802AULL, 
            0xDABDE759F90743BDULL, 0xE1FCD0728C6FA695ULL, 0x2901301FBE1BE95EULL, 0xE5435C0D42532B45ULL, 
            0x91DA8725D3B6BFD0ULL, 0x240F1EA58B4E1AF0ULL, 0x323CB92D062DE48FULL, 0x45FA1B977EFBC0C0ULL, 
            0x033D1F3FE265AF9BULL, 0x01E4F5CB2E757DCEULL, 0x9C8CA48A174DADAEULL, 0x2862D7477CE47D1AULL, 
            0x6511CC990ACC1084ULL, 0xA3D492B369BD9FFBULL, 0x5C8A1007D074206BULL, 0x4B0AE9E6514080ABULL, 
            0x7EE1EBE21A728E72ULL, 0xB6B07F876BF20216ULL, 0xAC452CB1CE917F3DULL, 0x3CFE129AF43F1CF3ULL, 
            0x379F360049701701ULL, 0xA288D57312FF4CAEULL, 0xFA2DCE356F224F6EULL, 0xE387080F630CD7B4ULL
        },
        {
            0x5D79387EC7FEA152ULL, 0x5441993824A933FAULL, 0x7907FC6B913B7864ULL, 0xF0F2AB5B4C87FFFFULL, 
            0xC6F9D0451A567F0DULL, 0x8ECF836D6E8D68DBULL, 0xCE31B7250350AFCBULL, 0x2117BB9447BA6AE2ULL, 
            0xB2CC2EEA129A962CULL, 0x2D28A48D26D8FD5EULL, 0x715F6B2CBBB4DA02ULL, 0x78CFD08BEB8DB3ACULL, 
            0x827C3D312F1C91DCULL, 0x7C45931D1CC4FA52ULL, 0x775DD22A138C3692ULL, 0xA6CE07F8BE1AED39ULL, 
            0xDE2341EACCD0318FULL, 0x8CC81D12A081FC2CULL, 0xA9F2BCFA1C32C590ULL, 0x3EE4A91830C3ED1EULL, 
            0xA63F1A603AED2B2EULL, 0xAD5A5421F2807D48ULL, 0x3B685B9B01C2A899ULL, 0x54A3A90B18F89584ULL, 
            0x546916352805B2E1ULL, 0x98B9A7C61F35DF13ULL, 0x4A0962801799FD6AULL, 0x1BD6CA8B185A90CFULL, 
            0xEBE7604E31668BCAULL, 0xFC41C991CEF1A68DULL, 0x635F7CDFBB05D2D1ULL, 0x13B6B716F873CB13ULL
        }
    },
    {
        {
            0x94BA46D43652DCD1ULL, 0x129EA642938C5B89ULL, 0x7EDAD5168A3621CEULL, 0x1C8802B218AA0652ULL, 
            0x8685423F6743DD9CULL, 0x657823F95F7B00C2ULL, 0xF505F264AD703A8EULL, 0x4F6295A65CE020EFULL, 
            0x92B32FF20674AD62ULL, 0x2D8A076F1A72872EULL, 0x13ED546522D7F603ULL, 0x7FEB7BFDE1648D3BULL, 
            0xDFAC03569410021DULL, 0x5085434B8B709726ULL, 0xB53563DDDCB3C812ULL, 0x7010BEA68C2FC413ULL, 
            0xADE125904813D686ULL, 0x467A84F1AD631974ULL, 0xCF251A829CC66FF5ULL, 0xB6DB3A735915E60EULL, 
            0x9614F2ED89CA4980ULL, 0x48DD696FC73845EDULL, 0x993F5B9C47A87DFAULL, 0x6ABDA8ED1ED58BCAULL, 
            0x0EFA7A98EAFD4DBAULL, 0xC9A917E886B6A0BCULL, 0x301A4EF4A71B07C9ULL, 0x301B6549F25B1A5AULL, 
            0xE2A3A72C7B4F8C80ULL, 0x51B938D015BA6A69ULL, 0x5A2EA809279EE2FBULL, 0xE5C1C93EAF94E591ULL
        },
        {
            0x84E71C089826A299ULL, 0xD8F0733C78E4417FULL, 0xD25FA2D0AB8C1F46ULL, 0xF4D9DDA95AC55E26ULL, 
            0x8B1555535E21EFB0ULL, 0x971E0A18E29B7AC7ULL, 0x9B5ED38BA90D4B6EULL, 0xAE3D6DE66F35D5ADULL, 
            0xE0DC1754AE7A7CD3ULL, 0x4C5837C96FDAD966ULL, 0x6C39D2F20AC272D7ULL, 0x23F3A2E83D26EDC3ULL, 
            0xD455E74A3DC81D47ULL, 0x39E164D45B701331ULL, 0x01CA9D9D36F9EF77ULL, 0x24A216CA484D0FA7ULL, 
            0x94603B69220475D4ULL, 0x69EF8C965CC51226ULL, 0x6BC2778D61E25733ULL, 0x089DB36605AFBC72ULL, 
            0x0FFFC24D829B8CD4ULL, 0x23EDB48DD2DCC3EFULL, 0xB69F92CE9B25C49CULL, 0xCFD1AE0B4F54CACDULL, 
            0x89DBDB404A014C32ULL, 0x4291630553D7548DULL, 0xC8C87A2871CD5EB8ULL, 0x19989EE6FDDBD750ULL, 
            0x629C9D4ADDBD1C98ULL, 0x7805755A957AAD2FULL, 0x3707254E067A0062ULL, 0x8C6293274E9F6702ULL
        },
        {
            0xBCFA28AB96B6D865ULL, 0xF181E4F95B1920C2ULL, 0x2FFB31A9B141B935ULL, 0xC8B0D58A9D0079E5ULL, 
            0xFD767BBCA0A22EDEULL, 0xF86DBD0AAFD09A75ULL, 0x3C943FEDA81CC66BULL, 0xA5333E0D421185D1ULL, 
            0x90E785C2AFB7FF33ULL, 0x0A152D9BF345DCBCULL, 0x47E7D6ABE811056FULL, 0x3456B2657479A897ULL, 
            0x08CCD7045ED81B4AULL, 0xB94CCA60F06C3C62ULL, 0x8DC413564425ABBCULL, 0xFDF8930D2A762449ULL, 
            0x6A0D464451443137ULL, 0x315384A28FA3B600ULL, 0x365F55EC11E1A285ULL, 0x9AA1753FFD13F32DULL, 
            0x82F68C2BB4B9D655ULL, 0x3C0B4BB19115A161ULL, 0xBB5EDA77AD2C78C0ULL, 0x16562B5C23A2AE69ULL, 
            0x2940DE458298001CULL, 0x3300BACD8E8F4BAFULL, 0x5B704D48670848EDULL, 0x00CBD835628EB7ADULL, 
            0xA9FB1B1F1969C833ULL, 0xB8100F9979DC4EE0ULL, 0x7DD2D6177CA3BE8EULL, 0x55039A29307566A5ULL
        },
        {
            0x44E1B6C451EB3F64ULL, 0x7A0280E1724772D2ULL, 0x395EF27F7B4DD485ULL, 0x2751FD4AD41F8101ULL, 
            0x5CF271F669F0858CULL, 0x2AF9E7AB476188FFULL, 0x069463F83B0BCA3BULL, 0x481654627A0A3808ULL, 
            0x87A74F9D53D9F16CULL, 0x2D09E3AFEF20E24CULL, 0xB01183B621219391ULL, 0xD046388E46EA6EEBULL, 
            0x5B4A6C89F054A85AULL, 0x0DB08C71C4AD83A4ULL, 0xC2D02508FE431EFAULL, 0x37972E47FB6ECEB5ULL, 
            0x02A127121C39BB5BULL, 0x0475F7A0945C67DAULL, 0x3CB02ED212A0DBCDULL, 0x46291B31B79FE23DULL, 
            0xB2599E7233AE5C43ULL, 0xB8375C6F30102593ULL, 0x73AA6E49EDBAD4FDULL, 0x3813E83F9C77C66DULL, 
            0x276720C2811CA9F3ULL, 0xC4EC11AB7FA8F5D6ULL, 0x9CD7B7A7CEAD29F4ULL, 0x078F252E8409D4EEULL, 
            0x610E1925EF091964ULL, 0xAE26C394C03937A0ULL, 0xC5E2167611529E0CULL, 0xD5026495228299E9ULL
        },
        {
            0x4544DEE0DCC99BFEULL, 0x8EA9E3D9A0AB4D73ULL, 0xDCCCE421869015D7ULL, 0x73A312F95DC7374FULL, 
            0x6210379468AEA3C4ULL, 0x588020EB8AF3A30EULL, 0xEA520B80B664E2ABULL, 0xDEBC6F41EAC2270CULL, 
            0x26C5FDD9F3610EACULL, 0x6C8D5FA5D151D7B1ULL, 0x5768C68F4059C65EULL, 0x8AB21E9A13B9564AULL, 
            0xE49C5F0F5CAFE395ULL, 0x98A72D845B1777B4ULL, 0xC97F8A1F2F3D8050ULL, 0x5217685624173C09ULL, 
            0x306C910E47D4AA64ULL, 0x7A0421B7AD7D755EULL, 0x44136FA576642DE4ULL, 0x71ACAD3459542A8BULL, 
            0xBE25CCACD8CFB748ULL, 0xA33EE7454CE87FE9ULL, 0x93F9BADE9CED91E8ULL, 0xC8F505A7F2BD8076ULL, 
            0x889495450EFD7C72ULL, 0xDFB690C873E2306DULL, 0xF21FFAD47609B979ULL, 0x2DDAEFCF1C666539ULL, 
            0x7239FEE61B33F799ULL, 0x70138635217F141FULL, 0xC1F6414CFDCD59FEULL, 0xEB0BB609E361022FULL
        },
        {
            0xF06B4A617C3704B2ULL, 0x9C43534145AAD321ULL, 0x5304DFDAC2D8E8AAULL, 0x018459F1D84CF5B2ULL, 
            0x0EF72D703D422AEFULL, 0xC6C623397A91FCE2ULL, 0xC20D0EC3CB8ED428ULL, 0xACDBB0AAC3CFE7CCULL, 
            0xB4570A538ACE43CEULL, 0xE9C3E193236447F2ULL, 0x16095F7E19F2912EULL, 0x1FE2B7960657B6C7ULL, 
            0xFC13E8C4BD282E0CULL, 0xA890EA5489F1F7DFULL, 0x65A3449C436A0D04ULL, 0x96753E37A4BE2182ULL, 
            0xBD647B7F327C6B86ULL, 0x1BC6D79D2835B1DEULL, 0xD301A46713F5FA49ULL, 0x11133F9353DF8B76ULL, 
            0x2002B14ABCAD040BULL, 0x725F213A877604CEULL, 0xD98DBE38990123DDULL, 0x5555A69CA33551EAULL, 
            0x6C6ACFD32CF43DCBULL, 0x5C228DCB9EB6F859ULL, 0x00F68F683EEE3BEFULL, 0x3A02849CF1F80C9AULL, 
            0xEC36B33A44C0865CULL, 0x28457E8FA08D5688ULL, 0x0C2D80EE7DE5787BULL, 0xA3FAB87676C681D0ULL
        }
    },
    {
        {
            0x83438EEF75FE099AULL, 0xBCDD9A72E4E59CDCULL, 0x4F7CB01C580EB81CULL, 0x4178EA999D1ED09CULL, 
            0x23AF67283DF3B461ULL, 0x4704A57CDB19B9FAULL, 0xE42CB0D557CC1A7EULL, 0x2B4A4B422B389157ULL, 
            0x6D6D7821618441B5ULL, 0x450DA975FE7384BEULL, 0x817C8999906738ADULL, 0x1A32C228CC6A5E3CULL, 
            0x709964F65F7E23EDULL, 0xD6ABD14706F91EEEULL, 0x55975BEB62D9FD60ULL, 0x33D39F26B2BB8996ULL, 
            0x412CAA2AA49BFF89ULL, 0x21C274B87E3A4F22ULL, 0xFB3CF0F1C830A769ULL, 0xC2518C0CD56A77D3ULL, 
            0x63D35A196B2AC0C4ULL, 0x07F97D02B704758AULL, 0x54C59635931C9795ULL, 0x34949FAECEADD75BULL, 
            0x303773930FC49713ULL, 0xD37575A1F6BF0AADULL, 0xD4AD0C267A242508ULL, 0xD0A158ECFEAA1C54ULL, 
            0x58CADAF9BB60F585ULL, 0xFCA4F174F3AE6142ULL, 0xD07F086671DDC5F4ULL, 0x3208EA1E602F9CCCULL
        },
        {
            0x7E1265E50269A292ULL, 0x40830A841FA7754AULL, 0x8B2364F2738EEB29ULL, 0x4F831E9002C397CEULL, 
            0xCFA1A3AADA86AA05ULL, 0xB4FE6708919107B6ULL, 0xD986F21684492DB5ULL, 0xDC58F4A0ECF985E4ULL, 
            0x645DFABD1EFB6567ULL, 0x464CB5144036C607ULL, 0x55BDC6DAD94DBBEEULL, 0xC21D3AF4A5FF1D02ULL, 
            0xD441AF2DCCC6DFC0ULL, 0x84506C83349AB796ULL, 0x6E19D71F6BD29D92ULL, 0x6D562DB2063A8230ULL, 
            0xE011000A45ABA3B3ULL, 0xD5176E92DF67AA89ULL, 0x791A3D6F5538ADBDULL, 0x981302C91E9E5A36ULL, 
            0x6A611BBA93F1636AULL, 0x04523B00BD3D1F90ULL, 0x289E7657198E5303ULL, 0xBE9DDEAB954CF765ULL, 
            0x9B1E0C2EBA2D5AC8ULL, 0x26B82AF6CF5C0B5CULL, 0x06270945F2F5BC2CULL, 0xF0954526AFF949FDULL, 
            0x2C8B964824485197ULL, 0x94CD6C3907A99A42ULL, 0x82CCBD2D98F78B4CULL, 0x638F1381D3E178E1ULL
        },
        {
            0x6BC3728FB0D6CFE5ULL, 0xC0B5136AEA2EB65FULL, 0x54F6E87E556054F0ULL, 0xDB5F296EEA5B1A1BULL, 
            0xC095196FCB886A92ULL, 0x2DAB935422EFDEFDULL, 0x359458C718D4DA90ULL, 0xC603F8B18DCB0A06ULL, 
            0xA647DDD56E27896EULL, 0x0772B426865CFF09ULL, 0xB3E3FB461FAEFBF2ULL, 0x6FBB1B7AD752577FULL, 
            0x7067BED68759E3CAULL, 0xBAE71F25B500FE3BULL, 0x7E01939DE6517668ULL, 0xFBEAF3E144CDF838ULL, 
            0xBBADC55BEA0F402BULL, 0x7D45337C0B4F91FAULL, 0x13CAD134546CF049ULL, 0x9C9FB2C884116F1EULL, 
            0x3587310B33221192ULL, 0x47C20D368E72DEA2ULL, 0x57E6F8C508C868E1ULL, 0x0C6E440EFA7B60C0ULL, 
            0x55183BB4E02DBC8AULL, 0xAEBF012E5AFE24E1ULL, 0xD38E3B3BE8C92F49ULL, 0x4961D758BAF0A480ULL, 
            0xAACA9348B95D7A71ULL, 0x4E44C981FE7A0301ULL, 0x0F97E9CF54CBC0B7ULL, 0xF38C19874B64C3FBULL
        },
        {
            0x57E7F53F2E85D886ULL, 0x622E30F19BB86F17ULL, 0xB56ADE6B88ABB2C9ULL, 0x17E40C5947DBBA87ULL, 
            0x8E2E95BA9BFDF45BULL, 0x2164BFEF43F1CAEDULL, 0xCDD465621FAEAEA5ULL, 0xA4E3862F4D1556E4ULL, 
            0x273B0A1578980524ULL, 0x9C7351F961599B32ULL, 0x7FE84FD1F544EC29ULL, 0x00B577FCAB9BC29BULL, 
            0x292D9E63DC40BCB4ULL, 0x7B2C2CF6CA0EAE89ULL, 0x07A78F9205905F96ULL, 0x81377B6861C77D7BULL, 
            0x24D36F44063B8E19ULL, 0xAC341DB7E2671571ULL, 0x9E84B2D7AFC0FA1CULL, 0x9438DD139874E207ULL, 
            0x66653843B30D654FULL, 0x3C1F5F74EB245C34ULL, 0xCA98B70D7D5A0B23ULL, 0xF0B0364E7EE628B0ULL, 
            0x8129935D2523B070ULL, 0x3C9CF38674707D66ULL, 0x54C845A0C7AADFB4ULL, 0x9E995719DF57FC3FULL, 
            0x299080928569F0B4ULL, 0x79C5A30EBAFF8E10ULL, 0xC5427115E11EFAB4ULL, 0x4AE7D740F4108989ULL
        },
        {
            0x4F0B5EB267E0D4BBULL, 0x38AB3F43988E765DULL, 0x26727FDD7399B1B8ULL, 0x64A1742BDDCFF916ULL, 
            0xD7E6EDD3A8AFF6C7ULL, 0x650B5F8D97BDEB03ULL, 0xEF66E936CD7B2D7FULL, 0x38B20B7D37FC8AC4ULL, 
            0xFA7835487AFD20DEULL, 0x91299C35919ED034ULL, 0x5FB9058AECC0886EULL, 0x26748A8FC462FC17ULL, 
            0x229F38C816022A9EULL, 0x9D5C85C47A1C8F70ULL, 0xC92783505D8AB8E6ULL, 0x8C6DB58C860CD98DULL, 
            0x88F68C547C2BDD80ULL, 0x74350669B67F785BULL, 0xBFC4652B9E391BC0ULL, 0xA3F78FD55E3FD351ULL, 
            0xC793596FC85233C4ULL, 0xF60225E0B8209190ULL, 0x91E4FE0C247CF521ULL, 0x504C8A29DBEC2E22ULL, 
            0x848BC00FA7AD9931ULL, 0xE1325A1F1D019B74ULL, 0xBE5A9CF6D5BC5B4DULL, 0xF5C69F68AADA203EULL, 
            0x6C63D935501B851FULL, 0xEBBFAAE0D6BE72F4ULL, 0xC8378017AB6CE0CBULL, 0xC6C3794301EA36B9ULL
        },
        {
            0x61501B096D34E8B3ULL, 0x394C4378EBC2DEA9ULL, 0x5748AE1B43E9B941ULL, 0x4BB725D59BA482E2ULL, 
            0xAF7C8D59F21B9B45ULL, 0x9EBE4016C49C3F81ULL, 0xC92ED5F2A562D5D5ULL, 0xB3AB57BD4A14AFBCULL, 
            0xB16A6C7033666F71ULL, 0xF612B655449CDDE7ULL, 0x584DC6AC8161E9B6ULL, 0x32AA6173D0AA645FULL, 
            0x1C5E3485A814AB1EULL, 0xDBE2F134ED3C1F4FULL, 0x270A0EF16A83788BULL, 0xEEE5F611805F2F56ULL, 
            0xF67BE8D9E0414AD1ULL, 0xEE333945EB8F8F02ULL, 0x7833093330C9AD74ULL, 0x4C50C68E0CA37C54ULL, 
            0x1BFE3D593D31D839ULL, 0x4EFBA7B1005379CCULL, 0x174802C4C18A5169ULL, 0xCD6A46FD343A1607ULL, 
            0xA1B1D982C8546A26ULL, 0x5734C472E6E38278ULL, 0x8B0A42D79E07C394ULL, 0x2A57F36FA30709ADULL, 
            0xCD5E301BE0156C52ULL, 0x865599565CC5F098ULL, 0x360D8DC0719F1A28ULL, 0xD8CE8BC8558074AFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseHConstants = {
    0x1A559285C2AC5D73ULL,
    0x48FE08447E03FB78ULL,
    0x02071C929864D52AULL,
    0x1A559285C2AC5D73ULL,
    0x48FE08447E03FB78ULL,
    0x02071C929864D52AULL,
    0xAD709E955CFA1D99ULL,
    0x1FED8E7343ABFFE4ULL,
    0xE5,
    0x9D,
    0x11,
    0xD6,
    0xED,
    0x97,
    0x43,
    0x48
};

