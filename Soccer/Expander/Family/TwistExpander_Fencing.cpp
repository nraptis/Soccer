#include "TwistExpander_Fencing.hpp"
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

TwistExpander_Fencing::TwistExpander_Fencing()
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

void TwistExpander_Fencing::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xE51E7AC7A915FA36ULL; std::uint64_t aIngress = 0xA9B685D68AB29711ULL; std::uint64_t aCarry = 0xA83A94CBC4E80D23ULL;

    std::uint64_t aWandererA = 0xA0805C50CAB3D5D4ULL; std::uint64_t aWandererB = 0xA6A4B27EAF1394BDULL; std::uint64_t aWandererC = 0xD6936C0D98DC7464ULL; std::uint64_t aWandererD = 0x95A257DE0879F794ULL;
    std::uint64_t aWandererE = 0xCE02F705B03A06DBULL; std::uint64_t aWandererF = 0xCF318EC1740C492AULL; std::uint64_t aWandererG = 0x98D22BD9E2556A1CULL; std::uint64_t aWandererH = 0xA63B3FD309E03599ULL;
    std::uint64_t aWandererI = 0xCB4E6518ED2D60BAULL; std::uint64_t aWandererJ = 0xFC110685F31972E3ULL; std::uint64_t aWandererK = 0xAB312565D558A5BCULL;

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
        aPrevious = 10001497454089175227U;
        aCarry = 11675927992127775908U;
        aWandererA = 13105602439580006352U;
        aWandererB = 16451379580949832920U;
        aWandererC = 15968746114005732184U;
        aWandererD = 11074631549388000048U;
        aWandererE = 17257511897229928646U;
        aWandererF = 12188692128123806049U;
        aWandererG = 16170262193543353704U;
        aWandererH = 13113866219000760638U;
        aWandererI = 17566941185385110582U;
        aWandererJ = 15558333328338928159U;
        aWandererK = 14463181384217490544U;
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
    TwistExpander_Fencing_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Fencing::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xD894E5A98984778AULL; std::uint64_t aIngress = 0x9829DB751135EABCULL; std::uint64_t aCarry = 0xC225C5B092581BFCULL;

    std::uint64_t aWandererA = 0xC32F8407ABB70591ULL; std::uint64_t aWandererB = 0xB6F0BF3A0E69BB65ULL; std::uint64_t aWandererC = 0x8978DCD7A2A77BA1ULL; std::uint64_t aWandererD = 0x99ADC435817179F5ULL;
    std::uint64_t aWandererE = 0x9D4C7A095591623BULL; std::uint64_t aWandererF = 0xB3517F0E7FBDD869ULL; std::uint64_t aWandererG = 0xA1862B162D2AC2A5ULL; std::uint64_t aWandererH = 0xCD5FC71CC31D007AULL;
    std::uint64_t aWandererI = 0xB8270AF7880136F7ULL; std::uint64_t aWandererJ = 0xCF91393A5D1AC894ULL; std::uint64_t aWandererK = 0xD0F95E2E39002985ULL;

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
        aPrevious = 10191863756491979854U;
        aCarry = 9264708256972387524U;
        aWandererA = 11240769715016384387U;
        aWandererB = 16694944808379335336U;
        aWandererC = 16785178742443187522U;
        aWandererD = 10043919386637801195U;
        aWandererE = 14177775878088414534U;
        aWandererF = 9502489822994299459U;
        aWandererG = 12016029762908484619U;
        aWandererH = 10637949447124547994U;
        aWandererI = 10475834534027434348U;
        aWandererJ = 14191234761438544690U;
        aWandererK = 16130916561272781208U;
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
    TwistExpander_Fencing_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Fencing::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFDE8FDAE00D16602ULL;
    std::uint64_t aIngress = 0xB30E4CF6761EE98CULL;
    std::uint64_t aCarry = 0x9A32F7083ABABD03ULL;

    std::uint64_t aWandererA = 0xE5527867C9A73652ULL;
    std::uint64_t aWandererB = 0xF9075AC49020EB3DULL;
    std::uint64_t aWandererC = 0xF34377375A931066ULL;
    std::uint64_t aWandererD = 0x9CD24EFFBE2AB072ULL;
    std::uint64_t aWandererE = 0x8421041610126747ULL;
    std::uint64_t aWandererF = 0x9985CF2463CC846EULL;
    std::uint64_t aWandererG = 0xB2A0E051763FFD1CULL;
    std::uint64_t aWandererH = 0xED5D90629C887DACULL;
    std::uint64_t aWandererI = 0xB7632E1D751921FAULL;
    std::uint64_t aWandererJ = 0x92545A5D5B2EC6F0ULL;
    std::uint64_t aWandererK = 0xADA83CDB20C39D53ULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD, 2);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC, 3);
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA, 4);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB, 5);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD, 6);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC, 7);
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneH);
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
    TwistExpander_Fencing_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Fencing_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Fencing::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Fencing::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCD3A6F8D8AD60B77ULL; std::uint64_t aIngress = 0x9351382C9A90F337ULL; std::uint64_t aCarry = 0xCFB4C1609CB83E79ULL;

    std::uint64_t aWandererA = 0xECEBAC33E47BA92CULL; std::uint64_t aWandererB = 0xA3A5322EF54C3901ULL; std::uint64_t aWandererC = 0xF9E60F93928B5E75ULL; std::uint64_t aWandererD = 0xBCB09FF8DA4C5A34ULL;
    std::uint64_t aWandererE = 0xD8F26175CADE056BULL; std::uint64_t aWandererF = 0xA143639B378FE452ULL; std::uint64_t aWandererG = 0xC4A2D0840EB02E18ULL; std::uint64_t aWandererH = 0x9A1D7B19EFEE1640ULL;
    std::uint64_t aWandererI = 0xCD1AA95B548F6B9DULL; std::uint64_t aWandererJ = 0xCCCFC161646AF592ULL; std::uint64_t aWandererK = 0xE63DAB32820817AEULL;

    // [seed]
    {
        aPrevious = 11921439618041775404U;
        aCarry = 11102729912897273197U;
        aWandererA = 10963703951216049229U;
        aWandererB = 10310657349879000033U;
        aWandererC = 11093779697504973477U;
        aWandererD = 13430568488662732727U;
        aWandererE = 9280379012320656314U;
        aWandererF = 17323995604559991506U;
        aWandererG = 15192895808041101008U;
        aWandererH = 9403223708408861933U;
        aWandererI = 11231558370525549661U;
        aWandererJ = 15238403727661468725U;
        aWandererK = 15847230095633681841U;
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
    TwistExpander_Fencing_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Fencing_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Fencing_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Fencing::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 1, 0 with offsets 4183U, 169U, 5009U, 5618U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4183U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 169U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5009U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5618U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 2, 1 with offsets 8063U, 381U, 6389U, 6640U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8063U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 381U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6389U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6640U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 0, 3 with offsets 5304U, 5482U, 4922U, 6864U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5304U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5482U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4922U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6864U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 3, 2 with offsets 6226U, 2691U, 5700U, 4147U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6226U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2691U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5700U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4147U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 1, 2, 0 with offsets 1486U, 259U, 80U, 770U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1486U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 259U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 80U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 770U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 3, 2, 0 with offsets 378U, 58U, 833U, 1623U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 378U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 58U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 833U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1623U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 0, 2, 1 with offsets 305U, 1558U, 1622U, 866U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 305U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1558U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1622U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 866U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 1, 3, 2 with offsets 963U, 911U, 1095U, 1566U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 963U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 911U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1095U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1566U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 649U, 681U, 1601U, 1052U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 649U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 681U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1601U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1052U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Fencing::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 3 with offsets 4658U, 1981U, 2390U, 3761U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4658U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1981U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2390U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3761U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 2, 0 with offsets 7469U, 7328U, 5954U, 6013U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7469U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7328U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5954U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6013U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 2 with offsets 7907U, 2966U, 4124U, 3172U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7907U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2966U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4124U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3172U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 0, 1 with offsets 197U, 484U, 4363U, 4231U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 197U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 484U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4363U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4231U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 625U, 7240U, 1236U, 7923U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 625U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 7240U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 1236U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 7923U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 510U, 115U, 10U, 1343U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 510U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 10U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1343U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1145U, 1640U, 298U, 1621U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1145U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1640U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 298U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1621U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 784U, 857U, 994U, 1966U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 784U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 857U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1966U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 279U, 616U, 1507U, 1192U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 279U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 616U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1507U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1192U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 3, 1 [0..<W_KEY]
        // offsets: 446U, 415U, 488U, 1591U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 446U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 415U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 488U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1591U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseASalts = {
    {
        {
            0x20D6B9833D9645A6ULL, 0xE6449EF44D9F69EFULL, 0x55D19282D556872AULL, 0xF1D65898501C71EDULL, 
            0x729E95229A656D02ULL, 0x6932716454798717ULL, 0x437848F3B7DCAC26ULL, 0x534DFC846863334FULL, 
            0xD55D465536ACCAA3ULL, 0xEF103667D4BC4C89ULL, 0x6E295FA43E522036ULL, 0x96FDEBDB8461C0BEULL, 
            0xBDF0C6316B84F77EULL, 0x3BF02AC52346C514ULL, 0xF0F6189DFBFBFAF4ULL, 0xFBE78FA917D3B891ULL, 
            0xCC639CF732483971ULL, 0xBDE9C497F78E4816ULL, 0x816F178DABCA3EA8ULL, 0xCE97B3EB33C876F0ULL, 
            0x6839C0521633C852ULL, 0xB8072ABB15051AACULL, 0x1287B0AEC1014C45ULL, 0x6A77F2D870724F66ULL, 
            0x8AE7200573F647F6ULL, 0xC76BD24064E6988AULL, 0x898FBD3BA5DB8D04ULL, 0x6EA9647B5F4E4936ULL, 
            0x2DE71E2F94C611AAULL, 0x60717B3EA5383210ULL, 0xCF4B780971766B5FULL, 0xBD58D1F7A6B002FBULL
        },
        {
            0x643265B42CE9B559ULL, 0x642C5BB9A0E64F14ULL, 0x9E089948C3891E8FULL, 0x81C3F986E599BD53ULL, 
            0x09BEC04BB26C1BF7ULL, 0x6BB0D8633471E11FULL, 0x4E73675A4924EF0FULL, 0xEE6D39ABDEB920F7ULL, 
            0x05827517244FE95FULL, 0x135B8C8385496AB6ULL, 0x107D1469D0EF3BBDULL, 0x7A6162FDB0A413BEULL, 
            0xDF63E66A716F6435ULL, 0x31345E934C680CFFULL, 0x6124276ADAF9A82FULL, 0x1A457ED6A2779B7AULL, 
            0xEB25972E4C284B2BULL, 0xA450C954293FF2E3ULL, 0xD5E7318BA589963DULL, 0xE184C08F38FA2DA5ULL, 
            0x468DD522725F6A0CULL, 0x4F34D481A54DBB48ULL, 0xE1DE57B90B374805ULL, 0x605D9FB63085434EULL, 
            0x307718E929F00453ULL, 0x54C4F960C745C7FBULL, 0x3AAEFC669F3FA8ADULL, 0xB42F6D5E2D6F6762ULL, 
            0x1FA474D5D2E82C5BULL, 0xA9C61F79152BD2FDULL, 0xDEA1B581C52CC6F3ULL, 0xF46DA1FD209AF29FULL
        },
        {
            0x00A94C39A0F58386ULL, 0xA3695CA016E10FF2ULL, 0x690741B6E6CE085CULL, 0x0F1509E9CD749FAEULL, 
            0x84CC66C367FCF84EULL, 0xF9168064DEC3EA8AULL, 0x7D29DDC095F86416ULL, 0xA5B153AF0B458AAFULL, 
            0x1389D4C2612C0B6EULL, 0x20073760D62EBC00ULL, 0x2FB3AED813FC9378ULL, 0x4CB3609B397B2A70ULL, 
            0x0CB10CBB1CD1389BULL, 0xCBBF70604ED10A54ULL, 0x09A88B8A194D829FULL, 0xBC071F4B93BC0030ULL, 
            0x6A597D0C31EA05C9ULL, 0x54F8F2B65044D523ULL, 0xC94FCEDA716BCF53ULL, 0x352691712CCAF363ULL, 
            0xAA51F2A895152FFFULL, 0xB51A066BA5C1ACB7ULL, 0xE5707BD0A3C664D6ULL, 0xFD9061492DB30773ULL, 
            0x230036BAF19EA3A2ULL, 0x4B27A4193FBEED2BULL, 0x24EC6919C9C81D03ULL, 0xFCAA50983E3806D5ULL, 
            0xA7A2CD4CE84C2DAFULL, 0x4A072D8D3CEE9EB5ULL, 0xA9F914F1DF918E12ULL, 0xFE8114F05388A682ULL
        },
        {
            0x68885E0942D0C8AAULL, 0xD66BE01C1D817FFCULL, 0x63AFD4F81675D1D7ULL, 0x3B928C119C0DC648ULL, 
            0xFF6424FB8820455EULL, 0xFBA5E0FA02BE1612ULL, 0x0A72033235D5A8DBULL, 0xBEBFAA1816292135ULL, 
            0x2BF75785642E5FBFULL, 0xAEC25ED1C13CB780ULL, 0xADA856AB38773F6FULL, 0xB5A9A2D1A61A60F8ULL, 
            0x873585FCD3E081EBULL, 0x493F0D5E6B692E83ULL, 0x9F7449134946FB58ULL, 0x3EB449CE14DE9231ULL, 
            0xA1C21D7482E430E3ULL, 0x0EEDE6B94A0A160BULL, 0x8B3243E1A3691F14ULL, 0xEF53719E2D8675E2ULL, 
            0xD2472B64AF0826E9ULL, 0x18C895B77DC9F7BAULL, 0xBEBD39E1A82451F5ULL, 0xCFE21EC400D4B75DULL, 
            0xECF1ACD5886F4FCBULL, 0xAB81EFEDA095FF2BULL, 0xD73C56C28EE5FC4EULL, 0xCC43AFC4ED4C5168ULL, 
            0xA0D7BA1813953730ULL, 0xD7F2EFD6573059A0ULL, 0x6FC000D27905CB09ULL, 0x87D752B829A8B771ULL
        },
        {
            0xC7AEAB4405F47B5EULL, 0xE8F38A61DCBC546FULL, 0xAB0783E762F2651DULL, 0x4B4B89100C1D88D3ULL, 
            0xF1C6C11F39D6C129ULL, 0xB7F6C305128F17EFULL, 0x054279AD1DE354CAULL, 0x5698135583ACF960ULL, 
            0xF81143A02FAB5989ULL, 0xA811041FA40D4FA7ULL, 0x77F5182A307DAC00ULL, 0xE66A9C698F5FB40EULL, 
            0x3DE96B450BB8D0FDULL, 0xC0CDEF1D7ED70631ULL, 0x0196CF1C4E3938EEULL, 0xB1375CF58B5E7303ULL, 
            0x1B15C3555E8E86B0ULL, 0x93977D6427E4695DULL, 0x0339C7CD10BC58CCULL, 0xFA61D0581D3B960FULL, 
            0xFCC6F21D9D3E0D23ULL, 0xAC4E1C45F66C5607ULL, 0x8E435F36AE7B8CDDULL, 0xCAB365F47862CDCBULL, 
            0xF6220010C9C44747ULL, 0x23695EC90972749BULL, 0xE535A2424D3D7300ULL, 0xEC7C7F6CA9A8BF7FULL, 
            0xAF93403C24DCA530ULL, 0xAF8B0CAAECB7A4E1ULL, 0xDE8FABDF331137E8ULL, 0xB2FB91FACB19C92DULL
        },
        {
            0x63C8356722DD1B6DULL, 0x0C7848419304F2C5ULL, 0x81CB00BC41ACF0E5ULL, 0x92BCB9359CBA9C5DULL, 
            0x348FC41CD8E61602ULL, 0x734E80EB8C2FE334ULL, 0x1990E8CBADC618CFULL, 0x464C709489FA0FE2ULL, 
            0x3574D1B00D923FB4ULL, 0x9C49014745E0ACEAULL, 0xE88AB64FB8A03EF7ULL, 0xAB58ACD52B386F52ULL, 
            0x509FF33CCC54ACC7ULL, 0x6BA7B9EE727309A6ULL, 0xCDDA9D998D73750EULL, 0x3B58F9E9B97D0D52ULL, 
            0x358CD0BFA753A773ULL, 0x238D4E903C33C290ULL, 0xCBEA2CAC9126E68CULL, 0xEB6FE89B84BB16D2ULL, 
            0x3E2534B50B700CB0ULL, 0xFC9841F47608F421ULL, 0x213DF52CE11C1361ULL, 0xF0436CAACAE89461ULL, 
            0x2AD93E1B398AE6BFULL, 0x77A938ABE5628C55ULL, 0x25DECFD493602EE1ULL, 0x76EF8DD16A5F9DCFULL, 
            0xCDC70009BC1268D5ULL, 0xD7CA6AA86D7A4A11ULL, 0xB8EFB473B2F1D0ECULL, 0x87D20570213D3E40ULL
        }
    },
    {
        {
            0x896550E8C0806190ULL, 0xED23A87C4A3183F9ULL, 0xC4BAE6905402C85EULL, 0x81E0A3AFE6FECAE8ULL, 
            0x6C2AE5DCEFD758BEULL, 0xBA6ABB2A8886185EULL, 0x0FF3DE996812B481ULL, 0xD50D87B123C340E3ULL, 
            0x19C3E27B695A4A8CULL, 0x8DB899B5C831F4DFULL, 0xC2456948B2B7A714ULL, 0xD26B25FE838A38F4ULL, 
            0xF833E372D719AED3ULL, 0x0D02AB716C09E126ULL, 0x084142571C8A6FC7ULL, 0x675EA58BC8DC31BCULL, 
            0x16F10353D6C0C483ULL, 0xFFAEE76CBA59B34EULL, 0xF131F2A69CEBC6ABULL, 0x7E32304D829C3D41ULL, 
            0xB4DC6FF4729FC8EBULL, 0x4F25F6FA90B17DE8ULL, 0x0F10766CCC5EC90DULL, 0x4CB3213D900F1AE3ULL, 
            0x8C331C00D3E741B3ULL, 0x95BB04A4601DC264ULL, 0xCFCDF3C00584BD7FULL, 0x7870A7D1DC27F64BULL, 
            0x6881759A7A9E654CULL, 0x8CB6BF95F14C4C0DULL, 0x701052A32D79C466ULL, 0x6721DCB686CA33FAULL
        },
        {
            0xC092790DEDE91260ULL, 0xD69332E93A80616EULL, 0xF932E951F49666C6ULL, 0xCFBB07CCA67C52BFULL, 
            0xED95C18C28AB04A1ULL, 0xED777A0255AD62DFULL, 0x943031B12195A883ULL, 0xE76D4346DDBDBF22ULL, 
            0xDDF7872C1C05B519ULL, 0x90DE293A8486EBD0ULL, 0x04C351045806D38EULL, 0x41C20983742D0963ULL, 
            0xF2739A26B21BFB1CULL, 0x7360F59A53B89301ULL, 0x74619187AADD1530ULL, 0x13B332D1E544AECFULL, 
            0xB295018F728F6DE3ULL, 0xB30A71CA8C255561ULL, 0xC22D0AB2F1648512ULL, 0x97C4672CEF49A7B7ULL, 
            0xEF2E9FDE41118439ULL, 0xF6E23592FE8869C8ULL, 0x832EA02C1103DD79ULL, 0x867EF3E0F77A496EULL, 
            0x3C732FC10D4D31DEULL, 0xCD0A7C97AB1E9DEEULL, 0xF54E4866F1CE8BF1ULL, 0x575E1578D6D40E99ULL, 
            0x8E07405CB21C58AFULL, 0x2FEF0B5FCD960AB5ULL, 0x60635F4C7DD36A39ULL, 0x18F26EBB81C09D0BULL
        },
        {
            0xAA196C35D8CC5B70ULL, 0x84C7E95CEF31FDFDULL, 0xA32C037B35BCCA1EULL, 0xD77FD4A4388F7F47ULL, 
            0x7BBC64B383C78ED7ULL, 0xF0D33F7F184EB746ULL, 0x0255462322AE0EECULL, 0x621574FA3B3299F0ULL, 
            0x34BEBAC31AF0BB02ULL, 0x882A0EA7913B3D5BULL, 0xF2D24EB6AA4247DBULL, 0xE12D7D5A86BF63A1ULL, 
            0x297E75C3229B2068ULL, 0xCB8118E08A3B9B9EULL, 0x634264A88DA39CD2ULL, 0x078E4154D9A9FD96ULL, 
            0x2F64CCB84DDAA5B6ULL, 0x6A259776F3FF863BULL, 0x760A8EBEB7E677E0ULL, 0xEF864D1E19452101ULL, 
            0xD7BC951E15EADBDBULL, 0xF195300D25DDBF11ULL, 0x85398CB1176F8A13ULL, 0x7E71D3622D2D4598ULL, 
            0xC6F4472EDA6E03ACULL, 0x2D42035CFA8D9FB2ULL, 0x8BAF1202BA772628ULL, 0xC314C0A04B2A4608ULL, 
            0x82A650512C438C4EULL, 0x709BFCC7BF536183ULL, 0x340475623601342EULL, 0xDF3044614FFA684CULL
        },
        {
            0x9E234C0F0FBF3E4FULL, 0x4D32AC224FE421EFULL, 0x4CAAC1E61D89C45CULL, 0xA3766BFF42BA75BDULL, 
            0xE0007ECF00468155ULL, 0xB0D33A2D85F80A96ULL, 0x99F2230A5649072DULL, 0x5718A416A9EFBB98ULL, 
            0x0EF646FB9EF8AF33ULL, 0xEDAC4A15579D6AECULL, 0x79C154C85DEF4AC7ULL, 0xC1B9161211F2A49EULL, 
            0x18021BC71EE9910BULL, 0x4D97BEEEB1613D09ULL, 0x7F29538361B640BAULL, 0xE128467D5C975604ULL, 
            0x6B7DFB360650D10BULL, 0x3DC59B90A169DB58ULL, 0xDAB3537F26DF9464ULL, 0x62403DB8FFAF37F0ULL, 
            0xBF56FD72DBD0FA29ULL, 0x5EF52A4149D1DFD8ULL, 0x9AA95C63B6B30B65ULL, 0x5F9DD0E070F3DDC9ULL, 
            0x268A30BBF8A1AACAULL, 0x51785DB20A330C29ULL, 0x448D37D95D8F6F9DULL, 0xAF0B5C1C76A004AAULL, 
            0xEEAE58B3620B5A5FULL, 0x14486ACEB553B5C5ULL, 0x81847860E58CABD8ULL, 0x435CA248077E2E4CULL
        },
        {
            0x1CDD6DD2CA02A7C6ULL, 0xEE3B829F03B61092ULL, 0x0EE5194CB4AF090DULL, 0x3EF8FFF99E99B88FULL, 
            0x7D208A5DA8BF82CFULL, 0xA86D3B8F7EBF2F75ULL, 0x429B6F3B3D9E8B71ULL, 0x4CB12AFB2FE52798ULL, 
            0xAC5AD6DD0A1C7EB5ULL, 0xA845B1FEBADA8CB9ULL, 0x0AC6A0743D52C8CEULL, 0xAB6B04E91C2718D0ULL, 
            0xCDE5AEB0A48CECCEULL, 0xA048D3E4A7371326ULL, 0xB81022BBC9F600E4ULL, 0xD7CF1FBC6C09A26BULL, 
            0x670513B5B40C014DULL, 0x976E6BDCE836FA32ULL, 0x468B7798E57EC69FULL, 0x4DC561C07D266A48ULL, 
            0xD4844327BC67D040ULL, 0xDC4DF461712AC955ULL, 0x4A8137E99DDBDB29ULL, 0xCF84DAF0BFB23BC9ULL, 
            0xD6BF91C957390F2CULL, 0xE5CA70838BE1EF71ULL, 0x53AC5D1680FD3CE3ULL, 0x1340E881E83FC8F7ULL, 
            0xAB228358F893971EULL, 0x85BD6625B93FA405ULL, 0x89AEC212677F097CULL, 0xE01C25F8BF1BBD5EULL
        },
        {
            0xAB8AAE0030BB52FAULL, 0xAAC4F736CCF2ACBFULL, 0xEC765AC412E42290ULL, 0x2A6EAA3DE983A0A0ULL, 
            0x224961D6A6D735C2ULL, 0x0CA54A5F194B0319ULL, 0x233CA3CB3145EA5CULL, 0x71C05238820AB272ULL, 
            0xAAD7AD3DB8931F0EULL, 0x268C152986462E21ULL, 0xDB1588E71FA1E9E0ULL, 0x1CA4BF118C861DF9ULL, 
            0xEA8097E9BE9AE74AULL, 0xDA3A576B20D1ADEDULL, 0x1054B0F940CEC155ULL, 0x5BC8623B6D15E334ULL, 
            0xF7DF485E9E5DF956ULL, 0x9743EE46EECA2EE4ULL, 0x52FE8A1D560161E8ULL, 0x1CEFDD5DDD9860D7ULL, 
            0x1984E77804C5AA8CULL, 0x97FB6ECB56A3E437ULL, 0x440B12E7D0CCEEFDULL, 0x402F966400DF1487ULL, 
            0x031D15EE46B1F90CULL, 0x8054BA3694F17295ULL, 0x143ABA5AA397BE6EULL, 0x274B2B2287C92783ULL, 
            0xB6E9D880560F35B8ULL, 0xE93E74702A66A942ULL, 0xF22C4E8BFF8BE673ULL, 0x0647201BBAA113ACULL
        }
    },
    {
        {
            0xF31374227730D3FCULL, 0xC186F853D2F80463ULL, 0x4AA0075D6696FD36ULL, 0xF2BE4D86D8E7ADE0ULL, 
            0x5143B2E3C87DAE55ULL, 0x80DCB2324D4F209EULL, 0xD04F0FF171FEBA6BULL, 0x9854BBB9EB90CE6DULL, 
            0x2873B292A5119D39ULL, 0x14ECF2A3A8313176ULL, 0x2E0C9FF34830521BULL, 0x8A9E497D63177BFEULL, 
            0x4091FD52FDCE5C5CULL, 0xEBB654FBA56B5B8CULL, 0x2EAA84F42978DAE1ULL, 0xE3F83A97A96D98ABULL, 
            0x513A8E526131D92FULL, 0x32CDB1F9518BDD43ULL, 0x10ABA3C5C141EEA0ULL, 0x8D3711A97CF91C28ULL, 
            0x2B7C84924FF295E2ULL, 0x7FFC619838C4036AULL, 0xA071ACD1DEA2015CULL, 0x03C839DA5CCDE3ACULL, 
            0x6718722E5E3B9511ULL, 0x4E77990466BD1285ULL, 0xABD251E6A9A031DCULL, 0x06E29A75B438E1ADULL, 
            0xE9E90A0DFF7E87C4ULL, 0xF86D2CCDBF7E2734ULL, 0x9A2A6C254244ADADULL, 0x11638882F5297CEDULL
        },
        {
            0xBBB64D7CBA926C0BULL, 0x3682B21390ECF185ULL, 0x9309219251CC1A7CULL, 0x12CD1058981C018FULL, 
            0xDA943B35D4A0AAB8ULL, 0x6FBFD72872EB2EEDULL, 0x5B4F1C11013E86FCULL, 0x76C99C00EF0D5411ULL, 
            0x51D10A3F4871F6A8ULL, 0x1776E1DD7285A1BFULL, 0x7BAAA5C9A7B59D38ULL, 0x7F5D1E24CE680441ULL, 
            0xE2BBEAB36B7610A2ULL, 0xC05B694A91E36576ULL, 0x03CE7E55A6CCD301ULL, 0xA48E4B0D6E4DFB36ULL, 
            0x38E3B5F0DF67F5ADULL, 0x4B361F1630C21B52ULL, 0x5F6B45FD273C0ABEULL, 0xACC541068CB71A5BULL, 
            0xE5C9F422F798C81DULL, 0xEB7DEF3D8C6377CFULL, 0xC2391F42B1E56716ULL, 0x24C24BDC6AEDB33AULL, 
            0xD2CE0814307490A0ULL, 0xB0C63A2DD926F923ULL, 0x9CF8D0755EC54505ULL, 0x24A32251C9D5BB79ULL, 
            0x9CE41B1044A61AF9ULL, 0x2C9FA8A74EE339F5ULL, 0x7CA7242FE3F0A062ULL, 0x9D9C0A6747A579F7ULL
        },
        {
            0x4A391314C4B75B2DULL, 0xF8125824BFA66E61ULL, 0x67347AFD09B05561ULL, 0x19EC34922C22234FULL, 
            0x2C30DA9BFEA3B702ULL, 0x28AED5C748B75EC4ULL, 0x1AA3979401757949ULL, 0xFF9B87E071B5ECF9ULL, 
            0xA2B05D2A2A00F613ULL, 0x706D203C615F5350ULL, 0x3CC53990B7C1976DULL, 0x3465DB13383A7CCCULL, 
            0x0AD55B452595EBE7ULL, 0xEEB892C2FDDA7EE7ULL, 0x657907A3B20E86E1ULL, 0x4152E59AE5DD163BULL, 
            0xE61258E726181D80ULL, 0x0991E307A77CE32DULL, 0xAB12C8B628ABE4A5ULL, 0xDAFB83BF29EF987CULL, 
            0x08C2C1CB6DF1C48FULL, 0xFBA042BB4AF93974ULL, 0x0BDC702D89ADE90FULL, 0xFED3A27E37E56BC3ULL, 
            0x5C8C263B002EDC36ULL, 0xA6E3A6F85D5C3458ULL, 0x36FBB3F4853AB3A3ULL, 0xC263795EA36B24A8ULL, 
            0xA3E2A57B6E9AD9BDULL, 0xBD3E3C629BFAC6C5ULL, 0xED5DC0E1C50C6693ULL, 0x56B6886949DBED7BULL
        },
        {
            0xA28ECBF11BEC7409ULL, 0x802823CCCC234BB2ULL, 0xD6C7CCF33D156CA5ULL, 0x41413593B0F1E85DULL, 
            0x26C55D84B11BD23FULL, 0xB8E67697FFE54433ULL, 0x4F6FD10BD57EEC5DULL, 0xD42CEA5DAF72C117ULL, 
            0x9CBA202237E45A3AULL, 0x9D46FFD9B8AF8FB8ULL, 0xAC6BFF556356EDEDULL, 0xCCE94829ABF0A736ULL, 
            0xA0D293C30C8EFD81ULL, 0xA19DC99A87245CB3ULL, 0xF6178CE70945CE79ULL, 0xE8E05A93D2538AEEULL, 
            0x5142D2F9F3B536AAULL, 0xD5F93A5E7E07B05AULL, 0x91E79125F255F283ULL, 0x1731749902EE1896ULL, 
            0xBA8F689FB1922BF4ULL, 0xF890BFF3A1D61E6BULL, 0x2D6707423F5FD73DULL, 0x78AAD0B0B33539ACULL, 
            0x9EDD59A211A85D6BULL, 0x8B2CF5769CB94DCCULL, 0x117668C372FBA4B9ULL, 0x601E4AF4176DA20CULL, 
            0x5A570125FF4C3CC6ULL, 0xFEF3960E246B146AULL, 0x13D9A159794FEED9ULL, 0x121783AEDDEF9B49ULL
        },
        {
            0x0C934D3375EBE8E9ULL, 0x143F87EE7506744DULL, 0xEE646C533823D3D0ULL, 0x10EB610E29F62913ULL, 
            0x71E11B58C8A12FB1ULL, 0x6AEC58A8EBB50F2DULL, 0x818BCC951BBA7D37ULL, 0xAE36343293F00E5EULL, 
            0xECD2AD566649CB10ULL, 0xABB5D97E878CCA3DULL, 0x5E648E554EAEB5E3ULL, 0x01EA17C9E5317C0FULL, 
            0x1F35AC339B667B55ULL, 0x75EF54078DFD5AD2ULL, 0x0CB29DA13988BB26ULL, 0xD660AA721293F668ULL, 
            0x3282593E7328FE9CULL, 0xFE26436B87D6C32FULL, 0x61607973F0C3FD1BULL, 0x61CFCD669212F97DULL, 
            0xEC2A7D976367C90DULL, 0x2E58BF434364FDF3ULL, 0xA2FF1415C77FED08ULL, 0x7A823ABAD4FA4CF8ULL, 
            0x4057AEDE816BF8F3ULL, 0x968D8AC033A0AE1BULL, 0xF3138834A75B7408ULL, 0x63273881562F022CULL, 
            0xAE9A07856581A4DBULL, 0x307465D11C59C215ULL, 0xFFEF292DC39318BFULL, 0x9BA9C765994E666CULL
        },
        {
            0xACAFDCFD3AECB87DULL, 0x4A9F9129BC0A3146ULL, 0xB31AB656AF4E517AULL, 0x68BE6DB9FA965E27ULL, 
            0x0C9F7FE8A734DC57ULL, 0x5449448A751B4AF8ULL, 0x9462D4137CB5E8AFULL, 0x2D1D7A01901898FEULL, 
            0xDFE6BA8E336D4C59ULL, 0xF62BA10CB7390992ULL, 0xC6330E8565652832ULL, 0x3BCD03171C93F987ULL, 
            0x598EFA1D2A108629ULL, 0xBE1F24C053A563A4ULL, 0x7C7349A4657225DBULL, 0x7FFCA443D7734CC2ULL, 
            0x619D5450A21BA1B2ULL, 0x19B481E29C1B91DDULL, 0x196AE262E1BAD5DAULL, 0x60C5CCC3840A5774ULL, 
            0xEBAF3FCDFD2FD25FULL, 0xDAAEDDFBB403065CULL, 0x5B445EDBD87F2FC0ULL, 0x9EECC2039E159C46ULL, 
            0x42413888944761C5ULL, 0x23E47B8FAFF20F98ULL, 0x647DFDF89A93F206ULL, 0xC3B86092A9FB3AEEULL, 
            0x670A74440A25E99FULL, 0x0D1D84634787DA4AULL, 0xD841A41705C8FE59ULL, 0xE20124FDAFBC7BA5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseAConstants = {
    0x2DAFB81B66A808C1ULL,
    0x15390E9CBF30372BULL,
    0x3572D983FE3C39BEULL,
    0x2DAFB81B66A808C1ULL,
    0x15390E9CBF30372BULL,
    0x3572D983FE3C39BEULL,
    0xEFFFCA08EF3E4C26ULL,
    0xDACC8695745AA520ULL,
    0xE7,
    0xBA,
    0xEF,
    0x6A,
    0x8E,
    0x70,
    0xD2,
    0x41
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseBSalts = {
    {
        {
            0x4AE65D4930F0BABDULL, 0x446FA97958B1E708ULL, 0x5F257529A995A2FDULL, 0xC747E5EC0AF60990ULL, 
            0x0EA6326E017BF7E0ULL, 0x4262B1E0C558093EULL, 0xF7A459F0A79012DBULL, 0xF7C7C0F106372770ULL, 
            0x71ABE1EC0BB7693DULL, 0x47DBE20A1CB234B0ULL, 0x35A01EC3BA916AA9ULL, 0xE6460F8F68D20393ULL, 
            0x402CE9B5DAB8E62BULL, 0x2F83D531563E344DULL, 0x57A744A64D2349EEULL, 0xDBC478E707C51074ULL, 
            0x61BE2DBEA8AD720FULL, 0xA44FB02984C146F5ULL, 0x9B5991CA13EB2DF3ULL, 0x4857B4B339B5C244ULL, 
            0xCD67B1C45575F52FULL, 0xA32C2995C4E8F192ULL, 0x208AD66B2AFFBD5AULL, 0x7C4034896F4BE529ULL, 
            0x91AA8AE27DF87658ULL, 0xF098F6D118AAE607ULL, 0x2F67DA421760FA48ULL, 0xAB73419D80259B3EULL, 
            0xF8789031D520FDD9ULL, 0xD440115BC33256BBULL, 0x190589EFAFBA6B90ULL, 0xDC1F77F5C7CE5C9EULL
        },
        {
            0x2B2C5E92906F8F19ULL, 0xB98FA9E109A990FFULL, 0xD20B13EC493B9E6FULL, 0x2DC24AE5987F89AAULL, 
            0x16739E7F601D4B05ULL, 0xB66C55FE93B38F44ULL, 0x70E94136C39814FBULL, 0x686403D4533F6294ULL, 
            0xBECA25C6FFF3600CULL, 0xE9E26485B57453B5ULL, 0x038412BE4A8473B7ULL, 0x3DF320F8B17B56F2ULL, 
            0x7C593E076F289ABAULL, 0x489A4549E9F19032ULL, 0x742DA1265A05BF06ULL, 0xD1510EB23B6F2A52ULL, 
            0xCFD2A6004B007384ULL, 0x64DB6AE8B9DB536EULL, 0xB3E8881DC7C716D9ULL, 0xEF10337ECC1469DAULL, 
            0xB60D9DDA3E79453AULL, 0x72510F791B4C3381ULL, 0xDB6ABC3FC513955DULL, 0x8DD7BA99E9B317EFULL, 
            0x4BF01A87F2CC9389ULL, 0x8AEC8BFFFAD33D7EULL, 0x19B9FE263832063EULL, 0x8BA68E1115083958ULL, 
            0xAA36B03A9B0E8401ULL, 0x139DD22B1F321D1FULL, 0x6CF551525680A0D9ULL, 0xB327842AC50A08EFULL
        },
        {
            0xB719FF245AD7CE09ULL, 0x113CD84019515861ULL, 0xFE0F6230E9CBD3A3ULL, 0x398E59D7C059EB3DULL, 
            0xE6B01EC219F4B553ULL, 0x5913589F86966253ULL, 0x6E60714FC6DF3EC3ULL, 0x82023B717ADB6BC1ULL, 
            0x26F470BE8BA413EFULL, 0x2D9A017D874289B5ULL, 0x3B58178A56D7776BULL, 0x6CC67E989EF4177FULL, 
            0xC31B2C485B5EAC9BULL, 0x47BAC841D5E4BFCAULL, 0x04B48A3488A6BA86ULL, 0x67475C91875288A7ULL, 
            0x05FE760DF0BEF785ULL, 0x1ACA3D70CA84D270ULL, 0x095BF1D1FC1E6792ULL, 0xD7B6D580DDDBFC05ULL, 
            0x49E2769748AA6F1BULL, 0x50FAE4894713705DULL, 0x9929B98C3F7742B8ULL, 0x99467D270A326E26ULL, 
            0xDD2A68464454ADCEULL, 0x6E5B575D65BA4982ULL, 0xAF414E27DBE02184ULL, 0x3DBB356C62262B4CULL, 
            0xF810BF2DA79D8FE1ULL, 0x0BFCAEBAC83AE122ULL, 0xA2229F48F1BB03ECULL, 0x540733051329D96DULL
        },
        {
            0xC66FD284C649F45AULL, 0xB52BC42C576961B2ULL, 0x471096B7A64A5BEBULL, 0x2DE3EC0A222A6153ULL, 
            0x91289B125ECB5A1EULL, 0x3C409CD041670B6DULL, 0x060186BCF9BBCA1DULL, 0x9922ED9343EB426DULL, 
            0x2ED8450B8C268231ULL, 0x1F919C647964B2FDULL, 0x53651B24A83DB2CBULL, 0x51C9667AA4BFDFC2ULL, 
            0x6BBF0DFC151A6BC8ULL, 0x71526A91D0050CFBULL, 0xDC406C7552ACE7EBULL, 0x0198C6F46DB00DCAULL, 
            0x5FFD0C5AE3FC4C13ULL, 0x986A5DD355BF9F7BULL, 0x1394EB47C214367AULL, 0x02FE342F9D6CFB6DULL, 
            0xDB7CD2D83C6A5118ULL, 0x0A0C8A4E9DA0E8BAULL, 0xBE024E208B0799B1ULL, 0x3119281B0B67ED68ULL, 
            0x0C22836D322428B3ULL, 0x83DE1B9B04A9D781ULL, 0xE0EDAFCC040E1F59ULL, 0x75DB671222F2579AULL, 
            0xF93927EE81A7989CULL, 0xD65AD6B2162F4403ULL, 0x04087C854A9CBCD7ULL, 0x5D05399FE241C1F3ULL
        },
        {
            0x1C10ADA961C5C31CULL, 0x3EEF549494AD4A72ULL, 0x57A8C8FA5664172CULL, 0x7C0F3A136FBF9ABCULL, 
            0xAE7659DBFA411615ULL, 0x158FFC97637B62EAULL, 0x1BB8E56D03B2E69EULL, 0x472630064F003D12ULL, 
            0x9147CFD5C0B4B843ULL, 0x3FA19D30BF91D559ULL, 0x5ED163214A64FF55ULL, 0x8E8CC3C04CF06E57ULL, 
            0x2F5C95449CAD8E6CULL, 0x37159DBBF7A7780BULL, 0x19079D376DF7B348ULL, 0x46A4BBE99D42EFC3ULL, 
            0x0BE50DEB23EAA851ULL, 0x697095011932CE16ULL, 0xDCBAA6335A3DE97AULL, 0x633DD2B5B8C80D16ULL, 
            0x62D0C047C89CE209ULL, 0x92DF306511547ABEULL, 0xFE5811118A267408ULL, 0xAFFCDE8425DB8F58ULL, 
            0x40CAF5A0520DCAECULL, 0x6E2FD261FC287CD9ULL, 0x1E94841A68621305ULL, 0xC382C252AAB4DFE0ULL, 
            0x8381C541A9D2F39DULL, 0x3AC0C900AE3D830BULL, 0xE2365F953E994394ULL, 0x6F0A2C326341ECA7ULL
        },
        {
            0x5CE47BE64C2506E2ULL, 0x355E311FED3A10A3ULL, 0xE0A6273A9259BBF1ULL, 0xFD8172A9A2663A09ULL, 
            0x61A1BE3315FA00DFULL, 0x1C8AC9BA9EB78938ULL, 0x242D5E0A84639380ULL, 0xA14ACF3009DE0F10ULL, 
            0x2F80269C1D107BBEULL, 0x314B9DDFE5BFC43AULL, 0x8742EF75559A76C0ULL, 0xF0EB9F2D00380BDDULL, 
            0x017A3821DAE65C95ULL, 0xB73555CAFEB2784BULL, 0x32B08ECE5556FA8DULL, 0x7B9B1E87FDAD8B86ULL, 
            0x6791E3B7B99CFA7BULL, 0xA4C2D17C996EFAA8ULL, 0xE8B49490928DE6B0ULL, 0xB6487B82B9D58405ULL, 
            0xC2DF6D5348E55FFCULL, 0xDEEA6E8973C2B920ULL, 0xF047EB0BF3945EBAULL, 0x1B70A069792B5524ULL, 
            0x4535ED807F1F0934ULL, 0x650D51E41FA19A22ULL, 0x247E188EC6D4C8D7ULL, 0x18C3B6531191382AULL, 
            0xCB7E1E93426173BCULL, 0xF2A8BE5A0D73C5AAULL, 0x1DB48B40351B66C8ULL, 0x30C4CC26CE60433DULL
        }
    },
    {
        {
            0x8498637644B7FB0AULL, 0xEA3EFA20B858C346ULL, 0x35705C4824A06569ULL, 0xF82536929AD766C1ULL, 
            0x36D4CEE3908D9AEBULL, 0x6D25655255F977DCULL, 0x61032917990FF3CFULL, 0xF8E16AFB259B105DULL, 
            0x6B83C8933D57EC00ULL, 0x7B151E29EA1B9362ULL, 0x651506EBE4737023ULL, 0xD1C6B84CDC8723F4ULL, 
            0x3C04B004C57B5CC1ULL, 0x7F072B325D4018E0ULL, 0x5957E45FBF2C0F99ULL, 0x6DCB5FFE79010745ULL, 
            0xA2546A8E47A39130ULL, 0x7EB9B0F4243FC835ULL, 0x2B6AE2CCD5B244B1ULL, 0x7ABFB8816ED56734ULL, 
            0xEE8809A7B803534BULL, 0xFBA4A15C89C57C93ULL, 0xAC1F137C1AA4767DULL, 0x212CFC6C1D300378ULL, 
            0x2DC82593EA79AAF2ULL, 0xE2B15F6293B575F3ULL, 0x44E0521069823F08ULL, 0x38D233858A4D0248ULL, 
            0xE4DC7384E3147BCFULL, 0x532DF1A25DBB54CFULL, 0xEB39ECEF8B53981CULL, 0x19DC0630C4D70897ULL
        },
        {
            0x920C3E3DC8B0AAB7ULL, 0x10DE4F619376915FULL, 0x5A467CBFE336147CULL, 0x65D54BDE96245D32ULL, 
            0x214231F0E27CE891ULL, 0xF345D9F66F1A7E9DULL, 0x1113BC581A412A56ULL, 0x8B3589F98645CDD3ULL, 
            0x47B63E81E2262874ULL, 0x238E035BA9CB2C23ULL, 0xE2CDF99D74793CF8ULL, 0x6472B36FC3557A74ULL, 
            0xEA99E18A963F7D91ULL, 0x9FA34EB175FC3FDDULL, 0xBB8A701A4BE7BD6AULL, 0x159E29C1654D8B8BULL, 
            0x4114D4A269B49759ULL, 0x196F306E3B2EEA7CULL, 0xFE480330E95F5063ULL, 0x82B7A6F17EDD75B5ULL, 
            0x4FD569028576C841ULL, 0xAF26EEE2A9868377ULL, 0xE1F654D926D3E7B9ULL, 0x391ED873FEEF0F0AULL, 
            0x37D1C638B4E871C0ULL, 0x74F3A41AB1319FD3ULL, 0x1C1FA2005C46D801ULL, 0xBC2F789E925B9082ULL, 
            0x18E22BF18FE05C04ULL, 0x5EEDA234F2535AE8ULL, 0x56146FE55DCD0592ULL, 0x730E40486BDB9174ULL
        },
        {
            0xBD66AF68D3D81553ULL, 0x2E7D219A8C3C39ABULL, 0x81D4DA55A5333002ULL, 0x6679E94FA8A67D7FULL, 
            0xCF4D91BEF7BD39A4ULL, 0x4FCF091ED401CDF9ULL, 0x02519CC0414E05E6ULL, 0x1C67EB0569605B74ULL, 
            0x5F2C761BCD51D2EAULL, 0x69F81269CCEE05DBULL, 0x331ABA6F00B06212ULL, 0x40FBF8D27AC4EFE0ULL, 
            0x7D8A8806C3FA445EULL, 0x4E773B433145DCAFULL, 0xFBF357502F65B5ECULL, 0xC89DB38F178C82EFULL, 
            0x15E0EE8089316BA3ULL, 0x827E1251A46174DBULL, 0x2A000C99447A9384ULL, 0x865B0BBB91F1183FULL, 
            0x98E1BE59B32A4502ULL, 0xE34D83798DF16807ULL, 0x4448A493B3C77D3BULL, 0x06B0EC71B7FE93F5ULL, 
            0xB4EB666EAD9620C1ULL, 0x5BAEE775015C74C2ULL, 0x038051D2EB799F7DULL, 0xD26F9B39521106BBULL, 
            0xDA3B34FF6141EB46ULL, 0xFC80ACC5D7F698C5ULL, 0x1DE27ECBDAF205EEULL, 0x53B60DEBFB2BC74AULL
        },
        {
            0x929FC73BEEBB38E6ULL, 0x8ADB8B316E396EFBULL, 0xD290465FD100B111ULL, 0x9FB59DF197F6AF8FULL, 
            0x79FCB139929C0F81ULL, 0x5006C417E2EDAB70ULL, 0x37A79A109B427C2CULL, 0x313DD5C8794CC155ULL, 
            0xE3802D3770D234A6ULL, 0xAF1CC7C39A20992AULL, 0x7E094E598E4DFE88ULL, 0x8CB1821EF6F58E33ULL, 
            0x01908B02963D985CULL, 0xA462EBF0B468C96FULL, 0xD75B8E5C063E967BULL, 0xD21E146D16C92A58ULL, 
            0xB029113769221566ULL, 0x66927679F2E70F4FULL, 0x0EF0FE7E7E4D12D4ULL, 0x036456C9035C6C97ULL, 
            0xDF52925B17EFAB60ULL, 0x73BABF22DE996EA6ULL, 0x9D9EB9A204A18F60ULL, 0x6AFDD3FADE302656ULL, 
            0xE8547261E6DD945BULL, 0xA50E4DC62E0EAF77ULL, 0x3CD5E7E06A6FE552ULL, 0x7B3DC9B8D9DA0B8BULL, 
            0x1F0C7743952EAE16ULL, 0x5946AF1C9212B09AULL, 0xB73A080CD70B8C75ULL, 0xA62FEF2D9BE9A95BULL
        },
        {
            0x62A2BBBCF842401BULL, 0x911598C12E1BB8B7ULL, 0xC4D1BFAD0D98377FULL, 0xA7A3694742AE8347ULL, 
            0x04DA421555C7463DULL, 0x4D8C65DB0911BFA8ULL, 0xEA86014969DD3CC8ULL, 0x90F9D69EB1225E04ULL, 
            0xCC63A1688042819BULL, 0x9D29B4298BE6B9CBULL, 0x100AC557F1520716ULL, 0xC41199375A206DDFULL, 
            0xC37A93FC471CCA61ULL, 0xA35E7DF155D0376DULL, 0x21FB4C1B62A4C9B7ULL, 0x2AD5A05F1D811812ULL, 
            0x5A296D64D2DCB115ULL, 0xAAD682C04E9B2905ULL, 0x95D54B81F630B5C8ULL, 0x1C491BC43967412CULL, 
            0xCCCBC09CB80C1B89ULL, 0x1015183F0D5FA14FULL, 0xDB4007BC0C62DC8FULL, 0x6E4AC8701717C04CULL, 
            0xECF4440071F0F557ULL, 0xE42D1AD42C762409ULL, 0x09FFCB36CA076A4DULL, 0x491ED61A238E1432ULL, 
            0xA3D94CB6B5536963ULL, 0xA72A7F7F3F76C8B5ULL, 0xA4897177364A2317ULL, 0x902EE8B167AE70E5ULL
        },
        {
            0x7BD6E590A799361AULL, 0x3DC3C39155EF3726ULL, 0x9B08B8B40E7F77B9ULL, 0x2AE334DEB804145BULL, 
            0xC674D615E5FD22B3ULL, 0x7723AEBB91E703E3ULL, 0x825EADE492E96A97ULL, 0xB6A9CD8D5B333CE6ULL, 
            0xEC3941FD6CC7C25FULL, 0x028031F8FA1CB6C7ULL, 0x61E20CA6E1B5ED80ULL, 0xF1B2F4B4294E99D5ULL, 
            0x7F26F82085D0FC4DULL, 0xCEB9AFBE4A603729ULL, 0x8A47A0EFAA156064ULL, 0xA6F080669168E497ULL, 
            0x2D9BA71245448376ULL, 0xD7CADF2BA41703A7ULL, 0x86FDBDE392DD0A54ULL, 0x52D1DBBDFD8D4173ULL, 
            0x494F2F0BDBFA5580ULL, 0x6D5B41B10A2E4B59ULL, 0x741ECFF1998B410EULL, 0x8CC8977F18ED83B2ULL, 
            0xAACBC054734B065DULL, 0xFA5CFD25FCBE7F36ULL, 0x430BC7749D78A8C1ULL, 0x3B8424F4C6621C37ULL, 
            0xAE3FEDB6024B84B6ULL, 0x74005C70C986E331ULL, 0xC7DC09E73A628984ULL, 0xA8817E6AF1448356ULL
        }
    },
    {
        {
            0xB6289D84D20C9B7FULL, 0x5D531249E4DEA8A8ULL, 0xA1C85281CAF09E71ULL, 0x2119E2D31C30A7CEULL, 
            0x6DA6EDC72C618496ULL, 0x61B9B33ECD51AE94ULL, 0x828D9979DE6FE8DFULL, 0x8A41B78C54A4DDBEULL, 
            0xE315E24146242B4CULL, 0x2B25B88C06B3C9D7ULL, 0xA702EFF6CB4206DBULL, 0xDB7E71537D8A2CE3ULL, 
            0xA3E5F002C1E48637ULL, 0xCF38241D0326AB6CULL, 0x63CF2E04DE2C5412ULL, 0x5F53FFB01BFCD98AULL, 
            0x766788D422322D8AULL, 0xA6842B01166A3DFAULL, 0x6824FB99CBAF5D65ULL, 0xB485748A5CF8B807ULL, 
            0x4FEC3128C9869FBAULL, 0x9A2A73F28EA3EB06ULL, 0x36C224BA383DFF52ULL, 0xE74A72CC564ADBC3ULL, 
            0x30AA5D1647A08FB7ULL, 0x482ECD27204B7340ULL, 0x7A488E1C57AD1E60ULL, 0x9FBFC4FFF4A50715ULL, 
            0xF98DA448F7C6DF53ULL, 0x655E1C393B2D873BULL, 0x3C5A1C02B3680638ULL, 0x6561B008E8081238ULL
        },
        {
            0x517A298427F111EDULL, 0xECC3B16FB2D9D01FULL, 0xDC5A074906629E98ULL, 0xF9EC51B89D50714CULL, 
            0x63CBEC9FCFCA392AULL, 0xB0DA931A0FAFB916ULL, 0x9A7A18A0739AF4CBULL, 0x2B42F7E68E42486FULL, 
            0x2C9E02AD3420C8D3ULL, 0x5E85A67416FD8F3FULL, 0x9249C88B644BD98EULL, 0x46ACC2301B91C80DULL, 
            0xA13D5D04B3BC7860ULL, 0x16267893C0E3A9ACULL, 0xA59449628414E960ULL, 0x6094C9E9E042948FULL, 
            0x5BF3F5EDE8B107CCULL, 0xEF669735444F5A95ULL, 0x39CD1E50F088EF96ULL, 0x47A57E6A8E634C94ULL, 
            0x461F16277C4AEB99ULL, 0x7798DEE4C35F5428ULL, 0x9DBE6ECDD28ADC99ULL, 0xC170E4FCBCD024CEULL, 
            0x309AD802DD0AFF01ULL, 0x2298F0F17E42EAD5ULL, 0xEB35EC02B8DD78E9ULL, 0x8B61390009713A2FULL, 
            0x76AE99312EE05FF5ULL, 0x4DD1A5BD77FD471CULL, 0xB4947C11C98194A5ULL, 0xB0E567D435C80898ULL
        },
        {
            0x26898BC8EA3DDADBULL, 0xE06034D9F4F71540ULL, 0x3BD9CD0DC4EDC4B8ULL, 0x115D9E95871B965DULL, 
            0x0BD90D4E1AE07F85ULL, 0x06D7636DB3597DFAULL, 0x34E70BF8AE1AB422ULL, 0x46B8C7AA1E2CDFEDULL, 
            0xFB11A95A69698B32ULL, 0x87145B9EC168EBF0ULL, 0xDF7BDFD2AE210355ULL, 0x1F3AD3ACCDEC7015ULL, 
            0xC4761A8A88D0FADAULL, 0x61F3ABE7C9746569ULL, 0x3DB5500DECCD5B5DULL, 0x91D5EE5B428023F5ULL, 
            0xF8C8EBC2BF4AEDC8ULL, 0x8AD78EE199ED2AB4ULL, 0x906B22334AC8E479ULL, 0xC4CE89EC2134F0F9ULL, 
            0xC7C574ADC3AEFA85ULL, 0x556559343113C66EULL, 0x560C6B53DD096E7AULL, 0x3A9B98209D172C81ULL, 
            0x7307B8CFDD7436A4ULL, 0xB5BE36AE7FB5D98FULL, 0x8BF495D64C39BB1DULL, 0x4565F2FAC990B37DULL, 
            0x065BBFFD5140B7A1ULL, 0xB6E2A59C79178302ULL, 0xBEE428690ED18BF6ULL, 0x79658D079ED1C956ULL
        },
        {
            0x820C95229B825C0EULL, 0x1C59B46C9B378144ULL, 0x4E1283185221637CULL, 0xFC388ED39C60D616ULL, 
            0x9964C81E496E4853ULL, 0x021B77045A7BE941ULL, 0x175ED757513A3AC0ULL, 0x30F23A3B2E9BEEA7ULL, 
            0x8816FA50BBD63D69ULL, 0x89CA16A35F5C548CULL, 0xBA630A5ED6AF6F10ULL, 0x8E25F0C2C135B484ULL, 
            0x8969540EBB3B2BC5ULL, 0x8EA0F3B2090A9747ULL, 0x9EFF55E15B581125ULL, 0x15345A38E937A80AULL, 
            0x9D3BB2B605D1EF37ULL, 0x9DBED9F471DD51B1ULL, 0xC31F1EE98D04A5EBULL, 0xA246AD3CE67409C3ULL, 
            0x9E2DDBDDA4028A16ULL, 0x03B357CF789535B7ULL, 0x536AD39A3DCB44CFULL, 0x425E4A231783DE5BULL, 
            0xF97DAE2E7B3E0086ULL, 0xFEFA52315BFDC1CDULL, 0xE7AB95AD0ADFFE8DULL, 0x7BC4AF0519334549ULL, 
            0xA0A1CD0B5198DDD0ULL, 0xF557F21A454A204DULL, 0xBD963792C95E2F6FULL, 0x7A9BEEE039E9DED4ULL
        },
        {
            0x0E1D0D6703DA6241ULL, 0x4A4793D9F9C366F0ULL, 0x6EA9FF70357DF509ULL, 0xE20D8DD7A32AFC2EULL, 
            0xA0494821B44A5C2BULL, 0xFA0915B89B564678ULL, 0x1E715AC997C09A72ULL, 0xAAA58F1ACE604BC0ULL, 
            0x338C65924FCEFC18ULL, 0x413DEC6E9242AB2DULL, 0x2B1E79782B299539ULL, 0xEB55C4ECBBA92E90ULL, 
            0x0A88B5A17437DC4CULL, 0x7ED2AD67918F9783ULL, 0x9278CD826D14A98AULL, 0xF82C5FF57991AB11ULL, 
            0x7D38B361C242E680ULL, 0xCED3EEB27FDD25ECULL, 0x5BFAE9751CF2088EULL, 0x8534A67FADCAC95BULL, 
            0x95C4CB327E49D707ULL, 0xCF6A2BA0BF9D642FULL, 0x677C18F12AC31BDBULL, 0xD979329A486EDAD5ULL, 
            0xBE96565AA84E89A7ULL, 0x45332153DF59C833ULL, 0x5ED5C9E507CEF487ULL, 0xFF1C2E9B63C17034ULL, 
            0x870E62258E843408ULL, 0x4AA6F3D212EBB50EULL, 0x33593026B3D465E2ULL, 0x27C179100D9F8114ULL
        },
        {
            0xC80F65C8AB5DC53CULL, 0x61C569E50EDBC734ULL, 0xB48B4F80591B1864ULL, 0x6DE6578A5FE27466ULL, 
            0x7DC4B62809B30656ULL, 0xCEF34E59D9B557A2ULL, 0x07AC3409788C5D67ULL, 0x8C6BAE82DF1C3C78ULL, 
            0xB75577F5DFC54DC4ULL, 0xEBC74CA3139EAAFFULL, 0x93FADB87681BE2EDULL, 0xEAC183163B52C148ULL, 
            0x9E229D0F6D8D7F0CULL, 0x0B6C387DE4E25B12ULL, 0xD271BF5E8B77AA5EULL, 0xB6D6AFF3FB5495B0ULL, 
            0x141DFFADF92BDA8AULL, 0x8B63EEBCD6B97671ULL, 0xDB9BEDA958273923ULL, 0x3DBCC781C7E79AE8ULL, 
            0xD3D201858A62A90BULL, 0x0064C75B8FA008E7ULL, 0x49E961173583DCF1ULL, 0x07E8B101A29CF3DDULL, 
            0x07ABCF7DB68206C0ULL, 0x51FB308232D7D016ULL, 0x6D73A90BE0F1437BULL, 0xFB62062FF46FA889ULL, 
            0xA5A7638AD039D9B9ULL, 0x1BA2C0B06A498588ULL, 0xF5C9EABC1A4FE6C0ULL, 0x263DB268C4DDE5A1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseBConstants = {
    0x9B8297108AC7D392ULL,
    0x11AFB503B31D2890ULL,
    0x3982367FC9B17467ULL,
    0x9B8297108AC7D392ULL,
    0x11AFB503B31D2890ULL,
    0x3982367FC9B17467ULL,
    0xEF086C3CBAF3C718ULL,
    0xA7784F124569DD35ULL,
    0x4D,
    0xE5,
    0x80,
    0xEB,
    0x01,
    0x98,
    0xB6,
    0x97
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseCSalts = {
    {
        {
            0xFCB6EC963DDB7ED3ULL, 0xC212711909E0B126ULL, 0xA103AB1BBFD54B83ULL, 0xFFCAE4CD36F9C74CULL, 
            0x1D6A790492EAE5D7ULL, 0xD830006C738E7A41ULL, 0xD3B8AEDA7B3DFEE8ULL, 0x3EE6A072D6B9185DULL, 
            0x085689062361D3AFULL, 0x42AC07A396CEA5B9ULL, 0x001D10D59939A029ULL, 0x913CE1DE1F0FDDD0ULL, 
            0x64BECBE09616C4E0ULL, 0x7632C1C6AF5ECD80ULL, 0x46DEECDFDF84D494ULL, 0x5CABE4AC9B5EAA7AULL, 
            0xAD4F9AB43BDF32C5ULL, 0x3DC522A1EF20641AULL, 0x08D70463FC535188ULL, 0x1E9C653EC7F193AFULL, 
            0x9CAAC2C8202244CCULL, 0xB63BAFA9FA728F8FULL, 0x18905812F962C1E8ULL, 0x8CE6A013AE47FC80ULL, 
            0xB9B30AE606BCFB0DULL, 0x81C0B7A783D0FAF4ULL, 0xA20CB6FF296AEB90ULL, 0x7743A100DF3069B1ULL, 
            0x8F181CDC36DF04D2ULL, 0xF12D774209898C53ULL, 0xECBDD17F62EDBC7BULL, 0x1CE9E75CAC09806DULL
        },
        {
            0xD3C4A6B3058432A9ULL, 0x38DB4F606334D0BBULL, 0x70B19B5714AE08B4ULL, 0xF57CFA3C7F4E088BULL, 
            0x70997A97A3DD8CCEULL, 0x0A835AE9C5624BEAULL, 0xBAF290CEC2553828ULL, 0xCF62D21A7615D4F3ULL, 
            0x20D54D5DECF22F22ULL, 0x65D6984D08328871ULL, 0x15B962F7C825639AULL, 0xD069ADF94FAF832CULL, 
            0x0E945384D84E87CEULL, 0x8EC904CA48969658ULL, 0x0379CCAD721F7B1DULL, 0x0B59FF413A941539ULL, 
            0x89F3E5A068C24195ULL, 0xD29B152BD8DDA041ULL, 0xABFDCF63A6B2ECB9ULL, 0xDBA383D390746EBFULL, 
            0xE19DEE3D535979B1ULL, 0xCBC0CD7B29A347CBULL, 0xBE3DA98624B3A165ULL, 0xB9A425DBEB74FB26ULL, 
            0x6F57ADFCDC6ABC2FULL, 0x9FBB76FAE0790F77ULL, 0x4F53FA23E7BDDD0FULL, 0xDCCA9F426C80BD66ULL, 
            0x9BA32B5018A19CE9ULL, 0xF3E5DBC0188D307FULL, 0xD11E14C6AC2966FDULL, 0xE5FE5486F96BCA28ULL
        },
        {
            0x2484CC76045A24AFULL, 0x1102E6C41182E68FULL, 0x5A308752D38001C1ULL, 0x387F2F4EEAF8D204ULL, 
            0x174784ED15D3FFA8ULL, 0xFFC9FFD2BB1F7F1DULL, 0x0CE8BB731ABA970CULL, 0x2794B220DF9D56F2ULL, 
            0x576E22F6F93F67B6ULL, 0x214077D9394D9BC8ULL, 0x08BD363347FB52C8ULL, 0x999DD92AA578A910ULL, 
            0x09CBE50050F0911EULL, 0xEEF2608103A05031ULL, 0xF3EE882126363FF8ULL, 0x5A99A36DA6E4CF55ULL, 
            0x432C37A49415AF21ULL, 0xD335706FD6E8445CULL, 0xB6C84AA991AA3EF7ULL, 0x338C0187497B753EULL, 
            0x229289D08458DB03ULL, 0xB5053C98741B9997ULL, 0x8E83E2ECBCC4E316ULL, 0xE0CBB437C9B09ED9ULL, 
            0xF8044467E85A9F7BULL, 0x9852047F69E86D8CULL, 0x1D3A08C2C456343DULL, 0x0E57C63B7DA518AFULL, 
            0x682C495C20C75952ULL, 0x3701E9C36D41893AULL, 0x8180D14C58EE5F60ULL, 0x28921FB990E69794ULL
        },
        {
            0xDC0CF578879E2D3DULL, 0x40909FE45E289CF5ULL, 0xAB1D781BB1E25975ULL, 0xB1612FC9EEFB3C93ULL, 
            0x5C0F8ABE7FE392AEULL, 0x5418236EB8BE6AB6ULL, 0x608C4C2BA2E91320ULL, 0xA915D54EB5591166ULL, 
            0x2366AAF6BFB4C359ULL, 0x0A044950808166D4ULL, 0xB8AB04F9BAEECEC2ULL, 0xEF9DC7C09453735AULL, 
            0xE09C258F00C36103ULL, 0x074ABC5F4E791C9AULL, 0x8E49315910355CD0ULL, 0x9A926B9ED73267BEULL, 
            0x5067191999D01B45ULL, 0x6FB381F30080EE47ULL, 0xB7CF4132C0630E25ULL, 0x23093FE3BC04AB31ULL, 
            0x0C091CD39E62FF0BULL, 0x4EE75D25917C5143ULL, 0x52339CAE30491DFEULL, 0x4471B5F1809F7C7CULL, 
            0xB007DF589C231FB7ULL, 0x55443D57A18FE29EULL, 0x4E6F3CD8544D7A63ULL, 0xA907009312804BFFULL, 
            0xABAF0CA5DB075A46ULL, 0x188A745793DDE0D0ULL, 0xA0D6BEADFE75165AULL, 0x8222E58A84E6D544ULL
        },
        {
            0xFC68965E8306D165ULL, 0x3581A87797CBC532ULL, 0xC7D83FB38575E3B3ULL, 0x0DFF13089EF4D970ULL, 
            0xC505F9C36078562BULL, 0xB3B8E0F9DE2D51CCULL, 0x5CF8CD011557EA45ULL, 0xAB6BA8878C5C9EE4ULL, 
            0x80EB715C2BE15FC9ULL, 0xFD09DBF81376EB2DULL, 0x650FCA4D5E5A0D43ULL, 0x84E247336E7B564BULL, 
            0x103C8BB104E811CCULL, 0x433B6FD8529814B8ULL, 0x75C9319D1BEAD4E5ULL, 0x41490B00B576611FULL, 
            0xBF84E3E430C267B4ULL, 0x5A29378C17550E9DULL, 0xAA140BDD58B6C03FULL, 0x3BD8C2E5C0EA0B28ULL, 
            0xD854F0ECBB75C540ULL, 0xACB711DF3219B305ULL, 0x1215AB3527BC34E3ULL, 0x9D69F105CA48EA0EULL, 
            0x0C518A2DD5A5B6A7ULL, 0x988EA4DE1015E1F4ULL, 0xE14B4BD96BD65AD9ULL, 0x22D1AA074C32DB6BULL, 
            0xF3CF146D4250A109ULL, 0x9382F5F834E4F075ULL, 0x6684663824EC924CULL, 0xDBC27E5F595C0B93ULL
        },
        {
            0x418343C5DEEE448DULL, 0xDF9233D9B11FA76FULL, 0x00F1BCD27DDBB1BEULL, 0x0C601C884001523AULL, 
            0x4B632DBE7FED9AE0ULL, 0xE63559765FDE03DBULL, 0xAB16166307240F5EULL, 0x717359EDE8A93F7EULL, 
            0xBB0F080249F12E09ULL, 0x2B4A20EA2A9928A1ULL, 0x2DE01853853E411FULL, 0x39060BF0EBF0E5F9ULL, 
            0x2D60216CE4B342D2ULL, 0x9075AB2B36C890B9ULL, 0xEE60A721D3EFF247ULL, 0xFA37E210E3CF8D74ULL, 
            0x58C27BE30220F9E8ULL, 0x537313C0885C0EE6ULL, 0xEEAE98702BC8D7C1ULL, 0x416DE0272E3FEBB8ULL, 
            0xE291F4F4D660C6D0ULL, 0x880014905A03284DULL, 0xC7255BC7D050C60BULL, 0x0DE5957E287D9284ULL, 
            0x0C5B78F7E3A9E428ULL, 0x01549E2659133DAEULL, 0x4D04DCB37184F8EFULL, 0x3C72FE8D2D166949ULL, 
            0x5E09A7BE706A2BF2ULL, 0xE4B6BE538D88CCA9ULL, 0xF59100CB08CB1D96ULL, 0xA021DDC76DBAC184ULL
        }
    },
    {
        {
            0xA1E92153D58F15EBULL, 0x951D5F2E8485ECC9ULL, 0xF4A62970944F76D5ULL, 0x08DBC1DC9791E09DULL, 
            0xFDAD4D292B88D64CULL, 0x43AC9C429E902728ULL, 0x1EE51AA714DE2797ULL, 0x42E25D75EF94F9E2ULL, 
            0x34497E1FFCCF7000ULL, 0x136E156DB18A9847ULL, 0x892962DA588F3CB4ULL, 0x0E7B25EDA6A8B1C5ULL, 
            0xC0C97DF2171E039FULL, 0xE1D70B0219E3722BULL, 0x25DE0834B6476D3EULL, 0xC3ED6D2CFF0A6B9AULL, 
            0x45FA83D4ADB2F376ULL, 0xCC8C171F7D33C31BULL, 0x7D7533202539B421ULL, 0xECA6FB875A611BDBULL, 
            0x9E7D02AC76C21F90ULL, 0x2A04787695E301E7ULL, 0xAB0457EFF0BCE5F0ULL, 0x2E24C3BE2D3AC4A6ULL, 
            0xA77D586FB850823FULL, 0x8DBC52CAC1C09D89ULL, 0x1B74C1A5F102789CULL, 0x60D8569FF3B350D3ULL, 
            0x29FBCFCDE64BDC35ULL, 0x198A1F5FBA46EC8DULL, 0x5288D60F529C444FULL, 0x8049C19BC91DB7D5ULL
        },
        {
            0x17B4F199DEB3A240ULL, 0xAD58F927B8E7CA5DULL, 0x67B143CA48C5276EULL, 0x14678434EAF47106ULL, 
            0xC976E9A8BE96FE06ULL, 0x90E6A14D432664E9ULL, 0x78E11121F636355EULL, 0x63BE9266B10C66E4ULL, 
            0x24090A12586390EFULL, 0x1348F22210A0CC6BULL, 0x12CE4AF9FC941B4CULL, 0x740AEB8C12CD64A4ULL, 
            0xB437A4AD4902A9E6ULL, 0x717AE095B794A048ULL, 0x04D38C3892B0242EULL, 0x0BAB781B35FF33A3ULL, 
            0x8FABDC615E0E0C77ULL, 0xF385582A34E64934ULL, 0xED8355C08BDF2EDCULL, 0x84E98A6F38525E26ULL, 
            0x5A779ECAE7EEB880ULL, 0x53EE653AAAEF3F9FULL, 0x1290A73451714918ULL, 0xAEF8882D65EA4EBBULL, 
            0x6B5C73530005C038ULL, 0x8D11B53D2A36B149ULL, 0x8752DD8C6BA4AF57ULL, 0x0B686DCF6BD57526ULL, 
            0x51171959E8B9B96FULL, 0x2D51628D92863817ULL, 0x05D4CD7D925C8A20ULL, 0x6D0426675943A2DCULL
        },
        {
            0x6A2A2A93A388A2E6ULL, 0x1F84BCC12D69C979ULL, 0xC01FDBF59F818264ULL, 0xD7331E960DB5AA3DULL, 
            0x5986DA506649982BULL, 0x8D2AC4FEB20B8F73ULL, 0x2197CA9B76E62468ULL, 0x3708D50B8C3F5A13ULL, 
            0x2D1870B8F7388A2CULL, 0xFC9C2FB0912C1ABDULL, 0xAD7181C40022A0CBULL, 0x2B0FC847B9B27BBEULL, 
            0xA2F15AB25DA860AAULL, 0x9951B660028EEB2EULL, 0xC1A46EF05D408409ULL, 0x1AFA0E5ABD957DB7ULL, 
            0x49466E824443A5D0ULL, 0x5728FFA99CEEC906ULL, 0xFF9E45BE408F86D6ULL, 0x2E4EF40D2E50E97FULL, 
            0x7AF109468AA1812DULL, 0x617BAC020F8F10E9ULL, 0x25B0E1BFA8E43EE0ULL, 0x3CA924EB580E6ECCULL, 
            0x66E8B837167C68C3ULL, 0xD6F2521B5BFB52D5ULL, 0x9D4CA64494E194E7ULL, 0x836A4BB0ECF6D2EEULL, 
            0xF2714F72BF62165CULL, 0xA543CD5BA5C029E8ULL, 0xC4A9D644692CAFABULL, 0x025F52630265D101ULL
        },
        {
            0x564AF55CFE615892ULL, 0xE3794E4EE49C4EA4ULL, 0x21D23CC70107A4D3ULL, 0xDEFA8EA85BB7BE16ULL, 
            0x64CE61280571CDDCULL, 0x2CFEBFC9895E42BAULL, 0x5B21E5EA2895FD32ULL, 0x0DAF726F68C79BE0ULL, 
            0xF5AA16529149849DULL, 0x205288D6BE6F8DC5ULL, 0xD3094769C443BC9CULL, 0xAAC3021A94DA6209ULL, 
            0x979220A1B9BA1A38ULL, 0x4D7CAE3955D13EFBULL, 0xA8C16E24091A044DULL, 0xA63629056D30AF24ULL, 
            0xAE35D1F6DD8DA2C4ULL, 0xAABDF4AF1A166227ULL, 0xE1E2E1EAB3C7AC41ULL, 0x8A2DA083E36B5C84ULL, 
            0x44EEFCCF8FE8609EULL, 0x07A291289BF782EEULL, 0xAF476B5ACBA35717ULL, 0xE7681C16D344D1C0ULL, 
            0x321322429BAC221FULL, 0x4A394B46785DF22DULL, 0x91EFB5A1D44DE570ULL, 0x09F66342D49A866BULL, 
            0x68E954A174608D07ULL, 0x2A3FA68B30850163ULL, 0x056507D78DEB7BD0ULL, 0x1BD4247D9CC5878DULL
        },
        {
            0x370098612A3D2C34ULL, 0xBEE6CA33DB05A203ULL, 0x3052AB3FFFC50176ULL, 0x662EFF75DFF4F7CDULL, 
            0x7A1A2379A248B828ULL, 0xF812D19BF4E8C7B6ULL, 0x76612F7DAA4D7F74ULL, 0x52042D1091FF90A6ULL, 
            0x30040EB758770D93ULL, 0x62C02ECA65AB9023ULL, 0xD76B901F1DCB30B3ULL, 0x81C9EDC924CA2FACULL, 
            0xAE23FF0ED02E60D6ULL, 0x2220AD43CB67B483ULL, 0xA64735472DA9E6B4ULL, 0xAA5F68B6017534F7ULL, 
            0x7C2CA150E775C7B8ULL, 0xE319D830D20AFF9FULL, 0xC69CED9D7CC7EF74ULL, 0x8D07DF890AA7F776ULL, 
            0x17550AF031561DECULL, 0x90C3755EF7DC96F4ULL, 0x7DA49EB9BE57A3D4ULL, 0x37E9F0A1BE7557A6ULL, 
            0x495E77F1C24C6A22ULL, 0x3FBE5782DA0AF877ULL, 0x2EC959908EF4CA98ULL, 0x0C56CFDA79E6BCD1ULL, 
            0x9E6B43ACBDF059C8ULL, 0x6B92054F624F9F7EULL, 0xA8F30DEDD509B0A5ULL, 0x37D5604EA028F8EAULL
        },
        {
            0xBE860F2929F30E60ULL, 0xA9AF342D9EAF00AFULL, 0x6CA659E44C3287E5ULL, 0x57EAC1C55CFE236FULL, 
            0x3C3F6753B473260AULL, 0x2CFE428908D83CB0ULL, 0x110E2846E965C276ULL, 0x5A3B08FFC0383C2AULL, 
            0x8C907917FEC9EE3AULL, 0xE7654AF5BA89FA90ULL, 0x95281B724B98E867ULL, 0x39028D32E70B36D3ULL, 
            0xAF6F850EF4FB21DFULL, 0x2CB9BDCB5BDD4632ULL, 0xE8CA9BF210210CB9ULL, 0xC420EF07BF247943ULL, 
            0xED83F46E96929A45ULL, 0x4E1DA93B423083B6ULL, 0xD5D50CB006D33462ULL, 0xDE256D73FFFA7EFFULL, 
            0xA12D04EAF177B945ULL, 0xA853EB32FC09A178ULL, 0x49E11D5B69BE76DBULL, 0xDF0599B0F67FFAD4ULL, 
            0x92F7F86086D36CD0ULL, 0xA5806F354977FF1BULL, 0x1ADA3F73793D9E09ULL, 0x5487D78083885D65ULL, 
            0xA633E483102D8A39ULL, 0x8E087B9FFA8E4213ULL, 0x55706757390D651AULL, 0xA95489C27A0FB570ULL
        }
    },
    {
        {
            0xEEB09E0FB0ED23B3ULL, 0xFAC874C7B3217049ULL, 0xA56C71F5CD0BD348ULL, 0xA1AAFB3C1847C55EULL, 
            0x0AE6F3E377599B82ULL, 0xB8F0350341752948ULL, 0x53BC038F0855844DULL, 0x979758FE9CD709A2ULL, 
            0xA163901AF92FED33ULL, 0xA3705C7AC5EDD947ULL, 0xE36A2D83E7DE1304ULL, 0x733E24F6BFE558E1ULL, 
            0x54DDEFEF7EE65452ULL, 0xE9A49FDC736E02CAULL, 0x43058A0FA6C1B69FULL, 0xDF953EE85EABF3FFULL, 
            0xABC6CC5586E7C8A4ULL, 0xACD1D7CA5D20B93BULL, 0xCC7E88DF42B9C2BCULL, 0x8662787EBBD752D8ULL, 
            0x434671E36DD441D7ULL, 0xEBA9C4C9E4FA26A1ULL, 0xCA059DF9E0D46CDDULL, 0xB52D3AC965B07E8AULL, 
            0xE9543F419FDBDAA7ULL, 0x685B7974F58E5602ULL, 0x2B5E728D7E7AF33EULL, 0xD8C4F356B73BC83FULL, 
            0x70424BD40F5B5920ULL, 0x3B599D12BC1B27D0ULL, 0x302B6510EF10EC51ULL, 0x85E354ECD528A446ULL
        },
        {
            0x00DA366BFDEA4068ULL, 0x712BD770DBC3BDF1ULL, 0x81E027DD014DF653ULL, 0xD29F20AF823A9041ULL, 
            0x52029F508E0244A0ULL, 0x3792E6B3F9F1A3D8ULL, 0xFB1C8AFCF29D8FB4ULL, 0x3FC1932716CBA9BEULL, 
            0xF393E278F741B219ULL, 0x5D0A3A7AC4CB13A8ULL, 0x072E27350248F8CCULL, 0xE8151F8B77559BC8ULL, 
            0x218D2922BF08A4D9ULL, 0x6D76739A3EA0C60DULL, 0x79D733A800482F93ULL, 0xC461937A17364D13ULL, 
            0x4D7BC6513952C714ULL, 0xF0B8F7B694805BDEULL, 0x3084E136F8914697ULL, 0xA85A2C66A03FEE5DULL, 
            0xF17289B937E4B847ULL, 0x4BE67452C747E5F6ULL, 0x4EC8011F3B1F5DBAULL, 0x66D7A695AF736775ULL, 
            0x71B3C780908F3D36ULL, 0x446C22554C8D04E6ULL, 0x1E960EBD3D124415ULL, 0xC160D9303C537429ULL, 
            0x83C99CDE95D19775ULL, 0x9084B89EAC37D226ULL, 0x2DC222771273BF46ULL, 0xD6C65FFB2CF647A2ULL
        },
        {
            0x1827F0CFD3DBFB48ULL, 0x13679613D7F99A11ULL, 0x054F972EF3BC2926ULL, 0xBE62CD943F837F0AULL, 
            0x50DDCD4E92BF90C1ULL, 0x3B6427ED8B5CECC1ULL, 0x8717638D960FF29AULL, 0xBEE3B8C3156A259DULL, 
            0x5029F2DD0A377618ULL, 0x1A44CDF2AF1F9961ULL, 0xB47F80FA94E0A2BCULL, 0x70EDB0A6DA7C13B7ULL, 
            0x8354CBD2609B8B73ULL, 0xADD7297186C7CF29ULL, 0x09DE9C2B757254ECULL, 0xD89EB0C8995CC4A7ULL, 
            0x1EFEE8CDD980DC7CULL, 0x3B2FC9A5CE68C391ULL, 0x773A4039D034E79FULL, 0x1032CE10707EFB85ULL, 
            0x5B82D6E31DE0FAEAULL, 0xC10BED5EA9C1117AULL, 0xBF3BFCCE55317CD9ULL, 0x0E479AE480AB1722ULL, 
            0x6A4DEB0C0EC71CF7ULL, 0xEC487451F9AF4B31ULL, 0x1306C68E8CE05686ULL, 0x400D12710884CC44ULL, 
            0x3AE6336D8FA2B4F4ULL, 0x5C137EA16E5DFA0EULL, 0xE12FF974E211EE01ULL, 0xEC51759CDB1A85C5ULL
        },
        {
            0x87E8E8325F4004FEULL, 0x8EF9C6C7A7B65202ULL, 0x640F123D2BD8E0A0ULL, 0xBF8312EE6A864F23ULL, 
            0xE37DEC128E7D5EBBULL, 0x4CDF81FC72E7DF1AULL, 0xB0FA05F67E833063ULL, 0x4CD61E0A8E6070C6ULL, 
            0xCF2A8D9C9183ACCAULL, 0xBE61D40B0F4726FDULL, 0x2D5BF2FF15A6702EULL, 0x4A69A40FC17237A3ULL, 
            0x6663AB0F17A9A827ULL, 0x5D7263EBA18BA56EULL, 0x085CFA26C96C2D6DULL, 0x17826FA72B1A9C0AULL, 
            0x9F9888EF3053139BULL, 0xE60AC6FD290F511EULL, 0x9B0EF6145B2C172BULL, 0x1D4641FF139DEA3BULL, 
            0x903B303221F9CA00ULL, 0xAB4993EE3F142CF3ULL, 0xBCCB1DAC3A7EA664ULL, 0x75FE9445926E8086ULL, 
            0x3E2F320EF3368AA4ULL, 0x9E270389FE83CEEAULL, 0xB34C3CF50B2C5762ULL, 0x37B077D817F69633ULL, 
            0xBFF1D341B478BBE9ULL, 0x9F07095CE97B93C3ULL, 0x3047832BC4AFE37CULL, 0xF83DDC326F048FCBULL
        },
        {
            0xAE609FE34DDB7FACULL, 0xB316A74361E57012ULL, 0x343E88488AC5C781ULL, 0x25DEAFCE641096EDULL, 
            0x131A315DDD6B21A9ULL, 0x778F67CAF5F1911CULL, 0x65BEC4D785AAA0F6ULL, 0xC6A71A2D45538C31ULL, 
            0x906141D7EEE65101ULL, 0xA5CC8787FA36B744ULL, 0xFF8EE79F9C4CFE9AULL, 0x1767C82B3FC99002ULL, 
            0xECEC7D2A178968A4ULL, 0xCB3C2E55F463EFEBULL, 0x43176617D7C931D0ULL, 0x73AEFBCC37927DA6ULL, 
            0x972E4EBA510B022AULL, 0x9EC57ACE7F285D3CULL, 0x0B863AB9E221AFE8ULL, 0xC23BFFBBF5848610ULL, 
            0xF5564E88F64EB389ULL, 0x8887430E9E939A47ULL, 0x64C1DA68F4592185ULL, 0x511C19823373CF71ULL, 
            0x4BE6721CA92D018FULL, 0x5FFCAAE01FE77B24ULL, 0x35E93160EB927902ULL, 0xB510D3BBBB78B401ULL, 
            0xCD22AE1969BD2277ULL, 0x860C9BE91FA586E8ULL, 0x8D55AB0921ED640AULL, 0x02A12D64EE90B8A3ULL
        },
        {
            0x144F1DAC9407B3ECULL, 0xFBDC0FB09BC55F42ULL, 0x1C59E27C24779235ULL, 0x60086CF53DF59198ULL, 
            0x92575FE3BD096B78ULL, 0x4E39F4A359D64764ULL, 0xB55D3B19D68E133FULL, 0x2C10A183EE759070ULL, 
            0x6CA1BFAED0DE009EULL, 0x71289874FFE17843ULL, 0xDD8BF28E7C11DAF5ULL, 0x1BFAE38D47131273ULL, 
            0x0D24D55C3EE199CFULL, 0xB372A4642194C927ULL, 0x5787B496A23D462CULL, 0xC91E6E368A7F5763ULL, 
            0x85AF2C37526C759DULL, 0xBD5D6861972D61B5ULL, 0x617413723B1EE8A8ULL, 0x43F712D21FAC3668ULL, 
            0x13205B1D45F2AF41ULL, 0x1E9B993CF8E824EAULL, 0x4791E7F55C79A779ULL, 0x46563485A237BD65ULL, 
            0x02836C7C5AFB1EFBULL, 0xF29F09B49CFBCC1BULL, 0xF8B057237AF6F632ULL, 0x6BB4CD9A6DFD5100ULL, 
            0xA1AF2794DDA43CF7ULL, 0xE4E425A63F0B4F36ULL, 0xF28C89DC20362977ULL, 0x40F1170DB72E274EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseCConstants = {
    0xFAF99FD981647524ULL,
    0x928008FDF49D9076ULL,
    0x6411DE921AB408B8ULL,
    0xFAF99FD981647524ULL,
    0x928008FDF49D9076ULL,
    0x6411DE921AB408B8ULL,
    0x2C7B30357924FAC9ULL,
    0x741D7CB472FDF8F1ULL,
    0x9F,
    0x8D,
    0x1F,
    0xB2,
    0xFE,
    0x54,
    0xF5,
    0xFB
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseDSalts = {
    {
        {
            0x94058BEB7468EC2CULL, 0x468314905A2EBCFEULL, 0x95D27781583753A4ULL, 0x4E4061EA8676A671ULL, 
            0xBE7DD25B112A40B7ULL, 0x77C1D66265CFC92EULL, 0xBE6439143531C3C0ULL, 0x40E1836638C2B522ULL, 
            0xD8103DA0ECBD14AFULL, 0xC18C53BC7773F4CAULL, 0xC89D62FFBFE27FFDULL, 0x89494891A9AE5902ULL, 
            0xF03C2B9A727A1DFBULL, 0x0144073638C8B4C2ULL, 0xC3ED2E1CCADCD3ACULL, 0x3D450BB8D616B02FULL, 
            0xC7C3CDEE5A491F45ULL, 0x0F657BD34C77BF27ULL, 0x8E82ED02198D3C05ULL, 0x1B893528A236F276ULL, 
            0xEA1D58A5BAF9B430ULL, 0x7A270435CB2AB77DULL, 0x7CE67D70B1727FB4ULL, 0xB6E8FB6E8993998EULL, 
            0x3D88B1A0D6BEACFAULL, 0xCDE0C43B00C4E0F7ULL, 0xD09D98209BE24E90ULL, 0x20392847AE08236BULL, 
            0xFB4422A68452EB13ULL, 0xCE7B85257D6E3771ULL, 0x3136956A70C84324ULL, 0xD43A83EC38FA9CD4ULL
        },
        {
            0x4FED938C37CAD548ULL, 0xE8DDC335D912B177ULL, 0x4FE75F3433F3D97EULL, 0x649D767D3166481DULL, 
            0xE0B34607C2385C8BULL, 0xC4CF5ED604237820ULL, 0x4D94B9F7BA27D5D1ULL, 0x47E9413F6153DC57ULL, 
            0xDBA417C15D6F99DDULL, 0x6ECD479A919EDD50ULL, 0x5FAB9BBB9AF5FCDEULL, 0x262F6405F85616F4ULL, 
            0x0C65F8D16937BD53ULL, 0x86D0997C6093AA14ULL, 0x6CF9CAA2B1EA002FULL, 0xF6D9B0412A656BD1ULL, 
            0xA7E3F622DB0C4260ULL, 0xC68F284B4367C2FEULL, 0x847F61D9E34A99F8ULL, 0x2EBE5F6DACC8C4D9ULL, 
            0xC52DAA00175269BAULL, 0x03EDD4F0EE85D854ULL, 0xDB69BED223E86041ULL, 0x0DBC8B118F29B279ULL, 
            0x3EAB605713250102ULL, 0xB6A08ACBF30AE5E7ULL, 0x13E88110616EA5B9ULL, 0x221A65713C03400EULL, 
            0x1BFBDB4A7452CCDAULL, 0x478A9739F51B0EEEULL, 0x92BB765346468660ULL, 0xB7C67FEED669FFC1ULL
        },
        {
            0xBB5F7142D7317095ULL, 0x825594D1B6E0EF40ULL, 0x39FB23ED94B69823ULL, 0xB0996FFDC62DE119ULL, 
            0x763240090713A475ULL, 0xF7B4CDC247AF0301ULL, 0xE9FBAAF4BB5E6A51ULL, 0xCC62F9D286E1CE62ULL, 
            0xA0D5F7604F6C6116ULL, 0x87BDB604E5617EECULL, 0x13EF8DDEFFB7A827ULL, 0x1DECB40E79B87663ULL, 
            0x3F3DC3BA650E563BULL, 0xF96189434D464F50ULL, 0x92E8CBB5A2CE5DEBULL, 0xCF532B1DE392DFE8ULL, 
            0xFA12A189D11D0169ULL, 0x83957472F8EA49B1ULL, 0x417772523EA76A3CULL, 0x34CB2D2334301B9DULL, 
            0xF1242FFF688E46AEULL, 0x6CF71C47B280C776ULL, 0x0FC72C73375DD7F3ULL, 0x7A4B6A0EC317092BULL, 
            0x366658ECD33E9659ULL, 0x63CA9EA60574B093ULL, 0x0411EF570228607CULL, 0x5470BADA8981E99EULL, 
            0x31F78B5A410D130EULL, 0xCE58B9261F384ADEULL, 0x4DE463708D29D938ULL, 0xA241BDD84A9741F0ULL
        },
        {
            0x6649CC2535E9EBFDULL, 0x3508AB5FAE1ACF51ULL, 0xE186DD2F9606CE96ULL, 0x7D3D6C50E4C031C3ULL, 
            0x8EB3B0EE576815D9ULL, 0x6463A2C9BECF2E15ULL, 0x1C8FBDFC1FFDC3A9ULL, 0xD9EA22A6FBB02470ULL, 
            0xCEDE9FA042F5AFB9ULL, 0x939549AB34851AEBULL, 0x1FC60E9E1A302659ULL, 0xE780E0725E6AC986ULL, 
            0x46E9E3318F955A70ULL, 0xF0B9D338906999B4ULL, 0x6696B693F5772254ULL, 0xD9D5E3E23D47AF11ULL, 
            0x89AD4662F69D70E6ULL, 0x459AED10062F8CF8ULL, 0xEAEA0E72D77ACB0CULL, 0xA37B33217994F76BULL, 
            0x89E87C24CC4CEC7FULL, 0xD2B704BF798BA6E5ULL, 0x72448C5D72F2F05DULL, 0x082BA21B7DAB5446ULL, 
            0xCAD9CFEF41956C56ULL, 0x4FEF91BCE254D939ULL, 0xFC3C2B30BF8B069FULL, 0x007739A8F389CD58ULL, 
            0xED90DF001F3D2FCFULL, 0x1AA691EBF08323E9ULL, 0x66951ECBC0ACDFCEULL, 0xF7306E23438C2A1AULL
        },
        {
            0xFEC087B30BBA4B14ULL, 0x3B3154468C46C487ULL, 0x444E03DD249FE767ULL, 0xC2DD64695ADB7367ULL, 
            0x3ADAF8F197BCA73AULL, 0xB47E90826FA87104ULL, 0x35B1931BA345E80BULL, 0x0F617722054CEFA8ULL, 
            0x701D697479CE13D9ULL, 0x419B445FD63918EEULL, 0x66F022E92A23E97DULL, 0xFBB1550D0934CB67ULL, 
            0x2B6572DDC77C1FAEULL, 0x4586A64DF2985D8CULL, 0xA243CF62E60C995DULL, 0xFEF6E137D1D6A0C4ULL, 
            0xEB844D80A29CF48AULL, 0x3CF02C546325AE26ULL, 0x0FC8ACC4C387BA06ULL, 0xEF86DD0C6686A6BAULL, 
            0xC652F12FBCCCD418ULL, 0x375914CA1B911760ULL, 0xB5FF7BFB553E0945ULL, 0xC856E7177FA7AB3BULL, 
            0x7356657F619B9ADDULL, 0x1DA7A8CC6E2E96ABULL, 0xAE6C5794646EC370ULL, 0x80ABDBC13D2E3C8BULL, 
            0x0D457821B9FFF242ULL, 0xEE0E4E85B4278B63ULL, 0x914036DD39F0F123ULL, 0x838B4FAE3C0367D4ULL
        },
        {
            0x995EA700FA0AF6EBULL, 0xE165489A62C9EF6FULL, 0x8126D47360F46ABBULL, 0x834B2EDFB8C28AF3ULL, 
            0x56C64CEED68ADB19ULL, 0x184C8C7DEF51606BULL, 0x0FABC2F5A697F93FULL, 0xBB381318398317FDULL, 
            0x04C6FDD645D94FDEULL, 0x67622B10494A9F71ULL, 0xFE3807097B1D37DEULL, 0xEA60CFEE71826800ULL, 
            0xCEBA10B8DEC8B7FDULL, 0xE79E58A7A06EF739ULL, 0x309491E7B4E8C230ULL, 0x1901B7A3633B9A01ULL, 
            0x4072B479040D3DC7ULL, 0x5E0C3678E97F6562ULL, 0xE0153790A382DA9CULL, 0xCC3394EAF8BBF6FDULL, 
            0x1F3DED04C80744E7ULL, 0xBE482F353A959F01ULL, 0x58CC8EF045653C90ULL, 0x4926040ADBD10590ULL, 
            0xD301F65A79BBAF1AULL, 0x31408918B322D286ULL, 0xE4ACF770FF5F9AC1ULL, 0x8005170AA548EEC6ULL, 
            0x9361236C2F1EB416ULL, 0xA138F3D20AE2B0A2ULL, 0x79E8F7917229017EULL, 0x3FCD145F8EDF9893ULL
        }
    },
    {
        {
            0x56BEE6BEFF41CA2DULL, 0x8D01C6D27B183947ULL, 0x48048CDCB88FBB71ULL, 0xF8693E13D6079E74ULL, 
            0xE500041355B76C0BULL, 0xC79F64509023F477ULL, 0xB4A9D53144A797F3ULL, 0xDE2131380C3312B2ULL, 
            0x65BDC7B51D7AD5AAULL, 0xD7ABA7EA761FC379ULL, 0x62C223AF20B7A87DULL, 0xCFBB5195CBEA2D79ULL, 
            0x79ED6E3741D34C35ULL, 0xDAE3A56E6B0D0332ULL, 0x7D75825B14C31E54ULL, 0xFA15989246FCD55CULL, 
            0x6CA3698B964C251FULL, 0x55FD9E2DF7E7567AULL, 0x905F8010AD4F6A09ULL, 0xF5D2B6B294B940EDULL, 
            0xB8F6AE356C336EF3ULL, 0x7BD025E0C5F2E75AULL, 0xA42034B2D36ECDFCULL, 0xBCAD2B6975706D55ULL, 
            0x729EB979B983EB02ULL, 0xAFD1F0AC00940B29ULL, 0xAE60CF89169ACED1ULL, 0xD8436F9C1905D8CDULL, 
            0x847E294A68AC8E39ULL, 0x88EBD4414A0CD669ULL, 0x1BF17685E4859919ULL, 0x255036501833135FULL
        },
        {
            0xA215C90D599F8885ULL, 0x71AFFAE674E2CB6AULL, 0xDA537A985DC78A92ULL, 0x1E6D6AB5EC9B02B0ULL, 
            0x098A0A052971C60AULL, 0x97E576331D6F8802ULL, 0xA498267E000214BBULL, 0x18F6D8479A65A37EULL, 
            0x63F5A59B3EB8EDFAULL, 0xBAD4D3F662BBE9A8ULL, 0x6E74126B97E5437FULL, 0xA47AAAD4F9329A8FULL, 
            0xAC95D91C181D79EFULL, 0xE78970BF48969793ULL, 0xCCACAC4B4CD55588ULL, 0x8B35A496E805C742ULL, 
            0x3621C617759180E6ULL, 0xDF716F68317279DAULL, 0x9EBFFD3D0D179B6FULL, 0x19301949446D4310ULL, 
            0x920E91A046BFAB0DULL, 0x17B6A1C5E14CDF9CULL, 0x1A084E519E2315B0ULL, 0x38AB88D02F94FC9AULL, 
            0xA5C1F264A58EED22ULL, 0x94EB7338A0768C26ULL, 0x356190E73F053AF9ULL, 0x41AA043B8F138BE3ULL, 
            0xA8AB515BE18DE180ULL, 0xAE33AA779BCCA0E2ULL, 0x40496F65E4298A82ULL, 0x3A38A7E61479D163ULL
        },
        {
            0xC12C9B4EAB7696FFULL, 0xA24818C9552374CEULL, 0x5BE533FD3BF61440ULL, 0x38C0B838816B3C99ULL, 
            0x8CF0A135E900CA85ULL, 0xA5D3E50C9AF1BF95ULL, 0x4962206DC47BB2B8ULL, 0x3925596FCA59BBBEULL, 
            0x5D2A010DD3C81D53ULL, 0x4C6B5CE31B2F3636ULL, 0x4455BA4A7DAB722AULL, 0x9CA819C20B892204ULL, 
            0xDCBAD7DE2020B435ULL, 0x4CCAC1D9265D0BA1ULL, 0xB3695D7904B9F5D9ULL, 0x4DD9A519C5F023D9ULL, 
            0x93FC3044FCFD88B7ULL, 0x738DCB184A7DEB12ULL, 0xFAC09113BB4E1573ULL, 0xCF2E3B90B651BE61ULL, 
            0x30A1849C2699AD2BULL, 0x5251C99DAFABFE14ULL, 0xD74C2F32722A366AULL, 0x9930711CA54BE37EULL, 
            0x58131C4DCA4E95F9ULL, 0xCB81DFF2B7EF45AEULL, 0x3D11891FFED67286ULL, 0xDF297ADBDA6CE72AULL, 
            0xC6A09F9AF78B8A7DULL, 0xC5AD4412C8A79126ULL, 0xCFDE763DF0F01AE8ULL, 0x59DE06B7A6E8A518ULL
        },
        {
            0x09F1748466F5623CULL, 0xC2E8C5691E4DD605ULL, 0x7C191D2F44F29DCEULL, 0x38199FA99051F0BDULL, 
            0xDC8540E632F4EE38ULL, 0x7B9D6BA52E7A4FCAULL, 0x6BD0D21C3FB379B1ULL, 0x8507B2D33F533EB4ULL, 
            0x8D0AA204E25CBB44ULL, 0xD56617CCCE19B34CULL, 0x3C9DD9BD7556BE71ULL, 0xF9E6E73422B39B78ULL, 
            0x4EE31F68DE3CB114ULL, 0xBB46AC16FB8A00B9ULL, 0x2D1F9FA2F463D7D2ULL, 0x21F1B8748D9D02ADULL, 
            0xA966B96CCC0F1C01ULL, 0x57AEA0014CDBD36AULL, 0xA91A404233C06DF0ULL, 0x64DD40EB80082D2EULL, 
            0x891ACE86FCDB17BCULL, 0x18DE7EEB69CD3530ULL, 0xF4577F0523193225ULL, 0xBD79B768FD5D9F57ULL, 
            0x3B6575077A2BC6D8ULL, 0x3CC9723BA93F5D08ULL, 0xA748DB86BAD840A6ULL, 0x660C2D0B8929EF22ULL, 
            0x48E61684B6A7BB58ULL, 0xE763A13EA006962BULL, 0x0E78084CB1864419ULL, 0xF50AAC14EE774724ULL
        },
        {
            0x676F9BB29652B420ULL, 0x0BCA8EA3042ADF40ULL, 0x8E9B88D4A98BD006ULL, 0x0D86AFF3035BB80DULL, 
            0x7C310E6BDB678D17ULL, 0x10C6A0B87DAF5BA6ULL, 0x7E0C6C289965AF92ULL, 0x9C7B0F905BCC7456ULL, 
            0x2744C2EF4327AFABULL, 0xD6FBB8C8059632FEULL, 0xF824582C78643670ULL, 0x95CA6BC2FB41AF42ULL, 
            0x2FDF071737B9890FULL, 0x372AAF93BE30D826ULL, 0x8C8F275149F4F813ULL, 0x2D2F12426C7D6ECDULL, 
            0xF863CDD10BB1FA87ULL, 0x582CA8B8C8EAA486ULL, 0x641A3B37DFF1D9E7ULL, 0x0C962267B87A535CULL, 
            0x5C94BAB223BAFF7DULL, 0xB6AA55D15C69B33CULL, 0xF2492396186E0D1BULL, 0xB900C9B1B20F985CULL, 
            0xDF21E9D500AF40EAULL, 0x92F52369319A0C3FULL, 0xF2590D56E10DDC76ULL, 0x57628364A34B3DF4ULL, 
            0xD31527F5EF8C4C1AULL, 0x9F91E3EF354F7CE3ULL, 0x7390BB64575AF73CULL, 0xD998598D0C22F253ULL
        },
        {
            0xA398B36A89D55CE1ULL, 0x3A0BEFF2A1829A0AULL, 0xB8B9D16668CCD074ULL, 0x969A85F44C9F9468ULL, 
            0xCE75FDE07A5F7E55ULL, 0x3F5FBB2C18D044ADULL, 0xB2F1AE10064368A4ULL, 0xC6111A83FCED483DULL, 
            0x53DD2CBC8AEC1E14ULL, 0xE57F8F8D30DE9512ULL, 0x6412CD8471484E9AULL, 0x929D2A6E699B78EEULL, 
            0x7096730B68732641ULL, 0x0585CC8269FF8D2CULL, 0xC2D0C12FFA52F9FBULL, 0x7587ABEF7C819F80ULL, 
            0x81D12B8EF2350DD0ULL, 0x5A403182C93FA01CULL, 0x3F23CA0A7D52E9D4ULL, 0x242B47BE042A1975ULL, 
            0x2C836809E31BAA16ULL, 0x80F050A0F586FF91ULL, 0xD44A96F78EFBDC5FULL, 0xC08DB824E10319F0ULL, 
            0x54547362C8F2AFA5ULL, 0x5B93AD39F80A64EEULL, 0x5786FCE2FC2FE190ULL, 0x85CA7658E24318E4ULL, 
            0x24177665B0BDBE70ULL, 0x67CE799B34C92B4EULL, 0x47FAA77EC2FB815FULL, 0xCD9B3CB5C142AA38ULL
        }
    },
    {
        {
            0x36A47D82D7D8848EULL, 0x55D32EEF72A12D88ULL, 0x65FE1F2445371F38ULL, 0x43243909D55EDDD1ULL, 
            0x358F04C1052DFCE6ULL, 0x5027480F98EB00FEULL, 0x40D5BD97318D861DULL, 0x0E030117F4C22A88ULL, 
            0x81512039284EF315ULL, 0x423349E36733BFCEULL, 0x2F0D2F446693779DULL, 0x0ED63F962900186AULL, 
            0xD59C65E3631767A9ULL, 0xB44DBAA9ACDAB202ULL, 0xC53FAD133491BE4DULL, 0xB55480C5F30BCB77ULL, 
            0xFB9DDE93A32C3010ULL, 0xCA2BF33689B9859DULL, 0xD91E8D03F2A2DE5CULL, 0x44E268C9794A8240ULL, 
            0xE6AD8202B2452625ULL, 0x48A98AC05CBA75FBULL, 0xF72164F2B0059267ULL, 0x61B702EB42936141ULL, 
            0xA76F34192B7AB353ULL, 0x32F998F678E1BC38ULL, 0x0D2EE4C35A4B9DA2ULL, 0xAD1821396B51CA40ULL, 
            0xCBDD8AD4F2BC2296ULL, 0x849D3C810137F5CEULL, 0xF486F5ABD4EF38F0ULL, 0xAAFCF88E95FCFB4BULL
        },
        {
            0x399EB1D19F4059DBULL, 0x3327DF9AB2DA5161ULL, 0x0DC7673313829BDAULL, 0x305927F9C2FA5CA6ULL, 
            0xA9F96B2153B7F3B1ULL, 0xD644EEAFAA56C55CULL, 0xC56756CF4CC9E115ULL, 0x34EDA53AC99B3287ULL, 
            0x9B56C1245A10E9EAULL, 0x2CF3EE57E88E019CULL, 0x2D2E2F107E206747ULL, 0x2265A147DCA71025ULL, 
            0x3397E28AAC410915ULL, 0x14F9274CA3152BDCULL, 0xA78774CD376ECBDCULL, 0x11304A3837559953ULL, 
            0x78C5F05264D9AD73ULL, 0x6248111BDC5D73E1ULL, 0x0E4DAFD2721F6490ULL, 0x3B39BF25558A0A5FULL, 
            0x01C6F3AA57C92EB9ULL, 0xA79B518AE39398F2ULL, 0xD68F74663478B9F3ULL, 0xDE3F8C5BCF3BFB9EULL, 
            0xDCE8A1D6ECFF3461ULL, 0x27BDBC5E86EC2BB1ULL, 0xB82D112475F81332ULL, 0x9B4E7FBC0FFD2AB7ULL, 
            0x696347D694B7FF9BULL, 0x60BAF993AA019F6CULL, 0xD2A21912D5E9CEA8ULL, 0x89F859D35CF95A3CULL
        },
        {
            0x334BD4E28D2E358EULL, 0x07B4B883A3A4750DULL, 0x481291D83E7CD773ULL, 0x9F614F689905BF81ULL, 
            0x592D37687A4B4394ULL, 0x770D0EF64BE34AC7ULL, 0x1FB0CFC76CC54003ULL, 0x188E7D8BC4178B57ULL, 
            0xF2869A880D638DD1ULL, 0x7980EBF84D59B07DULL, 0xB98AB257B22F3913ULL, 0xAFE881BDE91C9ADEULL, 
            0x0FD24BC755E040A6ULL, 0x6851F0E52B8FEE7BULL, 0x49A19192D2A87293ULL, 0x84E096DCE5787B56ULL, 
            0x4DEA0CB709260C02ULL, 0xA9DD2BF1E2E6ACBBULL, 0x351C801BA48BABD6ULL, 0x8C1E743E4CF1A702ULL, 
            0x4403A6E1239D92E3ULL, 0x71E4E132C6177861ULL, 0xE5C24A2406E20396ULL, 0x5E523F0F489831C7ULL, 
            0x54D05608FF8B08E9ULL, 0xCCDFA2B5DD0C07E5ULL, 0xDA94C58DE92A3FBAULL, 0x74FD3C224CEA71C2ULL, 
            0xB32E54366517814FULL, 0xD306D86B7CC67951ULL, 0xEBB43727426C4178ULL, 0x61DC26AE890F9ED1ULL
        },
        {
            0x23C2C8FD35B153ABULL, 0x67F1599BE661ECACULL, 0x3DD618BBE180CD9AULL, 0xF61B6CE1A0CFE414ULL, 
            0x3545BFF56686F9EFULL, 0x23C49616345F85D1ULL, 0x2D68CC5D71273564ULL, 0x14CB2C38FC34DA28ULL, 
            0xF93770C587A10645ULL, 0x08F17845B62B5637ULL, 0x1F0AF61253B68F4DULL, 0x0E04CD1DFA5948E9ULL, 
            0xC523D1BE86349682ULL, 0x9E0C6D15EE9B46CDULL, 0x330CDA05D1632841ULL, 0x611E53BFD267A684ULL, 
            0x2A935706177CAD4FULL, 0x3E012A7D6CE15EC3ULL, 0xF8E646A1574D0773ULL, 0x620CA031C234E246ULL, 
            0x9AE21EBE578206C3ULL, 0x50AC0B4396389A0EULL, 0x194D272E3732CFFAULL, 0xDB07908C4C947300ULL, 
            0x24465F2A22E91289ULL, 0xA5352DE2D83FFD2BULL, 0xC5B9226F686D5475ULL, 0x21FB5F47FD8770D9ULL, 
            0xEFAF62C63E0F4F12ULL, 0x313FA029B9A17D86ULL, 0xD484469242C354CFULL, 0xA32B63CCC139206FULL
        },
        {
            0xFE160952D4FFBEE3ULL, 0x748D05186FFA8CEBULL, 0x4835697D2CE1359EULL, 0x9A60EA08FB2D8A11ULL, 
            0x31B26D3E0F5F5C2AULL, 0x77C751C048D9E786ULL, 0xC8AB0F378DF3078CULL, 0xC68B4EF5C5516EECULL, 
            0x591E18FBE1547642ULL, 0x4F43E4562DDF4526ULL, 0x8ED406D584C7F4EFULL, 0x5239A012F05C5EE7ULL, 
            0xC8A5C9BA16A94755ULL, 0xE0316C709BB93FC2ULL, 0x4D4ADF1C81D17676ULL, 0xBACC3565A399B336ULL, 
            0x36F9D87930E314E8ULL, 0xE707070CE071FC0AULL, 0x521D14A1A9BE52DBULL, 0x37D19AC40238B625ULL, 
            0x3D8B2CD29F442C5CULL, 0xC9B02E84AED1E53CULL, 0x2BC11067516C22D3ULL, 0xEC2A0291CC29FC92ULL, 
            0x6114E68ADCB044A9ULL, 0xEA1B3F63EBF4DBB6ULL, 0x1684E04B07D9A3BCULL, 0xE033216260E0C8D3ULL, 
            0xF958680CC5A059B5ULL, 0x87E9BF336943B64DULL, 0x99EBD2C30D98E859ULL, 0xFF857D7C2B2B410AULL
        },
        {
            0x9DAA68120A023C8EULL, 0x580668DB06A6B176ULL, 0x0E63693EBC12BF2CULL, 0x10814A24A4E822C5ULL, 
            0xD3D8783B250B1BB1ULL, 0x53A6D6AF16F04E7DULL, 0x41101AAF728E744CULL, 0x1A8FC132CE2C5376ULL, 
            0x3E289438FD4B2130ULL, 0x886BBD4DEBFED69FULL, 0xFCB64FB996774622ULL, 0x7BF056625B4D7037ULL, 
            0x7BA7F4E1501CFCC7ULL, 0x4076D3AB9EDD2AE4ULL, 0x71AA89F7436642F4ULL, 0x48DC4B91A5C76A37ULL, 
            0xD0EBB4A4B99FC77FULL, 0x83F438DC53DB1A19ULL, 0x9A8E446698E6F50BULL, 0xE2D82F9EC09E4B52ULL, 
            0x088AB5454F55EC47ULL, 0xAF77A536B1966F60ULL, 0x9D7D11F643EEC6ECULL, 0x3C4861161CC3C21AULL, 
            0xA51D7165B9FDB11DULL, 0x219A2E87BFECCDE4ULL, 0xC4832EBAB5B242BEULL, 0xA08BA6CEBE4DDB61ULL, 
            0xC9EFFAAD924156F6ULL, 0x6E69CB0861A1DBA8ULL, 0xD7218DBA599E6EFCULL, 0xE0C438C0DE6FF9D2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseDConstants = {
    0x606EBE05DB2AEC7BULL,
    0x3C42345F5BD62C4EULL,
    0x72039223A7ECEC32ULL,
    0x606EBE05DB2AEC7BULL,
    0x3C42345F5BD62C4EULL,
    0x72039223A7ECEC32ULL,
    0xBB5532054BA51B58ULL,
    0x4D415BF132AD2134ULL,
    0x19,
    0x01,
    0x01,
    0xA1,
    0xC8,
    0x3B,
    0x8A,
    0x19
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseESalts = {
    {
        {
            0x970B8A3F3547B204ULL, 0x9018769305228165ULL, 0x8EFCEED605A899E8ULL, 0x3FC54EFDB119CE55ULL, 
            0x3A654D683C7C4535ULL, 0xD79C1F58A84CAA63ULL, 0xB916907A1B3CB3F8ULL, 0xF26CDBF396E7AB06ULL, 
            0xA9DBB716CD728777ULL, 0xC502E41475959608ULL, 0xC4069EE8043343C8ULL, 0xCBA4F586DF2E5837ULL, 
            0x77F647896D712FB3ULL, 0x80A85169D6B566E3ULL, 0x5E5BDD27D2CA3059ULL, 0xFFA9ED64C1E4C60CULL, 
            0x7B330AB54C15371CULL, 0x05D7F8F0A242399AULL, 0x5DE6E1EE0BD42E69ULL, 0x28585CFECD2510BEULL, 
            0xE633C83FA5B507D4ULL, 0xDD2CD74472980E8EULL, 0x463E0A4DFA248558ULL, 0xD2FE9D8B13B7793EULL, 
            0x3991E0D3B318FEF2ULL, 0x733127F3AE974D7CULL, 0xD386BC0CD7B8E6F9ULL, 0xC04F9431057D8D63ULL, 
            0x3B22947DF63CA58FULL, 0x831767F3678DA68FULL, 0x6F87F3EB87B866E0ULL, 0x0646250546A6F7B4ULL
        },
        {
            0x909C12F3D31818EAULL, 0x05D258720164DFC5ULL, 0x4DE4FA3FFB317046ULL, 0x02CEFEF6E31A6CAEULL, 
            0x16AF4BE45F3673BFULL, 0x33076B47D8C89B8FULL, 0x3B489E7FA402B340ULL, 0xFA7F9B4BCFDBCAC2ULL, 
            0xF5BD95CDB7738C4FULL, 0xBE05FFFF87077EB0ULL, 0xEB786CA8BD0C77F1ULL, 0x875A29F9DA14797CULL, 
            0x9A2A02903EAC958EULL, 0xB49048DDFD81D9BCULL, 0x7EB7597C91F410AAULL, 0x40465FE10E0B2EC0ULL, 
            0xAB3857813130FCB3ULL, 0x0B5DF85C679BFE86ULL, 0xA5C91E10B28D7A37ULL, 0xA2D53A813147897FULL, 
            0x8010C3944E7B370DULL, 0xDB265B1283FB6D67ULL, 0x0BB60572C7FB9962ULL, 0xFBA419A758C9EEB5ULL, 
            0x41F311C7B8CCA8F8ULL, 0xEFDB2A8CD4ED3EF4ULL, 0xA3FE86A110E0D6A4ULL, 0xA251F3FBF03C1323ULL, 
            0x420A449B60E2204FULL, 0xC634311930FA8DA6ULL, 0xD49322C8082CFAAAULL, 0x6A93C774017E94E7ULL
        },
        {
            0xE43EBFB8C661EAA0ULL, 0x233C90A0DC426080ULL, 0x3A518BC23729DAF8ULL, 0xB9676ED3526967C6ULL, 
            0x793DD87E38C79CE9ULL, 0x118EAB3154F0FF3AULL, 0x6234B8DEAEAE3A0CULL, 0x6AF61405774A1F15ULL, 
            0x0F6CA977F3480B26ULL, 0xF2C4177410BF1E33ULL, 0xE41A9A3C3ADB1240ULL, 0x85D7E7034C5E3C53ULL, 
            0x4A7A18F8C7272A51ULL, 0xA38C6E35DD131F00ULL, 0x91430BB8D4CC643BULL, 0xFFD314C5A8CCF187ULL, 
            0x0D4253927298C2D8ULL, 0x1077349B8CFBB329ULL, 0xAAF17F617575E696ULL, 0x55012ACC465DBBC0ULL, 
            0x6064E3E7664A0E52ULL, 0xC4E9F7BCC9B0C66BULL, 0x2B65413971052A1AULL, 0xB54B22A380C255B1ULL, 
            0x781754E0316BBAA7ULL, 0xE462217A8CB3E1FEULL, 0x60B19C2BB16E9288ULL, 0x3C25E6C7D585EF6AULL, 
            0xAD1DEEFE25919AF5ULL, 0x1155B85F173168D9ULL, 0xE3C36A01CF91DC69ULL, 0x47C629098AB905B9ULL
        },
        {
            0xAE240023CE632648ULL, 0xD7E024CF9220B76AULL, 0xA6867AA5B34B89E8ULL, 0x7E780C667FD17308ULL, 
            0x1628C2B42E8ACB0FULL, 0xCC1E0D19B2746679ULL, 0x6A13B08FB32F4F02ULL, 0x89CA940DCE820986ULL, 
            0x127EAEB990EBFCEBULL, 0x6A229B71E35E677EULL, 0x232C53C27A83541AULL, 0x7629EDF9AB0037F8ULL, 
            0xE18897C8F9A5DEF7ULL, 0xEFBA734E0A8E7B70ULL, 0xB9C6C1000580B0A7ULL, 0xE73261B47D763544ULL, 
            0xF664268F94283566ULL, 0x6AF28F6C7DF0733BULL, 0xBFA1262D763F2C5DULL, 0x260CFFE26AC97BAEULL, 
            0x42CCD600619228F9ULL, 0xD65706C160CF09ADULL, 0x78C38A89A2B203D4ULL, 0x6C0A2429E92C89C4ULL, 
            0x57F92FAF1A884EA3ULL, 0x9BEBD82CFDF7E3A8ULL, 0xB410B686E0983525ULL, 0x2421B4C2738836B3ULL, 
            0xACD910A3BB620E23ULL, 0x415D87671A5C6804ULL, 0x417A94990A4D0FFDULL, 0xF2BF573638D70BA7ULL
        },
        {
            0xB6CA62903F4BB4B6ULL, 0x67C2AE502DB9DA6FULL, 0xE7D30CD00BEE6A91ULL, 0x9F66213E4EFA0927ULL, 
            0x14ADAF0C81FB8938ULL, 0xC673624CEB92A055ULL, 0xB5F72BFB87317D79ULL, 0xFDD3548640650340ULL, 
            0x095AB4C105636525ULL, 0xB8B4AB973EB8FADDULL, 0x124620BD49E0A471ULL, 0x87D2BD689626D7FCULL, 
            0xBA94E2094AC648F8ULL, 0x5CE3FEF8A6489A7BULL, 0x8F1652EFD180A505ULL, 0x5391AD889CD05550ULL, 
            0x8136986716012C02ULL, 0xB6EBD3C390D3742AULL, 0x107FBF5F031C6F96ULL, 0x3AB8AA52B3B9721CULL, 
            0x92860424A405272CULL, 0xF492F312EB01DDD1ULL, 0xB88CF9ACFCF12A8FULL, 0xD89269ACDDAA48FCULL, 
            0x9F65F9B42B37EF88ULL, 0x5D4D38CE036251D5ULL, 0xC706FCF9CA9C5E51ULL, 0x88FE5508BDE72C08ULL, 
            0x852E76A95B1C0392ULL, 0x6E58B51590C98005ULL, 0x5C6F7268BB0EBBCDULL, 0xDC27C96DAFA7822FULL
        },
        {
            0xAC0553359DCFD061ULL, 0xDAF34AA593A0B782ULL, 0x60E50835BB8375BEULL, 0x945E50C5926FCB61ULL, 
            0xDBAEC0356782C13EULL, 0x12B7788B879B957CULL, 0xA21FFCE95DE59450ULL, 0x37D760B161B56EA9ULL, 
            0x71C950F4BE9413E3ULL, 0xDD6173510666FF27ULL, 0xF0B0AB321175FD73ULL, 0x391FBB78783E6736ULL, 
            0xBCAA6567C66F745CULL, 0xD4EF1A640707273BULL, 0xFC1470C9779033A9ULL, 0xC7FD36EA418BE939ULL, 
            0x34E4C30E3BC4ED54ULL, 0x97EDA0D154B8736EULL, 0x4EF104DAEAAACB25ULL, 0x668C14BCEA5A236CULL, 
            0x99E6BF2437E1B7E7ULL, 0xCA316E8B5051302DULL, 0xF5DF1D990DB40B24ULL, 0x4D1F39968C6D78EEULL, 
            0x3CBD4D2D2929C7D4ULL, 0x2855ACA47D5E2ED8ULL, 0xC96641A0E52FA1EBULL, 0x9FB7DF0559B61528ULL, 
            0xC62B6EF9D2BA5E48ULL, 0xEB36B58B34E40FD6ULL, 0x1FB820FF87D1A0F5ULL, 0x196950F3D0AF6FC7ULL
        }
    },
    {
        {
            0xA54BD0E33C462C76ULL, 0x575D3748885D2424ULL, 0x063EDB5337B8BA49ULL, 0x3744A9651A494315ULL, 
            0xCC55BE05A8122D7DULL, 0x2A28C2D76D07707DULL, 0x113A4421549CCD54ULL, 0x24C7AB71640B76A9ULL, 
            0x0BA0A5D3276BFEEAULL, 0x4A45726FCE29BE1FULL, 0x97F548D971076269ULL, 0xE337ADEEFFA029DBULL, 
            0x09DA40C92DD16CDEULL, 0xC9B1BA82058F6DF9ULL, 0x4952640554467E24ULL, 0xDC176FCFB05B9652ULL, 
            0xFD12A3937D37C93FULL, 0xA7D7CF6791CD4FB1ULL, 0x173CE5ECC79D55DAULL, 0xA6EF5C7049287BB1ULL, 
            0xD84E17D6561F39D3ULL, 0xF2F849D95C2094A7ULL, 0x482478F8AAA963BEULL, 0xED2C307B83011FC3ULL, 
            0x634CEF80AAC0293CULL, 0xB87A74F4D95A1D4CULL, 0xBA0692897AB64372ULL, 0x70D9CA9F4F8281CBULL, 
            0x05A54960D866A8E4ULL, 0x970F54E1CF43E7B7ULL, 0x1A1C6308FD0415FEULL, 0xF0D6714FA01F59E5ULL
        },
        {
            0x871C6E361D07D307ULL, 0x0605C2E81779F124ULL, 0x16D44A3A0A27C525ULL, 0xDDD8FBE3DE4D472FULL, 
            0x2B88686DF377F3FCULL, 0xAC542973B688FECFULL, 0x5F96F80E2E0D4520ULL, 0xA11AE4A9D40B15D3ULL, 
            0xAD699E3D1CA77632ULL, 0xE85ECD04311BCDBAULL, 0x29B9455EDD7C2898ULL, 0xC1F5A47B72E8D6F9ULL, 
            0xB8777301DAB903B5ULL, 0x24B6EDE9B4B818AEULL, 0x28E6F188B4B88816ULL, 0x3829E12451CC9937ULL, 
            0x8102BB87D09C48FCULL, 0xEF787834477F8FBCULL, 0x35470C00DAD66BE6ULL, 0x323938B1314AFDCFULL, 
            0x5696EC0F71B84B07ULL, 0x3EFEF101D77DEFF4ULL, 0x6BD02A3DB8BEA1CEULL, 0xE5C5B897FB7C1974ULL, 
            0xEB02DA34084E5CF7ULL, 0x5D96FF8E2F85B09EULL, 0xC4C02B733A002C6DULL, 0xBD3EEAE188F623EEULL, 
            0xEAE6EEE0AB9B2EA2ULL, 0x71736F7721742817ULL, 0x43F6935CF90DFF4EULL, 0x3344908893867828ULL
        },
        {
            0x75C0E9865B6D4C1AULL, 0xBABD193310295057ULL, 0x051DEC1CC96B2731ULL, 0x9141FF815926EFFCULL, 
            0xF8CA3AB670A52BA4ULL, 0x3906DDA95108EE37ULL, 0x1EC59ACD9294149EULL, 0x699297BB24F9A73AULL, 
            0x65B57460DE139DEFULL, 0x63024330C8320F39ULL, 0x44AD75240EBB005BULL, 0xBF52AF57A86173F6ULL, 
            0xC3D3DB8BE9B89122ULL, 0xADB9BDB88900238EULL, 0x3D60D19DFABC9905ULL, 0xBD7B9E26ED509B77ULL, 
            0x29B46646A4BBF30CULL, 0xAB65B1C751DEB462ULL, 0x9F4BC1D73B0C7FCDULL, 0x437998F49AE763E7ULL, 
            0x37150A644F339085ULL, 0x3B52477351F845FAULL, 0xA7847B19C33CA92FULL, 0x68DD815C3FFFBD36ULL, 
            0xC75EBA687ECF74E1ULL, 0x46F62A7692769F04ULL, 0xDBAD4BFE760B62D1ULL, 0x04EC883117CD2F7DULL, 
            0x2A7D4A405F96C4D5ULL, 0x9E80939D0C7FA64AULL, 0x92FA2B6039108021ULL, 0x07643B89921BBD43ULL
        },
        {
            0x1F3A1AF0B436625CULL, 0xAF5B2647B6FABF5FULL, 0x857AF0D462E3945FULL, 0xBA7B40D5241249B9ULL, 
            0x1A75D6E0C8FFCE18ULL, 0xB5660B09F1D4B797ULL, 0x7F7E5FD43E4928E7ULL, 0x64DA5E297D287BACULL, 
            0x0F388F8B50F94C02ULL, 0x6E463F8A98468B1AULL, 0x2F3478453066681AULL, 0x2DF0DB468158287CULL, 
            0xD869FB4288CA2C59ULL, 0x8D88EF4A04406904ULL, 0x24F9FE09AF82703BULL, 0x7A25E597252C6C95ULL, 
            0xF54DCCE15B17DB61ULL, 0x309ABE57E4A4038FULL, 0x90BD8221674829D9ULL, 0xBF4012BD3D06FD42ULL, 
            0x479B501FD6F47B2FULL, 0x9EB9D678726F19ECULL, 0xBD1C1479C533E681ULL, 0xFC4415B7CA7E9298ULL, 
            0x560BCA8A70F1F3D2ULL, 0xB992CC083F2E9545ULL, 0xDB231A94605F5F6DULL, 0x57601C326FC8CB0FULL, 
            0x757C46288EE06004ULL, 0xD21551D75B366551ULL, 0x9F1477CB79FA3A24ULL, 0x433792126BA7E4F2ULL
        },
        {
            0x2F18232C6A339AECULL, 0x9AEF9B96E13CE095ULL, 0x4171E0CC4B5AEAF9ULL, 0xB3A85B94CD0C1F21ULL, 
            0x02AC825B91BC93A6ULL, 0xD524335644BEF07DULL, 0x318DFF8A193878F2ULL, 0x025E3A8185E88323ULL, 
            0xA4231FB642DF2CDBULL, 0x87834FBEC4DDCB96ULL, 0x384F1C35F8D006E8ULL, 0xC89D28F48DF45B34ULL, 
            0xAA9F2C2BF859A743ULL, 0xBB7FDC8745F11421ULL, 0x4CEE1F4E5F8632B3ULL, 0xF07798ADDF62369AULL, 
            0xC3641F08F5FF808EULL, 0xA26271276FEF251CULL, 0xF4FCFE782BC1F807ULL, 0x92702D8184650663ULL, 
            0xD74D9D021E5F73C3ULL, 0xD0D677CD221C1609ULL, 0x0B1A419B86EBBECEULL, 0xB74CFBBD2FC6199AULL, 
            0x0E95F3CA2A82B9E4ULL, 0x543D6F595F2116A4ULL, 0xED176A12A35BE1C4ULL, 0x9CDF9128E90F1472ULL, 
            0xACED06C737449FABULL, 0x94F8376259B3119FULL, 0x1B13E4AE34C44519ULL, 0xBF560E865064C742ULL
        },
        {
            0x2604F1D93D9FCA55ULL, 0x90D4CD91899AB0EDULL, 0xF9D53044F11B0299ULL, 0x8209A665FA8C560EULL, 
            0x6A4BEDC8FBA22F3EULL, 0xC5F324CF17FA9492ULL, 0xCE3A1D8DC9113F2EULL, 0x9E1C325DD5071FF1ULL, 
            0xFF44459C5E5BE027ULL, 0x192244865AFC0FB1ULL, 0x268BA0CDCD80943CULL, 0xD432B7EC235A94C8ULL, 
            0xB8D098568B75E66FULL, 0x40B6E27E9ACADD2BULL, 0xD22536389454D64CULL, 0x9C690289D50DA872ULL, 
            0x6074F2FC63E2C250ULL, 0xDEC938982B1305FFULL, 0x943030E6AC907BFCULL, 0x5B0B82C511333AC7ULL, 
            0x96DA6CB6CEE58345ULL, 0x97F63EAC47279B41ULL, 0x9B4C8643C92F6AB6ULL, 0x753CAE2C02B3F71BULL, 
            0x5F12E091CFE2BBCFULL, 0x90F6EC8201EE511DULL, 0x2D63BB7F34CD023CULL, 0xC3E2A8BFB8576168ULL, 
            0xD8DC5DBF68DDCB29ULL, 0x53394100D3A21231ULL, 0x69B09D14D4AB8149ULL, 0x5AAAAFA275AFD91BULL
        }
    },
    {
        {
            0xC2AE3F8591BB57F6ULL, 0xA016AF239FEA666FULL, 0xCFCD61DC8605A8CEULL, 0x37E1A0FED1D494EFULL, 
            0xE527D33173E5FB38ULL, 0xB2DD967B7946B22BULL, 0xAFEA139B37FA143AULL, 0x08D8921FA625F0E6ULL, 
            0x59EAC2378FBD4B57ULL, 0x97A1FB334825C7BDULL, 0x1A4ECBB9447D5564ULL, 0xD7338CA33775B421ULL, 
            0xE8124A5F70462D44ULL, 0x3BEA38EA55ABE6DBULL, 0x142140B25449F7A1ULL, 0xF9155D8604519078ULL, 
            0x55C546CC8671FE15ULL, 0x9B4AB8A2352D65B3ULL, 0xE6915D57A4951D40ULL, 0x0644D93E88AB6445ULL, 
            0xD2CA3500340A7723ULL, 0x9C9F1091F2DDCB5BULL, 0x74BF81B9366EFEC6ULL, 0x73E474112ECC7949ULL, 
            0x868ABAEC8F70B56BULL, 0x2BB40530B0148F98ULL, 0x240AB37759BEE1ABULL, 0x9CF9DA21B0402E21ULL, 
            0xC0CDFD86CA5A09C0ULL, 0x50F823376828BAF3ULL, 0xE250800F30AFEDD8ULL, 0xA9EE7CFD9C7A3F96ULL
        },
        {
            0x2EFA8A78166DE498ULL, 0xC54849D5DECE1756ULL, 0x7D462593F3B8885CULL, 0xC861FB310880F6E7ULL, 
            0xC608E5F5096390E0ULL, 0xD2F489FF6E05EC68ULL, 0xA3DE2A3F1D40C30AULL, 0x684D20BB3ADB5BB8ULL, 
            0x7FCCF1790686C672ULL, 0x28A305C1C0179E08ULL, 0x410690DBCA96D3ECULL, 0xA3B2DFC5C9DD4DC7ULL, 
            0x4386F657D16B5F44ULL, 0x3F3D91E15A1C012FULL, 0x8FA5BE48C809659AULL, 0x08342A4CA0A53BC5ULL, 
            0x0D4EC94E55CB797CULL, 0x37BAA6428F8DF417ULL, 0xEC53ECF10C841D80ULL, 0x6AA011B4050AA284ULL, 
            0x17C3552ECB0EB48CULL, 0x8868EB2C897DCD21ULL, 0x31A8C19BA413A523ULL, 0x6D301DE87DF7260AULL, 
            0xBEE2BDF884F6121BULL, 0x4CCDBFE0C0624A7DULL, 0x627610BA16A1CA6AULL, 0x192B00F03DF27D4CULL, 
            0x4275C7B20D3A1A0BULL, 0x9FFF5966F387DEEFULL, 0x0AC9E3560D1A4E19ULL, 0x38D136DF6AF56FCCULL
        },
        {
            0x80D682191003AB97ULL, 0xD828BBCAF311A166ULL, 0x86CAD2FF5B17CFA1ULL, 0x1F29217D0D654EB0ULL, 
            0x5C824721CA66CF6FULL, 0x35C8C040BD89B8A6ULL, 0x643CE7CEB1ACFD41ULL, 0xEF1A1331C2C4D1F5ULL, 
            0xB5584E0C67C36555ULL, 0xD1FAF8A8C2C0ACD9ULL, 0x64A781E9EB39662BULL, 0xD14E5EF4AFBBA8A1ULL, 
            0x9A51665F7F25A569ULL, 0xA85BAB5AE8E31E88ULL, 0x5B3730B148FCD48CULL, 0x58B9F69D3AA32729ULL, 
            0x2218D8E02F6FD9BDULL, 0xFC9428C1B4646BF2ULL, 0x35535884F695E2D2ULL, 0x469F640B6537493DULL, 
            0x8EF93946975DF8C5ULL, 0x4F8586B4EF372D20ULL, 0xF141B82BFDD4AAE1ULL, 0x7665612E55016525ULL, 
            0x59529F85C5E25C54ULL, 0xF31E4F95351D7F66ULL, 0x02CECC420F52A89DULL, 0xB721DE570B845FF1ULL, 
            0x40BA28DF54FC3D20ULL, 0x20809F1B7392E075ULL, 0x689CD3DF3CE71E37ULL, 0x1DF74937D9736A92ULL
        },
        {
            0xC9F061F8C4F468C6ULL, 0xB069AD423370829DULL, 0xD8FD21B7D807582CULL, 0x9172988F847B332BULL, 
            0x244C5B02F8BB1A07ULL, 0xFD84A416F98DC697ULL, 0x59B369673222ACA7ULL, 0xA92E81106C49CBC3ULL, 
            0x680ACBC69AE853EDULL, 0xF676CF9107DCEDF6ULL, 0x40C95D160968E27DULL, 0x3F88A86EA244CDC4ULL, 
            0x1CC83A232B85E6A3ULL, 0x895433791A3BBD9EULL, 0x56BE5D727CBE2986ULL, 0xE7FF75F0C2EF74D8ULL, 
            0x250B8452381C324BULL, 0x6644B01C1616F852ULL, 0x241D4CFC566CD754ULL, 0xD70A6BB56B71C2EFULL, 
            0x08E2BF13061564FBULL, 0xD819B1A5BCC65405ULL, 0x5FCEC3F0DDFC8006ULL, 0x11B47DE301CB036AULL, 
            0x60BC278EF6AABE82ULL, 0x458F89E17EB9D1F5ULL, 0xADB28579C5199CA7ULL, 0xCF574BC6D79FA95CULL, 
            0xADBEC6A2A7DF047FULL, 0x7AAC2DC3C69CFAE1ULL, 0x424ADFB5E9C363EFULL, 0x1956AFB51C975239ULL
        },
        {
            0x0697E293694CCBD5ULL, 0x12828AFD04FCE602ULL, 0x6A39F2B13EE37EECULL, 0xDFEE40357EE6B0D5ULL, 
            0x37DFA2C8731C7452ULL, 0xF5601374E68B0EDAULL, 0x61D40C3FC9167967ULL, 0x3C75F61FE00D0CA2ULL, 
            0x9353382A96653CECULL, 0x40CC25D40E13EF63ULL, 0xD1B9240F68968968ULL, 0xEBE57DC860098BB9ULL, 
            0xF769DB90C39DBA17ULL, 0xF660DDCDDDFB488CULL, 0x46103FF91DD8B0DAULL, 0xFA3FBBE655179625ULL, 
            0xC41F8B397AC00588ULL, 0x58463D5370F35661ULL, 0x9BD7755BC603F0B8ULL, 0x0CAFCA8A079D9C92ULL, 
            0xA87B527B659CA6E1ULL, 0x278B9F7B19ECE1FEULL, 0x2371180AC0B70BA1ULL, 0x87C1E03F33CB1D52ULL, 
            0xDED1EDB23ECD5B33ULL, 0xF9C742235AAA4891ULL, 0xBD3BD8D38898F2B5ULL, 0x1A1DBFEEE93179C6ULL, 
            0xD30C4D8017882C13ULL, 0xBCA67D48C3DF7EBBULL, 0xB5B600993F914D9FULL, 0x8EAEE445414FBD05ULL
        },
        {
            0xFB4AA4F28B860EF3ULL, 0x45FFAD7D42227808ULL, 0xA42F107BF6D7E93EULL, 0x45FF534BD77056A8ULL, 
            0x9A74F4654DDAE2D3ULL, 0x5B9A3F2A88D09835ULL, 0x0053DC4DA51464FFULL, 0x83CF6B95E417E7EEULL, 
            0xB6A747D9E6E139F1ULL, 0x97768DB7042754CFULL, 0x9DDF0769829FBDD7ULL, 0xF541C592CB08B219ULL, 
            0x0EC3E479B387D13FULL, 0x2C0B63F0E042DD5FULL, 0x96C631103A9BB510ULL, 0x0961F6DDF652D632ULL, 
            0x1479A4FB374A87E2ULL, 0xD61D2CE338988204ULL, 0x519B68EE8E28E498ULL, 0x6C9F72F3E112E262ULL, 
            0xE80D427358C0C854ULL, 0xD612510BCBB35B3AULL, 0xC0FECD6B24113F42ULL, 0x769C3D5ECCA551F9ULL, 
            0xEF8552A61E99A09FULL, 0xD3EDB68C3BC0686DULL, 0xFD489C198287F9D7ULL, 0x92BACF0E229A91E0ULL, 
            0xA40FCCBB7D316FF7ULL, 0xAC00F20A0C40BF7FULL, 0x895D6BE7888F01BBULL, 0xBA9223614466F2FAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseEConstants = {
    0x9C3BE1A3EB8E55F7ULL,
    0x671D6B94FEF31DC7ULL,
    0xBA5600E422980C1BULL,
    0x9C3BE1A3EB8E55F7ULL,
    0x671D6B94FEF31DC7ULL,
    0xBA5600E422980C1BULL,
    0x4A0F42C68DAC39A7ULL,
    0x6EFE374DD68E7040ULL,
    0x20,
    0xE7,
    0x19,
    0xE4,
    0xEF,
    0x4C,
    0x84,
    0xEF
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseFSalts = {
    {
        {
            0xE03F87DE6AF13EF3ULL, 0x7DEE7A751975969CULL, 0x8EBEDD1A3856D822ULL, 0x6B118BF41A9FC502ULL, 
            0x00AF8D17EEBE6F85ULL, 0xB44C980A821DD4E3ULL, 0xFB7B206B3FBAC35AULL, 0xEBDE5773FF6FAF5BULL, 
            0xBA77BE14052DB51BULL, 0xDDF1F051B732AC70ULL, 0xCFAEBA4C522C326DULL, 0xE2916EFEECB2E0E9ULL, 
            0x54813C8D92827007ULL, 0x690665A6FFA50D69ULL, 0x045AD76276594572ULL, 0x052A00A520545DF1ULL, 
            0x6CBB29EB76C34C37ULL, 0xDA6EB5B3EB390F9DULL, 0xF9623F9D8C1871A4ULL, 0xF89000F2CEB566F1ULL, 
            0x810853B850539CBFULL, 0xB76AA33040EE9725ULL, 0xB6FFB69DF8FA2D3DULL, 0xC1186E7088728FF0ULL, 
            0x0128138DDC3C9F6BULL, 0xDB19E41522E85284ULL, 0xF39428C80B60C249ULL, 0xCBA5FD3DD2A748E1ULL, 
            0x1976FB1A0EDC3077ULL, 0x7259FD33EF86F2D5ULL, 0xACA9B03EAF229816ULL, 0x43959C737E528D90ULL
        },
        {
            0x111F2D9BBD43EB2FULL, 0x57F0D49692A22C37ULL, 0x2065B963DADA55CEULL, 0x6CED3F2C13CBCA43ULL, 
            0x397FAA8D5C1D2290ULL, 0xBC6D5BD90F1A50F4ULL, 0xC8F23D30FB7081C0ULL, 0xA2F38DCE5F27F398ULL, 
            0x5F10DA6FAE5B1345ULL, 0x440B354925042E94ULL, 0x7FAEE22AAD96F7C7ULL, 0x4949C2B326E281C9ULL, 
            0xD3AFD263A7A10C00ULL, 0xCE909C314A260F27ULL, 0x1B24D51C3A905310ULL, 0xBABA909320D85D4DULL, 
            0x3E16A21EB1715CA3ULL, 0x9F37EF06067E2DACULL, 0x92B471BCDBF49A80ULL, 0xFB1B33887B6311C6ULL, 
            0x6EFD85B9F8B6D452ULL, 0x615BF0D5A2A2A11BULL, 0x18B249E9406909B9ULL, 0xCB0CCC613C17B736ULL, 
            0x9E39159643F5D639ULL, 0xAFB0190C89F09FBAULL, 0xFBB4937C9E736F38ULL, 0x55BDA293AB2F00B6ULL, 
            0x70018B86A1C7D0E2ULL, 0xDE5C65691E48C2E0ULL, 0xF756EC0519D49501ULL, 0xBFEC8915AAFE9A90ULL
        },
        {
            0x094F2299C4513EFFULL, 0x24FBB976998FA81EULL, 0x0422456195655FE6ULL, 0x41B4F5BB165BFDEAULL, 
            0x04FC7FAB7013F02EULL, 0x2026012C4A479465ULL, 0x3FD8FA29BA2C3C8AULL, 0x289E46327614E101ULL, 
            0x19ADBA9BAA283BE9ULL, 0x4DAE3B39922C964CULL, 0x7E1D7E72E79B43F5ULL, 0x11F651FD09056E39ULL, 
            0x514EA9C7ACED2B7DULL, 0x02DC0C1ABA30221BULL, 0x71864D0831BEB733ULL, 0xF76DA000A41F96FFULL, 
            0xEE4273599A1E3C54ULL, 0x8F4EFCD14F0FA043ULL, 0xAD5138B6F6CA3C97ULL, 0x7AED6CF37B9FF29FULL, 
            0x13DE4C8D79085836ULL, 0xB0B5587AFA48841AULL, 0x5C8500A24BA3F057ULL, 0xBB5886B3634CF175ULL, 
            0xD8D5A4120F714463ULL, 0x45F5212473094FC6ULL, 0xF8D7EFE9BC4C2223ULL, 0xC5D8726BF2EEC1F8ULL, 
            0xF308ECD469ACC075ULL, 0x2D266FDF78A05F9DULL, 0xCED8444627D4C0E5ULL, 0x0C15EAD33D9FF266ULL
        },
        {
            0x71B29C8AB6448182ULL, 0x583AD483191F7A88ULL, 0x7773CDF6FB002109ULL, 0x97B6CF4A380DF4C4ULL, 
            0xDA69F1660DE2E712ULL, 0x3A44725264151125ULL, 0x92D6702C076729EFULL, 0x983F11C8304EA9A0ULL, 
            0x801F0E146BBD534DULL, 0x4D7535A9C141E188ULL, 0x31FDCEDF09C73226ULL, 0xCF36D612D7326C32ULL, 
            0x8602636CAAC7C887ULL, 0x3E8E3E6E08D01040ULL, 0xEC2CE6F384D72209ULL, 0x4F42F049A8F750CEULL, 
            0x3932971797502CBCULL, 0x766BE303502387D7ULL, 0xEFCCD72783C9D9E8ULL, 0x2775BA5CA18AA90AULL, 
            0x3CBEDA363234B6BFULL, 0x9CDF9D5C95E3ED64ULL, 0x54145132CDD37DCFULL, 0x64E1CCFA08177E66ULL, 
            0xE5831C4C666DE6BAULL, 0xAB0003883D3F6715ULL, 0x4CABF829BB73DC1BULL, 0x8A268C29E39C72ABULL, 
            0xF119822C3E344A32ULL, 0xF170F62C28AB4537ULL, 0x42764FA95A0F87F7ULL, 0x08A320B56CFF298EULL
        },
        {
            0x599BF41A0E42EAFDULL, 0x80FE771436BBFFF9ULL, 0xC64B0E260A86B3F2ULL, 0x30FE86901D757C93ULL, 
            0x35815E2F0D06BC30ULL, 0xFC02A21A4A6F7272ULL, 0x83C05C369AE284E6ULL, 0xE84B0988B9C20E57ULL, 
            0x2F7F83C1EA720770ULL, 0xDC796BE3A4B9C885ULL, 0x27A83CEE06B416DEULL, 0x9AC922B816CE31FCULL, 
            0x45E5EA5FBA815D5AULL, 0xA7CC0021ACB2BA9FULL, 0x03FDDC71552B6F6BULL, 0xD77E94A90C0D79C0ULL, 
            0xF52672C6C5C1E7FDULL, 0xABABF791E48E40E1ULL, 0x0C7FAB6E3977D569ULL, 0xC152516D7A697466ULL, 
            0x4D6D485C9611389CULL, 0xC07118EEDC2253CFULL, 0xA900654FCFAB101FULL, 0x3BAD32E4A34AECD6ULL, 
            0xE7E49618022FC410ULL, 0x048AE9A095AE49B5ULL, 0x3CA6E0819A9FFC3DULL, 0x9BE8AE6E0570DB2CULL, 
            0xD73FCC95816AE5EDULL, 0xA54B732B800E6CA5ULL, 0xFA6D4B8D50821DE9ULL, 0xA31F81E1D9A5A498ULL
        },
        {
            0xC9212DB3A106993BULL, 0xEF97B3BCB793E7DDULL, 0xCCD2EA00ECE96FA2ULL, 0x59CF9EE1B9EB7518ULL, 
            0xA38EF6FE0AE66C0DULL, 0x7C9791F56A816E5DULL, 0x9B15638ADF0EA0E7ULL, 0x2F3379ADBF06E4BAULL, 
            0x3F46BE2FD5B9E613ULL, 0xB11A3B917E0E9578ULL, 0xB57F94C4262228CDULL, 0x314F7E830E8C8CF7ULL, 
            0x4ED292ACF2D90515ULL, 0x40F79C9BFA88B56BULL, 0x403A65FB279460EAULL, 0x8520E9ED97EF5489ULL, 
            0xC87980C9A1C78942ULL, 0x5D8BADA765C5677FULL, 0xAD321D0870D62BCFULL, 0x19CDE0DAEF5C7F41ULL, 
            0x2ABCC3A58D0482C8ULL, 0x28967EFC742D82C3ULL, 0x5988B967BBC57882ULL, 0x17E1258B68FFB7E0ULL, 
            0xE2D0347BFF812E3CULL, 0xD8A9251F66DF98C0ULL, 0x4BADB7242A90BE62ULL, 0x61A1072EB88E1E75ULL, 
            0x5900662187AD6F4CULL, 0xF659779B4C0C9909ULL, 0x12C4C4D0ECA70863ULL, 0x0568842E4DDF340FULL
        }
    },
    {
        {
            0xDD4204B290C160CAULL, 0x7A0EB4822CB7CDD3ULL, 0x146E6D5451456F1EULL, 0x42389AD96FD5BD98ULL, 
            0x6E3F4CE85A2D4350ULL, 0x63000199388D5308ULL, 0xE46C56B1056C8121ULL, 0x76C8712BA5FC2120ULL, 
            0xE01B221CA8AA5125ULL, 0xE9769D2677483CD9ULL, 0xD680D7F7D1BAE260ULL, 0x7EBA8E69AACCC03AULL, 
            0x0A9753079771F141ULL, 0x4E6EEAA366DC9B48ULL, 0x243AD9797B08B5F0ULL, 0x53FACE3E10A8EDC4ULL, 
            0x1DF9315D41793C68ULL, 0x163C17EF3A5FA761ULL, 0xD727152526D7F061ULL, 0xD515BD6D41717693ULL, 
            0x69920231BD2B1C8DULL, 0xEC90FAD4E5445F15ULL, 0x5B7E85F599465319ULL, 0xB7F66B4AC082DABBULL, 
            0x7DD52952C004A72CULL, 0x558671A2194EFF8CULL, 0xB50556E96D7FDD87ULL, 0xF353213BD72C05BFULL, 
            0x293BF5213E1C71D0ULL, 0x663EBF90BC787284ULL, 0x68D4A86023FEB32AULL, 0x39CC3A035B4A8E11ULL
        },
        {
            0x82E61EB790BAC7C3ULL, 0xF5D94660FFA67661ULL, 0xD41AB33E3460ADC9ULL, 0x7FFE0BDB0D569DDCULL, 
            0xACB576FB2D015BCCULL, 0x8201E5B4E869E460ULL, 0x9740C7A1F1654D53ULL, 0x467CB00E0AC698A9ULL, 
            0xAAB543477609DB2FULL, 0xA54C99F385923204ULL, 0x557FC02436539B26ULL, 0x3B88FB525CCE04B2ULL, 
            0xA5C2405AB21C6244ULL, 0xFBEE074958F382F7ULL, 0xAFFCD97273D45A73ULL, 0x0BA84BAD6B804609ULL, 
            0xB9E678FC1FB26F7BULL, 0x5C22A8AAFDC6EF26ULL, 0xAC8FB5ADFE959896ULL, 0xE2C9AD7E68F60BA8ULL, 
            0x26720A2773DCA8B1ULL, 0x68AE94C78EA6624FULL, 0xAEC3AB6D5C8D8A84ULL, 0xB8A0334C57FEEFE1ULL, 
            0x45BF705434850628ULL, 0x32A13F09289B6669ULL, 0xDED179B7612618BAULL, 0x6235F751BFDB863BULL, 
            0xA293D90DEC2D5399ULL, 0xE85D055F5F45D2C1ULL, 0x153518CB9CE26E3DULL, 0x3804DE7025000A7FULL
        },
        {
            0x8F5B9A0F55668F5EULL, 0x6839FED4C3EFDECDULL, 0x7D5E2291344A0E61ULL, 0x5681040273691926ULL, 
            0x9EEF776FC64F0A31ULL, 0xD71D6ADC45FBA343ULL, 0xBFD22F9AD6A4F78FULL, 0xEE0E307B7920625BULL, 
            0xAF83FA612C3DFA0CULL, 0xAB864B2B99F5FE54ULL, 0x1FE2A53302F98942ULL, 0xC98D970E282EA2A6ULL, 
            0x39E4AD0449474358ULL, 0xEDF7521C15A8B562ULL, 0xBADF7ED85E2CCEB8ULL, 0x539F9C2BB8A3C3D5ULL, 
            0xA07B19DBB73A0120ULL, 0x34E1541DC751D50BULL, 0x982510B03572FB51ULL, 0xE59111DDE48A2A30ULL, 
            0xD108399E0D7F084CULL, 0xB4CCB045BE1BA11CULL, 0x6F14EC428C042F31ULL, 0x8B3051DD3316BAF4ULL, 
            0xEF27F222614CED6BULL, 0x14EA014815BF2D4CULL, 0x029206F4105C8C52ULL, 0x50FA9CB002E51299ULL, 
            0x8191F54CE09E4447ULL, 0x09CC300FC09A60FAULL, 0x89459E109B6D218FULL, 0x690D079BF10BFC9BULL
        },
        {
            0xF613707487F7304FULL, 0x00C3DD312585BEA6ULL, 0x392BB855711187BBULL, 0x993D9775C0BC66FBULL, 
            0xB133975A3F6089FDULL, 0x69F287929B7032FAULL, 0x7A5B666EC1C31E5EULL, 0x8378EAFC0921DE41ULL, 
            0xCAA04BC2F00BB871ULL, 0x0DC8562881600F57ULL, 0x1B4A07381AEB8055ULL, 0x10D0183194726ED4ULL, 
            0xC7CC318359D3DFC7ULL, 0xCAE1153749DE3041ULL, 0x10A38567D475239CULL, 0x7A8EE8D78A1FE32AULL, 
            0x73FE965120BAA6BAULL, 0xDCE23A61C90AF614ULL, 0xA031F52D8EA0A25CULL, 0xCD9C83E1EAE47280ULL, 
            0xEC35017A993100BAULL, 0x1DEB29EA758D1DE2ULL, 0xD90974ACEB5B84A3ULL, 0x67FB5B5AD17010ECULL, 
            0x74C29D3023A5A531ULL, 0x302F358C1CED0B32ULL, 0xD7352B38A187E367ULL, 0x97AF03DB3B3A23A1ULL, 
            0xED7EB110F612791BULL, 0x817A3B2A6101173DULL, 0x5E568D1E5F6874F5ULL, 0x3F01DB512B7542C8ULL
        },
        {
            0x807E2D1565CC4049ULL, 0xF63AB9D72FEA67C9ULL, 0x122CBCC4349AD090ULL, 0x23C0AC96AE767409ULL, 
            0xCF0201B5E95A7F3AULL, 0xD0CFDDC9B0FBBF71ULL, 0x0A14929067F56A8EULL, 0x51CC1F93404E840EULL, 
            0xA5D0BF4A1EDA138EULL, 0xC4C1A76BDB1950ADULL, 0x05DA33C4FF8FC613ULL, 0xF94EBC206E7FA531ULL, 
            0xDBC38938AF5E76A4ULL, 0x97D03D1C4A192F2FULL, 0xF0C77AD4EA8E1F45ULL, 0x8756967EEC7D1E7AULL, 
            0x4830656A884A4988ULL, 0x09A32E13F7925EE4ULL, 0x112E1AB6A0D23064ULL, 0x0AC1F7FFC71FE32DULL, 
            0xFBB6C6DA111475A8ULL, 0xCEF052D109EB1680ULL, 0xEB5AED4C27097A50ULL, 0xABC95181846F830BULL, 
            0x5A320F5BE9AF5C7AULL, 0x4F8BD71ECB56D5DAULL, 0x737E397314C3298EULL, 0x633252117D2F43A0ULL, 
            0xA821886BE00E70A0ULL, 0x18929FF52B05B380ULL, 0xCD37BD5E47E78DFCULL, 0xC973C08DD9D95A10ULL
        },
        {
            0xB799371E92658539ULL, 0x84828BF082D61AEFULL, 0xBEB9AFEA7398FE87ULL, 0x2C1E07402B8E388AULL, 
            0x26EAE3EE7B690396ULL, 0xDBF61EA127A7EAB2ULL, 0x82115A3A44BD7B4AULL, 0x016A735608139665ULL, 
            0xB3B0A3DDB0D9BEEFULL, 0x545BEF565EA46326ULL, 0x0485F81DB36A7C3DULL, 0x900770E167980C6BULL, 
            0x3A135FF6179128C5ULL, 0x9F1425AC7FEB7550ULL, 0xA273581CDA86BA18ULL, 0xFA7659CF34CA91BCULL, 
            0xDADB64954B2CC006ULL, 0x7A6CBF9E1D98156AULL, 0x204D88F89CED0880ULL, 0x5697FBE0FE13E81FULL, 
            0xA66789A1F0B08790ULL, 0x97D0BB7480D8AEC2ULL, 0x4F6E60FD6028AF57ULL, 0x4A5C77A5AA57CCB8ULL, 
            0x2548688FBC2D6EC3ULL, 0xA2330C6F36D9EBA6ULL, 0xBADFD70730D5B18FULL, 0x4F18C046ED65519FULL, 
            0x54BB30B9300FD251ULL, 0x64C0C20E1EA2580BULL, 0xF0D6DC75E23AFCB3ULL, 0x2E588397C6AF810DULL
        }
    },
    {
        {
            0x32C8AD09DA88533DULL, 0x34D86DD8708AA3B1ULL, 0x223936E3FA96F909ULL, 0x57CBF10C7D63CF8AULL, 
            0xEAF6B01B31785905ULL, 0xD5573C9CA3FB0D3FULL, 0x083EDF7FE8F8BFD6ULL, 0x88DE658A3812DDB1ULL, 
            0xE6C22988AB05E952ULL, 0x23655246BCAC8089ULL, 0x5F4B9DC671E869E0ULL, 0xA8AC90FF6F85B99CULL, 
            0x81B932F2E01B3FC5ULL, 0x4F8CD055BF4ABD76ULL, 0xFEC36ECEF98EE758ULL, 0xF57821FA6C4B3054ULL, 
            0x9C58EAD87217C094ULL, 0xF7A0725A6AD70E39ULL, 0x7E2B69B83EC083BAULL, 0x8E94B536B114AD2DULL, 
            0x4CEE104F53B27DF1ULL, 0x905BD5902AF7AF84ULL, 0xAEDF07B1712F0833ULL, 0x96EECCB143268FF1ULL, 
            0x18A6A62668E5CE5BULL, 0x24ECDEDB0F47CD3CULL, 0x7B90D21D60B329A7ULL, 0x8192CD6B0E5FB2D1ULL, 
            0x0EAD900E7F738507ULL, 0xEB140F7D4865B64BULL, 0x8ACB994B2DB55475ULL, 0x1628A4C0B4852373ULL
        },
        {
            0xADD48A051E78D831ULL, 0xFA97FB4A1FA71EEBULL, 0xDCDC99E0608149ECULL, 0x45CBFE65416B6487ULL, 
            0xFECE52CFA43C4A58ULL, 0xB8C2FEE8D2C9B385ULL, 0x1F4A25D25A74311FULL, 0xB887C36A5E7CE131ULL, 
            0xED232261A09F348DULL, 0x6C59586CB4C82AACULL, 0xB8D415FB3600AB26ULL, 0xD7AD931AC5E7F03CULL, 
            0x56921F55DCB248B5ULL, 0x148B08562D7AD083ULL, 0xB897A5783FEF3EA3ULL, 0x32A3D1EC51217BF5ULL, 
            0x2E47D8CD7B12EF89ULL, 0xBF359B9ACFDF84F7ULL, 0xA47099EB4D0B84E4ULL, 0x2A5418999BFE96E3ULL, 
            0x7D6D9C6DE8552774ULL, 0x596033CB9BEB5C03ULL, 0x8C77532802A99E0CULL, 0x408D882BD6733C65ULL, 
            0x22E2FE58DECB5DDEULL, 0xDD461C0D3AE94737ULL, 0xD813F98C18B1ABFAULL, 0x77DBEE7FD7E60787ULL, 
            0xCECCDB1605916E7EULL, 0x4B0D8AA2CD752CC1ULL, 0xF4278C91A11671CEULL, 0xC93BB0106730BCC7ULL
        },
        {
            0x7A7F2260803AA3B0ULL, 0x6B8E3AAF417A0D0CULL, 0xDF35A711BE98C0EBULL, 0x916533F7115B78C7ULL, 
            0xB9A685BC0665BCDAULL, 0x5096864082C709E7ULL, 0xF0A11BEAE7585D7FULL, 0x03B00809662F15BDULL, 
            0x5FCDD624BE0DC758ULL, 0x38FE9F158D78EE78ULL, 0x5BA848DC83266B3BULL, 0x4E603BC80603B00BULL, 
            0x13E4CD21DC993079ULL, 0xB0C140F91E5791CEULL, 0x0C26F7389D91E370ULL, 0x2F346D0DFD2ABE23ULL, 
            0x6B20F5A8E02290F6ULL, 0xA19D9AC321B3EE02ULL, 0x9094EC866C743F79ULL, 0x0479E9FE4BF48ACBULL, 
            0x97702EA579755860ULL, 0x94481B5F8B0ABD5BULL, 0xC9CF5AE195EFF0F9ULL, 0x9690BEA5AF2E0A1FULL, 
            0x1BB9BBE61789EBE5ULL, 0x24F1309033DB2C41ULL, 0xC854B158A78BA4BBULL, 0xBBE302732CCA4E7AULL, 
            0x27C5D3F1E7E68360ULL, 0xCB1414097F25B8DDULL, 0xFCBE83C8893FDD0FULL, 0xF927CE28B47129ECULL
        },
        {
            0x2B7594A0F0FAE1F4ULL, 0x07CF717B69CABFBAULL, 0xE03A7023B782D46CULL, 0x44CF8704F0C0DF32ULL, 
            0x25E34E7D70140B23ULL, 0xC91F75805F78025EULL, 0xF86809BCA2794D0AULL, 0xFDB3AF8D2D154D5CULL, 
            0x2F4525FC1E0720EDULL, 0x9FFD6335E050CEAEULL, 0x26482A3BBC83DFC6ULL, 0x0C6DA68735532CF2ULL, 
            0x96C1B0663B335057ULL, 0x060367FFB1898DCBULL, 0xDB153EE751C9D985ULL, 0xC7AD7AB65A6C4A77ULL, 
            0x11D37792799E84A4ULL, 0xC46031C18F7D720CULL, 0x52864CF3C696F7A2ULL, 0x3728DFF1F812878CULL, 
            0x6EF94C7A95F20A43ULL, 0x2F2A401A4C426179ULL, 0xC2EC01F8DE694F74ULL, 0xDA1D1D2C24082B87ULL, 
            0xF234648A08DA2EC1ULL, 0x08F9139F0564842CULL, 0xCB6A05F6672427F4ULL, 0xB60B7B46CF0581C7ULL, 
            0x88122EACBB451F95ULL, 0x1FEE9765AD472EE9ULL, 0xF84CDC12F9462DE7ULL, 0xA6AE09FC83AD98DDULL
        },
        {
            0xCAAB00856C429DC3ULL, 0x7BDAF2B2A7EF9628ULL, 0xED75ABC0C513AAF9ULL, 0x33CB35EE97F2611EULL, 
            0x93BA271D11BE9AFFULL, 0xEED365ADC4E58099ULL, 0x47145F468F996F34ULL, 0x8CEA85A7C6523EC0ULL, 
            0xF0430CAF781628CBULL, 0xBB42441D014344BFULL, 0x011591CF5ACAB2CCULL, 0x8A93F0E68EC0402DULL, 
            0xCA49F5ECDBB9506FULL, 0xE3F155CB88885A54ULL, 0x3EE7F8D9639B6AC3ULL, 0xF2BFE02C8E79FA5CULL, 
            0x5C50FD1FC349BDB9ULL, 0xDFC99C48143C4032ULL, 0x0F2531399CF7EFA3ULL, 0xBC615B6F0A63930FULL, 
            0x5065F10FFAFF97EAULL, 0xE2CC635D923AF9FAULL, 0x336A837A19C6E86BULL, 0xE1056A316DCB05BEULL, 
            0x58B72D7E85705B78ULL, 0xC92EC4AF5BB1D4D9ULL, 0xECDC7CDAB4B2B9BEULL, 0x6C460D0032AA6221ULL, 
            0x330D864B93C5F0FBULL, 0x840111AD3BDD142FULL, 0x9CB29445B86DD232ULL, 0xDD946996D58BD11EULL
        },
        {
            0xDD747C4B4CF71BBAULL, 0x9753E8903BBC0879ULL, 0xF793F061AD64B843ULL, 0x01000C83F19BDFA2ULL, 
            0x0ADD9CF6ACC78CA3ULL, 0xC9C4DC6AAC7F15D6ULL, 0x1BF46CF30F226C8CULL, 0x464C63F256935643ULL, 
            0xCB02B4093E6182AAULL, 0x570064E0B1E0E52EULL, 0x7256FCB571DFBF2FULL, 0x3A7472DD52AC24C0ULL, 
            0x5454F8724F3E4650ULL, 0xAF231976F609C408ULL, 0x706EF264E1F8325FULL, 0x9FB41CB843D5C807ULL, 
            0xE7AA0CAD0FE0EAADULL, 0xBF616B08B62D8E35ULL, 0x0AE3A61F9AC726B1ULL, 0xEB2B50CAD96F0BEDULL, 
            0x2319AA3A572A8197ULL, 0x398A815A0C5B961AULL, 0x7268693AF8BBC322ULL, 0x369C470FDED791A5ULL, 
            0x8FF40EC1391C5DC7ULL, 0x5F4F23D3025E9B24ULL, 0x9942FA2DB8874FF7ULL, 0x4323D6389B106E20ULL, 
            0xB1894709EE6F28A3ULL, 0xDB4BDDCF4694CCC3ULL, 0x27EB97C9A2986F48ULL, 0x610212EFA4C99C3FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseFConstants = {
    0x1DC26C43E0AC9C2AULL,
    0x82B8D7A57A9B657EULL,
    0x9F023EBC8A0FA36DULL,
    0x1DC26C43E0AC9C2AULL,
    0x82B8D7A57A9B657EULL,
    0x9F023EBC8A0FA36DULL,
    0xCF4A394BA7A2FC55ULL,
    0x69CAB1645C51B104ULL,
    0xA8,
    0xA5,
    0xBC,
    0x66,
    0x5A,
    0x8B,
    0xD5,
    0xA9
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseGSalts = {
    {
        {
            0x3E99EC072DDFE723ULL, 0xA35F859AB6ABF9A2ULL, 0xA76F594A3FCF75E9ULL, 0xA5DD1875B2B9CA09ULL, 
            0x30AE2A7620683053ULL, 0x9A1FAEA5897DADD9ULL, 0x21735B66B38488CEULL, 0xB157BCC5084E0FEBULL, 
            0x8C6575B7E2D55368ULL, 0xB56C348037D1D63EULL, 0xE0728525D442C468ULL, 0xE7DF6E9CAC1C6D51ULL, 
            0x2AEE855EDFDCAF0FULL, 0xC3E0476C2E0F2693ULL, 0x8F49E46F3F49470BULL, 0x567F0FA07384FA66ULL, 
            0x078AB91E25170F31ULL, 0xAD8D537053535A29ULL, 0x5CC583975527EE88ULL, 0x1FE1BEF1183B292DULL, 
            0xE0AD2A06449140A9ULL, 0xFAEB860CABC18354ULL, 0x871661818FC7C2E2ULL, 0x21DE96E97641F4D0ULL, 
            0x92CEC59CAA1C1ADCULL, 0x109EBE08FA8636A0ULL, 0x80255179484BEDA7ULL, 0x28C08722A39358E7ULL, 
            0x6323FD35FD4C68C1ULL, 0xC4214BCC41903837ULL, 0xA2B2155B896D2F79ULL, 0x65218E938CC922E8ULL
        },
        {
            0x1850CC13C9579CC6ULL, 0xE3AABD0540E51781ULL, 0xC73F092B68B48AB0ULL, 0xABB9EDF3F5E47F8FULL, 
            0x0B7512DD83F20F88ULL, 0x47508EFBC40B54B3ULL, 0xA06AA2E84095084FULL, 0xA4384DED0047BB4BULL, 
            0x884154481BBB3EA1ULL, 0xD178377937F1DED5ULL, 0x2E33755CCF532DAEULL, 0x3E081BA28F0E02F6ULL, 
            0x41598CCDF5F6E282ULL, 0xBB3BBB3F5F3B9B77ULL, 0x5233B14E17DD8841ULL, 0x51A5B8D007F05787ULL, 
            0x81CE2498108CB16AULL, 0x314E7027E500763FULL, 0xD7675300C77104FDULL, 0xC3A3BAD1BF1AB7A7ULL, 
            0x614990182138DD1BULL, 0x7CB7E02D8BA6627CULL, 0x35B0EF709689A8FBULL, 0x660571884362F331ULL, 
            0xDE6599069446DB21ULL, 0x36C4CCE92CEFD381ULL, 0xE9C2803F7798E2AAULL, 0xAEA6B00E80AD47A7ULL, 
            0x3CF6D2C40EBCEE1BULL, 0xAFC1F742D0AC1B8BULL, 0xDBAE3BE5947EA45DULL, 0x61DC499B5E364F30ULL
        },
        {
            0x8B74494BF68056C5ULL, 0x8DFFA4E665961E9CULL, 0x72D054D0A3606A6AULL, 0x67BA6A449F4C5837ULL, 
            0xC710114EF5EEBBCAULL, 0xE4716BFF7D31B4F7ULL, 0xEC99DC8CA22151AEULL, 0xB3B6E983D0FBFD22ULL, 
            0xE62A3748009869C2ULL, 0xF7349951619B0478ULL, 0x7FB3FC6003205371ULL, 0x689115D5D63D8814ULL, 
            0xEA465E4792FEEA69ULL, 0x47BDA55F57DCF7B5ULL, 0xEBB1E4B6C9B87DC2ULL, 0x687629D9CBC477BFULL, 
            0xB9A9C67E04D5DBAEULL, 0xC885E33970EEEADFULL, 0x8BF202798716C516ULL, 0xEF8B947E67F4C791ULL, 
            0xC4B7E7939D49DBCDULL, 0x0F90D2CC217E386CULL, 0xD96DF07F1C2C8B84ULL, 0xD9D6860CE319018DULL, 
            0x8C04923C751B4BFBULL, 0xB1292B1FFA88FE55ULL, 0xB82DCADBF42FF4D7ULL, 0xDDEAB6EF1B139D83ULL, 
            0x94EC9FEB434BE5E8ULL, 0x27C82472162AEDCFULL, 0x30B841B927ED13DBULL, 0xB364AE5B2E8905D2ULL
        },
        {
            0x15301A7E1BFC625AULL, 0x91F1321D2D622420ULL, 0x302D0C711548881BULL, 0xB3B1CBD60C797C0AULL, 
            0x8DDE02DE0520A74DULL, 0x03658C3E6AB86533ULL, 0x10E1EEE27ECDCE68ULL, 0x31FDB82086FF95BCULL, 
            0xEF5E949C8258F07DULL, 0x725C4ED04C88EB0CULL, 0x94DBDC9906A1F833ULL, 0xDDF0FFA42694F477ULL, 
            0xA32644FB79646CCCULL, 0x2885BE2F00BB822DULL, 0x0BA17F00144B65ECULL, 0xF9CC50362FDB37C6ULL, 
            0x2E97D67E18433DC1ULL, 0xBF5DE4F4EA5EEC2EULL, 0x47F9217AEA8C3747ULL, 0x354BEACED60D74E3ULL, 
            0x7B967BB1E2F500C2ULL, 0x5128173871E8461CULL, 0x84C49C117D7CEC24ULL, 0xB3FCCF515512E0B3ULL, 
            0xEACF8429836A06D2ULL, 0xA4FEFAAF23C9FC3BULL, 0xD98A29653D6631B2ULL, 0xC24DBF1C01252883ULL, 
            0xB74A84BB7FF2247BULL, 0x0FC355AB6FF50561ULL, 0x7982861520AA0A3CULL, 0xEF648A7AC3722782ULL
        },
        {
            0x3A752D8CC241E0C6ULL, 0x074CDE4A6CA2495DULL, 0x8661B7A9685974A0ULL, 0x9656150D61A2B9ECULL, 
            0xA2F610DB3E284CF8ULL, 0xCD4B11825D7EEB7FULL, 0x35AB902396FF536BULL, 0x5936B0D6EBF79AFBULL, 
            0x67FD724DE3B13908ULL, 0x90E44980BB2999CCULL, 0x7A6FD675993BBB2EULL, 0x40D428E16FAA62D1ULL, 
            0x2054A588B28B4353ULL, 0x4AD2B832E0976CC6ULL, 0xDB14D73560B7D0C1ULL, 0x08A178C3E9B6B537ULL, 
            0xBD95BC111A3E6259ULL, 0xE50820F187CC0C72ULL, 0xFF84D0D0D139ACEFULL, 0x37E0FA8E3D2A8EF6ULL, 
            0xBEC2C626CD7B35FDULL, 0x40C9B95DF649C021ULL, 0x794BE63C7D915F13ULL, 0x07F7B2B6543F0B74ULL, 
            0x0C92F5F1C917445FULL, 0xA481C04C130C06EAULL, 0x3C6F1C62C760E8E1ULL, 0xF644EF05880F56ACULL, 
            0x4573DB7A507EB28CULL, 0xDE945489A1DC239CULL, 0x2278F7E193AA8833ULL, 0xBA4F543D0381B801ULL
        },
        {
            0xD4BD3574DC70BE3BULL, 0x8C9B8A50D903A8CDULL, 0xD4AE8525842604F8ULL, 0xB5DDB408F3C05BFFULL, 
            0xEE210FE90C20F5BFULL, 0x35B22677C1F84645ULL, 0x0AC9F83754BBE67AULL, 0xF504C82F31FFB40EULL, 
            0xB815A3B05610D73BULL, 0x12FD6C2C5E569C48ULL, 0x167D7FD2181BDC31ULL, 0x6C1563A2916519B4ULL, 
            0xDAA54319761E343BULL, 0x34F743CA25E88770ULL, 0x273C255580CB8289ULL, 0x8F8FA27341EB54B3ULL, 
            0x651751A4CDAB90FCULL, 0xBCCF052F300EA6C3ULL, 0xCDB23602CEE9C381ULL, 0xAFE9B29C98E2ABDCULL, 
            0x777B44AEE8F74732ULL, 0x717D5F1B19F7B407ULL, 0xC9295B95B424CB9DULL, 0xD66BB8677ACCF83DULL, 
            0x160D6E57355F41C5ULL, 0x467D1B6A72B6337EULL, 0x13EDF4A3F9425C25ULL, 0x933C3A8F9B538DA3ULL, 
            0x94DFECB01A174C9DULL, 0x7BA3DDFCA1A66B0BULL, 0x0708E974C5483670ULL, 0xC4AD4036A7965AB8ULL
        }
    },
    {
        {
            0xE0E206ED594EE593ULL, 0xD8B1D25D35BC2228ULL, 0x06708D2A741B5214ULL, 0xF13ACEF70FC56AAEULL, 
            0xFF46EFFC0E984668ULL, 0x267716586860C2FDULL, 0xCCEA739A92AE3738ULL, 0x04586040C4BB647BULL, 
            0x6E7DC9EFFE8E36B2ULL, 0x1C61D619B3A55F67ULL, 0xF4125FFD59CF6B19ULL, 0x7AA2D9270BF762D8ULL, 
            0xFD5C5B9DE77B716DULL, 0x31735B70F08DB40EULL, 0x95709E1E90C1B091ULL, 0x40069CD593B7195AULL, 
            0xFE5F3006EB9CBE31ULL, 0xD38CC494478E9146ULL, 0x64451FC921F84271ULL, 0x16FA15C95B69506BULL, 
            0xEA8781CAC1E95F0BULL, 0x21628527BE1B82EAULL, 0x6E13A37B349087B2ULL, 0xF528EDA226A899F6ULL, 
            0x2BA49AF65BA56DCFULL, 0x61B08A1945A843E2ULL, 0xE2654E65CA24B4D1ULL, 0x7374CF23D802236BULL, 
            0x241207C5B10ABA99ULL, 0xC8FC8DEE2366E401ULL, 0x2872F41BEBC24276ULL, 0xC53B1B44AFBB60BBULL
        },
        {
            0xF7DE39386051E104ULL, 0x1E5ECCDA1BA02FA7ULL, 0x151506845ECECADCULL, 0xDAD06FB09766D74EULL, 
            0x6A63943FC393812EULL, 0x220FAF3D6A7C8F3CULL, 0xA9C1B2D2948DAEC5ULL, 0x51980C85176F269CULL, 
            0xCA6F96138E141FE3ULL, 0x4000DE5C3C7100D9ULL, 0x0F6BF7E692ADF7BAULL, 0x7566712F46CC99C0ULL, 
            0x9A2EBFC50BA1A0ECULL, 0x10BF5715BB369E4CULL, 0x2EBCBF14A890232FULL, 0xF41FFEB1BCCE8417ULL, 
            0x19F983DAB1ACDB20ULL, 0x5933653A6DEACD97ULL, 0x9859BF0565C15F3CULL, 0x8CDB96EE292CCF00ULL, 
            0x7406C6748ECDE74FULL, 0x0CCE53FCB098E543ULL, 0x538B9DA8F6895D97ULL, 0x7A7F7D871ADC26ACULL, 
            0x29C3EE7EC145EB26ULL, 0x67C558D8C13207A5ULL, 0xA9F1C5FAE79D21FAULL, 0x69E3BDFB3AFF24A1ULL, 
            0x3176CD2B494B1138ULL, 0xC678A9DD267DA96BULL, 0x278C2FD4E7F3BA2DULL, 0x09BA973FDB5223CDULL
        },
        {
            0xEA34F2B11ABFE835ULL, 0x348747586FDC6F97ULL, 0x3B08AB4D5B504F83ULL, 0x53FBE5168FD2BE36ULL, 
            0x35A924E40A7F1D6BULL, 0xE7DD587D89BC961DULL, 0x9BC90197F1A22E54ULL, 0xC3056B319FF80685ULL, 
            0xAD8B66090DAFC6F4ULL, 0xDB47E6C22A3C0EDEULL, 0x9E0DFCF3570EF3DDULL, 0x9657CB343316E59EULL, 
            0x87BF905E3CB21EB0ULL, 0xDC7D2666892BE9D0ULL, 0x8CF397BC95AC3117ULL, 0xC082B54F17843130ULL, 
            0xDD234D572DDBC6C9ULL, 0x206C5181BB73DC7DULL, 0xB1F786185AD6E0F1ULL, 0xA46AB6B6A40BA1E6ULL, 
            0xDF5E9B94C1B10921ULL, 0x86232851C3C13CB2ULL, 0x25127F6800566FE7ULL, 0x6BABA289BE4AF28DULL, 
            0x40C475DB20F55B35ULL, 0x97EF9203FB0F1D38ULL, 0x81139C10D7B582F4ULL, 0x7E245C918D6182DAULL, 
            0xE34933E4C180B0B3ULL, 0x933E991D64344D0EULL, 0xF9182E6999F05DF7ULL, 0x778EC19958E9ED98ULL
        },
        {
            0xC1C71763D5A43E67ULL, 0xD052092E9AAE4D3BULL, 0x5BA4214DD539EFADULL, 0x510C81FEABE72C58ULL, 
            0x8F9E09E23E6F8532ULL, 0x19E1650E6C0A90F3ULL, 0xE1836B6B5D80C765ULL, 0xD5C40BAF25DF2A31ULL, 
            0xA822AA029D967B51ULL, 0x15D856A1FF962E09ULL, 0xF8A19D149D4C7DD8ULL, 0x9BF5CA2497F7C954ULL, 
            0xE3A1EDD102007F38ULL, 0xE1EC019A2766704FULL, 0x194C4E7790528CB5ULL, 0xE1F645FF3CA1C205ULL, 
            0x33D02F9A471653B0ULL, 0x4C0E3C6CADE5A262ULL, 0xD624FED6554E3B63ULL, 0x51ADC3EC08252B58ULL, 
            0x2BF68BCCF41F94F8ULL, 0x088B40592D6D7A58ULL, 0x90B863EC485CB35AULL, 0x5891BEB3FB04DD52ULL, 
            0xFBCE3A615E66078FULL, 0xE57F1DF34025B6AEULL, 0x630E3F8D5364DD3FULL, 0x50CB5AC0C3CD10D5ULL, 
            0x4B2F09A7D1BB8A84ULL, 0x895930901621DAF8ULL, 0xE45C9D9F4701C179ULL, 0x66679CFEF22D0DCCULL
        },
        {
            0x08D53CF31F55EC80ULL, 0x28F888341949998BULL, 0x7ABB72A0D5704FC7ULL, 0xDC54AA3D8D54B575ULL, 
            0xA0DDBC3C6C32A126ULL, 0x0FDC4777ACE687B3ULL, 0x58E82381C7DDCB07ULL, 0xF745F0A047105DB4ULL, 
            0xDDFA7E2160F255A3ULL, 0xC396A60E1910770AULL, 0xBBA9C82C16E5CA90ULL, 0x5AD0375AA4F29E0DULL, 
            0x8EED79C0939277B2ULL, 0xADF696598E2B99ACULL, 0xCDAC2330E6B0A7D5ULL, 0xAA7BA39CE6DCA2F0ULL, 
            0xE59B5C8F60DD4290ULL, 0x85518CF20733A23FULL, 0x3108FF4C86EEFE1BULL, 0x3EE83001DCB98FCEULL, 
            0xDDD9E3CB5EA158BCULL, 0x7B997FD42FA527A6ULL, 0x0150A40051C3A25EULL, 0x136F3BF7EDAFB600ULL, 
            0xDCD044CA9FA53CFAULL, 0x106752F466227EF1ULL, 0x90005ABA1BCC4E6DULL, 0xC9C39A94E224280CULL, 
            0xE39AD0F998B3B91AULL, 0x3BA4A4A8ECB1DF97ULL, 0xDAD61CC44816E2A4ULL, 0x18D1DD30C092AF2AULL
        },
        {
            0x30E9E192252F6053ULL, 0x8B00ED148419E37FULL, 0x9415B15D9D373B0DULL, 0x015DF0A10623EE12ULL, 
            0x2FB27889387515FEULL, 0x1C96183C2CC1837CULL, 0x97ADF0C85117847DULL, 0xBD31FCDFC69D5C34ULL, 
            0xF034AC310568A5C3ULL, 0x053823F3D320B530ULL, 0xE17FA03026E2E7E7ULL, 0x38E1A73B507CF9F8ULL, 
            0x12F62F985D95054DULL, 0xCC7B7FEFD70A4FF5ULL, 0xDE5EF327E522908FULL, 0x0360C6DD5EBEEE54ULL, 
            0xF9C887D27E7DF380ULL, 0x9826B2D2D3172B1DULL, 0x7D3114288054DC93ULL, 0xA165B05AC43F3A5FULL, 
            0xC78458C31D2261C9ULL, 0x3E968151A84BCE84ULL, 0xEB97CFF9A5089EA7ULL, 0x2188E540D77B8487ULL, 
            0x7B0CD497D9CA59DBULL, 0xEF6F68187AA19F30ULL, 0x0BC0E339B5FA9E1EULL, 0xDB5CBD8E559567C1ULL, 
            0xE9CAF088D8074C0CULL, 0xDA9CD1AC68088D0FULL, 0xD3329BB493CDA41CULL, 0xFD1A9B27E9E42E71ULL
        }
    },
    {
        {
            0xC330290F5BA28124ULL, 0xDBE4717A692B378EULL, 0x66678898A7A37781ULL, 0x973339BAA7EA45FFULL, 
            0x0E67C723C2068107ULL, 0xFCC3FD6FED0671DCULL, 0xCA6E9A6FEF31BA83ULL, 0xE59DD4989C5A9779ULL, 
            0xC3EB7C2A5FF794C6ULL, 0x1E05863200079073ULL, 0x4CDAECF6B2032852ULL, 0x098787E7C51B0B09ULL, 
            0x9B663308B02EC86FULL, 0x6A1C4DA33CC32BC7ULL, 0x38DDCEFBA3D60AE5ULL, 0x92717F8EEDF4E711ULL, 
            0x0E0DC98C5E0C25D4ULL, 0x4EEB52D20DA863CEULL, 0x039EB398A231004CULL, 0x710D3335F7B8D8B2ULL, 
            0xD7B8309B9D2E3971ULL, 0xCEADBD7085F0A45BULL, 0xBB25DA8DBAFFA28DULL, 0x6B7496A1BC27E673ULL, 
            0xADED38F38EDA62E6ULL, 0x96CA60078C8C344AULL, 0xE026A18B0614C961ULL, 0x4D9F9F19A9D03D41ULL, 
            0x542574481FB4AF9BULL, 0x39D232932EEE8706ULL, 0x67850B30C0D244DDULL, 0x1892A7485948D571ULL
        },
        {
            0xE01743644629DA28ULL, 0x91AD157CF53D0C62ULL, 0xF302DAA9FB1E9DC2ULL, 0xE3AD40C27882EE8AULL, 
            0x8AB9E20839A969BAULL, 0xBD700E92033B5AADULL, 0xAAB3E711BBFD64CAULL, 0xF2D9D8F88B8C212FULL, 
            0xF0A030BA3D1F9BD6ULL, 0xA3A57B06AD005B3AULL, 0xE8EE73FA0F276988ULL, 0x6BA2CC5AF6DB8E81ULL, 
            0xDB696209C0457464ULL, 0x853C5F3AB602FB79ULL, 0x872AB11F375A47C6ULL, 0x6E1F39D03E6EF12CULL, 
            0xEDFBE1E910806D17ULL, 0x0970658EEC69A67EULL, 0xC0CA87927A1E372EULL, 0xC672B1283C2E0AE0ULL, 
            0x434F859DFFA6B552ULL, 0xE1D7FDD6AA045BDCULL, 0x48FE92C587200599ULL, 0xA6731BFAC791251BULL, 
            0xA2740C88BEF0FCAFULL, 0x3A33E6E321F38241ULL, 0x29B8413EAA805BD1ULL, 0x2DBF4DD3FD382A4DULL, 
            0x907BF7E7613D1A43ULL, 0x66B47456455E0072ULL, 0xFA85FC3FA255562BULL, 0xBA56B28CDBFC91DEULL
        },
        {
            0xDA120A391A4C7A57ULL, 0x3201F7C2FEE395ADULL, 0xC7299404AB7B3F6DULL, 0x8B9BEDA0B4D185C8ULL, 
            0x551E28AB30810338ULL, 0xB6AA2DCDF664B563ULL, 0x8310ED0FDF8BE528ULL, 0x6EE1DFB5E73773B2ULL, 
            0xEAB1CCD39D08DEFDULL, 0x6D3714F6FE76D5E2ULL, 0x74C4B17B2BA96ADEULL, 0x8E1D7960D7984601ULL, 
            0x7803C5F77EFD20C6ULL, 0x24550B6552D8EE51ULL, 0xF1559A16A59B6C23ULL, 0x13E04367069D8800ULL, 
            0x2CD579CA8B51CFCAULL, 0xFA733966A15206B0ULL, 0x8643F709CC45B2EAULL, 0xEAEA1FC072F4DC6BULL, 
            0x2F03C22D85A956D6ULL, 0x08A02232C9B10A87ULL, 0xCC7AEDA941FFABF0ULL, 0x572E6BA3F2CA3E89ULL, 
            0x9E75FAAE3AF51F89ULL, 0x319390398189B2C1ULL, 0x3CC0686FD95286EFULL, 0x8D08D182F8E3F592ULL, 
            0xF227B1A2271CF3E9ULL, 0x17ACE77E752406E8ULL, 0x4DEFD91A6FFFCB17ULL, 0xD723588DDE05F8CFULL
        },
        {
            0x779D98E40A8D2F96ULL, 0xF7590F5A3CD65BC0ULL, 0x801C998B742448D3ULL, 0x10BC65D18492BC64ULL, 
            0xBC2FA90FEBEB528DULL, 0xBF306F31A127D189ULL, 0x741B4B6D8EEA53E5ULL, 0x6D96DFD956112791ULL, 
            0x40151024B1B78265ULL, 0x18233835C00A0586ULL, 0x35F5AFF8696D6007ULL, 0xF41CA91FDC2453E4ULL, 
            0xA0D62E9D2D893601ULL, 0x743786F1265F20EDULL, 0x6E3D39CE6F780B18ULL, 0x27FA42AB69E9677BULL, 
            0x349A751984FCAEA2ULL, 0x915FBEE4728EAF99ULL, 0xCEEBDFBC2EEE2B34ULL, 0xE95F9D643B59CADEULL, 
            0xB28476642EE921F4ULL, 0x4BA4846E2C8C851AULL, 0x46BB63421A6E07BBULL, 0xF1E5C94EDCD6E366ULL, 
            0x3DF722F71B7F28CDULL, 0xDBDD2E4CA7AA9BA3ULL, 0x6C6C41BE5E09597FULL, 0x0C5335B1ED46D48EULL, 
            0x2076F32C0200D755ULL, 0xF5300ECBB0DF3DD4ULL, 0x37CEAA67D902739EULL, 0xFC7EB2AE43EE5E93ULL
        },
        {
            0x7CDEB73161DC8FC9ULL, 0xAA7799C01254AB38ULL, 0x30AF87076120CF3EULL, 0x7CE6BA96E161C015ULL, 
            0x439CAF18B6A212DCULL, 0x284786C810F9D534ULL, 0x7E0CA49E141E6384ULL, 0x1A96BEC9186F0C4FULL, 
            0x04F252F78B3D9A2EULL, 0xFD5272E0716C25FDULL, 0xFDE37664592203B5ULL, 0x56C0DC73EECD2D75ULL, 
            0x5ED20C59120DC3A4ULL, 0x84D313CC67822955ULL, 0x2226B9E83B690F5BULL, 0xDF0FF0BA75B560A6ULL, 
            0xC10D6933FE52842DULL, 0x246E0D65582F0C52ULL, 0x7F2B2222FA332E46ULL, 0x40AECCDA945A7FCEULL, 
            0x833DACD74E6007E7ULL, 0x8B5DF52C73A3AA4EULL, 0xFBCF887D966487C8ULL, 0x384EDF6D761F6C39ULL, 
            0xA928A1B23917AEBEULL, 0x1576F4CFEFB76E4DULL, 0x2D14E2D762D51EA6ULL, 0xB33828D549454629ULL, 
            0x8679DA00BC360E2DULL, 0x4CC57DE4003BBB60ULL, 0x02BCF93EF637F145ULL, 0xFED1E5E3CA9B9D28ULL
        },
        {
            0x2F01909EDF035D2AULL, 0xE48E552BD2E3DC86ULL, 0xE805CB2C08F33B09ULL, 0xEAD3DFBD92831165ULL, 
            0x7B099FFCA73943B5ULL, 0xD64991F3D04933CDULL, 0x12029D920FF1C3DCULL, 0x333917EC9549F306ULL, 
            0x02622CF445E5992AULL, 0x28B8A785F808D814ULL, 0x9A98F83EDED27ADEULL, 0x906C4E119D643574ULL, 
            0x14C80FA198AA3FA7ULL, 0x279676DD6142FCC7ULL, 0xC1E747436CC16ABCULL, 0x06702AF583DF7B2BULL, 
            0x01372057482C2FBEULL, 0xDB3F6A7D496EB49EULL, 0x248C547814EA13B5ULL, 0x801B5812E3A62F08ULL, 
            0x0E1621E2DE6E20FEULL, 0x179719686365DA47ULL, 0xE820A0800F268D66ULL, 0x90C419BC3E0EA18AULL, 
            0xD487F827E9AA72BBULL, 0x951C4790A56A6437ULL, 0x7322CE82A623C401ULL, 0x13A479535E906064ULL, 
            0x7EDE65480726B31CULL, 0x3E2E63288CD71C2BULL, 0x6B644377E0E5980FULL, 0x2568D2E0B94573BEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseGConstants = {
    0x28356AB35B540CB6ULL,
    0x5429536F04C88AB7ULL,
    0xDF3E3588BEDE0009ULL,
    0x28356AB35B540CB6ULL,
    0x5429536F04C88AB7ULL,
    0xDF3E3588BEDE0009ULL,
    0x61B55AD95DCA687BULL,
    0xCD27863454EC5B9EULL,
    0x86,
    0x61,
    0xFE,
    0xE9,
    0xE2,
    0x7D,
    0x67,
    0x4B
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseHSalts = {
    {
        {
            0x183C382D8A6201A4ULL, 0x712803D7C4147641ULL, 0x732CAD4AB0F1ADB8ULL, 0x51DF1A2E42AD9C58ULL, 
            0x31DE1D6B08D40625ULL, 0xF969DCAF952EC145ULL, 0x8E0C7F41450EEE7FULL, 0xC170C3C27BEE8D08ULL, 
            0xD2C3EF891BB27C90ULL, 0x2C4DF3EF32EBDC00ULL, 0xC919F84B07D613D8ULL, 0xD1FE6FFC5B4E8D97ULL, 
            0x1BB1B3B2977D5F06ULL, 0xFCFFA5DF7999BCAEULL, 0xA45E1930D3D13816ULL, 0x29FFFA90D02AFE2BULL, 
            0xAE81228F2A8B4575ULL, 0xC6301FBA1D3A715FULL, 0x5FAD36107B61E8F4ULL, 0xFF5CC4EA5DD5C769ULL, 
            0x30D74E8FA1311B06ULL, 0x58B58A3F097EC163ULL, 0xDD15184998EC91BCULL, 0x00466823291ABFFEULL, 
            0x74E562951B353838ULL, 0x8065EC0BDC38D5D5ULL, 0xB8FE85C3D1F7CF93ULL, 0x0F395C33C3B37424ULL, 
            0xF09578A7241267C6ULL, 0xA77CE97E15819DB7ULL, 0x83182EF65A9B7A18ULL, 0x06B62426F9A5C4FFULL
        },
        {
            0xA2961B7634DB88EBULL, 0xD9672907F817D5ADULL, 0x9FC80C2B3FCD796CULL, 0xD2C0DED4DD4BB6EDULL, 
            0x0EA8D1BF0711FD0AULL, 0xEFE115247923AF52ULL, 0x562DAAC914CB4E3AULL, 0xA09C9554DB0B9B99ULL, 
            0xB7FF97B29CB7E3EBULL, 0x6D716DC83F8C41D2ULL, 0x667CC5D68C92BD1FULL, 0xAF3C21AD132B5D62ULL, 
            0xD1934846587C655AULL, 0xB748C40F2778BD89ULL, 0x25EB38F46CAA86F1ULL, 0xBE9C50F814FF4667ULL, 
            0x039E2A8693F60EF3ULL, 0x3A545EB4E25E3A69ULL, 0xE7EFDD6F81DBAC11ULL, 0x127694A2A7EF53B9ULL, 
            0xF2FCF5110BF0B1E6ULL, 0x5C7F2FC13968F1DAULL, 0x89665F40601B0BF0ULL, 0x20D315A0DE3E8031ULL, 
            0xBBAAF2332FF9D662ULL, 0x3E9B7080238860ACULL, 0x9460A898D61291BBULL, 0x61BC9FB6632E3FEAULL, 
            0x5BA6FED7CED588F9ULL, 0x49C83A63BB93EF3AULL, 0x6148C41E840B47B6ULL, 0x40D94ABDAEF31678ULL
        },
        {
            0xEC1307B058A1E2AFULL, 0x04B44AC8A6CCF59FULL, 0x522FA0B1FE7B9E37ULL, 0x172367D4EBF8F87BULL, 
            0x0FF22CE3D7C982CEULL, 0x7C8DB76BAA9241E7ULL, 0xD9B8207212BC0CA6ULL, 0x77CB03694BC36925ULL, 
            0xC1074DC91781474FULL, 0xED963411987FC7A3ULL, 0xEB441BE2CD10BAC8ULL, 0x1B28FAF06439D699ULL, 
            0xF94334B20274BFA0ULL, 0x6FE4681C70DC5E4AULL, 0x1181CC60C0C1D247ULL, 0x94D21907EFD986C0ULL, 
            0x4842306B921C7956ULL, 0x3B6F97CE799EFC59ULL, 0x0215F748BC17BD14ULL, 0xCC1C38460987762CULL, 
            0x9A3A739A6EE93F81ULL, 0x8D5B94302AA9A119ULL, 0x2F1C106B7ABB145FULL, 0x0615074184BD27B1ULL, 
            0x42A1272FC07572C5ULL, 0x02437886D3CD8ADEULL, 0xB7E723A6ACE9B81AULL, 0x1F1CDA76C6CF5206ULL, 
            0x4F6188C2A39C6619ULL, 0xE7F25260AD3E4ED3ULL, 0xFEEF6C4BC4C15B8DULL, 0x05B8F9158AEE9A0FULL
        },
        {
            0x0623D81F729B7DF1ULL, 0x1A4976CBD4F18BD9ULL, 0x97E0B43DE0DBDD7BULL, 0xB16AA001838BC600ULL, 
            0xE41252BB6EEA28C9ULL, 0x5BDC29A4D41D3C05ULL, 0xADDC1E838826220BULL, 0x9A317379D9BDC280ULL, 
            0x48B48D1B2AAA9D51ULL, 0x3DBB41E22DAA0786ULL, 0x2C4C986A66BE373FULL, 0x2E54A13AA6A6C932ULL, 
            0xF3FE40F6435F6555ULL, 0xC870C8A759FAE772ULL, 0x0CF321CF33507E0DULL, 0xDB7156756EA74098ULL, 
            0x078D1EDD0277B2BBULL, 0xA57D688205972052ULL, 0x92FD9DE2BF3D3ACCULL, 0xAA3270707A2F5471ULL, 
            0xC4793F7EFD0D2520ULL, 0x2BBC0162CA0C3493ULL, 0x38E7D63DD47EC678ULL, 0xEDCDDF50B048A9B7ULL, 
            0xBB27E199DAC4DA7EULL, 0x7CA89A8F618B7AD4ULL, 0xE5A63459EA19AC91ULL, 0xF8182F42ECBEF568ULL, 
            0x066E19799CE16A29ULL, 0xBD96B08743747E01ULL, 0xB3EFEDDD53EC57D5ULL, 0x01E00A89D090C261ULL
        },
        {
            0x53C4CBF0168B85A5ULL, 0x4CF3B111953618C7ULL, 0x2FC6631CEF81E7B9ULL, 0xFFFF426B82349817ULL, 
            0x01A0395A06437728ULL, 0x7FA302DEA94ACA21ULL, 0xF982B05EB4733018ULL, 0x756A36E5F3068330ULL, 
            0x3A8DD12E563A7177ULL, 0x6070360BEE2E463DULL, 0x14F47B6BD00568A5ULL, 0x79DB3DF78C24F158ULL, 
            0x822A2797E4095918ULL, 0xAE5ECA61E1EA9D6FULL, 0xA944460C8A1B7969ULL, 0xCECEB27BC08C7DE6ULL, 
            0xD842CE2B4F71BA3FULL, 0xDCD9615903625381ULL, 0x21893A7651B1AEE8ULL, 0x1FDE2BC03A13A855ULL, 
            0xB171A4BC2E38715DULL, 0x55E4E8F488A475F3ULL, 0x52F03F107401CC78ULL, 0xD7E1F692F71A49E6ULL, 
            0xC50F578A7007A40CULL, 0xF5FA7759A6435C9EULL, 0xBE30E027C4387366ULL, 0xCE4B01386B0144B2ULL, 
            0x6B716BC75B49A58CULL, 0x7490E1C4629F9A0FULL, 0xC2CE3ED46A430DE8ULL, 0x0193578AD21FAFE3ULL
        },
        {
            0xC8EC9F102CC38303ULL, 0x03A2F0AA36BEDC16ULL, 0x56B564A31969973CULL, 0xB2B38BC7EFD5217BULL, 
            0xA32AF93E6E0FE385ULL, 0x8FCAC9FDEC1926B8ULL, 0x62B4332DCBF1D84EULL, 0xAC5E8EE85F83F0AAULL, 
            0xC790F1BFAB987088ULL, 0xA3556449F4D88372ULL, 0xA2B832D18AFC0721ULL, 0xEAFFC7B6764393C8ULL, 
            0x5C930933069A769AULL, 0x5EDF5FF5CC2C3324ULL, 0x45904AB60B32BB5FULL, 0xEFCD66212188B3D3ULL, 
            0x7646F7610B83274AULL, 0xF5E2D196021A831BULL, 0xD476084D0A46887FULL, 0x1B5F1DD3319BACCBULL, 
            0x3552B2C1BE9527BEULL, 0xE1C0EA257223A2B1ULL, 0x0684F6A316B02194ULL, 0x4FB95F6FC2C55F3CULL, 
            0xF0B7955F2920B0F0ULL, 0x9F7FB29604B7DF5EULL, 0x22716B9E8262464DULL, 0x4B821AA0715D3694ULL, 
            0xC507BDF5E16EB56DULL, 0x795A461370E73F63ULL, 0xC10C6C3FE6F966BCULL, 0xCCAA22F4BC575A6CULL
        }
    },
    {
        {
            0xE1F29DD39FCF704DULL, 0x56383A4C72528275ULL, 0xC0BEE03CEAA53A8BULL, 0xFD7FA3E341A47B1FULL, 
            0xD896F3A005C01B89ULL, 0x57796BE19FE7F5BBULL, 0xABF67EF3AFBA480CULL, 0xAB1991D469A902A2ULL, 
            0x4D96DEDBFCE2B915ULL, 0x5AE47E5C9A43683AULL, 0xDCD10B7F0E25623FULL, 0x3A57C40EBF409516ULL, 
            0x540C7095F1BA869AULL, 0xF4B2669F510D5C42ULL, 0x57B9970E7E5E80B9ULL, 0x315AA6700CAA6F67ULL, 
            0x1D4A16A256F5BD00ULL, 0x8CCCD523152F407AULL, 0x1B48A4DE674B6402ULL, 0x097422CA23262CDEULL, 
            0x63C046FA21BD4559ULL, 0xC3FAD4F1B4D2CB33ULL, 0x1E743DC2A26F9DFDULL, 0x70A4B19EA89A8AC8ULL, 
            0x18777BD8C13F8BA1ULL, 0xA3C56D67784AD0A1ULL, 0x13CF796320190A4AULL, 0x1D7F1951F63E41DDULL, 
            0x7942AAF8FBA7B9BAULL, 0x20416C8EC4C7C1F7ULL, 0x6DFBF35F0FC591A5ULL, 0x97E66EF8E118A9CEULL
        },
        {
            0x39758B5C59E8F954ULL, 0xDC6A72F6F12269BDULL, 0xDEE319B84A57D522ULL, 0xC426F31E8A7BF418ULL, 
            0x69F1F184EFDEF694ULL, 0xDD8D25A6DBCBBE04ULL, 0x75EA39236D7B18D0ULL, 0xCE8010EC157F0265ULL, 
            0xA6CEAA417BBA739FULL, 0x0E562D41F8CD4A21ULL, 0x02BE2EEB7FC95B11ULL, 0x577B51BAACC5AAFDULL, 
            0xB838B0287E5B36F2ULL, 0x9460B2CBFCABB580ULL, 0x48D320EEE3E25401ULL, 0xCFB70E496258F23FULL, 
            0xA787E0AFEE3F58F2ULL, 0x8A3876067AED9889ULL, 0xC1D3A2088AA139B1ULL, 0x573C0934E6DC2AB3ULL, 
            0x09B0D018D203175CULL, 0xE4C0ACCB84E3E318ULL, 0x42047A1BE6B91167ULL, 0xF0BD0E43A0B570B8ULL, 
            0xDB81CB088B83351EULL, 0x664F9D7BA151C100ULL, 0x0247A1E5622ABFE7ULL, 0xE0032B7AC5770563ULL, 
            0x7350507DD19DD71AULL, 0x18255F957D87B72AULL, 0x83993427FCAF62CDULL, 0xD90BB9B39A016CE9ULL
        },
        {
            0x50EB3759F9A1C167ULL, 0xCB9CF9AF62A62BF4ULL, 0xB15BCF4664B710AEULL, 0x69E590C5226707DBULL, 
            0x92815B9F1243C382ULL, 0xBA490E3030E8A941ULL, 0x1960E28F321B9DA4ULL, 0x4AC1C45C303A20D9ULL, 
            0xA254E5A1BB76EC47ULL, 0x7F5E3DB5EFB2E106ULL, 0x0643A1D36DEDC365ULL, 0x9FCB1BD86630102EULL, 
            0xC06D7B41923C114BULL, 0x31619F78AF86CF42ULL, 0x0B0A903932B616C3ULL, 0x21D6C24555CDE4F9ULL, 
            0x2BE2AB4C2D3AA3CBULL, 0x5944E735CE7B036EULL, 0x5DB16CD681D3F2EDULL, 0x23F800DC9435804FULL, 
            0xD2FA00E25FA2F6A6ULL, 0x98AC6F9AA724E667ULL, 0x220A2FE84E2806D4ULL, 0x2B76CD59ADF6193EULL, 
            0x143A7BDF75B1EC4BULL, 0x4FF202958D641418ULL, 0xD4E29DE4EBA00B4FULL, 0xB03DBE4618866CD3ULL, 
            0xC6A4A2E0EE191513ULL, 0xAA29619C8EE517CDULL, 0x92103A37918D2649ULL, 0xCE09F85BD7E9726BULL
        },
        {
            0x6290B7B93B6D841EULL, 0x39F2C632556AAE1BULL, 0xDDB9CEC67C164624ULL, 0x4BCDFFF7AAF77D16ULL, 
            0x823319174A8A2BDAULL, 0xD7114253C8DB42AFULL, 0x0F228D2F99B878AAULL, 0x8DB907F8A8F501F5ULL, 
            0xBFB591E0C50E9F86ULL, 0x7E96CD7D8844EC85ULL, 0x7B01A25FBAE3AE19ULL, 0x97BD5DF521D582C5ULL, 
            0x5108F2774DA60B31ULL, 0x9C853D0A9988FAA6ULL, 0xD0AE59EB79B5697AULL, 0xC6BCDEF376C5E4B8ULL, 
            0x178B6D2DAADE1700ULL, 0x680DFB304A7AA3D5ULL, 0xF8D062CABF8CBACCULL, 0xC10DD2E6887CC61CULL, 
            0xA0213FD82C1FEE82ULL, 0x4F2D721DFE9AA3D2ULL, 0x6FE401E199F84B6EULL, 0x127A93EF6EA05D4FULL, 
            0xB8766BDF635627D3ULL, 0x376AFC815F60C0D1ULL, 0x41CBB3B2F67DE37DULL, 0x916977F606A98AA9ULL, 
            0x7785A8306866C8B2ULL, 0x6979FF022ABB6633ULL, 0x3CFACBEA8B738CB3ULL, 0x3EFB084BE3BA8CC7ULL
        },
        {
            0x51F5514CB05F320AULL, 0x0954E246483D7845ULL, 0x8150A29C1BCF6F79ULL, 0x218FFE892C23BF0DULL, 
            0x5AA19DADB83DA375ULL, 0x15069F9B4BC03AA9ULL, 0x960A540B1A0FA220ULL, 0x64AB7FDF86B6AD09ULL, 
            0x19994D334B4A8580ULL, 0xFE9549B62FEDAD20ULL, 0xF32158DFD42F19B4ULL, 0x7F68377A05A1EF76ULL, 
            0xE518E66D68C88F64ULL, 0x4096E6B2D0D29351ULL, 0xDD69128AA3E2626EULL, 0x80A5C7E7D0FE171AULL, 
            0x946050509EA79E5FULL, 0xD6032F85DE8270F8ULL, 0xDD3ACE0AF06D8B77ULL, 0x325CF36C562F2DE3ULL, 
            0xEE2AD1BBE0AAA9CDULL, 0xD5FA963BB4ABD618ULL, 0x1FEE1A2D0573CE94ULL, 0xE1A7EAAB1ABFDAE2ULL, 
            0xFCD74F772B403097ULL, 0xD63DBCE4BA1626B5ULL, 0x342D2C4D4D1AC622ULL, 0x4FFA70CF78D89F73ULL, 
            0x42A010EB55D3C309ULL, 0xDA98A760F7EE7C57ULL, 0x70D9FE36A22E90AFULL, 0xBC18276796023181ULL
        },
        {
            0x81BC81AAA7238955ULL, 0xFBADDB7C34F8F0CBULL, 0x930FB983E8CEF6D8ULL, 0xD603FA13F9C6E1D4ULL, 
            0xFE6B10E89BCEBABCULL, 0xC8FF778DE4F6E71BULL, 0xB4CEEF362DCDB268ULL, 0x7B395B564C313CC2ULL, 
            0x0457320E70442D58ULL, 0x1180AA977FE8704BULL, 0x48C20207DA8C436DULL, 0x5F7FFF651CD7A6E5ULL, 
            0xCEFF4B080025A226ULL, 0xCD0BE678AA8DE8ADULL, 0xD81F2C6457EDB702ULL, 0x8A355C9C465AF7FFULL, 
            0x3473997E0FC93891ULL, 0x29A689F1543392EAULL, 0x6B714D07BF074AFDULL, 0x28CCB7E97CD9D7C1ULL, 
            0xD42D56C79B900134ULL, 0xF2A31FF744484554ULL, 0xB534B1DD85FA7D6AULL, 0x256CE624BB78C301ULL, 
            0x0645B03A6D8A37C4ULL, 0x42B03AF4F460C119ULL, 0x4DFE648D9660C4CEULL, 0x101C4863CACAC524ULL, 
            0xFB2734CC53188825ULL, 0xF1D758D594126711ULL, 0x5F35AA86D76767A2ULL, 0x28EA4EAFD145289EULL
        }
    },
    {
        {
            0x9BB9571FEBBBC102ULL, 0xF9E970471213B1C0ULL, 0x5B37C2DDF7F10CEEULL, 0x51A56A0AC497898CULL, 
            0x84C323F1B6FD0DB9ULL, 0x7812C08113BC2174ULL, 0x76CCE343AFD4B0A4ULL, 0x2EB05CE9D9DCF909ULL, 
            0x286984B86DC8D9C9ULL, 0x2F1EF98B128CB8D9ULL, 0x235DE70F9261BD74ULL, 0x7ACD49BDB6A75973ULL, 
            0x4ADCA99A621A320AULL, 0x510FCEBEB9C69FE0ULL, 0x56ADAD4D16C23A2DULL, 0xDF2F3404F423D0ECULL, 
            0xA636B6AD6C792B28ULL, 0xF847FF7EEF62BBFCULL, 0x4D8E64BFEEA011C8ULL, 0x67DB52B13EBEA38DULL, 
            0x652DE583A6CF18C7ULL, 0xDD5BE771781D3792ULL, 0x2B939ED661B647A1ULL, 0x21F8E916185AA31EULL, 
            0x77DC2F97954E9488ULL, 0xC06E8BFCC09EFC0CULL, 0xFBDF539D7284E85AULL, 0xF09E99EA0758F2A4ULL, 
            0x0F9BC73E68D4EFE2ULL, 0xADA564A49C4D62A2ULL, 0x5C1E6B89AA34CE4CULL, 0x6033C188010132DCULL
        },
        {
            0xE3B180F85D1ED27DULL, 0x2F1ACB190CA22AD0ULL, 0xCDF5A1783D1747A0ULL, 0x93640DEF27E5FA8EULL, 
            0xB792B471F0593264ULL, 0x702243431D28BB81ULL, 0xFE86ACCFC3A875A2ULL, 0x47A0367FEA72713BULL, 
            0xCEF92B28ACD0886DULL, 0x1AD07E754759519AULL, 0xD1D6190514D14CECULL, 0xA73198E848FB8E1BULL, 
            0xC10FC1C0507DF6B1ULL, 0xD7DCEB726E20AAB6ULL, 0xDA40F9DA694012A0ULL, 0x2F0672954C7A74EEULL, 
            0x29EB05A60F0DEB5DULL, 0x22AF7AEBFC591B89ULL, 0x6FFD688CA9133F73ULL, 0x6A10F11D5706E1AEULL, 
            0xD676ED8C60614668ULL, 0x4D61486BA130E98AULL, 0x157A76680FEEAE89ULL, 0x51F6CC9943A6BEDCULL, 
            0xF8588B11CE35A31FULL, 0x76014C6229F73DE4ULL, 0xA543AD2191D431F6ULL, 0xE1DE0167B762A32BULL, 
            0xCA1AE3DF85FAA3C1ULL, 0xC1E326EE2AB1BA61ULL, 0x1740B15D20869316ULL, 0x48032FC1D2696C27ULL
        },
        {
            0x4F590F06401CFA65ULL, 0xDDD5289B737EF2B0ULL, 0x73B2D76430929BEBULL, 0xF9245E0B7ADE62C1ULL, 
            0x397E3BBDBCB38EE2ULL, 0x65487EDD6BA631E1ULL, 0x4863B92ABE2F8C4AULL, 0x2E28B8B0CB9063B2ULL, 
            0x1FA40F345AD49D55ULL, 0x2CAFBD3AF14BDF84ULL, 0x1A6C784BFDB8C9A2ULL, 0xB57822B1030A02BDULL, 
            0x8E4A09EF0410E73BULL, 0x652989F04A3D0DE3ULL, 0xF0FF17799EE4666BULL, 0xBE91B5F4625ED0DAULL, 
            0x644FC4FD66C3006DULL, 0xE68979C8D9C583FDULL, 0x19BC977AB0B12A5FULL, 0x35F416148DA6CA6BULL, 
            0xD81C1FD8E85E2A37ULL, 0x8F09CA2CF76B1030ULL, 0x8D22D2FBB9F8C319ULL, 0xC62FD69A797D401CULL, 
            0x117203EAF3AC256DULL, 0x1DCA096264EFA66AULL, 0xC388D74A43F3CA40ULL, 0xEF892C828EF2DF6AULL, 
            0x9E0D8C0567A1AB36ULL, 0x9D71EFDA31FC790DULL, 0x51F94320DD3592CCULL, 0x0858D0E9BA87AC46ULL
        },
        {
            0xCC734675C0F3CDF5ULL, 0x1D24A23E48A5F82DULL, 0x920ED3A31A996767ULL, 0x0FC8C5239B132ADCULL, 
            0x8D7267C2817623CAULL, 0xFC8C9ED4531C967FULL, 0x6239ADB1D891E6BFULL, 0x2BD156F427CF1B19ULL, 
            0xFF7A8826658438FCULL, 0xD17C3CECFA926C32ULL, 0xCED3FA623648D802ULL, 0x8029AB1613BE11CFULL, 
            0x300B39883C2AE261ULL, 0x305C91E2C2023838ULL, 0x5BBA670FF01523B2ULL, 0x79FA76B8AAF79092ULL, 
            0x5C3628D98C846EB5ULL, 0x16D1BFC2D6D93A0BULL, 0x0B455C8B82C93D69ULL, 0x6F25919AE61065DAULL, 
            0xCFBAD1197DA12BF0ULL, 0x70C7167A86D22D38ULL, 0x814838F8BACF655EULL, 0xBADB2F31C9F8A921ULL, 
            0xE0570AC05343657EULL, 0xB4BA9E7B24EFCE94ULL, 0x2C92198CF6FA7F5EULL, 0xC6ECE3F0C3BF8612ULL, 
            0x9EB513249094464AULL, 0x045E072807C3940AULL, 0x8BEF038125C9C8B4ULL, 0x2C13BDAB36121E4FULL
        },
        {
            0xF9DCEDF310F963B1ULL, 0x09C3EE9492EE48A4ULL, 0xE25D0C86D87C9FA4ULL, 0xBC17E12F7A368731ULL, 
            0x60DC20196A5778E2ULL, 0xC5CFEDB727663841ULL, 0x3307C17E0B643778ULL, 0x4A222CA57A4EE5A2ULL, 
            0xB61D47BA14B767C6ULL, 0xE70FCBFD8C232503ULL, 0x05E9627B6557F816ULL, 0xD86184C80BAA0EFBULL, 
            0xE123CA231F9B7DD6ULL, 0x53ECD8C73D615B3EULL, 0x8453E3E66C1187E5ULL, 0x142A48246C80A6EEULL, 
            0x4BE0A99C87AC46EEULL, 0x56D30EC6C9EDB33BULL, 0x55CDD2FE6AA60ACEULL, 0xAB371E26CB410877ULL, 
            0x12F5FA1E463AE92BULL, 0xBDA8C78B50B9F9BBULL, 0xFC99A2FB2082C02EULL, 0xEECDE99E72D656BDULL, 
            0x06A51F6119FAE8D5ULL, 0x24445A7F7C4183C9ULL, 0xF2F28935A3CF45E4ULL, 0x7E530C6A613FA220ULL, 
            0x9D72BDACA922C8B0ULL, 0x768A147C031CCFFAULL, 0x5037AC0C500D78CFULL, 0x0695C00FCAA81494ULL
        },
        {
            0xB6BCBDF7DC6F0CF3ULL, 0x08A6576FC68366FBULL, 0xC70335DCB37763EFULL, 0x2DA3A97FC05BD4A0ULL, 
            0x9C850D41F5DFFD0AULL, 0x90947D633D66A922ULL, 0x9D300CAD82F431E8ULL, 0x75EEDEB72B210179ULL, 
            0x799ADB3EB6EE387AULL, 0xE9B952735C2F2F1FULL, 0xB01272F5958D1534ULL, 0x6EA48FCDD65A9E7AULL, 
            0x397040843B76A616ULL, 0xC07E2485F6DC18F7ULL, 0xC0A99528ABA1C4CFULL, 0xAE1A6885343B9AF3ULL, 
            0x4AC7FCDB6286DF43ULL, 0x109921BD1DC6C6E2ULL, 0x0F69CA2EA710AA72ULL, 0x5819A1FF6493E6B3ULL, 
            0xA3046F3B098E6BB3ULL, 0xB3D7480F08281436ULL, 0xF92F162840ED8F9DULL, 0x45599764CD4B25D7ULL, 
            0x96DF72F8A24E22BFULL, 0x2F66A5E2F78DA821ULL, 0xF568E25ED2A77202ULL, 0xF66051279DCE8984ULL, 
            0x6AB0E685F60E057BULL, 0xE40340FCC11491F1ULL, 0xAF863BDE3107A7C4ULL, 0x2A9AD238A6C1EA57ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseHConstants = {
    0x42F7DEE414F7CBBFULL,
    0x853BD39D8E22C511ULL,
    0x90B979FE6553DB02ULL,
    0x42F7DEE414F7CBBFULL,
    0x853BD39D8E22C511ULL,
    0x90B979FE6553DB02ULL,
    0x78DC16A1577CBF5BULL,
    0x3C0B7599E9A772A2ULL,
    0x66,
    0xF6,
    0x5D,
    0x93,
    0x06,
    0x94,
    0x25,
    0x1F
};

