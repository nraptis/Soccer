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
    std::uint64_t aPrevious = 0xE0505D721EF45942ULL; std::uint64_t aIngress = 0x98DF5B9B6129B9FBULL; std::uint64_t aCarry = 0xE2B3178C51D24336ULL;

    std::uint64_t aWandererA = 0x976675D311606EF2ULL; std::uint64_t aWandererB = 0xC2EF5C9E21E76BA7ULL; std::uint64_t aWandererC = 0xD22CC568A25F09BAULL; std::uint64_t aWandererD = 0x8195B9F794AB8494ULL;
    std::uint64_t aWandererE = 0xC6F070317A4101D0ULL; std::uint64_t aWandererF = 0x97378AEE14E30205ULL; std::uint64_t aWandererG = 0xE0A7F3F7BFFA8810ULL; std::uint64_t aWandererH = 0xE2CBFA0ADC4A32F0ULL;
    std::uint64_t aWandererI = 0xF737B298F0132BB6ULL; std::uint64_t aWandererJ = 0xCC475810179A84FDULL; std::uint64_t aWandererK = 0xEABE8E07444F7CBAULL;

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
        aPrevious = 9436763106627613997U;
        aCarry = 18068157349748742470U;
        aWandererA = 9720228525445872148U;
        aWandererB = 17215405893134939121U;
        aWandererC = 17693821108843243408U;
        aWandererD = 11046963334295335359U;
        aWandererE = 15097274440595896777U;
        aWandererF = 12901736685374290049U;
        aWandererG = 10863959723973902218U;
        aWandererH = 17093147741151521256U;
        aWandererI = 12968992834514404597U;
        aWandererJ = 17065123606363861824U;
        aWandererK = 18412879354931456583U;
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
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
    std::uint64_t aPrevious = 0xC0C212DEB990D856ULL; std::uint64_t aIngress = 0x9B60FE58926B4719ULL; std::uint64_t aCarry = 0xA289C6C65F876669ULL;

    std::uint64_t aWandererA = 0xCB40883F334ABBB7ULL; std::uint64_t aWandererB = 0xB2371FC9D6982A99ULL; std::uint64_t aWandererC = 0xD57ABF00E76B19CEULL; std::uint64_t aWandererD = 0xBB51F49E76D9BF34ULL;
    std::uint64_t aWandererE = 0x89B1C469E612E39FULL; std::uint64_t aWandererF = 0xA03C09349BC27A04ULL; std::uint64_t aWandererG = 0xE6FA60F9CF9FDF08ULL; std::uint64_t aWandererH = 0xA381BC09ACB4F0DDULL;
    std::uint64_t aWandererI = 0xEA1B3DBB6E74ADF0ULL; std::uint64_t aWandererJ = 0xC8B17C3CE768628FULL; std::uint64_t aWandererK = 0x84244AC4C6BD45F9ULL;

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
        aPrevious = 11336301776791702055U;
        aCarry = 17330255478813064860U;
        aWandererA = 12984185597920602903U;
        aWandererB = 15528065656455247245U;
        aWandererC = 14184064936648843352U;
        aWandererD = 15907496148601444321U;
        aWandererE = 12331347460468386413U;
        aWandererF = 15345551957150120755U;
        aWandererG = 10578517998802337573U;
        aWandererH = 11203983817264833780U;
        aWandererI = 17057200848947355043U;
        aWandererJ = 15245535820382179748U;
        aWandererK = 9808989933876034970U;
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
    std::uint64_t aPrevious = 0xB38655F6363FD405ULL;
    std::uint64_t aIngress = 0xCE45B6879000F918ULL;
    std::uint64_t aCarry = 0xE3D5BDE77D57D0CDULL;

    std::uint64_t aWandererA = 0xC737054D11C3BF0BULL;
    std::uint64_t aWandererB = 0x83D4DED0F6B6236FULL;
    std::uint64_t aWandererC = 0x9B92BE9C088259C9ULL;
    std::uint64_t aWandererD = 0xCB15D37C5B478A29ULL;
    std::uint64_t aWandererE = 0x98E056ECA7F35B00ULL;
    std::uint64_t aWandererF = 0x814D1313D58F849EULL;
    std::uint64_t aWandererG = 0xF0C0580F87C1E1B6ULL;
    std::uint64_t aWandererH = 0xC69FD92A6FE05FD0ULL;
    std::uint64_t aWandererI = 0x9827BE6030B7EFEFULL;
    std::uint64_t aWandererJ = 0xA345997EF4DE232AULL;
    std::uint64_t aWandererK = 0xC3B949FBD8124E2BULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB, 1);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC, 2);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD, 3);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA, 4);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB, 5);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC, 6);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD, 7);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneF);
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
    // temp storage: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
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
    // write to: invest_c, invest_d, work_a, work_b, work_c, work_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, invest_a, invest_b, invest_c, invest_d
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
    // write to: fire_a, fire_b, operation_a, operation_b, operation_c, operation_d
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
    // temp storage: snow_a, snow_b, work_c, work_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_c, snow_d, expand_a, expand_b, expand_c, expand_d
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
    // temp storage: invest_a, invest_b, invest_c, invest_d, fire_a, fire_b, fire_c, fire_d
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
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
    std::uint64_t aPrevious = 0x8183BD44801359F2ULL; std::uint64_t aIngress = 0xC746A646D5AF2F3EULL; std::uint64_t aCarry = 0xBA086D7BC81AB17BULL;

    std::uint64_t aWandererA = 0xE563F38D9BC2CC92ULL; std::uint64_t aWandererB = 0xE70B26083AE358DFULL; std::uint64_t aWandererC = 0x8AC2FE2669A815D5ULL; std::uint64_t aWandererD = 0xBD9BCB2496AFBB6AULL;
    std::uint64_t aWandererE = 0x9A0015938DB1B0C6ULL; std::uint64_t aWandererF = 0xC600DD36DD2BC1BFULL; std::uint64_t aWandererG = 0xD9644D0EE5EE411CULL; std::uint64_t aWandererH = 0xC128F715840C03E6ULL;
    std::uint64_t aWandererI = 0xA9EAC868AD9A6BBCULL; std::uint64_t aWandererJ = 0xE56F1A3AD132B806ULL; std::uint64_t aWandererK = 0xC0C85AEA824D243CULL;

    // [seed]
    {
        aPrevious = 18294128811684665000U;
        aCarry = 17203233799296498423U;
        aWandererA = 10139062202401440390U;
        aWandererB = 9772682373969639705U;
        aWandererC = 17853662835551578051U;
        aWandererD = 14024217354545590419U;
        aWandererE = 10560471183307577314U;
        aWandererF = 11309454645951255453U;
        aWandererG = 14020773836129064574U;
        aWandererH = 9835403681047024367U;
        aWandererI = 12159033156039521405U;
        aWandererJ = 17033280223534153144U;
        aWandererK = 16083597946343003269U;
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
        // read from: aOperationLaneA source quarters 3, 1, 3, 2 with offsets 5735U, 6607U, 4068U, 3826U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5735U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6607U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4068U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3826U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 2, 0 with offsets 6451U, 1775U, 7433U, 1890U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6451U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1775U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7433U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1890U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 1, 3 with offsets 5432U, 2110U, 1257U, 3458U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5432U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2110U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1257U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3458U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 0, 1 with offsets 4087U, 3414U, 4250U, 5321U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4087U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3414U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4250U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5321U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 1, 2 with offsets 1371U, 1590U, 1609U, 947U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1371U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1590U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1609U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 947U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 1, 0, 2 with offsets 613U, 1277U, 1732U, 145U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 613U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1277U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1732U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 145U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 3, 2, 1 with offsets 629U, 85U, 482U, 900U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 629U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 85U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 482U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 900U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 0, 2 with offsets 1377U, 850U, 1731U, 238U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1377U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 850U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1731U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 238U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1184U, 188U, 548U, 62U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1184U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 188U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 548U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 62U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 3, 1 with offsets 4874U, 2799U, 3461U, 1417U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4874U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2799U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3461U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1417U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 2, 0 with offsets 1889U, 835U, 1793U, 6786U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1889U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 835U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1793U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6786U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 0, 2 with offsets 581U, 3689U, 1142U, 6299U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 581U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3689U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1142U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6299U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 1, 3 with offsets 4280U, 2246U, 5659U, 3857U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4280U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2246U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5659U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3857U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5620U, 5645U, 895U, 5069U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5620U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5645U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 895U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5069U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 987U, 938U, 1367U, 919U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 987U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 938U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1367U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 919U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1677U, 1967U, 1891U, 1768U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1677U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1967U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1891U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1768U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 408U, 883U, 711U, 1811U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 883U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 711U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1811U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1942U, 866U, 214U, 1898U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1942U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 866U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 214U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1898U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 1, 0 [0..<W_KEY]
        // offsets: 440U, 1493U, 1410U, 1952U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 440U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1493U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1410U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1952U) & W_KEY1);
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
            0x4F6AC705D911CBE9ULL, 0x096267F5786F0FE2ULL, 0x598863FDF52BC271ULL, 0x5052B63ED203A79DULL, 
            0x3179410585DFCD00ULL, 0x89CE659E2A6C3180ULL, 0x36CAF4991EC21F11ULL, 0x6CE6757BFD3410D3ULL, 
            0xB28C89DF3B08F33AULL, 0x46AE2ADE60906058ULL, 0xC8B6E0624C44D4B4ULL, 0xBD3B69A2190D2170ULL, 
            0x65C794B44F4666C9ULL, 0xE55780731A06B40CULL, 0xB8D3D9CBE6FCC0ECULL, 0xC794694FDF6BA8F4ULL, 
            0x600DF021890A3931ULL, 0xD421BEBB73CD69C6ULL, 0xEF09E76B870D1161ULL, 0xB8B1B87FB166AC9FULL, 
            0x6016FE540987EA9EULL, 0xC5DB45F5DE1C27F6ULL, 0x2CA89DAF73C65531ULL, 0xB2B28A1FB7B29689ULL, 
            0x40009B7890311563ULL, 0xC1D23D9E97584AD3ULL, 0xDDDE3F180B7E6C91ULL, 0xA59F9E14770799C7ULL, 
            0x680AE15E19AFCC58ULL, 0x0B0604E5382D28C8ULL, 0x27C0869CE78B27E5ULL, 0xE0B16F3F5A8B1088ULL
        },
        {
            0xE8646A98386E9DF6ULL, 0xAF1F31997FDCADB5ULL, 0x7584BAB0436A408FULL, 0x81DA022D8E230953ULL, 
            0x78C0BFAB8CB96503ULL, 0xE356273379171010ULL, 0x7141548D616207D0ULL, 0x816EC9EFB985477CULL, 
            0xD9AB89278DFE39A6ULL, 0x9F3ADA376F753C1EULL, 0x9B47590651C22E6BULL, 0x717256EE1DA27CC3ULL, 
            0x3CF039F6F4E390B0ULL, 0xC95AC2C82BB1D5F3ULL, 0xA4EB748A2ED1BD33ULL, 0x59A9DF5A76FD907DULL, 
            0xF4FFB282A2598B9CULL, 0x6D72A092131D77B4ULL, 0x564B35306A1294DBULL, 0x6A7069CB2EFF66C3ULL, 
            0x134EB3664AAA7FEDULL, 0x9564EC9682C21BE7ULL, 0x21B741CD6C62CB82ULL, 0x0487D4A1374A544AULL, 
            0x2532455AF669A284ULL, 0xB809074BB188F695ULL, 0x375D37455E52EDA5ULL, 0xC4B36806B4618E01ULL, 
            0x4CD72176E11E83FBULL, 0x43F501BEA6D3A990ULL, 0x1E8876A41CBB63D8ULL, 0x84EBA48AE4593296ULL
        },
        {
            0x450DBA31C5C8B029ULL, 0x0ACEA8ABD5E9E77BULL, 0x7C1C139468AC4BDAULL, 0x565CB8EB6970A271ULL, 
            0xE275F2B9FF6E048BULL, 0xC02A258A9929A9E2ULL, 0xB76B849EDC84FA0BULL, 0x68DF231CCB3EB0BEULL, 
            0x7D9ECFEAE48F2AF5ULL, 0x6018A1E2A4E0F17BULL, 0x229F045E784F369AULL, 0x855E92BF1847140AULL, 
            0x28FBCE86D2E4DE6DULL, 0x873BB96D45B67AB9ULL, 0x8BB24AA98BC13FF7ULL, 0x940D7A59E8615334ULL, 
            0xEC0ADA9FD2E5F0E2ULL, 0x5BEEEBF9237DF3CFULL, 0x9EFE3F7A153B002DULL, 0xAD395919761786A4ULL, 
            0x5D4B5B1089BDB527ULL, 0x8CD1C2C1D2738D45ULL, 0xBEC4FA789F1A3DAAULL, 0xB347B24180722063ULL, 
            0x4860AE8300D5B0E6ULL, 0xF0C766B3634F15ADULL, 0x25E849BE234A91E3ULL, 0x2D2061529B011D11ULL, 
            0x36E7CEA4635670D4ULL, 0xB0FA4F6FDC5FED76ULL, 0x8C4BF736591CFDF5ULL, 0xDC42F6B316255AA7ULL
        },
        {
            0xF0D9456B1E65BD56ULL, 0xA59AE7FCDCD51048ULL, 0xDEBCCC02CF6B9BA5ULL, 0x4B3C48DE4A9A4EFFULL, 
            0xC5E397DC861F1EECULL, 0xB5AF0B280AF53A1BULL, 0xFC6A815C313A0C73ULL, 0x08CCB05CFC8A0F0BULL, 
            0x7DEDEBA0225665AEULL, 0xDC299DFDEFD36664ULL, 0xFBA529A30B82C57DULL, 0x5D1157652CBFA5C7ULL, 
            0xAB629DCB9DC8505FULL, 0x282C463535D2EFC3ULL, 0x6D62135DC06C9ACBULL, 0x4A0E0FC490728892ULL, 
            0xE205D5E608EF34BEULL, 0xBC458815B9DF2144ULL, 0x950CC16F2FD5FC90ULL, 0x31157A45126343EFULL, 
            0x139AED07FBE69486ULL, 0xA0F544748B40F849ULL, 0x3717D40603F3073BULL, 0xEA1C38D9A37B6330ULL, 
            0x4EAB0C6C65073C68ULL, 0xE2754C9EF9CFB413ULL, 0xADAF5581BBEF7E07ULL, 0x367F705408E6C8B2ULL, 
            0x16E26C964F7EFB8DULL, 0xC6665E3B943B7116ULL, 0x427876522B7289E9ULL, 0x4674F4955CCFA5CBULL
        },
        {
            0xD6FB691E2AF00403ULL, 0xC7DA437B3E40BB95ULL, 0xA3ADB0BDCDBFE0B2ULL, 0x6BB9813C3865DBBDULL, 
            0x69ADD15FE5F6B7DAULL, 0x0CAE0B523082CF28ULL, 0x3C441719CBF813F5ULL, 0x38E4638DF24A4C78ULL, 
            0xD6157C90BB909FDFULL, 0x9950E41F3754B507ULL, 0x25C3959AEB4FE9A5ULL, 0xE5436BE763A0A56EULL, 
            0x6AE7BDFDAB41217BULL, 0xA5EAC7F18377916FULL, 0xC3387F5BA3D5E69DULL, 0xF09E22A2BC52065FULL, 
            0x0CEC6C9AB35DAA83ULL, 0x302EF18FB7C2FD10ULL, 0x465AEAB71914A7D0ULL, 0x98E1C08716A7E30DULL, 
            0x47A7E85C1EAEB852ULL, 0x9DE8345927525F30ULL, 0x2B52C77BA75D054AULL, 0xAFD09366857ED5A4ULL, 
            0x2A944DFA92B8B5B7ULL, 0x0255D3D7B18435E1ULL, 0x45A25AA0187879CBULL, 0xC623934AD003B912ULL, 
            0xF9F8F483EC3BD5BDULL, 0xBDFED96996F43BB8ULL, 0x7711620C9BA552C1ULL, 0xC8E61C3FF44F8516ULL
        },
        {
            0x3E018F80E8B14760ULL, 0x1D84F6104A8BC101ULL, 0x7E0DF7FF93559548ULL, 0x81909B7E701019BDULL, 
            0x74CAB208C4C24172ULL, 0x2C2B6F98273C9585ULL, 0x33E104D3855C6889ULL, 0x1EF261AA9E5BFF69ULL, 
            0x7CFC0966DDC6376CULL, 0xFD4C6BBF60EC2D56ULL, 0xE811ED0058A18A7EULL, 0x058002D505B3DDD8ULL, 
            0x5161ECAB801A9796ULL, 0xE11712FB3C1C89F6ULL, 0x5A41CC69B1C7A9C3ULL, 0x5FE93B27CABC8EBFULL, 
            0x98576585269C1C56ULL, 0x0848791B54C8A844ULL, 0xBBF2A53C60F82949ULL, 0x939958CDBB86B106ULL, 
            0x0B5DAFCCC798ED5DULL, 0x07CE7EAEA280B590ULL, 0x440A51C12D056365ULL, 0x25C3860DF9BF922CULL, 
            0xB15EC8C295B6B8DBULL, 0x542DEDA0F4824A74ULL, 0xF64A7DF7168A7784ULL, 0x78283DDE9905592FULL, 
            0xDAB48E2F533F176FULL, 0xC254F575F8FABCFEULL, 0x6E6DBC51A5D5AE5EULL, 0xF8404D61278983F0ULL
        }
    },
    {
        {
            0xA244B57AC9C65950ULL, 0x6B33070A2F108F18ULL, 0xA82742E918E6B8E4ULL, 0x3CCE5C20ECFA0739ULL, 
            0x3B6B26A2F8F21019ULL, 0x9A796F5EE7A67B41ULL, 0x21CB20F81D3C3B56ULL, 0x70BB348239CAFD4AULL, 
            0x84FA6E48D0618EDAULL, 0xC55680BC181FED87ULL, 0x69D08A1045D7254BULL, 0xCC0746B12D94B7C2ULL, 
            0x0A45E3D1FB77D932ULL, 0xFD996FB32DFAC527ULL, 0xD9604E1FF9D5CCEEULL, 0x9B72987A3C6D9F6FULL, 
            0x826D8C77B1B75525ULL, 0xB6937E1795D0DB30ULL, 0xB8A40810B2A8FC83ULL, 0x3CBF98C1ACED7277ULL, 
            0x20732495A42AB306ULL, 0x81DFA800F22EE51DULL, 0xA8AA55D41BF3EB0CULL, 0x53B10A3B911F40BFULL, 
            0xA52B78A87E88E56DULL, 0x338B9C56610C2D24ULL, 0x8F1A42A19D819AF8ULL, 0x899DC5F0A089D6D9ULL, 
            0x649C5DBB1AC0DE86ULL, 0xE91E6008055E749FULL, 0xE3169E1AFD439ACEULL, 0x474065B4B7123A5AULL
        },
        {
            0xBB114655A077A858ULL, 0x673C82001D198F11ULL, 0x4B5F2DC443F92E4DULL, 0xC3EF8A0A3A0B1A37ULL, 
            0x9284AD50116C2B2AULL, 0xCB239E197FD7F36DULL, 0x9E353484967ADFB5ULL, 0x24C17067891956D5ULL, 
            0xF4C9382457A162B6ULL, 0x05B7730F203513AFULL, 0xAF406B6B0C7634AEULL, 0x6DD38D9BBCE6C7D0ULL, 
            0x259A7130816F2D48ULL, 0x82A4C6F1C9C89D3CULL, 0xD96D709E9A7BDB7FULL, 0xF1498071D7CC5408ULL, 
            0x1F7C8B8B0839DFAEULL, 0x421B071B30BB5752ULL, 0x6AC68BF2E72AE519ULL, 0xB5737183F549B31AULL, 
            0x27E5B702494492F8ULL, 0x8BB94D9713D627BEULL, 0x2A815E7E83CDC5B7ULL, 0xC93286A100E26C20ULL, 
            0x8A77E3BDBE39BCAEULL, 0x036D27E1AB5A1AA5ULL, 0xF6A35105CC3A1F8FULL, 0x79DA29878FBD4947ULL, 
            0x169F0CAC1D117F75ULL, 0x0F4B065C873F1833ULL, 0xFD3DE9336F4A42DBULL, 0xA332ADBAD6C37E5BULL
        },
        {
            0x64965F87B2D3F2ACULL, 0x31C65977E110DACCULL, 0x82F8E81566F113DBULL, 0xC3A573C2B9AD6ED2ULL, 
            0x258C54F6E709E987ULL, 0x6870179DE70343A1ULL, 0xAD3454BEE407A5C5ULL, 0x2592BCFCA600544DULL, 
            0xD800620F812AC52EULL, 0x660A2F38D904D90DULL, 0xB75F027BB533C1DBULL, 0xC330393F283AAB3AULL, 
            0x53A100C77ECFBCEDULL, 0x5247E406D2A505A3ULL, 0xE17D34BEADA5FF82ULL, 0xFEDF223B860F1AE2ULL, 
            0x83B7382CD33E8179ULL, 0x4FEBBAC5956A81D0ULL, 0xE7440C1837494F25ULL, 0x1FC8962D3B7531BAULL, 
            0xD6EABE0FAF0B17BBULL, 0x8A651C53E2225BACULL, 0xAB609E87B65FF146ULL, 0x416E06F731D2EA51ULL, 
            0x44A2615FB1FF65E9ULL, 0x0A8A619C1BB1A6ACULL, 0xC5C8894AFA0DFDEFULL, 0xA9C07A86D120809EULL, 
            0xA76AF4D63B79DA33ULL, 0xB2B73F034294F1E7ULL, 0x44885513CBE2E72EULL, 0x32E76279A24023A8ULL
        },
        {
            0x8E109130D02DB51CULL, 0xCCCA746311DFDDF8ULL, 0x5CC6BEA5C3E8A0DEULL, 0x53DF2FE91C2DDDB9ULL, 
            0xF49177B513129F13ULL, 0x87DF0C59FA2FEEB2ULL, 0x5692FCC029A87E50ULL, 0xE959DB55F578E20AULL, 
            0x733C18D25429EDB6ULL, 0x2260FBCF32EC3CA3ULL, 0x05F07BFAFE559505ULL, 0xF7A02C0D385B65B2ULL, 
            0x22259DDE8A443E50ULL, 0x62F75EA3EB07B94BULL, 0x2E0963E5F8AA3190ULL, 0x9B20C6C12B4676E2ULL, 
            0x1471BD9E6287DF95ULL, 0xE5B6C059A7BC81BCULL, 0x5E5E91667D114CDDULL, 0x6781C2701C42ADB7ULL, 
            0xE044B0A50F587E4EULL, 0xB2ED039BAFA74906ULL, 0x2A5C707452F6CA1CULL, 0x3C1C313E9BC842C9ULL, 
            0xEAB77696AD5E0781ULL, 0x859D45A25A7A7BDCULL, 0xAE83247AD887847EULL, 0x544106B4A85B201DULL, 
            0xDBE23646CACBD3CFULL, 0x8F43FE06255E5072ULL, 0x600ACA5C88FF920AULL, 0x15B43382CF8ECD66ULL
        },
        {
            0x98F738412865DA93ULL, 0x2A2066AAB486A785ULL, 0x810A5EBDF4111C79ULL, 0x76F540DD809E5964ULL, 
            0x92A7DA80654B0CF1ULL, 0x7C6222EA7111FBA3ULL, 0xC2C2D2A1B406C34CULL, 0x55ABAA26840A0AD3ULL, 
            0xC14CF67B78F28AC1ULL, 0x7ECDDA90F5E900FAULL, 0x7C470E948D65684CULL, 0x3D29C3B6FF4C2028ULL, 
            0x587DAAEA53A6873FULL, 0x4C2A6D5268B5A9A4ULL, 0xFC07259915322B61ULL, 0x97BE5C6A3A6C2750ULL, 
            0x1937EC1F76BFF1F4ULL, 0xCE8AD360CE1B2F47ULL, 0x9321BDB700745FA9ULL, 0x810A17CCB45750F5ULL, 
            0xFE4C2DBA47438FB7ULL, 0xE37922C611138782ULL, 0xDFEEEEA675CB8DA7ULL, 0x0B1D89574E9BD2A5ULL, 
            0x6A030910F428D48EULL, 0xAB0F60CF8CC26C61ULL, 0x954806BE2669F1BBULL, 0xBB3CFE74BDD146C9ULL, 
            0x7BC561263AAEDDF4ULL, 0xE3092344EFA1722FULL, 0x9C302C13798A416DULL, 0xA0420DA7F440DB7DULL
        },
        {
            0x90D4F8AF476B4666ULL, 0xECEF54FA6C8B31D6ULL, 0xBA345BEC1FB13DB0ULL, 0xB0019C6E14F128E2ULL, 
            0xFCA3D8C04A5127DFULL, 0xBBDB34447ADADF8CULL, 0x1A8629BB8888EDDEULL, 0x7CA5C3F5E89C04BCULL, 
            0xFBCEB43466B1A114ULL, 0x7AE99C68E7B42699ULL, 0xECCBD99E6CB74C15ULL, 0x3FF53B06C1A4E22BULL, 
            0xECE0D82058DA4987ULL, 0x1BAA846699967D47ULL, 0x278E898DED8230C5ULL, 0x47F9369B4141C1CEULL, 
            0xD9B81D2BC70E3D9EULL, 0x1AE4E99FDDABC206ULL, 0xC15227CBE6F6870EULL, 0x3DF010960347D1D8ULL, 
            0x90FD4A8CD09930D2ULL, 0x8420C9A72391C708ULL, 0xBEF4EEA8084C39FEULL, 0xE6CB118EB0759559ULL, 
            0x5C6B14DAF1598272ULL, 0x080BB04E8E2E3AE1ULL, 0xA1A4A85941DA5E58ULL, 0x2C445C350CCAE1EFULL, 
            0x5312E040716AC6FDULL, 0xFDC622D4E1CB7E38ULL, 0x3A853AF7529A07F9ULL, 0xA0AA836E74F7B250ULL
        }
    },
    {
        {
            0x84699FD2DEAB519FULL, 0x8471D59D9861DFF7ULL, 0xFF424368DE583B33ULL, 0xF9A80644EE8617ADULL, 
            0xBCEEADA1884E0E3AULL, 0x5E3D80B9D3B5B5F4ULL, 0x2A9C3425F662B31DULL, 0xD93CB5EE94616ACEULL, 
            0x747FC281CF388289ULL, 0xEF327C889B51E2B5ULL, 0xF00B8043E853A01FULL, 0x22DB30B04C6FDAF9ULL, 
            0xD8BDB22A32370911ULL, 0x8BE8698923CAD237ULL, 0xD8C1A25D33CFC016ULL, 0x4F3190002D7E2A62ULL, 
            0xC066FAF0A7515F3AULL, 0xD460E99731D073FEULL, 0x9A3D514F8FB29240ULL, 0xB347394F711F5636ULL, 
            0xB94344AB9DB99B2CULL, 0x3AFCF17A003C79C5ULL, 0x7FEF7D0125758DC1ULL, 0xA57CB8C716F25300ULL, 
            0xFBFB79ED9F3CAE37ULL, 0x563190B3C35FED08ULL, 0x27FDAC657C0CE0C9ULL, 0x0BAC8E051A6DFDB0ULL, 
            0x2AED9F6B8FD97F15ULL, 0x0F50C769F34210B6ULL, 0x3AB6B48E8429275DULL, 0x0AC338CAE903EFE2ULL
        },
        {
            0xEC2164878C429A9CULL, 0x636EA7B1900D04E5ULL, 0xDA4DCF2897546025ULL, 0xAE6ACB11C5D0993CULL, 
            0xEA2F0486191F945FULL, 0x6FF91CBEAFABB0C4ULL, 0x2B95310963B80E51ULL, 0x965C92AA7B5C1310ULL, 
            0x47E13492C7DDD28FULL, 0x0DA7B8A14C918B04ULL, 0xE0B7731D56B4C11BULL, 0xC3CB2CCF6CA71E3CULL, 
            0x3565BB985F626171ULL, 0x983237C4324E04A5ULL, 0x26D88668741E8E98ULL, 0x2A82616290BE44B4ULL, 
            0x69FB4094A29F58C2ULL, 0x14CC09C98C80501DULL, 0xD83AE63F81A0652BULL, 0xF8D5F93C507BE71FULL, 
            0xD975088788DFB1F1ULL, 0xFE3CFF6788A95AAEULL, 0x300A738E752A62BFULL, 0x17957207C94A2F27ULL, 
            0xB6201229EE27E58EULL, 0xB0FE44ADCA5CB829ULL, 0x72261F5173D30A14ULL, 0x90768104F816666CULL, 
            0x06008D65AA3AD2A5ULL, 0x00551496200B3DF6ULL, 0x972BACDE6428DEA6ULL, 0x2A65B6231EAAE7F8ULL
        },
        {
            0xB4E9CB0CB53F763FULL, 0xAA64735044C20783ULL, 0x1DFBB316400A85E2ULL, 0xC297476E1634A5AAULL, 
            0x15BC78469EAEC21CULL, 0x13C2562DB062C0ADULL, 0xA0976456E9D845BEULL, 0xDD315AEA9C8E1571ULL, 
            0xE3FF80A8D02F961EULL, 0x6E6BC41DB93BACC1ULL, 0xE2547DD3B632EC36ULL, 0xE0F4B26A5C0448D4ULL, 
            0x20FA12EAE0C2D01BULL, 0x8FAF3B8E6019EBA5ULL, 0x1467BEC7CA568154ULL, 0x8E3CCBC681DA131BULL, 
            0x3618922DA5AD88B6ULL, 0xC764924804124F39ULL, 0x0E32BA2F8DE1D752ULL, 0x4C0AB2B7DDF7562DULL, 
            0xA026354AC9848739ULL, 0x73654CDAB19D49B0ULL, 0x6E5C97EAE5C3CBAFULL, 0xB05A3CCA7FB6CD0EULL, 
            0xB9F72BC7BB75C9F9ULL, 0xC8E0AB1983525815ULL, 0xB94EE2BB848B748EULL, 0x42206773C1DB816DULL, 
            0x4EC2C702CAF6D13AULL, 0x4DB6347B794EFEAFULL, 0x46AED11D603156FDULL, 0xE1A30760867E0A3BULL
        },
        {
            0x8A292375F9F30C9EULL, 0x0F805A728A9CC743ULL, 0xDB7D4D10293A1AB7ULL, 0x696AB909CF2D02EFULL, 
            0x42F35ABC68279344ULL, 0x382CD13A112052A2ULL, 0xF805845F28D69300ULL, 0x72E2B0024BE4D500ULL, 
            0xA7A922074479B06DULL, 0xDD912469F174C7E2ULL, 0xB00409FF4BDF00FEULL, 0x21BC8EA653FA5E93ULL, 
            0xBF43C7FEFD7C8D25ULL, 0x77680BF3F2A3308DULL, 0x91923F4087CA2ED3ULL, 0xBAFC2A85131D996BULL, 
            0x263F5921645ED5CDULL, 0x2901004FFE302DA1ULL, 0xBA08D16273920F5EULL, 0xBA081A44E4B69735ULL, 
            0xB02B81521F64AF43ULL, 0x42429372BFD1E287ULL, 0x7319E75EA5A861DCULL, 0x81A08AEB924DDFD6ULL, 
            0xAE348793C781D525ULL, 0x4F42841105344032ULL, 0x0FEE8CB28986355CULL, 0x1E2EACA7581B3FD5ULL, 
            0x8094B89C38BF2F3EULL, 0x1B927315DE71F003ULL, 0x3E8952503129BC38ULL, 0x6086460F7DB2725EULL
        },
        {
            0x97BA37DD7370CB5DULL, 0x437514A6C42CFFBEULL, 0x79D17A15A7B7FEE8ULL, 0x034B032DA8704224ULL, 
            0x5ED20E572ED3100FULL, 0xAF9BA9AD5606A4FEULL, 0x8ECFD624B22ACEF0ULL, 0xAD3BD53CBBCF8C3DULL, 
            0x1684F03052CA0182ULL, 0x12F5357AAA57BE9CULL, 0xCC540A3EE5909F21ULL, 0xCC722720719C488AULL, 
            0x175CF7C5B151C38CULL, 0x8B1363BC13944E8CULL, 0xD231FD02A3D4D008ULL, 0x2623418B68BF5C73ULL, 
            0x8711205F15A62209ULL, 0xB6599120A908519CULL, 0x046E3B27C0AC2405ULL, 0xA577A45D59D56EE6ULL, 
            0x855676D3733F3ED5ULL, 0xD54463FEE19EF922ULL, 0x8D049F928B5DA75EULL, 0x40AD975E1B474AC2ULL, 
            0x1AB60F235E482486ULL, 0x3EDFEECE15A25506ULL, 0x620C06400DC0A9FEULL, 0xE8A1F0AFA85D82EBULL, 
            0x2A1C242EE71CEC11ULL, 0x0AA285F4A3FF0797ULL, 0xA65F827A004F09AFULL, 0x4CAE1D3FCCF3B572ULL
        },
        {
            0x7CB06B55C3DB18DAULL, 0xE3D2C111C285F998ULL, 0x5F286D690BD843E5ULL, 0x3DADB254D2498914ULL, 
            0x0058393E39F183AEULL, 0x1F1E9517454D2B1AULL, 0x7DF2A15B7BE2DE30ULL, 0x8985EB05FEABF5DFULL, 
            0x3B73765B727C3E1DULL, 0x9F54DBA711DC5922ULL, 0xE3C8A6456DFDAEE0ULL, 0x49AFD97575CB267BULL, 
            0xF823B87AF36E7DFAULL, 0xFA4C2F93F29FD17FULL, 0xD984E6BD75F624E7ULL, 0xBD6A86E45363CAD8ULL, 
            0xE97C466ACF94CC19ULL, 0x9B7A29FD4FAC414CULL, 0x54F0D4E45D6DE1F7ULL, 0x8240874B7BF593E5ULL, 
            0x8B6A331AF1EC61F0ULL, 0xE30C5F3D4989100AULL, 0xA0211625C7DFDDE0ULL, 0x882E4CE0C696AC97ULL, 
            0xF53CD766CCC1D32EULL, 0x0749D390CFBD09A7ULL, 0x9F3BC6D91B58B663ULL, 0x8B3AB5A20FB44ECCULL, 
            0x910711B5B655118EULL, 0x7ADBB8390EA847BFULL, 0xEE13E566FD63F7D7ULL, 0xADD00C6E5ED69497ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseAConstants = {
    0x82FE09B097C698A9ULL,
    0x0A626D746C2B0E26ULL,
    0xB513BC6EDC774C14ULL,
    0x82FE09B097C698A9ULL,
    0x0A626D746C2B0E26ULL,
    0xB513BC6EDC774C14ULL,
    0xDD7A7EF141DE09E0ULL,
    0x60E4A1EE8D390A38ULL,
    0xC2,
    0x13,
    0x29,
    0xCE,
    0x52,
    0xE0,
    0xEF,
    0x89
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseBSalts = {
    {
        {
            0x1950422CDA88758FULL, 0xE696BA2B5B1CB59FULL, 0x11B6ED7B768DCA22ULL, 0xCF62D7E5588816DCULL, 
            0x2AC7DD6A47E41F78ULL, 0x0D1608862782441EULL, 0x0C88EA67B3F3C927ULL, 0xF8EC6BBB27E75E87ULL, 
            0x91AE2BAE301E14F4ULL, 0xA4A9501B681DE603ULL, 0x0C8044A7CAF299BBULL, 0xCAEE41496E17DF18ULL, 
            0xC35B78977D232128ULL, 0x9CE731EA65A6DB5DULL, 0xB1F75E259883E1BBULL, 0xC3D4266AA1806476ULL, 
            0xDA6D6EBF1A234D20ULL, 0xFCFDB44B2FF7D0E2ULL, 0x848016773F037D06ULL, 0x262B8B8D30C8475EULL, 
            0xC0A122C09CC002AAULL, 0x1BFE4138FE89DE86ULL, 0x48B4858FB2F9A893ULL, 0x51B84817FB9122C4ULL, 
            0x7367511B47EEBC5FULL, 0x19ED20EB24CC617EULL, 0x87B5CFC2F342EBD4ULL, 0x3257D17209FF9068ULL, 
            0x33EDE1D50FE963C0ULL, 0x670E3F440CE7627EULL, 0x6E3A75B6C137CF7CULL, 0xC0D94825CFF79C5FULL
        },
        {
            0xD6D05B10E2498BB6ULL, 0xDDE5CA193259E109ULL, 0xE6F18A76E1BEDAA1ULL, 0x1CFC9265AB8C1D3DULL, 
            0x1A1E56F01D966026ULL, 0x6B52A4D56848BF08ULL, 0x7EE4357ED789AA5AULL, 0xB8D91386AC84A6ABULL, 
            0x441762159B5583ABULL, 0x4A2CE2E310C0C6EBULL, 0x5030F4313A1D2467ULL, 0x2122CDC49AF69228ULL, 
            0x60F4B8FBF20D88B0ULL, 0xACB0CD735C265F4AULL, 0x255589D66B6D7860ULL, 0xA454BB11483FC00BULL, 
            0x200398A1FF843EEDULL, 0x0580B7C4634BFA1EULL, 0x1E25AD403F29EE05ULL, 0x919B0C14D4656EF4ULL, 
            0xCBB3A595382D4218ULL, 0x24752FB8CE59C97BULL, 0xD486C2DADCA238A3ULL, 0xBA27E8F5A602A33FULL, 
            0x09221C9E846E7458ULL, 0x2284790812E19C31ULL, 0x3276A405920B7BDBULL, 0xAA10316DB286AAFCULL, 
            0x24022DA345E25D60ULL, 0x60F25D4B0D6D6E12ULL, 0x4CD45E23B17B1BE8ULL, 0xA6A3463235EC3C93ULL
        },
        {
            0x41B164A572B32D90ULL, 0x39C7760162450210ULL, 0xB191D0A7C891937DULL, 0x8886E07FFC21382BULL, 
            0x25B6E79071B77902ULL, 0xBE8CE58EA08752C1ULL, 0x47D5227661C34424ULL, 0xA1270081380E6DF9ULL, 
            0x8031ABFBBA7D6C01ULL, 0x0099690E903C24E9ULL, 0xCAC42BBCECB29B41ULL, 0x8B11882400461DF9ULL, 
            0x058456B41B693FAAULL, 0x34A7126C2B9EFF65ULL, 0x7435B154DF4E57ADULL, 0x4B975DE10E730095ULL, 
            0x0849ADC3520DA24FULL, 0x9D1B40460D09FDABULL, 0x6F74DA358E627CABULL, 0x060EAB01DC2CC6A2ULL, 
            0x921C4C435AD73936ULL, 0x2C28801C0EE894A7ULL, 0xDB4DCAF569C01A7EULL, 0x2DC322FBCE576EA8ULL, 
            0x1CC2D1D9242065D3ULL, 0x2198A681F9B0D8ECULL, 0x0064DD2A79C54225ULL, 0x5D1A9183F3FF1F47ULL, 
            0xDA092778D8C5E6D7ULL, 0x6ED37B9F9CE1F629ULL, 0xC791970F15A3AC8EULL, 0x06E56246F0CE8DA3ULL
        },
        {
            0x18D9BEAC06D23E8CULL, 0xDC1850ABF5957191ULL, 0xC6C530E90A28DADFULL, 0x318C9AB682830152ULL, 
            0xCD4923164FE53385ULL, 0xE91A6FD81400AA7CULL, 0xC43B37BBD57F7829ULL, 0xF42917343353ECF2ULL, 
            0xA97CB6E5EC475297ULL, 0x05C2A4B4CFB52E6FULL, 0xB388CC2FF4D41726ULL, 0x5EFC29A757FBE120ULL, 
            0x4A84413D0D156E7FULL, 0x0A89BDA630344DFCULL, 0x68A87307B0ACD3C3ULL, 0x1F6D2FA4BCC72AD4ULL, 
            0x3E33EA176BEAA829ULL, 0x435B1AA80817FE3EULL, 0xDC7786C816E1E3E0ULL, 0x13A0C8479BAE3195ULL, 
            0x887ADF88AF579260ULL, 0x3009D3AE5EE21823ULL, 0xAA9403452C9C3533ULL, 0x8031B295C310D1F2ULL, 
            0x5CA80DB72CAF75F0ULL, 0x0B5C1A4FA5A9449CULL, 0xF300B76BC5C4C50EULL, 0x959B04526637D265ULL, 
            0x6066173AF36D32DCULL, 0x55E78241CB91E657ULL, 0x8B1EB466DC7A7549ULL, 0x1570267AEAA8D827ULL
        },
        {
            0xD84D184143413793ULL, 0xBDBC431909E3D42AULL, 0x6C8573B314135243ULL, 0xE7FF31135E39F6DBULL, 
            0xC33BFBE67110EE28ULL, 0x91133D5A8B83DC00ULL, 0x428B0823DA824C24ULL, 0x4AF950ABF94C197BULL, 
            0x14028AA4F3574FBFULL, 0xD71BE1211654764BULL, 0x127EFD586BF91861ULL, 0x2A86F624F602757AULL, 
            0x407E75DC3197CA6BULL, 0xB1FC38A605CEB3FCULL, 0x05CBB82C231E1F98ULL, 0xD5D143C2EB84E636ULL, 
            0x225D35F0A794A7DFULL, 0xAC7CBD69770C73AAULL, 0xE573B97CF57CB593ULL, 0x31D01C7AF09DB768ULL, 
            0x616E6F6B61DEE4BEULL, 0x2992FF3FDA4ECE4CULL, 0x7905FBB8473FBC7BULL, 0xCD8FDC10724CA14AULL, 
            0x5D15FC284DEFCA74ULL, 0xB9DFD4C71621DD28ULL, 0x6662B7ABBA7EE7B9ULL, 0x175A1DC8711FE728ULL, 
            0x824AF94653C00DE1ULL, 0x9CB6B7C983C9394CULL, 0xB28B61C9CD7307D5ULL, 0x922FFA8ADD0461E0ULL
        },
        {
            0x77C89B0391EE87E2ULL, 0xD853CC730E945487ULL, 0xF03AD45586129025ULL, 0x03D348ED518E9700ULL, 
            0x4B60F49CB41BA43EULL, 0x9F02C26891C6CF73ULL, 0xD0E612DC9450A263ULL, 0xCA8EA902CCFD21ACULL, 
            0x37DA1F2C4C165BFDULL, 0x8B7DABC9455BB8A9ULL, 0x467E8FBFC708452AULL, 0xEB5BE02F74711A3DULL, 
            0x46DA6303EB0BA32EULL, 0x387A24D5DECC157BULL, 0xA2811535E7CBCCD2ULL, 0xAE37DBE22813331DULL, 
            0x4284CD491669FB4BULL, 0x633076AFD8545B24ULL, 0x19890C74485CE655ULL, 0x94FDD4B8837E8E28ULL, 
            0xF961F17D497A2EA8ULL, 0xBE59950BB4993F01ULL, 0xC9CD3F643DC4DBF6ULL, 0x9C9191C36BD033A1ULL, 
            0x8D3EE8CFCA00883AULL, 0xBEFE01077B7F5FA0ULL, 0x21B3953241B9737CULL, 0xCF295DA217A02742ULL, 
            0xD5A3FA9021025134ULL, 0x1F2EE49414023ED6ULL, 0xC3D84A5787EC9500ULL, 0xB01C22D5D0B3E33CULL
        }
    },
    {
        {
            0xE7BAC58A1C72D7A4ULL, 0xEA576C53E159DDF0ULL, 0x88525FCA0E0A05C2ULL, 0xD2451A0750754935ULL, 
            0xDD12F247F6E3FCDEULL, 0x5048AB2A8099F4C9ULL, 0x69775F5C48671481ULL, 0x9AD351F2DC1F5575ULL, 
            0x5BDE45A661D25AA1ULL, 0xAA02BBA1A06B728EULL, 0xCE1E0FA5A4C90B79ULL, 0x9EBC66BBFFB86B34ULL, 
            0xC058A3FA8AE295FAULL, 0xC70653B4CB090AA1ULL, 0xBB64493B419456FEULL, 0xC56B0112BF8670F8ULL, 
            0x3D2177905DB091CDULL, 0x8A95D5A1D79BFA2BULL, 0x87CF6166A345BCB8ULL, 0xCC08E8F1182F4C53ULL, 
            0x5A42A2753B85A84BULL, 0x9328A29AAD9EDC9BULL, 0x78CD2D13022B27AFULL, 0xE26CD64D9DFA71B3ULL, 
            0x4B856E18A3056A02ULL, 0x18611B109D75C5FFULL, 0xEF0869E11686CB5BULL, 0x5B9451F613EF3508ULL, 
            0x75D5D162F7FC457EULL, 0x83795F0B3A1530F8ULL, 0x10D22FB55380FEBEULL, 0x7DBD3DD340908FD2ULL
        },
        {
            0x73382E349D06863BULL, 0x74DB6C3B46F444A8ULL, 0x0FD9D2F6347B999FULL, 0xE95B7D622C222DDDULL, 
            0xA1E37132725C5CBBULL, 0x3DF8F14AF6990311ULL, 0x7AA943D90953EF1CULL, 0x5F7FF9E0DB4628D5ULL, 
            0xECC33C9497D31DE9ULL, 0x8B4AB0567B452520ULL, 0x18279D54F0888134ULL, 0x46965352756BBD6CULL, 
            0xA965A7D111826BF5ULL, 0xD7FC102A78BC07EAULL, 0xF785BEE357C1AFA0ULL, 0x78AC5620C047BEC1ULL, 
            0x4DC8F56C5EC27BC1ULL, 0x30058B4C2EA4A34FULL, 0xC02E59BFCF855D0CULL, 0x352F3DEA89569C62ULL, 
            0x5293110032543C14ULL, 0xAD0566CCF5503E3AULL, 0x71CD52FD5F438760ULL, 0x5E6C414C2E037E9CULL, 
            0x5FDD0AAB5E3BE7C2ULL, 0xA26C4EB075C49B37ULL, 0xF2915D82E80A8599ULL, 0x6FE121E60782AA02ULL, 
            0xF862EDAE8F25165EULL, 0xE7A0BA2CBB35ABA2ULL, 0x4E362244AAE4B89BULL, 0xF2B0B69DF027675EULL
        },
        {
            0x3CFBDD5F623BC9F7ULL, 0xFB432A9D97CBA520ULL, 0xC509D26E63FFDD4CULL, 0x713530BE91DB8B5EULL, 
            0x8876EDB4D33BE68AULL, 0x3AA968F6167B1B0BULL, 0x76EEDF91475E2426ULL, 0x433D22007C02DA21ULL, 
            0x8FE8B76558660C6FULL, 0xDCAC549CDF6F7C6AULL, 0xE3316EFB1EAC7BDEULL, 0x46F0EB295AE781E1ULL, 
            0xDB345AB6D9EEB5D8ULL, 0x039A49066C7B3A01ULL, 0x38057EE032207BA1ULL, 0x77C0F4F51F451329ULL, 
            0xC273B0F35F8298BFULL, 0x0268A637A21EBAEDULL, 0x90989529DAE6EB5EULL, 0x943C3561680FA17FULL, 
            0xB9DFD580D4B972A8ULL, 0x7427A38BEE20AB14ULL, 0x77C9EEC784D0428CULL, 0x8E26E3D25032D4F5ULL, 
            0xDBE78F4161DC4A60ULL, 0xB16A6BA00BE88328ULL, 0x6CB72841FEDE75C2ULL, 0x7BDCF0362339F795ULL, 
            0x78A8A097250BA8C6ULL, 0xA95708019C49FA6DULL, 0x44D4AB0FCE82C12EULL, 0x7603B07976C737C0ULL
        },
        {
            0x0D778E564307FC68ULL, 0xFF887C92BAE7C0C8ULL, 0xEA208DF36D439C2BULL, 0x1EE0A10E7F99C741ULL, 
            0x098658E73A6CA008ULL, 0x1EE8D27A3E4F79DCULL, 0x31C0C60116399F7BULL, 0x4145EF7EE800B04EULL, 
            0x45F27482AFF5E12BULL, 0xA0B8A651A470CBDAULL, 0xA7D4F39F63F9A916ULL, 0xB61B98DCBCF1EAD9ULL, 
            0x8A341BE6710B3CE8ULL, 0x14860790E0DD1B34ULL, 0x0DC6BACA31125768ULL, 0xF3862D414D2BEDA8ULL, 
            0xFC7AF88EF04BDA2AULL, 0x7498A9A525101130ULL, 0x42C314146D95F930ULL, 0x38FD44805AA90C30ULL, 
            0x4062FA5FC4C498A8ULL, 0x3257D1E3FFF41866ULL, 0x684A21707DE20243ULL, 0x9B2D2A4B6F46C94CULL, 
            0x2C7EDF4D58123F8DULL, 0xC28100DDF4E4F03AULL, 0x90EC915BBBBB4648ULL, 0x651C54677D9C2167ULL, 
            0x27A50BF159BD5F7FULL, 0x2BD0583F81CDD632ULL, 0xEC0E596CC041C716ULL, 0xB956D3DD8020CF8CULL
        },
        {
            0xCBAF35DF02A052CAULL, 0xE793F4E2F68FBB13ULL, 0x87A842F4C685C101ULL, 0x78A8CE8372FD6DBFULL, 
            0x62558D6379C45756ULL, 0x7053FE849BA04912ULL, 0x784830D7C4725D3DULL, 0x9F60F42826E18139ULL, 
            0xB3C21C5DF3684848ULL, 0xCB1E6C9C5DEEA32EULL, 0xB4FE3ED3B1F9C250ULL, 0x4AEC0550F09EFD80ULL, 
            0x83E8E3ADB3399185ULL, 0x6F717D7DC581712FULL, 0xF7DE651CB352801DULL, 0x21737748D9D81E0CULL, 
            0x2857DAFB6B43272AULL, 0x145BB20CC1EF988FULL, 0xF089B2B9C9906F66ULL, 0x40810FFB4CD50978ULL, 
            0x9361A3E7ADF8D523ULL, 0x52CA4E7EE432D370ULL, 0xEF69D93FDC3F9706ULL, 0x77D857EC6CFD704FULL, 
            0x0C2A9EEB1E6B44F4ULL, 0xAF768B5275395C9BULL, 0x1976CF05BDB60C33ULL, 0x1B2658C42F93E0B9ULL, 
            0x131BBA8709100CA5ULL, 0xDEF31558C101C101ULL, 0x8C04E3315D9166EEULL, 0xE9BD32D5C8C7E632ULL
        },
        {
            0xD1ECB61329136D8DULL, 0xBF26053ECFF341D1ULL, 0xF38574A1B2192EA6ULL, 0xE396E15800F59798ULL, 
            0x455E567285CC7E46ULL, 0x888E53E1FC9E42BAULL, 0x01114E2C5BED6082ULL, 0x9CEC9759A692D082ULL, 
            0x4A9646502100B384ULL, 0x2455558DCF6848C7ULL, 0x02F5A83CFE540576ULL, 0xDB08370BD8AACFC1ULL, 
            0x39273CEAC29086B1ULL, 0xFB8139740460B503ULL, 0x3B786901FE3AFADAULL, 0xB5CFE6C11B3C2974ULL, 
            0x40F5D75F82E32112ULL, 0xC06FD42D5A6FECA4ULL, 0x58783DD8E431F9C2ULL, 0x1B52348940590121ULL, 
            0x38128A48B2944126ULL, 0xF4527184594DF36EULL, 0xD1B78B7121D6749CULL, 0xFAD12A2A6000E526ULL, 
            0x614A14B5AD0AF275ULL, 0x753C5EEFA67CFF0FULL, 0x54744C3AA46400E7ULL, 0xB2EFA611AFAF1543ULL, 
            0x2603DAA4A3D45996ULL, 0xE116E34E10026801ULL, 0xA650C48D55C14090ULL, 0xFFC91AD3A213AD62ULL
        }
    },
    {
        {
            0xC8D140526181F60EULL, 0x5D21AF77429E8BA8ULL, 0x0F4A75A1271E8EF8ULL, 0x0B00F60239C88171ULL, 
            0x45E7B06401AA893FULL, 0xDF302907A7135E39ULL, 0x52177B6FAAE1830DULL, 0x671AD065D33FF61BULL, 
            0x360BA9FF0CE4A420ULL, 0x39BC689B679635FFULL, 0x1F6396AF3F13837CULL, 0xD1023D78960FE65CULL, 
            0xD3B3B7AB8E4F886AULL, 0x028D081C657FC9D4ULL, 0x0D30E8AAC938857EULL, 0xED53F91B14D17B9DULL, 
            0x9FAFB18023D292E6ULL, 0x2B589DA22DC1BE43ULL, 0x81C154C565BBF8EAULL, 0x46CF2164D001CF81ULL, 
            0xD312AD0B88EEBB1FULL, 0xA31155F79EC270DFULL, 0xC5DD1B00F2569FF5ULL, 0x01948449DD96F79EULL, 
            0x360C97232FFF7AA7ULL, 0x761F55E5D0FF3DCCULL, 0xDE6990362B7FB52BULL, 0x67B8AD103E95D02DULL, 
            0xD8DF5AEE5130BEDBULL, 0xEEDAE16D1DDD1B86ULL, 0x3C8805FA34E04393ULL, 0x097C9EA7D52551FCULL
        },
        {
            0xB2BB0FA60F596E23ULL, 0x5A6C1674BE22D8B4ULL, 0x0DD766AC02C1458FULL, 0x63BDA03EFE01279BULL, 
            0xD0CCC26A88A6C5FFULL, 0x6B86BEE58A16DC2BULL, 0xF69FF07C92029A08ULL, 0xDF350C2F40C07C11ULL, 
            0x8DD08547776D505DULL, 0x92D5D6177582E8DBULL, 0x28AFF2DA154290B0ULL, 0x2B68A667894E93ECULL, 
            0xF31607FFE5A3F21EULL, 0x0F264F9108DE0727ULL, 0xFC16DCAC43D9ADE5ULL, 0x7A22D2FAB98AB715ULL, 
            0x9AA5D065B5A5E561ULL, 0x22457A3F467B1FC4ULL, 0x8F0765FCE5D55C84ULL, 0x90C98996F767DD0EULL, 
            0xC62427230E351244ULL, 0x02202180CEF7286AULL, 0xD3B7D7E6912BC67FULL, 0x3421B8DEC65529A3ULL, 
            0x5804EB1FFCA23923ULL, 0x21BC5FB949E83CB8ULL, 0xFECA48AB4FD589C5ULL, 0xADE580448A95BEF4ULL, 
            0x862D23432A034C00ULL, 0x29466183F086D042ULL, 0xDD3CCE578B9539A3ULL, 0x60D1CB629F193301ULL
        },
        {
            0x7B99207F4E0D61CAULL, 0xEF4E2F8C0FA1A5EFULL, 0x1F5BF53A7FC4F922ULL, 0xF54E32F53E700F8BULL, 
            0x27D65843E3111579ULL, 0x1DDAABACFE0E0606ULL, 0xA3D14077913028BFULL, 0x36134841748E14F1ULL, 
            0x4136CCBC52FC1378ULL, 0xB1AF41A2D02475B4ULL, 0x0A9A460CA56F04C9ULL, 0xAC699F67A08E8C95ULL, 
            0x4164421FCEE1AA04ULL, 0xC08928383FE4FF51ULL, 0xB00CBCA8446D8F8BULL, 0x8A074CDB74733FCFULL, 
            0x39AC3A54A30A6811ULL, 0x4ADA6E323B5BDF07ULL, 0x3CDCF08AD302CA4CULL, 0x0908E937607413B6ULL, 
            0x0646EF1382290AC4ULL, 0xD197ADC92773E655ULL, 0x3A3837C28A939BD4ULL, 0x7CB8FD1BAE086DADULL, 
            0xDD90DB8239DFE1ABULL, 0x74A913278F5F435EULL, 0x18F5A89AC4365262ULL, 0x51BD1AA40313A5E6ULL, 
            0x16EEAA696AD01E73ULL, 0x5CAE48BE5DAA7F72ULL, 0x96E0A074960B5C64ULL, 0x22F975F2A20AD132ULL
        },
        {
            0xCF68CE16A5F14DA2ULL, 0xB0F3B91CA7AA8C13ULL, 0xA3D7D9B4B576806FULL, 0xD24C4511E8C703AAULL, 
            0xDCE5D7B8BF6687FDULL, 0xBF5522DB8241576EULL, 0xED300747A4FFF467ULL, 0x4CDE29D1B54B4FF5ULL, 
            0xFD0C91A692821763ULL, 0x0AFE64E058A80984ULL, 0xB872FF4E280BCF27ULL, 0x7A1AAB4D6370FE3BULL, 
            0xD8F8B5AC59EAFA5DULL, 0xE7DA343AAB0D1742ULL, 0x621F3E3EB3C2B022ULL, 0x3CE6495EA7BB8C42ULL, 
            0x9E4DDE8CB6F55E4AULL, 0x37D7B61CFDB90F67ULL, 0x9934D4B3E6AE4213ULL, 0xA5B81F97AB811EACULL, 
            0x4B5E2E348CF3E192ULL, 0x9120EC0EA67790D5ULL, 0x1CD1009D5B13BF39ULL, 0xCBF20ACE3DC8746AULL, 
            0xC171A810D9719D8DULL, 0x59AD038583F953A3ULL, 0x5120C55351FE8141ULL, 0x53BD353C1DA759B7ULL, 
            0x91C861B8C05BCE3BULL, 0xE9F750794907E637ULL, 0x82B419884EF70635ULL, 0x4E692D68C0B30979ULL
        },
        {
            0xF970FF406336E13BULL, 0x9432E32A2353DCA5ULL, 0xDC51D02742CA6265ULL, 0xE713D326748E8077ULL, 
            0xA2CD454DBDAB2E3BULL, 0xCFF2FA798F2DF4DFULL, 0x072DED81840831DCULL, 0x53BDAD89401B1E55ULL, 
            0x8E6B022E6991E249ULL, 0x0190E42C43248CB8ULL, 0xF53F880D2431DEA4ULL, 0x6DB78A9D65A0DD44ULL, 
            0xF48E87A658904E3AULL, 0xE23FB557346F5594ULL, 0x3F068B68D8F5A0C0ULL, 0xC4F8DF065A085B3CULL, 
            0xB96E7C288A261CA6ULL, 0x37C20C8BE8F180A1ULL, 0x0C02707CD3B0F550ULL, 0x74C8969B2B4186BFULL, 
            0x11701AAE2768491AULL, 0x2B75556F0CC372C2ULL, 0x51494DB6E49B0597ULL, 0x49845EF70992C56EULL, 
            0x63EA4824BA54A819ULL, 0xB8F299562239FF00ULL, 0xB86A03F27AAAC862ULL, 0xABC67B6BA0D61F15ULL, 
            0x6602A975CE08059AULL, 0x62F0E3260A4EC32FULL, 0x158640A87F960A16ULL, 0x6ECA2D4C31F4059FULL
        },
        {
            0x8974FEEBBC712167ULL, 0xC3F124159673C204ULL, 0xF77796B819475FF0ULL, 0x2FFF4B8430EC98B1ULL, 
            0x5575EF9B2B97C317ULL, 0xF16DCCD369E84039ULL, 0x27E499461D647C7FULL, 0xFBF7D8956E18DFA9ULL, 
            0x202ED717338F1AA9ULL, 0xA2D0C31A3BD85160ULL, 0x5F3E16D650A43F26ULL, 0xA255F9B53DDE4808ULL, 
            0x2F18A6D043D04998ULL, 0xBDCE6A638724B8B5ULL, 0xF75A2A2286C15D17ULL, 0x71A1B996BD17F260ULL, 
            0x9BC3256307165DFBULL, 0xD5535B875D06442CULL, 0x8B43F0A0EC182776ULL, 0x077917CBCF74EA24ULL, 
            0x743FCB76A178FC8CULL, 0x558B938C9C29CCAFULL, 0x9BBC99B385539059ULL, 0x3965FA7EEFBF1EF6ULL, 
            0x41C49B29275DD97AULL, 0xB4242F9D4B327DE8ULL, 0x97E4F965E5B19483ULL, 0xCC8E2E819E9ACC78ULL, 
            0xE3DE7E01BCBDC942ULL, 0x71D06C24C71E8F6DULL, 0x9C84ACC8A04E9C3DULL, 0x07E34450C968A9A0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseBConstants = {
    0xC01A8E13CE0219E6ULL,
    0x1FECAF50FCDA9041ULL,
    0x3F644E53A80DA31DULL,
    0xC01A8E13CE0219E6ULL,
    0x1FECAF50FCDA9041ULL,
    0x3F644E53A80DA31DULL,
    0x523BE5B3F2226D52ULL,
    0x3A005E09F15FE2B0ULL,
    0xC5,
    0x8C,
    0x4A,
    0x4D,
    0xDF,
    0xA6,
    0xA3,
    0xA4
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseCSalts = {
    {
        {
            0xD4655AD042F659DBULL, 0x210DA3BA835C2A20ULL, 0x121DC535E2B979A4ULL, 0x37CDC7A1830730C4ULL, 
            0xA93719CA325EEC7BULL, 0x7E02CD10AB1C12C4ULL, 0x748813AED226BAC9ULL, 0xF400711059B9CA52ULL, 
            0xE5599A5A433163C3ULL, 0x548775B445AE9E2DULL, 0x1208489B71243C4BULL, 0x0B182306DEDAF006ULL, 
            0xA9DB132FA14F546AULL, 0x7D7BBCEF8FEA9A04ULL, 0xA046C4114AAB4046ULL, 0x760D959AAC2E2381ULL, 
            0x827476B226BFF6CDULL, 0x12C05F2EE3AFEFCBULL, 0x4DF25A51744B4495ULL, 0xD70D5C693E4ED3A0ULL, 
            0x08B6A90B4C574AEDULL, 0xDCA0120B0E6484DFULL, 0x98E2012F01B07869ULL, 0xA80845BBD3826205ULL, 
            0x042A3EEE8F7D852FULL, 0x9CB2944C21D9C029ULL, 0x880E70DC2035C80DULL, 0x64036051A8D0DBE4ULL, 
            0xA4D8C72996939667ULL, 0x664EE765D8A70895ULL, 0xDEC5AC538B11D204ULL, 0x9E2A6CF4339F1F44ULL
        },
        {
            0x2CBE6D5BE7D14066ULL, 0x8FE21C58F8C3F004ULL, 0x25C95A41734A9985ULL, 0x40BE7E339CB68A0BULL, 
            0xB5BD00BE28644CA1ULL, 0xB5D54BD959565100ULL, 0x72F636A488580B02ULL, 0xA92312E7F58B97B7ULL, 
            0x947EBA3433B2632FULL, 0x33FAEECDAD6191D5ULL, 0xD855F7A33F027A0DULL, 0x1D08B5CCED5949F0ULL, 
            0x1B2D08105E5596ADULL, 0xEB0673AB9C23B6E5ULL, 0x1416D73918FDF354ULL, 0xB99FA4694641A632ULL, 
            0x122CCD680914701AULL, 0x4D0B832A953CE3E8ULL, 0x041CFAE57F86D4CDULL, 0x27378F1057F30264ULL, 
            0x080045C37E2A7B73ULL, 0x702F0FD992AC3010ULL, 0x1DC9BF9305B7D6A0ULL, 0x778DB8ED22250E12ULL, 
            0x2E51C0E8361C002FULL, 0xB8526C8B7EE072C6ULL, 0x502ACFE70873DEB8ULL, 0xC66FFF1F736020A9ULL, 
            0x979CAA56ED7860D7ULL, 0x466049FE467C5B67ULL, 0xBED15D8EA364393CULL, 0x396349C741B9A6E6ULL
        },
        {
            0xD55368E9FE03EE37ULL, 0x249859CC35B2C832ULL, 0x60B0CFAA0E5A2378ULL, 0xF49FB786C9024D49ULL, 
            0x4855EB214C440A50ULL, 0x529BB5D4F3432507ULL, 0x965F373A1BEB030EULL, 0x85897DEEA4E511D4ULL, 
            0x31875468BCD7515AULL, 0xB85D5C0AEEFB49E4ULL, 0x8C3BFF1F95860F13ULL, 0x00B8E572E9D48C0BULL, 
            0xF9FE269469E92875ULL, 0xCC652429EB3D583AULL, 0xD971B0D1621B616EULL, 0x9ED1D09B54947179ULL, 
            0xD05F1E3029408C0BULL, 0x6A519F90D83FE2CAULL, 0x77EFC8EECF81978DULL, 0x8B621BD43C2D7C44ULL, 
            0xCB89227CD756C9B9ULL, 0x4998EBE8208EA005ULL, 0x161A70896D73F6B8ULL, 0xAF1DDAC27FA45448ULL, 
            0x4D1EAC0AF0604033ULL, 0x55BCFC4EAFA1CC15ULL, 0x718974156B7D0595ULL, 0xF86386F8762A5579ULL, 
            0xD4EE2B9800BA52A9ULL, 0x08CD27C0489F0A16ULL, 0x1F0915D0FC8C5229ULL, 0xCACAF0232DA5EDF5ULL
        },
        {
            0x3EB803B6A7472D79ULL, 0xBF2EDD1029245931ULL, 0xD5BD34EE0D9D2002ULL, 0xD5F8A9CE2401B845ULL, 
            0x54F454994B86EAEAULL, 0xB297CD37D0FF38ECULL, 0xBB41DD6E28EEF975ULL, 0xA0090E0AFC4539E6ULL, 
            0x21B3684E3AEB9045ULL, 0xB6F01FAC118B89C0ULL, 0x9E737E7B81DEC18BULL, 0xB63C841021146FABULL, 
            0xFF186AC7CCEA0171ULL, 0xB14BFBAC30ED1B2FULL, 0x87949A3AAA8FD827ULL, 0xE1872CDB3012F692ULL, 
            0x9820078ED9FE4523ULL, 0x4A6BAFA829B38F03ULL, 0x18071EF35EEEBB00ULL, 0xF871C059BAF02A87ULL, 
            0x2FA4CF8D554D0DCBULL, 0x65C960FE86249678ULL, 0x4F2035C2E8966A3FULL, 0x8820D2C145664883ULL, 
            0x2EBDCE5E78D96F96ULL, 0x0CCD3EADAC243B28ULL, 0x8E25C26A7E0BF5F4ULL, 0x65F37FC24DC462F6ULL, 
            0xA1C27E4E76180945ULL, 0x95ADE8C0DA435BEBULL, 0xA9E25562F2C96E17ULL, 0xC77333B12543858FULL
        },
        {
            0x0DC4FFB6DCCDF133ULL, 0x2B1BDB4BA8FB707AULL, 0x5BD19E61DFBA1869ULL, 0x1C6C1D3A7D07207CULL, 
            0xF83802FBCC3DD351ULL, 0xE3A4DA830AB63F22ULL, 0x32BDB9D2F48FA8D7ULL, 0x92F00B067439EC97ULL, 
            0x2721F6CF078311DEULL, 0x7B5F366B9C5608B9ULL, 0xC392FF479078BD43ULL, 0x55206E1D402A5C29ULL, 
            0x168C0E73C40C9ABBULL, 0x5DA34AE031871B07ULL, 0x542B1E24448C5B51ULL, 0xC1F95B5CC651C8DBULL, 
            0x3D2B48898B4CC687ULL, 0xCDF4DDB8778542A5ULL, 0x9C8B15D3D22C3170ULL, 0x44E61F504CED9DB0ULL, 
            0xC21C0485AF15016FULL, 0x5D812F32066DC533ULL, 0xD63970C31944B61AULL, 0xB9A558DBDAE0169FULL, 
            0x3E3723EBCE7A67F6ULL, 0x243ACE911AD5D632ULL, 0x57A0A8E80BC6D70CULL, 0xCAC665F85B2BD2F6ULL, 
            0x4057A20D4EFB0697ULL, 0x3B706B0725462820ULL, 0x73B403F81467C56DULL, 0xCD825B641D8C9E95ULL
        },
        {
            0x8BA4D7C25048EB72ULL, 0x536EF8E18F2EBD24ULL, 0xF21337153385707AULL, 0xA8B9C7B9B2D9C345ULL, 
            0x3A9D37753B6C619FULL, 0xC0C848BDBF1195DAULL, 0xB782E777AEA407AAULL, 0x1E82EF8BBCADF25EULL, 
            0x8853E86F3FCED90BULL, 0xE3C773E83A95A1E1ULL, 0x1D73216B708B373CULL, 0x364C379FFD0E38E9ULL, 
            0xEBF3F248621639B7ULL, 0xF3C9A036D801031FULL, 0x8FFE8B4CC89F1C5DULL, 0x7531FC2F5A1884BAULL, 
            0x4811DFABFE3268E6ULL, 0xB33A2EC628CDE5ADULL, 0xB99CBBDAFAE56D81ULL, 0x4BF782867AE78FD3ULL, 
            0x9264596C85474C41ULL, 0xE3B86C42D8671AE7ULL, 0x0E00D23DC87B71B9ULL, 0xCEEFF0A9287E7FCDULL, 
            0x10F559A40714B99AULL, 0x9B5BC82912E54F24ULL, 0xCFDC75CEAC4A360AULL, 0xB93B8E963815D2EAULL, 
            0x6750C832A4CC160DULL, 0xCBA22C2286E50D64ULL, 0xA052E74885651834ULL, 0xAFDEFE5F2AE87A90ULL
        }
    },
    {
        {
            0xC5AC0264739EC64BULL, 0x1A165247606027D6ULL, 0xFD55DFFA6233456AULL, 0x96C1321E455F4ECCULL, 
            0xD62E078E1A341E8FULL, 0xF2BFA77934519946ULL, 0xC8D84E1CA8783099ULL, 0x6973900C00585803ULL, 
            0x83A64D9D798909E7ULL, 0x549F6256A5B60FE4ULL, 0x4D3FB206D335444DULL, 0x9E6052EDDB729CFFULL, 
            0xA0EDD71BF1F5B923ULL, 0x34C6B78E198F5D78ULL, 0x818631BDBAEAA860ULL, 0x92532C039D0F045FULL, 
            0x17B1729937DE898FULL, 0xEB72B7592A0D51BEULL, 0x288B2ECB0844CD87ULL, 0x701A8D610ADE5780ULL, 
            0xE8D1465D4C1124D5ULL, 0xD999FBAE15C46DB4ULL, 0x235B2DC3693F7302ULL, 0x918FA12567B1075EULL, 
            0x117A592BC3F9E06FULL, 0xB9C2A6A722A1BD5AULL, 0x5AB0BD1977E0672CULL, 0x56A833C77E881706ULL, 
            0xBA6AA177BD2D8F17ULL, 0x4FDD52498DEAA092ULL, 0x05AB589C4D7F8AB4ULL, 0xC1883AD503FC364EULL
        },
        {
            0x89D675AEE4F8AD3DULL, 0xFC820B5A5D09A8E8ULL, 0x882104C2B082AE9AULL, 0x63CC9C03BF906991ULL, 
            0xE89542C97C87997EULL, 0x0E0D1D8EF79236F1ULL, 0xE428C226FA95039EULL, 0x30CDEFCC94A1CE91ULL, 
            0xE22B7C63EA85DCA0ULL, 0xD135E77D6B2AA310ULL, 0x2E6829401C16DEEAULL, 0x5EE5F8232C80F4ADULL, 
            0xBB2DE1755EE4E421ULL, 0xC55CA6BD5BC9BDC1ULL, 0x89D16ECAB7166195ULL, 0x561C68483273CB41ULL, 
            0x108CF46E91377762ULL, 0x9628541A0AB7FBCCULL, 0xDDD813E9EB26DAA7ULL, 0x6E54E1CF2F854EFFULL, 
            0x57C5DED382AF431EULL, 0x049291985F76AEACULL, 0xB37E606C9FAD4094ULL, 0xD02407E12A979490ULL, 
            0xBD6A0EF1B7AFF990ULL, 0xA567BFA648D24952ULL, 0x2DCE9171DB2044E8ULL, 0xDEC51F5280AC2572ULL, 
            0x70C61B2A40A2118DULL, 0x2FBD06C3FD97BBC7ULL, 0x3D240ED568158943ULL, 0xCBAA884F3AAA29D8ULL
        },
        {
            0xB87472F25EC5E4C0ULL, 0xB8C52D81DD58CF8AULL, 0xD10CF169D747BA64ULL, 0xEEB4A2024FA1F533ULL, 
            0x0F689DAD77A3DE46ULL, 0x2606369AC40E176DULL, 0xF71C887ABDB84D63ULL, 0x564F421AB09062CAULL, 
            0x5A26920EC8D9C08EULL, 0xCE38E8D16BA71F88ULL, 0x7F7187E551D65B79ULL, 0xD21D6D8429BEADFBULL, 
            0xFA0C80A5E3A64B51ULL, 0xF96E55787F7DFB6AULL, 0xBB95AA52F38C3A39ULL, 0x4C065A2571A41530ULL, 
            0x2935146119EA2DB3ULL, 0x19883AFA962D415FULL, 0xB34363970E5A924EULL, 0xDA74880456EEEC60ULL, 
            0x79F5D7868EE11932ULL, 0x7C3AB55C74149808ULL, 0x318A7603750948DBULL, 0xAA43BE30AA1D6890ULL, 
            0xB6909E55DF6688F3ULL, 0x4BB93741848B19FEULL, 0x33564CBD06DD7218ULL, 0x9351C57C1177CE03ULL, 
            0x4F947355A70AFF64ULL, 0x9AE61932B92591ADULL, 0xB8A2066E0334C5D0ULL, 0x05A68A83B4F38BD9ULL
        },
        {
            0xB43368BDA973D7F6ULL, 0x52E2C58D46148E79ULL, 0x54BAD7DD7E14139EULL, 0x8720DE29317546AAULL, 
            0xF9D51BF98B8ED2E4ULL, 0xD3DC1CB594453ECAULL, 0x17E2BB6B3ECFBDB7ULL, 0x95E4E3FE4A7818CAULL, 
            0x53C4354FDA338D9DULL, 0xFFD0A455A351255FULL, 0x4B41DCBE1885C42AULL, 0x1B4428ED53CF8D49ULL, 
            0x1134152E38BB80A9ULL, 0xD76E6187A93EFFC5ULL, 0x51A3D5C7DC4DB43CULL, 0xBFA1800A9C729D4BULL, 
            0x07329CAF676B1EC8ULL, 0xEF39F891D9D3B2A9ULL, 0x1EE4AAB391843C25ULL, 0xAA467746D431A1A7ULL, 
            0x27043AA778B06139ULL, 0x5B2050446A6D966FULL, 0xC5FA12D1DCE059C6ULL, 0x25C77E465EA16659ULL, 
            0x13AFE6BDD314D29EULL, 0xC6888961CDDD7565ULL, 0xE1D78467D53E6384ULL, 0xB1DE7A5868895460ULL, 
            0x2B558198DA80826BULL, 0xD2DBF07D928DD753ULL, 0x299A189C7737B74DULL, 0x97BB872F3307D9E4ULL
        },
        {
            0x8F22762D23510040ULL, 0x87923E8E9C58CED7ULL, 0x2B7FB9A0436FCC82ULL, 0xD1E60D7CBE3D94B9ULL, 
            0xD9200B5C1196E2C7ULL, 0xD292250F26837785ULL, 0x670D13D815AF3024ULL, 0xDE7B09FD5C8C35A6ULL, 
            0xF1553F086895C3D4ULL, 0xC3048652C44324A4ULL, 0xD137FFBC0764E8A8ULL, 0x11D6675578F322B8ULL, 
            0x9D90B7EF20C605E7ULL, 0xCC92419EC87DB607ULL, 0x64773848CCC77634ULL, 0x7EB8E51601CF3FBDULL, 
            0x9DD0DA2CED364824ULL, 0x490F7BA2CF94B6DFULL, 0xD861DC4FB16F1D5EULL, 0x3B7D625CA6BE8ECAULL, 
            0x4870A523A1F427A7ULL, 0x1F6040653C27D082ULL, 0x828C7DED7D29B16BULL, 0x607F5AC83F3F1468ULL, 
            0x1FE6DD0CD0DDAECAULL, 0x202DF480C9A6A50BULL, 0x8601CFB5299A7552ULL, 0x40A0306031BD8B8FULL, 
            0x78B7CE8683076F50ULL, 0xED88DC2ECCB13AA6ULL, 0xDEEB7ECD5ACC0DD3ULL, 0xF28412DFF082731CULL
        },
        {
            0x5BF26985DB1890E3ULL, 0x7CEB2257003CD27EULL, 0xDFC5AAB1B7CDCAFFULL, 0x125AB6BFC9B3E2CEULL, 
            0x16814E306C2EFBFEULL, 0xEEF547A47E1D3A44ULL, 0x2F2BDB2966361BB0ULL, 0xDA83643701C6182FULL, 
            0xBCDF78BD0166B611ULL, 0x7BB8E46362DB7071ULL, 0xB5A3617B707F130EULL, 0x4523F023A47BF3E8ULL, 
            0x0DC5323746B74950ULL, 0x8DBE60AF8D6EDF35ULL, 0x1AFBAD0ABD397CE9ULL, 0x5227557C140ECBCEULL, 
            0xCBBE076A5B867E34ULL, 0x5E334A12F10278ABULL, 0x2DA0F4C66D1E61B0ULL, 0x34F8718C28DA3446ULL, 
            0xBC684BE3744C995FULL, 0x6549369E77332C09ULL, 0xDB3B3A52BE2D0ABFULL, 0xAD14DBD55F49D780ULL, 
            0xB0EB746FA95272F3ULL, 0x63C2B5D7C65BBA3EULL, 0x01ED0611CD568953ULL, 0x8255F9C5CF70B238ULL, 
            0xECF141228C1C422BULL, 0xC180D498415025CAULL, 0x64C4F8E45A83A7F3ULL, 0xE7AB0405EF09707EULL
        }
    },
    {
        {
            0x12D39D9B74648967ULL, 0x393CF257113FC54DULL, 0x0306B825BB9C8773ULL, 0x40B960F26CCAFBA9ULL, 
            0xCD1BA5306E5CEC2AULL, 0xF3817D957D22CDB3ULL, 0x11D6360BA4D90B31ULL, 0x11D78C87B8B0AF04ULL, 
            0x37D0C996ABA0FF95ULL, 0xE9745E0774116483ULL, 0xD8F2F8AF34B80E56ULL, 0x3BF8B72531F5AEEEULL, 
            0x9773BDA3D36E3BB7ULL, 0xB7D801B97B9F5682ULL, 0xF90A83A4F992EAC8ULL, 0xF6F5F8D5CA30CEFFULL, 
            0x93A5DF780CC17325ULL, 0x2776B9FD82B98AB9ULL, 0x7D1034CC680CAE08ULL, 0x9BB3D3A6D1B83D3AULL, 
            0x3B7834818F664445ULL, 0xC72A7A3CBFCD63DEULL, 0x703AAC841D05A988ULL, 0xB439453D1CAE1653ULL, 
            0x75E06421B6D67A21ULL, 0x14F3AE3E87067A3EULL, 0xC8849E853702D287ULL, 0xE0C398A0FD2C792BULL, 
            0xAFD8A917EF05EFD9ULL, 0xADC72333CA54E3A7ULL, 0xE71FC2AABFB11881ULL, 0x004E016564B45666ULL
        },
        {
            0xA524BC18F4E3DEE3ULL, 0xE3864827103D6D5FULL, 0x6B1DC97918D9CF6CULL, 0xC14877F6DC10EAF6ULL, 
            0x51258611BDFD71F9ULL, 0xEB4EAFB812082E4FULL, 0x247011A8F9418DBFULL, 0xDE48E36EDA6573D9ULL, 
            0xCE21CED5C1DF9FE7ULL, 0x4E85650646F57D60ULL, 0x6DAF8320A36ADD81ULL, 0x47D2DF908AD0DCD5ULL, 
            0x0B5970BB0BBF4FEFULL, 0xDB399EBBB1697A6DULL, 0x069666133A0F7D59ULL, 0xCC011E1CA96855A6ULL, 
            0x0BB07C97EE4E2A6FULL, 0x190D3B308F4795C5ULL, 0x4E27729223DAAE58ULL, 0x1532A3801870E5D3ULL, 
            0x27200F788028AF5BULL, 0x9129A6E10B2A33BBULL, 0x06CF2B140526E92BULL, 0x2311884DFBA13834ULL, 
            0x32F555D612DF3E82ULL, 0x6FCF6F49736659F9ULL, 0x84E8CEB221487BFFULL, 0xF8913188DDAFD130ULL, 
            0x2D0D5FB02EAFC749ULL, 0x733D2A389D6A1BBEULL, 0x569FA300B8701EEFULL, 0x651CC65F4EF0CD5FULL
        },
        {
            0xFE0AED656F1FDF35ULL, 0x0B7613A8ADB54C8AULL, 0x790A9F6837DCE7EDULL, 0x71895A8E0B3BE16EULL, 
            0x165D8803AC6FC82FULL, 0xCA2359F5F56EEFD4ULL, 0x10A62327F5A454FEULL, 0x42B2FD75DE887A1DULL, 
            0x2C3A4FEA3822C31CULL, 0x7509D0857ABA23D5ULL, 0x3376C946F1A384EAULL, 0x4F76B7918F9E67E7ULL, 
            0x11112BC306E39E2CULL, 0x366AF55BDF15651EULL, 0x1415E541D4B0A175ULL, 0xE0DFA17CC5085109ULL, 
            0xA5A81E9B4DEE79CCULL, 0x2D455DA1318108B4ULL, 0x129746E8DE52ED60ULL, 0xF4F235339E01EACDULL, 
            0x6D15C26086C79930ULL, 0x80A23D5991B183B7ULL, 0xC6E41336EE2469FFULL, 0x1FE60A70A83076CDULL, 
            0xC6C6D88E13C2809DULL, 0xFCFB5AC72DA7A621ULL, 0x2046182F1D1F73B5ULL, 0xDECDDA71E024E0F5ULL, 
            0x01125EA8A8429EE6ULL, 0xB4245AB112709DFAULL, 0xBE90BA86DD522007ULL, 0x6CCB0C1EA4AF381CULL
        },
        {
            0x2FB0CD28958D4858ULL, 0x9836FC5923CC291AULL, 0x7F5704739FCF9830ULL, 0x32AAA6BB11F1AE58ULL, 
            0xF5968EA4DB5B6660ULL, 0xC6605AC0189CCA22ULL, 0x5C57531E1D53231AULL, 0xAEAEB5E434F2AA78ULL, 
            0xC6D6AB6457C7855CULL, 0x5A05DBD43FD289C4ULL, 0x4A4F2190DA3AC743ULL, 0xD9D305351BC234A4ULL, 
            0x6B453BEE8B515BF8ULL, 0x3C0323E60A4E89F6ULL, 0x83AB1E468C90FD02ULL, 0xFC40C5241DEDB421ULL, 
            0x5D8437961309C1F9ULL, 0x82409A0DADA266C6ULL, 0x0D470685DA6E89ADULL, 0x27902B5701F6C7FCULL, 
            0xBD20D369C21F3722ULL, 0xFEE977841790725DULL, 0xE68BF327393E75E5ULL, 0x00F2FBAA7AF30B8CULL, 
            0xA6CF42F017BA596FULL, 0xD7C5E0A545E31465ULL, 0x61010A279F407A22ULL, 0x89E150AA596D3997ULL, 
            0xB627E378ECE233B2ULL, 0xAAFB4E234B5E551CULL, 0xCB8B96B50F2B18C9ULL, 0xDCEB444C4F170DA5ULL
        },
        {
            0x8AE419CBFD7BCFBBULL, 0x74DFCDCEBF49C6F5ULL, 0xBAFD045F92AE11D1ULL, 0xB1AAD547F3D1D450ULL, 
            0x67C2B75CB4319907ULL, 0x16459F650D787FF9ULL, 0xFB89E1CF2844037EULL, 0xA15713D8B07B53C5ULL, 
            0xC864B2CDCC822372ULL, 0xB5DD1DA85AB5A496ULL, 0x5ED4640D3DB999A3ULL, 0xA05A67AD7DD69C1AULL, 
            0xB6AB0F2FA062477AULL, 0x1C7BF8AE55686335ULL, 0xE9CE292E623D2508ULL, 0x56550CE8BE0483F0ULL, 
            0x3C6FAC1D618CBEFDULL, 0x13A091883B68BAB4ULL, 0x93D5AD9BABAC1123ULL, 0x349266AA72A7EA24ULL, 
            0xE3FAD51551701CF7ULL, 0x836D3A4DA390EC98ULL, 0xE645B54DEBAC2616ULL, 0xD3AC40F4CA0516BDULL, 
            0x271A791E3C3CA449ULL, 0x48701CA2E0B8943EULL, 0x2EAA5327A01DEF11ULL, 0x0B4B71DED75036B4ULL, 
            0xF842C18B10ED5D48ULL, 0xA8C7DAC827665043ULL, 0xD65935A4C28CB7D5ULL, 0x27B000B23B3001E0ULL
        },
        {
            0x72E1631346F6DE17ULL, 0x59376CB02B230ACFULL, 0x7641CB5BE524A24DULL, 0x7B8270BD5A783319ULL, 
            0x7DA2A583AE603D64ULL, 0xD41F7C45750ABEDDULL, 0xE5709C50BA5F6051ULL, 0xE1D0F6C95F1FAEDFULL, 
            0x167E22F86FD72064ULL, 0xFEE2F3C29AAD9EE9ULL, 0xF16346FC29A7A67DULL, 0xD79764A77BFE0A26ULL, 
            0x97CC0A99A553F78EULL, 0x6808D3038FD5AAEFULL, 0xFA0C07159FC23794ULL, 0x5BF39B8ACDB1DB24ULL, 
            0xDBE79C8F9181E0BDULL, 0x5AC06CC86F49D596ULL, 0x623EBF5A2AC28877ULL, 0xFEE266519B145DCCULL, 
            0x1C5A4ADE2EE8A276ULL, 0xF695DDE8C6200B83ULL, 0xF071E4D00929ADC1ULL, 0x0A74023DB1758872ULL, 
            0xF4E4CB6D4EFBAD53ULL, 0x0D6B3C722471C71BULL, 0xA66859EFB974BE08ULL, 0x179B92CF77DDD4A0ULL, 
            0x68F38ECCB9678464ULL, 0x5CD38D8AB402AAD5ULL, 0xFBC5E0FA8658BF25ULL, 0x3B4394CFC79766BDULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseCConstants = {
    0x500CBED7A79BBD21ULL,
    0x988495CD552ED795ULL,
    0x1EA8BF16CECD1E94ULL,
    0x500CBED7A79BBD21ULL,
    0x988495CD552ED795ULL,
    0x1EA8BF16CECD1E94ULL,
    0x2BD4B0C42EA95D1AULL,
    0x29F3E7DDE2BFD681ULL,
    0x93,
    0xFC,
    0x4E,
    0x2E,
    0xD0,
    0x45,
    0xC8,
    0xED
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseDSalts = {
    {
        {
            0x5F90D4A26F27CAABULL, 0x45BDB43B9661DCD6ULL, 0x8938FCD44C283722ULL, 0x43C001915CAC56B1ULL, 
            0x4AD0F25819AD7FECULL, 0x2697EEA3C5FCE339ULL, 0x72F6A496DC810A66ULL, 0x710417CABE65D7CBULL, 
            0xE669755D00FE9EB1ULL, 0x027619AC1EE8DF52ULL, 0x72ACD92EC5641E2AULL, 0xBE94A864E95E7660ULL, 
            0x27B973B64366AD24ULL, 0x8E66E65CFAD998BDULL, 0xF14A28C045665D08ULL, 0x124F471E3E33DC06ULL, 
            0x3A8236875B30B643ULL, 0x3D8A69DCAFF22886ULL, 0xFD7D21A0AFA86404ULL, 0x63C692948BCD7876ULL, 
            0x56712BA050A281EBULL, 0x52D73F2605C45E76ULL, 0x38704245CA68727AULL, 0x4B8AF99BD6857B71ULL, 
            0x0F47B7512C4B9F98ULL, 0x093C19624F2FE9D1ULL, 0x46421A22BE06B91CULL, 0x27668374766E9D95ULL, 
            0x04EF8069682245A4ULL, 0x95571DBB3668B3ACULL, 0xD4A9E329A9CBD045ULL, 0xB2924335FF092B0BULL
        },
        {
            0x0447F8292BBC9B96ULL, 0x60066429A4BA38E4ULL, 0xA0BB19BD672294BBULL, 0xFBD090CCE33E7859ULL, 
            0xB79E127A2D5DF59CULL, 0x8CAC3BDB1661B6C1ULL, 0x61F49AA53685AAB1ULL, 0xDD92AF1E2502B09FULL, 
            0xE9D865C30A604249ULL, 0xECA23EBADB8A4924ULL, 0xC6BF765D92A62B59ULL, 0xA08956F033917BCEULL, 
            0x86A44BB8101431A5ULL, 0x60DF2F5A9D3CFAA1ULL, 0xC8B229C5E025F21BULL, 0x921B21C3DFAD2481ULL, 
            0xF980BAE487FB3DF5ULL, 0x46B27D9BB118EC59ULL, 0x4B93EE207CF5D181ULL, 0x45D5816B94442BEFULL, 
            0x161609D18609A334ULL, 0xDE9AFE27C420B715ULL, 0xEED46E3AECFE8C74ULL, 0x813CA308D7E05B0EULL, 
            0x4B1E00B10B7B6352ULL, 0x3091E2662128AB83ULL, 0x33CD10A862356724ULL, 0x667DF2E1BD70AE56ULL, 
            0x368FADC15AECC179ULL, 0x2FB3A063564AD52FULL, 0x5169B4A94629E018ULL, 0x3CD1260626B0E15EULL
        },
        {
            0xC98022786E48C25DULL, 0x661B5B7108558B81ULL, 0x06E05FCCE4B3E99BULL, 0x5164ACD67A7C6D77ULL, 
            0x0285A99F7F4DCCA5ULL, 0x5DA547D3ED5DB7D0ULL, 0xB1B44E3914DF4E3BULL, 0x349E4CC8F420B1B2ULL, 
            0x03F1787B79599BDCULL, 0xA46FD4B3E28DB262ULL, 0x08A5924FF0179DBAULL, 0x7232D83AFD9076B5ULL, 
            0x65ABC8A4791DD608ULL, 0x3FCECB116B1B210AULL, 0x8760DD7C7A519B28ULL, 0xE798914370A52715ULL, 
            0x87F0D49FD8F450C9ULL, 0x4107005A9C528264ULL, 0x0574BA368EC80E90ULL, 0x6D2363551BEA4C88ULL, 
            0x0CCBD0BEB6C47247ULL, 0x775B4A9A97DC3978ULL, 0x601F5A6A0A0C3C59ULL, 0x3CDBB3950C93CCD4ULL, 
            0xECB47878D5D901FDULL, 0x091BF6724A31B391ULL, 0x4D62299C6FBB0C84ULL, 0xE7CB67E311E47396ULL, 
            0x7F3B5D70FCB70A21ULL, 0xFC70CD2477D4EF5FULL, 0xFD3BA1B4F0892731ULL, 0xFB58182B4D305779ULL
        },
        {
            0x338A7013A3A5E9C1ULL, 0xD5109DF23C4B5F11ULL, 0x916C7959C6034E6EULL, 0x4DF64B4093A46363ULL, 
            0x7A72BDA4B5945FF9ULL, 0x4F5381036ECEF684ULL, 0x7CD625D6244CB2C9ULL, 0x48E485CAAD88317FULL, 
            0x4727C06041A4BC80ULL, 0xCF1F623EE19FEC92ULL, 0x0BE70A05932F7DADULL, 0x9E06D522858049CBULL, 
            0x1CB46B2442AE0C83ULL, 0x676AAC519D727B40ULL, 0x31F17B9E39B7DF62ULL, 0xE7B864863002CF85ULL, 
            0xE46117E9418C0B51ULL, 0xAC5F6B8E57074FA1ULL, 0xCA57E73F6ED7B1BDULL, 0xF3ECE382BC1A7626ULL, 
            0xAC9B4988E79311D9ULL, 0x0B35CA1A3222FE46ULL, 0x84057E8D430BC81EULL, 0x266E0D93B447AEEDULL, 
            0x0F010908DB496E80ULL, 0x98B0E9C8F3156CF0ULL, 0x566F3C64BED5ED2AULL, 0xB68CD04F4BC30C65ULL, 
            0x570E7B76202AA27BULL, 0x73F609045A83DA1DULL, 0x7CA6AAEB03428BDDULL, 0x69E0A9714246D2F9ULL
        },
        {
            0xE2D7017EFFBA76C8ULL, 0x94D8D8401B9FEDCBULL, 0xF99EC2133333A4D3ULL, 0x6E7C27DD54EAB42FULL, 
            0x0D37C5178306B69CULL, 0x3339D1E6F8250B89ULL, 0x4A59EAE40B6137D7ULL, 0x02EEE6ADA24B1052ULL, 
            0x84B600BF3A35E9CDULL, 0x41F4E9C557D45085ULL, 0xE87FF18701A66B64ULL, 0xC7A396861A6CB03DULL, 
            0x283A9FC940B3C6FDULL, 0x9E93C7003A8FD1C5ULL, 0x292A30F45E71154DULL, 0xCCBE4EB36778817DULL, 
            0x12D417C06BE8C84FULL, 0x0EB7EC13F3E498FAULL, 0x1CF476C463BDCCE3ULL, 0x6FE172D664D510EBULL, 
            0xCA05689F4E7DC90CULL, 0xDEE98B0AD5A4C148ULL, 0x8C007BF7F05D729FULL, 0xEC34574697D6C632ULL, 
            0x030E9A8D797F29C2ULL, 0x43339EAAFE385D52ULL, 0x4286760D0448B0EFULL, 0x1D054B92D1000B00ULL, 
            0x96790242F48B1DAAULL, 0xFE89388D73828DBFULL, 0x9E31070696CEA5B8ULL, 0x30C94940E8E55924ULL
        },
        {
            0x8ECE9A36495166F5ULL, 0x0A2B5996144FA9E7ULL, 0x4DFE557F86BD84E6ULL, 0x10705A73050F7360ULL, 
            0xB3A443AD37E616EEULL, 0xB5FFBF2F74953A12ULL, 0x6C9278C4B3FFAAE2ULL, 0xB9C04E09E7BE085EULL, 
            0xC539081C5CA5FFF9ULL, 0xE1C41009EA761A48ULL, 0xBA57E1D7BA5AB881ULL, 0xF5E9BCBF9CF9CE0DULL, 
            0x22FDEC129AEC177EULL, 0x23B78E29559704CDULL, 0xE0600AF5F9A26BCCULL, 0xBE11FC693FB2D5BEULL, 
            0x93D2963D27A83C6DULL, 0x7C004E88C95D3F7AULL, 0x101911E26E11737FULL, 0xC557076ED66078E7ULL, 
            0xD6345CA139F07137ULL, 0xE5ECB161E60C0A8FULL, 0x63FA33C17760616EULL, 0xC5EACBA510346BA2ULL, 
            0x1B6091F2C4BC156FULL, 0x6CA51D9343416E25ULL, 0xC56A822BD01CA485ULL, 0xFFA52AC2B699FE49ULL, 
            0xF5B30F877FCD6AE9ULL, 0x6C4022E2B582B200ULL, 0x4185192B4ECB17F0ULL, 0x636CFB0AC4EDBAACULL
        }
    },
    {
        {
            0x3E8457048A2555A5ULL, 0x3DC0E2AB82E80642ULL, 0xE26FF99DE3DEDA5CULL, 0x8B7DFAC98F9A9C3DULL, 
            0x32EE1E896C937518ULL, 0xB2A0DC2E1026AE73ULL, 0xCD6EEB3808C9BD2AULL, 0xF6A525A592BFB384ULL, 
            0xA9001E4A89801AB0ULL, 0x2C5C393A8822895BULL, 0x2A83FADE7A329B5DULL, 0xC28F02F8767DE644ULL, 
            0xD44A626A3A2E1BF5ULL, 0x1A08404D066F7E10ULL, 0xC99166E1920DDACCULL, 0x58A801275D81AAFCULL, 
            0xB3B1CBBC1F16A3A9ULL, 0x1D0F0B873E61E518ULL, 0x7269C854A75F5F6FULL, 0xC78860493ECB23C3ULL, 
            0x1FA07B0CF4377302ULL, 0x0DB3E83F1F5A00CFULL, 0x576B433F0AB5BA97ULL, 0x33821B7AF2A90B2AULL, 
            0x5733B790F30624D0ULL, 0x27B2AB0EAC09129FULL, 0x7AA027A3BE0CF1C3ULL, 0x3E6C2448CF8D7917ULL, 
            0x8CDD6CF110FC7204ULL, 0x781D9D776190C56FULL, 0xFB7523080F57185DULL, 0xA5F8C60A9914CABEULL
        },
        {
            0xC12797ECF783C43AULL, 0x5EFE4336A6D70BEAULL, 0xD6D068879C11803BULL, 0x18EF642A34781A31ULL, 
            0x5EB0AD5551E771BDULL, 0xBE5AF9D588C6C688ULL, 0x5F68154CC487A262ULL, 0xADE4E2FA7573A202ULL, 
            0x35AB89C11DF51EC0ULL, 0xA5F2143799183484ULL, 0x2D846857153472F4ULL, 0xA0DEA800E60A02FCULL, 
            0x01C360F2DFED92C8ULL, 0xA3E90B17DC6907D4ULL, 0xC46B1ED866CA7743ULL, 0x6A569685D92E4215ULL, 
            0xB54F34420D550013ULL, 0x7E76DB8AF6981692ULL, 0x62EF65E4D6A2AC22ULL, 0xD140A66BBD91366EULL, 
            0xE933C8B27C56A9F6ULL, 0x76024839A69E89E9ULL, 0x6F318C3D44E8DD9FULL, 0x9009095EBF4A92C9ULL, 
            0x9E38EB9DE841699AULL, 0x0CEA650A1CA1F51BULL, 0xF47E4A3DBC6F1A7BULL, 0x9E48F0F1D879CB36ULL, 
            0xC851459A852B6A49ULL, 0xB3EBEBA1377B73EEULL, 0xB6705FA508F16F4DULL, 0x3AFA44239BC38876ULL
        },
        {
            0x7AF235DFB9423C74ULL, 0x73C9E0184C0DDC42ULL, 0x5E06A9B98D082397ULL, 0x965BF5EEDE7B6D71ULL, 
            0x555ABB55BBF4BA90ULL, 0x1288744A0D13D7C5ULL, 0x6C5F589398568585ULL, 0x8BE70628314082C4ULL, 
            0x067294093628BC37ULL, 0xA16C954AB0E0DAEEULL, 0xB5F274960116DD68ULL, 0xB58161FF2781F278ULL, 
            0xFC637754CFB87FBCULL, 0xE7FA780BDD7D40BAULL, 0xDCDBBD56AAE1BFB8ULL, 0xDDECB9A07C5518E2ULL, 
            0x9C45E964C6A22BEFULL, 0x7F3F85AD556928F5ULL, 0x3BA33EBB624A2661ULL, 0x4F3F95406B2ECD46ULL, 
            0xE8BEBB5511C41146ULL, 0xEAA1F1851223AFF1ULL, 0x1F9633A205C7B2B5ULL, 0xE663915E30EEF267ULL, 
            0x90FE43F91879B105ULL, 0x994D3CF5DD48D2B4ULL, 0xBBB929D4DB2B128FULL, 0x875A6E6F9142D93BULL, 
            0xC35370151A1D3EB7ULL, 0x95E4DD92E0A671CCULL, 0x68A1B9767FBC9792ULL, 0x15B4D331BF546227ULL
        },
        {
            0xA5BCABC9A9486A2BULL, 0xE8432F6D85965E8FULL, 0x3C219BB795580AFFULL, 0x60FA337772846A13ULL, 
            0xB5898A710D91E80EULL, 0xB16C6C2FC3835A4EULL, 0xA4A4A6AD792412F9ULL, 0x48EA56EC6BD85EF5ULL, 
            0x9FBA2F6ADA3F1793ULL, 0x83A95EE8666F4C94ULL, 0x6FFB953E4FBA1C7BULL, 0x0EB10B208B18D521ULL, 
            0xFF453D065A46FF0DULL, 0xFFA7766CA02B26AEULL, 0x57AD029E938CD6CDULL, 0xB1EC83BFC7E048BCULL, 
            0xD85DBD196B47FAD1ULL, 0xB20BE7A91D0458BCULL, 0xA39986127E708E20ULL, 0xEF1F44E1311EAB91ULL, 
            0xA7F4362324D3B901ULL, 0x35CE77347BF4A9C2ULL, 0x383B7BBEDA725244ULL, 0xCD12DA54462358FBULL, 
            0xD1415A2F1FC40789ULL, 0x443ABD055A41D3A9ULL, 0xA73F67DB14120D33ULL, 0x751D6EF15A36C506ULL, 
            0x2AEF12E8CA32A660ULL, 0xCB712E8D8F3C85BCULL, 0x23BB4E1970053B98ULL, 0xDF6FEF38E4653CFFULL
        },
        {
            0xD5CEB3E0A6360E3CULL, 0xFA5B83E38D806048ULL, 0x1CDD994CA9553A18ULL, 0xF523D21EADCCD94AULL, 
            0x278091D5FFA02CEEULL, 0xEA007BCD1DB441BAULL, 0xE72FED9D08ECDD2CULL, 0x3A581009B2392418ULL, 
            0x7FBDB01323CFA9DEULL, 0xBFDAA9B134F9C362ULL, 0x4F95D0C854FEDA37ULL, 0x2C82D0379006757CULL, 
            0x7DE02C993BB44DB3ULL, 0x8633DE3908CEDE97ULL, 0x632A038FA592A683ULL, 0x49A3DF33B470ADD1ULL, 
            0x7F2CA35362B8E279ULL, 0xC87AEFD3791C8B63ULL, 0xA33AC9CD3022D71DULL, 0x2FAF7D27D827EC43ULL, 
            0x13E6C19EAF983B1FULL, 0x95C7F5C97B54AC26ULL, 0xF50BDA3447C696D0ULL, 0x857D282302C5B9F0ULL, 
            0x54988568A391645EULL, 0xB38FFD274977092BULL, 0xDCC820B4D962745AULL, 0xA4BCBC1684CA8A3FULL, 
            0x39CCEBC06FD77425ULL, 0x4803000798201A12ULL, 0x61CF76821BF90BBAULL, 0x23289E47CA6F8FF7ULL
        },
        {
            0xAC64CF3B2019435AULL, 0x08341C447F58CEF3ULL, 0x9329BC1C303FDF95ULL, 0x1A47465571E8FF74ULL, 
            0x9AF1ED151805F090ULL, 0xE8593DA23AA3BDA5ULL, 0xBF911D7FA2C62E26ULL, 0x9FEDA872E58BBBC4ULL, 
            0x8C28B08A5884ED92ULL, 0x0FEBC24FFE9AB742ULL, 0x4B0225FB928C5DEDULL, 0xB6C6C15021EF2E87ULL, 
            0x5B64264D6DC04704ULL, 0xD9F72873947C3205ULL, 0x8407726518100719ULL, 0x461BD6099CE0297AULL, 
            0xF013A37C59DB23F8ULL, 0x06AA784E55043323ULL, 0xACDB48D3CF5E6589ULL, 0x399E946F77739BFFULL, 
            0x613967CE50A9B0ECULL, 0x5D3C0F11CDFDA4D2ULL, 0xD7B1470E49103307ULL, 0x047DBD1750DAE0A0ULL, 
            0xAEBD71389A337939ULL, 0x672D1D496E727514ULL, 0xA57511A19F6642EFULL, 0xE4384B6086C62D43ULL, 
            0xFB091FDB12548D64ULL, 0xC7C346C533089C95ULL, 0xDAE535CAA5B97EC9ULL, 0x4FB5312FBA36B03AULL
        }
    },
    {
        {
            0x506E08A9C5405C97ULL, 0xB184E66B1D157832ULL, 0x1F027D8483A0D4DDULL, 0x91FDBBEB958C2489ULL, 
            0x7DB2C1AEF6401C4DULL, 0xE93D008816C29A9AULL, 0xC920B9F8C24949ECULL, 0x5C1E41CEFC82731CULL, 
            0xA3FB7A4FE55825F0ULL, 0x787B452E0DE66F74ULL, 0x8CED34897D4012A8ULL, 0xC8002997B5873597ULL, 
            0x10EBE0E6479C25F7ULL, 0x70C67FCF0A8B2BB8ULL, 0x81CF99BED800848BULL, 0xCC9B13499B579DB9ULL, 
            0x0E8A735497F9DF25ULL, 0x55325712BD473CF1ULL, 0x0E40EF7874C5AC60ULL, 0xDE705A8C574F0D57ULL, 
            0x7005C854F022CC71ULL, 0x097C4E016F0E3DFAULL, 0x18CD3574405D3182ULL, 0xC6890D13CE15853FULL, 
            0xE947329E9F198231ULL, 0x007AB4CBE767826FULL, 0x7D01202FA60879AAULL, 0xAD45364306C3EA43ULL, 
            0xA2FFF43046343E7BULL, 0x0797D0567AF43DCFULL, 0x116217AF2FFAAD33ULL, 0xAA34AEB1A100F2E7ULL
        },
        {
            0xE42B7F5166D64780ULL, 0x629234F66AE7363CULL, 0x495BE16C140227C6ULL, 0x9C0DE29ECE169A26ULL, 
            0x854AF71C5E05DF75ULL, 0x2CEEE2D69681699DULL, 0x09888E114FB5A7C3ULL, 0xE7A1FA1A695AFD27ULL, 
            0xFE909853EB82A90EULL, 0x21AA43CB68959701ULL, 0x620D7A77EEC03306ULL, 0x54CB68C09402F5D4ULL, 
            0x0CA09ED35322A696ULL, 0xF1BDE798349DCA3BULL, 0xC7ECB003639223FCULL, 0x92CFD710C6F8613EULL, 
            0x8EE7DD2C3613BB6BULL, 0x9BB733A588F5DD1AULL, 0xD3699DE41CB93E32ULL, 0x09936EBEA94E1B53ULL, 
            0xC2B03C8F26A4C083ULL, 0x899B650FFA38A626ULL, 0xC48F84DE84C5E203ULL, 0xEE0DF04E2DB5D4D6ULL, 
            0xFFC1BFA89AAB5741ULL, 0x04E2E208A3B6EC95ULL, 0x8FD7FC2BC24C2C64ULL, 0xDB608875D1DA0CFFULL, 
            0xD355498EDA070252ULL, 0xFF80B7EC87D787E0ULL, 0xF1A03361E5BC325EULL, 0x3E21D72777BECA17ULL
        },
        {
            0x955F22FB24C99E40ULL, 0x453BF25B0F8FA79FULL, 0x95B34C2D365D7678ULL, 0x2DC9DCCF51C232D6ULL, 
            0xCC24EDDA52427E1BULL, 0xF237FFA9B7C4FA81ULL, 0xC62BE73CD6C982FEULL, 0x0DFCF42FCA3E1708ULL, 
            0xE7722FEAC2EEC141ULL, 0x8BF19E911236C413ULL, 0x066EF66A6913FE11ULL, 0xDC14F4CE12E7959CULL, 
            0xE7A7B573668AD557ULL, 0x9235415D344802F6ULL, 0x861948E8C765B68CULL, 0x5AD276AEC46C2D61ULL, 
            0xF99D361E72DB5508ULL, 0x27D332D3A60151DAULL, 0x3C1A03A26ABB7266ULL, 0x045045B4D961DB23ULL, 
            0x89567117609976CDULL, 0x3463769F9C303C11ULL, 0xAE2AD458D054CACDULL, 0xA8134EDE12E0E48EULL, 
            0x4758439C85D28A90ULL, 0x8B12CB0679DBE13AULL, 0x7EC20AC1526A93F8ULL, 0xE1DA7F8960419837ULL, 
            0x900483F193E57226ULL, 0xE12DD7A964417313ULL, 0x8CC3906AED26F678ULL, 0xD7A08B1CA10BE981ULL
        },
        {
            0xB8E1B8C97A1016D9ULL, 0x57C90422BF121E8EULL, 0x3E1725D49F758F75ULL, 0x9AB8CA4DF4F839AAULL, 
            0x3618D142F6337E4EULL, 0x2BCB14ACE420F157ULL, 0x6BF0E7B303A7348EULL, 0x8FBCC1B6EAA946CFULL, 
            0x34AFF09A231010FFULL, 0x7862D591BDE85BBEULL, 0x6A40C6311498F810ULL, 0x562D1F63EC0D6310ULL, 
            0x91F34C0A5BFD4536ULL, 0xBAFEC01EF321F27BULL, 0xDE0FAD443F07AA96ULL, 0x28904DF1BE2903F5ULL, 
            0x3EBC7D70BA6D89B7ULL, 0x898248ACD91E8DB3ULL, 0x658AC130748B90A1ULL, 0xDB07087E125CE946ULL, 
            0xE792090D364E098EULL, 0x4DA37786BA13628BULL, 0xFDE95A4C1017EE1DULL, 0x046A773AD6203D00ULL, 
            0xA372068E07A98C95ULL, 0x7830B0BBE748ADE2ULL, 0x189A6F4684B7058BULL, 0x897100AF7FF63A3DULL, 
            0xE360E69ECE33A141ULL, 0xB2FF1BB2CCDE0F97ULL, 0x4434A5439C8A2C7EULL, 0x8036E1EC4647C43FULL
        },
        {
            0xD359DD0427ABD416ULL, 0x966815710D9F9319ULL, 0xD8B45FAACA30F1ACULL, 0x4BC0261A11A4F0D4ULL, 
            0xF5862D3C9C0C584AULL, 0x116A92D73228ACA6ULL, 0x4C9B176BA117BDD0ULL, 0xEEDEEAAFB5357AD8ULL, 
            0x9A9E5CC366DD2FA0ULL, 0xD71300090909EE9DULL, 0xCC9084025C020EA9ULL, 0xF4921BCC8A111B21ULL, 
            0x5DA71DF4756FBE7CULL, 0x291C3CF1C7ECC465ULL, 0x1C1D97571ECEA4CCULL, 0x6BE5923842B41E49ULL, 
            0x6F882825A66E3FC2ULL, 0x8B85A5408404875EULL, 0x63E31C07BC96AAC9ULL, 0x0067D42C2966D153ULL, 
            0x6C55172F20E82BDAULL, 0x0F0EE82BB4B171F9ULL, 0x3B1851633EC29FA6ULL, 0x0697EDB62F135CA3ULL, 
            0x0BA183E8729E02E9ULL, 0xF0E66700CE32CA67ULL, 0x4FB7DCF74BC7D56DULL, 0x456A50FD3DA3D0B3ULL, 
            0x1E56EC73C1ACE53AULL, 0x6DAADD8F6306A49BULL, 0x7C847A19651A67E8ULL, 0xDBDE30C105AE0948ULL
        },
        {
            0xDB51FD57D65C6A9EULL, 0xBF255FCEEB70D7B0ULL, 0x6E82FE6F09100FCAULL, 0x4F84DB44D5688471ULL, 
            0xDA542E19E33DD0B6ULL, 0xCF7FAD09FC048DD3ULL, 0xEFEB0D7ED520CC17ULL, 0x8F23B2E72B761489ULL, 
            0x719B88436D3B9217ULL, 0x8B7314E996858F94ULL, 0x645EB07B41D951C1ULL, 0xA486422BEAD88ACAULL, 
            0xD888F135F94238B3ULL, 0xD0F08A86EAD0AA10ULL, 0xEECEC7E0058B2475ULL, 0xE2C3440DA9F34BB3ULL, 
            0x6AEB2D0AF598AC0FULL, 0xD3E73E1C15EB0AEFULL, 0x9C737F4259DCC733ULL, 0x36348CCF56AC2EC2ULL, 
            0x14A7E8053076D3BFULL, 0x69A8F2C777220336ULL, 0x3C785FA8C05A3D63ULL, 0xE1FA5E820ABBC356ULL, 
            0x786A702F78B300BCULL, 0x78359D0F3D199996ULL, 0x534238F894DBA7CDULL, 0x81270AE935CB8956ULL, 
            0x94082EA093CB11ADULL, 0x2FC64A8DDD383353ULL, 0x7DD23486E5D6477AULL, 0x9F36ADBD8F1E102FULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseDConstants = {
    0xF845ED67E899A3EFULL,
    0x09156EBA3FD0AB87ULL,
    0x0642F00C0AA1FDD6ULL,
    0xF845ED67E899A3EFULL,
    0x09156EBA3FD0AB87ULL,
    0x0642F00C0AA1FDD6ULL,
    0x8D0B9CA4609E28EBULL,
    0xF4992C4C6A9CDA0DULL,
    0x5A,
    0x20,
    0x72,
    0xF0,
    0x43,
    0xFD,
    0x84,
    0xB6
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseESalts = {
    {
        {
            0xEE5D8B1CA00C70D1ULL, 0x9271657EF1CA804AULL, 0xE22793772C08E3BEULL, 0xB6EE0F673FF23BC3ULL, 
            0xD73A88D9A7B54036ULL, 0xF2229CB817FB794AULL, 0x61D21AFD52C62409ULL, 0x7BDA0C9523BD0B2DULL, 
            0xDD6E70EF00074FCAULL, 0xDFBA174B7902FAF7ULL, 0x10557935856A8741ULL, 0xE94CDB444B8BA00AULL, 
            0xC66DE210B5DA449EULL, 0x67537D4EE3166DACULL, 0x2E6750FFCBECFF54ULL, 0x0B194026309488B3ULL, 
            0x6C509AF5C5E21D3CULL, 0xD755B03A2F1F7CAAULL, 0x4A1069E6ACA830A2ULL, 0xB2209FC48786DEB9ULL, 
            0x79CBDFD5B7BAC4ACULL, 0xE0344CD9729B88EFULL, 0xC9918B0584940DEFULL, 0x2BF96014739F25EDULL, 
            0x174EE705774576D9ULL, 0x1F23F0AE7B24B4C4ULL, 0xAABF1986CAD2F0F9ULL, 0xD6604860403FD3C2ULL, 
            0x99E4473722F8FD9AULL, 0x761E79ADBEA64CD9ULL, 0xA98DC3DAA7098E6CULL, 0x0B6815353F6C92B3ULL
        },
        {
            0x4BD80E7D2ACA5735ULL, 0x12B598125ED09CEFULL, 0xAA85BD5FD15637DDULL, 0x0097AF4840520D95ULL, 
            0xD7D6363F9B4847F2ULL, 0xBB2510A53A81ECB5ULL, 0x58787C4A40B39767ULL, 0x4F3C9B11D50264A3ULL, 
            0xE89D783DBF080ECFULL, 0x2B88B3F0BD0B04F9ULL, 0x26F6F9934F06FA2FULL, 0x0DB5C3D7E56BD93CULL, 
            0xE1B5AFDFFD7C6389ULL, 0x54F34C20C20BAE5CULL, 0xB349F4D74BDAFDB2ULL, 0x79DAE1DBDBFAF04EULL, 
            0x43F9C64C84CE961FULL, 0x15B780E3E298F456ULL, 0x3685EBC783191E4EULL, 0x60B621E5B45F5CD2ULL, 
            0xAED982C1F898AD6EULL, 0x7C7138558467282BULL, 0xC007BE1D640EFBCFULL, 0xB5F71F43583FA473ULL, 
            0x4A1310D9776F3455ULL, 0xD338EC05DF698ADAULL, 0xD26C99D58A934767ULL, 0xC393B9DAEB7A6696ULL, 
            0xBAC655010FFC8A30ULL, 0x7124997441FDFBBEULL, 0x78D38C033EA567FAULL, 0x76F63ACC00D440EEULL
        },
        {
            0x3D4366C6FF567C62ULL, 0x30C32F6CF9B34B3CULL, 0x201E9485D4C7544EULL, 0xF9AEA099CB23870EULL, 
            0x150B20182BD78959ULL, 0xDF2FE1F5B1E9613AULL, 0xB68CC0F015D3DD59ULL, 0x55378470E81130DDULL, 
            0x6B47FE2AF9AA65AFULL, 0xD92C41490E2FFCE8ULL, 0x4B48289827F27791ULL, 0x66DC1DDE02CB1EEAULL, 
            0xD923ED4A3DFEA4EFULL, 0xBDB84B3E2B671F3BULL, 0xA100D3492F5F7C90ULL, 0x971B965C5D64A73BULL, 
            0x2DF077DAE92CD1A7ULL, 0x6EBFA0CBDBE2DA4EULL, 0x8240479A13A00025ULL, 0xA0412D19135D66BEULL, 
            0xB12F34F0E240E830ULL, 0x64A33C45E25C2D49ULL, 0x0DE8776B80D4442DULL, 0x0EBA19EE90DE660FULL, 
            0x51A10EE826F3AFAEULL, 0xBEEA13CB49F87D7BULL, 0x59E0CB7C6446472DULL, 0x4E7B4D3BCBE40422ULL, 
            0xE7C45CA8A6140864ULL, 0x3F4F44EB6EA127E5ULL, 0xCE62C11DE8DE7D32ULL, 0xFD9F053EBF79A55FULL
        },
        {
            0x1654561A2F93135EULL, 0x54658CF4D6EB8F4FULL, 0x4E1A1E641022EA88ULL, 0x9D451B2A4586119FULL, 
            0xFD88228B5545509CULL, 0x8E29C76D1F1E72CDULL, 0x36F2454DD8EA3838ULL, 0x2BE1840D9BD3A04AULL, 
            0xC4BC2271AE55261AULL, 0x0CF3F1617483B309ULL, 0x0E4F359BE2CF4FD9ULL, 0x8E8385636E8EE3A3ULL, 
            0xC2282CC4D8477C05ULL, 0xB3178B8CF45F0ADDULL, 0x5176C67F59EA9298ULL, 0x5F7FD435D60F5D9BULL, 
            0xF6CC8EC33AFA8407ULL, 0x7D3850F7CAB84F64ULL, 0x79C31BF26A4EAFB0ULL, 0xFF4E05657C7AA8B3ULL, 
            0x9E41BAB8C6913686ULL, 0xBA88B90C150AF13DULL, 0x056F37B074AF7BCCULL, 0x050ADB75605F4262ULL, 
            0x9086339FB835D2C2ULL, 0xA5B971CF44B5030DULL, 0xDD959CD89A82F0C6ULL, 0x11A0AFEF047F3436ULL, 
            0x2103C4A6236E36D0ULL, 0xA70645B89037057FULL, 0xE81DDB4184BF39D3ULL, 0x6EA88339E2D1E7AAULL
        },
        {
            0xA4616F82D4D4FFB3ULL, 0xEC83CEFE9CFB9476ULL, 0xD6941A3D54ABA052ULL, 0x49C3A6E7EF367AB9ULL, 
            0x37EC87607AEA5EF4ULL, 0x9092200CB051AEB3ULL, 0x6F685E576382A4C6ULL, 0x759A05A63B361FC0ULL, 
            0x53FF033A58C672B7ULL, 0xC886445B524741ECULL, 0x0D8E0367A618E85EULL, 0x69086C0DF7541939ULL, 
            0x32D9730B368EB19AULL, 0xBA545F4F7450978FULL, 0x5C10083A012F00D6ULL, 0x31A5B62E25E46166ULL, 
            0xFEE5BB0886546F5DULL, 0x6554F33AD23578E2ULL, 0xDE1E0A0A483134FCULL, 0xC4EA29C214015479ULL, 
            0x0A44A9305A85773DULL, 0x796F0C0753832E33ULL, 0x4560F5D990953DCCULL, 0x0FBC4CB39219A8A0ULL, 
            0xE7B4EAA674F939EDULL, 0xB0C14411503AE067ULL, 0xB0F951076319F97BULL, 0x0E836606EF00CEF3ULL, 
            0x41628823A66C3A63ULL, 0xCE082BE6B605FF1FULL, 0x8C407D7FE896421AULL, 0x4EB67CBB9C2E911CULL
        },
        {
            0x22E6D64A630F9C18ULL, 0x80500E7ACD5ABF62ULL, 0x8FDE2D27A2E8B8B8ULL, 0xF2507B1DD7CCDD94ULL, 
            0xBC8F632D03FF242BULL, 0x8EB61AD42E09DC52ULL, 0x9BA2F90DE3C6267CULL, 0x72AC905BFD4DC602ULL, 
            0xFD3CE9EC781ED33BULL, 0xFB019815B69A5C6BULL, 0x9A729244ED2D5673ULL, 0x3B30B954C5068A74ULL, 
            0x8B0362553040009EULL, 0x093571EC840DCE48ULL, 0x344B47D4170AA821ULL, 0x836E5E954E3B1176ULL, 
            0x4985A5510C6B0B7DULL, 0xF8DF7F3A343BF33DULL, 0x26B35F6C1DD4772FULL, 0x8AC7F181AAD6E394ULL, 
            0x1843FD00D8E67A4BULL, 0x61C19144D9F9B185ULL, 0x7552B74F2DE28AEEULL, 0x91AF247942BC6E39ULL, 
            0x5E91C6C533515502ULL, 0x63B1AC1966108C86ULL, 0x632194F91BCBF246ULL, 0x273DDEA49FEE1925ULL, 
            0xE1E632ED8BB01778ULL, 0x82770F329118469EULL, 0x17CB3D26856EEBE6ULL, 0x3500215F3EB372ADULL
        }
    },
    {
        {
            0x6EB1918B0AD02B7CULL, 0x2F18E0DBD2EE66C1ULL, 0x580557E78FD6AE4BULL, 0x2DF0FB17812A9194ULL, 
            0xFFCF623B89F5E104ULL, 0xCD325CE8CCA049A0ULL, 0xA24ED08224711A94ULL, 0x12E833C9255E613EULL, 
            0xC16F3E41D134AE28ULL, 0x72ECAAC25549AF30ULL, 0xFB74FC2927A894FDULL, 0x1C582DB1DED95FAEULL, 
            0xEDBAEE7A8FDD4E0BULL, 0xEB706C213A26A6E8ULL, 0xAEC89396D6179AA7ULL, 0x8175B0A361E2215FULL, 
            0x992A1B34744BF9D0ULL, 0x5D5E1F25538735C5ULL, 0x6ED37EF8994F764DULL, 0x47309B03BFA9BF3EULL, 
            0xFEA86AC45153C0ADULL, 0xD2F7BF84BC43775DULL, 0xCEC0637F062450B0ULL, 0x62F8609687D28078ULL, 
            0xF171AA36CD227C5CULL, 0xA27ECE831727EA64ULL, 0xAC0BA4CBC1F6CBADULL, 0xE14BE45AECDC2B2EULL, 
            0xBD3959C41BA5BFDFULL, 0x51EF76A5F39997C0ULL, 0x6952988104594174ULL, 0x6CDCF36EA923ECE0ULL
        },
        {
            0xDE1B2C40344FF6D4ULL, 0x58CDF5F09D9FAF6AULL, 0x8FC820729FE005A9ULL, 0x3E2DAC403843ECFFULL, 
            0x57C1D73478679EA8ULL, 0xDCA4FE1873E5E805ULL, 0xBFDF76160AB17408ULL, 0x92B36F5666DA8919ULL, 
            0xA28D07C9526C13BAULL, 0x923C429C2D016255ULL, 0x08E0336E9F6CC481ULL, 0xF386C6622F3CC536ULL, 
            0xE91F5F378F3EDDB6ULL, 0x38C999FA98DFF78DULL, 0x093410A0F9E9AD45ULL, 0xD89CFD68EF8C19CCULL, 
            0x0B49C39CAE7F73D7ULL, 0xEF20130B87FA4F99ULL, 0xFB76BA51A0764A27ULL, 0x4C8B5208281552FBULL, 
            0xD5F3303ACA8D8D4FULL, 0x9D2EAD138ED09FF4ULL, 0x32C0E5684E339D09ULL, 0xAA8E302A7E11BEB8ULL, 
            0x4B7E4E428C0CA7A1ULL, 0xBCE3713968EF36C4ULL, 0x6558DFBCE271B32AULL, 0x88B03A13F9F17FF2ULL, 
            0x47166F7BCF4CB9AFULL, 0x59042470A4CF21EFULL, 0xAC743E2DC8937F74ULL, 0x2251149EF4E471ABULL
        },
        {
            0x9B034AE0E3FE2752ULL, 0x6AC7530341320140ULL, 0xCAC132C3181760EDULL, 0x328078684F7D7775ULL, 
            0xEF4E9151F40C9AA2ULL, 0x2CBC543EF1A050C6ULL, 0xAAAA88C8EBE1DCEAULL, 0x9E7D051FC284322BULL, 
            0xC12E5D1DBB603047ULL, 0x77C9FD7271862978ULL, 0x38A693AA5A071EA4ULL, 0x0EF33C100BA9BA78ULL, 
            0xE59831F02A671E7EULL, 0x259BAA232239D2E0ULL, 0x241C3F2D17CC7AB4ULL, 0x0B3FD107FF2A6CDBULL, 
            0x5FFEE6B3618C269BULL, 0x18925CE603FB2B45ULL, 0x8324F9EF75C421C0ULL, 0x57CDAB6203F751D0ULL, 
            0x8885BD66A029304CULL, 0x78FC8FEC86254FC5ULL, 0x95771852A282723BULL, 0xBAAAAEFE32968FE9ULL, 
            0x87234F6B627F358FULL, 0x8BB5576F994B29B2ULL, 0x013917B90C54134EULL, 0xE845B9245C415EA5ULL, 
            0xB58DA7A432E01D77ULL, 0x917C5D99CCBF47B4ULL, 0x9BEFC9BA77B168B2ULL, 0xE70DDCD164B066BEULL
        },
        {
            0xFE453F0B2611B294ULL, 0x268B6DA6B974E525ULL, 0x2DDA0B4DF799C7F1ULL, 0x2DB998191B93B155ULL, 
            0x5A1AC89F80CFAEE5ULL, 0x8EC7108EA29E98CEULL, 0x133DCA2E5818CB10ULL, 0xD8E0BC1C46AE0CC9ULL, 
            0x15F22F3AB1113E0EULL, 0x6C82A90255C830D8ULL, 0xD45E9FDEDB559A11ULL, 0xF977DA1CA7D6E035ULL, 
            0xBC103A4AC0662774ULL, 0x162ED3BAA434D943ULL, 0x130B92B9C9A53CAFULL, 0x1D1B6B356E505916ULL, 
            0x8407DA7CE389FAA2ULL, 0xFCBA6BB13C4A7870ULL, 0x1F008BD87368358BULL, 0x9E19345AD0E018B5ULL, 
            0x1EA25B781647FA7BULL, 0x35C9EB5DB6A9A793ULL, 0x87BFD49030FB5716ULL, 0x11364344FB466307ULL, 
            0x6F0F1432D2507396ULL, 0x417628E108FB3BF8ULL, 0x64C2D35DDC766611ULL, 0xD96BEFCAB90A8992ULL, 
            0x0E79CAB94F7AB4D2ULL, 0x00E7C7DC2433867DULL, 0x62AEB2E7E7100407ULL, 0x4BB8A8A55FEFF322ULL
        },
        {
            0xF14CB2DB4FBA0501ULL, 0x930C8F9361D24C76ULL, 0x43CB3E8E4EC824B3ULL, 0x75B125138CB23525ULL, 
            0x912360B5F5A4739FULL, 0xD2408BC77DA77B47ULL, 0xD3D8B51E011313ACULL, 0xCCA737C212D4098DULL, 
            0x905E9F4CE966AAC5ULL, 0x9FCA5B7930CFE964ULL, 0x95AB43E5E295F7F6ULL, 0xA7B283CF32607546ULL, 
            0xCB4F6A42339806DDULL, 0x0185A83AAA07D058ULL, 0x52F87405D9B83E87ULL, 0x38408A3BF7A883A0ULL, 
            0x0482DF936BCBF1D7ULL, 0x1DF3BCAF187B2344ULL, 0x65ED9CED433854CCULL, 0xA5A3FBCDBDD460AEULL, 
            0xD26D94EEBC48123DULL, 0xFDF49D9665A659F0ULL, 0xAD98C8B60CF94CB8ULL, 0x172CC95737656E43ULL, 
            0x69B945A772DA495AULL, 0xE46163967BD1543BULL, 0x7DA0E07D05BBF91FULL, 0x3B4EB29F0C547D36ULL, 
            0x07380609B7CC3C79ULL, 0x60CA6405DFEFFE8EULL, 0xAFF19A21791045F9ULL, 0x243A7E589051DFCFULL
        },
        {
            0x982256D816A38634ULL, 0x5C602E106909411DULL, 0x62A43900F3AAFA0AULL, 0x44A0A74BC729B522ULL, 
            0x48A020F6D0B3240BULL, 0x5DC9CA51061B75A6ULL, 0xE0B7AE019F12E474ULL, 0x688840D34934D47CULL, 
            0xAD8D406C57FB4AA5ULL, 0x67103787BB384E57ULL, 0xEBA0A1D23B70B66CULL, 0x638F5D66130ED1EFULL, 
            0x27C89772CC461F3BULL, 0xAA048516B73D14D6ULL, 0x6168B0D3954A8C18ULL, 0xBC7EE17B7DE124D3ULL, 
            0xBE2E6EB074028578ULL, 0xBB708EAFDB37284DULL, 0xA4D3E7C258A176A7ULL, 0x44CC3ADDEDB55658ULL, 
            0x311A189CB78F1AE4ULL, 0x6AD014CC082C07E6ULL, 0x7B6D98139D34D3F3ULL, 0x035197E4FA74B91BULL, 
            0xBE1ECF34622F84ABULL, 0x0DF76BE5E940456BULL, 0x117838C172429D87ULL, 0xC45BBBC2A982EA5CULL, 
            0x7226CCF21C804E33ULL, 0x24A1FE2E530A9DDBULL, 0xC0F8561F51526B48ULL, 0xA1825A0DABDEB5A1ULL
        }
    },
    {
        {
            0x7109BDBD7C176778ULL, 0x0F3192DFDB21D912ULL, 0xC15164A6116A902AULL, 0xC318912C384D8629ULL, 
            0x946BCF61FAAF7776ULL, 0xB83744E5D4780E0FULL, 0x1E0D7AB3C382B951ULL, 0x46F2E5132E10A5FAULL, 
            0x7769443182CAB7E4ULL, 0x9407F9149B6E3DB5ULL, 0xB3C974899CC9D727ULL, 0x90CD08A1EFCA5183ULL, 
            0x7EE18A1369984E60ULL, 0x53E8497FBCB36649ULL, 0x522E76BD11694B38ULL, 0x41ECE9DF40F31BB4ULL, 
            0x49D631289A22174DULL, 0xB19B4182C1E86094ULL, 0xD141E13C9B739350ULL, 0xA24CB4D075019B53ULL, 
            0x709AEA3EE4D3D299ULL, 0x7AE72F430728A401ULL, 0x136F7430F77BC7D2ULL, 0xCC33C2CEF7391EDEULL, 
            0xD9B30F4DD08B7179ULL, 0x33C9E1F9D60D6985ULL, 0x617456C2884D0F62ULL, 0xA39AB1CE2EED4CB3ULL, 
            0x60A6C83F42CDA753ULL, 0xDA2A8B473A6EDBAAULL, 0x5690F99C7475E8B6ULL, 0x139D189179ECE1DEULL
        },
        {
            0x50773E5154A49EC0ULL, 0xCE69A570ADF2ED9DULL, 0xE0FD08705FE44595ULL, 0x492D47052B31F2ABULL, 
            0x581F3A4033AFDC35ULL, 0x3ABC8585C1DB5BA4ULL, 0x28BD75951500EB02ULL, 0x46C78003327AB9DEULL, 
            0x2440FF1EF34C1BB4ULL, 0x5C41D13CE6A928DBULL, 0x646273191DF586C2ULL, 0x1B37EE04B86AFD14ULL, 
            0x0BD0919642A3D817ULL, 0x817E68FBEA570F5AULL, 0x8FEEA5DDA593C6D4ULL, 0x07864B1A57ACDC1CULL, 
            0xAA9246695965755FULL, 0x5C6A07BC529884F6ULL, 0x9A7804DCE2EA3429ULL, 0x55BF67F8009F8E1FULL, 
            0x0CF506B02A6072E8ULL, 0xB283D9CA02CAAF56ULL, 0xF23EB879ABE46E75ULL, 0x7880DB515FFB084CULL, 
            0x697CE200681A06E1ULL, 0xB640D81F7F7363A9ULL, 0x6198B5E4A4B1E3B9ULL, 0x9DEE89B4A792874CULL, 
            0x7E6709989D02B00BULL, 0x75597234981EAF92ULL, 0x0D615CDE41B67CCCULL, 0x882468F2CD358093ULL
        },
        {
            0x0D4761311EEF756EULL, 0xCD317150638889E9ULL, 0x40E83C16B1433BFFULL, 0x872D3ECF08453101ULL, 
            0x9B3903C0025E3309ULL, 0x06174258F4EFFCA3ULL, 0x51C46BC45276B974ULL, 0xDB9EBD3D7BBA98B5ULL, 
            0xFDB9A2DFE96C3ECAULL, 0x6DC55DDF9436C371ULL, 0xA9E83F62B4437A35ULL, 0x03BD4DEEBFC2296CULL, 
            0x37B21CEA0F97E2BCULL, 0x9FF8960BF64F6654ULL, 0x0A1087AFAB375ADFULL, 0x65DAC7C1F86142A5ULL, 
            0x9B274648476B7BADULL, 0x97429447A6F86140ULL, 0xB48F19881C09FA34ULL, 0x8AFF8F72AF44BCDDULL, 
            0xFC0715556F7730BBULL, 0x539C34D3BD658C9AULL, 0x5C4433D2FB1F3225ULL, 0xF12C537EFCD9141FULL, 
            0xF96A1DF9D1C8143CULL, 0x791FF0E0E01ED917ULL, 0x09C208CD3C0BE7BEULL, 0xA2F88D155B21319BULL, 
            0x0583D6A0A8E7526EULL, 0x5E015E65FF63334AULL, 0xD03204CEAEA72E73ULL, 0x1D53FCB6EBCB1552ULL
        },
        {
            0x5B2976C6F4415E40ULL, 0x7C6BF88D4EBB2E9DULL, 0xF6A441E2A0ADB5BCULL, 0xCA68FBDE4CAE984AULL, 
            0x80E35127DCF1FC2AULL, 0xD6C291516CD02ACDULL, 0x3DBE27090461319AULL, 0x8CE169BA78D3F384ULL, 
            0xB9B0BCA1F659DB79ULL, 0xDA20D565B8821B32ULL, 0xEFF953B84976FF31ULL, 0xCE523DFD22D841C9ULL, 
            0x2B1D6CB37C7030E0ULL, 0x73912E0D7141974CULL, 0x8AD820E465DA4292ULL, 0x9E8B4C820CF9C724ULL, 
            0xE97360A47A3805E3ULL, 0xE491315509A7BBB0ULL, 0x23E0ACB62CA2094AULL, 0x1509CA1296DEA9FCULL, 
            0xB17592C3192BE55AULL, 0x3A1950339ED3F30FULL, 0x317A57623A95FCD3ULL, 0x70E42E42C22151AAULL, 
            0x18A740258FD8CBCBULL, 0xEFBC396CFC87498BULL, 0x4C13267D3BBB9C98ULL, 0xA167CE4C88FF5CF7ULL, 
            0x58805DC69D85846EULL, 0x2AAAD55F720AEA43ULL, 0x5C7B92F7B7E628FEULL, 0x9394FABB675087D4ULL
        },
        {
            0xBD2D6ADE4261DE67ULL, 0x3314477669589F06ULL, 0xBBD37FE7B8276340ULL, 0x3531DA8A0EEA65EAULL, 
            0xA7EA08FBF461C79AULL, 0xD281E149131F019AULL, 0x59B0B60A0769B44FULL, 0xD6CE7B3401DD4548ULL, 
            0xF1162CC5D903E61BULL, 0xB2340F3539A41900ULL, 0x38C41018AD78CEF8ULL, 0x160E1C0ADA900187ULL, 
            0xE8CFF3F8AE55467AULL, 0x183330C0CA6A2035ULL, 0x013A8169882E618BULL, 0x02D8E8F5D5D80BE0ULL, 
            0x5255A2BE531AC040ULL, 0xE5ECD7A9086FE46CULL, 0x903EC571F7ED8D61ULL, 0x9447C4E74BB53A52ULL, 
            0x908921F615516ABAULL, 0x8A03623235B36757ULL, 0xB3AEDFE3589F6880ULL, 0xABDBD833F12D0B74ULL, 
            0xD9A2535A8AF95102ULL, 0x0B49A4422E1A7BD0ULL, 0x04CA48531097E5D7ULL, 0x13D3DADC7A35257FULL, 
            0xA9D76C928FFECBE8ULL, 0xDF987A6F50AF70E4ULL, 0x543D3D51C2A91262ULL, 0x8B16A061F6BA3211ULL
        },
        {
            0x631E68B64068450CULL, 0xB9DB7E19EC0EB79AULL, 0x3D3E56D1A4385D8CULL, 0x28F6958EBCE21F05ULL, 
            0x2D7DF62DEBB62824ULL, 0xBB22953DCBDC1EEBULL, 0xEC59FC4DFD4FED1CULL, 0x1C7E34FBCBA2465CULL, 
            0xF05348FC1CE88C86ULL, 0xFF5505FA02176208ULL, 0x5D4A4168FCDE63F8ULL, 0x94254D65E5D8B26DULL, 
            0x46917942660A9471ULL, 0xA80629AEFFFAE89DULL, 0xE5A7B82E2DFBC2C8ULL, 0x81A300A865F4CA31ULL, 
            0x5F9C049C3AE85FC7ULL, 0x6A2EA24015DAF43AULL, 0x84512427BB60A9FCULL, 0x505B5D092B5D79C2ULL, 
            0x927463241234ACD3ULL, 0x6FF27743432A5854ULL, 0x7106AC3A9519CF95ULL, 0xC6F2AF81FFFB59F0ULL, 
            0x4A0E43F13F750ECBULL, 0xE70304A73612E001ULL, 0x2CD37F6AAFA8ACD1ULL, 0x54FF9D11F4B73AEFULL, 
            0x3DF217ADF25CA5EAULL, 0xAA6C110D04B5EBC1ULL, 0xA687EC5A1787FC77ULL, 0xC29B357411C73F42ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseEConstants = {
    0x3E0535A309891595ULL,
    0x33CA83CA6FEB974DULL,
    0x9DAE55AE50E33D78ULL,
    0x3E0535A309891595ULL,
    0x33CA83CA6FEB974DULL,
    0x9DAE55AE50E33D78ULL,
    0x65AF7F7FAC86DB64ULL,
    0x63D43C032F744591ULL,
    0xDD,
    0x9D,
    0x5F,
    0xD7,
    0x09,
    0xC1,
    0xDB,
    0xC7
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseFSalts = {
    {
        {
            0x5892C93A5BD7D98AULL, 0x1AB3F7874D7493C2ULL, 0xB9FE42215313E2B1ULL, 0xAA4441193E629D75ULL, 
            0xBB1D8236383D3075ULL, 0x39D73357DA533057ULL, 0x33135BB94528EE51ULL, 0xF2A2518380088D27ULL, 
            0x2409982F4F95BAC9ULL, 0x915432A477A36390ULL, 0xB1BBEE8EEBA22558ULL, 0x539EBAAF92AB06CAULL, 
            0x449DF61D69380AB6ULL, 0xBF7D58DBDD9CC4BAULL, 0x175B3A3C0580DF6AULL, 0x793AFC6C81E7E288ULL, 
            0x6EA4DA1CD9DE96F5ULL, 0x290AADC9F1F47128ULL, 0x64C59ABFE51BF86DULL, 0x18B88507E791165DULL, 
            0x1BDF5BDAC4433F1EULL, 0x93D3D446D98BF037ULL, 0xFFA3B42577D359BFULL, 0x009A0B5B27FEDE14ULL, 
            0x92D35B49BEFAAF44ULL, 0xAAA9ECA2BD91FCB7ULL, 0x24C8F4896A1EBBD6ULL, 0xA1298DE898357508ULL, 
            0x95F3E046F1049C54ULL, 0xFAFE2D7C5A36F7E0ULL, 0x662BFF0835D0B3CFULL, 0xA9569E53794EEF18ULL
        },
        {
            0x55F7E3810FC495E4ULL, 0x4A3AFF8DB4DDD1A7ULL, 0xE16ACB642F3A5F48ULL, 0xA3D2ED29512A7405ULL, 
            0xB46E22B25AA8189BULL, 0x25B896C4A4220EDAULL, 0xDCC3072D58ABB4C2ULL, 0x2BCC692EC3BAC25EULL, 
            0x1AE7EA0C5335258DULL, 0x8619D3C8E68F7EFBULL, 0x31A98421F9C4AB88ULL, 0xBAB19C1305CDB353ULL, 
            0x369E31B55BD7DF4EULL, 0xB8D56F6F276FB845ULL, 0xE95D4109CFF5F1C1ULL, 0x3A1E76E85328EE5AULL, 
            0x1578C4DD578F1C37ULL, 0x2452384FC1403376ULL, 0xE4E44AB24F1C1524ULL, 0x0722B61D62061651ULL, 
            0x57CF0C3D9DEFD535ULL, 0x3F14CCB00460A8D1ULL, 0x47A7434600188244ULL, 0x368496C2CAACF88EULL, 
            0x031A06AC25EF4F0BULL, 0x59549D0DEC2EDA58ULL, 0xA6BAD47974EFB617ULL, 0xC2D3200425ED29EEULL, 
            0x81D15CD4D2B26931ULL, 0xFA185D0E6486125EULL, 0xBCB0C16AB835F331ULL, 0x3616A04B4CA8E3A8ULL
        },
        {
            0xF986E881C62E2919ULL, 0x4D5D79C75122C09CULL, 0x0BCC98997AE537CEULL, 0xDD1A545DF07D86F1ULL, 
            0xEFAD647BA2322659ULL, 0x1B47D4EDA446D39AULL, 0xFBCB418FB7CDAB29ULL, 0x0A6DC2847E574C93ULL, 
            0x1C70CD40068697A1ULL, 0x0DA6C2E7BDD948E8ULL, 0x00746E6B7BA3F72EULL, 0xC29C9E4EC895979AULL, 
            0xF8548B4CF3A91496ULL, 0x0C311C3B4F92FB7BULL, 0x3E5A2BB2C92932CDULL, 0x3A152200454F4067ULL, 
            0xE4FAA52EFAD63F3EULL, 0x35AC1C4D4333C05EULL, 0x57B2A34A125E1B4BULL, 0x615DCB3409295FDEULL, 
            0x7E9B428EA31CEE10ULL, 0xB8C0BDDF8AAEC604ULL, 0x3A9C8294C1D8A81CULL, 0xD0A901566447C680ULL, 
            0x6B5D69E0B6D1041FULL, 0x1A2C06092F7E5A5FULL, 0x25E34030FDF64AC8ULL, 0x65B76DA98D03E6B5ULL, 
            0xA15FC595679558E1ULL, 0x0A13CD5BFBEC6769ULL, 0xD46E991954387604ULL, 0xA4C92F0D497F71CAULL
        },
        {
            0x5275BC9D92B2BDA7ULL, 0x73C005D2B2CAB240ULL, 0x37C0B73F5E3FB969ULL, 0x2410B9C6D4B2E1E6ULL, 
            0x0908C272175ED4B7ULL, 0x47B6E1908E3A18FAULL, 0xB5239DC49F26D219ULL, 0x25112696EAA50361ULL, 
            0x830180A3AD9B1136ULL, 0x2A9F0F24DF353598ULL, 0xD182D3B230321B78ULL, 0x550A5DFA9F32141EULL, 
            0x8E376DFDFECD2EBEULL, 0xA2D615EF7763452BULL, 0xF91DD87CE1A3CB71ULL, 0x55B550084D3340E5ULL, 
            0x184647EDD8334136ULL, 0xF8DF87FCE5BE3EADULL, 0x3DAA8277056A6A10ULL, 0xA2D35756040B2212ULL, 
            0x003A8A94BA40F20DULL, 0xAA0FD10E228E9BCAULL, 0x0EC9F57E33ED910AULL, 0xC236D49E2176BF9BULL, 
            0x5A39B82F2D737786ULL, 0x4A79B55E0C16032DULL, 0xC2D9AAAE88511B19ULL, 0x123EB873B8B2FC02ULL, 
            0x32104D549EF3D7ADULL, 0xEB7F89705FC5A40CULL, 0x96D3EF31D8C081E6ULL, 0x8BFC466D9651D689ULL
        },
        {
            0x9F0E80C8B7216218ULL, 0x2A5383B618362759ULL, 0xB1C69BC438C35420ULL, 0xCCD8FD087F966657ULL, 
            0x87B9F75067E3804AULL, 0x0589F2B90C8C3A3EULL, 0xDBF8BB9ACB383ED0ULL, 0xE2B732CD470B17BBULL, 
            0xB468728F5C486526ULL, 0x64414D18961FCBAFULL, 0x5ECF6AD02716D837ULL, 0x76110958B62AE605ULL, 
            0x383E8E4A49D0F39BULL, 0xDDFC5D41299D3E81ULL, 0x6334EA27446C63F5ULL, 0xE0688048DF33B681ULL, 
            0xB1572B37CA425905ULL, 0x29F06BAC03FB4A4DULL, 0x20DEFF1D068C8335ULL, 0x5E72CA7BAF6F742CULL, 
            0x8A20094DFA68A722ULL, 0xF102B0A19DC2F8C7ULL, 0x2328AE6C9E7F8750ULL, 0xAF046CB37B87B7FDULL, 
            0x5F5430F35BEA9220ULL, 0xB99FCC984F6BC5D0ULL, 0xB39797E728E660ADULL, 0x095E53EFA077BF9CULL, 
            0x134FEDE2EEAC89DEULL, 0x008ADBFA1CD5721CULL, 0x0A54A879F7B31536ULL, 0xAB7FC4D89D0A3322ULL
        },
        {
            0x839BDD8581075747ULL, 0xC5F4A2BFC575FE9BULL, 0x52C65F0C7DC4862CULL, 0xF53648194748B1FBULL, 
            0xA4CF59EFE0B5BADFULL, 0xAEAC0680F71B167FULL, 0xD56F3D93E0BCFE30ULL, 0x83D3969CFB06378FULL, 
            0xC29D55DC71810FEDULL, 0x2234B5BBD88AE081ULL, 0x4F7DE1160B1A79CFULL, 0x75CE772036231259ULL, 
            0x11CB2EF99433B6D6ULL, 0xFDE3A96D2BD8565DULL, 0x0924D20C8FE1ED57ULL, 0x026E0D828EE994BBULL, 
            0xC2EEC1BD02C1DA99ULL, 0xD4DFC05D4F385F4EULL, 0x716608822EE89DFDULL, 0x7BD4D52BF910593BULL, 
            0x90198E1C879F7B77ULL, 0x57A2ADEB777DC87CULL, 0xCDBD5994678559DAULL, 0x8B74E44C06AB3FCAULL, 
            0x995A50261C8FBC44ULL, 0x18766EBCA61F7C89ULL, 0x3E82C8D858AF07F1ULL, 0xE6B7FF57BA979B69ULL, 
            0x80B2ED706896C0E2ULL, 0x00CD0B4E1813087DULL, 0x5EC39B88EF295B46ULL, 0xD5045C44700E2E61ULL
        }
    },
    {
        {
            0xB1CD33AD492F6B35ULL, 0x25225591EC44C011ULL, 0xF3ECA204EDA94634ULL, 0xB5B7E07D750FB6FEULL, 
            0xE721060BA9E780B2ULL, 0x589F69E04981A9FFULL, 0x7564C9F4C44D066DULL, 0xDB3B234E022626EDULL, 
            0xB35D670373A3EEFFULL, 0x2BEDF5A0262F20EFULL, 0xA43C702368B6C787ULL, 0xAD529936C77DD3C9ULL, 
            0xF895D3E8EDA31F05ULL, 0x473F7DF288095379ULL, 0x751F1F88615940EFULL, 0xD2FDA149FFBC401AULL, 
            0xB8695F3D52D587F7ULL, 0x5346091C9783A0EAULL, 0x3B4C1968BE45825AULL, 0x886B5497A97AF800ULL, 
            0xA23FCF3A4D11CDD9ULL, 0xCB340FE2A2DDBA57ULL, 0xACF6FBE95335BF7FULL, 0x49EFA7B3E4B59D99ULL, 
            0x5486F4D5C97D6FCBULL, 0xE27EABD60F289DFCULL, 0x449F1BAD9ACA8904ULL, 0xC283743D9BB6FD5DULL, 
            0x76FEAF09115B4157ULL, 0xA2A453683414CBA5ULL, 0x69E33F3478536497ULL, 0xC54D101EFBB3D77DULL
        },
        {
            0xF14ED9F5F5A502E7ULL, 0xED2BA5D6D65B61C0ULL, 0xE6222114F00C33BCULL, 0x8B823F6597054D96ULL, 
            0xD72CEAA64F4EE12CULL, 0x7FA6F673D80C0FA1ULL, 0x4DB4B667179DC2ACULL, 0xD5B851FD0EE12C3EULL, 
            0x6FC0149ED5E5A463ULL, 0xB56B21E9E9F5E90BULL, 0x7CA75D9C7E814297ULL, 0x31E0C6C0833D8652ULL, 
            0x62BBBCD2640CB167ULL, 0x79A8E38142895D4BULL, 0xE0B311A19F94203DULL, 0x0F2A76F1316864C0ULL, 
            0xFAFB76E9780FC478ULL, 0x39EA680F6E4CF071ULL, 0x8E04F7C7FE54196FULL, 0x9CA695A22D9EFE5CULL, 
            0xCE89CB2617C02067ULL, 0xFCBA311D16FC028EULL, 0xAA82486A52D137C3ULL, 0x164BD3D133794CEEULL, 
            0xA1FEF00761E86269ULL, 0xB2CB9561754F5C88ULL, 0xFBACC9DF22BABBA1ULL, 0xE0074ABBD74CB605ULL, 
            0x47729F6D1A3E56FBULL, 0xD079F9402F65DEB2ULL, 0xE2972EF6B706C204ULL, 0xEA63590485A2BF6EULL
        },
        {
            0x1B681B60CBBECC8AULL, 0x58285EA1A320A701ULL, 0x1EF703E5055F80B6ULL, 0x46ABFA5B525E21AEULL, 
            0xDA2BA440AD1965E7ULL, 0x55C83785A652AFC0ULL, 0xAB18768ABD25CB16ULL, 0xEE03C2697C8C97D8ULL, 
            0xAEC7E9B0865C13B9ULL, 0xC1D1BA8525E4C13CULL, 0x4854F0440A8E9D8CULL, 0x432ADF337B3BC7CEULL, 
            0xC7535506F81F42B0ULL, 0x9FF48DA448BA710CULL, 0xCE191739901F82B7ULL, 0xC2B442F413B3D49EULL, 
            0x4DE2233069539AD6ULL, 0xF5C8B70D7A2B5A00ULL, 0x4F3FDC62031FDE17ULL, 0x7E694ADD4B2FEFAAULL, 
            0x3FEEA230D5128109ULL, 0x55520D8E9BAA808EULL, 0x0657754826BBA3FDULL, 0xB6C698F80AE294F8ULL, 
            0x4B736A09908321BFULL, 0x7C0E4E53AC57343AULL, 0x9D7A124008568B77ULL, 0xC0645843739416FBULL, 
            0x76B0C382D7B2FE1AULL, 0x26CF1817269AE6B3ULL, 0x7997AFD6970499D6ULL, 0x75D06EC25A1FBD97ULL
        },
        {
            0x6864CFCB24D3A92CULL, 0x1C65E3004EB13950ULL, 0x08F49EA53A6C996CULL, 0x48A9C97822EF7CABULL, 
            0x54B8062C62D3C588ULL, 0xA041B09DCAD0276EULL, 0xF736A53CA79C60C6ULL, 0xE69A1C80F3867138ULL, 
            0xF56B95C09E8E8D2BULL, 0x430008211C7C0851ULL, 0xA947ECF464606562ULL, 0x75C88C7512B5DFBCULL, 
            0x16E72166F02112F4ULL, 0xD3F2D865B16E3CABULL, 0xB4270B4D533CB01BULL, 0xBBFD2E0769BCD46AULL, 
            0x74E945A9B2A76383ULL, 0x281C4E8CAAEE935BULL, 0x9B98D6FED90BBB35ULL, 0xAA75D5FDC0758F8BULL, 
            0x04FD1B2DE0B2605EULL, 0xBD234B63E5A1CC69ULL, 0x208F79ED7518C802ULL, 0x78673418778B6B39ULL, 
            0x6DE9DB408A187196ULL, 0xCFDDD052F251FA7FULL, 0x31F80332909607EFULL, 0x9571357AEDE163F3ULL, 
            0x7A5C4F30F77ED08CULL, 0xFBA30A6747617513ULL, 0x646EAA33A9A06228ULL, 0x3DFCC7A641CAEA3FULL
        },
        {
            0xD096230792F7AFEAULL, 0xC3F36389A0072833ULL, 0x972670BB05E2F16DULL, 0x139BD44205B4D4ECULL, 
            0xAFE2ED34F748E41BULL, 0xB6AEF7CA4F23F831ULL, 0xBC4564F4D6FC3DCEULL, 0xBE66E09D1338BCDDULL, 
            0x8549BA873BE0855BULL, 0x1120D515E90D8DACULL, 0x876AF2FB74CDE085ULL, 0x487C688AADFCD30AULL, 
            0xDDF168A9B6372BC8ULL, 0x3DB2CF8B5446432DULL, 0x8724D610106E0142ULL, 0xBDACD64E7C22D0D3ULL, 
            0xDB5BA365F0A4CBADULL, 0x0ED0668FE34FD823ULL, 0xD6B3F274973B7084ULL, 0x26CFD25C1DB6E0F9ULL, 
            0x4B655FCDCC9FC4CBULL, 0x96C769F4392E98E2ULL, 0x76807ADD10924335ULL, 0xB045C23160042636ULL, 
            0xA702B5A305DC6819ULL, 0x557343E7F2A809DBULL, 0x0D484B336E45D6B1ULL, 0xDB5C5BFA1695AE82ULL, 
            0xE1667BE5F47B314DULL, 0xC4E186B0406F255FULL, 0x7D1EDC34F2AC6FF8ULL, 0x6D674F0637659A3AULL
        },
        {
            0x92EBD0ADCF6E4B8BULL, 0x7D94FC5556491427ULL, 0x83611F256C3BB9FEULL, 0x7AD373BCC7D82006ULL, 
            0x605CBCAB6B2EF078ULL, 0x9B16463C152AE724ULL, 0x7A17EB753D4B5E74ULL, 0xD26A4C4652727840ULL, 
            0x57B04BCC08383EE5ULL, 0x563653CD3F54CCB5ULL, 0x8B32BDC18557F162ULL, 0x9F0FF4EE05ABE978ULL, 
            0x932185FA19197A55ULL, 0xC67EA32AD6A703AAULL, 0x320F55809F2A2C99ULL, 0x50D28F5D8A67DD00ULL, 
            0xF581FE67B1CB19F0ULL, 0x421E6C99BBB925EBULL, 0x5A03635B2215AF0BULL, 0x8BC9557BA0A5546CULL, 
            0x9B2298A0CE56A4C0ULL, 0x32E78A9F92165749ULL, 0x559C93B7BDB83C82ULL, 0xE0B3E054BDEE7B9EULL, 
            0x24E5FA0289164549ULL, 0xB6952FBC354D4F8DULL, 0x6A64272CA7240C5EULL, 0x5BCAAA17718C3BE7ULL, 
            0x1DF0D72A32CCE6A5ULL, 0x72B8BBBC5B2A5204ULL, 0xDCB97C5A34DEFDD0ULL, 0x6F8D68F2CE67D975ULL
        }
    },
    {
        {
            0xEDC79CF04D07024EULL, 0x72C4FE7406C8D849ULL, 0x21548028E6C5172EULL, 0xDE70659404A14C38ULL, 
            0x86222A547D76DAFCULL, 0x5959516338D00587ULL, 0xE49BE3A68A200A95ULL, 0x0005E9B91B8ED1B1ULL, 
            0xC0863625206E06F3ULL, 0x30A421BFEB028B3CULL, 0x3EAD7ED0414D1BB1ULL, 0x168218B86ADB3877ULL, 
            0x7A993EA012C5B1B9ULL, 0x7BFB652BCB66ED74ULL, 0x38A1ECF49510BEFAULL, 0xFC3902CCC77BA7DFULL, 
            0x63D44B5FDFFA5640ULL, 0x37D0AF8A02FB8BA9ULL, 0x2311BBCD6BD39143ULL, 0xC14C4145F808CCAFULL, 
            0x43F958758469BF05ULL, 0x46956A3F35919AABULL, 0x94B4B215BD473CF6ULL, 0x0FA1EE6AB1286FC2ULL, 
            0x48763D3511943E5EULL, 0x2FFB231FB5197CDDULL, 0x5A6CC8854B91B405ULL, 0x19218366F7F2981AULL, 
            0xF0B51B1A2CA05C4BULL, 0x63799AAE49FC4490ULL, 0x8CAFFE3DAD4333BCULL, 0x789863C003D44ECFULL
        },
        {
            0xDA9FD2113B51C263ULL, 0x3A52EB076F82F0BAULL, 0x77CE7D56F69A74AEULL, 0x233D50123F0EEAD3ULL, 
            0x351D7EB053818351ULL, 0x0B9809B9A487BEFBULL, 0xF90774054E84E356ULL, 0x08B51BB9A83157F0ULL, 
            0x525A85427335D61AULL, 0xABB9A37824CEDD40ULL, 0xE890AC4C4F2D2DDCULL, 0x810D469AA5DE12B5ULL, 
            0x1C245933EC19DA71ULL, 0xA73049E5C856D7E7ULL, 0x9E236DEC6385B171ULL, 0xF62190E5CDE4F397ULL, 
            0x8BC683B1068C7818ULL, 0x9E2E6B90D2ACD389ULL, 0x6C47D8B76AF96674ULL, 0x62CDE7172AE38C06ULL, 
            0xD27B3B5359746803ULL, 0x5C3FA7922E64DF10ULL, 0x4BB13D407E3D0395ULL, 0x4BCE61B912A12197ULL, 
            0x5833C8F41C17EED8ULL, 0x98DFE8B4B322BC7FULL, 0x31E26A6027094599ULL, 0xB771137C735E1CA5ULL, 
            0xCDD572DBCEB0AEF6ULL, 0x31BF1BBA1D0D332DULL, 0x00BB847C23B52776ULL, 0x05BDA361CF121708ULL
        },
        {
            0xA4C0560535B4128EULL, 0x64244C84053BFB69ULL, 0x05E5F31EBCF95BA5ULL, 0x11B0FAB8411EA185ULL, 
            0x667D9E793277D333ULL, 0xCD78087CABEAE6F0ULL, 0xC24961DFA92E2D74ULL, 0xA4FCB936CDC355FEULL, 
            0x70664C540E39EFB9ULL, 0x7EB1A89751B7CB14ULL, 0xCAF1892ACDA16436ULL, 0xBFF53FBEC2116FB6ULL, 
            0x3A15E97A1E5A3B6AULL, 0x696D1154F93405AFULL, 0x3D099823D7020366ULL, 0xF68514D8308DCDD7ULL, 
            0xF1919FE66F55914FULL, 0x970DEB6475220A98ULL, 0x68D9FE39B02E288DULL, 0x7AF234AC2E9677FFULL, 
            0xF1F454A5242D40CCULL, 0xF65FBADCB1A8C0A3ULL, 0xDC781BD57260E6E2ULL, 0xD72EE39EF16EB6C6ULL, 
            0xC80E3D3B6740C279ULL, 0x1761EE8A689F2014ULL, 0xA3C6077A152E7FABULL, 0x8DC28F2B19A30FBDULL, 
            0x65C9D53AD0B70F3CULL, 0x4959576AC723CCA7ULL, 0xF50458B282ABEA88ULL, 0xE2E78FFFA241C015ULL
        },
        {
            0x242871161E64010BULL, 0xC124A74689D78377ULL, 0x3DB25477BC763675ULL, 0x5E10859062C7100BULL, 
            0x6CCFA57E4024C07BULL, 0x8A1D74580A366AB1ULL, 0x13F960F0AE261C51ULL, 0x78EF76F2FD61845BULL, 
            0x29C6D164AB8F7028ULL, 0x079CA86A99FF41C1ULL, 0xECF9CBB776167C35ULL, 0x4C7EA24B618FA19BULL, 
            0xAA00A63B2311A4B1ULL, 0x8284E22163C76679ULL, 0x299C9F9A3EC482BFULL, 0x4ED4106125D01CE2ULL, 
            0xBEAFBAACA54DDC71ULL, 0xF692C2E2CB9F2345ULL, 0xEFC5253EE529CC62ULL, 0x1E2643D933AABDD7ULL, 
            0xFBDAF48908D63B18ULL, 0x79E132E63B2BBD5FULL, 0x27D9C954AAA10EC5ULL, 0x1D5459D35B6B5B63ULL, 
            0x614C8E77FE4830C4ULL, 0x2E60E76E942ECC4AULL, 0xABB3C34192835721ULL, 0xF3FFDC44A976326CULL, 
            0x1349DCECB55C5897ULL, 0x7A648EF57D517FACULL, 0xEBA81B87D892EEA2ULL, 0x9ACB370C52876917ULL
        },
        {
            0xD0404A034C48350CULL, 0x01453A7AC202E168ULL, 0x5F9D9450108EDD7FULL, 0x338B4FF0FD51F44FULL, 
            0xA119C093E7AF2EBFULL, 0xD8CB6C5765CA9887ULL, 0x8115532907693EF6ULL, 0xEFE896743CF3AD7DULL, 
            0x25B4C34E6D37D632ULL, 0x27654AA60E3D3AC7ULL, 0xA4669A06C6D92A23ULL, 0x37100CB461D9E524ULL, 
            0x8A7B981655288D8FULL, 0xD41893B810695CB6ULL, 0xD4825FBC05D97AA4ULL, 0x7B08381437E7190AULL, 
            0x68655BCEEBA4A798ULL, 0x7E2079C9AE506721ULL, 0x5AC94F1FC97384ECULL, 0xA3C8CF77C9BF0FCEULL, 
            0xBA4AE0011D8C0EC4ULL, 0x4505B02D1FDB55ABULL, 0x42C25FC74CBF6B70ULL, 0x3608C5F858F687C9ULL, 
            0x7D49062164FE98B7ULL, 0x1A79B7EDF7B4E9CFULL, 0xF08CAF9D5E64B4CAULL, 0x45D27321C288CE5CULL, 
            0xCC8451258BC333A1ULL, 0xC1E76AFE73D0A052ULL, 0x6703954829AF0C92ULL, 0xB7ADE2EC89A6C07FULL
        },
        {
            0x06E6B03AE1D88361ULL, 0x1E6D7AB4AA697BC2ULL, 0xAD1B7C4A840C824AULL, 0x7022DB5B54122B7DULL, 
            0x2C472ADB5959C7D3ULL, 0x6847103EB635C3E0ULL, 0xB508019B5B9AD61BULL, 0x214B00F364B67603ULL, 
            0xF0E13415C20A2D7FULL, 0x54A18E73B85A438DULL, 0x16A7E7BF2A2DC069ULL, 0xB9961B2A1DEF5885ULL, 
            0x0690B669C1EFD0F2ULL, 0xC530A1357FE694BDULL, 0x96A4F55C85EBE6DEULL, 0x6B93988E22F32929ULL, 
            0xDC43CDD96CC579ECULL, 0x9DAA05524026A249ULL, 0x4C82AD7C2E93FFC8ULL, 0xEEC9E1458761D81BULL, 
            0xF5E8C4A32ADD48FCULL, 0x166986E504FE0F82ULL, 0x1833E2F5E0EF8B95ULL, 0xA8443308D4D1C20BULL, 
            0x21BF36CA85460CF9ULL, 0xD59A81E9075515A7ULL, 0xDBEEA62D179804C6ULL, 0xA2C188696DED4CE4ULL, 
            0x4FFFF4F4BAAE83B0ULL, 0x79B32EA14F9DDA92ULL, 0x1FA0225388949673ULL, 0x9563330AA678079EULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseFConstants = {
    0x69DF7B0258E7060EULL,
    0x823036C68519B90AULL,
    0x0B51ACF98DDA0127ULL,
    0x69DF7B0258E7060EULL,
    0x823036C68519B90AULL,
    0x0B51ACF98DDA0127ULL,
    0x022F7D0B46A67413ULL,
    0x93985D28EBB22B07ULL,
    0x5A,
    0xFF,
    0xC1,
    0x51,
    0x2E,
    0xFB,
    0x1F,
    0x8F
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseGSalts = {
    {
        {
            0x899C30ADD3A8234DULL, 0x40B08732E732C360ULL, 0xED4955CA442BD660ULL, 0x8FBA7B93B677FCD9ULL, 
            0xAF76CDFBC5250D2EULL, 0xD96E576BDE1CB2C3ULL, 0x7154452C8AD04F6BULL, 0xB78AB6C1EBF44FE0ULL, 
            0x8807CECE064C5C23ULL, 0x415509E15DFC41F4ULL, 0x107B753891C1D27EULL, 0xFC8BEE30AEA8D903ULL, 
            0xD214E9AAD9BE9D44ULL, 0x3DAEE7F1F7E30349ULL, 0xA7B36617B1EF0F1AULL, 0x57C1AE16904DB714ULL, 
            0xB172E4BECC90846CULL, 0x4E53ADA5537F1146ULL, 0x007A3EA1D7B744FAULL, 0xF216BB3A60FC59D9ULL, 
            0x4D4BF19F867E7729ULL, 0xEE15149153A671EAULL, 0x3E34B576BACEC31DULL, 0x341E48346A3FCB41ULL, 
            0x65FC6303BABBBD21ULL, 0x5A80D0FF2925F856ULL, 0x402FAB133D337ECAULL, 0xA7934CD2D8097F5BULL, 
            0x59DE22E09AC55E98ULL, 0x9FBD3E1938C40841ULL, 0xAAF58063EEFF9067ULL, 0xC9EFBD49C6069A05ULL
        },
        {
            0x29DCEACD27718317ULL, 0xC8D55DE58AD15383ULL, 0xE82F371EAF7DCA2FULL, 0x1BB5C050D62C54DBULL, 
            0xF05C88679360BF2CULL, 0xB97B28FBEE537254ULL, 0x3D61E80AEBD3328BULL, 0x8734A26BC1C1824DULL, 
            0x226CD424694313E5ULL, 0xD177AFBC16B2A112ULL, 0xDC9F51D5B6FA0124ULL, 0x82AB6F6A12A3B4BAULL, 
            0x09AB77F3081CFD19ULL, 0xE4382F72838AC55AULL, 0x37FF4A1437D4EEEAULL, 0x6C16E2C436EF2F61ULL, 
            0xC60F82FFA87640A7ULL, 0xD8FA72B1A3326F9DULL, 0xCD79F7331AE403F5ULL, 0xBA3F0325EFBB3AFAULL, 
            0x1FF82A727EA78D28ULL, 0x6E8AEB9F87FB2AA3ULL, 0x6FA76016FD8321BDULL, 0xDD67B1EF5F925060ULL, 
            0x301F18C6602CA261ULL, 0x26851EF54809FF01ULL, 0x83F2C6C80EDA3D41ULL, 0xC20AA2889BB8AD8DULL, 
            0xD5DADC353B10024DULL, 0x0B984D9217BB4660ULL, 0xCA291A0A62F09685ULL, 0x2C83156CC5E37B07ULL
        },
        {
            0x349CB05475B3724FULL, 0x299DEA9C15979BD4ULL, 0x45CDD800AF4266E0ULL, 0x758C9B6D5DA1D3F0ULL, 
            0x88B0C30F205EFFE1ULL, 0x1B32AA35A8A50C0BULL, 0xAC409D708A622866ULL, 0x0DB2F77D8508AF3CULL, 
            0x017317F49178B7B8ULL, 0xB834DD655BF08606ULL, 0xC4B8EC3D9169F0D9ULL, 0xFA1EEC2C3E2C14C5ULL, 
            0x060B4C4D18E9AD20ULL, 0x1024343C04EFEA93ULL, 0xA3C750D48F989A62ULL, 0x26746A57A90C4C37ULL, 
            0xCE8738E6400FAA8BULL, 0xFE1DC3AA998ADD83ULL, 0xD7D7C766116FE1E2ULL, 0x6B0CD86DA14D2BB0ULL, 
            0x35A92D1CC6B6F79DULL, 0x67A29A3FE29DDC7DULL, 0xE7338A20CC804A7EULL, 0xDB586461A1E3C507ULL, 
            0xD8EDB728753DEC19ULL, 0x9E8E0E61D28916F6ULL, 0x646DC29C9D49219FULL, 0x1C9C6AC50D6B1023ULL, 
            0x6F03A19251FCAEBCULL, 0xD66872C7769B8EEFULL, 0xF83510B3211610BBULL, 0x65E6617A8F7AEE9CULL
        },
        {
            0x8DA3DEF787E6CC7FULL, 0xAF07D1A14F8FFB69ULL, 0x229DCA6C3B17016AULL, 0x62C184009DA9F729ULL, 
            0x0C2A183EDB5A11B0ULL, 0xEBDF8F86770CEB6FULL, 0x88BD1AF0258C348EULL, 0xB75F7DA8AC91F41BULL, 
            0xE5C5BC7FE626B3CAULL, 0x2DBE4F67023C5027ULL, 0xBFF715D4FDF9EBB5ULL, 0x7BDBA21F34DBB16AULL, 
            0x73E3C372842D2A08ULL, 0x26C8F43294575749ULL, 0x2FDFCC5380B78680ULL, 0x931A5C65D1C9EDFDULL, 
            0xF0CA05D8C353EFFEULL, 0x43DDC533CF572B8DULL, 0x8E6C59134E825E28ULL, 0xDC783F0D07C346ADULL, 
            0xD195F90385C9E509ULL, 0x0AC7C7F56973674FULL, 0x95D838F829F4C716ULL, 0x51A5B1E47C9761A7ULL, 
            0x712052900D9CCE66ULL, 0x15B2CEE77936C403ULL, 0x3217EB427D3F6273ULL, 0xCADC711923F5BA62ULL, 
            0x2B7C238572815C13ULL, 0xB3A3EDA0E274BD31ULL, 0xA8D54CA283BB9758ULL, 0x8E8C91F14C746756ULL
        },
        {
            0x4AA90C6620DD0C4BULL, 0xEB2E455ACB6438FDULL, 0x7121C9BF001FFADBULL, 0x8B8808712B4DD1AAULL, 
            0x498949187DC9AAFDULL, 0xA5016FA87E1A13AEULL, 0x59C444D2495A2356ULL, 0x9948EF21701C8AE2ULL, 
            0xCBCDDE4BE5A7E30EULL, 0x94CBB758C67FF9AAULL, 0x8E3E1487A5CA1865ULL, 0x83A3728DA0E8B2A3ULL, 
            0x73264ECEBF4397F3ULL, 0x29BE9753585D6841ULL, 0xC87ED9A7DEAE4748ULL, 0x9DF3981E3067C2CDULL, 
            0x46EB306D26CCAEA1ULL, 0x4F798831F1D56CD1ULL, 0xBAE26AA868E66744ULL, 0xFA46FA28F99D3724ULL, 
            0x221AABB878D4EDC0ULL, 0xFD60AD5257C20E78ULL, 0x5E595770520E96CCULL, 0x9A000D1AE0A3CF3CULL, 
            0x0689AD0AD5829D4AULL, 0x810A41D3D1FB97F8ULL, 0x498F83F1F3DA2133ULL, 0x88C6E9509BDBFB2EULL, 
            0x41CD6A3A8AA9EBD0ULL, 0x40DE744FF2111876ULL, 0xB7659F40E8CE3F72ULL, 0x36AB32484EF086FEULL
        },
        {
            0x0869F79CC5B02B5DULL, 0x443E684AA98ECB1EULL, 0xB39357DC890CBED7ULL, 0xECF76FE9D42D8F24ULL, 
            0x2F0975DD9FAB25C5ULL, 0xF2931C920D9725DAULL, 0x42A338A8163719A7ULL, 0x31E308BE81924D1DULL, 
            0x8215430451885B66ULL, 0x8F8D3E75A7A3986EULL, 0x3D486945C35821CAULL, 0xF05A3A507BA8B742ULL, 
            0xFB33BC13195307D8ULL, 0xB35701D90BBF9FC3ULL, 0x22BDF22B02055922ULL, 0xAAE2136B4F2E5319ULL, 
            0x93C160D872AD5112ULL, 0x67E16E02C56A6E6EULL, 0x5BA82453B54BD4F3ULL, 0xDAB917356FAE5B4DULL, 
            0x50AA890CCD278A47ULL, 0xFCCD1E2654058E49ULL, 0xC950219601F81CD4ULL, 0x48A2EFD616CF398CULL, 
            0x98E22662AFD952FBULL, 0xA6B0CB99D51F4810ULL, 0x5BD91465A0C4C144ULL, 0xD028196DEC2537C3ULL, 
            0xFE6231856FE32079ULL, 0xA4F99E50744AC659ULL, 0x706AB8200B760814ULL, 0x1FF3F5F833CB3B2DULL
        }
    },
    {
        {
            0x80ECA9AF6FF7E4EBULL, 0xC41144DBE299C1D4ULL, 0x30793E01082BC82DULL, 0x1CF0F39EB19370ABULL, 
            0x6737064CCEA6388CULL, 0x11B054976D484FA6ULL, 0x6AD79502229FCCA4ULL, 0xD766A1A92E179465ULL, 
            0xC2C24430BB331FC8ULL, 0xE3C02B251CB6F803ULL, 0xDEEB0E329BAFBDC1ULL, 0xCA6F6B571BCBAA9BULL, 
            0x4DFBFC5E646BAF1CULL, 0xE9DF7ECC517CCD15ULL, 0x20B736A334B138C0ULL, 0x0B8C102C42B9BA26ULL, 
            0x56DF5ED63DB09DEDULL, 0xA311059CE6345BB9ULL, 0x134B5CD180262C46ULL, 0x13738355CE14E7CFULL, 
            0xDAAC66B29535B586ULL, 0x2995EFB2579B61F0ULL, 0xC211B4B7C9253A0AULL, 0x35ADCD5F2406DC95ULL, 
            0xDE1362FFB4EC366CULL, 0x9BAF60B8676F21B3ULL, 0xE42BB06E394C7335ULL, 0xA94482782B753F51ULL, 
            0x07E4108AC9F4CA47ULL, 0xC072E44DD9B616D5ULL, 0xBA8A1EF81C04426BULL, 0xC087EB7245F6259EULL
        },
        {
            0x623C37EAF2FB80E8ULL, 0x1B4AE3B5835F2BA7ULL, 0xFDB9B0E542E2109CULL, 0x2087C51C9A985BE0ULL, 
            0xFCCFF7F687223225ULL, 0x3967CBCDBD0BB204ULL, 0xAE1E783F8DAFCE57ULL, 0x1B924CED2E3EC051ULL, 
            0xF2B9B7A72AFA07DBULL, 0x29EB476B21362A88ULL, 0xF5C41E9729403012ULL, 0x5DBE1043C11850E8ULL, 
            0x5D94F1BB96E4B46DULL, 0x71AA5EF37DACDE70ULL, 0x7CE14066079A5DE6ULL, 0x14002B50C70FEB85ULL, 
            0xD0E3171DB4DFDA36ULL, 0x702A344AB69EAFF1ULL, 0x44AF164773F22C6DULL, 0x6B9385E7221BB0F3ULL, 
            0x1AC5BC8120DFD443ULL, 0x935A591414BC035DULL, 0xA71C4B55571471B6ULL, 0xFD87E972C617BD3FULL, 
            0x16728FD5B4E9C409ULL, 0x2E2654BC9A709BE3ULL, 0x7765A098B9B5F9D2ULL, 0x3638E0F9871DDB38ULL, 
            0xDFC7C2290A5AA505ULL, 0x11B25DE8A9AC6C22ULL, 0xB31A0D29D9661F44ULL, 0xEB892E72756CDDDEULL
        },
        {
            0x1BCE8FCCE4CCDB54ULL, 0xE8A7C16FB2686AC8ULL, 0x107F1F7B24490B32ULL, 0x94F15846BD16CA75ULL, 
            0xDED6781B9ABC0FE5ULL, 0xFCF01E8EC715B0D1ULL, 0xD6FF6F7DD131E0D3ULL, 0xCE3F1527228C4177ULL, 
            0x4107043FAC6021CDULL, 0x6B62DA3156394496ULL, 0xF613BED4BBF352F6ULL, 0x5880788798215D66ULL, 
            0xE192638B1B8A69FCULL, 0x891AF0F43EE54E08ULL, 0xBFD35F01977DBA7BULL, 0xCE8D36A893E0BEADULL, 
            0x4BD8A4B1F2AE9F6FULL, 0xA339BC899AD18B78ULL, 0x5B299B5BDDB1A055ULL, 0xB204E64363CBBE47ULL, 
            0x9E98EC4085055D13ULL, 0xD74B2C4588323434ULL, 0xBAC9FBDDB718E0AFULL, 0x636F38EEA725F528ULL, 
            0xDDDB1718E9952BA3ULL, 0x6DD0E774F788A2EBULL, 0xC9C114460D37C956ULL, 0xDADD8A9CA0B2230DULL, 
            0xE9083EAE25CFB523ULL, 0x4CBC27F1DE40E5C8ULL, 0xD13346DC07B11633ULL, 0xAC3854682C60B9DAULL
        },
        {
            0xD23EB41D93063026ULL, 0xD6266EEE722EAE6EULL, 0x89DEF3A9968C8438ULL, 0x8490D07B77334E1AULL, 
            0xDFD13CB357C6D576ULL, 0xC53F35E9052521BFULL, 0xA696BFF757D21950ULL, 0x1614A9B71D103662ULL, 
            0xA195CF974E10CDE6ULL, 0x1DD4829C071ADF36ULL, 0xDCDC4F62A076AEDCULL, 0x8CEA7AD2C2144C76ULL, 
            0x945576BCF249F4F4ULL, 0xDF15DEF95A45D94AULL, 0xFDF09CA184804A7EULL, 0x5EB985DFFEEB33F8ULL, 
            0x3855BCBEE9FEE43BULL, 0x5E243358F2D9C063ULL, 0x7C3E81EBCAFDFF7FULL, 0x5B384B9385859A4EULL, 
            0x3CEE7C46D1F2FFE6ULL, 0x3ABE607266582F40ULL, 0xF7CB2AF9ED51FE29ULL, 0xE9CE96D25122F59CULL, 
            0xF927178F0118A9E4ULL, 0x519609C0B1AB06B4ULL, 0x8EC07F3F7302F8B4ULL, 0x84945331773B8A31ULL, 
            0x29092CF00B62F165ULL, 0xDD4BEBF42190C9A6ULL, 0xAF83ECF7A9CA72CAULL, 0x798DB58D4F71AB62ULL
        },
        {
            0x0BA60DD05D527657ULL, 0x9F48857915666550ULL, 0xF625A4A0D666B0BAULL, 0x8BBFB81ADACE15BAULL, 
            0xD822C60B000C69AFULL, 0x6CDF44520663FAE0ULL, 0xA851B845E5EDDD0DULL, 0xD3D9FD37011D596FULL, 
            0x8163B8D8B58CD50BULL, 0x89C46D704E2C341FULL, 0xA983242AFCB0F226ULL, 0x30213692C0214D38ULL, 
            0xE6CE3670537181DAULL, 0xC81E918AA60A21FBULL, 0x6F4B50D9D02CB7FAULL, 0x2E998372293100BEULL, 
            0xB65E63C09E3EF41FULL, 0xEA6691924456BA9BULL, 0xDFBDB1C0D69DDC0AULL, 0x344FDEEDF45315CDULL, 
            0xAA3EF1C970D97D5DULL, 0x4075245D1330EEB3ULL, 0x245EEDB998A4DEA0ULL, 0xAF7E4D1F4C4BEC70ULL, 
            0x1C3D3013B9190CE2ULL, 0x5B47F4E22171A865ULL, 0xA8EA6753B7191907ULL, 0x043104B588016C9BULL, 
            0xEAC5C2F724598390ULL, 0xDA406007C563B1DBULL, 0x23B77AC828E503A2ULL, 0x6B4536025F1F176EULL
        },
        {
            0x6B73E2D6C9934F3DULL, 0x4B8CA3D33819012DULL, 0xD92C8F0EAA5B83C4ULL, 0xC9FD00D252788D30ULL, 
            0xC0A6EF483D2D7587ULL, 0x1668972CDA6BC6E1ULL, 0x034324AA26630BD0ULL, 0x0C1A72798E811885ULL, 
            0x37EF74BADDF47A5CULL, 0x41A8495153C9EFE2ULL, 0x69A9D5E861C1C198ULL, 0x86865CFD077BC8EEULL, 
            0x88BB63F431C64E9BULL, 0x10153410C0DFE362ULL, 0x0A66AF4747796233ULL, 0x35CDF277FFFBCEA1ULL, 
            0x87EDEC31BE9D68E8ULL, 0x6B749FCD66CEAC87ULL, 0x6E62991D28F0DC14ULL, 0xB55B7475523B7320ULL, 
            0xFBA90D295A90C758ULL, 0x7194518F161B01E0ULL, 0x4FF79768E9D80943ULL, 0xDF0B403E379A9573ULL, 
            0xBFB4EBA431B41488ULL, 0x18BC53BEFC8FC117ULL, 0x50ECC0D26694A43EULL, 0x468EC4982E9DD0A1ULL, 
            0x628081F85F5FAD17ULL, 0xF03FC532B5314D14ULL, 0x340F1FB3B1706E2BULL, 0xE14F90D3D7EAC6D7ULL
        }
    },
    {
        {
            0x3BA6423811355A52ULL, 0x151B3118EC28DAA2ULL, 0xEFDCABF9D21B35D6ULL, 0x5307FB7D999BFA6BULL, 
            0x4A67FB08A16FF2C4ULL, 0x2A4F4501743A5DB4ULL, 0xB81C93D0A84E4019ULL, 0x835A7A82F564BF78ULL, 
            0xF5455386F7B1DD60ULL, 0x2BCCDA3D21CCE714ULL, 0x4FDD80C0C99D04D7ULL, 0x795C7E53E0B64727ULL, 
            0x018C3842271D0644ULL, 0x29E5A85C67A09C6EULL, 0xE44F5698DEDD0000ULL, 0xB660488F0EA643E4ULL, 
            0x435150009AF0382AULL, 0x38AF82F154564219ULL, 0x2BAA1D78B325B8ABULL, 0xE2F89D191FB15223ULL, 
            0xEC7C765E1A9D6020ULL, 0xE16DA27DE43C50B2ULL, 0x5707A5ACAB53252BULL, 0x49E6A14314BCD3B2ULL, 
            0x8FA3D2A094844AD8ULL, 0x36B8EEC0013367E3ULL, 0x1E48A15C87533FDEULL, 0xAAD0FE60EBDFBE72ULL, 
            0xD3BCE1973F9510AAULL, 0xDAF84F8152FF0106ULL, 0xF9D1A4A83ABAC8BBULL, 0x729FF644921910B8ULL
        },
        {
            0x70F0912B289AB3C5ULL, 0xC3FDDE4DEF81F9DDULL, 0xE5913C61CAB7A810ULL, 0xC28E2496409F0904ULL, 
            0xCA0D98C0F655B9B4ULL, 0x23B3567A5A4D28D8ULL, 0xCCA38BE4F81ED024ULL, 0x1263A46E138BD22CULL, 
            0x6B1FEB79D46DF4BCULL, 0x65F4D20579B6BF0FULL, 0xE0B41F988551C222ULL, 0xAD66879A7A04873BULL, 
            0x252E4E79153F5DFCULL, 0x7FE6C7D11F7029E1ULL, 0x60B18A052D03823EULL, 0xC8F7C553261C40B8ULL, 
            0xF8494EC2BA83A966ULL, 0x1ACC221B33F51804ULL, 0xF7272E5B2D88AC9EULL, 0xB71498859D9AD1BFULL, 
            0x6F37FEC9076AE296ULL, 0xFC8BBF72651B4ED5ULL, 0x7A1D21F2C6AB51F2ULL, 0xDBC70F1BD6018495ULL, 
            0xE123B730BACB4C00ULL, 0xF8CB45DB303B2453ULL, 0x6F50A60CBED5DB64ULL, 0x5A1946DA351456B7ULL, 
            0xE7B6960028357659ULL, 0x3D662B7BD3F65DF7ULL, 0x96BDFA108FA4D226ULL, 0x04C6FA9CCE4F7F9EULL
        },
        {
            0x8D5FF4A619F1C993ULL, 0x697476AED2B24633ULL, 0x835C98ACE77A5786ULL, 0x0FD8C266B07BC781ULL, 
            0xDE7E49E1BDC6F3B3ULL, 0xBEE4A47C8DB6C97DULL, 0x6DC7AE9797FFF778ULL, 0x936252300D337986ULL, 
            0x4D2AC74F9BDDF905ULL, 0x6161C743735B2B44ULL, 0x619F931516971188ULL, 0xEB3EFB1504558E19ULL, 
            0xBB1C6F1B96842190ULL, 0x4E32019847B7C42BULL, 0x04B53B790647E29DULL, 0xECAA476BF54D0171ULL, 
            0xA93B518FA4BBDD20ULL, 0xD10C412F6189460CULL, 0xFA227FB7D1B9D87FULL, 0x5FDD55A2E6355A88ULL, 
            0x7B444B64B0763A7DULL, 0xC71AC15999F79EFDULL, 0x4702F4FE8C132DD4ULL, 0xB8478128DA23B66BULL, 
            0x16C9B460474EE0E5ULL, 0xDFE1A0EEA00F2AD2ULL, 0x4FE3F2D8FC84D1F6ULL, 0xBF9E8C32FA9859AEULL, 
            0x74DFCA4A70DDCE7DULL, 0x999B3D9E2D30AF05ULL, 0x52339BCF8C8FE988ULL, 0x6E55E2BF86E53040ULL
        },
        {
            0x830C3DDD544C2BB2ULL, 0x98B9AF0967A8E9A1ULL, 0x4330A348D3BE787DULL, 0xC8E2E8D0F4D5E60DULL, 
            0xBBFD00DCF169B9D5ULL, 0x4A5F0E8F05EEBCCDULL, 0xD7709777873C3D3FULL, 0x2F240B227727E83FULL, 
            0x1521240E2A69B86AULL, 0xFB9267837283B167ULL, 0x2C7ABAC536CC984BULL, 0xB3544AE791B8AEA6ULL, 
            0x4B23BB5BAB633E6AULL, 0xCBB1A17B26402524ULL, 0x7D9049EE6AB8CFA0ULL, 0x1781D59683B7A4B4ULL, 
            0xFC67A98C828A33FDULL, 0xF6DEE4F823BB1EECULL, 0xE1AB96DFEBB572E0ULL, 0xBE75F1B563BE4412ULL, 
            0xA8C67028F423D7C3ULL, 0x305733935A2C25B7ULL, 0x2E3A94C4CECF7612ULL, 0x36688E592264F250ULL, 
            0xE0049DD95201A8AAULL, 0xEC51217CCED43A9FULL, 0xBBF3F3231E0AD8FCULL, 0xCDC6614579071CA8ULL, 
            0x290433D11A1AA386ULL, 0x5C41C0D95B2D5FA0ULL, 0x53CDFF20C8DEBDD3ULL, 0x88DAF9FEB227730EULL
        },
        {
            0xF66CE73010092CA9ULL, 0x71EF688C472F706EULL, 0x896F96B7671BA7DFULL, 0xB9797EF2226E0E2BULL, 
            0x04FBCA75A9E0969DULL, 0xF1043913F8CC3EF4ULL, 0x10015E6FD77F6C68ULL, 0x8B884D06600894CAULL, 
            0x973873F0D012ED60ULL, 0x485E7283BFE39E32ULL, 0xE22EA1ECCBE715BEULL, 0x8B2E6FE7FD89416CULL, 
            0x1F3BF43A6598BD04ULL, 0xD7554E91940D8B44ULL, 0x991D7B114D1E3C22ULL, 0x68D058C3F93F76EAULL, 
            0xBBB4425C04EA2DE2ULL, 0x41F3BE8D99E2AF66ULL, 0x735D4C0361E157DAULL, 0x367499D69259B5C5ULL, 
            0xC17A02B635506879ULL, 0x0B71D4DFD2D2AE88ULL, 0x29A366A704D1A61EULL, 0x3561972150B700F2ULL, 
            0x7E82F2470359E700ULL, 0xF372C89C098A03BCULL, 0xFCECD5FCD98F9892ULL, 0x78CA7D9268AA0D4AULL, 
            0xDE43415F10761100ULL, 0x6CEFB9BAE2853142ULL, 0xA7072CC6091393E7ULL, 0x6A0CE76C1CF5FD84ULL
        },
        {
            0xABFD089CE49CBCBDULL, 0x3F01CDA1AD7BDC39ULL, 0x6B2B418717C19A39ULL, 0xE8A55DE56F8BB762ULL, 
            0x2BE71C3F4447D36DULL, 0x40B3384EFDCD9218ULL, 0x6C24116815279E70ULL, 0x9A6F744AAADF0355ULL, 
            0x41602516462389DBULL, 0x18EBADAE2E8360F4ULL, 0x61F015086865A5D9ULL, 0xD990CEE1959468BDULL, 
            0xE904823B41B59EEEULL, 0x2C6FB6D2CA6058F6ULL, 0xA7D1B7B909CE2CC4ULL, 0x5868A90A387378EAULL, 
            0xE6BA6EF638653C44ULL, 0x8E4AF397CE4265FFULL, 0x057E9A3984C5085BULL, 0x698B9683B37C68A7ULL, 
            0xBD8A478065A050E2ULL, 0x4D6DB3FEF8DF6AC6ULL, 0xA1A427B2420B656CULL, 0x3376AE4711AEA888ULL, 
            0x179B838000BFBCEDULL, 0x9F87C3176AFA0A3DULL, 0xA1C0088B2B2756CFULL, 0xBA86DA655BCDADCDULL, 
            0x05EC30660D116DA5ULL, 0x241912738B37843AULL, 0x0F3C9BEB87EB1794ULL, 0x3BB03D6D80EEA830ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseGConstants = {
    0x704F6F0EF2EE2A8EULL,
    0x192C2D998D128505ULL,
    0x3DAA75081DD0B4CFULL,
    0x704F6F0EF2EE2A8EULL,
    0x192C2D998D128505ULL,
    0x3DAA75081DD0B4CFULL,
    0xD5504CCB4AD5D381ULL,
    0x05B4E51827710506ULL,
    0x80,
    0x5C,
    0x7E,
    0xA0,
    0xA1,
    0x28,
    0x7C,
    0xE2
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseHSalts = {
    {
        {
            0x4A6A9D96DECA31B9ULL, 0x1BD3F41F39CB563DULL, 0x2AA5EAD6A8F38332ULL, 0x3EE0389ADEBFE3ACULL, 
            0x011FAC52289AAEE4ULL, 0x6E07D1A3E8648919ULL, 0xB284F632F637BBE6ULL, 0xCF0C95CFA55421BFULL, 
            0x3D45E2CD14EE5037ULL, 0x7B4DB1CB164F11DCULL, 0xD22430583C6781EFULL, 0xF8D46CC2140A5FE2ULL, 
            0x651BAE28DB67D0EBULL, 0x1A23D47817DB175EULL, 0x566002FE506C25EFULL, 0xD550AE246CFF0954ULL, 
            0x00A97913CF86FDC9ULL, 0xD2B9D84A5C6312EDULL, 0xBA16975814E51D42ULL, 0xE4B5FE8DB1FA190BULL, 
            0xDAC7B014B9314F84ULL, 0xB5864F300EA00921ULL, 0xF8EACF8A0FE8160CULL, 0xAC4B64F30B2E90A4ULL, 
            0x5DD737563F7F016EULL, 0xBE73C622FDF2092FULL, 0x077B69AB219275DCULL, 0xC9D2016C3DA436F5ULL, 
            0x989ADB73C7703B03ULL, 0x5A9163ED00AAC7E5ULL, 0x517248A315F23C82ULL, 0x2E625053EDDC6DD2ULL
        },
        {
            0xA6C8438E360D44CEULL, 0x76572212CE000EF1ULL, 0x14CEADDE54EFEF98ULL, 0x2E7523D3EFF292FDULL, 
            0xF4D3F00C7E688998ULL, 0x1096ADF043CEE157ULL, 0xE29CE52897C672E5ULL, 0x50B364F451CCA142ULL, 
            0xA71E49C589719697ULL, 0x817C81AFACBDAC10ULL, 0x0219707C03CB8FACULL, 0x53B0712B9A6DDE8CULL, 
            0xBDB26320A902AB53ULL, 0x5D15168A23B82FC2ULL, 0x714197DA1CBC8C4EULL, 0x2F4B01849B90BFD3ULL, 
            0x849A68E5DF2DAACAULL, 0x6F61B67A57742F23ULL, 0xEF175C84D9110318ULL, 0x152DA119243C0F4CULL, 
            0xD14B903A72EA2B60ULL, 0x596FB00415D90BA7ULL, 0x4FAA4B8E7427DE66ULL, 0xA026452593DF7C2FULL, 
            0x92E0BBF6CB1EAFF6ULL, 0x169AEAF7E10E1A66ULL, 0x870CF13DEA4CB1D1ULL, 0x914CD8787A03220FULL, 
            0xA9B4315941E96261ULL, 0x18DD43678936EA29ULL, 0x0746C78E4B71BC9EULL, 0xF4D8B949534643FBULL
        },
        {
            0x01F9C21E1F36F6C2ULL, 0x6F6943136CB2571CULL, 0x9CC256F7E3D64331ULL, 0x6E7E47DD71EA7955ULL, 
            0xCB7D0E4D2D97BC1CULL, 0xB1E29B55F02CCF18ULL, 0x57AAE059AC32E662ULL, 0xF1E05B8F24887CAAULL, 
            0xB3303791786AFEB9ULL, 0x873B6A3B77146A2DULL, 0xA6D84FB0C1E20692ULL, 0xE05E7E83BC5F4A98ULL, 
            0x5B0BCCD710C02A5CULL, 0xECF291BBC0EA298CULL, 0x38D4A690C1BD0949ULL, 0x668F43AA27FC95FBULL, 
            0xDAC7EF75889C858BULL, 0x552DF960E85DA048ULL, 0xFE79DE78148A4B2DULL, 0x9947141EB49D03F7ULL, 
            0x9C1493082F2BBBA1ULL, 0x47EE5E3F63A8D562ULL, 0xEA652C9AC6A5EEB5ULL, 0x49CD3AF0C477AE18ULL, 
            0xE6A322EB2525574BULL, 0xB908A6AB512A85CCULL, 0x4FE452D489059249ULL, 0x48C28FA2BD5D0198ULL, 
            0x94E7B4E9EE1ED7B8ULL, 0x0FD6327F3EF3D759ULL, 0xF121BC48F9469BC2ULL, 0x82F495288BEC1E91ULL
        },
        {
            0x94A2BC94D41CD0C1ULL, 0xD6052D640F70F7C8ULL, 0x531B6837291261FCULL, 0xA77025F22D47E69BULL, 
            0x5F006F8BC2C547FCULL, 0x8A81F43B812A3F19ULL, 0x499C558DFF527491ULL, 0x2315B671EE16AB12ULL, 
            0x887D1EA8D93DCCA5ULL, 0x41E972EF738EB7DFULL, 0x3F27A9379892D728ULL, 0x61E2CC0E0DB0CF18ULL, 
            0x57114507DEFBBCC4ULL, 0xBBF7899D3A78557EULL, 0x2E9DA40F20A000D9ULL, 0xECF811D523B90A6FULL, 
            0x8FDB0368CBEAE7C1ULL, 0xDF94AC75AD952BC8ULL, 0x986D6183FC9A2A05ULL, 0xED101D68E59A7F15ULL, 
            0xA81B6FC472DF32A0ULL, 0xDE9D20E14768A956ULL, 0x1A77D52E850D7297ULL, 0xC6AA7F639B06EB28ULL, 
            0xDC06BEFF7F7B6A15ULL, 0x760900B96FFD35F4ULL, 0xD07DA24257C92F4EULL, 0x9D14873DC16086ADULL, 
            0x3BA9C0DA3F47EFBEULL, 0xCC1B9B7DB4B14249ULL, 0xE445762003877B75ULL, 0x73CCB167613CBDEAULL
        },
        {
            0x5E64098245A27D32ULL, 0x91B459A756FD6480ULL, 0x95BA83549B9F5853ULL, 0xCBFFA6C80EB1A7F7ULL, 
            0x41BC03915063709BULL, 0x9E36B7EAAE58CAAEULL, 0x143E75D4758A2283ULL, 0xEA2E187D911A966FULL, 
            0xF1E4611442D396D5ULL, 0xBB60FF2494E45473ULL, 0xBE3DA704D1984411ULL, 0x09A2DE1E92E3C6F4ULL, 
            0xEA0B7A45B9D79D8EULL, 0xFAA7172ECF686D56ULL, 0x3E63A3AD8361EDB8ULL, 0xEE634A1679D82DA8ULL, 
            0x740E72EC4A060256ULL, 0x68CCBF7F09348CF8ULL, 0x966EA5CBD08C2668ULL, 0x5C21B727A11EC9BAULL, 
            0xFC39A7AD5A5BA2B6ULL, 0x0E9094C8211C8644ULL, 0x43D8B157754DD090ULL, 0x20AA057DF81EFB01ULL, 
            0xC3F52391B3F17C0EULL, 0x509C98BDEE514E62ULL, 0x615862DF8E59FE13ULL, 0xDD389F2EC9A07C40ULL, 
            0x801B08C594428C9CULL, 0xADCC93CAC6AF6A59ULL, 0x90DB841E761DAE31ULL, 0xDFFC987973C03137ULL
        },
        {
            0x1A354B28819C2121ULL, 0xDE2C52C4993D2143ULL, 0x854EFF298A31670FULL, 0xEE106EFE171CA4F9ULL, 
            0x6D0087D1F1382892ULL, 0x0FE86C09E12E1BA1ULL, 0xDFE52518E2272DFDULL, 0x716F5FCE307D806AULL, 
            0x400F2919FF105130ULL, 0xE752BB18B34B03A6ULL, 0xA1406B5316368B2BULL, 0xFDA6B52CD0AA8404ULL, 
            0x64E470D660632768ULL, 0x101D388AB97428A9ULL, 0xCA779A69D8EA87E5ULL, 0xD5CBA789A6AB6F70ULL, 
            0x8D15778394E4B60CULL, 0x381DB295557C1778ULL, 0xA96743E290595146ULL, 0x9BE5195020C3074EULL, 
            0x39FEF08A1281D04CULL, 0x370ACC11ABEF9B54ULL, 0x845F435FDA3D9CE8ULL, 0xD1C6AAAB0057B8A6ULL, 
            0xA9450B8E2381F6A3ULL, 0x52091D1238C7042AULL, 0xD1E7269746F1B091ULL, 0x9D5987BCEB982673ULL, 
            0xEC61E1A3A7A0D4B4ULL, 0x72B2CAE88BE7533AULL, 0x116672F105406768ULL, 0xE559C88FE7AA8A55ULL
        }
    },
    {
        {
            0x8E79F78787DFAF13ULL, 0xE9901F74B4973DF2ULL, 0x4902D3E1DE01E9BAULL, 0xE752CFBA31398F86ULL, 
            0x5F9E0B173DF71C68ULL, 0x38D4F562CB43A046ULL, 0x5C558DAC47B21835ULL, 0x4E45CE324DD98D38ULL, 
            0xFB9FCCBB7D3BC05BULL, 0xCE356831E23DF046ULL, 0x21F23455143AFBAAULL, 0x71DE987AE7010347ULL, 
            0x0BB50939451C7932ULL, 0xD819B0AF485C70B5ULL, 0xF613B717CD534F25ULL, 0xDAFCB6079FF8FF66ULL, 
            0x07AD6D942D504F9BULL, 0xAD3114982256BDB5ULL, 0xBBD7C35E2F4EDA0FULL, 0xCB957DE84B5536A2ULL, 
            0x7E22F00A758974C2ULL, 0x5B2CCDAC3E095C3CULL, 0x5BDA4E33FD4D3A5FULL, 0x9DDC60C97E97653BULL, 
            0x989AAD811A89D20FULL, 0x1E38763C15804692ULL, 0x8AED8C442E5BDE92ULL, 0x6C3BF887F59A2E3BULL, 
            0xAAB211126F00E0D1ULL, 0xB0D886D77A4B719AULL, 0x416DEF7F51658D43ULL, 0xEF6D2E752431C7D7ULL
        },
        {
            0xBE06045B9D899DF0ULL, 0x2996770E2C0A9450ULL, 0xB565A040EE974B94ULL, 0xDC4EA0698D8E4F74ULL, 
            0xC5CC096F0B2F766AULL, 0xF771397DA3DAE958ULL, 0x02F2E0C95D4BD122ULL, 0xAD4F5FD30B786A24ULL, 
            0x300980D767EF5836ULL, 0x74FDE6409F2BFA55ULL, 0xCC57D461D5B06644ULL, 0xEAD367FCF5BC965DULL, 
            0x794007EBD14BF64CULL, 0xF16D4A5B35FD14ADULL, 0x7D7AEFD853075D56ULL, 0x562E0FE9D9B54A63ULL, 
            0x1FF2FB31BFEDE88EULL, 0xFE1D0136DE076FB6ULL, 0x801DCA41D8B09E8FULL, 0xAD733B0110226F21ULL, 
            0xA8A4C4B890B19C87ULL, 0xA25711302BD9024DULL, 0xD41CA60EA79D5D63ULL, 0x7D5F9C4E5BA2CF9BULL, 
            0x3961B13D1D537D91ULL, 0xEF1FD5B462155A18ULL, 0x740D90023C03B96DULL, 0x20F31C5BB8E300D5ULL, 
            0xBA4383FF19B04F4AULL, 0x66F54E0A1C54D890ULL, 0xFA33FFEA38371BDAULL, 0x79BE26AD2207699EULL
        },
        {
            0x1D6FEEF2CF01384DULL, 0x70DFB72508C3254FULL, 0xFD146EB2CD2433E5ULL, 0xB2F450E278117C27ULL, 
            0x637507C42D7E0897ULL, 0x4231C5ED0288AA27ULL, 0xF10901CB94712FBFULL, 0x44C8BE1A00A74537ULL, 
            0xAF98A43D5392B75FULL, 0x0B8388B39709111EULL, 0xF83F469FEE0B1966ULL, 0xF73DBA2A044F83E3ULL, 
            0xB620ABC11D7CBC01ULL, 0x2016C7B5BB99B61EULL, 0xDD3AADD268BD1095ULL, 0x80B4C32459C26DFAULL, 
            0x57159C326D50AAFDULL, 0x4225AD38AEB390B4ULL, 0xCE9CB26D06A67BA1ULL, 0x1FDBE8B7E1D84F7CULL, 
            0xA1B812BA9D8A595BULL, 0x9C7EE7FB3514F255ULL, 0x6C972537D31AAF02ULL, 0x2BC59C0DB2A54E3DULL, 
            0x40BD19A4C27015D0ULL, 0xED8A9E2FD3D8C095ULL, 0x54C205388EDA6937ULL, 0xD7B0D3E6B2AA3AF2ULL, 
            0xFB9E363586039FF5ULL, 0xE8B957F0D0EB8AA4ULL, 0x8694F53A73E4DC80ULL, 0xFEF3DEE7E90A1D09ULL
        },
        {
            0xDCAA9BF4CB4214DCULL, 0x0B69EEC657A6FC4CULL, 0x3EB2BD2290A3722BULL, 0xF2A59B1796674072ULL, 
            0xBA70C11349194EF3ULL, 0x46F9FA5FFFA0E883ULL, 0x716F7E04440AAAF7ULL, 0x5BB2E06F233E06B2ULL, 
            0xD1B2049297A279BEULL, 0x72445154B81E95A3ULL, 0x959B53AFC2843565ULL, 0x3A900467BAEEE5BDULL, 
            0x8FDFBF07C3213BA7ULL, 0x209DBBA2F142A143ULL, 0xEFEFB09F7458DBD7ULL, 0x14AF8126518171D2ULL, 
            0xFC390D27DA14A76AULL, 0x46E9436F766664D0ULL, 0x0847105640466654ULL, 0x02BDD796798FB66FULL, 
            0xD3E72E9F42D64E17ULL, 0x8B4FB26F0F40E81AULL, 0x86E44570D6687B12ULL, 0xC559E7D4AD89E37FULL, 
            0xEE97816E6C964D0BULL, 0xFC33BE3859C14F4AULL, 0x115A4E948456ABC8ULL, 0x2BFF04DE72EE04CCULL, 
            0x1386F4E6952C9579ULL, 0x5BDD33CA4727E6C5ULL, 0x5A18BE6FE768069CULL, 0xF57D0C469920A599ULL
        },
        {
            0x135BD384042E2E32ULL, 0x2F7F65A8A1547FACULL, 0x5B0817D5A4BD508AULL, 0x1D060ADB961E9CFAULL, 
            0x8B718833B4A87C37ULL, 0xC6ED60A5B415A1B3ULL, 0xCF3A1150CBFFEA7BULL, 0xF09A3509CAE42328ULL, 
            0x4E53F90C74096830ULL, 0x1BC67EFA4DFE5170ULL, 0x9A173E09057EE54CULL, 0x172B4682F36533C8ULL, 
            0x8FA96195218D9A5AULL, 0x96475BFB4A0ECCD1ULL, 0x85998AC235C34D03ULL, 0x22A044330590F988ULL, 
            0x460B646F3C4B9CE4ULL, 0xF5571330A7D80B2FULL, 0x81427BE9F11B9315ULL, 0xEF241A5998D3F918ULL, 
            0xB187854A65BC10E8ULL, 0xD5EA6003ED0DEF81ULL, 0x0D4A44EB7B28C0BEULL, 0xC4CCC165EB03F732ULL, 
            0xA5164802E90C08A4ULL, 0x558EE3AFF6AF7E24ULL, 0xCD7D6815F70A5B1AULL, 0x799F7E3DF08EFEF1ULL, 
            0x9030D4D03E6B2E22ULL, 0x301AFB48127A8999ULL, 0xDDEEA51A6C04CF80ULL, 0xF595EEF442065557ULL
        },
        {
            0xD1BBA863C58967E3ULL, 0xDA70722E9F8FC03CULL, 0x2E33B324425EB55FULL, 0xB97210F4C7DFA0C1ULL, 
            0xA4D0FC6BA756F555ULL, 0xB141960C5C4C12DCULL, 0xBE19139947257BCFULL, 0x5C60CE19C3459B4CULL, 
            0xBCBD3294692B5492ULL, 0x50A82A393BF5DF6EULL, 0xB2A29C7ED5E4E362ULL, 0xE12F55F8A63E2468ULL, 
            0xA9B87363A344A390ULL, 0x880158BDE82EFA93ULL, 0x33C26AE5927CAC9DULL, 0x96156CC9E76DF981ULL, 
            0xA6335C746CDE8CCCULL, 0xF9E00DA2027DA626ULL, 0x4AA5AA5D1B6E481CULL, 0xFC48FBB115FA6A4AULL, 
            0x07669E3E05680101ULL, 0x4A2669480D078E3FULL, 0xF89E1277427BE185ULL, 0x5F9475E971FAB01EULL, 
            0xCF74474DA8A7D4BBULL, 0xC72D27544BC7DC00ULL, 0x35D96683F728C1E3ULL, 0x51036F8F9C380423ULL, 
            0x0A7B39C5184F5EE3ULL, 0x490B4B85E8D6697AULL, 0x062019CD5B0C1D87ULL, 0x6D347F083E41E998ULL
        }
    },
    {
        {
            0xF5F96C8F07603E4BULL, 0x861CD3246049D114ULL, 0xEEC4D6A90C3163E2ULL, 0xA6155B5344B49F68ULL, 
            0xFA88E672319F3D9FULL, 0xD76D2E91EA3E7D40ULL, 0xCA722096D131712CULL, 0x26936FA017300F82ULL, 
            0xC68D423BF8F3686FULL, 0xAC8E04E6CADAD3E4ULL, 0xD8B4E353662A2A79ULL, 0xCAC5FCEAF557E3BBULL, 
            0x7B89BF34611754D6ULL, 0xAFB781629924D1ACULL, 0xC3B26E66983BA525ULL, 0xBC1DC7E428A7A917ULL, 
            0x91E73CA6686FEC8BULL, 0xF481E3D2FE988178ULL, 0xF3A740963C7AD3A6ULL, 0xDAFB585572DE62F2ULL, 
            0x5A5931F9F1BFD832ULL, 0x7D6C7476638ADEACULL, 0x4259B18ADE149F82ULL, 0x6B73CBE671C1E9D8ULL, 
            0x16903DCE683EBC50ULL, 0x948CED8E17889948ULL, 0xD332E08875924751ULL, 0xC4BAB212A1159FAFULL, 
            0x39145F6A7B62FEA3ULL, 0xB2E1063D55850069ULL, 0x69C29F175ADB13BCULL, 0x768A39EFA36DE197ULL
        },
        {
            0x360B0F3C5328DB17ULL, 0x4752AE61EDD5D727ULL, 0x51E100A7AB56FE06ULL, 0x376038855A3F7A39ULL, 
            0x846A9DC455ED0327ULL, 0x7845CCD6AE01C4EAULL, 0x22BF49EC4BBF9784ULL, 0x39DEF78B5940F939ULL, 
            0x68A1C432DBA1DA20ULL, 0x89B510FEB8C2C1D1ULL, 0x2F445799F44427F8ULL, 0xA6363466BAE8F793ULL, 
            0xAFEDF579856B50D1ULL, 0xF06926A0CC1059D8ULL, 0xF0925DF401479B9EULL, 0x857B8320A641FE1FULL, 
            0x46E8FC21F2699019ULL, 0x0B825E17A134632DULL, 0x6C10DA8CADAA2D0CULL, 0x128EF9EAA5C8954AULL, 
            0x1609731E10761E68ULL, 0xFD51FF59DDA10E9DULL, 0xB6AB1C853511ECC6ULL, 0xB54A8EC276C80C63ULL, 
            0x8253B7466CBEBAB0ULL, 0xA4EC0CB594DC72C4ULL, 0xDD2A123CBD4C3A4EULL, 0x5474E1F68D0F6A9CULL, 
            0xB8AD8698EDBC7E8AULL, 0x88F4231C4A1C8139ULL, 0x8DCC82E20FA9BBA7ULL, 0xDDF16F8263527A14ULL
        },
        {
            0x311BFE72FD2D95D7ULL, 0x5346A01B02295C4FULL, 0x724B6AC69744B801ULL, 0x0BE233E6E710C68CULL, 
            0xC7B930FB87C70507ULL, 0xCB2BBC1D3393D464ULL, 0xFB485A8E7C0E7FBBULL, 0xD6A3817C03525D92ULL, 
            0x251F5D82064CE0C7ULL, 0x6EEB70CE65CCBDE3ULL, 0xCE989448CF2696A5ULL, 0xDCBBBC8E6A5335C3ULL, 
            0x965A30BEF4A5929CULL, 0x99103A74F488B4DBULL, 0x55CEC64E212DDE8CULL, 0x9CAEB73216C44F92ULL, 
            0x61E0519F6DD7D64CULL, 0x9CB2132F1703577EULL, 0x4906F579F295AA6BULL, 0x2F66166209DB5574ULL, 
            0x5DF48B56AFC7D57DULL, 0xD7439F89C3FAC33BULL, 0x2FC94732DE8BC136ULL, 0x0A3255DAD30A1BDEULL, 
            0x79D0510069091147ULL, 0xC5AD16A4F25A32CDULL, 0x594017F8C3E74C10ULL, 0x9E58F822D3C1AE9FULL, 
            0xF5502977FA8F880FULL, 0xF5E0799AB72B38BBULL, 0x42D959183A1BEEAAULL, 0x8505BC8150F25420ULL
        },
        {
            0x68D33D54FC5A09B6ULL, 0xF778D4699A8D6713ULL, 0x38235E6B33C34167ULL, 0x4A7BB41D3B2B5170ULL, 
            0xD640D3AE4DD5A5D5ULL, 0x95950959432CD842ULL, 0x92DCF121759C776FULL, 0x88EF638DA5247C38ULL, 
            0x4E9A2CD9C9D219EBULL, 0xB36124B22BC9E13FULL, 0x0FAC1406B772A698ULL, 0x300C3E018B31EF8EULL, 
            0xA06AC447DDE73AF9ULL, 0xD8DBF01656867388ULL, 0x6BD8DCF43EA0A593ULL, 0x2146447B7F46321FULL, 
            0xCB6D23447E804AF2ULL, 0x21AF4BDC06B59278ULL, 0x0375EC066AC442ECULL, 0x7BFED3BBDB23D35BULL, 
            0x88B9B057C8A55133ULL, 0xCEAC391595D81085ULL, 0x0622144A16FE6CFFULL, 0xD3ECFD9DFC9017EDULL, 
            0xDAC287B840ACA587ULL, 0x7D7860863000D0E4ULL, 0x6FA97F9CED6FC0EBULL, 0xFA280B35A7E4EC91ULL, 
            0x774F12468A081E1EULL, 0xA221666B91B76C88ULL, 0xCA69F7420AE69DB0ULL, 0x3A9899D373B386A7ULL
        },
        {
            0x3E50A39F8904F4D1ULL, 0xFBB52F8569BEC5A0ULL, 0xFBEA6A2E597479ADULL, 0x5C9E244DC41FF6C4ULL, 
            0xCF584F361E8C211EULL, 0xB2178E81BFAB0CCBULL, 0xB241CC2BF162B86EULL, 0x2BA03961626B614AULL, 
            0x582E0117156287B8ULL, 0x19A4EBCAEAAA4A99ULL, 0xF5D2D69E5EF97D82ULL, 0xE7DEF2F896DEE2BEULL, 
            0x575990F647A25A57ULL, 0xD24FD58D31C65122ULL, 0x4826D71ECEF83C2FULL, 0xE8FF9043D3446E2DULL, 
            0x8C737658662049E3ULL, 0x55A1D5FED178DAC5ULL, 0xC7D0B0539BF8AE25ULL, 0xD095793E0C7996B8ULL, 
            0xC885B3FE63CDADF8ULL, 0x32DE3E24004169A3ULL, 0xB593584CCAF3C90EULL, 0x439915B3C32A480EULL, 
            0x79FD5924791F3C5FULL, 0xA32F62700774F212ULL, 0xAC05DED1D10EDA22ULL, 0xA2DD46BC874DFE06ULL, 
            0x803367E299150532ULL, 0x1A253CFE565675CAULL, 0x27F19626C5979BD4ULL, 0xBC458293460FBF99ULL
        },
        {
            0x0A134FFD5D97DC61ULL, 0x1A2AB2C2CCC565A6ULL, 0xB24F161B2F2F0FB3ULL, 0x5E195A053D98685DULL, 
            0xA1C7B40DA51D4855ULL, 0x4FE16E7B7D578E68ULL, 0x0B1BD1388C4A5264ULL, 0xD92F781131A860BBULL, 
            0x6FB715B68B0026ADULL, 0x1510D26CAAC6975EULL, 0xA11F3372E42A8492ULL, 0x09AA82E0A153BB5DULL, 
            0xF55834E30265BE43ULL, 0x2A5A8DD4664C89E9ULL, 0x4C768EC6E6361DDFULL, 0x9D77793DB717DCC4ULL, 
            0xA03F131813D99EE3ULL, 0xF725C5AD68D8F846ULL, 0x1B1D49B85D460C8DULL, 0xC5401A4EB39869EAULL, 
            0xAA0F214315AA645AULL, 0x15FE1EBFCAC2871EULL, 0xE5259B727F76EEE1ULL, 0xDC9E5FEFCE8972FCULL, 
            0x711E20ABBF17C6F4ULL, 0x9772390DC15A8390ULL, 0x9000CE2882C869F4ULL, 0xF2AA42592FE11C31ULL, 
            0xFBC9EBE274757D4FULL, 0x3C8F6BC657AFA0F3ULL, 0xF0E997783B9014BAULL, 0x508BA8889D8F7265ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseHConstants = {
    0xA0FCEAA1DCA03B5EULL,
    0x4514FBA745603B2EULL,
    0xF01EC10EBBBF8615ULL,
    0xA0FCEAA1DCA03B5EULL,
    0x4514FBA745603B2EULL,
    0xF01EC10EBBBF8615ULL,
    0x02CE8AA7B7665512ULL,
    0x84B9833F67718D80ULL,
    0x48,
    0x67,
    0x18,
    0x0D,
    0xA7,
    0x4C,
    0x4D,
    0x50
};

