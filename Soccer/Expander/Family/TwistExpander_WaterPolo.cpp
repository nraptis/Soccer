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
    std::uint64_t aPrevious = 0xCF21E9FFB4E8ECD5ULL; std::uint64_t aIngress = 0xB33B150544D97A53ULL; std::uint64_t aCarry = 0xCDB381A682841FF3ULL;

    std::uint64_t aWandererA = 0xA8FAD0C136DE575EULL; std::uint64_t aWandererB = 0xCD2060D74B9DB12BULL; std::uint64_t aWandererC = 0xAD98CA6E83DC275AULL; std::uint64_t aWandererD = 0xFF1DAD0D494B3823ULL;
    std::uint64_t aWandererE = 0x93AB788478021E33ULL; std::uint64_t aWandererF = 0x806DB839FD122995ULL; std::uint64_t aWandererG = 0x8BDBA40B44E0181FULL; std::uint64_t aWandererH = 0xA71FB9B34BDA83FAULL;
    std::uint64_t aWandererI = 0x9DE0989959768155ULL; std::uint64_t aWandererJ = 0xBD1498E9544C6F01ULL; std::uint64_t aWandererK = 0xC60DB58EABD0F57DULL;

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
        aPrevious = 14846919225990855032U;
        aCarry = 12825192325338523297U;
        aWandererA = 13568296215020428822U;
        aWandererB = 17070954369077514676U;
        aWandererC = 9597568089214407300U;
        aWandererD = 13422051340081845338U;
        aWandererE = 16741898093295603745U;
        aWandererF = 12305232499580139021U;
        aWandererG = 13845516288695736160U;
        aWandererH = 14310752125248134335U;
        aWandererI = 14813814230590728068U;
        aWandererJ = 12182514050054184540U;
        aWandererK = 10714634136658428457U;
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
    TwistExpander_WaterPolo_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_A_D(pWorkSpace,
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
    std::uint64_t aPrevious = 0xADFEA33F939B72F2ULL; std::uint64_t aIngress = 0xD46F9D1401ACD0AAULL; std::uint64_t aCarry = 0xCD9A19F513F1C300ULL;

    std::uint64_t aWandererA = 0xBEF774F6E45CA1A8ULL; std::uint64_t aWandererB = 0x86E257C56A6C78B7ULL; std::uint64_t aWandererC = 0xA0678CBA5E79A881ULL; std::uint64_t aWandererD = 0xD7D6F9B680B8BFA9ULL;
    std::uint64_t aWandererE = 0xE42BFC2F3642FCFEULL; std::uint64_t aWandererF = 0xEFF28A77C9640DD5ULL; std::uint64_t aWandererG = 0x89A4FFE2500C2B85ULL; std::uint64_t aWandererH = 0x839F568158EAE3C5ULL;
    std::uint64_t aWandererI = 0x8DA91EC7BEB4B2C0ULL; std::uint64_t aWandererJ = 0x9751CE6825E16225ULL; std::uint64_t aWandererK = 0xC13C8A27BD9CD59CULL;

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
        aPrevious = 14592972170540628187U;
        aCarry = 18051366458528170596U;
        aWandererA = 12241032553289615381U;
        aWandererB = 11510300525879592761U;
        aWandererC = 18081692252446883889U;
        aWandererD = 14091182129012384604U;
        aWandererE = 13802245400404982504U;
        aWandererF = 18159105582203761674U;
        aWandererG = 10953359017338774218U;
        aWandererH = 18192138077705354223U;
        aWandererI = 13622133847335375482U;
        aWandererJ = 10855808517613298778U;
        aWandererK = 14544936035246664233U;
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
    TwistExpander_WaterPolo_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_B_D(pWorkSpace,
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
    std::uint64_t aPrevious = 0xCAB8FBB20FF7E351ULL;
    std::uint64_t aIngress = 0x8C47B0775FB774ACULL;
    std::uint64_t aCarry = 0xE0629E46A589678CULL;

    std::uint64_t aWandererA = 0xB9373461C9DFAF6DULL;
    std::uint64_t aWandererB = 0xFF32311ED17FABD9ULL;
    std::uint64_t aWandererC = 0x9C774FE9C91FEB26ULL;
    std::uint64_t aWandererD = 0x92D07AFD5C3A4293ULL;
    std::uint64_t aWandererE = 0xAD315E70FA8FACD8ULL;
    std::uint64_t aWandererF = 0xF516B84EDB659EA0ULL;
    std::uint64_t aWandererG = 0xB1618DA355F980C6ULL;
    std::uint64_t aWandererH = 0xF13E857A072B78C9ULL;
    std::uint64_t aWandererI = 0xDED1F103F1DB4271ULL;
    std::uint64_t aWandererJ = 0x8714BBCBDCD4F080ULL;
    std::uint64_t aWandererK = 0xB90403C84176BD39ULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD, 1);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA, 2);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC, 3);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB, 4);
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
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD, 5);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA, 6);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC, 7);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneB);
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
    // temp storage: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_WaterPolo_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::GROW_B(pWorkSpace,
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_WaterPolo::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB4C50F961FE6EA72ULL; std::uint64_t aIngress = 0x9E3EA32B4DE61D5DULL; std::uint64_t aCarry = 0xEB1ED1B6A65D9C34ULL;

    std::uint64_t aWandererA = 0xA1178F8A1233AE3DULL; std::uint64_t aWandererB = 0xF1CF5B29A57780B6ULL; std::uint64_t aWandererC = 0x9D15DE38C06C6831ULL; std::uint64_t aWandererD = 0xB924292A3ED645D7ULL;
    std::uint64_t aWandererE = 0x897F931FC1DD1C19ULL; std::uint64_t aWandererF = 0x846EFA0421160C72ULL; std::uint64_t aWandererG = 0xA604856E9BE4ABE8ULL; std::uint64_t aWandererH = 0xD508ABC93BDDA2B5ULL;
    std::uint64_t aWandererI = 0xA7F5A86C8A8ACF89ULL; std::uint64_t aWandererJ = 0x8816DFF143D5A7E3ULL; std::uint64_t aWandererK = 0xAFD3A4A248140640ULL;

    // [seed]
    {
        aPrevious = 11234455373123085735U;
        aCarry = 11875972930554483810U;
        aWandererA = 16193147225110559543U;
        aWandererB = 16415534240703639329U;
        aWandererC = 14576265773360784817U;
        aWandererD = 9621386207577710097U;
        aWandererE = 15188945386203420112U;
        aWandererF = 10920278079765809005U;
        aWandererG = 15068755363626420925U;
        aWandererH = 12968694220397484346U;
        aWandererI = 14836351836175579877U;
        aWandererJ = 14270046153503304255U;
        aWandererK = 11978773008867737544U;
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
    TwistExpander_WaterPolo_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_WaterPolo_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_WaterPolo_Arx::GROW_B(pWorkSpace,
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
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 3, 2 with offsets 3445U, 770U, 7197U, 5146U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3445U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 770U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7197U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5146U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 0, 3 with offsets 1183U, 960U, 1417U, 7593U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1183U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 960U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1417U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7593U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 2, 1 with offsets 1378U, 2683U, 7318U, 7551U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1378U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2683U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7318U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7551U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 1, 0 with offsets 591U, 5995U, 7324U, 3202U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 591U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5995U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7324U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3202U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 0, 1, 3 with offsets 828U, 1329U, 1246U, 1687U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 828U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1329U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1246U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1687U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 3, 2, 0 with offsets 536U, 1357U, 1366U, 636U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 536U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1357U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1366U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 636U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 3, 2, 0 with offsets 946U, 1953U, 412U, 788U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 946U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1953U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 412U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 788U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 3, 1, 0 with offsets 803U, 81U, 1303U, 855U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 803U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 81U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1303U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 855U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 845U, 1151U, 1496U, 1966U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 845U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1151U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1496U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1966U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 1 with offsets 1563U, 1034U, 2381U, 3249U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1563U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1034U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2381U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3249U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 0 with offsets 6117U, 5894U, 315U, 2132U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6117U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5894U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 315U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2132U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 1, 2 with offsets 1872U, 4561U, 6034U, 2494U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1872U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4561U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6034U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2494U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 0, 3 with offsets 5436U, 4225U, 6362U, 4481U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5436U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4225U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6362U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4481U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 2600U, 7028U, 1901U, 3025U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2600U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 7028U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 1901U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3025U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 210U, 1793U, 2029U, 1229U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 210U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1793U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1229U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1042U, 806U, 970U, 1043U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1042U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 806U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1043U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1861U, 341U, 1037U, 1658U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1861U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1037U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1658U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1817U, 348U, 1800U, 1132U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1817U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 348U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1800U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1132U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 3, 2 [0..<W_KEY]
        // offsets: 570U, 471U, 2027U, 498U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 570U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 471U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2027U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseASalts = {
    {
        {
            0x8EE7B34FCA897C32ULL, 0x8161749CBD32FB1EULL, 0x39EA8993BD1A57B9ULL, 0x6C8432BEE4D525A1ULL, 
            0x1FE3543C911D79A9ULL, 0x9E5BB1017B18ECF0ULL, 0x8EAE05A7B4D49579ULL, 0x3CE52714BEB0A95EULL, 
            0xEFB5F2E7895DB2CDULL, 0x81AFAC34A449304CULL, 0xC19BFD774CCB97D1ULL, 0x1814DC8CFD9C7DDCULL, 
            0x57879E302A690F0CULL, 0xEB358EA7B7559F82ULL, 0xA581BF00E056EA20ULL, 0x13B378C948A11384ULL, 
            0x6BE696034E6DAEECULL, 0x544FC08F9ABF652DULL, 0x3D6DAE4DA8C166E4ULL, 0x508D57EAF430E898ULL, 
            0x8A0A96A422776ABDULL, 0x28F0A9B28494D2CEULL, 0xC692374EB9E4BFA8ULL, 0x078BB8B4FEFA9E7AULL, 
            0x2F28C6FF59C398E9ULL, 0x3FC7CA204B55C999ULL, 0x558487085F15CACAULL, 0xA80B9B20EBE243B0ULL, 
            0xF9660BAF67D4A648ULL, 0xB7EA78135751B684ULL, 0xBC650597BE32EE71ULL, 0xF5F735FFD008F7ABULL
        },
        {
            0x79E7AFE5C0C0E4DBULL, 0x276D2EF204054BE9ULL, 0x6C798F50E00E7FC7ULL, 0x01880BC835175D2FULL, 
            0xD899441C72BD3866ULL, 0x4426507C90BDFE04ULL, 0x0E4E53D56061A846ULL, 0x1801A6E486EEA599ULL, 
            0x7C1B950A1A528547ULL, 0xE0ED9059DA13EC1CULL, 0x06DE1DD062E72AFFULL, 0xA9D6E6087F7A66ABULL, 
            0x5EACB4E2081D4B35ULL, 0xB16AAF7DF0572DCFULL, 0xF96E541C230251DCULL, 0x23B37B30FAE303AAULL, 
            0x595C19A6FCB60C56ULL, 0x9F13038AA45E568DULL, 0x39641C4BAC65B84FULL, 0xB71003C62CD56FF4ULL, 
            0x0FE7B47E650B2F3EULL, 0x481312F59D791772ULL, 0xD6B4833E4FB0EAB4ULL, 0x74E13B82B9FD69ACULL, 
            0xDEE4C893C8E1F935ULL, 0x705BCF884772BE79ULL, 0x55AAC94989DA6362ULL, 0x7C0F95F902F0B048ULL, 
            0x09A04F291529F980ULL, 0x9AC780F63F826A91ULL, 0x5066A71EFA7D659FULL, 0xCA2A22A32D5C5B73ULL
        },
        {
            0xDB432CB612C1133FULL, 0x301B33873BD4CE62ULL, 0x93AFD06EB2E5F699ULL, 0xECCEF98DF9DA1943ULL, 
            0x60923171B149D9C7ULL, 0x9F26C0D7D8EC364AULL, 0xCD2180EB9B907F47ULL, 0xDEB023AA9B820BFEULL, 
            0x961EECE2DFE3DC95ULL, 0x890982373C458FEBULL, 0x8EAF62E4875F59DDULL, 0xFECECFF09ED34A0CULL, 
            0xD45E842399AE6071ULL, 0xC23661CD82B3BECDULL, 0x66460D731A546ABFULL, 0x9C3E4B3CC7579521ULL, 
            0x700B95F45957B6E7ULL, 0x2123A0781365EA89ULL, 0x98E9311559933A8BULL, 0x5DD3A0406248E63BULL, 
            0xBA161A1B252DCBC3ULL, 0xF75A5F05D9912E12ULL, 0xE2F2775CBC3CCB02ULL, 0x2355E3B3EE5AE2C5ULL, 
            0x6CFA6775A250E65CULL, 0x114A0D0F6CFB7248ULL, 0x2323A6878D044770ULL, 0x5CA410253C14B839ULL, 
            0x00DD95910AFEA873ULL, 0x6D1796B6FCCC8940ULL, 0xCA254A364D9A930DULL, 0x2D2BF44B94CB716DULL
        },
        {
            0xA3DD56EA8675DA2BULL, 0xB80D31FD58293D49ULL, 0xF3D8A88C19D3194AULL, 0xFEB20231134A51F8ULL, 
            0xB1ED7582B3CF8875ULL, 0x91FD70650AE47F8AULL, 0x1792C620DA4392F4ULL, 0x007EBB4D8042854EULL, 
            0xEF8A69AF13457F46ULL, 0x0253BA0E4DC92E3BULL, 0x26E2F1EE0BC761AAULL, 0x75DBBD15168977E1ULL, 
            0x417F4A4C523D1247ULL, 0x04B90DB00DE487EAULL, 0xBC81C2D010D5E82BULL, 0xDB48DD9FCD65DE13ULL, 
            0x052FDF52D8BE315AULL, 0x9C205D147A1E8E17ULL, 0xC0158D441F6C9007ULL, 0x1A4CDBC3B9714419ULL, 
            0x3C8D463498FCC333ULL, 0x6971263A4FB86F27ULL, 0x5B9EA9D9AFFB22E9ULL, 0x4CC1F8A4C0FBCA7FULL, 
            0xDC1B6D34AC30B186ULL, 0x2D564BD9AF538455ULL, 0x25598CCABA9F68F7ULL, 0x03A2186E33BFA958ULL, 
            0xD6C3D71CA7194362ULL, 0x177EC02630BC4774ULL, 0x8DFF23B802824FA0ULL, 0x85C3D89942569425ULL
        },
        {
            0x5F9B4EF331FE0040ULL, 0xE9AFF65D5B168C86ULL, 0xE330D385A730A644ULL, 0x50F45F778414DE2AULL, 
            0xEF18A772B7ADBAA8ULL, 0x348D822FA1208A09ULL, 0x6549486EACB2421CULL, 0xD015C14C0478D3CAULL, 
            0xE2448555ABC5C6DEULL, 0x7E766A2E60F94F8BULL, 0x3CFB42B83081E2C3ULL, 0x98F081B81A829300ULL, 
            0x55034EE3B1089CD6ULL, 0x7516A5610D0139CAULL, 0x4F2062D85C0D6D26ULL, 0x1CB9091D0270C500ULL, 
            0x31087D653C24001DULL, 0xC4097457D71662A9ULL, 0x121C83F687B1BC70ULL, 0x68D19DCBF6EA88E6ULL, 
            0xB148BBC4F3DDBD49ULL, 0x1894E4541FBF5EAEULL, 0x5D54D7893A4DD0F7ULL, 0xD1BA1A86E9392954ULL, 
            0xCC218B7A53DA4134ULL, 0x3A805454573F0EE6ULL, 0x56EDDACDE60B8B71ULL, 0x320DBECB0E97903DULL, 
            0xB8DFED09E4EEA98BULL, 0x9FC42C4D149DB1A2ULL, 0xE203BA3CD857D17BULL, 0x6B0F1434C23E5B41ULL
        },
        {
            0xD16AC307AB224433ULL, 0xF9B15A8DC8A60686ULL, 0xACF5226D1108CADBULL, 0x4FFD1FD8C01D3BD9ULL, 
            0x70B763E8FC7AA090ULL, 0x02F052BBA897DC18ULL, 0x5AB982ABF8081DCBULL, 0xC8CAA0E764D59D7EULL, 
            0xD4524F2D70858BE7ULL, 0xECDF1A65721C4E4FULL, 0x30498CF275B9AE72ULL, 0x730040A633A15EF2ULL, 
            0xCAD95DE4FD4650A0ULL, 0x7B90A3820452208AULL, 0x50214CCCB28C82CAULL, 0x17D6DFE3290720A6ULL, 
            0xA83576F591260999ULL, 0x8F261D78F3DD4977ULL, 0x74D97CB966E435C0ULL, 0xCACFAC465E7D4DD9ULL, 
            0x7F7A47C6536721E4ULL, 0x7E7F04181F1403C6ULL, 0x2865FE43D7B95090ULL, 0xCDE61E79EAD18492ULL, 
            0x93409AFB2D2845F8ULL, 0x50835AC160C30E70ULL, 0x94F88AF5958E83D6ULL, 0x31F16BB52A4039CFULL, 
            0xDDDB971D49319A82ULL, 0x575E8ADF58D256FEULL, 0x228830D61231376AULL, 0xCBC32ED4D3C445E6ULL
        }
    },
    {
        {
            0xC75BC1059D74606AULL, 0x055AE751673ABE17ULL, 0xA9825BFBC5712412ULL, 0xE82B419D8D6FC5E9ULL, 
            0x9BCA84C684804166ULL, 0x5F9557EF936411D2ULL, 0xCF77C1D9EBF25EAFULL, 0xBEE2E6805195F52AULL, 
            0x55FA2C29DB17DB9AULL, 0x48220F89F99872DBULL, 0x1C6EBE0E55DDB46BULL, 0xD4D6F766F170A722ULL, 
            0x03844358364AA364ULL, 0x09FDA85FABFD1B25ULL, 0xE434B12C92046F5AULL, 0xA0C243ADE5776DD9ULL, 
            0xC46CEB594211555CULL, 0x5F75DDB4CE008475ULL, 0xCF8C18ACE205A3ADULL, 0xBDC02D4645B3E958ULL, 
            0xFE9CAD035B728D0FULL, 0xE5F06094F29DE8A0ULL, 0xE808A862928B2355ULL, 0xA6942B85C45A982CULL, 
            0xDC859E8B430CEC56ULL, 0xB333C864FC65E765ULL, 0x3407FDD3DB5E43DBULL, 0xD1A6D3D9574323BBULL, 
            0x64193E171435D4A4ULL, 0x905E12CB3027E790ULL, 0xE35B03343CAEE4F7ULL, 0xCBDC40A918143F9EULL
        },
        {
            0x712DC445345E9191ULL, 0x5623C4A7A9D878FAULL, 0x6DA39487FCEFA0B3ULL, 0x8C632E555FFAF6AFULL, 
            0xB771CB19BF1D1C35ULL, 0xB818ABEA2EBDB465ULL, 0x8E4EC7B362028737ULL, 0x19FE40D8024F3B6AULL, 
            0x3BCFC2465F0F3EABULL, 0x60B9AC52C6772F5DULL, 0x43473A9EA9C6A2D7ULL, 0xD73ACFCAAA600652ULL, 
            0xE62282DB240BA605ULL, 0x8FF00FEB898F497DULL, 0xF5A89024F70F3092ULL, 0x2D4ECCA8C145B198ULL, 
            0xEC604A27621EB8BBULL, 0xFE8D2498B415F1BCULL, 0xC215FA4CD1C369B6ULL, 0x9068A58752889355ULL, 
            0x5B491BEA255EF5D1ULL, 0xC56264C04414C53AULL, 0xED471BA5D465EBECULL, 0x7793E066A0520155ULL, 
            0xA4062239CCDA6289ULL, 0x537F21859400BF20ULL, 0x276872C45A5993DCULL, 0xF523EAFC51B33DC8ULL, 
            0x10CCB65221AA035BULL, 0x7EA562DEE33BDFBBULL, 0xFD6333F6720D0BD7ULL, 0x18D2BF7542A0C8F9ULL
        },
        {
            0x4DAA8710053018A4ULL, 0x3A82E5569E99B3A9ULL, 0xFBC3A6A4DEC73AE3ULL, 0xEA8C6759F7399AB3ULL, 
            0x7087DABCE784BF39ULL, 0xEA1CB8CE1158AB88ULL, 0x98CDC8D617CD3603ULL, 0x5D3BAE1CB2C1ED07ULL, 
            0xE81CC9C2EA6E9143ULL, 0x5C8E0D0FD1B64ABEULL, 0xECF82F0E028DCA07ULL, 0xDFEBC185CED84BFCULL, 
            0xEE87AF236A0FBE21ULL, 0x8F5933C3F5F8BE92ULL, 0xF22CA7C253F99BBCULL, 0xC16F46733FC67193ULL, 
            0x39571D60EA461279ULL, 0x7CBB3C3845150962ULL, 0xD5133CE4E4C9030CULL, 0xF638BF872F459A63ULL, 
            0x44D9F45D34A7BCD6ULL, 0x9159A81AC4EC555BULL, 0xC1D7ADAFB26E4145ULL, 0x87E6C93C1238C757ULL, 
            0x99EDE7BDD28E6339ULL, 0x12EB0468DA968A3CULL, 0x58A1F2E78C2F1CFBULL, 0x272FB0E4C6474A6DULL, 
            0x3A892046E5E6A31AULL, 0xA33DD913F71B0B70ULL, 0xC7DD9E9E5C73FC6CULL, 0x8AB1259174ED75BDULL
        },
        {
            0x13E76807EDF7A549ULL, 0xD9006E66C4E623C3ULL, 0x916810EA81BED6CCULL, 0xE015363334AE2BF0ULL, 
            0xE0B173B009C7175AULL, 0xA0E6413C02B262A8ULL, 0xB31939E7C34786FFULL, 0x771BCB3D309FE511ULL, 
            0x0C81E5AEAB60457EULL, 0x6EDA0AD41B107FE7ULL, 0x97E71A4213A68E33ULL, 0xAAB8072AC1A72919ULL, 
            0x0CC8A851DD98E1C3ULL, 0x722DFC1ACB48D127ULL, 0xD2E79BC6BA6D1365ULL, 0x3E28403858B18F17ULL, 
            0x73E550268E5207F9ULL, 0xBEF198A8CF4DDCBEULL, 0xE00E94CE26BBE6E2ULL, 0x18DC0FBA63D4A9A0ULL, 
            0x7DF86731C99DAA4EULL, 0x8E89740C1E14DC99ULL, 0xFACE8DD970463E9BULL, 0xE80A794081409168ULL, 
            0x51EFD43DAD8F8F64ULL, 0x4ECE6D8BD3AD655CULL, 0xB54821A285764824ULL, 0x52AF79F3DC5C107CULL, 
            0xE9A4DB15A561E465ULL, 0x9B4447C2080D4EFFULL, 0x37AB904AC72F380CULL, 0x2A1A50179C34B31AULL
        },
        {
            0xB588F9DA9129E686ULL, 0xE3D843A5BF2896AAULL, 0x91F75AEBF5239F15ULL, 0x15BD208362B9AB80ULL, 
            0x0954AC3F867D1781ULL, 0x1D6EF6026D53C0C8ULL, 0xA18E6540FA845DBEULL, 0xDD33A62E73567FBCULL, 
            0x1E1577C1B1681CE2ULL, 0x01AC30C94A7B6D2FULL, 0xD73BA4C8921D2515ULL, 0xD993F455AA084BA2ULL, 
            0xBCB1985456C8368FULL, 0xBC0C6A5A75520F90ULL, 0x2CA91DB401B6D542ULL, 0xC834D49E3C1974FEULL, 
            0xBD8B68561177857FULL, 0x5187CADE13451EA4ULL, 0x826A00AF320D69D5ULL, 0x549AD9538DE891D3ULL, 
            0xFB56386BE0893FC7ULL, 0x0CC93E417897E2A4ULL, 0xACBFA18875D5CB8AULL, 0x7B8A82433962D67AULL, 
            0xF14B6D09D0A7F1C6ULL, 0xBDDE36E106BC11EFULL, 0xAFB933A1FEEB38B0ULL, 0x39FC10F5C530C4B0ULL, 
            0xFC2F3791987CADC9ULL, 0x4BF111E737D48544ULL, 0x215D8738E403CB51ULL, 0xFAE88EBC174C87D6ULL
        },
        {
            0x7645F5BBFE0666ABULL, 0xA39DC602C60FC6F5ULL, 0xCDF27FD2641D8BD1ULL, 0x614DD869A74FE0C8ULL, 
            0xC8A192F0D01EFD69ULL, 0xC22B8C06866EAAD0ULL, 0x64FC8B915245530AULL, 0x18B0A8288FC30A62ULL, 
            0x0CAF627D548E23EEULL, 0x064CFF62737D716CULL, 0x87938BA38ED0C23DULL, 0x026EF855879DAFECULL, 
            0x0CF81C3D5B910955ULL, 0x89D8AF0D0735EE70ULL, 0x57DCBA20CE7D5F24ULL, 0xF38D85481BD6014FULL, 
            0xAD7A839D686598EDULL, 0xB88CEDD0EBBD6F9BULL, 0xF4A22DB793F72C0DULL, 0x0DE2B07D3AD13A8CULL, 
            0xC0C4B26A3B78C4E2ULL, 0x60ACE3EB4CB75386ULL, 0x6DC8EB9A1BA8F2E3ULL, 0xB39514F3DE9ED773ULL, 
            0xB5E358B02A8F99B8ULL, 0x1F422094E3F22150ULL, 0xA0BE99FC1B541F79ULL, 0x09892C53215C153AULL, 
            0x9BDD3C87B4672A71ULL, 0x5D527D22FD8A9D99ULL, 0x015C422A567F9F87ULL, 0x8EB9C39A69C0EC64ULL
        }
    },
    {
        {
            0xEA748C6568491FBCULL, 0xED58EE99C0BB1DD9ULL, 0x2755CABA45B2893FULL, 0x93226257A2BE22F2ULL, 
            0xC0221744BFE1F8D9ULL, 0x680130E4EE290D63ULL, 0xB2A1E47CD6E6AD30ULL, 0xB2865E29FCA65AD1ULL, 
            0x5B2EEC31F1E21196ULL, 0x85B3FD79E7F6B0CCULL, 0x4B65B79773047E2BULL, 0xDB859D022F3AEA53ULL, 
            0x4D207F6002E517C6ULL, 0x0A65AB356EFC2076ULL, 0x0072DF70B9D230D4ULL, 0xC00B5E3641C4CD77ULL, 
            0x9388434100AA8CF7ULL, 0x06AC3D35F82CF32AULL, 0x0B04F2BCB3D50FE8ULL, 0xF8327836B02FB1E7ULL, 
            0x61A4903B8563DB98ULL, 0x9A35566D5A2921D9ULL, 0x5451BD652AFB89DFULL, 0xF1288F7D75ED9733ULL, 
            0x27D041262260A847ULL, 0x68E483EDC85997ACULL, 0x2664F63CA6A9F045ULL, 0x1B341D4241F1B5FFULL, 
            0x8B8F71E5B1A9FE21ULL, 0x27143DB2F0A1D75CULL, 0x2E78FDC49C81A715ULL, 0x2A2F24A4FF6E805EULL
        },
        {
            0xBE949F7AA6BD0BA5ULL, 0x507E83DD4F324C07ULL, 0x63AAB0645103172FULL, 0x3558DD30E53F5BFFULL, 
            0x26D9AE95791FC73EULL, 0x093F4114852C340BULL, 0x8D223E79BF129672ULL, 0xBD9D629A84B7CE72ULL, 
            0xBCA12A6D103AF54CULL, 0x6AE2185AD0671D6EULL, 0x8DA1E870A96310BFULL, 0xD3900D7E88A89BBCULL, 
            0xC9E17178CA72AD48ULL, 0xA7B35C11B181E22DULL, 0x192DA01D5BF9A669ULL, 0xFAB4EA3F539A0F5DULL, 
            0x410F4C7510C301D7ULL, 0x877D0C6C0E545243ULL, 0x8DFA462C7B6FCF04ULL, 0xFF0B1CD3B9C03226ULL, 
            0xCC7691A8F1D70A9FULL, 0x7B26AA32DD76BE4DULL, 0x086CA0FE4F18B9ADULL, 0x37E37578BC632DD1ULL, 
            0x2BE5A57EF17A13E8ULL, 0xFB48D52B983933CBULL, 0x48F4C3DD739DF8D7ULL, 0x5C9818C73B4CA0A7ULL, 
            0x23FB6253050FDF9BULL, 0x4A091A701B7735F1ULL, 0x919F08C2E75754A2ULL, 0xCA291AC8EFE2CEF5ULL
        },
        {
            0xB53DF01E1BBF41D1ULL, 0xA384F6036AB3A1AAULL, 0x6E7B527B46784B1EULL, 0xCFFA9A62CF04538EULL, 
            0xDE8DB3E6EBF0A3E1ULL, 0x887C7E623CB6B8B2ULL, 0x1938848B6CECBA48ULL, 0xC729562A76978A3DULL, 
            0xB63347B20F4012CAULL, 0x5B5EE15204B19F44ULL, 0xB1790C2E8A7FAAFAULL, 0x37FAC02AD34330ABULL, 
            0x57AB6095EF7E87A2ULL, 0xA8BAF69B52178C4FULL, 0xEF44BE950D7E3219ULL, 0xFE25E406980F14ADULL, 
            0xCF19922BA5550444ULL, 0xA62B14DDE1630053ULL, 0x5328452D8311BBB9ULL, 0x6841F89307F65AD3ULL, 
            0x29D384BA29A22F9FULL, 0x1F1F27F6B49E8920ULL, 0xF5772BF9E7902F1FULL, 0x3DC0EC65C169F4DBULL, 
            0xDAB2717DAC2BDBF1ULL, 0xD13C2772B7825748ULL, 0x46A528C7E417E136ULL, 0x6E520488A3AB22A0ULL, 
            0xCEF1D47CDB90DD99ULL, 0x971089DC269B6518ULL, 0x1913836B4A81705EULL, 0x9562EC9CDE515E71ULL
        },
        {
            0xC12E62F2D6B10393ULL, 0xB2E7AF848C4D72EBULL, 0x540F1ECA98A22637ULL, 0xBE645D2CB145AB5AULL, 
            0x75000299D4995594ULL, 0x97F49BF810402B9BULL, 0x418A329F3F380E29ULL, 0x5727BA740E0CA8B1ULL, 
            0x240661AA61C79F99ULL, 0x4320C8C0B6F8EEB7ULL, 0x0C6CD81049869246ULL, 0xA95F2EEF1D42323DULL, 
            0xD7EBCEF9CF16FF56ULL, 0xD4404693033E4CA9ULL, 0x4A17BFE07C6A10E7ULL, 0x5960DF7C9186ECF2ULL, 
            0x817A7DB96EB0FE55ULL, 0x5D6044420E78423AULL, 0x4B4E449E03860A2BULL, 0x5C75570D7500C4B2ULL, 
            0x5C3102FBB47B0FD3ULL, 0xC6A711665C267388ULL, 0x24B24B86C7DA74FAULL, 0x1C39D12A395AAF46ULL, 
            0x1FE54F57E16E551DULL, 0x63093D5AD71B81F0ULL, 0x49EA0C9F899E50C0ULL, 0x83FBC4547BBFDA77ULL, 
            0x45CF666DBBD3A57DULL, 0xF9BB5899C92E309FULL, 0x59A447E7868D26A4ULL, 0xAAF37D0BECE3C8E5ULL
        },
        {
            0x1ADF82C158631945ULL, 0xBCCDE7C6DA44F1B4ULL, 0xE1D4129EF79E36F1ULL, 0x4233C1EE61956F0AULL, 
            0x7D7C661ECFA90F4AULL, 0xC876AA7A2E9CFC91ULL, 0x4733BB0568D342D0ULL, 0x59DDF05564E3330DULL, 
            0xF1595721093EF2A2ULL, 0x3C79A005B98ADB24ULL, 0xF722143E35F137E4ULL, 0x18533F5E1851B82BULL, 
            0xA792BBF5B5FAC4A1ULL, 0xAE87F58072DA226DULL, 0xAC32640C61725CBFULL, 0xE7B1D84EC61A3CC7ULL, 
            0x9FB523A09AC67E1BULL, 0xF9B1C02BE89F94C6ULL, 0x5B925FB7A1E844A9ULL, 0x8FF978315FC25CB3ULL, 
            0xAADD30285B386AA8ULL, 0x08936BA9C575FB68ULL, 0x539E82DD453904F9ULL, 0xBBF525AF4A7726FCULL, 
            0x9C5E4D4307D3540DULL, 0x8BB24AC81C69CC33ULL, 0xAC59158E54AD4576ULL, 0x197152831290B1D3ULL, 
            0x3084AE692E09D93FULL, 0x641CC82840C9DC51ULL, 0x55F431FEF645E128ULL, 0xAAB4596026B93B4FULL
        },
        {
            0x0D649F82E9AE7C48ULL, 0x703906C473F3D85BULL, 0xACCF722292FBBDE9ULL, 0x413678002E3CB23FULL, 
            0xB691AC00A07A5DFCULL, 0x884C9EC92B9D27DDULL, 0xB2C18DFCDD32C5B7ULL, 0xC860652E48DEC10EULL, 
            0x637C19C77C3695BDULL, 0xB7DD70C38B39F055ULL, 0x9B8DF473623E2C73ULL, 0xA97E6FD0C020051DULL, 
            0xC4ED3CA9E29E0BB4ULL, 0xCA0860D5AF167F0AULL, 0x4561045085DB635CULL, 0xB3030C8CA790B6E2ULL, 
            0x7E9B786E368016F3ULL, 0x24609167E81DEDF2ULL, 0x3DD9A7E66077732CULL, 0x6EC4AE0FFA8E219CULL, 
            0xD2D79527E07A1A21ULL, 0xFD5DD5C2022063C7ULL, 0x112C34BC783BD1B5ULL, 0x593B9790872E465BULL, 
            0x828996B85754F951ULL, 0x54C9DAED71228345ULL, 0xE6107F28EC573109ULL, 0xB368164AD6008401ULL, 
            0x8574AABD165957C1ULL, 0xEE87B8A3C258843FULL, 0x836161EE6E30C313ULL, 0xFF54A012FCDB1369ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseAConstants = {
    0x3B2D7A100B161535ULL,
    0x538B85F90BB36655ULL,
    0xE3ED39F1FDF3F081ULL,
    0x3B2D7A100B161535ULL,
    0x538B85F90BB36655ULL,
    0xE3ED39F1FDF3F081ULL,
    0x12BAE17EE76FCB5EULL,
    0x1C4B85B173A7600EULL,
    0x92,
    0x59,
    0xC1,
    0x85,
    0xAE,
    0xC5,
    0x28,
    0x6D
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseBSalts = {
    {
        {
            0x12DC8589888A107AULL, 0x75AC65A930144031ULL, 0x67786DDD884DD530ULL, 0x828E531002EBD634ULL, 
            0xED8322F9149E3F26ULL, 0xA82F7B002B199A82ULL, 0x640376CBBE73DE72ULL, 0xE22F5ED234E5B274ULL, 
            0xAAB069C95AE82B20ULL, 0x7EB4EBA37CFF1B53ULL, 0xA6A70EED4BAF574AULL, 0x421E52EC30A8C9D5ULL, 
            0x518574D9B0AF674DULL, 0x80791ABCD39829A6ULL, 0x913D20AE5AC581B3ULL, 0x041AB66FE7FB2361ULL, 
            0x6638E92146F2D651ULL, 0x5A341CDC2938D4F4ULL, 0x96FC4005047F3885ULL, 0x7649A8ECC3353994ULL, 
            0x1443FFA2A39A0A92ULL, 0xB853D050516EF374ULL, 0xB447D96BC0E41ABAULL, 0x9D12D8F5804608CFULL, 
            0x8ED7C0FAAAEBC3ECULL, 0x6157F84064B4EEF3ULL, 0xAE408016E304F81CULL, 0x5C0BDF32E2F9D34EULL, 
            0xBBD2FDAD92032EE1ULL, 0x18615D09309517EDULL, 0xE5685C5A71618AE9ULL, 0x7715A7C2F06B69E3ULL
        },
        {
            0x21EAA0A03A40EA10ULL, 0x6B8806E088AAB1B4ULL, 0x713969AA9FB3612BULL, 0x9CFC8076DC3220E2ULL, 
            0x8627C96F2F167D2BULL, 0xD8F9791CF84A6D64ULL, 0x76B9F0D6BAEC21FDULL, 0x22B40239964B53B3ULL, 
            0x277CD4C57B3C702DULL, 0xC9283CDB51184F55ULL, 0x3C21B564AA198D29ULL, 0x7C51B30B93544C1FULL, 
            0xA5EFD16BF8F4056FULL, 0xF3BCB341912A1E55ULL, 0x0567D1FB0DA56E9DULL, 0x6F80D4932F4851B5ULL, 
            0x74E3FAD4D56A0651ULL, 0x54635C6D982DB444ULL, 0x3C0E143701661C46ULL, 0xA25658CDD29CE86AULL, 
            0xE9310AF8B922F995ULL, 0xF23FF9D68C05397DULL, 0xC510A9EB6552D240ULL, 0xBA686A9D9AE186DFULL, 
            0x64F6307A85BD0F2FULL, 0x07FB36B4E94544DDULL, 0x69723380C55F5E88ULL, 0xCA82C24ABABD3D66ULL, 
            0x195A86A65DC24F71ULL, 0xE46B30DB33BB710FULL, 0x6839332035D892D2ULL, 0xDBEB6D1647859365ULL
        },
        {
            0x552D6B137D729D45ULL, 0xE774FA58D262DE4BULL, 0xAD9BFDC574E2E501ULL, 0xEF0019FD213B51C6ULL, 
            0x9EDE38A450D1CEACULL, 0xDBF1BCC15BAC3780ULL, 0xE267902850AA4546ULL, 0xE67A3970733CF376ULL, 
            0x07AF6D3EA5CF8771ULL, 0x1B1931D38995501BULL, 0x967B8BB65EC28C6BULL, 0x2AA5CFE7B7847FFAULL, 
            0xFE7E844DDBC6DD45ULL, 0x91ADA6F3C5490372ULL, 0x47D82E87FE41A1C4ULL, 0x0EA148B3005BECBAULL, 
            0x6586F52F40F9200CULL, 0x77572BA84428BFB9ULL, 0xA1AFDE90EEB7BA72ULL, 0xFD28D24EB22A238DULL, 
            0xED5549BDE4E26ECBULL, 0x72FD0661CA6AB840ULL, 0xDDF90F2605432C15ULL, 0x682B6C14C49BBE19ULL, 
            0x7FAD7B00F12689B8ULL, 0xBCB37A5241B691E0ULL, 0xD06B6BAE8B6A1950ULL, 0xE8FB1835B259C7D8ULL, 
            0xF40964DBA387B0D9ULL, 0xCA841727E85C6010ULL, 0x991F1E0F3E47AD15ULL, 0x5F149754EA4EBB09ULL
        },
        {
            0x74F0AAC6457DF4C4ULL, 0x23E98A9433857570ULL, 0xB2AE00983D35B2EFULL, 0x7130DCD8CD0E9413ULL, 
            0x28BFDF726EC7FE4EULL, 0x4579BBF74D5BE86BULL, 0x67A6F1423C91D442ULL, 0x62BC07CFA423A0DAULL, 
            0xA699CDB79901409FULL, 0xB7567129DE71E0AEULL, 0x0EDD52F79CFE5094ULL, 0x9505410A45500950ULL, 
            0x7B62F24A60DEB53CULL, 0x13724F0D693AD81CULL, 0x8127F6F6F1CC0720ULL, 0x70CB10CF78513655ULL, 
            0x6D8092CCDE76AAB6ULL, 0x7CDC39114FE5FB3FULL, 0x860331723D4908CEULL, 0x629A159DCCDAFDA8ULL, 
            0xADEE813D3BE73AFAULL, 0x301341BBDE1ED0DFULL, 0x4F6C2570F9F9C60BULL, 0x4A08394902F8005DULL, 
            0x88A71CD376F5C520ULL, 0x63327541915F7F33ULL, 0x869E139BAAD6DBEEULL, 0xBE4E346B93DCFB2CULL, 
            0x75EE720CCC8A87F0ULL, 0xCE3B5EE8EB74322AULL, 0xDDCB5B79500FA3FBULL, 0x9539127E724FFCB6ULL
        },
        {
            0x18DF5FF783F64FB3ULL, 0x31AD11660BECE407ULL, 0x86F09C0D26783A4BULL, 0x35708683F41B72E5ULL, 
            0x557302AED8338BE4ULL, 0xD09A7850904B024EULL, 0xEBF33AE8353239D8ULL, 0xE54AC80D38251791ULL, 
            0x0E12ED4EF0D5C50EULL, 0x6BF59E8D8F79F230ULL, 0x6452DDA3E7E15149ULL, 0x0471F9759249A9FFULL, 
            0xC042E43BC4029DAEULL, 0x0F98E3108BF9685CULL, 0x1E443FA8A4968B08ULL, 0x2B90B849926F5527ULL, 
            0xB5CF348E61129129ULL, 0xC5BD3E9B20D6B12BULL, 0xFDA0459CE2C5F86CULL, 0x16448C64E3F7179AULL, 
            0xA1A018B852D93055ULL, 0x8299CDAD9FD6A82BULL, 0x033E3C74CA08E48AULL, 0xFA6D4BA506B6F19AULL, 
            0x2C081BA9BDDE94BCULL, 0x5A7E538611F3F56EULL, 0x88F7CF8E82265A9AULL, 0x570216103DEC90EAULL, 
            0x0F3ACB25954227D1ULL, 0x256DEF514A8F2E3AULL, 0x054F02247666F800ULL, 0xFD2E8E5102F91564ULL
        },
        {
            0x2837134FD9136155ULL, 0x5144C909747498AEULL, 0xD957842FC526251AULL, 0xD83D170C8330708FULL, 
            0x41AEFE65BFE1F80AULL, 0xC95A826516081408ULL, 0xDAFF053B914CB2CDULL, 0x730A71379B65194BULL, 
            0xE6D3869B3FC7DE30ULL, 0x5DD0F73AA10E9C34ULL, 0x3DB0F1B4F6771A2CULL, 0x2D7BEE032462222AULL, 
            0x86E3A03566EE0A0CULL, 0x7BAEB6ADE93A593DULL, 0x1557C795C2C129E6ULL, 0x8CA0FEE72590BA70ULL, 
            0xD2B206B31374AA81ULL, 0xE0B9C6B664D3934AULL, 0x341B9EACAFBB1F5DULL, 0x728870D9263A89CFULL, 
            0x05AF9FCF5D59A0F2ULL, 0xE55611563987B123ULL, 0x18A65778CF8830E0ULL, 0xEA5B2C4A78310BE6ULL, 
            0x973C86DE2C69D321ULL, 0x78F48F9A2833C59BULL, 0x2F8118984B037ECCULL, 0x3795FA071628A32DULL, 
            0xD8D8BCB368C03711ULL, 0xEF2FE30AC9E0F0D9ULL, 0x186E55CAB7A182A9ULL, 0xD8D77BC52CBF0057ULL
        }
    },
    {
        {
            0x37982E11FACBB450ULL, 0x03BAD049E8E2CABEULL, 0x438B21ADFAEA0715ULL, 0xCF47DE37E703BEDBULL, 
            0x14BC7D44F86672D2ULL, 0xCD25B8AB6AE72C02ULL, 0x2ACED7AA83B6C8C5ULL, 0x35A30D6C14676538ULL, 
            0x2B2ADEE9AF8EAE7FULL, 0x517416714879E471ULL, 0xFCB4AB4BE4700FAAULL, 0x8536F32EB9BB6E8BULL, 
            0x91A7E9A9C1946F63ULL, 0x06D18A03D34268FDULL, 0xDBE2BF7F22B5B1A3ULL, 0xCC91E6BB8B312D54ULL, 
            0x7BC2884FD2E81AEEULL, 0x624BE7509F5B01DDULL, 0xB5737763389F7326ULL, 0xDC678139DFBE8BA0ULL, 
            0x20E626EB3225A62CULL, 0xB6C657CE63A8319EULL, 0x8D271BB9D650D7C6ULL, 0x263D6686D45011B5ULL, 
            0x1174721E1BFBB48DULL, 0x65F9BB5330A8C705ULL, 0x012C83B17E2E5685ULL, 0x0519A5D9545EBB8BULL, 
            0xC7FE3A55990122E9ULL, 0xC4A4C43C5001E803ULL, 0x78B575FBFF734C8EULL, 0xC163D8ABD7B58821ULL
        },
        {
            0x0DC477A211547B58ULL, 0x2C586F24C00EDBFCULL, 0x9A703BB0C5217394ULL, 0x6E6D7C3085D13AEEULL, 
            0xAEE95A11DAFF6EDCULL, 0x37677899DDA13E81ULL, 0x401A109D8CFA9B3BULL, 0xEDBD52C5CB65CD35ULL, 
            0x61ACEC6406459BFEULL, 0x5AB92B1956CCBA4BULL, 0xE0CAF1488E55058AULL, 0x5FAFFCD369D9B6AEULL, 
            0xB8A452C5B2CE1C65ULL, 0xFA77396496BF938CULL, 0x7FC9AE792C9B50ECULL, 0x54EDF59F6F6C7E5EULL, 
            0xB1DB9E846E10BA68ULL, 0xE1716A8F3237E4E7ULL, 0x1659EEB52B4762E9ULL, 0xD9D3A4C50E449CA4ULL, 
            0xF53D3D300FBA58D8ULL, 0xA5448D2DA67297F0ULL, 0xCC1DA57E101E4B3FULL, 0x1C51326429500575ULL, 
            0x53329586459FED8BULL, 0xD0C0CA852903C7E7ULL, 0x146E43ACA950DE99ULL, 0x3B3F31FD99A3ACA0ULL, 
            0x30B7FFE570733194ULL, 0xC8A27972F7F56DCAULL, 0x2739E431C7FD79B2ULL, 0x71A7F52A0F1B93CAULL
        },
        {
            0x317369F668C6D91AULL, 0xF31A512A5629CAF7ULL, 0x27394EDD1A33473BULL, 0x0EC354D429DE0DAFULL, 
            0x3513A7850A1C3815ULL, 0x0B694C973C6047AEULL, 0xF29668B392F531A4ULL, 0xFF269459E6871A2BULL, 
            0xC9240F7003C63DB1ULL, 0x74474C98A3DCA875ULL, 0xE6EB34748A6DAF95ULL, 0x26C76F6E2E1EC750ULL, 
            0x41CB5ECFB3ED079BULL, 0x9ED94F34EDCFF7F3ULL, 0x9C475B26397BFCD2ULL, 0xC231678FBD8279EEULL, 
            0xB7F1B312EB51A049ULL, 0xA1B461EFB92E9539ULL, 0x3CBB9488EE4E7903ULL, 0x7656791FDB8C2FA6ULL, 
            0xB9180268CE3F7AFDULL, 0xE38A95542D93FA4BULL, 0x6D0B39E55DC20648ULL, 0xBFA9A39A105E1D9BULL, 
            0x978EE2DD54A22ADAULL, 0xCDBF4B60B7D7987EULL, 0x58C9F3F53995E5E7ULL, 0xDDF50ADBFC6D2E33ULL, 
            0x6309E4B09675D1F2ULL, 0x1FF34EF5808CC49FULL, 0x4773986444281B8FULL, 0x6CD70D75F4F862C6ULL
        },
        {
            0x1A3C03A6D1993481ULL, 0x1A87A9346759B84CULL, 0x42C8372A8FA2D3F2ULL, 0x50A578CACB0F81E0ULL, 
            0xC26822370B982575ULL, 0xE2C8AAE34FE65EE3ULL, 0x9AC1CB0052068DD9ULL, 0x79936032799B3775ULL, 
            0xC06397F82474D1BDULL, 0x2A56BAA3D44DACB7ULL, 0xD6C303D9F88E6140ULL, 0x985A90E503299949ULL, 
            0x1801B7105EAF6B7EULL, 0x116B3185E5C92F02ULL, 0x72C464E5CAEAA603ULL, 0xE511F0976B1861B8ULL, 
            0x5A458EA01CCDED4FULL, 0xD5E456135433A104ULL, 0x08EFAB350EF76EC1ULL, 0x5C2F8668FAF19DC4ULL, 
            0x413E42B04B9AA0A7ULL, 0x55B5078F9681ED5CULL, 0x4063F1D85A641FB8ULL, 0xFA6559747AA0F78CULL, 
            0x17ED86464D840D3BULL, 0xE4A4A3815182740DULL, 0xC6F8D148FB0DC11AULL, 0x49A13A54B18EEB21ULL, 
            0x3604E71D45CB9081ULL, 0x0F640B026850A557ULL, 0x176E844ED31397F5ULL, 0x090F69E3772AF7ABULL
        },
        {
            0xA186AD68344AE1DDULL, 0xE0451FB945BFA542ULL, 0xCAF8AEF22603BE20ULL, 0x5FD46CA26C0DEEC8ULL, 
            0x1A27E60483A21A67ULL, 0x4A77136EEA08156AULL, 0xC7E138143D4A1E5AULL, 0xE77D417BB70B0151ULL, 
            0xC0A1D218E484E7B0ULL, 0x800AD778E00D5105ULL, 0x489707AD2079E1C0ULL, 0x0650998A338F1207ULL, 
            0x7EF06730061ABADBULL, 0x558FF2A5F8F71B28ULL, 0x5D7B33F0EE116102ULL, 0x1AD8AC1F5AB5C34FULL, 
            0x4535972B4A969284ULL, 0x1FCE4F5BB5EE860CULL, 0x782069A7C9660DB6ULL, 0x257A9E29C3E341B8ULL, 
            0x47A7F94BA5F6619DULL, 0x8BED0D7F0ED06AF8ULL, 0xD1307B7902CD6618ULL, 0x0F6F5E2AF6A03600ULL, 
            0xAAB46D47D0E3674DULL, 0x2469DA219B8BB620ULL, 0x3BD15CAEB21BAAE7ULL, 0x51EA4A5283F7C0DFULL, 
            0xA6C0000721C240F3ULL, 0xCBCBD0416A066E55ULL, 0x70DF3E9D57810C67ULL, 0xCB32CD777E4DB08AULL
        },
        {
            0xD16A235C7B626AE5ULL, 0x26F86FCF1FDDF0E5ULL, 0x84514FF9F841D3A5ULL, 0x50BFDC02081A0A38ULL, 
            0xB9D8629B68A4DC7AULL, 0x383D38566EC64E0DULL, 0x0C54709F40D15C1CULL, 0x568A6E29C02A8AD8ULL, 
            0xA64143C9C4E284D2ULL, 0x7A10E3BE1A8B9A6DULL, 0x0456928C1AD03571ULL, 0x642E690C97F604C7ULL, 
            0x7C5F9E8D97E578B8ULL, 0x9D0CEABD4E7E0629ULL, 0xC47068F2713BE39CULL, 0x583B7E8DF6DE6433ULL, 
            0x3FE83B1E9495D648ULL, 0x384C130564520673ULL, 0x632AB68180A33C6AULL, 0xE9E462F99D081189ULL, 
            0xCF636878202530BCULL, 0x530E51EAE4820B6AULL, 0xC09E7BA82C6E56AEULL, 0xE4AAA37B714F67DCULL, 
            0x5970DB98E3CA4B8EULL, 0x0EF49D3B19136E0DULL, 0x68C52DBB3DAC1114ULL, 0xE0329789594BF451ULL, 
            0x1F532EBD74CD058AULL, 0x17C6A0E6840A508DULL, 0xA4DE7D4CB0ADF23BULL, 0x7F00788054B7A0F7ULL
        }
    },
    {
        {
            0xB56E93B7D79C6337ULL, 0x2B5DF9505D4E0DADULL, 0xD9B8B552269DB6EDULL, 0xDAAE917303DCD282ULL, 
            0xD7CA68E68A7DC9A5ULL, 0x163BA3C036256752ULL, 0xF6C339FC7A1D5362ULL, 0x18E49E2BA1B93CE2ULL, 
            0xFA640B909AF85F4DULL, 0x9A390DC0D17421ADULL, 0xE4146A94DC363EC4ULL, 0x5EA90BF4AF5F0D69ULL, 
            0x17C391BA93BDEAD0ULL, 0x6A13C212F31EE16CULL, 0x834D6CFF18F6CC9FULL, 0x307A2CF1AA997FA3ULL, 
            0x3D92ABEA5F8F37DBULL, 0xB86B9785C19FE5D1ULL, 0x26FF270D0F92C29FULL, 0x6DCD7549CD0F5276ULL, 
            0x035628D97AD91B43ULL, 0xFC01372EA84B42F3ULL, 0x4F24B5F3D3CFA4B4ULL, 0x0EE245245530E42EULL, 
            0x2E5053DAF6A66CB0ULL, 0x077A5F53711FFD3AULL, 0x463EF07150260DA2ULL, 0x5A0C21A362DEF7BEULL, 
            0x1FE4CD75BABAD5F2ULL, 0x362FD130B842EAD1ULL, 0x9FDA4981ECA45D8EULL, 0x1406BE58448745E9ULL
        },
        {
            0x7E2F7F074F065015ULL, 0x2D8A77B22EFB92EEULL, 0x85599AE7392774CFULL, 0xC8B83F9C9E7FFFD7ULL, 
            0x8E7B6B3E15E37503ULL, 0xE5D4493C40799C70ULL, 0x91E699E09E4AE625ULL, 0x7E4A17411A816340ULL, 
            0x72B1236C7F5E3AABULL, 0x2C43B7141F486990ULL, 0xF78F08446CA3759EULL, 0x547D84F228BB6F85ULL, 
            0x2008A5AB358D57A7ULL, 0x9F236DE1737A8B2FULL, 0xA8B3A3C6850207A4ULL, 0xAC972C5CD9DB5F1AULL, 
            0x404D8D976EE50EF1ULL, 0xC6222E97B59D6255ULL, 0x1E8726D1DBA12F88ULL, 0x6A5A5DFC6BBE8812ULL, 
            0xA5835D114C9532B2ULL, 0x17F4388FA2BEEBD1ULL, 0xCEA0823A8480464CULL, 0x30301F061818AE1DULL, 
            0x25DBA79BFDD4547BULL, 0x2D86A1042606A9D9ULL, 0xC74728CFF62F6A6CULL, 0x01432AF4FFFD7B7CULL, 
            0xA26D7AAB5D3F650AULL, 0x1E672B7872824300ULL, 0x1C364E06409155B5ULL, 0x38635BD7F0967C92ULL
        },
        {
            0x7EB00C267AF359AFULL, 0x0D16FA8DC0964A3EULL, 0x851533934669A076ULL, 0xC9AB51BBE1465D6CULL, 
            0x89E39EB0CDF81324ULL, 0x41DA02A9E2C17AA7ULL, 0xE77DCAE9B98A9602ULL, 0xE28301982A88B4DFULL, 
            0xA8FFBCC4BE188656ULL, 0xBC79A8D633F08920ULL, 0x0061AC2D9551C96BULL, 0x05AD6F929ED9C07BULL, 
            0xAB7833A31A44E48EULL, 0xC225618AEA5C98C3ULL, 0xF9740A0E8B528477ULL, 0xD008B2982D254646ULL, 
            0x08EEBB3CD9BB4CC2ULL, 0xF467BA39F03B5EC6ULL, 0xB422138A1467F775ULL, 0xB88CFDEF3196BCD2ULL, 
            0xB208B6B53BED3C9FULL, 0xDDD4B463A97D7CE7ULL, 0xCF64916077D84C37ULL, 0xBE91B1949427B27DULL, 
            0x920145D0CC05B165ULL, 0x70828B02E365D5D0ULL, 0x686622E6956AC929ULL, 0x4D9636B041FB609BULL, 
            0x865C182026E817F0ULL, 0xA1A4722EAA262A33ULL, 0x542B6D54DDD80284ULL, 0xCC1DEAA0797E89F3ULL
        },
        {
            0xAB372EEAE1C1D8FDULL, 0x85B559B0D596A903ULL, 0xDF8C44C81AC096C0ULL, 0xF9D34AB4BEAF921DULL, 
            0x62E80167A1018EC8ULL, 0x5164082080B59BE1ULL, 0x77C29C1E78CAA053ULL, 0x995D76DE8EC53261ULL, 
            0x6DB1F22ADB012749ULL, 0xA02A25CD27C261E0ULL, 0x02111BA78F989291ULL, 0xE74DBBFD6C2AB46BULL, 
            0xC5519CDD3DE17623ULL, 0xEED03CCFAEB50566ULL, 0x4C5A20F9D97FA75BULL, 0x3D09B1026F064053ULL, 
            0x0E1B0254235F5C67ULL, 0x3971EB38F1B6786DULL, 0x200C1B1400C71031ULL, 0xE19F4F06CC425164ULL, 
            0x6B58EA20B547D8DCULL, 0x8B5DC9DD944CA30DULL, 0xF6AB960E62EE09D0ULL, 0x4A9F2AC3B53116A2ULL, 
            0x973A13292C9AC207ULL, 0x1D0B2F07D71A7D21ULL, 0xEBDCF9B77BB7E188ULL, 0x08656B9A82826592ULL, 
            0x57AB941BA10F7A99ULL, 0xBEEA6F2E15088759ULL, 0x381F0C2F0C5E4785ULL, 0xF988EA7E4F9A22C1ULL
        },
        {
            0xBABBF6C24508E100ULL, 0x2B00C5D02E18FC97ULL, 0x2DE5B50818EE2863ULL, 0x42C3D765DE4BA0BFULL, 
            0x5E8F3C1DBBA60C88ULL, 0x67A4C2F783CFFF3BULL, 0xB56DD8282984C9C3ULL, 0x54428F4528457979ULL, 
            0x02F49C6176947DBAULL, 0x2D9770959DD4D224ULL, 0x2328A86F8D17CCDCULL, 0x4CAE547AA5DD4EAFULL, 
            0x95EE5CEF0C12F876ULL, 0x33174F7F19B344FAULL, 0xB6F9C1A305F9856DULL, 0x832D6CCF2C01D10DULL, 
            0xA6C842032155C873ULL, 0x0B30A7EB1B4992B2ULL, 0x5BE561EE30D334C2ULL, 0xE937CD0963F4D6B8ULL, 
            0xCDF24E09B812BEDFULL, 0x7791EAAB3C62ED41ULL, 0x49D2593F27FF213EULL, 0xD9839854BD24EBFDULL, 
            0xA65FF8EBFA212768ULL, 0x73905A9C2F53751BULL, 0x282D3644D4C46B76ULL, 0x83B1D8CA4222F1A3ULL, 
            0xAC7BF81FBD16AECFULL, 0xF07AE46D8DBDC40DULL, 0x9BF4278CA95E9F00ULL, 0x2DA1FF24D17427EFULL
        },
        {
            0xCC415B2F95D20820ULL, 0x76F820946DA2DC40ULL, 0x59C7F64D7EF0A54CULL, 0x761078373D51351BULL, 
            0xEAD7E80362D747C2ULL, 0x61F96F97E5487730ULL, 0x2B475297F3670205ULL, 0xACF55C6C6AA97701ULL, 
            0x194CD5D96E381F10ULL, 0xB36BE6FFC6EEF4E0ULL, 0xBAFB1A9442EC6FC2ULL, 0x8B96B41C6E6E1B4BULL, 
            0x724B4B73E31CAB4EULL, 0xE2D8CBD599500D5EULL, 0xE7FD996DCD555787ULL, 0x19C54667243C352AULL, 
            0x9D366F7FC11C3417ULL, 0x5B61696EB971A5FCULL, 0x1EF18CD2690F31E3ULL, 0x6E0DD5CED08DDA4BULL, 
            0x2BD4FF21F3662A20ULL, 0x8F594ACC09CE6D0DULL, 0xCD47D4E7BBA845B3ULL, 0xF6B893CD426420F8ULL, 
            0x95DF96EA8A416195ULL, 0x6D3428D9D87543BFULL, 0xB1C251E43BD20024ULL, 0x9DCEF4DB489E79E7ULL, 
            0xBA4B2B7371116856ULL, 0x50ECD0D03DD76D19ULL, 0xBA12B727A4E0C19CULL, 0x839FB9DD96F014DCULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseBConstants = {
    0xC2C98CA820E8361AULL,
    0xFCBE3D3B71643A5FULL,
    0x38904E180A3B4DE4ULL,
    0xC2C98CA820E8361AULL,
    0xFCBE3D3B71643A5FULL,
    0x38904E180A3B4DE4ULL,
    0x005406341B3560E8ULL,
    0x33D8204F0A01D916ULL,
    0xA7,
    0xE5,
    0xF9,
    0x1D,
    0xB9,
    0x64,
    0x46,
    0xC1
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseCSalts = {
    {
        {
            0x3779C7D46DDA2D49ULL, 0x043D25620643FB14ULL, 0x728C4A732B85DB95ULL, 0x7B65D876CDD3F72CULL, 
            0x7BC0D8623FAA095AULL, 0xF69625A092852077ULL, 0xCAB5A3AE0B091080ULL, 0x87D39945929C6DDCULL, 
            0x7138520FAC854F69ULL, 0x23BF930A8CDD6287ULL, 0x2909266D76EB3399ULL, 0xFBF7FCF8C5581210ULL, 
            0xE94CD52BDF584CCDULL, 0x6AEEEADA56656EBBULL, 0xCF03219EE2CF8D54ULL, 0xE4D13DC154987418ULL, 
            0x9AE61024CB4A5F45ULL, 0x414199786A55B3B9ULL, 0xECB2579BBABDA082ULL, 0xA2F5ABE8A49E06EEULL, 
            0xB336AF6D04DD7FC6ULL, 0x3F0E65037EE461DDULL, 0x70AE6C5DDF85333EULL, 0x9251538AD6D76486ULL, 
            0x2E05DCFB44E1AF96ULL, 0xA6E80060816B837DULL, 0x1BBE9B25D5126300ULL, 0xE05372449BEE59E4ULL, 
            0x1DBCC965431CC3D0ULL, 0x3B5EA617860028FBULL, 0xB0365464D13FB778ULL, 0x5CAFE6EBC93BAB37ULL
        },
        {
            0xEE3A7AD7C599A348ULL, 0x57AAF0551EF94657ULL, 0x2FBD2F7E088521D4ULL, 0xD37DE23CCE9F5CA9ULL, 
            0x26354EAC3B185033ULL, 0xE6A85BF5324B4B5CULL, 0x53BC2009E42ABCC7ULL, 0xC8C5340E5F58DCDCULL, 
            0xBEB106D5A139D93FULL, 0x6AFF7C6C552CC659ULL, 0x79AA0E6180CA3BC7ULL, 0xDE9C4232B1DA2C52ULL, 
            0xE03D054371B37E5AULL, 0xC5F9759B264270CEULL, 0x4B3B7F7D668AB3B8ULL, 0xF06088E6EFF2BEA3ULL, 
            0x949C90EF71B14FA6ULL, 0xFA673182A9A117F2ULL, 0x515E0616CAAC93B5ULL, 0x3069C8B7FCBBF1B6ULL, 
            0xDBA25CB7529A929AULL, 0x9CE776A6724D1769ULL, 0x5E6B4F7C40A5C355ULL, 0x035A0EA8F4AC09D7ULL, 
            0x2B494D620A384321ULL, 0xC2A883C1520C5DB3ULL, 0x091419F134D0D4A5ULL, 0x3C2B5D0A9360F6A9ULL, 
            0xA750089924FD432FULL, 0xC3D537DFBB9F4F23ULL, 0xE821EFF7C36FAB00ULL, 0xFC968974DDBDAFCEULL
        },
        {
            0xC4AC14DFE9654C1EULL, 0x119DAEA7944B2A63ULL, 0x3306B4698B05372CULL, 0x444A5F18A07A1973ULL, 
            0xD5403CDA4DB244DBULL, 0xEACB7ABE3A055AFAULL, 0xB76412668A3C724AULL, 0xE0E9CE7A042B85E2ULL, 
            0x1B4C7879C086B017ULL, 0x291C6E2E709C7CD4ULL, 0x79C8D48112CF6668ULL, 0x9541279CE14C70BCULL, 
            0x1BEF4DEF08EC229EULL, 0xDDF5CB9FB93B9E97ULL, 0xC63B11F493AAF342ULL, 0x2FCE7E0A5728A15DULL, 
            0xB0A674BD66B52A47ULL, 0x1CC028E933517203ULL, 0x5460F7444449A650ULL, 0x82541A70D1EF1BD6ULL, 
            0x2D48BE6F30ECEC2AULL, 0x393067B642434C4BULL, 0x9DE2A637E2EF6222ULL, 0x761A44C9C2B660FDULL, 
            0x94E575C4C39C3979ULL, 0x9106D2DB863EA9BFULL, 0x61A1EB985AE7F9FCULL, 0x00C04B83FBD5FAAFULL, 
            0x6B5B671277D56EA2ULL, 0x696961A274496252ULL, 0x17F5DAC75C270DC0ULL, 0x726B14FA536692E9ULL
        },
        {
            0x51C6E943566EA54CULL, 0xF44E0D592F2161CEULL, 0x5C48B5FA78D9E358ULL, 0xF571FFD7D0F7521DULL, 
            0xE557BAFFA870FE10ULL, 0x1CEE8B14380BAD80ULL, 0x8844ABE622B014E5ULL, 0xB42FE0A5635DFF5EULL, 
            0xE0A6398FB7F45E62ULL, 0x0C9C7215F828180CULL, 0x895C6A7C061C50E0ULL, 0x26555669E77A7D98ULL, 
            0x66F2A89BCCE3008BULL, 0x57CC3F16C13ED276ULL, 0x13EB5C92A66128BBULL, 0x0679AD9453C1E41CULL, 
            0xA5155E613797B079ULL, 0x1191A68B4430FB71ULL, 0x1F940C81C4D3503AULL, 0x39DF52CA9DCFFEB2ULL, 
            0x73C6199A5A13096CULL, 0x7A0E66ABAA8C8B5BULL, 0x0B4C4B8C19D6E5B2ULL, 0xE72CABCC02852279ULL, 
            0xEC926819C728356CULL, 0xBC777EEC880F7DB3ULL, 0xDCC070A74202576DULL, 0xA6BBA96E112B39F8ULL, 
            0xFAF22B8543C62091ULL, 0x5FC3AD2ED99855B8ULL, 0xA491B1BCC725AC42ULL, 0x301DA6C358CCD0D3ULL
        },
        {
            0x68043E13BC282203ULL, 0x2BDE8403BF132B9BULL, 0x2E5AF5D8E969A5FAULL, 0x7D92E6C13CD03FDBULL, 
            0x9F0439E15E9A866AULL, 0xA39E7A54039A4B8FULL, 0x05BD8C9F258E77C7ULL, 0xEB5ED5ADDB68722AULL, 
            0x8B18D5E6E5DFA869ULL, 0xC198F93CC0484BE8ULL, 0x3A7466891A8B2897ULL, 0x503326F51C632BF1ULL, 
            0x9E064C747927EA69ULL, 0xF8B345FCCA3829BBULL, 0xE9CF9E3228C50CC5ULL, 0xC9CC97EA3D3C635CULL, 
            0x5F262F937FC7A8D7ULL, 0x4BA0A05C74692B04ULL, 0x2AE763D8E2D5201AULL, 0x05886AA3333F2E10ULL, 
            0xBE57215DD9A13DADULL, 0xF4D48D5BEA68071FULL, 0xDBD7B27467C0FF9FULL, 0xC94FF3B287B9442EULL, 
            0x06E98EF4FBA07A5DULL, 0x9C73DD2E312DEB44ULL, 0xA4EE5CA1F616A858ULL, 0xA9ABB2267D979C96ULL, 
            0x804AE8F8DB9A0CEFULL, 0xA72BF134DEC1A72BULL, 0xC7E337E15DB26516ULL, 0xDC1DF0859D6EA136ULL
        },
        {
            0xFF317ED50A9F138AULL, 0xC411B9C592F8225FULL, 0x9D7A8BAA3E4432FCULL, 0x8CA6153BA4121D7AULL, 
            0x33FAD1A0063A02C6ULL, 0x053FF181BB9B5F7BULL, 0xEC587A002C35E63FULL, 0x5A4D2A0601E2B112ULL, 
            0xA36A0A37BFBA706CULL, 0xFA3AE4DA420B5150ULL, 0x1360464E55B94215ULL, 0x502E6A3F5556EA78ULL, 
            0x08F7666580332644ULL, 0x4C8C8B0E692F9222ULL, 0x8B52F7AD67BF7170ULL, 0x6381E02239DBD0B1ULL, 
            0xADD095F885BB298BULL, 0x98E24198378A4103ULL, 0x7A0FD4B90953038AULL, 0x78D2A16A144EE71EULL, 
            0x4718AA1967574B62ULL, 0x711EFB2D8CCDD291ULL, 0x1E373ED16533B4CDULL, 0x74816E942E2ED30EULL, 
            0xD87A83F6CBCA58BFULL, 0x453A7BD190711172ULL, 0xE9F615339FD73B9EULL, 0x81B31C7B98D5B8DEULL, 
            0x548F946247D80FEDULL, 0xC543A9402A4785FCULL, 0x84A0FFC46969F6FBULL, 0xF278B955D1D5215CULL
        }
    },
    {
        {
            0x58CF187CD5089A8EULL, 0x082C3020A99B0927ULL, 0xDDF2730B64C65731ULL, 0x326B0DEB5F57BF33ULL, 
            0xCDB619DBF576114FULL, 0xC966856DFED784CDULL, 0x5240CB2402ED376CULL, 0xF84C0EDF21DC6433ULL, 
            0x0F0E27710F706F4BULL, 0x60AB5252477A3A39ULL, 0x7927053888CFA4DEULL, 0x88EBFC1205C7A964ULL, 
            0xAD7EF743BF69414EULL, 0xF18A630A1B028F1EULL, 0x5C3ECD47BCEF22D0ULL, 0xB685392A469D7665ULL, 
            0x64F9B0AF344F31EFULL, 0xFCDD7490903E81C4ULL, 0xE66AFF89A3A5F322ULL, 0xD17FA25EC8293A6AULL, 
            0x6FFDE73D58008612ULL, 0x3EFC178C17A53F87ULL, 0x1B1FE8B367425947ULL, 0xBD2D2169282D4BA7ULL, 
            0xB724EAD89D2C1EECULL, 0x24EAF843B32EED1BULL, 0xC2A30E72B5CF322EULL, 0x6AB257E8438707D1ULL, 
            0x41CA59453F254D86ULL, 0xE940847C7DFD1CD8ULL, 0x66D60597A3F2EA91ULL, 0x998C42F2912BF1E2ULL
        },
        {
            0xDBA71AD30A93335EULL, 0x8772A123E61F7858ULL, 0x80EFC1B48BF2E6DBULL, 0xCCF1619441889E06ULL, 
            0x54D03C92FDED3FF0ULL, 0xC028A74AD6AC9CB2ULL, 0x77CBB9CFB59906CCULL, 0xB862679EB150E72FULL, 
            0x7A2ED4DE06029D36ULL, 0x67524D9F6537A5B0ULL, 0xEFB839A634C94EC3ULL, 0x730C457901B4FBDAULL, 
            0xD86378EF5E5FF028ULL, 0x20C9E7FB87B8A211ULL, 0xF92E102ADC1EFD0CULL, 0x9EC5DD0AEFEE8923ULL, 
            0xDA7399A22692C440ULL, 0xB6D9348EDB2F26D8ULL, 0x57C1B4D2A5071D6EULL, 0x309ABBC3CFD5758DULL, 
            0xA6926E747101F078ULL, 0xA46713C7808AD251ULL, 0xC0B97A5E8126D952ULL, 0x123BC4D56BEF1E70ULL, 
            0x017F48BF4AC6227EULL, 0x12D9D06417423A0EULL, 0x0C99DF8870FC7FA6ULL, 0xA8B8085DBE19636FULL, 
            0x01BEE26313EB3A3FULL, 0xFB7505EB047A4E2CULL, 0x6E7C55D7022293C5ULL, 0xF6DDCFAE53F15884ULL
        },
        {
            0xE928B6DD3146C84EULL, 0x1917F601E98BFDF8ULL, 0x5EC1830AEF24566FULL, 0x4F5C476B9D4B7120ULL, 
            0x5AA6CDE76A87CF48ULL, 0x54B75907A17AE8A3ULL, 0xE238C14AB1402CA9ULL, 0x76A3C8DF0D97AE76ULL, 
            0x5D91E2E6D3A0B571ULL, 0x6FC89CDACA4A65C2ULL, 0xBD8106B9E7BE567AULL, 0x6279624DB8AD787DULL, 
            0x01B0F65C66B2E5DCULL, 0xA35915630DA40BE5ULL, 0xE8C33F58284F0D69ULL, 0xC1AE3BCE5FC35D49ULL, 
            0xD6F7D56A0C693B6EULL, 0xD2F7FF96E2F443E3ULL, 0x3C5A748DF7B9342DULL, 0xFF1059EE83C55BAAULL, 
            0x0F200F2311216790ULL, 0x3F3EBC6515FA3EF0ULL, 0x0DFD7A6746C546E2ULL, 0x4B78E4B2C223B63FULL, 
            0xD0D518263EC07723ULL, 0xF16A962F449149C2ULL, 0xBB3F9D4BCD7A6DC9ULL, 0xDF520BF03EF16B67ULL, 
            0x4F1B47234992D49CULL, 0xB61DF2A113E5B8E2ULL, 0xC790A945B9BCF35FULL, 0xDE34D4F534F62F4DULL
        },
        {
            0xC585E04E7E149A4FULL, 0xDD60835ED8A13055ULL, 0xB39D36C21EF111F2ULL, 0x59C0CA2BB596DF7EULL, 
            0xFEFAD53132ECD8F6ULL, 0xDDBB56F4CB7CC51DULL, 0x15C20B26754EC1C7ULL, 0x61AFFAE278564C4EULL, 
            0xD26014B138691AF7ULL, 0xFBB024B4A1D4D84AULL, 0x4D0870B4797B6CA5ULL, 0x885D8BE703AB66D9ULL, 
            0x124DD78D43197F02ULL, 0xE24AE8FE0C4994BEULL, 0xEC9001BB3FA7939AULL, 0x1BE268AA457D0049ULL, 
            0x91EE9C8FB60CE71FULL, 0x5BF41B6D11DA8B43ULL, 0xD0BC73F7E70BE108ULL, 0xC8230D1AC9E1AD4DULL, 
            0xBC2C98D77D83881EULL, 0x2242D38FBAFB7A64ULL, 0xD555CF530D99EECDULL, 0xFB26D230197B2725ULL, 
            0x210FFF35EE179B60ULL, 0x1AA47C252AE3E423ULL, 0xE9AEFD6393EBE333ULL, 0x4A74F10D762D69ACULL, 
            0x2B0672F46123940FULL, 0xEBDEDD82E42BF648ULL, 0xD23C6D813A1FFCE2ULL, 0xCF213F8C2C75CC4BULL
        },
        {
            0x17CD17DD81CE8AD1ULL, 0xA94D0904CA3AF898ULL, 0xF9B782AC59C8B27DULL, 0xF866EBB2E0CB6756ULL, 
            0xB649D1A93389CA49ULL, 0x603425C55FE78F60ULL, 0x034C156BFA3A9048ULL, 0x0528DA6DBDFB4657ULL, 
            0xBBD2617D426BCE6AULL, 0x4D81AEDA4B074D54ULL, 0xD9B27F61D368888CULL, 0xF82B50AA971D3A38ULL, 
            0x449FDC407BA8441BULL, 0x61722191AD45B938ULL, 0xBAB210D2D0E873E3ULL, 0xAAC8B4AB50461A35ULL, 
            0x3B2BCCB2ABDC0090ULL, 0x3BCFF58A4783DC2AULL, 0x3768F5E217B77CD4ULL, 0xC36A8BE02B3EC437ULL, 
            0x217590347A30C43CULL, 0xF73508DD71570F8BULL, 0x9B864DA4E73797F8ULL, 0x4BA38D7B47E60A24ULL, 
            0x2F03BC0CCD1D64ECULL, 0x25B17C37CD6B6396ULL, 0xC074E9BA3BFD2834ULL, 0x57D2317BED349D0EULL, 
            0x7681DF41CCDEB018ULL, 0x1333B7A2ACD2A67CULL, 0x92A223439FA0E257ULL, 0xC15CB753ED5FC115ULL
        },
        {
            0xFB78F638D3209818ULL, 0x6E001FE4FC0F1896ULL, 0xF8DDB7684A9A4C46ULL, 0xFA41EC5C5335D9B2ULL, 
            0x1BB3187397262D12ULL, 0x99752BC544E7EA99ULL, 0x08B1F243903F3E55ULL, 0xCB8DEBB6CD20FA94ULL, 
            0xD92101E492F51519ULL, 0x7D0818B9D13296ECULL, 0xF5B1DE4716821F9EULL, 0xB4131B70EC1A4E11ULL, 
            0x816C973642E7B6C0ULL, 0x297021E2FE06F513ULL, 0x8388F8E1658ABA0AULL, 0xC200FA0C192B3473ULL, 
            0xC138FEDEF18FDE5AULL, 0xBA5B2E98C5AC41B6ULL, 0x65CD1206CA6945E0ULL, 0xAFD9010E104D4FB9ULL, 
            0xAD55403AAB4E86B5ULL, 0x1CBDDD743230216EULL, 0x7B6420C3C3EFC48EULL, 0x0965BBBF10D81AD3ULL, 
            0x1B5DA9AFF929AC03ULL, 0xCCC9CF21E22C022EULL, 0xAF48DD6545B9F5CBULL, 0x81CA61CCEAE23E52ULL, 
            0x19B90101C093B724ULL, 0x3309F8135B4CD5CFULL, 0x87B20CB0BD369748ULL, 0xA2AD615AA6626F91ULL
        }
    },
    {
        {
            0xE76FD0BA37111BCBULL, 0xE811E2BE6B956C6CULL, 0x973E579E8D326EB1ULL, 0x6DFC62D4EEDA4317ULL, 
            0xE53E1A1D5C17EE07ULL, 0x01AE6860BCEE6BADULL, 0x4FFCC5C003A0B989ULL, 0x8593F4897767C95AULL, 
            0xBA8353D7FB0DA12AULL, 0xF64AC88B41ECE5D1ULL, 0x203DE41F064F36A0ULL, 0x6B3335DB81B203D2ULL, 
            0x269B387F20D19A7DULL, 0xEAA4D70B047A3670ULL, 0xFED97CC665CD036BULL, 0x0B84A6C76DB91678ULL, 
            0xC7A77EF6A1552FD2ULL, 0x5F1E0BF2A9224A22ULL, 0xAF7FA72B63FAC914ULL, 0x74EFD33AE5C9AE5BULL, 
            0x1DB2E1083DC59130ULL, 0xA6BAE9DB245A759DULL, 0x952F77EF9FFCFE1DULL, 0x5C67B82368B2BF5FULL, 
            0x919B4680D20CCCB1ULL, 0x2CE7BAFA6DAD29ECULL, 0x3F1C2B2B7A195B17ULL, 0x5E172D3291913E2FULL, 
            0x8F31F25C43BBE5E5ULL, 0x80FAD20F057C2260ULL, 0x468921F39F1C3E80ULL, 0x42AE6CA073636CB5ULL
        },
        {
            0x55C7F4EDEB307B47ULL, 0x1ED35005BE4DF4A6ULL, 0x7B2233FA18FE811CULL, 0xCE565809C6A9C826ULL, 
            0x031146B932D4AE0FULL, 0x3BFF0804912B5B8EULL, 0xA8BFCCBB4845CCB1ULL, 0xC32BDBB16939B53BULL, 
            0x4EF0BB8A0A6C026DULL, 0x3784F15D7756668DULL, 0xE4E6EEF0A5CD8194ULL, 0x2AD5AF511AB1D27BULL, 
            0xBE94C612DA0787D1ULL, 0x3C9FDDF25D131E52ULL, 0xD821EA0DFEE97EF6ULL, 0xB99396A26BCC1291ULL, 
            0x4CC17BD8656EA12BULL, 0x4DC3D8FA2C93F7CAULL, 0xB12BCC9B07493E72ULL, 0xF77744EEE9A1A573ULL, 
            0xB8C88F971C5DAEF6ULL, 0xC6D009EC42BE84A7ULL, 0xC807EC4D8A930B84ULL, 0x30D12E555C10E80BULL, 
            0xC795AFE7FB5BEAEEULL, 0xA3DA2B139409D1AFULL, 0xBC38D525995AF43AULL, 0xFC4CC142EA5913ADULL, 
            0x63D41B428EBC446AULL, 0x4317B3520A97F98FULL, 0xC4EE3770C0481E72ULL, 0xA957A5889D871F14ULL
        },
        {
            0x027C60AE854AF091ULL, 0xCC93009C7A15A1EEULL, 0x361037AF68FE7F8AULL, 0x7E67B18A294D5581ULL, 
            0x96752BCAD28AC2E7ULL, 0x0386AC44315E57B1ULL, 0xE87054A084C0CA9BULL, 0xFB44371B2536F86AULL, 
            0xA68DCAF94579B4DBULL, 0x05C3133CB26F1DD7ULL, 0x776769706ED4B8C1ULL, 0x1BDB88EE227E65D0ULL, 
            0xA0922139F10F7658ULL, 0x694F083BF396C960ULL, 0x369E4065944D4CBEULL, 0x8734898004A4DA70ULL, 
            0xDB20E3C959F4E56DULL, 0xF4068037BD26A340ULL, 0x4B755A12C4E3EE41ULL, 0x64E1A7D273CAB855ULL, 
            0xFC361B69EDEB9A74ULL, 0xC0BE1197C9B57514ULL, 0x7CE98D5F3423EAA2ULL, 0xDDE249FFAD2EB1C3ULL, 
            0x04C36258C363A9BDULL, 0xA26BEE9F33D4FA58ULL, 0xB4E554F97643AEA3ULL, 0x727B54327F62D59EULL, 
            0xDE0C6BCD7DB88ECBULL, 0xC3E5894A26924025ULL, 0xE67BC75E97040AA3ULL, 0x283CF0B2273D5597ULL
        },
        {
            0xDF6B74BD3EA1FBE0ULL, 0x1CDD8AE9900B5649ULL, 0xF82166F69B0B67B5ULL, 0xD487D09FAA0AC835ULL, 
            0xA4A14D23C461A7E5ULL, 0x84E89ACD38A8C5B3ULL, 0x54D39BCDC479FB62ULL, 0xDAE54FFE235FA79DULL, 
            0x8A7B67954EBFD20EULL, 0xC9982A0CE73E1720ULL, 0x3097FFDBA0DEA760ULL, 0xB2D2EF28910CE961ULL, 
            0x64E1BD006C841516ULL, 0xBB89358932D66E5EULL, 0xFFD0E7D5629FEC0AULL, 0x2994CE31CC7E517FULL, 
            0x7825027D62B8598DULL, 0xD78DDE177D8A315CULL, 0xB669160382DB5CA9ULL, 0x7359CF04CEC4E061ULL, 
            0xB2F0BB9F444A54BDULL, 0xD3DF6057AF934716ULL, 0xFA661493B6106932ULL, 0xFC80F5FCF0427A8AULL, 
            0xC775F29ED719E179ULL, 0x051A5C2C665838B4ULL, 0xBE55D93E240DB5C5ULL, 0x3F9D6A8787E99479ULL, 
            0x3614AC890C6D2714ULL, 0x07E49184912974C7ULL, 0x8F2CA6432F27F951ULL, 0xE9DCB1110467CFA0ULL
        },
        {
            0xCEEF29698B63014EULL, 0x6260129E4599B7CBULL, 0xE87B9A1ADAF8AF89ULL, 0xCB379FD5BD501E49ULL, 
            0xB2BB2F3F9D3AE35EULL, 0x175F8121FE47E985ULL, 0xFC7255E0E6513A5FULL, 0x941F118557FD314EULL, 
            0x0897E499FEA0E191ULL, 0xC1BF61F99A4B0CCBULL, 0xBDE8FB67E5DB49BCULL, 0x8F7C7DDC7F485C6DULL, 
            0xD679FB09C8FCEE55ULL, 0x3DB1B544C2044030ULL, 0xD7971E3C43B8024EULL, 0x467CF2A3B52525B1ULL, 
            0xAD2AD7B71A851EFBULL, 0x91D43E723C28BAAEULL, 0xBFD040920D9BCDFBULL, 0xE495E55DAA013A05ULL, 
            0x0F051A74FB0358B1ULL, 0xBC3E3C1A7EA6A104ULL, 0x390EF542A86967F4ULL, 0xED14A1411D02DDE0ULL, 
            0xBCF78223980F2F24ULL, 0x76572E78A4E69BA7ULL, 0x0D7611091251E607ULL, 0x18B3BF2822EC5CEDULL, 
            0x223FABE91A2172D0ULL, 0xD1A887A29286C7EAULL, 0xB1CB5DCFD4FF01CCULL, 0xA7292D0F6C55E101ULL
        },
        {
            0xFEF59D87E05E97B9ULL, 0x93B59D6AD9844B88ULL, 0x0170D6233856E48FULL, 0x669659E48844B0C7ULL, 
            0x6F3D0EAB18D93160ULL, 0x08A1119AD6302C30ULL, 0xABB6B203C51E5993ULL, 0x3F2E970B46FD1CEAULL, 
            0x5D5AE86F818A1BF1ULL, 0x0947C11883298F19ULL, 0x4F4D795A919522DCULL, 0xFEA1C20E56C14F9DULL, 
            0x41F93351C9319BA8ULL, 0xB09F61859DE396CCULL, 0x5C4D76B11BEBFBA0ULL, 0xE120491C41D38428ULL, 
            0xBF0BBBA875B13586ULL, 0x7FE917FCB78A205DULL, 0x63FD3E5BCABB29CEULL, 0x3B090F66FDDC81D9ULL, 
            0x830DA5C52CE7B834ULL, 0xC7AE6CF1B65DE1A7ULL, 0x6813CEA5C4B276BBULL, 0x2FA6A1B6CA649AA3ULL, 
            0x1A9F3C7B0ECC41B2ULL, 0xB2C8C6A797B4172AULL, 0x4DA9615FD35B3C77ULL, 0x85761A2B03994088ULL, 
            0x97422B30CC50329BULL, 0xCAEC203701C434CFULL, 0xA37079D350ECC402ULL, 0x5F24A9422465EF6FULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseCConstants = {
    0xB13A466D10C76BA4ULL,
    0x9DC7B728641B0159ULL,
    0x1B7CA30E9B0DD70DULL,
    0xB13A466D10C76BA4ULL,
    0x9DC7B728641B0159ULL,
    0x1B7CA30E9B0DD70DULL,
    0x714C3E388E5D1D20ULL,
    0x9495B876D68B6D43ULL,
    0x09,
    0x02,
    0xE8,
    0xB9,
    0x01,
    0x14,
    0xE9,
    0xD6
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseDSalts = {
    {
        {
            0x1940BF3015BFC56EULL, 0x2EE975BB523188F3ULL, 0x652FAB15D98FF3CCULL, 0x78B9AA5B25A02CB6ULL, 
            0xA783AF57A48E77C5ULL, 0x2F05356787E70962ULL, 0xE5D84268954BA013ULL, 0x3B6F1F2B222E35C2ULL, 
            0xD3B6A580F93CEA28ULL, 0x790131277F450369ULL, 0xEFEB5522CA5D5A3AULL, 0x22AE56658B1DDC73ULL, 
            0x9C757F755D6A1EECULL, 0xFB16CA7B77B17A4EULL, 0x06EDFFDD0D47DFE9ULL, 0x41C7CEAEEDD3C815ULL, 
            0xFC56A30E0670937CULL, 0xBA65DE4B19AF4D5DULL, 0xCCD2A677645FF98DULL, 0x37CBFE0238B62B63ULL, 
            0x5341A9CB33C792F3ULL, 0x02DE86D3A4A6C112ULL, 0x0F184AB42A766000ULL, 0xD777283C0879416DULL, 
            0xA02C4205E06F4662ULL, 0x2A1E915CF239FC2FULL, 0xF554B80C63BA2CAAULL, 0x6864DC97E8A656C1ULL, 
            0x1F641C2B2694F252ULL, 0xF2D148A76519B606ULL, 0x1DB55403B290143CULL, 0x4425ECB67324D27FULL
        },
        {
            0xEB552399D2914F70ULL, 0xAF872ACAC8C0820FULL, 0xFB53117D5695A7AEULL, 0x3EB83DE3E2FF3707ULL, 
            0xEBF3F10B513F7F7CULL, 0x41D9DD9D8DCBB539ULL, 0xCA508D31F67B673CULL, 0x0EB51096E78E7D53ULL, 
            0x1562CE9A3AAE6C3FULL, 0x5AFE12DDEEB2FD39ULL, 0x52462351C369D252ULL, 0xD5CE6EA9970E5D42ULL, 
            0xCF2E2846E748AE9EULL, 0x713DE5303C71D780ULL, 0x1DF2F6155B011308ULL, 0x17266768BAD28956ULL, 
            0xF2CEFE0D764076D6ULL, 0x85A277B43D267C7DULL, 0x0B2BBADD8C24B428ULL, 0x1CE5F6C5D93D8ECCULL, 
            0xC9BCDE426C8796E5ULL, 0x0ECF0FDF78240EB1ULL, 0x3E17EE48AF52F0DEULL, 0x9FC4237F442BEDBCULL, 
            0xA48AC4394A584D41ULL, 0xA14ACBDD3D8D9580ULL, 0x9AD2AAB167A929D1ULL, 0x6B11878B01E55FD4ULL, 
            0xECFF368C5CC89A5AULL, 0x05214FE834E3A83FULL, 0x3D0F2FAA629F123FULL, 0x2649A8AD0D27A009ULL
        },
        {
            0x1BAF9061065CBC39ULL, 0x0FF6C55573F0B5CDULL, 0x18C1C6A68C8363C2ULL, 0x9DAB8563D2B9F916ULL, 
            0x22985B631521443DULL, 0x8F3B1558709BB46AULL, 0x89D24ADF4B473C10ULL, 0xAF9969633FA38574ULL, 
            0x92AE1ED76F701FECULL, 0xF9CEBD5F1FB7E619ULL, 0xD56DBCB0EE953E18ULL, 0x73DD989E4A64FD3AULL, 
            0x40BB698C49004DE4ULL, 0xD37AF69E987C6235ULL, 0xCBF0A782F5268B7CULL, 0x340DD8F96B8EBC09ULL, 
            0x1244A9178D99FE3FULL, 0x9977DE376223DB5FULL, 0xC8A305627CBC5550ULL, 0x20BFCAFEE80363C8ULL, 
            0xF419A61AA2D22726ULL, 0x3B98B3E2408C53C7ULL, 0x3E3C3D1B2DC7671FULL, 0x7DC56A71F604E300ULL, 
            0x8CDD0BA005A28E62ULL, 0xA9AAC875D2ED34EFULL, 0x6B2464FD9A87866DULL, 0x2ED61076AACAE4E1ULL, 
            0xC98FF728688D5A0EULL, 0x51397A02A39412D5ULL, 0x8D31C609769541D7ULL, 0x5E3A0ECC27573C65ULL
        },
        {
            0x985DA301ECACF53CULL, 0xED3A513F22834D34ULL, 0xB68A27BE67036DCEULL, 0xB3721572A4D583B4ULL, 
            0xA67A0D0D87B1960EULL, 0x6071CD2739AC1ABAULL, 0x7C5C5D20AA39B53BULL, 0x270F79D7E4AD4D2AULL, 
            0x89AF2AADF0561F19ULL, 0xE2B59F969D1BC255ULL, 0x9A318EB159FD2EACULL, 0x0C15728324292F93ULL, 
            0x87698E611B5E199EULL, 0x0750E807F68DD928ULL, 0xE3FC53E748CA06E2ULL, 0x3A46CA2F7A2AC89CULL, 
            0xEDEEB4F95DA2CE7EULL, 0x3E39520152AA21AEULL, 0x68D5BA669B0FC934ULL, 0xD55521AA32388189ULL, 
            0x0D551D5E694983FDULL, 0x02F5467CF5B5BABEULL, 0x8FB330BCCCFAD89DULL, 0x7DD486D44E7E0042ULL, 
            0xF2E41A64CFA87B82ULL, 0x97A1D16FEE9ACCB2ULL, 0x0C1C676847FCF3F1ULL, 0xBE575C9A8CD828D1ULL, 
            0x491C0E577B2BC133ULL, 0x1EBAF52A234A0B36ULL, 0x2583E0702EB4A95CULL, 0xFF98212C4C88A436ULL
        },
        {
            0x0E3AAA4AE82ADF50ULL, 0x8AE896566ED6A910ULL, 0x7CDEC2A5FB3E63BDULL, 0x01F7B04905AE10FDULL, 
            0x3240C1BC374F9066ULL, 0xD35B53A2E2150176ULL, 0xB4DFA4589568757DULL, 0x81F14441111A1035ULL, 
            0x25E52D70918979FDULL, 0xF8936A87A7BDA122ULL, 0xA4B24F084E8787AEULL, 0x1B1848F30286FEBAULL, 
            0x18DB2361A9A37EA5ULL, 0xDFAF021AC8CA59F9ULL, 0x455F065DBB050583ULL, 0x42E6A6D889609E85ULL, 
            0xC8C697839897601CULL, 0xFFA218ED2F733395ULL, 0xE313950B03B8A176ULL, 0x17EB387C727AFFCDULL, 
            0x5ED8EDA543FA7DE4ULL, 0x16BD52D28DEF97BFULL, 0xBDAD5CD6BA4EF828ULL, 0xE8D6F40425103566ULL, 
            0x792FA13AB2190538ULL, 0x1831A02F245B4498ULL, 0xC0060351C9B08357ULL, 0xC987CAA1B310C608ULL, 
            0x376C65B3D04DF1F1ULL, 0xB6C58CD4EF3D9552ULL, 0x91AF04D68522A563ULL, 0x27B464CEF9A164DAULL
        },
        {
            0xB13026316F1A94E3ULL, 0xE4F8FC21B9D030BCULL, 0x16C19731BF5E5ECDULL, 0x715F136AED1C4FB1ULL, 
            0xE04208A6FFEF4097ULL, 0xA891D80E36E1DB13ULL, 0x0F8B0DE56C5338BDULL, 0xBA9CA65214AAF83EULL, 
            0xE64255FA6E0E6831ULL, 0xF418CCB0562566D4ULL, 0xF3723813D55C7E07ULL, 0x306F68EF7F673AFEULL, 
            0x0AC73EDA53A19835ULL, 0x55E5007DE0E029CDULL, 0xF9F8D27F3CC67EC8ULL, 0x99158B2A5E06F2C2ULL, 
            0x0849E53886B46F3DULL, 0xCDB13B03B7382A55ULL, 0xAA5098B0341FE1FCULL, 0xCED0797BF037101DULL, 
            0xEE690823696288CDULL, 0x716800B2E4860008ULL, 0x7CF557BC1A784E3CULL, 0xA8034033E51C0B69ULL, 
            0x906C2CFF952C7F0CULL, 0xF25A814D0BAFD79AULL, 0xCDED0C398839E3D0ULL, 0x038DFF760B7C76BCULL, 
            0xD5DAC169866516ADULL, 0x5281A6D70443841FULL, 0x4C274F98B8C69F7AULL, 0x5EA4E36982B72215ULL
        }
    },
    {
        {
            0x1B8420546C8B242BULL, 0x05FEE148738CA067ULL, 0x4892DC2541C1E83BULL, 0xED7C934009C6D253ULL, 
            0x2F1CAAC1013BAB46ULL, 0xCD85B7B13BFAE2E7ULL, 0x6988998F9DCDF595ULL, 0x4A3C084DB647045DULL, 
            0xFB60544302FDE507ULL, 0xE4B8531668D0144FULL, 0xE54C7B22ACBF2208ULL, 0x75037E368C693E31ULL, 
            0x2EB92A9E1B1BF2A6ULL, 0x33C37C7732647D55ULL, 0x7E2F1C490BC32675ULL, 0xCBF7F80F73D8B87CULL, 
            0x1A77EF71F08960EEULL, 0x79044A8BC2BB60B3ULL, 0xA0FFAB0A038EF1FFULL, 0x1EC68E1AB6D55D83ULL, 
            0xAC1789B4C86E5FA4ULL, 0xE597DF9813D582D5ULL, 0xB3869BD9EB4AE52BULL, 0xBDD124932F25B42FULL, 
            0x59BEF390A858B078ULL, 0xCDA9A677EA670707ULL, 0x64338959D7FB300CULL, 0x2879BAEEEEB9FE30ULL, 
            0x295CEC12FDC80C50ULL, 0xFC903FBAFBD9D539ULL, 0xA600E234B16EEEA1ULL, 0x8DCDA379C93139FEULL
        },
        {
            0xF3E471CD3B693BB7ULL, 0x44A74664CE11AA93ULL, 0x46747B4CC1DBA3B6ULL, 0xF4662793D49DF4E9ULL, 
            0x1A58506EBA3B4845ULL, 0xEE4C5DA9C702B181ULL, 0x6005F94FAD941DC2ULL, 0x7F2892DD5B1D967AULL, 
            0x9EB419B10DCE50AFULL, 0xD60F8C1EECAE02C9ULL, 0x960B6EE403A23792ULL, 0x6C41B89B2E73016CULL, 
            0xD831DD4F7CB81048ULL, 0x303D177268729425ULL, 0x38ABB7D031B57F10ULL, 0x2BD1AD5C5804D9A9ULL, 
            0x09B5C576D8A9CDD8ULL, 0x8B7BAE8D5392A52AULL, 0x2D3117B8D5A44336ULL, 0xF390F088C3607D6BULL, 
            0x5EB1ECCAB19204CFULL, 0x852F7AD36400B65AULL, 0x078F5C8F2DECE38AULL, 0x993AFF2BA2A84842ULL, 
            0x2C02F2E2C00E9F6AULL, 0xA2CA202A8225D188ULL, 0x91CCC83E5ED52E81ULL, 0x2B5E94C0869CAB44ULL, 
            0x40CFA03DDDB438BAULL, 0x8FF0F3BD05359409ULL, 0x6F38E5D7CBC19B44ULL, 0x2A719536D844DB42ULL
        },
        {
            0x2F854DD2814C5089ULL, 0xFD4FE64BEE12E4DBULL, 0xCEE26D27A8267E61ULL, 0xD0F6C50CD8E3D4D5ULL, 
            0xC4AFFC2D5CE5167EULL, 0x2457097A8E93B2DEULL, 0xE1880E6579E2C7BCULL, 0x9E4D7194F3D66681ULL, 
            0xE86ECE907F647F35ULL, 0xCD88E79675B0EA1EULL, 0x4D05815F962ABE30ULL, 0x77D38C61D3D9EDDCULL, 
            0xFD511809FC3B23D5ULL, 0xDCC71668B430AE2AULL, 0x0AA863E75B330A5AULL, 0x905F3DE7773E4D28ULL, 
            0xD6FB7A92B9918871ULL, 0xEE4D83E5959B836AULL, 0x0750D18F7B94E1EEULL, 0x3D2A792CC9DF0E2FULL, 
            0x720FB34B339054E7ULL, 0x260C4EABC448284CULL, 0x010192AAA988E16EULL, 0xF5B83A5BE833595EULL, 
            0x411CB81E8E790263ULL, 0x24705858A829828CULL, 0xED37FBD657BF038EULL, 0xB0D0E9C0A9F3985CULL, 
            0xF4CFBF0BC450479AULL, 0x0149092782352DA3ULL, 0x4EB4F2FAF3148F8FULL, 0xADC621EEE50AFD74ULL
        },
        {
            0x92B95AB4590CD0FFULL, 0x6A1D7EE3C5E6A9B7ULL, 0xD17F09ECB2415522ULL, 0x161EF84A64BF6A1BULL, 
            0xEB19C6537EE4F951ULL, 0x5C326AF3B178B8ACULL, 0xD5D083E6FCE1D7A2ULL, 0x9D3CD697E71126D8ULL, 
            0x94A5F0E13FE98AE4ULL, 0xBDD9B1DAD7EF4760ULL, 0x42263FC73D0A1DDDULL, 0x6BCE1C730A04EE81ULL, 
            0x3C168F604C708549ULL, 0x74566B9F658869E6ULL, 0xAF8E1DE7C1854A15ULL, 0x85B940395D351493ULL, 
            0xD72D0F126940DBE8ULL, 0x8E53958619758D4FULL, 0x16A23996AB3163FCULL, 0xE3AEFD9E47C33C26ULL, 
            0x4C23175247C34F79ULL, 0xEA32548B602A321EULL, 0x493D8C67A2F51BAFULL, 0xC9E26E440DECE644ULL, 
            0xB5F3E4278D08F588ULL, 0x5D227FEF245913E0ULL, 0xDC977AF026B2AB50ULL, 0xB5ACFABDDD4612DDULL, 
            0xAE309866CBDC3896ULL, 0xBAC4D3D3E2FBA844ULL, 0x619C15CBE40F4DECULL, 0x93DA3F1C8C1A2EC2ULL
        },
        {
            0x071CD01EAAA56643ULL, 0xE830528156E4EE95ULL, 0x1D9BEEA57AA24577ULL, 0xE3A33A25F15815B8ULL, 
            0xD52C43114AD87586ULL, 0xCFD338BAFBA84704ULL, 0xECD6BA385581EA2BULL, 0xECD87D1B4995C963ULL, 
            0x1BEFC49F8E917F36ULL, 0x34F9A37C42476148ULL, 0x37753AB0D5CFD888ULL, 0x99EBB7B825176909ULL, 
            0x7F2A3AF03F9CBF3DULL, 0x863FDE087B1E88EEULL, 0x7C15E8A8E4A349A3ULL, 0xBA38448C3C9B5229ULL, 
            0x4EEA683711E7B42FULL, 0x927033FDD04DF55AULL, 0x00647FC83BC69FA2ULL, 0x01DD00108411A50CULL, 
            0xCB8B16F5CAE0007FULL, 0x3909D421397577BDULL, 0x1F7F93A78654AE95ULL, 0xBA6DC638F16E3DA8ULL, 
            0xD7B89035194BE8DEULL, 0x97E96046925EF3B7ULL, 0x635E7EA9FD5F7AD5ULL, 0x9E5A4A04323FA2A3ULL, 
            0x4740AE0A12D7ECDAULL, 0x8616F391180706AEULL, 0x38C54A16434CD496ULL, 0xC96C84EC42C4047EULL
        },
        {
            0xE2ADFCF6B964E534ULL, 0xF375B8D7A5C8AAF2ULL, 0x108AFDD626508998ULL, 0x0FDC25243C70A622ULL, 
            0x7218CF938C61F09CULL, 0x2B6EA2585A7E28C3ULL, 0x58DEB488E741F447ULL, 0xB6D0BFCC3E420F80ULL, 
            0x8470A03621B6A002ULL, 0x5BAA82C3DEA398B7ULL, 0xC22181805562E52AULL, 0x8E868DA941BA6540ULL, 
            0x0270C9BDC4F7FA6DULL, 0x4CA297180BD4C691ULL, 0x8B91D573D6348949ULL, 0x99E211245FAC6CD8ULL, 
            0xE8C928A92B48BA73ULL, 0x741A9689903E719DULL, 0x2E8EAB40ABE76F33ULL, 0xE40BDD242EEFEC3FULL, 
            0x406EB8F8180405B0ULL, 0x34957C1EB7221A74ULL, 0xF30FC8B64002A474ULL, 0x7661E7A0E8516C49ULL, 
            0xD542CB32DDA835DAULL, 0x2D914B359BF5F69CULL, 0x1B79846CE59CEA6CULL, 0x11180FA55A2D0C1AULL, 
            0x4C8BE3C699FE0CD3ULL, 0x0FF4375FD05064EAULL, 0xEA9784A5BEF4A7ECULL, 0xC6439EEB1600AF0DULL
        }
    },
    {
        {
            0x41E8774FF474446CULL, 0xDF98218275F8E7ADULL, 0xAE8B3CB2116E0F3AULL, 0x098B689E5A0FD946ULL, 
            0x4FECC1A227941C6AULL, 0xC516695742AD02A6ULL, 0xAD156CBFDCADC551ULL, 0xEC9A56263F2BD773ULL, 
            0x37BA16D6365B20C7ULL, 0x4AC26B73B16976D4ULL, 0x18B411992A63CA22ULL, 0x6CBF327702CCF134ULL, 
            0xE1F75C0B8F83E3F0ULL, 0xC9963C51F664711EULL, 0xE15EE910B0381304ULL, 0xAFE64EA2FD3E346FULL, 
            0x939F908D799BDA41ULL, 0x1B59F763872B8872ULL, 0x69010B9DA735CBF1ULL, 0xA8E8B71230541CB7ULL, 
            0x6218D47D022A649FULL, 0x539CCECC3BA3E5BBULL, 0x77A054F084427D70ULL, 0x8B1DEF44CCB03431ULL, 
            0x14B685D2AA898185ULL, 0xC73A90A7E1348D28ULL, 0x132855FE26C847C0ULL, 0x6389E8C58B582B28ULL, 
            0xDDB00DDF9FE38D65ULL, 0x32FD99305FC24FE9ULL, 0xBEE641B0ADC41B5EULL, 0xAEC77CC59C7FB284ULL
        },
        {
            0xF1B14A535492B537ULL, 0x7F5F316A4DEA8009ULL, 0x6D8164EE188C85C6ULL, 0x723082AE01C64C30ULL, 
            0x788CF1F62DAE5FF6ULL, 0x5DBB44A5C7EB0FF3ULL, 0x537933926CD2B086ULL, 0xFFAD22BBB43713A5ULL, 
            0x95CFEE2D02B5E85FULL, 0xB9B628CF3610B006ULL, 0x50D7B3EBF3B1B03FULL, 0xEA0EEB42DABA68B2ULL, 
            0xA07FA1FD39C10F8AULL, 0x99E2FEDACB8F4B47ULL, 0xF4C3CB8AF3AADEBEULL, 0x4B36C81BAAA65F43ULL, 
            0x32C03E567EDC2323ULL, 0x9C4F1CDC808430F6ULL, 0x044AAAE448A1F907ULL, 0xDAF7E9F54E51BAACULL, 
            0x7A36025BE09A92D6ULL, 0x147A2330A3B96FD4ULL, 0x8746D82931DBCD30ULL, 0x2F1BC3DD8F926056ULL, 
            0xCA3EB4C3D71E4ACDULL, 0xC4A9A950A0D967BBULL, 0xB7698B0F500BDCDAULL, 0x0CD9087F250866FDULL, 
            0x4F09DEF4A0F93F21ULL, 0x5CB1CF1302E25568ULL, 0x9BD33F1BC2DE4456ULL, 0x0BB9E0D3DC52F66EULL
        },
        {
            0x2E2C1AA85C8F91A2ULL, 0x5941B2E1FC831328ULL, 0xC24A5B84140F5868ULL, 0x4C93ECAF4E56CA92ULL, 
            0x5AE956E8DADCBE61ULL, 0xBAD9EADA40F53A1BULL, 0xB446DFA0886B8216ULL, 0xDF83ECECC3A00771ULL, 
            0xEFD858574B8C0A08ULL, 0x10C2955A34621023ULL, 0xA46F641E0C69F389ULL, 0x6B41EAAA876AB407ULL, 
            0x716D3A3FDA7FACECULL, 0xEE02FF9098B42F98ULL, 0x1AD76AFAE298CDD8ULL, 0xF2AF53E5B76526EBULL, 
            0x5CB92C29E3276DAAULL, 0x5567B589D760CE57ULL, 0x047136E5308499A0ULL, 0xB585B852B745995BULL, 
            0x54DFC38FECEE4D66ULL, 0x298D56A5A1B6D884ULL, 0xC09B457EF31FAC0CULL, 0xFA76CA51FDFB3121ULL, 
            0x871AC4B6EB8D7392ULL, 0x5D5FA64748AD7C13ULL, 0x3131BFF8C505C599ULL, 0x31A45139565007CBULL, 
            0x4A5520EC28CC0290ULL, 0xC269119F27227881ULL, 0x6A81D59DF15B4006ULL, 0xC3E672D7059EE00FULL
        },
        {
            0x8AB971D0F8A0AA59ULL, 0x679AF1B5DD50CE30ULL, 0xA3876004306A6219ULL, 0xD8566B16F96D6C8AULL, 
            0xF5EDF30F92B7F587ULL, 0x7CD7404DA6A7A750ULL, 0x185B1FA98B99D51FULL, 0xF484AC3C188845A4ULL, 
            0x09DA99B580445CAAULL, 0xD0E60FC30F2D7C92ULL, 0xC619F71E64B1CA31ULL, 0x166BF474CEE7BB82ULL, 
            0x0DC94508042097A9ULL, 0x8DDC7DE2D9A80524ULL, 0xDC89999E6C0B65ECULL, 0x71B3B9BB089A1EF3ULL, 
            0x2CF7B756D070BB92ULL, 0x9149CD87B24457A3ULL, 0xBB91BE28FFD4CEADULL, 0x8E4CB14D0CE27F58ULL, 
            0x11E84B00EBEA6D33ULL, 0x91504F5990EBCDBAULL, 0xE53ADDB2E0586192ULL, 0x390B1A5FDBBD9E31ULL, 
            0xEE303B3DE4CCB408ULL, 0xF643C06CCBC72F84ULL, 0x011957AAD268D931ULL, 0xA38180A15E76F607ULL, 
            0x35282D6B3994BB70ULL, 0x05F6F1028C423E16ULL, 0x39D82E8929A85E27ULL, 0xCBF2A91CE7FB4076ULL
        },
        {
            0x1606FCF8F83DA66BULL, 0xB00AF051CCF9FC5CULL, 0x82721F2CB9418859ULL, 0x362A9677CA1F31AAULL, 
            0x0285FF8FED3790F7ULL, 0x06B904463AD1BD41ULL, 0x6744BAE9D5C2B4B6ULL, 0x04D98987FA5A123CULL, 
            0x74DE9562182B954DULL, 0x7ECC8DAB18F9967BULL, 0x81EEB38DDB5743B6ULL, 0x46C01AD9AFE29E0EULL, 
            0x3D5174936BE742F0ULL, 0x480436D22080465EULL, 0x7BB5E93096DB6EAFULL, 0x65E9C7C4305C1FA0ULL, 
            0xE746CF34A6F76922ULL, 0x317A9D734D13BD88ULL, 0x8C3DA0E250DB25D2ULL, 0x90D911AA68779375ULL, 
            0x3B3C1AA60FD60613ULL, 0x571F14A9DD4FA845ULL, 0xB0EBD8855E5CD6BBULL, 0x64E54BC6566B269DULL, 
            0x7ADCB7A2860D3785ULL, 0x96FC96BAB126FA1EULL, 0xD6FE440FCF185B07ULL, 0x315C01CC22A81686ULL, 
            0xBDBE676DC5A314A5ULL, 0xF9ED12FB96B386DBULL, 0x06E2C14CCA5D2D85ULL, 0x40C4F23FFCAA85C3ULL
        },
        {
            0x3486893F36D012B6ULL, 0x678E1356A829A31AULL, 0xADCABE2F61D17864ULL, 0x7B46D6516E96437DULL, 
            0x38771948946298C0ULL, 0x9A067DD5354270A1ULL, 0xD8E5E809F5D9D431ULL, 0x2EB53CAF6D5508DBULL, 
            0x1886C9B9B4D0AC4CULL, 0x9371B37122A7C2ACULL, 0xE003CD580AAA0CF4ULL, 0xA4B915B273AF956FULL, 
            0xF03EFEED92C2E6CEULL, 0xB218F13A9D69B1D4ULL, 0x245DA7A1E00A8533ULL, 0x92BD039D1CC17E48ULL, 
            0x3854B9E5897BF43FULL, 0xF9157C98A3890608ULL, 0x976C5420A4A4E3C1ULL, 0xCBA5982DFA2980ECULL, 
            0x2E73563CEE7DC03EULL, 0x9F62B2999F243F4DULL, 0xBF39E2834A3598F5ULL, 0x99402F5972E6E9B8ULL, 
            0xC326FDEECD38DB29ULL, 0xF6A21311C934A9E8ULL, 0xAFF9A68072A7823CULL, 0x2DC524B3C2719986ULL, 
            0x26F0808DE4C6E012ULL, 0xE0E0271C1DBDEEF0ULL, 0xADF379DA72B58E6CULL, 0xD488B6FFB6572BEAULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseDConstants = {
    0xCDE05A251285C96DULL,
    0x15B8BC777CAE7A84ULL,
    0xD8C6F6018B18AF4AULL,
    0xCDE05A251285C96DULL,
    0x15B8BC777CAE7A84ULL,
    0xD8C6F6018B18AF4AULL,
    0xAAAD68CBE1AF2788ULL,
    0x49817A051BAED21FULL,
    0xA9,
    0x26,
    0xDD,
    0x8C,
    0xE7,
    0xD9,
    0x05,
    0xAE
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseESalts = {
    {
        {
            0x3CFB940B555B2105ULL, 0x0797E5042FB51DE4ULL, 0xEB853FE54E24C55FULL, 0x90D404AFD44293B5ULL, 
            0x41146FFDC9FA658BULL, 0x5947E38AFCA90010ULL, 0xD84BB6A9BF6C1458ULL, 0x91E7538BB2E7D11CULL, 
            0xC5A124E7D872BE68ULL, 0x598DB2EFADCC5BDBULL, 0x1ED6F72AF03A8617ULL, 0x2C30F6479189D075ULL, 
            0x8C5AE106F5F530F3ULL, 0x1ADDCCF9DD4FC9EBULL, 0x9DD4EEAD2CF2E8D6ULL, 0x8ED226AFDE93AE1AULL, 
            0x457A5D3783B7580EULL, 0xCF3EA7D567DFEA62ULL, 0x425809DCCD521194ULL, 0x42C792FAC8F9491EULL, 
            0x973644E70CE244E4ULL, 0xD1A34E111A655311ULL, 0x1C3C341932E7918FULL, 0x5E3CCB905E369002ULL, 
            0xE281E1B453C18A90ULL, 0xFC3A2404F41725CAULL, 0xE4CBFFE5C588A579ULL, 0x37D7FE480CEB85D7ULL, 
            0x7830929475E105F5ULL, 0xD243526C9368B6AFULL, 0xC458A1AA822624B9ULL, 0xA21C013E094BF07CULL
        },
        {
            0x18FBD81B9859D3D1ULL, 0x11E64C3D373AE415ULL, 0x7B123ABD4CC05FF8ULL, 0x742814DA651355E1ULL, 
            0x3C90C98493D2EDFBULL, 0xC508CF76D980C7A7ULL, 0x5E6666AC19579B98ULL, 0x0CBE6D9E23B36530ULL, 
            0xDDC57B8F79FA7198ULL, 0xB06EB0E41E3BAC21ULL, 0x1587B40CCFFD3D72ULL, 0x8F63B78C4E3DA5FDULL, 
            0x683245977A58C743ULL, 0xEAEB7F4CB39BC891ULL, 0xEC7EC92A74947CF9ULL, 0x68228745B896DD30ULL, 
            0xEF02B14F6A6BB18BULL, 0xA6D21AEA6924E4D3ULL, 0xDDE603D01322E6FFULL, 0x7C0DBE9E6029F840ULL, 
            0x8E0781F634F4764DULL, 0xF22AE1DAE2AB7478ULL, 0x6B9D5FC4FF64DDF2ULL, 0xB569B07063F54774ULL, 
            0x8FC4E2136AE05226ULL, 0x57BBF099EE5B8D7CULL, 0xEAE7E23DACE261E8ULL, 0x18B6259905E73298ULL, 
            0x8A712A0C5F40943BULL, 0xC843C0A4AF30696FULL, 0x16E762C5905B0BC1ULL, 0xC550B111095022F8ULL
        },
        {
            0xA8A55EC92D02554AULL, 0xE241BD2D4A813CFCULL, 0x7678BA243CE6BF67ULL, 0x50BB926D609741F6ULL, 
            0x89251A86E52F105BULL, 0x37886A6D6AB0FD84ULL, 0xD5F5937CB3A7C881ULL, 0x90E0A9C4FEAD481AULL, 
            0x7FEF8AAF853EF0DBULL, 0xF3AE4A7CDEBEDCFDULL, 0xA8C4F22D35201E86ULL, 0x44BE2144B4DB7BE3ULL, 
            0xD1452CCD67BDA795ULL, 0x65DC665770C3C819ULL, 0x785AD80FCE7AC5E6ULL, 0x4429C27251A238C0ULL, 
            0xE6B09D0E695C3EC1ULL, 0xB8F752D9E48FC4B0ULL, 0x75BD22DD3EDEF228ULL, 0x802546E3C9BBC158ULL, 
            0x4C82B6302B7F1DB0ULL, 0x30180F39B67EB5AAULL, 0x14B3DA7CE2680DC9ULL, 0x808056031C6F0E60ULL, 
            0xF2196EA5325F0068ULL, 0xEED7B2AF243A90E5ULL, 0x4361D5F4CB5497C9ULL, 0x24B3FDD613EA56E1ULL, 
            0xAACEA2E259F9369EULL, 0x15536AC2C407B1A4ULL, 0x6330871BD6C48D6FULL, 0xB622CAAE3AB1841FULL
        },
        {
            0x41DFC9EA09D5DA4AULL, 0x4EB4778474215C32ULL, 0xF9529C5A273F71E3ULL, 0xE6EE425BFB401690ULL, 
            0xB6FC80E5460128F6ULL, 0x1CB8131DCFE396C3ULL, 0x2DC5AE80F876CC88ULL, 0x4CDBB0D2AD75A8B6ULL, 
            0xE09F8DF18F8D339DULL, 0x891153B886DA33A6ULL, 0x014727AAACF64FA9ULL, 0xDA1867365CC4AD21ULL, 
            0x4E817C75FFE5BFA5ULL, 0xF76E1283E7C27441ULL, 0xAFBB1FBED7868A5CULL, 0x6EB89E59E89047CDULL, 
            0x412921EA7DE5FD47ULL, 0x44AC2128EE9F95DDULL, 0xC8DA50989C599E09ULL, 0x0B0FAE1B1C9B5895ULL, 
            0x099B0031606C3EBDULL, 0xDB5838EB9CE2A919ULL, 0x7D340FCE9367930BULL, 0x0EFD27A3299529D7ULL, 
            0xEC65AA645A6F1167ULL, 0x9F86DEFDB1672BD7ULL, 0xB4B2D25025407083ULL, 0x35D03F3BFCB98691ULL, 
            0x36D4B27390F4B928ULL, 0xB98EAFA50E0A2C19ULL, 0xCBA4FA9225038A21ULL, 0xE885D24DBE057CC1ULL
        },
        {
            0xA6D928A73A65DCEBULL, 0xCC771549116BD7C9ULL, 0x786F0171F1E6A246ULL, 0xEDCCC281EF46F7EAULL, 
            0xC806B708DC84D1B8ULL, 0xE94BE0C1714DC574ULL, 0xAC6C12E11B177C68ULL, 0xD98B89219286A3EAULL, 
            0xFA4C2A2DAAE3F95FULL, 0x38F0EA01906FCCB2ULL, 0xCEF33654B7634915ULL, 0xB0DD58A9574812DFULL, 
            0x732FD0A986D56AB2ULL, 0x89F03C733CD0805AULL, 0xE3AFE1B4D03E08C4ULL, 0x478E3F8F60BBE662ULL, 
            0x14524D346FD6012FULL, 0x306A1A784C234658ULL, 0xDAA0D7B0459A8255ULL, 0x6D07B6EB7F143AC6ULL, 
            0xC8FFDCC44DFBECB3ULL, 0xA7B594F918C705BBULL, 0x1DE185DBA506A737ULL, 0xB1B553616D50944BULL, 
            0xCE0EBDBD3467B2C1ULL, 0x53EBCDBDD4C28E72ULL, 0xB48D2222571DAEF3ULL, 0xF4856D19BC2CE757ULL, 
            0x4DC070451947129BULL, 0xC8F8338299F38C7AULL, 0xB8F9D0ED5BAD103BULL, 0x3AC0FF0934F0258AULL
        },
        {
            0x7575B919B8C2AFFCULL, 0xD484AA7F41013DB8ULL, 0xEBFA56A2B980043EULL, 0xC2A0E21CA7BB3E03ULL, 
            0x662A5D6452B07CA4ULL, 0x022A15B062787DC0ULL, 0x805675495F4F54F6ULL, 0xF91B8EADE7DE7830ULL, 
            0xE39BDC361989F49DULL, 0xC68D7F30C66748E4ULL, 0xE4788F2A670E584FULL, 0x2AB2DA83D58D0334ULL, 
            0xD7BC2B6E3CF1CFD3ULL, 0x031E08F2B591F115ULL, 0x393F472E3B915806ULL, 0x56C0623E8AE6147CULL, 
            0x95E41CC91C9AD1CAULL, 0x318B424587F53090ULL, 0x440CD5E3D732DF1FULL, 0x7E62CC0780D5FE66ULL, 
            0xA37192AEE326BA99ULL, 0x9C60D76CD8CACCE9ULL, 0xA72BD605CF2D5B33ULL, 0xB3732602EB356653ULL, 
            0x79C9A58C8DC92D9AULL, 0x5216B4A007B8AA82ULL, 0x4238E6B2612BCFD3ULL, 0x0DD55448367C42DEULL, 
            0xF5907DC538B8C66AULL, 0x74CA5CA91E4076A9ULL, 0x24E27E5CC54D5567ULL, 0x5934BB6BE2C0D5FDULL
        }
    },
    {
        {
            0x794BDDAA97AA1CF6ULL, 0x01F065261F9BDFB0ULL, 0xBAB74E07CE374E28ULL, 0x96F96ED33C82E349ULL, 
            0x7468FC128FC50B85ULL, 0x6815DA543B699372ULL, 0x579F77E6699A6CADULL, 0x3F734A30604000D7ULL, 
            0x4A6BBDE843812B81ULL, 0xB73C7DD1C04DC845ULL, 0xAB3516E54C1AF5EEULL, 0x35B5362C27D7EAFFULL, 
            0x41554E3266F31EDDULL, 0xC8E9707EA8F6A646ULL, 0x135E1CFF551757EBULL, 0x737AA8557DB20E7DULL, 
            0xB50C43BA67DD2220ULL, 0x615115E2B62306E0ULL, 0x877B54F3897C7252ULL, 0x5D11A1F7EE0C6D27ULL, 
            0x9ED3BD01527DBC0CULL, 0x4231BCEFB0733D8EULL, 0x65F6E606189546BDULL, 0x02E5FB7E6F4F67DFULL, 
            0x46F1A168D0F11F08ULL, 0x19D3E1E219CD2158ULL, 0x4766C6CA640DAE11ULL, 0x89745D301874601CULL, 
            0x55B807C783A37BF7ULL, 0xB3F7C3266254553DULL, 0xCDD4638B07EA0E72ULL, 0x285A9E80E63D4111ULL
        },
        {
            0xAF98DD0027572BACULL, 0x4313D7ED46BC0D6CULL, 0x50B6701FC84D063CULL, 0xB30A8D95CCB0976EULL, 
            0x5146CD7E7B37B2CBULL, 0x160F516FD200C509ULL, 0xA46066E3F0DA22C6ULL, 0x1F62BBA802169CCAULL, 
            0x3E859DD8E9AF4084ULL, 0xA54B07B8B36EDDE3ULL, 0xF40A2399611F75A3ULL, 0x5E07E684524CB062ULL, 
            0x6CF7C27FE1D1DD3AULL, 0x436F7A78F6E4E892ULL, 0x598AC5EF023A2A6CULL, 0x2696D4FB27B1D202ULL, 
            0xD70BC464D5BE536CULL, 0x6437815199761CEAULL, 0xA5898FE48CC6F021ULL, 0xE20161FA27F637B1ULL, 
            0xEFF9123CADC573B0ULL, 0xF24A0358427808E0ULL, 0x0ED1C512AD04430CULL, 0x38E3A401BF7DF095ULL, 
            0xE5DF4DDF74150206ULL, 0xE6DC3F962D96CE03ULL, 0x9C1C5D27675C1C32ULL, 0xB14DF3F9284947C5ULL, 
            0xFA7DFD9D2EE27D16ULL, 0xF0BD39BB83607914ULL, 0x20A673DBD518FAA0ULL, 0x70782BDEB24F0E23ULL
        },
        {
            0x26CCCB133DD0049BULL, 0xE801A74532DA043AULL, 0xB0F5D96C17ECB099ULL, 0xF9434E1C30B9CC2FULL, 
            0x1367E092699C3F19ULL, 0x0324FA7929517354ULL, 0x631FE40DFBFC9162ULL, 0xD95F61216B90E53BULL, 
            0x3B7B69523729FACCULL, 0x76176FC7C79C4BF1ULL, 0x8B8C8FE4C006A088ULL, 0x53371B9C0C610608ULL, 
            0xB709B7149216636AULL, 0xA9D749A06B28A54AULL, 0xA18D1FEA0FDBF0F5ULL, 0x2FB736BAA0E8EF4DULL, 
            0x993DB53663BC37A6ULL, 0x5C995E654171B7B3ULL, 0x5B7355266D78160AULL, 0x0193A671A16680BDULL, 
            0x1A15FFCB4C8779A2ULL, 0xE3392FE1687EC7A1ULL, 0xB5EB263D8CFCC88FULL, 0x1C1394A5E704B6ABULL, 
            0x6CBBB0870EEA2230ULL, 0x0D5282606B7579CAULL, 0xDFBE4AD5159B6071ULL, 0x13B28015C5082056ULL, 
            0xACD0A5956DED39B8ULL, 0x4EB48A3C83D74DB4ULL, 0xD0274FA04EFBB2C1ULL, 0xD86D74B01C92D883ULL
        },
        {
            0x4DA0B66000CA966FULL, 0xCEAE18424CF0D762ULL, 0x396BD59217034A9CULL, 0xFCD734A37B8B5F81ULL, 
            0xA3E91CCFDF43513BULL, 0x808E2D173510B70AULL, 0x8FA2DAB1D29AE65DULL, 0x9A4C646DF4ECECA2ULL, 
            0xFF0E64CB4DFD5DD1ULL, 0x8408AA7566A61312ULL, 0x382CBB15E1D6F676ULL, 0x80717500088F7DFEULL, 
            0xD754E3FF1409F70FULL, 0x291AF0AF2518A80CULL, 0xAC3201735AF9F567ULL, 0x3058B6251CE4A46CULL, 
            0x3C06F4558E7B5D8AULL, 0x993E9F3838F3497FULL, 0x325878ECAD69F92EULL, 0xE90A2AC5DF103360ULL, 
            0x2B30D9354E585CE7ULL, 0x348F299578A7062EULL, 0x882AA52D5F301922ULL, 0xA0BF125F9FC41ABAULL, 
            0xB37A4BC9C30A0471ULL, 0x2075C1AFC22AE128ULL, 0xAA54BC2A2BBDC096ULL, 0xB685754C9CDA04D6ULL, 
            0x13917B28A8F184D4ULL, 0x3C88C04DF63E9F91ULL, 0xD59F19415FDA6E62ULL, 0xE278D4814B31188FULL
        },
        {
            0xCF80AAE9CDD12DBBULL, 0xF5128DC54D0A404FULL, 0xFE665A84EBEBFD43ULL, 0x7306B5E1FE193156ULL, 
            0x668DE4FE67AF2DEBULL, 0x8A8EC50FBA3236CDULL, 0x6622145AB6CEDC2EULL, 0xA8123B0288612CAFULL, 
            0xA5BCFF5114C668FEULL, 0x1F88F580BC1C87B2ULL, 0xE999916DC7CFB756ULL, 0x44FC0E679DB91B48ULL, 
            0x332CC1B988833D5AULL, 0x9EFA06BBD4DCF37AULL, 0xD2F828B55C22D634ULL, 0x40C8BA3C0C2B826EULL, 
            0xB9EFA6EEFB0FDD8FULL, 0x2DF62E4F650F1761ULL, 0x69B2989106F0B9EEULL, 0xC5CE9707AA38BBDBULL, 
            0xC261AA855D6648A7ULL, 0x512E68AA6C4E1B2FULL, 0x568E545A6421FDECULL, 0xE7965357D2142B29ULL, 
            0x78EA037C1F425DB8ULL, 0x8E9FDF1CA147DD79ULL, 0x20DCDB2BA4F4D1D7ULL, 0x2F0CABD684094FFBULL, 
            0x5254A9D0E604629DULL, 0x35C94FC4FBBBCBF8ULL, 0x63E97C9FDAB2417CULL, 0xCAAEA743E7240359ULL
        },
        {
            0xF90BD5B31F4C9AA5ULL, 0x2638CBE8EEC32C15ULL, 0x6E5E21FE96C01F50ULL, 0xF20344EBD244D30CULL, 
            0xB4E214286E52531FULL, 0xFF24613D62ABA082ULL, 0x507F7DE9F2DFB369ULL, 0x9AF0263A195A4021ULL, 
            0xE0DF45B6653FB2A8ULL, 0x000BD972F85164E3ULL, 0x0DBC8DB2C6E805DAULL, 0x21378454B196CC7CULL, 
            0xEA09A1A53567378DULL, 0xE99D1EF21C4856D5ULL, 0x5A3AF7DE2E0EEDC1ULL, 0x595DC7EA207340D5ULL, 
            0x41C001D18FC49196ULL, 0x14552477AE1F63CEULL, 0x40BBD79700677A6CULL, 0xC86A07B46D9A318EULL, 
            0xAEFB0F4EB47A4135ULL, 0x633D7F66F0CFAB6FULL, 0x74817B4A55AC406BULL, 0xBBD0EFEEF262C784ULL, 
            0xD512C1C7BE7E58BEULL, 0x1C6B6A081EAD785EULL, 0x11FAFABB719F3440ULL, 0xAB7439FF50E5E669ULL, 
            0x314DB8D43B7DEC40ULL, 0x663725C55AB368FCULL, 0x12DD0FBEB863083CULL, 0x8FB4B63E38951758ULL
        }
    },
    {
        {
            0x2882861B518488D7ULL, 0xC8B88D0AFF5AC18AULL, 0xCDF36EC986A0FEC0ULL, 0x916DAB20E0C7F5D5ULL, 
            0xDB3ECA0213BECA64ULL, 0xA77AA338A7C5B0B5ULL, 0x51D79D74DF6A5C07ULL, 0x6E11A1BC16F33016ULL, 
            0x1FC7D83C041A07DBULL, 0x714DA12D5F4E5587ULL, 0x4DD174A46FEA9745ULL, 0x1DD2AD4AAA42F39DULL, 
            0x369E9AD8CB1401C2ULL, 0x9AFF4C86F4D299EEULL, 0x70F98D255D689212ULL, 0x372C2BFE5ED575F4ULL, 
            0x74CE27165EC6BEA1ULL, 0x2A456E888FD536E6ULL, 0x08132C018E2B9221ULL, 0xF2D6DAEDD942F505ULL, 
            0x8EF69BDAF40AEAC4ULL, 0xF6EA90DC755581CFULL, 0x4DE19C332D527622ULL, 0xA3FA38203D0B28E8ULL, 
            0xDF371316CC88AD80ULL, 0x742E9988E1B7C9E8ULL, 0x773829177B3A05A3ULL, 0xE862AD2B6F2515C6ULL, 
            0x0CD204D525524676ULL, 0xB10E3DFA1FFF8C00ULL, 0x19DE25C8C6B5A9EDULL, 0x209D1D9CBB67B18FULL
        },
        {
            0x9B593841D2945E72ULL, 0xD2973C7AA9D50E63ULL, 0x558206DB87D4A9D3ULL, 0xA8CAC16000355096ULL, 
            0xC85D270E7F52DB06ULL, 0xB84D30D4F5810A53ULL, 0x06B2803BD02BE3A6ULL, 0xEB27DCD17DF2B002ULL, 
            0x344182D308E83783ULL, 0x99E20BFDD1A221C1ULL, 0x0A9873324C7B9631ULL, 0xFBC8A9D9B6C36313ULL, 
            0xCA1AC0F29CA92A32ULL, 0x24DFFB7F83A2FD5DULL, 0xDE52838759CF3C04ULL, 0xE9FCA3CC5E2A8735ULL, 
            0xFEF15A878C9B1650ULL, 0x716C7AD32607F49BULL, 0x5BA899390FE98616ULL, 0x96DF3D8E50BEE3A4ULL, 
            0xFF050312EA175ED4ULL, 0xC699D41A575BCEDCULL, 0xE26B8C4989222A36ULL, 0xFEFA5E736C08A7E6ULL, 
            0x84792A3A98BD0ACEULL, 0x759CCFEF24651F41ULL, 0x3DA33D6F77EA434AULL, 0xD8C8CC925D90101AULL, 
            0x650067B63FBB71C8ULL, 0xD9BCAE78A076A24AULL, 0x9A11A63A7502F50EULL, 0x486C959EDF13FDCAULL
        },
        {
            0xD23045C46166E468ULL, 0x63311C09BEF2E196ULL, 0x6A450B733267ABFCULL, 0xA7BB6212E8CFF014ULL, 
            0x9D493413993BDAA8ULL, 0xC9330E9734D1A1FDULL, 0x3ACEADB709364676ULL, 0xF8BA8DA7B11331A0ULL, 
            0xF31A889BB508D82EULL, 0x53353294ABD0098EULL, 0xC56EFBFA4623FDF6ULL, 0xE1A442484879A48AULL, 
            0xA8AC6E69989D84D4ULL, 0xB4AC07C8ABE2685EULL, 0x359F4C38ECB9C7BAULL, 0x9E4E25CABFE5F752ULL, 
            0x5A49B5E7A3F8D5D0ULL, 0x81E56F0DAA80C7DAULL, 0x11D7258706EDED57ULL, 0xE28B644DD5694471ULL, 
            0xB93E59CD47D03790ULL, 0x82652589F6FE5A0FULL, 0x1D09D41870D85DEDULL, 0x6A7BD6BBF75DF6E0ULL, 
            0x8F77E57BC0B4C539ULL, 0x21B7983F8E9840ACULL, 0x0AF3834ABE196F4DULL, 0x876B6C89C6980FF3ULL, 
            0x8AE8F5EFDF2A0B3FULL, 0x453677C38BF8B58CULL, 0x3CDED25B985907CCULL, 0x91A0FA56402DAA7FULL
        },
        {
            0xF6C1C36D10F75A4FULL, 0x52EA92D87684DC30ULL, 0x0CF17D53AB8B68D1ULL, 0xFE669134DC02B211ULL, 
            0x91935C343586B0FEULL, 0xA5E43690076E8B1FULL, 0xF57E8F05216666B9ULL, 0xFA4AB4393C0F4963ULL, 
            0x7887B32ED8DF9C48ULL, 0x94CE6E770CA720DDULL, 0xB63882B388634386ULL, 0xBCA51297637F38F4ULL, 
            0xCAC2A11A3F533C9AULL, 0x79197CE82EDE94BEULL, 0x7A501B1936D12332ULL, 0xC9F66E592D02F610ULL, 
            0xD1F1867952C43CC7ULL, 0x37D8E27FEB8458FAULL, 0x9DCEB18000295562ULL, 0x0E0F822DBEBA9378ULL, 
            0x2B72495220C99445ULL, 0x597DA37DF531F41AULL, 0xFA9F21AD5A4EEBB6ULL, 0x3CD970EEEAF12497ULL, 
            0x05A6BD18B9D6B1A7ULL, 0xCF12D17B94484915ULL, 0x39B37F9F7CD14F54ULL, 0xCD78EBC18EAFA77EULL, 
            0xF9B8797719F9DBADULL, 0xC5A1CC2EA02B107CULL, 0xB91386E80E6F1876ULL, 0xA49202E6DA83CEF6ULL
        },
        {
            0xC3E3DA25CA8B19FEULL, 0xC845E7A3E203D2A3ULL, 0x6BEED859D770BD1FULL, 0x05629E3BBB27E563ULL, 
            0x886C65E5C9C248F9ULL, 0x7E523EC73674854EULL, 0x3F34F7A1C1DEC068ULL, 0xE382F33A6A1F590FULL, 
            0x00AAE8EADA283B55ULL, 0xA938778B8BFDB4E8ULL, 0xADC9ED92D41B2AA7ULL, 0xC49A0DA8D42EAF2CULL, 
            0x0ECCBAD5FBFED587ULL, 0x6C5E1C4427B71BDFULL, 0x1CA6D153828EFA0BULL, 0x376781348B27ECADULL, 
            0x18BE087DF922F8E6ULL, 0xE8B51BD9226DACE8ULL, 0x40202D2A1E4D7302ULL, 0xCCCDBD3C11514C70ULL, 
            0x4FA1D396719537C5ULL, 0x0F729BC06024C803ULL, 0x37718251F1E55463ULL, 0xBE95B154651BD37FULL, 
            0x2DFA347FE372046DULL, 0xCC96968EE6B93F30ULL, 0xF667FD091B44A577ULL, 0xB003E325FBA42CF0ULL, 
            0x978A08E39174607BULL, 0xB75EEA71916FA303ULL, 0x1F1BC6EC4FB76EB1ULL, 0x4A1976D654A5949AULL
        },
        {
            0x56A292C7AE9458BFULL, 0xB4251D99A4698ACAULL, 0x8314C2C1A9C5634BULL, 0x3E0C1986FE71AD8DULL, 
            0x1FC9A5918FA16B77ULL, 0xC342AAEB19BA1EA5ULL, 0x8F3941D9EC2C0456ULL, 0x44F12D6BC9606CEDULL, 
            0x1C5D33EB87AA67E0ULL, 0x7479FCF0DAB8AFB3ULL, 0x1EAC9F0CE0493379ULL, 0x1CD8FFC66784AC5DULL, 
            0xF91EE73A12D04201ULL, 0xFFE3A209D707722FULL, 0xC3090965B004D886ULL, 0xF4EB8FAC25169E98ULL, 
            0xB894B9845771C10DULL, 0xB400371AE8589A03ULL, 0xC5C49FCD534F0C2DULL, 0xFEF88C4E62B6D1CFULL, 
            0x28C743C795A0AAB7ULL, 0xB44F8391BC012464ULL, 0x11C444FF4977AE0FULL, 0xCFCF347C947750D9ULL, 
            0x207B4F6F6B247A1BULL, 0x8415918AC62D4DBFULL, 0xAB055BE116BFBC9EULL, 0x85FFD453F39FDB23ULL, 
            0xED18C4E0C50C5230ULL, 0x31144748AAEBBFD8ULL, 0xD70FAB6A7DC1081FULL, 0x8775F38B3CDE1C55ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseEConstants = {
    0xADD7BC17512782EDULL,
    0x32272336D78A2328ULL,
    0x17185823B94D4B7CULL,
    0xADD7BC17512782EDULL,
    0x32272336D78A2328ULL,
    0x17185823B94D4B7CULL,
    0xFC5126F86318B7DCULL,
    0x7B433EA614F2FC2CULL,
    0xA5,
    0x5C,
    0xA8,
    0x0D,
    0xD7,
    0x74,
    0xF9,
    0xD5
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseFSalts = {
    {
        {
            0xBB941EEE3B065413ULL, 0xB292A9AA62A26852ULL, 0x9C523366D081CC15ULL, 0x40AD7DCD77AA5096ULL, 
            0x1B55BA8778C06F6DULL, 0xC37F2C5651179B04ULL, 0x70BB9473CF4223EDULL, 0x69264FF43621E991ULL, 
            0x39ABC14D9553B45BULL, 0xCBCA30F9A3B3B85BULL, 0xAC26CBD81FD6BCBDULL, 0x6C8747BD29997308ULL, 
            0x4EF7A1FF3578DB9CULL, 0x78F5E8220B324D16ULL, 0x7028918FF01BC20BULL, 0x8556ADC633B4AC46ULL, 
            0x5EFC003AA63F4C00ULL, 0x8AD4B7EFAAAC6943ULL, 0x379D65DD15A8EAD7ULL, 0x7D4C0FABE6E1ADEEULL, 
            0x029FEFEE8112D9D4ULL, 0x1A02A501E7007542ULL, 0x093389CEDD5C42D4ULL, 0xE94A7C94CC60ADF9ULL, 
            0x75C825D2990F4B8AULL, 0x21FA907AE6EC6E0AULL, 0x941C7BEB49B4576EULL, 0x3DD59FE7E0821CB7ULL, 
            0x6B4C5579BA0B719FULL, 0xFC211004B4A06FA1ULL, 0x7C7FDB074E8C02F1ULL, 0xF8CC0F19CA0A2C6CULL
        },
        {
            0x4F63FE99CD755AA2ULL, 0x4AD64AB527C98A65ULL, 0x86F3294D4FD3625CULL, 0x0FC8D2D73E86B247ULL, 
            0x9BA7F62A1F5A5153ULL, 0x7CB0E603F8CCE88AULL, 0x7843132F63020D41ULL, 0xA17764AD51A893C6ULL, 
            0xB8E97C3CEE0D0A75ULL, 0xAA96847593220EE8ULL, 0xABB161F17ECA77C4ULL, 0xBB319B0001C75BDDULL, 
            0x94E8DB9ABEAEB6D4ULL, 0xCF2186E8BFC6C810ULL, 0x3B4756A829B03106ULL, 0x08C17C7B6644ABC6ULL, 
            0x00589C05A8B49797ULL, 0x77521CA8C165C15CULL, 0x98E3063BAE5EE039ULL, 0x0F20201C6AB46840ULL, 
            0xD22AB37CCDFB2AF5ULL, 0x2C0DE807227D6FC0ULL, 0x4A2DFB645CA56D5EULL, 0x0D20E3B82ADFC747ULL, 
            0x1011511DA5C60019ULL, 0xE3F1FD795484EB7BULL, 0x1392ADE11BF8AEBAULL, 0xC5C07927FABB5D60ULL, 
            0x0886A09064C2CD68ULL, 0xEA0FCBBA4C3CD12AULL, 0x7EDD954CA76DAFFBULL, 0xD3FE6306BE1BA0A9ULL
        },
        {
            0xBB09D0AAD033B2D9ULL, 0xCC36B8882119C692ULL, 0xD43BE030D2765AB3ULL, 0x0E1F1256C8718C05ULL, 
            0x43FAB18F242C41E9ULL, 0x3AC4D46FEE6023CDULL, 0x35F97B09EBC798A8ULL, 0xC43CC3A5929AE5D7ULL, 
            0xE5C5F19145408CB7ULL, 0xFB4E661FC94C2DF5ULL, 0x6378AEA7CF81C4A7ULL, 0x7D0D719A2BC147B3ULL, 
            0xD85696494F7BBBDFULL, 0xE2A477E31F1D40F5ULL, 0x157C565D53756222ULL, 0x275C22D722C0F0F4ULL, 
            0x2B0FEB4C3D778D9BULL, 0xC6AF2465E53151BEULL, 0x5C53400E93CB7F61ULL, 0x2679FD63304C1C09ULL, 
            0xD3B53158BC607329ULL, 0xFC502A6A6750ED3DULL, 0xF00C006BB4339149ULL, 0x9183028E1F421CB7ULL, 
            0xF2C833272166FE9DULL, 0xAA023FE9A511513FULL, 0xA115CE24CF64A9FEULL, 0x08CC9DDB2041608FULL, 
            0x3D4339CB844B8C85ULL, 0xACC9E41D609F6EE2ULL, 0xC270A1C4590DA221ULL, 0x4EE0EF9E43BA4D70ULL
        },
        {
            0x0474FF8CDB7FB305ULL, 0x3A8F52AB3B601AC1ULL, 0x89096A5B8DBA0A52ULL, 0xA3D0386EB8CB840CULL, 
            0x24D5A70703775104ULL, 0x9ED1969E6D237DF9ULL, 0x9CF32CC1256A2E11ULL, 0x5479CCA66E539E7AULL, 
            0xC4A220939034DA30ULL, 0x7A505BAF5354DDEDULL, 0x7E66F2EA3B3980CCULL, 0xA6F03B8E3A0011A7ULL, 
            0x44933B2489ACD301ULL, 0xDBDDF27D83A10528ULL, 0x111093828BDE6DF6ULL, 0xF57BA9A39155EDEFULL, 
            0xA62DFA05EA904E9CULL, 0x56168B6DB7512054ULL, 0xEFDC90CAAD243BF2ULL, 0x14315A1B4F50158BULL, 
            0x4F8CCC4AACE00253ULL, 0xDA01062FCFAA7E32ULL, 0xACB3C565C09CDBA2ULL, 0xA2C37CB26104B754ULL, 
            0x407C748CE8B07FB3ULL, 0x21125CEDF25D722EULL, 0x0CB8A46660185E0BULL, 0xFB1C80AE72159DC7ULL, 
            0xA8F831ECAAFA793AULL, 0x704FC2FCFCF730C2ULL, 0x134E7574E3F163C6ULL, 0xFB3DCF6EE0E3EB58ULL
        },
        {
            0x45927DF678D8E132ULL, 0x5855B05F0414C731ULL, 0x9429EFF8E08BF2D0ULL, 0x91BC17CD3CF21A65ULL, 
            0xF29D2BBC04F05246ULL, 0x34A32ACD9F4D3DDBULL, 0xAE871FDC12BE8F94ULL, 0x4FB7F9CA05A22A8AULL, 
            0xC30BF2EA88F6C739ULL, 0x128006A7203B8A2FULL, 0xF927422E8EFCC5BBULL, 0x74E32879F77B3FB5ULL, 
            0xE276CBCFA0AFFF59ULL, 0x303BE06A3F147122ULL, 0xA2E8D840260C0E32ULL, 0xC014DA3916C19ACFULL, 
            0x656A115DD2F75F4EULL, 0x6338819D400F103AULL, 0x72585893A2AF1FFEULL, 0xE0ADA7EEE8EE759FULL, 
            0x0F388C8D38635C99ULL, 0x2BFED2E83A4820F7ULL, 0x1E578A4EE344C93FULL, 0x55D06E7B876D6326ULL, 
            0x90E9921EB60D5B18ULL, 0x6E9487824CEF6FAAULL, 0xA12F18B282310D46ULL, 0x5B70BB379B5A1699ULL, 
            0x069AD472C1D0E171ULL, 0x34C16D3D78633C41ULL, 0x10B68D1F8C73B087ULL, 0x3A52A0B3C6EC970CULL
        },
        {
            0xD8AE2305050391E2ULL, 0x48F31538D0DC0C41ULL, 0x88C0CCC7059EAF6BULL, 0x19677DFBDBFC4077ULL, 
            0xA22520003B398E4AULL, 0xDD54143277A72191ULL, 0x4A20E01B46C8352FULL, 0x1BA8EFB8AC9410ECULL, 
            0x3361364163BC5CE9ULL, 0xF725900FA40D606EULL, 0x2D750631FC0A5542ULL, 0x1622C72F5E637535ULL, 
            0xA45F875082E79249ULL, 0x0E6429FE045D2CC9ULL, 0x9AB0DBFC836C9354ULL, 0x03869C0D04DEDBD6ULL, 
            0xD43057F48CE1DF0DULL, 0x7D19104793E99805ULL, 0xFCF79EB79D2BAB8CULL, 0x9CE066738BB1A0BDULL, 
            0x1837A840A71DE517ULL, 0xED172FBE04DA25EEULL, 0x26CFF44F0DC72107ULL, 0x62177A3A95F9DE50ULL, 
            0x952E0121A2D7DD23ULL, 0x745F6BB1C74593ABULL, 0x00D6150FCAD728A7ULL, 0xAC305ABED94A4E13ULL, 
            0xB48D4C17273F00C3ULL, 0xBE8E0B529AF3E514ULL, 0x10BA8CE3A7F63885ULL, 0x5FAB2459CE546352ULL
        }
    },
    {
        {
            0x68B0CBA0F7E048BDULL, 0x81D205A7FD99F00AULL, 0xFC5297DF8C7FFDF8ULL, 0x4AF96479E9E65EFEULL, 
            0xB4366F9950CD92A7ULL, 0x1DE2A6EF6C23E969ULL, 0xB3675011239843F5ULL, 0x66B6824F7F2C3839ULL, 
            0xDC37EE55A6314DF8ULL, 0x6E33FA9261D6DBC6ULL, 0x697FD25B0539FA8CULL, 0x06507B74DF5202D7ULL, 
            0xA224CB1C900733FAULL, 0x59B39F989074D216ULL, 0xC4EEBA1311ED3A48ULL, 0x5F9C86C86D53F099ULL, 
            0x802E966829E0E10EULL, 0x828E8EB5BBF2605BULL, 0xF4746FE0FDF41B3CULL, 0xA6F0B2B4A5274590ULL, 
            0x6185D503EFBB4C89ULL, 0x0B8D84A5ED09C1B4ULL, 0x3089AADD004E7007ULL, 0xD70E8B6EF330948FULL, 
            0x5EDC54DF15D81DD4ULL, 0xB5B2DEA3FE79BFD9ULL, 0xD931DD774D969D95ULL, 0xA703C93312D43068ULL, 
            0xAC0648B0A19FEB89ULL, 0xACF5A9595CD72B6EULL, 0xD5E59E7F9D1DA1FFULL, 0x5F8C3C362D5B807EULL
        },
        {
            0xCF51BE66E3D1588BULL, 0x7B789623422BFDF4ULL, 0x92A7C603A674E4FAULL, 0xC83C16AB2AECAF45ULL, 
            0x91980942EC987E04ULL, 0x4416A3B59FF65030ULL, 0xA465879BE5C533A2ULL, 0x35F5D85CF6BEBB57ULL, 
            0x7807733A7AE1FAB4ULL, 0x1FE19A511B1F747BULL, 0x9A6E79104A3866EAULL, 0x12F8316DAB4C2542ULL, 
            0x90C901A0718F1E2FULL, 0x81F55C75BB5BCD11ULL, 0x1C37046D09943B45ULL, 0xE6670ACC98A2A5DDULL, 
            0x672186D4C12F9C1AULL, 0xDFE79948A2A30FB4ULL, 0x6EA7EA24540CA857ULL, 0x8AC43E96BCBB64EAULL, 
            0x10E76F00E571665AULL, 0xB4EAF6F9610C8169ULL, 0x1CF691B53B652E26ULL, 0x9D2EF45B2B74E7E7ULL, 
            0x2A411875DAF40455ULL, 0x5D3B34A21953240FULL, 0x3B425841C9D2134AULL, 0xB8C6FED089D2D458ULL, 
            0x0C2C34FFA7714053ULL, 0x4687C6EE27C7BF8CULL, 0x98D8FF3E1D57DBF6ULL, 0x60E9228581F45DA9ULL
        },
        {
            0xB72987EB39BDCCEFULL, 0x158BD7AD3670C53EULL, 0x042C2A8854007533ULL, 0x7CF9825DF61A46E3ULL, 
            0x6CB39C746C2AB1B7ULL, 0x86ECCFA4075B430AULL, 0x93F0E120F51D39BBULL, 0xE72AB3A3AA286E85ULL, 
            0x31A2A00E10DD24DBULL, 0x2644B4835442E04AULL, 0xDEE39B87EB9F6AA6ULL, 0x10DA75EFED609EE3ULL, 
            0x1DED32D736E1B073ULL, 0x5968EB95BE3A0B41ULL, 0xD022DAEFC77B5C0EULL, 0xEBABB40CE521846DULL, 
            0x063A809A5819A419ULL, 0x2A1D2CBF3002FF6AULL, 0x6E9F14F49AF2D800ULL, 0x0ED84F7CE65757A8ULL, 
            0x7D935153DE4D6F1FULL, 0xCD6B67CCD72610BEULL, 0xFD7BABBA5BB2227EULL, 0x24C37907840D4DF1ULL, 
            0xC12255206C9627AFULL, 0xFFA43CA58E92827AULL, 0x31668052BF01B3ECULL, 0x6ECA8A9EB254A62FULL, 
            0x920487942AF9269CULL, 0x4300305A4EB305D4ULL, 0xA69BA039D2C7A853ULL, 0x1388CCF895661A94ULL
        },
        {
            0x2C4C3C99917E5671ULL, 0xCEE70F2944C30B2EULL, 0xA1E8995B6BADA6FCULL, 0x0EBC713437ECE1DDULL, 
            0xE80E60BAE61DE123ULL, 0x3D7A3FCE8FB33C74ULL, 0xFEBD034BBF4CA05FULL, 0xAC3C21D5C304B3BEULL, 
            0x325E07337B3ADC2FULL, 0xA74B99F6E07F4530ULL, 0x94598C6FF937C1D1ULL, 0xD976E9007C8E26D7ULL, 
            0x57E3C66B14CD9B0EULL, 0xA3C16BBAFAFA3675ULL, 0x4F0D32DF5CC7F5B8ULL, 0x7C10E3DCD322CA22ULL, 
            0xAB5ED8EDD30ED4EFULL, 0x2118352A7E371528ULL, 0x8EBD9E4A05D43FB0ULL, 0x3BECF6288313B435ULL, 
            0xB0F268C3283F2FAFULL, 0x6C820AB283F8A6FBULL, 0xE401F63B28E12E40ULL, 0xCF34333A534B383AULL, 
            0x75B047E2BC9C558CULL, 0xB9C184BB7666565DULL, 0xCA7546401C42CECFULL, 0x41384C732F88BD47ULL, 
            0x4165ED9C04713EE5ULL, 0x6CD110462FAFB1BFULL, 0x6E803508A56AA48BULL, 0x951CEC05BE1780B0ULL
        },
        {
            0x350306418C4E49F6ULL, 0x524ACC43118E8CBDULL, 0xE688C14E0F840B6EULL, 0x66C69AC1BF78E4A1ULL, 
            0x18FA58F854DEE966ULL, 0xB3B0D4749EE7657CULL, 0x2ECB8244A02B05E6ULL, 0x32BBC533CEE9CD79ULL, 
            0x64A2226A1F0B0AC7ULL, 0xC429631939D6EDEDULL, 0x0DF5D8532354D406ULL, 0x61392480DEA62424ULL, 
            0x167C1BD8DB553153ULL, 0xC24EDA4109BF6DE7ULL, 0x67469168B9253897ULL, 0xB5E0A3F68ABC0D4FULL, 
            0xC4F27CA59B64E25CULL, 0x2BD1CEB6D126D67CULL, 0x73ECC9615B5191C9ULL, 0xD3D00893A5474AA6ULL, 
            0x7C36A5159A6A77FAULL, 0x75DF22A73A2D712BULL, 0x11BDC01E3094BA66ULL, 0xDA526723E850EB1EULL, 
            0xA0E8BCE3A8E217FAULL, 0x480A6745E2D71DD0ULL, 0x83411E7AA5ACB2E9ULL, 0x069C574CBEF403DDULL, 
            0x5153C08C273B1D24ULL, 0x02EC1ACBB2BD7139ULL, 0x285F3C1201D85A41ULL, 0xEBB863F877541A35ULL
        },
        {
            0xEC0235C6C9815988ULL, 0x0DA05344A84F4268ULL, 0xDFD382872B59DB5AULL, 0x13F7B268A1C9CFD0ULL, 
            0x96B288F6D2F12BB4ULL, 0x4F08D0486EDC75EDULL, 0x4879872EB5896447ULL, 0xFFB4252A4380ECAFULL, 
            0xDE9181BC75D70F09ULL, 0xBB693D91D5EB24F1ULL, 0xBA8D71C6116F5290ULL, 0x6B688A6C1DF8EABFULL, 
            0xBEDFBC2FB82D37ECULL, 0xCD4376FD6EC611C2ULL, 0x83167E27A7F4E837ULL, 0xCE3D7A5A3F2B8B3DULL, 
            0xBBBEBC96FD6654DBULL, 0xD05E286CBB5046FAULL, 0x00607BF825E2DC28ULL, 0xF12C625E1A283D1AULL, 
            0x9F88A4EF3CF20ADCULL, 0x8165E322AAE4643CULL, 0x43D53C3D886045D0ULL, 0xCD1C4E4D16466189ULL, 
            0x45E0E9179F838C22ULL, 0xE30003F264EF98F4ULL, 0x493CDF1651CCACDEULL, 0xDCD9C3A281663A2BULL, 
            0xE0AA8A9E39F77302ULL, 0x1B1D5873ECF78F5DULL, 0x4171E3410D65A306ULL, 0xAA7C8F4ED9D4991AULL
        }
    },
    {
        {
            0x81805F7D6C5F2903ULL, 0x1D60B895584B0745ULL, 0xE762B94AD2D94861ULL, 0x60A546AA9471535EULL, 
            0xD7D77035D9495A02ULL, 0x5D6E17BB093D1882ULL, 0x7F2730F031C376D6ULL, 0x89EB710613CFAEF9ULL, 
            0xA5F40ADB75699F93ULL, 0x4CA4908D0B9B58E7ULL, 0x4EA95B8FDADFBA7CULL, 0xDAAEF28D1C22A09AULL, 
            0x5481517286A7DF90ULL, 0x461C09C20E9C45F2ULL, 0xEF0C2F376270F06AULL, 0x64FECDD46AA7FB8BULL, 
            0x3176EEB2A005C3E2ULL, 0x2E5E4E5183E680E9ULL, 0x6175323F01373E06ULL, 0x7DE217CA47B5AF7BULL, 
            0x02D0E1DB481FDDB2ULL, 0x7A51CDB5CEA8A7E1ULL, 0x40268442BACB372FULL, 0xA22C769C7F1B458EULL, 
            0x7DD899700AC12F8FULL, 0x0433999BC8C09017ULL, 0xF2914E0E411938CEULL, 0x13635ECBACCC529AULL, 
            0x95CB00CB96D76097ULL, 0xB52E396F90C040DBULL, 0x17484A32EB56D433ULL, 0x5B070A16D273A8D8ULL
        },
        {
            0x82EA073A41D3143BULL, 0x7DEB29EEAF99E661ULL, 0xC509B64D08457E4CULL, 0x386E5CBDCB6F723BULL, 
            0x7BB7B7D0DD5EB6E2ULL, 0x3E1171BFA13BDA49ULL, 0xA3A1D954F8B42277ULL, 0x1C6DCE5BE44CF188ULL, 
            0xFDD84C14D5094802ULL, 0xE8FD867446F1077DULL, 0x0106AF2032242442ULL, 0x4D2C9DA217D53A4CULL, 
            0x4FF2B8F4F261C9A7ULL, 0x0D59378F874EF163ULL, 0x6505F69ED19EBDA8ULL, 0xF48640C4F9BB5D8EULL, 
            0x4E8E1532B3FA4AFEULL, 0x4D2FD72EE42830CCULL, 0x0870FAA18C73B9DBULL, 0xB191B28F5942B209ULL, 
            0xA9BB2CBAD84974B9ULL, 0xC79138F0E9B8D6D7ULL, 0x1B3960937D6011B1ULL, 0xDC08C6F1D5FE545CULL, 
            0x9EC7A2BBA0BC395CULL, 0x008C753D940037FDULL, 0x4307DAC252272B56ULL, 0x0A1ACFD9F3715F4CULL, 
            0x2ECC286088AAC11DULL, 0xF3C06C211F378EFAULL, 0x98954C19C128AB71ULL, 0xD9F376FFED8B1C7EULL
        },
        {
            0xE0A81F6C7D7A276EULL, 0x048488EA7D00ABEEULL, 0x1FBEC6D5F8DEE272ULL, 0x6445953B1308D936ULL, 
            0x24144D68BC9E87E5ULL, 0x49A523291A284E07ULL, 0xE9302601A1457087ULL, 0x4675DEB89D4EAC8AULL, 
            0x791751F5BDEE3D69ULL, 0x78203EFE67549E96ULL, 0x4D264C24C7BCCB5EULL, 0x456B7CF4AC9B4964ULL, 
            0x947372FE6DE067DAULL, 0x3D70B81B3C080566ULL, 0x83C5A5592F898D3DULL, 0x0D4540861C5EA9A8ULL, 
            0x55C240A2F2B18886ULL, 0xA754E82F3D0E1BD9ULL, 0xB999D8610DA81CD5ULL, 0xF17953055D3EBA0DULL, 
            0x7A9F26F555B8EA67ULL, 0x22C83799C97AD314ULL, 0x42A28CC15FE274C9ULL, 0x62B88FE16C2EB21FULL, 
            0x7DE72B06047A3F37ULL, 0x41E9C28A6F2C0843ULL, 0x919F94754222B69AULL, 0x8BA3B0A0846B0DB7ULL, 
            0x46D97136E02A13DAULL, 0xBEB03BFC9A3C0DFFULL, 0x3FDFBB3EDCD95EF1ULL, 0x7C430E8741D4D868ULL
        },
        {
            0x23C33B067D78A3E5ULL, 0x2733CC254130686AULL, 0x3A3CF88F652685B3ULL, 0xE455A4B607412B9FULL, 
            0xE735F594EAFE3B7BULL, 0x0059C43A2D0AE644ULL, 0x7E5E0D7B753FEFB6ULL, 0x11FEE3BA37C3ABF0ULL, 
            0x4BAA5E11428FB48FULL, 0x048C958D7D2697C3ULL, 0xFE7E8D9BE27815CBULL, 0x16180820113F2B24ULL, 
            0xE9EDB99F7233A885ULL, 0x734731BDC33102B6ULL, 0x994BE6B8419C4557ULL, 0x7E9AA42E179012C6ULL, 
            0xE419EC9070D9F6C0ULL, 0xA7777DEB5AB8BE48ULL, 0xB246C974BBAE9B4DULL, 0x36776A75E99EA9B1ULL, 
            0xA66A731877A1FEE3ULL, 0xAC0413F0C0225AB3ULL, 0xAA19F434CD922788ULL, 0x3FD8EA0F0961CE6CULL, 
            0x01AA6A8F2EBE3F16ULL, 0x8D9DB8F332FAA5EEULL, 0x9317BAD16C59FCB0ULL, 0xA628CD6F934712CEULL, 
            0x85A4B1DED15D3569ULL, 0x81AD83B679F68719ULL, 0xF410B9F7CC65D9C3ULL, 0x448AF6033943AA33ULL
        },
        {
            0xF43F7E4B4872600FULL, 0x922856F1AE379C4BULL, 0x4D1AB5D88395B696ULL, 0x356D8A0A8F99F179ULL, 
            0x63E46A4D05C061AEULL, 0x48C54C7BCDC2DE0EULL, 0x8069AFE0B382D528ULL, 0xC47EBD7A6E53C6DAULL, 
            0x90E5640C8057F68CULL, 0x71B1356E504B7EFEULL, 0x41DC70F3F4038F5BULL, 0x60443791156DF233ULL, 
            0xAB648EDA839F5D21ULL, 0x9E185112D991FA62ULL, 0x9666F92E10641C02ULL, 0xBA6CE900A532E5A2ULL, 
            0x0DB462A790A648C0ULL, 0x612F421611BBC8BBULL, 0x71651A5193437C2FULL, 0x508F47056CD2B490ULL, 
            0x73C27F04D0A6998CULL, 0x38E57671E5A83D8EULL, 0x00A8E00EA6FC9B6AULL, 0x9E1B487134650272ULL, 
            0xC298447283DC1E2AULL, 0x5ED5FA3FA3A93688ULL, 0x6D9929C4F565E995ULL, 0xDF336F3065A4AE42ULL, 
            0xFE927A4C18293C84ULL, 0x5954FA1DD88EB784ULL, 0x61600D3C3BA3596DULL, 0x3CFD3E64BF4EEA36ULL
        },
        {
            0x1D20A9531A201AE2ULL, 0x75F0B5FE26E94510ULL, 0xB151FCD9C720012AULL, 0x537CC7E5486F92B0ULL, 
            0x013D4A4CF832E20DULL, 0x83A8F7D916096E88ULL, 0x121D71ACBACB4BFDULL, 0x40608A9767E32A60ULL, 
            0xEB9D13ED698953C7ULL, 0x51C990E7D077E79DULL, 0xBD8133B653680E5BULL, 0xBB287D681CFB0FA1ULL, 
            0x12A30F90901773E4ULL, 0xE26383CFD2513073ULL, 0x4AE2FE638CCF9EB5ULL, 0x8FAD9253F0AD81EEULL, 
            0x6264DDB6C5E927D7ULL, 0x0CDA685CBD25BFF1ULL, 0xE9D1AE675BCFA10EULL, 0x326275C1BFB73286ULL, 
            0x301EC40240CA7CF5ULL, 0x7CEAFF376B31AAA1ULL, 0x8E50E0099DE14B26ULL, 0x25222235A8FD3A7AULL, 
            0xD76C5543B5473021ULL, 0x8D9ADC8FB5C99984ULL, 0xAB221BC629D3514EULL, 0x12A43FAE70CDE3C5ULL, 
            0x90D2B6243E72320FULL, 0xE68B25CBF2FD2A2CULL, 0x012F28119FC74B56ULL, 0x1801647341831648ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseFConstants = {
    0xD1D2F8621016C5F5ULL,
    0xB101F072A6E2017BULL,
    0xDE8ADD6D509F9284ULL,
    0xD1D2F8621016C5F5ULL,
    0xB101F072A6E2017BULL,
    0xDE8ADD6D509F9284ULL,
    0x79AE2E13296A3C78ULL,
    0x776F5F93683527D0ULL,
    0x02,
    0x25,
    0xEA,
    0x2F,
    0xDA,
    0x4E,
    0x6F,
    0xA4
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseGSalts = {
    {
        {
            0xC26BD9D3C7473D41ULL, 0x2AA4E1340233E6CDULL, 0x577B937419241239ULL, 0x805D83786FE74BA5ULL, 
            0xBEF8211FEE9F7F38ULL, 0x3EB2D632F7408DF7ULL, 0xA1E48CD7A4E66A54ULL, 0xEE24A095CAB41F25ULL, 
            0xBA1E9EF4F3572E19ULL, 0xC007F096BE400788ULL, 0x2A3DF44AE06AC3C3ULL, 0x6BDBB72BAD4A78C5ULL, 
            0x48D0F221FC5E04F0ULL, 0x934DA8707A7454EAULL, 0x86323D83078D8E9FULL, 0x4383BE667A5A88F6ULL, 
            0xA47D6DBBFBB787ECULL, 0x6E7AC5C4446EBE8AULL, 0x1F2226BF48459DF0ULL, 0xC6A423356B5B4835ULL, 
            0x2AF5A3F8A4BDB089ULL, 0x50D5E494AFD4A659ULL, 0xBBADCCF1861BAE0CULL, 0xBCD63A745515FC93ULL, 
            0x8B1B20CBD6A74D3AULL, 0x78BE046F567EB624ULL, 0xF306B36523F7C4D0ULL, 0x11FAA27A6517C081ULL, 
            0x3BA48A68B35437BDULL, 0xB2264B46A5B4D712ULL, 0x84C16AF542E47984ULL, 0x5F25079B765383E6ULL
        },
        {
            0x5234BD340AD6D235ULL, 0x9245E6575734C125ULL, 0x2C1B213500766685ULL, 0x8E7D7C96F9179381ULL, 
            0x551637B9FCE60FCCULL, 0x961BDF21F72F4D05ULL, 0x265B838BE7E49134ULL, 0x6872C3BF6B765156ULL, 
            0xEF7CC7FEAAD06EE4ULL, 0x273E0FBA4840A6F5ULL, 0x8C07A1C905801F78ULL, 0xF6A514D9EBF7F5F7ULL, 
            0xE32A6905AEE2A1E2ULL, 0x725EF833DA65A3BDULL, 0x084502B1E50EE3F0ULL, 0xDB6A78AE2AEC3EA8ULL, 
            0x7FCA02ADBC958496ULL, 0xD885775300CD9322ULL, 0xC203F87C73C049A8ULL, 0xC52A99C5E4CCDAD8ULL, 
            0xF0FEDF1497B47C40ULL, 0x575BD300003C987DULL, 0x1C8351CC76B90371ULL, 0xEA132BF1168D10B3ULL, 
            0x9F8AEEB44B75381FULL, 0x1C867E96CFA7C689ULL, 0xD4238E91C8B787E6ULL, 0xB5E804E5E95F1288ULL, 
            0x38B5658D6EDA50D9ULL, 0xCA018F7264C3A5BAULL, 0xF783D48FBEC88FCBULL, 0x5BF8FA93B791422FULL
        },
        {
            0x9333A9D5EB76148DULL, 0x890E47F7F2885CABULL, 0xC2B3C450685A4AFAULL, 0x52A8167B22EFD922ULL, 
            0x4C4D17B258A77B22ULL, 0x006DA66E96C5CC4FULL, 0x3F00F091C553E631ULL, 0x8B547682071C965DULL, 
            0xCE91644A2F645646ULL, 0x19BDE424FA5EEF83ULL, 0xA1402B0C4357A8BAULL, 0x4710EF186D925C70ULL, 
            0xE2D92825DB9A0A6CULL, 0x8FD1B589481A1B15ULL, 0x8A69F188FDB11013ULL, 0xCE9A9D475C5CF71FULL, 
            0x0EB92731B2D68B52ULL, 0xCA2C3E001A46B8ADULL, 0x8028D3326112A7CFULL, 0x8DD98104F3613718ULL, 
            0x538F7B52C161BB7FULL, 0xE7463DE68E18854BULL, 0x7386484F7DBCB074ULL, 0x9D732DDF5CFCD115ULL, 
            0xDF350122305705D1ULL, 0xDE11B914D32F9E69ULL, 0x638BADF061147733ULL, 0x754E02AD55807A6AULL, 
            0xFF8ADD6971C2C2F0ULL, 0xC6AC55941E1E03B1ULL, 0xE3CC9473CFBB6018ULL, 0xBAD22EEAF539EF3DULL
        },
        {
            0x0B0110D6969925A6ULL, 0x6EDE1B4248EE4BC3ULL, 0xD8C3BFA090FCF0A4ULL, 0x1BC04030BC4DF152ULL, 
            0xF7412FC6837093F1ULL, 0x0CBA17E47407F4F3ULL, 0xAED567EB707DCE2EULL, 0xD300FEBEBF6E972BULL, 
            0x1472BB16DD809A41ULL, 0xFD8B933C4761F366ULL, 0x3928A890B963D7A3ULL, 0xC8A3F9D59466BAFBULL, 
            0x1C2AA05D008B2624ULL, 0xF5A352F48474AD76ULL, 0x03CF61BB779E282EULL, 0x63D0E2E129DD78EEULL, 
            0xCB8E15B207FC4770ULL, 0x86B7A1A22AC1F8DFULL, 0x945BBE15AEE38E55ULL, 0x80F90E05A66874EAULL, 
            0x0940D3554C818518ULL, 0x083F48465ABB380AULL, 0xC8A4549520AAEAEEULL, 0x428778F1FE493719ULL, 
            0x610B287A99AF463BULL, 0x402743499324E88CULL, 0xAF1BC4814E5697D0ULL, 0x8848A7C158D6F9C5ULL, 
            0xDDCA9CC3DB4C884AULL, 0x60C296DDD0A61026ULL, 0x232E77E7E5768C9FULL, 0xD5105708645791BEULL
        },
        {
            0xA0359DBABA0626EDULL, 0xB5928558CF65249DULL, 0x7246DCEFCB8FC545ULL, 0xD01F5EBF309C7064ULL, 
            0x81EDE3C94653DD7DULL, 0xDBFB21FF2F50D5BBULL, 0x3A2BFCBDA54C1F61ULL, 0x45740890A418451BULL, 
            0x96C759B4C4EDC84EULL, 0x42FEC70589A3DA27ULL, 0x450C156395E1D30DULL, 0xEEA2A8D4550B82C5ULL, 
            0xA025CD7CC4F92E0BULL, 0x35175B19794DC7E8ULL, 0xFAD7CA61325E13DAULL, 0x2ECAC98AB73AEEC3ULL, 
            0xAA05BE44C63D35ADULL, 0x50B3E537EFDE6C78ULL, 0x1BE0A7237FC718A4ULL, 0x1D091377030FE5B4ULL, 
            0xD09E4E8D016D02E8ULL, 0x9AC54A2A5B231CB6ULL, 0xF5C87A9EB7706E9DULL, 0x86BA33812BD51D42ULL, 
            0xCE442081B1A3A6C0ULL, 0x193219911EA558C3ULL, 0xA9E537927372120FULL, 0x6ECD07BE685F3D3EULL, 
            0x2271710EA761CD35ULL, 0xB727A351ECC29B81ULL, 0x4A9E8281B1326BA4ULL, 0x4B89D7E359A61DEDULL
        },
        {
            0x0EB3ACF3E77F8F5FULL, 0xAD652ABBA38AFC1BULL, 0x586C73C112CD5F57ULL, 0x79F12FDCEBBFE304ULL, 
            0x9297DB4CD43AEF32ULL, 0x859650B9515E87F4ULL, 0x716214AD62EC9204ULL, 0x8F3DBDE7236EB203ULL, 
            0x1456AE9D7C531CF2ULL, 0xD77363F11D7DE457ULL, 0x2372E71177426235ULL, 0xDE5C2EB8A0E1C552ULL, 
            0xF4DDFBECF8362588ULL, 0x3DE9A9CB3E750602ULL, 0x3885F98A91CD14F1ULL, 0xC896B57D35D80741ULL, 
            0x84EEC257FD90BB12ULL, 0x65072D03ADB748B3ULL, 0x0CCC661B4C86DBB0ULL, 0xFC70DD69BF840507ULL, 
            0xDAF482368FAB643FULL, 0x6D5AAD7E2AE4C907ULL, 0xA752B499D1D5AC98ULL, 0xD649A54ADFA10D6EULL, 
            0xF749E51E7CDFF5C0ULL, 0x8A8DE5486898C970ULL, 0xE9F0F7A9480DE1C3ULL, 0xCA4EA6DBFD73C29CULL, 
            0xF0D79EAF5D076D8CULL, 0x75CB2CFDC1BBCC4CULL, 0x8D5BE8161C6C180BULL, 0x48B872C62BC88A90ULL
        }
    },
    {
        {
            0x47134035551AC02BULL, 0x93E73BBE06D80D73ULL, 0x241F9EBF6B86D3D0ULL, 0x37A73C75FB2D59F5ULL, 
            0x5F62225324E5BCF3ULL, 0xC1771263312A65CBULL, 0xFB41DAF029555CFAULL, 0x624CB37568BBEE05ULL, 
            0x2AFCC414F574B46AULL, 0x0CC04F494C3CDBD3ULL, 0x634B277297C18EB1ULL, 0x466727B24B3A1214ULL, 
            0x792C14BCBE92F0CCULL, 0xDA1C791275C2EEEFULL, 0xB3B18729A0E277E6ULL, 0x090D1A0E940C97D9ULL, 
            0xEF834D72B7777BF2ULL, 0xAA6B80293141A50FULL, 0xA7CF8DBCBE7BDD20ULL, 0xDF361DDB46D7CBB0ULL, 
            0x274C733E9CEEE490ULL, 0x1B9B331BC941CC47ULL, 0x61946A7DD43CB2DDULL, 0x0AF1FB03F8A8F05EULL, 
            0xDA07C05D6DBBDD2FULL, 0xE11489296384DF70ULL, 0xD628DA72C5A19BF7ULL, 0x4240EDF9015C2CF2ULL, 
            0x79167AA8F4580978ULL, 0xA6BFDFB90E7BD64BULL, 0x9CA046891DA3857BULL, 0x7BCAE75173BD62A0ULL
        },
        {
            0x15BB20C76222980BULL, 0xB53AE324CE6DB71FULL, 0x42E0E19E9B1B79A6ULL, 0x39BFC1C93629F319ULL, 
            0x3F5D49AA14C339CFULL, 0x9407E27D345E096CULL, 0xA8117FB77FE5FA90ULL, 0x4D2974BF0212D9BFULL, 
            0x7A00B053E8A7B34DULL, 0xB41A2500BDAA548FULL, 0xDD126D10AAB583ABULL, 0x570B6DFD80E7F3FBULL, 
            0xF14F27F6B63BECF2ULL, 0xAA4C54B6DB8B28AFULL, 0x86D29AB1EE365140ULL, 0xCE7B2F1E22FF1806ULL, 
            0xDC949BC7CA4F72F1ULL, 0x5306C75546250C3BULL, 0xF56990B80F3B4ADEULL, 0x41AE4A90F0EF9648ULL, 
            0x38A25C959F61E865ULL, 0x1CDF6C9908E65846ULL, 0x2A7C73E986F62C8CULL, 0x68CF5F622B2D9965ULL, 
            0x94810D861B30DF10ULL, 0x61363C3C10ACE5E2ULL, 0x5857977BAC38A9E9ULL, 0x29A7A882CB807C8BULL, 
            0x23945FC062A3B90DULL, 0xA22CCBEF5457670FULL, 0x95120230E8B75841ULL, 0xB7C27BE6EF0F5B85ULL
        },
        {
            0x6A12570D82AFBB3AULL, 0xCB05576E2CE040E3ULL, 0x14BD7EB8AF82878AULL, 0xC534EB95BA07B6BDULL, 
            0x941ADBCC17C4A1DFULL, 0xD7027AE6E0F475FDULL, 0x0F58DE0DC0DABEADULL, 0x70F239536E63CD7EULL, 
            0x21FA7EE4C10FDD43ULL, 0xA396548A8018E9EBULL, 0x68D71BE71FF20FCCULL, 0xB6D86BA3DAAE15CAULL, 
            0xAF2E1A9A81DF59E6ULL, 0x055B99DF623F5952ULL, 0x71A39BD9383168ECULL, 0x87DA6492B2D4FC2EULL, 
            0x9BB2CEED076AF0DAULL, 0x06B7A3F5D1B2B627ULL, 0x6DBC68D90162CDAFULL, 0x00DFECB291A4C2A3ULL, 
            0x4F7C4AFD74745352ULL, 0x6E037E05746D0319ULL, 0xE38660B39E952B98ULL, 0x267CB595D26A58A0ULL, 
            0x655076F221F1140BULL, 0xFB6178762BD7FFE6ULL, 0x02430913EE52CE34ULL, 0x49B5F369E352ADA7ULL, 
            0xDA6F0B25E947E933ULL, 0xCD3097F5745AF1A2ULL, 0x56A19F64C2C822F7ULL, 0x5048260A80E19421ULL
        },
        {
            0x8B6E0282444E6DA1ULL, 0x9B1511195BA01526ULL, 0xE57CE88D7265FAD6ULL, 0x6E3519D480DE4609ULL, 
            0x02C6526BE5F6E8B7ULL, 0x548393BDA3310152ULL, 0x10DCF5139FF17F8CULL, 0xF6E0D4BE1CD988A8ULL, 
            0xC44AE7F59F33CFB2ULL, 0x42E5CA7EA2F1E078ULL, 0xC6EC7BFE2AD1C078ULL, 0xA5526B0C44809DEEULL, 
            0x2E36F70D6128278BULL, 0xBC291E21C66AD50BULL, 0xA50BFB289562C883ULL, 0x9FCCFFAB5B493FDAULL, 
            0x52893B7D9FEA41F2ULL, 0xFAE9DF42C88B6C2BULL, 0x662B3BB5FF73463CULL, 0x2B807EFCD42C3429ULL, 
            0xCD6C9C334F52F5B0ULL, 0x77E97C41F4B0A131ULL, 0x2B4A2BB2E244DC48ULL, 0x7A8A0A25BDC1791CULL, 
            0x4B5E66E6A5A57FD3ULL, 0x3732220942A08854ULL, 0x04C43E3237717739ULL, 0x1B4B67873E64496EULL, 
            0xA4F038D246F661FAULL, 0x644E8A76E708B684ULL, 0xAA302F728D734547ULL, 0x9791B59B7F7CC560ULL
        },
        {
            0x3DD0C40CDA02EE07ULL, 0xC923285F56447416ULL, 0xEF44F538908B85B3ULL, 0x34194595DBAD8F03ULL, 
            0x2BFDC2F2D1766821ULL, 0x6C8BBE0E9658D826ULL, 0xBFBB3380AFA1EB45ULL, 0xBF896ADECF7FBF2EULL, 
            0x538C17CDB03E0DECULL, 0x83B47068878C3DC6ULL, 0x0CBFB81DC92E9973ULL, 0x2BABEDEF1BE7E805ULL, 
            0x6E969728FB8E39F7ULL, 0x9B4F0042BE271194ULL, 0x765360B3D02B71A4ULL, 0x3AD44CCA068FBE9EULL, 
            0x643DB259AA6336EDULL, 0xBD824CEEE36351C8ULL, 0xB2B96ABC2A1955EAULL, 0xE5ECC390BF2286D4ULL, 
            0x8480C86EA1AD213EULL, 0xC8DCB2C4F3733BDCULL, 0xCE4946556B93B3ADULL, 0xAA476B6DF79FB4D5ULL, 
            0xC18735EBB0C6A908ULL, 0x32705A537029EB3DULL, 0x3D44E1D3C9FB2BF6ULL, 0x58312A1FAB3F0FC3ULL, 
            0x461908AABCDB59D9ULL, 0xF2EF7E3320C913D5ULL, 0xBDB32611E8F58CDCULL, 0xA0B81C2EB509DC79ULL
        },
        {
            0x090F19DB6CB38B81ULL, 0xBA149614F8EDBAD4ULL, 0xFBB204E72750679FULL, 0xB023CB99F82A09DCULL, 
            0x69C93FB27E0BE515ULL, 0x6CC4AC85AC24C6EFULL, 0x2CAE8E7CD8438236ULL, 0xD8DFB9B7AD2FB0CFULL, 
            0xAA282B3E7AC8B35DULL, 0x0BF0A9B0A389E471ULL, 0x9678CFC3BAF4823CULL, 0xD1F4FF721EFDA3AFULL, 
            0x3CEE54069C88C2D2ULL, 0x93E9F05769A72C1AULL, 0xED747C986CC786ABULL, 0xD8165DCCAC9E8F29ULL, 
            0xBA15785564A4E404ULL, 0xD85D580FA869AFACULL, 0x655B9815C4A4BE37ULL, 0x4426DA672FF3838EULL, 
            0x63DB01BE757521E3ULL, 0x61DBEF6DC5B2D266ULL, 0x13A82EA29B6BFE91ULL, 0x7A0650F416857286ULL, 
            0x51DECF6EAD2039FCULL, 0xF0C144CCD3A7F21CULL, 0x3884D65077D6F258ULL, 0xF956ABE9469DFBB1ULL, 
            0x7BA78B05ABAB8E7BULL, 0xE4E3131AB0D247BAULL, 0xF681A3A20362CDE3ULL, 0xA0C680E44CD65F96ULL
        }
    },
    {
        {
            0xE793CA281E0C7C21ULL, 0xB63D7C3DBE574C94ULL, 0xCF97456B3835DB5DULL, 0xFE0A65FF2D6C658DULL, 
            0x094E32A6BEA9673FULL, 0x1980699E680E80AFULL, 0x0542F5875A811052ULL, 0xB2974CFE627E024EULL, 
            0xD8D0C5C796612AB0ULL, 0x14AB0A50C2569268ULL, 0x4BAC865903E951A9ULL, 0x00C96029F269668DULL, 
            0x56E684566650BB4FULL, 0xB1F968F426866243ULL, 0x1933F564464BE833ULL, 0x194034E74FA66699ULL, 
            0x1D9949A6EA55AE70ULL, 0xA30023EE100F8968ULL, 0xDAA1D4B81E804243ULL, 0x3238F8FC9DED301DULL, 
            0xC98F368CF730162DULL, 0xBEACE5450D85D466ULL, 0x1C08D5563352AF20ULL, 0xA654CC75ED37BC31ULL, 
            0xC7F3A39E2E940ABAULL, 0x98D207CE45192A0CULL, 0x1D52EBDF17A6345AULL, 0xF32F2E22F89C8507ULL, 
            0xDD0547651F188443ULL, 0x4D1002DE15B71ED5ULL, 0xCF4488945191B91AULL, 0x8E1243508A6F370BULL
        },
        {
            0xD2E9F725DC4909EBULL, 0x8D86089B7250BD69ULL, 0xF58BBC5D2D4DC48EULL, 0x60B991F7D435B90FULL, 
            0x02471E5C7AE05D0AULL, 0x4E7944E8A27ECF3FULL, 0x44AED543A44EA32CULL, 0x31BC4E73C55DA33DULL, 
            0x67F6A85FEDAD7A4FULL, 0xFD2CC3F735BD5B0CULL, 0xAA4D5C3016ECF089ULL, 0x94AE3B6975F7E3B6ULL, 
            0x1F93C3026BCB6FDDULL, 0xF3AFECEECD6BFDBEULL, 0x36648517120D488FULL, 0x2163A7C004C70373ULL, 
            0xC4D9CE370E6DD631ULL, 0xF14924D39A36F717ULL, 0xB194A08D60A39F85ULL, 0x05B62DCE8D65B896ULL, 
            0x64EC48369319860FULL, 0x618D3980845A616CULL, 0xF51330206F0549DFULL, 0xFCED4CA6FFD6F303ULL, 
            0x38B06E5D9928FEC8ULL, 0x8F8D8294807C1E27ULL, 0x9488C53BBB44C071ULL, 0x63968C0EA563E38CULL, 
            0x063C17A98FE93EEFULL, 0xD8FA52460E68B62AULL, 0xD6BB91085A9E1A29ULL, 0x96722DBA4891B48CULL
        },
        {
            0xB4A1C146348B424AULL, 0xB3F838F5C2E4B32CULL, 0xC5E030AFFBBAB6B3ULL, 0x2AB02B8EE529528DULL, 
            0x30D7424BE0C4D66DULL, 0x4572137FB52E7554ULL, 0x5F53A36E121447D1ULL, 0x25915D0AD5DE7C10ULL, 
            0x39B6F4AFCCA4C17CULL, 0x0EA762E5BDD55F4CULL, 0xF68D974CF70728F1ULL, 0xC70FFBEB40F0548BULL, 
            0x4624F213BAA5D71FULL, 0xDB8862B279282C72ULL, 0x4AD98BF9FFB6904CULL, 0x08A7E01718B0789FULL, 
            0xE16D078408E1109BULL, 0xF9BF443983E5D696ULL, 0x4F0C85047F034385ULL, 0x50E2959AD7E9DD64ULL, 
            0x6A6A3C7BA9CCA2E5ULL, 0x53A2DD708D4E2031ULL, 0x61E98AE19E70A8DEULL, 0x56DD3460CA7B154FULL, 
            0x56E2994A2163D0DDULL, 0x954BD158FE1DE111ULL, 0x54D3EE0AEDC82FFBULL, 0xC8CCBA0FCD59D2BBULL, 
            0xF56A0B88881D90B1ULL, 0x9AFE25DEF05ECC1BULL, 0x2B9A7F5F2FFC8ECBULL, 0xDCECE83FE53B3616ULL
        },
        {
            0x1D0D878BA02FE4D9ULL, 0xB1C1EBC9CE5871DDULL, 0x3813ABC83DC17D49ULL, 0xB3D8742043010EB3ULL, 
            0x291617E8A0C6E94EULL, 0x511D516E26B8C26BULL, 0x47C08B01FCE7DA67ULL, 0xCE94C3F08741A153ULL, 
            0xF9FE62B7BD1BAD4BULL, 0x703B03C174D8EA71ULL, 0x15907ADFE22C9994ULL, 0x0C652184D8ED6364ULL, 
            0x0208241358B67B8AULL, 0x5CB6EAA5791434FAULL, 0x4945977851B8DB4FULL, 0xBBB47EA7A8DED94BULL, 
            0xCDDF685AB595295EULL, 0xBE70FDFC0EA52DA5ULL, 0x2E42312AAE169BE3ULL, 0x692BE56F8048C116ULL, 
            0xD1C7B447BEB40ECEULL, 0x8153DE2739239A3AULL, 0xE2800D48E62B09A3ULL, 0x8C812F6DF2ACF3C2ULL, 
            0x979CE5FA2A6CA183ULL, 0x95C9417DDF05094EULL, 0x5205EF8B9284F74CULL, 0x40D31D425CF4C064ULL, 
            0x84FFF52106E186C4ULL, 0xC5D81A3E35EE167AULL, 0xD44035BD7D6E8389ULL, 0x85088ABBA0EB2103ULL
        },
        {
            0x8CAA3F32C70591AEULL, 0x9E711094A1EC9B76ULL, 0x198A688CC433B9EBULL, 0xCB38F11CEE13F520ULL, 
            0x518E9999232615DFULL, 0xD63901CCCA27D3F4ULL, 0x4B46EFC35E26D065ULL, 0x324886687A68FF5FULL, 
            0x01E26D6AFFBD1B93ULL, 0x052DD78EE4E8444DULL, 0xAA6BDD217E0B2CB5ULL, 0x399B397B9B62B4DAULL, 
            0xB40B7EDAF0C1FA12ULL, 0x749F8E5F40A3D8EEULL, 0x4494FDECC284E81DULL, 0xA76265172AE26927ULL, 
            0xB92398ACFBA43DA4ULL, 0x2F0E831F9C9742D0ULL, 0xC3DD47AA2DA386BCULL, 0x7B2480DFFAF62ABBULL, 
            0xDF331180CDD3FACAULL, 0x5A05ABC22B097611ULL, 0xD5081C3DC1085119ULL, 0x58D30541BE169EE3ULL, 
            0x5C20099C170A53B7ULL, 0x3004E4B1045064A6ULL, 0x8DAEE9047F99ECC5ULL, 0x56E90347B0032095ULL, 
            0x0C345A4F0E159B11ULL, 0x7933B067A5BE0125ULL, 0xE99114743D52444AULL, 0x9AB673585144A243ULL
        },
        {
            0x7A0BA8437B96B9A3ULL, 0xA4C6EBB09891EA37ULL, 0xA7333BCC34A72472ULL, 0xBDB2AABD49A4362FULL, 
            0x415CBF2A4F2895A1ULL, 0x8E54B0539E9E1C80ULL, 0x3B1CFFE61A6EC3A3ULL, 0x7C71BD41E58EC4E5ULL, 
            0x94A48804D4E767CFULL, 0x3AB57CAA178CC96CULL, 0xEBAAFFD559EB84CDULL, 0x220349824E260EBEULL, 
            0xD7B80DD7F2C90CBEULL, 0xF82171E93487724AULL, 0xDEA391F8A7D3B002ULL, 0x103FF2926C40B874ULL, 
            0x65C7112B78AD546EULL, 0xD50C4574D0218F9DULL, 0x273B581098C6D252ULL, 0xDDC9F2DAAF86A754ULL, 
            0xCC782FBF37639DBFULL, 0x31CD2B179D93816FULL, 0xBDA8A33BB6031EBDULL, 0xED28F3266F333EECULL, 
            0x7ECCD4007712D92CULL, 0xF83F2EF7C1724C2BULL, 0x42242071E0E03F54ULL, 0x0967971E9467539BULL, 
            0x0D325B8E95B383C0ULL, 0x44F7C363DCA7EECEULL, 0xEC2B9B3205B9A4D8ULL, 0x26B3947945DF1CACULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseGConstants = {
    0xE1EC3C70AEB97F29ULL,
    0x6E4994F6AFD4FB39ULL,
    0x5A1E1F6EC4DB0734ULL,
    0xE1EC3C70AEB97F29ULL,
    0x6E4994F6AFD4FB39ULL,
    0x5A1E1F6EC4DB0734ULL,
    0xD92FA90BB7C96D6AULL,
    0x67B69BAC581F9EEFULL,
    0x48,
    0x2E,
    0x0E,
    0x98,
    0x9D,
    0x83,
    0x7F,
    0x0C
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseHSalts = {
    {
        {
            0x375D03B1E4F3069CULL, 0x4D96E3CC4D4BA736ULL, 0x110D03E71453F8ABULL, 0x4660053EDB327C6FULL, 
            0xB6CFE6C521534A7DULL, 0xB02D8998FF4DF351ULL, 0x6D5C5A287E5D39C9ULL, 0xD6CE70C7334A67A2ULL, 
            0xC487166BAB48282EULL, 0x6FFFF13E326E933DULL, 0xA20E56DA1F4C4C1EULL, 0xA8552DF65930931DULL, 
            0x9B79CCF2F796BC68ULL, 0xF3A947BE26C5A8C7ULL, 0xE73B11014C99A1D0ULL, 0xA469EC0D5EBD4EDAULL, 
            0xE8F68EE7DB16113DULL, 0xCD60452292FB6ADAULL, 0x4184DCB93F5B782EULL, 0x6F93F95265C28581ULL, 
            0x0E22B2A4D62452ADULL, 0xAC2989676618BEFCULL, 0xEEB11F04CE5A1D07ULL, 0x8B4BC3B5D209E486ULL, 
            0xFC3996CC07F8466EULL, 0xE78DFBD1B7ED0CB1ULL, 0x53071D5B1EE69A95ULL, 0xD4DF740F89618E44ULL, 
            0x442DB0656B9AD06BULL, 0x188C24A577BA2C52ULL, 0x4F8368EEAFEE36A2ULL, 0x9EDE823ECC47E6CCULL
        },
        {
            0xBAD37ECB26792A8EULL, 0x444E37F40C07C677ULL, 0x82368ACF6CE3726FULL, 0x5EF0AFF1379C28CBULL, 
            0x283E15EFCE92D568ULL, 0xF9F953366A7DE545ULL, 0xB5FE9D550EBA7B43ULL, 0xD4D407CD05E7C2E6ULL, 
            0x7EBB7CB3329599A6ULL, 0xE8298D5ED59DCFEEULL, 0x9567701DB454F0A5ULL, 0xFEDF8CFE58150FC0ULL, 
            0x55810251C9F25205ULL, 0x76E88E88A7AB41E7ULL, 0xD5E1266585045AA5ULL, 0x3D8CC2D27AC3A302ULL, 
            0x6135F4236AB835ADULL, 0x481E9964804757D9ULL, 0x5A7197A2E1897511ULL, 0x5BB1AAA1313E1C92ULL, 
            0xB2FF3839D8F062AFULL, 0x7AA5471310EB703FULL, 0x9D252748CC157524ULL, 0x7C7F11EF9DFFED3BULL, 
            0x9C33356320F53AFBULL, 0xF3C46AB41FC4D251ULL, 0x22133E98FEECAB8CULL, 0x72549DE62D8751FFULL, 
            0xF00C5C2F1F68C7B3ULL, 0x058489E9C9B0095BULL, 0x6BBA56194AC3820CULL, 0x72F175B7EE4098DDULL
        },
        {
            0xA96E6E9A931541A8ULL, 0x95201F96AE678743ULL, 0xCDFB06C216C37123ULL, 0x0F377BF2ADAC46D8ULL, 
            0x7F37F0D4985E7791ULL, 0xD2EE5580A4A4508BULL, 0xBD88CDCB8F08FD59ULL, 0xB8217EA1069A5EAFULL, 
            0x5D900A6C773F80D6ULL, 0xD36E25D476F21151ULL, 0xB11D82ED5CB59D9DULL, 0xBC890474C479513AULL, 
            0x66770B83C55F2B41ULL, 0xE848A70BAF4AD28DULL, 0xF939A0F5263890E2ULL, 0x4A7E736ADFD579C2ULL, 
            0xBD91264B4F7B6E95ULL, 0xA593A2DF89BA8448ULL, 0x5FA152FDDCB4FDF5ULL, 0xC58EB9FF6EAC9867ULL, 
            0x0831F7AFF91D9264ULL, 0xC64326244B586089ULL, 0xD0FD226D5278C42AULL, 0xA0ED253AFFDA0B08ULL, 
            0xE0E4F8641263321EULL, 0xAB678A12465C5D23ULL, 0x744C38383EDD1529ULL, 0xEEA2F547027BE04BULL, 
            0x3597CA4305DA2102ULL, 0xED191EEA3556CCD1ULL, 0x6163086584D798FCULL, 0x77A59A945EC207FAULL
        },
        {
            0xC20E8AA39F579FCFULL, 0x67B81CE118BE5CB0ULL, 0xFDA308D648C15830ULL, 0x2B41B3A0AAE9657DULL, 
            0x5ECB4389EB2D71F2ULL, 0x40D2D170260062B2ULL, 0x9A6FFE425F826842ULL, 0x0F1DB03777FC80C6ULL, 
            0xB3C074B35E99112FULL, 0x898685B8235D0423ULL, 0x8DB0EDC4AE3F11E3ULL, 0xD15552A3EB4471C4ULL, 
            0x7B89701EF8EF9987ULL, 0xD72A8FA35F73426BULL, 0x921289E03F572F1CULL, 0x00CABE3398CAC8B9ULL, 
            0x6837A9A1CB54E9E2ULL, 0x41DAB5F631ED84C6ULL, 0xF135E46B817DB386ULL, 0x142ACCB02131BC05ULL, 
            0x092F92BFC12C9401ULL, 0x4545803D3AB7F451ULL, 0x78D5E2B85B287F4FULL, 0xE50609EB4A4155E6ULL, 
            0x997FBB3D44A501BAULL, 0x400D58C6236E94D5ULL, 0x29C6326FE33C7F49ULL, 0x7B81D2E4F29A8C81ULL, 
            0xBF7C99A996B4997DULL, 0x691462B3BEB0D3BEULL, 0x0B74F604CD1565D2ULL, 0x89BD2D0D59D843DAULL
        },
        {
            0x2E5CD05459959A0BULL, 0x21E37E94C06A5557ULL, 0x7C25D5B6530B3D37ULL, 0xB2AF468BD738DF2CULL, 
            0x9F3453D2F09B19CCULL, 0x58B4081FED90DD6CULL, 0xFB45A39EE8B1C39DULL, 0xF344177D8FC36F87ULL, 
            0x1BD4D9BA5E71ADE2ULL, 0xDC5BB3BED2044180ULL, 0xB3C656E90D5ED2C4ULL, 0x16CF638F7821780FULL, 
            0x344D569882DC463BULL, 0x3722A2C396FC270DULL, 0xFCE923F41D5CCF74ULL, 0x7FB41817C7656BC6ULL, 
            0xEC1EAAB8A15B0F06ULL, 0x67EC7B9FD9479579ULL, 0xB6D9EC5DB1AA91F0ULL, 0x6E0909D4BBCD783DULL, 
            0x8A08FA889B8289E6ULL, 0xDF536F063A371B4AULL, 0x25D3AEEBB348EF2DULL, 0x4843AF264247E2ECULL, 
            0xED6FD905AD589E0FULL, 0x18416B92FAA779F7ULL, 0xDFB738D80BCBA2E6ULL, 0x192108DEE63D56C5ULL, 
            0xBC04A196EF3B519CULL, 0x4890051219C2E310ULL, 0x3016C157F4FD287AULL, 0x70CCFBC8621A1CBEULL
        },
        {
            0xBED9A0150CBFAE28ULL, 0x7ABE263A8556ED82ULL, 0xA5597A73ECC51C6DULL, 0x867C03F0973EF8D3ULL, 
            0x463C7449C1BED31FULL, 0xCE7B9108FE38B7FFULL, 0xA1D6F0EADED81D94ULL, 0xF8FD4BCA1835FA04ULL, 
            0x9A547791AEB3CAC3ULL, 0x04027FC5BE7FA375ULL, 0xE4565899918F4D37ULL, 0x3DD24CE65614BBF8ULL, 
            0x981424C3559642FCULL, 0x4ABA53CEB7C71280ULL, 0x5B395490821B0873ULL, 0xCE8A1529C65D7D94ULL, 
            0x4CF51352DFB09F0CULL, 0xD75D6FD95F6122E7ULL, 0xD27E460E38E60E62ULL, 0xA388FDA69D0DFCE7ULL, 
            0xB1393182B7181B3AULL, 0xA46DE18CFA50EEEEULL, 0x47C4436558C88E5EULL, 0xC5509151AE3A167BULL, 
            0x3123FC4B5E9AD3BBULL, 0xDC296CC6FB0D3802ULL, 0x399E0AC0A4511820ULL, 0xFF6DF199B74A5E91ULL, 
            0xC158E3FA21E51C04ULL, 0x522876BFA9C985BAULL, 0xB322E324AA68C4BDULL, 0xBEF42D180EA07618ULL
        }
    },
    {
        {
            0x906B124B4ED74746ULL, 0x4A64A1D957D83F5AULL, 0x7810BD27608C99CCULL, 0xF0FFE7043E618D39ULL, 
            0xC56F58A91F8B43C3ULL, 0x7496EA91A09A5DCAULL, 0xF807CD88F15C353FULL, 0x47C447ADB4C27846ULL, 
            0x227F881E67C1EC3FULL, 0x4FCFCAD5E2AFF7AEULL, 0x8549E2878E97BFC0ULL, 0x76B28B5F9AA8D3C5ULL, 
            0x5D3F95AF60FFCBEFULL, 0xF1E1870D19D8B748ULL, 0xC812DFBE115A338AULL, 0xF7E48F17172E3341ULL, 
            0x2833993B9804DA63ULL, 0x1A03E306A3A98564ULL, 0x96DA2092D535B5EEULL, 0x35B59E7D5B6B3A6CULL, 
            0xA6A36842B0096F74ULL, 0xA08C020119FB55ABULL, 0x814B2F18C83DF7D8ULL, 0x38DCEFBBA4AA1DA4ULL, 
            0x101A7ED69067839CULL, 0x129E163BAEF06EB7ULL, 0xC1B27FC984A307D1ULL, 0x7F5C2E6C0E73AAE8ULL, 
            0x38B7010AF057199CULL, 0xA8AB3034B0EC8040ULL, 0xD464BFE7497D9073ULL, 0x7A1763C0FA8B7542ULL
        },
        {
            0xA8D2ECBB59308D26ULL, 0xB305F98FC99ABF4BULL, 0xD2FFED1B54B62466ULL, 0xD7765BCD3E4BCEECULL, 
            0x2944AE21B96B6B7EULL, 0x9D5126A1C84A2587ULL, 0x3B863953488FC4E5ULL, 0x057AB8B5AB859A57ULL, 
            0x3C4E1B13AB7E88CAULL, 0x37B229FDCDC168C1ULL, 0x3D283755BD60F048ULL, 0xB5417C511A4AB2AEULL, 
            0xEF09FC2908DDE7AAULL, 0x468D7CEA5AFDCFBAULL, 0xDCF8AFA93F1472E5ULL, 0x620DD864C3655AE6ULL, 
            0x7816A3F60BB63A4BULL, 0x5730C5E7DCA12706ULL, 0x8F959573683C553AULL, 0x238C9AB904267AA4ULL, 
            0x6096C5A02758BF61ULL, 0x0391A80795264EEBULL, 0xA68480CBDDD5511CULL, 0xA4DBA708983DB223ULL, 
            0x0ECFEBA5AA4D2D14ULL, 0xC82AB7199F67289AULL, 0x2F936A432BBE8853ULL, 0xC2187C3505AB8F32ULL, 
            0x4DCC56B1458DD6B9ULL, 0xCA129062BF1D48A6ULL, 0xCAF22E92B776F9B9ULL, 0x3A8E252FE1152EBDULL
        },
        {
            0xCFA27CCC4928BE55ULL, 0x6DD109251EA28287ULL, 0x92CC0A2F7FFECF56ULL, 0xCF695EF498F02A93ULL, 
            0x1DAC289C5049E1C8ULL, 0xB3845143ABA7E08AULL, 0x34E4CC4D344617BCULL, 0x62E0AE301787B551ULL, 
            0x0F29D332C8C5B20FULL, 0x6C5284454E6B1255ULL, 0x1E376C683EAD2A51ULL, 0x44E3F3C721E7B953ULL, 
            0x3669E3DF6FCF066FULL, 0x68315D9D0E57C25EULL, 0x26C0C000C5F8CE78ULL, 0x828DA5C241802EE8ULL, 
            0xA8BCA496A42903BEULL, 0x102811737CFE0FA5ULL, 0x913849531B15411DULL, 0x51C0EB494DF2D8ABULL, 
            0x2A4F0173598ED842ULL, 0x7F5A5D906BEE9808ULL, 0x167DAF502758F00BULL, 0x51360149E43A7060ULL, 
            0xFAE3B945CE7867C6ULL, 0x6C111CFBA87AB4ACULL, 0xC722ACDEA10FD768ULL, 0xC4B52BE9B9C07402ULL, 
            0x8BCA02C1FE83E8A4ULL, 0x95E199840790C320ULL, 0x66213FB5559289CBULL, 0xA12C4F8192FD6BE8ULL
        },
        {
            0x6785F21613235844ULL, 0x5037B81F2C7AFE1AULL, 0xBCB1D329A2725807ULL, 0x23BDA188B6978C73ULL, 
            0x62EDB7831B7B43F6ULL, 0xCC47872BA23C5174ULL, 0x4D4C9D59E3B62988ULL, 0xC3CF0C0E808622B3ULL, 
            0x0A5540BFB592EAE7ULL, 0xB512ECCD34497EEEULL, 0xBAB6E0A45D05A865ULL, 0x367CC7740485E7FDULL, 
            0x563C84FDBDEE28EAULL, 0x4C405E47265DFC0CULL, 0x8CC333705DF2113AULL, 0x00B27653A75159C2ULL, 
            0xE9A1260B79A72008ULL, 0x1948CFB2FDA13D59ULL, 0x80AA065CB86530E6ULL, 0xAD32D45F570A7374ULL, 
            0xB5738E67E2A73593ULL, 0x1FAC701927F4BDA8ULL, 0x0A92A5FA5F463D6CULL, 0xDAC09088977F5968ULL, 
            0xB55C796AF623DB9AULL, 0x74A277C456299FDDULL, 0x97FA6F0A9030BF00ULL, 0x684F1C38520B851DULL, 
            0x6CC2C78E0C47CC7FULL, 0x103151A82D0CE18EULL, 0x1D2A410E2FFC5474ULL, 0x61C5E0FA504DFA0AULL
        },
        {
            0x9279F734D6D3DF41ULL, 0x751FCF57A7758183ULL, 0xE3CD7891F7DAE043ULL, 0x369BD286DE281955ULL, 
            0xE108DDA3286221AAULL, 0x7BB959BE588E93C9ULL, 0xCE8B3B3B8EC2416FULL, 0x78D237D2C242BE76ULL, 
            0xD50103C68C4B1ECFULL, 0x152050906589C1EFULL, 0xA0F4CEDC50624FFBULL, 0xD5AFAA5AEBADA520ULL, 
            0xD9774AA4F042CF16ULL, 0x130B69712A550F7CULL, 0x5E1FA7C9C3764106ULL, 0x8E0AE02C63C6E921ULL, 
            0x73B61D15D51B0B12ULL, 0x15D89DE92CC5C465ULL, 0xE78B8294D7FF3B55ULL, 0x3AE5CDCC4CEE4ABDULL, 
            0xD97F6B06B9297830ULL, 0x166C0EE69D46BB5FULL, 0x0F8F41333AB32D37ULL, 0x51486F630D5DADB1ULL, 
            0x76C4B93F689E0CDEULL, 0xCDA86D5A67DBB9F8ULL, 0xB2AB55B815FE642EULL, 0x4D1E6A28D5304224ULL, 
            0xFCB0038705EE54BAULL, 0x17BEB8FE7EB4C644ULL, 0xDACDEB25DBD68852ULL, 0x166FB9990A3DE726ULL
        },
        {
            0xD63999EB2BE57BAEULL, 0xA9AF5F031E143250ULL, 0x53B22C679BA68F14ULL, 0xC448B48DC894D045ULL, 
            0x8C2EC4F59035B11BULL, 0xAD4383F0493AF664ULL, 0x93AF87588813DCF0ULL, 0xA4413BF9FAEF9B7BULL, 
            0xDCA8304F181AEE2EULL, 0x61EE7CDA7CBEB70AULL, 0x51F382F89CFA1EB8ULL, 0xB3CAE435DE786248ULL, 
            0xFEFB32924EBE1A9FULL, 0x98910A925EB5051FULL, 0x4AA3BBFD7157DAD4ULL, 0x09727FFB795CE657ULL, 
            0xDF31557A83E836CDULL, 0x1AB7FDA152893967ULL, 0xACE19D1ABD94C60FULL, 0x78CD7EAB3C32BDA0ULL, 
            0xFAABCC0666B7D598ULL, 0xBFAEE8A3EA62D2F0ULL, 0x249386368B307472ULL, 0x8BB73770D73C48F7ULL, 
            0x11E4F4884285A842ULL, 0x9434C9B110ADA274ULL, 0x83DC1B0D391B6731ULL, 0x66BBCBFCD6934B47ULL, 
            0x3140DFAB30DB5DC7ULL, 0x28DE7D3A84BB298AULL, 0x2821292AA7563937ULL, 0x6AC018602358F3DAULL
        }
    },
    {
        {
            0x6D57174DD8ACAA67ULL, 0x6DBA84A5F99B3C4DULL, 0xA46AC9187CB09B39ULL, 0xD68C9E5342BCCCD6ULL, 
            0xBF79A92725AD0091ULL, 0xAA34FC06AFEC1DBCULL, 0x3C950CBC98952491ULL, 0xDC04BF4686C49CEFULL, 
            0xEE357A9F78B0B6FEULL, 0x602A34E45914EACCULL, 0xB3D5A7F6B85D28A3ULL, 0xD7EC9930FFDA7BBCULL, 
            0xE2024975BC9CF470ULL, 0xCECBC79AB460183DULL, 0xF6D2AAC7D5474584ULL, 0x968E3B7A96250FD7ULL, 
            0x70F7097846C2063FULL, 0x082750BCC58A32A0ULL, 0x8AF18E1C2668278DULL, 0x3B521DEC6AD445BBULL, 
            0xA1A77621C568CCA9ULL, 0xBAFAE7321CC66384ULL, 0x292C62520D053D5EULL, 0x7C5F2E2D0470165BULL, 
            0xC78B08CF39A8404AULL, 0x840A42398768D22EULL, 0xC32A097671837C8CULL, 0x0928F15C363FDDC1ULL, 
            0x7456CF8DB1B5CB5FULL, 0xCF83600CD05C2EB0ULL, 0x8EF5729CC83BBD1AULL, 0xB1DFCAE3FA146C09ULL
        },
        {
            0x147AD329E9994518ULL, 0xDC4655B117530B01ULL, 0x9D0CE0B31A497390ULL, 0xD22F4CFE4B0FA97BULL, 
            0xBE87A58DA3F58DF5ULL, 0xDBC484DCB0F007FDULL, 0x04DE8C50EB9EF902ULL, 0x5F7DBDDC51EE39A4ULL, 
            0x6A4D5F060D70C4C8ULL, 0x36835360DFF351BBULL, 0x0B52FA512C7A7768ULL, 0x181753676D9DF7EBULL, 
            0x9320E5EE96274BF4ULL, 0x5C093A906BCB0272ULL, 0xD468C7139562C243ULL, 0x5B5364E1B5920E30ULL, 
            0x571B8D14413E7526ULL, 0x23DB76FBF035AE3DULL, 0x50D6203C7665709BULL, 0xBDF1E91CE65FF2F9ULL, 
            0x5538965FF5B01392ULL, 0xF90FFB2EF63386B7ULL, 0xA6F9446801CB2CBAULL, 0xF0A9A47172C1DB70ULL, 
            0xB5B128B2F2F2BCCBULL, 0x6D5E5D341E310505ULL, 0x88AD2A9E42AB0662ULL, 0xFA7853B8D32F9BB9ULL, 
            0x58487EC1FE7B0132ULL, 0xD56CD9553CF83386ULL, 0x896E84269F336298ULL, 0xC8AFAEB45E41F5B3ULL
        },
        {
            0xF1A4DE291E0B7E13ULL, 0xAA36BD09888401D5ULL, 0xA86C3CAF002D8B14ULL, 0xD5E264CDCBE3219CULL, 
            0x5FBA89F5A466E0B8ULL, 0xE7D8B31977DE531BULL, 0x86072B19603CE1B6ULL, 0x84F2469D4D356D3BULL, 
            0x2D8CBF92817F2DD8ULL, 0x31430FD3762CB53DULL, 0x3BD406AE80733833ULL, 0xF65DA4F2AB065DD9ULL, 
            0x77C3F6773F3FCBC0ULL, 0x4FCD3AEE31A56132ULL, 0x9DAC7078AD71337CULL, 0x2D60E0E5BEBDFB1CULL, 
            0x3D5293185E7F7899ULL, 0xB2D36C1A3973BCC8ULL, 0x56CF2385BB714162ULL, 0x1D5D010904D6FE2EULL, 
            0x3D9C93062FEF8BC1ULL, 0xA79234951F2F99E2ULL, 0x0A82A186DAC1566BULL, 0xEE9F80C2EE03DFE7ULL, 
            0xB08E9E97711C579FULL, 0x73886234C6E0A111ULL, 0x3ECA70F6FB391109ULL, 0x5D59722737441E3AULL, 
            0xB7123ADBF208E68EULL, 0xABC1C088CA8422F2ULL, 0x29027C6611B6D754ULL, 0x6283AE6E419AFCBFULL
        },
        {
            0xEAE29A9CFF3EE7DDULL, 0x1919ABA8A62EF292ULL, 0x60789BC454F2AB53ULL, 0xFE998930B9016D85ULL, 
            0xB0E519DA23EA9DEAULL, 0x04598337B90E06E8ULL, 0xB1CAE13E85110ED4ULL, 0x5A74E7A1840F6123ULL, 
            0x61B011A69879096CULL, 0x751EAFA99CF79168ULL, 0x06FD24F1E58D27DFULL, 0xE388410DE0F8538CULL, 
            0x586B4ED8969D4EDFULL, 0xEA1457AE09EECDB5ULL, 0x124DDD6734506849ULL, 0x9B17000030B672AFULL, 
            0x41843F40E903E5CBULL, 0xD30EEE0B555D057AULL, 0x5D675A76BDE13FDCULL, 0x594C1CFD1A4291D6ULL, 
            0xE43C897E0D46A28CULL, 0xA3ACBC092076C52CULL, 0xB3D45E5843AA9D64ULL, 0x06D0180FCF98CE75ULL, 
            0x0C320C0D2682DBAFULL, 0xEC47308C9EC6E89BULL, 0xF44344C9FF47DDE1ULL, 0x81A5DA6507CBA395ULL, 
            0x261ACC85916B38F2ULL, 0x2E87DE890BD30881ULL, 0x13E02EA8051CA645ULL, 0x96CD2EA6570EAE85ULL
        },
        {
            0x59A6ADC1A0BFDA1CULL, 0x995129390B33F288ULL, 0x32399D3EA1894456ULL, 0x134FD3BAA6BBAD72ULL, 
            0x4B9FEE2B599B4945ULL, 0x36FF65DB10744994ULL, 0xF059E0D2A40275D4ULL, 0x7AAFF3AE472797ADULL, 
            0x9E1EC797CC04232DULL, 0x9DF555B710A16E0BULL, 0x8606FBB96AD09768ULL, 0xC640B7D293D7CE48ULL, 
            0xDF971CE33108C81EULL, 0x41F44E85CFCFCC8CULL, 0xC6807E535AB17870ULL, 0xAEEF43EEF38CE8E5ULL, 
            0x83C57894439CB9B9ULL, 0x749FDFED17BA9A41ULL, 0x700717126BC0EB75ULL, 0x51CB00ED91A54F6AULL, 
            0x0A941270D193A4C5ULL, 0xC66A95AB4EBAC350ULL, 0x06727F0996E5BCFAULL, 0x83EBAB8E3B29A50BULL, 
            0xC66AA5823C269C8FULL, 0x0B9BAFC733D8A331ULL, 0x91064F739CD5B3C3ULL, 0xE1B3ADC012D1F8C2ULL, 
            0xCE8C8068A960640AULL, 0x7D71000D431A551DULL, 0x5EE9B17EEDAA395EULL, 0x528FFC5E054E15EBULL
        },
        {
            0xE448154C2E747FA8ULL, 0x72BA5B9412BFD7E1ULL, 0x4CB767826B9BBEE3ULL, 0x47320330FF54D617ULL, 
            0x5629C9AC3A5ABAE3ULL, 0xDA140223A6292714ULL, 0xE71E5D315E7F66CBULL, 0x7E644BCD51709847ULL, 
            0x89B81587A092278DULL, 0x289916ADF90FDC37ULL, 0x691472498BFE3665ULL, 0x089712C2FBF75237ULL, 
            0xF186F39C946DB6B7ULL, 0x608D29612BF0F054ULL, 0x9C680E0C8D965180ULL, 0x3EDD8E1BBCC5C8E8ULL, 
            0xEFAE5FEA64DB739DULL, 0x78BEC9AF48367145ULL, 0x9105D97BEBB15FA0ULL, 0xA06B5B01A7DCAFABULL, 
            0x29FCCC73E6D8191AULL, 0x2122ED720A25D29AULL, 0xA80B5633781373C1ULL, 0xC5DF82C2921CFFB3ULL, 
            0xD5EF2FBE028E5DC6ULL, 0x13321EDB52C1E80EULL, 0x18974494512849F0ULL, 0x0472A319F21F0289ULL, 
            0x506E04922B9C786EULL, 0x00077EF521788B42ULL, 0xDEFEF681A280B879ULL, 0x81032576EECAD0D7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseHConstants = {
    0x275BEC1F07A70E5FULL,
    0x05CD67974641DA67ULL,
    0x550A7AC6EF6A9C3BULL,
    0x275BEC1F07A70E5FULL,
    0x05CD67974641DA67ULL,
    0x550A7AC6EF6A9C3BULL,
    0xF9214CCCFEF7B5DEULL,
    0x599F5123C329DF3CULL,
    0xB9,
    0x1C,
    0xE8,
    0x8B,
    0x87,
    0xF4,
    0xBA,
    0xD3
};

