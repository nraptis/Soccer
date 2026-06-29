#include "TwistExpander_Rugby.hpp"
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

TwistExpander_Rugby::TwistExpander_Rugby()
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

void TwistExpander_Rugby::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xC6326E4E4B826AF9ULL; std::uint64_t aIngress = 0xDAD5E4299CD886F8ULL; std::uint64_t aCarry = 0xB6C77C0268DD1BD5ULL;

    std::uint64_t aWandererA = 0xDD71D651FE878F43ULL; std::uint64_t aWandererB = 0xAAEA930B96EC9105ULL; std::uint64_t aWandererC = 0xE546C97C8EAD10D7ULL; std::uint64_t aWandererD = 0xC1AA4D54CE7C0E85ULL;
    std::uint64_t aWandererE = 0xC7F5ABFCFA02D9FEULL; std::uint64_t aWandererF = 0xD9AD22F383EDF421ULL; std::uint64_t aWandererG = 0x9E316654C699F109ULL; std::uint64_t aWandererH = 0xB2CFB1F6CC2D1D2AULL;
    std::uint64_t aWandererI = 0xC8148ED28C98B347ULL; std::uint64_t aWandererJ = 0x88CD23DC63FD5E6FULL; std::uint64_t aWandererK = 0x83889B153E02559EULL;

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
        aPrevious = 16603106408618796300U;
        aCarry = 12676963187394881942U;
        aWandererA = 9665608774720496437U;
        aWandererB = 17579821587278142677U;
        aWandererC = 13827827338727738399U;
        aWandererD = 9744988834048690393U;
        aWandererE = 10737684079417212435U;
        aWandererF = 10644979325231581010U;
        aWandererG = 12013684153681818576U;
        aWandererH = 13884270014167972388U;
        aWandererI = 18042706200886350260U;
        aWandererJ = 16551560349947610823U;
        aWandererK = 17667197531168668638U;
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
    TwistExpander_Rugby_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Rugby_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Rugby_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Rugby_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Rugby::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xF1D81549F1D6AD93ULL; std::uint64_t aIngress = 0xD7E1D3638B3B0A60ULL; std::uint64_t aCarry = 0xB41CE1D8E2AC253BULL;

    std::uint64_t aWandererA = 0x93DF7698FD82C774ULL; std::uint64_t aWandererB = 0x8A891A4762892760ULL; std::uint64_t aWandererC = 0xFEB2B923474C7737ULL; std::uint64_t aWandererD = 0x887985C3FF6D8B2FULL;
    std::uint64_t aWandererE = 0xE33BED6741E38798ULL; std::uint64_t aWandererF = 0xE205A472F8538FC1ULL; std::uint64_t aWandererG = 0xDABC4FD907E5317BULL; std::uint64_t aWandererH = 0x801E9B41DA81B195ULL;
    std::uint64_t aWandererI = 0xDC737A2FC496279CULL; std::uint64_t aWandererJ = 0xF3214856CACE24D8ULL; std::uint64_t aWandererK = 0xFBE5D92A5EA65DC2ULL;

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
        aPrevious = 12617818307855013164U;
        aCarry = 18247750439519501933U;
        aWandererA = 11201406423262003473U;
        aWandererB = 12614365626412389456U;
        aWandererC = 14808797891187368848U;
        aWandererD = 16885660688648745999U;
        aWandererE = 16039771703062549519U;
        aWandererF = 10808981557149534917U;
        aWandererG = 12572291258231148655U;
        aWandererH = 17665102655945767906U;
        aWandererI = 17286374214726473794U;
        aWandererJ = 12193625427824681396U;
        aWandererK = 12505803322136194039U;
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
    TwistExpander_Rugby_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Rugby_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Rugby_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Rugby_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Rugby::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF15CA2867A43F0DCULL;
    std::uint64_t aIngress = 0xBDAC59473E0B7000ULL;
    std::uint64_t aCarry = 0xCC81FCD2AA196073ULL;

    std::uint64_t aWandererA = 0xD58A55795500E54CULL;
    std::uint64_t aWandererB = 0xF52B3458F47E5AD3ULL;
    std::uint64_t aWandererC = 0xAF18BC667B9FD003ULL;
    std::uint64_t aWandererD = 0xF2E633290FFB71EBULL;
    std::uint64_t aWandererE = 0xE077103B169C3239ULL;
    std::uint64_t aWandererF = 0xBF37782FF0E2AF66ULL;
    std::uint64_t aWandererG = 0x8CAB5D00476C44E9ULL;
    std::uint64_t aWandererH = 0x883ADBFE2733F161ULL;
    std::uint64_t aWandererI = 0xA801D8478C62ABB0ULL;
    std::uint64_t aWandererJ = 0xAA72BE9B4229F88AULL;
    std::uint64_t aWandererK = 0xF985756E4E66E086ULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD, 1);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneB);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA, 3);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    TwistExpander_Rugby_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Rugby_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Rugby_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Rugby::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Rugby::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCFFE908B5EDF588EULL; std::uint64_t aIngress = 0x9BFE315EAD0EB05AULL; std::uint64_t aCarry = 0xC5F89067A24EF924ULL;

    std::uint64_t aWandererA = 0x81B956FB877E715FULL; std::uint64_t aWandererB = 0xD692C4109C8D1530ULL; std::uint64_t aWandererC = 0x927CBAA8020081C0ULL; std::uint64_t aWandererD = 0xE97E68F86F2D776DULL;
    std::uint64_t aWandererE = 0xA0265417ADFB76A6ULL; std::uint64_t aWandererF = 0xA7D4DE93490C2813ULL; std::uint64_t aWandererG = 0xE2656C2D19300DD3ULL; std::uint64_t aWandererH = 0xC0559C1FF16A8FDAULL;
    std::uint64_t aWandererI = 0xA00BA999433941F7ULL; std::uint64_t aWandererJ = 0xE12DF0FEA3ABB944ULL; std::uint64_t aWandererK = 0xC5398D34501CC04AULL;

    // [seed]
    {
        aPrevious = 10091282613984504821U;
        aCarry = 17720023385672851732U;
        aWandererA = 10040752810122307448U;
        aWandererB = 14018083950268612311U;
        aWandererC = 12304371349144147137U;
        aWandererD = 14085389117349236184U;
        aWandererE = 12570383435891246076U;
        aWandererF = 18270103374456430865U;
        aWandererG = 13116925560650742184U;
        aWandererH = 17057800081154728563U;
        aWandererI = 18438224442379607486U;
        aWandererJ = 16784750751782719038U;
        aWandererK = 17339371577790151716U;
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
    TwistExpander_Rugby_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Rugby_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Rugby_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Rugby::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 2, 0 with offsets 1176U, 5509U, 2894U, 2324U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1176U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5509U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2894U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2324U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 0, 3 with offsets 981U, 7412U, 7548U, 4500U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 981U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7412U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7548U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4500U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 3, 1 with offsets 2214U, 2895U, 7752U, 515U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2214U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2895U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7752U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 515U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 2 with offsets 202U, 3003U, 2289U, 2330U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 202U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3003U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2289U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2330U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 0, 1 with offsets 1081U, 1334U, 641U, 1222U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1081U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1334U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 641U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1222U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 1, 0, 2 with offsets 152U, 1142U, 1391U, 1287U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 152U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1142U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1391U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1287U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 1, 3, 0 with offsets 1630U, 1475U, 405U, 291U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1630U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 405U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 291U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 1, 0 with offsets 420U, 527U, 1574U, 891U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 420U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 527U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1574U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 891U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 287U, 283U, 1626U, 680U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 287U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 283U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1626U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 680U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Rugby::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 0 with offsets 5458U, 4130U, 111U, 4414U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5458U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4130U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 111U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4414U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 3, 1 with offsets 6901U, 5726U, 5519U, 6744U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6901U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5726U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5519U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6744U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 3 with offsets 3974U, 4707U, 3193U, 273U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3974U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4707U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3193U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 273U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 2, 2 with offsets 3319U, 1840U, 4475U, 2778U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3319U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1840U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4475U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2778U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 418U, 1007U, 7034U, 7266U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 418U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1007U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7034U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 7266U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1304U, 332U, 1069U, 890U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1304U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 332U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1069U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 890U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 640U, 324U, 214U, 1312U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 640U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 324U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 214U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1312U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 442U, 1777U, 1262U, 798U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 442U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1777U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1262U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 798U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 210U, 1175U, 375U, 1361U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 210U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1175U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 375U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1361U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 0, 2 [0..<W_KEY]
        // offsets: 1611U, 596U, 1477U, 141U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1611U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 596U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1477U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 141U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseASalts = {
    {
        {
            0x60B3F1F8E1E373A3ULL, 0x14D0360CBCD54777ULL, 0xC2A4FCA60955DB7CULL, 0x75E8005B9EFE1793ULL, 
            0x3F5F1A10CFE8304FULL, 0xB671EE355C386A8FULL, 0x14E75FCC0CE075DAULL, 0x8A52C3AAE1BD9387ULL, 
            0xB8AAA9E0D8546EBAULL, 0x1DB2B72FD533EE80ULL, 0x8A1848BDFF5233D7ULL, 0x6DABC571600E4BA8ULL, 
            0xB69D941A03BDB85CULL, 0xC3145707BC982EF8ULL, 0xFA394F948BAEA7ADULL, 0x48AB00649A76D486ULL, 
            0x54528F3B3F0D3432ULL, 0x39988511718A040AULL, 0x929C701386E3BFFAULL, 0x33D2B259ED3A49D6ULL, 
            0x9065624A3F4ABD15ULL, 0x9AF18D0174024CDEULL, 0x79A5D5BCE688A174ULL, 0xA16391C42C6493B2ULL, 
            0x4355AD14B44DB771ULL, 0x3ECDD7FEC902B823ULL, 0xDD8630796DCAEFBAULL, 0x8C49F4FD119D27C9ULL, 
            0xF4EB6B783B963743ULL, 0x26B206B254AB7AB7ULL, 0x35E98C062FE4823DULL, 0xE6F53465528DD03CULL
        },
        {
            0xCA38B8E6EC5E4367ULL, 0xED451B4282311169ULL, 0x5F9ED457FDC2FF58ULL, 0x22F0B9382CCB0D4FULL, 
            0x56045211C8B5FCFDULL, 0x3DE146C40E5AAF6DULL, 0x5D9B419075CBE199ULL, 0x6A10075B767E320CULL, 
            0x32A328AED2168D2AULL, 0x0F7C64DE038B20ADULL, 0x53FB32512C7F6B42ULL, 0x72306688AC9C35C0ULL, 
            0xD0BE9385045FED45ULL, 0x5466F2B9D7C9A841ULL, 0x432ED783CDEC039FULL, 0xBA9B3C4F2E43B9E6ULL, 
            0x4794213C729EC6D5ULL, 0xD05BB5483832394BULL, 0x87363A84AACFBCBBULL, 0x63F56F51CA0091BEULL, 
            0xE38C436FDD6FCC01ULL, 0x487B6160B0AE035BULL, 0x3D923AEB2B851921ULL, 0x9C464C3783EBD1E4ULL, 
            0x5B3F420081460755ULL, 0x8FE845C074520FA7ULL, 0xD2CAC9009534F2E9ULL, 0x6FA36D51556BD81DULL, 
            0xF90B28725444F423ULL, 0x2BAE8BE9B16C8B44ULL, 0x9972BD8CDA221C13ULL, 0x3EB2ADE9C83E7F42ULL
        },
        {
            0xF33521164228134DULL, 0x924A8E50D65D15BCULL, 0x629360928CD62197ULL, 0x9C7B85926B2DB1B3ULL, 
            0x043A9B52C69E9ADEULL, 0xDF2C1064DB38BC03ULL, 0x1A2426E9C2B6BD68ULL, 0xCD39D0C44D206600ULL, 
            0x83CA3F36C0FC5062ULL, 0x382A752CFFA7E8E7ULL, 0x880721A2EE159B74ULL, 0xDF36DA4EE787B760ULL, 
            0xFD6D9279681D8C28ULL, 0x9E97960909FE4630ULL, 0xF5BBE823DB01727EULL, 0xB3E6417E8D6CE9C6ULL, 
            0x0A8ADCB80EE5C343ULL, 0x9BB8CAAAD56D13E2ULL, 0x01E6B271D9FD8701ULL, 0x0F07821EF85174BFULL, 
            0x5B573114B16D9447ULL, 0x3E4FB34002BA3F88ULL, 0x8DC650051ED71A8AULL, 0x2FDA591339DE4951ULL, 
            0x0E66DE3E1ED26509ULL, 0xB7E36243C7C21247ULL, 0xFB35681EB2CDB6D9ULL, 0x4783DF669D1FE6E5ULL, 
            0x3F5D468B95B092FEULL, 0x3FB161DF744BACB1ULL, 0x506749B5C13DA10FULL, 0x2EFE091215092625ULL
        },
        {
            0x2ACF82DD7469464FULL, 0xEC060F0DA6D94A9BULL, 0x8F4C3A0D92CB52E2ULL, 0x86BD84CA59405F02ULL, 
            0x8164A7B3C544B899ULL, 0x030A3EB81987B964ULL, 0x24FFA2603DB83ABAULL, 0x087BA4EBFF82B650ULL, 
            0xEC1A2B288D443620ULL, 0xE88047347E81813BULL, 0x6219DB61F7088D9FULL, 0x75CA8ED354E246B5ULL, 
            0xA1FFB5C2EA3AAAC9ULL, 0x3F96EF49F7095C18ULL, 0x8B036CB5A24AD5B0ULL, 0x16230AD5B97D9D3EULL, 
            0xD2195216A546DD97ULL, 0x7B230A9D5CD5D5E6ULL, 0xDB2C731A8B8631BCULL, 0x2852157B729928B6ULL, 
            0xC8A16AEEE3C70701ULL, 0x1F684A8364F22D8BULL, 0xCF8786FC62135D58ULL, 0xFA9CA84B8E2C36BAULL, 
            0xB88B86F761D08577ULL, 0xEAAC9F85F3D7E3A7ULL, 0x63D26A6878348983ULL, 0xEBB5E2C5E76503EAULL, 
            0xA057B96B4038B5D1ULL, 0xA74C6763FCF58630ULL, 0xE91DFAE0D7B60E32ULL, 0xB0A58EE064BB8DE0ULL
        },
        {
            0x68829485EE8A5409ULL, 0x0697A9815F024A3DULL, 0x4A00BC7EA0BA950AULL, 0x985981C343B0EEDDULL, 
            0xB178C9EB25A63938ULL, 0x2E93B6D68E54750FULL, 0x63B028EFFE41AED2ULL, 0x88E308425D7F7DEAULL, 
            0x69D389B791E33DCBULL, 0x7848BDB4E64C92D8ULL, 0x2C3BE1A624C87BDEULL, 0xA256AD932681D5D9ULL, 
            0x6C799FF8370E91EBULL, 0x3F631631B2BF186FULL, 0x701A1EF557BB1F02ULL, 0x75E9A260C10F11E4ULL, 
            0x3B8E1FC9D0D1562DULL, 0x27075705F2758BB8ULL, 0x0A0637664E58E33CULL, 0x25383795124950EDULL, 
            0x19822D22A60E8440ULL, 0xD08D0BE358F3160DULL, 0x2E3C8790D6CBA871ULL, 0x480770CCDDA4ED74ULL, 
            0x39986CA32F946B70ULL, 0x2CAA1FB470BAA827ULL, 0xBE56FA5238BDE549ULL, 0xBDADFCF76777B47CULL, 
            0x14DE0A5BDDAB2E9AULL, 0x5C4CC116F0EA6684ULL, 0x236E5BFF907AC13CULL, 0xC2EFE43FD6084D12ULL
        },
        {
            0xB9F1C16403C732DEULL, 0x68A05FF566212887ULL, 0x90AEA5D832DF6A8AULL, 0xAD0952C687F5F21FULL, 
            0x4B8680A4C8591287ULL, 0x8E352CF809F5A7C2ULL, 0x54552D6E6F7F8920ULL, 0x0FFF38B7C2F10478ULL, 
            0xCB04FA7B7DB08084ULL, 0xDF773BA1D7F94985ULL, 0x8D2E1550900D7742ULL, 0x0D66E06BBC50CB1DULL, 
            0x1317D62F895F4214ULL, 0x29670FEA74AA2FA5ULL, 0x7EB950DF91D8562CULL, 0x45AEAD370C60B6B1ULL, 
            0xA7374F82C87628A5ULL, 0x1715CF8092498B29ULL, 0x99DD94A87EACAFC1ULL, 0xA18C1527D609EB77ULL, 
            0x23915344F483B60DULL, 0xDEB8709F6C44A4F7ULL, 0xF15A9BC09A34908CULL, 0x7FE3AD2D22769A1BULL, 
            0x84EEDB3C6B281F11ULL, 0x5F3EA480272DC56EULL, 0xF5481C604D6C38CCULL, 0xE2FA780A4DF921ACULL, 
            0x8DE4199D72CB58C3ULL, 0xC1A3E21074AB04D9ULL, 0xBB21FF6D1004F43BULL, 0xD79E5C0B6B987B9FULL
        }
    },
    {
        {
            0x8D2BDAEDCD7A17BDULL, 0xBA95DF220F12E1DBULL, 0xBB30B997E15C12B6ULL, 0x976AFE47EF41CCA1ULL, 
            0x923C3084B47844E2ULL, 0x7BE8FFDFF69D17DCULL, 0xF09E183D655826F5ULL, 0x94935CE1C67AE108ULL, 
            0x33BEDC24830848A9ULL, 0xF1010D8A753F253FULL, 0xDA6727F88CEC79A5ULL, 0x0720C62BF0AD09E1ULL, 
            0xE4CEB100C475EA88ULL, 0x7DEDB9F05FD6584DULL, 0xD41C784B71FF26B0ULL, 0x72B50B3CA83622C0ULL, 
            0x3EF74A6120067BB2ULL, 0xBF8439EF1888EC8AULL, 0x8C8E49E9D3301C86ULL, 0x029BF96F991ACC21ULL, 
            0xA2B5D9ADC85E5371ULL, 0x9BF3A887BDE458BCULL, 0xB12A5A62878670A4ULL, 0xF7766A6185B79694ULL, 
            0xF46E6B7480B3B181ULL, 0x1D52330823F1A5BEULL, 0xEC793AACEEA7ACEAULL, 0x3743D7FEDDBB5E4DULL, 
            0xBDBEB41F9D65835AULL, 0xD775E83EE98E802AULL, 0xC08B618D90025B6FULL, 0x29CDA0898B9DD8EDULL
        },
        {
            0x6759C279E254B870ULL, 0x40BDC42728A3AB6DULL, 0xD9852F4E8260942AULL, 0x7666E8B08E85A776ULL, 
            0x9160A2F50096ABB0ULL, 0x6CF10077D7D0E1F7ULL, 0x265647790ABC94C7ULL, 0xA46FCC075A495BEAULL, 
            0xFCB90CB87A9B38D5ULL, 0x94DDFF17D3C6E3DAULL, 0xCDD1544F6735D721ULL, 0x51472891899AD33BULL, 
            0x9AFFE3098C7CE1A6ULL, 0x720A5DF640263718ULL, 0xEC9201EFC63EFA8AULL, 0xA77346F4CCC46D1BULL, 
            0xC84EDCB96A22BFA1ULL, 0x42D41B848289A57CULL, 0x29CE352353C6CB77ULL, 0xA34A689CC2224C5FULL, 
            0x28CC9970E46ABD07ULL, 0xB70CE4D5531A9FF2ULL, 0x1819D81982BDDDD4ULL, 0x199141E09AF3EC6AULL, 
            0xED4C718E7F6A1E72ULL, 0xC2DA8B67132D7A9BULL, 0x6E267F28C6CE4237ULL, 0xB6163A40CCE0A718ULL, 
            0x6ADCB8C6AAA92EF4ULL, 0x3E713EECDD5B293AULL, 0xA982CD3725005A22ULL, 0xD671001022559564ULL
        },
        {
            0x67E56BE4FB29AB8AULL, 0x26E2FFC53C3382B1ULL, 0x41415C89C80CBB18ULL, 0xF97854312F11C1B3ULL, 
            0xA936B2FF39184858ULL, 0x5DB74480CF9DB510ULL, 0xE111B047FEB5AE00ULL, 0xF61A654442DED802ULL, 
            0x5B4877F286E2DED3ULL, 0x19AB9D020A280256ULL, 0x3CAE3600779C5074ULL, 0x0D2664F60DD21CD8ULL, 
            0x9793B0F1BA749201ULL, 0xB3391ECC8B80E1F8ULL, 0x084735F8B5D5C543ULL, 0x4A9EDB7705ED23ACULL, 
            0xF7AEE321E23575C1ULL, 0x3F5E79CE8E1389EDULL, 0xAF1B8FABC2BC4DEDULL, 0x7C0858D992CA519AULL, 
            0x752E817EC353BC4CULL, 0x82F8B19546D7A62EULL, 0x9907636A81D953A7ULL, 0x99FC7B5DBE4D32A3ULL, 
            0x60CD96ECAE17F561ULL, 0xF728E53FAB44FD4CULL, 0xF7FE58DA5705D311ULL, 0x138C27B02ABFAB97ULL, 
            0x8A15901777682C11ULL, 0xF09D44189E1502E5ULL, 0x6D4FA489FD834A88ULL, 0x69E95122B3CD0EBDULL
        },
        {
            0x5CA38D5DB7748E56ULL, 0xB41A4DEE7185C0DEULL, 0xB4A3550B56589C19ULL, 0x32648689D42B789BULL, 
            0xFC35E24C9BD0B62EULL, 0x4EF7195E396D92B2ULL, 0xE506165E0A8C929DULL, 0xE77D93787B15A8F5ULL, 
            0x455E980E9124ECB2ULL, 0xFC89361B85AEFD32ULL, 0xBC4354CF30068905ULL, 0xA958F6239C54A111ULL, 
            0x2E87FA11038B3B78ULL, 0x16E7ED7BFDB1A21CULL, 0xA9F4055C757E5A71ULL, 0x2EFEE3DAFE09020BULL, 
            0xC21D89975AA6D2DEULL, 0x906AA55FDEF03F52ULL, 0xAB12D3F6DD37D8EAULL, 0x1C1CFF43BF23A40AULL, 
            0x3817F49308E610CAULL, 0x578B4667B21D3D83ULL, 0x53B99686824DB712ULL, 0xAD5652A2C904B356ULL, 
            0x98ECFA2EC35E8A36ULL, 0x0AE1508925F95102ULL, 0x22938AC3BB3D0735ULL, 0xBBD86EEC1CA9DBDFULL, 
            0x4A7CE1675FAD2BD8ULL, 0x857AED83502DA2DFULL, 0xD6C1BEFDB6A89938ULL, 0x23CDB1AE2C63D468ULL
        },
        {
            0xA54D196A21D8D628ULL, 0xF3DA158682A5859CULL, 0x65213AC1C4631F07ULL, 0x8A514418A51EEC63ULL, 
            0x1BEA4405A9BDF96FULL, 0x3953CD7901BE4A21ULL, 0xA0EAFCF3A3A948F1ULL, 0x3C759C3A9766844DULL, 
            0xDED966A95E8BC558ULL, 0xFA6E3D19752F0473ULL, 0x0E19AB94233BE36AULL, 0xEB814C881CA67982ULL, 
            0xFEAFE0CAAE8EDBDBULL, 0x7E3BED5086519214ULL, 0x448CA1C44C021570ULL, 0xD8EA8C7B96C8364FULL, 
            0xF4738AF457C018D6ULL, 0xCD6AEF75F49D2CB9ULL, 0x8CA91B9A40B1714EULL, 0xB3E24E03D27FA10AULL, 
            0xE8ACCD6C9CE7862DULL, 0x33265AA7B3A5B559ULL, 0xBD7772B7E802E9E1ULL, 0xBAA528677E99A7FCULL, 
            0xFF71B20264DA8187ULL, 0x8BB6E393248651DDULL, 0xB8035C4AA461CE1CULL, 0x66BFD634C1A23AA9ULL, 
            0x98532DDE9C4C7C55ULL, 0xD4A33686A41B2296ULL, 0xCACD8C790511B51CULL, 0x19ABF8FD0338A271ULL
        },
        {
            0x5AF76671FDB665BEULL, 0xF55A22E7670A0331ULL, 0x21F3B55425DC3A15ULL, 0x080B57ED1B6060C1ULL, 
            0x049387A7F35F3AA6ULL, 0xADD94CA4CB491919ULL, 0x0EBFF41F071E1CCFULL, 0x047D2764F02FEEA2ULL, 
            0x77E825D2C6749869ULL, 0x796E9494DD141AF1ULL, 0xF6D6EA4910EEAC24ULL, 0x1C2E1BFBE45329BCULL, 
            0xB97516A0789C635CULL, 0x82E4200FC8BD39C5ULL, 0x10889B47CD13AEDEULL, 0xF9F9C54A864AE235ULL, 
            0x7AEB71CBC4EB28D1ULL, 0xE76A12D5ED952CB3ULL, 0xB5C724F09A4E6864ULL, 0xC5594318D9A1307AULL, 
            0xC939E9F29CBB9615ULL, 0x1CD00905C23FC286ULL, 0x8283F4421BA2983DULL, 0x326CA9E7D92D7A02ULL, 
            0x13E100DB170DCF5FULL, 0x91A25224DBFC3693ULL, 0xB33E66BB04C03F25ULL, 0x6059D17BAE3E5092ULL, 
            0x14B5AD4897DFF5FCULL, 0xB0CD30F268204CD4ULL, 0x6B1AA39E4B3DCBA1ULL, 0x61D64FB3D1CA2D6EULL
        }
    },
    {
        {
            0x5981650C12549215ULL, 0x20DA09A7ACEC9D1CULL, 0xD3D39F96F5AF0347ULL, 0xA34EDA3279E23656ULL, 
            0x0F88821D96463107ULL, 0xF198C4ED5553D429ULL, 0x5ED20AD1431F61FBULL, 0x70A8A523E3CFD737ULL, 
            0xFC0A5744F6B18BC8ULL, 0xA1CCE44CC7C8A090ULL, 0xEF37F32994763A99ULL, 0x24D14759656C68D2ULL, 
            0xAB8FBB3935527625ULL, 0x3AEC87B8DBB99FFFULL, 0xA6376CD12CDA8BCCULL, 0x34E5716912664AB2ULL, 
            0x65138B2464CBEE6CULL, 0xABEF07C5A6BA2F81ULL, 0x68B33261607F3C83ULL, 0xA1901870E0445502ULL, 
            0x38B73AA50A5136B6ULL, 0xA8F93955D158DC66ULL, 0x1A4753C49E751F70ULL, 0x7BB8C1C079D9651FULL, 
            0x810A936FDE7084E9ULL, 0xBE53D364E3297F46ULL, 0xAB404132182D0D49ULL, 0xF9E00F8A393E1DCDULL, 
            0xADA6EFBD7C84BA6BULL, 0x533BB5B7B4214EBBULL, 0xD90C0620A17B994EULL, 0xFC0AB31490B23BA2ULL
        },
        {
            0x0C1512F50EF0EA5BULL, 0xF2FF88855011056DULL, 0x98879576BE94C725ULL, 0xE9B9C1AF9FB3A1C3ULL, 
            0xE7965EE5825B0904ULL, 0xDF0B99547B67A92AULL, 0x0377D9B048CC91E5ULL, 0xDF9F9A779C17F47BULL, 
            0xF89B2F8AC811053EULL, 0x6977618779D91CC0ULL, 0xFFB95D049F31454AULL, 0xF32E9DC9B833F604ULL, 
            0x7F3CD8D554A6795BULL, 0x6C9B19094CA149BBULL, 0xDCE959A95582DEE5ULL, 0xC048A9AA90129A2AULL, 
            0x9C6867B72C95A552ULL, 0xE509C61EE701F71AULL, 0xE7DF3A8498B4E9A0ULL, 0xD1DE88DE84484E76ULL, 
            0x233F321F97056973ULL, 0x8C29CF3CF0007A74ULL, 0x62947FD5F704AB3DULL, 0x1707CF598D8ADEF6ULL, 
            0x35610C08DF615C8AULL, 0x5CC7FB0F804CB930ULL, 0x9B5F06FC82D6553EULL, 0xF1DB426A5B0BEF91ULL, 
            0x9241FC22BDFDA32BULL, 0x07A801F8FE93113BULL, 0xA6A9E7E6DECF07EDULL, 0xF907B48DB0DDE9D6ULL
        },
        {
            0x4B0961CBDFE6A26AULL, 0x6716C811551740FCULL, 0x9D288D4DAB56B257ULL, 0x8E2F05F37E4FA8CCULL, 
            0x2DB3A9DF2281DDF0ULL, 0xF0B7DA38E7CFE230ULL, 0xED0097A7AEC593A0ULL, 0xB504588856FBA667ULL, 
            0xDEAE210ADA5400AEULL, 0x3A1D5CE362AD2649ULL, 0x779493F001324C3FULL, 0xC90B45F304A29280ULL, 
            0x0AF9379BAF469860ULL, 0x98F4082ED0CA9D91ULL, 0x54C80EAD340EAC7CULL, 0x5B76FAB97E02CF51ULL, 
            0xADEEE51B5AAFCE3AULL, 0xFC663AF9F5EEE0D5ULL, 0xEB4F90D99BCD349BULL, 0x9748024CA849F387ULL, 
            0x013ECC3166855B19ULL, 0x6645181E4F2A80B3ULL, 0x0A22FE759F7904FAULL, 0xFE5BE304AA35F3B1ULL, 
            0x0BBA36C77EA936ADULL, 0xEA26EF9F58879916ULL, 0x5FA251806AD0ACDFULL, 0x46C72F452D759B82ULL, 
            0x8C72C589A3634D6CULL, 0x9678DAC70D03BEF4ULL, 0x6E1DB10D102E0445ULL, 0xC6D0894C8CB80C48ULL
        },
        {
            0x9D4F5655D954FA17ULL, 0x8940CD8B72C8A5D4ULL, 0x56E87D77D25CC40EULL, 0xBA47FE4F3E8CB44BULL, 
            0x3B830F0B3E78CBCDULL, 0x23557DF966CFA09DULL, 0x83CCC328C3260740ULL, 0x6C70F4C150AF5254ULL, 
            0x8B4898190B1123C1ULL, 0x30AD54EC2FE7BF9AULL, 0xD5AC5B02EC277049ULL, 0xADEEF27E7EAEC1F4ULL, 
            0xBAFA391C80881FAFULL, 0x13ED8C4FFAFA4FA9ULL, 0xE72504F46F3842A9ULL, 0x4F1341C7F2D8DD4FULL, 
            0xE6C1187316370ABAULL, 0x12DAADE8C0AEFDDFULL, 0x1ED5F4B0E0CEC4D6ULL, 0x8F2421C6728D6407ULL, 
            0xA1C4CCEC93E4FDF0ULL, 0xFFB05275466FEFC7ULL, 0x0A49E58F0ECDEDC4ULL, 0x006853737A01A422ULL, 
            0xAE07E592AE4FC154ULL, 0x340AAC3EAE03853DULL, 0xB6F578DA62F4156DULL, 0xB33C48678D556B0AULL, 
            0x42B6B53AFE621F14ULL, 0x22CA3E8423E4CBDEULL, 0xB2CEAEB55F95FBB6ULL, 0x4BC57EB7ED3351F4ULL
        },
        {
            0xB38426784743245DULL, 0xCCCF2E124766987DULL, 0x6850908046DE3084ULL, 0x4010C511EF8B5C3EULL, 
            0x86536601874B41D3ULL, 0x7DC5776F6BA1C1ECULL, 0xDF7CED760EEC06B7ULL, 0xBB7B94132FAF0563ULL, 
            0x0AAA814FFFD97397ULL, 0x7FB665B6E2CF7C5BULL, 0x140B0AFC6CB4ADAAULL, 0x72787C916D1803A9ULL, 
            0x14B2EA5441588A53ULL, 0xD35F647BFB79E7ACULL, 0xFB38F0D65532FEC9ULL, 0xB3315787B1A7D513ULL, 
            0xD38F01998BB887B8ULL, 0xF49FD400A09A2959ULL, 0x9E3AF2418DCB017BULL, 0x9DA5F6619F71F3A3ULL, 
            0xAEE32ED3DDEA73A0ULL, 0x0564F0DE6CECCDEAULL, 0x43CEA81CFC5CA800ULL, 0xB1B417188F820890ULL, 
            0x93B4E3A4B8DAC3C1ULL, 0xD9A801EFFE3E2F9AULL, 0x379113043114EA88ULL, 0xD0D5C8479B7517C5ULL, 
            0xD9F4B5F4B16B8560ULL, 0x261598F29DA53609ULL, 0x04B03DDD00D642FDULL, 0x8C85671CEDBD4E63ULL
        },
        {
            0x4D46AA24AE623AFDULL, 0x218E4386A949522DULL, 0x32170CB07421F648ULL, 0x2B3DD60BB181360BULL, 
            0xDD9B662DD1F894E2ULL, 0x4CFAAB9F702BEE56ULL, 0x5E0CF6A8EBDA486EULL, 0x7418DB03F9C08CCDULL, 
            0x59FBD307ED694A60ULL, 0xB344291BB8C67F50ULL, 0xDC5FFD5825BD5786ULL, 0x09D3DB9ACD89FC09ULL, 
            0x84B935B71E6E166AULL, 0xDB74EE5E40AD46F2ULL, 0x4195558F80F0D3FFULL, 0x67B2EFAA32E588D3ULL, 
            0x2C7F8F64E3C3CEC9ULL, 0x5A728FA9CCAB9D0FULL, 0xFF9737D2CDDBBFBFULL, 0x42CC586142E2D48EULL, 
            0x840CF57B41C4FC3CULL, 0x385509757953D72BULL, 0xA73B7F22F2184191ULL, 0x1265C01C3A0CCBB5ULL, 
            0xE71087480364DF02ULL, 0x6874CB022744403AULL, 0x52250711CFB05279ULL, 0x614236909DCD52FCULL, 
            0xAF256D53C415E19BULL, 0xBA2B7AFDF24F35EBULL, 0xBE9AE9F5949AF0FAULL, 0xEBA8F9EDE9E6E726ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseAConstants = {
    0x5FB0C3EED956DD1AULL,
    0x7B17AB3660A29A0FULL,
    0x4516D8531EBB7A87ULL,
    0x5FB0C3EED956DD1AULL,
    0x7B17AB3660A29A0FULL,
    0x4516D8531EBB7A87ULL,
    0xDF4A300F005DFDF3ULL,
    0x3812E321E0931780ULL,
    0x4A,
    0x45,
    0xCD,
    0xA8,
    0xE2,
    0xC4,
    0xDB,
    0xA9
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseBSalts = {
    {
        {
            0x0F278CBFE47FE736ULL, 0x19075F8972CDF054ULL, 0xE4FE5793884452D2ULL, 0xE352A1CF4A60DEC6ULL, 
            0x3CD8DD7939B82F65ULL, 0xFC1D5726C9F41EC2ULL, 0x0218B4DD3C3878CAULL, 0x093C24AE2412AF0EULL, 
            0xB6EE9948AE8EFF73ULL, 0x1457A5793616F150ULL, 0xDDE9CE3E61787B2DULL, 0xBBDB3400B6678DC5ULL, 
            0x03FB5EFE86C6084AULL, 0xCCFA0BEAE98965E6ULL, 0x4CE5DB890909AF7EULL, 0xCCFD41D1073061B6ULL, 
            0x547488761BBD1484ULL, 0xDB20DBC27F344086ULL, 0x949AC88B71D3DF4FULL, 0x30418FECBBFD4FD9ULL, 
            0xE37163F3BA5663B3ULL, 0xEBE3ED8A2A6DB817ULL, 0xA23608CC3204ED19ULL, 0x23CA82A2A8844A37ULL, 
            0x2AF8C84565CC8257ULL, 0x58DFF77BC6E55FA5ULL, 0xC915701E69CD37DEULL, 0x4AC44B78F3621C75ULL, 
            0x493F7B4845A83F0CULL, 0x924F0FF2D967B85FULL, 0x514D16EF862B015BULL, 0x7855538EBAFBA3BAULL
        },
        {
            0xDF6B86B5F39171FFULL, 0x31D8A4D905C6F0E3ULL, 0xA5CD1EDE026A3761ULL, 0x34FD7CAD4BE2EAB0ULL, 
            0xCFBC0A50B43FDB59ULL, 0xAE45B6FA25B993FFULL, 0xC7714628F1D7157FULL, 0x83ECCA762D20712AULL, 
            0x9A64D196963A1FE8ULL, 0xEF42A1650AC63D72ULL, 0xAD42F87410787264ULL, 0xB0D82579C618057AULL, 
            0xFE67BB517CCCAF62ULL, 0x8F1E5484A1DEB20BULL, 0xD6672A33007D5A9EULL, 0x09058AFAE4A18589ULL, 
            0xE70AD22FCD34F299ULL, 0x7C3E78E58F9389F8ULL, 0x716A8ABDFAC51F24ULL, 0x90E9B14CCAF1F63DULL, 
            0xCC580F55A0376256ULL, 0x8CE1533B5992B319ULL, 0x96AA6F402E33B8B4ULL, 0xFAF8A6B5D683ADE9ULL, 
            0xB81FB235D50151DEULL, 0x3603E03032C1FC71ULL, 0x19DA4007ECF909F2ULL, 0x96C647E7A244C20FULL, 
            0x015AEEA37340817EULL, 0x1442F08A2F0E27D0ULL, 0xD4FCD9D828FED113ULL, 0x92A6C50C15E15EEFULL
        },
        {
            0x9974E5ED7366A1C4ULL, 0xFD547753077F8B02ULL, 0xBCFA29A5F1E236EFULL, 0x3A6430947D9DB5ABULL, 
            0x52B93794BC952C28ULL, 0x77CF33DC09B60654ULL, 0x24C502889CA0DEFAULL, 0x001BD43460D8A45FULL, 
            0x96F7D4967177F90AULL, 0x6E51BC7505D93A85ULL, 0x474F98CBD857A0B9ULL, 0xA7B7054AA322540BULL, 
            0x7FE5A6E10DB55EA9ULL, 0xDE8B62C9BF5A8F37ULL, 0x7C15019AB0A9C529ULL, 0xCBE151C99B6E541CULL, 
            0x97992E5BB4F8B1A7ULL, 0xBC44658EA8070C01ULL, 0x1B032C013ECBAABBULL, 0xE7FEEE391849F8D5ULL, 
            0xBB1687A774A45CD7ULL, 0x808C7910F25A2A41ULL, 0xF43B13A4E6F3AD0AULL, 0x44D56A9C1EC64879ULL, 
            0x0C917EA4D149F203ULL, 0x85EB5AF399C1880EULL, 0x3502AA86BD3BA533ULL, 0xE0256DA2BCBC657BULL, 
            0xAF7662B3070B12D3ULL, 0xBD37F69CBCC5FC00ULL, 0x94E57F39CE31C326ULL, 0x52EC9748A263E1F8ULL
        },
        {
            0x7F7AD916819A71F0ULL, 0x9B13AA46163B9E9CULL, 0xC0A389F7DB18E197ULL, 0x874662022D56C849ULL, 
            0xF6E828AD1BAB08D6ULL, 0xC397E93914E0727EULL, 0xA4F36E2289ADD1E4ULL, 0xB82BEC76570BB976ULL, 
            0xF6827585FE2DB805ULL, 0x04EE51F9D587DD3AULL, 0xE2C81C65CD757B43ULL, 0x18DDBB14C898079EULL, 
            0x26926812C0C34507ULL, 0xE14CC5896B608E9AULL, 0xAF54E64877527AC9ULL, 0x8715116F6FC2C350ULL, 
            0x1281D3E08B501536ULL, 0x783F74D791F874A1ULL, 0x09E8AE305FF7E3ECULL, 0xC058AED10A306D54ULL, 
            0x94030967F339D4CDULL, 0xD0F89DDBCA4EA443ULL, 0x8D3FDCE2DB7C1C35ULL, 0xFB6950F89F0E200CULL, 
            0xEA937F4FD8C5024EULL, 0x3F1D763AC6AD60BFULL, 0x41F2BAB98065AC78ULL, 0x37EEB558AD8FF42BULL, 
            0x9EC2513C850967FFULL, 0xFDAAF09EE9129DE0ULL, 0x38EBAFCA9434677EULL, 0x0C72DA7FC3AC6449ULL
        },
        {
            0xDC3E68773690149DULL, 0x91E0198009E67E28ULL, 0x6C03CCDA3B309571ULL, 0x2711A59D0FC0F0B6ULL, 
            0xD2AE29B0E2F77557ULL, 0xFCDDD5D72A2F8A56ULL, 0x6BA211630A5DA65CULL, 0x98C558FADA05F008ULL, 
            0x36403197C8C21AD3ULL, 0xEA88DEB36F785714ULL, 0x3843CF5523DBAD8BULL, 0x9D9665A621E7F489ULL, 
            0x643BD82923A9FF68ULL, 0xBD843B72E593FCFEULL, 0xBC533CDB310501D7ULL, 0x90CB9655A6FFF322ULL, 
            0xF42099F1525A74B5ULL, 0x58CC6A4D9E91285EULL, 0x2FFBDCE18B935346ULL, 0x3EC89D8647641663ULL, 
            0x8A8E070BD898AB5BULL, 0x0A220F086704E0A0ULL, 0xEAB105C57BC97197ULL, 0x7DF37E68BEE45296ULL, 
            0xFC7782730D2C189DULL, 0x4C0864037EB28582ULL, 0x99CC6C630BB89C66ULL, 0xD6A9E2DD766BD52AULL, 
            0xDD59712A4A6CAF6AULL, 0xE4C882D172DB9363ULL, 0x0D2251BB2942DDC9ULL, 0x9AA57D8BA6E96508ULL
        },
        {
            0x61E609496980BF60ULL, 0x66891140F5654D83ULL, 0x93B8D871693D6215ULL, 0xA31B1F1D61670EC8ULL, 
            0x3E0CCB57C39ECCEDULL, 0x03B368656306DB20ULL, 0x0D9520FA1F354BA1ULL, 0x8A9399E377CEE465ULL, 
            0x5435744F834CA9C0ULL, 0x0D6BCD0E6836930BULL, 0xDEEB1CC23E84107EULL, 0x35B056BFD1D442A6ULL, 
            0x9F919B5749D9B36BULL, 0x20763227322B1540ULL, 0x1429C8B6E5043EDAULL, 0xD0F798B8DACD9355ULL, 
            0x3AEC06EE818915A4ULL, 0xEEECC62F3A80DFDEULL, 0x404D9EFD9D6760F6ULL, 0xA76459D0390EF904ULL, 
            0x8F8A913792524CABULL, 0x7BFAD70A8EFB559CULL, 0xFAFC0443A4CF055DULL, 0x48A396A7D5D483B1ULL, 
            0xBFDC6CFC5C5C2EE9ULL, 0xB7BABF226F30ED1DULL, 0xEF48FB253A38B166ULL, 0x76098B01516662D7ULL, 
            0xD1F0B81C6473E500ULL, 0x1F1114C211D545AFULL, 0x619A907558BC2130ULL, 0xC677B083993CE1C0ULL
        }
    },
    {
        {
            0xF5BA2BBFEC86EBDBULL, 0xCEBF2C0A5985E41DULL, 0x25B0F652EF195D58ULL, 0xF2327FFDFBD64C2BULL, 
            0xE61EDB8E36676B96ULL, 0xEF70A83F0705606DULL, 0x09E533542CD0D43FULL, 0x504C74766A29FFFDULL, 
            0x646C251FA95F20A1ULL, 0x1D4EDB84840B7434ULL, 0x774D88F967953363ULL, 0x33D819E496C1FE22ULL, 
            0x9C93BA548366AA48ULL, 0xE3BF1B345ED5D6B7ULL, 0xC7B5A134DB3790D4ULL, 0x55B7F6D41F98D85DULL, 
            0xA5273F894F6B8930ULL, 0x3455B5C76710E641ULL, 0x4CF361ECB6974052ULL, 0x1B0D5A5077A0B955ULL, 
            0xB1CF153FDB9F52E5ULL, 0xA9054B64DC9B5A11ULL, 0x939B96002A0CB2C3ULL, 0xB2059BD3D5170EE1ULL, 
            0x40ED1E3CF5AF09BFULL, 0x07C9DC3BA0671AFAULL, 0xDB8076F255E1CF76ULL, 0x17210255CE06855EULL, 
            0x2FD5F982C43DF378ULL, 0x9F2AE48EC37C9479ULL, 0xAF5D71AE7C52874FULL, 0x8D453EAF542918C1ULL
        },
        {
            0x46857EDA996CFA36ULL, 0x4111D6BA68DFA295ULL, 0x955353BAF6B00CF5ULL, 0x70C097CA824D0696ULL, 
            0xF341FCB21A8FD8D7ULL, 0xAC1EA0FAB5F7A7C7ULL, 0x2A36863F3137D5B5ULL, 0x005A8F4083FA223FULL, 
            0x0AF1C9E447CE9312ULL, 0x9B562B94CAC31D4FULL, 0xAE09A0E1129AA7ACULL, 0x49BED844A06A813FULL, 
            0x844DE50BD35F41D5ULL, 0xF090019B66772003ULL, 0x7A308D476B134C8BULL, 0x0C9E8445CAF67809ULL, 
            0xEFDDFAEDE0825A00ULL, 0xE33C0380ADE9401FULL, 0xBC9D0E35ABE52F76ULL, 0xE21BE5CE39A4CEA3ULL, 
            0x670935004A3CF7EDULL, 0x62F6F425ABF0E29FULL, 0xF87AA5D042946788ULL, 0xAA4DB0287A84893EULL, 
            0xBAF07BFE35D6BD92ULL, 0x88B467931EBDF63DULL, 0xF8BC89254DD9F8FEULL, 0xE35C358A5723830DULL, 
            0xC234AFCCC072C03DULL, 0xB96ED870F3EBCADEULL, 0xCAECBB38C20E579EULL, 0xB800BC6F8F2E3804ULL
        },
        {
            0x5326FFAC3F6CBB32ULL, 0x45BDC56FACEF22D4ULL, 0x130E5E6B130B7D5CULL, 0x155C5EB97C65C56EULL, 
            0xCA3982DF8C9A44CEULL, 0x6F9A69963A581F5BULL, 0xF49A08DD5F5B3F56ULL, 0x37F937D7D9E91678ULL, 
            0xCD0BDE71ED91F788ULL, 0xD6E9E95930E6AFA2ULL, 0xE0834E553A382321ULL, 0x765160430C47AACFULL, 
            0x7447E6D97F6D365FULL, 0xFE9707B802D89E73ULL, 0x0BCF6D8EEF7B0D20ULL, 0xE92B3300152F7F58ULL, 
            0xDEA53AEA07BD6968ULL, 0xE14A7B83C2CBED32ULL, 0x2339F8B4E7883C20ULL, 0x7F70C11941A44538ULL, 
            0x10B32DC361CE6817ULL, 0x72BD12F5F3480043ULL, 0xD38E91B8513F28D9ULL, 0x731F2ED3CAA31AC4ULL, 
            0x2363CD722BEDF090ULL, 0x07520F5FEA93D0D7ULL, 0x141A1ACA2FED1BFAULL, 0x2C3E0A7101AE86AAULL, 
            0xA2F9810643DE337EULL, 0x7A0139AAB99F4FA9ULL, 0x32D6E4BD2D2EB505ULL, 0xCE409410F78094B0ULL
        },
        {
            0x58B3C3387D51519DULL, 0xD72F4D5E9AB249C9ULL, 0xD1CFCB4E10226E22ULL, 0x0D5810DEE9E16314ULL, 
            0x82DA0D55199C91FDULL, 0x8CA7B1A54C68C751ULL, 0x7F104D682A2A4223ULL, 0x74F7D5C28FEE3BCBULL, 
            0xA79200DBAD377AD9ULL, 0x4FA18F5C2E4D2871ULL, 0x73EE485E33E152FFULL, 0x75E3A065C36AAD06ULL, 
            0x082BF71418D30FF2ULL, 0x0FD0B0A00FF44397ULL, 0xC35BD4EE69AC66FBULL, 0x3430D69D19675532ULL, 
            0xD310D08B26D03FE7ULL, 0xDF79DEB4DB343EA3ULL, 0xF1601C654EEEE366ULL, 0x833F68DD1EAA8CCFULL, 
            0x3F99C7A2FD758F4CULL, 0x61E32B8C18EC52A6ULL, 0xC46D4B64C87A1629ULL, 0x0BBCE18A66B861B5ULL, 
            0xB6146E8D35A2CEC1ULL, 0x538C6A9DF4FD8919ULL, 0xE5DDE195D7176C68ULL, 0xB75E08A13AC55EA9ULL, 
            0xCB6F15DE8F51E505ULL, 0x9AF9910725F7D215ULL, 0x55665F2ADC4B5406ULL, 0xF4C6FC0A15D91F5EULL
        },
        {
            0x54A6AD2EC5AC64D6ULL, 0x8EBFECEBBA683AA3ULL, 0x061E96759E53821DULL, 0x8A07F1A1DF4A2694ULL, 
            0x0AA5BD427ACB0DF3ULL, 0x9EECE4D00C98FF89ULL, 0x8A10E6A6BA903D92ULL, 0x9D45A4D37CB9FF10ULL, 
            0xC0FE548DDCFA8C4CULL, 0x32F794BDE9825434ULL, 0x1AF7815724E8F759ULL, 0xF62520C991F14D49ULL, 
            0x808790DF93B1DE01ULL, 0x9A1E7E0005DBB464ULL, 0x235B09626D9FC9DFULL, 0x0A234BA12DFD8126ULL, 
            0x7CD6BF18C14995D6ULL, 0x19E59C35C72EB1CFULL, 0x76096DD8CD457ACEULL, 0x1688AF5A84B0620DULL, 
            0xCE385C537DBCA166ULL, 0xB6AABD0979C9D098ULL, 0x1E62F08E98101A45ULL, 0xC2169E1964183D28ULL, 
            0x9F3306E1EDAE8ACDULL, 0xB9141E47BBDD8F4FULL, 0x347A02446929C950ULL, 0x035570F17FD856E4ULL, 
            0xA8E27A7FA7731121ULL, 0x100396105762D707ULL, 0xC610A3A1DBD18AFCULL, 0x2B623EB13C814880ULL
        },
        {
            0xDDD7B85203CC2326ULL, 0xDF3188C0A252B6A9ULL, 0x7286F3A22310405BULL, 0xE8DA7AAABFB1C29BULL, 
            0xB33C7EFE6ADB7965ULL, 0x669C6D9CE36A289AULL, 0xB0E5160CA832DDF5ULL, 0xA7FB593F8EA80269ULL, 
            0xDE8774D0D20B03A8ULL, 0xD0F99F54AE1BC5A4ULL, 0x6B751C56121C2D92ULL, 0xB6A935AD9E21B0C3ULL, 
            0xF58A43DF99C1155BULL, 0x9243A140655E0376ULL, 0x6F29189AD0A72486ULL, 0x7F40E5B25079462BULL, 
            0xFFDD5FDD0AF255EFULL, 0xF7715D3366F02C26ULL, 0x76C9586941F3371EULL, 0x2FD5C6BA7CA9EA0AULL, 
            0x625D3D5E0C46E654ULL, 0xE2421327E8F650B4ULL, 0xC8A2329E0F43AC78ULL, 0xBA0F40E5FB56459AULL, 
            0xE86B3D10627B9400ULL, 0x8947F57C0231ABFBULL, 0xD9C1C4D5D115E960ULL, 0x16EF40A57D564DCBULL, 
            0x34D4BF4CAE1EFF6DULL, 0xD59796B446E877E4ULL, 0x8149A71BF017F95AULL, 0xE429843D3A3E0DD2ULL
        }
    },
    {
        {
            0x55F9B90C062DCDC2ULL, 0x5A29519B9621D7C5ULL, 0xAA70D4077A2A2888ULL, 0x6F49E609683D5EB8ULL, 
            0x5C77EC4D2898FED1ULL, 0x90010709D9CE9978ULL, 0x9AB334301E121F9CULL, 0x8E0FC8A7A14F605BULL, 
            0x18E672318C508098ULL, 0x237EF46A55D02D71ULL, 0x697E9A577535CEE8ULL, 0x0A5B6757C169CB56ULL, 
            0x97A57F1F2A520571ULL, 0x3BECE9F6504C1893ULL, 0x043996C4D6FB60AFULL, 0x8077415B12BE77BDULL, 
            0xE6CA9F939DFCA8ACULL, 0x4318472C61C22E0EULL, 0x017062AC3AA1A91CULL, 0xD92770B9484D2791ULL, 
            0x32B53D3B7A31C51DULL, 0xA00BEF0DCF070C14ULL, 0xFFD103AF53049E47ULL, 0xDA2081CAF6984F57ULL, 
            0x9A79E72BAA9CC005ULL, 0xD4FD07A625C3D9FDULL, 0x6E7107BAC52F3857ULL, 0x5B59DA8692970D61ULL, 
            0xB669A5A8EB6E4F6FULL, 0xDB98F459D1C11178ULL, 0x87B48D023C0A3210ULL, 0x3B4263BC45A68029ULL
        },
        {
            0x7ED39F4BFA63B7E7ULL, 0x5952707F56F6B90EULL, 0xC76402AAE14EAAEFULL, 0x66B70E54B9A11B9EULL, 
            0x03B22846F3A45E44ULL, 0xB3292B293D9C721EULL, 0xC54BE8EE52468D65ULL, 0x414BFED817954E79ULL, 
            0xFD32A258E8D0767EULL, 0x9EF6E22456A1150DULL, 0x2C3137C522FBDD17ULL, 0x9B11BA7913E8EA3EULL, 
            0x36E07AF2B0BE77F6ULL, 0x0F5AE00B5D4A3946ULL, 0xC5EDE82B33978826ULL, 0x4E5D7BA953C2B015ULL, 
            0xE87A8FC7497575C8ULL, 0x3CE66D2F4801E7FDULL, 0x19F39D4267789096ULL, 0x5A3C35109C5DD756ULL, 
            0x828B792774F5D298ULL, 0xF2A82F253F2FDFB4ULL, 0x3E54A4A06BC19509ULL, 0x71397F7F5F229F5CULL, 
            0x0CD93FBE0C42205BULL, 0xDF48FE215655ABA3ULL, 0x23D137884164D1BFULL, 0x4356D793D0408192ULL, 
            0x935BD06FADC6DF03ULL, 0x4E00AB9C24046C2CULL, 0x7B685BFE59810851ULL, 0xAF6C650F7003FEBDULL
        },
        {
            0x251C32F91C5FDC8CULL, 0xF20B1A5C78571724ULL, 0x8BA2C02F16F5A5F5ULL, 0x4A2550FD76D22A7FULL, 
            0x66AE770D912FD2F2ULL, 0xC01720CD049093E2ULL, 0xB25AB54836E9C596ULL, 0x32C6A579B1201BE2ULL, 
            0xB494E348E4B75860ULL, 0x5698680E0A728D45ULL, 0x9D483DAFDDD14BFDULL, 0x6BC42FB0B85CD060ULL, 
            0xADC5BFBB6425A681ULL, 0xFF8B8281830D5249ULL, 0x945495F530C06708ULL, 0x79F327CD6FC1E5CCULL, 
            0xA6EAE3026F163F75ULL, 0xF0B3CDFB9FD9F502ULL, 0x97D745444514FB7FULL, 0x48CDDF81497351E9ULL, 
            0x21F1728AFE5E3D3CULL, 0x1F56EA00361261CAULL, 0x36EC0C80B0DBCDF2ULL, 0xDF094791B4599C8AULL, 
            0x6505FEF1A5F11EE1ULL, 0x5625D89D7E6F2085ULL, 0x335B8D4E87E4830DULL, 0x5B0E0E199353C36FULL, 
            0xBCB62575C02386D1ULL, 0xD4130D82AAD119B1ULL, 0x1D1B6308B0A3B1D7ULL, 0xFF242F88374E7BAFULL
        },
        {
            0x798A0AF635E2B031ULL, 0x5BA48D836A16F475ULL, 0x1A0B0F85F6FD8404ULL, 0xB4B823C6247CABF5ULL, 
            0xEBB942F07FF732F5ULL, 0x3EB64B75F121E64FULL, 0x15F000AED13B6AEEULL, 0x9505B261FA566919ULL, 
            0xD916A077311F0ACDULL, 0x4DF700135569AC09ULL, 0x50166621708303F2ULL, 0x3641C583B7968C15ULL, 
            0x446F215C385B554BULL, 0xB78FD73BBEF18BD8ULL, 0x5A846A585E279156ULL, 0xD67EC384D44B930BULL, 
            0xB6F539786D455398ULL, 0x26ABD8FCD1CFCA49ULL, 0x0704DB02EF83C940ULL, 0x3F4B3F769AD63A31ULL, 
            0x2955B72E3DB01629ULL, 0xD5394BB14BDCB4EFULL, 0x770C828E37F23270ULL, 0x518603534E659A19ULL, 
            0x31A387CC1985BB56ULL, 0xEA3DEF3499666619ULL, 0x74803B3992571A1FULL, 0x5A7B35E89D1AF978ULL, 
            0x3F81429F339CEDDEULL, 0x717BF9471374CF42ULL, 0xFA86850A4ED1CB09ULL, 0x08D4943443A916F9ULL
        },
        {
            0xDD49B0909C6D54DFULL, 0x51A286840BC4C55FULL, 0xBE5A7108A62E96F4ULL, 0xB796BFAA060A9B03ULL, 
            0x2F831371E2A9BC19ULL, 0xCE030C32062FC259ULL, 0xFE1C81118A7D9C13ULL, 0x117E5E22E19A4A45ULL, 
            0xBFFF46B85249B7CAULL, 0x754F31276AF8104BULL, 0x52B86BA46EA31D71ULL, 0x05D2C94EF3853C29ULL, 
            0x4A6687F6BB5DCFE6ULL, 0x388B239B1FAAD122ULL, 0x21A0999EE5C43822ULL, 0x2C900113AEF6092AULL, 
            0xB41EA6DD1A2817BDULL, 0xD9F304BA83AB579FULL, 0xD20CF5F7A2976FF6ULL, 0xD6B02CA67DD5A02BULL, 
            0x5C51E3FA164BCC5EULL, 0xC92A9A9B53E9B751ULL, 0x2C68D67C87699C08ULL, 0x030DA36D90CC022AULL, 
            0x6D66984AD4DF2178ULL, 0xE99E8F2FDAF77B38ULL, 0xAEE1BA0FA9BFA06AULL, 0x63E781CFBCAA99C1ULL, 
            0x32A518D278EE8992ULL, 0xF20A89D6DE2A7F6FULL, 0x8319DA04EE293EDBULL, 0xDAD5EA327600BFA3ULL
        },
        {
            0x32611DDF1A7A00A3ULL, 0xCE3CEAB883E7F1F5ULL, 0x7752DBF339701D48ULL, 0xF71FEA4612F87B5EULL, 
            0x05692651AE8287A0ULL, 0xA94ACA6D9A19F852ULL, 0xCC4B21100C3A522BULL, 0x296C5A8A9AF9BAC7ULL, 
            0xE47E8D4F7656F991ULL, 0x3F5AA0C1291DCD42ULL, 0x5014208EF168A4F7ULL, 0x1D50E9BD4400A6D3ULL, 
            0x31E2A12B6EF78BF5ULL, 0x23EE6378FF105A91ULL, 0x7405506020D1C194ULL, 0xFE5BBB21A469AD89ULL, 
            0xE9681EFF2973CB13ULL, 0xB6A16795800DB6B4ULL, 0xBD7541B4F5AC0A3CULL, 0xE73FEA7FE5BB3345ULL, 
            0x61F7AAA5DF555913ULL, 0x123C70319795A375ULL, 0xD877F011133804B7ULL, 0xE983E27E694A6688ULL, 
            0xE68C685C8B4ECEAFULL, 0x9908308A0C4323E2ULL, 0x8B79910A1CA82660ULL, 0x2260A86DF171432CULL, 
            0xB7242CF847289353ULL, 0xF8AE81D6470574E1ULL, 0xBB50B1756E6A0E1DULL, 0x8BE7D7F6AF602227ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseBConstants = {
    0x03B6BBD2C9C3BC4AULL,
    0x27FC903ABF4458E4ULL,
    0x0A52020BBAE87276ULL,
    0x03B6BBD2C9C3BC4AULL,
    0x27FC903ABF4458E4ULL,
    0x0A52020BBAE87276ULL,
    0x1F95A9A29359B69CULL,
    0x9A212102DBC566A3ULL,
    0xD8,
    0x15,
    0xA5,
    0x01,
    0x1E,
    0x90,
    0x6B,
    0x47
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseCSalts = {
    {
        {
            0x14C4D4F80346DDB0ULL, 0x67A9D107F6E91D49ULL, 0x9ED0C65D15DB641DULL, 0x6F7FB78271C3E228ULL, 
            0x7C7737EBE0BE5FD1ULL, 0xCA1B5782F25DEF55ULL, 0x367DFBB7E891F674ULL, 0x11E07A073CB95BA2ULL, 
            0xB25BAA56DA9944D2ULL, 0xD05BD5C453F114DDULL, 0x9F59DC5B8E4041F1ULL, 0xE3B915BCC0B59F64ULL, 
            0x2A47CAD200330709ULL, 0xBA8147F52DCE3BF4ULL, 0xD6B695D9C1E1B1C6ULL, 0x6532E9C9DEF9E1BCULL, 
            0x3010A5A9AA64B806ULL, 0x555908FB260A0FB5ULL, 0x6851C220A765BB2FULL, 0xCC93D242C40AB35AULL, 
            0x6451BFC84E225DDCULL, 0xF2C0D00D74660B94ULL, 0x487962377E3B328DULL, 0x628A58A64B8BAA77ULL, 
            0xC81CEB0F7288C416ULL, 0x798FEAA2C5131774ULL, 0xEF02558C08AFB12AULL, 0xAE96D5CA3EA17B33ULL, 
            0xC2E1E4046357937EULL, 0xE850E272ED47D4D8ULL, 0xDEF7AE4CFD8C8ED8ULL, 0x5E02F947B1E7F2D6ULL
        },
        {
            0x132505D2C94B4AE4ULL, 0x8898AFCB41D76948ULL, 0x627BFF77C6DD83D9ULL, 0x0BE99A8E1B941A04ULL, 
            0x9AF1E2348CEC9942ULL, 0xA28F24B0AFF6EDC0ULL, 0x9D85381C888388AAULL, 0x77F4F99A01B45C5EULL, 
            0xADF0990CC8ED3416ULL, 0x9E6B76D6ED80A9E5ULL, 0xEE405AFF69D5E365ULL, 0x8C2D9D985131C1A0ULL, 
            0x84A6BCC6EA608DEFULL, 0xDF60F998A4AE40B0ULL, 0x12CE3B9D699B325DULL, 0x5F40FC8B90E4DECEULL, 
            0xAB75EFCDDBD5D94FULL, 0xF412DCD948BC218FULL, 0x46A31CA26D1AB966ULL, 0xA299D041A7B19827ULL, 
            0xCAFB8D62FDDC0267ULL, 0x728FE41898EE33D4ULL, 0x027DA9468579133FULL, 0x2680223F9F9DEFDFULL, 
            0xFC7E5BC754D60E11ULL, 0x7D5DA48886FC1260ULL, 0x6EBC59F642959B07ULL, 0x28E413A4496805CBULL, 
            0xC3D9DD076FD54909ULL, 0x105CE9C3FBBCF6CDULL, 0x67110625697CED52ULL, 0xD1A46492033A5927ULL
        },
        {
            0x7BB736B465ED3D7CULL, 0xD33F1B0510EE2782ULL, 0x63413E9A2CECDEB3ULL, 0xF2DCA1F4560A914EULL, 
            0xC958CBF35011F5D5ULL, 0x929F8F78AC3A07EAULL, 0x6D7889AB9380DE6CULL, 0x2E9247E39697EFB4ULL, 
            0xBC632550F5FDD2D3ULL, 0x550E34C208D02354ULL, 0x80F4AE8A51EC2A93ULL, 0x5F7E75119EAAE8BBULL, 
            0x38C505B962E7FA0FULL, 0x211C08BC622D8FA3ULL, 0xDF100B9CFE35B430ULL, 0x2FCA4E0C93DBAFB9ULL, 
            0x8F617A66B728877EULL, 0xD854E53AF50C2C4FULL, 0x75110B03707BC9F4ULL, 0x7AF930A96763B5DBULL, 
            0xF696240117DE6821ULL, 0x76D8B1167C34B522ULL, 0x7E24D11212A5B4FAULL, 0x2E5B7AFC696B027EULL, 
            0x52404E13918FBB7DULL, 0xCDD25DDC46BF4430ULL, 0x7052326A427DEF0DULL, 0xDE1B660510072A1CULL, 
            0x68F61CEF3CB0E23FULL, 0x4310C23D51F0BC78ULL, 0x6FE6C04BDAEEA905ULL, 0x85AC7934F88DCBABULL
        },
        {
            0x07619994F9F1FF5AULL, 0xC7C7DE00FE4AB5E7ULL, 0x7E78AB6517E409A3ULL, 0xCF0599C4DB3CED68ULL, 
            0xDFC79882F0359FF5ULL, 0x9BF943E55B0400BCULL, 0xD50F7A0487B74E21ULL, 0x77BEE6CBB867AE26ULL, 
            0x3F60D6CE011D641DULL, 0xAD930B338A6CF853ULL, 0x8FE24A9B80DF3CD3ULL, 0x7AC4D0A0E53B638EULL, 
            0x063EC670626F4DCDULL, 0xD8B630FDC3D65142ULL, 0x53A7BBD88EF5C682ULL, 0x49ECE5C95F88248CULL, 
            0xBAE7600B59520ED8ULL, 0x4E3A8997FBF02524ULL, 0xD65D1A026D4D1D41ULL, 0xD7CBE7DBF1D6D82CULL, 
            0xA4E96CAA8A821A80ULL, 0x45BC36DA8043694AULL, 0xCBF3B2FACB44833BULL, 0x1BDDD381535EC897ULL, 
            0x06D512D760A4DE7BULL, 0x769D9070030FE392ULL, 0x122E8A8370251929ULL, 0x82D08C59EE3CD822ULL, 
            0x0B14ABB22A8F22D7ULL, 0x6A645D114115CC1AULL, 0x5D95F7686A0E2B12ULL, 0x764CD06A6914F478ULL
        },
        {
            0xCC2CF22B2CB061B4ULL, 0x36B16654DB37DE6CULL, 0x02C04C6D23518233ULL, 0x27BEA3C469F08CF7ULL, 
            0x2BC710C51586DBF8ULL, 0x112051F405BDD066ULL, 0xCAA9AAD7A0872279ULL, 0x34640686C1BFA02DULL, 
            0x034952436CB5E82EULL, 0x06C4D577B31BE513ULL, 0x7849BA589BCBA7BEULL, 0xD00025F515984130ULL, 
            0x4C0964C59415606CULL, 0x2ECDDE2CBA32F9ADULL, 0x0AE01A2DD36F0E9BULL, 0x908873A6200FD65FULL, 
            0xBB586F3A424CC646ULL, 0x08BD876C999BDB2AULL, 0x47D5230A777A212AULL, 0xC117196032215B01ULL, 
            0x3B68FEA67D16A74AULL, 0x5818C7A3D22BF4B2ULL, 0x73801194C60A34A6ULL, 0x90465EBD5586894EULL, 
            0xA40EF1BABD4AA023ULL, 0xE56EFDBAA6D2B18EULL, 0x97483B523F86F23EULL, 0xA11CC837EF978FFCULL, 
            0x72A03E7A6F7C20F6ULL, 0x711E48DA62A488A8ULL, 0xE6951D94B1B46054ULL, 0x2FD461F68E4F58ACULL
        },
        {
            0x687FBC0A6F837EF7ULL, 0xF38093E000A96080ULL, 0x0EAFFEB7A773F602ULL, 0x5FCE760E3E621644ULL, 
            0x7F513235BCD248B9ULL, 0x882810E9A03A5541ULL, 0xEB405FECF316F9BFULL, 0x0E8F267C628AAE11ULL, 
            0xB00E39F8607809E4ULL, 0xE2B7B322B2BBE9DBULL, 0x32C7DCE165C91581ULL, 0x61F1582F0DBBBCFEULL, 
            0xC7EF6A7F72C9C143ULL, 0xAC8E667F8D833F2BULL, 0xF1E81DA3EFB5CC56ULL, 0xF946B964DEA3F4A7ULL, 
            0x2758E1D3C568FB0CULL, 0x5C120C9381BE4EF8ULL, 0x12876F4A726E1363ULL, 0xC777C19F112D09C0ULL, 
            0x973ABBF18B698A5CULL, 0x7D22B8EBDD8EC8B3ULL, 0x5C4973EE38D4AF30ULL, 0xEB71750F5410E8E0ULL, 
            0xC49C96440A690D50ULL, 0x8306DA145066E905ULL, 0xD7E9E37FD36A56DEULL, 0x322D320A7E35F267ULL, 
            0xB02B3999306203DCULL, 0xF5592193FC11AAAFULL, 0xEDCBB803545C0D7AULL, 0x358A1F04C7D20A4AULL
        }
    },
    {
        {
            0x443FA90721838C23ULL, 0xFD4BBC583E630DC9ULL, 0xA16DE8B9BE47453CULL, 0x017787920F74C26BULL, 
            0x1F5FD5C49FD2C5F0ULL, 0x2E0CC9543CA14454ULL, 0xFBD4ECBD71FDCB0BULL, 0x46496640B23563EFULL, 
            0x2DC9BD5F1962E9D9ULL, 0xAEEB05CD3E02CB83ULL, 0x169446B70C295D58ULL, 0x195224C654904426ULL, 
            0x59D705C41892CC9CULL, 0x160BDF1FC57173A6ULL, 0x291F116784A9F2A8ULL, 0x11CEB00EEC64F67BULL, 
            0x680B197ED99A2094ULL, 0x44C6EAA27EDD9D79ULL, 0x08FF3A1EF2F474E0ULL, 0xE529CBFDC0D4DABAULL, 
            0x23ED152AAD5C1A3BULL, 0xA236E6D83D84B503ULL, 0x7414B1CA58F1A810ULL, 0x2CCEE4DBC889A408ULL, 
            0xA5A9160CD3E86917ULL, 0x2C8C53AE5DBC6DF1ULL, 0x5983AF7D5E4CCDACULL, 0x20C67C60C4786634ULL, 
            0x7FD10626EACB8E34ULL, 0x730B9023AE663383ULL, 0xB0E4401A398E4D60ULL, 0x029611DAC7914159ULL
        },
        {
            0xA404F147A0DE896AULL, 0x226D0AE7074F8553ULL, 0xF8191F958A372BF8ULL, 0x0C24B92184ACE4B8ULL, 
            0xEB9D56F029593BF4ULL, 0x1B2748AF6DC4CF41ULL, 0x8BFF4EFA87D44125ULL, 0xCAC98EE9B8B56017ULL, 
            0xD638BFCC2BF54D81ULL, 0xD65B7F9CF9A49191ULL, 0xE748D282E0406815ULL, 0x379EFA3721A6E559ULL, 
            0x7A7FB36872F35AF5ULL, 0x735483F1F4398922ULL, 0x1106BB2FC856BC4EULL, 0x5B5F8CF195AC93E7ULL, 
            0xEDF62A12946B3CAFULL, 0x0697AD9A27A453B7ULL, 0xE7A88008A694C96BULL, 0x5407A9943B73E7ABULL, 
            0xA0D0DAC3803028D9ULL, 0x1AB04B0975CF0C67ULL, 0x9CB9DEE79A7B38E7ULL, 0x6F329E2326906754ULL, 
            0xEC71B0B098685D17ULL, 0x1B7376FE288D0CD3ULL, 0xCBE60C0330C9F977ULL, 0xD8DA399A78F695C3ULL, 
            0xD8BA56A088FD27D0ULL, 0x8B78FAC4263494F2ULL, 0x2B2613E167828636ULL, 0x43157D6C739DB8ECULL
        },
        {
            0xCE80AD96B78C2D16ULL, 0x7B4E658264363BBEULL, 0x9803F7DADDC0D339ULL, 0xEAEC9B4F797F253DULL, 
            0xC5CED1544ADED2A3ULL, 0xC9D3B1CFB35CDC5AULL, 0x912735BFF0090DFCULL, 0xA7F2DAE9F1EA222AULL, 
            0x21292788605ADDB6ULL, 0x0206812F4C2EA1CAULL, 0xCD95C46282DBADF9ULL, 0x0594AFF8AC2C077AULL, 
            0xF5B43B9A36C19E8CULL, 0x60ACA46E276B546BULL, 0xDCB93910969F7B8FULL, 0x5A557A05FB830696ULL, 
            0xBEC0E9CCAA72353BULL, 0xEE508F8ED7FB819AULL, 0xD7CA37130B7237A7ULL, 0x738D1534CFE099A9ULL, 
            0xF688B56EFA89D110ULL, 0x38731BEBCEF9EEB5ULL, 0xEAD7D42A1D7AE968ULL, 0x2DF5487E947B7AF6ULL, 
            0xA845D0829A406506ULL, 0xC2DECF77D04C5BD4ULL, 0xA53682C1A1FD0ED8ULL, 0x5CE179F13A4A10E6ULL, 
            0x2B31528D8CB7648FULL, 0xFFF34FE6B3F74323ULL, 0x898F293DDE419DBEULL, 0x1963B8981E2AE9D3ULL
        },
        {
            0x60361DB90D9F817DULL, 0xD96A8A6ED9AD90CBULL, 0x0BD87EACA4560C76ULL, 0x78544152F21FBE8CULL, 
            0x5B9F70C85BE22883ULL, 0x63BA8B45F5D452C1ULL, 0x37DF7C36D0F0E525ULL, 0x11E3FBA344ABBB5FULL, 
            0xDAE0EAA4B2B044C4ULL, 0x7B47189180876E35ULL, 0x4D3478DD5B4562B2ULL, 0xDCC0AF6331A6CD34ULL, 
            0x14AB755BF86B2EDFULL, 0x2F6A0FCBE51B26A2ULL, 0x1A020278E5C25E44ULL, 0xA725FC514EC4784DULL, 
            0xD9E217C17640EB78ULL, 0x45EAA7D4FE2037E0ULL, 0xF05B475407A3722EULL, 0x61CBFF4B9E61075DULL, 
            0x426066DD5E700C5FULL, 0xC6A9430FAE461A63ULL, 0x588D4F3D9CD14758ULL, 0x26F17BADFDC46702ULL, 
            0x583B9540E3DD9688ULL, 0x5A1D3C28ABA1EB55ULL, 0x06552531DD01387FULL, 0x63A1BE70F3B0EB40ULL, 
            0x6CB26903E80F03CCULL, 0x1A6E21E85FD66E03ULL, 0x3F1BE62D50C01894ULL, 0xB49E954F9BDD18D2ULL
        },
        {
            0xF3785B0B20AA304EULL, 0x2410D51DA4EE4685ULL, 0x2FDFD1B5ED6F53A0ULL, 0x029E77ACA72A9834ULL, 
            0x2E428A1AC03FD805ULL, 0x9E93E92FB20E19AAULL, 0x5BA79FCA606BE3D5ULL, 0xE682773E3A364AA0ULL, 
            0xF38446290B8DE28DULL, 0xCFE2AB3889E233A8ULL, 0x534C53C6E7269A4EULL, 0xD75BC079A6BA5677ULL, 
            0x3C65E35B3D8FDC46ULL, 0xD07F1E9ADDEC4956ULL, 0x3DA75D3EBD08E922ULL, 0x9FE8A4C0FCAAF4C6ULL, 
            0xE7CC37485EC4E8CDULL, 0xA7A81138029CC85DULL, 0x667A6B543CADF719ULL, 0x08E42D05B2A81EABULL, 
            0x0F9F68A6FC71FBA8ULL, 0x568FE7B793F92788ULL, 0xE1A7075B6055C198ULL, 0xB02D74FA6D6FA16AULL, 
            0x01FCCD320444EE83ULL, 0x15F62214AF900266ULL, 0x9024351824694B74ULL, 0xA12D05A5F91C138BULL, 
            0x07626D3C71A14596ULL, 0xF00BFDAB0AA39F98ULL, 0xFA783525E3E08135ULL, 0xCE4BA54A5339117DULL
        },
        {
            0x1C990C9BAC032201ULL, 0x334F385E12D5CF6EULL, 0xC3FE0EF052731B06ULL, 0xA1422FC76C6F850AULL, 
            0xE50621F1EED5A78FULL, 0x5DF58F06CAE3B7EEULL, 0xA04C118ADDD583C0ULL, 0x996BFD5FA71F2801ULL, 
            0xF86976CF0A2E76BEULL, 0x75ECA334E497E414ULL, 0x6F06A95B6A5C583CULL, 0x12A8E39AF26D1DBDULL, 
            0x13AE2F59003B1242ULL, 0x48265D4D287ED8B6ULL, 0x014E1BA633B156B2ULL, 0xFCC8FE3C70FC852DULL, 
            0xDEA7C78E3B235E65ULL, 0xB3B8A11D504BA31FULL, 0xA58437C30AC4D867ULL, 0xD0663A84B5553C96ULL, 
            0xDB58AEE3999D3A4BULL, 0x2E461A69A4BE8435ULL, 0x894A58761AB28C87ULL, 0xE93859D86D80DA46ULL, 
            0xB5DC1190D9F79EE0ULL, 0xE091917060F1B00CULL, 0xB7EB449FDAACC727ULL, 0x5441CAC9B48843BEULL, 
            0xE9FC87AE79B38E80ULL, 0x792F50D27300A206ULL, 0x9FEF97E158A380B3ULL, 0xCCE7A6DCE802CDFEULL
        }
    },
    {
        {
            0xCD10C32CF97D4B10ULL, 0xF9EDD9FC3509E379ULL, 0x570CC4754A5F6D4EULL, 0x1535BEAB2F652B6CULL, 
            0x712EBED4C55947E5ULL, 0xC7263213A9A78A63ULL, 0xEDAACFC3E8271797ULL, 0x6F3B8052C6074131ULL, 
            0xB8B61F8FFD0B4B84ULL, 0x9FA0F51F4F53BC72ULL, 0x5A1CDF914FD8E95AULL, 0x46C6187D5C4EFA83ULL, 
            0x7D2B572863EE64F9ULL, 0xD56B9A20AB732B41ULL, 0x67D020AF7979E3A3ULL, 0xF7B2648160B46FC8ULL, 
            0x2F87AA67F1982D25ULL, 0x866949700F4CABD2ULL, 0xC11AA73A749FF4B5ULL, 0x62981A34CE901F35ULL, 
            0x298237534FBF5706ULL, 0xFFEB2EEE775E07FBULL, 0x0E8CBB4C0BF11DEEULL, 0xD06E238349A639E1ULL, 
            0xDCBDE74228F3CBF6ULL, 0x77540BC01E39BAC4ULL, 0xD352BE18542BF88EULL, 0x63DFD067982F07C4ULL, 
            0x78ED9291A87C8420ULL, 0x97CB92FE508CC0E1ULL, 0x7A2558D9EFD1E04AULL, 0x49D9DF0CB2874A33ULL
        },
        {
            0x26DFA73A8983DD3EULL, 0xD47EA2F5D36404D9ULL, 0xD1EB1479CF1A6E77ULL, 0xDA7A8068FBB37778ULL, 
            0xD43C733A75171E8DULL, 0x1554E24BE0CE48A9ULL, 0x23B7BC3C0709C4ABULL, 0xC619C031D3926E21ULL, 
            0xE39414A2F71BBC9FULL, 0xDDB686223BF9EA02ULL, 0x6258709B508D81B4ULL, 0xA697812D256CAF95ULL, 
            0x3B314D3C971E2C13ULL, 0x4005744407C943D7ULL, 0x61E71DC28BD85F00ULL, 0x46E6B638B094B2B3ULL, 
            0xD2749D7942E35BA8ULL, 0x1ECA1AEC54E7FABAULL, 0xC9746B2ECCC9802BULL, 0x99502CE185FEA755ULL, 
            0xE4DD387CF2F41B53ULL, 0x9C6271DC6A26AAB1ULL, 0x56A4A2DD9A97BD7BULL, 0x0B59A61E9DC814A2ULL, 
            0x8212730F142AF515ULL, 0xDE77FA26F74909DAULL, 0x989AEACCAB034E00ULL, 0x0CDF34C6E3084EDBULL, 
            0xFA801ABF9DF01C8EULL, 0x5A997B352CCBF2C9ULL, 0xD0EF638CBC6DEE82ULL, 0xDCA37475B61FD3EDULL
        },
        {
            0x0F08798418781EA3ULL, 0x0715F3267B933BFDULL, 0xB20A51E8B1AC8B05ULL, 0xAED3C7A6D615C166ULL, 
            0x8B91945BA3398806ULL, 0x4A9232F33F15F2C6ULL, 0x53C586BB7BC2AC59ULL, 0x918F5EC868B441D1ULL, 
            0x34E9E687C3CE389AULL, 0xDE942461EEF54D00ULL, 0x31776C4F3C8ECD8BULL, 0x26F3D76D9C8C1439ULL, 
            0xCA9934294905EF4CULL, 0xBA2904EA37E2B389ULL, 0x45C574A4F077761BULL, 0xC7EAF808ABD2FA79ULL, 
            0x49814BC7B74CDD28ULL, 0xD5005E2F23CD6A35ULL, 0x3F5E1D7179619A41ULL, 0xA2746DA0DCD8FC4DULL, 
            0x26AB5B56FB5E7069ULL, 0x6B46E996A2E3014AULL, 0x3257CFBDF4610B6AULL, 0x4293BF11BA1178BDULL, 
            0x4B6DED34626BBBD9ULL, 0x1F0F36BF900B89C6ULL, 0x69540D9A0C90F257ULL, 0x2BEDE2C3A8DF1CFBULL, 
            0x9DD2325F14CBF964ULL, 0xF14C693404C690C6ULL, 0x9656FEB2EF8B020EULL, 0xDCD1A8643EEBE739ULL
        },
        {
            0xEDA084DF852C6438ULL, 0xF334E81EFD79152CULL, 0x386511FBC23A5167ULL, 0x0F2EA1FECC7EE647ULL, 
            0x9324F58C5564E96CULL, 0xC77589DF764D9A61ULL, 0xC933F874E6F53AA1ULL, 0x859B818DCFE91575ULL, 
            0xD38B088B3E26C16BULL, 0x7F7928D1A9C12E75ULL, 0xE3997DBF0BBE9817ULL, 0xF5EC7D766AB0EDE2ULL, 
            0x54552B69499BCA2DULL, 0x744922D7BF64AE8CULL, 0x3EE59F6154FC8260ULL, 0xA01D4E204AA474D9ULL, 
            0x2C70283243DEC037ULL, 0x2E52A01FBACAED29ULL, 0xACE499C7D6FC9EAFULL, 0xE120FFCD2E4535C3ULL, 
            0x15677FE1AB03D7CFULL, 0xBCC0AA88B1542472ULL, 0x01958A8062BE2DE6ULL, 0x90A44F348F412F9DULL, 
            0x223B83ED27247EB4ULL, 0xA05F71D5C2A6CF09ULL, 0x10A93A0A0440914CULL, 0x551BAF7545CF5F90ULL, 
            0xD15A6B87A80DB950ULL, 0x5F27C5F301220971ULL, 0x99C72BEE6E968026ULL, 0x0ACEA22DFF25CF6AULL
        },
        {
            0xF55218103AEE9B25ULL, 0x368BE6686F0567A4ULL, 0x50565FA217C5E237ULL, 0x36F3C54E2A0A0B08ULL, 
            0x7982F09847B0597FULL, 0x22796F6ADC300AC8ULL, 0x6E63984A6C973EF6ULL, 0x6A8F15F15A2359A8ULL, 
            0x335C666FB63EA8F3ULL, 0x56CC237CD7A322C3ULL, 0x201C9B4F79149FC1ULL, 0x49F45B90ABEEA719ULL, 
            0x03267FF84DA115AFULL, 0xBDAFD623E1F73728ULL, 0x0E7BEE229E1B328BULL, 0xD24F3DFA9F59A704ULL, 
            0x7A4488A444853645ULL, 0x62F1DF086A9974AEULL, 0x18624C25A57B7965ULL, 0x0E6674BAEBD19C89ULL, 
            0x1AA11F970719F72EULL, 0xA15E62D65884F7DAULL, 0x43EAB610F3CB71D7ULL, 0xFC9A30F99D7BCFBDULL, 
            0x25F402658924666FULL, 0x406C9D37228D12F0ULL, 0xC83724CE0CB24D96ULL, 0xAA994983AB09C97FULL, 
            0xD13BE05427DA1978ULL, 0x2246F4B9CB66783CULL, 0xECCBF008CD54FFF5ULL, 0x673F817188B9A6FDULL
        },
        {
            0xF945EE721B747D2AULL, 0x44CF635A20FD03B9ULL, 0xDA88E6126E0F21DEULL, 0x85490206CBAE92B9ULL, 
            0x45DE5EBFB3CF465AULL, 0x823FC912493EDC56ULL, 0xBCCC264A919C5B12ULL, 0x089433F39DCB64B9ULL, 
            0x09970297353A6C8AULL, 0x9001BA43CF821304ULL, 0xD20FF8B072E0EEFCULL, 0x9766CA8493CDC25FULL, 
            0xD7C7C39B0088D25BULL, 0x8F9D1C6CE29C97ECULL, 0xCB0C6688FA75BC6EULL, 0xCE3ECB1BB2C0E7EFULL, 
            0x6A639BA4A4500534ULL, 0x83AEAC549FE33F04ULL, 0x189C79EC58C1FA28ULL, 0x8C95BE21E5109D4BULL, 
            0x4201E7BAC6B912E0ULL, 0x6E0467816D2274CBULL, 0x450029DCFF530653ULL, 0xC1E2D8FD4E499E82ULL, 
            0x5AC4BD5D92628AC2ULL, 0x03EFFCBFB655447AULL, 0x278CD06589328AD5ULL, 0x3D3D8F4A9EC317C4ULL, 
            0xEB0930C18B679990ULL, 0x45E0C5FD2A31A611ULL, 0xBEA126A94CB4E97EULL, 0x2CF01795BC4B2D90ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseCConstants = {
    0x2115386766F3D7B8ULL,
    0x806B2B9D8767598EULL,
    0xE06883FCA1A63A71ULL,
    0x2115386766F3D7B8ULL,
    0x806B2B9D8767598EULL,
    0xE06883FCA1A63A71ULL,
    0xDC1FB971280892E2ULL,
    0x4C7EADADF638FCE1ULL,
    0x37,
    0x78,
    0x44,
    0x49,
    0x4D,
    0xF0,
    0x48,
    0x06
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseDSalts = {
    {
        {
            0xE9B1E2BF7ED2E6D2ULL, 0x5CC2E3913410183FULL, 0xC20FCD091596DFBEULL, 0x6140D9834657F519ULL, 
            0xB849FCDC1C1C37E6ULL, 0xB5B6745514F79808ULL, 0x1002BDDB544E8AA8ULL, 0x93D29E4B76A95522ULL, 
            0x2CA69615249C51D2ULL, 0x021E601B72AFC4F7ULL, 0xBC39093AF8A0C427ULL, 0x6643C2A4BE5DE8B9ULL, 
            0x9DA4415FF055A452ULL, 0xD11D7327DF1DB6B1ULL, 0xE93E8606C05B6568ULL, 0x5A3D1D330403D27DULL, 
            0x0A531CAF75E2C3D4ULL, 0xE51CFFEF186408D3ULL, 0x3DECABFF7384A235ULL, 0xB7D3F0E825259095ULL, 
            0x0B2AF81556522EC6ULL, 0x37641042EBAC4D23ULL, 0xB03ECB0D3E145E61ULL, 0xF503AC7BFF2C68D5ULL, 
            0x314B9BD9C36AB2EDULL, 0x32A9B7FA2DC7BB94ULL, 0x859614DB799748EDULL, 0xDA876AD47391A666ULL, 
            0xD1DA9BE69C5E6114ULL, 0xA0CC34F49D6CAB1EULL, 0xC4B7CBABEC38A133ULL, 0x299E4DE241946B70ULL
        },
        {
            0xE22ACC0F3B43B3D0ULL, 0x4EA40903F69007ACULL, 0x4791AF1AA6EAD559ULL, 0x6972EC83B21AE3DFULL, 
            0x46B1FEB97BBCF1AEULL, 0xF564672694F364FEULL, 0x846EE740CA9728FBULL, 0x09B84F76B92487EDULL, 
            0x2D7573558B5D4E02ULL, 0x44BA2D2E68093F93ULL, 0xEED95B27EFD32638ULL, 0x8C424B1C4204B665ULL, 
            0xFFD3EE355623B15DULL, 0xD15DFFDAE94651BEULL, 0xB015CB4EF320BAA3ULL, 0xBB3802B19285210FULL, 
            0x3C76CB8C91FE56F9ULL, 0x89E5F091755CA0DCULL, 0x3D61E08E029253F9ULL, 0x4E0BC2B76295440FULL, 
            0xAC779AA9F7C45FCBULL, 0xAD290274D2D2ADB1ULL, 0x71C31322048FE19AULL, 0xD80622B18E79C4B2ULL, 
            0x149112F01946A9F3ULL, 0xFD38DB7634714822ULL, 0xBD49D8993EDE81B4ULL, 0x2D296A8CD445087BULL, 
            0x06B68A4CF3E55274ULL, 0x630A9F58C0949B08ULL, 0x90E4E85ACCFE7CA3ULL, 0xFB983FE2276AD377ULL
        },
        {
            0x5D9DD46DB85AE292ULL, 0xC95B884B7A57E56AULL, 0xE5755CC20969CCECULL, 0xF6B7CC309012BAF1ULL, 
            0x548EDAB665FABED3ULL, 0x833116CC8F16BF0DULL, 0xBA761C5FBD7D0DE0ULL, 0xBF69003425A43859ULL, 
            0xCFA4B304C6257285ULL, 0x1008DDEEF0DE248AULL, 0xCC90EBDA3EF081B1ULL, 0xA862A7EB3C1A46F1ULL, 
            0x0289D8EE2236B6EFULL, 0xF5EBD4E09F70C9EDULL, 0xCA64F355A5256D3CULL, 0x8289D7A5748A7E03ULL, 
            0x595BBDF9D5B2BCB6ULL, 0xB78C4C0D784AB234ULL, 0xBB2CBB6C26F9D102ULL, 0x116066B9FD77A25DULL, 
            0x0FB8D9DA609603B3ULL, 0x3F3918E9BBAEC2D4ULL, 0xD68A1273BBF52CA6ULL, 0x596451ED0510164DULL, 
            0xC5A1267E37172384ULL, 0xD08CFB9E2CBD570DULL, 0x752745C60432403CULL, 0x908386B4552705D3ULL, 
            0xE2EB0E6D34A76B2EULL, 0xF593141E925DE8E4ULL, 0x886EE46E63DE6ADEULL, 0xA28BB915DC4A4E68ULL
        },
        {
            0xBB2A2E17FB9E6A1BULL, 0x1984824AA57EBD70ULL, 0x3DAF82B10F08097AULL, 0xBAB02978A23519F4ULL, 
            0x77AC2C7C0BDB9DC1ULL, 0x243D98DDEDF46895ULL, 0xB3B075DE59D95B2EULL, 0xADEE0C13097EA433ULL, 
            0x29D27A057A27EC99ULL, 0xA310EBDC2EA9E36AULL, 0xEE9F8F1F2110CA6EULL, 0x6BBD3AB078AF4A60ULL, 
            0x62EE74C9194AFD55ULL, 0x2176D72E13264F84ULL, 0xD3FB7638D7F4D5A9ULL, 0xD2099615AA762FA9ULL, 
            0x2F5AC3FC2C6CDB6AULL, 0x64CBFD450AFC0D58ULL, 0xCC427297797045EDULL, 0xE2C7BA6274C39A58ULL, 
            0xCDABCE67A2CB505BULL, 0x398975C6AD39EA6DULL, 0xAE1E155344540663ULL, 0xEA737ADA5C607262ULL, 
            0xE0DDBCD4199F5641ULL, 0x63CF6EC9EADC65E4ULL, 0x3CD7119F01F76124ULL, 0x23CF8295FED7C674ULL, 
            0x4B481606F105D90CULL, 0xFAA205E158ED6642ULL, 0xD888CE027BFAF061ULL, 0xDE82A5AE41F0F2E9ULL
        },
        {
            0x5F8687E8E9B10FEBULL, 0x57D22FF53586E0D5ULL, 0xC926ED883280B6FDULL, 0xB50CA91A2B119794ULL, 
            0x8D2A0A1BB5A71AE4ULL, 0x99DF29120B1437F4ULL, 0xE632481EB65C08BCULL, 0x93BC3656C64869F9ULL, 
            0xB6D0048788672004ULL, 0xD386498C8DDF2702ULL, 0xFCAB015A0EC4A3C9ULL, 0xA595D515FDA99E3DULL, 
            0xCA54A069A741B019ULL, 0x137B6E3FA284C3D5ULL, 0x971D33279D26FC8DULL, 0xDE158B1C431187A9ULL, 
            0xD23C9FF74CF29750ULL, 0x612A3E6DCAF05DA0ULL, 0x1712502C773AB9DBULL, 0x6B006D25A20AE4C8ULL, 
            0x3A0F33CD0DDDF25AULL, 0x08094D337B788F13ULL, 0x6BC6FE6BF2571DF7ULL, 0xB071A1675A46B90EULL, 
            0xD19906862D67D675ULL, 0x09D0AEFBA7340E1BULL, 0x89FA580B9FCB8520ULL, 0x5A5D19F27FDEF10EULL, 
            0x6A401F173ABC3235ULL, 0xEEB329F35ECED4ACULL, 0x71A01226F4C8B464ULL, 0xA09AD465F5DE543AULL
        },
        {
            0xA240B24E2800BA59ULL, 0x31C55B6F5751538CULL, 0x2B19183B367B08D0ULL, 0x2A80DB7859115070ULL, 
            0x960874EA33888C8BULL, 0xA6F05037FD2539A1ULL, 0x1C528AB5E5DFFB5AULL, 0xFD7B8D6817B9C01EULL, 
            0x1345ADD313219F8FULL, 0xA92138DFD73123C6ULL, 0x4D8B16EFE55821F1ULL, 0x8DF354D85C298D1FULL, 
            0x1E0A290E9A1392C3ULL, 0xF9A6DA71ED0D5CB9ULL, 0x0E289FFCE0F25C26ULL, 0x68BB2EDD2F2B510CULL, 
            0xB50B56B7EA29AB97ULL, 0x1B3839359382A3B2ULL, 0x37BE4AB0F6118448ULL, 0x4E04F0A3D78F9C9BULL, 
            0x97272251F02CE590ULL, 0x840068184133C340ULL, 0x937DCF00D61F8914ULL, 0xDCF960BCD537F423ULL, 
            0x15EE9AA9B8171391ULL, 0x74A87FFF3B83ECDBULL, 0x2A08C268F75C9968ULL, 0x6EB09282F3FD8BCDULL, 
            0xEFEFEF1A294246D2ULL, 0x5DA1C3BA68FC6C84ULL, 0x0362D5013CAF4123ULL, 0x708E178370735479ULL
        }
    },
    {
        {
            0xDCF18E95C9418844ULL, 0x6B5DE630551FAB34ULL, 0x4ECED67DF9BFCBA7ULL, 0x153595E0F99B66EEULL, 
            0x6144FF718535C3BAULL, 0xB1E2A261C2C5913DULL, 0x81ED17C8E2609D7BULL, 0x81B2FE81D6561A66ULL, 
            0x4F5B46396ADCE8FCULL, 0x1BFE1B10295A11B9ULL, 0xF9679383693C0F0EULL, 0xB08D55EDC0C35ED6ULL, 
            0x7DACAA72ECF3F434ULL, 0x3737EC1EBB398928ULL, 0x19CF403BAA788D3EULL, 0xCBC38C3F18992046ULL, 
            0x333B89B8A155238EULL, 0x14DAAC37076AC314ULL, 0x599D66D28FC5B3E3ULL, 0xBCC79B5D563DD7C3ULL, 
            0xDF3D3E31443D7819ULL, 0xF0954738F92B7211ULL, 0x836A38F2CFD0D328ULL, 0xCDF7003CC70DE53CULL, 
            0x60E91F2D36EF4AE6ULL, 0x8BCBC425CC08A4CEULL, 0x40B31C28436AD144ULL, 0xB0F41E2B572EE41DULL, 
            0x43628BEC6417F431ULL, 0x91AC3F663DAB4FFEULL, 0x38181FE855A70DFFULL, 0x627E63A7F3FA0984ULL
        },
        {
            0x97D077CF1D627D27ULL, 0x5F12FE0FA6EFA974ULL, 0xB7489F5083609699ULL, 0x59F054762EDB0C97ULL, 
            0x20007C3668CA59FCULL, 0x858876306F5229C3ULL, 0xEC614F843A566D5BULL, 0x02F2F4B4F4FFBA88ULL, 
            0x7B1216191C68F35EULL, 0x23B9F5E2B3E265AAULL, 0xFAE6F11E44215D3EULL, 0x2E15FCC34ACAE39AULL, 
            0x0C2CFEBEEC9B8876ULL, 0xB3EE2E1C5BA1A415ULL, 0xD7259E3B52EDB09EULL, 0x0E06BD03C58A2EEAULL, 
            0x9D1878F88599E21CULL, 0x7913DBBFF5FF2DCDULL, 0x85F5778F63668060ULL, 0x734A33CD96FD8E24ULL, 
            0x0DF9285DEA5076AAULL, 0xE921BE174A6FDD91ULL, 0x1CBC619D56DE78A2ULL, 0x19D701DBDE40EE72ULL, 
            0x8CB86D433E38DFEDULL, 0xE03D31EFD0D59B72ULL, 0x0C2E1A0D5D716E3BULL, 0xEEC3BC9B89349A7FULL, 
            0xE625E2CBBAB20C5EULL, 0x4F266C886AF631EAULL, 0x403104715E2E454FULL, 0x1D86D0FD711EA74CULL
        },
        {
            0xC178C45C867923D7ULL, 0x4AB2DBFD067517E3ULL, 0x8D010801528EBCE0ULL, 0xB5DFF95CD2EDFEBDULL, 
            0xE29B26AD8ADF5BE5ULL, 0x79AE132552364E1CULL, 0x2E7F4117475006C6ULL, 0x7D7482E2D437712DULL, 
            0xBC18559745DC9B52ULL, 0x5D569B842A86E234ULL, 0x8733F6D0A91F6261ULL, 0x09675606A58430BEULL, 
            0xBA1CDCAAFBFD2884ULL, 0x12B001148F7853EDULL, 0x87D8F0EBB8D69058ULL, 0xE7A5E8413E140500ULL, 
            0x376601907B895E5CULL, 0x802EF13326EDD55FULL, 0x41226AD6D8D942BFULL, 0x6C5A6F16F12EDF20ULL, 
            0x40AC70AD9E70C036ULL, 0xCCC009514BAB2856ULL, 0xD673C5138E6FE2E4ULL, 0x70E6BC89BBE9E21CULL, 
            0x6708967E5FAF6748ULL, 0x1141AB00FE88C3FFULL, 0x9D8D2429FCF015B0ULL, 0x6882230CF716C901ULL, 
            0x1AE85A3452535089ULL, 0xDBC410FB25A49D6FULL, 0x6A59C4CD746B1CADULL, 0xD70B5D80533DB373ULL
        },
        {
            0xEB69EA815500DE43ULL, 0x638E97964D28255AULL, 0x965EC53062AEDBB9ULL, 0xB12952897B21463BULL, 
            0x0728A659375D2A92ULL, 0x76375E146D0AD4A5ULL, 0xF656815A43C7246CULL, 0xDFA1019874359976ULL, 
            0xF74466C5C52B3C9AULL, 0xD37EE749F2A3980FULL, 0xDFD1058E6F3854EDULL, 0x70F92BE37631C66BULL, 
            0x116DA66254A1A999ULL, 0x921E157EC196E576ULL, 0x0973253B7977F92BULL, 0xD200C1558C930C39ULL, 
            0x7F0908446ACD37A9ULL, 0xF2D01BF3C14D3211ULL, 0x6E55139302039B82ULL, 0x05D6A3BB5C1EF74CULL, 
            0x16E9B0F3D884E664ULL, 0xE50C8457AAF1603BULL, 0xF3412B7ADB0D8014ULL, 0x167E9C734B09EEF3ULL, 
            0x68FFBA140EE68A9AULL, 0x1B72BC6C269D7D84ULL, 0xB3F85061517A3905ULL, 0x80848255FD3B9901ULL, 
            0x1E800AF40BEA50A2ULL, 0x73D4622D3669A86EULL, 0xACC134F89D842EF1ULL, 0xB08B622089E8E420ULL
        },
        {
            0x6998E423F2F605E0ULL, 0x61346120BAE563C8ULL, 0x814430B31A82BB0EULL, 0xDFE12648F55A59A3ULL, 
            0x5819B79D4F7BF643ULL, 0xBAC28F307222F6BDULL, 0x97C60A0A957F2225ULL, 0x358744F37A85DAFBULL, 
            0xC1BAC102AA68E96CULL, 0x1CA8AA1DA43DFE7DULL, 0x502AE5A421AACEB1ULL, 0x192E054610E15770ULL, 
            0x4D23905E9CF9B833ULL, 0xA57E21E301A3EA65ULL, 0x5E6D4B724C066BFAULL, 0x2A269E4039C5BD3BULL, 
            0xD62F3C4D6B608055ULL, 0x95AEE52A6BDC6BF3ULL, 0xEFE02B044175BBF3ULL, 0x8B87EF06646B9F8EULL, 
            0x2CD52816FA2EDEAFULL, 0xBDB24AE4C0A620B2ULL, 0x1287C07CEE68CB95ULL, 0x8B01C3AC1C632DB1ULL, 
            0xD2EE3BBFF1F05D61ULL, 0xC9DA683C660F08CBULL, 0x95FDDDBADE3B7DE0ULL, 0x0383B056CD25A488ULL, 
            0xFFD98C6277BFB4AEULL, 0x4267A568D2F64CFAULL, 0xFEEBB65E21D14F02ULL, 0x7C4285ECEFADB6EEULL
        },
        {
            0xDACAD34CE0B879A1ULL, 0x6C60DEE206607B0AULL, 0x15CFFCA2640972A6ULL, 0xD5E174721B4C9005ULL, 
            0x26775EDE78F8ED2BULL, 0x3F1BCF63C3CB731FULL, 0x38A2A628C5D47468ULL, 0xBFEC11434BD3B577ULL, 
            0xF15F67173C074044ULL, 0x9C1E22D45B52ED24ULL, 0xB299DDB63D650E39ULL, 0x3AC9A813F755590BULL, 
            0x77D6FF1B130DAE30ULL, 0x88EEA301865716A7ULL, 0x13F27F8683FA6A52ULL, 0x0E0AEA5E7DEBD92EULL, 
            0x5698ECEFEDA3F8D0ULL, 0x0562BEFA80F78EB6ULL, 0x1D6453951E2770F8ULL, 0xC7E550D587A9618BULL, 
            0x194203B57AA9D6CCULL, 0x77770C30C0C7845EULL, 0xE2540E94220837ADULL, 0xE99B1B3174F576A5ULL, 
            0x3EECE9136A04B3F4ULL, 0x48EE6AC6FE73CE35ULL, 0x953EFB6B51A1DB66ULL, 0xF7347E51CF38843CULL, 
            0x75918AB365C04721ULL, 0xBF5D01F0096AAB00ULL, 0xE4B80B055DC0B2EEULL, 0x2E96388C82939A9EULL
        }
    },
    {
        {
            0x7C89125CEDD04DEAULL, 0x72B3EF1C416B27A1ULL, 0xDB57D3EEDC959741ULL, 0xDDF36B15369A06C4ULL, 
            0x851999424E7C4D99ULL, 0x41E4D1C0C0A6AEBCULL, 0xEF66DA935A565CFBULL, 0xB10A3152CD1CF4DEULL, 
            0x956CB9927648476AULL, 0x2A763421BBF34440ULL, 0x5774C08403729FB4ULL, 0x68A3E819F349A64EULL, 
            0x98B83E73FDEB62E5ULL, 0x018FD45322BBBBD4ULL, 0xFA8AE2F3B4036409ULL, 0xE377307AD34D84F9ULL, 
            0x2EF62D913D1C5191ULL, 0x8FE3D63914CB2822ULL, 0xA5C27C2D80378BABULL, 0x8D60FED6A57A70A7ULL, 
            0x7EEBC7469379713EULL, 0x5C78AD1D40749ADEULL, 0xA9F4BED816AB4DCEULL, 0xDB81A0FDCF82451FULL, 
            0x9987131B942C41B0ULL, 0xC0980C78E9423102ULL, 0xFB6F355E2BFE96EFULL, 0x80F459174EB4146CULL, 
            0x0F64CF17EA5F2687ULL, 0xF8D79D28C43949C2ULL, 0x1E6CB0F03FDF5187ULL, 0x4F7ACE606262422CULL
        },
        {
            0x0228B6FF4BA3CA03ULL, 0x169B128D9ADD1B77ULL, 0xD71FDE022006923DULL, 0x3F166F65F8286294ULL, 
            0x9B43DB158D7F0151ULL, 0x8C7381F4CAA140DFULL, 0x0D1724E0E24FB736ULL, 0x39F4A7B72A6E29EFULL, 
            0x1F40F39E7E606341ULL, 0x6BEE696A75D4E2EAULL, 0x5FCE0FAF9CEB4B3BULL, 0x904D97E45530AB50ULL, 
            0xA4502969009BB668ULL, 0xEC9178A6B33A5790ULL, 0x2B0F54443BE09FE3ULL, 0x57DC086907E0E673ULL, 
            0xEB9D8B99E35A9D97ULL, 0x30425C09D8C7CAE6ULL, 0xDF8D8F84D59E3D60ULL, 0xECC96F124C002C22ULL, 
            0x6A19FE8F45D0D902ULL, 0xC869AF29653C7850ULL, 0x5D4CEE1FB655CF37ULL, 0x00E0EDA875332181ULL, 
            0xC85EA432E138AC78ULL, 0x1AC0F67A7B34CC5CULL, 0x246C9C6781C15BC1ULL, 0x57DA7EBE9EDE0932ULL, 
            0x2156C9F09916343DULL, 0x645CA325F9C79704ULL, 0x093BF2B14ABF1D5FULL, 0x8862B296238C0CD1ULL
        },
        {
            0x204AE5D2C3D94AF4ULL, 0x3D5B08E828BC99F9ULL, 0x410C72C1BB6F86F8ULL, 0x7794EC0F7F459F74ULL, 
            0x5C228B4E073BE8E8ULL, 0x63568C5BA144BC79ULL, 0xA2BF60A81287D2FFULL, 0x22BBED98C5386537ULL, 
            0xF277942345E1C722ULL, 0x6D0FEFB4084B5EC8ULL, 0xE58B14375018A740ULL, 0x0CD3C9B09AD0D49BULL, 
            0xF0C218FF545F9D1CULL, 0x4FDD097DDE24217FULL, 0x86087AB7B7680542ULL, 0x3B7FFC3BB4D73383ULL, 
            0x9704153238801EC4ULL, 0xDA249ABD78FE7A70ULL, 0xA393838C2D2EBF0DULL, 0xE4C551B5216127C3ULL, 
            0x95722790AD2FC99AULL, 0x394338E18931EFCAULL, 0xF827981AB42FF70DULL, 0x5D632F5FA67FC619ULL, 
            0x9E707FD73D61131EULL, 0x2BFD8B499AF420D2ULL, 0x2BFE57A02EB93D42ULL, 0x29A80B12C50AD2BCULL, 
            0x878CA4286A1DF677ULL, 0xBAB555CCA6F65754ULL, 0x69AA16A30992592EULL, 0x50684F919484F0BEULL
        },
        {
            0x3117D9163B3F821CULL, 0x685BE18E8F57F33AULL, 0x9733D6633EF97AAEULL, 0xED2F3C001DED7F2EULL, 
            0x84108D9DBCDD9119ULL, 0x73CA3EFB809B72D2ULL, 0xA54FFFF07B016063ULL, 0x5D076CEFDB14BB62ULL, 
            0x22A43DBBF004B1D1ULL, 0x6A54372354573C13ULL, 0xD40B601BBA7F833FULL, 0x0445DEA6B829C187ULL, 
            0x088823A6144FCD83ULL, 0x2C0142EFD3EAE49DULL, 0x88E89B92A0F8303CULL, 0x463592CA5F12207AULL, 
            0x3CA922DEFA6CD7E6ULL, 0xDD27B2363F8CE7AFULL, 0x505433112736F456ULL, 0x0D6CC6B10CC4C44EULL, 
            0x99A6C4683184E1E3ULL, 0x0C7CFA34F0A80F9FULL, 0x0688009354943423ULL, 0x084A83ACE6082C5BULL, 
            0xC538F0933C91F0E0ULL, 0x82799932914A2AA6ULL, 0x40AFD19D584A4BE8ULL, 0xB3E3347F57BC7836ULL, 
            0x8E194A214AA45E79ULL, 0x2E9E49458D3C92EAULL, 0x66F96D54DF337F6FULL, 0xECDF2FA5191EBA64ULL
        },
        {
            0x28410E5A741D5B97ULL, 0x704C5BEFB719A37FULL, 0x549CA8D8335F3490ULL, 0x1ED7D5CB53D1FC19ULL, 
            0xE11519091A55F526ULL, 0xEEB698191E543541ULL, 0x01AEBBB19AF2B084ULL, 0x1B26A9479698E1DDULL, 
            0x55200B95AF745D44ULL, 0xF824AFE86696A63FULL, 0x3B647AE217A313CAULL, 0x73185CA2C236B65CULL, 
            0x53AB265A3609139AULL, 0xD02EAADE358F6944ULL, 0xDF916308E00D61A8ULL, 0xEAD029A9C0E5F5E0ULL, 
            0x4BFFBF9382CE1807ULL, 0xDC50AC2212161D4AULL, 0x62C6C270B2C8F264ULL, 0x638A7D11533FC4D5ULL, 
            0x12C0FBD34F11E702ULL, 0x87D76F3ED70BE64BULL, 0x7B858EAC3E977814ULL, 0x7907455CA063EB18ULL, 
            0x78C305AA722C1BBFULL, 0xAC242CC4DDCC2F4EULL, 0xF24A71F6B4B73D6CULL, 0x4EC40DA58966ADACULL, 
            0x506463D782041C15ULL, 0x6C090842E1B61812ULL, 0x1414F82D4894ACC0ULL, 0x2BD62DFC2B1A4B5BULL
        },
        {
            0xFA20FD0EBE840256ULL, 0x0F3623BED2F6C88DULL, 0x21546BEB3FA8C9F0ULL, 0x73B40FF9CF16E4A8ULL, 
            0x8B129315B54B6AA3ULL, 0x117269254DAC5741ULL, 0x2621196F04DB0D3CULL, 0xBD5C60874025F6C2ULL, 
            0x0EB34B6D512A2DFCULL, 0x2F9A0C6BB09B4214ULL, 0xB53280D33CC32E32ULL, 0x25CD1F70C3328FDCULL, 
            0x3538BD150B367032ULL, 0xBBF2BC93AEBE2E46ULL, 0x1CD5767B60053E0DULL, 0x9994802FF6A8659BULL, 
            0xAC9940250A60A6A7ULL, 0x3865BB69709D7D33ULL, 0x503660363ECF90B5ULL, 0x808AAB603D3832F3ULL, 
            0xC32A13A6C956FC06ULL, 0xA26554A32F0E7AB8ULL, 0xF8F2F948232BA8FEULL, 0x8652EC6C139344CEULL, 
            0x29CDA6CDA4C16C82ULL, 0x00DB35CDDBE58B27ULL, 0x7A7793743BC7574DULL, 0x49EAB6CC86DA9ECAULL, 
            0x6934918047A9B50AULL, 0x46E26668B899C528ULL, 0xD133F34CA7245123ULL, 0x7BE24266D1F4C9EEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseDConstants = {
    0x81E99F4AAE00E11DULL,
    0x3D36170C0045796DULL,
    0x95D0D6CB96BA4888ULL,
    0x81E99F4AAE00E11DULL,
    0x3D36170C0045796DULL,
    0x95D0D6CB96BA4888ULL,
    0xF90D4F6631608372ULL,
    0xFA8FC55E5EEA778BULL,
    0xBB,
    0xC4,
    0xAA,
    0xE9,
    0xD3,
    0x80,
    0xA6,
    0xE7
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseESalts = {
    {
        {
            0x0C006A1DA624831BULL, 0xCF6C3266B7B7CA43ULL, 0xC4C562B2F0B9E91AULL, 0xD986F367887246E3ULL, 
            0x172863ED56A60D55ULL, 0x7E5AB37EC0C83925ULL, 0x93A28C8B64453F8AULL, 0x7BB3083FA6B61FFEULL, 
            0x7DC2D1A69BF23EB5ULL, 0x6C8686D05061767AULL, 0x0B362208E958D858ULL, 0xB4BCA088F80FD7EBULL, 
            0xF2D2D82F00D90329ULL, 0x7C6120CC8EB79002ULL, 0x3E1F3BF2E4CD4B4CULL, 0x76474F1EF8404F9AULL, 
            0xC5BAA6E8546CFF09ULL, 0xAB745D6E51DFD944ULL, 0x318DC7A8F57C76ECULL, 0x8ACE3E7112B9BFB9ULL, 
            0x7C61AC8462E1FF3FULL, 0x1347E6BDAE40EC8AULL, 0x433E30262A416B4DULL, 0x0AA7CBE37D186FBEULL, 
            0x88CA6407F526002BULL, 0x4BC8686800FD4F60ULL, 0xA5D28DA13A7243BAULL, 0xE48D391DE26110FEULL, 
            0xAFA4865D2FF43EF6ULL, 0x8B517D4EBCBE6696ULL, 0x71BBDB0841C94796ULL, 0x370998B5509F5230ULL
        },
        {
            0xAD5F0FA319D4D056ULL, 0xCEA4C71AE41DD722ULL, 0xB63BBB2D529DE169ULL, 0x01FC7A5F443B6F22ULL, 
            0x4691C78EB1024268ULL, 0xEA41804145B0E10CULL, 0x1C469448373D0312ULL, 0xA19A934E3993C07FULL, 
            0x35EDF1987AB796C1ULL, 0x4B57896A5A3B83A0ULL, 0x094036605D2CC96DULL, 0xD8524468E8614EF3ULL, 
            0xFBB4B487AE128D78ULL, 0xF433656336F4D293ULL, 0xAE737096280B4573ULL, 0xF5E715CD5BF389C8ULL, 
            0xCA45DF0C7974A191ULL, 0xCEFBFD41904A9D95ULL, 0x43FC40D29F8AE9D0ULL, 0x5E7CD7375F24CF31ULL, 
            0x650D12DCC7EECACAULL, 0xC68C2B7F5EDE58ABULL, 0xE3342876E4DF6BBFULL, 0xC1D6B569940609E8ULL, 
            0x8702C43C10AB7802ULL, 0xC3DEFB35D0BC97A4ULL, 0x169F10871E2846D3ULL, 0xB902EB5FFC586B32ULL, 
            0xB7015AB4D22203D1ULL, 0xEBEFC078E5AC05BFULL, 0xBCA8C1837A4DDF0BULL, 0xBF9716B99563878FULL
        },
        {
            0xB6A3D40C176D8296ULL, 0xDFD20F2BB02E5601ULL, 0x059DA4576874258CULL, 0xDB98F683C326C53EULL, 
            0xD002767526CFCF59ULL, 0x0C8C592042192FC5ULL, 0xCBFB9B0A42D5736BULL, 0x4755DA118BFF93A6ULL, 
            0x076AD7BCCF2A94BBULL, 0x1031A1D479B08164ULL, 0x369FD2A0D45FBB71ULL, 0x8FCBB3F08449D9FEULL, 
            0xF27DE89A9FFDF5F5ULL, 0xB550B3E6EC153701ULL, 0x00CFDF68266F527CULL, 0x47CE9A5F447DA4BBULL, 
            0xE5152F2A2382111BULL, 0xBF96D93C5B3B801BULL, 0x3D1C40A023FAF085ULL, 0x5ABE6B00E8767A57ULL, 
            0x1CDF6CBEF3ADF285ULL, 0x2F68E34BD8BDD04FULL, 0xAF651BE2CC59A08DULL, 0x1ECC937B1772A54EULL, 
            0x06139BECB1A59878ULL, 0x6CBFB5DA103D83FFULL, 0x4142A829CFD1356FULL, 0xE54C4D8C8F4B44B9ULL, 
            0xD06EF1004212AB77ULL, 0x2B90B213C02991B6ULL, 0x9189B014EC307BA4ULL, 0x2F4DF7DBE155655AULL
        },
        {
            0xCB008DD02F44BEF3ULL, 0x8DBD596502239FFDULL, 0x2C2362F72AF20969ULL, 0x41894411EF85F771ULL, 
            0x1571E6631D07F974ULL, 0x0B9972D9C9206752ULL, 0x4BB3B8BA7CBBE16FULL, 0x433FB887BEA7777BULL, 
            0xB9CEFA476DF7DB11ULL, 0xCCD3543BFD040C60ULL, 0xC562C5BFE3753436ULL, 0x9A83DC3D771887D1ULL, 
            0xAC0258A9A7890F8DULL, 0xCA019A2F01EA8BE9ULL, 0x7F69A45531CD76EAULL, 0xA4018BE1ACB2AF70ULL, 
            0x5FA09F87AE78DC58ULL, 0xBCF04E2614C8E6E3ULL, 0xF368DACBCAD5DED8ULL, 0x756C352721B5F4B8ULL, 
            0x4D75E53A520A57FDULL, 0xB1727805EC1409F7ULL, 0x396EA8A81C7B4D94ULL, 0xA3E0C0DD75DCF271ULL, 
            0x20868C77377BFAABULL, 0x14F743A15EDA6742ULL, 0xA5F0CC5D72022713ULL, 0x238DDFBF5B143003ULL, 
            0x4EFAE850D365039DULL, 0x990FD939487E29F6ULL, 0x50C3665A4A07C66AULL, 0x77DA18995FF6E319ULL
        },
        {
            0xA2BB762C08F47B41ULL, 0x69774835FAB398EAULL, 0x7278B0097D40E1FEULL, 0x9850BC4F5F0BF309ULL, 
            0x17B461BC3C1AEE57ULL, 0xFA8B3F0C2003A3F7ULL, 0x2AC9E8E9C9E914E1ULL, 0x0B8AF0A45EF75C6DULL, 
            0xE6DE285BA75F5EADULL, 0x71E62EB63B5A3C1DULL, 0xB468A8324823F1F9ULL, 0x822A77BCABA81DFEULL, 
            0x2C60186F50EA8B8EULL, 0x1E8AD4BA04DAD772ULL, 0x3707E8C2C0F94D20ULL, 0x99D1B8A8C736AB71ULL, 
            0x4A78CB902A18C060ULL, 0x9AD8E90DD25687BFULL, 0x8B4FB79263552FC2ULL, 0x1E515604E05C7472ULL, 
            0x923685E9B6991EF4ULL, 0x79E4103D2E8C0180ULL, 0xB3D12B5A0C775E0BULL, 0xCF0EE67F924982B1ULL, 
            0x0C7677D94B0F47F0ULL, 0x3122BE05870D6925ULL, 0xFA956C89CD956ABBULL, 0xAC595EA556DE218FULL, 
            0x781D0EA797922BC8ULL, 0x466E827FC37D03C7ULL, 0x28766E7C774A6CD1ULL, 0xE97CEB2CA775A5F2ULL
        },
        {
            0xFAECF36DD9C80CC8ULL, 0x6C814179C46C04B4ULL, 0x40597CC639E73D0BULL, 0xEF1D717B8D65C522ULL, 
            0xFB38A66222DA9F15ULL, 0x007EE15C1E05DF73ULL, 0xBFD4EABCFCE1207FULL, 0x0CC121B5C2BD959FULL, 
            0x02974639A0763952ULL, 0x3A46161B714D6C79ULL, 0x1378D2C28BD0A023ULL, 0xB9164C130D1554DAULL, 
            0x4E854EDA27BD068BULL, 0x1F47C76B4D0EBDD8ULL, 0xF344C23E91130C60ULL, 0x3977159330ED7FF3ULL, 
            0xF067930B4A887F3AULL, 0xBF87F03E90FF85FDULL, 0x59FEBFACB2519B82ULL, 0xEF1436D53EEE1E8DULL, 
            0x2AB45456EB2BAD20ULL, 0x28DFF61A0A37D70DULL, 0xF5ACC7AB65D4DBA8ULL, 0x1694FD7EBB4566C8ULL, 
            0x903D2DD129C42BE5ULL, 0x5BF298EBAB9CF905ULL, 0x5B725841856071D6ULL, 0xFDE24BA7F620C56DULL, 
            0x53E28084C94B4052ULL, 0x53D10186AD9CC13AULL, 0x77CED9690817025CULL, 0x6A1A527D8F488AEBULL
        }
    },
    {
        {
            0x7780B685E57B8A0EULL, 0x6E0E65374850D031ULL, 0x8407DBF425BCEF0DULL, 0xD3DFA4D6633F1C2EULL, 
            0xBCFAD747D8B52830ULL, 0xC23BC949EF58A8D2ULL, 0xD9305578B6956220ULL, 0x419F459589D2766BULL, 
            0xA081886A2D7AAFDAULL, 0x68B5D29BFB64CF44ULL, 0xFD199AE3B7AAD793ULL, 0xF87FD91209A49B4DULL, 
            0x65E4EA3BED8CFB72ULL, 0x94E000558B7B4906ULL, 0x4D611E7C39188E7FULL, 0xEC002E4026A53E1DULL, 
            0x8DB8D7434B87B7C1ULL, 0xA7093F64E4750C44ULL, 0x1B339521A0F9103AULL, 0x8EBA4FA05B6C9DD5ULL, 
            0x6F7682E590E9CEAFULL, 0x57CCC09AD4CFC2B2ULL, 0x4F86AF5FF95E4EB6ULL, 0x0CBF7CC3E981E73FULL, 
            0x03B9FF3EF4BCB337ULL, 0xB1439B5ED89DC6A7ULL, 0x357D89B5B2BB1C0CULL, 0xDF0123E261245FC0ULL, 
            0xCF899E0E30002453ULL, 0x5187EA19ACF1C191ULL, 0x8B679305C9E98DE0ULL, 0x3565B0074EE0D6F6ULL
        },
        {
            0x658BB92A6EEEF944ULL, 0x4385862A27E95C7AULL, 0x1C515F0113325F1BULL, 0xEFF419E583232EDFULL, 
            0xC2171F8661C6903CULL, 0x41C53ED7818430ECULL, 0x5F601A6ED9002746ULL, 0xAA3213F3F5CC2CC3ULL, 
            0x06725B5A54225EEEULL, 0xBF11FD8ACC88193EULL, 0x61990277D6C9EA7BULL, 0x550F8CABDDA1CE31ULL, 
            0x24345670BFC0774AULL, 0x810415CCB2327FD3ULL, 0x7BE1300E4178BBC7ULL, 0x11CD929904BF1216ULL, 
            0x25AD6F1CEA7AB1D0ULL, 0x2C68320815FBC084ULL, 0xA664BA387D93B2CAULL, 0xBF45D7F03034F019ULL, 
            0xB4F7FC479CCD0F82ULL, 0x30E09E20BC9ED790ULL, 0x1169D50A73D4FFECULL, 0x7955048BB553415AULL, 
            0xDE380A9ED53D9A32ULL, 0xDD96369013AC67ECULL, 0x812567B81677D685ULL, 0x10A35B8468A7683BULL, 
            0x5ECE3A2D7366EBDEULL, 0x67A134FEE12F5A00ULL, 0x157F949DCF941F11ULL, 0xF7F586BE4C12A9CAULL
        },
        {
            0xAEBD5CDDA15F4821ULL, 0xEB82522E527783E8ULL, 0xAD491A2C0AA15D73ULL, 0xC246C971BA9DFDAAULL, 
            0xE95CD087697B248DULL, 0xF50F76096D43021CULL, 0x19E49DEAAEBA44D3ULL, 0x30CA2FE25C5EB10CULL, 
            0x0C17A50FD7FA2449ULL, 0xFBBF09095C8C0E9FULL, 0x9257681C58FECA7DULL, 0x356EE5BF41AA6E06ULL, 
            0x39544979497DC666ULL, 0xD5C57138A9AF5A66ULL, 0x800C5DEF66D71F46ULL, 0x31A374678F6A8684ULL, 
            0x8BFED7352EBF8320ULL, 0x2DEA67BCBB44902AULL, 0xEDB61CF3B574AFC1ULL, 0x9CE9F51F2A8A8CABULL, 
            0x28B14D8A624D21E1ULL, 0xA07757318A41A7D3ULL, 0x56132991497F8F55ULL, 0x74BF2ADE9727A526ULL, 
            0xB026EEF0AA15EABCULL, 0xB07E6A0FA87276DBULL, 0x123DDCB8C81EFCBAULL, 0x85044B6CCA541E59ULL, 
            0x59933ABBB21CF8AEULL, 0xF9BA26DE85A84963ULL, 0xA1115EE7D1C43263ULL, 0x0EBB5BBEB476FFF7ULL
        },
        {
            0x18C5658A38E6013DULL, 0x078322E4AE5A5E23ULL, 0x2B633427BEDE758EULL, 0x41A9A8C8B54365F0ULL, 
            0x9DF74CBA7D366F01ULL, 0x4AEB1E402A38170CULL, 0x0EE5090EFD2277C1ULL, 0xC2F590B1EDE87D9FULL, 
            0xA826D3611867B743ULL, 0xC43B0D7C49A7C03BULL, 0x94F0FAA72A6662F7ULL, 0xDAF147BF1CD5AE0CULL, 
            0xF548C13DA93FA6B8ULL, 0x3D3C08BD7A2CB4B2ULL, 0x55D8DFF8F44B8A57ULL, 0x23AF853684D4BF91ULL, 
            0xD432FEFD17B3CB41ULL, 0x0903269AA0C1C514ULL, 0x7868568E283A38B7ULL, 0x1C41B02A77DAED3BULL, 
            0xC06F772F52A0D004ULL, 0x729BA63ECA0C20A1ULL, 0xD840A99ED24393BCULL, 0x12CF0E1FF900A7DDULL, 
            0xE68F22C79FEEB5C1ULL, 0x330AD5C7FAB3D7ABULL, 0x377A7568BCB2EF40ULL, 0x4EDE8802C9B8E4EFULL, 
            0x9E2FFB4A3CFDA5BDULL, 0x220F53B0E27F6B8DULL, 0x4FDC99372381A8FEULL, 0xD8052BD67AD673E1ULL
        },
        {
            0x04C11F28B487CC83ULL, 0xE2A08F8C7BC7D134ULL, 0x0F3CA116F00F7F30ULL, 0x10978DA24ACA7B1AULL, 
            0x90CE28581491AA1EULL, 0x8DC86724D8915D8AULL, 0x123F025930FD877CULL, 0x58478C7E1003C094ULL, 
            0xDC71E83E109663F7ULL, 0x9A0779622BF7A818ULL, 0x48F4DDB0AC302009ULL, 0xEF1155162F197E0BULL, 
            0x402DA3FDC08F8E9BULL, 0xCAC38C76940CF2C1ULL, 0xED67A3F72E10958FULL, 0x74941D596742B763ULL, 
            0x9ABC873F5E56A340ULL, 0x06AC9849F4889140ULL, 0x37509D36A9D550F4ULL, 0x7E3B43427AF8D700ULL, 
            0x9B0480921C0DD438ULL, 0x0DCB37492619D40CULL, 0x2B7E5A5F84972B3CULL, 0x6F9C132504E97914ULL, 
            0xA1516C42A15436A6ULL, 0xEBF7DFDBFA40B332ULL, 0x5997817880D29AC0ULL, 0x176D4F296A21BB04ULL, 
            0xBA3A653EC987C898ULL, 0x0609C22A96F8EE1FULL, 0x2D09580A86E6F789ULL, 0xCB139ADAECF31BB8ULL
        },
        {
            0x1728D819715EFC36ULL, 0x0A590E4D2025AED4ULL, 0xC14B95CC4F59959AULL, 0xB8DE2BA4950D9738ULL, 
            0x50763923FF22035BULL, 0x8CE3AD5D18C43899ULL, 0xC169B1E9D8DF7C50ULL, 0x4383308936B56079ULL, 
            0x6F1EE821BC15EE50ULL, 0xDA396F91FE8C1532ULL, 0x0C8500CFA53E9C07ULL, 0x422A36E8D8526E17ULL, 
            0x1B7747B223A465A5ULL, 0x224245A0806E1EBFULL, 0xFA9DE56448C277D9ULL, 0xB10714E3D3E608F1ULL, 
            0x5D73DAF930B0901CULL, 0x41514E281FD811E5ULL, 0xACA17753E16C9AFCULL, 0x147A048B48AC3CF4ULL, 
            0x84A4FEF009A1AE64ULL, 0x7984A71C85458C65ULL, 0xF2B96A177C1F5382ULL, 0xC6F77D743A4875A8ULL, 
            0x360C10F8F19C8F3BULL, 0x4814722EE65AD27BULL, 0xA7537550E422AFD8ULL, 0xE62A71747E066398ULL, 
            0xD44B55AE079F9461ULL, 0x3BF2D62D82D20F15ULL, 0x84E69F05EE9313DFULL, 0x1D7A46B059F38DE2ULL
        }
    },
    {
        {
            0x30300A76944CED7FULL, 0xC033B3641F325C08ULL, 0x6027ED60B8F345F3ULL, 0xC47CC49DCB1A7543ULL, 
            0xDCE2E6CD48BA517BULL, 0x4E10F0775C50D2F5ULL, 0x69E47D9BF6E76F4BULL, 0x2312F1F4E0E99BF8ULL, 
            0x157D61758EE373E8ULL, 0xC83E1112774DD189ULL, 0x9938A101F62BF8A2ULL, 0xD87E6D25D093DB7FULL, 
            0xB3570EA8FB11EAD4ULL, 0x76276DECEC5A3E42ULL, 0xBF5F0ED77E3E242FULL, 0xBE8F1488632F95DBULL, 
            0x000418ED95036FB2ULL, 0xE6FE4EE9DDE28749ULL, 0xE0FB4CEAF043BBA7ULL, 0x86BD5397BBB4AE46ULL, 
            0xF0019C35F38C1865ULL, 0xA2A441ACE868094BULL, 0x9FED93C0437B7F8EULL, 0x4A605B7E98FF900AULL, 
            0xD9EE9C220D44DA8AULL, 0xFA82267115BA88CFULL, 0x42C6EA6B90891AC6ULL, 0x530AD413B807FD9EULL, 
            0xD94CE283D23914C6ULL, 0x4FD7E474566860B6ULL, 0xA24E31120CF59416ULL, 0xE3260FD06A780C69ULL
        },
        {
            0xB16C17D40FAF9274ULL, 0xC0571A6F9261ADCEULL, 0x3BF99F640D545FD5ULL, 0xF99A9DE64DCC4824ULL, 
            0xC6D5EB4A18E53502ULL, 0xE8555CFE1CFF9E27ULL, 0xED6517451E0A0E58ULL, 0xE20280A553DAB73CULL, 
            0xC490B417C063DD34ULL, 0x0DC16B93C24DA4FCULL, 0x7B37D2DBDB703F94ULL, 0xF0314FCE1CF52041ULL, 
            0xAFC3C07C190D5FC1ULL, 0x74788ACB61F3F744ULL, 0xD9E35BE8E17D4D0CULL, 0x02C544417724ACA8ULL, 
            0x5866CA418993CA14ULL, 0x7F28831CE08ADB59ULL, 0x594DF5D7E1897421ULL, 0xCC937B86E0BA6787ULL, 
            0x9A5BD00B996D2970ULL, 0x9A3FFD2595B6EBD2ULL, 0x8506EB94CA2AA9A0ULL, 0x4750F849805B40C6ULL, 
            0x60B5A86FF7F29553ULL, 0xB14F2909B29EC4CEULL, 0xB52227A53F43C11DULL, 0xC3ED395EC50F7E90ULL, 
            0xD18B5622261714C0ULL, 0xEEFB45F22234996EULL, 0x74905BE780A598E2ULL, 0xE7560117B93C63BDULL
        },
        {
            0xEAEF4283F9699485ULL, 0x1F7D8F5AFA147636ULL, 0x3A88B66DE32C2223ULL, 0x6C3C8656A65E6D49ULL, 
            0x3E5FFD773FE8747FULL, 0x6C7145A65CB7EAB6ULL, 0xEEFA703DCCEACB73ULL, 0x168D66372FD41700ULL, 
            0x9F8C627584D1A96AULL, 0x9CCF401E275C87F4ULL, 0xFD016FC6B5D6D113ULL, 0x5DA419F4BDDA4D05ULL, 
            0x301BFCD8D8B0A01DULL, 0x405647B276245AB0ULL, 0x46DB4CE86BE228F1ULL, 0x1E151E70BCD28A55ULL, 
            0x3D4D37589D58AC05ULL, 0x5D1BB7A635005EA8ULL, 0x7483395D78F56425ULL, 0x997A74D6ED779FF6ULL, 
            0x7FD7ADAFC76CD46EULL, 0x1FAAE39161C67A21ULL, 0xDF1ECC3F947B1657ULL, 0x79838C98C30A99D1ULL, 
            0x153236CC73194D59ULL, 0xDD0F926EBEC882E2ULL, 0x9744958FC1C6076FULL, 0x70E5F0BA567B106BULL, 
            0xB4BC0BE35C457A14ULL, 0xA7BB396B3058E31EULL, 0x990B75A50A9BC56AULL, 0x096DCDD872EACCF2ULL
        },
        {
            0x38DA9DC3547E2ED0ULL, 0x3D123995600048BCULL, 0x5F2060F49CEA8887ULL, 0xED14371B585E3B38ULL, 
            0x497F26F404A11044ULL, 0xE5CECDE2D7D2E548ULL, 0x748A3CC1E4F04F86ULL, 0x700254AF8E59060EULL, 
            0xF37AF9EF3FEAC2CEULL, 0x3149C7C368B37249ULL, 0x759C0DA680A6EC46ULL, 0x6EDB77F7B6183E10ULL, 
            0x9C57D918F149444AULL, 0x83785BFC092045F7ULL, 0x523570AE1FD857A3ULL, 0x041B9A31D1F659D8ULL, 
            0xFB457CA4F257B683ULL, 0x540A6B23DEBB9E30ULL, 0xBA5178A5D8714621ULL, 0xDD178730D2491847ULL, 
            0xEA30F790BC6FB23FULL, 0xA0DCB9050CE1FC8FULL, 0x9A82B796211805BAULL, 0xC69BC5C651A14DE4ULL, 
            0x57B834806DD522B5ULL, 0xEC6B39CF2D86EF29ULL, 0x4BCBE1A32A32E0C5ULL, 0x5E25BFB40F534D51ULL, 
            0x5C7F6826F1E58DB0ULL, 0x4E69E89485F02428ULL, 0xFDC9EF761AE88E05ULL, 0xE75970632610907AULL
        },
        {
            0xBE8F012DF8A77195ULL, 0x56CF210A0D9CBA09ULL, 0xFEE83DF75911114BULL, 0xC7E3B93AF4117736ULL, 
            0x2DA5BB97684804E4ULL, 0x7DC0F3735CE7572DULL, 0x5FD0A5FF171E04DAULL, 0x12D3B197718FC5DCULL, 
            0x3534E0CB6EA90CF0ULL, 0xAB9341E5EF8B5062ULL, 0xC44F4A6B8085C551ULL, 0x358D47B6FDBBC957ULL, 
            0xC513B82E27A3EEB0ULL, 0x34D3C571BBD13319ULL, 0xB2CB41EED22B1E4AULL, 0xA4C75D9AF5698B2EULL, 
            0x52F51733BB035E32ULL, 0x39EA14054E831E2CULL, 0xFF74508B7386B604ULL, 0xC7182F77B7FCC3CEULL, 
            0xC9E4D8628EA001C8ULL, 0x92ED03E95CD94A11ULL, 0x3A42374C79BF1707ULL, 0x9B72D1A32B8232B6ULL, 
            0xCA523D251AAA3060ULL, 0x1B70EB6ABCF08252ULL, 0x7CAF7082CFF02DFAULL, 0x82C1C547793A2840ULL, 
            0xAF4C4C75C29E3CC1ULL, 0x38CF9C5DD25EC46BULL, 0x2F6644C91E1A8093ULL, 0xC251982F161502B0ULL
        },
        {
            0x55DFF81C665283E0ULL, 0x103EB11A7E878C0CULL, 0xF569FA9B88224E67ULL, 0x573C6D48726C6E9DULL, 
            0xED5F66F52912A6F9ULL, 0x8EEE4CC24DBABB53ULL, 0x615129BB3DE4D7B0ULL, 0xC7E86B144FBC9B57ULL, 
            0xD0FD47E53ADE1122ULL, 0x43220C92A301E664ULL, 0x8E66427F3D94E89DULL, 0x548F0D29ED9326FEULL, 
            0xB3C60A6CC67AA9CCULL, 0x4AFF51BC7D1F151BULL, 0x2214CF9361EA94DBULL, 0xBC90031E02A18024ULL, 
            0xB08953D557B73544ULL, 0x050814997702E829ULL, 0x5D597617AB1F00A8ULL, 0x655031E45F1DF9E6ULL, 
            0xAAA1383E6FEBDBC3ULL, 0xB6B2FD1A9B1CCE6EULL, 0x88304E38E73DEFF7ULL, 0xA685580D2AD6EAAFULL, 
            0xFEF6E9B644A21E34ULL, 0x7C4BDE010E4DF1FDULL, 0x7AC8B8A292E868AEULL, 0x68BAF47999EF96A5ULL, 
            0x9F6499507D05FA0FULL, 0x4518ECC841871130ULL, 0x5AFAF28255E93F74ULL, 0x55D7C2E6144FD717ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseEConstants = {
    0xCE6C7B1786078A71ULL,
    0x86CA1259839AC3FFULL,
    0x4A405D2E2A6BBCAFULL,
    0xCE6C7B1786078A71ULL,
    0x86CA1259839AC3FFULL,
    0x4A405D2E2A6BBCAFULL,
    0xEA7E329AF220DD63ULL,
    0xFC44FAADC30DBDD1ULL,
    0x60,
    0xA4,
    0x67,
    0xC0,
    0x74,
    0x3B,
    0x8E,
    0xBD
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseFSalts = {
    {
        {
            0x8E5BE8FBB7D2F18DULL, 0x928A13A65188AE66ULL, 0x684AC66223680590ULL, 0x236F5AD8E0ECABF1ULL, 
            0xEFB6E63DCFE965C9ULL, 0x789E4D9A4E8E71E4ULL, 0x84EF8D86ACE8BC47ULL, 0xB83918F7035B9225ULL, 
            0xCD39EEEC5834680DULL, 0x4AE4508D4EB10FAAULL, 0xC41D51DB13791476ULL, 0xB34C89B222CFB433ULL, 
            0x657B3F0A880AF439ULL, 0x906FA6ADF3B93330ULL, 0x6EB942F78D066DAFULL, 0xDFF34AEC29064AB3ULL, 
            0x05F63FFE2E0922F6ULL, 0x249141E4CC5ACAE1ULL, 0x6E63681A88F5B227ULL, 0x5E9F77B5C10BF4C9ULL, 
            0x8F641A779DAB59C9ULL, 0x07C165DD4821313FULL, 0x9F4C8B7497B92DC2ULL, 0x8A147F850FB87B83ULL, 
            0x474020AAC8C4A51AULL, 0x359A179118DE4C82ULL, 0xE3DBC97691F5B4C7ULL, 0x79C3EB4EF5792AA2ULL, 
            0x24762A0617E9F7DFULL, 0x0781D67CD151F675ULL, 0x7BC9529944AB5138ULL, 0x7C206CBC59ECB06AULL
        },
        {
            0x74306906562AA2CBULL, 0x783CAEDBF4CAD924ULL, 0x173475214F17F796ULL, 0xFD25F44E57762B73ULL, 
            0x3E57CBE24E52C733ULL, 0x41AC0EA835896392ULL, 0x04570C5F651DD972ULL, 0xADB047E437ABDAF0ULL, 
            0x77914A0E13C90B9AULL, 0x8CBB83780FA88D17ULL, 0xD5630869F1AD61B6ULL, 0x74E34757319AA6A5ULL, 
            0xE82384638A52950CULL, 0xB9E464730B35C9DEULL, 0x8E9D401D3F196FD4ULL, 0xE6A024070BA95471ULL, 
            0x068255EA507F7C3EULL, 0x7174D84FBA4B41F3ULL, 0x1D38105027133944ULL, 0x9131DDAFF868FBB5ULL, 
            0x91425C06218CB0ECULL, 0x91A2F2E16E89C306ULL, 0x189F948CC82E99B5ULL, 0xABE7500510A4CB8BULL, 
            0xF9FEB75B07D8876CULL, 0x1E7104993CACB61DULL, 0xA1E5741F12824865ULL, 0xC0CF02F07E846101ULL, 
            0x2F6552D26B342830ULL, 0x1D0B9848BC127002ULL, 0x844399F34A57601FULL, 0xAD9A039A7BBC1192ULL
        },
        {
            0xF4ED407A36408B1FULL, 0xC22D61B6EF4F2B3FULL, 0x02C4E839C8759A9AULL, 0xD6E9A22C3CDF2733ULL, 
            0x8CC2970487C87CC8ULL, 0x2465D46FA4060761ULL, 0xA4C9D2432A1F5427ULL, 0x2FBBB94F184EB984ULL, 
            0xC968F8B9F50EF702ULL, 0x7FB98FD9DD3707C8ULL, 0x1D4249CE0CB7E692ULL, 0xE08B0F5367482B41ULL, 
            0xCC72D3DB8038766AULL, 0x39AB5DFF90D00143ULL, 0xE218A94AEC4E0693ULL, 0x90CD26F6FA20BC1BULL, 
            0xA744E2A5C5082F88ULL, 0xBF45B918C06BE13EULL, 0xC4BAAD0D48FA19CDULL, 0x1ED9387307AC26B9ULL, 
            0x7EC0A464A2E91925ULL, 0xEB28A36CE5DFF030ULL, 0x7C410735E2498E3BULL, 0xE14D41CCE102AD9FULL, 
            0xD2454B0A7D6065D9ULL, 0xACBDE2856EBC529EULL, 0x475907820C6D4187ULL, 0xDA624DCDFB2E2C9BULL, 
            0x390325B01D413EFFULL, 0xE78B768E228F1417ULL, 0x42C506C0B28E2918ULL, 0xBA7B1B2B023DDBA0ULL
        },
        {
            0x02C25EB0B69157BAULL, 0x728F83495FFB4EC0ULL, 0x03B622E205992056ULL, 0x4BDCDD956DA1DC36ULL, 
            0x42B896956BCF558EULL, 0x770B59390F649372ULL, 0x5BEF758B449C61C8ULL, 0x875FA5F21D8BF00BULL, 
            0xFB3AE9E97C2504C8ULL, 0xCE5CFF43FB654997ULL, 0x0152A14C5CB7534BULL, 0x1A544BC9E7BA6AF0ULL, 
            0x68C014AFD8685A80ULL, 0x0D4AAADC033550BBULL, 0x41B20AF17304205DULL, 0xC304A7768C61DDE9ULL, 
            0xF9C265254A5945CFULL, 0xEFBF4E7FDE4472EAULL, 0xB80A0AC15D9B9A73ULL, 0xD7937B3E1AAA199AULL, 
            0x90935A7A4A171A92ULL, 0xBF8FD8D3C47CC501ULL, 0x4138F63A44790F19ULL, 0x48A338E20C063246ULL, 
            0x04B50AC7745F9D9CULL, 0x8E558E8AB3469A25ULL, 0x73FD2EA8DAD4C113ULL, 0xAAF679BAF58D4F93ULL, 
            0x363617908131EAD0ULL, 0x2057611A75843B7DULL, 0xB2E495AC1CBB6F92ULL, 0xE709AAC47CE6A936ULL
        },
        {
            0xA65AE2DA9CC40EFBULL, 0xD18F993A3DE07368ULL, 0x2E131F598BAF44D7ULL, 0xD30AEA132E829163ULL, 
            0x8084251958CA5990ULL, 0xA0000AED21175579ULL, 0x3D83AB2872CA8F62ULL, 0x08DB0B2282F64463ULL, 
            0xF111AC6870A1E191ULL, 0x71A41706394288C3ULL, 0x070BFC7D07592B14ULL, 0x22D0D17CA7FA8CB9ULL, 
            0xE3C4232EAD774B34ULL, 0xB82552193858B61EULL, 0x2C6C9FF1C667608BULL, 0xC981A42B9F705CB6ULL, 
            0xB072EA47DFAA9C38ULL, 0x810B2BB2ED177384ULL, 0x9B57671D21135E07ULL, 0x56B9AAB164C271EAULL, 
            0x390B21EA5593C5C3ULL, 0xF606DC073C94F6CCULL, 0x013D3E8906829BB4ULL, 0x087B417DE65E06C5ULL, 
            0x57C949E84E651482ULL, 0x26E69666B6081F40ULL, 0x79272B7295EAD23DULL, 0xBC17271495E93FF3ULL, 
            0x20001DDC7AFA959CULL, 0xE760CAE88A6B62A9ULL, 0xF40E5049EFF6C22DULL, 0x249E8C9170550069ULL
        },
        {
            0xB3DA5E183A647779ULL, 0x6D7117A6B686F480ULL, 0xBA3F622F8C328403ULL, 0xEA23FF96C3D5DADAULL, 
            0x0D0D3D5C813A9F56ULL, 0xCC12B8D953F2B246ULL, 0xAA9682A8DEB5A9DEULL, 0x8847D7506841FD22ULL, 
            0x51224969893633A8ULL, 0x84BFC1A8A5C5154FULL, 0xB9A1D462DA608DCEULL, 0x9105984410789B4FULL, 
            0x80156274A09D68D1ULL, 0xDA30BA4A8B1405ACULL, 0xF3C877926A2E58E2ULL, 0x1FD8ADAF917025BBULL, 
            0xD7D05AA905C78F6AULL, 0x5E58DAF041FF6119ULL, 0x01C16CA16ACF3090ULL, 0x2B73194C35E1E1FAULL, 
            0xC5EBC7D367E42F03ULL, 0x5C615123317C576FULL, 0x70109DB0D441B4F2ULL, 0xF5E3BF51E542595EULL, 
            0x96D8887CCCD7C10EULL, 0x0F967315275BC18DULL, 0x22919FD59E7ECDC1ULL, 0xC55AB3563FABAAEFULL, 
            0xE9C34D37409458E0ULL, 0xD5BA36365527F7D8ULL, 0x1E64C82B6319567DULL, 0xBF1AEC9A80138957ULL
        }
    },
    {
        {
            0x19CC784F38AA6076ULL, 0x4ADE21A96F6BC25BULL, 0x612F34B7F55273D0ULL, 0xA14AB6A16266A7BFULL, 
            0x63D8B481EEC2AA91ULL, 0x927C059FB1B74CBAULL, 0x041D0B78F700BF84ULL, 0x20E493FFE8B4BDA5ULL, 
            0xA418458EB9C65240ULL, 0x71E02E6F0A114909ULL, 0x0F88637391E3A10CULL, 0x2A43DF1BB8DF8623ULL, 
            0x41F402ECC2C8D7ACULL, 0x0FA55A48359F5D57ULL, 0xD72B0E50426D84AAULL, 0xEF2BEA2A5E324523ULL, 
            0x3069964B9A4C61FAULL, 0x1634FB2510C5A183ULL, 0x544FA2BE83470594ULL, 0xA44B078527D65594ULL, 
            0x5D0175D4C48271EAULL, 0x40838C6E035762B1ULL, 0xEACEDE4F6614868FULL, 0xDC4659CB8C8F335CULL, 
            0xF8CF10656E184F23ULL, 0x582F2CE3CF22B079ULL, 0xD25452BDE63A36C3ULL, 0x354B578AA38979C4ULL, 
            0x39A77D784011B1ACULL, 0x6DA1E7F3650AD713ULL, 0xC4D153A547994CA8ULL, 0x8BF452423D2B29C2ULL
        },
        {
            0xA63B6D442F384841ULL, 0xE5CA8DA0CD683B12ULL, 0xE75D9A9790AF806FULL, 0x01052E8C0A57CA11ULL, 
            0xE4B5A074E40DEF00ULL, 0xE280124DC06F63ADULL, 0xEC956EA9FF76DA18ULL, 0x2D8E862BD868D5A7ULL, 
            0xA6B8B9A17329B4EDULL, 0xB9BAAB1EC9EE592EULL, 0xEEDB06DE068B9A98ULL, 0x2958F89D00AB4A38ULL, 
            0xA949310B92540456ULL, 0xC979CDFA01FCE23AULL, 0xEBB89938A6DDBAC6ULL, 0x53CECB9EE3564EB2ULL, 
            0xD9B6234A11A618FFULL, 0xFD313017E17F9AA1ULL, 0x3B5386A3998B648FULL, 0xE1A38E01FC69A438ULL, 
            0x4382BE0A11C293FBULL, 0x09B3EA1A50FCBC03ULL, 0x457A364E2D14AB45ULL, 0xB6DE1A51E4159D1AULL, 
            0xBB6E77AD6E2DA94CULL, 0x8216EAA787768D8DULL, 0x1BAF53975DD8EDEFULL, 0xB65ED2A1755280DDULL, 
            0x9732B9DFBAF5ACE4ULL, 0xCC6577FD978C4526ULL, 0xF34FA445605FB5C8ULL, 0xADA59CE712646537ULL
        },
        {
            0x02AC59FC4DD551F4ULL, 0x18C8F64F3A49E8F7ULL, 0x49AB20CE280E8160ULL, 0xF0552A1B1C123339ULL, 
            0x3FE8D36FC69A6DA2ULL, 0x7553A58618CA4DA5ULL, 0x8628F71F29B2BAFFULL, 0x4E82414A8A8F71E2ULL, 
            0x7D1B56C7C59333C1ULL, 0x65393EE3D6AF9AD8ULL, 0x451247EE3C01744CULL, 0xFD1CB3622333090EULL, 
            0x23CBD85A21FA0B8AULL, 0x66829F121DD794A0ULL, 0x89AC0803687635D1ULL, 0x3E4CAD001C7EF1C0ULL, 
            0x29C9B40A7E9E2F4BULL, 0x94D19B73752E7470ULL, 0xE0428CB5BD9BECC9ULL, 0x87D5CF15D74E7E18ULL, 
            0x8D2D0687C6AC4FA2ULL, 0x0034135FDDFEF784ULL, 0x1D4637330D49CBA6ULL, 0x8BDBDBF311F76AA2ULL, 
            0xF769EFE9AC56B7EAULL, 0xC32A0E1B5E8C0FFAULL, 0xF9A16AB30750C807ULL, 0x47031CA67DE734C0ULL, 
            0x68F842A2F4591457ULL, 0x796B30C40BBDFF02ULL, 0x3F6E7676A2535842ULL, 0x6444C91A38AB79FDULL
        },
        {
            0xE04565774B5388CAULL, 0x5CB50FBE84BF3582ULL, 0x0E9E7A10F67D1FC9ULL, 0x926E6DEE31DBF89FULL, 
            0x267DB6172193AA55ULL, 0xB929E7F7493615A7ULL, 0x2A5F45207659BC80ULL, 0xBF0C7447E4C91124ULL, 
            0xD319C22A675EFAFEULL, 0xDB7D423A4718C52DULL, 0x6221681F6352660FULL, 0x3EDE5465E7A9C993ULL, 
            0x79C3E76083DE57F1ULL, 0x863E06E3AD28AC82ULL, 0x2FA959917792314AULL, 0xBCE04A5AC71B1D01ULL, 
            0x4D720955466B6A54ULL, 0xD1B46D0819FB972EULL, 0xA5DC7D2C8A634D34ULL, 0xA0C38BAB7237A3C9ULL, 
            0x7FB7B1A61191F690ULL, 0xEB58BFFAC661BA12ULL, 0xC0AF2CC1EFD9561DULL, 0x1B08ECD621CAA688ULL, 
            0x4E802981F8E82E44ULL, 0xCFA0ED662B54E8F2ULL, 0x84B1955F53BFAF38ULL, 0xA72E6D52C44762E6ULL, 
            0x88E857D370B84EC4ULL, 0x700C0B4FC1A284EAULL, 0xF89D07E2ADF060D9ULL, 0xA928CFC9A11855B4ULL
        },
        {
            0xF67C99395DAA9AC9ULL, 0xBB8C11C3D07D9A8EULL, 0x63BF0D978373F513ULL, 0xE91F5B387978EA43ULL, 
            0x3B59D3976E03F0E2ULL, 0xBF33EBA00EAD77C7ULL, 0xC77843FA5343C356ULL, 0x36D187B2CBDAAC71ULL, 
            0xE95332BDE20A22A6ULL, 0xFFFC43CB47220D15ULL, 0x6976E6A222415599ULL, 0x34C0750AF387A1C0ULL, 
            0x0465C0D836CF1C8EULL, 0x6222E2F1586B0CA2ULL, 0x15213C38F4FA0C35ULL, 0xCF12FBA4068DE026ULL, 
            0xA4C65772F72C9966ULL, 0x2E5BA8ABAD5E4ECDULL, 0x3A2298D5F0DED03CULL, 0x5D322E932EF98493ULL, 
            0xF0BC7DCAC604DCA4ULL, 0xA7758036F0BBF851ULL, 0xEC4FBFD35E53FAB3ULL, 0xEBC2F48AEC9D2816ULL, 
            0xE8E904C2C3684D95ULL, 0x503B57A69B29409CULL, 0x911AB6DF48CA5590ULL, 0x6E1DE4B0ED03C789ULL, 
            0x9E1AD4B3DF86B922ULL, 0x7753B97DC2E19AA7ULL, 0x2E6AD8C3C1924248ULL, 0xB211BCCA85FD093FULL
        },
        {
            0x62F4D7117A7A22E5ULL, 0xD9653BD6F57844D2ULL, 0xC0CD32C547426CE7ULL, 0x74C610898921281EULL, 
            0x29DCB65EBA5FF612ULL, 0xEC3E46F8CCF1060EULL, 0xA1B36501B1B9DBF3ULL, 0xCBA262B45EFA4626ULL, 
            0x90805E0AF7342A97ULL, 0xEEAFDF1AA595416FULL, 0xFA74140AC5C378D2ULL, 0x052187BADF714154ULL, 
            0xB2370F7EF89F3E38ULL, 0x3F302CCA08EB68BEULL, 0xB96468F3F707A215ULL, 0x382D90BDC7EFB9DDULL, 
            0x610D801C9DB9F697ULL, 0xCE6474BC039ED07FULL, 0x310165CCC816AA90ULL, 0xF69691AF5A896F3BULL, 
            0x99067624300B9D45ULL, 0x38DDC4292C984C3DULL, 0x28A469A4658178A0ULL, 0x06681632025FF3E0ULL, 
            0x4D1A08531154E4F7ULL, 0x240947F5F11F3D81ULL, 0x6FBDE0B555002166ULL, 0xBEFB78C3412C2A7DULL, 
            0x2D9124037C6DAC6AULL, 0xAB81041B6F9CC449ULL, 0x34CD985AC62C0AA9ULL, 0xA63BD8170CC730C8ULL
        }
    },
    {
        {
            0xD73021B6243186AFULL, 0x0144582AEE1152DFULL, 0xB564B436FACB30FFULL, 0x8DA2E03BF1297C4BULL, 
            0x9934B8ECF0FB73A9ULL, 0x712ACF53B6CF5CC8ULL, 0x77FEA87208037E3BULL, 0x527D6BEE12B9669DULL, 
            0xD68FDC7FF453FD20ULL, 0xD8443D2CA33947E6ULL, 0x9470B3D0E393BEACULL, 0xA47D600A73247A6EULL, 
            0xBF522890CB757B64ULL, 0x5C5E3F8AD10902E8ULL, 0x957DF0269E42F8DCULL, 0xB77FE35D191D9109ULL, 
            0xF4992723364F7E64ULL, 0x63784E96AE08C5E8ULL, 0xC8D433A492A3A7A7ULL, 0xC15216128332C89DULL, 
            0x8582AD2848900062ULL, 0xA4FE656F68806DF5ULL, 0xCDE7E5D4BBCD2ED8ULL, 0x28DEC930BC1BB496ULL, 
            0x62F9D997E42CEC9EULL, 0xE55B642FF2B0B370ULL, 0x505C77C8010723F6ULL, 0x5DF7C745FB4883D4ULL, 
            0x8B78C85E6CDC5AB2ULL, 0x175CC8E015AD5D21ULL, 0xBDB0126BB2921656ULL, 0x4A62F4118538026BULL
        },
        {
            0x902A269487DE1071ULL, 0x1577527A821F92CFULL, 0x5FE76E517693B0CCULL, 0x459B2B802E64074FULL, 
            0x8100E1E416B59FAAULL, 0xF50BC97A277AFFE7ULL, 0xE1298E3EC6A335DFULL, 0xD724F2ECF9539DA7ULL, 
            0xAED93E87A6D37CB6ULL, 0x838F94376C383D31ULL, 0xA03C261BE37D447AULL, 0x31978F37577F1577ULL, 
            0x78CA22D61F29C25CULL, 0x6526976E0E366E02ULL, 0x9C5FFF4C5E438EADULL, 0xD90F2F2B7B0D1B58ULL, 
            0x8D3E7F2EA87F52AAULL, 0xAEAC9005D6F5185AULL, 0xB2A9C853B7988A3DULL, 0xC43BC029EF8718C6ULL, 
            0x01501B0E4261FE70ULL, 0x7E9A9355083F2C8FULL, 0x65A99D1ADE035290ULL, 0x6808A17503178FE1ULL, 
            0x2B0BC76207A5EADDULL, 0x451FE8685FFF1703ULL, 0x0CC0487CC6AE87D0ULL, 0x42528F72D4CE963CULL, 
            0x700B0F079E9FC8E7ULL, 0x99DAFE182D26D8C7ULL, 0xD6DC3BAC68EC1010ULL, 0x85DD2E3B10E328DAULL
        },
        {
            0x82E538DE8F7B8CA3ULL, 0x83115EDA98C36E16ULL, 0xCC46428680B53DB0ULL, 0xAF425E90504D7405ULL, 
            0xE565977F43A14B48ULL, 0xFD4BA8E787FEB5FDULL, 0xA0541134F87BBAE7ULL, 0x2D0038507905ED77ULL, 
            0x221561AA4FD483F0ULL, 0xCD0770E69134DE73ULL, 0xD4253F0D9792FF64ULL, 0xD3F1EF64A9E3F401ULL, 
            0x7F574D3EEEE33FB8ULL, 0x4DA5551B2B9E2A97ULL, 0xBED43665CD873AB5ULL, 0xFFFB0C146E26F784ULL, 
            0xEB537056B8751516ULL, 0x42CB76F5FC3FE021ULL, 0x50008A9DD9479F05ULL, 0xEDCB9ECB4C432F61ULL, 
            0xBA95B3ED57786929ULL, 0x9A6C762BF39D8E0EULL, 0xD4210A3F2D27DF92ULL, 0x8F472C8EC9343398ULL, 
            0xB7930A3666CDB12FULL, 0xAAF41DD90F69C823ULL, 0x158B9CEEABF172CDULL, 0xEAAA6B0E078E023CULL, 
            0x309460B86B01E1A6ULL, 0xD0705A7559C439C5ULL, 0x440822ABD9BA33E3ULL, 0x8CA77A420BB9B380ULL
        },
        {
            0x3BE37AD2213B1C6BULL, 0xE955E90A6BBE28D5ULL, 0xA836484AF2BFE16DULL, 0xCA8CA92E01AFC606ULL, 
            0xC3A1289E033637D3ULL, 0x070A384BDE8C8537ULL, 0xE2CAD4FA7F575DBBULL, 0xFBFEF11D03573DD3ULL, 
            0x2E7F3550AD7FB245ULL, 0x2E15C42D331F68CEULL, 0x69C2FE5C03FA3A9BULL, 0xD8986CB160DE79CAULL, 
            0xE59C1DAD6B61B842ULL, 0xB1043CA570FADCEFULL, 0x0E5C778A526EB7ADULL, 0x6CE942426BE9F119ULL, 
            0x6B9D1E39831AAD4DULL, 0x0A484B5E94F7536AULL, 0x8680D293398793E9ULL, 0xA7BE57D2C062F358ULL, 
            0x62B4CCE907005C94ULL, 0x454720CACEE39638ULL, 0xB2669C8D1F641C0EULL, 0x7D835B6309171CFBULL, 
            0x4F39EA6E23705A17ULL, 0xD57A2F927F09FF04ULL, 0x1B050B1DB17C1AC3ULL, 0x17D57E7DE20EF311ULL, 
            0xB8EF8B612FDC1240ULL, 0xDED996217B0EFE4BULL, 0xDBAA68E556A58CFAULL, 0xF547A0672A60A998ULL
        },
        {
            0x6F9FE0C6E0705A89ULL, 0x2BD232369A99EA36ULL, 0xAF7FF58D4F15FD22ULL, 0x849AA577487A8886ULL, 
            0xFEB4C5FCFC3966DEULL, 0x3ED51FB4390F04F8ULL, 0x22B9ADD9DA06B372ULL, 0x35E66CB27C3350D2ULL, 
            0xAA6DA44095C9D804ULL, 0x6456AD17AB8C0735ULL, 0xEC14240C338C7AD6ULL, 0x484E15E65AD5F959ULL, 
            0x85D85F4F84CB66D1ULL, 0xCEA2F3B1ED132410ULL, 0x2616BF5D606D3DD1ULL, 0x3A9E90E71628023EULL, 
            0x11F1C651F464D75FULL, 0x2690C357922B3431ULL, 0x1E361FF6C1429EA7ULL, 0xA3450361444C03F4ULL, 
            0xE318857C646A5B8FULL, 0x8983B0647AF35B43ULL, 0x5ABCC44F1C8B2C78ULL, 0xD887CBD2842AE6FCULL, 
            0x7AC487911CF7B8A6ULL, 0x27D20ACE805401B9ULL, 0xBDD969C10DD32007ULL, 0x55B723B335B3CE4CULL, 
            0x348F0D1AE792C798ULL, 0x8DC5AF68BA439672ULL, 0x5343BF94B5699E79ULL, 0x969D1F914B91AE49ULL
        },
        {
            0x54998E90303164E3ULL, 0x9EE1FA644173B35FULL, 0xA7EF7B0C1ED36C66ULL, 0x50F71EDBEDE63605ULL, 
            0xE74F4EE76281C154ULL, 0xB994E78F819C8ECFULL, 0x17D731BD84776954ULL, 0x073BA33A672EE2D8ULL, 
            0x0FD57037A7FD2B19ULL, 0xFAE72383E734C5CEULL, 0x5740D8F67D66567FULL, 0x84B1FA743CD3D7C8ULL, 
            0xABF09B554C6A78CFULL, 0x7979EE4109DD3CFAULL, 0x41EB2FA4100D7D17ULL, 0xCC250F10EA3DD5C4ULL, 
            0x44ECB6E81922691DULL, 0xA2EA2E3249BD6D29ULL, 0x53366BAF09D79DA3ULL, 0x3AFB8C6BC5A1170AULL, 
            0xBEE04D49163445BDULL, 0x82E8DC092960EB76ULL, 0x9BFB0D1E835E4E60ULL, 0x76157A8F29E4E20BULL, 
            0x3ECD9AE70DE6E3FDULL, 0x2AD531C19B9C7C0FULL, 0xA3157EDEE618011DULL, 0x2E2BE2823BEF0F3BULL, 
            0xD48BC7BF2012A0C1ULL, 0xF32822C501D796CBULL, 0x4F110C9C104C5A2BULL, 0xC92899E61CE6FEA5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseFConstants = {
    0x13670A6FC1B9C3F6ULL,
    0xE441FD78DBF38731ULL,
    0xF43A1053F5C80922ULL,
    0x13670A6FC1B9C3F6ULL,
    0xE441FD78DBF38731ULL,
    0xF43A1053F5C80922ULL,
    0x45E99E20AE12C1CEULL,
    0xA740F8AD2820A878ULL,
    0xDA,
    0xEE,
    0xBD,
    0xF5,
    0xF9,
    0x7A,
    0x81,
    0x16
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseGSalts = {
    {
        {
            0x21CF3F85BB828A92ULL, 0xB0539BFD8DB8FC02ULL, 0x0002D23AC85A9EFAULL, 0xD4BD52A0789B9777ULL, 
            0xBACC288A9E746494ULL, 0x1A7E0AC629077297ULL, 0xC34365F3B0595BBCULL, 0x11D0FE0CBEC4D14AULL, 
            0x4ADE97023DEFCB0EULL, 0x64F513E40AACC847ULL, 0x8BF48F3F3D0C3301ULL, 0x59504E5A83FC3827ULL, 
            0x2B34B19FF5EFE0E1ULL, 0x584289D2D4D78BE2ULL, 0xA3BCCBDBB7D94AEBULL, 0x0A46D0935E3ED65DULL, 
            0x7772F6D1DBFC0242ULL, 0x75F468A5F60AF1DAULL, 0x1ADA177AC311D0BCULL, 0xCAFDE3674BEEDADAULL, 
            0xEB1F070E6E9F7531ULL, 0x6630A609E4127534ULL, 0x4E92CDA6FD94753EULL, 0x0233709CA67294D3ULL, 
            0x0BB7E590B1A20896ULL, 0xA72160E1554515B9ULL, 0x0B6AC45EC89D672BULL, 0xC2B85F8D7B3EB2C8ULL, 
            0x6C5426AAFDE49B8AULL, 0x93D586C9D2B8F354ULL, 0xF5165D22A365FCEFULL, 0x8544C5A662F215DAULL
        },
        {
            0x485B60C7CB3C4053ULL, 0x2AFBF32D849D9248ULL, 0x4DE1D40B678300E9ULL, 0x69B64ED51174202CULL, 
            0xBF2B942B16DB0C00ULL, 0xE142C918BA0B0D68ULL, 0x44E051FA45A35221ULL, 0x3E846CE955960462ULL, 
            0x576D2BFE0D542D35ULL, 0xA591608ED6F049ADULL, 0x14EBEB43BF8015D4ULL, 0xD62EF9287E8A0A02ULL, 
            0x91784F62D2A44F35ULL, 0x00A139FF142B1764ULL, 0x52046942808AC6D5ULL, 0xDF7C92A90F071FCDULL, 
            0xF8A28CA2BF3DFD3DULL, 0xCB5E232A91E337D6ULL, 0xAC3C6E5AE2DAF39AULL, 0x9581BBC34D28E185ULL, 
            0x47C9BE3D73C034DDULL, 0x666ED0657C4FA696ULL, 0x30EAECFCB118B366ULL, 0x683B8C3BE2F2DD63ULL, 
            0xA9FF54EBC73B81EFULL, 0xDDF87E97D0DE7CA3ULL, 0x53FFA402A70AC133ULL, 0xE744A1F1CBF586C0ULL, 
            0x4DF4533A2AB34638ULL, 0x7BEE0AC0C26182ACULL, 0x61A0E633517108E8ULL, 0x37619E943F585527ULL
        },
        {
            0xF69F42A44DCAAD57ULL, 0x00EA363396334C47ULL, 0xBA6DF8406FCED28CULL, 0xE80593D228045936ULL, 
            0x7B36ADB8E2925916ULL, 0xBAA68D9982DD5DEDULL, 0xB86F29117AC787A4ULL, 0xDFCC8E1E34823C7DULL, 
            0x8709F723B5530861ULL, 0x539901DC33954C57ULL, 0xD534D2E00F31BB0FULL, 0x8D69CDF5AFD9C920ULL, 
            0x241480A9EDC07E88ULL, 0xA87BD52FAD7F077BULL, 0x458F13304AF7E235ULL, 0x1C5F5294138FFF26ULL, 
            0xB6F10AC35F40B248ULL, 0x22F0AE6D2A5B3234ULL, 0xE734102BE073C068ULL, 0x6AF0E419678E538EULL, 
            0xB1B786465CB03490ULL, 0xE3EE1263004E5447ULL, 0x6A4C4A4B70C52A0EULL, 0x28B7979013E79C40ULL, 
            0xA11DC7C16DBCD283ULL, 0x28FA4A9BAF7C0F27ULL, 0x9AB9CB3AD201A03BULL, 0x3345587C556AABD5ULL, 
            0xD2D893F12CA2A62EULL, 0xA8432E00FD0A9E9CULL, 0x452C1FF08B50C5B3ULL, 0xF735C15A25551B1FULL
        },
        {
            0x7E8E231122F03512ULL, 0x6D1D163004E9DCAEULL, 0x8AE52BF203BB225BULL, 0x66167F0790821237ULL, 
            0xCD252A7F023E0803ULL, 0x0982ED13EE51EB78ULL, 0xF5BC78F1FF41EE50ULL, 0x73425EED5274C78BULL, 
            0x3715A0633C90A982ULL, 0x967981E04187E665ULL, 0x3E1649CDBDDFD7EAULL, 0x1CA1F4F2637724AEULL, 
            0x4DB2AE5975CAA3AAULL, 0xF0AEB4599891B75CULL, 0x98FE96E13474E969ULL, 0x7BE9360801567AD0ULL, 
            0x7629D12434832F8FULL, 0x83FD116F73617B9DULL, 0x6BEA9801E907E897ULL, 0x62FA224B8D7CEE5AULL, 
            0xEE72ACE727EE9FA7ULL, 0x7500DEB4C7ADA9BAULL, 0xEAE4A00B0D7DCDD1ULL, 0xA7410173521A70E9ULL, 
            0xFAD045D357331933ULL, 0x9D057034F99A68CBULL, 0x5661F0FB30793651ULL, 0x4207A54D49B983E5ULL, 
            0x05607B48E30EB044ULL, 0x25A760D99038A5E6ULL, 0x79B4A9CE77890146ULL, 0xF02672A900DB393FULL
        },
        {
            0xAA841B6DF0BF5232ULL, 0xFCD9B3798325C8B3ULL, 0x496296F41AC594D1ULL, 0xB3B96446183EEC33ULL, 
            0xDAF430112C6B6D57ULL, 0x060B14B7EC3B7B5AULL, 0xC7492D1F8CF82A76ULL, 0x9A47E96E3C2ED150ULL, 
            0x0E8C46DD9FAE89E8ULL, 0x5C0EEBDBF6D453ACULL, 0x07ED29560FE57E2DULL, 0x65529FB9D303621EULL, 
            0xDCD79CBC9E8B8765ULL, 0x2E3F1F400263F399ULL, 0x5C7CCEA621593FD5ULL, 0x1FA28D7A9A56496DULL, 
            0xF7DA0E067B8A0A8CULL, 0x6327B2539C62CA64ULL, 0x7E65A0293BF07C5FULL, 0x8B829342D403E6C4ULL, 
            0x9FFA9E2E688B95CDULL, 0x330E0356DD1EF653ULL, 0x6D8947AE2C57ACE8ULL, 0xF9F78971D26A800DULL, 
            0x9CACEACF4B9EE577ULL, 0x525932B38A4D5F46ULL, 0x6FAE8D75D0027B7AULL, 0xF8E186F67F45302AULL, 
            0x3467EF0B78AE4EA1ULL, 0x6793F4B30EB4DC8FULL, 0x0CCEBF684B46D21DULL, 0xC74F759332984370ULL
        },
        {
            0x2F37FF562F813E0FULL, 0xB71FFE8C9647BAD9ULL, 0x6CAFE05CF76D0554ULL, 0x236D62EAED3C3714ULL, 
            0x015F435A32D6018BULL, 0x85150E568D49D431ULL, 0xC96F41180DDFC76CULL, 0x6010BE5E3C649378ULL, 
            0x0B4F32FEA1037BEDULL, 0x0C63F3DD5DD7028CULL, 0x02DD750B16716E29ULL, 0x1000E68E875F24E4ULL, 
            0x4EA4071EEDA22F1FULL, 0xDE1E4B903E1270CAULL, 0xC1F522A3F44D3EEFULL, 0x3BC1B43781508508ULL, 
            0xF27D92EC506F315EULL, 0x72D3320152692A2BULL, 0xAFD6EFA049F86AE7ULL, 0x4BC2EA4AE279A073ULL, 
            0x433B9FD9F3ED6D44ULL, 0xEF636DFC05BADDC6ULL, 0x4CFC6B51BF2EB243ULL, 0xB6E3BC3160709868ULL, 
            0xFD57F94F63662E64ULL, 0x3D71717B91FDD78AULL, 0x40C515572F401C5BULL, 0x4ACE1F103B0CD9F3ULL, 
            0xC99568E177D4825AULL, 0xF641EB16FD351799ULL, 0xB544850E1E29C28BULL, 0x48572FFF9B31D519ULL
        }
    },
    {
        {
            0x7D16A51B852206DDULL, 0x24BE3613A6CA177BULL, 0x5193B79B92772331ULL, 0x4A8B0AE39A91BE32ULL, 
            0xA634F623F6EC49F7ULL, 0xF6D50316A1E5EFF3ULL, 0x4FA315BB88A8581EULL, 0x53C96D8F9396CDA6ULL, 
            0x6F8F810208571FF1ULL, 0xB37800CEE7CDB548ULL, 0x247B52953A52F7E5ULL, 0x87BB64A5E24737C9ULL, 
            0x741218C973B2D044ULL, 0x3D198616C657E74BULL, 0xAD3255602979371EULL, 0x49979974975FB08CULL, 
            0x94D57940558EFE2CULL, 0xD93BAE5D8F4CB0BEULL, 0xBB5D98DCBD3335FCULL, 0xC7F251D3B37931D7ULL, 
            0x8EA269A71DF4CB26ULL, 0xE2D6E6B75A9C7579ULL, 0x2E86397486F64107ULL, 0x4F61DCD59664D02AULL, 
            0x69E4D48F52C05D9EULL, 0x46C210C954405A19ULL, 0xA04CF00012CD3862ULL, 0x820BD2FD902AB67AULL, 
            0xA8CA0CE14493AAD4ULL, 0x8C4ABF16C42545F4ULL, 0x380D68087ED1B742ULL, 0xFF93540D44F983C8ULL
        },
        {
            0x82D854A52C1869FDULL, 0x2D9BA1502739CC49ULL, 0xFF7E3A1518387D22ULL, 0x65A0E16C43E2A35EULL, 
            0xD1DD035491901DF6ULL, 0xE9BA19A91D693874ULL, 0x5C32F2DDAD3FB5ADULL, 0xA5A15BDD089E0BF0ULL, 
            0x3FD877DACD6D9BB5ULL, 0x4E9FAFF49BAE2DFCULL, 0xECCC5E2BD553884EULL, 0x7BFB4358C8B17A74ULL, 
            0x145D86B5422B5042ULL, 0x206FB12EF77E4555ULL, 0x7DAE18A1FD9B70C5ULL, 0x582FD94EF7B85900ULL, 
            0x07CA5DF4D6CB7A1EULL, 0x4B5C8147887EB553ULL, 0x6CCBD66AE79DD3B0ULL, 0x7A5FFBB1326BE63BULL, 
            0x24EE7EE84567ED78ULL, 0x9E007775BD8C9327ULL, 0xB8C98823D2C3BD24ULL, 0xA8D1B67ED06E1E27ULL, 
            0x126583B11FC4A1D8ULL, 0xDC3F17AC92BFC0BAULL, 0xB8D49E6CCB45F1DDULL, 0x992B5D7B9E265828ULL, 
            0xD65C0F1344E074E2ULL, 0x09B7D4279491E7BDULL, 0x246D7D5674533698ULL, 0x6A5CD5059D514DFAULL
        },
        {
            0xA832D5E1BCB97C4BULL, 0x8320366CC16C9A9DULL, 0x33645AF981C14CB2ULL, 0x825518FB4BE99563ULL, 
            0x44CDFEFC968E039AULL, 0xD81E3FF8B539DE7CULL, 0x32D7150640573C6BULL, 0x293E2933EC7AF04BULL, 
            0xF8BA9C0E08E4F258ULL, 0x2CFFAF812B2ABB6DULL, 0xB5FD215BF1BF6B15ULL, 0x55FEADB6126195C8ULL, 
            0xF08FF35A0EBBBE5AULL, 0xAA3578AAED5D177FULL, 0x165E805C3E0EFD97ULL, 0x46B2468F31E0AA0DULL, 
            0x4AB4D16B521267CAULL, 0x8992EDC688B226A8ULL, 0xC274DFCB521D8A47ULL, 0x91A75794041CFF2EULL, 
            0x5E0891D4F797AF21ULL, 0x11C6C3687ED9BFDBULL, 0xD16D58B7BBF459EBULL, 0x408BFFFD16BA5442ULL, 
            0x3C774FDED4E3EFDFULL, 0xFDA2484CB11EB5E1ULL, 0x2EF9CC75B44BE17CULL, 0xD50AEA86B7E00F44ULL, 
            0xF482B7F90C7A377FULL, 0xE8A5885A73F4DEDAULL, 0x8FC9D0E308676692ULL, 0x4F1EF548DB46B084ULL
        },
        {
            0xD08B1CB27C9A6950ULL, 0x3DBC55E48FBEB81BULL, 0xAF2EF7CA5DC50150ULL, 0x673EA8F6B67F46A1ULL, 
            0x9061D73959761273ULL, 0xF994B7DFEF9EF3A1ULL, 0x8FBCBD2C0611867EULL, 0x90D3C3FC3CFB9ED7ULL, 
            0xF68DF6C4E3194FF9ULL, 0xFAA9AEB05A5DD068ULL, 0x29A717FA8024114CULL, 0xDC75D196784E9C68ULL, 
            0x78AC4F8016D1F01CULL, 0xED9BA9FF5AD5DDCDULL, 0x72649686D57ED408ULL, 0xCF3F2FC62C9424C9ULL, 
            0xC50AC22E8CD54FC7ULL, 0xEF505F8FFF8AF10AULL, 0xD6085F4BF17E3BB1ULL, 0xAED32D2F21CBF063ULL, 
            0xAD1BF4B457ADFF4CULL, 0x27F33B730DD6531AULL, 0x3657EE091B817403ULL, 0xE61D12795526DA3DULL, 
            0x3A5019B0F8D31D48ULL, 0x77361E308A4F9358ULL, 0x0C408ADE99A99E94ULL, 0xA7120F6229A838C6ULL, 
            0x91AB23670C2BA1CAULL, 0x3BDBF67D46B84BB4ULL, 0x214C4716B4B1A640ULL, 0xB6C8902951214D85ULL
        },
        {
            0x78D569265E81EEFFULL, 0xCCAB6D7441CA5417ULL, 0x65097872C50E7D31ULL, 0x3280F7460963248CULL, 
            0xAC7690BF170C7FFDULL, 0xDEBDD4B3746F4FAAULL, 0x361749961689CC57ULL, 0x0A39C655F982DCCBULL, 
            0xBD971E244C571DECULL, 0xF18C63F809DE2156ULL, 0xB0689CFD22F6E498ULL, 0x9553F18ECE296D6EULL, 
            0x4C1B294C5069330AULL, 0x7A7F5AA6D29A0A6BULL, 0xE0A3716154068730ULL, 0x857860C9679EDB3DULL, 
            0x702F3BA433F1265EULL, 0x1015AA7173E5DB8CULL, 0x143806BBDDAEA064ULL, 0x3495F0266738C9F0ULL, 
            0x6787A08E0A8F4C32ULL, 0xD0263374E7245CADULL, 0xEDF3134DA7ED7533ULL, 0x86E92D943D0A983CULL, 
            0x9DB10197A75E3EDAULL, 0x108C559AF2E460BEULL, 0x4893366322B0F9F5ULL, 0x837ADA02636387D0ULL, 
            0xC9FB78E65B9AFCEAULL, 0xDCE677A074900A2FULL, 0xB755247D13B31860ULL, 0x091AC7D75E70F93BULL
        },
        {
            0x784D164B662F2882ULL, 0xA8AE3BBD2787D832ULL, 0x69BC031787F8191EULL, 0x013B8BDF34F549CDULL, 
            0xDB84390042FF9563ULL, 0xC1637F1B19D19B81ULL, 0x7219EF3D7148C6DEULL, 0x1F63CAA79B5C3AB4ULL, 
            0x944D55D06FE2DA98ULL, 0x6851DED433D50CA1ULL, 0xCB3AAF12A2E21EB7ULL, 0x804D2DE8B5736C0AULL, 
            0xB437332BC774FE28ULL, 0x052ABB0D95DE6457ULL, 0x8F0BD14169E9FD91ULL, 0x1A3DC727A5F801A4ULL, 
            0x7C4767E2A2BF237EULL, 0xBE0269BFC2483993ULL, 0xD48ADF3B5B37B91EULL, 0x1CBE37906C062ECFULL, 
            0x958513D0E2E28097ULL, 0xE9D04D69C48D2347ULL, 0x8D722BC5B446A29BULL, 0xBA65F62DD8F15101ULL, 
            0x239ACDA3CC0E239CULL, 0x3FD3FB164691DCB6ULL, 0xEAF0D7FDEE04FB8DULL, 0xB0D7469F3D4D6365ULL, 
            0x1E206A630C725F0BULL, 0x4C0FCC26F68890B1ULL, 0xF5B0774C6D5841A8ULL, 0x4FD084A5E275E2AEULL
        }
    },
    {
        {
            0x53FCD3BEA4F2DD68ULL, 0xB00F66AB87A5084BULL, 0x1062518F4C094753ULL, 0xA5903B38BEEA822CULL, 
            0x9BE0B3FB37F6BD0AULL, 0xB460D25619DCB384ULL, 0x0103DE2302C6409AULL, 0x890C65292D268CC6ULL, 
            0xA10D4CC0068E223CULL, 0x154B6BC772965DBDULL, 0xFE0B2BCFAD9F93F8ULL, 0x98CCB818C734A9A0ULL, 
            0xA30A69CFF8EF9A4EULL, 0x447FFB9A9DF217FFULL, 0xFFFC291181BCF112ULL, 0x68BB13C6F72FD4EFULL, 
            0x174770713C98F126ULL, 0x0908CF79CA5B7BE0ULL, 0xE3D5DCFCAC66B846ULL, 0x5402CDCC2A92F7F6ULL, 
            0xC68C2155805EF3C8ULL, 0x3A11F5C52636696EULL, 0x25944A696C64CFF9ULL, 0xD5A861346B2F104EULL, 
            0x5F435D00187F4BD0ULL, 0x266E04021B1F4027ULL, 0x734CD817F5CC407BULL, 0xFDC6A2FC1F33C241ULL, 
            0xBD9A005CC10A094AULL, 0x82873D5145DD345BULL, 0xF2C2093F330EA723ULL, 0x629415E4A15D5788ULL
        },
        {
            0x82C577AC584BA35FULL, 0xF80FBC6D62A343A6ULL, 0x6D6B0C82BE6586FAULL, 0x9FDCD49F43B4058AULL, 
            0xEF6C810C51B86E96ULL, 0xB9BCA4979B740C8BULL, 0x094BD42E04BD87C6ULL, 0x39257269A21038BCULL, 
            0x4AB6227DB2B43E91ULL, 0xEF75894720BD5791ULL, 0x24AD78F50BE451BAULL, 0x9A4C35966E5A395AULL, 
            0xC1B3849CD93ABCFCULL, 0xF86A4E114A82B940ULL, 0x0608AA8ED473589CULL, 0x729994ED54155AF9ULL, 
            0xA70482CBF67AD4CBULL, 0x5DC793B0D553BE9AULL, 0xE493B3521577A592ULL, 0x182ADC344A6006CCULL, 
            0x7C41FC6D78266862ULL, 0xA164E0BCFC45882EULL, 0x95105049068E18B2ULL, 0xA7908109770A8ED1ULL, 
            0x6A5DB698AECA263FULL, 0xD6156030EE46CF49ULL, 0xC2DDEDD7C0B71479ULL, 0x519C9E9870003743ULL, 
            0x2379E0FF0AE42231ULL, 0x070F5FF4FF6B860BULL, 0xCB7BF8528CE3DF55ULL, 0x4D944644E2681AB1ULL
        },
        {
            0x814C2021B3E1F3ACULL, 0x699D91E87FA00300ULL, 0x2F66C8EF9395349EULL, 0x1A00B1D4ADF5C702ULL, 
            0x0495D1B029870464ULL, 0xFC41582C08790DABULL, 0x82B0C7C9D61E7C78ULL, 0xCC3E6E739F83DC12ULL, 
            0x429932442629D710ULL, 0xC62D9253856D5D63ULL, 0x938EDB76998BEFB6ULL, 0xAFC5F03391976176ULL, 
            0xCF46790F51232716ULL, 0xDD9B8A599F9EEF72ULL, 0xE57B141DA449818CULL, 0x2C31F8D44A6A381BULL, 
            0xE98202D3722740FBULL, 0x1E2E9816700CB816ULL, 0x2A9A181CA9581996ULL, 0x58A6B548AA601714ULL, 
            0x21ACDB2E193A5E47ULL, 0x7FDD8C77CF00B58DULL, 0x5D98877E28135564ULL, 0x950CE4B2FD36BD56ULL, 
            0x64837EE822EB1977ULL, 0x33F39A40C2CEEC86ULL, 0x2C3ED4F5FDE320ABULL, 0xB98A29A2AF21FE70ULL, 
            0xB7C1D1EE51310EC8ULL, 0xD47CF0248C49BC3DULL, 0x19911828ED80489AULL, 0x956EF435898A9A8BULL
        },
        {
            0x2E100AC01CA3DEAFULL, 0x630EF3AA205B89A5ULL, 0xD6E266437A479395ULL, 0x74E71A9B3D8CC5D6ULL, 
            0xDC2B35233C0FAFC9ULL, 0x172199FDBE9A3404ULL, 0x697F11BC4D84DDB7ULL, 0x8ED9DEE957D8AE3DULL, 
            0x8EDB35941839EE18ULL, 0x8485AEB788CE2351ULL, 0x11B076D629779F08ULL, 0xFD5678F50C8AF2ADULL, 
            0xF1189561B46DFB74ULL, 0x326ACAF23D16CF1EULL, 0x94E51B50281D60CEULL, 0xFD0BF481BF9A6AAEULL, 
            0x260596C875B25EE3ULL, 0xB8769C945A353265ULL, 0xFF849D680ED6C1A2ULL, 0x365A4C6ECE4AE2F8ULL, 
            0xE89C62891409D4F2ULL, 0x1F80430E3A4556E9ULL, 0x72891E9F81D222BAULL, 0xB3D0C4A1CAE94323ULL, 
            0x7C9456FA8088664EULL, 0x1640EEBDFE483288ULL, 0xFAE1C712C4DBB3E1ULL, 0xD1A824EE32844D24ULL, 
            0x98D441231BCBBC45ULL, 0x09848C316E98F1D5ULL, 0x0D48E2AA2110DCB5ULL, 0x192B02DEB2156F5FULL
        },
        {
            0xFAF02CC0FA05BB8BULL, 0x963C5364AE902177ULL, 0xD5CD5CA7195D7433ULL, 0xD0F55AEAC98C887EULL, 
            0x98B3B7D8B9F7A337ULL, 0x9392572482372898ULL, 0x128B13C6619CF498ULL, 0xC17E02AB9861AEC7ULL, 
            0xB9B73750A45D156DULL, 0x5F0817564E5E36F8ULL, 0xAC5C5534CB29DD49ULL, 0xBE3FD1562F6343E6ULL, 
            0x839C578908B95D6AULL, 0xD54783532410D3A3ULL, 0x30F2A56FA58155B6ULL, 0x8DB7F9B95A9C7FFFULL, 
            0x7A3C3EFA38C2BD2BULL, 0xA090322B620885D2ULL, 0x134C94EF62DF481AULL, 0x4DBD7FBD6B3AF001ULL, 
            0x727B0B5D155AF892ULL, 0xEC4ED3D20A5C5FFCULL, 0xED2ED10CBC0B2074ULL, 0x69C9617C128A53FBULL, 
            0x90695F025B1BB31CULL, 0xDFF0FE5B804872E1ULL, 0x02EE109DF65B3DF4ULL, 0x1A27E9B01644D353ULL, 
            0xDFC3A1B9DB8FF48BULL, 0xAB326B282F309622ULL, 0xBF30C63217254C36ULL, 0x555C7E6889E37948ULL
        },
        {
            0xE4DED1FEFE469655ULL, 0x2A4D9674E565339EULL, 0x8530925A9C9CAE0AULL, 0xCAD15413240D4B78ULL, 
            0x30DF9D496A630F59ULL, 0x8B87AF865384F404ULL, 0x93996C88914DC35CULL, 0x9B49620B5CDE5D4AULL, 
            0x40F2FF1A0F926810ULL, 0x0A43856C73A0002CULL, 0x1833A0FDCB265EFBULL, 0x076B558672B0BC83ULL, 
            0xCF68B50667B96FEDULL, 0x2078FD58D2E376E4ULL, 0x521B705C00D2ADC2ULL, 0xC4EE5D7EC8E14705ULL, 
            0x86F7AAA5C3F05AE4ULL, 0x9CD8005EA85A913FULL, 0xFF40F9DD49744E8DULL, 0x9775B8A7DE3C059CULL, 
            0xA7FD692DE709AF48ULL, 0x1328878AE44AF0EBULL, 0xE5A2C3AABD688F10ULL, 0xE498DEA729A1A754ULL, 
            0x784569B644128ED4ULL, 0x74001361E6580A73ULL, 0x9200A8F1B9CF7076ULL, 0x8A0EFC35E4C89784ULL, 
            0x09D07B925B1C83F6ULL, 0xB9C5E7E9E53390FCULL, 0xDABF6BD5BFA0CE99ULL, 0x02A8A063189FBDD3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseGConstants = {
    0x9C5E4C6A06966E02ULL,
    0x776DA16F9C717319ULL,
    0x7AA62CEE4CA49DFCULL,
    0x9C5E4C6A06966E02ULL,
    0x776DA16F9C717319ULL,
    0x7AA62CEE4CA49DFCULL,
    0x36A8F644737AFEA2ULL,
    0xD33E17DBAA929959ULL,
    0x7C,
    0xA5,
    0xB8,
    0x48,
    0xB6,
    0x25,
    0xCE,
    0x2E
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseHSalts = {
    {
        {
            0x50169B6A5A223925ULL, 0xD10A6AEA71DCAA40ULL, 0xEF2B2DA2E8DB31F1ULL, 0xE43DE9D70CB63A71ULL, 
            0xB598A4B9F5A0A922ULL, 0x5170FBED500C039CULL, 0xF40599F4B1F335A3ULL, 0x48C06F06E2DB7F14ULL, 
            0xF34C7B7B70E8EDCFULL, 0xF0036459A1EB1964ULL, 0xC57E2E801FE35927ULL, 0x58C577D2FBC7C380ULL, 
            0xCBC5AFE0BF965176ULL, 0xE1E1488744560A5BULL, 0x8152712E90E9C582ULL, 0x8A22FDA698577A4EULL, 
            0x12E0D4DF0894722CULL, 0xBDB7A39FC83D611BULL, 0x7ADC8F4DC669E86BULL, 0xC786684605080871ULL, 
            0x41C9E7EE56AA9E49ULL, 0xC82E3FE190594218ULL, 0x38A4100A13EEC708ULL, 0xC92295726DD98866ULL, 
            0x0300CF14AC915D2EULL, 0x97D8F4ED7F81B6ABULL, 0x34AD908941C75D18ULL, 0xDCBD294DE78CAE92ULL, 
            0xCEB6FD15B18C50CCULL, 0x8E5B01861F025832ULL, 0x5E721998ABC9563AULL, 0xCD1EF9841775C1A6ULL
        },
        {
            0x655296EBA67E280EULL, 0x31934D24459BF2A8ULL, 0x5C3540FB6C8267D5ULL, 0xE4EBFC2AE5061D73ULL, 
            0x18E9BE068ACBCAF2ULL, 0x380C0C960974B4DAULL, 0x18EADDFB1FBE6C10ULL, 0xB75A2EC0E6E92A2AULL, 
            0x1D526AECBB1F774AULL, 0x610FBCB0E76CBF71ULL, 0x162235CEFC750C04ULL, 0xA7CBD0F15EC60152ULL, 
            0x0B8F39A2D64FE9BDULL, 0x2AE503C131C4ACF4ULL, 0x4B32C94437F74B7AULL, 0x8CCBB7570DA5EE9CULL, 
            0x996B4B2E33F7CB1CULL, 0x451B75111B41D809ULL, 0x744403D1A90B3747ULL, 0x918E46385A9A02B2ULL, 
            0x79AF33F4AABF2A0CULL, 0x91C12A50D3261FE8ULL, 0xB8B4C9FF779FA623ULL, 0x2B461D9599EF9E6FULL, 
            0x90700173262F96C9ULL, 0xFF524C6BA2175843ULL, 0xEEDBD759CF110C56ULL, 0xBC9956085E605576ULL, 
            0x01A8F6DEC54375EEULL, 0xD90D404EEBBDCAA3ULL, 0xDEE8A8FF50256198ULL, 0x49B36B599F57CB00ULL
        },
        {
            0xA2FDA059B814DDC0ULL, 0x4186B4E7B0E9AAD2ULL, 0x55475B1344A827B7ULL, 0x388E3AC5E3AC406EULL, 
            0xC8D84A08C9F74118ULL, 0xF7D5AF7FF2757120ULL, 0x5D9A31EE7E24AD5BULL, 0x8D78C896A9F50FDFULL, 
            0xB48F98AF929D1D3AULL, 0x3CE8C810E05D0BDDULL, 0xBDDD18DCA333882AULL, 0xE700C3A7ED349EA3ULL, 
            0xC982000CE414E133ULL, 0x0ACBEC2EE0ADA8B2ULL, 0x0A69886F9AC9A312ULL, 0x0004A36A7C73F97BULL, 
            0xEE3A2D165FC67557ULL, 0x7EB2B7BC7312ED52ULL, 0xB94637CCA27FA234ULL, 0xE49A161BD7EE3FDFULL, 
            0x654BF96D33DBDBD9ULL, 0xB65DBC76A889E079ULL, 0x731DB3C9BDC52A81ULL, 0x34C335A3D76CB3F4ULL, 
            0x6E53AE6A104D070CULL, 0x3342AE2DEDDD6A9BULL, 0x5813B9BFEEA1ECE1ULL, 0x07FCEFC1E9CAE4ACULL, 
            0xF0B7691646E3BF51ULL, 0x658AF64124EA2495ULL, 0x4879BFDCA406DD87ULL, 0x11EC47EFB6C2860EULL
        },
        {
            0x2F371F28389AC4F6ULL, 0xD36F139F621A1E0EULL, 0x7C06F0E13E3C0248ULL, 0x188574C8A48E57D3ULL, 
            0x93F1202361317D50ULL, 0x7898416072609ECBULL, 0x956708EC464A851DULL, 0x332DB15C50135296ULL, 
            0x8EA143F7BADB3818ULL, 0x933454CA4DD555E1ULL, 0x8473157617AC01D5ULL, 0x82B26F6A2EDA8DF5ULL, 
            0x2BA6DF3BF7E233C2ULL, 0x866780535A18FC35ULL, 0xF25126ADF13388C2ULL, 0xFDEFE7BF8DED0F70ULL, 
            0xF9E3861AA635072AULL, 0x440CE51D5669D6D3ULL, 0x8E9CCCBF1B3D3F4DULL, 0xD501AD18D90AFEB9ULL, 
            0x315071723EE30C3FULL, 0x66017DCD78D2B4A4ULL, 0xA9E15744401B6F5EULL, 0xC64EFB8478C47A7DULL, 
            0x6C2820F5DD099A02ULL, 0xE30F8BF493F0B693ULL, 0x0EC1332DD54C4BF4ULL, 0x204274E415888401ULL, 
            0x1D7D7BF3FEFCBAA9ULL, 0x7FAB5E0F42EF805EULL, 0x65BC31D24C81EEABULL, 0x98AFB16F9A06D55EULL
        },
        {
            0x81E91A1DABD2EB89ULL, 0x095C57174F092693ULL, 0x12803C1FED870888ULL, 0xF8E22DF9AB641367ULL, 
            0x83AA22EA1220DC32ULL, 0x1693AD01A579CFD4ULL, 0x531525E86ABB7000ULL, 0x347D05913ECB7776ULL, 
            0x8455A19C9BCAC39AULL, 0x48AA0D9D8146D461ULL, 0x062EE9446E41CD86ULL, 0x29022082880F9AE2ULL, 
            0xAAE1EF89CC77356FULL, 0x1E563D219F327EE4ULL, 0x4C004EEB92E3DB7AULL, 0xA58C53B0F8F49A66ULL, 
            0x81068BC118CC498EULL, 0xAF61C1EAA649510BULL, 0xE8F3CC15D3F8CDD5ULL, 0xF61FFA0ED233CC8FULL, 
            0x2B5B955C9F51F626ULL, 0x16FA07B4EC5B1B51ULL, 0x8EAB392F98D2FCEBULL, 0x6D5B1CC1EBB5958BULL, 
            0xDF7BBCF734975D0DULL, 0x6A9B7B3B98AB7692ULL, 0x777101DA0F545AA2ULL, 0x5E01BAF62951D9D3ULL, 
            0xEAB89599F1F5405EULL, 0xD8351712592D4AE0ULL, 0x4FB456F3AC018635ULL, 0xA261E0ECF9960C8AULL
        },
        {
            0xBADB0E6A2F7789C6ULL, 0x6083CA99C5ED9A4BULL, 0x4D431BA138EBE731ULL, 0x3825443263DD24C8ULL, 
            0x26866DF2E64B9922ULL, 0x274B547C87BFD8FCULL, 0x88142A7CF3FDDA98ULL, 0xAF97EC22869045CCULL, 
            0xFB60F0588FABFE98ULL, 0x2FB800103BCE2467ULL, 0x2EAAF40C1F916957ULL, 0x00936A8811B014B5ULL, 
            0xFC27FF3EA528FCAEULL, 0x9FE4C125477CFFBAULL, 0xD892AC2C2B475233ULL, 0x84184B1309BCE7E5ULL, 
            0x4CF5DB1509A7B555ULL, 0xDBABD5EFF57C38A6ULL, 0x16129F21BA046112ULL, 0x487961E7EEDD2A15ULL, 
            0x2E5588B5AC912090ULL, 0xF0652016C9F12521ULL, 0x9C71304F42140E67ULL, 0x2C61FAAE6CB79F59ULL, 
            0x2E25FD1481176EB9ULL, 0x1245CA554A05831FULL, 0x03126E13A0114D74ULL, 0x8A66EB1307B5CF8DULL, 
            0xC01E2F2C1DAAC0AAULL, 0x54DDA75E53066E1DULL, 0xBCEFC4791371FFA5ULL, 0xC9D7060C88E11721ULL
        }
    },
    {
        {
            0xD0A28272FD96B056ULL, 0x93B43159341D3F14ULL, 0x2AC09EE5A2A3F010ULL, 0x767E5B8CAA94B7C8ULL, 
            0x01ECCDB5B3EF92DCULL, 0x44DA4377DDC0BAD9ULL, 0x78A7FADB7EE2A445ULL, 0x95C0EAB9C75150ACULL, 
            0xB5970B5429C9D51AULL, 0x8833FFBC136E3153ULL, 0xF17909AE4253AA43ULL, 0x888603CB47623CD2ULL, 
            0xDB96CDCB113A6C78ULL, 0xCE27372E94FBDFA2ULL, 0xBCE91B750C394FECULL, 0x3EBA2B66C3422876ULL, 
            0x38643F77285E2E12ULL, 0xFB1EEDBFAFF8B54BULL, 0xD14A8BB52A94FE45ULL, 0xCA37C6599806CCE9ULL, 
            0x5684766172E860DAULL, 0x85142A0512A26D75ULL, 0xB5CF16495F14344AULL, 0xA0C83DC3A3832E7CULL, 
            0xA126592D245CA07AULL, 0xACD66C33370DE372ULL, 0x105A3F0B8BB5CE79ULL, 0xF26473CE9B5402AEULL, 
            0x8CB89F32FC1A2511ULL, 0x4B4E8E9D6F9BEA2EULL, 0x064824235D53DD76ULL, 0x5936CAD851EE9C19ULL
        },
        {
            0x680D5305439171ABULL, 0x57AC7FA7E2060321ULL, 0x2104658FBC092EE0ULL, 0x04371150CEE8AE37ULL, 
            0x4A8B336E40B3FCBEULL, 0x4AE1288F337AE674ULL, 0x14A504DCE9AC8E7CULL, 0x1E6D25A7C98B0BD7ULL, 
            0x13046C4BD13750C9ULL, 0xEA764AEE98FC5BFCULL, 0x9901AAEFA5451A99ULL, 0x93EC27DC1C30F5DFULL, 
            0x594BC8D11EAD4534ULL, 0xFA389140E0D21A35ULL, 0x72EB4D3ED469A4FFULL, 0x515AF81B5D28CD01ULL, 
            0x6A7B54B1263D5CDAULL, 0x7598309B4A52DCE8ULL, 0xA5E71A46176820A7ULL, 0x57407DE9C487F08DULL, 
            0x5BB1B353BCF3D07CULL, 0x1FC186C17A4DC97BULL, 0xA7179C364B233992ULL, 0x241E0FE6A784C611ULL, 
            0x869DCFA4EE959283ULL, 0x7764AEC8A23D0917ULL, 0x50FCDC5B34EB7F23ULL, 0xA7CAE94D32968474ULL, 
            0x5D6EB3D8B7B07F13ULL, 0xD8E9CBA4F035D492ULL, 0xABD36BAE89A16A93ULL, 0x8FE4072DF6239273ULL
        },
        {
            0x58E1A2299D129F6DULL, 0x75190AEDFD0A5B5FULL, 0xD74A202C1F2C46E5ULL, 0x7C02CB4BF22A3CDAULL, 
            0xA9BFF5A28EC247E3ULL, 0x63016167DEEE50D6ULL, 0x52510C8E90E787F3ULL, 0x95549E1A20D58408ULL, 
            0x309B693C439D6A31ULL, 0x0106D30003B9FCC8ULL, 0x3E9AE9F2C746F4DEULL, 0xB3408438BD674429ULL, 
            0xB3D482CFC6218E8EULL, 0xE43A4447D6888B7CULL, 0xBD2A3ACD637A5B69ULL, 0x0328C6BFDAC77D8FULL, 
            0xBE27753588B67094ULL, 0xB35A26B4428508C5ULL, 0xDF6907A929D38A32ULL, 0x4A855BBA61607F79ULL, 
            0xB41FE5493EBC9A1FULL, 0xEF3A616D14304A7BULL, 0x2250DFB0C34EC76CULL, 0x47312C1D2DB19BA4ULL, 
            0xAAE0696A7F2CDE31ULL, 0x69F70528425E05FCULL, 0x5A68A259B1A7513DULL, 0xE20A8F672F853CBEULL, 
            0x20AA64B3521A4E9FULL, 0x1ED1EE38E9193F2FULL, 0x16C0E5D0142D5559ULL, 0xF8708A092AB37AB7ULL
        },
        {
            0x756C101B86E16887ULL, 0x7D73C08C74FC2BD2ULL, 0x68A450C93A0BA8A9ULL, 0x0D514F21BF845CA2ULL, 
            0xDEB96A983455B389ULL, 0xE989724FA6CA73B9ULL, 0x184BCC645A4F0BB4ULL, 0xA0439679E36FC3D4ULL, 
            0x9E36EECDB273CD79ULL, 0xF9173D15080591C3ULL, 0xBFDD64D5EFDB297AULL, 0xA0D24458574067C4ULL, 
            0xB226B4EB030E8F53ULL, 0xE83ABA1B4D23B97BULL, 0x52C88395339C4AD0ULL, 0x5C2291249EB9804BULL, 
            0x1D79FF162BEBE4B6ULL, 0x785371C3DDA03836ULL, 0xFC0C74FF673847DFULL, 0x0A131401D16B3AA8ULL, 
            0x8F53BDC1B76383ADULL, 0xA5102C07F242C8A8ULL, 0xBC535B303D148480ULL, 0x58CEAB929E98CC06ULL, 
            0xE178B0CEE21F81EEULL, 0xF291922260473D8BULL, 0x99C23FDB3C62B307ULL, 0x062185DC217ECD98ULL, 
            0x044F9952F55196E7ULL, 0xAA13BB0175707BCBULL, 0xD3AC7338D459C824ULL, 0x7A1D8C5CF6B1E2BCULL
        },
        {
            0xF537F508A20DCB33ULL, 0xCBB93570E2567D11ULL, 0xEF9C0661F7D6E520ULL, 0x9AA94DA6FBE705E5ULL, 
            0x6D77FB380318EA22ULL, 0xAF64A207D83B692BULL, 0x794F1AB49FED8C19ULL, 0xBE16A5268699B3EDULL, 
            0x9037EA8685CD62DAULL, 0x8BDB20E0062984FAULL, 0x176420A2359ED609ULL, 0x90D9CB48B2FA010EULL, 
            0x1BF3DE857472371CULL, 0x0B4A67FC05BBCE7FULL, 0x7412DB0B98B21AD1ULL, 0x9F183AF893A74FEBULL, 
            0x0DF5FCF5D6F6CC8EULL, 0x3DEEB4D57C4F4F8EULL, 0xBBD04292EE09F941ULL, 0x4C135F72B6424C9DULL, 
            0x58C1B540093D9733ULL, 0xF0B45C0FE90D8E88ULL, 0xA7F4F1DA6B06778AULL, 0x099A9100FA4BFB19ULL, 
            0x228A25B2E96905EBULL, 0xD0C9E6DED79B1C27ULL, 0xE39F918D421CC6CAULL, 0x890443524C39AA79ULL, 
            0xC7FF42FB5376C725ULL, 0xD5C0D62ED976C2E0ULL, 0xCCA09CEC47409423ULL, 0xAB38AAF7B109320AULL
        },
        {
            0xD014F3C2995C0B83ULL, 0x4515D6547C16B717ULL, 0xCA2154F7941CD18CULL, 0x11BDA2FE172C8FC3ULL, 
            0x8BA2298A3D6D96EAULL, 0x50B0255BC7F27930ULL, 0x4EBADB9744503D66ULL, 0xE1FCD29A50B2A0C2ULL, 
            0xAA17026BD5105610ULL, 0x89AEABAD2371447BULL, 0x92332846B6DD4907ULL, 0x4EA278D9033A6C27ULL, 
            0x11DCF4708C38EC6AULL, 0x29672F4E1AD3D96CULL, 0xE7C044FF83D03661ULL, 0x3527FFD887E53A90ULL, 
            0x2DF012A938416501ULL, 0x2AD57C33CD5785C1ULL, 0x5549856FF059257AULL, 0x38C282F1802816BBULL, 
            0x5E5C527E564DA7F2ULL, 0xEC377D163B3D583EULL, 0x83FED7E7A6130066ULL, 0x6927A22FF4968DD0ULL, 
            0x5FA8E5E6B273DD24ULL, 0xE5370328A67E9DEDULL, 0x2F4A9FC97D193295ULL, 0xFB16A473A13429AAULL, 
            0xF1D7417765592E5AULL, 0x3C77271F53A68E52ULL, 0x79C99559057526B6ULL, 0x444E0100651984D1ULL
        }
    },
    {
        {
            0x73C460664DED1D18ULL, 0xB8EFC46CDCA3E70EULL, 0xFB371661ED3A68CDULL, 0xC53DBF9BCDC83607ULL, 
            0xB14819C2D0CE5FF7ULL, 0x39A6847EB6209624ULL, 0x473D73929E313321ULL, 0x166B42E78B06DCE0ULL, 
            0x5B07FE31DD0E056DULL, 0x6E0141490910AB9AULL, 0x288DF2000B949EA6ULL, 0x995C6784AD240E23ULL, 
            0x8A8635C78263B918ULL, 0x1E80CC24FFAC91D1ULL, 0x3D48CCEA743019CBULL, 0xCD37AB50C84AB45AULL, 
            0x2FBD7775B18D0777ULL, 0x5359FD0F3FC95615ULL, 0xDFE0D958356295ECULL, 0xEC46958673B7D0E1ULL, 
            0xC2A1508B3B0979F5ULL, 0xA0E044AD07AD4C2DULL, 0x6952C8654072B5F3ULL, 0xDFA3DC67658F78D6ULL, 
            0x581B1578D50BE398ULL, 0x8A00BAC276E6644DULL, 0xA5192AE075F7C21CULL, 0x0BB59CE37CE1CF1FULL, 
            0xC6AAAB3F40D05F0DULL, 0x2A12DE818BADFA0EULL, 0x010DFBD93BA9CFC3ULL, 0x9DC77579EFF9FAEFULL
        },
        {
            0x133461ACC036DAD8ULL, 0x9EF6A40F1A3B1EDEULL, 0x62AD3CB7AE722944ULL, 0xEBD359202F655D34ULL, 
            0x54D8D50A8521FEA6ULL, 0xB5C4F6FEBC3BA910ULL, 0x85ECEB9C34CD5C44ULL, 0xD8852CCFCA02C54CULL, 
            0x78B8A109BA428591ULL, 0x26DF116F7D3139B2ULL, 0x3B2F929961772011ULL, 0x344826AB839B453EULL, 
            0x4D4E5B9B45889D5EULL, 0xA0A100B2D0C39B4AULL, 0x361B428249601E48ULL, 0x3FBB592D6AC37CB7ULL, 
            0x505FE2401FF9599CULL, 0xD6127008E6EC011CULL, 0x2A49CCCA09E9CBA3ULL, 0x070D4526D1C865D1ULL, 
            0xBE03B58856969E12ULL, 0xE02E5D9C23EF2B01ULL, 0x2C16DEE97986E465ULL, 0x9C3C4DEEA1F85D21ULL, 
            0x01202B47F51DDBB6ULL, 0x8F4EDB76AAE2F6DBULL, 0xCF0189F27B377479ULL, 0x97D0ADB1B200D46AULL, 
            0x8E6D32026769F7E8ULL, 0xFBCB0575129E0A9DULL, 0x3FE9EC6DD67755A9ULL, 0xDEAD6C61786F5D0DULL
        },
        {
            0x34F72D5B9361562DULL, 0x422D524214D7C5CCULL, 0xBD3ECBEEB357A3CEULL, 0xA0B46E883C3863E1ULL, 
            0x73F022F1865C9A24ULL, 0x172D40A779481981ULL, 0xE998D4BDBF989469ULL, 0xF1D4EEEB495EA192ULL, 
            0xBB27DBF1CCC8EFBCULL, 0xBA409B4968C30B69ULL, 0x562ADA930038BFDBULL, 0x64925D151D0392D1ULL, 
            0x431AE43FF87D5C4DULL, 0x063D340F1F575AB5ULL, 0x06AB6B082D0B47BDULL, 0xEBB117D57715E48CULL, 
            0xE7C14D28B97BC48CULL, 0xB6C242BBC4BBB5CBULL, 0x81C5D7F15F9E9E4CULL, 0xE44465978AEF96C2ULL, 
            0x8E2E953AD64CE97AULL, 0x5D32E94241573FE2ULL, 0xB8F312023AB0E8C5ULL, 0x723484E59F05F0E4ULL, 
            0xE69E750388EF7B45ULL, 0xFC63E8A55FC45CCEULL, 0xC194884BC0065BF8ULL, 0xD8D76ED207ED2F10ULL, 
            0x5EEED8F8BABD6877ULL, 0x2E95A9782ED2EFA5ULL, 0x9095A1424BCA96DCULL, 0x0EB0534134B90B77ULL
        },
        {
            0x76FD8878BAD2BB39ULL, 0x1ED339E79000DFEFULL, 0x0BB6F8B33DC70580ULL, 0x65EDA8EA2571F677ULL, 
            0x5609ADBA927FFA93ULL, 0x9B309AA042C37413ULL, 0xB28B8A0C105B6A67ULL, 0x4B0787DC82B16684ULL, 
            0x509BDF0C24B53CE6ULL, 0xA87DB4A0AADF6EC9ULL, 0x1595E837A9F02064ULL, 0xA876125CEF70EF5DULL, 
            0x31EF51682241AD8AULL, 0xEC12655527B05D4FULL, 0x7B5CD4A9E657F2B1ULL, 0x47A4183592DF4BC1ULL, 
            0x51E61FC87008BBD6ULL, 0xFD4219EFF9AF6007ULL, 0xAF38605D76B04723ULL, 0xFFC80EDB319B3097ULL, 
            0x69F3C7384F86C412ULL, 0xE0667C5591858840ULL, 0x00EFA20D1533A55BULL, 0x8B408115311BDE82ULL, 
            0x98144E644D38EE7FULL, 0x70E8BEE84FBBF67CULL, 0xBE5F5919B2BEC8BAULL, 0x09E2E70ADBF67C03ULL, 
            0xEDF95B02DEB62AA9ULL, 0xC3F0D93FFBBF5632ULL, 0x7CB9FECC12403C22ULL, 0xE7E04FFCC6071010ULL
        },
        {
            0xE85F61042651C21EULL, 0x28FADA17B421A6CBULL, 0xE8C2C439E6451AEEULL, 0x3DB687EA93FBD1ADULL, 
            0x84A44239780A2AB1ULL, 0x82F97112E723D891ULL, 0xA25C5F1462D836E6ULL, 0xEE4FC30EC3C2660CULL, 
            0x228E0BA2E6C68CF8ULL, 0xD61A9E12E17FB4E5ULL, 0x4A410210B7F5B23EULL, 0xDAA8213EA06C84ACULL, 
            0xEE1BBC37E1E1F3EEULL, 0x16B7041B5992828EULL, 0x1787AF6246A3247CULL, 0x30DDC6C933F14658ULL, 
            0x13746E0D5545F42CULL, 0x550AA8229DF81639ULL, 0x651105758DDDF80FULL, 0xD1CD1E6C6069FDA7ULL, 
            0x522D849AB36F179EULL, 0x52CAA29A66351EECULL, 0x150CA103FB917E36ULL, 0x46CBFC40D106D6C9ULL, 
            0x2C83F9C6072240C7ULL, 0xDE0BE5AC8FCE0E04ULL, 0xEF958DD9E02C7C35ULL, 0x8F46F47FA2BF4878ULL, 
            0x7CECFE570DC406B9ULL, 0xBCAE8479919E6A6DULL, 0x7D454C222D4A783DULL, 0x2DAF0EF9403288F8ULL
        },
        {
            0xA7BC798DF22946DBULL, 0x7F1CB0520F5FFBE4ULL, 0xCAA55B07D53506EAULL, 0xA35D924AA03C43EBULL, 
            0x60FDF1788DFC30C8ULL, 0x8FE18403AC4C9423ULL, 0xFA58B96D43B298DBULL, 0x832D66AEB0220786ULL, 
            0x7AA7EFBF817DE0B4ULL, 0xC56DD7795BF46EE4ULL, 0xA05DE7A7FC415375ULL, 0xAB048C020E9BBEDDULL, 
            0x0473B5010921462CULL, 0x6362974EA45290DDULL, 0x70299F1D31857657ULL, 0xEE4A4AF89CC0F3FCULL, 
            0x3709B358C98B5723ULL, 0x65837F14822F3A13ULL, 0xA8A3A47BB19E2B52ULL, 0xE2971AC93ABEBC69ULL, 
            0xC2BDF0D61316FC42ULL, 0x1748EFB004DF0EB4ULL, 0xAC25A4F90385A2D7ULL, 0x6842A19D7BF4BBD1ULL, 
            0x1AE4E3DD46FCE097ULL, 0xA834F862A8033B3BULL, 0x6BC6CADCDA71A972ULL, 0xCDF52FB65E796F48ULL, 
            0x2DF644EC857D3541ULL, 0x32A725BA5DB82A44ULL, 0x721A7829AF7FEDF3ULL, 0x4C3E6E6CA22B43FBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseHConstants = {
    0xDC35FFFF9E53E138ULL,
    0xBF80A91FA64ACDF2ULL,
    0xFA7DDD9707DDD199ULL,
    0xDC35FFFF9E53E138ULL,
    0xBF80A91FA64ACDF2ULL,
    0xFA7DDD9707DDD199ULL,
    0xB856A16A3D5F2FDEULL,
    0x01228B6463542A75ULL,
    0xC0,
    0xB4,
    0x11,
    0x77,
    0xE7,
    0xE8,
    0xC8,
    0x3D
};

