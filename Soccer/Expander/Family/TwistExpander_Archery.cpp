#include "TwistExpander_Archery.hpp"
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

TwistExpander_Archery::TwistExpander_Archery()
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

void TwistExpander_Archery::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x97BC17F454708AC2ULL; std::uint64_t aIngress = 0xAD97041E40337A83ULL; std::uint64_t aCarry = 0x82C1970EEF163D6FULL;

    std::uint64_t aWandererA = 0xFED24E3C82DBCE0EULL; std::uint64_t aWandererB = 0xD41F95E7D86ACD9EULL; std::uint64_t aWandererC = 0x981BE29EE280B3A5ULL; std::uint64_t aWandererD = 0xF2EACE5A3619F31EULL;
    std::uint64_t aWandererE = 0xA266EED58D5A277DULL; std::uint64_t aWandererF = 0x9F673E52BA12155FULL; std::uint64_t aWandererG = 0xC058FE02BE8AFB3DULL; std::uint64_t aWandererH = 0xBCA5BBD371603DA7ULL;
    std::uint64_t aWandererI = 0xB9541176CB426A77ULL; std::uint64_t aWandererJ = 0xB489630A20874B11ULL; std::uint64_t aWandererK = 0xA2D2F0B5D5C5FF7DULL;

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
        aPrevious = 10068187451273055966U;
        aCarry = 18308291417206060103U;
        aWandererA = 17729489375509039441U;
        aWandererB = 10316150406854301117U;
        aWandererC = 13650779864647806808U;
        aWandererD = 16578599694421106882U;
        aWandererE = 13041802227729816678U;
        aWandererF = 14656888627296701476U;
        aWandererG = 15091950294250740108U;
        aWandererH = 14113232173356943210U;
        aWandererI = 18078743113529640905U;
        aWandererJ = 11560501289558996347U;
        aWandererK = 11720582316263030226U;
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
    TwistExpander_Archery_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Archery::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xC5A1E50B857B9048ULL; std::uint64_t aIngress = 0xAC3DCA54432F49BBULL; std::uint64_t aCarry = 0xB1096BE0DB97824EULL;

    std::uint64_t aWandererA = 0xEC4631070A84799FULL; std::uint64_t aWandererB = 0xF7E4A0E8EFCD28AFULL; std::uint64_t aWandererC = 0xE5D459B2833C3B1EULL; std::uint64_t aWandererD = 0xDA72F291F23A2F2FULL;
    std::uint64_t aWandererE = 0xC06FE0A253B4BFFAULL; std::uint64_t aWandererF = 0xA8D6A7E5B2281BDAULL; std::uint64_t aWandererG = 0xF7EC8ED029DDD81AULL; std::uint64_t aWandererH = 0xE915B074CEC04106ULL;
    std::uint64_t aWandererI = 0xE4E7B793EF69C3F6ULL; std::uint64_t aWandererJ = 0xFB46024E708C7BA8ULL; std::uint64_t aWandererK = 0xAD2CC4DC2DB87400ULL;

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
        aPrevious = 14937729420348689725U;
        aCarry = 11594602969665570511U;
        aWandererA = 17352599792363428618U;
        aWandererB = 9777682849539893685U;
        aWandererC = 9556893112818644490U;
        aWandererD = 17106325970634406634U;
        aWandererE = 12235074326536259544U;
        aWandererF = 11785726729085627554U;
        aWandererG = 10659525532842419137U;
        aWandererH = 9339917109739628751U;
        aWandererI = 10789496713535901207U;
        aWandererJ = 11689773172661485791U;
        aWandererK = 18179261343111091900U;
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
    TwistExpander_Archery_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Archery::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9706141243F72D86ULL;
    std::uint64_t aIngress = 0x8D66ABB8EF794B28ULL;
    std::uint64_t aCarry = 0xF06715068CB51530ULL;

    std::uint64_t aWandererA = 0xD586AC10A1B2122FULL;
    std::uint64_t aWandererB = 0xD746C78ED3119BF4ULL;
    std::uint64_t aWandererC = 0xCB1BF02059C07BC1ULL;
    std::uint64_t aWandererD = 0xBB8E4EDB390BAA78ULL;
    std::uint64_t aWandererE = 0xD47386390E553D4EULL;
    std::uint64_t aWandererF = 0x8876B104977DB23BULL;
    std::uint64_t aWandererG = 0xAA4A5C59C7682D1FULL;
    std::uint64_t aWandererH = 0xB75000E8156DE26DULL;
    std::uint64_t aWandererI = 0xD1FAD65E752D9873ULL;
    std::uint64_t aWandererJ = 0xBA84E2F0DD9B78BFULL;
    std::uint64_t aWandererK = 0xEDF8BEA6F986D034ULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC, 1);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA, 2);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB, 3);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneB);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC, 5);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA, 6);
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB, 7);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_Archery_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Archery_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Archery::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Archery::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBFAC9B40F79F27AEULL; std::uint64_t aIngress = 0x9D1ECB36D2FD2189ULL; std::uint64_t aCarry = 0x8B4138F2D6E74940ULL;

    std::uint64_t aWandererA = 0x8A37CA7AA00E8315ULL; std::uint64_t aWandererB = 0xE06A1964F7A9DDABULL; std::uint64_t aWandererC = 0x9466AA4632CB6088ULL; std::uint64_t aWandererD = 0xF05DF4E67E7B4E08ULL;
    std::uint64_t aWandererE = 0xBC4CC3AAE8BCAD9DULL; std::uint64_t aWandererF = 0xF4FD256AA83536DCULL; std::uint64_t aWandererG = 0xEECD1415C690E992ULL; std::uint64_t aWandererH = 0xC70AC1B6ACC98C64ULL;
    std::uint64_t aWandererI = 0xACC917FE24A66646ULL; std::uint64_t aWandererJ = 0xE41DC928277AC4C8ULL; std::uint64_t aWandererK = 0xFED6FDE7164A95E8ULL;

    // [seed]
    {
        aPrevious = 13099662322786465526U;
        aCarry = 13392479658678989290U;
        aWandererA = 13020656518241241869U;
        aWandererB = 11149706993085259026U;
        aWandererC = 15002067660141490351U;
        aWandererD = 12447881532329725154U;
        aWandererE = 10395448406179116333U;
        aWandererF = 10220034342444550446U;
        aWandererG = 12175015175332248699U;
        aWandererH = 9562398916008969134U;
        aWandererI = 15544377378652666256U;
        aWandererJ = 14983112513561600241U;
        aWandererK = 14392627870558598762U;
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
    TwistExpander_Archery_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Archery_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Archery_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Archery::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 3, 0 with offsets 284U, 1890U, 2690U, 423U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 284U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1890U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2690U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 423U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 0, 1 with offsets 2339U, 7353U, 6488U, 5873U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2339U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7353U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6488U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5873U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 1, 3 with offsets 5743U, 5097U, 3806U, 4413U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5743U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5097U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3806U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4413U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 2, 2 with offsets 6561U, 2497U, 1636U, 192U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6561U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2497U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1636U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 192U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 3, 2 with offsets 822U, 432U, 765U, 1114U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 822U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 432U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 765U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1114U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 1, 3, 2 with offsets 84U, 177U, 220U, 227U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 84U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 177U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 220U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 227U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 2, 0, 3 with offsets 228U, 113U, 1446U, 377U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 113U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1446U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 377U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 1, 3, 2 with offsets 106U, 255U, 1332U, 1113U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 106U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 255U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1332U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1113U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 2042U, 455U, 805U, 1970U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2042U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 455U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 805U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1970U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Archery::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 1, 3 with offsets 1734U, 3420U, 4932U, 4704U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1734U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3420U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4932U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4704U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 3, 2 with offsets 2841U, 3241U, 5042U, 8178U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2841U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3241U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5042U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8178U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 2, 1 with offsets 6396U, 3467U, 5485U, 7386U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6396U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3467U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5485U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7386U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 0 with offsets 926U, 5285U, 7369U, 6459U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 926U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5285U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7369U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6459U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5889U, 1563U, 5210U, 2473U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5889U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1563U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5210U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2473U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1625U, 762U, 1702U, 1670U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1625U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 762U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1702U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1670U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1566U, 1842U, 1590U, 2000U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1566U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1842U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1590U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 2000U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1835U, 1020U, 1998U, 1889U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1835U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1020U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1998U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1889U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1519U, 925U, 1923U, 523U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1519U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1923U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 523U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 2, 3 [0..<W_KEY]
        // offsets: 1580U, 1785U, 1460U, 1752U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1580U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1785U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1460U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1752U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Archery::kPhaseASalts = {
    {
        {
            0xED2480C6BDE52D28ULL, 0xA3EEE6EC8E1172D7ULL, 0xF6FF1839F2162081ULL, 0x4FD863E8D590115FULL, 
            0x98A192A8B0C8E439ULL, 0xF5E5A2DADA39E2D4ULL, 0x0DCB13099446F793ULL, 0x7326F33869B186B8ULL, 
            0x872429EDBF35E937ULL, 0x365720CE934A3D8BULL, 0xF169B1D0F2BF1A1AULL, 0x7D672735756C44D8ULL, 
            0x0A12E65ADE93C7FEULL, 0x03C1E36758BAA84DULL, 0xB28CA07A46B161A4ULL, 0xBAFFCB2943480E46ULL, 
            0x7617E61115082082ULL, 0x987D477ED9D19CD9ULL, 0xDF47ADB3DE92DA9CULL, 0x706F4AD7106135FCULL, 
            0x7EE6DC5E6E61B67EULL, 0x7941933BDDD17E35ULL, 0xD5D5D95C51A6EED6ULL, 0x87F39CC8833E523DULL, 
            0x15A351B829317FF5ULL, 0x2B327454DD2CAC44ULL, 0xDFAAF86BB42DD043ULL, 0xB7EB6936C81CE7AEULL, 
            0x526A926E930736B0ULL, 0xCD30E761FBAAE829ULL, 0x2F7E9F801E6B0028ULL, 0x020B9E913A400050ULL
        },
        {
            0xD78F579C9B5FDCEEULL, 0x2F0B01172DB8E28DULL, 0xBCBA46FF9D033578ULL, 0xE23E8AA1E27333C2ULL, 
            0x52B9314C4EF8A61EULL, 0xE1878E0D65C7FBA2ULL, 0x1BF3026C45FB0319ULL, 0x9FD21D54C71C5DB2ULL, 
            0x76486C8B782E9285ULL, 0xD075791798E7F58CULL, 0x7D673F97005B90CDULL, 0x2AA084509151548FULL, 
            0x04B4555B4EEFB462ULL, 0x0CDA5BEA8A08116AULL, 0xE36BE98FA6939EEDULL, 0x8EECAD48735173F5ULL, 
            0xE3F449C15A8B31D5ULL, 0x1C476C55E446078FULL, 0x1201FFD6FCB22BDAULL, 0xA5AA848C63B0C51BULL, 
            0x24F46394BA327FBCULL, 0x3730CA0B4E60A24CULL, 0x532471464807B697ULL, 0xCF7EA86D5FD444ECULL, 
            0x08A47D1B75970C25ULL, 0xAE709B99A5D35D91ULL, 0x8399D17F52550555ULL, 0x4C94F7B7FD05B0D4ULL, 
            0x5F49194ED176448DULL, 0x3DDEAFCCCEBA85CBULL, 0x8FC048BC8F749ED4ULL, 0x209F1A3E47E57FC5ULL
        },
        {
            0x54CE0ED9DCC19779ULL, 0x3E97B32834BE863DULL, 0x794190CBE13845A7ULL, 0x1D3F4D1ACB32BD6BULL, 
            0x1BFCE26B69E68271ULL, 0x98A388BE7CC8CB3DULL, 0x473B694EA765368AULL, 0x28028F1CE786BD02ULL, 
            0x93821794B7F49C5AULL, 0x041A954B4470F719ULL, 0xE8BE196EA1C551ECULL, 0xB6BB65869EE16EE1ULL, 
            0xCB33997D430A4CA6ULL, 0x2FE558E5D16479E1ULL, 0x9F975B054232B770ULL, 0xD6B49299EBB892F0ULL, 
            0xA934F9DF6E085756ULL, 0x3CF71A68FAA065E1ULL, 0x34CE9D50841F6077ULL, 0xEAD753B413729E13ULL, 
            0x3E19A2DA2CB2F6ACULL, 0x76FFCDA543A5B600ULL, 0x825495E83BBB203DULL, 0x78295FD5441F52DCULL, 
            0x9283F6B9D50C52D9ULL, 0xE47315948732D7EDULL, 0x83BA4BFB3145D627ULL, 0x7F7C45D06A84EB6DULL, 
            0x1104F4A5AB3885A2ULL, 0xB2408C4344297092ULL, 0x5C3A5FAEA52788FBULL, 0x884B33B27524E6D0ULL
        },
        {
            0xB70B86BC85833743ULL, 0x51E1529F3E3574E6ULL, 0x7BFE4747C4A08C9CULL, 0xD7356A2502519ACCULL, 
            0x34F4DF507748698CULL, 0x4AB22C6DFF374A00ULL, 0x7E46F07F90480BD8ULL, 0xE251FE145414CDB9ULL, 
            0xA377DA9F3DF08E8AULL, 0x66547A3576F24265ULL, 0x761726DF687920D5ULL, 0xC47D2908FB6661F2ULL, 
            0xDB94AD6FC643BB4EULL, 0x1F1FBD25E3632592ULL, 0x7D3C6469FD1F2C82ULL, 0xDC92BDFC749D15F8ULL, 
            0x408F0471A8456F9DULL, 0x930AFC129D9A7632ULL, 0x5D6A959FF1A29908ULL, 0x284CE6260746DCFCULL, 
            0xA029C605D5E9943FULL, 0x8F3F40159C7C23B8ULL, 0xB9DD81CE2047B610ULL, 0xBDA208A8D8AC9B75ULL, 
            0xE3FE24AE1D3BCD86ULL, 0xD30928B0AE6E066FULL, 0x535F008D7E06DF82ULL, 0x5C8BDC7175902210ULL, 
            0xBA33A59A10F4CE3CULL, 0x4549BEB5E8D21B51ULL, 0x345DD0C7FAF6BFDFULL, 0xAB1DDA74FB5A2EF9ULL
        },
        {
            0xB02659254A24EEDAULL, 0x6DD4B1E80556FC14ULL, 0xD4077D16258EE695ULL, 0xEB470319DC9F53C0ULL, 
            0x583D5819072DAF37ULL, 0x211E038886B1A6CCULL, 0xFAB9730ACFB8BF6CULL, 0xB5C1CABF2AAEC2D0ULL, 
            0xEFFDEEBCD530405CULL, 0x14F6CA0FA5CC57A4ULL, 0x2DC3BB06CCED1F35ULL, 0xEEA3E5D2688ABDD0ULL, 
            0x104A93E773DDF5A3ULL, 0x06D77F87347F9052ULL, 0x89CF09428525148AULL, 0x4622E755466C0B08ULL, 
            0x728B24391C6E0BB9ULL, 0x09AC3D796FFE63C0ULL, 0x5E5140D495BD5C9AULL, 0xE8B1F058DFCD674EULL, 
            0x7F04676FD6C63F3EULL, 0xCCE1086EC9685B02ULL, 0x463290C9ADCC4374ULL, 0x2A6CD5806BBCC570ULL, 
            0x69ED5E17C0B3EE24ULL, 0x3A04CE0026CAC666ULL, 0xBFA8490AA443D9E2ULL, 0xFA4087CC545441CCULL, 
            0xC39384BA67CFBE79ULL, 0xE3BCC83FAEA3A677ULL, 0xB9C1DD7FF7E9F97BULL, 0x65EEA9A22D30489AULL
        },
        {
            0x3BA66993B2386784ULL, 0x48B5B73ACFF592C4ULL, 0x73E1D5D47403AA94ULL, 0xED9420943770227FULL, 
            0xDB5FC960AD4FC803ULL, 0xB83C7CC83D166500ULL, 0x6D34BE264CE00073ULL, 0x17B806BA7EA8D8C7ULL, 
            0x598EAF8A9B57E8C4ULL, 0xA5E0FD92CC411E15ULL, 0xE9D3887A3BCB5E1AULL, 0xE9232EA334B88DEEULL, 
            0x3AC39ED18AF16A9CULL, 0x9217DEC34F609E76ULL, 0xB78EB37244BAEA2DULL, 0x1EBF7B9C97EFE2CAULL, 
            0x771BC438F703E718ULL, 0xD7B48C67758607AEULL, 0xED02B3DDECA6978AULL, 0x98342342F5D7BBFAULL, 
            0x43ABA6A580BFFEF1ULL, 0xFB630E1B329A2427ULL, 0x6A19686E3E9620B2ULL, 0x7E0BA7988E118944ULL, 
            0xA92D6440F059604DULL, 0xCCF382D66DD4C37CULL, 0x6DEB9DCBB3C0E5BAULL, 0x6D4DFEA94BDA2A4FULL, 
            0xF7D67A5A7226BEC7ULL, 0x34788E785F6C7E1BULL, 0x9FDD4FFF5F5E1F68ULL, 0x37F727135FAC279CULL
        }
    },
    {
        {
            0xE579FB9156A33BBDULL, 0x4FF99F448B5F84B5ULL, 0xFA8F87ACE2A261CCULL, 0xC2703F47F5A1D765ULL, 
            0x29B5D21E95DAD5CBULL, 0xE6518B4A5768AA98ULL, 0xD5CCFCD69217F5EEULL, 0x22206AEB5855FBE1ULL, 
            0x874543D105B60E63ULL, 0x4BBF57E126213830ULL, 0x583F2C96B9568780ULL, 0xC033234116C42C86ULL, 
            0x5F02FE3E8142399BULL, 0x2E678628194E0FC2ULL, 0xF0524F2B6D3634F9ULL, 0x2F34D4E90FE8545FULL, 
            0xC36465E87108515DULL, 0xC0E1DD0D6FEC6ED2ULL, 0xFDCA1C0777810604ULL, 0x8A58702419E5F353ULL, 
            0x385B559ECCFF1732ULL, 0x00765588DA893B3CULL, 0x2CCEE261FE5B2234ULL, 0x30152213DBCF682EULL, 
            0x42033DFFDEFA831EULL, 0x1C0F9A2F4B5DABA5ULL, 0xBB0049BA56B888CAULL, 0x6F9A11A383F46BD5ULL, 
            0x89C88E9A706C6117ULL, 0xA781BE3D9F7AF0A4ULL, 0x4F7142BB74DA7065ULL, 0xF2E393B5FF57EF20ULL
        },
        {
            0x38D111CE1324B51EULL, 0x6532933291D61F47ULL, 0x9766F655885C9D47ULL, 0xB3157A66F3A740BAULL, 
            0xE2F52FB329BD0D8CULL, 0xB14C07A0BDE04D9EULL, 0x7795C6FA33E4C9E8ULL, 0xFFAB5B67435A69CAULL, 
            0x2EE01C92E3A1C780ULL, 0x7A29A26FE43877E6ULL, 0xDAA3915084D59AA9ULL, 0x6F6DD08840AC6798ULL, 
            0xE3687332B35EFC37ULL, 0xFF2448FA564ED308ULL, 0x80F599DFBF6C0117ULL, 0xA5772008CDBB6EE2ULL, 
            0xEC0832DBA2BC4C49ULL, 0xEF42518D3BA1F00BULL, 0x183BDE7E37661B21ULL, 0xE05C49BA86CEEBE7ULL, 
            0xE974B0BC78AEABFCULL, 0x7578A9D2E9E66050ULL, 0x61B0B8DC2CE544AAULL, 0xBF013B0C52F8D982ULL, 
            0xCB5271F43D8FDCA2ULL, 0x978BB4B6899E72B3ULL, 0x8DE177DEBC5A49B7ULL, 0x7CEEFBF730FF3DB9ULL, 
            0x5526FBDEE2FC4CE4ULL, 0xEB78BD5DA8E11CBCULL, 0xA5C1B2942AF7DA26ULL, 0xA7EB48A3A8DA3E92ULL
        },
        {
            0x3056DE49084B71CBULL, 0x0C4AA23A74736D20ULL, 0x1721A331E7410118ULL, 0xCA2DC3F2E1F3A7E8ULL, 
            0x934077C2C036B691ULL, 0xAD8DFD6104E922C1ULL, 0xAD49DAB27640F525ULL, 0x34778629B379F24AULL, 
            0xBCD66BA934BBFADAULL, 0x0C2A35755CE61E08ULL, 0xD06A7321AF6CB391ULL, 0x8F95E26EBA29EE6BULL, 
            0xDEABC659B33BAFB5ULL, 0xFF71D07B0B69B3F4ULL, 0x80C9D4AEE452648CULL, 0x5F107F4FBCFB071EULL, 
            0x65C967E417FFDB1FULL, 0xD11180855F41DB37ULL, 0xAF35792BC692006EULL, 0x18BC9D749C9109D8ULL, 
            0x6D60E924F0E2CDFFULL, 0x47052C051218EE58ULL, 0x4FBC1028DD3A1423ULL, 0xCC96A90546DEF5EAULL, 
            0x777E7D1592D97150ULL, 0x52BE2C1CBAD4D92CULL, 0xD49EFDAAC7BE5D2FULL, 0x8A9440CED257CF1AULL, 
            0x81813676C8A69749ULL, 0x7003AD74A336F99AULL, 0x3933F90F112CD161ULL, 0xE1B64BDDA691EFEFULL
        },
        {
            0xB4BD78F679B19F0FULL, 0x1C17E6EEB53A4115ULL, 0x6A233F738CE8483BULL, 0x43D9242CFE86765EULL, 
            0x43F2B4066D5C15BCULL, 0x4CA3E28D1B5F99D1ULL, 0x9BBFD0177C08950DULL, 0x9C3A02A787EECC7AULL, 
            0x8BDCEA67945C8F26ULL, 0xDA7C804F22395BB6ULL, 0x317E757FF314186DULL, 0x741F59D3273AFDE4ULL, 
            0x08A078AC4063CDB6ULL, 0xBA55124B188F90ADULL, 0xAAAFB684970FFFB8ULL, 0x1EB3D9B6E5BED3D9ULL, 
            0xAF5C4A5AC574974DULL, 0x9A04CABA26EBDC65ULL, 0x7D10B335AFE9E117ULL, 0x094E0DDD3D7FA7B4ULL, 
            0x41BDA6FC43FCD034ULL, 0xAA88D2FD733ACA1FULL, 0x6E2C657F9DEF71E2ULL, 0x5CBF36804D3FA27DULL, 
            0x78AC956CF0B6C22BULL, 0xE5F263A9AB2A790DULL, 0x36F34C9B57EBD092ULL, 0x322D3830BFF74CF3ULL, 
            0xDA5175E1C2D437EAULL, 0xBDCFFE31BC92EE25ULL, 0xD1BEA9E446E84DC4ULL, 0xD3B7530E75A25D09ULL
        },
        {
            0xF208D0EE0A46F024ULL, 0xCD25C029B07386A7ULL, 0x8412ADF3BA4ED2F1ULL, 0xA04F7B5D19BF433DULL, 
            0x57C20A96DAC9B859ULL, 0x3DEC7DBAEFEB32E7ULL, 0x642226BD28ED9E3AULL, 0x54B82BFBB5821057ULL, 
            0x8169C11F40CD7021ULL, 0x16DB44739F1127EFULL, 0x1AC74748A402BDE7ULL, 0xDEE6F22352398862ULL, 
            0xB2A3C376DEB70B6FULL, 0x6A30DD0FCB7A2D4BULL, 0x8B294D8476F25DACULL, 0x236425EE237FDA84ULL, 
            0x62E995CFF9638778ULL, 0x3F7DEAD48F42618EULL, 0x28965F4962CC7EA3ULL, 0xC4BB1EC1D636E65CULL, 
            0x7B3D9CF5D528561FULL, 0x10C096EA31959A1EULL, 0x1A75ECCAC2EA0A89ULL, 0x76C4FEDB69B64CB7ULL, 
            0x8FE11E1F1D35DDF2ULL, 0x6EBB241A74AFB7BAULL, 0xCEEF066386FAAA2FULL, 0x9CD635467CEA5228ULL, 
            0xE04EB94DF9448494ULL, 0x5E190F4FAC3500A9ULL, 0x3FD468B2DE6121BBULL, 0x0797B10D5A1B7ECFULL
        },
        {
            0x807B3E5003ED6F75ULL, 0x101F6CD496A88AA2ULL, 0xED31104FEA98B7BEULL, 0xDA84C92DB6462199ULL, 
            0x1474FB2C37A8188FULL, 0xD2B70AC8A22461AFULL, 0x44A4F67A9D1A8654ULL, 0x8F2FDFF7134E50D0ULL, 
            0x9F2F5EFAADBCF7CFULL, 0x4008C9ACFA586F2CULL, 0xDC51EE52F1C4DF7CULL, 0x906540F20605E2C1ULL, 
            0x0A2B19EEBE899BEEULL, 0x8A1E1C5CF8F9CF60ULL, 0x70BDE8C677FA908EULL, 0xCA94F95AC58996D8ULL, 
            0x6096FF1E9D32B9D9ULL, 0x922AA31D43A7B8C0ULL, 0x9890BE7A981C61D5ULL, 0x8A88ED9663D61172ULL, 
            0xB304D36CD12D7282ULL, 0xEEDC70F404B800D7ULL, 0xA6EE05838FFC1D1FULL, 0x9177AC6B574E0D4CULL, 
            0x15DBB5E4610B53E5ULL, 0x76A33CAB331E3EF0ULL, 0xA0FF5883AB9A4FDEULL, 0xB356D4DBA30587E7ULL, 
            0x8FB4B298D4C82742ULL, 0x4E24448663A1DEC9ULL, 0x113CA1F761552819ULL, 0x0BC5B5C1F8FE4095ULL
        }
    },
    {
        {
            0x6D4BE2F87B15DCEDULL, 0xB3494AFF900C181BULL, 0x54AA08448D8E6405ULL, 0xE2F7C7999AC028CCULL, 
            0x09D00E06BAD1243CULL, 0x1E47FEDCADF416C6ULL, 0x7E2BD56FDD8B5AF7ULL, 0x4A1037E048FBD3D4ULL, 
            0x39892C41D9085200ULL, 0x051BDB658DF70ECCULL, 0x5DE2FF96D6174CB8ULL, 0x4E0A62A1CF1A43F1ULL, 
            0x94011D27583C094BULL, 0x9E2B2D25FFA1A34AULL, 0x57AD8ACE424F0E58ULL, 0xF34E3DD4AD7DAD65ULL, 
            0x55FA93EC5708596CULL, 0xA6B932F0CDCBBEB6ULL, 0x9A0ABFC693FAFEC7ULL, 0xE94107BA056C93B0ULL, 
            0xDB69CC0BD75CA59CULL, 0xA8E6F0AEA826E87EULL, 0x57F898D888A64434ULL, 0x1F462FD9599E9B03ULL, 
            0x5D52A2C8B2E4143EULL, 0x837E4316E726648DULL, 0xB5662B81E76727BEULL, 0x5007F40581AE6E33ULL, 
            0x0957658440ECE1B7ULL, 0x55A88B1A7C979008ULL, 0x745552B5494A354BULL, 0xC0E85B96A4170EE3ULL
        },
        {
            0xBE7D28309C2CC24CULL, 0x2E7FA90652C9ADA0ULL, 0x9D6DD6F5AC3746C7ULL, 0x7AC5C72AA3221194ULL, 
            0x0A56B57F56D23BC2ULL, 0x9A12A515E4354422ULL, 0x4E934C56DE430872ULL, 0x2949E913A2A8CF94ULL, 
            0xC9669532AF240CE5ULL, 0xCE537EB58E1A3604ULL, 0xCF22347700DC6F13ULL, 0xB68BB4145A58141DULL, 
            0x30D436E842E6A6D3ULL, 0x3B27D1D05BC01D25ULL, 0xAF688C47B105ECA1ULL, 0x950B0595B12D37E6ULL, 
            0x7EEB2655E79C1687ULL, 0x846B348F3EFB2B91ULL, 0xD410A31CE43A7946ULL, 0xD9AC337C7CC607BDULL, 
            0x1F340079D98E3F67ULL, 0xC61431E7AB30990DULL, 0x56265997FDA24906ULL, 0xF5F3628779D6BA24ULL, 
            0xF06C27F40D39EAE2ULL, 0x500C663CCC35F1DBULL, 0x9C3481996F3BF201ULL, 0xFC292ACEBFD68436ULL, 
            0xB2D064192D7CB5F3ULL, 0x308B4023403439FAULL, 0x2943247F8C11F0D1ULL, 0x3F7105EAD70C62A9ULL
        },
        {
            0x40CD09F3B808672CULL, 0x199E99E0AF689039ULL, 0x28AB7932AFDE267FULL, 0x8293D57441147CD2ULL, 
            0xE1C00B7738D89738ULL, 0x97F35576C8AC470FULL, 0xEB4A21A7958A3BA8ULL, 0x4073AC68EAB4C765ULL, 
            0x03AC2EB17F6FC128ULL, 0x4F4ECED2475672D6ULL, 0x1BFDE1D1392CFCF8ULL, 0xED8F473F8ACD6C5FULL, 
            0xDB1C7985EC30CCA5ULL, 0x914913069408317EULL, 0x71E25C997646D4BFULL, 0xB7826BE46FEA22F0ULL, 
            0x66DEE91AD4490A01ULL, 0x27CD1F7A00940F97ULL, 0x202B0B6C5F8145C2ULL, 0x9A96190A059A18B7ULL, 
            0x06E71A6163F3A736ULL, 0xD56B112C32A506E5ULL, 0x6BD57795870C0092ULL, 0x251AA9D8CE19C378ULL, 
            0xF962670A29753A6FULL, 0x83DF39FCD5C6C044ULL, 0xDA4AA1925AD4715FULL, 0xE0BDB6D5954E17FCULL, 
            0x772A2D4B428A5E53ULL, 0x0027AE43749A9BD2ULL, 0x5BC891FCBDAE19A6ULL, 0x3FC9ACB01D6E5444ULL
        },
        {
            0x00859B119495D817ULL, 0x0419DE25A91E0075ULL, 0x07BABAD0F4B40F6BULL, 0x8754D7B695816A96ULL, 
            0x504D650E33F17D10ULL, 0x5BE49C220D2E7FD2ULL, 0x507902801C67BBDFULL, 0xC6D3D5E87378DEB6ULL, 
            0x7366D651CC21E7ACULL, 0x0E2064526F06DC88ULL, 0x1119EBD7DFF7B6F4ULL, 0xC539E818785853FAULL, 
            0xBD60682E9B51DAEBULL, 0xF95B572E78A6649AULL, 0xDC172D23E55796B4ULL, 0xD6214105D223AFD2ULL, 
            0xA07E02FFCF791E8EULL, 0x99CA05684D8F1475ULL, 0x30AA5F72D846750FULL, 0x8E8B60152DBD109CULL, 
            0x0CB7B1785F72A318ULL, 0xE8A02D9DDAC1D6BAULL, 0xD705833A18AA19DFULL, 0x52DA4D7C1FB26C88ULL, 
            0xD496DD04E198F9C5ULL, 0x23F04F421C2C54A9ULL, 0xFEB4E34020D8FA9DULL, 0xECAEA820B87CA8AEULL, 
            0xB17F4AD1CE54D7F1ULL, 0x5EF33035CBED3C36ULL, 0x82F709AE2533D5BAULL, 0x951FB071779102E3ULL
        },
        {
            0x96B6F05597843F76ULL, 0xFEB49CBE9DAED127ULL, 0x02216684382B6E46ULL, 0xC31956DF52ABB24BULL, 
            0x559D4F18A82A3CE2ULL, 0x4C75B226B7894BD4ULL, 0x692AD87D49DBD77EULL, 0x05E2EC3F6CFCBE9AULL, 
            0x9A471FE97DB68E2EULL, 0xE00F307934B857B0ULL, 0x2358AA4A0F3C3900ULL, 0x5B7419CFBFA4E138ULL, 
            0xAC19641F77D7106FULL, 0x02DC7B59617D3664ULL, 0xD0A8AB619AC7F550ULL, 0x5DFCDEEF36222E11ULL, 
            0xA9B6F073F60CC704ULL, 0xADED6D0097358372ULL, 0x2FCB29E71260DE63ULL, 0x5A45803497167D6FULL, 
            0xAF803FD04422D426ULL, 0x4084232414E66ADCULL, 0x5916804EA7B1604DULL, 0x7C037E69541AEDFDULL, 
            0x4840233428670988ULL, 0x18E6DD8AD13414ABULL, 0x821A6BE2C07911AAULL, 0xC96A9BC553BBCA7FULL, 
            0x3B69FD530780415CULL, 0xEECEAD71C5514502ULL, 0x07AF86006D6D2275ULL, 0x30FCE862991642C5ULL
        },
        {
            0x9C89C91E2B4E135CULL, 0x1D33B5E3229F155AULL, 0x19467603BA1C614AULL, 0x1A9218E686D99D82ULL, 
            0x85B3267468C0DB1DULL, 0x031D798C4CFFC27DULL, 0xACD6DDAB656AD722ULL, 0x210BF49E54C8E5E2ULL, 
            0x1055188C574F2BDBULL, 0x22DF903A08F6F24EULL, 0x1911039357957E45ULL, 0x0AD5304CFD903FFFULL, 
            0x1E70ABAFBA199BBAULL, 0xD29295584731063CULL, 0xDA3B4629696DC9FEULL, 0x01D52ECF193E639EULL, 
            0xEE43C17EF74EB41FULL, 0x553D817A8112352BULL, 0xA01E92E05957B0A1ULL, 0x7E229F3190DAE1F4ULL, 
            0x553A168345810A04ULL, 0xA3DCFC5D58941C9FULL, 0x8D719B53E79861A9ULL, 0x2BC89F232ABC12E3ULL, 
            0x826B124F135C8333ULL, 0xBBFE8E5CC5C51782ULL, 0xB756FBA5687FD7B6ULL, 0x8533F457B2EFBA4BULL, 
            0xBC7F550CC909C2EAULL, 0x10CA0FE801481281ULL, 0x73A057470BADB185ULL, 0x80442A3B98B1CF4DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseAConstants = {
    0x09465A9F4031D315ULL,
    0x499633FCC392B5C1ULL,
    0xB8D75A5AAA653676ULL,
    0x09465A9F4031D315ULL,
    0x499633FCC392B5C1ULL,
    0xB8D75A5AAA653676ULL,
    0xB3653931DE3902D2ULL,
    0x6BBFCF509DB39511ULL,
    0xCD,
    0xBE,
    0x59,
    0x1A,
    0xC3,
    0x3A,
    0xF5,
    0x42
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseBSalts = {
    {
        {
            0xDE4ADB68352FF5C1ULL, 0x827C70FF736C3C34ULL, 0x5DF9ACBDF18CDED4ULL, 0x29F7E20106EF9892ULL, 
            0xD8ECA6DDC4A709F8ULL, 0x8682D19E79DEF69BULL, 0x7C6310908EBEF921ULL, 0xF4CA2CF73F19A3DEULL, 
            0x507974D33BD115CBULL, 0x400AF4FE668BC704ULL, 0x834BB0CA0B29C80FULL, 0x3D20E7968F545297ULL, 
            0x6D41B90F62670DD2ULL, 0x9366B0FC7BB38368ULL, 0x8FB2C32DF678868CULL, 0xF874ACB2EDA3D92EULL, 
            0x0DE6AC9C5C9F6FE5ULL, 0xEE4E6078FB00C8D1ULL, 0xEE1592ECCECD8D1CULL, 0xDE4C986F853CFA70ULL, 
            0x33AA6249888B86F9ULL, 0x144ECC0FE2765114ULL, 0x844023D8C1058D7BULL, 0x4A917A1C836172C2ULL, 
            0x61E872FA0A78C39BULL, 0xCA958AFB6754CCC7ULL, 0xAB1260F7A967B237ULL, 0x83A5BFFBC9AE286DULL, 
            0x54FEB82169C8F272ULL, 0xFD485036EFBDF341ULL, 0xA98B4AB67F9D1AE6ULL, 0x350E046642055189ULL
        },
        {
            0x9612070EB5C072ABULL, 0x2FC68F18AC59DCD5ULL, 0x3A0C5A7B2EC70FD6ULL, 0xEF007752F088D821ULL, 
            0x6C0F465ADE86863CULL, 0x7B4DB4A1694A9303ULL, 0x6F5AD21DF78D1A73ULL, 0xFE4CB5E8528FBC58ULL, 
            0x19E1FE429A85AF2EULL, 0x95E6D86AC1518D36ULL, 0x370C51A80FC46AEFULL, 0x33F7A4AE92142D21ULL, 
            0x623005849CC8C015ULL, 0xA380E303689AD642ULL, 0x079C033EE147B93EULL, 0x562F60D2F5E95DF8ULL, 
            0xB726375FAD2991ADULL, 0xC9EF32D4657A3990ULL, 0x1927D3FF6C6975F4ULL, 0x71C0DF09BDA215D4ULL, 
            0x35D08F54EC892D1FULL, 0xF376E16C8F48324FULL, 0x9891477DFBA7B72DULL, 0xE0F094856171EEC7ULL, 
            0x98D21F421F6879EAULL, 0xF7D753C3FFF9B43DULL, 0x876CBC686233000CULL, 0x4EA4104E1952BA50ULL, 
            0xACD695BAA8E662E1ULL, 0xA5372F1DED7A5059ULL, 0xCD651EB553D1CBE0ULL, 0xB511BD5B41728FB7ULL
        },
        {
            0xF2F0C8F7A9002924ULL, 0x5D65A9B66BCD81C2ULL, 0x8816B01DF1D357E7ULL, 0xEE2488B2D7279257ULL, 
            0x5C5CCCA811A74B7EULL, 0x4EA54648EBDDBB14ULL, 0xD3A4A727DE899822ULL, 0xEB19FC17EE3F71F0ULL, 
            0x212685587061DE1DULL, 0xE77F7C7503419D70ULL, 0x3907C02AD32F428EULL, 0x76751CCCD52C0FB3ULL, 
            0x00978BCFDC4E5D8AULL, 0x268188547D35C151ULL, 0xDD9472FE482145E9ULL, 0x06C05C38F2C7ACBAULL, 
            0x6FB0190826DAA6A9ULL, 0xC09D366C0FE94980ULL, 0xF8B6C13A29A87568ULL, 0x9D2C747F8EBD3A78ULL, 
            0xBA6A29DD37F7813EULL, 0xFDA622464566455EULL, 0xB8842C60D02D2CF9ULL, 0x3B0E4509DAC0C915ULL, 
            0x2617FF9185582C93ULL, 0x6C11BCAE446BDD2CULL, 0x729A052C22CFE887ULL, 0x7412BDFC0335C194ULL, 
            0x7FDF146DDDA2B0E7ULL, 0xF689F9291BEB5691ULL, 0x69734B59A9D61492ULL, 0x6A7F89C08B5844DBULL
        },
        {
            0x85B31DB61A0E5B70ULL, 0xBC99D975DB7897BFULL, 0x44B4352649B7E820ULL, 0x0569D1931B172440ULL, 
            0x1637C5915448402CULL, 0xF9DFA17303F8E477ULL, 0x2B0E4E5685163682ULL, 0xBB1F7176FC4D83AAULL, 
            0xE9665E45787CD32CULL, 0x5133B5A877481544ULL, 0xFF3297C55B3075D6ULL, 0x3D645133789B8159ULL, 
            0x880D06FF2CEEA367ULL, 0x3DEB1C19C8D516BDULL, 0x5EAD49952F8A32EEULL, 0xBBA7936A3EA1D6DDULL, 
            0xF548BAAFEFA5A25DULL, 0xD5F2E51C808EA290ULL, 0x6207833F6BB0EA1CULL, 0xC1AABE6CE5CE81DCULL, 
            0xC9BB393F98EEAFFDULL, 0x578E6CD0FE1D7546ULL, 0x6C9B642789BF4E3CULL, 0x6E89B220648CD330ULL, 
            0xCAECB044A2DD6460ULL, 0xCEA092761A9A6F9DULL, 0x5447DBF7F5AAB316ULL, 0x86751FCBF02A8C28ULL, 
            0x379B591FB9DAAC0CULL, 0xE9EEA5537597BFBDULL, 0x3D60BE07F08226DCULL, 0xEB9A6C8CF29B6F42ULL
        },
        {
            0x63BCF29304D7B066ULL, 0xDCC7D7438E862823ULL, 0x709CE32A69A84865ULL, 0x804F71B35D6920DFULL, 
            0xA59A1E3C713BF6D7ULL, 0xD162BD42C7B0AE34ULL, 0xF70778131A8C8D42ULL, 0xCD9764D52CF1C579ULL, 
            0xF7D8EF723E739BDDULL, 0x40DFE76389F01125ULL, 0x09634CF1AAF57F82ULL, 0x81BB10C37937093AULL, 
            0xAF61BEEB1D58612FULL, 0xE8B58C4FA9F0D2C2ULL, 0xDE730C9AC5D98F9FULL, 0x772C9A706600B5DFULL, 
            0x561D8F159196D9F7ULL, 0x0AF6CC7F67C2C029ULL, 0x5E35D70E00D48AC8ULL, 0x926565AF91319094ULL, 
            0xAB7B4AA4204F860AULL, 0xA6762F508E6D6C60ULL, 0xAC257BE1D999FC20ULL, 0xE8FC30F91C5396DAULL, 
            0x8AC02EAF42AF0032ULL, 0x320A2ABE9EDFD6F1ULL, 0x30AAD481E689EF6DULL, 0x11FCD2479B104F34ULL, 
            0xAE667A9D2AA4B97FULL, 0x5204023840A53B4BULL, 0xF488FC8CEEA46876ULL, 0x0CD0D15B1AAF7B16ULL
        },
        {
            0xFB5E042E0AA1FA15ULL, 0xC7A071992270FD4AULL, 0x9CE64DA7E5B80CA5ULL, 0xAD0CB0C33A06FD7BULL, 
            0x64E0D50D6070A51BULL, 0x2A4E45FD840D44E0ULL, 0x2D1E9885F0FF72A0ULL, 0x5DFC5A436B89140FULL, 
            0x75CA36F66EBD9FE7ULL, 0x874B048A79AC8D8EULL, 0x5DA4A12E3A1D7303ULL, 0xD3243324E7567783ULL, 
            0xF2C3B8CEAA26F636ULL, 0x14ACAFFA044A13E4ULL, 0x9F2035099D2A978DULL, 0x9E8DFD6E650A513AULL, 
            0x43D253BDC4B08CEEULL, 0xA83778B346B7455DULL, 0xBBC7A8AB7DB28372ULL, 0xFFBA6235FF8C9F6CULL, 
            0x2B5B8AB97136085FULL, 0x6C9C0E287644D32FULL, 0x5EEA25239CA0DC98ULL, 0xFD5E70726A42DFE1ULL, 
            0xC4E4B12568CB5644ULL, 0x7F7156B1901CFF17ULL, 0x174AB00ACDD8D15DULL, 0x386E81454F97BB51ULL, 
            0x86ECE8E86B82F020ULL, 0xBD20DE387FA2DBEEULL, 0xE8C2E83A71316BF4ULL, 0xCBE70E279A8B1E82ULL
        }
    },
    {
        {
            0x018A71FD9B084328ULL, 0x9B323540AB436B09ULL, 0xCFF94BE1A34A82B8ULL, 0x4545406331CF397BULL, 
            0x2E5B074E3079340DULL, 0x3A58EC4575AF4941ULL, 0xB06D638919158BB1ULL, 0xDB6F45056DE4AA77ULL, 
            0x6646596ADF88DF30ULL, 0x6261CDDCBED5F5F1ULL, 0x03F141294A85C02CULL, 0x045B713105200FBFULL, 
            0x9E55A5B5F7212796ULL, 0x36DC53BD6065F88FULL, 0xFA91976E56261F3CULL, 0x6DCD96C7AE473663ULL, 
            0xBB8CBA7823B23E9CULL, 0x743AC49147CDEE16ULL, 0x9E21AB469F1E4B90ULL, 0xEA9E8724BA66D73DULL, 
            0x5FE06C0C579C60DDULL, 0x83FC1D9DE152855EULL, 0x39915DD1397F0B8FULL, 0x040CDFD1EFF65754ULL, 
            0xD0A3512A239AAD4DULL, 0x1F709AB6E878741DULL, 0x0AB0BA731872A9BDULL, 0xCF9CB0F00AECC59AULL, 
            0x46532CAAE8EC1A9EULL, 0x492666965366D668ULL, 0x6D618011F11F82D8ULL, 0x97B7D7E548F358CAULL
        },
        {
            0x81D0FEF1A7BA7C36ULL, 0xFDAA1A9B60A5C4BCULL, 0x47CB908DCA21E4D5ULL, 0xF862F521EFE299C8ULL, 
            0xF4322BEB881E44C1ULL, 0x5AF3EE2A8551943BULL, 0x23D9A6FCD5FEF0CBULL, 0xDC7A4EC87DC6B637ULL, 
            0x0A19D71893DC653EULL, 0x28920077751BA648ULL, 0xEE0B1286C9D4B863ULL, 0x2A310A02EFF0B808ULL, 
            0x8B404C332452F7FBULL, 0x3C38CFB16A296744ULL, 0x22361ED773311939ULL, 0x866462DB3FC9A869ULL, 
            0x0DAAF4F094A0FBFEULL, 0xB226A1943F113043ULL, 0xA40B6A0EAB021677ULL, 0xBF49D25C270DD7B5ULL, 
            0xEC6A15A905BD12CEULL, 0x4E6A8B5CCFA3D399ULL, 0xFA678A3165E86DA0ULL, 0xE882CAC31D2967F9ULL, 
            0xF02925C0CEE18BDFULL, 0x9CCE92257D94FBC2ULL, 0xB439C0EE8CB15124ULL, 0x44FB3304F2A6EB77ULL, 
            0xD8C7E247FB7B901DULL, 0xD7CB9FE32012E198ULL, 0x768382CDE68F2966ULL, 0xE13F65B148414BFCULL
        },
        {
            0x9D2DFE3929E3910CULL, 0x9E194F5CA0305F65ULL, 0x18A16EE92E831D09ULL, 0x3F034DB03E250DA3ULL, 
            0xFDF4A5A3BA691FB8ULL, 0xA487BFD5A1B434A0ULL, 0xF265D305D83502B4ULL, 0x3643ED1EEA5691A4ULL, 
            0xEF5F658AE9A6FC52ULL, 0xC1F89F710A6C06CFULL, 0x958A77FE53023ADBULL, 0x3422B4B2986BB8C1ULL, 
            0x6E4DBEBE667098EFULL, 0x15AE804988B7F72BULL, 0xD6A0254B5EBC25D1ULL, 0x1D20AE6339BE9D48ULL, 
            0xA72C4990D2CD8921ULL, 0xAC106CE07CEE69D9ULL, 0x0E2E3D08DB4A9712ULL, 0xFF07B37B1945DA56ULL, 
            0x9D397D697BF26E13ULL, 0xA691DD4A3608673CULL, 0xB91E72D8A8CBB672ULL, 0x0AC730F4891E900CULL, 
            0x0158065A623EF349ULL, 0xD3C522A3103754B0ULL, 0x970EF7A5420A2793ULL, 0xCA8C76BAB1608338ULL, 
            0x5BD4070AB6B4C664ULL, 0x3614D5867AED1917ULL, 0x21F2803A3022A3FCULL, 0xB9E64891862050B8ULL
        },
        {
            0x1C1F7742DEB06ACEULL, 0x3DDFBB86791727F7ULL, 0x84D93F61512E9CB1ULL, 0x782FCB1A80B19509ULL, 
            0x4D479C2EB3C5E1DFULL, 0xABB62CA692C8C958ULL, 0xC5C50125154C5814ULL, 0x4F7B52E691EFD35BULL, 
            0xFBE5ADD701F7F1D2ULL, 0x7D20950940AAED34ULL, 0xF495D2A68442CA4FULL, 0x0499CCF223123743ULL, 
            0x2AF9AA7FAE527578ULL, 0x25C1F34F6D48FFFDULL, 0x7035011A08F2175FULL, 0x66FDBC247714009CULL, 
            0x6E9E5E85126DE08BULL, 0x888DF378F2FAD550ULL, 0x720F6C250E127D40ULL, 0x7D0ED6CE9EC29879ULL, 
            0x1699178515805430ULL, 0x792319B635210091ULL, 0x74673B028C86F271ULL, 0x284D4A70972506B3ULL, 
            0x4AF9F075B655B17BULL, 0xBB60B2657692FDD1ULL, 0x265E890C453FA1F4ULL, 0xCA200E1B1FBB9B7AULL, 
            0x5B9CD23D7AEA07A9ULL, 0x6637A7E3D91363C9ULL, 0x13F4CB4B06CE1DF3ULL, 0x849E0C27D38C3C74ULL
        },
        {
            0x465CAA920CD8C937ULL, 0x63CECA48F769881FULL, 0xE51EA47787B02472ULL, 0x4E46DD2F2576B36CULL, 
            0x14A1B3E0031A5D02ULL, 0x4510CD262B7F194FULL, 0xF5E4559E337173BCULL, 0x03D4467B8C562F8AULL, 
            0xD63467D5C914839BULL, 0xF83F61633378F1DDULL, 0xA15DFF5B41278240ULL, 0x8BCADD8C0A818AB1ULL, 
            0x35C67D548F40FA45ULL, 0x7F5AEAC7CDB12370ULL, 0xBE414AF12306FC40ULL, 0xC86C8BF285EA0407ULL, 
            0x5EEC06087C6827FFULL, 0xFA2399FD14345353ULL, 0x7FE8D1D29674D8AAULL, 0x9971353F4B4C662CULL, 
            0xC7B5FEDAEB73FB96ULL, 0x812BA34170A1D22AULL, 0xAAED87D631B8E0AFULL, 0xA0DC53290B37D7D0ULL, 
            0xE15DA19769E823DCULL, 0xB2E936348815FEBEULL, 0x813CD4CCF01248D1ULL, 0xC7215480C505C98DULL, 
            0x783087126C6F70D6ULL, 0x6E1E13506FD3094CULL, 0x75A9837CFBB9C5AAULL, 0xBEAC3417C4A03D0FULL
        },
        {
            0x70E973AE62F14890ULL, 0x294FCB84DB9D5D10ULL, 0xE570B935C95452ACULL, 0x41FA0C6F89E08123ULL, 
            0xABB4331EA821D3EAULL, 0xDF9288F7191ABC17ULL, 0x04D5AF15E1DB6613ULL, 0x9BA9E86FC690723AULL, 
            0x5A6662A06C758563ULL, 0x74BE3351D9181CFAULL, 0xC81B095A16B273A6ULL, 0x516F8669EBE9E273ULL, 
            0xC495078D6D5B67D0ULL, 0x32E883A5A47447A8ULL, 0xF6F8987674F6C3C1ULL, 0x10A8E16359456F9CULL, 
            0xC23CA604D3CD6305ULL, 0x06C1E8E5B7A1F7E2ULL, 0xF0781C4E395C2A43ULL, 0x6A9CC51E975F18D8ULL, 
            0xCDB542391D9FC6F3ULL, 0x61FB9038084F5518ULL, 0xCB68EF98150A8841ULL, 0xE3ABF10E9656CB26ULL, 
            0xAEEED53F8FBA35DFULL, 0xDDD5164AD2EB11A1ULL, 0x0844EDB82D8EF3BAULL, 0xC773A43A3754BB08ULL, 
            0xCC16714399B3A6CFULL, 0x6DFBDC3C9946FFB8ULL, 0x7B52490E2DAD2806ULL, 0x6350310349E38CCBULL
        }
    },
    {
        {
            0xE6D3A29D491EA4A0ULL, 0x9BFE9885542AFCA4ULL, 0xC8EAEC6143CEF8B8ULL, 0xC9A9E8EABF7C8082ULL, 
            0x1A829E40C3A2ED17ULL, 0x96FD6A66C30B4CE5ULL, 0x0CEA80C446DB861AULL, 0x851C384440703A28ULL, 
            0xC5873A16CA20ACA3ULL, 0x04692333776170CCULL, 0x3B946CFF2663724EULL, 0xF86754ABCE76E827ULL, 
            0x9113A289DABF5DA4ULL, 0x86E015CDFDE860C0ULL, 0x04764110D78DD2E8ULL, 0x77A8F549D3AB7411ULL, 
            0x398D8EB033AB1EA3ULL, 0x8BBD03FDC8B05008ULL, 0x1A610B5435A08080ULL, 0xD44F24C6573A1975ULL, 
            0x5B7B2F5C34547647ULL, 0xBA011EA67A1A8DCEULL, 0xEE5BF6118B1FA468ULL, 0xC7AD1AC67CC609A4ULL, 
            0x34FF6A1CB500184BULL, 0xEEB7A676BC12E2C8ULL, 0x968C31884C0FC00CULL, 0x2E3A0C2E36E61044ULL, 
            0xA31B8E45D4145E2AULL, 0x10DFD2D015E55B87ULL, 0x789BFB0B383BA7AFULL, 0xDD591ED0BC19AA74ULL
        },
        {
            0xBA3AA05E4C64784DULL, 0x47A65808F88C00F3ULL, 0x64C48271F502A2D9ULL, 0xFCB413EE52D4ADA8ULL, 
            0x87504E2546D37B21ULL, 0x2A5E38262EFAD2BFULL, 0xB8A5C693D9847208ULL, 0x2B709F83ACE0F337ULL, 
            0xEA1942C49BB65C79ULL, 0x9AFB9B5FCB9378D6ULL, 0x50A01E981002CB1FULL, 0xAC3E01928694D4E3ULL, 
            0x95A68C00143F5D4BULL, 0x82D04DB78803F857ULL, 0x8E12389423F2CD8FULL, 0x21BD21009C4DB131ULL, 
            0x7733283D46FFD485ULL, 0x0CC5FC4E264C7FD6ULL, 0x762502294657D534ULL, 0x3D781B05B9BAFA01ULL, 
            0x8A2AAEED93B52871ULL, 0x2A4127288FBA3879ULL, 0x1B631884ABE56F15ULL, 0xA51F55D6A9D17F83ULL, 
            0x502250900A582761ULL, 0x5F1F246847D67F1CULL, 0xF07CC59D053F1D59ULL, 0xCA0B044E8C2ED0F6ULL, 
            0x727E66BA9090997DULL, 0xC9451AE2E5ED0C94ULL, 0xF5A0B9F0152860ECULL, 0xE33E0D86FAF0F1A3ULL
        },
        {
            0x6D60246F359D80C5ULL, 0xBC66FEDC06D667BFULL, 0xFF06D3601488CA76ULL, 0xB3E1687659BDB196ULL, 
            0xF66E4A0F90FA5D21ULL, 0x36BD1278A5283734ULL, 0x6728CB382C6A1B74ULL, 0xB9029316A6916DD3ULL, 
            0xAE7D8C10E898E28AULL, 0xB38AF8ECCDBFD357ULL, 0x3E4AA30EC8DCEC78ULL, 0x6F82678D8CB01E58ULL, 
            0x787EBF9082E1F37FULL, 0x9DDB39B89409D484ULL, 0x57EC4CCD26FDE236ULL, 0x990371EB3F03C41FULL, 
            0xB2FE1097E338E5E8ULL, 0x4CBE1F17A891D6DCULL, 0x401ADC720BE805BBULL, 0xD732DAA2CFB82CCDULL, 
            0x73AB1E1D48313B4EULL, 0xB28FB7D551E6D8C7ULL, 0x642A83DC40C1E7EFULL, 0x44D8FA8D8203F77FULL, 
            0x5F171D1EF049B430ULL, 0x19654BA05658F08BULL, 0x8BC95158806F8BDAULL, 0x3A5456A8C9E637F6ULL, 
            0xC556681D3E17649CULL, 0x5ECCB5F1A1A5CB38ULL, 0x0E4C5B1E5D2BBD7EULL, 0xA6D07CC1EB9C25CFULL
        },
        {
            0xFEC3E12873168D4CULL, 0x464B71C389533819ULL, 0x6004E0486E801030ULL, 0x4FF74AA3D1136DB5ULL, 
            0x7D92312583BBAF5EULL, 0xB18AFB9A352C4712ULL, 0x73B3BF55B3F01154ULL, 0xB0575248E172DD08ULL, 
            0xB66B36AD8292BDBDULL, 0x8B7EBD40D76DC8B3ULL, 0xFFA9B4FF9F38423AULL, 0x2EB3573EF91BF36EULL, 
            0x0A31A25472535782ULL, 0x60EF40C5A11E65DBULL, 0x5EE8CA415FD681D2ULL, 0x1113ADD3F4A599CDULL, 
            0x27D3F0B171833E1BULL, 0x073A37148A27685CULL, 0x2CB1115FE72D93E9ULL, 0x6084B63E367A0158ULL, 
            0x58C98B7B014F92DEULL, 0xD1C3731B71D8B2CEULL, 0xD6A1590BDE4C59C4ULL, 0xBC3FFC285D86CE8BULL, 
            0x3E5C928ABAC1D8A7ULL, 0x542F5DA3A68F3C51ULL, 0xEA9DE433B9128CFFULL, 0xA7CA5E3CD252A42FULL, 
            0xC9D51C6451B1F4AEULL, 0x2B64A125C6353F29ULL, 0x24DF7EECE9C0C300ULL, 0xD1D2CA4B4C2BBBBEULL
        },
        {
            0xAC8767EFF5204DCCULL, 0x98BEC145D153D39FULL, 0xAA8421C6012772D6ULL, 0x08F6503DFDD39641ULL, 
            0xE2BEA18A696E174BULL, 0x94825B41C36801BDULL, 0xE7BF667B49E01503ULL, 0x2A097256C6AA52DFULL, 
            0xCC195B4E98141C8EULL, 0x6DE6AD683ABDF929ULL, 0x2C471C4F23562FC5ULL, 0x311738992E86F215ULL, 
            0x3D00CD2BFFE14A9BULL, 0x046BC5076E6969E7ULL, 0x709B95911C71B089ULL, 0x90AF20C4A12E2311ULL, 
            0x2E94377ADE05E71BULL, 0xA3072203B0D0DEB8ULL, 0xE66C44F31CF96FBCULL, 0x7C298098F0BA6386ULL, 
            0xCDCD8F0EB167F7CAULL, 0xEF0D58A6C18DB0E1ULL, 0xAF2A132B5D88DBF6ULL, 0x64766C40C6B069D0ULL, 
            0x593DB92FEBC93CB2ULL, 0x76D9612DF2352792ULL, 0x92E6954ECFBDA057ULL, 0x68FF3D0C2FE58582ULL, 
            0x993838A4C1F070F2ULL, 0x798864AF2614CEEFULL, 0x80E328650D19856CULL, 0x07D5E54DBB5DC880ULL
        },
        {
            0xF0D9726E814F6706ULL, 0x6662408C02E7BFA1ULL, 0x0C194E4C2F4C3836ULL, 0x1BFA486DA21E2D96ULL, 
            0x386D0642C94E2238ULL, 0xB0F6F4C156AEAD14ULL, 0x8CDBD063BBAA63D2ULL, 0x1B3F15E775AC84DBULL, 
            0x48A6AAD5850D956CULL, 0xEAC1D9D4829F281FULL, 0x6AC9E897DC0E0C75ULL, 0x341EAA7BF714E962ULL, 
            0x47B8500A3A02FF7BULL, 0x550688289C1FF79EULL, 0xD7A8624BE407E029ULL, 0xBA7C9B1097189803ULL, 
            0xFBFCC9485E7931B8ULL, 0x58AD8AE0467CB962ULL, 0x65840355A7B18E6EULL, 0xF4BA947036FFA48AULL, 
            0xDDBDF8E45DFEB676ULL, 0x3F8EAFE760F169EEULL, 0xAEEEC9AF4351730EULL, 0xDB8E699DB92510EBULL, 
            0xFB4DD47D612CB5C3ULL, 0x2CB224806038245AULL, 0xCF0EB8CC321B716FULL, 0xC45E56B876354929ULL, 
            0x78F5442EEADC30F1ULL, 0x77D17D037526F8CBULL, 0xAB33DBE9B27D245DULL, 0xB6D8356DB0F50BC0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseBConstants = {
    0xF52E575DBA19B86BULL,
    0xF3238C062AEE5E1CULL,
    0xF4A19F95F12DABE9ULL,
    0xF52E575DBA19B86BULL,
    0xF3238C062AEE5E1CULL,
    0xF4A19F95F12DABE9ULL,
    0x7284232167A52D4FULL,
    0x7EF3328182DC2625ULL,
    0x2A,
    0x67,
    0x40,
    0x93,
    0x9B,
    0x09,
    0x7F,
    0x70
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseCSalts = {
    {
        {
            0xBE6292C42BD6238BULL, 0xACA44B72DCEDA0BAULL, 0x46AB609489C63CCDULL, 0xD7897FF07164AA17ULL, 
            0x23F3913CEEEEA537ULL, 0x57F3FAC51D590F3DULL, 0x47A8FAABD948BAC8ULL, 0xD5A19730D0D6DA45ULL, 
            0xD07EE98D06C9E2F8ULL, 0xEEFB3B24B8480DBAULL, 0x438CDB0C2AF49688ULL, 0x75E8E495FD55429CULL, 
            0x55F107B6A3D210DCULL, 0xEC3B2E0D0FAE15C9ULL, 0xF8893B3DF5DC57C6ULL, 0xD82C98F603E540F3ULL, 
            0xDEE9F78A773CEC77ULL, 0x9AB8C7E42A3BEA35ULL, 0x638AFBDADEF24A74ULL, 0xD72A06654AAE14BCULL, 
            0xAA3E15FD5D6E7632ULL, 0x14D253C0866395BDULL, 0xA85761C1F37919DDULL, 0xFE936B5ACC152A8FULL, 
            0x8AEE4A9E6B2E8D92ULL, 0xEEB0CC37A272B804ULL, 0x5E874856D5AFE851ULL, 0xAD37B292984262ECULL, 
            0x05FE59ECD785E711ULL, 0x6582564BC10F6D20ULL, 0xB14D6078F05E1E2AULL, 0x9B3D1BF39A268115ULL
        },
        {
            0x6369D883C042BAAAULL, 0x010BF07B0F561B82ULL, 0x66BDAA4527189F94ULL, 0xED0C356CA52D14A7ULL, 
            0x0BD73A931894EC67ULL, 0x4E77D4D3624A2967ULL, 0x70C64D806B4845A7ULL, 0x4114A38A52F6F8AAULL, 
            0x96D01C1518BC9C35ULL, 0xA98E7193FDF0BA07ULL, 0x5F9115EA24FE73E7ULL, 0xF0CD696ADFFA81A9ULL, 
            0x484CAEDD2196015AULL, 0x8DBEAFE822C35F24ULL, 0x0EB1097D875F782BULL, 0xD18F9212E91B981EULL, 
            0x7A44ACEF36F7EFCBULL, 0x4DF713994829F0EDULL, 0x32AD6281D8715336ULL, 0x38F51BF26F1B6457ULL, 
            0x2AABAEC235D41C15ULL, 0xEB6FFBA0B2BF50BEULL, 0xC10A5C52B73CDE9AULL, 0x83E9907A21AD4999ULL, 
            0x18F65EB9F0272D81ULL, 0xB4C349AC9ADEAD44ULL, 0x86A5D8810A09FC35ULL, 0xA8A1A4B58E53E0D3ULL, 
            0xE6E341A38EB6D0B0ULL, 0xF51B77BE8386301DULL, 0x6DB43C82921E1A00ULL, 0x083C844F3E70E780ULL
        },
        {
            0xE03E8751FCEA027FULL, 0x157BDB8F20688324ULL, 0xCFEA0A824BCF2CC3ULL, 0x8FFBB70467DB64E0ULL, 
            0x7C2B34DCD8A7B02EULL, 0xC760AB179310A441ULL, 0xD88216C4AA47BB14ULL, 0x3A6D3B8FFA899265ULL, 
            0xC0F171DEEC780515ULL, 0xC2391942A59669A9ULL, 0xF615EB65DBB828D0ULL, 0xFD6468998213A0CEULL, 
            0x2CEF821E8232862BULL, 0xF094F15EE646F4B4ULL, 0xF832D6007EC73F30ULL, 0x22C970C462F45406ULL, 
            0x4E2C617A13ECCAFAULL, 0x48964BDFDABECECFULL, 0x78991575667924AFULL, 0xDF1DDE368D10D74EULL, 
            0x62C8399174A08A42ULL, 0xE5C829B06A1F2803ULL, 0xBAA6E7BFBFA52814ULL, 0x39A91FE60207D68CULL, 
            0x437E2A702921CD86ULL, 0x18FFDFD4990D4C26ULL, 0x49A3B496F123CB59ULL, 0x6A095715CD4A7472ULL, 
            0x110E1B2ACD87B9B7ULL, 0x648ACAE01E11CA07ULL, 0x8BF032D8618E8367ULL, 0x0203882D3E025D81ULL
        },
        {
            0x69D0B8A643EF010DULL, 0xA16BC0F34C1794B5ULL, 0xA39489EC3E48EB23ULL, 0x21CF5F2D517B9443ULL, 
            0xC2C51ED6563521A8ULL, 0x02A95908D7F86035ULL, 0x9F4C0CFEF82EE58EULL, 0x2143F2E83E2E8F3EULL, 
            0x6764C334BCD80A47ULL, 0x36FA3EE0C564A61BULL, 0xA65534F7C25524BDULL, 0x9763BE7156A148D5ULL, 
            0x3CE73459D758AAB4ULL, 0x42F5C8454B51F7F8ULL, 0x39F947C3AABE52F9ULL, 0xFBC0AA2777527D39ULL, 
            0x9309B962761C29F3ULL, 0xC3A745F3F4864F19ULL, 0x55B8C1860EBEBE12ULL, 0xD228E530B5E39CADULL, 
            0x6D19804A8485B404ULL, 0xD0AB82148D75AA84ULL, 0xBD9B4B65BF8733CFULL, 0x198A1AD0A95A80DEULL, 
            0x7AB1D2EDA59D7FC7ULL, 0x2C878AA64BF1F2ADULL, 0x619D4C688C654754ULL, 0x134180994F473470ULL, 
            0xAE9F66F29659BBDBULL, 0x0FB91480F31174ADULL, 0x998E0587B9995445ULL, 0xBAA31579ACA4D41EULL
        },
        {
            0x5B808382F0194CAAULL, 0x6C9A83E5480D6E51ULL, 0x5C2A96C57419F05DULL, 0xA4423D17F39B4C78ULL, 
            0x200D4D3DED3467E4ULL, 0x34B624CB72679437ULL, 0x7C9A644C595C1326ULL, 0x966F4D5E6227F3FFULL, 
            0x308F8868ACBF75CFULL, 0xDB2DE65898688CC8ULL, 0x8A642EE34324F83BULL, 0x867CAB57F8C10C6AULL, 
            0xC1338966F2B2E8DDULL, 0x4A40009722B0FDB1ULL, 0xA63BF09D3C73C6EFULL, 0xC3220E4FDE36B481ULL, 
            0x3924877AA7D6A403ULL, 0x9CACA9653D97C8C6ULL, 0x02DD83ADFB8591A2ULL, 0x1FF626186D8145B5ULL, 
            0x49E996B708689B91ULL, 0x35EACD5F14815756ULL, 0xBEE775A70B9B39D5ULL, 0x025E14E87D0CE08DULL, 
            0xF372F6B21F87C894ULL, 0x62FC32530615C4F9ULL, 0x8C039B0DADFF8388ULL, 0x65DF37312AF81577ULL, 
            0xECBC34538E4D710FULL, 0xCE92A0FE95EC7A12ULL, 0x903EA73D20A77490ULL, 0xFAF1D3E66F6B14A2ULL
        },
        {
            0x745DBB1ED4100E31ULL, 0x5E01F0E115108803ULL, 0xCA7F2EC3FE3D8AC3ULL, 0x47D72594294B119BULL, 
            0x80BAF1AAED161DC7ULL, 0x48E41DBACB3AA2BFULL, 0xD4B81B0A0C27B237ULL, 0x723104FD345685AAULL, 
            0xAC6663B23E5B111BULL, 0x011C5DAA3513226EULL, 0x6F4C4EF271076807ULL, 0xD53BAABF32CD9DA9ULL, 
            0x5063BBC53D023C57ULL, 0x7A9EA19363E9A751ULL, 0x866DD7AB6AEDB23CULL, 0x0DDBC2292AB20EDCULL, 
            0xC4A0187B0B2C94F3ULL, 0xCB903D9AF63156EBULL, 0xB293C66BBE4EB64DULL, 0xD69D6F668E976ACAULL, 
            0xE79A44149E487AC2ULL, 0xEC3A7F0F6A837E8AULL, 0xA80F5EA89E667751ULL, 0x856B55971AF5088CULL, 
            0x3FCD688B80B58914ULL, 0x76BB2877C0C3B773ULL, 0xF57515DCE443AF90ULL, 0xDF500D8BF84A43D5ULL, 
            0x510343366783194BULL, 0x2AF23DD7E3B01275ULL, 0x43B2634535A8F6E6ULL, 0xCD7963C1780D5215ULL
        }
    },
    {
        {
            0xBA7B26E648EA8C91ULL, 0xC493CDD43CB8B2DCULL, 0xBA2F96D7F43C90BFULL, 0x54635C26C48B9F7BULL, 
            0xDB19E23FB0689333ULL, 0x21A8CAF1CEBE8DB5ULL, 0x74F782BB0673D793ULL, 0x4D17A572490272AAULL, 
            0x406D92C2911F9470ULL, 0x3722277F1EF6E910ULL, 0xCC2E57A8B15BA958ULL, 0x96208082C33C5D8AULL, 
            0x092C0C516FA7F937ULL, 0x2B16F8868DB19144ULL, 0x03D4979798CAB04CULL, 0x2089DA76C860BD9DULL, 
            0x742FEAC067999825ULL, 0x94A515D6959F5A33ULL, 0x04D55BF9CBDBACDFULL, 0xF752F1F5DB1D1D95ULL, 
            0x14DB9AF08B9FBAB4ULL, 0x2BE7F0A4E6409B9CULL, 0x654441F442B6BAC0ULL, 0xDC138BFFDAC3C564ULL, 
            0xBFCC00FC4858F98DULL, 0x4AA2BC30FD654A06ULL, 0x2C059C9122E13FF2ULL, 0x97D9EE673CFB7B04ULL, 
            0x3187181012691AE0ULL, 0xCB65814F473804E2ULL, 0xA472A5A2B74E237CULL, 0xDC46022812B61072ULL
        },
        {
            0xAC6D20DB2DF1B8B6ULL, 0x82C10C72383BB377ULL, 0x22885F7C65CADE9FULL, 0x8A68E66CBA518541ULL, 
            0x3A08E536F689EE2FULL, 0x3E54F15F2DB91DADULL, 0x2D83FFA3BB378BB2ULL, 0x494351DCDEF76BF3ULL, 
            0xA67174CC78B57B4BULL, 0x570B20E81851D186ULL, 0x1B8DB41AC43E19FBULL, 0x9626B2114EE216E5ULL, 
            0x140D9C2DCCCD97B0ULL, 0xC58D004898A7DB8AULL, 0x58AAC5FB44DF8493ULL, 0x4525144D133B684CULL, 
            0x7479C543120F1475ULL, 0x4B969382733E5AFFULL, 0xCFD2AA4A341E861FULL, 0x6480D8F1F602B16DULL, 
            0xA9829F24BA5D47D4ULL, 0x252EE608AB056683ULL, 0xCC15AA866DA82309ULL, 0x9A2814817314137FULL, 
            0x8AFC390CB4C97E26ULL, 0x1122B27FEEF57E29ULL, 0xB87060D77BD63CB0ULL, 0xB3C659B4703C0D4AULL, 
            0x636E4270A1A7A2FFULL, 0xEE6099EADEA3882FULL, 0x032E0650821E95CEULL, 0x0E12537451619354ULL
        },
        {
            0x241CE3522DD29153ULL, 0x041DAEAF90CD8CD1ULL, 0x9D17B63A67020ECCULL, 0xF29AF0CFC98C3A7FULL, 
            0x227BB679AD222661ULL, 0xC6CA4076CD5F2203ULL, 0x65675C726ADE19A6ULL, 0x9A06E9E3A5C895B6ULL, 
            0x8D0D1EA869BA0370ULL, 0xE01B91CB6415A8D4ULL, 0xDFA25DDE6D7FF9FCULL, 0x00503CC333221AB9ULL, 
            0xD74853654C31ECCAULL, 0x8B75B415DD7DFDAAULL, 0x6084D11B13B76906ULL, 0xFCDBDF546613BD86ULL, 
            0x645AA44A3D2B75F2ULL, 0xF18AF004484741E1ULL, 0xA739E264E1F3011AULL, 0x0FF8032F7C73BB8AULL, 
            0x04A0A8066AE7D4D4ULL, 0xB18145A9CDEA2BA9ULL, 0x313E8E0654BA7030ULL, 0x3A02D4A3E518DF19ULL, 
            0xDED71EED9F50FCE4ULL, 0xB692E3921B87C422ULL, 0x129F1A5D74084ED4ULL, 0x26C296350B0A983EULL, 
            0x04C1CDDCFD655D47ULL, 0x5E0F4FDBE740A514ULL, 0x73F38B7A6BB34B6CULL, 0x485DB5D9CAC88926ULL
        },
        {
            0x8862976C33E31AE6ULL, 0x53C61926BE97ECA1ULL, 0x1013F43B6CA2D5FFULL, 0x78046389A1300FC8ULL, 
            0x2DD2D0DD42EF3D18ULL, 0xE071A15F7D2B736CULL, 0xACA63D9DBA834B5FULL, 0xDE20438B7DA59371ULL, 
            0x0991479056BF3A2FULL, 0xCAD229AEB0BA875CULL, 0xBF262008485F7688ULL, 0x5A351B6B2773C218ULL, 
            0x4D94AC530B4563F2ULL, 0xDC5325CFADF12D8DULL, 0x624D6BD462FA9836ULL, 0xC49C83E996CC72BAULL, 
            0x4EBEB8945FF074CBULL, 0x57ABEAC0814D8BC0ULL, 0x5712328E49406C2BULL, 0x89A136603483D923ULL, 
            0xCADAEE5FD81937C5ULL, 0x5C7F95585B99D073ULL, 0x667724F5D4378CDBULL, 0xCCAE859C30BA6775ULL, 
            0xB022E97C2CCEBDD6ULL, 0x8444B705776E6E60ULL, 0xDF475FC11191D3B5ULL, 0x03077A6A6B39A204ULL, 
            0xB31AC397063B8087ULL, 0xE9A6E910BB93FD31ULL, 0x35C93D57E8E7F920ULL, 0x0F7BBDF63905FB81ULL
        },
        {
            0xD9723CA43B3D1E2FULL, 0x28F67482C6378C5EULL, 0xA4E7C70EEA7A8DEEULL, 0x655C339CAA25B244ULL, 
            0x3786FC43DDCCB17BULL, 0x16C402291C3ED7F8ULL, 0xBC086D7EE589FC35ULL, 0x9C652605ABF6C970ULL, 
            0x76072FCBEC05703EULL, 0x052506B8AD1A10D0ULL, 0x885D57E935F0CBAAULL, 0x58D4D43046CEB0A5ULL, 
            0x6A5E63FCF09B5359ULL, 0xFA55CA28D1402D83ULL, 0x68B9CFA868B3F304ULL, 0x7C50D8C529A76086ULL, 
            0x44F7F26653431FACULL, 0xA098F59E1E2D02A1ULL, 0x25B01F183D37F06BULL, 0xE72E18BF4EAD2232ULL, 
            0x816AE7E29AB3046DULL, 0x251DE9C9BEDADBC7ULL, 0xF3FD75266C149255ULL, 0x12DB366BA72C8955ULL, 
            0x9D7044A2064097A3ULL, 0xC71C37F43E1A9BD6ULL, 0xBCD0FF29082EBABDULL, 0xA60CF8CCD82857A7ULL, 
            0x91D41E2250FC6C06ULL, 0xDD45E5E691B50EC8ULL, 0x4008A0BDBDA1D0C9ULL, 0x007D63CB3829BB2CULL
        },
        {
            0x8CC4E862D534A414ULL, 0xA5089506602A17DCULL, 0x2C621D29D2209774ULL, 0x85D3716B68C2FC13ULL, 
            0xD5F1A34049FCEFB9ULL, 0x9686F893A7C5C5ACULL, 0x5D380C88988277EFULL, 0x7C4F46399C50D648ULL, 
            0x99DCF5DA3E61971AULL, 0x0F43AFF03957813BULL, 0x6B51A9221AC005F1ULL, 0x82B3417339C4C467ULL, 
            0x8BB64DB0FC38A53EULL, 0xC0FA808D34DE905EULL, 0x52D58D2D71638A06ULL, 0x519975BB6BE6D36BULL, 
            0xA41B4CFA039C41BBULL, 0x20DA8E18F3FBBFBEULL, 0x5D7407341A892B19ULL, 0x04483C377C23AE8EULL, 
            0x19906F9FA0BC1561ULL, 0x266A80DB9EB49C35ULL, 0x7731019E1F79B780ULL, 0xD165510667B51EE4ULL, 
            0x5765F2CC614D05FDULL, 0x730A301332CEA1D7ULL, 0x9EDD673A526983CCULL, 0x9C43DADEA2DECB91ULL, 
            0x96C714744B3852F3ULL, 0x2C926B1F415FC5ABULL, 0x8E1990A3D0A2BFC7ULL, 0x5241C070083D025BULL
        }
    },
    {
        {
            0x1D0692CC8A3310A8ULL, 0x1FD57278FEE35656ULL, 0x27724C1976DC1829ULL, 0x7C922CB583847A4FULL, 
            0xC313BAB2728808C9ULL, 0x0441C8022775A5B2ULL, 0xA5E2F4C760B0F8F1ULL, 0x8E73BF936D1A59E3ULL, 
            0x69A53EEB0E8A94F1ULL, 0xEF945E3790E5A389ULL, 0x756E5E5DA7AF4C0CULL, 0xEDB6C2327B802980ULL, 
            0x0CF793F5DA011E03ULL, 0x41FB102BA4F3E279ULL, 0x7595B322F689150EULL, 0xA6F599ABEABFFB49ULL, 
            0x7D57A50A49130B19ULL, 0xCA6DE4FE8FF290BAULL, 0x04A8B5DFF74618E8ULL, 0x0FF35C898A7B6848ULL, 
            0x69B53E4D1556E4BBULL, 0xD144CF2E9CB2D0E6ULL, 0x88D71051C3511B49ULL, 0x8F43AEB4B4B4673EULL, 
            0x0136645F107B0BC3ULL, 0x323E5BEAFE6004A3ULL, 0x22BE2C972E7BF008ULL, 0x29CFF17FC67FCBA1ULL, 
            0x25C195884111A28BULL, 0x6FCC07559D414C17ULL, 0x0B8859D7768A8BECULL, 0x2F1B0DC0939E7559ULL
        },
        {
            0x21D777F7C1EFEF68ULL, 0x59E77A3A502BAC7EULL, 0x893276794F1C54DBULL, 0x10DA6E7EA0C4C8D8ULL, 
            0xAC8AFC3A2ABFADC7ULL, 0x381A40389B965C2FULL, 0x0A9063CFB94E16C8ULL, 0x72C059F70809828BULL, 
            0xA435CB662E29D7D9ULL, 0x00313D5565803EC1ULL, 0x8C629598771667B9ULL, 0xDEE27BC8FC3BF428ULL, 
            0xACC0E13B4BE673D8ULL, 0x01886776EC074B65ULL, 0x2ADB9D420D23962EULL, 0x609D291FAEE95B38ULL, 
            0xBFA3D72F85A5C149ULL, 0x0D98A426B0CEA75AULL, 0x6F3B3EA19D189E98ULL, 0xBD14BE96749B3075ULL, 
            0x88E39D79E532055FULL, 0x8A443940E4F5CA7CULL, 0xD1FE370EBD7703DBULL, 0xE3FACEE9B73342ACULL, 
            0x3159DBEC1D8AE1E5ULL, 0x0D2FFCFA293AF60DULL, 0x40EF0D8D843EB51EULL, 0x733C9D2D0788B9CFULL, 
            0xAEAC6A8341D93F4BULL, 0xF45A6D0892AFBFEFULL, 0x8B8FD5DE9C390173ULL, 0x81E068B6CD6B8CDBULL
        },
        {
            0x98F58082DC9E95BCULL, 0x0241B860BBFF7E89ULL, 0x826CA661774A4324ULL, 0x58FC071894158B01ULL, 
            0x3A4F6FAA07276003ULL, 0x451F251524393CECULL, 0xE61FF46DBD71F892ULL, 0xB873284C34C20162ULL, 
            0xB8BDDCC36900B2EDULL, 0xF12C2D6323835258ULL, 0x6F4C98A23E324B7DULL, 0xBBD776611E3A22ABULL, 
            0xE9966D3BF861776BULL, 0x1221F5684BB3E347ULL, 0x60443E6A81B414EEULL, 0x9322388CDDD4D966ULL, 
            0x75938F2045EF1E51ULL, 0x058EAED3598A1A6DULL, 0x9B1F5524E903EA6FULL, 0x229C46C32D592B50ULL, 
            0xD49B27FFC3ED921BULL, 0x825A3E169AB10B5AULL, 0x4CBE2FEF77BE8D8BULL, 0x3EF2F7639D7D3A45ULL, 
            0xA2CC33ADE78A7839ULL, 0x3288ABBF9E485DF5ULL, 0x7D5484E4E05634E3ULL, 0x760BA709660569ADULL, 
            0x97271E5F09E11A7AULL, 0x638F2CC2D9573A4DULL, 0xD7AD1E65BFF171B8ULL, 0x2CC99CD3EA6F74E7ULL
        },
        {
            0x49062FB1A634EBA7ULL, 0x89A48AE324FC802DULL, 0x4A07328210FC38F5ULL, 0xD1396CFD1415B7ADULL, 
            0x412F286687D7C423ULL, 0x82DD030E4A6D1444ULL, 0x1792EF76813717B5ULL, 0x2BC8B88B2F70FAF2ULL, 
            0xB9DED510BC0D8D24ULL, 0x9786F425D237BCC4ULL, 0x1E6A0F28A8526B66ULL, 0x6AF79C7D108650A2ULL, 
            0xF1C220059EB665F2ULL, 0xB2BA26B3FD5BD0F7ULL, 0xA529D6A09F1DB2A6ULL, 0x965755EA4E51625AULL, 
            0x741B04615219056AULL, 0x790E0A27A5EF9E72ULL, 0xA2E671B4372E4AD8ULL, 0x148EFA19465A5983ULL, 
            0x3051B769E22F93BBULL, 0x89DE7ADA8987FCC3ULL, 0x83367F65DFB93578ULL, 0x4A02F393B211B5D8ULL, 
            0x7894E1787D627DD1ULL, 0x2B2ECA916A199E97ULL, 0xCC1785EAA1A00D51ULL, 0x60D03FEB3C3C8D20ULL, 
            0x1261DF8BD2A70B67ULL, 0x3741ADA05B59CD9FULL, 0x8A46A4D52DA7CF2FULL, 0x897BFA1F902F9B40ULL
        },
        {
            0xDA8B37E8E310B3F7ULL, 0x0EAB8B29BE282BA5ULL, 0x83A0D2602AF30907ULL, 0x096BB13E4EF127AEULL, 
            0x6FCF2A0C41904251ULL, 0x573DD84D5D8B81CAULL, 0xD7CC23A7C6CD2456ULL, 0x9C0F495F6E5DF870ULL, 
            0x80E230DF8FA38771ULL, 0x4B073E7E91C10218ULL, 0x02801AE650C97536ULL, 0x8128BEB134B78A75ULL, 
            0x30F3295A0367F003ULL, 0x4E365409AD4FD35BULL, 0x479D8A2DD515B1D5ULL, 0x17934D31AF3A39C1ULL, 
            0x3DADCF74C9BE35F0ULL, 0x4D42E4761806B0FBULL, 0x0B091112A5E8F475ULL, 0x7C7F4CE871367616ULL, 
            0xF28CF68332B7C69CULL, 0xC73EDFFAA7DA9372ULL, 0x1AECC29F8BAB9222ULL, 0x628D50C8B0211837ULL, 
            0x193175CE722C3127ULL, 0xBBAE788D8673794BULL, 0xC6BC3CE1147C7478ULL, 0xBD8100BA17741129ULL, 
            0x2E344E8F4331EB39ULL, 0x3AD83F8EDFCFCD60ULL, 0x36625E0B493E28B3ULL, 0xC4AD010A11831AE7ULL
        },
        {
            0x4FEEBFFC56D2AAF1ULL, 0xD2720510122A0B2DULL, 0x751EAF01460A2290ULL, 0x0F672AA4295E62FAULL, 
            0x03108245FAEDD323ULL, 0x959CF9988925F944ULL, 0xC770644EB83EF8CEULL, 0xF7BDA627D63C6E81ULL, 
            0x764384095E95A64EULL, 0x1689B81AAB57CAC9ULL, 0x24965166B76993F8ULL, 0xD1BD6ABCBF729A33ULL, 
            0xE1EB6A058CFB14A6ULL, 0xEFA5AAC09386A27CULL, 0x78C7600C608661DFULL, 0x0F93B6E341015BDFULL, 
            0x289EDD8ED6EB499CULL, 0xA6A17CCA7A634256ULL, 0xFEF37B8FEE4005DCULL, 0x84B223EDC375954CULL, 
            0x2F4F5F921C27FAD5ULL, 0x30A36E383E686ED3ULL, 0xB9FE84910FB473EAULL, 0xD89ED121B33DC48EULL, 
            0x64E0F0E388A91B7DULL, 0x07E464D51A041135ULL, 0x913ABED6289E6CC3ULL, 0x4D23064A61015B69ULL, 
            0x78CA40493DDFABFEULL, 0x777D37B7851F3C4AULL, 0x04C2610DF8427F05ULL, 0xB6AAC072ED385B13ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseCConstants = {
    0x1083B7F486384B7CULL,
    0xE9D1EC961B0F755CULL,
    0xC80B1F60099149CCULL,
    0x1083B7F486384B7CULL,
    0xE9D1EC961B0F755CULL,
    0xC80B1F60099149CCULL,
    0x57061352099B5820ULL,
    0xCDD0E62895498999ULL,
    0x40,
    0xF5,
    0xB3,
    0xBA,
    0x8A,
    0x52,
    0x83,
    0xFA
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseDSalts = {
    {
        {
            0x1113486744850EACULL, 0x9A08B6BF99C0AA0AULL, 0x623BFD8A4E62E3B9ULL, 0x6F8EA4567DFED6EAULL, 
            0xB679D6CC5AB59123ULL, 0x021047B9A577D000ULL, 0xE5CD002AA2E31085ULL, 0x3224816F6F70B61CULL, 
            0xFDBC49A94CC49831ULL, 0x2FC85C86F6011C09ULL, 0xFAC7F696631B5E1CULL, 0xC876F7DAD7EFD395ULL, 
            0x42BCA664E1DDBF74ULL, 0xB7910B62996627A9ULL, 0xBE8E3633B770EB57ULL, 0xD3421C3339B2703FULL, 
            0xB59DBE2DF26BE3CFULL, 0x3E8EEBA874CBABBBULL, 0x2B9B835D2D34DD75ULL, 0x5BF1681DD4DE9CDFULL, 
            0x8FA4753B5A7FAC57ULL, 0x94B1761AD04410C3ULL, 0x0EA9B6A295021884ULL, 0x1A0C7BA62E7B808DULL, 
            0xCD2594B62097CEEAULL, 0x7A0E6681E9FDAB0BULL, 0xCDE153E02C2A92BDULL, 0x8D8D1B47CCF8C4A9ULL, 
            0x2CC926E2FB1CD116ULL, 0xB5E4A9252408F22FULL, 0x5CDCB01428558073ULL, 0xDB49E2E582FA6D09ULL
        },
        {
            0xAE3D6E2693466587ULL, 0xCAB888799F3FC4A2ULL, 0x3B1E6D190E1820C3ULL, 0x29FCC13FD156BED8ULL, 
            0x31D96242A4E1DDD5ULL, 0xBC11666C41E22498ULL, 0xEDB8FD17613EAC31ULL, 0x4C37517459BA6832ULL, 
            0x86C75AB1A9DC6FA1ULL, 0x1E6BE8B5A134C367ULL, 0x39A3B534DCCC2B11ULL, 0xAECE890AA1F6A9A7ULL, 
            0xA19159DE130A3362ULL, 0xF06E10FD830D056EULL, 0x1AFE19D4053CB24EULL, 0x4CA1244A6CA0FC38ULL, 
            0xAA93C0EFC9ED37FFULL, 0xDEE5D4675352E5D4ULL, 0x4FDCB4150C0F58C3ULL, 0xC4654E968BF6B06FULL, 
            0x6FFC72082855EB41ULL, 0x6DF19B1BF271C20FULL, 0xDE75E0EFC394F821ULL, 0xB02C1FF980B88BC4ULL, 
            0x133AB0F9DEE128B0ULL, 0x0FF6B21A3CDB91D7ULL, 0x5C280553523269D0ULL, 0x71F5076D14BF5953ULL, 
            0x3C217904024B88B0ULL, 0xABCBB556688D334CULL, 0xC2BD7D3A809F216FULL, 0xFE563A8FD464A7B2ULL
        },
        {
            0x8E116F5656C65858ULL, 0x4343ADCBB8F0A235ULL, 0x84F399DC56FEB47CULL, 0x18EAE428E23B4456ULL, 
            0x1C504D34E788EB70ULL, 0xD7EF2AA09F4A3FD7ULL, 0xB241B003B30FC298ULL, 0xC00AE43F299E4A2EULL, 
            0xC1EF7B4E564FF2C4ULL, 0x134C307233E6443DULL, 0xA66D7B17ED551DC6ULL, 0xA69FBF17463EEB47ULL, 
            0x2FD0F0AE4EFDADA3ULL, 0x8DC94054449ECE7EULL, 0x5C95367F566C2FD0ULL, 0x6E32E6DB7F04B890ULL, 
            0xB393C1ECE498BEBDULL, 0x774F60E41B35D913ULL, 0xC69D1F922ACC3095ULL, 0x94C476874A247105ULL, 
            0x44492B3A7750F7C1ULL, 0x6B7763D0223C0698ULL, 0xA3A68C3CD968156BULL, 0xE00E99276D604EDDULL, 
            0x8B039ECD09521E67ULL, 0x91FBF94E9C26920FULL, 0x2A93A639361E471FULL, 0x00F27E4EFE559159ULL, 
            0x97EB1BFCE13A6B9BULL, 0x764CA2F0304DE52FULL, 0x101C237C103EB506ULL, 0x1DD053F99CA980E6ULL
        },
        {
            0x3E1AB915633FA298ULL, 0xA79FDF67851FA463ULL, 0x4D243B3F2A38D0AFULL, 0x0661959D60ABA4B8ULL, 
            0xE4749FC6200A8F20ULL, 0xCADDA38C2333F4BBULL, 0x7557FC0D3D98A67CULL, 0xB19D6AF39679014DULL, 
            0xB8019ECE3BF7A753ULL, 0x883408272901B7B5ULL, 0xC159EB4A08584012ULL, 0x08A2C300092AC7CCULL, 
            0x187AF3AB837A0E31ULL, 0x035CDE9CFF8984A2ULL, 0xC872BBA9CEBB45DDULL, 0x5BCA7F4A919F1485ULL, 
            0x3A516D4857BF81F0ULL, 0x2BD012919190A2D3ULL, 0xFF54782C3F7DDFD3ULL, 0xD983CD46944223E2ULL, 
            0xB7045CDB346361B1ULL, 0xF390FE6E67D3C90CULL, 0xCE214D396B166DA0ULL, 0x1E5B78041E0FEFB4ULL, 
            0xE961687B50B65F57ULL, 0xECBCE275FD2E2B9BULL, 0xEAFE5C9F59BE67EEULL, 0xF00BB350D096255EULL, 
            0x05E1944C67E38B40ULL, 0xF08823003CA25934ULL, 0xF820D6914DFC2F49ULL, 0xEAB71DC47AC7C4FEULL
        },
        {
            0x98638A0027E9B153ULL, 0x8C186136178F0D2FULL, 0xC6D7E3279AD7E2ACULL, 0xBCC36E2747123471ULL, 
            0xDB64C533CA503C05ULL, 0xD3E8E38FEB9ADF85ULL, 0x74ACA9B26323B97AULL, 0x233C864649C730A2ULL, 
            0xF17D9BD4FCA62D26ULL, 0x256B8D4145C2DC8BULL, 0x04181CB8D6FAC23FULL, 0xDA7F8950E21F2882ULL, 
            0x32EEC7CEB237266BULL, 0x3AEEA49599F1FA5CULL, 0xF334C251C93FE60BULL, 0x34EDBDC3069E8357ULL, 
            0xC54F27C560E16F4CULL, 0x00252A3A8EF3054AULL, 0xD3A79EF3A58CCC43ULL, 0xB981FCB281F020DFULL, 
            0x09CF8919D99C323EULL, 0x427A715709B9198CULL, 0x3FB511A59F9F8EE9ULL, 0xF07226C0523C9CA8ULL, 
            0xEF17C08E9B5FABC0ULL, 0xF3734573425AF358ULL, 0x85CC86DAE7175A62ULL, 0x5588F993716AD2F5ULL, 
            0x46C4FC209F0188F1ULL, 0x7296EFCC4425F405ULL, 0x87B1ADC327DF18CFULL, 0xD90758A4B037E65FULL
        },
        {
            0x5CF43FDC81BE5081ULL, 0x76C91C82D9743392ULL, 0x0771967F6EB007AFULL, 0xB48D4BA586FD32CBULL, 
            0xB9D8412DE12E5FAFULL, 0xCD3EDAF43E7AAE2CULL, 0xAAE1C425FA0569B4ULL, 0x2D2938B86AE4D8B2ULL, 
            0xB59E79AC2ACB7344ULL, 0xE900DFF52C5601E9ULL, 0x410CD1A5BD91D26FULL, 0x13AE1D8C422150CEULL, 
            0xF44CC40F04D1A589ULL, 0xFA70E3F33F259ADEULL, 0xBE2811E64386A9B3ULL, 0x6F65C55E0FD1B266ULL, 
            0x780F5A8081F4E340ULL, 0x6D99BFBD2DAF5B8AULL, 0x11429889B8C7790AULL, 0xA1703F5F36BEBA12ULL, 
            0x5F8E1BF5548F9FF2ULL, 0xEDBADD112FCAEC1AULL, 0x5E13B49A3C50BF75ULL, 0x6E19E0C10D61D585ULL, 
            0xBE8FAB3F8AFFAF0AULL, 0x6691FC742EABE0E7ULL, 0x9EA3CBDEE0760D23ULL, 0x334ACEAED66AFB19ULL, 
            0x65CB50C9E5C19E9AULL, 0xAD37BF17556C263CULL, 0x69FA261661A97574ULL, 0x9773A7BBDD392654ULL
        }
    },
    {
        {
            0x351D336E02EF4914ULL, 0x8AF25BFEBE85891DULL, 0xA6E50B4BA6D45BF2ULL, 0x84AC657227EC968EULL, 
            0x89A6906A8ED309E4ULL, 0x42BFD94BC8DAE511ULL, 0x2AEFF64529FAA742ULL, 0xA29260F6C2B71CABULL, 
            0x906D9A6ED82A393CULL, 0x099A27BE4516A74FULL, 0x487B51F55A640531ULL, 0x8380F52165207C2FULL, 
            0xDAC7554E29B1EA9BULL, 0xB71B28CFBA960378ULL, 0x79CAE2351A24FB72ULL, 0x292DEA09974EBE81ULL, 
            0xA5D3DC67013F3928ULL, 0x8DD3A786EE475F48ULL, 0x2E4B1E38AE45E889ULL, 0x26073AE26980BAE7ULL, 
            0xFAD7CA1DF592EDCAULL, 0x3715639FBE987880ULL, 0x55D1FBD1FEB11DF0ULL, 0x0AF23417B5A6299BULL, 
            0x63685EF1C4FFE01FULL, 0x75E846D1082FEF17ULL, 0xB9EAFBF3009E60E9ULL, 0x81795FDF2A3BAE0CULL, 
            0xAAF3FBEA54037177ULL, 0x4DA7513967C7C652ULL, 0xDA14628B4494E93FULL, 0x0900331535A83898ULL
        },
        {
            0x521CB0A8E4E62F0CULL, 0xF8D743CD5E5AE810ULL, 0x9B5C1C9DF65BA6DBULL, 0xF763643D7E83E43DULL, 
            0x00741DC0CB1C4BE5ULL, 0x1824BA41F3E9304CULL, 0xC00C93C931F09506ULL, 0x9DCFFE3D2B07CD46ULL, 
            0x7493DDF96A642A25ULL, 0x3EBC1D0156362E67ULL, 0xDBC29B82566DE803ULL, 0x7C8AB004A6B2E89FULL, 
            0x5552CD2C22B8D561ULL, 0x34881523F3962166ULL, 0xC4A1A9491E7B5F76ULL, 0xCC60A91211F745C3ULL, 
            0x0AF0E25D7C7AAAEDULL, 0xF0292B7A4B1E9EBCULL, 0x2EE32A2F865670F0ULL, 0x5840EC046FA0CF8AULL, 
            0x8AD83A9A2082430FULL, 0x092461DB9894A3C0ULL, 0xC63C756C5E4D7BCDULL, 0xA008BA037306C3BDULL, 
            0x74EDB29080880372ULL, 0x09E1CE53D5E6C699ULL, 0x35328EC7602B7117ULL, 0x4D90670C62265A3DULL, 
            0x5AAB633C7585A49AULL, 0xCCCA046D1DB76D94ULL, 0x0D695443A6085E15ULL, 0x22F99E8D15685A97ULL
        },
        {
            0xA4E088262CE67609ULL, 0x3965E6370A96568FULL, 0xFF1FA199404702C2ULL, 0x1D7038884A80205EULL, 
            0x3EC1A9701A438CAEULL, 0xB264A02A2C622BF1ULL, 0x522E50E5DB11B399ULL, 0xDAF8CC2427B26CF3ULL, 
            0xA22CFB88D6445597ULL, 0x042859A3F5D7A43BULL, 0xF51EB52CBF098ED9ULL, 0x60195CA63DC49538ULL, 
            0xB22E46B0BABCF5CCULL, 0x5B239B7BC4729641ULL, 0xDC3BC52D09B93637ULL, 0xD76A29B46B56AFBDULL, 
            0x4E0F9EED2D806EE5ULL, 0xDEC89727145D8E9EULL, 0xC5C50CAD3BCFBA7CULL, 0xF0DB92904720B4CBULL, 
            0x78FF3C22C31B84A3ULL, 0xC503094FB31CC017ULL, 0x5144A466CA38E211ULL, 0x10E57037C83C8EE7ULL, 
            0x0E24BF0B9C9702C8ULL, 0x5EF2E2A46D6157DCULL, 0xDE3D0D9EB7F0F81CULL, 0xFD2724B2986D73C0ULL, 
            0x97E1716C07E9E9F9ULL, 0x417B5C6F6A25ECDEULL, 0xD9D93791C5401FEBULL, 0x772E3DCFEA77B9C6ULL
        },
        {
            0xD4BCC1B698CCA1CAULL, 0xE13C4996BF4A751BULL, 0x7A4EF37C1CE62E69ULL, 0x1F50AFA0D007A04EULL, 
            0x4936F75CBA8E0E86ULL, 0xC6EC18252EB90EA4ULL, 0x60E573691A6B0795ULL, 0x7782C8B88B788681ULL, 
            0xE00759C00681264CULL, 0xDD5B354E7134C28FULL, 0xD74FF2942DA0EFF2ULL, 0xC1DCF39F9B6AEA8AULL, 
            0x32AE8E70BEC96774ULL, 0x5F99B607F08A4AEAULL, 0x177268F4B8030619ULL, 0x62C8E00F18D5345EULL, 
            0xAC74AF184DCADE95ULL, 0x358C76B6A19F9E5BULL, 0xADF119A7337FB29BULL, 0x6D9831C6D86C1986ULL, 
            0xB3B327BEF2FD2909ULL, 0x9ADA5DD51ECACC4DULL, 0xA1BCFC951431130DULL, 0xAE0166638305C4D0ULL, 
            0xA39ED63BC1C8CD81ULL, 0xE6CEF84F3A039601ULL, 0x3AD88C4A07E24299ULL, 0x23C007B09E709C0EULL, 
            0xAC5D7097859497B6ULL, 0x9C8F5C3BA6582441ULL, 0xC8EEB8592A9E8F42ULL, 0xA2E128A061B3B170ULL
        },
        {
            0x4692F03E1F5478EFULL, 0x6542204892B7EA6CULL, 0x02EFEBA062C97849ULL, 0xE37C45C189D189F5ULL, 
            0xBDC07919DE6258A2ULL, 0x23045338DEB3397FULL, 0x4387BBBBA261E0E4ULL, 0x3BB61F7D3AF0F0C4ULL, 
            0xE90FA981D3CC86EBULL, 0x5AE06D7390CF1F37ULL, 0xB606FDA09D78769DULL, 0x82FA92A6E6FE72A5ULL, 
            0x190C6367DC5CD0A8ULL, 0x8EFC2C243098894BULL, 0x8AEF59834169F9B0ULL, 0x5C42D59F8F3D3E1EULL, 
            0xCB6B6AB234106B2CULL, 0x03152CDE18C6F45CULL, 0x3207F5F8F32FA85AULL, 0x635460FC7F82CDA6ULL, 
            0xA0D380243D3EED31ULL, 0xA857D8844AAE88B6ULL, 0xCB6463B5F02A52CAULL, 0x4E8900356D44B723ULL, 
            0xC5D38D658EAFBA22ULL, 0x143A3949A9E22730ULL, 0x6F8A7D4E4206DE0FULL, 0x174B469F19F8674AULL, 
            0xA0E5E15CFBBDD450ULL, 0xB3ABB986934A0F76ULL, 0x53CFCA0E17722E55ULL, 0xAF5C8899E5BAF5F1ULL
        },
        {
            0x5AE4969677E34331ULL, 0x4DB42B41A7347BFCULL, 0x4DB6099AE13659A6ULL, 0xEF8D81D377AE64DFULL, 
            0x6294BD8623519ED1ULL, 0x93ADF624D8B84892ULL, 0x372508396C971FFAULL, 0xDD694022C1F92662ULL, 
            0x63FF76F079B6FE17ULL, 0xF6B83169D85CC5ADULL, 0x497F3552A1666785ULL, 0xDAF448D6568CE684ULL, 
            0xE7AE8C1B5DA7277BULL, 0x473AF2D7EE1D952FULL, 0x0D36DE0A3EBAF355ULL, 0xB65EBC3D6C79742BULL, 
            0xDF35C8B7C20AC03CULL, 0x1393ED1D5C1B82DCULL, 0x8167724825148266ULL, 0x17294B252C85FB88ULL, 
            0xE3E5B327FFC4D5F3ULL, 0x1E0DBFF2676C7C92ULL, 0xF2AC5829961ABD12ULL, 0x9557D7620072B578ULL, 
            0xEA0C80EFAFB07A1DULL, 0xC10FB40AE83696EFULL, 0xB08C32219BA78E2CULL, 0x20614F61532D1BB1ULL, 
            0xE6F84453E9ED24A8ULL, 0xC8DC962E5A92D65CULL, 0x208B69ED5CFA4E40ULL, 0x258B7E47E4EF7895ULL
        }
    },
    {
        {
            0xA23698C1DFCA7F6FULL, 0x507B91C7BD321CD3ULL, 0x41EC603348EA37A5ULL, 0x9273433B98DB2B06ULL, 
            0x6DC506F16466C297ULL, 0x1B08E8D586125CA9ULL, 0x220544D75D7A959BULL, 0x742D6DFD5534AA9DULL, 
            0xC5DC9F554894B650ULL, 0x54734DB03B617103ULL, 0x1C76CE91099ED278ULL, 0x54672ACDC5A46109ULL, 
            0x25D16FC31EC197E9ULL, 0xC58E091D548B80F7ULL, 0x13F49F6C7D650F03ULL, 0x76DAE5947D38F63EULL, 
            0x2D3CC7E0D858CD82ULL, 0x98377D06021240AEULL, 0x5410C00E47471D1CULL, 0xF51DD8AD233E9C4DULL, 
            0x81F0F59EF2082DB0ULL, 0x9C6DA76F22B58504ULL, 0xE5F4361EEEEEC980ULL, 0x6F3B54FE1C068948ULL, 
            0x4AE7B0BBFA35FE84ULL, 0x9448BD4557818894ULL, 0xC4D8B3C5587AF972ULL, 0xD7C835B4F8EE69BEULL, 
            0x337091E14BA6DF0BULL, 0x117CFA1CA175EDCCULL, 0xFEB387AD7F95D5F1ULL, 0x79D0F7B03C269193ULL
        },
        {
            0xA507FFF9FAAD6EF5ULL, 0xC4E1680A81E595FDULL, 0xBBD6A10E78BD66D0ULL, 0x62A2690B1E9C4DE1ULL, 
            0xA5E770DB2F545742ULL, 0x138ABDE942469120ULL, 0x22EAD67C0562FE6DULL, 0x2084AD2261888F40ULL, 
            0xC3FFC03FD46C6CF0ULL, 0xF3B740F1872D21CFULL, 0x010CD5305E1C5014ULL, 0xC7EE2A29AC12C6CBULL, 
            0x550711FB1B5ADB79ULL, 0x3AD249A06E1A913DULL, 0x18134BCCC8085F6DULL, 0x452E6B255BFA2622ULL, 
            0x61EC73DF3AD3754CULL, 0x69B559C8F837C4FFULL, 0x99F5A6D9D9C9CF9AULL, 0x88C9B79F835C0AA7ULL, 
            0xB167ACDB1350DA9DULL, 0x358749BE0F09D8BFULL, 0x2227E2ED22D6DCB0ULL, 0x9B14D734B9EF5C4EULL, 
            0x3D2489D1B446295EULL, 0x5DA0F173B0E02DC9ULL, 0x3EB58A6DFD80FAEDULL, 0xA8B2C443584098EEULL, 
            0x81B2805E554513AAULL, 0x22FB4C402D9A78A5ULL, 0x3ABB7BC8B0737FDCULL, 0xD4DE37756AFB8F34ULL
        },
        {
            0x30B9C7480FA707A4ULL, 0x8952554CFA3CA19CULL, 0x319AD5EFAE24BD00ULL, 0xB14F194E70F40E93ULL, 
            0x2F2423C986FF4C2DULL, 0xBD23577552166F0DULL, 0xAA0AAC6A4C534354ULL, 0xA2884E8CF95F4C60ULL, 
            0xD4FABB6747CA2349ULL, 0x2A7C517F7DDCA313ULL, 0xCA11E0B23684729FULL, 0xF5B5BF425D6865D8ULL, 
            0x468731AE00031395ULL, 0x04CA744AA3B41D3AULL, 0xFE3565F9ADE1A612ULL, 0xF8357603E38C817AULL, 
            0xA965515D65FFD8ECULL, 0xFE8BCD1E6A411B23ULL, 0xFFADEF998F36258BULL, 0x90E42E72FDD537EEULL, 
            0x1E90EC8EBA9818CCULL, 0xE888EDCECA3368C5ULL, 0xD97F2DB96F34E0B1ULL, 0x5A5A7EBC8A6FE1F1ULL, 
            0xFC7E320EA75482B4ULL, 0x108880C73D4527A4ULL, 0xE89F04CD24B31CCEULL, 0x91F88E5198FEF56CULL, 
            0x7EAC6D9191566266ULL, 0x10B8CD14661A9EF5ULL, 0x8A747AB77DC38DA2ULL, 0x12CB0B9BAAB906F5ULL
        },
        {
            0x8E81575015239613ULL, 0x99F97ACD0AD13125ULL, 0x4B046E4596B5304EULL, 0xBE5FBBA1D48CC56DULL, 
            0x1CA9E807C0B527FEULL, 0x11EF2E8C6E9ECC0CULL, 0x541DC96DE607BF5CULL, 0x47AFA822008A7874ULL, 
            0x82668F547BB7F967ULL, 0x881EC9ACEC79F39EULL, 0x93E1E091426A58F9ULL, 0x5C8D981E59D7EA90ULL, 
            0x776E5C27FE2F542DULL, 0xC40443324727F059ULL, 0x823ACA66DAF899D0ULL, 0x5F8CAF1B0A3AE73BULL, 
            0x29723A3A42F88DF3ULL, 0xB3834066FD7C1622ULL, 0xE3B53A23B5923AA3ULL, 0x178290061C431DE5ULL, 
            0xCFC539AD72D188B4ULL, 0xF390E67A0D631D6CULL, 0x7E045DBB23891085ULL, 0xE6702DE700C7F26FULL, 
            0x3F669EF0CC4176E0ULL, 0x1AE856305F6CE60BULL, 0xB62ACB32FF310610ULL, 0xCFF61BBF192827C7ULL, 
            0x0DA4BB8DF455F8F8ULL, 0x2D78D14D8389A82FULL, 0x906420D191C51CF0ULL, 0xB63648081F33923AULL
        },
        {
            0x8F6ECFE4A13BC790ULL, 0xD351E179551FDFB7ULL, 0x93A70CA6D5525F8EULL, 0x8088037A90E19D4CULL, 
            0x4CFE986B6E05DDE4ULL, 0xD0EBCB18611B19ABULL, 0x0E86F33E5820974CULL, 0x7DB7F55A291B7CC0ULL, 
            0xEDD4D60886CDC7D3ULL, 0xAF91A9246FEF9346ULL, 0x6CF83477536F27E0ULL, 0x8724BD84D7C419EAULL, 
            0x810DE59E00ACE4B5ULL, 0x26F429ECDBB029DAULL, 0xBC5227C759AB6185ULL, 0x16A7BE77B92C8239ULL, 
            0x02300C2006DF0339ULL, 0xC558B8C1739F447FULL, 0x78149E3ADC3735E7ULL, 0xA4555B8662F9573EULL, 
            0x89B112EC00DFDB4FULL, 0x80F3E879BF915F90ULL, 0x0D3784BA67093B45ULL, 0x460BF0C07D575DADULL, 
            0xF2A6BADD73B55357ULL, 0xF736F45606840978ULL, 0xDDCA33230E425B2DULL, 0x4831F020EB5EC1B8ULL, 
            0x85A307718B153C8DULL, 0x7CDE6A676027105CULL, 0x930D489265A04C5EULL, 0x14D5BAA6B71A1056ULL
        },
        {
            0x8929E17EAF713DBEULL, 0xA4E0DEA5B043E58BULL, 0xC7CC35C286376857ULL, 0xCDD9A405BBDF113BULL, 
            0x2CC2C4583AF1529BULL, 0x0B1678FEE8776CD4ULL, 0x147DEBF7F720F131ULL, 0x8139C533F88A5238ULL, 
            0xEF0C3241B5307ED6ULL, 0xCF2C930BB9334ED5ULL, 0x6020A6973CFFCBA9ULL, 0x66B3BA1F8D0F78D8ULL, 
            0x9F508CD0B6C31665ULL, 0x6D7017996B7803B7ULL, 0x52AB1A502E347286ULL, 0x7335ABDC0917DEA9ULL, 
            0xEE63268732D9426FULL, 0x2171D5313814DDB9ULL, 0x98F14146D37E7879ULL, 0x5616BC488AB8DED1ULL, 
            0x19AD463BF006AC82ULL, 0x6D91774D4B0D89B3ULL, 0xF35318126CCC530CULL, 0x0DE364E62B173E00ULL, 
            0x4724CCDAF5B8A628ULL, 0x9EF0DCABC7338F44ULL, 0xEC0BC5ED841FFD3DULL, 0x199061160FDBDE13ULL, 
            0x01B78A180AFEA82BULL, 0xEFE6F3897D09CC5DULL, 0x02D47A6F5E264BA2ULL, 0xDCC24009DC908BCCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseDConstants = {
    0x2B1C14A5785DFA71ULL,
    0x28AB4C143D0533CBULL,
    0x68F52D15F263D39AULL,
    0x2B1C14A5785DFA71ULL,
    0x28AB4C143D0533CBULL,
    0x68F52D15F263D39AULL,
    0xA5ADDED8ED8A4BD9ULL,
    0xE1DB2F5B304D90C0ULL,
    0x63,
    0x6C,
    0x8D,
    0x9E,
    0x38,
    0x4F,
    0xD7,
    0xFB
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseESalts = {
    {
        {
            0x15508A885329B08FULL, 0xF77A1BC4AF24D599ULL, 0xD68E6AA2C94B5CDCULL, 0x9E9E73A5CCC7F7AEULL, 
            0x4A459B5F1F69923DULL, 0x32DCEEC9F7DE7F2AULL, 0xCBC834BCBE957030ULL, 0xBB65AA4FEFB04534ULL, 
            0x948872BD1A4D84AAULL, 0x4BD7C5FEE245749AULL, 0x7F2A9AD867D2E4CEULL, 0x65F7F131247D1CC1ULL, 
            0x2E7F274280E1569BULL, 0xD0254B11DB83E9C2ULL, 0xE5D187EFC573E38EULL, 0x07CAAFD76FAD7FFBULL, 
            0x28ED72A8819E7A7CULL, 0x8F322720BDACDB10ULL, 0xE7B82C61EEC8DF87ULL, 0xCC28143AA8464612ULL, 
            0xCC95C26B5CEDE870ULL, 0x95B9DE85D6D8D71AULL, 0x4162D2FB48CE190CULL, 0x97218C1EE5722BD0ULL, 
            0x8CCD09AA2B516D21ULL, 0x3914047CA2F81236ULL, 0xE5D11317063FEF35ULL, 0x8818784C53CF1D74ULL, 
            0x93535D61F8B51D1CULL, 0xE7978C14B2027FEFULL, 0x452F4A905467032DULL, 0xB8EAFB0529FF2710ULL
        },
        {
            0x5CE1282869AD21B6ULL, 0xAF170099646250D9ULL, 0x2469A8A44B0ECB92ULL, 0xAD33A273DC47401DULL, 
            0xDF30B63D672CC6D2ULL, 0x1C6529958E083E35ULL, 0x34E67DA3B01B6A6EULL, 0x95447C72DEE3D310ULL, 
            0x9C72773568498E90ULL, 0xC98AB34A13CA7385ULL, 0xFB004CC44273BCBCULL, 0x5305694909A7F1E1ULL, 
            0x23B910B9D7229AB9ULL, 0xBFBD57953CF34EA2ULL, 0x80AE8373ED5A5D06ULL, 0xDD7F73E1AE265EFCULL, 
            0x2D588F4471DA0454ULL, 0xE3462189C5DB6B20ULL, 0xCF82A8DF6D121FDCULL, 0x3CD64BBB29B16CDEULL, 
            0x05511A7D37BDBA47ULL, 0x89EEBCFBC62C62CFULL, 0x167DBCBA27821BF5ULL, 0x33FBBB9D7A0591E0ULL, 
            0x1D32311BF7037E03ULL, 0x8F2A29DA90BD1E0CULL, 0x2B81830A5FAA4552ULL, 0x90B3EDF7C86A2683ULL, 
            0x235A6B132CC5FBEFULL, 0x8181899208FAE491ULL, 0x1A783290DC94801BULL, 0xFF2EE13CA6607320ULL
        },
        {
            0x75DA6A90FD126870ULL, 0x2782DD1801F3B7BDULL, 0xCFFC1F7D166AF5E2ULL, 0x8EF7CAA772BF81D3ULL, 
            0x4269C6F96677DA41ULL, 0xA9A45DB7A18D1B17ULL, 0x53EB961FDDE9526CULL, 0xEC98D929BD3DF2A5ULL, 
            0x253C7128F7AD4FE4ULL, 0x285DC0EBC8050DD7ULL, 0xB318E1BCBFA9D62FULL, 0xD4766AD6CD9C8C28ULL, 
            0xAC1C1BA90F102181ULL, 0x621F41020BC656A4ULL, 0xE5384C8EBD93B220ULL, 0xAD84308A8D0C17AEULL, 
            0x88E96BB06779F029ULL, 0x5AFA9E970DB19BD4ULL, 0xADAAB7A602266C03ULL, 0xF38D758883A70889ULL, 
            0xEC26561E3337EB68ULL, 0xEECD1FCF6D1EF8A7ULL, 0xC77F4EB166E20EC6ULL, 0x415FDD5E6EF868ACULL, 
            0x7C30964C0FB498DEULL, 0x17A451B3E5F2ABB9ULL, 0xAF37C096DF3216F2ULL, 0x7E1B789C8EB225E9ULL, 
            0xDB35C424BE868ADBULL, 0x86FE029CEBFA52B6ULL, 0xF4070AF472533A38ULL, 0xCDFA2C90F500DF8EULL
        },
        {
            0x0120F9314097849BULL, 0x025BF3AD8DFC8CABULL, 0x9DE6D0A885F7206CULL, 0x5C98A53EE1A8B818ULL, 
            0x6827FB6167FD4C42ULL, 0x3ED3E3627A3A0E58ULL, 0x95C2E6C63EAB59A1ULL, 0xF096C6488C3A244AULL, 
            0x273773B2EBFFBEC7ULL, 0xDB876DF73A256CFAULL, 0x052C7577C641F71DULL, 0xB47555639AFF13A3ULL, 
            0x5207B999726D808AULL, 0xB3B0251C52DD78E4ULL, 0xD4C2033089F20DC4ULL, 0xA60D9C5D88A738CEULL, 
            0x19B641B16E44B7FAULL, 0x1F18457A009DF0D2ULL, 0xB39237537C8599E7ULL, 0xAEB7D71F3DB6A65EULL, 
            0xD9AF86E45C245B19ULL, 0x4E9A55823A1EF4C9ULL, 0x49F0A8ED10FAB70CULL, 0x89A2CC69F03B690FULL, 
            0xD200ABCAD5330E84ULL, 0x8ACB566B6171DA9FULL, 0x0E06BA56B22A5912ULL, 0xF4457CE07885BB7AULL, 
            0x4B4A3F9A8DFC38F2ULL, 0x806ACCF8CDF7544EULL, 0xFD5A952F869EEB57ULL, 0xCC3C08DDF7723934ULL
        },
        {
            0xE284D346429909AFULL, 0x9CDF69840DB4CB94ULL, 0xB33AA939D381B1F4ULL, 0xA589D200BE738D41ULL, 
            0x6D1E911FB9778637ULL, 0x90231A513985B382ULL, 0xFFA4B25881AEE191ULL, 0x59A1EE4AFC58F57BULL, 
            0x347AA1D97EB19EE1ULL, 0x6B39B30EC1AA6CE2ULL, 0x077F54D40A876682ULL, 0xBBD296F621328B80ULL, 
            0x3D63CA9637FDE126ULL, 0x9DCDE93FD65B5EDAULL, 0x36E9A33F391EA851ULL, 0xCE5748F0AC9DB44AULL, 
            0x13BA6872301803DEULL, 0xADBE5FAC291DF9DEULL, 0xA6F9A0FF4F366C42ULL, 0x1C341EF8ACB1F4B5ULL, 
            0x69CA6949F8207779ULL, 0x140F5F763424A5E5ULL, 0xE8B2F6FAFC9CD36AULL, 0xDE2E0E98FBB42BBBULL, 
            0x04CE9F96E5D97D43ULL, 0xBC2C7073C0A88EAFULL, 0xD93F3257143E18C8ULL, 0x5E0D4E2F0BF78274ULL, 
            0x2B431D423C54F6C7ULL, 0x8D87D25338159032ULL, 0xE996C08A706043A3ULL, 0x12DF6EE3BB632C2FULL
        },
        {
            0xE0E9602309D513C9ULL, 0x3822BA285506CBF9ULL, 0xF7707362B2056DCAULL, 0x6FD154492828B005ULL, 
            0xF2C87F28DF4A77FBULL, 0x6CBF71B7474DAD3EULL, 0x591CBF4A4C97B30BULL, 0x7F3631582CDC1253ULL, 
            0x3793CF958832B353ULL, 0x920564533482ECD1ULL, 0x818901675F37BC34ULL, 0x55FF82921A08A27CULL, 
            0x6F1DB27D13BFEB70ULL, 0x456A6D45F26BD1A5ULL, 0xA78663003204A090ULL, 0xE892FEB6A6CF1E8DULL, 
            0x768DE09558C18146ULL, 0xD7AA2A975D4420E7ULL, 0xF582DF00410E8E10ULL, 0x4B8AFF61C0A87F1EULL, 
            0x3327552BD1C10221ULL, 0x3D8D655A789F4CCFULL, 0x5C0D3BBBE2C4EC6BULL, 0x35ABD9D30C61A9DDULL, 
            0xD8B7D19FEDDD706EULL, 0xE725852B95D4B7E4ULL, 0xC10D055899ED1F5FULL, 0x44D4D303FC80D0FAULL, 
            0x2ABFCD5A1AB4CDAAULL, 0x63728F340A61C403ULL, 0x8E7B220B3BDA4809ULL, 0xCDB2A28C2749C24DULL
        }
    },
    {
        {
            0xFF5E40C50CADB1D4ULL, 0x8F23ECFB79F6EF21ULL, 0xEB8539FBEFF100BFULL, 0x8716CF26321F86FAULL, 
            0xE3EB2253FD843E59ULL, 0xF5C287A856589C4BULL, 0x53B3A918F12B963BULL, 0x5100F69A3E193BB4ULL, 
            0xCCBDE5CA2D72EB65ULL, 0xC29CCF4375BA3ABBULL, 0x2301B6FA07CC3060ULL, 0x9C58D490E95D3BFBULL, 
            0xECB9B52A9657C972ULL, 0xA1771EED13C1D854ULL, 0x077468FD8EB91831ULL, 0x346323259655D2FCULL, 
            0x445BA457C3DBEE53ULL, 0x7421F1FF021A254FULL, 0xE48D36C571449CB7ULL, 0xD199D0A2D95DBBF5ULL, 
            0x2E7AB4F9BCDCB2FAULL, 0x292A30120EB8E15DULL, 0xF44794A27FAD2763ULL, 0x94485624E44A40D1ULL, 
            0x6C58FE8C4A7EEEA9ULL, 0x38237C3A962F6757ULL, 0xDEBA073A5F8A81A7ULL, 0x9C419C960D4C811BULL, 
            0x0C5ACDA6B8C88031ULL, 0x4626350072BD85D6ULL, 0x045955086A5BB6A1ULL, 0xAA2A411603870E6BULL
        },
        {
            0xF727AFCE8306D89FULL, 0xD0ED320890BAAD1FULL, 0xDCACAA4ED79A4F22ULL, 0x6C754A9E0DD97D54ULL, 
            0x1190E76FA85676AFULL, 0xF5FE8175D9756DBBULL, 0x512DF79AB1C4495DULL, 0x48BD0936DB798EF2ULL, 
            0xB65D16A871F378A1ULL, 0x7900A7900A87CA3EULL, 0xE671767A8178180CULL, 0xF0C21F886B7CA4E3ULL, 
            0xED24D9FB98167B8BULL, 0x95CCE5E6E45ACE79ULL, 0x78E59B3A445C8D26ULL, 0x7C5C1AFA88BBDCF7ULL, 
            0x6946A7DB76F9C844ULL, 0xD55E72200637F42EULL, 0x348A475249C98EC9ULL, 0x4C68A62B0502D057ULL, 
            0x24A34C94EF8F1D31ULL, 0x381C8DA434A00E03ULL, 0xA46200935933306DULL, 0xDE4D874345EA30A7ULL, 
            0xA23C466A9F9F3143ULL, 0x6ED7398314156048ULL, 0x08965F2952D4A264ULL, 0x6A0CB0CC4C7FD66AULL, 
            0xF40DC86C4D7D15FFULL, 0xA381558D5D4B1505ULL, 0x680D54531CCD0B44ULL, 0x4363C83F975B0A50ULL
        },
        {
            0xC84C98E34A5B9AD0ULL, 0x92E76DA32A00661BULL, 0xCC0E070DC086DF55ULL, 0x8D9B5F1F4EDD1151ULL, 
            0x5C54A3965482D758ULL, 0x468BBA8A0759CFA6ULL, 0x4A291D1A1FD1D41BULL, 0x474329436B2ACF31ULL, 
            0xF9095FBA4D89BAC5ULL, 0x0BCF82364E62D053ULL, 0xA7485B19DF01D6EBULL, 0xA3D004BE824AA129ULL, 
            0x66933599B9FDDBBEULL, 0x4CA04B3BDD497374ULL, 0x0AE375A792277F48ULL, 0xFAD1191DDB107FACULL, 
            0x88B9E43B5371DF74ULL, 0x357EAB153282798FULL, 0x7E431D90F48624B3ULL, 0xCF93487F62F60D92ULL, 
            0x1D4A746EDF32903BULL, 0xCF5F066339ECD733ULL, 0x47EF6E3D81C25584ULL, 0x600B2055002493DDULL, 
            0x3A607ED4BDBF7433ULL, 0xCB7736CE067967ABULL, 0xCF21C4039B62E086ULL, 0xD23FE1460EF26AADULL, 
            0x3E78D4780E639103ULL, 0xDDB1F96845A316D6ULL, 0x3A4784DB27EDC2EAULL, 0xA2F4CA1F038EE8C8ULL
        },
        {
            0xCBA3F9F451B4F343ULL, 0x746B0E8810985C99ULL, 0xB8EDF7E665E72893ULL, 0x8F5CB0ECD61B6B58ULL, 
            0x63383443166EF880ULL, 0x1AC6697D51266099ULL, 0xBD66485E66BB728CULL, 0x2CD8B335E9373B75ULL, 
            0x2A20D7280F73F018ULL, 0x8742436D5CEE6164ULL, 0x1A066345D2E17169ULL, 0xC6F5E9C56114A7CDULL, 
            0x27CEE2C7831A057DULL, 0xC1D3F59B6EE4E25DULL, 0x457FA92324095519ULL, 0xF3FEE2F34D8C4337ULL, 
            0xA0CC9B6C5219526AULL, 0x5B8FC12C8B4CB8D3ULL, 0xCF64F88C07942927ULL, 0x893A915AED7A0929ULL, 
            0x4CB46B112EF21739ULL, 0xA9981AD6AF47039EULL, 0x295ECE7F833553EFULL, 0x120F91091E084196ULL, 
            0xD90B409CB25D045FULL, 0xDA970D4574ECD4DAULL, 0x06F08B16BFD5E812ULL, 0xB0A70A27F7DCF7F2ULL, 
            0xE369DDCFF359C126ULL, 0xA548114383F45ACEULL, 0xB2F407BFDB4B90FCULL, 0x01AD8E26E8FB8075ULL
        },
        {
            0x58C60FC80B55F4D2ULL, 0x812C8F6C818BE9B8ULL, 0x4B349BDD7858B0A6ULL, 0xD283A3E5BCF97803ULL, 
            0x44292EF6DF2FFF8CULL, 0x091AB60C3B26B3B3ULL, 0x897AA5C02F782D96ULL, 0xCBB6AFA18E945291ULL, 
            0x0FD9A16D2B0CDD09ULL, 0xBF931CE8AEA7804AULL, 0x0A9BFF2298E5BAA5ULL, 0x77FCB92DBD092C39ULL, 
            0xBBDC12454B6033F7ULL, 0xB728CD4B57676B6BULL, 0xE0BECEED31CD467EULL, 0x2002E512AE292FB7ULL, 
            0x19E7F6C4CF3207D8ULL, 0xC669518AF0AD8B91ULL, 0x048E5DE238E08515ULL, 0xFBFD18F70E31DDC3ULL, 
            0xD7EC894B09E35B53ULL, 0x0A2F7F7865D9634AULL, 0xDC90615488D8A2CDULL, 0xE9EBC4C373BCB712ULL, 
            0xEEE2336F7F9D27E6ULL, 0x924BB7D45D3F0517ULL, 0x9481D69917A3BA6CULL, 0xFF9CF1D7F3966B0DULL, 
            0x2B0737F114CE191AULL, 0xCB1348BCC6DB3140ULL, 0x09C6F225A9771A40ULL, 0x0A5207561429A6D4ULL
        },
        {
            0xC38AF78EDA08A4DBULL, 0x791E6C6D3E5DA4DCULL, 0xEB8EAC4AC5A54909ULL, 0x0BEC737B18978461ULL, 
            0xA9C5BD672872C302ULL, 0xCCAB7F94686AD60AULL, 0xDB997AEB28F8CAF6ULL, 0x01A8908F33866E73ULL, 
            0x56D53092E965A0EBULL, 0xD5FA95417362BB27ULL, 0x7A8FB9375770027CULL, 0x1D1F83DFB36AF2B7ULL, 
            0x58BAC17A6D94BF78ULL, 0x9C0FD655307981AAULL, 0xE95CB41467ACA6A6ULL, 0xA7177FD9F842DD1DULL, 
            0xF683FB705BE000EDULL, 0x10F5F1ADF640356FULL, 0xA9E63193537A15CDULL, 0x4A979D7DDD1095DAULL, 
            0x7C73163504701452ULL, 0x10CA1CE8A78361D5ULL, 0xF0132A2CD3057917ULL, 0x99D2197DD35EE9F1ULL, 
            0xE2B5CD0B5876FB9CULL, 0x2BDB5CDB115EECCDULL, 0x0D70F88FD32AC37AULL, 0xD2BEBBAB72AE0D61ULL, 
            0x3BA4B447EDF5577FULL, 0x1CCCFE3838814D59ULL, 0x97572E051EFC965AULL, 0x6067AB0656C4DBA7ULL
        }
    },
    {
        {
            0x74F575A61CB7B659ULL, 0xCDF6D1881EFFAF05ULL, 0xD0F5560F23DC9F0DULL, 0x5F113CB7977E2462ULL, 
            0x444A4686E9CCA10BULL, 0x884BF8422F7425ECULL, 0x1668CC89A3D359DCULL, 0x8426F25C6A3F8FC9ULL, 
            0xF3A127951F6CFD34ULL, 0x7727106226089E51ULL, 0xD6B22337D10FDC70ULL, 0x257EA34EA895DE55ULL, 
            0xC66CC4A40F6DE178ULL, 0x9512335E7EFA3FFFULL, 0x923BAE9FAF865210ULL, 0x83C070864E329B15ULL, 
            0x421B32189C2EAC72ULL, 0x58DBCFA48499AFD6ULL, 0xA77D7C3F55D59285ULL, 0x266FEF2DAA826044ULL, 
            0xCF576214951E9BA8ULL, 0xF0E597E39D4ADF33ULL, 0x25E2DFEE0226B046ULL, 0x3424CFA5E1FAE75FULL, 
            0xA602D4318DE4E361ULL, 0xD6BA55109CF1D45BULL, 0x359239C4579E18C6ULL, 0xEC44D90DD0949C2DULL, 
            0xBB1AFF16CEAE0401ULL, 0xCFDF97520D2DC8A8ULL, 0xBA4228FA2CEB7B28ULL, 0x472BC757101CE803ULL
        },
        {
            0x4494AEF88D1341A2ULL, 0xFC9D407F83DB18FDULL, 0x3EB137FE57898961ULL, 0x75FF4EB979A1790BULL, 
            0xEF31BD60ADD6447FULL, 0x567AF653E4F87A2EULL, 0xA65202676B10B765ULL, 0x5932AB714CAAE796ULL, 
            0x39365A8CE460B364ULL, 0x1DCFEEC94E61C993ULL, 0xB9E90C6BEE01F397ULL, 0x2D40B66ABE0AA93EULL, 
            0xC9C93BD2ABD3E737ULL, 0xA370F8BA2CA322C8ULL, 0xDD60FEA964A7EA69ULL, 0x210FDA012FBC78B8ULL, 
            0x06C54B03F70EC141ULL, 0x5A6A93960CA6F128ULL, 0x13A1405E5281DE7BULL, 0x477D326827083216ULL, 
            0x73B85AF70C9E8D7EULL, 0x449E111E5CC259D5ULL, 0x404F8B7F11FB9774ULL, 0xD51E82FE2F36B75DULL, 
            0x2D15EC7B3C85A2E3ULL, 0xA8D6A1FFFE8ED7CCULL, 0x0F7D0769620EE6B3ULL, 0x9A8606DA207F19CFULL, 
            0x598713C33AED57D7ULL, 0x57C1EC6594C74366ULL, 0x7A9F22D01F350A67ULL, 0x3C94CD4B3804D072ULL
        },
        {
            0x64A0FCE1CF66A53DULL, 0x7708A81C3FECC4E5ULL, 0x8D72DBFB98328AC5ULL, 0xA57FE1CF85CE1910ULL, 
            0xC8C8E038ADE2C757ULL, 0xF7F5E0630D4A2210ULL, 0xD3592B43953F50F8ULL, 0x76AFFAB5DF74C14DULL, 
            0x9D394CE2C91D101FULL, 0x89DC8CBA68154F0DULL, 0xEBC286C85E28C72FULL, 0x7D1C85EB0857B88AULL, 
            0x569765626D9F6EA1ULL, 0x9FFAFEF54CE474E8ULL, 0x0BB20F87F60CF70AULL, 0x5DAD9C61925F3245ULL, 
            0xDCC982AB1091B922ULL, 0x9E2A07326DC36E50ULL, 0xED7D0E71E5FA4052ULL, 0x4ADD15052CFC0258ULL, 
            0x0AA87ACD6FCA526AULL, 0xCD3C1D2ED5653A56ULL, 0x3A175BC5B7C3E1B4ULL, 0xBA36FB4642AB718DULL, 
            0x579E1A6B83D13D2BULL, 0xA4EB53EDDF2ADEAFULL, 0x0EC01835D6FF66ACULL, 0x24A61E9BCD08C9FFULL, 
            0x3A031D03B292EA51ULL, 0x28B3B15147D49F73ULL, 0x6811AD19605874FFULL, 0x5EF79AF15C7A404EULL
        },
        {
            0xF62BA634B2A7A14FULL, 0xD2F5386B697BF2BBULL, 0xE50A2788B069775BULL, 0x9671E0FB76AFA89CULL, 
            0xBE9D61EA2609D07EULL, 0x18285A6B2364B72AULL, 0x91731B4AD359672DULL, 0x37C9221AC93EBE0DULL, 
            0x81B8903928768821ULL, 0x0FC6B5216AB3816DULL, 0x580D4A0E3893BBFAULL, 0xAA2347EDEE6696E2ULL, 
            0xC292EC5DBFEC4EACULL, 0xFC3540A270EA331AULL, 0xD6A626B22ED48133ULL, 0xA23A50AB7AD76EF7ULL, 
            0xF9EEB90F9F850E58ULL, 0x770579E84F489C78ULL, 0x8411CC0C9DF60B60ULL, 0x34085DE636CAD075ULL, 
            0x22B2FC40F299C6F0ULL, 0xFD08E7F6C3497E44ULL, 0xC029F18555B6A47AULL, 0x68686BD12F2873DEULL, 
            0xD3A45010D381D244ULL, 0xF6148BF30A320659ULL, 0xDFF7C5434F66F674ULL, 0xFC98F181F59AC689ULL, 
            0x93108862C5C21FDAULL, 0x7BC2A67D8ACACA8AULL, 0x8D4595E6E9518C40ULL, 0xD4A7A4168CA57234ULL
        },
        {
            0xD5DC9EE2E8F8E849ULL, 0x6AA1A46490364CE2ULL, 0xD6E8F28469A69989ULL, 0xECCD862E7877F4D0ULL, 
            0x112D46D1FAE37D5EULL, 0xBFA1FC8E766DAFC0ULL, 0x7AB3D6849EF66366ULL, 0x2CF4DBA029665849ULL, 
            0xB406459B9C6EC72BULL, 0xA15E731A524B7682ULL, 0x03789C2E934D7FE2ULL, 0xD5CD44334B4DA06BULL, 
            0xB3093C5E1D229E21ULL, 0x6AA38C7C5CF69FECULL, 0x36E324FCF4B3753FULL, 0x68A0A59ECF91291FULL, 
            0xD5A14C83D7FCC4FEULL, 0xD7C77A50F4334C36ULL, 0xACC6DC6FB1655929ULL, 0xB2B38E53C830DF2EULL, 
            0xBDF5FEFD9BBF47FAULL, 0xEF84A45CABDCABD0ULL, 0xE8AF1A6572B424BDULL, 0xE19EAA8C87D0C4D8ULL, 
            0xF1123E98515E39F8ULL, 0x8B6BB97A88C9EA73ULL, 0xCF3D447CB77E9DCFULL, 0xF0022C31BD73DE97ULL, 
            0x6815CD54C2120267ULL, 0x00EC281792099442ULL, 0x2239EE4024FE5DFEULL, 0xF4E0EA79ACA052A9ULL
        },
        {
            0xE4147E4F57553C6DULL, 0x2712DDB15432B11CULL, 0xB364270334919E71ULL, 0xB34C7B7EDD216711ULL, 
            0xEF10BA0BE161DF6DULL, 0xB46C7F255E28ED12ULL, 0x38733499562E2732ULL, 0xB1D67902B391F1D6ULL, 
            0x798548BE98E42729ULL, 0x44A42F11B2D82EFFULL, 0x09AC25B02764DBE4ULL, 0xB52A2DB35FA0A247ULL, 
            0xE09BB51AE671BCA1ULL, 0x08FCFA54CFC06588ULL, 0x4570468ED512860EULL, 0x137CE7D4FE920D5CULL, 
            0x98F85F65DFB7DBEBULL, 0x0F7533A4638A2B1DULL, 0xF088A5EDC3F4A59EULL, 0x78D5E2FB2F113FEEULL, 
            0xA6A56B19D0A2CFF2ULL, 0x7B9BED84900815C2ULL, 0xC8B4BDEC0D8D2BBBULL, 0x483C73201B24E317ULL, 
            0x53A3ECE784ECB70FULL, 0x2A942FAFACEE11A7ULL, 0xE6EF5D309BD9785DULL, 0x6076781CC33A5AECULL, 
            0xB914EC756466F289ULL, 0x46D9987BA86E2FF0ULL, 0x36BA7A81A38C5964ULL, 0x9F324ED8763CF11AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseEConstants = {
    0xD17B440D7359CDEAULL,
    0xD3FE77FD2843DDB5ULL,
    0x6C6D25763E10A76CULL,
    0xD17B440D7359CDEAULL,
    0xD3FE77FD2843DDB5ULL,
    0x6C6D25763E10A76CULL,
    0x07D1E6C8D99C7B3CULL,
    0xF279AB8019EC21A4ULL,
    0x62,
    0xCB,
    0xF5,
    0x60,
    0x9F,
    0xC1,
    0x14,
    0x71
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseFSalts = {
    {
        {
            0xA9C3CE2FA15C28AEULL, 0xDA98FEFFB4ABEA58ULL, 0xEF374674D921E30AULL, 0xB45889E221FED8A4ULL, 
            0xFEE3DF1F80D3653DULL, 0x3983C3C51560C8D3ULL, 0x96F609E93F28BD7FULL, 0x7927A7BB21E4FE6CULL, 
            0xBEB918DD115A3302ULL, 0x6131C88A16E82643ULL, 0x519D96F6D45FF443ULL, 0xD0AC3764CF3BAAD0ULL, 
            0xF3AB8550B837B576ULL, 0x145511473E5B0622ULL, 0xE3AE09D8AB360C96ULL, 0xF36FC2E351DDBABAULL, 
            0x9801B1382C6A1D82ULL, 0x64FA718788B9B4C3ULL, 0xBC3D81F2577EBD77ULL, 0xD23B1D0DB1719F88ULL, 
            0x132B03B0CEF5EF66ULL, 0x3E1D021C424D3A5EULL, 0x4CD211FD8EC61133ULL, 0xE602DEEDA105C4C4ULL, 
            0x171BF59C035FE786ULL, 0xFDBD1AACECC5F5E0ULL, 0xF546EE889879AB4BULL, 0x564D827C4C3E75A3ULL, 
            0xB88112A1F4B07DF0ULL, 0x072D1D8A3893089FULL, 0x679087856ACF114DULL, 0x1D65C5F9D7EAE9A6ULL
        },
        {
            0x3F2B7D4F114CFF75ULL, 0xB30B3F72973AA36FULL, 0x853577FCD71E6439ULL, 0x849E6ABCAAB1CDEAULL, 
            0xBBE07A78263C1960ULL, 0xB53FB641E0486575ULL, 0x1B736AD88D367CECULL, 0xD0D23FD6646D9C76ULL, 
            0xC22263B7A0B88656ULL, 0x66CEF7D317517486ULL, 0x3D3A214E012A4F7AULL, 0x4F5B48112E0E24F6ULL, 
            0xC57077168E66121EULL, 0xD33C70C0955C0E4EULL, 0x5A94D4098E1C95C8ULL, 0x5B5D7DD55E21D86DULL, 
            0xD7F4AC7E6ED4D378ULL, 0x0704D0F3B8D7A135ULL, 0xE87BC30E1BDEA58FULL, 0x0FC785FF6049157BULL, 
            0xE6F122392FBC2D01ULL, 0x82A5C711E5E2439EULL, 0x86C635DDAD2E75F7ULL, 0x0B55EC4F14E45F9CULL, 
            0xBE40F68764EAF0C3ULL, 0xCF2C5FD42E466F7CULL, 0x7548AC03DD5FC447ULL, 0x6799CACD9DFB4548ULL, 
            0x7168B2F748A6529CULL, 0x0D092701BEAC47A4ULL, 0xCFD76B295D893A95ULL, 0x4AA7FCF951D35C73ULL
        },
        {
            0xCFCCD2EA4975442CULL, 0xA03EE3FF6AE17666ULL, 0xB2BCC8D95B308043ULL, 0x585C6C5FE1BD0735ULL, 
            0x35B2AF26D5393C0EULL, 0x53068B2B269F5CBDULL, 0x24E75B7B24C7E00AULL, 0x7DF07699706ECBBAULL, 
            0x929F5F880C161034ULL, 0xD9DD9814F4B6BCBAULL, 0x017A15C900EC39B1ULL, 0xB5E0485321C52DFAULL, 
            0xA554D803D01EE292ULL, 0x55E4F2C262EC7CFBULL, 0x84B44AB715441B52ULL, 0xF1A68C24587E18A9ULL, 
            0x839E22DB68183A8FULL, 0xFDC50B5309B850FEULL, 0xC09365B8C85F0642ULL, 0x518A7AADF142B92AULL, 
            0x2DE1CBD68AF431DCULL, 0x82929363767993F5ULL, 0xEE45C5B65DFEC066ULL, 0x5DAEC69CBA3FAD6DULL, 
            0xC6AA1DD714F2890EULL, 0xAB258BDDFB74A88FULL, 0x02BFA18181DB6FD8ULL, 0x433DFA0E096CFFAFULL, 
            0x26966F83CB27708EULL, 0xA0E8E9128919B1AFULL, 0x15E51247E8954EEFULL, 0xC61F71E707585F00ULL
        },
        {
            0xB88D93B32C58D1D4ULL, 0xC44CEED45E8A9E5CULL, 0xF1DB868E4E0389C9ULL, 0xCD594946B75EEC75ULL, 
            0x7258CF6697CE10F7ULL, 0xFF80E563BC395913ULL, 0x0869B710D1D21FBDULL, 0xB3ABB6302B87E5E0ULL, 
            0xE6A452B285D679DFULL, 0x1DC89686803EC517ULL, 0x38DD3A85FDCC12A6ULL, 0x6A94B9569E8BCAFCULL, 
            0xA9E004934912F435ULL, 0x1639D6467750C876ULL, 0x6C5809790CF86263ULL, 0x5270BEA2F8F9F739ULL, 
            0x285E890C13CA3ABBULL, 0x161F149B16C970F9ULL, 0x83B084A704507036ULL, 0xB22678876DDE88F2ULL, 
            0xD99CC85727648E51ULL, 0x66A48FE35F121873ULL, 0x6CE5FC4B07B4B071ULL, 0x8003FEF04A22B023ULL, 
            0xEB847480EA8A2D1AULL, 0x0BE00A1520104DAEULL, 0x3D18E421AF50A349ULL, 0xE23A1D93FD13F812ULL, 
            0xC5E42CF4126ADF23ULL, 0xB69DE36D20BD08A5ULL, 0x26AA517205AF9CA7ULL, 0xA0C8BACB6A2FCF3DULL
        },
        {
            0xE779414E3DCEE588ULL, 0x8D3F002BF908322DULL, 0x761F49E9BB6AF444ULL, 0xC31CFFCA00F31F05ULL, 
            0x76101FAA63405649ULL, 0xF9664D1E4FE40AE1ULL, 0x57AEDF9ADDA3D139ULL, 0xA31FD8994D658218ULL, 
            0xC990436E6C658F1DULL, 0xA5CCC274EB9CC12FULL, 0x3AC9196449BB6748ULL, 0xFBE375A2939729E7ULL, 
            0xC201898FFC477AA3ULL, 0xB1DEE5A834CAD5B1ULL, 0xD935F073544204D8ULL, 0x577056477CB09CD9ULL, 
            0x755EEA5B9CB490C0ULL, 0xE697F76A79152F59ULL, 0x0553A61BA20ECB19ULL, 0x8C7D1AC8C21C06BFULL, 
            0x8C8724D39741D69DULL, 0x11F3F2DCC79CAE94ULL, 0x13F20188158D965DULL, 0x56401D14BDF00F9AULL, 
            0x3B6D7948D70B093DULL, 0x16083E787A5AE5FEULL, 0x6CB69F86EAA6FB92ULL, 0x68343DB3126414B1ULL, 
            0x22CABCBCC9B9BFBCULL, 0xE006537097597BC0ULL, 0xA135A0702B8E360DULL, 0x657002E8307353D1ULL
        },
        {
            0x7CA8F49980F999D1ULL, 0xDFD33AF5E8FE5ADDULL, 0x7A058B696491261FULL, 0x7AE07D87FC3E4100ULL, 
            0xB68FE3E3E2162648ULL, 0x955C864A176D70D3ULL, 0xE440E9ACA834F17AULL, 0xE2EEEF09EB1E5A40ULL, 
            0x0066F6E3EA2753C3ULL, 0x75911D7F6EC52772ULL, 0x08834B881D994237ULL, 0x903E20088CB2EDA7ULL, 
            0x50B95EE7EF5BEB25ULL, 0x7EC6C31404E80B2DULL, 0x2BD4F7E7EE23B58CULL, 0x68E62D82CEDB6C6EULL, 
            0x786EEE65ABE86407ULL, 0x5060697AA3AD772CULL, 0xA02B9884B77A6AB2ULL, 0x3AADB3F3C840EA7FULL, 
            0x0FED8D3339479D80ULL, 0x1E08439A9891BD01ULL, 0x043F43A4DB289CDDULL, 0x1F1B09D49511EEFAULL, 
            0x44A7582ACCDA44B9ULL, 0xC690DB627F2347A1ULL, 0xD78D90F4F0E8DFEBULL, 0x2B8D1D42EDCE413DULL, 
            0x29BD190DD510835EULL, 0xE29EC80081223E22ULL, 0x5AED372A1B6C0CE6ULL, 0x171D0DF8D1AC935EULL
        }
    },
    {
        {
            0x880D022CBE76A3AAULL, 0x553C8CAAE06092E3ULL, 0x5F2C291C9BF649A0ULL, 0xF91960EA17176968ULL, 
            0x4C5B588762ED17DBULL, 0x9EF03592A07DBB0FULL, 0xA9622E6C95B93373ULL, 0xE545E8D1C2B0E048ULL, 
            0x53033F426F9F71B2ULL, 0xD85A5D009BE2988EULL, 0x6650114DE9CE91DBULL, 0xD7910B232A69CAEDULL, 
            0x15463B79C76209B4ULL, 0x3460AF505C1DE490ULL, 0xE210C860DDB23481ULL, 0x052997C81416E1F4ULL, 
            0x2BA792892BF8A655ULL, 0x92D539B9C36A3448ULL, 0x58420FD1C870053DULL, 0x92112701D910C45BULL, 
            0x1986D8AE67B9BE5CULL, 0x58681507C95142C5ULL, 0xBEB0CFE975615B52ULL, 0x9ED94CE4E1E11AD7ULL, 
            0x85B1104D046473D2ULL, 0x6F216B2D4209EFF6ULL, 0xAD588D4A6846D93EULL, 0x24C16FA1519C6933ULL, 
            0xF3827C5C06ECBC21ULL, 0xD236F7B6ED64DD84ULL, 0xE702BC518E8AC53DULL, 0xC99BC542C228FA75ULL
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
            0xA0CCCD8B06C269A5ULL, 0xCA2DCBCA9D9D3DACULL, 0x260FA5C9D8F3A74FULL, 0xC5C9B96DC77715F4ULL, 
            0x443236CB6E3CA1A2ULL, 0x6E91C2FFFC6A75FFULL, 0xABEFDF05962F06B7ULL, 0xF7D4E58B653B2E09ULL, 
            0xE2CB7F458BE601A4ULL, 0x3970E64744F58885ULL, 0x2577D1ED40CBEF58ULL, 0x904B76CD2F62234AULL, 
            0x0B1C716F685B5645ULL, 0x6286C42A70C6C20CULL, 0x3209BAFF36456E5AULL, 0x43B8270EF8E5A990ULL, 
            0x28648F56AF8B0BB1ULL, 0x815F2D662D45184CULL, 0xCF2D4372ABAE254FULL, 0x8B1EF852CAB9B194ULL, 
            0x9F1CE3E4C0EAC0BCULL, 0xEE05A17C977D7325ULL, 0xE04F699999F0B81AULL, 0x3859A5138E4F48D3ULL, 
            0x22A25B44635DA0C6ULL, 0x792A106BB8A75DA4ULL, 0x39EF1C2A24793AEEULL, 0x35D49E58250C37F5ULL, 
            0xB798E60B31C84C7CULL, 0x86350732FEB4E947ULL, 0x63FA3E6861139286ULL, 0xCF07479A48355E49ULL
        },
        {
            0x83040E0518B683B1ULL, 0xF8E9EF7730AB0C89ULL, 0xF5AFCAED71FD75C8ULL, 0x9CDFEC422029078EULL, 
            0xA4B39636A118034EULL, 0x4656CE313F46F6C4ULL, 0x0F6CFF74319C7EA0ULL, 0xCCEC26CE0D728204ULL, 
            0xBA2483AD3AEE1A7BULL, 0xBE2494340B3590D4ULL, 0x9538941E391395C3ULL, 0xAB7C8286537F47CCULL, 
            0x61272E9247D7B753ULL, 0x711F6D720C0558C3ULL, 0xD00C86FB75D9D110ULL, 0xB59E3A0D8A722A5DULL, 
            0x63367E9B9EA62026ULL, 0x111BA6B8A77EC2B5ULL, 0xDB10B13C8790DCADULL, 0x71CE4897AD018631ULL, 
            0x855654E15E10ECB6ULL, 0x56EBDD8FBDBB00B9ULL, 0xCF1834A1299D3D37ULL, 0xA230F07B90AE3A78ULL, 
            0xBB1AD60A4FC41521ULL, 0xC263AD13D8E7A128ULL, 0xD8056DAF0ADFA781ULL, 0xCFC74A88823334DCULL, 
            0x22F2DDB9886A09F5ULL, 0x06701367A128078CULL, 0x1B9E9AD2D07E4D9AULL, 0x5BB9DB8EB8903B2EULL
        },
        {
            0x5A0E491BF94D6799ULL, 0x9E6A50BA10958DA2ULL, 0x6DA72B2EB2F1A0E2ULL, 0xAA9B6A3B14784D7CULL, 
            0xA71D45AC2E958C7AULL, 0x865149A5162E53CDULL, 0xE4012547008B33D1ULL, 0xE843A6F72A02F4D7ULL, 
            0xAAA07C9EA11B0E36ULL, 0x233BEA9B4D371712ULL, 0x5FB2D6514E351CA8ULL, 0xA307C3524459ADEEULL, 
            0x978908D753CB21C9ULL, 0xF129DB04262ECF33ULL, 0xC01F7C359645FE2DULL, 0xF33F4ED33A07F32CULL, 
            0xCABF6EF701569D1EULL, 0x822A04ED680E3B56ULL, 0x3ED98043FB5E3D7EULL, 0xBCB922950FB1CC2BULL, 
            0x11D231E89687A264ULL, 0x5A29914662F66E66ULL, 0x9BFA55702F60F3CCULL, 0x63B19B3EF2812769ULL, 
            0x78EAB735B9BAAD90ULL, 0x1CD175634EA4BE2DULL, 0x5434AB23C8E5B22FULL, 0x53DA2D3892369550ULL, 
            0x76329E4B27C8D607ULL, 0xC5995CECFD7AEEF3ULL, 0xC9B553B6F72F4BF4ULL, 0x96976AA24BFE5E8FULL
        },
        {
            0xFAF73526B80C1A3CULL, 0x32E0145A2E9624BDULL, 0xA30174149E6773AEULL, 0xAE318A87CA3D24AFULL, 
            0x83DF01A0D9A935FEULL, 0xCDFAA77DC88B67D6ULL, 0xB8F2597800F8F93AULL, 0x0F4208B64A7ADC4CULL, 
            0xA21433EC6C7438C6ULL, 0xB0DA5C52E7EFEF91ULL, 0x7811024642D3CDBAULL, 0x9A72F09D5A7447F1ULL, 
            0x28CB759A20B61818ULL, 0x93D1903D7AB7DD85ULL, 0x4B5798B3FFD2BB7EULL, 0x963134E79CF50F3DULL, 
            0x31B1AC64D6516372ULL, 0x86C2767F210E7EE9ULL, 0x1963C6C247D99513ULL, 0x91DA367175417FA4ULL, 
            0xD6F306F8C89C310CULL, 0x3E42752E2AD8B24DULL, 0x0670F71F9C46B94CULL, 0x98712B69E8AAAE80ULL, 
            0x971F7D9110FBCA7EULL, 0x7623795C0D74F08EULL, 0x111EF01A9E24541DULL, 0x394FE611D398DE40ULL, 
            0xF2A8DA9723B06061ULL, 0xE43ABE192B1F3823ULL, 0x694659D862A3B5D4ULL, 0x23D0D57DFC2E61E9ULL
        }
    },
    {
        {
            0x5E9AB10CC6262EF5ULL, 0xB47950D0C2C04B35ULL, 0xDEF81E09AFD17978ULL, 0x8BDD0877B163AEBFULL, 
            0xD89ADE036361E342ULL, 0x398656D90111A572ULL, 0x84293A48DE592BEBULL, 0x57CAC6BE9F1E47A6ULL, 
            0x79F86A9A36DAA025ULL, 0x49FC809248CC3BDCULL, 0x0ACD2DF7E9E6E88FULL, 0x8CFEC698A5FE0005ULL, 
            0x50B7F241A8CFCAE9ULL, 0xCFBA9D5AF13B46BCULL, 0xF91432C2A2F58010ULL, 0x4AAAC708EBAF5D80ULL, 
            0x8023BFA56077B3A8ULL, 0x0F835FEE2A3AA7E0ULL, 0xF206CD23F89550FFULL, 0x7A6C9EAB80EB568CULL, 
            0x804253B4943E4383ULL, 0x2239C618CBABBFE1ULL, 0x5AF0727A62D5E2FFULL, 0x9589DE9578ED6151ULL, 
            0x853747F2C7457042ULL, 0x15AC9CC2B5A84CBFULL, 0x97B858FA6315EA02ULL, 0x75FEE6951E6CC11DULL, 
            0x6AC5D846CFA4DA32ULL, 0x5B10837166903417ULL, 0x6B9C60B07C0BA42CULL, 0xF399800A27548477ULL
        },
        {
            0x6AAB74C12D784F8DULL, 0x12A26CFB0CDFFFE2ULL, 0xED21AB9EC7C3FB05ULL, 0xF8BDCB5B9E8B64C4ULL, 
            0xCEF073018A26BFA0ULL, 0xD46DB616FB5E3C13ULL, 0xD127B642805C3D68ULL, 0xE2D4BFC169B08A51ULL, 
            0x742D7C3A790A975CULL, 0x552A1919FD341B45ULL, 0x0ADEE6CB4706E7E8ULL, 0x806980FBB7BA6EB0ULL, 
            0xC38853F700488D98ULL, 0x907891315B723DD0ULL, 0xDCEE80009D6BA184ULL, 0xD861A01289DC6FA1ULL, 
            0x4DFCAE0AB008A386ULL, 0x3CA1D51C77D6E9C2ULL, 0x347F5300296A6B75ULL, 0xCA7C64AE831A0868ULL, 
            0x4919DE03983A996EULL, 0xCACB7EBF33D390CAULL, 0x8EE1A8D79B7C3565ULL, 0xD8C3333F76675DD0ULL, 
            0x8C3EA2800AF49501ULL, 0x19E0DEF066AAC332ULL, 0x9B2A737B172A6C7CULL, 0xB22AA0E79A715650ULL, 
            0xAE33F2F107CCCFA7ULL, 0x6D0E355A222DD257ULL, 0xC5E7EC38B9B7EE24ULL, 0x401C6B83F092413EULL
        },
        {
            0xC043EFF4B8CB9FF2ULL, 0x262055E362956E5AULL, 0x6621DA2469C5F3D3ULL, 0x7611D16E940C71A7ULL, 
            0x1FC2B38B54C204A7ULL, 0xEAF0E9B493BE93F2ULL, 0x8B033607EB7000F1ULL, 0xB881F645FA2090D1ULL, 
            0xFD09262941F08EABULL, 0x05BDE88BAE9E0F89ULL, 0xEE1C15B601A89B2EULL, 0x9C75726220701F48ULL, 
            0x9A174D1FC339DDFEULL, 0xDBD6F213C1EA8C22ULL, 0x235E042DEBAE3EF6ULL, 0x09BDA16C7CCE68ADULL, 
            0x0709CAB6CC5D6EFEULL, 0xD6C67B91B1BD2D05ULL, 0x89C1E2BF07525734ULL, 0x58257D825733C380ULL, 
            0xE8E7411E9006F7A3ULL, 0x5452B99305DBAF0AULL, 0x59F482731747764CULL, 0xF4DA6E5D7BC23D51ULL, 
            0xE0A92287965C3213ULL, 0x4B475A7423417A7AULL, 0x6C79AA01256F915BULL, 0x8ABB7FB02B7A8961ULL, 
            0x802EBB419BC73C89ULL, 0xD88C08673063B6D3ULL, 0x34D277E84ED71245ULL, 0xD13FB124526CEEE0ULL
        },
        {
            0xE681CA0A29FE59F8ULL, 0xC02C4CA076F095A3ULL, 0xF63AEB2180B96111ULL, 0x9C3821D557F76490ULL, 
            0x71D0DBA6B96F6A95ULL, 0x0A9C4BE87A8CCD7CULL, 0xFD0AD76003C3410DULL, 0x22657F9FFA33211CULL, 
            0x8FFD404FAE8311D1ULL, 0xBB5AB555AFA89246ULL, 0xF4BB0BE8348F2ED9ULL, 0x192B9BFF737045F9ULL, 
            0xFAB06F5457BA54FDULL, 0x178198D8F26859E2ULL, 0x170EDF10F17780A5ULL, 0x244B6B17D7FB28F5ULL, 
            0x41973758F2B889E4ULL, 0x2905FE16ECDB61E3ULL, 0x49867DD7E92FC4B1ULL, 0x3CAA66E47307B72CULL, 
            0x915827EC0E925702ULL, 0x9A1FD5C99D692C9DULL, 0xAE5D8F845ED29861ULL, 0x2377E5E086310AB2ULL, 
            0xFC52D10456BA5A30ULL, 0x3042954CA60F2B9FULL, 0x0632CC6756DBFAB4ULL, 0x33C299E07F22C6D9ULL, 
            0x94089DD436EB664FULL, 0x1B58024F7F40A97EULL, 0xAF8BCDD1C2B9C8FDULL, 0x69FB81EE87045532ULL
        },
        {
            0x125EE0968C5834AAULL, 0x6E5CEF3B685B86CAULL, 0x8531FCD5F4E8848AULL, 0x08EF202980A798F0ULL, 
            0x771C7DEA22EEFE36ULL, 0x2E9F0C6F376F6DEAULL, 0x337D17E464F17D04ULL, 0x22533F9B74146249ULL, 
            0x5604DF2520C65FCEULL, 0xB2EAEEAD7992720DULL, 0xA15107ED0789594AULL, 0xA5B2F65F2C5AA5A4ULL, 
            0x9524B8E01668D642ULL, 0xB1E12FA6D484D77FULL, 0xDE30C5E246EA9F8FULL, 0x995766CF4DE2A47CULL, 
            0xCAA9A277B921B85DULL, 0x4D26ED2FE069514EULL, 0x72F70F37E2EB03FCULL, 0x97303D553B8097D5ULL, 
            0xFF24596BE5EB2B79ULL, 0x6DABD9FC48E2F973ULL, 0x20B187BA9C99A83CULL, 0x85E52A57FFBB769AULL, 
            0x3CF804CCB2D1788AULL, 0x829C55F940483B4BULL, 0x8ED1DF28F851E910ULL, 0x1028968F2CCCA37FULL, 
            0x3DD537E08988D4D7ULL, 0xEE3BBEF64147885AULL, 0xFEC3F584C41C19A6ULL, 0xB061ACF1805ECC2EULL
        },
        {
            0xE8331ADC3A06A228ULL, 0x840B8D8EC93C231CULL, 0x4DE8569C7F2D835FULL, 0x3F489D5EE00C7600ULL, 
            0xC583557590581E2DULL, 0xC60FC3D52E3DA2F9ULL, 0x88D0F80D812ED140ULL, 0xA52E84A03B87534FULL, 
            0x7B97770EC6346172ULL, 0xA4A16BE58DA37DF4ULL, 0x6559AE29B803F33CULL, 0xAA4A12756B5CA1E1ULL, 
            0x0736F81D1E0361AAULL, 0xD89DDB9FDD2B9154ULL, 0x595785300D8EA0B8ULL, 0x6DE9D44EF87EBFEBULL, 
            0x5A727269FB1CAD48ULL, 0x68E06776F8ABB0E2ULL, 0xC4978FACE4FB9D42ULL, 0x7CE6BAB7C4875342ULL, 
            0x0323C92D91A42F3FULL, 0x2EBD116ABB3AA23FULL, 0xD51D81D41B7D0458ULL, 0x814952CCB710C86FULL, 
            0xC3C3404D91D542E1ULL, 0xA334180EEDE53FA4ULL, 0xE16B958A29D4321DULL, 0xD93026E489839528ULL, 
            0x3574CB0CBCB57E40ULL, 0x06769ECAFBECB270ULL, 0xBC784E2DE04D55CBULL, 0xDB3A93D2950BFA11ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseFConstants = {
    0xDFE48F06268C16D9ULL,
    0xFD8CC0FE2BE7A0E9ULL,
    0xB50C0573651D3495ULL,
    0xDFE48F06268C16D9ULL,
    0xFD8CC0FE2BE7A0E9ULL,
    0xB50C0573651D3495ULL,
    0x70BE807EC4FE12F2ULL,
    0xFA378813715A2D54ULL,
    0x78,
    0x67,
    0x3D,
    0x7E,
    0x6F,
    0x33,
    0x88,
    0xDF
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseGSalts = {
    {
        {
            0xD3000BD444128D83ULL, 0x48BE6ED37228BC50ULL, 0x706BC73C25C2A27EULL, 0x97FC7201D44DE07AULL, 
            0xC2EE558824E45185ULL, 0xCABAD29FC2C8F9A9ULL, 0xAC575684E50719EBULL, 0x3D646FF0DBA47150ULL, 
            0xDBD4AD2C08A4D389ULL, 0x1EE21B0F73723690ULL, 0xBAF3C22EAE3CAA3BULL, 0x765F411FDB44E294ULL, 
            0x40A5C5DE04AC62BDULL, 0x0D9E7C1ED3BD38C5ULL, 0x946CE9280F580235ULL, 0x6849809BBFDB8DC1ULL, 
            0xD592F45E7442E0B6ULL, 0x69AB2529FBD553AEULL, 0x51B2BFFC725A4F7EULL, 0xBC9F5243273FB193ULL, 
            0x9189C1D98A421B9FULL, 0xE4D5B3A15D94AFD0ULL, 0x0B49446D34D4DB14ULL, 0xC1FCB3D6C0A75CACULL, 
            0xDDF21151F19BDB89ULL, 0x7DF21DA739204634ULL, 0x95E48A524B253127ULL, 0x479C9F7500154524ULL, 
            0x700EF700E405329FULL, 0x75041DB5BA371D4AULL, 0x7394390E9E44FC09ULL, 0x6FFBD2A3B091637CULL
        },
        {
            0xDA91CAE59626CC0AULL, 0x80581282496E984EULL, 0x4DA58606AABACD93ULL, 0x65D5894B05E9EDE6ULL, 
            0x9528982F401A2A66ULL, 0x6576FC83A9E77B6DULL, 0x90F3457AE34127F0ULL, 0x65CEFAA27F7EE428ULL, 
            0x815773E456663B8EULL, 0x85BD63730651D43DULL, 0x5BFCA53A4275C9CCULL, 0x4F91AFF8F241A882ULL, 
            0x42D4ACC678B45D01ULL, 0xE829FC084F87991EULL, 0x54F487FBD9F5AAEFULL, 0x9678C370337DB66EULL, 
            0x351B69387CD17792ULL, 0xDD6220A052B73B5EULL, 0x2AC3B6B6693B4D4EULL, 0xE2A9FB8B4DCC6ECDULL, 
            0xEC29559818B2A127ULL, 0xAA786DFB3CC9428DULL, 0xE2C14D54B8A0D786ULL, 0x497A080D51784A32ULL, 
            0xDC974633D3E05BB3ULL, 0xA14D87520418D430ULL, 0xA7CDDE5B339BE46AULL, 0x23AE1C1986E6FC45ULL, 
            0x3F26C930677460DDULL, 0x37313C66F25FEDF8ULL, 0xD356E3E1F829B541ULL, 0xC24945F088960DBEULL
        },
        {
            0x7758866CA27C7494ULL, 0x9F3804FD1D8F2539ULL, 0x1D21605A5F2AF40DULL, 0x1515A6E93C022F03ULL, 
            0x4F0977B2321313B4ULL, 0x39831C03E24D1D2CULL, 0x7F594274160ACFADULL, 0x2810D7059F2F76B6ULL, 
            0xDD0E1D3D1D984A3FULL, 0x509A28727C3A51C4ULL, 0x1DF29D91C045F265ULL, 0x16FB20D17CED9809ULL, 
            0xD00B4CD427D95C73ULL, 0xFA445F903501B04BULL, 0x5FD285ECDD8887DFULL, 0x6D725D8A457B2392ULL, 
            0xE49603BED217924EULL, 0xA2D765118D4DC440ULL, 0xE5E0C38361C7BD32ULL, 0xBEA2FE67E04562BEULL, 
            0x42E68BD61086A2D9ULL, 0x9E1D165B3E7F663EULL, 0x4C0A6E1BADDB3EC4ULL, 0x970388F3A43F2989ULL, 
            0x9EFF76C5B0DDD071ULL, 0xDAEC6D0F98D26ECDULL, 0x6B47ED77D1513473ULL, 0xF05E52A3E8AF7C02ULL, 
            0xC459AAF0890A2124ULL, 0x480325BBC6C9F2D8ULL, 0x828780CE72B2F459ULL, 0x06B29B1CEDD5B0D9ULL
        },
        {
            0x125F75CB6E56268CULL, 0x796CCB334EF4CCB3ULL, 0x3C961B9EDCAA83E2ULL, 0xE5FF0587DAD489A0ULL, 
            0xBBB4A0DD1C7C3835ULL, 0xBD6535686D094899ULL, 0xF2E8466090DC600EULL, 0xE5023278EE761068ULL, 
            0x1660477EA3E2535BULL, 0xF8B8FBC726138BA1ULL, 0xD6D761C5B1926A07ULL, 0xDE3B71940C27A48BULL, 
            0x6663DD13EC19A6E4ULL, 0xD09C90726DA6953DULL, 0xFEB80A0830FBCF75ULL, 0x5D65DF4342EA6B84ULL, 
            0x6E8F555EACAB6D87ULL, 0x40B5673077806E17ULL, 0xA4D6587220AFFA97ULL, 0x4273D800DB01B45FULL, 
            0x38A473FEFABD16D0ULL, 0x90B8AD3FCED813A3ULL, 0xD15A238A6B8DEEC7ULL, 0x57044414C37032F6ULL, 
            0x8C8F3422B56640B2ULL, 0xBC2DC870345F1881ULL, 0xFBBCA660F79AACAAULL, 0x5D06AFE6B6DAB72CULL, 
            0xF8E4FCCB61C70B43ULL, 0xDC4CE6E02928F150ULL, 0x1FD3911926D9D49CULL, 0x47A0696DFE2822C7ULL
        },
        {
            0xBF7BD7EC0D2E7838ULL, 0xC3899B7F08960262ULL, 0xF25856CFD7F0F9EBULL, 0x7B46999D4FEAA544ULL, 
            0xD13172CB134847FEULL, 0x04FDE6C94EC38DD0ULL, 0x145F3FD203199BEDULL, 0x97EFC1135B8F7189ULL, 
            0x34B63FCA0E6B9BB0ULL, 0x75C3425F11601CCFULL, 0x2DB1B6B768A01C1BULL, 0x0D936388A15A0C36ULL, 
            0xD2A871050D3A528EULL, 0x9B189E47FD8174C0ULL, 0xEEA0F7380F1B0A9DULL, 0xF61AADBCCD574118ULL, 
            0x398E1461E8CB5693ULL, 0x228EE296053694DBULL, 0xE97C9EB5A09F1109ULL, 0xFA85236C7A6B9C65ULL, 
            0xFF87630755CEA524ULL, 0xBAA8056023035D4CULL, 0xA60E171E3D2F6EAFULL, 0xD280EB4B10419485ULL, 
            0x13FDD8E25A7F969EULL, 0x54A42F08475B3C6BULL, 0xCD7C2767FBDE42A5ULL, 0xFDE60D42C98CF10BULL, 
            0x828972E57E1C8224ULL, 0xF4D6C050E68E8DA7ULL, 0xFAF4A8B1997739B1ULL, 0xCB8E3648A6AF78DEULL
        },
        {
            0x741E43260C966776ULL, 0x7DE7165F7C6AB0F9ULL, 0x111278664EF23399ULL, 0x087E983089D710BBULL, 
            0xF190875AEE57196DULL, 0xBE7EAAE17A9E533FULL, 0x10C1429B558FE631ULL, 0xBC2C7E86D9DAC58FULL, 
            0xCF8CCFFAFF7B7ACEULL, 0x4F1D6D68BCD2B34CULL, 0x9475B03156A61ED8ULL, 0x4F301CDC2575E42DULL, 
            0x5A7109AD720C6BDAULL, 0x6E9AFF0A0D0AEDCAULL, 0x94F3CF117186B272ULL, 0x4DD5EBE3E86A8652ULL, 
            0xEB408AF53788D225ULL, 0xBD1DFD59EE3E8C6EULL, 0x79B4E2D841541BF7ULL, 0xABE655879971D018ULL, 
            0xB6FBF4F13FAD950AULL, 0x197BD505B5924118ULL, 0x7C337A0FF5206EB7ULL, 0x9B9EEC1A85DE0A20ULL, 
            0x0191B46D2213A70DULL, 0x0BC04AC87F549A99ULL, 0xAB4B8B3E1C194583ULL, 0x78AA2636BF2B285BULL, 
            0xAA191B30532872A2ULL, 0x176799439E9F1DC7ULL, 0x588C21ECE0F31196ULL, 0x8CD9B67BC5FF6C7EULL
        }
    },
    {
        {
            0x78F1FE317303A8D3ULL, 0x5A6E5C1A605EB3E8ULL, 0x21667CA07151FF8BULL, 0x1B118C4CC72E72D6ULL, 
            0x50817105723A76E2ULL, 0x8383726EF474EE35ULL, 0x9A497B21D61290EBULL, 0xCB84C271A16C51E1ULL, 
            0x877C5673433DAB55ULL, 0x045567902F1205F4ULL, 0x6538D7E6B42C907FULL, 0xAB45500162CC3D7BULL, 
            0x269E2FDCDA7AD8F8ULL, 0x9F3511A3005A1F81ULL, 0xED604F2DDA2EB26DULL, 0x90A6979ECA177048ULL, 
            0x1CA21D34AB2904BEULL, 0x8C7CFAB22114301AULL, 0xF7B330A43DD16E0CULL, 0x8178277953B7F881ULL, 
            0x3C6CAD5A5451AAD3ULL, 0x7C1557AAC60E3171ULL, 0xDC954DF26DC8A2E2ULL, 0x16989790D89048E5ULL, 
            0x959C23ECD7F14EA2ULL, 0x083658B319FCDB3DULL, 0x2BE69D3016ADA00AULL, 0x3877CCA91187C217ULL, 
            0x20835E5D010B4DEAULL, 0xFCB466732937AB0BULL, 0x2924FA6E86F30371ULL, 0x9ECA2CF92211F3A0ULL
        },
        {
            0xAB43BE4E9A68691BULL, 0x99BD177ACECDF73EULL, 0xBA112CD5C10A87A2ULL, 0xA18E8CACAAD2F1ABULL, 
            0x7720479DE9A9F9A1ULL, 0x8D03496F79F4419CULL, 0x3504450509FFF882ULL, 0xE1CCF61225E56674ULL, 
            0x6D3281E20A731CB8ULL, 0xB29F3938420314C4ULL, 0x8E6C3DBF9CB859D0ULL, 0xA7728945AB2D4B46ULL, 
            0x2C7102D9CD24278AULL, 0x92AE961FBA53B0F9ULL, 0x730AF80B99EDCB2DULL, 0xE3D6B1CF4237BA46ULL, 
            0x08E76CA6A172AA51ULL, 0x3E99C1F06C3FDBC3ULL, 0xDCB78B5D7B0F288CULL, 0xB855480A45BDD265ULL, 
            0x396A356406C52465ULL, 0xA7BF3DBCB1EA5ABDULL, 0x7E560E3F7F67871EULL, 0xA50D5F52B22A9D87ULL, 
            0xA6EC12B2E86A2850ULL, 0x2FA96C07221EBE2EULL, 0x025189C9D9BB0FC2ULL, 0xF9EA744D164507F3ULL, 
            0x99D620C3BD2438EFULL, 0xA7A88FF062021E66ULL, 0x680F6263E051B9DEULL, 0x687A18CD8657B48FULL
        },
        {
            0xBCE7DB9CD934FE9EULL, 0x1456FAA4D6D57C99ULL, 0x32A76A9D58FBC9FDULL, 0xA4958EC232FCD876ULL, 
            0x6EC5BFAEB26E1C9BULL, 0x1CC053D804674003ULL, 0x5F840FD68FE54DDCULL, 0x06A6D666E161BA8FULL, 
            0x0ADACE02A0E5EDB9ULL, 0x9EBD917B2322CEC2ULL, 0x3686D0D7FC7416FCULL, 0xB9CA9199AFD3455DULL, 
            0x768FFC32437F5041ULL, 0xB41B29D860EE9AFFULL, 0xC41C3663C2EE5E3BULL, 0x06D5C602722952A1ULL, 
            0xC6964ADA8DC770ABULL, 0xD721F4F0FD3805C7ULL, 0x577E60CD7E8C2513ULL, 0x534C3CF912CC665BULL, 
            0x10AB7612CB9A9550ULL, 0xA54CCDB4A3145297ULL, 0x69C08D669C401D37ULL, 0xD56465ECF8C429A0ULL, 
            0x137AF0E4466AC8C8ULL, 0x5A67EECEF03D77DDULL, 0xB8D7FD6ECD844B1AULL, 0x93214FD6ED220073ULL, 
            0xFC9E9821172010D3ULL, 0x9C099A15715AA6FEULL, 0x416C348A039F4B93ULL, 0xF701F957180FC7B5ULL
        },
        {
            0x7563263C9980D3D3ULL, 0xBCC60EB26C56B87EULL, 0xB1682F139FCAEDE9ULL, 0xD11F4BB38BE1D745ULL, 
            0xA877F64A21A25BB1ULL, 0xBDB5FC438DFCA6B5ULL, 0xBD7454FD721949A6ULL, 0x2583DACD723344ADULL, 
            0x8AD2DCD2882E1F65ULL, 0x41A02066D4DBD461ULL, 0x90D1FB735FBA2D23ULL, 0x252CFC4236197DA4ULL, 
            0xDD62D88357B718B3ULL, 0xB4FF66FDB75B6B1DULL, 0x338D7F83A2D6385FULL, 0x3A61125CBCCA216BULL, 
            0x26E60E9DD43A00CBULL, 0x4745EBFD3481DE5BULL, 0x7E874629FB58CE1FULL, 0x53185890FC9CEB38ULL, 
            0x4728BBA415C204EFULL, 0x9A586A5C8DF585AEULL, 0x66495E0B008C37D4ULL, 0xBD58ACA131BBA05EULL, 
            0xF48817F3C2D29FD1ULL, 0x66F8B412A96CDE24ULL, 0x4A6ED433F2D41EA0ULL, 0x678367107E3D43B2ULL, 
            0x1A0DB42D6694E351ULL, 0xE2D9B97B4F915B90ULL, 0x19F0B3206A3E1021ULL, 0x7924BFF175FD4AFAULL
        },
        {
            0x29E0E12B168C1E6FULL, 0xFAE290785C9691ECULL, 0x0B8BECAE4B29F802ULL, 0xFA249DF5516DD880ULL, 
            0x207BE74D286A154DULL, 0x79EE5D1DF75F6565ULL, 0x7E5F20A3EA1B29D0ULL, 0x3751C7C4E84811DCULL, 
            0xDE6B4B405163836CULL, 0xC1B20CFFF4234FE0ULL, 0x0ED85148B1E54BAAULL, 0xC98086CDDF75F469ULL, 
            0xE4B9606F69C5277EULL, 0xB929D2D80196F841ULL, 0x71B67EB456A5D333ULL, 0xF1E43F6EB6D5D024ULL, 
            0x8CE56C68CB421196ULL, 0x809C737DF30E1F30ULL, 0x647838E9E81A9651ULL, 0x330E4CCA131F67EFULL, 
            0x2487EEAEDF5CA488ULL, 0xE0D9C8BCFBC35AA7ULL, 0xA63EBA2282D06A05ULL, 0xEFAF09105EFA83EAULL, 
            0x01FFF7A63DBDACF7ULL, 0xCEB91E1E9B8D3647ULL, 0xE2A6EB51B98757EBULL, 0x05E30CBC1E48EEF0ULL, 
            0x9024A52F43387838ULL, 0xC15A2A61B64A4DE4ULL, 0x4A4DB27337E5E4C9ULL, 0x93F7EFF8F07B91D1ULL
        },
        {
            0x25051A6AAC562FDEULL, 0x1FE5BF8E7D27BDA9ULL, 0x6B9A778DFEAF2181ULL, 0x570B26344FA73C79ULL, 
            0x653DF82859A931B7ULL, 0xC00B2E53AD0E5A28ULL, 0x49E13F8061430F17ULL, 0x74028B0C69F438DAULL, 
            0x80A830DA77BE83C1ULL, 0x2CC52BD545CDCF14ULL, 0xF222C93DD0B0F471ULL, 0xC30E9D72E27C1726ULL, 
            0xD8B79F6B8B92ECEAULL, 0xF6E85325C9D74DF6ULL, 0xF426B15F8D107A63ULL, 0x1F77193155B0E612ULL, 
            0x25E07A6303EF6248ULL, 0xAFBECF14DC197096ULL, 0xF70BB0A681B2689BULL, 0x5A76FA0C79332A27ULL, 
            0x440F00E476FC13BAULL, 0x972D64EA84F6D61CULL, 0x238ED40AEBC9F04BULL, 0x946BCA046349AA8DULL, 
            0xB76DB54E704E7013ULL, 0x4A03223C83D87B70ULL, 0x88399742DB9DD069ULL, 0x31EE5B4F7035127CULL, 
            0x02D8A16FD91D8D7BULL, 0x9C528DFF6421EF03ULL, 0xCAE8CB2D2A441743ULL, 0x26A6FDAFF73F447EULL
        }
    },
    {
        {
            0x94F5FEF79C2CAC0EULL, 0x7B9BC47175B68739ULL, 0x0B891163A33586A3ULL, 0x349643D6B6389961ULL, 
            0x7AC1B66D6B3933E5ULL, 0xEE692CDC13A8CE6BULL, 0xD2BB9AC8030406B1ULL, 0xBCCF455AC4CDC0E8ULL, 
            0x086ABE7C495F82ABULL, 0xDA793C87CE2FEC52ULL, 0xAEF59E375A005A00ULL, 0x821C0D63CDB9C59AULL, 
            0x06EBBAD78FF517A7ULL, 0xA88F610501C3E805ULL, 0xCE623CAB25BF636FULL, 0x6046DB5EDF327047ULL, 
            0xF1D22EB49E7FB27DULL, 0xB92189DBAB86DA83ULL, 0x083F6CD77608CEB8ULL, 0x53E012A785888275ULL, 
            0xDF3C5DDE603CA1EBULL, 0xAF0F0B7D943B52B2ULL, 0x4B4D237C6E72BE45ULL, 0x2C9BA1F0A2BF382AULL, 
            0x9C2E29A40B17FB3EULL, 0x74C95561857E93F3ULL, 0x73B4C21D9EF70957ULL, 0x213C3F6903AF327FULL, 
            0x705510D272212FD8ULL, 0x86AD78F5BEAC4DE0ULL, 0xD2B374C59181B2E7ULL, 0x2B6D494448E2630AULL
        },
        {
            0xE3B624F9CF2D8C47ULL, 0x37BC1E7166D27044ULL, 0x8E1A970BE8C7FFE1ULL, 0x04CF463F50F83F6EULL, 
            0x4DB81BB302A8BA6CULL, 0xDEC64CDDA4B94F48ULL, 0xD7A4CFA8FBDA3AE3ULL, 0x596D0550997C9A92ULL, 
            0x556F043D23ACC13CULL, 0x8FF9FF801F3BE252ULL, 0xBFBACBD80616E82BULL, 0x5143FBA6FC43430CULL, 
            0x87CD33685A2FAF81ULL, 0x8BB84D4E80CC4E92ULL, 0x196C187BC6749A40ULL, 0x64DC189FD08511E1ULL, 
            0xC61A3D9AE9A44351ULL, 0x870853BA33702D4DULL, 0xA1D0920779175C7AULL, 0xD0306EAD2C832B34ULL, 
            0x543BE08271E54D70ULL, 0xDF173F925C1B34D9ULL, 0xD3AB59DCDF73E9EEULL, 0xCFA7DEA75BD04653ULL, 
            0xF778FA0AB431845EULL, 0x0C82823DC68E97D2ULL, 0x8ABD0D1243ABA8B5ULL, 0x005DE87A88147F81ULL, 
            0xA9205EB8A49BB474ULL, 0xBA597577AF4F4889ULL, 0x92AC88CE11C417F5ULL, 0xF3ADAC43A94A8B7EULL
        },
        {
            0x6D26A78ACEC1A552ULL, 0x2D4053358F652723ULL, 0x24A34D0E0F1633E4ULL, 0x985D01E3A3BB0EB3ULL, 
            0xF02A5433470C7906ULL, 0xA6F41415518432ACULL, 0xFAA00CAD6432E875ULL, 0x6D375940FBD81777ULL, 
            0x938CEBF34789DCB0ULL, 0xAE96525881EBD10CULL, 0x0321C0DBB7F23044ULL, 0xC62D6B9C44D6BCA2ULL, 
            0xA352FA83874F6582ULL, 0x97DF283D8AA8DFE4ULL, 0x613CF2736E51258FULL, 0x543A162E20733AAEULL, 
            0x25A4E47E7BFCDE2FULL, 0xC80494D4BDC474B2ULL, 0x6B89000DA820FE4EULL, 0xC79A425BB1DA2A33ULL, 
            0x608397BF415BA15EULL, 0x0E5EFD039A9C4F7AULL, 0x6E0633B722F5555BULL, 0x7B1F86F45D2A9BB0ULL, 
            0x84E6A355CE159C5DULL, 0x09F30893AD061BEAULL, 0x4A164AB7914BB956ULL, 0x19080C024863506DULL, 
            0xBE1FA3F67966A926ULL, 0xAFD89993561B2FF5ULL, 0xEFA6B338694A7C8DULL, 0xF1DD416B6606DEF7ULL
        },
        {
            0xA45A027186D1564EULL, 0xDBD2597BECA7AC22ULL, 0xF3F34A5CB6140D3FULL, 0x8643EB092BA6A2AEULL, 
            0x697417AFF3462A54ULL, 0xFCB7C64642AA0BF3ULL, 0xFD35602FA5E956ABULL, 0xB848C672B914B4CCULL, 
            0x181366DA61EAC352ULL, 0xE80803BB2C66E29EULL, 0xE694C9E82E8B9D8EULL, 0x593B1D4D586153AAULL, 
            0xC63581451D7F712AULL, 0x56FEB3C327A31820ULL, 0xA3943191C6433AD7ULL, 0xD2464630F278BA92ULL, 
            0xAE1A8DBB9E6F5700ULL, 0x57639C97529468D2ULL, 0x99BBD9E273D2E924ULL, 0x8DD7AA66AD6C01B6ULL, 
            0x3587C82EF7975136ULL, 0xED9BCDFAB5024821ULL, 0x22BF5DED57E47285ULL, 0xE2A41D6E1076E2BEULL, 
            0xD5EFA2FD921C8B82ULL, 0x9D4BB08DA6C7790AULL, 0xF4CE2AA86A1F5887ULL, 0x194A2D9281C447CFULL, 
            0x8599E03610937A4FULL, 0xBD6DD5E98ECC4D8BULL, 0xD6A8564543748C2AULL, 0x3D8FE4E4D668C0D3ULL
        },
        {
            0x824CC07D2F983CD5ULL, 0x3295E9BF606AF379ULL, 0x549D49E32AD75A24ULL, 0xCD3A03FFD1224359ULL, 
            0xA20750E80DF5A35DULL, 0x32035E4AB206C562ULL, 0x92BBB57925D030CAULL, 0x8CFF4AD434B76CA8ULL, 
            0x6E7F4F4F6896991AULL, 0x996F78FF7C363413ULL, 0x293B47A7A27E9843ULL, 0x216619A138A70155ULL, 
            0x6E89DD3BED4198B0ULL, 0xDED7D8D87EBEF597ULL, 0xEA8140C4F325B1E1ULL, 0x1242CA8C444489E0ULL, 
            0xE60DC9D06DBC539AULL, 0x1AFC36E66667470CULL, 0x5C0459493B7F33D0ULL, 0x51452C48E386B214ULL, 
            0xD2BE39A00873E62BULL, 0xA8D02DC339E76BA2ULL, 0x6059A5704A3A77BCULL, 0x56A2AD6991418BC5ULL, 
            0x7AEA5D4A0ACC3BE6ULL, 0x49DAF0A2F2967272ULL, 0xF24B99F2F9D14E5BULL, 0x338EFBE87DBE5B6BULL, 
            0x3737049AC722DF1BULL, 0xF61D3836932083D0ULL, 0xCEA5BE0B0F7C4E6EULL, 0xD48B71939D2D4E05ULL
        },
        {
            0x84B8BA2C5ADB5FC8ULL, 0xA976547868A9E5BCULL, 0xC799075472D09938ULL, 0x8153E14B410988D5ULL, 
            0xD12367D3D59B7B34ULL, 0x478E0484F8B6F3DBULL, 0x69DFA85BBB543A60ULL, 0xD67AE596D55C6458ULL, 
            0xDDB03FC9A2617B14ULL, 0x7A0E91DB4144E832ULL, 0xA73580A8DC9DE963ULL, 0xB63590E10BB83423ULL, 
            0x47F5FF60C4660CA0ULL, 0xDAC614FEC1A4B5D1ULL, 0x8D55B1EE2AD02A49ULL, 0xA7FEC743E7B29AA2ULL, 
            0x1FA63EED3D3AC58CULL, 0x879CBA83677D1DA8ULL, 0xA7DD446E928116F6ULL, 0xBAB116078B6EFCF4ULL, 
            0xAC306DA83959939AULL, 0xC9404722BF563264ULL, 0xDD7CD7EE1B38DBBEULL, 0xE628D77D0BFCB4A2ULL, 
            0x67EB87A19D080305ULL, 0xA596F9E95F424941ULL, 0xBA442DCDE6CD68F2ULL, 0xABC173756AFD101BULL, 
            0x1E430B1E7240DB78ULL, 0x0492F753FA0AE35EULL, 0x78178FBCEB262E04ULL, 0x9449D5FD6481A56CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseGConstants = {
    0x04A3C8A38C74DEA1ULL,
    0x3937844C96C70EE1ULL,
    0x98B6BE4C29A73200ULL,
    0x04A3C8A38C74DEA1ULL,
    0x3937844C96C70EE1ULL,
    0x98B6BE4C29A73200ULL,
    0x4F41E61960FA5764ULL,
    0x7E3F91AB89E6CD3EULL,
    0x49,
    0x05,
    0x0E,
    0xB6,
    0x3D,
    0x70,
    0xFA,
    0xAE
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseHSalts = {
    {
        {
            0xFDE0C648F0759B55ULL, 0x015F9CE0CC6B4A95ULL, 0xFB18E7DC075046A8ULL, 0x01AD75C93ED868F4ULL, 
            0x1CBA309B4543590FULL, 0xCAA8BB09CD78CD50ULL, 0x564B41CC95610E7DULL, 0xACD0D329046535E2ULL, 
            0xA3CC2A8CEF44AEA4ULL, 0x1F40FDD19D1E93D0ULL, 0xD87D6698CE4111ADULL, 0x1921CB009EABCEFFULL, 
            0x17E5AC2C341F533AULL, 0xF2300F6D6892992BULL, 0xB3FABF3938B9ED47ULL, 0x88C4F41690C90255ULL, 
            0x3BCA9BFA28ADF29CULL, 0xE34E27A798A46C0AULL, 0xDDCF61AE7150CAACULL, 0x514A321FA41F77BCULL, 
            0x64445D487F85DBBEULL, 0x787BC2B4FF79EF2FULL, 0xDDA78F1F4B9349E0ULL, 0xC25477C22366E2D0ULL, 
            0x82D9E844D2DD30F7ULL, 0xE4858DB8A3CC3C9CULL, 0x3C08F1182E9C507AULL, 0x8F4DE1F990A974BAULL, 
            0x04579450722809D4ULL, 0x379C8F21E745FEA8ULL, 0x4A91CB40B25E2E70ULL, 0x43F04214F1DC545EULL
        },
        {
            0xA22F2D21049E3FCCULL, 0x7D7DB862F3912561ULL, 0xFD92E2BFB774EE00ULL, 0x7E9C571498B3C843ULL, 
            0xC7A33F4AA4C4356EULL, 0x2A7170CEBAA092F3ULL, 0x1BE0171F723A69C5ULL, 0x320554CC75CFDBD8ULL, 
            0xFE50EB1EEFC358B0ULL, 0xB9102B9F56D41C01ULL, 0x9C9FBFAFF377569EULL, 0x23B081E9156562F8ULL, 
            0x906A15FD77304B1FULL, 0x36979B68EF6B11E5ULL, 0xB0AD10C26747B5F4ULL, 0xDD7E109EFB5B778DULL, 
            0x0AFC6A94EA178A6AULL, 0xBE6C404C0E1F561BULL, 0xAD2BF83391698BB2ULL, 0x65474AFA6C20D53FULL, 
            0x6413A27BAE505F2CULL, 0xABCF2D483687FB14ULL, 0x1F19999767FBF6B2ULL, 0x42FC515529E24775ULL, 
            0xE2A8B06948BCF68DULL, 0x0A3D2B05C9D16AA4ULL, 0x2D783885B2895DA2ULL, 0xD9DF0B660AB2BF83ULL, 
            0xB48A38958E42C567ULL, 0x68AED037EE3438E9ULL, 0x0DFDF1936C2F1B30ULL, 0x907CDA9ECE60933BULL
        },
        {
            0xB3C4940284F0EF3FULL, 0xEFEE8F0507217C15ULL, 0x5EAA80FAB95B5B57ULL, 0x924EFCED0E3651D1ULL, 
            0x35A687729CD7FCC1ULL, 0xDBB9DCA1B22E0735ULL, 0x9EAAACCAC5F5BFF6ULL, 0x7E0F7FAE9BA0D13FULL, 
            0xEFE67F9C025F4FCAULL, 0x107EB48680A68B8FULL, 0x8200E6CD91CBFA4DULL, 0x4D0F952AACF92A89ULL, 
            0xB42BC17CA6A24FFBULL, 0xB718BEB72EBE20B7ULL, 0x861F5C791A50F294ULL, 0x9CB7408D673391F7ULL, 
            0xE281609BC6D895E9ULL, 0x5DDF08B703063466ULL, 0x85A55879F2C54A36ULL, 0x35D395C2151933A5ULL, 
            0x06156F58869EDC71ULL, 0xC3AB57E5163AA07FULL, 0x33CB74FA07A77A5EULL, 0xE9A4DA8FC8953502ULL, 
            0xCCFA1F975E0C37FFULL, 0xBE4DD34590827D61ULL, 0xB4980BE4AF32222AULL, 0x5BE6AF0EA889A124ULL, 
            0x1CACF09C6505AC84ULL, 0x8946233585FCDD84ULL, 0x4D758A83D1559BB4ULL, 0x0384361CA98B2F22ULL
        },
        {
            0x8A72C657A10BCA80ULL, 0x508D82A7B27CEE03ULL, 0x872FEE9BEC63891FULL, 0xA86ED8731446DBF4ULL, 
            0x20E60CC7DE748559ULL, 0x2BFA997E6AEC6795ULL, 0x90C344B61997C99BULL, 0xD8E6B4E26A439A1DULL, 
            0x8B76C8A68A2ABAFBULL, 0x33FDE8EE29D9473CULL, 0x6A31166037F0A2E8ULL, 0x02CF4949AD51EA3AULL, 
            0x94A9F8A65C9E1D4EULL, 0x5AC98AF0D9140098ULL, 0x53994B6C4EA2AD98ULL, 0x9F88DDB11986FFA2ULL, 
            0x3AC6D3089E03F96FULL, 0xBEF75A66A3DE006BULL, 0x66D8AAC5F635ED42ULL, 0x10B5F7EFFFD92DC1ULL, 
            0xEBB34A693917C33FULL, 0xE0BD7A567DD365E6ULL, 0xF369992DE74EEA2BULL, 0x81B57E050613021EULL, 
            0x7D918FA8CF74B268ULL, 0xA95BFDDF974D5EEAULL, 0x5601BA025B1F5928ULL, 0xF5CE64ED22D67353ULL, 
            0x8DE6992640F1EE21ULL, 0xA34828E5772EE342ULL, 0xFA8023519CB6EED3ULL, 0x4FC662ED9558B6CFULL
        },
        {
            0xEDB40F6EED0C717AULL, 0xFD02B0A70E890BF0ULL, 0x5D6D4B707BC7F423ULL, 0x843F2CCC6E347707ULL, 
            0xBF0AD5F89265ECEFULL, 0xED81699A907EFEA5ULL, 0x9312F9B9791E4BDDULL, 0x2B5F96DF1A923AFBULL, 
            0x33A6DF580759F919ULL, 0x43B050E9485B7F1EULL, 0x5A7C46C4F854C2AEULL, 0x571E5ED1B9F59BDFULL, 
            0x9601717B5A3AA7B6ULL, 0x3767E9FD3BEC8984ULL, 0xC39F755C34A6872DULL, 0x6F62D6F15AA496DBULL, 
            0x17EEA4C37F6DB64AULL, 0xBB34544C2668BD1EULL, 0x1E0B5DF504AB777BULL, 0x2EB3F268D1C9466EULL, 
            0xB4FF859891B0A1E0ULL, 0x06492A216D0739F1ULL, 0x4B8B90C8B7B7857EULL, 0xCAA52B5809E7F315ULL, 
            0xD96416DE66089F55ULL, 0xACD43207FD0423F6ULL, 0xDA1E506B3111F79DULL, 0x895F0E9ADA48D5C1ULL, 
            0xEF8E76106BE0BD73ULL, 0x014BC5355B8E2211ULL, 0xB45F3D310818613AULL, 0xD5857FC5D043A0A2ULL
        },
        {
            0xAE841091F443A8C5ULL, 0x78FEDD0AFF96F6E9ULL, 0xA1FECC26955FA7F7ULL, 0xD1E35AB7CBC882C5ULL, 
            0x8F8DD469F55B6DB6ULL, 0x39B2E0A6BC6FA32CULL, 0x082585E2ED469C92ULL, 0x6378ACF10C3F0908ULL, 
            0x767D4C494BC3896FULL, 0x8FDCDC529E258F08ULL, 0xF843AAA8B34B7E6AULL, 0x62FC4FFECBA75205ULL, 
            0x958786FE086E64E8ULL, 0xE9B252F002D3FD77ULL, 0xC169986A9F984783ULL, 0x38D6052B097637D8ULL, 
            0x2815C52F7B051280ULL, 0xBCC9CE309F838DD4ULL, 0x5D9F3CB0D7A4E558ULL, 0xDEC87D5F0A2473F9ULL, 
            0xD275AB5C590B9A72ULL, 0x7D105E55F6474B2EULL, 0xB958DC5D43618F12ULL, 0x9B8DE74774AB1BF0ULL, 
            0xD89A9816DC15AB83ULL, 0xFF7FD1A12C9F524FULL, 0x6723947FA442D0D8ULL, 0xB62C2E658BEAA3C2ULL, 
            0x470EE7FE8269A81EULL, 0xA1887ABFE5A80FF0ULL, 0x293D9E2D28C118A4ULL, 0x892D95239041F838ULL
        }
    },
    {
        {
            0x6D362A06804B5FA3ULL, 0x7BC51AAAB2839422ULL, 0x475EEBC4797E6CCEULL, 0x87E4D0CAC82C6DA8ULL, 
            0x313153D664A3F66DULL, 0xB030166049229DD8ULL, 0x607989D95372452AULL, 0xE6D9CF49C2FD42EAULL, 
            0x0E1899CE0E762B4FULL, 0xFC8C8F19FCF97889ULL, 0x20361B3796B67880ULL, 0x9DBB7C4D3833AA3BULL, 
            0xD3EF543F43257E10ULL, 0xE2C65ADC5F9F5BC4ULL, 0x8AFC843B92FD6E47ULL, 0x67383510FAC804DAULL, 
            0x16B0DCC86CBB2378ULL, 0x3171F9C49B8D6737ULL, 0xDC1E27FF6F6E5186ULL, 0xC299A1C097FEB855ULL, 
            0x916A19C2261F6B20ULL, 0x5B957626EC9C650AULL, 0x7849AF74BBCFCA95ULL, 0xED029FBCE8B70024ULL, 
            0x2D4F548EDDD1D975ULL, 0x4C6FC9211936A48FULL, 0x69E45A87B412C9F7ULL, 0xE7AAF3D1F5595612ULL, 
            0xA5FF40322E06E6B9ULL, 0x94F0717B369ED0AFULL, 0x2DB808ABFC1F0BB4ULL, 0xE04E5D1546F34941ULL
        },
        {
            0xD41D75AB6E03E6A4ULL, 0xA5FB0F5AD781640BULL, 0xE31D16004A85346AULL, 0x17A876A96A76E0B8ULL, 
            0xCFB42587C0D2B21DULL, 0x847E38C6FCA4B511ULL, 0xFA89B24C50F56BFEULL, 0xD6A03D55880D3E4BULL, 
            0x6A2A937CA2868A28ULL, 0xDBCA6231E3ACF077ULL, 0x6AB3750B878F47A1ULL, 0x0B7CDE0100D4C5FDULL, 
            0xF2E7A4CA38D5A8DDULL, 0x1B923EBBFD66215AULL, 0x0C85970AA46B7102ULL, 0x1FEC273E845BCD4FULL, 
            0x97478AEBEBC2A0C2ULL, 0x77882C2C20CD6AEEULL, 0x3BF5AEDEEA21C705ULL, 0x2824A7C34F931271ULL, 
            0x9552CDAD96E7E5A7ULL, 0x46F5AE9D89477E7EULL, 0xBFF949462D6B9674ULL, 0xB068C512D442127CULL, 
            0x57B3AE3FB6693A93ULL, 0xEAF1C4F0420235F5ULL, 0x06F63E29CBD2FF36ULL, 0x120DF255B7FE5745ULL, 
            0x58A2CD88EF582732ULL, 0x430C67B54B735EB2ULL, 0xF0E96D6DB0016719ULL, 0x2193CE860FC38733ULL
        },
        {
            0x866B2F0963BA92F7ULL, 0xE40588F6CFAFBB4DULL, 0xCD0AFB2BFFA87858ULL, 0x95663B16CAFC8A5EULL, 
            0xE27903B91A3C4233ULL, 0xD932B5FA6247B2B4ULL, 0xB42D092D638C4290ULL, 0xB156501173ECE7D2ULL, 
            0x76445A612C049D54ULL, 0x65996D77E18443CFULL, 0x4AA093F7E472C9FEULL, 0x59B3EFF3247FED94ULL, 
            0x7D3D6929FD3CC24CULL, 0xDBA0D2A8965A38B8ULL, 0x9FF5B513B54BEDC4ULL, 0x683FAE20A97F0658ULL, 
            0x5175F56A88EED8C1ULL, 0x6A494D6A490604FEULL, 0x1E16289F9F99DDD4ULL, 0xB66569E0CC157D01ULL, 
            0x0672BA59AC19ADAEULL, 0x9C9772E864351825ULL, 0x1152D14A080FC0D4ULL, 0x5BA5F8C34D443187ULL, 
            0x138A59C829B7F357ULL, 0x8E32255AEF396D3CULL, 0x1549D10677BE3EC0ULL, 0x582F7CB6E4A62F2FULL, 
            0xFA5735802397D2CAULL, 0xFF5375E35C78E502ULL, 0x0796DEF15B42F0B7ULL, 0xA0EBC2AB0B444CC8ULL
        },
        {
            0x7BC76D71355ECBBDULL, 0xD56978BFCD871386ULL, 0xC6397233DB50286BULL, 0xC48DC3B63DFBC1CEULL, 
            0x810110B47A2E467DULL, 0x969877203BDD91A0ULL, 0x2252F7229E2A7A01ULL, 0x0529857B46B18F4BULL, 
            0xD3725D722D915833ULL, 0xC020ABE93E0873C6ULL, 0x6AC362426B89F4D5ULL, 0xC8625D46FE10540CULL, 
            0x8D44DCEDA0533C42ULL, 0xDF1A526C76E026C3ULL, 0x54D7F2E332211611ULL, 0x917BF32D7A45F915ULL, 
            0xCB8526E04BD4A0C9ULL, 0x67CCC50F09852AB5ULL, 0xE0C95E3CE5B1F6BEULL, 0x48A557E16C411A59ULL, 
            0x6D08D036DE40F2D2ULL, 0x6C670AAC0755EB09ULL, 0x8BAFB91BAD9A690BULL, 0x2A60E5CCC815CD43ULL, 
            0x07FDC1D91F7634C7ULL, 0x5817052D20A447D7ULL, 0xB0A1D3877AA3D346ULL, 0x9EA856409B7C5F3DULL, 
            0x85CC97D05368B28AULL, 0xC2E7597220E9ED9AULL, 0x564D5B4DE86D37D5ULL, 0xD11F493AEE4FA401ULL
        },
        {
            0xB743B27F47C21149ULL, 0x32DB68ADBEE8567CULL, 0x92530844806E9DF1ULL, 0x90421CC6737AD41BULL, 
            0x06BBB34469E54DEDULL, 0xFEC8E7D92E501C0EULL, 0xB6C67D362C6A96BFULL, 0x9459D715145C2AE5ULL, 
            0x3CBBC60424345021ULL, 0xB817667C6782EDA3ULL, 0x84B8660EC92CF163ULL, 0x5AE917C481FF1507ULL, 
            0x1EA3FE53FD72101FULL, 0x7C56AEB9D81903F0ULL, 0x3E92F63FC1535F5BULL, 0x343F1E55B154D7FEULL, 
            0xACBC5C28D704DD12ULL, 0x6668118E1FF549F5ULL, 0x74482F043327CC67ULL, 0x71AAB01C6DA7DB3BULL, 
            0x57EA30A2E7F49561ULL, 0x051704770C748286ULL, 0xB51630BFC7F260F2ULL, 0x9C7D3B17CB4C1AC8ULL, 
            0xABE8231DE18AF2C8ULL, 0x8F8573063AA59C0AULL, 0xE0F800B1C8992212ULL, 0xF964974071C29987ULL, 
            0x8F68324EBA56E5A6ULL, 0x73193DF656EB5530ULL, 0x0321CED110262767ULL, 0x885114EA2EE18523ULL
        },
        {
            0x9EA238A214206BF2ULL, 0x76AB4593EFDD728EULL, 0xD0D8A74611EF5ECDULL, 0x53E4FD53AB817A6AULL, 
            0xC97500597E422B34ULL, 0xF60230C8D51EB8EEULL, 0x5C8DD5A303FF92E8ULL, 0x2A64E6A053F15A26ULL, 
            0xBB6893AA4324DCAAULL, 0x8BE3F0C161E01636ULL, 0xC5CF16C4D3F84123ULL, 0xB420DF132AE16AA3ULL, 
            0x5F73C164CF99BA89ULL, 0xC9495F7ECE4CE014ULL, 0x6CA8E891BA4493E2ULL, 0x8BDFEA7775AE68EAULL, 
            0x141241C1AC2858CCULL, 0x550BEAE65991E298ULL, 0x4B837A224075B6DCULL, 0xF257C1394FFAAFCEULL, 
            0x5CEC1AEAF453747CULL, 0x0A5E1A293AE34250ULL, 0xB03C80146B1E4A0BULL, 0xE165B8BDB4693982ULL, 
            0x36B3377FE5B870ABULL, 0xE69F54A29FE47EFFULL, 0xF73DE7D3642DB13FULL, 0xBC1A1A69ECE7DAC6ULL, 
            0x7B07B124643D3084ULL, 0x424239F8B4629869ULL, 0x094204F5D3788EDDULL, 0x9746EA9089E6D15CULL
        }
    },
    {
        {
            0xD23F171BB255F05AULL, 0x2D94657E17E7FA0BULL, 0xE3DEB5C1CD0CD9BFULL, 0xFCE3CC0AA22DB8A3ULL, 
            0x00D44BAED7341B2CULL, 0x6CA819592CB6C6F9ULL, 0xB80B2C5347FC747AULL, 0x7306D4EF78724C30ULL, 
            0xDE5D8A046451254FULL, 0x693096114D45D498ULL, 0xC3425F28D343D531ULL, 0x45248D58F8B9BB9AULL, 
            0x3D7C4858DAE09387ULL, 0x7AF1926CAE686243ULL, 0x15B08854A690D07BULL, 0xBD2D67B4444DDDFEULL, 
            0x7BDA51C8F96185F4ULL, 0x38C43E3D48F614EFULL, 0xDEF8B880DC216F2EULL, 0xC97BCF8886D3CDBCULL, 
            0x8C97C921A60DB7B0ULL, 0x9F0820605371F105ULL, 0xF2E9B31CD5F60741ULL, 0x433DD07EF9AF207FULL, 
            0xC3D27607E830BE68ULL, 0x012F8898DAD10A4CULL, 0xF499E47C8FEB9483ULL, 0x8C5BD31A0E961112ULL, 
            0x3B50C53BD0715A58ULL, 0x1067D7F55C3943ABULL, 0xA472B9CF09468982ULL, 0xF68F4FF092455385ULL
        },
        {
            0x77C36DEB6457EC8BULL, 0xEC55E218914E15D1ULL, 0x1FF29C026F9FF847ULL, 0xE1C68E23DF3C7F7FULL, 
            0x7E415A840DE222DBULL, 0x07F874B66472010AULL, 0x4050A912AF009D4DULL, 0x0E796A75BE21CBA9ULL, 
            0xF0F27A5DB8719EDDULL, 0x02DAD2D8BD3F652CULL, 0x71DCD98C7430E41DULL, 0xDF92F65C7FD92DEAULL, 
            0xFCFE4637CDCA6D46ULL, 0x95B9392F592BDE89ULL, 0x5AC2A33C5EDE4A0DULL, 0x12D066E5D56C87F4ULL, 
            0xEAEA2FFC4863DD4CULL, 0x9D14DF1DC67D1201ULL, 0x92F0ED7D3AE73710ULL, 0xFB565C7D0EEE6D5EULL, 
            0xBB91B08A49F7E6F0ULL, 0xAEB08BB51208892BULL, 0x6CFFF44FB2B3BB0DULL, 0xE75588C21FFEDAF8ULL, 
            0x6274505B3B1E609DULL, 0xF9FCAFB2D90ACA31ULL, 0x8B3389BE2B88DC3EULL, 0xC4ACA69D3DF06DBEULL, 
            0x60B4422AFDB87606ULL, 0x97F6FE8AF8552F0FULL, 0xAB1569B53CD93A0FULL, 0x2DF0D8B23B7A3623ULL
        },
        {
            0xBD2503211AFDABB9ULL, 0x253947AD3E983A02ULL, 0x800CC7E01ABC4ED8ULL, 0xA6C035F25F52DBBAULL, 
            0x6786D59607D0DF29ULL, 0x207E8183B62F3B43ULL, 0xAAB94AFE574ADCC5ULL, 0x322DE7062F8CB663ULL, 
            0x42F0D38C11C80896ULL, 0x181CF05AB4EABF7FULL, 0x2D7D5CFE87A45D7AULL, 0xEA1598647F556515ULL, 
            0xA56268580F6A9237ULL, 0x45ED23F22909156DULL, 0x9BD4AF49BDE1E89BULL, 0x423C95F0409D4C2CULL, 
            0x0A6CC41726205EB4ULL, 0xAABE34D8F35ABD00ULL, 0x4AD6013AF0535A4CULL, 0x2B4A324D2B47F18CULL, 
            0x6B7A4B65F066E7E7ULL, 0x4C7159F399FB7A01ULL, 0xB3C2A6B3BC4619C8ULL, 0x9283C681F3264312ULL, 
            0x8BF52356EBA0CD42ULL, 0x9A3A6A175674CE2DULL, 0x42749AD5A4A850AAULL, 0x2A1423EC6F99CAD3ULL, 
            0xE43D2D68A7C2F719ULL, 0x739A67194E401C2DULL, 0x3DAD2795677C2FB6ULL, 0x5EB3255D11CBB68AULL
        },
        {
            0x6D2B825D18D6F1E2ULL, 0x042396472C1B1863ULL, 0xF4EF6A3AD0C79F44ULL, 0xD951B2C0FC8FE81DULL, 
            0x60710DACA0F0BB12ULL, 0x573F5F8BF2C45440ULL, 0x653B4B0C7674D453ULL, 0xA999BD079DFD553FULL, 
            0xECF4B101090732E4ULL, 0x44994E5DC93294B6ULL, 0xCE4BE1C6D56F944BULL, 0x1B61B44FCFA1A9B0ULL, 
            0x9000B78A7B03501EULL, 0x8ABB61B993E0C221ULL, 0x9ED3209A579A6B54ULL, 0xAD79CB72BECCAC2AULL, 
            0x2E59CAC672CB2969ULL, 0x77B17C67997B1552ULL, 0x6C850928FC7D1009ULL, 0xBD86B57C3B6D7A87ULL, 
            0x2019EF39499872EEULL, 0xFD97464B558047C2ULL, 0x37B69FE7F4A3D6FAULL, 0x837D0D3A9BE817A5ULL, 
            0x6C6DC21446292AC0ULL, 0xD016A2405B2A80A4ULL, 0xE269EE1BE66608DFULL, 0xA9511811F63B7F2CULL, 
            0xDFBB01B196AB30B0ULL, 0xDF404C6600D0E567ULL, 0x8274D8C59DF4D059ULL, 0x0E8E8EDF8D468B5EULL
        },
        {
            0xFDEC2256B367C19AULL, 0x10EEB4FF9628E6CCULL, 0xE30CF89D4C5E7515ULL, 0xFFA70DE34E50D6D5ULL, 
            0x3D15D649313F51E0ULL, 0x9D240DC688CD1E2EULL, 0xCB578B657BDEEB5BULL, 0xE720CEBD7D285A32ULL, 
            0xC321CEA495FBCCD7ULL, 0xD35A8901E5F3A280ULL, 0x93EFBC1821397E2BULL, 0xF311F19CEA39763DULL, 
            0x5BD1BF90BBA7042DULL, 0x4E2DDF69790A1DE9ULL, 0x07D1E70FD2B5AABDULL, 0xFC1DFF368DF6BC55ULL, 
            0x2D7C151756CB62BBULL, 0x654E431A86DA7FBCULL, 0x2863E96FD9939DF5ULL, 0x5B36E4D7BE6458A6ULL, 
            0x73635280DC50637DULL, 0x8A69629067321C28ULL, 0x6D80641DEA6FB08AULL, 0x58950EC81CF85ACCULL, 
            0x5CC43F9DA0DDF189ULL, 0x6E6A4AFE6A3F1635ULL, 0x72CD0C340DA592E8ULL, 0x1B7170FA5EBD0F9AULL, 
            0x2086BE68AB9FAC2EULL, 0x389DD968862EA2CFULL, 0xEF24D8D295CF2778ULL, 0x204964E01F479ADDULL
        },
        {
            0x0438A9EA91DC22FFULL, 0x490DB3AC9E7E410CULL, 0x1346FA16568C59DBULL, 0x52B2FB47F6A70012ULL, 
            0x7C5E31FFC55092F1ULL, 0x363F2B24DDDB1F27ULL, 0x0B24DC877C59F838ULL, 0xDDC965BA667FC25DULL, 
            0x5002E6B8B61B32B7ULL, 0x399898F1CC37BB07ULL, 0xB668F1E1A07DB5C0ULL, 0x16B61360007217E4ULL, 
            0xBB759E3EC17453FBULL, 0x06B776A17934E99EULL, 0x4D235901E83FA5FDULL, 0xC3F95EB9A571B8B1ULL, 
            0x23575ADA3F466C95ULL, 0xDFFD7F2D35C7626DULL, 0x5F310493C7C8B4E5ULL, 0xE1FF526C1354A69EULL, 
            0x8333791617ADEA4EULL, 0xC79F5B5E41ABDE29ULL, 0x63E3EAE4CE2EEF70ULL, 0x87F998961AE4524DULL, 
            0xC9023A108D7569E8ULL, 0x0A3D0CD6CC23E4AFULL, 0x7D347BB1F266724AULL, 0x131A41E3D16CF190ULL, 
            0x6A39575CCDFC849AULL, 0x7973B5F09AD221EAULL, 0x9B728948A7C9AD54ULL, 0x49FBC9EF9A62F716ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseHConstants = {
    0xCC0F02203590A8D9ULL,
    0xD2B9614DE46C13FBULL,
    0x562DD3E92FC3B85BULL,
    0xCC0F02203590A8D9ULL,
    0xD2B9614DE46C13FBULL,
    0x562DD3E92FC3B85BULL,
    0x9B0395E7289A782CULL,
    0xE1B33D072C42C403ULL,
    0xEE,
    0x9F,
    0x61,
    0x3F,
    0x12,
    0x55,
    0xC1,
    0x39
};

