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
    std::uint64_t aPrevious = 0x8D873DA99D35AF36ULL; std::uint64_t aIngress = 0xBC347D9792DE1056ULL; std::uint64_t aCarry = 0xBCCD8F1BF486DEB2ULL;

    std::uint64_t aWandererA = 0x96ED75C195962AACULL; std::uint64_t aWandererB = 0x8211132C5FF87D1DULL; std::uint64_t aWandererC = 0xFC5535886B059210ULL; std::uint64_t aWandererD = 0xF70EE44FB2CAF90EULL;
    std::uint64_t aWandererE = 0xD84D5D908088147AULL; std::uint64_t aWandererF = 0xFF564064BCEBE08BULL; std::uint64_t aWandererG = 0xCC3921E561506AABULL; std::uint64_t aWandererH = 0xF027FFFE01C5D190ULL;
    std::uint64_t aWandererI = 0xF512E15AB87443A7ULL; std::uint64_t aWandererJ = 0x8121355255550006ULL; std::uint64_t aWandererK = 0x8DEBEE5A00EC2FFCULL;

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
        aPrevious = 14097298341290790483U;
        aCarry = 15624983468435487984U;
        aWandererA = 15444574853171063885U;
        aWandererB = 12938134618406690167U;
        aWandererC = 10170874601098117491U;
        aWandererD = 14521778211618124446U;
        aWandererE = 14525084352694728520U;
        aWandererF = 17892335698173934916U;
        aWandererG = 15641196562004463507U;
        aWandererH = 14501063113546208062U;
        aWandererI = 10497450110668440079U;
        aWandererJ = 14574589165823370187U;
        aWandererK = 18336103727614813901U;
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
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
    std::uint64_t aPrevious = 0x8163B90752ADDEE7ULL; std::uint64_t aIngress = 0xC2ACD223006591C3ULL; std::uint64_t aCarry = 0x9C6D622C1C49A71DULL;

    std::uint64_t aWandererA = 0x9C24E4A2C64C5CBEULL; std::uint64_t aWandererB = 0xB237CEC843319804ULL; std::uint64_t aWandererC = 0xA725F5F6696685F7ULL; std::uint64_t aWandererD = 0x9A9582774C02717EULL;
    std::uint64_t aWandererE = 0xDFD9876A0A16B731ULL; std::uint64_t aWandererF = 0xFF65FF4AD0B04A95ULL; std::uint64_t aWandererG = 0xECD9DDC6AFD80CD1ULL; std::uint64_t aWandererH = 0xD19A065AD3003281ULL;
    std::uint64_t aWandererI = 0x95ECFB14082C1928ULL; std::uint64_t aWandererJ = 0xCD66AFBD45B712DCULL; std::uint64_t aWandererK = 0xFDBE0BCFFA48DCB9ULL;

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
        aPrevious = 17901851166777834991U;
        aCarry = 17391132670553077135U;
        aWandererA = 13467878909628934949U;
        aWandererB = 12902281379468641201U;
        aWandererC = 9575078287173655013U;
        aWandererD = 12569049115070141654U;
        aWandererE = 17039405384701873442U;
        aWandererF = 12316975418696225174U;
        aWandererG = 10132031332207882711U;
        aWandererH = 13626237283973691935U;
        aWandererI = 16597162234962490840U;
        aWandererJ = 14928776760043649611U;
        aWandererK = 16458064029315731920U;
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
    std::uint64_t aPrevious = 0xEBF14951FA902204ULL;
    std::uint64_t aIngress = 0x817BBB8A42A30CB7ULL;
    std::uint64_t aCarry = 0xCEC475BFB0C90495ULL;

    std::uint64_t aWandererA = 0xAF3ED33CEC9292E5ULL;
    std::uint64_t aWandererB = 0x8E893798FE784826ULL;
    std::uint64_t aWandererC = 0xEBC7C18499BA8E59ULL;
    std::uint64_t aWandererD = 0xD4EC4DE4AA745C71ULL;
    std::uint64_t aWandererE = 0x8DA28AE200699B35ULL;
    std::uint64_t aWandererF = 0xBDF8532145F6B28DULL;
    std::uint64_t aWandererG = 0xA53180B6BBD8E64EULL;
    std::uint64_t aWandererH = 0x905C18B66CC7692AULL;
    std::uint64_t aWandererI = 0xEDEFB925842A2BA0ULL;
    std::uint64_t aWandererJ = 0xCE4EDC8C8ED08CD8ULL;
    std::uint64_t aWandererK = 0x9574F18226A41739ULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneE);
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
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneD);
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    // write to: invest_c, invest_d, work_a, work_b, work_c, work_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, invest_a, invest_b, invest_c, invest_d
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
    // write to: fire_a, fire_b, operation_a, operation_b, operation_c, operation_d
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
    // temp storage: snow_a, snow_b, work_c, work_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_c, snow_d, expand_a, expand_b, expand_c, expand_d
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
    // temp storage: invest_a, invest_b, invest_c, invest_d, fire_a, fire_b, fire_c, fire_d
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
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
    std::uint64_t aPrevious = 0xA088DEA404D16F09ULL; std::uint64_t aIngress = 0x97677E18BC5299ABULL; std::uint64_t aCarry = 0xF30C7F07E5FE12F8ULL;

    std::uint64_t aWandererA = 0xA7B3336DAB3C0DC6ULL; std::uint64_t aWandererB = 0xBABF40A8D22A464AULL; std::uint64_t aWandererC = 0x9C0D208721E0C290ULL; std::uint64_t aWandererD = 0xE623714548C5969DULL;
    std::uint64_t aWandererE = 0x875379E21D0FBC68ULL; std::uint64_t aWandererF = 0xA73E68FE7AFFE8C6ULL; std::uint64_t aWandererG = 0xAD96E80EFFF4A018ULL; std::uint64_t aWandererH = 0xB4C7DD065EC39786ULL;
    std::uint64_t aWandererI = 0x8F23834830EDB842ULL; std::uint64_t aWandererJ = 0x8DBC794DDF4EAC9CULL; std::uint64_t aWandererK = 0x84D03ECE172525B8ULL;

    // [seed]
    {
        aPrevious = 18326091789798273728U;
        aCarry = 18153217889807893835U;
        aWandererA = 14013949684961650523U;
        aWandererB = 16686123131206819559U;
        aWandererC = 17642565950322021085U;
        aWandererD = 15098079952583973098U;
        aWandererE = 18080345413934652478U;
        aWandererF = 18082234229890135869U;
        aWandererG = 13514082232695586694U;
        aWandererH = 10460869113516993254U;
        aWandererI = 15287559810862710896U;
        aWandererJ = 12234080530194749581U;
        aWandererK = 14468686933461187916U;
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
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 0, 1 with offsets 3751U, 3415U, 2283U, 3644U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3751U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3415U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2283U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3644U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 3, 0 with offsets 7600U, 2305U, 7847U, 7745U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7600U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2305U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7847U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7745U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 1, 3 with offsets 4601U, 5107U, 5884U, 4222U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4601U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5107U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5884U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4222U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 2, 2 with offsets 5416U, 4571U, 6586U, 550U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5416U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4571U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6586U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 550U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 1, 3 with offsets 667U, 401U, 29U, 822U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 667U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 401U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 29U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 822U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 3, 1, 0 with offsets 1252U, 1053U, 2030U, 2004U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1252U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1053U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2030U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2004U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 1, 3, 2 with offsets 129U, 1378U, 963U, 300U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 129U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1378U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 963U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 300U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 1, 2, 0 with offsets 1165U, 1415U, 685U, 546U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1165U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1415U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 685U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 546U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 831U, 804U, 1101U, 336U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 831U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 804U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1101U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 336U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 3, 1 with offsets 1610U, 996U, 6612U, 5953U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1610U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 996U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6612U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5953U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 2, 3 with offsets 278U, 179U, 470U, 356U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 278U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 179U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 470U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 356U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 1, 0 with offsets 1342U, 7855U, 2128U, 635U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1342U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7855U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2128U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 635U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 0, 2 with offsets 5819U, 7200U, 6855U, 410U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5819U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7200U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6855U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 410U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5456U, 6757U, 7806U, 2213U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5456U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6757U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7806U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2213U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1690U, 325U, 1698U, 184U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 325U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1698U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 184U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 595U, 943U, 127U, 564U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 595U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 943U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 127U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 564U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1334U, 1091U, 1892U, 440U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1334U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1091U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1892U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 440U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1430U, 551U, 378U, 892U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1430U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 551U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 378U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 892U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 2, 0 [0..<W_KEY]
        // offsets: 1040U, 410U, 556U, 640U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1040U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 410U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 556U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 640U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Golf::kPhaseASalts = {
    {
        {
            0x3374916B463C3304ULL, 0xF9BCAAF2B8B5422FULL, 0xCB1F66730F3054EFULL, 0x5F4B1F0412F2014BULL, 
            0x6FC72B1D00C560F0ULL, 0x074F98DC13D03CB9ULL, 0x6FB1508A6A4C89E5ULL, 0x2624885B3DF7C9ECULL, 
            0x558E396BBB26152DULL, 0x5B1314990A08FC32ULL, 0x59474ADFE5C0DC8CULL, 0x50C90B1FB8C30498ULL, 
            0xFD5AB3DB35129D4EULL, 0xF1B001C22B4D529EULL, 0x8DCF879F5C361C02ULL, 0xB4B3458C3A247F50ULL, 
            0xD522114144FA04F7ULL, 0x8F7FCC21A8A8CAAAULL, 0xEC3428183735A770ULL, 0xDCC2E5064CDA4FCDULL, 
            0xE8D1FE90F067E8F5ULL, 0xB54A554BBDAD7D43ULL, 0x72FDEED4BE611736ULL, 0x6D7FDDF395B53E73ULL, 
            0x420D6C82FC966B1DULL, 0x1241623AC4091918ULL, 0xD62835C47DEAC514ULL, 0x5EFCE37ED8290712ULL, 
            0x12A9B9492A63EB08ULL, 0x80E1AE0FD2940B77ULL, 0x71CDD880F6F8FD2FULL, 0x24FA14BCE8B46B46ULL
        },
        {
            0xFAE70ED2CA1C7501ULL, 0xE706D6CC9B11FE11ULL, 0x63BA7718827EC898ULL, 0xC1848C3EFD2E8139ULL, 
            0x6B825D061E4AF968ULL, 0x9643C99D933ABB8FULL, 0x23F4516D7AD2D2C4ULL, 0x9922BBEC75124290ULL, 
            0x667EE43917FC25A7ULL, 0x0E1A7E09BE25E96AULL, 0xD01C97F23C174268ULL, 0x2D95B64E2B9A54EFULL, 
            0x658A5D947B574EB9ULL, 0x21D0528AFA21AB5DULL, 0xE33E8C5049ABEC68ULL, 0x6DD3A5A46B89CDADULL, 
            0xF10208EC53882607ULL, 0x9928FA0EC06B70EFULL, 0xBB8D85DAC1B33C2FULL, 0x35FB9CD73C72182CULL, 
            0xDEDBD0BEB8EC555FULL, 0x640DA2EBD3E2F618ULL, 0xB2DA70296E3E0268ULL, 0x92511AD0A75B0B0BULL, 
            0x4845CCEB52E212D9ULL, 0x53F9DE73D5BB5614ULL, 0x50BED24F33F45F14ULL, 0x7137BB4FF5FF0629ULL, 
            0x5C82FD397DFEF68DULL, 0xF93A9F5607A8413CULL, 0xCC1AB8569A318AFBULL, 0xD92B20AF9FA13580ULL
        },
        {
            0x42AE26A12BD22C1BULL, 0xCC44A5505B586248ULL, 0x1DA04B97015613F8ULL, 0xD865E1DCCD89640EULL, 
            0x83658EEFA6243497ULL, 0x22417D31E9043BC5ULL, 0x911419633FA74527ULL, 0xA1B80443D2E2FF82ULL, 
            0x584F5BF27050D329ULL, 0xD1DCA81802C85FC4ULL, 0x30B9C4F576F710ACULL, 0x4C0A07C0AEA55422ULL, 
            0xA139B982FD87AFDBULL, 0x15A07146E4EC835BULL, 0x0C1029B70946053FULL, 0xAB05567D1803122BULL, 
            0xE9ED41E109C77DEFULL, 0x5A03CFCE81E25BE0ULL, 0x3FF454FF6B1362FAULL, 0x8FE3EF0B966C88F2ULL, 
            0x3DCFD7CB845D97BCULL, 0xEE9462E55892CF1FULL, 0x58F12BAD80E8CE99ULL, 0xC0E016E723CFF1C0ULL, 
            0xBAC0BBFCEE05811CULL, 0x92ADA0F2AF43B2A8ULL, 0x47657FCBE014EDC3ULL, 0xEC71707584479258ULL, 
            0xA60CAFA6D94D47B5ULL, 0x36549BD81A451D10ULL, 0x76AE1ADE5C80DE0CULL, 0xF97828E0700C6ADBULL
        },
        {
            0xD3883CF8D31ECB4DULL, 0x730CF050B66AE901ULL, 0x22C8EDFDAD2FE51BULL, 0xEE1DD448A26CDF2EULL, 
            0xB435D2B5C61B8E6FULL, 0xB3D6E5980504C858ULL, 0x7180CA83B21AD7F8ULL, 0x011592CE1BE43FFFULL, 
            0x75911748AC60C7E5ULL, 0x5747EF8D4C70B8E5ULL, 0x10003B682BA0213EULL, 0x0B806810F32F5026ULL, 
            0xE3CC766ADF1E4D1CULL, 0x1309BAEF65F2F3D3ULL, 0xCAE78632D72D92EAULL, 0x106F4FE4E4ED7AE8ULL, 
            0xAB12E75F168BC9EAULL, 0x67AFE0670535D3DCULL, 0xDFAAC39C03E9C4A7ULL, 0x4691CB482E7A7A8DULL, 
            0xC5BEA1D83462112AULL, 0x8FAED50100E5DE56ULL, 0xF7CC706BC721B7DAULL, 0x505FF5E9DBF7958DULL, 
            0xB1B63B08A4FF1FAFULL, 0x32F4659D86F2BFA8ULL, 0x875095E8BBAEB305ULL, 0x20E971C952ED07B3ULL, 
            0x655D81BC7B43B173ULL, 0x7631A4F882F580B7ULL, 0xA046ED9AB0C0458BULL, 0x93F025BECB04FAAFULL
        },
        {
            0xD9C01104C73DCC2BULL, 0x66A5D3E5B661B7A1ULL, 0xCAF66646A01F3659ULL, 0xC9673467F17690D6ULL, 
            0xF5E9D2CDE975EDDBULL, 0xE8303F1CAD15D2A8ULL, 0xF1011E05B79F0C52ULL, 0xFAE1B7F31FF04AEDULL, 
            0xA732D28476651359ULL, 0x1153E31F8104D971ULL, 0x81D57F7B0F947234ULL, 0x4B2C4E95B016D70EULL, 
            0xF9A83E6CD50A66E0ULL, 0x48FF7B91CABE60B4ULL, 0xD5DB78946F131C0FULL, 0x69C3590C7768ED89ULL, 
            0xE0E1D1865F7CEC4FULL, 0xE628F3DDBD538C9DULL, 0x49B43A8843196434ULL, 0x0B543DB3B6C9F606ULL, 
            0xBAFDBD5B6AF2CFA1ULL, 0x1224B3B20423A1ABULL, 0xFD6203E98204278AULL, 0x97A74C550F3FCBF5ULL, 
            0xAAD4076FD3308BD7ULL, 0xBEECC1AAF6196B00ULL, 0x750B19648B19399AULL, 0x44742E1AB381393FULL, 
            0xF0A353AE88EDCACFULL, 0x0B1A7BBD7D4EEC2AULL, 0x7C483D7C67675C0EULL, 0xFB07C096C4544C3CULL
        },
        {
            0xA741023CA3839C0DULL, 0x18C63B1B26BBBA9EULL, 0x264EB498680249DCULL, 0xE6697C05A969D3CBULL, 
            0xF5906424C8821A31ULL, 0xC7A5968FD026D8F4ULL, 0x9F38E693115E797CULL, 0x9FA21FC103A7E3B3ULL, 
            0x98D88BD5CE427278ULL, 0x5C4A0BC7EB56EE38ULL, 0x9AA535DCFDB8C739ULL, 0x41669A202E8D4FD8ULL, 
            0x5079A6BBAC6801E6ULL, 0x13186D2A9E37F48DULL, 0x60AB67428C66CE82ULL, 0x127C143CEDE432D4ULL, 
            0x910AF1B9E6F4E798ULL, 0xF511CE98ACD2638DULL, 0xFBD3CA5C4C7497D3ULL, 0x3D629475AD3C24B8ULL, 
            0xA361745E9038D7F6ULL, 0x62E18DB8A5EA2C79ULL, 0x4B20542DADF0CE42ULL, 0xA9169308B8CED054ULL, 
            0xADB6A46166F563F5ULL, 0xF90ACA400B89CDC2ULL, 0xD36883D510AF84EFULL, 0xD2CC0E5476596EF4ULL, 
            0xABFA6CEBCB0690FDULL, 0xBA7F7998DC6E5018ULL, 0x4D53889CD44379DBULL, 0xCC6EAFC308C81929ULL
        }
    },
    {
        {
            0x2B71A18569D82F8BULL, 0x95D3E5F9DCFF4256ULL, 0xBDE6C31729B39494ULL, 0x9DCBF5925972C07FULL, 
            0x82A6059D2121C033ULL, 0x665BA0086A3F005FULL, 0xE1315765D4BA9AD9ULL, 0x7F61E2B5B15F616BULL, 
            0xD55D9FCB73280823ULL, 0x9A9E32B5D9E110DEULL, 0x5CAFBF5099C82A48ULL, 0x9A9F1AB5D70CE124ULL, 
            0x027EA454B2795F24ULL, 0xEFE2D99DE5E8C61EULL, 0x79D699A70587F227ULL, 0x0CD1F627B0589CDDULL, 
            0x56D4F1508E11BBACULL, 0xE8F10B021E94AA1FULL, 0xAEB45A1DCD022A40ULL, 0x76462FD45410AABDULL, 
            0x72C0E861373D5ABAULL, 0xD324C79A6903FAEAULL, 0x9D666793A87BF549ULL, 0xF826D4AF694A0E01ULL, 
            0xD54AA4B9E975140BULL, 0x6DCE52B55A275EE9ULL, 0x4EB132D421E87176ULL, 0x06006CD28CE20CC9ULL, 
            0xA429992C4B6BC16DULL, 0xA2B05C9E92CA2DD2ULL, 0xBB3552D74FD3B2BDULL, 0xB7669BFD10FC1FC1ULL
        },
        {
            0xB5FAC74473304634ULL, 0x23A1A2062A6D4341ULL, 0x95C88D95E541CBBAULL, 0x62366E999316B26FULL, 
            0xF54B861BD5D48EEBULL, 0xDABE18856AE72B1DULL, 0x4B7DAD173130021DULL, 0x6679B99446D01258ULL, 
            0xB75D49F73CA2426FULL, 0x648278879FC1D934ULL, 0x93B58330C0369C06ULL, 0x70BF9369150DF57BULL, 
            0x069609C4E34AC6F1ULL, 0x453EAEF710AA9518ULL, 0x9093A2A96872C200ULL, 0xABC4027D422C4B19ULL, 
            0xBF4658120190DEBBULL, 0x511946E422551C69ULL, 0x6F34D594FFFFD90CULL, 0x849EAB75DA5EB02AULL, 
            0x43FA5BC0C4750B78ULL, 0x54D5FFF471A48DAFULL, 0xD40C54FFE9FF4393ULL, 0x028FA06B56BE9F3EULL, 
            0xC99E01868D13BCD0ULL, 0x703CF8A40E590D07ULL, 0xEDCE4110EFD929C8ULL, 0xA588BA30A100FC61ULL, 
            0x305E6CCF41E23345ULL, 0x4408AF111153DE9AULL, 0xE47C51EEADD44850ULL, 0xEA854A3D33E99AC2ULL
        },
        {
            0x1CC30D8998D22227ULL, 0xF19B59A4E985E1B8ULL, 0x524E21EA7A12FBB0ULL, 0x13AD3456B17DCFEAULL, 
            0xD1DE116CB80C555EULL, 0x5AC41BDD139855ADULL, 0x43174720926110C0ULL, 0x679BDDC5D6FFC39DULL, 
            0xE146FB248DE1F2DDULL, 0x6B3C7A6284615AB5ULL, 0xD759CADE9A10D312ULL, 0x54995ADAB5171088ULL, 
            0xB295DCF9D4B37CDDULL, 0x26A946FE29EC6758ULL, 0xAFA9A66F2F52CCF5ULL, 0xFABDB7A158D5560FULL, 
            0x652940FC545AAD83ULL, 0x268377504E0E3157ULL, 0x85423FF5E62E969BULL, 0x20473152CE3928D5ULL, 
            0xD88F3DC7BE22F838ULL, 0xB2E77AC82C0F0529ULL, 0xA365168884364397ULL, 0x2FA52B865B0E6D32ULL, 
            0x99193F8D3640AC96ULL, 0xA6D0C77727DD21ACULL, 0x382D14CF34B4D812ULL, 0xE4884C6F7B796C30ULL, 
            0x89666C61A464F8C0ULL, 0xEBC03D5836D20BB7ULL, 0x7D131A5AD47E0946ULL, 0xDBC7DA63A41DC562ULL
        },
        {
            0x416EDB5799790D64ULL, 0xCC6FB433ABC60FF8ULL, 0x2CD264B5C8D8315FULL, 0x0B4F5F1DFDD0ADD3ULL, 
            0x39E23C823B27D539ULL, 0x4439F29CEE336521ULL, 0xFED77235FC0E756BULL, 0xD11755336AB9C170ULL, 
            0x935B889C1588E3B6ULL, 0xABB0FE4EF38BAAEBULL, 0x4780D31A92A2BE7BULL, 0x478C520ADD3A2652ULL, 
            0x9FE8F66638FBCDE3ULL, 0xEA937B75C0D23578ULL, 0x29E9DD4A391DD1E7ULL, 0x711E9CB153CF2A82ULL, 
            0xB43E592E8B6DA865ULL, 0xD474EBBE0C2654A8ULL, 0x4245B8CA40B85E7EULL, 0xE912CCB770C349D3ULL, 
            0x50B8AACEBCBDDF34ULL, 0x0EFEA6572EEFB518ULL, 0xC321F11DF4AFADC7ULL, 0x94CC73FA1D422B78ULL, 
            0x81DD06F617239B23ULL, 0xA74D04CD5B13EFC6ULL, 0x1AEFE1FA2BDE454DULL, 0x8CA072440E412A51ULL, 
            0xB026CFFB38E58A62ULL, 0x7FFEEFC4F33FBA6CULL, 0xCFCBC86EFBE4EBA1ULL, 0x859882EA379D983EULL
        },
        {
            0x21691ABD05856C19ULL, 0x404524A880342C37ULL, 0x4397F8FD1100B6B4ULL, 0x79F1C12A96774926ULL, 
            0x70B0A6B133E516C0ULL, 0xBCBBCF7A2691738EULL, 0x2A8AC55DC0B00A11ULL, 0x4D68B1F29722ED23ULL, 
            0x050050462181D554ULL, 0x682544CFB3B8F8B6ULL, 0xFAC4055B20FE6002ULL, 0xF4B33E12216F724EULL, 
            0x6C9650F64636AB30ULL, 0x6912F3B15D2445C0ULL, 0x8D3D124AB3CA89EDULL, 0x287B3D9D6E579E4BULL, 
            0x5EFD672785BA4137ULL, 0x3F51CF7C30FF0C51ULL, 0xAE85BE47FCE26FF3ULL, 0x7E3A651CEFF3A768ULL, 
            0x077719EE99BA3003ULL, 0x8756D0A1501CD4AAULL, 0xC76B8BA797123963ULL, 0x422E222B6C853E30ULL, 
            0xC6540F80C331D7BEULL, 0xCC1DD18D05D8B5E5ULL, 0x10C30B14D322BF43ULL, 0xF43FE5AA623F0303ULL, 
            0x7AF67E3FEF120F72ULL, 0x5B8B514F70E35110ULL, 0xFA4EB2392693A0EEULL, 0x38C48F2711074B50ULL
        },
        {
            0xB46C778CDCBC194CULL, 0x903CFA6F7DBB30DCULL, 0x54D4D12B7D152317ULL, 0x02D15E8F7F4D9B9AULL, 
            0x2F137F108DC28B9BULL, 0xFE83CBFC1348C439ULL, 0x4496DA387AFED315ULL, 0xDD766AD18E57D2FDULL, 
            0x149D175FF30F4C93ULL, 0x9C4492B130CA7401ULL, 0x8B984BD6E20B24D2ULL, 0xC1E84CD53D24AC13ULL, 
            0x48AE4BE5F4A38C6DULL, 0xB7F21EF51C73E4EEULL, 0x7976190C8BF13084ULL, 0x5DA8F905EE8BECDBULL, 
            0x520C42256448909CULL, 0xC7D377D4AB9AD2FFULL, 0x6FAC89320F7DD982ULL, 0x0888C55D7F8C6D4AULL, 
            0x802E2D6BC56FC48CULL, 0x02EE1372A2C1BB11ULL, 0xEE3AACC11C225966ULL, 0x9C371F8631735F9FULL, 
            0xF1E54FFF66A5C2B8ULL, 0xE5D353962244A895ULL, 0x321D6B413E0EC90EULL, 0xFAFCB99A9D245F7FULL, 
            0xEF70076CE9BD1BF1ULL, 0x8F184B33CF0DC0CDULL, 0xE1B5FA8871EBC089ULL, 0xE824C152CA5CDCE9ULL
        }
    },
    {
        {
            0xC2341D9CC5F33C03ULL, 0x207B49008E8D7A47ULL, 0x57B58748749CC6A5ULL, 0xFCB50A5712AD31FCULL, 
            0x9D40C9742F669A68ULL, 0x73276320D56F914DULL, 0x02A92A06C1034A64ULL, 0x11F1005402D3DEBBULL, 
            0xE8C744BA6B757151ULL, 0x1AB52C10E7E6D5AAULL, 0x79A3140B73D4C27EULL, 0x499667E0252C7A0AULL, 
            0x48152CE6484873FEULL, 0xA2206F95DE7ABA3EULL, 0xF071FFFEF0E1892DULL, 0xE952F69A543275D7ULL, 
            0x58DAB9DCBFC1D71DULL, 0xA7E77A5AF1E43252ULL, 0xF3EE11372E95D5F1ULL, 0xC6C8A54D71C0C77BULL, 
            0x68E60143A27F62BAULL, 0xB0BF880030E3D104ULL, 0x6EB84C8F1F501D9AULL, 0xF5F3E24990348CD0ULL, 
            0xE48D0C912BBA1F46ULL, 0x83EE216D03725107ULL, 0x2814971FA9F9D322ULL, 0xC88077688F486985ULL, 
            0xB364E032A3173422ULL, 0xC1152957667382E9ULL, 0xC8D6793EE11D1657ULL, 0xC0F1F142E15DABBFULL
        },
        {
            0x537FE7FFC9863877ULL, 0x08059BA7BD4167C2ULL, 0xFDC93C0FAF18771BULL, 0x3F388BAB96D90EB3ULL, 
            0xBAF3B4494600EF5FULL, 0xB09AFA75FEDCFA65ULL, 0xEAA8DE6A4BC41367ULL, 0x82D45FBA189180AEULL, 
            0x625DCA63B0F38D03ULL, 0x927A3EDF3C917125ULL, 0x992ECCD30FB41849ULL, 0x09BE7AC5D7EC4918ULL, 
            0xFE94E2B82C711CF7ULL, 0x30DA59D6DCCD3ADAULL, 0x2FB4EC1CAA73C18FULL, 0x20B7E5F10BC3267CULL, 
            0x059453D5CA09B939ULL, 0xA1BADD17078B6329ULL, 0xEBED5D5489331CEDULL, 0xD57A3B04FE98C8FEULL, 
            0x52C0CCD42297048EULL, 0x12A96356A9D14FDAULL, 0xFBBE1F5B8ADFB525ULL, 0xBE1BE4AEE5DCBBA0ULL, 
            0xD491EE6F5BC4F688ULL, 0xB42BDA9990096EE7ULL, 0xD846A3FAC05097E6ULL, 0xD05DCC40476F1B66ULL, 
            0x26C255C0565DD67DULL, 0xFA873A46B5EAB3CEULL, 0xA5D5C4FBD561A7A5ULL, 0x17F665F782F095FEULL
        },
        {
            0xC5F4AB0B2460FFA9ULL, 0x53203D2D631FA704ULL, 0x93C496C6B5C5603EULL, 0x8E21E892192BEDE5ULL, 
            0x568C7AAAF2C44473ULL, 0x094BE861064ECB08ULL, 0x3E238D12EE6DA839ULL, 0xB9874E70A58B2B1AULL, 
            0x93D54FE51391CD67ULL, 0x90037F47D7A65EFFULL, 0x53FFF7195F351FDCULL, 0x18C706992621F1A1ULL, 
            0x7720AA37599404D6ULL, 0x9C94C2239DAA5630ULL, 0x07E02D301E262ABFULL, 0xB5586CE1F2690D98ULL, 
            0x76C8A7122B4E43C0ULL, 0xA00DA474414CC2F6ULL, 0x44D8C59940A04D6AULL, 0x5541ECB4BC657462ULL, 
            0xE05D8AFA8723FA90ULL, 0x277F58D01A0FA66AULL, 0x9B46A3479CA31C9EULL, 0xF1FC14DB275F6192ULL, 
            0x85478489B41C4D1CULL, 0x4861071BDD4D2D04ULL, 0xE31B9A23ED049468ULL, 0x6CA2088404047271ULL, 
            0xDCA1550D8D8FB713ULL, 0x97B5C7CC04A47B8CULL, 0xAA4D69BD3D7DD61DULL, 0x390E091FBBC5E0E8ULL
        },
        {
            0xA193A9CD88D5FECCULL, 0x03E38AB15959676BULL, 0xB70DC5871BF74703ULL, 0x53CFB6639A7A5C2EULL, 
            0x05D742D7537FEFB1ULL, 0xE9C52AA8C1A66014ULL, 0xA2D656F253C7F84DULL, 0xF3DA90531DF5D5D3ULL, 
            0x9A1E2A8977506E6BULL, 0x69510B4DB06FBAFEULL, 0x7F31FA7F222756AFULL, 0x2C344E956AF13777ULL, 
            0xCA297B1B8635DB27ULL, 0xDDBB0F13CDA98DB5ULL, 0x2B286A50D8D7F4ECULL, 0xC32E4A7C9FE47F08ULL, 
            0xAF08430052DDB3CFULL, 0x68149539BA779F26ULL, 0x1084352659E83097ULL, 0x4B04A2F190E30604ULL, 
            0xA9A90610DA89A119ULL, 0x11F945D218481F94ULL, 0xDCCCA52408A4DE68ULL, 0x7033BB75A4E96F47ULL, 
            0x838B675386663C46ULL, 0x07D28DB0D0C1DB71ULL, 0x140A118621CA2F57ULL, 0x1004622A455228C2ULL, 
            0xB1F459B7B0C7D00AULL, 0x3F0E64C3D8AAF54AULL, 0xDF3EB03C091BCF27ULL, 0x57D44B8DE4A3AC8FULL
        },
        {
            0x042A603B7C05AE3AULL, 0x5FF1293B61E1B203ULL, 0x60DD0EAF85EBAA1FULL, 0x650BC4CA0C957D6AULL, 
            0xC904B3154088E011ULL, 0x7A66163F16A1CAD6ULL, 0x003A078A1FFD753CULL, 0x06CABBD3A3DD37ABULL, 
            0x26A895DB6B9D5C75ULL, 0x23B2B4611CEE5883ULL, 0x02E6D40DD0D4D020ULL, 0xBBF643D0543D7C00ULL, 
            0x320F196067034288ULL, 0x5E08D5BEA86D011DULL, 0xAFA924B4A643ECF9ULL, 0xB2F8EEDBE0427445ULL, 
            0xD9A8BF555A0DCEEEULL, 0xFBB9FB0615A4EAB3ULL, 0x0A2F03232C496298ULL, 0x1AA62D9BC2383DB7ULL, 
            0x17883BB1C7240246ULL, 0x61344B4D13FA2970ULL, 0xF93E4CFECE4702A6ULL, 0xB4EEC11E4ACC390BULL, 
            0xAB012C196C394F4BULL, 0x4646FA8E95974A95ULL, 0x823A3A2ED6FF3046ULL, 0x6C132C23EA08854AULL, 
            0x8BEAD74664E40B72ULL, 0xDA24D9E9E71CCAABULL, 0x113F13B8B3E97F46ULL, 0x3FEACCD3B74665A8ULL
        },
        {
            0xF82C9D1DD387D117ULL, 0xF26408D9696288FFULL, 0x58C0B54EEB21834DULL, 0xC5A73A1C03BB9201ULL, 
            0x472C028237006CB8ULL, 0x805BBAD967247166ULL, 0x7BD7FF803BD3FBBDULL, 0x22A8071C3E689656ULL, 
            0xCFD61F649C4AD38DULL, 0xEA2374AB8CC87F21ULL, 0xA455CA4BB31E8719ULL, 0xB958B7BF8B6B4A43ULL, 
            0xC618C8A6084BB7F7ULL, 0x995DA044ABC2C1DDULL, 0xD4E9A71244F14BA3ULL, 0xF88F8B2977AF75C2ULL, 
            0x30EB794B9DCE8C5AULL, 0x169A67D268016D32ULL, 0x2F988280B9D42F4EULL, 0xE0FCADCF93BEF379ULL, 
            0x44BF46B7663A50C1ULL, 0x2E53BB7A47D866C3ULL, 0xD982122A84762F9EULL, 0x58256C9A578516A2ULL, 
            0x20BBB1385B32B6E6ULL, 0x47B9A7A2295AE988ULL, 0xB7AF1B81FE5A0E02ULL, 0x3A0D5E866286FF97ULL, 
            0xE55621349B2CD7C2ULL, 0x75EEDE85753A6177ULL, 0xDFB03A45D5E04C5BULL, 0xD571EAD60B5DA66FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseAConstants = {
    0x6B27BA7FB3DD266FULL,
    0xAE24CF88D1B3829EULL,
    0x1F3ED72BCE38658EULL,
    0x6B27BA7FB3DD266FULL,
    0xAE24CF88D1B3829EULL,
    0x1F3ED72BCE38658EULL,
    0xCE61E580CD153E8CULL,
    0x188E9F71A02C1427ULL,
    0x2C,
    0x29,
    0xA0,
    0xAB,
    0x8F,
    0xAD,
    0x11,
    0xDE
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseBSalts = {
    {
        {
            0x1093D01AD214CBC3ULL, 0x21F5712A1BC0D0A7ULL, 0xB26C5DEACEC50A6EULL, 0x774F10212FBEC610ULL, 
            0xFB385922FD5630E2ULL, 0xB50D424232E8E18EULL, 0xE4A8D3579AECB8C8ULL, 0x41830598B876B57AULL, 
            0x6D89A5964181401BULL, 0xF7CA2760A39D25ECULL, 0x12485770F7C770C2ULL, 0x7066FF72BB6C0C7FULL, 
            0x176388AFEABB1FF8ULL, 0x1CDB7226C551A3BFULL, 0x74F8F5ECBE6EF567ULL, 0x2BB8CC589F2DEABCULL, 
            0x469AEEDF142E6051ULL, 0xE44F805D59F4DAE5ULL, 0x4E9E6F3A751ED706ULL, 0x65845B4083E8F8EFULL, 
            0x8FC6C3A6CFEEB7ADULL, 0x345A9D27218F7669ULL, 0x6FD6209EE492EB12ULL, 0x1DBF27905D048C77ULL, 
            0x2A47D5C5E5044C6FULL, 0x35590AC31A1CF006ULL, 0x7C014613A6DE5AA3ULL, 0x64FE951B9A85167BULL, 
            0x4AF41BF497D5263DULL, 0x94903C047983961DULL, 0x7EBD9D306FD7714FULL, 0x75288DF1A138CDD1ULL
        },
        {
            0xC95B7918BFEB631CULL, 0x467BFA686DE8FDDEULL, 0x0F22EE7400ED78C9ULL, 0xA54ACB8DD39BB638ULL, 
            0x2EC4A81B18155083ULL, 0x69B19F82E40FF2AFULL, 0x4C3D0655CD7F0216ULL, 0x0564E4DF6F1C2FCBULL, 
            0x54D138F43B00E6DEULL, 0x838FBF2566ED188DULL, 0x6CB7D341F717DCD9ULL, 0xD3959141CA8A5B79ULL, 
            0xBA976FC280418231ULL, 0x41A14DA83D7C3664ULL, 0xEDECC404D8CF94A0ULL, 0xD9BE673EB778E151ULL, 
            0xC1AFC02488CBD5AEULL, 0x8C37D9D46832AA53ULL, 0x5972351D0B0966E6ULL, 0xB9AAF19291A0CA73ULL, 
            0x114FA967D81B0C0DULL, 0xC41D6A102BAE1E39ULL, 0x92ABEFA65260193DULL, 0x11D27B80FF0BC5E0ULL, 
            0x3B16C2664416FABFULL, 0xD069E35653116116ULL, 0x0B3D561A27F9C264ULL, 0x76855FEE7932EF33ULL, 
            0x100D0DA302E31B32ULL, 0x6672C6A6D06A1B43ULL, 0x3038A2A481B6DCFCULL, 0xA2DA3608DF36D912ULL
        },
        {
            0x1798C0A3E6887B9BULL, 0x9D5A721ECA789D90ULL, 0x803E3C9C58E2D57FULL, 0x369A4CCBCF82EEDBULL, 
            0x6DA191E84E3C8712ULL, 0xB3C16EB267D6A189ULL, 0xCBABC99DD0B1A732ULL, 0xF107C5F08A7B3670ULL, 
            0x321136ED146284F7ULL, 0x9E5FEC9B26B66013ULL, 0x9F2995027C144C51ULL, 0x8647D3D5AB274EE2ULL, 
            0x4A00002E5561A77EULL, 0x9806FE67638DD292ULL, 0x8FF13A0DDB945E31ULL, 0x8CECBEA8262A34A1ULL, 
            0x702EA5F2187D0424ULL, 0xBE4A64983AE476F0ULL, 0x2A2CFA3F74F8E0A6ULL, 0x3E011C2AA0CFE7D0ULL, 
            0xB210CF48ACB6A448ULL, 0xD2B353318B6A2AF2ULL, 0x91A9505846A87906ULL, 0x598FE38668ECF90AULL, 
            0xAFD3C5BD5CF4C801ULL, 0x5FE9C67DD0294717ULL, 0x1EBE95648D6615C8ULL, 0x3ECE75C1BE7681EEULL, 
            0xFED74AAD412F0567ULL, 0x7F947B0B5DC094A6ULL, 0xC0B039DB9240C1FFULL, 0xD6C14E7E240731A2ULL
        },
        {
            0xA84A50BB4E0B1E74ULL, 0xD46118A893106758ULL, 0x89632E4306F5259FULL, 0x58C4DD0AA6066173ULL, 
            0x728BAE1D4F6265FDULL, 0x45BE3129B73360BCULL, 0x42E7C02DBB42A186ULL, 0xF9909B6074724DABULL, 
            0xF0207D756A667893ULL, 0xBD572DE32FDE9D30ULL, 0x8198210FCB64BA38ULL, 0xBB56FB88243BDB7DULL, 
            0xD4C79BD6FD35CE5CULL, 0xBD0AE73D6D587297ULL, 0xB1A30FB18F848B4FULL, 0x00E7D8A647512BE3ULL, 
            0xA9B6B43B9FC17D44ULL, 0x67CA0BC21CBB9B64ULL, 0x25D0AC33A530AE8CULL, 0x3ABBB7FB7AB50F6BULL, 
            0x4DE7C7BCF4872E57ULL, 0x8F19F7BBDA881EE0ULL, 0x33BC927C79616189ULL, 0x9AFC69F7DE9A9D62ULL, 
            0x8F3B467D2A33F24FULL, 0xEF40295F0B39F2ABULL, 0x0D6169AA59A37A13ULL, 0xF813CDD4C0C4BC3CULL, 
            0xCBB28F3225F5B94CULL, 0x10EFC2A21A221561ULL, 0x24E234D2A860F85FULL, 0x845515034B004689ULL
        },
        {
            0xD9A724B30F5E6F3EULL, 0x29E4F87D88EA5AC9ULL, 0x8F43875AA189D376ULL, 0x6C1C56496727C381ULL, 
            0x76B7BE39893505F6ULL, 0x181C62989CD25319ULL, 0xEA51CDDB4023A3E8ULL, 0xAF68EC8C864EB4E1ULL, 
            0x6D0FC4A5C788A175ULL, 0xBA5E71D0EC457560ULL, 0xFC4E148EA97EB975ULL, 0x27F6E66567C21171ULL, 
            0xF4F01E09811E1A4AULL, 0x441D10F01781300CULL, 0x8E2422639F288D68ULL, 0xA9C71809F3796CCBULL, 
            0xF7B8281C82555031ULL, 0x8D9C6D70479C73C2ULL, 0xD71B27AA1834925EULL, 0xD007A0C129DBF9FFULL, 
            0x7A1F4DAE0F327BDCULL, 0xF11CA1E98023B0A2ULL, 0x32029583071EE5B6ULL, 0x8698074B8805493FULL, 
            0x9C37766FDF23DBB6ULL, 0x5AC4825DB55EA98CULL, 0xF2C6A31490007FC4ULL, 0xA483E706222C89E7ULL, 
            0xB8F320AEF958AB45ULL, 0x9BBA8ED6F89D25D5ULL, 0xA7D0AD918B2390ADULL, 0xABF74D7002EEBFF3ULL
        },
        {
            0x5512F59DA5088EE5ULL, 0x2DD3360889C2E713ULL, 0xB431F50BDD7FE47EULL, 0xE17D4BB7F1EF7D3EULL, 
            0x3461F7EF61C3B36BULL, 0x0D2C2C2AC4BA726DULL, 0x89DA626949042322ULL, 0x98EBC2F940DD3BA5ULL, 
            0x59B153D54CA62BDFULL, 0x22EB0C1C3BC86F55ULL, 0x9FEA792D06E812A7ULL, 0x219E604478463C82ULL, 
            0x29AC88BDE10F3E8DULL, 0x94ED8ABBECA37C1AULL, 0x927830A4E2F6C4DAULL, 0xECA0B8B627625236ULL, 
            0x149AAFF85C9B4041ULL, 0xB370DFE157FBF56DULL, 0x192840C0FF4DF5CAULL, 0xC6A9EC8AE7AD5FD5ULL, 
            0x4DF0C229DFB3D170ULL, 0x2B0CFBA1C9AA31B6ULL, 0xD81ADF36C8900844ULL, 0xE76C397EEEE6341DULL, 
            0x816893569F05A353ULL, 0x8CF31E52CB3526E7ULL, 0xFB6693583CD183C4ULL, 0x301812D648803FE8ULL, 
            0x32D4F3F14D35FB08ULL, 0x09DBA921438F121EULL, 0xAC506F9780E3CBB1ULL, 0x80E3E6D0B14359DDULL
        }
    },
    {
        {
            0x94BC9503269360D5ULL, 0xFCEDCE8156C43C35ULL, 0xEC1F5DAE8788D475ULL, 0x6E486E86E39CFB11ULL, 
            0x71E263338D517A4DULL, 0x905A1D2615A3E097ULL, 0x69F0E539576CDE94ULL, 0x3C50B2CB0B62794FULL, 
            0xB03646873C2C5E63ULL, 0xE9A91D8E7DB750FCULL, 0x873060B41D7402FDULL, 0x64E7A2A9DE57D303ULL, 
            0x5D99C8C9337EB3B4ULL, 0xE4204AC3B71CEA04ULL, 0xB41D16FFEC609FF0ULL, 0x11DECFA4934BBDB8ULL, 
            0x7BEF7D35F30A2004ULL, 0x38B3C33C31422C4DULL, 0xA684A6CF0433CB97ULL, 0x1F5E473FB665F6E3ULL, 
            0x9535ECECB869195CULL, 0x6E52788CF51FF63FULL, 0x8CF503AB3F0EEE76ULL, 0xF69FFB8958DF8BF8ULL, 
            0x21425382C5DF0106ULL, 0xA4EE3136FB0D88D5ULL, 0x18FAA4022EB76F27ULL, 0x7F1E779C62B9D19FULL, 
            0xD5FC0BC9C7523EC6ULL, 0x65940008F69DD9D3ULL, 0x36C476445D818698ULL, 0xEB106A969753FFAAULL
        },
        {
            0x8FDDA96F72248FF9ULL, 0xB16F1C71DCAA12B3ULL, 0x440B891CD15A7E06ULL, 0xB7CE4F41F936467EULL, 
            0xC410DB16A3E3BAACULL, 0x3A957395A15223E6ULL, 0x4C78F40CC34D547AULL, 0x277D2564D51576FBULL, 
            0x64820DEC8EE3537FULL, 0x9477D686C72031F0ULL, 0xC757120C71C7BAD7ULL, 0xD8B68C93CCB37852ULL, 
            0x5C6DCFBFE53FAFA9ULL, 0xE82A383AAAF6D77EULL, 0x6A46ABEB4FEFCB6BULL, 0x3DF9844F17EFF582ULL, 
            0x97F929496EC7F2DAULL, 0x9526336F2C08A189ULL, 0x2047B4786942404DULL, 0x1FA7B9DBF9B0595DULL, 
            0x4F7643C3B1459B7CULL, 0x1F7EA59BCFC2D613ULL, 0xEB779C2509942D65ULL, 0xB99A6C53B318274EULL, 
            0x9E2D81B2ABBB8645ULL, 0x276CC16C309F5605ULL, 0xA87EF73E1ED53B34ULL, 0x76CCDB7C870185E4ULL, 
            0xA7C60E6607260750ULL, 0x150E54E2BE1811ECULL, 0xA0B896724EE39AB4ULL, 0xE4625BD789E9E8ECULL
        },
        {
            0xB2555EEB0750B454ULL, 0x3A83B4BB6686660AULL, 0x64680F0AA3A4344CULL, 0xD96B308FB65489B7ULL, 
            0x9E9CD3DF73C3D210ULL, 0x492917A9C2FD5143ULL, 0x781B3A3188118F91ULL, 0x551607ACBCAF542DULL, 
            0xAE4DD1BB22EA6DC7ULL, 0x6939B72031628578ULL, 0x03459A763FFA9A54ULL, 0x7375A7236ABECB85ULL, 
            0x5BE38D4A208666A9ULL, 0xA9DD9855CEAA4396ULL, 0xE8663EFF315774CEULL, 0x8B7B758CDAE1D537ULL, 
            0xD76C68B6B7203222ULL, 0xB4A62F79E82ED791ULL, 0xEE5577145E66F2B2ULL, 0x7B2DFA0C471B4DE5ULL, 
            0xF82ACDE60BDC60A3ULL, 0x3C6D6B7A364DEA40ULL, 0x3C8B2B4C3B9E813AULL, 0xA852C03D70DE0C4DULL, 
            0x34089B20C108E183ULL, 0x80F409F346986A02ULL, 0x71D65A9F91BCBB31ULL, 0xB950E6B60C9C1CD6ULL, 
            0x7D6A3C3B16E2D3CDULL, 0xE94A65B3919C1AEFULL, 0x2AC8CB279340DDEBULL, 0xA701ABB4D9D9B5ABULL
        },
        {
            0x4C6884EF6D61A50EULL, 0xF1E42082FFF9E354ULL, 0x9EE81CFD30CD3967ULL, 0xF8E4284CF02289CCULL, 
            0xD272B1EF96853A5BULL, 0xE44DFE43635982F4ULL, 0x1436B932396D7978ULL, 0x8B0141ECEE96B9EBULL, 
            0xB40A416108538F4FULL, 0xF4D43B91542805F6ULL, 0x1F98B4826D3C5C79ULL, 0x452DB3DB11F47D98ULL, 
            0xCE80E609A4F7D334ULL, 0xEBAED246D8C3C5EFULL, 0xCC3318994CBDFF11ULL, 0xAA1F9C48F822F9B1ULL, 
            0x148F509D3C8EFC55ULL, 0x5D2C5D1798E24467ULL, 0xC6E1973553EF9653ULL, 0x8AC2C2D1231B5A52ULL, 
            0x0FFBFC71BF02765FULL, 0x8DDFC93479E81F09ULL, 0xC10BDAFC8852C967ULL, 0x0958852C315F28CBULL, 
            0xC3200DA9EAC070A3ULL, 0x2BD23DD9B2CD49E5ULL, 0xA7911C940389986FULL, 0x8D61A3CA9BCBFC1DULL, 
            0x827B0F1B576B25FDULL, 0x1AB7B88239A7CDE2ULL, 0x0B3460899E461B89ULL, 0x1A73B847B68ED83FULL
        },
        {
            0x8CCC3BA2CFDCA205ULL, 0x0AD4DEEF41303C6EULL, 0xEDAF7DC102FCDF95ULL, 0x5BBFD6E6F2CB3A79ULL, 
            0xCD5B0AF4CA215017ULL, 0x69F1C3899801703BULL, 0xD0DB9B9F8194053AULL, 0x16A56376B0283CE8ULL, 
            0x35115DB5C1117BCFULL, 0x34DA41A0DC32295EULL, 0x0ED1597323A95E97ULL, 0x5FF886FA82DB517AULL, 
            0x30034499555FA8BFULL, 0xD1908D5C9F2CD5DFULL, 0x3EB7D24FBE801912ULL, 0x35B5C6DF5B17B3B3ULL, 
            0xB86ABFB07BA29F51ULL, 0x9060D313AFCF041AULL, 0x637386CE15EEEFCFULL, 0x25B0E7F9DF1C309EULL, 
            0xAB55822B19014450ULL, 0xAA0B36775A50EFCCULL, 0x39D6C342664BB398ULL, 0xFAC262CE31DD7D8FULL, 
            0xF26371218B4DE3AAULL, 0x4B12DE187CEA4B02ULL, 0xEEA0DA34ACD792BAULL, 0x98A6E64B604F230DULL, 
            0x31EBD07112451A3BULL, 0x7066A0D2318A5916ULL, 0x3B4829D9D949D8D2ULL, 0xEC6FC1B87B9E569EULL
        },
        {
            0x5A5DE9F7AA4D582FULL, 0xE4141AC5D5BBA12AULL, 0xC4553F829AF8C210ULL, 0x574E509DDD506C6CULL, 
            0xF0A7081CB1DF1E03ULL, 0x2D8F47266C6D61BDULL, 0x3B813D24EF939A7CULL, 0x36E4C3C710DC8421ULL, 
            0xDD332490D8D9E1A5ULL, 0xC5879FE1403C971FULL, 0x28C3D7B023299830ULL, 0xC519B7B378190B62ULL, 
            0xEFB2BC49CD5208CAULL, 0xBA123C18EBB1EEA0ULL, 0xF6A41562327E450CULL, 0x49F34C0A560156EEULL, 
            0xDB134B0A03BD5DE4ULL, 0xE2E23911822196A2ULL, 0x4D81A974347C761AULL, 0xA9357D2E62CCF3B9ULL, 
            0xCA006E68863173D8ULL, 0xAF4021EFDFF81885ULL, 0x5E0D4F6FCCA638AEULL, 0xA1D8C2C50D8575B4ULL, 
            0xE7431634A0B30A24ULL, 0x6E7BA205D0164B81ULL, 0xFA90177410B21343ULL, 0x076F186289353B89ULL, 
            0x0821B871339EFF0FULL, 0x54BC3D1C22A9D3B6ULL, 0x4546083918C4CF2CULL, 0x047DD583F9759BFDULL
        }
    },
    {
        {
            0x078F669A33045D5EULL, 0x606C836E6F747096ULL, 0xCC9CD4DC1DC3294CULL, 0x8EB683D6D8F9C4FEULL, 
            0xD3A7FE374517AD4CULL, 0x002B303A5779052DULL, 0xBA68EE08AEDF91E5ULL, 0x776B152FA0F2AB1BULL, 
            0x41265CE93F7DAF86ULL, 0x5975D2E97F64A57AULL, 0x3DD02B87BEAFC832ULL, 0x6905E5A04EC5181AULL, 
            0xFED889D913B1CF58ULL, 0xFBC1AF74A54DF561ULL, 0x1F07A5D02B757FE3ULL, 0x327F0D321D217DD3ULL, 
            0x99B38ACA8A53F002ULL, 0x81B4C7C6FFCFF67BULL, 0x48494144EC6A7779ULL, 0x0F9675519BDA6334ULL, 
            0x6E184B4B2AC357DAULL, 0x925135759D7075D0ULL, 0xB3BCE44E14FBE393ULL, 0x73B39EE66A86CC15ULL, 
            0x7CCAA217A24104AAULL, 0xB34C754FE185F463ULL, 0xD5348E4772F563D5ULL, 0xAC2539EB6DE98B21ULL, 
            0xB8A025CD5D109E2CULL, 0x2085354FD0FF94ADULL, 0xB6F78D3A227D0220ULL, 0xC92A5AE7CE30D7E9ULL
        },
        {
            0xFE99FF18FF9D9047ULL, 0xDE28644A2810E864ULL, 0x2CF2EE4ADA7025F5ULL, 0x32027E83DB43D9ADULL, 
            0xA7332CC7EEE8E93DULL, 0x025A35FFA0A8DA4BULL, 0xA3D6448A3E4AD1B3ULL, 0x6DACE29F4D256BC6ULL, 
            0x4980C52522AB9AB8ULL, 0xCDB5A2A1FAA66D38ULL, 0x3595A2A9F7F88717ULL, 0x802E9E2C016A4B73ULL, 
            0x660D8FA849406CEEULL, 0xE67D9EE6A1639E9BULL, 0x25CCADD135176DE5ULL, 0x7042F74CF8599EDCULL, 
            0x2DDBE283993C9524ULL, 0x55966AB0D12F9C4EULL, 0xFDE68D903AE9865DULL, 0xAC435587B7E22727ULL, 
            0x5B71CA5173F03DECULL, 0xB7C9864B75D1B1BEULL, 0xC222F06F2F200CF4ULL, 0xD5F1726B3DB7BC29ULL, 
            0x69AC49655611B911ULL, 0x669B7E3C9F9B8A04ULL, 0x1E49B89E9E845049ULL, 0xA1D1D792A9DEB587ULL, 
            0x30D8E59D46B499B9ULL, 0x0628C88F312C0DDEULL, 0x4E376178F2AC4D49ULL, 0x50BBB85EBFFE8A00ULL
        },
        {
            0xB651FF1F91D487FBULL, 0x20A79ECAC305CC0EULL, 0x8179A393ECC6D732ULL, 0x3A67A9B2A00924C4ULL, 
            0x886F1D2735E5C93AULL, 0xB83DF2EB93035501ULL, 0x02C6D5D0AC4F28E6ULL, 0x822F7328D8C58BF0ULL, 
            0x9BB0873006CC7A62ULL, 0xC12F1899CC5E435BULL, 0xEB12AE4110637C87ULL, 0x577A3863AB61B8FDULL, 
            0x2BC301D6F71F0D3EULL, 0x5A9417D6BD4B4078ULL, 0x7C7BB3DE864499B8ULL, 0xEF688EC65737AB82ULL, 
            0x82ABC25BAA3B8775ULL, 0x7ED8AD420AE3DD0CULL, 0xC13446CFF9062861ULL, 0x99EE6C879228FCCDULL, 
            0xA00645E84A036B51ULL, 0xBCAC8C2CC5214CC5ULL, 0x31E3D2D4F4E60B89ULL, 0xCF9C78F3AC5D3AF8ULL, 
            0x58E73808D3D75B1EULL, 0x7434FD8D97641398ULL, 0xC600A94130E6439EULL, 0xB30DD31F44ECF684ULL, 
            0x0781830508F7AA14ULL, 0x3C281EC1159FB491ULL, 0x5EB32E04E3B77582ULL, 0x9DCBDB14539D7E23ULL
        },
        {
            0xBB18A0D5AEDD11B6ULL, 0xC5056CF021DDF29FULL, 0xD46D55208CB59DF0ULL, 0xD7CC2C57415129DCULL, 
            0xB1958D5621DA1249ULL, 0x72C6F1555A7B5F33ULL, 0x720EF1C6A737576AULL, 0x684A8211335DE9A8ULL, 
            0xECA88B118A7A74B8ULL, 0x5E51C2BFFAA4CF8AULL, 0x9617878F7B4697E3ULL, 0xB1AEEA69C34F8E42ULL, 
            0x7211D7599061A177ULL, 0x066ED549D63208FBULL, 0x25AB809852825BDAULL, 0x89D777679D9B7830ULL, 
            0xC83E3EF90B07F812ULL, 0x1B9B57E46C3AC79DULL, 0xC2AA2BCFD239FD19ULL, 0x67AC290A381C2600ULL, 
            0xD664E25149101DDBULL, 0x0FFEFE0152F45CEEULL, 0x8BF5D1A87B349318ULL, 0xE6245D2326A427FCULL, 
            0x6515101494386724ULL, 0x89014D98D912EED4ULL, 0xE52F23EF1DF0000AULL, 0x6A1CFCD734BFFB04ULL, 
            0xA3397905480A1999ULL, 0x71596EB64692E98EULL, 0x9814F467A3C12D4DULL, 0x291F02E631C278B9ULL
        },
        {
            0x2AE3E6036169DA1EULL, 0x80493D777850B484ULL, 0xF96349EC4929C579ULL, 0x997016FC31209383ULL, 
            0x407F77B0E3BED318ULL, 0x65C2295A6FD6A617ULL, 0xDACA30967C104B9DULL, 0x18305C8BFCFD2FA4ULL, 
            0xD95E182CB6F8DB65ULL, 0xD56F9C4B7AB7B295ULL, 0x1D099D162054A8DFULL, 0x34953FC10B8EBDC6ULL, 
            0x706D70496107ECAEULL, 0x9A240D2F09D2A851ULL, 0x632F3E6A66E245EEULL, 0x4C472083FB1A6C30ULL, 
            0x6776DF684B35D44FULL, 0xFD6596D3C2EA293CULL, 0xB7ED889E52EFCC12ULL, 0xD5F47AF63744354AULL, 
            0xD45FF7D7E8252078ULL, 0x35EE8B9E9E38A5D5ULL, 0x10F169A5C2AE16B1ULL, 0xC58201E1700230CCULL, 
            0x9048CC1E57CC286AULL, 0xA6B2B15988BB2D59ULL, 0x942646FBC10ED5F4ULL, 0xB15E2C4DFDD66381ULL, 
            0xFB74EBCCBDAF14B5ULL, 0x8AA553CAE830DB02ULL, 0x4D3C01CF23B400DAULL, 0x007417E5EBDD4A87ULL
        },
        {
            0x5B14ACBBAE633301ULL, 0x86BF773ECB894BADULL, 0x4326BFBA69F082F4ULL, 0x8A12C731C687673EULL, 
            0x0D837ADBF2CDA264ULL, 0x2A70AA90F1FC9A87ULL, 0xFFB035A4A358633CULL, 0xAD958A839D55F19FULL, 
            0xED4B20F613F719BBULL, 0x406E49F611BB8450ULL, 0x72A0F6B73A144504ULL, 0x95220086E98165F4ULL, 
            0x76AF0679B56037D5ULL, 0x722C21F02E021E89ULL, 0xED830AAB9FDD5E72ULL, 0x7EE0B6618B9CF234ULL, 
            0xB78CE1AB32625029ULL, 0x029511E3E2B4A3BFULL, 0x72CAAA33D15C34FBULL, 0x81BF9BCFC87976AEULL, 
            0x2215FCC95958A7D6ULL, 0xAB32408286899710ULL, 0x0DBCF2602DA1D74DULL, 0x930D72BB44F5C321ULL, 
            0x38E84C98BEC1F0C1ULL, 0x9004E5037CF4C605ULL, 0xB9426DB51070CE86ULL, 0xC1B07FFAB46B5761ULL, 
            0x58C31C490A580015ULL, 0xA1BB4B0FAB02A23DULL, 0xAD5818DAA9963368ULL, 0x3258C799168BDF63ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseBConstants = {
    0x8AA16F099960CF8AULL,
    0x61F9963EEF893625ULL,
    0x652B026B79A74B30ULL,
    0x8AA16F099960CF8AULL,
    0x61F9963EEF893625ULL,
    0x652B026B79A74B30ULL,
    0xCDBA92A554995BDEULL,
    0xF11A31F067165286ULL,
    0x57,
    0xFC,
    0xE4,
    0x12,
    0x88,
    0x8D,
    0xFD,
    0xAA
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseCSalts = {
    {
        {
            0xD03E06578835CF6EULL, 0x402AD687F752F77BULL, 0xE41E2D2DA7338A45ULL, 0x6883632278DE9CC8ULL, 
            0x0A208B74680EC386ULL, 0x5D7C4E2D1B6D2BCDULL, 0xC985390751648DDEULL, 0xF7A1C2FF70FE026BULL, 
            0xCB79C8F215E1DC59ULL, 0x6743907556A16370ULL, 0x9C600088503B67D0ULL, 0x49C91AEE946CA3D4ULL, 
            0xAE9AA9ED5931AEFCULL, 0x1F2FF3466A0731B6ULL, 0x7422ED3C434B1F2BULL, 0x6529DD55700EB896ULL, 
            0x95EBE469275AFEA8ULL, 0xDFE7A6BE47A399F6ULL, 0x2548E29588FC70BCULL, 0x5D0F3FE99A4CC5C4ULL, 
            0x4BFABA5712A0CEEFULL, 0xC49419C2AF1E3CE0ULL, 0x53FF54E137D3B6A5ULL, 0x9E93244145C3D0A9ULL, 
            0xD953AFDB40B405A5ULL, 0x78BB86D4B548FD86ULL, 0x3A09CFE65D9BEFC2ULL, 0x7E1344B2F528F8B3ULL, 
            0x20EDD6BC1B53420FULL, 0xEDC68352BEA91DECULL, 0xCB70345962441E27ULL, 0x77F6B78E3D8A3F4FULL
        },
        {
            0x010656D371A5C469ULL, 0xF4D5E41B853BFEF9ULL, 0xEEA32A58D3E79D4AULL, 0xD8839A9899F16D30ULL, 
            0xBF8E3B4CE00E7357ULL, 0x5E3E296C9ECB37F1ULL, 0x5D19140C3639FFB3ULL, 0x080DAAD2D84A0F03ULL, 
            0xF0D8B12E230CE304ULL, 0x2A151F04E85B8564ULL, 0x51BE6FDBE4ADA9ECULL, 0xEEB84E5976D20012ULL, 
            0x5C843EDDB8B584C2ULL, 0xCED503A985FF8224ULL, 0x64E13943D03B68CAULL, 0x13EF505061F4EB2DULL, 
            0xC8F53CE353CEAF9DULL, 0xB507F112B901EF16ULL, 0x56233807830B3E44ULL, 0x5C7AB1D5B7201BCCULL, 
            0x6342A64542809854ULL, 0xD9BF034A0ED515AAULL, 0xE85BF55D74286925ULL, 0x79F0BD083DA2B955ULL, 
            0x15966746D0011DFDULL, 0x4AB9C3125D733F36ULL, 0x7889CA0CD766D253ULL, 0xAEDFFD7DDAA29C4EULL, 
            0x62AD5D1A05A4B8F7ULL, 0x06B27E86EBECB1B5ULL, 0xFC88666337E27B65ULL, 0x2B7F29279FC60E84ULL
        },
        {
            0x3E72E3AC57858DCAULL, 0xD901421D9F8430F1ULL, 0x53A6255FB293682CULL, 0xD473BD4854415A05ULL, 
            0x5D9DA53CE3BDE5D5ULL, 0x97147C0B5F5A2B38ULL, 0x137EE70DB5523D6CULL, 0x54BA272D2C8A5C9CULL, 
            0xD88ECADAE85D62F0ULL, 0xD022FB4B3EEBB5B1ULL, 0xEF8456C05DB4C930ULL, 0x10106084D7B09A0FULL, 
            0x5713B80A424A9BDAULL, 0xFB9BC41230C38A8BULL, 0xBD4E4C4F278C8AD1ULL, 0xD0EAA8163FF24F88ULL, 
            0x4B1A7BAA7FF84E5CULL, 0x68AAC8F456A81418ULL, 0x2246928A103CA2A0ULL, 0xCE98D6491DCA4A44ULL, 
            0x0752AE0D5460AA61ULL, 0x66FF388501C6310FULL, 0x3F73106F8B251C4FULL, 0xA79EF10B3655C330ULL, 
            0x984CC2D5BFC8894AULL, 0x0D4AB75340429F03ULL, 0xFDF25646209F5A8AULL, 0x22F1E9D78565C31AULL, 
            0xB7643366716BB654ULL, 0x915B0CEA86811ABCULL, 0x29EFDDD6DB7184DCULL, 0xCC61555CD2B879E1ULL
        },
        {
            0xE45F425230DB63F9ULL, 0x0E585CEE629574EFULL, 0x5B3CFE90FD61FF2DULL, 0x7EADA2A8C978C782ULL, 
            0x61A28171897BCA0CULL, 0x3AF058BF573B6803ULL, 0x0C8BC1A8B0760484ULL, 0x220E6D85CA48CDC0ULL, 
            0x27790BE863611CB4ULL, 0x5AEEAB0D7D708061ULL, 0xA5B1F9C69FACD159ULL, 0x4F40E49034760EB2ULL, 
            0x41201D71E68E020BULL, 0xE4C710BB4C69812FULL, 0xE042E5365B0E7FFEULL, 0x657CC58802FD0FFBULL, 
            0x38EF5BD3BCBD1905ULL, 0xAAE99375D2FAC3CCULL, 0xBA8DF07DA1C5B188ULL, 0xC37265F18D975BD5ULL, 
            0xC6293918235DAE4EULL, 0x170BBDFCB00C80FDULL, 0x04E1CE11E4ADCA8FULL, 0x9E2B8E9765B01010ULL, 
            0x010D93FD9216B22FULL, 0xBD5F2535032C54ADULL, 0x5D2573F09F196151ULL, 0xE0605A647E5A5106ULL, 
            0x328698163CB79333ULL, 0xAE24DCAB1C2F8799ULL, 0xAFD73487B805ED46ULL, 0xCD41CFDF693AB5C6ULL
        },
        {
            0xD93BF701980EB03FULL, 0x52DB2B28A8E37521ULL, 0xB21F576BC30EE6CEULL, 0xDC1287D4F4E8A49AULL, 
            0x4CEEC2298C078C5CULL, 0x71946C90C285646DULL, 0xD1579FA8BA30B533ULL, 0x19867369827610A6ULL, 
            0xE0BDD7B9653E48B8ULL, 0x32F289060DFC1233ULL, 0x1FE40C99115BBAA1ULL, 0xFA402637268C0E5CULL, 
            0x1EF69B35FBF0580DULL, 0xD319C58514044A54ULL, 0x48F4BCA959632D82ULL, 0x3678C0D07B5DB092ULL, 
            0x4237B290AD877A75ULL, 0x5EE96C4C9F70148FULL, 0xE2A4FC7EB5FDA090ULL, 0xCE2CA73DD7B722D3ULL, 
            0x3C3AFA0E9830AE72ULL, 0xCEE8AB28113575FFULL, 0xCAD4CCB33921B6FBULL, 0x94B87949E38337EAULL, 
            0x7EEFA1150C25638EULL, 0x9131E594D403892DULL, 0x6108B3937C68BB95ULL, 0x4633ADC4F77C4B0CULL, 
            0x0296C7D592A95B23ULL, 0x45093C74323B737EULL, 0x59EAAC558EBD3789ULL, 0x372D1800816C9CF0ULL
        },
        {
            0x98E644C6CDAE28C4ULL, 0x3E605C439304C891ULL, 0x3A994ECBBD4128FCULL, 0x85CB991037C1A109ULL, 
            0xE005E1E55C4AE2B2ULL, 0xAEEA4D145C6B7FDEULL, 0x8C7ADCE844A027F3ULL, 0xF4EFE6D59A72242FULL, 
            0x36451C588C60C965ULL, 0x7E900633036CDE7DULL, 0xF20420BFC9AEB6FFULL, 0xA7E5763A1601053CULL, 
            0xFCC90975094A3064ULL, 0x78B5CE49499F2BA1ULL, 0xFEDCA397842488B1ULL, 0x8A1BDBB05A8DACD6ULL, 
            0x034B4A7DD1EE69A6ULL, 0x787863D345C31984ULL, 0x6A19667084BFFF36ULL, 0x788963A128B2E836ULL, 
            0xACB74358BEB7DA68ULL, 0xD7188CE62C92B969ULL, 0x36E7F9931533C61DULL, 0x303491E5392B1FF7ULL, 
            0x8EC722133ADF63E4ULL, 0xB3C74FBEA55E5EE0ULL, 0x6EC3626211FAFA94ULL, 0x00C409461D65B0F7ULL, 
            0xCE3938CD576EC748ULL, 0x7D2EFA708C70522EULL, 0x56B870F073516E87ULL, 0x420C6AF60C7BBF2EULL
        }
    },
    {
        {
            0x713A3D01B32E510FULL, 0x57B86CD135430D63ULL, 0xBF5BE64C1FDF9C8EULL, 0x2A5D6B87027010DFULL, 
            0x56794AEA020DA794ULL, 0x5B394F85722C4708ULL, 0x87902B11D3DD0CD8ULL, 0xD4392B0A94EFE5C5ULL, 
            0x3EE6112AC9A67391ULL, 0x36CE71A393536EF1ULL, 0xEA5AAF70243B7DD6ULL, 0x7E2CE20254796C28ULL, 
            0xB507E2DC2A52676AULL, 0x6E2E4AAF8310FEB9ULL, 0x396A84B8FBB07B56ULL, 0xB26D637B8DCEA5CBULL, 
            0xCF321E4A38DBB951ULL, 0x5BC17B3ADEA1D5E1ULL, 0xA0393EF5B56C13D1ULL, 0x78D3AE908A727613ULL, 
            0xF75578FBAA940CA3ULL, 0x59272DF7AE5FF79EULL, 0xFE381C6D2C0A2B82ULL, 0x7598799BCF599E56ULL, 
            0x024051ABCA63CA24ULL, 0x34F233F9A70B429FULL, 0xBEA962A96436F047ULL, 0xFFEE9D66847F51C0ULL, 
            0x1D7A2C7C9A14FE1FULL, 0xED83EB0EF9FEBFBBULL, 0x6D1FE8CA4A18A8E5ULL, 0x43CA1DF58A7D7FA5ULL
        },
        {
            0xFE31A735A64E4A1DULL, 0xDD2C8291FDAB8431ULL, 0x7C9B383B29E8354EULL, 0x44C216CB1C3DB98EULL, 
            0x9A43AB41DB7F6721ULL, 0x2E71C20F8009F4EEULL, 0xC0DF6A01F104FC47ULL, 0xE04D965544086BEDULL, 
            0x9BCBCCBA6D1B6C61ULL, 0x5DF2EACE0FA79760ULL, 0x22084AC0B40F0681ULL, 0xF4C4D21D118961D5ULL, 
            0x9E534D73D7F0C00CULL, 0xB38506B59E415399ULL, 0xE09FCEEC5B0814A7ULL, 0xCE9E4F5347506C46ULL, 
            0x267C246AEEFBE6E2ULL, 0x20D3DA685C7A4BA3ULL, 0x36FB1AE8C1D6DCC4ULL, 0x7DD9532E4889F103ULL, 
            0x4257220E1116574DULL, 0x02CEE20CFC8CA500ULL, 0x357D5118E0069CBCULL, 0x9BB09A500E049EBEULL, 
            0x9C86650101152B8EULL, 0x43FB4FCF4FA5CD58ULL, 0x5CF767528421D9B1ULL, 0x58FF84A0FC313494ULL, 
            0x10E49EDE38B0B6DAULL, 0x9ADFC4DD515CFD53ULL, 0x8FAB501674A47C12ULL, 0xB3AECCF6915D5851ULL
        },
        {
            0x2DE0590EA8959899ULL, 0x2BBD167931DEDBF0ULL, 0x7687B7FF054AD6CBULL, 0xB8E3552E26833572ULL, 
            0xC3F65C5626B02251ULL, 0xD11F294ADB445803ULL, 0x98E4891BB44C9D9EULL, 0x6DD5AD58669625D1ULL, 
            0x4427A07975D2877AULL, 0x5DABEEB1FF647A9AULL, 0xC9B05F01F0068819ULL, 0xF568753042F9964CULL, 
            0x671490DBB37DDF31ULL, 0x3D5AA765CB86A0ECULL, 0x436D7A293065B940ULL, 0x7813C6EED2EFB94DULL, 
            0xA83D05C01499DADFULL, 0xED60CBC96A6135BCULL, 0x77FA668F4EE0A328ULL, 0xB68EE803DA3820A4ULL, 
            0xA82403460BE78B0CULL, 0xC25368AB01C5BA5EULL, 0xDCBAA7C31A606B85ULL, 0x3573D3A3750C24BDULL, 
            0xF356062B7ABA808EULL, 0x224CBB7FEF643EB2ULL, 0x109CBAA4D42BDDD7ULL, 0xAA6FDB0E06EE36B3ULL, 
            0x36E16E816F541720ULL, 0x0544841A89F41E76ULL, 0x794076A06D2CD2E7ULL, 0x99267DD3A44CCE2DULL
        },
        {
            0x5E75D504189A9822ULL, 0x8329794B5E5CEAC2ULL, 0xFE9E8A42E82FDC7FULL, 0xFB8EE79CB994497BULL, 
            0xD809FC1D50E5FCC5ULL, 0xDB7B8BF2735B876AULL, 0x57039B990B4421E5ULL, 0x9D971DD083BA8D93ULL, 
            0xA6330851445D11E7ULL, 0x71F287431C55DC32ULL, 0xDE5DCECF9A99ECDAULL, 0xBC6C1AAC258060B0ULL, 
            0x568750C398E3D28DULL, 0x5F227805EC3BBE10ULL, 0x9176C69396834F7CULL, 0x823F64CD32B60E3BULL, 
            0xD3C74278888E3055ULL, 0xA9A42C02E946A527ULL, 0xF0BAB272D9FFE7EFULL, 0xB6E02BA4A42852CFULL, 
            0x4050589CDD2C19B7ULL, 0x954B2F352BF72FDAULL, 0x7C35E501D79AEBC9ULL, 0xD3AB75CE231B0F0FULL, 
            0xEDFCE40A098249FAULL, 0xFC43B76D8F9E9762ULL, 0x34F6117A646FBE89ULL, 0xA0F8708122175B59ULL, 
            0x8F2ABCC13468187BULL, 0x78A4183A3B870567ULL, 0x3AF0D1E197787A84ULL, 0xD9A1DC864BD41C18ULL
        },
        {
            0xD6AFB0F0289DCB88ULL, 0xD6FBEF0DAD4C95D6ULL, 0x4F9BC50DA04DE9A7ULL, 0x0DD1BEC2018D9CEFULL, 
            0xF96080C79DCD53CEULL, 0xFA8EE657D39885FBULL, 0x60305A824EB402DDULL, 0xEF725727B3EB1A98ULL, 
            0x0363CD3E6081EDD6ULL, 0x42389C47FA71DC7CULL, 0x5BB31AFBB922FF9AULL, 0xD00BC056C38808CEULL, 
            0x1DCEFE974D5D651CULL, 0x73A1CB9ABD745588ULL, 0xBD475114D83598FCULL, 0x92BBF1453F81DFC3ULL, 
            0xC6650AAD94D238C0ULL, 0xF4BEBA049495EFC9ULL, 0xFE8F741F5A6FE293ULL, 0xF5B73DDACE461894ULL, 
            0x8572DF8316048727ULL, 0x857DE5096811A2E9ULL, 0xC1C2B1FCD5CA30EBULL, 0x9CC3BFA124284663ULL, 
            0xAFE6AB8C4A36B6B0ULL, 0x0D6F6EDDA2398550ULL, 0xC66B2476C69E77C1ULL, 0xCA061C8963A4C970ULL, 
            0x77A2FAA9EB28E837ULL, 0x4A50260C2E8BAD83ULL, 0x159213F423CC1E07ULL, 0xDBA0BE2E7E0588BDULL
        },
        {
            0x20DBC24E8554178FULL, 0xC7E8CDE176F00820ULL, 0x20772489CC4E6343ULL, 0x95DE392B2EB2C280ULL, 
            0xCD41ACB5D41FECDAULL, 0x4283364FB57B438EULL, 0x11642D4EBE947739ULL, 0x168305655B7C6480ULL, 
            0xB695F2A343B5542CULL, 0x98E8B0D1495CAAF5ULL, 0x31FE68D724A6F703ULL, 0x5A6E68208CD5E358ULL, 
            0x51514FB5BABDF048ULL, 0x52FE31286EA4C132ULL, 0x4079DCA3B1380F63ULL, 0x603AFE468F09219DULL, 
            0xB4C0D42A27624C2CULL, 0x5EEE9847D2A70B9AULL, 0xB096A4B895730E6EULL, 0x757582990A6F3D4EULL, 
            0xF3DD3C2D11B583BDULL, 0xA0F5F2236014AFC3ULL, 0x3AF3913228989BF3ULL, 0xDC690B8C7143C6F8ULL, 
            0x458D716122649DF8ULL, 0xB407B3910164ECA0ULL, 0x3481F74966D5E73AULL, 0x88DAC499102164F6ULL, 
            0xCB3B38187F3333BEULL, 0x2BDD66B16D0988D8ULL, 0x9BF03F351B583585ULL, 0xC0D8FE55F665F1ECULL
        }
    },
    {
        {
            0x4C03DF4B53ECA4ECULL, 0xBC2CF4A7B6E02276ULL, 0x90E13977433067FFULL, 0x25B8DDFA3B9A81B9ULL, 
            0xC62E55A6304E3F85ULL, 0x2E4B2B8DEC4BFB13ULL, 0x2895945FDDD4B5A2ULL, 0x38C32B1E563A9BB7ULL, 
            0xDB9E0C51F9EA68EDULL, 0x78C9BF3EB1574ACEULL, 0x095CE60C57D5FEB5ULL, 0x84803934B9454CC7ULL, 
            0x4503DA615D2BA2C4ULL, 0xA3D5A478E31756DFULL, 0xEC2DF3DA301AA453ULL, 0xB280C640C94B4C68ULL, 
            0x06F1B9D641669AD2ULL, 0x0466F29413C1741FULL, 0x5F5BA78B7633838CULL, 0xBFA1B9AA69D6E645ULL, 
            0xEC12CDCABA4F7BA9ULL, 0x6A3AAFC46A3ABA20ULL, 0xA49A646C7A436B44ULL, 0x7A71F0E4EE7CF9E9ULL, 
            0x3F3FEEA95B4C27D9ULL, 0xB99D6959C67B1399ULL, 0x30C701BEC6D27E21ULL, 0x6E1B48AD933928FAULL, 
            0xFB42843FFB190445ULL, 0x51F95725EF60D816ULL, 0x9F8F0DF4D8ED0340ULL, 0xEBAF0AAD4569F84BULL
        },
        {
            0x4F92581D0A4F4686ULL, 0xA8A4B12BA5F4683FULL, 0x5287D1985BFC84EEULL, 0x469AFF626865B7F7ULL, 
            0x911926A10014D42AULL, 0x942DC5F23BE69F22ULL, 0x6D37C40B1B95F1DAULL, 0x3771F3F24216B7C5ULL, 
            0x8DD53346CCCDBA0CULL, 0x1A85DF3327D85DA6ULL, 0xBE90FE0B504CCF37ULL, 0x147B174FFEA2CBCEULL, 
            0x5C4D8E1FF0CB88E2ULL, 0x3FEF4CD0823843DEULL, 0xEC4790194558A5F8ULL, 0x5A201814C890A7E5ULL, 
            0xE4B808E7090BD1BCULL, 0x781D63FBB8999910ULL, 0xA4C3C71175B42D23ULL, 0xC4614A94E01E3543ULL, 
            0x8A4F4FBD6E0EEAE1ULL, 0xEABB39938C6C94C7ULL, 0x9C96994849D5212BULL, 0xFF9C690BE11E4C51ULL, 
            0x9DC2AE6C16C661E6ULL, 0x141C01CDE441F2B5ULL, 0xBB3A38F99A670161ULL, 0x0C26BCBC733541C7ULL, 
            0xF91B163F4420198EULL, 0x1080CE8DA549903DULL, 0xA0E974FC8C2CF80AULL, 0xE80F029740B45EF1ULL
        },
        {
            0xA8BA27AEDB7A6292ULL, 0x294D03353AEAD25AULL, 0x9ADC1214BAC76F17ULL, 0x6294232208589025ULL, 
            0x2D32CB88633EB77CULL, 0x1AD3511C29732EB1ULL, 0x82604F0574886DE0ULL, 0x5236E357C08BB508ULL, 
            0x3D3A9A2582C5A58DULL, 0x830C819506FC1CF7ULL, 0xE507A2E46E3647D4ULL, 0xB3C239B8684BDC6BULL, 
            0xAC2EF8DB076A0E8DULL, 0xB79AA035B34FE0A8ULL, 0x469EE0DEEC4C22F1ULL, 0x29D2710A1B92628CULL, 
            0xB03D20CD4463DBB9ULL, 0x702D6DE1D1CE260EULL, 0x24D8EAD032DC0DAFULL, 0xFFC46C06C5958D8CULL, 
            0xF730105499D518A1ULL, 0x0CD95CC41DDFCDB9ULL, 0x832CB3F7E8B5581DULL, 0xFD1977017997BF36ULL, 
            0xE63E57CAEABC7123ULL, 0x29D639BED2EA9413ULL, 0x3E0E85F18AA1380CULL, 0xD48C82DE79BB3EB9ULL, 
            0xDB5AB1C1A2C8809BULL, 0x1A7B8684FE38ADA0ULL, 0xAA65B4455ABE3DFAULL, 0x9EDA36C3E143E2A8ULL
        },
        {
            0xC0FA615B8D59124CULL, 0xC9E11886358E080AULL, 0xD6221BE2BCDD0DC1ULL, 0x6D7A1167E79D4FCDULL, 
            0xB9CC7360344982D5ULL, 0xEEFE74FD73628E7CULL, 0x028BEA677D9DC646ULL, 0xFCA1199ABC927ADCULL, 
            0x5135D6E0BD19DE38ULL, 0x708F4D44973EBA42ULL, 0xD091053962B3D6FDULL, 0xBF2A761FCA2FA519ULL, 
            0x959F6B3EBB51DAA8ULL, 0x5855251ABFD2C81AULL, 0x5738EEEA7099EC9AULL, 0x77AABC12C3F286C3ULL, 
            0x0B31269B4437FE45ULL, 0xB5DCDFCB0EACF2EDULL, 0xAB523D685BC0934EULL, 0xD43944A6A0078F97ULL, 
            0x05D9BEFBC26BA834ULL, 0xA6654C68727281DDULL, 0xCF1B356BB849E53AULL, 0x7C244EA3C2E1C351ULL, 
            0x5588BA705C66BEDCULL, 0x9CCAA11BA5571319ULL, 0xDE4F2DECF911BAD3ULL, 0x3D4D5796E966C2FCULL, 
            0xC6137807C21B1957ULL, 0x1F6C837B95FCBE49ULL, 0xAFBAD1593B09B40BULL, 0x51EA6E0A3D4FC9E4ULL
        },
        {
            0xABA7D2E79F009654ULL, 0x03686EDA30823590ULL, 0xA88006F052D54C15ULL, 0xCBF3C414F7DA70B7ULL, 
            0xB9DD1C2BFFDE508CULL, 0xEE4F6BBB3CD1A71DULL, 0x30CBACB7DE1E257DULL, 0xC054BF8957CCD6AFULL, 
            0xEFADB6AAA894ECA8ULL, 0xDF0E33C250FE2F34ULL, 0x2C2F13BBE57F0857ULL, 0xCAE947F8DF8393F4ULL, 
            0xBE57A47CD4FAEC75ULL, 0x81FBE777F6358871ULL, 0xCE092CC85A48DB40ULL, 0x6EEBE92D7C3B77EDULL, 
            0xE21D1AB9C10D10A9ULL, 0xD66A91890342DBA5ULL, 0x0B80938166298B67ULL, 0xF26670C98A4F8925ULL, 
            0x1180A71DB8EDE53DULL, 0xB7682814F1E92830ULL, 0xF474C64A3DD6E54BULL, 0xE9CFCE638D6D9788ULL, 
            0xE99014BA9F3C7901ULL, 0x44F9F27431F25558ULL, 0x718186C73B7101FBULL, 0xB5F8B16589A399CEULL, 
            0xD734F0055BA216EEULL, 0xC4DEF523F215AFA3ULL, 0xECDF69A4E35464A4ULL, 0xA6C3DB067BB65918ULL
        },
        {
            0x894622738E821895ULL, 0x66600F5200CF99DEULL, 0xC449D487D0547605ULL, 0x7F79F24392965FB9ULL, 
            0x56D270B979FCA332ULL, 0xE2958943DA5D227FULL, 0x28CC1FE92BC3CBC2ULL, 0x712A872A676B8894ULL, 
            0xD2C6F87C3A7F4332ULL, 0x0D3AF69C545426AFULL, 0xA239D9285F194436ULL, 0x28A118C8492D614AULL, 
            0x844FAAC2A86342A8ULL, 0xDCBA055CDCC71CDCULL, 0x035CD56E257F9C35ULL, 0x6994807CA7AB27CFULL, 
            0xF8A104C9721DABD7ULL, 0x0DCAE9A62417F465ULL, 0x117E9F3AABE755C7ULL, 0x00C3690E84581633ULL, 
            0x52ACFF22074E1B30ULL, 0xA7F9E3CA32343A46ULL, 0x5B0275AF342E9519ULL, 0x2FD600316D01882FULL, 
            0xFEF2A230226D95FBULL, 0x0AF6E1D15C4817CDULL, 0xA0F0801C453C43E3ULL, 0x446B3B9562BEA3FCULL, 
            0xAEC8640473525D1FULL, 0x1D0A4E742DF96613ULL, 0x15055CABC2525DBCULL, 0xF4E31591DC1B062EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseCConstants = {
    0x62EF15E132DAE99AULL,
    0xBFCA88947754BD4DULL,
    0x6EF81D504E4309A1ULL,
    0x62EF15E132DAE99AULL,
    0xBFCA88947754BD4DULL,
    0x6EF81D504E4309A1ULL,
    0x410A6DAB9CD0E6C7ULL,
    0xAFFDB4BE833959AEULL,
    0x33,
    0xC4,
    0x79,
    0x67,
    0xC2,
    0x44,
    0x02,
    0xDE
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseDSalts = {
    {
        {
            0xE93DF1F715936A31ULL, 0x334478FEC426FE33ULL, 0x7A2A2BEE132EB4DAULL, 0x6FFFB8CB504011F4ULL, 
            0x0FF893F7C6DA9968ULL, 0xFBAA63D9B27B04A4ULL, 0xC3AB8AB36CEE5F0BULL, 0x798B13A56389482EULL, 
            0xAAD854058A4F84B4ULL, 0xBCC0AD63731B1EA0ULL, 0xF07937731E415EC4ULL, 0x75C7150A1E65EF64ULL, 
            0x413A620E6E07C773ULL, 0x8F2434A102969DE9ULL, 0x320C22111E3438F4ULL, 0x9C948E75CCDD4C7EULL, 
            0xE023525DB2153E6FULL, 0x8FE7EEC8485E865FULL, 0xBA7A737DA18A632CULL, 0x8F14A537BD348EA0ULL, 
            0x827BD01ABE765AE7ULL, 0x43490E9CC882A0A5ULL, 0x7C786813F2179854ULL, 0x7F428E734689CEB4ULL, 
            0x9D9DBE74C384152AULL, 0x418ADD9C336A2200ULL, 0xAA6BA5A8FE76F97AULL, 0x238B732EFACB73B2ULL, 
            0x21AB4F0A82363C9BULL, 0x545CDB557E3B809FULL, 0x1FD9733A8BDB636DULL, 0xA34235FABF01CA3FULL
        },
        {
            0x96B6E33AC12F4B70ULL, 0x2081D1BBD316E378ULL, 0x9CB0161CFA6F0E14ULL, 0x9179C91B3636D347ULL, 
            0x16503F5020BAA0CDULL, 0xF211BD4827F46291ULL, 0x2CC593A26388C5D9ULL, 0x803BEDDD766AF33AULL, 
            0x9B178C1617F72B2DULL, 0x15699A1CE46D6CB4ULL, 0x500EB10420A7339FULL, 0xCD54A68303B7E46FULL, 
            0x6D563EB16D35E1C8ULL, 0xAC736EA3AFD285E9ULL, 0x66FD04402785277EULL, 0x7480747E53A6992FULL, 
            0xA80561ADADF6C316ULL, 0xB027B18168C5B762ULL, 0x31E85F715E5DC856ULL, 0x92E892AB85AC5C50ULL, 
            0xBC25AF206D2F2D67ULL, 0xB1D34606989469AFULL, 0xF48E960767A03C08ULL, 0x1F8668E5B8BB603AULL, 
            0x2237FBF5C48C3F1EULL, 0x9AFC4A50E76C345AULL, 0x9A0CFF0A3F360367ULL, 0xA483D07887480A57ULL, 
            0x02D7225ACD4D2492ULL, 0x1B6AD874D271484FULL, 0xC60CDB2C30E929F3ULL, 0xC149E9A3558AB351ULL
        },
        {
            0x3F69B2FAC32DA97BULL, 0xAAAF46A317491CD0ULL, 0x3A1B5BF0649AEA92ULL, 0x0F04E411F743F414ULL, 
            0xCDB6E821C28DE59FULL, 0x692FE16CDAE19BBAULL, 0x45830540E54BE084ULL, 0xDFE1C1105EA3C9CCULL, 
            0x4C1C5A74EB821618ULL, 0x3A24370FA0FA745EULL, 0xEF980D992CDA6F74ULL, 0x1378F5992C540B09ULL, 
            0x1710D06108154D4BULL, 0x2CAB2BD8F40B191BULL, 0xF34A9A445F134AACULL, 0x9FC09227B7BD8E7FULL, 
            0xF1CFEB19A5BF10C1ULL, 0x51571ED73065C458ULL, 0xB0D2D3D5C3280584ULL, 0x38A69E7F0F1A4D46ULL, 
            0x0191EEAAA6A7E03DULL, 0xFF9F01665D02D0FDULL, 0x2ADE687C2D8532F0ULL, 0xC8A9D6D5FDC24274ULL, 
            0x1C662A8EBF94C175ULL, 0xCF9970E231C8E6C2ULL, 0x75D894EB45EB2AC3ULL, 0x626708837C0F884DULL, 
            0x67002E0448AC3277ULL, 0xE5A6D46A85F74760ULL, 0xAADF593F4A9140E5ULL, 0x7C81608172FB63D8ULL
        },
        {
            0x466D302DCD1B7BD5ULL, 0x1154F267CDF6FD95ULL, 0x78BFB211CB883A97ULL, 0xB7F84064297D73F4ULL, 
            0x110CF5A5EC5EC463ULL, 0x03DB6F33695523EAULL, 0x75715EDE700D2A8DULL, 0x5ED90293971F7EACULL, 
            0x5753005B614DD29CULL, 0xD9BCD767B00D1B17ULL, 0x20A1EDBFDAE40154ULL, 0x6F20EFF57DD28066ULL, 
            0x56F85C9F87C56771ULL, 0x2DEB764012E2A744ULL, 0x05C7D81944AB856FULL, 0x9E8EA3E2F6C20A95ULL, 
            0x87400E71437EE353ULL, 0x73F8482439E5C8F0ULL, 0xBB57AE423B226B96ULL, 0x7035523EFEEA143CULL, 
            0x8A4F3440CE9E56EDULL, 0x2AE2F14D9960F221ULL, 0xD06475EF428CAED7ULL, 0xA194E3A80E396890ULL, 
            0xF36211C236CC9293ULL, 0xFC0B411A10C8C456ULL, 0x1D34DC1DA371FC8EULL, 0x8AE21CBD4AA68832ULL, 
            0x2C14F4CB7299CED7ULL, 0xAEE271A1D41F0F41ULL, 0x25B1AB7FE96E0CE1ULL, 0x40C5398DAA87A699ULL
        },
        {
            0xBC093E2C7178ED4FULL, 0x34B84A805EC6B244ULL, 0xA673E7BEA229AF15ULL, 0x83AF471A40582356ULL, 
            0xAE90CB50ABA9A9EDULL, 0x2B3712764299B8BCULL, 0x74C0A29394CAC5BFULL, 0x2EBD835874C227A0ULL, 
            0xC3BB7E2067A1F3F9ULL, 0x37716629B592A349ULL, 0x879CCFB60825E7ACULL, 0x41AC154C210BAFBCULL, 
            0x1F73B66CF497237CULL, 0x44C6E22D6EDF3126ULL, 0x42C44E8BCF36DE26ULL, 0xD25E7F8B20AC5582ULL, 
            0xE15E9F8FFF6A0CC6ULL, 0x76F25B6EBFBB664DULL, 0x0AD760E77EDAC116ULL, 0xA8DF481B1D8E8DF3ULL, 
            0xD6AB4C6BA63CBFE4ULL, 0x17CFD24E40E17840ULL, 0x0C433F7B441458F5ULL, 0xFBF5CCAE9705A7DFULL, 
            0xFD182CA162BF656BULL, 0x4588125F01110FF0ULL, 0x41C8F315A63D7EF1ULL, 0xBF1E199757FCC3D0ULL, 
            0x548A8E11843CBBCCULL, 0x5DFA2E912B520F05ULL, 0x8AE02EFE39BD8FDDULL, 0xFEBA71AF13744FF1ULL
        },
        {
            0x4C2E756A0550BBFDULL, 0xADBBD71ECFBD1647ULL, 0x88B3C5C8C987A76BULL, 0x7E4C803E037AE45EULL, 
            0xF16E3C6332285E37ULL, 0xC94E283E7B49B72BULL, 0x14D7DAE426949BBEULL, 0x1036878B1B51E0C6ULL, 
            0x6779CC5A0EA7B18EULL, 0xF7F3A57F340667EAULL, 0xAA4BAD08D5A70D07ULL, 0xBB7DB02A06A42D07ULL, 
            0xE5999AD9562C85F7ULL, 0xFF7D662247E3D4BBULL, 0x6CE31F2225E58813ULL, 0x0F8DE189C92C9039ULL, 
            0xEEB113CFB5163335ULL, 0xBC6E05119A5F26CDULL, 0x4DAC57DA152A2CE8ULL, 0xA3799F7BB82C8B44ULL, 
            0xCF5760A3B2C56DDBULL, 0xE08ACF428A9C7259ULL, 0xA940F0FE66738CBAULL, 0x8549A60EE462CB7EULL, 
            0x2E7A0CD368D39F21ULL, 0xA30D81553BB2F283ULL, 0x48E9B0A069C32E30ULL, 0xEE8CB5C1870C5274ULL, 
            0xE199C66037637EE4ULL, 0x3429D2949638F14EULL, 0x0F2F04A6D9D7BCC1ULL, 0xC2EFFDE579ABEF40ULL
        }
    },
    {
        {
            0x238C956105802CD6ULL, 0x07CDF3C2E3242FDFULL, 0x24D6CB2D6BFD3813ULL, 0xCA8BA873D3920662ULL, 
            0x317B456F23E56D26ULL, 0x9E565AD757C567F2ULL, 0x92AB0D46399628EEULL, 0x2FEFDAC32AB9106DULL, 
            0xD9110849751D2B1BULL, 0x83B5A3C70F69A088ULL, 0x13F4CB91CE13DFA5ULL, 0xA9752ABC1EDA3C85ULL, 
            0x305F79D5B4AA1BD7ULL, 0xC5F3DF249FD9A9CCULL, 0x68AE33E0024EBF9CULL, 0xEBA14851953E4050ULL, 
            0x3339A09EC41A1DE9ULL, 0x8F6AC28FF0AF3754ULL, 0xCEC31BD437F860A6ULL, 0x108459BC408D2363ULL, 
            0x8C671024DE3C3846ULL, 0x2B39E26F3901384FULL, 0xBC15BDFCB83CBDF1ULL, 0xA62460093F498D4CULL, 
            0x71DD0810EABD77DFULL, 0x0C51D9001BC335CDULL, 0xB4162D3A6BA33D53ULL, 0xCF3AAC52ED9F545FULL, 
            0x13C1464EE88DFBAEULL, 0xDA1E82B3A9EDA97DULL, 0x6EA6EC4B16D1CB66ULL, 0xD7542FFCE6C967EEULL
        },
        {
            0x4B2A0961612F8393ULL, 0xCA163BD8D14F7E9BULL, 0x4434AB4D3A76C17CULL, 0x530EC7277E7F33E8ULL, 
            0x662D577838563495ULL, 0xBBD8744466E36CB7ULL, 0xBF808AE49BBD2C5BULL, 0x1AF15A74CA419EE3ULL, 
            0x58CE43C07DC43DFBULL, 0xA1C7AAADB4FAF634ULL, 0x88C80D03D3552A49ULL, 0x8F829E6419A0E794ULL, 
            0xB5EA048824A5CC2CULL, 0x6439029056FB042BULL, 0xA601422CF9FDCDA3ULL, 0x5FFFC733BF538028ULL, 
            0x651DA2FA57BB87CCULL, 0x2367333DA843BCF1ULL, 0x9BC8A8E26A9976A6ULL, 0x814DF420C262726BULL, 
            0xE0D92115B180BE8CULL, 0xF9F485EDED20EE32ULL, 0xFC7468CF57BB115CULL, 0xEA0EDD5EDC049529ULL, 
            0xBFB3C80FC4A71C7DULL, 0xB1B523B17725BCBDULL, 0x053BA8955D77B2FEULL, 0x894BF98A0048CDA3ULL, 
            0x0925CC98C4CF616DULL, 0xF332A9FD94AD64D5ULL, 0xD05A8D2A22673DA7ULL, 0x68C6BAF4ED8F5B5AULL
        },
        {
            0x5962B7DBF5B620B2ULL, 0x769DF43970D9FEBDULL, 0xED8945026CCC433FULL, 0xDB01F6831BA61865ULL, 
            0x84C3793A4C92C92AULL, 0x14A03EA6C29BB2A7ULL, 0x6547FDB25813905BULL, 0x0E7A28DEC62B94DAULL, 
            0xCDFD5231512BB2BDULL, 0x8D4227F4A0E25F40ULL, 0x8F7DA89FAD724433ULL, 0x46C3EB2642DFAE62ULL, 
            0x9F43977FAC924B3AULL, 0xF1D34B4D3EBCFC98ULL, 0x98E64F691A3BDCC4ULL, 0xB595D4A0208F43FBULL, 
            0x55A946CE05E104F0ULL, 0xB1DA94D54B3292ACULL, 0xA07DD8B388AE26A4ULL, 0x97F52006A5895628ULL, 
            0x9F53750FF158131AULL, 0x100BDEA58B270A4DULL, 0x93BD1D17374E39CEULL, 0xD89171E980519B78ULL, 
            0x513F1064FD5E63D2ULL, 0xCD74FB743D318E96ULL, 0x5DA22A550379951AULL, 0xB198924A043D764EULL, 
            0x89061757E2C75656ULL, 0xCEB5E2442ABECC11ULL, 0x9FB15FDBE0103773ULL, 0xC4F1C343A5AB568BULL
        },
        {
            0x84ABEB05478AB5FEULL, 0x3FBC59878B26A695ULL, 0x235FF2AC4EA7EA7CULL, 0xD3FA1B359A977622ULL, 
            0x18100B939AB8890CULL, 0xDA449B9A3BFCF5E5ULL, 0xAD0E0CFB1979FDA5ULL, 0xC88679B62F6C6921ULL, 
            0x9CDCA55F3BE66E23ULL, 0x8B3BA22F1815EC1AULL, 0x657D14D97289BCA8ULL, 0xCF6CCD51774BD13BULL, 
            0x7259A05B5429E758ULL, 0xBBC203945A71442FULL, 0xF4F93B9CD874DBE6ULL, 0x0D7982670B98116FULL, 
            0x1E114F08C545D645ULL, 0x66FF861556BCD0EDULL, 0xEEF8983E18B07046ULL, 0x17E2C7591351D0A1ULL, 
            0x53CD4F0BECB1FBD4ULL, 0x6990AB64B1304B7AULL, 0xE8902E16480DB770ULL, 0x34DAB01D016FC8D4ULL, 
            0x2CE56CA4DCCF55E9ULL, 0x7457F993B88135ADULL, 0x6945FF8AEAA6D5CCULL, 0x21633AF866D81160ULL, 
            0x7EFDE6869AEDA3E1ULL, 0xE66175258FAD2D3CULL, 0xE3B0FF400C2374ECULL, 0x35885AC5CCF484F8ULL
        },
        {
            0x1202BD7BA40B84ABULL, 0xC6ED210F67E4B941ULL, 0xC0657FFD9113F6C9ULL, 0x5C3A9BF752859FEAULL, 
            0xF3E5137C26D53E3EULL, 0xA47BD90BC5CB9F09ULL, 0x3453FBCF747E7AECULL, 0x20625AC99ED74C90ULL, 
            0x749366D5B73C798EULL, 0xCD2A56DE8AE04F4FULL, 0x36BB36903A4ABF53ULL, 0x54F02604606510EFULL, 
            0x9AF5E1C92BA173C0ULL, 0x6F2CF3077F44522AULL, 0x2F0ECCCCE94C095FULL, 0xA1286178410B323FULL, 
            0xE67F0EC7A2A58CB4ULL, 0xF52EA981D25BCD3FULL, 0x5A8E3D6FCA17F709ULL, 0xE0A7CEF6BC758DB4ULL, 
            0x583F2373E34989BFULL, 0xF4BF99BACCDC5322ULL, 0x567F68DB797070ACULL, 0xB8C7FD7EC9573325ULL, 
            0xAEF2E538221D2ABFULL, 0x5605AAC48E8DEEDEULL, 0x78A5E78B5DD909EEULL, 0xC392D29AC5327173ULL, 
            0x192249EF586A0A60ULL, 0x7EE4581F50ADFE84ULL, 0xB438FFEF0C3A55E6ULL, 0xE546A066BF90A3E4ULL
        },
        {
            0x474E0DC0E46A7600ULL, 0x86248F326F8FDCABULL, 0x7C9E1C99A499D0FFULL, 0x1AF790D428D021D1ULL, 
            0xB8E35BEDEBA27E4BULL, 0x0BA173B244A85A55ULL, 0xC72C9E0870E7353EULL, 0xA10653A4C6F60CCEULL, 
            0xC853C5CE2F5946CDULL, 0x7589C00CE75FF4B2ULL, 0x946E776B55CF78EDULL, 0xD016D470C8449848ULL, 
            0x2AE32422E41AD1A9ULL, 0xBF1CAFAEDD8B1D43ULL, 0xFDAA5064717440F6ULL, 0xDE167CBFFA6ACF9AULL, 
            0xF16B46B7B6CF25E2ULL, 0xD841DF04BA32597EULL, 0x4C4E5C5302E048B6ULL, 0x9C7B8C4BBC864BBDULL, 
            0x47588B1DC379FA99ULL, 0xC956D8100DAA709EULL, 0xB52AB5936DD0C9BCULL, 0x4AC189C32809552AULL, 
            0x5B1713BF2D70E23AULL, 0x3D252D0E63802948ULL, 0xE90266898008C4D2ULL, 0x6B79B509FE5F2B5AULL, 
            0xE09F51E30DD43591ULL, 0xF68547D5C8CE3A6AULL, 0xE90B5BE8AF17B452ULL, 0x4D74144909FC4880ULL
        }
    },
    {
        {
            0x8F877CC024542F07ULL, 0x090EBCE52DE32C91ULL, 0x4A9563D76642A469ULL, 0xBBF972E682B5C538ULL, 
            0x5F38C4E6885C9E93ULL, 0xF87E0AFAD415E185ULL, 0xA3726D149631CA99ULL, 0xAA369ADA453525FCULL, 
            0xEFB893CDD4CFCB06ULL, 0x27B94A41B8ABBCC1ULL, 0xAAE00CE175C4F9E5ULL, 0x7FB3A3AB1EA65675ULL, 
            0x4C3C789A260A1C3BULL, 0xEE2F151C65556050ULL, 0x978EB802D0E1B9A8ULL, 0x8069998CC915C0E3ULL, 
            0x13E6C064572E3B87ULL, 0xE2E90CF85DF7F948ULL, 0xD7C55950BBDB4ABEULL, 0x4CA13785D194A554ULL, 
            0xF4BF5F85E3D7C71AULL, 0xD80BA7C65C0F856DULL, 0xA635D59A413B2E2CULL, 0x994110B748813B1AULL, 
            0xF55BB16ADD4A79FBULL, 0x44216591DC88A261ULL, 0x6F0B698A6B494870ULL, 0x835C3184C3A528E5ULL, 
            0xFFFD2EE73AAC30FDULL, 0xDA8E761A5E42F5D7ULL, 0x81C3AE2C7E9BB4E5ULL, 0xF4F4838F6E387A2FULL
        },
        {
            0xD4F5378B923987DCULL, 0xB2917A229C9043E1ULL, 0x455D9BDDF7B8144CULL, 0x2D558C23B5BAF0AAULL, 
            0xE37E6C1CA3CB5C05ULL, 0x6E0AC17DF2E5DD96ULL, 0x65D2EF1AD498DAAAULL, 0x6D033296B7992949ULL, 
            0x62FDEA97360D29D5ULL, 0x63CE78B595AF56F0ULL, 0x79357CCA617690DBULL, 0x57A16BBD7FD9312CULL, 
            0xDBEE35D5C45102C7ULL, 0x7DFC4ED4B6D1270BULL, 0x8AA1323AAAD9767EULL, 0xC5C313FB55ADA338ULL, 
            0xB470C65C29F77A45ULL, 0x01DCFA2561D68B97ULL, 0x22E388903F9B98A5ULL, 0xB13AEDCB22927140ULL, 
            0xE971A48B25977933ULL, 0x3A1953C3EDCA3CADULL, 0xA938C3A4871A92C0ULL, 0xE493BD14CEE698B1ULL, 
            0x9C83B8FA3CC5045EULL, 0x1A43D2822625F30CULL, 0xCD8B822E578C6A0EULL, 0xC7AA94BEA80FE29EULL, 
            0x00EB6475A540FFD9ULL, 0x139B1FD18BDFD569ULL, 0x030C1395D9AB4285ULL, 0xA21D828FE443C640ULL
        },
        {
            0xE705002814A23285ULL, 0x52909CDD71711E6FULL, 0x53F7C04950A447EDULL, 0xA53C3A7655FAA766ULL, 
            0x7144F3FC83C9CDA6ULL, 0x6EE139E3BD4AEA6AULL, 0x1FBDFF507B52CD3BULL, 0x53F5FF81001B216AULL, 
            0x0B79E9DC07C52BEFULL, 0x0A84BF19D7110762ULL, 0x301B91F4FE76B698ULL, 0xB6A1E4F40CC2D9D8ULL, 
            0xD3B66BD0DC454439ULL, 0x5DC6DE1CF7461211ULL, 0x65E5A5F37CEEF0E9ULL, 0xF9F7F516211421BFULL, 
            0x96F97737A77FCC11ULL, 0xCFD7C1F4D193F2F7ULL, 0x557AFB2D6A4465BFULL, 0x7907DEFCC6BF81FFULL, 
            0xE97BC448597220E5ULL, 0xCE55E03BB56419E8ULL, 0x6BFA2D8CC4BDDD38ULL, 0x7BD24F1D97CFE933ULL, 
            0x153EC6844E144A46ULL, 0x5833DB9A4BF2D9F3ULL, 0xABC835B8B04BAC3AULL, 0xE9FA2DD0F84D913FULL, 
            0x5EB1621406AA5C33ULL, 0x0538C434AF748440ULL, 0x9375BA0FB9312895ULL, 0x83FF6B44E17B6415ULL
        },
        {
            0x3A330039842B56FDULL, 0xD5BC45A769B1DD44ULL, 0x90D0167FFF473F89ULL, 0xFACAF7D7E4F1B184ULL, 
            0xAD19BF0BCF676C53ULL, 0xF315B4B641CF21A5ULL, 0xD04F89A7476882A8ULL, 0x51BC5F2B3B4B7F99ULL, 
            0x40A9B9E1A18A9D52ULL, 0xE99FECBD1914AF7AULL, 0x68335C227E782724ULL, 0xA9757F09CCC4683BULL, 
            0x03945E38E1159784ULL, 0x4EE5ACCF37E1055DULL, 0xE2E4314F17B4FAA9ULL, 0xFD5E2622BF98E6C4ULL, 
            0x359942F6FC6CA79CULL, 0x12FF58B8909195A3ULL, 0x4078ADF6C4376A66ULL, 0x8665227F62270404ULL, 
            0x26887BFD849963E2ULL, 0x7A975CA12DE28D07ULL, 0x969E7800878547AFULL, 0x5F4C0E722CCAC588ULL, 
            0x74D536D0AEAB77AEULL, 0x97C1D44DE51DEE26ULL, 0x6DFAA06EC1814625ULL, 0xE373E0965C7F98DDULL, 
            0x03F416B2C8DC22D2ULL, 0x43FE1BE44EF3DE94ULL, 0x6D9F0D63CB879DDAULL, 0x8039DBD941F2AED8ULL
        },
        {
            0x91BF5BBD78B9E1E0ULL, 0x0EE60112C9D1679BULL, 0x9F2D0A39BBEE1AC0ULL, 0x5F48F80381792F6CULL, 
            0x3B47BA285CA9A22DULL, 0x6839EBAA928AA152ULL, 0x4F25F620AC2639A5ULL, 0x7A2B2148C57E413FULL, 
            0x16C843664FB18E89ULL, 0x50442E056F6170B0ULL, 0x421C28E8B64018B6ULL, 0xDDEE57406A906411ULL, 
            0x4F1F2E0D9A35131BULL, 0x1DA2B0685012400FULL, 0xFC2CF94CA1A00839ULL, 0xD1586C34E28FF855ULL, 
            0x1926C5A19951CD17ULL, 0x34677F05EBB442C2ULL, 0x8316C5F1711208D9ULL, 0xBE3597B744F954C8ULL, 
            0x836B65BA0F80CAFCULL, 0xA168B166679B09F6ULL, 0x9E609CCC66CFD0C1ULL, 0xCE79C40C61F403C6ULL, 
            0x4D3E42F4DEF910C4ULL, 0x70F00C22745077BDULL, 0x893F0196ED4169FDULL, 0x0B90643E7A0EDE45ULL, 
            0x560E94D6D6F2E529ULL, 0xB919D4EBFC9A7495ULL, 0xB57B57B64AEA1507ULL, 0x45A4E849E78D000DULL
        },
        {
            0xF48341F911011341ULL, 0xDA06F3927C63B639ULL, 0xA1F3BC0303896E74ULL, 0x360B717AB09237D0ULL, 
            0xC9FD61F8C193906CULL, 0xBACF8003A5257A1FULL, 0x42F7A01C51E88A53ULL, 0xAC39F23B862827A3ULL, 
            0x9A24F8FD0E61E02AULL, 0xC913A4C62B2CED1CULL, 0xC1D3C471A87F9C95ULL, 0x62138CB8B34C870AULL, 
            0x075C295AD6904036ULL, 0x93C769F19564DD14ULL, 0xE868349F39430343ULL, 0x11B62409815BE599ULL, 
            0x8CF03C16B50B3AF9ULL, 0x339DF844D0BF6AC4ULL, 0xDC3B4D734B410D0AULL, 0xF607D71F147D5FCDULL, 
            0xC020B448F8478F42ULL, 0xB9D7DDDAF8E66411ULL, 0x405D14ED802478B4ULL, 0xA7E990D53E83736AULL, 
            0x1967E0138A630B72ULL, 0xE8CD4134916A4784ULL, 0x80B34BB8CA57DE60ULL, 0xFA8E350A2C5E550DULL, 
            0xA9EAEBC76FFA291CULL, 0xAE49ABB4060FFDB4ULL, 0x842A402CDA541F15ULL, 0x21ED4AABA152011DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseDConstants = {
    0x0F8E3798331026E7ULL,
    0x7D1638026BD86CDDULL,
    0x3DE7933AE408050FULL,
    0x0F8E3798331026E7ULL,
    0x7D1638026BD86CDDULL,
    0x3DE7933AE408050FULL,
    0xF040D9540CDDAD08ULL,
    0xDD095B4BBF00ECF8ULL,
    0x32,
    0xCD,
    0x35,
    0x53,
    0x1D,
    0x3D,
    0x14,
    0x8D
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseESalts = {
    {
        {
            0x201286C05433DBD5ULL, 0xFF8686234BD5BE3CULL, 0x94B34F8EAC77A591ULL, 0xB28C2E6134F529CAULL, 
            0xBD50DA59F9E28095ULL, 0x7C6B903C3205E43CULL, 0x34ACE3C37C52093BULL, 0xE1EE8ABE4E1A048EULL, 
            0xD8A93819DC4762A9ULL, 0x1DCA5CAAC9E499C4ULL, 0x2966D4B470B41952ULL, 0x2A463BFA5D629775ULL, 
            0x4E2025BC82B5B6EFULL, 0x506EE32FC65FBA45ULL, 0x9E8A6F8115DAA152ULL, 0xBBB12E5EB37A6691ULL, 
            0x16AA4838D44E29CDULL, 0xA16F0328466D16DFULL, 0x9177C155C563AFAEULL, 0x9FC26D9AE624191EULL, 
            0x867D3F2002A3FB1EULL, 0x18B7E3D39C8204C7ULL, 0x0DD16EA7264295F5ULL, 0xA2AFA2E749F20A77ULL, 
            0x474297F939AFE02FULL, 0xE0ECF97F2C074247ULL, 0x3FB9E44046BD5CA3ULL, 0x236174E53C2BF9A7ULL, 
            0x9B456E6C1C4E88A4ULL, 0x2FE9A38978B8E0A5ULL, 0x6CB5708B82BCF9DFULL, 0x603056DAC5CF5293ULL
        },
        {
            0xC92B7E6189406447ULL, 0x5E5355ED678D9F25ULL, 0x5765DC15FADBF2A7ULL, 0xA910FCA36095CC55ULL, 
            0x719B6B9F0B0B1232ULL, 0x9D3987B4B30E9F66ULL, 0x725E215A45D4AC55ULL, 0x035F6BB179F8D333ULL, 
            0x623105CD3AE0CA64ULL, 0x4D53E78B91F5C34EULL, 0x2DEEC39AE98D558FULL, 0xD6C114AA645DB38FULL, 
            0xEDFBDB8885039BAEULL, 0x634B14286D32A3CCULL, 0x8F09C59081726281ULL, 0xABEA6BF8475FB5B8ULL, 
            0x706014AEB765EAC8ULL, 0xFDAD75876AA0AC7CULL, 0x6D0EE3C61E0A02DAULL, 0x3ADA73BD38A3C841ULL, 
            0x0C1153C2FCBDD6C5ULL, 0xCD7774CC8ADE3231ULL, 0xE2CD7980D7ED8486ULL, 0xBBE1EF5064AE855DULL, 
            0x6164ACDB7E3C89CEULL, 0xB2C3D74AABC2253EULL, 0x331FE50CE9D20330ULL, 0x20B4768760256709ULL, 
            0x61A68BC784323CECULL, 0xFA690ABFDEFCA03AULL, 0x3EB3A9F0C326182AULL, 0x77C77B29CED0F84FULL
        },
        {
            0xC2B63876D7370267ULL, 0xDFCEF59FB42DB4D4ULL, 0x96BED72091DBB21DULL, 0xAF09F18AE99C43A1ULL, 
            0x420B35A4C0C688DEULL, 0xAAB49222EBA36A89ULL, 0x7CF56C91965ED368ULL, 0x00713733076B0418ULL, 
            0x1964030187E9F695ULL, 0xDE15CFA4B1FDB8B7ULL, 0x9C04EF9817545D08ULL, 0x67578FFA72B580D3ULL, 
            0x4DBB1818975D4858ULL, 0x1EEB78FAF4D2CF02ULL, 0x30439427E4094EB8ULL, 0x6D8BD0FAD68AD3ADULL, 
            0x97D85BC59D410AF1ULL, 0x0DE1812AFB5A17E3ULL, 0xAFE7B61AF5597BBBULL, 0x53C126527729879DULL, 
            0xE6C315F2246C6196ULL, 0xF0195D17A2403566ULL, 0x99E06452446EC30DULL, 0x98A7989A9B4DB656ULL, 
            0x03745EE588359A8EULL, 0x929AFB02C4389CAEULL, 0x0ACBD2D4B9E4B8DEULL, 0xA45D2D6318BE740FULL, 
            0x28BA3F0D6D5FFFE3ULL, 0x734AE69809FF0200ULL, 0xA0FCE1367BB2B187ULL, 0xD8905365AE170153ULL
        },
        {
            0x1B6383F803FA3269ULL, 0x8E30BB4BF99F1EB2ULL, 0x893F533B21EFE45EULL, 0xCFFA586B44C15622ULL, 
            0x7F9DF62AAEC3E847ULL, 0xE1112C5271AB72BAULL, 0xAE935157F4A9E51EULL, 0x7F4914668872C105ULL, 
            0x7087BAA6C77856A7ULL, 0xCCECED5831A0B875ULL, 0xEDCBF01DADEF7CDFULL, 0x2717523C615F13F9ULL, 
            0x64C07755C80B2081ULL, 0xCCDC287CC0A8A90EULL, 0x43226AAA07DA7147ULL, 0x0AF6476C84F556DEULL, 
            0xE46DB359FF700E29ULL, 0x855AA347797261F4ULL, 0xC1BC6C536660C5BAULL, 0x08AD8ED7FC57D502ULL, 
            0x32AFEFE761D15ADDULL, 0x299B8786398D048CULL, 0x0F87B29E7FC234A0ULL, 0x755FEA12B990843EULL, 
            0x362DFAD50BB4480CULL, 0xEEC0B3B8588A97B0ULL, 0x192466D3EAC8B788ULL, 0x57C4A480814805A3ULL, 
            0xB136928897DEBE51ULL, 0xB95D5B30BBA42EEAULL, 0xC0A58FF88C2BB425ULL, 0x86F4968BA437CA84ULL
        },
        {
            0x99E410A4410B2FDFULL, 0xC1ECE1AFF8D8765FULL, 0xD5A40E62ADB926E0ULL, 0x4F97DB4F196F27E2ULL, 
            0x9FA3E0C0DCE4A3DCULL, 0xFE66C2B9AC1CD622ULL, 0x10C5CFF2EBCC60DBULL, 0xFA01EF669F5A7E3CULL, 
            0xFBBC81119AADEF1AULL, 0x7C05156D6A2ABEC7ULL, 0x73D72BB6D8ACCD81ULL, 0x79D6D7F2C20F5709ULL, 
            0x046ACC43CD747CD1ULL, 0xEA05576FCA7592CDULL, 0x484E0AF3F0A7F1D0ULL, 0xCAA13F0E278A37C5ULL, 
            0x3485BA57598DA936ULL, 0xEF0D0259B06E651CULL, 0xD11DBE370302BF49ULL, 0xBDBC2431F8A20FE9ULL, 
            0xF8CBB93FBFCFC24DULL, 0xC1C256D56ADC1218ULL, 0xDB1C9D052E4578EFULL, 0x655635789B4E0F9EULL, 
            0x1AA4E729A84ADD71ULL, 0x6C6AE4F584DEFD22ULL, 0xA56C6477D49A6EB5ULL, 0x7260637A6511FD4AULL, 
            0xC18D9D16CD011FA9ULL, 0x6AFE645E07A100BEULL, 0x997CD3CD62F08C53ULL, 0x4491E25C43A21E7BULL
        },
        {
            0xE72EE168B4D164A6ULL, 0x1A046E3092DFD578ULL, 0x7CDDFFFA134296CCULL, 0xB5741B75CF5D2191ULL, 
            0x6AE13CC43406226CULL, 0x897D4DF83B8F7BC4ULL, 0x05CC371B2CABF04AULL, 0xB862626A77542C89ULL, 
            0xCAAA82EF92545A59ULL, 0x00DDBCE21785C247ULL, 0x84E95C23E23EF54DULL, 0x9BB8F0066E646A96ULL, 
            0xCF4DAF519274B317ULL, 0x0C0D9175A6218C6FULL, 0x86F52B23490DEBECULL, 0x086B4D700417FBB6ULL, 
            0x9D4BAAE82E85531FULL, 0x04F693B5AE71E0DBULL, 0xF07EE99164988EADULL, 0xE42CD1C59C6EEF37ULL, 
            0xCD9B85E7D73231EDULL, 0x7EE15CF6037BB0BFULL, 0x93F21A1FDDBFD765ULL, 0x5BB12B8A7006B215ULL, 
            0xEF1393011BA095AAULL, 0x3754E7548C249C85ULL, 0x537FBE8EA329132AULL, 0x4C2EC42E4ACA9E76ULL, 
            0xC294B8680440C944ULL, 0x96A6702777922F96ULL, 0x15CB29441552904EULL, 0xEDCF76809D77D6F6ULL
        }
    },
    {
        {
            0xA9B7279B5AD4BE18ULL, 0xDF35C3DF8A936166ULL, 0xD1B8D8C79A3CEA84ULL, 0xEC830BFFDE359DFCULL, 
            0xD7064BD6B3E4C88CULL, 0x353EB2838B7F284FULL, 0x24ED7622814BAD5CULL, 0xBA67362AF22D7468ULL, 
            0x317AFF746F1E3C36ULL, 0x17668FC61C405524ULL, 0x70A6A457342FB282ULL, 0x1CB75A25FA205419ULL, 
            0x83E0AA8B1BC6AD56ULL, 0xB95F21878ACA1B2EULL, 0x68DE0615D908436FULL, 0x97FC68ABA16AD60DULL, 
            0x68D6CB4BBB0669E1ULL, 0xB39463F74F04C83BULL, 0x4F35D86FFE6256DDULL, 0x5543D3999376A144ULL, 
            0x7902C856146F9AF6ULL, 0xD26D166C7FBA8166ULL, 0x45AE54B9BE4E191FULL, 0x0C5250B80727FCB9ULL, 
            0xA8CF831816AEDC07ULL, 0x4B0E856C58A70EECULL, 0x5FE7E3B96EE4D01BULL, 0xE22715E42BB5C69EULL, 
            0xF47E0FF02FB3E399ULL, 0x4664B4CF009C1BDCULL, 0x710C44B333A6E271ULL, 0x9CE56A687EA6392BULL
        },
        {
            0x35E82A36AF0E4193ULL, 0xF813E1B720C1FA23ULL, 0xF718E160A861D7ECULL, 0xAA049475844881FFULL, 
            0x65977D53F6C78534ULL, 0x28A9DA1048C564F1ULL, 0x5BB8CF1DDC5D92BEULL, 0xEFB1E84DDF8F2868ULL, 
            0x7123EF0F8B18298FULL, 0x4FB5C765AF383A41ULL, 0xC3CD3BB29DE33224ULL, 0xB3C8F0B891F000B2ULL, 
            0xA42365AA253BDAE8ULL, 0xA29BC6E1E541B15AULL, 0xDEEA3777ADC2316CULL, 0x3D8046C5DB88A420ULL, 
            0x612790EA876342D4ULL, 0xBE654319D5D03FEDULL, 0xFCC3B638A3952C30ULL, 0x1D90E3862FA5B70FULL, 
            0x4EDDBBDF1FD9FB2CULL, 0x6FD38CDD76D11734ULL, 0x4EE74D5FA9004757ULL, 0x7DB383F3C7AEF4E0ULL, 
            0xBBCFC6E109897A10ULL, 0x10D4122A8FD335E1ULL, 0xC04AE99CD643FCECULL, 0xF3944BBDBC364BE9ULL, 
            0x3E78694082FC4843ULL, 0x04DDA3D97A9CD83AULL, 0xE82AB0B0F78951E6ULL, 0x4BA17B3DEACE1F99ULL
        },
        {
            0x4F337D4D15C0B288ULL, 0x5997082DE3220001ULL, 0x277562C4420A7297ULL, 0xED70B5A75A193A6BULL, 
            0x55ADF4E56FDCFCE4ULL, 0xBFFC79F15639B228ULL, 0x8BA05CF6E84C5178ULL, 0xA844422EB5A67BFFULL, 
            0x25385C1683762DE0ULL, 0x96DD65BD22BAB48EULL, 0x4A270477CB598664ULL, 0xBD76B80642E0C2F4ULL, 
            0xD5E423F7D3B416E9ULL, 0x152BC31D28073F57ULL, 0x0DB35872F71BFBE3ULL, 0x0916484DE96106ACULL, 
            0x08C764763D8426DBULL, 0xED736487A8BA9C3DULL, 0xE68AD0EFD5274811ULL, 0x0B7ACFBD6CEE2012ULL, 
            0x37F5927CF235D837ULL, 0xF91C106B3D8D1536ULL, 0x2ACFA41535A2FEFCULL, 0xE1B5EFDF53728C81ULL, 
            0x95D60CA6DD26C4DAULL, 0xCCCC3C424B773D5BULL, 0xDF5523E606EE6954ULL, 0x831FDF1C2F70284FULL, 
            0x2819D494A6937B37ULL, 0x46DCAD0987B92DA7ULL, 0x745869324B79533AULL, 0xA7D5A3E1C50B97DDULL
        },
        {
            0x0EE4D2747602525FULL, 0xC3AC7E12ECAFE696ULL, 0x3292487A2B2F680CULL, 0x01A2A12C2003AE7BULL, 
            0xD3DD16BCA227193FULL, 0xEFCA306747D4D644ULL, 0x292CB48986A71C6DULL, 0xC5AB5D6065159AA3ULL, 
            0xDDAF59838384AFD0ULL, 0x98BC8E0282230DC0ULL, 0xBC7568DF88652A69ULL, 0xB10FF8593506E644ULL, 
            0xA11F0144F830754AULL, 0x809045C10A05039EULL, 0x925407721B9D5220ULL, 0x9696FAF2051B9999ULL, 
            0x112473254B25334FULL, 0x16C95771F7B14535ULL, 0x107807BA920C5B88ULL, 0x5516A326C1B24859ULL, 
            0x214514F952D45BD8ULL, 0x741B2076502BD99FULL, 0x16CE629EBD52439DULL, 0x81368962721894DDULL, 
            0x5F99BAE9FAE3CF97ULL, 0xCD2C5D9058DDAE1EULL, 0x55E296A0486C5FE6ULL, 0xF6742ACB569E26B7ULL, 
            0xD147A33B227713CBULL, 0xC2B0D99625CE2AEEULL, 0x362FDF92863F38EDULL, 0x2C2DDB565997024DULL
        },
        {
            0xF4478116ECB504D8ULL, 0x6EB13DD030BFFE17ULL, 0xEE4DDFB50F47893CULL, 0xB89522B2DF15A0C8ULL, 
            0x55C30B82A2195F09ULL, 0xE6604D9FF356CC5AULL, 0x83AC4A85BB9E3ACDULL, 0x97B357DD51FFF3D7ULL, 
            0x3D785F279EDAB133ULL, 0x667723690F9C604BULL, 0xD03E1720A4769F70ULL, 0x01BA3F78FEA2212CULL, 
            0xE8658E176E5AF10FULL, 0x3A99490B144B5B9EULL, 0x53D7552E6D90E181ULL, 0xFB77CCD30BE0A2B3ULL, 
            0xC3224EBC4F03A32FULL, 0xC36BF2EA8939F76FULL, 0x24DFFF898EA1039DULL, 0xE8D67CA3C5EBC6DEULL, 
            0xBC8EBB4612BF3D6AULL, 0x7F97C0FA51805562ULL, 0xC4DEF83D7269443FULL, 0x4AFC9DCC8FFA6B1EULL, 
            0xFAFA6EE6FEBD6E73ULL, 0x71BB86E92CEB9129ULL, 0xDD51965DCEBD8F80ULL, 0xAE5C33A53049FA56ULL, 
            0x88B0978F283B3BC6ULL, 0x903025B6CC364ADCULL, 0x48BF8166D240A054ULL, 0x33C844292EAE4057ULL
        },
        {
            0xE9546B3085E22193ULL, 0x01AC73E40F18DBCBULL, 0x7FF03C5BA99F867DULL, 0x81F0E4211980384AULL, 
            0xAF4892BD59BB9145ULL, 0x5B60855909BEF757ULL, 0x85FBE0E6276B412CULL, 0x90F5BC45A4FBA2DFULL, 
            0xBE8B37C49B151319ULL, 0x8416C68B6C399EA6ULL, 0xD12C63949EF8F5B0ULL, 0x1356DE5CD1A07117ULL, 
            0x163064C64AB523CDULL, 0xEAB8BB36D34E9CFEULL, 0xD3EB9A6E79D38FEDULL, 0x694C86C24B5AA011ULL, 
            0x2AFE0316CE61E894ULL, 0xB1AEAC1A698DEBE0ULL, 0x0603142938366880ULL, 0xB5FCE91CA7C791E0ULL, 
            0xCF2687A6880002E1ULL, 0xE6116BDCF893A97EULL, 0x73CDB20F9AF281B5ULL, 0x1B6A16C7D5D3E853ULL, 
            0xF8DA8BC63CE18D95ULL, 0x12AD34CA87836EC3ULL, 0x2C99A007451AD832ULL, 0xB15A762745C29A70ULL, 
            0x3E81DEA58D4B8D41ULL, 0x800502013A3B3B1FULL, 0x1A4653B5D129D938ULL, 0x6B45C655C29B9EA2ULL
        }
    },
    {
        {
            0x8475B99BDDC27C9EULL, 0xB0C4341B7CE531BEULL, 0xA4A0A9E4BA6335B7ULL, 0x7340A255DDB5EA47ULL, 
            0x566146282DC35570ULL, 0x921E629597642F6AULL, 0x597CCCA3754C7CCEULL, 0x6E233DBB2540AD00ULL, 
            0x3031B1CE196A2B3FULL, 0x643068F492C279CFULL, 0xAA835D3DCB800794ULL, 0x29C8888ABF3552B2ULL, 
            0xB75B74B4857942C4ULL, 0x4A1AB46F6C424FF3ULL, 0x14C27058EA89CF5EULL, 0xF5EBFBB5D92A39C5ULL, 
            0xE2E7D92805C2957DULL, 0x594C97D10A22A204ULL, 0x62416A9FAE1647A1ULL, 0xB2FB43E7780AE6F8ULL, 
            0x52EAE02023B22DBDULL, 0x5D728061BB98A8D2ULL, 0xF80111A299CFDA41ULL, 0x29256B4560A210DFULL, 
            0xB0A64EA76C644622ULL, 0xEA986520E4403677ULL, 0xC08BCE01C9D01C8AULL, 0x76BC4B274D419155ULL, 
            0x14EFD63A3ED520D3ULL, 0xACF06F743B43952DULL, 0xA86ABABCED99D080ULL, 0x77F69B706ED4127DULL
        },
        {
            0x8D0C595E2067EB52ULL, 0xB122E44512A71612ULL, 0x95908D1A60C24FEBULL, 0xB2B371B8F2F015A8ULL, 
            0x5FF6DC6827A623E2ULL, 0x128299AD374ADBDDULL, 0xA930ED4C21BBAB13ULL, 0xDF11A86531759F6FULL, 
            0x0413BE779B167D65ULL, 0x49A958DD9C852719ULL, 0xD4F5428ABA9A3675ULL, 0x763DB8DA8C6CD210ULL, 
            0xA3E3FDA5C83714E6ULL, 0x8122040FC55CDB4FULL, 0xF5862B173E3014DAULL, 0x1C83D98FB58B5BEEULL, 
            0x6E4A710724261D2CULL, 0x8CF870404D0AB9DFULL, 0x1288DC970E9413C5ULL, 0x406657886710DDF4ULL, 
            0x15A5B3716442AF0DULL, 0x89EA6BA6278F9316ULL, 0x62AFF16AEC5546B9ULL, 0xF8AA0290561CE920ULL, 
            0x47184E26F6B1C34EULL, 0x2EDA94915451E948ULL, 0xAF258E1363776F53ULL, 0x0A90F9DF8CC189D0ULL, 
            0xE2AF68A334FB1BD1ULL, 0x10905AEB8550B0F2ULL, 0x6162A0A1B36EC9B3ULL, 0x969978D8413595A6ULL
        },
        {
            0xEA80573744435E40ULL, 0xF0B06E4AC223AC7DULL, 0x99A95672FB62F7EBULL, 0x8368945570F737E3ULL, 
            0x52EA51D04BF3D89CULL, 0xEAEBAB401FDFEDDBULL, 0xD8CD080CDD5C049FULL, 0x2DD5C4253D66ED42ULL, 
            0x7054D480B2205E23ULL, 0x7D27C450E756D1B2ULL, 0x2CA6222B80F9900EULL, 0x07561290ACD33B8EULL, 
            0xA0203F524052CE0BULL, 0x6AAA4B49F5296A85ULL, 0x04641955AA463690ULL, 0x275AFE5D065C1E6BULL, 
            0xC1480DD9D3DEB1EEULL, 0xCC38AF62B949FEE5ULL, 0x3F4A78B422103794ULL, 0x719140E35A10C2B1ULL, 
            0xDB25DC7385410CD6ULL, 0xE5D9A935056B5885ULL, 0xF1DBE5CA5C261411ULL, 0x61A57538989BF240ULL, 
            0xAA5F012C8AAF24CDULL, 0xAC17DAB6513D6C8DULL, 0x4B84A3368F8D048CULL, 0x79FE557622493305ULL, 
            0x5AB4E0481E3D6800ULL, 0xB546DE1BBB3B90E3ULL, 0x5A06F735A9578FC3ULL, 0x517E29B0ADD4FADFULL
        },
        {
            0x317B474D93BBFE82ULL, 0x24FCBA49203B7FC7ULL, 0x0720683E511D5F82ULL, 0xB84F57A7E37E8064ULL, 
            0xB8A95101604C2E9DULL, 0x00CE7D6B5E0F7F7CULL, 0x563E58B353AF6335ULL, 0x74D32660C3CA28FAULL, 
            0xFDFD09888C9A7C6FULL, 0x0E5EE574678886B9ULL, 0x05E34A38C26D09C7ULL, 0xFD4CE18061EA5D20ULL, 
            0x209E1770A5ED8CC7ULL, 0x2D1A5CE470476503ULL, 0x26F6C4ABAE5EBE41ULL, 0x650150D62A10BDB6ULL, 
            0x09348479541EDE88ULL, 0x080A0ECF97F18599ULL, 0xB380A8FEDD286FDBULL, 0x9DC7E24AF993684CULL, 
            0xDDB2525D240F86D2ULL, 0x074AF6E12946B05AULL, 0x24C1B291AB46C4C4ULL, 0xDAE0543EE51AC2FEULL, 
            0xC30063B9941CEE05ULL, 0xE13EFE97A6FA4AE2ULL, 0x57F051AB2E38DA46ULL, 0x263F5C76048EED2CULL, 
            0x832DAA2692E85DCFULL, 0x938C67A44032AF0BULL, 0x5AF27589FE5623D5ULL, 0xB0873E8B9D7544B6ULL
        },
        {
            0x545A2ED87AC0676AULL, 0x978A905F48ED6079ULL, 0x257C5E5391E87FD0ULL, 0xE28A8D04A1F7704DULL, 
            0xB97F8A7B41EB282BULL, 0xF5E32B68C970680EULL, 0x83D5EE4FE72E197AULL, 0x6109903E395D52ACULL, 
            0x299D3AB947571BD9ULL, 0xB7A1DCED47DF526CULL, 0x62BD62E6D635D844ULL, 0xEE3CC5B14C12EA5FULL, 
            0x08B8E8808B5E114FULL, 0x4F865E52646F0063ULL, 0x6EE29BDD0589C866ULL, 0x65E48A63BD126C0AULL, 
            0xBAEDFFB2EF7C9C68ULL, 0xB5D9CABFC2883B0EULL, 0xD1E19B160E42BF23ULL, 0xDEB994201DE43FA4ULL, 
            0xA970078F0442ACDAULL, 0x2557B4E5574FA4DBULL, 0x0580B8677295341CULL, 0x3A37CC4EC25C8035ULL, 
            0x1088BA02EF89BC67ULL, 0x9389DB50AC97916BULL, 0xE6E42A9D9F3B7562ULL, 0xA03FDFE90359FD2FULL, 
            0x079D4D7ABBD8EDD7ULL, 0x7294387858EFC6C4ULL, 0x28F572FA83062F66ULL, 0x6EC1BA844D65C993ULL
        },
        {
            0xAA098ECDE7C2D797ULL, 0xF38447BFC9997B93ULL, 0x01241C2CDB980FF2ULL, 0x0192FF9F39DC4B3CULL, 
            0x571AA4EC6739B9A6ULL, 0x8E6C3D00C7FED775ULL, 0x7B68C42D2783A199ULL, 0x17749B81C94FF05AULL, 
            0xD7C3EE1CEBA35BD9ULL, 0xDBD843BE5DFE9057ULL, 0x5607D2A93230EAC6ULL, 0x6B1A49BABDD7D89DULL, 
            0xB441CFA23195766FULL, 0xFD8EFD26C789C979ULL, 0x554068F590C071E5ULL, 0xC4885626609ADA58ULL, 
            0x3117EAB71241AC0DULL, 0x0224169FDC5FF10CULL, 0x97DACCABD5E8B091ULL, 0xD69B731E36CFE98CULL, 
            0x199C1A1E573C77A7ULL, 0x6429008DA13BC77BULL, 0xD81D0BC70891914EULL, 0x89FE6BEA78E0432CULL, 
            0xE868AEE5CA2317C2ULL, 0x13FDA71E908A02CAULL, 0x6AB39E170CC46C68ULL, 0xE61721A3E03AE199ULL, 
            0x88B501CEFBFF8BC8ULL, 0x80A9E9AF1999C479ULL, 0x4A4508C49EF3451AULL, 0x6FBE5EA87C89A837ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseEConstants = {
    0xD4C3C7CA05999E55ULL,
    0x6AACC3538AC6E0C6ULL,
    0xCB3465ADD4EE5742ULL,
    0xD4C3C7CA05999E55ULL,
    0x6AACC3538AC6E0C6ULL,
    0xCB3465ADD4EE5742ULL,
    0x68533BC5EA5EA664ULL,
    0xD39F504C5D8BB4B1ULL,
    0xDD,
    0x31,
    0xB0,
    0x82,
    0xCC,
    0x1D,
    0x83,
    0xBA
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseFSalts = {
    {
        {
            0xF3BF9B6E33E31289ULL, 0x8C8A4DCC3A7C6FF5ULL, 0x843C9D4955D09CF6ULL, 0x48F6A96ED8F6DC89ULL, 
            0x03DB7E11E5C1B695ULL, 0xCB620F2088DB3E9CULL, 0xD0C9430B620EC379ULL, 0xDC63D07E12BC0888ULL, 
            0x10DA8E689F00C295ULL, 0x52C58EDFEFF17EDFULL, 0xCC016B1632A50073ULL, 0x3D19A40003FF4702ULL, 
            0x2A28A311F0808E68ULL, 0xE06507736BF98BDDULL, 0x86668D83F9F14312ULL, 0xE87E90725CC15426ULL, 
            0x093BBBDBFACFCEA5ULL, 0x0871C902F8524FACULL, 0x02BB4B3D57C19126ULL, 0xDBCBDE2DF3400EB2ULL, 
            0xA6EA708DDE8E58B1ULL, 0x13B0D7411B2E29A0ULL, 0xBF2E33024A976490ULL, 0x4A2C458DAE3B434CULL, 
            0x8BBC8CFFB8B0CA74ULL, 0x4B641364F7A1C6ECULL, 0x12779FC0F7677987ULL, 0xEAECFD5A357DA669ULL, 
            0x51626F0C1F264015ULL, 0xACF69E096D372678ULL, 0xF588B95C3872E072ULL, 0x59EC988E40678D34ULL
        },
        {
            0x05F9D74998E8FCD6ULL, 0xA218E47774373EDAULL, 0xE6297EDFFD370CB2ULL, 0x7869EA14D18C12B8ULL, 
            0x223C7C07249E91BEULL, 0x5DEA74C25282F81BULL, 0x407B5B22C2F7CB3EULL, 0xCAEACFB362ECEF27ULL, 
            0x2A39EF2BBA9E8627ULL, 0xB5BD3BB7F526C263ULL, 0xE3B35E157C0C864EULL, 0x38C750BA08CF7A11ULL, 
            0x1BA46EAA56D8E7C9ULL, 0x351A32F8DBF984B8ULL, 0xA828D493C48817F4ULL, 0xF0FD09D4308B1535ULL, 
            0x96822B5369F65EDBULL, 0x8D4B54BFA0EABB22ULL, 0x26D514E38645DFC6ULL, 0xDFAE95A6BB4451B1ULL, 
            0xC040C7C69D63DF5AULL, 0x9586E3EA1EF483DBULL, 0x6CBEB9E002DAB237ULL, 0xEA531BABF5FDAE7FULL, 
            0x86D1FFE42771A302ULL, 0x32A6A1D02436B5C7ULL, 0x794939F7CB265FC2ULL, 0x07188C106C55A0E7ULL, 
            0x724B6AA2217931B8ULL, 0x7FA27D4AF8AA95A3ULL, 0xC6E4F1C402C01ABAULL, 0x4FB73B41381A47B7ULL
        },
        {
            0xEA350EA83CF31D6CULL, 0xA506C3030389865AULL, 0xB49D898CC96786CAULL, 0x70339D8425DDAAC5ULL, 
            0xE5E5F90ED36395BEULL, 0x3BA9A6ED2F04E0D1ULL, 0xE9CEA38C36B11032ULL, 0x9EAEC49E7A745557ULL, 
            0xBAFA319E3C21AA44ULL, 0xC26FDB6A8985B934ULL, 0x74349E84EC1F4D82ULL, 0x4B5E9352138D52A5ULL, 
            0xDDD5EE352A8AC866ULL, 0xE5E11FEBD7B32179ULL, 0x78E77270A18B86FCULL, 0x223D525A40CB423AULL, 
            0x3C2AABC26E6064E4ULL, 0xAD85C713EC1F5476ULL, 0xC480D02772CD86ACULL, 0xDE46FD54B8A5B03FULL, 
            0x4DCD8EF4F673141CULL, 0x744A4535E44BFE70ULL, 0x79230B669F678069ULL, 0x94F0BD9877FAF341ULL, 
            0x2C55E223FC34BA8CULL, 0x81E91E245FA046A8ULL, 0x66710210FFC8FA59ULL, 0x4A5A42722572DFC5ULL, 
            0xE22103BA34E90220ULL, 0xB6B4124039E1DB72ULL, 0x5E91A57538317942ULL, 0xB208FBB48EB14FCCULL
        },
        {
            0xAB4402B85CA0CD79ULL, 0x61842A1010536715ULL, 0x1BDE31710E28DE5DULL, 0xBF2C040278E31C28ULL, 
            0xA4E73FA8981E35D3ULL, 0xBDE72AFE23F857A2ULL, 0x3A8359DF7CE77C35ULL, 0xD7777D9628816602ULL, 
            0xCF8D6A3AE4891D1CULL, 0xB17940C4D97B87D5ULL, 0x9FDA0E88780C969EULL, 0x14CBA4FCB81186C8ULL, 
            0x7D21A169F398F9DBULL, 0x362D5B01E4DE3C31ULL, 0xBC4AEF8B8A2546F6ULL, 0xBE968CF13EED8467ULL, 
            0x93709F5C71049D5BULL, 0x5FC7C5600F75679BULL, 0xD1AD2799D3ACB701ULL, 0xDC2DA18B79A33931ULL, 
            0xAFFC42651FFD1F78ULL, 0x00EEE8899428F49DULL, 0x8988E4D62C650CAFULL, 0xFB7C1D68F2EA77B0ULL, 
            0x04F6521CC7EE5B55ULL, 0x6846668A6015362AULL, 0xD73EA818F78F0EA3ULL, 0x89CE6DFB90D8A8B7ULL, 
            0x020BA1169CCCBF35ULL, 0x30380EB66D2E735AULL, 0x45B27AB3B06C8D41ULL, 0xA97865724273C724ULL
        },
        {
            0x66939B12AAD2464FULL, 0x8A1B7E09C483D7EFULL, 0x01971225738E6305ULL, 0xCF91948C3225AB7FULL, 
            0xFE51842D875520E4ULL, 0xA20E5C96921B5E6DULL, 0x8D99A5B4BF04A22EULL, 0x77C2175AE420E1C7ULL, 
            0x1538700FFDF37B37ULL, 0x8B31D28DBBC62A3CULL, 0xF9A070D3259F4B90ULL, 0x170B9040139B48F8ULL, 
            0xF97C28B128641B1EULL, 0x93515DCA5F1D83D8ULL, 0x850B967C1FAEA259ULL, 0xD9D8F431D891CA1DULL, 
            0x3C642A4CE00099EEULL, 0x8842A7DD1040BAF4ULL, 0x0D1CCEF5E7EB5121ULL, 0x84C35E035E8AAF13ULL, 
            0x96E564446B919548ULL, 0xFCCA5F646785274AULL, 0x31DF14C289A9D4EFULL, 0x547E2B46ADB5C344ULL, 
            0xE752EA80AC49E403ULL, 0x78A551DDBCF4AE8CULL, 0xE4654725EC2E427FULL, 0xA03532848530D102ULL, 
            0x016D7A82A27F50F7ULL, 0x48B77106723AFEEFULL, 0x5F3742040F77677CULL, 0x420690B0F06B1DDEULL
        },
        {
            0x28AFDC19F4AF993BULL, 0xB2924D2A86C63C29ULL, 0xA640B1FA16DEACCEULL, 0x0E618A4F4C5C4B5DULL, 
            0xEBA45D415C4AABC8ULL, 0x746717A9CC53859EULL, 0x42174A821E0BBCCCULL, 0xFCC3FD892E5E7AE9ULL, 
            0xB6D82E6806E694DFULL, 0xBEF63F07A212A5F1ULL, 0xF6EE96D8AA4C7CB2ULL, 0xF801C34C5F9AF74EULL, 
            0x18ADE228F1ED90FCULL, 0x53212BB3EC87909FULL, 0xABB8D785072A31FFULL, 0x1947337DFE939055ULL, 
            0x7A412F4343453D6BULL, 0x006E37F58D95EE45ULL, 0x0269D0F43201C3CEULL, 0x3E4BC7E8DDA41753ULL, 
            0x72BE8F7EBEDC8947ULL, 0x66AA84F95FD12942ULL, 0xA3FE6244DFBEEB4FULL, 0x636663C44C598615ULL, 
            0x40A6D4B900DC2594ULL, 0x4831372759452A8DULL, 0x45E6F3CCADECA667ULL, 0x831F3DD59C8E1D06ULL, 
            0x3DA501170B4078C3ULL, 0x6DD2BB5612E195D3ULL, 0x0614B87322A59569ULL, 0xE60A8AFC6C225D89ULL
        }
    },
    {
        {
            0xEF71E5587E063951ULL, 0xDAA185A5992A3BAAULL, 0x80E885334C5F3CF5ULL, 0x64878A339E5CFF07ULL, 
            0x850DF452B78DFF2BULL, 0xD47DC2E640BC323AULL, 0xEF9E1C66046A58EDULL, 0x78993B033051C418ULL, 
            0xE53762E7683AAA01ULL, 0x6294716F917B5C7AULL, 0xF30111F8DF412D11ULL, 0xCEAE5026FD4ABE6DULL, 
            0xB75E60AD5CD9ECEDULL, 0x868DA961BFC5D423ULL, 0x2C494686D064E0B8ULL, 0xF44DB2F1C885B406ULL, 
            0x6EF3BA9AF25939BDULL, 0x3D80438012108C6EULL, 0xBEF52EA1CF1EC6B4ULL, 0x54EBA8823FA20F06ULL, 
            0x24B5F61E2A9E617DULL, 0x61D8580427DB31F3ULL, 0x5EC1814E359B9236ULL, 0x672053E9B26AD56FULL, 
            0x1BECC08CCD0C8AFAULL, 0x7D6C639CC1509E33ULL, 0xEE93898642B02ADEULL, 0xDAAEEBEC5829CCD5ULL, 
            0x7D4AB98587530976ULL, 0x2B552B29ADAF6B08ULL, 0xBFD46EEBA5001949ULL, 0x56FA2FD7BC56023BULL
        },
        {
            0x92B2E2EC97627F15ULL, 0x1A1FC879F4B9EFC6ULL, 0xC844500809B54DF1ULL, 0x5DCFEB1D29EF42DAULL, 
            0x1B11C390C6E10AA9ULL, 0x13A5EB6B368C7D46ULL, 0xE1E9E372892012C2ULL, 0xD2FEC2585463A436ULL, 
            0xEFB869252E1F7CB6ULL, 0x126FCBC3991858E3ULL, 0x5354392B156EA4F0ULL, 0x239BFD655CA62C96ULL, 
            0x5A2C25E5A94AD835ULL, 0x97FCACFC22D597EDULL, 0x1BF1A570F68001CFULL, 0x267E6002DB607FF2ULL, 
            0xDF234E3324435D58ULL, 0x774CF73AA27D13CCULL, 0xAE5382CE5B3F7D0FULL, 0x1ACC6CC30FD822D9ULL, 
            0x1F6D35622881E0F4ULL, 0xB2AF8A51DA565239ULL, 0x73D7C5DEFEA5218FULL, 0x50A63CF57F81EE91ULL, 
            0x8F849F63E59ABE0DULL, 0xF0B41B97FCA77882ULL, 0x09A906328E4E331BULL, 0xD84EF8BEEF00EEDFULL, 
            0xE8CD4AC4463E42B9ULL, 0x8459E921CE2A000FULL, 0xE899B87F088B24B8ULL, 0x71086E1C7E6240D7ULL
        },
        {
            0x3494B63B0BFE697AULL, 0x7A5E401677F1B92DULL, 0x105A65CA45273B0DULL, 0x73181A9FB22F6184ULL, 
            0xE6B2B52112907DE7ULL, 0x8B6D0AECE8909614ULL, 0xAAD24FED2AB509D2ULL, 0xD5F77B024B20EFB6ULL, 
            0x4189FA8A721B8A0EULL, 0xAAC15EFEB5CA5635ULL, 0x527D2AF03670D881ULL, 0xE8B59086A4FBE3E8ULL, 
            0xBD6D1A89AF9D7F8FULL, 0x3269A3EA8A86C629ULL, 0x1BCE904F8EF4AAD3ULL, 0xAA496B11925E9D0EULL, 
            0x0518BFE8305FCAC0ULL, 0x698557139FADDFDEULL, 0x1A4123B414D4F3C7ULL, 0x92E330D2FA195EC6ULL, 
            0x774AD10F6CF0A9F6ULL, 0x85B6833CB741AD53ULL, 0xE5BE4F7AC9085011ULL, 0xB865C67E4A074BFFULL, 
            0x268622F1A24ED37BULL, 0xEEEA84BB0016CBABULL, 0xDE6EC7E6BAD4B053ULL, 0x72F343CA89673D41ULL, 
            0xA9159C0F49889AEEULL, 0x14E1067B7AC95FF1ULL, 0x4108740195ED6C9FULL, 0xAB519014FAF48E20ULL
        },
        {
            0xC56AA4D6781E09F9ULL, 0x339910825AAB39F7ULL, 0x2590E35BA989E88DULL, 0xAB81364777097563ULL, 
            0x9809749D57D4A8ABULL, 0x55E74138F9539214ULL, 0xBFCF04177D859376ULL, 0xA746989B979BC4BEULL, 
            0x969255A1B48AF93CULL, 0xCEB65768F29265D2ULL, 0x6ED3CCE90ECE9B4CULL, 0x3748B60ADF2F6E95ULL, 
            0x08708FD9A9309393ULL, 0x11156AB96FB514EFULL, 0xBD404EEC7ED6204AULL, 0xE4DFED2803EB1CE6ULL, 
            0x409E3D8FC1EADEB3ULL, 0xDCE76756572A547AULL, 0x270D0E730D4243FAULL, 0x937556B57ADF2246ULL, 
            0x44908D164E1510AFULL, 0x9228F3AFE60777BDULL, 0x49431F10DD5A6918ULL, 0xCAEFDAFA38B64638ULL, 
            0x2B4F3DCAF77FB13BULL, 0x2B69B9432B994CF8ULL, 0xB9600777E3289796ULL, 0x6F80F98457471CA2ULL, 
            0x7E9679172CFE41C6ULL, 0xAA360210A7C4719AULL, 0xCAF5E30CCAF3446BULL, 0x2B31BCC2AB470E68ULL
        },
        {
            0x75C36685EE0CC947ULL, 0xBDF05EE70C57B417ULL, 0x5D2BAFDA5AD3970DULL, 0x3F14666DE5150C82ULL, 
            0x7231087400B10E3EULL, 0xFFCD085A941E400EULL, 0x1988BDE4908CD1CCULL, 0x21BC82990F155EDAULL, 
            0xF413F0E7F2FE05B7ULL, 0xC83A7BC1B0FACC3FULL, 0x0422222B99804D19ULL, 0x67C3009C37578BC0ULL, 
            0x4094ED630655855FULL, 0xCF9D0A090B8FAE99ULL, 0xED89FFC431F646E3ULL, 0x19AABCD7AEFB9645ULL, 
            0xA88F26B928226282ULL, 0xB9989F8F7AFAEC51ULL, 0xCB68B67361ED1174ULL, 0x76EC6C7CF2A18B9EULL, 
            0x6CA193F713A399BFULL, 0x887FF27FFE7220ECULL, 0x78C2F59C97292991ULL, 0x1539376590BB56D4ULL, 
            0x699F6666425AE803ULL, 0x71371B199664B875ULL, 0x42973491F59D73BDULL, 0x990F024A0DB3E7FDULL, 
            0xC9994C640797C38CULL, 0x994B4A9C53845474ULL, 0xEEAB27B673C56219ULL, 0x8FC3F1C55C7E73F3ULL
        },
        {
            0x2006292F733A2FBEULL, 0xE03B4BA6CD857138ULL, 0xBBE2806762865DCAULL, 0x1B0E96C7964B1C80ULL, 
            0xD82E9A415338EC68ULL, 0x55F87171A84A1271ULL, 0xEC898D0A90620835ULL, 0x7D44DBC8F11129EDULL, 
            0xAA619159DFD50A6DULL, 0x9A6AD695AC4C1C3DULL, 0xF2EEB0AA1DD5E399ULL, 0x52BCAA57728937AEULL, 
            0x722B3E7824F42B1BULL, 0x87D7906C1C5ED1C6ULL, 0x19DD265DF17D927EULL, 0xA7008B40C37CB485ULL, 
            0x3DAA65CA998EF5D8ULL, 0x6CD65F7D5B80A4E1ULL, 0xF66A49B6E28D322AULL, 0x952B7722FE3D1C58ULL, 
            0x3C9447BB549359ACULL, 0x517C0BEC65D86642ULL, 0x69762CB09997C034ULL, 0x75593F334B1700D5ULL, 
            0x6DA6E9C061A6AA2FULL, 0x6D40776F5B251079ULL, 0xE7CDEE6D46DFA0EAULL, 0x7EA574654B6A007CULL, 
            0x46826043744F5CBDULL, 0x677A0A62E43AEAB4ULL, 0x16CE68A90E168F39ULL, 0x66AFC0468374663DULL
        }
    },
    {
        {
            0x98AD98CDE7520082ULL, 0x4267EF6E857ADF88ULL, 0x6EF0DAE042863353ULL, 0xDD3C34F0E6CD33D7ULL, 
            0x47EB8F86FDDA4768ULL, 0xD65E31960E19574BULL, 0xAE8DEAE16166357AULL, 0x578D278E289F5BAFULL, 
            0xBA21EF7D1E6A24AAULL, 0xBEC95143C5E0BD0AULL, 0x0EE24F6681519C22ULL, 0x389146D64056AB1FULL, 
            0x2F9360C107619896ULL, 0xB955C3C3196C55CFULL, 0x6D2D5922AE0258DBULL, 0x20FA2461A2A5B47DULL, 
            0x38038778937A2E81ULL, 0x386DB0EAF05632B7ULL, 0xF860CA1F433A0CA1ULL, 0xCAB84863EC908615ULL, 
            0xE38E4758B3B9CB06ULL, 0xE9FF0927318966BCULL, 0xAE6893BBE8B55D91ULL, 0xC25A4F1271D2ADB8ULL, 
            0x8508F4898869EF32ULL, 0xECC181CF40B632C6ULL, 0xAD93DA273552D3BEULL, 0x83DBFEA2ED146550ULL, 
            0xBEE6EECA099179DDULL, 0x06866D44CCA5280BULL, 0x2C20939FD79819D0ULL, 0xC1A61FB367F33B0DULL
        },
        {
            0xE75F4B7F431CA450ULL, 0x21E2983657035483ULL, 0xA123528359255D93ULL, 0x1BB7CD4117398A6BULL, 
            0xB4D51B20A11BDDA0ULL, 0x289FB42AF5866DF5ULL, 0x14FBB24FE1B1317DULL, 0xACBB0C9595436B16ULL, 
            0x63F91EBB87B4ACD1ULL, 0x8843619E6F26518FULL, 0x43091EA88008E437ULL, 0xFD405AF7C6A4BAF1ULL, 
            0x1C2C862E59C8F859ULL, 0x67448186F6A30695ULL, 0x6AF9FC27DC64C037ULL, 0x6A473C8A216D2E14ULL, 
            0x2A2787FFFD8EED61ULL, 0xF4A7F842727A7507ULL, 0x632B5F1FCCE25909ULL, 0xD0261B744A487E95ULL, 
            0x6F106283A21185B6ULL, 0x51632EC4673B6F22ULL, 0x52AEBA2AB3DC2C92ULL, 0x128433657E5CA70FULL, 
            0x12D123D314F8F444ULL, 0x4A4642184584BF71ULL, 0x05705F644BE16138ULL, 0x267F1B04AB06A28DULL, 
            0x10DB140EBE7603A8ULL, 0xEA3B3CB2F22032A1ULL, 0x656857024E237C3BULL, 0xF8A8B2DDF3739868ULL
        },
        {
            0x506246555561E342ULL, 0xF53A28A676CC98F3ULL, 0xFEA2021CB93CA2ADULL, 0x13C7E30594B49A16ULL, 
            0x1A3F43E20A6BDEDCULL, 0x484D10F3CA43E182ULL, 0x915F6D2C0C103135ULL, 0x5261F54ABACC89B3ULL, 
            0x09879841F05C5DBFULL, 0x5EDC623C7D9C4DAFULL, 0x5953338555250858ULL, 0x36D67DD310F05653ULL, 
            0x67BDBA485CE19E5FULL, 0x680BA592A85A9C5FULL, 0x51A9EF4C92132E79ULL, 0xA7A23B281169F0DAULL, 
            0x49586140DFC66FCFULL, 0xE6BC78185AB02B23ULL, 0x5FCBC47D83881777ULL, 0x55D3085EC03E742FULL, 
            0x234AA57C8FDEA2FDULL, 0x7CDEBB1092D6AA2EULL, 0x9751F94071E39FB2ULL, 0x0599B0306279D545ULL, 
            0xB510AE5FB123B02CULL, 0x75D14DF583F7BAC6ULL, 0x259B44E5B7C4A928ULL, 0xECE9B4D594D428BDULL, 
            0xD5B8D6E2D942CA3BULL, 0x99BBBDE426CE27EEULL, 0xF4D6022B7A54F39BULL, 0xFAADFB850357C2A4ULL
        },
        {
            0xE2E4703C81B81043ULL, 0x23DBFE73154048E0ULL, 0x3887F2F4EAD3EF7BULL, 0x869BF7F47280E658ULL, 
            0x544CC9E0FBED4F90ULL, 0x38E386F8C9676016ULL, 0xCD6212BDFA20E606ULL, 0xA09246823B35313FULL, 
            0x7356B5EC78C56EF1ULL, 0x9F6DB8E38D601BC4ULL, 0xC7442C91FBDCB104ULL, 0x38005C77E161E92BULL, 
            0xCBD61F8D025BAECCULL, 0x040B17F269AE3ECDULL, 0xE48DEA03C0E406A4ULL, 0x62F9F9508ED547E2ULL, 
            0xE9331E949CB94DF7ULL, 0x3E6BA2E6A84D7A39ULL, 0xFE37A1C7F68F407DULL, 0x88DBCD6C7E21C448ULL, 
            0xC8A0CB231BFE6637ULL, 0xEF6769715EC7DC56ULL, 0xDCA53B19CDF5EFA8ULL, 0x39B2A9D731C77A5AULL, 
            0xEE8CE58C6E1B9F45ULL, 0x2F66F9F3A6E9017EULL, 0xF6DA4FEA8A221A06ULL, 0x785753755C2A1932ULL, 
            0x18EC1374AE3ECD30ULL, 0x58ED3FBD8413F395ULL, 0x1C78AF75B7451DEBULL, 0x35F8CD5912AFFA4FULL
        },
        {
            0x29FA34350C36DD76ULL, 0x319D4ACA5E3D9CECULL, 0xF6D16141D66DCAFAULL, 0x50981350C1E4335BULL, 
            0x1C17CFFF2E319AE6ULL, 0x70C6EDC0C4A1E39CULL, 0x7DC3CADD2BBA54A0ULL, 0x6443A850A15352E2ULL, 
            0x5F1E123771385607ULL, 0x726476D455C12AF6ULL, 0x25AD9CCE0A07BD06ULL, 0x7ED79EB1C3466151ULL, 
            0x66DCE176C59712F9ULL, 0xC9488175C6FB8224ULL, 0x25EDDD9B5F28A588ULL, 0x636544085E1E6B79ULL, 
            0x8D68ED67E9716133ULL, 0xFED7E6C588D9D0ECULL, 0x9576AD57FA099E00ULL, 0x00A7C894E5D9CC69ULL, 
            0x43BC199BA844D8B1ULL, 0x346328B54069815FULL, 0x98375D9B4E138785ULL, 0x06CBCC70F1430075ULL, 
            0x3981797E35492DBBULL, 0xDFCD7082BDC33576ULL, 0xEF77417D3CF879B9ULL, 0x060FD1BDCCAB2EDEULL, 
            0xD5CE6551FAEA2437ULL, 0x2FDD8712E96DCB97ULL, 0xC55205D860021B49ULL, 0xC4F02AC2CBDBFC38ULL
        },
        {
            0x424BA3017272988DULL, 0x31B4FC12FC6732ACULL, 0x186FE1BFB54BAD05ULL, 0x2D375B535B0CA1DDULL, 
            0xD63C825E47627B82ULL, 0x027E49C4CA8DCA76ULL, 0x47954B03F35A9AD8ULL, 0xE4C7E3C0912A734CULL, 
            0xD655819D4B7D0A3BULL, 0xC63FE21E3DDAB114ULL, 0x075311EF41204184ULL, 0x490C405D6EBEB176ULL, 
            0xF1B48F7E44B2EEA2ULL, 0xFAB40EC3CFEFB194ULL, 0xC50DDA2D488BA758ULL, 0x0047CD0C7385E13BULL, 
            0x481D6EB2455CC677ULL, 0x4E4A75800419BF55ULL, 0xA8DD3C871E6AB6EAULL, 0x5E63C4CB0D33AA71ULL, 
            0x63340D59CBD3BC89ULL, 0xFD351A4A30EC1721ULL, 0x8F54AC00A2FFC236ULL, 0xBD13EDB1A0C24985ULL, 
            0x464086F4FEC24D7EULL, 0xB7D02534F1970CC1ULL, 0x8C43F97F8A040664ULL, 0xF31F8F5C7104D2EDULL, 
            0xD64819E1074A6506ULL, 0xCB20BA8DA720B0E8ULL, 0xC6075951917E1278ULL, 0xC333509ED4F9B355ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseFConstants = {
    0xB733C37BDBC608C5ULL,
    0x36F70CEF73DA0D72ULL,
    0xF5B71BBE9382D878ULL,
    0xB733C37BDBC608C5ULL,
    0x36F70CEF73DA0D72ULL,
    0xF5B71BBE9382D878ULL,
    0x036AA844564F5434ULL,
    0x483B24E0D6A9E899ULL,
    0xC4,
    0x76,
    0xCC,
    0xAF,
    0xB1,
    0x2A,
    0xF2,
    0xE9
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseGSalts = {
    {
        {
            0x8A86837F1764170FULL, 0x138EDEFD71A69E7CULL, 0xCF5376D0544DDFF9ULL, 0x034AC27BECC93E16ULL, 
            0x30D7D285206FF1E2ULL, 0x9D17FEAB4AA790E1ULL, 0xBAACB2C275926CE2ULL, 0xE11C5F1A8C886CD5ULL, 
            0x499C69E08EF9C518ULL, 0xA44585817CB1D5EEULL, 0x80BB44A14DEB4CD7ULL, 0x768C84D2723299D1ULL, 
            0xA13BEB9726099306ULL, 0x4F9D67617156FF6AULL, 0x3C4E128582CAC3C0ULL, 0xC8095A6B882BBB74ULL, 
            0x8F7DD55417953A1EULL, 0xEA9B52B14E05D9F6ULL, 0x9B7246846E7C27B8ULL, 0x177E8E98FDF6BF68ULL, 
            0x8EE173C5302B5A62ULL, 0x9C88C6765426D967ULL, 0xA73A62D98893EB40ULL, 0x027509E08E2FC717ULL, 
            0xC724DD467307D849ULL, 0x0C5BC6A3CEA610CFULL, 0xA4CEB6A34115F705ULL, 0xE1EE94C2D96084E8ULL, 
            0xFA3A2D4C325F1255ULL, 0xFAE34A417BF0F984ULL, 0x41B16CB609DA902EULL, 0x72A8A28334BF7098ULL
        },
        {
            0x8D10BA666B9278E8ULL, 0x0FC649277A40AA28ULL, 0xF5C865FF6C6F2567ULL, 0x775326F2370F746DULL, 
            0xE50FBEF72C9D1FC4ULL, 0xA3301604CCD15FC3ULL, 0x1A33E8F31A6AB232ULL, 0x4CA904BD25A0C123ULL, 
            0xBDC0523B5984ED69ULL, 0x992C212C97F549AFULL, 0x89BF43A51C043AF0ULL, 0x58E688DA463C68B4ULL, 
            0xFF7B22CBA9266071ULL, 0x7F29721E7A185416ULL, 0xE0C32FA1962C4211ULL, 0x91F0BBD102F6264EULL, 
            0x626EE9BBEC46C6E1ULL, 0xAAAF547827BB2773ULL, 0xAF4B8F9113813702ULL, 0x572EFDB9FD800367ULL, 
            0x39924C88632BD6B8ULL, 0x6A9C25E289433C57ULL, 0xFF4CF82FF0BEFC75ULL, 0xD8D3D05694A4F850ULL, 
            0x1A8DDDC64D259215ULL, 0x9AF479E1E9EFD39AULL, 0x864497E561C3BEBAULL, 0xBD9C3ED07DB20158ULL, 
            0x4879D0E6B6D47E46ULL, 0xB9EAECB43105DB29ULL, 0x40D3F17359599B6CULL, 0xF967C8ED7D93D991ULL
        },
        {
            0xA7282EE8FB013B54ULL, 0xE5308FC041FB5FA8ULL, 0xD2ABC7212E0A945CULL, 0x3BAA625C950AF63DULL, 
            0x358B4DEE37EC1684ULL, 0x734BEC4A8634F288ULL, 0x0FA558401CE93207ULL, 0x75E2F3C6C73883F0ULL, 
            0x06D8036E44ED61C3ULL, 0x99921088C725D57DULL, 0x1F24991AB72F046BULL, 0x59EE0A0AF1C658E5ULL, 
            0x585DC0C9E6856FA3ULL, 0xA6134CFE67522680ULL, 0x96B2555E34D5CDDDULL, 0xB70330C35A823CB3ULL, 
            0x6F7073F32C0A76DEULL, 0x2D450E80406F4458ULL, 0x39E4B868264EFC1AULL, 0x6E29960EA43B4AAFULL, 
            0x2960FC309770E028ULL, 0x9F20B4015DA0ADE7ULL, 0x37996370B08E7A10ULL, 0x937426C05ADD77EAULL, 
            0x0BA4646898870303ULL, 0xD7CA7FA986892CD4ULL, 0x0602F192E7FB2A58ULL, 0x7C2FAA8A45F4FB12ULL, 
            0xC5650536E38BC2B0ULL, 0x86ACADA578D1E159ULL, 0x8EA6528679B22CE6ULL, 0x7654E27BC7330E41ULL
        },
        {
            0x2CDDBA7936E57D2DULL, 0x8B36A8DDF90E4F69ULL, 0x1E788F2FAF3C4C94ULL, 0x3C4E6FD91ED98AEBULL, 
            0x6C232909B86CA973ULL, 0x9F47D24032ED4DAFULL, 0x70EB03EA272F5C3DULL, 0x3256AA227316F36BULL, 
            0x9DA79DE161118C65ULL, 0x74D6B033CCB0B1A7ULL, 0xE6E763E69AB38C47ULL, 0xB1F8F162D6EC4ADEULL, 
            0xA7E9C91E76B6DF56ULL, 0x6D56C564E3A37746ULL, 0xDDFE7F11004174F5ULL, 0xC17B229ACA2408E2ULL, 
            0x703300D3954468BCULL, 0x2A6BCA50B9A1BDCDULL, 0x49687EA080AD318DULL, 0x4B30BA30AF871AB3ULL, 
            0x68D0D4F98FC7FE91ULL, 0xED56D0DA53E83FEAULL, 0x09F4973B5A0B0601ULL, 0xF95FCE65490F47B7ULL, 
            0x6747053358074897ULL, 0xBA35F3DE125FB109ULL, 0x412C51878EB40E1AULL, 0xA815B2DA48CDCC91ULL, 
            0xC85DE5DE96B68513ULL, 0x1927C60675A8AB67ULL, 0xEDDD4E1343AC2C65ULL, 0x363CE60C273D1311ULL
        },
        {
            0x033EC27B706FDF01ULL, 0x8E984398B96A9575ULL, 0x40F26034F16737A2ULL, 0x7DA3F1A44A9EA5E8ULL, 
            0x78A4A4F1462112D3ULL, 0x8560D16A02763F80ULL, 0x1ABDD0A36FF839F4ULL, 0x8465190381C271DCULL, 
            0x3BCC5D02DAC30D69ULL, 0x20C0C74D7839D139ULL, 0x84A79141AE64F8BFULL, 0xC0A11B25DF247172ULL, 
            0xAA200D081BABCA1EULL, 0x0ED98BCDF25CA0C2ULL, 0x6F76F546E76A41F1ULL, 0x89799BE7F86398B0ULL, 
            0xEE2143D44B1A39CAULL, 0xFBC7F9AC5CF0CD14ULL, 0x5D7092FD817DF7C2ULL, 0x75813013508AB5CAULL, 
            0xA338A780F4A6511CULL, 0xB72F31C0B8513DABULL, 0x3CE8938A9FCEE282ULL, 0xC70D80936D1673E3ULL, 
            0x7944BDC6B87DE0BFULL, 0x6C2A3AA18019A197ULL, 0x7CAF3E04F77C9422ULL, 0x0D9B0AE76BEDA750ULL, 
            0xA211EAB47BC8B3B0ULL, 0x7C6CA3D2E7D725E7ULL, 0xCC1E1B51B7721C26ULL, 0xF226B8FA32E6DE51ULL
        },
        {
            0x1348E3664AFD3749ULL, 0x43DE17D5F0DA0872ULL, 0xD9FF5A9D14F8A0EEULL, 0x3EC7E91E01967DDBULL, 
            0xB95BDFFA23C34DB7ULL, 0xA8885CAD545DA592ULL, 0x48EEFDBC7306FA5EULL, 0x0B2BB1758B54493BULL, 
            0xA284C6336C18231AULL, 0xC3ED165EAF7FC58BULL, 0x6F04BF1F1C9395ACULL, 0x9B772582D9517286ULL, 
            0x61E0204A705453E1ULL, 0x0751F9F870379DB6ULL, 0xB65790BAC0BFFB57ULL, 0x623D5106C0D630F5ULL, 
            0x12C29ABD664FE6B8ULL, 0xD4BCA0F18A0FB906ULL, 0x6A7A0728DC44C148ULL, 0x20CFBF5291BD7C35ULL, 
            0xAB9C7930A23680EDULL, 0x916C0676412FCB04ULL, 0x8A45CDB7601532DEULL, 0x99CEBB1E53672608ULL, 
            0x77E54CF9FAF65958ULL, 0x7EF1A44ADF238238ULL, 0x6B600B4106859BBDULL, 0x37D794F872E64A11ULL, 
            0x8E0B225B08DE8214ULL, 0x1FE99EC99185C817ULL, 0x4496B1FD38E05584ULL, 0xE3EF016ACC9BB49AULL
        }
    },
    {
        {
            0xD5BE0F72847CB5DEULL, 0xD77FE4D5F098F85EULL, 0x06AE052C4519D280ULL, 0xB8B50D031785A7F7ULL, 
            0x02F15479845EB5F5ULL, 0xACCF2446C9CA9FC3ULL, 0x357E096E2AFA56E0ULL, 0x83B02C8F799E1778ULL, 
            0xEFC547316CDF05BAULL, 0x360FACCF87BC3E39ULL, 0x59EBAF7D42CF426AULL, 0xBACBAA2BF36E02FDULL, 
            0xFF19EA745A35F7CEULL, 0x55B408D83CD51C42ULL, 0xAC4764844F84E7C4ULL, 0x60953592E3368DFDULL, 
            0x1D15564F70215667ULL, 0xE22BD3BE9B2E68F4ULL, 0x85D3614E77AAF664ULL, 0x295C4330304D0ACDULL, 
            0x58715C4EC0624AE3ULL, 0x9D365F29507A4626ULL, 0xBDB982E5EFEF8E1FULL, 0xF44DDAF856ED6053ULL, 
            0x3A8F99F04B893AB1ULL, 0xE9C1CF3F29D01D5FULL, 0xC885C7C14A582438ULL, 0xE2843289BF6D9C85ULL, 
            0xD223E09DE7B2FE98ULL, 0x2ED8189A9203C59CULL, 0xA45BD158203076DBULL, 0xF5541A9FA31FA79FULL
        },
        {
            0x6050572123B0BA13ULL, 0x91A5AEBBC41D0661ULL, 0xEE93E976A700B9D3ULL, 0xAAA82DEA1F6F9586ULL, 
            0xD11A200AAB28EA9BULL, 0x280704392C0D72D9ULL, 0x7A9F7CA5DC9B517AULL, 0xECFDE39DDD784CF7ULL, 
            0x847D31EED4C7A429ULL, 0x043F47B30D8BB814ULL, 0xBAEA088FDBAEA5B8ULL, 0x846CAE2007841A15ULL, 
            0x865D30388747A922ULL, 0xA7B37DD5B1ABEBC2ULL, 0x8D55C6369F20763DULL, 0xC44FA13BAE415219ULL, 
            0x6C62A51ED26AB46AULL, 0x927BA6C60BC13C5FULL, 0x8E62036271C65E83ULL, 0x912B8AB5D3FD342EULL, 
            0xEFE54AF89BE2EE36ULL, 0x2CB4EAABB62A21D4ULL, 0xC96877B11CE5FA10ULL, 0xE3279912302B2A05ULL, 
            0x311FB6A748762EBBULL, 0x5D6BD794C808CD03ULL, 0xCA5F77C5C8D30F05ULL, 0xBB8CE3E45BD664B6ULL, 
            0x302905FB8BA13609ULL, 0xD2C5934C0F4E1F84ULL, 0xEFCEF1F80D4DE610ULL, 0x805853D7B1D9900BULL
        },
        {
            0x6CB2700A965BA71DULL, 0x8061E1CA00E1EE61ULL, 0x7770EBDB7AEAE137ULL, 0x90AAF95A7D0DCC2EULL, 
            0x9C6DF4306D93C7B3ULL, 0x2F894EDB99025D18ULL, 0x9A3C77CFCE70CA6AULL, 0xA834228646882A6CULL, 
            0x70390C5A14EBDB9DULL, 0xE6D7404BEF2406DAULL, 0xEAB75C21FF7212AAULL, 0xB9B16206349692AAULL, 
            0x451F03FAF00ADB15ULL, 0x93E9ECB3D7EEC531ULL, 0x0A4F22D890EA7D3EULL, 0x8215EED1B4A899E1ULL, 
            0x76A7DB92149C32B6ULL, 0xDB133339FF6EA133ULL, 0xE833476E07C4605AULL, 0x86D33F7F4D6394FCULL, 
            0x775284CE2823AAB0ULL, 0x9461BEF433FFBD95ULL, 0x2119D9A357AFF84BULL, 0xA1E23FF84E112628ULL, 
            0xBEA8D4C16BACADF4ULL, 0xB4B1421A612CAAE8ULL, 0xE7C24E6CE4ED2B79ULL, 0xE9F8816DBB5C47F2ULL, 
            0xAEAE2A811EA3616FULL, 0xE30372D774145D65ULL, 0xA696213191AA75F4ULL, 0x035E65F61C3A4F2AULL
        },
        {
            0xFC9D04385E765311ULL, 0x6119D7E453E151D8ULL, 0x7C2F520B6BF8BD67ULL, 0x6AD9D8AC47216B5DULL, 
            0x15A6534FA610F363ULL, 0x1F37D79263B79E14ULL, 0x56ECBC2964591067ULL, 0x91BC0B506C1B40C4ULL, 
            0xF3E908D2AB8C394BULL, 0x2CF1311A2DC2A510ULL, 0x481FEAB312729DC5ULL, 0xD9D6E1C093CB510CULL, 
            0x5CFFB804EEEAFC51ULL, 0x53C58985BDD79BAAULL, 0x17329F17215EE3F3ULL, 0xE2FD4F3A320B7B9CULL, 
            0x76296DF586E8A156ULL, 0x34DBB66D0CB46654ULL, 0xE28EC538E9E554D6ULL, 0xF6FD85E485EDB6CAULL, 
            0x1DB2231AC6A76190ULL, 0xAF025816E0BE82DCULL, 0x7FD27C6210AC7C18ULL, 0x215304A717CAD931ULL, 
            0x88CF80B129B9CFF8ULL, 0xAA373BD48AD6148FULL, 0x774340A9769E190EULL, 0xE48CE658985F2BE8ULL, 
            0x0FEF902240508772ULL, 0xB99D0C68F328BC12ULL, 0xE980C73897BFFB67ULL, 0xAC82855465333E30ULL
        },
        {
            0x0F6F8A22D6D5D379ULL, 0x74E427B6F8645F9DULL, 0x758D46B6D93E2398ULL, 0x354FDF86C03B2DC5ULL, 
            0xAB71E250478A3499ULL, 0x9EAF8D740BF4B2F7ULL, 0x9FAAA6317FB4C234ULL, 0xD001800A7E43021BULL, 
            0x144C8B984B86BED9ULL, 0x02295DC08131AFCDULL, 0x0BCE6567C98AD02BULL, 0x553BE0AE55655114ULL, 
            0xFDE4EB21ACD4938FULL, 0xEB1DD421B565F100ULL, 0x113A9228266F17F7ULL, 0x038A75F321A67AEAULL, 
            0xEA40899E2A101068ULL, 0xEE9CFA11D4AE2C1BULL, 0xECC559DCDC792623ULL, 0x136119505F5711ECULL, 
            0x71AECF33027EEF37ULL, 0x297FC7F4C8795AA1ULL, 0x51BED7513A14234BULL, 0x0F33030ED9A79D2FULL, 
            0xB87E7B5E3C2AD1B1ULL, 0x9FFC2FB790DCE499ULL, 0x0529774660697587ULL, 0x1074E08EFB0A5E3DULL, 
            0xE99459046872BFA3ULL, 0xC390DE08EF5AEAF2ULL, 0x54B00F8527BEF9A3ULL, 0x40DA300840249552ULL
        },
        {
            0xE75F127FE8C59C1EULL, 0x83BD497C9DE8BC64ULL, 0xD9B9D9A9B9F55D1AULL, 0x495A4C7443780F2EULL, 
            0xE41D833B83375554ULL, 0xBA565652B32C0CCBULL, 0x00AC96E6F204E304ULL, 0x2A175B9845EFBADAULL, 
            0xC01A21C31535E026ULL, 0x933062555011F0C8ULL, 0x70DB8BC82C2F8218ULL, 0x9460FC6C43C7A010ULL, 
            0x86F5D16278B8E260ULL, 0x746BDB8FE1E126ABULL, 0xC6B94EC9B1BCDAB1ULL, 0x077996878C3FCF29ULL, 
            0x47A9CE394EF277A8ULL, 0x2666B2E30D573536ULL, 0x3C7EA1167CAD91BAULL, 0x591E8EB0692B133AULL, 
            0x2C453489D1273069ULL, 0x92AA37AAA84E4D5BULL, 0xC003C651E1F6DAB0ULL, 0xBFA1474737B2CBB8ULL, 
            0x91FDE45955AF970FULL, 0x83A15FEE668743ECULL, 0xBEF39DA90B8EBE5DULL, 0x80E9BEBA46AA201CULL, 
            0x23675734F4C7B53DULL, 0x1E70E273F6E7D2CBULL, 0x42EB4879E32020A8ULL, 0xE6AB1F83E8E16BAAULL
        }
    },
    {
        {
            0x81CADA5FD604BD20ULL, 0xF2BEC0BFAD4B42E6ULL, 0x0D95ABD822D655D5ULL, 0x763F3C01671F8987ULL, 
            0x68858481FC6A6331ULL, 0xB11999F5D4FD2C15ULL, 0x4BC627A4AC3EDB8EULL, 0xBA1D09BF33CD29B8ULL, 
            0x62C306485F15EC50ULL, 0xABCE2A24C5A32D96ULL, 0x44CF4605409860EBULL, 0x855C8D35242E5F5FULL, 
            0xD616C078667A680EULL, 0x60879A4787C92050ULL, 0xDA60AD4DCC5D7108ULL, 0x730A1E3EF391841DULL, 
            0x568A955097B79787ULL, 0x5D6C6A110398A74FULL, 0x537EA5FFA039F2A3ULL, 0xD446C36BD0AA7317ULL, 
            0x7D89712E81229C8BULL, 0x8F46C946015196F4ULL, 0xAD01415C2BD237A9ULL, 0xF0F4A114DBA51C43ULL, 
            0x5570D85BB12E4FC2ULL, 0x93FF1E00D0087E70ULL, 0x61E75504F157A171ULL, 0x612D8A85FBB5F34CULL, 
            0xE32463C86BB8D5B8ULL, 0x674161DA37A9EA66ULL, 0xC4C6599D9D0BC9BAULL, 0x62E11310DAE6205BULL
        },
        {
            0xEEEB45A875C4B95CULL, 0x217E88D4A3F8179FULL, 0x5809BB7EA7D9CFD3ULL, 0xDE07A5CEEA1D7DB3ULL, 
            0xCF3EE2339B8658A5ULL, 0x10559C651D9C10A9ULL, 0xF4AE1703BAC15710ULL, 0xE1EFD15EF1A42B2CULL, 
            0x4C6B65ECD5F0AECDULL, 0x8F941E15BD617720ULL, 0x4B0BD8EA544F914DULL, 0xCC006496FCAA849BULL, 
            0x8280A02460AB8D3BULL, 0x62B36FA10F519B3AULL, 0x002E4BC8273494D6ULL, 0xDAE37DF461AD413AULL, 
            0xD6B9A9843615FA28ULL, 0x27B3B7E4DDABB502ULL, 0x68E1ABAB436F4E49ULL, 0x3F2A36FADB3B5232ULL, 
            0xD7C06915C7E6AEF4ULL, 0x62FEEC954C1401F5ULL, 0x0638F3DBD87B32C5ULL, 0xF93BD1FB97017865ULL, 
            0x83BE953D7D3EC826ULL, 0xD0DAC69C1FD98E08ULL, 0xB11B796866F56B50ULL, 0x7F94C7CB33FB1F77ULL, 
            0xBAE9AFF97F7CD48AULL, 0x97AA56A07985CC52ULL, 0x7FAC94464568BFB0ULL, 0x6999DA2D3C9BA28CULL
        },
        {
            0x695B34D98620C133ULL, 0xB0566C111818B726ULL, 0x8880979D8FDC35F0ULL, 0x8881EB20A1827989ULL, 
            0xD0419F0FD0C0F0AEULL, 0xC94B7AC79BBF1D1CULL, 0xBCC94D8288365429ULL, 0x441D1E672FEAE6FFULL, 
            0x09CDF4E66BC8FBA6ULL, 0xE370B473F76AE3C3ULL, 0x3F634ECDA57C70CBULL, 0x9044558C8F3C14CAULL, 
            0x0CF6FF40EE5FBC58ULL, 0x69E6835F23D131C9ULL, 0x394E6F4BCD5B4D39ULL, 0x12F0A4D40D082FF1ULL, 
            0x3065DC1969052AB9ULL, 0x54799E86C6F1AB3BULL, 0x4169A0593283475FULL, 0xFD25F9B519E06C25ULL, 
            0xD6CD806993CAC3AAULL, 0x2455AA3D7E5EA883ULL, 0xA1572B81BCAF19D0ULL, 0xA26F4323DF0DEED3ULL, 
            0xEAF5B2B719D15A9EULL, 0xD14E3C13B4B8E325ULL, 0x81F42015F63DE186ULL, 0x676047B98F968448ULL, 
            0xC9DE26CCEB018BFBULL, 0xB71380DED19410F1ULL, 0xB85B588772B673E8ULL, 0x04ABE2F53CA21694ULL
        },
        {
            0xB1E84CE65AF110BEULL, 0xBAC2BCD8403727E1ULL, 0xDBA7173754095247ULL, 0xFCE5B2A780AD4AD6ULL, 
            0x9BDD482878E49216ULL, 0xF131F3E6E37FAD03ULL, 0xF67ECF46661F6BA4ULL, 0xBFAFF21499E10D5DULL, 
            0x029B68463E1C493DULL, 0x8C1BCDD493EA84CDULL, 0x8BE0E4CC209DFBB6ULL, 0x50C069511E08BC79ULL, 
            0xDEAD24FC15F71947ULL, 0x6407841F307126A7ULL, 0xF10CFFD7BE4F8C1FULL, 0xFF166604FFB48967ULL, 
            0xAA4DBDAABCF956B3ULL, 0x623D5660E6994BECULL, 0xB41782E8CF2139AEULL, 0x354F90DC8E61F9EBULL, 
            0x33B396E787E40F37ULL, 0x94AC80C802FCF9F4ULL, 0x11654E12047D5170ULL, 0x6C2D09CA7AA17E92ULL, 
            0x510A0452A0D8AD39ULL, 0x48794D5CA08266EDULL, 0xC82F784398A09282ULL, 0xCAFA7668DC1477DEULL, 
            0x4F18A2FDADF506C8ULL, 0x4EFDA63C7D731A9EULL, 0xA797976D357D7527ULL, 0xA13DD12F56AF0BD4ULL
        },
        {
            0xBC6085F0AB4DC3F9ULL, 0x04C129DB6AA14629ULL, 0x59DA5126D46F518EULL, 0xA13A603CF5A95940ULL, 
            0x1EDB83033F718AC9ULL, 0x0F576D3880C81DCCULL, 0x339546A2025C293FULL, 0x5BAC77282D256035ULL, 
            0xB7ADCD762200D6EDULL, 0x720D8A597B60CFC8ULL, 0xC7367F70DFC76C0CULL, 0xBEBBB271ADED99B5ULL, 
            0x96C7790207F085EDULL, 0xD107EC48CB958C42ULL, 0x13A2B36F6203F94EULL, 0x6524CD0C5833ED7BULL, 
            0xA3FFA956371374DDULL, 0xC72C19DCB0C36BF5ULL, 0x5B65B2B8369D0CD1ULL, 0x5935FF9F407C9398ULL, 
            0x88453FB5A6FDD81FULL, 0xF43D6B1F6EB01DA4ULL, 0xE4627314C95CDD2AULL, 0x2BD17A44F4B2C1D7ULL, 
            0x232BDF253390AEDFULL, 0x19AA0FB87948FC95ULL, 0x0D9008EC158AC5CFULL, 0xBD568B539A2BF504ULL, 
            0x75E7CB4CFAA13CB3ULL, 0x829D8C9396E6BA83ULL, 0xFA47929BB2E3C98DULL, 0x6628A30166C1B544ULL
        },
        {
            0x30B0368C4A653CE1ULL, 0x83F02109C26D63D7ULL, 0x76C070FEC14CD4C7ULL, 0xB72A9B681DAFF8F4ULL, 
            0x2EDD2E53D2AD2D6BULL, 0xBDBF0DCF17DD8A3FULL, 0xE537D9C46A5140E4ULL, 0x7589EBE337BE914CULL, 
            0x24BE68A74068245FULL, 0x4E8A7E54CCD18A54ULL, 0xEE9CE7202CF9A6B0ULL, 0x1E3093AAF06B3DEAULL, 
            0x1AB71AECECAEA113ULL, 0x7A1C22AE33325ACEULL, 0xDEEE23C048AB8055ULL, 0x5193E435705EDC47ULL, 
            0xC2335DEEBC635F4DULL, 0x4FF0D240B42100A2ULL, 0x586C394C6FA363D6ULL, 0x3A904568714F55E1ULL, 
            0x24A52844901D84E3ULL, 0x49EE68A2E17BF692ULL, 0x7556E11C9E0B7498ULL, 0x034BB7ED900B435EULL, 
            0x0DCFF48B6723206FULL, 0x936E7F63A596C75AULL, 0x8DBAC5C2B899D8FAULL, 0xEAA7BE5452F7FE75ULL, 
            0x4D58E4CFF63E0A9AULL, 0x9DED8157C4A958AEULL, 0xCCD5906E2F1D43EAULL, 0x59B0B15708619F80ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseGConstants = {
    0x80E77AA732600CD6ULL,
    0x1964746089344F7AULL,
    0x33B0C57D8902AED5ULL,
    0x80E77AA732600CD6ULL,
    0x1964746089344F7AULL,
    0x33B0C57D8902AED5ULL,
    0x2AC8119B44DCABABULL,
    0x5BD6D85FC2E795CAULL,
    0xBB,
    0x5B,
    0x1A,
    0xA1,
    0x3F,
    0x4B,
    0x62,
    0xD1
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseHSalts = {
    {
        {
            0xABAB6D3FC9380D14ULL, 0x56AA1FBD75EF1A1CULL, 0x047447A89A067844ULL, 0xDD34BA13164D1F51ULL, 
            0xCED166B43C21E37BULL, 0x05B9455D5140F27CULL, 0xDC48B3BF6BFCBF48ULL, 0x844ABE4D8201F507ULL, 
            0x5B1EDFD4F0F1227FULL, 0x3D94631125AD2FCEULL, 0x5CDDC5FDCA246BBCULL, 0xD1E9F4FD23CE06E2ULL, 
            0x67CFB396FC21A406ULL, 0x687BA2BAAF166BDCULL, 0xCD9709F088174B79ULL, 0x1FAE8CB37F8B2549ULL, 
            0xFB65EFA908E0A994ULL, 0x7BFAB10892738FC4ULL, 0x1CB3EE643FF717FEULL, 0x3614811CBD23898BULL, 
            0xD7555EE56140FA66ULL, 0x17BA428BBD515C44ULL, 0xD4A35F691B7048A3ULL, 0x768BA2B7D66F5E33ULL, 
            0x87F2936EEAE21DD5ULL, 0x505DE50AFA032A88ULL, 0x75B90431AC509C03ULL, 0x7A094526C1BAABBEULL, 
            0x3831F1D61DC07467ULL, 0x0C22460A4D0AD521ULL, 0x274A269486AFD874ULL, 0x804B431A571AF23AULL
        },
        {
            0x8D209893F1AD91B3ULL, 0x3ABB1F5729284825ULL, 0x60898CE1FEFBD3EAULL, 0x28420FEEA0DBDAE8ULL, 
            0xCD19D32D302B1C26ULL, 0xFEC3772DD9485DE2ULL, 0x32EBD235D5CACBBBULL, 0x2DFD89FAEBBE0759ULL, 
            0x0DDEE241F47EC6C5ULL, 0xB417970B32977D54ULL, 0x84C198DDB9BD20F0ULL, 0xEC023E882538DC1CULL, 
            0xB8F5023613EADDF0ULL, 0x15C29E8C60CE995AULL, 0xCE8551F026C58EE7ULL, 0xF409F08850DA7AD7ULL, 
            0xBC805010E6A4009FULL, 0x0B5379AAA6D5EB2AULL, 0xF636EFFB360828E5ULL, 0x993FC8FF148E7762ULL, 
            0xC21C53CF29DC6F02ULL, 0xBFABF5902EE9C979ULL, 0xA159EA7E5463D13FULL, 0xF08FE5203656F902ULL, 
            0x7483FE8CB1F3B3FFULL, 0xB7840DC561DE1EC4ULL, 0x4D662310250179F1ULL, 0x091D3D14DD8E6765ULL, 
            0x2DAE9BBFA1B42094ULL, 0x9BAF326B3B7F61DDULL, 0xEFA59815AEF03C7FULL, 0xFF954A4DE1AE6FB0ULL
        },
        {
            0x6E1128989DC44277ULL, 0x7CB88E3342118ADDULL, 0x11A5E73E78A8D7E7ULL, 0x7AB29CC749D803D2ULL, 
            0xA6049865D7F5771EULL, 0xA1E788447FDDBDD8ULL, 0x760CD57FBA5383F1ULL, 0x35FE185C6B5DB187ULL, 
            0xBC3364DB9C178DA9ULL, 0xC70A68D5A9CC14CEULL, 0xBFD8EEDE3CAD3A91ULL, 0xEBB61DD6B0F26845ULL, 
            0x0F8D20956D799D2BULL, 0xF55A9C7B8098D3E0ULL, 0x3BEBDF6EAE663566ULL, 0x15218A110ADD7747ULL, 
            0x952BA4806C11C36AULL, 0x392E6DC11D8A300EULL, 0x76F27DB9D4BCE8DEULL, 0x5B59DC6E2CB1940BULL, 
            0xF89C62D9F082E3DEULL, 0xB90DE058896EE41DULL, 0xBC213E348B8314D4ULL, 0x5625813D408764A7ULL, 
            0x1AD0F5BFA628CB43ULL, 0x7CCC52FBADD91F9AULL, 0xE3F1117B0848B07CULL, 0xFA7F90F7A4AE8FE4ULL, 
            0xD8262994049970F5ULL, 0xA87BBD2B6753B3D5ULL, 0x673E67F1C168DB7BULL, 0x95640B2C16DCF3AEULL
        },
        {
            0xF03ECE30AABA00B4ULL, 0xF079DA58B1D97D96ULL, 0xE4A1556EB71B0B23ULL, 0xDF7F5E9883555837ULL, 
            0x64E129D01B55E7D5ULL, 0x09757B08798675EAULL, 0xFD0BD282CF988530ULL, 0xB75A54AEEAD3A952ULL, 
            0x891B6A0D4365E78CULL, 0x51AA08726151637FULL, 0xCA9BB0BF2656BE23ULL, 0xE4CD0DB27E7867B6ULL, 
            0xB4FF84B28BB08399ULL, 0x56B06303CDE99633ULL, 0x391A2B958654D70BULL, 0x430EBED824CF96BFULL, 
            0x24F585C7689E06CDULL, 0xF2ADE5055A8053B1ULL, 0x5B893DA436081367ULL, 0x3ABCF4575C5A62B9ULL, 
            0x5FE39B91E54F8010ULL, 0x7E6DB3D5288693AEULL, 0x42870CC897A083A3ULL, 0x54400D35F3CEB926ULL, 
            0x4803039DE4D52D01ULL, 0x04794C2844130220ULL, 0xD04556CCFB7C9046ULL, 0x114AB39BC382CFF8ULL, 
            0x109B594D99C952AFULL, 0xF4AE0E0BEE42829BULL, 0x086D965008708E3DULL, 0x22960B8612317ADFULL
        },
        {
            0x06AB4129CFED6109ULL, 0x16B6C002E261E66DULL, 0xD440D012247B49A7ULL, 0x7C6C58A46B9A0708ULL, 
            0x3850D7AE0247276FULL, 0x2F88A5DADBFA6FDAULL, 0x289C9F9347686D66ULL, 0x079C4A7B51155204ULL, 
            0x1562519291A51F7AULL, 0x528B56DF683D9AC1ULL, 0x4423052A6CB3EC18ULL, 0xD2E110E77F0D7AA1ULL, 
            0x624C8FAA5CD0E8C3ULL, 0x6ECDE4C6212AA090ULL, 0xD8B9F6846F8F5975ULL, 0x59AFB9BD446233B4ULL, 
            0xE30CD0630CC4FBFDULL, 0x0A038FE082F3D66AULL, 0x7BEA26CB769F89BCULL, 0x5DE4929478D16B9AULL, 
            0x91292459751DC280ULL, 0xCFC92BB88A29C70DULL, 0x05DCED9F13C99443ULL, 0x45D8FBF13CBCB78AULL, 
            0xA7A197ECD29C851EULL, 0x0CAC6DD2CB0824E7ULL, 0x4174342D25F397E7ULL, 0xB2FD800CE11981A7ULL, 
            0x4C11BAA74CFC0042ULL, 0xC265F0C6749FC6B8ULL, 0x872A9859E59BACEBULL, 0x35B657A5D0795917ULL
        },
        {
            0x95AB2A96848FE0AAULL, 0x7B6C7D360622A9B2ULL, 0x2CCE3262B6932176ULL, 0xE9BFF1FBA05EA2C3ULL, 
            0xE965696C56468DEBULL, 0xBBB9C9C49A2CFAFAULL, 0x0A85FA330C9CF335ULL, 0x78386F7E04ADC12DULL, 
            0x8A825F654ED300EDULL, 0x548846B1E2323B45ULL, 0x8BFBA15FD9240A52ULL, 0x3469F746CA653530ULL, 
            0x10C023A0A98D92F9ULL, 0xA6819ADA1E49CF49ULL, 0x739F1C441CDF152DULL, 0xCD921520D2805197ULL, 
            0x7FD3F08E35FC5E5BULL, 0xF1E71AEB0F3FA0F6ULL, 0x3E113931D22B0861ULL, 0x67747AE8290E9F05ULL, 
            0x29CC4CDD776DA5C7ULL, 0xADB9D25695EE1045ULL, 0x82A4B9215C73134CULL, 0x902C55941FBF35C5ULL, 
            0x494C8E7A5A6269C5ULL, 0x3B6E4EB5E9B4DA98ULL, 0xF4B29B1178744757ULL, 0xA6D534A218A91EAEULL, 
            0x0E97DA7C48373087ULL, 0xB2743924CA10966CULL, 0xF239ECA57E40DAE8ULL, 0x8A04A41BBA5CC4C1ULL
        }
    },
    {
        {
            0x2B19043FA22193F9ULL, 0xD12789590397A850ULL, 0x0E899FB784DCE8D3ULL, 0x4948B7C1C4B919ADULL, 
            0x7B10EE53C2FFC729ULL, 0xBDE18939CB72E039ULL, 0x95DA6D4E48F2125BULL, 0x4E2C01F0569D648BULL, 
            0x6FF5948F6A6850ACULL, 0x470BB67BEE87A182ULL, 0x5580ADD2305B502DULL, 0xBB03243F2C6F1A57ULL, 
            0x7496CA6E40FB273FULL, 0x9DA7F4AD461EB20EULL, 0x8895DEAABF6ADFF5ULL, 0x57A9295998DC8968ULL, 
            0x93336D43A4DA7403ULL, 0x3A09AF56AF0951F8ULL, 0x262ECE74515080BDULL, 0xBA161F421C068A2AULL, 
            0x04088CB9C9EAEA6FULL, 0xC9FC6013D1671EEDULL, 0xFA2B838DF0C752F8ULL, 0x131E75A392326D50ULL, 
            0xDA97110E3394BA6AULL, 0x1780DC0E7C225C7EULL, 0xD46DECBF7D2E3BDFULL, 0x1DC1B58C59256A1FULL, 
            0x7A41762ACF11AADDULL, 0x5A2D404B0A699F9DULL, 0x73996B4AE94D1FD3ULL, 0xAE957E14107EDBFCULL
        },
        {
            0xF82F197E482A528EULL, 0xFB8F55E32B4FBAABULL, 0x5FD6E985443B17F1ULL, 0x4FE4BA7613402C85ULL, 
            0x1578C16ED99583EDULL, 0x7647BA5D2985647BULL, 0xF82EE746112CECC6ULL, 0x63AF70DBC3B46567ULL, 
            0x36F55AADA3514AFBULL, 0x89F4FB7B2C291D6DULL, 0xAAF91FA7091E8A4BULL, 0x8447B4F13DC4D90BULL, 
            0x65478F225C88311BULL, 0x8B831099945462CEULL, 0xD288582E3EEC514AULL, 0xB150D61604014C76ULL, 
            0xD9CE395602B45BBCULL, 0x10A04478F96F69E9ULL, 0x11BD90A5C296A31DULL, 0x4732AD47F26E504CULL, 
            0x1D8CE0002D118180ULL, 0xFE73AD1681F6CD0CULL, 0xD2EE678E86A43531ULL, 0xF481CE2B00F05C53ULL, 
            0x452D28D9D81E1F86ULL, 0x118741FDB2DF2F1BULL, 0xE90C344E38A85BADULL, 0xC3ACB0561930FF90ULL, 
            0x7F79B09D0406AC50ULL, 0x11F6B1ADFD78C3B0ULL, 0xC10DA02EBD953CF9ULL, 0xFF00BC35E0D75666ULL
        },
        {
            0x3A238249D248D520ULL, 0x7B13B2DAD8ECA6BAULL, 0xEDF97BB7AA5BB5BAULL, 0xB8FDC0ECEFB2CD69ULL, 
            0x45D246ED38BA0089ULL, 0x92C745DC85208563ULL, 0xE58E4FFB313DFB63ULL, 0x82B45B5CDE82E8BFULL, 
            0xCE6C25F8004D83F3ULL, 0x6D6B1E874B9F5A1DULL, 0x761D6C55D50D1427ULL, 0x81FB28987E804FE2ULL, 
            0x5D5337C1120E2322ULL, 0x28AA1E99FF045829ULL, 0x132386B9F4F3AD37ULL, 0x35EEAA073798A9F4ULL, 
            0xB53B56C3814F8816ULL, 0xE536171DD43DD38CULL, 0xAAE10F20E7EF43A4ULL, 0xDB836698BDB31F32ULL, 
            0x58FC4F9889012A8EULL, 0x0300EFFD153993C2ULL, 0x88110436C8E4B675ULL, 0x74730DF114AD5271ULL, 
            0x5BCCB7AAF36EA951ULL, 0xD2870AEEE01654FAULL, 0x805C69673F02C624ULL, 0x4C4411CE0F1A3979ULL, 
            0x023879F49D18D5A4ULL, 0xA31210CB911A57E1ULL, 0x3CC1D20909EC3F8BULL, 0x171F07A44AEE3AE7ULL
        },
        {
            0x1904B21330576689ULL, 0xC37354C0E882F803ULL, 0x2181D0E61FD881B1ULL, 0x904E1003BD0AB568ULL, 
            0xA4A3725B127CE30FULL, 0x3E48EC9F41C02FD9ULL, 0x38BBF560C394F545ULL, 0x24814228765554E0ULL, 
            0x7EEA6654CB2F96DEULL, 0x879A38CA07C81268ULL, 0x522D808081437CF2ULL, 0xB7669951D00E1716ULL, 
            0xFD8C6E7DC4A557B8ULL, 0xADE0E19C3DCEF871ULL, 0x39089C9D7005583CULL, 0x565ADB99DE6929A8ULL, 
            0x869478DE022CC6DDULL, 0xBF4A40747DE39799ULL, 0xA97D775B21BBCEC0ULL, 0x54D4EA0B80688C4CULL, 
            0x9E5D5D7CB7618380ULL, 0x2697206333582E92ULL, 0x8C8348A95A43DBCAULL, 0x2009BD307F7E0480ULL, 
            0x94D26EB93B74C164ULL, 0xB5CB58719E24FDC7ULL, 0xE7E21DC92027BBD7ULL, 0x1B602C5D2F56FE32ULL, 
            0x7A26D943BE209E8AULL, 0xCD6C89F3DA301DADULL, 0x69EF3A6A265098F3ULL, 0xD00C2FF59B6653ABULL
        },
        {
            0xB03BB2C7ED64022CULL, 0x8E2F1446E642D943ULL, 0x22A162692F0AFB5AULL, 0x0441A9EBE222D139ULL, 
            0x6D52599E4DC57CE9ULL, 0x1A7135E0E13B170DULL, 0x21CB87BDA0EDAC4EULL, 0xB73346AA81933634ULL, 
            0x463A4E67A39B9647ULL, 0x60E89179548455ABULL, 0xDF926AFFDA3ABC1CULL, 0x9D19AF22C8EE5A4FULL, 
            0x01EBE6311F70A3D5ULL, 0x3C9C4DB9E696DC11ULL, 0xEA08BC3ED9EFDEEFULL, 0xFD3C6F80583DA5CBULL, 
            0xC49871C9F5836E24ULL, 0x7B24C92F5D9D6B42ULL, 0xDE72C1A3B94AFF5BULL, 0x70FCD3B3C89E0207ULL, 
            0x55E4BCFBFF33400CULL, 0x218DC57932D41A98ULL, 0x73B87D7E03070C6DULL, 0x463CD2B1B72E5E37ULL, 
            0x6ADDA371ED70FDCEULL, 0x78E7D959B369AAC4ULL, 0xB07A13B2FCB778A9ULL, 0x744C3B5C1EF38304ULL, 
            0xA0A0DF7005AD48E9ULL, 0x22A0C7E241A730D0ULL, 0xFB08A5FAD0E1D0C3ULL, 0x389E08B32AB2C33AULL
        },
        {
            0xE3C60E02536784E3ULL, 0x1B1C32F77EF18214ULL, 0xF1D820988EA62AB9ULL, 0xA5453ABB1A338B91ULL, 
            0x19E11C40874C8E00ULL, 0xCAB4A95D19A5FCE7ULL, 0x2F3A5E304D7699AFULL, 0xBAE20382B1B363F5ULL, 
            0x3E74261C831F7FCAULL, 0xE8114F1A176DA6BDULL, 0x8262491DE361B424ULL, 0x978ADC734BBAE85FULL, 
            0x46AB4A03FDF26947ULL, 0xB187AB56AA4F1CD7ULL, 0xCE602944F4821655ULL, 0x9DCC76C07496BC2BULL, 
            0xC87438452D2372A4ULL, 0x5661F627E6E7894BULL, 0x90DF3D293C5BE30EULL, 0x8A4D9590DC573AEFULL, 
            0xDFCF60EEC3802C37ULL, 0x7C8F9528D32DA7E2ULL, 0x27E72BDA1431438BULL, 0x9DDE27B95A9F1B93ULL, 
            0x79C39338A67F9377ULL, 0xF69588B1A3C2E709ULL, 0xF6A2B9C9F59841C2ULL, 0x6267A6965A0C93A6ULL, 
            0x56EBBE6391E5BA01ULL, 0xF9E0CBDBA266F719ULL, 0xFA430157F56DAF58ULL, 0x060B5608D630A94AULL
        }
    },
    {
        {
            0xD09A76FD3BA51077ULL, 0x105093AC80E9C705ULL, 0xC79556070F649686ULL, 0xA3AAF0B7C1E4512CULL, 
            0x38746B47863BF126ULL, 0x5725A6059E314873ULL, 0x57E2A8DE752AF4C3ULL, 0x44BD35C6B40983BCULL, 
            0x08E4DBEBB05A5E32ULL, 0xAB42C2B0265E110EULL, 0x02BE0D137D978276ULL, 0xA6416170353F23ACULL, 
            0x821E7AB0F9E9B41AULL, 0xF6155CE7DE9F7CEBULL, 0x04A3AF14208868B1ULL, 0xD384C88664592F3EULL, 
            0x33EAA1A0598334DEULL, 0x079AB21A64352464ULL, 0xA51F62B66524CDB0ULL, 0xD09C30182E463EC2ULL, 
            0x8EC5C7586853D1E9ULL, 0x61358401578958BEULL, 0x8756E73D7A0AA94BULL, 0xAB3E97D6DE31D678ULL, 
            0x8575AF1BCBF0AFA0ULL, 0xC0FC1C8F4E15D6F8ULL, 0x675D386A42895A88ULL, 0xEF96D0617BE54B0BULL, 
            0x1D44E74C849590F3ULL, 0xC5CCC79A7796F069ULL, 0xC834EC54ED17CBB5ULL, 0x7ACE6A9F7DFCD952ULL
        },
        {
            0xA73EE685B39FB78CULL, 0x5BFD1EAA56976C57ULL, 0x51327E4CBC2BD822ULL, 0x481B73EE25DE3DE8ULL, 
            0x4CAB53D5FE40F674ULL, 0x420397F84FA9A365ULL, 0xA97671D838F92CDBULL, 0x73C7C7760E660A28ULL, 
            0x69B55D4F2407A651ULL, 0x653CBE780CBBF721ULL, 0xA2A5AD3154219776ULL, 0xF3D7888B5ED6FD5FULL, 
            0x40A42DC3BE7D256CULL, 0x5C3A31EB9EF7B819ULL, 0x0BC872BCF225D9C5ULL, 0x7D57081BC145E66CULL, 
            0x3AAE7F9413DA4DE7ULL, 0x9DA028D46CEBEFDAULL, 0x75CA05DE8113694BULL, 0x587F67EE5440D866ULL, 
            0x18361ECFDEE5B5C2ULL, 0x01C804C667A05787ULL, 0xE9E979FA6DB9524FULL, 0xBB59B787020D0A9FULL, 
            0x6BD87FB05F85AB93ULL, 0xB297A58D403DA365ULL, 0x7A16ACC06E210641ULL, 0xB5E22A61704ABF63ULL, 
            0xECE539C9E0E89437ULL, 0xAD00B2DEDB47D356ULL, 0x505786911F7FFDC2ULL, 0xBAAFCB86BEA38A14ULL
        },
        {
            0xCAD95449614A226CULL, 0xEB08D651E834BED8ULL, 0xDBF928D01E255154ULL, 0x038142EF42595DF6ULL, 
            0x7002C6DAD0DF71DFULL, 0xC64117524246EAABULL, 0x7A17B3865F41A2FCULL, 0x4565BD5E991FBD95ULL, 
            0xC918D45D1546F44EULL, 0xDA29FA0B6DC546D1ULL, 0x6CD05E560F3FA561ULL, 0xFA485377D61C98E7ULL, 
            0xB15E24C26E45873AULL, 0x2F8DDCAC634E4203ULL, 0xF99B9D745C1FA16CULL, 0x085E111C772C3CECULL, 
            0x6FD2474388212853ULL, 0x746E841C81E135D6ULL, 0x24CABDED7C6B0AA1ULL, 0xE3C72E35277BE9E9ULL, 
            0xC0C977D6C5833632ULL, 0x09720D508BF9D7DEULL, 0xB989F75CF91977D5ULL, 0xD7A649AA2F297079ULL, 
            0xB988C65C8D2FEDDCULL, 0xEBF5B2875DE5A29BULL, 0x450C1EB872C34E4BULL, 0xEBC05B127CCA4BA9ULL, 
            0x8553C85CC3EDCFC6ULL, 0xC6EDB2B2F348CE61ULL, 0xE0C7FDBFF00517A7ULL, 0xD14C3B2BD6A7D33FULL
        },
        {
            0xE89D9E78676BD68BULL, 0x28D88711A7277BECULL, 0x150D6821F110C9C2ULL, 0xCE68BDF7A7DF05EEULL, 
            0x94A67553AFAFDE1AULL, 0x48EC55FC48D67857ULL, 0x41191966461076D1ULL, 0x0836B2CAAFEBDD00ULL, 
            0x21E7FB0D8099BEBFULL, 0x49632555F5B5DAD6ULL, 0x7B37179613BC32AAULL, 0x3E1C859BE1304AA2ULL, 
            0x8F6A52DCF315480EULL, 0x9F0F16B7E8C04ED6ULL, 0x7ABC54DB3BDBE361ULL, 0xE27305C6725477BCULL, 
            0x76553B87B80F38E2ULL, 0x299C6F80907AB757ULL, 0x41AEE5AE9AEFD6EDULL, 0xBF2D4D47DB991AC7ULL, 
            0x0F1E1EC77F06A2D3ULL, 0x28780597F9330771ULL, 0x12F96E1B32828A2DULL, 0x894E7A096CA9D945ULL, 
            0xD1E833B5CEE153DDULL, 0xBB8125EB5DDB0B50ULL, 0xFF45DAADEAED325AULL, 0x8A9CFB42329E00B5ULL, 
            0x6D8D947CA4774E88ULL, 0x27F3C69AA332FC8BULL, 0x6C203C9692FF4F25ULL, 0x1378B9F92FD85FBFULL
        },
        {
            0x3C9345555DB07259ULL, 0x9472400404392A0BULL, 0xA07F63B6FCCC7299ULL, 0x8230F60188DA6666ULL, 
            0xFA4443D12783CD51ULL, 0x3026753E41DEAAD9ULL, 0x27C369283EB36D91ULL, 0xE4CD40916738F70BULL, 
            0x468773D5F4762B9BULL, 0x265F2E897EDD188EULL, 0xDFC4780C114F3A21ULL, 0x99240E1D7D3F181FULL, 
            0x3902BFB19DBE2FC8ULL, 0x979FD53208904A18ULL, 0x42F4AE8AC287FC4FULL, 0xB4AFC946C054E932ULL, 
            0xA6F9822ACF6409A2ULL, 0x937AC842CDCC8AA7ULL, 0x4318939750555B93ULL, 0xB0BF9086705F64BFULL, 
            0x3EEB6A0267E009ABULL, 0x3E2D66569C6EE5E4ULL, 0x55D2DA34F403E34BULL, 0xF8964060426099BBULL, 
            0x74C3BE28180F4766ULL, 0x660BB9077BA8FEDFULL, 0x65D5156238FADBC6ULL, 0xBDFEA124E90F5345ULL, 
            0xCFA181CCE75B74F5ULL, 0xA4E9BFD709FAC917ULL, 0xB34132979452B2E5ULL, 0x5840E370C3D603F8ULL
        },
        {
            0xD51A9104409143E2ULL, 0x30B49D62D956A234ULL, 0xE8BEB05F6C98CBAAULL, 0x649ECE7BF4BCB1FEULL, 
            0xD2E12F0247C04714ULL, 0xDECCC57BDE57147AULL, 0xCF743426F034D196ULL, 0x21A958E680893222ULL, 
            0x52E0E7CE142B8215ULL, 0xA7C9AAB1A3616B2DULL, 0xFC4B299D473D23F0ULL, 0xBC00157768EDBD02ULL, 
            0x69142AC557CD1B66ULL, 0x1CB9F0ED61A029D6ULL, 0x85A03FCB24631ACEULL, 0x67EADB3F5D502D28ULL, 
            0x45B3CA80F21773CEULL, 0xD9EE0F658DF71E80ULL, 0xFF2281F428B921CAULL, 0x3BE25943F45430E8ULL, 
            0xE40B338AA886B899ULL, 0x5AEC1675BF10B01AULL, 0x86B4C09B1EA155EBULL, 0x1D7BBDA079C996F4ULL, 
            0xFBF47D487DF70AE1ULL, 0xA5C658BA5C0CAD4AULL, 0x6F32CE989BAFB558ULL, 0xD70740D341B1F87EULL, 
            0xFCFFAD587354382AULL, 0x34B331150765BF36ULL, 0x076C05032FBF9753ULL, 0x2A4249041DD9E41AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseHConstants = {
    0xE32FAFB2488034DDULL,
    0xA318796A7424F482ULL,
    0x5946BE98EEC5BCD0ULL,
    0xE32FAFB2488034DDULL,
    0xA318796A7424F482ULL,
    0x5946BE98EEC5BCD0ULL,
    0xAE002E639C913AADULL,
    0x34C0907B848367F7ULL,
    0x2C,
    0x62,
    0x13,
    0xC7,
    0x81,
    0x4E,
    0x55,
    0x7E
};

