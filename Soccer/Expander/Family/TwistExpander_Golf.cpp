#include "TwistExpander_Golf.hpp"
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

TwistExpander_Golf::TwistExpander_Golf()
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

void TwistExpander_Golf::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xBB4B6A547F44550AULL; std::uint64_t aIngress = 0x819B91D4E7001027ULL; std::uint64_t aCarry = 0xE0F23F60F2CBCF00ULL;

    std::uint64_t aWandererA = 0x9D2A1C04171E63BAULL; std::uint64_t aWandererB = 0xF15F2E4AF86423E6ULL; std::uint64_t aWandererC = 0xC342F88F09D54138ULL; std::uint64_t aWandererD = 0xE3343EAE83002C75ULL;
    std::uint64_t aWandererE = 0x9EDADA9703706D16ULL; std::uint64_t aWandererF = 0x9FD834BE944C4E35ULL; std::uint64_t aWandererG = 0xA4072EF6461C79E8ULL; std::uint64_t aWandererH = 0xD65FC654DF90C1CAULL;
    std::uint64_t aWandererI = 0xAAC94AC8C8325596ULL; std::uint64_t aWandererJ = 0xC9FFD6A6A9675C1CULL; std::uint64_t aWandererK = 0xE7718EFADA6AFA2CULL;

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
        aPrevious = 17210826391133400083U;
        aCarry = 13334365924374659417U;
        aWandererA = 17019468021797950341U;
        aWandererB = 10156821655727923045U;
        aWandererC = 13264195964757964713U;
        aWandererD = 14183774260622701887U;
        aWandererE = 16677943456117650874U;
        aWandererF = 14337187997575508418U;
        aWandererG = 14856061247490977443U;
        aWandererH = 12075956207621328736U;
        aWandererI = 13945117893585020381U;
        aWandererJ = 12835775659790577562U;
        aWandererK = 12022678105290035759U;
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
    TwistExpander_Golf_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Golf_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Golf_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Golf_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Golf::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xDEFFB6F775087B2CULL; std::uint64_t aIngress = 0xDB00E6DC15CF0F6FULL; std::uint64_t aCarry = 0x8B9DFA9EB63E8612ULL;

    std::uint64_t aWandererA = 0xF7220493AADB8F84ULL; std::uint64_t aWandererB = 0xBC1C52D1E9D0087CULL; std::uint64_t aWandererC = 0xF78B31AE5D17C7B1ULL; std::uint64_t aWandererD = 0x8790D0417CA4B910ULL;
    std::uint64_t aWandererE = 0xF4AE1147E277DF1FULL; std::uint64_t aWandererF = 0xA9C30EFB023F0515ULL; std::uint64_t aWandererG = 0xA17C7A4D374634B4ULL; std::uint64_t aWandererH = 0xE89F3A0DA4E9163BULL;
    std::uint64_t aWandererI = 0x9DF622BA21E0F4F3ULL; std::uint64_t aWandererJ = 0xD773D264F97F8FC1ULL; std::uint64_t aWandererK = 0xBF323E2E09B2C0CCULL;

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
        aPrevious = 11911654379723576457U;
        aCarry = 10505176575322917355U;
        aWandererA = 11850939982123993139U;
        aWandererB = 12871906208980335676U;
        aWandererC = 9950721539861488742U;
        aWandererD = 16173366207186476782U;
        aWandererE = 13818554055283588831U;
        aWandererF = 9931217649999789864U;
        aWandererG = 11050198179601493721U;
        aWandererH = 15689677978284189151U;
        aWandererI = 16604978157014883514U;
        aWandererJ = 13353249507306648199U;
        aWandererK = 13702912883994197639U;
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
    TwistExpander_Golf_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Golf_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Golf_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Golf_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Golf::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8200E4C852053292ULL;
    std::uint64_t aIngress = 0xDE22975E6B69F712ULL;
    std::uint64_t aCarry = 0xA3D9A235EE561C9FULL;

    std::uint64_t aWandererA = 0xE89618CA637DE1D9ULL;
    std::uint64_t aWandererB = 0x80128747B56922A4ULL;
    std::uint64_t aWandererC = 0xFC5741F6BC5AB6AFULL;
    std::uint64_t aWandererD = 0xDC0D5F37445007A8ULL;
    std::uint64_t aWandererE = 0xB1EFA8C1C8E9F108ULL;
    std::uint64_t aWandererF = 0xE84D6E20E891D42CULL;
    std::uint64_t aWandererG = 0x92BB762059F6D1FDULL;
    std::uint64_t aWandererH = 0xB32C0DA96DDFC34EULL;
    std::uint64_t aWandererI = 0xDB1291C8CDE5BA82ULL;
    std::uint64_t aWandererJ = 0xEED78AF83C6CD105ULL;
    std::uint64_t aWandererK = 0x9A6E9E15813FC1AFULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC, 0);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA, 1);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
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
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD, 3);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneB);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA, 5);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB, 6);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD, 7);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    TwistExpander_Golf_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Golf_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Golf_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Golf_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Golf_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Golf_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Golf_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Golf_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Golf_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Golf::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Golf::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x83D55AEE35DD90B7ULL; std::uint64_t aIngress = 0x986890799C70EC54ULL; std::uint64_t aCarry = 0xA19D187AAA7456AAULL;

    std::uint64_t aWandererA = 0xF9CD48D6C5C3E22CULL; std::uint64_t aWandererB = 0x869D03114406D30AULL; std::uint64_t aWandererC = 0xA1C3CB77751D8D02ULL; std::uint64_t aWandererD = 0x88A239DB3A950FD5ULL;
    std::uint64_t aWandererE = 0xA16952F3B4FBA1C5ULL; std::uint64_t aWandererF = 0xA0C4AF658FD9D240ULL; std::uint64_t aWandererG = 0xA943C7F39795B418ULL; std::uint64_t aWandererH = 0xD400CE64CC7B37DAULL;
    std::uint64_t aWandererI = 0xD022A81F93651761ULL; std::uint64_t aWandererJ = 0x9831915E7C038D8AULL; std::uint64_t aWandererK = 0x8DB4FA3E6236BCDDULL;

    // [seed]
    {
        aPrevious = 9861936790914754662U;
        aCarry = 10129010524956657258U;
        aWandererA = 12784595974658006662U;
        aWandererB = 17028479353073513729U;
        aWandererC = 10614738089136074998U;
        aWandererD = 16094171899924667633U;
        aWandererE = 15513766183252506936U;
        aWandererF = 10086275178926869971U;
        aWandererG = 12117298840953009227U;
        aWandererH = 10623288672377472916U;
        aWandererI = 13540712500921248290U;
        aWandererJ = 15426759055871668525U;
        aWandererK = 11506644480683983335U;
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
    TwistExpander_Golf_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Golf_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Golf_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Golf_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Golf_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Golf::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 0, 3 with offsets 2401U, 5190U, 3226U, 2107U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2401U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5190U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3226U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2107U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 3, 2 with offsets 4598U, 2212U, 7922U, 6295U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4598U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2212U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7922U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6295U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 1, 0 with offsets 4700U, 103U, 7027U, 7957U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4700U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 103U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7027U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7957U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 2, 1 with offsets 3829U, 3624U, 6979U, 1461U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3829U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3624U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1461U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 3, 0 with offsets 2012U, 951U, 861U, 1636U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2012U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 951U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 861U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1636U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 0, 2, 1 with offsets 764U, 1961U, 158U, 924U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 764U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 158U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 924U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 2, 3, 0 with offsets 1794U, 1844U, 1048U, 808U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1794U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1844U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1048U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 808U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 0, 2 with offsets 28U, 119U, 0U, 715U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 28U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 119U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 0U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 715U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 392U, 1063U, 59U, 470U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 392U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1063U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 59U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 470U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Golf::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 3, 1 with offsets 4047U, 5649U, 5030U, 7111U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4047U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5649U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5030U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7111U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 1, 3 with offsets 4855U, 5093U, 2689U, 1570U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4855U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5093U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2689U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1570U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 2, 0 with offsets 613U, 5815U, 1832U, 1945U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 613U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5815U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1832U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1945U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 0, 2 with offsets 1204U, 2601U, 838U, 2096U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1204U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2601U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 838U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2096U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 6553U, 632U, 2209U, 3530U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 6553U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 632U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2209U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3530U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1344U, 1249U, 446U, 1194U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1344U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1249U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 446U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1194U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 580U, 411U, 271U, 365U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 580U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 411U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 271U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 365U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1703U, 1237U, 1865U, 601U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1703U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1237U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1865U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 601U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 183U, 997U, 53U, 1643U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 997U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 53U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1643U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 [0..<W_KEY]
        // offsets: 1696U, 1644U, 404U, 245U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1696U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1644U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 404U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 245U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Golf::kPhaseASalts = {
    {
        {
            0x18F2B0296EDB0C72ULL, 0x67F2330B7CC50E53ULL, 0xD35686AF397EA955ULL, 0x3AFD425890D97C21ULL, 
            0x802D4C83D0D37D45ULL, 0x24DB230BB8ECB553ULL, 0xC4FD2FD12AD53703ULL, 0x7F1585B972C12167ULL, 
            0x7912262CC44CAB82ULL, 0xB5C157D344FC0C55ULL, 0xE9ED017C7888A2F6ULL, 0x910163A406096454ULL, 
            0x5ED7BB4202BE00E9ULL, 0xA947DDBC85C248C9ULL, 0xAADADADFE92EEA19ULL, 0x9C2148781C1E5E4EULL, 
            0x5A6C0293F7CB957DULL, 0xD45B66FD41CDAB0BULL, 0xBF7BAA7F6665BE5BULL, 0x89B20C1D8ECFB696ULL, 
            0x443853AFDAAB3587ULL, 0x6E7D5BBA3C5D9EA5ULL, 0xA16C05D129A323C9ULL, 0xEBEC0F1E2A812808ULL, 
            0x6F81CA878F699BAFULL, 0xD25634F225F05BD5ULL, 0xEFD1521292469AB5ULL, 0xFB60F6BA95C2519FULL, 
            0x22B363FA42A474B2ULL, 0x2E8C7D2729212197ULL, 0x1DAB384BC008C783ULL, 0x78CAA89204F510EFULL
        },
        {
            0x92024026022EE453ULL, 0x25F498D867ADC1A8ULL, 0x4A8E03A98D461125ULL, 0x8047F28F1071E4E0ULL, 
            0xC105A7227A01CD73ULL, 0x6D14992799044C7EULL, 0x03F2623F62077C6AULL, 0xDF6990324FECB2F0ULL, 
            0x3E419EFA49035E61ULL, 0x759580479961A11DULL, 0x534E4D9F4D7D916EULL, 0x2B732542B1C13921ULL, 
            0x9C1A2ADC2D7EF3EDULL, 0xF37A0E48599BDC20ULL, 0xF4DD40B98AEF5C46ULL, 0xA5BB962411905CDAULL, 
            0xBD778B03DA1E2EABULL, 0x857A4EC745278462ULL, 0xBB9D6842D9DB866BULL, 0xE7374652A79546C4ULL, 
            0xDF647A559A7488B1ULL, 0x0920D9A37AA3AD0BULL, 0x22010C3B48923C03ULL, 0x4694FD688BFBB09BULL, 
            0x6862BC1856F9C34AULL, 0x3A1DA71832B8FA74ULL, 0x476BBF00D7DDAE5CULL, 0x34F22C80A65263CBULL, 
            0x9D132424DDC93B75ULL, 0xD5111B53D5077C80ULL, 0xD92BA3E51EDE0486ULL, 0x87C1A07AEE8906BFULL
        },
        {
            0xADF81499B153F855ULL, 0xF756CD76EBCBB0E2ULL, 0x4971951AD249C062ULL, 0xFCD7AAD189A55EDCULL, 
            0x828AE4EE80D72842ULL, 0xBFFD0EDB248DA295ULL, 0xAB15AB2E273053CFULL, 0xA2035F8E93A0D308ULL, 
            0xA21CDD5E6DBE9348ULL, 0x854CBB175CFDA1ACULL, 0xC13502BEB989AA22ULL, 0x0D78AAB73D07084FULL, 
            0x857F78EA646C5FB5ULL, 0x793C11E48227384DULL, 0x0A40298AA6B0C1E8ULL, 0xFAB725C1676E86B5ULL, 
            0x449504078EAA635BULL, 0x183CC2A4842406C5ULL, 0xF5C863CD2240B578ULL, 0x591C6430BD753BB1ULL, 
            0xBB13D7F06A1412D3ULL, 0x64BE37FF7812C99DULL, 0xCA5CBF00D9F835B1ULL, 0x7B366B6E1E60586CULL, 
            0xBE51E62624FA5683ULL, 0x82FC5811110AC64EULL, 0x7F7777D83BD4C94EULL, 0x7112E58847ACED87ULL, 
            0x924079FCB5F5755BULL, 0x89A67A71DD599B8FULL, 0xAFB56C9C772578FEULL, 0x5240383BF364A3F0ULL
        },
        {
            0x901BFA9B29EB6091ULL, 0x4DEF666737DC9395ULL, 0x3A2C11EE26536F9DULL, 0xA7CA3E862522EF87ULL, 
            0x10DD5E1459DF30A7ULL, 0xD36AC13A4F001C4CULL, 0x74C9DE6D71953E60ULL, 0x8230BFC5BFDCF47BULL, 
            0x9679B8CD96E8C47FULL, 0xE381194E4EDEFF23ULL, 0xC54571256B85FC02ULL, 0x64ADAD85C93EA4C1ULL, 
            0x9589501C60F4626EULL, 0xB136C9F903B231E8ULL, 0xE063E3166269A8E0ULL, 0x1CE9269E33019C1CULL, 
            0x418F9FA0A6E05EE5ULL, 0x28C50BC0B07CBCA0ULL, 0x9D4CF287A23CE960ULL, 0x2D0BD19CCA576CE5ULL, 
            0xC0C9998049DFA479ULL, 0x39E133E4A4E65294ULL, 0xA0AFC8E178C99A1DULL, 0x15E3538B63536BCFULL, 
            0x2D4553AF19D0001DULL, 0x93ED136737663744ULL, 0x0DDD69F85DEAF2DAULL, 0x5A3E7B1B2CB7D6C3ULL, 
            0x58FCAD1524FEF743ULL, 0x2BC7D87CF64F86F1ULL, 0x983F137F5306249BULL, 0x85E85B8A816E0A1CULL
        },
        {
            0xBD4C2F970ECC59F6ULL, 0x6BD7B1AF6632B018ULL, 0xA6C77C52DD1FAB01ULL, 0x21DFD7FB9A35B97AULL, 
            0x2A73958529CEE9F3ULL, 0x74EFBA773D0906D9ULL, 0x07EC83ADF80AE578ULL, 0x89769C1631C5B834ULL, 
            0xF5EA98C9F4D6BA06ULL, 0x957DF37F57CA48BAULL, 0xCE0F3E9C1B1C891CULL, 0x4508105AAA0CCEC9ULL, 
            0x92011DF2C732A684ULL, 0x36BBAF27ED6F6A8DULL, 0xFDEF8B4100AC86D6ULL, 0x438455CEDAE9CCA6ULL, 
            0x2D352114C8D3B0D5ULL, 0xE140240EFA1F4CFEULL, 0x5F8BDF872068465AULL, 0x1D98394434452D53ULL, 
            0x0C01839144000D88ULL, 0x96E901C40A8FA957ULL, 0xC705E2C7C9EFCE9AULL, 0x00E752C6A5EA819BULL, 
            0xE7BA549F2549E514ULL, 0x82C16FD1574210DDULL, 0x9610E874FA5388C1ULL, 0x6FFDFA2CF55FD83AULL, 
            0x097A8BA626507C7CULL, 0x07A7F7A09BF7961EULL, 0xF6DE35AD0E9461B8ULL, 0x16292F9CFD021F1DULL
        },
        {
            0xDF1B1FC3F27B71CCULL, 0xB25E0C1778AC5330ULL, 0xBF6A31F40C3EB41CULL, 0x1D177D6EC28F91C2ULL, 
            0xAEE3F19979DB06C9ULL, 0xA795448D3CAABDE2ULL, 0xBE4CC7542B4A7EEBULL, 0x77B02151CB96E5C8ULL, 
            0x2F31CCAA3A1B30D5ULL, 0x900DA2900F14164AULL, 0xAC942EF02EB2B366ULL, 0x41FB27E6CF087544ULL, 
            0xE8517FF174C99D26ULL, 0x2E9173023B671D7AULL, 0xB78209F5AF3F47B2ULL, 0x59FAA6A41584B9D6ULL, 
            0x6E942DB0D9620D68ULL, 0x32882683C4AF389AULL, 0x75A04E6F40C83E49ULL, 0x44916F426CE253EEULL, 
            0x5CBE635AF6C43851ULL, 0x2CD2ADD3B5D9DC93ULL, 0xC463E99240633999ULL, 0xA90178667EDEEC84ULL, 
            0x0E5F4B2CAC8C83A0ULL, 0xEAE056F85548D9E3ULL, 0x3BAEE9D9DF057266ULL, 0xBEB7AEC37AB9F8E9ULL, 
            0x02A4BDA31123950AULL, 0x9F621421BF9C7134ULL, 0xBDBBDE935AFB74B4ULL, 0x4A8E906380FEBD62ULL
        }
    },
    {
        {
            0x121EBB3BFF55E135ULL, 0x71EF78A8D14AE7D4ULL, 0x2D22094B6EB2D573ULL, 0x7AE80347600E5455ULL, 
            0xDB5F8900A25AC759ULL, 0x28521D9E6FD3C0B0ULL, 0xDC2FB64DFCC2FB40ULL, 0x264A0AFBA725BABFULL, 
            0xE55E72291BE1CF6BULL, 0xF53A38150C6B03E8ULL, 0x36350880FEDB45EFULL, 0x13D77B70E81D3EF2ULL, 
            0x2D32F03D69C7ECF8ULL, 0x8B14D3781EAE6FACULL, 0xEB13913CE7EA6288ULL, 0x04BC4A9EBC2B91C5ULL, 
            0xF8D03DC2769C034AULL, 0xB23ADF15ECDB2AD5ULL, 0xF1B44775E7C8EA54ULL, 0xFD0B17344F3CF19AULL, 
            0x573CA3AB36FA3C65ULL, 0x93B9B5006FC71454ULL, 0xA1604B6970D133EBULL, 0x848E0FFE2452AE16ULL, 
            0x841AB289203CE0F4ULL, 0x0DD5FD07E5A51424ULL, 0x946D9C4F7FE886B3ULL, 0xEAF267371F7913BBULL, 
            0x15F8FEF6FAF5C432ULL, 0x30A50B0A79040340ULL, 0x0586168B6386106FULL, 0x0E973146CB25D016ULL
        },
        {
            0x90C96A35F936F337ULL, 0xB3C75CC187756DF4ULL, 0x6375BC1FEF9FD8B1ULL, 0x3128E83537139385ULL, 
            0xB851A07D94A946C4ULL, 0x20B3CE4E878B6890ULL, 0xD988F540A7AADED7ULL, 0xE194544A94267DD7ULL, 
            0xF565EA19F0071EE5ULL, 0x31CE3A3E467BAD74ULL, 0x46FD1C0B4C510256ULL, 0x4606EC7ABB1F834DULL, 
            0x2FDDB9F87F098D88ULL, 0xA389E75097053B2AULL, 0xEA20C3E50A4B6E90ULL, 0xD2D914B859AAE37FULL, 
            0x4DBE3612901DCBC7ULL, 0x75E1092228FFFB32ULL, 0x8E7CA8CC02D7F764ULL, 0xC8ECBE995A8EF5D3ULL, 
            0x40DF3E66EB310849ULL, 0xB45809885F62FD72ULL, 0x08C5418BD10ADE3FULL, 0x7BA30E10B0B3A663ULL, 
            0xD10DDD6C1FFD545BULL, 0xCA7CBC49876B21DEULL, 0xE6960C7C3132E799ULL, 0x499954E00ED9F155ULL, 
            0x6BEE7D8A5F4E034FULL, 0x54769BCE123A43DAULL, 0x4F5DF6A46A21F412ULL, 0x06746848D1E61B6CULL
        },
        {
            0xE2929C1A80D8C068ULL, 0xA78A9FB3A46EDD9BULL, 0x69A60D22B697FA5DULL, 0x0190D8EA5DC2BEFEULL, 
            0x636401F5668743A8ULL, 0xD5A3BB5C3AD8FC73ULL, 0xA02BF7CDD569418FULL, 0x32296E9AB9607ABCULL, 
            0x3E756BCB25DF7E21ULL, 0xF7C6352E40A45C8EULL, 0xE94FB4D79266E9CEULL, 0x85A99CF6840D390EULL, 
            0x17DE806C13F03D65ULL, 0x4219893089B0B010ULL, 0x4E6161B29C8A000DULL, 0xBF4C264BF99F35AFULL, 
            0x870C11B74290FDAEULL, 0xA3CF02674E72F1D6ULL, 0xB6309AD9617DDFE2ULL, 0x4325C41FD9114A28ULL, 
            0x6BE97A29BB3C594EULL, 0x4CC06E8DF01BFD02ULL, 0x746CA78AA903D902ULL, 0xFEF2FC8B61F3D14EULL, 
            0x184CA0353AFF10CDULL, 0x6938AFE2A46EBB28ULL, 0x7FC87DCBFB532988ULL, 0x671F54BC907AFA17ULL, 
            0x94E8A018A37E4253ULL, 0xCCA867FC2F7CBE60ULL, 0x8403B6769FF43DF0ULL, 0x931EEB98E74B53BEULL
        },
        {
            0xF0A96B62C145A869ULL, 0x8CD756FB7F5AB48AULL, 0xD8D99D6423219B26ULL, 0x2D63ADF0B159AC55ULL, 
            0x978B7E6926F7BD1CULL, 0x51E8ABB624A9B7B3ULL, 0x989856E2F5CB95C2ULL, 0xC8F4F2446A3278CFULL, 
            0xA0094468EC48816FULL, 0xDE0CACAEC894B684ULL, 0xB10B3FA826020A15ULL, 0x717EB734E2DFE192ULL, 
            0xF72C6C267C5FAFFEULL, 0x4158578EAF8C55F5ULL, 0x81BBD21BCD83F518ULL, 0xE9BAA749C6DCC2B3ULL, 
            0xBE81A1316787994BULL, 0x11811004CE0AEF0DULL, 0x6B8A1BEA9AF4D3F7ULL, 0xA8515FADE74FFE88ULL, 
            0xC1C29AB68404EDD2ULL, 0x1FF40F2FEB5B2B15ULL, 0xE3CC770E7DB1495DULL, 0x78591BEBC9783D94ULL, 
            0x0D42CF4047D2BDCBULL, 0x01329690424CB0C9ULL, 0x9F35F4521E7EA97BULL, 0x332D258A2ADA3357ULL, 
            0x0F545EB56A083166ULL, 0xC1F121270B5B4457ULL, 0x5062A6BA86592B6BULL, 0x18A90634FBD821D4ULL
        },
        {
            0xAB0357DFE5F801A6ULL, 0x818D32F7039CEBADULL, 0x08A29F3DF154AE59ULL, 0x301970D3D8B27E8BULL, 
            0xE55BA97EB04F85CAULL, 0x5AD6765787A964AEULL, 0xEC578FBC01B84468ULL, 0x28826CBEF9356515ULL, 
            0x76C10D516A5DB405ULL, 0x518211EB5ABC4FEFULL, 0x3CD75ABCD7277C94ULL, 0x89A991FDD9DDA852ULL, 
            0x39FDB19861B58518ULL, 0x0A527F90F1D81023ULL, 0xD3A98C68816D8713ULL, 0xAA51EB4B90549C67ULL, 
            0x0C598A664040F81EULL, 0x2232387067E3CA57ULL, 0x63FBFB5932FAC26BULL, 0x7092224C37D0676FULL, 
            0xB40779AD3D19F998ULL, 0xE2F05221C1381321ULL, 0xF1CFC7178C362681ULL, 0x7ECFC333C5477811ULL, 
            0x03DFB554E1BF0E94ULL, 0x8CA5617E4929E590ULL, 0x0B44A0155901658AULL, 0x95B223174DECC125ULL, 
            0x2565F77B6D18BF31ULL, 0x30E9F4CD32B558E9ULL, 0x94A2EFCC33D7BC21ULL, 0xDF5FE853198A5BD5ULL
        },
        {
            0xF62020213333701DULL, 0xB3E255D826188DE0ULL, 0x4C3D77CDE6AFF572ULL, 0x496FF9351EA32F59ULL, 
            0x1F24721FBDE4656BULL, 0xC7A89801C60460B5ULL, 0x3C2E59BA64D87273ULL, 0xA45DB206539253F2ULL, 
            0x6008D8B72241FF9AULL, 0x036C3FDB6CFBA64CULL, 0x210A394B4E9EA7FAULL, 0x2F78CF5303DCFFD6ULL, 
            0xAD3CB0D72CFD03A7ULL, 0xCB974FE2AD52B0E2ULL, 0x12B9FA341231F0F6ULL, 0x846D6DC40BB52F56ULL, 
            0x783F06A8E62BDA26ULL, 0xDEBA5C76A57624B7ULL, 0x30E317B32FD52CABULL, 0xD6F4688943291C5BULL, 
            0xC414F7E039CCA56AULL, 0x54109569E7598C03ULL, 0xF2AC2E93393FA5C8ULL, 0x0B69514117FC7868ULL, 
            0x862E0B60E2FB256FULL, 0x59B2B097A86BEFE4ULL, 0x59152B9F27652285ULL, 0x23DA6ED4DF325D1BULL, 
            0x48A5A069459D1A51ULL, 0xADC1894A32E966A2ULL, 0xE02A6AB672D9597CULL, 0xFFF91A80F1F7AF1BULL
        }
    },
    {
        {
            0x3DC92E85566B402FULL, 0xE5597397C8991AE0ULL, 0x2B99922985A8A090ULL, 0x54272DF5D8178F93ULL, 
            0xCF6000CF5C3649B3ULL, 0xC71B681DDADD4049ULL, 0xCCA61117FDA38434ULL, 0x01C28EE32B03F8A3ULL, 
            0xB2CB42DE70C64A3FULL, 0x5E7C872B44DFB0F9ULL, 0xB283AB20F82DBCECULL, 0xE16B072B459162BFULL, 
            0x7D78D1A747998E40ULL, 0x4C6737F92971FCD7ULL, 0x2FFF0EEA83023520ULL, 0xCD885DEB62B2B819ULL, 
            0x9B2DCD3CC6518951ULL, 0x7590CA31655E8040ULL, 0x18A7F61D421629C8ULL, 0xFD6668ED277B78AFULL, 
            0x1B58FD3BEC38540EULL, 0x072D9577DB93BEB8ULL, 0x72AAECB6E5426E91ULL, 0x192EB499B51DF738ULL, 
            0xDF8D7ADBDF114E1EULL, 0x0D7109F7A9A85C3AULL, 0xDB2FB7245EF2A3D6ULL, 0x889C9022BAA2765AULL, 
            0x25CF6883B5B9A2D7ULL, 0x2AE4257ED5540F2BULL, 0x3A38A176571B35C4ULL, 0xDBBA0DAC5327B46FULL
        },
        {
            0xB428D2DE81DDBBECULL, 0xE63CA2C0C8CD2890ULL, 0x3A774A95E7C9D1E8ULL, 0x6DB7F5FE37F480EAULL, 
            0x213B8168B9E68ADBULL, 0x56996976CA604EA7ULL, 0xD9F71F03D6255A3DULL, 0x219A955055725EDCULL, 
            0x1F407485FA7B2D47ULL, 0x993518BE080AF960ULL, 0xCE72E430887573C0ULL, 0x01A669E44BF72E62ULL, 
            0x4ABAC3759B615687ULL, 0xA41592A41B0E5A8FULL, 0x79F29B3EC54D0B84ULL, 0xE81DA6BB3292F77FULL, 
            0x7C74704AF14714DAULL, 0xD403695903EA5B13ULL, 0x1FE8EC564AA59FADULL, 0x0C8DD3447CEB6D16ULL, 
            0x6BC24B94D706F3D2ULL, 0x9F431DDCDD341D69ULL, 0xF5E6EDC4947FF5D7ULL, 0x1E70262BD46BC854ULL, 
            0x2AAD2F3EE844E880ULL, 0xB6CCF183CB6F3257ULL, 0x1349DFCBC77AACF8ULL, 0x35BDA005AF976E39ULL, 
            0xFEFBC3F4BEB2A9EEULL, 0xBEEAE216181DC723ULL, 0xAA75995F6C60839CULL, 0xF9D65789D6683DEBULL
        },
        {
            0x0D375B06098C1A8FULL, 0x81C5422DCFCFD72CULL, 0x959446A94BF025B8ULL, 0x2F266023B6F8BF4CULL, 
            0x6791A143611AA39BULL, 0x9589520C851F8B3FULL, 0x03F19D4CDC4D3F18ULL, 0x2D02874A6CDB512BULL, 
            0x311F3E746F2D5625ULL, 0x9071C8D09AA7861EULL, 0x4ECF293AFB8B1487ULL, 0xEE5158238E6B2BF1ULL, 
            0x811F1D4CD8D660FBULL, 0x9E4557902F49FCFFULL, 0xE6A1600465831BD3ULL, 0x7BDBF74A6AFC31E7ULL, 
            0xCE4799F7A42296ECULL, 0xFC5CDA5A7C6347DFULL, 0x2452BF98D6FC066EULL, 0xABC90313383AD040ULL, 
            0x38BC645788E7EE44ULL, 0x5EF9D753B504A1ABULL, 0x8BDAD912DB705AD0ULL, 0x61DA72929DC09959ULL, 
            0x72DE0F59F1A05C81ULL, 0xE3BC7418D1E814E6ULL, 0xA6F6C7FBC0E319A4ULL, 0x058E7706A824AECAULL, 
            0x1EAA5A0FC7014D93ULL, 0x790452E08B05E27BULL, 0xA6A63CE3CC279534ULL, 0xE825BADAFCE7A7D7ULL
        },
        {
            0xFBAC9ECE35AA0052ULL, 0xB70CD3EA6A971800ULL, 0x3A7AD680C0572139ULL, 0xBE8B2CB72E9ED5B1ULL, 
            0xB1D5AFE969F0C59AULL, 0x91F2DD9B974BA824ULL, 0x122BAE84BC41AEC4ULL, 0x7F6BDC6BD764BEA0ULL, 
            0xBCBCD9A4BD03564BULL, 0x59E6B4C1BCA1001EULL, 0xA5E6FB098B0A40ABULL, 0x2F9175CA20C14A85ULL, 
            0x9F317A6595F6CFF4ULL, 0x2CE0C2DFD81A7C6EULL, 0x1A7476BBBEC91090ULL, 0x4880F25EDF679AFFULL, 
            0x943B27D2362A0C22ULL, 0xB1C3121558C929F3ULL, 0x35AF08DF718AC35FULL, 0x1A76AFD360F563BBULL, 
            0x007F7C34774379B7ULL, 0x97A4C4996EB8B095ULL, 0x2C216BEC5552433DULL, 0xFA007D8F0A1F7CD4ULL, 
            0xF65F6CBAA7167163ULL, 0x98CB55CCB44A8352ULL, 0x765DA400A90B5A54ULL, 0x2BC77251390DAC3BULL, 
            0xF957F6993F0C60C9ULL, 0x14F3D9FEB360D2DBULL, 0x6D1D9E4070808BD6ULL, 0xA438F352C2470E08ULL
        },
        {
            0x14E4F84BB2B6A527ULL, 0xA7D347C0525F6FBAULL, 0xA03FD711A1FFD359ULL, 0x36E35178BB2B3B2EULL, 
            0x67F143690A2A4B8EULL, 0x340DBAD83A4A7F06ULL, 0xE6750402EB1B2BC1ULL, 0x968C8661C22B0DBAULL, 
            0x488A0230AD632584ULL, 0xE7E641BE8F57B6BDULL, 0xD641D8981A962B48ULL, 0x2899D52D6DA003F9ULL, 
            0xE0B90F0A0A675151ULL, 0x56E9C1B523966A89ULL, 0xF8166C23D56E9FB2ULL, 0x8F14BC77308F9CA7ULL, 
            0xAD453BD45A6D66B9ULL, 0xA51B1B65CE999ABFULL, 0xE3F05007BFFED389ULL, 0xE7665F2C46BD5010ULL, 
            0x74C86AB77CD98DFEULL, 0x673AE946DC7D5721ULL, 0x4560689295895DA1ULL, 0xEEADB4E3CDA1BB17ULL, 
            0x0DAC4486AE307DB3ULL, 0xBDB1B34DE0FBAB87ULL, 0x59552D1E04270314ULL, 0xB9F12BA874771EC2ULL, 
            0x2A8F149FCF41D21AULL, 0x22BC144AA52FE2ABULL, 0x8BA1B4D14FDD821FULL, 0xC28C174BF734A27EULL
        },
        {
            0x1BEE6984FDAA4554ULL, 0x30F202524028CAD3ULL, 0x230E3E2947DF2947ULL, 0x7725F2771C590050ULL, 
            0x45F137DCB9A2B497ULL, 0x1EE03C9D9E479CA4ULL, 0x79179A7F61762ED9ULL, 0x468A663CD04C676EULL, 
            0x350FED1A2798795CULL, 0x0D44EE6E69940D38ULL, 0x273B441D02AAE678ULL, 0x71370E9FFA58F65EULL, 
            0x725F1CB86D2E7F24ULL, 0x1B72FC17FBE16B14ULL, 0x2BF29936DF21D818ULL, 0x314A11BC967FB135ULL, 
            0x58C4E25DD451A99DULL, 0x00D9448E68073926ULL, 0x14D6A8BCBEAD8AF7ULL, 0xB4B986EFC39124CBULL, 
            0x74C2BA7FAD5BEBFEULL, 0xC672BA9DBDF29639ULL, 0x693727F2D6304B3AULL, 0x6FDDB967EB4697BEULL, 
            0x33459BC379A6C3E9ULL, 0x0354F6423E0EF6CDULL, 0x385A5F5F2C9E7327ULL, 0xF4165932ECD2E9ABULL, 
            0x1AF976F975E93C56ULL, 0x4AECF4E7FB0A2C91ULL, 0x8CF16A01B56B0FEDULL, 0xA302CEBC901725B0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseAConstants = {
    0x4E48A0D48EBA47CCULL,
    0x2F061816BBDC4DECULL,
    0xE932A178901B32A7ULL,
    0x4E48A0D48EBA47CCULL,
    0x2F061816BBDC4DECULL,
    0xE932A178901B32A7ULL,
    0x38CD122E098C2F84ULL,
    0xF4D5770FD107B2ECULL,
    0x7C,
    0x69,
    0x53,
    0xA2,
    0xEC,
    0x98,
    0x05,
    0x09
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseBSalts = {
    {
        {
            0xBDABECFBCB423862ULL, 0xA7E20A8FD0F8338DULL, 0x52B3F780806E8BCDULL, 0x8F099AE8BF09D593ULL, 
            0x12430CD1BF7E9847ULL, 0x54983B3F4789E3AFULL, 0x699B52738752447AULL, 0x0A351FDE132750DBULL, 
            0x7E71409E66229CC9ULL, 0x1D75C0654843AD39ULL, 0x16D93C3F5802EBE4ULL, 0xBDC472F5A144B8A4ULL, 
            0x8ACD35192CFCDB99ULL, 0x61E68C66C45C3C82ULL, 0xAFECBF69F1F25C2FULL, 0xF0DB202191F511E5ULL, 
            0x09BD78B28133E7EFULL, 0xB422B158DE8AB1C6ULL, 0x4A8E27EE8BC13B2EULL, 0xC34005B131C75232ULL, 
            0x344305DFEB432417ULL, 0x24995FA6186E201CULL, 0x65DD64677C34C211ULL, 0x73A71BF763448E65ULL, 
            0x8BA458EE645985A8ULL, 0xB0DA5ED49E88F290ULL, 0xEC8561423F5D3D43ULL, 0x0E3052786ACF9A3AULL, 
            0x830F75CD161AEFEDULL, 0x6CCA0D3A1A8C0225ULL, 0x797CD0B30B18B9D3ULL, 0x58DA726CAFDE22C8ULL
        },
        {
            0x03D8C66B8CF04486ULL, 0x46A1416A87705525ULL, 0x7094E865CFE26AB2ULL, 0x5541687F4E8F9E93ULL, 
            0x3D2FA650EBB1D40DULL, 0x26603C7C6F9C4379ULL, 0xFE1D6F5B511F2EB0ULL, 0xB1D4996789DB9BA4ULL, 
            0x743E455D2A4FA118ULL, 0xAF00A8F651638DB3ULL, 0x6D276FAF924C5891ULL, 0xED635859493FBEFFULL, 
            0x57827DA868D6BF51ULL, 0x3DB7B4D7B0722288ULL, 0x34C4B63061628B0CULL, 0xDF0A4F98A0E12A63ULL, 
            0x8AD8DACFB828F168ULL, 0xB7F16B6082540B14ULL, 0xA46E0D2ADFBC8246ULL, 0xA3D31E7A2EC0414FULL, 
            0x97FCB1397152C193ULL, 0x401FE8AB25B13C37ULL, 0xE7D99FC71E7A2FEEULL, 0xCC4810E8315190E4ULL, 
            0x56065BBC811FFEB8ULL, 0xEB18C6D9A22FAD09ULL, 0x95EF6F3F91F4779DULL, 0xE2A9C96B33DAD304ULL, 
            0xDCBDB237A1912317ULL, 0xD75210AD98348E6BULL, 0xD5BCCE629FA492C2ULL, 0x35DC8BB6C3AC21C9ULL
        },
        {
            0x9763A823A528CD67ULL, 0x9A46835FE3FD3DEFULL, 0x1853024E5D4F2A9DULL, 0x604EBD71C1407033ULL, 
            0x52F0B1E1C62F723DULL, 0xE8FA267512BF9DF2ULL, 0xC3E4C4E9B2A76A19ULL, 0x1594474AF83B9B22ULL, 
            0x5850ED2DAC1299DAULL, 0x037C2F2238E9A211ULL, 0x9233AAEE7BCC837BULL, 0xA031338B47B609A9ULL, 
            0x11F26D946C69B97AULL, 0xADD1889CA5E200ADULL, 0x84D772D4EAFF3382ULL, 0x6CB58D69F8C60DB0ULL, 
            0xCB7DC208FE346F11ULL, 0xF915AAC710131E06ULL, 0x7C6CC8B5E2B8AA74ULL, 0x6885C8E3510DDB9AULL, 
            0x38D6925F77C15C48ULL, 0xC2A6299A9B4C0B3FULL, 0x559832CA3CBAAD71ULL, 0xE4830CBF44F6B3AFULL, 
            0x5F068807CEEC9DCBULL, 0x7856A5B3E148DDAFULL, 0x7E8F21DA7C9AF0EEULL, 0x4191E7808CE211A2ULL, 
            0x19C19053DEBF12CFULL, 0x9E7A57C3B1EA7880ULL, 0x48D963C111578D88ULL, 0x35AC71C45AAAC7B1ULL
        },
        {
            0x7F95D55F076F8B18ULL, 0xC1B1702D49E813F0ULL, 0x8506B0783E83C63CULL, 0x6AFE606CFBBCEE37ULL, 
            0xF216D92A27E8ACBBULL, 0x771A44C2E4C25DB4ULL, 0x9C41916A246B7CD6ULL, 0xC02332E4E7965B59ULL, 
            0x2D326F67CA25F301ULL, 0x5C36D3A982FC8355ULL, 0xCBC63F04BEEE11C6ULL, 0xACA3D3F393E69EFAULL, 
            0x5531036CB41B7EF2ULL, 0x2F7651CC86C45969ULL, 0x34F92611AAA6FC35ULL, 0xF8D302FECA776DEFULL, 
            0x7DB085C702BA2139ULL, 0x206C073989046B44ULL, 0x96EF76469A3CC159ULL, 0x421BEF532DC83CB9ULL, 
            0x4F2B14E79ED7FA83ULL, 0x82CEFF4257DCBBDEULL, 0x250DABEE6EFFC4C4ULL, 0x2F1176A2F3E888BCULL, 
            0x83A7A35A0CF71BCFULL, 0x0A0301067698B861ULL, 0x6C7EA310D5C2674CULL, 0x4DC189CA28B2C389ULL, 
            0x5DB4EEDBCE4F6C7DULL, 0xD09AD8FE25651FD9ULL, 0x5D66FD3A4AA7D564ULL, 0xE7D9CD038093CC56ULL
        },
        {
            0x4980A113FC106134ULL, 0xECDE075A22DF86C2ULL, 0xF192D1722CF63811ULL, 0xED015E999459BBB8ULL, 
            0xF2757F66649E15C4ULL, 0x200FE7C05B26A41DULL, 0xC5C03A96AEA934D5ULL, 0xB1CE4BBB59FCAE8EULL, 
            0x69EB6A3BE005A8D3ULL, 0x97C51484DACE1E71ULL, 0x6BB957138D30DC82ULL, 0x3EEE6D07A68D1DD0ULL, 
            0x4D47E4BC10CF4F6FULL, 0x2EA3C729468BD121ULL, 0x33ECB2D10C083043ULL, 0x8DFDF24507C94F9BULL, 
            0x77E0C1956F3BEC36ULL, 0xD279DBBB5A9AD1E7ULL, 0xADE1F201E23EF097ULL, 0x0C6B6ADC168D77D1ULL, 
            0x99CE763561965A51ULL, 0x3EA33687AC04BECBULL, 0x2664BE591639C35BULL, 0x0F68BA042FEBE048ULL, 
            0xF75D4A68EC412C95ULL, 0x92D3B54688CB1447ULL, 0xC1415B700B19DEE9ULL, 0xE04126B1B1C2C2AFULL, 
            0x859EF86B858D4528ULL, 0x8A1914930C9C2257ULL, 0x6324093A83BA49C9ULL, 0xAB3E1835D1A7E836ULL
        },
        {
            0xB8ABFF1A130F96FFULL, 0x9AE33DB2BAFFE103ULL, 0x7565B58CD6C454B8ULL, 0x70DDAB527BF7957CULL, 
            0xAB006479C4D1350BULL, 0x0590F351C95D6C8FULL, 0x53886F27A97F01C0ULL, 0xB2437A2CCA5B434EULL, 
            0x10C0BB569A311421ULL, 0x12850D16A732A112ULL, 0xADFE96AEB8098A5CULL, 0x297A36D0BB2988BEULL, 
            0x8D2A96D82B7B7BF5ULL, 0xD25D6B7E336C3E76ULL, 0x283429FF6EEB1994ULL, 0x6B9D3DACEEB6564FULL, 
            0x66DB8E21FC6064FFULL, 0x074D3F599A946B5DULL, 0x50B08872D5B758C7ULL, 0x1386B5388A3614FFULL, 
            0xBE70645A4EEF7843ULL, 0x8EDAFD55B0B1698BULL, 0xED8919F3928FF181ULL, 0x10A38EAFF5C5120CULL, 
            0x76A23CA44A16CC4AULL, 0xAC6461FC55AF8CFDULL, 0x3A0C2D51669AADD8ULL, 0xECAE809B5F1F523AULL, 
            0x0C2ECC94A09AD5A9ULL, 0x7DE8CCB1BE7AE642ULL, 0x3192E9060D927E89ULL, 0xCE5A256B790C65C0ULL
        }
    },
    {
        {
            0x4920A0527D63975BULL, 0x243A023F5127AF1BULL, 0x1965C8B790336FBFULL, 0xF850A4C353BED6F8ULL, 
            0x6724D750C4E9B221ULL, 0xAC6CB48D889862F3ULL, 0xE06AC659584BF50CULL, 0x6599BA546D6D5289ULL, 
            0x54361F04CE145A21ULL, 0xE6D556D8EC07B52DULL, 0xD14C396936E006A0ULL, 0xDE9C246E3353ABC8ULL, 
            0x9CCD68A89D3C4201ULL, 0x33F862B9EC0380A5ULL, 0x0FE18E77FD2D6ED0ULL, 0xF5161CBE6E4DB4BFULL, 
            0x4F1AE7C75BE9F952ULL, 0x678FE43523DB7916ULL, 0x60FABEE059423F70ULL, 0xB2D50299802DB256ULL, 
            0xB3D75455A9D8FE7CULL, 0x90C319CE90B4C2E3ULL, 0x4C954F3BA7A10FCFULL, 0x28542EB84819215EULL, 
            0x83089DEA946A9050ULL, 0x2C820069867C4AE9ULL, 0xC1A300072CB9A67DULL, 0xFCDEC7C09401F532ULL, 
            0x4D2CC103BC7E5491ULL, 0xDBD3A5EB363D8D34ULL, 0x19BD65872F27CF3FULL, 0x3B09B7C754500013ULL
        },
        {
            0x08BFED393D132304ULL, 0xFD97FC99EAAD8FB4ULL, 0x4AEE79BDEA0F1433ULL, 0xA4F1DACDDA27F5CFULL, 
            0x012D36196282EF67ULL, 0x28048E7153A98AA8ULL, 0x5A45B42247C1227BULL, 0x8442588346476874ULL, 
            0x9BB5740A55BF63C7ULL, 0xD7BB3361C65048E1ULL, 0xC8D7D5C9A8F9AD1BULL, 0xD0E634366E283C42ULL, 
            0xEF0F1336E4D547DEULL, 0xB5D39FC0E5CFADE6ULL, 0x979EFC153D573900ULL, 0x043BE5D29FF20861ULL, 
            0xBB3D234CB076C6DAULL, 0xE70AA5C4ED3691C7ULL, 0xD38C1635D6D53395ULL, 0x9DFFDCF88C35FECBULL, 
            0xE2F8EF647801CE24ULL, 0xF5B1599DA591CFCCULL, 0xFCD02986D369DD8CULL, 0x9844CF69230D53D9ULL, 
            0x58440E7E0B1836ABULL, 0x775A6C621B1152D1ULL, 0x146594EC216FE960ULL, 0x2AEE7A9EE0797F3CULL, 
            0x14C38E5BF5DDD433ULL, 0xA13DEC1F536B9320ULL, 0x604CA15027ABC3B9ULL, 0x74231261B5109FA4ULL
        },
        {
            0x70574B509270DD24ULL, 0xA949BD8F89446933ULL, 0x69600DD0D7698F28ULL, 0xC620035C1799D452ULL, 
            0x47600F09279B778DULL, 0xC41847DD1B277785ULL, 0x8DC61642E07C3D02ULL, 0xD5C63DB224CEBAECULL, 
            0xCF0DC4FBB85D73BDULL, 0x4FFC6E2B40B6FBDAULL, 0x7CC62C33AF2031F4ULL, 0x40911398BD623A53ULL, 
            0x89065919674EC871ULL, 0xA2E1257FD4C6C95FULL, 0x236D843721AE634BULL, 0x62D5B7F3CCAA320AULL, 
            0x37762258B6489491ULL, 0x7F064F7C61CE54A9ULL, 0xAF0EB1CA80300E16ULL, 0xCAC66325A1B3C3D3ULL, 
            0x7FED9C76CB77E258ULL, 0xB57D20428B09F247ULL, 0x9DF53125A335D879ULL, 0x8ECC90D02643D99DULL, 
            0x8F242DA2DEA63768ULL, 0x1B41F637F1145606ULL, 0x9ACD0024BE0F654DULL, 0xD2EDE809C998A445ULL, 
            0x163D5F30D7C6F2FEULL, 0x510759F7C33643A1ULL, 0x234DC1E844C42AA4ULL, 0xA7101A5F04F29399ULL
        },
        {
            0xFDDBD31DE5BEAFF4ULL, 0x8FEEE73F6F0F4BA1ULL, 0x0A721BEC1609D7EEULL, 0xF035CC0E559E35A0ULL, 
            0x834FF1646ADDD20DULL, 0x11A6CD121572DEC8ULL, 0x81BFB6A2B282C694ULL, 0x993534BF3FF74463ULL, 
            0x79DB693C15D76F76ULL, 0x55EFB6C246753BDDULL, 0x79FCC0F1D4F9A0F3ULL, 0x2C73BDF608C6C65AULL, 
            0xB25CF7067738E2F1ULL, 0x465CB3CCAEC2A6FDULL, 0x89DEAA8F6F196F7BULL, 0xBD311844C80654D0ULL, 
            0x87D7E5C2C326A151ULL, 0xE9DCC792C60B77AAULL, 0x0236CEC22DF2EC6BULL, 0xF4671794E4A2303AULL, 
            0xF77534D3ECED35D5ULL, 0x8A225C047127CFC8ULL, 0x69629D86F50DF848ULL, 0xAC5232E5890D47B2ULL, 
            0x111C0B3F25A48EFBULL, 0x0A0581244D8E8537ULL, 0x2CE71A03B203A2A6ULL, 0xECEF18844BA1DC11ULL, 
            0x31FCAB52E401FFE9ULL, 0x1AD86723A8FEE2A6ULL, 0xB73AB032DBDB47E1ULL, 0xD4E6E2766936D600ULL
        },
        {
            0x738F56721A6BC8E3ULL, 0xD7982DEDF69AC3BFULL, 0xDCE03DACFA688F89ULL, 0x34AAA93783E5E106ULL, 
            0x78CA6E45626DED2CULL, 0xA2F409DBF91F7A5AULL, 0x0C12BD86F07B6DD9ULL, 0x214F1DE8C4F1BF4CULL, 
            0xEAB7A9054E0CC341ULL, 0x7753DCBBE7FB4956ULL, 0x5110CE68E0C95502ULL, 0x7626B2A95D25CF53ULL, 
            0x5FD15907923A64DBULL, 0x1D955BC0952B4E2EULL, 0xA3F40B33FB32680BULL, 0x28CED3856814961DULL, 
            0xFE711D5D0B8A81BBULL, 0x4F4DEBB01BFF3448ULL, 0x64901970894D2DF9ULL, 0x6489A84B83ADEAF6ULL, 
            0x6C1E8792640A1F1DULL, 0x45F81C9EC6A33FBEULL, 0x004AA682D9C0946FULL, 0xD9912D2D38EA41A7ULL, 
            0x745E8C9DCFC434D3ULL, 0x47E7C60F7A142AC6ULL, 0x7E67F6FC4D6EAF61ULL, 0x44E92B98D50C026CULL, 
            0xC1767F691A26BC08ULL, 0xA6ECE4B82E90F112ULL, 0x3F4DD4449835E341ULL, 0x072CF5938B56C8D9ULL
        },
        {
            0xFC2B0B5B42E28F40ULL, 0xA43900E57AD0F283ULL, 0x1FA6944A01E84A36ULL, 0x2324EF0CE7986814ULL, 
            0x988F13DD8340983BULL, 0xC4556352F5495E09ULL, 0x199E2D2CCBF78EB6ULL, 0x1FBE7FD870D239A9ULL, 
            0xC2887BC109E9B25CULL, 0x898DDC2439117DFCULL, 0xD6254AF5C2C178F5ULL, 0x0DF6987FE33D6D8DULL, 
            0x4089DBB34EED2AB8ULL, 0xFFC1A5DC16A75175ULL, 0x8B8E3354424519E2ULL, 0xC0B2E0E1AB9F9DDCULL, 
            0x4D0C13C6A5927D6EULL, 0x89DE2B6F0D20D6F1ULL, 0x746FEBECE9612149ULL, 0xD57561F69CA0E6E9ULL, 
            0xA1D3972C3CD8B1EBULL, 0xB35A24D75CDC968AULL, 0x2DBA1E63D5BCE5A0ULL, 0x16D5F696BE6B222DULL, 
            0x8093077E81B0185AULL, 0xD5AB3B99D3648510ULL, 0xFA9AD59F89B21F27ULL, 0x1D9E2345024472C4ULL, 
            0xDE693C2006A6664AULL, 0x2FE65984D6DB6556ULL, 0x9748C77897AF9BF3ULL, 0xC5D9D92A1C18048CULL
        }
    },
    {
        {
            0x1D68BDC172531AF3ULL, 0x845B21B56EB474E5ULL, 0x5F08A1082479CD27ULL, 0xAC6F1843B0C72EA5ULL, 
            0x1D274508CC014B5DULL, 0xA27C661C713AF83FULL, 0xB9E7BD114337EC31ULL, 0xAAA59C48A7363A2BULL, 
            0xDCA7872D4F284A87ULL, 0x417C1825F6B00D6AULL, 0x320D46EC6CB2D115ULL, 0xF986B897B63BE06CULL, 
            0xF8AB47C0EFBD8811ULL, 0x028301C853A3AA11ULL, 0x5832961C60D16657ULL, 0xEA8B6242C02060EFULL, 
            0xBCBE285E69B5BB39ULL, 0xA1222160949A6948ULL, 0x48E4473819379586ULL, 0xFF72AB95D8B43A38ULL, 
            0x877526AA4759DCA6ULL, 0xE7462F113B840B9DULL, 0x3FB0FFD4166A753CULL, 0x1A44EA36141FB48EULL, 
            0x31D908E73E183E3CULL, 0x2174FF74D1A07175ULL, 0x31DC090AADA81EC0ULL, 0xD7640000B2FC2869ULL, 
            0x8EB54550FD6A84ACULL, 0xE40CF800AA044B5EULL, 0x9AEFD9B9C62CD400ULL, 0x106AF553F5C0776FULL
        },
        {
            0xFAB50C2640D8981FULL, 0x3C6F84842167B5ADULL, 0x74E49672CA6F7182ULL, 0x0471ABFABCCD3C0DULL, 
            0x910A5BCAD818B532ULL, 0xC533A5662BD48492ULL, 0x8BBB8D4BA94C365AULL, 0xB8566004B9CFE086ULL, 
            0x92DB8F29EDE95597ULL, 0xFB9F0288222D2743ULL, 0xE43B22CD02CC8217ULL, 0x7E3C50DE7DFAED8CULL, 
            0x29DBCC3225943A2BULL, 0xA9A8EA0D9D4ADAE1ULL, 0x49E5FD520AD1E2B0ULL, 0x5CBB0C6034D78701ULL, 
            0xDA88E9B4B495565BULL, 0xF64963EE60CAD32DULL, 0x2A754AA23E1A0BECULL, 0x287442AA657CEFB8ULL, 
            0x97B2E45FA24FF04BULL, 0x4BC06D9612941066ULL, 0x821D720E9F46A823ULL, 0x624D92903493E8EBULL, 
            0x9F628F4D5432AD25ULL, 0x03A70EACE6FD3CFEULL, 0x36669EA4B2282257ULL, 0xF3EC565939D48550ULL, 
            0x354AE1D912CAA812ULL, 0xB080244852A97E31ULL, 0x97558F0A5ACB1666ULL, 0x5ED220ACF46AB3E3ULL
        },
        {
            0xBB19A74DC385ED3AULL, 0xC945B1D0ED7F4957ULL, 0x48E0708A0C25AF3CULL, 0x1DC21885A230AF88ULL, 
            0x0C2F77FE52782C17ULL, 0xEA92BC355F8DE4D9ULL, 0x3713FA1A68C2C9F1ULL, 0xC9E45D0299798B52ULL, 
            0x547B51F4E7FBA51DULL, 0xD4FF90705A70EEBEULL, 0x8364F1EA83D4A389ULL, 0xEB00330216312473ULL, 
            0xE5665CA2578BCAADULL, 0x93D0241054B063CEULL, 0x9038C2A2378BC82BULL, 0xCBA8A61F1DEC3008ULL, 
            0x23411F940ED6073CULL, 0x079EBDD15299E360ULL, 0xA75CAE5AA6D433D4ULL, 0x6138F911CA9FCF5FULL, 
            0x7BCC36173450DADDULL, 0x0446D3ED038C0B11ULL, 0x7CFD6E10905C6A0CULL, 0xBA2CE6348A5DA0E7ULL, 
            0xADA59210F377DDA4ULL, 0x54E5529CD3EA073FULL, 0xAEE33B84EFBAEC2CULL, 0xF072C8478CF89F7FULL, 
            0xA7EF296D2DB795ECULL, 0x9E043DB8D621C54BULL, 0x1A2F7CF21C732F91ULL, 0x60A2CDFD33B7CD1FULL
        },
        {
            0x91489D012C100630ULL, 0xD6861AFD9F3DDCEBULL, 0x90B88AF11D4A5A78ULL, 0x54A1BCA256DA76D4ULL, 
            0x04F7FC853636F894ULL, 0xD5C8D0B323D33DF2ULL, 0xA0BAAA63A945124DULL, 0x420944E4ABD4EEA5ULL, 
            0x15ED17DF56499CFDULL, 0xF164C297B5A81BBAULL, 0xBCFD90C96654185EULL, 0x6E2FB2C540EB0E81ULL, 
            0x6716F0D20A22FA39ULL, 0x347BA53D9AB5B18AULL, 0x56122F977C79F5CCULL, 0xBE01CAF739C846C9ULL, 
            0x6D52F08737D61851ULL, 0x38D5E7A152999340ULL, 0xCA86A70FAA094CD7ULL, 0xA5DED0D1B27CC35BULL, 
            0x2BD6BE8430EA2A39ULL, 0x6C9EAF50CF73ECEAULL, 0x8ABBC5CC34C0E6DEULL, 0x5F029BB84497D878ULL, 
            0x99286308DF70D2A1ULL, 0x893FDBAB50F681ADULL, 0xF9BF98309936BC11ULL, 0x62ED3EBB029AB67AULL, 
            0x0F9312A12902588AULL, 0x468D8BC1673329D9ULL, 0x433F4E35AB9A2D8BULL, 0x46608BF027AE5D55ULL
        },
        {
            0x924DDB2D171AC2D1ULL, 0x686F1B7A9D455216ULL, 0x514FA4DDFF2402FEULL, 0xCB1E5B748A737E87ULL, 
            0xDBDC39AAACE49D0AULL, 0xFF3EB522E5D75419ULL, 0xCBAA575758D520B1ULL, 0xA26E88714965DE0BULL, 
            0xF88104AFED6F9B39ULL, 0x6BE20E103EC47E2AULL, 0xF0B9BA6A2E0CEDE4ULL, 0xC859268AF420151BULL, 
            0xF64FC5E5C718F5B7ULL, 0x24FF3C5B1FD23675ULL, 0x9D874CB7C1AE4617ULL, 0x767D206BEAB3348FULL, 
            0xD3FB576396012403ULL, 0x18E0C9E2BEBC10A9ULL, 0x3FA2F4C2ADDFA018ULL, 0x3AEFDFB5CED02FBDULL, 
            0xF38682B7DFFC47F6ULL, 0x16ED40A70C308BADULL, 0xC30BA377E52E1FA0ULL, 0xE52DBA9F73E1A22BULL, 
            0xF83AD1A39E18CF63ULL, 0x29D82D0187BAB159ULL, 0xA5B8B769405D5D95ULL, 0x2912B808E4261409ULL, 
            0x1CDDCBFD6E806B66ULL, 0x5C04D760D330E330ULL, 0x3F278D201C8FC72EULL, 0xB3DB3622BCD6788DULL
        },
        {
            0xB0924BCF0F75CCDEULL, 0x582474ED12F65915ULL, 0x5A2EAA4F22675DA6ULL, 0x58EFF73879E166A9ULL, 
            0x61D1BD642C84051BULL, 0x13FCA0402FA29299ULL, 0x0D69DAC882969E88ULL, 0xAD2DCAAB91BD71C9ULL, 
            0x33B61BA6A41D1CC9ULL, 0x571EE2F7208EE835ULL, 0xD0083CF2C63FF9EAULL, 0xDCA02777490BBC8FULL, 
            0x9429094FA3D84476ULL, 0x6278F6D006F90BBAULL, 0x295AFDFE2A3B3CD0ULL, 0xE492EECB0EFCD962ULL, 
            0x5F401933E2967518ULL, 0x37981A6CE2A89C3CULL, 0x4FF0E7483E62DFDDULL, 0xA6D52C240439BDDDULL, 
            0x4EF13A05EC52D809ULL, 0x4EC7469D8DC78FE1ULL, 0x17610F29A1E6FD7FULL, 0x8E2B2DB9F580E5DCULL, 
            0xB4250BAD1FB604D6ULL, 0xAEB1CC25AA207B78ULL, 0x2234589129CD5D41ULL, 0x98A2DBF989D1FA15ULL, 
            0xEC856BB026E92BC0ULL, 0xD2943009AC0FAB07ULL, 0x88C7D794ADF8B2E1ULL, 0x5C53FBDC56321380ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseBConstants = {
    0x04B3644484D92C34ULL,
    0xF480D74AA1DD4DBDULL,
    0x5128001682F4506EULL,
    0x04B3644484D92C34ULL,
    0xF480D74AA1DD4DBDULL,
    0x5128001682F4506EULL,
    0x2087011948524345ULL,
    0xDF668CD6FF57A38EULL,
    0xA8,
    0x4E,
    0x11,
    0xFD,
    0xE4,
    0xB3,
    0xA9,
    0x6D
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseCSalts = {
    {
        {
            0xEF2917A5DBAD7B00ULL, 0x9451B1E464D4F314ULL, 0x2B82CC6C164CE402ULL, 0x0520E9D9679F6C8CULL, 
            0x782EA1981372C4BBULL, 0xFC9BF7F89ADEF46FULL, 0x05A4F6BE8AEF368AULL, 0xB105A40E247549C5ULL, 
            0x3731B4E066EBFD32ULL, 0x939CC471983A459EULL, 0x0F5F9B218A856CA6ULL, 0xF2DCEE5D52DB8D31ULL, 
            0x492DABF54EEAB172ULL, 0xDE35BFB3B289435CULL, 0xEAC91A98F025D3B7ULL, 0xD67B6EAE9BBD0011ULL, 
            0x783C7220AD2074F0ULL, 0xCA09D9BB4CD94B03ULL, 0x3A92307FCE9ED527ULL, 0xD2DFA34FFB3A28F8ULL, 
            0x83D399A925058301ULL, 0xCB83F4C3FA87704EULL, 0xF2B51A19483DA402ULL, 0x6E896A1819F44E0FULL, 
            0x97A3281DE39512B0ULL, 0x9E76A52452A3F96AULL, 0xC9762EDA68425375ULL, 0xAC8E0BE514C61207ULL, 
            0xC52164A3168744F1ULL, 0xE46198B70D0BF14BULL, 0x517F98F8DB697B71ULL, 0x730DE16FA7A649C6ULL
        },
        {
            0xF926C99911A18EB9ULL, 0x0311AF85CE6BC3D1ULL, 0x9DF1C0059B4F4CC7ULL, 0x5D544ED23F77F591ULL, 
            0xE1D197AEA0FBACC2ULL, 0xD167DB634F20AD6AULL, 0xD694D096C3EE8E8DULL, 0xEF694AA109BB2D5AULL, 
            0x61F31D5AB357786FULL, 0xDBECB256780578D2ULL, 0x06EBCED86D1EF439ULL, 0x31DF440B18376788ULL, 
            0x679425F42FC0D572ULL, 0x7E0738B2287CEFDBULL, 0xAA9F9E9D03147998ULL, 0xD3DA4A337E0F9880ULL, 
            0x4CE235AF50D5AC28ULL, 0x24F3CE4AED9B1CA1ULL, 0x7FA41200EB4B589FULL, 0xAACD01FFC5C31730ULL, 
            0x8F29F7CAAD432E65ULL, 0x982B98112F07B638ULL, 0x5B1AC5DA2F82DB21ULL, 0x3A8C41B9298540E8ULL, 
            0x853F805B4B1304BBULL, 0xEAD95A06ADB7BF96ULL, 0x347C409303A2C91CULL, 0x8B3B0EA37ADE44A3ULL, 
            0x1D92D8D0F095C72FULL, 0xA84A9040CD17B61BULL, 0x7B63306BC1E3564EULL, 0xF4066929C0161022ULL
        },
        {
            0x03278015FD62B164ULL, 0x21358F71026E95D1ULL, 0x7AC4730E683B7DAFULL, 0x98974A24523FDCBCULL, 
            0x8AF7ABD743D6C5D5ULL, 0x7763BD206D6C6605ULL, 0x4942D203296ED2FAULL, 0x8380FA3F8C40D3EBULL, 
            0xD9DF41D7FF70B685ULL, 0xCDA54473294426A6ULL, 0xF522C5EB0AF3C1FCULL, 0x6799E334361411B4ULL, 
            0xB40EC64E7AB985FFULL, 0xF6180051746C9AF7ULL, 0x581FE3BC0AC25F6EULL, 0x78ABFD5DA6E31F9CULL, 
            0x2B6EED3C130B0241ULL, 0xDB50AB7B6F10D2CCULL, 0x461354ED4B192491ULL, 0xBBD0B5667436EF0BULL, 
            0xCCF9F51928802EE7ULL, 0x26374BCEA2D8318CULL, 0x44CCC693A93458E7ULL, 0x033305E28C06F80FULL, 
            0x6F2E72331C6148F7ULL, 0x28F8A6A991334211ULL, 0x835ACCBC3A279F01ULL, 0x743C9A636B0AE604ULL, 
            0x7A855327340522FBULL, 0x7A8018142D7A3DD4ULL, 0xF980E19098F67A8EULL, 0x6E0B82F26CAC5655ULL
        },
        {
            0x98D18FB1AA12BFAFULL, 0xB71560084AAD97F7ULL, 0x412754DBDD6C0C53ULL, 0x1280D39028AF4BB5ULL, 
            0x7C937A5A2D9844A2ULL, 0x100C59B002EAB50FULL, 0x4BCA86707C909FE9ULL, 0x85468C7B0EB150D7ULL, 
            0xB9CC92C513940387ULL, 0x952C80718460126CULL, 0xAC32483F45C1CC64ULL, 0xA375926577DB5EC6ULL, 
            0x65ECF5530927D495ULL, 0x9B7E2CE338717202ULL, 0x62FC34B31A2C3399ULL, 0x0A420E70677EF135ULL, 
            0xCCCA6ED92522C3FBULL, 0x20191BA11A884062ULL, 0x3EFA85E504C2DB5EULL, 0xCC386AAA461DCDCDULL, 
            0x973287AA11FDFE6EULL, 0x945F080CA4817884ULL, 0xA37E970FA0391E41ULL, 0x24BF2B3FE1F82142ULL, 
            0x22D9FC6D0B206D2FULL, 0x618FEFC27D249E88ULL, 0xD6AE48A5E68B4616ULL, 0xB1B6B1C154FB5ECFULL, 
            0x09D7D7693C7FB1C5ULL, 0x249A0C176F3117A6ULL, 0x704690B65B1DFCDFULL, 0x5363D441166AECACULL
        },
        {
            0xA45C5F2B16B2A06CULL, 0xCD335FE5B54D0D16ULL, 0xB2CF281DA61D26DEULL, 0xC35A9076328FBC18ULL, 
            0xEAC48C9F8F2BF5CAULL, 0x380D0CD5DBA50A44ULL, 0x13A1A91B133EDB30ULL, 0x507C516CEEDD00A2ULL, 
            0x4E24839C32859C63ULL, 0x4904E02E8786695AULL, 0x59C818A84C2C0653ULL, 0xB5EA7989F9D02313ULL, 
            0xC7DF4AFC04A2CA42ULL, 0xE347B35E4F90D038ULL, 0x32E50C209D056D7BULL, 0x747B037ED768C01DULL, 
            0xE7671DDABFF53F82ULL, 0xBF878FFBF1CEC425ULL, 0xB77D87E5F146C6D4ULL, 0xF22A6ADB3864AC70ULL, 
            0xFBD1AD1B6FBC14F4ULL, 0x6BBA4E4F34CA10E5ULL, 0x638DCC3CB2513007ULL, 0x2994E2AACA51B8E9ULL, 
            0xCE1E08D2671B41DDULL, 0x1A1188A7E7F6BA39ULL, 0x869EC00564AD8BD5ULL, 0xD71EF869F20CC3B0ULL, 
            0x72EEA8C326C8FD7BULL, 0xEF74780C8F12B345ULL, 0x286729769B672B47ULL, 0x4505BC93463BE8AFULL
        },
        {
            0x76CC24329E2991AEULL, 0x73B5FF5FF06A19ADULL, 0x224CB48FF8A2BE04ULL, 0x912F177B60728548ULL, 
            0x31B611E8A6B17445ULL, 0x14801DD461E72C34ULL, 0x90887A722BFA0684ULL, 0xF5B92E72EB468043ULL, 
            0x8218658D80C02FE6ULL, 0xEE703E93C00F5A1EULL, 0x0CCEFDBC316C2D80ULL, 0xA1ACBC49A90C06EBULL, 
            0x0253EC0F77A92F6BULL, 0xA12B341C32F0BC4FULL, 0x18C5B570B4948367ULL, 0x0E56137A3CD1FBC3ULL, 
            0xFB9667DB05A8ABA5ULL, 0x62BCA623D6BB6B35ULL, 0xEBB741D05DDB5686ULL, 0xAFAF024D1E3B32CAULL, 
            0xBD5E5C11066D7D4DULL, 0xE1C436B762EAE2B6ULL, 0xF7EAE24537B47019ULL, 0x1AA10C435305F326ULL, 
            0x01E6A39F8776EC8AULL, 0x82167DD56232970FULL, 0x90AEA0DD7F6FC54EULL, 0xDBD1122CA3C47639ULL, 
            0x291DAFD497E1C65AULL, 0x3C40873ABF63EFD3ULL, 0xE8C9E805A2D44C81ULL, 0xE8E66FEB038DEF00ULL
        }
    },
    {
        {
            0xD32BFEF0A94AA1EAULL, 0x5C5C3FC0E5EDB48FULL, 0x6406CEB54E011776ULL, 0xE8A5688FE010FDCCULL, 
            0xC1A1654C7C1B9049ULL, 0x35A03F3F289602C2ULL, 0x91FDCC60871C83EEULL, 0xA5029AA935F330E9ULL, 
            0x853E409A20971B52ULL, 0x6FBB8504055236BBULL, 0xEE2CD85BD1675AA9ULL, 0x3D551A080F0A12ACULL, 
            0xCA0A52D637BFF173ULL, 0xC9589C93DDB54154ULL, 0xB27486FF0A1E9038ULL, 0x7455E4DDEAF0558CULL, 
            0xD9ADFF8B189C2393ULL, 0xBCEB553A31164077ULL, 0x9CBEFBB01F78442CULL, 0x0D2F3B9C1CDE7730ULL, 
            0xF8950866491673B4ULL, 0x29DC198C8B8F3E7EULL, 0x5CA9043F32E3DB21ULL, 0x18CFEC8E557320A6ULL, 
            0xC897F5317A0C4F8AULL, 0x81F3DAB0FC82E1E2ULL, 0xF746AA144F069A18ULL, 0x06F26E8C9BDBA4D4ULL, 
            0x2DED350A65FDAB99ULL, 0xB14A0A2904C1FB4FULL, 0xA7B06E884A89E191ULL, 0x8D5E12320A185A73ULL
        },
        {
            0xDD9A558A6EB58015ULL, 0x0DB1879CD0E6E06DULL, 0x400304DCD2F2B3B4ULL, 0xBEE714309BF773DEULL, 
            0x46ADC890FAE4D899ULL, 0x291476385C921474ULL, 0x7D0829187E498019ULL, 0x1E021F86BA745B00ULL, 
            0xB8A977680B9308D8ULL, 0x1F4FD8C4CCC8D879ULL, 0xCB7D255FF0999E74ULL, 0xC606859397DD76AFULL, 
            0xB4BD830C0928C870ULL, 0xCF74E61E9892D2D5ULL, 0xAE338DC4E079FCF3ULL, 0xCFC9287492D61468ULL, 
            0x0D29F20719601F16ULL, 0x7842E0D7C74BBAF7ULL, 0x14FA4A8A4DA8E9CCULL, 0xDA8AAFB88932B5BCULL, 
            0xD3D41CFF42C2705CULL, 0x116316B8B8F3628AULL, 0x0D0244856E56C290ULL, 0x6AD20E20B7794273ULL, 
            0xC6606B582B0E54DBULL, 0x0B890DA0AF5AC601ULL, 0x343412F100608F80ULL, 0x3782B6046117C11DULL, 
            0x6B9E707636DEDDEAULL, 0xC6DF75C87032D7EAULL, 0x0ABC3A943EB3E8E1ULL, 0x31CF02A3AE49462DULL
        },
        {
            0x4D121200B1B4870FULL, 0x4413C28E7359340EULL, 0x2305ABAE21CD0340ULL, 0xA1A526D3D0DA76D8ULL, 
            0x7E9AC28C964855D4ULL, 0x59D6BE0794109394ULL, 0xE427C7A35608F414ULL, 0x36CBED8966923CB6ULL, 
            0x09F13D1D90AA3BBDULL, 0x10FD0B29CCF1BEF0ULL, 0x55A3ABF294D864FFULL, 0x019D9DE24039BEE6ULL, 
            0x2DE9838668B4AD88ULL, 0x89473DECED22A8DAULL, 0x50B7E6E5BA445843ULL, 0x299C4825D07E35E0ULL, 
            0x0F2E8C292A72491FULL, 0x9AB1A98366DF1D54ULL, 0x28B1DEC3E35EC208ULL, 0xCFFF662EDF53A4AAULL, 
            0x83223EF074E47356ULL, 0x8BBCE7D4ADF48EB7ULL, 0x4E058EFE8910D78FULL, 0x206A602661ED10EFULL, 
            0x4F08F0986A97925AULL, 0x148994DE5D2E6F4CULL, 0xDCD025470DC49D2EULL, 0x5D2D5D5DF4541950ULL, 
            0x3552B09A9AB5534EULL, 0x882225637599420EULL, 0xCEBE6B95C15651DCULL, 0x8D94CA1C35BD2B79ULL
        },
        {
            0x804E951851DA2C2AULL, 0x3905E8A3E05E9C2BULL, 0x9633560E8F96D388ULL, 0x796E84B8765F7D7EULL, 
            0x9B73223A693A9BAEULL, 0xBDBC04086287D3A8ULL, 0x1CC036F5D709A30CULL, 0x92898F4CFAAF18A4ULL, 
            0xC49DB1ED815AEC28ULL, 0x1F265D8778A9AB3FULL, 0xAEC44F92C9097567ULL, 0x83051CFB6C9EE8E8ULL, 
            0xB2A76F3D0EBA9C7CULL, 0x40A5D3DF366D2A0BULL, 0x241A829C46CBCAA3ULL, 0x2C597DA6B64B7185ULL, 
            0x016E76B03B6D1534ULL, 0x77487D96744F0BE0ULL, 0x11B723872D982DFEULL, 0x0E2A036D823A458FULL, 
            0xD265F24AED86B1DFULL, 0x00AA17A74DD543A8ULL, 0x785D221E28059734ULL, 0x3D8F7DD101C96068ULL, 
            0x6772175F20748782ULL, 0x9A3140195D75EB79ULL, 0x254F7086289B1EDEULL, 0x32D615B8359917E2ULL, 
            0x29C41A0CB531230EULL, 0xA19A8B1BBD96C04EULL, 0x14D93E447E46B1DBULL, 0x9F7F0A4558615C87ULL
        },
        {
            0x32146FFCB3B9D572ULL, 0x39D233054DA1240DULL, 0xFE52CFB5F528D6E4ULL, 0x0739CB49E86C8AADULL, 
            0x8D6A6D0403EDF2D0ULL, 0xE0F57FC4E4F8EE70ULL, 0x6B556C01B525B452ULL, 0x9DBB69EC94CCDDA3ULL, 
            0xECDB27D36EAE33BFULL, 0xCB8047D27CF4958FULL, 0x3227CC72741A14FDULL, 0x55EAB1353326EC6EULL, 
            0xD82708A47B18CA12ULL, 0xD27EA3BF09ADAD40ULL, 0x5804424C4C9146CAULL, 0x3284F8B3EAF38098ULL, 
            0x78C1021F2875BDB7ULL, 0xA5B201DD028CF86CULL, 0x55A63C97E8E4287DULL, 0x76D0E541865A07D3ULL, 
            0x992F9DC0708AF210ULL, 0xEA273CBC1B076EF9ULL, 0x3D2A2D5DFD43102AULL, 0xCC8124A792337AECULL, 
            0xFD1F2A6A9E4EB9F6ULL, 0xAEF6F435A27F7185ULL, 0xC18F89312D53952FULL, 0x952CF5331D7B5F01ULL, 
            0xC45A841DFE68376AULL, 0xFE60BBDFCFBF9349ULL, 0x02277EA28693ECF1ULL, 0xA91FEF38200F469CULL
        },
        {
            0x3E388DDC8186F3F2ULL, 0xA1FAA3D28C0BADEAULL, 0x0EAC03931B587A49ULL, 0xD138894184DEE535ULL, 
            0xCCCA09F456C4C187ULL, 0x7AE726949E73B070ULL, 0x8341CBC1B3F68721ULL, 0x0A96E5F1B528ADBCULL, 
            0x103E41473252412EULL, 0x5CD6682BDB52A0C8ULL, 0x7D3C79EE0BBB2651ULL, 0xC1511AEF0F0F8D95ULL, 
            0xAD4D4D65377A0397ULL, 0x6F17A47A95A3CAF2ULL, 0xA6533F2C2C710FF4ULL, 0x82339B22E473E68EULL, 
            0xA89EAA13F0C97D30ULL, 0xD7AB3BB11B175745ULL, 0x71A5D20724124B23ULL, 0xD044C9FB825EBC55ULL, 
            0xF8C62256573DE758ULL, 0x5586B61FAF347807ULL, 0xF72A2FFF23C36484ULL, 0xF076FBFE3642FB48ULL, 
            0x6135C8B1921AF1CAULL, 0xAC590D06B175EE83ULL, 0xA71BFE39EBC8878CULL, 0x052A0A35F04911A8ULL, 
            0xCD3D0221F6D82EB7ULL, 0x5ADEEB305E74F5CCULL, 0x91600DA9C91AFCC0ULL, 0x29EF353D8459AC91ULL
        }
    },
    {
        {
            0x16291999E465EA1AULL, 0xE3A58767364A0279ULL, 0x135B0C62022F670FULL, 0xDC4245F4F9AC831CULL, 
            0x4143A1E27CC167B4ULL, 0xC33ACF7BD339785CULL, 0x70F141C4BCF3EDF8ULL, 0x49CFD8052BF8D668ULL, 
            0x8223A7E55A89B0BEULL, 0x4CBA70C2504D911DULL, 0x0D230F5D74DFA6F1ULL, 0xE6E202EB1BB5B593ULL, 
            0xC6926E70385E432DULL, 0x0D6A75F3B64218B2ULL, 0x1A95E7AE82A12E84ULL, 0xEE862FBEA147264CULL, 
            0xD9B94C71B68B2DE2ULL, 0x4B20A698B06F61AFULL, 0xC369FBD69A62C9B1ULL, 0xC8480C55C5ED1426ULL, 
            0xFD8FA6B9F30C3718ULL, 0x09F056522E1EDDCBULL, 0x6A635EF7EAB3217CULL, 0x6C342032810EA235ULL, 
            0x963BDBC102A9892DULL, 0x46C810CAEA99DC94ULL, 0x39466696634E8947ULL, 0x89CF59B0FED008A5ULL, 
            0x5C8450DDFC0BA6EDULL, 0xA70740D695204B03ULL, 0x37098E29BD3DEB38ULL, 0x326E3DB41203C051ULL
        },
        {
            0xF0D59E4ABE43119CULL, 0xA705E4CEC08496C9ULL, 0x8D6874D46817049CULL, 0xB11DF148A0449659ULL, 
            0x703C70CC992A4CE7ULL, 0xEB4A3C1B3C99E4F0ULL, 0x388A814B4962E2FBULL, 0x68B96FD90EE940A8ULL, 
            0xD7B1519EF7D932FCULL, 0x87943B26B24A4BC5ULL, 0x17B802997CF1D43AULL, 0xBDAD0F46E406B830ULL, 
            0x0DEACB6099D717D2ULL, 0x19A48F6B76278418ULL, 0x5AC816E6E6F17643ULL, 0x190DCB23B25B50E4ULL, 
            0x4F1397EEA95BFEE6ULL, 0xB2D095490947BC79ULL, 0x0F5A5A797A17D74DULL, 0xF47F252D92598D6CULL, 
            0x2DE04058C5DC5EFEULL, 0x49BA4994C59C326FULL, 0xA694F43683AADAD3ULL, 0x81C46540026EB455ULL, 
            0x36CD6EB18B078A22ULL, 0x17C068FB2CCF9055ULL, 0xC5020656D1211BE2ULL, 0xD9C3BDE502DE98DCULL, 
            0xA56FA22879475237ULL, 0xC2FF613F1279EA98ULL, 0x7621EB34CF51B8BDULL, 0x1311145F5F2D0D47ULL
        },
        {
            0xC83E4DE2A429A3BEULL, 0xB432C0825EC26154ULL, 0x0E032BA98022E57EULL, 0x38062A4D3E756833ULL, 
            0xD21BE6A108250B9FULL, 0xF4AA7DBAE525CA8AULL, 0x558F8A53D37157D1ULL, 0x4986C75A5F594EECULL, 
            0x4BB72B42D4414B93ULL, 0x6B8390D2EE26CE26ULL, 0x3C8F83EB79B8CA25ULL, 0xC08DDD8E6DCD5227ULL, 
            0xE9993FD4D54861DBULL, 0x1740D58075DA9583ULL, 0x1E08462F037399A2ULL, 0x3F98D199E51BA927ULL, 
            0x390F6431BDE46B46ULL, 0xF063BEAE398B7683ULL, 0x56AC59C9543F07DAULL, 0x16149D3FF8CDE884ULL, 
            0x290F707DB8609C1DULL, 0x0DFF70225733006BULL, 0x4B4F4E7885F46BE9ULL, 0xA4645445BD78E6EFULL, 
            0x1D2AAE627E8370AAULL, 0xA7A2DCC4E62D50FAULL, 0x57F7F93EC1A8F6DEULL, 0x5404A099217DCF37ULL, 
            0xE8F39923F03C7661ULL, 0xC2E236ED0BD89EC3ULL, 0x03A04A6407817786ULL, 0x23D37EE9A5BCDC17ULL
        },
        {
            0x0C95D103338B9944ULL, 0x8E592DB0136B92E2ULL, 0xB8E4978F155EB582ULL, 0xFCD5C8D17C1E747EULL, 
            0x0E30D314D92419CCULL, 0x25C4586FD618F386ULL, 0x956B9ACAA45AE02EULL, 0xD60FCF74A6929D96ULL, 
            0x0A86D6F3AEC86359ULL, 0x29B117D0E577DF7AULL, 0x846FA07CE4300D37ULL, 0x56F266739C926491ULL, 
            0x965853B676C3ED4BULL, 0x8429750CBF747235ULL, 0xD9318815AC5448CEULL, 0x089A65679C8E79B7ULL, 
            0xCECC545AD0C1F994ULL, 0xCDA94EE817FC60FEULL, 0xE857AD6B002D496CULL, 0xD995819E04A3654EULL, 
            0x5EF51EFA4A23306DULL, 0x628989BEB56E3AFBULL, 0xE0B6DEC492102386ULL, 0x82EA2F964210F767ULL, 
            0x3F8218885FFE973AULL, 0x59AC66527BB8BCABULL, 0xA8158413D26988DAULL, 0x6EC212AAC191738EULL, 
            0xFC502B0B5BF501A0ULL, 0x6A99B9E27E77BBE3ULL, 0x11A9B061312D29D7ULL, 0x8A8020C917EE00A7ULL
        },
        {
            0x295ABCF6F91C466FULL, 0xA8092D6FF08DACF8ULL, 0x82E4C8DA962D9D10ULL, 0x8BBDC3BCD50F99F2ULL, 
            0x4978AF7C6E886FFCULL, 0x73E0B723AC6CA6D4ULL, 0x80615B797639720EULL, 0xC0BFAA25F58288E8ULL, 
            0x05D4364624FDA350ULL, 0xD07A5C2D6AF60617ULL, 0x7D8AA56E18F49F72ULL, 0x6DD276BAB0CE8972ULL, 
            0x6F32607FA980C9EEULL, 0xE36434F19D96C27AULL, 0xF6A11C6CE18F3149ULL, 0xBD72E9B9D75B9A32ULL, 
            0xF719DAFBC22D2F47ULL, 0x1EA24E9354F68000ULL, 0x2EA58D9BF05DD812ULL, 0x5933B3355E9C10D5ULL, 
            0x296DA10BA5D2CA30ULL, 0x2843CF46EB2E881FULL, 0xBDE7F04476ACEB83ULL, 0xD969A0152BF99105ULL, 
            0x5D3E471036AADAADULL, 0xCDC0389EFC31C380ULL, 0x2871A1892EC91C85ULL, 0x6C23F971A7F82F14ULL, 
            0x36F4868C37D9C4F0ULL, 0x1CD6BE089FD4BC55ULL, 0x68AFD406893AE605ULL, 0x48206841E90E2018ULL
        },
        {
            0xCDFDF852CFF0BBDFULL, 0xD27AF1E1E364A755ULL, 0x570A3F96FC80925EULL, 0xD843710B083C628CULL, 
            0x3E40D73D3D53C7CBULL, 0x13E5FCEFABD616BAULL, 0x7E97D04AEA96633FULL, 0x010AB7FDEC11B69EULL, 
            0x24EABA52ECFE54B1ULL, 0x5AEC969E333ADADEULL, 0x5DAE65ABF9C397B4ULL, 0x3127CCF1A85A1B98ULL, 
            0x56FAF25B99FFA6B3ULL, 0x20571884454627DCULL, 0x454A725262EEA3A0ULL, 0xC499EF2ABD8A333AULL, 
            0xA27B542053385077ULL, 0xB0B2EAF86FBAB573ULL, 0xFD3A40B34A6C3553ULL, 0x616855832A732688ULL, 
            0xF6C11401B2E86181ULL, 0xDED13497C5AF261EULL, 0x7D202E5C9F7C6677ULL, 0x0517D4B526DEE660ULL, 
            0x6EBA499FE42B58F8ULL, 0xA82959127BB6FB37ULL, 0x1615E14FF6499F33ULL, 0x126436EF979802BBULL, 
            0x6A199A015DAB94CAULL, 0xE11933B69C2DCCD3ULL, 0xCF2001A40D2BA8E4ULL, 0x31309F559CD57E46ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseCConstants = {
    0x1CB6E877E02DE41BULL,
    0xF73247894B6A04BBULL,
    0x7BF7BF6384EBAADAULL,
    0x1CB6E877E02DE41BULL,
    0xF73247894B6A04BBULL,
    0x7BF7BF6384EBAADAULL,
    0x1098CA07F80BC323ULL,
    0xF379312E8CE194F4ULL,
    0xD8,
    0x36,
    0x96,
    0x52,
    0xE2,
    0x41,
    0xFD,
    0x75
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseDSalts = {
    {
        {
            0x576ABCAF99F05A26ULL, 0xDD40ADF38A46C719ULL, 0x9139A07199B278C4ULL, 0xEA394E4CCA8D64B1ULL, 
            0xFE5F8DF044C5EEBDULL, 0x0079DB9FAAC332EEULL, 0x4A45BC4F7CCEDB70ULL, 0xB912E3E0ABA4C4CAULL, 
            0x0225A391C9FF38F1ULL, 0xD6992FAD0B55B938ULL, 0xA959F0004CC09F67ULL, 0xB7676E080C5BBFADULL, 
            0x906DF0947338DA40ULL, 0x0BEC08ACF98FBDA2ULL, 0xE0F3D0DA86596B57ULL, 0x3CAB411C5385D636ULL, 
            0x1C8F1C427C823C71ULL, 0x0D8500B9A4D0A153ULL, 0xE929506FC25A6FADULL, 0x8B3CEA03A850DD7CULL, 
            0x37B25B67E6708C9DULL, 0xE5BDFF6305D4776DULL, 0x71862CC14C33F4B6ULL, 0x150806A9FEFA6C7BULL, 
            0x2E2E89FE114B6D72ULL, 0x3AF623496758F10BULL, 0xDD88BA9C4BB96B4BULL, 0x950AD7D3A9E3677CULL, 
            0x1976962CE69D5D44ULL, 0x3C5CF0B270EAE943ULL, 0xA6D0F41A7A5AC4E1ULL, 0xEFDCA21AAB134016ULL
        },
        {
            0xD3E81C0E2836A420ULL, 0x70562399EE0F354FULL, 0x9407F2072332A5C5ULL, 0x5DF1E058DA3614FFULL, 
            0x48F99E7DDC9B7910ULL, 0xEC10872A337F23E5ULL, 0x402B97625F550C8DULL, 0xDD31C855448BD455ULL, 
            0xE9005FB591F6CDA5ULL, 0x199BC2CD5CB7F8B5ULL, 0x9340D44FFF8A2492ULL, 0xB67591F7A514C47CULL, 
            0xD2F855E1A6EDC480ULL, 0x7208590730E08E93ULL, 0x479CF12CCB00A15BULL, 0xBBE46ABBFA9D5AAAULL, 
            0x32981422F1F72CAFULL, 0x4ACAF781050D9362ULL, 0x135EFF1805288B0CULL, 0x59601AB7D8A11335ULL, 
            0xEC2ED22B18D6A81FULL, 0x52D41E22A9F25D35ULL, 0x83C1F77B89A0DF7FULL, 0x0C2559A7F9EC60D0ULL, 
            0xA035FCCA58261F48ULL, 0x75FBEBF1D57A0146ULL, 0xCBEDFA70B484E9FFULL, 0x1AC7F46C4FB2D47BULL, 
            0xCC6CBD9D2A53756BULL, 0x11C08FED4C12F486ULL, 0x27C0162C36E846DDULL, 0xC45F996F67809DE5ULL
        },
        {
            0x12E1B5B23DBDEEEEULL, 0xFE8337C6A10CF9A8ULL, 0xFA3A92F2FAABF369ULL, 0x6D678DD07659DB3EULL, 
            0x80328778052ACBE0ULL, 0xE032041FA265EC07ULL, 0x19EA3B8B7503D936ULL, 0xA0945C0DF04D14D6ULL, 
            0x596D46849E1C76D8ULL, 0x9201089F3AD89DE5ULL, 0xDC836E7A55F1C689ULL, 0x0171D22A088D13C6ULL, 
            0xF09533A28ABA6271ULL, 0x39BD4D3AFB16365BULL, 0x2D32A60A4D066DB7ULL, 0x63FCBBD30F43AB01ULL, 
            0xA1DBF074984ADB53ULL, 0x95120EAE383919F9ULL, 0x2409F0614D23F618ULL, 0xB0D407DB0ABB5556ULL, 
            0xE769198680D73C62ULL, 0x9EF19B9B9B1E7CE5ULL, 0xB82E2EACD4BF236EULL, 0x669CBE78470C86B2ULL, 
            0x933C8F9440F3B7A6ULL, 0x39B45C52CE52F4CFULL, 0xC35587FDD23C1EEAULL, 0xA948AB30625EF820ULL, 
            0x021FEA47A8C88642ULL, 0xC9E4361ED3CA7A31ULL, 0x57CC2EADB88CCEBEULL, 0xEE60633DBA555058ULL
        },
        {
            0x5195125F9BEDCBD1ULL, 0x4B7C63076E0B2EE3ULL, 0x45563D37BAEB481FULL, 0x66EE751F6C74A8D2ULL, 
            0x35DE9092D5682E53ULL, 0x16E01E59B3414120ULL, 0xA21F389A06D2773AULL, 0x5C0D5E588CA5EBCDULL, 
            0xDA0EE2DC31A3A174ULL, 0xD537356857D748D9ULL, 0x1ED6BA2F00C6F957ULL, 0x14E2E7B3867BB328ULL, 
            0x70DB4384B881CD17ULL, 0x492A6DC33AD5D637ULL, 0x7C1D276B38AA365BULL, 0xA2B7910AE941E04CULL, 
            0xBDAA3398B5510D71ULL, 0xAAAF87C78AB84C53ULL, 0xB131742FAD4BB15FULL, 0xF644C032531C7E39ULL, 
            0x5BD1B4506ACEF420ULL, 0xD8ED438D2519295AULL, 0xA1D6686FD5CB7483ULL, 0x0858E654FE8F37ABULL, 
            0xD2B915EB0AA5E584ULL, 0xED6767C59688BE7EULL, 0x6C9BC98D72DEFC0EULL, 0x6F5347DDFE0389B4ULL, 
            0xFC048F1F1E6A52A0ULL, 0xB222912279A231F8ULL, 0x5554B36A068B48C7ULL, 0xB2E27F4F0F9EF546ULL
        },
        {
            0x3A469DBE055D6FBEULL, 0xF387923A414BF632ULL, 0xE3A680EAFF15D691ULL, 0x1CA349BC01597188ULL, 
            0xD92E3C9339F765A3ULL, 0x6A014453FD782E86ULL, 0x215181249792BDF8ULL, 0xA6345830E2309D36ULL, 
            0x0D9DE9A064ABAA6DULL, 0xE572F2086EBFE0F1ULL, 0x18B842DC38672BBCULL, 0x49A233EFDF31B936ULL, 
            0x5A970AC97ECE4E00ULL, 0x3C61AB3805F78419ULL, 0x5ACE5FF211DD08BCULL, 0xD7E680055C53CA1AULL, 
            0x93B5B2FB223634B1ULL, 0x2BA7E65F534BA986ULL, 0xE5388ACB367634C3ULL, 0x5B49518697474CCAULL, 
            0x44E055F029C0B9A5ULL, 0xA63A25517B2C0E9BULL, 0xB88205F736E74D0AULL, 0xCB8326D37ADBC634ULL, 
            0xDECFA516618CE700ULL, 0x4922456B3D02150FULL, 0x89D6213D09C6A4E2ULL, 0x08C0A7780386D1B3ULL, 
            0xDE7CD67BB8CE253FULL, 0x9AEC6023657C276FULL, 0xD4FA4557A8E427D1ULL, 0xBC447D0DEAAF3E66ULL
        },
        {
            0x9D2FB63EAE7BB006ULL, 0x360668C4C7E2AC43ULL, 0x9B481D05436EF4BBULL, 0x4DDE191491B07985ULL, 
            0x1D08F1A6539149C0ULL, 0xBDBFE2C70C274A8DULL, 0xD45E33CAEFF3C3E8ULL, 0x6FC7138E014DDEEDULL, 
            0xCF20ED44DE27A1FFULL, 0xBBD19455590CCCE9ULL, 0xFFA6D933412DD2D5ULL, 0xABBC58E5EAA5F195ULL, 
            0xA32E1CFC6BE8ACA6ULL, 0xEC8BF463465B6804ULL, 0xEE8D82D0A62F4308ULL, 0xBD4E9BB40E5F0B14ULL, 
            0x0A67A48C31410073ULL, 0x8710242DAF257D08ULL, 0x8CF450E9CCF6E295ULL, 0x7AC742AC0FB7D844ULL, 
            0x44651DDAD693CFDEULL, 0xF21C2F707BB05F1DULL, 0xE65CE5332C18AD7DULL, 0x0CB8AA0EFE7ABAE1ULL, 
            0x6BCFD7632C3BBEDBULL, 0x9AFFFBCD3DE34B1EULL, 0xA4C45B104C6057E3ULL, 0x1F5F8788F6F9F576ULL, 
            0x43252C179E2D2CD3ULL, 0x6942211A0E6EC139ULL, 0x570BE6FDA6FBCA92ULL, 0x5DE54E5D27DB1ACAULL
        }
    },
    {
        {
            0x01C5DFC3E3B186C7ULL, 0x8EE5D218133CDBE4ULL, 0x382CF007416F3E46ULL, 0x62D9B4B350D82BD8ULL, 
            0x3C5665C152BAAD1DULL, 0x75494FB6E3B192C5ULL, 0x498B960BF8BB06A0ULL, 0x85BD99984F0399E0ULL, 
            0xFD1A62AC03999C7FULL, 0x304A9F1257FDA4AAULL, 0xC49E39607F74D5A4ULL, 0xA6FB5C4ED08C06CEULL, 
            0x94156B3019B9E915ULL, 0x6B14252CCFB3C9AFULL, 0xCB6E63268306AE03ULL, 0x5C49E5A6DB04A7DFULL, 
            0x37CAC749624C6FA6ULL, 0xBCFD17171A81345EULL, 0x40F2E539BEAB2C45ULL, 0xC2A3E3F71FA0A665ULL, 
            0x930C700351F2E9EFULL, 0x498271AEAD759CB1ULL, 0x748B06A998746261ULL, 0x506A48F06A0F44E4ULL, 
            0xED867EBB898E9120ULL, 0xB9B125A80F0B18ACULL, 0xD5250150DD74E726ULL, 0x3F53C28CDE4C8300ULL, 
            0x066D624074DD5757ULL, 0x4A544B9DA91762E5ULL, 0xDFA365173FEED6F7ULL, 0xAECF6B1D02A1ABFFULL
        },
        {
            0x12B27D040B34BC6CULL, 0x530877666AAA798EULL, 0x51EE9CD0541B347DULL, 0xCF42BB854D3CE3A1ULL, 
            0xDD3D4897FE0F1B63ULL, 0x86E3B4960B07730DULL, 0xC071C2404D7B7C64ULL, 0x89B5CCD6D8CF6E7EULL, 
            0x49AFD8C5BF5C1ED8ULL, 0xF8B37A244374AAB3ULL, 0x9454DB1CAB221B59ULL, 0x26C7FFA99BE1B23FULL, 
            0xA708EBF6747A44A0ULL, 0xA6E1FD2C7517AAE3ULL, 0x3F0467271E3E38E5ULL, 0xAAC1B3FA98170BF2ULL, 
            0x0004D9FC6545ED0EULL, 0x5128AE762559EB4EULL, 0x365DF3113EE83E46ULL, 0xAB6B2245C0CB4EC1ULL, 
            0x461C306836C9EA29ULL, 0x56AB00B004763A6EULL, 0x3CCA3F4FB7803FF9ULL, 0x937A95C0FB6E5C52ULL, 
            0x79FF9EBFDA55FED8ULL, 0xDA299658DAB54641ULL, 0x0CD467C1B52177A4ULL, 0xDCD22E5FAA457312ULL, 
            0x87C9ABC95BF68C75ULL, 0xE99F7EAB1C9B202EULL, 0xC0C336C91B1A85B3ULL, 0x422C54F39B4876A6ULL
        },
        {
            0xAE8F2E0FE982AB9EULL, 0x0D1A5337C66864C3ULL, 0x2AFD26BC4843FF83ULL, 0x6B2805684B23BF7AULL, 
            0x9F317D48CAF8049BULL, 0xBDA3CA613C2F3BC9ULL, 0x8EA480CDA249F574ULL, 0x4DE4C69A11D820F2ULL, 
            0x9EEAEE322B7F283BULL, 0x697F1C6A8A2F84E6ULL, 0xC21E70BC02B92B0FULL, 0xF07A72B00D8256A7ULL, 
            0xAFF18FB02883B9DCULL, 0x80CFEEE0E906469FULL, 0xC3F57813FE189E01ULL, 0x08DF872589E80B52ULL, 
            0x7FB57FA8241DECA3ULL, 0xE6ED1B8B2279A866ULL, 0x49E6B2587A5C8229ULL, 0x05E41B4878107841ULL, 
            0x1EB74C503B01BE62ULL, 0x7C74EA825115FB7DULL, 0x5ECF52739FBA40DCULL, 0x7EEF82D58838FE9CULL, 
            0xA058A12D61889506ULL, 0x34255679D5E92A61ULL, 0x3872E506877B0DE9ULL, 0x55D44A3FA3F53FA5ULL, 
            0xC58776BE9641A0D3ULL, 0xF0DE250F23E52C42ULL, 0xB93ECB2F15FEE8EAULL, 0x5F0B3409F068725EULL
        },
        {
            0x9003EC9B1B89245DULL, 0xBD45D7A75C977945ULL, 0xBDBC79295AEE2CE3ULL, 0x281CD6E606E79485ULL, 
            0x803CC3F19DEA778CULL, 0x62DE845EE5C77658ULL, 0x5B4DD96CDFFA7D51ULL, 0x8EA4F401C19E23BBULL, 
            0x01CBF4840E5ACD41ULL, 0x94F4536E67C2AA9FULL, 0x36132EB9CE98596EULL, 0x6160E606C106616BULL, 
            0xDEDCAF5D6CE904BDULL, 0x7D8ACC2B73B801CBULL, 0xD62A6EA929DC8963ULL, 0x3748CD03D2822E37ULL, 
            0x70FE4162B8A3F2F1ULL, 0x5E32FFD8D3CE8A80ULL, 0xB555B5DD9EA699AFULL, 0xDCDA5F54399FFA49ULL, 
            0x22456664DC928BCCULL, 0xA0A8B456D8CD0241ULL, 0x5ECCAA460EBC1D1EULL, 0x2F1EE5F9F8EDBCEDULL, 
            0x83049F4BAEE06DB0ULL, 0x25A5620CD82483DAULL, 0x97203B5AFAF44F99ULL, 0x586999814C053FB3ULL, 
            0x25CD3AE14B03B120ULL, 0x8D3D90CC74FBBA11ULL, 0xA1D2D492A9B62D5CULL, 0x6DE504E56961393BULL
        },
        {
            0x8AC26E296F26AEFEULL, 0xDCF5000DD8F9BEB7ULL, 0x642D7F01C0064C29ULL, 0xF97D5197BE396FF1ULL, 
            0x205D094FBF7B16D7ULL, 0xF3FA4FCB579FDD74ULL, 0x38D9DB5CD7B8D2D6ULL, 0x3A359393D55B5BEBULL, 
            0x9101877831FB2C48ULL, 0xACF339DBDC3A4360ULL, 0x9413FB1CF3F50787ULL, 0x3614D6DB5DC77FC5ULL, 
            0xCDCE8F805E9D12E3ULL, 0xE16389B94F49B966ULL, 0xE12FD145B19B48F8ULL, 0x3DB75A9390F33DC9ULL, 
            0x7E5C974360BADC13ULL, 0x7208F007A81F4F37ULL, 0x266655333B073722ULL, 0xA617063E05627B36ULL, 
            0x3848839486489EE3ULL, 0xE6234101ACF2402EULL, 0x21B6C8A754A7E160ULL, 0x48DCD4142935A7CDULL, 
            0x99393FEA845C31A8ULL, 0x8C4EA5963A0DA472ULL, 0xEC9E2DABCDA0E6B4ULL, 0x5A76C04A4F7083C4ULL, 
            0xA36F2055D160B77DULL, 0xD252578EC6B15F49ULL, 0x1EB46696C24277D0ULL, 0x38DF17A2D571382EULL
        },
        {
            0x57C0536D3E71154BULL, 0x03D2BC61073DA677ULL, 0xE38CA3304F759700ULL, 0xD2E237412ED20960ULL, 
            0x9B594A86EF2387B3ULL, 0x7204298F64F77274ULL, 0x917B8FDC5F80A4D2ULL, 0xD00CE3EC5FA1411EULL, 
            0xB5D13C9F997635B4ULL, 0x58238EFBEF961805ULL, 0xAE88C52C531ACE12ULL, 0x75C64F3BA0A85A27ULL, 
            0x149952EC73A0DCBCULL, 0x47BB3BA15B7B6B8BULL, 0x5A61952BCE07008DULL, 0xB13F3D02A1E675C8ULL, 
            0xE98817D64217CD67ULL, 0xAAC9E40DC0B8B9D8ULL, 0xCA1FDC365112D556ULL, 0xEC9FCD4CC1C51083ULL, 
            0x77EA843321054631ULL, 0xA88E82EA6C5D86BFULL, 0xC3FB72CB9CB32D37ULL, 0xFE1722820FBCE7EAULL, 
            0xBC685A08E87C9539ULL, 0xD0001AACCE83D70CULL, 0x0575C514DFFA3F19ULL, 0x82D0B33DAA66077CULL, 
            0x91E313A6D1B14F7DULL, 0xD60F4890FC32FD0EULL, 0xDFE4F7B9DC2C9900ULL, 0x1C984674990275D9ULL
        }
    },
    {
        {
            0xA0B5D8E3C3C15255ULL, 0x4E4A29C6BC14CB35ULL, 0x117B401533BD0DA8ULL, 0xDB7CFABDC7DF29D9ULL, 
            0x8B5D1E4169860D25ULL, 0x08FC14D802A1A8C1ULL, 0xD4A1A001BC5FC393ULL, 0xFFEC0BA4D79FFD41ULL, 
            0xC6776654851DDEE5ULL, 0xEAD0F1ED95A9D36EULL, 0x1B3627121E5E9F77ULL, 0xA969743D0E01F089ULL, 
            0x6B558D945A61D1E7ULL, 0xE03C530CD44568C7ULL, 0x0609011936B435A2ULL, 0x6FD2C6036AECED3CULL, 
            0x46A4EFBA933CAA01ULL, 0xCD74267D4F92288EULL, 0x0AE18D47284E72B0ULL, 0x20E38F23F79682B3ULL, 
            0x8CE1612C8E52B898ULL, 0x8F06CADCF948187DULL, 0xAAF0E59EA9E4566BULL, 0xCC3E0B952BC58E44ULL, 
            0x9699946597F48EB3ULL, 0xE358B842533D7B20ULL, 0x2D875FEE21D840D2ULL, 0x7A8591B03408042DULL, 
            0x1032A8883568F33EULL, 0xD3DFB6499E13985CULL, 0xA533B96CC475E362ULL, 0x187B12DDC6E0428CULL
        },
        {
            0xB9BE1A7488B5E737ULL, 0xD20B5BC9EE8EFD00ULL, 0x1C3EA2810DA88D9DULL, 0xB70F159848588EF5ULL, 
            0xBA9ABF1AF25A21CAULL, 0x562A9742B583D526ULL, 0xB86F0A48D20E343CULL, 0x798867E64B5FE702ULL, 
            0xAEFE34FDDD8518C6ULL, 0x89189491BDCF5F3FULL, 0x7A984A19F48E2F3EULL, 0x6064E4FF9A97A352ULL, 
            0xBD638FFFCC5325C5ULL, 0xD1336C39AA1FABD1ULL, 0xAB2E22F14D4DB602ULL, 0x6C1FB3B343799EDBULL, 
            0x262EF0AD704D02F0ULL, 0x8467FBA4A19BAA7DULL, 0x00223FE07387A525ULL, 0xD961DE97BE501414ULL, 
            0xF89C18FFF1A41D57ULL, 0x36F9E59165B323B9ULL, 0x741519E9252B1F72ULL, 0x5481C7C05BD8F4CDULL, 
            0xD1C55F2E621D55F2ULL, 0x8EABBB50B2D11269ULL, 0x8DB5D01DC025B570ULL, 0x296C74146F195B12ULL, 
            0x6E6FDB460ADCC76BULL, 0x0BEC5C4845A5DD79ULL, 0x8F791DD66F10369DULL, 0x234E6F16F185B4B7ULL
        },
        {
            0xB5A6C1ACE6C9504BULL, 0x8F5255BC788FA234ULL, 0xD0208A7F6C5BAF8FULL, 0xB81181A8DEE8566FULL, 
            0x040BE06F69270B6BULL, 0x12E1E003B19D68A6ULL, 0x65BD37A4DD823BC5ULL, 0x09B298ED9D93EB1EULL, 
            0x8C05691868F35FCAULL, 0x6A7091C8624E4B37ULL, 0x08346B8EAA53EC28ULL, 0x526F1715DCC6DC7BULL, 
            0xAC7368D4017A7184ULL, 0xE0618242DE402D5EULL, 0x059DD8A6F69E9525ULL, 0xE9B5B4144BC9326CULL, 
            0x4C8F805352DEFCFEULL, 0x1F241C3BE387803FULL, 0xD531B7F89CD7EB0BULL, 0x66C59EAED8D0F7C9ULL, 
            0x17271E3E65C7E2AAULL, 0x1A726A787BF44548ULL, 0xAD189477216F1C67ULL, 0x1C90C2CCF310E86DULL, 
            0xA489B6F038F8E38CULL, 0xF40028545C469952ULL, 0x4FB9369D917760A8ULL, 0x69520A648B761A19ULL, 
            0x7B47BA00BD83835FULL, 0x4D828861CDA67B98ULL, 0x17D2947E3FE1C61BULL, 0x0435257CDC54249EULL
        },
        {
            0xE8B3F624D611889FULL, 0x914379A72D9780F3ULL, 0x0461652185BF7AC6ULL, 0x8D3790F1F08D6711ULL, 
            0x22ADB1E9DA58BE69ULL, 0x8F7C2F9D54434380ULL, 0xC0124E9FD47FA852ULL, 0x9BB517D186E0E4ECULL, 
            0x44D3C9B5DC3C022DULL, 0x9946173B343F97FCULL, 0xB69CB06EE101DA50ULL, 0xE6C0D441A5E29AF8ULL, 
            0x7DE196A509D90020ULL, 0xB6077B2B9D5B13FDULL, 0xA16CA3DF38ED5063ULL, 0x52F7A4884379F395ULL, 
            0x04EAE6F2FD9C563FULL, 0x74D0AD16D2B3FC17ULL, 0x8169916EC539C483ULL, 0x5648FEB660B30749ULL, 
            0xD213DF6E3D18F549ULL, 0x36985C8E2AE287B9ULL, 0xA571849CD1B5E3DCULL, 0xD17862F6EC680DA0ULL, 
            0xEE69ABA424C2B46BULL, 0x71FAB0F8F3389BA1ULL, 0xD76CDC6C706DC48CULL, 0xE578F0EEBFB06A5EULL, 
            0x3C1529004242ADACULL, 0xFF1BBBE902D8B22FULL, 0x2A1B8B62033BC60AULL, 0x781CE80D791549D2ULL
        },
        {
            0x71AFFFBE13B82719ULL, 0x616B71ED84EE2DCCULL, 0xEB1460D67EF1AB49ULL, 0x5EF2AD1FB0C4023FULL, 
            0x7B5B35BA8235FF11ULL, 0xE4AB860CEFF3D579ULL, 0x8F2B57C4F39CEBFEULL, 0xF8499BF953C34579ULL, 
            0x0D037EB0F77C0D66ULL, 0x3E78DCDE7BC77EF9ULL, 0x0E782BA80312FA81ULL, 0x68BE3133FDFA37BAULL, 
            0xC3D194746F2EF36CULL, 0x15C2605634F78A70ULL, 0xD9BB5307BD374C7AULL, 0x9D36E5318F54EE28ULL, 
            0x714D25F2AC8352EBULL, 0xBF4D3479A6BDB558ULL, 0xA826557BCE60E129ULL, 0x703F104F812A3654ULL, 
            0xD00BA5C000601BACULL, 0xF9B4686D6D5BBF47ULL, 0x3E2B559ACB4F188BULL, 0xC72506F9E97A3D90ULL, 
            0xF79C764E17F2EDDBULL, 0x385F5861CA6CEB45ULL, 0xABADC8A0EF895260ULL, 0x703D60A75A7BC01BULL, 
            0x486545467082F354ULL, 0x1C4523FD07908EDEULL, 0x11AA91D3AC160D73ULL, 0xCCD6A89F899A3C5EULL
        },
        {
            0x26F7A26FB85930E7ULL, 0x112E5BEAA1B9B495ULL, 0x59967AD65805B2E5ULL, 0xA45E639B41BB2870ULL, 
            0xE2DD8B16419F8E43ULL, 0xC7D6283B8345FAB9ULL, 0x8077E9BB657193C9ULL, 0xA779B206D361AC92ULL, 
            0x930640CF2D356F86ULL, 0x6AD5D96BE972DAC6ULL, 0x4A975C512C651F5EULL, 0x7F10E17CDF974BEEULL, 
            0x00173C6E5C891B0FULL, 0x63FD8F173A781916ULL, 0x199E0C7471A1BB0AULL, 0x073CB0DEF9095770ULL, 
            0x98D508824D437154ULL, 0x9ED5438A7D71AE85ULL, 0x453C8406C7D3F338ULL, 0xBAA5ED0ABBA944C0ULL, 
            0x23558B6B65FE4C53ULL, 0x6FD0BBFF28AC9945ULL, 0x64EC6DC3EA30182FULL, 0x124F2C619BF97958ULL, 
            0x60A947B765BB2217ULL, 0x4C81A99F4E1D8E92ULL, 0xF0E0095CA8853E22ULL, 0x922169F5710F9D7CULL, 
            0x8FDE7AE4DAC45CE6ULL, 0xF4C4138B0D86BD50ULL, 0x200BAE2A9AA58437ULL, 0x119765A072C36DF2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseDConstants = {
    0x8607BAFF1BD99AB0ULL,
    0xC9C326278A35F803ULL,
    0x393FDC6BB186C168ULL,
    0x8607BAFF1BD99AB0ULL,
    0xC9C326278A35F803ULL,
    0x393FDC6BB186C168ULL,
    0x5DA958F8EB27C8D2ULL,
    0x538F65B40977C4CDULL,
    0xF4,
    0x96,
    0xE1,
    0x99,
    0xB2,
    0x12,
    0x02,
    0xCE
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseESalts = {
    {
        {
            0x8A349649DFCFF01EULL, 0xD1C472F613D018B9ULL, 0xEA8C96E0BE0868E4ULL, 0xFA237697C4B41B2FULL, 
            0x98904A1A98C3E9E2ULL, 0x1B04F06DBD272797ULL, 0xA3333266FFBDB95DULL, 0xC2F3FCD9B54F10ADULL, 
            0xC994BD4D01351ABFULL, 0x7D42FD3A93A96FEBULL, 0xFD6A7FA2CB5B5F09ULL, 0x14C725E558F957E1ULL, 
            0xBBD06E27C585EC8DULL, 0xAC74E5DA0755773CULL, 0x463442C2488DC5A6ULL, 0x98767EA196C87F6AULL, 
            0xFB5965842BFB3676ULL, 0x0EA7F51BE620BBF2ULL, 0x151A1A615B1A1F8EULL, 0x8B5DD710898AC3FEULL, 
            0xB87ED77D80C31262ULL, 0x39C730DBC3F74AB4ULL, 0x4BEFA661C39D0121ULL, 0xD617570FCCBE66F9ULL, 
            0xC91431329DAE3DDDULL, 0x6030DFB263826042ULL, 0xF923A14F67654EF2ULL, 0xBA1DA0299D4A8674ULL, 
            0x53C585EBD911F8AAULL, 0x25521CCA1D40540DULL, 0xCB44845C44008180ULL, 0x2D60DC2B5B52FCF8ULL
        },
        {
            0xCD33ED2715879F1FULL, 0x721DDDFB265250D8ULL, 0x7939F67A479EAB62ULL, 0xFB140640545E849BULL, 
            0x473AA05597CC03C5ULL, 0x66964344372D52B0ULL, 0x93FEB7E10B453541ULL, 0x24EE9389DA452326ULL, 
            0xE5668B01E3EFB5BEULL, 0xE2A83902A10F1BDFULL, 0xDF442D758E9682D7ULL, 0xD1307A2CEB4AC89AULL, 
            0xF9813F93F1408D6AULL, 0xA765592845619708ULL, 0xC8B31FFD54E4344AULL, 0x9BCFBC4F4A340C25ULL, 
            0xDABD4FF7651A3A3FULL, 0x80659CB6A0AABAB1ULL, 0xB193B3E792AF8A7CULL, 0x94CBA27BED56C081ULL, 
            0xE9D6C00641303ED7ULL, 0xA00E10BA04BD091CULL, 0xADD4E23DFF5EC0F9ULL, 0xFA761C6A4228FA11ULL, 
            0x125E9A6A8156388DULL, 0x9D9FF03836612EA9ULL, 0x9103731B33DD497AULL, 0xFEAA9FF5235CDA21ULL, 
            0x3922427305756B34ULL, 0xCCC132FBCBBE16F4ULL, 0xE80A6D0B6C28D948ULL, 0xCE66B35578A7BFD1ULL
        },
        {
            0xB368352231FE40DCULL, 0x7E32E806A3F1440DULL, 0xB617922C54605A87ULL, 0xB6EF7FAEFD3AD6D0ULL, 
            0x9C9EE3523FEB23E3ULL, 0xEB265A9897209C1EULL, 0xD4DD6D1269D6E124ULL, 0x68CCA905288D7A01ULL, 
            0x46B85F29879A1F0DULL, 0x4F2742D867385E5BULL, 0xF4C9BDD97C738EACULL, 0x185E6DBBD8B1E09FULL, 
            0xBFBEC7854D04D446ULL, 0xB62477B1CBF78DE7ULL, 0x377EE867590890E8ULL, 0x795932DBE118FDCCULL, 
            0x8474895642A57498ULL, 0x0C7A02E89E80213CULL, 0x962786511727719DULL, 0xEFE2FEB679554D73ULL, 
            0x9091FCB98BD6322CULL, 0x7D5684766D3C5868ULL, 0x3D49FCC14E9CBB64ULL, 0x4B9FE9E7816148E4ULL, 
            0xF548BBAD690B46D0ULL, 0x89143D58D25BB185ULL, 0xE88A786F0AFC6580ULL, 0x9C73A05A278B6A6FULL, 
            0x7F3D655E2F7FEE2AULL, 0x06A3610B61A482EEULL, 0x9E62AEA1D2EDC3E7ULL, 0x29A5A23637D1C315ULL
        },
        {
            0x987C2AD74FFD76D5ULL, 0xBFFA1638C295E6EDULL, 0xEBF1B64B72A754DAULL, 0xEAF4D571B22DA12AULL, 
            0xDFAD9CF8B3586CFAULL, 0xD092ACC3CE99F1AEULL, 0xFEFD8FB2CBDEA21BULL, 0xDA607DFCB1B874F9ULL, 
            0x125B293DEFDC7883ULL, 0x80B53EB86A7AEFE4ULL, 0xC54A58B1F02B305AULL, 0x40673A7B0DE95135ULL, 
            0x8432B4E56ADCE1BFULL, 0x32BF02F985BC2E27ULL, 0x90F1B6065F11D24EULL, 0x75B238C2B6C46E2AULL, 
            0xCB4DABD646C035A3ULL, 0x9063544F64EB76BAULL, 0x856E485274D297D8ULL, 0xAED3C0BD5B66879EULL, 
            0x7FDA2CA303A3209BULL, 0x83FA7F7EF4B9D5C3ULL, 0xC392F95413B2A146ULL, 0x61922765B169DF58ULL, 
            0x1EC0549650869D13ULL, 0xB225CA39BC8D0F73ULL, 0xAD022693AC89FFC7ULL, 0x28148B907B387353ULL, 
            0x401E5CC201BB8BD9ULL, 0xCF112DCC1E99768BULL, 0x5CFCB97CBF5AE750ULL, 0x6D0424DA08403378ULL
        },
        {
            0xC7F80EB7B0956813ULL, 0xB203D51165AD6FECULL, 0x8EF2FFE14F55C4B4ULL, 0x379AA6C37615F692ULL, 
            0x3F55D73E1510B4EBULL, 0xEFB8729797DA6829ULL, 0x0346D09C01070C5DULL, 0xD0046E0DB9771F9CULL, 
            0x7D8B71F45991B510ULL, 0x9E5510662727DBCDULL, 0x9B28F18F73451F64ULL, 0x243B7E435110A85BULL, 
            0x077E409E713B318BULL, 0x3743509093F42BF0ULL, 0xA30278FBE1451240ULL, 0x5CEF850AF3FDF375ULL, 
            0xC593420D70A92246ULL, 0xD34BED8C5A1468D8ULL, 0x39FD692FF710222AULL, 0x5E263C39CF1EA2B2ULL, 
            0xEA04908F78F0AC9CULL, 0x5006B08A65F4ED26ULL, 0x4939D2FD8B6C6AB3ULL, 0x7A71B340E57E7A75ULL, 
            0xAE530AD34B620474ULL, 0x5128F0A5F31303A7ULL, 0x86D8484A1C21FBA7ULL, 0x421339FF18A02C76ULL, 
            0x01E37E493BEB534FULL, 0xEBCC501FF89A3EEBULL, 0x50F0881E6302D992ULL, 0x127DF8928B86ADF7ULL
        },
        {
            0x40865E6A0AD60C47ULL, 0x1E1097DEE2C7B377ULL, 0x8522909E91479A1FULL, 0x4C2C6F06C7D5D60EULL, 
            0x4E83A081834AF4D9ULL, 0x3FBE816DA0C2C654ULL, 0xF52691BA7A6CF3D7ULL, 0x6C7BF0639C69F2AAULL, 
            0x039AF87FFDDC784AULL, 0x0AA47171601A9600ULL, 0x69A44C83D70BBFC7ULL, 0x0C8DE952738CF08FULL, 
            0xDF57F6E0F93F97A9ULL, 0x8B0365F613812574ULL, 0x2384406ECC414B49ULL, 0xA730A713E580CD8FULL, 
            0xE3A2F4D8882B2B8BULL, 0xE0BFE2A463D41B73ULL, 0x7172A5D2071ACD13ULL, 0x541D25435657BD26ULL, 
            0xFB88CE56F04FFA71ULL, 0xA43A954AFACE6632ULL, 0xA7D445CB10BB2E45ULL, 0xC3109E0C08E4B81FULL, 
            0x6EF699FB5FB46AE4ULL, 0xD2A59A8E13CF8FD1ULL, 0xBEE6D321FF77D73EULL, 0x21F67CB23DF362F3ULL, 
            0x3EB4E9B70490A98CULL, 0x1A4556BDA2E7EA9EULL, 0x0972B6161E756C78ULL, 0x4AD72B7CD5BF7095ULL
        }
    },
    {
        {
            0xDBF05481BCF9E2A1ULL, 0xEA6630F669027728ULL, 0x9469DD099967D1E7ULL, 0xD1C21DC576D92EC1ULL, 
            0x6E990168731DE003ULL, 0x63CA4EE1F36D129BULL, 0x6E88F79A2D0CE857ULL, 0x79016C59A74D3E10ULL, 
            0x0666B9B47A21CA9AULL, 0x14EF16A6B41776A6ULL, 0xBD4606A36BC3FC83ULL, 0x52E60A3843C4BD49ULL, 
            0xD3669970CFA5A9EDULL, 0xB5754FC44916C2A1ULL, 0xA0A84B309ADCCCC0ULL, 0xB91F9703EAEC51FDULL, 
            0x1C64EDBA98CFAC72ULL, 0x63EE4A12FA4422F8ULL, 0xF6C5BF64796472D6ULL, 0x5B10173F74523577ULL, 
            0xE26D143B54C02A64ULL, 0x6A5FB88ED705C98AULL, 0x2FC80D1AEEB5114CULL, 0x13F4F25833BA850DULL, 
            0x913F6611C558E2BCULL, 0x60CD1B48527519B4ULL, 0x48FD615CFF58F4B8ULL, 0xD1FE9F387873F714ULL, 
            0x23DEE0B2F97AB2DCULL, 0xAA8D84B1A8F6CC2FULL, 0x7287C6F21B5CCF67ULL, 0xE3E44169DD840EA5ULL
        },
        {
            0xC43FC565A213C4DDULL, 0x6CA71B6374D70629ULL, 0x9D97D9BECC2E30E8ULL, 0x135AC9F3E192BD7CULL, 
            0x80F4DAE341A94FB4ULL, 0x4FEB1CA5BAA8BDD9ULL, 0x33235F0C5C0A3215ULL, 0x50EB5D4038F33C1AULL, 
            0x8CA28BC3B81AFD4FULL, 0x86B007F6AB6166B1ULL, 0x87C1AD5179C8C90EULL, 0xA234BAA1BE3D473DULL, 
            0x582ECDFB2AA5767EULL, 0x7E49D6B35D2B1545ULL, 0x58EC92B22737A94CULL, 0x9E7B6BD474F74B51ULL, 
            0xB21A48BEB63BC814ULL, 0xB2CD2B919ACB91A2ULL, 0xDBBA7643AB9923CDULL, 0x430C7C7AF876045EULL, 
            0x08491FDDCFEF485EULL, 0x6837FAEE91BB9E1CULL, 0xC5F469246AC5B2E7ULL, 0x11A4544E10450D2EULL, 
            0xAE0198F971BE89F4ULL, 0xCA4A7D3FAF96DDA8ULL, 0x46EB8C11103C727AULL, 0x55D373799DFA5015ULL, 
            0x04FB78E07AA8E154ULL, 0xC94E0294DECDEEB7ULL, 0x264E016F4D6D14D5ULL, 0xCB53A3D129233FA5ULL
        },
        {
            0xB546EC6C2B0B300FULL, 0x9240D0C643B4DE7FULL, 0xD1730978FA607FDDULL, 0x88440204C9E0B23AULL, 
            0x396D748A7B2A01CBULL, 0xA2621F72C8D36490ULL, 0x97CA1D0B9D41C2F5ULL, 0xA070F07AF55EC1D7ULL, 
            0x4664BD680C3FF6FEULL, 0x340A170D6CE99574ULL, 0x586F5BBDED818448ULL, 0x5A93C98CEFAC520FULL, 
            0xE56F0E5AEF861B91ULL, 0xE1B2C2A411A608BFULL, 0xE5D9DAB5F4EA634CULL, 0xC93AFE8EA37FA8A8ULL, 
            0xF7536C19358275F9ULL, 0x8983285E0F0F8B89ULL, 0xEEC6ED0A55380830ULL, 0x913E9AD51E4064D9ULL, 
            0x8329FE6E161FD0F2ULL, 0xEDEEF5086B0D26AFULL, 0x20F389E18D795E58ULL, 0xE046EDC9C5A913E8ULL, 
            0xA7DE99120084B184ULL, 0x0C355976E31D035FULL, 0x65910D0CDE5719C0ULL, 0xC70D37B3CE081281ULL, 
            0x85B5DEFCABEED2A9ULL, 0xF6F69B030DFD726CULL, 0x487DADFB9AFF06F8ULL, 0x25DFCE6BB688FEC3ULL
        },
        {
            0xBCAA04E4814BAD45ULL, 0x3707161E7128ABE9ULL, 0xD8BC2A3F4B554BECULL, 0x52AF18D699934D6CULL, 
            0x706536CBB3133863ULL, 0xE001DF37979F3BACULL, 0x59981A98C0B649BCULL, 0x8103ACD3E807608EULL, 
            0x56A1191D6CBB6DBBULL, 0x4C4A9C4B9E6A1FFFULL, 0xB6A1372AA6C41E53ULL, 0xC394EB4B23724935ULL, 
            0x9DA3B56C51FF7D7BULL, 0x75C574E81B61C8A5ULL, 0x383E8FCF1762BF1EULL, 0x07303D74B25766FCULL, 
            0x729B6520D0472738ULL, 0xD3713866CA5A3120ULL, 0x76B50D4599C8DDA0ULL, 0x97FA8DBB4A47B019ULL, 
            0x8CD423EDA812BB6EULL, 0x9DF98F22DC982F52ULL, 0x872BD3D4A70ED9A3ULL, 0x4A1CEB34666EE337ULL, 
            0xBC386D3A19C8B3C7ULL, 0xFF441E34AB140F98ULL, 0x012E506B06BD87CDULL, 0x8A4AB713D5A1A8B8ULL, 
            0xCBC08B13B94827E6ULL, 0x366E9DDFCBC496F4ULL, 0x65F9E2FA42710DECULL, 0xFF7903717EF37034ULL
        },
        {
            0x31E054410F1405DEULL, 0x8D5AB42D5D285F8AULL, 0x88BD96A6A6AF752DULL, 0xA9B21DD6CD07FA4FULL, 
            0x77651CD7EFC95894ULL, 0x77FD851EDA8B21CAULL, 0x24B95B4B63482BC8ULL, 0x17EBFEEC79B6CBE8ULL, 
            0x06C293322DE4BB15ULL, 0x0D25207532C63357ULL, 0x3A3AD2D41A889A32ULL, 0x22DA2DA5452A8962ULL, 
            0xAB0237F324FCB213ULL, 0x74DF04FB970F808DULL, 0xAC733580CCC5DFBCULL, 0x619AC95A1192B793ULL, 
            0x25FFAAF1461A1CC5ULL, 0xB328623F396B2808ULL, 0x9EE0FFD13BA43B00ULL, 0x918544E723BBA5E6ULL, 
            0x74EC27CBFDEBD492ULL, 0xEBE4564E66551407ULL, 0xC149E0F1DF20C74BULL, 0x5557E07559E98D85ULL, 
            0xCEACFEDDD10C469AULL, 0xC6D4CD5E5F2F810BULL, 0x7B949F38EF2E86E1ULL, 0x593499C2A14F7EC2ULL, 
            0xFCCD79C1DB586AF0ULL, 0x0B92EAA950799027ULL, 0x74CE50BD6FFEE403ULL, 0x07B8C2B25358DB5FULL
        },
        {
            0x7F2A72028735512CULL, 0x6B03C43F44F37FF4ULL, 0xE92861535CDD8330ULL, 0xC85B4C5B7EC56DF7ULL, 
            0x882C77C425B4ECB1ULL, 0x3A3666046399A1F4ULL, 0xC684F23332AB84E2ULL, 0xC12FA8640940F679ULL, 
            0xE68C2A42E690AE00ULL, 0x1453C22F04033909ULL, 0xEF82D4C32D79A17FULL, 0x534A4E6003CE57CEULL, 
            0x955D30442CA5C620ULL, 0x3B97F4C206FAB0C2ULL, 0xEB8BB18511917FDEULL, 0x16023B9F47ABAEE3ULL, 
            0x214FC9C9067FEEEDULL, 0x20D4A0E91EB63259ULL, 0xC0DB19DD7A6D4FECULL, 0x5AF291BE674892F7ULL, 
            0x05C16206A5CECEB7ULL, 0xBA214B898B6D6D60ULL, 0xAAE81D442D947153ULL, 0x08BEC8971B74C936ULL, 
            0xC869C5C014C9F005ULL, 0xCC70F0C093ECBE27ULL, 0x3E56ECED65985787ULL, 0x8B84529FC610B5F1ULL, 
            0x56DE2B5004885405ULL, 0x03F8438D1A53536AULL, 0x6ABF0A899BBFA021ULL, 0x855E62A23CE779DAULL
        }
    },
    {
        {
            0x1C4A50CA6E4D7647ULL, 0x548298AEC4A202F0ULL, 0xF15850FEB5CD0A96ULL, 0x388F42D10B68F6FCULL, 
            0x241E6218FD6C5B97ULL, 0x5013F4B87F681239ULL, 0xE914FD240C74869FULL, 0xFB4C1092B8C46A16ULL, 
            0xCED523B892B6F806ULL, 0x6CE82B5B7FCF79B9ULL, 0xB87B25B3FFD1AD16ULL, 0x52602B39107CA9AAULL, 
            0xCCDE3CF2E6FA114DULL, 0x78EAA160D4D1FB12ULL, 0x69322997F090B0F2ULL, 0x83706EF75D318909ULL, 
            0x14B2D0BDCF6D7901ULL, 0x61018B02012585C5ULL, 0x992559AF863DEFC1ULL, 0x578084E50E0272DBULL, 
            0x20A06550CE4F49BCULL, 0x56AE0DB75198FE74ULL, 0x976CB5265397B10CULL, 0xC641A091EEEA747BULL, 
            0x6BD607D931D9362DULL, 0x5D8B20C419CF5724ULL, 0xA4960CDB7F41FCBCULL, 0x2505A3DDE407D54BULL, 
            0x74E01544170CEC7DULL, 0xD3BB632129A2F4FBULL, 0x2DA0A335B5FF1D57ULL, 0x7FBD9077AFBDB403ULL
        },
        {
            0xCE30E3CA6DEFB13CULL, 0x1F34174B8FEE170CULL, 0x0F6A40020D424EA1ULL, 0xB99251A2814B084CULL, 
            0xEF8C356F4244F15FULL, 0xAFC2D8982A39DCC9ULL, 0xD3C103335FE91E51ULL, 0xD9D400416FF76702ULL, 
            0x07AC5EB09D068DD5ULL, 0x0E3422ADBF9E18F2ULL, 0x26671FE7DAC31E96ULL, 0x2267642092E71EA8ULL, 
            0x9B57A1092761D935ULL, 0x08F628DC6FEA1C93ULL, 0x7661F08C5BDFACC2ULL, 0xD0F7DA8530BF33BEULL, 
            0xAE5FFF75839329ABULL, 0xB29440CF46AE6022ULL, 0xF93E8203A23ED243ULL, 0xD93E7B18B282B8DDULL, 
            0x2A4957859E7C04E3ULL, 0xFDDE927272B63B10ULL, 0x8B50BE04E17E3652ULL, 0x1970921D9489F03FULL, 
            0x4B213E5FECC6AFF6ULL, 0x16CE0D78D77658FFULL, 0x0085C6CDDF27553FULL, 0x532CFF57DD0D1684ULL, 
            0xAC584A9237396DB2ULL, 0x015D8DE46938F282ULL, 0xB4BC0AAC0E275927ULL, 0x254D76A92692DD9CULL
        },
        {
            0x7F2F62A97D012163ULL, 0x357E29271CC421ACULL, 0xAC8F0E9BC18BBE00ULL, 0xF18BB578C026E74EULL, 
            0x45C0CEEC0BECCDEBULL, 0xC4310A6D9345368BULL, 0xF670F1D3378C5F9DULL, 0x18D1EE05283626F6ULL, 
            0x1F8893CC2DFC9294ULL, 0x1223BF6AF33A5146ULL, 0xB6F080EF3D48F22CULL, 0xE6C303D73B279F76ULL, 
            0x6CF92DB11F29148CULL, 0xD7D7D7369DD5E6EAULL, 0xEC0361189E00A9CBULL, 0xBE7E76DA6A0831BFULL, 
            0x1321C22B5C6722EDULL, 0x4F740E860CA7367DULL, 0x20AED1470F6FEE8DULL, 0x5F92EBB83F3F0A9BULL, 
            0xAC6D047826711F08ULL, 0x36EAA31077E45757ULL, 0xD22341A4D646AF4CULL, 0x0DFFB7A55D0BC666ULL, 
            0xE0C4926880E32AB3ULL, 0x74011ABCDD9315FDULL, 0x899B060A0E7E047CULL, 0x22A7FCC52FD2678DULL, 
            0xC4A09785FFBDB861ULL, 0x38E3B9D09CEBD181ULL, 0xE1A5C845E8A5D841ULL, 0x7C76435D3B809874ULL
        },
        {
            0xD1D78B0F8A99A183ULL, 0xBC5ADC3AFA15EA36ULL, 0x1CBC920296823B0DULL, 0xCA9098FBBA872683ULL, 
            0x55EA8306209D0F80ULL, 0x51E1EC5484311935ULL, 0xD73F37526319D1FEULL, 0x9405C89545BA1FF9ULL, 
            0x41825186F0D67EE9ULL, 0x8CDC83048B0296CDULL, 0x44E6D714021AFD3FULL, 0x4A31E8DEA63335B2ULL, 
            0xA49CE8AEB9DA8434ULL, 0xEEB684E584063F29ULL, 0x75689AC0BB66AF38ULL, 0x7330087C898014ABULL, 
            0x51FC48311026D096ULL, 0x337A106B7E1F85DBULL, 0x1DE346681DCC7B7BULL, 0x3DB05FF144452909ULL, 
            0x949FC0C2E12D937AULL, 0x62289421A10877C1ULL, 0xF7250F9ECAB20844ULL, 0x4C9BAA24373E7D30ULL, 
            0x17FA067EDC72F1CFULL, 0xED53A4B4F96634C4ULL, 0x59517D0AFDBCADB0ULL, 0x451A6F7EB4BDEF51ULL, 
            0xA86A452ADC2DB2F5ULL, 0xA5F617EF44AAE185ULL, 0x478D3F067B92D097ULL, 0xAB5C5794884357ABULL
        },
        {
            0x92B9A461CC084EB3ULL, 0xE7F1DB682A73EBC7ULL, 0xE89B1DB15F2C1384ULL, 0xC0BC964FE73A6365ULL, 
            0x52BDB35AB1AD5267ULL, 0x462CA8029C83487BULL, 0x31B6184DF677DD47ULL, 0xF5F7DF8FE241C4CBULL, 
            0x355D966AC54157A1ULL, 0x11634B4F5C4413A9ULL, 0x755250CE46767D8BULL, 0x7DB7991A7EC5C307ULL, 
            0xFE1D2EE55113919FULL, 0xD67C9FC59252EA94ULL, 0xDC50C1D8EEC58AA6ULL, 0xC33CED58BC54F4FCULL, 
            0x94C038BA64188832ULL, 0x4179AAB180BA3B08ULL, 0xC91733A4B086168EULL, 0xB4ECDA869A56FAECULL, 
            0x7E5AC729AACEB79BULL, 0x4B467E2F54AF2165ULL, 0xB8151AE281D22481ULL, 0x4BB7FF9F2C58A992ULL, 
            0x5E5398553E4EFB94ULL, 0x291C00782FA3EB43ULL, 0x2C602F20491B13A8ULL, 0x05AED62224A00E96ULL, 
            0xFEF9E2266F23727CULL, 0x592DDDB628D0B025ULL, 0x7B7F9894598B8A9EULL, 0xABFAFCCDDDA0D295ULL
        },
        {
            0xEBAD2DB3E3C100A0ULL, 0x49F2D8370BD73301ULL, 0xA4171764B26E9C17ULL, 0xFB32855AAE29A793ULL, 
            0xA6127DC80788BD2AULL, 0xD620BCD4DF13FB84ULL, 0xBC5AD2104543A9E3ULL, 0x9F59A31D6021D772ULL, 
            0x2B337B7988B39B1DULL, 0x07734DB1D7BDF5C8ULL, 0x7919EC499DB673B7ULL, 0x993C53DB5022D8A6ULL, 
            0xD31C12BEA825A2E4ULL, 0x667AA4C4A544435AULL, 0xB99A68F5BC7EB17BULL, 0x13DB696677EBBF8AULL, 
            0x84D0FB62300E9D0DULL, 0xAA32BE427CA2D473ULL, 0x6C4861D29AA75BFAULL, 0xDD15CB15BD8F3777ULL, 
            0xC8564E1C999A0A28ULL, 0x099DCAAA605B331CULL, 0x7A8A3F90CB989634ULL, 0x170266615E8E0F7CULL, 
            0xE7062FBC43BAABCDULL, 0xC0BA03DA06C21EF8ULL, 0x032854E28E1E655BULL, 0x8BC895CB2BA0BCB9ULL, 
            0xFB653E88F3AD9783ULL, 0x86346553701E6BA0ULL, 0xE5762C9E351164FAULL, 0xD726E4E971433AFCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseEConstants = {
    0xAE3266C3249153E4ULL,
    0x5295A286F111E34CULL,
    0x86A8B0A3D48B9AD1ULL,
    0xAE3266C3249153E4ULL,
    0x5295A286F111E34CULL,
    0x86A8B0A3D48B9AD1ULL,
    0xA61D9520217FB38AULL,
    0x69384EDC9F4E0DCEULL,
    0x7B,
    0xF7,
    0x9D,
    0x81,
    0x02,
    0xB3,
    0x66,
    0x2D
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseFSalts = {
    {
        {
            0xCD61199EE4AE4BC0ULL, 0xADE6D5CED0C27438ULL, 0xFE15776AE59675A1ULL, 0x831BD4DF18D5DBB0ULL, 
            0x14B8E79E88ECABA9ULL, 0xFF376F5A659499BDULL, 0xE6A0DCF76676039EULL, 0xEDDCA6C215F530CEULL, 
            0xC94FD9A87A74DC8DULL, 0xEE53B6944E3030CCULL, 0x760BEC81546A45A5ULL, 0x8824F06457D483F6ULL, 
            0xBA2D5F6BCD2395B6ULL, 0xACEB5512823B3078ULL, 0x30A4E5D3792FF918ULL, 0xC7436445521287CCULL, 
            0xB389821E031C8807ULL, 0x5CBECFD7018B712DULL, 0x0472D91089D4AAF8ULL, 0x6CF91E599EF7C5C9ULL, 
            0x19D68EC4D413494CULL, 0xE6C30C051417C871ULL, 0xE5CD234DBEA33EA5ULL, 0x888D15F0127DE40BULL, 
            0xC4A8C8E4ACC38E40ULL, 0xD68CA09A4B8C842CULL, 0x374F07E30EC92DBBULL, 0x307FCA4B91AD5B33ULL, 
            0x600144C642FF9D1DULL, 0xF9CA6AB2E427368AULL, 0x6B0D7C3B79120020ULL, 0x96736484508CFDDDULL
        },
        {
            0xA50BAEE5A791877AULL, 0xD2C215C584487FF0ULL, 0xE613409079AB535AULL, 0xCB09F4860972C24AULL, 
            0x66040A33C769E5A3ULL, 0x9DD61D1E3774E3C8ULL, 0x4798C09652D8FD3CULL, 0x54221FCCB3F57026ULL, 
            0x4143F034D44595A1ULL, 0x5ED2BCF7EA6B56E6ULL, 0x1AF4F01B97862765ULL, 0x60339EC788C778F6ULL, 
            0x9F354AEAA239C08BULL, 0x9E3A615AE89ACF7BULL, 0x192EA432F2894B8BULL, 0x8683CE2A83DC4C71ULL, 
            0xB6472C8D2CBF86C1ULL, 0x7B0080C3BE74FDF8ULL, 0x3F0CA12DCD03F0E6ULL, 0xF9865B1E2DC5225CULL, 
            0xDA99C59D98980411ULL, 0x2D90D7A1A7DF3F63ULL, 0x5F84458A5BD0C510ULL, 0x4A875769F5C24BB2ULL, 
            0xC2D9CC14E56BAC0CULL, 0x6162ED0ADFA96FC7ULL, 0x19F051552C66E273ULL, 0xE48375EC1F3179B0ULL, 
            0xE9A3A51D1B284F72ULL, 0xB194CFEE38F1C23DULL, 0x33306EF307702737ULL, 0x0CE5039CF3455C5DULL
        },
        {
            0x1194951387CABBD9ULL, 0x4DF4CF63C956B3EFULL, 0x29E13A490611EEB5ULL, 0x25BFC0F498C7397CULL, 
            0x1C20996B76C4CF1BULL, 0x5E92490EC71BB0C9ULL, 0x913FADA49EE5D6B4ULL, 0xECBF9A3EA6C51402ULL, 
            0x4F4A4968676733CFULL, 0xCA80183B74E856CAULL, 0x3BF9E7F7D372D80AULL, 0x11365D7BF9417D5AULL, 
            0xE0DD5CB779EB8489ULL, 0x62ECAECDC41FF543ULL, 0x1C536FC2AAC9D4B4ULL, 0xDA83CA7DABDBEAE0ULL, 
            0x0EF6C70BCEA5CB75ULL, 0x0289D197AAA1C07BULL, 0xD15545F5AC29411AULL, 0x32BC46655B1DDE14ULL, 
            0xB92828E7448E7313ULL, 0x02051B726AF0ECEAULL, 0x55A79A97ED6BB7D3ULL, 0xA12CA4721709EF4CULL, 
            0xF109D43D72A7B8BFULL, 0x90CB423A72DD8BE3ULL, 0xDDBB27DB0A685198ULL, 0x960CBC9036362170ULL, 
            0xF6A51CCED9B23067ULL, 0x00DE0ACFD0009D60ULL, 0xCD48DE99BE830BBAULL, 0x931EA752EEACC519ULL
        },
        {
            0x839B963F540C44DFULL, 0xDC7FCD03AFB77AF4ULL, 0xDF73EA6320225C8CULL, 0x7D93B26C50F644CEULL, 
            0x7AE06BC77D3064CBULL, 0x4C3C5F006D35C027ULL, 0xCC5D34B981847857ULL, 0xC6E24F488924EBA2ULL, 
            0x320D23537D9D8588ULL, 0xAD255429B94347D6ULL, 0xE131BC47E60AA3C4ULL, 0x6A947C888C56D29EULL, 
            0x2A18726AF3C64460ULL, 0x8F19937A9A7E72FDULL, 0xFAFF32DCC1862A7DULL, 0x45E21995942DA18FULL, 
            0x1E6188347B4C9E07ULL, 0x17E03FB9BCD85765ULL, 0x41316B7EC130B421ULL, 0x46F44E7533658FA8ULL, 
            0x92AD6DCA749C28FCULL, 0xCDB5169A54BED1C0ULL, 0xD4D09FC11DBBF424ULL, 0x9430DD35DC4568C7ULL, 
            0x0D382597AD959D58ULL, 0xC7A2D0C51BA75B2EULL, 0x1BB6EA7949709E06ULL, 0x72D75F574BE3459AULL, 
            0xDC8519A42D718546ULL, 0x9908AF8A97A005BEULL, 0x8363CD9A972F46A9ULL, 0x3E3E950FE35174ADULL
        },
        {
            0x6120AA6134A61E0DULL, 0x6D7B15C12545DCF3ULL, 0xF06123A92E240EADULL, 0xBE0BB4D502BC0E96ULL, 
            0x11FD6DFA92CF2537ULL, 0x0100147031F4312FULL, 0x2B32B9ECB19768EEULL, 0x6DBD455CF5D6899EULL, 
            0x43717B1143F9B549ULL, 0xD2638E396C53934CULL, 0x92155300B443DA65ULL, 0x2079457BE0A1665DULL, 
            0x046C54850230BDF9ULL, 0xDC407767136CFF11ULL, 0xAFF1448A25B6EEE2ULL, 0xA5EC959387337122ULL, 
            0x31C148B69EFA5A5EULL, 0xF008576528A5F958ULL, 0x50375F207D7969CCULL, 0x76A3CDB297638F73ULL, 
            0x97D1A356F8AE82EFULL, 0x7A1F3F246D8B4B13ULL, 0xA546B23F9A7A9D8DULL, 0x25F53DBF396AA838ULL, 
            0xB08BD92C2235A4F0ULL, 0xAA148CF93E6C0322ULL, 0x434B4A236339A322ULL, 0xC87237C8AF9DDA3AULL, 
            0xDF5303BC98A1CA8BULL, 0x300DFCD231679220ULL, 0x2DCCE27362849D6EULL, 0x87310372A04D8BE5ULL
        },
        {
            0x1E570C2851F67CDBULL, 0x747D063FCD6487C8ULL, 0xDA2F5251367BFEEAULL, 0x57F3D88DF495728EULL, 
            0x16B4AAC3DB5A63E3ULL, 0x233998C842828AB8ULL, 0x1C7917B7FB387C7CULL, 0x04503D9804D7BD58ULL, 
            0xF66A410267A5247AULL, 0xD5CFEACC5493DAD2ULL, 0xB8A53F82EB3055BFULL, 0x169982F6144005EFULL, 
            0x25C64351F684CC31ULL, 0xFBDFA3F7BF857F9CULL, 0x9D401D092A214B4BULL, 0x85457F2A75BA86AEULL, 
            0x961CE6AC8FC50FBDULL, 0x05E14B91E624E2BBULL, 0x88C7924CF4335F89ULL, 0x9AA6EE39D9E2854CULL, 
            0x138D33175839A41CULL, 0xC069D53BDB4313AFULL, 0xA7E101F6FD74460FULL, 0x8A43B57446003895ULL, 
            0xE9C91AF52FFF0A3CULL, 0xA6694C9B6F6310DAULL, 0xEDF2297C946F61A4ULL, 0xC9CE403B2B73F6E0ULL, 
            0x5D3A79AD31FDC708ULL, 0x6593DD0721ACC10DULL, 0xD8F453EB8645D775ULL, 0x0836C3BF7AAE760AULL
        }
    },
    {
        {
            0xE56EF343D1421296ULL, 0xEDD39A61B47105B8ULL, 0x843FEADB2DF7E248ULL, 0x40FB93B564544E43ULL, 
            0x59862D30257E537BULL, 0xA0051AD6CE955679ULL, 0xC2D8DCB6E80D8B29ULL, 0x93C5DB82F7CFE689ULL, 
            0x2AB902332F22750BULL, 0x01B4593A1211B928ULL, 0xC02ED32D70798072ULL, 0xC69A1B8592F60EE1ULL, 
            0x3F1771FB79B38069ULL, 0x218FE2460EF543F0ULL, 0x665E23651431DDDBULL, 0xE00A1AEADB80BCE4ULL, 
            0x6A31B683E5B2EB75ULL, 0xA3A064FCBBC239DAULL, 0x0C04EDC968F88DB8ULL, 0x7A53B80BC5D8523FULL, 
            0x3A5E774E4C909DF4ULL, 0x49864C09C1218592ULL, 0xCA10C4D7B4FC4E8CULL, 0x53EA18A09B3728BAULL, 
            0x13D82A9F86A1A4B1ULL, 0xD186BF571AF30E59ULL, 0xE3BBF01731954320ULL, 0xA986B29E7E6DC17DULL, 
            0x7E969BFA6B0D5C20ULL, 0x0153A527AA93364AULL, 0xBE8ED43EF1DD79CEULL, 0x6D76A18A07B84E55ULL
        },
        {
            0x78CD61FA2B636026ULL, 0x3F2C53EE5324368EULL, 0x88DCA04C0661B7E6ULL, 0x0B29A3049C29D900ULL, 
            0xC56AFC6385FF5B73ULL, 0x19E165E90793B759ULL, 0x63194EB0A5FDA387ULL, 0x849FBD8C785A7429ULL, 
            0xCE3DA4237A8716D2ULL, 0x5084A3ADA05D1B3CULL, 0xF1739779384DA05FULL, 0xB75D490B73C3C0BDULL, 
            0x0058B7D58B2636CEULL, 0x8BCD938328609DA7ULL, 0xCEF56D92085F5BB0ULL, 0x154E0850443C854DULL, 
            0x2AEC51831C8D1253ULL, 0x09D83B255364968FULL, 0x8DDEB5EEEA27C093ULL, 0xDFCFFB324D645280ULL, 
            0xD1CBA78E66DE4020ULL, 0x5DCFE05DFB82C1ADULL, 0x4D7B8617EB46E90AULL, 0xEB4DD44B62EFE448ULL, 
            0x854A81DBA8037F15ULL, 0x42F714F75B0F5C38ULL, 0xCB138A6AD4C11789ULL, 0x498905A52C0D4026ULL, 
            0x6BB732396C67EB7AULL, 0xFC10A312805A974BULL, 0x52030B9C1CB03943ULL, 0x318F8D035600E958ULL
        },
        {
            0x7F54736BB97D6169ULL, 0xFB2E07C1694531D4ULL, 0xEA23CAE10E5F8AE2ULL, 0xF44654223E976922ULL, 
            0xAE8B0265F06FCE0CULL, 0xAEB5F539169BA2E9ULL, 0x6DC99C8D4CA19DC4ULL, 0x92861F29D7CA5112ULL, 
            0x60ABE29887E4E4DBULL, 0xEE952D54B5971A9EULL, 0x280CC5B5FA3A3DBCULL, 0x32B661E58993A400ULL, 
            0x948DCEB7A5C77A9CULL, 0xB2282389CB536079ULL, 0xB81E0AC1665DF7ABULL, 0xCCA9E046C56B9D69ULL, 
            0x10F190CC724F7A3DULL, 0x1EAD0E48F691B71AULL, 0xEEA163A23DAB0026ULL, 0x76A6A87DD03C8CE3ULL, 
            0xAE90E54B9EF3725FULL, 0xD6DE779CC74B50EFULL, 0x658C3E05712B1927ULL, 0x0D6A5242E14DACC8ULL, 
            0x025B963B4C204D11ULL, 0x689B89DC66D94399ULL, 0x6EA691A8931B64CFULL, 0x6B1B7BEB7A37CE5CULL, 
            0x932B769C88CC188AULL, 0xCB4B78EF1FE1A301ULL, 0xCF08049B0FEB169FULL, 0xF67BB0A16100323FULL
        },
        {
            0x7D44D345B1F4524FULL, 0x752CC3CD70D91F98ULL, 0x270FCA09ABBFA491ULL, 0x9B6027A25391B6ADULL, 
            0x4BFC7321E1DD6F2FULL, 0x7DBF33011A5390F2ULL, 0x4961210CC7D87390ULL, 0x36D3B502F4756D5CULL, 
            0x6C4A98A07F9E0FA4ULL, 0x30C9B47817FF5AF4ULL, 0x9C2B9919BDFEE82BULL, 0x2DA31AA146F5F769ULL, 
            0x021FAE08270F9966ULL, 0x0BAD7CD18A07883AULL, 0xE36E6C1DBD10CDD8ULL, 0xE3B571DEA2811866ULL, 
            0x1B850DD3F4110F8CULL, 0x8AE1D5095C1B3FB8ULL, 0xAFC15153616DC439ULL, 0xF32C0932D3999C15ULL, 
            0xA723FFE93E7C3F16ULL, 0xDB066E547AF15296ULL, 0x4C530B2626AC74A8ULL, 0x84E1A26D4C955E1EULL, 
            0xBC16D1DF38B5B257ULL, 0x4B4EC5F44A56F01BULL, 0x4373AF88E1DCE9B8ULL, 0x1A06615153D06D73ULL, 
            0xC92906253D4CDBC6ULL, 0x4F9ED3351AD17C91ULL, 0xB7DA881026148829ULL, 0xA6443C86D93810A7ULL
        },
        {
            0x02CF99A830F7284FULL, 0xF9A4F8F522791CB2ULL, 0xF749A64FA1B47B1FULL, 0x0257B6E5761DF739ULL, 
            0x51264F33BF506732ULL, 0x136007A6B30497AEULL, 0x190D9A852659E84AULL, 0x21921F7F425BB1FBULL, 
            0xFBECC99B19D5F8BBULL, 0x4902B79519BFCAACULL, 0xD48DB5AD147E3D2CULL, 0xEB9039D0C1A50EC1ULL, 
            0x66610F200BDD7157ULL, 0xEB46E5901804FBC7ULL, 0x3A1457F0E12867EBULL, 0x05A2B1780D496625ULL, 
            0xAA8054AE3917FFE3ULL, 0xD8E75B962755D70EULL, 0xE4D8C46B70CFA4DEULL, 0x2585EAC6C93363D1ULL, 
            0x2677FFBB5E74FC9DULL, 0x62A2ADF9A7E8D2DDULL, 0x64F21A4BC453841CULL, 0x0E26C5D660B1626DULL, 
            0xAA9EDFAA1F1A01E3ULL, 0x1E089A781BBE324FULL, 0xA3FA5BBE5D0110F7ULL, 0x374BA0FD6B3CA633ULL, 
            0xA20378EC98F8FC06ULL, 0xBAC765C31DEC70F0ULL, 0x1D270210D5EAB20BULL, 0x8D07160956BA53F0ULL
        },
        {
            0x081E45D008CD3AE1ULL, 0x8C3D1109594661AEULL, 0xCEC3E4FDFFB77115ULL, 0x351F356CDD57D864ULL, 
            0x2DC3208EDA9E7D8DULL, 0x1238BABBF3A96E32ULL, 0x5A90087690849554ULL, 0x2E01400D3057EE8DULL, 
            0x8E6DF58AAF3EB87CULL, 0x78F786EA0B50865AULL, 0xAD124CD994D9E792ULL, 0x4FB160A420084FE8ULL, 
            0xA301E8ADC3D5DBC7ULL, 0xA43F122B27874E8DULL, 0x3202E28CC1008364ULL, 0xD0E51BC286B4F0FFULL, 
            0x392F2EF81ADBE339ULL, 0x16F4A6BB709D5B75ULL, 0x2E04D483D4FBE71EULL, 0xC79E446BA93692EDULL, 
            0x2FC2C8D1C03F1C84ULL, 0x5F8F2A9865F04B28ULL, 0xE625971CA194B9EFULL, 0x3B14269A3C778494ULL, 
            0x1697BF4079BB959DULL, 0xD579F7A2D6314A0EULL, 0x280C3709E83037D7ULL, 0xD1CE78D7BFE43966ULL, 
            0x06999D9754C54ACDULL, 0x688DDB2309BDBB61ULL, 0xA8A208621872648FULL, 0x917EA08A2ED7031FULL
        }
    },
    {
        {
            0xC0DBAB6AACF77D4FULL, 0xAEB859ADF1AC48B1ULL, 0x17BF48D5A7D9D469ULL, 0xF62ABA8686AC242CULL, 
            0x396A408F789A6006ULL, 0x32AE5C77A504B1EBULL, 0xC10B78076DB22D07ULL, 0x55B983BC53600603ULL, 
            0x771DDD2774DACB5AULL, 0x08466A49ED7C0DCFULL, 0xF001D9EF44E539FAULL, 0xBE433CF22EFCCE66ULL, 
            0x2403405E46E7F20FULL, 0xA84962B829A1027FULL, 0xBF6AB650A5664A00ULL, 0x687053C7ECE6824AULL, 
            0xBD4C663AE7B89AE4ULL, 0x9553364C150C73DEULL, 0x1CF863FFFE2374EBULL, 0xC94480B6CA1A1644ULL, 
            0xD17EC6098AE5C8EEULL, 0x474FAA7821A4F23EULL, 0x6F0BE0FA075477B5ULL, 0xE97F0E9DE4BCDA29ULL, 
            0x14D1D4A8B917AF5CULL, 0x73750E4452261BF5ULL, 0x1C19BC5010879DD7ULL, 0x2F925FECB03FE9AFULL, 
            0x92FDF2EE05DF564CULL, 0xA34303CC317F20A4ULL, 0x724505C7E0CCFC9EULL, 0x453B135B42227DA6ULL
        },
        {
            0x1B686B99227CDDB7ULL, 0x95CEBE8CAAC67BC4ULL, 0x9003204D9B1204DFULL, 0x2BC997BB422DE2A8ULL, 
            0x7132DD4E7ED39752ULL, 0x8DFF34CF72DDDED8ULL, 0xA5BA54264AB45301ULL, 0xB41CDDE59AAE9381ULL, 
            0x39798FBEB05D0561ULL, 0x24C81C07C99F9FD5ULL, 0x8961A6F4FD9D0A85ULL, 0x831A206716854030ULL, 
            0xF365567A04FE9641ULL, 0x5BD8C7B6D5497947ULL, 0x818B0671AF46556DULL, 0xEBD44CBA188463A8ULL, 
            0x487260B3D05B068DULL, 0x8A216E4157EE1A8EULL, 0x318A6FB05EA199FAULL, 0xFA7EBB48BA3C19F8ULL, 
            0x7FCDAFBA4A11C19FULL, 0x52CCAE521B0EA89FULL, 0x67C9E13CE96575B1ULL, 0x84459493C964DF33ULL, 
            0xE9D29FC10DE1FA30ULL, 0x198663A5C6F4B708ULL, 0xB1AF51E3D46CBE84ULL, 0x2D48C74C43DE8116ULL, 
            0x16BF16A528459F6AULL, 0xF62135B65F1F334BULL, 0xAAF600B5E6CA0C68ULL, 0x0E54777AF17C25F0ULL
        },
        {
            0x6E2DE9FBE8919F30ULL, 0x8C920DCC7C0105C3ULL, 0x47DCBD6CA7AFBDB5ULL, 0x1668C29BEF521B31ULL, 
            0x38907EA758907BFDULL, 0x027EB466E8EA9905ULL, 0xDB96B634E90E25C4ULL, 0x0548C2475C19CFA6ULL, 
            0x489034697D4404E1ULL, 0xDAD6B32D80BF3EDBULL, 0x44B8D701D373F4C3ULL, 0xD563DF14E5008510ULL, 
            0x3213CA8AB35BBD35ULL, 0xF4896A408038AE19ULL, 0xD87315DB1DAB98A4ULL, 0x4E3BD85A3CFD9320ULL, 
            0xDA048634A2CEF424ULL, 0x871B5D2E682B128FULL, 0xA2E2A6D02D76A150ULL, 0xCDAC471B885027F6ULL, 
            0x0E293EE975EF63A5ULL, 0x9536A642500F157BULL, 0x2EF49350430EEE5CULL, 0x3CB2BEC4982EF366ULL, 
            0xC211E589BCB49ADCULL, 0x328F335E377EB1E6ULL, 0xF0FECD83C1D32900ULL, 0xA038847A6AAC9DC0ULL, 
            0x33AC97F8A43963CDULL, 0x3CED3B93FB0350EAULL, 0x1FB59735385CE8D3ULL, 0x0737E4E9CA0251E5ULL
        },
        {
            0xE9B2CEE71C159A99ULL, 0xCC18E56B687E0C53ULL, 0x7261C326D163342DULL, 0x14465E0CE8411F2AULL, 
            0x0F4D69F3210BFBD3ULL, 0x5703C12111416AF6ULL, 0x2F9AE82D2166C4B1ULL, 0xDDE072AB5DFEB665ULL, 
            0x03753461927425ACULL, 0x2CB9B22022D2077DULL, 0xA8A5E7EC3596C22CULL, 0x71325995C03F56F8ULL, 
            0xEA5F6B3A5E42E846ULL, 0xB7B44EBD5BB5FBD7ULL, 0x14C3CED1EC8FE111ULL, 0x24CCB0A67D62BB08ULL, 
            0x9580563E6FF568A8ULL, 0x52B8BCF373D0C777ULL, 0x3C8B97A92227C155ULL, 0x261FDEC852FD646BULL, 
            0xD8501C74ADA46F6DULL, 0x11D95501A2EC5C65ULL, 0x010F1F7BE54A343BULL, 0x46190E0831BE6471ULL, 
            0xA39DE0A3D8C9A80DULL, 0xD46118EC07EE348FULL, 0x52BA8C8F0E204EDAULL, 0xCA23DDEC799D8156ULL, 
            0x1AD7662C7427E06EULL, 0x466623F456B03519ULL, 0x486ECCAA45F6672FULL, 0x0E2A028DDB9AB000ULL
        },
        {
            0xEF074E1F05BF6077ULL, 0xFC24AAEE9ABC6A1FULL, 0x8C29C8882AF9C843ULL, 0x1E11DB7651EFB699ULL, 
            0x060CC82B9B4B6098ULL, 0x7D5E04412EC35C6CULL, 0xE9A1624C017FCB74ULL, 0x4959614E48B2FF97ULL, 
            0x6B2A92C4F36AFA3DULL, 0xE2EA2269F44D41B4ULL, 0x1E43E1BECD1A0F33ULL, 0x1D1A7D69D36DD4D4ULL, 
            0x16E68E8B2144890FULL, 0x6F8AD64C52D50F80ULL, 0x794F1D83B177FD10ULL, 0xB7CF19F402CE5E47ULL, 
            0x76B42BEE6A6DA82EULL, 0xD6BC0CDBC379005EULL, 0xEDE11A66FB7D42A5ULL, 0x7767C08B65DB71ADULL, 
            0x8B764D5EAD1ED869ULL, 0x0FE1A6064EAF5C09ULL, 0x84BC4C7271686C44ULL, 0xF65EE393A0A4B87BULL, 
            0x8E60622E508CDE46ULL, 0x6968FE94221FB8EDULL, 0xB24644B7FBE39DCCULL, 0x0509372057BA09E2ULL, 
            0x4C7B9966C0EC5C7FULL, 0xE311B2549E8CC84BULL, 0x6419A71651589660ULL, 0xD6FF634B89ABDF15ULL
        },
        {
            0xB03300469FA21065ULL, 0x8E4602941C389009ULL, 0xC4D98797D22B65F4ULL, 0x6E1B45B4BE6DF3B4ULL, 
            0x54DAC1F7DF00EBF4ULL, 0x42E916DBBEEF5F62ULL, 0x1A576C44E32BDE7FULL, 0x349AC856A336AFB7ULL, 
            0x3B7150D0D54D8B02ULL, 0x14A698486BDDEAD5ULL, 0xC50D6DF4BD4D293AULL, 0x823326520C7BCA46ULL, 
            0x636C34D6010BAE69ULL, 0xD396AF07B0EF086DULL, 0x1301EA59F6E2AEDCULL, 0xD3682EDB63EF100DULL, 
            0xAF89D71359A98A94ULL, 0xF294CE1544E93D41ULL, 0x1FAF1287EB65C638ULL, 0x728790DCD2F6419FULL, 
            0x4C78FAB13A11D8A7ULL, 0xCFDD2F696CAC901DULL, 0x9374C56FB55906DDULL, 0x064D3C6AD088065DULL, 
            0x6703341516F4E286ULL, 0xF1FFC2BA3BE560A1ULL, 0x9B58359C94321640ULL, 0x849CC1EC576E0518ULL, 
            0xFC1648983452BA93ULL, 0x9DBB73B368B50E17ULL, 0xDD33CFE487BEAA29ULL, 0x8D02F46E4A6F70B1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseFConstants = {
    0x900078123B9D1C1EULL,
    0xD654A2BD89796227ULL,
    0xB054DB84E6611AB9ULL,
    0x900078123B9D1C1EULL,
    0xD654A2BD89796227ULL,
    0xB054DB84E6611AB9ULL,
    0x3185B15298146C46ULL,
    0xA561A439E1CCA99DULL,
    0xE9,
    0x93,
    0xB9,
    0xBC,
    0x4F,
    0x51,
    0x05,
    0xFD
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseGSalts = {
    {
        {
            0x4086F25F6CC070EFULL, 0x93523605035208F7ULL, 0xD1472B042F2202B0ULL, 0x92885E6628918E09ULL, 
            0x74D413C5A947A257ULL, 0x2F1636B68BA0F0E1ULL, 0x14A0CE3C349D47D3ULL, 0x451B71BB39F1A459ULL, 
            0x176C2E62580AA53CULL, 0xB2A2FDE7F243DD9AULL, 0x4B41613F688E7454ULL, 0x841C174BA2A47D6BULL, 
            0x1E1E15DE8F25DFAFULL, 0xF54EFEB8E9DBAE87ULL, 0x7B4F2DB89085AE1AULL, 0x699724516E333850ULL, 
            0x9FF489B38A067ABBULL, 0x8F4885526F2A6370ULL, 0xE1A79522EFCF63C9ULL, 0xB2A5DE10FAEE2DBFULL, 
            0x673602A35FC519CAULL, 0xE43D1373EE0ABE0FULL, 0xA55C1DF9B946845FULL, 0x7E46DBB9A19EA617ULL, 
            0xF71298EA8199DE2CULL, 0xFED4196C02CCEC81ULL, 0x03BE7555094CD767ULL, 0x0BA938048C834DFAULL, 
            0x202060C2E3B8F57CULL, 0xF877C1976940A54BULL, 0x1EDA1BEE3F3BBECCULL, 0x8466F07560591D38ULL
        },
        {
            0x5F0D846A427F46E6ULL, 0x74F834A3D880456AULL, 0xFDC07748A96882C6ULL, 0x3BCD8390F5A5A098ULL, 
            0x9D866BE17CF72846ULL, 0x1EACCF70401B0F51ULL, 0xE359528A9CDF02C6ULL, 0xFD58666F9CA3727CULL, 
            0x8A058A2B1FB4C4ACULL, 0xED544DE1E8244C64ULL, 0x114D38BDBAFEC08DULL, 0x2E77DC40B061B7A0ULL, 
            0xCA8A3412D216D425ULL, 0x2A1ECE2014AF9BF5ULL, 0x714635DC58B5D524ULL, 0x00FC22035C8C987CULL, 
            0xD7515FA581429763ULL, 0xAF83BEB85F21ECE5ULL, 0xEF66BC2DF81C0AD6ULL, 0x21A7D894E1AD8EE9ULL, 
            0xFDD500B520B4266DULL, 0x4BB0C5CC5CF26D8CULL, 0xDEA76510F0D254CEULL, 0xE46AC2E3912E6428ULL, 
            0x20E529C7D6BB5283ULL, 0x80880FAA06BD0C0DULL, 0x4873B5F039024DAAULL, 0xCF93CF4701F72969ULL, 
            0x499CF3E8E68D674BULL, 0xC7AB4086F0AA58E9ULL, 0x2DBE354141A2E669ULL, 0xE462B7F70D7261FDULL
        },
        {
            0x5C96E79BC9BB0E3FULL, 0x529268AC5B02148AULL, 0x56E8DA996FDD5C48ULL, 0xFD0C5318E07A3E95ULL, 
            0x74BD9B2C638EC1F2ULL, 0x719C012DFD8B663FULL, 0x9529146C7B6CFAB7ULL, 0xAC9FA2C2F947B034ULL, 
            0x9BFD7AE2B4EE2058ULL, 0x2B2491236045E67CULL, 0x59B05A59B442F750ULL, 0xC1A4757C0D8F5288ULL, 
            0xC141492AB33FC61DULL, 0xE3BFC719DA387808ULL, 0xF8C1D7733384B333ULL, 0x3F0D9163368F8FBCULL, 
            0xF3D95C8E992F7E56ULL, 0x195F7A661B8BDBEBULL, 0x863F8D957B8A906FULL, 0xC2EF6922FE62F14FULL, 
            0x98F329590A7FFCC5ULL, 0x61BA07917B134D6AULL, 0x5F94967ADA49CB08ULL, 0xB490F35B47B15C1FULL, 
            0x7F59173B5EC592F6ULL, 0xA694A6195694BB09ULL, 0x170723FCCDD9B258ULL, 0x35056D7DF6D20B34ULL, 
            0x2F9F5F8601A350CEULL, 0x141EE26CFF2629BBULL, 0xC11D2CB964E93EE3ULL, 0x4E0C3992FA67BD18ULL
        },
        {
            0xED9C1C7C8CBFEAE8ULL, 0x0A12BE44D1378228ULL, 0x5E1D61B537265710ULL, 0xA13F37FDABA4CEA5ULL, 
            0xA9195D78BE29A6CFULL, 0x2F0D04BC2EF86E37ULL, 0x85CEF8CE8FA38626ULL, 0xC032B6A59F597855ULL, 
            0xEB0E043A9176F2F8ULL, 0x885B16A3BE0049C8ULL, 0x4D258DF73BC80182ULL, 0x99248489C5B8AB97ULL, 
            0x9C54DB9F5D29A256ULL, 0x8CC51F023C2750D9ULL, 0x3B88A65C29FE3EC7ULL, 0x94DBA02FB339CBF0ULL, 
            0x923A81FCC2EDF729ULL, 0x3D230CFE4F146679ULL, 0x534F4DAA4E4C482DULL, 0x317D37ED9CCEC890ULL, 
            0x7603A4E51C41F1F9ULL, 0x5FB7B71AC3D3F6E3ULL, 0xDBFF45CBAF4F73FEULL, 0x2CC165919746DAE9ULL, 
            0x0B1237525C576991ULL, 0x54397B0F365C4D07ULL, 0x112CDBFEE1A1343EULL, 0x1DA17C32BEAFAAB9ULL, 
            0x5354B0A32B070D47ULL, 0xD49EA65B94BB905FULL, 0x8B460CC9F3420272ULL, 0x776729E04B120138ULL
        },
        {
            0x45C4E30AF325C721ULL, 0x99B7DAC916616596ULL, 0xF09FD04B48805140ULL, 0x8472151BFE5911CFULL, 
            0x667C3C8F035DF8C2ULL, 0xB003EFF9ABBE0A8FULL, 0x6AE43A18EDB32291ULL, 0x8706078CA2F5FDA5ULL, 
            0x50D8C4DABC0D396AULL, 0xD18D4868659ABC0EULL, 0x430C62E5791DEF01ULL, 0xCF2F1BD3E6C74335ULL, 
            0x2AA8BB4696CDC2F4ULL, 0x7A8F856848225D67ULL, 0x20AAD8574DF2F2BDULL, 0x615001AAB930D9D6ULL, 
            0x9A6621E61E1C6569ULL, 0x5E3025015296B26DULL, 0x2FB0EABC89E605E9ULL, 0x5AA137510D36346FULL, 
            0xE64B8731AAB545F1ULL, 0x996266F4DA72F33DULL, 0xF72886AE4AD19084ULL, 0xB7E4315F48890C18ULL, 
            0xA40F04BBE548D389ULL, 0xDEB12C27DD084394ULL, 0x187085AC5A5B1AA7ULL, 0xA0115F5CA75885EFULL, 
            0x81016378D4758DD6ULL, 0x203A830461E63543ULL, 0x9FFAFE6830ECE42CULL, 0x7A6DB5CA7E2D70A5ULL
        },
        {
            0x328CFF3EA3E5D97BULL, 0x96ECE6FE09753F8EULL, 0x5F312DFAAE724D75ULL, 0xD1AB5E0FF658879BULL, 
            0x742DFCF990C228B4ULL, 0x2F46B5C6F4ABB5A0ULL, 0x06B419A8B6B08891ULL, 0x9E19F1B30B8E41A2ULL, 
            0xF4BBBECA9BB7BEF1ULL, 0x7535261827A50E25ULL, 0x715899F3011BDA7FULL, 0x6F321CA97DCF20D2ULL, 
            0x896044C3056F361FULL, 0x2CCC94E14A36467CULL, 0x55CEA9263B0A65D7ULL, 0x9112A253FA1F0444ULL, 
            0x5DDF9B94B74691C0ULL, 0x0CE5914BCBA1185FULL, 0xF39CBA99ECE1A77EULL, 0xCD8A6F21D5EBE0EEULL, 
            0x1AAF141AD3D4AF2CULL, 0x23F49648E470B155ULL, 0x7DDA9BFFE16A84B1ULL, 0xA68C8114604680C8ULL, 
            0x2BE57AB64921B909ULL, 0x6CB89A81706E5F3DULL, 0x98E200A763341A84ULL, 0x515A68687364DCBEULL, 
            0xBA4CF6EDC95BECFFULL, 0x2403217D86D0C07EULL, 0xC87B7BD21328BC91ULL, 0xF0857C91A432F138ULL
        }
    },
    {
        {
            0x5106B25D35403E4CULL, 0xEEC6C19139726225ULL, 0xA749366F9C772D07ULL, 0xAB4CEBBAAB897F92ULL, 
            0x96E81B82D5E2B84DULL, 0x33653671D07A71E8ULL, 0x9F1F23295EBB06ABULL, 0xAE6B458D102B0B9AULL, 
            0x902A30C5B845CB5BULL, 0x4366B594740C288BULL, 0x77E38A3FF2E0BF3BULL, 0x90721254D0B88EA7ULL, 
            0x3D65E8EAF27878FAULL, 0x9939FA1560DE3E03ULL, 0x1FBE9DDBA6955B81ULL, 0xF732322398AEA4E6ULL, 
            0x6DF6C070F4ED700EULL, 0x53016E4D2353D2C4ULL, 0x29715DFDC699618BULL, 0x63BF7459AE7C0044ULL, 
            0xC0F23BAB7EA913D2ULL, 0x4D8600241F388DC3ULL, 0xBBA062643A5D411EULL, 0xB709E2D7E4A71D04ULL, 
            0x7D2D848E0A3036F9ULL, 0x6ACFDC574C3EC5D0ULL, 0x707154BAB071E32FULL, 0xE07258DC98A8A15FULL, 
            0xFC27653ACE67C62BULL, 0x7F5A7E370DD64FFBULL, 0x0DDC122FE8DEC104ULL, 0x1C4A5C77633F27DBULL
        },
        {
            0x436E613A6A12A46DULL, 0x791FBD9D2FCB1EA5ULL, 0x1167BA448FED41C7ULL, 0x81DBF0474F549ED7ULL, 
            0xB166ECE63A349ED9ULL, 0x947820917F368D65ULL, 0x7FDD1C03BDD0A6E3ULL, 0xCBBCC26D6D4F918FULL, 
            0x5AB6B8C1AD3F7505ULL, 0xD7DCF03F3ADEAD93ULL, 0x1B5596824D4C7C6FULL, 0x9DB44F9FA1691743ULL, 
            0x728FB321BA690E07ULL, 0x4EE26E11511404C1ULL, 0xDEECAA5C331BE156ULL, 0xF37E3B53999A065EULL, 
            0x2F090D9AF3014B8BULL, 0xEF939EAD2690A680ULL, 0xE65EA39A5CD60EFAULL, 0x1DD8713A959F7690ULL, 
            0xB54D2200ECA97971ULL, 0x705AE3C52039F436ULL, 0xAF1CA0B214E86F07ULL, 0x4E0F9D90D5AEB037ULL, 
            0xBF54F98D82740FC6ULL, 0x8FC1F51F945142DBULL, 0x0EA09BA843B47E49ULL, 0xF63A858544049D7CULL, 
            0x5AEB176AC86910C3ULL, 0x17BC7DD362979340ULL, 0xC25807CB350121D9ULL, 0x6EB106271732F083ULL
        },
        {
            0xDF9955BE3C555F2BULL, 0x1A9DC0AAB26CFD29ULL, 0xAB9873B4C32646ACULL, 0xE281876AFC8D2702ULL, 
            0x3A10D275A53F8FE5ULL, 0xA41CDDE48BA1927FULL, 0x2CC7E77FA3216D58ULL, 0x1500D25B9B637FCEULL, 
            0xD2E77CD8D94E3B32ULL, 0x606E4D34086EEAEFULL, 0xB0550A18B0BD118AULL, 0xADADAA996658E980ULL, 
            0x79222A909EFF39BEULL, 0x1F36AE5F3DB2C10FULL, 0x06A9C6ABB0F79269ULL, 0xC0866D1A836EE550ULL, 
            0x52DD8F0A8E8B18FCULL, 0xC510EAE121AC5426ULL, 0x3986700668B80E0DULL, 0xFCCA8EF77A4A629EULL, 
            0xAD7977900B3D1226ULL, 0x8D226CE32A5C63A2ULL, 0xFE81EA82DDA953D3ULL, 0x5E6CD2B299D02D33ULL, 
            0xC6D68DFC94C850EBULL, 0x6E97C630665E5565ULL, 0x1257058E6AFC9DB4ULL, 0x328E66606B052B66ULL, 
            0x00F66923C4872DFBULL, 0x77DB1B048685D323ULL, 0x8A798EBD6EB1964EULL, 0x626B9DEEA82402C4ULL
        },
        {
            0x05822924ACC293F9ULL, 0x4D783C3892068BD1ULL, 0xF2D4123B46A83E49ULL, 0x76A7C1120561C601ULL, 
            0x04F705821A53E745ULL, 0x04F2B37BA4CFE169ULL, 0x7312D620068456B9ULL, 0x7CBBB9221EC62C23ULL, 
            0xE25BC693BEBBBB48ULL, 0xCFC49CBED8856325ULL, 0x66BB98B23CBA9230ULL, 0x11491983C94D4EDAULL, 
            0x7EBF3DFCC5057659ULL, 0x83C2C9C1004D0B74ULL, 0xDB17B423621B6122ULL, 0x5182F790C35C8D58ULL, 
            0x97BCAC8C2BEC1C01ULL, 0x3FD48AC5D5566873ULL, 0x29B5AA48E9E9734FULL, 0x37C364D191BCBBA3ULL, 
            0xCA09202D78A386F2ULL, 0x95145D042BE4031FULL, 0x711B985E8638DFEFULL, 0x5E6A9589A9E786A6ULL, 
            0xE28A5A2024784F5AULL, 0xE9BCD49CDE609CD8ULL, 0x1F40E4004E2F49D3ULL, 0x1E491A6887B0498CULL, 
            0x5F2FDB1AF78BBF13ULL, 0xD51B75742ECF925AULL, 0x9B1329C25AF0768AULL, 0x17845924652BD7A9ULL
        },
        {
            0xB33D53DE352BD298ULL, 0x8762E6345B949403ULL, 0xD4F6292B359BDF42ULL, 0x080BEDF7BBF2D101ULL, 
            0x392637AED7F167A5ULL, 0x8A4CC0095CCDB2A9ULL, 0x14C87DAF4F2C9AADULL, 0x0CE2956D4B1BCE0FULL, 
            0xE9073AC881949535ULL, 0x652B78D8A5DA0414ULL, 0x7337987297C80EAFULL, 0x9A31760C490B158CULL, 
            0x6977BCADE0FF58AAULL, 0x6E06F69AD2568C96ULL, 0xCDBE3D6423043451ULL, 0x89C08F7089E028A1ULL, 
            0x4AAC999E05CD81ECULL, 0xBA9A2D941368862AULL, 0x07E8B51047773E4AULL, 0xB642FB72323C5C0EULL, 
            0x16316300028EB999ULL, 0x666080DA0D226507ULL, 0xA20E7F048DD03A7EULL, 0xAC788529AF6EFF5DULL, 
            0x50181ACA1C9DFAF7ULL, 0x456F99DD235E9BD0ULL, 0x8BAFE494D4E24FC2ULL, 0x16602BE2BA7C1AF3ULL, 
            0x52D27A47F195A6A0ULL, 0xD71ED2A5B3CABE26ULL, 0xDE4A6B4CEA9E29B4ULL, 0xB8048F0ECA007909ULL
        },
        {
            0xAB83D25D1A977876ULL, 0xF0A55FA3E20F46FCULL, 0x6AB6781521642666ULL, 0x9BDB0A537C33CAECULL, 
            0x5ECA4B1E84D8C72FULL, 0x5B0E853A9A0177C6ULL, 0x8686AD1B83B672D4ULL, 0x231186F22718F3BDULL, 
            0x0AEC027CDF597EDAULL, 0xB97FEBC5D5633A5EULL, 0xACB91242219F5F47ULL, 0x26531FF4F5724176ULL, 
            0x96EC73773CB10C17ULL, 0x1F75BA3EC96464D9ULL, 0x4521D3CA92BAAE6CULL, 0xC95EE499D5A65272ULL, 
            0x72C782AC8C688AE0ULL, 0xA744D083903934CAULL, 0xD59E7033E7C47700ULL, 0xFE179A06FDEBF64FULL, 
            0x3EA70FC3F5B0341FULL, 0xB7CB857DAB49E38CULL, 0xF8587EDE0B588665ULL, 0xC407BEEF592E4CD3ULL, 
            0x3BADC7FBE8C24A9AULL, 0x21B943375C886274ULL, 0x94BD2BF2346F0F44ULL, 0x2D715054B371C50DULL, 
            0x382005866B1A0294ULL, 0x3534240F21096B6BULL, 0x6C33DDFC9CB1923BULL, 0xFA58313F5054B427ULL
        }
    },
    {
        {
            0x584EA9CF122C948AULL, 0x1FF0D7B6C748624BULL, 0xC144034F39348D40ULL, 0x8E8D68CD247B8AFBULL, 
            0x90252A2B5E6795F0ULL, 0xEC0D4E2F8F74C797ULL, 0xBA67C66F4D081C39ULL, 0x3E92290479038CCDULL, 
            0x1E76D02B4F897A95ULL, 0xD047B7B51F5DD7C4ULL, 0xD83FFBA2ABBBC951ULL, 0xF0BF3D990CF87AC7ULL, 
            0x3AE76F5BD6B8621FULL, 0x007481D8A928FA60ULL, 0x902CBA3A564B1F91ULL, 0xF0B382ED40D4D9DFULL, 
            0x49F14B3B6B1C749AULL, 0xA8CF7ABD894B6CD7ULL, 0x7BF50D9D9A1D365CULL, 0x7160B2766E8BC859ULL, 
            0xF0441A26428B1C29ULL, 0xA8261522A1482A47ULL, 0xEA591038A7C68A4BULL, 0x42A54EB368D3689FULL, 
            0x274B85057F16C5F4ULL, 0x66F474A14B012769ULL, 0xDD9C10FF75A313CAULL, 0xEBC9F89CAFBC9B7CULL, 
            0xA4CEC601D7AF9318ULL, 0x44702BF136D870D5ULL, 0x865CA7E4C80B2E81ULL, 0x0A8A25DF449BA27EULL
        },
        {
            0xEBDE03E2AE71D859ULL, 0xBA16D3C112D83E20ULL, 0xF31E0968F85678B0ULL, 0x5CDE34661F9632EDULL, 
            0x4F5D4F168135D1D3ULL, 0x61AC47E5E07B14D3ULL, 0x29B3CE2C95E98F17ULL, 0xAC75DA150E881C47ULL, 
            0x23F17C9D3972A85BULL, 0x666FD472F22EB3ECULL, 0x2F28858A5A30E19AULL, 0xAFDFBBD3C3B6A8C1ULL, 
            0x2F81AF1965C96CCFULL, 0xE70EF5E53B1CA0D0ULL, 0xCBFEBCE109CC65CFULL, 0x9570BABA1C14BD0BULL, 
            0x282DA0EB9F03099AULL, 0xD4572DF5DEC8A8C6ULL, 0x1CD0DAC8196BDF5DULL, 0x5CA5F2E2E021721BULL, 
            0x4EF193B21677E391ULL, 0xD7333D5D0B1EDD2FULL, 0x9309586C037E25A3ULL, 0xC1D0226D0611C172ULL, 
            0x17BF03EC390C85C6ULL, 0x94D4E054B1986F43ULL, 0x2E72CDED7206702DULL, 0xE56B3E823D985F3EULL, 
            0x53CCCE7195E55FBFULL, 0x45B7100E123D5C83ULL, 0xD8E8AB8D72E5C4BDULL, 0x29E8E450CEA88555ULL
        },
        {
            0x1843913AD355D62AULL, 0xA5688D37A21020B4ULL, 0x7B18306D3B2D5C7DULL, 0x3C099DB28AA77BD9ULL, 
            0x4E49A99F15A729C0ULL, 0xB19589D1E0BB88ABULL, 0x024355FC86B7ECCFULL, 0x528D1F9CEEC23094ULL, 
            0x69F38E139111C298ULL, 0x191A763CA5563FEEULL, 0xB9BDF43448267705ULL, 0x20F3A3D8C8561EB4ULL, 
            0x0AD95D403D807B29ULL, 0x5CC7EF6E4924CA5FULL, 0x027166F31255EA4DULL, 0x3110B6A3CD9980B6ULL, 
            0xF87B82D74A96F122ULL, 0x457E4B1614BB5F7FULL, 0xD6102DFDC15FCF2DULL, 0x0AD317C3A960FF8DULL, 
            0x1D551C20B43677D8ULL, 0x977323A1C5564E21ULL, 0xE0040CADBED4FB52ULL, 0xAA7E7ABB4C8ECE1DULL, 
            0xBB4477C67788542FULL, 0x78EBCB5879F6460FULL, 0xDFB0DBB50A2142EEULL, 0xC8BFD30D97C81707ULL, 
            0xF441D7CC4982D173ULL, 0xD278038F9A7E4187ULL, 0x75D72B039DA1B2BDULL, 0x7F795EC224111656ULL
        },
        {
            0xDC503734DDAC1E4BULL, 0x04EB0CED69EB293BULL, 0x95A4350F952E5E6AULL, 0xDACFA76AD0897050ULL, 
            0xEBCD2B9BE018D491ULL, 0x246519B4C5390814ULL, 0x4A04AF1E69D2CFC5ULL, 0xEAAF5A6F0DAAAEDBULL, 
            0xE4E4EAB63256F955ULL, 0x98A66B8B3EEDB66AULL, 0xDD50CDB959692527ULL, 0xDCCEB06D58CD7A89ULL, 
            0xE79F61CED27863C2ULL, 0x3BE8D7D0BA3A0694ULL, 0x78DBE4FA605176D3ULL, 0xFBD6375763C49E92ULL, 
            0x4B6B4E0CA4F3326CULL, 0x63B27CA92A4F66E9ULL, 0x920502513B692328ULL, 0x20439400A8EBD8BAULL, 
            0x36ABB1B0AEEBCC37ULL, 0x5F3F0946F8CDD1E8ULL, 0xC1D675C39EBF7377ULL, 0xC8F7CC53B36B65EBULL, 
            0x315694601E43E19FULL, 0x7FCC5BB1400312C0ULL, 0xC13BAC143B5D55D8ULL, 0xAF005811EF9C0F56ULL, 
            0xF8F5E62A8F7B651FULL, 0x861A31B0F96B0F43ULL, 0x4A8DCF24425CA093ULL, 0x6C61CA8379DCE11AULL
        },
        {
            0x9A01B708CF49480FULL, 0x2919B84E07A11F6CULL, 0xE71847D09DED6C73ULL, 0x9B829BA48E98D7DBULL, 
            0x1378A5BE08D1064DULL, 0x281E1788496FD07AULL, 0xDCA334B0AB5726C5ULL, 0x892B589AD68B2A9AULL, 
            0x4F89BF2C9AF391DCULL, 0x9023D149A9CA3781ULL, 0x876BD8DD12368F99ULL, 0xBA6868A64C96284BULL, 
            0x1A28356CE047B2A1ULL, 0xF6F1DDD38D071734ULL, 0xE9F57D3370A73555ULL, 0x856525C61245F5A7ULL, 
            0xA96D4D0A4512587FULL, 0xC3EE29616680A5EBULL, 0x0CCB44B09D97DD18ULL, 0x8F0DD1910B0AADAFULL, 
            0xF1B6B682EEEFFEA2ULL, 0x9A529C69786D1F02ULL, 0xBFF359AF41C6E4EAULL, 0x2395FD4279D9936CULL, 
            0xC4BA40869131CABFULL, 0x4FA4952CA176A76EULL, 0xE5452FF89AD58451ULL, 0x34461E7D94B247A0ULL, 
            0xF8020D8AE4A50C29ULL, 0x7B4D21314B9E809AULL, 0xBF8ED294459276DEULL, 0x9E035BCAD281C3A4ULL
        },
        {
            0x97A63BD8D098B3FCULL, 0x1D1AFABCEFFBFA97ULL, 0x5C3794DE6B2518EEULL, 0xA4D45F64F7435A95ULL, 
            0x7F0A7DE3D3B83132ULL, 0x31C489F7D2F7AA94ULL, 0x96EB16614ED7ECD2ULL, 0x1957CF5F4ADEDF36ULL, 
            0xD090A9A6CE3C8F93ULL, 0xAFD8C598D9AC59C6ULL, 0xF4492C83939B9013ULL, 0x64CF8B9E430CADE6ULL, 
            0xD011E485EAC061D1ULL, 0x00522F579568B44BULL, 0xEEAEBD2D8F740B6BULL, 0x1A3D966D806FBAE1ULL, 
            0x009698B18F6DFED9ULL, 0x70EAE26C0C721BC2ULL, 0x8FE0618458B66B19ULL, 0xA63516D3B8F9EE49ULL, 
            0x5E8C2F4066CF3B84ULL, 0x9DB2F9BB92724C82ULL, 0x71CDBC1E34341DEAULL, 0x451341EC573ED3D9ULL, 
            0xF299C9F1EC356213ULL, 0x99D4E4D1121B7664ULL, 0xA40D29AF0E394E4BULL, 0x95305A372BEFDA61ULL, 
            0x5E94C46D621E2E70ULL, 0x3FB28840A8752BDDULL, 0x79E6F8E1819E8EDDULL, 0xC915D217028922E4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseGConstants = {
    0xFA2CDBF911EA47A0ULL,
    0xE685F056200ADCCBULL,
    0xC23B3A28087AA84FULL,
    0xFA2CDBF911EA47A0ULL,
    0xE685F056200ADCCBULL,
    0xC23B3A28087AA84FULL,
    0xBEA28E77F1E2AE28ULL,
    0x285D7B4FDC5F9728ULL,
    0xC6,
    0x88,
    0x94,
    0x17,
    0x08,
    0x74,
    0x1E,
    0x3A
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseHSalts = {
    {
        {
            0x3F173BAEE732E4DEULL, 0x64DB6093C1FCDD71ULL, 0x1DAF38BAAE7790F4ULL, 0x99CE741C630B08A2ULL, 
            0xA629E3BBEA1AA746ULL, 0x42B2AF63F140CF3EULL, 0xADDEFE5E010FE0D6ULL, 0x7FE6F0EE6A06AAF0ULL, 
            0x11C55E8BEB7D4B60ULL, 0x05C9371A359C9AABULL, 0x6AD7B592BAE2AA20ULL, 0x522B1073B9634901ULL, 
            0xFF7BC6A5C09CF388ULL, 0x2A57A16660B370D7ULL, 0x08B2DB2B17ABD5D7ULL, 0xA18CEA75B10A3F61ULL, 
            0x7E2ACD01FCCDC501ULL, 0xC015B95D689671A1ULL, 0x7E0C5ACD85C79B78ULL, 0x22A85109AF5852E9ULL, 
            0x91A09A7278ACD6B3ULL, 0x237251A392821E35ULL, 0x705BCE51CCA5DB6FULL, 0xBAA89241A71A1962ULL, 
            0xE32A6F05EE02F4DFULL, 0x0B1B269A9C42969CULL, 0x23A7C6CC21F845C0ULL, 0x9B538F0E78A8814AULL, 
            0x9A49EAE0EBB2D859ULL, 0x9C9702E1DE8441FFULL, 0x3BDB7CC54E5EBD1EULL, 0x4E18C14CAF631BFBULL
        },
        {
            0x3B93FB16ECAD6CE8ULL, 0xB443E15AA7D53C5CULL, 0xC185A2D982755596ULL, 0x2D2E09D533C1E228ULL, 
            0x1EAF6B11B4B6F54EULL, 0x0B52F048D7B7DEC0ULL, 0x6F60A477D8EFB5E8ULL, 0xC0B02CA267A21184ULL, 
            0xCCBE1200B762B8B6ULL, 0x0F349C0F7E2EB907ULL, 0x140A2D58278D2FECULL, 0xD8EA4E78AC5E53F6ULL, 
            0x6382F6045C1D94C5ULL, 0xCD7320BA2F889322ULL, 0x5396BF02DF648043ULL, 0xB4568D1756ED9663ULL, 
            0xEEE36A576D7F739AULL, 0xF6B8348A10BE5629ULL, 0x8CFC95A3F79A2CA6ULL, 0x68C90F84C831C817ULL, 
            0x3C3E4CAA14D8EA74ULL, 0x9ECB4B988126E82DULL, 0x69C4631869EE2CEBULL, 0xD15A366D216A7E67ULL, 
            0xD06BEA0A7048EB4AULL, 0xC4642F80A36C10C8ULL, 0x69488194072B56ADULL, 0x007EDAECD0488648ULL, 
            0x832A40CC2EF03724ULL, 0x64C314F2C0EBBA63ULL, 0x248F994FDE95D16BULL, 0xEAE3796F6F3BC7B3ULL
        },
        {
            0x3499CCD6CD9A35C9ULL, 0x704DFE0119745E78ULL, 0x846D98A021FF06A7ULL, 0x56F0672DAD0164C3ULL, 
            0xB890EB25DD5790EEULL, 0x626B7E0512C91A81ULL, 0x6B5074CF8B58820AULL, 0x9C1B381146C3F9D6ULL, 
            0x6AB73AFD3CEC91CAULL, 0xE91DFC841C089271ULL, 0x0873794422009E11ULL, 0xA8EA9A156A30C892ULL, 
            0x5FC6C358DAA5E6B3ULL, 0xCD38F1059CC22E16ULL, 0x7C7D88E12489AEB0ULL, 0x8DD9E2F50A96758CULL, 
            0x3940289893314D62ULL, 0x06BD05BC762430B2ULL, 0xF3BBF66D170EB205ULL, 0xE2798F7F95F81E42ULL, 
            0xB5596C9248D10FD0ULL, 0xBBE1273EBF778FC0ULL, 0xA55EFCDF52A94638ULL, 0x21C47435CE3256C9ULL, 
            0xB48CE1932B40EACAULL, 0xD5D625F7ED5128C7ULL, 0x56F0401CC173E82EULL, 0xFCA6426D770586F5ULL, 
            0x6F4D1551DDA4A2FBULL, 0xF4071A211CFFD328ULL, 0x43BBAC6F30801DC5ULL, 0x576D3DCCA8A2B12EULL
        },
        {
            0x1A1D5545BD7B4A16ULL, 0x7A935519B3A74D37ULL, 0x1ECB1A7E75FAD5CFULL, 0xA9ED1B7AC488738FULL, 
            0x648AF7A76A3E1A32ULL, 0x1682853F79EABB01ULL, 0x16349D8C30C3DBA9ULL, 0xEC8EB58CF96B50C1ULL, 
            0x3A24D621FB7E6960ULL, 0x0EF807FE28903A20ULL, 0x6261B920B0924CF4ULL, 0xD5FADE0204B41D22ULL, 
            0x2AAEBF6A9371F6A9ULL, 0x39F9E8B5AD18B965ULL, 0x14510D4451DA9CF9ULL, 0x9904985C31477153ULL, 
            0xA0B393272F90AA07ULL, 0x576FB881083A6373ULL, 0xC48FB1710F79320BULL, 0x3761652917D11E95ULL, 
            0xD201A25B8E698F8FULL, 0xDDA3F531ED304A37ULL, 0xAFB836D8A56DBCD9ULL, 0x6FDB5EEECD2CEFA4ULL, 
            0xB87C8D16A43534FEULL, 0x7CAB3C74FBD358F4ULL, 0xAFD9719151C5C53BULL, 0xC68DF4A6743E91F3ULL, 
            0xF7B7692BE19B5DE1ULL, 0x0851760718BF618FULL, 0x21AC6F88424D98B3ULL, 0x88533C466B53BF00ULL
        },
        {
            0xB12EE222D2A7868BULL, 0x67C0181B7C363310ULL, 0x1545AA97EF071F5AULL, 0x5A91BAD678A42182ULL, 
            0x035F6B3370C9F53BULL, 0x29C15E4C4DDD2E0EULL, 0x55126ACDBFFF153FULL, 0xBF79D0F13AEDA484ULL, 
            0x36C1E903B4842F35ULL, 0xE9DE1CB58F644C4CULL, 0x0C11D13755F37A44ULL, 0x9FC47D225D95443BULL, 
            0xB2F6CD6B66D8DEDBULL, 0x14775062E9D82E2CULL, 0x9DF0FAEB29C2B0BBULL, 0x65E30C5C6EEADDBDULL, 
            0xF16B94A4BAE73120ULL, 0x11F4DC2272AB56F8ULL, 0xC49531C99A48CE5CULL, 0x7923F42013ADAA82ULL, 
            0xDA0BC451AB36A16EULL, 0xE92F89C084614AE3ULL, 0xFAAF0B7F69B2A4DCULL, 0x60AFCCF51985374CULL, 
            0xC4B9508177E8DBF2ULL, 0xC603D78A1B3CA779ULL, 0x6F12EA2D5394B6BEULL, 0xB1EBFD71FEFE44F6ULL, 
            0xFE1F49B15A7DB780ULL, 0x93DF45F1206BCF0CULL, 0x46C17830A8F53EF8ULL, 0x0F1F2B7ED93FAE48ULL
        },
        {
            0xC2BE33F02A47A978ULL, 0xF34594B185030EB8ULL, 0xEB70C4B5B269EC65ULL, 0xDE5FE0D152046693ULL, 
            0x3F79B873D5E0EAA5ULL, 0xC46A04A1E1D90858ULL, 0x0BA0D57085045C82ULL, 0x84D63809FB3D8905ULL, 
            0x8D7F6D79083E1A12ULL, 0x915707AD591E197BULL, 0xCF8992B6102788F5ULL, 0x626B912510D6972CULL, 
            0xBF55D7B21048B4FCULL, 0x919EE6379FDFCC57ULL, 0x3B0270B631614ADBULL, 0x681D9F687CCEE09FULL, 
            0xA811DAB49E246EEFULL, 0x461E56D6CC7D82E6ULL, 0xBC8AFE48714C3E6AULL, 0xF651E6BC2F528779ULL, 
            0x6106CE21C7144E93ULL, 0xFB5CF172DC2E35BFULL, 0xDC4862A9A49127EAULL, 0xA3FECE161F6B5C9AULL, 
            0x4B7F1E04A6020037ULL, 0x6AB2350FD66175EFULL, 0x98C42611E300831AULL, 0x52230480046D38A4ULL, 
            0xDB3755B8F3081709ULL, 0xAF4116409CC4088EULL, 0xBAF43D6DF833B544ULL, 0x60441624988C74D7ULL
        }
    },
    {
        {
            0x9E9BBED722651A44ULL, 0x3EDC2C1A4B866119ULL, 0xB665AB3B62B7865DULL, 0xCF6E41FCD8163CA3ULL, 
            0x911FCD06F9D051F9ULL, 0x01134B92D9DBF522ULL, 0x8FB5231A5FB96B54ULL, 0x84AD89DEF52FC384ULL, 
            0x8CEF3ACEA5E8E95FULL, 0x0B828C362170DDDDULL, 0x1520EE4E5E46CC45ULL, 0x17AC37440110BBBEULL, 
            0xEE452AABFBA6B591ULL, 0x5CB77EA8A5C0A96BULL, 0x0AC96073AD974821ULL, 0x626302D8C140A130ULL, 
            0x116CE1F04E914B39ULL, 0xDE3D78D267441882ULL, 0x48B339A59A670C61ULL, 0x3F85F88D2EDD3511ULL, 
            0x3727E82FA8085369ULL, 0x1E99368CDFE20F96ULL, 0xCF1891C2E8FB03E8ULL, 0x8CFB445C15D4AACDULL, 
            0x2B700F3041A8D1E2ULL, 0xA0DBBF96CD3A58B3ULL, 0xE2083FC6D81CE4D3ULL, 0xC69B9FEB99F9880DULL, 
            0x2691DEAC7BAF6220ULL, 0xBD8B1C75B886ECD1ULL, 0x06144FBDA644CFC7ULL, 0xD4E22262BBFB28A1ULL
        },
        {
            0xDA90F878B6A58298ULL, 0x449D7C4D1F6752F4ULL, 0x58B1E4BB4701B097ULL, 0x3AF0C7BEB07B51B9ULL, 
            0xB3A4852BBDA8893EULL, 0x591C5DD95957A97BULL, 0xDCDE7540204F2C52ULL, 0xFE0B0E5D37CF911FULL, 
            0x6B325FFF6E37AE45ULL, 0x05B246B9527E6E0EULL, 0xEC44F86BAD0574A8ULL, 0xF787A4E81703771EULL, 
            0xC01F0F6F035994C5ULL, 0x8058F224F5E78BC8ULL, 0xD9124FB1E8230BFBULL, 0x7818DD6014551F4CULL, 
            0x123C821CAE0CA903ULL, 0xF71761FF38EE20AEULL, 0x1A37DEDE290C1549ULL, 0xB4CBF91C96F314F6ULL, 
            0x7EF7A878B3ACAB2BULL, 0xF9742B906D72F7ABULL, 0xF03044DD354AA5CBULL, 0x6F02645438960292ULL, 
            0xCD8EFCF54F8072FCULL, 0xBD38225CE6DF7C76ULL, 0x86CBD00304E0C510ULL, 0x37834ADA412A78B0ULL, 
            0xDE358B00DB07DFE9ULL, 0x335DBFD6D57B5853ULL, 0xB297506CA1A8CDDBULL, 0x567F7CC9157015CFULL
        },
        {
            0xCF5B5EC24EAD71C4ULL, 0xD37D622E3081A3B0ULL, 0xD2C851C8DD2A768CULL, 0x0EA679BEF055BE66ULL, 
            0x3FD4F41591B5CBCDULL, 0x9D27561CCB91C6EBULL, 0x08455CD0645618F4ULL, 0xEC6E124C5A9FD1C3ULL, 
            0xDC733B0DE515BF42ULL, 0x1DB66D07A2D8870FULL, 0x4ABA3CCAD981535BULL, 0x1CF97A673650FA10ULL, 
            0xBE852702A5607CCDULL, 0x5839AFD22F319B55ULL, 0x18B01C77F1F717B0ULL, 0x3FB5AAA71E9F695AULL, 
            0xBB22F3DC0B9C49EBULL, 0x2C2486331BD9045FULL, 0x0C3C0ECE8A53BC29ULL, 0x7EA48D91C80E1CB0ULL, 
            0x8268FF643BB7040EULL, 0xB7FDFE41694AB7AFULL, 0x6DAE54122DC429B1ULL, 0x06DF394D741B3DD6ULL, 
            0x554E02C95678CB94ULL, 0xF6438E1D62C87E3CULL, 0x70259C4DEE91F165ULL, 0x9FECA5ED55A139D0ULL, 
            0xF6FFF14C84110861ULL, 0x6A1FB432F5DDB283ULL, 0x6BB07530AB0933B8ULL, 0x54734FE0E12AADC5ULL
        },
        {
            0xC0A8C11BBDB5BE51ULL, 0xA71037E7096C2DF3ULL, 0x8F7142DAAF7B4176ULL, 0x451AC4120DB87575ULL, 
            0x21625BF5B118B1CFULL, 0x3C4651C4A1CEDB58ULL, 0x2EC626D666B3B7C9ULL, 0x67AE099D43C290AEULL, 
            0xFA9C6FDE211A6E26ULL, 0x586D13399BAEC8FBULL, 0x4F32876A12FDFF31ULL, 0xC67C782175201A58ULL, 
            0x80E0841DA4DC785AULL, 0x6171882FCC1F3303ULL, 0x95E629A337408C0AULL, 0xE167E8B242E103B8ULL, 
            0x5529477AB1203AD6ULL, 0xEF6570FFE8EC0CF8ULL, 0xDA0958D7AC6791DAULL, 0x2FA12F5698AAF806ULL, 
            0xB788EBB7E37122EBULL, 0xA918C7AE140BFF57ULL, 0x3DFC0D2FCF6F8AF0ULL, 0xEC52D1C5720047F1ULL, 
            0x25586E2A475BCE61ULL, 0xC238499860907463ULL, 0xB91F1627F6EA4C9FULL, 0x694D61A24D27AC05ULL, 
            0x667054F9E423F9B9ULL, 0x3565DE951F0C8D2CULL, 0x8D0C4E81B550B33AULL, 0x84D0B11AA2499FB4ULL
        },
        {
            0xC47716D0F77AFDEFULL, 0x72552812DA4F497DULL, 0x86E020FE713C3EA9ULL, 0xBB1C53C37AE78B4EULL, 
            0xC7DBC652EFBB2CA8ULL, 0xFF01DFE2882841DEULL, 0x8A7063DFBE1429BAULL, 0xEEF48D459B77B8EEULL, 
            0xB8CC7C9B0A6FEF6AULL, 0x09BBC9F12A4A6BCAULL, 0x688821CF28B121ACULL, 0x449365EAC71CD7E1ULL, 
            0xE2408E5B99BEF1E2ULL, 0xCA2AA188796710F8ULL, 0xE460F7F236E80BA8ULL, 0x212E9D29DE9A2068ULL, 
            0x852BBED6BF2B12C6ULL, 0x55444188C15CDB40ULL, 0x882A07738DEA6D4AULL, 0x1F2040642CAD1EF5ULL, 
            0xB7944F78A7C04550ULL, 0xE91C0672E39C1D4DULL, 0xA079A3DB9F9FE069ULL, 0x35015B6028E2BD06ULL, 
            0x60A1D2FD070E03B4ULL, 0x6219CF5E0DEC451EULL, 0x46331BC9F7D5CC79ULL, 0x4C9A3F660D002B0FULL, 
            0xA33E886B79DA3B27ULL, 0xD80AD380DD7968D9ULL, 0xBE3F3E41173D667AULL, 0xBE8D5A8C3F0B1258ULL
        },
        {
            0x093C4D85A7EEB059ULL, 0x6629383DE38BCAACULL, 0x55D108C044483C83ULL, 0x936474296D2A3779ULL, 
            0x0F690574A5ABFC8BULL, 0x4DF89E640F8A7B69ULL, 0xDBC20CFCCE6ABA79ULL, 0x0A52FACE3EA2FFE1ULL, 
            0x97B620EDC4BFC4DBULL, 0xD58D10440272DF20ULL, 0x57972BA11B5135C5ULL, 0x38E6E1E2246F0BACULL, 
            0x1219C0204E29B1D2ULL, 0x1C3A0479A66880F1ULL, 0xA0D7E280FF5E4062ULL, 0x890FC1E0D35C63B5ULL, 
            0xD19126221BB47740ULL, 0xF6FF305655492ED8ULL, 0x76955936F6F26CE2ULL, 0x7645242348A5E441ULL, 
            0xF3625D7323FF5AADULL, 0xF7AA20DADFFDC4F4ULL, 0xE80B4B5FAC550074ULL, 0xD5FDAC1AA4C6191BULL, 
            0x984E917ACCD33D6AULL, 0x921427165B4CF518ULL, 0x50EDA801BB2D41E2ULL, 0x83385085A785A7D0ULL, 
            0xDA1067B2A368252DULL, 0x4FB7FF8045D87DBEULL, 0x7F6D18A7B42C02FEULL, 0xB131E4A2C205BF73ULL
        }
    },
    {
        {
            0xF9E308BC71B01266ULL, 0x8853AA18560D1ECEULL, 0xA079D79E008F7754ULL, 0x6038080B7B6CF023ULL, 
            0x06F510B9D79A875BULL, 0xE35032EC265563EAULL, 0x01A8FA7220386F3EULL, 0x9F9E56E6E90EF88BULL, 
            0x56503A465080A1BFULL, 0x5261CEB10AFB7084ULL, 0xC5BFFA69CB250D7EULL, 0xE044C002CEF4FDA4ULL, 
            0x0D48B11C5CA8FAD1ULL, 0xE776A6BF4EC77344ULL, 0xB455C1E744A796B0ULL, 0x5B9DB41C2C36C70FULL, 
            0xCF44E47371A61BADULL, 0x31BE7A0AFDCC70D5ULL, 0xD7C4DA6655FFB79CULL, 0x3496D5221B56DF38ULL, 
            0x63EEF239A8E860F2ULL, 0x836E531639131FC9ULL, 0x5E15195B29D2AE5BULL, 0x29E8CD1BCBE36241ULL, 
            0x6493C9F213C07482ULL, 0xBC5F15E27161364AULL, 0xF37FD17985E0E94FULL, 0x76D7CD32B5B1A730ULL, 
            0x0455B932E1F50919ULL, 0x5B80C235A343951EULL, 0xFC2F3FEAA2E63833ULL, 0xA95E82B6DE366001ULL
        },
        {
            0xC88FD7306561F1FDULL, 0x24FCC02FAC54EC2DULL, 0x90202FA4C25E9E3CULL, 0x8C32780AAC911C8BULL, 
            0x5594EFD3F2710021ULL, 0x200924C8D2091C7FULL, 0x1D61A5DE03F8FDC7ULL, 0xF79C2D778A974CE9ULL, 
            0xBF4A8B7CCCDD7583ULL, 0xB37EB1E85A98E8BDULL, 0xBB8BAE96A4E71FF8ULL, 0x3E12383F5875B51AULL, 
            0xBDB34CD5B746F33EULL, 0x14645E8329B2E9BEULL, 0xD147C042D48419DFULL, 0x8366863AFE9FCD45ULL, 
            0xCDF7AC74DC67C8D0ULL, 0x202334B6824535CEULL, 0xBD621405331E61A8ULL, 0xF1DBDF9D4D2C8A34ULL, 
            0x901F1044AF25D952ULL, 0x752711D689A9B6FBULL, 0xF3554490478677A1ULL, 0xC525C86A2CEA02DCULL, 
            0x33F377535BF33952ULL, 0xB060F328AECE752DULL, 0x0D6DE29618F68680ULL, 0x954F66D181BB699BULL, 
            0x6F3F2BED3E848B41ULL, 0xB3E9E3D83CBA6F7CULL, 0xC09285D580F33E98ULL, 0x66C04AB310B65C07ULL
        },
        {
            0x17FE113AB5EAC597ULL, 0xD222D1487BA03FB7ULL, 0xC36B137C6E4D8C56ULL, 0x6A1D510C3269063AULL, 
            0x02CE7DCB443A7D5DULL, 0xB57650BF8655A4F8ULL, 0x2B0FF9EE9BB7E3CDULL, 0x3C7A66B32FD9224EULL, 
            0x7D81063CBB1DF9D4ULL, 0x2C7B42B0DAEE723BULL, 0xE414DC982AF93FD7ULL, 0xD18533AB9E319DE3ULL, 
            0x6CDC1260B50FD5F1ULL, 0xD9861BB5E13DC366ULL, 0xF2DEC2E9B16CB7E2ULL, 0xE87B64A003D3479AULL, 
            0xE29F09A23638D64CULL, 0xB2BA887DE59E42B3ULL, 0x3347FC848C34C452ULL, 0xC977CB83E7870EC4ULL, 
            0xB314EE7C5145E661ULL, 0x77525273B0FA492DULL, 0xD38F4DCDDB626708ULL, 0xE5497C1933D052A1ULL, 
            0x48BB1A9FBE25569DULL, 0x12DFE4114CAB8D26ULL, 0x47FA50D8466B1A48ULL, 0x88B0138B05C5D563ULL, 
            0xC03B9FCD48DC5C27ULL, 0x2CEEBCA0D8229525ULL, 0xC097F0ABDB41BF2BULL, 0x6B3C216F783AA0F4ULL
        },
        {
            0x7C6596D13A1A7CC6ULL, 0x6BB958DE218E20C3ULL, 0xEDEF4CA28FC7EEC2ULL, 0x4F84F41ADFFAC4CEULL, 
            0x6EE291FD67B13DB0ULL, 0x29F0FA8F794BCFD5ULL, 0xC5E385A1ABD06FDCULL, 0x4680A555EF7CE8CCULL, 
            0x95963A8EF2C74964ULL, 0x50A194FD33D53F4FULL, 0x8B965E262C95A910ULL, 0x91990621138A9CD7ULL, 
            0x455C5140549B3CBEULL, 0x519C111287376DAFULL, 0xDC2201F20ADA9824ULL, 0xDAD0BD260754E03CULL, 
            0x4CA55CEAC8E42664ULL, 0x2A03BB91A63DC257ULL, 0x880CA710726A0E1BULL, 0xF5CE637C3F61B988ULL, 
            0x5B3B6A69551BDB9CULL, 0xE16EE39B7CFC6C88ULL, 0x5D4CABA4E5A67634ULL, 0x402DB45B2C76FE5EULL, 
            0xD5B4D589D288F8F8ULL, 0xA09F81BF5494BBA7ULL, 0x7A33B7481BC35A3CULL, 0x5F3EC3B572BF6861ULL, 
            0x02751E04EC067ADEULL, 0xAF71D334C946055CULL, 0x6B3B41C04593D637ULL, 0xDBB073065229329BULL
        },
        {
            0x2E0E6976CF14EE19ULL, 0xF3A7D07BEC59E310ULL, 0x244CFEFC93B54530ULL, 0x847D006C93E41903ULL, 
            0x04E6AE989D0B571FULL, 0xCFECB946222638B2ULL, 0x7D55ED3875759E03ULL, 0xBAB9CC152458EA6FULL, 
            0x6D522379A2E40AB5ULL, 0x45F05844D258C547ULL, 0x2D4FED35303FF498ULL, 0xDB8815FD624E9ED5ULL, 
            0x5C53ABAF5FE2049DULL, 0x185C9619792C9C64ULL, 0xB4DDA4C8F4CC9296ULL, 0x482AB4D230D5CCF7ULL, 
            0x18341429C4F4A9A2ULL, 0xB545DBF6DBB56D36ULL, 0xAE2262AC4EA17EC9ULL, 0xBEC5DECA25E21D86ULL, 
            0x3CE9BFCFC490EB52ULL, 0xEE3978B57B42ED9FULL, 0xD202EFACEC62599EULL, 0xE546439C43CE9BBBULL, 
            0x9DC7B8145E07F491ULL, 0x37A365F252DF69B7ULL, 0x6765BC1B3FB3D7C2ULL, 0x4C478950D05D13C5ULL, 
            0xE36CAE0E73949716ULL, 0xBA1E011503828C56ULL, 0x66251EE01F3E12D0ULL, 0xB70C8840657E426BULL
        },
        {
            0x2E991E96093FB9E6ULL, 0x441188CB2175E6B9ULL, 0x0ED33BFF53EB8D8BULL, 0x5ECC43EDCE62F6FCULL, 
            0x08FDC1BAAC41826FULL, 0xDB2BE271C54B50F2ULL, 0xBE44EE64A6498482ULL, 0xC62C6AF9E41B47EDULL, 
            0x550E5579591A61F0ULL, 0xCE1D60A10349B5CBULL, 0x3D1C9DD24F671AF7ULL, 0xA74A8B722E0435E7ULL, 
            0x2AE31C798D586859ULL, 0x21B1777E371DBAA3ULL, 0x34878AE8327F7785ULL, 0x0C9A48426F965D50ULL, 
            0x48AEEAC0C1AFB8E7ULL, 0xDE5B2AC8F392B5ACULL, 0x9617FDC3C5932D9CULL, 0xE90FC4A5EEE1F70EULL, 
            0xDD86D41A0C020A31ULL, 0x61E10DA168DE2FB1ULL, 0x5EC6FD263EBB705FULL, 0xFAC263DAE2EB5DFBULL, 
            0x65E5A00F53C14AD9ULL, 0xDA7FCEA0DF9239EAULL, 0x73C14ACA2C203A60ULL, 0xE93C7AB4184D00E3ULL, 
            0x0BF93D4ADAA2B433ULL, 0xA31BB537DC8CE90DULL, 0x909AAB90C4BDDB2DULL, 0x8FFD62C4737F09D4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseHConstants = {
    0x88568DCCD628180BULL,
    0x547105D6456B7C65ULL,
    0xBAF478D75F2EF720ULL,
    0x88568DCCD628180BULL,
    0x547105D6456B7C65ULL,
    0xBAF478D75F2EF720ULL,
    0xA7DE0767200DE6C3ULL,
    0x5EDCB9DE510E7DC0ULL,
    0x60,
    0xFD,
    0x27,
    0x28,
    0x19,
    0xBC,
    0xFF,
    0x8D
};

