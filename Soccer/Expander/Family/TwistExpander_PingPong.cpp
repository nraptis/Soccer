#include "TwistExpander_PingPong.hpp"
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

TwistExpander_PingPong::TwistExpander_PingPong()
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

void TwistExpander_PingPong::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x95282AB4E1D97A39ULL; std::uint64_t aIngress = 0x8A96603E3348FBC3ULL; std::uint64_t aCarry = 0x8DB25C68F6DA9B86ULL;

    std::uint64_t aWandererA = 0x949C8A6077297EA5ULL; std::uint64_t aWandererB = 0xA45E6BCAAD92B3DBULL; std::uint64_t aWandererC = 0x9E09A6F1EED0956DULL; std::uint64_t aWandererD = 0xC50202A080E71F3DULL;
    std::uint64_t aWandererE = 0xA19F7381D76BEE70ULL; std::uint64_t aWandererF = 0xBFF9E9BF5CC25DD9ULL; std::uint64_t aWandererG = 0xBC32D43D36D42C20ULL; std::uint64_t aWandererH = 0xC76AAB927AC47B24ULL;
    std::uint64_t aWandererI = 0xEF3BD9279402A518ULL; std::uint64_t aWandererJ = 0xE5114002950B6C50ULL; std::uint64_t aWandererK = 0xD0490D3E1914865FULL;

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
        aPrevious = 16646818369245940971U;
        aCarry = 13120107483930481456U;
        aWandererA = 15851301148179586306U;
        aWandererB = 9338157189557070179U;
        aWandererC = 13944241018555812570U;
        aWandererD = 14062487443319958804U;
        aWandererE = 9782745135178089192U;
        aWandererF = 13268665743519566531U;
        aWandererG = 12130885958986221551U;
        aWandererH = 9896562105701376755U;
        aWandererI = 11558914497721137416U;
        aWandererJ = 16260275291147731827U;
        aWandererK = 9451730775598465232U;
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
    TwistExpander_PingPong_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_PingPong_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_PingPong_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_PingPong_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_PingPong::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x8BF5687EA8AAC696ULL; std::uint64_t aIngress = 0xF96E14DE59A9AA3CULL; std::uint64_t aCarry = 0xA547AA3ADC4C6044ULL;

    std::uint64_t aWandererA = 0x947F0E449854FDB5ULL; std::uint64_t aWandererB = 0x84A537718AA40CC7ULL; std::uint64_t aWandererC = 0xFF10F4654CB9A503ULL; std::uint64_t aWandererD = 0xC0180C93C9269FEAULL;
    std::uint64_t aWandererE = 0xFC7459897CF8597FULL; std::uint64_t aWandererF = 0xC922F22CB2A8AB8FULL; std::uint64_t aWandererG = 0xD143A5B291A334ADULL; std::uint64_t aWandererH = 0x8807E46760804324ULL;
    std::uint64_t aWandererI = 0xBA34A2F81EE5723AULL; std::uint64_t aWandererJ = 0x8C7B5B8546EFB766ULL; std::uint64_t aWandererK = 0xB92930AC5A037E47ULL;

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
        aPrevious = 13974590428674763803U;
        aCarry = 14529460542309514948U;
        aWandererA = 16986991113107907112U;
        aWandererB = 13573476304067646135U;
        aWandererC = 12014808198277445104U;
        aWandererD = 13502231440767343642U;
        aWandererE = 11041022411869866477U;
        aWandererF = 14046433296796570686U;
        aWandererG = 17733982834383948418U;
        aWandererH = 14881006806030631956U;
        aWandererI = 13290507893638555328U;
        aWandererJ = 15290038636747104497U;
        aWandererK = 18174963428457416889U;
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
    TwistExpander_PingPong_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_PingPong_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_PingPong_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_PingPong_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_PingPong::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFD2008D4E2170B24ULL;
    std::uint64_t aIngress = 0xEC3181389556D300ULL;
    std::uint64_t aCarry = 0xD78FCF684C54BD7DULL;

    std::uint64_t aWandererA = 0xE41E898CD13C9634ULL;
    std::uint64_t aWandererB = 0xA8B704490C8B9184ULL;
    std::uint64_t aWandererC = 0x86993C8F3A81947DULL;
    std::uint64_t aWandererD = 0xE1FD93074EAA6DC7ULL;
    std::uint64_t aWandererE = 0xAAFABE571852B43FULL;
    std::uint64_t aWandererF = 0x8B8627195EF47526ULL;
    std::uint64_t aWandererG = 0x8C98D2E2AAA42D38ULL;
    std::uint64_t aWandererH = 0xEE9842939E056F38ULL;
    std::uint64_t aWandererI = 0xB2DAB9AA672A4802ULL;
    std::uint64_t aWandererJ = 0xD3BE19A3D285BA91ULL;
    std::uint64_t aWandererK = 0x9B17691DC5FCDCC0ULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD, 1);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB, 4);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD, 5);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    // temp storage: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_PingPong_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_PingPong_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_PingPong_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_PingPong::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_PingPong::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9E821CA862D9E7C9ULL; std::uint64_t aIngress = 0xDA6B541B9DB7D355ULL; std::uint64_t aCarry = 0xA4F84CBC93A4A6C8ULL;

    std::uint64_t aWandererA = 0x8C8C06601EAC9961ULL; std::uint64_t aWandererB = 0xDB7057A2187851F6ULL; std::uint64_t aWandererC = 0xBA8288BE1950755CULL; std::uint64_t aWandererD = 0x8B43DD33D539DEC6ULL;
    std::uint64_t aWandererE = 0xFC3B922CC3716DE7ULL; std::uint64_t aWandererF = 0xF05CB034D75C0FC6ULL; std::uint64_t aWandererG = 0xB3092193C6E7EB93ULL; std::uint64_t aWandererH = 0xC9314C916B3E670DULL;
    std::uint64_t aWandererI = 0xDEE6F599198C3558ULL; std::uint64_t aWandererJ = 0xE0E6EC5EB9043F14ULL; std::uint64_t aWandererK = 0xC5E8545DBC01184AULL;

    // [seed]
    {
        aPrevious = 9251446495681459024U;
        aCarry = 17647669368569016842U;
        aWandererA = 10001602453484438204U;
        aWandererB = 15221395502937123559U;
        aWandererC = 10483662833267767743U;
        aWandererD = 10565962102500390343U;
        aWandererE = 15087724878516337947U;
        aWandererF = 13750116481363466920U;
        aWandererG = 17243604105279102395U;
        aWandererH = 13262405678643633058U;
        aWandererI = 15875657003355912391U;
        aWandererJ = 16283299267821836610U;
        aWandererK = 11119177552290812428U;
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
    TwistExpander_PingPong_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_PingPong_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_PingPong_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_PingPong::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 3, 1 with offsets 4552U, 1304U, 778U, 1863U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4552U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1304U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 778U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1863U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 0, 3 with offsets 6501U, 1492U, 5155U, 1828U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6501U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1492U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5155U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1828U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 1, 0 with offsets 5038U, 6527U, 1818U, 4341U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5038U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6527U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1818U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4341U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 2, 2 with offsets 4107U, 1269U, 7830U, 6908U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4107U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1269U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7830U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6908U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 2, 1 with offsets 451U, 1138U, 754U, 650U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 451U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1138U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 754U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 650U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 0, 3, 2 with offsets 1469U, 1522U, 219U, 479U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1469U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1522U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 219U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 479U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 1, 2, 0 with offsets 305U, 2046U, 386U, 1017U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 305U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2046U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1017U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 1, 2, 0 with offsets 1389U, 1986U, 1220U, 1475U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1389U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1986U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1220U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1475U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1315U, 1934U, 535U, 558U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1315U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1934U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 535U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 558U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_PingPong::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 3, 0 with offsets 979U, 6559U, 523U, 6874U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 979U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6559U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 523U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6874U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 0, 3 with offsets 6897U, 2418U, 7413U, 6883U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6897U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2418U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7413U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6883U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 2, 1 with offsets 1023U, 717U, 572U, 185U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1023U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 717U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 572U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 185U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 1, 2 with offsets 3932U, 4544U, 7810U, 2508U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3932U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4544U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7810U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2508U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 1513U, 2325U, 3959U, 4125U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1513U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 2325U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 3959U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4125U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1543U, 409U, 535U, 400U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1543U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 409U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 535U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 400U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1179U, 740U, 1335U, 425U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1179U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 740U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1335U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 425U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 479U, 1997U, 309U, 1214U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 479U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1997U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 309U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1214U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1391U, 1672U, 186U, 1261U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1391U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1672U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 186U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1261U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 [0..<W_KEY]
        // offsets: 1810U, 15U, 1953U, 78U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1810U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 15U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1953U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 78U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseASalts = {
    {
        {
            0x3EB6043CC8769F77ULL, 0x7F718C41395F6BAAULL, 0x63C10F582FDFEB1BULL, 0x8F212F0AC30041E7ULL, 
            0x9931D4F81EC530D9ULL, 0x4BF3941CA6459547ULL, 0x4604EFB8C0D86BACULL, 0xE1EDB508EBD36CACULL, 
            0x8B74847A71BC368FULL, 0xB464FDE0DB472010ULL, 0xDE974395063CEE70ULL, 0x218B8ED39E19CB49ULL, 
            0x5632395D89BCD207ULL, 0x832A359528C9DE6AULL, 0x69EAABC431F78C07ULL, 0x326F1200D5E37A4DULL, 
            0xCE463404341F85C3ULL, 0x5DA75EDDE4790821ULL, 0xF909DFAAEBE24F96ULL, 0xA09D8178042D40E6ULL, 
            0xF7C331927E0BEFAEULL, 0x51B284EEB7BED7D3ULL, 0x07D4C9AB2DC2C85DULL, 0xE182BB9967C34D76ULL, 
            0x9B4A1EEE83BDFB04ULL, 0x1887E02ACD9057BFULL, 0x0E0955B27E43F227ULL, 0x095D4E0F9D9978F1ULL, 
            0xDC1DFF297F33DB9DULL, 0x2B01A94D3A8C2128ULL, 0xC8D937FFFCB2A1E0ULL, 0xDEB21C987544BA64ULL
        },
        {
            0x93BFD29AB1CD1EEFULL, 0x7068ED4F330E8135ULL, 0xCE6DC7BA74C0CADDULL, 0x97A0C35AFA9B03B0ULL, 
            0x3BE7A76170845BCEULL, 0x2ECE9D18DFF7964AULL, 0x9C1743ADF4164EF8ULL, 0x87C4F3E83DE7C225ULL, 
            0xCFB8231E1B24ECAFULL, 0x9B276F9E0EB15FF1ULL, 0x5D6FF3FF603784C4ULL, 0x01118C854BE15A9AULL, 
            0xCEEA8FBDF36B1F1AULL, 0x2021F8480D466CF6ULL, 0xB8FC2C5106952B12ULL, 0xA1DA56DB272E076FULL, 
            0x77151CDB564A58C5ULL, 0x171EA501FBDB851CULL, 0xBC2D3628B889E2BAULL, 0x23A4180B7DDA7E41ULL, 
            0x5DF84126CB168942ULL, 0x7044E8A0BA426D4EULL, 0xED5520DEB9329785ULL, 0x07A9DF22F6E09EA6ULL, 
            0xD1D8D7C11A9F81EFULL, 0x01EE14E0DFAAC30FULL, 0x1F365C330EEC4619ULL, 0xA5F7C145199143E8ULL, 
            0x9761C70ACCB7EE4FULL, 0xFC216BDD6A4B2AA0ULL, 0xCC0A1B1BE0E25C1AULL, 0x46B92E51DDC907F2ULL
        },
        {
            0x3A303A7E2EB45771ULL, 0xF2FE2EC2A99425A6ULL, 0x241647C94A5A19C6ULL, 0x0377029F0669C134ULL, 
            0x43EC2F24431E89F2ULL, 0x6951B19C285DE2E9ULL, 0x4DDD9D40037E85FCULL, 0xF432231B3FE8178DULL, 
            0x4CFEC3F0EE0163C5ULL, 0x7E5A3F1E6B5BCD7DULL, 0xA02CA4120A5548F5ULL, 0x270AC13937664207ULL, 
            0x129F86203AD293E9ULL, 0xB0CB92B4DC35A38CULL, 0xF04E09E74A374282ULL, 0xE7C67CA9EA614D8AULL, 
            0x739939EC680D8C86ULL, 0xA8B56E82938A48D7ULL, 0xC59070F9421D2A9FULL, 0xCBFF1C1F4A03B4D3ULL, 
            0x8ED428F59D885604ULL, 0x47BB49E125BBE470ULL, 0x0B404791E2AF31AFULL, 0xF4160D0D00133DC1ULL, 
            0x807141E3DCA5CD1FULL, 0xEA3EBCF21889E49FULL, 0xA8167702A61F7AA4ULL, 0xC4D8FBC2087293ADULL, 
            0xDDDD1372699044ABULL, 0x7B05232BCC60BE4FULL, 0xC1EB4EF27AA895B1ULL, 0x7360F0D81340389DULL
        },
        {
            0x36A882ACD4B71643ULL, 0xB536B689A0B9AE48ULL, 0x3545CFBB18E8F3BCULL, 0x2AF9A3B41A065A7BULL, 
            0x3A4728EF99886705ULL, 0x382E79A13E9BEBBFULL, 0x81A70821C85F92D8ULL, 0x7CAEA2CEE14EA8AFULL, 
            0x18AEDF4BEEE4496BULL, 0xA25BB85454C230C3ULL, 0xABAFC5E91B8B9FB2ULL, 0x0803B75159529588ULL, 
            0xBB8D42BB0A827161ULL, 0xDA160F799261982DULL, 0x2747FFB37DCB50E3ULL, 0x7B77C160A49CFDC3ULL, 
            0xAF62398F23997E3EULL, 0x572420B878324469ULL, 0x28FF13539A8B130CULL, 0xB1F2A4FAEC87F446ULL, 
            0xB561A68B9C23A0B9ULL, 0x2A88A08640C8FFEBULL, 0x6568B4EA4A52A02BULL, 0x7D27911B929D755CULL, 
            0x7C94E0CB3A103CD1ULL, 0x0EFD3DA9A00119F6ULL, 0x9D131CD8538D19EEULL, 0x1D8C71F757F4397DULL, 
            0xE28481F4A212D39CULL, 0x28577CFCA94102F3ULL, 0xD760B073C755C64BULL, 0xBCD335D7CE640187ULL
        },
        {
            0xCD30BAF140F17CAFULL, 0x97812AF15F6164B8ULL, 0x4011840769047EEAULL, 0xF726793BE33B8F8AULL, 
            0x12C70B8B29A22D40ULL, 0x95F84AA89F9E9DD5ULL, 0x728E23D10B8F8AF5ULL, 0xDE17CEBA99AE631CULL, 
            0xB343440B142B2920ULL, 0x87BA1AB7B033A509ULL, 0xF360BD5AF2B364ECULL, 0x0B6FCCB3A2AC30B4ULL, 
            0xF3F7258E6EA8C731ULL, 0xA093AF85EC65BC9EULL, 0x2C9EBAA0861FCF46ULL, 0xB9A058DC07ADCD76ULL, 
            0x69464DAA483A4331ULL, 0x74D9530A56D1C314ULL, 0x543234FDCEB25AFEULL, 0x4529801DD59900A6ULL, 
            0x4B764367019895AEULL, 0xC3AE5B6F766ACB3DULL, 0xB331FC40BEBA25D7ULL, 0xC7D749AA02C5EAA9ULL, 
            0xBE049243EBCAF320ULL, 0xDAD7779DE7BEF47AULL, 0x82DBDC40EDF421D4ULL, 0x858D458A35BF613EULL, 
            0xA95E40D71D31D175ULL, 0x16BC9BF79D3D845CULL, 0xF9C3F69AF1DB1398ULL, 0x0A3FA8555486315DULL
        },
        {
            0x37BC79D8BB75B9CEULL, 0x6BE33406651CF1EFULL, 0xF1DA7506C7EFB3C6ULL, 0x05BB9D095AF06A56ULL, 
            0x055AE96FEA004DFAULL, 0x5E554FF0758F17EDULL, 0x8D60FD8548D4644EULL, 0xF6E82FFDECD930C6ULL, 
            0xE759B47C7F628E9EULL, 0xC1277C684DD2A53EULL, 0xA550AAB964CD9FF2ULL, 0x4B4620ACF28C9E69ULL, 
            0xD1C2E209ABBA787CULL, 0xDC93EC2D716D12EDULL, 0xD1500DE9C4CA62A2ULL, 0x88D12A129ECDCC15ULL, 
            0x2B39C14770AD750BULL, 0x85FFB912B2593694ULL, 0x9DD551C9C4BADCECULL, 0x1A74EBEBD3757FEAULL, 
            0x0A26ED1915A317C6ULL, 0xA4EBFB6A9C490D4FULL, 0x2EAEEA11CC118244ULL, 0x7E0100468F911A55ULL, 
            0xFE1031BE5CF5E37DULL, 0x17C19D57FBD23B08ULL, 0x8DB3F20527892F90ULL, 0x847915812B60E98FULL, 
            0x96E1992624CEC88CULL, 0x27A55BE554109471ULL, 0x609E08FACE1952C3ULL, 0x7D68175D5C78E68BULL
        }
    },
    {
        {
            0x57F4C57E835BE5F3ULL, 0xC64E382DDCCB3304ULL, 0x8A184B77581CFB0DULL, 0x95850A03D26984A8ULL, 
            0xB182089434AF45BBULL, 0xE44D1A36409C5A6DULL, 0x8A65B3E1AD0489D1ULL, 0x60FE0BCC84DC405AULL, 
            0xF2DD8604A13551E4ULL, 0x53BEFF6B147847C9ULL, 0x61BE71EB3B09E555ULL, 0x2320BC84393BACE6ULL, 
            0xB68D11B36A335A82ULL, 0x1A0D0DE4FB9BCE03ULL, 0x8AA3DAE683B90953ULL, 0x37133AF85DA79B52ULL, 
            0x6F4DCBB5A9E16388ULL, 0x1DFE2A3D6AFF433EULL, 0x447B18804CB61C4CULL, 0x2B049101F744C9B1ULL, 
            0x82E6BF57B6F76FECULL, 0x869CBE730C2B2775ULL, 0xDEEEC25304A6DB61ULL, 0x8B87BCE3CE04DAE7ULL, 
            0xC4BA0FB9B851E00EULL, 0xEDD00D97E080F382ULL, 0x52F4B45BA04343ABULL, 0xDD73E99F5651EE79ULL, 
            0x0D6007F75BD8125BULL, 0x380AC4E113AD1389ULL, 0x1894578FFD81C3CAULL, 0x78492B6BA08CA85EULL
        },
        {
            0x821186767D769214ULL, 0x89658C3155CFC52FULL, 0x941B2E09AE4419E1ULL, 0x8F301276E9129690ULL, 
            0x389985A372A21C02ULL, 0xB7D6A4D5088E7735ULL, 0x1927AE5C815D5DC0ULL, 0x3E14BF793C7EF587ULL, 
            0x472E527DA4AB309BULL, 0x94BC13C6642D7684ULL, 0x9FCCEDCC69A03BF0ULL, 0xE01B656751EEA2CCULL, 
            0x03140CC215F9AA92ULL, 0xF3B0DF9AEFC21137ULL, 0xF8E261970BF5E140ULL, 0x4359C1FFA4763C1CULL, 
            0x34940642ABBEAAC4ULL, 0x99AE61DD42B860D4ULL, 0x13FC3064DE29E0A4ULL, 0xE2B46337BE085D01ULL, 
            0x65CC2F7AA9876A84ULL, 0x3FF6BF85002BFD27ULL, 0x4FFBB4406929229DULL, 0xE763995E86E90E58ULL, 
            0x82CD86AE3CA81D24ULL, 0x40EB40A0C59D62EEULL, 0x58AD95298200A8E9ULL, 0x5408B638651E65FBULL, 
            0x1E5725281DE9D809ULL, 0x24771E6139EE8C3DULL, 0xB17000D9C8D533C7ULL, 0x3098C4E21D2B76C6ULL
        },
        {
            0x82A7F9CD8EF2F1A5ULL, 0x319507FDE4F10C2AULL, 0xACF5C6397675739AULL, 0x56B16FABF70F6495ULL, 
            0x0371B8E09A1810C2ULL, 0x11DA2771DC72B618ULL, 0x956E89144025F859ULL, 0x585A885BF60FF4AAULL, 
            0xDAEABEE65E4C4137ULL, 0xCF6316E7683A8442ULL, 0x0913B2D081C63478ULL, 0x88847DECEE775AABULL, 
            0x280E5A0734545468ULL, 0x1D51DB4EA8654C2AULL, 0x32A578C7354D7096ULL, 0x4BA0F053E921BEA8ULL, 
            0x4BF88F6C7FE9FD84ULL, 0x715FC8AC752F69A4ULL, 0x4B93F82AC3FE1EDEULL, 0xB6F9CE5D62E8741CULL, 
            0xA084974FDD3FABC4ULL, 0x24FEB3486CC1CE33ULL, 0xA4FD3BEAC704DB85ULL, 0xAE60E78CE83A2DAAULL, 
            0x3E711D2998C2914CULL, 0x00447763F8E68EB3ULL, 0x5B33245CEC672F39ULL, 0x119DF9C792AC3F5FULL, 
            0xF6E7A0AF72C29E38ULL, 0x10C04F65A0EFAEF1ULL, 0x3F28B948F6C61552ULL, 0x7186248E714FEBDFULL
        },
        {
            0x1E99164FC5921576ULL, 0xE942451EB9B01A98ULL, 0x2B9940B1282F575BULL, 0x72705EAFB9488913ULL, 
            0x4645F79DF2DAB9D4ULL, 0xDADB44BC33345996ULL, 0xF959DA301E5524C6ULL, 0xD0D7F62516FBFCD4ULL, 
            0x9C83DBE99A4644D8ULL, 0x8052254B202634D4ULL, 0xDF33BE98B0DC9A26ULL, 0x2E784D07320BAD4AULL, 
            0x099F763D0DDF075FULL, 0x32A3D294BE117049ULL, 0x81D1D7F77ECE0FBDULL, 0xC859B4746F7BF99AULL, 
            0x803BB56997E7D0B0ULL, 0xD0074C4C7E7D0A1AULL, 0x999C49B1E9653612ULL, 0xAA0987DF8DDE2713ULL, 
            0x075D7A3F6ABC5801ULL, 0x3A2A08E11C83423BULL, 0x5849EE8CD5E76095ULL, 0x1852AC0659222F0CULL, 
            0x3AC72CDAD53990FDULL, 0xF7E794FFE50E06BDULL, 0xD7942CD2306B1A3FULL, 0x5E88BCBA991FB2CBULL, 
            0x9EB503B557D9C797ULL, 0xCBEF3FA3E0D859D2ULL, 0x9ACCA2F43871B3CEULL, 0xB0E56D5A0F54BB67ULL
        },
        {
            0xCED4CD856C1C0EB5ULL, 0x79F56F1261D64430ULL, 0x845B3221F8531C1CULL, 0x5921CF2F62ABD1FBULL, 
            0x6E2311ABE51040D0ULL, 0x95CA4FE6A578F4E9ULL, 0xD0BC34531D483832ULL, 0x7B0E3531EE091A7EULL, 
            0x72D71B9DF13AEED6ULL, 0x1B9F27208D4A617EULL, 0x29707F4740BC6A7DULL, 0x61C4AB8FCD24EEC9ULL, 
            0x8A3BB7514F3B12FBULL, 0xD507340A6DDE3E71ULL, 0xBF7B014EFE17C12AULL, 0x6CABE05233E609BBULL, 
            0x5240CF99E4C6A7D9ULL, 0xCEF8914FD0EDCD73ULL, 0xB36DE9C65CDFE237ULL, 0x076D884C08E0B32EULL, 
            0xF4AA30864499C3CFULL, 0x0F990E86655F601DULL, 0xC20E34308030D92DULL, 0xB496E8DD663AFD97ULL, 
            0x6E6C025BBBD58E7EULL, 0xF4AF0B8E91E78D05ULL, 0xE6AC1EDE21455BD2ULL, 0xC708FAE7D723F990ULL, 
            0x44B0B321C8159176ULL, 0xBF64BD5F7F06CE93ULL, 0x048EC3D15D3D7C91ULL, 0xB118A57FDD22D9F9ULL
        },
        {
            0xE1DE89186AF5E69BULL, 0x0DE4C187E89E75F4ULL, 0x1CC76CD8C2238C6DULL, 0x5ECA32DCD9A84986ULL, 
            0x037F7389FEF03D0DULL, 0x4CE50BE6CECEDBE5ULL, 0x076F7BD30475BF64ULL, 0x8C2D032EEA0E9957ULL, 
            0xB2260FD3C725014AULL, 0x2AD94304F7982F9CULL, 0xE8650228671EDEE5ULL, 0x8FF3C9B72414A14EULL, 
            0x888BA3F3082EBD25ULL, 0x0A4579F46AE1EB8DULL, 0x8866567A02FC70D7ULL, 0x1E504B315D50B79AULL, 
            0xCF3074CC94CF226AULL, 0x3700BADE82364D57ULL, 0xC35E058FC71B615FULL, 0x6EA7248C78F906C2ULL, 
            0x884044DF6D9223F5ULL, 0x2492F804C50B43FBULL, 0xBCE3D640A7F3162CULL, 0xE40E49451C5F8687ULL, 
            0x02EBD9EE2774B2C0ULL, 0x1C05F2F3CAE1D22FULL, 0xAA8BF07495726378ULL, 0x9DE32766498322F9ULL, 
            0xC6491D4BCCA286BEULL, 0x60DC6CC89AB404B2ULL, 0x416523816D2AC13EULL, 0x49CE21957A0A4CD8ULL
        }
    },
    {
        {
            0x6538648FAD9BC120ULL, 0xF8CC5E96FDAC3AA8ULL, 0xD896BAAF9477041CULL, 0x1249AB7B89356410ULL, 
            0xD33ECAC372A5E760ULL, 0x8F55B3A9687FC81FULL, 0x638E8A7C4263A99FULL, 0x13EE658BE6470E50ULL, 
            0x9FDA8D7E83B9E9D7ULL, 0x15794981F129ED4AULL, 0xF6DD9CC1BB5159C1ULL, 0x18BB7A34C76B8B6CULL, 
            0x1828C4BBCDA4328DULL, 0xDD15CD01543F14E0ULL, 0x81704018E684294BULL, 0xD28753090878A980ULL, 
            0xA303F91B9F630300ULL, 0xE1B0FCB5D57F4EF4ULL, 0x3C35BA1841EE3DD1ULL, 0x097F81F392B76CDCULL, 
            0x15E3E45AA48CBE67ULL, 0x728E5EF9E63D4148ULL, 0x97F128F6D65C47D7ULL, 0x91B18EE3B9599A64ULL, 
            0xA44C27164DC84305ULL, 0xE41BB1ED695B5451ULL, 0x3F285ED4AC192622ULL, 0xCA3B62B4F858D510ULL, 
            0x977D3F084B83D38DULL, 0x8ADE0128549A2080ULL, 0xC1518B1CA8E838B8ULL, 0xC1E508C78E368214ULL
        },
        {
            0x98DCB7721BF8919EULL, 0x84C715B1C0948DE9ULL, 0x0FE54A7416FDCDDAULL, 0xC0F03B1D151B34E8ULL, 
            0xB3472CED2AC67D5FULL, 0x98D66C6B64D83CE6ULL, 0x60E8615A9BEF42F4ULL, 0x1743CB45C6B06B53ULL, 
            0x98CB81348FA27EECULL, 0xEEF46962A1B44E00ULL, 0x7DB93B33780744A4ULL, 0x4225E015C25B0B16ULL, 
            0xEF8355F069E7CA7DULL, 0x2E81EAF4522B5E8DULL, 0xFE083614A09BDD53ULL, 0xA6DB96E86DA04CB7ULL, 
            0xE831743DC0D8E189ULL, 0xD70F7F7B99256F4AULL, 0x0A3E34A8123E62D5ULL, 0xAE7C62B93B56789DULL, 
            0xFF1CC88B3D8C4B71ULL, 0x30D5674EC2E3342BULL, 0x8646EA509328B2CDULL, 0x00C53ECBD8731E2EULL, 
            0xFF90A94D221500F1ULL, 0x02A96C243F78D8A4ULL, 0x9F835BBED552FF5AULL, 0x4296AB4CDDBA3B61ULL, 
            0xF98998B37202261CULL, 0xBBEDFE4011347895ULL, 0xFB08110DD9539986ULL, 0x62765ABF600931FAULL
        },
        {
            0x3F4CCD59C37E3F42ULL, 0xFDE6334CA1CA1B37ULL, 0x4441EE8199B62283ULL, 0x7EBA0A4DF8574719ULL, 
            0xF46C1C0863F6B1D3ULL, 0x51B5BF9F47323B02ULL, 0x40D9F35F2F50BCFEULL, 0xF550BCB3AE2708FAULL, 
            0x0A27EC8828F7CD1AULL, 0x8E4DDD639F975EAEULL, 0xCED9E81CCD8E4F89ULL, 0x2EE4B64BACE39539ULL, 
            0x93AB111B4DB3CE9FULL, 0xED941928726FA980ULL, 0x61D09D1BCE545EA5ULL, 0x78AA33FA1A0275E9ULL, 
            0xB30C7E2576ED4117ULL, 0x9E91E052FE7D2870ULL, 0x4E8E4D0D3BBEBD58ULL, 0xD5D79D21357DA1B8ULL, 
            0x82E1F27309532F06ULL, 0xCA87F83BE344D254ULL, 0x58A0111D03AF9758ULL, 0x5C9830026A0B1C01ULL, 
            0x6F7801F16AD00B64ULL, 0x8295AA8E52FECFB2ULL, 0x8D56BBFE5E0E7D53ULL, 0x4BAD0982410DA4DEULL, 
            0xA393202E943F0569ULL, 0x18CC3D6367D4B60AULL, 0xCE3CAEAF0B05246EULL, 0xDFA86720ED1D6BBFULL
        },
        {
            0xD8ECF1F2FF769CCFULL, 0xB36B6C1E19508802ULL, 0x347A86572F3C0E48ULL, 0xE34A1F960B53E345ULL, 
            0x8DE3A69F906649BDULL, 0x1D20C999FA750A6DULL, 0x7A82FA98F187BB1BULL, 0x686E2BDD20EC7204ULL, 
            0x156943A167D21CAEULL, 0xA53C7148E745E4C3ULL, 0x8166DB0AF7F13279ULL, 0xECAEF7789BB58FD5ULL, 
            0x07C4E77320FFD89AULL, 0x44F350BEC126F8B1ULL, 0x2A93B6CDA61985C1ULL, 0xCC22DB47ECBE530EULL, 
            0x63D981385024F806ULL, 0x8CF6E1C98A8945F6ULL, 0xC2E8A136D897199EULL, 0x9DDAE6BA197FF920ULL, 
            0x1D30A7C4A771E464ULL, 0xEE31F32159CFE2A1ULL, 0x523A7AD0C4A25C6CULL, 0xA96BAA2E24F7C61EULL, 
            0x0F4B65847D731EEAULL, 0x7BAA4EE197D3F8FEULL, 0x2EC78D6FCEBFA8B9ULL, 0x64CAED0FA1318310ULL, 
            0xC49FC1AA19963B39ULL, 0x27886F511B2CD57EULL, 0x6B86092072A65853ULL, 0xB9E3403F15653DADULL
        },
        {
            0xCF0A752DDFD14C14ULL, 0x4E1EE3177C7C0862ULL, 0x16083D4DF73C1F85ULL, 0xA999E4EE704D86CDULL, 
            0x7C365D01CFB66F3BULL, 0x7207578C0F188AB4ULL, 0x8408C09DA9DE2E1EULL, 0x024D2F3186D8FFA5ULL, 
            0xB9B1E7BF271AF086ULL, 0x4F78FF0C2AB6CC26ULL, 0x1E96A4352EB365B9ULL, 0x1D5560BF4DB25C6AULL, 
            0x5E3BBEA16D814E80ULL, 0x56E088EF11CA5F26ULL, 0x63DA617A8A5FED02ULL, 0x22E70EBADBE073D9ULL, 
            0xADC186E9DB26F99DULL, 0xC5DBA8936E432116ULL, 0x02D532FD6A2D0200ULL, 0xEEE217B9D191D862ULL, 
            0xA342EDBF4B3F4FEBULL, 0xBB1665B1309C920FULL, 0xACDB5CA3E8F14ACCULL, 0x7F2A20DCD38C2808ULL, 
            0x5FE95424D14DC694ULL, 0x3B74B51287FCC644ULL, 0x5943CFB0A27321E0ULL, 0x9D885EFDAD25E923ULL, 
            0x27FC66C5A26093C2ULL, 0x827EB51773290A52ULL, 0x4DCCCCACA545FF6BULL, 0x4A49F134690681EEULL
        },
        {
            0xA96E2E3A1F9DD8A1ULL, 0xD32B499F4DE45773ULL, 0x8440A75CAFC767A6ULL, 0x8DFD56316D186548ULL, 
            0xBEDDFCC5D9371BD6ULL, 0xE08B97F6E7E088A2ULL, 0x4332A055F8E497CAULL, 0x60611DB2A70541DEULL, 
            0xADB23075C334F4C6ULL, 0xE33B43877E80377BULL, 0x1C54AE3B1114EB26ULL, 0x8E5C8A9195B17D10ULL, 
            0x446302091CC0346DULL, 0xBC3E86912CC53FB9ULL, 0x7C48F2915114A074ULL, 0xD347E291B84CFEA2ULL, 
            0xBE836318C155AF66ULL, 0x42F0BF55B108583AULL, 0x6F9A46DF8D3BA703ULL, 0x2A58BE805012A996ULL, 
            0x4DFEB5FA75CC3328ULL, 0xFAE922AD5B099D61ULL, 0xBB19C9D5A1121929ULL, 0xBAC0373FE3119B79ULL, 
            0x8D262EC8012F815CULL, 0x170FBFBA2E5C722CULL, 0x8639E8ABC2847980ULL, 0x48A9C3FF40700812ULL, 
            0xCDF3B3E459FC5D7AULL, 0xA5956F2C5C0CC98AULL, 0x2898E7C4B41C310AULL, 0x94AB2322E3A06D80ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseAConstants = {
    0x71CCBDC793819BBEULL,
    0x20252E044F31649DULL,
    0x4D436B2586E39D2BULL,
    0x71CCBDC793819BBEULL,
    0x20252E044F31649DULL,
    0x4D436B2586E39D2BULL,
    0x586293FBE2173658ULL,
    0x50A4C90DC4485FA2ULL,
    0x26,
    0x91,
    0xED,
    0x63,
    0x88,
    0xBC,
    0x37,
    0xC5
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseBSalts = {
    {
        {
            0xB594797B0C6CB6F5ULL, 0xAED1FF03B1189FE1ULL, 0x9905B7CA74C631BFULL, 0x0A3092A040D937EBULL, 
            0x0599F5ED9C60DE06ULL, 0x477AF48CFB9925A4ULL, 0x02215C60D4919BF7ULL, 0xDC890BE925A6C3B8ULL, 
            0x8D9DB2295B5C04BEULL, 0x3D88AE0B5038C02AULL, 0x83B8C0D57A7CB6EAULL, 0xC08A1555F49CD46DULL, 
            0x333D4459739CFD6BULL, 0xE9021D50BC5DFF5AULL, 0x24B6590AD404878EULL, 0x542E3E6DF5C7B4B8ULL, 
            0x86DD25F921A5EDF8ULL, 0x19A02DB76201FF5BULL, 0x583765103786EDCBULL, 0x31E34F6981F103C8ULL, 
            0x3EEA6E6D9F19D93EULL, 0xB3D80233652B5CEFULL, 0x127E88FF4D16ED44ULL, 0xEBEA5C1A481451F8ULL, 
            0x517D274883CDC5C4ULL, 0x712B2D32A1F098E6ULL, 0x26EAC927C1D9F8CDULL, 0x0AABE8D9E2455374ULL, 
            0xA9F665814CCBAC4AULL, 0x7FE09833C2AC12D2ULL, 0x55DD2D574F710817ULL, 0x88FFF86F85889B96ULL
        },
        {
            0xA4A6747248A5AF82ULL, 0x5369D2EC14585DA2ULL, 0x31E92CD3A3CB04DFULL, 0x37B514869A8B0477ULL, 
            0x18E69CDBF8AD4E33ULL, 0xC75767D92609082DULL, 0x385AB15760A75AB1ULL, 0xCD8C7413034725B7ULL, 
            0xC8F8A0D2B581B7B6ULL, 0xDEF7980D6A450856ULL, 0x0C83C45ACEBEF1CEULL, 0x3A8F0CA36C1C4C56ULL, 
            0x0F86925F1B250872ULL, 0xC9252A1D1610C6A2ULL, 0x5383A86B9DDEA439ULL, 0xB3A9535E08AAE50AULL, 
            0x7E97A161559E4EE0ULL, 0xC60E623FA39D4A26ULL, 0xE77F66B58A121333ULL, 0x8C8FB86CB169969AULL, 
            0x9FE8691DA8A30A53ULL, 0x623C0D016D797D76ULL, 0xD45EAFD6C5F2DCE0ULL, 0x5C80E29B9F8B786EULL, 
            0x3120FC98E0F1F6A6ULL, 0xE5EF17F4EAA2B2B4ULL, 0x79573BDEF7B07542ULL, 0xCD004C3BE25390FAULL, 
            0x848FDCF7C7A9CA8BULL, 0x3946E85E3050B194ULL, 0x1F53EC8AD4265B59ULL, 0x6B27159572FB8FB7ULL
        },
        {
            0xF7967E3738FCFD8FULL, 0x6C7BD03799226A68ULL, 0x2CD1DF473CEB46F8ULL, 0xBB1BEE2D17BAA1C3ULL, 
            0x03D0DC1FCFF07944ULL, 0x1B6A94D106621C0FULL, 0x921566C4D356E31FULL, 0xF1C9429965AB2955ULL, 
            0xC31BAC17B00380EEULL, 0xE131BD071592D604ULL, 0xBF47165917437764ULL, 0x04055FEB6B3581CFULL, 
            0x5AA8B67E33BEA248ULL, 0x447EC4A54C9CE35FULL, 0xEB9439FEE7C7A123ULL, 0xC00298CFF9C9AF06ULL, 
            0xBA78957216BBE369ULL, 0x70D376AF064EEB17ULL, 0x2409908AD37FDE1EULL, 0xDF8858AB33815A09ULL, 
            0x067861F5A47F9C65ULL, 0xAC5839A1A40D7C17ULL, 0x8EA1CC6EBF10270EULL, 0x241819CA67C21FB3ULL, 
            0x577E7EA7276DD29CULL, 0x7E8712B950B5FC05ULL, 0x7AC8F98486055BD8ULL, 0x8C7AFE6084519DFBULL, 
            0xFAA8EF919ACB9859ULL, 0x23EEC603A6D72029ULL, 0x5AAB3592816DC4B7ULL, 0x809CA79B4002F196ULL
        },
        {
            0x096ABA641614AFA5ULL, 0x1B4132644D7DCB9FULL, 0x6442F93606B02098ULL, 0x334917BB9FE460D2ULL, 
            0x1A530A5C1ADEDE49ULL, 0x350E57E01BF6DCBFULL, 0x5FEFC2C9F4C6159CULL, 0x6E3365ABAE5ADCA3ULL, 
            0x4752B4D6B870A7B2ULL, 0x25B24F301C91A2BBULL, 0xA432B802C1F981F5ULL, 0x551E2B8D235B2754ULL, 
            0x6E94C98E667CA84AULL, 0xCEABB7B90C8B118FULL, 0x25328256D3ECE1BBULL, 0x1F5C7ACB9B84846AULL, 
            0xECEE45BE84D51DE7ULL, 0xD96DA0EFAE25F546ULL, 0xD47667FB197B17E4ULL, 0xA6DE91745940534FULL, 
            0xCE7F17B3A9CF291AULL, 0x14B7106B22F1EAA9ULL, 0xF66214A9A36B82E5ULL, 0x5007F4F8528CC420ULL, 
            0x450982A4476F6F41ULL, 0x7857E3E4F28B4FA3ULL, 0x4A809411AFDBE0FBULL, 0x04C0866712DC65FDULL, 
            0x185C5D44224CD514ULL, 0x9BA5758EAEA83355ULL, 0x706086693101F8F5ULL, 0xAEC90FDDDA53604CULL
        },
        {
            0x3405252DA7B4531AULL, 0x11632FEC06E54A2EULL, 0x9EC2390D12E18F39ULL, 0xF43F8BA8C2250E32ULL, 
            0xE8E7C4D4364A88C5ULL, 0x16E8527E62BF3C92ULL, 0xBE5564F01B7B4AB3ULL, 0x84D09984D53C50A1ULL, 
            0xDF6141C3D04F7B78ULL, 0x448E06579E579CEDULL, 0xD0B6B8D483DCFEC8ULL, 0xA4093048CC8408B3ULL, 
            0x9BBB220B0E0B8275ULL, 0x552CE693931E497BULL, 0xFA1D06034D7B719AULL, 0x6B0ADEAC8A73A041ULL, 
            0xEB8C033CC91CA0F5ULL, 0xCC6B733E26338AE0ULL, 0xD56A1B99240F777AULL, 0x2365DDE2035EC8FCULL, 
            0x98CBC7C12B0BCCD9ULL, 0x724A7647E8E63416ULL, 0xD75F3DDEF382B2F0ULL, 0xED34869344ED9939ULL, 
            0xC77A222969ED02B8ULL, 0xC3ECFE611C9FB738ULL, 0x1BBB3A18128FC5BCULL, 0x44F863ACE5042484ULL, 
            0x3EC54974D15EB2D1ULL, 0xCCABE4CFBB741084ULL, 0xA65033A14BB8B8FBULL, 0x0A5C9A1E09CBDAB7ULL
        },
        {
            0xB3CE30B7A36DB1C8ULL, 0xF5DD7474DF4110DAULL, 0x770AC060BFC97856ULL, 0x456C7682E4BC8C63ULL, 
            0x624E54C3361F7F14ULL, 0xF777CBC386379E9AULL, 0x3B744D9ABA01993AULL, 0xBC61407C8585E746ULL, 
            0xC81245B8FF7CA9A7ULL, 0x21465D8650B48826ULL, 0x9BF9E5F0CCAA710BULL, 0x0D656744469324FFULL, 
            0x1AB35B8AB8194DC7ULL, 0x55250203158ECF73ULL, 0x88D9E382710B39B6ULL, 0x29CB8A2F9EA99762ULL, 
            0x747E2FF71C078387ULL, 0x175A3FDC4EE71F28ULL, 0xA6CD52B258B2FB13ULL, 0xECF0E2CC18878B06ULL, 
            0x157F7B7AFA50776FULL, 0x0B01710F11B2B24FULL, 0x1CAA198A12595925ULL, 0x98763135E08F7882ULL, 
            0x0F8683CBF0FE5284ULL, 0x331292C531498E54ULL, 0xB09421C73BEC045FULL, 0x4E95495CC03738D3ULL, 
            0x14590EEA07271155ULL, 0x4DBADB30B6038F2AULL, 0x925047CB7EF219ECULL, 0xA4E96DFC8ACF1261ULL
        }
    },
    {
        {
            0xE1FB89610114560BULL, 0x53C72B38C44AE67DULL, 0xF8BB463ECD120021ULL, 0xDBB2D88D57F67D6CULL, 
            0x8EBF1745710E7B0FULL, 0xA052CC2C670D6577ULL, 0x516114586961B4AEULL, 0x4DD991CFFD793693ULL, 
            0x6BC057D0A57648D6ULL, 0x1F5E1CC4411B0647ULL, 0xFB705C94627900E6ULL, 0x7FDB145ED42DEAACULL, 
            0x762BC514268EE68AULL, 0xEDFDA9B4D45D61B9ULL, 0xE216664DD7EDBD55ULL, 0x3889D49F77786CFDULL, 
            0xFF278EAA3EF8FA44ULL, 0xAAFF57F1499F1990ULL, 0xEC42B00CE344A4CFULL, 0xC4EF389DDF4377F5ULL, 
            0x5B52333DE7A78A8AULL, 0x8742BE8775116057ULL, 0x2D1D8D91D75A84D8ULL, 0x7A9DBEC633034C2CULL, 
            0x2BA5969795A2580AULL, 0x05E46826DE6D0C03ULL, 0xBC47A3367AC25FFDULL, 0x01E3005944A81820ULL, 
            0xFF685BD44B6A5142ULL, 0x32FBF00605E12007ULL, 0x317BE2E679D894BBULL, 0x141380E9B8413A98ULL
        },
        {
            0xC3ABD45A7CF2EB00ULL, 0x07AE10AB4056DF15ULL, 0xB52C9DD6FF0B1991ULL, 0x49F25691966ABDB2ULL, 
            0x2E1668668FAED605ULL, 0x5B0E344FDB85B638ULL, 0x7602D9E287D59CA8ULL, 0x686E27541ECF68AFULL, 
            0x0854EC39B4A82C8AULL, 0x1E9D135736B85DEDULL, 0x77B12CCEAAFA5F80ULL, 0x92DDE21B45CB2608ULL, 
            0x67C211E939EA2224ULL, 0xDBC8A5DC0CE41B75ULL, 0xD982D5F42B36ADFAULL, 0x47A4A2A0D4594F5CULL, 
            0x25F8A255D6D9E7C5ULL, 0xFC8DFE8EED5237D1ULL, 0xFB86F721B851D628ULL, 0xBA1D0DBDE053B437ULL, 
            0x3AC18B5B43DCABF7ULL, 0x57A7172F73623AFAULL, 0xEF1172FD897BEF88ULL, 0xA94BB24BDFE15D47ULL, 
            0x36A0B8E34A8E22DEULL, 0x26D08613577DA6FEULL, 0xCEDF3B8297A282B6ULL, 0xB6FBF393B48954E4ULL, 
            0x5558D028F83E32F7ULL, 0x476C05ACE0C1BB40ULL, 0x58AAE834A451BD92ULL, 0x1AA8DE0B87B3F955ULL
        },
        {
            0xD47308166B76DCC8ULL, 0xB59372B8761F9083ULL, 0xAFF797B31CE5596CULL, 0x07E2796D19FF32E5ULL, 
            0x09725CA33C77AB44ULL, 0xCD985CBD4E7B98B2ULL, 0xB7FC666903E5D3CDULL, 0x88E8138C67FE83D7ULL, 
            0xF9BAD13316A8EC7DULL, 0x968F924A1B910071ULL, 0xE19B196CEBDC2E38ULL, 0x37C5BAAACAC973CDULL, 
            0xDE587A3B06FE5C40ULL, 0x898A958E93C84517ULL, 0xF94F48D730363D48ULL, 0x0E22DDAAB64A9B28ULL, 
            0x9EF9FF1876A6D291ULL, 0x504FB5FFDCF0B621ULL, 0xE353B09891693AD3ULL, 0x49745948E53FD778ULL, 
            0x3F6DC753275D892CULL, 0xAC2BFCC9A2A36B94ULL, 0x17E7AE3A2427AAEEULL, 0x92BA6F5760995EB5ULL, 
            0x4930ABF9B4F18B4FULL, 0xD2AC6BE6B2529410ULL, 0x1EC3AB37D2EC3FA8ULL, 0xBC15FD8F44053B6AULL, 
            0x743FD97BF8BA5B97ULL, 0x7743980380F1F21FULL, 0xA2F594D7835C7117ULL, 0x3FB98496808843CDULL
        },
        {
            0x2F7F03F43801DA41ULL, 0x489228069BD96618ULL, 0xDABB2CF09134F2AAULL, 0x89F39DC3BD3E84B6ULL, 
            0x5D9A025D57FB6E63ULL, 0xD8B9B492B81851A5ULL, 0xE56B70CA63F2CE0FULL, 0x512207C71F9364D8ULL, 
            0xD874842AC5BAA37AULL, 0xAD0D04D9C80FE475ULL, 0xB8D7F568EA39CB44ULL, 0xF492ABA18BC62719ULL, 
            0x932D19BE810F33A0ULL, 0x3FE41665959A9FCFULL, 0x3E127F3E79B0FEA1ULL, 0x27E82018B9B8F384ULL, 
            0xDC14F1D39A1EC429ULL, 0x085BAF0F4FDBCB04ULL, 0x3537D47C74437F5DULL, 0xE706B516A8C1D6E4ULL, 
            0x0F5322838AB3B27EULL, 0x88CD62A7989F8075ULL, 0x49FDD19E042369ABULL, 0x3B70AEB0682016A0ULL, 
            0xFF0D233618B574C8ULL, 0xD2F5BB8E41E207F5ULL, 0x4D5AE5C9864473C8ULL, 0x0433202084CD5813ULL, 
            0x642F77E40740FBCFULL, 0x3936BFB11CEDD152ULL, 0x214C493D631CAF4BULL, 0x4D63AAA640653302ULL
        },
        {
            0x1C4B5222B0D611D7ULL, 0xE17C5685B7F723FFULL, 0x816E7FC803DCCF62ULL, 0x968764C4BE8D9C22ULL, 
            0xE690CA09F64F278DULL, 0xF7682182E401E602ULL, 0x70F021D9411E6D99ULL, 0xEF9B3DA3E93246E3ULL, 
            0x5D49D27A0D339C7FULL, 0x115EF2187E5764BFULL, 0xB2A6627B10E1ECEDULL, 0x961C04B72CA1472CULL, 
            0x1D964357BC420A7FULL, 0xA737EDA95E88ADFEULL, 0xC50129605FF43D61ULL, 0x8D1A46FF0F6970D7ULL, 
            0x88C5B892E343EE18ULL, 0x32ACF33399B7A3BAULL, 0xAEB60B2047D59126ULL, 0x2FB21C923634C8AEULL, 
            0xFA43E2FD8C12D224ULL, 0x98E68813D1C6494AULL, 0x89E12BA22561AAF0ULL, 0x4FD95A3D786B33F0ULL, 
            0x0005EC9434A7779FULL, 0x7D5DAA665AE1B5EAULL, 0xAA0570462626BFCFULL, 0x664A85C5369085E4ULL, 
            0x5AC8C7435493D99FULL, 0xC43CCBF5FD89EB5EULL, 0x4C122D125216DCCFULL, 0xD1131DEE2B9C33A3ULL
        },
        {
            0x61CE2439D03E51E5ULL, 0x38F86DBD4BDCC9B4ULL, 0x6E3A4CC65A2589E4ULL, 0x9E0847468DBCEFC4ULL, 
            0xAFE4252298D4DF45ULL, 0x052A1F96F4B28780ULL, 0x726120685EF3C81DULL, 0x646BBEF884EB369AULL, 
            0x8D5D92C831FA17FDULL, 0x5DACCFD6612C8BD7ULL, 0xFBA879633B141ACDULL, 0x275F5F43D79AE4A5ULL, 
            0xF0FC8396770C84A2ULL, 0x21B328426E09670EULL, 0x77B0C23618454AE7ULL, 0x5741647C021A2297ULL, 
            0xF53E67E38890F551ULL, 0x2D3A432ED2C92194ULL, 0x746801564DCF6CC1ULL, 0x06A6620C88051413ULL, 
            0x6EDB8EFF5E58F85EULL, 0x3D4B6EEA1AE412EFULL, 0x1D7C7E652CF97103ULL, 0xDB8CEBACF63BD734ULL, 
            0x90A563A1D193A23BULL, 0xEC64F3EB56EA543CULL, 0xFAB1C2166CF57CC8ULL, 0xCAA9B227F022AD28ULL, 
            0x3B38C480146BEFD5ULL, 0x2CE1F59B5CD6F730ULL, 0xCB8E1AED4894CD63ULL, 0xB5396134CEABE32AULL
        }
    },
    {
        {
            0x5E62A2A19DDA0E3AULL, 0x69136EF9BFA2F28EULL, 0x6B6A72DED9CB6BA7ULL, 0xB975CE0A9C085372ULL, 
            0x2F7E7CFC4BC80E61ULL, 0xB0653F48A3FF4116ULL, 0xEDC8B11BD62BF73FULL, 0x455AC5DD8BD5D6F1ULL, 
            0x7718DD517C59FF2AULL, 0xE35E50C1A49404D4ULL, 0xE25185183A9C3628ULL, 0x100C6F6FA3B1DABFULL, 
            0x251C44EC5845E258ULL, 0x0D11ACF32329225CULL, 0xD01B2239468497B0ULL, 0x831D21FDDC571EBEULL, 
            0x5C345CF07263F840ULL, 0x29213193A99E4742ULL, 0xE79A637FD2B3D638ULL, 0x392535BA4EA54707ULL, 
            0x190A9E758FFA685AULL, 0x333FCC2ECECED8F4ULL, 0xD2D7E2F92FF1142AULL, 0xE26D76265DA35F77ULL, 
            0x7C8C46F25D3267ACULL, 0xB9B5526DC0A9BBC1ULL, 0xF51C41C7B4E0D606ULL, 0xB4A72CD403B91502ULL, 
            0x5134EC87583F7AB4ULL, 0x8FF238545B4925E3ULL, 0x4E6A5C9249F966CBULL, 0xBBA10BEB9BF5B002ULL
        },
        {
            0xAE3464D4B4343993ULL, 0x4E6786EE4A1411CAULL, 0x8D08C85562DBAF87ULL, 0x3C5F892A6BEA3A59ULL, 
            0x177CDD1C717E6478ULL, 0x76E993B7C629DCA2ULL, 0x547D1ADF38B5A946ULL, 0x7DF4BC8F10110205ULL, 
            0xAB66E9CFAE38119DULL, 0x3D675ABA1076D874ULL, 0x335A28F78E4E26B0ULL, 0x2F7E0458F616ECDBULL, 
            0x8ADEAB5ECAF35A1BULL, 0x3618EF6A675117AAULL, 0xA62FD70E159D8878ULL, 0xDA9FDEEADDD27B4BULL, 
            0xCF189C7C049E4027ULL, 0xE5E81613D6944B91ULL, 0x9CF6810E7E2588D4ULL, 0xB2B964262B3E8C3EULL, 
            0xC8651F745011448BULL, 0xA42BF63ABC697BA4ULL, 0x13AC0F60DB0F2820ULL, 0xFFE6FE1283200E78ULL, 
            0x00A2B0F1DBB63986ULL, 0xE48683141495C893ULL, 0xBAFEFDA49D92D9C9ULL, 0xAF1F8B53F2E52938ULL, 
            0x0347F5CA637F1446ULL, 0xF3A564F81EBA84B9ULL, 0xF67F182FDE2BFB04ULL, 0x70D285258E0C2DCFULL
        },
        {
            0x32AF8CEB9BB9F663ULL, 0xCE3DA300D0BE0276ULL, 0x21C265053FDF0236ULL, 0xC64EFD8F76B0B29EULL, 
            0x2766BAF33957BB22ULL, 0x6A9A8D7ED85CEB40ULL, 0x05F737822057CD7CULL, 0x791D2B1AB87C1516ULL, 
            0xCBD01E960E7904EEULL, 0xAC8EA5D3B2AA1332ULL, 0x65833B5567294503ULL, 0x43635530AC39DBA9ULL, 
            0xA21554C374FC2783ULL, 0xC4CE598F5915E36DULL, 0x9079E304CBF91AB5ULL, 0xF308E8567D2FA891ULL, 
            0xB01FBCCEEFEBFCE6ULL, 0x8C576523B0448D71ULL, 0xA2943CA0335ADDBEULL, 0x9511A8609DF5807FULL, 
            0xE3204C28557B1813ULL, 0x735BE58E9E6C946AULL, 0xCA9DF79C03B0C35AULL, 0x038E4A55AC0AF047ULL, 
            0xB7E3E06187516DF5ULL, 0xAB0F8A87ED79CF9FULL, 0x7EF5F7EB35309D55ULL, 0xF265E67AD530C2EAULL, 
            0x8B094746FB6E97ABULL, 0x7504557A30A3E8BDULL, 0x38F010264BB1232BULL, 0xBBF3065BE8CF0249ULL
        },
        {
            0x9484E1D980F38856ULL, 0xE07DCB3270B43F5FULL, 0x0331F531DDA84BD6ULL, 0xFC178420F246FF19ULL, 
            0xC99ACC13F00B9AC6ULL, 0x8601DD36D6A4DBDCULL, 0x263D05350F232B68ULL, 0x4B4127BCB7B7900AULL, 
            0x7B23B70852D2A55AULL, 0x6C46B5F5890ACAB4ULL, 0x8ABD9FD076A4AB6AULL, 0xF14085E7955155BDULL, 
            0x2B0D662D8EDF707DULL, 0x717A305937F729BEULL, 0x9F7E302DF5676727ULL, 0xF4DCD3F4FDC4EEE8ULL, 
            0xF5A8550918B87EA4ULL, 0x365F77D5765D26EFULL, 0x09EE9057A70BE7BDULL, 0x7ECAD2F7A3F6A1B3ULL, 
            0x9508DAA6EBED4812ULL, 0xC271C0F774672C3EULL, 0x3EA525D334986479ULL, 0x9266FD990374F858ULL, 
            0x2A6678EC119490C6ULL, 0xF0B78D356F573723ULL, 0x415D48AD265A5D77ULL, 0x89E154FE5F836492ULL, 
            0xF195F664029EB793ULL, 0x401F9F6729B70D7EULL, 0xDD45E7CA65576998ULL, 0x90C88F025BD00D25ULL
        },
        {
            0x0154F55618D13FA2ULL, 0x942CE6CE7D9C6313ULL, 0xC9F6702F2B6CC1A4ULL, 0x9FEEDB181DD1FAF9ULL, 
            0xA21B3FA336E06D23ULL, 0x322FE512968A9637ULL, 0x4DF6B692110D1F22ULL, 0xABE08C15E1F02188ULL, 
            0x51517546498BD274ULL, 0x126831A26F9E218FULL, 0x31C6193E55548948ULL, 0x430244A6254855E4ULL, 
            0x7BC4AD703228DB10ULL, 0x8BE364161049156CULL, 0xB2A5440FFF0B07DDULL, 0x88488BB9343EE801ULL, 
            0xE60EFC404E65035AULL, 0x3595865FB61DEC1CULL, 0x5F0594CAF7F2EF72ULL, 0xD0B7C8E1A65738EBULL, 
            0x496B248E79C817A4ULL, 0x651B5EF0C31695ABULL, 0x0015E3C72CE8D5B0ULL, 0xA8D79237BA802941ULL, 
            0xAF5566DF6F7358C3ULL, 0x78D57277E5C74362ULL, 0xF0AB74295967BB07ULL, 0x21F427A253518067ULL, 
            0xEF9CA2A8C79CDA9EULL, 0x2BB24EA48F6906F7ULL, 0x628BB6B81003CC83ULL, 0x74ED7BAA9CD95197ULL
        },
        {
            0xAC7C39AAE31B90FBULL, 0x6435859482D2E997ULL, 0x1E709E628945C9EFULL, 0x1D47FA05DF947A47ULL, 
            0x5EA43626441E825AULL, 0x4B90DFADB25A84CFULL, 0x028932C4489C3FE7ULL, 0xC3C4BEFF30A0C911ULL, 
            0x33335EE421E5B035ULL, 0x94FC55FFF7C6A1C7ULL, 0xA46FD89D907F581FULL, 0xFB34EB0EA7FCBCC7ULL, 
            0xC4B367F8AA0E5487ULL, 0xB320138EF59424A0ULL, 0xB4E6AC7F7D75BF7CULL, 0xDF8683E94E00F810ULL, 
            0x6FACBB681F0A0F11ULL, 0xDB478EDBB7E2D5A8ULL, 0xD2B94853E6FA607CULL, 0x000084653FFD930CULL, 
            0x7C7B51E181D4BB8AULL, 0xB26744A08765AB4AULL, 0x26F6EFCF31D5B796ULL, 0xA6BD2F3AB7F3A270ULL, 
            0xA32A25DB238B37DEULL, 0x6033BCEBEA544206ULL, 0xF64EEBC82DE9F112ULL, 0xF04F469F4E6902C7ULL, 
            0x25ADDFAC7C0EA2BDULL, 0x2F05ECC56A8DBAE6ULL, 0x5E772B0856BF95F4ULL, 0x8F6A0271C92A2D67ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseBConstants = {
    0x3D6C7EA2EEEBEA8AULL,
    0x68CADE5038E52A17ULL,
    0xD9FC8ACCE1E2F625ULL,
    0x3D6C7EA2EEEBEA8AULL,
    0x68CADE5038E52A17ULL,
    0xD9FC8ACCE1E2F625ULL,
    0x5F288F4AB124FB31ULL,
    0x96456520A427F5FAULL,
    0x2E,
    0xD2,
    0x21,
    0xFC,
    0x9A,
    0xD0,
    0xBC,
    0x0C
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseCSalts = {
    {
        {
            0xB1681B97130EAC15ULL, 0x8DFFB21A7F0FB35EULL, 0x5F5E1972A5BD06FFULL, 0x11BA48DF8B614A7EULL, 
            0x9CB13ECD67280B76ULL, 0x24955B092FF527BFULL, 0x6209C9C36C493B58ULL, 0x8EB3C7D3F32531AAULL, 
            0x5044A5F7E28B4863ULL, 0x364FD5BCB37A551AULL, 0x93AA3B94CCEAA4DFULL, 0x0A244B2E4F53C124ULL, 
            0x4B74175BE8E4A74FULL, 0x6E05B9EF43CE987DULL, 0x1D8A7F82270F3D13ULL, 0x05D09A4CDC32ACDBULL, 
            0xFD8F9F0A8B51E025ULL, 0x92E1F0EDB42DC9B7ULL, 0x4A8CFFACCDCF69B6ULL, 0x7C4EA0129CD8F578ULL, 
            0xF825ED27D6FE552CULL, 0x31E82C80017C352BULL, 0x7C2340FFACB666D2ULL, 0x607A360822319EA2ULL, 
            0xF3E8818205451516ULL, 0x513F276699FD4922ULL, 0x943B16992A531CEDULL, 0x896B761FFAB2F61DULL, 
            0x8D126244C398F8ABULL, 0x4BDE5C740E91C392ULL, 0xC0822DEBD3F309D1ULL, 0x3D24A9812AAFCC3BULL
        },
        {
            0x9B1C343D379D50CCULL, 0xF0722D1E76099D30ULL, 0xD659B9C5242FA691ULL, 0xBD259CB80FCA3A08ULL, 
            0x9ED1F61CE625FBF6ULL, 0xD52CB4A66F36DA1AULL, 0x65F8D6DE28EECAECULL, 0xF0CEC746A3633E2CULL, 
            0x7289D072C1FE499CULL, 0xA0B7188F38B33207ULL, 0xCDF749FC0076279DULL, 0xBCF39BC04431ACDEULL, 
            0xF8C9FDC2AA0D33FAULL, 0x9E7CD32CB8ECECD2ULL, 0x339C7DFD5EBCE39AULL, 0x91F1627A9115CEDAULL, 
            0xBDE8A6399BB73C1CULL, 0x64D1C5B601111EC7ULL, 0x5A9F6C03998BC9DAULL, 0x033023FE69CF394FULL, 
            0x3798994E5931A81DULL, 0x10385A8AB6D2D23EULL, 0x0F963D12FABB4805ULL, 0x01C7756E407FAFA5ULL, 
            0xEE4C357AB89C2000ULL, 0x2A7F6808E9A2DECDULL, 0xD3B0A0E90C268EB1ULL, 0x91061D89C9BEAFD5ULL, 
            0x7FE90E9521164898ULL, 0x5A1A7139BC6D0E15ULL, 0x8F5393192DABFE1BULL, 0xD8DE09876F100E62ULL
        },
        {
            0x13B94D24FAB0F13BULL, 0x67135A52E60E7758ULL, 0x8D6720E1D33C5310ULL, 0x46DC8F91EF888E2DULL, 
            0xE71C7458CB53F4ACULL, 0x946A25FA2F908463ULL, 0x6065FC92EB095725ULL, 0x3F1DF1AE47B50F84ULL, 
            0xB5EE2CE83EFA5F76ULL, 0x6805BC3A73ABE293ULL, 0x39043D1116D5ACE5ULL, 0x73675715923C6C45ULL, 
            0x7EE8680241D5AE3AULL, 0x791107FA6387EB63ULL, 0x9813B29593151734ULL, 0x2528523D60CC43C6ULL, 
            0xA42DE22A054836EEULL, 0x03B7F673C914690AULL, 0x7AF660A05A0FD49FULL, 0x413A8EF0F92F20FDULL, 
            0xE4258D97F2E59AE4ULL, 0xC5A8F21E24D78D84ULL, 0x5A9CDCBB1238E1F0ULL, 0xF4270BC1A6A6C285ULL, 
            0xA1140E4183EBBA4EULL, 0xECC7413044C8A81DULL, 0x5EB5D2A8849A614DULL, 0x8DAC77FB9FBF79A2ULL, 
            0x8A72AF67AE6AB336ULL, 0xD348F1039D452E85ULL, 0xB5BC3D6A478F3516ULL, 0x75236697BDB1B7B6ULL
        },
        {
            0x08AF1F0CC4688F73ULL, 0x608E20740099D4AEULL, 0x57FC67DD841D2979ULL, 0xAA1E3B4BAEAD7C22ULL, 
            0x7CD1A4078A253046ULL, 0xAB71F6B2522C315DULL, 0xB4041E479FDFF6AFULL, 0x62FA71EC7FC67F30ULL, 
            0x2C0EF470AA5C8EAFULL, 0x0BA0F98CD6BDADF2ULL, 0xEA78FC6A0C5D588CULL, 0x88277B4CAADBFA4EULL, 
            0xEA53BE11ACF24974ULL, 0x96BF93B5413F5BADULL, 0x253ED5354CC15DC0ULL, 0x45C95FB4CD443B5AULL, 
            0xB95EDF72BD46DD48ULL, 0xA74B633FEE08B4B6ULL, 0x3CC7413906AF85C6ULL, 0xF5C7EFA18D8C2977ULL, 
            0x97097C9ED2ABF762ULL, 0xF025A50779815DB8ULL, 0x58C0E0F40FB41A13ULL, 0x77ED3CBE4137E3C8ULL, 
            0xEF789AAED249FFF5ULL, 0xC052638401BC6602ULL, 0x78C427A25D887C0FULL, 0x4E59A920538307B3ULL, 
            0xF9F2BCFD09DCDE61ULL, 0x03755658EA57A604ULL, 0x1FEE8906A08DC697ULL, 0x492AE6B2A3946D04ULL
        },
        {
            0x5C37C22091993FADULL, 0x74598A2D41DF2AD4ULL, 0x068CA126281C5F26ULL, 0x75BCF1B8CE026F69ULL, 
            0xA0D423FFA68CBF99ULL, 0x19541757BE931725ULL, 0x12B1E3C2831208AFULL, 0x82DB80AA607396B9ULL, 
            0x151547B7C900797FULL, 0x92902B0AB7EE5738ULL, 0xD94BDE020D022A37ULL, 0xB7C3719015C3FFCDULL, 
            0x64167E8938A127C6ULL, 0x6DE14079EEA0A9F4ULL, 0x862A6B76D4EA5BA1ULL, 0x45DB2FFA96AE99D1ULL, 
            0x05F32659ABC4AFDBULL, 0x81E53F068D145B33ULL, 0x485CD57805755FC1ULL, 0x968C8747AFF4CD72ULL, 
            0x49F88CA8A47BDC53ULL, 0x1E30B2283BED6794ULL, 0xBBE8E8C5E358A126ULL, 0x86F60FE22E0750CEULL, 
            0xDCE6B90760E919CBULL, 0xD01BE1B4BD6D1F5EULL, 0x0D6B65444FD27AC6ULL, 0xF186EC9453485DACULL, 
            0xCF4920F586B4B12BULL, 0xF6732A8D5AADF875ULL, 0x0240F1C6FF658988ULL, 0x0E18664AE31532BEULL
        },
        {
            0x06F896EFC67D041BULL, 0xEA1B91BA7BCBD8EAULL, 0x080FA4A8AB1AC5C1ULL, 0x787C239206B3B6D7ULL, 
            0xE144C02A4D69012AULL, 0x0E5BF004EADCA48EULL, 0xD71F3244DAD50484ULL, 0x96828DE59F488D19ULL, 
            0x4E0B9C07316591FFULL, 0x9631F2C96BA24287ULL, 0x1DE61B140F09CF1AULL, 0xB8D539787AA41FAAULL, 
            0xBB550807FF49157AULL, 0x0B69AD82E899BE00ULL, 0x8D06060004CFE59CULL, 0x05BF08BEE2B725F1ULL, 
            0x2C5CCD4626B42B65ULL, 0xEB94785557012363ULL, 0x1D2D9A7DADEF0175ULL, 0x2422E7E96AF57438ULL, 
            0x989952F71FEBEE5EULL, 0xE3A7078C0D6ED2D4ULL, 0x56EE47C6CBDC2786ULL, 0xE038912DE04D5821ULL, 
            0x7109721C5B1D6614ULL, 0x35E9167B0BE792F2ULL, 0xC2D50AB24902A726ULL, 0xB79DB467E32C32F3ULL, 
            0x018D8392AD74AE3AULL, 0xCC8A09FF79001F26ULL, 0xFFB081E6CFC60CF4ULL, 0x5027F69972EA3FA8ULL
        }
    },
    {
        {
            0xEAE146E4802E5BB1ULL, 0x9FCD1D11F645C871ULL, 0x1E98788200BD0BBFULL, 0xA10D32B5E52E7C28ULL, 
            0x7C750DA4D7910090ULL, 0x6590B49A9860E76DULL, 0x73164395C18D6BD2ULL, 0x9D7E3E4A09CDB3E3ULL, 
            0x687FA24281040A60ULL, 0xF341A4627AA14E5BULL, 0x2604BA1F77D9CF68ULL, 0x4DEB7B13FB15DE02ULL, 
            0x5AB83BAE678CEC0EULL, 0x05A50907E6B2033FULL, 0xE113C9B6725CE77FULL, 0x78A99A2BE8521E70ULL, 
            0x88C2AAF99D1B4318ULL, 0x6D378902A43B58E9ULL, 0xC5A561501E55692FULL, 0x0D654DE919AFE7F5ULL, 
            0x6EC45F65CA732C79ULL, 0x144CDA34E8210286ULL, 0xD5CD66A3CF99A600ULL, 0xA9828F49243CA600ULL, 
            0x971E76340DECC876ULL, 0xCBEF59EEF4C34327ULL, 0x9B00C3CD9D6E87FFULL, 0x3727F9977F3CAFB8ULL, 
            0xEE02EE9DE45FFF1DULL, 0x8BB51A59D5804C25ULL, 0x1B180EA116476B54ULL, 0xFF90D33309E6BAAEULL
        },
        {
            0xA196085D870DAA8EULL, 0x5A7AB9305233EFEAULL, 0xD5FE7048371DBF46ULL, 0xBD040319060438BEULL, 
            0xD0F8EED4E140EEC0ULL, 0x9F2142E6BA390B08ULL, 0x988866C499C08905ULL, 0xF792616AEA7B844EULL, 
            0x2D289DC919B916A7ULL, 0xE1E449896F9051D1ULL, 0xB9B7CC4C02723DB0ULL, 0x63C2266D60B25B3CULL, 
            0x55BF6702D06420A7ULL, 0x250C01E9242C6C78ULL, 0xD1E9C02EF31A26DAULL, 0xB6678458AB1EDF60ULL, 
            0x1941289BF67E1C2EULL, 0xF58274AF2B8C80D5ULL, 0x4C10D953222721F0ULL, 0x7F95165EE030251CULL, 
            0x2D4B96E381D83C42ULL, 0x15FA0A5DAA0B5B9EULL, 0x0CE15C9D97081542ULL, 0xFC43FB08CA579FB2ULL, 
            0x84A974BA8486B6CBULL, 0xE470518096913C9DULL, 0x82F84D082F696BC2ULL, 0xD29334031930F652ULL, 
            0xC7C634E8759896E9ULL, 0xB35A674B06BD7C2AULL, 0xBF450F84CEC7F7CDULL, 0xFA70CDD6EE2001FFULL
        },
        {
            0xF898E3E8943055A0ULL, 0xBE61D59C15FA98D5ULL, 0x8F83C6E5759C04A3ULL, 0xB9A3AE5E4D27586DULL, 
            0xAFD0B59813E80AC1ULL, 0xB796B1196C3A5B38ULL, 0xE44950BBCDBBD342ULL, 0x5B5D269B451BED31ULL, 
            0x5B7FB141F996BFC8ULL, 0x4F8317F43BBD5823ULL, 0x98F5D1FB4BA1B18FULL, 0xAD4D947989882014ULL, 
            0x667A4115657AED3BULL, 0x85EE6B0258343E96ULL, 0xBB0C2C0D574CFD78ULL, 0xD25B2D474715213CULL, 
            0x5B56991572332878ULL, 0xC55B1E858033E743ULL, 0x57D655FE220867CAULL, 0x820B650FE25B6930ULL, 
            0xE1BE41CE247E4984ULL, 0x9521AC736F6DE2ABULL, 0xBD76AAFC7C54B476ULL, 0xF7C13B1012BA2ED2ULL, 
            0x4F8DCBF857F6EBEDULL, 0x6DA064B8147870C2ULL, 0x4E860B881726DDC5ULL, 0xD4753E44889C78F2ULL, 
            0x95749ED933C7E660ULL, 0x9532E379BDF71C68ULL, 0xB8904C63C1942898ULL, 0x6CC31FC474DAA786ULL
        },
        {
            0x7F78AF971FC8A36AULL, 0xCCB314527B9B790FULL, 0x1E62235F91E7A1C5ULL, 0x0333106C3B119150ULL, 
            0x7920BAC111FDB201ULL, 0x7F4673DF18084B10ULL, 0xCE1D2AAF65DD9311ULL, 0xF40772B39CCD4092ULL, 
            0xA1A82509E5BC0F3AULL, 0xF0F500EC69DC208FULL, 0xC603609967199CC8ULL, 0x3B2254DBD0BFF202ULL, 
            0xF496B663BF997FADULL, 0xC7C2BD42205A1BDFULL, 0xA7DCE58BBC937F66ULL, 0x4E37584B2C241FE7ULL, 
            0xE112923FE7C6ED76ULL, 0xCA982FE8E945714CULL, 0x438F05F40AC86FA6ULL, 0x144CA692939C1D70ULL, 
            0x0BD90E87514608FAULL, 0x57F7C67252ADDED2ULL, 0x8D04F46093FEF488ULL, 0x35493D0A06AADFCAULL, 
            0x356FC319CE87C02CULL, 0x0949F36672ADFE9EULL, 0x8C6054A24E5DFEDEULL, 0xAB1B5E4802CB99A3ULL, 
            0x86684CF70CB9F097ULL, 0x3F26C57A6621B3CBULL, 0xBBF0EFDE6724AB78ULL, 0x8DAF0E2D5C6FECF9ULL
        },
        {
            0xF2EC116D6E60A696ULL, 0xC3DFF830586EC885ULL, 0x844D05145F6694ACULL, 0x7515C985FB98B69AULL, 
            0x653FDE958539D486ULL, 0xBE689860F717677DULL, 0xAA180D6735C0B76EULL, 0x8C722D8A6A8FBB98ULL, 
            0x0E995E448E8620C3ULL, 0xE8361DA4501BBDA1ULL, 0xCA97D9ADC1E54A7DULL, 0x5D4C6D1A302883A7ULL, 
            0x80E18436A601756AULL, 0x2CA3466EA45EDC54ULL, 0xB3935E9ABF987E6AULL, 0x96DBBAD79C46E51AULL, 
            0xB31D034EFBF9C52CULL, 0xFEA1EFC3145A921DULL, 0xA94B0CBB3D7AA41DULL, 0x6C0EBF6EC1B6CAEDULL, 
            0x1D1E6043FDE9CD3FULL, 0x2284098472B24823ULL, 0xFA24B3C84E00A85AULL, 0x208D17EC8FD0B63EULL, 
            0xBF4996D3420129BCULL, 0x405E07CDEF61D3C2ULL, 0xC89C861F121D18A8ULL, 0x02E1D26EC67CC82BULL, 
            0xCF696A23C538140CULL, 0x94FBC7EEC6DA6229ULL, 0x3241B81A2FE9B365ULL, 0x07553E179C2CBAE3ULL
        },
        {
            0x48D37DBE02C9DB49ULL, 0x87492BA17BAF8DE9ULL, 0xA41F1E4D9AB40F68ULL, 0xCF928F027BFCAE98ULL, 
            0xFC24B004A5616605ULL, 0x7A45453E37305EE9ULL, 0xE25DC1BA606444D7ULL, 0x91609C7150CD69BAULL, 
            0x2C601A5798D78E23ULL, 0x84F734735A1FCDB4ULL, 0x8C4C0DAAFB454361ULL, 0x9471DB842A2F6CFDULL, 
            0x7EBFC4A6E1457183ULL, 0x78306AF3AE546FAEULL, 0xF7AA358136580EEAULL, 0x71579BFA6C5D5C29ULL, 
            0x0C8C1E3D96708659ULL, 0xFC84C8F1E2E2BB22ULL, 0xE16E6D54D3944389ULL, 0xD44FF32F80268579ULL, 
            0x8D070F4F12EBEF6AULL, 0x98F04EC05BACC0D7ULL, 0x8ABF4C8BB2CA3BAEULL, 0x67157C0751F2755EULL, 
            0x362D98AC067E021EULL, 0x277D99CFC97A0961ULL, 0x72B7C94CEBC59527ULL, 0x756A14E190EDF2D6ULL, 
            0x72ECCFB680243574ULL, 0x952AF3FB9CB99096ULL, 0x844ED034A0F43A4FULL, 0x65B50055AC973830ULL
        }
    },
    {
        {
            0x96F48ECC9676CBF0ULL, 0x50D71AD12351128FULL, 0xF705CC751CFA5826ULL, 0x258FD44D89AA7E61ULL, 
            0xCAB27E2763E0DB8CULL, 0xC6EC49F1644475F9ULL, 0x86F8BBDB3F88179DULL, 0xFB6996D5FC62CE5BULL, 
            0xF244FC4E819C9250ULL, 0x5F53865361A0F748ULL, 0x3FE642A3E3AACCD1ULL, 0xECBD45874F947F0DULL, 
            0x0B0E6E4579434142ULL, 0xC1C9179D6580B6FAULL, 0xC8A3A6239BC5D54FULL, 0x70B300A6277EFC8AULL, 
            0x90DF1013675753D7ULL, 0x30A4939765ECF9BDULL, 0xAACE7D05B131D7E7ULL, 0xE7E237CDBBC7753EULL, 
            0xF1E153B2937F71C7ULL, 0xD88D3128D6D17CACULL, 0x2F57B722A60670C5ULL, 0x7DD8C0DE6940CBEEULL, 
            0xAA2C4AC507F540EFULL, 0xD5D1437BC6E2B24BULL, 0x77D4B98F38E15275ULL, 0x76D27CBDD74A58F1ULL, 
            0xAD791191DC48106BULL, 0x23AA33CFB6A0C27BULL, 0x967967E591F771CFULL, 0x45A4EFE8DE5A48BDULL
        },
        {
            0xF37799BAE463EEFAULL, 0x3F0AA3E2E6A0D87EULL, 0xE0F4AC4DBE8C60F1ULL, 0x4268ABB0A6887D66ULL, 
            0x900AA4A0D0D5F92EULL, 0x5512E97580F2329BULL, 0x4550D40E51992AE7ULL, 0x6FB1F705933D739DULL, 
            0xE17994A70A5490BDULL, 0x7198D624F5CFB6B7ULL, 0x2393638317C8E56CULL, 0x9C2BC7CFF112534FULL, 
            0x306C2907CBA52610ULL, 0xB19187735293B1CDULL, 0xB33C490ED4A80D1DULL, 0x2B0573D92640D0C1ULL, 
            0xC38378A5BB72B563ULL, 0x047129AB25F23240ULL, 0xD22251A6D3D1E126ULL, 0x801E6C2ACA391658ULL, 
            0x4DC93C19A5ED1BDBULL, 0xD0FBB5BE166216A0ULL, 0x82555271865A4946ULL, 0xA61326E3D1C52C30ULL, 
            0x79EC758DC62599CAULL, 0xE1ACCC4CFC8E3FEDULL, 0x66E83C20868E87D6ULL, 0x5C6F5C07EDFFE1D7ULL, 
            0x9CF948946592BB43ULL, 0xB96F476AFAC6D1A7ULL, 0x792BCE56A833D221ULL, 0xEF385CD7E23FD101ULL
        },
        {
            0x9E4DC718D92795E7ULL, 0x94EA1B1F8D5FD050ULL, 0x5268ACA98ED32F3AULL, 0x0D672A8BD3F20523ULL, 
            0x046EEFFF180E0DCBULL, 0x121D2716F0EC3ADDULL, 0xE908D0A7304E30B9ULL, 0xB896E440534A2F04ULL, 
            0x9013253526680347ULL, 0x4917B18AA411FEF3ULL, 0xF54DB535C0CE0EB7ULL, 0xD42815E8505149F7ULL, 
            0x0A98287B29EA0E2EULL, 0x0B23F05A14935798ULL, 0x5EFFBFD2C98E0706ULL, 0x9746A075C389BA15ULL, 
            0x21A64222BC7669F0ULL, 0x8B00E53D1C1AE0F8ULL, 0x3644B83A3E3CF004ULL, 0xC6AD52D744141602ULL, 
            0x3D9AB44A5973CD9AULL, 0x7BAABD6DF0BD2537ULL, 0xDB18ACF91BB05A76ULL, 0xDA69E3F1ADFD4D36ULL, 
            0x28A94DC92858EBD4ULL, 0xB3D302537170B03AULL, 0xEB27D6EE3755CAFDULL, 0x3CA1F1CAAE7F0634ULL, 
            0xF296D7CBEC90F6DEULL, 0x62D5AF6846789A5EULL, 0x48F5B0DF7B80F9E5ULL, 0xA9BC11331C8BE7DFULL
        },
        {
            0x03B08E4B01122FEDULL, 0x5C343F51D252C58AULL, 0x6FE854C5BC2018DCULL, 0xDDBBA5037109CC0BULL, 
            0x15F6EA5CB7BABB7CULL, 0xF2E1B3BFA3E3DC53ULL, 0x7B31887A883619F3ULL, 0xBA101B14FB469309ULL, 
            0x76729587B34C970EULL, 0xE9B86491C6AB42C4ULL, 0xB7F72B023E6A901BULL, 0xB4E5429EE575EE39ULL, 
            0xCEB9D4FD9EFC4353ULL, 0x96E735BA48E737A6ULL, 0x396C0F78D1190561ULL, 0x3E1BB72E10936201ULL, 
            0x924D8047C227DD01ULL, 0x4AE38A57EB105EE5ULL, 0x4D641631246F87A3ULL, 0x6CCCCA05437B00ABULL, 
            0xA0564C54870971C2ULL, 0xAE5D4BB3E6E8ECD1ULL, 0xFE2551EF7193CFC6ULL, 0xF6AA978AA3F08C59ULL, 
            0x6F637D6B40E5C3B3ULL, 0x5FCF7F71182EC329ULL, 0x4827323777337A91ULL, 0x9850E3C800FB7B22ULL, 
            0xA1121C2E062FB77DULL, 0x104427AE445FE145ULL, 0x5B3A04912D178975ULL, 0x99D9E828B1976D0FULL
        },
        {
            0x9051391D07DD1298ULL, 0xE94914F996A9253BULL, 0x58AFD8942E953EA6ULL, 0x2DA764C94082A413ULL, 
            0xF0C3683613C3EA53ULL, 0x0519018C277E9404ULL, 0x2340DE7543CB8E22ULL, 0x1A1DA455821EA620ULL, 
            0x046E70679ABE425EULL, 0xC74AA113262C72C1ULL, 0xAFF296DA87D5BC48ULL, 0xCB0FED75681CB509ULL, 
            0x082B9F1D3F50FC8BULL, 0xE2F46B3216503C4EULL, 0xF044D9EF3FBA7FE6ULL, 0x418C6A446EA7F263ULL, 
            0xBAC7FE392A76AA19ULL, 0xCC6BFE10750DB4E0ULL, 0x798178F8459CF0FBULL, 0x49725E3AB391CCC9ULL, 
            0xEF8D7913E1939F56ULL, 0xC07C6B2F2D8DCE2FULL, 0xBA12E75FDDF410BDULL, 0xFBE6C63CC1444EAEULL, 
            0x76EE52D3EAF601A8ULL, 0xC92177E1AF3F5295ULL, 0xC6EC01C0FB0AD3D6ULL, 0x7DFB1CD23677D903ULL, 
            0x7E3C6B9B1CD2B565ULL, 0x2B1F96848C6537C7ULL, 0x93D4F60B61009A90ULL, 0x5370434644AF2506ULL
        },
        {
            0x5AA7AAB005A77596ULL, 0x1C29161CEFB070CCULL, 0x5139C285F188FB9FULL, 0x6FF020A93753742DULL, 
            0xDD7104EE295F5160ULL, 0xD7A33C5F1F9E236FULL, 0x4774DCE481EBA15CULL, 0x4ABF8D9A75400663ULL, 
            0xB26E53FA12E20802ULL, 0xC67CB9E2F013ADCDULL, 0x6E3CB7952F067A8DULL, 0x6745CC56944CAEC5ULL, 
            0x7FA28892223FA04CULL, 0x769238F01FDA6600ULL, 0x78982048036A3E63ULL, 0x4FCD0A8120B4FF90ULL, 
            0x29696530C1C8989EULL, 0xD9FB91E729BD444CULL, 0x1C4D1F48FCA1536BULL, 0x47694677EDA6B9F6ULL, 
            0x4F1D7BB1D30B3EFFULL, 0x0198645DF3D9A210ULL, 0x0DAD036A812429D2ULL, 0x5554BDD678AE99A7ULL, 
            0xD9D7ACD6553EAFDEULL, 0x4DF768FC4F53A98AULL, 0x4129350D04716BA2ULL, 0xAEBEB8091B7AEC15ULL, 
            0xAEECB8B6CB83C885ULL, 0x1E5629E9D8CA5A83ULL, 0x6A2682455220DD75ULL, 0x8848441B6E85CEFDULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseCConstants = {
    0x7D1763B3505775F2ULL,
    0x5BA407A36DACAB20ULL,
    0x41FFAD0A7DF2EB9BULL,
    0x7D1763B3505775F2ULL,
    0x5BA407A36DACAB20ULL,
    0x41FFAD0A7DF2EB9BULL,
    0x732B8D157AE90C62ULL,
    0x3AF3E9BC0035A182ULL,
    0xA8,
    0x69,
    0x0A,
    0xD0,
    0x5D,
    0x41,
    0xDD,
    0xE2
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseDSalts = {
    {
        {
            0x7F25E3AF08FB6BFDULL, 0xC7D34045807FD390ULL, 0x16D7E22B5602B4BDULL, 0x607E26F8D5784B89ULL, 
            0x0618438534391B36ULL, 0xC7212A7472D95C28ULL, 0x7C66E5CC004C93F7ULL, 0xACF9ECBD95C872ECULL, 
            0x708A74EEA4312340ULL, 0x817497A8147300B5ULL, 0x15FEC53694ED214FULL, 0xA2EC74F44AB8DC9CULL, 
            0xC2F2A7D629225CD5ULL, 0xD68C731398123CDBULL, 0x4902AA403A1321D5ULL, 0x65AEC1B31ADADB9AULL, 
            0x5212B99B4751E66FULL, 0xA1BD7BCFA2B50E19ULL, 0x8BCEF729671A2FE9ULL, 0x13458E98C329F9A7ULL, 
            0x246F7764CF774C76ULL, 0x439DF3BD3F677FEDULL, 0x455AC3B0FAD9E136ULL, 0xF24CC34C30196D9FULL, 
            0x341AF2A1D1ADAA02ULL, 0xE554AA6116E5E033ULL, 0x6A0D41A7CAE52334ULL, 0x617A7CCEF1BC1A76ULL, 
            0xCB2BB6DB60029BB4ULL, 0xC16F11E2A716D4D4ULL, 0xA3F3EB5DE041CBB9ULL, 0x876369BF5B576DD5ULL
        },
        {
            0x89E53456046C6F7EULL, 0xB5EA49ABFDA49D90ULL, 0xD417460E8B3813F7ULL, 0xACA53D4C8BE4087DULL, 
            0x96BBBB1886CACA3FULL, 0x90D1F62B928BBAA3ULL, 0xECD3173E462BEAA6ULL, 0xC6455EAAC7C67332ULL, 
            0xC7BF3774AFD053B1ULL, 0xB9C86A6FB176B8F8ULL, 0xD2E11AC456228250ULL, 0x949F60A23C2A86E5ULL, 
            0xAE5E162BE8852A51ULL, 0x42412D83DF526539ULL, 0xB38EBBAF928ECA26ULL, 0xE6AF9C417D6B92ECULL, 
            0x04142C4EA54E2F7AULL, 0xF6703CB08CA64402ULL, 0xF1BA0A9D4BFB87A6ULL, 0x2F976E351057320FULL, 
            0xF30AD0AE23D0679BULL, 0x60835FC41C3AF5FDULL, 0x0AA4FFED4E901A72ULL, 0xBA1BBE11B0568422ULL, 
            0x3ED118FA0C9BA0A5ULL, 0xCA9B5CA6B73EA001ULL, 0x92C700811BE72A72ULL, 0x35F7392D8173E1C5ULL, 
            0x8DC1BECC893BF106ULL, 0x81D62C941BF42575ULL, 0x77887BC463A3BEFEULL, 0xF660C3982D0C7C07ULL
        },
        {
            0x99775FC497360805ULL, 0x45E3909CA70075EBULL, 0x2D5936474BAC2A7AULL, 0xBD2443611BF0F1DEULL, 
            0x780B0CF237754705ULL, 0x568F5DFA1FC28C4EULL, 0xCF68CBCA0ADFBC51ULL, 0x5C36DD11C11103CEULL, 
            0xC000587034100FBBULL, 0x502DCADC26E6C7E7ULL, 0xB0904DB4276272A5ULL, 0x1EC70800456D70E7ULL, 
            0x0D58DC06987B7435ULL, 0x3DF1E94F9E047929ULL, 0x86032EC1FAA24213ULL, 0xF8B2A34667CE7848ULL, 
            0xA4849F4310098BA6ULL, 0xD34A26220626CFD3ULL, 0x74DE5DF993609560ULL, 0x222CD0EC859DE10AULL, 
            0xF0F05A7CF61AF835ULL, 0xC061219DE77590FAULL, 0x72F0FB4B7B779FA7ULL, 0x47338BD8AE23426AULL, 
            0x92A7CC7B904F5164ULL, 0x556FE5B75C0724D2ULL, 0x7B43DC41DF28A3CBULL, 0x429B585E076ABA72ULL, 
            0x38384C870965F5BDULL, 0x9D52A7A9EC7125A2ULL, 0x5DEFCB80CADD7727ULL, 0x7F3F9484BFBE2064ULL
        },
        {
            0x2ED0C376E559112AULL, 0x8E0C6A37E4FCB0F3ULL, 0xE6EC90190EABE9B4ULL, 0xE55E71D311AE0CE6ULL, 
            0x97E6F16A57235897ULL, 0x81424AE38096FFA8ULL, 0x249DEE7CBFBA9B24ULL, 0xA7764A9CE54B3AFAULL, 
            0x62F47A51BF96C261ULL, 0x26865C3C770E738EULL, 0xBE0F45B16311FE06ULL, 0x724B118AF940A4ABULL, 
            0x825F82D9BA68E4D1ULL, 0x5B97291F0A28965DULL, 0x57379E6E148F6EE3ULL, 0xE9492A92AB8F264FULL, 
            0x881468652D3C8DD1ULL, 0xF4C907699DDE4725ULL, 0x5773463EC92E4815ULL, 0x3C20A6E7248BAD4AULL, 
            0x46BAE32FE1566BA5ULL, 0x90FFAA706656FE30ULL, 0xAB716ADECF5CF3A3ULL, 0x19B7A77FAC37802EULL, 
            0x6472C1BC7EF36A3CULL, 0x0C2BEEB075D57936ULL, 0x7E0E53FA067AC1D3ULL, 0x843EC22426A910B7ULL, 
            0x10BC09D893E42997ULL, 0x1C726816C5976E02ULL, 0xFCC7EFC5996851CDULL, 0x01018F9718F42969ULL
        },
        {
            0x7951B0B87BF526B5ULL, 0xB5963DAF4DBDCD82ULL, 0x2FD084CBF90523E9ULL, 0x12AB16B28B5144D4ULL, 
            0xBA519E0CD7065033ULL, 0xBAFEEB42D14B270FULL, 0x550D35D91EA82696ULL, 0x6EA8D13007FF8AA7ULL, 
            0x77A70B42E5D8F9B1ULL, 0xE4A605486D691276ULL, 0x75D9EA04DD44CAE2ULL, 0x689EC075A3D35091ULL, 
            0x3098B32B4B4537C9ULL, 0xF00C1E2D0F7333BBULL, 0x3DAB0EFF44B1C2C2ULL, 0xDA55F4B9A831CBEAULL, 
            0xDDEFABE01B7D3C2CULL, 0x8093DE21F88C24DBULL, 0x5907E3579BC7AA49ULL, 0x7B6C13AF5B58F0F1ULL, 
            0xD967796F9C92E25EULL, 0x52C10EAAE7D925E0ULL, 0xC99B07C880E79DEBULL, 0x280FA62AF00A1234ULL, 
            0x8DA6B2215A76C8FBULL, 0xC47F851D920D5D41ULL, 0x9C4037C6596D04D2ULL, 0xF85A4FFEB489CD22ULL, 
            0xE6ED64AA0AE82E74ULL, 0xAB72631DE3D18481ULL, 0x2FFBA17A749F828CULL, 0xD132D9DDCDC43D23ULL
        },
        {
            0xE784D1D02025B9DAULL, 0x29768DE9869E7E8AULL, 0x64C9CDC43BF283A5ULL, 0xD455F7739047DC75ULL, 
            0x2D63A672432C43BCULL, 0x1859B8C636A7E567ULL, 0x7D4CC6F18399877BULL, 0x8FCA583790DFEBFAULL, 
            0x97B78DE99F73A88EULL, 0x1C45CBC372799275ULL, 0x1EC8AB1C34D44B7FULL, 0xF16A509E87AFB688ULL, 
            0x6EFB62CFBFAD6DD7ULL, 0xAD1CDC79D4E96FA8ULL, 0xACC0BDB312684595ULL, 0x09BA5E5F046AE576ULL, 
            0x4B038F2595C43C02ULL, 0x8DCCD323ACE8F22FULL, 0xBAA61114FB8BC941ULL, 0x591249E36B712308ULL, 
            0xA5EB17EF39637825ULL, 0xD44F3AEFD463FD28ULL, 0x52BA2D9496427BCAULL, 0xBAE732782AFED716ULL, 
            0x5C90CD7D49D9D397ULL, 0x3BF101D1A5C2F67BULL, 0x5FCF8450372CF8DAULL, 0xE474F2E533AD6C83ULL, 
            0x9999FF5571260640ULL, 0xBD257FA38F9C0536ULL, 0x0C589B814E646148ULL, 0x75852D4E643FC2BAULL
        }
    },
    {
        {
            0x95876F1EA06A38A5ULL, 0x6937C438E108ED52ULL, 0x90137BB0B0641609ULL, 0xF100C57E1C3BE77BULL, 
            0x6C70988C7AEE5775ULL, 0x77F8FD25217683AEULL, 0x9B51BF46D9A86E93ULL, 0xDDE49EFEF08CAD25ULL, 
            0x30CED4BFE44796B4ULL, 0x5D3818A19B5E3EE2ULL, 0x2FAA180AABBDF18EULL, 0x534FF3215A1FAD87ULL, 
            0x3A82A2927C058D62ULL, 0x9706CDCFA5ECC0FFULL, 0x7532794091419AF5ULL, 0xF3E44A4001FE9F16ULL, 
            0xC669731B573B5B85ULL, 0xFA3BC7799A4FBC27ULL, 0x4E2DA6CA9D3E08B9ULL, 0x4E58E4F70D8B01EAULL, 
            0x127F7503E1E12963ULL, 0x7A4D5A48E3F7DB07ULL, 0x5040E5155848A031ULL, 0x9EF7E319556257C3ULL, 
            0xDB45FDAC0DBFF05AULL, 0x0BBCE25477BBDFFAULL, 0x7BA1DEAA0D3DF9B6ULL, 0xDE20EBD86AF7FDA2ULL, 
            0x5D8E4BE0B2D5FFE4ULL, 0xAFEEB2C4CAD36D4FULL, 0x709A2816573B0B84ULL, 0xA341EF409F824825ULL
        },
        {
            0x9F4717401ADFA933ULL, 0x69F5E7DBF2062FF0ULL, 0x6199ABE470AA6E98ULL, 0xDA4F2E558D0F5A0DULL, 
            0xCE7F198EBE21D330ULL, 0x87882A27FF84F60FULL, 0x11745A8B33049DEAULL, 0xC85F6428E29C25A0ULL, 
            0x22FCDD1C4BCFAE45ULL, 0x037F55E6F6182DCAULL, 0x0C036B63830ECCD1ULL, 0xABE2C4D114935D46ULL, 
            0xC46BFF53A9635D2BULL, 0x9706B450A9D85231ULL, 0xDF298126160BF08BULL, 0x3D51C5B3F05B0681ULL, 
            0x1F02AE73E808FD89ULL, 0x729BB2ADBEF843FAULL, 0x5A67617AA030C9A5ULL, 0x003BC0E01389806DULL, 
            0xA3BCE42F6EEFFD12ULL, 0x993363B489DBF025ULL, 0x1B68A63B310FEE0FULL, 0xA125D46576AAA5CAULL, 
            0xAEB0E59B8B372A9FULL, 0xE7B18351CB31066EULL, 0x7EB971325850EB04ULL, 0x829B17DDFB1845D1ULL, 
            0x0F81E90795AA1C16ULL, 0x4B5C11600334C729ULL, 0x505ACD6DF8D6DFBCULL, 0x3F075555E9069A77ULL
        },
        {
            0x0BC9723FCFCF4AE3ULL, 0x27E54722A725A9AEULL, 0xE6CD8BAB075D0778ULL, 0xCD3271C86A8FE6CDULL, 
            0x84B7AA7968DBE3FCULL, 0xD80EA6BEA99CACCEULL, 0x097D4EBC7BA6DA8BULL, 0x5091AFF02DB491C4ULL, 
            0x83AE18E2A11B905EULL, 0x4C70AEB318FAC6ABULL, 0xCBBC4D343CD5CC70ULL, 0xEC337CA9C30FAC80ULL, 
            0xD0C466C5EDCD6D2BULL, 0x9D943611DB20C4F9ULL, 0x0A31DE11BEA53F5CULL, 0xC4B15419C22F6701ULL, 
            0x310EF4071EEB49C4ULL, 0xC229B4E7B161F444ULL, 0x0AEB737600555321ULL, 0x4E3B6CE4270F4ED0ULL, 
            0xC86459D981397EA6ULL, 0xF7A9DE3D31DC5791ULL, 0xD22698DAF6DECAE1ULL, 0x795B327949B77AAAULL, 
            0xFF3B847041938429ULL, 0xFB342DDBCB234F0EULL, 0xED332A8383BAACD4ULL, 0xB93AB6F5153CDA44ULL, 
            0x662875771D45826AULL, 0x5D0A2C793237E8B9ULL, 0x44586FA4487B9293ULL, 0xD1F889164869D246ULL
        },
        {
            0xE5FCBE086ECBA0B8ULL, 0xD2286F5729334BF0ULL, 0xC00D29ACD890A92EULL, 0x3188355F11B7CF85ULL, 
            0xA693DDC0E00180BDULL, 0x68B9FFE620A0CA97ULL, 0x8AF6B800C911EABAULL, 0x3001DD9D0D039573ULL, 
            0x35D2E1893EFBAAD6ULL, 0x69CAF82EADF54233ULL, 0x16D84737DE374098ULL, 0x1E35D58C66584E3CULL, 
            0x9157E7B74F608953ULL, 0xF5675AFD0B610105ULL, 0xFA2E32A85CACA359ULL, 0xC56FA8B0DCE0D041ULL, 
            0x5D5C88D28F50F7C9ULL, 0x362D713ACF5A8AE4ULL, 0x2025D7B5ADA81358ULL, 0x608DB231BEF28E73ULL, 
            0xF352935429BED718ULL, 0x60156D1B62B1B239ULL, 0xFD6A07500C00C6A5ULL, 0xB9BDF7C25ADA1743ULL, 
            0x6F0425D330384B39ULL, 0x5A02CBAE82D78EF0ULL, 0xA60380DF4585809CULL, 0xFCC9020075D0FACFULL, 
            0xAD1921EF18FBF1A5ULL, 0x4F920AF2D6CE2B69ULL, 0xCB525CE8E77FE923ULL, 0xB1DE08FC0843ABC5ULL
        },
        {
            0x7FC102B81B291A6BULL, 0xEAA75D6F5F03CF66ULL, 0x360AEF9255140D7AULL, 0xBE4C301A37CBD9C0ULL, 
            0x480C1CAB2B8ADC80ULL, 0x9477CD5AA15D3677ULL, 0xB588C4E1B43CAF64ULL, 0xFA6C38EC486B9C2CULL, 
            0x8488693E51A56D5DULL, 0xA89699D43359BDD0ULL, 0xBDBFAE9B6DD82292ULL, 0x4D68BDB73AEA64DEULL, 
            0x78497B23A6FC806FULL, 0x43DA7993CE508F81ULL, 0x30A57BF0392904C4ULL, 0x04DF7CDBF57597A1ULL, 
            0x92C11FF7B47FCBA6ULL, 0xB6B55BEDD5893FCBULL, 0x4D5647A85A43B413ULL, 0xB8C02039B88D3A3FULL, 
            0x4D0F13F008E10A17ULL, 0xC5DDC9F542EE16E1ULL, 0xC04DC60578548707ULL, 0xD54539B9A6001ED1ULL, 
            0xCED12C48F6796613ULL, 0xEA056F44E335C109ULL, 0xE1F6E8C7157F9C01ULL, 0x1B69E097D70482FCULL, 
            0xA04BE27D821DF1A9ULL, 0x5F0C983C80345755ULL, 0xF05C025664EB1D51ULL, 0x1EDDFC19362DFCC1ULL
        },
        {
            0xBF6FD8E5A5EDDD21ULL, 0xB888FBAEC29421C6ULL, 0x36D60DEF8626D20BULL, 0xAC8EA441B4470F52ULL, 
            0x30E205CF500779ECULL, 0x19ED44892F4656BBULL, 0x8C0115904E22CE52ULL, 0x75BDAB72393AC588ULL, 
            0xBD42B6B29272DD3AULL, 0x09FCB3A7C9C5AF62ULL, 0x75F5317AF6748EB4ULL, 0xE79E17993AD035E7ULL, 
            0xCE4DD74898B72D21ULL, 0x91EC501E68113C22ULL, 0xBE24DE5C1F15C845ULL, 0xBB74C089DF252767ULL, 
            0xE478C7D693438F59ULL, 0xD999DC53DA957A14ULL, 0xE792FD5B0852EA90ULL, 0x437A97C6C321BE18ULL, 
            0x4DF2AC0B7F646801ULL, 0x21F85AB8D24DCBF2ULL, 0x4AFEABD72E410C21ULL, 0x9428D69F4F3435BFULL, 
            0x18CA4F180556D0A7ULL, 0x69CDEF48F0BA2032ULL, 0x0CA75AC5B43B9ACFULL, 0x6D00D8757E846B3FULL, 
            0x8C520DF38923CAE3ULL, 0xF70663D3CBF40826ULL, 0x779E5A693FBDE30CULL, 0xC485E60F1F3F13F5ULL
        }
    },
    {
        {
            0x2AFBDC61A7C1839AULL, 0xD6F4FAFE69186995ULL, 0x29A7426DF63508F6ULL, 0xED85A8395F8C8F8BULL, 
            0x3EBAAC8F7999A90BULL, 0x4FAC7A408ECB6733ULL, 0xE0B1B8F27DD6C9EAULL, 0xC4073987D0B507C5ULL, 
            0xD66EB9EF89FDA9EBULL, 0x38703332237B58BFULL, 0x975D7A5B4731960EULL, 0x1451EBB31B9B667CULL, 
            0xF2DC53E9D0DA2570ULL, 0xF19A0B91260368BDULL, 0x44E07B80BF1E6993ULL, 0xFEEEF7CCF4E4A4BAULL, 
            0xDAC38A53F0E9CEA7ULL, 0xE3C43562BEEE2259ULL, 0xDB89519327A4A540ULL, 0x05CC37FE6D08DFE0ULL, 
            0x7BF69998D2EE4E73ULL, 0x642C76515EFFC49EULL, 0x94BA2F123D5FDEABULL, 0xED6B98513568A537ULL, 
            0x97ABDECEBC676C23ULL, 0x2CD47C3CDE4E7F38ULL, 0xD0AE717BBB1FE47BULL, 0xC7992A4025D121CAULL, 
            0xA87DE121BFE33696ULL, 0xF8881620B03B6D1FULL, 0x99421A1BBF9BBFC1ULL, 0x05643B56934BDA07ULL
        },
        {
            0xD4C95121A3681328ULL, 0x94D476276904A21EULL, 0xA21AF30EE8CC007FULL, 0xAA03F5DDDC880752ULL, 
            0x300C61421B9ED074ULL, 0x86EC9C4A6AC65F62ULL, 0xA906F0F05A8F781CULL, 0x7824AACAD4F49E98ULL, 
            0xC973DA376C0524A4ULL, 0x5E068FF762BB9C66ULL, 0xFCDCD914CD074E19ULL, 0x6A59F8477AFD840DULL, 
            0x82DC279DA059F9DEULL, 0x04CD412771B11F02ULL, 0x93D8BD9C224241B0ULL, 0x2B8CD45133D1218FULL, 
            0x984EE08A220145B4ULL, 0xC09DCB805E1729B5ULL, 0x8CC1460DE48E54A7ULL, 0x375CEEC2AF475A23ULL, 
            0x6353683649824B8EULL, 0xEB8062234854A78CULL, 0x034FAF734ADA6859ULL, 0x7CDBBA3BA429D243ULL, 
            0xF751B1D43C8B9CFEULL, 0x5B93099A48FE396DULL, 0x7F5865F76D08BCECULL, 0x53ED7B684D03BA28ULL, 
            0xD43E9F3D7761874CULL, 0x51844C92E73FB73CULL, 0xC7E6FEFA212F7DCAULL, 0x0AC1E1EF025D9FAFULL
        },
        {
            0x5A569D4379A36632ULL, 0x683FF6F09545B07BULL, 0x7D08EE5A1D3A7BDEULL, 0xB4B0986C41EF47A2ULL, 
            0x41AEDF409335B976ULL, 0x172B4DEF4EC9AC7FULL, 0x1AFA1661F094712EULL, 0x29DD4CCDF43CA547ULL, 
            0x34EC346AB1504166ULL, 0xB498B785EC156D9FULL, 0xBBB1C85C761D3B71ULL, 0x9E27373DA97DF940ULL, 
            0x4122001208834AD7ULL, 0x3EB7A88E2553CC4AULL, 0x6D36F2F3F2AF2B3EULL, 0x7CB3C2C29A4A7FE7ULL, 
            0x87BB7E92FD25A7F2ULL, 0xA9EB0C7746F792E4ULL, 0xA1F688481602B9B7ULL, 0x6908F74BE621923EULL, 
            0x1DB529E04F4ECAEFULL, 0xC3115264B57F1A96ULL, 0xC7913E31DF07F861ULL, 0x770E76514B77C0D6ULL, 
            0xAD44FB6F5415CA15ULL, 0xADE919E9B49F6907ULL, 0x574CFD7C56EC812DULL, 0x71E147B0E465D1C7ULL, 
            0xC0131A45DE0CBA98ULL, 0x0EFBBD82DEF8F0DDULL, 0x73C3008EDC43EE1FULL, 0x38EA45408F550064ULL
        },
        {
            0x83F89CE65DB6B409ULL, 0xECE2FBB33BDE9ACCULL, 0x63DD091AFFF8FDFEULL, 0xEBC7F6B5A97BFDE4ULL, 
            0x17A74CCE3F0186E7ULL, 0x08F4DA63BEB9B6C6ULL, 0x6946B69F124B3184ULL, 0x68DEC47A21857404ULL, 
            0x555A80730F8B3897ULL, 0x6FBF3FF31813FDA7ULL, 0x745BA5513B032FBAULL, 0x80AFFC730F2FCB2DULL, 
            0x9EC6AE5FDA8C7865ULL, 0x51934E0308879897ULL, 0x1495455EC75C8773ULL, 0x9211093CCB49649EULL, 
            0x51616AB3FD9FDBF7ULL, 0x67ADC7CF61F3C9F2ULL, 0x0525D6950599CD23ULL, 0xFC607693316863C2ULL, 
            0x819162AEDD38EBA1ULL, 0x1A6CE6BBBD6DE28BULL, 0x2D91A90E17E37C0AULL, 0x0421BF4EFC1EF2C6ULL, 
            0x419A143EFE15D8E4ULL, 0x18805EEDC81BC1BCULL, 0x38096EC7B52CB107ULL, 0xD563A618898DD7EBULL, 
            0x4FFF477C4AB22991ULL, 0x6B7D7CC0B59C1699ULL, 0x20554E80F04B8CB4ULL, 0xDC8F1E415D4EDD19ULL
        },
        {
            0xB3C91666E37DA492ULL, 0x23380FA0FF1C39CCULL, 0x0D3E2664D498FE4DULL, 0xF29BB9B2FE77BACAULL, 
            0xE81E86C784EA476BULL, 0xE4DC3F549A149A57ULL, 0x0A9DD0C33D600C72ULL, 0x4AB396DEEBC4D174ULL, 
            0x9E7776F7595DE6BCULL, 0x0FF2EFD4C3DDC0CDULL, 0x0447FEEF13AD9F85ULL, 0x33E9481DF5F1AF5BULL, 
            0x07A230FF3FDBE581ULL, 0x9B9AB2FE28E95A3CULL, 0xA5764CEFE28D2FE8ULL, 0x8A7C468287C6F2AFULL, 
            0x4616F828D0EF6FB0ULL, 0xC49AEE252EFAAD80ULL, 0x1DFCEEE0971381DAULL, 0x97C806B6D16D56FEULL, 
            0x90696A40B1339388ULL, 0x9C39ED3AD3EF42D4ULL, 0x39D501329C2ED4B5ULL, 0x17567CD8787CCC09ULL, 
            0x84D8F9937BA06462ULL, 0xF2F1CE511734B9F9ULL, 0xC836F340D7FA73B5ULL, 0x13F20A45E2E49D6FULL, 
            0xAA3597E960C188F4ULL, 0xB8DB85DF786DCC4FULL, 0xCDD50337FE04605DULL, 0x221F662E9485CCB6ULL
        },
        {
            0x59699172D5C6CD0CULL, 0xC1F57A76C2E00B13ULL, 0xCD3D00A26BE2EEE6ULL, 0x42FF3A855E595ADBULL, 
            0x2A0037E29C4BBB81ULL, 0x6950DF736D98C030ULL, 0x2C53B160B9ADA4A9ULL, 0xAB1939C0D2341BB6ULL, 
            0x1E92FB2AC731994CULL, 0x1FE9DC90649DA61CULL, 0x2C22DF42FB1959BAULL, 0xEC086E5DE9C821F3ULL, 
            0x2F9089729ADA197EULL, 0x54DBDAE4A2465ED1ULL, 0x035284747F8AB715ULL, 0x69C3728CDA3E53C2ULL, 
            0x88C3F8C2CD9380FCULL, 0x545B5399E7761288ULL, 0xC0FA05AB0073413DULL, 0x5CB989A020C06DD0ULL, 
            0xFA8B4D0685C492FDULL, 0x3F3DF6A4636FA78CULL, 0x6FAE888F196F6555ULL, 0x6AFDB1C5E3AA2554ULL, 
            0x07817EC4969C586EULL, 0xD1CD24585030265AULL, 0xCA4D7F63E9F62679ULL, 0xA365AF1521570ED1ULL, 
            0xA39763343B4D929CULL, 0xE465AB3E62FB82CBULL, 0x8F71DDBCB025188AULL, 0xC5AE947BBF4A72C9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseDConstants = {
    0xAC574FEBD527908DULL,
    0x08F99974F59470DEULL,
    0xCE926BC9F8856009ULL,
    0xAC574FEBD527908DULL,
    0x08F99974F59470DEULL,
    0xCE926BC9F8856009ULL,
    0x41E72627FCEF6737ULL,
    0x21B1E81C772C93F2ULL,
    0x8E,
    0xDF,
    0xC3,
    0x59,
    0x79,
    0x69,
    0xEE,
    0xFF
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseESalts = {
    {
        {
            0x66F9CBD7157A2D58ULL, 0x496B2F38939E1713ULL, 0x39B01E50D2AAFA78ULL, 0x02CF72A7AF17B2F6ULL, 
            0x86CC43342632688DULL, 0xE34BF579156763DBULL, 0x49DA30FC9AAE27C8ULL, 0x549DA4C500CC2B69ULL, 
            0xCCA04257F500DBA6ULL, 0xCAABD2B7C6B8704BULL, 0x8688E957489FE380ULL, 0xD12D4F2BC83749D2ULL, 
            0xD67FEE26E90C0EB6ULL, 0xE33C584C92D2C1A0ULL, 0x3661228FF02104DEULL, 0x6E62F403B9490E40ULL, 
            0x71B467AA4D989763ULL, 0xC01A573E0855169FULL, 0x745611281A91E265ULL, 0xCFB4AFCE05139904ULL, 
            0x05C1CC659B276FCEULL, 0xB9FB512B212C83C0ULL, 0x363779536978E9B5ULL, 0x339B1505AAE3DA79ULL, 
            0xD10931AEAAAFF89DULL, 0x4D4F8964EE11CF33ULL, 0xEEF17A6D82A1C668ULL, 0x073E0C6746838D90ULL, 
            0x905300D347EB5C15ULL, 0x8ED7A592DBEF9715ULL, 0x31A0F02B5B3D3DFDULL, 0xDF565C548021A338ULL
        },
        {
            0xE8B7F25CC5F7FAE8ULL, 0x33CC7FAEC326BB5DULL, 0x977476D6ED58DA6EULL, 0x2ABCBAC77CFA7CFDULL, 
            0x1EAF239D72FE82D2ULL, 0x2E21A5392D7A9241ULL, 0xC6F634F70AF241ABULL, 0x386F9D3E86A1C40AULL, 
            0x2962F3688123E98AULL, 0x86AD6EA0A82094F5ULL, 0x065125EEF3A7704BULL, 0x68EF5E4F308AD397ULL, 
            0x6BC67D30A010F5E1ULL, 0x8C1BF9CF92F2B6BFULL, 0xD0D21ACECD383706ULL, 0x8A5625A3258A4A55ULL, 
            0xBB48EB922514A54AULL, 0x6A45BDEB6FDA083DULL, 0x911A8A8D9610FDDEULL, 0xDF3D969DFA9B4B7DULL, 
            0x59B4EE54B702B1EAULL, 0x50BA5E5FA34C34ECULL, 0x78DCC98686F1F0FAULL, 0x06761D0BAD364101ULL, 
            0x06A0D61BC5E42CDEULL, 0xA1B6E68FBE720C92ULL, 0x4A932C34AE3F3E60ULL, 0x944884E45BD79B1BULL, 
            0x1CCD4B4A888AF363ULL, 0x5DA2376FB10C18BEULL, 0xB16A76574CA2C7A9ULL, 0x2E87CAB8815BA689ULL
        },
        {
            0x4AD8AF0DF6FC1B1FULL, 0x5E6ED7C86F6169FAULL, 0x3A824B9DB68B72DAULL, 0x2B9C33D5C243374BULL, 
            0x4FC300EF86E513EEULL, 0x6349DE3355DB66DCULL, 0xB3C229F312054136ULL, 0xB7D0719586F67FF7ULL, 
            0x0E113CC235F54F3DULL, 0xF66F458A0366CD89ULL, 0x1ADEC6583AB237D1ULL, 0xB39D5F237F0F2F9BULL, 
            0x18CB805C98804BDCULL, 0x1EAF103C5ACB32EBULL, 0xDB5E0C881FA824A9ULL, 0x4FEE14B45F564080ULL, 
            0x3ED20F44D3BC167DULL, 0xFC44EDD0FF08310DULL, 0xD7B70E9C4883E4C0ULL, 0x09A73FD37123C41FULL, 
            0xBF1E8F5617FD0A96ULL, 0xC0AFBB48F7CE3EBDULL, 0x913CF9E51764AA4BULL, 0x476EB84AC17C860DULL, 
            0x17A1E275192FD020ULL, 0xFBB47F6D6B29855FULL, 0x94081D981CBD456BULL, 0x6A543640B7B32231ULL, 
            0xC390E99E4276BD6CULL, 0x69B1E4C174304D71ULL, 0x53FAF45294F871BEULL, 0xFDB5D2B48E89DF51ULL
        },
        {
            0x8181D1C49D6FED75ULL, 0xED44D4BD9315F3B9ULL, 0xB2E5BA20776E3D75ULL, 0x664C865AD5BC61A3ULL, 
            0x41F331F904D868C9ULL, 0x852F4CAD67E1064FULL, 0x82C9260270B794EAULL, 0x483C3A747E700C31ULL, 
            0xD3D672EED7BEECD1ULL, 0x259049F8A266CA7BULL, 0x08C3538D1085EB62ULL, 0x5962DA952522805BULL, 
            0x55F4313698F9E583ULL, 0x9F2180F7B477D6B5ULL, 0x1C3594D583D5CD19ULL, 0xE78374296C9C20CCULL, 
            0xC0A5315237020F2EULL, 0x33ABD63719CA7B78ULL, 0xAB52FFEF5C4852BBULL, 0x188AA2713BF00507ULL, 
            0x9E09A851C4546192ULL, 0xBD935476C375BF2BULL, 0xFD03F47F6445760BULL, 0xBAD93DF6BD71C4CBULL, 
            0x63A919AAE0373F3DULL, 0xAD5E986707B620CCULL, 0x828E1B44DACF9D8EULL, 0xE78C6E54589BDB16ULL, 
            0x542C9613FEC0F9C4ULL, 0x897B65E40C80A290ULL, 0x6768768C06E7A5D5ULL, 0x44B6C363C6F7FB53ULL
        },
        {
            0x3D0488B478B4C94CULL, 0xF71F1824E08A2D93ULL, 0xC44314D0C1ED260FULL, 0xFA7D48AC42B944B0ULL, 
            0x7EE127C19983D4EEULL, 0x26661FBA7902B45FULL, 0xC27A0E0A623D2991ULL, 0xF45DAB144D421AD2ULL, 
            0xCDE4875CFA75D0CCULL, 0x7B5BB0BA6B8861ADULL, 0xC8CE77B0402E3CADULL, 0xC6C3D43350945DEBULL, 
            0x1A58BC5313B50634ULL, 0xDBF351750C258651ULL, 0x88FF51F5D1D67DDBULL, 0xE4BE722611216784ULL, 
            0x0E86BBF242FA55B8ULL, 0xDEF152EA3627EAC8ULL, 0x833E87C8A881250BULL, 0xDEAB0C5948D199F0ULL, 
            0xD3B284D243128F8BULL, 0x9E0BB44A9A1B9820ULL, 0x6F62FEC45655EE4BULL, 0xA3130DBFD1699A62ULL, 
            0xA8697E72D12396B9ULL, 0x0797384A42FB40FFULL, 0x4F69C5A05FC8F432ULL, 0xAD526E9597AE350EULL, 
            0x817BF422165D9CC0ULL, 0xA77077224F92FA64ULL, 0xF947FFB635B10AE5ULL, 0xE2A95109332ADCF2ULL
        },
        {
            0xC312EF810616865CULL, 0x8FBE6D75ADFF4B26ULL, 0xDC7C37EAFE39D162ULL, 0x6241432D594F5541ULL, 
            0x993D5762536D7823ULL, 0x967E0E607C4917E5ULL, 0x72B581A1C3D83709ULL, 0x27194B17E4C0D0B9ULL, 
            0xDCAA0B29B49959D0ULL, 0x6603484CA8B89E07ULL, 0x6B0E95E650BCB4DAULL, 0xF042174386866D7AULL, 
            0x9B28D96D7D848045ULL, 0x0EED19538244FB21ULL, 0xDBD16FBA09B6DEE3ULL, 0x127076E0871C5CFDULL, 
            0x5B423704B2F96458ULL, 0xBEDD4FA8DADADC88ULL, 0x7B12EC848C66A7A4ULL, 0x6D8F0527A9A977C0ULL, 
            0xDE61E9DFC72EC2B1ULL, 0x0FE2AB09BB91C610ULL, 0x5E75CB3692AD5540ULL, 0xFB98E8EACA659DDDULL, 
            0x53CEFF70A18FED03ULL, 0xD9CED3F8D0934460ULL, 0x7E0F39786EC110A3ULL, 0x86A0A39977E44487ULL, 
            0x9F30F6F7B4A17A7FULL, 0x8FCD309E89BB0DFDULL, 0x4CEA86420E63235CULL, 0x9195D17BE10DD5DCULL
        }
    },
    {
        {
            0x8030E0A76C8AA0D3ULL, 0x78AA87339204A481ULL, 0x7EEE8C9A876A3406ULL, 0x29B640EB9C042869ULL, 
            0xF7AD7FCC771D3C88ULL, 0xC65E64893380E45CULL, 0x146FADFB2827F65CULL, 0x15DE79E14D2A183CULL, 
            0x17FC4672E0180B86ULL, 0xC964B6B48212DF2DULL, 0xB75E5EBB92CDEDCDULL, 0x8737AD74FA293439ULL, 
            0x2F61A406015E440EULL, 0x2CD99E7973FA5E1BULL, 0x3CCA9553C16B87A5ULL, 0xDDCC502CE2B1FB16ULL, 
            0x5F11FC77CF82CC3BULL, 0xB4F02FFC019C80D4ULL, 0x31FE8EA0E2BF5558ULL, 0x3274AF854020D4D3ULL, 
            0x63F6A6CE1EB02169ULL, 0xFA37CB4789FFC054ULL, 0x68DAF94EAE9D7248ULL, 0x732D9F6DE36B9833ULL, 
            0x6F9738DC61A8D25EULL, 0x579EE904F8FA6AAAULL, 0xC79C4A888159980DULL, 0x7EF6183BAAD6B2F2ULL, 
            0xF985A9F84E9DA094ULL, 0xF8732BC17A52C5D8ULL, 0xEB9E576861A58558ULL, 0x3DB29DECFFDE4CD1ULL
        },
        {
            0x6382DEEF91B1E4C5ULL, 0x8B5945E80B0DFA97ULL, 0x40B410CA801A7908ULL, 0x71CE4C8342F6C503ULL, 
            0x0FB39E8D6512491AULL, 0x6D46607EB0B1822BULL, 0xDFFEF25D17E735E5ULL, 0xA670B9DDEE3F3ACBULL, 
            0xAD8099FE40CCCD43ULL, 0x5AA31EB1417C14DDULL, 0x5B8A6EDE6ED0A62CULL, 0x395D188613F2E0E1ULL, 
            0x0CC8845B60AC7D82ULL, 0xED584A8EA193F8A0ULL, 0x49CD8146A1303720ULL, 0xE40789969E6691F5ULL, 
            0xC1B5F4C1CD0DEEC1ULL, 0x85C1AB4BCC454CC8ULL, 0x42020EEC61D2B68DULL, 0xA98AD78767FAC074ULL, 
            0xBA6CBADD0EF6D39BULL, 0x536828A75FE8BA49ULL, 0x2C937DF3911B716EULL, 0x395286D866D5AAF0ULL, 
            0xF1E7A532FCC981DBULL, 0xD671FAFB38457D0CULL, 0x8CB0E772D17E0FEAULL, 0x1CFA417B7A52F20BULL, 
            0xB4D2319FBC00340CULL, 0xB4ECCB16E2865A16ULL, 0xD838978A6379012FULL, 0x450D11AA141502C4ULL
        },
        {
            0x0CD0680E046A80ACULL, 0x9DF622789F95B77DULL, 0x4933517578CF6C2CULL, 0x7FB62C4C0835EFC2ULL, 
            0x4D80594060BF7A3BULL, 0xAE65B8933F06BC90ULL, 0x923DB044F61F54F2ULL, 0x13E9BEFA7272675EULL, 
            0x57D31C2891646498ULL, 0x838CCA0D89AF56C5ULL, 0x720EE47C298FDEFAULL, 0xC666A6302C731905ULL, 
            0xA675A7325187FC4EULL, 0xF0DBF3926E984242ULL, 0xE832E31551A971C5ULL, 0x05D8A6CCEB479B7AULL, 
            0x36EB3C4E42DCE804ULL, 0x23419C7929FBD2C0ULL, 0x20BF9B39201E1CCAULL, 0xA2E2BB889210C384ULL, 
            0x263120AF8F963E88ULL, 0xBF04B6F247465C30ULL, 0xCE73219F6510D7BAULL, 0xFCD87DF5C1AAB253ULL, 
            0xB7CA01A2DBF86BC4ULL, 0xD76075926174CE2BULL, 0x400067CCEB4B021CULL, 0x1666E723FF7A4578ULL, 
            0x2D0E62077578CBAFULL, 0x000FB88C88F8F683ULL, 0xFC97E1226E520AF0ULL, 0x2748CB9977071AC3ULL
        },
        {
            0x89341EF03F926E3BULL, 0x2D1C9D51A16A7B2EULL, 0x4FF9A148A10AE55AULL, 0x8F4B2E2A40483F95ULL, 
            0xB68C108255E423ECULL, 0x5CD22E422E384F96ULL, 0xC6D5BFD197D14404ULL, 0x97318805B5EF251AULL, 
            0xD21ABA2EC862DFB4ULL, 0xF6B97F7E62B93D1FULL, 0xA885DBBDA9BF2396ULL, 0xD83010149C51AF84ULL, 
            0x366A7D2D0EA8FCE9ULL, 0xD1EA2FC6CC0D2080ULL, 0x057A3CFF9C3EA955ULL, 0xD665F47607C9209FULL, 
            0x129851E2560E3F94ULL, 0x8C2874BC4A7CFDABULL, 0x060B651817DAE797ULL, 0x7A3365DF5F6B3A98ULL, 
            0x28A9CF629A37302EULL, 0xEE343A36500B12F1ULL, 0xC7794253EA082CC8ULL, 0x423BC0B8A2867BFCULL, 
            0x13D6C20E8EF764A2ULL, 0x256252F68F37157AULL, 0x29C654C4C1810534ULL, 0x6D9AB89FD2EE9B38ULL, 
            0x85C2FE169160215BULL, 0x511666BBEB28F083ULL, 0x1DC57712B90604DFULL, 0x23D6B5331AF4C879ULL
        },
        {
            0xC0CC900720819E24ULL, 0x252EA0373AAC4255ULL, 0xE6CDB5BA81FFD5CEULL, 0xDA05EEB28AA17AABULL, 
            0x154B68C2C7E16FDFULL, 0x8EA7F8BE50898934ULL, 0xCDEF8C980CD5AB6DULL, 0xA41220697C33F029ULL, 
            0x5833C5A37C601620ULL, 0x9E1B932DD7AA0808ULL, 0xC9502EC09321CCD4ULL, 0x43DC9042266F9153ULL, 
            0xEB3709E339F50E59ULL, 0xD6B427B871EE3911ULL, 0xF1E1698BFD77F324ULL, 0xAB96C561D325413CULL, 
            0xCA5AFD7E6CE82DB3ULL, 0x029FC9CFA9A81E0FULL, 0x1A2BA20FC0C49539ULL, 0x1D4FBB933D0109E5ULL, 
            0x404886A9A94761A7ULL, 0xE81BBDCBB66787F1ULL, 0xD6828AB293822CEEULL, 0x1AB06911C1894BAAULL, 
            0xB1D05501A4A4BAE7ULL, 0x8CE83271B66BB9DBULL, 0xE48B2BDB3AE86842ULL, 0x1A9DBEF0FA785E9FULL, 
            0xA356B22A02518D11ULL, 0xCB22BF957423896BULL, 0xF622F75819F31713ULL, 0x3D8680AEC3B50D67ULL
        },
        {
            0xFB6A4BCB22A5E0FDULL, 0x0B5AEEE030F60A79ULL, 0xDC78217096B5DFADULL, 0xF32D2D7BCABE846EULL, 
            0x33D714F7D856128EULL, 0x75150F7E6BD5B9BFULL, 0x6D44DD1899377B5AULL, 0x454D08CC9142A7B5ULL, 
            0x9F00237B03CF9396ULL, 0xE2BB250D041EB166ULL, 0x719FAF33BCC1435CULL, 0xCC48ECFD207667C1ULL, 
            0xDE9AB6E2F16F49F0ULL, 0xFC5DDFE78F280998ULL, 0xCC484B3644B153E6ULL, 0x6A7D71E6BA3DB94BULL, 
            0x7AE0FA84774756CCULL, 0x4231521C83B230A4ULL, 0xEF26D12D31E2DB3EULL, 0x9920CA8FEC324A7CULL, 
            0xEA6F0595649BA533ULL, 0xD82C6B021691B2D3ULL, 0xFF7EE86CAFF5E651ULL, 0xC6DC01893E76323AULL, 
            0xA4A75F6C349B18AFULL, 0x8E45277D8647FFF1ULL, 0x13240E1883A88F5DULL, 0xED5A07708589AEEBULL, 
            0x418E4F6402056CFEULL, 0xCC1BA1A351B2F6D6ULL, 0xD092364928D7C1C9ULL, 0x22773AE56A778C8FULL
        }
    },
    {
        {
            0x718196B3CE1A0CABULL, 0xFE5D013DE51E540EULL, 0xC2D90E17C42DAF4BULL, 0xEA3C7A4DF5FA94F7ULL, 
            0xF9D756575C1AC128ULL, 0xF937281BEF2419D2ULL, 0x39F808CE0A3E9EA9ULL, 0x81415642490846D6ULL, 
            0x123DB9AC8FFC35AFULL, 0x6051B345C1D46E2BULL, 0x1F4F8014C3B2E0C0ULL, 0x42FADB483FBED746ULL, 
            0x21E6ED5B3F8F8234ULL, 0x0D03AEF0FAC0654CULL, 0x35269ACA0D157B67ULL, 0x3B6725A4AF47C13AULL, 
            0xBF2D01DBADF3D69FULL, 0xBBF446A4627C19A1ULL, 0x6813F1247C845C10ULL, 0x6527EF9B7F9051BFULL, 
            0xDC4947347B7717A7ULL, 0xA3EDE0D25DE46048ULL, 0x79E60CDF73D67CD0ULL, 0xEE282F199E9B4974ULL, 
            0xF6BDCF4FA30D04F2ULL, 0x3F04DA1C5FA14599ULL, 0x3B5ABD0C389E1952ULL, 0x61FA784EAE4C888AULL, 
            0xC2CAF1A5D4C9F96CULL, 0x2984C215ACF8B401ULL, 0x06DDB97B6BFFF840ULL, 0xD630C03888B31662ULL
        },
        {
            0x486B4636CB4AB1ADULL, 0x3380F72AE33A9C14ULL, 0xFC50182A7D8608BBULL, 0x24AA151171480953ULL, 
            0x2D247F32B9D42C91ULL, 0xC86DDB6129893164ULL, 0xB3BF74A7ED936EFFULL, 0x66173048EA32957AULL, 
            0x58CB4B37B6AB3625ULL, 0x2680D1861ABD5F81ULL, 0xAFC86B2AAF3D837EULL, 0x49622E80A076260EULL, 
            0x2484B5AB537EB7D0ULL, 0x9ED6F538C7B057E9ULL, 0x81F8A1444D55292AULL, 0x705392A2CB067F5EULL, 
            0x3EB3F3012191EDB4ULL, 0x9C2C08EBE37C798BULL, 0x9C940543AE884907ULL, 0x9D294C68ACEF83ECULL, 
            0x07755F6E6F739D8DULL, 0xB473257650A7C6EBULL, 0x217EF108745F6A52ULL, 0x4345529B67E80552ULL, 
            0xDAB4E780A2C94754ULL, 0x227B824F18D744AAULL, 0xCBD215A4A54A49DCULL, 0x89FD18D24D9390A3ULL, 
            0xD219341015A10C06ULL, 0x60FC8165255E1335ULL, 0x4F2600283B7FDD0CULL, 0xCDBC379120D48B56ULL
        },
        {
            0xF8AD4B0AE2FB5524ULL, 0x17D41D8FB70ABA2BULL, 0xC520150C5D4C2024ULL, 0x8B768C1F7156D08DULL, 
            0x21A2405057894E7FULL, 0xCBA2B8AD214BBD8CULL, 0xB8E35705B475C310ULL, 0x848E54C012E62A0DULL, 
            0xC8040F17FD333667ULL, 0x20BDFE46C9D54DC0ULL, 0x37C16E22B22DB9CBULL, 0xF4A3100116509FD2ULL, 
            0x4C42F09806D27D1EULL, 0x32F3BB60293C698BULL, 0xEB9B787C582CEA15ULL, 0x0767C59A2FB055FCULL, 
            0x22C0708C97206536ULL, 0x8B3498B2907AED5AULL, 0x4178FC1A49F1628CULL, 0x1A58583CB1F59B6EULL, 
            0x5D378762D36B4DF6ULL, 0xAC288E0FDBB8837DULL, 0x716FD9F2B995327DULL, 0x1E10DC7DC4F79926ULL, 
            0x5B94BFB35FE9A871ULL, 0x3934CCD1E2A00C58ULL, 0x47AF4195BBA655D4ULL, 0x592E3AD0A3F43B07ULL, 
            0x865E2207FED71B0CULL, 0xDDE3802350488053ULL, 0x09ABFCB4E7C67E59ULL, 0xF2E807E3FA8B64F2ULL
        },
        {
            0xA318D1EC2F9D2022ULL, 0x64379D4830AC15F9ULL, 0x43B5B5CD5FEE5663ULL, 0x7189A136ABA367F4ULL, 
            0x74DB5E37CE190DA7ULL, 0x65616A396AD1AFA8ULL, 0xC8B44F1271B27F44ULL, 0xAF65200734418D6AULL, 
            0xBDC73E10D93D413CULL, 0xB1AD75232EB466D2ULL, 0xAEF6F8BE164F0E90ULL, 0x1AB01A1A679960F8ULL, 
            0xE2B48E69DEF340D2ULL, 0xB84C97748BFBF3A1ULL, 0xBB1D7A73D321BB1AULL, 0xB67931DF477DB269ULL, 
            0x3D1C71664D669841ULL, 0xF9B37C9C5BBDFFAAULL, 0x8CC6D91F67A39F0AULL, 0xC0C9945D6AA1FC8CULL, 
            0x7B0A1BD903385C4EULL, 0x2C40EFC61E5B3A6AULL, 0xE7A64A93BAD97DBAULL, 0x360988662F04AF50ULL, 
            0xF170DA0BD1E00B65ULL, 0xC3AB7DE77EFB3CC9ULL, 0xF1CCE084E8620CBFULL, 0x0929000F1FAA018EULL, 
            0x3B855CAF14FD11ADULL, 0x7A5C97A008BDA849ULL, 0x3D1E5543A559F592ULL, 0xF6285163B67CEEC3ULL
        },
        {
            0xC95399C954162DB7ULL, 0xC38503BD56D3C590ULL, 0x20720014C2325DE1ULL, 0xB0BFA3149D394416ULL, 
            0xEF3DB6818929BFEAULL, 0x68EB43BB578C7BFBULL, 0xBB80F12091159AB7ULL, 0x80E09271CCEDEB52ULL, 
            0x8B1131D4571B5388ULL, 0x279309AE33EF621EULL, 0x9F04CE1757563B12ULL, 0xFF7466AB7E75D420ULL, 
            0x19E072E016BBF1ACULL, 0xB5EE9D12EFE0081CULL, 0x77CAFDD85B02EE3DULL, 0x132942566DF77BF8ULL, 
            0x984D7F1195DD80E3ULL, 0xF3652333E38A20FBULL, 0xBE6575CABB480266ULL, 0xF254DE22B890A4FAULL, 
            0xD904DD8C6D3FC8C5ULL, 0xBE45054185EEACCDULL, 0xEA04F6AE777A95F3ULL, 0x9A444148C471B117ULL, 
            0xA1590C0110A513C4ULL, 0x77638DCB511D296DULL, 0x5F6A45438C727ACFULL, 0x43B7DD8D66C7326EULL, 
            0x378468E129440561ULL, 0xAF58C99F31497CC1ULL, 0x75F43779565DC0E2ULL, 0xF20C8F1C23C540B7ULL
        },
        {
            0x2F2851E1CB78A08BULL, 0x0ECA6C168287E9A1ULL, 0xC67843423A9475E0ULL, 0x939DED950ADCA3FBULL, 
            0xE76AA6D0A82B1BF0ULL, 0xCFFAA8FFBB8166EBULL, 0x19A026D0A2411FFDULL, 0x751FF86EC74813CAULL, 
            0x9BD6C970752561BBULL, 0x7B4A807D4F9A785DULL, 0x10C7C4395D101BE9ULL, 0xAC39CA3D9AF1BFD5ULL, 
            0xF4220FB86D4F60D7ULL, 0xB0633D2979EB2A55ULL, 0x06B6913CF7160BFEULL, 0x753863CEE3695412ULL, 
            0x595136ECFD3FD241ULL, 0xA8BE6ABFF728A0AFULL, 0xE30F275F58CAC825ULL, 0xC86AEEB89C951A5DULL, 
            0xE87CA84B02E1B0F3ULL, 0xA8B27A7B1558720FULL, 0x619D0E0502BC7050ULL, 0x19B86A0A9FDDE0B4ULL, 
            0x8B4584C290693143ULL, 0x39F94794EE7C5A71ULL, 0x53995B4EBBA5D087ULL, 0xAD9BC60A67CEA0A8ULL, 
            0xF5CEADD1A2D70864ULL, 0xF280286390B1B760ULL, 0x6BDB8FE3F42F92EAULL, 0x4C8B3AF645C9804EULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseEConstants = {
    0xF6E7FFF0D786745BULL,
    0x31A6C0863459D412ULL,
    0xAFEA8B035914C776ULL,
    0xF6E7FFF0D786745BULL,
    0x31A6C0863459D412ULL,
    0xAFEA8B035914C776ULL,
    0xA361F666AF8B3580ULL,
    0x780E2F132AD2A1F5ULL,
    0xC1,
    0x0C,
    0xFB,
    0x39,
    0xE7,
    0xA7,
    0x78,
    0xF1
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseFSalts = {
    {
        {
            0x65BB58CD54268BC5ULL, 0x2D34290F1FFD10B1ULL, 0x3E250F2DA5A2FCFCULL, 0x818EEA481395F6A9ULL, 
            0x15BB463CDC95849FULL, 0x231AE922A417FFF3ULL, 0xC4B13BC2B62B91AAULL, 0xC4E26DFB473561ADULL, 
            0x0097B394C71200A0ULL, 0xB946390BE546EFE4ULL, 0x6EC0F2B7DE7246F8ULL, 0xC2FB762807385B03ULL, 
            0x7297D192EFFD598AULL, 0xAF377AC2DC1673EAULL, 0xD5E0A8F9781E83E6ULL, 0xA5985DECC4AB12E4ULL, 
            0x7813D4FC3C14181CULL, 0xB755D0BCCF787C81ULL, 0x6A313DE06CF8302FULL, 0xF7B11921959D04E3ULL, 
            0x4AE85C8E7B04B915ULL, 0xF7D98FE1ACD0D735ULL, 0xD664D3BDA8CBEE4FULL, 0x235A5E6BC5257613ULL, 
            0xC63056250EB814B1ULL, 0xBF6238129E319954ULL, 0xA1A068D21BC61D38ULL, 0xD1A607293EC7F499ULL, 
            0x7550BCF3D807AE8FULL, 0x2D760EEF7733324FULL, 0xCA2C013DAD352725ULL, 0x211E0FC8AAAE0CBDULL
        },
        {
            0x5CA34B006F47716DULL, 0x52F01C6CA07E055EULL, 0x28CA9B2CA79A3663ULL, 0x5E8C1502625188DBULL, 
            0xF74E93D4696813D2ULL, 0xD4E96E8CF6252B4CULL, 0xA3C57E545189523BULL, 0xB8C58B7FFC390FB0ULL, 
            0x234273B147605646ULL, 0xBA32085C4BDCC940ULL, 0xA54367F46F6912DFULL, 0x8296234DE67DE333ULL, 
            0x2A2D5AD468E02FB1ULL, 0xAE1F44C4EF32F283ULL, 0x8C3514DBC4D5DDB2ULL, 0xB847D26A50BDB0A0ULL, 
            0xE1DFD1BE9ABDC548ULL, 0xEF2C7110612B9A53ULL, 0x9C4E63A5676A865AULL, 0x07224857ACBF6ECEULL, 
            0xA291170782B935A0ULL, 0xE1EA51215CA6DCF1ULL, 0x1BC530C4FC2026C1ULL, 0x0EF2F873C25865ACULL, 
            0xB0D76D664B9FEDECULL, 0x5D1FFD8553872213ULL, 0x1EA5B95205A8666CULL, 0x5B2E0EFB2E643500ULL, 
            0xCFD0B7CB3C57D093ULL, 0x76BF625EE4CEBF90ULL, 0x0E195411E9C168FEULL, 0xB8FA663A12254B0BULL
        },
        {
            0x0260AE52BAF36074ULL, 0x63630EBE8D46A3F5ULL, 0x1BE10F52E8695BA0ULL, 0x78577002FEBF4ACEULL, 
            0x380A5856072E0102ULL, 0xB058C21135BDD371ULL, 0x48AE0C99C609924FULL, 0xA512756107B84DD3ULL, 
            0xC4350844F347F907ULL, 0x857FDC588B9576D8ULL, 0x86D760E52CDBCA04ULL, 0x68BD671C1871307BULL, 
            0x9D32E52FC4C8009FULL, 0x7116989657BE84A9ULL, 0x86DAA942A5CD7CBFULL, 0xE52DB95366182C69ULL, 
            0xAEB6B400DBB6A064ULL, 0xF681CA8F1345EEA3ULL, 0x988A219EAC84E46AULL, 0xC2378D034BC4F332ULL, 
            0xEE5813B3CEFA4A72ULL, 0x54BF444AEE8BE807ULL, 0xF7A444B86FFD0AF6ULL, 0x8C29A52176417898ULL, 
            0xFA4BA7299B6970EFULL, 0x6991FF8C70455859ULL, 0x717AA5C20D94CBFFULL, 0x11347604F8CB1584ULL, 
            0xF8738F16BAF90707ULL, 0xADDF1544FD97ADF7ULL, 0x8649393D765A3E08ULL, 0x83CDC2A8BCD35526ULL
        },
        {
            0xB6508EB4D1446C3EULL, 0xAA318081FBB6D195ULL, 0xD7B4DCF375D373B5ULL, 0x207BAA086B338103ULL, 
            0xEC4EDE429EDF811CULL, 0xEDDE009DA09715B1ULL, 0x4D158C748E4774E8ULL, 0xC4069930C897CC62ULL, 
            0xAA054A4886056D83ULL, 0x69F20852E70BB3D6ULL, 0x14F7D3CC8166150CULL, 0x098CEA1635852A96ULL, 
            0xAD8C99C27E30E71AULL, 0xAFC90D3D7885D739ULL, 0xC653D93EAD21AF81ULL, 0xA9B205CB82923484ULL, 
            0xA9761217683DE95DULL, 0x13534C2A147AF81DULL, 0xD2F695929EEA777BULL, 0x8FE104C4F87A7C02ULL, 
            0x1AFAEA85ADC361A3ULL, 0xF5318942A926F27BULL, 0xA744617F803D2279ULL, 0x8F6FECF78B9E69BDULL, 
            0xA59565B02B26D898ULL, 0xF1E556D6A7F6FA7AULL, 0xC0DB52900D494DF0ULL, 0x5D0975EA0A2E8735ULL, 
            0x04BC20049FB067FEULL, 0xF4654FD277405845ULL, 0x6275C2B88C3EB8FEULL, 0x8EC723B2D0F68F7AULL
        },
        {
            0x972208B0F1C4B629ULL, 0xF8E179771919893AULL, 0x880CD1C426AABF9FULL, 0x0B3E0F356AA86F4DULL, 
            0x38BAA0FA5FC10AFFULL, 0x011A6F513779F078ULL, 0x58AD37F9AFDF1FBAULL, 0x39AD93B2AC7FDDFCULL, 
            0xF176F1DF5705CE41ULL, 0xCDA93FF027FE6FEAULL, 0x3E2D3F4396551D77ULL, 0x947925A0F9978052ULL, 
            0x4DF7D37930291DFEULL, 0xD0876012BC0F6F68ULL, 0xEE459ABA092B469BULL, 0x65354A7B98955BD3ULL, 
            0x0227EF863FF9F131ULL, 0x8821BA27B8028D1DULL, 0x00B620AE79F78372ULL, 0x2FD6926B8BF2EEE1ULL, 
            0xAE7C4747CCF950F1ULL, 0xF1C5AE5113F69E7BULL, 0x7C6F32E0921BBE33ULL, 0x73B39B6A89A432C6ULL, 
            0x27DDA26E96A67FE4ULL, 0x8151537279DC15ACULL, 0xEB9A7C3D70851079ULL, 0xD6F0A68AB4F95CF5ULL, 
            0x3049AE8AC7EBD230ULL, 0xD5CDB5C4F7B8B3D8ULL, 0xB7357D28A37665D4ULL, 0xD9E8D6CADD4CBD17ULL
        },
        {
            0xFE8E3264088B4BB7ULL, 0x420C1C5BAEAC199AULL, 0x09159C4EA73288E7ULL, 0xBFCF3A39B583AE63ULL, 
            0x3B606B1C64FC963EULL, 0x171D9276CDA30E7BULL, 0xE9641CF79671D6F6ULL, 0x54636752A9598330ULL, 
            0xE4CB9DDF0E26BAD6ULL, 0xC53D0C1C57F8EFB8ULL, 0x8CB7A85941336713ULL, 0x96D7749F534231F9ULL, 
            0x5BE89FACA7B5425FULL, 0xB57758FFEB498FABULL, 0x5DA30B9FC7C94DF3ULL, 0x3AF34FE529C53837ULL, 
            0xBDD6EDA8BFCA398AULL, 0x50227BCCBC375663ULL, 0x1921A6EE9E4F448BULL, 0x642382731042495AULL, 
            0x758A6A5C53FDC8C5ULL, 0xDD5A8835B37CE701ULL, 0xD2850253D755F912ULL, 0xB04DCDB89B6042C7ULL, 
            0x5C97FBC9C7C987A7ULL, 0x886A258CDB8B7D1BULL, 0xF4CCED1CDAC86A74ULL, 0x545CBD6C1F4D9F1FULL, 
            0xA1F74A3414158583ULL, 0x32E88D573A62D8D3ULL, 0x2378596678F42A6EULL, 0xD99896D7813D51F3ULL
        }
    },
    {
        {
            0x24BDC9A12081B027ULL, 0x256B2B149EC1B3C6ULL, 0x8DA596CE21896EE1ULL, 0x81A1992E8331C0FBULL, 
            0x2531B22660ED2B69ULL, 0x77E2D57CDCA229CDULL, 0x37776B953A5F171BULL, 0xCB0C40EB52ADB37DULL, 
            0x5ACDA428E13D5E29ULL, 0x4C87B745239886A6ULL, 0x92A52E5CD85C1CC7ULL, 0x4FE67A1CAB57C934ULL, 
            0x1044C8B143C1BC05ULL, 0xA68D5C73DA304521ULL, 0xEF0183D32E4AC332ULL, 0x81F5DCCAC837B1AEULL, 
            0xEC317669FC1431B3ULL, 0x7ED8E855A60F44BCULL, 0x8253A191F5988EE1ULL, 0x44B64FB67F9EE45FULL, 
            0x9EA35A3FCBD5584BULL, 0x977E4E038250FF5EULL, 0x6E004CA57801C922ULL, 0xE1EE96DA6A536E12ULL, 
            0x7ED7ED106DE64887ULL, 0xEA4A08B1047CA6C0ULL, 0x213FD87C85A7AE79ULL, 0xA78CE7BF78341BFFULL, 
            0x1C8FA27C038A8FD7ULL, 0x4D846DA2EF32B075ULL, 0x5FCDD4703F44C933ULL, 0x15518D02AC616721ULL
        },
        {
            0x1A08B2A89FA314D0ULL, 0xC7D87FB76FD8D8B0ULL, 0x8C2BB080F9B14454ULL, 0xB3B1D48522F3A8FEULL, 
            0xCB4755BC65F9594AULL, 0xF940A509587C5F34ULL, 0x063B813BFA58F96FULL, 0xF4F54416F2BBD0A4ULL, 
            0x5144A95EE9E1E5A2ULL, 0xD57F97983374E826ULL, 0xE10FDD9332E74E7DULL, 0x26A28DDCD0476575ULL, 
            0x0328FA3C0F95CD84ULL, 0x8A0DE845601AC890ULL, 0x8A14C4DF1F9D4553ULL, 0x898E7C619D8989E3ULL, 
            0xE1707C40A789E539ULL, 0x1E44AB7FFF1646E9ULL, 0x24BE2090B559153CULL, 0xCF07DB2C5F36B4E3ULL, 
            0xD46CA6C841AC5B6FULL, 0xA77EFA13181DC94CULL, 0xD3261546395BF161ULL, 0x70A76C95C63FF674ULL, 
            0x1F5108611D267650ULL, 0x45DCF11EBFD5E7CDULL, 0x0EB31C07A8D786BBULL, 0x87BF1AE5A87B7517ULL, 
            0x4816EDED7FA39080ULL, 0xC0625EC1809BEF11ULL, 0x52D4FAA638FFE048ULL, 0xDE15D4726E6B026BULL
        },
        {
            0x30F74B941D12D18DULL, 0x68423EB89B5C6D5DULL, 0x1FA6CE379E87B44AULL, 0x3A84199E3FEF1896ULL, 
            0x7B291F211C4FA0F9ULL, 0x7431B1013BB77773ULL, 0xBA6375F5496742D6ULL, 0xD510E4F9B18FEC2BULL, 
            0x7FABFE549EC7D4A2ULL, 0xD793AA935602DD69ULL, 0x6DA74311E381E04DULL, 0x6035DCE2BCCE5B92ULL, 
            0x989DE4CE23988F3EULL, 0x4CCA1D493BE96B3CULL, 0x64AA29A659303A54ULL, 0xF963B8979EEBF06AULL, 
            0x4A3F2859FE657B68ULL, 0xFA009AFA47D769F3ULL, 0x90742DC41305941BULL, 0xB35FA60936B47A65ULL, 
            0xC846FC5180AE02A4ULL, 0x2444B1132338EC96ULL, 0x35F05D617DE90F10ULL, 0x9324267F6AFB3AB9ULL, 
            0x84C0D2F4C79EB3FBULL, 0xB66A7EB71017FEDFULL, 0x502CF3165A8C0446ULL, 0x3D07A927F05D81A8ULL, 
            0x4B49467241E67D9DULL, 0x76645A1E93C0ADFCULL, 0xE1845F704CAE7FB4ULL, 0x3E62DB2ECC03F928ULL
        },
        {
            0xAE1ACC0F09F50F43ULL, 0xA2346FC4CE54B00EULL, 0x45809BB37A2C9230ULL, 0x40E03196FEE4371CULL, 
            0x02F7C1F50F5EBE71ULL, 0x1304A8DEAA128DD3ULL, 0xE496EEA6E93622AEULL, 0x832495FD8AEC46B9ULL, 
            0x417E5B5C7292A133ULL, 0x0BE46FF601C718B3ULL, 0xA6EAE4CEC8AC0847ULL, 0xE3C0FE9298DF4755ULL, 
            0x306C7D95AFC02193ULL, 0x1C55E8AB7D940730ULL, 0x5BE7DD6AA0A44048ULL, 0x5A34BD46C4B930DAULL, 
            0x9648B0A2490FFD8FULL, 0x193B6D9A161DE7A3ULL, 0x4BCBFAB529BB1D26ULL, 0x1FD995D3E6E6AA9AULL, 
            0x50A871696F88CF8DULL, 0x6DF4E9EFFE006E8FULL, 0x6BA60E59636868A3ULL, 0xA6F3A9C3DE1E6ED2ULL, 
            0x8EAF2AD3F38BBD59ULL, 0x1DA4CA7A8FCF148CULL, 0x8FAE8F5EE4CCE140ULL, 0x19E2E61EACA6C4A3ULL, 
            0x79F940BB3BA6FE2AULL, 0xCA98E4525FE97C26ULL, 0x04715376508B58CCULL, 0x4A0A775400F4B6DFULL
        },
        {
            0x0AEEC8BF31C506A9ULL, 0x4E6F071BA860690BULL, 0x0BB35692CBD73425ULL, 0xAC340E658C4E5F70ULL, 
            0x6561D29738371355ULL, 0x201EDE95530E8D97ULL, 0x9C146553D8DEB0CCULL, 0xD4CA983401E580D6ULL, 
            0x58505F15EECB9BCBULL, 0xE205E04C6A4A1361ULL, 0x873D581AED91687DULL, 0xCF18AAE500032BFFULL, 
            0xF4E7FCB996F38AB7ULL, 0x8294BB10DB798D81ULL, 0x60A45C04F9C5FDCDULL, 0x35F5184D01286E31ULL, 
            0x03C9C2B635D8CD12ULL, 0x5C9DB29A7A6BCED9ULL, 0xAC73B14022C91ACEULL, 0xF41E18980CD435DFULL, 
            0x95661F2FA850C338ULL, 0x632D579125DCA476ULL, 0xC92DAECB37E0CCB4ULL, 0x97D89164B72534D3ULL, 
            0x873BA73AF551C0EBULL, 0xE457EFEB340CA363ULL, 0x43B4828E0B1C5078ULL, 0xCBF182FAE8D6B195ULL, 
            0xB4CD7DC33FBDD679ULL, 0xB2BC358C3E112740ULL, 0x0D397A44F8F70A06ULL, 0x8034FDF9ACC558CEULL
        },
        {
            0xFB44424A9C80957CULL, 0x21379E39431036AEULL, 0x741562B26B2DF332ULL, 0x97BA106F9667F286ULL, 
            0x842CA46F0BEE5493ULL, 0x7D4B04A0E3580B02ULL, 0xB9CEDA3FBB747E51ULL, 0xC015B68537B85D5FULL, 
            0x3ABC0EEB05B562FEULL, 0xB9DB91C9EFF7DCF7ULL, 0xCA0C74D26CF9F169ULL, 0xD2DAD0BF5133BF1BULL, 
            0x009C19CAF6CA1091ULL, 0x38D4C724390434A6ULL, 0xC1C530B89FC0D18DULL, 0xB8A7B948108C736CULL, 
            0x18596E8FDE53D698ULL, 0x9FCA2EA68F5C46FEULL, 0xC400BDB8C5A9EA82ULL, 0x9F5BAE704E33D022ULL, 
            0x33C889BD114669B7ULL, 0xD5FF4C71E18F2949ULL, 0x7C48AEE938FE947AULL, 0x49298766B87CC677ULL, 
            0xE77074889A4D1131ULL, 0x2248E116CD5C0CDCULL, 0x062E62823C34EBD2ULL, 0xC50D28AE76BFF31EULL, 
            0xC9D5E6B29313AFA7ULL, 0x16FDE615C5B6FA18ULL, 0x6BB5EC8C6D55BE83ULL, 0x54FF52359D13E6AEULL
        }
    },
    {
        {
            0x982D995A2D2BC69CULL, 0xA399E02806CFAFB5ULL, 0x5885D7932C27FADEULL, 0x34231AA9AD017B54ULL, 
            0xEEB14E80D818C115ULL, 0x273A7AEAC8DFEF04ULL, 0xA1676071924EF819ULL, 0x82D7FA8F25FC29A8ULL, 
            0x003BFC195409CE8EULL, 0xCA03C0A6A0E8CE7DULL, 0x182A06C7C5DAC8ADULL, 0x996D8418856A9594ULL, 
            0xA547AE46BC69DC28ULL, 0x72BF8658EB030068ULL, 0x1F85876E73300CA3ULL, 0x183A52858348F5ACULL, 
            0x5B6F407B1DB6FAB9ULL, 0xE5189E174E804CC7ULL, 0xA6C73F754BFDBEDEULL, 0x85370E09B8650357ULL, 
            0x4B9B36FA7DF09DE0ULL, 0x6749839B62118435ULL, 0xE5FBE4CC63893AAEULL, 0xEC8A71D6D5292EE6ULL, 
            0x04E4A4BA8C787408ULL, 0x31E0C12313408A62ULL, 0xAE26F3041C3E5256ULL, 0x8460EDA4B8282593ULL, 
            0x1E0E070ECE645FE8ULL, 0xB8CF3AC95A14F29CULL, 0xDFBAD09C70AFAA32ULL, 0xE553194504C27004ULL
        },
        {
            0x787C91CD78C2FFABULL, 0x5AEDAD3592499DAFULL, 0x3A0A2CC95FE61EA8ULL, 0x3D0A66B53F738295ULL, 
            0x4A9B0D20C5B1CC15ULL, 0x7509CD092DD5EA20ULL, 0xE32A5E867ADDAB58ULL, 0x44571635ABC75BD5ULL, 
            0x794FECD914C798D9ULL, 0xDAEE26F166200BA0ULL, 0x935D27FE08ACA649ULL, 0x716C0ED029EF56ACULL, 
            0xFC45F83362E22EB1ULL, 0x8CDB90E0C2095A4BULL, 0xC7C637D05C9BCB11ULL, 0x65DD75079D30AF63ULL, 
            0x87A22E9349D0ECC1ULL, 0xA43BC6AF7ABAFB1CULL, 0xA5D6CBE976A1BFFAULL, 0xFBC446C541CEEA3CULL, 
            0xF9F2320524002DCCULL, 0x7CCC17EA0BB4841FULL, 0xA1D99275F2B47A46ULL, 0x7187C60D04786692ULL, 
            0x19DAB31766DD153CULL, 0x3054A69A8855C072ULL, 0xF0AC2D8F900908D9ULL, 0xE42E2DDC577E08D0ULL, 
            0xEFFF12D7382339F5ULL, 0x174FF6CBA4D8BBC9ULL, 0xEE7354874FDD34AFULL, 0x818B17FE95538226ULL
        },
        {
            0x62624D1F642EA132ULL, 0x272C2CB10BABD1BDULL, 0x0C01286919F57D63ULL, 0x32D0733660526C69ULL, 
            0x8C582A5E0384A72EULL, 0x93FF564C44E33F58ULL, 0x9ABCDDFC91753FC2ULL, 0x7BA13B816A7A3C77ULL, 
            0x51FBB920A9BE8EAAULL, 0x4D039BE9420D217CULL, 0xD303BC8855B0B5B1ULL, 0x372928BE3EC4B19DULL, 
            0xDC4786996ED9CE2DULL, 0x78B54141F4AE5844ULL, 0x7E8CAB4FDE82FBCFULL, 0x46722864E02B0E97ULL, 
            0x2E86773B68A713D8ULL, 0x2228D53F5225B63EULL, 0x286452B367A11BF9ULL, 0x19BCCA37586CD0E4ULL, 
            0xC27B998586AC2C57ULL, 0x43C2B839C5E28009ULL, 0x71F04F3220CF8DAEULL, 0xEC888D18DD90E93EULL, 
            0xCC19F14DF36A8AACULL, 0xB64AB62FF572F781ULL, 0x07A5C6EC471F71B9ULL, 0xC98AFB73C30C7D77ULL, 
            0xD6F367A5CD19D76EULL, 0x4C5CCA1AEBAB044BULL, 0x305124DBBDB6FFB4ULL, 0xB495AF86629127FDULL
        },
        {
            0x441FC978D5F4B0B5ULL, 0x10A9E04A54806055ULL, 0xEEE64B0C86D14A14ULL, 0xB2C4691D11D30971ULL, 
            0x00DF09C618B6B57BULL, 0x7768921AA091F843ULL, 0x8CCAFF3FEFA3515AULL, 0x603CDB47D8FE2037ULL, 
            0xFFB807DBE2C5F72CULL, 0xD1C41D04A4F54DCDULL, 0x8612759A84C3E8B1ULL, 0x5AA12833C3AFB3F5ULL, 
            0x7992C2B7C9E14832ULL, 0x7B6F9CD005837A46ULL, 0x03BC977882BD31B6ULL, 0x639AD4243D86893BULL, 
            0xFF3E576698FA9DD2ULL, 0x764DD1BB82786BC9ULL, 0x72A5265C62820E76ULL, 0x5112C51C5FDFE31AULL, 
            0xD6D0E49F988E3CE3ULL, 0xBF1D9F6078AF2316ULL, 0xA2FCE238F6EE2A6FULL, 0x926999ABA0F85FF5ULL, 
            0x10713840971A6725ULL, 0x6ABAFFD2CB51A3DCULL, 0x6A01DEF145E4A388ULL, 0x27778181711CEBA3ULL, 
            0xC09E679001801279ULL, 0x782F179DF8804632ULL, 0x3FDA1A93C07E6132ULL, 0x57494F1BBB43A145ULL
        },
        {
            0xAE63FA6203364F2FULL, 0x6429BFFB2450ECE2ULL, 0x27F70BB320024A9BULL, 0xA870422C29D3AFF1ULL, 
            0xD560578F6EAC139FULL, 0x2292625AEEB1D6BBULL, 0xEC08A5A2D0F1A971ULL, 0x404C9EBD12B71A3FULL, 
            0x1C8D8DD564C15AC3ULL, 0xC76DCB41F78542ABULL, 0x2FA4AF53EB099BEDULL, 0xD5D83B3C706D1C76ULL, 
            0xE176B998282C5A7EULL, 0xCE21856F7223446FULL, 0x5505BF57154C1C33ULL, 0x2656B3648CFFA66EULL, 
            0x3EEFA7364699A8D2ULL, 0xEA79559635E00118ULL, 0x9BF90D135C17464BULL, 0xDA60C7886DC2EEC9ULL, 
            0x5F06C14BC3383C5AULL, 0xD8BB6E81B3E57E09ULL, 0x4687BF322A28C6D6ULL, 0x020C5BAED6C5AA9BULL, 
            0x854AA40317BBDD8AULL, 0xBA11B11CD8C2F765ULL, 0x02B5811E01064E84ULL, 0xD35D403733C6C1F2ULL, 
            0xB7F143F2E58DB088ULL, 0xE2447E6E7C904FCFULL, 0x35727E8F0F34EE7BULL, 0x38ADC637CF2F3CB6ULL
        },
        {
            0xBF1E8A32C3A7A91EULL, 0x256B2D78C7EADD95ULL, 0x002E93F9AF4DCBA9ULL, 0x151A858F52736295ULL, 
            0xD935E2435A3E2CCAULL, 0x2AACFF99640A4D91ULL, 0xB7E532D234C62036ULL, 0xA031B5AB2E7FC809ULL, 
            0x0A45F770987241D7ULL, 0xF2A40B3500DAF60EULL, 0xB0CAC8B344D2F5F0ULL, 0x5A7A6CFBD4A502E6ULL, 
            0x7B72C4548839ED91ULL, 0x7F7E265ADE1C4FF9ULL, 0xE08C6038B9BCF7EFULL, 0x49F464D03DA5FE22ULL, 
            0x342BADDF5240A1E1ULL, 0xDCB866D4D1AC092DULL, 0x3F4BD717984CD351ULL, 0x6E181F7F4A95E743ULL, 
            0x6EFE30626E0BBE55ULL, 0xD0B0D841407DFB50ULL, 0x21DF4B6E96AF2BC1ULL, 0x3F0AD67460299929ULL, 
            0xEFBA1953E1FABCE2ULL, 0x1161FD72A0D3004EULL, 0xD4348CACF214C5B0ULL, 0x43CAF36729831EA2ULL, 
            0x7E1E2BD34D8B5002ULL, 0x88B09EB6678A09E7ULL, 0x60F6BC49E7D0F0BEULL, 0xE14D252496DABB15ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseFConstants = {
    0x529C29463003B6F0ULL,
    0xEF220EF0D6C4A0C3ULL,
    0x87C3D34B1B49F4F9ULL,
    0x529C29463003B6F0ULL,
    0xEF220EF0D6C4A0C3ULL,
    0x87C3D34B1B49F4F9ULL,
    0xC3D344D88A574198ULL,
    0x37329C16BCA9E8E2ULL,
    0xE7,
    0x4F,
    0x7C,
    0x24,
    0x0E,
    0xDC,
    0xB2,
    0xB8
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseGSalts = {
    {
        {
            0x58F1AFC09C7CAC7CULL, 0x552F84F1266A4B9AULL, 0x0F46727B6C943E30ULL, 0x94F7760F6FC69E6AULL, 
            0xED9BDB06A5DD3C02ULL, 0x5AE9349E64A36F99ULL, 0xFDDF1226D44C1FDAULL, 0x3E662F21ABF98F8EULL, 
            0x4849E1F95D3669FCULL, 0xFBB821E78DE0C88CULL, 0x0ECF1E1547829707ULL, 0xB725DBECBCDBF343ULL, 
            0xC8250553822ECE9CULL, 0xB280A7A9108D6417ULL, 0xEBFB1AB85506233EULL, 0x797EEB68FFCC46BAULL, 
            0xF368B086BF64E0B5ULL, 0x059F65D4C40E7DDFULL, 0x35511DC180EC0A89ULL, 0x8FC1112E50AC8D8EULL, 
            0x4E57380107D0E5DAULL, 0x6FA805E6A6123A18ULL, 0x6F555EF1251A8EDEULL, 0x5BFF13A2A4097D0CULL, 
            0x856D04F9A0BBB791ULL, 0xF150FB80624F2358ULL, 0x63F4850DE3556277ULL, 0xAC4CF4A032501D89ULL, 
            0x335E87560D60DF92ULL, 0x12B5754C140AD8DDULL, 0xF38AB96ED36E290CULL, 0x65E1AE7F8ACC53AAULL
        },
        {
            0x74A155201A7559BCULL, 0x40AC2EB24610BDA6ULL, 0xDFF812E89FEF4D69ULL, 0xF195E6A7ACC5013DULL, 
            0x72C1B5A7A1791B04ULL, 0x9D1EF8176D4AAED8ULL, 0xE7CFE871A5F80282ULL, 0x7E777C3E8792BB2DULL, 
            0xDA5078179A86434AULL, 0xEF4A063E67061DADULL, 0xDD6DF656F1F7A0C5ULL, 0x924AB6E7ED83CB88ULL, 
            0xB694F7220F7448C3ULL, 0xC971FAE7318055BDULL, 0xC362A09B025D763AULL, 0x85DFE5E993BA2051ULL, 
            0xE0B38F6CF2AB1C53ULL, 0xBBA49C7BA3BFD365ULL, 0x272CE96C1160A541ULL, 0x4CB2CDD741D06AF5ULL, 
            0xB59F5CA8C8614E6BULL, 0xB26DED451FD5E84DULL, 0x3C00755C6D163CE2ULL, 0xF6853DA4EE2F6589ULL, 
            0x9A2D8DCF4FBA07AFULL, 0xF06D8E2A53EC69CBULL, 0x8DF78CD335BCD6F8ULL, 0x1382C4E8732B235AULL, 
            0x9245DD2AEF036BF6ULL, 0x5B1C72F4DFD25B8CULL, 0x660B119F30940DA9ULL, 0xE285774658DA36D2ULL
        },
        {
            0x3C8D709A992C841BULL, 0x05733191EDC7F397ULL, 0xFC1B65F7F0E060A3ULL, 0x853BE2B1133ADD28ULL, 
            0x4684113EB1320BDDULL, 0x6B6D712E0C5BDE84ULL, 0xD9E894F7700239FFULL, 0xD708BB497C3EB2A2ULL, 
            0x5041643D70B1DCDBULL, 0x880AE7A2B151C2B7ULL, 0x4E500CFE07C6AA60ULL, 0xA550BDCB609618E7ULL, 
            0xABE265E78A720521ULL, 0xE830B8923840A5FBULL, 0xB2178E3ABA803018ULL, 0x5269783B4DEEE435ULL, 
            0x17895F37521B5260ULL, 0xBA86A989FD86CF26ULL, 0xF2FA14B98D6702D1ULL, 0x97BC1EAB0DF5A800ULL, 
            0x81B88233C2E909E3ULL, 0xF5A4572FC079CF61ULL, 0x5AE7FCD617B843E4ULL, 0x5B01BB13C2514291ULL, 
            0xF084F9028F817BBBULL, 0xC14629075BB3BF58ULL, 0x7AF11625410CD17DULL, 0xEAE957F8E2E74A10ULL, 
            0x150311BC51D68C20ULL, 0x9507CE18AD5809B3ULL, 0xBE85F49F0FB9C882ULL, 0x5A00A909F4CEC6BDULL
        },
        {
            0xDB1D0F38D97CD68FULL, 0xD4E5A60B11997B58ULL, 0x96BECE1CEF04661AULL, 0x74DAD6D1B3B70CE4ULL, 
            0xE696C812BB5F3149ULL, 0x1EB5A8234EED746FULL, 0x08C14B91DDBA87FAULL, 0xB914CBA14F725F5BULL, 
            0x117953411EB61503ULL, 0xEB3EED464589B198ULL, 0xA006E5D4D2B859F9ULL, 0x38BB3C65276DFEFAULL, 
            0x05351BA72CEA8D1AULL, 0x599578940570D7C9ULL, 0xE2AE3B699EFE5A17ULL, 0x8191CB8A09BD8354ULL, 
            0xDA4A72A25434393BULL, 0x01E41F7855C29697ULL, 0x960706CC47569755ULL, 0xF80A76BF923D2464ULL, 
            0x5FCE5689208E5FFAULL, 0x2FE5489D0378C526ULL, 0x55BA6A752438F4A4ULL, 0x7C26058CFB96049DULL, 
            0x1A4533A0A4CC6336ULL, 0x5BBF3F42C2B013EDULL, 0xBB22ADEA3D36FCC2ULL, 0xC17D360F6A61E61EULL, 
            0xCFF2FD9D84917B55ULL, 0xBA1EA3D767C232DEULL, 0x50568D628B1AF913ULL, 0x0EFC0468E8C6512CULL
        },
        {
            0x2A869237F4C85481ULL, 0x4A58F42334D6A04DULL, 0xF402CD6C599F6A3AULL, 0xD1CE4FEFFC66CAC5ULL, 
            0xFF26286A9BF03653ULL, 0x8845D42F131E7193ULL, 0xB08943FC63DEF3D9ULL, 0xE0387F510CE84BB5ULL, 
            0x274E0A83393FE44FULL, 0x0186AE4E969DD928ULL, 0x9D5B1256DED2BDC2ULL, 0x4E5B743E19A3DB96ULL, 
            0xA650AF19A52164AAULL, 0x72986840B5861B12ULL, 0x00A32B6F33D65838ULL, 0x39388AF60BB02B12ULL, 
            0x334688B24D139CE5ULL, 0x3608C37ECCF052A4ULL, 0xBC194C9AD85F9901ULL, 0x2D8504804F8E0B84ULL, 
            0x8C61CB113281329DULL, 0x90EB3B6A0B5DE510ULL, 0xD80C8DF64C66940EULL, 0x8E78CF01CBFD7A88ULL, 
            0x2D98DD17AE9802E5ULL, 0x231307205725FA2FULL, 0xCC01BDB4C4B93067ULL, 0xBA1367693AAA4F52ULL, 
            0xBD7FE180AC853621ULL, 0x33FAD92A9AD5A69BULL, 0x389EC38920B56E8AULL, 0xA8129912F3A8031EULL
        },
        {
            0xC3E4EF36422DCADBULL, 0xEC1F37D0A5BE2A05ULL, 0xD6FC256A400E5806ULL, 0x146AAE221F774A84ULL, 
            0x08D10E0D2A3FE05AULL, 0xF32FEE3022A7F1FFULL, 0x3616B1B3C2FE548DULL, 0xFF16D0485BE4AE66ULL, 
            0x8CBE7A6B995E55FDULL, 0x941AA3D4CE24227CULL, 0xD7D3F7A4B90F627FULL, 0x9B3D47B920DC0F79ULL, 
            0x29B37257C6838273ULL, 0x94E2806BFCEC653FULL, 0x24DC3B5A33DC9960ULL, 0xE0B792A205CDCDB1ULL, 
            0x8AC8B3564DEBDBC1ULL, 0x750186B6607DF63EULL, 0xD0313E27A672E069ULL, 0xC0C17D6A28759479ULL, 
            0xA4831D1E663A5AA1ULL, 0x2CD221A77038CC69ULL, 0xEE15CA6F97554CE7ULL, 0x5619F6068CF94861ULL, 
            0xDECE8C17C0A4BFEBULL, 0x35C04D16D29FE81DULL, 0xAE69CE2C0D3B5934ULL, 0x34DDA2EFA5D37E72ULL, 
            0x26757C30A84F7936ULL, 0xFDA8B6E0651BE183ULL, 0x772664B961E68919ULL, 0x5C916146B0E1FDB7ULL
        }
    },
    {
        {
            0xE36C8579623713F0ULL, 0x231AEAFBCA136685ULL, 0xDD07866553ED00B4ULL, 0x87937A5B7236D0E2ULL, 
            0xDC9FB5D3CE0D71D8ULL, 0x0B25389D9437DCBFULL, 0xBBAD28D0CFA263FBULL, 0xEC1DEBAE494591E0ULL, 
            0x4191DF0E4C26588AULL, 0x083FA2B9BD789F38ULL, 0xB45955FF74CEEE42ULL, 0xB34B149C3466BE80ULL, 
            0xCAC559AECC5ADB58ULL, 0x21937B296EB377E6ULL, 0xCF1D640E00DB46ECULL, 0x08A3515D6F19176AULL, 
            0x6D3A824DCA66A768ULL, 0x106E1F3D8C099D97ULL, 0x65A2E52122EDD305ULL, 0xFE6C2835FCBDBC1FULL, 
            0xE23B98F4BA33DB7AULL, 0x21677920114139B2ULL, 0xB1E91B12B9C8A1E9ULL, 0xEE4CF0FCF4B5EB4DULL, 
            0xB2F46EE63B1D4404ULL, 0x953FB3A11391B9ACULL, 0x8BC1AEC793EDA291ULL, 0xE0FBB01B32AD6402ULL, 
            0xEBB86B126200F779ULL, 0xBF8892E29EEC2D4FULL, 0x11815904B2B86AB9ULL, 0x4EF04F2C9099D7CFULL
        },
        {
            0xA4C11D735AE93B7BULL, 0xF1F7EAE4C6FDAC4DULL, 0x438FFE0BB3618A30ULL, 0xDDA1CB99EE21F731ULL, 
            0xB5AB9B4E104837F9ULL, 0x9114225340635653ULL, 0x45ABE4AB225974D9ULL, 0x36DB55D92B55714CULL, 
            0x0096A26E51C86F15ULL, 0x7480ADA16FDB1A59ULL, 0xCE211F3E15E1CD88ULL, 0x81CB7CDDADEEE5C3ULL, 
            0x5229CF30606075C2ULL, 0x62F4986BD2C3DF44ULL, 0xE896076445482ED7ULL, 0xAFA90AABE515DD0FULL, 
            0xCDC600D51FBA20D2ULL, 0xC76CF85973982B35ULL, 0x1DD4C7075FD33F50ULL, 0x6B6C05FE8FDDFE91ULL, 
            0xAD610AB5E423DAD7ULL, 0x13D819C663E4B382ULL, 0x27D944E0748B838BULL, 0x520360BBDE824B2DULL, 
            0xEE1F098851F6F3FDULL, 0xFDD51A78DC702700ULL, 0x718647B3665B2700ULL, 0x7ED3351E8BC5319AULL, 
            0x642A095346CC5C98ULL, 0x9CF00BA09E54C46BULL, 0x4BB61F8CA6348513ULL, 0x2F9D3C139668FBF9ULL
        },
        {
            0x5E1C9A5FD9415485ULL, 0xD34BA652731533D5ULL, 0x082B7C9D80795C56ULL, 0xDEF5264B9936B40CULL, 
            0x7E32A8BB96929FDCULL, 0x30492775F28CAD01ULL, 0xE37DE53D7D02965FULL, 0x7BC909542B8C198EULL, 
            0x8BC2A008639F3A48ULL, 0xD99553575D44AEE5ULL, 0xC734C2079464FC1EULL, 0xC1F2A4C07E01666FULL, 
            0x63741486C9B1BD5CULL, 0xCDE0398A7898A8D1ULL, 0x130ECA9609C6F64BULL, 0xF0322EA8D3671847ULL, 
            0x088FAEF437EBCDD8ULL, 0xE1409D51DA6935CAULL, 0xA0E99148EC475B92ULL, 0x789CD1F5A8DA7B0AULL, 
            0x00A46F62DCD0FA56ULL, 0x87E618889490693BULL, 0xA8C53B59A8EBCB8BULL, 0x74C37D3C848B89A2ULL, 
            0x19D5D2CB00BE8A9CULL, 0xA94E67618BBA961AULL, 0x165CEB209DD6815AULL, 0x9982B35A86C593A9ULL, 
            0x9970E8A408B5DB1BULL, 0xBA6A89D9356073E3ULL, 0x4F03E2B3F7502245ULL, 0x110658F99B4D963CULL
        },
        {
            0x53DB8301844D36A5ULL, 0x866C510F78BC9B69ULL, 0x117263AE9803434CULL, 0x845C5C6F03F0AA5AULL, 
            0xB46B4BF8D89B5F35ULL, 0x11894401DCB9A9C9ULL, 0x50185365B917FC93ULL, 0xF8D4EEB5EF1DF179ULL, 
            0x7713DA7EBA57F35FULL, 0x713554C0F970D4A9ULL, 0xA17A39E02276941DULL, 0x1AA773CA7596702FULL, 
            0x63A8C54439E5F0ECULL, 0x4064E4B797FD02A9ULL, 0xAA2B09D4DC30B09DULL, 0x2CE2BEB89B1BD005ULL, 
            0xCC5855D8F51F4DCBULL, 0xA70C094A8E2E69BDULL, 0x819D0F7540FE2B43ULL, 0xF9E20E61315434E6ULL, 
            0x111AB2C7265AC6DEULL, 0x0EC53B8FE071E7B2ULL, 0xE6F8BF62C16EB355ULL, 0xA0602195ED2A8E29ULL, 
            0xECFF828CBC12BA5BULL, 0x65D4E13C83662915ULL, 0xEF62403866CD6E2FULL, 0xA44BC13CFA62903EULL, 
            0x4ADBB5584A75EE4FULL, 0xE20A54C031CD8B4EULL, 0xB10078D6CAC7EE56ULL, 0x55E7FEB770C2EDFCULL
        },
        {
            0xDD6EEBDE74987EBEULL, 0x9BDA4ED5CAAC3E22ULL, 0x552AEE9CD756F98FULL, 0xC1F38844C942CB33ULL, 
            0x983C77BFFD1A81FEULL, 0x54235264196795DFULL, 0xA6AFB67AA092C7EEULL, 0x4602A1286CFDA2FCULL, 
            0xCBD9272A4DD0A29AULL, 0xB255080D0DB232D3ULL, 0x886C23FC8F172AA0ULL, 0xE846666994AAEFE4ULL, 
            0x4291EEDCF0F39539ULL, 0xC64715AE809CE642ULL, 0x8F4BC01AA69E4061ULL, 0x3F0B8F6993CAADA1ULL, 
            0x6CEFD0C23B2C6C20ULL, 0x638A850878456EFBULL, 0x384D8B4F187FDF6FULL, 0x51848D56A289E81AULL, 
            0x2AE5A444E872C024ULL, 0x04A6928B690271EEULL, 0x4FF3642F8B5701F4ULL, 0x4F66F3F6815EB00CULL, 
            0xB7AF48E2B7A16AE9ULL, 0x9C4658C7F24C950EULL, 0xE6884908CE42340DULL, 0x5AD86EC10C7715D8ULL, 
            0x86F06EEA2177A266ULL, 0x833BE57CB39E1E17ULL, 0x86AC6EBEAAD747BEULL, 0x373C4FF692451B41ULL
        },
        {
            0x54ED9C00BA86F44EULL, 0xB672809E1B2B4EF3ULL, 0x1AC2557F7CC08C52ULL, 0x1C51173520D6EA62ULL, 
            0x1507617E333144C7ULL, 0x2F6CCCB3A5217CE3ULL, 0x0B612DCD42B12515ULL, 0xBBA917EC7DAA2E8BULL, 
            0x6571085563D3D8B7ULL, 0xF3023229F863B13CULL, 0xD0B17158ED4BF861ULL, 0x6E78D501180F0B95ULL, 
            0xA5664FE0118D8FBDULL, 0x8D9B08F2F4BF631AULL, 0x5FB9D25D397D0CD1ULL, 0x2C6BA0E6818BC445ULL, 
            0xCB974FD880DD4A39ULL, 0x59DA12FE44A92934ULL, 0x90E25AF527B93D79ULL, 0x2F1ACE0E9CD77CBBULL, 
            0x5233247C4F3B1EC8ULL, 0xB5A31275C5060AACULL, 0x0AE88BDACA083AB4ULL, 0x2D913D8B9895EDFBULL, 
            0x535D53F816AD4E83ULL, 0xBEBD5DF4C882F4AEULL, 0x2DC2877942DD5980ULL, 0x5253A49775D95923ULL, 
            0x5CC2132B05B71EC0ULL, 0xE1C4296696774A72ULL, 0x7D22D4B3E1518126ULL, 0x4CB3C977EBB3617EULL
        }
    },
    {
        {
            0xB923338A58C963FCULL, 0xE8D9A32673B60045ULL, 0x14F70F64323CABC4ULL, 0x4CB9C9780804C7D5ULL, 
            0xE312F531B90B4B2DULL, 0x3424E943D0A6A8F3ULL, 0x576FC7D4E3E059E3ULL, 0x75B5FC2D6BDDE36DULL, 
            0xC20BE5A62AEE2EACULL, 0x64C7344CD62EDC60ULL, 0x8B1AE968D9F86660ULL, 0xA08C3DB4C05B7583ULL, 
            0x323984B4549F24B6ULL, 0xA29C90150B306CBCULL, 0x93C9495C1D25C41EULL, 0xC1BFCD2CDEB0B87EULL, 
            0x91B19972B75FE111ULL, 0x2913F1268FECF8D1ULL, 0x51EBEE090B970896ULL, 0x2143C2D02D8870ECULL, 
            0x5E47233DDE578DE6ULL, 0x1C1B28348679CB71ULL, 0xC5C0908B868C4C2FULL, 0x76D149765E556F11ULL, 
            0x0872570DA745BF25ULL, 0xCFFA618FBBB596A9ULL, 0xBBEB1D8DEF169E12ULL, 0xA796903B7A106609ULL, 
            0xBEC615EFD344A034ULL, 0xB57134076AD33BDEULL, 0xDCFE42500B3B1693ULL, 0x6612FE1F52CFB003ULL
        },
        {
            0x21473A393C7696DDULL, 0xF09BBAB5D8341FC5ULL, 0x2AB45659D9C9CE75ULL, 0x9226BDEC6B86F8C6ULL, 
            0xBE1B2A42855C6E17ULL, 0x333DF241295E3E97ULL, 0xC3A989CC7ECCEAEBULL, 0xB714B8DE96069DFBULL, 
            0x54975779B0F00C4EULL, 0x7F5A93BBB3BEC8BDULL, 0x860C1D8B0D5DBCEEULL, 0x5EF06DE601D53C6EULL, 
            0xE45768E048FFD550ULL, 0x44D170491AEF02B5ULL, 0x8FB13E17F15E293AULL, 0xF677941771D3B3C8ULL, 
            0x8506B1B13AF51BCBULL, 0x050E97FAB01D973FULL, 0x1880B0B8B499B164ULL, 0x395B29949A1B9495ULL, 
            0xA280FA39B695FBCAULL, 0x19B88A75B3B2C669ULL, 0x5B2B8D7A0267EC55ULL, 0x74E8F829672BD6FBULL, 
            0x6DC8DDC7083105B7ULL, 0xC8D69040B0CC1526ULL, 0x7A911E5E3136E862ULL, 0xE6328B5E2C2CE4F8ULL, 
            0x3B0BF253E7B14548ULL, 0xF8657EE0C04CB5DAULL, 0xE24686523479909EULL, 0x3D003DFD3952324FULL
        },
        {
            0x40534EB962CA76A7ULL, 0x4BF95EA03748A94AULL, 0x1D1B33CDCE2A1F91ULL, 0xF053D4B0371BCDB3ULL, 
            0x37F3388E4AF59E66ULL, 0x93D53572F9360C5EULL, 0xEC0FE7023C7EC622ULL, 0x36AE41A15CE67A45ULL, 
            0x61760809D1EF2AD3ULL, 0x79C83AF621BE85B5ULL, 0x8FDFFAFF1CCF58E3ULL, 0xFCB2ABB11239ABA1ULL, 
            0x40D0675AF3676773ULL, 0x1FD2F214C8EFAD0FULL, 0x60EC47C01E424B36ULL, 0xFDFB6DB889D5464FULL, 
            0x40C2C41C808FF6AFULL, 0xA9946E80473C4046ULL, 0xDD54547B174170B9ULL, 0x6F9A15C8C772161AULL, 
            0x996C4B5EC5DA1200ULL, 0x3F75D7F3242E435DULL, 0x46853C74CD33C412ULL, 0xA31B53F4EC10E879ULL, 
            0x300B7BA917A3BD7CULL, 0xFACE7C9A77A8CA35ULL, 0xF586D9CC28A674D6ULL, 0x494575172264920DULL, 
            0xF6D7A04F3A493586ULL, 0xABD2C96E1FD0746DULL, 0x4DA47E11BA851409ULL, 0x054CB99E29BDF0E2ULL
        },
        {
            0xEB0972A0C959E3BEULL, 0x93191A2F859832A2ULL, 0x75E72A8E846C1288ULL, 0x7EDC1F383EBB0B2EULL, 
            0xD2FA062FDF6F207BULL, 0xD49F8C62A9D90CA2ULL, 0x43EA7D40C99DF60EULL, 0xDE40ECA5DE90E4A3ULL, 
            0xBC6DF2D8BDD4AAF9ULL, 0x0A6E657675C0B416ULL, 0xFC58032FEE033281ULL, 0x317A14C82FBC44E9ULL, 
            0xF6DF339095C8102EULL, 0xB05824C16DB89717ULL, 0x7CD5101CC816458BULL, 0x25B068043EB0282FULL, 
            0x0B8C899D9454E4FCULL, 0x61AB6D39117FAC01ULL, 0x5B5763E7ED6B6AC8ULL, 0x42FE8A34C2ACECADULL, 
            0x2E81FAD97458AEF3ULL, 0xDDC1601C0700EFDFULL, 0x548395F38C8BC36CULL, 0x08A377496DC175E2ULL, 
            0xA4BE68134A476520ULL, 0xF5936E4030BB0093ULL, 0xEF43C770CA319986ULL, 0x5D7665479722092BULL, 
            0x394CDF77B16F4576ULL, 0x6995DF07A419927DULL, 0x61A29109642A493DULL, 0x07DB7525646A5549ULL
        },
        {
            0x51953A874C91779DULL, 0x217513460F2A6B2AULL, 0x05E67F134B6DE86FULL, 0x4FB2C68AC9C67B7CULL, 
            0x24576008C833EC9EULL, 0xD8E8D01191E6FDF7ULL, 0x4BFCF01CC5CBCB0BULL, 0xEB05A41D0AEA3F8EULL, 
            0xFFA1074913945CC8ULL, 0x6E7EC96F0043B0CBULL, 0xA8B70F39745EDBA2ULL, 0x4CA2446EC478FAE7ULL, 
            0xEC1DB669B38FA7B2ULL, 0x8328567530E989D6ULL, 0xB3C5FACF2B8853D3ULL, 0xDA1FAB7DA97BDA9FULL, 
            0xCD594494806A2DFBULL, 0x5A93355FCB0AD3C5ULL, 0x6339FD9835432393ULL, 0xB4FEA3AC21DE1674ULL, 
            0x7EEC70F65C64DFF8ULL, 0xEA2146105A239BF9ULL, 0x2F156F219A948C34ULL, 0x534B345129CD14E8ULL, 
            0xEA9867F23775FCA6ULL, 0x9AA56524A171466CULL, 0x28C7F5653A7FC99BULL, 0x86AE1BD7E8A1693AULL, 
            0xBD9DE25D4422EAFCULL, 0x2D87DABC1D258C88ULL, 0xB39780A4192246C3ULL, 0x357FEA72C61FB032ULL
        },
        {
            0x0C7F2C94C263D9B7ULL, 0x50279C47CDF462F1ULL, 0x8592DD625D9E4081ULL, 0x1D8C48AFC1DF33C6ULL, 
            0xD141AA560EAFA52DULL, 0xEE8F5679565F2F9AULL, 0x12D17DE173ECC10CULL, 0xB3BAF5324AEEC2BBULL, 
            0xE63FE65ED9A6E9F3ULL, 0xCF8C869F3B13984EULL, 0x4929E4722E8CFF03ULL, 0x1AAB47D464864853ULL, 
            0x3CA9F262A7697558ULL, 0x357D6ED0637DF47DULL, 0x9E76BF619AF285EFULL, 0xF5BBDA1EC2985545ULL, 
            0x01AD9F501065F24FULL, 0x0D99928E2452C203ULL, 0xB3ED43919A031392ULL, 0x56660A1893134E96ULL, 
            0xB93A734D8BD58870ULL, 0x8C5182EF521CA38EULL, 0x6499785F20F7A7A6ULL, 0xA8E018B9995AADC8ULL, 
            0xBF4EF3750A5E6755ULL, 0xEE4522A44CA8BE80ULL, 0x9D3F611FD1B4F698ULL, 0x504B641FE910C275ULL, 
            0xF709149F25BB9F35ULL, 0xF09211C173661790ULL, 0xE418677E72B12687ULL, 0xF682BE3751FA64D0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseGConstants = {
    0x54CB6186170B4A64ULL,
    0x9604614923F17ACDULL,
    0xB67568B5CA382C9BULL,
    0x54CB6186170B4A64ULL,
    0x9604614923F17ACDULL,
    0xB67568B5CA382C9BULL,
    0xF239ADBBFDA73847ULL,
    0x01BED75A525A4096ULL,
    0x27,
    0x92,
    0x7A,
    0x74,
    0x9C,
    0x67,
    0xDD,
    0x8A
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseHSalts = {
    {
        {
            0x5A9A522EA849542EULL, 0x324A3F374EE5604BULL, 0xEABBB348B59B298AULL, 0xF0917D33C8EB7B45ULL, 
            0x0EB146EE605884B8ULL, 0x06381BA0FB82551BULL, 0xFBF55B18FA3BBCF2ULL, 0x894AF0FA26590F42ULL, 
            0x49D5CDD0753FC2D5ULL, 0x88D4B72CF846A0DDULL, 0xB9CDB9C89C444E67ULL, 0x042A8474A338AFA7ULL, 
            0x176197346AFB0A74ULL, 0x953FA10AFD2CF8A1ULL, 0xD0076D0CBA6CEF0BULL, 0xCBA865C5CD4D3F58ULL, 
            0xBAA1831EFA496569ULL, 0x6535EF6B1B5292C3ULL, 0x766C8ACAA7A5327AULL, 0x688495669A6EF990ULL, 
            0x907747926F3AF256ULL, 0x26F1D7AAF3FEFE72ULL, 0x4701352CCFB1779CULL, 0xB0B7B16046707475ULL, 
            0x33F7797D78C67C10ULL, 0x27562B345E91C4E7ULL, 0xC93B31BF405AF6C1ULL, 0xE4314B9866AF6C68ULL, 
            0xB8D608244E1FAFAEULL, 0x7F26B1A810D4411AULL, 0x5BC6371899A17499ULL, 0x08FE2F8B41059465ULL
        },
        {
            0xA332774E27583782ULL, 0xC3D75CAF4BD708F3ULL, 0x4334CFBBD4D100D2ULL, 0xDDCDBC47DE2E8DC2ULL, 
            0xF003231B29D62AA1ULL, 0x7B7ED3FEF9C6F6B8ULL, 0xA774CDFB3A8D182CULL, 0x272CBA31AD59AFCCULL, 
            0x7C8EDC6FF3F0C4A8ULL, 0xE690B6EE2FC65220ULL, 0x396A23C2B6117976ULL, 0xA184E8BA1DBFBF4DULL, 
            0x2BF9C45D562CE921ULL, 0x3B66CEA40EB73337ULL, 0x1306E53B163FC178ULL, 0x4727E5E2FFA7BA51ULL, 
            0x72DED81ABE5A1B33ULL, 0x83ADAF3045B1F363ULL, 0x3D8FE5AC2A9D65D8ULL, 0xE4778B7BD46AAD04ULL, 
            0x22E65854435C9737ULL, 0x35BAF6708188E43AULL, 0xF21A26C0CA8870C1ULL, 0x734ABF9D21FC843BULL, 
            0xB92B54AB433F2271ULL, 0xB542608A0677A28EULL, 0x2FCFF24F2851540AULL, 0xCB06E2DB5DA39C80ULL, 
            0x19FCA8A896147FCEULL, 0x81244EC4A33DC162ULL, 0xE0D3FBC3DB1F45C0ULL, 0x44BF7B898F27B0F1ULL
        },
        {
            0x020289352081F65FULL, 0xE93A34DF11BF6C61ULL, 0xCC795E7DBE757EA6ULL, 0xAA95B3C21B8801E7ULL, 
            0x76821FEEF4BAF2DBULL, 0x8A670E94632C4FECULL, 0x8A3B9F938D161341ULL, 0xB463792BB8798C9DULL, 
            0x940537943CFABD4BULL, 0x9B31725B421A03DEULL, 0x8496EE6257438F07ULL, 0xB6D447EB06019891ULL, 
            0xEEB16E4DACD0AF61ULL, 0xBE78714BDBBF2AA1ULL, 0xB2BEFCC683269E2AULL, 0x343EDB9819110F7AULL, 
            0x55C72BBB3CFF2AD9ULL, 0xFAF031ADB53BFF47ULL, 0x912B761ADA5BC5B2ULL, 0xBE41B304DBB647F2ULL, 
            0x607477824E0D0CBEULL, 0x0A5BC2AB2B8C2C68ULL, 0x81BC896936543550ULL, 0x31699221FF4BCB40ULL, 
            0xB61960ABA47B229CULL, 0xC0B3D90DF6D92503ULL, 0x7AC6B3D57F38BA50ULL, 0x192E8F8D099ED3F3ULL, 
            0xCDE3FAA269EFBCE8ULL, 0xC87DB73FF582E185ULL, 0xA318057E32E25E74ULL, 0x2B5F98C922B8D667ULL
        },
        {
            0x6913EE964100AAB3ULL, 0x4ABB9302DDF1A569ULL, 0x527428338F868C6CULL, 0x43242B3DBFA55A83ULL, 
            0x65E24DF9D789943EULL, 0xF53857DBC02E4A02ULL, 0x51032555046BF7D2ULL, 0x52F982827FAE4875ULL, 
            0x3DB1A7772303F569ULL, 0xC6B12D7BE990AB6AULL, 0xF7A41804C43CE062ULL, 0x97EE5BB57254164CULL, 
            0x5754D21930318F1EULL, 0xF7ED44BC9BE1F245ULL, 0x682F92294B8E59F8ULL, 0x770B05E342B4ADDEULL, 
            0x4A5602735400D293ULL, 0xCF32A17F0C34CDCFULL, 0x3C700AE60D834721ULL, 0x178654816C5FBD5FULL, 
            0xD98EEE6C0615D99FULL, 0x35E8C2EDC3B8DA67ULL, 0x3FB01A095D177724ULL, 0x429C191BC23C734BULL, 
            0xA9AFDA0838E6E83DULL, 0xFBAB448B15526937ULL, 0xFC5C09179946C898ULL, 0x272210A3F57E4B4AULL, 
            0xCC78ED166F5F4321ULL, 0xECECF7365912CC5AULL, 0x73670654D4ED36DEULL, 0xECDA748438D46D10ULL
        },
        {
            0xDA6E7EE37B2A769FULL, 0x0767168D93C05F8FULL, 0xFA0F42319DD699EAULL, 0xB19B1D211017CCB3ULL, 
            0x99D4D5046E138864ULL, 0x0B3873C9C41D8B51ULL, 0x729A27B2EB7DDB72ULL, 0x2E0F3E6DCA06CEDCULL, 
            0xDC41C617A21054DCULL, 0x3F0B721E0FB3A76DULL, 0x7A4CEF9BF3A0AC0CULL, 0xDF09E17580FDB9EEULL, 
            0xC393B7C93E8C3866ULL, 0x1C184FEDAD55E7D0ULL, 0xEBB8CA0AF2CB0D95ULL, 0xF40F80D5BAA53B3DULL, 
            0xF6143F50FA4E1DE1ULL, 0x7338C51E2D178934ULL, 0xE3D379615992B670ULL, 0x70429E1EE3B06ACDULL, 
            0xA89C1F948AF8195DULL, 0x24DBFA97545D1F92ULL, 0xC776F8435F459EF1ULL, 0xBE5A46346F9CCC6DULL, 
            0x2CA995E71D3E2B30ULL, 0xE64CD47FEB1C885FULL, 0x2A484AAAB7EDBCDBULL, 0x00BB936FFAABCB49ULL, 
            0xAF7F1A1FFF4A1379ULL, 0x49EC5EB58FD354CBULL, 0x8EBEC35F24D1A2C7ULL, 0x72617B5E35E9D026ULL
        },
        {
            0x18D129062E6F7562ULL, 0x846E6C6199B3AEDEULL, 0xE67B0591ED25B58BULL, 0x0C8024FAA638FC3DULL, 
            0x4EFFAED77598DF9BULL, 0x11E8761FA3623AF2ULL, 0xBBAE6794B539E3DAULL, 0xD772B8BD958621F1ULL, 
            0xB8549934F8607D05ULL, 0x58711B92F923BE87ULL, 0x23937642C5D91159ULL, 0xE47AB2CE83C11899ULL, 
            0x838C187891C416B3ULL, 0x0E0AF2D8EDFC139AULL, 0x38FCBEBB6702B304ULL, 0x222AF0DDF0CBD012ULL, 
            0xC2B47C941EA7CB12ULL, 0x0DCC2D3B9C445DF9ULL, 0xD975C903729E6FF0ULL, 0x489C2F34162E0C65ULL, 
            0x587765D214F58544ULL, 0xD84410751F83ADA2ULL, 0x09C213D65CC073CEULL, 0xAD465BCEC54614EAULL, 
            0xAEB245714CD98182ULL, 0x179CF88AE8B30D8EULL, 0xB008BD872CE77D5DULL, 0x98C894994D9F7EDFULL, 
            0xEA0B04DA2F290E86ULL, 0x6ECBFD205342B3A3ULL, 0x6B601F580ADCFE89ULL, 0x3E8E5EB00944AC0CULL
        }
    },
    {
        {
            0x7825C779A7B342D0ULL, 0x48F060B303715BF6ULL, 0x831705AC89B013B1ULL, 0x99D4EEAB0D490C1AULL, 
            0x3196C60112CE9A51ULL, 0xF83E7E69563DE80FULL, 0x78135CBD9788F028ULL, 0x258021B93A085C1BULL, 
            0xDF3275D056DDE89AULL, 0x2E47780AC91EA298ULL, 0xDEE561C04B6E4D2AULL, 0x4FD43C01BDAB0327ULL, 
            0x30E69FC4DF1397EBULL, 0x446096E68CD78DD6ULL, 0x058DC1F617748670ULL, 0x3DB2D48EEFF3354FULL, 
            0xBA746A9374630C75ULL, 0xC2B408F17F836737ULL, 0x240FD81C5AADE21AULL, 0xE805BA8354523167ULL, 
            0xE9FCD9D551BA49F5ULL, 0x006223DA7D512F5AULL, 0xF2DF1808DC4FC284ULL, 0x94193497692834F1ULL, 
            0x857154DB4B40CAB4ULL, 0x5E0C18AA9D691EA6ULL, 0x191062721A8182EDULL, 0xE75606B3092E16D7ULL, 
            0xE3BAD8F87C51D4C6ULL, 0x2439F7D8AAF80D4FULL, 0x421EE5593BA6EED8ULL, 0xC2D04CE6C8FDE744ULL
        },
        {
            0x925D2B77E9341C61ULL, 0xD2CB90926AFF92D5ULL, 0xE2FA2F7299046489ULL, 0x53F2E723F6B49E1AULL, 
            0x39FC08423181A0A3ULL, 0x1BCFBCE86C03D501ULL, 0x89B692C3B3D94538ULL, 0xCF9B9D86D0B5EFE8ULL, 
            0xD986AF265CD16E25ULL, 0x7794C612052C0611ULL, 0x5703FDC6BEFC135CULL, 0xF09A429EC104A1EBULL, 
            0xDBD7A05D56A05AE3ULL, 0xADFBC12B435A65DCULL, 0xD40CA0A022B06D10ULL, 0xFE73B6EABC05CD0CULL, 
            0x3BF6581191DA4F1BULL, 0xFA63B41A62261B06ULL, 0x8157AF6A09930163ULL, 0x9E49BFE56896FE8DULL, 
            0xD9089AFE65117550ULL, 0xDCC97480A99D75C2ULL, 0xBCEB595D74CB56EAULL, 0x7372960130C6898EULL, 
            0x4A18D4CF38EF4443ULL, 0xB97389767C59B2D8ULL, 0x8D36C6A576BFC391ULL, 0x3E1015F226306112ULL, 
            0x14A2A3645311DA43ULL, 0x23F21EC234F1A19BULL, 0xF10D35C12085681AULL, 0xC51BC58134786485ULL
        },
        {
            0x5C3BD5BB31EB8961ULL, 0x2827941593B6834AULL, 0x3AA4CBCD0BA9C3DBULL, 0xD5EF3FDC733A4B37ULL, 
            0x6158F902C0843E2FULL, 0x73A5289C700B2B39ULL, 0xC1FF7D5AE1051B7AULL, 0xCC3B662CF96DA0D7ULL, 
            0xA534547EE699CF78ULL, 0xBB61E959D8861E1EULL, 0x6E08518BE00F4696ULL, 0x823B8F864EE0C333ULL, 
            0x64260AD7085B8ABDULL, 0xFE0BB7360C99B849ULL, 0x9CBDBCDA0F596E15ULL, 0x970DC388F5C83426ULL, 
            0xA30E67D4F2BEA9FEULL, 0xEB59076151F959B5ULL, 0x0D49807AA27C5822ULL, 0x8271C3BF2B8257A8ULL, 
            0x9A4E7B52A798D2CDULL, 0x21059C8F37599F90ULL, 0x7783EC0DFF2B7548ULL, 0x9A08B5807A463793ULL, 
            0x5DB4AD030AC1276DULL, 0x965C8EC3C0E7D496ULL, 0x6977AC4E59E454D2ULL, 0x33785350AABC6930ULL, 
            0x6E10847062237E4EULL, 0x2773FBB046BB2D81ULL, 0xC5E543E6F9E4C1D7ULL, 0xB882DC217B42F6ACULL
        },
        {
            0xA349671ECEFDED69ULL, 0x818A89B62B15C1E7ULL, 0x8BC22C86E115CDABULL, 0xE40DC962EDC896C1ULL, 
            0x76B973456189D3F1ULL, 0x9A6FBFF84BDEE387ULL, 0xF664FE3D812F39E8ULL, 0xD22B571B512623F1ULL, 
            0x39FD7CC93168ECDBULL, 0x29972A2A324F717FULL, 0xC9EFBEE32E88C3F3ULL, 0xEBF461CCA2F0F649ULL, 
            0x8F969DD22672A784ULL, 0xEAF8BC0325A73BD7ULL, 0xB5EF9E8A7CEACACEULL, 0x4F017EE8E897706CULL, 
            0xA9B47C602666951CULL, 0xBBE622E0C4A2E72CULL, 0xDF4E736BFB9CF712ULL, 0x0F3F4444FA487D74ULL, 
            0xD9D1B0CCB1B7CEE6ULL, 0xB1018D5C6065D8E4ULL, 0xB9B7C73131DFD41AULL, 0xD8C4FF6DDEECDBD1ULL, 
            0x2F2E2CECBF95ECDBULL, 0x78E242EC8C315FB3ULL, 0x24C24D8186E7207AULL, 0x7D3D35ACF71B099FULL, 
            0xBA3C31AF8967775DULL, 0x51B8D7EB923827D3ULL, 0x51A5E7593DC22F9AULL, 0xB9253B3F7460C63DULL
        },
        {
            0x2A9DCBA0CE0B8DC4ULL, 0xF3FE9BE6B71541DAULL, 0x26CD10162C2C7616ULL, 0x1C0141095FC17D20ULL, 
            0x9467205D177A99C2ULL, 0xAEADB79FB7B16298ULL, 0x96703DD3E27F24FAULL, 0xEAD716761DF00554ULL, 
            0xE7E46399D2D437B7ULL, 0x2416B073FB0582E7ULL, 0xDC679D3F3B070BD5ULL, 0x6DC4EB500E9AFE5AULL, 
            0x564836379F790100ULL, 0x4A56C0573C0A7DD2ULL, 0xC05B39F3D0DDD1EDULL, 0x5BC7F243348E9567ULL, 
            0xA5B22A0DD081A587ULL, 0x342D95CF658F927AULL, 0x95D083795DC93C4BULL, 0x706EF5865619BA10ULL, 
            0xB2609F70C8A67E72ULL, 0xCBC37BB529E5CCD2ULL, 0xCD6C264C35C7B1B0ULL, 0x14DCE03571EF0F1CULL, 
            0x34217924FC630255ULL, 0x7F01C4C546D2C2E1ULL, 0x0467860760DE2A87ULL, 0x3C038C0506B005DCULL, 
            0xACF0761F85C26101ULL, 0x647B95CF8C9B7BACULL, 0x078F3761A4DCEB7FULL, 0x395885B160548421ULL
        },
        {
            0x121E0601C896671DULL, 0x19F36D8455026E3AULL, 0x35C0753F1701180FULL, 0x440C2EFDE8A3BD7AULL, 
            0x60EC34147C804A82ULL, 0x88809AEA20B381E1ULL, 0x2519991C9E711529ULL, 0xCCA129B67578D7BBULL, 
            0x95738231A4A96D41ULL, 0x23F150E2175EC2FEULL, 0xEEC53003C61076E4ULL, 0x945523AAB8BA3338ULL, 
            0x385F9143F315D44EULL, 0xFA471DF95BA4C6F2ULL, 0x2A0A9295141BD92FULL, 0x853A4CB253A0FFA7ULL, 
            0x51B0A775624517C9ULL, 0x53A08FA52AB7D20AULL, 0xFFC0DC768D1579A6ULL, 0x7BC05C94E7CB384CULL, 
            0xCC6EF11AF2538FE9ULL, 0x31E3C7779A11C501ULL, 0x14339632D3FEB22DULL, 0x581E9CA248BB2137ULL, 
            0xC013DD3BCE584B1AULL, 0xB6E960A7A7DC12E9ULL, 0x95D1F77794CAF51BULL, 0x1EA82217D3E59CD8ULL, 
            0x5D30E847A384C9D6ULL, 0x83D9E2C270FD333EULL, 0x9C10779A9B3622B4ULL, 0x9A28CD02B634FD69ULL
        }
    },
    {
        {
            0x0B828A703245B744ULL, 0xCA0A9E814BF1888EULL, 0xE940312260CEA292ULL, 0xF9420039A6FC12FDULL, 
            0xB635355DB621D845ULL, 0x1CD41702B35F9878ULL, 0x89E66AEF0C1B5560ULL, 0x0C2C69347204BC4BULL, 
            0x9DA42AF434EFC439ULL, 0x2175206FDB1756E1ULL, 0x5A0D67B877AA0276ULL, 0x78E288214D15E007ULL, 
            0xA0A5520F937796A2ULL, 0x41602505D29923EAULL, 0xE608442B5BF6DC31ULL, 0xA88ABBBA2DE2070CULL, 
            0x0EB62D7DA00951DCULL, 0xBE3C3E27B7330B56ULL, 0xE489538CEA217684ULL, 0x7A258723F7DCC767ULL, 
            0xC6E5A8BAC021C243ULL, 0xB627A4C9DE520465ULL, 0x79A1BCC851A60644ULL, 0xCC8D3767DF948D64ULL, 
            0x1D2B546F2EAFBA07ULL, 0x93A135AFC812291DULL, 0x6D20F7F1E3E97D06ULL, 0x4A31F8EECF834870ULL, 
            0xC95EE5B448DB7154ULL, 0x2A394B5D279128D4ULL, 0x0EF2A829CA7BB015ULL, 0xCE128A38997D11A0ULL
        },
        {
            0xC6CD310393C2DEE6ULL, 0x75CA5F4F92B1EC7AULL, 0x2894A32F8AB85992ULL, 0xAB04258AE4EC6426ULL, 
            0x7DBDEB10986F53F4ULL, 0x35AC81F9B2564E39ULL, 0x9E784339BDF53D57ULL, 0x0647A2950312CE7DULL, 
            0xD50650856EAB8C2BULL, 0x55A6CE2DC5F4542AULL, 0x5D36C24EB9D81C04ULL, 0x1C307D7AAFD84A18ULL, 
            0x4057EC2C13182A7FULL, 0x3F30D127184616B0ULL, 0x871B76B1D1DE0FC3ULL, 0x2DAB8DDBAD809A59ULL, 
            0x9C14D069A7498718ULL, 0xCBF1575C7605C84BULL, 0x3EE5215DE2D2A349ULL, 0x5518D2C1CE797CC8ULL, 
            0x5DB5866CBB75570EULL, 0xC2352E07C0DB3E90ULL, 0x68185948BDE1B02DULL, 0x4F76B0C7FD4F3E78ULL, 
            0xDAABC02A9BB8C862ULL, 0x0CDD7EF8D5B227F1ULL, 0x2D82242DA3D0BE6BULL, 0xF06B3F00195B429AULL, 
            0x6FDA3F91AC00C949ULL, 0x37C77DA7B98E9954ULL, 0xCDB18D440E05E7ADULL, 0x0D89DB2B32CA332AULL
        },
        {
            0x79A2B6593F1AB504ULL, 0x08AEAE2CB180BA23ULL, 0xDF951FFEC0A3374DULL, 0x62396F94D685BF8BULL, 
            0x0603D4C1F0B5C096ULL, 0xD5764104BCB7806BULL, 0xC779FD597DD8943FULL, 0xE4318CE606A91DBDULL, 
            0xEAB49579D8460010ULL, 0xB67D9D78673395D8ULL, 0xE2EACB8C534C7EECULL, 0xF8C4EEA732D7E837ULL, 
            0x89D0F0B6027955EAULL, 0x689BCB128EBB7F4DULL, 0x849E5BFF80212AF6ULL, 0x9B2A0F1BE6E67769ULL, 
            0xCF32B991A8EC292AULL, 0xF9A9FEE26CD19C96ULL, 0xC775B6F207E37AB7ULL, 0x6F5808C17A1CA071ULL, 
            0x7F6B8170D1E5B717ULL, 0xB83293CA1EE2F06FULL, 0xB5CE456755ED0ACCULL, 0x58BA08F0DC1B0E03ULL, 
            0xFCE85A1FBC0C0C99ULL, 0xF5993905D2AC65A2ULL, 0x7A2D31F8A1359178ULL, 0x95D2E026493B6EF6ULL, 
            0xE30EDE934ACF395DULL, 0x6873F88BC28708F1ULL, 0x5DB902BF4AE8D314ULL, 0x443561740BBE4F7BULL
        },
        {
            0x52E22BB7C234EA6BULL, 0x31B445AF7DD4D0BAULL, 0x15CFD28FF4A0E97AULL, 0x2EA5A0416CE47441ULL, 
            0x2D0A802C7A8B25B2ULL, 0xDBEBA70F22989534ULL, 0x01D3730C9E4BD8B9ULL, 0x6BC9D7CA7A2FFCB2ULL, 
            0x125C34BFA080D646ULL, 0x5B495BE1A261812CULL, 0x8388358DA5FB61A7ULL, 0xCB8A8134A15BAD6BULL, 
            0xF68619E0058BE003ULL, 0x61CAB878E11D90C2ULL, 0x9C2DD228007346BBULL, 0x78D62E2ECFF12412ULL, 
            0x04006A3448525996ULL, 0xD4BA4328444DDC8AULL, 0xFA87E14C182080CEULL, 0x212F5115CC2A3CBEULL, 
            0xEBAFEE4C96F5073AULL, 0x79357E18EFBD2639ULL, 0x9B38EDDD917303F5ULL, 0x762BBFE32B35A1F5ULL, 
            0x554CBB4D388B8C02ULL, 0x6A1A5A180FD9A158ULL, 0xFC7F3C10279AE176ULL, 0xF6D12738798C35D3ULL, 
            0x78F1FF39D38D0A36ULL, 0x90CCB443E5273DA0ULL, 0x5768A65FCC81D60BULL, 0xA331BAC291EDDC21ULL
        },
        {
            0xCD6B66D9E395330BULL, 0x31FF51457BFD2A1FULL, 0x8557068A5A8A2831ULL, 0x97F8D7D6EC4C860FULL, 
            0x5B2BE3AC01532C2BULL, 0x5C197E9BCB14CD50ULL, 0x1046D293AAF3394DULL, 0xD42B8A1F467503F3ULL, 
            0xC1C48217BA81DC74ULL, 0xA7AA2ED589B3EB7DULL, 0xC37C063830BE4CB6ULL, 0xC4B498942C43C46FULL, 
            0xD39EA0407216ADA6ULL, 0xEE38E2659FE50D14ULL, 0x82FE9E9E0D2287DEULL, 0xCDA23A76F92A9AC2ULL, 
            0x89E5E2E0B0022882ULL, 0xA1F6F5EF74B30ABDULL, 0xDBE84B0582839B16ULL, 0x510F7E21DF9512EAULL, 
            0x189F199BA4F8837AULL, 0x7072CA68090170A9ULL, 0x197A6207DA948073ULL, 0x67B618ED931B6DDEULL, 
            0x0C44770D1C5F3EE5ULL, 0xAAD44F37131BCDEDULL, 0x6F494AC794986C78ULL, 0xF0D8654626D4E348ULL, 
            0x7209BADCDA096271ULL, 0xEB82FBE2A016E173ULL, 0x98D9FE54978CA9C5ULL, 0xE6BA389530EA6171ULL
        },
        {
            0x2389E3410C9D7292ULL, 0xCD91C655897B5E36ULL, 0xE0A8FD42CE423DDDULL, 0xBE3C85A824A13082ULL, 
            0x297BE1C830F88ED9ULL, 0xB465DF7627E756ABULL, 0x1ED290002DD6ADAFULL, 0x82F324A23CC71453ULL, 
            0xB9B4A3F1410686ABULL, 0x6AE4E26309A5DBBCULL, 0xA9A93D023ADCD6C2ULL, 0x88E8D50F21864F7CULL, 
            0x71EB4B3C91022F9FULL, 0x63D6D2280AD0B9BCULL, 0x8DD3187F3753D8A6ULL, 0x5C63F0CCCF1F64D1ULL, 
            0x81E22B9D8C353944ULL, 0xBEB0113BD490D547ULL, 0x318D3DF1EB27BEF4ULL, 0x7CDB30EC19BD35D7ULL, 
            0x103197640225163FULL, 0x4BE5CE25728FA202ULL, 0x45AA1E2348457C16ULL, 0x44ECBD757708507DULL, 
            0x8B2F31E591637B33ULL, 0x9ACEF74692F0239FULL, 0xE4CB9AC5C329160FULL, 0xC764DB2127C2CB9CULL, 
            0x263FD0FC3F612A7CULL, 0x4202712B40B4EDACULL, 0xEBD115510572BA19ULL, 0xD4922F92C584BAAFULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseHConstants = {
    0xA57BE9F4F10C282BULL,
    0x9880187320FA9FD5ULL,
    0xCAEEDC370FB3DFEBULL,
    0xA57BE9F4F10C282BULL,
    0x9880187320FA9FD5ULL,
    0xCAEEDC370FB3DFEBULL,
    0xECC268A86BA94162ULL,
    0xF07016BB2962E038ULL,
    0x79,
    0x0F,
    0xAF,
    0xA0,
    0x4C,
    0xA1,
    0xB8,
    0x12
};

