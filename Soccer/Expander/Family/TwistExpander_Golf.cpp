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
    std::uint64_t aPrevious = 0xB375D0B636C716D6ULL; std::uint64_t aIngress = 0xF6A588EF2AD1B2EAULL; std::uint64_t aCarry = 0x8A3C50DF72AF8051ULL;

    std::uint64_t aWandererA = 0xC1F9B407429F8870ULL; std::uint64_t aWandererB = 0xBB209A2DC5D777B3ULL; std::uint64_t aWandererC = 0xA00E1F2009CC4C5EULL; std::uint64_t aWandererD = 0xDD03D0E6C9766CD3ULL;
    std::uint64_t aWandererE = 0x93A9D7F13CFBD7CEULL; std::uint64_t aWandererF = 0xD9AEAEFB7C66B221ULL; std::uint64_t aWandererG = 0x94134FC73C908EF1ULL; std::uint64_t aWandererH = 0xE8C5408D4B57C3DAULL;
    std::uint64_t aWandererI = 0xF17713C4102DB78DULL; std::uint64_t aWandererJ = 0xC5C4ED78BB6BB0C4ULL; std::uint64_t aWandererK = 0x8AA86DD5B6E7E208ULL;

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
        aPrevious = 11753550762180345843U;
        aCarry = 17093684906344619959U;
        aWandererA = 13036073791341955943U;
        aWandererB = 15261362739789065788U;
        aWandererC = 12817460251878746671U;
        aWandererD = 18131746015713458994U;
        aWandererE = 14177444599367095512U;
        aWandererF = 16439039617157908225U;
        aWandererG = 17109915952034085311U;
        aWandererH = 10433677709386724351U;
        aWandererI = 10954451607901416116U;
        aWandererJ = 12356457716804392993U;
        aWandererK = 11533931830255873213U;
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
    std::uint64_t aPrevious = 0xD78D4D516079B9C5ULL; std::uint64_t aIngress = 0x854050A0BE6FCE21ULL; std::uint64_t aCarry = 0x904DB8F78F17A660ULL;

    std::uint64_t aWandererA = 0xF51B05540A21E55DULL; std::uint64_t aWandererB = 0x9C422EE9DDC70A27ULL; std::uint64_t aWandererC = 0xA8F0DCA51329A66AULL; std::uint64_t aWandererD = 0xB62D74E40CAD7F74ULL;
    std::uint64_t aWandererE = 0xAF2992A3A95DCF39ULL; std::uint64_t aWandererF = 0x8F536D4708975953ULL; std::uint64_t aWandererG = 0x8E22CB5115F3C220ULL; std::uint64_t aWandererH = 0xEB09E4F1A0F6868EULL;
    std::uint64_t aWandererI = 0xDD658D3F3ECA2DE7ULL; std::uint64_t aWandererJ = 0xC0173D82608381F3ULL; std::uint64_t aWandererK = 0xEF89AC0EFC9E84E0ULL;

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
        aPrevious = 16913779599286141143U;
        aCarry = 12975812870021223154U;
        aWandererA = 14150149481330870025U;
        aWandererB = 13256207958284467788U;
        aWandererC = 14334281793048027530U;
        aWandererD = 9686796508316357661U;
        aWandererE = 14532022377311802560U;
        aWandererF = 9554703328294520556U;
        aWandererG = 11123749013842872025U;
        aWandererH = 11897593993071597615U;
        aWandererI = 12628913463116248741U;
        aWandererJ = 11509449419867879172U;
        aWandererK = 16397201829971068260U;
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
    std::uint64_t aPrevious = 0x84595330B5933C78ULL;
    std::uint64_t aIngress = 0xD7C55A4A94697A6DULL;
    std::uint64_t aCarry = 0x81689DCB50B5EB28ULL;

    std::uint64_t aWandererA = 0xB384999D64A4B1D5ULL;
    std::uint64_t aWandererB = 0x964CDA28FC0B3825ULL;
    std::uint64_t aWandererC = 0x8B4F36CD59CD463AULL;
    std::uint64_t aWandererD = 0x815B39D497C03BA1ULL;
    std::uint64_t aWandererE = 0xA041D8077889592DULL;
    std::uint64_t aWandererF = 0xBA6E681A3B5096A1ULL;
    std::uint64_t aWandererG = 0xFC58BCAEF94080B7ULL;
    std::uint64_t aWandererH = 0xBFCFBBD08ECEE54BULL;
    std::uint64_t aWandererI = 0x9E0C0FB4165783B4ULL;
    std::uint64_t aWandererJ = 0xF1E5277DC5F4422BULL;
    std::uint64_t aWandererK = 0xE6E6287FBD317B1FULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB, 2);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD, 3);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC, 5);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneF);
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD, 7);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
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
    std::uint64_t aPrevious = 0xB19A492365FFC16FULL; std::uint64_t aIngress = 0xF3B4147D3219D87AULL; std::uint64_t aCarry = 0x8276726600CFFE07ULL;

    std::uint64_t aWandererA = 0xFBBD51C5A9040F29ULL; std::uint64_t aWandererB = 0x917C4C1263D815ABULL; std::uint64_t aWandererC = 0xB0EF3C3E457F8588ULL; std::uint64_t aWandererD = 0xD60D1888BFAD2052ULL;
    std::uint64_t aWandererE = 0xAC38D22D13F135C1ULL; std::uint64_t aWandererF = 0xEB81A7463802B711ULL; std::uint64_t aWandererG = 0xC2AC89592C8922B4ULL; std::uint64_t aWandererH = 0xD5308233ED144CE3ULL;
    std::uint64_t aWandererI = 0xC584F72EB5B79E7FULL; std::uint64_t aWandererJ = 0x96BD48419B8E6D01ULL; std::uint64_t aWandererK = 0xDA0727CA3A6C7663ULL;

    // [seed]
    {
        aPrevious = 15007121279508872432U;
        aCarry = 9237541385152954065U;
        aWandererA = 18345214076292834542U;
        aWandererB = 12793649647741706996U;
        aWandererC = 12447749876336941610U;
        aWandererD = 10096123882061700212U;
        aWandererE = 16571967717270352683U;
        aWandererF = 15242414964131324803U;
        aWandererG = 10708237502363384960U;
        aWandererH = 12845687572969314697U;
        aWandererI = 16602846932653000472U;
        aWandererJ = 13850614617015160324U;
        aWandererK = 17595276121248809888U;
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
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 3, 1 with offsets 3145U, 3761U, 5980U, 6220U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3145U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3761U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5980U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6220U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 1, 0 with offsets 2156U, 7972U, 2698U, 2577U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2156U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7972U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2698U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2577U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 0, 2 with offsets 8166U, 3041U, 3481U, 4589U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8166U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3041U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3481U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4589U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 2, 3 with offsets 2141U, 4225U, 4860U, 3045U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2141U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4225U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4860U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3045U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 2, 1 with offsets 264U, 741U, 1484U, 1691U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 264U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 741U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1484U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1691U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 0, 1, 2 with offsets 1317U, 1439U, 1032U, 857U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1317U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1439U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1032U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 857U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 3, 1, 2 with offsets 948U, 1427U, 1785U, 976U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1427U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1785U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 976U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 2, 3, 0 with offsets 280U, 1874U, 774U, 9U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 280U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1874U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 774U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 9U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 174U, 1532U, 268U, 877U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 174U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1532U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 268U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 877U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 0, 1 with offsets 6729U, 5219U, 2382U, 6551U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6729U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5219U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2382U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6551U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 0 with offsets 2972U, 413U, 3455U, 8006U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2972U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 413U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3455U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8006U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 2, 2 with offsets 7686U, 171U, 5654U, 4803U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7686U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 171U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5654U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4803U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 3 with offsets 75U, 7047U, 180U, 3643U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 75U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7047U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 180U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3643U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7807U, 7102U, 8171U, 1407U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7807U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 7102U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 8171U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1407U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 202U, 770U, 953U, 436U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 202U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 770U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 953U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 436U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 924U, 1616U, 317U, 1664U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 924U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1616U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 317U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1664U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1696U, 1902U, 104U, 1250U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1696U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1902U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 104U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1932U, 583U, 100U, 2007U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1932U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 583U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 100U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 2007U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 1, 0 [0..<W_KEY]
        // offsets: 100U, 835U, 1528U, 854U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 100U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1528U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 854U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Golf::kPhaseASalts = {
    {
        {
            0x0EFB8190C93CE0E7ULL, 0x21D63DCBA1382245ULL, 0x2FA97713E2B43F71ULL, 0x1C24A6C0224E9BE3ULL, 
            0x7D8835AE0122C0A6ULL, 0x58656BD788E2301EULL, 0x2BBFF423A7559C7DULL, 0xECFE724942688FB5ULL, 
            0xDA122455E87D43E5ULL, 0x4C4E330CE92D6A16ULL, 0xC1B07647469D6232ULL, 0xD99676106C5DCC9CULL, 
            0x2A24882C7C7ECF01ULL, 0xED0D84DE8957600BULL, 0xC63B4877A6E8FF7AULL, 0xDCCCFEA653A9A0D6ULL, 
            0xE39CE249CB874BC9ULL, 0x73532B817771DE8EULL, 0x8FCBDF2FC6BA62FDULL, 0xBF074FAC020C0526ULL, 
            0xFAD2BAF30E33EE4CULL, 0x003FAA92037E2E9DULL, 0x1425D2E310277315ULL, 0xFB4E320656364EF1ULL, 
            0xF8AA0B66B5DCAB23ULL, 0x7CA60A20BADCEED5ULL, 0x7124512BB5AE7880ULL, 0x891D02B3AF6B8EB9ULL, 
            0x086E57CF6A92AE80ULL, 0x44BAA1741FC0A4B4ULL, 0x5066136DDE9D702FULL, 0x0BFBFB6C76402EBDULL
        },
        {
            0x1EBE67276E15F4C0ULL, 0x4D2FD480B47452EAULL, 0x4EE61E396257C549ULL, 0x1CFA4BB0CACC2E54ULL, 
            0x8F0677FFEB25A6A4ULL, 0xBBED5F239AC1F5C2ULL, 0x30F3FB17818B7D11ULL, 0x277B107A2A44DAEBULL, 
            0x9F3B1C7B6105DA68ULL, 0x51289DC08201CCD4ULL, 0x78F25BA009511F52ULL, 0x42DC591B1BCD9D4DULL, 
            0xC6C2537116BC9C91ULL, 0x2BD09C2535223925ULL, 0x185C6BF9A956F0C6ULL, 0x8C62274F322B6C15ULL, 
            0x4CCB9E66F23C5078ULL, 0xBA191C12B058F43AULL, 0xA41E7A348C2481B7ULL, 0x9B398CBF9234195FULL, 
            0xE7A33A5A0CDEE81AULL, 0xE1B08137AA58365BULL, 0xC74B0EB056994870ULL, 0xB11449029AF1D2B1ULL, 
            0x1C795AB4A9114335ULL, 0xE34493DC77A1D8ABULL, 0xE88A46850541FFC4ULL, 0xC07C43BDDC255213ULL, 
            0x75D05DC0702CACDFULL, 0xAB59DB593C6CF7B6ULL, 0x848EFAAFDFED66E1ULL, 0x03B65A9938252D3AULL
        },
        {
            0x8267C1916CA27CC0ULL, 0x7F19A6BCBAE3E3D7ULL, 0x69C88806796D2F9FULL, 0x3D37FF8ABB36E295ULL, 
            0xA086CB8164DF009DULL, 0x61ADF554DA2D12D8ULL, 0x856619AE055A7F48ULL, 0xFC020C8CB26CA5C5ULL, 
            0x2C46BCAA70693929ULL, 0x68C1B1A24AD4207BULL, 0xC9C43C4934E813C6ULL, 0xB21092A8FCD7B20EULL, 
            0x36AA9DB16ECBC21EULL, 0x452BEC4DF4A15BB0ULL, 0xBC5B538369BC60D4ULL, 0x6CA99FF96B5F8436ULL, 
            0xA8E6938BA8A82497ULL, 0x313D254B97D19F36ULL, 0x2258BFA1117AD389ULL, 0x936C31253338297EULL, 
            0x6DD679627D83FEDEULL, 0x79066D0A5784D708ULL, 0x3ABD6C012101B813ULL, 0x0EFD2DE522BBFDA6ULL, 
            0xA7AFCC21B266E58DULL, 0x71DC31769EC8FBD1ULL, 0xD36CF10C3ADF6A61ULL, 0x0BC2FAE607A16C3AULL, 
            0x4D5D664B0DB90764ULL, 0x17C425BBFE4CCADFULL, 0x7315E57475F1555CULL, 0x74C5F5B8FD0DB387ULL
        },
        {
            0xC066962169DB02BDULL, 0x52D96731AFD16AFDULL, 0x47BE7612BCAE7A47ULL, 0x5161AD16E44C09E5ULL, 
            0x9E3F2200F8CA50F1ULL, 0x32BE6BEA9B9E55D4ULL, 0xAA3DB640D737E6A3ULL, 0x0BE339E33DC3324AULL, 
            0xE17CB7397ACA0AFEULL, 0x0D3E2141D56B1427ULL, 0xA1CDCE58A63BEAE2ULL, 0x3EFF42C1A78566F2ULL, 
            0xC004672C08B473CDULL, 0xB202D953D7DA6CCEULL, 0x97CF28F3F86BA542ULL, 0x64E5572EB21ACC6EULL, 
            0x65EB5E885916C402ULL, 0x912E5C037493FA4BULL, 0xFC95E249585E41FFULL, 0x6A6A7FB5B1E1A952ULL, 
            0x96B279452872D6A8ULL, 0x33CD319C70E354A7ULL, 0xEF366CC05C833BF9ULL, 0x7A6A85F11CA2E6B5ULL, 
            0x9312DC04DF462869ULL, 0x10D8703224540ADCULL, 0xC6B2EF032C7430BEULL, 0x8FFD42B2A3195360ULL, 
            0x51BDBE1F847C1B27ULL, 0x8F780526A05259D2ULL, 0xD92BEF4F5291AE62ULL, 0xC505593BAD97DEE3ULL
        },
        {
            0xC70F3C6A444ABE8EULL, 0x644AA0C7192EEB54ULL, 0xFBD18D4DD1C177C9ULL, 0x1C2D3216173F2DA4ULL, 
            0xA68668658736413DULL, 0xA09345FB16BF514AULL, 0x05A48CD3A4489DBCULL, 0x8DD1FFA87BA8D618ULL, 
            0x38BE286DD1ECF95EULL, 0xE97DE8ABE67FCE38ULL, 0xFD16410DA54D35CDULL, 0xC5D7694F991F802EULL, 
            0x3658FC709125EC48ULL, 0x3B08DB41AD990696ULL, 0xD386D3BE69C25FCDULL, 0x940793C504312B7CULL, 
            0x13A928002D46CC65ULL, 0x7118669952F4040DULL, 0x124509B347C1D58EULL, 0x80ECB33686C50128ULL, 
            0x7ABBC58BB5963E9DULL, 0x0270D7C639CFFC4DULL, 0x529D6F73DF5AF0ADULL, 0x0E9CD6E912D4FD64ULL, 
            0xBF52CA3DD02A7B70ULL, 0xAB296AD77ED4BA0EULL, 0x74B9BBB8EA17B887ULL, 0x178D502BF0A53B29ULL, 
            0xB5B68C9394E40672ULL, 0xA1B0F5514ECAABABULL, 0x85D7B59C82AC24EEULL, 0x38097F7E67D4109DULL
        },
        {
            0xCAFAD9D613F65F59ULL, 0x614E85FA66AE4411ULL, 0x142B3BA853CF12C0ULL, 0x0AE299B20F2782FCULL, 
            0x53D9D639E9EDEA35ULL, 0xE7FFFFB4470E1822ULL, 0x8DEFE9C942505F93ULL, 0xD84E8052C1BBC619ULL, 
            0x7BC188BD5F3E21FAULL, 0x59F7CBF0D9B38F2EULL, 0x7E81A215190CB679ULL, 0x91D34792562002FCULL, 
            0x21DD72428EDFBC1BULL, 0x3C8653D39F14A3EEULL, 0x975FED0BA9F75309ULL, 0x4DE03BA489BEA940ULL, 
            0x0397C937C488157FULL, 0x3D5890F174B1D1F9ULL, 0x61D0ABCBCE1F5C03ULL, 0x3A82732C2B171B14ULL, 
            0x74E00DE65C69A90EULL, 0xEC4AB0049CA9B4B9ULL, 0x5314D6A524838EBCULL, 0x4AB9B652C17C6912ULL, 
            0x1A77511736193F73ULL, 0xAC3FD011392C7FD7ULL, 0xD8E6EAAC447DC28EULL, 0xFC1B5B71D2D321FEULL, 
            0x14235AFDD07F8D4DULL, 0xDA96663B6CBFCBE4ULL, 0x4F3A80EC29782A25ULL, 0x62B7F19B5FE7EA56ULL
        }
    },
    {
        {
            0x01463D9FB56009ACULL, 0xDAA6633CB7FB5002ULL, 0x5CBCB903675F7CA7ULL, 0x053CD4106094E013ULL, 
            0x1C6C2FEF810A1C8BULL, 0xB699A2C1E2D0BE13ULL, 0x0D4EA2D7F97A1BC4ULL, 0x02C2B1DF2EA08BC5ULL, 
            0x1E36FEBCB2FDBCBEULL, 0x5CF5AB5940E3E31FULL, 0xC8B129836D716DEFULL, 0x1A49D3220FC36DC6ULL, 
            0xE599702A06C8D72BULL, 0x2665B88D773BCA54ULL, 0x10F89C80EE013221ULL, 0x3E6161A40D2082C4ULL, 
            0xE4D9EF098B92BD44ULL, 0xA6C7DD5C07E84E08ULL, 0x95B1CE333C5C179DULL, 0x5221EAABA8B54962ULL, 
            0xEA976F88CF0DF6BBULL, 0xF575C18315441E4BULL, 0xA2E1E42ED134640AULL, 0x037F4840F3103ADAULL, 
            0xE9152F18E7FEC9A4ULL, 0x29E073D42329723AULL, 0x7836867E81FC89FCULL, 0x09D6E3E9D2E8FB80ULL, 
            0x455E8B2938B837FFULL, 0x78F242ACA01A5DBBULL, 0x4C2F3673ED049726ULL, 0x724810621773007EULL
        },
        {
            0x1D73CCC71A3BF31EULL, 0xE09FD3283F116796ULL, 0x55707F8BB4FC9576ULL, 0x95CD86BC7BF89A34ULL, 
            0x235185B7B2DD0C96ULL, 0x14440149876733CEULL, 0xAF958F5A7C3F5EE0ULL, 0xEDC72EED27A4DFB4ULL, 
            0x0561DF2A5C3EEEC1ULL, 0xF14538A15E467A12ULL, 0xF49EFD79DF8B919CULL, 0x9C87F63A40F8B975ULL, 
            0xF08484ECFE94BB4DULL, 0x21A7BDD003D1DB72ULL, 0x291A54EDB0B65BE2ULL, 0x330B2B367BF85FF9ULL, 
            0x3A3A54F4987319EBULL, 0x315A55755B433580ULL, 0x3A7A59ADEF28A64AULL, 0xD301301C6F0DEC79ULL, 
            0x664BE00193EDA8FEULL, 0x7F6D0463C531D0E0ULL, 0xAD02A2C309FD39F1ULL, 0x2A76AEFE348E0B5EULL, 
            0x5D7073B16446DFF4ULL, 0x8E8DCD292E6C0097ULL, 0x4238870D50D652FCULL, 0xE4D8E3A299B6683EULL, 
            0xAB371A4DE8FDDFD9ULL, 0xDD164D65CAB1EED1ULL, 0xE836867924C413A1ULL, 0x1CAC6BC41546F1C1ULL
        },
        {
            0x6979F2E671EA9DDCULL, 0xF9DCEA248C65295BULL, 0x5A81CDC0540DCD3CULL, 0xE72027A76C44EE18ULL, 
            0xA7687D721EC77B0CULL, 0x2DA4ADF6E4CD919DULL, 0xE2A396CA27F76AD4ULL, 0x0190CC5B15A1CF82ULL, 
            0x56F9CE1FA470B79BULL, 0xD0AC2FE9BB438272ULL, 0xBE894007F40AF585ULL, 0x5AA86536A2365FECULL, 
            0xFB626BE9EDC60C9EULL, 0x12C807FB06C1A3E8ULL, 0xAC7D3FD8F2AE0C3DULL, 0x181DB204D04A575DULL, 
            0x569141E882AA7E57ULL, 0x509477AE16871677ULL, 0xCF2677FEF67E4EB5ULL, 0x231E01EE5E170B3DULL, 
            0x81B52FE59582F44EULL, 0xD7C2CA61CD661C1AULL, 0x1AE7D68AA501947AULL, 0x3F5FA9DB79D6794FULL, 
            0x7373DAEC1F535CDFULL, 0x8667270F47CE534EULL, 0xA866BFC453AEA91AULL, 0x7AB77A9729CEB99BULL, 
            0xE0DBBAE76C02A35EULL, 0x6540C0F80770831CULL, 0xBF338BA7499F2633ULL, 0x61304C8889285D4EULL
        },
        {
            0xA93C82D2B0FE96E3ULL, 0x03992DA17CD51C95ULL, 0xA0B565DF56074504ULL, 0x38061041E916BD69ULL, 
            0x701D231E95CB1CE5ULL, 0xD64C035600A524F0ULL, 0x7347CCF6AB844492ULL, 0x6521F8A9D89303DAULL, 
            0xF0A380ADB977F9DAULL, 0x299A637D7F725B10ULL, 0x7B98799051A451E4ULL, 0xF520B34521876FFFULL, 
            0x4C574E9423B20247ULL, 0x837EDF4349CD9BA0ULL, 0xFEACCB4C54A26F9CULL, 0x19276D647DD6C250ULL, 
            0xDD18827C6C2C7569ULL, 0x6572DE303B493DB8ULL, 0x0C8CA0F8DEBB7BEBULL, 0x3FBB088107CCBECBULL, 
            0x0E9F6BE54F468700ULL, 0xA754E93B5FB45851ULL, 0x1F4C992DB8CAF7E0ULL, 0x412ED5BA21FBC855ULL, 
            0x3E5479EFF9D83D50ULL, 0xD49EF9FECE55035DULL, 0xD3E2F1C714AD34D5ULL, 0x85A070BB74115D9AULL, 
            0x902BB81E9654DB64ULL, 0xA061A2BD53A25C36ULL, 0x27B0298F7B37A20DULL, 0x09DA531384D5B5E9ULL
        },
        {
            0xD134A067A408558AULL, 0x15F19B3B6A9E04EFULL, 0x88BD03C2E6C53A0CULL, 0x6B79400C1E4205FBULL, 
            0x8AB5A675C47ED37DULL, 0x28F94B540373AF94ULL, 0x597B62CAD46E204AULL, 0x25E972020DD9784FULL, 
            0x34FF053C4B82F6DEULL, 0xFF65F0A9994C48C2ULL, 0xFEBE79EA36433BC7ULL, 0x658CDABF3AA65F4CULL, 
            0x23CB89C72106B2A4ULL, 0xEFA52D1C6988E0C8ULL, 0xDD9CC6B5721393ECULL, 0xE92FBBF672304C9AULL, 
            0x95F0BD6196B0323EULL, 0x60E4C582375B9511ULL, 0x513E43C03490C119ULL, 0xA733DDA4D59F22BBULL, 
            0xECF2C4CB7CF56675ULL, 0x5B61A130D3027E3EULL, 0xAA449FBA0F8F4656ULL, 0x9745E6F35CE31C30ULL, 
            0xA86CF42F1C3D4A2DULL, 0x7628E04269CE96FEULL, 0x20770ACA98E4B0D2ULL, 0x1BBFF4D20EC741E2ULL, 
            0x82427A1665A23004ULL, 0xE8ED8050E0993444ULL, 0x8CD427C42D2A7FD7ULL, 0x3397526FD4C7001FULL
        },
        {
            0xBCBC510E3EE7C104ULL, 0x13F57F896AA8D4B1ULL, 0x94BA69F77A48BCB0ULL, 0x7A4360D821F53AD1ULL, 
            0x8524236BEA889BA3ULL, 0xEA0BCC32822C5E62ULL, 0x19AAD807A8F2C727ULL, 0x1D4982C43716062AULL, 
            0x5A550A68C5B03D09ULL, 0x0989336948232AADULL, 0xA27910511B761E15ULL, 0x769B64159A2EA945ULL, 
            0xB3E7D8990477BF8AULL, 0x13E6D33F95D69082ULL, 0x8EF6E53CDE1F03BCULL, 0xD13BA9C244170E12ULL, 
            0x33DAACDC5BCFAC38ULL, 0x54BE5A2BED726AF9ULL, 0xF58B216490131960ULL, 0x2E54CA3F25C91C59ULL, 
            0x9AC5CA1C986C8B7DULL, 0x94AEB1D3FD12F8A2ULL, 0x4498B7BFD4158551ULL, 0x0893F5F3E8D4BC15ULL, 
            0x0D6C85524C35A77FULL, 0x0AF2B52E49CC6CCBULL, 0xB7F78AF5BA4A6A11ULL, 0x97AD49C11EBDBD50ULL, 
            0x9B40D50028A57171ULL, 0x1CA4B5531A1CCDBCULL, 0x3D0F734991014B16ULL, 0x6EF2F47742AAA027ULL
        }
    },
    {
        {
            0x2CD1BE80137C2444ULL, 0x43764507CF8FB351ULL, 0x61C93CCA4F4B470AULL, 0xC4F71CB2EFF3FB51ULL, 
            0x6629B74ED929E6D5ULL, 0x6AE0305DA220E987ULL, 0xC34BC710F1D102EEULL, 0xDD94BA6B101B0DC7ULL, 
            0x2CD51E8767C7EEA6ULL, 0x9BFE10AB24389456ULL, 0xEE8BB0515020D0C1ULL, 0xE26260ED61B19EFBULL, 
            0xC9CFF5BBE835C992ULL, 0x6429A4AFDD1001DBULL, 0xB76D571614F92146ULL, 0x63D00960E8AB6F00ULL, 
            0x34C33EA0B6F39A29ULL, 0x5178841E0AED059EULL, 0x84292274E22B6E52ULL, 0x4F2DA43C9CAA58E1ULL, 
            0xF11F222F562B7495ULL, 0x79833B2A1CBABE2AULL, 0xCC482FFD8486043EULL, 0x50955965753C0474ULL, 
            0x953667C6E24E7F80ULL, 0x59B249267D2B00FCULL, 0xB405E78E150973C6ULL, 0x62E6B5928E79BE32ULL, 
            0x26AAFC83AA510DD8ULL, 0x53BF5304B0B20DEBULL, 0x28F58469A822DF18ULL, 0xE1085F3B1867DDA3ULL
        },
        {
            0xD64917D4E73FD399ULL, 0x0718DF727444C1B9ULL, 0x9214BB4DFEF938EFULL, 0x7F6958D16BA578F5ULL, 
            0xCA69C4E997309476ULL, 0x0693627096356131ULL, 0xC0DA6A2F60862FCCULL, 0x2ED697544549EC2BULL, 
            0x0285EA2C85691D18ULL, 0xC004A868250D5494ULL, 0x3BC390CC8E5DDC79ULL, 0xD67C18B0139B2EC0ULL, 
            0x60F4DBF81B7469FCULL, 0xF3E0929E129FEF2AULL, 0xCFE60902C7A293FEULL, 0x659D83EB0AEFFE96ULL, 
            0x5E22A09D3355055CULL, 0xD486DCC4A2EA025BULL, 0x4F3C97997C4CB4B5ULL, 0xFADB4CCEF9749876ULL, 
            0xB899F21E35289152ULL, 0x25A1C2EAEE527DC1ULL, 0x55D56AD2F211303EULL, 0x36A4603408B559CCULL, 
            0x301493D4C364AFCAULL, 0xDD6B1B269CF5A7BAULL, 0x2B6B670D5FFD01DCULL, 0x76386AA718BE819EULL, 
            0x09F65FA39A3DC7FAULL, 0x9E24A18B4D392AC4ULL, 0xE643FDF8DB858BF9ULL, 0x1477BB4E4BCA2242ULL
        },
        {
            0x91DE4E0A89A9A2ABULL, 0xE45CA11BF8DB5119ULL, 0xA8FF1046AA30BCDFULL, 0x1FE5925243F26B3BULL, 
            0x4102DE80E92AEC65ULL, 0xBA72D9D38D1B0D3BULL, 0x1B42A6992F61BAB1ULL, 0xDB8A99EF433F2798ULL, 
            0x232CF016CA80E7F7ULL, 0x9926562931C91F4BULL, 0x3B9148D7F0839440ULL, 0x2368C459D416FDD9ULL, 
            0x377007D34954ECDFULL, 0xC01F718375B61DDDULL, 0xE5959CA5DF0343BFULL, 0xE7DD976210397FC5ULL, 
            0xA8651E310E1F2A7EULL, 0x9319D184B47ED983ULL, 0x8CDF1E2F02F047ACULL, 0x6F09E9506CFC1BD6ULL, 
            0xAA31B9D3001AE1BCULL, 0xDE172FBACE8C9DE0ULL, 0xD5109270252FF8DAULL, 0x941F4C297883ED77ULL, 
            0x636DBA48596DC4F1ULL, 0xD64311F9FC7B9607ULL, 0x44FBBA4AE50851D3ULL, 0x684CDCB483BC0F12ULL, 
            0x4B7BBF21A6AFA6B5ULL, 0x0EF73AA5D7AD40F9ULL, 0x677D8AD809E49CC0ULL, 0x124FF92334E55175ULL
        },
        {
            0xF9086794C6775EC5ULL, 0x27DEE105AE79B475ULL, 0x056D25C245967F8CULL, 0xAECAA489DB49F2C4ULL, 
            0x3E9783F82CC53714ULL, 0xD911229BD0DE2EC8ULL, 0xB6499207782FFDD6ULL, 0x0B85C3B52E492F2FULL, 
            0xA55CD47C6B510459ULL, 0x3E24C30D8274B214ULL, 0x46772465A9FB8428ULL, 0x10D98F07B4EC3AA7ULL, 
            0x4779CC9F371DE54DULL, 0x65BF358FCE6B9485ULL, 0x929349860DA7EA53ULL, 0x1AA75B953F314E1EULL, 
            0x1463F43FFA023F1EULL, 0xA729863375FD5D89ULL, 0x70A15B12A08B0245ULL, 0xD54D5D98DD394982ULL, 
            0x96D60F56DF72D5C0ULL, 0x390671F0D6D3AC20ULL, 0x3B07033FDCC64E58ULL, 0x8F291DF15EFF9643ULL, 
            0x1A7494CDAF326E7CULL, 0xEDD82FD1E725485BULL, 0x8893FB73620B3A18ULL, 0xC21EDDA3D7B5F813ULL, 
            0xBC70ED6979888916ULL, 0xF71034F1DF5B4447ULL, 0x5CEB3A5B0E1E16E0ULL, 0xA63794426F865D57ULL
        },
        {
            0xA2BC889D45CDDFB4ULL, 0xB23C8619C7873F73ULL, 0x9D65AEE986E32C7AULL, 0x1CB00274575662E9ULL, 
            0xDAAB6AB6456FEF33ULL, 0x832745C05EE79261ULL, 0xB01BE6BAA9C11262ULL, 0x08A51DEAD9047154ULL, 
            0x63CD33170BDBF111ULL, 0x3E4E07290D08F19DULL, 0x31DF0F08EDB46413ULL, 0xCB1F8FBB82360ED6ULL, 
            0xAB14A07188C84E06ULL, 0x19BE370F00F94889ULL, 0x87D9F3B1F37D8A3AULL, 0x1F8098D7BE12A6B4ULL, 
            0x0FEA2DB0BCFBE53CULL, 0x877476C6F94A2F16ULL, 0xDCD972DDC0A851E2ULL, 0x8B9D44D5C2C74390ULL, 
            0x2E35337A29D6A1BDULL, 0x467787DB9ADD7543ULL, 0xF9ACA203FB4E36CAULL, 0x9BB7E9B06FC4448AULL, 
            0x527D5FA3A53BA113ULL, 0x722C7C1C1E64EC36ULL, 0x58E4454F06BF4572ULL, 0xF8CE65018CF04859ULL, 
            0x3C32FD2AE8211046ULL, 0x39A8C606E108ACF4ULL, 0x7FFBEB3588748B72ULL, 0x844F265C86E9AA23ULL
        },
        {
            0x355C57B66539A9BBULL, 0x0D0D900C79BF5950ULL, 0x587747E4F826B2E1ULL, 0xD840C00E94DA1C63ULL, 
            0xAA920B7ED625349CULL, 0x634FFD07F0BA56C7ULL, 0x17857C1510605DDDULL, 0xAFBCF3AC706B34D7ULL, 
            0xB6F6491557369CF4ULL, 0xE93537337C1C34C0ULL, 0x24C58F30DF38DB6CULL, 0x7A67E664B9FF5559ULL, 
            0x05AF0B5D8EB42669ULL, 0x97E3F5E9291F9FBFULL, 0x189AB8CD97DC41FAULL, 0xB12E345645F1AA14ULL, 
            0x0384B0B092653065ULL, 0x56F8EA94C18262C2ULL, 0x8750A922CA632373ULL, 0x48DD9F6ECFFE5ED8ULL, 
            0xCD23014D1C6A6FC5ULL, 0x901B43350615C5E6ULL, 0x5F75ADB3464CB0E3ULL, 0x551CF1918472F390ULL, 
            0xA38A77BED40D9C1AULL, 0x942C2B9CAD0EDF33ULL, 0xC260A76B756D8980ULL, 0xB1C33BC58D7D006DULL, 
            0x4C58A81B9AAAEC60ULL, 0x3B69160E3A7D4BBEULL, 0x4FDAF1CBA04F3740ULL, 0xB28068CAA32217A9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseAConstants = {
    0x96B088A79DAD5443ULL,
    0xD4929DA6948D776EULL,
    0x16F11C2968CD7A63ULL,
    0x96B088A79DAD5443ULL,
    0xD4929DA6948D776EULL,
    0x16F11C2968CD7A63ULL,
    0x43C6168B42CE3883ULL,
    0xC70BEBEC9DAD9732ULL,
    0xBA,
    0xCB,
    0x4F,
    0x9F,
    0x1D,
    0xE3,
    0x63,
    0xE0
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseBSalts = {
    {
        {
            0x624CF497B0E61D5CULL, 0xBA93E7272581D6D4ULL, 0x6750DA7B06152543ULL, 0x6CAD42EDE0F9ACC0ULL, 
            0x449E02F00A237CC1ULL, 0xA4181A6AB65DE9F5ULL, 0xC0D9F09234E05A80ULL, 0x572B341F60142790ULL, 
            0x720D1C04617D7E8DULL, 0x49C7E1A53140501CULL, 0x8DB9F05C1448FE4FULL, 0xB038FDBA34967D8BULL, 
            0x0159083453F3D039ULL, 0x80E564E35A07330AULL, 0xF664B871CC4B6C56ULL, 0xCE9CBD0F430A835CULL, 
            0xC9EBAF71EB59853CULL, 0xCB5D4F374F90E26DULL, 0xB394272FF67B1CC1ULL, 0x1FA5DCB105A34A9DULL, 
            0x8E34E679B8BCF059ULL, 0x3C28FD9CFD3B09C0ULL, 0xC92781B4D630CAE7ULL, 0xE033E0E5DE475699ULL, 
            0x97A68BB14E2744F4ULL, 0xC25D168641BA527FULL, 0x85A83E15F4808965ULL, 0x420BB8808E299803ULL, 
            0x539CE2BA6EEAF840ULL, 0xE35916150D378FF8ULL, 0xFD8D80A752BC7008ULL, 0x6E1D6236E0B999F9ULL
        },
        {
            0x9F8911EFED4032C3ULL, 0x0B3DFDE51DE25AE9ULL, 0xC0999A92BF421A9AULL, 0x6292CE67CDC5D9C5ULL, 
            0x4577D1B84E8D9E3DULL, 0xD011124DB310C5D7ULL, 0x6D8323DB04FBB2A1ULL, 0x16C37868887E12FDULL, 
            0x39D6EA2E3FE49116ULL, 0xC580281EA4512C0AULL, 0xD8AB9993135FEE61ULL, 0x57FE4D378233F505ULL, 
            0x35478C844DC1FF4AULL, 0x8E10E25C69DCE026ULL, 0xA519860F6B90BD76ULL, 0x5B22D669BB155268ULL, 
            0xB6891346FCF22813ULL, 0x343E28D85E01E7F7ULL, 0x11B21B8AE68D2D81ULL, 0xB1BB50DA49A94E75ULL, 
            0xDECAB9CC04424194ULL, 0xBE7C3411D64D5E0CULL, 0x746670E939F533F3ULL, 0x4832CAA94CBFC07CULL, 
            0xA8555DA87C0CB5F5ULL, 0xB819675E73B0DF98ULL, 0x383400DDEE4494D4ULL, 0x4BA7092F12C223CBULL, 
            0xA983CB6355BAE553ULL, 0x09043D76CA1B594AULL, 0x95BC34CDBB4679AAULL, 0x693ED4E15F538215ULL
        },
        {
            0x9099B3920E94A9F9ULL, 0xA64A5CF45CB6E025ULL, 0x9BF009E0A4346939ULL, 0x80CD77ED7791B58FULL, 
            0x9889DEA008A5F80EULL, 0x4663C7883510CFE7ULL, 0xF645371ED29FA899ULL, 0x8C8B17F668029A4EULL, 
            0xC5B097F1215817FFULL, 0x54DAC908482FC36AULL, 0xE5C64DD6A4FF3C4DULL, 0x676B340A16B4328AULL, 
            0x6DE1FF516612558FULL, 0xDF26CB5CD349771BULL, 0xD67CA5E57148ABE2ULL, 0xCC79CA2A9B887333ULL, 
            0xB81BAA5DA99D5CECULL, 0x50415C36625866C5ULL, 0xE4B67D4C6CA6B584ULL, 0x0450AEFC55BE219BULL, 
            0xF190AB89DC0BE50FULL, 0x33BCE954929FF7C9ULL, 0x8E062ED9884C62A7ULL, 0xE6EAF7EE3048CF7FULL, 
            0x9D013A7A753D8EC6ULL, 0x9F054140729F9734ULL, 0x5ABE2EBEB069AC4EULL, 0xBC937E41179F7611ULL, 
            0x2CA6C8E99C46DECAULL, 0x2B407A3A3BBDDB4AULL, 0xF6F503EE0DF37DE4ULL, 0xE4AF8F4E0455F8A0ULL
        },
        {
            0xE6AD74946206A26CULL, 0x98717772068A2211ULL, 0x5947DCCECEEBCD7CULL, 0x832DAD6F72E8976EULL, 
            0xAF78E30ECEA57978ULL, 0x492AB396890A533EULL, 0x0D687EBCF0183120ULL, 0x81FC739B35BE8902ULL, 
            0xDC752AF78F94AA4DULL, 0x5B52B47C006657BAULL, 0x5CDF99C80EABA6A7ULL, 0x91C1444D1BEF3518ULL, 
            0x47D9503BBF386CEEULL, 0x5D77785464E75A28ULL, 0xD6101ADFEB6A0F87ULL, 0xA4ED810B3CA01DA2ULL, 
            0x42C46B7CF0ABDE90ULL, 0xE4AF6195BCB37ED5ULL, 0xC5D407B8F59040A1ULL, 0xD1F517D5B33B1A95ULL, 
            0x0EB99F39DCCA2736ULL, 0x13413577E8DA949BULL, 0xF68B402FFB9817B7ULL, 0x379B65B51E73E82BULL, 
            0xB32368921A153874ULL, 0xDF6AC34E90D88687ULL, 0x9C11BD20FB63D437ULL, 0xE981E250DD2C7285ULL, 
            0x9D802F7493762AF7ULL, 0x6B16D1848A044690ULL, 0x16F81081E99B3686ULL, 0xD237D91C31B25E58ULL
        },
        {
            0xE87AD6514DCFEE34ULL, 0x355403A77967F5C3ULL, 0xD4F7B869E3898B99ULL, 0x10FD56A38F8766C6ULL, 
            0xEF081D60DBACFC97ULL, 0xA424700544CD5D9BULL, 0x3F6C910C7F1D0D44ULL, 0x81AE3E297A98C65CULL, 
            0x4DF7DFD4342565B7ULL, 0xACC0081C75B61D7FULL, 0x37595044847437F2ULL, 0xA9E6EC6478D4CD11ULL, 
            0x5F26D561B9529A33ULL, 0x1F097EAFBAE70F78ULL, 0x8C0A396B197EDC99ULL, 0xE376BA3143C31820ULL, 
            0xA29CEBC8C492EF07ULL, 0x8E6C0A8AA5EC2D8BULL, 0xF462A87703DA8F59ULL, 0x19BD5DD4236065A3ULL, 
            0xC84F71AA7033F981ULL, 0xD81EC6266CA2C4A6ULL, 0xB21F6A962B1103C0ULL, 0x66BBCBA5B9948BACULL, 
            0xC6CD8065045502AAULL, 0x3E3653CB399E4A9FULL, 0xF0D2125C15E10D95ULL, 0x20AEA6E6CC554D82ULL, 
            0x4FB112E52ECD7378ULL, 0x3D03FE21E301996CULL, 0x6D35AD1D1088B426ULL, 0x829E5FD480A1A6E3ULL
        },
        {
            0x1B45E8A6E359BE4FULL, 0xC5B172FEAFECDD7DULL, 0xBC7F001307CB2F39ULL, 0xF57F95B7F863E608ULL, 
            0xBD7E06C12F299705ULL, 0xB7579AD89AAFF119ULL, 0x3B850E1BAE1990F4ULL, 0x35339155C4304D09ULL, 
            0x34249508290EFC4DULL, 0x610C241008936710ULL, 0x6C277993410CA6E5ULL, 0xFDA399E2D594FBA9ULL, 
            0x42911E2A7E16801EULL, 0x5A50E98EF5CBE53AULL, 0x11F831DBA1D13D77ULL, 0x4050B969889DF638ULL, 
            0x20571B37471B42D8ULL, 0x39506E120AB8BBBDULL, 0x3C2C4D21A72C83C6ULL, 0xA8DF1BC5D85C64B1ULL, 
            0x2A099E13B92D8BF7ULL, 0x6B103203789A37FAULL, 0x6DC827A6461579FBULL, 0xD3929053D1A5AAD1ULL, 
            0x784E0497EF1EB415ULL, 0x277B518CC2D5127CULL, 0xBB4A4E321F8A5055ULL, 0x005C6D00413B45E9ULL, 
            0x5906E5EA3BC37133ULL, 0x639ADD506FA7B365ULL, 0x18A6A2EEE5CC857EULL, 0x7286C0AAC18BB79DULL
        }
    },
    {
        {
            0x3E68526689A067E8ULL, 0x815F2A2C60630B53ULL, 0x23F3EFAC44BA313DULL, 0x5798A673A1656DABULL, 
            0x5679627CDF7C11BCULL, 0xF6514621030B4EA0ULL, 0x3BAB33BAA3ADF51BULL, 0x6BA2A81B474C6CEEULL, 
            0x75DFFC777DA07259ULL, 0x0628D71FBEF9909AULL, 0x7E1949BB1C687C2EULL, 0x84C942F1930E9720ULL, 
            0x2C327E2C26DFD8A7ULL, 0xAFC4BF6E73EAE125ULL, 0x8297DD288539CCEEULL, 0x93EA2F992E3424F3ULL, 
            0x176D7AD137A9E238ULL, 0xE1792432365F7898ULL, 0xA8337BB7447C24D3ULL, 0x248BDAB3F3B13FA4ULL, 
            0x0A33DAC492EEEA5EULL, 0xB77953766D684F4AULL, 0x4E750D16DEA3D2B5ULL, 0xDA6774CEABA94C38ULL, 
            0x30F20DE65B106B99ULL, 0x2BACBF0C3B085132ULL, 0xA46BC19F1E2AF107ULL, 0x13899AE735606FF4ULL, 
            0x08DDA24F03CDA2C4ULL, 0x449C91D72806E955ULL, 0x5965081EA3F50EE5ULL, 0x44A26AE839FA22C1ULL
        },
        {
            0x472C09431724B6CDULL, 0x9D7FDCF4C8FA2957ULL, 0x541FFF5BDD0E9F50ULL, 0x833373C254233F88ULL, 
            0x5CB00FBDDA128508ULL, 0x1BACE4CFD89B4A6FULL, 0x2BF31790DAF75A96ULL, 0xF23206D5A0F4B9BCULL, 
            0x6AAFB96325659E3CULL, 0xD0068AA51B0ACFA9ULL, 0x71E888D0FD5585DCULL, 0x1F0949EB27BE4B4FULL, 
            0xE418896B83A0449FULL, 0x3E51EC94EE0DADE6ULL, 0xA1062E2BE9BF04D7ULL, 0xA01778C4928BB75FULL, 
            0x7F30D46C6D58874FULL, 0x5A73F821034148A4ULL, 0x9EF32EDD54531044ULL, 0xE7E4F2020C590163ULL, 
            0x642055B92DDE5688ULL, 0x7EB3A5D51984777DULL, 0x4090725E2FE8CEC2ULL, 0x035F9F5269DD1888ULL, 
            0x86512403E92163F5ULL, 0xCB06B22B76911881ULL, 0x1F5A2E574AEC92ACULL, 0x486C54F6BE7C8FCCULL, 
            0x5E6E515059AF9D61ULL, 0x2DDFB63732B69D12ULL, 0x31E702E7BA6CC9A6ULL, 0x527BCBF67EFEBFD7ULL
        },
        {
            0x4129A2AEE0AF0C12ULL, 0xA85503894F980F86ULL, 0xDE2CA9FF96E2BC90ULL, 0x2B5149447FD4454CULL, 
            0xB6B0BA2799FFD0C9ULL, 0x58C1DDFE9866AD1DULL, 0xE9C18C4F262EBE98ULL, 0x38093ACDADFDCB53ULL, 
            0xFC643EA5382E5FB7ULL, 0x6D8D648DDA7A1D07ULL, 0x5DD1AB945CC715B7ULL, 0x1CA08A699AF01381ULL, 
            0xA7FAEC4CE5514510ULL, 0x31EEFC5CD184BB76ULL, 0x5F7E5724FD0589C5ULL, 0x14F51A84F2696809ULL, 
            0xCD42F0E3AB4B25FCULL, 0x4731B58DE2B6CBD8ULL, 0xFAEFDF1DECB8175FULL, 0x30DDDAB49CE23634ULL, 
            0x06FFE9B11DA12ACFULL, 0xCD4C79BF8F974A6FULL, 0x0D49629D384C465CULL, 0x54BDD0E376BB5A04ULL, 
            0xF885753511D6DE44ULL, 0x8853A7622B33FC5AULL, 0xE18F4BCF59EA60F9ULL, 0x56E96EF1C8D3E127ULL, 
            0xF8984FADDCFDF4A1ULL, 0x43C7B9C1B8C1545CULL, 0xE69905B4A33BB63FULL, 0xE3D3ADA423E5E196ULL
        },
        {
            0x0D52E0839FFE648BULL, 0xBA891503D9EF7E01ULL, 0x6C46575B09DE744EULL, 0x183551176BD45778ULL, 
            0x0529F7E07D372E55ULL, 0xBB33147E079E6B38ULL, 0xEA79182A314E37F0ULL, 0xE906D1A6795C624CULL, 
            0xA75801B4A6B77751ULL, 0x522D9682B6666A6BULL, 0x8D0FD4EF3DC09CA5ULL, 0x10537BE89DE06C7BULL, 
            0x4BCD524D24681773ULL, 0xAC193996CF5D4228ULL, 0x0434AB0884E4E3D6ULL, 0x2A1B32B2D001245EULL, 
            0x37FAC278EF3B1ED1ULL, 0xA2954E84A9AB6CC7ULL, 0x7FF2568487047FB2ULL, 0x7F08B1D774BAAB85ULL, 
            0xF7186C1DE1F5D479ULL, 0x91D379650E7476B1ULL, 0x803A46FFCD73B584ULL, 0x8A4303AF3917FF13ULL, 
            0x30E3BB1E199FF995ULL, 0x392CF693B83ECBB0ULL, 0x79D05C853E1C90ABULL, 0x2E0CEE9040533D68ULL, 
            0x66097C37B52F7B9FULL, 0x0046AF20FB3C3766ULL, 0x218266DC02723F29ULL, 0x0ECC6BEA45712D14ULL
        },
        {
            0x2197492DB4439C33ULL, 0xADC606D5C1F6A9CEULL, 0x12576D59A8A86AA3ULL, 0x9F6A20A9B9CF028EULL, 
            0x3FD986B16EC1AAF1ULL, 0xAADAA043A53EC650ULL, 0xC084C5AADAACF697ULL, 0xE44BF377E3E5B209ULL, 
            0xFFCD6C6DEACD81A5ULL, 0x1E177F62A128BC74ULL, 0xB683502FCA8C67E2ULL, 0x481CDDDF914F28A3ULL, 
            0x7C7F6AB90D3C8836ULL, 0xC0496638824F6F39ULL, 0x54E5512E63A0D163ULL, 0x5925346EBBB21918ULL, 
            0x32A0E34A59B5C248ULL, 0xA3023423DA6E38F9ULL, 0x5C814E0D09DB1DA7ULL, 0x96A1C47B6CBE8ADFULL, 
            0xE6E1045436B2E241ULL, 0x42C76264AD80A7FFULL, 0xD3518E50827F9132ULL, 0xB120FEC3761F0446ULL, 
            0xE9852B729CD4E6FAULL, 0x3F9D822D2F29B129ULL, 0x23BA7D2E8EBF59D3ULL, 0x4E8F3FAE447E1450ULL, 
            0x6261BCA44D859AB4ULL, 0xE566BA2B0B85F0C5ULL, 0xCABD52F638009E2AULL, 0xC0036CEE7DE334B0ULL
        },
        {
            0x4D81E2E245A94249ULL, 0xE7BEDBDE937AFAD2ULL, 0x6844FB5768FA263CULL, 0xEDDD05716272915AULL, 
            0xAE5E66A0605E48B3ULL, 0x88B76D4969020C25ULL, 0xE0CFE178CE0AAA36ULL, 0x36DF324C396A40E5ULL, 
            0x3573E8549760160AULL, 0x4F7033CDEECE31C6ULL, 0x1863FBBEE98EB74CULL, 0xD2EAD9822377431DULL, 
            0x6DCA6BBACED03976ULL, 0x539F26252EAB3A28ULL, 0x9DA9FA484CF29482ULL, 0x5C622F0ED0FFCC33ULL, 
            0x01C6B42C6B81284EULL, 0x84465D4B85027449ULL, 0x7D31F0AF429CAD48ULL, 0x1A86D9F14A907800ULL, 
            0xB2ACE3A81FEDA0C2ULL, 0xD71CD5DA099E961BULL, 0xBB7BB3AAB666F100ULL, 0x15D954331FB17BB5ULL, 
            0xC251A370389170D3ULL, 0x3E6AE84D34F4FA67ULL, 0xAB498769A74DDCD6ULL, 0xEEECE0C320EAFE2DULL, 
            0x830C9CB6A4803B1AULL, 0x51A18FA466C89938ULL, 0xC96EE81E30029BB5ULL, 0xF6B6B5BADD754E8BULL
        }
    },
    {
        {
            0x59025989DAC3C794ULL, 0xD4E323DD9E4E68A8ULL, 0x03847FBB63920082ULL, 0x74158738D8629E01ULL, 
            0x269B3489DEF1FE3AULL, 0x5A6CA448AC439FD1ULL, 0xCDD26CF368997BC2ULL, 0x9ECE1DFEA84AD2E2ULL, 
            0xB0F286A4D2D2E8C3ULL, 0x3446070C94F2AE34ULL, 0x317FCB272479C4BBULL, 0x899B1B233B428790ULL, 
            0xD260DB4B3C95C725ULL, 0x380A317D3456F9A3ULL, 0x386FA27214C387CBULL, 0xA0B5CAE8E93DB0D5ULL, 
            0xE535EBE514F59184ULL, 0xCE9D98394A91D212ULL, 0x42EEDAA872218DB9ULL, 0x80CB20D3BBD7360FULL, 
            0x02E9F0690BFBB944ULL, 0xAE3F1CCEE65EACC5ULL, 0x3D6EFA6AEC8BAE9AULL, 0xEF448FFF0DEA7B59ULL, 
            0xEF82BD346EE9387DULL, 0xF84D8AAEB29CFB25ULL, 0x07B01C16FACA90C6ULL, 0x6DADDCB58992F5D8ULL, 
            0x73000FC215DFD426ULL, 0x038D0D4B149787BDULL, 0x3427EDD47B1E017CULL, 0x2376E1E62A16A9ECULL
        },
        {
            0x6EF072F544B3F6B8ULL, 0xFE824121F8158639ULL, 0xF6987039B31717C6ULL, 0x796BBEB70880E5ADULL, 
            0x1081FE0F90CDED3BULL, 0xA04CC5D8B8729C5CULL, 0x65A2C6524C6E7A7FULL, 0x9C265535D711EA0EULL, 
            0x71F22C3ECD060B4AULL, 0xEE88E8F304C1AC5FULL, 0x21502B0AC4873E71ULL, 0xA6B82A878BC14387ULL, 
            0xEB16FF295CAF8277ULL, 0xFBD6FE08D3A4182FULL, 0x6C4AF5DEE6B47689ULL, 0x3B4E4410DF57A1F3ULL, 
            0x0967D5912E61CD08ULL, 0x8E123939C964D062ULL, 0xC16A6121B6AE0B6AULL, 0xFBE0932A9E0441EFULL, 
            0x993205A57C552C77ULL, 0x1170A813C5C21986ULL, 0x283E4175F3E0EBEAULL, 0xA83622C5FD1A7667ULL, 
            0xAE73209DCB301391ULL, 0xA81C675A8AACD03AULL, 0xCD8F8674E132A3C5ULL, 0xD77B567C02CAEE6CULL, 
            0xA51F111EC5B4760CULL, 0xE151C8B9DDA41BA7ULL, 0x55010D61D88DA710ULL, 0xE92DE7C04EC530A0ULL
        },
        {
            0x14B250592CD0B15AULL, 0x15C21480A81A711BULL, 0x20D76F0B8EC26C8BULL, 0x3840072D85628AFFULL, 
            0x159433071E526186ULL, 0x1921B66124621127ULL, 0x4AEF3F2BC37EDE0BULL, 0xCEDDCB3BADB951AFULL, 
            0x83EE098BCE10D95EULL, 0x59DF5880A971C8AEULL, 0xD3649A7DAE9E891BULL, 0x988B6DEB10BE9EA3ULL, 
            0x7DF689ACFA0BF44EULL, 0x94B05E4DE0747E8DULL, 0x1DCFCCB632E8F875ULL, 0x3BDC9B3703DA9345ULL, 
            0xFD2B47007624AA14ULL, 0x74FC53B92015B7C2ULL, 0x96C912CF70E6956DULL, 0xB4BAEF7935AC24DFULL, 
            0xB07B9CD84CFB72D6ULL, 0x39AFCFF8D4EB3B02ULL, 0x73BFFF2DEE1DC6CEULL, 0x59F806035C868407ULL, 
            0xF31916A0BDAA3AE2ULL, 0x1680260177FE3B13ULL, 0xF54A03CCFBCAB2C1ULL, 0x67E61B41556E0EB9ULL, 
            0x37858747B763DA3DULL, 0x1D70D18B22A44A22ULL, 0xB98B9B60839F1CD7ULL, 0xA7FBDB9FBB45DDD4ULL
        },
        {
            0x93A0B2108CCC5607ULL, 0xCAFF365BC20CBE24ULL, 0x1A1A9B7263A75799ULL, 0x67B4E4FEFA500C9BULL, 
            0xB3BB5CEEB101E5BAULL, 0xB7A4A1AE637B9C24ULL, 0x1D1D498F8EEF1FC0ULL, 0x2F2D8E8B8AB408E4ULL, 
            0x9FDC1F2308A1CED2ULL, 0xDDAB83B091D22527ULL, 0x5D5E63668190F066ULL, 0xE2C0910E75652DE4ULL, 
            0x64656CCCA6E02C8EULL, 0x3A735F6549FE88F4ULL, 0x6A10532DC7166B9CULL, 0xB53E422A6D793E9CULL, 
            0x966FEF31D015E8C6ULL, 0x27A1D960A6140B9FULL, 0xE7140AE3B5CE5C22ULL, 0x3CB99758671A66D6ULL, 
            0x6C6F477970E146D6ULL, 0xB2D1447F1510754AULL, 0xD0DF74A628E385C8ULL, 0xAE290AE2FFF165E8ULL, 
            0xE539ED08077AD998ULL, 0xAA6BDC440C27F294ULL, 0xFCC2F021C002A8A9ULL, 0xCB77E94761C333E3ULL, 
            0x809FB9FBDF7EAA1AULL, 0x424E02DD1AAE5919ULL, 0x2A6BE84E8C15DC42ULL, 0xFA05FC5C37F1E4E9ULL
        },
        {
            0x79505FDCCE2C8EDBULL, 0x8B6D76DB5B30437BULL, 0x46009C75C0232E3EULL, 0x7F820AEF762A617CULL, 
            0x1A42C3E630920977ULL, 0xE33D13E9FD25360CULL, 0xADC4C08EDB9397EDULL, 0x68BD477F50997DBFULL, 
            0x9DCAEE348405915AULL, 0x1593E278867EBE1BULL, 0x62AC0B137042A7B4ULL, 0xD18B143A63DA6C61ULL, 
            0x9F16048256EFCA4FULL, 0xFE85D2782C375A5AULL, 0xF80D47D1A94B30B1ULL, 0x6A3FAFE00072C43DULL, 
            0x2AB2116A82F02D24ULL, 0x6D473DB047BDDA50ULL, 0x8AC0A6E5DA3D486DULL, 0xEBAD5C3219C6AFA3ULL, 
            0x965E732658477400ULL, 0x6C5E3456D671FFB8ULL, 0x20141E8BA2009380ULL, 0x032E6034EEC53D5EULL, 
            0x8FB61BCB383B263CULL, 0x81014EC855BC2C16ULL, 0x96D9C8EA91BD819EULL, 0xD1638FF8138C81DDULL, 
            0xC7BA975B7C1FCA53ULL, 0xEAD98308F6C13A50ULL, 0x31875C8DFDD34A4EULL, 0x643623C5CA9B52A8ULL
        },
        {
            0x175DEAF28E9C243DULL, 0xFF6A5FACE682E423ULL, 0x4F216A1539F08CF0ULL, 0xF1A258506B0E2664ULL, 
            0x5A52F0BAE996F035ULL, 0xCA5870215B505FBDULL, 0x8125ED1569B98358ULL, 0x0B9F20FA8497560DULL, 
            0x893FCFAC058F7DB2ULL, 0xC7C783BBE3CDB7C9ULL, 0xCAA7570FF54E58B9ULL, 0xF9571305C40CD8E2ULL, 
            0x11F7231EA5265521ULL, 0x828AA05AFF72962BULL, 0x51AED592AF24C46FULL, 0x5B40FE3423A9232BULL, 
            0x8C317798F37722DCULL, 0xCE684110CBFECA42ULL, 0x5817853A15768B08ULL, 0x3658A03BEF1A0D41ULL, 
            0xB2B4E5ECD24182AAULL, 0xC296E0F56443E090ULL, 0x634D522D5327FCDBULL, 0x20B7B6FD18AA89E5ULL, 
            0xAB6E7CE466E31335ULL, 0xD61D55ABEE5E5C3FULL, 0x85B83C986C84AF5FULL, 0xFAFEEDB88B51837AULL, 
            0x1AF08309C33B3E74ULL, 0xAF64897AD2919E3AULL, 0xADC5DAB4D910836EULL, 0xA36B1D51530AC887ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseBConstants = {
    0x420E6C07E13711F6ULL,
    0x0F0AA4E7CEAF4BE0ULL,
    0x9549DF9CBA8D021EULL,
    0x420E6C07E13711F6ULL,
    0x0F0AA4E7CEAF4BE0ULL,
    0x9549DF9CBA8D021EULL,
    0x59E69992A6833B7EULL,
    0x864E1740B292D3B7ULL,
    0x25,
    0x65,
    0x7A,
    0xBE,
    0x1A,
    0x4F,
    0xCE,
    0x45
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseCSalts = {
    {
        {
            0x24102B5F8DC1C3CDULL, 0x509DC9B3C827F9A9ULL, 0x41E0CB6662CDEA9DULL, 0x79E68B43799A0593ULL, 
            0xB734C2CD543999F9ULL, 0xF5D2B2DF98481879ULL, 0x77B0617F44FF1AC9ULL, 0xE225AA3349FB2B42ULL, 
            0x25B03664B1FB3C51ULL, 0x93A2CE21F27966BDULL, 0x2F42E95DC0B5685BULL, 0xC6B60003ED189898ULL, 
            0xA9C006527DC84A83ULL, 0x5E578449A0191CDEULL, 0xD9ECEEBC89892C6CULL, 0x889E13A1C75A7EBDULL, 
            0x1E000090B5C7F220ULL, 0x863605F6E44EC4C8ULL, 0x0B15013D6EC54977ULL, 0xA6019AA9508B9127ULL, 
            0xE403FB7C0F73E1FBULL, 0x58F9BE5A94386C22ULL, 0xB55457D0F85287F3ULL, 0x8778F7CBAE246668ULL, 
            0xDB54B0278F255CCEULL, 0x0D99475740BA800BULL, 0x14815049BF216B51ULL, 0xAAD0BD43034844DEULL, 
            0x227E638DF1FECB62ULL, 0xF0720EAD10D10013ULL, 0x01FFC1BBB640D5F6ULL, 0xC1FBA24F7F078A2EULL
        },
        {
            0x87DAF74D12626B4DULL, 0xEB4DA3BCD989FABEULL, 0x81D4DDD9EA45F5A6ULL, 0x189E7AC68AE42907ULL, 
            0xADA21C8FB5566115ULL, 0x40C182670A34F480ULL, 0x86DF8DD8C3FF1EA6ULL, 0x400E0D4823E8885AULL, 
            0xBDCA18C3D234F9E6ULL, 0x74966DDEE19A9440ULL, 0x633118A7690DFD5FULL, 0xDEF3EE54950A0522ULL, 
            0xBD29F4ECD14DD37BULL, 0x9996FFB5A8CC5633ULL, 0x9BC27B40A5D993A6ULL, 0xEF79C591DA1FC031ULL, 
            0xE7E95EBBACBC127EULL, 0xE87C8F57AEED9E45ULL, 0xE543742A4622E8F4ULL, 0x2E4933828D36F45CULL, 
            0xFC75DD94261A02F2ULL, 0x5D6AF5B8B48C4EB1ULL, 0x490FEF8E11BE74A4ULL, 0xF29237DB79797533ULL, 
            0x304122D04C46FA48ULL, 0xD5C733029B3DDFC4ULL, 0x6B54F26A3B865CE3ULL, 0x8DAA560DB3BFEC48ULL, 
            0x3486D1D3E5C6D044ULL, 0xEEA5D062A484B04AULL, 0x6FF5DA7C79A67C1EULL, 0x0638CE61C77FD251ULL
        },
        {
            0x5D279EDABF51219AULL, 0x73FCD0CCE39E6F3EULL, 0x6C7CA8A7C0BB79D5ULL, 0x125A5E7E2DE58B3EULL, 
            0xE1238D2D1B56E7E9ULL, 0x6B01025C80309B49ULL, 0x2EAC9EBD3359FB2FULL, 0x232D16C654BBFD31ULL, 
            0x6F3681442E0ED303ULL, 0x39057E7E953A1D3BULL, 0xF3D8FF715DD5AC62ULL, 0xD5F7E218175E96C2ULL, 
            0x4BA5C53F8D9B1186ULL, 0x2D86D186A6A0E542ULL, 0x8636A99FED8A3E59ULL, 0xC65252CEFF62E9FAULL, 
            0xDA5A93DB691FE5ECULL, 0xB3C70AAE275E4821ULL, 0x1843C271CC10930EULL, 0x5DAEEB0B6CB37E47ULL, 
            0x5517467AEEB632A9ULL, 0x5B8F6C07B67A629AULL, 0xD8B3B85DE761E3A0ULL, 0xEE3334F9EFB9D33CULL, 
            0x95BA8018B99AE9E5ULL, 0xBEB6D1C128B5C018ULL, 0xC022ED7B74D94C1CULL, 0xF2D83A33A88CC83EULL, 
            0xDBE786D2F3F18FDFULL, 0x06278C4CEC096497ULL, 0x9335EA1FF3288710ULL, 0xAAAB30298177B8F2ULL
        },
        {
            0x71741C874CF7CA3DULL, 0xF8FBD98AC3594731ULL, 0xFF733D4C1549A03EULL, 0x188E26BB067AD2AEULL, 
            0x31FEA4E475B368AFULL, 0x69082AB4933288EAULL, 0xEA88A68194196B26ULL, 0xE24F91BC767E3BDCULL, 
            0x8F41094813F3D0FCULL, 0x870BA0746B7A373EULL, 0x4F624B62D4EC49BBULL, 0x66F9A39712EF2A83ULL, 
            0x7B6D4261CEE70C23ULL, 0x5044EDEB954013AFULL, 0x49B7F47E969AD0BEULL, 0x6F0D58EE02CC61ECULL, 
            0xE11DD44C435FCE08ULL, 0x44ABE2165AF0BD55ULL, 0xA784C0A523463A02ULL, 0x9FD093F38457C13FULL, 
            0x62E854EE46BAEE07ULL, 0x477A330EC695A4A6ULL, 0xFC0EA55CAB1076B1ULL, 0xD1072549CF57729BULL, 
            0xE6568186595D9EB4ULL, 0xA44FD099C5276384ULL, 0x794013D5F61DE5AEULL, 0x9416104009818E8CULL, 
            0x173D88AA3C848D59ULL, 0x3CBC833ABF4945FAULL, 0x163F339CD65042BEULL, 0x4F9115DB906BF9C1ULL
        },
        {
            0xC5966FF2CB660673ULL, 0x637E3A94CD6FC67AULL, 0xF852B59B5C04E114ULL, 0x06EA7E030E33B5A7ULL, 
            0x0810A97228097256ULL, 0x6A5C58CA67C2CDEFULL, 0x8DB900C65D88E7A4ULL, 0x5542364D44A2CF3AULL, 
            0x66CF92BE15BA19F4ULL, 0x722D2A62C80B456FULL, 0xF1AE534CDAA69E08ULL, 0xFCC57964D5204986ULL, 
            0x3965DEADCC832B45ULL, 0xCC302A0866544476ULL, 0x3FA2EDF7F0188CD6ULL, 0x89D34D3183C8B733ULL, 
            0x5DF0ED736A6EBE70ULL, 0x1435D18A4525B122ULL, 0x296E1087346E986EULL, 0x96A45786DF438F20ULL, 
            0x6A0355C4AA16C7A8ULL, 0x97EBD931A0D26140ULL, 0x1958497CAC95BB8DULL, 0xA18C6E0E1F11CE7EULL, 
            0xB20B6590A87CA2FDULL, 0x5B60D9BAA25ED72DULL, 0x234AC1558660D831ULL, 0x5174DABDF816C8B8ULL, 
            0x43CBB5F4D4949C4AULL, 0x83649D7A8ED0A4ACULL, 0xC45D19CFD5FD88D6ULL, 0xFEDAF573B2F9B82DULL
        },
        {
            0xDCFFF4A83A7BD0B1ULL, 0x140A52F5E59161FAULL, 0xA3DAAD7004CAD45AULL, 0xE9A2E9FBBD8B4781ULL, 
            0x14E713459F55EFC3ULL, 0x95111BEED2C3C28CULL, 0x8549C21B92789101ULL, 0x9BB84FEC442BF444ULL, 
            0x6B116BC363315809ULL, 0xC56C24FB1FA470C6ULL, 0x467EACD5173C9D28ULL, 0xDB4537A7EE2901E0ULL, 
            0x2156CBFBEA804E9CULL, 0xF4B0FBA4821A6F4AULL, 0x0D964F60422E7887ULL, 0xEC774C60D357CBBDULL, 
            0x24B09AFEB686253CULL, 0xDF51F007D8AD99BEULL, 0x74F383FA4A291874ULL, 0x21A42064D666F7C7ULL, 
            0xB4F8816AD1211187ULL, 0x34E84EE2978094B3ULL, 0xE2EA5E79703A5A8CULL, 0x52B0387F82EE3ACEULL, 
            0xC9596BAE48BE4FCFULL, 0x9CD553536CED6ED2ULL, 0xC06140C4B27C7172ULL, 0x70013A3F35397249ULL, 
            0xB185C58259D76E9CULL, 0x03DC274CF152DE3CULL, 0xCC600E3E42D85CA3ULL, 0x02B0CA97509B6A32ULL
        }
    },
    {
        {
            0xBDFC12E37BA81DB9ULL, 0x4D929769CD75A0C2ULL, 0xBF083FA1A59A1607ULL, 0x0D1107A11E551FD5ULL, 
            0xB579492C0B3E0FE2ULL, 0xE196C9D9D39ED3C1ULL, 0x6DA098FB971A2457ULL, 0x20460AACA1B09705ULL, 
            0xAF188A3B2BD90613ULL, 0x833C9B98FBF310C4ULL, 0x9D54EC445B0B60D0ULL, 0x9D119BCE04BD0789ULL, 
            0xF3CBF9BFAE67FB69ULL, 0xAFC9FCDA4D9F8D91ULL, 0x426F28D45E051933ULL, 0xA7BF0247AA54B4AAULL, 
            0xC29BA3DCD309F88FULL, 0x289B4362ECE00D53ULL, 0xF9CB57E78BE413E1ULL, 0x49DE88CC259C320DULL, 
            0xA399D064FC933114ULL, 0xC48772EFC8A38CF5ULL, 0x06E80F3C2ED74483ULL, 0x5D8834278B9C9402ULL, 
            0xF7E4C58387BED6A6ULL, 0xFF72C8CE951BB084ULL, 0x3FA86957C15CAC4AULL, 0xAC8355051D8A2A48ULL, 
            0x96AB7DFC5D80F414ULL, 0x4D57F2D2E28A6D97ULL, 0xD41A7ABBAC89170EULL, 0x3A42ACBADC6F610CULL
        },
        {
            0x1CC6C5C2A01B13F3ULL, 0x1C334B625F479294ULL, 0x2976DBABE2DFFDF6ULL, 0xB7D482FE339A0C9FULL, 
            0x77F4F6806288FF7EULL, 0xF7EB3E1C236B9F07ULL, 0xE9C8FFAF2D9A6AAFULL, 0x6AE6A2AF530533FCULL, 
            0xCB62CB5C0749277CULL, 0x7F787D96A3498EF1ULL, 0xA3367AA8A4EFADC5ULL, 0x995838BB341CE5E2ULL, 
            0x512FB02DE7F851D9ULL, 0xFD4A167FD55BB601ULL, 0x0BD470788C27B026ULL, 0x57F9DD505FB91EAAULL, 
            0x2076D0AAF6C88DD5ULL, 0x2A1A31EDE6DC0F24ULL, 0xBF149A3738F009DCULL, 0xD497B05D0617A69EULL, 
            0x63737DB8412CAEF5ULL, 0xB748D9F455D5589CULL, 0x525680129616767AULL, 0x09023EEDE80C463BULL, 
            0x5832C6907A2CA06FULL, 0x4B94FE422E8C150FULL, 0xD06C860973FD038FULL, 0x0037FA7B4CAFF653ULL, 
            0xD95F3E2E5D0FDDF2ULL, 0x80E0B0D937C19F43ULL, 0x90A844CF551744F5ULL, 0x500D700ABC312A72ULL
        },
        {
            0xD102C0D489D66866ULL, 0x5F3823F9C390696BULL, 0x03C4DEC95B18D540ULL, 0xF7689F4A998E0F91ULL, 
            0x98D89DBB0764D5BDULL, 0x2A2DC08F24925BD9ULL, 0x384FF18D6DD34341ULL, 0xE9527102C4773A6EULL, 
            0x15990688DAE3BFCEULL, 0x9B7CB8606F658B9DULL, 0x06C07E9EBD96E25CULL, 0xAD86A795093A2633ULL, 
            0x6BC8104FFA29F6CEULL, 0x3924B1083659701FULL, 0x1C178A616224D9F3ULL, 0x72FD164FD7612327ULL, 
            0x2B60705283CD2FBDULL, 0xB5327293791D38F2ULL, 0x47BB9B186DB8F182ULL, 0xD15CEFE8627A9D0AULL, 
            0x96DFEFBF620C5A72ULL, 0x37B0F79D95C0E8E4ULL, 0xF57320C053E4AF48ULL, 0x6BBFED14D2C9C30CULL, 
            0xBC913EE3EE3C222AULL, 0x3EEACE044C00D4F9ULL, 0xCDEE6E5B3747D665ULL, 0xB7091537743FB220ULL, 
            0xEF55D63CB4A30A93ULL, 0x1103F75F25690011ULL, 0xA92E66BBC1397301ULL, 0x794B9D912C253468ULL
        },
        {
            0xDB5CE56AD987409FULL, 0x8A988C7B23AB25E2ULL, 0xC92B52C0A6F1408FULL, 0x65340DE98F0E819FULL, 
            0xC625C7447870118CULL, 0x23C4AD1DFB99ED39ULL, 0x3231B54B122E1350ULL, 0x6DBF3D944773F271ULL, 
            0xD9A8EE0EF63F5F00ULL, 0xD982D6F17FC80636ULL, 0xCB9954E0C1CF68E5ULL, 0x4528EF74BE22417AULL, 
            0x2902DE4557184DD4ULL, 0x1D0F327B23DAE889ULL, 0x5F3B1F3DB8DE6171ULL, 0x7D4A65B5023DF93DULL, 
            0x45C3DC2E00C5C687ULL, 0xBE46C0536A6DAFF4ULL, 0xBAD58F8B1717E2E9ULL, 0x0CE16C6B8618B519ULL, 
            0xD1F062D7DFE1AE47ULL, 0x7E774E7BB2CB11A6ULL, 0xEE1002DB96D015DFULL, 0x99802982F8AE2A14ULL, 
            0xECEFA56C4EFF3ADAULL, 0xFB0BB341B709391FULL, 0x8A25455BB5048E5FULL, 0xBB8D9C836CC3F6BEULL, 
            0x4C101ECC93371697ULL, 0xA2E2CEB417855EB9ULL, 0x1CFE16F9FE1BEC5CULL, 0x75CB450FA25F3BCCULL
        },
        {
            0x33088BA6BECCEB41ULL, 0x1A4D040E098CD83DULL, 0x0C8E6A078D5B0C9BULL, 0x0960B3D455DDDFD6ULL, 
            0x105AAACF54B7BEE8ULL, 0x38974B1E55A0A1A7ULL, 0x98F2B5FD359D23FCULL, 0xDE89BDC17E75AD48ULL, 
            0xEBA51253412A9460ULL, 0x134AE9FCFD90ABA7ULL, 0x4E9ED6B110AF787FULL, 0x1990FC305CFBE531ULL, 
            0x449E688B72B7C3AEULL, 0x6B4AACE816BD63A8ULL, 0xB086FE7BAB8AFE6DULL, 0xC47A5DC74C940162ULL, 
            0x1013F2E2073B8FBFULL, 0x3F6F9FC66B18D085ULL, 0xEED3701253262EB0ULL, 0x7C7C9DBF1EEF0061ULL, 
            0xA57EC7EFD0B1B33BULL, 0xF0233388DAB4C0BEULL, 0x02FB196818DFB69DULL, 0x691EB4F5ED648085ULL, 
            0x85B43B2F13CD5564ULL, 0x8CB121AA775BF349ULL, 0x57F003A1EA8AB2ADULL, 0x33BFD0805F61D64CULL, 
            0x9CB883281B942FB4ULL, 0x48B83F92179F41B2ULL, 0xD1A05B73144180D1ULL, 0xB023F0D491E3656DULL
        },
        {
            0x427E39D1202F5AB8ULL, 0x26106EAE8CCEACC3ULL, 0xBDB7FB1CD33B2437ULL, 0x240A1AC6E040EBDFULL, 
            0x81E67E3E407048C5ULL, 0x527CDBFB580533BFULL, 0x08714A236797DCA6ULL, 0xCC44E196660B2C7FULL, 
            0xEFE51D3A198C915FULL, 0x162C252B6E77D529ULL, 0x67A71E953679E8D1ULL, 0x85749D57C67335C0ULL, 
            0xC758EBCBCF36FF8FULL, 0x260AA79CE73A1EAAULL, 0x525872264F35305EULL, 0xAB0B909E73C95401ULL, 
            0x08E77341612603FAULL, 0x182ACDFA9295928BULL, 0x226EA6397BF1E989ULL, 0x22458A57499AAFB4ULL, 
            0x54038CCECB67A6CBULL, 0x3A9BAB401E61CF0AULL, 0x29BF2FAE4A97BCCCULL, 0x9F8399972AD074F7ULL, 
            0x4B6537BCA1AD0C18ULL, 0x5186BB2A19EE7553ULL, 0xCBF5D484DE1EF1E5ULL, 0xEA97F359D3CE2F3AULL, 
            0x0C1B1B1CFB0AB51FULL, 0x7813AF6A3C121A8CULL, 0x937677589C24FBC8ULL, 0xA3F1CD7465C9EA6FULL
        }
    },
    {
        {
            0x0EA9B6DF64A7500BULL, 0x485182F0F15AD6B8ULL, 0xEEB5B9EC9B411AAFULL, 0x5EF47D1F20BA7F57ULL, 
            0x1ADC8B44B00BBAC3ULL, 0xF4E4388D02D754A8ULL, 0xC1977F1D2F31B081ULL, 0x6DD892CA6D3D1A62ULL, 
            0xF57E44C92E5BF372ULL, 0xF22CB2465A664EAFULL, 0x93610E5AFA744245ULL, 0xBA19D21849C188E1ULL, 
            0x759E2EC99F4CDEAFULL, 0x889B93C5F42207C0ULL, 0x49A027FE4D74F1DBULL, 0xE42074C5B87339C9ULL, 
            0x514937D03BE7706EULL, 0x36DC2F061441ABDFULL, 0x7961C33DA7983903ULL, 0x38A0376F36D38655ULL, 
            0xD7C310693A9B23ACULL, 0x2839C881F6C9BDBCULL, 0xCE4595171CEAA57DULL, 0x9BE3999EEEE183B9ULL, 
            0xDE8F095CF9A4B6E2ULL, 0x2266EA0CFF406F0DULL, 0xFC82FF3DBEC0D588ULL, 0xBB98C5B1FDCA6A3EULL, 
            0x90F79218C6645475ULL, 0x7A7DC5974D876D8BULL, 0x3CAE4CD238016547ULL, 0xCD8ABF951E2818E0ULL
        },
        {
            0x0BEC764E92CE2520ULL, 0xDE7219C759B1DE9EULL, 0x2F32E4A858FDA62EULL, 0xB8B961A7A8D364C8ULL, 
            0x44CA364DE9B0CEF1ULL, 0x1A1F117317570416ULL, 0x3F92A758C41F92D6ULL, 0x4315FE84DC240B62ULL, 
            0x75AC25E10934C849ULL, 0xE7F316A92C9E9D3AULL, 0xA8836C8AF0B2B04BULL, 0x5542D220F81A6A9FULL, 
            0x20C7DF497DF8B5CFULL, 0x937D4DCD1FCFB8F8ULL, 0x966CA87BAD87C02DULL, 0x32F07D88BD7B4C48ULL, 
            0xC37CED9CE92A6886ULL, 0x466A9D4193B421F9ULL, 0x3EA46951994DE237ULL, 0x7F4D78C0AC0D7897ULL, 
            0x1EFB54C065558A5AULL, 0xD186C451AD098BEDULL, 0x70A5016D43E10A58ULL, 0xBC21EA8AF8959BA4ULL, 
            0xA7C5A01BFEF61F82ULL, 0x74223A21B9E091DAULL, 0x7FAE1563DADAE00AULL, 0xAA276F43DDA4C130ULL, 
            0xCCD42436C34A280FULL, 0xDACCF2FE64FAF61DULL, 0x9BCD630BF94044DCULL, 0x8A28B7A1CF35A3D1ULL
        },
        {
            0xCDA38F602841290BULL, 0x0BDB2F48F9C5B18AULL, 0x773F511B0549E0DDULL, 0x0F0D01CD8C6E9E0CULL, 
            0xA3D89AC0700C22F9ULL, 0x20A58590CDA1846AULL, 0x2BA1F513B5FB5D48ULL, 0xE296C931FDE8B1AAULL, 
            0x30E75CDB9A0C5A70ULL, 0x81CB54999028BEBAULL, 0x81D7F7C94C919268ULL, 0xB11AFCA25C94F160ULL, 
            0xB472EE3D832C92E1ULL, 0xBA485BB4AB1BD55FULL, 0xF13DAE0F1F43F6F0ULL, 0x553D3F8B3149D3AFULL, 
            0xF7117648A966F9F9ULL, 0x5E79C2D05772FF11ULL, 0x95C57C1F289AB73FULL, 0xFC1CABD616E483D2ULL, 
            0x8C644EF7CBFECEAAULL, 0x5D1665CA61D7C4BAULL, 0xA071BCA719EE3479ULL, 0xE5A2BD4AFED31DDEULL, 
            0xD6BC32A7FB0FF42DULL, 0x94F908F9DCF3FE0AULL, 0xC0D97F7F8DCBF8E7ULL, 0xCDFDE567228C1F59ULL, 
            0xDBC2AFB8B1DBD32DULL, 0x596344C566BFF151ULL, 0x6954BC21C5335DACULL, 0x2A759F789972E761ULL
        },
        {
            0x4DF538D727E28844ULL, 0x73AEE355A0DA3880ULL, 0x9DE2F3B50DE62797ULL, 0x84E24421D84D767BULL, 
            0xA2E02EFAA4915137ULL, 0xC3F624E3C596AD3DULL, 0x8E9C66370C09B96DULL, 0xAC011BFBAB610D1BULL, 
            0x8B6A6428F69F6B77ULL, 0x3BA7D4E134800893ULL, 0x8F5CF63B9D0BBAD4ULL, 0x07FBA1CF2A4F4D0FULL, 
            0x8D9E9901DF19CDCBULL, 0x6EE39A008B50DE71ULL, 0x9112694668F01FDCULL, 0x5D68B504C2571965ULL, 
            0x2543F443FB70209CULL, 0xD589AB9FFF8889A3ULL, 0xF26E9388D408E9A1ULL, 0x2A09C26FA2B537B5ULL, 
            0xF8CD680EAFBAE6F8ULL, 0x75AB9C33B857324DULL, 0x500B3BD5E22F8D61ULL, 0x70C9FEC87A73C92DULL, 
            0x381968A4153D6277ULL, 0x70C31EF3CEA34871ULL, 0xF500ED4F1C9E46B2ULL, 0x49C566A6F551D62CULL, 
            0x742FB384EAD138DBULL, 0xDD0C3FB28984222EULL, 0x71685C35578B1CAFULL, 0xD8CB97998081099CULL
        },
        {
            0x00A43B239711F5DBULL, 0x7AA278E206821DCEULL, 0x8328F37780509BD1ULL, 0x601F5B564EEC1128ULL, 
            0x3960904C8EEE8AA3ULL, 0xA746A441C3C3AC34ULL, 0x1E395BDFD6B20A89ULL, 0xF5A2E87DC50C8AA9ULL, 
            0x6C37DFAFDB7C3DC2ULL, 0xE55D1A4758DF72C0ULL, 0x3C9D815DFF3D5E01ULL, 0x461FAE1740ABB4DFULL, 
            0xC914D2218AD41747ULL, 0x08B6EE5332CE3F0AULL, 0x9DE46156030849B8ULL, 0x2BC048A09F27B6BAULL, 
            0xE3435DD4A8F53D75ULL, 0xC993C6E45C698F82ULL, 0x81CE84CEBFDAB88CULL, 0x1D1099A2A12B6F0FULL, 
            0xD3B574035853B155ULL, 0x6094289EEB5C5545ULL, 0x3813FE13732E5753ULL, 0x1AA33C73A73FD36CULL, 
            0xC9FD46A340F1B72FULL, 0xBE4FEEE4F79D1DCDULL, 0x86FEF0F8D2837829ULL, 0x153C01A4574A768EULL, 
            0x82474AEA29ADD140ULL, 0x4AE2674B6AF03430ULL, 0x23E677DB2C71EA22ULL, 0xE13F45A8876CA2E9ULL
        },
        {
            0x37DD5E8A504F87A9ULL, 0x2CE65857B135201AULL, 0x371942AD1323FD2FULL, 0xEBDF745BA00FE21FULL, 
            0x5AF703FAB947E658ULL, 0xA1BB5D496F5975DBULL, 0xBA56456AFFFB1E8DULL, 0x151546AAA4F4F2A6ULL, 
            0xCEFDFE25117F5A18ULL, 0x6577EB2CD786D502ULL, 0xCDD4BDA770D8DC20ULL, 0xA05715488F2CBD1EULL, 
            0x88E148AB5953B1B0ULL, 0x8F3469A41102B71DULL, 0x4459C8808549AE06ULL, 0x1DE60D222F76D965ULL, 
            0x670E3D7D2410751EULL, 0xF2A2D04AED847454ULL, 0x6852E751C5984916ULL, 0x0FEB5FBBB5C7E537ULL, 
            0xC53146556CACCABDULL, 0x443C9083C7715BB0ULL, 0xEE43EB524EEC9F29ULL, 0x69AD15649313109AULL, 
            0x4CC130E8CA086601ULL, 0xC9D8F0D22E4C8486ULL, 0x4CB36190A63BC423ULL, 0xAB5276B6EC9A2399ULL, 
            0x48BFF6EBF2C4BB81ULL, 0x5C2D06DC2D0A29BFULL, 0x77DBAA6D29CE6BF6ULL, 0xF849880B7BBC4D57ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseCConstants = {
    0x96D8A762A5693AA4ULL,
    0x7A6EA8867D74AA37ULL,
    0x5916311B47F9B0A3ULL,
    0x96D8A762A5693AA4ULL,
    0x7A6EA8867D74AA37ULL,
    0x5916311B47F9B0A3ULL,
    0x245B293780029B1BULL,
    0xD11A264B077A58DFULL,
    0x4B,
    0x43,
    0x81,
    0xF5,
    0xDD,
    0x3A,
    0x7B,
    0xC6
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseDSalts = {
    {
        {
            0xEB93A48836F55112ULL, 0xF1CA314019E70563ULL, 0xE561CC3FF2FF3175ULL, 0x95C28A9717EBF1FCULL, 
            0xEA901997FC92449BULL, 0x8A8F3AC6C217207DULL, 0xAEE4D1E7D7134053ULL, 0xE1DC5AE5D8EBEB71ULL, 
            0xEEAFE9DDE2A48B73ULL, 0xCF2301E40B130F69ULL, 0x21F534DA099FC3FBULL, 0x6C6019BC831EAFD7ULL, 
            0x61B4FAAC7C56EFBDULL, 0x4B27592D473C1A38ULL, 0xE9E76093701D8959ULL, 0x8F151A2D820292B6ULL, 
            0x4E68ECF91E09D21DULL, 0xACA8D3A5A8AFE91FULL, 0x60F882238144D0BBULL, 0x91E3E0C44AFECAC6ULL, 
            0xC21A9C31C4106B5CULL, 0x38BAAC1D4B93B2C5ULL, 0x8FB7D40728A2B059ULL, 0x795342D38F81D9F4ULL, 
            0x6FBBDD829EECE67EULL, 0x8ED96009F8D628D6ULL, 0x8EAF7C9223A10BF6ULL, 0x2A09EC6CF5AA18ACULL, 
            0x02150CC63D94526FULL, 0xD46A6F9B3520C420ULL, 0xA1B58335E949FE1BULL, 0xF64913B920E45A44ULL
        },
        {
            0x1D638E86F96407E9ULL, 0xA10EF10C71ABAC1FULL, 0x4B72EF9024A8981FULL, 0xFF8689124BFEF5F4ULL, 
            0x7E5503DEAE9066B9ULL, 0x55C7371D8065FAE4ULL, 0xE1BA5189CB075C51ULL, 0x97591F8D12D0BE1DULL, 
            0x9CA6F7689CA4674EULL, 0xF0C9EE1ED433347EULL, 0x7C7E190BB55DFB5CULL, 0xA419977AD216FA67ULL, 
            0x18F9DA88EA398EAFULL, 0x34DFF8A7BDE6A75AULL, 0x16B49E3C03099503ULL, 0x3850EB98852186D6ULL, 
            0x2B57FEC33FC4F5D0ULL, 0xD37A2FF7E5329C66ULL, 0xF80140EB925527D2ULL, 0xC1210A78AF00B038ULL, 
            0xA58233991ED3FE0AULL, 0xB043B5159C3C72F1ULL, 0x66DDB95B29B8FD13ULL, 0xC8A02A917856E3BDULL, 
            0xA4E102F10C712700ULL, 0x0AB9753EBFD66C11ULL, 0x586049F164858335ULL, 0x182D00278A52F0BBULL, 
            0xF687366EAAF92349ULL, 0xA34BA6D762D000D0ULL, 0xED83EADD79537822ULL, 0x17E185AC02545CAEULL
        },
        {
            0x8B165BB84706BC33ULL, 0xCDB6841314DA8C41ULL, 0xA6854A707EC4D148ULL, 0x3F441E2DD67D5E9FULL, 
            0x651FB24BF6C045C8ULL, 0xBDE8C4B7B2D928EEULL, 0xCA32838FC9FA68B0ULL, 0xB522D776A42DB9CDULL, 
            0x5190F7701A341B8EULL, 0x949D5485ABE45733ULL, 0x06478FBA8712F59BULL, 0x00D618E97E6340FAULL, 
            0xDE9E2E733191B518ULL, 0x4784089345635272ULL, 0xFFAB1559CBADA64FULL, 0x50FFE681985D5C27ULL, 
            0xF9654EF0A0666438ULL, 0x47648D7E95B9BB56ULL, 0x63714F9DE8FF770BULL, 0x997391CCCDA12FE8ULL, 
            0xE9E7CAE0EAAAF0C1ULL, 0xCD42AC5EF4C8625CULL, 0x45B36AF4319D0546ULL, 0x1A1DEBD8C5495B37ULL, 
            0xF60DBDF4392AF162ULL, 0x43131D54A4F7DACEULL, 0x6F4AF46F763B8A88ULL, 0xCC15BB20F98B7E19ULL, 
            0x67B3E92B34D0D4AFULL, 0xCB1676DCDE7C5A82ULL, 0xCB27CF13222D7F82ULL, 0x7D6B36672822B6FFULL
        },
        {
            0x3B171C2F6B443D81ULL, 0xBB7513B0E40B70D1ULL, 0x8092F8E2A8B20A83ULL, 0x8D1E675071791C80ULL, 
            0x66E214E590F9E315ULL, 0x788CB31B36C8ADC3ULL, 0xB0340EDE5A9A3A79ULL, 0x40826245D9DC9EF9ULL, 
            0xF39E6DBC18B951A6ULL, 0x40F3BBDAE140DC0CULL, 0x0C1F3B259C9B31D7ULL, 0x0921E68EBA9CC818ULL, 
            0x0A59B8A1342C0FAEULL, 0x96141F6864E75409ULL, 0x769A36201CA3C6D2ULL, 0xECA2BBC61CF1D78AULL, 
            0x679CB6FB7487804FULL, 0x7C9CBD80068357C0ULL, 0xC807CEBD514E5D84ULL, 0xC09A24B2EF488869ULL, 
            0x95293DF1AF683B62ULL, 0xB90C0F6F0946D51AULL, 0xED7797E56F2A9092ULL, 0xCE7EF2CAA37817B2ULL, 
            0x875A882B87F22A3BULL, 0x3F0329932EE490BDULL, 0x0A18E7BC1D57C118ULL, 0xFECBEDACF2AC5512ULL, 
            0x87132BCCE3AA42ECULL, 0xFF0151F4C6A40FB1ULL, 0x935C903C75088717ULL, 0x869B9F97590216D6ULL
        },
        {
            0xADE9400545B3D057ULL, 0x95F912E92265AF3AULL, 0xB945FA61EDF468F1ULL, 0xE6FD199F69DF1847ULL, 
            0x1801E2160AB8D8EEULL, 0x1CA460FA4F5A8208ULL, 0x1587185372FB0DB8ULL, 0xBC4E54A136DA3454ULL, 
            0x897BC3C5F65B9E31ULL, 0xD5525A2157C46E6AULL, 0xE9263B6A4C4A2609ULL, 0x34AF285C4C4150CAULL, 
            0x892DBB45DD2A767AULL, 0x0F3EE6649465F739ULL, 0x7363F6BD81833521ULL, 0x753225C2D94AA726ULL, 
            0xAD2B75E7144FF2D7ULL, 0xF3FBE05B785F071DULL, 0x5828F9F1620243DBULL, 0x5F41EE6A54FF6637ULL, 
            0x539B76CE6ED82B60ULL, 0xE0F6DEDD50A13B56ULL, 0xEEA815F3FA4DD9CFULL, 0xCAC1FC652C42C7E4ULL, 
            0xF0DE5855FD61B5E8ULL, 0x6536C8319747350AULL, 0x2BDA8508D00496D4ULL, 0xDADAE8FCB8AF0112ULL, 
            0x359641016C5754ADULL, 0xB411EED696CD8F13ULL, 0xC1F7CB766F0AA0C0ULL, 0x276E91005FEA2506ULL
        },
        {
            0x8F4C5E9C6C8CA1C3ULL, 0xED3E95DF8308E9ACULL, 0x7C661DF8B2FB4221ULL, 0x084FB9D15B2EECFBULL, 
            0x24BD06DD04DDEE43ULL, 0x15F323F2DE46D702ULL, 0x176B2A59AE15C848ULL, 0x9EA9EF5509822E7CULL, 
            0x0F772B216CAD77C9ULL, 0x99CD97D754C36928ULL, 0x95D577C83C7D3F33ULL, 0xEB1CCB6C4AB560EDULL, 
            0x6632D60D3FF04875ULL, 0x394F454F56F4265FULL, 0x71FED5B11FC0950DULL, 0xCB7B540353C849B0ULL, 
            0x6B55A87037A2800AULL, 0xB3045D8ADE19B43AULL, 0xD9A0E6C09B0451DBULL, 0x8AAD7805F3EC70D2ULL, 
            0x51D7C719BC766A39ULL, 0xB962AD0C0D4C6789ULL, 0x4CB7D89549684D7DULL, 0x072A11E1BED0ADB2ULL, 
            0x15592D835691E3A0ULL, 0x1537FBFC0FCD4E11ULL, 0x287E04811D6737D3ULL, 0xB93384E8F8885D24ULL, 
            0x05124FB133217672ULL, 0xB5EFBD410F2ACD5CULL, 0xAA94C1B8D447875AULL, 0xEA23D56C54FA5EDDULL
        }
    },
    {
        {
            0x47505DE6867463DCULL, 0x297C3ED1A1BE81D8ULL, 0xDD59037FF9099714ULL, 0x006A730B76F22155ULL, 
            0xFA565C8E230DD63DULL, 0xE111BF719C99BF5FULL, 0x7613BE4CE481BEEFULL, 0x7CF7783A4E8B9DE1ULL, 
            0x14AFBE848223132BULL, 0x6ACD102D6C8E9B43ULL, 0xD0EE52230AA50105ULL, 0x2748035C7300508DULL, 
            0x5F2E1EA74A969BF8ULL, 0x0A5DFFFA3479640FULL, 0x281448C4D5330B87ULL, 0x256D5242A81A44D7ULL, 
            0xEEAFF0FDE563F8A5ULL, 0x45920251E3C1BFC8ULL, 0x22931C77A5A7D884ULL, 0x4E05FBEEE7AFD0AFULL, 
            0xE0554D86E89BAEB0ULL, 0x82E67A0B6DD37133ULL, 0x78ECC779FA33261BULL, 0x2C36BEB2406D248FULL, 
            0xB47A6DCB76728575ULL, 0xE303E4D73C788367ULL, 0x9134577938CA5854ULL, 0xE53CE9D10BB315D7ULL, 
            0x4794BEC905BFC9E0ULL, 0x965A616CD517715FULL, 0x26CF956B72485B9FULL, 0x2AAE43EF02910F31ULL
        },
        {
            0x0D0931FD00E875BBULL, 0xF218D30397531AE0ULL, 0xF17387367229AA4FULL, 0x8947C2D6ED180122ULL, 
            0x1081EA2757147958ULL, 0x8BC45B73CBB10A03ULL, 0xFB3635E3D816589EULL, 0x691A98F100CA89ADULL, 
            0x6805D500E50D3BA1ULL, 0x58AB85441D802F66ULL, 0x816FAE1533CA9BDDULL, 0x0A121AA87996E790ULL, 
            0x3CD666C6203CBA78ULL, 0x24764C4624EA946CULL, 0x02BAC6F12ED61E71ULL, 0x83CBDC49A18849E0ULL, 
            0xAFBF583985B38C2AULL, 0xAC2E2247B14C6909ULL, 0x0D6578F6E759CA7AULL, 0xE416E51E856CB245ULL, 
            0x33F13DA816EA9FABULL, 0x26B639E1714B832AULL, 0xDC3723E5EA39572FULL, 0xA8BA0077DA9A4251ULL, 
            0xEAFCE190C26A1306ULL, 0x4017F99635559D83ULL, 0xAA5BB49E82C2AFC9ULL, 0xE7C1A3F56DE3415EULL, 
            0x27FBC8F267A5C92BULL, 0xE246EAF077C7E3ECULL, 0xE446301D68A8A3FCULL, 0x7163E5E143B61030ULL
        },
        {
            0xF798673F987EDAACULL, 0x32B54970C2FF9AE7ULL, 0x3381EFEA40EEDDB1ULL, 0xE86DA0A193894C0AULL, 
            0xFA78748442287238ULL, 0x3F47F2BB85A8E492ULL, 0xCEB6E14700B76E79ULL, 0x2896B23935E17235ULL, 
            0x370C32D097F7752CULL, 0x5B379BCC0E74AFDDULL, 0x32D4431FD0CB8A6FULL, 0x8E67E5FB099F79B9ULL, 
            0x1B09A60DF606DE99ULL, 0x5CC2F5039A525952ULL, 0x903E9F154344729DULL, 0xF6773C6770D49F0BULL, 
            0x9A52A0EBE0F006C9ULL, 0x07FB5D50646AFEA0ULL, 0x3F69E24E520ED9BCULL, 0x4AE604609B4538B0ULL, 
            0x921118C8E745AE6DULL, 0x97D19FF256631D37ULL, 0x62AC9C480974E0ADULL, 0x5DAFF1F7817402B2ULL, 
            0x9B0C6903A2C2D00EULL, 0x8A76A3F8F42EDC54ULL, 0xD56F795DB0DBFCB6ULL, 0xA700C980689C28F3ULL, 
            0x6E1A25D5AE90C5C4ULL, 0x96FD8FAC1E027849ULL, 0x73F79547A3077C33ULL, 0x60E7DE21711C3CA3ULL
        },
        {
            0x3294389489B13603ULL, 0x1701FEA2770C4C80ULL, 0x554F831306CA6860ULL, 0xCF7DEC22ED7D4B82ULL, 
            0x7CC4D8FAAB38E53EULL, 0xADBD15A182F4CFC8ULL, 0x71270C3C6BC240CAULL, 0x818FE6C4E96E1EDDULL, 
            0xA3D562C724FAF8B7ULL, 0x284F7D97D6955246ULL, 0x2C0BD0FC4D1B822FULL, 0xA33EA03D3E106A29ULL, 
            0x00D7815D8CB1D61FULL, 0x30952D6A70243ED9ULL, 0x937BA6EFA7A9650EULL, 0x3EC62826EAA39A97ULL, 
            0x1FAF95B19DF40DE1ULL, 0xC2B17EDE6D5FE330ULL, 0x2F0B96690721F9BEULL, 0x6AC83E8DDAEF90F3ULL, 
            0x7170ECB6F4B67848ULL, 0xCAC7E2D829CEDE4BULL, 0x5AB441FAD9471019ULL, 0x6B9F06C346290F5EULL, 
            0x85DE01EC2673F0CBULL, 0x13C3C44C9ED5401BULL, 0x87A300A75DC557E3ULL, 0x324A58B3F4523426ULL, 
            0xDDC7F040EE16C3EAULL, 0xBB28B6E905DCBBA5ULL, 0xB9199E43FD765801ULL, 0xBDE58571B3F489E3ULL
        },
        {
            0x52B0A09324D49262ULL, 0xC7701B318C4EDBF2ULL, 0xA88FA9C5DBE6CB4CULL, 0xA4AAC5F28C950000ULL, 
            0x8C607CE6B7C9A317ULL, 0x24487242EE2F0B35ULL, 0xBD9A253C663325C0ULL, 0x688ADE1DF0C77163ULL, 
            0xA6255AFF685D868AULL, 0x3C2DD2DACD2EDEB9ULL, 0x7AE14C7694F1A2F5ULL, 0xC62DF14A7EF1F1E2ULL, 
            0x7117916C1AAE69F7ULL, 0x0011F3C203C4E9E3ULL, 0x8DE1494C2C64AD91ULL, 0x0939E9B8551ABDECULL, 
            0xDB1B5951FB152683ULL, 0x01A6C3BBB672AA89ULL, 0x139E9C1D7FE5D717ULL, 0xB31D185A4024ACD4ULL, 
            0x7AAE984174454D67ULL, 0x79DFD5BC3281E721ULL, 0x5F8FCC08D4582E01ULL, 0x4892E54AFE275985ULL, 
            0xD411F79DC57D9F24ULL, 0x581DD839952C7657ULL, 0x7ECC207A91C5173BULL, 0x59B9CBFA688CA393ULL, 
            0x26544644D3A2C77EULL, 0x5FBB9804C6381E66ULL, 0x4BC4D7E052BF7B84ULL, 0xD88D13038ED84EF6ULL
        },
        {
            0x16CF5345753A498AULL, 0xD29F93CFE0BCCB36ULL, 0x85BFAB8C2441201EULL, 0x25BEFFD1F1402638ULL, 
            0xE1040E246BB6DE92ULL, 0x819178DC3780D68FULL, 0xCFEAC6AF62AA6A14ULL, 0x9F2EF9C27FFEFD56ULL, 
            0x31E28D0FFD21DEFEULL, 0x64D9153F450E69AAULL, 0x2F489E93EA90DA89ULL, 0x000421B4C9757C17ULL, 
            0x5E99F4A8AF26E83FULL, 0x8FFE5E9AD8BCE204ULL, 0x91E7694C0B2A40E5ULL, 0xF36E74EC74F51761ULL, 
            0x8E118298B44DA79CULL, 0x5409B4B932D5544DULL, 0xEC8E66D3D01B977DULL, 0x01960F94757EE79CULL, 
            0x402D30269EC368B7ULL, 0xEE2C1B78A3E80886ULL, 0x056351CBECBDC91CULL, 0x1D22B34402E088E8ULL, 
            0x89AF915B5097141DULL, 0x6E140C942C9A8F7EULL, 0x22FD8A10C159C63FULL, 0xEC44DB7C2E69C43CULL, 
            0x338D6AA70A1BA2A4ULL, 0xF840BC459A78F57AULL, 0x9A759FC1C864EF1EULL, 0xAE8C44DDA0A8FA60ULL
        }
    },
    {
        {
            0x76B2F406D2E2C92AULL, 0x0B7A805D2A98BFD7ULL, 0x52E57908EA59D46BULL, 0xD458F63864D68F54ULL, 
            0x64E9E4256E7658E9ULL, 0xD520D3D5687EC1A5ULL, 0x5191D4F5572B92C7ULL, 0x28A46637323B82EAULL, 
            0x946DE53B40D1B309ULL, 0xF7B4593BD0D61C23ULL, 0x14114B41AC49316EULL, 0x3A26408DB4E04595ULL, 
            0x56D8208D2F405CD2ULL, 0xDFBE44659B31B887ULL, 0x3B400F4809EDC2C2ULL, 0x2FF7EF58D9725BD3ULL, 
            0x3ACF509672C12989ULL, 0x1F94678D86462746ULL, 0xDCE344893456526AULL, 0x700D49ABA55F9CF2ULL, 
            0xB32221DDD713A7BEULL, 0x0B217B07545A602BULL, 0xF4460729D11E0512ULL, 0x15AB34AB50B05B73ULL, 
            0xD6E847A5F1E84C23ULL, 0x31B1A35422D4C371ULL, 0x649B587883A41B13ULL, 0x0DA2B925627C3800ULL, 
            0x7B7B5A28694F77DDULL, 0x934260E3319F8A24ULL, 0xD08D45341B7189BEULL, 0x41D074692534E0FBULL
        },
        {
            0xD0FA1578971C9680ULL, 0x8F74536D2E64D2D6ULL, 0x430CBD22C898E9CEULL, 0x5E449B67BF5BA042ULL, 
            0x55FA8FF15B0980D3ULL, 0xD670269939848510ULL, 0x980A36B903C0CDFEULL, 0x61D6CA1814CA69D2ULL, 
            0x3F7D04FD13C07B44ULL, 0x22E40AF46125BA21ULL, 0x5EBCA99E6EF1A4CDULL, 0x041D5631FAE79404ULL, 
            0xFBB9EF9CB2C65F83ULL, 0xAD3181BC8A89C6D3ULL, 0xED0C3A44074FC117ULL, 0xB246D998507F6FECULL, 
            0x91C424BA5A3611B2ULL, 0xB8C38EF9F3FF497CULL, 0x0D83399452B12C5AULL, 0xD55DA169B585CDAFULL, 
            0x80C80946A0F8BEF9ULL, 0xBE01A1B38C2FCBFFULL, 0xE09ED1CB942F8AE2ULL, 0x759019B57AC62774ULL, 
            0xD1E40D5BA3E96AE5ULL, 0x21B1F631C01D582FULL, 0x08743995D5F6477AULL, 0xD70628F891A5B8B2ULL, 
            0x6FC524047A6AC22BULL, 0xC604FE3FA756D3EDULL, 0x8C64420C6B0B144FULL, 0xFB2FFBEB3970204DULL
        },
        {
            0x7F3E897CD97ABDEFULL, 0xC6BEA219E01DC61EULL, 0x5C460681FBC47F2DULL, 0x3FB8D45318E99D16ULL, 
            0x2193E60BB721DE26ULL, 0x982A908FE30C9FFDULL, 0x85CB6ECB46982217ULL, 0x0B3F8C2B8C52C0A9ULL, 
            0x3FFD1E0F1DA3893FULL, 0xE2963101AD4D009AULL, 0x1C54501657DA5261ULL, 0x0695B8B97282D344ULL, 
            0xBF4C59EC1A3B5DBCULL, 0x811E18B9AE89673FULL, 0xE0AE8858759FA8ADULL, 0xA5CC22D124558B37ULL, 
            0x923E83BFB82BDBAAULL, 0x3632AEB22D9AC465ULL, 0x3CCCAC9FDF81E653ULL, 0x46913530DC003D98ULL, 
            0x4CF9BB711EEB0CFCULL, 0x22365752B6C29D62ULL, 0x8A0B6DD03E6F9E8FULL, 0x51E4FBF39BA74771ULL, 
            0x2A7A4DB4C07C6F49ULL, 0x24E09798C48B7F8FULL, 0xE501C80C68745293ULL, 0xE253B7FF640CC32EULL, 
            0xE7368B84EFBA2EADULL, 0x334255DB80D1498EULL, 0xC1D97F0B3650947EULL, 0x1CC37D99CEEB0BA5ULL
        },
        {
            0x19634F02CA313931ULL, 0xEFF51C707F969F20ULL, 0x65A844CBE3663F1AULL, 0x3E16C76929F8B1A6ULL, 
            0x59E8C318FDED8737ULL, 0x90F71A6D9218EE41ULL, 0xA77B2783213DE5EDULL, 0x8B19CC9B9FBA74A7ULL, 
            0x498F549E48A07EDBULL, 0x211234ECEACF8087ULL, 0xD6DA1D2645FE7152ULL, 0x11E02A4283E30675ULL, 
            0x0B4EC3EF503D82C8ULL, 0xBDFEB83E698B49C2ULL, 0x64D588CCB3EB1493ULL, 0xD25F6F096ED93F09ULL, 
            0x901008A20926FDF1ULL, 0x39358BC286A655A6ULL, 0x23BF6655BA154735ULL, 0xA39DCA4EF7A32F98ULL, 
            0x59A76F68F113DC21ULL, 0x3F19C3F3BC526B4CULL, 0xE9A71E04F4C6321CULL, 0x8CAD92577057522AULL, 
            0x1C30BBF661577624ULL, 0xCE0749F4037E82F6ULL, 0x1D27038B8564FD7AULL, 0xA9E72880A2088879ULL, 
            0x8BAF3021E45ABF6FULL, 0x17D68A6E5F2DA078ULL, 0x3D60AF2E71F2C7BAULL, 0x8B476C37E333EFEAULL
        },
        {
            0x50745815BE44D9A3ULL, 0xAC049ACD0D0DDEA2ULL, 0xFC491A87554374F0ULL, 0xFB809E150362BE1FULL, 
            0x2BE3BD768D67AB2BULL, 0x305E4965792D8937ULL, 0x13DCFF003153973AULL, 0x9FD877D9372825E5ULL, 
            0x35A0629D7599A613ULL, 0x624DD6DDC3F9AA12ULL, 0x32492B33013D1196ULL, 0xF6697C8C738E86E3ULL, 
            0xEDF5902CBC6D065AULL, 0x265DFE3F5A247A30ULL, 0x42EE43D4755421D1ULL, 0x7BCC26D193E93149ULL, 
            0xE09C1C56AFA97A50ULL, 0x186D6C96E45B0DD4ULL, 0x61F34D25A88B8A95ULL, 0xB310BD0475E0A723ULL, 
            0xA15FC9154A4836D8ULL, 0xFBF055960CEEA508ULL, 0x309FC746D432A0F9ULL, 0x10A362CA50BD8D83ULL, 
            0x45093E79DDF9B2EBULL, 0xDE01D00009533C0EULL, 0x07AA71021A428CE1ULL, 0x5A814CEFD91E0FE0ULL, 
            0xC75FC02027529C6BULL, 0x1DA70EF5212378F7ULL, 0x320C8EEEBA17965BULL, 0xDA041C8CC7BE0314ULL
        },
        {
            0x78F9F37BA2F6F165ULL, 0x30303B92F08EFCB5ULL, 0x2DA18012E9368155ULL, 0x61074E748B316619ULL, 
            0x2EFB9BEB83DE32F6ULL, 0xB31E1551330B36DDULL, 0x73788ED06CCD3D13ULL, 0x6C5B352E540EEE86ULL, 
            0xAD4DBED5CABF1BF7ULL, 0xEDCFF872456936C9ULL, 0x28D0ED33E47D3703ULL, 0x8DA3C2CF0CAF9F46ULL, 
            0x17C25FBF3301590DULL, 0xF3284B14C0609ABDULL, 0x4EA0E2FFA990F257ULL, 0x08B00E2D062E0404ULL, 
            0x9C308A55EA4AE2ECULL, 0x05480C69E2C0B3DAULL, 0xCC0A4C94070DA026ULL, 0x5264C440E9440857ULL, 
            0x53687E8AD8287B87ULL, 0xD2DE4B1135FBC6D1ULL, 0x15956DB8049206E5ULL, 0x32B73F124E0E4DBEULL, 
            0xD131EFB485036109ULL, 0x0A0C24A07B7C6B25ULL, 0xAAD2040A6672354BULL, 0x70CAE3F9D8ED8C17ULL, 
            0x7ACFA2CD48116B4FULL, 0x1765FF0538221CBCULL, 0x0530D5F6922611D0ULL, 0xF0392AD112D00ACCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseDConstants = {
    0x8EF1F54B6C73068DULL,
    0x17770CF288F40990ULL,
    0x1A93F592A899480FULL,
    0x8EF1F54B6C73068DULL,
    0x17770CF288F40990ULL,
    0x1A93F592A899480FULL,
    0x35C5B3C80D765641ULL,
    0xBFDA03270802E782ULL,
    0x8B,
    0xAA,
    0x22,
    0x88,
    0x42,
    0xD2,
    0xAD,
    0x2E
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseESalts = {
    {
        {
            0xA1CA62BEBB46C7A2ULL, 0xD7576C64CCFF6982ULL, 0x0EA048269271876AULL, 0x28C62D54AA3F936FULL, 
            0x4D277293CA4CD913ULL, 0xAE9723615B014DDCULL, 0x7CED957612A2FFD1ULL, 0x8755215F1BC42CBBULL, 
            0xC8DE74371D0F828BULL, 0x026B4155A4C2F4CBULL, 0xD0556C60072C2AFDULL, 0xAF1FA140D6759043ULL, 
            0x9C98B8D8DB6DFBA7ULL, 0xA6C42D5AC15B6A9AULL, 0x057940B17D0D74E8ULL, 0x59C478D8ADA363D7ULL, 
            0x45B448F8D9956A4CULL, 0x1213658D8215E87DULL, 0xD719B5B75E7A2C07ULL, 0xFDC000E90AF9163AULL, 
            0x0A4D3BD106374DBEULL, 0x7D3BE2359D9D5E6DULL, 0xDA71681739C7441FULL, 0x5F0095A678EF196AULL, 
            0x0034807400BBC59CULL, 0x5B6A62546F85D332ULL, 0xCF4E37B2E4F926CDULL, 0xAC7ED68F04DE7232ULL, 
            0x40965115712DA527ULL, 0xE2CD859D58B3F030ULL, 0x1AA68DAE3FCD5795ULL, 0x12B5981B07ECD231ULL
        },
        {
            0x456B35B89CC12B8DULL, 0xC5E018F937E4BB29ULL, 0xD476B202D3C15AA4ULL, 0xC51D1ED538F77E75ULL, 
            0x2C86616DCBD77559ULL, 0x6BC2C468B19E7FDCULL, 0x9C16924DE5D89E1AULL, 0xE29BE038F0967841ULL, 
            0xA0023FD36352D8E8ULL, 0x116A7A7BDAB8594DULL, 0x2B78953483571330ULL, 0x493711D646CAA9EAULL, 
            0x493BAD4D4BA04907ULL, 0x8797A2C87E5441BAULL, 0x1BAB7FA426C181D4ULL, 0x4FBD3F8569DBCAF3ULL, 
            0x913C43F54E750A77ULL, 0x823AC06AB5A4F674ULL, 0x622BA0F103E924C7ULL, 0x3F2E31C5D8B88577ULL, 
            0x523E84F8F7493E71ULL, 0xB0C22D00483FCFECULL, 0xC10E20CED496555DULL, 0x79169393A1F116D5ULL, 
            0x5EDB32BA30623DB1ULL, 0x39FB9089D8A70A8FULL, 0xF66F8177FFF9BE7AULL, 0xE38BA8F26112ED14ULL, 
            0xF7248B668073FB6BULL, 0xCECFF0A8C9705704ULL, 0x835445E6BBC07F52ULL, 0xBD14D6816C8FB9CFULL
        },
        {
            0x896306BC2CA1D791ULL, 0xF242FAE14AFF6672ULL, 0x521C38D12A6EF3DEULL, 0xF0D62465A01E1548ULL, 
            0x46A0B71FA90D6ABFULL, 0x02573BF00C3EA9ADULL, 0xC1429518416603C2ULL, 0x9BE2FC45D80DE8D1ULL, 
            0x7BB9B479FE4A81A9ULL, 0xCF012FA22DA0287CULL, 0x9BEE5BEBC9E20978ULL, 0xCAE8AB6C36E39036ULL, 
            0x9EED48001553B6D8ULL, 0x5DBA048E77F2B277ULL, 0x98AFB08091A309C6ULL, 0x0FCC0E4981BB4D7DULL, 
            0xDFA0C64C27B89446ULL, 0x067BC9D7ED930ACFULL, 0x769FD0008E0FE830ULL, 0xCE6C0809341137E4ULL, 
            0x0A009622A77375E3ULL, 0x61E03CB4D0484CD7ULL, 0x2614E9B7D0A660ABULL, 0x6F7E1A6778485B24ULL, 
            0x76E97A2EA98A1B7FULL, 0xA3D66A7C037B3984ULL, 0x9AF1665CBABD75CAULL, 0xA8C962AA0193D869ULL, 
            0x1707E32CC1147D4EULL, 0x200A9EEB7B29FD5AULL, 0x46AF1FAC68B7CE1AULL, 0xAAF6676EA21BBDB2ULL
        },
        {
            0x0B35F08094EBD975ULL, 0x6D5E638FF6477A0BULL, 0x031E2D558FBAAB95ULL, 0x49C36012A18A530FULL, 
            0xF4636B78A6CCB62CULL, 0x5FA8D8D3668D3980ULL, 0x8D377848797FD517ULL, 0x768C9B68B3206B42ULL, 
            0x65891B1778C5E1EAULL, 0x6FA96729CC226F23ULL, 0x48CFE2C0DCD84ADBULL, 0xECD323F22B2DE21CULL, 
            0x024186BCB5F68ED4ULL, 0xE804D7EAB09D293AULL, 0x1701B6C98C76B685ULL, 0x51A0B64F535482E7ULL, 
            0x9CA915575C41E022ULL, 0x6B5F01B1BFE6ECE6ULL, 0xC38D3B264F2D0ECCULL, 0x35EAA4132BEDF790ULL, 
            0xECEB50F6462DC9B4ULL, 0x4C43AD27C14E4D51ULL, 0x57BA3111661036FBULL, 0xAF4B201BE917EB0AULL, 
            0x58AB7C6FC8969B1CULL, 0x3352C6EAEDC6C33DULL, 0x33E97AC837020DFAULL, 0x3CE3B2FC25388DC5ULL, 
            0x55D389BB9C0C3E1FULL, 0xB26E16D9FAE2A1D4ULL, 0x9FB8170F8E994257ULL, 0x0FF9FA78754A6AE7ULL
        },
        {
            0x96C660FABBACC2A7ULL, 0x85BD011983AC3046ULL, 0x0CE70CE259C1804EULL, 0x14546536938F4492ULL, 
            0x1EFC61F593AC1536ULL, 0xCE2C0BC789ED187AULL, 0x9BB46700E8A3FFE8ULL, 0x6BD07C5432525D1EULL, 
            0xBA5694A31292EE77ULL, 0x3403617BF84DDEA1ULL, 0x0BC1C2DEA03B5BAAULL, 0xBFA0F2055BC8FFA1ULL, 
            0xCE604A0ABE06B6A5ULL, 0x8CAA907817DE1AEFULL, 0x7EBE5428275F0C2CULL, 0xF7C1F3616AA9CEF2ULL, 
            0xA4521E0F241B4469ULL, 0x5B523126E5CF2C85ULL, 0x51AAD73F1E7F65ECULL, 0xDA97C5740D31A3C8ULL, 
            0x4AEDE2EDBAC6607AULL, 0x75CDC03293983FBEULL, 0x67DF4E1833340B6FULL, 0xCB02004979A579C2ULL, 
            0xAC8DEC536458B134ULL, 0x195A1F110A945612ULL, 0x395E456910265A6EULL, 0x9B518924FE06E26AULL, 
            0x7F1D622600D73AF6ULL, 0x3387C3A75DF94191ULL, 0xBB0EFE34A6ACC976ULL, 0xDE5C667445A56980ULL
        },
        {
            0xA205C8D2D811427FULL, 0x696CAEA969F3AC3AULL, 0x803B3B051A9D3607ULL, 0x79B568600203AF45ULL, 
            0x81D06793B392E08AULL, 0xA8999B32687F0969ULL, 0x970524C832CB1DC2ULL, 0x5F93D45A7759CC24ULL, 
            0x400AF3D6044096A1ULL, 0xFFF8E5E8C2801AB6ULL, 0x9945F339AC414610ULL, 0x7711929159FAE912ULL, 
            0x984E7215220E1FDAULL, 0xE6E49C9CBB43E15EULL, 0x1CA33F6A4D7FD024ULL, 0x0F8FA525C194DD51ULL, 
            0x4B297AF74B0DC435ULL, 0x5EC744E9C52BC068ULL, 0x822AB2A3765CDCA9ULL, 0xFAEAAAA051425A4CULL, 
            0xAA03FB28C936AB81ULL, 0x4FD76572B6243E8CULL, 0x0A9555AB567FE7BAULL, 0x01726093868C0FF9ULL, 
            0xAC0C5AFA8B4A6C0EULL, 0x0D28149D39B7B7B1ULL, 0xB4A281D928F93418ULL, 0x704A584BE7761993ULL, 
            0x1E7EE218605D6532ULL, 0xBAFB0E9D509AB457ULL, 0x7C46DCA1E39F36BBULL, 0xBF25D5AB745CC097ULL
        }
    },
    {
        {
            0x02202E6D4ED840DFULL, 0x7CD6DF81A619AB63ULL, 0x545957ACA15A9117ULL, 0x45AE0650E995D53BULL, 
            0xDBD42DAA1EB98CB4ULL, 0xEB84743ED0B0392EULL, 0xBDA03AA75E9132B6ULL, 0xA9D35E3902EADA79ULL, 
            0x98CCBDD6B0B9E571ULL, 0x81055740875D8BC2ULL, 0xD1EF98493AFF56A2ULL, 0x6ADD944B0D9DA65AULL, 
            0x7DC1F6427C792869ULL, 0x1ABD980F6ABA698AULL, 0x1902A40F641C84CAULL, 0xBD387C7A3F9375A8ULL, 
            0x562060595478BC58ULL, 0x96BB0F144FC14265ULL, 0xA21C1C85E425EF8FULL, 0x2C6C629065C22AA4ULL, 
            0xB0EFC91E7A6A9907ULL, 0xFE204F9454F51CE9ULL, 0x5BD4F6B4F42D6A8EULL, 0x0C897D0AFB345057ULL, 
            0x469F100F83843488ULL, 0x6578475AF046C8F6ULL, 0x9DE0492B16FB6D66ULL, 0x6EE8756E86023820ULL, 
            0x50FEE2DBFBF29557ULL, 0x3CC99695CB7A6016ULL, 0xCEE63DD9CD1309EDULL, 0xAF63D1E43C77E553ULL
        },
        {
            0x1FFD86E31D341668ULL, 0x4B266B7491531295ULL, 0x5F7289D782A78A18ULL, 0xB6573D2626A0A154ULL, 
            0xA99D404E626F533AULL, 0x12CB845637F164E9ULL, 0x1036331FB03A3CE8ULL, 0xF30A725056F1B03BULL, 
            0xCDB9609F6E7E2C18ULL, 0xFA2684E5EBD1B9C9ULL, 0x5050039CF668C0DAULL, 0x4CBFA3B351ECD051ULL, 
            0x2D3B03F3E5011AFCULL, 0xE7F73AEB4C81EF6BULL, 0xA4849CB6317B9049ULL, 0x2C029C5BECCDB2A3ULL, 
            0x1CFE78DB4DE8E868ULL, 0x8D840D9C4F737CBDULL, 0x142ADD3AC0F56F59ULL, 0x01906A5E91D3F2E2ULL, 
            0x4E630EAD1DC84532ULL, 0xC273BCABDB95E3BFULL, 0x39BC53BA159D9A8CULL, 0xDDEE9220F66479A4ULL, 
            0x667F68EB5430166BULL, 0x01CBC3C629A70E08ULL, 0x19349BEE6C02A699ULL, 0x83EA4449CF983626ULL, 
            0x93BDA3906479A08BULL, 0xB1B1D784614FB933ULL, 0x08940DF74B576F16ULL, 0xF9B45621B3CF921BULL
        },
        {
            0xB0026A80E6FBA8A6ULL, 0xE2A58F273EAD89DBULL, 0x66CA5546B66C2B5CULL, 0x71F1A6A6A18BF589ULL, 
            0x4432DB194BB47AB5ULL, 0x34E25F28A84C5978ULL, 0x92D9D6C9705D58B9ULL, 0x593C5B99C4824E25ULL, 
            0x7A3BB62BB3DA66C7ULL, 0x6A6A663DC1BE2976ULL, 0x7B52D2465524BA9EULL, 0x31E08889067BE83DULL, 
            0x63DA233DD2391D77ULL, 0x4BB9E82F32DE1A9EULL, 0x6FB470B26A914AF6ULL, 0x0838C95621D03050ULL, 
            0xF55EE23B048A1241ULL, 0x013A5BBA9849F79EULL, 0xF2353212D4C4DC2FULL, 0xD5E88C280359246CULL, 
            0x4CA53EB67BCE8EE2ULL, 0x12238EB6F74AA250ULL, 0x7DBB7848567CA77DULL, 0x8399DED62EE06504ULL, 
            0xB23069A41DA4A259ULL, 0xC98EBC79E183ECB4ULL, 0x4284D686082CEDDAULL, 0x8DC921AA7A4E024FULL, 
            0x2572DC04B7DE5F90ULL, 0x490F398C84F55DF3ULL, 0x1ABDB60388129674ULL, 0xF9F5113248C71841ULL
        },
        {
            0x5E89C92121CAD3C5ULL, 0x392B87D744ABB3B2ULL, 0xC2FD812863F9D13FULL, 0x5817F0E66D008F0EULL, 
            0xA576DD8A7C94FB2CULL, 0x1514CEEDCC9DD8E2ULL, 0xD3268E6869629FCBULL, 0x277BA175C8959E7CULL, 
            0xF3F0442CAB1F2D88ULL, 0xA36296A5F694E076ULL, 0x09815B026D00E5FFULL, 0x2225885D81DB10F2ULL, 
            0x2257A43A4A52D3A9ULL, 0x7974FADB9660805DULL, 0xFF9A3BE70B1D8D53ULL, 0x921388EBDEBD45B6ULL, 
            0xE61567F07C4D6299ULL, 0xCDD13C92E3297DCAULL, 0xEBF6B7A1EE2110D7ULL, 0x14CE7C3374E186E6ULL, 
            0xF4BCC0C10319BF4AULL, 0x7371B06F0CC4E77AULL, 0x0EEF9E3B1AA55B3EULL, 0x5CDFD7EF681D99BAULL, 
            0x06358FFD724EFFB1ULL, 0xEFB941ED14550CC3ULL, 0xCC3B6FE19559AB94ULL, 0x9A66CC100E7F157DULL, 
            0x8F742A12EB6D1546ULL, 0xD05CCE3ADC518532ULL, 0x58B10751DD52C741ULL, 0x7D93A1049740BC6FULL
        },
        {
            0x1EFD1E3D73434CC3ULL, 0x0EDEBDEEA0D003CDULL, 0x0DB8747C8E594CD4ULL, 0x5D4CF681F4D7B7C8ULL, 
            0x060ED63831570326ULL, 0x5605F0A3840BBBCDULL, 0x5E3C530000C9729BULL, 0x0189CB9FD0F62A2FULL, 
            0x19AD55899D755722ULL, 0xAE8348694E42F1AFULL, 0xAC9C2329783559BBULL, 0x03064D4D912FBE7AULL, 
            0x99882EF0F5911332ULL, 0x8C2796C3AAE3E034ULL, 0xD706D92253E5ED39ULL, 0x14AABA0CB26EEFDDULL, 
            0x0BF9AC09A28A101EULL, 0x783C4CC7E5BF3EE8ULL, 0xC1FB5DD8820E70BFULL, 0x8E3E16F10C19A98EULL, 
            0x2F51F55B001BCDB9ULL, 0xB7C189CED04EC78FULL, 0x885241741BC2EFD1ULL, 0xFB57D723768CD926ULL, 
            0x2A806CFD244C37CDULL, 0xFA62CD4AD969573DULL, 0xB2C72C0B941FD6B9ULL, 0xB251A3D8106E98DFULL, 
            0xBA8CEBB05D1EAC9EULL, 0xB1FE1C31F41F7ABDULL, 0xD0332EC91DE765D2ULL, 0x225B6A98F8D9B9EDULL
        },
        {
            0x7E52E3B53AFECE49ULL, 0xE505634022E5EA6EULL, 0x4083E2817373A3C7ULL, 0x9BDB2F4F3D4D96B7ULL, 
            0x7546736F7240FD38ULL, 0x2C3AC6A3BF15C3F7ULL, 0x5107476B08523F47ULL, 0x85341DF17248700BULL, 
            0x3EDA21EA7E7011A2ULL, 0xD2820FF24261C17AULL, 0x523D97E7B3FB17F9ULL, 0xD3ACCCBB9AD12E20ULL, 
            0xCAC7F8D66D623664ULL, 0xC40DDAF227483FC4ULL, 0x0103563E3AFD311EULL, 0xB013E7A4517E97A5ULL, 
            0x946752B936FFD615ULL, 0x4C40149FFA95F4E6ULL, 0xE7470418DC02A3A2ULL, 0xC9BC65EF2CF7A1A7ULL, 
            0x64517AEAA082EB37ULL, 0x1B00902AC777E23DULL, 0x2FE44A37E0E88FC6ULL, 0x91F250C49BB79702ULL, 
            0xBF464F3D75A69237ULL, 0xAAC10C26113853C5ULL, 0x160A1913CA819D50ULL, 0xB671F3A55E567FCFULL, 
            0x2D78DBEB7A826F74ULL, 0x69AB97940C405366ULL, 0x6726EEE3B08F820FULL, 0x79468D3E39C31A3DULL
        }
    },
    {
        {
            0x81289062A46AEC4CULL, 0x7388E02BBA597EC6ULL, 0x7C9C1DCA464803E5ULL, 0x9D85E1556ECDE33AULL, 
            0xAEB193DB28D0ACF9ULL, 0x05BD7A6462FE7AF7ULL, 0x56E27E2DADE1E459ULL, 0xEC534F9300B672A3ULL, 
            0x0C0C74CDE603F311ULL, 0xF61AA1B2187848F9ULL, 0x2512A29FE9CCFF88ULL, 0xFCC2FFF1DD9FD515ULL, 
            0xFD7A6BF8585D33D1ULL, 0x10113AC945EFC68CULL, 0xB373017E2292C4D7ULL, 0x057FA633C520F19EULL, 
            0x5C178DB7AD12F3D9ULL, 0x43D83A6BA1043650ULL, 0x187BA097E95F77F9ULL, 0x558ACB0DE19F9517ULL, 
            0x8B8FAC192AA59B96ULL, 0x40BD6BE2B52E6594ULL, 0x0A99E74A2A209E51ULL, 0xD51306A1947616B2ULL, 
            0x1247514D216EAF1CULL, 0xB8339DC54C650D95ULL, 0xB34B6726DC1886F9ULL, 0xCBF35889B32497C0ULL, 
            0xBF1AB15B4835891CULL, 0xB8E6E9F6AE5EFC2AULL, 0x5DC71B52C2065241ULL, 0xB338F32822E6E78FULL
        },
        {
            0x6B3FC1DC5BD8A1B2ULL, 0xF43542EBA57E064FULL, 0x3ED170BDAB4B4EC4ULL, 0xA27094BE07341163ULL, 
            0x391203D893FC2C51ULL, 0x223DB00DBBB65923ULL, 0x47B4BBE95B44AC82ULL, 0xE4A986AD03D9359EULL, 
            0x2169196BDEB16272ULL, 0x4154455463500D6EULL, 0x842B07014ED6AE00ULL, 0xBB531F55905FE890ULL, 
            0x84178E2A2BD7B1C8ULL, 0x32E016DE8947EFBBULL, 0xC97B7D9D882DC007ULL, 0xE210568426213DC4ULL, 
            0x6F7F09CE9B09B5D3ULL, 0xC0247057F8EAD73AULL, 0xAD55B6C0EDE359B7ULL, 0x64C079C2D330C70FULL, 
            0x0AE4C144092A6E67ULL, 0xB126931A1F23A60DULL, 0xC2DF881B884AB1F6ULL, 0x72388CDB05F0CB1BULL, 
            0xC490BB1929780F35ULL, 0x96100043B947AD97ULL, 0x81976861A052B002ULL, 0x5DD309B018ADE536ULL, 
            0xF60954E20894E9A4ULL, 0x02825C23AC5D46E0ULL, 0xE6DAFD9133629C65ULL, 0xDBEAC3A936E07D1FULL
        },
        {
            0x58E6C3185CA78BE3ULL, 0x46CAB148AED57166ULL, 0x41B98B876F526425ULL, 0x21EA54E7640A05B8ULL, 
            0x7CE312F78FCB4998ULL, 0xA2AECD1BBCB3CEF3ULL, 0xC485F0ABB0F049D4ULL, 0x55E6467C1BEC81D3ULL, 
            0xF1874BEF1B951D08ULL, 0x48C5BC9AA7D56C41ULL, 0x979B7C3EFD9C4A1DULL, 0x439B0B31B497429CULL, 
            0x1CC1D1104A7141B7ULL, 0x0AB3618E70121DA3ULL, 0x25A9839C8A0CB6F2ULL, 0xCAE3A5A58CC6EB37ULL, 
            0x38D3B40974D65379ULL, 0x6AB636AD11B1D049ULL, 0xFCCEFCFAA30C2BE4ULL, 0x2355DC339F981FBFULL, 
            0x95374845702B984CULL, 0x1CDB91F0F5DF3924ULL, 0xE2F59ACCD21EB0F0ULL, 0x0C03B75CE7B2508CULL, 
            0xA3EC08C69F563D03ULL, 0x8145681DCC196C48ULL, 0xABB09135842C4C21ULL, 0x51AF9BE2638E09F5ULL, 
            0x45BAEB89831C49A8ULL, 0xC76DA46C012AFFA2ULL, 0x4BAFDA8514C13934ULL, 0x1C8923CE07B3465DULL
        },
        {
            0x2E2F6A8924BFA828ULL, 0x817E7EA4977D74E6ULL, 0xF2DC28045B0B923AULL, 0x3441588AB9F7FBD6ULL, 
            0x6FB851C8AE621626ULL, 0xBE212BCEDDE5A1EAULL, 0x43E6D735CCB551FAULL, 0xDDDE793BCDBB2BA8ULL, 
            0x4785EA4E3469D936ULL, 0x3DD10C6646BC3BECULL, 0x4D1623E8D229C443ULL, 0xF768B69724076A6BULL, 
            0x35220F48774685D2ULL, 0xD5DE63787DA01042ULL, 0x16CCFCE4F29570C9ULL, 0x5B1D0326B3F5FFEDULL, 
            0xE654D5B5354B0359ULL, 0x09AE09066C8ADFBAULL, 0xC5AEE73AEE4DB27AULL, 0xFFFECEF631F92FAAULL, 
            0x8AFFA08132A0CE36ULL, 0x1C8076FFCCC06C04ULL, 0x8DFC0A207160B134ULL, 0x51E5BFF91519BB79ULL, 
            0xDA06D68ECD7F0B13ULL, 0x613BE97341356241ULL, 0x1181836352699C50ULL, 0x1A1ED75D9B9E3C91ULL, 
            0x2A8F170A8E091FA9ULL, 0x06F0C41BBE0DDCD6ULL, 0xC3F6CD772D587EBCULL, 0xD0A75F2D7C574E48ULL
        },
        {
            0xC88EBFFA77B2B7D6ULL, 0x6CA4CE2E958616CAULL, 0x4D486109B944F34AULL, 0xFA49F382DA4907AEULL, 
            0x6AEF4DD7B52196B3ULL, 0x9FF925120336F677ULL, 0xAEDB9AAF2EF30ABAULL, 0xAFC8C8BAC12D644AULL, 
            0xA96AC6DD401DE650ULL, 0x5CBE687F09564B12ULL, 0x14F4AF10A3B2C954ULL, 0x2FA9350B82983DB8ULL, 
            0x3649D65BFB4E2702ULL, 0x8ABC880A5351A60FULL, 0x4CE74A5680B2B5A6ULL, 0xF29877F0BDAAA6B2ULL, 
            0x519CD29FC2C79A11ULL, 0x2D03D782124390C3ULL, 0xADDD254390428EF9ULL, 0x6F70BB27D50F744DULL, 
            0xA272695B9E1D3DA0ULL, 0xF367AFB42D18B3DBULL, 0xB71DA3E4632E7049ULL, 0x31272ED6A3BD8BCBULL, 
            0x9E1D80CA824F497AULL, 0xA926C9159B64D3DAULL, 0x9C36E209F290779DULL, 0xB39FCB6847F82F31ULL, 
            0xDA396DEDAFBEF919ULL, 0x04A816DA93F6B74DULL, 0x05B3DAD4F62DE824ULL, 0xA28BD8B622EFEEACULL
        },
        {
            0x5124C25F9ACEEDF0ULL, 0x049DF55F67F4A89AULL, 0x1D2CA28506281C4AULL, 0x80D6235DA88938C4ULL, 
            0x7079C9F7FB9B5567ULL, 0x86846091B9864101ULL, 0xEE2F04B4794E1015ULL, 0xA2EA9F2015B93C31ULL, 
            0xF4DECB3CF9B4AD15ULL, 0xE7D1C9E91F465FBCULL, 0x459F2F045269EA2CULL, 0x349F06BE2EB4B303ULL, 
            0xFEBE5B45DA58C02AULL, 0xF43AAA792BB1FDD9ULL, 0x7F9A351C064BEC56ULL, 0xF65562F3DFBAAC69ULL, 
            0x60C6AEB2A9482C93ULL, 0xEA79096564722342ULL, 0x19C38F92338A877CULL, 0x59EEE78089D3A893ULL, 
            0x4F7E89149950A1CAULL, 0x9E57FCE31D18E476ULL, 0xFC4C5792F54C1A7AULL, 0x10663EA2E8F08C2AULL, 
            0x4B8EEFAC1CB06A7EULL, 0xD9F7A6ADB39C65D3ULL, 0x3DE1C692FC20845CULL, 0x878B84AE8751326CULL, 
            0x56CC4F2C971707F9ULL, 0x51C7636551F76343ULL, 0xAAAEE8F2B0F923EBULL, 0x4BB391114DD940EBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseEConstants = {
    0x4233A8EB33B08C60ULL,
    0xA33DCF4BAC993079ULL,
    0x95D5F167D534E891ULL,
    0x4233A8EB33B08C60ULL,
    0xA33DCF4BAC993079ULL,
    0x95D5F167D534E891ULL,
    0x45FC3677596D9ECAULL,
    0x86EF60295D8B6958ULL,
    0xDF,
    0x15,
    0xC8,
    0xD3,
    0xD6,
    0xA1,
    0xE9,
    0x44
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseFSalts = {
    {
        {
            0x348AE5F17748D739ULL, 0xC3DE62C161E89076ULL, 0x50E9012B9D69DE29ULL, 0x150B55E75DFBE0B9ULL, 
            0xF22E1AA27CB74A72ULL, 0x0A05CA27F7CC6F39ULL, 0xD95AD7F377296CC8ULL, 0x8C28B789C5A8FDE1ULL, 
            0xEBC4069BE090F70DULL, 0x841524842DCEDBA1ULL, 0xA8394AC4570B74AAULL, 0x92FA002C92D99F97ULL, 
            0xC2BACD68F5335925ULL, 0xF6984E128845B420ULL, 0x2E0972ED197AC930ULL, 0x34E6FBFCA6EB2B5EULL, 
            0x623D4526A7654533ULL, 0x9F862D20AC823759ULL, 0x0EE394DEA2A9519DULL, 0x2A06D0971CD75B70ULL, 
            0x2E882B69097A223BULL, 0x64EE49B3960D52DDULL, 0x00D541E801431507ULL, 0x03065C6418B7D5B0ULL, 
            0x553B22C69E7ACD81ULL, 0xD2A1163CC242738FULL, 0x225B9CB10D49A840ULL, 0xE8B71B58CFE8FD50ULL, 
            0xD4848BC6EFC9017EULL, 0xEDA6557F3BE5B9ABULL, 0xAAA24FB0B22B5043ULL, 0x2F7ADCDD1B8A5DB7ULL
        },
        {
            0x9F1310ED98B36DDCULL, 0xB74F11BCCCFB8569ULL, 0x847480EB8C0F346AULL, 0xE122F6ABCE6F9F51ULL, 
            0x55DF1318872DB76EULL, 0xF0237EF71EF0415DULL, 0xEB7B98092BEC8F3FULL, 0xD91BBD1808D2545BULL, 
            0xC514573440F8E6A3ULL, 0x11F4058DDEA74EF2ULL, 0xAF3BEE9E2DBA4938ULL, 0x656D7F1D62BF5D85ULL, 
            0x98DF2747BD7B4AD7ULL, 0x4BCD48C59CBF428FULL, 0x9D3A7351CA70459DULL, 0x7C84906FB5306A1EULL, 
            0x69FCB55D14409875ULL, 0x8DEFBB6D02725E75ULL, 0x9FE263B27699C0FBULL, 0x0B4E35070F7CF615ULL, 
            0x2C90BAED851BF940ULL, 0x4D66ABF7F3069253ULL, 0x3CF7B18EEE02DAC9ULL, 0xE1703B950CDBE9ECULL, 
            0x8E1DDBC78BBC2B03ULL, 0x01056D152AF29824ULL, 0x31578D54884506BCULL, 0xBF8E91E9B6467805ULL, 
            0x553EAA02FA5CBEEBULL, 0x598A6FABC11CEEA5ULL, 0xA3A08C8F2FABCA20ULL, 0x9ACA61B8CBA7865BULL
        },
        {
            0xF1D0591AC9E51353ULL, 0xB886E3E12BF8F2B8ULL, 0x688091D66DF479BDULL, 0x767FD09572758C3DULL, 
            0x51448D73E1C45712ULL, 0xE018D5D3A0203D96ULL, 0xD6429562A700618EULL, 0x8A12008F7818E287ULL, 
            0xD7931234C13C9EC3ULL, 0x342D178CE20F756CULL, 0xD12AF036C0615DF4ULL, 0x285698860EA21615ULL, 
            0x977BEBCD24A5945FULL, 0x8FEBFA3B02697A64ULL, 0x10F28BF169620AA2ULL, 0xB97619221B42C612ULL, 
            0xCE8BFD9C5CDD752DULL, 0x43B35583FD0F1927ULL, 0xCE61F01DB98FAA1CULL, 0x4E7095A790EA5608ULL, 
            0x9831A9134DAA0FFAULL, 0xEA2C495CB9439939ULL, 0x05C82613EB939242ULL, 0x0F921B76F9616A83ULL, 
            0xAB172BFB988D09A1ULL, 0x3A7595613719E781ULL, 0xFA2DDDDD0FEA3BA1ULL, 0x8D3FA396B86281D3ULL, 
            0x523D97CF29392A72ULL, 0x535F642629406B4BULL, 0xF8C9A5F6E0DEB171ULL, 0x3CBEE039D4C23F40ULL
        },
        {
            0xD8870C5ECE2183CFULL, 0x6FAA3DF51B998FDBULL, 0xDF6EC36DDBD3ACC6ULL, 0x16E65D929F891B18ULL, 
            0xDC5A37594DA7B345ULL, 0x651D8A26B495FD21ULL, 0x45D7FB3C8299F8D4ULL, 0x58F64470B67CB796ULL, 
            0x0F5339A61116776AULL, 0xC8A19491E9252802ULL, 0x41E260E0B62D60EDULL, 0xF02C3A86A8298D76ULL, 
            0xE30A35113E6E14E3ULL, 0xC6C5701F574A92BCULL, 0xE9057C31E01E9184ULL, 0x4B88456E40EBD383ULL, 
            0x922C585EFF393ACCULL, 0x4364AC9C2FAB8740ULL, 0x4C77A1F0B9FDF700ULL, 0x9947B186661FD682ULL, 
            0x6A265F79C6CE06BEULL, 0xD92F99DC9C999745ULL, 0x14F0D75416456618ULL, 0x7A342A08F8D75A1AULL, 
            0x5B892486E019F681ULL, 0x329B38402E974985ULL, 0xEC23095F0EC6A7CFULL, 0x27D3C2DD238FB966ULL, 
            0x0999F739E949F383ULL, 0xA9EB2120B1B136C6ULL, 0x6A6272C1AA1315F0ULL, 0x4FDB8189A28C1602ULL
        },
        {
            0xAB8FD3ADAE790A96ULL, 0xA6E84D87665C3F78ULL, 0x3E4150AB97420141ULL, 0x2B26D9E0B071907EULL, 
            0x0EB629119F5BC10BULL, 0xA109B4646BDF6471ULL, 0x004703F5BA0FCCDCULL, 0x12543AD254AEEC1BULL, 
            0x924EBBCE96D59A53ULL, 0x07C979409CD5FF71ULL, 0xF7AB2927BFAA56B9ULL, 0x6E26DE660D2FCF03ULL, 
            0x6D5F5AF8F2C15F7FULL, 0xBBFEBE6FE8F171C4ULL, 0x400958CDC1C604AAULL, 0x12D22D3D80171715ULL, 
            0xC0BA975CD9DD8FF8ULL, 0x250D91C937CF8EE2ULL, 0x6EE319A20A9A8F62ULL, 0xB3E1D6E0631D99C0ULL, 
            0x4BE616D2C9F85C5CULL, 0x90D4739287CC6128ULL, 0x089BD8E60136EFEDULL, 0xD4C2633D89A64256ULL, 
            0xFAD039CB70674E30ULL, 0x55CCF3BBCE3FAD57ULL, 0xCC61F57B6A60CC4CULL, 0xCD1F8B97F62A743BULL, 
            0xEE59801B28EF43A0ULL, 0x85178D4F47440EDCULL, 0xD920C847B7BB3F94ULL, 0xCFF680A66974ABC4ULL
        },
        {
            0x7E52599E8F90E4C4ULL, 0xDAD3C52A35509643ULL, 0xE76F97FD8F4B608FULL, 0x5BFAA5ED6DE857E7ULL, 
            0x0C35B4E6A906BDA3ULL, 0xCB46E3D9020B9E54ULL, 0xB3BBF30652E03ED4ULL, 0x7A71E907EF9A07BDULL, 
            0xEF75C3D7B4EFFD14ULL, 0x34C756C908C13BF0ULL, 0x22FB0642435F6701ULL, 0x759A86075E8F6B19ULL, 
            0x5C7CBFA718B17C9BULL, 0x7935F3BB3D6FE7E7ULL, 0x3D4FB0A5664E1D04ULL, 0xACF3918945D55141ULL, 
            0x5191EEF462C6E3B1ULL, 0x36125A08DC353A79ULL, 0x43968136EF79DD5EULL, 0xCE8F88A23FBD676AULL, 
            0x0FC586FB88EFA3BFULL, 0x8BFF6C88C91E3C9EULL, 0x7F7F86B56B938CFDULL, 0x15F16E070088F230ULL, 
            0x44B567CA4CB46ACDULL, 0x33E4337B48C8CB70ULL, 0xD9676F83A3CBD522ULL, 0xA573ED7CE2B84D82ULL, 
            0xFF20E3812C00D612ULL, 0xAFE214DDAF461EC1ULL, 0xED0B4CC7B0CC2F31ULL, 0xBC9258A27AF256E3ULL
        }
    },
    {
        {
            0x10E32C12CB615174ULL, 0x01179BA1FDC39C5EULL, 0x06493B3968935CBFULL, 0x90C6F3E95BF8D1C5ULL, 
            0x0203CB59A52E4861ULL, 0x6A1B3419946F57C4ULL, 0x526CC89F09D16B95ULL, 0x74D3EB6F8AF93882ULL, 
            0xCD08CDE0AE051C98ULL, 0x8671564D0DA4C7C1ULL, 0x8435F5FF83A8721BULL, 0x65DE7CE4631FA14DULL, 
            0x3A6969028287CF27ULL, 0xC7E52696082DB3DEULL, 0x9AB0B7EE6C74623FULL, 0xD2B73EADD015CF2AULL, 
            0x40712AA936FB5F12ULL, 0xE529E30EB74EC089ULL, 0xD8142CE180CDBE43ULL, 0x438E85EAD54B8DA9ULL, 
            0x1FCFFBA807073309ULL, 0xD906DBCE6FB1B434ULL, 0xDA52F59A5A674D84ULL, 0x0D19BAB1D2639C75ULL, 
            0x7AF5F0C0625E4F9AULL, 0x0C9577F1DA6FC462ULL, 0xBA84A6D43CD9A69BULL, 0xA3DCA5ECE25BD9FDULL, 
            0xF07EB48CF13881D8ULL, 0x05B167645094DB99ULL, 0xFB118336403D513EULL, 0xFEA17C6DF12B80D3ULL
        },
        {
            0xF735426A5E4B1E11ULL, 0xCE619F2106C142AFULL, 0xF16936FD56304B79ULL, 0xB8C3571B748F436BULL, 
            0x9FC0C0D366BDDEA5ULL, 0x9290506E9C494D8CULL, 0x9DF7C6DDC860D4DFULL, 0x8C156B43CE5A2F29ULL, 
            0x9ADE0ADF12076D8CULL, 0xA618F6317070AE39ULL, 0xBB236504FB8F78BBULL, 0x63326BC6AC3C6DE7ULL, 
            0xF5544B79F2C6C482ULL, 0x6A22E3B25901D78AULL, 0x0B01E8675529C4E8ULL, 0xEA5EA3FA60A6A10EULL, 
            0x9ED79E2FD004673BULL, 0x1A445C63C6BFC276ULL, 0xAB1A7AAE88037F73ULL, 0x18C3CBABA7792835ULL, 
            0xFC00301F8F7A8BB9ULL, 0x192B8460988ABB87ULL, 0xCF4283787A7ED839ULL, 0x1B34DAF88A756DEAULL, 
            0xF455B93D0C43E2EAULL, 0xC56739D1B2B07306ULL, 0x486C3A1013019595ULL, 0x255EA268AE3FE4FBULL, 
            0xBD39DA696FD4C253ULL, 0x199D3CC5637FF64BULL, 0x098E9E7A34826332ULL, 0xCE8DC3228F8F2276ULL
        },
        {
            0xD66F865FEAEBA802ULL, 0xA534CD611B32ADD4ULL, 0xEC0EB199F7C2E3FEULL, 0x975E14D60EC70B7CULL, 
            0x8DF2204F241B7219ULL, 0x343430ED5EEB802AULL, 0xFDC1F7FA888EFD78ULL, 0x6FE29EB45461761AULL, 
            0xC98B895A3B4697FBULL, 0x18DCB2D168B87C4DULL, 0xC10FC6583FCC7558ULL, 0xD7DF19BB06B97AA5ULL, 
            0x63FDF18F171DEB9CULL, 0x50898657DA7BFF48ULL, 0x626E53A0D5FBC9F0ULL, 0x3567C14B436D4666ULL, 
            0x5FD84AFC9555BD18ULL, 0x2A622941E3738766ULL, 0x27B3C31F3A2BEF15ULL, 0x5EA8FBF05DA7F756ULL, 
            0xBC14E5F21DF72F01ULL, 0xE797F210C84C64A8ULL, 0x0C23C08B866BA5FAULL, 0xE1B1B3E30C5DE4F2ULL, 
            0x43C96C29406358D3ULL, 0x56E2411ACCB60598ULL, 0x62DC35B0B09E1235ULL, 0x33EBA0BC4035DD24ULL, 
            0x80CBD269B5D3F0BEULL, 0x4271000B801FA4C9ULL, 0x0FD3943B7393593EULL, 0xDF5CAF273C502C88ULL
        },
        {
            0x45E4677308ADCF4CULL, 0xFA6BC6E897C293A6ULL, 0x3C525D249B98E65DULL, 0xEB68E0604C4CE589ULL, 
            0x730940C4F296EA42ULL, 0x0932DA81624AE04CULL, 0x648D152FDFB7A918ULL, 0x687FF43644C0544DULL, 
            0x0D219FBA00DC351DULL, 0x9D09004A5C41DF8FULL, 0x5FC647E900A5F3A2ULL, 0x9529ECC7AE31B58FULL, 
            0x787C4BCB865DFFADULL, 0x2FF415180C6F3123ULL, 0x7D0200731FC53B23ULL, 0x46681D5C409F022BULL, 
            0x0E49003EF56FE181ULL, 0xB6092F004CBF5287ULL, 0xF8CA108D67BF637AULL, 0x8D3B94DB7447E99CULL, 
            0xE157F6319AC8FC9EULL, 0xAC747CCA602CF090ULL, 0x60E46C90CFA74573ULL, 0x2C31C6852D8371E0ULL, 
            0x490DCD216D3F6E97ULL, 0x6E528AF82F32C2BEULL, 0x911D8DE05B9B7E69ULL, 0x0FC56972328AA6B4ULL, 
            0xD9F2A214CF763AF4ULL, 0xCC524B3E7F3FE0FCULL, 0xD6C55D7DFD5A32FCULL, 0xAB8CC2053727AA09ULL
        },
        {
            0x5E87F38A6CFBE00DULL, 0xC762173801E868FCULL, 0x159D8D424C3EBD9AULL, 0xF097C7CDDC024A9DULL, 
            0xADABEA47C3702C92ULL, 0x7A675DF12AF70DA1ULL, 0x68B535693CF22FD1ULL, 0xA65DC9913AD2D14BULL, 
            0x9BE7F03EF7A2530EULL, 0xBBCC24B28E3F6968ULL, 0xC6C1D264D23E7AAAULL, 0x4DE7E78B3F66D9CEULL, 
            0xEAE88E96BD39C0C7ULL, 0xDF3B7BE94FCF3014ULL, 0xB72F3F7F602FD9C1ULL, 0x9F44CE59D2A11EC3ULL, 
            0x33ACB3B277A50404ULL, 0x7BBB03A18C8C1DB9ULL, 0xE5A82C72585A7626ULL, 0x97B405BAC89734A9ULL, 
            0x389606CCA2943C35ULL, 0x9CCD00104E2C60B0ULL, 0xAB8DD0AF9BB246FFULL, 0x74DAE8296D6A9817ULL, 
            0xFFF3DE98ED7D1DEDULL, 0x2B0F0F06643F879BULL, 0x99CEF56CD38EF32DULL, 0x4FD0505C434F9247ULL, 
            0xE8076BEED86F70C7ULL, 0xFEB2386D0D96AFB2ULL, 0xE40D3270A6158486ULL, 0x551D8D04AE19B89EULL
        },
        {
            0x1B01A3C184949D53ULL, 0x058EBE0BEE34C4B8ULL, 0x17F19F55165D4372ULL, 0xC98A0536BEFA017CULL, 
            0xCEE07C49B5913281ULL, 0x8D311E39D54079FDULL, 0x413CE7881D239624ULL, 0x81E16B2FF0304268ULL, 
            0x244C6B79179C08EEULL, 0xE85E32BCFD6C5441ULL, 0x44DF3274B112A2C9ULL, 0x3470195D12673328ULL, 
            0x3F480685883C7308ULL, 0xECED6B0C5C55C9B0ULL, 0xCE1298110654D9F3ULL, 0x5B9B030521DA8D09ULL, 
            0xD0526CCB2110E478ULL, 0x352717618110A0B2ULL, 0x5904C3C91A1629A5ULL, 0x0BFD39C060880ECFULL, 
            0xA1290B161350646BULL, 0xECB97CCB172EC87BULL, 0x876167D65F541D62ULL, 0xEFE446311081CFEFULL, 
            0x77E50B23203716CDULL, 0xCDDFA4A5C69BAC69ULL, 0x7F3E36989EA00ACEULL, 0xFD376655F8694E89ULL, 
            0x70716FA7E04E00DEULL, 0xAA4307285815BE5BULL, 0x8F19344A1BA362B4ULL, 0xE31BDD1785EE7856ULL
        }
    },
    {
        {
            0xC27818B17C89AB64ULL, 0xF74DDBF778C82890ULL, 0x3F4884DAD6269778ULL, 0x553DD2515ABCBA66ULL, 
            0x25DAB9DAC79DCDD7ULL, 0xA06CC7436B37A9D9ULL, 0x670A4717A6D20565ULL, 0x1338EE05AECC9B72ULL, 
            0xF85119553B9ED4C6ULL, 0xA83FCB0366A158D6ULL, 0x4E01727060512884ULL, 0xAFCD953C0055E60EULL, 
            0x2D6F73519EB3361CULL, 0x599029B67FB0EDF2ULL, 0xE2C9D882E9349175ULL, 0xAF5A7B3F489B0A61ULL, 
            0xB456D73B5F7AFEDFULL, 0xC29D0DB1961E42C0ULL, 0xE4C030F98642B2C8ULL, 0x44CFBD5220BB0CB6ULL, 
            0xE3B4238735EE24A2ULL, 0x14A764A783802111ULL, 0x60F452D2DED4D67FULL, 0xED7949947FAC6E16ULL, 
            0x4FB9962C37F84BEBULL, 0x0AFDB57BE87AA39BULL, 0x9F45429DC20C2C35ULL, 0x5E3CC509E73F8770ULL, 
            0xF5F93EA81EE23CE9ULL, 0xD8EEF9ED6ADA938CULL, 0xC1FBF75DD6FDC2DDULL, 0x5823D2EC5B172289ULL
        },
        {
            0x9F07173ADBD94C84ULL, 0x0E79768CF342002BULL, 0xC0615B7E0A5106C3ULL, 0x838120F0A7757774ULL, 
            0x6886655614FC08A7ULL, 0x7F1D73356BDDBD3EULL, 0xBE3C7C55D0C3BEB0ULL, 0x7F04102A3AB11D4EULL, 
            0x73D89A69313289B1ULL, 0x3AA8C34D48DB0B1AULL, 0x8616141F9E68CAB5ULL, 0x4D86724A24DE1372ULL, 
            0x57655F82A42CBF6EULL, 0xE65F5F5623621C7BULL, 0x3C8B54DB26CEDB48ULL, 0x078CBC163740E8CFULL, 
            0x2C7605B2AAF970C9ULL, 0xB4C2EB86EE482BF4ULL, 0xC81F38FC36E9C61EULL, 0x5B0FC26572809D4AULL, 
            0x80DFCFB5813E2B56ULL, 0xF1D10A409C07CB96ULL, 0x6C7EE6C50001A277ULL, 0x96244CB6B9D79804ULL, 
            0xE87E2C48440F003EULL, 0x44D271DFD718C1B1ULL, 0xA0C73E13A2818951ULL, 0x3DD68CCDC30FD796ULL, 
            0x2E56C27C5588A1EAULL, 0x622F6D42B70BA77EULL, 0x106A61F84B3C61E0ULL, 0x70AF3D70A8DC9116ULL
        },
        {
            0x1CE810339D063394ULL, 0x114C6FB918B7CAC0ULL, 0xAA21F8A6FA62E8A3ULL, 0xF55CFD1619734650ULL, 
            0x7E53E8BB5B121A90ULL, 0x7A09822D5A61B148ULL, 0x5ED5E93471F1F5EAULL, 0x4AB7400FC03DB128ULL, 
            0x55F72CB31A49F57EULL, 0x2A1525807F642236ULL, 0xB2E1C3C0EE47D57FULL, 0x9C5AA3AA04E106D4ULL, 
            0x001AC90A55E2C396ULL, 0x0B8BC1357844CC9EULL, 0x6D6ECF7E90A89238ULL, 0xDA51464BB8B408B1ULL, 
            0xA8A71A6ECCA4DF91ULL, 0x06FD31330AC3DDE4ULL, 0xDC5F0CA56E64EF97ULL, 0x8A22E7442CD61EECULL, 
            0xF9C004E613A59E35ULL, 0xBA42834B2324F627ULL, 0xCEEA900FCECBCE36ULL, 0xE2072C8C63230BDCULL, 
            0xAE6A50089BDE39BAULL, 0x8A21C0D7B8D2B5F7ULL, 0xDCFD5EF9689076F8ULL, 0xAEBC61B4B0872E4DULL, 
            0xD664D56D983D155EULL, 0xDFC2DFF9B50C6D50ULL, 0x06C6BF3C7C942181ULL, 0xE3974E838CF70784ULL
        },
        {
            0x92E2499DD2CE06DBULL, 0x1EEE9BB834A733C4ULL, 0xC01CD3AFE635C40AULL, 0x82D70A78A00BFADEULL, 
            0x67E7F8B35344D2FEULL, 0xC7BBBD7D8F874709ULL, 0xF30882C410F811CDULL, 0xC096D1C4BD818A2AULL, 
            0xF857AE5806E2578CULL, 0xD115B59591AF64AAULL, 0xD10D15011AB09ED7ULL, 0x13D1BBFA55BC4478ULL, 
            0x2261B3222A8BAB9EULL, 0x4A334C0C06EC47B9ULL, 0x5696B8EB47B58B96ULL, 0x8FA11B6C92BDFA6FULL, 
            0xA27D361D5B366C9CULL, 0xBA44CF95781D5603ULL, 0x7B2486D415AAD87CULL, 0xBF9D8316F1A31A88ULL, 
            0x1BAFB6076C2F6B2DULL, 0x64C4D4DF137D1A1BULL, 0x57ECE09CF8FAEF57ULL, 0xCFFB519C14DED8E6ULL, 
            0x7DA18CF842B56756ULL, 0x20FF00054C3C1717ULL, 0x51DAA73DC4901895ULL, 0x13BCEF3A6A37B62BULL, 
            0xE12757CDB96A2291ULL, 0x262B683C8DD2C436ULL, 0x47478384A928C6A1ULL, 0x4957781DC33BB7ABULL
        },
        {
            0x61DBB2CE3E1CB11DULL, 0x44794251BABF2666ULL, 0x3A04FD16AED231A0ULL, 0x36CEA89B3809F095ULL, 
            0x34FBC9D56B228B55ULL, 0x2CBC2695AB90EF84ULL, 0x1938F8CED98E87F5ULL, 0x13BC8AFBCB016089ULL, 
            0xEEC5545E9436AF39ULL, 0xED70207803D542D2ULL, 0x82FF4ADE28158CCCULL, 0x9B2DD043FB38943CULL, 
            0x65CBBD85ECB0F9D0ULL, 0xD426956752358532ULL, 0x6EB37030D30A8F0AULL, 0x461F9A7EAAC6F4B0ULL, 
            0x084AD72D3F24A22BULL, 0x2BC7E8E186D80D0EULL, 0x803F54A59B84EE81ULL, 0x999EEF3B8A9DBFB8ULL, 
            0xD3F4C29DE58AEA2CULL, 0xE6353A7E66CE1925ULL, 0x34052675EA78D7A3ULL, 0x155D9F9AC4DA525DULL, 
            0x9B0CEC48B0CB3876ULL, 0x0F1D07C39FF2BD9EULL, 0x12E971AC2D4213E7ULL, 0xBAC64F8B24F68DC6ULL, 
            0x48E0801275845E36ULL, 0xCE63DD42567B18C3ULL, 0x8C1B192F4261BBDDULL, 0xA2FF0F1645D3322FULL
        },
        {
            0x9EAACA11896EB72DULL, 0x83B47B2D7169CEC9ULL, 0x4A1EF2B78C5FC89AULL, 0x06CA5DA83FAD6A3DULL, 
            0x4168ED3FB9BFCA7CULL, 0x5229FAE4DC119F9DULL, 0xF716070A8F11CC2BULL, 0xE9163C104101A282ULL, 
            0x9404305F8205B63EULL, 0x8703C0E187D2DB08ULL, 0x154D6D502F5E6060ULL, 0x95723A68D9AE63DDULL, 
            0x1F385B4E2114F674ULL, 0x225BAA91B530C478ULL, 0x448897C43D8BBC1FULL, 0x67524EE9190A0674ULL, 
            0x11A11E30E7EAE6CEULL, 0x57B0145FAD90E409ULL, 0xAA59BBAD6279471AULL, 0xF9402113C5C31E28ULL, 
            0x2F13F79152369EBCULL, 0x45F8DE20775922C4ULL, 0xA762616D3B138032ULL, 0xAE55D4D5FD975D13ULL, 
            0x659118EFA0CACE64ULL, 0xD1840086F562C5F2ULL, 0x5386B6CF6B1F3F65ULL, 0x27147B151336E918ULL, 
            0xABC7BFE8DE46EDF6ULL, 0x1AD3BB7C1168AC20ULL, 0x3E148A8078784AF0ULL, 0xEB391F6CC9E4C9A6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseFConstants = {
    0x1CC835937D9D714CULL,
    0xB1BE3FDFAEA5C604ULL,
    0x4FBB2126D6325CB9ULL,
    0x1CC835937D9D714CULL,
    0xB1BE3FDFAEA5C604ULL,
    0x4FBB2126D6325CB9ULL,
    0xF32E57D26A46768EULL,
    0x91AE8C70AA0AC2F0ULL,
    0x9D,
    0x73,
    0xFD,
    0x74,
    0x4A,
    0x79,
    0x77,
    0xFC
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseGSalts = {
    {
        {
            0x5E80E785E56BD81DULL, 0x1902AB2DDCF2D569ULL, 0x328FDA77720E51A1ULL, 0x3134E236742CD97CULL, 
            0x045397035B4D1EDEULL, 0x42D6A1E4CC55F135ULL, 0x44642C261015BE05ULL, 0x2DC954062D7DB6D3ULL, 
            0x499D51ABBBD24EB8ULL, 0x4911435289A3BC7EULL, 0x607F8DC8D28C4054ULL, 0x8BC82D9C9D735D39ULL, 
            0x7F97B6B8657C851FULL, 0xA99825EDF0735AE5ULL, 0x5236891BAACFC694ULL, 0xEF1FD2CE34A2A753ULL, 
            0x1CA2C85BFD37C950ULL, 0xB529EC7A19855A76ULL, 0x391911C66B888E13ULL, 0xCC4C6A3CC0D143F5ULL, 
            0x74A4929124F2F995ULL, 0xDCBC6E1033EA05C2ULL, 0x597A0CFCE657A01CULL, 0x22592F31F189BE41ULL, 
            0x6665E1E7A188AC2CULL, 0x46C9CE6825C053CEULL, 0x204A4FA677381F9CULL, 0x7A6E316602C29A7EULL, 
            0x3CA0C640C6F37848ULL, 0x647B5AAC6B8C6DEFULL, 0x0AD41D1EAA2520C2ULL, 0xE3ED876D694BE2C2ULL
        },
        {
            0xB5C3DD1BDC9CAC2BULL, 0x76A7F2F5FD41E916ULL, 0x7434FDC90BC47ED6ULL, 0xD7D204DD21A05161ULL, 
            0x7777033501435A6EULL, 0x750DE0B8033892FBULL, 0xACB1D95D480215D4ULL, 0x7F9A6F06C53E18DFULL, 
            0xB53557195500245FULL, 0xC21370527E35C623ULL, 0x38985850014C334DULL, 0x674FB4D018685713ULL, 
            0x03C8A0707E401C4FULL, 0x3342E41B60A85755ULL, 0x2FF9365BCAF2A855ULL, 0x884E8BDFC0EE6814ULL, 
            0x6EB97A8E4899E76EULL, 0x2E66F6781DF8D2E0ULL, 0xE5A3D9CCA6C30924ULL, 0xEFDD3E38B16BBD54ULL, 
            0x908F17CFE51CB945ULL, 0x63A49D842C98B841ULL, 0xDBF60F9D178A3731ULL, 0x67D8A0E31A236089ULL, 
            0xFEBACB36049DA7BFULL, 0x2506C496C21CFB6FULL, 0x65F782BDA454628AULL, 0x8FABA8E90FBF9FD8ULL, 
            0x8A8EB1779FA61D3FULL, 0x629AAA73D7BC20A8ULL, 0x883C4B59DDD878FCULL, 0xF89AC64685B6C927ULL
        },
        {
            0xF9AE07B4DEEAF473ULL, 0x8F8F07DFC083203FULL, 0x7CC1043B419843DEULL, 0xAF5D3E15F1C10FE6ULL, 
            0x367FF0AD3544CFB4ULL, 0x97398ECE11C534C1ULL, 0xD791B3A61DEDDD31ULL, 0x475AD17D2926B0E4ULL, 
            0xB2F728685107C65DULL, 0xBF81E773188118EBULL, 0x3A941EB97B959C4FULL, 0x37DEF74C7D0D36C4ULL, 
            0xAE763F04BC040FCEULL, 0xC459F109D5EBDCCEULL, 0xDC7795F4F3D0D942ULL, 0x490B7CEC7508009AULL, 
            0x09EA2E310C8EDC48ULL, 0x8E8004FB2239029FULL, 0xAC74A81BFEE237E6ULL, 0xA84046AFB545A5A6ULL, 
            0x13E0A391109CD752ULL, 0xA5F88C01E01D5550ULL, 0x32DD5983898FB50FULL, 0x0FFBB2447C7F8A9FULL, 
            0x9DB1DD115AD2BB44ULL, 0x88F46A8D236794D4ULL, 0xDC615CEA346EC2BFULL, 0x32BA08091F3AC5CFULL, 
            0x3637ED8F3E54C864ULL, 0xCED6261FECD2BE42ULL, 0x1B222A40E2E45AA7ULL, 0x829D163EA359C1B1ULL
        },
        {
            0x643CFBEE266EA469ULL, 0x751D21809ADA9369ULL, 0x68C528DA6466DAE1ULL, 0x727BCAC198209307ULL, 
            0x0BC3B32B2E270BC3ULL, 0x9AE024D2C7E96B73ULL, 0x2C64E87934AF143AULL, 0x74E72411510110A1ULL, 
            0x44A3B75B3176DC93ULL, 0xDEEEA32D766B4309ULL, 0xE1587E91DA0D69AFULL, 0xFCC6B060FA3098EAULL, 
            0x1761D3814C45379BULL, 0x23E9D4C0B52B27E5ULL, 0x67B3AEEFEEDA3E35ULL, 0xBE7C312A9F754897ULL, 
            0x504CEC19A2BF60F7ULL, 0x6D9A8D058BE45050ULL, 0xAFB9784BEBF06D69ULL, 0x724A49CFE7CE05F1ULL, 
            0x08EC135B1A4F6746ULL, 0x388EC54B7256D30FULL, 0x39B7579D0BA973A1ULL, 0xA4ADBCB47B97561CULL, 
            0x8D7B351D898A31F7ULL, 0x3AF17F54182E9CFCULL, 0xDE713C13B1C273D8ULL, 0xF70F2A1847B446ACULL, 
            0x0C8B30B2F4DDE14CULL, 0xC19E8F0280BEFC54ULL, 0x870FA2E3C79C1176ULL, 0x3D08A36785427EFFULL
        },
        {
            0x7EB4EA91AF8304D1ULL, 0xF8DFB8E066288A21ULL, 0x38B5FC0068F2BCABULL, 0xAD96B61832E06A68ULL, 
            0x2D61BB5897F025DEULL, 0x7E5E280BAD80E8B1ULL, 0x8F8C478B52DD0B94ULL, 0x90D9545DABFA9F29ULL, 
            0xAB8E3ABC89DCADA1ULL, 0xEB617D60C0C7CE97ULL, 0x4C36177B4AED249EULL, 0x7E10567744CF2C5BULL, 
            0x9BF97AAFB3791C70ULL, 0x488A7F30985B4CD8ULL, 0x85A8962E44ACA2FDULL, 0x90FD4FF8A3072EF5ULL, 
            0x5664DB100008B75AULL, 0x5B5A37913314C86DULL, 0x907C1D6DDE7EDB2AULL, 0x031D263991990048ULL, 
            0x2B0E574522349969ULL, 0xB005FE67FC4A4D0CULL, 0xBA81FB5568AFC74DULL, 0x64D2E6B11378D481ULL, 
            0xBD2F9F11A2307BDCULL, 0x1C4AAB39CB18F9BEULL, 0x57B980B141D96D8CULL, 0xE82D001FFCF85944ULL, 
            0x3850DDE860BDCE53ULL, 0xAC5993378DA18D48ULL, 0xDDF0106195CEA04FULL, 0x2581DD3698C95987ULL
        },
        {
            0xE87049316A55AFB5ULL, 0x72CC92D29CBC7AB1ULL, 0xF389069343BB4045ULL, 0xAE3A55AC20EC59F2ULL, 
            0xCACDF4434766B401ULL, 0x1E10FBD4A81BB20DULL, 0x02B61F6D94AA3C63ULL, 0x01CCEB7AF74C87FBULL, 
            0x336D701ADFB9ACDEULL, 0x51A0405D776E92B5ULL, 0x8A572883D93C4AECULL, 0x6C20EEC59E1B2255ULL, 
            0x26FDCF870D57F205ULL, 0xC05235CEE1E7128BULL, 0x961413A2AE9305C9ULL, 0xDA6AD69F97F52E2AULL, 
            0x3E1768EF46D29526ULL, 0x07C6E9A79FCF72F0ULL, 0x647A5B39504C61A0ULL, 0xDE5734E692FAE465ULL, 
            0x2FD49B8245EA75C4ULL, 0x289251CAA555DE6BULL, 0x8747F6CF34552423ULL, 0x84D2EF669A9C0339ULL, 
            0x85D33CF74AAC6C69ULL, 0xA8A652AB35A8AEB2ULL, 0x97A10F165C09643BULL, 0x107D8094CD38711DULL, 
            0x2278FB6704854A70ULL, 0x9E421A08228D03C8ULL, 0x0959C97F0EE1051FULL, 0x79D6421D10F1B93AULL
        }
    },
    {
        {
            0x317C688AC89A6D46ULL, 0x44031BF96696B0BBULL, 0xBAE0DF7ECF228C64ULL, 0xD1E60490D667A526ULL, 
            0xD508EDD4C8DE1C43ULL, 0x431F6F94BB5F12A4ULL, 0x73E2D8ED1C7066F2ULL, 0x3ADA4F2D3D9F7840ULL, 
            0x3741547A2776EC57ULL, 0xDFE28206B2B73230ULL, 0x4E87A523DA9B0B77ULL, 0x39EBDA849B360B18ULL, 
            0x28B6646D89E4665AULL, 0x6C36B8D7F6EAEF35ULL, 0xC42DAB9BCBA06DF4ULL, 0x2D1160E42DF7A3A8ULL, 
            0x29DEE182B6BF0D7EULL, 0xA1F455367E044A2BULL, 0x2E3687023B67C435ULL, 0x08C0D80E3029606AULL, 
            0x158D584833922ED9ULL, 0x714546EBC517D589ULL, 0x0CFF8802CA30699EULL, 0x5E727E6DD7ECB6E8ULL, 
            0x459D7EB3DCF14765ULL, 0x8B4B2759D590621BULL, 0x9F3B6CC5E6224129ULL, 0x6067EC7A1DD4C1B8ULL, 
            0x4863B62D78E5C244ULL, 0x5C170E94619F1301ULL, 0xA80EDD9BEA7E4479ULL, 0x95E717308A35F33EULL
        },
        {
            0xCFF68DABB4DAF9F1ULL, 0x64CF3E3A208BFB76ULL, 0x644ADF5F7386F7ECULL, 0xA4707994939E432BULL, 
            0x9ECE27F623054B16ULL, 0x4618E9064F39DFF6ULL, 0x1B59D3855D579BEDULL, 0xB7B93A4CC273ABD7ULL, 
            0xA0739CC119DB14E8ULL, 0xE81E2080A4323F78ULL, 0xC533905222AF9E13ULL, 0xB000E583A48D659FULL, 
            0xD741D63DCFD176E9ULL, 0xA3A468EFBF0F855BULL, 0xF009A9FEB70931E5ULL, 0x9408BC4704AE406AULL, 
            0x8B3F3563F2DFE7ABULL, 0x349EC40126F2F75AULL, 0xE177930D8B04BF46ULL, 0x516ECEF601712FBCULL, 
            0xAC0EE733A42CACDDULL, 0x283C732B9407C604ULL, 0x9EDB05D9385DA6C3ULL, 0x875F7B18A5729B1BULL, 
            0xF814FFB78DFDCD1CULL, 0x27C309206848206BULL, 0xC9956C90173994BCULL, 0xE3A7DFD8E66AFBCFULL, 
            0xAB60EB0B4D98E91BULL, 0x14FEB8AC20A05346ULL, 0xA2F41B94AFF5F064ULL, 0x7746770169B86553ULL
        },
        {
            0x0C5825CE2C0431AAULL, 0x22300DD2845C50FFULL, 0xCD5A96164989F3B1ULL, 0x1F7C31A7C5ACC374ULL, 
            0x8E6B26A076FDB71FULL, 0xF187FFC5EB77C926ULL, 0xE8FF03896D42C76EULL, 0xF150BAFDB7175FBEULL, 
            0x25752236CA00475EULL, 0x0A3560DCA39FB43AULL, 0xA1440C10CB99D448ULL, 0x07B54D495CE7358AULL, 
            0x626FDFFC59C91C5FULL, 0x80000FB4F676872BULL, 0xB7906948D92B0D13ULL, 0x4E65AB90F01648E0ULL, 
            0x02B8CEAE0D8576ADULL, 0x2933F0CEBC6D0FE4ULL, 0x685978626D73806DULL, 0x420190B866FC4F95ULL, 
            0xA58B4ADB68680293ULL, 0x5B1EE4D684E992EAULL, 0xAA710FE45810A7A4ULL, 0x440A78EE25EEAA26ULL, 
            0x9795933F68201EFCULL, 0x00BCC90031FEBB39ULL, 0x2D531A55C0A7A859ULL, 0x61224607220B54CCULL, 
            0x2C09D338265C84B8ULL, 0x35E7F0A1C617FCEAULL, 0xCD2F9D8D2E731DFDULL, 0x6BE6960505596D11ULL
        },
        {
            0xA44084A715E1DFDCULL, 0xDEC3117085B07B29ULL, 0xE1E1CC6C19467BADULL, 0x516ACD3F15E35C99ULL, 
            0x8446FF27E55060EBULL, 0xC1279C36F0E49859ULL, 0xEC7AEC4BBDB14602ULL, 0x7299CD2F2A7929BAULL, 
            0x27F765AEAC86E02BULL, 0x6229AF682D867BCBULL, 0xC539BD9D62D1236DULL, 0x869FB8A405B24226ULL, 
            0x3EB62AE1C6A9E91DULL, 0x3C7023018B701F51ULL, 0x660F0CD2C7800933ULL, 0x95B2B2A7462CEF35ULL, 
            0x61E1951EACEB8E06ULL, 0x7F8CAB2354327284ULL, 0x68B275E595018754ULL, 0x9E7F90A9ADEE90F4ULL, 
            0x5C8ACD731115EE36ULL, 0x9E5478AD3A91D99BULL, 0x12D01FDF034C468CULL, 0xE5F2406E2547713AULL, 
            0x82B5B9F527DEB8CFULL, 0x5B3CB55E184CE722ULL, 0xFA1D19AB03C09B72ULL, 0x5BC566AD9EF35676ULL, 
            0x0954A17BA1BCEBF6ULL, 0x7CC97B109BC908DBULL, 0x92089D310AB282E0ULL, 0xF6252C4FDE2DFAE9ULL
        },
        {
            0x8A6765B9FA7A43A3ULL, 0xC064556031E2ADF7ULL, 0x69A4BAF40032CBD6ULL, 0x798C8D51EFDB50BFULL, 
            0x79F0839356C508C3ULL, 0x677677FC296CB374ULL, 0xA1FEF585A7998A86ULL, 0x253A56E08B7C9BBFULL, 
            0x156730F2DF22E42BULL, 0x0DB1E956223CAF42ULL, 0xAB52A1A6842367F7ULL, 0x59856B8B958A3486ULL, 
            0x1205C7A331E10D49ULL, 0x2C2C5E51D42F94A2ULL, 0x18F357E6BF2B2615ULL, 0x19B79C6B3162CEB2ULL, 
            0x4E0F3F2341ABAD08ULL, 0x42232C6C0915F729ULL, 0x3B8E8FC4E6F7D322ULL, 0xE51727342EF86896ULL, 
            0x92378697B8FB58EEULL, 0x2D177A84EDF4F8B7ULL, 0x2E17FA59A342C94DULL, 0x66C5CB20DC85166DULL, 
            0x32C23F889B0E62F2ULL, 0x000729EA211F8501ULL, 0x9517A2D8552EEA59ULL, 0x4CB9F2BFD788CD8BULL, 
            0xAB2440DA539E22E8ULL, 0xFA8A7652C1E53791ULL, 0xC2F27B6C9D28E6BBULL, 0xFFEBC1741E93981EULL
        },
        {
            0x6989579DA7F8A00DULL, 0x83B036CB23D960DEULL, 0x631B5010810BE01AULL, 0x7CFD279A1EE6A83CULL, 
            0xD4CA8FADDE33DBC1ULL, 0xE83D3B5825FC9D28ULL, 0x861316C8BBF37C86ULL, 0x90B99DF026A674A4ULL, 
            0xD0A7EBAAAEFF149BULL, 0x61C072CEE30DC257ULL, 0xBF770013556CA7ABULL, 0x6D0D0E2B24FDEAEEULL, 
            0x2D72E4825DDBC066ULL, 0xE02EE4285ADB86CDULL, 0xAC583B3D16DE4EC7ULL, 0x0A366E3EDD9045B3ULL, 
            0x9097951A24004B78ULL, 0xAB9E34D17EA105A2ULL, 0xC6DF8595ADFEBE09ULL, 0x30D29E4839EF06FEULL, 
            0x764A7898C0F55C61ULL, 0xB233D1D4ACCF7B47ULL, 0x1D1F7EAEC3CC63DFULL, 0x0963CA5460D4EF59ULL, 
            0x2E4FEEDC3BB7B13DULL, 0x51762824086F2638ULL, 0x3D9EF0A1FF867BB2ULL, 0x917FD59F94C12C6AULL, 
            0xDBE7FC89D2F7D6D6ULL, 0xD24C6A2AED8EB6F9ULL, 0x76061EB1D8BB1814ULL, 0x30A82DBD17D7E54FULL
        }
    },
    {
        {
            0x22CD19EA04AA9434ULL, 0x931B5B22E6E01CE7ULL, 0x94262006E65E8EC3ULL, 0xF2348F6BE186837BULL, 
            0x9E779373655BF8C5ULL, 0xFE4ABA582C67EF16ULL, 0xB2C6283757AF6992ULL, 0x43872573E4E523DFULL, 
            0xA926199C66A4221FULL, 0x4093768E9E01C817ULL, 0xAFFF08F4F9D9B787ULL, 0xCE1512823D444377ULL, 
            0x819E81C828173074ULL, 0x1A44E86D21468E94ULL, 0x855CEDBC1A00EF82ULL, 0x88805750A15269ACULL, 
            0x79B6082FA6A3A4BAULL, 0xB22708170F6DB627ULL, 0xC3BBEFD3F6401EE0ULL, 0xA81B55DEF76BD3F2ULL, 
            0x5A901FE697BDD9A8ULL, 0x6F2C73851C8215F7ULL, 0x95E074B9286A581DULL, 0x387DC5CC78C03D55ULL, 
            0x3B0B7F608A623B5DULL, 0x7D0CB0CA1EF2DBDDULL, 0xB7A442B0AF725D4CULL, 0x7267948BE5ED5427ULL, 
            0xB1FC37FE3425BE4BULL, 0x2EF2F3CE708F928BULL, 0x5F302DFD142F9F9AULL, 0x66E8DBBF3F6A21B6ULL
        },
        {
            0x00230510079642E3ULL, 0x03A5CF485282002AULL, 0xCF18E845F5BA9A34ULL, 0x5FB8F59FF452E325ULL, 
            0x6472374046421F64ULL, 0x320B78121B8E568EULL, 0x585B433D4C08DECDULL, 0xE0FBCA44CE6807AAULL, 
            0x147BCE68201BAB43ULL, 0x69FD7BA40C54D3ADULL, 0x44DA5EDBED66061BULL, 0x46ED3CBBA374EB6AULL, 
            0x34CB9AEA495FB0BBULL, 0x3F4787CA6919AAD6ULL, 0xAC78ED5EE4FD0FDDULL, 0x58DBAA9902CC4EBCULL, 
            0x900145D260027B26ULL, 0x43A74829858BB2A3ULL, 0xC35F66017BCBCCC4ULL, 0xB64067883E15CAF2ULL, 
            0xC12A8EF792BB0958ULL, 0x927465D47ED3C5FDULL, 0x38DB7E6A3E69191CULL, 0x9E3C50B9457AADAAULL, 
            0x9E48C33CD38EA337ULL, 0xA83BD04F73E3AADEULL, 0xAE314F62C1E63C37ULL, 0xF120BCFBDA54CA9CULL, 
            0x1F0B0BD3929B91F3ULL, 0x3640E166905D59F0ULL, 0x0B571DF81D349D57ULL, 0x2C69B33D511C99A6ULL
        },
        {
            0x751563D0D5FF22E2ULL, 0xE816372DE3A414B9ULL, 0xCA84F8EFE8E47297ULL, 0x8F0B04AFFB9577DAULL, 
            0x256C1E56E51D66B9ULL, 0x9D882101F737EC03ULL, 0x8560EC9B1576DAD5ULL, 0x7116EB7E80941D12ULL, 
            0x518E0FA5B1FCF481ULL, 0xE476E992609E779AULL, 0xB0BCF3B9C70E3D98ULL, 0xEA50255F9A9E3AFFULL, 
            0x586B8E7527711F04ULL, 0xD3B688A7EADB19BFULL, 0x8AD19677D4793819ULL, 0xE590766E3E5B9CAAULL, 
            0xF92D124EF4D56535ULL, 0xF616EC0043200127ULL, 0xA92EBBD92633D888ULL, 0x9AC790CA073CC6A1ULL, 
            0x673CA6415C3FFA75ULL, 0x9E2BC2C26A026291ULL, 0x63146FE6335B3B35ULL, 0xADAF27F0A6407971ULL, 
            0x119E56E58BCDBA2BULL, 0x9406375234FE998AULL, 0xFA13FBA390CD42E8ULL, 0xE1ACAACC181B26D8ULL, 
            0x5BFF36572E94A522ULL, 0xEDC13E8C516B2EF9ULL, 0xEB0897116647D696ULL, 0x48747DB582251CF3ULL
        },
        {
            0x6E8E90371C25AC47ULL, 0xD3A610B457EBDB43ULL, 0x33EBA5EB23C806F0ULL, 0x9511E53AB5CEFC51ULL, 
            0x86BD3FB4A4E88766ULL, 0x62D0FE4244CA7DF3ULL, 0xF8FC4EFDD36B372BULL, 0x155B08EE150C9960ULL, 
            0x2A3BC3F899C9DD75ULL, 0xA9C55136D1579035ULL, 0xA8AAD260DCDB4FD2ULL, 0x63F317B74BF5AD2FULL, 
            0x1986F5273D496F3BULL, 0x457AE996B376BBC2ULL, 0x6B6AE5FF98FDC299ULL, 0x73BBB5C4CDF4F922ULL, 
            0xD61525C7128A03C4ULL, 0x8E69D3D85217EDBAULL, 0x9C853BD7324A97B1ULL, 0xB72C433E797BED0FULL, 
            0x5FE72D5205A078DCULL, 0xBFE6C9E2C2A330B8ULL, 0x55DE8EF7FB77EC83ULL, 0x3ED138DC8A57FDA2ULL, 
            0x8978BC51A0E12675ULL, 0x1D2114B95FA409E2ULL, 0xED2D87E6FC2839F9ULL, 0x7DF0F0F8F8B31E95ULL, 
            0xFC2128C0DD145391ULL, 0xC7261A2A2A890D56ULL, 0xCFF7382637A6F4CFULL, 0x6AF5BDB8A7198F15ULL
        },
        {
            0xE0436CEFB3A2F739ULL, 0x2003EE67D5B53B04ULL, 0xD075F17F12C4497BULL, 0x0CF48E4FEE53F260ULL, 
            0x23F744A59CAD0358ULL, 0x493412F459DD3E19ULL, 0xC979F3C0503D6DD1ULL, 0xB671A4E042923D5FULL, 
            0x6C5FF5714AA6EB47ULL, 0x190A185955F553B9ULL, 0x7B5D8C47502B34BBULL, 0x9396468E38BD7C94ULL, 
            0xF8B28FC719F934F8ULL, 0xBFAE65773208BF6FULL, 0x78EE4535554B971BULL, 0x2B62864E52DF7B62ULL, 
            0x5B270B04971B2A73ULL, 0x2055F768DE9C2C9BULL, 0x192FFD9569A4FF62ULL, 0x3CF1BCCE4775079FULL, 
            0x25275C71038120A2ULL, 0x8A1EC0019FE2958DULL, 0x4D6C96112BD939E4ULL, 0x993A95C55D6623E8ULL, 
            0x8FE7D46FD2F52FB6ULL, 0xEEADD6B2F19C954DULL, 0x00183310F6DF8E42ULL, 0x0937F78A28691F42ULL, 
            0xBB47E820327A1234ULL, 0xF86A5ED70B207E39ULL, 0x88FA7858F15E2DF2ULL, 0xB4E5E286C410393CULL
        },
        {
            0x0C7BE3352C63AB00ULL, 0x400C0C1BA206AC03ULL, 0x8F5C2B865931A63AULL, 0x25F321534F7D2532ULL, 
            0xFF13F0C20A5456B6ULL, 0xC2EB7AC5135EC890ULL, 0xD869D53EDDFBE4B5ULL, 0x406F9C50C9D5FCC1ULL, 
            0xD5BC9F447B1871C2ULL, 0x452F1C998E0214EBULL, 0xDBDA59EB402D34A2ULL, 0x8ADC9AA54B08745AULL, 
            0xDB3CC3906397D233ULL, 0x9886A6A8162D0704ULL, 0x97D1AD8A10CEAD16ULL, 0xD407A1BAB23AC5B4ULL, 
            0x89A408885AA41DE7ULL, 0x9E58770A09F5ADDDULL, 0xE9EBD2BE3C133EC0ULL, 0x78445448BC032658ULL, 
            0x4320A9E39393856CULL, 0xCCF17D45548F2D08ULL, 0x49CE3BABA409C0FFULL, 0x7384F846AAE85263ULL, 
            0x9A204925BB6D7EF9ULL, 0xA6B5F78692BA5776ULL, 0x7EB4A2DB29297319ULL, 0xA9A532A559298A41ULL, 
            0xD334AF0E9743CA09ULL, 0x3995F83C7ACCF75CULL, 0x87E2BA3835B7D9CEULL, 0x281EA0B56BA8A00DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseGConstants = {
    0x2903C3E67F984E8BULL,
    0x799888C2C5AD699AULL,
    0x671B5C89C688D203ULL,
    0x2903C3E67F984E8BULL,
    0x799888C2C5AD699AULL,
    0x671B5C89C688D203ULL,
    0x747BCF2A9B8DBC93ULL,
    0xE78A7D77586546DCULL,
    0x61,
    0xC4,
    0x9F,
    0xDF,
    0x96,
    0x8E,
    0x28,
    0x96
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseHSalts = {
    {
        {
            0x3460D7D9EFA2E7D5ULL, 0xF782B7AB229E36D3ULL, 0xE82A39D1D155BA64ULL, 0x7B203A7EB96FAC90ULL, 
            0x0F4679B8BC4C1B29ULL, 0x2179B91BBEB9067DULL, 0x38F89A12CDDF18CEULL, 0xC5E7FCAC5C265DEAULL, 
            0x4C770415C8DB9846ULL, 0x5A8A4187077BFC95ULL, 0x33E8A792E99A72B2ULL, 0x7C4EFA6B74A359EAULL, 
            0xA36F87A80A6CF929ULL, 0x4A4A10EC3FCA70CCULL, 0xCDD17066A9EC667CULL, 0x55261525339D9D28ULL, 
            0xE314DE88B44AFA6AULL, 0x1F47CFE422AF3B45ULL, 0xEB54FC823F70B74FULL, 0xC8F3BCB7EC3C20E2ULL, 
            0x7DB6A5160A5A2587ULL, 0x0952835C2A60F3F7ULL, 0x74543BD6FE842939ULL, 0x7B08C6F3F89B8F00ULL, 
            0xC4225D370D854C92ULL, 0x8ACCD129CDEC96E4ULL, 0x4690FF1C0F313382ULL, 0x9531778ABDCA7444ULL, 
            0x723D9E588659D533ULL, 0xC445101F4576D35DULL, 0x2FDB384FCB6BB4BFULL, 0xFB08B04DE0B9194BULL
        },
        {
            0x9217D79047D321ACULL, 0x147F16001EC3BAA9ULL, 0x37427F8CF83D288EULL, 0xD24EEB0C346781D8ULL, 
            0xFE0FA800032985B1ULL, 0xE92392FAC4BF4C65ULL, 0xAD45E6D7A8A29B70ULL, 0x6A644CE17114FBC2ULL, 
            0x14E4A1B9A59F875EULL, 0x1C828266D85FF0DCULL, 0x4AD880D516B08101ULL, 0x97D384D7D0949C86ULL, 
            0x9A6A898716985401ULL, 0x61C009A3E30EDA59ULL, 0x343833F450EF60D3ULL, 0x670DDAF5765F59EDULL, 
            0xD143F12AA4D682D5ULL, 0x00D06CB86AA249EBULL, 0x8AABA50B6CEA0A9CULL, 0x8008574BC8F53D90ULL, 
            0x441DF35DE56C962CULL, 0xD6C084A566294292ULL, 0xECBF16B190BC4BAEULL, 0xE18020F9EC266297ULL, 
            0x7D5D26277833B587ULL, 0xA693C9986E05BEBBULL, 0xDEA13166816E2B1CULL, 0xDA254797F87322BAULL, 
            0xA1B12D85504228AFULL, 0x3C481661BAF99939ULL, 0x726C7DA5D6B80303ULL, 0xDF9BDF0DBF705239ULL
        },
        {
            0x5FD78185B3F7C837ULL, 0xB9B81B34B3EEA95FULL, 0x338CB808F75E2B56ULL, 0x8C6A411A615D8F5FULL, 
            0x6A8A1FEF268AAD6CULL, 0x3C7D1CAA6AE427E7ULL, 0xC98575904FD3FE62ULL, 0xFD67A37C1321074DULL, 
            0x63D3CBFF2C3895D0ULL, 0xC802156C47EEF991ULL, 0x479F9006BE427619ULL, 0x14CFA2E732F11D2DULL, 
            0xD26DADAB98C4DC42ULL, 0xB7ADEBA7AECDF52DULL, 0x34B97DB3F8AC2F72ULL, 0x71C2900AE76AB721ULL, 
            0x5B12C8A6F0D44221ULL, 0x9135F0CF27717B80ULL, 0xC861416489C6EE72ULL, 0x6D3EE8949537D7BEULL, 
            0x26F9719BE27482B9ULL, 0xCCC7BF537E028368ULL, 0x6D28ED6503BB1524ULL, 0xD3EC3A2BFCD0A21DULL, 
            0xF4C1DAFF8B7DD270ULL, 0x68EA3604268A9B8CULL, 0xC5C45A43DB3A24DCULL, 0xCB79142027C55D5AULL, 
            0x4E6443BC8C0BAB91ULL, 0x32EED23CE108BF1AULL, 0xDE23A0D094B66E65ULL, 0x52F6260F0AA9DB26ULL
        },
        {
            0x093766FA2CFDEE35ULL, 0x8FE07CC566A9C8F5ULL, 0x4D405D6CA7475FA4ULL, 0x2CA2186D43421013ULL, 
            0x48D0289749F590BBULL, 0x6B1003457B5CE48EULL, 0xBFBCC8B9ACD7763CULL, 0x823FD8A41AA78763ULL, 
            0x5204FA82D6C31ED7ULL, 0xB2D8636F6EA09DF3ULL, 0xA498C7224C430271ULL, 0x0A4A07F5F5AF43A1ULL, 
            0x84CC99232A5A93D4ULL, 0xE335FE9310630B7FULL, 0x0395988AF11A80A5ULL, 0x100B84B5944FE077ULL, 
            0x6C1F7FE7318F1E2DULL, 0x736B901DC8176033ULL, 0x59B221F930BF55ABULL, 0xB9E33959D2FAE421ULL, 
            0xBC9AD963EB17CFD4ULL, 0x8C52492EA35BDB9FULL, 0x86A554A42106370CULL, 0x6D7478D2C611CC54ULL, 
            0x65F6E8A62DF967DBULL, 0xD422AE4F2CE048CAULL, 0xE26875EEA2A2CA4BULL, 0x64D20E20599B819BULL, 
            0x49F465551B8CDC11ULL, 0x56D99AADC54A1D95ULL, 0x914F767FF2145C09ULL, 0x21FA91B3A7489380ULL
        },
        {
            0x8F90BD05F62EB4C2ULL, 0x81594ED45D7FABB3ULL, 0xAA0EE74E508EC601ULL, 0x9219AD87BF014F06ULL, 
            0x0D7547EABDB7AFF2ULL, 0xA1A01DB8D401533BULL, 0xA3C78ED115415B67ULL, 0x553E6C0E28F8F771ULL, 
            0x96A9092EB993050EULL, 0xBE92690501CB6FE7ULL, 0xEAAC4346D26F3944ULL, 0xFEA5D8C44241AB4AULL, 
            0xD8089F15FDEAE9BBULL, 0x437783EDA051D0ADULL, 0x8166E4AA0EAF567EULL, 0xE49B2E82EC4C5F3DULL, 
            0x433732090A45A15EULL, 0x8BD33256ADC7E071ULL, 0xF26359BD2C1B8DF4ULL, 0x2C4DE72BD627ECABULL, 
            0xE344F3D16BBAF94DULL, 0x210F99988C68DF04ULL, 0xBFB398451B1FB5C6ULL, 0x141745BA9E88AEADULL, 
            0xE6EAB004A096C582ULL, 0x640E20CEB379F88BULL, 0x9D9FC7171FD3DB71ULL, 0xEF38DACE3010FA71ULL, 
            0x17858377A83E3FBDULL, 0xFE2DFA5A31609BA6ULL, 0xFC2615D6EF2B1FCFULL, 0x8D1A3F2BCCE936C2ULL
        },
        {
            0x6531CE73F051D1CEULL, 0x6EF32BEE5CEEFA86ULL, 0x367607C7C8042F3EULL, 0x48D8CD04A2B18D72ULL, 
            0xF0598CA93510C930ULL, 0x827D521032C27989ULL, 0x1B691DC3E1C27457ULL, 0x2B93290495C8C74BULL, 
            0x62AB3EC997F03367ULL, 0x7FB7149A6F3594DAULL, 0xB8C22E278DD9642BULL, 0x0EC4EA834805BD6CULL, 
            0x0A93106EE4D7FE10ULL, 0xC03F893790C395CBULL, 0xFE07CA6DC63D8B37ULL, 0xB28E9CA772266301ULL, 
            0xF4C3E2C91CF71F88ULL, 0x434AB8FA08E0EBAFULL, 0x6159207A6E0FF6FEULL, 0x5463B464404C29FEULL, 
            0x1F5454DA95C86E8CULL, 0x8EE266A26902B3C4ULL, 0xA152C3A3CF940EFCULL, 0x6C473FD5AE61DBD6ULL, 
            0x4DBE22C243C98AF0ULL, 0xB40A99633166A980ULL, 0x50BF871EC9D9C84CULL, 0x35D9503A218D2DF0ULL, 
            0xAC26BD438D546AD1ULL, 0x2F83C511A0BD95B4ULL, 0xB2DD7F3681A77112ULL, 0x4A82C189A1E8898DULL
        }
    },
    {
        {
            0x05E3B4D78E0DBDDEULL, 0xC38003B048C6A8D9ULL, 0xAD20ECE88D475A5AULL, 0x5A662D6F5B0A190EULL, 
            0x3C1F5918C1448370ULL, 0x47056471B7729061ULL, 0x42DFC735877DBE3AULL, 0xC00E3F50EB3E88AFULL, 
            0xC3035CF3423EBCE8ULL, 0x8C5ACC7979F36F90ULL, 0x77292B99A50BF8CCULL, 0xD05B9DC3759EB461ULL, 
            0xD10BC37B7DD7AA2DULL, 0xC5AAE079A3AEDF54ULL, 0xEB45095F7A1C5353ULL, 0x853A7E64E11C4AFBULL, 
            0xAE59749C8A9D90D2ULL, 0x5E61397956B23EABULL, 0x6F6A04EDFCD20A16ULL, 0xF7840936317741D2ULL, 
            0xA3BA8253DFEB979AULL, 0x9088EE43D07F6D7AULL, 0x40A3CBAB87272672ULL, 0xBF982872D4D6751BULL, 
            0x3C97E10D54B14550ULL, 0xF6670E6A446F62CFULL, 0x46F8D6BB27E34501ULL, 0x5C0AF4DDA83E8807ULL, 
            0x9C8213C6758F3909ULL, 0x3290F101B32AEC3AULL, 0xDBA72E911DC8A642ULL, 0x722B9C6969E4B4D6ULL
        },
        {
            0xC7D58B2A2A801531ULL, 0x03C92B51C0E9A1C9ULL, 0xFBA44692332866CCULL, 0x6D40C5E2AE5101D2ULL, 
            0x2734CC828377DA7CULL, 0x5E734E27B2F63056ULL, 0x4C9B57D1D5F4FAC6ULL, 0x0333D3E37004BB24ULL, 
            0xB7D0CA3D3ACE8AB8ULL, 0xFEE8933CDF3C9535ULL, 0xBF99B58B05744E57ULL, 0xE8900B9FAC4B7817ULL, 
            0xBFAAF6F70EC85697ULL, 0x3D9CFD09BE67293DULL, 0x9EE8B928300A5B2FULL, 0xF64EE83E175FD231ULL, 
            0x3E90CD120B9B22B8ULL, 0x2ABF6A04FDF1A450ULL, 0x9E80A7944397E138ULL, 0x0EFDFB8C94276A48ULL, 
            0x4E769C01B79D6183ULL, 0x3C177E389255A4B6ULL, 0x73C8ABA3CD3E2E8FULL, 0x6FA4A0431F016E9EULL, 
            0xC4A3063802636227ULL, 0xE552341D0397CEC4ULL, 0x2277397CFC37E023ULL, 0x2F78F66755B07297ULL, 
            0x41F65678B19AF170ULL, 0xD080328217C18243ULL, 0xF183D786E01E9366ULL, 0x7B7614CD3B72A7A8ULL
        },
        {
            0x67ED4558322D45ECULL, 0x64F1234600F83076ULL, 0x7191F09B77F3082CULL, 0xCEBCF1E8641BE079ULL, 
            0xC26627C91763D622ULL, 0xBE8889DA0D9ACC92ULL, 0x7D06F186DCD4DE77ULL, 0x3112FBA244F43519ULL, 
            0xF73C47F0890EE889ULL, 0x765873BFB674A0BEULL, 0x6E7B0EABF04251E6ULL, 0x57BF51EA2FC67E6FULL, 
            0xF148DF5A7087034FULL, 0x01B2AE4C45186038ULL, 0xCE137CF28518DF0EULL, 0x2DCC7BFF9540B57FULL, 
            0x9B5AFF2A28E65337ULL, 0x569FE8A1EE65225EULL, 0xF329D2DF7B21B510ULL, 0xF3572783948895ADULL, 
            0xBB6D55A2D19C1A1CULL, 0x6D65B3D293E949D7ULL, 0x2A86912AC0B95A2CULL, 0x5406625678461114ULL, 
            0x0200C8FA24C84043ULL, 0xCD552FAFD7D5482CULL, 0xD43163DE2ED33564ULL, 0x36CC27C18B601EC2ULL, 
            0xD7B73F402583E49FULL, 0x12FD62C55DA21968ULL, 0xA429CA82B435D443ULL, 0xAF644B1BCE590A5EULL
        },
        {
            0x6080CEE32BA96E1DULL, 0x070F85A56D08A9A4ULL, 0x6044C526DB43688DULL, 0xBC8847C930C20E83ULL, 
            0x74630E056980E9C0ULL, 0xEF941B3AA580F446ULL, 0x884A67CC210AAAC6ULL, 0x2B27B3D58020E2F7ULL, 
            0xBE8B2DE616BA93EDULL, 0x4D138EA84155A41DULL, 0xDFA230CCFB2BF6EFULL, 0xAF03BD1743941E80ULL, 
            0xF1787C8D5300E283ULL, 0x14E4C9DA0E045F21ULL, 0x4360217ACA208B46ULL, 0xD6138D7816029B5CULL, 
            0xA77C1416BE72F128ULL, 0xDBA40032FF8A1362ULL, 0x16EE9EDC2FCC0DEBULL, 0x600D333CA3BE68CAULL, 
            0x56C7B14C928F4383ULL, 0x1EC3832E5F8854DFULL, 0xE3F2E413E6696C6AULL, 0x2F1DFBBF8EDD8481ULL, 
            0xDB463E3667DBEB6FULL, 0x6AA158AB348A2A05ULL, 0x7EB27CF6E082957EULL, 0x2836310A8134B036ULL, 
            0xDF113FFEB40B6DE7ULL, 0x8D2DC30161E87A24ULL, 0x4AB7FD805A01A13AULL, 0xCA0C2D1A580B0275ULL
        },
        {
            0x81A30903534F30AEULL, 0x6DBC7D42CC28BEF0ULL, 0xCD93E47B17BFE1C3ULL, 0xDE7151B0FF25C333ULL, 
            0xCB24EA36EBB3DAC5ULL, 0xE4E56B422158FA0FULL, 0x02C41A7D52EC80A6ULL, 0x21172DDCBDB2AE52ULL, 
            0x88F342D277B15425ULL, 0xEA4E2B7C0C9BB972ULL, 0xB26A17EE2294D42DULL, 0x71BD020703E2CA9AULL, 
            0x538F41E31EA5BD10ULL, 0x71E354AF9DE6ED72ULL, 0xB50C4CCD0DB641A1ULL, 0xFC336EDB8616B2ACULL, 
            0x9EA2D78788FF8FEDULL, 0x5B686C4CA694DEFFULL, 0xFFE9CE7FCD611759ULL, 0x2B818566E8F73EAEULL, 
            0x2F831595359A4EACULL, 0xE7C7BB0E1FAC3956ULL, 0x011B9148E3F6B51BULL, 0x5E9154472038E5E6ULL, 
            0x23D043BF26C4AFCAULL, 0x9E9B9D995269C9E0ULL, 0x254FBF39B724315AULL, 0x9E34D0F87E3F7943ULL, 
            0x4E72DD906CDEEB1EULL, 0xCC1A78A7FAC42854ULL, 0x3C9F3F9C6BA1CFC8ULL, 0x3061207C278D1420ULL
        },
        {
            0x1F5AFD4F51414760ULL, 0x47567858BA7CB67CULL, 0x399C399B2B6D9759ULL, 0xA10CD3FF3F720E1EULL, 
            0xB649707B9B250441ULL, 0x3AED7AAAF53B999EULL, 0xEEC465BC9184E744ULL, 0x86E34007BD4C2693ULL, 
            0x5A4EB838FF9641EDULL, 0x9DBA7AE5F23CB048ULL, 0x09581C94C3CB8176ULL, 0xEF74E13AE67A6E3BULL, 
            0x454826E8500F494AULL, 0xA765B31BF35DED83ULL, 0x89180EA3EC18F849ULL, 0x651606B95FD7D6E1ULL, 
            0xFE9EC80D92F05BC5ULL, 0x1963B2B2ACAA39F2ULL, 0x63A0E589979D8ED0ULL, 0x4C7269BA0CDDFD6FULL, 
            0x8EA890FF227185A3ULL, 0xE238FEEA0C581F1FULL, 0xD0B4A32CE887DA51ULL, 0xDDB91DCF023939E2ULL, 
            0xBFB7ABE6A520225DULL, 0x52468381657474D7ULL, 0x60937A618FAFCC5FULL, 0xE9F9C911E3F56E09ULL, 
            0x1ADBE3B66E0BAF49ULL, 0x5839FAA6309D9BE6ULL, 0x9B2023C9582568BCULL, 0xF6BA8FA11D2B3010ULL
        }
    },
    {
        {
            0x74AE7E48A17F3727ULL, 0x13FE4989DBFD8E28ULL, 0x9116C3FBB0F2D3DEULL, 0xB75144EA3EC5DD3FULL, 
            0x847407CEC076800AULL, 0x83866B7A0109B501ULL, 0xC9C7093DA6AED174ULL, 0x763B60E531EF26B5ULL, 
            0x9D6990048D652E80ULL, 0x318269F833977BEDULL, 0x91ED203A2A10838FULL, 0xE9134C43D01894EAULL, 
            0x5F6337DC48222444ULL, 0xF07FF7AC2B7D234EULL, 0x8CB882C17A32043DULL, 0xDA5AFE8BBBCE238BULL, 
            0x6C918E399CE30486ULL, 0x11C3D64FEAB0293AULL, 0xEA2161237442CFD2ULL, 0xBE5A361261ACF978ULL, 
            0x10A2562A59A6652FULL, 0x700E5874663D1DEAULL, 0x6B5C27F2FCFCC62CULL, 0xE4A938203CC438EAULL, 
            0x5F043027B27CE9E6ULL, 0x30E96A7B13B27790ULL, 0xF1C3EE15435C3754ULL, 0x904748C018F9D335ULL, 
            0x7D6768822CE006FAULL, 0xF955B09824107325ULL, 0x70E645DE644DEEF6ULL, 0xAC5E170218CBEB03ULL
        },
        {
            0x05EB7CFF056FA26EULL, 0x408E5C299C6121A5ULL, 0xEAF73E192FC297BDULL, 0x198A07ABF150B112ULL, 
            0xD040DEF79E6365DDULL, 0xA03EA0BF363A0794ULL, 0x533AE6BDED32635BULL, 0xE7A709B058E8D375ULL, 
            0x5082EF82DF1E54DEULL, 0x66B66C2FB1468792ULL, 0x360293450A262835ULL, 0x7729C3287C15AF81ULL, 
            0xF8C195A26821118BULL, 0xAD4B1C247BE424D9ULL, 0x67E748B34863BE7FULL, 0xD09AC07F7181FCD9ULL, 
            0xE643BB5D93A0CA82ULL, 0x9B43F7EE942153B1ULL, 0x326A398AFE72053CULL, 0xB8BBBADD568232F5ULL, 
            0xAEE538E0B8FC02CAULL, 0x183F8C947A9C1B26ULL, 0xD16F958C0CFC0BF3ULL, 0xE6A13EEF08E03935ULL, 
            0xE15EB973D0965504ULL, 0x39CB0F3DA3A3ECCFULL, 0x8FD5755F58D76AFDULL, 0x6182206C8EF60D34ULL, 
            0x7810A8430D0032E7ULL, 0x3DC47074AF10CBA8ULL, 0x0A4ECF62A3CE763CULL, 0x1F0C725062C8C242ULL
        },
        {
            0xC369314597367CD0ULL, 0x6ED76C4D75FBC138ULL, 0x8C2EA35508EEA1BFULL, 0x3F7AE0042241482DULL, 
            0xAD20181AB953F701ULL, 0x263D6C9766CAA517ULL, 0x4A4B0CB320CAC223ULL, 0xE30666B137246687ULL, 
            0x3783CD3094E713BBULL, 0x9CEF3B7E6FC74F6DULL, 0x514B4DDAFC89E470ULL, 0x15A495F0AC01D518ULL, 
            0xA53A53100DEA7C1CULL, 0x4B32ECF85CDF2999ULL, 0x6DB848DDD9DE7905ULL, 0xF6FF94D0A0492EF4ULL, 
            0xA84FEEAB63370285ULL, 0x7405A48683EC429EULL, 0x601DC9547D4C5036ULL, 0x06910DBC7805CF2AULL, 
            0x5C3772DBFAA3F3D4ULL, 0x75FA8BFEA006A0D7ULL, 0xFBDAE5A5A8574DAFULL, 0xE9E2B4B0A859C587ULL, 
            0xF933E51328657234ULL, 0xE369D498CA393D23ULL, 0x034520725261FD31ULL, 0x6515FA46CF7D4B6AULL, 
            0x0E545FCFD170975BULL, 0x8ED7FBCFF6177429ULL, 0x5318212B7492EBC8ULL, 0xDBACA2AC51AA0EA4ULL
        },
        {
            0xC5B00F4673CE843AULL, 0x7B5F2F17BB11C506ULL, 0x2F25A402991B979FULL, 0xEE903EBE45FCC2DAULL, 
            0xB2171A67C926481AULL, 0x57CF0E41E2F231FAULL, 0xD82A6023424E0813ULL, 0xBD5EB1EAE43D5CF0ULL, 
            0x3F0FBD2C9099B125ULL, 0x184ECCC2CDDF18D4ULL, 0xBBBD3ACF28D8FA02ULL, 0xDFF871DF4D3BADDAULL, 
            0xCB26CC5450A929DDULL, 0xAE302A4FA2626F5EULL, 0x1308F12183927299ULL, 0x326DECB33EAE4B6CULL, 
            0xDE951BBC31214CB9ULL, 0x03661A35A703B1CEULL, 0x52BF2C00522A63CFULL, 0x6D8E6ACF99978A32ULL, 
            0xE5DE786D344D5BA5ULL, 0xE73870BE05A91840ULL, 0x5E816D0970371247ULL, 0x81DC68F28485B69CULL, 
            0xD68891C78D257783ULL, 0x56D6509E5F783F64ULL, 0xA6857ABAA54A131BULL, 0xC9B05FE0D998D233ULL, 
            0x13C403C2690E325EULL, 0x83E0E7C64E577506ULL, 0xC6818F4DD73BA80CULL, 0x7E6363718530B0D5ULL
        },
        {
            0x216CBA3FFEFEC1CDULL, 0xBA5AD2E1A650EEE9ULL, 0xAFD65258C126464FULL, 0x21F0A9ECB8210C83ULL, 
            0xDE517842B29B2200ULL, 0xF4FA3E030AC47F4AULL, 0xA754C408E9804A86ULL, 0x225D3A73FFE6C74CULL, 
            0x227755EB6C690F60ULL, 0x16DCCB9B07F42FA1ULL, 0x83F1D217A7A0AB10ULL, 0x56BD7558F4E5E9DCULL, 
            0x74474FB164E41F96ULL, 0x7F9505B571C30542ULL, 0x74FD1E5F3BF27405ULL, 0x6DDB26B8EAAE4798ULL, 
            0x858BDA7E3EAB1088ULL, 0x0376D9EFABA23653ULL, 0x10EB51AA522E0AC2ULL, 0x18DB16E311F35F12ULL, 
            0x8E68325C42350653ULL, 0x6001377340799A3EULL, 0xDD07F78A45C6D7F6ULL, 0xA9071831C9CA59DCULL, 
            0x67D5EFA45C0E4D39ULL, 0x5A4D5BFFD2B3D114ULL, 0xC467857D6767C769ULL, 0xDCD2955894FEC7B4ULL, 
            0x6A389A494AD27DE4ULL, 0x7B8A9985C055D197ULL, 0xD410BF53DD947A84ULL, 0xA40BB1244D58256DULL
        },
        {
            0xE5DE8807AFE9D9F7ULL, 0x1D84D0D0D40EACA4ULL, 0x0FB2F54433DCA6F0ULL, 0x1AEC2D2B5DCED9E6ULL, 
            0x0E9929450711AACFULL, 0xBE2815E8D368B93FULL, 0x17505E50C32D9D08ULL, 0x63D95D9FAE998F50ULL, 
            0x9C9D6B67303D59ABULL, 0x54924B0662349005ULL, 0x6D02A97DC293ECD7ULL, 0x7DDC12EDE6F871A1ULL, 
            0x55CBFDB905FB773EULL, 0xE4DD2152015CEF38ULL, 0x18A6B05949790806ULL, 0x7F987DB3CBAAF0F3ULL, 
            0x98274A53DB0EB19AULL, 0xB87AB9F2F40618A4ULL, 0x3D7DB2D0470A83ADULL, 0x41EA8C6834866042ULL, 
            0xDC8470215679D528ULL, 0xB629E07ADBFEA0B3ULL, 0x17AA770EFEE630C5ULL, 0xA280C4FA5C39C7BBULL, 
            0x2A061A75A8ABC254ULL, 0x989C3D8B7998B6DFULL, 0xCBD363E7BD95A727ULL, 0x83704F395EF17900ULL, 
            0x7330FD82D191F01FULL, 0x6138ECEA5E657984ULL, 0x46958C501F61A3D6ULL, 0x7D206406F4D900B2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseHConstants = {
    0x6D350F6AB45805B0ULL,
    0xD7DA50D7925B6989ULL,
    0x55452FFB222D9C84ULL,
    0x6D350F6AB45805B0ULL,
    0xD7DA50D7925B6989ULL,
    0x55452FFB222D9C84ULL,
    0x29E1E83D0D123C9CULL,
    0x4D5038E927AAED27ULL,
    0x67,
    0x1B,
    0x01,
    0x57,
    0xF3,
    0x08,
    0x0C,
    0x26
};

