#include "TwistExpander_Billiards.hpp"
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

TwistExpander_Billiards::TwistExpander_Billiards()
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

void TwistExpander_Billiards::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xC92F09378AC12E02ULL; std::uint64_t aIngress = 0x86D6D21D1DC6EE5FULL; std::uint64_t aCarry = 0x935105252A92B547ULL;

    std::uint64_t aWandererA = 0x8D151BF205FD3716ULL; std::uint64_t aWandererB = 0xB4310E1422E4AD1AULL; std::uint64_t aWandererC = 0xCAD6E44B730C28E6ULL; std::uint64_t aWandererD = 0xD6B52AB70BE41833ULL;
    std::uint64_t aWandererE = 0xD13CC556D6C9D98FULL; std::uint64_t aWandererF = 0xA15FB9CE032CCF64ULL; std::uint64_t aWandererG = 0xA26DC037AE19E258ULL; std::uint64_t aWandererH = 0x911E8F36A36F12B9ULL;
    std::uint64_t aWandererI = 0xD6D1058EAFE2317CULL; std::uint64_t aWandererJ = 0xDE78768063273F78ULL; std::uint64_t aWandererK = 0xB7107ED0821F42C5ULL;

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
        aPrevious = 12445319585715166610U;
        aCarry = 17301435910437187904U;
        aWandererA = 15541913626021056151U;
        aWandererB = 12555064982846131677U;
        aWandererC = 14172308422649829707U;
        aWandererD = 15868480444726208871U;
        aWandererE = 17026909896720709405U;
        aWandererF = 15936726744599352932U;
        aWandererG = 13745253092349657818U;
        aWandererH = 13060610476975626886U;
        aWandererI = 16958060358704531610U;
        aWandererJ = 14627333683171578494U;
        aWandererK = 14189057628440667433U;
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
    TwistExpander_Billiards_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Billiards::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x9DFED78F69DA76FEULL; std::uint64_t aIngress = 0xB6DE1D78547F68F4ULL; std::uint64_t aCarry = 0xD8245FCC2B50CDA0ULL;

    std::uint64_t aWandererA = 0xEF1696668EDB1ECEULL; std::uint64_t aWandererB = 0x9C5370E31DF680E2ULL; std::uint64_t aWandererC = 0xF07DF015B6AED3F4ULL; std::uint64_t aWandererD = 0xE8F7BB7F764DE473ULL;
    std::uint64_t aWandererE = 0xBCB9C28DD655E29DULL; std::uint64_t aWandererF = 0xD19EBA17CD5C54D4ULL; std::uint64_t aWandererG = 0xB31D3FA2DCE7458FULL; std::uint64_t aWandererH = 0xA3A6039CE74DEA3FULL;
    std::uint64_t aWandererI = 0x9BC15787EEC210DEULL; std::uint64_t aWandererJ = 0xD3419603236A1909ULL; std::uint64_t aWandererK = 0xE9F9834DD9DFC2BAULL;

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
        aPrevious = 14733383127463238893U;
        aCarry = 11739237457680253451U;
        aWandererA = 12578635235996994546U;
        aWandererB = 10231096184141056163U;
        aWandererC = 18240462548242909886U;
        aWandererD = 16310040003756598198U;
        aWandererE = 18030422014109990054U;
        aWandererF = 11350113463311767669U;
        aWandererG = 17035084327995386694U;
        aWandererH = 12017665446171033581U;
        aWandererI = 13910225420615491812U;
        aWandererJ = 11162924476552622951U;
        aWandererK = 17774499205286706992U;
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
    TwistExpander_Billiards_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Billiards::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF8A1A038FD8ECDD2ULL;
    std::uint64_t aIngress = 0xB494AEC5CF331C2FULL;
    std::uint64_t aCarry = 0xD1CD5150A0E9EA73ULL;

    std::uint64_t aWandererA = 0xD610EE57584951FBULL;
    std::uint64_t aWandererB = 0xAF0BC355B0C2AC07ULL;
    std::uint64_t aWandererC = 0xA3F84A1E779FB7FAULL;
    std::uint64_t aWandererD = 0xF588EF66347C3F11ULL;
    std::uint64_t aWandererE = 0x92D2F16BC51DA0FEULL;
    std::uint64_t aWandererF = 0xF4645E6E4D340BBFULL;
    std::uint64_t aWandererG = 0xD343614DBE44404AULL;
    std::uint64_t aWandererH = 0xED8E99C0571B5C26ULL;
    std::uint64_t aWandererI = 0xE024D09999EDC92AULL;
    std::uint64_t aWandererJ = 0xAEF6AD94B0F731C0ULL;
    std::uint64_t aWandererK = 0x825D9BDA738455E7ULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC, 0);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA, 3);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Billiards_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Billiards_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Billiards_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Billiards::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Billiards::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEE2B210FB3B66E6AULL; std::uint64_t aIngress = 0x94721A550CC77908ULL; std::uint64_t aCarry = 0xF990B4895A01FD23ULL;

    std::uint64_t aWandererA = 0xEE7F4BCD878EDBFBULL; std::uint64_t aWandererB = 0x815E7436E5050727ULL; std::uint64_t aWandererC = 0xBE9B293FAAE5CEFEULL; std::uint64_t aWandererD = 0xC4F337B8A393E300ULL;
    std::uint64_t aWandererE = 0xDF91E72696EF40A0ULL; std::uint64_t aWandererF = 0xF5A7561638E4F9AFULL; std::uint64_t aWandererG = 0xEB1CD17E791CEF87ULL; std::uint64_t aWandererH = 0xB9680654DEE76C56ULL;
    std::uint64_t aWandererI = 0x9240064E8CBA81B4ULL; std::uint64_t aWandererJ = 0xB5D29A40920ACAE3ULL; std::uint64_t aWandererK = 0x96347CCC0E75E2BAULL;

    // [seed]
    {
        aPrevious = 15817844579119785059U;
        aCarry = 10140033591084161489U;
        aWandererA = 12430940333933619159U;
        aWandererB = 9660049036663308762U;
        aWandererC = 11165594987237831527U;
        aWandererD = 14713909307577711033U;
        aWandererE = 15157388108408183548U;
        aWandererF = 13950460507672818995U;
        aWandererG = 17913387071603853570U;
        aWandererH = 18209629466907043450U;
        aWandererI = 10650561568509827381U;
        aWandererJ = 15683175587102303057U;
        aWandererK = 14105388599052292137U;
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
    TwistExpander_Billiards_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Billiards_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Billiards_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Billiards::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 2, 3 with offsets 5625U, 3752U, 6941U, 5777U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5625U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3752U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6941U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5777U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 0 with offsets 8118U, 8139U, 1493U, 2669U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8118U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8139U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1493U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2669U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 3, 1 with offsets 7759U, 7190U, 6706U, 6549U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7759U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7190U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6706U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6549U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 0, 2 with offsets 2500U, 5279U, 3986U, 3508U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2500U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5279U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3986U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3508U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 1, 2 with offsets 538U, 703U, 978U, 1866U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 538U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 703U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 978U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1866U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 1, 3, 0 with offsets 2U, 2047U, 1071U, 217U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2047U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1071U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 217U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 1, 3, 2 with offsets 1691U, 906U, 1384U, 516U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 906U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1384U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 516U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 0, 1, 2 with offsets 1089U, 232U, 1924U, 1659U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1089U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 232U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1924U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1659U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 915U, 550U, 224U, 1032U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 915U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 550U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 224U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1032U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Billiards::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 1, 0 with offsets 7271U, 7339U, 5842U, 963U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7271U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5842U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 963U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 3, 1 with offsets 4456U, 7096U, 1166U, 407U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4456U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7096U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1166U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 407U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 2, 3 with offsets 1523U, 2138U, 5474U, 2090U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1523U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2138U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5474U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2090U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 2 with offsets 5869U, 4181U, 4348U, 1424U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5869U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4181U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4348U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1424U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7527U, 4210U, 5142U, 1240U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7527U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4210U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5142U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1240U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 283U, 1704U, 1829U, 1741U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 283U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1704U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1829U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1741U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1301U, 1086U, 618U, 387U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1301U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1086U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 618U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 387U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 173U, 489U, 1197U, 1172U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 173U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 489U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1197U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1172U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1173U, 1524U, 1595U, 1405U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1524U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1595U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1405U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 2, 1 [0..<W_KEY]
        // offsets: 333U, 238U, 514U, 1982U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 333U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 238U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 514U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1982U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseASalts = {
    {
        {
            0x6DC882E9D29C3660ULL, 0xB2707D5F74CE2FE9ULL, 0x04282692AB2BA960ULL, 0xC54FF628F760B9D5ULL, 
            0xC99E0EB48AFF2064ULL, 0xD4F4CEA6A0F2A306ULL, 0x631770BD9515BADDULL, 0xE6D8C230499F6BEEULL, 
            0xD0C8975B1E54B6B8ULL, 0x3108511E73366031ULL, 0x6C8412D7B2CBADCDULL, 0x9B053C4BC84DBAE4ULL, 
            0x96B71BD7D7ED1637ULL, 0x4D15DA67ADDDDA2BULL, 0x385D6BF23DE89369ULL, 0x1084CDDE59C250FEULL, 
            0xBA10CF30493AA18BULL, 0xA63CC2ECC1CD601EULL, 0x867FB9FDCF19BFBDULL, 0x77CF34E4F34C990EULL, 
            0xF612199FADC5A5FDULL, 0x21E812F0F0626E9AULL, 0xCD5644EC16D17A09ULL, 0xD46287FA66C55427ULL, 
            0xDF5C486A0B16519FULL, 0xAE86C8277F05696BULL, 0xAA0933BF80EB9445ULL, 0xDEF56EE4B1301B10ULL, 
            0x58D9F757732AA98CULL, 0x10A1E11029F832EBULL, 0x53E210ABA6EA7D19ULL, 0xCE4E445CBAA21FC4ULL
        },
        {
            0xE59023FB816AE6A2ULL, 0xDD992B158C7A1498ULL, 0xCA7CC4B91015E741ULL, 0xF85286DE55D1A392ULL, 
            0x30BE0F0FE60A22BFULL, 0xF61063B0BB418A09ULL, 0xC100C02A844F678EULL, 0xD089038AC1E0230BULL, 
            0xE6F6D546788A7FF6ULL, 0x61564A02F3507320ULL, 0x021CEA0EAF7F5EC3ULL, 0x76B7A9E34BAC5FABULL, 
            0xF2F145A7FE0CDF37ULL, 0xFAC439D245737CE2ULL, 0xFD363A3EE39A61B3ULL, 0x996DBD5B55DEC32EULL, 
            0xA80B389FB72BB27BULL, 0xC82AB0D9CD22551BULL, 0x8297B2911D5C45A3ULL, 0x615B0253374EF881ULL, 
            0xEB042B8D2DFFEA93ULL, 0x6BFBA74C79F55EA4ULL, 0x4697C11248D14ECAULL, 0x80FA8D2E44F4FB46ULL, 
            0xB75FF0CA2723C6E2ULL, 0xFACAC1870B3FDDD6ULL, 0xCE7302E7B6D5E956ULL, 0x3159695DA01FA825ULL, 
            0x216929BB7C63078AULL, 0x0520DB37AC00C978ULL, 0x5768EE82AB6A9538ULL, 0x5475D047303FDA97ULL
        },
        {
            0xFB4911A32DBF4F27ULL, 0x6800B2B00AAC1634ULL, 0x654238881829320AULL, 0xB6B77DD02C0BCABAULL, 
            0xE90E6897660CAE78ULL, 0x79EF1920DC0B0691ULL, 0x5C5D2498F1F41DAEULL, 0xB97AD63B17235C7AULL, 
            0x43C8D91350088612ULL, 0x37165BCF7F73D841ULL, 0x2B6FEEDE0D385299ULL, 0xA38CE7521F9F448FULL, 
            0xC4ACFD96D92CD14AULL, 0x1C4A0A96C3717279ULL, 0xACDDD23D86B52FDDULL, 0x31D41BB77B6A9FF6ULL, 
            0xA62AA82840C053B4ULL, 0xB905E46AC837ADDDULL, 0x4613B21A28923C73ULL, 0x347940642F68680DULL, 
            0xA0F62A034B9A1BF5ULL, 0xFA8DD86830CA246AULL, 0x9BCDE9FD6BECE3DDULL, 0x4967C1C28D5AF208ULL, 
            0xC900FEB7EFBDB9F7ULL, 0xE794BF4219CB8D78ULL, 0x9048950FDFB7AD3EULL, 0xC622226E4A47DA61ULL, 
            0xFC37F18363D26758ULL, 0xA85F1611CE24443DULL, 0x9B1F0E894AC90142ULL, 0x866DE46E4F80606FULL
        },
        {
            0x9C8CF7B89CF73F55ULL, 0xA75D92EFE2396216ULL, 0x0A0FCD9ADDF8ABEBULL, 0xD0DEF8671BADE2ECULL, 
            0x255C507A01090CDDULL, 0xD535D69382040AB2ULL, 0x9229E22C1450CFB7ULL, 0x20268ECDEBBA5A10ULL, 
            0x6DE43F2D2DA42748ULL, 0x2BCFBAA47E5B31A9ULL, 0x940EDC20EF0714D9ULL, 0xD2CDF92765E6676BULL, 
            0xD0458EAE124D705AULL, 0x2B980AAD3A18B1E8ULL, 0x28D82226F99F0083ULL, 0x5A87753E1317E697ULL, 
            0xE45985B3EE3ADB02ULL, 0x1722CE2468650B01ULL, 0xDDE2CD30FB1BCC1BULL, 0x8A3EB88F0D3145F3ULL, 
            0x63F13C35FBC3F51BULL, 0x7C566E5B7AF29A76ULL, 0xA818B5D1A1FEA659ULL, 0x6F9C825909C9FDB0ULL, 
            0xF39CA5B788B89BEBULL, 0x8EBEA4A665B423CFULL, 0x1A582783096DC717ULL, 0x04F6302B7CA7A1ABULL, 
            0x55557FFB32CB8BE5ULL, 0x41A7AC67FD8B0448ULL, 0x5B9712A149004B2EULL, 0x49C6DF6AAC63D170ULL
        },
        {
            0xA9A3F99212B01C4EULL, 0xCC0283FFE55FB202ULL, 0x67358B4B966695B8ULL, 0x538EB41EDB5E0738ULL, 
            0xC9A8296F6CED928AULL, 0x8033B0D1D90143A8ULL, 0xBC99F43AFC06F119ULL, 0xF438830F2BCF483DULL, 
            0x0E0D2F1134AB6259ULL, 0x0E8BD6B1C354A40AULL, 0x5FC10AD641722BAFULL, 0x14A83FC6683F5ABAULL, 
            0x461ADBAC7C20F3BBULL, 0x5E0FDB592986C02DULL, 0x618E16D4ED7CFD24ULL, 0xF4D42AEF8283D01BULL, 
            0x0630F25CD2AACE73ULL, 0x8B2B46A4302EE685ULL, 0x9D842EDCB6E24E00ULL, 0x81F79EE09478F04BULL, 
            0x9CD78EB31C01F2BCULL, 0x72912A96181F1A41ULL, 0x8FB2D17267314730ULL, 0x40B7C6038579E5BEULL, 
            0x4794E4054946AE11ULL, 0x9B06F80C7D387C34ULL, 0x85DE5965BE568AF2ULL, 0x03153D7539C2007CULL, 
            0x9F93FE6FF6C87EEBULL, 0xC4A1679059F2EF15ULL, 0x44AA3050FAC4EC82ULL, 0x6EB240E567B85B8BULL
        },
        {
            0x06691CE02CB7C589ULL, 0x3139A378F2593F3BULL, 0x76E254E33C30BAEDULL, 0x76695481D5BE241FULL, 
            0x1390BCFF4383DC27ULL, 0x48918E090BCF5453ULL, 0xB057CEA09D27D96CULL, 0x246F21DE35B67CB5ULL, 
            0x09C3A61CFD1BB473ULL, 0xE0D6ADF2CA15D2AAULL, 0x21566E5C9ED99A45ULL, 0x678459E2B582D289ULL, 
            0x396E07FDCA087084ULL, 0xD89DCC7F3C7A1644ULL, 0xF99D22CD270416BCULL, 0x51D6D6CF271ACD6BULL, 
            0xFE3A6FBFD9B420BCULL, 0xEE4828C2847D6B6EULL, 0xC656917BA486F3D4ULL, 0x4E9EB8909F25B9B1ULL, 
            0xCCD94E0D57E72C56ULL, 0x05B2EE250CA2EF2BULL, 0xF2B07C7FFF73CD5CULL, 0xBEF8D9F4B97F8E69ULL, 
            0x3B2DE4CA3638D52BULL, 0x85783EBD36091FDFULL, 0x8E5F972741ED6AA4ULL, 0x903F9534AAB7BE96ULL, 
            0x45AA5D32DDBCBEF1ULL, 0xB2B78A2DBAAC88E4ULL, 0x8756DA07C5D4A3D7ULL, 0x7494A8110EA8E3B2ULL
        }
    },
    {
        {
            0x8EB9374BB6CE301BULL, 0x6DADBE9C05A61575ULL, 0x09382A99A0D293E4ULL, 0x916AC42F74C036EAULL, 
            0xC7A898B2F8C036B5ULL, 0x8316ADEEA08EC16DULL, 0x7045B1DA7D959033ULL, 0x3242C225B6FAD1B1ULL, 
            0xB28AA41D9CFF3360ULL, 0xE9392EBF253F2C44ULL, 0xEA5AD9B86110984CULL, 0xDF76E5CCF75F141CULL, 
            0x31B3650B76DF8BA9ULL, 0xB948B4081A0207D8ULL, 0x5B3A590DC638E829ULL, 0xB414684418578727ULL, 
            0xE69E3C9247631786ULL, 0xC007B36BA05EE892ULL, 0x374D3C16947C15FBULL, 0x3047D019E32A0905ULL, 
            0x99CA602A8DF814ABULL, 0xFD42431652875098ULL, 0xE390A3BDBE9C5013ULL, 0x0039B1C9094D509CULL, 
            0x1DC485992EFE35C8ULL, 0x30CEE511F6779067ULL, 0xE096F2C64DD0B2C3ULL, 0x826DE8DDEBCF28CEULL, 
            0x08D075E45022D3EFULL, 0x939DDB2C06864F16ULL, 0x2101AB23CE236828ULL, 0x6CF3ADEDB831BB43ULL
        },
        {
            0xC12E49BF2CDD6DA8ULL, 0x80B161BB990C6C8DULL, 0x2CDCB9090B059C3DULL, 0x3996EA22327A5AFEULL, 
            0x17D3846945FEBF9AULL, 0xD9C8730AFFBF4109ULL, 0xB281976287AC8F77ULL, 0x624FFAE029F877CDULL, 
            0x870CE7E1D6C1DB38ULL, 0xA3DD47ED3C1E0A9AULL, 0x598DF1AE2B2B2B40ULL, 0x8E9BEFF000E0A770ULL, 
            0x9B074732D0A44E2DULL, 0x28D2C1A7B556A3C0ULL, 0x748337AB985E6394ULL, 0x383A633DB246EB98ULL, 
            0x574924A00A21DE91ULL, 0xA495710D6A0B5A6CULL, 0x3C1B790F1B6FB1CBULL, 0xE7F32A03303900D1ULL, 
            0x2BB6F4D5A0992D95ULL, 0x637B7EF61F29EAD6ULL, 0x605EEB8A2B88ECA6ULL, 0x0D6200E6157767C6ULL, 
            0x88D97E26B25FEE14ULL, 0x852A4FA257A3D5E0ULL, 0x013ED682EE06B588ULL, 0x52E516B166FF3C2DULL, 
            0x0E49BA3D3603B34EULL, 0x8F5B13F97D026F90ULL, 0xFA7EF73557393EC8ULL, 0xDC9E811CB861648DULL
        },
        {
            0x45129B7E9C547CABULL, 0x8F954CEF6E1C254FULL, 0x889601ADED033917ULL, 0x0B6604B4350AE0C5ULL, 
            0x57987D49EE92E212ULL, 0xDE9C3190AA22C779ULL, 0x5E693B7A6B65528FULL, 0xFFFE6D1C76CAEF66ULL, 
            0x39B1365DC22DBD6DULL, 0x82D3F8BCCAEFA5C6ULL, 0x6C4FA2302C90112AULL, 0x21BA96EFF8E84B03ULL, 
            0xE0550AB8C4ED3FAAULL, 0x6D4B8B1841125E58ULL, 0xAB63A5E6A5BF04C2ULL, 0x70C7A0796122CA3EULL, 
            0xE84A9D70EA34E0DAULL, 0xF96A87CCCDCD3767ULL, 0xD474BE0CD651275CULL, 0xBEDD8AAB37B74F57ULL, 
            0xF1B892EBF33FD9B2ULL, 0x1382D70231342C02ULL, 0x315FE0F53FEE8D12ULL, 0x15C9F915BB81D6D3ULL, 
            0x6A566BA1AC85462FULL, 0xC01020FF7F6DF07CULL, 0x80163E2A0BBE2A5BULL, 0x3D61BEB242A5F44BULL, 
            0x1CDD32DA71BE6F77ULL, 0x577A3CA60F02BF16ULL, 0x5CB4FAF9554A483DULL, 0xE96EAD22450A0D94ULL
        },
        {
            0xF7BB84FA05414DCCULL, 0xBE753EF79657E080ULL, 0xEDAA0C6A5A3391F5ULL, 0xD0ECDED63A8A5518ULL, 
            0xA395822B036BC8EDULL, 0xC8279338A166E5CCULL, 0xA45FF655CA6B6AABULL, 0x82C8E431BC343CC3ULL, 
            0x2039B1E88E46057EULL, 0x54252262523F03BBULL, 0x561FFF2E9F42B9F7ULL, 0x0A6C10AFB76CE4D2ULL, 
            0x2F1EB5E40E71C1A3ULL, 0x6239A60FB0F5E65CULL, 0xA6B5C2D0A201970EULL, 0x6C8C270F969A245AULL, 
            0xB8438B6EF2A765A5ULL, 0x5AF7E3BF39514ECCULL, 0x50D5B0C258911F85ULL, 0x408FE85FDC2DB2C0ULL, 
            0xAB3B6AAF045CD67FULL, 0xC0E840BB3162AD0BULL, 0x2DCD4A02359D9DA7ULL, 0x72D1DC8097A69B51ULL, 
            0xEBB16E19686E7A66ULL, 0xAC94914952954859ULL, 0x421E1703902FF016ULL, 0x70A163B7CF08C569ULL, 
            0xDE160B094C631FC2ULL, 0x5CC0AEA99F252B04ULL, 0x4AF35F1A634A6F9AULL, 0x58D1FE88C580986AULL
        },
        {
            0xE53BC9A640BA2B01ULL, 0x31F8D23AB4A20409ULL, 0xFC89107DD9503026ULL, 0x3873723ACDC8E45BULL, 
            0x8B0427581BAF002EULL, 0x150244238D6D3AECULL, 0x4348A7908A4D83C8ULL, 0xA2C7204F6FE12A0AULL, 
            0xB1CB2E19FFDAC6D4ULL, 0x7F2C5D7759B74B23ULL, 0xBE3417627059E983ULL, 0x0773922D545131F3ULL, 
            0xBE7A7E2CDBB63ED5ULL, 0x8458A145ECD2AC22ULL, 0x3C1B6B5C57F63474ULL, 0xD03E66CC914FF6B5ULL, 
            0x934870B91AAB107AULL, 0x191395DF1B40D91EULL, 0xF691D541531F010CULL, 0xD8AC3735763D4515ULL, 
            0xDDEE0DD8D6669BD2ULL, 0x28AAE463BCDACD65ULL, 0x9E538B28DEFD7FDEULL, 0x91C2C3D9587C15A6ULL, 
            0xF3DEA3CAB2549FA1ULL, 0x1179A738D17250BEULL, 0x2B0553AA550EC169ULL, 0x935D0BBC878A5046ULL, 
            0x74FD6D3DA44CAA3BULL, 0x7350549ED9EE3231ULL, 0x91C286BBC676762EULL, 0x467147F5E923B4B5ULL
        },
        {
            0xDBAF2B42CAF97B50ULL, 0xC0F52245F15A871FULL, 0xAA299CD9AA5281B1ULL, 0x12CD3F78B9A0FFBFULL, 
            0x2E070DD483A187DBULL, 0x5082A84D0D58F21EULL, 0x8A8F29C75651222CULL, 0x9D9E6F0FE568028DULL, 
            0x327073ACAAD26438ULL, 0xD7DBBB145DD68011ULL, 0xCB37FF6C536DFB6BULL, 0xABEE39D122958D59ULL, 
            0x51D2E6E175DBCAA9ULL, 0xA63DC164D580278EULL, 0xCDE2EC6FA2167D33ULL, 0xE371663FD6D5F42DULL, 
            0x1D25F965D8CBB11DULL, 0x164EBB6EE1BF4A64ULL, 0x3606109A0EE01E0CULL, 0x7C970EB2FC9C568EULL, 
            0x9A4F47DC3520D542ULL, 0x11AD8A25856E8706ULL, 0xCC86830AFD26EAA2ULL, 0xDB499590476CAA4AULL, 
            0x989C03C4C93C11A8ULL, 0xAEE9856785AAF031ULL, 0xC35B24BE54544198ULL, 0x61195AA07202D96EULL, 
            0xA2081C052562C631ULL, 0x29951822B8CD8C63ULL, 0xEB2769C6F97CD5C2ULL, 0x87E4CDBA09B56D70ULL
        }
    },
    {
        {
            0x52D4B4FE86192D0BULL, 0xFE06D8CDCA4A5DD2ULL, 0x546C66F2149E974FULL, 0x35A4D9895CFFE03FULL, 
            0x7FA1C7ACEA650FD7ULL, 0xCA3EA70DFE584396ULL, 0x5FF8EC559A7BB69DULL, 0xCD82B39EAD613A88ULL, 
            0x16CFCCE6BD5CD60CULL, 0x0F809B8F3AF59ED5ULL, 0x470E6B1105900B1EULL, 0xEA16648743C735A1ULL, 
            0xCF41363EBF88A3D3ULL, 0x51C1C022E7AFB5CAULL, 0xAA18A123A1AA3556ULL, 0xE6ED08C85BC3E7B7ULL, 
            0xA1E787DE785E90FCULL, 0xF23C66584F8FC099ULL, 0xE47FC4DB6F51FECFULL, 0xCB81BC219BEAFB06ULL, 
            0xBC0D056E185A28C0ULL, 0x5F047C3E4CF7BD72ULL, 0x748FC45F8C8FA062ULL, 0xA393CCFEFAD9F993ULL, 
            0x1958114D996E72F6ULL, 0x3D9D3B3472F46554ULL, 0x8BE115B2AE5AC05BULL, 0x49AC84238DB59260ULL, 
            0xA97AEAC52F3CE155ULL, 0xA4E13FB9495081B3ULL, 0xE5D690C94D152CA7ULL, 0xB8C9E0F0EB0D0384ULL
        },
        {
            0x77ABE33B1A89916CULL, 0xA1D074D513D3F305ULL, 0xA095FF9B30169BC2ULL, 0x67D8FBA0C5F5EDA1ULL, 
            0xFFEB68BEC5F99324ULL, 0xA855450B1A919328ULL, 0x4165616412AD9AC9ULL, 0x2E26058862A71D94ULL, 
            0xB465D7DAE6FD1CFAULL, 0x6F5AEE6DFD061728ULL, 0xF9BB07B0F5EAF19EULL, 0xD4077CEE30A8E423ULL, 
            0x3D0A4C728308B02DULL, 0x455F4092B5FBC503ULL, 0x9A03179EC903BE4DULL, 0x0FBAF09840BCF8ADULL, 
            0xC937484E1E47A917ULL, 0xF73581C5FE23C3E5ULL, 0x845667C197ABD9EBULL, 0xE583DD463017D5FDULL, 
            0x02A1D1BA9078BC23ULL, 0x9AE7B0D199B08D4FULL, 0x48C5FE374FA8EDD2ULL, 0xD9A000AD85034B4BULL, 
            0x362F9D450DB82C2EULL, 0x62ABBA6364178938ULL, 0x10792DEF668C34E8ULL, 0x71ED182B8190B605ULL, 
            0x438AAD88F7FCF72FULL, 0x42842C4CDED94AE1ULL, 0x97538D63894C0D7DULL, 0xAE5D1BA1F22C3967ULL
        },
        {
            0xE6E3E9C26D0C066EULL, 0x9810E79FA3DF938FULL, 0x5A1FBC28104B7143ULL, 0x61871206BD04FC12ULL, 
            0xA5234889FF4B5A7CULL, 0xC55811E6BEDC42C8ULL, 0xFEDF10632C8676DAULL, 0x495F00EB54E12541ULL, 
            0x6DC6F076D8E67E6DULL, 0x071499C28AB3BD67ULL, 0x03EA1B52F35F2DA2ULL, 0xD120489705AB110BULL, 
            0x99B1572F40A9C1ADULL, 0x6E4A1870F5F7717FULL, 0xD10A927E6749C77DULL, 0x578C5BA7FE95B7D0ULL, 
            0xB559D988D919D00EULL, 0xED7BEEF43C1B682DULL, 0xB582327658AB7864ULL, 0x3D3CFD81FE4082C8ULL, 
            0x0D318FE14A246C73ULL, 0xA5916ABAA69CE0F5ULL, 0x9CA43F8D498EB705ULL, 0xDA3F192BD790ECD9ULL, 
            0x5056FFBEA1578F2FULL, 0x924C26CD3CC691DBULL, 0xFA4C74C21D5A5A12ULL, 0x3F5EB0F538D1D963ULL, 
            0x43F3BF890217C915ULL, 0xAFA99E7097CD91A9ULL, 0xC4F8F6893A6AD4CAULL, 0x8D6D8CA639BD6118ULL
        },
        {
            0x135E00013FFC546AULL, 0xE2478BB7B805A499ULL, 0x11437E577F753ECAULL, 0x316D1E8DEBC6E91CULL, 
            0xF2A1C94185E4D888ULL, 0x8F0CBECCFE1727C7ULL, 0xA0B93DA2C63F1528ULL, 0xB72346AFC2D36EE6ULL, 
            0x4FF904A3298E4883ULL, 0x8BB4A77782CB2D45ULL, 0x5619E7547F85E8CEULL, 0x5AAAF2D614BB5154ULL, 
            0x0F3A89ED5160F35BULL, 0xEBA414F795EA8D2DULL, 0x7522FD289DABA210ULL, 0x56419AB97C69D43CULL, 
            0x88E84F1DA99431C9ULL, 0xB20252C96B4D21CCULL, 0x664CF8FEA7AE56CDULL, 0x0A9A8B18A0735E14ULL, 
            0xBD6DE54591B58F41ULL, 0x2A1F1FA37440AFE5ULL, 0x127C81C51EF74F58ULL, 0x010D5A0C4E519908ULL, 
            0xD9D3797FF8FCB7DEULL, 0x1E0A7AB7BE1A00D3ULL, 0xEBC51F296272E365ULL, 0xC913BD8F945F089DULL, 
            0x968B55A39E2B71A6ULL, 0x380C212EF9C073D4ULL, 0xE85E7BBD2159AE36ULL, 0x7050DEC9A956615FULL
        },
        {
            0x21FE6971430B50FFULL, 0xBD5515D664D2B3C3ULL, 0x60198CCA3962EB8CULL, 0x695684C4494778B6ULL, 
            0x49AB8333A0EB9FB1ULL, 0xA15B8F50C90D9EFCULL, 0xFDE9D84CC205C048ULL, 0xCF0439F3BA911E24ULL, 
            0x6D933639324F4884ULL, 0x9D476598D084B31CULL, 0x07E6D5DD06E5CA0CULL, 0x156ED94E7E201A84ULL, 
            0x0CAB501AD26272ECULL, 0x04689DC7B6DD6474ULL, 0xA799065441E7A949ULL, 0x6F578EA94C2F1FDEULL, 
            0x3A1A5EB07A6FCA9DULL, 0xF0D33D2FB9974D3EULL, 0x5A603D466650DA00ULL, 0xDE0AD701939EC706ULL, 
            0xA72D89E4ED12BD9DULL, 0xF33ABE2200972624ULL, 0x583EDFCA6CF62FBBULL, 0x7866CC47E5973038ULL, 
            0xE6CC14DE8B83B7E8ULL, 0xC131058834C1A47AULL, 0x5A504CE39440C434ULL, 0x5FAE086B683AAAD9ULL, 
            0xA49D670646AEF239ULL, 0x4D220BFFB2475D62ULL, 0x8DD0E1CAB509CA60ULL, 0x50AC561EA50AC1EAULL
        },
        {
            0x09D813AEF3105B49ULL, 0xF89BB3D5837C82F3ULL, 0x191D4E1BC8CA0422ULL, 0x89DCCC867396D75FULL, 
            0xB74CD50F18A7AF1FULL, 0x42BB6694203E967BULL, 0x310CB6FB35B2C8A3ULL, 0x1D85733C38F6A335ULL, 
            0x9CD6BBA66FAB91C4ULL, 0x928235DAEA312258ULL, 0x45726530DA22F8BFULL, 0x2BE7CF30265EF816ULL, 
            0x55651EE9B0CFF228ULL, 0xC48D0736341D0874ULL, 0x69EBF4DAF56CD6D4ULL, 0xEBD2BCA6C4F4F1DAULL, 
            0x8DADE0FFAD94C540ULL, 0x4435226D50C8CC75ULL, 0x5CE5F3942BC424FCULL, 0xA88C4F58F0096ABBULL, 
            0x4CAE4BA60175BCC3ULL, 0xDD1F0CBCE2DF0776ULL, 0x433C5DC9527E8392ULL, 0xAFA5AF1BEE703903ULL, 
            0x110073038A5ABFE8ULL, 0x084EDC149A5C8146ULL, 0xE40A76F09C43560CULL, 0x4261CDE4135F80BDULL, 
            0x943BFBD3410629F8ULL, 0x32B1E0C1EFAB4603ULL, 0x33E98EA940BDB504ULL, 0x3E330A7A883973C8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseAConstants = {
    0x7B9CFDF0D86F5C5CULL,
    0x5CC12D1D4F59FF37ULL,
    0x3B6C108222E11BA3ULL,
    0x7B9CFDF0D86F5C5CULL,
    0x5CC12D1D4F59FF37ULL,
    0x3B6C108222E11BA3ULL,
    0xF52C59131B254EA2ULL,
    0x93067BB574153CE8ULL,
    0x7C,
    0x8C,
    0xF4,
    0x73,
    0xBD,
    0x28,
    0x62,
    0x03
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseBSalts = {
    {
        {
            0x50874D09E3A4E347ULL, 0x86FD916975C61A95ULL, 0xB15A9684A5EBC9DDULL, 0x3E150B75BB94C741ULL, 
            0x6D375F33D9E6CE87ULL, 0xFB2E50D7E36D679FULL, 0x55153FEA5F9C8C34ULL, 0xB7C838C4B83DECEFULL, 
            0xCBBE6814AC4CF14EULL, 0x1953F08485996C91ULL, 0x3E63AACB973415A8ULL, 0x6730C1F59F02D6DCULL, 
            0xAB89D4FCB4125E02ULL, 0x0610C11B5094B3F5ULL, 0x7CC376E5041D5EB0ULL, 0x01CD9740F2AA07D3ULL, 
            0x9B182C57EE2CB072ULL, 0xD16D141A71AA5D7AULL, 0xB7BD261B1B71929DULL, 0xD80CF2ABFEC209B9ULL, 
            0x67BF746C4AA836CFULL, 0x543200AC1AD129F7ULL, 0xE91F17D9A3A5F4C8ULL, 0xA8BF713D6C647DEEULL, 
            0xBBA70F343AB26B7FULL, 0x12546E85EB989D9EULL, 0xABC3B2DB56278D9CULL, 0x81F136EDE934D079ULL, 
            0x44903F2410C5CFFCULL, 0x8967ABEF73545587ULL, 0x041B4F5BD656D144ULL, 0x8F39A69C2B6AA227ULL
        },
        {
            0xD7120EFFFFDE647BULL, 0x658A958AEFC80771ULL, 0xD359AA16A36E2B45ULL, 0x27A1992898A04D4AULL, 
            0xE48E538A9A3A66E4ULL, 0x73AE52CD5DC00F46ULL, 0x469319E424F8A81FULL, 0x2CCE44FDDB5FE848ULL, 
            0xCE38C0E7A706C1E8ULL, 0x0291FB4AACAB1D8FULL, 0xB7F30BD739CDA613ULL, 0xA0E895A44EE86DA2ULL, 
            0x2A5249B3E0F68893ULL, 0x0BF2D061D59D37EFULL, 0xD3F14B2C8A0411C6ULL, 0xAC4435ADCEC25F6DULL, 
            0x9DBE2B08892620D5ULL, 0x20167A2DF094C5D4ULL, 0xA41A77695C82AE61ULL, 0x2BD231AB4D4B610CULL, 
            0xAE19509FA750151CULL, 0x45B2D9F76EE6E400ULL, 0x54E8A4D66A177819ULL, 0x09CF6C73F80AC62FULL, 
            0xF5BFA09C546BE4E2ULL, 0x5456467889B6A6CBULL, 0xC494F5990BFFBDD9ULL, 0x0040D52C35DB339CULL, 
            0x962AC3FE737DA38AULL, 0xE87C236059D4130DULL, 0xFB9276B47143814DULL, 0xB90DAA1ECCD5F5E0ULL
        },
        {
            0x865C53D39AAFBA3EULL, 0x15FD80D1BE6F1B9CULL, 0x8F61BD03CFA6296DULL, 0x286697240175EE34ULL, 
            0x0C6986ADCE7D0231ULL, 0x8ADA748525CE73E2ULL, 0xAF24A4030BC48807ULL, 0xC627E7ECB76C57CBULL, 
            0x438F25EADAA4BADBULL, 0xC4AAA291C98B5949ULL, 0x4E914AACF7A5E23FULL, 0x82623D05557C234BULL, 
            0x83A13ECFEC767B42ULL, 0x22FF8DC5B4D7CE37ULL, 0x27746CB74F186018ULL, 0x05304EA10BE73A66ULL, 
            0xA7B73F17DB64CD9BULL, 0xB40C2B0233291F86ULL, 0x757448895C7E71B5ULL, 0xCADF72876CB0373DULL, 
            0xFC8B31D504AFA604ULL, 0x2AEA0DA51463FFFDULL, 0x73BCEA210FD555EBULL, 0xC3C9E06900FEF3C6ULL, 
            0xCD094679791A7ACAULL, 0x56676AE03FFBD2A1ULL, 0xF782656071352D56ULL, 0x9E09EECE913CE1EEULL, 
            0x8AD73F8B8AB43A2EULL, 0xDB127A345F20CAF9ULL, 0x48E71A3324470232ULL, 0xA5547F0D8B1F68FEULL
        },
        {
            0x35B654951B6BC16DULL, 0x4DD75BBD101EA511ULL, 0x50351684DB86C8B0ULL, 0x37523989B58431C5ULL, 
            0xD08876E7F25065BAULL, 0xC1AF16C3760B90F0ULL, 0xD977C19D7A20D700ULL, 0x3158DCEB1C05BA9DULL, 
            0x1015AE37143AB967ULL, 0x9D6A8B94FFC661E4ULL, 0x7F51FFD1991DEBC4ULL, 0x4A5D9487E12DD7D7ULL, 
            0xDBE6364B554BA484ULL, 0x31F21C1445541AFDULL, 0x2EB1682C0C8E7BFCULL, 0xB56595A0E7D3B7EEULL, 
            0x3D423FA336332FEBULL, 0x7D036E8B7A262351ULL, 0x7032920C96A45EB3ULL, 0xD54EB172E766A676ULL, 
            0x10869D3457BCE3C2ULL, 0xE11CB3DBD9439FBDULL, 0x07C6F24C6AA9061CULL, 0x7D43E04C7E1C5B0EULL, 
            0xAAAC806C7A9B2C0DULL, 0x2FFF80FCFC9DD871ULL, 0xE7ADEE3D362A3BABULL, 0x75C82E0E94161FEBULL, 
            0xA3821A75EDA0884DULL, 0x0F8B8AFE34F45DCAULL, 0xF8DE30926CB935D3ULL, 0xC45EEA6C084BC2FCULL
        },
        {
            0x28CA55DD6CCE4D71ULL, 0x27B32E71EDFB3957ULL, 0x27F1AB46231C1AC2ULL, 0x52B756B6FC085C3EULL, 
            0xD05441AA17EA5C4FULL, 0xF547D5F149E2874FULL, 0xCAF2DC547C1D074EULL, 0x8683D3B74998B4BCULL, 
            0xE655B54F73989380ULL, 0x5BD89E07F2368AF8ULL, 0x6FED3345E6B8170BULL, 0x64F3FB9C377AFCF8ULL, 
            0x94E9F35D46DAF2EEULL, 0xB5D1E444F280AC9BULL, 0xF7942ECD82B5D8A1ULL, 0x17EA2C97F4951454ULL, 
            0x3460EF00ADEB604DULL, 0x3E32FA947E9BE003ULL, 0x9C0D2445D00383E4ULL, 0xD0E9C711BBB9D6D3ULL, 
            0xB184A6DDE8A78635ULL, 0xF1AD2DFBDCC865FDULL, 0x5564FD6458FAF196ULL, 0x7D03D8E077C44A0BULL, 
            0xA888CCDCB02E908EULL, 0x78E1BC32880A9779ULL, 0xEDB9E4420E99459FULL, 0x1306C1C46CAF3D94ULL, 
            0x70B6F0C8F892A256ULL, 0xF8717C58A37457BDULL, 0x89E29490EBA62E18ULL, 0xE3329D1505BB7D3EULL
        },
        {
            0x15AB0186E7762FFFULL, 0x04DAD4572F07C13CULL, 0x13C1B225F884B100ULL, 0x741E086D74CBFC20ULL, 
            0xAF836ECFE750B051ULL, 0x9E9CD8283F3E4763ULL, 0x220D9B87B26B06CEULL, 0x9469852EE4067DE1ULL, 
            0x6BE1F2CF8C236EEDULL, 0xE7F762C23514EBC7ULL, 0x212D85C222AF8740ULL, 0xD3EB8450A94DC8D5ULL, 
            0x9ACF170C4F2D8784ULL, 0xD09F90528553D763ULL, 0x55A080884473A599ULL, 0xBE199A313A859538ULL, 
            0xAC7827E0D171FA83ULL, 0x37AB072B53CA830EULL, 0x0386B92FF2DF729DULL, 0xE43FE2C5F8EB606DULL, 
            0x5AB11E707FBCF556ULL, 0x6E6932337A1BBCC9ULL, 0xC71B20223B4F2FE8ULL, 0x1863397E36D5C2BFULL, 
            0x1F4BF7A729642AB7ULL, 0x14C109B2E36B990BULL, 0x8E22C865EC4E009EULL, 0x41B37317F8DC4602ULL, 
            0x7A62A8DAA1AD7065ULL, 0x0D7CB088B15AEEB9ULL, 0xA8C60CE7FBB3871BULL, 0x53AA316A9D86505EULL
        }
    },
    {
        {
            0x8E745E5D83E57607ULL, 0x1FE23E7740387B70ULL, 0x5D39B3EEA4E05F86ULL, 0xF95406405AFD1915ULL, 
            0x2AE21AC867E5A4DEULL, 0x74187BEFC7545D0BULL, 0x437B83CFCEF97441ULL, 0x733FB2625F7D21A9ULL, 
            0xA1B7AE67F2CC6258ULL, 0xEDD2FE9B6DF2B607ULL, 0x12D7EC70209D527CULL, 0xE3307F735B2C4CB5ULL, 
            0xF8ED6B2A7907E948ULL, 0x371BA9F360C00C05ULL, 0xEDA827CF95822E53ULL, 0xB9EF637E0DC508A4ULL, 
            0x4F500EF08F22E85BULL, 0x8E91FBDDB13D0A08ULL, 0xD038433A52C04852ULL, 0xE6A7A10DB15257BFULL, 
            0xE5C86F910A8BEC4DULL, 0xCC422A5D8D3968CBULL, 0xDE5B1882F4356F6DULL, 0x50DBC88959796FFFULL, 
            0x337E5F6335A5D051ULL, 0x5279A628A821AFC1ULL, 0xAC1F69E20EC8E077ULL, 0x1768682CBBCA4A5FULL, 
            0x75106CB428A41E47ULL, 0xE6152ABAA1A44874ULL, 0xAC7564EFA747CF95ULL, 0xCEF911227DE3380EULL
        },
        {
            0xE107D5719C5AEF89ULL, 0x8AD923902BA3C61EULL, 0x50F0399804B6882CULL, 0xCA62C5D9D4DA095CULL, 
            0x2052C69F267194BAULL, 0xFBA875B3B4EA232AULL, 0x67CCEA195C457339ULL, 0xEAA9175CBF1F0E08ULL, 
            0x7983D4ACA83CB054ULL, 0x60A0E4840EB35376ULL, 0x27AF5C0E40B5F929ULL, 0x53F5DBE02A56BDD7ULL, 
            0x77A947EDC5FA2BCDULL, 0xE03F353C14E40C2BULL, 0xB236E47C83952C1DULL, 0x34E9051B3886B5C0ULL, 
            0x216AC0B396D7BD40ULL, 0x9FD39F937C3461EDULL, 0xFC38BADEE30B8EA7ULL, 0x6D44D08183C783D0ULL, 
            0x314D98591DF458FCULL, 0xA8E9AABC31CF9F24ULL, 0x2E1CD0A417869D3FULL, 0x29D082637E2CE921ULL, 
            0x46AB4E9469F43A89ULL, 0x9F613474923BC907ULL, 0xD588812B99A8CB3BULL, 0x1A29BCED7763C1C3ULL, 
            0x2B624424F13CE5ACULL, 0x1D3BA59B7D207443ULL, 0x1403AB96AA5E5638ULL, 0xED12B249103CA8F2ULL
        },
        {
            0x2E2DBBEEE5BB68DFULL, 0x1CD125F4F53937CEULL, 0x6F6F42C6E9179FFCULL, 0xCBCA1E9C347784B7ULL, 
            0x8C607FF26311169DULL, 0xB3E6BF8289539C51ULL, 0x260845DEAD3ACC25ULL, 0xB27FB93C962E79EAULL, 
            0x2E6D451266D74CDDULL, 0xB30F100C6B56AFDBULL, 0x4FF5FF2D3EAAA3D9ULL, 0x9AD447D2857F7CBBULL, 
            0x83556A38A60F8331ULL, 0xBF113A539F83CBBDULL, 0x84ACCD31F677667DULL, 0x4916F9D64420D518ULL, 
            0x1C94027CDF568A4BULL, 0xF1EC8B02D9A7C217ULL, 0x001B5C801BDA3799ULL, 0x948E3E630EF56A45ULL, 
            0x2366CD7555E3B7BDULL, 0x5A8970388E90EE39ULL, 0x639901D58893C8BAULL, 0xE84B3D3A9CF14EB5ULL, 
            0x3036BF52C5C1F541ULL, 0x65D259F7A95F696BULL, 0x5929C72F3EF289B6ULL, 0x927EA2469C8136AEULL, 
            0x665B4D241FF28FB2ULL, 0x8C1E39E143339FF9ULL, 0x90F23A46BB355F86ULL, 0x74E91E74A1843E1BULL
        },
        {
            0xDCC3E1903AFE554BULL, 0x71B2A492C19A8557ULL, 0xAE30BD2082BEF2E5ULL, 0x05C4AD0B32B09750ULL, 
            0x58DB30650CA1E20EULL, 0x0ECD40AC0580B990ULL, 0x7E24BD08750FF11AULL, 0xBB391CEE865B7159ULL, 
            0x021C17CDCB3F3F08ULL, 0x934A94C4972A7667ULL, 0x667AA1E4071FB621ULL, 0x5EEE73AA613655F0ULL, 
            0x2C68A51563906FE7ULL, 0x0B39D415887E2A82ULL, 0xBFDFDDD7BEED9462ULL, 0xC0C10E237EB8D752ULL, 
            0x306A36E4D79B8248ULL, 0x832FBDD310BFEB53ULL, 0xCDCCFEFECB1C1741ULL, 0xBAFA58DD928CE033ULL, 
            0xBE8ECF5DD96534A7ULL, 0xF8AA45491DE5715CULL, 0x67494726484AE43AULL, 0x090BA14CF6955173ULL, 
            0x441170957FB0118FULL, 0xD53B28C5BC94ED4DULL, 0xD63B96FFE7D84DAEULL, 0x73BCC5C8F2F00C81ULL, 
            0x02B916355D3914FDULL, 0xEEE2A31F9C0FE2CAULL, 0x1EA1CE08241E4C8EULL, 0xCDCA04D183AB18A5ULL
        },
        {
            0x47647C4AAE278B99ULL, 0x1D8EC95CCDC2CB10ULL, 0xE6841546D00B6516ULL, 0x773F60433BBBDA1BULL, 
            0x5C7B4A7106C786EAULL, 0xF86F82BAA5C724A4ULL, 0x1BA2F3FDFA5F7A13ULL, 0xB62F18045EA1E5E4ULL, 
            0xCA3B17A67A8897DAULL, 0xB4594B8C04805CE1ULL, 0xDB8FF950FEF5B90EULL, 0x7A19C40E06E2D4CFULL, 
            0x0E8D120F0D25169AULL, 0xCA98B26AF7506E29ULL, 0x670FB9C7609943CBULL, 0x49D665AA3E861FAEULL, 
            0x0FDECBB9AC4C8F2CULL, 0xC387520366A6B500ULL, 0x4DC7D35E97AD3868ULL, 0x40538B8979A2627EULL, 
            0x3B646CA3D2DBB5FAULL, 0x8EAECCD7CED8D0DFULL, 0xC2C1A4AD5432A784ULL, 0x172C7E4EA2267860ULL, 
            0xC7AD4763D0834C85ULL, 0x60B7239A072D13E2ULL, 0xF6157B183F811DC5ULL, 0xE99A948D0CFA89A6ULL, 
            0xE3262A269058B2DBULL, 0xB2111B39F81DC7CEULL, 0x36F630CCF9BE3A5DULL, 0xCBCC33F5FA7F03C5ULL
        },
        {
            0x4FA33CF4CC7F6641ULL, 0x3B2088E2DCF95403ULL, 0x8D2EDF834F249054ULL, 0x884C98D859716272ULL, 
            0x2C9BFFC5036BAE30ULL, 0x3282A61C1FD8D45EULL, 0x19F2188E54BDCB09ULL, 0x3F08F1CE06652A7AULL, 
            0xC237E467A492B34AULL, 0x651C69D8E890DE4CULL, 0x31CA3D436761017BULL, 0xE7503C69960D67E8ULL, 
            0xE352286A26FDE93BULL, 0x58D084E6FE9FC18DULL, 0xB22D1F3678BCB359ULL, 0x41CCC91E57172D2BULL, 
            0x17093C0B1D083753ULL, 0xEACD3A4DCED4B410ULL, 0x963ECF23E4694DB3ULL, 0x0DAF0EC6C2196114ULL, 
            0x53F3F8016BF1D62EULL, 0x4BF4D11D09A8823EULL, 0xDA1320177E3552EBULL, 0x313F13057281CDBEULL, 
            0xAD1912DDFE17E03BULL, 0x146B44891237784DULL, 0xB4224DC0C0A357C0ULL, 0xA043BF4E40D599E5ULL, 
            0xD903CEDCCC8C2A02ULL, 0x5509059B6DF4988AULL, 0xD8A3E9C20F6C77B0ULL, 0xF7ADD4B23BF12973ULL
        }
    },
    {
        {
            0x5C48A554B15D2E6DULL, 0x2B8F2CF5E7309B6CULL, 0x7350EAE8C6865658ULL, 0x49EC97CE84B64122ULL, 
            0x261406EA68F5E367ULL, 0x5E319B085A06DFB8ULL, 0xBBB4275E7CF9B1B9ULL, 0x6CA07F4AEA6483DFULL, 
            0x60E9DD2BF3E71514ULL, 0x5DAB8337509F3D07ULL, 0x8397FF07F176EBB8ULL, 0xFA06CABAB3427494ULL, 
            0xC53E3E74F4BC4117ULL, 0x4E7C8D2334CD442CULL, 0xA3DEF74F0F263934ULL, 0xB3B45E61D96C1271ULL, 
            0x81F0372227439292ULL, 0xC8D73FC89F70AC8EULL, 0xC8A89A6892482CE7ULL, 0xDC32E4E447B980A6ULL, 
            0x053A9094858596C2ULL, 0x19DBCBB1DBE71B77ULL, 0x9FDD6EDD2119EFADULL, 0xA29C2F95A9F78157ULL, 
            0x87451E7EA87DD9A1ULL, 0x34D358A7861AC45AULL, 0x96D8B582D96F7D1FULL, 0x317B25B3783B1420ULL, 
            0x0A569014FD7BDAF1ULL, 0x965956BCDA7D8FE8ULL, 0x10074355016F18D4ULL, 0x3B475AE3BC06FDD4ULL
        },
        {
            0x3EF4649510B49091ULL, 0x755D87CFC4F6C8E2ULL, 0x26725055D5F29690ULL, 0x164CFC776BFA6A4BULL, 
            0x5CFF3D0B7B9A2E11ULL, 0xA970314B9209A042ULL, 0xB0664D7F3D44E291ULL, 0xFDB6C70FB8E064D6ULL, 
            0xF4EFAD04135AC97BULL, 0xAE75F63E0FEAAD7AULL, 0x8A975F343ED01BEBULL, 0xCAA1D8ED83EBF0E1ULL, 
            0x8D80151C837EF8A0ULL, 0xE1D4D39A865C1209ULL, 0xD19B59E51E564F68ULL, 0x282F1653D64EAA9EULL, 
            0x75F379A3906BEDE0ULL, 0x4F3644E40061983FULL, 0x213FD9E9823BC614ULL, 0x55503FBE8117F32CULL, 
            0xBFEC73269672BEF6ULL, 0xB7CA79E531C28ADEULL, 0x16F0BD58F1EA1017ULL, 0xD66389DDC9557888ULL, 
            0xA55874F2DB228EE0ULL, 0xC2FFAFE49311718CULL, 0x173FF2469BF77EDAULL, 0x817B9DAA967CF986ULL, 
            0xFA6E4F0680B63ACAULL, 0x0431867946C87DBCULL, 0x7748F6DEF30C97C1ULL, 0x4065B6A0EFE4E4A4ULL
        },
        {
            0x3A04384C9CC0AE37ULL, 0xA955DF803A0C56C8ULL, 0xF823D3FBA03D26BDULL, 0x1117A2EC9ED7A697ULL, 
            0x41C16EA62F960395ULL, 0xBC6921E841B25302ULL, 0x49088B28CDBCF9D6ULL, 0xE1CB87FDCA629076ULL, 
            0x66561C5E3A385EC1ULL, 0x61067A0CBF036EEAULL, 0xC7C9C31B7E5D2E32ULL, 0x633D8888447768D3ULL, 
            0xF4C75EB9E02F148EULL, 0xC6EEB169E279D8D0ULL, 0x3DCFA2C0993C7ADDULL, 0x139C9945E3E32BF8ULL, 
            0xDFE11418AB9793FDULL, 0x88C1A887A37841C7ULL, 0x11099D00D6E08D2AULL, 0x6F2A401AAA3E953DULL, 
            0xAA42B306B7A82FE9ULL, 0x5798DCB8B613AD9EULL, 0xBA33340E33B24198ULL, 0x987E650896C38497ULL, 
            0xD50D2D1D3D6F6EE6ULL, 0xE2F3185E6771528BULL, 0xFB02B08D52A24825ULL, 0x3FD30C964C144526ULL, 
            0x156553AFD4F8F609ULL, 0x308C75C72F9C0A60ULL, 0x8F9D731CA3FC4647ULL, 0x6EF829753866011CULL
        },
        {
            0x95E7DC5CF3D96923ULL, 0xFBA1AA74CB998BE4ULL, 0xDC909D7290B72388ULL, 0xC26792F92CE20AF1ULL, 
            0xE96C11E78FDB2100ULL, 0xC6C76A7449D91D0BULL, 0x6FA499CC83F56054ULL, 0x8F5FEB380BC3AE2FULL, 
            0x70FEDC8DEBFCEE1BULL, 0x43CD776495DCD9EEULL, 0x2300881DD5DE21BBULL, 0x33E0475FADF8ED5BULL, 
            0x1C14F4555D455F41ULL, 0x12C9B955C5C58938ULL, 0x375FAC6B8005E4A3ULL, 0xBB13E4BB56FE9863ULL, 
            0x4ADA3314CF6EEA33ULL, 0x8397E2D8A5AE4928ULL, 0xEEDBBB3D7C208A87ULL, 0x27DA1EFC2745A62DULL, 
            0x042D957992F45BBFULL, 0x7B19A7B1F0F40DDAULL, 0x9EE3BE90434A0914ULL, 0xFF8FAD564422DBA0ULL, 
            0x33EFA17865AB7E7DULL, 0x88D614F46549CC63ULL, 0xCC8DE1E7BFF77E9EULL, 0x2E80DFF11184879DULL, 
            0x8633DDB72013D880ULL, 0xFABEC4DBB708C976ULL, 0x8B9937E16B130784ULL, 0x7365CFAFCCB6BFE4ULL
        },
        {
            0x76A3E936B9DE5B7AULL, 0x49E9E95F2716CC55ULL, 0x7207AA8B29B47A8FULL, 0xE6579DA8473AC87DULL, 
            0xDA78FC4565C6E20DULL, 0x19C0C8D4D107CEACULL, 0x0C97F225F0E9F9D1ULL, 0xB51EC8BF525FEA18ULL, 
            0xCA59E9B9D1974F03ULL, 0x4CB2AA9EC2928BC1ULL, 0x6FD1E7A00C6C51A2ULL, 0xC2BF9B487B9DB6FEULL, 
            0x556F9946418E5B50ULL, 0x52EF7FE23FEF0416ULL, 0xA89A40DCCFCE1B5DULL, 0x42FF8AF8C8B3E0C0ULL, 
            0xF5E76835D7D7D761ULL, 0xA180F998BA3DA23BULL, 0x12C0FC4AFD31F570ULL, 0xD70006E7BEE84E0AULL, 
            0xDEAA852A5B319D35ULL, 0x5E0E6DB9E1FEA06EULL, 0x9F8F0139D686C856ULL, 0x23E1BFF8B0BC175EULL, 
            0x8B301E044698F4F2ULL, 0xBF087263B68D819AULL, 0xD6A32DF7CCA9BB65ULL, 0x023C92FFEE4D8354ULL, 
            0xCFD873F736F522C1ULL, 0xB985204ECA0DEFE6ULL, 0x463D95F743FFD025ULL, 0x0251C25E6620AE9EULL
        },
        {
            0x6FC5D0D20ECE7F67ULL, 0x7EF686B9E3687CDAULL, 0xF10BF914499A41EBULL, 0x56836C05F42F32AAULL, 
            0xA2E843C291737E9EULL, 0x358F95E72522B739ULL, 0x2961F38972451F70ULL, 0xB645576F4DBD8E37ULL, 
            0xF418639CF83763B0ULL, 0x2CAFA6FB2C68D313ULL, 0x49F697CA1389C1FCULL, 0x08F14AF5C8E91B39ULL, 
            0xEDD2C2EDBF178E2FULL, 0xD16D23374BDCCF0EULL, 0xA8F5D91318CD6679ULL, 0x6E78C4DFF10BCB75ULL, 
            0x3F3451BAABC3014EULL, 0xB8001B84CCA4516AULL, 0x97C98468C425B19DULL, 0xA9ED0E4D295FCD20ULL, 
            0x621B931DB94AB6EDULL, 0x0B609C65EE8C6C61ULL, 0xC74F32CFE54A7EA3ULL, 0x81402F14B6DCF496ULL, 
            0xA20FD2D4BF90D1BBULL, 0x9693D8F81428942FULL, 0xD1DB0727ECC5EB9EULL, 0x1D600229AF9DB098ULL, 
            0x37908907ECD30BA9ULL, 0x9B4BCC5302B7B683ULL, 0xE24D721B3F9AD0E9ULL, 0x5974B0C24184A826ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseBConstants = {
    0xD1301BDAD053C433ULL,
    0xE07543A33FAA7206ULL,
    0x24D7B3A6CCB88F21ULL,
    0xD1301BDAD053C433ULL,
    0xE07543A33FAA7206ULL,
    0x24D7B3A6CCB88F21ULL,
    0xBE9A55A4C2DF8F26ULL,
    0x54A9283E756AFAE0ULL,
    0x8C,
    0xA0,
    0xC9,
    0x75,
    0x33,
    0x6E,
    0xA6,
    0x6D
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseCSalts = {
    {
        {
            0x138244F066E0D072ULL, 0xE045C4931005D3C5ULL, 0x6C745012ACBCC1D1ULL, 0xF2544BFBCF7A502CULL, 
            0xE74C926A24704A50ULL, 0x50A711E1E685395BULL, 0x973740DD0214E2C3ULL, 0x793F81E7485BA413ULL, 
            0x742CDC2D00045F84ULL, 0x1036926D3E962904ULL, 0x0A20B875DF645A14ULL, 0x78CE8BE95ABF2B0CULL, 
            0x5105BD1AF3C326A5ULL, 0x5947707934252261ULL, 0xFCAD9173F28860DBULL, 0xF86937E415C7679AULL, 
            0xFCDAF5911BE4966DULL, 0xFC34B8640FDCAE09ULL, 0x6281B8D7FA508BFAULL, 0x03D2DDD82F7B4314ULL, 
            0x466719A4BB08400DULL, 0xF55CEDFAB33851C5ULL, 0xB65A70AA9AEE7CC9ULL, 0xA53D43CF249C0FE7ULL, 
            0x8846FA2D706496F5ULL, 0x0FC68ECFBE3A2B45ULL, 0xF8C91FB9D8209AF4ULL, 0x8BC48A634A14179CULL, 
            0x7975611BB409FC63ULL, 0xD7B6B88C33AF95F0ULL, 0x4A4DA20CB251A3BBULL, 0x4B2238D4D2F4048DULL
        },
        {
            0x7E4BEEA8DD73F07EULL, 0x2FCB16B847BE6825ULL, 0x23ECA52DA4E79AEBULL, 0xFF5568645B53C28FULL, 
            0xA0D87852455C5398ULL, 0xB4650BEC6DD29534ULL, 0x051614B38D4C123FULL, 0x69C3C7012BCBAC17ULL, 
            0x01B996A571586B14ULL, 0x6B11D2CD1FB377B1ULL, 0x481EDE953FF007FFULL, 0xD912D3386246672FULL, 
            0x3158B0203249CAF1ULL, 0xC31A5ACB64C6E4E1ULL, 0x2938FA27B5FC9868ULL, 0x74CE789F5052C0C3ULL, 
            0xE42B0042B837134CULL, 0x6DE919153BD88EEBULL, 0xBBF6EA8A1D594F22ULL, 0x84046AE7B4AAB34DULL, 
            0x41A424C19342BA6AULL, 0x778232D29980EA5AULL, 0xEDCF29B24C7793CDULL, 0x5DB4D873F790FD47ULL, 
            0x8D78A926460A59B9ULL, 0x74EAFBA2205B7FAAULL, 0x26488A504BDDE6E1ULL, 0xD68F9AD810CE4D94ULL, 
            0xCDAA87755402410DULL, 0xA46BDDEFFFEC280FULL, 0xEA30263FFEF7EBE1ULL, 0xDAB5344CDFDBFE1CULL
        },
        {
            0x1B1FEC9041F6C144ULL, 0x834D91D090B452B5ULL, 0xEE731C6508961773ULL, 0x7F7A0DCB523F2B44ULL, 
            0x6E2215ACF627513AULL, 0x6AF2E345EB904B82ULL, 0xB291971035E5A2E3ULL, 0xD1F77DFF67D08312ULL, 
            0x1EBDEA32F621486EULL, 0xE21BDD3FC753F0FCULL, 0x12F311177A864CF2ULL, 0xDFBF3EF6C031F259ULL, 
            0xEEF57A97E0C78C67ULL, 0x4F30665F4E1EB8C2ULL, 0x2058E2FF9EE30D7BULL, 0x4A2B98BB2960C968ULL, 
            0xC85880A69A4DC365ULL, 0x14CBE7F62FDF59E7ULL, 0xA3CFE9EFE46FF7B4ULL, 0x3608EDC4E0BCB00DULL, 
            0xC1ABEB91ECB086D8ULL, 0x14AC5FDAA1AF625CULL, 0x2369DFA8D3BF6995ULL, 0xD4E0B9A554D4DD17ULL, 
            0xE13D9BDE12414FE5ULL, 0x7DC9BDD23755B011ULL, 0x90BC4470DF867ACAULL, 0x6CC4E778824F630AULL, 
            0x8FFDABB797B98F45ULL, 0x577351F5E0655693ULL, 0xDB48016211997B99ULL, 0xE617EB31E41EE6EEULL
        },
        {
            0x9BC18D5DA23F7A79ULL, 0x6501579247CE377CULL, 0x5A24F67B6C982093ULL, 0x2A1E7A093498B2DDULL, 
            0x900C70DFD2915285ULL, 0xD330CFD73D03B351ULL, 0xF15548AE25171D34ULL, 0x4F8DBB8D77ABBDDAULL, 
            0xC12DB35823E8C91AULL, 0x47179060037F757FULL, 0x569FAE88E28F2D7FULL, 0x1A5149C9F7FAB247ULL, 
            0xFC339ABA28BFFFDEULL, 0xDE5EB3206D15C9E3ULL, 0x960D090C90043546ULL, 0x3F0E13B45C859921ULL, 
            0x016EE92B402471D7ULL, 0x02AFB39A43049604ULL, 0xBD74605A38A4DFB7ULL, 0x2B60E6A3E6121655ULL, 
            0x8E5998768BCEF57BULL, 0xADB67B0FA93E592BULL, 0xE1E9065AA34AC548ULL, 0x72A6F5BD5B369C5AULL, 
            0x45B44A69679A391CULL, 0xFA743D0FB69F4CE5ULL, 0x5FAE10879B5A5AD9ULL, 0xDC60044A1FAC5186ULL, 
            0xCADFC36D07E0836BULL, 0xCA340689015CA419ULL, 0xBFA19BED4EA4685AULL, 0xD8DA56400B6A81F4ULL
        },
        {
            0xA6D0710762988036ULL, 0x5067D8FDCC472EEAULL, 0x5DCD6C7D60098531ULL, 0xEE79CB9BB049817CULL, 
            0xAC3AACBA1A734008ULL, 0xFE262F9DD6EEAB71ULL, 0xD8AE4A79FEA0EC30ULL, 0xD24E623597C50847ULL, 
            0xF057DD3FCAAE2EADULL, 0x2E28499AF93FA67DULL, 0x9DF82355D3C07396ULL, 0x24D5F0EFEB1EF344ULL, 
            0x3CA6E479368343B4ULL, 0x928D6078A6EBED0DULL, 0xBAEE8BB035A772B1ULL, 0xDB14437F37BEDF7CULL, 
            0xF87686A4011536F8ULL, 0x9C83CD05781EBD36ULL, 0xF010AF5F5B4AEF98ULL, 0x437E41A094EAD637ULL, 
            0x2F690F83D190FFC0ULL, 0x1FDC5FDCC983E070ULL, 0x48991EBF7317D9C8ULL, 0xC2C5F8F8FB7D766AULL, 
            0x865E7D7E45FB9B53ULL, 0x7423DAD7CB864F6FULL, 0x6B9E19613C9E5FF5ULL, 0x95800A96FA52418CULL, 
            0x84184EF56425634EULL, 0xD66B31912AD8E50AULL, 0x59FC6DFE3261088FULL, 0x009E3BC0B1616D95ULL
        },
        {
            0x5B9E5993CF0BF1CCULL, 0x8783775CA53C5132ULL, 0x79C40D7B41F0BAACULL, 0xB844F3D5630050CFULL, 
            0x8B68E3A54D5E6CA6ULL, 0xE6558F5D8F3E492AULL, 0x35BBE7C8F8EBA444ULL, 0xAEB6EB5BF90CA11EULL, 
            0xA756345AC253FA0AULL, 0x2371C4C597262E94ULL, 0x7B1BFB6796D30F17ULL, 0x511FAFCB199E721CULL, 
            0x39CA3C2EEAC2B7C6ULL, 0xEB56AD7F8BC4FFC3ULL, 0x7F0ADC99802E2866ULL, 0xB20F1230AEF80E2EULL, 
            0xD5A141F941433A87ULL, 0x9DC7F93B898ED92EULL, 0xCDD23956A5F706C4ULL, 0x1C3F8D99A846840BULL, 
            0xA975F819940CC755ULL, 0xF10878C6AEA68703ULL, 0x33A98DCD54E27050ULL, 0xBB5880DFA15F84DDULL, 
            0x85BEAE56EE83AF26ULL, 0x8F545766DD0D0953ULL, 0xE769B08311F64551ULL, 0xEBCE0016F2C3890EULL, 
            0x2D004F8454AE9D36ULL, 0xD6DACF5940F4D182ULL, 0x461DB98BC636EAAFULL, 0x8C7AF1A04BE12C90ULL
        }
    },
    {
        {
            0x82792BE7FDFEDAEBULL, 0x06FAE447B0FC2830ULL, 0x5E8A6E3E074E567CULL, 0xD0CA17189D95D64DULL, 
            0xE2ACE81A64262837ULL, 0x7848C1E38282D6A9ULL, 0x5E410E8C56359A8EULL, 0x2D124D3838792E97ULL, 
            0x869818D697E107D3ULL, 0x93D7E9E42151A6FEULL, 0x865BA611AB5961EFULL, 0x4DBE4F37182BABCBULL, 
            0x2F7CDEFAEC8CDA32ULL, 0xC972139115124CA5ULL, 0xD6EFDE3A582A68F0ULL, 0xB2E0D0D4F6F5CFA3ULL, 
            0x95683709FED6C148ULL, 0x5C8F6E8BC6C1A3A5ULL, 0xE49D084CD5ABC06AULL, 0xABD4FEA1796DC3E4ULL, 
            0x5042917FE59D0C8BULL, 0xB898873338E7CC69ULL, 0x61B86E01CCCAAF15ULL, 0x6463E092020B040CULL, 
            0x94F470A91503E6ACULL, 0xC3E709780BF97295ULL, 0xAC261AEE304F64E5ULL, 0x9146A4AEB713BEA6ULL, 
            0x54DA8FF11A47C6BDULL, 0xBEB162E3B58CE9D0ULL, 0x49D5062F54BA1456ULL, 0x56189FB2AE536C47ULL
        },
        {
            0x27B41C6B5613A2E6ULL, 0x635FA70D5096D322ULL, 0x69C65F16161002C4ULL, 0x951D37A2874FA406ULL, 
            0x249378BF7D717417ULL, 0x3A339DE77512B35BULL, 0xD9B7EC841B565ACAULL, 0xB5F2F83810D660B1ULL, 
            0xF026B49BE7A01E09ULL, 0x1DF21F491B2F8FE6ULL, 0x0671B28475A6F325ULL, 0x76677674749C1315ULL, 
            0x6835EEBE60D3FD15ULL, 0x0B0C002412AA122BULL, 0xC4CE6D401323C6C8ULL, 0xDBB73DA485F6CEF8ULL, 
            0xE9DC63AC8D795186ULL, 0x1A07CBB69FF91113ULL, 0x23E8A51E8FFF6B1BULL, 0xCA3E8E4F3CE78D8CULL, 
            0x57BF4C60BC4BB200ULL, 0xA1406F8EAFFD2673ULL, 0x451897364EAA3436ULL, 0xE8740686513777AAULL, 
            0x96B26F0FF9145404ULL, 0xA095A66D61DC7AD6ULL, 0x9B120D4CFD0A1F87ULL, 0xE967D32B1C7C9AFFULL, 
            0xCDEDC8952A1AFF13ULL, 0x031B75774884341AULL, 0xDB144964EBB91134ULL, 0xA9833CB0CBD09846ULL
        },
        {
            0xED50BB89792317C1ULL, 0xCEFF650D02905155ULL, 0xFA830C99FEFD071EULL, 0xDBF525E5BFB6DF0DULL, 
            0x60C36A463719779DULL, 0x61863CAF2434A301ULL, 0xA8821919394608E3ULL, 0x9873A2AB5E01A844ULL, 
            0xA769ACA66270CA21ULL, 0x8236A250D1197FA6ULL, 0xE8581287714B7A23ULL, 0x08E854439ECD6A1EULL, 
            0x424D3AEA1903AC30ULL, 0xF3C0EE575E723A31ULL, 0x13B8366B3986825BULL, 0x2D60C42ED267CA4DULL, 
            0x414BB34AD1059B48ULL, 0xD2C0F68924D8F122ULL, 0xFF0DF6A50D84DC5DULL, 0x324EFFD8FCE6C874ULL, 
            0x8FD1FC9544F1534FULL, 0x86626579A7FA18F5ULL, 0x1AA4114412DBE857ULL, 0x001D296AE1220AF1ULL, 
            0x91A0D3C44F9D1B2AULL, 0x0853A76BAF559E3AULL, 0x470A22306AE96DF3ULL, 0xAF4E5493C808C231ULL, 
            0x80DA84772E5BE333ULL, 0x1DAFDCCED50B110EULL, 0xE8309E04C9EB6258ULL, 0x90A08278A5530A4DULL
        },
        {
            0x0BB44781D0589A04ULL, 0x5C1F6D1804ACC0B2ULL, 0x9BF3C6AF331F6877ULL, 0xFB0B68421F4A34D0ULL, 
            0x7BE2559217F71EC2ULL, 0xFC624F4FA0F80054ULL, 0xAEF1F448B68193DDULL, 0xD7F0AF4E04FCC06BULL, 
            0xE7947EABDC907E50ULL, 0x933D5488815BD1B8ULL, 0x077FA5B0B3D3EA1CULL, 0x81261F4DC87FF97EULL, 
            0x8813B584D26B45CDULL, 0x7A19F1C45375680DULL, 0xD1987DA06B980519ULL, 0x512EF6470576D886ULL, 
            0x169D25BCC7E15293ULL, 0x719B85524037E137ULL, 0x3BF8BADB15081A93ULL, 0x4C04344002F225FFULL, 
            0x501AC5F525772EAFULL, 0x5BA1976E08F1136FULL, 0xD79B1E371A8B6298ULL, 0xD5357B2139179191ULL, 
            0xE550E50864BCF5D6ULL, 0xD8C44F5E894F7512ULL, 0x3897EF7514923AF0ULL, 0x8BCB9303B5E0B10AULL, 
            0x37ED7F090C6CADA9ULL, 0xE262365828733CD7ULL, 0xA16F38F00819A7A2ULL, 0x3A0C34D3EA21A846ULL
        },
        {
            0x2FB8EA6F2748B705ULL, 0xA9B217EC3A7007D4ULL, 0x5F8DA1EB4F310937ULL, 0x1909D752A05A7517ULL, 
            0x051CD39F2FB7F577ULL, 0x0B2D409EA6E7798AULL, 0x3A455730EFB8F070ULL, 0xCCA2D7843626B69CULL, 
            0x70227757F87C05BBULL, 0x596791DFBE9B4FB7ULL, 0x5B06E6398528C056ULL, 0xFE8FCFACD0EE2EB3ULL, 
            0xA05E8070645304A0ULL, 0xAF48B0887469DFB1ULL, 0x59E6F70A3E6975E9ULL, 0x568F09196A583B2FULL, 
            0x413E9418B06BC57DULL, 0x394693E4D61FEAEFULL, 0x2B62C76C475E5549ULL, 0x3C9BB5A6CF456B14ULL, 
            0xB66DFA17C4D1912BULL, 0xBFDDC6AAFD5163D0ULL, 0x668549800DECCE50ULL, 0x5724DD70310159BDULL, 
            0x4CDBBFF9F0AEEA5CULL, 0x47C59B38E3E559C0ULL, 0x55B76752C6C63842ULL, 0xBFAF0DAC99970E6AULL, 
            0x437B4A040F93B889ULL, 0x10B0B2685623A0B0ULL, 0x58EE8AE3B37553B3ULL, 0xD5368C6F36416791ULL
        },
        {
            0x547454F6479A4871ULL, 0x1965B072307B0D85ULL, 0x625DD42F90742B15ULL, 0xEBBE6F6F293605EEULL, 
            0x3F2782CC8CA7414EULL, 0xB2E63AE646EB43E0ULL, 0xCDA34D5673FED9DEULL, 0xF9F320D2CC162C77ULL, 
            0x1A4570244F1CC3DDULL, 0xD358E3056B304C9AULL, 0x5B278D966070458BULL, 0x2685923AE4D63596ULL, 
            0x79E62349A1038EBCULL, 0x1EF9777D20D2BCBCULL, 0x2D446EC6E906C937ULL, 0x5A69C4B5BD760143ULL, 
            0x0AA14D30D50A62E3ULL, 0x7F043FE81D87F6E4ULL, 0x52E6C2BB1D04A63EULL, 0x0BF460D8731AEB36ULL, 
            0x59CFAC66942CA983ULL, 0x94E1208F8E000D01ULL, 0x92A31287893E7C77ULL, 0x548FABFE0E45DBEBULL, 
            0x9BD6DA40D2E1D9DCULL, 0xD4D2A89EEC80209CULL, 0xAB8AA174A46CBB25ULL, 0x0F3103B5139E658DULL, 
            0xD702A8CB4AF68297ULL, 0x0F5BB842039B09C4ULL, 0x2B758B86F6531BFFULL, 0x2FB50E08BB1E29A7ULL
        }
    },
    {
        {
            0x88C87B947AD1B763ULL, 0x83E084574B2E87F2ULL, 0xC421B19FB9837E42ULL, 0x19143A1A811D7785ULL, 
            0xBD7006BB0A0C5937ULL, 0xB986562203AAEB3CULL, 0xBBEFA5D96C11DA50ULL, 0x08FBCA9198C32ABAULL, 
            0x539D03AB890622A1ULL, 0xB04B0D4DAEAF9179ULL, 0x017EC518AD16EF9AULL, 0xFA9676E6404FB04CULL, 
            0x5F0737FF98B83E49ULL, 0x587E35B15E3AF7ECULL, 0xE80594975C77C527ULL, 0x15151D6297B498B9ULL, 
            0xB9983D442B45D827ULL, 0x597C12E6E2ED838EULL, 0x30A699BAE05805FCULL, 0x6C382BE0379B9D5BULL, 
            0x822121BB5D0E0CF6ULL, 0xAC1E2DEB874DAAEDULL, 0x188F9CCDD5F3D5C7ULL, 0xC0E8594C94AF8F2EULL, 
            0xF1479C7886B1D969ULL, 0xF861A49C00B81FF4ULL, 0xF9D5298224A642E7ULL, 0xE63B11D2E1E481C4ULL, 
            0x27E2BF35F76FC27DULL, 0xDD1B5802B539EC42ULL, 0x25DFD56E65B121E5ULL, 0x4A946E10BB830BB9ULL
        },
        {
            0x242407FC40C994ECULL, 0x14B51FDA9C2C2502ULL, 0xD47303DC0925B4B1ULL, 0xF9AF6AA47B8009A1ULL, 
            0x79F164D8CC07837AULL, 0x69A1202C34CC2FB1ULL, 0x4A351EC4338247ABULL, 0xD2D3430699E5966CULL, 
            0x54B4D99BF9704845ULL, 0x8695C990580FBE5BULL, 0x1E9774BFC0054AF2ULL, 0x192E30B69FF097FBULL, 
            0x134E36C616D030FCULL, 0xB47F77E028599A28ULL, 0xB40A60E6D9CCC29DULL, 0x1DCED4B6815CB067ULL, 
            0x2D0FF2850000C6FFULL, 0xF62D38A0DA48C180ULL, 0x86F0A12D086856F9ULL, 0x4C01E372CDED6994ULL, 
            0x7DF612631A45D6F6ULL, 0x2E54C2A2EFB3C343ULL, 0x430CF848C273B3F5ULL, 0x9ED9156F8CDE822EULL, 
            0x717C5CEAE8BA815DULL, 0xC5810B5F348A3AD1ULL, 0x1E1913FF4BBE2EDFULL, 0x91935FFCE79782EAULL, 
            0xFE6F138A3F84F013ULL, 0xB868D8BA6313DDCFULL, 0xFE7ABE817119041BULL, 0x69D686EE97E57438ULL
        },
        {
            0xEDDB1BBE7B5FF0BBULL, 0xFE683FB96C35B72DULL, 0xCA4D0D298B5C1F93ULL, 0x084470D39891AAAFULL, 
            0xE3D12C059B2DF1A6ULL, 0x6FA9D40665E8B3FCULL, 0xF3DA7175FF0D3751ULL, 0x3B6BE40970C00648ULL, 
            0x00FE3E09F6BE2793ULL, 0x3C0A647EDB6DEEBEULL, 0x6F62D5F27FB5148DULL, 0x60FBDA70A1A18D71ULL, 
            0xF4F3D9B374A1DB94ULL, 0x27A07B17F1BDC2C0ULL, 0xCD97AAA0C26EC9CAULL, 0x89861011B00E7588ULL, 
            0xE222A4FB4A52C8B7ULL, 0x1F97E850996B1662ULL, 0xA93831D1A838F396ULL, 0x56287D660C4A2283ULL, 
            0x9FD06D2E28B0F419ULL, 0x92C42F3C1DC1E90EULL, 0xAC7D9FB49BA84D58ULL, 0x4C6E44703EA588D9ULL, 
            0xF3CE0E2793FB40C0ULL, 0xCD68047C7B0998D6ULL, 0x8A225BCA2AB36E08ULL, 0x749C46F834E54791ULL, 
            0x1A48833DF3F3F78CULL, 0x1BE69BC69594E613ULL, 0x7C8FC5CF50FEFFBDULL, 0xB52979198E044159ULL
        },
        {
            0x397D3580391B20D2ULL, 0x8BEB0F777F797827ULL, 0xD8211CA978A4D064ULL, 0xB0E7C8B741A2B2D7ULL, 
            0x5A24CE2D1D1DDCD6ULL, 0x199FE65D684591EEULL, 0x2AE12414CEF8C730ULL, 0x6EA03C5B82A12847ULL, 
            0x4658F3C60582D1BDULL, 0x299A2755E624752CULL, 0x76800AEC2A381D60ULL, 0x8D9BEE70BD076D73ULL, 
            0xFD357170E37B4903ULL, 0x65D646A78568C407ULL, 0x64AAA895D0340715ULL, 0x20B8A196FFD8EECFULL, 
            0xA849FD8BF1D092B6ULL, 0xAC726D4542390CABULL, 0x5EF95FE7EB837B2CULL, 0xEDF3F01A730DA1C5ULL, 
            0xCAC606F0537FB045ULL, 0x369C036CAFF2BAE1ULL, 0x834E736FCC272DCDULL, 0x2C1945F524265887ULL, 
            0x2B7ACD36949999D1ULL, 0x8A68C671F5F7AB03ULL, 0xD7671547B7C1D707ULL, 0x1E2FC41D83AE1A60ULL, 
            0xD28245ECEDF08EBDULL, 0x0B533B20DFC691F5ULL, 0xCD0C5BFD3AAEE95DULL, 0x02FA9C49FE925EF3ULL
        },
        {
            0xDF639CD3429ADD20ULL, 0xACA5A938C457D378ULL, 0x9B0A431AA77F676EULL, 0x35F275B60F792782ULL, 
            0x050C1EE77D134069ULL, 0xC0446A5B403517C2ULL, 0xEC53BB92864E5458ULL, 0xA0DB27A0DFF5516FULL, 
            0x8CE0EFE91D362E5FULL, 0x07F6F3312159BC91ULL, 0xE8FC33C68EFD6FA6ULL, 0xBD6225A97231E929ULL, 
            0x0278B6F11579F600ULL, 0x667471A7A4D8B6DBULL, 0x0A260C50E6A489E9ULL, 0xE1B90AAE5FFFE016ULL, 
            0xEFC3FEC76220BB70ULL, 0xDFF82BC488E50B35ULL, 0xB63BEE1FE5B2AC19ULL, 0x8D0EFC95369AF2E5ULL, 
            0xA105A98042EF247EULL, 0xA78617BD0FEAC665ULL, 0x2FD223D907CECFEEULL, 0xB92366C087377466ULL, 
            0x872B207E9765CE5DULL, 0x9DACCDD835E4545CULL, 0x43A63FE3713CD435ULL, 0xB3803EB75475D432ULL, 
            0x9A264EB5BA36C20BULL, 0xEF652A64C0570D33ULL, 0xB656D8E98AA19DD1ULL, 0xED215682B028C3EEULL
        },
        {
            0xB627F2014075D33CULL, 0x004943F6E94A9B80ULL, 0x276BEC06CAF51B75ULL, 0x86574A2957F66A6CULL, 
            0xA680BC14109C6CCFULL, 0x04D2B69DFEC77BD3ULL, 0x9BE281DACB7DF76FULL, 0xC633E147D8B5B027ULL, 
            0xB78673C3A677E5EEULL, 0xE9070481C47ACB72ULL, 0xDF5A2F0B7576A35BULL, 0x788A67C7FA6B4381ULL, 
            0xADC5D91C43AC2688ULL, 0x1204BFEA1828426CULL, 0xF14C0E7987A1B8B7ULL, 0x805F28FED83CD2AFULL, 
            0x87A7FAABB6D8B839ULL, 0x05F14CFD32DD098AULL, 0x477653863278908CULL, 0x846F2894822F7217ULL, 
            0x7945C2AC03300C9FULL, 0x21F3FB893E979C73ULL, 0xE4049F85C9159F91ULL, 0x3F7CD5C40DB081C9ULL, 
            0x525D098494FB112DULL, 0xF646905CCBEEF1ECULL, 0x6916001B2C63BAD4ULL, 0x12435DF924B4B799ULL, 
            0x97B2B1A2AA8AB5E2ULL, 0x49A43BCAD7F2A6D0ULL, 0x57FB16BF7AA1D858ULL, 0x1E04116359DAA25BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseCConstants = {
    0xB9BEBFF8AB395BC1ULL,
    0xF67FF2491D2A93D5ULL,
    0x86BD16992474DF73ULL,
    0xB9BEBFF8AB395BC1ULL,
    0xF67FF2491D2A93D5ULL,
    0x86BD16992474DF73ULL,
    0x4025756F93A3700CULL,
    0xF80F73D0A3C25F4CULL,
    0x6D,
    0xBD,
    0x43,
    0x55,
    0x30,
    0xA9,
    0x9C,
    0xE3
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseDSalts = {
    {
        {
            0x55BE97AB1E140E3EULL, 0x15A2D7B9330BA8ACULL, 0xFB2AFDBB5F937817ULL, 0x7E69058E2163310CULL, 
            0x9159C15BD8117EE1ULL, 0x9CE5DEBDF8804682ULL, 0x2B962CCF7D7011F8ULL, 0x5CE48BC05B316F81ULL, 
            0xDB2C2BFAFDDBC228ULL, 0xB0620163A5FB447BULL, 0xE3A63240984F1E12ULL, 0x72CB48ECAAF886F7ULL, 
            0xFD0FA4D84BBDA954ULL, 0xA3960F869B6A23F7ULL, 0x942EFE54C864CF12ULL, 0x2CF3E36DAAE3BE5FULL, 
            0x431C96C138E45D1AULL, 0x856E6545E1866DCCULL, 0xE3228B9DE0768599ULL, 0x836EB55F4A72DC39ULL, 
            0x664F9F8183BB8379ULL, 0xF8E5F0F513907A5DULL, 0x02358E32EE8D1CD2ULL, 0xD56A3923A690CD7EULL, 
            0xFCF63C3B4AE2D550ULL, 0xCF0BDA6779C716F6ULL, 0x22C7135AF9262543ULL, 0x39466B776303BEDBULL, 
            0x8C38CE4844C9AA5BULL, 0xD2D9859DB52213C5ULL, 0xE00CDEDFE54FB73CULL, 0x2528C1DA1ADDCAF4ULL
        },
        {
            0x3A15729458DA50B6ULL, 0xDED1A5E19C7030F5ULL, 0x02765391B563FCD3ULL, 0x2DE1D6244DD7A9D6ULL, 
            0x644ACF826FD4AEFCULL, 0x6EAFA06616AA4128ULL, 0xF026142C42903F84ULL, 0xA96DFADF3C4561FCULL, 
            0x7FCE776D077A51E0ULL, 0x62FD80390CD4E012ULL, 0x06F1E00EB8BBF5B8ULL, 0xC208202FDAB61BB2ULL, 
            0x265A4E95A4561EDDULL, 0x988DED267F47C6ABULL, 0x4DB574E9DE4CC051ULL, 0x845799A2C7C6D264ULL, 
            0x55C65E3ABA5435F3ULL, 0xDA7A82A0E3412E04ULL, 0xA8ED023C354BE540ULL, 0xF3FD62505CA6B76AULL, 
            0x73B56CD96BE57174ULL, 0xF201CDAB5B06E5D3ULL, 0xA3BC1D0DF59A7B84ULL, 0x1C8337C19F3B22C6ULL, 
            0x73D15785ECECE7F1ULL, 0xEE7CC1A99A9A0DCAULL, 0x5C3993261E6B592EULL, 0x7AAA3F7A57201704ULL, 
            0x0910C1FFA7698CA3ULL, 0x7F93507072C8AD62ULL, 0x51E7571C7027AB96ULL, 0xF00C5E660CC8ABC1ULL
        },
        {
            0x8AF7AF424136EBC7ULL, 0x48312DEC1FCDD955ULL, 0x5B4B7AE6E422F20DULL, 0x6F4DA5D01316D3EDULL, 
            0xBB67E3526471DA1FULL, 0x11DA7873A21D89C6ULL, 0x083DE7A9DA7646DFULL, 0xA0C69DBFE1A1A041ULL, 
            0x1679CD25B3D95827ULL, 0xB8E39E6689A6A64FULL, 0xEE6D0BAE13D56863ULL, 0x90D1C178088071F3ULL, 
            0xA8BEAF067EAB9CD6ULL, 0x8ABA5B283619DDB8ULL, 0x80167A074525E0F3ULL, 0xAFCE6980CE2FE68DULL, 
            0xC1071105321A815AULL, 0xF0F048BA9BC25536ULL, 0x988307EF92E3506EULL, 0xD0A42A8202C42805ULL, 
            0x705D5C753E1B0BC5ULL, 0x5FD27DFF7A97325BULL, 0xBC30EAB699B9A865ULL, 0x5749BCD5FB48FD78ULL, 
            0x8FA7983CDEA8E42AULL, 0x2A772E39A098AC46ULL, 0x982746E9BDEA9B40ULL, 0xD7EA430E1AC86B08ULL, 
            0xBE42106E0D42BC84ULL, 0xBB71CF71066C18FEULL, 0xE66DF1C3C9274CE3ULL, 0x0A1AADC4329EBB52ULL
        },
        {
            0xD68170CB5F0ACC0EULL, 0x2881F4D1A992485BULL, 0x024A8572F104DB44ULL, 0x5E96813126753602ULL, 
            0x1CA4425A074505E4ULL, 0x455F3B54043AB08EULL, 0xFDB6C19F8AC8D7FCULL, 0xBBE34E87D12A1EB3ULL, 
            0xA1D35DD59C7D1D00ULL, 0x1C98FE7306015E2DULL, 0xE544449DB05D89BBULL, 0x2D4846371D6281A9ULL, 
            0x7529BA94CD89B64BULL, 0xBBA4ABE2D97F3051ULL, 0x041EBD37871724CDULL, 0x4B0FE59FFEDABFFCULL, 
            0xDF9EC776F9E6C909ULL, 0x0A2A050D5ED2BBB1ULL, 0x65328B2589C41634ULL, 0x53ED6D03A256B3C3ULL, 
            0xC83D275866F9F93DULL, 0x762DB4D21804636FULL, 0xE7BF4CF97BA8C5BEULL, 0xA0DA9CE245205B9BULL, 
            0x408E72A9A81BDB5DULL, 0x138652B176869F4DULL, 0xDCE96F58C5DB693AULL, 0x212ED081F62CB49FULL, 
            0x5D5E49264A07A089ULL, 0x21C8480CB30A96D0ULL, 0x40F28599040EAA71ULL, 0x7DAD364FF74567A2ULL
        },
        {
            0x41D064BD6349C5FDULL, 0x5909F17A91AC9EFBULL, 0x51DBFCCEC8AE661BULL, 0x81A7A1D595E5098AULL, 
            0x075446E3B01C2428ULL, 0x956B8AB4F0746E28ULL, 0x22931C79392801AAULL, 0x7CFB0DB05EC37F4CULL, 
            0xD8258DE0925C9B8EULL, 0x3530BDA4F2E56A5AULL, 0x97DC6BC4C19B66F3ULL, 0x7687A0E6800A63D7ULL, 
            0x2D3FDD12FFBAE758ULL, 0xA35F448FBAEDD1FAULL, 0x2CAE60F4B2FC49EDULL, 0xCBBC7972D7A6983EULL, 
            0x29EA67C1053C8EBFULL, 0xDAB67D0652B32A3CULL, 0x676696584250A64EULL, 0xBDA18B6511814604ULL, 
            0x87B7E7AA22D4F1B5ULL, 0x41BF0F2C8F7A92A9ULL, 0xEC95DF6948EBEB39ULL, 0x418B5E15FEC87BF2ULL, 
            0xBA6E6E6145AEF2EAULL, 0x0541ED5C6EDF7119ULL, 0xDAC9FD602AA1A29CULL, 0x10FD405EE9C7B322ULL, 
            0xE6D8C5E0683A824BULL, 0xE80EDBC28CD624FAULL, 0x3BB0C0A0B6FB4E67ULL, 0x889604BAADBC35DBULL
        },
        {
            0x942D1B30A77089C9ULL, 0x268BC744EBCAC223ULL, 0xB97B64D719B12771ULL, 0x86C15ADAEEFD71B5ULL, 
            0x4BA2338D4C520F2AULL, 0x3518E875C1DAE640ULL, 0x45AD4442C74DC0ACULL, 0x4211B525ABB394D4ULL, 
            0x5F975586EE679C98ULL, 0x3D79673A5B16E571ULL, 0x74CB0A40B36E88F9ULL, 0xD8B0545DE4390129ULL, 
            0x2B86417513DA6736ULL, 0x0D2826B286B22F49ULL, 0xD5080473BECD4C8CULL, 0x22D9F0AE2FCF2F7FULL, 
            0x09FC180AFF20FD9DULL, 0xEB7AF05A2A770FDFULL, 0x901E3472FC861252ULL, 0xCCA5284D20416DCEULL, 
            0x1AE03952736A7391ULL, 0x8956DCABBCE79191ULL, 0x3B645F0332310608ULL, 0x8D5407DC35198566ULL, 
            0x6472CE215B084DC2ULL, 0xC22F590C058FEE35ULL, 0xD66CBCD28CB3527AULL, 0x3A2A6D838C8B70BBULL, 
            0x17CFAD554654A951ULL, 0x003244B3B763BECBULL, 0x8DB54BCB45EF3E8DULL, 0x233DC631229595C7ULL
        }
    },
    {
        {
            0x1E010783B9927CE0ULL, 0xC42F91A89B2AA90CULL, 0xD0537B63FDF5FA8DULL, 0x2BDA6CD8F9C506E9ULL, 
            0x3A86981046173EFFULL, 0xDA977BD4ED4A0C9DULL, 0xB984A140E4CA0E4BULL, 0xB2667ACEFD8B486DULL, 
            0xB73E7014051BD21EULL, 0xEAD2598B7625AABCULL, 0x72B82FE91442DB44ULL, 0x8193EC2BB55FD270ULL, 
            0x5AF19516ABF751BAULL, 0x93019001C07D4F10ULL, 0xBDDE9633C00E8892ULL, 0x2AFBB4629A80876DULL, 
            0x07862E7D0B88A6FAULL, 0x1B6B6911FC853F01ULL, 0x92C406B7EDC6678EULL, 0x39E6DB330C9C3A0CULL, 
            0xAC35048E167A4C32ULL, 0x0A9F38679C56C9A4ULL, 0x9E3E5AA58400D5DAULL, 0x5CC7069944AE9DA4ULL, 
            0x567AF5EC738A134FULL, 0xC0C2C2B3429EB53DULL, 0xDC3747E4244F6C26ULL, 0x1D171220454EBBD3ULL, 
            0xC12737C02C8229D3ULL, 0x12DD20DDC8D19212ULL, 0x6A7C0C50A29EA3A3ULL, 0x2F2FFDA87DAE36EAULL
        },
        {
            0xA59A466051FA6493ULL, 0x5568DFB5CD526699ULL, 0xB6269A1942B21673ULL, 0xBC9FB8B1FCE1D33DULL, 
            0x7B6DC81B5A19D9F4ULL, 0x38D95544D210C5A3ULL, 0x075D7DEE8EB08D92ULL, 0x80AC4F390CB16AACULL, 
            0x89D133AAF091EB7AULL, 0x0AEE95CD2DE8F526ULL, 0x6F6EB477C9772F41ULL, 0x1C23EDA08FDF40BAULL, 
            0x63F338D7B51DCEEBULL, 0x738F710D76A9C631ULL, 0x4D7E617AF509DD7CULL, 0x93BA4DDF3DD6FEE0ULL, 
            0xAF942710E7985DC7ULL, 0x11E6ED6525719A45ULL, 0x734F88BCD1EE6DD0ULL, 0x83C83D57C3067127ULL, 
            0x3C65EB5D330F4CC4ULL, 0xEC06A473FB68F08CULL, 0x9AB990239F891872ULL, 0x25B0E46124E2C66CULL, 
            0x37A73471E1EF3F6EULL, 0x696ED06B01D21398ULL, 0xDE362193A95FDA4AULL, 0x9BE9D752F2A02A8AULL, 
            0xAE9486B5118333DEULL, 0x408C2ED3AE305489ULL, 0xDB3EFE4F673FDF44ULL, 0xCAD77B0190D1086AULL
        },
        {
            0xAE89DFB8C97A88D1ULL, 0x0485E16063B5028DULL, 0x2E092192DF1ABCCBULL, 0xAD6C5FB87D211942ULL, 
            0xCF0836FD76064E06ULL, 0xB631232C54022919ULL, 0x1789EFDDF94C7E7FULL, 0xEF2A3792EDAADA0EULL, 
            0xC2A69C27BF61EE25ULL, 0x837893A45793B7C2ULL, 0xC4B269CF90ED0677ULL, 0x0413249D000BF248ULL, 
            0xEC7ECE252E70FA20ULL, 0x4130A90F7BC6E5BDULL, 0x22F34BEC690EDC6CULL, 0x21BA3F01944F425FULL, 
            0x583E098237BBF8B9ULL, 0x71B1E40E657E13DEULL, 0xA655BE3C3E912BFAULL, 0x6D421F5D036BD2F9ULL, 
            0xA1480573B75B4D03ULL, 0xCB59383451ED462BULL, 0xC3125AC934FD1E3DULL, 0x14AB6819CF1111A9ULL, 
            0xAC6E39BBBB1004E8ULL, 0x563E362C7377E120ULL, 0xDAA3E3944938A795ULL, 0x65C066548829B0E3ULL, 
            0x7A2DE96795B333C7ULL, 0xC06076F94DB2CA9DULL, 0x7623F4C02A4B6ED3ULL, 0x05774D257C914095ULL
        },
        {
            0xA5057DB043657DB5ULL, 0x532A29A9BF4E8D96ULL, 0xA835B7BE0D67B357ULL, 0x7C435AD01714877CULL, 
            0x6A127CCDAE263AF2ULL, 0xDF6A32234343FA38ULL, 0x4803843ED814A3DCULL, 0x5A2C0DFC3CC8E07CULL, 
            0x40250B38457E732FULL, 0x2B4C063C386DB432ULL, 0xF08B5DA8A7D29BA6ULL, 0xDDBCBABC09C8D1C8ULL, 
            0x6DCDA58BEFEA0762ULL, 0xA0B6951E021477D6ULL, 0x73530AABDCFB4A8DULL, 0xAF6CDF1DD4E9340EULL, 
            0xBC30A785DD18721EULL, 0xADD55E23266D9C04ULL, 0xE31632744FD01CEBULL, 0xDEC94EA29202301AULL, 
            0xC9E91F7D271D7E72ULL, 0xF3CB4D798F4ED7BFULL, 0xF768C379FBCCD267ULL, 0x0265887C03557A8EULL, 
            0x22E7DB808203A5FAULL, 0x87609A6835E4997EULL, 0x126CA161C0B2999DULL, 0xEBCD711187918A34ULL, 
            0x435B2B75E1B228B4ULL, 0xF2E0FF090BD9CD59ULL, 0x89E913EA2C94F492ULL, 0xDD9BFA1AC1C99BAEULL
        },
        {
            0xD3178EAAD2F257FEULL, 0xF5DE380C590B544DULL, 0x458AF45A825BE8D1ULL, 0xD7ACD059E2129635ULL, 
            0xEE7F8919A30E7D63ULL, 0x726673FB8D34622EULL, 0xE459A3C020F71D1DULL, 0x3D796D85684D9B81ULL, 
            0xA55A430C1391EC8CULL, 0xE47E45D11CB2DA1DULL, 0x1AF892C83BF98EFCULL, 0xDACE677D8AD883BAULL, 
            0xDA0E557CD5CC10BAULL, 0x59944C3BBCE1DA2DULL, 0x6BBA3F7D5ACF4C4CULL, 0xF1932B374DB67879ULL, 
            0xC996ED99CBF00D9EULL, 0x82A32096560AD9F7ULL, 0x4BD9DB66278322A5ULL, 0x885A3E26A9AB6598ULL, 
            0xEC199B351A3F248EULL, 0xBDB84FE1DA1C8A2DULL, 0x967FC6C33AB95A9EULL, 0x8A3723456520CE13ULL, 
            0x0477A29530F38EF5ULL, 0x6B2FF4F4B04899F5ULL, 0xE68DBA1F346FFC9EULL, 0x87B383F7F5333E68ULL, 
            0xE2D2A37B26484986ULL, 0x05DAE56CC67E4409ULL, 0xAC97B8EE97F58BA9ULL, 0x6FF497FAAE1CCFD6ULL
        },
        {
            0xC8EAB6ED85BFC299ULL, 0x10EF44FBDB49687BULL, 0x5F322BBF603BFB19ULL, 0xACC74CB02C5F4F9EULL, 
            0x6E19A4AEB93999DAULL, 0xB400A6C19F9167F1ULL, 0xBAD8F09F6C6D9F8BULL, 0x761A58FA773538EBULL, 
            0x241F63F583E3CD07ULL, 0x5720B60C6921EF99ULL, 0x9F26B4C508B24321ULL, 0x395F8914BEC015A2ULL, 
            0xF9953B11418CFCA7ULL, 0x0DE5AF33C9786810ULL, 0x96693ECE51A57DC8ULL, 0xAB32EC71D1EDC089ULL, 
            0x78661B96B961C7C8ULL, 0xE361CF8CC1BFE7FEULL, 0x45F9A7B7601A31F4ULL, 0xA96C29980F89681CULL, 
            0x54E78306EA7DE600ULL, 0xBEDB5A0C5010C90AULL, 0xCC2C89A36D5E9215ULL, 0xF35095A57055AFC6ULL, 
            0x4B7C5421E8D81F32ULL, 0x9735AF56E32D18E2ULL, 0x4523CD3BB9C0A40FULL, 0x79A32602736D1A51ULL, 
            0xB050414D47585B7FULL, 0xED6A3B7DCA02A648ULL, 0x6DA6A26287BC7B74ULL, 0x847AB9C9B3BED721ULL
        }
    },
    {
        {
            0x69E7E03B09E950E4ULL, 0x1EA7B2B285A365D1ULL, 0xDD6F80216C294141ULL, 0xB747AF26EFC6D0EAULL, 
            0x899C29C6621F790DULL, 0x9D3FF15A47D00506ULL, 0x484AE184A13FF32AULL, 0xABF75B54DF7F76A0ULL, 
            0x009490DA68197E35ULL, 0x1DCEB742AA6AEBD4ULL, 0xBEFA2730B923D78AULL, 0xC0C4ABCE278FF2B3ULL, 
            0x2A5E3B8388B91CDFULL, 0x5B2C9303E6302BAFULL, 0xB4702EDD55B9C13CULL, 0xE6EB053E6C1D2B31ULL, 
            0x87C8BA9823ACC8ABULL, 0xFED7ED719691F1EFULL, 0xA59DEBBFD607CE2DULL, 0x7737785B24121DDBULL, 
            0x2E7EC0EF6AF1152CULL, 0x028897F16DFFBB97ULL, 0xDE62639CB924B670ULL, 0xF687C5AD3E0F2BD2ULL, 
            0xD3C013FC155BBCFBULL, 0xBC67C536FA453FB1ULL, 0xCFCBAD5664F41F3DULL, 0x72C4DE08DB36ABEDULL, 
            0xE70EA08B908A7B5DULL, 0x09FE9C901183E5EEULL, 0x7B82CD4490A0CD42ULL, 0xF7C43027E4363020ULL
        },
        {
            0xB00CF9084E4355F1ULL, 0x78D7B932D732783FULL, 0x12BE6B6ADD51381EULL, 0xCF98F4BF1250DB3BULL, 
            0xE4EFE45956FC8D7BULL, 0x64E4AED24768C42BULL, 0xD24A0B506FCE32E6ULL, 0xA96CDFFF91E85B55ULL, 
            0x2342538E0AE3A357ULL, 0x2BDE592AC3790188ULL, 0x04E2486D3D1B2F3EULL, 0xC2F14FB0F7AB24C4ULL, 
            0x26DD35DE69572CB6ULL, 0x3E0C1A9782E00A23ULL, 0x17D4BBF76415539BULL, 0xE046B4D0A62C0463ULL, 
            0x410BA90AD1670780ULL, 0xA3594B4BB8BB726DULL, 0x934696C3A87FC111ULL, 0x9341ABE929A11956ULL, 
            0x35C74DAA5E93F656ULL, 0x9E3C571E32011A74ULL, 0x3431F8E40B1281CEULL, 0x055DAE03B4C4C2F5ULL, 
            0x25030AC72F3B6D9DULL, 0x926C9ECC0B011C69ULL, 0x3452203114725147ULL, 0x4B002E3013BC11DFULL, 
            0xA716285FB7A92BB7ULL, 0xAB2CA3672F9012FAULL, 0x0B89299CF3DB4546ULL, 0x3FB21EE1C459A325ULL
        },
        {
            0x8F5952B485AC08B4ULL, 0xA43A8CF6237717F4ULL, 0x4782AD2DCBB1ACC2ULL, 0x962E27D8E4CA445DULL, 
            0xF4103902B2AA494AULL, 0xBAD5C87290520E81ULL, 0xD11E7D5AB2E16502ULL, 0xA10D71F286D83410ULL, 
            0x0077DE3B9E18A32AULL, 0x5CF6D5454527F5FFULL, 0x1A65CFE6AB92442CULL, 0x96EC015F519B3A24ULL, 
            0x638B386F81C337ABULL, 0x3A97063EEDA24555ULL, 0xD6DAF020A32EB34FULL, 0x5BC9164C1566248DULL, 
            0x1F6434DD2DEBBB00ULL, 0x300DB47FFF01C4A7ULL, 0x291B2D99A5C4C5B1ULL, 0x020C88D5494A41A7ULL, 
            0xCF8DAA0BC419713DULL, 0xD1F89224AD157441ULL, 0x7FE7EADC8747D2FAULL, 0x21E76DD1622F5915ULL, 
            0x354FCD20AF9DFB19ULL, 0x51E6FAC6F0284029ULL, 0xC2947FBF81952717ULL, 0x66996FD20A4448A5ULL, 
            0xA95207FF8E3BE623ULL, 0x31BDF769D1BFDB25ULL, 0x75F87E406C4169ABULL, 0xF006E6F0BE5952EBULL
        },
        {
            0x45311F3FFB47E01EULL, 0x23E3BBB5C5DF22C0ULL, 0xAA1B40626CD3EF92ULL, 0x6783E831E1427D41ULL, 
            0x4FF055E7653F10E2ULL, 0x686117D4C34BEC28ULL, 0xD26E15032B44CDACULL, 0xE75AF5167ED41B74ULL, 
            0x088AC406E28B12CAULL, 0xE20137AF76A439A4ULL, 0x209A8F60A0D8A947ULL, 0xF2B5BE0A5281BB94ULL, 
            0xE3087C64F3BE55B3ULL, 0xC7E679A68E100C22ULL, 0xFEE4B71AC75248C6ULL, 0x7A2828A7424FFFBFULL, 
            0x44E31305729BA368ULL, 0xCF903FF31E1C5E86ULL, 0xC9A1AE75BF618429ULL, 0xC142C3104589B177ULL, 
            0xB4E728DE7AF28FC5ULL, 0x233E817B902E3F66ULL, 0xB0609BF542F73B69ULL, 0xCF5FF31E1E57A917ULL, 
            0xC0DC65D0BEC11A58ULL, 0x0E45612580582E99ULL, 0xE4C6C24FA25F3DF5ULL, 0xA6101CB114D69784ULL, 
            0x915FD3D77947CFFEULL, 0x03D0E7C9E007A58DULL, 0xDA95D20DEC97AE65ULL, 0x7C1161CED2B13898ULL
        },
        {
            0x44CB50CE9A3710D2ULL, 0x9749A134D31B4675ULL, 0xE29BC81F069AE917ULL, 0x728C6E779AA798EFULL, 
            0x9336A9A5F256A963ULL, 0xFBBADF80E301EC36ULL, 0xAD9404A81FBF77F3ULL, 0x661B1DCFD505D44BULL, 
            0x85F1CC337A213430ULL, 0x3BF778CC856C2C06ULL, 0xE83E816FDB15180FULL, 0xD712E4CBF6FAE5F8ULL, 
            0xB0F9CF08E66717B5ULL, 0xB0F119A3A9DA80CCULL, 0x11DE4DFAD4AC08C2ULL, 0x8E19C53062674630ULL, 
            0xBF16310CE63C726BULL, 0xD3FF80159D2B2ECEULL, 0x583FDB2DD765402DULL, 0xF2619FC49362EB08ULL, 
            0xDBCEEE445FD35D90ULL, 0xABE0E990DD1AD258ULL, 0x61401F76EEB9CD97ULL, 0x9F8309AEE4FEB282ULL, 
            0x13E52AF387B8F0DEULL, 0xA91D3BFC819A5FF0ULL, 0xC56193CCB6C42585ULL, 0x9E2F4E4D61D888A2ULL, 
            0xF9BF4D6E90DF7586ULL, 0xF1AA0FBA6B948B77ULL, 0x82C1B9CE2BBBAAEBULL, 0xEA032AD7D19D7484ULL
        },
        {
            0x58678D154E2C1D6FULL, 0x62BFB08A697FAA7CULL, 0xAB2CEF431C6FA65DULL, 0x1E8B30785C582A51ULL, 
            0x011EE3C5FCE3AED0ULL, 0x61FC35E3EE7E7977ULL, 0x7EC712FBB0EE6911ULL, 0x909C8BAEFF1B416BULL, 
            0x9EF1DC7F93E4A365ULL, 0x4A86C0B5ED24D948ULL, 0xEAB4E45BC0A80DF5ULL, 0x7C3037A4F8780AAFULL, 
            0x093F545A275E1C56ULL, 0x78E0CDD7C17B7B43ULL, 0x2B4D9A292243FADAULL, 0x9E9F4241FE986AA8ULL, 
            0xCDA881C99DC47680ULL, 0xDB1842FCF1CF2AB5ULL, 0xDF595841F0B20924ULL, 0xCC66E72F20B426ABULL, 
            0x51C90838684E769CULL, 0x9EDEE617718FB357ULL, 0x1E5FDF3C1D77D8B4ULL, 0x4F04B01AD3DF798CULL, 
            0x11202CF1A05282F6ULL, 0x8FF00AB61D413778ULL, 0x365896ACC20C6BF2ULL, 0x7FE6B0D915E207BBULL, 
            0xE4C84F66A35AF963ULL, 0xD5B97D4163C1AF52ULL, 0x3144CD590B200DFCULL, 0xB8E388BA146469F8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseDConstants = {
    0xF0197BE73628A5C1ULL,
    0xD18A78F416556CF4ULL,
    0x435347F6D00221FEULL,
    0xF0197BE73628A5C1ULL,
    0xD18A78F416556CF4ULL,
    0x435347F6D00221FEULL,
    0xC3BDE0991C237CCCULL,
    0x8DC6A27B22B71800ULL,
    0xB4,
    0x08,
    0xE3,
    0x40,
    0x8C,
    0xA3,
    0x45,
    0x09
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseESalts = {
    {
        {
            0xE6DD90A2D81344C2ULL, 0xCB7BAF02F0F0F833ULL, 0xE84DCF757EE9FB2DULL, 0xC4D8AD816A92B1C3ULL, 
            0x15EE12D2E54E9D55ULL, 0xDC730E9FF54C721AULL, 0x103E9B680FC4302CULL, 0x939F8F78A319C240ULL, 
            0x1709A84045D1F621ULL, 0x4BEF8AE95AE672AFULL, 0x5DBE01D2777AF128ULL, 0xD5258A53F1FDBFF7ULL, 
            0xD8CFE5B220EF8588ULL, 0x6FC156F8ADBB3C2EULL, 0xC1D40C231F4FB509ULL, 0x1D61B97892F6F613ULL, 
            0xFAB6C46D51FBC556ULL, 0x2DA7D5F9B01B0F9FULL, 0x8DA3A6ACFB200ED7ULL, 0x670707B18316BBCDULL, 
            0xDE241C1DA7D0A6C2ULL, 0xA7204788A3D1D298ULL, 0xD2F59288EC4D67FAULL, 0xDA2E852461E2820BULL, 
            0xAF183A4A2A389374ULL, 0xCDEFEEB572B71C96ULL, 0xBD5B28B5333D5C5DULL, 0xB1D4D0DA81AD3790ULL, 
            0x20D759AA4AB3EF77ULL, 0x13D5F19635C332F8ULL, 0x85685BED6BF35893ULL, 0x81135CB8ECE29573ULL
        },
        {
            0x955DB7A0B9C56A84ULL, 0xF8E1F2AAD14D1EE3ULL, 0x32EF04F4BDD1CB98ULL, 0x9A67CA80D414CD21ULL, 
            0x44857F1EA998FE9EULL, 0x25546C8BA99FF0C6ULL, 0x6D1E97C3AD238CF1ULL, 0x1EC6E1DBB0AA7A38ULL, 
            0x6E84D4B3A9723B7EULL, 0x0DC31523E7E3D951ULL, 0xA0D31DFC122B9C21ULL, 0x40BD7FCEE849CDFAULL, 
            0x780903AF69495867ULL, 0xC90DBEEF21BC492DULL, 0x95A155820E8F26ACULL, 0xD17D482D78777532ULL, 
            0xD46690AC7506F1D4ULL, 0xDB4E7B3B3E468E64ULL, 0xA85E95799D7E3D7BULL, 0xFA7DBF4DB5DEF0A0ULL, 
            0x5D091E719572ACC7ULL, 0xE975AE0090AEE4D5ULL, 0x3CDF33739021B245ULL, 0x55607A461E4A5EADULL, 
            0xB8C363DE07DAEA79ULL, 0xFC4392B6DEE1F8FFULL, 0x555831C064B34359ULL, 0x4F33C8D5464146A4ULL, 
            0x2E7E0A5A34D9FC83ULL, 0xEC85B8F8671ECD33ULL, 0x318120A875F8135AULL, 0x2E1E929891AD9A14ULL
        },
        {
            0x43886F5FD7DEF2DFULL, 0x6B6553B5A576E1B4ULL, 0xE3ECB1226676F7ACULL, 0x314055828C64EE84ULL, 
            0x0EB018936AC46381ULL, 0x8C02589CA9C6E409ULL, 0x5F0B15D35A6519A9ULL, 0xC3779528ED0E1C4EULL, 
            0x168FACF5D9EA71B8ULL, 0x875D019B073CCAAFULL, 0xB4C519F7FD92726DULL, 0x6AA8C0EC7D70CA61ULL, 
            0x2281B521FB6DF9F9ULL, 0xB607B20A3FD98F08ULL, 0xDE34BDE38EE231E0ULL, 0x2CE3D9629B0C9F2EULL, 
            0xC0F3E53FC0B3B30BULL, 0xFD879CA7EBB7B733ULL, 0x4B4882719FF6D215ULL, 0x7C2813694830D0E7ULL, 
            0x8030A195EE82A969ULL, 0xDF8EBDBE0BE3A636ULL, 0xF63C672272E56B90ULL, 0xF4B8DD834D2313D5ULL, 
            0x5326E16AFFD3CC78ULL, 0xD6EF685190B8CCF3ULL, 0x8AEEA5D95F6980FEULL, 0x813165395879D76DULL, 
            0xBC124CFDE93AE6E8ULL, 0x1D3E6098C7504BB7ULL, 0x4F48D0BB509046B0ULL, 0x2457E6E88FE08DFEULL
        },
        {
            0x73B5A01C7362CF17ULL, 0xBB277FD4AEEE4DAAULL, 0xE13F5D2C29945B4EULL, 0xB88F0F32C97143EAULL, 
            0x38843B59668728BBULL, 0xFBEAE97E79FEAA4FULL, 0xD347A873CB1A3E7DULL, 0x5277F0BB12B9C17FULL, 
            0x393140363D151C03ULL, 0x1AC566F4C8F4AC95ULL, 0x36D060EEA4D54BFAULL, 0x6085BF7C0D55277CULL, 
            0xF46719FBC974FDE9ULL, 0x47B6C9ACD0D6E8C8ULL, 0xAF81247677CF33DBULL, 0x10FA904524E91854ULL, 
            0x9E0CF804E9B6F0ACULL, 0x2C8BFE296F966048ULL, 0x9F5AE65496C65CBEULL, 0xC9AC437463A95DDDULL, 
            0x927A4CD25DB374EAULL, 0x2A30020FEE135B35ULL, 0x37D161FA4EAD7241ULL, 0x00706B98011B0D73ULL, 
            0xCB4F6D14486CA3F5ULL, 0xDA2E196C3435A6EFULL, 0x1079AC6516199014ULL, 0x4CB76E708EA56D32ULL, 
            0x0CEF86E09105A9A2ULL, 0xC4E39685746ED403ULL, 0x83950BA196F2C85CULL, 0xDA6D1F18740F265AULL
        },
        {
            0x60F12141E253426AULL, 0x36D368E88316DA52ULL, 0x32DD0758234D5D2DULL, 0xB0E519EEC725C0D7ULL, 
            0xE7C4B064BFD96556ULL, 0x7C899C28B35720AAULL, 0x8AD1950006BC2DEAULL, 0xE16F98C396879D5BULL, 
            0xEAA2C6A675A6F0F9ULL, 0x63546044CED78CEEULL, 0x701C338C880CFEEAULL, 0x21B006A817F838A5ULL, 
            0x7F8D2B641F6F773CULL, 0x12AC00D0D4EDC69FULL, 0x27D0FC1F165F4EDCULL, 0x00DC2EBD2763917EULL, 
            0x3F544996AEE3A507ULL, 0x7BCE01F08B8C38F2ULL, 0x73E70608B04DB3CCULL, 0xFE30DFBCAED0ADCDULL, 
            0x12C6FBA271991C43ULL, 0x2090E0FB130A6BDDULL, 0x670CE0CF1410C177ULL, 0x8BF0622B4D10B7FFULL, 
            0xB2644C967D7E7009ULL, 0x5F0A35B0746C4956ULL, 0x416E8E7503EBEE01ULL, 0x20E1708671B14520ULL, 
            0xC9AD61109471474EULL, 0xFFA0F2B0C0D48CBEULL, 0x8921ED46BE7DC836ULL, 0x1DF01589779DD412ULL
        },
        {
            0x983F71E7B65838FBULL, 0x82EE07DB4462F4EBULL, 0x7FA91A8994FAAA77ULL, 0xFCF9EE4444C4A798ULL, 
            0x014AE1F9F7EDEE10ULL, 0x02241D9F8C9B2109ULL, 0x8CA97E3B16B9CC5AULL, 0xEC1F952234022067ULL, 
            0x54115924DC946A62ULL, 0x2E1406EE0B024A05ULL, 0x7AD075E2F3958DD8ULL, 0xBF14488F30A2B2BCULL, 
            0xE5E03A79E5729D12ULL, 0xEF1AF4B89114BEEAULL, 0x902666244EDE8937ULL, 0x3DB634490BE1276AULL, 
            0xC1F9FC28D5EC5925ULL, 0x36E2087010246820ULL, 0x89474AD7CD134FFDULL, 0xBC37CC43028C68ACULL, 
            0x52F2CD363615A802ULL, 0x34E574B650FA34B7ULL, 0x87AA8FD99EDE4D2BULL, 0xD52F6D6FC7D6A72EULL, 
            0x594B61F92FBBE240ULL, 0xDEDF03F57F8591BBULL, 0x00C74FBDCBF7AFA1ULL, 0x0F6650B7B198BA9CULL, 
            0xEBF68405BF5A9793ULL, 0x3D5014E007B7F653ULL, 0xC129D4083928E44CULL, 0xB4271EF419E806FBULL
        }
    },
    {
        {
            0x0ACE1648C24FBF17ULL, 0x73FC39A87182EFD3ULL, 0x264DA9FAD56735C7ULL, 0x81B65CC5FD9BCBDAULL, 
            0x3FCE024A27EF73B4ULL, 0xCB3598E9BB0D31DBULL, 0xA3948F8851A4FAEAULL, 0xE24BE4658DE0012EULL, 
            0x9BF6D9EE08607FBCULL, 0x5F6E7AD27826ED30ULL, 0x3547FA6D5C23898AULL, 0x4940C5AC9A8DFD08ULL, 
            0xE4CC9414FFBD7C35ULL, 0x2E340C9B3669732CULL, 0x1AB802B9665FE626ULL, 0x86388244D13AC909ULL, 
            0x42F91516CB5C45A0ULL, 0x4509A4CE1326F0CAULL, 0xCB29E8A33F6D689EULL, 0x53050DBA8BA55F89ULL, 
            0x6F38C7996B98E080ULL, 0x2822B80E95AED54CULL, 0x5C8FF624D786E435ULL, 0x003D1C9D133EFD82ULL, 
            0xE388A6177166AB25ULL, 0x83DF71BAD2668B3DULL, 0x9C8C8E0685C8B8FCULL, 0x44346F14A5C0812AULL, 
            0xDD3DE3D3C036BF69ULL, 0x21D93A31E67EBB67ULL, 0x7726DDA2B6EA0331ULL, 0x57FE4FC8A17E18DAULL
        },
        {
            0xE7BA848EEA0206FCULL, 0x184701CD10A82B5FULL, 0xD81DC5D730C5CE7CULL, 0xA68CEA3EAD66E62FULL, 
            0xBDAA29342DF317DDULL, 0xB61460F4221CE412ULL, 0x30F09D5B9A58F4EAULL, 0x3192265AA0071AB4ULL, 
            0xF70BBDFD891DA24DULL, 0xE86301E7FB475E17ULL, 0x92485FD2EE2E904CULL, 0x5402F7146EFFC5D4ULL, 
            0x4DD0F1860BD4B063ULL, 0xA40586F860FA2EFBULL, 0x7479D8E9C39EAADEULL, 0xE028B2C3D8ACB887ULL, 
            0xD2EDB272F3F0AD93ULL, 0xFF964209104C10FFULL, 0x9A2C391484A0A1F1ULL, 0xABA4597D2BBE332DULL, 
            0x6A70983955051A23ULL, 0x85DAE052383A072DULL, 0xF02224FC4CBE2803ULL, 0x313CF6559C9428AEULL, 
            0xF94045E0DF066536ULL, 0xEB4651BDA14C19E1ULL, 0xBEE008F67ABED275ULL, 0x34D8AE3728D4E773ULL, 
            0x48B3E4814631E629ULL, 0xED5E7378D738C13DULL, 0xCB39207DA37F5137ULL, 0xF8BF9CECADC38C85ULL
        },
        {
            0x20307AD5C514E010ULL, 0x4FA0BF72CBCA890EULL, 0x5D1222109F93C5ACULL, 0xEB27227DF97AB7D4ULL, 
            0x3D774DFC58D6C33FULL, 0x7BE14BB1A2979B75ULL, 0xC999629F62915D8EULL, 0x5CC534F1A57413CDULL, 
            0x37904C49D247CA1AULL, 0x02E6F0F2555B5A4FULL, 0x314BB307C22A1096ULL, 0x24185170DEE01672ULL, 
            0xAC7C5562FB4EFFF2ULL, 0x539AD4091A2A2C92ULL, 0xFF07D5C79D140C23ULL, 0x8A9E64DD6C50FA1CULL, 
            0x8D7C5B0C626597F2ULL, 0x36FE624BB81F55ACULL, 0xF4B3865F6D9E61FCULL, 0x456C3DA39F8D8FE8ULL, 
            0xE69940C5D85B9BF8ULL, 0x501C6C898CB1C74AULL, 0xE04C674573CE3ADFULL, 0x3D3DC1CC607228D5ULL, 
            0xA60C45A4460068D8ULL, 0x95D6D471A433F3F5ULL, 0x9815BED25F15CEC7ULL, 0x162E70E131A7CB14ULL, 
            0xACA119694A5C4073ULL, 0x1FF1348FD552744DULL, 0xBED2901E9B2B76D1ULL, 0xAB9CF952BB7F7C64ULL
        },
        {
            0x74C428719287BEAEULL, 0x9838B9D7EB8628B2ULL, 0xBE4857566AAA7A94ULL, 0x8147AA4BB550A234ULL, 
            0x83E7D80F2F61B2A0ULL, 0xD7D5BB46F64E069AULL, 0x10F761507F0637A8ULL, 0x897289438FD1317AULL, 
            0x304ECF48D9FB917FULL, 0x73EEE6C6311FC3BEULL, 0xFE182CCC7BEE7111ULL, 0x5E2CE069B0EFC837ULL, 
            0x6E7F0EECB7F692C1ULL, 0x35A460AFE891CE37ULL, 0xE546E06966C7E970ULL, 0x1BA0E58F3B468CE2ULL, 
            0xE62E9F4376AB00A5ULL, 0x5F48ADE97FB5AF6BULL, 0xA5CDBBD8208BBD39ULL, 0xCE58C6D661CBC80DULL, 
            0x2CFD6A9C6DBDB819ULL, 0x4A4405AF61D87CE6ULL, 0x7B2AC7E00C0F3654ULL, 0xD55C713B0ADE6F4CULL, 
            0x5E515EBBF01C045EULL, 0x791C04EDF3AF3147ULL, 0x7C2D2F83C54697FFULL, 0x58504CD968944841ULL, 
            0xD6E499AD49562FEEULL, 0x2C0386781D3E7FFCULL, 0x7DAB2106199BFB19ULL, 0xCA6B9FA5C22938E4ULL
        },
        {
            0x715A4487684D604AULL, 0x3662AB2F639D1C09ULL, 0x28DFBDE1E0535683ULL, 0xD66197C12E73942CULL, 
            0x55896F14CB952CADULL, 0xE407C2B6592CB296ULL, 0xA7B741CCAD8527F4ULL, 0x96FEF3C7219FB269ULL, 
            0x6AA5325350A9AE5AULL, 0xB660B8A87C8FA7B6ULL, 0x64F93DE8C4967064ULL, 0x163FCDE6C60B126CULL, 
            0xDDC68F2B5ECEDB3FULL, 0x135F443EEDE1F7A4ULL, 0x45EBCEF4EC6ED379ULL, 0x70ED242D44EF98A1ULL, 
            0xF382A6586B8C4C1CULL, 0x648EC685D76BA7B6ULL, 0x48351D6A14973339ULL, 0x3D424CC0D54939DCULL, 
            0x043526264B5276D8ULL, 0x83915FB1CCA755F7ULL, 0x70590AF6A3CA2B0DULL, 0xF525410D365DB5E8ULL, 
            0xE6AC9427D36ECC80ULL, 0xD6B4BDBF21D4C62AULL, 0x4C4717917C3BFD44ULL, 0x1B37E64A45B97804ULL, 
            0xDEEB2489726592B6ULL, 0x200B843832AF7FC8ULL, 0x67029961A92F82F9ULL, 0x99DF36A916FDB89CULL
        },
        {
            0x9D7AF4DDD34B5B23ULL, 0x1AE598E4D66FF338ULL, 0x25679F43E65E7ECFULL, 0x023868AE3E9C1511ULL, 
            0x7F4CE9DCB2CB27B2ULL, 0xA7639EC94AEC1CF9ULL, 0xCADA25083149EEEFULL, 0x82B7CC015BD0EFF5ULL, 
            0x3BD4B2C32F4821DBULL, 0x37408D489C0B6BE7ULL, 0x41D9CB8E984405E6ULL, 0x230894F3925C59ABULL, 
            0x59D004E27FC24692ULL, 0xE402608B2ED67F0AULL, 0x2F4B1EC5E6DB9195ULL, 0x96EAFF84D7898CA7ULL, 
            0xF306B666B22EC62BULL, 0xA69B697F4BCC7301ULL, 0x588D6DD2AAB46514ULL, 0x13AEFFDA996CB3F5ULL, 
            0x14EA8A8147599226ULL, 0xBE594BD5658DC3EBULL, 0xB6F6FCA0174AD6D0ULL, 0xC1427CCCB5D93B90ULL, 
            0x1D97218CC46BF406ULL, 0x62F58296F79141A2ULL, 0xEA922016FB958B89ULL, 0xB02A1D9D61FA5E18ULL, 
            0xCF1DCA7DA2CE438AULL, 0x9BF3894957D21A05ULL, 0x11CE467D636D4A31ULL, 0xA173C3636B77F799ULL
        }
    },
    {
        {
            0x5B53F910B9F00CDCULL, 0x593FC0F8245A7247ULL, 0x229E05E255A46372ULL, 0x3C2DBEA8011500D7ULL, 
            0xDFA831C5AADE17E7ULL, 0x9A39D69D7CE37F20ULL, 0x657399DEB2AFBC77ULL, 0x7038512580BFAAB6ULL, 
            0x769EEF7E3691F039ULL, 0x7700068E5473539AULL, 0xB94A3784446BAF6BULL, 0x84A8F98E01DE2010ULL, 
            0x1D9B0B9E7F120551ULL, 0xDBD478773146506DULL, 0x0EB05F1EF928EB7EULL, 0x8EE121AD62A6B485ULL, 
            0xA1157B2286EC5F9FULL, 0x014BF3A6C0A8D86CULL, 0xAA696A0D373B01A3ULL, 0x33363F4FFE7B84E0ULL, 
            0x819E2518E1B060D0ULL, 0x138D516C334D9C86ULL, 0x994F4D4B3EC74AC2ULL, 0x15A715B0EF6EBFC2ULL, 
            0xA8881EFD4A086783ULL, 0xD6871F4084EF88D0ULL, 0x3C23E56038F0642FULL, 0x922B9EFE6854FE39ULL, 
            0xF439BEE180AB98A5ULL, 0x893CE472DD50097FULL, 0x72BDB3BA78D421DBULL, 0x0A4942925CED2CC1ULL
        },
        {
            0xB286A664BEB12CE5ULL, 0xCCF19A6C1F2CD1A4ULL, 0x7FC31F570BFDCF1BULL, 0x3622DC2AE616122AULL, 
            0x1A0768668108778CULL, 0xB3F450E0881A2311ULL, 0x62A4FFA0D37E0B59ULL, 0x7FFE02468E85CFD3ULL, 
            0xDC5185264D68C2C0ULL, 0x020F3C8BF922CD42ULL, 0x3157D8837F8C17ABULL, 0x319DAD749843F46AULL, 
            0x8620BBB6B7A8696DULL, 0x7AE85FBDB1D1DDBCULL, 0x1F0D748D184FC3F1ULL, 0xFF28772AD8BEE4F9ULL, 
            0x28D38CEB352FEBB9ULL, 0xD283CC757D737AFEULL, 0x17697CAF09424127ULL, 0xD683B08880087236ULL, 
            0xE76D34866BCBDCFDULL, 0xA79130C0EF9BF49EULL, 0xED0F8254F14902AAULL, 0x3D0785253CE67351ULL, 
            0x1420B4641F94E51EULL, 0x52BD62E1EA7B1A9FULL, 0x0A4599CF2DEEBB44ULL, 0x99650C47B7DF4AF4ULL, 
            0xCEE86DD0A91AD549ULL, 0xDEDA016D7349DA9AULL, 0x7FB3EF96DFF5B64AULL, 0x70F9F2E927BFA20BULL
        },
        {
            0x409FB48CCF843EC7ULL, 0x431A0D2BE643E7C8ULL, 0x5CA5CB95641B0654ULL, 0x2C5CA5DD98DF55C3ULL, 
            0xE8AE5DE0EB05FE2FULL, 0x8AB6A9771E4B4EF4ULL, 0x66D05C9DF907E806ULL, 0x0558B5478060F025ULL, 
            0xDA77BE3343892D7CULL, 0x8E0E6258B57A9441ULL, 0x7A684746BE50EF39ULL, 0xDB35A26786AFB666ULL, 
            0x9469881C1876A8C4ULL, 0xA35E0B02F77869D0ULL, 0x04ECA6EB904B0EBBULL, 0xFDD08872A481A70DULL, 
            0x72A3100226E424FAULL, 0x82E792CCA45CB04AULL, 0x714A3376A702F7ECULL, 0x97A041BFA4C6D908ULL, 
            0x532A2AAB73D1CF63ULL, 0x19B1BE5098593886ULL, 0xF5DC1380A798F1DBULL, 0xBEA2137B9568C1F3ULL, 
            0xC592CF47A6D19645ULL, 0x5B0146A654B0E64CULL, 0x96AF47E949ED6AE9ULL, 0x53B3DF89437236C6ULL, 
            0x6DA8F9A42802FB6AULL, 0xBE0D321214576F07ULL, 0xEC47F39953648180ULL, 0x159C9F3E8B2E325DULL
        },
        {
            0x751E515AC25E8AFAULL, 0x9B15DBACC66559B8ULL, 0x164197C5F21A47E9ULL, 0x7D95F58A846678DBULL, 
            0x868B141064158396ULL, 0x92A4415E88BA8724ULL, 0x2FEBA1CCFAE4A209ULL, 0xAB52FCDDF3F40EB9ULL, 
            0x5C0928AAD28E840EULL, 0x79C6D723252E9D47ULL, 0xD52369C2B8C60F56ULL, 0xB4AB92652759E207ULL, 
            0xE8639366C298CE5BULL, 0x29130110447BD9D6ULL, 0x0697311EEDF218C5ULL, 0x3418179A03501594ULL, 
            0x9826386ABAC60B1FULL, 0xC3C849DE9E04CFA3ULL, 0xC818E374524810BFULL, 0x238F10B39F2DF6F4ULL, 
            0x05C99FF1DEB9E6C4ULL, 0x9C19A176CC5F7C87ULL, 0x5198E3FC007F9301ULL, 0x20DC24C2533722B1ULL, 
            0x477BDC5324549B5DULL, 0x36037FFC11825C0FULL, 0x759B5CD34126D7F0ULL, 0xFC93C6920ABC6DE8ULL, 
            0xD04F3DAA91BFC725ULL, 0x579789A378CC382EULL, 0x8E2EAB69405DAD21ULL, 0xB8C05C11D787C22AULL
        },
        {
            0x85E135A012C4873DULL, 0xA08DE2123EDDCC85ULL, 0x29F93713BBC476B0ULL, 0x7F9946987E9DF462ULL, 
            0x6E6283F1FBA1D5CAULL, 0x66CBF20DEF65C34FULL, 0x47983B509F823F20ULL, 0xBD2C45F5143A3316ULL, 
            0xF6E8C56B3D5F104AULL, 0x720F8A6F12C7FF29ULL, 0xFA85039C433FE02EULL, 0x427310D38B7B0C71ULL, 
            0xCD021C6617DEB069ULL, 0x3A05729ED3BE0849ULL, 0x6AD29A88C5534902ULL, 0x4105A2F4ACDBF4CCULL, 
            0xEC36BAC5B5DFDBC7ULL, 0x71D6578FFE35D24FULL, 0xAD283A87CCF6C983ULL, 0x4C99E46241B26453ULL, 
            0x6EAAD2275E0E3A50ULL, 0x74495A14E0361A32ULL, 0x05A1DC126B605057ULL, 0x3EACAC4C570CF2B5ULL, 
            0x2F5927F6F82129F7ULL, 0x2618387DA5E4BD17ULL, 0xB68BF8BC593ECDADULL, 0x82C32F104D3D1336ULL, 
            0x9BF144AA6C726B83ULL, 0x2567D0828729BAB5ULL, 0xD72AE525A2131333ULL, 0x0DBE615DD7D3B59DULL
        },
        {
            0x0A3E03E13C87AFBDULL, 0x5AF6CC7DE46CDE40ULL, 0xD0F2B95EEB27FAFDULL, 0xE9A3AF0DFB26CF2BULL, 
            0x86A3E123C3B75D7AULL, 0x9D5555693CAB67ABULL, 0xA6AB1B7EA862E06CULL, 0xD8BD0C708B9C936AULL, 
            0x88CA429D197F0FE9ULL, 0x6C043F76F654E487ULL, 0x97C8507B0E70F964ULL, 0x0F5FC139865B6907ULL, 
            0xD086866B0327C2D3ULL, 0x10AEDC77F26A2A21ULL, 0x1BC2D1876CA84C52ULL, 0x66DA67362EC75D29ULL, 
            0x8CEFB726A2E6C6EFULL, 0xB293625DF5893E18ULL, 0x4CC933AEE24DF2DCULL, 0x94BFD55CA11BC899ULL, 
            0xB28F9FFFF87EBF85ULL, 0xACD2241982B115FBULL, 0xFD335DD4115BCEFCULL, 0xB508416B97796A00ULL, 
            0x8D53CF5A83E7AAB3ULL, 0x8D56E98304AA268EULL, 0x2A6ABBC0C8472204ULL, 0x37A61A426BA8D566ULL, 
            0x0BB69850A3405D5AULL, 0xFB3CDEC2FA27ABBDULL, 0xEB39AA3DD81C658AULL, 0xAE90580D1063105AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseEConstants = {
    0x33A2A019D7B81A20ULL,
    0x08AB9B36A319DDCCULL,
    0x189177D840241A56ULL,
    0x33A2A019D7B81A20ULL,
    0x08AB9B36A319DDCCULL,
    0x189177D840241A56ULL,
    0x23D3F9C153BDBB2FULL,
    0x5DB9C8A4176C3926ULL,
    0xFD,
    0x0D,
    0xF0,
    0x67,
    0x6F,
    0x59,
    0xA0,
    0x0E
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseFSalts = {
    {
        {
            0x4312569C2B1E0F7DULL, 0xF85F3ECFC39A60EFULL, 0x4F4EA9EF8304EE4EULL, 0xA0FAD1607D0F8256ULL, 
            0x7148DC7BFCE13ABDULL, 0xC3054438B1A1A8D0ULL, 0xB9C16BE40AACE617ULL, 0x1017F21CCE533622ULL, 
            0x33E1441656A4A752ULL, 0x6F3586420E3F877EULL, 0x36B79D8A7CB5E26DULL, 0x635CDA6E294D2F00ULL, 
            0xC6FBE9A6C08DFF28ULL, 0xE81C4C0325BADAB2ULL, 0x61A931945559FAECULL, 0x3146A483770876A5ULL, 
            0x50DA1835D7A9D702ULL, 0x9F370A1E87E51F6FULL, 0xAB7B63BA7458A921ULL, 0x503A95EE1B01E802ULL, 
            0xAEE0362DC08B728CULL, 0xD4A04F0670E1C2B7ULL, 0xAA09AC98AFB6FDA4ULL, 0x3F72B9BD65AEEA41ULL, 
            0xD58C63B17C0109B1ULL, 0xDBCDE7D6A9BA3082ULL, 0x97FD0D60CA0C4E0EULL, 0x400EE877387546B9ULL, 
            0xA3645D81065072FAULL, 0x06985E94AB3A32FDULL, 0x2FC60632A7D2A458ULL, 0x935BFD0341D9ADDCULL
        },
        {
            0xF6C103E250DEA86FULL, 0x85CE3665D6C58378ULL, 0x7733D02B5BD2765FULL, 0x4503DEE321A8DFEBULL, 
            0x11A8D9FE5CC27B31ULL, 0xC69D511088FF5653ULL, 0xD273A9CF8CCB96C6ULL, 0xE7D2E02682F68997ULL, 
            0xFA17DA36E0134993ULL, 0x6366CF97D222EC2DULL, 0x67493A038D8E6714ULL, 0x42049DE2D56779CEULL, 
            0x78F84120CF14C30EULL, 0x26AFADA3ACA6A097ULL, 0xB2BC2084FDEBB551ULL, 0xB2FF772FAE1AB03EULL, 
            0x94516711A2206DC2ULL, 0x03E7EDCD044D1FFCULL, 0x6E448466FBBB01A5ULL, 0x234CD911D46C262AULL, 
            0x23B5620E84ED41BDULL, 0x63A52087535F89F9ULL, 0x3EBA6BC8A0891032ULL, 0x4A8482ACBE63B330ULL, 
            0x6062006AB2385DD6ULL, 0xBE0998C93DFD5052ULL, 0x0FE0BF0DB85AF5BEULL, 0x486FC5A9AE986978ULL, 
            0xC8581E4AE6DC6B28ULL, 0x5DB025001411F7D8ULL, 0xB1411C68E243EE9EULL, 0xD63A0362E4A87C9DULL
        },
        {
            0x672D4ABA013556D2ULL, 0xC1DE75483FF442A0ULL, 0x1494FB8AF6818FFCULL, 0x8A96F3B9D3F6B7FCULL, 
            0x761814451DEB47FFULL, 0xC33FAA337C973319ULL, 0x7E02A2EA6AE0E730ULL, 0x7FB7B2F1F03DE172ULL, 
            0x752F7863424268FCULL, 0xE3BA416950ADB69EULL, 0xD870CA7AD1A97A2EULL, 0xCE1074D3A840BB38ULL, 
            0x792333F3FBD15FF4ULL, 0x3F53356F048A4A4AULL, 0x641116DDF8BEE755ULL, 0x78FA1702A1E35C7AULL, 
            0x90CEC0635B3C266DULL, 0xAF80B608DF0E8319ULL, 0xBA85F1C49F50D812ULL, 0xD9BA3CA9802F380BULL, 
            0xC3EDBC7F7AE7C0ECULL, 0x4191AF2796BFA3F1ULL, 0x3A84041D2D155EE3ULL, 0xA4F91CBE33BA0236ULL, 
            0xC01B19E477CEBD50ULL, 0xD2EE4FD1E46704ACULL, 0x910C15390CA0E108ULL, 0x389CE24A17DD938CULL, 
            0x431C6C306150789FULL, 0x8ABCF4310F761C5EULL, 0x85BD3368B365CE46ULL, 0x097210AD2863BFA1ULL
        },
        {
            0x1AB8FEBE92728871ULL, 0xAC1EC625EEBD2515ULL, 0x2526F8F3DF83642EULL, 0xD8AB17C1BD973848ULL, 
            0xADAC40969BB8C9D8ULL, 0x9150F5384BE3E171ULL, 0x41C34B5396EAD37BULL, 0x791D3EC79C929D36ULL, 
            0x471A779AD7F5AE43ULL, 0x4974B48FB4E4A64CULL, 0xA186F764293C1A09ULL, 0x0DC73BDEE4F2BA92ULL, 
            0xDA3B33D2B4EF269EULL, 0x9105A9AC236DF472ULL, 0xE2F7B34D65F4C8B6ULL, 0xCBF07739825833EDULL, 
            0xCDBD0D49083EA576ULL, 0xCE7DCF4CECD71977ULL, 0x488DC83762C9E680ULL, 0xA0AFF50D20DE22A9ULL, 
            0x82861019E34DB162ULL, 0x984F92E49A096F84ULL, 0x3AB989B93195AFE4ULL, 0xAFD79D2C89153FC2ULL, 
            0xCAF67EC99F479624ULL, 0xBD41821EDD1F6482ULL, 0x4E39A83064403462ULL, 0x6A983FA665FA9DC8ULL, 
            0xA8D37AFD63FA6E84ULL, 0x278EB28B8F87D231ULL, 0x7DE4FEB5640E6A20ULL, 0x0548D64AB8B678AAULL
        },
        {
            0x10934C16575A0FF3ULL, 0xEEB57DD549E27BCFULL, 0x68D5C1893E7D136CULL, 0x2FA8C14CCDC540F0ULL, 
            0x32FB6141856AC5C4ULL, 0xCB9738F2105EE968ULL, 0x5A72804966AF4017ULL, 0x267173CC4781D7FEULL, 
            0x20CEA73D643E8A2CULL, 0x105D944AD6D9CE20ULL, 0xE5B6A3B91ED3BD8AULL, 0x390CC8B63A804745ULL, 
            0xAB9E71DC268BCA9BULL, 0xDB2873B5B45FF563ULL, 0xCD6279550D43836EULL, 0xDE14815870DA08A0ULL, 
            0x5808A1F2A92E6C2AULL, 0x043A0246FC2D0FB4ULL, 0xC246900D538E3C1DULL, 0x926FDBA7063009F9ULL, 
            0xB48969A26161AA45ULL, 0x760ED9B3D57EDEE8ULL, 0xC8341233E65A88E1ULL, 0xB547224C3C815111ULL, 
            0x27716FAA95DC7FFFULL, 0xB577F11EC6AB94A1ULL, 0x343DDB5ABD7E67D0ULL, 0x0E9B4A4E9809B8C6ULL, 
            0x256BDDA9ACFF491AULL, 0xC0F4367CB2E567B4ULL, 0x1E856A5496774CB6ULL, 0x62BC3ABE7C9423BDULL
        },
        {
            0x62FB048A6D79F387ULL, 0x8017592EA03300DBULL, 0xBC23675F02DFAEFDULL, 0xC3DA2B6BE9374E63ULL, 
            0x45C62B43744E3919ULL, 0x8A9BCDAE9ED35447ULL, 0xCE103477C691DBB7ULL, 0x15631DA8167CE390ULL, 
            0xC43E789EB93DC7A3ULL, 0xD4415AF98C3F6667ULL, 0xF85219B919A76387ULL, 0xA655422753C4B0E0ULL, 
            0xCDB1EE10A23CAA3AULL, 0xAA96D76D72E50C5FULL, 0xA54A935D7DAF0A4FULL, 0x264A71E7A1BB7682ULL, 
            0xFAE9A4AE79F5C65BULL, 0x066FE54CADC8A9D8ULL, 0x7EDA1A127BD1E52AULL, 0x794F31092356FE39ULL, 
            0xD24997967757D41DULL, 0xCA31AA30CDAD531CULL, 0x18F6DC5CCCD8D119ULL, 0xDF0EF4E9E7A99D9FULL, 
            0xD83716DAAEE25E06ULL, 0xE10EE8DC5A4B245CULL, 0x04D3880BA937344FULL, 0x1C6FA62911BE1B6AULL, 
            0x1E8D860476E1E536ULL, 0x86F57FF5930ADF21ULL, 0x05BC26F56FEDB6CEULL, 0x1CD44A0DA88721B6ULL
        }
    },
    {
        {
            0x4374B09A8C7D6C72ULL, 0xE5D8CFB9C66A9AC4ULL, 0x11C3EA47F46F7B9AULL, 0x497D773761C1FA79ULL, 
            0x1C6CFA4C3B2130EEULL, 0x6BA2BF5EAC6A5588ULL, 0x17A95B403ED737FCULL, 0x168C47603E32B3AEULL, 
            0x89C17461410D84E8ULL, 0x094B54C980821526ULL, 0xA22A9D528C131B21ULL, 0x9C537069BC8D7BC0ULL, 
            0x4C147A1F43A91176ULL, 0x828D9AAF090F7173ULL, 0xB3214E977E64D962ULL, 0x384AF05E1C2C9C34ULL, 
            0xCE9AD69B5C3CA142ULL, 0x07B033FD3068A6D0ULL, 0x223358893177C85AULL, 0xF3CD309AC318BF66ULL, 
            0x6ED4536F2E55CBF7ULL, 0x762EDD78F321C1B7ULL, 0x7B7754420BC79F4EULL, 0x2EAF3AC5EC3525C4ULL, 
            0x4423B4B600E88EB0ULL, 0x7F9CA35884AA81AAULL, 0x2BFCDA8ADE5E3101ULL, 0xC4A4963C4EFD8434ULL, 
            0x1AC64B2A906BEAFCULL, 0xB1C015A74747D161ULL, 0xBED136DDFDC11DA0ULL, 0x019ABFD5DF7A93BEULL
        },
        {
            0x89BCF5796AEB169FULL, 0x86EADDD06EABBBD7ULL, 0xD383366D01CE713EULL, 0xDB0B20AD9290FECDULL, 
            0x0754AC0D2982078BULL, 0x91BD748630527592ULL, 0xBE03E2E190026744ULL, 0x073F56241BB48244ULL, 
            0x1C19983A95B6F3CFULL, 0x7B9403FEB661E568ULL, 0xE4179906EC3094D8ULL, 0x86467E2E9C53CF5CULL, 
            0x57803680C8FC0A6DULL, 0x669816059FE61DFAULL, 0x3C837F531EFBEE3CULL, 0xA1832AFF94E398CEULL, 
            0x8E0850496D5689D9ULL, 0xEBD42A6662E1542CULL, 0x79017C3CBBA8CF99ULL, 0x1D20F6CE6F8FF310ULL, 
            0x747739331B4185B6ULL, 0x17194C9D65A317B6ULL, 0x4CD84BD131CFF3A4ULL, 0xB6032EE6911C2927ULL, 
            0xB97A05EA7509774BULL, 0x30FD1E8FC1DE6862ULL, 0x261A551DB66380F4ULL, 0x63456B6E69B01DABULL, 
            0x82AFFF40E99AC0D4ULL, 0x405FEAE27A3D58E1ULL, 0x91D59065275DDD61ULL, 0xEC61E876708FE848ULL
        },
        {
            0x3330BED9F52E5B8FULL, 0x3AF61352F8DE9812ULL, 0x835DDAC1FBD06A5FULL, 0xF7B688A6BE460EF8ULL, 
            0x5F721FDC79EE2D47ULL, 0xC2809B49ABB7301DULL, 0x6DAF86642286BA74ULL, 0x0EDDAE5C5FB7ECE7ULL, 
            0x812944F1A0F48F26ULL, 0xF7767FBD17C6E827ULL, 0xCAC110BC8D8A52D9ULL, 0x5A041F57D30D9EE7ULL, 
            0x2B79A90617778461ULL, 0xC4F01342AF01F394ULL, 0x55C369A7C977E76DULL, 0xB6922698F52E78C2ULL, 
            0x643E95FE9695F2C1ULL, 0x13B23116607C0CA4ULL, 0x96E66D28A0B312FFULL, 0x6FBBFB7C604FEFFAULL, 
            0xCE10786EF88F024AULL, 0x13B170E306216F89ULL, 0x9D0DC9C5529F6D9CULL, 0xA76187F386CBD2D4ULL, 
            0x3FB26AC4C55CDC43ULL, 0x1D6227FDD11F846EULL, 0xA65006DE92A0C038ULL, 0xA290DD8D292CE010ULL, 
            0xCE82EBAA6D9C6358ULL, 0xA2DE8B55C0888E37ULL, 0x4718ACF664E42984ULL, 0x93CCD4A57D1F08B2ULL
        },
        {
            0x2776B3599FA8527EULL, 0xB493282085BDFA68ULL, 0x2E5CBC8A54EE718DULL, 0x9348D6BA39DA73BAULL, 
            0xA85520B94498CB14ULL, 0xA6E0388D7FE20497ULL, 0xFF2C3094DB050840ULL, 0x3AEB0A3E7474DEC7ULL, 
            0x81D2A6126517CA82ULL, 0xBD2AE81750505FAFULL, 0x9E9DC035B977C6E2ULL, 0x7FA57DFFBD06E247ULL, 
            0xD802F0B3F489EA2AULL, 0xA5C82C1259DAF684ULL, 0x03F9222911CC7EBCULL, 0x4C2514E05B26D9C5ULL, 
            0x5747E0B0B04FBE85ULL, 0xD6C917AE9892ED24ULL, 0x10277497B219DC28ULL, 0x85ACA7044EDA2D0AULL, 
            0x3E8B8E1B245D75FFULL, 0x2C57B8C4E3FD68E3ULL, 0x56298D3E3FE8B2DDULL, 0xFE037A2B244A8885ULL, 
            0x0620667BF9D65D8EULL, 0x8B836E1833217A56ULL, 0x55E83C5E7F27BE7EULL, 0x474E8B8BF4F47BADULL, 
            0xBEA69C7DAC4B0AE7ULL, 0x1158F5929B66CE77ULL, 0xF759C3AFA505C1ACULL, 0x16DB8DBFEC10604AULL
        },
        {
            0x5C92E658E0F7DAB2ULL, 0x120125A2E4BDEB1FULL, 0x9D88EB26737D469FULL, 0xDF6EEAA1A3303ACBULL, 
            0xB481E01060BD4C55ULL, 0x8D1D2340473A9D5DULL, 0xD3647F583CB9DB53ULL, 0xCC8E56B0D2228620ULL, 
            0x57689B8614454D9CULL, 0x69B2F38872E3161EULL, 0xFED00E778C82381AULL, 0xD258C3479361E7BFULL, 
            0x3038340B6CC0C96EULL, 0xDA4F1356D73A503DULL, 0xEFD5998729E01197ULL, 0xABF23D355C01A9B4ULL, 
            0xEF99D7F1A3F2F9E2ULL, 0xD0C426E06E9C2C48ULL, 0x1D0D715390F08491ULL, 0xE892FE5F57601E2FULL, 
            0x2CE87FBDB07B5814ULL, 0x54B4D8984634BD06ULL, 0x43CD510479E9050EULL, 0x0657266D89F9229CULL, 
            0x1DFC2EF5F8C7886CULL, 0x94F88AC138500B2AULL, 0x741E18FAE400A1D5ULL, 0xA1D1F49D484FB064ULL, 
            0x8E37C7A46E9F4C15ULL, 0xA05ECD02FACD87CAULL, 0x8A63F020CDD8F27FULL, 0x055390787F207778ULL
        },
        {
            0x5293CFA4BA99580EULL, 0x69DDD4A649D943BFULL, 0x2F0835B0645C3195ULL, 0x9FEE283B9B5192B5ULL, 
            0xBD2EBD39DC930740ULL, 0xA581E2BFF5BB894AULL, 0xCA09EE5BB487CF29ULL, 0xC43D7275D6437A58ULL, 
            0xC121CBE0E3728BB8ULL, 0x9DD9AFA07697AF0DULL, 0xAE2266F0F22F8694ULL, 0x13EB71722EAC23DAULL, 
            0x957C5C4865B2E46AULL, 0x76BD91DDE55DD8C5ULL, 0x929279049C8B88E3ULL, 0x35A20F919A4EB726ULL, 
            0xB08E3CEBB0DEFABAULL, 0xA9EAB1C0DDE556E8ULL, 0x5CC5B47BC4F01EF4ULL, 0x9BE16DD1811C046CULL, 
            0x5DC23773787B897BULL, 0x3E1FBB23F1B2432AULL, 0x8FAA1D5E5A537842ULL, 0x6287CF21260BA71FULL, 
            0x1BEA457756E0D957ULL, 0x0C76DC33A956B2AEULL, 0x2EF362E7A0BEA85AULL, 0x35570E561F1AC3EAULL, 
            0xC816FF854DF10768ULL, 0x37F8A3F96E87AC4CULL, 0x5328A607E10D12EDULL, 0x185B25C5C96BE8C0ULL
        }
    },
    {
        {
            0x399DF8B7F87B4BC0ULL, 0x4239CAB24C1AF71AULL, 0x562C199DFBA63C43ULL, 0xE1421757AC25F844ULL, 
            0x99070F81597E5A3FULL, 0xEC7F33B5D97B69B2ULL, 0x62FAE2C10E6215ECULL, 0xF1631DD802190131ULL, 
            0x8CD9F91905291D43ULL, 0x50921C3D78487CF0ULL, 0xD944180D045D672FULL, 0xA766C35766899D15ULL, 
            0x4F47CE50E597339EULL, 0x68E5F0FB5C091C92ULL, 0xF79549AFF15D4CBCULL, 0xF94064AC89792972ULL, 
            0x57507291CC0ECED1ULL, 0x736A39BE63830208ULL, 0xF425E9CE4FBD725AULL, 0x5249D81E7DB36EF9ULL, 
            0xCEF45A9B0D6950F0ULL, 0xE8AE2C1BFA0FC49CULL, 0x12911EA2795A7B0FULL, 0xDB1DF1BE00FED5CDULL, 
            0x193E32448F3CF045ULL, 0x092FB7344C75D743ULL, 0x6845551CA50303ABULL, 0xC432403FEC363E00ULL, 
            0x693DB73660BC4497ULL, 0x868F0D97DF38B9C5ULL, 0xF06F303718567EF2ULL, 0x03E7C529072210C1ULL
        },
        {
            0x971FE636AD766FDBULL, 0x7BA9C9DABDE6535FULL, 0x4C26C375D86181DAULL, 0x78F3756CA006E01AULL, 
            0xC309C30F237D18B1ULL, 0x26A23C5CECA06FB8ULL, 0x517B1D59942D2C9BULL, 0x4F3B9DB33104F4D3ULL, 
            0x4FD2EDB7E6AD5FAEULL, 0x4328588908AB94F8ULL, 0x707C2C2D3C9B7187ULL, 0xB49C32EEA8DCDC92ULL, 
            0xCD1063E9F4AE726EULL, 0x1547CB1EA5AEA458ULL, 0x34E76367136FF9EDULL, 0x22231D85631F8889ULL, 
            0x961BE889098E9EF7ULL, 0xF1A93C7E49ADE8DCULL, 0xE4A3DAC6B602ACA1ULL, 0x9FE8A16A875C19A5ULL, 
            0xFE88B9803AB035B7ULL, 0x83ED6BFA8585BDA1ULL, 0x6E7CF39EECFAD6F5ULL, 0x41CFE7E9EFA9F909ULL, 
            0xD94D973F76EBBEAAULL, 0x2E3316010F275346ULL, 0xBC5D854513C740FEULL, 0xB7D9B839CE8C72A2ULL, 
            0xD2826850E10AB48DULL, 0x21320561024EC16EULL, 0xEC552E0C9458166BULL, 0xF35DFCEDD06DCCF5ULL
        },
        {
            0x089951AC8599657DULL, 0xD9B46BF8717BA2CDULL, 0x26680012FAB6AB12ULL, 0x17FD4BA224BFAC96ULL, 
            0xBBB0131341BD894CULL, 0x04228D9587353FD8ULL, 0x94FCD306D3FFDF15ULL, 0x83B166011F06AA0CULL, 
            0x66CDE58153490980ULL, 0x74AC6D806C584DBFULL, 0x4B0B9BF728622726ULL, 0x062B491003AB93E6ULL, 
            0xB28E18877715FD8AULL, 0x617664F32BA0CC25ULL, 0xF6D881B3E7C721D8ULL, 0xB690820434C6162EULL, 
            0xCC500172993D6C8BULL, 0x0AF7BD8BEFE9E200ULL, 0x678F3CEC4E114F2EULL, 0xF5DA0C991C70788CULL, 
            0x96DAA979B8C2EC61ULL, 0x9707F76519AC5746ULL, 0xC6086D5C7C5234C4ULL, 0x9D39CAFB81FD1043ULL, 
            0x68B83872AF06E800ULL, 0x9795E7608ED03AF3ULL, 0xB227B23F37D2D86DULL, 0xDD90A4CE136D7BB6ULL, 
            0xF781A6A533B70068ULL, 0xB137EDF34CC8A81BULL, 0x3F1AD18B05B89023ULL, 0xDB055FA78B56983EULL
        },
        {
            0xE291176FECF4E99AULL, 0xAD3306C1AC94F05DULL, 0xD3CC791C7E23A167ULL, 0x68F29C90A13847BAULL, 
            0x74E807363C259BEFULL, 0x6B2772434DECE85AULL, 0x9C818AAE064F193AULL, 0x773EA829A3C56DAEULL, 
            0xEC87FB01F4AED02FULL, 0x1DF9EB14149D39E3ULL, 0x05E8BDB3D3E53888ULL, 0xE189676ED3F9E72DULL, 
            0x38A395A2DA6D3D26ULL, 0x716C3A91D1A7A181ULL, 0xB68AB768AF81AF56ULL, 0x322990D53A32ECB3ULL, 
            0x721EBE43F35B8CEAULL, 0xCE84490FF16E3330ULL, 0x6114D9767655111BULL, 0x714FC83C177C719AULL, 
            0x2ADE693502271D52ULL, 0xDF1CEE474FFB2509ULL, 0xFDA27769635EC153ULL, 0xB23E377B4A2C4EE3ULL, 
            0x9CDB0ABC9F6116D7ULL, 0x7CA9ECD2A30B6A24ULL, 0x17AEF94611FD55E4ULL, 0x6CE9A2DBE48F9B8DULL, 
            0x3F0B360F54070AFAULL, 0xAFB74A6D789F6A69ULL, 0x213A45859F6E841EULL, 0xC4F8CD49B5B6673FULL
        },
        {
            0xE7FB32AF947F6BECULL, 0x0C6D9AFFAE01E870ULL, 0x09045A8B9789EAEFULL, 0x220A783FC10845DEULL, 
            0x72AA525F0DFE7938ULL, 0x59F6CAB8D387D6C4ULL, 0xB0E9C33BBC9139BFULL, 0xFC2182F3BAFA34DDULL, 
            0x205D81C775E10B68ULL, 0xA87303767388D4F7ULL, 0x0BC52DD321E69D30ULL, 0x598AA10EF8150F5BULL, 
            0xC2C603CA4EBF0AEBULL, 0xD3FDDA1F6666CA71ULL, 0xE6B86C0E8920669FULL, 0xF19961EC8EC1A651ULL, 
            0xF18870E7F4813346ULL, 0x1685D2A99FCD3AD1ULL, 0x5FB59238313C4D48ULL, 0x8617A175EEE865CFULL, 
            0x77DFA58224F4E152ULL, 0x08407AD6657D20CDULL, 0x57C6582BA0B96F5EULL, 0x405D2D683E3A6C0EULL, 
            0xDD699E766D85ADE6ULL, 0xCD3B7CF3250E6259ULL, 0x63696D2710E12B76ULL, 0x1730F0B15BC47D54ULL, 
            0x7BB3C8E596502896ULL, 0xF1A033CCDFC34D9BULL, 0xBB44EBC59D9E03B6ULL, 0xA448E2CE368FEBEFULL
        },
        {
            0xD44EC961B0B3E055ULL, 0x4D39E8A3596F1511ULL, 0x51EE75030F764A7CULL, 0x03F0E03567A92D08ULL, 
            0x35A4A3DD668616D0ULL, 0xF312C3B6B6485C97ULL, 0xAC5BF768D0808F17ULL, 0x9F4F6684DCB87129ULL, 
            0x906940FE812D093FULL, 0x9B737799E3E83419ULL, 0xF567E200D269D601ULL, 0x39029876005A1A30ULL, 
            0x0779EF0E6691F5B8ULL, 0xD41C8438EC667104ULL, 0x59CCC80A0E856348ULL, 0x5A777DC54E9C5795ULL, 
            0x31262D953D7C28A1ULL, 0xA80CB9C1D8666AE7ULL, 0xDF9FBA3A3BBF611EULL, 0x1AA0687DBACA3C8FULL, 
            0x5242E23A5D2B4D7DULL, 0xB919048AACBA6936ULL, 0x6B65913463A98251ULL, 0xF5ADB326044FCC42ULL, 
            0xE20CCAFCB6C140B6ULL, 0xF047EE9BA06416F7ULL, 0x40B52FE55139C5E8ULL, 0xF05EAE7DC61A489FULL, 
            0x8F5B797E5F013F36ULL, 0xBB13A292B4449EF6ULL, 0x45CB9F2F4693409AULL, 0x22863801CF096F01ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseFConstants = {
    0xB9607B9409102D1AULL,
    0xA6E0BE8BEBAB7F55ULL,
    0x1452CFE42EE4622BULL,
    0xB9607B9409102D1AULL,
    0xA6E0BE8BEBAB7F55ULL,
    0x1452CFE42EE4622BULL,
    0x48F69B50AF409A1DULL,
    0xE9C5F8F898C93F9EULL,
    0xEE,
    0xA2,
    0xDC,
    0x4B,
    0x99,
    0x64,
    0x55,
    0x68
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseGSalts = {
    {
        {
            0x2C5ED55B65C7E09CULL, 0xDC14FF7D3F2537E6ULL, 0xDE512FFEE32FD826ULL, 0x3D557097B0B07526ULL, 
            0xA73494BBAA4DC2CEULL, 0x57540E0AAFE872B6ULL, 0x93EBD425F5DFC037ULL, 0xDE68B783B8892BDBULL, 
            0x882210117E0081CDULL, 0xD9C77FAC9753C8A9ULL, 0xF4C4C7CE73789753ULL, 0x2255072B8358B3D8ULL, 
            0x802EEFCA0FE18012ULL, 0xACBA6E4CA39723EFULL, 0x37BA8F285D195C74ULL, 0x276C8E61F89FE0F3ULL, 
            0x06EE4AF66EBE67F0ULL, 0x145AD033DDAD8D55ULL, 0x7578AE6B82891DD8ULL, 0x9A409B531DC675EDULL, 
            0x7987A8CF109BA5FCULL, 0x2E92D4F68AFE767EULL, 0xD684C6F46BCF146CULL, 0xF2BE57FBD47BC3DAULL, 
            0x046FB17B4DBD9625ULL, 0x4A5C69544AFFC1D4ULL, 0x5D1B4CC82EE30E57ULL, 0x9E0FA954590D8186ULL, 
            0x2058FF800A5B6033ULL, 0x81C65AC890DD2E72ULL, 0xA738877959F5A30EULL, 0xD770FC2C1C220F6BULL
        },
        {
            0x124A2255CE4707BEULL, 0xA181FB4FFF62F005ULL, 0x59BB284C9EECB676ULL, 0x8F2CAD7D7501D531ULL, 
            0x2B5DD3642F1A13FFULL, 0xAA4A894808A0D38FULL, 0xDD509A3A640A7490ULL, 0xD7EB1018A6B10B7FULL, 
            0xDE001C486D61A560ULL, 0x114927729AD69932ULL, 0xD9DEF3A8EA032FA9ULL, 0x8F3450C65C9222F4ULL, 
            0x39139DA05561CAEDULL, 0xA61644146577FE17ULL, 0x722DC1443332177FULL, 0xE4EC73DD0B5114C9ULL, 
            0x2D8EC004FAA3AB8BULL, 0x09D06DEEB3F21CA1ULL, 0x41011F2EED1C8C51ULL, 0xD84AB01AD4FA5683ULL, 
            0xD87C98643DF9ACDCULL, 0x75B847C99A792CDCULL, 0x20B2322ECBF002AAULL, 0xE88831A155142F31ULL, 
            0xBA8D8547D29E2535ULL, 0xFE0153D7D0226A94ULL, 0x7A4031B3FCE03513ULL, 0x02772AE132889478ULL, 
            0x0F9FEF9651BB91E6ULL, 0x1E34CB19E05AB3ECULL, 0x239682F152781F81ULL, 0x9C2265919BA65E42ULL
        },
        {
            0xC0BE5F22C5F65882ULL, 0xAC367A275F0DFF9DULL, 0x864052711C9F936AULL, 0xFAF48D0F2BA8B35FULL, 
            0x4F5E0405DB23226AULL, 0xA59B6409EC56A0FCULL, 0x605FC1559B56B16AULL, 0x3A0DCC2A469923A4ULL, 
            0xBECE92996F48E7A9ULL, 0x9EAD25C4BAC4BA92ULL, 0x7EE5F790DD13A85EULL, 0x25508EFDD03F7D09ULL, 
            0x31AF9940A8133C15ULL, 0x785CE27BBDA4678FULL, 0xD013360713951DB5ULL, 0xF215C537F86BD24FULL, 
            0x34909C0E978FA17CULL, 0x717AAB00468CF8A3ULL, 0x52FBC0AC84902F08ULL, 0x1F508B7F5D97B696ULL, 
            0xE68D951D5C9FA254ULL, 0xBCA7A911285677E6ULL, 0xE93514E2543F5700ULL, 0x537C59D8E35919EAULL, 
            0x505981E8315337E1ULL, 0x9DDF702F921AB2D5ULL, 0x1D52DA863F30BE12ULL, 0x22444CD350674586ULL, 
            0xEDD3D6A34ADF739DULL, 0x6FD84E3A8C7F3209ULL, 0xF9677178A6676FD3ULL, 0x6F3BFE67646B6CC1ULL
        },
        {
            0x4C16554B1BC551D7ULL, 0x046682A3C7339A46ULL, 0xE9FB316F64D4D37FULL, 0x901942585D94385FULL, 
            0x03BDE3B902612194ULL, 0x0D8FAD8109ABFF0EULL, 0x8FC982D702081D86ULL, 0x213018FE6D691A0DULL, 
            0x154BCC9BF96B72B7ULL, 0xC3F7F0BD1980F924ULL, 0x9A1F506A802E2CE0ULL, 0xC551198A76C4FA50ULL, 
            0x42C2B9A6215F4EEDULL, 0x665A8DA46E4DF271ULL, 0x3FFEE10CC17481D0ULL, 0x6ECA713D7D3EB908ULL, 
            0x6FC877AF3B52EB76ULL, 0x778695B91859B152ULL, 0xA7F80E454BA5C957ULL, 0x453630F603F461D8ULL, 
            0x7A8565CA4F624775ULL, 0x2788D97048AEA6FAULL, 0xFB3A00720E9A514EULL, 0x974A0A5F0148A04EULL, 
            0x3A4F011C22CE3C05ULL, 0x77484B5842D935B3ULL, 0xE7FF13C360FD077CULL, 0xB42A7409CFEE6F29ULL, 
            0x1F50100A68061325ULL, 0xE5487352038BF07CULL, 0x819896225B8FADA2ULL, 0x0CEAEAD15B83A5CDULL
        },
        {
            0x31C7E821C41324D6ULL, 0x52F438F166B20DA4ULL, 0x657A91EE86575D6FULL, 0xF75152CE1289CFA8ULL, 
            0xC3FA53FD57E729C9ULL, 0xC696F7ED885CBC7AULL, 0xB035DC02BF1049ACULL, 0xA580D33F54F7B435ULL, 
            0x9702798476BF54A8ULL, 0x9D24E92025F7750AULL, 0x6F03B63E9B2A6A20ULL, 0x6B489045944ECF84ULL, 
            0xA0DE95D3EACB3BF8ULL, 0x6FB61D7DCAFAFCA7ULL, 0x4FF9EDB57C0638D1ULL, 0x90A91EBBEDA723E7ULL, 
            0x45B8DEADDC41CBC7ULL, 0xE757F9311E8F1E8EULL, 0x9479DC047D94A528ULL, 0xDEF92D2955C3BB49ULL, 
            0x8938762DEDA75958ULL, 0x9C8B6470260C0813ULL, 0xFA981AF0A1178028ULL, 0xB689CB241AA03094ULL, 
            0xE269272E2A1D015BULL, 0xC3A06F66DF50D39DULL, 0xABDB5A9D4B0118C3ULL, 0xA32EE3B22DD8428AULL, 
            0x6FA8F238DA47523DULL, 0x680AF7E57FF080E8ULL, 0xA6499F6C3E64BAE9ULL, 0xE00DBDE67FE7C555ULL
        },
        {
            0x2A9CDADA500A3342ULL, 0x51E2D1D5412A910EULL, 0x48A9FEE726B3E2BEULL, 0x5D2D96F9E1AE01E3ULL, 
            0xAD47CC6B2066800DULL, 0xF7624D3F7BD94033ULL, 0xBD77B14051161A89ULL, 0xEB0FCC03E6836A1FULL, 
            0x6BBE0FBF8F32C3D6ULL, 0x4C4AD33F71538C82ULL, 0x76B4DE39C6B452A3ULL, 0x23421FE8ECA2F18AULL, 
            0x5DD935AD9EF11285ULL, 0x4A3D2507571CB984ULL, 0x217A4846D5414A3DULL, 0x013B30293D800C93ULL, 
            0x5F736AC53688C5E5ULL, 0xEBD40987F2A97BF2ULL, 0xC23E8FDE02F85FE3ULL, 0x4F35FDEC0C570A80ULL, 
            0x6BBFCCD764786B31ULL, 0x9DCBE066D120AD65ULL, 0xBE1A78BF12FFDDA8ULL, 0xB5218AD01E802596ULL, 
            0x94E24980B7123B7EULL, 0xDAF2CAC9B14217AAULL, 0xEAFA0D1DBB70AF46ULL, 0x229789B8270E8F3AULL, 
            0x36E9CACEED1E8F1DULL, 0xF307E8508C0FF14DULL, 0x8AC607F059C0C055ULL, 0x720DE3D40F56D3E5ULL
        }
    },
    {
        {
            0x54F772BA78AAC406ULL, 0x630320A427820DA9ULL, 0x52837975132150BAULL, 0xD15DB5333C10F8EEULL, 
            0x38CD7CF87299CB9FULL, 0x4C577E22052DCDCFULL, 0x1C4CA82861FD69CBULL, 0x5A129050F0BC5504ULL, 
            0x6FC3EBC53DDA780CULL, 0xD9DFAA5D33B107CCULL, 0x62ADA667A74DEA08ULL, 0x74A154D02C6BCEE0ULL, 
            0x59ED48E2A1D453CCULL, 0xD726985E2A5771FBULL, 0x347E1AC56BB136BCULL, 0x47C82219AF1BC211ULL, 
            0xA28E0A2484C98AAFULL, 0x780FF6B2E1B25BA1ULL, 0xB81475A8F25A90E2ULL, 0x2986D745D4111A73ULL, 
            0xA4E860ADAE0B765AULL, 0xA472709CE38B567EULL, 0x32B93795CDF75DDEULL, 0x5A9C43113A7C118AULL, 
            0x43C295FD0AED7D24ULL, 0x7DD46384C1E1E45DULL, 0x7BB8FD9296D52936ULL, 0x5E37B13CEBB5922CULL, 
            0xE140D30E4CBD38C3ULL, 0x5AE35094EAC55241ULL, 0xA0BA594C8DC1A48BULL, 0x2FE85C282587394FULL
        },
        {
            0x4D19F169A680AB75ULL, 0xBD7BBB245D9E1876ULL, 0x47E0A050F1F37668ULL, 0x468495F29D8986D3ULL, 
            0xA5ECA8D93A0E0A79ULL, 0xAC6CB54F9366057AULL, 0x0576E1E4D90FEFCBULL, 0x7818A35B4C4E7702ULL, 
            0x8015488685A69BA1ULL, 0x354F02152FD293C6ULL, 0x9F2C7E5D8CBBA82AULL, 0x9E7A386C4F31AC33ULL, 
            0x95678A9585E92CCBULL, 0x074670E43F8B95D3ULL, 0x29B824DDB6E5B773ULL, 0xC8B4F53A9E40D51EULL, 
            0xFD30613D01FFB825ULL, 0x1E08A0DDA784628CULL, 0xDF844ACF6C68434DULL, 0x631330F5ED3C2C1AULL, 
            0xA8CBD64901B5B579ULL, 0x0E5F31A884D9ED29ULL, 0xC221A7208830F57EULL, 0x8130FB9D98DE51DBULL, 
            0x129743D609DD03C8ULL, 0x613592F4891B169BULL, 0xB39CB1815A7E54AFULL, 0xBA369E3438971EA7ULL, 
            0xAA5C3965726E6931ULL, 0x1882017F0A08758CULL, 0xC92E1EDB7C5DA224ULL, 0x5A2D2D3EF1A8AC16ULL
        },
        {
            0xEC96990FB4745FEDULL, 0x77B1F3CF184161BBULL, 0x80BBE9D6E6D695F5ULL, 0x1E6CA5E9A3150E25ULL, 
            0x819AEBB3F996F565ULL, 0xDDF09A6BED989D0FULL, 0xA1A8D13E867988C2ULL, 0xC51C24B88C9711C7ULL, 
            0x28539779999A6C9AULL, 0xEEFC574CA6FB0215ULL, 0xB5DBD463327C1DE9ULL, 0x1B222D28CA72C317ULL, 
            0xDDC26E2AAA631271ULL, 0xA35FD811D9FEAAAFULL, 0x43F4B5A9DF55AE0EULL, 0x85CA2AEEB888BE61ULL, 
            0x5BF7891C4CD066AAULL, 0x9469A72EF6C21965ULL, 0xAEF0D1C5C8E86DCEULL, 0xDE02B6113C217BFBULL, 
            0x87FF2B1C8DD23A5EULL, 0x32BD612E4FF3533EULL, 0x3137FF15E58A6DEDULL, 0x777276A94E946F4EULL, 
            0x5749F240645A1AA3ULL, 0x8C5F928D96F3B69FULL, 0xEE860EDD98986F11ULL, 0xC5E64521D2FB4033ULL, 
            0x674D4012BBD70DD5ULL, 0x8E2DE8BC7CA66025ULL, 0x124CF4693D891964ULL, 0x3DE238C16CD8E33EULL
        },
        {
            0x9BE08945C95226F4ULL, 0xE5EDCEB7E0BC7A83ULL, 0xC0AD1D8E0F6CA8CDULL, 0x6F751EED2C5A49B1ULL, 
            0x407468B17A7ED0EEULL, 0xF8E1AB2CBBCF3265ULL, 0x10ED0EAC23E4D911ULL, 0xFF800CC54E684DB8ULL, 
            0x2AE7FFBC7D80D0B5ULL, 0xF21DDA608FDB39F3ULL, 0xFB1EE9A6FEBF2D00ULL, 0x7DF7E9177A0A7327ULL, 
            0x198E01806A67EBF4ULL, 0xAB556757E50622E7ULL, 0x954C34399835C991ULL, 0x8A8F1B8C23C6E066ULL, 
            0x1CA5430BCE7E7A1AULL, 0x87059A4FE4CE7E73ULL, 0x7B1568B6B1A0A75FULL, 0x0EA50FDC8E353354ULL, 
            0x08CB24CA0B4D3305ULL, 0x07F6E0FCB17E2CAAULL, 0x630D0BE4E8D6146FULL, 0xDE7258334E3C9F05ULL, 
            0xFF28ECC1AE23CFBEULL, 0x29CC2DC3B3CCF59CULL, 0xA83DE4036EA00FCDULL, 0x468A3C160F144CDCULL, 
            0xF7D2CB8B33F45115ULL, 0xEA23E157C38FBBC3ULL, 0x695EC88ECB13D0C6ULL, 0x806F96798A81461FULL
        },
        {
            0x41C84136DF9165A1ULL, 0xED0885A543931DEEULL, 0xB42309723E81E301ULL, 0x34FC24E9D6C59AF3ULL, 
            0x400BFB8D799B16D1ULL, 0x51A756322AF49253ULL, 0xA95E599B24A6C919ULL, 0xBCEE06F6210F146CULL, 
            0xE36E51D7E66E4B43ULL, 0xB7D0C58D7E74E9FBULL, 0x73C1E15917589D0CULL, 0x2205D27B4E9649E4ULL, 
            0xFE8ED1563BB1B412ULL, 0x0BD56B9F1D7FD2ABULL, 0xB3DD63F2776239BAULL, 0x0F600CDFD303B03EULL, 
            0x5E22A569C4939E94ULL, 0x2B81F8013F4AD87BULL, 0xE79D428173769671ULL, 0x7AD1BF201B8603A2ULL, 
            0x50F738917B279038ULL, 0xDD7E8906DA1ED52BULL, 0x44596142B7EAECABULL, 0xA0FD10116DECD3F8ULL, 
            0x22CB53EFC35D06A8ULL, 0xEE8E5FCB968B049CULL, 0x41B8DA853FA1B01FULL, 0x6AF3588ECC7AB3FCULL, 
            0x5E2060E1FE1FF249ULL, 0x869625AFD8121F24ULL, 0xB65A5FA44EF46CB2ULL, 0xB163190377D51B1EULL
        },
        {
            0x399F6CDE34E9288AULL, 0x6282AA1F2BB15F09ULL, 0xF66B76C1ED677732ULL, 0x7BFA9FBCFACA0642ULL, 
            0xFC94F8C97E424E12ULL, 0xD0BC7EF8A7AB307EULL, 0x65BC463AF757D95CULL, 0xF5EB82721D2D6C98ULL, 
            0xA303241BFC6089A0ULL, 0x0706A28184A147EAULL, 0x32DDBA2D43D7085DULL, 0xE7E95B92499F1636ULL, 
            0x91D4B1565D2DB45DULL, 0x7A1D899FB2AD1683ULL, 0xD4C268F5EA87ACACULL, 0x841177ADDD9AE13CULL, 
            0x69FD3D7C352D039DULL, 0x3F187495786A424DULL, 0x27F2701E41CDEFD7ULL, 0x3DE7777807D53531ULL, 
            0xC11B0148D4316ADBULL, 0x00E06B28A4EEA61EULL, 0x8E365ADC44A9B935ULL, 0x465479C2642FF269ULL, 
            0xBEE7767090CE71F7ULL, 0x0F030C729D2972A0ULL, 0xF15776D05DB5C4E0ULL, 0x9CF41C4CDA288D6BULL, 
            0x526CEA8AB1D5926EULL, 0x8A5F0ED921AB2855ULL, 0x4BC190201E43D945ULL, 0xFCFDBE212B4AB2B0ULL
        }
    },
    {
        {
            0xA8E9BD8B06304323ULL, 0x9C1D8C181F9ACFC3ULL, 0x0E9B3B3337B445FAULL, 0x704E2CD3DED37CB4ULL, 
            0x9C95C470472E5C4CULL, 0x75260B59A8F5897AULL, 0x2DE448DFC636E766ULL, 0xACE71A7472442140ULL, 
            0x0308F1969D7107FAULL, 0x75E05A9569210D10ULL, 0x1B7AC01650FD37ABULL, 0x8FC0F095A7DE4774ULL, 
            0x67A24FAE972962FDULL, 0xFD47A1A94FB1EE10ULL, 0x3E469D20B79B2F4FULL, 0xE8DC6BF75089D56AULL, 
            0x0B40095D05144EB9ULL, 0xF132075B28DC448BULL, 0x83FBD2051B45E4CEULL, 0xE4D37FB401885675ULL, 
            0x8DAAF04DF44BF41BULL, 0x2EEB22E6881C6A71ULL, 0xF386A133F070E25CULL, 0x113E2B3F8B404FC7ULL, 
            0x9B1390758CC9DE6BULL, 0x9C0A67F6A14A81B9ULL, 0xF8F267BD153A4CD6ULL, 0x707755A6ACB292D1ULL, 
            0xFF22B463F2B4DB54ULL, 0x27FD43DB0539A2C7ULL, 0xB2B40FFA578479C2ULL, 0x03F4C6BAFE12AD23ULL
        },
        {
            0xE87F77AE2E1D8D41ULL, 0xA88CA791849A67ACULL, 0x68C732E479703B2EULL, 0x014033F9644AD970ULL, 
            0x6F1CF27F56AE3557ULL, 0x03D07377CBA905BEULL, 0x2047416B8A9ABA3DULL, 0x51723E418233C371ULL, 
            0x02E100AFFDBAAEF4ULL, 0xE272C865EC7EF2CCULL, 0x3D309B095B5603F5ULL, 0x7CF2D59FB84ADE5EULL, 
            0x6571A68D8B962379ULL, 0xAF64D0372E244B4AULL, 0x0747F57E09A990D5ULL, 0x75B10F2217C278A3ULL, 
            0x5ADBB59A68DB1F93ULL, 0xAAC565B4B3A68195ULL, 0xEBC4898C92BCE4E1ULL, 0x1F92B9A6E7B10E11ULL, 
            0x590649079E45CFC5ULL, 0x907EBF6A3AE0DA7CULL, 0xAA0E7DC35B4BA521ULL, 0x711871A482504438ULL, 
            0xA0008F461173E44CULL, 0x431B6D2BB0B7EAB5ULL, 0x353F516F1B2D1A0DULL, 0x6B9C18D7843C73C3ULL, 
            0x7120B6129A1F2F62ULL, 0xF3B3E7240C258C6EULL, 0x4090F7D8056C245EULL, 0x9F4BE67838C86548ULL
        },
        {
            0xCCEC3F9EF631F0A7ULL, 0x7C699A2159D7AAA5ULL, 0x23F77F720B783984ULL, 0xD797A2038A2F3865ULL, 
            0x32422BC3D7C8EF8BULL, 0xF6BFE6DB93F7FEA1ULL, 0x09215E50080F59FCULL, 0xE112EA789EE60B10ULL, 
            0xF434E25BDF157A3EULL, 0xD96F585D6D8E9516ULL, 0x10AF53AC8E1AA9D7ULL, 0x9C5D26C23440E4C0ULL, 
            0x774C1431B9E21735ULL, 0x56BBA18536C7D5C9ULL, 0xFD40ED525B0AE383ULL, 0x100E778D4971466EULL, 
            0x84650C94F7E8734FULL, 0x197720C802BB170CULL, 0x94666C3377F7B71BULL, 0x087D98187C093185ULL, 
            0xAB22E925080AF374ULL, 0x281A7B286A2E3E56ULL, 0xDEDA7E53E61F3262ULL, 0x76CD6C43AFCEA2BDULL, 
            0xCC6C132188FF0ED2ULL, 0x9ACE4FAAC6EC39C2ULL, 0x2789A8F99A3BC709ULL, 0x72ECDA33544CEAD8ULL, 
            0x18E38EB3D1E959EFULL, 0x22DA8AA677F6497DULL, 0xB79673542204DAFBULL, 0x50A408B6AD6343EFULL
        },
        {
            0x60EB09C53128A7F0ULL, 0x0F97B761AAB2D644ULL, 0x44470667BF88A808ULL, 0xC0E9D6F5CDF89722ULL, 
            0xC06BE1EE5BE2EFB6ULL, 0xFD8D38C9F9341801ULL, 0x229DFB3F40248B53ULL, 0x191C0B0B60E37ABFULL, 
            0x9C663ECB497133DFULL, 0x108DC572F96A069DULL, 0x741838EE6A67AC96ULL, 0x42757615B72702E6ULL, 
            0x2E426CF7E73B6DF6ULL, 0x601945D600D8E8F3ULL, 0x1D16E008A60FC30CULL, 0x6ADC6DA7D3B25D1CULL, 
            0xAF28DF22B79E3C18ULL, 0x0E4F11BF9856347AULL, 0xFC117EE091362F22ULL, 0x581D04B88CF6CC86ULL, 
            0x308FE50931D22F40ULL, 0xA3D028A36060A6E4ULL, 0xCDB1A736CF5827A3ULL, 0xE82AA72E718B8042ULL, 
            0xD5A1271D0D22C4E9ULL, 0x2FF897BFB15E2EA4ULL, 0x692EA29948E75318ULL, 0xC12495DD3DC52DA7ULL, 
            0x2CEEDCFB4D9B2F37ULL, 0x82A6B1D361B79B39ULL, 0x212751D595E6823CULL, 0xBCDC42E25D014171ULL
        },
        {
            0xE7DD2AD7CC07B272ULL, 0xF891910AA0F50F65ULL, 0x17ED38C633ECFC00ULL, 0xFEFFDF8E07D79787ULL, 
            0x8AA259104A5BD813ULL, 0x997A3C4DB2C5129EULL, 0xE4617061C0C6F839ULL, 0x47351D08BEDF7B2DULL, 
            0x863296E989299596ULL, 0x7AB5FF5002FE9E92ULL, 0x9E67D1C31D84473DULL, 0x9E5408D2E52C8E0CULL, 
            0x13F859D25FD47B97ULL, 0xCFD678578807961BULL, 0xDFC804A23912097FULL, 0xA2BA69835DC2922EULL, 
            0xD09C5BACD1B2A3C4ULL, 0xF9ADBD31AE3C55A0ULL, 0x62C7949CBFF5E8F5ULL, 0x61FEA2818C395D73ULL, 
            0x03631DAB6E9D7C33ULL, 0x61D8C3E6D59425B9ULL, 0x2CC2D1BBF4884804ULL, 0x35E35FAE06B6251EULL, 
            0x4C8859E006BDFC21ULL, 0xB6A9D755A60D2B03ULL, 0x5FC7AE5F94389475ULL, 0x51C893F1B5832B87ULL, 
            0xD3A323E165DB1AB7ULL, 0xA611EAE11FC37202ULL, 0x8DEE720CC0D38892ULL, 0xFB68156482A8640EULL
        },
        {
            0xC99F3F1EE38F79A2ULL, 0x1F0D24578404F8E4ULL, 0x05F7B1EAD2C44340ULL, 0x5B5A7E89306EF4C1ULL, 
            0x20C1A3305C6BB34BULL, 0x3F0DFCAF8EFBF5EAULL, 0x883EC5EB75D392EBULL, 0xED05D59BE99848C0ULL, 
            0x90F14426127DF4C3ULL, 0xC9D4743CB60DE5FCULL, 0x7A6848BDC09F78B3ULL, 0x0D710F52C42B4444ULL, 
            0x131B4CA6B0C514FAULL, 0x74A899CF45A0B652ULL, 0x7B134FDE6E1D64C8ULL, 0xC415763B780D6459ULL, 
            0xC270F69C8EE509EAULL, 0x01C270E4539E0465ULL, 0xF4AF29866287E235ULL, 0x483B295349A92535ULL, 
            0x9456B64E1FA2988DULL, 0x3024DF11F4EE88F7ULL, 0xABEDA4BEF5437CEDULL, 0xEEC6DA921AB2A2D3ULL, 
            0xCB8E9F832CF4DCBBULL, 0x69EB90577EF2A9E7ULL, 0xFA2CEF29A409D30CULL, 0x619C4285302876ABULL, 
            0x73A54A5E0B0F781FULL, 0x4160846EB1C0F1CAULL, 0xEA984DF12E4A40FDULL, 0x29A441DFD87EEE53ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseGConstants = {
    0x94125D383DA4D617ULL,
    0xC8F4B726A7E6F3F7ULL,
    0xD7050069D49FC685ULL,
    0x94125D383DA4D617ULL,
    0xC8F4B726A7E6F3F7ULL,
    0xD7050069D49FC685ULL,
    0xEB3E43048D32EF50ULL,
    0x7B929C61D96E10E6ULL,
    0x3B,
    0xC0,
    0x88,
    0x3F,
    0x60,
    0x7B,
    0x2C,
    0xFA
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseHSalts = {
    {
        {
            0xC9267469274F7D9CULL, 0xE5843D7336182E3FULL, 0x78F776F7E304747EULL, 0x9A0E6200C2EEBDACULL, 
            0x338FF3ACC00A2911ULL, 0x5F832C9D3368506AULL, 0xC3592FAA3CD88F24ULL, 0x857FF07261CB8E95ULL, 
            0xF3A17D3340A829FEULL, 0xBFD4D946FBF405EDULL, 0xD30F35D7B57BC526ULL, 0x7A4318339BBA2CF6ULL, 
            0xD03CE55836F03F36ULL, 0xA8470C59A9CEAD2CULL, 0x4282F0D3072E50C4ULL, 0x5B70D8BFBBE720C4ULL, 
            0xD4DA514C07EAC70BULL, 0xE30A2B0CEC32C3C5ULL, 0xDA3634FEBB2BCACEULL, 0x87AB8A18586E2D76ULL, 
            0xA09666E2CFF589F4ULL, 0x4345160865222A87ULL, 0x0509DAECF7757694ULL, 0xC1EC9B7465F1866DULL, 
            0xE1D819F11CB47BDDULL, 0xD0CD80AF257A8CE5ULL, 0x0AB8454987095DA2ULL, 0x0E6A9DF3EBB1D0ABULL, 
            0xA2E7C2385CCF38BAULL, 0x82381E5CF6F529DEULL, 0xA922A58968629043ULL, 0xC9446C02DAC59FC7ULL
        },
        {
            0xBB9F9B671B5E7825ULL, 0xC5F0F4B9ECF0C68BULL, 0xC459A770183E5294ULL, 0x19DE2373B81C38B4ULL, 
            0x3D84E68C43A33F98ULL, 0x80A7CF12666FBC76ULL, 0x9B332741911EF72AULL, 0xA5D67C5A840E4397ULL, 
            0x1500AD0EFA3977BCULL, 0x3394FF5C19F985DCULL, 0x2887119EC6F264CFULL, 0xC8EF964DB60509DBULL, 
            0x2E569B79A3D2ABACULL, 0x1CBC09CBA7BD53EBULL, 0x8BCA51DE3C9CCDD9ULL, 0x22F1F2009A2EC422ULL, 
            0x037851B9743F9841ULL, 0x3DF4E2DB80DC93D5ULL, 0x3E5F8358BF11D74EULL, 0xC54FEBF81F3A1844ULL, 
            0x5BC8BCBA02829D10ULL, 0x1C581EA5EF1C1B19ULL, 0x63876843A40C596FULL, 0x982AAD75CD45C0E8ULL, 
            0xF8BB8B2581C81A1BULL, 0xAE067A51ADB550CBULL, 0x740F4379495F2114ULL, 0xAE8474F5381BCCBEULL, 
            0x1C39C1000499E729ULL, 0x232318904F3525F5ULL, 0xA82661ECFEAD5937ULL, 0xA0897527D3AE6D14ULL
        },
        {
            0xDC905884F3692BA3ULL, 0x91DA8FEA8470AC5CULL, 0x00E41ABA1B323ABAULL, 0x1EB4C6200D281015ULL, 
            0x74CC5AE70F8FD605ULL, 0xC4FDB86F3373CFD5ULL, 0xBB6429A137129510ULL, 0xB342805D1F8D063BULL, 
            0xA594C5B40B9CFB9BULL, 0xAE0EE04A43898C99ULL, 0x1D1311206EC65C05ULL, 0x390FB88CD9DFDE88ULL, 
            0x0F77F70EA961824DULL, 0xA4A15B877A0159FDULL, 0x31BB4811DAC5786EULL, 0xD1E23BAD1F118243ULL, 
            0x6E3E773013A7023DULL, 0xE9F4B97AF8BF9B29ULL, 0x4D3BBBFE3CE803E3ULL, 0x60A1B60D3CE78146ULL, 
            0x9DEB187C146E29F1ULL, 0x1B97E6B79F85D7C6ULL, 0xA015964D0F445917ULL, 0x94F32B75D97188DBULL, 
            0x7A00EB2D37DE9D69ULL, 0xA0F274EE6433C5D6ULL, 0x916824EC89942D05ULL, 0xC2EE9D8D68753C62ULL, 
            0x7808A4B19A502871ULL, 0x620C828A3030163AULL, 0xCB8DEEDEDFFD106BULL, 0x71D917907800B064ULL
        },
        {
            0x8601B46AB50ABF70ULL, 0xDC5BDC1A8A23B921ULL, 0x1D4B6BF453EC2B76ULL, 0xA23BA36127BC33C2ULL, 
            0x84EA686A8C0FFDDAULL, 0x1A790861CC8F31F9ULL, 0x4D368E5401E607E8ULL, 0xC57770A712D56D14ULL, 
            0xC2D90310A12E0E09ULL, 0xC6A4428F3DD6A4E9ULL, 0x195A8C88EC594817ULL, 0xAA2F0F0DBCBE2FA0ULL, 
            0x796E6C69C7D7ACB2ULL, 0xD9821692BCE067B2ULL, 0x7EDF97CE12111D6BULL, 0x4A1580A3D8BC96C7ULL, 
            0x20398669CBE259B0ULL, 0x41A0D1A04F749DBAULL, 0x935032B0A74A80B2ULL, 0x69F71DE42F9D1BC0ULL, 
            0x3F7AE243374C4515ULL, 0xB979F7B7AADE6999ULL, 0x5FA9579DBBCD43F9ULL, 0xF5B66DC4D2A39A35ULL, 
            0x6D7B4CB439A02786ULL, 0xA0306705493E76F5ULL, 0x45E28FE02D000686ULL, 0x12EFCECEAEACF082ULL, 
            0x5EED1F9629139869ULL, 0x1AF6D3A0BF75C6A4ULL, 0x91C70E5D0B38CF8EULL, 0xE3E220DFF3B89C27ULL
        },
        {
            0xE6B84A31C4766CBCULL, 0x2A2BFC406CC112F2ULL, 0x157F92B758BEB096ULL, 0x79AF929919AFBCAAULL, 
            0xA2F1B2A5E20EF706ULL, 0x894524EFC3FA3DADULL, 0x4F84921AA6B1E4F5ULL, 0x658442F5E330DF2CULL, 
            0x346CEBD05EA3F281ULL, 0x7AA67C5EA35D2CC1ULL, 0x78732264E01C0A63ULL, 0x1E71FB6F57CADE70ULL, 
            0x4256B5F7FD002D5BULL, 0x6ED15FB1EA7B5B1FULL, 0xFCEEAC3B378AAE45ULL, 0x0E0E0ADC695184AFULL, 
            0x401CDEA69813460BULL, 0x4EC2B189F272EC1EULL, 0x59177ADE35C91477ULL, 0x94FA4B62AC57FEB4ULL, 
            0xCF246BC66F5EC377ULL, 0xAFD9E2FADC63A6CFULL, 0xE280DFF169E79719ULL, 0x9C8E0DCBD4898E09ULL, 
            0xDF72563C2848C9FEULL, 0xF77842F3BAEBA8FBULL, 0xD67082F103691FB4ULL, 0x9F732C045ABE61B9ULL, 
            0x25E3B638B5F1D060ULL, 0x021EE31422725940ULL, 0x83ECA7B57A2092C8ULL, 0xC7F278649D2824B2ULL
        },
        {
            0xDF7577C1533A273EULL, 0x282FD8E9C3106547ULL, 0x790A201A86CC0E6AULL, 0x963AD95C5BAB2682ULL, 
            0x829E1BC43DF1A716ULL, 0x6FD38D55EF4F0E80ULL, 0xEC188D96BF641539ULL, 0x120B5A1129BA7CFFULL, 
            0x402F6FD9BFFEFCE3ULL, 0x3E0F84D286C1E74DULL, 0x0E52337C46F0E6BEULL, 0xFBEF2C41FEE0CFABULL, 
            0x5B2A8700AC31204DULL, 0xFBB480788B61E350ULL, 0x147130E9DBFDC55FULL, 0x664B355062CDD24DULL, 
            0x6990051330671B9FULL, 0x97C743393B2F2E95ULL, 0x350E78CA9FB5461DULL, 0xF46F4C2283EC5C06ULL, 
            0x88FAEF82B46E196FULL, 0xD5DC32419262F31FULL, 0x5104FFE6B5B238B2ULL, 0xAFB3364DA0E48FE0ULL, 
            0x8F6972B403A72558ULL, 0xC164E3D2360D3F23ULL, 0xB5B2A718FE0E8CD3ULL, 0xFA883BC5D8C002C2ULL, 
            0xE93FD83BA59FB85CULL, 0xA55273D9283420F5ULL, 0x2A835E6E5F68F0CCULL, 0x3873161C222997CCULL
        }
    },
    {
        {
            0x1ED4F481DF20D699ULL, 0x812E60BDB47CAA1DULL, 0x1C8E08E4AC76D9D5ULL, 0x039A20549B586EADULL, 
            0xCF891CE96030F45CULL, 0x473C575643B5CC9AULL, 0x27832D51763DBFE6ULL, 0xF50931A8F20404A3ULL, 
            0x2E37940546A5C51BULL, 0x10568E82381F13C3ULL, 0x3310AC8B47EAA89EULL, 0x389CBA4559A153BBULL, 
            0x26C6811F5B0D8645ULL, 0xD27D67DCE3CBA93CULL, 0x5F6870E9A075138DULL, 0x9E6299115C311048ULL, 
            0x20E7BAC386FD3266ULL, 0x0E6412C4D6F17F55ULL, 0x783673233D68C7C5ULL, 0xF744A614DF148F0AULL, 
            0x4C4CA50D3519FD42ULL, 0x1AE0BC99E2722625ULL, 0x58C45818E8998443ULL, 0x424C233BCCAA4D22ULL, 
            0x516DD0B4E7944B78ULL, 0xDE18761BD25DFE40ULL, 0xF2136F87B524D2D8ULL, 0x3FA680AA4B107152ULL, 
            0xB5017D6ED0AB2713ULL, 0xE0F82ABFFFBB8EDEULL, 0xCB0ECBFF52F5D59AULL, 0x8B6534C0425215A0ULL
        },
        {
            0xB41953AEAB71FAA9ULL, 0x57322417B77F9456ULL, 0x60B0B460B3800E83ULL, 0x11C48324831C69F7ULL, 
            0x190B61A3820BA1BEULL, 0x49CA2E47DAD00664ULL, 0xA75EEE6791A0FBB6ULL, 0xFCCC2FAD0F846578ULL, 
            0x3A01EE3B3C78EBE7ULL, 0xFFEB3587850BF886ULL, 0x6B0FBBCCF15B2E2EULL, 0x5FF31EAE041DFB78ULL, 
            0x0BA9646A10EBE3A6ULL, 0x1601A5EF359AEFE1ULL, 0x1B76709CD1C90BFBULL, 0xF8B196DC2B42DEB5ULL, 
            0x95983E67C944A43FULL, 0x6E1B92AA55501EB4ULL, 0x9387D4AD9C13B15AULL, 0xD46B84659AECBD90ULL, 
            0x304236CD144F12BDULL, 0x817360933AD9B4F5ULL, 0xCC486D22E8832E19ULL, 0xC1CA2553DDD2000AULL, 
            0xF91684CD79F23617ULL, 0xCE41BAD553542822ULL, 0x1C885A4E95AD5730ULL, 0xE3656638B4E28A3CULL, 
            0xB0F510EDDB1E0CC5ULL, 0xEB4F83D22D4875FEULL, 0x6FA5232D636E8A88ULL, 0xE827584FBCA310CEULL
        },
        {
            0xB0077A4932E91EA9ULL, 0x50F25AFA8CB34C21ULL, 0xBE7EE31BAADD76D1ULL, 0x91E79F70632CD0B8ULL, 
            0xBABF771140B265BAULL, 0x229292CD2904B485ULL, 0x463E277FB5FF7DABULL, 0x79A1D5DFF1B97E3CULL, 
            0x58DD541DF2235969ULL, 0x61630C52AE4844E6ULL, 0x54D1FA97EECD1503ULL, 0x0588547CFC24AA4EULL, 
            0x4A72A3B0BECC1540ULL, 0x61C63B30B45ACEB4ULL, 0x0EA00AA603E46952ULL, 0x611673FDEA0C6D1FULL, 
            0xB6689E5EFE59D893ULL, 0xF5C2DE3EAA136255ULL, 0xF98B38C2347E3727ULL, 0xA1B9F6EE0C2C402EULL, 
            0x246AFFBE55B00E52ULL, 0xE6179EEDABE9463FULL, 0xEDC203AFE117429CULL, 0x796853F3248EA4F8ULL, 
            0x13518B07323713F0ULL, 0xAFD90094C1E45D19ULL, 0x880D147C9C36348DULL, 0x172F6F29FC02312BULL, 
            0xB4B0D1216B0D01C8ULL, 0xC470E7156461342EULL, 0x7A0EC5D53252FDB4ULL, 0x739E49F812DD8D80ULL
        },
        {
            0xE3B5C99FE707895EULL, 0xB4E3F6033422374AULL, 0xAAD3F7B171C01F6EULL, 0x29C6C718924AC795ULL, 
            0x42450784A045DE40ULL, 0xDD1766DB1C045C9BULL, 0x7C6B18238B20E3D9ULL, 0x40F92A154022B178ULL, 
            0x723BF2114C354A63ULL, 0xB44B69B6C7BA3EECULL, 0x21F880454821EE5AULL, 0xC65112205D47DCCBULL, 
            0xFCB270BF884C8046ULL, 0x229ED22A19AAEBFCULL, 0xD6CF39C1025E629CULL, 0x3821C935921725B1ULL, 
            0xAAB669C2AEA23402ULL, 0x326E491D63742340ULL, 0xE460E94DD94F1FACULL, 0x588714B404FCA91AULL, 
            0x0D45E0817CDBB21FULL, 0x7A114ABE9BEB2CDAULL, 0x542331C90F74399BULL, 0x9BC40FAC4E8BD1F8ULL, 
            0x3E16E9D1BA89B0B6ULL, 0x0AE6F52DFFB853A2ULL, 0x3BE80B73D31FDB2FULL, 0x5D4099DC09F7ADA7ULL, 
            0xBE798C4B156349B0ULL, 0xCB57CD3A96027998ULL, 0xD74E60A19AF1A8CAULL, 0xA9547EB1EFB2CB0AULL
        },
        {
            0xF173A6F2F5439F3FULL, 0x6FD4B3B82C20FBB5ULL, 0x85FDA8160E1171BEULL, 0xE0EF463B791317D6ULL, 
            0x24142E6EBF94E7FEULL, 0xE2EDF95A3EBABD8DULL, 0xE79A8C95B162095AULL, 0xB1DBBD44D5B2612CULL, 
            0x4384E3238AB9A583ULL, 0x3787EE4E4FEEC0EEULL, 0x36147F8E3294AE34ULL, 0xB11CDF8BCE32A5B3ULL, 
            0x0146C9A41AD16D8EULL, 0xADDB9A2B4062B392ULL, 0x38B1063B17346686ULL, 0xFD9DBFEF88EA2470ULL, 
            0x1C784BC3CB4C3592ULL, 0x4BBA89D9D4FB176AULL, 0xE62CB5095899F676ULL, 0xF6065CCB9E06A604ULL, 
            0x6BDADA1D1C2AA659ULL, 0x34EB162EEE6087D2ULL, 0x4F2CD3D4659A4C4CULL, 0x11F854FCC557DD04ULL, 
            0x4B92A5EFA7D99A4BULL, 0xD3449C123B59BBC5ULL, 0xAEF0CB1304A15505ULL, 0x84CB8A9E7CE752C1ULL, 
            0x14EE367C57EF1C76ULL, 0x58577AAD77DA51B1ULL, 0xDC24B7E6382F1C3BULL, 0xF085CA95C4445FE2ULL
        },
        {
            0x019F70075735A1BCULL, 0xD0A38C52B567415BULL, 0x8D969059905D0905ULL, 0xD1EB80C456D95600ULL, 
            0x3455F1CF90E312F4ULL, 0x1D9BD64B4A319F4AULL, 0x603D70644551A53EULL, 0x226AFEAD64E8E476ULL, 
            0x84F0FAA5717330B8ULL, 0xF4D23EE0DC8A6F3BULL, 0xE84E03AA792FF7A6ULL, 0xE8DA5F8590C31E4AULL, 
            0x4FD55E8F0DAF73D3ULL, 0x7453040F583B8365ULL, 0x7C7FE3C2DF0EF7FEULL, 0xB21A99D8CCD49FD6ULL, 
            0x35672C54C079DF5AULL, 0x273A914858BCFCDCULL, 0x762E70D83F050B23ULL, 0xFA07F60B35732E43ULL, 
            0x995A638FFA9B3124ULL, 0xC0813D126256487EULL, 0x785F0C10E43890D2ULL, 0x1DDB46CD0DEDB3B0ULL, 
            0x61B5FCDFFB03C94DULL, 0x5341CAC935705578ULL, 0xD24D97EE40980FB9ULL, 0x271229DFCCDDC8C5ULL, 
            0xABE445B6F743D454ULL, 0x160934ABE00C5DDAULL, 0x5377735A44C3957BULL, 0x2A1C87FE88BF31A1ULL
        }
    },
    {
        {
            0xE2A353EAD18328CBULL, 0x8709B8E97CB16A62ULL, 0xD81AD7C544B7F4E1ULL, 0xAD00F06753942100ULL, 
            0x0281724B0BA27A9BULL, 0xAC9E796B993FD9E2ULL, 0x3B51F5128642034AULL, 0xDE41A304A6E62723ULL, 
            0xEA5BE39734DBB2AFULL, 0x448850073520C4F9ULL, 0x6CBBF29A8BD659BAULL, 0x91A7C239786AB1D5ULL, 
            0x6EEBBBC765000EE0ULL, 0x8FD51772330CE953ULL, 0x4F8B922AE714480DULL, 0x8769F086F10483C5ULL, 
            0x2064A4AE8F7E875DULL, 0xE5DF0CB96C2A664DULL, 0x02159457ACDDB39AULL, 0xA7DF3727BDF07B1CULL, 
            0x57DE0CE02FB84A47ULL, 0x78D8957762112F9AULL, 0xF893050A68257189ULL, 0xC15C23B1119024B5ULL, 
            0x9383A3C868DF3BDFULL, 0x5DA7A73AFF928012ULL, 0x3870C307CECEA7CFULL, 0xAA789DDC6F643192ULL, 
            0x0E314C361BF17590ULL, 0x681BCFBDF64A4E6EULL, 0x6758E9AD0E1377DDULL, 0xC916044CE1151E39ULL
        },
        {
            0xED008A267B4B2D98ULL, 0xFD5A6D5AE41A46D1ULL, 0x3BB0D80022BFE497ULL, 0x58CC94DF54BD35EFULL, 
            0xA6E9B4008292782AULL, 0x0E49995469DE3715ULL, 0x518CF3AF3CF945ADULL, 0xCD44729045D19CD6ULL, 
            0x3A426F7DDCEA051AULL, 0x94EB1467F9DEE517ULL, 0xC16A7F6D19EBC3AAULL, 0x3EF13352E5732C24ULL, 
            0x17F247A1827D81EAULL, 0x48C74491CA1B6586ULL, 0x7021A21EA7317E3BULL, 0x5F7E83E3FC3A00B2ULL, 
            0x32D21B56B15894E8ULL, 0xF036D420C6C67984ULL, 0x62E23E5940ADB2EAULL, 0x6FA4C25DD40DCEB7ULL, 
            0xC4D7E6538247B6E2ULL, 0x1153FA5E8634D521ULL, 0x1ED8F3C3BA52FE66ULL, 0x015BB08320FE51F4ULL, 
            0xB48D0D8D057FA12EULL, 0x5D746FF779829977ULL, 0x68874F65CCEE9E2FULL, 0x8580B9050E1A5888ULL, 
            0xF31DD07ADF9A2E63ULL, 0xF6E28D8C47E5178DULL, 0xD0B7262CEDDE2DBBULL, 0x9FB8BD0090D16759ULL
        },
        {
            0xC8F4704F0FE59BD5ULL, 0xD3DEE53A72F02AA1ULL, 0x9B6B70DE2E040F36ULL, 0x731F277A07524DC7ULL, 
            0x54DEF12EE520F668ULL, 0xA4E4229BEA31DA93ULL, 0xFA40D9F1329606E9ULL, 0x375A7FC85F47DECEULL, 
            0x7C73467D2411D22FULL, 0x1BA48E2CB034A29DULL, 0x56DE823EEB6E5450ULL, 0x292D4B86BB2AA897ULL, 
            0x45B96D895E28D464ULL, 0x1E2D024E504D41EAULL, 0x80D8C761A26B9AC0ULL, 0x938B65CB50C4C6BBULL, 
            0x9E92279CB764F115ULL, 0x551D7716F6A5C8E8ULL, 0x0AE96C1B18D33004ULL, 0x94E05542A2460140ULL, 
            0xE476F6E5D0599451ULL, 0x71FE3D24346F3FB1ULL, 0xBCA191D8AFD67C37ULL, 0x81676E0184A31775ULL, 
            0xE37D6B3AFCEAE1EBULL, 0x17FC58ADFEBD83EAULL, 0xFDBAFD0EA2D3C441ULL, 0x6C36611737CBBD11ULL, 
            0x5F546D2A68646C75ULL, 0xC007678EBF911E48ULL, 0x44D92CDE685D8E48ULL, 0x7DBF557281C333A3ULL
        },
        {
            0x8A5AC78C4AAECD91ULL, 0x47EC6107D88605BEULL, 0x25EE3FE1BFDF0ABDULL, 0x8209E8BF62CD6525ULL, 
            0xC587C2148CE29DF5ULL, 0x5E60D5CEE27FD5A9ULL, 0x5FD8C2385CF19EE5ULL, 0x0B21D68CF7E87281ULL, 
            0xF95632C54A84D53DULL, 0x0276323078921E16ULL, 0xDCBA26F29DFF6C35ULL, 0xBE03F3BC41F888B1ULL, 
            0x04959CF4E96777F2ULL, 0xB86610FC481C4D95ULL, 0x0FF8E7FAD1E0627DULL, 0xE00AFAC09D571F80ULL, 
            0xE832184CB6B4EF2AULL, 0x24E199BED4C375E4ULL, 0xF7EB501450A0ABD3ULL, 0x1B0E1D2296329599ULL, 
            0x9CC66FF7A2F1D4BDULL, 0x6591D9C81AFA2CA7ULL, 0xCEFB7AB81CD6324CULL, 0x7E3D783BC0B3B0FDULL, 
            0xEED1212AB591C532ULL, 0xFF4BFC3A9DDD7D94ULL, 0x386426C32AA08D3FULL, 0x5871DCFD612F0AF3ULL, 
            0x1D9624DEF14E5674ULL, 0xAB57CA786F8EC735ULL, 0x47F15289C4B06EECULL, 0x79E3FB69638589D8ULL
        },
        {
            0x20CA948BC15DDD0FULL, 0xC1FA4CD63310F221ULL, 0xCB0FFAB449F6F83BULL, 0x352D68A5E61AE07AULL, 
            0xB629448E8C5A4947ULL, 0x23E0028A40CD68D2ULL, 0xDC84036F2FDF47B3ULL, 0x5A836C100F10F182ULL, 
            0x0A572AA6012C90D1ULL, 0xC7CA9E3C4B23247AULL, 0xF1EDA4B3B1D2824DULL, 0x3FBC44922D9D98E8ULL, 
            0x8D745474D6D51F83ULL, 0x91C95A50A740C2D7ULL, 0x44547BE28C92C4CEULL, 0x0B4FB6C045587280ULL, 
            0x188CEAE932C70178ULL, 0x8EB05CE5C9F40DF6ULL, 0x5D726C63319DF4E9ULL, 0x61C4A626C3C00998ULL, 
            0x5CCEB060B072B56AULL, 0xDB93400D522FD47EULL, 0x0D408AA782202F69ULL, 0x4D8D95B34D53825AULL, 
            0x860E4102725B80EBULL, 0x54390B3EDAD55F41ULL, 0x1FEEC1C2A9DAB474ULL, 0xD137389F255DB5F0ULL, 
            0x8757CFCB64F28042ULL, 0x04A5D5C1BADD94E2ULL, 0x449D3B22FF84AC88ULL, 0x2AEB79266C4EA4D5ULL
        },
        {
            0xCC05440BB0C95E85ULL, 0x427BC6EE835A18B0ULL, 0x084E7A2C32EA88DBULL, 0xCE33ACD892A7975EULL, 
            0x18200F5321D439C6ULL, 0x6DA91176D6F9849EULL, 0xF380DA02DD31A5ECULL, 0xEB3549050E624293ULL, 
            0x25902DC4DEABB447ULL, 0xAFC8229006BF4C4CULL, 0x3F7792BBB006042BULL, 0xDA6767F805A28070ULL, 
            0xC577830C7490E280ULL, 0x2120501E50C26EAFULL, 0xB858E999F579CDA1ULL, 0x64E7BE1B261F768BULL, 
            0xF7FB2C5BD4D17D82ULL, 0xC7D3AE83EE05E8AAULL, 0xADE9954CD3C218DCULL, 0x6842D7624231DFB3ULL, 
            0x2E12EAFB5AB639D0ULL, 0xD9D113381BD0AF64ULL, 0xD15E0F66EE1F9C90ULL, 0xD6FB73D9963A5649ULL, 
            0xFCF4015B37047F52ULL, 0x043AEBB148F8B4F8ULL, 0x427FA3A0C44D1449ULL, 0xFD7A0805923AD768ULL, 
            0x6E971D3EFE47B585ULL, 0xC5B8B0915686B716ULL, 0x382343CD226463FAULL, 0xED71663CE2EF81D6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseHConstants = {
    0x5334DFF9A786CA22ULL,
    0x78F343D6CDBD2A0EULL,
    0xBB88C5901A4B4DBDULL,
    0x5334DFF9A786CA22ULL,
    0x78F343D6CDBD2A0EULL,
    0xBB88C5901A4B4DBDULL,
    0x0E7B726830E51E49ULL,
    0x0783C695383CAAADULL,
    0x55,
    0x33,
    0xB6,
    0xBA,
    0x0F,
    0x38,
    0xC0,
    0xEF
};

