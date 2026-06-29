#include "TwistExpander_BasketBall.hpp"
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

TwistExpander_BasketBall::TwistExpander_BasketBall()
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

void TwistExpander_BasketBall::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xCF23F79F1A190DF6ULL; std::uint64_t aIngress = 0xB8F5FB1E345493EBULL; std::uint64_t aCarry = 0xAE5E3459DC575ACEULL;

    std::uint64_t aWandererA = 0xC8D91B9751426F24ULL; std::uint64_t aWandererB = 0x88F70E75181859F4ULL; std::uint64_t aWandererC = 0xC7A90EFAEFA5021FULL; std::uint64_t aWandererD = 0xE717D693E1C8B48CULL;
    std::uint64_t aWandererE = 0xC0E87C370E88FAE8ULL; std::uint64_t aWandererF = 0xC3C243A5BF736C7CULL; std::uint64_t aWandererG = 0xDA83255510331700ULL; std::uint64_t aWandererH = 0x9219A46237C472B4ULL;
    std::uint64_t aWandererI = 0x9021690A8AACC0BBULL; std::uint64_t aWandererJ = 0xCD08A7C148ABE050ULL; std::uint64_t aWandererK = 0x9015C328646EBCA8ULL;

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
        aPrevious = 16054744441965617915U;
        aCarry = 12401532196729961605U;
        aWandererA = 11577172019612615094U;
        aWandererB = 16102635456675504691U;
        aWandererC = 9609823412100444271U;
        aWandererD = 18296726825638587700U;
        aWandererE = 14129109540525132269U;
        aWandererF = 17826938768054533240U;
        aWandererG = 9986091145587946289U;
        aWandererH = 13518356058970146287U;
        aWandererI = 11217196569854584831U;
        aWandererJ = 12958455294901581390U;
        aWandererK = 13958617636223427486U;
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
    TwistExpander_BasketBall_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_BasketBall::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xEBF144C892B33F9EULL; std::uint64_t aIngress = 0xC44B63730134C925ULL; std::uint64_t aCarry = 0xECB826F012FF8133ULL;

    std::uint64_t aWandererA = 0xF4EAC811072CF5F1ULL; std::uint64_t aWandererB = 0xD85AD158BF409B0EULL; std::uint64_t aWandererC = 0x8A78B13DD4B3E527ULL; std::uint64_t aWandererD = 0xE183C899E3F626D4ULL;
    std::uint64_t aWandererE = 0xFDBC3C8BE5091DB0ULL; std::uint64_t aWandererF = 0xB64F1CC2EB56D2EFULL; std::uint64_t aWandererG = 0x9B17C006A9E05E57ULL; std::uint64_t aWandererH = 0xF288B027692F6CBEULL;
    std::uint64_t aWandererI = 0xA60A9F24A1ADF632ULL; std::uint64_t aWandererJ = 0xEDA7A4C9D8BFC3EAULL; std::uint64_t aWandererK = 0xB4F2C4F33256C490ULL;

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
        aPrevious = 10317507349948099138U;
        aCarry = 11550132895797707386U;
        aWandererA = 10889471898841303579U;
        aWandererB = 17158995126180335955U;
        aWandererC = 15872594449463158736U;
        aWandererD = 10712869989917653143U;
        aWandererE = 11286082979809699621U;
        aWandererF = 14894440544389806180U;
        aWandererG = 17309428311880028032U;
        aWandererH = 11744056990627392824U;
        aWandererI = 11253804797328752769U;
        aWandererJ = 16470974443596948284U;
        aWandererK = 14703981599421325318U;
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
    TwistExpander_BasketBall_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_BasketBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8B09BAA07255A824ULL;
    std::uint64_t aIngress = 0x80C780CBA93F6181ULL;
    std::uint64_t aCarry = 0xB2D28A054DED48EFULL;

    std::uint64_t aWandererA = 0xFBBCA8DAB85FB9B1ULL;
    std::uint64_t aWandererB = 0xE49BFF7B301A17CCULL;
    std::uint64_t aWandererC = 0xD7ECB25480599E47ULL;
    std::uint64_t aWandererD = 0xAAD6B92751179EB2ULL;
    std::uint64_t aWandererE = 0xE256DCF9FC514DE2ULL;
    std::uint64_t aWandererF = 0xF9E242D0DBBFCE69ULL;
    std::uint64_t aWandererG = 0x960A4637BEDF45BBULL;
    std::uint64_t aWandererH = 0xF9B4279563C148F2ULL;
    std::uint64_t aWandererI = 0xD11E30D4CB909C8AULL;
    std::uint64_t aWandererJ = 0xE19CCEB7BF63EBE3ULL;
    std::uint64_t aWandererK = 0xCD685BD28B4B3CC3ULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA, 1);
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneG);
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC, 6);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneE);
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_BasketBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_BasketBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF73CD7D7BA7D1F50ULL; std::uint64_t aIngress = 0xE2ED07B7B4FFFC3CULL; std::uint64_t aCarry = 0xB2D56A5136209164ULL;

    std::uint64_t aWandererA = 0xCE1F2E21E0C7084FULL; std::uint64_t aWandererB = 0xE8C55003DD051B29ULL; std::uint64_t aWandererC = 0x8A3A88A216D82253ULL; std::uint64_t aWandererD = 0xE3842D9BE23A508DULL;
    std::uint64_t aWandererE = 0xA23331D0B6343AE5ULL; std::uint64_t aWandererF = 0x88833425CC0B67F5ULL; std::uint64_t aWandererG = 0xBA5ABF9FCF564CDBULL; std::uint64_t aWandererH = 0x93B478096BF9590DULL;
    std::uint64_t aWandererI = 0x9CEDB3A6DE67FBBAULL; std::uint64_t aWandererJ = 0xB9DF13DD4D8A41B6ULL; std::uint64_t aWandererK = 0xA6BE50F8CF2B8FD5ULL;

    // [seed]
    {
        aPrevious = 17679069410607783371U;
        aCarry = 12789656513891828281U;
        aWandererA = 10367275648311277999U;
        aWandererB = 11374475748302466545U;
        aWandererC = 12641666971174430714U;
        aWandererD = 10004408348905183611U;
        aWandererE = 11203883260420218001U;
        aWandererF = 13792941144998066329U;
        aWandererG = 14320730921401899434U;
        aWandererH = 15448411017317215354U;
        aWandererI = 13216229174896179421U;
        aWandererJ = 12476723955737621247U;
        aWandererK = 11882872970087900405U;
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
    TwistExpander_BasketBall_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_BasketBall_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_BasketBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_BasketBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 2, 0 with offsets 2744U, 3303U, 5429U, 4402U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2744U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3303U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5429U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4402U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 1 with offsets 4436U, 3416U, 4168U, 2140U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4436U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3416U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4168U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2140U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 3, 2 with offsets 7641U, 3277U, 6650U, 4769U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7641U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3277U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6650U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4769U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 0, 3 with offsets 5663U, 1510U, 47U, 2195U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5663U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2195U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 with offsets 415U, 484U, 141U, 1205U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 415U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 484U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 141U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1205U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 0, 2, 1 with offsets 122U, 1756U, 1953U, 1309U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 122U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1756U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1953U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1309U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 1, 0, 3 with offsets 287U, 487U, 142U, 1680U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 287U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 487U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 142U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1680U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 0, 1 with offsets 496U, 273U, 798U, 1121U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 496U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 798U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1121U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 125U, 309U, 1082U, 1138U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 125U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 309U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1082U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1138U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_BasketBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 1 with offsets 1778U, 6077U, 369U, 4157U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1778U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6077U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 369U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4157U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 3, 0 with offsets 5602U, 392U, 3936U, 7087U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5602U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 392U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3936U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7087U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 2, 3 with offsets 7708U, 294U, 6366U, 2949U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7708U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 294U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6366U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2949U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 1, 2 with offsets 5131U, 8146U, 7220U, 8162U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5131U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8146U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7220U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8162U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5371U, 3508U, 7063U, 2293U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5371U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 3508U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7063U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2293U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1331U, 1122U, 410U, 914U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1122U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 410U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 914U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1682U, 1928U, 852U, 1326U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1682U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1928U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 852U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1326U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1977U, 2044U, 1235U, 2031U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1977U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 2044U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1235U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 2031U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 560U, 1334U, 133U, 549U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 560U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1334U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 133U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 549U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 0, 3 [0..<W_KEY]
        // offsets: 1808U, 738U, 41U, 52U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1808U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 738U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 41U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 52U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseASalts = {
    {
        {
            0xD443F950914E1E21ULL, 0x04248421D870D8E3ULL, 0xF96E3DF4E815F857ULL, 0xF6F0E636289AD95BULL, 
            0x21A74D22A77F44DAULL, 0x60A1386883A9A32BULL, 0x04E14EE122C97012ULL, 0xEA7AC7D9DEF07289ULL, 
            0xA2E3732A33034085ULL, 0x795C863D50530946ULL, 0x47658B797AF4E08AULL, 0xF4CCD6BCBCF92950ULL, 
            0x34F3096F824E660FULL, 0x47557EBDD205B565ULL, 0x8376CD770F77C5F4ULL, 0x4EC0C044B13DDD2BULL, 
            0x796549299E611695ULL, 0x55CA7F985BAFB3F7ULL, 0xCA3BFB62BC17DEB3ULL, 0x7C0EC3CD8D4841AEULL, 
            0xFD26400024502D2EULL, 0x0DDC78EF907B13FDULL, 0x5E44E8881CFC39D4ULL, 0x60B347B03114BB3EULL, 
            0x2BF6446C19740ACAULL, 0x2978A5F068143495ULL, 0xBFA0F9D347046081ULL, 0x660EB8E8DEBDA3D2ULL, 
            0x816A881EC5366A13ULL, 0xC57B82C2B33A033FULL, 0x9F79701F25FF2919ULL, 0xA311E00D0A8ED7B9ULL
        },
        {
            0x351B2D97783957D7ULL, 0x67A7BB832C0A95C8ULL, 0xC5E8E112C1CA285EULL, 0x2607640E4FB616B6ULL, 
            0xB6C3D08ED8003A2BULL, 0xF1DF567233307AC9ULL, 0x9B336A138792A699ULL, 0x717B64B64D96C5D1ULL, 
            0x0E81AE16CE87F580ULL, 0x0924422159C3BBC6ULL, 0x2E591D6EC3514A69ULL, 0xAF54AD9E842B09C3ULL, 
            0x927A5831513104F9ULL, 0x78F89B7B571B54DAULL, 0x7F57D76ABEAD58EDULL, 0x95474F8D94083D71ULL, 
            0xA67DA45F38EB3D70ULL, 0x959728012B23705FULL, 0x3E17C7EC297605B0ULL, 0x77CF3EA9C611B44AULL, 
            0xED5EA9D559388FFDULL, 0x22A8CE3368389093ULL, 0xD818E0486A8E7E3BULL, 0x90A88ED5A4D8F941ULL, 
            0xBBDC2197BF5F751FULL, 0x76FD93A81D786249ULL, 0xB75FB0B14C0BABFAULL, 0x53637CAD7B8546A1ULL, 
            0xBFFF5C3694D6478DULL, 0x6A8850E25E0D3B48ULL, 0x96C4CEEE622E58CFULL, 0xED3CC8F1F482927BULL
        },
        {
            0x0860E8C09FD2BC74ULL, 0x32B626D50869088EULL, 0x9A88FD0CD5698BCAULL, 0x61332FB33BB57427ULL, 
            0x0A34DF05C0D85E96ULL, 0xC87E945B2B2F5253ULL, 0x23D3C52CCC663D2EULL, 0x1353AADF3F745D69ULL, 
            0xA61E3A6CA5BD60DFULL, 0xF0284612B5977A09ULL, 0x40AC02E6940176F1ULL, 0x5C72C445701B94E7ULL, 
            0x1BD37B2746B7063DULL, 0x442222C8769732BCULL, 0xD1A05059484911EDULL, 0x96556BB48857E459ULL, 
            0xE166EF9D25BDE5FBULL, 0x3D40134B6ED79D73ULL, 0x8766C78BAE8D23AFULL, 0xA45E6AD367CD9726ULL, 
            0x77A26E267C8D7963ULL, 0xF54256DA227C5A2DULL, 0xF859DD930A304709ULL, 0x332BF308D59B3DE8ULL, 
            0x7F78603FAE2269C9ULL, 0xCA914FA618A6DCEAULL, 0x4EE73FE4011BDE86ULL, 0x065F42CD9953181DULL, 
            0xB284EBA2690B8AAEULL, 0xA123DB413DCB4C19ULL, 0x32C6132A84DD20C4ULL, 0xFEB6671C6C630E5EULL
        },
        {
            0xD2FE5C0C5AFC5125ULL, 0xDABF7E5C055866DCULL, 0x1DBBA60A97A49AB7ULL, 0xA28132CD56269166ULL, 
            0x7687C8A52DEDB009ULL, 0x813F69230BD8D476ULL, 0xCC27F3196DE8F31BULL, 0x6413C94C877077A4ULL, 
            0xDAE431DD29680A38ULL, 0xB0AB75248C8348E9ULL, 0x3E0DCF312757A2C7ULL, 0xBEE160AACDF27893ULL, 
            0xCEA0CBD0F05ACBCAULL, 0xF86A8328B5255789ULL, 0x444A87C72AC6CFCBULL, 0x2A45221F7F444D78ULL, 
            0xE97640BCD011F703ULL, 0x6E52A6A12BEE917CULL, 0x580D9F11FFB1BB85ULL, 0x95E6A2E4436E51FFULL, 
            0xCA2145C96038C439ULL, 0x20ABE19452D57B0FULL, 0x09F23535B8823124ULL, 0x0AF024C21A81DDA3ULL, 
            0x48A82270B8A3F2C6ULL, 0x0463C37D5D5FFA4CULL, 0xA6122398A8DAD33CULL, 0x503DD47BAFA47B32ULL, 
            0x57667EDECC38142FULL, 0xEF06E60B033F2252ULL, 0x1F27F5A7EF9383BAULL, 0x418AF2F727B1644AULL
        },
        {
            0x881F084F55200108ULL, 0xEB59A242BF7A0FA9ULL, 0x9890D877D9A6B6B6ULL, 0x0E1AA27034C72726ULL, 
            0xD27C1E372FAC414FULL, 0x8ADF8F6B666D8370ULL, 0x0CDCFF441E6CBB6AULL, 0xBFAD0D6A9787DEC2ULL, 
            0x6FAA64D621C7529BULL, 0xFD903CEED8AB5204ULL, 0xB5E493E09AC6D724ULL, 0x645ECC72419AB643ULL, 
            0xA39771597A6F373EULL, 0xF8A8C383C79310C5ULL, 0x53A610036FF41F05ULL, 0x0CD079C38C2CC062ULL, 
            0x43E9A639123577F3ULL, 0xA733A1CE908B6CA7ULL, 0x5816946B35732CE5ULL, 0x798CCDF2E7D75BCBULL, 
            0xF173B9D1F951512FULL, 0xB9D8538CDCF8B8CCULL, 0xCFFB636ED7DA800BULL, 0xA6A64F682790C515ULL, 
            0x7905CC444C6B016DULL, 0x9F10F0F6DABA679AULL, 0x04791CE6561CFBEDULL, 0x8E7A2B9D351B94D3ULL, 
            0xD38DF2D6451257F0ULL, 0x074E07724B23F6D2ULL, 0xD11DDBC282C7F21CULL, 0x3114DD41B83DD843ULL
        },
        {
            0x37EF4CD06FE30DA9ULL, 0xB7CC0967E6EC0FC1ULL, 0xF79FEB08617CCF5AULL, 0x331C2815FC8ACB1DULL, 
            0x1CDF4247820A4CFBULL, 0xB1978584C67367B8ULL, 0x1F86C8CEF65D5DBCULL, 0x8393D6FB1213BFCEULL, 
            0x25A086737BD121D1ULL, 0x7A30A30B554EA2BEULL, 0x4E0EBDA5ED0FA673ULL, 0xFBE524B4F8311BFDULL, 
            0xAD3123B5ED8BBF32ULL, 0x5C9760716130D868ULL, 0x9B123110D4D5A00FULL, 0xC59367A8C0850638ULL, 
            0x61A7C03517325E63ULL, 0xD536AEF55593E517ULL, 0x9C0B57BC1FFA866CULL, 0x380BAA0306093430ULL, 
            0x0CB809E0654BB0D2ULL, 0xC6A38A7126F5CED4ULL, 0x5DF9E3C8966200C8ULL, 0xF95A498E6672DBB6ULL, 
            0xE8AA062CC18BD7EDULL, 0x699F88793A76DA72ULL, 0x83121CA3B9CEDD36ULL, 0x414101CDF4EA3740ULL, 
            0x3CAB0C49C9536B34ULL, 0x23C13AC799DCD515ULL, 0x11E355CD95187787ULL, 0x98A17DAD59412DAAULL
        }
    },
    {
        {
            0x674D7553D9C6953BULL, 0x0E0E58225A9DCB24ULL, 0xA1D028D9416A6F76ULL, 0xFCAD6FE29C410D57ULL, 
            0xB1DA227591A3A5DCULL, 0xD8E8A8E70884CB70ULL, 0x1BFD3971CA156A8AULL, 0x2325AEABB5F2138DULL, 
            0xF08B87B6F960AA10ULL, 0x49FFB2D4AC0B0B5CULL, 0xE1ED07932957F647ULL, 0x9C84D89322026236ULL, 
            0x5484488E00FE744CULL, 0x01891A2BDBC2F631ULL, 0xACE851610F30DDE8ULL, 0x6FA2AD9741F56997ULL, 
            0x77DF38BC2618F51AULL, 0x4C6C35815A678DE7ULL, 0xA633320B7CB8092CULL, 0x3245A7F19576F04AULL, 
            0x0115F97F3CFF2DF3ULL, 0x0968CDBAE483A517ULL, 0xFC829D0D3B4B7869ULL, 0x70D3A9AB42A0B632ULL, 
            0x57D427C53D0CBCDDULL, 0xB90317DE7C7B991AULL, 0xA9AEB30A216247D9ULL, 0x86AEC5157A8EF267ULL, 
            0xF90F919D6F5C9FECULL, 0xF3B769F122CB273FULL, 0x7D1F7AACFEDDDF96ULL, 0x5446F52610FC0953ULL
        },
        {
            0x28D85F1371D7E045ULL, 0xD5FBC4FF064B3364ULL, 0xF9C69C09F6C49E3BULL, 0x34ABCA86B61734A8ULL, 
            0x8131C4370540714BULL, 0x610D99391526D3D6ULL, 0x71A11194DA42FB65ULL, 0xDC9E54BC8E515467ULL, 
            0x0378111E5CD1B02EULL, 0x501621499C3988EFULL, 0x261F71FBE8EAA0F5ULL, 0xB7934A8202300CD8ULL, 
            0x82427B1D0B808D48ULL, 0xCC1BA95AED5DAEB0ULL, 0xADD07C469BD76A28ULL, 0xD52064AC248874EAULL, 
            0x90E8693F8F30A57DULL, 0xA024FE1F3C1FF9D5ULL, 0x791BEB124AAC6936ULL, 0xC24315A8877225F4ULL, 
            0x6B4C349D76DDAE32ULL, 0x8E203C6A98831831ULL, 0xB010E71369B14138ULL, 0x9BE6867A21E85276ULL, 
            0xADCF47323A491F83ULL, 0x6F6EE5F457F621C2ULL, 0xF41D2DD47A40AD25ULL, 0xBDFA9ABEE5A7CAB0ULL, 
            0xE7CD18C1AA932FFCULL, 0x01B04F0F5F8B1F6CULL, 0x0C0E3DFD3AC8F8EEULL, 0x56948F4F5F0F6D30ULL
        },
        {
            0x354B9CDDEE9E02B9ULL, 0x24D44F67C61CB00BULL, 0x47F13E3952751324ULL, 0x3D0F64907D276D54ULL, 
            0xBC513B908CB99986ULL, 0x852B8F4F40D7E8CBULL, 0x3A6EBB12D0951D33ULL, 0xF1E7A9DF6D171B8CULL, 
            0x65A38F8127E17ACEULL, 0xA4F11F1A7D73479BULL, 0x7B82037E040372BDULL, 0xB3E556431440CDA7ULL, 
            0xED3C65E3B157EB6EULL, 0x3931069E514A3C34ULL, 0x180B0B22572828E7ULL, 0x384E78580906E3F6ULL, 
            0x1F7A77E7DECB9A90ULL, 0x9581F6AE2F6166AFULL, 0xB6F65B0CE10B6B3DULL, 0xB90DF85FA4B6F413ULL, 
            0x0AFEA418C08E2D7CULL, 0x0E6848775F6895C4ULL, 0x22533A578B4B9F02ULL, 0xA899396AF436A731ULL, 
            0xC1EC6409353AEF89ULL, 0x963B7260927D139CULL, 0x6F022E6E2239315AULL, 0x978FB94E76DCF57EULL, 
            0xA27B5330FC101C02ULL, 0x827B91D2DE200289ULL, 0xED05E8736B65E668ULL, 0x8846B4A606B1AFC1ULL
        },
        {
            0x7C49400CCFAFB42DULL, 0xE39D85D3F6947272ULL, 0xCB5F7E2F1496ADDFULL, 0xD855FBB3FE1FF849ULL, 
            0x3315CF82B1D2290FULL, 0x12EEF5BCC4406757ULL, 0x5AF393E16B9BCB5DULL, 0x0649A9B36AAE1DF3ULL, 
            0x0A35FC447746C5DAULL, 0x5459781D0DDFD497ULL, 0xDB11FD8F705ECA55ULL, 0x93C13B456FE1D696ULL, 
            0x293A808B9A317164ULL, 0x1A10EF4E93654A79ULL, 0x3DD8CD82AC38EDD1ULL, 0xA0D9CAEE86A21376ULL, 
            0x17C3FC8001DEB46FULL, 0x3D13187D7A89EAD9ULL, 0x48679A0DBAEBE791ULL, 0x8543C6D0CFC281D2ULL, 
            0x7E45402757AAC95CULL, 0x41E0F4C66823A84AULL, 0xB7E6AD42854113A2ULL, 0xDB1D3C86F8A61C25ULL, 
            0x320F5C8F8ABA8F71ULL, 0x0ED18255A11394DBULL, 0x20A2C4A03242CD1BULL, 0xD890ECD6CDCF2A8AULL, 
            0x4C29D3D5B5B51398ULL, 0x34BFEBB0F495076DULL, 0xEA99EBA3E30EE7EAULL, 0x633621446EFEF2FBULL
        },
        {
            0xAA437CBE9B1CB23DULL, 0x0E426F21C4DB3753ULL, 0xD9C2B3D4C7AFAB29ULL, 0xC9485F2825AC1874ULL, 
            0x6589C0ADE3910ECDULL, 0xAB3EECDA17EE240CULL, 0x3C1D8E8EC1C1CCE2ULL, 0xDCE3CAAFC1986F7AULL, 
            0x9C49FD78C22D1C7BULL, 0x44CC5745468EEDE7ULL, 0x6D350148991CDE71ULL, 0x249806825E305F37ULL, 
            0x3A5F5206EEEC6DF4ULL, 0x31C755E200091D13ULL, 0xEB621D80FCCFB214ULL, 0xB6A62F32D9FBB47CULL, 
            0x66683F9F1E6113A5ULL, 0x4BF2B4429C1917E1ULL, 0x487E1989D1C6E6BAULL, 0x12EC7D2F283EDFF5ULL, 
            0x32205BCC3693A69CULL, 0x340F190FEE15D4A2ULL, 0x5C4924255C6FE14BULL, 0xA72424523BD6159EULL, 
            0xF9D5D68CD918793CULL, 0x10C55DB6A1CF72E4ULL, 0x1B4B413BD72AE8E6ULL, 0xA5DED171B413945CULL, 
            0x16BCF1D3924021E6ULL, 0x5C64E7D2BABC5E19ULL, 0x1C531B42303D0D85ULL, 0x48B64263CB15FF4DULL
        },
        {
            0x131F71C4D9B368E6ULL, 0x3A79B2F64E83E779ULL, 0xF1CCC68C93584D42ULL, 0xE5634AF43C7BB8E6ULL, 
            0xC2667AF1F7DF3D46ULL, 0xCBC55FC501DFFBE4ULL, 0xAA517FED7016438EULL, 0x89C92DBA02996882ULL, 
            0x6210F29082FAE15CULL, 0x6912C782B9D4DB50ULL, 0xD72C4E51BBA4CB09ULL, 0x5187E351CA2D768FULL, 
            0x083657C7EE38CBBDULL, 0x3EAECABE536D822EULL, 0x5846FE2C9143CD82ULL, 0x9909827B3BD8F2F8ULL, 
            0x96B80F35866F8891ULL, 0xCCB50D86C675E010ULL, 0xA8368C4529F79599ULL, 0xDEF8043099DFA74DULL, 
            0xCA00AEB317D669CFULL, 0x54B8E86CF9283BA9ULL, 0xE8D83FEBA12A0285ULL, 0x6BFAD7B8746EDB89ULL, 
            0xD94E7814E5B6E4DEULL, 0x39B0945A2857681BULL, 0xB1C23E1BADDD7BFAULL, 0xEB8ED53D15F03718ULL, 
            0x74193284A50E57DDULL, 0x637A12B7756F3074ULL, 0xDFE07C09B758FF65ULL, 0x5EAFD646247EC98BULL
        }
    },
    {
        {
            0xE02A99C3160F3030ULL, 0x1DC292669FDE1FA8ULL, 0x8F57A7D9A3D3C842ULL, 0x5FAF335F83DB49DDULL, 
            0x0230309B5268E136ULL, 0x4ACC7F9FA1E959F5ULL, 0x7FE44B47922F5BD0ULL, 0x045FCF67CD9CD8EAULL, 
            0x7F24C7D986C7403FULL, 0x0ECB6B956CF6336CULL, 0x0DB0DBA67D43EF0DULL, 0xF6A451ED62950CCFULL, 
            0xBC875A38E95B6F39ULL, 0xEFC7893287B89355ULL, 0x4FF4314F0E1664CDULL, 0x2B1D28F151D09FEAULL, 
            0xEAD2F3C7FBF7B514ULL, 0xA3E09A8C11402C24ULL, 0x0C22635B842926B4ULL, 0xAC243DDD4B6691D4ULL, 
            0x8E89A44D97B50192ULL, 0x0A80770D8DCD059EULL, 0x87A77E4C191BF706ULL, 0x0720DF47744091B0ULL, 
            0x1DF02866CE7E6AC9ULL, 0x75189743E6DFC6C1ULL, 0x61B0B7CD3793EB02ULL, 0xB466F4B393A00267ULL, 
            0xAB4F1096DCE8FB3AULL, 0x315A4CD441EC089EULL, 0xAF0BF75153928008ULL, 0xC7206C0503B459F6ULL
        },
        {
            0x7C52BBF52CA37DAFULL, 0xD32219E46322B875ULL, 0xCB532200C41217A3ULL, 0x6E7A42140CE08A14ULL, 
            0xE889FFB02373D57DULL, 0x61737F3A04C89DA4ULL, 0xCD98A3B0CCE9667CULL, 0x215D5D2B94C15182ULL, 
            0xB71BDB20E0D8234CULL, 0xCFD699F11F77D64DULL, 0xD978C7080E185BE1ULL, 0x5500F07E2EB35458ULL, 
            0xA0453A353A05550BULL, 0x0375814DEB9FD87AULL, 0xA98464A5214C02A4ULL, 0x90EB991AEEA72351ULL, 
            0x9C1DF396E336AFD0ULL, 0xCD61C9780025E690ULL, 0xEBCBCB02B0E52100ULL, 0xD270A515E1B91460ULL, 
            0xA3FC9F2F916F1FB0ULL, 0x4A0B2B846B7AB8B7ULL, 0xC205B72D368BD10AULL, 0x4393903346BB477FULL, 
            0x537587FD53D6DBF6ULL, 0x3900F529F6F82F72ULL, 0x4451373AF57F181BULL, 0xD3B7DC5B4EF1CFBFULL, 
            0xAC6FF455CA0CCE9FULL, 0x59DB7406DEB61307ULL, 0x178F8C289DC83C12ULL, 0x077C6F9B4E60251BULL
        },
        {
            0x465D0575D1295C1AULL, 0xEBED77ACFDAAC1BEULL, 0x9817833B6DC78BB5ULL, 0x436C80BBCC55DCCEULL, 
            0xF3356EF6F2E9181EULL, 0x4D32D56B85224897ULL, 0x3E9B7C5BC397CB27ULL, 0x53250113CC3832C3ULL, 
            0x3A7373B4D0012317ULL, 0x7937A857E324565FULL, 0xDB45F318E1CA473EULL, 0x532BF9441ABFB236ULL, 
            0x8581F2A4259D3709ULL, 0xCCC45AC9E4940ED9ULL, 0xDB390BE88CE976F4ULL, 0xDC247AC352862AB3ULL, 
            0x67C279D2EE58BCE0ULL, 0x57A41DE7B8E71F35ULL, 0x50C3C6BC1F312A54ULL, 0xADEAFA3652B0477AULL, 
            0xB6E6AA127DFE8E92ULL, 0xA17DF08C06AF5D03ULL, 0x735214E65349E3CBULL, 0xEB3552A27B01AEF8ULL, 
            0x150DED4F00171F1FULL, 0x17D55B5A9C4549F7ULL, 0xA77BB5153DE6B419ULL, 0x6ADC1133624B190BULL, 
            0x5E11F8CE7BE7ECD2ULL, 0xF79296D188360080ULL, 0xD552DA03BD55B185ULL, 0xC177C7BEEBF55B62ULL
        },
        {
            0x5DD927D5F540F2E6ULL, 0x758E25D21C9DDB88ULL, 0xBC989C3EB540765AULL, 0xC096F22CA3832957ULL, 
            0x05A30DECB849CED9ULL, 0xF48437525BE49627ULL, 0xB3B74FC18A2A124EULL, 0x48D4B219449A68E3ULL, 
            0x478543E32D2E4983ULL, 0x44094471943E6484ULL, 0x8662195E672F81FBULL, 0xE196F76867ECF0AEULL, 
            0x1F95C52F00BDB1C5ULL, 0xDA3556231AE9AEE5ULL, 0x1CDC78D292246F63ULL, 0xEA49CB7AA782F75FULL, 
            0x50201560D4BF0AE5ULL, 0x58C16FAC1299CF0DULL, 0x638058BC974F00B0ULL, 0xCA88D1C17E004754ULL, 
            0x9968448528403830ULL, 0x2B06A6D353D73082ULL, 0xC8D3ACAD8D76D26DULL, 0x7DE7D7BA05157A10ULL, 
            0x744025D4B5EA43F2ULL, 0x6DC3DA18634C51A4ULL, 0x5FA0C2E34E1AE62FULL, 0xE894228885972327ULL, 
            0x1A179EA212F47298ULL, 0x0A734D11A444AC5AULL, 0x929E3DB5C9296083ULL, 0xC5BB96811A8D59A7ULL
        },
        {
            0x2AF5164A7307DAA2ULL, 0x6E01829CBD5706CCULL, 0x3E259798E29F810DULL, 0x345D777AAFF1406BULL, 
            0x7C33B4C4ACAAED74ULL, 0x015A9302FF3E83E9ULL, 0xFB2B76A2DABAE8FEULL, 0x5B206354E7A1086FULL, 
            0x9473CA0247AB04A6ULL, 0x5681FBF3750EF98DULL, 0xD442C7CB0DE88BB4ULL, 0xA8784531A8C70775ULL, 
            0xC227783F1BBF8BDAULL, 0x5E8D39DC2B6FDB21ULL, 0x8C91C1B181402FA0ULL, 0x90AA883D7D7E496BULL, 
            0x9D19365173CAE21DULL, 0xAA4E55ECE73866ECULL, 0x43329D0FD520B5B6ULL, 0x00190F45E00F79A8ULL, 
            0x771B14FC9F1C637EULL, 0x3CF4BD8C16DECF4FULL, 0x477287D19A6BD396ULL, 0xA950CED53018BF31ULL, 
            0x09F34C6536A5C48DULL, 0x6478295592EB3C2EULL, 0xA2C985AD025C538EULL, 0xCFDBB87E2C9BDC55ULL, 
            0x5DB8493D7367BE62ULL, 0x5AE12E45E1FEFD07ULL, 0x61E4B2847CB2A1E4ULL, 0x0AB3219B37A7AE64ULL
        },
        {
            0xD4AB8AEA5C2E82C3ULL, 0x98B65CFBE8BDDB0DULL, 0xCB51B7BE54C1592EULL, 0xA01FFA396B0ACDA8ULL, 
            0x6D1A98349BC85DC1ULL, 0x423E6291940F2B56ULL, 0xE915D0F7B233E8A0ULL, 0xB75C1CE80CA124C7ULL, 
            0x63FB448499106493ULL, 0xF2660411A3236B8FULL, 0xD41A3AEB1D4DB893ULL, 0xEC9B6DC1ACD2239AULL, 
            0x861CE9256042BD17ULL, 0x345DFFBD324CC4EAULL, 0x97D1E388C366AF64ULL, 0x1125DB1B9DD0CC8DULL, 
            0xA48EFF05B685862BULL, 0x31697D769418A334ULL, 0x697F790CB26FC237ULL, 0xCB79A01B23020175ULL, 
            0x026031A7D97F4028ULL, 0xBFBADEAB757392F3ULL, 0x061348C6E211D333ULL, 0x7D123E13DE128976ULL, 
            0xA5288D6F9D0D81F1ULL, 0xABA0AB96C901FB0BULL, 0xFC094CD40BC2A3E0ULL, 0xE180C499367A1ECBULL, 
            0x3370D6C42E3A4E63ULL, 0xD110D29C02787E96ULL, 0xF5206C25D92512B2ULL, 0x73637AC05A34EB83ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseAConstants = {
    0xF33DE4C893550D51ULL,
    0x4CCF5B6868C79964ULL,
    0x56DACF962893EC80ULL,
    0xF33DE4C893550D51ULL,
    0x4CCF5B6868C79964ULL,
    0x56DACF962893EC80ULL,
    0xD7F634C228DC54B8ULL,
    0x10768569972CF25AULL,
    0xF8,
    0x33,
    0x6A,
    0x5E,
    0x01,
    0x57,
    0x4D,
    0x0A
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseBSalts = {
    {
        {
            0xE73BB4DB82EA2AD2ULL, 0x8636BF34DCAA042FULL, 0x8B83F92B74BC3B9DULL, 0x86067E2B74650978ULL, 
            0x10E293F83B075725ULL, 0x321BF6B6797D25A8ULL, 0x8C0E48CAD752CECCULL, 0xD87E39756AB153EEULL, 
            0xDCA3343343A53E4CULL, 0x705735710FFF1E8EULL, 0xB9FEA15EF96F2B35ULL, 0xBA6B80549DB7805BULL, 
            0x88DBF3F56780217EULL, 0x94864BC1CD2BE5DDULL, 0x6054B56709CC4FE2ULL, 0xA70DE631198B155AULL, 
            0xA4BBF7B0F7C968A6ULL, 0x036DFF72E34988C3ULL, 0xA733C50A209858BCULL, 0x2ABB929DF179B1D5ULL, 
            0xD84CE11E2B3B2B00ULL, 0x9726A8923A32D2DEULL, 0x2C1200D89A438A4FULL, 0x21BE3AE391F94C8BULL, 
            0x825836AFB1DB505DULL, 0xCCE05BE77F9FC8A5ULL, 0x6973014425122B09ULL, 0x885B8FF53B985070ULL, 
            0x6E6CE1C8F27FFD31ULL, 0x655B37B93ED161D9ULL, 0x598DF69227772D21ULL, 0x972B26ACEE22E0BCULL
        },
        {
            0x9CCE4296C057F38BULL, 0xEFFED481884681C5ULL, 0x7DF7D4888D48D749ULL, 0x44F4F2DB52BA7441ULL, 
            0x51A0F2D9166D4B3BULL, 0x431C8C081841859DULL, 0xBC9882BBCF33631DULL, 0xA869416CDAF87960ULL, 
            0x21D62A0483BD8A0AULL, 0x81F9670A486DC37DULL, 0xD57D732D4BE6EDCBULL, 0x6A24197A1ABE4BE5ULL, 
            0x8D4E614312190150ULL, 0x9EB825A1977D08ECULL, 0x528F299F3C94C35FULL, 0xE27B1FC84812ABAAULL, 
            0xA5A74E9B7BC1FBFDULL, 0x5EF14F7C7D9552BDULL, 0x94A2C03081D58D97ULL, 0x98DF8FFE7FB0B910ULL, 
            0x1F912670FD08CDA3ULL, 0x25024AA92A4AC2C4ULL, 0x6ED9B0DB31D1E521ULL, 0xE5F63CE84DB03B13ULL, 
            0x0373E94011C8FF4FULL, 0x8E1D7D09F59ACA35ULL, 0xFD12586662B6993DULL, 0xD619ABA942243A4EULL, 
            0x10B6484DC24838C0ULL, 0x0CBCA333ED1198C9ULL, 0xA830A0415C0782AAULL, 0x6462B9F762E2E379ULL
        },
        {
            0xD285FA4EA384CE72ULL, 0x73504FC44E8D2AF1ULL, 0xE5D38CB175D91F9BULL, 0x685313E3DB44576BULL, 
            0x1CA903626790EE01ULL, 0xE3DA60DAEA99DDF5ULL, 0x0E16CCEEC9510D7DULL, 0x24F5C3F865596C56ULL, 
            0xEEADC3E4C9951F73ULL, 0x61326F29EC6F2261ULL, 0x7D685E1FCD20C736ULL, 0x14C752F3EA4987ECULL, 
            0xDEAAB367868CA65CULL, 0xE16643322DD00814ULL, 0x6A3073EED2D87138ULL, 0x2F426786A341792BULL, 
            0xD724947850BA8D3BULL, 0x8BCD7574D9D27D7BULL, 0xD23FE9CE488DF694ULL, 0xC8DAC9C21592840FULL, 
            0xB71338D732B9A1A5ULL, 0x5AAEB41A6A848BB0ULL, 0x6849630D2D367E84ULL, 0x6029BE6C62BAE337ULL, 
            0x85C2DC1A4CE52459ULL, 0xFA0DE3BE3E1D9185ULL, 0x7A823A759668AFACULL, 0x4D18F4A16FF7DF96ULL, 
            0x930542CB49B5672BULL, 0xD0C3CFE97DE08079ULL, 0x30115EF931DD0D49ULL, 0xAB0AE827A76261A4ULL
        },
        {
            0x3170446449B06FDEULL, 0xEF54533A55258F41ULL, 0x6273597120CC1398ULL, 0x57E3BEF003A321DEULL, 
            0xE82C2CC8BD2F5907ULL, 0x4290B214E1774A2AULL, 0x83DE01C46BD545A3ULL, 0xF5AC6A06E6D10B57ULL, 
            0xEBCAACAC5CA9E2E9ULL, 0xBB34B47CBC9AF905ULL, 0xDE830EEF7933D385ULL, 0x3A0C6BA41013668BULL, 
            0xB994DED323DBDEC9ULL, 0x687DC9C9692629A0ULL, 0xFA0B5C543184EE44ULL, 0x6DECB9602794CA50ULL, 
            0x2765F8BA94414204ULL, 0x14CD616C9B694145ULL, 0x577A12E73B36D348ULL, 0x994195F9354FDD04ULL, 
            0x535AEE80C057D92BULL, 0x0CD61C8303DCFDDAULL, 0xD3B290E87C6C9985ULL, 0xBF49E89ED8A10596ULL, 
            0xECC68B7463C28CBAULL, 0x33FBAA06048D7BEEULL, 0x2BC0B08F10130DC8ULL, 0x81E4477D56247238ULL, 
            0xBE15F1685C43EB49ULL, 0x0A699CC9843F52FFULL, 0x567F662E603DA3D9ULL, 0x7E357BA752D1A53BULL
        },
        {
            0x286881BFE97D93A9ULL, 0x9BC17E4016C4C9C6ULL, 0xC02207DCB14E9CA5ULL, 0x7F1025491857E262ULL, 
            0x754083C14873C383ULL, 0xBC1C92CA6BFDC616ULL, 0xEF1E00AE8193C444ULL, 0x4905178F55ADD85BULL, 
            0xA1BA7C3B2DAF1DA9ULL, 0x71578DDEF359F845ULL, 0x589290CBF14D1273ULL, 0xA848DD52323DDE90ULL, 
            0x3C0EC7E8A5808A29ULL, 0xD12CEB6B97419AE7ULL, 0x6DB8D39E11A94475ULL, 0xC43E7C2450AE1F34ULL, 
            0xC9E7136B2200B539ULL, 0x7326F1B580895539ULL, 0x0C6FB541ADC15A64ULL, 0x7E529A6636EBC7D4ULL, 
            0x0BF7B6AFD1C316C8ULL, 0xA6E5EDC70D2AEBCBULL, 0x1B10FA129F84B4ABULL, 0xF70451040D7307D8ULL, 
            0x02921527836CA518ULL, 0x2656D8F3B4710A75ULL, 0xAF93F1FAF05BF709ULL, 0x1D885833096FCFC3ULL, 
            0x6FA40B36D3C0A3CFULL, 0x4DD8387FBDC3C8D2ULL, 0x08F280A383AE170EULL, 0xE8EF2CC69B34CF84ULL
        },
        {
            0x6343762E57C91BEEULL, 0x459B9624F0DD55C2ULL, 0xECEAC465E2FE1E73ULL, 0x0AC353FFCD3C0D0BULL, 
            0xB1EF566D8F181F78ULL, 0xE4378838897BF3BBULL, 0x05622AF815EDBCB5ULL, 0xBBBBBEC593890E5DULL, 
            0xB57A77A5FF3A979EULL, 0x6D9083A7D5F453C2ULL, 0xF3B587B6BFCC996AULL, 0xFB9C855434DC6752ULL, 
            0x74A4609D4B8C2338ULL, 0x71EDF072E24023C6ULL, 0xF0270C59B6D1FD01ULL, 0x17F3C2CCD4F6E9E8ULL, 
            0xFD715830D1BC413FULL, 0x8D7E3CBA9A2F3A5DULL, 0x6A63A7B19FFC7014ULL, 0xE724B7CCC4C826EFULL, 
            0xB18B52E29756A39FULL, 0x77D8BE0ABBD934E7ULL, 0x25FC49288FFBE1A2ULL, 0x455515A96F9FDE4AULL, 
            0x88077AFD905D0646ULL, 0xEB9ADAF87EDDCE44ULL, 0x064344704FA9F833ULL, 0x054A7E8DBE03C32BULL, 
            0x5DD14C49CE004F56ULL, 0xEB99F44C14E8A8BBULL, 0xD98F98E7066FC418ULL, 0xFC2993D22FB3E0F8ULL
        }
    },
    {
        {
            0xAC6ECC48F6F9DF61ULL, 0x5542B7C1D4B82F79ULL, 0xAE81BCED58434F20ULL, 0x768802BEDDC5F61BULL, 
            0x69DB35F95E8AA486ULL, 0x2A6F1E5C27425B1AULL, 0x0FC3050DC7E56EABULL, 0x7E026B3E73B9346CULL, 
            0x409D7E255DF45604ULL, 0xC5E489E7B19092BFULL, 0xB60F17519AFE3B1AULL, 0x7FC5ECEE09FE7CCDULL, 
            0x2B0CCE9B0ABACDAAULL, 0xCA86D7BF42695C24ULL, 0x735A950198CE2412ULL, 0x39ACA9AFD2BF0768ULL, 
            0x9914AAA1D71DDE24ULL, 0xC1D76728406DBD08ULL, 0x98C5823D579473E1ULL, 0x0CD3E7BCA281459CULL, 
            0xB95B3677D7B30F2DULL, 0x5B88351B2689B13EULL, 0xEAD6AABAEFF3A102ULL, 0xB92D891C6363B447ULL, 
            0x8AAC71417526107CULL, 0xF801455CE6A2A184ULL, 0xB02A058623ED01E1ULL, 0x6E2D75E14689D5B9ULL, 
            0x9A45941D2A1D4632ULL, 0x74A9BA89A2F63969ULL, 0x77E07D1F7D815673ULL, 0x93820B160AAEACAAULL
        },
        {
            0x6A412C63CF28F0E2ULL, 0x5A654EEEC42F0C63ULL, 0xBB7C8A00E2AD56C3ULL, 0x1AEC1BD46B1AD366ULL, 
            0xFDB4371A0FFC6E6AULL, 0x8257AA0EA5831D55ULL, 0xC90C4D44983FCD43ULL, 0xB8A19FA55440037DULL, 
            0x5CC57C0C31B6055BULL, 0x5ACA48E41A1BC677ULL, 0xF85163261B6CF660ULL, 0x8B0D026304290A2FULL, 
            0xA8078572E7A44C6DULL, 0x59F5E97505742CB7ULL, 0x152876B45059A6BCULL, 0x25EC0F6638196D1DULL, 
            0x54F5137B8F7AC08CULL, 0x86DCA4A9FF3D6380ULL, 0xD4AD571DFCAA6473ULL, 0xB955B93E346B498FULL, 
            0x7A881D9F66671492ULL, 0xFCA02240D30EB4C0ULL, 0x10C7B09F95FB9526ULL, 0xDC33F1B78A3CEF80ULL, 
            0x871B2D58BC7C0B4DULL, 0x9CEBF6905CA1AB36ULL, 0xAAB8C02AAEB33F32ULL, 0x6FF1BA120799CCB6ULL, 
            0x547931B5D559EE6BULL, 0xF332C60B185727CCULL, 0x24E73A754FCCD910ULL, 0x3363347EFF03DF41ULL
        },
        {
            0xD423F14C02C51F00ULL, 0xEBFC1DFFE511AA81ULL, 0x81F9E545FC157EF4ULL, 0xB988A2C03859CECAULL, 
            0x34A7C0DE162D4641ULL, 0x12F1CE3BEBEB3C5EULL, 0x9A62FDDB1716B739ULL, 0x61A1971152750D3EULL, 
            0x72DFFBDE471C654EULL, 0x92E940AFB567F13CULL, 0xB35151007D61DE05ULL, 0x90122512D49C330FULL, 
            0xA661325F1DD6CC16ULL, 0x98A8DF34D2A5C845ULL, 0x3F60B2EC625672DBULL, 0x2FD002364EF0EAF2ULL, 
            0x630DC80A8F46C4F8ULL, 0xD5805855993DD83CULL, 0xDCB365B05E0E402FULL, 0xEDD447CE500B115EULL, 
            0x8BE5EF5236793E80ULL, 0x325B5547405B9AA0ULL, 0x84EB14FE725F33FCULL, 0x6EC19B5D4E7327CEULL, 
            0xD995CF76EF7A89F4ULL, 0xAFAB60812783E54AULL, 0xC677E03CE77CC140ULL, 0xB608A19A2BED1231ULL, 
            0x059028B0A6BA48C8ULL, 0xF998CD0CF195679CULL, 0xBA47345039BC1FD1ULL, 0xEB20EACC8E23126AULL
        },
        {
            0x762FCD7C24AD5C2DULL, 0xF0EFA2D9E703FC3BULL, 0xF654018C8E756034ULL, 0x9468304FCAD29DC3ULL, 
            0xCAD980FE60224008ULL, 0x7A18F02AFB8ACFFCULL, 0x9B10DE6C1DC910CBULL, 0xF00F37C5022456F9ULL, 
            0xECD05DE00E6483A9ULL, 0x5A4BA55EE483E3C4ULL, 0xFA8F24410774359EULL, 0x9C53E1608C675B6EULL, 
            0xC56A0A356B226847ULL, 0x5318D4CCCC8B221AULL, 0xAC4C35090975D47FULL, 0xDB7724DF1F81ACAAULL, 
            0x5E931963D9DE66E5ULL, 0x69D4A1B24665134EULL, 0xF7BECBA3ABD9FADCULL, 0x6D5298A77BCB272CULL, 
            0x2076909E85D3C9D3ULL, 0x6B24596A7462DA00ULL, 0x0FECE42CAC767B41ULL, 0xCC8681EB984A7253ULL, 
            0xB1E50D800632FF16ULL, 0xE9DB1C23E819C391ULL, 0xBE09C5D9E55ADED4ULL, 0xBD5C7EB148CA109FULL, 
            0xC268CD07564BF9CEULL, 0x9B03E5FA3CB790EFULL, 0xBDA3FD3DDB59D366ULL, 0x6BE810119AD34E96ULL
        },
        {
            0xE5D9034DEDEFF338ULL, 0x0A4FAD283B0AEF2CULL, 0x936D341E875959A1ULL, 0x7BB4616BBA4AE411ULL, 
            0xBB62BB65ADD65591ULL, 0x4E3114A3EAB4CB0AULL, 0x5C15EB96B94F60BAULL, 0x1575D4D358C6DCA8ULL, 
            0x524E2D79B37F8F5BULL, 0xCFB69F53E805EC1AULL, 0x926C62D28FAF7B6DULL, 0xA1035039417F40BAULL, 
            0x998EC64FC2ECF1B0ULL, 0xE6D3CD3FC3CC746DULL, 0x69FEB908A443013AULL, 0xF10F22B98CA3A310ULL, 
            0xAD918C48EA9E77F8ULL, 0x44185890F3F31C9FULL, 0x14AD86BDAA13B05AULL, 0xED502E2AD02B6B7FULL, 
            0x078A8D25CEBA7072ULL, 0x25BB91203B886617ULL, 0x52FE1CDF2B4E0212ULL, 0x51DA441055F2778DULL, 
            0xC16890944C9D8B9FULL, 0x2C05FC4BE2C3E6CCULL, 0x1D70FFC8339695DAULL, 0xAA9BCF5561342844ULL, 
            0xD0A9144C775F3AC1ULL, 0x87586CDD4A9D04E8ULL, 0x709F17845BB8F5BCULL, 0xA3242D42A267763DULL
        },
        {
            0xE04FD39DCE98E9F9ULL, 0xDAAE12417CAF5DD5ULL, 0x0622A1A9F82DBA97ULL, 0xE78B5EA9E36F1FF7ULL, 
            0xECD02663BBA93115ULL, 0x2660EB3F17E173A8ULL, 0x79FD4608C81C5DF7ULL, 0xD0A843FE84D8BD66ULL, 
            0x3CADF08FAAF2A81BULL, 0x77DC7F1D544CCE79ULL, 0x105B2EFF2825B989ULL, 0xC3DC4774492EFF6EULL, 
            0x1495FBD17149CDA3ULL, 0x01928752FF3AC7C2ULL, 0xE5C86B8E2552E29DULL, 0x157616403D135A5CULL, 
            0xCCA56AC95832B943ULL, 0xE0FCF3ADE66696F0ULL, 0x3CE3DE1C9CBEAC1FULL, 0x26F3122FF2CD7086ULL, 
            0xA3496A4890E1196AULL, 0xB476948EC7B793B9ULL, 0x32F5EFE7A996242DULL, 0x1C27840480D9D56CULL, 
            0x5A422C43C1E20802ULL, 0x1DEE596B6A192D1AULL, 0x15C9865300AB0DC9ULL, 0xD7ACA80C96AB358AULL, 
            0x6667F195D672D5ACULL, 0xA5E61C40AD237102ULL, 0x1608F4A0896D6685ULL, 0xD7E73921BA5DAE7DULL
        }
    },
    {
        {
            0x7AFBDC6E811967C2ULL, 0x3EFB94B17F101678ULL, 0x8364BC58B3F38859ULL, 0x5923AB15C849C878ULL, 
            0x8CC75D2339B420B1ULL, 0x6B89E2D722131D1DULL, 0x1626F6FD3ED91CF7ULL, 0xC014C83DFE4A1E16ULL, 
            0x86DD113EE360A998ULL, 0xF903CFEA996360FAULL, 0xBA6071F7D28A9F6FULL, 0xCF67EEA741CB0492ULL, 
            0xA7062759C2FE6011ULL, 0x50437BFDAC3934B5ULL, 0x68AE8ECBF8C566E9ULL, 0x43E30AA54E5BC95FULL, 
            0xC4255693DC536FC3ULL, 0xE648B6536C1907BCULL, 0x1E2B3979C28074DDULL, 0xC8108D0185438C3DULL, 
            0xF9E228236FC222E4ULL, 0x15D4651E30299AE1ULL, 0x0483A8FAEF42116FULL, 0x2F5FC89E3DAFBE02ULL, 
            0x52EABB40BB9E810EULL, 0x16B79D72F9F6AF02ULL, 0xBF5FEDE26645F5E1ULL, 0x2872C853AA22D70BULL, 
            0xD26A5153701DAC45ULL, 0xB2BBA81C506A03D3ULL, 0x5B6DEA779C8AD432ULL, 0xCED271EAD2C43DC0ULL
        },
        {
            0xC673C7844C0EEB0CULL, 0xDA27FBF3F106E602ULL, 0x0C658E80AD3B0E5FULL, 0x3708CFAE9082CAD4ULL, 
            0x5E66277E883AFF04ULL, 0x3FF6083C83E7463CULL, 0x730A390183B4DA15ULL, 0xFC3635292795B93AULL, 
            0x91B238B009CCF028ULL, 0x7DC57616F1A927ECULL, 0xDF81B8C2914094F5ULL, 0xD4655C26803527D2ULL, 
            0x8A256150BB90BFBDULL, 0x4F4B3ABFF431FC8BULL, 0x906DBE6D485459E7ULL, 0x2E9BE5315D4B5138ULL, 
            0x3D6BE29862DC151CULL, 0x24CC1D78B6DECA86ULL, 0xE8C7D11484AD44CCULL, 0xE10BB61013356705ULL, 
            0x434DA781DCB920AAULL, 0x7B726B2096C8E6BBULL, 0x9522887332A03B37ULL, 0xF926163CBE9CA5D2ULL, 
            0x55EF08CCC082690DULL, 0xA56CB7547033B1ADULL, 0xF5BA12D3E4B9AE1BULL, 0xFC428DD4E66DDFD8ULL, 
            0xD482DF1D20E5A391ULL, 0xD0FB2A6B58C7489CULL, 0x0F4776D9B5CA0776ULL, 0x60E20669AD9DD07FULL
        },
        {
            0xAF258D4241626966ULL, 0x5A91A78877E5B5F8ULL, 0x822D6E708A72423BULL, 0xEEEFD6640F5921A0ULL, 
            0xF0970E9F14581CB6ULL, 0xE2A228729D78A050ULL, 0xC96584ACA227808EULL, 0xC77A5447C9E423D0ULL, 
            0x9B6773D9F512E13CULL, 0x78D47432BD63E461ULL, 0xC97B6EBA9F297CC7ULL, 0x1F7646FE3858987BULL, 
            0x6D229ED03A362095ULL, 0x6B341091F7B7C5B0ULL, 0x413BA2D3C921B3B8ULL, 0xEC5B3D46EDEE1BD6ULL, 
            0x93D297FD7292A441ULL, 0xAB03BA857E9308B7ULL, 0xAA8B96D4B4EF4F76ULL, 0xDE62B8D265F5A1F4ULL, 
            0x23B52F27FF6E2531ULL, 0xF3653AE200CAEAA4ULL, 0xC31A4F6984AA8AE5ULL, 0x4BF989D539991CC2ULL, 
            0xCB134CA90EB0E69EULL, 0x5EE0146F5D2D4B6AULL, 0xD61F0F7363828565ULL, 0xB33B36B705725027ULL, 
            0x584DBFCDCF29E064ULL, 0x9558BE96C3004C29ULL, 0xE176D74E50E69F1DULL, 0xF0CEB6F97881EFCFULL
        },
        {
            0x49B966C2AF25FF27ULL, 0x11AF9A31BCC316A3ULL, 0x8A8CC4F0378DDF9EULL, 0xD61EA0154ADA4FCEULL, 
            0x8BEDCD94304D4B9CULL, 0x6075427100F3FFEEULL, 0x417E3B67E66EBF10ULL, 0x4340143AF72FC67FULL, 
            0x614C0140AE298291ULL, 0x50E34FC78F0DEB8CULL, 0x398B921BC3D9FA98ULL, 0x73187C13ED8C9EE6ULL, 
            0xB9E2FA8FFEEE4540ULL, 0x2B19DCE7649D49DEULL, 0x19F77431FE18F08EULL, 0x7E7DE31B13130B5DULL, 
            0x7A8EBE6F8805E67FULL, 0x9D0F33146743AD60ULL, 0x979A56BF89D60BFAULL, 0x7BD58AFA4B8AD5FCULL, 
            0x7299DB81F209A9B1ULL, 0x9298847FD098A22FULL, 0x075F666625C77ECBULL, 0xD38E968C05B311BAULL, 
            0x63D54A2DE80CA063ULL, 0xBD0D4B22AC094BB6ULL, 0x0C74F5B1EBBEB1F1ULL, 0x2E4B54E95871777FULL, 
            0xCCE5215A93CFF4ECULL, 0xDD7C879864BD2B4EULL, 0x47CAC6904A27DD6CULL, 0xAB85F1D67346FA84ULL
        },
        {
            0x29C4FC1D5594ECD5ULL, 0x8D1C3F6FB7B44D73ULL, 0x4FFA345DE7C13AFEULL, 0xF93B5D426D471F41ULL, 
            0xF8017A0ADAEC1EDBULL, 0x4D8E8A47840EB485ULL, 0x0361AB2349C40F3AULL, 0xBE8F1D34F7539E79ULL, 
            0x4F4F8EEE75CA6661ULL, 0xBEBF9E7955753581ULL, 0xC2F8F9C219307833ULL, 0xA72D90114C822BCEULL, 
            0x92DF0F9A5D98300AULL, 0x8A38E2AD340E99C5ULL, 0x568D078761D0E63EULL, 0x92D97ECA8B1317E6ULL, 
            0xBC789EA9FBAA4C89ULL, 0xD7092906EE9972CCULL, 0x3D2652DE0DB540E8ULL, 0x7BDFC5CB7A1E8B76ULL, 
            0x1C7773A44A9BD9DEULL, 0xD5CA4C8C4E3C549FULL, 0xC45171AC5BB610D3ULL, 0x6632E28CDBC93460ULL, 
            0x05697F90BA3471AEULL, 0x062BD76CBFA256B7ULL, 0xA91243ED641D2731ULL, 0xB1AECE11C1F5CAE4ULL, 
            0x9E35FE49048AFEFCULL, 0x46365120315025CAULL, 0xC83CB4BEFB836097ULL, 0x3184F6377BC3B960ULL
        },
        {
            0xF711B56DD433E591ULL, 0x9639E5196A4D828CULL, 0xA1DE148897201864ULL, 0x38E4BBF88F1B513EULL, 
            0xEA19FE237FEBFDD6ULL, 0xE2AFFA9FE6973892ULL, 0x910D9D12B8432FAEULL, 0x2EFD07422C2E31E6ULL, 
            0xDF347236D3E9AEA7ULL, 0x20DDC4558CFBE674ULL, 0x01ECADF227B1B228ULL, 0x365B3B75FF391EE5ULL, 
            0xCD890B6D8AAEA127ULL, 0x7BED735683A6900AULL, 0x268ADBD1E3493A90ULL, 0xB7038BB71FEF1938ULL, 
            0x0814C9911A9ADAE9ULL, 0x49B8B2E397408C15ULL, 0xFC33C76D1A998289ULL, 0xD34E371F935C62A0ULL, 
            0xB6309B6D3C42F6C8ULL, 0x92B6ABE66FA9ADFFULL, 0xD90B7D0E0133BCACULL, 0x331E9E4B01917F2FULL, 
            0xF2B4104272C90E7BULL, 0xE5C00F6CB0406CA5ULL, 0xAD69EDD92EE38769ULL, 0x7AEEBAB25283A6DBULL, 
            0x7DAF85CEAC5F3B0AULL, 0x372EEE48864D7ED4ULL, 0x6AA3C19C5C6587C0ULL, 0xADBC690DBCF4C339ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseBConstants = {
    0x0E4D769974C83571ULL,
    0xF7E401921E24A074ULL,
    0x8866D31A1C75F749ULL,
    0x0E4D769974C83571ULL,
    0xF7E401921E24A074ULL,
    0x8866D31A1C75F749ULL,
    0xB486722A86E6FA9FULL,
    0x94B809C8BDD270E7ULL,
    0x45,
    0xB5,
    0x42,
    0xC3,
    0xD7,
    0xD2,
    0xB8,
    0x0D
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseCSalts = {
    {
        {
            0xE4BFB0EC351BE1A4ULL, 0x8E6EA04AFDBFFB43ULL, 0xBE0B588A67206A6EULL, 0x5854ECD842FE4F55ULL, 
            0x3EE1E83974F77A6BULL, 0x38B92A0684C4DDADULL, 0xE1FB5243961E96BDULL, 0x0835A0FE2F040931ULL, 
            0x2F8FADC9CCC07D9EULL, 0x30DE98FD9ED3EC6BULL, 0xBBE640B935AB34DDULL, 0x5B70EBF8D1F8F257ULL, 
            0x582B3532D5E627FBULL, 0x59FC821F9CAD5B21ULL, 0xA996B26616C04325ULL, 0x1E876E4DCFAF4C10ULL, 
            0x4A184EEF3D45EDF1ULL, 0x3F1A38C41DC3C41AULL, 0x301857188C313421ULL, 0x627773688BDE2591ULL, 
            0x026D4B4BA44B37BAULL, 0xC0791BF19A9D42D3ULL, 0x35B464A05B70BE91ULL, 0xF38F3D3116D582CCULL, 
            0xD1B1A58BB64391B6ULL, 0xBD114B2EF12A943DULL, 0x08C612E9A6B587A2ULL, 0x33E0C843BA127318ULL, 
            0x0A0CEBCAB943AC45ULL, 0x66AA3ADBABA7224CULL, 0x223B126BF88A723AULL, 0x23088E925DE96E78ULL
        },
        {
            0xC9320228D044FE90ULL, 0xAE03FEEF171BF0E5ULL, 0x2A2EE773D140C77FULL, 0x43C6D19D4F4A0DD6ULL, 
            0x2E63FBE63698BE45ULL, 0xDB04F96EED0C10A4ULL, 0x0A9E4A677379AE43ULL, 0x3642DF3147551DFBULL, 
            0x2C6B321FADBF24C9ULL, 0xBB87D9CDC801CE56ULL, 0x7DB6AC905DD9C0B2ULL, 0x87D8C150A35D50E8ULL, 
            0x1E2FBF62E4DFE4F4ULL, 0x6C03E763089347DCULL, 0xC2CDEC7D01A815FEULL, 0xD9EE03FA2CB6AF66ULL, 
            0x8E1609208B023222ULL, 0xB749E1236F873702ULL, 0x6ADE201097FFD036ULL, 0x236D2DF12111714EULL, 
            0x5CD99586044C77C9ULL, 0xA084C374F023DA5EULL, 0x95078D827B82347CULL, 0xA79E99ADFC9C5FBDULL, 
            0x687840C0000F599CULL, 0x41304FA084B365B2ULL, 0x65CED82D7F56B7E5ULL, 0xF239E9E79DE0CC2FULL, 
            0xF55AC69E38DA086FULL, 0x751DD82B34AD561DULL, 0x94A0AAEB6B630553ULL, 0x7D209D7C27A1264DULL
        },
        {
            0x6B8F9987B0A53FD0ULL, 0x32FCF1233F5C1632ULL, 0x6DEE479AD78B3D73ULL, 0xBA6159E64B74FD6BULL, 
            0xBA75638E6BD375DCULL, 0x8E7D3D4C2613570AULL, 0xBC8D6C7BDF14673BULL, 0x5AE53E3E4F8E5945ULL, 
            0x8AA812426AC03B59ULL, 0x26CAC2173EED4168ULL, 0x7A501508EBE3305DULL, 0xC3A05FAAF08954FFULL, 
            0x4C3CB9329D4873B4ULL, 0x518ED30A9D62DDB7ULL, 0x4F7D7BCBC0C2E63EULL, 0x00A55BEACBF1F05CULL, 
            0x03EF1DE7EDE79AE4ULL, 0xCF0CEDB5517763D4ULL, 0x3E09D4388BEC1343ULL, 0xFAA5E9F9C3B6EB0EULL, 
            0x7A242BAFE6013C31ULL, 0xD9E8106EB9805CE6ULL, 0x6B015C12891061AFULL, 0x1487F4F99B8751D8ULL, 
            0xD9C179666C89957EULL, 0x912AD0C41A9147E0ULL, 0x626BED9DFF2D7B68ULL, 0x19BCA90E9C3DA3E5ULL, 
            0xCAC4D5153A9760CAULL, 0x507FDCE7D9479579ULL, 0x36C1CCCC691AC1F8ULL, 0xC50998FB19E51AE3ULL
        },
        {
            0x67538E9FD04D8D72ULL, 0xA8AE6D8223455D36ULL, 0x53A888AFB4DE6AF6ULL, 0x2B4EDA8F5734A1A3ULL, 
            0x471BD59EFBB1830EULL, 0x7950FC58EE2EDC9BULL, 0xFBD584FDBDB36190ULL, 0x44FDA72938799D20ULL, 
            0xCADEA0D82BB57F2FULL, 0x75648BE02844555DULL, 0x67F29EEF52238AE4ULL, 0x1E528FDA49FF1FFEULL, 
            0xB30AC1BF2030B772ULL, 0x9076A3D9D00E2D9BULL, 0xA103F193B4C90F14ULL, 0x1E614DE4E53DC8ECULL, 
            0x7135B78FC521DBC5ULL, 0xBAACB3692FB275CCULL, 0x9368227A684625A2ULL, 0x4ED937392430918BULL, 
            0x784069063964597AULL, 0x78B72F94732844F2ULL, 0x73AED0134ED5EA12ULL, 0x5C96BE263AB3D2A0ULL, 
            0x2F3459BFDD372CD2ULL, 0x9F16C692E35F13FFULL, 0x84C1D51C0212A3E8ULL, 0xF4DD0AF119720490ULL, 
            0xDADCADE5ACA62E57ULL, 0xDA6A4B54154AC68BULL, 0x9C3E2C3271AC7A26ULL, 0x74FC70629A47E52DULL
        },
        {
            0x877BC9F36E8AA6E5ULL, 0xF439CBDF6C9CEBFDULL, 0x404FCED52509B5C9ULL, 0x5E9688AD76737724ULL, 
            0x0A5E48814BA23010ULL, 0x8D19E189128D0DB7ULL, 0x1E87F409C8393AC4ULL, 0x86B7FF15CED4E8EEULL, 
            0x1B0CD43B39908F96ULL, 0xE7BB269827426A04ULL, 0xBCB84E22F260DDB2ULL, 0x9BBEB91033674199ULL, 
            0xFFE7C0984C2D64DBULL, 0xE705DB11C6893A8BULL, 0xFF31A56C56D15992ULL, 0x4E46C487C3394460ULL, 
            0x54C3156FB4227B49ULL, 0x67955BB2E28F35CEULL, 0x271C76B27A789A0DULL, 0x7393A7ACCF420E8EULL, 
            0xB3384DA14834DAE2ULL, 0x2B77C1A015E12492ULL, 0x4E9151EF9EAB7846ULL, 0x96224FB337225A42ULL, 
            0x08061F55E69B09D0ULL, 0xFA212F6B6B349586ULL, 0x858E8EFCA2505BB9ULL, 0x8D1DEB58C75B53DCULL, 
            0xC9B71597F9E1D3AFULL, 0x68FCE3526AEC274FULL, 0x28073EA9F3871F42ULL, 0x36465D736429CD2AULL
        },
        {
            0xE8E38A30BE972EB8ULL, 0x6ABE776A5ACD4FD0ULL, 0x4A9F19767028CCA9ULL, 0x9CD2616905F7C5F5ULL, 
            0xE11BF4DA0ED71743ULL, 0x7044E6B4AB580728ULL, 0xC673A9126A2BC947ULL, 0x3A70141589E025BAULL, 
            0xDC6671D4DFF7AB44ULL, 0xB05D90F7F975F5BEULL, 0x845DB5B5DD67812BULL, 0x52FFB8E6E816A88CULL, 
            0x26A9CE26EB39009FULL, 0xD483E713B96D0F99ULL, 0xDF8D568258C60D02ULL, 0xE4AB4DE0467F6CF9ULL, 
            0x5AF24391DBD6A906ULL, 0x3E915BE947E2FD32ULL, 0x17C4BE47B1ADA5D2ULL, 0x002D970A09D69E55ULL, 
            0x8528B4427B799D63ULL, 0x427E6F02F9B3955FULL, 0x11B1402DF22AC82BULL, 0x39AD4CEAB57578E2ULL, 
            0x3E1F3495690004A8ULL, 0x7B2E02D1B255191AULL, 0x0EE952F5A385EDA1ULL, 0x3172E6C4EC1110CDULL, 
            0xCB51AD683F2D2062ULL, 0xEEA015B711916158ULL, 0x672335D9AA600160ULL, 0xFDF3E3655907932EULL
        }
    },
    {
        {
            0xBB9E0055479F9C72ULL, 0xEA0ADA2D248FA6BCULL, 0x3531947E35EA02EEULL, 0x6CFE2D1933D27364ULL, 
            0x6607A771014EBEE6ULL, 0x93EB69B6B65C47E9ULL, 0xD710F1F38F1863B0ULL, 0xF5AAB38A8E962EA3ULL, 
            0x8448A5E7F0DAA191ULL, 0xCCD73581722E3BE2ULL, 0x4BE3F432B1620102ULL, 0xCEE4E17BCF0F0BBAULL, 
            0xBBA139070E6732AFULL, 0x850E9AA3F898EB3BULL, 0xD2C03D65419085E5ULL, 0x3F2C5BC65B0E816EULL, 
            0x5B3A517CEB7BF6FEULL, 0x71DAFCAF89DF8FAEULL, 0x54EC038A50167475ULL, 0xF832EC251DD1DDFCULL, 
            0xC16E3237D6E91FEEULL, 0x7425BB7850818E27ULL, 0xC8CBB78B03D6ABA6ULL, 0x96CF37CC1B1056B3ULL, 
            0x48C4F5FEB6CC333FULL, 0x3D99C426797618F6ULL, 0x58FCDF7DA676972DULL, 0x0C2BE4C9E605E074ULL, 
            0x6F1D6C70E99E5DF8ULL, 0xA656A32256F3665DULL, 0x868DDC0DBAC2E30AULL, 0x27083DD07E3CC8F5ULL
        },
        {
            0xD12CBE97A66F03FAULL, 0x72908D1325B8A8D9ULL, 0xBD99FBFC728C3C3DULL, 0xFB029DB4E70A9DB9ULL, 
            0x1BF33986401AFC9AULL, 0x8624E40640C0943EULL, 0x4C1F942C7118578EULL, 0x84A196A00DA0ABC4ULL, 
            0x4AFA4785F54DD81DULL, 0x9FFBDFAF4488AF40ULL, 0xFFA27FF1025A0C1BULL, 0xBAD3DC6044AB3542ULL, 
            0x8F8EE581AF72AA5BULL, 0xF77A424BB44FC79FULL, 0xB01B1A607CF1CD66ULL, 0xB4C291B283AD845AULL, 
            0x877E7650ED353EC1ULL, 0x775365D4F99629F8ULL, 0x2592FD86FE5DEABAULL, 0x5D8F62C6B7DA9953ULL, 
            0x76F7D1D674DF812DULL, 0xADA6E3805CA9A053ULL, 0xCE95E274E02083DEULL, 0x7D47206206D3ABD2ULL, 
            0x26746A22437D5A15ULL, 0x353F56EC440AEE59ULL, 0xF17BB09E05A506D4ULL, 0x4BEA6FD5AF5FAB06ULL, 
            0x6805D52844B84A35ULL, 0xF17D04FA4133EEA4ULL, 0xB57E684B487CBCD9ULL, 0x13A33DADD70A89E8ULL
        },
        {
            0x696E8FCBE0CAA09EULL, 0x4C866EF3F7DE7D61ULL, 0x89DC65033248631BULL, 0x5F39D0F4AAC80210ULL, 
            0x960E38FA4A47F1BFULL, 0x20E661D24271CCCAULL, 0x40ECC11E8DB4807DULL, 0x83D303E0A8E20F7FULL, 
            0xE462FE69DB27175CULL, 0x7069CABAAA723565ULL, 0xD6AE6A78851A75E4ULL, 0xE443FC4E85D09D7EULL, 
            0x84DFDD35DC1B42CDULL, 0xE33189512EE95D9CULL, 0x085D2CC1D031D67AULL, 0x338A884DD8790302ULL, 
            0x3242DF7E4D1975DBULL, 0x0A21A641779146C5ULL, 0x3BFEF63AD953755BULL, 0xBEEAF5E48A31256EULL, 
            0x1E806584770DB685ULL, 0x1C73FB07E46B50DFULL, 0xA063361AF66F719CULL, 0x073C7935068678F3ULL, 
            0xE5B92AEEA0602A56ULL, 0xCE3CAB49B459323DULL, 0xE847C842C701CA4AULL, 0xBB5C914E7393ECEEULL, 
            0xF7C85E90822D2A89ULL, 0x4E04F412A6C5EC6DULL, 0xFA1B84CCBA0DA7BCULL, 0x0A4896FA92C8FE85ULL
        },
        {
            0xA533610926D04352ULL, 0xEB8107FFF2EC3F18ULL, 0xA0F8069A7FA7051FULL, 0xD341C0412B93B89CULL, 
            0xA06E0918382410B4ULL, 0x6D239F287FE777BAULL, 0xFAC2A5439ACF61A3ULL, 0xC1EE794F65F63AA7ULL, 
            0xD5992C86C77E3B15ULL, 0x6FE2F9CCDAD58CB9ULL, 0x07AA37C7BBF408E9ULL, 0xB91175A180EFFEB0ULL, 
            0xEA29944D72F04B84ULL, 0x4528176F5FA92B74ULL, 0xBB0400D283913D6DULL, 0x43FA67C179596425ULL, 
            0x1DDE314683B71F30ULL, 0xC3CAF13DF9B9E3E5ULL, 0x156F9A8229F84A98ULL, 0x1B748FB4F5D202EEULL, 
            0x793039F9CD12C60EULL, 0x265064C480D54FA5ULL, 0x3802C291D484CC9DULL, 0x370EF4C3E642FD5EULL, 
            0xB71592294C1F7240ULL, 0xDECDC61AD8379C99ULL, 0x5E5782C7676F3514ULL, 0x04E39928C98CD0EAULL, 
            0xD28F188D1DAE41F2ULL, 0x45C51D5C910903B6ULL, 0x1E2D11C360344CCFULL, 0x62588094B44DF94AULL
        },
        {
            0x01396B0734A6DFC1ULL, 0x0F81F3542BECAF65ULL, 0x5F38FD23D20DBC36ULL, 0xE75E323B0258F9B0ULL, 
            0xA8AE77374FCBFBF4ULL, 0x1CA3933F1669699BULL, 0x6BF0DDFD4693E9B3ULL, 0x006C33E33895593DULL, 
            0x8E6BD7EC218374A1ULL, 0xDAFCD0D6F1D2385EULL, 0xDB604FCDB11722EAULL, 0x36A305ECB22C879EULL, 
            0x7139F11BEB989584ULL, 0x943F56B306A9B0A9ULL, 0x02ED9C1AA84AF54BULL, 0xDF45CE7F4B1A30F5ULL, 
            0xC902279D6F9F3036ULL, 0x4E0D2CA8EDE688E5ULL, 0x2A872643B5C82ABEULL, 0xB204DF028AFDA6B2ULL, 
            0x121AD8D76400EA33ULL, 0xA6EA6A4F8DBCAAAAULL, 0x4A333F8E34A4FE6CULL, 0x00EFF5C01C2E702DULL, 
            0x66AB50CD02AFB050ULL, 0x6FD688AB75DCCF39ULL, 0x3A7192326AB1499FULL, 0xA186334C5447B36EULL, 
            0x9EEB2EEEDC50CBA6ULL, 0xC483D0438A02C59CULL, 0x0E485604DB825468ULL, 0x2EDC9E987018B6FAULL
        },
        {
            0x70978D5EA528E5C9ULL, 0xDD89FC0823408766ULL, 0x6F915ED1819BFBFDULL, 0x522E123416C57FE4ULL, 
            0x72E2DD32272A47BCULL, 0xB0C5C8C5295148B5ULL, 0x4D1A37508F10313DULL, 0x9505B1DDA90A17EDULL, 
            0xDEE5292E04F891E2ULL, 0xC8D9004903A51840ULL, 0x1A63EE3F95E97386ULL, 0x6B5DE00400DC006EULL, 
            0xCCB502F79AAD08B2ULL, 0xBEE7BAC9F83770F5ULL, 0x24B6082D20B85D9CULL, 0x0A04C0BF5C45E475ULL, 
            0xAD9FBD1896378AD4ULL, 0x46A65A4F825370D3ULL, 0x4867DF74313B5767ULL, 0x35C87346786FD48DULL, 
            0xCC4F5AF66B6838EEULL, 0xB1A052679AD6F89CULL, 0xEEECD05C983D59E0ULL, 0x7B1EBF93FE4B1675ULL, 
            0x926A0F8FEFC65F2FULL, 0x404252CBE074A668ULL, 0xADE757C11916FE25ULL, 0xF70D1DA07E25C876ULL, 
            0x6AEF2486479EC6B4ULL, 0xC55E481739BD39FEULL, 0x666B3C9E213AFAF2ULL, 0xC25CC2DF0F8A8F1FULL
        }
    },
    {
        {
            0x4185429BFE096415ULL, 0x0159E52077ABBEBEULL, 0x7F217D06D21D6BF5ULL, 0xA861FC7D16F0CDC2ULL, 
            0x754BE2C9DDF25CB7ULL, 0x5325A33389082FD9ULL, 0x2447154C6BE02D87ULL, 0x3BAD4CDD59EC5AA2ULL, 
            0xE1030EF675DCB0D4ULL, 0xF0DF851FB69A449FULL, 0xB1F47AD51F7711A0ULL, 0x86C7C6B47C9D045BULL, 
            0xF24BA4134152075FULL, 0xDBF09A3592377BD7ULL, 0xD9E874BE1C1B88FCULL, 0xFAD616D47AF46825ULL, 
            0x2EEF5A58640DD05BULL, 0x48F7E9CF01059CE1ULL, 0xB302CEE7E89DFA94ULL, 0xB7AC1F02BBB21F59ULL, 
            0x588F0E7D9FBD1EE6ULL, 0x46D23F6DD3F380D6ULL, 0x16E25756640024FAULL, 0xFA874E349760050FULL, 
            0x3ADDC3A7A8FAC05DULL, 0x941524001D250BE9ULL, 0xD0C6BC09A7CB825AULL, 0x61FA29E68AD67420ULL, 
            0x7CDB25767173442BULL, 0xC36A49B74A96CAB0ULL, 0x0B6C71A7108F0665ULL, 0xAFC8209F91693129ULL
        },
        {
            0x4119568D949CACD9ULL, 0x5634C34AD1BDD516ULL, 0x6535498D22258CD7ULL, 0x23E5A158DFC58BA0ULL, 
            0x65A37FFB305292FBULL, 0x6CE2B8FDE4C0F916ULL, 0xAE3B351D3F77495FULL, 0x1BDF352E8368516BULL, 
            0x62066F5299B8C55BULL, 0x041181756D9115BAULL, 0x26B6B5ADCDCB0143ULL, 0xADEEC527D30B604BULL, 
            0xE2BB8A3373E6E7E2ULL, 0xD072D1854D485465ULL, 0xA1582CF64BD866B9ULL, 0xB6DC939ECA141ED7ULL, 
            0x67D8A1D4E654AF31ULL, 0x1553C0A4894638C1ULL, 0xE18B2E4542D81EADULL, 0x3F6304E370EEA20FULL, 
            0x606D16614774782AULL, 0x0B8EF7A90BF504D4ULL, 0x601DF99830279C1EULL, 0x281E5A3B304AF36BULL, 
            0x53BC0F1A5EA7F204ULL, 0x13DBED8C99BDE02EULL, 0x9A04147FB012757CULL, 0xFF20A9C91ADE24A1ULL, 
            0x43F4E9EA3BDAA8A1ULL, 0xD347ADC0EE7979E3ULL, 0x69CE80F191BB0146ULL, 0x7222BE034DAD7952ULL
        },
        {
            0xACC5BCDBC01596E3ULL, 0x02BB59457DD926C7ULL, 0x89325A9BE63E14D2ULL, 0x05725D31FED63E37ULL, 
            0x4CB551D780B4AF77ULL, 0x8A7F157CB76766F6ULL, 0xFAB6F37684E26DF2ULL, 0xC2575843E9531B4CULL, 
            0xF738354A9EC47703ULL, 0x1317C975C7D49777ULL, 0x3B9156309CD2CB91ULL, 0x1B124BABB7847C25ULL, 
            0x2DD660A7787F5077ULL, 0x3EEA4E8FDA5EE5A2ULL, 0xCC30E988A3F170E4ULL, 0x1E24F4A190E096A7ULL, 
            0x04205488A82E1586ULL, 0x7CE39C61C741693FULL, 0xA107E98BA1844453ULL, 0x6BAB5ABEA3751137ULL, 
            0x64370E318D14D168ULL, 0x6A1BC61ACC0260D1ULL, 0xFB465D188D5BCCC6ULL, 0x3A50470B67390230ULL, 
            0x763153D4C3703528ULL, 0xB0A94D6D4640428FULL, 0x04AC3E744A60E1D8ULL, 0x08A72E4A96185095ULL, 
            0x3BB16703F1BF12E9ULL, 0xDED2EA073624FF03ULL, 0x823A84432175564EULL, 0x8C77F6B2E206F9C6ULL
        },
        {
            0xA1253850526B90DCULL, 0x8C16E5D85D535860ULL, 0x816A84951525EE03ULL, 0x69C62FA1F5DC4C46ULL, 
            0xF53B4E0F9F6D65E7ULL, 0xF80DA60E5AF1463FULL, 0x6498C78E48E4CBD3ULL, 0x9AF1A3733EE0EC81ULL, 
            0x4ECBC97A13067260ULL, 0x37649CCA4F8AF5F3ULL, 0xC99D5E59D1F968FAULL, 0xB463D2FFAC218302ULL, 
            0x9CE3FF7998CE17C2ULL, 0xE44B84A805B3522AULL, 0xB28ADADA7DC1F051ULL, 0x39833C64470841D4ULL, 
            0xE3EB00FE65B4483BULL, 0x2AC9B47C7A0BE6CFULL, 0x1A8EB3588FDD4D3BULL, 0xDCAFD4E8AAB3E459ULL, 
            0x3408E0A5E717BE05ULL, 0x62C5D8635FDEB110ULL, 0xBD78DD6E2BE20894ULL, 0xF8B4C234D5C953B0ULL, 
            0x9FDACF34A39C883FULL, 0x65425C0396420770ULL, 0xC0C6EA3D794CB751ULL, 0x35B0A6F69C86AC98ULL, 
            0xEC2AF093222E0417ULL, 0x8A03C2F11686985CULL, 0xA987DC24BED012BCULL, 0x9BDA1DD074E495F3ULL
        },
        {
            0xE89D00E705B005A1ULL, 0x6FD31BE2DA6C0BDCULL, 0x4F683A35DAB779A5ULL, 0xBF1C97AA3FDC454AULL, 
            0xC7A4A4FC5E70317DULL, 0x4D75F3198770FDBFULL, 0x166183EEEE9419C2ULL, 0x24920F5CC5DF5008ULL, 
            0x1219EEDD22A9337AULL, 0x10563E5DD2B17E07ULL, 0x8F8E5A81AF65B62BULL, 0x1DA0FEF6C47A74CFULL, 
            0x39FF0E31113B4D0BULL, 0x22C9467F867A2680ULL, 0x4471BBD47EE93A40ULL, 0x089C7388A3B7C6CEULL, 
            0x9BFCAF4068619CFCULL, 0x9A4CA896EC87A155ULL, 0x2F77CCDBAF3C63FDULL, 0xA4B3FD55836406E1ULL, 
            0x62542FDA9B3EB45AULL, 0x1B34E8A4E053730CULL, 0x13578F735F53DE3FULL, 0xA78AD58487388518ULL, 
            0xA4AE6ECF4C1E9A7DULL, 0x444570DC542FE691ULL, 0xBD5FDBF5619B5A0EULL, 0x186ED52D7DB6457CULL, 
            0x5948B6A7F154F536ULL, 0x54B6125432F08856ULL, 0xE86A8B31B24D7C2DULL, 0x9EABBA658B984B3EULL
        },
        {
            0xB98D1AC9569511DCULL, 0x5E43BDF4234DCA6CULL, 0xB2056BC762020814ULL, 0x3912983DF499E6DBULL, 
            0xDE7095A3CC50518AULL, 0x262D4D713AA6ADBEULL, 0xED50BA312D1387DDULL, 0x24EF703CA986F9AFULL, 
            0xFA3639003C50C557ULL, 0xFFD59E702886F8BAULL, 0xF3CFF9C98DF5DFD5ULL, 0x38062CE8D0A615A8ULL, 
            0xED01CFCE164A8BF2ULL, 0x70D27E3437E5E519ULL, 0x9685393036FAC57FULL, 0xEF471B3F13618EAFULL, 
            0x2663B6349C661D95ULL, 0x8B08F55A38751FC0ULL, 0xF9FDC2A25AEE2DF7ULL, 0xB8D5CB9042BCF9A8ULL, 
            0x9A5F14783FC502F2ULL, 0xC74BD480E98F5DECULL, 0x775EB3C298228987ULL, 0x89DBFF39746C5913ULL, 
            0x8EEDB9976834A5E3ULL, 0x990BD2FC60A6CCD3ULL, 0x1277198A430D2D95ULL, 0xF134E2C483C3FC5DULL, 
            0xAF8679CD2952E1F7ULL, 0xB94AC86B60E05C81ULL, 0xCA44856BB1230349ULL, 0x0789E2DDDAB3CD78ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseCConstants = {
    0x53A46E2484119C8BULL,
    0xF690A97307212CB3ULL,
    0x3298F9E7DB7CAD5EULL,
    0x53A46E2484119C8BULL,
    0xF690A97307212CB3ULL,
    0x3298F9E7DB7CAD5EULL,
    0x259F3EC1918E27C0ULL,
    0xBB2557624A715411ULL,
    0x67,
    0x71,
    0xEC,
    0x73,
    0x38,
    0xAE,
    0xE6,
    0xA2
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseDSalts = {
    {
        {
            0xF99CD619D9841FADULL, 0x0C955CCFD2278675ULL, 0x99B51E15F13AEB57ULL, 0x9C83A28B5EA6ED4BULL, 
            0xA81AEFC3FFAB3A08ULL, 0x53079A4598E134A2ULL, 0x2FCF674A728F6D6AULL, 0xE4F613B26344B1B6ULL, 
            0xBB2814F9ED2ADE07ULL, 0xE43BCC8D58AE9CDEULL, 0x42CF01E1B93C4248ULL, 0xC27CF3B6D4B6E62EULL, 
            0x5BB5B73AB8D7BB26ULL, 0x1458BA174D65BCCAULL, 0xBB29FE9D7A68C221ULL, 0xC8DB6DDB753C2FCDULL, 
            0x25774DF9AE4A8342ULL, 0x3F14F796E8B549E6ULL, 0xB546C310D0B15937ULL, 0x002598FB93F58914ULL, 
            0xCAB1B1B0539245D4ULL, 0xA31033DD8EA8CD95ULL, 0xBCCFB4238EFF4222ULL, 0xEABA8DF777E38791ULL, 
            0xD1F53020809CA808ULL, 0x2BCEDDFDD8AF5CCCULL, 0xD40B0FB883CA2818ULL, 0x697988898BBF2546ULL, 
            0x6F533CEAD258B5D2ULL, 0xCF8D31063BAE9C3EULL, 0x0496C9D979EA025AULL, 0xD38B67C84500CD21ULL
        },
        {
            0x23099828522560D5ULL, 0xEDE846C4AF338781ULL, 0x83DF43B991354595ULL, 0x300CF39C2686D971ULL, 
            0xF320E73952365D06ULL, 0x30C28284D6A3C71AULL, 0x0D8F0D7BB7AA4C41ULL, 0x27B58A900852DFE4ULL, 
            0x070E456057FC8AB7ULL, 0x2993FB92FAE3E333ULL, 0xB1BCA83E0AAAAD28ULL, 0xEB4DA20A955398CBULL, 
            0xB9DDB2B8182F13BFULL, 0x5791747309022713ULL, 0x2BFBD8DD437A3FDAULL, 0x5E093A4EECBF1459ULL, 
            0xAF8ED50704B065C7ULL, 0x781EC51D21A38DC4ULL, 0x964268E4D1EA4324ULL, 0xD3F0CCD4B13926C1ULL, 
            0x622A4C17CBECC123ULL, 0x5B4851C186A73D51ULL, 0xEB6486AF19A8056BULL, 0x72402FA022A3F29BULL, 
            0xE0B7D4C10C8EB471ULL, 0x5EA8E2096C9C3376ULL, 0x1C4BCE6882EEF36DULL, 0x2D5A18B803F127D5ULL, 
            0xA995EC2357F883F1ULL, 0xE7C24E9D5E3004FAULL, 0x5BE5803BB0FCE577ULL, 0xF7FA157A37B51695ULL
        },
        {
            0x429BF8999DCBE298ULL, 0xC58097C090B52DDEULL, 0x7490F8D3FBE06F4CULL, 0xEEDC977B6994630FULL, 
            0x8A4ED3494D6E5CFFULL, 0x079B83F4FD10E9DDULL, 0x316CE19C05874365ULL, 0xCDA8B34110AF27B4ULL, 
            0x188D1ADE644C172CULL, 0xE70734D6E787A86DULL, 0x7E4CBE0AF45B6556ULL, 0xD3AA93B58E0CCC98ULL, 
            0xF061E8B5FE7F3906ULL, 0xE1436F62618772B0ULL, 0xE8A26EB947991939ULL, 0x1E22802089F02C5EULL, 
            0x7C47779BAE512B92ULL, 0x7336406254B67D4DULL, 0x4F81106C5956D26DULL, 0x806C1971E8FAABD4ULL, 
            0x4BFCF71068A20AB1ULL, 0x8039A68DA5E6342EULL, 0xCC27072E095E8A95ULL, 0x1EC6D4C02614F519ULL, 
            0xA19D5FA1C0AD9856ULL, 0x638E25427F1A7781ULL, 0xA218B189D7D37463ULL, 0x6C877FB5D1C4213AULL, 
            0x8E28F8F7076EEB79ULL, 0xD10220188C08C67EULL, 0x1527883D8E652ED2ULL, 0xF9073E3D71991875ULL
        },
        {
            0x289042CAD7E7519FULL, 0xEFF6929ADD93D53FULL, 0x5DFEE24B5B9E41AFULL, 0x186AC59BB464443CULL, 
            0xC48B021D16014B22ULL, 0x39978BA58AAA1589ULL, 0xFA13540FA73F4321ULL, 0xE2646E26CEB3C38EULL, 
            0xAEAEFB666EE610A0ULL, 0x235EE33161631454ULL, 0x8F668B8F019B6F33ULL, 0x4342450494A972B9ULL, 
            0xE17AE54F1A8B1E46ULL, 0xF4304500EA4F030BULL, 0x500B53CC8718921CULL, 0x3CBAD20C9B25F54EULL, 
            0x4E9EF00C1AC6F9A8ULL, 0x370FCCC88515F1E2ULL, 0xB0848246FB2F7A8DULL, 0xB958BAE7E93C4EB9ULL, 
            0x847E3CB7B39D9600ULL, 0x31C0B58B355AA792ULL, 0x7BE0409856D1CDDDULL, 0xBD1465B4026E0150ULL, 
            0x36D9669E88EA7850ULL, 0x598BB464824F79FDULL, 0xDA0433B9F9C12B8EULL, 0x6EB1F196B0A8A335ULL, 
            0x59E0C0B8C9BD26D2ULL, 0x2D65E7F7AC571D87ULL, 0x80576A01FB41742DULL, 0x4583231588B40471ULL
        },
        {
            0x62E92E36D1AA52ECULL, 0xBD1228A1F130008CULL, 0x111601D3F0DBE079ULL, 0xDF48BAF4BB2AC38DULL, 
            0x9871125A226A078CULL, 0xFE51F257D86C1AE0ULL, 0xC2C5F73F00A77BB6ULL, 0xC2C1833207693C5CULL, 
            0x6C68E0D6CDF90E7BULL, 0x30B3A4A06B77CBF3ULL, 0x5F1FEB98669F5669ULL, 0x8F2C5D6D94CE4196ULL, 
            0x8603C0350DA04E7EULL, 0x605A1D2CE7A253A7ULL, 0x4567685969B859B9ULL, 0xCCB1B188A36C79F7ULL, 
            0x391624951DABDE73ULL, 0x9D2107AF382ED97EULL, 0x6FB180778E45251BULL, 0xB5676D99ADB35A6AULL, 
            0x1FDC1C9BC7564F0DULL, 0x08055783E96CB632ULL, 0x4F52D0ADA0CD664EULL, 0xBE812E9EDDB3899AULL, 
            0xCD651DE545F7AF9AULL, 0x86FA32D195DF9A8EULL, 0x342E2C981D87BABEULL, 0xFA41FD8493BB2BA4ULL, 
            0x3CC1D4E094A01FC8ULL, 0x151A4EE2C9E7267CULL, 0xF135E5E0504475B3ULL, 0x2967ACDC3F01ED31ULL
        },
        {
            0xC6D9678C1106E198ULL, 0xF70388EE8612ED5DULL, 0x4BD10FCEBB36DB4DULL, 0x32E0882FA9689616ULL, 
            0xCD8722FCE6C1A5B4ULL, 0xB38976167DCB1C05ULL, 0xADC403EBDE7F7448ULL, 0xEE025360D41EB3C2ULL, 
            0x529B71499D7070DFULL, 0x6D0F37550CCEDF5DULL, 0xE477E398FE5E6B29ULL, 0x3CAF91AF58EE1AFDULL, 
            0x03AD8C4EF17F04D2ULL, 0x4E2C6D74333303EBULL, 0xF9E429A6144C4AC8ULL, 0xCF93255D1CE4437CULL, 
            0xB2AB92511B746692ULL, 0x91C9299921CDAFDFULL, 0x3444ED7A79CFD428ULL, 0x0829B5EE308E7F9DULL, 
            0xB955330E363ACF8DULL, 0xC74AC4F8828964EBULL, 0x06EEBF6B1AE55B77ULL, 0xC4AC10E3F918E8C4ULL, 
            0x64802E4052A95DBFULL, 0x88340B7AB96D4D5BULL, 0xD45FBF1BFCB16B60ULL, 0xB6627AE6D2B1E228ULL, 
            0x180C6CBA3E1D0313ULL, 0x8B8639C56EB72E05ULL, 0x72B11931FD0F90C6ULL, 0xBB4674FD09790464ULL
        }
    },
    {
        {
            0xA225B72803922B66ULL, 0xCC36E9BD9E3B8767ULL, 0x6E3BDE8BCFDCD988ULL, 0x1FE89D846066AA48ULL, 
            0x59FF01168400E361ULL, 0xA67D3E0A327B1C8DULL, 0x953F8F63AAD6B969ULL, 0xEA29431E3BD5BD45ULL, 
            0xE720CBAC57502C92ULL, 0xC4756BDEA162D55CULL, 0x33E02ECD99AF05CBULL, 0xD5FA78EC6A943BFEULL, 
            0xF12308219509B93BULL, 0x1CBCD62423BD1B49ULL, 0x6CDA96F3B7562235ULL, 0x73EC13B8DC6476D3ULL, 
            0xCB4AB0504134BE81ULL, 0x47EDEEA399502CADULL, 0x83A5803E7344E3CAULL, 0xC4A616538C86C77BULL, 
            0xEBA513D8AFB76FE4ULL, 0x361CC2A3C0CE1FCCULL, 0x4AE426B62F6BAD6BULL, 0xE241954B3DE8D1B1ULL, 
            0xCA1F3B8E12CDFB80ULL, 0x20357D309C059C82ULL, 0xA849CABC6EB0F62EULL, 0xE54F395EF92F1411ULL, 
            0xDCE7ABEEEC92EFC8ULL, 0xBAF4F739D750A7C0ULL, 0x65407017861A91D6ULL, 0x3395EED9D148B248ULL
        },
        {
            0x9048AB61DED12D29ULL, 0x1237DAEFF34BA545ULL, 0x5D77A4CBAF5C9E47ULL, 0x3ABDB2ADB2599EE2ULL, 
            0x64DB43E9071337A5ULL, 0x10CB1726C7D8951DULL, 0x8CD986A46C1980A1ULL, 0xC2C75F223060469AULL, 
            0xE15AE048D8232797ULL, 0x45C434060AD80197ULL, 0x5D62ECE40319A75AULL, 0x543D952FD02FB139ULL, 
            0x51499910CAE22284ULL, 0x96E7A8BCAED36ABBULL, 0xB6FD46F85DA61908ULL, 0x047CDF059D9799EAULL, 
            0xF0DEEB4463F1669DULL, 0xFB32B600AE6C5A1AULL, 0x0C09BC823F66E6D1ULL, 0x8C55D27094D24230ULL, 
            0x1E61DBB778B44E4EULL, 0x9FDBF2CD9C180E35ULL, 0x1AC50388F08B106BULL, 0xBDB6F386C88E194DULL, 
            0x04EFEF3657888FC8ULL, 0x94B7BE7D1058DA4EULL, 0xC430B80545F022FEULL, 0xE92E883505C2D55AULL, 
            0x50FD8701E98EFC02ULL, 0xE4343DB864763FEEULL, 0x35694483B0F90E71ULL, 0x6523BB57F20331B5ULL
        },
        {
            0x297B4B6846C6F27FULL, 0x2D149A54AFDB96C4ULL, 0x0F112744A0DBA4E0ULL, 0x478494906A854F61ULL, 
            0xA20E0403ADEE79C1ULL, 0xF869E39BC91F4B40ULL, 0x9167C41DBD0F5158ULL, 0x7CF3158A15D41576ULL, 
            0xDA1B64E0E5E5BEB2ULL, 0xDB37B059A476978AULL, 0x0A3786205DB79BDEULL, 0xF7D09B6901D7D4BEULL, 
            0xAAF3602B249E0F7AULL, 0x7386EDB2E072E061ULL, 0xC26D89B76AF0C5F6ULL, 0xFCFFA753A971BD3EULL, 
            0x3AE5BAC2F11BCC51ULL, 0x6A1083B38DB95177ULL, 0xCCB169500A442FC6ULL, 0x6DA872C862735587ULL, 
            0x0226EFF288135379ULL, 0x329B197D68C96D4CULL, 0x6DC0F3433C2DA022ULL, 0x2A717F21025A85BBULL, 
            0xAE0F1FB8417C5FD2ULL, 0x770E6059EDC3C06AULL, 0xB5FC26620964471AULL, 0x9A7E53880F610F77ULL, 
            0x83398AC1CD9E249AULL, 0x44CEE1265F387BCBULL, 0xBF9F06D32139B094ULL, 0x23309A6ABFD290F0ULL
        },
        {
            0xD85551A811BAD766ULL, 0x1573DA8F560BC948ULL, 0x82DC67EE0A5238B2ULL, 0xFE81C1E11A46EAF1ULL, 
            0x09820CA4ADAC04A1ULL, 0xBAF54940831B2EBAULL, 0x145CA5F36DAF3298ULL, 0x4DBF831AE5F8E03BULL, 
            0x40D6AE7895323D21ULL, 0xAD2249851334AE45ULL, 0x805D5577698D38BAULL, 0x19533C42728A34DDULL, 
            0xABD9EFC595747305ULL, 0xB2D13BB0DE880D4CULL, 0xA320DE00AB2B6332ULL, 0x102E05D13E023D47ULL, 
            0x8D0D9213F3831397ULL, 0xA248D31F15FFC241ULL, 0x12BBC40CCE725FF7ULL, 0x6E1BD924E32D79C3ULL, 
            0x9F1BF4A6E5AD840BULL, 0xF888BBA74572A0F5ULL, 0xBDAEF18638FBA100ULL, 0xBD827FDFEDD637D8ULL, 
            0x1381C61E3834ABB3ULL, 0xA080E0A2D87B4B3DULL, 0x1B98A341A37E119CULL, 0x6081299AF97BE11BULL, 
            0xA3BA78E2BAFD6454ULL, 0xD21A5D56183AFE77ULL, 0x22D6B3913D20BD1BULL, 0xB410A8B7E7258CEAULL
        },
        {
            0xA53F1C7C79146758ULL, 0x9C6F4CF4FD5EFEBFULL, 0x6816A8F9D1179037ULL, 0x5F1A407D20C43E41ULL, 
            0xB8EE5FD3D60A10F3ULL, 0xAB3578F154EA5C54ULL, 0xA6D2F4BFCF67CBC0ULL, 0x9192BC52DADD9ACAULL, 
            0xCF5C2AD1A12F3289ULL, 0x73BE145BC3B84692ULL, 0xFA3A021073D0E778ULL, 0x162F969DAA1A5244ULL, 
            0x929D8D1CCD1C8A4FULL, 0x6322516FFA87114FULL, 0x4BB3626B877DBF4AULL, 0xA180FA1870AEABA4ULL, 
            0x808D34D4D29D84E8ULL, 0x3EA894C762D39D6AULL, 0xC2B3420467B6CCB6ULL, 0x8DFC4027BE358AB4ULL, 
            0xB1A17AEAFEA7F9C6ULL, 0x0963E254B14E5165ULL, 0xC71250D0DAB227B0ULL, 0xD014FB6EAFC23147ULL, 
            0x0CFA4F46166E2976ULL, 0xAE2656C6CDE60CC1ULL, 0x0ABE464379FE3627ULL, 0x9451C6FFDC73A5FFULL, 
            0x151B6FD6A539809BULL, 0xD494A52E048A4B7DULL, 0x10A25535778B7C0DULL, 0x0E9060D6E1A27064ULL
        },
        {
            0x347E3FDD0F49DF1AULL, 0x577295C6DA12ACC8ULL, 0x57D9D1DD972096D3ULL, 0x5B0EDFABFE847975ULL, 
            0xB1325C32DF5D35D4ULL, 0x3A4F8C3B37309539ULL, 0x5374E7F76EC06B1EULL, 0xBAAED11FBB8FA7ABULL, 
            0x0E724CE5FA999472ULL, 0xB3D078286C202F05ULL, 0x8A16570FF12DB863ULL, 0x38C555EE3D788DA8ULL, 
            0x6DB17B27B30E9242ULL, 0x4A96B5A2A6259DC8ULL, 0xAA7E574D79356784ULL, 0x9790FE292C4F0C58ULL, 
            0x3C21A317ED07E831ULL, 0x325300459FA024EBULL, 0x3FAF98ED28A320D9ULL, 0x8FE288947003073BULL, 
            0xA09D8BAAF6190F6CULL, 0xF54D7BC9E24CBE22ULL, 0x64ED1EA716B83EE3ULL, 0xB5CAAB6B18395143ULL, 
            0x46A910E3F1772020ULL, 0x22619EE205AFA4C8ULL, 0xD77E075340A7A6AFULL, 0xD9761DAEC2876CAEULL, 
            0x2D2C4E190B4D3717ULL, 0x96C5B0D31720B782ULL, 0x89E6C7BD20791354ULL, 0x33030D725111C91FULL
        }
    },
    {
        {
            0x01475AE130047405ULL, 0x1160FF915E7D9FF7ULL, 0x106ACCDE1C31074DULL, 0x3DA6E369A291BF7EULL, 
            0x07EFB84E41AC9E53ULL, 0x9E7DCE42ED944C5EULL, 0x7FB8208430E9DE1CULL, 0x729AB0A5A187B17BULL, 
            0x83354B7DA30307AAULL, 0xED2B4DADDAAED420ULL, 0x375C73DC7DF32794ULL, 0x3A22FD7CEB400D67ULL, 
            0x564DBD05A33CE2E5ULL, 0x34896E38A8BC8B3FULL, 0xE0DED1746415F19FULL, 0xB96A56B2BC72F772ULL, 
            0x3A55448C4CF3E2E5ULL, 0xA6C3C9B7C3570D0CULL, 0x03FF450200FB2E6AULL, 0x8D3C73DEB5FEAA23ULL, 
            0xDCE19B22F5DE0948ULL, 0x268E49DED54D7CC3ULL, 0x2A5D4793A619A688ULL, 0xA0E3F444347D1AB3ULL, 
            0x0289EAE4A4E9DAFCULL, 0xA4D0AE3F6A466557ULL, 0x61710E0E5077F7FAULL, 0xD9435612EAD87A2FULL, 
            0x88F7D835FF1EDB05ULL, 0x9EE0F7A8D0F0CEF0ULL, 0x723BF29D49510672ULL, 0xECB79CCD7B8CF85CULL
        },
        {
            0x24F2AE73A85C3D8FULL, 0xC38623F27A56EC5FULL, 0x2E351B92FB2FA6DEULL, 0x3DB16A618DB46278ULL, 
            0x7F58929FB7B94165ULL, 0x5708B3317D4FB916ULL, 0x77EAADF1CC68BD37ULL, 0x842987EC77F6ED1AULL, 
            0x61718CBB68DBE32AULL, 0x1A319BEB7930458CULL, 0x566DD1DCBBA56503ULL, 0x01832191FDB46E80ULL, 
            0xB9764535D9A13191ULL, 0x954070425FA854FFULL, 0x8BBEFF45768297FAULL, 0x12B98A4B44895545ULL, 
            0x5F01F195761A486AULL, 0x42B63607A4C9728FULL, 0xEDC41F04D0D7E58BULL, 0x1738BAED978327C1ULL, 
            0x3CD6555BFE1E99E2ULL, 0x1AFEA96098736D3DULL, 0x26971108A3B02494ULL, 0x78A80F0B578DA5D8ULL, 
            0x496CCB65F522DF92ULL, 0x1F22247792305C99ULL, 0x0516F4211075AADCULL, 0x9721A5F8B9D51507ULL, 
            0xC8975DD832253338ULL, 0x06725CF2D372E99EULL, 0x4B411CE7C8EE1093ULL, 0x2FD3DBD06FD0D4D0ULL
        },
        {
            0x0FC79FB7A9A52BF2ULL, 0xC2EC7B0C01225820ULL, 0x0C3F75C967ACB059ULL, 0x2768C37F883E991FULL, 
            0xD2E307FC2D5C7623ULL, 0xBB5B3D913642B3B4ULL, 0x51B6D761992B03D0ULL, 0x416181861CAC55D5ULL, 
            0x2F33192FA020E396ULL, 0xBF262DD98F6FE2ECULL, 0xC604A06E98A4A888ULL, 0x0AE1DF9AB9510719ULL, 
            0xABF011F97DDB669FULL, 0x45DF69F21A1DD9E2ULL, 0xECF6EBAF0FEA6A7DULL, 0xFBB44FF9E3DA8438ULL, 
            0xE7FB4C026E735A27ULL, 0x5CDA2E6EAD808A34ULL, 0x6DA3EDF381B48DDBULL, 0xEEC0E2087D0B6A80ULL, 
            0xA49E52849688630BULL, 0x3AC55FF55C89CE9FULL, 0x554DCB5AFD14930BULL, 0x61AD36256BF0C86DULL, 
            0xCCAD66C86ED83374ULL, 0x2859A9887F68F2DBULL, 0x69746DDE49E8A5ABULL, 0xAA1BDC7B11E0CD69ULL, 
            0x2D2B131B658107FEULL, 0x39AA195B17BE0115ULL, 0x5C8D066D9EA15277ULL, 0x7E9157D31FA03D12ULL
        },
        {
            0x8B25966CD6C42E94ULL, 0xEF9B1BEFC61BFD63ULL, 0xAF0858FF4E3B2120ULL, 0x7AD4D698BD9ED52DULL, 
            0xC8FEAA92C1909288ULL, 0x4FBEA75C8018ACA5ULL, 0x6C7C3A4CDE52B72EULL, 0x58FCE5CEF7A9352FULL, 
            0x46B8FB978E3BAC30ULL, 0xABF312A46313CED9ULL, 0x02AA00175F3F4CCFULL, 0xE7C552523751BE44ULL, 
            0x1A584F5207B5A00DULL, 0x864A519CE5CE2EEFULL, 0xA288D0A73B7ACEA1ULL, 0x28FE955ED3D177E6ULL, 
            0x27AD921D113E513BULL, 0xB73000745689F07FULL, 0x7247FA3DA99E3A52ULL, 0x82013A53BC1542D8ULL, 
            0xC5E3161418AC29A3ULL, 0x679F8AB0FC9A4DF9ULL, 0xE6BD0E6D65F3A231ULL, 0x8DDCADFE0D578B96ULL, 
            0x82287342803108F1ULL, 0x01228AA99D8C4685ULL, 0x35712EEF00491061ULL, 0xF0B7CA15D8587BBBULL, 
            0xBA27AD2B724BE27BULL, 0x49D37EB98AFF297CULL, 0x941ABDF5E4F894C7ULL, 0xAF98137401759536ULL
        },
        {
            0x17B7D717F4974303ULL, 0x635A46E31D7B3745ULL, 0xFABA7F6DBC45CE27ULL, 0x9F0EF886B7A43678ULL, 
            0xFD77E73BD31A1792ULL, 0x3FA3412C08B4D792ULL, 0x2DDBE374C13D1505ULL, 0x19B1CB186E4C2A9EULL, 
            0xA635D746723E8D9DULL, 0x98BE2B1879F6012DULL, 0xB0AC0D8ECF5AB335ULL, 0xE8AC8655B47BAAEBULL, 
            0x7D0B1615E0D20FD9ULL, 0x8139A128B019CF21ULL, 0x040432BA5117E6B8ULL, 0xD87C6A379522A7D7ULL, 
            0x34C72D8A2B45F8D6ULL, 0x308330E7B4F7A8EEULL, 0x0533AA1ABC9368D3ULL, 0x2E6DAA28D2822718ULL, 
            0x31AE08EBB26B625AULL, 0x3CFD9048E1B9A25FULL, 0xA2785184AA0B3094ULL, 0x3C7025A2F7621059ULL, 
            0xB60377FA35835B41ULL, 0xAF942C6AA37DA661ULL, 0x022AB1FA9C7BA431ULL, 0x5DE7DF7EE2C5D0E0ULL, 
            0x1D0C54A66471255AULL, 0xE557B2BE4F97B3AAULL, 0x15775058DD59E60DULL, 0x9972011DC00079DDULL
        },
        {
            0x5A3CD145378C13C6ULL, 0x4F1B98A83FA6E333ULL, 0x8F863B02B81D24F3ULL, 0xCE222F1A6A9D204DULL, 
            0x0EE60845BA1A2C16ULL, 0x568773CD0FC14905ULL, 0x508899773C839794ULL, 0x29EAEC23882AF0DAULL, 
            0x66BDBD2C65D98312ULL, 0x378E2006866A44DDULL, 0x17902D21BFEFCE18ULL, 0x14E51FE63B278C09ULL, 
            0x4482216FFB6F90A5ULL, 0x4618A8472559B3E5ULL, 0x38EDCE5F09D07993ULL, 0xEFDD253FC73DFCD4ULL, 
            0xA42114DC9AF18B25ULL, 0xA96CB0E7AD2F1C83ULL, 0x58E70EBF85C1DEB2ULL, 0x6AC3ECBF65F7B201ULL, 
            0xA95B227713EB71F3ULL, 0x303F45078F6F2CC9ULL, 0x00F6D9F92AAF57B7ULL, 0x540CF31E1A0E25E5ULL, 
            0xD1C0707134610ED1ULL, 0x114A3CA9B2CFE59BULL, 0x99154B438D4FDAEDULL, 0xAEAB9D5148E75CCAULL, 
            0x01657A0649221632ULL, 0x3D0BFA28EF0BCB50ULL, 0x6614C726D0489825ULL, 0x3984FBA03F6B18A3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseDConstants = {
    0xB8F0F35A845FFDECULL,
    0x296136E8AEA22509ULL,
    0xF191B86BD2302973ULL,
    0xB8F0F35A845FFDECULL,
    0x296136E8AEA22509ULL,
    0xF191B86BD2302973ULL,
    0x178A03141A28896BULL,
    0x2708CA429ECFC00CULL,
    0x2D,
    0x94,
    0x9C,
    0xD3,
    0x11,
    0xBF,
    0x29,
    0x1C
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseESalts = {
    {
        {
            0x7DA569BFC5B55834ULL, 0x69AFD32EAEB1C00BULL, 0x8C53C24DB30FFED9ULL, 0xD5B2A69AF9E1501BULL, 
            0x5CCC40ED03E0D3BAULL, 0xCBDD5E14B4402030ULL, 0xFCDB971A08EE1331ULL, 0xBC5D126192840878ULL, 
            0xC140F5CA57C7A814ULL, 0x928F719B89437B2CULL, 0x4D9532914AAAFDAAULL, 0x562437FD99309911ULL, 
            0x6213321549756178ULL, 0x1B58610F8A09578AULL, 0x503ABDF9ADA52B06ULL, 0x2DD40263E4499BA2ULL, 
            0xB2DC06F887D239ADULL, 0x45629EB78D7C85DDULL, 0x28857D68C0987A37ULL, 0x89C0A8D2EA124FD8ULL, 
            0x2FCFB049E771999FULL, 0x251CB307D80E64A8ULL, 0x9128EE791C06B78DULL, 0x7561B23612C6FCC1ULL, 
            0xFB7943B410539F96ULL, 0xC7AA343F7851D3EEULL, 0x27497FA793E75E67ULL, 0xF060F95EE83BF80FULL, 
            0x10D68870801F7B0AULL, 0x64DAED4C75B07BBFULL, 0x0037D99E0C411484ULL, 0x99F94B6CC90BEB9EULL
        },
        {
            0xDF4A44121F1468B4ULL, 0x47DA17E999931705ULL, 0x560259E28EEF2A72ULL, 0xBF6F98DCDB3ACD15ULL, 
            0x271EA50D63637027ULL, 0x176CA2D012B8E5B1ULL, 0xCC55977B600E6FA2ULL, 0xA9852416AF623A7CULL, 
            0x53CB2D11F808147FULL, 0x63BC59FD57CBE7E3ULL, 0x9A1E91116BDB9C9EULL, 0xBE01289913347661ULL, 
            0x34D6F717DF314511ULL, 0x25D18EC602E2AF1FULL, 0x64B3CECB48B8510DULL, 0x8AA6749E937A491DULL, 
            0x8F4EC8094534CF77ULL, 0x3787D5378E918EA5ULL, 0x8B0C288D7DC48ED9ULL, 0x84364C5321A67D54ULL, 
            0xAD3B7D2CAE155AEEULL, 0x3527568DA0D68A3FULL, 0x63CEAE54666B1629ULL, 0xD3E90ED32FAC7E2DULL, 
            0xB45C59F963B0EE8BULL, 0x0BA7E45A3C88BA42ULL, 0x94E60BEDF1213D82ULL, 0xE2554BF8FF74DB3DULL, 
            0x60BAF68C3C905096ULL, 0x2495E22C7AA484D8ULL, 0x3CD878AA0C63F032ULL, 0x8AAC0031F792C9B1ULL
        },
        {
            0xC165C7F9D1A5040AULL, 0x4AEEA7C76628E075ULL, 0xAB4864E658E5AE4FULL, 0x4339499B188CBDD9ULL, 
            0xE966BD0D5AEA4B55ULL, 0x1FAD8134F7345888ULL, 0xDFB343B36AC5A768ULL, 0x3F717071A2341A9FULL, 
            0x29E297E9DE1B8F4FULL, 0x3682E90164E2C5C5ULL, 0x5FFE2F8F4B4A1AB3ULL, 0xC0728964EEB1F0E9ULL, 
            0x8103C17032242070ULL, 0x1F946DC483CE5424ULL, 0x3D189299B5102EB9ULL, 0xFA04304BD3F31964ULL, 
            0x61EF563C08019679ULL, 0x4FC561273852B044ULL, 0xE02C42D4C6784E33ULL, 0xC097DD02D58CBB5EULL, 
            0xA11BB702D108290DULL, 0x339ECB9A489BE33AULL, 0x2120E494F11155B0ULL, 0x2E226C80024ADFDCULL, 
            0x6880C96876836444ULL, 0x5197FA2C25D98F21ULL, 0x7C49D338468C3981ULL, 0x29AD7F992FF18C51ULL, 
            0xC61AB0515D36AD23ULL, 0x8E6FA626E9973BD5ULL, 0x8DBE399D26A19181ULL, 0x77ED39AE464AC6D0ULL
        },
        {
            0x6AB9141F68B6F092ULL, 0x3E2C52532BE1FB39ULL, 0xA6D725B290149510ULL, 0x89CB3DFC731519F2ULL, 
            0x186B1DEC146905EEULL, 0x5B481DAEC7440C9DULL, 0x4CCCF41F2C895494ULL, 0x6BBF54B93F7FA718ULL, 
            0x651C91252707B878ULL, 0x1AB58ED923F6575DULL, 0xAF97915F6329E837ULL, 0x8ECDF1B433D7921BULL, 
            0x570B86526B4395C3ULL, 0x39FA6860D3F94FBEULL, 0x9B803CF72FBA3FD5ULL, 0xEA7D5DF7C41E8C95ULL, 
            0x6711CA063EEA94FCULL, 0x5C63E1D034E98832ULL, 0x6819AA67F78BB745ULL, 0x3AC5578C8066BAB4ULL, 
            0x92166A1545759F48ULL, 0x59E0DCE32B2361D7ULL, 0x59D8D6614532F20BULL, 0x0B03D5EFAFBBC419ULL, 
            0x17A2C975CEB639FAULL, 0xB2A68BE68B551030ULL, 0x70FC21CF6B67DA9EULL, 0xA91170F74472856AULL, 
            0xC5CB4FCD52646C61ULL, 0xC8719A402836988DULL, 0xBBFA332AE36D0418ULL, 0x3B39F274FC42C7F5ULL
        },
        {
            0x97DD3E9849D64ED2ULL, 0x1E78974D8A0B5427ULL, 0xB2356AF0602BDB02ULL, 0x23703FA23BD69D45ULL, 
            0x7F5A93AC2BC61831ULL, 0x199E52B4A0D85007ULL, 0x1DF03FB76F6CD0CBULL, 0xEDE33AEB997F8C8CULL, 
            0x7FAF95D2AF255B6DULL, 0xEBB3C9C3EA6BDC95ULL, 0x24096C06AF43FADDULL, 0x4BC4FA173131A712ULL, 
            0x5AFE885999A2A42FULL, 0xC9DBD59D080160C1ULL, 0x986D0257EA93AF15ULL, 0x53A522B04AA60308ULL, 
            0x183F7B36FDE3040EULL, 0x049611E5533B4F3EULL, 0x623932D421F9A3FAULL, 0xB5992F0F5CBCF068ULL, 
            0x268E62B39A5C7A85ULL, 0x23EC7DADD8647AF0ULL, 0x247D9E89C045BD7FULL, 0x49F0A61CEE3D01A5ULL, 
            0x50A739E60431E2A5ULL, 0x090614332E4B6D30ULL, 0x9F4DAC40A5B5B9C9ULL, 0xFF6D97CA9252C4CDULL, 
            0x8C9B1BDB4F70167EULL, 0x01AF06DAD2C8F663ULL, 0xBEC7DD12E243655CULL, 0xB2E690D051BE20F5ULL
        },
        {
            0x113DCD9139E8153BULL, 0xF1DC059541660C50ULL, 0x0F3977F630ECD19AULL, 0x5A4231050642168BULL, 
            0x3769A4603C1DE109ULL, 0x7528668DA8B57015ULL, 0xE36CF458AF4DE073ULL, 0x7C8352E41158D7E7ULL, 
            0xC332088173BC0C01ULL, 0x64B8DB12EB0BFDD8ULL, 0xB533325A80C65D0BULL, 0x257B4B4ECA314510ULL, 
            0xFFAA2051F5DBFFC9ULL, 0xD04A4B9ED670CD96ULL, 0xF9FF8F8CF6EAB7CAULL, 0xF539E412A75CFDBAULL, 
            0xC29060473C09D4D3ULL, 0x6A33D7A7942D9F01ULL, 0x325E5B08C6034CAEULL, 0xCC766690CEDC5C4BULL, 
            0x1BC65D2D60A0A559ULL, 0xB525BBC0562693BEULL, 0x19A87F7EC1FD5C3CULL, 0x80030920D466AB68ULL, 
            0xFF761139AD5A0DE8ULL, 0x529FE90259581328ULL, 0xE3713CD34F5BB62CULL, 0xD2A523FD53221D50ULL, 
            0x8311A4EC5FD04B65ULL, 0x6D146EE1AD693E3BULL, 0xB2D788FEC0102CB2ULL, 0x9E7794AD4945AFC4ULL
        }
    },
    {
        {
            0xC3BCAFBD3AA239FAULL, 0x1C41264B7BADE90AULL, 0x8C1CEAA38F5E7123ULL, 0x1A31C73417F1DEC9ULL, 
            0xFF302B11D6E5273DULL, 0xA43C9E6752B727B6ULL, 0xB359C13A858B0E19ULL, 0x924DDD344ADC565DULL, 
            0x2968626198800F01ULL, 0xD56DC042B42C3A15ULL, 0xE6A14BF525337886ULL, 0xAFB55FB5EB9213BDULL, 
            0x05E53C1E6F454860ULL, 0x51A7E1FDF2BE525EULL, 0xE4A53B5EA9585EF1ULL, 0x2A2A8B3DFA8D1480ULL, 
            0x7E99BAB461633460ULL, 0x305B08C7FE507DD1ULL, 0xD9A1AF180206C6F4ULL, 0x10E3C8ECD40D1DEAULL, 
            0x702F1CF666EF4A61ULL, 0x32D3103952DA73F8ULL, 0x73EC8EEBDB59F13CULL, 0x092FF913434EC3CFULL, 
            0x55777FE68FDDDB8FULL, 0x1A447B4C87E342E0ULL, 0xCD685177231CD64FULL, 0xF5756BD213EFD409ULL, 
            0x56942DB51F3FFDC7ULL, 0x98BB3FE0737DF7C7ULL, 0x5A0F7F2AA0ADE3AFULL, 0x9A62AE74D461A492ULL
        },
        {
            0xFE474B36A5F7F65AULL, 0xBC16A48FFC04B508ULL, 0x3C61F92A389AE21DULL, 0x2F2EBE3A3CB4EF1DULL, 
            0x5E0C3CB2339BBB53ULL, 0x795AB91ADE9C7FE7ULL, 0x0F85C867C79619FBULL, 0xCB23CC0CF7F117C6ULL, 
            0x60B9D5F242CCF7E4ULL, 0x8A8E73AC3956BC39ULL, 0xF6B1312B6F029108ULL, 0x4B07FCA040E22E49ULL, 
            0x88096F3841B58B63ULL, 0xE68ABDE1701C0310ULL, 0x2183F2120DE20A5FULL, 0xC98C8A16C763D0FBULL, 
            0xA8D196C9179FDD14ULL, 0x64F995098147ADD4ULL, 0xA23B8AC010BAA784ULL, 0xCFE4B781A831A6AEULL, 
            0x190041E62A84A941ULL, 0x7653F999C070C0D0ULL, 0x26B59C29A126CF7BULL, 0x636DDE62CB8C59F5ULL, 
            0xC638B2ACC0D4C3AEULL, 0x20A9668060167A6CULL, 0x3730BB1952EEB44DULL, 0xFA75AAC028F8BC83ULL, 
            0xE0647C6EDED6AC01ULL, 0xF1E12D59C99F7F17ULL, 0x83709F15197CE3A4ULL, 0xEFEE09A656210226ULL
        },
        {
            0x8A0A85E34E99CD67ULL, 0xC3A29E065B66110BULL, 0x68BD87AE7C6C883DULL, 0x78877A7E0C4E3CE9ULL, 
            0x2AE0B89E8C011822ULL, 0xA3A9E5FDC454504DULL, 0xFCFA9643199AAC5BULL, 0x8261AD212FD04D13ULL, 
            0x4BC5559474010386ULL, 0x631CA4832B041B1BULL, 0x200E074844F8A877ULL, 0x89977ECEF5A4AE48ULL, 
            0xC60F543A8251871AULL, 0xBD6083F5B20F48EAULL, 0xDF1B20752B7F529DULL, 0xEB4593B6861EBBE6ULL, 
            0x34FAADD9ABD71EC3ULL, 0x03F4075E1A0240E3ULL, 0xD35B022A919D58F0ULL, 0x1A846DFEF3675842ULL, 
            0x6B3255729CA95F96ULL, 0xB3FA3EB9C4FF3CD7ULL, 0x0B4B0E2ACC7AE6FAULL, 0x248222A7FE24CA56ULL, 
            0x18A99B4ECA3BCA89ULL, 0x0C4348230C201484ULL, 0xC9BBA6EA5AEE3FBEULL, 0xFB0855A2511B3096ULL, 
            0x595762D11A1D0F05ULL, 0xBF424CBE2F570801ULL, 0xE550127D924A68B8ULL, 0x1149EADC8BD20BF4ULL
        },
        {
            0xB07C95BFB6084C9EULL, 0xCDE347477D4BA238ULL, 0x797A47BD05B25940ULL, 0xA523CE16E12CFA03ULL, 
            0xBB799F84079B271CULL, 0xF0D4D60A8A7E5A2BULL, 0xF4545089299DD2D5ULL, 0x4BFA7649E5017EBCULL, 
            0x01EB12D06DA04FE1ULL, 0x5762D64D669EEDBCULL, 0x5FDB52EE4B742145ULL, 0xE0D75E35971E53CCULL, 
            0xA3A1A3DDA42DBD7FULL, 0xD85C83EB616F0A8CULL, 0x9613CFB9B9242D90ULL, 0x19038E3B7E20E855ULL, 
            0xE1448F56F4B2BA59ULL, 0x52D219286D3A5CCFULL, 0x2696EC940A6D0890ULL, 0x56B93C9F42704C2CULL, 
            0x1E3D5C408314262FULL, 0x8FD0A65D74E21407ULL, 0x624F36B2B33A4206ULL, 0x3BA30A2001759863ULL, 
            0xAFC201F843CF0A6EULL, 0x587A3A7A5E14617CULL, 0x183DA0369AA01F08ULL, 0xBBD8A2D7D8521ED0ULL, 
            0x463286047439052AULL, 0x97EC1C0DD474929DULL, 0x95FEF0B862AC5763ULL, 0x6DF589FC9D026C46ULL
        },
        {
            0x6C1703CE54E0D68AULL, 0xF49EE2F4CE1AF8E7ULL, 0x731DCC0A0063837BULL, 0x465C4836E1E92259ULL, 
            0x5C787205B57EAF13ULL, 0xD80A868E6DFEB5AAULL, 0xF35F752FAA475613ULL, 0xDC94ACA105F38A9EULL, 
            0xD8772DF010BD3D64ULL, 0x4CDF7B9D043EC1FBULL, 0xE48FFFEC389ACA72ULL, 0xE693A92E64F4431BULL, 
            0xFAF845F2B0EE8A44ULL, 0x2F4DDB1D842D4CB0ULL, 0x66A97B60284EEA8DULL, 0x93429E9C27764FADULL, 
            0x69E0DF6BD91B65DFULL, 0xAED4BA6400B13D8AULL, 0x0635A8262D45AC1FULL, 0xA41ADB66F1A2E8E0ULL, 
            0x63F337D42A0184B0ULL, 0x699A3B845ABB8063ULL, 0x236FA8DD1C01B8ABULL, 0xDC22DD5EE6E2D95CULL, 
            0x89F1E8D9BD365A2BULL, 0x7BC5A11AD0B15EDAULL, 0x0ADD5254250AE55EULL, 0xD1D5C22D259053B4ULL, 
            0x18304E5C6D8FBE07ULL, 0x1872D8AD55E6D5BAULL, 0xD475A412AD9A3146ULL, 0x27ADEBA7CC96AD27ULL
        },
        {
            0xC80F16E8938B16A3ULL, 0xFFA33420E4E85B5AULL, 0xE7DEAD88EDCADE1CULL, 0x51C217B77746AADAULL, 
            0xF3FFB9327B6BA624ULL, 0x980A91F82B805B70ULL, 0x2DEEF8FA12C2F552ULL, 0x6208657508DE1EBBULL, 
            0x2F9649D9BC25EF36ULL, 0x5988F0E7DFEC4B7CULL, 0xDE9C0D7022ACF9C8ULL, 0x21762BACCF4C6E80ULL, 
            0xEA9F8EE13F8D5F68ULL, 0xBAA550E6688B164AULL, 0xE59E2FF195C2B446ULL, 0x4B601E1543816747ULL, 
            0x3042E581FC7BCCCBULL, 0x8BE0153E15316621ULL, 0x9160A08839B61AD5ULL, 0x8D02065E80D1DD06ULL, 
            0x42CF0EC6FC892BE9ULL, 0x582D90C05DE17825ULL, 0x1F2B8583CD2B9CA3ULL, 0x42CDE8D33F631299ULL, 
            0xE207F05CBA1C9C49ULL, 0x701BF26B0D62309BULL, 0x0A7610AC68952469ULL, 0xEE774C491B5D6972ULL, 
            0x7D17E2CC60E42A2CULL, 0xEC8634C127EB5CC0ULL, 0xFEA0F989270A41B0ULL, 0x1952D7DF61155030ULL
        }
    },
    {
        {
            0x49426E93F2EE0632ULL, 0xD701D3E782DFCB3DULL, 0xBBF81F42EB7E6ED3ULL, 0x74C015E7EA8A69B2ULL, 
            0x8A16090DCF104BCAULL, 0x4C493B9342A3E791ULL, 0x3FEFADC978A915CBULL, 0x047E9C255A7EB943ULL, 
            0x25E57B3B43ACAED4ULL, 0xD4167BE4A5549CC4ULL, 0x51E51A43B3619B83ULL, 0xB321D82B98B60C51ULL, 
            0xBAE99E970D358284ULL, 0xB9D27BC5D12210A2ULL, 0x8602C7E4157BA605ULL, 0xF8EA7E1CD1E38048ULL, 
            0xDF5CDF43CF7321E4ULL, 0x65C5B236E9274D89ULL, 0x537996A36DE05780ULL, 0x1299119B95B1CBC3ULL, 
            0xBA1F3B502C668AEBULL, 0x1797B23F3AB61899ULL, 0xAB4104DCABEDBA90ULL, 0x603A69993A417DC2ULL, 
            0x49B14824B3686E20ULL, 0xFABFB8573523DDABULL, 0x41168F95A2818E69ULL, 0x89388A52A790B772ULL, 
            0xBBB2C773757EE16DULL, 0x1E6B445D5CD1FB6FULL, 0x4A4C356733B239C1ULL, 0xFDF6D0369471189FULL
        },
        {
            0xB2F7BBB84592B533ULL, 0x5DAD6E4369341E52ULL, 0x5B1CFE166532909CULL, 0xD9DDC81B403BDE70ULL, 
            0xE6B38CAE13B5625EULL, 0xE31E288A65639D8AULL, 0x5E3D1CDCB9C5D19FULL, 0x0145837D40DDE4DBULL, 
            0x32377B86968EA6AAULL, 0x22AFED0FFDA3B48FULL, 0x9413F4EC630BE556ULL, 0xF654D017D51805FAULL, 
            0x10BA653AF88F06C7ULL, 0x5408E410A7176EDFULL, 0x2DD213413E8C4563ULL, 0x96A8CBC88AF64A22ULL, 
            0x0797D7376F88FA32ULL, 0xC0D52D686EEED176ULL, 0xEF619A52DC46F584ULL, 0x6E78BBC61ED39706ULL, 
            0xA7071102801ACE55ULL, 0x63F5843590544C44ULL, 0x8716F209E75879E8ULL, 0x6B25BD874F1C9D5CULL, 
            0xFA90A7205E3CE5A0ULL, 0x76340CD99DEF32C8ULL, 0xE10FDB8B36339BEDULL, 0xFF28B1B32CDFF754ULL, 
            0x86EAE5F15BD8F6D3ULL, 0xE1650D8396AF5186ULL, 0x7AF4F94FA185BFE5ULL, 0x9EFF873029011BE7ULL
        },
        {
            0xD5A0555F19C5C499ULL, 0x12CC895146ADA9EFULL, 0xD4EBAFB18BD749A0ULL, 0x70D8DB8AD7F66A8EULL, 
            0xDB3366F8D10683D3ULL, 0xF0474F0BFEB7FDCAULL, 0xFB51FAB81706742DULL, 0xC9E3D728F849D20CULL, 
            0x0B5BC1244399126DULL, 0x5110824FA64D8F3FULL, 0x862C2E10C5E1297CULL, 0x1814F9425E124C78ULL, 
            0x9109963282BDEA0EULL, 0xD4F2737EE580C5E3ULL, 0x021A4F2CF435A9DEULL, 0x6C91A0D90BF90CE7ULL, 
            0x46E540FB706C4A8AULL, 0x8823F2D81DE63381ULL, 0x46BF90171D9BCD92ULL, 0x4575312BE017156EULL, 
            0xA67F563555AABCC5ULL, 0x7F60D191A02F3714ULL, 0xA239067965803F26ULL, 0xAB514A28772F20D5ULL, 
            0xBA8EAE3F0927C88FULL, 0x9E9910B5A71BF487ULL, 0x3BDAD2BCA8C0B085ULL, 0x2591FE97B6156A58ULL, 
            0x8B3E8057300C24BFULL, 0x86879016901C946EULL, 0xA587D52EC7BE11B1ULL, 0xB6E2E097904F2D73ULL
        },
        {
            0x3CD3DE112597BEC3ULL, 0x53579F9F82254CEAULL, 0xAD0C3B55B349B3FEULL, 0x73A37056182C0D57ULL, 
            0x0491FDBFDE30D099ULL, 0xD322EB2AE0417AB0ULL, 0x48AAC43C1EAFFE99ULL, 0x63AFC52893A9F327ULL, 
            0x5E0E18E73D8FB81FULL, 0x65312B60878E56ADULL, 0xC2824EE0817D8656ULL, 0x33EBF2EF43D8DF5AULL, 
            0xE305EDC29E40E1A3ULL, 0x5B7B9FAA643F4F53ULL, 0xD61DE34405E3CDF5ULL, 0x165814A0D721ED49ULL, 
            0x1AEDD0E4B89D3107ULL, 0x24AD24AF8394A254ULL, 0xF7957E85A43C1224ULL, 0x42E335F13D1D35BDULL, 
            0xD0A0B12D0624CE65ULL, 0xA09D7118CE73521DULL, 0xF0505E7A0C7DBC57ULL, 0x665E7E62AB5E2D45ULL, 
            0x63EC0CB0AFA53F91ULL, 0x94E9F36ACB89CFCDULL, 0x5B340B38C4CFD108ULL, 0xC42C38981BAD7580ULL, 
            0x676AEE4C5E74DF3EULL, 0xD84CCDB7F9AB99F3ULL, 0x8DA642A956AF0CAFULL, 0x3C9B7D0C2D55F5DCULL
        },
        {
            0xDBDD86BB9EF88554ULL, 0x7DE48E84B45D1A57ULL, 0xC7C892774A481935ULL, 0x562CD55DD86AC607ULL, 
            0xE322C169FE0E1310ULL, 0xFFE63D4386351452ULL, 0xFD90EA4EA5D40CF4ULL, 0x0FE5EE3517025CF5ULL, 
            0x1E48BB29C99D84A2ULL, 0xDB2334CE5298247EULL, 0x232D99ADFD731C5CULL, 0xC317680376D497EEULL, 
            0xCF363DB457CCEF0DULL, 0xDAC6F75739ACB063ULL, 0xFB5AF61AB5C70B47ULL, 0xB3FB31EBC0052641ULL, 
            0xE590AC8B345D6CB7ULL, 0x0C67C5C3C79D4EE1ULL, 0x0BBA0A810D10E751ULL, 0x9C4B5FCD9AE5BFC6ULL, 
            0x83AE3E08A80F516DULL, 0x1F8BD49A63B308A6ULL, 0x4DE53817B41A2C87ULL, 0x8C94491B711301C2ULL, 
            0xDB034B18512EB0CCULL, 0x7969A396F7D00987ULL, 0xAE0E1E4DF0B0B75FULL, 0x52CC9273F76D08BDULL, 
            0xFE50C635765B4103ULL, 0xF0AE08FADB5EF342ULL, 0x996B8A8C618FA342ULL, 0xF5C73166191D7F95ULL
        },
        {
            0x14A527200DEF9BEBULL, 0xB2C9AAC95C04BF53ULL, 0x8B719B4463E5EB5FULL, 0x766D7C70473A834DULL, 
            0x65EB4BF8F464D450ULL, 0xE985BF80750E3790ULL, 0x7E8809B95BC7F74FULL, 0xEADBE78F5CC6F2B3ULL, 
            0xBDA95DD58641A65BULL, 0x6960674A1858D38EULL, 0x47F18CFA6C286853ULL, 0x708849260E93D9B4ULL, 
            0x1819B149CDA0DCEBULL, 0x62043C21FA0A8742ULL, 0x32A8AB474584EA28ULL, 0x03CC9D3A9CAEA177ULL, 
            0xC16781D9F2DB5D0BULL, 0x9B7F2C7CBC012F76ULL, 0x9E30DF636B2D5104ULL, 0xE51855B51F4AF4DFULL, 
            0x88374FE7929DE624ULL, 0x98AD20BD8CC278BAULL, 0xBD32EB84BAEE554FULL, 0x232B102618B22485ULL, 
            0x8A26A1DBCC53B437ULL, 0x9941731241008E77ULL, 0x70C077A78CB44EB2ULL, 0xB57D64810FDE6CAEULL, 
            0xED67030B7B5E06BCULL, 0x9247A998C0D29E31ULL, 0x63988735015C30BEULL, 0x3CF45950A9F83B3CULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseEConstants = {
    0x5C17B47E070492C6ULL,
    0x8F73842B9C13D810ULL,
    0x60D3266F4714BB2FULL,
    0x5C17B47E070492C6ULL,
    0x8F73842B9C13D810ULL,
    0x60D3266F4714BB2FULL,
    0x51BF346F3F52D6C5ULL,
    0x0615C48C0D48E211ULL,
    0x81,
    0x85,
    0x84,
    0x6C,
    0xE2,
    0xDC,
    0xEE,
    0xD3
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseFSalts = {
    {
        {
            0x9AF7A8C1B0073CA7ULL, 0x5093A4AC3B533358ULL, 0xBF15A5C9EA0BF8F6ULL, 0xD6A06E504EFD89D5ULL, 
            0x61AA28E104DF67D0ULL, 0xC766BED2C56EC482ULL, 0x82C44F0C91F0662FULL, 0x040641DC34E10D4FULL, 
            0xE2CEF66E6DE415AFULL, 0x3852365E2F4F9276ULL, 0xE66D229F706CA06CULL, 0x4F343979D20D5A4AULL, 
            0x5DE481D30426455FULL, 0xAF2FD3DD27E7CB32ULL, 0x78748EEE0F8565D0ULL, 0xA346323FA0038C48ULL, 
            0xFB9699B849D0FFE3ULL, 0x155A0C1833BAA691ULL, 0x6F56AC6208569D12ULL, 0x946B6B32C3FCFEC6ULL, 
            0x70737FDD550684D3ULL, 0x017EB09E8611ADC4ULL, 0xE6EDF59939FEBE62ULL, 0x6B58F4C85799EAA0ULL, 
            0x6AB885B9AA2B47D4ULL, 0x2AD2366054E5337DULL, 0x94D2C3B485352DD3ULL, 0xB6834F4611042F0DULL, 
            0x899238A7F2BB72CCULL, 0xDFCA9750F47EA216ULL, 0x2A69C058D099DCFFULL, 0x420AD82D64BBC0AEULL
        },
        {
            0x734EDC0F4C40063BULL, 0x1F9D57C94908C052ULL, 0xDF99D3D8DED4BE7BULL, 0x6B191F3ABD44FF36ULL, 
            0x6184D490B084D869ULL, 0xE79BDB1D405DCFCDULL, 0x2BA06C00774CE0A3ULL, 0x8F68C097D3AD3586ULL, 
            0x1F7BA3DB439EC138ULL, 0x5D4DA83C064B0039ULL, 0xB85A7DEFA6AC99EFULL, 0x90BB037410CA5262ULL, 
            0x2DF1F4BC9DB016DAULL, 0x437106678C7863A0ULL, 0xF54D48D67364159BULL, 0x60D52434D6C0B50DULL, 
            0x421A29464E6B0270ULL, 0x319F2639A82A942AULL, 0xFA4194A240C2DFF1ULL, 0x680BAD91B10EF4B3ULL, 
            0xCF41E95DAC6AAE63ULL, 0x5250368A7044F80DULL, 0xDBEFEBDB9D4CD2F5ULL, 0x042D9A7B2A94227FULL, 
            0xA534A827B89029E0ULL, 0xF5CDA152652D9750ULL, 0x1CBC27A2CE44BA4BULL, 0x529D8784EC7C3DBCULL, 
            0xFCDA840DD31048D2ULL, 0x5C19E28000B001E2ULL, 0xD75F0B78C072A7F1ULL, 0x9A65FA5C7EF5894CULL
        },
        {
            0xF93A2804E0A02832ULL, 0xAEB1140D746A900AULL, 0xC286ACC84346538CULL, 0x82FC0503D44AE3B7ULL, 
            0xC7FA8CFAC43F2201ULL, 0x93B6E65C4876ECB1ULL, 0xDE0ABD6A0E90190CULL, 0x9D9F3861945AFAF1ULL, 
            0x716E50934909B6A6ULL, 0x64CF8788FB67BB25ULL, 0x09745959E1ED68BBULL, 0xC8B7B191D866D6A7ULL, 
            0xD2262942D2EB1166ULL, 0x8279B56839000C93ULL, 0x1949683311E15CB4ULL, 0xF572F47495B5FBC3ULL, 
            0x868C17CD1FBD91FFULL, 0x500A0E063ED0AC7AULL, 0xF80B14B04DF2B724ULL, 0xE666196D0CE559F9ULL, 
            0x25F976A7D442BFFDULL, 0x3285356936F95CB8ULL, 0xC581B204FBAFCAA8ULL, 0x79020E954D995741ULL, 
            0xADA6367EDE595A74ULL, 0x88A15AE977C503C6ULL, 0x6173283D034B1E74ULL, 0x3F139BEC1B276153ULL, 
            0x854E6C8E4B157091ULL, 0x8E55389AE5EC0459ULL, 0xC3146A508AC3C87AULL, 0xBCD313D52FDC50CDULL
        },
        {
            0x83EBA2A1D6F2EF80ULL, 0xC61A2C8957ED4E00ULL, 0xB8819D79E3C7D4D5ULL, 0x8F00803CEE9F8DA9ULL, 
            0x06AC5ED6D275FA3BULL, 0x11515DBD6642456EULL, 0xC19F5AF0A1F5EFF5ULL, 0xC5AC866CCBA218D4ULL, 
            0xD6C25B8C4BF6C784ULL, 0x7CFC0AD3272496A6ULL, 0xE9A92A78AB343DF7ULL, 0x13A0D80D11B745DAULL, 
            0x6F001AB8338B8933ULL, 0x7E5358CD8B04707FULL, 0x52A469F785686E07ULL, 0x21512FD9E518132DULL, 
            0x4103E07BD45F66ECULL, 0x3DF97FA233E1FED2ULL, 0x9A71DFCCF3347DB6ULL, 0xCBE1598A161A8AA7ULL, 
            0x2010EB3419055BC1ULL, 0x0E367F393DD81EF5ULL, 0xB79669D316C97E6AULL, 0x9DD33CD84573CA1DULL, 
            0x0D71F9F03B35486FULL, 0x5482F6B357C3ACC4ULL, 0x0F967170DE4670DAULL, 0x92F005887C1F9DA5ULL, 
            0x6361FFDF3F61093DULL, 0x833C8EEB5D88137FULL, 0x256A606E58DB24A5ULL, 0xD3C06CC346CF11AAULL
        },
        {
            0xFD419D5699C7D97CULL, 0x011D8E12E9FD52E6ULL, 0x320CB432925C76A9ULL, 0x39DC60A335A3B680ULL, 
            0x57F32C7D0A07E44AULL, 0xBE3C909996B39F37ULL, 0x588AA5005130B04FULL, 0x8247F97A0DE72C46ULL, 
            0x4810BDF97800AFB2ULL, 0xAEC9A8222F81E0F1ULL, 0xDDD3F5D2918E488BULL, 0x6BCF1625DE8B282DULL, 
            0x0C5C4D0E34081624ULL, 0x4EBB2A20DC426B24ULL, 0x81F5E3117FF3335BULL, 0x87C750D639DB9323ULL, 
            0x361628B81BCE63B5ULL, 0x78DCFCB31F065A54ULL, 0x3B99338BFE7FBF6BULL, 0xF781D02A77E5EA5AULL, 
            0x6F56659A36951C00ULL, 0xC7A47F3F262267B3ULL, 0xB239A3300B5CCCF4ULL, 0xB8E167EB116FBD34ULL, 
            0x873962F79E1EDDEBULL, 0xB5506153846F99F1ULL, 0x41AD24DC7B8C86FDULL, 0x42087897B7C8DB24ULL, 
            0xB343EA29ACEA3952ULL, 0xAF11440F6BCFC22BULL, 0xF51B9CF37BBBD8C5ULL, 0x61B587ACA924F406ULL
        },
        {
            0x21B86EB2AA9A204CULL, 0x61A0342768224D15ULL, 0xEBC025A582BB4672ULL, 0xE2E10719E77EFF81ULL, 
            0xD9348F45F781AE92ULL, 0x65F5F7F6B0F80064ULL, 0x248AFE2FA05063F4ULL, 0x05A8C57AC53B84D5ULL, 
            0x8E4CA7609EFE3839ULL, 0x307880610EFC30D9ULL, 0x6ED9075192BEE364ULL, 0xB3C02197EC016CF8ULL, 
            0xA35265299AE4D827ULL, 0xABB2EACCACD55DA8ULL, 0x8AF945FC1BEE981CULL, 0x94638E5FD5508AC9ULL, 
            0x62B219A15CAD7FD8ULL, 0xE7E9D0629C2DF65DULL, 0x950A0345C2927C01ULL, 0xAD61B518E7D13072ULL, 
            0xBAE5758D2E681A25ULL, 0x9785FDEE383B1DECULL, 0x65CF2093B74038F8ULL, 0xDBA19C9F5915F9B1ULL, 
            0x13DF9BD31AEC1778ULL, 0x40561D35A298654CULL, 0xC865F934AAD4DEB0ULL, 0xDA201AD345B00994ULL, 
            0x1E86939C1FA10D5CULL, 0x6F9556C53520055EULL, 0xB5AD15B1CE5D289BULL, 0xD08AE14B0ADCFE72ULL
        }
    },
    {
        {
            0xEF24894F8990B89BULL, 0xD8CD2638F8B7CADBULL, 0x0A6FA6969E0658A0ULL, 0x545A422ED170D184ULL, 
            0x33EB0D5C78C63702ULL, 0x2205D2592B662180ULL, 0x646CF746C9BA3C3DULL, 0x788E32BF6DE2D4E7ULL, 
            0x21EA1A6B8FF9CEC9ULL, 0x1572B2666E8DFD16ULL, 0x6F6658C413381ABFULL, 0x5C82693176C0760FULL, 
            0xF15CD8300247CA14ULL, 0x62E2939F9F99F09DULL, 0x952BECEF28F3D646ULL, 0x56DC7F7AD848F365ULL, 
            0xD5C05C5CAFC960A0ULL, 0x8002389ADAC27B00ULL, 0x5E818FCA9EF6D21CULL, 0x27BD6319F2852A03ULL, 
            0xCBD7FD79B3FDF954ULL, 0xC57D41B27D850347ULL, 0x62A5759FA2F2F120ULL, 0x050676C462B57FC9ULL, 
            0x2C6563F78A83EBE1ULL, 0x7B4A63C586E6D708ULL, 0x59BD47B02BDA1D97ULL, 0x8FCA8F940AF2E710ULL, 
            0x307B6A2D45C77D40ULL, 0xB7B7DCBAA16D1C11ULL, 0xCE9BF1F4A9E5C944ULL, 0xA53D20F7E750EBFCULL
        },
        {
            0x6700A7435D8043EDULL, 0x8ECAE11818FD318AULL, 0x68DC662A6CAEBFDBULL, 0xB3A1859F206B9DCAULL, 
            0x3F2226EF154F29EEULL, 0xD8E734AF24C88812ULL, 0x1052006AF7386AC7ULL, 0xB69C3AB34EDE49CFULL, 
            0xF94C0BB5C8DA7B80ULL, 0xA9D8B3D0603C9E8AULL, 0x060FBED666E3D7D0ULL, 0x501363996A830279ULL, 
            0xBC5DAB1060B2C8E3ULL, 0x6D771997C9D8AA50ULL, 0x6D5EAD5BE4824198ULL, 0x58CF176149BF2320ULL, 
            0x7DDC8B1DADF3D427ULL, 0x6515E100E2EAC2B3ULL, 0x1293BB3A8AB943C7ULL, 0x27B062C5CA70235BULL, 
            0xEE3763C2E3737E9BULL, 0xBE895602EED6E6BDULL, 0x0EE9E180B78A60D2ULL, 0xABB87B59734AEEBCULL, 
            0x9EE71783F76F03BEULL, 0xDC3EE5CDCA231F32ULL, 0xF1299A0DEA9F13BBULL, 0x2AFDD4B77B839656ULL, 
            0x7C1D706CC52DDCBFULL, 0x8F9905E300F32302ULL, 0xA65252327F55D811ULL, 0xAEFE6593A157FFC8ULL
        },
        {
            0x78FA3A62CB4A6773ULL, 0x1D45A1DC85F73BD6ULL, 0xC6DB19E7F5C50ACEULL, 0xA52DEEFDB75C59A8ULL, 
            0xE260703E0881F50FULL, 0xF6432285E42CCE4CULL, 0x68940FCF7AD4568AULL, 0x962973A0951ADB3DULL, 
            0x59D1F0994A831BDBULL, 0xDEB0D6ADAA7E13CFULL, 0xE0175E0DAC08D29BULL, 0x7A3584F619F94CD1ULL, 
            0x05D334EA302427B6ULL, 0x3853010FF24F9D5BULL, 0x828A5BED22DAEF05ULL, 0xE373682473F23624ULL, 
            0x817C2978AE7279E7ULL, 0x34D9A01459498E9DULL, 0xED47524D4FC08AE3ULL, 0xAED59A353DD32555ULL, 
            0xD23C8EE2453F0FEAULL, 0x38103AF40644E1A0ULL, 0x6883E4E1E47CDD76ULL, 0x86297B4024DF0674ULL, 
            0xADF860587210A2F4ULL, 0x9DF1242EFB255BE0ULL, 0xFE0D72743CC1B947ULL, 0x51CFCBAAAB1B63DBULL, 
            0x3263D4F29BE74D01ULL, 0x3D8BB09489BDC7DDULL, 0xC535D0AD182E500CULL, 0xA5373CCEC4B3109AULL
        },
        {
            0xE0996EBB853B9A4EULL, 0x12693F637BF7F874ULL, 0x8302A6B680E623B0ULL, 0xDD9BE98D8513E422ULL, 
            0x1F6124DDE619A834ULL, 0x305A092A14B49AAEULL, 0xA7917A314DABA92FULL, 0xBCEDDD66526FD53DULL, 
            0xA42E571CF7EE4D84ULL, 0x4ACE7DC35BE7458FULL, 0x9A877769A0312B0EULL, 0x4EA8513E13DEBEEBULL, 
            0x4D1C3A8D179C4B28ULL, 0xE542D474FF4F1C83ULL, 0x41E246304AA5C393ULL, 0x5AB16BE1D4F35473ULL, 
            0x275543EC7DCC0618ULL, 0x20C58F54D2D11A61ULL, 0xC242118FFB71B68BULL, 0x26F475F2F693D79BULL, 
            0xFACD00E7949A211EULL, 0x7B262DF63101A480ULL, 0x64D7D9779416DFC5ULL, 0x3509B88A13C9F314ULL, 
            0x9BF1BD77E6F3A595ULL, 0xD3AD23AA4D617F9BULL, 0x6A2BA115C51EB8C4ULL, 0x2000E826F8511706ULL, 
            0xD0B3D8042CAF2ABBULL, 0xB7A5C6B9C304B566ULL, 0x5A82E05B9F60277DULL, 0x74915BD760B28828ULL
        },
        {
            0x876063433A090614ULL, 0xEEEEA16790541023ULL, 0x7CEFBCE824B8F8A3ULL, 0x4B6A424F96E9BAF6ULL, 
            0xE1C2CFB3746F3DA2ULL, 0x56C9DC507D98B47EULL, 0x3F2E5B094494464CULL, 0x79AF37886C656B9BULL, 
            0x3C2BCC01456C9478ULL, 0x61E118984EC32E80ULL, 0x64C4BB1F31E266D4ULL, 0xD111D4575A43CAE5ULL, 
            0x4E5707EFBFE976B5ULL, 0x6FDCD9A463DCC2DEULL, 0x457D2F917229D147ULL, 0xB803A2D32ECC9362ULL, 
            0xB7CE6247CCD09056ULL, 0xFEEF5972F4DF65C8ULL, 0x60F741BE5B9C9FFFULL, 0x843BD7854FB9F220ULL, 
            0x455739BAD0932B75ULL, 0x12EAB3E20AEE83D7ULL, 0x1560BD38F32AE394ULL, 0xC966CB3B2117A6F6ULL, 
            0x4C3311C808264152ULL, 0x9C4FC07A5EF5F259ULL, 0x74C74480B31172ADULL, 0xB09FCA4620AF2C25ULL, 
            0x2C413B607DD6C528ULL, 0x5D84E9833A765859ULL, 0x557CD7C72A96ADF9ULL, 0x24521B7C9B5CE12FULL
        },
        {
            0x27EDFA69FFDB1443ULL, 0x115E36AD7AF3E481ULL, 0x2AB1BCCE97058EE0ULL, 0x068FEE20ABA6D9AAULL, 
            0x0239A8CA0777C356ULL, 0x52F25BC8F2C3B84FULL, 0x25DEB227B8A6BCEFULL, 0x66817637A25AB64FULL, 
            0x82C5AB46DC7F9AC1ULL, 0x73E31720D02BF865ULL, 0xC2E15C934FFBE8C4ULL, 0x96F28B697DA6DBACULL, 
            0x35B37E0526D8F65AULL, 0xDD919691ACE1CB0AULL, 0x72E44F36D737909EULL, 0x5F1FC5BA9B2B0ADCULL, 
            0x0122FE1E539784C5ULL, 0xC51E68B6E0D7AD05ULL, 0xFFB57AB00E16E38DULL, 0x21BD74EB5B72636FULL, 
            0x206F63128174005DULL, 0x1746A0B236CAA6BDULL, 0x6DDFCFD50F480960ULL, 0xCCC87C0C610B58F6ULL, 
            0x0431B10E47212EF6ULL, 0x4B31A0596ACFDBFCULL, 0x4BB6B07E6480552FULL, 0x52EF8BB4BA9228D5ULL, 
            0x70F88316964866F6ULL, 0x6DDA5F40213C817CULL, 0x3E723FB7911D3244ULL, 0x9A625053580DAC40ULL
        }
    },
    {
        {
            0x29F21CD2E6761B40ULL, 0x6CBC9BB6752B20D4ULL, 0x1C267E736870ADC6ULL, 0xCDF426ADB4AA7132ULL, 
            0x46079F0EC7E1512CULL, 0x25B3B51D9AFCB0A2ULL, 0xDB45F4FD7B40F595ULL, 0xE518138C910ADC0EULL, 
            0xA1BB35D304E102BFULL, 0xFCE70C4DA67A9ED2ULL, 0x8D0B0D69E981BD53ULL, 0x1CA9B82F311E5E7FULL, 
            0xE679B49D85A063B0ULL, 0xBA3F7E2279E0DD68ULL, 0x5FE4973418D87324ULL, 0x50FC3F9A43F5F03DULL, 
            0x6133CBD6382339B9ULL, 0x3EC3B36CF402450DULL, 0x1B8B09930A1C34E1ULL, 0xF5EBC8056B4E2B8AULL, 
            0x77CAB96FEFC9F048ULL, 0x943A039A256CD669ULL, 0xCD43F8A4B1A09EC8ULL, 0xD4C2B14BC88F0F78ULL, 
            0xF7D5B469A623406DULL, 0x85F64C631FD31C07ULL, 0x3212BA2318AB489CULL, 0xB7FE8986CD79A90EULL, 
            0x47D88A3D90345372ULL, 0x2886F9BB14DBC595ULL, 0xA7E7E270C832C931ULL, 0x0B800D762236D4D9ULL
        },
        {
            0x63DF81DA66C7CD39ULL, 0x4C83131858AD3E66ULL, 0xAF236184CDAC24E3ULL, 0x308A6EF09C8746F1ULL, 
            0x7E24C079A4AA66F7ULL, 0xE7EDF8154B190E02ULL, 0x73A11BCFD572C86FULL, 0x6A262A8364A2524BULL, 
            0x7675D3F44E197166ULL, 0xA571E2232E829FF5ULL, 0xAC9943B73920118DULL, 0x23055CB0B7D42618ULL, 
            0x9F9E76D7628C0A16ULL, 0x699939E7652F7A6AULL, 0x28D8CAF7230FCF34ULL, 0xCA5334D459E52839ULL, 
            0xD88205D52A7116EBULL, 0x39F78BCD4D517412ULL, 0x013CE462A010517FULL, 0x6CCFD72DCCB7B319ULL, 
            0xC9174D5583242D93ULL, 0x16B48C652C0A8EE4ULL, 0x860481E77DCD4026ULL, 0xBF79F4C4C687DDD7ULL, 
            0x723D217854944476ULL, 0x3AA00C27D7575EECULL, 0xE032669C63F01CF8ULL, 0x729058D41FCBCF33ULL, 
            0xF11FF5E4DBF13FA0ULL, 0xD3458E556737B0F9ULL, 0xAB041EE1DD60DEB8ULL, 0x365E144025046022ULL
        },
        {
            0x2F721FC64D6A911FULL, 0xED20FD7CD7803EB8ULL, 0x8D81A97E42EAC135ULL, 0x3971281B0A24BBADULL, 
            0x51C2EE76AB79C622ULL, 0xCC6495AC80AFD6FAULL, 0x3104679DB7235E48ULL, 0xFAF7329471185546ULL, 
            0xBF08FF512BDFD5C8ULL, 0x8DCD7CD74004FCC6ULL, 0x1B2AC913B9D775EBULL, 0xAC48D2EB2547D9CCULL, 
            0xED967FF5ED0A3702ULL, 0x734BC999B7F365E5ULL, 0x27BF2F5B7E77AAA8ULL, 0xED8AC544A3514E0AULL, 
            0xA4A87EE89DDACD9CULL, 0xA658ABAF6BC50694ULL, 0xD5D02535D24C0AC2ULL, 0xF2F965963F6EF540ULL, 
            0x3B6CB9F5BFEE1EFDULL, 0xE0720F29FA237094ULL, 0xDF6CA2F783E07421ULL, 0x013C5548F616E853ULL, 
            0x2DD5C4D48CC750CAULL, 0xAB63F2AF2A2C0EEDULL, 0x825566F15E1C98D4ULL, 0xFF6544D46E772828ULL, 
            0x4AC747348BEE49A5ULL, 0x7424BE1740DAA626ULL, 0xB636D1A6D1E50E59ULL, 0xBDD06838B1985EBBULL
        },
        {
            0x623DA33D926B670EULL, 0x27F1255C77C2119EULL, 0xBB3D293E7D84CA4AULL, 0x2843961A66C07609ULL, 
            0x5739963953B31287ULL, 0x2B037180B16D2073ULL, 0x4BF0347D1C40EA1AULL, 0x993EDA9A186EDD3DULL, 
            0x5C66CBBB0828A327ULL, 0x823B41132872A992ULL, 0xD1105853CE82B23BULL, 0xFD53EB2C208F6688ULL, 
            0x6BB40E3CFC28B878ULL, 0x6F2B2F8A5D91D52BULL, 0xD1F1C94D2296D40DULL, 0x26732DD9213942D8ULL, 
            0x31910D7F6E738943ULL, 0x507FAAC4B1A3D7BFULL, 0x3437E254FEBFA335ULL, 0xD2F569BD2A32BBD2ULL, 
            0xC47F72BDBD7DF46AULL, 0x52F81B3B48F094ECULL, 0xFDBCA0A296075616ULL, 0xA3D41E9B20AD48F0ULL, 
            0x28EF55D6ED1750F3ULL, 0x3AC47064CFCBBF91ULL, 0xF8495BF98C6C270AULL, 0xB0DED971F249D769ULL, 
            0x88C1FD0995E4077DULL, 0xB18EEBAA29F6F93EULL, 0x1986B9D19C457698ULL, 0xB03F065FAF119D4AULL
        },
        {
            0xFE11FE724558C221ULL, 0xD45D3A9B6009053EULL, 0x18798A865C34DD54ULL, 0x19BAF7C77C2048FDULL, 
            0x2DD30E94BAB0A848ULL, 0xE88818B1D2DBB049ULL, 0x7545FFFAA5FBC3D7ULL, 0x3D40E5BE23487801ULL, 
            0x8A82C869EBC85671ULL, 0xBF15391DC54179A1ULL, 0xA83E4590C40AA519ULL, 0xC213F9B66584AD86ULL, 
            0xFF6DAC9608B40574ULL, 0xED55DC71D5CD3913ULL, 0xC558A0B0644D57BBULL, 0x2AC4834DEF9E0144ULL, 
            0x73B643E518A6B6E5ULL, 0xCC2B24014574E3F9ULL, 0x273F54E5C1F8BF10ULL, 0x0E54EA3234BB6382ULL, 
            0x718207712CD8063BULL, 0xFBCBCC8453F85377ULL, 0x976BA32898EB3410ULL, 0xF4958179419BA2FEULL, 
            0x40BF310749548288ULL, 0xB37606F8B8C9BE64ULL, 0x3F0CD5D64A33EB9FULL, 0xF5C182127B06FB05ULL, 
            0x4DF56DA806F07ABDULL, 0x248E04DCBC559E3FULL, 0x82F74136DA492E34ULL, 0x7B4C6C1739DA8FD8ULL
        },
        {
            0xA472D9213407184AULL, 0x881F2EF4604298A3ULL, 0x05FD6C561C6E6764ULL, 0x342EA7455D003976ULL, 
            0xEB759EAE946DE8EBULL, 0x92605F99398D86C2ULL, 0x33A45B2CC55AEC25ULL, 0xBE5A417F4A6622C1ULL, 
            0x0DB21DEE566B8738ULL, 0x41BC130E46D00312ULL, 0x28F538A5F3F97258ULL, 0x6B7FAADF7DD7080DULL, 
            0xE9848B0CCCBD685FULL, 0x523202A6DCA31E5EULL, 0xAE4ADBA490F88D74ULL, 0xAF808B5B97329922ULL, 
            0x39D0CC5B2D6BE529ULL, 0xEA72BA55F8FAD9C2ULL, 0x6A1AC0A37FF526DBULL, 0xF01EC295236054ACULL, 
            0x80B40D4E5C14B97AULL, 0xEE65E1DB7ABF3742ULL, 0x9F13397E28100DD9ULL, 0x3A35E795B07A3AE8ULL, 
            0xD06C74A599627284ULL, 0xF789C87E3E67AF97ULL, 0xC30605DC518CA7CEULL, 0xA383142FDFC5F3B6ULL, 
            0xDCDD39C575C3EC8CULL, 0x5CA29D068CB66D45ULL, 0x23058414BDB919D8ULL, 0x52B8516F6703F83CULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseFConstants = {
    0x25BC1FDA00B92623ULL,
    0x4D10EB514C0A2C7AULL,
    0x955B8FC1147E3473ULL,
    0x25BC1FDA00B92623ULL,
    0x4D10EB514C0A2C7AULL,
    0x955B8FC1147E3473ULL,
    0xBC33277B380BEDEAULL,
    0xA95F88EF1E07872BULL,
    0x44,
    0xFB,
    0xA8,
    0x02,
    0xF9,
    0x7B,
    0x40,
    0xCE
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseGSalts = {
    {
        {
            0xB4D5D8FE5E06C935ULL, 0xEF0FD68AA2EA8621ULL, 0xF986CCFC68F04416ULL, 0xEB4B7317F4E3D52FULL, 
            0x84BE605DAF7EB892ULL, 0xCE71317128465C80ULL, 0x6D315C453148C904ULL, 0xBE17760244637BD0ULL, 
            0x214795502159EFA8ULL, 0x13603947F8109DB2ULL, 0x1F7117A2FF23CEE4ULL, 0x6FB5D5A4763720FEULL, 
            0xA21BE4A4A3919D49ULL, 0x036959F7EFBAB4D3ULL, 0x0875239EF630BCF8ULL, 0x256BF05E20697763ULL, 
            0xDF25A1206A997FADULL, 0x3C547B8AF333215DULL, 0x15FCE874337712DFULL, 0x1229BB4F1CC3BF5CULL, 
            0xE81E69BBFE603D70ULL, 0x1DFAB51D6B0270E9ULL, 0x316EE7BA99723FB6ULL, 0x5B4E17C8CE115121ULL, 
            0x53C23F48F9221DB9ULL, 0x53221C457F5D4EF2ULL, 0x546228BB090D9E8DULL, 0x2F1BEDF173B6DC57ULL, 
            0x7B95612CE5B318DCULL, 0x2BB2386A5B82768FULL, 0x7D41749CDEB42E6CULL, 0x06EA53C5DD043539ULL
        },
        {
            0xB667731335B7957EULL, 0x7E6808D15D3EA75DULL, 0xE411FED4C65B213BULL, 0xBA07111A70B433CEULL, 
            0xF3488ADF401D7218ULL, 0xF480765990A64E61ULL, 0xE1BE6200463DFA3DULL, 0x1FD0069F002BF142ULL, 
            0xD3F7D4E0673F922FULL, 0x49F8212453BEF575ULL, 0x59675C947AC328B0ULL, 0x7BDD4D93EF578460ULL, 
            0x5450B7EB8E64D5B8ULL, 0x9909B295C35EC920ULL, 0x03E12D05A55B75C5ULL, 0x61BF99A0792779B2ULL, 
            0xA0013D60B8BEE473ULL, 0x1335D98532C8B200ULL, 0xEDF6B6240C55849EULL, 0x2B59DA46A8AC925CULL, 
            0x7AAAE9278D6E6650ULL, 0x90FF5A26618E817AULL, 0x3966BF5381CF20C2ULL, 0x20F27BCCAC1F65E9ULL, 
            0x707F920A8E40ADC4ULL, 0xA5A1024BC627027CULL, 0x9FB4C7E54A5C47BBULL, 0x41438BC1CEF6DDD8ULL, 
            0x75933C73F012BE8AULL, 0xFA62EAC5D06FD8F6ULL, 0x2B715361C4327629ULL, 0xE0731707D759574CULL
        },
        {
            0xBBB8A6CEA4E5A88EULL, 0x2362425453DE56CCULL, 0x9C7D457BFF2E61FAULL, 0x011AE3B1BF21207FULL, 
            0xDB4D138CFAA66860ULL, 0xB6D4D055D4988E96ULL, 0x3590873E15BE524DULL, 0x832B999D7A8197ECULL, 
            0x6EAA4A9FEAD97721ULL, 0x431180B746E7633FULL, 0xF916AB56D1D540B7ULL, 0xB4335A589279865EULL, 
            0x03872C1E58772F6EULL, 0x1AB5DA1BFE6D6411ULL, 0x59DAA8F8AAB5A565ULL, 0x8A82B9EF2D992D1DULL, 
            0x681F1C5C7C51A3E0ULL, 0xAB472B240C353102ULL, 0xCA70B65760D3A0E5ULL, 0xF67FCCC7A5C9A343ULL, 
            0x0B49A4CDD94AB616ULL, 0xF2629E8E7494C525ULL, 0x1980C758A649A57AULL, 0xE8E465B3D68419C8ULL, 
            0x413D37864EF1A08EULL, 0xD57CF17C752D4F67ULL, 0x862C026E407E85F5ULL, 0x031D20775BB86223ULL, 
            0x24B841120E2B59CFULL, 0xCE34DAA92D76367DULL, 0x65DF65A232EF67E7ULL, 0xAC6D973667617FAAULL
        },
        {
            0x7437DBF933415434ULL, 0x4BAFC50BB5510CBCULL, 0xBD7C19EDF3D056E8ULL, 0x21F8304A242022EEULL, 
            0x344F9A02C89DAD91ULL, 0xBA712539C835F7CDULL, 0x8F68E5245A2AACEAULL, 0x55A6EFC70B185B25ULL, 
            0x42F46BD6BAC66BA3ULL, 0x8EA266D035E097BFULL, 0x3D118499F9CA8433ULL, 0xD5882683F4537230ULL, 
            0x1616706E061B0F02ULL, 0x857A41457441BAE0ULL, 0xA6114F3BBAC9362FULL, 0xFDF3E075D6AEC302ULL, 
            0x50962F319A0B0AD5ULL, 0x5E45D73B5D18A5AEULL, 0x47EBEBAA104246A8ULL, 0x473524EA70378BF0ULL, 
            0xFBBEEA06B7713A31ULL, 0x6C93727DC7769C0AULL, 0x16BABDDD116C37EFULL, 0x40EACF8A3724892CULL, 
            0x81048D95E2A6F216ULL, 0xE7C8F91EACAAC739ULL, 0x847AFD29EA733B85ULL, 0x0A57537FA5663F49ULL, 
            0x41C302A27D022EE6ULL, 0x68EE0C2BE903DB2BULL, 0xB028B93897260264ULL, 0x8797E6C2E0143F52ULL
        },
        {
            0x701E57128C0B8DDBULL, 0xF5BE6CB6830AC767ULL, 0x7C6FBABD76592881ULL, 0xA2A66A4527E965D2ULL, 
            0xE2D76315FD253CE7ULL, 0x77A94CEEDD28F672ULL, 0x79A5C0623ED0ED25ULL, 0xFAB2CE2E1F1E237BULL, 
            0x4B8B984CB1269705ULL, 0x8FC9D0CA13782BA6ULL, 0xA1B8F1E57AAC4695ULL, 0x17A02BCA7A7E9E15ULL, 
            0x79AFBFDD12F7FD61ULL, 0xBBF13D96C0165E02ULL, 0x848851E39512C9C0ULL, 0x5D4A36AE7EB62B29ULL, 
            0xFCF7D77362A69AC3ULL, 0x5040F5BA3CE09808ULL, 0xCF3BFB6920A9E8D3ULL, 0x4E92DC99001CF211ULL, 
            0x662286D20D16C637ULL, 0x7EE79D79FB72BC98ULL, 0x816C67C78A00F9F5ULL, 0x8AC6571BD7D2EFD8ULL, 
            0xC89835A417B33FB6ULL, 0x61972A9117647B53ULL, 0x4E2D522430D2B5A3ULL, 0x605AF86672544849ULL, 
            0x37D3B059A49D084FULL, 0xB06FF09AD3B7FE58ULL, 0x1A8247714B4F3935ULL, 0x589C38024FBB94DEULL
        },
        {
            0xDA59556CE07A9686ULL, 0x4849CCEEA91F2C31ULL, 0xF34DED2BF063FAF4ULL, 0x308BF2C20FDDC06AULL, 
            0x6BF85CFE2DFCD4ABULL, 0x803B02F0BD59CA5EULL, 0xA36D22663308EDF9ULL, 0x3D3F9EF1440807ECULL, 
            0x7E93C4A64770A11EULL, 0x6D3C43F645D66296ULL, 0x418393A3C9170550ULL, 0xCA643A936FDF32EBULL, 
            0x88617C1F4ADC9D43ULL, 0x5F107640AA04B3E9ULL, 0xB6E5D8D8E5CEE3F8ULL, 0xB98873DEB270E343ULL, 
            0x8E3AF01D6176FA0EULL, 0xC2B849B160CEFCA4ULL, 0xF1B33F4BD82EFC14ULL, 0x702E30937360BC1EULL, 
            0x38A88726DA9F6997ULL, 0x6A9CC2FEDC6382E4ULL, 0xA335A4735F3CF912ULL, 0xBFBE8AE0C0470C01ULL, 
            0x6E3EFDA9B78E300AULL, 0xC56E6382005ED5EAULL, 0x85FB5EFB6716F2C2ULL, 0x8208131CF62FA926ULL, 
            0x17AB5E68290079ABULL, 0x2B0209F399F5F4FFULL, 0xA046F7DC6708E9CAULL, 0x65303DBE792EB82EULL
        }
    },
    {
        {
            0xCAC732CD05386A88ULL, 0xF249C1F9D50FDDC6ULL, 0xF6000DB8AF11A98AULL, 0x2603684394FED3EFULL, 
            0xFD43399F91CD2AFAULL, 0x4AC307CE3B3956E9ULL, 0x58D59EFB7A0527DBULL, 0x39AEE68B06AA918FULL, 
            0x3FDAFDB3F607403FULL, 0xC8ABC1FE00F99D4EULL, 0x42C5CE5FC0FE0D78ULL, 0x750DBBB1BFB1A8E4ULL, 
            0x16C4AC409D69350BULL, 0x63688578E6CEA754ULL, 0x5190DAAF1C374555ULL, 0x7848D98CA379341EULL, 
            0x308791BD2A36D8B2ULL, 0x6B6B3659526D1944ULL, 0xC18440D7EC933CF1ULL, 0x700A226082E14982ULL, 
            0xB92694641989AFDAULL, 0x741BBB0172BEDBDEULL, 0x4C015E22B9232697ULL, 0x4AE89AB9C51E4CA4ULL, 
            0x854461E7F3B1EAFFULL, 0x55BE7EABC34FF323ULL, 0xEB36E0C6AD1697D6ULL, 0x421CE1F481A23056ULL, 
            0xE79B96CAFF7686C3ULL, 0xC8EFAA257113E9E7ULL, 0xA8C8B900BEA00514ULL, 0x0AC0BD5509881899ULL
        },
        {
            0x0DEDF3FC79C854F5ULL, 0xFABB883A1F389541ULL, 0xCE2D4F1A4D3E5523ULL, 0x002F94274A6EDF2CULL, 
            0x57BAC96A21CAC868ULL, 0xA40F0977C3AAFD44ULL, 0xFB7B99082C0E33FCULL, 0x99A5F8DB4EE96601ULL, 
            0xFEE10F1FF00CF406ULL, 0x7799D6C1C3581B84ULL, 0x9D4DBFA30934B45FULL, 0xE278A35338C376EBULL, 
            0xF1C1AC7EDE201F7FULL, 0x79F7D83EEBE1AD70ULL, 0x640313910ED3F97DULL, 0x50934D430337A896ULL, 
            0xCB03454B7AA9FC37ULL, 0x0D1D11C007E94822ULL, 0x0B7CB0A4E50DB609ULL, 0xF7DBFAFEEA19876BULL, 
            0x2C1C96EFA6D5D3D2ULL, 0x66BFE103FE3C2776ULL, 0x2D2C498FE1074623ULL, 0x64962A535563A0EAULL, 
            0x7027E11FDCDE53EAULL, 0x2D8CA121C1F6FE81ULL, 0x2F7574342A82FC17ULL, 0x2A1017E1F6299BF2ULL, 
            0xAD8310B6227308B8ULL, 0xA4EB7F0E6B57E493ULL, 0x9FA2DC28715DA726ULL, 0x2621E1912606346EULL
        },
        {
            0xE1693E66CC50CD70ULL, 0xFB5007BEA265300EULL, 0x2D566FB7C4F52951ULL, 0xC87B97B18483FCAEULL, 
            0x8774C4D926F3DA5AULL, 0x72DF87C5301A3521ULL, 0x576FC4B79692A16DULL, 0xC5E47085CB616CE1ULL, 
            0xFD32E26D798D4F6CULL, 0xD3FCE96204A813ACULL, 0x2606DB2B0A49EFA9ULL, 0x26243F33E2D7CD69ULL, 
            0xE5103E2F7219274CULL, 0xD6C17E067A579D2EULL, 0xB75106B4676387A6ULL, 0x337A9FE9DF314DA0ULL, 
            0xA397143C684E9973ULL, 0xE0C01E147A6FC469ULL, 0xB38AC92E8F747E02ULL, 0x65C1D6D256A2AB45ULL, 
            0x8F19F557F48E4F0FULL, 0xA4943BAA53584384ULL, 0xA2EE306B36A02705ULL, 0xCCA3C5D4B0963E13ULL, 
            0x2503E01DDA922A7EULL, 0x87034195B297A25FULL, 0x41ED10A9A4B7BDF1ULL, 0xA9C1121F80042C97ULL, 
            0xCDA230777273476EULL, 0x90335F7CC72D5B88ULL, 0x39B3C9A51BE1A099ULL, 0xEEEC9440DF3E4E4DULL
        },
        {
            0x3464709E4F8FADF3ULL, 0x54E965DC49AC0F82ULL, 0x74CB32584B20BBE7ULL, 0x8E3A3FFA825C04FBULL, 
            0x439D9DC80FBF5355ULL, 0xBCDE51517C9918D0ULL, 0x53BCC4E37479C06DULL, 0xF522F567610BDCD3ULL, 
            0xDE69E8A4272ACBA8ULL, 0xCCDBCDA7D358A4E0ULL, 0x6C62CCFA60AD8B12ULL, 0xD738CF1E583DAA96ULL, 
            0x604560A72B676599ULL, 0x28B9416C3BAE319AULL, 0x513B9C68D5CF1813ULL, 0x0F364C5834A292DCULL, 
            0xAC4EB49BDAE7CE2EULL, 0x80C1B2685412BDB6ULL, 0x853030148B4D01AAULL, 0xD50FF00789C6CAC7ULL, 
            0x0A69FA840F45513DULL, 0x25AF9AAE8B1FF671ULL, 0x13357E4E817BDE1CULL, 0x4A03EB518EC81631ULL, 
            0x594ED8A33F38367EULL, 0x8ACEAC3D99C60BB7ULL, 0x73925506696D7463ULL, 0x6DFF92DE999B3CE1ULL, 
            0x94EA47C9F65A8E46ULL, 0x5773DB18E247FAA5ULL, 0x47EE18F6D715BE07ULL, 0x3F865B7FE06C3E86ULL
        },
        {
            0x195A88651D56BC06ULL, 0x9CD56577F6AB3FEDULL, 0x30763330D0D09AB7ULL, 0x041C689EC9EE9F8FULL, 
            0x039DF128E7395374ULL, 0x836250CD6E994726ULL, 0xD912F0F17F90DC92ULL, 0xD74745FA6F674B81ULL, 
            0xE448C63589CA8BDDULL, 0x3B12338977CC4394ULL, 0x5A7815BBB783714AULL, 0xB5546D59460306ACULL, 
            0x4E7046F64626C98FULL, 0x3A093436795F881AULL, 0xA63543101617EFE0ULL, 0xABE9D5880670C92BULL, 
            0xC43D4A6A40EC106EULL, 0x9BBFA35DB610EC34ULL, 0xFC5F4610C1D0B674ULL, 0x222790055A1CE6D4ULL, 
            0xB31319C45BE1AA5FULL, 0x4E929CDCFEBEC77DULL, 0xE8012C43EE4E1CECULL, 0xA2FEC467A213BD0AULL, 
            0x4B567B5C6F8D4989ULL, 0xC7D226EB39FA625DULL, 0xCE0964B197A53595ULL, 0x7430BB93242D7727ULL, 
            0x80AE9FAACAD908FEULL, 0x1447170640D34AC2ULL, 0x89E1ED33E12ABD53ULL, 0x441B980F20D9A75DULL
        },
        {
            0xA1DF3FC09F5AF714ULL, 0x46BFE8F16B00A392ULL, 0xF6D915B0D6F9DC5EULL, 0x1997BF3BF0D0C47BULL, 
            0xA1E2A15FBFD09124ULL, 0x5C8CDA85EB72B2B2ULL, 0x65FB0947DB3D8849ULL, 0x560940468E0A3065ULL, 
            0xE7DFB445299F1803ULL, 0x12867D4FE7DC34A0ULL, 0x4B84E38558BDB516ULL, 0x8CB6F2EB31BFA3CAULL, 
            0xAEB5264719F12B71ULL, 0x3632F9E0167B0357ULL, 0x02575648521B4275ULL, 0xEACE0DBF15AB8EB2ULL, 
            0xDAEAF221488E13F4ULL, 0xA9193ECB18465FCDULL, 0x771565A9532DA59BULL, 0x69E50A188934CE2DULL, 
            0x208D544AC6B17580ULL, 0xA0846708C097ECB0ULL, 0xD216BDB383ED92ABULL, 0x0C15D9994E60F88CULL, 
            0xC6F065307D839170ULL, 0xC74D49AF1EEF4481ULL, 0xB425A8D6038A4037ULL, 0x5EC73E4A517493C0ULL, 
            0x1628FE9EFDA1C72AULL, 0xDE4F371524A2F77DULL, 0xB2C7B961909D736DULL, 0x76C6D9BC3BA13736ULL
        }
    },
    {
        {
            0xB66069B364A8CCBBULL, 0xF99C2C157E2FCB68ULL, 0x18D0572766541483ULL, 0xD0FF989A462AEAFAULL, 
            0xA33A705872796468ULL, 0xEA11C2CC296648A5ULL, 0x698C73D03E040BE9ULL, 0x166FD7230345A895ULL, 
            0xF43137616F0FDB52ULL, 0xBD07AB5337917BF2ULL, 0x6F85CFECFC388750ULL, 0x7B3BEBC3D3E0DF6CULL, 
            0x3046834B12CC1AFDULL, 0x30405C791C6B45F8ULL, 0xC656D8680BEA306BULL, 0x618794B9EE1A243FULL, 
            0x054D36F99CCAFE51ULL, 0x8315A21E814FE76AULL, 0x07A00B688C8EFC75ULL, 0xA30609F6B6AE905DULL, 
            0xE5448BE7A8983DD7ULL, 0x6848999F377DCDA7ULL, 0x4949FCDE5C974DD8ULL, 0x3AE4D6358F844C3EULL, 
            0x05BEB28DBABD9879ULL, 0x15B50025E6A6C007ULL, 0xCC252951F18AE923ULL, 0x168A46F13E80926FULL, 
            0xB03D508ACD91D759ULL, 0xC285382703BE5140ULL, 0x0482EB6770CF40F1ULL, 0x9515B3A6AA8F278DULL
        },
        {
            0x6BB65F5C9EFBF449ULL, 0x616ED61918C7DA9EULL, 0x4C4F0C5DC50D0231ULL, 0xA685E2B763A8C167ULL, 
            0x604D0D7B6D489E5DULL, 0xE83D76FD429BF294ULL, 0xD7697B51E57BA0ABULL, 0xA6DBE58C2C449C7CULL, 
            0xC7D03899E0054F41ULL, 0x7CB7636D83971BC2ULL, 0x2AEDA8B78B2CED16ULL, 0xD8195853BD089054ULL, 
            0x3D416E464094878CULL, 0x1DADD83A080962A4ULL, 0x4738B0C1ADEE112EULL, 0xF9F08CB90105A5F5ULL, 
            0x095E685D6D0453D4ULL, 0x285F41C951682328ULL, 0x5349B9751A2E4090ULL, 0x57D83FB2FBCC02E5ULL, 
            0x3C2AA89859FA7A5DULL, 0x301EFC85108D2D7CULL, 0xEAF6DA18D8BF4D9FULL, 0x099385C6EAFF433CULL, 
            0xC9E91CCE3B77000AULL, 0x771AB93C00077F60ULL, 0xD4491BDA97D3FC8FULL, 0xCE8ADBD37B4EA76BULL, 
            0x3BB589AA03728912ULL, 0xCB4AED201693FBEFULL, 0x90821BEDF38E7D2EULL, 0x7C6937E6E9A6FBA7ULL
        },
        {
            0xDF49173021E2F9B1ULL, 0x1911C93292AEED09ULL, 0x255F3E0AAD292899ULL, 0x532052C0B7F7DF94ULL, 
            0x7A754FB5978E3CFBULL, 0x16F55A9737912298ULL, 0x5ED8B925A13C4B59ULL, 0x3E4DAD18B64E5AEFULL, 
            0xCC4750FB5379E2F0ULL, 0x72A16BC615DE5A76ULL, 0x8C21032039CB02CAULL, 0xC10F5E60754B14ABULL, 
            0x3DF5AF1F2C5D6FE8ULL, 0x6C75DD451ECD7305ULL, 0x9F3DD076F069B775ULL, 0xF61EE331746F59D6ULL, 
            0x32355AFD543B3A5EULL, 0x79CCEB5DC1F0BCDFULL, 0x07C8CA1435073086ULL, 0x86925EE6A9EC6C3EULL, 
            0xFE390C575CB5FDDEULL, 0xF3425A325103A7A0ULL, 0x8E538FBCC9016C6EULL, 0x5BC09709F9978F53ULL, 
            0xFD072DD8019FC8DAULL, 0x252A211C8ABCCFC3ULL, 0xE5687355E0A7E4D3ULL, 0xD675B0007779F96EULL, 
            0xCFC6EEB1F8659946ULL, 0x00D16B4BB921E10BULL, 0xC4A5D454173D55B5ULL, 0x5BD0EB0977825FE3ULL
        },
        {
            0x0ABB6F53CDFAF86EULL, 0xF99FEA76D30564CEULL, 0x83CA424A76B71777ULL, 0x4DC33945A90C2523ULL, 
            0x4962BF419FACF2BAULL, 0x34CDF9B1AA57C3FDULL, 0x0B098F114D465187ULL, 0x7EBC8BD4EE11A853ULL, 
            0x321A581996F89945ULL, 0xAA5957EBC315EA5BULL, 0x184D1A1F0923F26CULL, 0xBDF455FD3E8DB1D1ULL, 
            0xE92FCA739FA7621DULL, 0x2226A1B51BC8D13FULL, 0x5A8D748151045D7FULL, 0xC59A72A3981E24DEULL, 
            0x5E054B47A03115A9ULL, 0x4D614F621B2F85EDULL, 0x2733B46B4116068AULL, 0x8AF8BBE2E00E98CAULL, 
            0x8C0BE1EE5CF1915CULL, 0x27B9A9A484E9C4EFULL, 0x4D111844543E872EULL, 0x8824E1F26A4116A4ULL, 
            0x24CAD524BC171BBAULL, 0x9EA3D0528A30483BULL, 0xE3C6EF6B8C830866ULL, 0x852D6334E81B0C1FULL, 
            0xB54989F7B3C375EEULL, 0x96B5ABF735E802BDULL, 0x92CE496470B99C88ULL, 0x0152A53C476E316EULL
        },
        {
            0x2513E7C907BF9C4AULL, 0x01889F9B9B758476ULL, 0xFCA502A82A0A70A8ULL, 0x7353DAC2C158DAF0ULL, 
            0x55211617C8E49CEFULL, 0xE979A0457113295FULL, 0xBB7FB6B1D08D87FCULL, 0x8253BAE957FC2667ULL, 
            0x6CAC411DAF435389ULL, 0xFA567CDED07F2DA8ULL, 0x194669D9DD983578ULL, 0x2E4EAFAF80828CDBULL, 
            0xC5AB8CB2933B973FULL, 0xAD3433CE0D36D2AEULL, 0xFC7433545F222AD5ULL, 0x8A25040FE16C93DEULL, 
            0xD94B7FD35B1199E8ULL, 0x5DE2008657D08905ULL, 0x5B668C8002CEB5AFULL, 0xD10690F9E85F1CA0ULL, 
            0x28041DA2D80C5D92ULL, 0x105594A8512E02AFULL, 0x5822271F6E551B71ULL, 0x4F40679A1C5BBC8CULL, 
            0x228A6476EB79F26EULL, 0x4ACC2E47BE962525ULL, 0x637B82E40F3A2926ULL, 0xDDDCDBC10C5E07AFULL, 
            0x237314261A447659ULL, 0xAAD9EFC5A2CD2F18ULL, 0xB0FD6739A7976A02ULL, 0x2E529F363DB9F45CULL
        },
        {
            0x68A0CBE7E8E2F69EULL, 0x2066C07FCA2ADE59ULL, 0xCBD96CE4AA77712AULL, 0x16608D94AA9D77ACULL, 
            0x67C0CB6C79CD96AFULL, 0xEC44CCE0F09B9A47ULL, 0x1ABCE9398CA65890ULL, 0x3FA9C20B223B40B9ULL, 
            0x716868444FA596E1ULL, 0xF37EAC0F7AB131F8ULL, 0x5E055E2803D7DC07ULL, 0x20EEE8E45DB96C3EULL, 
            0x5A45D20B87AF57FCULL, 0x22DA388969340AD9ULL, 0x3CFC09EA5688BD09ULL, 0xB73DAD6852A72B6CULL, 
            0xBF1620C13B1088E7ULL, 0xD501C3F0F5695084ULL, 0x90E3A1713DBF3F2BULL, 0x2124D9A3C2600253ULL, 
            0x879A8C9F9DF25FB1ULL, 0x4168B34D86CCDDD3ULL, 0x19FC6EF94F3DCB79ULL, 0xF9F73C8BDA9F0B48ULL, 
            0x06E0226098A70B86ULL, 0x0E87CC3F32F0156BULL, 0x409CE065C5A0445AULL, 0x81967721E70800B9ULL, 
            0x07561B1835BB68E6ULL, 0xF372ACCE9E30F221ULL, 0xF524B38BB056D1BCULL, 0xA27E2FD8A078162DULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseGConstants = {
    0x0D45C45C960EA647ULL,
    0x72220EB901A77DF5ULL,
    0xFFC4818C3B890F53ULL,
    0x0D45C45C960EA647ULL,
    0x72220EB901A77DF5ULL,
    0xFFC4818C3B890F53ULL,
    0x1069197A2DF1D0D9ULL,
    0x747640E4FA39E4D0ULL,
    0x0E,
    0xC6,
    0xF8,
    0x65,
    0xCD,
    0x95,
    0x2C,
    0xB3
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseHSalts = {
    {
        {
            0x847AB10378D76B97ULL, 0x5D95BA853E590B5DULL, 0xE466F001E166B01BULL, 0x762251BDA18F9374ULL, 
            0x47CD5CBCF34CCB13ULL, 0x63F0EAADBABC1338ULL, 0x40C4BDB09931EF12ULL, 0xEBA8FA61378D13A7ULL, 
            0xC5C98A624F521A67ULL, 0x2B9BB184A90B14A0ULL, 0x3CED30F22877B9FDULL, 0x80E0495D9AAA618DULL, 
            0xDDFF75FDEAFE282CULL, 0x30EB98465945704BULL, 0x2653E147451D1DB3ULL, 0xA63CB5C616DEDBFFULL, 
            0xBEC6EAC4695AA363ULL, 0xBDC84C04E36219CBULL, 0x1F37404861BA8A0BULL, 0x8DC4D083F1D22CBCULL, 
            0xFA50F4FE1F5839B8ULL, 0xFBFDB3F7C95EFF9CULL, 0x5D0B8ADEBCE24F40ULL, 0xAD3D26FF8BD1A615ULL, 
            0xE3744FB7BE671C64ULL, 0xF91B6663FDA51B4AULL, 0xB1A30DE6EF856BE3ULL, 0x51EE5B1E157C27BCULL, 
            0x3D7F921787A875CAULL, 0x2F1B44AD6008588EULL, 0x78C06B9ED3F2B702ULL, 0xFDDAA27947C42649ULL
        },
        {
            0x9A55B7C501DD8DEBULL, 0x14977DD0675079EEULL, 0x0E6C205CF551FDA8ULL, 0x1D1E539DC292F8F5ULL, 
            0x57936A16C8E9CC31ULL, 0xD15CE3B2381ED98CULL, 0xC6DF2444A62FF2D1ULL, 0x5DD6BA7DEE72974DULL, 
            0x927409D844B6DC8AULL, 0x0F0F5D12867B177DULL, 0x59292B204AA5527FULL, 0x1C43CCD7567796DEULL, 
            0x2DD89A4EB3241AD7ULL, 0x8B3A91AD6A873286ULL, 0xB9654C9DFD7F58FBULL, 0x500A7D1BC68495C2ULL, 
            0x72053FCA6FA01197ULL, 0x4C7497C9C6736DF3ULL, 0x876206FCF658B9A7ULL, 0xA0BB7AC2AA6ED213ULL, 
            0x344E187C57F38481ULL, 0x1F7955D69C6F301FULL, 0xFCFD1A2937533198ULL, 0xB725E8E2DC632633ULL, 
            0xF2C8DEE6176B10B6ULL, 0x4D00733E184D892FULL, 0x7ADF6AC9FF3C4877ULL, 0xFE8A4EA032CDDF0FULL, 
            0x3991527649B2221BULL, 0x1FF1DBE20BF07223ULL, 0xB7BDC9BDFB60675CULL, 0x9B34D5A3A13A292BULL
        },
        {
            0xDF07B6CB371364E3ULL, 0x7C5742A7EA13AFFFULL, 0xD4B5FBC85CD2CEEAULL, 0x94EB7469B753ADC9ULL, 
            0xAA50F2AFBAF6390FULL, 0xE1FE25A111F16B2DULL, 0xFC7373F69E60163FULL, 0x89B5D53A4B38B231ULL, 
            0xB7F1872A496B22AFULL, 0xB5AB4A24C67124ACULL, 0xE2F086E70C30E6B9ULL, 0x520818DC616B5BD4ULL, 
            0x2200284B279EFE1FULL, 0x587006D603157FACULL, 0xAFB53940E2C88A46ULL, 0x47A51C27827A254DULL, 
            0xB67EBF3C4658ED59ULL, 0xC083EF165C033E88ULL, 0x897DD6A6D4FEDFABULL, 0x8E4CA58A2D68D749ULL, 
            0x685B075D869F377DULL, 0x18131814ACB0EC18ULL, 0xFFBA7F41E24A4FC5ULL, 0x80826A3EC4D516D2ULL, 
            0xDBABBEA51E3D4F3BULL, 0xF01E33CD9CDBD822ULL, 0xFCDD8F149E4926BCULL, 0x8A6228D37F3650D9ULL, 
            0x40F4AEA72B9C173FULL, 0x8915D69DCC464112ULL, 0xF6FB27AC7859E8F2ULL, 0x50E77748ED2F202FULL
        },
        {
            0xE22552D4DC8089E6ULL, 0x173B0A1ABA5D0A23ULL, 0x63BE23BFD240AA7FULL, 0x678DEDDD8136E779ULL, 
            0x500786DA23CCA6CBULL, 0x618FA2631247258FULL, 0xB6A9521E4A7CA9E9ULL, 0x7FB402F03A17869CULL, 
            0xFDDE37141D220C75ULL, 0x112BC7E1590007D4ULL, 0x5B0379B54E1AFE7BULL, 0x99A58A6AEFD908A8ULL, 
            0x681C0A42FEB97F84ULL, 0xE5F9F0BD1212146AULL, 0x90B96FFE851AA741ULL, 0x50D98B25D390C363ULL, 
            0x9CFA02EFB30BD707ULL, 0xB483D235BA3B934AULL, 0xA9C2184F017A42ECULL, 0x67E762ACFB6A8334ULL, 
            0x085AD8F77876633FULL, 0x6E50CD875F33F02CULL, 0x3B79D45F7D950B41ULL, 0x07A1CDB44D8B1DB0ULL, 
            0xEB8E85743ADB759EULL, 0x5ED8CB045175A1C4ULL, 0x5B1032B398A51AB6ULL, 0xA7F5B4029662A365ULL, 
            0x18E18DF5CADCB146ULL, 0x0458B05048C461A8ULL, 0x05C5EFC0DFC80F12ULL, 0x3167E986E5BC35C3ULL
        },
        {
            0x34A6B2BFCC559A6CULL, 0x5D45D184E88F5063ULL, 0xCFC41B518B47691FULL, 0xC72073FD21CAE34BULL, 
            0xCBEEF753BB157B0AULL, 0x78CD3C6EF8575B8BULL, 0x576E5EB51C75F57FULL, 0xEC034D18EA5E3D0FULL, 
            0x8A6338CA48618C02ULL, 0x6A424E99BD617421ULL, 0x5813C2E2DFEA749BULL, 0xACD7BA8DC662AD96ULL, 
            0x5F9BC0A817947C02ULL, 0xE8BA772AEFCFCCAEULL, 0xFC78DEA04EF4AFA1ULL, 0x69491CB362083C50ULL, 
            0x76F9BA9B30AF8B9AULL, 0xB1123F2471674822ULL, 0xE854FDEBF07DBCFCULL, 0x106DF45CF686AF6DULL, 
            0x9579F540CBEE11E8ULL, 0x600322B6F9B056BCULL, 0x95D4B53B572A3A83ULL, 0x5320F316B7812F8CULL, 
            0x2B902DFEFE498EE0ULL, 0xCA2F1714D119AC02ULL, 0x2395762846B51DFEULL, 0x5E823013BAC29ADBULL, 
            0xA63AFC1B1D6100ADULL, 0xF75F936054D3DB19ULL, 0x22FF55DB25D1C67EULL, 0xC056DC60B649A0BCULL
        },
        {
            0xB9C5D4E87B07FC1EULL, 0x274524BC7770EEB3ULL, 0x42EC715C7483DA56ULL, 0x44D6938B7B5A5C2DULL, 
            0x596FA212E38F2625ULL, 0x4002E8FECA80164BULL, 0x35C5FD95A89FED39ULL, 0x4868DDE740B0ADF6ULL, 
            0xC77624227BD5F88CULL, 0x989FA5FBA5E3EADCULL, 0xC04F27B38F5B71DCULL, 0x1FB571D149D13260ULL, 
            0x79FC2F3D7CC63CBCULL, 0xF2CBE7D5D250212CULL, 0xF365591A2123997EULL, 0x2D963E6CD7DE24FCULL, 
            0x40957855335B232EULL, 0x49BAF0796EDFAEAEULL, 0x27AAD8054E31EDFCULL, 0x3D1C29B9FF6226FFULL, 
            0x9C56AF50C9A85822ULL, 0x60FF66FD943642A3ULL, 0x5456D0AF39E0D308ULL, 0xD1D2D102ADDE09C9ULL, 
            0x5FCDECC4701DF696ULL, 0x5619496BA7A55C1FULL, 0xE532B7266F776486ULL, 0x13612D7FD3095A6DULL, 
            0x7073BF0570B384B0ULL, 0x54D7EFABBCD20EC1ULL, 0x85B0614625D87789ULL, 0x81268646BB89A712ULL
        }
    },
    {
        {
            0x733124D22BF1145DULL, 0x45ADBDD50D35FFCAULL, 0xF87AC3374BDE8359ULL, 0xCDEC4DFAE9879D63ULL, 
            0x7D20DE44E18CD296ULL, 0x4131675135511129ULL, 0xAFCF01E798BAA672ULL, 0xE024E6DC80FB330AULL, 
            0xD28C2BD7D096C0D2ULL, 0xBAE5EF28F4E88285ULL, 0x3D6E1BDCDC51B2DBULL, 0x663A6EC95B58081DULL, 
            0xFCA270D7A8E018DFULL, 0xEE2CE45D9D2D1D65ULL, 0x0148EB35A4E874D5ULL, 0xAB37240D4F39580DULL, 
            0xC31D7BF4A55E7899ULL, 0x43D30AC9B197B6D2ULL, 0xB3FA6C188222BAFDULL, 0xE9CB6BF21593313BULL, 
            0xFD49401D5DC3058EULL, 0x786238005BE66F80ULL, 0x438C0EE2EAD71048ULL, 0x912B0CB9CC209A1BULL, 
            0x77FC98C8F11D316FULL, 0x01761F590D636150ULL, 0x8E456C79F26C34C3ULL, 0x594D10B97241085CULL, 
            0x3953F0AD24FDDD9BULL, 0x27F31480A0EAC941ULL, 0x444C02C3D6F31C1BULL, 0xBFB61E74186C0C85ULL
        },
        {
            0x689B9A4D1452DDC7ULL, 0x8121EC7B7C109FD0ULL, 0xF44F1E2506D17225ULL, 0xDC0E9F3A1FDB3A38ULL, 
            0x3A514CBE88BC2842ULL, 0xEB0BEFBE55D7DAC0ULL, 0xCE29D33EE47F7544ULL, 0xC9B0A5E46D495610ULL, 
            0x8DD3FFA817211BCFULL, 0xEC1BB584D719F922ULL, 0xF260CFA0319D94C3ULL, 0x74DD6EC992E58A3DULL, 
            0xC0425C492CC2D4BEULL, 0xEAD4EA58A06CB5A7ULL, 0xCB23E304134F9708ULL, 0x4E3889707DE60306ULL, 
            0x05E27F2A0AC3B475ULL, 0x28AEAD854FB5989CULL, 0x69B5ACC7FA9F4B13ULL, 0xF42B3BDCEC54D28FULL, 
            0x9317730CC19564A4ULL, 0xF902ED6436D8551FULL, 0x634BEDA07FCDDA8DULL, 0x65E6D615956CE18BULL, 
            0x21B574BC360DDDB5ULL, 0x9EA15723218BDC27ULL, 0x496FBB664F7A019FULL, 0xC70E2DE50410C032ULL, 
            0xA2ACC987A45002E0ULL, 0x62468699867E4A26ULL, 0x71FA6D3AE8E3B39AULL, 0xB2E8A5E39EAB69A9ULL
        },
        {
            0x42A47E9B12B1D855ULL, 0x196D988F115DE5E6ULL, 0x3B37AE515ED7FB3EULL, 0x5ECFDCFC01A77C3FULL, 
            0x35CBE8E570695F88ULL, 0x77E535C864F1E6F9ULL, 0xABF1DBB2CD5229DCULL, 0xB5CC32E77285482EULL, 
            0xC25C0E0AE2D405F4ULL, 0x3547285AE31072C0ULL, 0xA8C4F74A47B80DBFULL, 0x96FAEE53859C937BULL, 
            0x3D9DF9E3DE3749C6ULL, 0xC51B2255BA52FEBAULL, 0x6DBB8F04D6CC36D0ULL, 0xD27DFA4D0CA12B47ULL, 
            0x81001D5B4FA327FAULL, 0xFD543E6FDCFFB312ULL, 0xE68AA82C377D4898ULL, 0x67ED5137E59E6ABAULL, 
            0xAE9AD7F277E88B07ULL, 0x84433B220BC91E9AULL, 0xF0B0AF8123C08E5BULL, 0xEFD5E1E6404EF157ULL, 
            0xA8C9D780A8B6E8EDULL, 0xDAEB9102A9FDBAB7ULL, 0x609A7CAFD7EC7A33ULL, 0x7E63AB60AA25C920ULL, 
            0x22B02C790995A577ULL, 0x034177E68CEB361EULL, 0xFA9A88E7921CA378ULL, 0x1F458AC4D6D6568BULL
        },
        {
            0xD99E37AE2D8BECC3ULL, 0xE3B3457C669B1B50ULL, 0x976BBCAC027630A9ULL, 0xAAD03952C1D2AB01ULL, 
            0x27921AFE0318A77AULL, 0xB1093CFA3176EE59ULL, 0x123219FE15108C77ULL, 0x6949314BB841832BULL, 
            0xED94E87DFFF38E4DULL, 0xF523595E39FC34B5ULL, 0xBCB1AB0FD3D66850ULL, 0xDC92902BD11F97A7ULL, 
            0x54C4A65FFEE8BC98ULL, 0x9CBD19654DF57296ULL, 0x13ED9E2AF28B8233ULL, 0xB5DBECFFB5FDE1ABULL, 
            0xC715A8E6A480FD13ULL, 0xA8A701676C66BD5DULL, 0x00D66D67FFE24B9FULL, 0x89B4D360837C0065ULL, 
            0xD6B8581D4F41755CULL, 0xF7E0BD4F547AC302ULL, 0x0EEB50992CD41319ULL, 0x9EE36444C3B17F35ULL, 
            0xF33E3EA1DDFFE9ACULL, 0xE21F1C22804EBC4FULL, 0xF31BB6E33B66FD34ULL, 0x831F5F291C449A1EULL, 
            0x8F5DFB11385B7C1FULL, 0x9C56BF61589A85DFULL, 0xB720E3E895371FF3ULL, 0x6AD17E1849EF5126ULL
        },
        {
            0xDCBFC4B5DC81C0DCULL, 0x9D5EFCA8D8D0F663ULL, 0xD2DDDA92A16C6213ULL, 0xC8ABD0F1494C3933ULL, 
            0x1A5A810A9C74F894ULL, 0x53807D93F74004E7ULL, 0x48589EFDA9A478E2ULL, 0x4DA0D1DD1226EF2AULL, 
            0x30DFF8652FCFAE9BULL, 0xF6C9D904206BD45CULL, 0xF725A44AF1635D7FULL, 0x9C67DEFA51F9D11AULL, 
            0x6CA1266AFD07893CULL, 0x89E7553A86DE53ECULL, 0x23495670560B089FULL, 0xF2BA1494A8ED6A88ULL, 
            0xF79DC7B874E5DDE8ULL, 0x01372F9DC83FB567ULL, 0xECC7B4BB1D509607ULL, 0xFEBBCEA8DBEF81B2ULL, 
            0x4299EF6D869AD093ULL, 0xBD159B73498355C3ULL, 0x58E18F36B950037BULL, 0x39D5730E4E3D92B8ULL, 
            0x96C0C81E1D3EAB8AULL, 0xD5D3D093DC3159C8ULL, 0xB309359A1474B1D3ULL, 0x6534C2B8C187A869ULL, 
            0xD5F98167D113DBDBULL, 0x82456FDD3752C7F0ULL, 0x9F6D6F75434C93C8ULL, 0x5C655D19DB124BABULL
        },
        {
            0x549391C777AB6E57ULL, 0x1F2ADB952B0F7E1DULL, 0xE255C627BCB50C83ULL, 0x90AF0763C4572C91ULL, 
            0xC2177103B742EDE8ULL, 0xFE7810774AC69811ULL, 0xD48278A996A7CAF5ULL, 0x335088C11EF38EF9ULL, 
            0xDC51F560D0904F9BULL, 0xECE661EA95BA6C28ULL, 0xE7E22ACA6AB4A187ULL, 0x30733B4384233B8CULL, 
            0x10817CA64E51A9ACULL, 0x4007F761C4EC829FULL, 0x04DAFD290E369466ULL, 0x6220ED6C6521A76EULL, 
            0x6B97DCCC06649C5DULL, 0x1477821FCA365933ULL, 0xC6DE340C90A914EAULL, 0x4BE7C5F88A36F8C1ULL, 
            0x25949684043FF74CULL, 0x7AA335EB96E7448DULL, 0xDF1D493B0B3AA20FULL, 0x628C559121309E22ULL, 
            0x260E0B259AF80489ULL, 0x7A41838D3A52467BULL, 0x6903FCE33E15B170ULL, 0x1B3D55DC02370071ULL, 
            0xE402F26D5F3D226CULL, 0x670214E775792568ULL, 0xC15BE263BD8489DEULL, 0xD8E93DFA83085606ULL
        }
    },
    {
        {
            0x6673ECF8A22D9718ULL, 0x8D1E240AC5802FACULL, 0xE5BD0E72C770EFEFULL, 0x87F0A06E8D499C2FULL, 
            0x45202FDBB09607A4ULL, 0x2CBE61B918AFA91CULL, 0xA388FABFBD20E77EULL, 0x51640F23628C715CULL, 
            0x19AA0F3E7E75E928ULL, 0xD47EEB2CEFF347E4ULL, 0x0966B2052B9C6D70ULL, 0x4C2442F241FD37CEULL, 
            0xCA90DBC8797D580DULL, 0x79D0165A6B0D616DULL, 0xBB23C349ACC4CEC0ULL, 0xB0FCBBE93ABE916FULL, 
            0x7346E54F3B60C890ULL, 0x7B8BD366C73F5372ULL, 0x8D0BF4AC6E9DBF49ULL, 0xAF2A2CABA9CEEFD4ULL, 
            0xA76C4617576982DDULL, 0xC86CE4BC40F9F29FULL, 0x71C72D54874FC367ULL, 0x7B46B01E4DA8C7BBULL, 
            0x0E7FC1FD9DBF09CBULL, 0xDA6507F4A00AE0B5ULL, 0x6450FCDD317ADB39ULL, 0xE3C570D31189B98AULL, 
            0xA875AE051B2BCD2FULL, 0x12A24C94A73BCE22ULL, 0x509FE3A8BBABFE84ULL, 0x22C241AB9854093BULL
        },
        {
            0xFF1E6B3BAB50238DULL, 0x06FBEBE52039D80FULL, 0x87A78B51D72772D0ULL, 0x0CDF6B0CDAAED39AULL, 
            0xBC86797522D86157ULL, 0xBCA9379C69D63C8CULL, 0xF356CE2EF53D4EBAULL, 0x395BD3839A7F060BULL, 
            0x1564D4E9F9EC88B2ULL, 0x0621A361992E7BEEULL, 0x738FCA47C2CCDCCDULL, 0x50B1CB9DA8A08908ULL, 
            0x290D4C0EC9E88725ULL, 0x33E86EF4379B0A58ULL, 0x64F64763284900E1ULL, 0x64DCC8263CDA532EULL, 
            0xBC025A14A9B1C675ULL, 0x0F54ED353A5F5987ULL, 0x0CFE7604BAB42F17ULL, 0x3415A07C84F7D2FCULL, 
            0xEB1A3582A8969568ULL, 0xFC73E8A6B80A1717ULL, 0x9EB7ED0A39857FFFULL, 0x6799E75EEEC173EFULL, 
            0x046FA2C0014B2CD3ULL, 0x764DDEB9EA526D34ULL, 0xF28D1F3084FAD6E3ULL, 0x2661D8FCF32657CCULL, 
            0x662FB8164C015BECULL, 0x5F22D2665639EB95ULL, 0xC79FBF65F7D3AF6BULL, 0x0343F7EF2AE31499ULL
        },
        {
            0xEBAB8A08EA9A35D3ULL, 0xD77348639A0B19FBULL, 0xF2A72EEF9077ECB8ULL, 0xDF571AA2ACB2E113ULL, 
            0xF93ECC64F245EE3FULL, 0xEB378E51F48C2807ULL, 0x260770AA95FEAB5AULL, 0x5C984C343AEE2F41ULL, 
            0x96587B1AEFDF7FC9ULL, 0x5314BA6F06B1F026ULL, 0x7BC19A588505304DULL, 0xE9B4AF5E4EEACB1CULL, 
            0x7830A698FB8E80F8ULL, 0xB22A944F2E527A9EULL, 0x10599D71B5B8F2CEULL, 0xF6487FC885921E17ULL, 
            0x79A04DC0779340A6ULL, 0x46007C5BE5D89AC0ULL, 0x4421B4E08B4265D9ULL, 0x5DB05928C817E2F6ULL, 
            0xC58DE532D5906E3AULL, 0xFEDD104F8FB594A9ULL, 0x1CACBC04A0DC9943ULL, 0xE76D8CAB4B38AAA7ULL, 
            0xAA4A3149F39CF183ULL, 0xEABAE8DE123D18D2ULL, 0x4011AF4952DCEE89ULL, 0xD07E3BE201D8AB5FULL, 
            0x73960436CFE87461ULL, 0x9BAE838614F87A0CULL, 0x727B2873A105768EULL, 0xFCFBDB6B24BAB298ULL
        },
        {
            0xEF4BCF4C00327ED5ULL, 0x3272EDA087316E52ULL, 0x4D002CF48D9B38A7ULL, 0xFE1054507D17C113ULL, 
            0x2CA951E708582968ULL, 0x88E7927FA54C0D37ULL, 0x04B7F4813B41BCCEULL, 0xAE383DD7402192B6ULL, 
            0xADC830E2AABDEF34ULL, 0x053944BB1CF6C58BULL, 0x8B8980E4D7874DC8ULL, 0x96902DE02D3DCEBCULL, 
            0xABA8AFA172FC5B9DULL, 0x387D68E88F7E9A39ULL, 0x07A0F22EB6E4670AULL, 0xE3284C22971D633FULL, 
            0x30D64A47FE2DC64AULL, 0x63E36B19AEE00B62ULL, 0xECEB9107B00E532CULL, 0xED9A1C234A3BB293ULL, 
            0x1B6AD037D288C706ULL, 0xF1526EF9372580CEULL, 0xB485E5DE9AA69866ULL, 0x51562E604D667FB9ULL, 
            0x598B8F7FB9497E77ULL, 0xF622FC7A55A756EEULL, 0x34E13FE3C9447735ULL, 0xE002E265AF7D4656ULL, 
            0xF13E9FE6846DE2E4ULL, 0xCBD63894644ECF3CULL, 0xA121C96F53056953ULL, 0x39CC28F3C1F6701BULL
        },
        {
            0xD79C19DCDB54DACCULL, 0x3A4B46661E305DCFULL, 0x7C54D04FCDE11FFDULL, 0xD8681C0D0D6BF9D7ULL, 
            0x8580F6F8566F8AC8ULL, 0x5CB9842374E0934BULL, 0xF4E22F66EE51BF6FULL, 0xD7AD657F7EB1C00BULL, 
            0x0E927F68012695BAULL, 0x3F7B7F12860A2FADULL, 0x330543AE00FA09BCULL, 0x80FA167C6B9CA530ULL, 
            0xA14689BD36D6D920ULL, 0x4DC2EE6B6C013FE2ULL, 0xF1B2982D8142FA53ULL, 0xEB3A1F3F25A2ED70ULL, 
            0x0CAC820F421448F1ULL, 0xF8BD511323442E47ULL, 0xCD19CDA468B22FB2ULL, 0x97B84986D465DE33ULL, 
            0x476F34B675F4052DULL, 0x31A87565027CE21AULL, 0x1E550C2BE9818870ULL, 0x30E94562E5005576ULL, 
            0x8873121CAD1CA99AULL, 0xA8C5099DF34FE559ULL, 0x2C6B91E4573A62E3ULL, 0x1352AE13E655A428ULL, 
            0x8CAF356C5A943264ULL, 0xEB626A33C97E7FD9ULL, 0x773CBB2BF37C1242ULL, 0x723F64C5F6D8A71CULL
        },
        {
            0x1820347161504DC9ULL, 0x46631F811882BC13ULL, 0xE2B4F83EEEF0024FULL, 0xA53A9B6D09FED94EULL, 
            0x18AD42219F366497ULL, 0x6FFE7272277CDEC0ULL, 0x7E4F7377EBFBEC8BULL, 0x36EA5A70AEFCA1CEULL, 
            0xE9688DE4477E1537ULL, 0xADB9D89A4EC5F434ULL, 0x04F6DC53E69B19FEULL, 0x5B5629A189513F43ULL, 
            0x70C509D17DD04EB9ULL, 0x35435F25FE2906B4ULL, 0xD5319B0AF6A35C5AULL, 0x60EFB5DBA89AE484ULL, 
            0xBEB6EEB90AB0B13AULL, 0x21ED214C4364BBCCULL, 0xE36BB800487DBF51ULL, 0x2237D92AAE858DCDULL, 
            0x4455B002DCE3EBB1ULL, 0x7A253B867053BF85ULL, 0xD4097E78C74EC9CEULL, 0xF302B75463B6129CULL, 
            0x17EC321F4ADD9BBFULL, 0x971BDC66208D299FULL, 0xCC352A6E167DCF82ULL, 0x6EDA539C21EFC414ULL, 
            0x622B73104D2BD017ULL, 0x64EB972B2520FD59ULL, 0x5FF7EE8FE7DF1E80ULL, 0x28E01B1B73DFF500ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseHConstants = {
    0xDC95DDC99B62A459ULL,
    0xF5486E08EBC5C194ULL,
    0xA33B487434C29057ULL,
    0xDC95DDC99B62A459ULL,
    0xF5486E08EBC5C194ULL,
    0xA33B487434C29057ULL,
    0x7F9B38A453B879A5ULL,
    0x73ADEFA84DF97257ULL,
    0x99,
    0x1E,
    0xA4,
    0x21,
    0x35,
    0x79,
    0x16,
    0xE4
};

