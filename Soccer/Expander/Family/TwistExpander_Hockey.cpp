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
    std::uint64_t aPrevious = 0xB0B9EE1275F7B957ULL; std::uint64_t aIngress = 0x9E8F6762BB4DAA8FULL; std::uint64_t aCarry = 0x8176E4A5D2D71A13ULL;

    std::uint64_t aWandererA = 0xF6D9FE130A61658EULL; std::uint64_t aWandererB = 0xC4FA6E67627BE3EFULL; std::uint64_t aWandererC = 0x9CDEBEDBD8276C0DULL; std::uint64_t aWandererD = 0xEACA0E7D67BEF146ULL;
    std::uint64_t aWandererE = 0x8E06B220481951CCULL; std::uint64_t aWandererF = 0x9D3BCF085E83F582ULL; std::uint64_t aWandererG = 0xAB3043D97621D5CAULL; std::uint64_t aWandererH = 0xABBEBABEDD99403BULL;
    std::uint64_t aWandererI = 0xFBC25DF241F063FDULL; std::uint64_t aWandererJ = 0xAC03F0AAEDAA8AC8ULL; std::uint64_t aWandererK = 0xA46753C0981008FBULL;

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
        aPrevious = 15993180554110186901U;
        aCarry = 12698994494970499796U;
        aWandererA = 14186669717568423361U;
        aWandererB = 12471611599159208494U;
        aWandererC = 11586606128267784086U;
        aWandererD = 10586190996418399811U;
        aWandererE = 10916506204181517043U;
        aWandererF = 11661872083729091614U;
        aWandererG = 16196159308059996206U;
        aWandererH = 17980140357001883757U;
        aWandererI = 11274557698989645011U;
        aWandererJ = 10580391921596352093U;
        aWandererK = 12313828537810471670U;
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
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: fire_c, fire_d
    // ---------------------------------------------------
    // write to: fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
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
    std::uint64_t aPrevious = 0xC2B414193BAF7173ULL; std::uint64_t aIngress = 0xAC6C8159EFAC77B0ULL; std::uint64_t aCarry = 0xDA4EB1B4386BFE69ULL;

    std::uint64_t aWandererA = 0xB01CFD7D9432CB99ULL; std::uint64_t aWandererB = 0x9B24B99D4BDAA2BAULL; std::uint64_t aWandererC = 0xE90BE89C352A8013ULL; std::uint64_t aWandererD = 0xDE13164778F03F4BULL;
    std::uint64_t aWandererE = 0xB9D26DD9510547DFULL; std::uint64_t aWandererF = 0xFC5DEE0FD67A118FULL; std::uint64_t aWandererG = 0xEC7CC382210E9BD9ULL; std::uint64_t aWandererH = 0xA8FE2A02A0EC91B7ULL;
    std::uint64_t aWandererI = 0xCF374D2F43AD4A18ULL; std::uint64_t aWandererJ = 0x86F4F91A6A0E9036ULL; std::uint64_t aWandererK = 0xC3D6A97CA75819F8ULL;

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
        aPrevious = 17661981297686496150U;
        aCarry = 12420534913082362878U;
        aWandererA = 12204827976220520586U;
        aWandererB = 9990455202997582999U;
        aWandererC = 15509016876657620604U;
        aWandererD = 11266768885547064579U;
        aWandererE = 12712975579137583591U;
        aWandererF = 17488849956876225312U;
        aWandererG = 10100086243042353897U;
        aWandererH = 17866274109503357177U;
        aWandererI = 9919911874558866741U;
        aWandererJ = 10660088745566937829U;
        aWandererK = 11100178123488799581U;
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
    std::uint64_t aPrevious = 0xC8B256CAF987D89BULL;
    std::uint64_t aIngress = 0xDA94A13097ADB673ULL;
    std::uint64_t aCarry = 0xAE241B7DB0751385ULL;

    std::uint64_t aWandererA = 0x97B495CCF7A70196ULL;
    std::uint64_t aWandererB = 0xC87771105ECA456FULL;
    std::uint64_t aWandererC = 0xD2421D1A26EF01A5ULL;
    std::uint64_t aWandererD = 0xCA404F7FA6540771ULL;
    std::uint64_t aWandererE = 0x93F38F0083F9EDA2ULL;
    std::uint64_t aWandererF = 0xCCF1BECF7075A067ULL;
    std::uint64_t aWandererG = 0xE9BE344697BDE5F3ULL;
    std::uint64_t aWandererH = 0xF6B2F1F6A5305C1DULL;
    std::uint64_t aWandererI = 0xB69451B02D6E58E3ULL;
    std::uint64_t aWandererJ = 0x962A397E0824B572ULL;
    std::uint64_t aWandererK = 0xC8F60CD1760EC61CULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC, 0);
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
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD, 1);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB, 2);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA, 3);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB, 6);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    // write to: work_a, work_b, work_c, work_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, invest_a, invest_b, invest_c, invest_d
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
    // write to: snow_a, snow_b, operation_a, operation_b, operation_c, operation_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, expand_a, expand_b, expand_c, expand_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
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
    std::uint64_t aPrevious = 0xC8867CE50DE99745ULL; std::uint64_t aIngress = 0xFDF65DA9DAC8A606ULL; std::uint64_t aCarry = 0xECB12A4A42BE7EB0ULL;

    std::uint64_t aWandererA = 0xB736A59F43D218F5ULL; std::uint64_t aWandererB = 0xCFECF66BCCEADE85ULL; std::uint64_t aWandererC = 0xA7D078DCA36CBC29ULL; std::uint64_t aWandererD = 0xE36FFA9792E7655BULL;
    std::uint64_t aWandererE = 0xC7A20E1A22C2B6D8ULL; std::uint64_t aWandererF = 0xF2489CBF66F4C4FAULL; std::uint64_t aWandererG = 0x8261E6EED0F518BAULL; std::uint64_t aWandererH = 0xDD854591FA21D112ULL;
    std::uint64_t aWandererI = 0xE369821D13823C81ULL; std::uint64_t aWandererJ = 0xE3582313CB050ED8ULL; std::uint64_t aWandererK = 0xD19F9DF8BF77FD50ULL;

    // [seed]
    {
        aPrevious = 13041965906890091440U;
        aCarry = 18225586299302667084U;
        aWandererA = 15063109403334330103U;
        aWandererB = 15796447870597779493U;
        aWandererC = 12084335045472848747U;
        aWandererD = 9579114266396424187U;
        aWandererE = 16395607994467052132U;
        aWandererF = 10299901811990203938U;
        aWandererG = 15703011677923150221U;
        aWandererH = 10147569224436299369U;
        aWandererI = 15725722713416325123U;
        aWandererJ = 14223958219961217227U;
        aWandererK = 15931251649115902752U;
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
        // read from: aOperationLaneA source quarters 0, 2, 3, 2 with offsets 2106U, 3676U, 922U, 3224U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2106U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3676U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 922U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3224U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 0, 1 with offsets 2U, 4785U, 6470U, 3510U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4785U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6470U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3510U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 1, 0 with offsets 7573U, 7735U, 5494U, 6974U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7573U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7735U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5494U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6974U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 2, 3 with offsets 452U, 2579U, 5875U, 1470U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 452U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2579U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5875U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1470U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 0, 1 with offsets 710U, 1748U, 1131U, 888U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 710U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1748U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1131U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 888U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 2, 0, 1 with offsets 1571U, 429U, 369U, 64U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1571U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 429U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 369U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 64U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 2, 1, 0 with offsets 1445U, 658U, 575U, 13U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1445U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 658U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 575U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 13U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 1, 0 with offsets 1088U, 999U, 906U, 796U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1088U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 999U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 906U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 796U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 66U, 702U, 1617U, 477U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 66U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 702U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1617U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 477U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 2, 1 with offsets 5372U, 4251U, 346U, 6065U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5372U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4251U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 346U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6065U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 0, 2 with offsets 3272U, 6452U, 6540U, 4950U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3272U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6452U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6540U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4950U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 3, 0 with offsets 6922U, 4295U, 6009U, 801U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6922U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4295U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6009U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 801U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 1, 3 with offsets 396U, 1458U, 5481U, 5246U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 396U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1458U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5481U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5246U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4922U, 571U, 4724U, 3027U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4922U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 571U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 4724U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3027U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 475U, 1129U, 430U, 1272U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1272U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 398U, 1895U, 458U, 1980U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 398U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1895U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 458U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1980U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1890U, 346U, 515U, 643U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1890U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 346U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 515U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 643U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 2024U, 1262U, 879U, 908U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 2024U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1262U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 879U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 908U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 3, 0 [0..<W_KEY]
        // offsets: 1281U, 942U, 112U, 1908U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1281U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 942U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 112U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1908U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseASalts = {
    {
        {
            0xD0F30FF892B91C07ULL, 0x5362AC843F020221ULL, 0xE3795D5AF37FB87BULL, 0x37AA415DE7A92D3BULL, 
            0x1CDFC562F6F0F78CULL, 0x3090E73D4F9A93DBULL, 0xE694018AC008C984ULL, 0x88825C1A3CFB8DE8ULL, 
            0x96DF7B69F0034352ULL, 0x93E9CF3CC19059E6ULL, 0x93331575F30E8250ULL, 0xE35718869083AC9BULL, 
            0xB00E4F0BEC23E095ULL, 0xF696858E4BD6DFF1ULL, 0xB9C0698EAAEA39BFULL, 0xB3BAFFE144BA7F2DULL, 
            0x1261181556B19C5EULL, 0xA9111C0D351C9FC6ULL, 0xF8263420546D6228ULL, 0xB296B0162858B5DCULL, 
            0x1BDD7CB867836680ULL, 0x6EE9AF8531AC91EBULL, 0x129DA6E188A94DF6ULL, 0x340B76D09A381D2BULL, 
            0x8910099935C834BBULL, 0xBA5919BC93127074ULL, 0x08F4E9C7C40BE510ULL, 0x57F10780F4ED5109ULL, 
            0x73AEEC7ECA330457ULL, 0x1BB9F6F6DF74E363ULL, 0xF41B3DA171049A10ULL, 0x926EBB42E47897BBULL
        },
        {
            0xF3C4C0C7BF4EC3F3ULL, 0x4F7F42816C172802ULL, 0x04D92940BCC77E60ULL, 0x615C85599B3BEF7FULL, 
            0xE2EF9E2C1FF19BF6ULL, 0x289ECB5842C87F40ULL, 0x33C2F1907A9675ECULL, 0x1DA15CD082359360ULL, 
            0x89D6D79026A73381ULL, 0x72D5A810CB2F5EBDULL, 0x904D9035A3DF278BULL, 0xADC4DEE7CD11DD8BULL, 
            0xF23A18FB2CE2AEBBULL, 0xA10EB7A101E6BEF3ULL, 0xEF34BEEE0A18B016ULL, 0x08AEFA6AC61E712BULL, 
            0x4347A6FCFB5977BCULL, 0x70CC049E31609EF5ULL, 0xE59851432154681FULL, 0x86D79A7FEE72A241ULL, 
            0xA34EA521AF6D4DF1ULL, 0xB06B6AD561736278ULL, 0x4AA1F732441EE60CULL, 0x102AC50AC6E5E3EBULL, 
            0xC9FF883E56B03D0FULL, 0x4629008DF0EA50B8ULL, 0x5510F16D0ECAAF93ULL, 0xB0AE1D390943CFF7ULL, 
            0xFE6EA589F2D4C5A1ULL, 0x1058050A401562C9ULL, 0xB540F62A9F52CCE3ULL, 0x08BB1462715411D4ULL
        },
        {
            0x11383239E47233CBULL, 0xD52E3B5E2F3B09B6ULL, 0xF6D3AE81AFD2EB75ULL, 0x098DF2CBF71C2611ULL, 
            0xF585A8883883A334ULL, 0x6031DF3768AAD4AAULL, 0xFE5728D75AA89F76ULL, 0x5FB8B43529328807ULL, 
            0x35F35406907FCA66ULL, 0x14DB9EF0DBAE3977ULL, 0xF940C53D4E979469ULL, 0xD03FD848E93DBE5DULL, 
            0xADD45D809466E41EULL, 0xB9D2B2E55DB9EE35ULL, 0xD7FC08DB0E627354ULL, 0x63B3FC8CA76C7581ULL, 
            0xA8A691F4B898BE7DULL, 0xE256A281576528B7ULL, 0xAB5773FE33BB6EE7ULL, 0xC3D59A9130C8502FULL, 
            0xA3365143E34178E6ULL, 0xA1646596D180C3B1ULL, 0x2651FCC8F34DA94BULL, 0x36AC9990512803DBULL, 
            0x0BDABE70B154864DULL, 0x4BD6939B6FCBDFCBULL, 0xA59CCA1E611009B5ULL, 0xDCBB3A0D2D63314FULL, 
            0xCAADB343B593D58BULL, 0x4D38FA98353BD8ECULL, 0xB1F6B09E65181254ULL, 0xB24E22E8A98ACDB2ULL
        },
        {
            0x3F4595B2910FCC8DULL, 0x59C4AEC438240EC6ULL, 0x7D7FBACBA2EEB3C4ULL, 0x0E63A857D1FA9775ULL, 
            0xD4CC1F73D7100E53ULL, 0x763D3C64F2AF81A2ULL, 0xAB1C622EEF4A39DFULL, 0x6DF90172DE301517ULL, 
            0xDE752F4E577D87A9ULL, 0x2DCB85DBC0F19D02ULL, 0x6671F42427A5E43FULL, 0xA3CD08001F81D13AULL, 
            0x71C8EC68857D91ACULL, 0x7A0121F2989A0839ULL, 0xC42A0F5C7E753255ULL, 0x1790033F0B8ED52BULL, 
            0xCC6B419E6E5A2671ULL, 0xACAA2B0D175B09A4ULL, 0x7A05B102EBE64C31ULL, 0x89AC42081F5080A2ULL, 
            0x62FE2656457C67F2ULL, 0x17422F6B089B03D8ULL, 0x0A9A7C7AE2793217ULL, 0xAA82A2339C94D8CBULL, 
            0xB78109149DF6E3BCULL, 0x6B1ABBAD0DEE8E50ULL, 0x245A31BDECEF3F6CULL, 0x0338BC3A364E001EULL, 
            0x0ADE0C70899BE3B7ULL, 0x10EA12279C6D203FULL, 0x20163F46F3D0324FULL, 0x361D025281AC8F6DULL
        },
        {
            0x1103D6BDC14A088CULL, 0xCE7497C1EED1794AULL, 0x00A4C65FA9C8E119ULL, 0x83FD9BDF7A7CD463ULL, 
            0xE045F878410D850AULL, 0x89F7A8AD1D5839F9ULL, 0xE564E8C9D4D2E285ULL, 0xDE2D1213618EF614ULL, 
            0xD1BD18419BE73050ULL, 0x31D6D6D7C9C33600ULL, 0xCFC8F0826FAE6C6CULL, 0x6248F863EDB7736FULL, 
            0x0B74D5ECE1CED8FBULL, 0xF7499133562FED3FULL, 0x1CA6A3F06BF987C3ULL, 0x9F89315598DE8E00ULL, 
            0x70621A3DE0D9059BULL, 0x533A5C223EA4482EULL, 0x7D327EFFFAC231F9ULL, 0x4B2176AD3AC6075CULL, 
            0x0CFD1247CFFAA03CULL, 0x1B90806239A8DFBDULL, 0xE59457BA7BEBE24FULL, 0xD237735AD129D97CULL, 
            0x8DB237AB91CD7A29ULL, 0xB6549E1A89E95056ULL, 0x6EC3B3BC11815F44ULL, 0x411ECCAEDDA5E8B0ULL, 
            0x85136E28A7397C9CULL, 0x9E45DFBA9709D1DBULL, 0x80DB873C8351D500ULL, 0x30378DEB79331F04ULL
        },
        {
            0x0E25CDCDCDCD6FD2ULL, 0xE4CA40985D7B387EULL, 0x830910D4B5875209ULL, 0x9D2279552B9698CBULL, 
            0x8959EBBBF759C7EAULL, 0x822B3DED6B4940EBULL, 0x3CF809F8E26AB979ULL, 0x8A4AA67301451A2DULL, 
            0x17516557B926AD8FULL, 0xB06A62C2DC9971CCULL, 0x7E5D09F920EE8180ULL, 0x337154648299E8E1ULL, 
            0xD10014060B12CCB7ULL, 0x9A6A84EF761382F1ULL, 0xA84360CC4E46F7FEULL, 0x33D16F9D76D7F33FULL, 
            0xAECF3EAAB97825BDULL, 0x25736C9A298DB426ULL, 0xDD3CC0DF346F2467ULL, 0x916DB9C532CFC428ULL, 
            0x48A5DE3C127B528DULL, 0x68B2E584EAC7CF4DULL, 0x26D9D5C8F65A9BAAULL, 0xAC96B580C3AA2FC0ULL, 
            0x4D244B41DD268533ULL, 0x52FF208778A3C527ULL, 0xBACD68B038B5FB96ULL, 0xA330EF081296BC53ULL, 
            0xA0F8C0E318B22455ULL, 0xC2DE1ADB17001B23ULL, 0xDD6FB22ADD1EE67FULL, 0xCB7D430ADC0F1A22ULL
        }
    },
    {
        {
            0xC95AED4C83AD2B42ULL, 0x7F2F2EBB4550C1ADULL, 0xA9F059C6AA78428EULL, 0x9DE47F8C7C66772AULL, 
            0x5768D6E9CE158C88ULL, 0x0E522F765E07C948ULL, 0x5451184052B0902AULL, 0x57D8787F33618C56ULL, 
            0x3F116410489FBE12ULL, 0xE223B1E47F57DD22ULL, 0xC25F1E09572A207BULL, 0x54618050EFFD5C63ULL, 
            0x7D1B65D36C770242ULL, 0x4A058A654A3A0815ULL, 0xF9161D4060329C37ULL, 0x3BAB71D24F8B10FAULL, 
            0xF2F1101AC00F199EULL, 0x359438A419C2C7C3ULL, 0x4FDDF0F798393CB4ULL, 0x1658FF14628E1465ULL, 
            0x21A5886DF671C58AULL, 0x45BBDC1FD6454C27ULL, 0xD7BAF995597E3C63ULL, 0x2083CC0083F724FEULL, 
            0xA68A00611EE1A4A6ULL, 0x546A96CA5E95A11BULL, 0xAC7C8572C084E70EULL, 0x13B80E3CACBDA3D0ULL, 
            0xEA943AE9B13C380DULL, 0x86751B9AF9166EE5ULL, 0x478D1DA2A173FEEDULL, 0x97C3F66BBA0A4086ULL
        },
        {
            0x6C6BF5734827B02FULL, 0xF10281CED929B6AEULL, 0x2AD30705CCD8EC98ULL, 0xDBAEEE3DD382145FULL, 
            0x4748C2B343B54C4FULL, 0xD504EAAE9C8E64A3ULL, 0x8C431C414E4BD43AULL, 0x3B87B4487C215F10ULL, 
            0xB475C91FA3751239ULL, 0xA8BA4827F0F10527ULL, 0x2B7ACF624DA201E2ULL, 0x3104D0E186C600D8ULL, 
            0x50833C5AF107CDB1ULL, 0x2A745CF408FFD576ULL, 0x5991052ADA758E22ULL, 0x74C0664AC4CD901CULL, 
            0x4DE87DEE4441321EULL, 0xF849F4443EDDDAB0ULL, 0xA6F599A3BDEE70A6ULL, 0x4407E130CD9E7D2DULL, 
            0x4FECBAA4C9DEE253ULL, 0x8ED38144375D700EULL, 0xB4190F55FEA459DDULL, 0x2592225E7198A3BBULL, 
            0x7230BADDA99A7E94ULL, 0x4E6214381559311DULL, 0xE890AE68BCB7AAB8ULL, 0x9CD98383EDC37A48ULL, 
            0x07A9FD31DE17842DULL, 0xA65B835CED70A8A2ULL, 0x8767787F3C97129CULL, 0x42E6923E1FE02B96ULL
        },
        {
            0x2998254FFD9B4B44ULL, 0x351F0A9D7841300BULL, 0x921D154F313E54EEULL, 0x8A8A2769DF12E605ULL, 
            0x7DA895C161DAEE3FULL, 0xE05477531C481E3FULL, 0xDBF32575629493A2ULL, 0x71367CEC51559127ULL, 
            0x3F4F453B0FF5149EULL, 0x47BD685E0384BB87ULL, 0xA82912BE6A4ACE7AULL, 0xDBC9EF1B8EFFE419ULL, 
            0xB8DCCD74BB82A787ULL, 0x94C186E96AE7F9BAULL, 0xAB17DF323B4107FFULL, 0x9B79A9FD7508F892ULL, 
            0xA07CE9A20FD56E90ULL, 0xA02F831A3F2F33A8ULL, 0x6B19F6B6928BF17EULL, 0xA3E8980AB59E44C1ULL, 
            0x97B71ED7ADC3CCD0ULL, 0x442D0EE34F620D75ULL, 0xDBCDA12B8F9BE38AULL, 0x74668C0A166D1399ULL, 
            0xDA2EC8C2442BA7BBULL, 0x95F0161AC30A915FULL, 0x39FE8CD8245D1C9FULL, 0x352C04162E7962FCULL, 
            0xDE55177B92F1F4A0ULL, 0x0D066D9BE40C61CEULL, 0x23B3CAF5DAF276BDULL, 0x2191C9C39E1FF732ULL
        },
        {
            0xB074B19E0980E5EBULL, 0x99E1DB14A03C5916ULL, 0xC77CDB3867AEA8EAULL, 0x96DBF04751CB86B6ULL, 
            0x8857CBC101C919A0ULL, 0x4D9B204C5F96C23BULL, 0xB6013DEEB06D2C21ULL, 0xAC5808F7C1131205ULL, 
            0xB991AA0EEDC020FEULL, 0x498586240699798EULL, 0xD40EE164CE3B24CEULL, 0xDD8D3874AFA400FCULL, 
            0x548FE675153D7BEFULL, 0x9DB4B6F9F99BB396ULL, 0xCC8A63C2A4AB7A78ULL, 0x34A9C1B6AC8F457BULL, 
            0xFD3F5708B8286F84ULL, 0xADC6186C2D42D2E4ULL, 0x04E80429BBCA0B86ULL, 0x5DC2EB4957FB5B7FULL, 
            0x34528D14CCC9F126ULL, 0xBB5037D182D5A743ULL, 0x15A6646464E756B8ULL, 0xA5C7383B3E1C34AFULL, 
            0x42AA3CA66A0ECDD4ULL, 0x315DCF3BDD86EB13ULL, 0x72D1B302C6114751ULL, 0x8B946077BE51ABD2ULL, 
            0x556B3021EA984A1EULL, 0xBF3126932766A441ULL, 0xCC7002D169267C7DULL, 0x17416AD3BC587C4EULL
        },
        {
            0x607AC10057044507ULL, 0x27F1B2B07AE9768BULL, 0xE66B13651A0A8954ULL, 0x4AC3007395799559ULL, 
            0x191B845A8375580CULL, 0xF1E6C5ED9E47568FULL, 0xE0404DE4B1211826ULL, 0x7A6086B2EFAB4A4AULL, 
            0xCB8AB733D2A77BA6ULL, 0x9D5EEF8D178242F4ULL, 0x822E9FA9C039CB2EULL, 0x5434B6B4A0A25691ULL, 
            0xE5FCF9470BDEB2CDULL, 0x9066F8BE059AA823ULL, 0x7120CEA286B7C8E3ULL, 0x5821045BD208A853ULL, 
            0xC8931C6D1590536FULL, 0x3D0BF1D8AD0F2A2AULL, 0x300EE614F72A3E3FULL, 0xC5F1C836EE3E0FC4ULL, 
            0xBFF8A0981BCC23A6ULL, 0xC04FEF210F1FC645ULL, 0xAB1B82EEA9DF1B89ULL, 0x901FD588B9E89C30ULL, 
            0xF1D215A80EAA0358ULL, 0x509B4E31451BF0A2ULL, 0x42C0DBD90ADB34D9ULL, 0x973D95C1CF2F6358ULL, 
            0xAAB7517547D046ECULL, 0x73B4788B00D5EDD0ULL, 0xF76AADBB5E79F9DDULL, 0x3CC4821DF108ED67ULL
        },
        {
            0xAD0C8540A1CCE5A1ULL, 0x9AC00251087201C2ULL, 0x2F7EE0E6D1D87626ULL, 0x8B3ED135A7B304B2ULL, 
            0xFC298A49A81E25BEULL, 0x6111039078AFC57FULL, 0x172A3725DFC1E345ULL, 0x5AFBEA70EF0DF2CEULL, 
            0xFA195EBBE50141B0ULL, 0x6807424C799CECCEULL, 0x469035B508D946EFULL, 0x9C61233CB5E5015DULL, 
            0xC987DF02DEF77D90ULL, 0x5B992D8B14DDC493ULL, 0x5BB78609E125627BULL, 0x06CCBF3795003112ULL, 
            0x1ABA0B1E0A8FF1D0ULL, 0xA0CDF873AAC66354ULL, 0x425141FB647E4540ULL, 0x6C3A924081FC31F5ULL, 
            0xA74C29D3EF91D6C9ULL, 0x1291AC8318868C19ULL, 0x5CA8995CAE7BF253ULL, 0x111FDBF3F1A09C85ULL, 
            0x5C3D3373D098DA88ULL, 0xEBEDBCA67B102DBEULL, 0xF66C47E326ECC838ULL, 0x5439D36AE999ED8AULL, 
            0x99759D63FC9B41E4ULL, 0xC09359B694868E2CULL, 0xA9B612DBF31CBD68ULL, 0x608098C8ED69BAB6ULL
        }
    },
    {
        {
            0xE26AAF8CBA389A03ULL, 0x1CF55CB3AECF51BEULL, 0x57F994EED3384C5CULL, 0x8E4557FA20785975ULL, 
            0xB86DAAD663B05B92ULL, 0x097DB39691B12095ULL, 0x141322988BAEFD8DULL, 0x4372DCF6FB85CD61ULL, 
            0xEE04FA7ECE03C630ULL, 0x445DC43940997838ULL, 0x64CB7314A6B9FEE8ULL, 0x6A919D357CD38FBAULL, 
            0xA822E87C548E6446ULL, 0x497464AEF4408929ULL, 0x66E7B1D648D0B476ULL, 0x1256162B0CBDF89DULL, 
            0x62C030FB6B528EFDULL, 0xD764D6D35B65EDD2ULL, 0xBF13D0CF30E438AFULL, 0xADC1B3D19D285C94ULL, 
            0x79DBAFC992BFF970ULL, 0x029423F2DDB80C37ULL, 0x8DEF4BF6D647D4A9ULL, 0x302F7026B21AE1A2ULL, 
            0x24364F1DB1D78CE3ULL, 0x88D84C83E3C3C365ULL, 0xBC214D59ACD5C788ULL, 0x0FEC2E93DA0958BEULL, 
            0x071B050473E3CE11ULL, 0xAAA1FC0729F04B7BULL, 0xFF595FABFE5B7EC8ULL, 0x711075ECA35BB400ULL
        },
        {
            0x3CDCA96DD0BC3371ULL, 0x7342675705E5688CULL, 0xD65F8E96B120896DULL, 0x98A6D4A9D3188F10ULL, 
            0x2917EF3167325C2EULL, 0x4C5EAEC1283FC49EULL, 0xCA9B01D71C26AFFAULL, 0x02B8551F272B19DCULL, 
            0x61861A7EC360E087ULL, 0x9E6255B5553B372BULL, 0xDA0D7D7F11012191ULL, 0xD931B5753FCA9FA0ULL, 
            0x4BE8188D67ABAF98ULL, 0xDA10B33B78F6E6C3ULL, 0x9AB95D312E4CBB7BULL, 0xF72630693A37E474ULL, 
            0x67F36D4B6FCDC50BULL, 0x99BBEC74869D388BULL, 0xF631AF33ABA3E634ULL, 0x3B3B67F66007A26BULL, 
            0x2673B42D5E3AF8B3ULL, 0xB2457FD11F0FFC82ULL, 0x7EBCE01E6E02AC56ULL, 0x8B2392EA928710C2ULL, 
            0x59B4AFDEC66C1302ULL, 0x3A9DF7402C2DCCCBULL, 0x89101323D9C74EC7ULL, 0xC3C8D58E61FCAAA3ULL, 
            0xD25A333013FB5457ULL, 0xFF3C9CD671E19D92ULL, 0x0B7EF7B4C7C53E2CULL, 0xD950C5F753AC4A9BULL
        },
        {
            0x3ACC3A025DD6C820ULL, 0xC87279069B2537DFULL, 0x2794B570D503B152ULL, 0x14A6376AAC0D2B70ULL, 
            0x120D53882F800915ULL, 0x4B0172884556DBCDULL, 0xA1C2AFE46135DA9DULL, 0xBEE3F1F548087131ULL, 
            0x34DEAE78C0FEF0C3ULL, 0x9CEBF1CFBD8A43D7ULL, 0x13FBF2927B225296ULL, 0x8EC6522E26AA911FULL, 
            0x7B5A4E8317108952ULL, 0x29C4783F8AC66C70ULL, 0xC63D52528D487696ULL, 0xFC527E521964AD7BULL, 
            0xAFAAAC3B20ED7568ULL, 0x13AD0E10F4BF3ECBULL, 0x93DCCD4879E774FAULL, 0x94C20B1F661B1749ULL, 
            0x9DE23198EEBB0DF1ULL, 0xAF1D5098A1CA6F6AULL, 0x0CB41D1BEB122BDBULL, 0x95001879BD6F8BDDULL, 
            0xADA62C63F05184A0ULL, 0x9F0144CB50215D87ULL, 0x7325247A0EE32C33ULL, 0x33F0A94A58D2AFFEULL, 
            0x79DF4CCC6BBBCE87ULL, 0x4E9A621F7DB37555ULL, 0x836436EFDAF64380ULL, 0x986A1FA5B7A7C70FULL
        },
        {
            0x565E8F7461E702B9ULL, 0x21511CC7A382F5CBULL, 0x1F053E5EA3DA1DACULL, 0x38933C6CD876FC77ULL, 
            0x6BE3B4505A770B91ULL, 0x0ED5EA4EF1255556ULL, 0xCC2D42970AA39491ULL, 0x9896E294B190341FULL, 
            0x4FA685CACFB52E15ULL, 0x4E251249E74167EBULL, 0xB62897E3F361B58CULL, 0x2149D3C943E1FB91ULL, 
            0xCF30D6857E7B3F6DULL, 0xFA7FFE62A7E9E1C1ULL, 0xEFBFF9B6E21DC10FULL, 0xB94A6E7FAFE4E1CFULL, 
            0x0CD1A7110A163D07ULL, 0xDF7588BF949822B1ULL, 0x8DABD794B5953600ULL, 0xA030FF57252B4ED8ULL, 
            0x40B8E7F20CCA91A1ULL, 0x855F911107837436ULL, 0xBDDA09BF2A835AEAULL, 0x7016B35F368EE367ULL, 
            0x2B496E0CB5F4D4EFULL, 0x4FA1962FC5BBA234ULL, 0x272DD198EF3AC877ULL, 0x1E155A8A993FAF92ULL, 
            0x4A0BAA61DEEE1E12ULL, 0x1B70DF184AC518E5ULL, 0xD9661C69BE27C6DFULL, 0x8CA8A9C1471AEF9BULL
        },
        {
            0x823A95608536D534ULL, 0x600A70A88B9B2811ULL, 0x89B2F15F39D4DED7ULL, 0xAC5279411B414675ULL, 
            0x145BBBA89564D6F1ULL, 0x63EC85DB38598CD6ULL, 0x1CB45D82CEB4F837ULL, 0x2755B54B2BABEA16ULL, 
            0x97264A84E07786E3ULL, 0x179A2F65B4740AA7ULL, 0xDAC63100B880E27FULL, 0x37AEE1A83A281D6CULL, 
            0x02BB284FC21C9273ULL, 0x7F00B60F7ADC5629ULL, 0x8815EAE6340E326BULL, 0x821A2ADF5790D72EULL, 
            0x0E998EB83D82168EULL, 0x23C91ED66FC6428CULL, 0x5E1BD1FEFD70DA29ULL, 0x69EEACDFEA499D36ULL, 
            0x86789E07C3070351ULL, 0x7FB7CB21C7914C9BULL, 0xF38A09F9AA578996ULL, 0x406742B32E266D9EULL, 
            0x5676C96A82F38AA5ULL, 0x4F5D8FDEEBAABB88ULL, 0x214DE9A8F94FF3F9ULL, 0x1A3FF023222B3EDBULL, 
            0x2979DD4400367906ULL, 0xA40636DB0D5178B9ULL, 0x70D718C8693F9FFBULL, 0x68451A601C02EB95ULL
        },
        {
            0x4752C6518B900C13ULL, 0x6EA71E5154F54EF1ULL, 0xEAC229739750DF2CULL, 0x4AED45B2F12041C4ULL, 
            0x83CDF10EFB8F5C8EULL, 0x0A17AF24F699401DULL, 0xCF18B5058E99F7C4ULL, 0xA32F8C54680952F8ULL, 
            0x17020C40FC451E8DULL, 0x3BE63BADE83B8028ULL, 0xCAABA273C0EE8985ULL, 0xBCB8097A9ADC6C54ULL, 
            0x9AA4BFD5BF53C95BULL, 0xA38067A8BF7D50A0ULL, 0xC95B6AF31AC0ABF6ULL, 0x50E000A1107D8413ULL, 
            0xA2C29262461111ECULL, 0x6AE9A8E752DE1195ULL, 0xF8B73542C00F1B1FULL, 0x7EDB9EDF7F2D4A6FULL, 
            0xCE9412E015E47EABULL, 0x324287F3F489209EULL, 0x20F36BAFED69E417ULL, 0x267B43447B5CBE4DULL, 
            0x753182DE5B53779FULL, 0x839E15AA2036442DULL, 0xECDA11A0D74DA83CULL, 0x5205183E9769D1B5ULL, 
            0xCBDDE65EDAAD69DCULL, 0xE1287B681C6156E5ULL, 0x76EB58600C669967ULL, 0x25226DB8FDC7520DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseAConstants = {
    0x46E51446EC91F07BULL,
    0x43775179AEDCA893ULL,
    0x5AA0C93A3930D310ULL,
    0x46E51446EC91F07BULL,
    0x43775179AEDCA893ULL,
    0x5AA0C93A3930D310ULL,
    0x817188505EA9DD43ULL,
    0x4CF1EDC25F7D80ABULL,
    0x7E,
    0xF5,
    0xDD,
    0x26,
    0x2D,
    0xE8,
    0xA8,
    0x84
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseBSalts = {
    {
        {
            0xC0B492E31593D7FAULL, 0x8AF5ACEBFC21B86AULL, 0x2C45A8F1644B0D74ULL, 0xF55AC6C3E1AA4AD9ULL, 
            0x6F32330647465472ULL, 0xFE4CB4F8AF99B2EAULL, 0x24B747155BAA29EFULL, 0x498D5698DC5BF5D2ULL, 
            0xEF973553835C41ACULL, 0x516423722F94F107ULL, 0xAD0A4206157B618FULL, 0x342EDAFD2EE31AC3ULL, 
            0x17F8A27BFB2F59EBULL, 0x05B6C60FE4A2C899ULL, 0xBF313D01721F1915ULL, 0xBC0792171D639D4BULL, 
            0x48D8FECF46AB7E5EULL, 0x85647D40521CE5BAULL, 0x20CEAE69444679C7ULL, 0x339FC0987D009C28ULL, 
            0x73C1EC3670A74CFCULL, 0x3FA545427847CDECULL, 0xE0204FA7E7D6626FULL, 0xF8CB90AC7D3F7285ULL, 
            0x494863B2765E2710ULL, 0x971150860C062316ULL, 0x243E161EBC764ED0ULL, 0x93C2301113AB7F1DULL, 
            0x49F194F46BB5E9DDULL, 0x7B1F9232C041BDE1ULL, 0xB462C49FA00680FDULL, 0xFD9B2A4E185772C0ULL
        },
        {
            0xAC81810782586368ULL, 0x06B9E5FFDA546DF8ULL, 0xDFAB6FA9850AA595ULL, 0x011693294B328188ULL, 
            0xE7FA47C301587149ULL, 0x31D598511211BEA8ULL, 0xFA21FEACA60A956BULL, 0xC6FA3406A1D1C893ULL, 
            0xCFAC0B0AC88582F8ULL, 0x34E670A8C44B6E04ULL, 0xB43DB9EF59D93B92ULL, 0xEF317BC2D7760EF2ULL, 
            0x987A9C34C2118310ULL, 0x3F12FED58971D1FEULL, 0xEAE5CD3B1D14C35EULL, 0x67A63C495DDA4B8FULL, 
            0xB0799EE3677D9F61ULL, 0x6953A96BDDFF89BCULL, 0x664814FE76DB90AFULL, 0x4B2910A1FB848E28ULL, 
            0x2B67D441880448E5ULL, 0x5A85F34146626571ULL, 0xBEB240758B4590E1ULL, 0xD74738741A6A52D2ULL, 
            0x6524F9ADE7C883F6ULL, 0xF89E754FB2B13652ULL, 0x5A91C646108A492AULL, 0x677E80E5939CEE57ULL, 
            0xAD3B73B8EF0D999BULL, 0xAFEC6AA666E4CC7DULL, 0xAC57D125AC01B505ULL, 0x74658C9D980F89B0ULL
        },
        {
            0x907BCE4915328BEFULL, 0x0816395A75804A59ULL, 0x69FDBC7F6AE56AD8ULL, 0x175899BD6E668B42ULL, 
            0xE99C4C458A816044ULL, 0x8D0317B8D8C2EB95ULL, 0xEDE49FDEB0C2944AULL, 0x461A3C0AD59418AFULL, 
            0x83DC0766C85AC2D5ULL, 0x0DDC2D3C49209F80ULL, 0xE1E7DFAA8B4FE753ULL, 0xCEA486FB14D84F99ULL, 
            0xDFC9B222499AF840ULL, 0x8BB9D5BF02E93892ULL, 0xA6D61744BC28CDA6ULL, 0x44ADD095BB856CE9ULL, 
            0x37C3F147F3E48A22ULL, 0x2040C9E337509345ULL, 0x64414991C92AEEFDULL, 0x651DC3C40E1ED57EULL, 
            0xD53708FD892D5241ULL, 0x3A9A0081950EB7FBULL, 0x7AE53FCD256095CBULL, 0x94C488C67B8DA0D4ULL, 
            0xDE1A122C4D6A9F61ULL, 0x8CD729931F64A4E6ULL, 0xB3823262746923D8ULL, 0x25FD88C1736799F3ULL, 
            0xE65D286BE102963AULL, 0xD292284BE4081E71ULL, 0x58AEF27DF755ED63ULL, 0x33DC717273B367B4ULL
        },
        {
            0xF8F8B85085176E4FULL, 0x4DFFE2A927EAFAACULL, 0xF3F1A1A8CBC248B5ULL, 0x27A2E1FFE3A90B95ULL, 
            0xE74F694E58881F64ULL, 0x1544078465D00594ULL, 0x2A57C77877D558D9ULL, 0x1FC1B9B5C1A6F689ULL, 
            0xB412E79933C24133ULL, 0x8AA3C6A0F17B92F3ULL, 0xE075914B778E056AULL, 0xA36EF58BBB63C019ULL, 
            0x3AAF926771D60BF9ULL, 0xA575FC90176DA8AEULL, 0x1E49B76BD0C608F8ULL, 0xED2A5D99E654F16BULL, 
            0xCAB4949BC583A494ULL, 0x1EE4755A0374BAD8ULL, 0xFFD093FDD14E00B1ULL, 0xA8CC4B8AD0AE9805ULL, 
            0xBC8D76296AEA869FULL, 0xA2D88267CAB9AF91ULL, 0xD82B3A4245E915CCULL, 0xDD71BC8AB6E8E22EULL, 
            0xF61972129E847394ULL, 0x35A2A10D530C36DEULL, 0x9C09D35E9EAC9A74ULL, 0x75C4CA9F8AAEA8D6ULL, 
            0x37B65CCFBC2A401CULL, 0x848D61562B10AE83ULL, 0xDC520829921C51DAULL, 0x8639B611143311D9ULL
        },
        {
            0xB2C650C10F8E83CCULL, 0xE1F328051DA25B9AULL, 0x8809AD3429647AE2ULL, 0x603142187FA981B1ULL, 
            0xCE39B926D28D4336ULL, 0xF4881C4A57ACE2A6ULL, 0xB48BA1250E7527F0ULL, 0x857568DF4B6B0ED0ULL, 
            0x706A188A0C2F5FA1ULL, 0xB16761EAA1DED674ULL, 0x58F0655ED3288C33ULL, 0x0134BCC8AE206D8DULL, 
            0xDC9A300ABDA2842BULL, 0x479A0E96BEFF27CBULL, 0x0AAD252C550EE6A5ULL, 0xE6AE4223E55A7AC3ULL, 
            0xFC4D3245B0E3F6EFULL, 0xADEB2373A15C5E93ULL, 0x5CB3E66D87B36065ULL, 0xCB2B66AB8D4C6563ULL, 
            0x509E826969984192ULL, 0x62DD58C0410E3869ULL, 0x8B4F21850AEDC311ULL, 0x6E48B8961F8C2486ULL, 
            0x5D9871E3B4653A33ULL, 0x9C7A66A6E2263856ULL, 0x8336C20C18CEDA76ULL, 0x5AB09D586BF04C12ULL, 
            0x7E8837F05F3D71DCULL, 0x0FB4B83EA1EA0384ULL, 0x45DE3F7B7D0D354DULL, 0xD5B2765DB77C9A71ULL
        },
        {
            0xE9F5E3097358C4D2ULL, 0xF059E579B96C1A50ULL, 0xFE3B6CF7CA58C408ULL, 0xDCB0713F9157240EULL, 
            0x218ACF6545419781ULL, 0xAA0830CFF0911D24ULL, 0x437A7ECB935AC91EULL, 0xBA8B8728903F75F5ULL, 
            0x47F3787159637577ULL, 0xFD6A79C7B959F7D5ULL, 0xEDCC4E45F5171A50ULL, 0x132AA8E5BBE47040ULL, 
            0x970DA5590AD5B453ULL, 0xB3F08097CE0DC3B2ULL, 0xAD9EFAC9B8777A82ULL, 0x4914C0D9F7743B79ULL, 
            0x4B3AC2E4E461A00CULL, 0x48706ABF6476F840ULL, 0x2D597F3416DC68C8ULL, 0x1C2125F495D4C367ULL, 
            0x7D211405089C9F16ULL, 0x3A4CAA853AFB65B3ULL, 0xC0F775AB1BF61E79ULL, 0x9E8E3E1D7B9A3AAEULL, 
            0xFCC6C801443CB77BULL, 0x4378FBF1ADCDC6BDULL, 0x3713AA9FA5210EF8ULL, 0x7A1882E2CBB51150ULL, 
            0xD77D2EAC1B650E39ULL, 0x3527DEFD1A2B0401ULL, 0x32809A68C542ABA5ULL, 0x830713943ACED24FULL
        }
    },
    {
        {
            0x300AAFA00E6A2C23ULL, 0x440FA78DF08D1F67ULL, 0xBA0D3602595AEDE4ULL, 0x5A4EDA39158CCB8EULL, 
            0xCA6E072B57288D76ULL, 0xC55DE83A6EEDB852ULL, 0xDD628A21DBA1C24DULL, 0xB5333A35A136A5DBULL, 
            0xACCA7DCA62A024F8ULL, 0x281D459B40AE737EULL, 0x78555D515D7E91BFULL, 0xB524EFAC17F875DEULL, 
            0x189267C892862D37ULL, 0x29420E7801E5DB2BULL, 0xF1F95D3E3F62771CULL, 0x89A7EC8CCB555F57ULL, 
            0x2EB614D27BB1921EULL, 0x6E2AF077C3B73D19ULL, 0xC08FCCCBA03A9842ULL, 0x1ACD8A6FD7214D86ULL, 
            0xEE84C6DC7500577BULL, 0x02E0CB4F9385DFCAULL, 0x47E7EBC2BD04009EULL, 0x31FED0EA4910158FULL, 
            0x98E5009AB2F29851ULL, 0x30D84FD1BB8D9D21ULL, 0xCD7C8926B0ABE75DULL, 0x73CFB6B1C381035BULL, 
            0x1021DECC11169450ULL, 0xA69839EC342EE16BULL, 0x0DEA12183B30D2FEULL, 0xE910A024E872DE01ULL
        },
        {
            0x4FC80D0D65D8A0D9ULL, 0x5B062584CB0934C3ULL, 0xF42D316DE1356502ULL, 0xA0ECCB2BCFBE57B2ULL, 
            0xCB9BD06988F50C19ULL, 0xE88B1CC650663DD3ULL, 0x207C13B3081C0BBAULL, 0x81229A72F6E221FCULL, 
            0xA6144EE0E0B3C540ULL, 0x4ECF3F4DFE34D893ULL, 0x0FFD676453E3B5E6ULL, 0xBDF3BE26A1732271ULL, 
            0x1584A4A6ED6B3CD4ULL, 0x45B19A57E2F16314ULL, 0x2B06633005E059D1ULL, 0x56096EC3CB2E39EDULL, 
            0xB894C770ACC4AB63ULL, 0x9A434C3F9301F38DULL, 0x944EC96D09F08840ULL, 0x8D29F9AA6ABF8605ULL, 
            0x87C54A662E8474AFULL, 0x87FDAE7E757F4F00ULL, 0x2B5FB54671D766B3ULL, 0xF9B160A4C3EB2A1FULL, 
            0x7FC8468CAB99C960ULL, 0x56AAA1EAEB300769ULL, 0x522836787C612849ULL, 0x09AAB593DA73BF9CULL, 
            0xA51E0AAF8B9951EAULL, 0x5DB77BE7FBB22333ULL, 0xCAB6C0FA5B6CDBA8ULL, 0x43F849B3F21C73FFULL
        },
        {
            0x5C888352E3986E3FULL, 0x7B06E6B756695A84ULL, 0xE52E63C04CE47509ULL, 0x339414328244C860ULL, 
            0x219A798654A8D78EULL, 0x845486CA0FC1B3B5ULL, 0xBD80AC553DCCF4DBULL, 0x8335966F14A6796DULL, 
            0x584B9F602FBE707FULL, 0xD9450C0E7A96F0A5ULL, 0xF52A5967793C5A0AULL, 0x4F9D54655DAFDB86ULL, 
            0x08B91B6EFA0407E5ULL, 0x13B5A7F0FCFD196FULL, 0xE52BDBF8C1BDA149ULL, 0xDCD3504D36B01524ULL, 
            0x1856193244C6F32FULL, 0x157A6CF414E44AC8ULL, 0x170DD9F4982407E7ULL, 0xEC2BEF31BAE90408ULL, 
            0xDACF97B2EAA82B68ULL, 0x9737E88E4DDFD28CULL, 0xB8CCB408DC89A19EULL, 0x6756D7FD0CA62183ULL, 
            0xAB363584B809AF21ULL, 0xC32CC9544996CE67ULL, 0x8E2345AC70CF4A25ULL, 0x8CE314CE9A89BD0DULL, 
            0xF9CD0E7CF8AA4D06ULL, 0x636EADBE26A0A0A0ULL, 0x3EA866F346CCA6ADULL, 0xE186D2332DF5826CULL
        },
        {
            0xE4305E3B5BC9E8F7ULL, 0x9B21C8122AC85BF5ULL, 0x5EF2F719896ED89EULL, 0x98AE9AC5A446098AULL, 
            0xA6A2D17C9E720EFCULL, 0x7AA3FEFC9B0B91F4ULL, 0xEC914484B31FAFC8ULL, 0x155D316836AA8067ULL, 
            0x8D31BD3B70E60264ULL, 0xE74CCDF849428EFFULL, 0x3929E2DE030E2FDDULL, 0xC46C9019199A6712ULL, 
            0x0E4B96963165A2B4ULL, 0x9FA927B2563F4094ULL, 0x33168950F6BF706AULL, 0xE9DE8308EA1B87B4ULL, 
            0x148AF8409AD22874ULL, 0xFF3F7B735330A609ULL, 0xB1D902CF62CC4B04ULL, 0x5251C5325E5E2A97ULL, 
            0x19BE2D81221B956AULL, 0xC2F9983DCBEE8FD2ULL, 0x0808BD03E847594BULL, 0xFFA7F30E0FB2A14BULL, 
            0x956F7F80B5FDC938ULL, 0xBE696508D6A0A642ULL, 0xBFD7A013D01A51D0ULL, 0x27CC213F29479171ULL, 
            0x99538FF64C3F2F37ULL, 0xAF72A9C4D224B031ULL, 0x3012A131C469FDB4ULL, 0x09155466F65287A4ULL
        },
        {
            0x390F77F458A0DC5FULL, 0xF35876DD14123E7AULL, 0x020E5F54009B1CA2ULL, 0x98405887A40ADF0DULL, 
            0x00461DE8D72F8BEEULL, 0xA066C76B1A6613FBULL, 0xD2F5B6EADDDBC789ULL, 0xFC689B98B1D6873CULL, 
            0xBA298A8A4B131494ULL, 0xDAFF7B45D493DD8CULL, 0xA532AC1FCDF42AA2ULL, 0x1D988212AD483F67ULL, 
            0xB9F493E130B456C1ULL, 0xE91AD9235D08A17AULL, 0x6ADED937F31C1829ULL, 0x148BF5D14C06C59DULL, 
            0x705DC70BDA99D0C7ULL, 0x1F69CAA420D0001AULL, 0x566891812E427A63ULL, 0x322FACB021D4734AULL, 
            0x36F8E9E50096A532ULL, 0xB94BB3ED37AE8DA5ULL, 0x6F0C19F3A7045886ULL, 0x021B5BFAB4F5FC40ULL, 
            0x997AE54A279745F6ULL, 0x560D183F9C3735D0ULL, 0xE17786D9A3F9FD6CULL, 0x00052908E2791B6AULL, 
            0x6573371D8286F283ULL, 0x4F7B315CB7541F0AULL, 0x7ECACD5631A1630BULL, 0xE006019F87A75A37ULL
        },
        {
            0x3ABFF1C12D470E76ULL, 0x3944F7982E2623BDULL, 0x6F9B1F290A909018ULL, 0x7CB9ED74C85ECABDULL, 
            0x5A12AE5CE44C0426ULL, 0x9287165292EB13ADULL, 0x3A03322C1732F916ULL, 0x6296E9D01F1EC762ULL, 
            0x4534FF7EA2073630ULL, 0x921C44F513CB2412ULL, 0x54A767218EA48130ULL, 0x63665FA1F5A8601DULL, 
            0xCC33D79F0A6A8ACFULL, 0x820A2463AD452758ULL, 0xAD1C2130ABAD3B2DULL, 0xC21E035EF93088B6ULL, 
            0xF0F6ACF20E5DCC3DULL, 0xA8E07C93044726BCULL, 0x5BB7C2B43F4052BDULL, 0xA5B0D90B16B11DA7ULL, 
            0x8B3574DEF7308861ULL, 0x7B0399EF3E38BF5BULL, 0x5BC93711D76E096EULL, 0xC893E141705B4D0CULL, 
            0x72D870F3E93989F1ULL, 0xF9256565B7FC3716ULL, 0x30FBC64616EFD655ULL, 0x91320FE5DA1D744BULL, 
            0x2B54194BCF3893CBULL, 0x99249180BAB8F7A6ULL, 0x2BA78583947EB128ULL, 0x06289742B54E0E60ULL
        }
    },
    {
        {
            0x8ED3A7A34DD50588ULL, 0xC8089BFD62ABAB25ULL, 0x9532BE48966B66B7ULL, 0xA9648B544705A564ULL, 
            0x2E1919DF429E19F5ULL, 0x1AEFE4F1D876F7BAULL, 0x0CBB907E1FA9889EULL, 0xEEC7CE136FD9000DULL, 
            0x55E16E7AB574A19BULL, 0xB7D7A06BDFB96FBCULL, 0x3A222243AEAECFC1ULL, 0xE7A438331E60D55FULL, 
            0x8BD80039F0CDE12FULL, 0xC23F9B37C3FBE164ULL, 0xCD460AB804D24B2BULL, 0x6102F9357E8D44BDULL, 
            0xA726745194CF8112ULL, 0xCCA6EF5B09AE695BULL, 0x2BBBEEFA0E0017A9ULL, 0xDD5B8BBEC11FC93FULL, 
            0x1EB76C1EF932BDF8ULL, 0x354B4763FB5DE7E9ULL, 0x78BC1D6E8EEEFE6AULL, 0x2C6983CF5129903EULL, 
            0x0090D8E280574EB1ULL, 0x1CE9C39097662E52ULL, 0x02F5E6EF526187DAULL, 0x0E8BA8F809670C42ULL, 
            0x2050847A4F47DF64ULL, 0x8991FD074C9E8961ULL, 0xEA0F2F780B9E2B8CULL, 0x4DF94C82BBF00606ULL
        },
        {
            0xBDE47E458CBCB47AULL, 0xBE04856F01F76DE2ULL, 0x409A1FA922B91D44ULL, 0xBAA6854FF8D64585ULL, 
            0x5AEA8366A5496B32ULL, 0x9A77E8239EC3DF38ULL, 0x4FB71956ACEAC443ULL, 0xDA48FD752418FAE4ULL, 
            0x626CE9625044CE2AULL, 0xD4339C7225085374ULL, 0xAD53A04C3495B636ULL, 0xE0BF0BCF20693B3CULL, 
            0xD6C6CB094060D001ULL, 0xCFE1BB891445A4ACULL, 0xD7B18BD2F820A42BULL, 0x58B2309984E8BAE1ULL, 
            0x88849840D96DB000ULL, 0x1779CA7F654AF29EULL, 0x39E446716D84CEA3ULL, 0x163BB5722472124BULL, 
            0x8D2370FCE320A3CEULL, 0x1AFDAFCAA3567DF2ULL, 0xF34A0EC2A7089731ULL, 0x7AA2BB1CA5ED4D60ULL, 
            0x22AEB1167ED92AB3ULL, 0xA8B097787A538C33ULL, 0x9F0D89885B9E6290ULL, 0xEEA5981BCAF6FE53ULL, 
            0x3EB6217488C17AB1ULL, 0x15438CAEDA74AE98ULL, 0xA6FCBF59D4F1BBBAULL, 0x7BDEB796B86F74B3ULL
        },
        {
            0xDC06258A6818519BULL, 0x8067CA6E4BFEB626ULL, 0x2F7BAD500F3F70B3ULL, 0xBF925F41B9F82DA5ULL, 
            0xB90395A0520473D5ULL, 0xFD9EC7B8A6113391ULL, 0x344EFE3410D82E7BULL, 0xB55BE9A6897B5373ULL, 
            0xE2B60456B287A388ULL, 0xEC83B08AE7ABA846ULL, 0x35434F2256D2D19BULL, 0x384BD023BA5BC64EULL, 
            0x69B9EE9391164699ULL, 0xECAD6E6AD57F1B0FULL, 0xB85A9EFC4AA26773ULL, 0x6E454AAEA368AEE0ULL, 
            0x888EAE0DD9CE0D87ULL, 0xAE85EDB5C35292E9ULL, 0xFCA3B534726A0828ULL, 0xEE58EB4BF21FC6CCULL, 
            0x3284F10D9A16185DULL, 0x41FAD219A7B666C9ULL, 0x76309D6BA1944CEEULL, 0x01C7179F46DA33ADULL, 
            0xE599580D2B6C42D2ULL, 0x1F27ED0B710F0405ULL, 0x7F36149363F6A658ULL, 0x9F26FCBB135AB7AAULL, 
            0xBE65A55B845573ACULL, 0x0B974B9305252D78ULL, 0x392895B209865413ULL, 0x02CBFFFF065F0F02ULL
        },
        {
            0x888D2DB976B275E1ULL, 0x7FFC4ABA4EE0B2BEULL, 0x7584FB761C4EDC3FULL, 0x48038E47B50209A2ULL, 
            0xFD5FF4587D3195DEULL, 0xDAB47D848D2C115CULL, 0xFAC74AB6C9B99290ULL, 0x1063708079722D7AULL, 
            0xFE113D4D111B885AULL, 0xD50F4DAEC958B8C8ULL, 0xB217AE8468831767ULL, 0x751DC681AF26EFB3ULL, 
            0x7E991440CB58C4EBULL, 0x8D39707E749E168EULL, 0x1680E865D61F732CULL, 0x4F7731891907F4F3ULL, 
            0x65BABC6723768EC9ULL, 0x5E2C9F7F6EA8FEE5ULL, 0x4B1D9817D5DC49A6ULL, 0x58FF930DC0583330ULL, 
            0x749CAF354997F824ULL, 0x92F1108846B0E4A7ULL, 0xB1E479EC13C3EFEBULL, 0x80DDB2F026B873FEULL, 
            0x7DC2072E752F46AFULL, 0x2A7AC8B2F5617D3CULL, 0x71C2F8E4FD40EF9FULL, 0xEA0FA13A86EE9D49ULL, 
            0x019EDC3A94645755ULL, 0x2C5A3D5624A9145AULL, 0x727A60DFAE9A03C3ULL, 0xABE6E2EF0C8DD90FULL
        },
        {
            0xA9BEC9B9F9074026ULL, 0x2B8AA36274B935CCULL, 0x0228455CC07647DBULL, 0xBD64EAFFAAF9C1F7ULL, 
            0x920F5D2307D7005FULL, 0xA964D6561FA5548DULL, 0x459C155720858BF1ULL, 0xE687E618ACD19794ULL, 
            0xE286FCF94DC9CB4AULL, 0x6FD2AFB093BBD31BULL, 0x2DCDE6ACF45ADF38ULL, 0x2DCF3BF17665AFDEULL, 
            0x17FF3E20F184360CULL, 0x4DECCD77B1E7578CULL, 0x3CD5DEC0016DD4E5ULL, 0xB1F0BBB9CC66CDDCULL, 
            0xBCF09FBF8593100EULL, 0x134097499388EE7CULL, 0x292A164D5FEB6516ULL, 0x8D2644FA06AAC07DULL, 
            0xE6D711F5B85E15FDULL, 0x432491AFF2EC886AULL, 0x5F3B654BA811A90BULL, 0x85CC6F7A2DCE90B4ULL, 
            0x3EDDC899F3DA83FFULL, 0x4D78973E74B94BECULL, 0xEE3CBCA49C747BF6ULL, 0xAD764A2FDB87F953ULL, 
            0xAC38D43D99B68F92ULL, 0xB2B60DF10F225F1BULL, 0xF0432AA9B63AC358ULL, 0x4576DD519F64C674ULL
        },
        {
            0x7F3B299D64A56003ULL, 0xB28F41F61ECE423EULL, 0xD00E560FEAD982FFULL, 0x3CCA6779719F16E7ULL, 
            0xFC88B73505E241C6ULL, 0x054AB5D7073BF3D7ULL, 0x5A80535FE9684360ULL, 0xF95A768CD54158D1ULL, 
            0x4132C539DA85F276ULL, 0x727551539251B06CULL, 0x4898751E0D9E72FFULL, 0x2B63449398685D7AULL, 
            0x262425B5B856ED4BULL, 0xBFF5D54572E88AC5ULL, 0xB17FFD5EAE654251ULL, 0x9EC4911DD521CB03ULL, 
            0xAB4452B966EA484FULL, 0x1C61035AB04265AEULL, 0x417A0041D774663CULL, 0x845B7A161E07A21BULL, 
            0x920AE0ECC147A461ULL, 0xB06D1ED38B3BF5BBULL, 0x37B89F2BBD3FB53BULL, 0x1B808DF48A18E269ULL, 
            0x0CBDAA46996C1A73ULL, 0x3F9810BB9E6E3779ULL, 0x30BA3D91FF7896EEULL, 0xBF0B353BD626B39FULL, 
            0x9332E9295250F977ULL, 0x13C1F85185E09D6EULL, 0x3DDB5FFDD1C576A9ULL, 0xED4D23E253AEACA0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseBConstants = {
    0xB1A858DFA15CA00BULL,
    0x4951BD0FC66E6A61ULL,
    0x211297AA2AE6E0FFULL,
    0xB1A858DFA15CA00BULL,
    0x4951BD0FC66E6A61ULL,
    0x211297AA2AE6E0FFULL,
    0x9103DC69B66C73A3ULL,
    0x05FDB78625681B53ULL,
    0x58,
    0xC2,
    0x66,
    0x5C,
    0xA4,
    0x8C,
    0xF9,
    0xA7
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseCSalts = {
    {
        {
            0xF801BA0176B397B5ULL, 0x74033B166800AB15ULL, 0x7352801DBB828CB4ULL, 0x08128BE1DBA548DAULL, 
            0xA0B6888DC83C2D8CULL, 0x06D26B20AC7C33A2ULL, 0xD1A0288865429E8DULL, 0x2431E59EED90049AULL, 
            0x9B456D3680544F8BULL, 0x3048CE3EB0F699D1ULL, 0x9402BCDF3E86407AULL, 0x192E50325F1043E3ULL, 
            0xF2B13296323AB9B7ULL, 0xDDFFF730FA10F71CULL, 0x22A6C699C611B7B2ULL, 0xC06003717926F757ULL, 
            0x2D0085EB9D74C14CULL, 0x8031FB25751B2E52ULL, 0x875401D8BE40B863ULL, 0x1A6752AE9CB07F8CULL, 
            0x75301694A42C9340ULL, 0x6C1709564A80EAA6ULL, 0x0C9A4DD46480ADEBULL, 0x21019D4D14A8FF5FULL, 
            0x0B0725BCED400C00ULL, 0x93DFE28F119DED7BULL, 0xE151EB64F35B1A0DULL, 0xDB51C3AF7B0B6D42ULL, 
            0x3FBB8E1947429450ULL, 0x4A513C3E4C69D908ULL, 0xEBA233D2594A3D95ULL, 0x293F14BEDE1A5F46ULL
        },
        {
            0xD20E416A004CC752ULL, 0x8A85B212A657066DULL, 0x9A94A95221E6C1D0ULL, 0xEEDB0D37F949FF89ULL, 
            0x0C72F799A4488A37ULL, 0x45601D6614EFA9CBULL, 0x358922A3382055C7ULL, 0xFD08579F482D2D22ULL, 
            0xBDEFEB20AF89847AULL, 0x84323B2CDAD58CC1ULL, 0x33D38D00EA57D631ULL, 0x4C5808FF0DBE136DULL, 
            0x68140DED35557209ULL, 0x4A3802CA8EEFCB87ULL, 0xD6FEC1C6E5CBA614ULL, 0x6122F24E2BAF0158ULL, 
            0x4A2587F8AC362959ULL, 0x3F077ACEEE50994DULL, 0x35431EE8493288C8ULL, 0x399A2F7BE901EF98ULL, 
            0x05FB089039E5EE13ULL, 0x001EB4E96300E8B6ULL, 0x8010E4764A1EF5D9ULL, 0x836EEB718CF232BDULL, 
            0xE78828C035385F9BULL, 0x010BB6A18D40FDADULL, 0xFFD00412F3490B0CULL, 0xA59A6A91253A65EEULL, 
            0x3EE2218DA551CD1FULL, 0x0BDA1820F566B3EEULL, 0xB59B5DEE7E9D497FULL, 0x573EAE5388F75F47ULL
        },
        {
            0xC38C256EF8E84698ULL, 0x36693DBA3694246EULL, 0xB6FB812A0C0969CFULL, 0xB263ECFC00970B7FULL, 
            0x41CE87F85A1F9FB8ULL, 0x2EAA5E8D2ADC6277ULL, 0x5714AF2E998F8EC5ULL, 0x9DCB69B84DE1BF3BULL, 
            0x83F2029AB49F3401ULL, 0xA074A4701D4C05D2ULL, 0x6AB351C639169726ULL, 0x3141D933B7B8D1D8ULL, 
            0xDD92EF4C14483602ULL, 0xEFCC6A045922F612ULL, 0x638FFC36F27B468BULL, 0x7FED1C4700441E81ULL, 
            0xABA71CC3FA1FE7E0ULL, 0xC80EDF20941A8B87ULL, 0x5374B2C81B5CB1D3ULL, 0xF7875937ACE00E4FULL, 
            0x95762A33030B811FULL, 0x8740D36BB1B9CB08ULL, 0x4F8CDAF75FE2F751ULL, 0xCDF52D7E0E6D2995ULL, 
            0xA8A47858F61EE983ULL, 0x2176A8F2425DC79CULL, 0xB4910ECC5401CDF8ULL, 0x1BD24AFB4E0E31F7ULL, 
            0x4FEEF1693498E79EULL, 0xEB4FF358C5B85A47ULL, 0x2F508B41C27B9C41ULL, 0xA355902F688C57B3ULL
        },
        {
            0x96E82DEB60BB049FULL, 0xD9B03BC3FE117EE2ULL, 0x9D69021E262AA097ULL, 0x1398D4C3E3677859ULL, 
            0x17EFBF7C95BC47F7ULL, 0x906C58727E4B7944ULL, 0x5C102DCD8D30CB1DULL, 0x6F94C06A4B389999ULL, 
            0x85B667990AD5E523ULL, 0x2CA85F246B4F73B7ULL, 0xA52F6041772B2C65ULL, 0xC83864CF510A1A07ULL, 
            0x957A52E94E889195ULL, 0xD8FB7487ECE5287AULL, 0xC87A044F3D249871ULL, 0x8E65C3662A37DCF0ULL, 
            0xB818E364CDA87D1EULL, 0x48B6097B54179CDAULL, 0xBF0C7528CE22755FULL, 0x959F3DBE0D2587B7ULL, 
            0x5C16AEE14F14CA12ULL, 0xBC040FCFCCD2FA49ULL, 0x0D69645F79186B11ULL, 0x4A635A6F3644E64DULL, 
            0x2B306E1829CB0453ULL, 0xD332BE64103CAFE4ULL, 0xCE9B84E92852DB4BULL, 0x2141AE590EA771C2ULL, 
            0x68C5731BF292E4BBULL, 0xDA8277C3BEE9908CULL, 0xFBB66C0EC42D3951ULL, 0x346E8F5177B0BD96ULL
        },
        {
            0x7C1998CEE3C542B6ULL, 0x7D4D2948E976273DULL, 0xCF1928CE0486D05AULL, 0x5B0CB5318637B765ULL, 
            0xF25D4D3B3D252520ULL, 0xEEF4541AC0196F71ULL, 0xF65CBFAC5CFC5579ULL, 0x6B9B3DAFCAC3885BULL, 
            0x6B5EE292D91E3657ULL, 0x75AA58B46C0189E8ULL, 0xCB938DA034E868DCULL, 0x50C921DD15797FB0ULL, 
            0x313DE513269F8E65ULL, 0xB224F0A761BB824BULL, 0xC5B340CF3CD9AC8DULL, 0x07F7C1A536D38E57ULL, 
            0x73F5B6611A5342F5ULL, 0x2BF2627B9412DDC6ULL, 0xB95899DE871127CBULL, 0xD4761EA5AD3EBC5EULL, 
            0x08A3897507A153CDULL, 0x7365104B9A3B4FC0ULL, 0xEFAA376BAC5CFCA2ULL, 0xD6E2B3016102377EULL, 
            0xAF5DDFBF6B6B2E29ULL, 0x8B07356B31FD1153ULL, 0xB1998F580CE5BDB4ULL, 0xA71A5C0FBA97BCB4ULL, 
            0x04B9676EB0114BE2ULL, 0x53B663FCD7A74D7FULL, 0xB49580CF613E1B05ULL, 0xC6AB9D2CDA045D01ULL
        },
        {
            0xC06D2E9BF0F343D3ULL, 0x29DA2EC9C487F1F3ULL, 0xE26CF69FA792847BULL, 0xBA3EC358EC1BD691ULL, 
            0x5426BC0EFF7B934FULL, 0xC9369C09016AF969ULL, 0x15E52F8C8E6F1411ULL, 0xC2CEFCEF856258E9ULL, 
            0x44E3F12C59AE885AULL, 0x3BF9F30A3D1846F0ULL, 0xB50BE17E3C4EC9DDULL, 0x7EC9C06DA697012EULL, 
            0xADA3B120A2C4DC0BULL, 0xC1DFECCA1BE01893ULL, 0xF0949E12F1083EC5ULL, 0x37A399F941258BF2ULL, 
            0x0FE1B038EB78FE11ULL, 0xCA39975BF592E0ECULL, 0x52098091F83939BCULL, 0x974BDF616D1CB9E8ULL, 
            0xDF572414851D9A0AULL, 0x66E5D72E32CDEDFAULL, 0xD648DF0AB90C3926ULL, 0x4B3C1AA3888215D1ULL, 
            0xDC0A8251B8042D6FULL, 0xE4ADFA4F55C3F527ULL, 0x99D852818B6385E3ULL, 0xBEFDBA74BC5D5B10ULL, 
            0x42C2C3D5FAFED3AEULL, 0x9B22AEC386C2ADCAULL, 0x4597A722803C7CBAULL, 0x3AE969313F0D9BF8ULL
        }
    },
    {
        {
            0x3EE3C01888369B8CULL, 0xB6DCD85D2A395BADULL, 0x420D2EAC939DB70BULL, 0xCA249D622B2D2E04ULL, 
            0x0D7B4976102810CDULL, 0xBDF21E2E782ADCAFULL, 0x813D8C919DA97C1EULL, 0xD55242DE61543748ULL, 
            0x9FD22F1AC820CBCFULL, 0x7CCEB79362B2917DULL, 0xE19FA33727319DE7ULL, 0x8CF6738C1992FCA1ULL, 
            0x3B1E916E87580202ULL, 0x6E075D9F67A39949ULL, 0x79C303963DE44F85ULL, 0x8ABBEC15FACDB825ULL, 
            0x3CA46A64A4B3CDFFULL, 0xE05FDBD3B18D2D52ULL, 0x5BABCF379459F56FULL, 0x4C88A8BD5B6F3DA9ULL, 
            0x2A77E3C40FBDED5FULL, 0x80A464F42FE8E6CBULL, 0x7ACFD518A2D3C24BULL, 0x0C25033DBD2C972CULL, 
            0xAA40AFDBDD8EF8B9ULL, 0x3649C048275ABE89ULL, 0xDA1770A06F172910ULL, 0x9335D0D07E0E144EULL, 
            0xF6B28AEAC92500E7ULL, 0x996195AF3C99C12AULL, 0x83ED8AA66C267CCBULL, 0x9480C049A4CD8327ULL
        },
        {
            0xB5E8C796028B8FB7ULL, 0xFCD81B9CCACA6322ULL, 0xE30DD53E79BE4623ULL, 0xDD78B552BE809CC4ULL, 
            0x92F3708D5084908AULL, 0xA6D6B9F3464F41DAULL, 0x24365D37898F62A1ULL, 0xB7013420EAA754ADULL, 
            0xCC9220A7EE3034D7ULL, 0xFEFD0BAB190AA2E4ULL, 0xBEA5835EBF90788BULL, 0x715FFE92BBDCE452ULL, 
            0x16BC09DDB62ABB3BULL, 0x691A68E089B08414ULL, 0x2F623AE2F0675B6BULL, 0x3B7B5FF021D1FAC5ULL, 
            0xAEE956C4378FBDF3ULL, 0xA6F21746A2E52BB8ULL, 0x292799FED055EE5BULL, 0xCEF531DCBF68400FULL, 
            0x2EF83BFBE5059B45ULL, 0x17C25FC515560490ULL, 0xDFB0C27AC63D62A6ULL, 0xE6BA1047F4E2A978ULL, 
            0x1B7230B36D9CD82BULL, 0x83C850860B9BE0ECULL, 0xB73DB48C7EC7F611ULL, 0x4DD1095C06DDE3C2ULL, 
            0x4496F0DEBCAA3754ULL, 0x5C70037CB822A994ULL, 0x932F410F587FA720ULL, 0xD1FD255738383100ULL
        },
        {
            0xDE11FD3299D87F5BULL, 0x0D9E76074541A27BULL, 0xC24E160C328E1150ULL, 0x2A630BFF2CE2F69CULL, 
            0x446DF8D6523DDB58ULL, 0x9C58142273536983ULL, 0x14714F5BF21ED5F4ULL, 0xDF0A047E389794B9ULL, 
            0x6CF141F3878B76B5ULL, 0x8FCC24D71D48E6C8ULL, 0xD86B1D48F48F1A64ULL, 0x57773E11B6B83667ULL, 
            0x7EC900DC3F80E2E9ULL, 0xDB9CAD7989C05495ULL, 0x0AFDECAE75BA7991ULL, 0xD4166ECF2A238477ULL, 
            0x2C7945CD09C54C18ULL, 0x2B40C06D8BB7607CULL, 0x71090D5AF19DCA0DULL, 0x1495467C761DAAB4ULL, 
            0xFAF26F56957E7288ULL, 0xB36477490609B8B1ULL, 0xBC69020144D6A545ULL, 0x30CD9B4DB58D6DB4ULL, 
            0xC27CA5BDE0DD724FULL, 0x573C124B4336A902ULL, 0x6D858C0F37DA128EULL, 0x7AB4CB592F74A84CULL, 
            0x0EC78E1C154D822AULL, 0xEBEB6B9B142FF9F6ULL, 0x3402CCD4AC99C8CCULL, 0x41EA444082E94B0EULL
        },
        {
            0x064C89994E1FF9D1ULL, 0x9E4677E90AA2041DULL, 0xDEFB8514140CFE40ULL, 0x26CD594C45A54AFFULL, 
            0xCBE57D2A31C2BA78ULL, 0x09595305FD5AA9EAULL, 0x590CD296C91E8352ULL, 0xBE86129F710CBAFBULL, 
            0x1659968E856566EEULL, 0x5E3BC63A55C31896ULL, 0xF2A28B3AE46B5A24ULL, 0xF7E5CE0226BBBB78ULL, 
            0xA625B21F9B044F79ULL, 0x225DBA6494FBDDFEULL, 0xB54FB6FDBF215323ULL, 0x5F2C19EE39EE5C49ULL, 
            0x471627438D374BD8ULL, 0xC61F774B0B2B47D1ULL, 0x1E46BEAC814AB58EULL, 0x51F3AB63D12FB580ULL, 
            0x71CBEC7BD624D5B6ULL, 0xDE136DCBC8AB7046ULL, 0x951CB6483C1C0695ULL, 0x7767A379E5925990ULL, 
            0xED0D7C91581384A1ULL, 0x65ADB9223E614F8FULL, 0xF674C2B184022C55ULL, 0xFD6DEB7A09E23A1BULL, 
            0x50C0F4FFAE2CF129ULL, 0x932BBD46623ABB15ULL, 0x63A066D26A2DC45EULL, 0xB26E9629435FC740ULL
        },
        {
            0xA0F0003EA9488436ULL, 0x7DA846D45CE8F0E2ULL, 0x914FEB48D129A3C5ULL, 0x10A4E3188A6EADE0ULL, 
            0x5A09CFD5A4BA03C1ULL, 0x466BD96D47C7BE2AULL, 0x92ADB170CBCDCC70ULL, 0x778441789CBE1883ULL, 
            0xC4D6A1307E4D065FULL, 0x8356232F839E31FCULL, 0x5EBB13666B145A6AULL, 0x70AA953F52C38D91ULL, 
            0x1DAD89A9BF33E1E3ULL, 0x2921B90D04FC9E4DULL, 0xD4C7FB33CC101314ULL, 0x3EF9844717D0AD05ULL, 
            0x0735BE0F12BE7513ULL, 0x16A7CB3AA35CA0F5ULL, 0xB38EC5C6A4C4F4A4ULL, 0xA41A4F9E30AC653DULL, 
            0x478F22C0FDE59703ULL, 0x6A9B29B3BDC4BE0DULL, 0xDB3A525702FB0071ULL, 0x2D9C42F5C164FF8BULL, 
            0x3BA03B4F7A4F88E4ULL, 0x03B39C9E7285068FULL, 0x7881DDCAF4C31664ULL, 0xBE28240C2C02D3A5ULL, 
            0x1C778677B93D9C88ULL, 0xC8CCCE4BCB05D9CCULL, 0x81920D2EDA30595EULL, 0x6BE0D3B6C30DA63EULL
        },
        {
            0xE3A2FA76820252B6ULL, 0xC9FA967DD453E45BULL, 0xE91FA84EEA7DDDD7ULL, 0xF73E2ACB5A4DB01CULL, 
            0x78C0C48C26267842ULL, 0x2E1A209ACD1ED31AULL, 0x41EFC01EDD1197D4ULL, 0x3C7E92A4037375BAULL, 
            0x92689786703B2CAEULL, 0x2E213872D320C1C5ULL, 0xC59DDDD438258C4DULL, 0x6A98FDCC4848F669ULL, 
            0x58A8B452E696F5CEULL, 0xB103CD2F467A4EBEULL, 0xF069FCADDCB93850ULL, 0x1004CE1B46543892ULL, 
            0xB8567C69864B81FEULL, 0xDC13099C12E57339ULL, 0x4F86014605409650ULL, 0x24C5C17A06B17FC6ULL, 
            0x32B85150F3DF1AD3ULL, 0x7155ED895306C523ULL, 0x375594A6CAF67B95ULL, 0xF207252FBEDBB47AULL, 
            0xC08815D0F66C159EULL, 0x2A2A42513F4D5909ULL, 0xE833444BDA541D20ULL, 0x0B7E0DE3A9DC3174ULL, 
            0xC7F4C8592A73ADEFULL, 0x28216E362D88FA13ULL, 0x582C97596CA4D8EEULL, 0x0577CE9E180039B6ULL
        }
    },
    {
        {
            0xE04CB0AAC6A211EEULL, 0xE812D924D066C89DULL, 0xBDD5ED2538475D50ULL, 0x9D2F9CB7220E8D63ULL, 
            0x68E5E9808AD15AD2ULL, 0xA6202612CEB2C057ULL, 0xCDFDA9626F84163DULL, 0xC8098D7F5FBA4E67ULL, 
            0xC0688CAD2FDA842CULL, 0x026B4D84F1CBF0AEULL, 0x7FC68422682ABA76ULL, 0xAA24DB4FA5C25CEEULL, 
            0x01AABF548306D44CULL, 0x87BE18F68116D9C2ULL, 0xAFE2D7EC6FE45205ULL, 0xA38FD5E61B4C1271ULL, 
            0xE6A856C679813E43ULL, 0x5317368D6606D512ULL, 0x25BE98C18D713813ULL, 0x913FB94C08D0A34AULL, 
            0xC03EF5D913B55E88ULL, 0x3C5104C51FE166E9ULL, 0x1F5DAFAA39119766ULL, 0x68B05F6516448A24ULL, 
            0x0388B70528681088ULL, 0xFC297B46F3004488ULL, 0x81C5C1E060EE6471ULL, 0x54D2952D5AB2185CULL, 
            0xB20476CF42443C2DULL, 0x53C5C1D4A9F58E56ULL, 0xAC498624F4FDD3B2ULL, 0x6E9924AB2185FE77ULL
        },
        {
            0xEFE95104330DADC4ULL, 0xA7312261A5288DD2ULL, 0x123158FA57CBAE8EULL, 0xA4A0F0EF571940F4ULL, 
            0x73258CB932248A27ULL, 0x90B012435226C023ULL, 0x87281EEDE6BBC75DULL, 0x7A60D06E84CCC257ULL, 
            0xCDA3DE9FB508EBCFULL, 0xFABF564159E42158ULL, 0x57546693DF9BDAD2ULL, 0x2590038DAC002C2CULL, 
            0xDF62326809E06C91ULL, 0x458D9B2FAA9F7A0CULL, 0x079464290A332A48ULL, 0x0109CBE5D9FDFEEEULL, 
            0x03D4C828CEC426EDULL, 0x4A826CA6D6A30491ULL, 0x88BCD0198F49318FULL, 0xC53C576345281B05ULL, 
            0xBDF8068361B96196ULL, 0xFB65C7094191CE0BULL, 0x2818E4E9F6CD2A9AULL, 0x059B86752965D50FULL, 
            0xF7153428D7242003ULL, 0xDD370CF81B109E44ULL, 0xE6530E185DA5AC8EULL, 0x296AAE2B9AB8400FULL, 
            0x6AA8DA6CCDB1A76BULL, 0x18A8CD0FFD204892ULL, 0xFDFED638646E17F0ULL, 0xA9B54FFC56C27F3BULL
        },
        {
            0x1AB8D7CFBD985137ULL, 0x258ECB80C46A02D8ULL, 0x0BBE00779B3CEF66ULL, 0x90BA9FB7A163E0BEULL, 
            0xF6A40B6886BCCE31ULL, 0x6D616B2CC6F497EDULL, 0xC2E4265B5DD0BBBEULL, 0x37417A8DC9E818E3ULL, 
            0xA611885E2215C162ULL, 0xB335A96276664754ULL, 0xC15E6387CEF741A7ULL, 0x66886AC4ADA40F26ULL, 
            0xB890F81455D70645ULL, 0xF42EA308A1258FA3ULL, 0x34CC57153C652381ULL, 0x46422C90C615737BULL, 
            0xBA7A734DC42FF40EULL, 0x1D6CF4659B3F835DULL, 0xA4E2E60CD609DE0FULL, 0xE96668C8BE3EC9C3ULL, 
            0x3AEA708D8CCF7EEEULL, 0x75FE58D62C0D6D1CULL, 0xE8D5210A5D4A28D0ULL, 0xD05D2AF3B909046DULL, 
            0xD6E49D41CBEE64B7ULL, 0x83532C0FD4A45497ULL, 0x94778663BA4F1F28ULL, 0x1BDAB5A1DF278E37ULL, 
            0x57D825197DE57DB6ULL, 0x6025C24DB190E958ULL, 0x7264352B4CD37B20ULL, 0xD2F239178282A102ULL
        },
        {
            0xAE0A85C4F232A2D9ULL, 0xE4C75F5EC1727A82ULL, 0x73B0F17C948FA7DCULL, 0xBF9BC8BDF80B30B3ULL, 
            0xBDF9722FCB1E9D16ULL, 0x92BD598B203E5F61ULL, 0x06953C46E2C94D72ULL, 0x541CF9FF76C3DE6DULL, 
            0x967A9AB4E3BB8CBBULL, 0xFA42EA3745FCED1BULL, 0x9CC2D7ADF2F4F25FULL, 0x08978A7ACF4B3859ULL, 
            0x6D6F772CB32414DBULL, 0x93FD14FA576B1E77ULL, 0x8810ED424854201BULL, 0xEFE041FE28C45552ULL, 
            0xCCC4DB8C641C1917ULL, 0x3CE402D20D7EFDCBULL, 0x18B9F9666CD6355BULL, 0x277476C5D3B7D083ULL, 
            0xB8B92A04D3DC2F80ULL, 0x8AB08DD69ECC10E6ULL, 0xB2552B796D79323EULL, 0x9283ADCA9957E9FAULL, 
            0x4F6E7DBB0253DB02ULL, 0xF88C177DE67F88D2ULL, 0x946CF78FC398D4A6ULL, 0x092D4035BE7DFACCULL, 
            0x288E9F2E745DB37EULL, 0xA076436F8FB29AB1ULL, 0xA7161C92159A8E5AULL, 0x5BE63BE70C0A2266ULL
        },
        {
            0xC68E007CF02AF252ULL, 0xACE30422236D4EF4ULL, 0x81C3BC96E27D0000ULL, 0x8E4F72B0371768DCULL, 
            0xB7C3D57E693E1E32ULL, 0xBF1C6ADEF180585DULL, 0x226E9B2D0E22B029ULL, 0x7673FB800AC6F222ULL, 
            0x0574185768FE5493ULL, 0x9A9F03E30AD6F011ULL, 0xE8CCCAAC02536602ULL, 0xEAEE8879C2E06C58ULL, 
            0x85A5B08FDA0D10EBULL, 0x657557DC25741B18ULL, 0xBE22C091FCB75662ULL, 0xFD2ED447478ECF6EULL, 
            0x82720BF6BB203562ULL, 0x66B2430B5CC84C33ULL, 0x4651D52D18D9B347ULL, 0xF6034AEE640F3C57ULL, 
            0xD4855B70C4A7C127ULL, 0x895E07CA66AF7F08ULL, 0x7AEA278FBF928C16ULL, 0x2B0F3CC3F795FD80ULL, 
            0xC661A534C4C6C7F2ULL, 0x5372C5E7BD49A01AULL, 0x5E871650175054E0ULL, 0xF4C31673BA373803ULL, 
            0x087EB41524F61146ULL, 0x1C105DF768B236FEULL, 0xBD9C087EC6B929E9ULL, 0x1275F4ED4DD2BE81ULL
        },
        {
            0x49B7A09A0F3E8654ULL, 0x7F3BF9CFEFB7B20BULL, 0x517297BA44DF904FULL, 0xD9CD45A6BC6FA553ULL, 
            0xEBCD35D0A5F2CCF8ULL, 0x26439F20034DCB3EULL, 0x0C4C058419037EC8ULL, 0xAB3E40FFF004F03CULL, 
            0xB78E7332BBC22A88ULL, 0x8AE63C7424EADEE0ULL, 0x8FC56E8DFFB406F0ULL, 0x9421A876E16E367DULL, 
            0xDE372D4518E14C66ULL, 0xC20FBCC5EA07B046ULL, 0x89F4DA52DDF445DEULL, 0x515519E2E09B8117ULL, 
            0xB6539BFE73E543CEULL, 0x3B406E949D519EE1ULL, 0x0E85173DEFA3F67FULL, 0xE9ED01C243B968CEULL, 
            0x92B640A9DC210FD8ULL, 0xB233FB8993107274ULL, 0x54B2488261D6A2A1ULL, 0x3AF5C0FE873B6B45ULL, 
            0x5E8ACC5F91B0E23BULL, 0x572C766943E040ECULL, 0xEB786DAC6D88AC6AULL, 0x24CBAB9A65E79AA1ULL, 
            0x2CC591645B9FCAF5ULL, 0x29C5C0A0FB823ABDULL, 0x8BF3955348473043ULL, 0x6EE820ABB35C52E5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseCConstants = {
    0x1F00809FAC0A28FEULL,
    0xCD3812D211FB70DCULL,
    0xE9F81767BEBF6EA5ULL,
    0x1F00809FAC0A28FEULL,
    0xCD3812D211FB70DCULL,
    0xE9F81767BEBF6EA5ULL,
    0x898528028F34F52DULL,
    0x9FFEFF47ACAB62CCULL,
    0xD0,
    0xB3,
    0x09,
    0xB2,
    0xEC,
    0xEC,
    0x25,
    0x7B
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseDSalts = {
    {
        {
            0x86390079D44B8546ULL, 0x42F108273AF2B509ULL, 0x658F1F065C4884D3ULL, 0xD1694AF51482DEC2ULL, 
            0x61EFE863523CBB2DULL, 0x54409E680A38E694ULL, 0x70C1561C72E16BD4ULL, 0xE419032E848A769BULL, 
            0x5486CF763D0FCB1DULL, 0x629DDB14DD7FF8D7ULL, 0x5853569DA0F92784ULL, 0x4616284AC61C53FFULL, 
            0x0365B58B056282A2ULL, 0x5D80ADA7D34381EDULL, 0xEA208C5AA440D68AULL, 0x74D3D5FEA4B34CABULL, 
            0x33707050D2E4000EULL, 0x140C04BF2353C55DULL, 0x7623EA748AFAB64BULL, 0x9A834A356735A311ULL, 
            0x1C4C7C8246CCAAD0ULL, 0x2FD570FC0214F70DULL, 0x3DD989907D20D754ULL, 0xA898768D36289E7EULL, 
            0x70169B7BA084464CULL, 0x82454E79D32D6A92ULL, 0x042386A2E947D63CULL, 0x3DDB0C0C2E8DEA94ULL, 
            0x5144279D66E58215ULL, 0x537E1538C15B295FULL, 0xC2AFCA03DEEBB58FULL, 0xEA2A1CBBAA9F6916ULL
        },
        {
            0xA96DA0B65777BF92ULL, 0xC5D212CB52EC67ABULL, 0xD017495268BD2D78ULL, 0xA6C5B7180F1CC611ULL, 
            0x86229F3F4E19DC51ULL, 0xAC9187416359DBEFULL, 0x69A86D072BDEB33CULL, 0x6F7AE641C9DA23E5ULL, 
            0x6FAE4F3182E68516ULL, 0x6C4C86BACF53A0C8ULL, 0xAE0378E76E85AF8EULL, 0xD0B384B6984368FDULL, 
            0x31886D14AD065CDCULL, 0x2CC427A777A5B212ULL, 0x07BAABD8EA8DC2A9ULL, 0xC7B1CB95F781CD99ULL, 
            0x5A281A52DE5FF4D0ULL, 0xAD6D4774296C7B75ULL, 0xA698A58C98270646ULL, 0x63340C8AADD86194ULL, 
            0x8226D36571F70F61ULL, 0xE97A55CCEFAF62AAULL, 0x646586A3D38DA2E9ULL, 0x13C8EF9A24F7B22FULL, 
            0x8CE1543EF1D67CA7ULL, 0x25AEBF4284F680ABULL, 0x52E5B8D698666764ULL, 0x673DA55590359144ULL, 
            0x862CF3501C1E7D40ULL, 0x74E926A89065D1B1ULL, 0x7195C85751033ABBULL, 0x2CCC0AFC21E4417AULL
        },
        {
            0x3C0AA191FDC31448ULL, 0xAD286DA613AD18C6ULL, 0xCBD1184E6924F097ULL, 0x5A534D70F0C693EFULL, 
            0x906CCE277A207761ULL, 0xEBF5A25CC114C327ULL, 0x4793AD893E6FE928ULL, 0x550FED7B3DC6C413ULL, 
            0xEE89D735E4794BEFULL, 0xA182F33D3FA24CECULL, 0x262D3A4EB63C040CULL, 0xA584CAF62A79F06DULL, 
            0x4AFC9A2FE0AADAEAULL, 0x9EB96C70ACE4A365ULL, 0x18F0E93722B46D71ULL, 0x2CDC354AA4136FA6ULL, 
            0x3B9EE482348330F0ULL, 0x64E0CC5872AA56A7ULL, 0x7B76D551112425C9ULL, 0xD8DCDAA5A4275394ULL, 
            0x2E5701EF300EFB3CULL, 0x28AC258C416D5699ULL, 0x161F4DF8A08FF107ULL, 0xE46AC93D7C54DD54ULL, 
            0x155BCADFD2172461ULL, 0x7D65E36A3938FF85ULL, 0x76F0F586AA52EA00ULL, 0xEBCA0C5DC2C91B89ULL, 
            0x22BC212F345348CFULL, 0xACC74D745703BFEAULL, 0x27432B19D59D52B6ULL, 0x13A21F87D91444ABULL
        },
        {
            0x7E33151B19C6FDEBULL, 0xB404052F413AE7F4ULL, 0xA485D17362E75BE7ULL, 0xCC645778380ECC98ULL, 
            0x4B17C42507CF9E2CULL, 0x67D5EE3A95A96049ULL, 0x502F49485168A190ULL, 0x0E02651065980811ULL, 
            0xF102E7BACDD8A43DULL, 0x1B5092508ECDAD1FULL, 0x7E2F6BB41D2C7E97ULL, 0x1699783A3B05309CULL, 
            0x602B664D6696BFBAULL, 0x0FFDA6A5EB2AEA31ULL, 0xC07048D70DBCE36AULL, 0x682CFE6F5C53C0EEULL, 
            0xE21C86C518F6FB0FULL, 0xC5E3EB56DD217241ULL, 0x650F659F56827A5EULL, 0x2E56C28607D07062ULL, 
            0x3A23B25F4D5226C4ULL, 0x54F540A76F6E3303ULL, 0xF1226014B33F1AADULL, 0x3B7CB9059572D6F6ULL, 
            0x9D32EB0F71D0260EULL, 0x3B04971E84A8B6DCULL, 0x4DDA8ED1F5F2AEC6ULL, 0xDDA5726901FEFAB2ULL, 
            0x8ADBA36ABE135851ULL, 0x5E31CA43936FF9C6ULL, 0x00857692685843F7ULL, 0x097DE98ACB5CA25AULL
        },
        {
            0x138916AE36460938ULL, 0x46A932D2643037A9ULL, 0x5A05FA241C74D965ULL, 0xEDE0C2878BF062CCULL, 
            0x8C70702D5126B87DULL, 0xB3F2B194F869F366ULL, 0xC7ADC30887F76AB7ULL, 0x7E0D4F3ABC28B4FFULL, 
            0x8F060C1F118EC1FAULL, 0x6BCD2F755E088130ULL, 0xCEBEA1E2D397648AULL, 0xE6E3EB236F7A7968ULL, 
            0x96F8EABDAFBFFB60ULL, 0xAB588102C38A592EULL, 0x1D7533DDED359B2EULL, 0xC11644254D904267ULL, 
            0x1EBB07337CE51200ULL, 0x9CD20D48ED0C6B57ULL, 0x3A41BBF9E0E7E797ULL, 0x8EE62AAA61033219ULL, 
            0xF7A007829FE796F0ULL, 0xCAF26D27311AF3CFULL, 0xB7876DCCF4C8A228ULL, 0x940DE3F5C451603EULL, 
            0x99425FA6249846ACULL, 0x028ADCD69CDA214CULL, 0xCCE0EE21A71DC083ULL, 0x4128D147497CE4AFULL, 
            0x7A8F470B36BB4B8CULL, 0xAF02BB57D6BFB251ULL, 0xF58917969771D9FCULL, 0xE85C9AF7BCA248D1ULL
        },
        {
            0x6E4FE90563035DC5ULL, 0xD0172CCD49095E58ULL, 0x597C1D36335F82A8ULL, 0xCBDF7C1BCF7F5167ULL, 
            0x3241486D1553FA56ULL, 0x3C5CB63CA267D64FULL, 0x22F8CCA38B944348ULL, 0x6FF81B6FE4461496ULL, 
            0x4DBF6791A3B06775ULL, 0x8FF3BBB97F2B8558ULL, 0xF350CE6BF39BB6CAULL, 0x7693CE5C18907D53ULL, 
            0xB8941132032AF171ULL, 0x6AC57CC2D3DFD146ULL, 0xA6952EEC62DAA4B4ULL, 0x1452306F639EF556ULL, 
            0x8CA5DA31ED4DA46EULL, 0x4A0E142EA60AFDA6ULL, 0xD750B74A3529C677ULL, 0x1D6DC94490A1DDA0ULL, 
            0x982B3BECFDFB87B3ULL, 0x7361CF9D57300942ULL, 0x38412D636AD84CC3ULL, 0x6453AAC1A7A39B6FULL, 
            0x3093B59FA7D55591ULL, 0xE1733320D12A1E41ULL, 0x98EC6451051EAAD2ULL, 0x1B8E2AAF8167AABBULL, 
            0xBB2F0EF29F15403FULL, 0x9C59091F58E934F6ULL, 0xA13B8899582E0319ULL, 0x0330082DCAE4EDA0ULL
        }
    },
    {
        {
            0xF509617C9574A159ULL, 0xB3CF340ED0EB6458ULL, 0x67FFE43F21C0DE2AULL, 0xAF4A0BDB7B4981CBULL, 
            0x8187445BA3F4E764ULL, 0xAC319D3AF4368C2EULL, 0xE168CFEBF345FD04ULL, 0x437C7DB762964D2FULL, 
            0xCDA2AAA55DD63DD6ULL, 0x9284DFC36B6A2CF4ULL, 0xB36B2B94998826CAULL, 0xB9C68FC3259392B1ULL, 
            0x1E545A8499585798ULL, 0x652BC5C8B1DB3165ULL, 0xD5C633253D2DF3FEULL, 0xEB209ECB183F8D8DULL, 
            0xC062E2AB5030B0FEULL, 0x42FAAD48767B2273ULL, 0x400241BB937CAB96ULL, 0xADF83818EF21D265ULL, 
            0x2633C17BE9136C52ULL, 0xE40662EB03418687ULL, 0x0C4F7639A614E2E6ULL, 0x5F0B322F92CD5D14ULL, 
            0xDD37975E046DD531ULL, 0xADDC71E57A855B44ULL, 0x6EF6026082F6206BULL, 0xDC726A67B8F42ACDULL, 
            0x94E30889A5A7C000ULL, 0x8A638F5FD077A286ULL, 0x2CB37D2E269135A0ULL, 0x2A737601FCC4AB8FULL
        },
        {
            0xCE1DF67BF6CA43E7ULL, 0x3FB7637FCF0480A6ULL, 0x57BD9A392C2A0976ULL, 0xB3087C48ED498772ULL, 
            0x2703221987DB0046ULL, 0x45607AFABAAD070AULL, 0x166454CF81A90F64ULL, 0x86D5B350BFAF9702ULL, 
            0x85559E1183C59E5CULL, 0x36A4B26C548221FEULL, 0x577B25D7DE1A72C8ULL, 0x5A7D3CBEA5841867ULL, 
            0x4A410F713A51390CULL, 0xD9010061377CDC21ULL, 0x075A0D3CD780480AULL, 0x1A9305EA86001494ULL, 
            0x977E5AF92D5AC23CULL, 0x9520DCF41F1A1DECULL, 0xFD058FBCCE376684ULL, 0xC2856EDF2B6874E1ULL, 
            0xD1AE8513F1C401B4ULL, 0x3FD9974A9410EA45ULL, 0x6A0F70E7BC3FD951ULL, 0x7C562E63F319D93EULL, 
            0x18A462CDA6BC183EULL, 0xF91B963A43BFE6C5ULL, 0xE3DE70A025B6BA44ULL, 0x5AF83277CB303549ULL, 
            0xC28ED1C53E1F0F6AULL, 0x6A93DE316FA35D5FULL, 0x3A0D4E7B23196A3CULL, 0x089A4BFA3F70461FULL
        },
        {
            0x9CEC6307ABF9B202ULL, 0x196BD03CAF921BF8ULL, 0x812B8C4572E620C2ULL, 0x3BA288DCE61CCB78ULL, 
            0xE157EE4F7FF4FDA2ULL, 0x11CD8E7969936501ULL, 0x18393236499A0F73ULL, 0xC269DF550DB8C6DDULL, 
            0xC378433AFE074335ULL, 0x0B5C8B3A1131DAF4ULL, 0x5184D23DCB4AFD12ULL, 0x0133F802E80AE4B6ULL, 
            0xF3BCF947892A2AE6ULL, 0x202B0851A48870EBULL, 0xAD5DCC8FA6E39160ULL, 0x4EECB20BD1D03FB0ULL, 
            0xA1D8C24E846EC3C4ULL, 0xD85B43DAA2E2E95CULL, 0x356ED00B14DBC6DBULL, 0x2C1F1CD7F88469F0ULL, 
            0x5654650384C1A605ULL, 0x0007EC38A88A0013ULL, 0xF69BA65E40FC4A96ULL, 0xCB60A388D3792356ULL, 
            0x6B12887B3BB25736ULL, 0x5AC5DA78F5AF8278ULL, 0x6B1F6A8BC6011811ULL, 0x67D5AC5C5D41EAA7ULL, 
            0xB0950D22024CD0D1ULL, 0x2D37C2D5889613A2ULL, 0x7472C8C05DB08B27ULL, 0x1E2277E00D3FE680ULL
        },
        {
            0x6C12BFB12F50F1A2ULL, 0x0C610427FDCCB5F7ULL, 0x4A12022C3F7CA0E7ULL, 0xAF1C1C05409CDAF3ULL, 
            0x88F61767B0ABEF7FULL, 0xF030A05696264844ULL, 0x92165643AB766B7AULL, 0x5A0503771C21C0EEULL, 
            0xA0EE3A1D45CAC664ULL, 0x0A7A1D8BA9E16D5AULL, 0x54B608C959265080ULL, 0x9F620AE62FC200E0ULL, 
            0xCD2601FAD0C8674FULL, 0x3FBEBA67C6D6E4B1ULL, 0xF94A0FE9783CE096ULL, 0x2D5D14617DC3CF1EULL, 
            0x697CF60327BE7B53ULL, 0xA02264D0A0E7F002ULL, 0x4DD86D10E755134AULL, 0xC98CD9AFC5C48C32ULL, 
            0xE489B8BB3D26FE8CULL, 0x79D1F38CEFF540C6ULL, 0x8325F8FFC6C51467ULL, 0xB2A2D13E15245366ULL, 
            0xED7CBFB4C1B69961ULL, 0xC6D47364A9DCDB3BULL, 0x10467A85CA6B6173ULL, 0xA1B977167EC9B3B2ULL, 
            0xC7226C3286E1C13AULL, 0xB91C194CEBAC766FULL, 0x494E3F81186690C9ULL, 0x46538E31188E2089ULL
        },
        {
            0x243F738A38A9D59BULL, 0xEBA75D755EB453EDULL, 0xD83757528B8E8EE8ULL, 0xDCBA32958FD00DF4ULL, 
            0xE37B22019E3DFF65ULL, 0x15195276FCB0A431ULL, 0x5725CA2583F9FCA8ULL, 0x6A4D870EFB0B052FULL, 
            0x658E48132820D838ULL, 0x90FC4D6E899EEF3BULL, 0xA0E3DDFC5CE4295EULL, 0xF2F81ECE941EF484ULL, 
            0xE69740EDF08B8638ULL, 0x87921BBEFE0812FDULL, 0xC24FF4F0EC01B8BCULL, 0x6B7796F044AC114BULL, 
            0x40582E026AEEF36DULL, 0xC052D32EDF33C59AULL, 0xEB56F92AA822B8A6ULL, 0xB7303795D6A8F14BULL, 
            0xAC144C439C18A3A1ULL, 0x5E7DDF5436C32D17ULL, 0xB4CBFB71A186700FULL, 0xC16DB246C55BB757ULL, 
            0x03D1D3A6032D2C48ULL, 0x1AEF380F57120F6FULL, 0xE482DA30D4E5AA61ULL, 0x9318FFDB8C695974ULL, 
            0xC89FACF7E2ED9C16ULL, 0xE404B52DA08CDE3CULL, 0x7DE935EBAEFBCAF3ULL, 0xB8F5AFF7295E1F38ULL
        },
        {
            0x9304BDDD15E27489ULL, 0x82670459A37DAC58ULL, 0xDE1279EC5D884695ULL, 0x7E339B61B0E40AEEULL, 
            0x776AFB210E0907EEULL, 0xF0BE143406A00CC4ULL, 0x5544923585D5503BULL, 0x7B3D4014473B6CE7ULL, 
            0x7720E1990E4EE221ULL, 0xC806DA74EFF7D52BULL, 0xA137CB1398DF5509ULL, 0x4084122115FC3687ULL, 
            0x7C0C3F7689C26188ULL, 0x08E953BD479C84A8ULL, 0xFFD214E5804264BAULL, 0xFB20150FCAF4D358ULL, 
            0x8AD7CC3D2E7912B3ULL, 0xC469590F21FD6E2EULL, 0xE4AF8ECFD55ABA17ULL, 0x2D58377CE58488BAULL, 
            0x4E68BB17083766FCULL, 0xAF052792098CA74DULL, 0x5570B44D86E81ADBULL, 0x54C863E4CB622FB0ULL, 
            0x721621C65635AE32ULL, 0x53F3DFFA4EF86A89ULL, 0x81E66BAAE14B3509ULL, 0x92BCF1316A2DCEEBULL, 
            0xDD4C1B9A80DA0BA0ULL, 0x7A17BCCC2D197991ULL, 0x248DC13CF05EBE70ULL, 0x93F6DC9325CF2E6AULL
        }
    },
    {
        {
            0x77371B7D558858BEULL, 0x957CDD41AA2F974CULL, 0x74F449F00C7EF48DULL, 0xCE39A1073B4BEA4EULL, 
            0x30630866CFB6F5C4ULL, 0x373C2BB16700031DULL, 0xC3EEB9D8098333B9ULL, 0xD61FAD7AF3F05BFBULL, 
            0x73307C6F11A92181ULL, 0x06D804DCB7D0D2CDULL, 0xEB9A1182860E3C50ULL, 0xF64D19F0C727A17AULL, 
            0x219B05293BBAFFBAULL, 0x747D640FC0E54912ULL, 0x1A2962573E359872ULL, 0x40FD11CC4B1EDE67ULL, 
            0xFBBA3D4427273CDFULL, 0x6AE9E8CB4865066DULL, 0x5071AAFE6D59CBB6ULL, 0xC2DAA927E9EF8265ULL, 
            0x1461E51878254BB8ULL, 0xE3C3D7E406858511ULL, 0xD9B12AA9DA74489AULL, 0x187D2461C48298C8ULL, 
            0xD25AA39405518E86ULL, 0x3F324BC0E052213DULL, 0xD529C4947E660B0FULL, 0x7B1EB93DD16BEC0CULL, 
            0xED7BCFDE0DF2CAF2ULL, 0x97C2175A064A82B9ULL, 0x2CDBD278C89B8E88ULL, 0x18D2A74FBCDDD815ULL
        },
        {
            0x77F879933D6624DAULL, 0x55B669F145B7BBF1ULL, 0xC89F27AA1931110CULL, 0xDBF9723A058F8A2EULL, 
            0x03175FCC5456FA19ULL, 0xDD9F9419D98346DCULL, 0xE2AC9D1923427EB6ULL, 0xFD0600F813E3DDA2ULL, 
            0x3CD92658E2050102ULL, 0x410E2F074EBD3A4FULL, 0xDEEFC21CACF4DA83ULL, 0x53471AE1131C3750ULL, 
            0x52B1963CA66A214DULL, 0x3337A8B473BB9C35ULL, 0x7BFAEF57F3D0B1D9ULL, 0xBB9E35E111E96BE6ULL, 
            0xCBEBD8BD89AEB768ULL, 0x35B46C430C0A8E43ULL, 0x5718684D8588E8CBULL, 0xDE4AA1DE0DDF4460ULL, 
            0x559E9551198DAA45ULL, 0x8855B81F25415B0EULL, 0x2F2669B557487F50ULL, 0xDE05B3075D741824ULL, 
            0x01B44DBEE7DBED99ULL, 0x8D9A040D54EC0B3FULL, 0x60FBAD06F7CE4D14ULL, 0x624F0814CDDCEEB8ULL, 
            0xE06310CF6B7D0F59ULL, 0x2C8E3A8266DB05A4ULL, 0x73A35BC77E66DC00ULL, 0x2DA034EEBCDD0259ULL
        },
        {
            0xF979C5CAB55BA1CAULL, 0x20444DEF3FB4E049ULL, 0x153A812B5ED273ECULL, 0xCF9C6ED8634DAE01ULL, 
            0x59C8E9010825305FULL, 0x1D22ACAE7A4F0841ULL, 0x19125BEC5C3105BCULL, 0xE6106E475B09ACA6ULL, 
            0x815AE1F81849D927ULL, 0x87A50A88F4398B35ULL, 0x83977261BD501414ULL, 0xB3519B60B156AA3AULL, 
            0x8570B1C55A111538ULL, 0x376E3AD84112B576ULL, 0xB4E4922BEDB0DE55ULL, 0xD2711CE69A99A55CULL, 
            0xDDDF37385C1313BEULL, 0x69AE335A421434B3ULL, 0xEA209ECB10404FE1ULL, 0x69D987E0A2C2F09CULL, 
            0x9C88B2F6C1C73A18ULL, 0x653250844E6683FFULL, 0xE4159A22C768F2E4ULL, 0x5E14C2C805DB0115ULL, 
            0x3C08EA06018726BDULL, 0xBDE184B525495F83ULL, 0xF6EAF8738690DE3BULL, 0x5F09E942DCF23DF1ULL, 
            0x5170A164C1A1BA34ULL, 0x66B4615AB60EC9B3ULL, 0xFFC5EA4C26D19983ULL, 0x9739A56041EB14FFULL
        },
        {
            0xCA4B8B4E4E5D056CULL, 0x17253CD100C2CE26ULL, 0x9C031F8767BC8B57ULL, 0x7407B6CEF49AB9D1ULL, 
            0x507904DE202880E0ULL, 0x2EFD63EA42931DFFULL, 0xDF7EA503DB84693BULL, 0xA26780F4820E35DDULL, 
            0x77445AB2A8D350B5ULL, 0x047F034E08764740ULL, 0x477F6545A7AF1E3BULL, 0x36337F813F7EF14AULL, 
            0x9B6485B04EBEF5AFULL, 0x9BA714D7525DFCABULL, 0x7D826F6F591CFA3EULL, 0xCB3A13F86000A7D6ULL, 
            0x1863F9BE52380B56ULL, 0x5B934FF0C5963281ULL, 0xDA63BE739F3198C9ULL, 0xD0DD07556A862778ULL, 
            0x90E83A5D0CB3B333ULL, 0xD48963A0F08A2B68ULL, 0x8649DBBD2516A146ULL, 0x2379040959E6CE15ULL, 
            0x9438F6860565D775ULL, 0x7F257C53AA35A11EULL, 0x06EEA62EC853D9DCULL, 0x6049376BD5EBA6B3ULL, 
            0x893D0BAC8D5EFAC1ULL, 0xB0C15A92B3AD2993ULL, 0xC89F6CAFB242A23DULL, 0x146758A1B1D86707ULL
        },
        {
            0x02547966969607F6ULL, 0x4D4E5E868FC6E3E2ULL, 0xA7ED708A90310964ULL, 0xA0B3C434C353147DULL, 
            0xE9279B327DE84F2EULL, 0xB7CA9F05FBC76911ULL, 0xD3BA975C586C1BBAULL, 0xF889DF1DCF26A286ULL, 
            0xA2003D8D5FEB9DA4ULL, 0x7526F338B43C218EULL, 0xA00FBE7DA092A4ABULL, 0x30291CC1CB513377ULL, 
            0x724DB44CC8D0E42EULL, 0x4526069067CEC4B6ULL, 0xA3EFCB2F7712E549ULL, 0xD8F768FFA1E1F007ULL, 
            0xC80CFCF8B5F222E3ULL, 0x53653099CD736B44ULL, 0xC6D8F8F54460456BULL, 0xF32B6D60B651212FULL, 
            0x3B1551CAFBE36C66ULL, 0xE0FBC284D8D0DC8FULL, 0x12A45E0F15715D0DULL, 0x47A0B765DC87232FULL, 
            0x6C2A53798669081FULL, 0x200792116A9A6579ULL, 0xB799897F52D7EE30ULL, 0x28B2B5A1F86637E6ULL, 
            0x08E1FD1B9CAF6B84ULL, 0x5911A1703B4CEC92ULL, 0x9ED536C566651F67ULL, 0x6BE893A113E5BB67ULL
        },
        {
            0xEF3F423FE2BB309AULL, 0x04A50DA0D9362AA9ULL, 0x4519F382C5AE887CULL, 0x2D477363FF8F4780ULL, 
            0x9435903744457672ULL, 0x63271EB40746BA47ULL, 0x7FE31D42549E8D80ULL, 0x6525A72A1E794033ULL, 
            0xA3C44D6D9D8E3577ULL, 0x16A0E4BA413B436EULL, 0xCE5764D935DEEFE3ULL, 0x87BD92A49A26404EULL, 
            0x44231CB08EA5C105ULL, 0x6A3F58138EEDC122ULL, 0x36DF07E66260B196ULL, 0xC870AFCC2887967AULL, 
            0x8CAE55021E34CAA3ULL, 0xA9F9394E3CFBADC0ULL, 0xFCD9D9FD8DAF9AEDULL, 0xE081D26660DFFD55ULL, 
            0xA7415FCC07B36AA7ULL, 0xD9A070758D021F0AULL, 0x24D7E2A9AA4444FEULL, 0x184DAD2479C8A9BCULL, 
            0xC660317C7926B8FAULL, 0x7B1BB4E5B460CBE2ULL, 0xCA977F6E16C65252ULL, 0x822F8945CFB50559ULL, 
            0xA323957673D42C33ULL, 0xC37D086FDCCEEFB8ULL, 0x644BCB8F801674DCULL, 0x347C8EE1397E0148ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseDConstants = {
    0x15A6FFED8AC41D71ULL,
    0x0EB2303A6AD01402ULL,
    0x81E9ECBCF747F58CULL,
    0x15A6FFED8AC41D71ULL,
    0x0EB2303A6AD01402ULL,
    0x81E9ECBCF747F58CULL,
    0x238704BF791C3A99ULL,
    0x6A87776E5451DC84ULL,
    0x38,
    0x01,
    0xF5,
    0x7C,
    0x62,
    0xCB,
    0xB7,
    0x61
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseESalts = {
    {
        {
            0xA67CD462682DEBC3ULL, 0x2F2B68768534CAC0ULL, 0x667E85B84C9CDFF6ULL, 0xB6885B24D9236628ULL, 
            0x2A8E4762200AB08BULL, 0x4DD0B2B4D30E04D4ULL, 0xA6DCFF91350C7907ULL, 0x08D0B04EF1CE021AULL, 
            0x76D4B6C70E94CF67ULL, 0x185F7E28167BD1EEULL, 0xAD81B64AB4511542ULL, 0xCB5276BD6BEF99FEULL, 
            0xD9303B9BC1CF698AULL, 0xF3CF9687B56E181AULL, 0xAE8CBAC22F201911ULL, 0x21D3A8411B5D9C1AULL, 
            0xD40B1689A5C4767EULL, 0x392AEE7AC9E847CEULL, 0x3975E218E32E2D8AULL, 0xFF711EC5E433362FULL, 
            0x0E1F7CB29F642E7AULL, 0xC19161D66DB92788ULL, 0x937A81507BDEEB81ULL, 0x645C85E873A414B4ULL, 
            0x7292642215D9A01AULL, 0x798D85C41FB78D26ULL, 0x345E70D8302FFF4CULL, 0x014763CA0F61E8DFULL, 
            0x48548A4931C7C39BULL, 0x3E5C6AEC2A9AE3F9ULL, 0x600836F3FFA6F62DULL, 0x1349B0206F986289ULL
        },
        {
            0xAF019E01BC8DCDD4ULL, 0x498750A5E9ECC640ULL, 0xEDB277F11833CACDULL, 0x72EB6E31B605AA59ULL, 
            0x5E15C1951F736F14ULL, 0x2B3BC96C8665B234ULL, 0x6FA03927E28BFBCAULL, 0xAA754B81AA402D4EULL, 
            0x5DDAD68F766EAA5EULL, 0x1498B28D2E115E68ULL, 0x5149980BD9632D4AULL, 0xDA25FFB64D96E585ULL, 
            0x66347856CCE83FC0ULL, 0x511C0C4DD18E7283ULL, 0xC831F5F86C9EB74AULL, 0x409880895E451EDBULL, 
            0x1E1192FBB4661902ULL, 0x31F731C5D396967EULL, 0xF572EB957F773F23ULL, 0xA8A135662B6A3AE0ULL, 
            0xFC67F845332808E0ULL, 0x45A6A25E3C647F97ULL, 0xE91F9171AF00AC37ULL, 0xD06F9B48A1C41A74ULL, 
            0x36A6A45202AC402DULL, 0x2582B22FBF54F7F5ULL, 0x316CD2D335BF980BULL, 0xD15C22D5F0EFBC01ULL, 
            0x88597CDF3681E07AULL, 0x9EF1903554D7B84EULL, 0xF650E15712F57327ULL, 0x68D080098DCE1BA1ULL
        },
        {
            0x9CB770400DAA9B57ULL, 0x7010217C02082F22ULL, 0x860CCBB45E50689CULL, 0xBA37C6FC9B6D2303ULL, 
            0x6FB2840E8DFAD09FULL, 0xBC63B14001B06865ULL, 0xDA488E8A67CBFCC5ULL, 0x157F13145E409377ULL, 
            0xAF601969ADD5E92FULL, 0x84F19502BB8EAC05ULL, 0xF62BDE90137AC3ADULL, 0xB2B41B7A2420ACF1ULL, 
            0xDE353EE961E67F58ULL, 0x94BE748FF42F6523ULL, 0x7E22CD0F4C28C9B3ULL, 0x3C9BD5A24B4B560BULL, 
            0x65B065EC7BD3ED09ULL, 0xE9D7E87C93156884ULL, 0x36A80EFC69407E9BULL, 0xCEB76D22667548C3ULL, 
            0x163FD2D1461D3FAFULL, 0xA351DF304252DE7DULL, 0xE3265D48B5A2D35FULL, 0xA3F53E93BFB3390EULL, 
            0x7F18C8EB5208E231ULL, 0x065EBA38018EB141ULL, 0x54C94E7C088FA6E3ULL, 0xCBFBF77B527DBA5AULL, 
            0x224EAADD0EA3F561ULL, 0x2F87D56956B54326ULL, 0x1D70DB1005909E3FULL, 0xEE5E830AD19D54B6ULL
        },
        {
            0x5BE0D06E5979806BULL, 0x2795D38DEC9E59E1ULL, 0x67DE5DB0CA061D09ULL, 0xF5F685E0E40765DEULL, 
            0x8B66037B0CA98337ULL, 0x1BC2DB82E0562198ULL, 0x2EDF2C96F5E45CE4ULL, 0xC8EE3CF47109C7F6ULL, 
            0xC73FC290FC1E99EEULL, 0x2C7C3419DCC8AC35ULL, 0x90F08566D66D3090ULL, 0xA72F37516B4CEAC7ULL, 
            0xB6E6711AFAAACC0BULL, 0x8ED3B696977A3EE7ULL, 0x029403A3709A340EULL, 0xD58116E4DE7A5C08ULL, 
            0x51CE6498BB3D1114ULL, 0xB18D450DCBC9D186ULL, 0xFBAFC12DD4CAA008ULL, 0xB00B38BFEAE78054ULL, 
            0x9BA615C6719BC657ULL, 0x9A644877EEB2AF20ULL, 0x12474D5FEB162690ULL, 0x7AF9253A67BBF771ULL, 
            0xF18E2ECAA953FBA8ULL, 0x2AA04F1B21A0443EULL, 0x8306E7DB9776D07EULL, 0x047D31FDEA11DE75ULL, 
            0x96F60DE7496BDECBULL, 0xE043E9403266B4D8ULL, 0xF5F94E3D05E0AB6FULL, 0xC0B507A5EE43E8FDULL
        },
        {
            0x535673CF8B0EDB03ULL, 0x00B6787058F0B227ULL, 0x22AB7DC62AB5372DULL, 0x9B78C252FDDED118ULL, 
            0x3A90AB6DCD745F25ULL, 0x0421D0CF811D7580ULL, 0x4A47885BDC123C59ULL, 0x5655A6CE8EFD5F57ULL, 
            0x901234B55172AC7CULL, 0x0D407BA34A9E4913ULL, 0x3A3D411FE1F37246ULL, 0xBF37849C063307A7ULL, 
            0xEFB01C504D2F5DE7ULL, 0xC732950ACC2B136BULL, 0x26863ACAA80708F4ULL, 0x78EF1010A41E127EULL, 
            0xECB2290F68C8AD9CULL, 0x27C46B4838DB5D8EULL, 0x834770B2031DF368ULL, 0x9D8B6350F8E580E2ULL, 
            0xB2C2D23ADA89EC64ULL, 0x4728FE9423EE2F67ULL, 0x7724F838C46BB0C7ULL, 0xA679920898855FF2ULL, 
            0x633F5B1D43B101A2ULL, 0x55F3CCF19D0F7166ULL, 0xF89FA9AB48FE470AULL, 0xD8219BC32031FD19ULL, 
            0xF1D761C572D79D68ULL, 0x4D9C0B25673679EAULL, 0xDA5DA743BBAF9D94ULL, 0x9D28AE225A833A3CULL
        },
        {
            0x5258FA35EFB034B7ULL, 0x5253CDE86439E072ULL, 0x5FD4BD5755396C0DULL, 0xEDB0E92FFC35BAB4ULL, 
            0xAC27D07087B342A7ULL, 0xA7BF979E803AD0A2ULL, 0xC731569AE7029F3AULL, 0x50C111F0036938E6ULL, 
            0xADA4920B1C587EBBULL, 0xDE41DAFAE763192AULL, 0x09FDE181B41B584DULL, 0xD41529B5385294F6ULL, 
            0x03F7FC9B3E11390DULL, 0xA0CF294DB50A6228ULL, 0x0FD1B2BE5057F788ULL, 0xD2BC9D06502E8D3EULL, 
            0x1BD916BE008E0B93ULL, 0xD42987D18DAE115DULL, 0x9A71059048575936ULL, 0xDE3CDDAFFF21B640ULL, 
            0xD427881F5ED71FECULL, 0x563841340E236C44ULL, 0x492F2BD194429A99ULL, 0x06A70AF5C3F4847CULL, 
            0xA96731349BE653A1ULL, 0x16EA4578D40E1773ULL, 0xE7387BE35AAF3572ULL, 0xB9D807D86641B739ULL, 
            0x9DA9965BBE9B7BC4ULL, 0xC4633120CD6E1D4CULL, 0xED74CA1468E182F2ULL, 0x4C68DF237E9BEB1DULL
        }
    },
    {
        {
            0x750C7877EC75F1D6ULL, 0x825AFD83C8693E14ULL, 0x0C3F4873F18DA1ABULL, 0x9256A7A8F9C26536ULL, 
            0x391B0DFA304D9E1EULL, 0x15226F2B314A2F18ULL, 0x438CFF68750B0F60ULL, 0x43AB3F3136B7EF49ULL, 
            0x0F28754BA507BC7FULL, 0x4B6E844679D021DEULL, 0x59BB2D41C808B0A5ULL, 0xED77D923630ED543ULL, 
            0x312D22B36A9977ADULL, 0x105FDE696EDC2908ULL, 0xD8AF0FDFAA02B3E4ULL, 0xEA5DC335576903AAULL, 
            0x130FF100B1AF5028ULL, 0x9B4BBBE6BEA7D560ULL, 0x452690F7B1E6AABFULL, 0x08E809C60FBA906EULL, 
            0x015B6D5916030416ULL, 0x7F3852ABBB0F1B93ULL, 0x97D127D385A3C8D3ULL, 0xF3BB1D9B1E182159ULL, 
            0xF44D176BD1568E4BULL, 0x4F32B93075A6A8F2ULL, 0x2948BB4CDF720450ULL, 0x240DFE1CFE35651EULL, 
            0x7C27ECDCE0425203ULL, 0x471C477BBCCBC208ULL, 0xB1B9AF339AB6E43AULL, 0xAA12C7D113FFDB49ULL
        },
        {
            0x87DBFDE84E51B60EULL, 0xD6710A6928766ACCULL, 0x55D1E5F37B0BD087ULL, 0xABE4B531FC1A2043ULL, 
            0x601B3A93AA03A69DULL, 0x576EDA733219C877ULL, 0xA1B79328E1683A8CULL, 0x92F67AF8DE266973ULL, 
            0x9AD02A1A1CD0B946ULL, 0x5AB94FDC5FFBD11EULL, 0x8AE9966FAEC64324ULL, 0x13BA652494904595ULL, 
            0x9E0B69CF1C0552E7ULL, 0x7AE7EE6F3999AE92ULL, 0x3E75A2A0223A1E9BULL, 0x958EA9D817845FC7ULL, 
            0x4D47DC579103CCC8ULL, 0x4148A8BA45B0A11FULL, 0x9D1AF36C455835FEULL, 0x129C36FFD332BD89ULL, 
            0x3B03414BFC4A20FDULL, 0xCA410DCDD07DEAEFULL, 0xA362EFBD1CB3E92AULL, 0xB8165C2E35C3AE5FULL, 
            0xCDD66501D2678613ULL, 0xAEB1A0AD77A042E3ULL, 0x43AC87B989E59700ULL, 0x8A3A85FFCAF150EFULL, 
            0x60F0C0413C2CF24FULL, 0x1890200630CA6423ULL, 0x76E63DF52E6BEDE1ULL, 0xB813C717A4B76FCFULL
        },
        {
            0x5B00EF5845DCD45AULL, 0xE266C2067C6DD5B8ULL, 0x6341069318A47FCEULL, 0x5E654E5F909CDC4EULL, 
            0xD0643451D5256BBDULL, 0x637CDF58CA10246AULL, 0x495B6393E9D1DC88ULL, 0xBBACE006B79C98BCULL, 
            0x990FEF07CB4B88F9ULL, 0x2ECAC89F70CCAF8EULL, 0x3B668E973EAF6C4EULL, 0x8506DE59A735ADA7ULL, 
            0xB70600256C871F18ULL, 0x70EEC7123557FC26ULL, 0x6A7F1120C8093EB4ULL, 0x2255BAFEB9F36617ULL, 
            0x37FF0DDBC4FB4D4CULL, 0x9B0CB6931C9715D0ULL, 0x4F2089DD307F1755ULL, 0x63FB0B1584221184ULL, 
            0xE89282B533B3F324ULL, 0x038C12D760355A4EULL, 0xDF7760D26728CFB6ULL, 0x52A210A400E5FE52ULL, 
            0x9E987BD2B1A7FB11ULL, 0x4BEB11AA75E7723EULL, 0x1348F32B63A6C29EULL, 0x89A1D971A6E74016ULL, 
            0xC7A4AAAD525742F6ULL, 0x5F698A748D57FAE1ULL, 0x16487A3F77AF0309ULL, 0x8CCDFD0415945596ULL
        },
        {
            0x2292F13C2B06F754ULL, 0x403616307FCA9CC7ULL, 0x1F765D31066F5A27ULL, 0x781C2D7E7F3D9D76ULL, 
            0xA3435C26D627C9C0ULL, 0x0FD65A7D45C21AC8ULL, 0x083B8617B209EA1EULL, 0xD5A6283CD40299CAULL, 
            0x74C1A51CAB961214ULL, 0x5CA099D73AD88823ULL, 0x8D10B8D375AA6E63ULL, 0x283F7EA55C200869ULL, 
            0xF9B8050BE54B40C2ULL, 0x5F69E440F9824752ULL, 0xFD39BDF37552B5D8ULL, 0x0E858CE5FE7BFB85ULL, 
            0xFAA232D06CB30022ULL, 0x29678D5116FCA4FFULL, 0xF22CB2B16821A334ULL, 0x197431EF6D890279ULL, 
            0xB0473679275AEB94ULL, 0xF72B462359B9828CULL, 0x8905B1F023FC6A04ULL, 0xA6B0EC9FAD928B8FULL, 
            0x6CCA6E1B90AA753FULL, 0x15C1B08964EAE291ULL, 0x5D00017C7CEDD128ULL, 0xB8E78ED7179FFBD9ULL, 
            0x3241AEED05EFD3B8ULL, 0x6297B9251F4C329EULL, 0x98247D8C7D76CD2AULL, 0x220FE01CA01467DDULL
        },
        {
            0x48000BC337AE528AULL, 0x1560087B100DFDF8ULL, 0xA5AD2E5FE5665BD9ULL, 0x023795C5344E2B2CULL, 
            0x03C7612057C75E9DULL, 0xD00535E6B320098AULL, 0x1327F6A08C36030EULL, 0xF71B4660A4EFFC8EULL, 
            0xC0D5D4FB548546CBULL, 0x02D0A31C82249D25ULL, 0x44C68220D2561BCCULL, 0x66CA1991B4F8EF35ULL, 
            0xE0E3F791155AC207ULL, 0xB9291CD3646ACAACULL, 0xAD5A81ADF1742B2EULL, 0x3CAD67A97EA64D9AULL, 
            0x54E88B88D19E0F49ULL, 0x8C44C7EB23448DE2ULL, 0x1DC946A92D7CF3F7ULL, 0x2F59472EF24CFBACULL, 
            0x2C1F26B6252ECC07ULL, 0x3D0ABF1E9EAE3EAAULL, 0xD27201131F304301ULL, 0x028E48BE42439299ULL, 
            0x555263D706973F92ULL, 0xB674105AE7EFA703ULL, 0xBF9C13FE7CF14421ULL, 0x8BF60031C1159BCFULL, 
            0xA0F936FBBA2C8F4BULL, 0xA2589F6F059400A4ULL, 0x1B6AF0C1D7EE7E1BULL, 0x49109CBAB571AAFBULL
        },
        {
            0x2CFB3681C39C7815ULL, 0x0CB0CEFC218C17BFULL, 0x2A4540295F9572D3ULL, 0x0FECE97E52639379ULL, 
            0x2DD50CAD143EE047ULL, 0x42117CF0D2026B55ULL, 0x266AF9F3BFC3F654ULL, 0x379AD163DE2F68DDULL, 
            0x408CF8154644015CULL, 0xACA2F0B129F1E0F6ULL, 0x5023CE838446A8CBULL, 0x726BAC5788035164ULL, 
            0xFE8ECA9E0E11D871ULL, 0xA0BD3A75C44E9E0AULL, 0xBE7B7A0768C644F9ULL, 0x040F9BB1F8F75B48ULL, 
            0x022F8D35FF4D5FCCULL, 0x0137316E737E856FULL, 0x9708374D440621A9ULL, 0x4FECB5A2602E702CULL, 
            0xBAA77A99CFFD1772ULL, 0xF9236020D925DC7BULL, 0x6DA4BDF428EB04F5ULL, 0x713511AC8AE1C07FULL, 
            0xFFADBA61C9DB0646ULL, 0x01E9AA0E1237D085ULL, 0xE43BE71339918B4BULL, 0x8242416423F0352CULL, 
            0x5E22DD22E554D850ULL, 0x4689856DF5EF11DDULL, 0xB1C002C1D7C2F2DBULL, 0xAA8A374505FF6357ULL
        }
    },
    {
        {
            0xE9E1D67772BC36B8ULL, 0x2F38930750BF9FA7ULL, 0xCD6B29CC4DC998CBULL, 0x0660611D9183E5E0ULL, 
            0x42E39445F762B2E2ULL, 0x2244F1DFAE4F22AFULL, 0x4B7DCCD3AA519099ULL, 0x315B7E9908C8490CULL, 
            0x068F72693297D726ULL, 0x691B0FA5E329E73FULL, 0xA48D7CE22AF17C06ULL, 0xF432313F34FE7E89ULL, 
            0x21081021A4D2AEFBULL, 0xC902FD709C49BD89ULL, 0x1B51DFFD78A0F987ULL, 0xC368D0E2A2C15C41ULL, 
            0x522E6BEF01868140ULL, 0x8E2B401B2DBFF1C8ULL, 0xD373EF0159EB6F80ULL, 0xA915C502913564CCULL, 
            0xA0B40FD545844475ULL, 0x019527FCA6C802BCULL, 0x1DDE91962D07237CULL, 0xBCDD5D47F5093084ULL, 
            0x4E625EBE67B74813ULL, 0x4AC0D1B3EB0FD2F5ULL, 0x02D0B18FAF4D8E51ULL, 0x5B4700FD7F990E73ULL, 
            0x4B2FA9DC485B2626ULL, 0xC1D063B0D25F5436ULL, 0x84739DB0B2FE22DCULL, 0x4E2F0B938BC27D72ULL
        },
        {
            0xF897C288105DDC15ULL, 0xDC7A79E48D7EA40AULL, 0x7BA43C65F8243ADCULL, 0xAA241CBAE9FAF3A3ULL, 
            0xF14244BC495249B4ULL, 0x4CAC17F78A27B707ULL, 0x46FBC37041D80F5CULL, 0xD6FC20CA9E0DE555ULL, 
            0x61E822AB6883CC24ULL, 0xB9C11552D22E0C96ULL, 0x7618A9E8D2B61C92ULL, 0xC6B1F1E018A63F23ULL, 
            0x78ADFB88D93AB79DULL, 0x7B3B6444D5F243EDULL, 0x3376838F3D58CF8FULL, 0x55DA790C00B88F80ULL, 
            0x3A6D04C6865DEAFEULL, 0x8C0019BDF0A6A085ULL, 0xA0F6BC85BBD0C2A7ULL, 0x5240372234A85179ULL, 
            0x27BB9E6255176A9DULL, 0xE655261D545570AEULL, 0x12F5AD486905392EULL, 0x7354A03E44B8C1CEULL, 
            0x347A191C50FE28FFULL, 0xCAE30C6C1961AD6CULL, 0x9A67FBA9D6CF0D47ULL, 0xDC1ACD811FCB7F66ULL, 
            0xAC163F1198D7B11BULL, 0xD85464362FC92B3CULL, 0x9B594148DD70EF86ULL, 0x03C3C26D498F5042ULL
        },
        {
            0x7593D4942D9F9188ULL, 0xD6C29FCE9EB84F1BULL, 0xBDE212CC0DC05A2EULL, 0x35027CBF429A42CCULL, 
            0x3DFB208A58508E3CULL, 0xAEF22655FAAD9381ULL, 0x52C4C90A9E05EFA5ULL, 0x6815EEA8E81D5F81ULL, 
            0xC8D7177C63958805ULL, 0x043C97A9889B8778ULL, 0x5C593B3D722F890CULL, 0x3C9680170DB75B1AULL, 
            0x6E5ABBD0601389FFULL, 0x29C06D226CE3E62BULL, 0x9ABD553664215E3EULL, 0x72C8C85C78D7D89DULL, 
            0xAB70D523CDE97FCAULL, 0x920E88142DDAD806ULL, 0x50B7A4D0AD18BF4BULL, 0x5A8F35FEA86815A8ULL, 
            0x6EE9C9EC3DE95AB5ULL, 0x6B19A3137FC8485CULL, 0xF8D43B1CE75B8B74ULL, 0x65C4076A2CBBF05CULL, 
            0x574380F3BAC87F57ULL, 0xC8F5D2279372E1AEULL, 0x113A8B3BF9062264ULL, 0x59A300F2F48EF6D4ULL, 
            0xDEC784E3AD698119ULL, 0x5A5874A4A00D166EULL, 0x9738D32FA8262BDEULL, 0x6C08290E80A200ACULL
        },
        {
            0xCB0C2F733BBA27F8ULL, 0x3A6E6B3354039039ULL, 0x45E30DA1152CB162ULL, 0x5C66B9652BC90F9CULL, 
            0x882398B1214655B6ULL, 0xD21F90E0146CFF5EULL, 0xAC3398327ACD2A1BULL, 0x4E1F69D757DA2491ULL, 
            0x8C748050FAB82B4FULL, 0x28E8173E3E2CEBE6ULL, 0x299F1154CF7C7953ULL, 0x8D694C41726BE5BDULL, 
            0xB39B9F0A1CC5F581ULL, 0x8D6733BC2911B2E5ULL, 0x95A47B325A5F4E86ULL, 0xDA64385683B10572ULL, 
            0x00405CEA9A0C3DAFULL, 0x5E5E52ED7E6745B5ULL, 0xD9DE428A525D42B5ULL, 0x1BB6FA8B01C250B6ULL, 
            0x10CB8096DB98AA1EULL, 0xE698C931BF7257B2ULL, 0xBDDC583DC88C4BB8ULL, 0x591156A024C6EDCCULL, 
            0x0BE0A90BE6246C86ULL, 0x9E1B754EDA2AB4BFULL, 0x5203001B635AC2ACULL, 0x62E6E5DDC3DB20FFULL, 
            0xE38A67C39469EB34ULL, 0xE7DEC6575A507FBFULL, 0xA564F8D208F23069ULL, 0x33A08B86C951636DULL
        },
        {
            0xD663F38A1E749532ULL, 0x806404E01DBC49D2ULL, 0x45FB13134510D2ABULL, 0x612B4A9B29A06AAFULL, 
            0x26F8CEC9F2842120ULL, 0xB8A6AEC2A06EC97CULL, 0xB81350674BF35923ULL, 0x8D9F680E5B16D9B4ULL, 
            0x6CE9AF2212BD4AC9ULL, 0x1CE60AB5D4CCE663ULL, 0x9CED2658288CEEB1ULL, 0xE56F029534733F42ULL, 
            0xC86A7026240C939CULL, 0x9AC734D190E7B3A6ULL, 0xF9C38640842BCB36ULL, 0x8F297B68F67FF6B4ULL, 
            0xD8BF8352DCEF95B9ULL, 0x5B1F8B985287444BULL, 0xA0E82EB250BFEE3AULL, 0x83FD45B9FF19A400ULL, 
            0xD0FC29716B7DF799ULL, 0x325D96A6B160A158ULL, 0xB4F46782CCFFD455ULL, 0x992F5FCADDDA59A5ULL, 
            0x1696B1309DBF8C3CULL, 0xAD6B63D172BAB538ULL, 0x2ABCA3B2179398B9ULL, 0xBF95421C23F9D9F8ULL, 
            0xBDD1474CE9BE57B9ULL, 0x8A0CACE09B29EF16ULL, 0x18B769A7C6AE8327ULL, 0x53783F27A20D0212ULL
        },
        {
            0x0918EFF5AB6EE139ULL, 0x61A56B2B359B6AE9ULL, 0xA6A1F9CB597617ACULL, 0x2C3B2495C487071DULL, 
            0x2F822B1BBDDAD7FAULL, 0x57700E013CDB2274ULL, 0x686C3A765ADB3AC5ULL, 0x9720A5277BABA125ULL, 
            0xBA748391CEA9E631ULL, 0x43761B2C71DDD412ULL, 0x5CE4D8A8DF328EA0ULL, 0xB26AF0B855C0E332ULL, 
            0x9F2DB8A7ECD91D43ULL, 0xFB014A7E18FBC307ULL, 0x11191F639720E92EULL, 0x0448A8274322E148ULL, 
            0x67788B4B6374B3D8ULL, 0x97F6500D41331346ULL, 0xA6B1DF2B337478DFULL, 0x34FDF03FD11DBC1CULL, 
            0x84CB99233A6F6F9DULL, 0x2AC0DE42F6DD8B9EULL, 0x18161593BEE83C40ULL, 0x97370BBA9CF8485DULL, 
            0xD69FFEA0BA4BA650ULL, 0x2FB23BD50076F3A7ULL, 0xE8B6B2854EC8A8F2ULL, 0x2380D59A21800171ULL, 
            0x6726579399A7A900ULL, 0x4C9EB9A5BD0B7A47ULL, 0xF370E987662434A6ULL, 0xEBD3B44A9FADD4FAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseEConstants = {
    0x78962A94566F29E6ULL,
    0x287B52A4EDFCFC0FULL,
    0x3E9F5DDA3D65B607ULL,
    0x78962A94566F29E6ULL,
    0x287B52A4EDFCFC0FULL,
    0x3E9F5DDA3D65B607ULL,
    0xC1B4B2F860E45F32ULL,
    0x07B1AB3C56D8B62DULL,
    0x4B,
    0x61,
    0x04,
    0xB0,
    0x84,
    0x4A,
    0xB4,
    0x25
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseFSalts = {
    {
        {
            0xC94305D8666BB108ULL, 0x1EDABBC33E78AEECULL, 0x3B53DE92412BE554ULL, 0x0B5F9D04C75847A3ULL, 
            0x7CE33D8E6F9249D3ULL, 0x0CBB1ECF4E3E25ECULL, 0xA7C9EAA0369F72F7ULL, 0x3A97409E6EFFF742ULL, 
            0x5FCD9DB5783D4897ULL, 0x3F7F9F857EFAD025ULL, 0x97D5C92C2DE64D4BULL, 0xFDDCF570A8DAEEDEULL, 
            0x4E0426CACB682EEFULL, 0x9936420EAC61A302ULL, 0x06B9D06627631136ULL, 0xB4D756DFBD4DEEC2ULL, 
            0x19C0A992779237A0ULL, 0x0837FDDAA81BBC6FULL, 0x42532DD0D0B43CEAULL, 0x485542248D4ED18BULL, 
            0xD4DC7025F2621FE1ULL, 0xAD1E2808DBD92141ULL, 0xA7C9135BAE470000ULL, 0xCA44E3C0D8AD6F26ULL, 
            0x3FFA27EB82134FE2ULL, 0x9A4A94CD6A611218ULL, 0x62D44322DA80B470ULL, 0x3B386E35A68257F7ULL, 
            0x550B4F2F6E1E3EECULL, 0xDF3D8CCB33DB00EEULL, 0xC6BE103D0330C424ULL, 0xC91AFD071AC43134ULL
        },
        {
            0x4A05AE44699CC4D8ULL, 0x4E8F2CCC8532382EULL, 0x1D6355A3190E1484ULL, 0x2AB1F710B202BA13ULL, 
            0x7B91401581FD4248ULL, 0x69B40DA9CC77B0A5ULL, 0x2226618EC85F9779ULL, 0x53078333B954E2F3ULL, 
            0x8A519196415F1E04ULL, 0x9C13EE5E471EF960ULL, 0x5E380D4EEDBBE9D6ULL, 0xFD85DA87AD0652E1ULL, 
            0x8F5623260A97761EULL, 0xE98EDEFF3AE91D2CULL, 0xECFD8ABAD54513C4ULL, 0xA73F9681CD5776AAULL, 
            0x9B045F1B03EBDA0EULL, 0x073FBD2899C006CDULL, 0x95EFDE5908D4169BULL, 0x62516C5A147E94DDULL, 
            0x9D8F6470A19978D6ULL, 0x1FFA5CE8841A3E48ULL, 0x06ADFFA77AC6801FULL, 0x7ED1C8D6F331348CULL, 
            0xF1AB65FF6D589594ULL, 0x12B3275EC65732A9ULL, 0x8366A30BEA57D059ULL, 0x8EAAF0A6E1031CCCULL, 
            0xEB2710567F55AC9FULL, 0x92774BE92F130D84ULL, 0x059832677B9AF711ULL, 0x841781CB60E0DAF8ULL
        },
        {
            0x6CE597CACBA97F02ULL, 0x82048BB0BA5CC35DULL, 0x1E3906327F05DAFDULL, 0xE113E97FA9DA555FULL, 
            0xC48F4BF75CAE879EULL, 0xAF4F0E585EA8B24EULL, 0x214906CA9690A071ULL, 0x0C406D543D6E8552ULL, 
            0x1938172B446497FFULL, 0xFB4E4E1BC6ADA5B1ULL, 0x2E2605C6DBEF66E1ULL, 0x229941579A35DD10ULL, 
            0xBF0146EB9F5C83ACULL, 0xADE87E489AF143B8ULL, 0xF032895A3FE4A439ULL, 0xD051B29E1EED3D5EULL, 
            0x94DB9E889FEDC5D6ULL, 0x80947CB9D367C216ULL, 0x80CED5363D83E72FULL, 0xB4A4A7D79A961748ULL, 
            0x8B1E565A4FB79630ULL, 0x6A0B8D7E3EA284BDULL, 0x56B00D960DBFEF85ULL, 0x59E80672F5A48BA4ULL, 
            0x45371AD0B0400B55ULL, 0x03A8655E4203B0EDULL, 0x77D4AD72AE6D9AEBULL, 0x4BD4E07A3B39F550ULL, 
            0x37FC9EC935DAD883ULL, 0x8695046F5EE4CF15ULL, 0x3892028EA2756D75ULL, 0xA1FEBEBDD4B779ABULL
        },
        {
            0x01A1F8D6376F2B00ULL, 0x72F93FB66D71217AULL, 0x403613AD26D13B72ULL, 0x3A6681A8D164A7A9ULL, 
            0x44DB74421FABBDDAULL, 0x3CC004C0A7FA0E8AULL, 0xE9D9B7B40FEE54A6ULL, 0x23B434B402C2739BULL, 
            0x9CB6695665FA96CEULL, 0x3F9E98789A6C0FDDULL, 0x5D33D5FC5F7F502BULL, 0x107D896B1F595A4FULL, 
            0x5F397E803A8B843AULL, 0x2B232EE42F771E2AULL, 0xD9D67BA0B6EE521CULL, 0xA87E1488C7437591ULL, 
            0x1E093B67B17E273EULL, 0x723B998043671686ULL, 0xBEB6011D65EBA9ABULL, 0x689B24C3899B097FULL, 
            0x21EFCA2EB0204417ULL, 0x92DA4DEBF6BA99A2ULL, 0x777F24AC7A022C4BULL, 0x1EC2D97E778EE2A9ULL, 
            0x2BEFE491A4329FF0ULL, 0xBCCE1431BD481CE3ULL, 0xE5FB06FD00C12E48ULL, 0x367922C3E455CE08ULL, 
            0x1ECE70D3820A7AEDULL, 0xF0F76A684402BDAFULL, 0x051759FF21072F44ULL, 0x475C259A1A9921A8ULL
        },
        {
            0x11109AFCAFCBE848ULL, 0x25CEF3E4DAD4651EULL, 0x47E831965C9B3DFFULL, 0xEE52097220AEA6E1ULL, 
            0x20FD399A2EB3BCC7ULL, 0xAFBD4983611812E1ULL, 0x47E420BB03EF575EULL, 0x87081919280678F4ULL, 
            0x609D3F0BD491FF7FULL, 0x3338341BCBCA9F97ULL, 0xBB4208F72948A0DAULL, 0xB875A4A324D89090ULL, 
            0x67631A78649E52B5ULL, 0xB46A5365B052CF66ULL, 0x07E6E673B7503AAFULL, 0x1A05B00474657176ULL, 
            0x18289FB1BDBBBD4CULL, 0x73E168EC404B944BULL, 0x1BD774CF104710F9ULL, 0x0E931B991BB75C75ULL, 
            0x0EF755464DAEC83BULL, 0xDD8D6EECB6689BF2ULL, 0xE2D42E8B42878B92ULL, 0xDA49CD6F68211492ULL, 
            0xB8091097C92FCA35ULL, 0x440F7C47356515F2ULL, 0xBDB0FCFA7E7A18B9ULL, 0xE7E61E8D0D1F2D7EULL, 
            0x50A50B4527FC9A48ULL, 0x71E94F58BB922CF0ULL, 0x9CAD6AEDAA1FD4D4ULL, 0x7266368CBC355930ULL
        },
        {
            0xC8C7134EE7F9B26AULL, 0x616AEE8EE9376288ULL, 0xE6DE179C7FBA65A6ULL, 0xC6F5B0F0F863CF51ULL, 
            0xDAAB5979274FDFA1ULL, 0xF54DC0320C7818E0ULL, 0xFDD630A8ADC53300ULL, 0x0E4F663BEA8F1D1CULL, 
            0x4680B87CC429C1D4ULL, 0xD557938E85B0924BULL, 0x1D4719CD9BA942B1ULL, 0x51FC3728FE56017FULL, 
            0xB5F281966B8D86F7ULL, 0xEC96820A85CDB96AULL, 0x8389EA289C671A98ULL, 0x702A8CA061245C9CULL, 
            0xAD599CBA7B0564EBULL, 0xF57418657BD25C05ULL, 0xCF28B49F4B10C9ECULL, 0x7F9203D0D95B80D9ULL, 
            0x6D576306ACE7EC25ULL, 0x7F682013567F499CULL, 0x4F88424FDDE4998EULL, 0x75FB6450B9FFAC61ULL, 
            0x6FD06764770B65FDULL, 0xD129DE96B1303BCBULL, 0xEE6FB8CDF5EBCA72ULL, 0x78D92215E4597454ULL, 
            0x52E0FFBCE1182652ULL, 0x3726C5200F7A2F87ULL, 0x47BED83B227F0BDAULL, 0x39E2ED864CD6BA57ULL
        }
    },
    {
        {
            0x3DFE4546149C5568ULL, 0x470CF9EDE93B19D7ULL, 0x40296FD6FEC0234AULL, 0x2A3641A59F5241F9ULL, 
            0x8D026B7145ADC4A1ULL, 0x1B92F039BC23900EULL, 0xEBFB54E82623C840ULL, 0x810EDE4EEF2EC24FULL, 
            0xB98191BB02806167ULL, 0xFB22C25399B3A124ULL, 0x965DAF776FD5F9ACULL, 0x7ECB28D2C0E560F2ULL, 
            0xC16A04EC016AD838ULL, 0x7665D4D152DC7D3EULL, 0x471655C26A85D3E7ULL, 0x58EC39AB5FEB28FCULL, 
            0x19E71A13B91F1ADEULL, 0x3B708414109CFFAFULL, 0x429B2592FCBEC9C1ULL, 0x815CD7A1E02643CDULL, 
            0x91599FB7EDF31E29ULL, 0xF865345A3A432254ULL, 0xD40083CD8254FA76ULL, 0x547AE29CD34608E7ULL, 
            0x41F457746C49CA51ULL, 0x4EAB8FCC2E36BBCBULL, 0xD9E8C17744C0A444ULL, 0xADDA4DCF58EDCCD8ULL, 
            0xB29E7FC9CA58C75CULL, 0xF5AE8628D7754353ULL, 0x411F3D4740EB7314ULL, 0x027E2ED7006C1018ULL
        },
        {
            0x196AF01D9B1BC570ULL, 0x3A69ADA51280FCC3ULL, 0x793FDA2197FD148BULL, 0xE034B78B1E893865ULL, 
            0x8147DF63EA057832ULL, 0x35805B2EDE0B2A42ULL, 0xEBF9F700395469E0ULL, 0x43DCD83E60487E71ULL, 
            0x40AF93DB280BF838ULL, 0x5BF4A1F5DD5521E5ULL, 0xD0AEFB6D743F1737ULL, 0x2A4BA2387C570E81ULL, 
            0x0C7B2B9766D28E21ULL, 0x170207D11F2B5035ULL, 0x6DDAED07461D18BEULL, 0xD7AA76971B39E059ULL, 
            0x1CABCA9E66C4D920ULL, 0xB203273779E76DAEULL, 0xAB5E1BC5AD44A1F8ULL, 0x810CDCFF2388B154ULL, 
            0xFEEACB76F52A41B8ULL, 0xBB3DACCCE5B0098FULL, 0x3F19BF43387E577DULL, 0x7BFA0D47C83FFE64ULL, 
            0x7B7CAC68BA6A7863ULL, 0x52DFFFD87FFB2200ULL, 0xD3F0D4D6CBC51823ULL, 0xD624168FB787AC1CULL, 
            0xFB5C421EA665A472ULL, 0xCDCB25076D0904ACULL, 0xB0200D95EFE2EB35ULL, 0x04C40387EAB14D1BULL
        },
        {
            0xBB72FCE1B74A9F1AULL, 0x6D5DCB1133937AD4ULL, 0x4FD9D5D73067979CULL, 0xC91EF47E1D997948ULL, 
            0xCB71CE2E9F69F184ULL, 0x36DD079B5DA74D49ULL, 0x6CEAEBF5806574E8ULL, 0x5901A64769CB9DD3ULL, 
            0x156E404A10018F39ULL, 0x10844221DE7150F9ULL, 0x601857FD222D56C4ULL, 0xB017551ADEB3A649ULL, 
            0x92C528B3C2037F1AULL, 0x2BF25499127C94B8ULL, 0x6FFF4673C72B2E7CULL, 0xA2C875BEC7726DC8ULL, 
            0x7B034E73A54992CDULL, 0x2B10A2EEA8DDDB77ULL, 0xF28B3622F5F5F4C7ULL, 0x6D07001961306E9CULL, 
            0x65CF468BB601F8A6ULL, 0xE48D0931A713B58EULL, 0x2673ED1D69A5D856ULL, 0xF20229B6055426BFULL, 
            0xC1886D52A55A242DULL, 0x654663441A8F535DULL, 0xD39A5744D9B24830ULL, 0x50EF22EE2DB381D4ULL, 
            0x9550CA8B394C1CDDULL, 0x0663FAE669AF3021ULL, 0xEB07DCF2892522D5ULL, 0xFE548D10BEA0C2ECULL
        },
        {
            0x70F53CD36A0B3938ULL, 0x826AED3CFF056E43ULL, 0xB6261535A1EEFA38ULL, 0xF124A68BDA23A163ULL, 
            0x6C12D876252A930BULL, 0x1654BEB75EA4D4B8ULL, 0x9DB9ECA3A5981F0EULL, 0x7C043386A67AB9BDULL, 
            0x976C1E6488F13FB8ULL, 0x924F95B4B1E51FABULL, 0xB73864C0869A2126ULL, 0x8718742F63CC9B0DULL, 
            0x003CF41D7126D708ULL, 0xBF5CA077CB60E805ULL, 0x216CD0AECF4ABFBCULL, 0x554AFB52E6609BD5ULL, 
            0x6A36819BA52E80DDULL, 0x46A189D0EBED78CAULL, 0x5B28F788A034E862ULL, 0xF9EFE7431F8A8F0BULL, 
            0x479B4B02C0E53F18ULL, 0xFCE87A94E4B91DA5ULL, 0xB46AFA86A2B26FCCULL, 0xFE709AB6E9372E3EULL, 
            0x592C16B6505F4113ULL, 0x2A0A57AF7677B0E6ULL, 0x0FB0F4614B1AF629ULL, 0x7E233D4DA982A64EULL, 
            0x6AB531179BE18F30ULL, 0xF245D3F2DF45D7CDULL, 0x30E4AE35E0C9E51AULL, 0xF96150E07ED1C7E3ULL
        },
        {
            0xF4F1DA0DC34B11C8ULL, 0x25947AFC9812F55CULL, 0x3DEB0AC6C8CCF0FBULL, 0x6FC143D16860F214ULL, 
            0xD5B7E6E759DE6C3FULL, 0x3FCD9BBC3A65B3BBULL, 0x13756919FDA850D5ULL, 0x4A9FE5BC2336A131ULL, 
            0x1ED7F68141C247FAULL, 0xE32A7EC2A3C7B2B0ULL, 0x107E3667A6867CD2ULL, 0xA5809F5518B74DE1ULL, 
            0xE0A7C7540F2E67E7ULL, 0xD28CB7E7FB984549ULL, 0x8DA1949776842B96ULL, 0xC2F8BD6E949055CAULL, 
            0x7041AA80709C6DD3ULL, 0xBED30EDC59A455E7ULL, 0x8FFAB2ED906241C9ULL, 0xE926B879266B3DC3ULL, 
            0x3BF5FE9FADAE7EDFULL, 0xFB87D62A0A4DF52DULL, 0x570B771B4F558A9BULL, 0x5EE6DACCAB4FFFF3ULL, 
            0xE62FA5960F43D68BULL, 0x8DA7BD3F2955FD9FULL, 0xB0807863BEA98E66ULL, 0x83675B3C6D23E186ULL, 
            0x41EDD6011F9913B4ULL, 0xA6CB8FBFE7A0920CULL, 0xC42C54530ADAD1C8ULL, 0x9096E9314E04F75CULL
        },
        {
            0xA25954527B279579ULL, 0x07539A91C415EA36ULL, 0xC72EC2DFD1906AD6ULL, 0x31767ABBAB1117A2ULL, 
            0xBEF8266951622376ULL, 0x5BCFEC1D00A1203DULL, 0x6C49DA5EFDE5BB5CULL, 0xB0E493A4D5FB1D6CULL, 
            0xF84D05D31C2D6DDFULL, 0x5280AB8915E942BFULL, 0x715EDD8553411C4DULL, 0xBFD6B37DC33DBCD4ULL, 
            0x83397A7221E10BCDULL, 0x9C4C11CBCD129423ULL, 0x277F607DB4211BD2ULL, 0x941EDDA4645ED471ULL, 
            0xE5E3F03DE781C738ULL, 0xF9E305526293BD72ULL, 0x5F45FD7A25BD762CULL, 0xCE342050E7DD7780ULL, 
            0xD9CAB396825B77D1ULL, 0x1632BFAFDD9C28DDULL, 0xAC077E6CFE86B9EFULL, 0x1B50C1B0F0812DA2ULL, 
            0x74A17AAE2F1B6B6AULL, 0x60F590FE6E64C51CULL, 0x2CDB1EAFB8897F38ULL, 0x4156B8DBFD54936EULL, 
            0x3207C0874F340723ULL, 0xF3B759FB33D255DCULL, 0x9D05A67AE29065A0ULL, 0x1FF90A8B4FF10F4EULL
        }
    },
    {
        {
            0x90E89E92BE4EE179ULL, 0xF60351FC81DEF072ULL, 0x9578A658BC994363ULL, 0x7801E7FA00BE4D2CULL, 
            0x0545974E6EE4CEC0ULL, 0x2B77414B7BE28E8CULL, 0x75614AE1E9051B63ULL, 0x516B5AB09D5A6AEEULL, 
            0xE63BE094CD88B08EULL, 0x31225AC91431587DULL, 0x629C9C0B2063A1BBULL, 0x6D57C742689F91ECULL, 
            0x89E4E9DD8116BB89ULL, 0xE814CB0B1BFAE9F1ULL, 0x1D1ACE0E45872D4FULL, 0x7FA79B2189318012ULL, 
            0x2BA29DB248267A34ULL, 0x3EA1A50FAE71B3DBULL, 0x640AFF2EF499AC69ULL, 0x26B71A11081EC185ULL, 
            0x805F2A0088900BA5ULL, 0xE6A91A1D108C83BEULL, 0x43B799E7C3701DD4ULL, 0xECA29A25DC1B5AE2ULL, 
            0x35D03948902DA3BFULL, 0x9F8C72DE24E44D17ULL, 0xDBDF85EE1B6167BBULL, 0x473DC4ED75B644CBULL, 
            0xCD0A4F2A815A1045ULL, 0xB0042961E2B5B138ULL, 0x6EA29F67B034E9C6ULL, 0x893252F2350B9EF6ULL
        },
        {
            0x4D9976FD59DC763CULL, 0x67D41F58FDE49FD3ULL, 0x3B79D70235523F7DULL, 0x7EB386EB49997B26ULL, 
            0x8035D740CF345EBAULL, 0xF65B0CAA50D7FB82ULL, 0x4EC4D48A0EF5F8F8ULL, 0x8E1CBE0F6EE84B43ULL, 
            0x8CB32DBADF658839ULL, 0x58E542D0A3B48F1AULL, 0x477C2D5553B8901CULL, 0xC13B43967EE592EBULL, 
            0x082F5721280772B7ULL, 0x8FDA22725F1D8AB5ULL, 0x4B24886E951F3217ULL, 0x9B2D388EA829B765ULL, 
            0x3D50688B502BF83BULL, 0x05FE578FC9FA7866ULL, 0x3F4C5EEC4046F323ULL, 0x5FC52DDCD0FF454EULL, 
            0xBEDCA213B53AF985ULL, 0xB5CA38D2F978F344ULL, 0xAE3309CC986414B3ULL, 0xD7FADA23E74C7EA2ULL, 
            0xB303B0F6AC34CFD5ULL, 0x9ECEFA5BA4718D3BULL, 0x98965AF4F5197B60ULL, 0x850A787D3C58D6EEULL, 
            0x90CD6CE2C713DF5CULL, 0x717393713BEDEF88ULL, 0xB706AD0062BAB21DULL, 0x7024F733F82E6889ULL
        },
        {
            0xD76F9B4B3FDEEBECULL, 0x53040414D1766FA6ULL, 0xBFD8D74352599969ULL, 0xCC652A0EBB09588DULL, 
            0x117AA6829D468028ULL, 0xEF75B08A2AF426BAULL, 0xD52CCEA69FFBF5AFULL, 0xC150D39D1BCA9274ULL, 
            0x4CC7E3A0F31DD76CULL, 0xD44A4DCB003AE11CULL, 0x22B24D70A717A6FEULL, 0xAB736355643017F9ULL, 
            0xECEC359F70C2B895ULL, 0x69EF122D0B789461ULL, 0xD5B7BD3F3597E4E4ULL, 0x447C713E62ED471FULL, 
            0xBFA9F1DE6980C738ULL, 0x8B126605AD4C853AULL, 0x5B5C4B22298EB536ULL, 0x2B60D4FEBC7202D3ULL, 
            0xCCFC7568131C8F8BULL, 0xEE418AC7B5166D39ULL, 0xCE751C7AACA103B0ULL, 0xF37D2AB7F3ABBD2EULL, 
            0x10E00474F976E601ULL, 0xFF3A6B86B3A35C67ULL, 0x9B164601D8F5D593ULL, 0x6A99B4F5ED51DDF2ULL, 
            0x6CB7AEFDB2378B7CULL, 0x11908C8CA77CD2DEULL, 0x9D5F55F151BCAF78ULL, 0x3E36CCDFDD5EA74DULL
        },
        {
            0x4D0038D313B39F80ULL, 0xCD8DD12DFB3D5CB9ULL, 0x7BFB50CB7692272EULL, 0x8223BAA00833B59EULL, 
            0x7A484BCC4ADD2651ULL, 0xE80C61D927609249ULL, 0x43EC70218CA345A5ULL, 0x0A376E388635F9D6ULL, 
            0x8DED43FA97490C14ULL, 0x3DEB551653D1DC44ULL, 0x6C7C9B2CFBE5B31EULL, 0xEB3EEA844667B964ULL, 
            0x11E7C53EB647CC12ULL, 0x6765E5C21BD5D96BULL, 0x16BF1253160BB0FAULL, 0x64D0366FC29224E1ULL, 
            0xFC8E5864D668BD2AULL, 0x54C716ED5C2A719AULL, 0x77AA643EA843BD17ULL, 0xE5C4FCE4BCE08C0CULL, 
            0x67BC9B26293DD08CULL, 0xB59F82E37208693DULL, 0xAEE80E8F63DA5ACCULL, 0xDBA85A98EC993833ULL, 
            0xBCE70EB167946C10ULL, 0x5EE404BEB6536E63ULL, 0x6C4AF3E34AE05CE9ULL, 0x7B0B4E0B1C2D2C49ULL, 
            0x1F96B58528B20DE6ULL, 0xCA2DBFBFF7BDCE54ULL, 0x2872A508D159E73DULL, 0xC2BC3AF2E9B09005ULL
        },
        {
            0x7E0F4D3FFB193A6FULL, 0x53F33F2B06794E0AULL, 0x5BC39B467B27B978ULL, 0xD24398D61576FEB0ULL, 
            0x4279E2C7B38C88E5ULL, 0x2823E80D1947092EULL, 0xBCF920E6225796F8ULL, 0x8C63586DB0037821ULL, 
            0x8457C203AAD25695ULL, 0x3BF5F1499A8878ABULL, 0x6AD08984F904A718ULL, 0x345D2230C63B81E7ULL, 
            0x9EBF2D1885809F9DULL, 0x6C8CB88AF7F0CC92ULL, 0x44DCBBA961B9EDF3ULL, 0xAED82289D5A61189ULL, 
            0xA86E3099823D442CULL, 0x9627ACDBB59B83CFULL, 0x5D10DCF2E131AF79ULL, 0x64E8F3C2225EA001ULL, 
            0x5A3BFC47E22DAAA2ULL, 0x388C9D8C6ECE7956ULL, 0xBC45A36D20C5E49BULL, 0xEC28C007A5AC6137ULL, 
            0x3661AC0ECC08FB18ULL, 0xFBE2356B78141856ULL, 0x30C913F5CC467C43ULL, 0x3C9C2C9AA2BFB87EULL, 
            0x288833DCE1244360ULL, 0xFF590BDE2B00E0A4ULL, 0x04A22610DD1BA241ULL, 0x406131CB22C84275ULL
        },
        {
            0x1AC0F22C724E187CULL, 0x030C247F50B9EA58ULL, 0x2481BE8B4B3607E6ULL, 0x5346B907A247010DULL, 
            0x236211E66476F2C0ULL, 0x299CAEFCB9105398ULL, 0xCDF81C7DA40D730DULL, 0xF6CFE45592520B09ULL, 
            0xB0D8A76AE464E2D4ULL, 0x4C2A41FF713FFE0BULL, 0x07D4AB0EF85F40DCULL, 0x062A435637AAA058ULL, 
            0x2967A3D6210E5D56ULL, 0x423DFE04DC2DB3DDULL, 0x8A9F1CFAAA01C763ULL, 0x4465958C6441B051ULL, 
            0xE37974BA0E47C87DULL, 0x3D9D074F8B1FBF45ULL, 0x6C802DA497015143ULL, 0x0192F5928D74E035ULL, 
            0x976BD25A106FDEC2ULL, 0xAC76CD2B6A221BC6ULL, 0x1DBA0F5E48FDCFCBULL, 0x4948A3FC82918ABBULL, 
            0x47C43561962D7EC1ULL, 0x49468409A5826123ULL, 0xDBF9CD104EF095C6ULL, 0x5631C67B51FFAB52ULL, 
            0xC1706992A2E8007DULL, 0x4E5C7CFC52B0A5B3ULL, 0x7C9672635607FA17ULL, 0x15237577620034CDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseFConstants = {
    0x250F27757061BBB7ULL,
    0xEC13F59628410A11ULL,
    0x8648335AB06616B0ULL,
    0x250F27757061BBB7ULL,
    0xEC13F59628410A11ULL,
    0x8648335AB06616B0ULL,
    0x4C273317F97DB2F6ULL,
    0x54DC1A509F4C22DEULL,
    0x9A,
    0xFB,
    0x64,
    0xF4,
    0x62,
    0x59,
    0x7D,
    0xCF
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseGSalts = {
    {
        {
            0xA1FC73F6F803603AULL, 0xA765039EFD340D3FULL, 0x70C7D145449521D9ULL, 0xE2DB94E9F220D801ULL, 
            0x575DF67E33473E31ULL, 0xE416CA4AAAAB9E1AULL, 0xDF39E82454C80A03ULL, 0x3DE9A706D0820A51ULL, 
            0x98650EB2EC339D94ULL, 0x28199ED4690B7AA6ULL, 0x1124ADE74F83346BULL, 0x9A65A1AC575520D4ULL, 
            0x289271475C27B77CULL, 0x1329B8B44EE82E62ULL, 0xDE77117A533F4297ULL, 0xD8B2EB136ED016B4ULL, 
            0x3A12159096D19723ULL, 0xC2EEEB5BEBECDDCCULL, 0xF89CEFD0694B8277ULL, 0xBB8EA99FEEFD0325ULL, 
            0x3142082F6D3D044BULL, 0xEBFD74A650A9C230ULL, 0x81906F2E5754C4D0ULL, 0x0F84E54583F8B041ULL, 
            0x1F2AA380EDBF10DFULL, 0x1C6A5C0036FB1545ULL, 0xFE6C860CB335FB10ULL, 0xF56A2E894B72E24DULL, 
            0xC414A1A106009968ULL, 0xEEA23D246CC4A562ULL, 0x40818556FA0D3317ULL, 0xF928CB93BBD31B02ULL
        },
        {
            0x965D7043A1A84799ULL, 0x573BEA8ED85EF952ULL, 0x3AEDD7187F3BA044ULL, 0x2D42BCDE9E439E32ULL, 
            0x5F7680A4B3C4A606ULL, 0x9A611B7ED62E0BDEULL, 0xCB39D6500B65BE48ULL, 0x6789330F0F2CB121ULL, 
            0xD8149D7886F1ED25ULL, 0x6AD9D473FD6697B3ULL, 0xDE1FC4E7DA7305E9ULL, 0x6EDFEFB56793615DULL, 
            0x983651190043E3C3ULL, 0x1868477E13D38BEBULL, 0x272F887D4D0561B2ULL, 0x1809781D3BAE05D2ULL, 
            0xB76A758C8A352BABULL, 0x0015057F037BF538ULL, 0x22A40B2F757D325DULL, 0x572007D36E0B039AULL, 
            0xD2F5590A9FD5E565ULL, 0xE727BB3CC069810BULL, 0xBAEC9B4DC76CA583ULL, 0x1DF57927C5FAA8F1ULL, 
            0x0F89BD6C46C30FB1ULL, 0x3720826F6CD7DD6BULL, 0x581CB0B5987AFEC8ULL, 0x1A298D92C622CD90ULL, 
            0x600397D8F6006B22ULL, 0x89389B9D5196A86BULL, 0x2469441B52CB3C66ULL, 0xE8F939D6AB259978ULL
        },
        {
            0xB2D2D5A65A0258B8ULL, 0x6EA3C7A536832177ULL, 0x1DED470EA75AAB15ULL, 0x603DE4FE9BD10DCEULL, 
            0xA70F5078B9F02438ULL, 0xE09AF5CBCD068F0BULL, 0x3F27E2155BD85C72ULL, 0xDF59743BC387B996ULL, 
            0xAAF4D045454E31C0ULL, 0x92C96B5E5A2DE127ULL, 0xF7246676A675540EULL, 0x88E890D612ED9867ULL, 
            0x59FEF31C405731A2ULL, 0xE90E090255F440B6ULL, 0x52180D7EEE5AB7AEULL, 0x5D42736B4AF33D78ULL, 
            0xA57D75B9A49B3159ULL, 0xB89085C6D23D8862ULL, 0xA1DBE9C4C9D54A10ULL, 0x171531FC21C2F15FULL, 
            0x0D55CE16F1D3EC87ULL, 0x8512955667A1DA07ULL, 0xE35A802578AFDDEFULL, 0xF9E54FC40F096837ULL, 
            0xA34B01EC0BC40FDEULL, 0x0AE90834106EEA97ULL, 0x4BFC0E5609E95794ULL, 0x3260DF1735FCDE36ULL, 
            0x391F1A93C422B05FULL, 0x5E3616B958EE583AULL, 0x4D49E46E89925C70ULL, 0x31B290A89E220C20ULL
        },
        {
            0xA223B2592AA25780ULL, 0x4FFF6A06513ECD7FULL, 0x7503681036C225FCULL, 0xF021E7AAE2DD07ACULL, 
            0xD13BC4F23F3CD19DULL, 0x69352FA228CFC4EDULL, 0x921EE0EFC9DE4D6CULL, 0x87B7094DBE8775A2ULL, 
            0x647C594F5B0A64A7ULL, 0x76EFB660B35627FEULL, 0x933D0FD67BBD763FULL, 0x37EA7CDC92E8A6C8ULL, 
            0xD1137B4595AB4274ULL, 0x6AD90CF1310D9BCCULL, 0x537B905E8C915E48ULL, 0x607D731CA5263F23ULL, 
            0xD0B8438C45EF0AAEULL, 0x87527A841A1A5211ULL, 0xE0580027C1413D59ULL, 0xE4B37FB3BFF0EB9BULL, 
            0x65A155A67ACE8588ULL, 0x82B77043B71CDF44ULL, 0x2B7AA10A7545F65BULL, 0x7558511731E597FFULL, 
            0x0916596C64B762ECULL, 0x5A0876D882460111ULL, 0xD7EA1F94556274DDULL, 0x225583BB6C6E5ED8ULL, 
            0x69ED589AD0E9F6FDULL, 0xD02D1D693D95CA2EULL, 0x79DD194512B7AC00ULL, 0x25C2F26CA5220476ULL
        },
        {
            0x82D51F309DE790CCULL, 0xB36663111760E895ULL, 0x7690E60E76CF225CULL, 0x5C7D2258FA02D39EULL, 
            0x1845C1A8B06CAA5AULL, 0x13AAD80AA54393D5ULL, 0x9326E8F5CAF86666ULL, 0x1F5C3DC71A09ACE4ULL, 
            0xEC7967D47BD36DF5ULL, 0x9596BA33C091980CULL, 0x08E99EDADB7418CAULL, 0xABA438679BC306B4ULL, 
            0x70EE61FEBEEAD2AAULL, 0xB85E50312B3E84B9ULL, 0x113E78BB6D3BBB17ULL, 0x5622347E9D993CB3ULL, 
            0x7EC26FB2BB200422ULL, 0xF40226A214338537ULL, 0x2BC245D308A6D861ULL, 0x55D3FED658494133ULL, 
            0xD7EDE24BC717C845ULL, 0xD4F7E480E73CCAA9ULL, 0x2D07141D0B2B64C9ULL, 0x3A3AC09F939E37E0ULL, 
            0x01B6AFE39569CDD6ULL, 0x5226F4184DCE38D2ULL, 0x4A11AAE52063B7ADULL, 0x010C4CDE8E36B63DULL, 
            0x05C09F4684706716ULL, 0x2E6C50941297ACB3ULL, 0x3D7EC11783EDBA00ULL, 0xEEE58EB3C3C25D74ULL
        },
        {
            0xD668BFFD60B06CFBULL, 0xA8EBA222C2026271ULL, 0xA52E5704C181BE5DULL, 0x57440F890F9955CCULL, 
            0x187FD6833F2B2799ULL, 0x227CBF8ABC27E1E7ULL, 0x44947C97299EB434ULL, 0x12AA566AF797CFD2ULL, 
            0x1705C7E745D822F8ULL, 0x3C54580C9B86ECF9ULL, 0x8514143F70453560ULL, 0xE26F95DD953AFBFEULL, 
            0x732DC3921C4CFFA5ULL, 0x0AE7BF92F33CD0E3ULL, 0x185B31B4CD7C1E10ULL, 0xF0F632805CC0B283ULL, 
            0xC3C286F291B760A3ULL, 0x9239D4F7BEB04C97ULL, 0x9791AE4D0DAC2FC2ULL, 0xAC359849AAB108ABULL, 
            0x91A749BFD4458159ULL, 0xFCEC397970817310ULL, 0xCC7B128537FD3A3AULL, 0xF67193DFC87A9C2EULL, 
            0xC7E3097C127414ECULL, 0x003E08992E412174ULL, 0xAB9AB2530C3F657CULL, 0x7B73A6AB9982C13AULL, 
            0x19B7D8237FD09942ULL, 0xDD67A4415C76F297ULL, 0x5DF71354F6DE8562ULL, 0xEA39E5B611DD7A1CULL
        }
    },
    {
        {
            0x5CE32F4E0000F379ULL, 0x4C54F9CE03E966FAULL, 0x7E8110D62220C766ULL, 0x9320B9D64608FE98ULL, 
            0x9C323F6C662526F4ULL, 0x6BD0570994AC70E0ULL, 0xF8BAD92137BC8A56ULL, 0xCA85F538A4620B3AULL, 
            0x43DC9BEDD08092E3ULL, 0xFCC71740910F5A9DULL, 0xC1C1765AF820F490ULL, 0x973691557E0DD0F3ULL, 
            0x5A7FC579A513B0E3ULL, 0x3DF26817B91BDB0BULL, 0xF64BEE46D1453F99ULL, 0xC376389D45152219ULL, 
            0x0F348326F5C9A234ULL, 0x962CDA47C4C8696EULL, 0xE8F40711C7B36A50ULL, 0xDCFC90C1954C8610ULL, 
            0xB7A7E23DF6C0E0FCULL, 0x02032D6DA151B882ULL, 0xCE0368261978BF8DULL, 0x5A70EB765E6BFD0DULL, 
            0xA81DC7D2CDCBDCD5ULL, 0x0846E965E9AEA767ULL, 0x8026D774BCC4750BULL, 0x421663A25CCCB6F5ULL, 
            0x6BDD5542901F7BECULL, 0xF61B0CD4B04A931AULL, 0x421949F065D5045AULL, 0xED1881F4B127FC6AULL
        },
        {
            0xDCFD6B17A5A07E50ULL, 0x1271FCF1CEA4CD68ULL, 0x8962785EF9D5FA3EULL, 0xC841CA489B577442ULL, 
            0x4BB3B6C37109346EULL, 0xE4A12C877829654FULL, 0xABD5BC846BB5CE9BULL, 0x104A208265FDA2F4ULL, 
            0xBF8C9633E65919B5ULL, 0x94BB55AEFED4CC66ULL, 0x1246B32166A6B16EULL, 0x3891CD62F7D80814ULL, 
            0xAAD859D5F38AAB14ULL, 0x0944411B030BEF12ULL, 0x018D45A44295C682ULL, 0x6B32A6359B00968BULL, 
            0xA7AFFCF6B4323CA5ULL, 0xF984D42EDFB597B8ULL, 0x7A10F9F99ED46D1AULL, 0x35B6BBC60F7ABB23ULL, 
            0x62C18E9DEFA7E0EEULL, 0x5D823BFD21C9E925ULL, 0xD5FF4EB5AA0E0F4BULL, 0x2567B7457F9DE1A1ULL, 
            0x04629CD9D860C542ULL, 0x8AD1EAC354F821B4ULL, 0x7088A983CFFA6EC6ULL, 0xFEAAEE111603A1EDULL, 
            0x3E0006C72346F752ULL, 0x250A1A30DECA6B62ULL, 0x7D3DE722442A119DULL, 0x2B2CEB4B1D961C69ULL
        },
        {
            0x886632886761E601ULL, 0x82F4CECA5D520459ULL, 0x67DA6C860F7BCCBCULL, 0x56097196B56ECB96ULL, 
            0xB8BC536AB8CEB178ULL, 0x61D003A95E75C179ULL, 0x1484D166ADEFA018ULL, 0x7365082C70151AF7ULL, 
            0x693F5C119E9E2914ULL, 0xB33D31C67BAD954EULL, 0x2C799CEF5CACF2D0ULL, 0x79B6A1F85720C9BCULL, 
            0xB5A18265AFC2B007ULL, 0x569B082753D52A84ULL, 0x3019EEFC1B9CE56AULL, 0x7AECCC8B8BFF4D42ULL, 
            0x5CF750837057750CULL, 0x45B4BA1BE71FD4E0ULL, 0x018AB30FE51299CFULL, 0x6DBCB230FA33CF35ULL, 
            0x198EA1FD4783F9CBULL, 0x3BCADE076630E425ULL, 0xB09C6AE315C21CEFULL, 0xF4BEC66E4ACBA8C1ULL, 
            0x9D151D508C3A08DFULL, 0xCFABC8807CA46944ULL, 0xD7A6A8367B6C9E64ULL, 0xD6DA9F8DDB18ED70ULL, 
            0x42446C618C815B24ULL, 0x4BC8ABD46BF9ACF1ULL, 0x789B7EE1639EE3F6ULL, 0x6FCBF3689880F571ULL
        },
        {
            0xDC5724016923E0A4ULL, 0x2D7C3BA12B7EC6A1ULL, 0x659667318A87E8ECULL, 0x7EC2AD6BE6E4D1FFULL, 
            0x5A517073DD68BC9AULL, 0x0F815064BDDE6B3DULL, 0x69414BE3C3E12599ULL, 0x14D8FFC083E17986ULL, 
            0x2A9E22753D3A7A3EULL, 0x5E00D7E61614F408ULL, 0x237A21F9E9C2B94AULL, 0x6312F5BCC164ADB4ULL, 
            0x0EA44A56E7F89F32ULL, 0x4C900D670F42F8C0ULL, 0x9F4788AD25827001ULL, 0x1D145042461AF642ULL, 
            0xBBE29916A84DFEA4ULL, 0x5EBE7D6C662022BFULL, 0xDF400A3BBC118C81ULL, 0xCD6DC95199F9691BULL, 
            0xA9435F2BF0DC9014ULL, 0x171701C8B6CAF585ULL, 0x9CC52B8E0AB3DCA1ULL, 0xE88E3DF720BC3B13ULL, 
            0xEE95FFEF2D5C749AULL, 0x5B2545A3000B0425ULL, 0xAA9C832C363D6F5DULL, 0x82D665B3E4533020ULL, 
            0x9339C08E69ADF3A1ULL, 0x4D07FCE189D7CF67ULL, 0x4F379B7655730D68ULL, 0x375536C2032FBF28ULL
        },
        {
            0xAD95DFF3BA08639EULL, 0x45F54B76657C7B4BULL, 0x384C3FDF904D5910ULL, 0x41FB2BCF61BDBBA1ULL, 
            0xD88BF3A336966C30ULL, 0xE27D00B21E2AFECDULL, 0x890F743C5C6135A6ULL, 0xEBFBB99BF67637D0ULL, 
            0xD9052951766F1FD5ULL, 0x56CE1A61351DF9BDULL, 0x125B1E87344D8C18ULL, 0xE4A3DFFABBE8D88BULL, 
            0x1098137CD9EE52DEULL, 0x394161867F5D9785ULL, 0xE9919E3921CF82D1ULL, 0xEDA04A28D05795EBULL, 
            0x82D4E375B67014F7ULL, 0x856BECB3DD380C7AULL, 0x6D093156AEAF7FD7ULL, 0x95D51F64C28F641BULL, 
            0x525D27A6921E85EAULL, 0x7245D8A1F615142EULL, 0x599FC5D668AF90ABULL, 0x517B3F1A18C65579ULL, 
            0xF251D1AD55A867CBULL, 0xEC0618AD25494982ULL, 0x4166377171627074ULL, 0x04E9CCB0F7ADF4D8ULL, 
            0xE9F1D249E6FB875AULL, 0x315B7028C223CFCEULL, 0x9FCA719651FCFF5CULL, 0x3AFD04A81ED349E0ULL
        },
        {
            0xDC19DDB1DE6C770DULL, 0x62CED473A5CD4FE0ULL, 0x42295B70842B1BB0ULL, 0x4FF6B0A211DEDF20ULL, 
            0x1BA704B60783719BULL, 0x1D0B9956EDD09608ULL, 0x9A21F0AA2A10908DULL, 0x4608165049082C1DULL, 
            0x07FA8F59AD69436CULL, 0xAD3BD248921E0578ULL, 0x3D4FD60B5FCEE14AULL, 0x5386938A171A4B01ULL, 
            0xE37CC201357D4446ULL, 0xA7DB49E20D21F109ULL, 0x375473849DAD4FC4ULL, 0x76573E4E98CEED04ULL, 
            0x92CF0AC2D9C1E732ULL, 0x8E36F450DF4A2F68ULL, 0x2106A833ED27CC32ULL, 0xFCE215365CDF4248ULL, 
            0xB49A20F22DEF499BULL, 0xACF87454921BDDCAULL, 0x71701BDA5D0B0E20ULL, 0xEC4C4BF828ED0B3BULL, 
            0xBB2E147CBF89CA7AULL, 0x846559F0F1E6D537ULL, 0xDB679B8A1FF6D657ULL, 0x0B659AAB1B25D328ULL, 
            0x7050F4A030262F2DULL, 0x187F517BA8A10D2EULL, 0xEC75B34B3FC670CBULL, 0x7C8BBDA403B75647ULL
        }
    },
    {
        {
            0xD3A2C618AADD93E5ULL, 0xFFB544151A78828CULL, 0xAE4D69633328788FULL, 0x5DC0360202B7EC28ULL, 
            0xF84131BBE826BE6EULL, 0x2033E1094CE25887ULL, 0x0FCCA7CD1F509D19ULL, 0xAEF9D4BAC20C86F3ULL, 
            0xB9844D27DAE3AF92ULL, 0x54ACBA6D8BADBF47ULL, 0x3DF4E05C53DDF6BFULL, 0x4420D22DB2B8F46CULL, 
            0xF4446BC2D530693CULL, 0x99BCD976BD493C07ULL, 0x96371D2A7B9B7481ULL, 0x9383C9258B80ECE5ULL, 
            0xCBC449B17E56B3EAULL, 0x85C16415B85ACE90ULL, 0x0E049D143BA7CAE0ULL, 0x6FCF02A8DC844B00ULL, 
            0xC3E9BB5E41707251ULL, 0x12E3F567E9635044ULL, 0xB09888EAB4D6B857ULL, 0x5352DF1256B3457FULL, 
            0x45D4A7B20984D304ULL, 0x35D7D811D0CC5F9BULL, 0x3AFAAC49776FB4F0ULL, 0x3747139C3192C90FULL, 
            0x083697B3E45BD607ULL, 0xC2A85CE18E2B77E6ULL, 0xCE192355D8D8651DULL, 0x78F0340F2B19A5D7ULL
        },
        {
            0x2FF958F04E428D25ULL, 0x07F0A6775CB37663ULL, 0xB78560BF177390E6ULL, 0xA5513CF51FFA6D5CULL, 
            0x56AEB66A6E0BBE91ULL, 0xD7B122D158AC142CULL, 0x5B5ABA0AE8A20AA1ULL, 0x6E8AA999ABFB4319ULL, 
            0x783D3D3A2C1C53EEULL, 0x5498E6C906F70660ULL, 0x2EE02F44AD78F979ULL, 0xAF51E9D8B13133A1ULL, 
            0xBFCEEB3CE5723272ULL, 0x2C23E69E6B3032A4ULL, 0xA2A8AC923386D63CULL, 0x36C1BC1596735061ULL, 
            0x2D59CB44DD5BFF3EULL, 0xF2C73FB71A008EE0ULL, 0x83F62B3E40BC8773ULL, 0x56199282D2D156CDULL, 
            0x42859F798DD04F8BULL, 0x9076139B4BD130CBULL, 0xB9875EE5E6EE6943ULL, 0xF0BFBC5EC75EC326ULL, 
            0x1086F4B08A8EA604ULL, 0x158BF4E852F0137DULL, 0x102CB48F6BC127B5ULL, 0x4F8C2F49EA1AE910ULL, 
            0xF3EB99DF4033167FULL, 0x8661457F4DD49F8AULL, 0xF037B8E672F35D4AULL, 0x8A52D30D5FBABB27ULL
        },
        {
            0x012E952FB6EB663CULL, 0xFDFCBF3B8F065BF5ULL, 0x3BFFBB8D013E5B25ULL, 0x8CBC26689B491CF0ULL, 
            0xC4934EFCE82DE67EULL, 0x19161931664602BDULL, 0x0ED10DDB2F0277CEULL, 0xBFAB0F918978B139ULL, 
            0x9C23C3D7F5D22051ULL, 0xD1B6E35C43E39A6AULL, 0xC78B18BDCB348068ULL, 0x020A0257AB185C8AULL, 
            0xBD092A8EB58C56D3ULL, 0x85528B6595A4B064ULL, 0x0EB77720A2FEA6A3ULL, 0x7DB0E169C4C4E680ULL, 
            0x39360CED7084D2DAULL, 0x5755242701CE8E9CULL, 0xDB4FD0BAD5794A25ULL, 0x225817A2C132A89FULL, 
            0x74253473E655EC1AULL, 0x1ACB29592217E5D6ULL, 0x779CBBB3CCFCE062ULL, 0xB3854C50EE0973EBULL, 
            0x428EF5783CF42ED8ULL, 0x09C243618FF66EB5ULL, 0x4F5EF96EBCD34B82ULL, 0xFD11D96AEF5499E4ULL, 
            0x3FE1FA1CB695D12DULL, 0xE9713FBAADDE14F4ULL, 0x2F760D4377A04F13ULL, 0x704BF29CB8D47218ULL
        },
        {
            0x53F63A053D89BF01ULL, 0x5A912C8D73BB7494ULL, 0x615ACE01F5FE5CDCULL, 0x0F28884825E98540ULL, 
            0xEDA52F4DE2E41F40ULL, 0x3C99E5679316C85EULL, 0x4E8A57A4F44619A7ULL, 0x056612CD001350E7ULL, 
            0xB3E992F100C599DEULL, 0xC9DB404E18128756ULL, 0xAB97DE482ED04267ULL, 0x12BFA39BC3CEB115ULL, 
            0xA8EF8B0F23111179ULL, 0x048639E04A31238AULL, 0x5BCCBE347D34B423ULL, 0x439964120D81D008ULL, 
            0x311C08B638FC516EULL, 0x8ECCFAA038F90243ULL, 0xBEDB34A2132082B8ULL, 0x7325DD74723920C8ULL, 
            0x10A7E335B3679FCDULL, 0x5E2775D5F71BC699ULL, 0xAB81E6A35E9C2826ULL, 0xE1EEE011BD1067C8ULL, 
            0xBB2B751FFA8D0E44ULL, 0xA92934850C472014ULL, 0x365B28BBF921DF06ULL, 0xF30703B86E3C93DBULL, 
            0x3DEC32F2ADF56694ULL, 0xEF44C6F7C2D81179ULL, 0x0AEDBBD56A0508C1ULL, 0x81AACBCD4632AAB9ULL
        },
        {
            0x086F830711643368ULL, 0x64F031BBABD2755EULL, 0x9571E29A83B8BE2FULL, 0x6B4835461CF338B2ULL, 
            0x49C129CE966174C2ULL, 0x40155ABBDEB60F8FULL, 0xFBE92E5BC68E030BULL, 0xCD8848F627C4CD00ULL, 
            0x5742DC6F2103E821ULL, 0x32E6E7A7DD70EAE3ULL, 0xBA03CFC6623A0E49ULL, 0x66C0076DC34B69E3ULL, 
            0xC26EF82AC1A6E7EAULL, 0xEE171F22E72B5C42ULL, 0x5641139FBE93B5A0ULL, 0xFA31D8E9C7E2AF13ULL, 
            0x7135D92EB32A3FC4ULL, 0x6385F24CC97050F2ULL, 0x7B667E2F7B66395AULL, 0x92750875E2CC2BACULL, 
            0x0E0F71C454C3EFA0ULL, 0xED37AF83E5571E1EULL, 0x60E7DD18EB751D4FULL, 0x222FBD847986A4FDULL, 
            0xAE3DF70AB0B87898ULL, 0x02DCD40594A75B02ULL, 0xACC2935C5EC4C4F4ULL, 0xCF7CB36C86B97E19ULL, 
            0x207B1DDC28915E96ULL, 0x121F071569E5F166ULL, 0x6805E63C46B2CBFDULL, 0xD1386B41CBDA9FB0ULL
        },
        {
            0x4FA95915A9366057ULL, 0x4FC5FB4A9CEA0C43ULL, 0xECA8B1616B27C60CULL, 0xC759A63024ECB348ULL, 
            0xB07E802A47EE2BB0ULL, 0x58B6AB7337876E32ULL, 0xC955933C1C005502ULL, 0xD255A05DE3992D18ULL, 
            0x69458749B1D80A05ULL, 0xA9CA9C3FCD333B88ULL, 0xF84F49CF7EBDF8EDULL, 0xD1C5DEFABD1E9691ULL, 
            0x98974B97F7FD002FULL, 0xB1FEB6A111293A2DULL, 0xE3EB7B2A53A8E804ULL, 0xF0EE2924E1057B0BULL, 
            0xDB3FBF1669BD71B9ULL, 0x9B83223F0D4D2F52ULL, 0x28B5202DABB2EF5AULL, 0xED23B13140846CF0ULL, 
            0x68A053C4BE9FD8D9ULL, 0x5C4785DB5C1B38EFULL, 0x97EEC95B758DCC5DULL, 0x0E4A21DD117A7593ULL, 
            0x4FFA6E096C56A7E6ULL, 0x244273C3DD5116CBULL, 0x851120BE7237AFB9ULL, 0xFB1565044FC1CB7CULL, 
            0x590CA6D4BF245610ULL, 0x764EB6E0FE497F78ULL, 0x8965F3C96FAA8EB2ULL, 0xA253C9E8447585AAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseGConstants = {
    0x5C1FD11794B38193ULL,
    0x294477C8311489EAULL,
    0xC54220219298894DULL,
    0x5C1FD11794B38193ULL,
    0x294477C8311489EAULL,
    0xC54220219298894DULL,
    0x1A0B027A5245E9C4ULL,
    0x2B61DE387D737ACAULL,
    0x15,
    0xA7,
    0x9B,
    0xCE,
    0x96,
    0xA4,
    0xBE,
    0x23
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseHSalts = {
    {
        {
            0x6DBD6763C1C584F1ULL, 0xE4F81E2DB81D63D6ULL, 0x165D4EEB487D5BBDULL, 0x196DC1E91E095FA1ULL, 
            0xFA475B5C30E662A0ULL, 0xEA121BE00BF0549BULL, 0x56F16FB8C4F851D9ULL, 0x8B8A79421EEB4D91ULL, 
            0x3AE7981ED899B1DDULL, 0x6E6BB84832B9A879ULL, 0x78CE28664C04ABD3ULL, 0x38F9900CAF4AA781ULL, 
            0x71406FB477BD1653ULL, 0x499057AC74FCF690ULL, 0x8B9DDA6C3FA06616ULL, 0x6AF6024999618CE8ULL, 
            0xAFE1053740863F26ULL, 0x4CB28FE4863B52DCULL, 0x77B0EA8B964BC43BULL, 0xA1EACE1C1F8621EBULL, 
            0xA7F7C3A8619C83E3ULL, 0x30D00822C3313529ULL, 0x66106BBE590161A6ULL, 0xC62C3BF9B5C380A4ULL, 
            0x0A294684CF6EDD82ULL, 0x768330B66F4A62F7ULL, 0x14A4A72D49C03D29ULL, 0xFB467CB91EAF07F5ULL, 
            0x9082B811F722C521ULL, 0x5A7C8BD77B8062EDULL, 0x46DCF407295A406CULL, 0x71C509DED03B2560ULL
        },
        {
            0xC68F69AD8B317FAEULL, 0x7F29965510F006B2ULL, 0xB56E96523B73F5FFULL, 0x88590DA28A5B688CULL, 
            0x14C8FAB3DD0991FAULL, 0xBBBE08F34190DB8DULL, 0x02B97BA8455879ACULL, 0xE72E913975473640ULL, 
            0xA0AB9B8BF23CB48AULL, 0x24A4849CFAA2B17EULL, 0x04DDC66A7756987CULL, 0x8E27EDE9C2BC178FULL, 
            0x1F628A52E1E3E287ULL, 0x1C3473919048767AULL, 0x360D5ABE28C80997ULL, 0x623ECD89B920B6E2ULL, 
            0x02421F07B76138F5ULL, 0xDDD31E8C42DB9E64ULL, 0x7920AC457CEAF671ULL, 0x87D22541AE6EBF11ULL, 
            0xEB4DAFDB302219C2ULL, 0x883BAA63704F1575ULL, 0xD864F868BA70051AULL, 0x4F3013407A84C10DULL, 
            0x71257DF2982EDF26ULL, 0x5CADD3A8AD40503BULL, 0xAA98CD832AA04265ULL, 0x4AFF424331E94DA6ULL, 
            0x738A78C4638D4C7FULL, 0x70FDA439AED8141AULL, 0xB17CB12B80AB0681ULL, 0x79A001821866E494ULL
        },
        {
            0x8E52FFD2CB7F49BDULL, 0xC0A743176BF3DF4AULL, 0xAB3BA0A1903288A5ULL, 0x0699EAA147F4ECE0ULL, 
            0x7EF867B60A7120BAULL, 0xED28ADB864F99356ULL, 0xFED310D84ECAB6EFULL, 0xCB875E331CF720D0ULL, 
            0xB2FBBA40668EEB2CULL, 0x7E5AE63D5D07AB89ULL, 0x107BE400F9958768ULL, 0x2FE23FE90C6D9580ULL, 
            0x1319F63FBBA75F82ULL, 0x80A9489957A8CDB5ULL, 0xE055BFC8CB93707BULL, 0x19A7A3AC59915804ULL, 
            0x87967CB292A240A0ULL, 0x304F7AA8958575A3ULL, 0x99496782D9D18626ULL, 0x65F58FBFB8D20DC4ULL, 
            0xAC4430A12FE8FED3ULL, 0xA29B62DD845EAB39ULL, 0xA4B9846E8254A772ULL, 0x432E27C78C6CADDAULL, 
            0x027C2077CA6D74D0ULL, 0xC93C7B39183EAD8FULL, 0x2F575383857D6BF9ULL, 0x1D72569E5C799CE9ULL, 
            0x79990CC2B3A3689CULL, 0x65ED7B225ABE0D08ULL, 0x7B3E7560CBDF070DULL, 0x1948DE3CF2B70A1DULL
        },
        {
            0x751A5CA642D270A4ULL, 0xF43EA2F82A89F6CDULL, 0x4BE29B41A6D3F9B6ULL, 0xD2820BE662D7DA78ULL, 
            0x27C4B8B447116C11ULL, 0xF997848BD8144039ULL, 0x6FA8C50C9E91D4C0ULL, 0xAFFFF3568A05C795ULL, 
            0xA67C41ACBAF33C7BULL, 0xE8B596AD3129FD52ULL, 0x52BB483F6B09D0D9ULL, 0xAF0FE78EE86AD396ULL, 
            0x0F7799B51CEEEBA9ULL, 0xBE9A62F690B68E7BULL, 0x029A1F6230083E46ULL, 0xE8A653F8A941D0D5ULL, 
            0xDC4BD313FAA4E3AEULL, 0x26AF053A5EEDA7B5ULL, 0x573DC9E4B0ED0326ULL, 0x88E02290C9B6A1BAULL, 
            0xFD980BB721BBE033ULL, 0x61A5B7775FE9A19BULL, 0x52FD8DF5D3A91C68ULL, 0x5E74283C8B88D081ULL, 
            0xD449E8907CF61427ULL, 0x147C2BA86C8CF9C9ULL, 0x4FAB140C9D09F2D3ULL, 0x08542353F0685E4FULL, 
            0x92282AF58FEA6992ULL, 0x7A37E0EE5C60F4E0ULL, 0x43E98B1F230AFF00ULL, 0x0E39D14BFFC6EB91ULL
        },
        {
            0xA8B14AEA54D1A695ULL, 0xA5650ACC7EFFC7BBULL, 0x008DE93449167AF0ULL, 0x23CDD2E65EA29DB7ULL, 
            0xAB010CA2771C667AULL, 0x93CB8A33102B83E5ULL, 0xBA7288F9206DB66BULL, 0x54D3CAD807B27F78ULL, 
            0xB682DDF7257B6E88ULL, 0x3586F9AC214C8DC6ULL, 0x7EB872C9B77F3465ULL, 0x49665D4F9EAF0D4BULL, 
            0x5C0C8C2941C16307ULL, 0xD0DB970788110C2CULL, 0x7D1E42D88D2263B0ULL, 0x9D637231A47F969AULL, 
            0xB7A81EE95A766439ULL, 0x1A25C3C7CE3BBDD0ULL, 0x1C9B23600484FF37ULL, 0x24F3294F83441E40ULL, 
            0xF15F6831EA19A90AULL, 0x81BCFBF3C953FD75ULL, 0x4F199DB4F9A4F677ULL, 0xE83927984B5B5C65ULL, 
            0xBDC6D80980428D22ULL, 0x0E32751D1928D032ULL, 0xC960B89945F06FDFULL, 0x2E31EC9DDBE9F739ULL, 
            0x8954690268F54CF7ULL, 0x32D2D7E9F4CB5E65ULL, 0x4F153AAB15483D9EULL, 0xA80570CD79B56655ULL
        },
        {
            0x5582061BC96CD1A6ULL, 0xEA3ACCC2BC8B47D3ULL, 0x158A941E092CB35BULL, 0x4B4D5A0288E84E7DULL, 
            0x0E668623740E12AFULL, 0xF674CF840E1E4186ULL, 0x960AF316BF993FF7ULL, 0x8ADC3F0F5CF987A5ULL, 
            0x7CABFF48029EEA50ULL, 0xA36917B0BAB0E1C0ULL, 0xB14A508B438BB241ULL, 0x5888ED2DB17B6530ULL, 
            0x0356316F45345E00ULL, 0x979D801D5AC9CD49ULL, 0x6DB73DF377AD21C8ULL, 0x113A9D87FB7A6ADFULL, 
            0xB99A214FE9830FF6ULL, 0xE47C7B2FB12E6510ULL, 0xFF0B2C378DF4D75AULL, 0x26237EAD5F2157ADULL, 
            0x4E3A751120E85416ULL, 0xF66D3C8DE7E86A4AULL, 0xAFADAFA3C0A40AB3ULL, 0xC8B84093DADF8CF4ULL, 
            0xC5370864FBC6F991ULL, 0xDCE84C6B70AF66ECULL, 0xF70C39280B2D65D2ULL, 0x3169CB48A387E978ULL, 
            0x42EE63F6F9AA392FULL, 0x91D1CEFF3ED5F552ULL, 0xEC60AFA9B3252AE8ULL, 0xF6AF7FC8139BC78DULL
        }
    },
    {
        {
            0x11FF41AE3977C0B9ULL, 0x7BF5C76309A8259CULL, 0x9499A96692F32C22ULL, 0x9B1665D699431010ULL, 
            0xC762D5D74B37C699ULL, 0x22FF3CEEA25B0462ULL, 0x70406DDB222A5140ULL, 0xC23EC6791566A89BULL, 
            0x73AC30705F7887FAULL, 0xF2374A42BC46B6C9ULL, 0x5ABF608A8566C2BDULL, 0xE97F49A09DFF0E7AULL, 
            0xEB3E1E46EF7074F7ULL, 0xB25B2ADCA14C232FULL, 0x90B76117535E0EF6ULL, 0x16F59B00B5623E50ULL, 
            0x073C859C7F332A68ULL, 0x8807467030DAB81AULL, 0xD10BF6586196202DULL, 0x4227A39B75A0A686ULL, 
            0x61A218EB2AA8903EULL, 0x99D54E7D8CFB005BULL, 0xE1610EEAE39A0BBDULL, 0xA09A1BB02C9E2D7FULL, 
            0xAD0A7C603B6F80EDULL, 0x0D7E1BA9021E3FE4ULL, 0xD6FBC868D66A4755ULL, 0x13695FC1049DCD2DULL, 
            0xF23F1E0BE91770CBULL, 0x7EC99040D7E15FB3ULL, 0xC2DF64B4AA85D76AULL, 0xF9271BFED52BF6B0ULL
        },
        {
            0xF63E93544C51B9BDULL, 0x721AA4DC6D10142CULL, 0x94DD15EE5F748AA1ULL, 0xC896A12181A82D3AULL, 
            0x6970E2886DB80D85ULL, 0x17F1D5D66CED0D95ULL, 0x82651BF8DC8289D2ULL, 0xE4F995EC884E873BULL, 
            0x2FEFF5C0D4093ECEULL, 0x50A7A7318BD7EF39ULL, 0x82A281812E7F8F46ULL, 0x733DA644FA4D9269ULL, 
            0x1EB94052CE5AAA76ULL, 0x7F5DAC3EBF250292ULL, 0xE3A5B8A217F52C55ULL, 0xBAC4064BD5E75335ULL, 
            0x59FA4FA1DC84DD03ULL, 0xDA4E79C1796A24B6ULL, 0x46E46BB6AD54D024ULL, 0x46899C76D382B80EULL, 
            0x1179FB1F4DAF90A5ULL, 0x4D76988613704696ULL, 0x71E78BBC2FB0C06EULL, 0x6C7A70BF835FDC1EULL, 
            0x98F46F9921538CCBULL, 0x47E3112D2F0A74F1ULL, 0x9D03AD3EE7DB5A00ULL, 0x2A3832C34F2B7FC9ULL, 
            0x6BB376E92CAD2067ULL, 0xA966BE331D5306C8ULL, 0x579BFCD37AA02E8FULL, 0x7664DA1F8FECF53BULL
        },
        {
            0xD09E0E3624ABA08CULL, 0x5FDE4B2723D7DBD3ULL, 0xB8D1CCC1BD89EA14ULL, 0xBD7EED0376BA774AULL, 
            0xC5CDD2EFD861B5F6ULL, 0x4843577AB9C0F881ULL, 0x6B79D2F7C04C83F7ULL, 0x23E25ABA3921EECBULL, 
            0x12DC32C22CD65553ULL, 0x704CE00A02A7F4FAULL, 0x870867551BBF98DDULL, 0xC3510D3EAFB9669AULL, 
            0xB921973490E325EDULL, 0x6443C2B6FD810AB0ULL, 0x744E3CFDD5A6CAFCULL, 0xC198885217869FB1ULL, 
            0xDE88F3B0AB58264AULL, 0xB07B83D8C5B43A58ULL, 0xE244C0EBF7BA87E7ULL, 0x668A68878FB7E2F3ULL, 
            0xE6CF0B7AB9D5BF63ULL, 0xF77DEA570801E33BULL, 0x538E0D5E91213B31ULL, 0x8A0A0978AA8DE751ULL, 
            0xF41E5452023B0FE3ULL, 0xE4E00C391B3FA311ULL, 0x2F9D151499AD420AULL, 0x42CF90C9215498BCULL, 
            0x1E59BFAE72ED3A67ULL, 0x802CCE32661B1D2DULL, 0xA9CEDE5AAC32959EULL, 0x4EFAEBFA321383B4ULL
        },
        {
            0x04F69F378C5C8D6FULL, 0x499E5CC73CDA77D0ULL, 0xF9F29DEA73492787ULL, 0x55ABF0DDF93FB3FCULL, 
            0x3A5510AC5838CF19ULL, 0x5B525FDE50ABCD7DULL, 0x24E15D8D82B47377ULL, 0x00C3BD7E685200ACULL, 
            0xBFD94BD3BE37799EULL, 0xFEF2F98F400F4807ULL, 0x7696E91E30F29D62ULL, 0x50863FDBE04D7DE6ULL, 
            0x0889A22D16298280ULL, 0x2C893589F0C08B46ULL, 0xB95A02E978CDE5F5ULL, 0xA752D0F59AC84CC1ULL, 
            0x23AE038DC849EA10ULL, 0x27C34D70A6CE96A2ULL, 0x452C823ED2C23060ULL, 0x42485B28E02DD6FFULL, 
            0xBD5B4C24FC745153ULL, 0x5065B614F33072C4ULL, 0x3E7B27CFF0E10B59ULL, 0x1A71DD441A5C55C0ULL, 
            0x1DC16A6F272A1459ULL, 0x9394AE228C72E84CULL, 0x352B6BFBAF56A12CULL, 0x9D9F17AEE54CADC6ULL, 
            0x6ED1BE2A025A93F3ULL, 0x0BAF32CD595B0DADULL, 0x2A687FF2FFCB6C19ULL, 0x47AE74D7EA76E925ULL
        },
        {
            0xB22B76F3A89F1C18ULL, 0x6502C4FE4FBF2864ULL, 0x60195CA681F2A2B7ULL, 0x72DA67AE5891FC86ULL, 
            0xC6AE13AD56A30F6EULL, 0x99AD54EB84C8A0E2ULL, 0x010033E0A2373A25ULL, 0x856C82D4D5772702ULL, 
            0xD8F5EFF650EB318BULL, 0x11BAB13CBDD4A208ULL, 0x4B4BEA297801121CULL, 0x1A843E09345F14D8ULL, 
            0xB7A18632238BF249ULL, 0x0630621649094EA0ULL, 0x3178C0C3C8A861D3ULL, 0x53F83252103B8B0BULL, 
            0x81602752CD967320ULL, 0x6551BC1F02010B95ULL, 0xE2B4D82F0485DA47ULL, 0x9B8A10B1488031C4ULL, 
            0x325857D4AC6C3BF8ULL, 0x4FBB4A3A6ADF24B2ULL, 0x850E99424FD80141ULL, 0x7451DD2E23E98A82ULL, 
            0xF0019F12E7EA13C8ULL, 0xF9471864C6C81A9DULL, 0x36F8833650380AB5ULL, 0xA318B862A210D853ULL, 
            0xC68DE4B9F6EDA5FFULL, 0x6EB8A3820C6515E4ULL, 0x0BAC30925A860315ULL, 0xAC8A482D06C9F867ULL
        },
        {
            0xFC31A0023001CD13ULL, 0x5BE02E8142E2EE47ULL, 0x6396650A57A23C75ULL, 0xC550F1DBAC0A41ECULL, 
            0xEDD0EEFBE923C6E3ULL, 0xCE6AE2DBBE2C7D84ULL, 0x990B753210E3E33CULL, 0x804A6D1FD5677A72ULL, 
            0x93D388829DC7296BULL, 0x174EE7917564AD71ULL, 0xDEB3B4C291534FDCULL, 0xEAC74EC5C77A422CULL, 
            0x000D010009DF99B4ULL, 0x119183CE3849D0DFULL, 0xAC15F2A1BDDF7181ULL, 0xA86A55C50C9F59DBULL, 
            0x0BA73FA5D437FBA9ULL, 0x2F509BC879B51068ULL, 0x5E67A000ED312DEDULL, 0x39B6758DBFB9B490ULL, 
            0xFBB0F629C41C685CULL, 0x6F8410A234DA5392ULL, 0x2474C6247D149F4FULL, 0x8106B7D96E4F2E78ULL, 
            0x695A9547A111D878ULL, 0xC25AF9B4DE10E819ULL, 0xEA74945B5C333585ULL, 0xE49A190D5801E1B5ULL, 
            0x80B0F8A8673A1DEAULL, 0x76D435BBC55C7DC7ULL, 0x4420E8A460804CA0ULL, 0x9A34EA771C887390ULL
        }
    },
    {
        {
            0xA118BFAAEDBC7A79ULL, 0x6AE289D42A77F159ULL, 0xABCF83EC0A1583F9ULL, 0xFC2264A8F23B48A6ULL, 
            0xC4EF4C09E99C1D4FULL, 0x825E0DB093F6F4B0ULL, 0x02A91BB0C92AFEC3ULL, 0x8D06EE85A48AC413ULL, 
            0x5A366C41DF393C08ULL, 0xA12B4893BA890870ULL, 0xBAD9A4DAA72D32EAULL, 0x4BC034329F6E8A37ULL, 
            0x29D2157443834C0DULL, 0x63892F78412B3AF9ULL, 0x034E30E300855AF4ULL, 0xA108368445D243E3ULL, 
            0x30300998E7EF771BULL, 0x9C9577431F006CFFULL, 0x43D440E0187A9F1BULL, 0x2AE0705DBB23E1C3ULL, 
            0x4AB50C047577AFCCULL, 0x33AA1AD6102D1E43ULL, 0x5DB9BE2A1668D3B4ULL, 0x25DB22987428385AULL, 
            0xD3C6F8B3930C033EULL, 0x0C09065D2E33C528ULL, 0x7F34334C18DEA153ULL, 0xD0C1EADE43FBB6E6ULL, 
            0x39EC0E39BEA052AFULL, 0x05401F1CCC67BBD8ULL, 0x6CC5CE62239580F3ULL, 0x1A5D65ABFA7DAD07ULL
        },
        {
            0xDF157588830BF4D5ULL, 0xF1721142E9B8608FULL, 0x627F4AF70A1269B3ULL, 0xA0643ACB798D6688ULL, 
            0xC2F52ED7E8467773ULL, 0xDD96BFAC4E048CCEULL, 0xC5BA6CCD788ECD4AULL, 0x8879CEBEFD2E7C10ULL, 
            0x76BCB80BDC7AF7A9ULL, 0xE3EAA994C09BA131ULL, 0xA4D7AFD0785B91E8ULL, 0x5F232B73F825D4A4ULL, 
            0x716EA123EFAAE834ULL, 0xC7E303A2CA07F384ULL, 0xC8E1F58B0865A00EULL, 0x6393AFEB79EEA160ULL, 
            0x7CF9BD03CBA92DFBULL, 0x0CC642AFCD0C0397ULL, 0x3FF6B72865868D93ULL, 0x84A9862E0BB4FA38ULL, 
            0x47528A29C54EC16CULL, 0x61E5B0515E109179ULL, 0xAEC4C39BE062A22EULL, 0x2C3EB60FBEDC434DULL, 
            0x4D0575B5BA290B15ULL, 0xBDA9219029067B40ULL, 0x16D1B72E54697AB1ULL, 0x3EC73F808BB0C620ULL, 
            0x86B97B0CCB7E4C5AULL, 0x8B23866CC567F90FULL, 0x7B5D779A87362595ULL, 0x045B6172340C6EDEULL
        },
        {
            0x036DBF459B877F7BULL, 0xE037B2620941C01CULL, 0x323A67A071D54092ULL, 0x6AD3C53F9B3D3A78ULL, 
            0x8D0026CF7995868BULL, 0x310C54A06AC72568ULL, 0x141DBE7CF4EC2ED2ULL, 0x7F8DB47313DBC315ULL, 
            0x1CB2706C5324D166ULL, 0xB54DC2F72B63A07CULL, 0x81DB2F649E7577A5ULL, 0xB045C774533DC390ULL, 
            0xA8080C0114FB6786ULL, 0x9AC32ED30092CD43ULL, 0xC40C3022F196B796ULL, 0x3223048BD4D53493ULL, 
            0xA360F974A868AEEFULL, 0x5165B8D58677BC0AULL, 0x7D183BF028419EA4ULL, 0x011C181652072230ULL, 
            0x9E136886DF8D912BULL, 0xA1CFDB9AF1D2124FULL, 0x04451F8851858F23ULL, 0x88C3C0AE8CD3A306ULL, 
            0x32E833FB4C90C258ULL, 0x99B1049A990FB0EBULL, 0xF59A0275713E071AULL, 0x5CF81822B6F08B37ULL, 
            0x8E0003CA0F7CDB88ULL, 0x31D055A7E5EE1FFFULL, 0xA1303B5719E446BBULL, 0xCEAD5D72BCF90E78ULL
        },
        {
            0x18F4EA6E304551B7ULL, 0x9E68E2887877DFCDULL, 0xA3F1674F747AB644ULL, 0x3152801D3A6CFA15ULL, 
            0xD8AD39CEB93A5D55ULL, 0x12FA7E55FEF19D75ULL, 0x067F433F5B0C239BULL, 0xFECFBF1ECF24CA84ULL, 
            0xDD45717B750859A4ULL, 0xC5D83C1DF6A88EEFULL, 0x0CCA86A76945507AULL, 0xFCB358AAF195D9C2ULL, 
            0x07B494C96954FACDULL, 0x598B571F1CC514DCULL, 0xE120CCA25C29A354ULL, 0x401A2B1CE1BFC6EBULL, 
            0x092A6B7A5CAD8CE4ULL, 0x4F3B7709FBD454B9ULL, 0xB74DE607D6FF0B2EULL, 0xEEFEC94488C2C00CULL, 
            0x1CC7EA961F2A0ED4ULL, 0x3AE875086327945DULL, 0x90407545C2ECAF6EULL, 0x61F10F36656AD4BDULL, 
            0xEE020C3EAB6002C3ULL, 0x2C3F0F18E377831DULL, 0x63EC10C085E81D15ULL, 0x4D5AA2794403448FULL, 
            0xBC5C0902B9AD8541ULL, 0x41586793390DD6E3ULL, 0xB05077CADD3951CDULL, 0x851DBCD98DCB203AULL
        },
        {
            0xEDFEDB03CB82373AULL, 0x2C4E1C28EA3D0715ULL, 0xD2CE15312A8CAB8FULL, 0x061B8D925E1D7B4CULL, 
            0x72922AADA3233DA6ULL, 0xBCB3CB9596FF0E6CULL, 0x8002F6E7739BEDF3ULL, 0x67883A6DB1731A69ULL, 
            0xD766850EBDA0185AULL, 0x0A69F1FE74B9AB68ULL, 0xB7476C5F77F3235BULL, 0x4CCBF328519C81B6ULL, 
            0x409AC36FBE806D58ULL, 0xFC4BF50D38B0206BULL, 0x8EBF7C36AEA50E70ULL, 0xCE20D8E855F1EDD3ULL, 
            0x4FAB944DEF825419ULL, 0x5A8D7D3441A13968ULL, 0x274676ECDFF79845ULL, 0xF8A102DEB3BCBCF2ULL, 
            0xABFF130377D421AFULL, 0x76099739A0529B89ULL, 0xFFAF12C5CA62BCABULL, 0x76A743E4DB9027C9ULL, 
            0x969499A8A8BFAC88ULL, 0x769B3B3BC6B00E87ULL, 0x706781211F3CC118ULL, 0xC087F1C41E6708EFULL, 
            0xA5BAFAE5FEE13E3FULL, 0xD9B65C51429B4971ULL, 0x247C3474A4A64115ULL, 0x50237CE4532174CBULL
        },
        {
            0xD47DC7BFA240FF42ULL, 0x654E8F3ED8853620ULL, 0x114CAD4720225B30ULL, 0xC0CD18FCAD299C9DULL, 
            0xAAA6D8832A851338ULL, 0x5246B39832C82E77ULL, 0x3D9EACC97DFD0489ULL, 0x610B3CFBE783E595ULL, 
            0x31346420E1E48BECULL, 0xD310A26210FCE157ULL, 0xFCE550D36F891774ULL, 0x80D530866BC59CB2ULL, 
            0xAD37C33D007AEDB1ULL, 0xBBA1A2AAE7DDF19DULL, 0x1CBFEE42CD7613B4ULL, 0x8E18EFE32EFE5417ULL, 
            0x62DE2C12BBC3DB2BULL, 0x1360E6F35C3BA54AULL, 0xDE49BF840FB3612FULL, 0x8AD5537FF1143C90ULL, 
            0x3CA3BD2249E0D7FBULL, 0x1B548FC42D54717CULL, 0x4CDABAF946ABD8D8ULL, 0x5C29831494E42DD7ULL, 
            0xC002756DD5AA6A81ULL, 0xD352CB8480EDE21AULL, 0xABFDA257FB905811ULL, 0x0D55DE205D606A23ULL, 
            0x5F0F2175A4BF7999ULL, 0xF44C901357CD36F7ULL, 0x39B837E331CDEE7BULL, 0xAE57ECFE6113F02FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseHConstants = {
    0x16A5EB6930C28FB5ULL,
    0x1788924634B4C939ULL,
    0x8CA5F2A46A3627C3ULL,
    0x16A5EB6930C28FB5ULL,
    0x1788924634B4C939ULL,
    0x8CA5F2A46A3627C3ULL,
    0xCD0C72B8695C1AACULL,
    0x9470EFB953713E8CULL,
    0x16,
    0x43,
    0x30,
    0x5C,
    0x05,
    0x09,
    0x20,
    0xF3
};

