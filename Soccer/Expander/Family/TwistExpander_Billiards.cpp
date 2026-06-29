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
    std::uint64_t aPrevious = 0xA0AD21BEB1B18C5CULL; std::uint64_t aIngress = 0x88818866F246F67BULL; std::uint64_t aCarry = 0x83F690294842920CULL;

    std::uint64_t aWandererA = 0xA29D4B0FA19144E1ULL; std::uint64_t aWandererB = 0xF58C3046FACE98A5ULL; std::uint64_t aWandererC = 0xB1A30F45595060EBULL; std::uint64_t aWandererD = 0xE90AFEBB6445F16EULL;
    std::uint64_t aWandererE = 0xF28CDFD06C5435DAULL; std::uint64_t aWandererF = 0xB33D64DD49CD6605ULL; std::uint64_t aWandererG = 0xA3576EBE248426F6ULL; std::uint64_t aWandererH = 0xDA4132DDBD47D74AULL;
    std::uint64_t aWandererI = 0xECB7469650321AD5ULL; std::uint64_t aWandererJ = 0xE19C2A02DA0F0FCBULL; std::uint64_t aWandererK = 0xDEB192AD9F2F9A58ULL;

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
        aPrevious = 13320931161356129124U;
        aCarry = 13166622789772409945U;
        aWandererA = 10853398393166236209U;
        aWandererB = 18000856507908194142U;
        aWandererC = 9869317940579397729U;
        aWandererD = 16834900924529172346U;
        aWandererE = 14833853186382674039U;
        aWandererF = 12012946377225770469U;
        aWandererG = 12767509648181494258U;
        aWandererH = 10697834183420302772U;
        aWandererI = 14246402476828609217U;
        aWandererJ = 12821445732318477000U;
        aWandererK = 10058997765677184378U;
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
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
    std::uint64_t aPrevious = 0x946AB8D5B33FC9A3ULL; std::uint64_t aIngress = 0xD3D8C90EEBFDC6F0ULL; std::uint64_t aCarry = 0xF889AB2B9AEA9F4FULL;

    std::uint64_t aWandererA = 0xE680DBF633698E2CULL; std::uint64_t aWandererB = 0xA286E1B6C2D4FF97ULL; std::uint64_t aWandererC = 0xE90DF74E9FF1DBF8ULL; std::uint64_t aWandererD = 0xEAB22D57D3063A47ULL;
    std::uint64_t aWandererE = 0xB31F987CD202A247ULL; std::uint64_t aWandererF = 0xA88D6413A9FF7E11ULL; std::uint64_t aWandererG = 0xF2E5E9804F941BEAULL; std::uint64_t aWandererH = 0xFCEDDC9A521460ABULL;
    std::uint64_t aWandererI = 0xCB147B14A5E20117ULL; std::uint64_t aWandererJ = 0xCA8AC73EB5081A64ULL; std::uint64_t aWandererK = 0xF8F7D9840BF324EAULL;

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
        aPrevious = 15037222239403417533U;
        aCarry = 9739392962288074167U;
        aWandererA = 12068387915102178093U;
        aWandererB = 15695979353731080616U;
        aWandererC = 12155025896719963217U;
        aWandererD = 12239025420431868099U;
        aWandererE = 15377728881302968128U;
        aWandererF = 17484212851817625149U;
        aWandererG = 12242825333048408168U;
        aWandererH = 9312287957047422585U;
        aWandererI = 11531937881851532087U;
        aWandererJ = 10335056803870355202U;
        aWandererK = 13977836033572137775U;
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
    std::uint64_t aPrevious = 0xDFA16FB130618131ULL;
    std::uint64_t aIngress = 0xDC0D3AD3DD616D0CULL;
    std::uint64_t aCarry = 0xD816D23FF7F5E70EULL;

    std::uint64_t aWandererA = 0xED747F6FE8373E96ULL;
    std::uint64_t aWandererB = 0x981C238D416DC806ULL;
    std::uint64_t aWandererC = 0xD2CCBED57EDD8333ULL;
    std::uint64_t aWandererD = 0xADE4C752F32C1E52ULL;
    std::uint64_t aWandererE = 0xED0F567486D87403ULL;
    std::uint64_t aWandererF = 0x8D0A85F45BD88346ULL;
    std::uint64_t aWandererG = 0xFE371EC91FA6689AULL;
    std::uint64_t aWandererH = 0x9D63A4BFFF145A29ULL;
    std::uint64_t aWandererI = 0x95EBB7F9EBCE2187ULL;
    std::uint64_t aWandererJ = 0x84CC407745C59C06ULL;
    std::uint64_t aWandererK = 0xF1329F050C7862DDULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB, 1);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC, 2);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA, 3);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB, 5);
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC, 6);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
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
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneB);
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
    // write to: invest_c, invest_d, work_a, work_b, work_c, work_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, invest_a, invest_b, invest_c, invest_d
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
    // write to: fire_a, fire_b, operation_a, operation_b, operation_c, operation_d
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
    // temp storage: snow_a, snow_b, work_c, work_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_c, snow_d, expand_a, expand_b, expand_c, expand_d
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
    // temp storage: invest_a, invest_b, invest_c, invest_d, fire_a, fire_b, fire_c, fire_d
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
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
    std::uint64_t aPrevious = 0xF63350838059CCC6ULL; std::uint64_t aIngress = 0xD7A96274F0491F4FULL; std::uint64_t aCarry = 0xA73A593FE0A263F5ULL;

    std::uint64_t aWandererA = 0xD6609CCE962E1B51ULL; std::uint64_t aWandererB = 0x96B129538FBEBEF1ULL; std::uint64_t aWandererC = 0xD98688D19DA2257AULL; std::uint64_t aWandererD = 0xA4A39B68AF42D5AFULL;
    std::uint64_t aWandererE = 0x9F2CE9116CF7B3E3ULL; std::uint64_t aWandererF = 0x88D2CE9AF3BEE94DULL; std::uint64_t aWandererG = 0xF183C0857639677AULL; std::uint64_t aWandererH = 0xCD8E4D566E3C4ECBULL;
    std::uint64_t aWandererI = 0xE0C237082F4ED38EULL; std::uint64_t aWandererJ = 0x8A52D61C5142286CULL; std::uint64_t aWandererK = 0xA726A7FD554EF60DULL;

    // [seed]
    {
        aPrevious = 17587330026932938193U;
        aCarry = 15925398725562255979U;
        aWandererA = 15096143725394991245U;
        aWandererB = 13525421275072796437U;
        aWandererC = 17416066028087426172U;
        aWandererD = 16809879726809405767U;
        aWandererE = 12165697108552897335U;
        aWandererF = 15862196559189339067U;
        aWandererG = 18018473048031216501U;
        aWandererH = 16412496178114687944U;
        aWandererI = 13408180773996572965U;
        aWandererJ = 16519132071245552569U;
        aWandererK = 9785967514604856799U;
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
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 0, 1 with offsets 3809U, 3874U, 5111U, 2820U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3809U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3874U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5111U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2820U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 2, 2 with offsets 663U, 2026U, 2462U, 6385U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 663U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2026U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2462U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6385U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 3, 0 with offsets 4638U, 5627U, 7634U, 1491U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4638U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5627U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7634U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1491U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 1, 3 with offsets 2705U, 6043U, 3615U, 5296U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2705U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6043U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3615U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5296U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 2, 3 with offsets 241U, 1074U, 272U, 90U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 241U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1074U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 272U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 90U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 2, 1, 3 with offsets 1717U, 125U, 1642U, 1346U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1717U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 125U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1642U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1346U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 1, 0, 3 with offsets 1864U, 598U, 1118U, 1006U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1864U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 598U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1118U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1006U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 2, 0 with offsets 447U, 1628U, 561U, 10U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 447U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1628U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 561U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 10U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 6U, 838U, 853U, 1895U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 6U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 838U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 853U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1895U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 3 with offsets 4038U, 8119U, 1265U, 752U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4038U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8119U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1265U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 752U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 2 with offsets 2091U, 2374U, 7047U, 142U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2091U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2374U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7047U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 142U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 0 with offsets 611U, 6054U, 3545U, 1685U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 611U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6054U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3545U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1685U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 1 with offsets 5216U, 169U, 1471U, 1489U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5216U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 169U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1471U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1489U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 1143U, 7782U, 3295U, 3734U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1143U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 7782U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 3295U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3734U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 250U, 949U, 143U, 1612U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 143U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1612U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 569U, 105U, 789U, 1952U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 569U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 105U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 789U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1952U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1080U, 939U, 879U, 1666U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1080U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 939U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 879U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1666U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 48U, 1421U, 1037U, 746U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1037U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 746U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 0, 3 [0..<W_KEY]
        // offsets: 547U, 499U, 1222U, 1096U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 547U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 499U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1222U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1096U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseASalts = {
    {
        {
            0xB5C5574B92EE6338ULL, 0x62204A76FCF3EAC4ULL, 0x27F5B31313B2E050ULL, 0x488FB0F286B463E5ULL, 
            0xA322521F6549B76CULL, 0x6EA3863826190631ULL, 0xC088403B1B80EB71ULL, 0x2548DAE69EB7F558ULL, 
            0xEE9131B858403255ULL, 0x2E551FE6123A07FFULL, 0x40F4AE062D7E7258ULL, 0xB567D8DBAE021C39ULL, 
            0xF6B5E27CE5EB0254ULL, 0x8C0E107109568753ULL, 0x91D29FAD11BFED09ULL, 0x4238BB8834C48D9BULL, 
            0xB6B15FFA7B6C36CBULL, 0x694D0F58CEF79317ULL, 0x19E2BDA9F4F178FEULL, 0xE01E023B5C512657ULL, 
            0xAB4A27A2FDBCAAA5ULL, 0x6AD49438256BCD58ULL, 0x7D42330196D1CE0AULL, 0xAD0C6F38F4413CEFULL, 
            0xE38B4B33BE1AAE3EULL, 0xE26C2AE141224565ULL, 0xAFBD864EAEA58FA1ULL, 0x27E38C87046A2D25ULL, 
            0x47B1E2F2DF06E1C5ULL, 0x3813CEE90FCCEF42ULL, 0x452B2321E0B2F2F2ULL, 0x5E73BF3E6CA7B470ULL
        },
        {
            0xCA20054B62233390ULL, 0xEBBC6F17CC29711AULL, 0x07D14C7C88498E02ULL, 0xDE6011A585FF1790ULL, 
            0x4C1DF8F8B43C6170ULL, 0xF807C50BCEED9084ULL, 0x1D15C144259C04B5ULL, 0x23B816EFCFAE22B1ULL, 
            0x738414F23FF20257ULL, 0x51BB3541D3C6D151ULL, 0xA6F8D3510CE3625BULL, 0xE3598E8BD055DE50ULL, 
            0xA08588E8A76186E7ULL, 0x77920C0472B27E06ULL, 0x1BA92ACA3AF58385ULL, 0x0A70AB806A1778ECULL, 
            0xD24530FF47C05473ULL, 0xD677F88AD51134FCULL, 0x9491D60E339A2699ULL, 0x168F8A130A5F818BULL, 
            0xCFFDDADA7FC013DCULL, 0x75062576BB05FAEDULL, 0xFDE28927B4E97707ULL, 0xC9B8331E3A1625EFULL, 
            0x5661A36FA65B8255ULL, 0x4DED91B0665E15FAULL, 0xFB54774DB70BC94BULL, 0x5287C523C0068202ULL, 
            0x6C64E6C89A2340DBULL, 0x8691F0852BF1C918ULL, 0xFE52B209EF3B3E15ULL, 0x76C4871BD345FBBAULL
        },
        {
            0xBEE6CD8C7BDF6E43ULL, 0x65E38ADA06AFC6E9ULL, 0xE3016D6112714D54ULL, 0xAB685FF76FD37CE5ULL, 
            0x3FC74F8201494181ULL, 0x84358135CB2B3928ULL, 0x8E01F2B497A5B212ULL, 0x92D37FDFA8001EADULL, 
            0x31A143895B1A1EAFULL, 0x6F7A2AD9233CF93EULL, 0x7107F2E77C20CCBAULL, 0x6AFAD480A372C69BULL, 
            0xA8E75213DD125209ULL, 0xF1C6F848AFA17701ULL, 0xA2867C69C8D4970EULL, 0xBC34C12D26F3C568ULL, 
            0x97B414F375282F5FULL, 0xEB8EC13A5AAA1FEBULL, 0xE0EA9415141E2A42ULL, 0xB70D2B35A7D04A6BULL, 
            0xAB4EF33BA909A00DULL, 0x9550E84502708FA5ULL, 0x608A526D12CEBD42ULL, 0x2419755805200C65ULL, 
            0x2B8BBEAECB1B7A4DULL, 0x355C914029B29978ULL, 0x6B219ACC9BA8A5AEULL, 0x562FB6FE76574975ULL, 
            0x03CDB4D3AC621026ULL, 0x090E250D72E3C2BCULL, 0xD9A677F1EE0D70F4ULL, 0x8280C0D997ED7F19ULL
        },
        {
            0x639E720E69118771ULL, 0x21C0E4B436ED0416ULL, 0x49FFB3A7665E3B49ULL, 0x14CBEB427D71848CULL, 
            0xCEF0390F91B30381ULL, 0xEF5889936AC34C5DULL, 0xEC02714300009869ULL, 0xDC6FA6F498AD8FCCULL, 
            0x1BFDAE115E4D2566ULL, 0xC10835D16AC8BC97ULL, 0x03AD30E1A25C6AA0ULL, 0xFE83B3A83C5B9B8DULL, 
            0x5258FAD43F12E78EULL, 0x5FF509E1E049CD70ULL, 0x1078EFAF6A9E60DCULL, 0x78948D5032840953ULL, 
            0xAB6686D6892AD5B5ULL, 0xA554D31013FE9079ULL, 0xE0643A52DDEA729EULL, 0xB210208D18AD4683ULL, 
            0xBB657316DFBDA2F7ULL, 0x58F36D782E905847ULL, 0x34E38850B2C1FA80ULL, 0x08A6EC4596B32385ULL, 
            0xD3BFB624B6697A7BULL, 0x136D7993328A4E32ULL, 0x6D4C2968EB4579D3ULL, 0x3DB3062D54A7355CULL, 
            0x60D1C53EF4634B0FULL, 0x8360AB8B6BFCB051ULL, 0x8828B09EF113B366ULL, 0xE28558A503D5886FULL
        },
        {
            0xB7C9DE90FAD74E6CULL, 0xB00E926B74D91B87ULL, 0xD4555C150877D995ULL, 0xC5E9D0D50C3EE5BBULL, 
            0x867DF22C1F839174ULL, 0x89F72F8D3A8326EDULL, 0xDB2672F8D88E472AULL, 0xD1801BF808AA82F9ULL, 
            0xB9EC7012D4036472ULL, 0xC72C8A5ECACF052CULL, 0x94E3B98703579218ULL, 0x13EB2EDE6061DD0EULL, 
            0x89BCC51D9ADD9CF8ULL, 0xFC793CDA0E171D20ULL, 0xC8170A0F1A7C4EA3ULL, 0xC445F481BFE5487EULL, 
            0x63D790FB4282B668ULL, 0x67CD2F3CE2948800ULL, 0x0E4937F25D9E09D1ULL, 0xFAFE92033E1F248BULL, 
            0x1F278A7CC58548F5ULL, 0x2FE8F543E0A08013ULL, 0x0149154831303066ULL, 0x3D7EB9A5BA0FDBA6ULL, 
            0x3DAC9D43BA5B002BULL, 0x9403872CB12DE77EULL, 0xFB7A5E130B8F99B1ULL, 0xB37E252ACA7A8A58ULL, 
            0x69CFE75E374065F9ULL, 0xEFA0899DF26C0E7EULL, 0x24CE2688924A1A38ULL, 0x2AD2492AC5195EA4ULL
        },
        {
            0x85704F961854B37DULL, 0x0AA4DBE6FCC7868CULL, 0xA06750B151CD2475ULL, 0x0DD86E779AF0A792ULL, 
            0xD59421B02564242FULL, 0x9039519D2193ABAEULL, 0x8C7F375A33266722ULL, 0xE918561C2CA6F76FULL, 
            0x235FD946D8724900ULL, 0xA9627659EF9A86CEULL, 0x59445E75E18B8B43ULL, 0x26CAC73682CFE4E5ULL, 
            0xC3AAC2F6D1E83475ULL, 0x6D9FDDD7CDA81EEFULL, 0x1361006999F2BB3AULL, 0x614567C0CB52A639ULL, 
            0x51278BA4A984C10AULL, 0x1A5F7CC106B338ADULL, 0x3D7A648C0969E68CULL, 0xBB1F433A2E3FA48AULL, 
            0x35E6EB8AD7959C8BULL, 0x1DB907320FD7FE5AULL, 0x3D07A09CC063E122ULL, 0x62DAFED78DE83122ULL, 
            0xA0F2CFAC472EB18BULL, 0x0FC13DE4FD825852ULL, 0x9F5C98FAE254936AULL, 0x9D1E2ED7A6E151AFULL, 
            0x0E25DBF145F17902ULL, 0xFEF9653A4A379DF4ULL, 0xD7D2F8D517C131CDULL, 0x572CEFB25FC60A31ULL
        }
    },
    {
        {
            0xE1097BD18888AD78ULL, 0x38B771F980AD0B47ULL, 0x9ADC184F65C7F4FDULL, 0xCD5306B888FD30E2ULL, 
            0x1671650DF3F900B1ULL, 0x1E198BDF5B4D5A59ULL, 0x3FE9905A83222CAAULL, 0x826C8166335774ABULL, 
            0xC512ADEB574C0019ULL, 0xF5133E4999557C73ULL, 0x98B1B3A073FE78F7ULL, 0xCC9188CBD70E0BB4ULL, 
            0x0D8E53D6958D944EULL, 0x4D76BBDBAFAA27BBULL, 0xD324FDDF5CBED735ULL, 0x23DEFA472002B067ULL, 
            0xB0FE40D1EB14C0B3ULL, 0xAA278B00E6D65AFDULL, 0x4F8042E5B473AC12ULL, 0xB2CF8706C96D29E7ULL, 
            0x10FE1F7F391899D5ULL, 0xF19EC132708E7DE5ULL, 0x931F9DD0C4867D70ULL, 0x9BE65CBFA90244E6ULL, 
            0xCCB2197C7AF60FFFULL, 0x8635848020C34EA7ULL, 0x6B961760490F063AULL, 0xFE68080D157EA287ULL, 
            0x4BCFBDA05143C77BULL, 0xAF56DC9261E3BA92ULL, 0x9D475F6DF1E6E067ULL, 0xFDA6FCEA7F593C3BULL
        },
        {
            0x1222A5F6FC1B7DFAULL, 0xFE3241F9BFD3A22CULL, 0xF590C69F061E7F20ULL, 0x4FB94F809C0C3CE5ULL, 
            0x4AC10A38AB750BC9ULL, 0x9ED1A8A7A3D88693ULL, 0x51F9459011238EC2ULL, 0xC4CE4C66B6261DBAULL, 
            0xC9222ABD83A0E91BULL, 0xB22795ECEE51AAF4ULL, 0x0F3521CAB07333E5ULL, 0x21B10A74A7C1BEF2ULL, 
            0x170606647C064A9FULL, 0x18D917E9F3CADB15ULL, 0xB2E214B0EA32131CULL, 0x2D84478A428B5B97ULL, 
            0xBBA3180271E907B6ULL, 0x6C00F8BBF5E83D24ULL, 0xB5CDD66AA5BD1A69ULL, 0x185671C6B4E09648ULL, 
            0x8780F45810D12F2BULL, 0xBA28F815FE35743BULL, 0x93EB0DC46971B5EEULL, 0x6131781AB7C302F2ULL, 
            0xD91A387A283F7A6FULL, 0xBAEB58D693886C19ULL, 0x5789F4BF07F52B16ULL, 0xD3B2642FDCD1364BULL, 
            0x215A020792095E0EULL, 0x517D9DF3F87321BEULL, 0xA3620455EA668A36ULL, 0x615CD8DDAA41C000ULL
        },
        {
            0x8A7A3A01EFD5D937ULL, 0xDF4C2E247D8F1742ULL, 0x1547028DE37A2865ULL, 0x29B2DFE6F8EA8C7DULL, 
            0xE4F262B50670783FULL, 0x671AE720BA4099A7ULL, 0xF28E78F22DDB71EAULL, 0xD4052F4E07EE778EULL, 
            0x357518B2A6BE6E5CULL, 0x6F59BD5D2DCE1618ULL, 0x852211A2250A1971ULL, 0x5F56B812110A4EEBULL, 
            0xEA55EB8CA067A693ULL, 0x57287C1532B75FABULL, 0x540915E3F6A7D265ULL, 0x1A881B05F27E670DULL, 
            0x274E9CFFB454FDE9ULL, 0x6E9290A0B4FCD388ULL, 0x3DE9826E5A47BBBEULL, 0x28BA2DCD6F8D5492ULL, 
            0x098396615CE87495ULL, 0x188B77D22EA2D42FULL, 0xF8370611B43BB13BULL, 0xE4A742EB1927E34AULL, 
            0x2BFD4DF641A21C2BULL, 0xA7F422C4CCA97689ULL, 0xD8D61E8565BFFFA7ULL, 0xB79943738E047813ULL, 
            0xD0B1633534F2CF19ULL, 0xDC48655F0954432FULL, 0x13B02B6EBEFB1E15ULL, 0x5B01D7E70EEA6B79ULL
        },
        {
            0xCDD0252AE6BB6BEDULL, 0xFB7BB074D11B955DULL, 0x595A5065843B19ADULL, 0x5B28DD6103C8FDADULL, 
            0x4716DC779DEBB425ULL, 0xD2BE3175BCE098DCULL, 0xD2DD731942DACB86ULL, 0xFE49D19C03D163FEULL, 
            0xE63CF0E298A7A6FEULL, 0x9E8619115493E431ULL, 0x7A405863F83BDE16ULL, 0x489A80097B51D6F6ULL, 
            0x10E0D4EBFD495134ULL, 0x2E9CB96326611E7AULL, 0xCFD5D418332EE07CULL, 0x4E7894B3F0ADD04FULL, 
            0x848D22AFFD76095FULL, 0x01423662A719638EULL, 0xAD06B2DFEA16D442ULL, 0xFDDEFFCC8AEE1E92ULL, 
            0x49D04C9C0E231B00ULL, 0x3D9DFC33F9304E20ULL, 0xA39E8CD0D85E1424ULL, 0x943F47C9049F03DBULL, 
            0xBB2AB5E372DEE3A7ULL, 0x68E360FA18F74FEBULL, 0x0B9AC7DFC8AF732CULL, 0xC758031D40B7E982ULL, 
            0xDBB21E4D5E380242ULL, 0xAF8D1F24295BF1EAULL, 0x5C91137123CFB6D8ULL, 0xF3F352883C52A71AULL
        },
        {
            0xFFA26366A871AC64ULL, 0x0426F1A6C23D6E2EULL, 0x6118654980ACCAA8ULL, 0x03F4C36E67E8363EULL, 
            0x0D796CA3EC0CDDA2ULL, 0x26A644C7994D6CBEULL, 0x057278D6962405CDULL, 0xFA72E2CA63E6E5FBULL, 
            0xF1493CB32329230AULL, 0x1FC5A58CDE264821ULL, 0xE8FB385947845C97ULL, 0x1DAB6DD020F8B4E1ULL, 
            0x0292AE65DC9DEC6FULL, 0x9B23612390B55C90ULL, 0xAEBFB7E31E31700AULL, 0x03B17D45354BB781ULL, 
            0x923DB15F295D1CB3ULL, 0xD77E8535A4ECEB0AULL, 0x52E7CC311B5B1CC5ULL, 0x3F8724C47D4350ADULL, 
            0xA9B858749CC8EC38ULL, 0x36059D469D6F47A1ULL, 0xDBD15320A688BB00ULL, 0x534039CE2DDECCA0ULL, 
            0x9104F4EFFACC843CULL, 0x5DD9FA11208BFF97ULL, 0xFA2E0938B8CCA0E8ULL, 0x7CE1831FCC1911A0ULL, 
            0x07A73CAE8A9A673CULL, 0xF370397A6E7FB96EULL, 0x2E6841CD506FB435ULL, 0x31EC601187CC5C93ULL
        },
        {
            0x4125D72249DF0CF0ULL, 0xED864AD225FD47F9ULL, 0x82A1C4C86A0DEAC8ULL, 0xDAB996FA02525FBAULL, 
            0x24D651230C4AE2A4ULL, 0xD0A9E6A483C88CA7ULL, 0xE727E9B90A83F955ULL, 0x7AF169DF140FC778ULL, 
            0xD50C9743999E8CF2ULL, 0xB4B9465DC415F2C5ULL, 0x6AE5AC6D49CAC617ULL, 0x0BD0E58FC6812A1DULL, 
            0x8793F9EF0F4C299FULL, 0x8129D4841DCBA375ULL, 0x24FE6B837BCCC57FULL, 0x8912FBB99E404B2DULL, 
            0x96FD0C815BB4B2EBULL, 0x95A9E3FE2A58827FULL, 0xDC5E60DB43E38D57ULL, 0x56071CA27AB8E70DULL, 
            0x956F5E6232E338C7ULL, 0x19C3729A66A36786ULL, 0xE8DE23D19BC8ECD0ULL, 0xBAF16CEBB3355929ULL, 
            0x285768BD83CB39E8ULL, 0xA728BA03728CFEFEULL, 0xDFA41D3EB934CD07ULL, 0x0D8DBEA6E71D1EE1ULL, 
            0x67A938967123D7ACULL, 0x7A317DF3A320FC4BULL, 0x6DE0120C31BEF2B5ULL, 0x3DE6196E36FA8241ULL
        }
    },
    {
        {
            0x00403CFE0E231BDFULL, 0x35533A7490E16656ULL, 0xAC0200938D5B874EULL, 0x3D899050BBC39FB8ULL, 
            0x9DAC2A829DDD2A38ULL, 0x272D655D2C15BDD9ULL, 0x11427561100AC39EULL, 0x7109CBF1DB514C7BULL, 
            0xF526E73433DDE9ABULL, 0xBCE19FA9AD3FC917ULL, 0x807F34EE77065BDCULL, 0xD5348552218CF909ULL, 
            0x1EED56ABF35C8954ULL, 0x435C49E7CD5341F5ULL, 0x905B56CD956E2CEAULL, 0xA16EA02A40366D9CULL, 
            0xA91203DC8E0DC065ULL, 0x9A51D63EF8090A89ULL, 0x33CB910BF29E42AFULL, 0x70556CC94612C47AULL, 
            0x7F89A948BB02C3CAULL, 0x4EEB27AF544339B2ULL, 0x94DADD26178C26D5ULL, 0x8F6A22725A83D2E4ULL, 
            0x6B2235BE47987320ULL, 0xB704A58B875AF75AULL, 0x2E079A1ED7CD960DULL, 0x41230F72DC9DE09DULL, 
            0xB1F6C742E7C42C6AULL, 0x0F6D0B9D6031920CULL, 0xF45287116ED7A298ULL, 0x30A0065DDC58B305ULL
        },
        {
            0x36D42E781A2ED115ULL, 0x0A4930D483CB1799ULL, 0x13923022492C9ECCULL, 0xBD51FCE0339E51D7ULL, 
            0x30D62FBB62FA8A85ULL, 0x022DC0224FF748A2ULL, 0xE009C35405772178ULL, 0x6C3B662B9C2506B7ULL, 
            0xAECE5EC487F4CF9DULL, 0xAB71E37182C4F0C1ULL, 0xEDD13EB74D6EFD7DULL, 0x78CF54E76FB3017AULL, 
            0x662142C24FFBFF83ULL, 0x801962F694CAF00DULL, 0xECA4DAE863D2C3AFULL, 0x64BDAD251A4425B2ULL, 
            0xBC2A6118381634DDULL, 0x819F77E6F2A09CD3ULL, 0x1279BE50B0B562E2ULL, 0x11AAF75E3105D3F0ULL, 
            0x61E412D1FD5B73CBULL, 0x357C65A17E3D4CB9ULL, 0xBA938F8EB2B175DEULL, 0x797D66C003C9BFB6ULL, 
            0xEBAF1F2B2CF720ABULL, 0x52BC7CF396F6B556ULL, 0x93C6C2779B93F170ULL, 0x301C9D299CA562D7ULL, 
            0x0E45F231970FBD18ULL, 0x7D93511A0D5BB79AULL, 0x5230AA8A769D0E1BULL, 0x883AC4581552E859ULL
        },
        {
            0x72AE4CBD4BF39B98ULL, 0x88C9E35097B35F13ULL, 0x7EE3A3DD0889CB1FULL, 0x5B406459E7FC9756ULL, 
            0x3E33FC06CB54F500ULL, 0x98D7569821DBCDC5ULL, 0x97E32070D74B00FEULL, 0xF8B7488BC664D06AULL, 
            0x981D2AC22E9229F1ULL, 0xE5EE7AA39A008F5EULL, 0xA38F76232090D5AFULL, 0xAAF2DF3DC73876A9ULL, 
            0xE37977068FFCBA5FULL, 0x656F50683D3255D6ULL, 0x6FF04E556FC1CCA0ULL, 0x2CBA162003C5D75DULL, 
            0x1D2868A211A8292AULL, 0x28CD0E3DA12972C7ULL, 0xBBDA50EBA8CC7ED1ULL, 0xE3A7E64EECA5AF00ULL, 
            0x9EA1FD8D05505BA8ULL, 0x522F791522A0EDD6ULL, 0x4AA464CB25CD5B18ULL, 0x88EE6BD51E68B1C9ULL, 
            0x3EBD90C71703FD69ULL, 0xBF1D023EA6F9A280ULL, 0xA0BA80D1E201922EULL, 0xBBC2B4B899EFF58FULL, 
            0xAC6FB8E907973779ULL, 0xB02D077F677803B4ULL, 0x0E9804BF32479AFCULL, 0xF3B56FE4A4F75266ULL
        },
        {
            0x5AD652F66893BCD6ULL, 0x956427EC5F7576B8ULL, 0x8E13079C933CA335ULL, 0xAB95257CE5BCDDD8ULL, 
            0xCA98D6D59BBDA80FULL, 0x2004932E5CFA2D90ULL, 0xD50A51FD8ADDF5A1ULL, 0x95835F7720C143EBULL, 
            0xF9D1E0E5F6ACB80EULL, 0xB7E1180588DEC5B8ULL, 0xEBABC3BA2F01C7B5ULL, 0xB09974B6E498443DULL, 
            0x3B96CE066E1C3C32ULL, 0xDDCB28AA582E2B9BULL, 0xF2486282AA80D4FCULL, 0xB1CB7D04484FADDEULL, 
            0xC6CEF7027AAD619EULL, 0x9E411E218C7900CCULL, 0xEF55FDE81B37EA70ULL, 0xCDD5994E3FCFFFA4ULL, 
            0xCE43B4BA9CAD778AULL, 0x351B80E13B73D0BAULL, 0xA44624BDD1C4FE85ULL, 0x61D0E81A34B1D798ULL, 
            0xBE1C7A278A6D1BB6ULL, 0xFA9B0308B62C78DCULL, 0x813E4D6A52034813ULL, 0xE52CBFB54D1AF36CULL, 
            0xC5F39BB24F7425E2ULL, 0xE295F6B285D25D31ULL, 0x88D5D428CAAE0EB5ULL, 0xDB08440B4EB5C348ULL
        },
        {
            0xF396F4DACCC0E4BEULL, 0xC72EFF908C3F801FULL, 0xA8A1151E2B281762ULL, 0x96C279C8E703EA45ULL, 
            0x3960F56497FB7D3CULL, 0x8870E427F2D02D90ULL, 0x11A258B726BE5DD5ULL, 0xE3821763F4340C44ULL, 
            0xF503BA617CBDFDBDULL, 0xDF00C45F464ECA91ULL, 0x66EEDFAC1DCEAFC1ULL, 0x144758F0982A5AC9ULL, 
            0xC08FAD1108D31C78ULL, 0x3A5B3601ED35034AULL, 0x0BB20FB2BA2165C3ULL, 0x882EF43D9A12C9D1ULL, 
            0x2CA3EA19F444387BULL, 0xB081032E3DAC4CC9ULL, 0x823A5A4EFCB9E6B6ULL, 0x75EBF8EE816A85E3ULL, 
            0x20D846293B0EC2F2ULL, 0x538DCA58BC9A096EULL, 0xE7D89674150096F3ULL, 0xA055289C70E6B8D5ULL, 
            0x3E9B3E26CFE7E69FULL, 0x6E8127498E528F78ULL, 0xAF62B7DB3D1CF14FULL, 0xEF639389A3662F7CULL, 
            0x82D4A8372AB60295ULL, 0x1B3878BD7EEEB209ULL, 0x397355E9AB3133EFULL, 0xB9231250C86339B5ULL
        },
        {
            0x391E9A93488B4CC5ULL, 0x8FEBDA9C48BCC2F6ULL, 0x7169D91FF04C9BF9ULL, 0x803ABECA09AC8F6CULL, 
            0xAC52109654C2AE5EULL, 0xD0B140C9023A2D0EULL, 0xDE752B6648BE0121ULL, 0xFC3AE6539F0891CEULL, 
            0x426D4FB9658CD199ULL, 0x804F01FF731F322FULL, 0x6925C9E3B0D62548ULL, 0x4EB6A81A5F174B54ULL, 
            0xCC99D2004672EFFDULL, 0x4DBC5F676C0C3613ULL, 0xC78E6E9F37B3DF4CULL, 0xC0530502491593F5ULL, 
            0x6C9307D770FBB6DAULL, 0x452C80848665ABB0ULL, 0x7A4B2E00997D8AC8ULL, 0x526678042A4658E9ULL, 
            0xB3A681EC07E8DBC3ULL, 0x1A11BEA371EB1DF6ULL, 0x6CF0B0E30BD3B34CULL, 0x9BACA7B363EDC466ULL, 
            0xED91E48C8ACF33ECULL, 0xC03F055CB72A7D92ULL, 0xAC331199B5F2819AULL, 0xA464F2F27A52380EULL, 
            0x8C5B7B1CA79A0F44ULL, 0x9822286803FA6426ULL, 0x8D3036D7281AD0F4ULL, 0x1AADAC017D381052ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseAConstants = {
    0xF429542D0CF18FDEULL,
    0xBDA4A8BA200EECECULL,
    0x631F779FE71A34E4ULL,
    0xF429542D0CF18FDEULL,
    0xBDA4A8BA200EECECULL,
    0x631F779FE71A34E4ULL,
    0xC18EF766B84DB5C2ULL,
    0x9CF5505D8B30BE95ULL,
    0x27,
    0xB2,
    0x51,
    0x76,
    0x62,
    0xCC,
    0x26,
    0x61
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseBSalts = {
    {
        {
            0x2348BC5DF9E651A2ULL, 0x8CF82FD66A9F43AEULL, 0x18AB5E26265069F2ULL, 0x298372FCCF4E8772ULL, 
            0x893C95F3A6DA0380ULL, 0xE54F1FDC5B7D67C0ULL, 0x88748ED4D7EC8920ULL, 0xC4939E3A06E3EDA0ULL, 
            0xAF572D8114AC0A92ULL, 0x61D2A1964334C11FULL, 0x8C481ABE52F64E95ULL, 0x5DED1BD763663395ULL, 
            0xB567FA69B2D271CFULL, 0xF5F833F449BE6AB1ULL, 0xAD18FA843DD255B4ULL, 0x756C9B4BBC546BD2ULL, 
            0x3810D254474DA254ULL, 0x3562BEA17C234118ULL, 0xEF482236172B3BCBULL, 0xEBC78C30EFAB579BULL, 
            0xE2A77084E661B7B7ULL, 0xFBAC49F79498C91AULL, 0xF4D695E0E52A33F3ULL, 0x1389DB336041E772ULL, 
            0xE3CC1862740BB083ULL, 0xE94AD751E0ACD29BULL, 0xF8827F532D2928E9ULL, 0x017D33C68C6868B8ULL, 
            0xE910EC5B9AD151F2ULL, 0x0DE8A300E4E23D80ULL, 0xC4E87137D8847CD4ULL, 0x969784DE46D8ABE0ULL
        },
        {
            0x05D7212A4C6AE223ULL, 0x2B1A41E4EFAE88F7ULL, 0x5DE82DCECB6F2BC4ULL, 0x3E18328ABE1F6281ULL, 
            0x896E6C576E7F28A3ULL, 0xCCD9F7CEEFEEFF97ULL, 0x31CC8352F8FCABA3ULL, 0xCD70E64E2FE20BB0ULL, 
            0xB69C7071C9C56BADULL, 0x925A824E64FA2685ULL, 0x592B7459E499BA6FULL, 0x1506897D5B8D67EDULL, 
            0x170D2D3CA6BC4D6CULL, 0xD3912D2F116D9529ULL, 0x4E91CA156D1A73EAULL, 0x9A121DC676BB693EULL, 
            0x26E152AC504B8EF3ULL, 0xB1AC2BD5B5D13118ULL, 0xC80BFFFEA827AB7AULL, 0x5830E94BD47C1E1DULL, 
            0xA3CB76D5394AB80FULL, 0xAD8DB8D65F5F6F0EULL, 0xA56C474A37B014EEULL, 0x6E6DE0BC01EA5002ULL, 
            0x34973FF72D95D3A8ULL, 0x4A08F9DE48298C49ULL, 0xCB2E2BE969357514ULL, 0xF2C7876F2AFD2DC3ULL, 
            0x6964C17915574496ULL, 0x1DEDF92D1CC39A6EULL, 0x65268C5F4A907F99ULL, 0x8B2A4DB46446BAD1ULL
        },
        {
            0x214B74AA702B1EF3ULL, 0x29214E3FD7698FF6ULL, 0x6373EC96FC7A698CULL, 0xD4DAAB08638E7F6BULL, 
            0x07DC6FF9B2F8A172ULL, 0x9E07D92F53F2A066ULL, 0xB6B828CE9C2F87D0ULL, 0x031BD12407597CDFULL, 
            0x5841973F240916D6ULL, 0xBB1C0782229A2D0FULL, 0xC13C1875D3C37DF5ULL, 0xBFBCC034294C369DULL, 
            0x708DF9B32ED9F213ULL, 0x489B9D40D0589DB3ULL, 0x23D53F22955C06E4ULL, 0x644A9705CB9140B4ULL, 
            0x61D45A21DDF76ECAULL, 0x269A30F381D3AF25ULL, 0x7574C0724FD7BA7AULL, 0x0FDC7114FEDF9B61ULL, 
            0xFE208BC76DF44671ULL, 0x379002D5ACA91F3BULL, 0x694E2943ADD2B811ULL, 0xE0083D3B53FE761AULL, 
            0xD54FF3B5E753A370ULL, 0x692E0E16A8DB1B3DULL, 0xF0FECB51017CFD96ULL, 0x4511A64053F052E2ULL, 
            0x0188E35B76A4048EULL, 0xA3CDDC32A4C4891AULL, 0xD7495E4CBC2E2718ULL, 0x252DDC28CDE5BFADULL
        },
        {
            0x52AEA3746C13FBFEULL, 0x969C92FF4BECC833ULL, 0xFF6D60A06709E22FULL, 0xB7ED0499ADF244F7ULL, 
            0x24C4649F35C3C91DULL, 0xB00653044D3A5E80ULL, 0xB5F51481356EEC2DULL, 0x3FEB4BD6AA0A513CULL, 
            0xEF8C3B0422DDCFCAULL, 0xA6F0CA5E68BE8F13ULL, 0x79D92101B35DCA62ULL, 0x52415984E52D242DULL, 
            0xA48E4431F933A4E4ULL, 0x9781CD3C3BA8FD71ULL, 0xF92E76F6149D704AULL, 0xA20D32E3F0652DDCULL, 
            0x3AC2FCE951DB09D9ULL, 0xC2DF9ECD65A06D00ULL, 0x4465F37C77EEDA2EULL, 0x87F0F1B9B5C8ABCEULL, 
            0xEA61E9CA11F1B72DULL, 0xD050C64C0AECC6C2ULL, 0x89961DD608BB99A8ULL, 0xBE4FF2BD5195518FULL, 
            0xE570580D5AEE0C66ULL, 0x1914468809ED8592ULL, 0xC7C98ECBE93C695EULL, 0x25494D62E7D57422ULL, 
            0x8D4FC92367AD0D73ULL, 0x3A0CC28168C71C33ULL, 0x57A584E57CE46889ULL, 0x5E71005B653683EFULL
        },
        {
            0x6202B5346B427BCDULL, 0x70AF7487078DD958ULL, 0x774CFDAF72F0015FULL, 0x0CB0ACCBCA2D47DEULL, 
            0xF5603D753967716BULL, 0x9D8AFD54492676A2ULL, 0x5A13AE28F4CB622FULL, 0x1233B93C5CCA46DBULL, 
            0x89ECF6576150944EULL, 0x4A5F30E63B44F2DDULL, 0xD82492D5708925C5ULL, 0xB12046DB80C38D14ULL, 
            0xCBF217C696F6D167ULL, 0x1D87522D239EB1DDULL, 0x533C82E3CC53FA89ULL, 0x5964C9CD82F823C1ULL, 
            0x5C6F64357BF2DFC5ULL, 0xBE8F592B2F23AC0CULL, 0x2D0E97C897F0CEB8ULL, 0xB45CC954953FE13BULL, 
            0xF99DF5F4551F6D0DULL, 0x9059D6410087EFDEULL, 0xE681B0CDD5B9DAB2ULL, 0x375520091BC54F32ULL, 
            0xA2750A26E27F5E1DULL, 0xED800AF8928C4FC8ULL, 0x380ED74E7C430C5FULL, 0x16C0CA483BB2E93FULL, 
            0xBE9BF13F51C6D3FFULL, 0xA576298FCAD964F5ULL, 0x0800A4A55977E3AAULL, 0x4A79C2562F81941EULL
        },
        {
            0x6DDDB4F6D4F435B8ULL, 0x419268D9AF4A63E3ULL, 0x214D6664A2488A05ULL, 0xCF5CA3409BB39D4BULL, 
            0x7D8EFC32DFF42E20ULL, 0x0327AC0606039BB6ULL, 0x3E3E50EC7C8543FAULL, 0x4A1B7051EF202B87ULL, 
            0x3B562AAF62B3F597ULL, 0x47B659054F91B725ULL, 0x243A3DE98007E4FEULL, 0x65415A85BB475F5AULL, 
            0xF619D5F28B76C58CULL, 0x736C032663954C6EULL, 0x97A2A9EC3F34DF44ULL, 0x6F771147B19C6D39ULL, 
            0xB7CFB204625CC2F6ULL, 0xF360C332C2C88503ULL, 0x6C0EF1EE47BB775FULL, 0xA8ABD30CF47316C6ULL, 
            0x8C240DB822FB4D6EULL, 0xBEDF69241D834F56ULL, 0x9EE457B82D53471FULL, 0xD0F80228122826A2ULL, 
            0x8186081804D82260ULL, 0x4FA18E3CFB10C69BULL, 0x13F9E356AA73886EULL, 0xD9C89A375D543881ULL, 
            0xDFB603140C12B523ULL, 0xEFC545BF3DA000ABULL, 0x20109C974882D72BULL, 0xA99539D8BDBCB48CULL
        }
    },
    {
        {
            0x79D7A5E6C9B6B64CULL, 0x7A060BC4F320B858ULL, 0x12CDA2ACEE3E46A7ULL, 0xC1D2810A96DE20E7ULL, 
            0xD8B534D1EF5CC69DULL, 0xF88957B06EFC5E6DULL, 0x00969E7CE19BF854ULL, 0x4AE0FE359792E277ULL, 
            0x00143E6209E80BEFULL, 0xF829F886E5654BC1ULL, 0x8C2DA6B4BE5A88BCULL, 0x554AB002A8C10FEDULL, 
            0xAAF51945F41C9918ULL, 0x3DB6A17101020EE6ULL, 0x29AA82CC31A2282FULL, 0x7BACFE16B020918AULL, 
            0xE1E0479D9970DF5CULL, 0xA72CB7C4FE3321ADULL, 0xD1953E873D16D594ULL, 0xFD44175152AE81B9ULL, 
            0x7019F439B339E6D5ULL, 0x633E543B0116CB10ULL, 0x6FBF93C294F8F917ULL, 0xC7F7BA9206249012ULL, 
            0x1027B78E78E1D127ULL, 0x0E2C9C5C27A0F9CFULL, 0x05E7BF927EC994D3ULL, 0x48C995445AE07E89ULL, 
            0xF6A7AFA238B15EDFULL, 0x400BD01122721104ULL, 0x2EDA2DB13FF6201DULL, 0xF395046DE79AEE30ULL
        },
        {
            0xEE23D79E430961FFULL, 0x448595ACD6F39115ULL, 0x57DF45BBD8CC6C90ULL, 0xA5D2A682F8F40CA9ULL, 
            0x6BDAD79FE5903264ULL, 0x8CA1F3485AEED56BULL, 0x9680C3388B8B9AECULL, 0x1962D74C0B47D870ULL, 
            0x648189DA43912E56ULL, 0x5E31BF15638EB2BEULL, 0x6D4852BC705F8FFCULL, 0x5FC8BB481347E33CULL, 
            0xC2A3CC3B2800D169ULL, 0x830DA30E2E7B1913ULL, 0xED0D992A0A7E93B4ULL, 0x1E2804324AD91952ULL, 
            0xD034CB2808B88C0EULL, 0x570C5AC8CBDDDE08ULL, 0xD59014FDE45C3663ULL, 0x1D4C43A338B75764ULL, 
            0x57294A9B777E62C7ULL, 0x08B4B14B7CD8EBF7ULL, 0x80E4A7C0A6CE10A1ULL, 0x0558D7B487B42D96ULL, 
            0x4A69FA11FBDABCBEULL, 0x654AF85BCF6E2D8EULL, 0xBE3C40A5DEB7A4EEULL, 0x2271482983B29C3EULL, 
            0x7048BE9FC319480BULL, 0x8C70204CCF4C0DC8ULL, 0x2E86329304940339ULL, 0xA2D5F262A692CF55ULL
        },
        {
            0xFC8AD2886D533E2CULL, 0xFCF92C3E445557E8ULL, 0x3F1797A92750128BULL, 0x97F7AD4BCC64DA81ULL, 
            0xB06D82DDF3FB63CDULL, 0xF48FB67925CA5498ULL, 0x744BA38E14F53AEBULL, 0x604CEB41FD09674EULL, 
            0x4B65D116DECE1F5FULL, 0x667B51D4D4690B37ULL, 0xBB99A897A5148DA6ULL, 0xE06DE3D35F1CD247ULL, 
            0xF0BBF5D5ED9C68F3ULL, 0x15E43FA902436826ULL, 0x81183856F0E81048ULL, 0x9DECFD37EE6D81F0ULL, 
            0x825D4CD762D1AEEFULL, 0x781F2A9EAD0B0979ULL, 0x5A2154684F1425ABULL, 0x15C716E7371ABCF6ULL, 
            0x8C0F5F5C4548FF9DULL, 0x4A54E0A66AB0903FULL, 0xDA45FAF8791BD4FFULL, 0xB492891A14338ED1ULL, 
            0xEF33482B8826515EULL, 0xDF83B893AEAFD8ADULL, 0x8D84A6E8FCB14CCAULL, 0x14D9CD0EDD8B1ABBULL, 
            0xFECF143AC9464AC2ULL, 0xB99155156681C619ULL, 0x6EEE0A69413E2111ULL, 0x6F3B68D6ECDCEDA9ULL
        },
        {
            0x0EE9BED0BAFAB4A4ULL, 0xDA7FC2A9C8C57C72ULL, 0x3D0F1A46DD8064E6ULL, 0xBB7B5AC79C6661CCULL, 
            0x2EF485F9F6FA601FULL, 0xC429EABD204920F1ULL, 0x48BB99A06F5CDD71ULL, 0x4C9B4DDF3D7EF758ULL, 
            0x9C73BCA444436891ULL, 0x7381D54123B29F84ULL, 0x94839B7DFA206FA4ULL, 0xEB5E469DFBED4ADEULL, 
            0xCD37D284F448C679ULL, 0x1B3249EB9FBFE4E3ULL, 0xA17A696314070813ULL, 0x8A88102C7EDE4B84ULL, 
            0xD993D5357B1BAB8BULL, 0xEDB0F2EAE940C6F1ULL, 0xFE4F7982411AD575ULL, 0x457C629CFEC9B676ULL, 
            0x8CB504270C5F4F1DULL, 0xEA012AD70CEF4A02ULL, 0xE312D8C982730824ULL, 0xE7438329DD40FB1BULL, 
            0xAF01D8B55AFA5086ULL, 0x20F3925C933FB5CEULL, 0x3E43028AE4875A3DULL, 0x8EB6A15DD128322EULL, 
            0x59108C5F1AFF8A5AULL, 0x9B096FB56999667FULL, 0x512B10112C5677F9ULL, 0x517350DAB376553FULL
        },
        {
            0x9B12D6A274EAA944ULL, 0x550176241D32A0EFULL, 0x1E38A509DC567097ULL, 0x70E85ADBB8034425ULL, 
            0x523FB1A9A3A29CD3ULL, 0x189B71D98584369FULL, 0x14AF3EDB5D2DC937ULL, 0x79DE02E23C74187EULL, 
            0xF7587346ACC43E97ULL, 0x715435E35E917304ULL, 0xFC03B866F9C32C2AULL, 0x41C36DA4D8FF4E61ULL, 
            0x18D1D8C8333368ECULL, 0x5A1CFC72BF0D69B7ULL, 0x31C9FD3D8BEFF467ULL, 0xA8CDB5634B27483FULL, 
            0x884B295FB55608FDULL, 0x74CFFF7FEA08081FULL, 0xA750B311BD9306DAULL, 0x38AFBC942BBD7520ULL, 
            0x91DE191920124C58ULL, 0xACD63E6F24A3DC5DULL, 0x7BC77BF6BC92E5ECULL, 0x0E2E8488F7E9DCE4ULL, 
            0x8D2FB116B4E53E37ULL, 0x7E374DE0B2F33E77ULL, 0xDA4C9B7517ACB320ULL, 0x3A1334B411276453ULL, 
            0x0F686927866A6991ULL, 0xA8327621856B4CC0ULL, 0xD88C0085350AAF0BULL, 0x8EB6669FB71D7DC8ULL
        },
        {
            0x3057353554359755ULL, 0x3EC9F0C1B58E23D5ULL, 0xC2F23AED3EB9BFC9ULL, 0xC6A5973B5E7F3F1AULL, 
            0xB0666B1AE3B93ED6ULL, 0xBAC201DFA5D1F9EDULL, 0x0F53440D1348EE9CULL, 0xF4608EE811C084B0ULL, 
            0xA7FD0CBD91C7DC32ULL, 0x475DB235F8A0E744ULL, 0x13BE53977FEC71AFULL, 0x524B01D6D2EF6D4EULL, 
            0x51DEB581CD835F7AULL, 0xDDF00949171D29F1ULL, 0x2483250BAECBF29DULL, 0x23083F623833F501ULL, 
            0x3182D2FB17473508ULL, 0xB955E66D66F6BF60ULL, 0x53CF1BF1ADA7B6A5ULL, 0xE8CDA7351D70548FULL, 
            0x5E6CF6B9B18E3C5AULL, 0x6D979C6AE127A455ULL, 0xCC7B8291A9EA7007ULL, 0xFFA892B48A495C7CULL, 
            0x6FD7E888A9B3AF17ULL, 0x46DA21263436DB2DULL, 0x562E597E7F4C89CDULL, 0xBE06A06FF2AB0741ULL, 
            0xD60495F409BEBF91ULL, 0xE20F4DD972D8A2B8ULL, 0x48E44201A26D381AULL, 0x7F97516DDCC86236ULL
        }
    },
    {
        {
            0x9D3E918DB130C962ULL, 0x458E8C434B6ADD98ULL, 0x837E7ECBA41DFD5DULL, 0x69ECE2F5428FF491ULL, 
            0xD2F99E436058DF07ULL, 0x046D3B2B9BDA3E7BULL, 0x44A3E6BE81D7E949ULL, 0xC57224B2F2A811A9ULL, 
            0xE973188F262A2B88ULL, 0x383358F895435901ULL, 0x1CFEC82A001894BFULL, 0x77572F9E5EDFB497ULL, 
            0x2CD65AC530DD758BULL, 0x734536F7C7FCF725ULL, 0x67D4E0C91B09990AULL, 0x86C6A60372577D77ULL, 
            0xB3E8FC7D6F7ADA08ULL, 0x4BFDFFA18DE4F181ULL, 0xF36153463CA3C728ULL, 0x1D77E13C1B5B0854ULL, 
            0xEFA55D6B41706F63ULL, 0xDBDA8355129FA3A0ULL, 0x218A9853ECBEAF9DULL, 0x00B99A6078DE312AULL, 
            0x6EFF62B12E259151ULL, 0xC511738FB287800EULL, 0x9D7D775F532CC58BULL, 0x5B85A6B1702F90A9ULL, 
            0xD65234A093116751ULL, 0x48D0307E7C9AC4A4ULL, 0x2371BB1FCB6001FFULL, 0xBE4B0DC3E8AEEE6DULL
        },
        {
            0x41A51C6717115392ULL, 0x0FB23D7D780A1288ULL, 0x672607DFBB59B460ULL, 0xFEA73017D8EAD9E2ULL, 
            0x96EE2EC424141AD5ULL, 0x54A03E3BE292DC11ULL, 0x246CE0925C20260AULL, 0x4DD5762946B010C4ULL, 
            0x35FD8BDBAC1D9989ULL, 0x7F043285625056E2ULL, 0x5D34F9E0E3E93C8FULL, 0x945060E63E75FD93ULL, 
            0x7595581F00D6B852ULL, 0xF6F979C7C0AEDE53ULL, 0x84D7D3BB3466CD92ULL, 0x78EF8604594C332AULL, 
            0x52C98510C9BD8A88ULL, 0x8F00F1E31C0E8C6CULL, 0x94B66C7546EAD0B9ULL, 0x10DBD3FC27F05674ULL, 
            0xBD9E8B1B694555C0ULL, 0x1CD825001DA59A8BULL, 0xCE4AD8A5869B675CULL, 0xDBF3D90D26217D53ULL, 
            0xA4FF54A049E9084AULL, 0x23179200E19B8EF3ULL, 0xC6EC74D569D32C28ULL, 0x769B19AB1E7226F5ULL, 
            0x379423AEE4C25CBEULL, 0xC4B192ED6603793CULL, 0xEF32F3554ECA25E6ULL, 0xDF6F4E2DC4A2C07DULL
        },
        {
            0x6CC532EBF35228B0ULL, 0x5A8475B07EB40790ULL, 0xC620CD7643078F1DULL, 0x6609507909A77E0AULL, 
            0x89328D4B22EE793FULL, 0x7144583C6BD47FD9ULL, 0xDB2C403AF0400673ULL, 0x90C0EC6305C12AF3ULL, 
            0xEF40332C571DB6D2ULL, 0xBB84B4276038D540ULL, 0x85F46AEAF17035C1ULL, 0x35B1CE4131779232ULL, 
            0xDE6CEB5BFB644067ULL, 0x66CB6E0C0231427CULL, 0xF447AB092B5EEC24ULL, 0x819CBC6C0028334AULL, 
            0xCA857B3FAD6C10F6ULL, 0xEBE038D730CA4F28ULL, 0x95F19BB02C4259DAULL, 0x4E981D36D1786431ULL, 
            0x840EF4D9D9D35CF4ULL, 0x7CFDDBBBC0890EF6ULL, 0x6F442A4EFA01E3FEULL, 0x042C486D2EDA0679ULL, 
            0xF4E779631B483036ULL, 0x616E52B9EA59DDA3ULL, 0xE4A8DE8FEAFF6BB5ULL, 0x79D1FCFBB5D71C78ULL, 
            0x4976D839A0ECB19BULL, 0x5C6DC43A79D2F523ULL, 0xC702FA5C82BF10DBULL, 0xCB1E3A54B8E70522ULL
        },
        {
            0x86F7AA6DDBE9E14DULL, 0xDC475DA8C720637DULL, 0x93DFC759BCEAE061ULL, 0x08074170A3BF84F6ULL, 
            0x0776062BFE8F980FULL, 0x1C564A9397968544ULL, 0xD767F63BCD52EBAAULL, 0x7BB7B859D22396F4ULL, 
            0x45E0EB7F47D0B7BCULL, 0xC3DAC50D8F2EED3DULL, 0x8AE9F1162B16DDACULL, 0x4718A2E17F9A0A93ULL, 
            0xDCB2A56DF33376EAULL, 0x77FACE81E9429EA9ULL, 0x63764ED48EF022E7ULL, 0x5CBDBED56A8398B6ULL, 
            0x57E7F21E306E16B6ULL, 0xB2C2234BCC0C18DEULL, 0x04C60833F23C543AULL, 0xAFA118049319F73EULL, 
            0x867535663164F62EULL, 0xD70E2E2402801BB7ULL, 0x2CCA53083F05561BULL, 0xB83605DE19CA6324ULL, 
            0x0A61B042A998D2E4ULL, 0x9DD51CF714952A80ULL, 0xEE8DA696E7F6A060ULL, 0xED15720A974C297AULL, 
            0xA7F8B347F2BBBEE4ULL, 0x82154C8E1B0A353DULL, 0x351DFD638C007DBCULL, 0x1B2B81A0E6746445ULL
        },
        {
            0xAF39C537C7FEBB7EULL, 0xFE32B055FC53F1E8ULL, 0x26934B145D6C0A82ULL, 0x9BD11EA7B8678D9AULL, 
            0x4F40552B53528E39ULL, 0xA505D21FAC6749B3ULL, 0x242AF2B97146699EULL, 0x35C05DB4DE4986C1ULL, 
            0x0D323E5B01DF159FULL, 0xCC0B4003FD0D82AFULL, 0x83D2C778A08D34EAULL, 0x7B3564EA4D19187DULL, 
            0x23EA1DD6D09E3EA1ULL, 0xDC11BF5B32E011E9ULL, 0xBB00064CB89A4C8CULL, 0xE428EE690D0BEA3BULL, 
            0x3A85C9463ABEC067ULL, 0xDC24E5DF67AA3575ULL, 0x5912F7C500086A8BULL, 0x29F406CBB42DB767ULL, 
            0x29C585A62092CA54ULL, 0x3051BAB0C7F150E1ULL, 0xB3AE464E2B3A22FDULL, 0x31DE8FE2F0658A3CULL, 
            0x3CCEC7C0627F495FULL, 0xA3340905960329B1ULL, 0x3917A80E3DCB4764ULL, 0x0E466E920A141522ULL, 
            0xE12B9B52BB5EE142ULL, 0xB01CADB444272679ULL, 0xD907108A650EDBD8ULL, 0xBB99A9346FDE1831ULL
        },
        {
            0xBE9025966AB9E7D3ULL, 0x588740812372C5ADULL, 0xAA0FB4AC9DA59C7FULL, 0x0F500C692489EAC5ULL, 
            0xDE8092B1914B5901ULL, 0xC95258154F5E766EULL, 0x30830A28FE748FADULL, 0xA5342B590B3F3E3CULL, 
            0x2A524CC1534CE56BULL, 0xA5C2D6CAEF24382BULL, 0x8831C4FED6B0BAB7ULL, 0x985E27CFDD583C76ULL, 
            0xCED2E2C388B3D650ULL, 0xFAEDEE73094F0367ULL, 0xDF2DA8F6BF082661ULL, 0xEDC1112997F1D0ECULL, 
            0xB1211CEBABE822E6ULL, 0x2F542644E7B0EA4AULL, 0x6FAD3E11AB0487CBULL, 0x37D4D1ABBCF5EF71ULL, 
            0x75CD0DF63763A169ULL, 0xE6E435A47D2BAA8BULL, 0x6977E633DFF5E621ULL, 0x218C93AC989BA99FULL, 
            0xDC35FE2266D3E8DCULL, 0xA2B759BAD814FCE5ULL, 0xBAB440B797D8AA2AULL, 0x69C69E79B0FE95FAULL, 
            0xD91781F188F909C1ULL, 0xA3CAA40FEC1837CCULL, 0x8CD9D0C148E369F7ULL, 0x6BB07DCBA526BE43ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseBConstants = {
    0x1870E0A1F8D2A332ULL,
    0x96E38FB9AC05DDC5ULL,
    0x1884746193A3B194ULL,
    0x1870E0A1F8D2A332ULL,
    0x96E38FB9AC05DDC5ULL,
    0x1884746193A3B194ULL,
    0x5AEA39F928CE8CBAULL,
    0x8D684AA37503D5D8ULL,
    0xF3,
    0xB2,
    0x6F,
    0x36,
    0x86,
    0x77,
    0x74,
    0xE9
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseCSalts = {
    {
        {
            0xAB038F5FC96A89E1ULL, 0x99817A60F72FC521ULL, 0xEF68889330148CA6ULL, 0x6B5EFB0ECEE311FCULL, 
            0x495DF8AF41E684D4ULL, 0x6A5DA1EC5C851FE3ULL, 0x85B0B3B14D06D0EEULL, 0x4277279578B8A255ULL, 
            0xF1C73D81372332F5ULL, 0x7491F0BBAFD4DB87ULL, 0xCA93FF22719CCD50ULL, 0x890A39D2FB34F217ULL, 
            0xD7C3744FF4222D63ULL, 0xE1CB3D493980C427ULL, 0x6F988F11513EC672ULL, 0x3D51DA0FE23F3E3BULL, 
            0x7D440EDADB6E38D3ULL, 0x63C7587A976A0383ULL, 0xA264EB5078BDDDE2ULL, 0x6C82CC6E01E51D2FULL, 
            0x6DC625B2FDE17553ULL, 0xE3EE81E9B1039373ULL, 0x7584FA5F4DFED8E0ULL, 0x2846807CADE9A972ULL, 
            0xFD921EAE209316EDULL, 0x38E658B6191A761AULL, 0x3B277D73F430579EULL, 0x9A52380F6C0433ABULL, 
            0x432F5DBC9B61E50CULL, 0x7419953FDB5C72B9ULL, 0x4E978F29DC70A864ULL, 0xDABC97762C5F8A88ULL
        },
        {
            0x40F122AF37AA6D0BULL, 0xF3C4D771A7D1822AULL, 0x5825F84E053B3262ULL, 0x821839F35F77F46BULL, 
            0x3B544D398EE10360ULL, 0x5F9E6E559982551AULL, 0x0D7EE7E96978D4DBULL, 0xC385994F28E18AC4ULL, 
            0xFD903321B8FA717CULL, 0xC19D342706062305ULL, 0x01F31516093E124CULL, 0xD480EB33FD26891CULL, 
            0xAD0525DFD17B85ECULL, 0x8D578CE94EDB6CE6ULL, 0x3C6694D05A93C2CAULL, 0x0F40CA2FC44A133AULL, 
            0x61C616703AC7C0B0ULL, 0x31E801E9B7FC26BBULL, 0x7DE1B14EB7F26FF6ULL, 0xF608735C13B30CEDULL, 
            0x3CA3E3CCB46EEBCAULL, 0x39122D1A98D33DD1ULL, 0x9AE874BA8E91A56BULL, 0x442C86244936DCF8ULL, 
            0x70BCAF4C0A935E6AULL, 0x3BB2EC6D25EBC8AAULL, 0x442303675DB1C8CEULL, 0x537B376A7478676AULL, 
            0x8089F49235374242ULL, 0xD11884F53DE6E3E6ULL, 0x681A127DC113985EULL, 0xF66D2732742C05C1ULL
        },
        {
            0xA68EC6E76C4769A0ULL, 0x0F020805DA87B49EULL, 0x836E2B0816B02B22ULL, 0xD6A77B6919AB1BFAULL, 
            0x5EE213439AE4A024ULL, 0xDEB1604BB0E4EA5DULL, 0x6AC2B76FD875FE5FULL, 0x1CE57EF76A54D6DFULL, 
            0x44312DB5D94B24B3ULL, 0xBCDB624E61E5CCC3ULL, 0xF8CB2C8D596B4F66ULL, 0x4E8C696DF53FF579ULL, 
            0x38F16D5F46C5091EULL, 0x581339CEE4A3AD0EULL, 0x882A54FC9A08D759ULL, 0x50ECA434CBE975D7ULL, 
            0xA9318F2CE91E4960ULL, 0x539FA303B221CEE6ULL, 0x9447505D0BA0E1D5ULL, 0xEFDD68A280C283E9ULL, 
            0x5B885BBF3500EAD7ULL, 0xB0A14A1F7883E4FBULL, 0xE712D2D389ED4BF0ULL, 0x8BE3D55300291583ULL, 
            0xFCBA8628FC65131FULL, 0x19FD102302597C91ULL, 0x4AEBB076A4979ADAULL, 0x384E1E1CC3EE40E7ULL, 
            0xA2F36384BA17C3DEULL, 0x3BD82F9D1A22AFC3ULL, 0x93F0AF8FDA913CF7ULL, 0x38F5F2B58B6CC64DULL
        },
        {
            0x120E521F73175155ULL, 0x08D641F633E433C8ULL, 0xEBC54D27DF31AB98ULL, 0x0FCBD17A30FD0204ULL, 
            0x4449E9DAC3A90DB3ULL, 0xC519D8AAD0423BC3ULL, 0x346C89DAF1460692ULL, 0x17CD5BEC0EC3C38CULL, 
            0xB21194C7FDF9B833ULL, 0xC6DD5B699CC11BF5ULL, 0xB94D11843349B41DULL, 0xCAA4D2D9DD57BF93ULL, 
            0x89A850A66E97D348ULL, 0xFE612C26809E57E0ULL, 0xF46BFC1A600B8CD2ULL, 0x3254FA25A7B3EBE2ULL, 
            0xB7CE4F6922AEAAFBULL, 0xDA3998BCADEB24BEULL, 0xD0BE210AAA912925ULL, 0xD5A2EC5F963E40AEULL, 
            0x9EE87F567BBD310AULL, 0x8A1C5561D9964837ULL, 0x84B4AD67CBB28844ULL, 0xEA6219F5E3E2ACCBULL, 
            0x2055E4D62FD0E0D7ULL, 0xD3236CDF862BA821ULL, 0x58CDDCAE06D48080ULL, 0x46F7FBE506A0BDBEULL, 
            0x02F8CD3F17E10DBAULL, 0x38BFC707A9ED3700ULL, 0x5484FAD08B042F9CULL, 0xE3D3220B9E2E39BCULL
        },
        {
            0xCC727DE50B98239AULL, 0x5A4D8190DBD96C4FULL, 0x992E2E38301CFCEBULL, 0xF6565BBED1FF5EACULL, 
            0x87B1EA86D66BF6AAULL, 0xCB72694EF03A9800ULL, 0xC7EE48118C271711ULL, 0x0297313D483A868BULL, 
            0xD34413877A754784ULL, 0x075D736152D633BFULL, 0x93224D6A09DA204AULL, 0x47646F45DEC44F7EULL, 
            0xF2175BDC80AB49F6ULL, 0x7F1643F1E4A528E7ULL, 0xB296B2757DE93B82ULL, 0x695743700118A05EULL, 
            0x7C95E90A02CED5ABULL, 0x66EBCDCB8ECD165BULL, 0xE7F9F1558CEB3850ULL, 0xC77A7F91D27589B8ULL, 
            0x74588E5E2AE7F687ULL, 0x1A284041FCB78F3AULL, 0x1FD49E4DEE1245D6ULL, 0x11D2288FB6059236ULL, 
            0xF096E5F8EFF9A4FCULL, 0xC56BCE78770D72B4ULL, 0xDB131A2B4756A5CDULL, 0xCE10E69E27882515ULL, 
            0x83605EA622F34947ULL, 0xA210854811629C07ULL, 0x0267DC1F3C04888FULL, 0xF259F17BCD11E976ULL
        },
        {
            0x0A62F8007E75A92CULL, 0x9B396A7CF7964FF6ULL, 0x83C0BF9B655FE2DAULL, 0xBC1B3A0C411E7652ULL, 
            0xC083DCC43DD5DF61ULL, 0x01AC4684E7ABB3BAULL, 0x4636C1882C7F1F3DULL, 0x42D851ECD052F92EULL, 
            0x9300124C4AB945E6ULL, 0x1B8ED1280A9C5753ULL, 0x3DA1219131341653ULL, 0xDEEC2C2252F3F1C2ULL, 
            0x3A67E989EBDE8E02ULL, 0xD66498A0BF74B581ULL, 0x30E31299D2A7C32AULL, 0x38AB5D8C4A76EF89ULL, 
            0xB8DD5362A4297182ULL, 0x5A42F9033E1F60F0ULL, 0x71090884AB00EFDDULL, 0x649781E1D77F08A9ULL, 
            0xB4873EB003C44244ULL, 0x2D210A71DACE9B3AULL, 0x42C030FC717AE7A3ULL, 0xEBA2A396B69FEAC9ULL, 
            0x1CD27B2E4C419979ULL, 0x922ABF44FBC71D69ULL, 0x00E48ECE69D16EE0ULL, 0xFB772D103313ECB1ULL, 
            0x4779C38D6A4B6CD2ULL, 0x1E9F1A49DF0B8F3FULL, 0x8B835B5FDED8E024ULL, 0x1F54BD2B3F0BD0CDULL
        }
    },
    {
        {
            0xBD77EE832B1554F4ULL, 0xFB5E5A88CA944A74ULL, 0x531E1073E8E7E5C6ULL, 0x3A49E6FA94266116ULL, 
            0xBEBBA5CEE51AF99DULL, 0x08863B8830163DB5ULL, 0x41BF229C697C4F86ULL, 0x892C1AB5A33E5A2BULL, 
            0x48C202926CAC0664ULL, 0x2D404B4266558E96ULL, 0x7488E4D5EF4989E5ULL, 0x2B2E10A3C67AA09EULL, 
            0xF49BE1D9B6F5E380ULL, 0xB231D125F598F507ULL, 0x0661B1AD44924C0CULL, 0xB1B9BA1AF8FB8017ULL, 
            0xD0F7D97211DA37BAULL, 0x788C3D55955F260BULL, 0x54F1DAF17F0A602AULL, 0x06D175AA5BC3DE37ULL, 
            0x301F4C1CE2585F82ULL, 0x09ECAC7082F364A6ULL, 0x3CC0AE6B580A9C6CULL, 0x23B9AC3E2258DDECULL, 
            0xD112362A69F0A8A5ULL, 0xC3FDBF66F73180EDULL, 0xE79483CBE7E78A00ULL, 0x47DDC995AB1445FDULL, 
            0x8FA5DC96290CF3F5ULL, 0x0D1F74E537609B68ULL, 0x16BA837068CA8A2AULL, 0x798E35910DC181F9ULL
        },
        {
            0x7DE8D480E61AC5C3ULL, 0xCF453E1E2B1DF4A6ULL, 0xB7F58C7F9F1A2999ULL, 0x14E95C0373CCBAE0ULL, 
            0x412B77544E83F12CULL, 0x80A0111DEBA74C4DULL, 0x72AEDEE95B105DC5ULL, 0xE7A11CF50897DD34ULL, 
            0x54B1B774BA8D82F8ULL, 0x97B8E58ED29D9D49ULL, 0x2E7DF56E6C04E363ULL, 0x7F6A818E7BF0A7C7ULL, 
            0x49766FD1619379F7ULL, 0xB0F8315D3CDDF4C1ULL, 0x1597AC38F552AE92ULL, 0x1DFA90C87B527B7CULL, 
            0x9E12FE27068C8F59ULL, 0x2092218A8C526B01ULL, 0x6C6BB0934B48640DULL, 0x69B1B489EDDF9CF3ULL, 
            0xF4209B8706A5F102ULL, 0xD91F9E34ECDCFEDCULL, 0x5AFC6EF290713D08ULL, 0x8051B3DC9DFA4495ULL, 
            0xEA6FE6C3DD9DD8A0ULL, 0x1FB0257071C16FDDULL, 0xAD6537AF76D29D95ULL, 0x017CEC7259F8FE7BULL, 
            0x7085ACDF22DE25E4ULL, 0x6B4831DCA8F0902FULL, 0x443295A15B8748AEULL, 0xB6939DF823DF0F8DULL
        },
        {
            0x32EF059B8811993FULL, 0x2164CCFF67245F94ULL, 0x94AB174DE34992F8ULL, 0x0079F1FDF6F4580DULL, 
            0x1B8BEE3214BA2BD7ULL, 0x27A1977E59AF5770ULL, 0x97D7D2D2FACCF8D2ULL, 0x8AD4545505D3C0EBULL, 
            0xD3317158CE1B5A5BULL, 0x8D5B70E9BEA2BD77ULL, 0x48284F7F615F0108ULL, 0x49C83753069B5BFFULL, 
            0xB4F55ED0D2B84FC4ULL, 0xCBBCE33864FDE792ULL, 0x1A3FB71E9F62FA67ULL, 0xA02581776937CE93ULL, 
            0x23E0D042D80C0AFBULL, 0x085AB83228B09B2DULL, 0xF00A9C47D399FCC7ULL, 0x046D3F7A32B80483ULL, 
            0x3CBA649569BC069EULL, 0xAF70BC4C39FCAD76ULL, 0xBAD3C8F3D22B84A7ULL, 0x9A5E95D0381CC574ULL, 
            0xF68D0A3EF484CEFAULL, 0x9D9666A3F1EA9388ULL, 0xA0845BDAC552E537ULL, 0xA6D58B7D82BCD0F0ULL, 
            0xEF3D24F5E3EDF5BAULL, 0xF2211698398C046EULL, 0x728E4D66C80255E5ULL, 0x43242EB8BD362305ULL
        },
        {
            0xD35E843FBC35B5F6ULL, 0x657843E68A83878FULL, 0x7FB9CF6ADBEE0D8EULL, 0x8AA11FDCE535ACB9ULL, 
            0x3F58C63BF543BE28ULL, 0x7D7A81A938C4B73EULL, 0xF4E49C59CCE4BE1FULL, 0x7F5BD69CDD2BBEB1ULL, 
            0xD80AC882ED4B4B1DULL, 0xB5545D0AA187DBBEULL, 0x11ED45F144DEBA4FULL, 0x44FCCD905B82AD44ULL, 
            0x105A8732AFD63802ULL, 0xCDBEC4491E7A705EULL, 0xF1AD7D2D46AFEBC0ULL, 0xE62E7BBE83625A60ULL, 
            0xA366D0284CD1ABDEULL, 0x1EAC27B28FFC0189ULL, 0x40FEF0788CDBB06BULL, 0x586FDCCAB2CABE79ULL, 
            0x98913C511C7A8F58ULL, 0x8CDE667306436E5AULL, 0x10DF64D418281408ULL, 0xC90029D8F9EDF48FULL, 
            0x980FA5FE1516505FULL, 0xC4AB82B28C6696CBULL, 0x2780D1250ECF7F83ULL, 0xF1D05915AC951653ULL, 
            0x1E55549DEE8E5706ULL, 0xE72AA87BD8E72DA1ULL, 0x225BF49633FCB359ULL, 0xCBDF6F5F6FBD146EULL
        },
        {
            0x337E4EE4A1E462E3ULL, 0x98D5ABDB99587651ULL, 0x3114B9766A96268DULL, 0x37E245B4A0DE8798ULL, 
            0xD007305847EBCF7BULL, 0x0408AA9350044ACBULL, 0xC5601CF30960A06FULL, 0xD7B60A46ED84747DULL, 
            0x6CE9C2D7BEA704EAULL, 0xE1499143BC386BA1ULL, 0x953E5DA256AA29ADULL, 0x5F5FF24BB60A2AEFULL, 
            0xE7339B69AD076983ULL, 0xFDCBBDAAF1FD46DDULL, 0xD31D920442943094ULL, 0xD7D4F23B84065BD4ULL, 
            0x503F684DD4ADAE55ULL, 0x0DD83B21D1E3D957ULL, 0xDD27513314D34319ULL, 0xB06950826582BC63ULL, 
            0xF5530356DC5705E9ULL, 0x369835984D1DC5C0ULL, 0x1370DBA9117A5C8BULL, 0x48D2DA3CBB1B61ECULL, 
            0x23FAA5C6393EA3D2ULL, 0x20EB82A2A3388F85ULL, 0xAB2DE5C732FFE2D9ULL, 0x6F51933EF04923D7ULL, 
            0xBB4447011CFDA887ULL, 0x44DDD9A334574FBAULL, 0x990F3652F2688DEDULL, 0xD36B452418A27A84ULL
        },
        {
            0x2865E1912000D056ULL, 0x4AB056725BDEB522ULL, 0x0C6BFAF295EBC62BULL, 0xB28A1235C73762BDULL, 
            0x578336F5EAD2769EULL, 0xD0F4D7A137236D0CULL, 0xC65A986758A22BA8ULL, 0x2939C8C99B99CC03ULL, 
            0x1621618C3ED265FEULL, 0xA1C38B3794C2A743ULL, 0xE6C2CA14AA04853FULL, 0xACFF4A006B7B70CFULL, 
            0x28D1D9D944A553AFULL, 0xCE3C2C1D72944095ULL, 0x377DF2C6B56D1559ULL, 0x35450CFF3383AA6DULL, 
            0x78DC0CB5B1EC8B11ULL, 0xA7015374DB01C8EDULL, 0x694120DBB6F03E6EULL, 0xB2314D4DB9F8A737ULL, 
            0x4E05E5899D70AD5CULL, 0x464A9D6E24968549ULL, 0x9CA9C1C614A8058FULL, 0x9C5EC8693D511233ULL, 
            0x184EC12D82C4F781ULL, 0xAA85512E2F288E74ULL, 0xFF17BC9A96C3371AULL, 0x51A367A6BFEA0805ULL, 
            0xCBEBC18172702A79ULL, 0x009944F5B8EF5EEAULL, 0x82D583162D8900A8ULL, 0x599E7DBEA3FC9E2DULL
        }
    },
    {
        {
            0x7C5F66996F486956ULL, 0x599A7F89D1B3821DULL, 0xB0D4122A3BBFD40FULL, 0x9ABD3A5DD9F3A853ULL, 
            0xD81729D9680E9F63ULL, 0x67DD7D0C63E65E0CULL, 0xDAF75927789A98C7ULL, 0x8D5556C7DA3BFE37ULL, 
            0x5E5FAC0E823B92A4ULL, 0xC28AF3806C7B39ABULL, 0xE2328D90B4672811ULL, 0xE2386F8CC7781623ULL, 
            0x36959F0E8E615E64ULL, 0xA759D929A833AD82ULL, 0xE7BD2525C3CE3D63ULL, 0x8B2CE553658B1811ULL, 
            0x50ACEB15AF42AF18ULL, 0x8BE5A302C8782802ULL, 0x7BA73806C3FF7E7DULL, 0x1C0149F63E41AC0AULL, 
            0x5ECD1F2D6418AB92ULL, 0xB5698CBBE591EF36ULL, 0xCF1137B5996FCD92ULL, 0x32D4F331E65CE8DAULL, 
            0x9236336EFDD2952AULL, 0xF1014D25327ABC4FULL, 0x62B45FB2573D6C52ULL, 0x173A01DC29BD8910ULL, 
            0x3815B8EAA70A49A3ULL, 0x9CD78E4E9D768FC0ULL, 0x13DF5261A3F67782ULL, 0x1F024E0BEA940EF6ULL
        },
        {
            0xB59DFF6E3A5A9B1DULL, 0x46754EE8D3A7C842ULL, 0xA8B8F02B017B55B4ULL, 0x84E686A49CF5391AULL, 
            0x628E7F312BECC6E9ULL, 0x350CD3E13B739CAAULL, 0x927D57B5753C26A8ULL, 0x6EA518221FAAE49DULL, 
            0x5ED1720FF5BDE408ULL, 0x363205ECC757860DULL, 0x77B1E66985E58DDEULL, 0xE4597BB964F2AD6DULL, 
            0x2BD44B6ABFA7BCA5ULL, 0x57E1C9D259452A0CULL, 0xEA30E2608285744AULL, 0x84055C230A7E9EACULL, 
            0x43DB9DEF93F438D1ULL, 0xBBE290AA9EACE0D5ULL, 0xD08474AAC48F29F2ULL, 0x5CF3AD7D68748F94ULL, 
            0x4A35BB7D9AEAC61AULL, 0x13F710513BD25492ULL, 0xFDF235AE71D86F07ULL, 0x18E13589A74726A5ULL, 
            0xCFCDC8FD00BA8EC5ULL, 0x30C775497081C0B5ULL, 0x0680DB3237716890ULL, 0xEC42178F5A36DE50ULL, 
            0x9E4A328339AB7463ULL, 0xAA1C0881C64538DFULL, 0xDB1975EE9623EB77ULL, 0x3E43D4113F3E9B65ULL
        },
        {
            0xF7E976D862627C17ULL, 0x4762BFF0229A3C14ULL, 0x2AADAAB534D5041CULL, 0x776B024F29D195F9ULL, 
            0x1E90B9A34B2D0BB7ULL, 0xE3CEDBC2C98566C1ULL, 0xEEA14E176392AA53ULL, 0x27E9E7B9580F78F8ULL, 
            0x0638DFADC0615BFEULL, 0xA8FEC81D9945E278ULL, 0x813237D8C276D05BULL, 0x22F341A04945EE86ULL, 
            0x8F47218F54A5FBC2ULL, 0xF405FAF93841BC29ULL, 0x56822036DB106170ULL, 0x20D8E0E7240DDE77ULL, 
            0x329EAC957A0F04A9ULL, 0x86256A88437F6378ULL, 0xA205955E6D1D34FFULL, 0x90E292DF42CC432DULL, 
            0x331B2F4DB3601AA0ULL, 0xD0D295A2CFEDE40AULL, 0x35DB825568A22D28ULL, 0x55FC64585B7672A9ULL, 
            0x0A7A4093414AF6ADULL, 0x3B707886921A757EULL, 0xA89A6C88D8BBCDC1ULL, 0xC1E3461B5D0E6301ULL, 
            0xF241F2533D5185CBULL, 0x665DC7D2A0DC01EDULL, 0xA47D118656817AB6ULL, 0x643D31273D6CE133ULL
        },
        {
            0xBCE566C6CC50B79CULL, 0x7E6915EAE00D5140ULL, 0xDEBA9E36754E6513ULL, 0x4031BC907AE890A8ULL, 
            0x0F243C04D915820FULL, 0x7C96FA030B4BDD23ULL, 0xBB46EDD95134418BULL, 0x2BBF7910EEFF9F8AULL, 
            0x3A0D0B93BA94FE8BULL, 0xA754E91446A9A117ULL, 0x888CB9B7FD6BAE29ULL, 0x8D3788D2A2C48428ULL, 
            0x66CE304E65EAD980ULL, 0xE03A279FFBE7A053ULL, 0xAED08A6F1ACA8941ULL, 0x2BA45535ED290E74ULL, 
            0x05B1AD4652C523FDULL, 0xF06D60FE67D8D0BEULL, 0x73441EBCACD97834ULL, 0xDD19168631A6EB5BULL, 
            0x456CEA9A051920D1ULL, 0x013F33C1F9CF4AB7ULL, 0xF686BF6EC61DA91DULL, 0xB88C705F3FDA708CULL, 
            0x1132D2D0AB5EAAA5ULL, 0xDE4A6F6CC762E7A1ULL, 0xD3309101F3271ACAULL, 0x87FB3818E59D901AULL, 
            0x3B33D7677610702EULL, 0x61F4A9CCA44D6655ULL, 0xF45E81A45D55DDD9ULL, 0x57E62DC54113E704ULL
        },
        {
            0x00E61A94DBC31489ULL, 0x900759391B56F6F3ULL, 0xAA8D203CA30C6C32ULL, 0xA13290284E66AD4EULL, 
            0x6EB9F4584DD5388CULL, 0x169C64B8B39E13F5ULL, 0x91E3241F3611679AULL, 0x4A7D149927573A58ULL, 
            0x12A2EAE534763A67ULL, 0xCB0F14237F509998ULL, 0x9098C6D88B2E10AAULL, 0xF75E2DEFA218AFE2ULL, 
            0x2F9169D484FAD3D6ULL, 0xB72175D6F63EA4F8ULL, 0xFEF825B5CA427115ULL, 0xD2A7EC0E3AA91639ULL, 
            0x812661603AABF98EULL, 0xC1A3073EC63807E9ULL, 0x4F30B148CE630933ULL, 0x80A043BA99E5785BULL, 
            0xD90C16721C82DA78ULL, 0xE238085A41D451E1ULL, 0x41C70AB7C446905DULL, 0x85ECE83CFC69B55CULL, 
            0x770BD9FCDED86DCAULL, 0x44A9A167AB51CA5AULL, 0x6C23A3B0CC21ED30ULL, 0xCB7AADBFF6A15684ULL, 
            0x90EFB24E75D72735ULL, 0x064600798945BCF0ULL, 0xC450EEB3D0064A73ULL, 0x2D3BCEC427F34D2DULL
        },
        {
            0x825BA188819B6951ULL, 0xFDBCE0CF29971A97ULL, 0x72CB0B2E48CCA7BDULL, 0x593D5A9EF93D2CC9ULL, 
            0x353142A57FBBD69CULL, 0x23DA26D78A6F89C0ULL, 0x172B80FF9C2C496EULL, 0x662FD6179ACB42D4ULL, 
            0x57E4519E79E02E1DULL, 0x15F2FF312D30003CULL, 0xFD135CCD4B5FB88BULL, 0x5D5599AD8898B957ULL, 
            0x314D2B1ED2F15418ULL, 0x7DDEAF247E8BBE09ULL, 0xEC76D29FB63A953EULL, 0xFE93305FFDE849E9ULL, 
            0xB78F218455627424ULL, 0x3479FEC4DECA0028ULL, 0xA25D404E00A5E810ULL, 0xBB88D0603A69C027ULL, 
            0x4459DF553F0C095BULL, 0x9E6EBD8EAB0440DBULL, 0x28C4A5F2B4072673ULL, 0x4BAA4EAE11AF2B33ULL, 
            0x7B9C20FCFA15FD8BULL, 0x09E4CD49EAC5D2D9ULL, 0x7C210EC515D18F5EULL, 0xD11921E4F5871D4AULL, 
            0xC5980DC7F99BAFC0ULL, 0x2C42ADE3FB24A3C7ULL, 0x497617BA598CB205ULL, 0x797951C6F643AAA3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseCConstants = {
    0xDFE4F910C6F0CE0EULL,
    0xD1D29B3805C87AA5ULL,
    0x028913AE939D0598ULL,
    0xDFE4F910C6F0CE0EULL,
    0xD1D29B3805C87AA5ULL,
    0x028913AE939D0598ULL,
    0x30DA13127AF579EFULL,
    0xF984B06CECF994FDULL,
    0x36,
    0xCB,
    0x24,
    0x8A,
    0x6B,
    0xF4,
    0x4A,
    0x99
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseDSalts = {
    {
        {
            0x0283AB5FB9BA4665ULL, 0x66390E12B250B5B5ULL, 0x5B9016A9311916EFULL, 0x79281A9274CEB9F3ULL, 
            0xC6C7DC8116E9B2BBULL, 0x707469E168368F0DULL, 0x91C64B7E47ECFE38ULL, 0xA25C471D2CE1ED30ULL, 
            0xB5986D7E4C94C76DULL, 0x81388E1C4C6CF306ULL, 0xB68E378A3B7621F3ULL, 0xF2D969CE0FE6A12FULL, 
            0xE238F4606D17E2D1ULL, 0x69875089C6D714D0ULL, 0xD09777BEFF72AC05ULL, 0xC4978D3DF40003B9ULL, 
            0xFF5CF60C90E403A3ULL, 0x7903329F379303DAULL, 0xD4BD238206FEA73BULL, 0x8D3DB077AE6364FCULL, 
            0x52213BDD4994B284ULL, 0xD81675ABF6E35845ULL, 0xD4F4B4290E79A994ULL, 0xB26F9811815C25C8ULL, 
            0x59EF495FDDA5C7EFULL, 0x668DB489FF29DA30ULL, 0xA34FCBF76A49B6BDULL, 0x359F4E4C6559E39DULL, 
            0x1D868FA8EE4009EBULL, 0x64D209479E255BF7ULL, 0xF692997B678A3BC8ULL, 0x0E3CDC1DAA49167FULL
        },
        {
            0x313342D6DC133E3BULL, 0x046E6A8A0AE80503ULL, 0x2B1DAC0253304EC5ULL, 0xF89425E1A8B5D5F1ULL, 
            0xF3E61207FFA27419ULL, 0x3DF6039CD2959DE2ULL, 0x84FB012E46CF4977ULL, 0xE752EA2E3C27BFD8ULL, 
            0x2713D1C40CB86913ULL, 0x6AD501676B9FD939ULL, 0xCB23E16928D5195CULL, 0xEDE8E8706B5FB4F2ULL, 
            0xB8D496DB3C32E199ULL, 0xEA3981372770D878ULL, 0x10FED99E259DDFACULL, 0xE6ACBCC269E7678DULL, 
            0x7C7450DD7DCD8205ULL, 0x473EF703BAB167CFULL, 0xCDE0C4B25B99EF00ULL, 0xA58C2D52D0C18DB5ULL, 
            0x54B29A573F7DEBB7ULL, 0x10BA1D53CBD11FFDULL, 0xD0D075A5B3672179ULL, 0xB83B32D176DE2815ULL, 
            0xD7AADEF522C21F94ULL, 0xB055FA659CAFAF3CULL, 0x088151174BA47F00ULL, 0x4B1657C6BFBE7A2FULL, 
            0xA45C15DB7E575804ULL, 0xB7AEB9DE05E3D3E3ULL, 0xC874495D698523C4ULL, 0x8B6E44CE3204B5FEULL
        },
        {
            0x898C0FE583BF15F6ULL, 0x0603E18048E72C66ULL, 0x84F11D4B6A64D12FULL, 0x439E332D1FCD4828ULL, 
            0xD1A126351EF4D7EDULL, 0x821B04CF4ED4BC33ULL, 0x0DC1EE9F3BA6F288ULL, 0xAB3869CDCFFDBF91ULL, 
            0x7A889F1F4422301BULL, 0x29780B5AA5423809ULL, 0x79D2CE506F816AE3ULL, 0x575E335CA36554A8ULL, 
            0xD96D1A50F550C3B6ULL, 0x1BD39AFEA724BB4CULL, 0x6822C4D350EDE88DULL, 0x8480E657B7935062ULL, 
            0x8ADB85B2F4845DD3ULL, 0xFD7616CC09F7323BULL, 0x92A25379A02C4F7DULL, 0xDB3B48D3454A85BEULL, 
            0xA6D9EAB0CAB98F2AULL, 0x523FA42BE755A943ULL, 0xC422CD4F2F82C1FBULL, 0x2B249EC99396B66BULL, 
            0x9B156AFD4F65670CULL, 0x7F6695C950F338CFULL, 0x46EBBCE78EA25575ULL, 0x56AE73E6A4B35C48ULL, 
            0xD28BD6A091579BD3ULL, 0x26ECDCB2442F84EEULL, 0x7028C6638650B554ULL, 0x9791B76467175BF5ULL
        },
        {
            0x1031403E8EC248A9ULL, 0xE5D4D222A9FBDBF4ULL, 0xEEC599C155BDE5BCULL, 0xF21EF74C48642BF3ULL, 
            0x2DED16BB22E701F5ULL, 0x7BD3E6CBBF5AEA9DULL, 0xB947C0289DAF4002ULL, 0x5C62E5D90B26BCC5ULL, 
            0xD408D49D926A3793ULL, 0x643C17711330EB7AULL, 0x6C53737EEDC7FD4DULL, 0xC3ECC7602CE37274ULL, 
            0xD58BDA39D59F7389ULL, 0x89E5D588F6C3760DULL, 0x95E9FE6A6884AA33ULL, 0x86A1216A9E9EB46DULL, 
            0x08EF6AEA7DD88ED8ULL, 0x0C0E07634FB23957ULL, 0x8D2689E1547AB26BULL, 0x247AE810594A324DULL, 
            0x4904384BC9C2FF84ULL, 0xE4EE9349037B9188ULL, 0x12E022F2F5266A17ULL, 0xFA466286AEC60B9CULL, 
            0xBA654C0D58D47775ULL, 0xF2390B9C290B2625ULL, 0x4C2C8ADCA537C0F5ULL, 0xE95E1BA5A6B77EB3ULL, 
            0x70BBFAD5ED4AE9E0ULL, 0x2787118469CF9D16ULL, 0x2101ADAF28CFA1DFULL, 0x9AE6FB67754D3216ULL
        },
        {
            0x93E25A11F05FB1A0ULL, 0x63E7BDCDA3CBC4EAULL, 0x14DB14BBCA31B3E6ULL, 0x625E119EC2FD5F86ULL, 
            0xDBE0BE60A9AE34D2ULL, 0xC0200962E26B3418ULL, 0x8272EDB9D15CFD6CULL, 0x182310C8C2219384ULL, 
            0x6D2F545DE53C9BFFULL, 0x5CEC5A3768C3C254ULL, 0x17F2997A4F5E9450ULL, 0xF4C6A704583C35E2ULL, 
            0x7235A54B53E356F2ULL, 0x1F2762FD232C244DULL, 0xD4F8DCD6916D525EULL, 0xC7FD2A7ED324371DULL, 
            0x813FF92262206814ULL, 0x44503B5AECBDFF07ULL, 0x127E5C47626FCE2CULL, 0xFC635089266F0A61ULL, 
            0x05B5E7E7FA830554ULL, 0xE15B5F4C7840F2C4ULL, 0x8B054FB1D926BDF1ULL, 0x9C7D9F8E637FA703ULL, 
            0xECFABECB3B6E5D3AULL, 0x6ECDD0A915A479BCULL, 0x061B60E6952D9AB3ULL, 0x5EA56C6C5C152C17ULL, 
            0xBF056B90C5C55B48ULL, 0x4682B45BDEC642CAULL, 0x7EBF733D974ED291ULL, 0xFE35EF6C2AAC63B4ULL
        },
        {
            0xE44947990CE498F3ULL, 0x4F82559A8AA1CE46ULL, 0x4934C3111AB36104ULL, 0x3AAC3CFE26276D52ULL, 
            0x9F644CDAFB80B4EEULL, 0xC102C325822DDB3DULL, 0x0BA4F26F6562A375ULL, 0x3C3F307F1A51A147ULL, 
            0x49BAFA4857AB582DULL, 0xDDA29E7A36395B50ULL, 0x5B718EAC217A8706ULL, 0xDADCDE08FA1C5E06ULL, 
            0x5C4278C22A0CF99DULL, 0x16042C8C786544F9ULL, 0xCBADC97EB88A16CCULL, 0xB4968B03D731FF41ULL, 
            0x8493B4A43E55C93CULL, 0xAD9D1C4898762D36ULL, 0x7C3EDB70D42DED99ULL, 0x01BF6A8F953D349FULL, 
            0x88F27BEB07B3A718ULL, 0xABC903A745B5C813ULL, 0xD14920B04BDB2833ULL, 0xA66BA0DAD931D0EAULL, 
            0x186BC5BC1B96063FULL, 0x0262546EE03C19B2ULL, 0x4076B39D935065D9ULL, 0x8BAB32499AC3C88CULL, 
            0xFAC18F605AB4E3B5ULL, 0xFE8FFF19E5A8BCBBULL, 0xFF4BDF8E2CA215E2ULL, 0xB2787CC54F8637F6ULL
        }
    },
    {
        {
            0x2C2FF622978BB3C9ULL, 0x480B9B1AF4206422ULL, 0x96EEBB14BB02EFE0ULL, 0xBB50B0051C24D7C6ULL, 
            0x9D5617671E09A731ULL, 0x5B98B3910A574F1CULL, 0x6788F48C45EA7C25ULL, 0x67DCD061DD73AFCEULL, 
            0x76B6F10F1A6A92B0ULL, 0x158C2611464EF31BULL, 0xFB42CF1DA4BACF37ULL, 0x137F708B2B383E1DULL, 
            0x980F7F76FCCA3262ULL, 0x0093DDBD499CAD58ULL, 0x5BC1FBD8D1E2469FULL, 0x6A15A94B8FFD5F9AULL, 
            0x738369E2C97F2A1FULL, 0x9AEAA37D1FB90BDAULL, 0xDD0906128587F9BAULL, 0x6ACDD03797F7CBE2ULL, 
            0xAF53F39DE61F6B6CULL, 0xC46B2786B844DDB3ULL, 0x95A0997F91590F91ULL, 0xFAFB7CCD34E59FF8ULL, 
            0x4A4B03B6F4DE654DULL, 0xECFD487BAB2799FDULL, 0x4AF4D95397F93DFBULL, 0x11F569B6DC9E5A0CULL, 
            0x2AED197895161623ULL, 0xAA8247016461C793ULL, 0xD4AF169C499738E2ULL, 0x2BDAB6E4437D5BB1ULL
        },
        {
            0x984F99F3381E2232ULL, 0xD8D1D26674CA552CULL, 0xCCE8959B03269300ULL, 0x79CD8D8E9FCE281DULL, 
            0xC58DCFADA276310DULL, 0xD45B2FB36AFE601BULL, 0x44CB10BB6EC2D39CULL, 0xE8C965297203283EULL, 
            0x3AE2EFDB8138A709ULL, 0xAD1A924A1808C98BULL, 0xE3787D50F80338ACULL, 0x3C4A99D317CAEDD5ULL, 
            0xEC184C365BBA9A58ULL, 0xB58D0E7F3C5F48CFULL, 0x5AF15EC295FB0EC0ULL, 0x096D6C18C6CDD35EULL, 
            0xF2461941131D4092ULL, 0x34630C83119BBC95ULL, 0x8DE20494601987F8ULL, 0x3A3C7E6EA98363D4ULL, 
            0xEFDD1E3784632218ULL, 0x79DC8DAF31EF0756ULL, 0x730545B7BCFD613FULL, 0x925096832C5261AFULL, 
            0x0A10BBB7EBCA9C1BULL, 0x4F8AA567ED6BAA5EULL, 0xDD4419BC298D6A22ULL, 0xC46A2BA104F78BF2ULL, 
            0x1407E6EDBED781C6ULL, 0x1ED22807CE50BF42ULL, 0x69686DE5AA3AB034ULL, 0x3CD6F31DC7E3A33BULL
        },
        {
            0x82FB379E19D84A08ULL, 0x8C9CDD5916655130ULL, 0xBF2968444D02536DULL, 0x0E1E316B70216872ULL, 
            0x499FAF3CC0E441C7ULL, 0x16909F1ADDEDC438ULL, 0x9FA94F4FC0461986ULL, 0x45E14E404BC69D9BULL, 
            0x50E4E412E5A5D700ULL, 0xA6A9AE5FE659EF53ULL, 0x048FE40447B051F0ULL, 0xC5A181BD10C62BFAULL, 
            0xB440006C0C634D25ULL, 0x6F917DDB9B60F929ULL, 0x2B309A9F7AE62FAFULL, 0x42E6A768311205DCULL, 
            0xE230A6CEC1CC354BULL, 0x521B240CE215FFE3ULL, 0xA484E7AD5E49B5C6ULL, 0xAFE2D4AD01601F11ULL, 
            0xAB6AE61620F12F83ULL, 0xA7986361B6CE9BFFULL, 0x4ADAB29E29D0792AULL, 0x355F1155426007F5ULL, 
            0xA611776B6D5F9C87ULL, 0xC4BAC190EA9E8B0AULL, 0x7832AAB75CDE56F2ULL, 0x56B5F002F155FCF9ULL, 
            0x2BE7AC8B1DE6C813ULL, 0xB866E16C1CEF7C45ULL, 0x6597FBD2DED190AAULL, 0xD0164CCE0339DFF1ULL
        },
        {
            0xBCD1F84F57C328E6ULL, 0xE1049CF1837C85A5ULL, 0x4A0460B6A7BD601CULL, 0x9D78622AA82FB94BULL, 
            0x798362EF2AD1C3EEULL, 0xD0CF3E0E465C09F7ULL, 0xBD5D78E13154D2E2ULL, 0x2418A101E9ECD1F8ULL, 
            0x8F7D4D8B6FC5A883ULL, 0x435584622CC4329DULL, 0x05B43049AEA94667ULL, 0xFC171770B43EF2BBULL, 
            0x35E5E1D82B09FB7CULL, 0xE7AD520B39E59C05ULL, 0x6367520EF421F3F2ULL, 0x6B3DFEC88BEE122BULL, 
            0xB184C29AFF88EDB6ULL, 0xFB15FD0F3FA3FC89ULL, 0x6D7E75B4DA3480FEULL, 0x11BEE77756F24E95ULL, 
            0x0C2194EAC7DF65B8ULL, 0xE5231C14D6CD169BULL, 0x1A4954685DC7F02AULL, 0x979BBE2D68F00287ULL, 
            0x9ECA28007E335F86ULL, 0xA55D60D1C039DFDDULL, 0xB814231CBDB7E189ULL, 0xAB6EAEE8D3C24DA6ULL, 
            0x012794E3D8A0C034ULL, 0x4DC9E31A17CB29E4ULL, 0x2253E30ADBC33472ULL, 0x5EAB6F5698C54302ULL
        },
        {
            0x161E6698FF7094D0ULL, 0x09E29E63C0DFB739ULL, 0xBD3FA8D02CFB4501ULL, 0x7C979BC381C8EEB8ULL, 
            0x7D1A1B87BA70087DULL, 0xD5367367E33FAD7EULL, 0x34D87F211B2BD84AULL, 0x731FB8825BC498E3ULL, 
            0xD061E3C3B9158847ULL, 0x7BEAE48D4D21F76AULL, 0xCFF743933086D178ULL, 0xB3E9E0A2CC9D854DULL, 
            0x303E51AC711C704BULL, 0xEC0F0F76F1B33BB5ULL, 0xC93DBBB7C254AD89ULL, 0xDCE97D82FDCDDCD1ULL, 
            0x1B7C08F2E0F4BA13ULL, 0xB9992123EBE16954ULL, 0x5D7CE05D4ECF37C9ULL, 0xBCC4A2B1514FA51AULL, 
            0x35A042A237DDE2C7ULL, 0x8C160884889F5319ULL, 0x84A694EA6B755683ULL, 0x1C5FB2A78FBC0D3AULL, 
            0xB4EBCEA4A0F898BEULL, 0xF61E39E5DCFB9E3BULL, 0xBEEE4B2BF767667FULL, 0x3B511CE848E8DEA2ULL, 
            0xA2E6BA76DC7701F0ULL, 0x02A6960B9B806C29ULL, 0x845BBA10F89FA863ULL, 0xA178D36B2097C732ULL
        },
        {
            0xE28EB0824D95F0A6ULL, 0x6EDCCD4B9CE0F495ULL, 0xA0A2FEA14FBB6E77ULL, 0x2B98E17CCDC3564BULL, 
            0xDB7D9D05406F83B5ULL, 0xE4E2F10CAE58B27BULL, 0xEF20D93CAE94C6ACULL, 0x06EDB4D07778D718ULL, 
            0xB17BCA8EA8FAE4E2ULL, 0xDDAF48801DF68BBDULL, 0x53E0625B94E7EA5EULL, 0x7D7F99CCB8670512ULL, 
            0xCA326B189F499734ULL, 0xF4F787DA686515EBULL, 0x9C0F583D2106A207ULL, 0x3F8E5DA254270FE1ULL, 
            0xF1D6F6ACB43AFCAAULL, 0x70A7F8A7D55E08E7ULL, 0xAE61006F4E13BF97ULL, 0x2D6732947F9BD3E0ULL, 
            0x018586CAF7CBB499ULL, 0x99AA3EABC314349AULL, 0x0AFDE39A10687509ULL, 0x79659CB0BC1B32B7ULL, 
            0x6F6A577D9C3CC6F9ULL, 0xBB6D9B158A170145ULL, 0x5322E948E58C8075ULL, 0xA6F0B47290E5AEE6ULL, 
            0xEB5EE22FA439AE84ULL, 0x38536830779C13EEULL, 0x5695B06B280671A6ULL, 0xE180257E87A8F799ULL
        }
    },
    {
        {
            0x72BCF3DA92D073FEULL, 0x4491D73B9C64C673ULL, 0x70078F095841D203ULL, 0x249B7B38D9359B8AULL, 
            0x03BD3E53822AADB9ULL, 0x0931790E7528E4E7ULL, 0xACDFB9CDC057E386ULL, 0xD9F787BA86358E11ULL, 
            0xBD6431F0ED7A2AECULL, 0x985C70B78B43E34CULL, 0xCF7A562600E070E8ULL, 0x7F1ABA140618A836ULL, 
            0x3BD6A9D8BEC77957ULL, 0xAD545A23AF85B229ULL, 0xAAD14802B25A5908ULL, 0x2BEAFAD65B1A2523ULL, 
            0x8408778826DF76BCULL, 0x0D897525E0DAE043ULL, 0x067F6E415A5DB83EULL, 0xC94C7E1BD3FCBF7FULL, 
            0x74E6CB34A75D00C4ULL, 0x83AD6D99A5C88D03ULL, 0xCC7609E8CF214ABEULL, 0x45D46CC230CF06BCULL, 
            0x3CE7853F6FA2B4D3ULL, 0x731DBFFF7FAC1487ULL, 0x9C49E70A808F803EULL, 0xDBEE2BF8867038C8ULL, 
            0x10469D9877ED33B2ULL, 0x05101A75A35AD9D1ULL, 0x831E87A9EF736190ULL, 0x50398D66B9DBD5AEULL
        },
        {
            0xA0AE3617D0B9A1A3ULL, 0x4C11231021D73068ULL, 0xC2CBAEB8A80BE78CULL, 0x13ECC6A6CF8A241BULL, 
            0x8E8E4F7D5950D252ULL, 0xF04A1BC0722CBCB3ULL, 0xC989493E4946C530ULL, 0x5CF83DE96B11E56CULL, 
            0xDCE4ADFA5DC38EE3ULL, 0xF9807E6FACAC11AFULL, 0x37CF1A6E5304AF88ULL, 0x7A5D5A7FA59CB624ULL, 
            0x123BE1F2254BD0D9ULL, 0x46C5F27A25361162ULL, 0x10D8FD6706C8D517ULL, 0xAE54F6FE89DFDB1EULL, 
            0x2ED485AB832B6602ULL, 0x63B3DF5D5025D360ULL, 0x38BE59ED57FD9CBEULL, 0xABEEFDBF67F559AEULL, 
            0xF78D882C05ABBE5DULL, 0xD1933A6311F37F97ULL, 0x54F73B92EB4A7D73ULL, 0x181712FFF34B7D80ULL, 
            0xB0AD0552DC5B44B7ULL, 0xA638F56D0AC0ED8DULL, 0xBF0034A639CFEFB1ULL, 0x1AA63764FFF344E3ULL, 
            0x3A434C0F7A25E3D0ULL, 0x1D651ACE03430A2CULL, 0x0012B98082B36589ULL, 0x618AC128C49290DFULL
        },
        {
            0x2C082C1D894520C7ULL, 0xB0EC0C7D08DDB44EULL, 0xF457AC30DB7F5539ULL, 0x9E8D089FBF297B8FULL, 
            0xAFF471F5590F447EULL, 0x7E62579E1934BB6FULL, 0x65CE0EFE7886FA68ULL, 0x1B2122005DAD3DDFULL, 
            0x95E01D79875E1377ULL, 0x018F0C59ADDCAA6EULL, 0xA2A8E2FB3DDB47CDULL, 0xB947C212CF4C7522ULL, 
            0xCE9B7967FB3AF044ULL, 0x4BA961F715FA4737ULL, 0x8B0C24FEE22C9DF1ULL, 0x7B6536BC2EA84F34ULL, 
            0x2753E16377B8B317ULL, 0xF776CADF4B35DDC9ULL, 0xAEB570EF9EFA09AFULL, 0x4A454799CC9C84BBULL, 
            0x580F4A9EB118615FULL, 0x1A7C2B6EBD8A658CULL, 0x25ADF86DB8BD09FFULL, 0xAB441FB765F773F2ULL, 
            0x8090A1314DE6592AULL, 0xF79C63EED02FEACFULL, 0x05CAC2A6F52153B3ULL, 0x074428239455E615ULL, 
            0x56920924BA2A8367ULL, 0x4557E09E62A347A4ULL, 0xD1A9336E53FA1A74ULL, 0xE121120BCD6C3E26ULL
        },
        {
            0xBD12339FEB890261ULL, 0xED57406BE623775BULL, 0x28E0319EF78374ABULL, 0xAC4D1A3034999F85ULL, 
            0xF92A126F340775CAULL, 0x57BD666F1FFE75C5ULL, 0xD23B1E6A97C80DD3ULL, 0xD8270B57944C30F8ULL, 
            0x6B6DA5DD3E5FC2B5ULL, 0x2D151751D318091DULL, 0x00D20CC77F7E58F3ULL, 0xAD357784A7312E48ULL, 
            0xDEBF4271D409FE32ULL, 0x47CC07263F5D6980ULL, 0x30E82AA99FE44994ULL, 0xC063A2D1514F8A2FULL, 
            0x2A72F8BB2C9443C7ULL, 0x2073ABB2FC9D16CBULL, 0xD26E18DC2005F522ULL, 0x032CE82A7B8C04C5ULL, 
            0xE2D9E60DAEDE882EULL, 0x35C3F0E8434EF4E8ULL, 0x92A76DBDA58E6D02ULL, 0x7A41B45CD43FCB53ULL, 
            0xF4AE8748DD6EB2CBULL, 0xD03A4A1515B8236DULL, 0xC155439B979A2EE0ULL, 0x55BC865B9FCA827CULL, 
            0xFFCD125EBD4958C7ULL, 0x900A7EEEE1AB59B5ULL, 0x1913C0BFEBBDD8B6ULL, 0x4244BEF73064CC5FULL
        },
        {
            0x6B2DC486ED038EDFULL, 0xD7F3EB214EA6EE12ULL, 0x630E828F194ECA29ULL, 0x0504C6FB29E8346BULL, 
            0x232C2665BFEE0D86ULL, 0x552AEBB99D290820ULL, 0xD0C7C276A606AE6BULL, 0x0400796E70452994ULL, 
            0xDFDFC4411B0EC746ULL, 0x8C4C5EB2886CCCEAULL, 0x0AE43FE3957AE6A0ULL, 0x2B37D1C418B93EC1ULL, 
            0xFA654AEDFF43AD0BULL, 0xBB001D4CDF12CEEEULL, 0xF69E428C0225D793ULL, 0xA6EC9A141269FE4FULL, 
            0xA1B8DE8AEFF153EDULL, 0x947CF8ADF0BD7BC4ULL, 0xAC9763C383F52B0AULL, 0x04027352E49CE4C4ULL, 
            0x24AAC6CA9D57397BULL, 0xF6C23F6B399E1FFDULL, 0xE944C0C27196B4C1ULL, 0xE98908128C158D12ULL, 
            0x5574806724831CC2ULL, 0xF64FE723C272B0AAULL, 0xC505B1E8ECF7F8E8ULL, 0xE56C7F84B03B4CA8ULL, 
            0xF4D6B76B85B4D59BULL, 0xD978500B647576B4ULL, 0x0E5E6F0CADAFAD05ULL, 0xA81D8D8BCA96DE3EULL
        },
        {
            0x590A92224502A5C8ULL, 0x231C91B29C6416C8ULL, 0xC8C9D08EE5C61E91ULL, 0x6C8C1EB31E9BDFACULL, 
            0x5072EDD3B69A2119ULL, 0x2EF237AA9BB69908ULL, 0x81617F5289475FD2ULL, 0x9CB75F431399467AULL, 
            0x379F4BF47B6C7824ULL, 0x3BA1CBF8DFDC4AFDULL, 0xB3C6AE1F10C78F9FULL, 0xDB3911E692937EA8ULL, 
            0xB3B6B4E4CAA2D82EULL, 0x288F10CC4670378FULL, 0x399BFCD8BC773CFBULL, 0x4621D2FDAD70295BULL, 
            0x9124A054AD37A4A3ULL, 0x0012807EC001E0B6ULL, 0xC70C1D11480A0EA8ULL, 0xF57690F692F99DD7ULL, 
            0x6E270F3C691566C4ULL, 0xC483226A1F76C064ULL, 0x5ECBA42F2C87A356ULL, 0xEA2A636E6E33EA91ULL, 
            0xC3A5363D1D66CB19ULL, 0x9C1554CD6110AA4EULL, 0x3D64C167C840F93DULL, 0xE5FB0CABAD77A5EEULL, 
            0x134A93C8D974BD39ULL, 0x82D9EE1776962F45ULL, 0xFBB6AC7B8B2EED34ULL, 0xDF9876C751E8DFEDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseDConstants = {
    0x67D8DC0DE6E41603ULL,
    0xA8001985E8D3896FULL,
    0xC67D37ECA88917D2ULL,
    0x67D8DC0DE6E41603ULL,
    0xA8001985E8D3896FULL,
    0xC67D37ECA88917D2ULL,
    0x2F39207977AE2404ULL,
    0xE1F0C7B127761275ULL,
    0xD8,
    0x25,
    0xF4,
    0xB8,
    0x53,
    0x6D,
    0x89,
    0x14
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseESalts = {
    {
        {
            0x0CC409CF65C89CF0ULL, 0xC3FEFA67FC1EA6B8ULL, 0xE66CD59758061C57ULL, 0xD25B6BA8F49FB7E8ULL, 
            0xF9024A785D8569E0ULL, 0x4FC9A690449AD743ULL, 0xB7CE85C888BB1F2AULL, 0x903B8241BDA24997ULL, 
            0x11BAEB148F5B57E6ULL, 0x92570738EC33B813ULL, 0x36E795938C226B4DULL, 0x99FA889E95F219E1ULL, 
            0xF8A3DB0FBFEE838DULL, 0x88FB1A1F876751B5ULL, 0xB43C3D88283EF27BULL, 0xD7F4DFB86628FB15ULL, 
            0x560B8472576A2DBAULL, 0xBF271B978C24CF59ULL, 0x1844FC7FBAB8F6A0ULL, 0x4E749A597163707FULL, 
            0x11392B24FC7AC664ULL, 0xA3F8F5B9AE00ED38ULL, 0xDFBC4B2D18743D63ULL, 0x8BA7E128ACB90511ULL, 
            0xCE5A3B67266DC8A3ULL, 0x15F7805A636E57B4ULL, 0x3EC46EAFD574D881ULL, 0x974CDF667DD2C36AULL, 
            0xF6192E5C18070D11ULL, 0xD1AE94676D879DDFULL, 0x1B066D8F1F01F0C5ULL, 0x0D1C7599CEC5061DULL
        },
        {
            0xA8244785C449B142ULL, 0xAE2E12258B0DE5BFULL, 0x2C776E0449A76B12ULL, 0x14F8E4701FCB5D19ULL, 
            0xD9840DDC543BE6EFULL, 0xA2547655D9E1E99DULL, 0x47AE0B59722A6F8FULL, 0x70362B6A18522383ULL, 
            0x4A8779B50852BC75ULL, 0x0DC5DDDF5A82376AULL, 0x0EF1BD5EFD67FBF9ULL, 0xD39DF6D1BE241C43ULL, 
            0xF2C77E47BCF92EB4ULL, 0x92D4ADBF89D9479FULL, 0xCDA8778FF22B030BULL, 0x01A3CCE200200587ULL, 
            0x76ADFB515D497E6CULL, 0x6A1DB3E21D852389ULL, 0x5E88ADB6BF37131FULL, 0x173D5AF263675735ULL, 
            0xBC96D8CC396DC9BAULL, 0xEB48D98050413EC4ULL, 0xD7E1294CC0F73AA8ULL, 0x5130C4DB19915054ULL, 
            0x9BB64D94CB30B3CAULL, 0x1E8CDFE5912044D3ULL, 0x5CA391A3D89BD672ULL, 0x8458521C77403799ULL, 
            0x8B60FEEE907BE529ULL, 0x9DD2B429DFAEC3E1ULL, 0x163FD03BEF453D3DULL, 0x4EE6977EA6A34187ULL
        },
        {
            0x4AFDC9E74AAF5FF5ULL, 0x6817DC061DDAAB81ULL, 0x64898E981DF8E2AEULL, 0x4093B54EF1DE92CEULL, 
            0xA118789E71BC1453ULL, 0xF70F839022FFC15EULL, 0x4D97636EBC8A8777ULL, 0x2E900F4999ED6AABULL, 
            0x2E745BE3EAA4AA4BULL, 0xB54350327635801EULL, 0x132FB0B30727C245ULL, 0xC7652C02A55EB092ULL, 
            0x92D91569E5A4EA1BULL, 0xAE354E3C659C02D6ULL, 0xC0464056DF3125F1ULL, 0x992B73A86907D75BULL, 
            0xDE16209BED596F08ULL, 0x8E9D74C92CAA5A48ULL, 0xF9744777667A4AD2ULL, 0x73108EE55E47B8F3ULL, 
            0x858549591FDBAAC1ULL, 0x8CFA3E79F99E4439ULL, 0xE288247CED714647ULL, 0x4B7C9A4C91108A29ULL, 
            0x3CDE0C64D7FD5143ULL, 0xE8D1D2114DCDCD79ULL, 0xE25894C93E4A2008ULL, 0x6B96DEF6ECAB58B3ULL, 
            0x5AA629A3B5F0B34BULL, 0x253D7B208D407E49ULL, 0x5E9E120DFC6015E5ULL, 0x4C79D3136317CB0CULL
        },
        {
            0x553181068CF210C6ULL, 0xBFCD63E3A11A0DCEULL, 0x52CDAE575C9D3493ULL, 0x01981C7BE299A732ULL, 
            0xD605939D5189A0D4ULL, 0x4ECF0B09C931C3D1ULL, 0x63FC2B07D62A2E92ULL, 0xEFD243F6199B8943ULL, 
            0x09C8246BA2E6B28FULL, 0x7DC669C520B3C266ULL, 0x804DC295BCC4C8AAULL, 0x5B4677FDBBFACA50ULL, 
            0xBE7D998EBDC2064DULL, 0x6C63A07117D2E242ULL, 0x59563D4BB1ED17A6ULL, 0xFEB68DA9C3318EC5ULL, 
            0x3B579FBF79373F5DULL, 0x7F47968581D4EB23ULL, 0xCB1CC6D57AD81FB6ULL, 0x99D8AF2C2E7F2728ULL, 
            0xB30EA9203A35B336ULL, 0x8D568BF7A3DD854EULL, 0x2731AA6FF4391008ULL, 0x05757B3A29C42531ULL, 
            0xB58ECCDDB28D26FBULL, 0xA41BEAC1F05B29F9ULL, 0xAF40F5ECDA49A143ULL, 0x01F32DFBBC235CA3ULL, 
            0x2A1D4246D08C265AULL, 0x0A7B81C4DDE88F3FULL, 0x5653FB72D3A43B44ULL, 0xC095B172C16C328EULL
        },
        {
            0xA07D77ACA058371AULL, 0x12F60F6F7904229FULL, 0x753D99F160141C32ULL, 0x54EB27386375B1C8ULL, 
            0xDE75883CA1A12D3CULL, 0x242B50F893BC1AE2ULL, 0x411F139DF2F7E9EEULL, 0xDB7CB76DC7479299ULL, 
            0x3E1CA2FCBE65A1DEULL, 0xF321737CA98CCC7DULL, 0xBD0DB83557DC7CC0ULL, 0x38CF57B4215D1A10ULL, 
            0xF44A64F4EEC9757BULL, 0x96939093D09D470BULL, 0xDA636C83CF3D42B9ULL, 0xD1658E8B233B73AEULL, 
            0x70612EF556E0F83BULL, 0xCBD7907D57389399ULL, 0xA27421DA2097FB92ULL, 0x3ECC5D8E27F632FFULL, 
            0xD5DE82CB93DF0F7DULL, 0xF1EC491AD2EC5437ULL, 0x3AF21937B9F792BCULL, 0xDBE65A0FAE444010ULL, 
            0x9C40DCC356CBC37BULL, 0x658A2DC98DF6164FULL, 0xC0F774A35A3BE008ULL, 0xE33BA02BC46F1664ULL, 
            0x50190B0C1061ACE8ULL, 0x9503AEE8FCEB27EEULL, 0x5B22CB4240EF7F01ULL, 0x24735409FD03422FULL
        },
        {
            0x8412196E362A4F72ULL, 0xF73E1795CD56A0BAULL, 0xE49461941A7B75DEULL, 0x8B0F772A62A2812DULL, 
            0x1179E956D86CF8FFULL, 0xEE36C7044D870348ULL, 0x0B6A1DB62B19C7A0ULL, 0x1095167B2E0B6442ULL, 
            0x23631C47074B534EULL, 0x62426FE4299DC539ULL, 0xAA8253B7D7C3D8BFULL, 0x69B38C5E4695C60DULL, 
            0x57B260DEE0B5599CULL, 0xAC499B99D10D566FULL, 0xD875F576FB370CB4ULL, 0xDD776715A8E9B915ULL, 
            0x37D2BB99886ADD65ULL, 0x2AEB4C71A1181107ULL, 0x1A3222A8AFAD37F9ULL, 0x1255F90A82D1516CULL, 
            0x33B3543A42C7FA43ULL, 0x113A97C6F1A81C5FULL, 0x8A6D4C76569B6081ULL, 0xAB2440391A32EA78ULL, 
            0xB595E53AA91D371FULL, 0x0A627C557E5DA184ULL, 0x7CD586692A2D93BEULL, 0x052BBF033563B6F0ULL, 
            0x3050462B9CCA21C7ULL, 0x2964A3C10A34222FULL, 0x18CE5B1DDEF837AAULL, 0x0252F782CBE28EA4ULL
        }
    },
    {
        {
            0xBA1E1378FF7B861EULL, 0x0041EA4CDC4B29F7ULL, 0x73EED36E2D44CA46ULL, 0x795DC0342FD6F8C7ULL, 
            0x1CBADA2FC416E34FULL, 0xEDDE2BD30C57172BULL, 0x95AB56D298C3F5EBULL, 0xAD8249850FE3AAA2ULL, 
            0xF4DAA940AA82F52BULL, 0xDC1CF9FBD1064BC4ULL, 0xEA0416C3AC3C3136ULL, 0xA06975A9B02DEEFEULL, 
            0x630272F845F57DEEULL, 0x0532CBFC7CA576B0ULL, 0xCF6D96FF96543F31ULL, 0x16F6CB36E50DE0B2ULL, 
            0x996E7D9608F4D47DULL, 0x34F3E8F7C01D4D1BULL, 0xA449739D70A41191ULL, 0xBE958FB36A7C9D54ULL, 
            0x76D7C29C8D964F8AULL, 0x7D9835B4B035A2FCULL, 0xBB810F617BEF1072ULL, 0x0679B5F4B610034FULL, 
            0x93908574A2F0663CULL, 0x36CA090F6FCF7864ULL, 0xC69759CEE3AE713EULL, 0x8CA748C56476BFFCULL, 
            0xB01EC83566C4B0EDULL, 0x6EA601FA68D515D0ULL, 0xCF3894AAEB894C3FULL, 0xC5B04B3C7F9B7265ULL
        },
        {
            0x4CFB4159FE8EFE76ULL, 0x069051666E5DFC15ULL, 0x7D5EF50493AF9A73ULL, 0x32DD87BEA834EE0BULL, 
            0x34E46E3AF19736BEULL, 0x91FDC875C515B1B6ULL, 0xFEBA35D9BBC673C6ULL, 0x201D7F1D0EB33D02ULL, 
            0xD1699337AAC0A58FULL, 0x27A74E9C94FCB70EULL, 0x234889BECC40585FULL, 0xF5AB892BD616DFBCULL, 
            0xF76711D274504291ULL, 0x56C6E8E5BC852A1CULL, 0x7548C80478F433C6ULL, 0x80F0AD846D82FA50ULL, 
            0x9A951CD025E26BCAULL, 0x5A2E26C0DCE19440ULL, 0xFF085125EF7A164AULL, 0xA9BFF5CCEE02C105ULL, 
            0xC621AADA78AF042DULL, 0x32B716820E61DB80ULL, 0xB2E68382C07CC3AAULL, 0x645C76B7223FA844ULL, 
            0x416CA78C90883A20ULL, 0xCA2376010AEBCABFULL, 0x9C93128B580995A5ULL, 0x43CD51DFC12E0D52ULL, 
            0xD1F0BD22DCC1AE58ULL, 0xFDF7814ACE0803F9ULL, 0x1F162B38F47A30D2ULL, 0x558CB90EAB5F8115ULL
        },
        {
            0xC0A629C0972FA372ULL, 0x46DB292FED024BD1ULL, 0x591A267D21FC1EA2ULL, 0x9028ECDC95664E38ULL, 
            0x5F133BDDDE976F9DULL, 0xC4F44ED7514882E3ULL, 0xD8C04CF6C6C160BDULL, 0x17BB70D683611FEBULL, 
            0x0AB1C00960FD99A9ULL, 0xD8C0D9890BA09ECDULL, 0xE53249EFC1CCCD5AULL, 0x0721119DF7765183ULL, 
            0x5FAEB226233D8378ULL, 0xB639831BA00CA02BULL, 0x6E9CFB820582CADEULL, 0x38E4B2AA7D46DC6DULL, 
            0x3CF852426384E660ULL, 0xC6612338EFE918B8ULL, 0x5ADD61E9204E818FULL, 0xF7E3AB30CA955532ULL, 
            0xD46178224FD07077ULL, 0x5E3CBA8E1C8194B9ULL, 0x00A0D81942C360BAULL, 0x9503BC1C1FBF33BBULL, 
            0xA998D3E1535775DCULL, 0x29DE44E4DFF8FDC3ULL, 0x05C4F2754462DFE7ULL, 0x4277E71CDE9EF64AULL, 
            0x0A62D49826CA3F22ULL, 0x5D0B6584B5EDADA4ULL, 0xD1BD5EE6CA258D8EULL, 0xCE241F5DD1371A88ULL
        },
        {
            0x6DA6BC0F6043A344ULL, 0x795180BE6FD2F732ULL, 0x520A563188BDF352ULL, 0x9E6CEE75EB7ABA13ULL, 
            0xE3FA0DA170BF2293ULL, 0xBC8CF6F76E08040BULL, 0xA632B512C2B3FD47ULL, 0xDE73578FEB29DFE1ULL, 
            0x48C009C31F43D6C1ULL, 0xF52732849B8092C6ULL, 0x1879C00833949907ULL, 0x7D071FADE586DCE2ULL, 
            0xA39621BD9BA38E6FULL, 0xC2CBE39A836A37ADULL, 0x8474D93169880819ULL, 0x009F4E7E7801AAACULL, 
            0x5635B302A853E5AFULL, 0xBAA32F023346B837ULL, 0x382F086299FF5BD0ULL, 0x69BA0AC54DBDE2CCULL, 
            0x8CAE265CDE24E987ULL, 0x6564B2919BC7ABEAULL, 0xD46656FF99C954F4ULL, 0x67C038A9BE866393ULL, 
            0xCD07A5BE80569467ULL, 0xF994008374A248B1ULL, 0xE0B13889E6806EB5ULL, 0x15B786FC7BA5EB70ULL, 
            0x56FCDD5D7703CFEEULL, 0x1202A519449E3EE8ULL, 0x8730C0D1AD357DA2ULL, 0xAEF865A2659E4183ULL
        },
        {
            0xC112B575966E327CULL, 0xD95603F39E13FF21ULL, 0xB240E47F3AB6557FULL, 0x7F5C62AF74CE3071ULL, 
            0x4102E9F73B5FA263ULL, 0x768EFAAE1362765EULL, 0xB5055E989F33B32FULL, 0xDD60B47A95F6F135ULL, 
            0xCFA7F8A337E8EBB2ULL, 0x7E2BF14D03A44C2BULL, 0xC59136E8855E3672ULL, 0x305DA5C45326B2FFULL, 
            0x14B7A94FCE9C6714ULL, 0x1B858D1F4F020405ULL, 0x67123EF39A1AD1D9ULL, 0x4D67A6DD12884F56ULL, 
            0x7E1A6474B38FDD34ULL, 0x0D723B88768C8AFEULL, 0x6661FA2F9544D0EBULL, 0xCE4CAB9D0236D6FFULL, 
            0x67A19412B150301EULL, 0xDF2638DBB2A568CBULL, 0x8824EC1499C481FFULL, 0xE070F1B4E051D576ULL, 
            0xEB94D68B0D80BC62ULL, 0xCB7CB5797B9A2D37ULL, 0x64A439565C14DB6FULL, 0x27BCC3FD88D8E4A0ULL, 
            0xD987917F2A123A2CULL, 0x9CAEEB8CDAB9A31DULL, 0x4889B27FB60EAE16ULL, 0xB99D8F5DAFCCBC79ULL
        },
        {
            0x67FD2F7951574188ULL, 0xBCEDD591C02DD0F4ULL, 0xF9B484217026E4E5ULL, 0x82B52F7CC18EEBDCULL, 
            0x8722AB3E7FD56C25ULL, 0xD43A861822D47956ULL, 0xD7E9AA426E2CCEC0ULL, 0xB56C699A31387523ULL, 
            0x303B589915EFD1B6ULL, 0xB2636C6FC0DCB7C3ULL, 0xF037E3A0F1147753ULL, 0x6B602713F1D6259DULL, 
            0xF2AF226F942416B9ULL, 0x53E529BF71047467ULL, 0xAD73BD083F20472EULL, 0x172CE5C62D54B9EAULL, 
            0x501FC34E5684073EULL, 0x585E7D03B2EDAE14ULL, 0x2D7732627EE9D70FULL, 0x10728C9B79BCAB59ULL, 
            0x77062C206A2154ECULL, 0x45C1A017AFFF507FULL, 0x6DFD9C6C654CB5A7ULL, 0xED65B94236F9EA08ULL, 
            0x3C61871DF1292B56ULL, 0xCDFF4E14C527E558ULL, 0x85E240F29FD8EA0EULL, 0x0FB806E8043D2A04ULL, 
            0x6E4A6A31EDCDD8ADULL, 0x9CFF8FD474699295ULL, 0x618754E615FA4C75ULL, 0xECBFB6FDEF8FD69FULL
        }
    },
    {
        {
            0x558A9AD266E886CCULL, 0x43324E4CDB5689A5ULL, 0x7DD8F2AF8820F9BDULL, 0xADF2AFD61BA1C25BULL, 
            0xFC1A2DD1AD4C70A9ULL, 0x3DD39C6611BEE70EULL, 0x52BB9DF450CE2494ULL, 0xBF6504EFA340D105ULL, 
            0x67A4452FDBE0F13DULL, 0x11732A8D6907586EULL, 0xAD26BD48F8EF4751ULL, 0x6CB3765135080CDEULL, 
            0x18DA22FBD289886EULL, 0x538F6BE5E1F723D3ULL, 0xE3208F585F5D1462ULL, 0x93D99282C8D73697ULL, 
            0xD0864D80F528A78DULL, 0xAC4AF832C2326EAEULL, 0x75C27190AA7E8B4EULL, 0x32AD635FD1605360ULL, 
            0x6E7D90138BAB471DULL, 0x69D26B3038E66268ULL, 0xC12BEBE02A386DA6ULL, 0x8118D5D7BA0790FDULL, 
            0x74ABACAEE91605D8ULL, 0xF06CAF9ACC30DF2DULL, 0x52A1370C94BE8A8CULL, 0xD717B595F04D38BDULL, 
            0x85668FA1E121E0ABULL, 0x858FB82150C88AE1ULL, 0x8B7F1D814127F815ULL, 0x48F88A4145F3A6F7ULL
        },
        {
            0x3FEBD755B8FA57A6ULL, 0xCD5FD4067EAE0DEEULL, 0xA3C881F2959E387AULL, 0xD53FA850726458F0ULL, 
            0x9C9C3ECA8B748180ULL, 0xE1C7BDC2E6729168ULL, 0x9290F5C9088EA90DULL, 0x649AFE4A92AB7A1BULL, 
            0x1514261005BB004FULL, 0xEDED3F2EA2E1C7E8ULL, 0xABA3B6B80157084FULL, 0xE8DA4D0F59065AF3ULL, 
            0x502E30FEE5FD65EBULL, 0x426E8AC51ECD7815ULL, 0xC7968997E3E8CCADULL, 0x18CF3368EC9131D6ULL, 
            0x21E398301FC1E281ULL, 0xA465386C0F392F92ULL, 0x50FAE2FFE0A74BE9ULL, 0x7B3935BC272075B1ULL, 
            0x801BE7928BF067C7ULL, 0x99A82F30E2E80C2AULL, 0xDF8BAAE8069FDDDBULL, 0x2F651228E64D2DA2ULL, 
            0x257877C312502E3DULL, 0x9947294097D0B8A6ULL, 0x0F1FBE6D30102A46ULL, 0xC372CF107EBEE798ULL, 
            0x9F673AB24E973157ULL, 0x347BF3D0DE96D53FULL, 0x2203BCCA2C51CB16ULL, 0x4978D927D350DFDEULL
        },
        {
            0x520EFA73CB8C0E49ULL, 0x3655A34479CFCEFBULL, 0x06885D238415662AULL, 0x6B0E8C3C3D866B1EULL, 
            0x97507D0DD17384E4ULL, 0x99414AC71D034446ULL, 0xD8A0BFBFBB236963ULL, 0x81F02A1E01CE5E7AULL, 
            0x0DB0D2C93865BDB4ULL, 0xD88D2408F1269671ULL, 0x70B8827E3735EA49ULL, 0xAE2617370F4B4D77ULL, 
            0xF535B919D819455CULL, 0x679B8BAF405C2788ULL, 0xC056B2D07EF5309CULL, 0x8F6073FCC4C14B3DULL, 
            0x6CECEF7EC37721B5ULL, 0x6BDD2F2760A7193DULL, 0x37FFA118E155F9A8ULL, 0x1CB1E2B9320EC661ULL, 
            0x053603C245337BF4ULL, 0x3DF09FAF894633EEULL, 0xE028D50153FE83E1ULL, 0xB533F44BAD5085D5ULL, 
            0x53AD67E00663F6B3ULL, 0x67332986417B7D7CULL, 0x342A6150937D04C2ULL, 0x5AA0E0C9107FBE99ULL, 
            0xF94833DEFA6C157CULL, 0x368C7E45B9925BC9ULL, 0xCC18B282E7C78770ULL, 0xF9F37198E8040A98ULL
        },
        {
            0xE66B946805A5D72DULL, 0x5F53E6433A3793B0ULL, 0x0D9B3DEFE992426EULL, 0xB87618F442658888ULL, 
            0x68F8C348717678D6ULL, 0xB79860A80292C21BULL, 0xA6748BF835BD062FULL, 0xA311BEBFC10287E8ULL, 
            0xE966C7A26806AA69ULL, 0x1DCB2453DAA4428EULL, 0x4088BC1825ED5DB0ULL, 0x9172112AAE3CA6E6ULL, 
            0x0006BED502685E8AULL, 0x64BE69C540778A2CULL, 0xD9E1201A0375A16EULL, 0xA8FA1005F8143597ULL, 
            0x32E6879A2EF155A4ULL, 0x34BE79A4AAECE25FULL, 0x046864CABF33D8CDULL, 0x4BB7A195729A3C68ULL, 
            0x2258C4F04E9335CFULL, 0x85679C8C78705D0EULL, 0xC618FD335DBC77E6ULL, 0x6C35689A70B5897FULL, 
            0xDB52B394E984DD76ULL, 0x2E6FE2E7FAFF052EULL, 0x4838D84181E62B3FULL, 0xE96F017808D4AF02ULL, 
            0xE01EF1421123AE39ULL, 0x46E9CDD08894C82EULL, 0xCDCC9E77A8602DBEULL, 0x4F623FD0BD663348ULL
        },
        {
            0x36DBFFF8EC6150CCULL, 0xFDDE3AA253653743ULL, 0xC577BA141F75E7C5ULL, 0x7E9B88B4B21FA569ULL, 
            0x53D6FBEA8D5A845BULL, 0xB156EC1323E858ACULL, 0x25A14CCC81C7DB2BULL, 0x7D610348BCDEA0A2ULL, 
            0xE6A3D35E5B8B4425ULL, 0xAFA450E53868596EULL, 0x210237C30917E6B1ULL, 0x8E6C0C9310605721ULL, 
            0xC3A3F10B195B0488ULL, 0xBF3854E64084214FULL, 0x0152D49827710FA6ULL, 0xFD0A39B5846E81CDULL, 
            0xFEDF3F25F273A0A6ULL, 0x66E41F0DB02739CBULL, 0xD422518EF40285AEULL, 0x6170A1A3BEAB6BE7ULL, 
            0x2B2F5A0713E22241ULL, 0x418270CA45FE222CULL, 0xC424432993FF229AULL, 0xCE2F4175D064C9A3ULL, 
            0x9DE3BC8837E87DE8ULL, 0x928CF1FFFAA4C474ULL, 0x23B1BBCBA0F58A9CULL, 0x03B7AE292D86871CULL, 
            0xBD90A2B41F5F7C1FULL, 0xC45D1FBFC39D441EULL, 0x40E46A1B730E58C4ULL, 0x2693A91E7DC1D22CULL
        },
        {
            0xDC8F13FA2568760AULL, 0x46C0E99E27AD3848ULL, 0xBDCF5CA586C5D819ULL, 0x89BC716C2F29F2B0ULL, 
            0x045C307FD526305DULL, 0x96EDEB6A207BCF3AULL, 0xF6A6DC10B5BA378FULL, 0x325B92D6E3F91D4BULL, 
            0x27A56FBD36FD93FAULL, 0x103A3F726A72E48EULL, 0x676E74B0A8E2AAF5ULL, 0xC4653E76BE919CBDULL, 
            0x4847C176485885F7ULL, 0x115BA1F5A18A893CULL, 0x0CAF0E873D2A276DULL, 0x6D7A6FBAC38EBC82ULL, 
            0xF654C6AF5180B6B6ULL, 0x483D0F9704D4AFCDULL, 0x4DD90772CBEEBE1AULL, 0x0ABE13F6369945EEULL, 
            0xF9914501ECF1F977ULL, 0x42D68EDA4E3FF9CCULL, 0xD91D7F1C055E3514ULL, 0x058383AF40D47447ULL, 
            0x29757A639FBB97F7ULL, 0x477BD97D6DC9570EULL, 0xC186FBB93420ECB3ULL, 0x5B966C1971A731F5ULL, 
            0xC477D8F44287DD69ULL, 0x77F54597FE5EE7AAULL, 0xCDA98823D42DD410ULL, 0x63E80B56C3B96943ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseEConstants = {
    0xDE8FF57618D6C5E0ULL,
    0x80F84C0A50F559CDULL,
    0xF6C21B11CD0F3784ULL,
    0xDE8FF57618D6C5E0ULL,
    0x80F84C0A50F559CDULL,
    0xF6C21B11CD0F3784ULL,
    0xCC288BE10E875A2FULL,
    0xC374940A36D037A4ULL,
    0xFE,
    0xDD,
    0x22,
    0x74,
    0x0E,
    0xA3,
    0xDC,
    0x71
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseFSalts = {
    {
        {
            0xBC7D95C52E3B0612ULL, 0x7269193F90C5A32FULL, 0xDE5E211F5B3E46EAULL, 0x0984E1A8A3372D77ULL, 
            0x7A7046A7C2F3863DULL, 0x492A3E6240C6460BULL, 0xFE959AD2CED37716ULL, 0x4DDA9D55FC34E9D2ULL, 
            0xC00EA23FD3036FBEULL, 0xCDC208078C7CB8EEULL, 0xCABC8B919DA9D74DULL, 0xE6D6979E3FCF40D9ULL, 
            0xA62D606B2A29EB0AULL, 0x323A3F616A351B8AULL, 0xE56FD26E8958FBA8ULL, 0x6624313A88707C54ULL, 
            0x79836666563593A1ULL, 0xF8C8AE598F8FC3A2ULL, 0x4E450BD40964453CULL, 0xC0CE9ECFDD33FEBDULL, 
            0xB9BF7E19A87F0AEAULL, 0x2423CCAE45937C0CULL, 0x76167623EF90C698ULL, 0xE5EAED2D8654085FULL, 
            0xE811E749E2C5F685ULL, 0x826B843AD90F438AULL, 0x4CCC352BE5EFB95AULL, 0x37783170A2512BB3ULL, 
            0x22F102B9D91C4C66ULL, 0x1DA4FA7123695692ULL, 0xF5F87FBE0B158960ULL, 0x32FF0BB4E6D5B4B1ULL
        },
        {
            0x7401BAD40EB22B75ULL, 0xE2A4699ADFF1166DULL, 0x718D82B5BC57852BULL, 0x018EB430925782B1ULL, 
            0x1426CBE9B4FD39AFULL, 0xB7FA208CDF7768DFULL, 0x50EA9B3C66DF8577ULL, 0x74C563392E200CCEULL, 
            0x0B16C5A81185196CULL, 0xB5B9C3B3FE4E99CFULL, 0x740E0A504BF3FF6BULL, 0xA2E087BE9EDD78ACULL, 
            0xD5D1D7CF7011DE8DULL, 0x0FFB551994B31896ULL, 0x5B90A926C7C0F655ULL, 0x3ECFC1E0A54A6F8DULL, 
            0x081A083017BF7F44ULL, 0x471233482145F153ULL, 0x753A4EE81EF3F515ULL, 0x3B3C10C376FC7952ULL, 
            0x44AB26B1D438B8A6ULL, 0x460BF322B89B4EA9ULL, 0x775DA49C8AAC5A0BULL, 0xA20FBADE604EFD2AULL, 
            0xA70674A248E46E97ULL, 0xF45C23458A11FF4EULL, 0xE81815E4B945862AULL, 0x512DBA2794DD7308ULL, 
            0x48243842FCDA5385ULL, 0xA5AF09AFBD18332EULL, 0x4612011A76BBEF57ULL, 0xFF1C92B339B8011EULL
        },
        {
            0x97CF776F69DE1932ULL, 0xA956654B299C3775ULL, 0x463724DADDC53852ULL, 0xAC5A25E8664D7E4EULL, 
            0x40B0737F08F6225EULL, 0x03C33BFDC7CB06F9ULL, 0xB49B3E7E363ECB66ULL, 0x66EED230CAB1E8FAULL, 
            0x0F96EF6726F438A4ULL, 0xC0334F30790A9058ULL, 0x51784B4E85BCAB64ULL, 0x3B798C8DC70C33F4ULL, 
            0x4918170439ED4850ULL, 0xE16C1992E458CAB9ULL, 0xEC8FC53963E0F088ULL, 0x1FCA33538A53AC5BULL, 
            0xC6811E6A70C3F3FBULL, 0xEF5F4E07E94321B6ULL, 0x32B2DED62769F17EULL, 0xA794C4FA8BA126B9ULL, 
            0xC08A9DA63D17D2EAULL, 0x511C4A23C7999285ULL, 0x3DD812B2C8F714E6ULL, 0x7DB547760E112391ULL, 
            0xDDBD4C80B80E757AULL, 0xFB9CE84BEB8050A5ULL, 0x46FBA81728C469C2ULL, 0x67DF82388B96EC6FULL, 
            0x5898A72B2247DC83ULL, 0x541B61FFED7843C0ULL, 0x1A8DE54F894C47B3ULL, 0xECCC3A64A457344BULL
        },
        {
            0xDD82EFEA7CA9B755ULL, 0x309FC495548BED87ULL, 0x364CC82FFB553231ULL, 0xF8605797F6CA08CAULL, 
            0xBD02FAB0E1DA664FULL, 0xD03D2045AE26FDA4ULL, 0x7520804633A9988EULL, 0x5D9AE48DDD6666F5ULL, 
            0x6C03D46E67A695F8ULL, 0x48D66038638F1664ULL, 0xDB1307ACA49843C5ULL, 0xBA811A4741F79776ULL, 
            0xA6B9F51BE42991B3ULL, 0x5EC224A360607032ULL, 0xADA55EC9A14A73D6ULL, 0xE2CED9170CA0EE73ULL, 
            0x19E1A643BD42D0ECULL, 0xC29B62071C3C1360ULL, 0x2677D2BA980DA7DDULL, 0x73FF94AD193A7D92ULL, 
            0x5B77BDAA2A06A6ECULL, 0x24E4D8E70163480DULL, 0xC11F63989490BEA2ULL, 0xE9FF654DBD1C2392ULL, 
            0x1E55AE20CBA7467BULL, 0x80A547C4C2087346ULL, 0x6A751758E72FCE30ULL, 0x80BDB3459712FF21ULL, 
            0x262C8EE50D40DAF9ULL, 0x1BDF174AE10A34FDULL, 0x49BE02AF4852CA38ULL, 0xB4B37795FB33211BULL
        },
        {
            0xB65C0EA0EC3EDF05ULL, 0x7B1F2B73D6C5311DULL, 0x8DDC9B2998F5A939ULL, 0x6FD6E3CCC203103EULL, 
            0x702FD70299404F8FULL, 0x3EBE254DF9C97BF5ULL, 0x875CEF62604C5610ULL, 0xB11CF8E8B7C3CCF8ULL, 
            0xA67BBF750E14CC5DULL, 0x3E279911AA0A2505ULL, 0x71BF3984F621F6F5ULL, 0x787CA3D6F580AE24ULL, 
            0x4D6F12AD0CFC0DA2ULL, 0x0E4B6D7AD9AFEC4FULL, 0x60BD855C5E63EEBCULL, 0xD7EBB65CF1634635ULL, 
            0x73F474D0545FBCB2ULL, 0x1F5B4938B75DF53FULL, 0x7681E51B0B95285FULL, 0xAB1F43E64799DC58ULL, 
            0xFF2943A202FEF797ULL, 0xD23FD5E809B57036ULL, 0x4D39008F12021922ULL, 0x2893B78A27DD5638ULL, 
            0x6DCA249511B34684ULL, 0x71B1F48BD16C6B4DULL, 0x406567C14DBFD4D0ULL, 0xD393BA0CE4DF0811ULL, 
            0x97A73D785F408580ULL, 0xD96ACEE90AA1E3D4ULL, 0xA6B9AA637874A7FFULL, 0xCC807A135D25426BULL
        },
        {
            0x4C509711FA9F31E1ULL, 0x3AFAAB3AF4B74AD4ULL, 0x00C051BC3E77DD11ULL, 0xEDB8BEE43452F4EAULL, 
            0xB5BEF8DA8212EE97ULL, 0xEA9484E102D06EE2ULL, 0x7D1310D1A3862DE6ULL, 0x1A558B7C8A351715ULL, 
            0x6920527246122B71ULL, 0x0D37CA4BDF5BB2F6ULL, 0x64D805DA369EBF7AULL, 0xF17AF48956CD1F3FULL, 
            0x01B9308FF5A20085ULL, 0x7FF9E50295BF3060ULL, 0x9561C4FEE32DFD31ULL, 0x20E305AFE07EF6A0ULL, 
            0x2F198619B23E1DE8ULL, 0x39DED0078B5D79A4ULL, 0x8734E9CFF85513C3ULL, 0xF82297CA60B0AA95ULL, 
            0x04405A2638988835ULL, 0x7F5908429E5C2A2BULL, 0x080EF66486082AA0ULL, 0x061A02A5BA9D46CDULL, 
            0x6FFEB58186A95654ULL, 0x77B9340ABA258D33ULL, 0x554A33E3F95C0943ULL, 0x157FCB6B9E30E007ULL, 
            0x2AA1E46D4972916BULL, 0x2C673E385EF4E8F9ULL, 0x64AA317FCE0957C9ULL, 0x5E57D37DADFD362AULL
        }
    },
    {
        {
            0x779B93BD6C33499FULL, 0xAA43E4C28FE6FA2AULL, 0x86E23D28C1819DC9ULL, 0xFEC35105B04C5502ULL, 
            0x722A6C4678B0264DULL, 0x7B22555FF22398F7ULL, 0x126753A076748DEAULL, 0x87B11CBC9D7F967BULL, 
            0xB5DD66A65C047DF3ULL, 0x07E9C055AC7F7420ULL, 0xC47AD188B0163BEBULL, 0x73E1969D9125DB91ULL, 
            0xF2612DFA34D61985ULL, 0x36234E4D353C57D1ULL, 0x5126845449A0B8C6ULL, 0x943C243C244E77BFULL, 
            0x2FC841F9C4D134D9ULL, 0xCA3FF628A653004DULL, 0x3204AFC6EF50AFE6ULL, 0x6496F97DFF55AC61ULL, 
            0xC08585A84ECFFEC5ULL, 0x61FF804F5DDE3F22ULL, 0x9BD636194C9B7C88ULL, 0xE92149DCD11B5291ULL, 
            0xAD580C1A8B168970ULL, 0x6741814C5B183F02ULL, 0x0BBA32D7E86FA941ULL, 0x88115A8C4BD1E194ULL, 
            0xCABF0B06A69345F2ULL, 0xF20D883447C5621AULL, 0xFE27E50490DBFDF8ULL, 0xE98633FCA448497FULL
        },
        {
            0xA2DA909944C20DB8ULL, 0xF8F9180D6F58146BULL, 0x6D4BEA539D38085DULL, 0xF63CA1269AA397A7ULL, 
            0x6B08E79A7066E137ULL, 0x97F83BD312B2DE2CULL, 0xDBDD2763221D2B90ULL, 0x95FFC9BBEFCE6D88ULL, 
            0x46FD8BA02F4ECFC1ULL, 0x9716EC28B0167567ULL, 0xB972A304BE698DDEULL, 0x7CA280C256DBF7BFULL, 
            0x2FA0927BC9E3FD67ULL, 0x67577AD64D244EEDULL, 0x0E4627C099847B15ULL, 0xE6ED7BFB2D87B14BULL, 
            0xDE7158622062A04AULL, 0x3D381BD7A418B185ULL, 0x3C769D16A303EE39ULL, 0x7E53688235C22B99ULL, 
            0x3C6939BCAF77D973ULL, 0x92C504CEE67BD9F7ULL, 0x8428800380897202ULL, 0x7FE1D9C0D7803022ULL, 
            0x277AE4581BCE1690ULL, 0x2E4C635D84C7F4CCULL, 0x75756BCF31BD65CCULL, 0x4CFC67B7FFEE7023ULL, 
            0x3CF063603ACF66B1ULL, 0x5A59D89C731EC66AULL, 0x4038E97678B36410ULL, 0x5AA00231406F49DBULL
        },
        {
            0x9A32FE473108FB74ULL, 0x3CA99349873AD6F6ULL, 0x5B8D8EB6588712ABULL, 0xB3C2D7A557452AA9ULL, 
            0xBB3654B3CF3C966CULL, 0x0CDD4143773EBBDBULL, 0x66F4FAE88FB167E1ULL, 0xA886E146B6E48459ULL, 
            0xABEF7492E5C22FBBULL, 0xA5BA8A3FA5BEC12AULL, 0xBE8A0B409AB925BAULL, 0xC5269510E1E843C4ULL, 
            0x40337A9164F14D3DULL, 0x6CB85F37F13B31EFULL, 0xA8587247DF86E71DULL, 0x6EC17953F4430C43ULL, 
            0xF682B9D563A51153ULL, 0xE45E1C62E6BA759AULL, 0x138D2E0F392B007AULL, 0xD4E80B0E696A5761ULL, 
            0x403957D681F47876ULL, 0x8662713DDCAF438DULL, 0x26793611B0D6EF3BULL, 0xB2625464FB28C880ULL, 
            0x04D9B87138D1CD1FULL, 0x128AFC6D96E58D27ULL, 0xDE6A409D154C2D04ULL, 0x1DEECBD29960A5F7ULL, 
            0x0AF942608CB28E20ULL, 0x02681B55E82ED9CAULL, 0xD9EA861B2365350DULL, 0xDB3F50B86581B4ACULL
        },
        {
            0x25EAEC967A8F56DAULL, 0x6DE789B93A66C8B9ULL, 0x57BCE72B0B001190ULL, 0xCB1BE2A7C11D6023ULL, 
            0xE7E35E06EDE2DC94ULL, 0xB6DEC45992CB2F1BULL, 0xF1A1004A28B96C86ULL, 0x7202723713334E17ULL, 
            0x8259A500E80B73F6ULL, 0x4233D093FCB0B78EULL, 0xAC5668D333CCD374ULL, 0xAFB6EA6B9D3016C8ULL, 
            0x7BB7103DF11DAE6EULL, 0x241C378F0D7C58DFULL, 0x781EF42EE9158619ULL, 0x32BB3833ABE83596ULL, 
            0x72F88772B1739C1DULL, 0x7389EE00468FFF4BULL, 0x3630FE9729C32B7CULL, 0xB51605E66ECAA978ULL, 
            0x6DABC264F48753B9ULL, 0x1A0F49296C2A415FULL, 0x300C1E4A2DFCE9EBULL, 0xCE541FF20425A938ULL, 
            0x63E8E31B6CBB8D67ULL, 0x57E5189190E20F55ULL, 0x8266D28542F3E961ULL, 0x77C972310B93C87DULL, 
            0x6423AE43C04011C1ULL, 0x6106880F4D9EC25DULL, 0x39286E44A1EF5975ULL, 0xB9E596745F28EFFDULL
        },
        {
            0x2FAEDEB17CE1DD5EULL, 0x63AE9D96ECCD9EA1ULL, 0x18CDFA7495D5A8E0ULL, 0xDD568073B3B4E404ULL, 
            0x6249232A0614890DULL, 0x3481489C97FE8913ULL, 0xD1A511B45E1CB7F4ULL, 0xDD7AB9DFE069655FULL, 
            0x840B9FF8A0C3EA06ULL, 0xD415BAF9C42F9E60ULL, 0xE0C61D610A9F964CULL, 0x09D07A67537E3A69ULL, 
            0x6C84D3AC881D27F6ULL, 0x67CAAFA60D26024BULL, 0x6A84239084D06A43ULL, 0xE9EF31640873EEB3ULL, 
            0x36EE7A87EA62F24DULL, 0xE8C1F8783432F96AULL, 0x281806C97D5C3792ULL, 0xF3449A034A139ADBULL, 
            0xD082BF2B66912900ULL, 0x1704D5DF737E5B34ULL, 0xF3C5E33BB33BFBB6ULL, 0x3846AAA3B5BFA6A4ULL, 
            0xED4D1B35128D6AA2ULL, 0xC4CD4E71A217FE9AULL, 0x916D0F5815373C58ULL, 0x3D2446AEADEE22FAULL, 
            0xB135A38C12B7C80AULL, 0xDA01B929FFB99C18ULL, 0x50409BF919490648ULL, 0x4E86AAC7743D94DBULL
        },
        {
            0xA2898698582CE64EULL, 0x3B6170D66BD0A48AULL, 0x217A71177031799DULL, 0xC6E91DC224B81A4BULL, 
            0x27E429F5242F40E1ULL, 0xB782CCCEAAA5C24BULL, 0x9E4EE73E4764B8D3ULL, 0x054E195A5C402EC1ULL, 
            0xCF3AE76E38BDB663ULL, 0x2102B6D012CFE68BULL, 0x741E3C41B5B3CC15ULL, 0x2FB167129D635542ULL, 
            0x36419716BA3589EEULL, 0xA4D1C64F2A054400ULL, 0xE004A6374221299BULL, 0x3018397F6E181907ULL, 
            0x09C4CADB313E1079ULL, 0x7A888CB4E64152C8ULL, 0x5534484A3285B1FBULL, 0xF291F5D179D8AB71ULL, 
            0xA242DB2963603F17ULL, 0x30EFB914150414F4ULL, 0x11E29FD901A102FFULL, 0x54C0A67A89D1910BULL, 
            0x6F46ED16E20CE7D8ULL, 0xF0CE0C2D22C23A41ULL, 0x0F3289654DF91AD2ULL, 0xD4920010356E8248ULL, 
            0xABE289CFA73F2814ULL, 0xD5DF6059761D0DD4ULL, 0xE748C0075DF71A26ULL, 0x53A355FE10CB6B33ULL
        }
    },
    {
        {
            0x62346E164AF4F06CULL, 0xD1BC36BBF772C058ULL, 0x4842716BF65CF73EULL, 0x4B95C3067D1A259EULL, 
            0x4CDC374A9C616B76ULL, 0xC7FCE160E520F8A1ULL, 0x556DC95597CCCC89ULL, 0x94134823A61CC5FDULL, 
            0x813A7C339A1160CEULL, 0x6F880EE23A7282CEULL, 0x8DE51BAFD34E8695ULL, 0x3D60ABCA947A6851ULL, 
            0xAB8112223B1BB4D9ULL, 0x018627EAE0E27801ULL, 0x0040127C2B50CB4BULL, 0x0ACF0A2F058CCF1EULL, 
            0xA123B36CD35B5568ULL, 0x718A3D6BA1D2EA23ULL, 0x03C17D21026B224DULL, 0x10D39DD76AC50C9DULL, 
            0xDB05D2BD3A71ABBAULL, 0x0970494817786532ULL, 0xF32A978443BE327AULL, 0x3D8D4A4FD1B8E7F9ULL, 
            0xA16DCE38CCC8A9FFULL, 0xEB8399A4947DCBA6ULL, 0x13334E2731760177ULL, 0x4BD268A78505D282ULL, 
            0xE1E1E0A8B1DC3730ULL, 0x93D10E6FA92C25C8ULL, 0xD152AE0C0FA48D2BULL, 0x0DCE50B1A5D0C8FDULL
        },
        {
            0x86531DB58F97DFF1ULL, 0xE02CECA6EB26117AULL, 0xEC09DF0C2F30EB20ULL, 0x88E8D7687C7DD93FULL, 
            0x29D2AB84BB881C63ULL, 0x373EBBC60952FD72ULL, 0xE43F58C4DBF60CAEULL, 0x159548586D06CD7DULL, 
            0x587E428034003618ULL, 0x764F32B99E0D059AULL, 0xCC4369BD382CB288ULL, 0x64E993703C76AECFULL, 
            0x4BBE28FAB238D3EEULL, 0x3999B5A1C0AB7CD1ULL, 0xCB6CB08AFF0AF9DFULL, 0xEC9FC5CC3509E7C5ULL, 
            0x7D9FE4D51423EAF6ULL, 0x7C505EE95D00DA1CULL, 0x7221E50D2C8A1AE0ULL, 0xC5FCA6CDB60F751FULL, 
            0x748BDD172D52FA3AULL, 0x590C9B922BADF70CULL, 0x1318006A5799AD9DULL, 0xE97CF6043A382F81ULL, 
            0x0EB174653BDAE213ULL, 0xAFA7904AA955BB57ULL, 0x2D441693BBE77FD0ULL, 0xFB472B82E452DDBAULL, 
            0x1881069B45D5122EULL, 0x07EFA251E2619C56ULL, 0xF7A81D6D38B21AA1ULL, 0x6AD9C260D59A348FULL
        },
        {
            0x6CE02A980BEEBB78ULL, 0xA779A5F0FECE5AADULL, 0x15C0FB13ECF569DEULL, 0xD43B8E40C10E4919ULL, 
            0xD0DF21FF565FFAB3ULL, 0xB35376C39AFB0629ULL, 0x4D5FC8B89BDF3EA2ULL, 0xD7E880E6222D37D5ULL, 
            0x91DB5BA9D33A00FFULL, 0xB31830326C20405BULL, 0x3C86EB6DF8A0939CULL, 0xB1DEA0E56439C8BFULL, 
            0x476C7F59CFD92962ULL, 0xF1BC1D6E22C46498ULL, 0x0F04DE13EBC9672AULL, 0xB2E7933DCBBD0120ULL, 
            0x7CCA6B7606BEF3FCULL, 0x91C4076DE037F61BULL, 0x31BF6739F3AE1B54ULL, 0x63FBEA2EA06B3291ULL, 
            0x6B10EF53E3141D28ULL, 0xD1B03F7A4A5B9156ULL, 0xAF5C9AD8809F776BULL, 0x0C4AADD78822D421ULL, 
            0x77193A5D87515B95ULL, 0x1879982E8BA84D7CULL, 0x10A54C364518BFCEULL, 0xC7AC9F62F985E37EULL, 
            0x259ADDF712B5E512ULL, 0x999E82D655907674ULL, 0x72D2CD0530DDF159ULL, 0xC9B63D1CE6100EEDULL
        },
        {
            0xF966C750DCC621CCULL, 0xCA57D5A90F1ECA97ULL, 0x5A07038DD566C828ULL, 0xE04618A39598114EULL, 
            0x2C9CD9B4F22CAA5AULL, 0x9ECB25D7CE824C03ULL, 0x68E619EFC92529A8ULL, 0x3910BCDBC15DCACFULL, 
            0xE439835D06735131ULL, 0x8E82BB13983AEC83ULL, 0xF26F608B8D93CFF8ULL, 0xE9B7A71328B46FBDULL, 
            0xEC4B383E02DEE691ULL, 0xC4914A07FC86CED0ULL, 0x557A12C49111EB96ULL, 0xD4D4655BB438C083ULL, 
            0x1061E2311E29DD3EULL, 0x4E66E2962F1F9FACULL, 0x1D6562FE6F1DAA0BULL, 0xF8744810E71009E4ULL, 
            0x075F88F3E0CB072AULL, 0x74ACF8923C83CD7AULL, 0x835103A3A1C00D30ULL, 0x805909BECA25D128ULL, 
            0x8CB1C9BDFB8B2CA4ULL, 0x06120172B12E2B86ULL, 0x07BA44C89458F5B2ULL, 0x8E75587687347E15ULL, 
            0x3C349F8DB93E54AEULL, 0x64D604674087447DULL, 0x8B322F3D2B78D9C1ULL, 0xDDED35B9C2DB486CULL
        },
        {
            0xF6DCF5DC3BC8F32AULL, 0xF120B0001699CC91ULL, 0xC55DA0BB92CC7F11ULL, 0x2516C1D531E00CF3ULL, 
            0x17655703F75838DDULL, 0x612B4D2F7C9FB1E1ULL, 0xDB11B76FD336FAF8ULL, 0x519316F793224D1FULL, 
            0xA56573BF1B9E178FULL, 0x55BD50D0AC61C036ULL, 0x25EB0D85D65B6282ULL, 0x2C2ABFCCCB7B54F0ULL, 
            0x9B8095F3EAB8777BULL, 0x8518C25054758C12ULL, 0x365E06BC441389FFULL, 0xA550014329FBC4A0ULL, 
            0xD1E4E987173CF924ULL, 0x36FC55E5433B7441ULL, 0x9AFA0D0035D1AE9AULL, 0x19A5A0EF4ED1508BULL, 
            0xA83DD73C64945C08ULL, 0x706DE6351A2C6DAAULL, 0xB48746EE5969C3F1ULL, 0xDC3372F2712C79EDULL, 
            0x1D7B5E797B1BE3C8ULL, 0x714DF79D2398158DULL, 0x6687452937195F65ULL, 0x99F012D974A580D0ULL, 
            0x8138B9D4E95B9FD3ULL, 0xACC3C571B07B6EC0ULL, 0x7BC79C1371189091ULL, 0x6BF2EABC5EECCDEDULL
        },
        {
            0xBB3D3C38E33AF527ULL, 0x0BD176B6D82549A9ULL, 0xA16AAC48D657AD0AULL, 0x7A7618EDCA934048ULL, 
            0xE2B025D98810E330ULL, 0x47782F1C1D0A6B95ULL, 0x821C8E5AD2C13550ULL, 0x0D3495D81B6C3BC8ULL, 
            0xE7CFD80EAEED3C61ULL, 0xF065CD35BCF0D5B9ULL, 0x9D2A33DA2486E06CULL, 0xD3FD923D9DEFACCBULL, 
            0xAA4B6BA8C0AFC7ECULL, 0x82227B8EE427C9D5ULL, 0x0674C3A039E2FC53ULL, 0xE087C940AACF4336ULL, 
            0x0076970F76C580B2ULL, 0x7D8B7AF7535FF7B3ULL, 0x47832844A96FCCF9ULL, 0xCD764150616E78B1ULL, 
            0x56FA8C4D73F9169AULL, 0x64ED82166D8DFCB6ULL, 0xEBC2639D2A7B0E19ULL, 0xA007E0D79E38FB0AULL, 
            0x845F7ADEE57A9762ULL, 0x6522E26F1B785EA2ULL, 0xD976FECB948F1588ULL, 0xAFE0530782BD0452ULL, 
            0x6691CF02C85A586EULL, 0x96402DBA158B72DFULL, 0x13DCB54E55D8CCECULL, 0x90B78A5B2E1062AEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseFConstants = {
    0x772FE5B2A0E2AAD2ULL,
    0xE74188075DCE2A71ULL,
    0x8D8E5806DFF0A269ULL,
    0x772FE5B2A0E2AAD2ULL,
    0xE74188075DCE2A71ULL,
    0x8D8E5806DFF0A269ULL,
    0x1EEE6E1631320667ULL,
    0x32A456A856BB5FFEULL,
    0x36,
    0x55,
    0x56,
    0x47,
    0x14,
    0x78,
    0x63,
    0x4A
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseGSalts = {
    {
        {
            0x8E2412AA255DDD35ULL, 0xA282D164A06A50E8ULL, 0x688624A621A5ED06ULL, 0x0455D0DCD4EDE191ULL, 
            0xD10991B718CDB850ULL, 0x8D7A58A44535BE70ULL, 0xAC4CB08E193DD7ECULL, 0x7E36CBCD9B60EE3AULL, 
            0x7D3A4D196B5764D0ULL, 0x2478294A52E4728BULL, 0x25F942C518E200F2ULL, 0xE2AF7C2898E83761ULL, 
            0x84D7F1E383E636B7ULL, 0xDCFBB44F638D0689ULL, 0x624296A615E2CED0ULL, 0x7BF4E40211712650ULL, 
            0x9CFA2A33C6537989ULL, 0x6FD686712186F6BAULL, 0xD608BA211EE7C878ULL, 0xE8DD4C86D02F1C3EULL, 
            0x1F55E6738AF1B31DULL, 0xE175F4F66FDCFC38ULL, 0x074492D036BF136AULL, 0x21A688422C7A897AULL, 
            0xCEF3AEF6EC5E7E57ULL, 0xFA2E75D4CF19E207ULL, 0xC5301C6C7CF84BE4ULL, 0x1F00262FA2C5BEF6ULL, 
            0xD1390DB94A5C0091ULL, 0x44A62D638930015BULL, 0x086F57ABD8DEC1F4ULL, 0xE565483BC38DABC6ULL
        },
        {
            0xA1EBE62A26EAF5F0ULL, 0xE9A0BDE15B51EA48ULL, 0x93928107B7C4C4FAULL, 0x2A9F384D16D9E01EULL, 
            0x416585DF0446BB6CULL, 0x574A5F744324918DULL, 0x318F765BA54BD109ULL, 0x7579E300D108568CULL, 
            0xDD7BDE4C29079F27ULL, 0x5A3C9739CA5F7D74ULL, 0xD7C4BDCAB30D63F7ULL, 0x0E69DADAD1420ED9ULL, 
            0x9FA4E4979F929879ULL, 0xEC5BF6A566FAB034ULL, 0x9E918305BE677373ULL, 0xCDBAF62387A0B10AULL, 
            0x63CD7FC9E7A18738ULL, 0x570B063F8A91DB2CULL, 0xF2041862A24EFE08ULL, 0x0E7190BC3E4FEAD1ULL, 
            0xDD3A6AA0694D24BAULL, 0xA92D0EA4731719F7ULL, 0x5A8A3B3ADA1495A5ULL, 0x4738FE81F7C5075DULL, 
            0xE859E79D4504534EULL, 0x3F6C65D783205E61ULL, 0x6BC44D8816B7FFB0ULL, 0x251363AE949BF069ULL, 
            0x0CCFCB4165A13279ULL, 0x7B4C5424073C455CULL, 0x26DEF3CCB9F18769ULL, 0x81960AC52A3BF991ULL
        },
        {
            0xB15426C290036564ULL, 0xC2FF7425D38E849DULL, 0x0CB0070A03CB37A2ULL, 0x4F12C7013EC18EF6ULL, 
            0x9F9AB1E546CF72D9ULL, 0xB02B3A3D6FBDC61CULL, 0x0084B6B052FAEBA5ULL, 0x97F8EE6451FFAC9EULL, 
            0x15E39E3ABC3A8996ULL, 0x538C75ED92067EB8ULL, 0x8E161E73A02ACE7FULL, 0xA31583B9845CDC8AULL, 
            0xAE32FBF807EFD5DFULL, 0x8C9FED01E2896610ULL, 0x0AC8F053F8258BD4ULL, 0x4D8F79841F93D5BFULL, 
            0xBA80DF77657BD93BULL, 0xF3AE34C83F768088ULL, 0x595734A8F083DD5EULL, 0x9843088E1918FCB8ULL, 
            0x23FFB13589ED0C59ULL, 0x2523C0061461A1F1ULL, 0xA1F77457E500E56EULL, 0xCC91F849B5860C3FULL, 
            0xCA2CB7CEA8C008A4ULL, 0xFFEFBB9CF30842E8ULL, 0x9086F6511D092B47ULL, 0x2169596FB79AB565ULL, 
            0x1E2B19C6F29B9FE2ULL, 0x90662E66DD41C3F9ULL, 0x9A662626B5F33B74ULL, 0x3723E11C635BBD89ULL
        },
        {
            0x94E7CB2345AD5BCDULL, 0x5C1634668CC4A9A3ULL, 0x1E1D7A85F659DDA8ULL, 0xA861D13C9E1EF209ULL, 
            0x0A4E8EF0D475C834ULL, 0x1D5CB0A2470FBF2FULL, 0xEDE2A984838DEBB5ULL, 0x1B838A959D87DFE5ULL, 
            0x1C65E55C798F5562ULL, 0xAD05FC2FBF1404C7ULL, 0x028917F28028EBAAULL, 0x824FBA0B5B874EA8ULL, 
            0xFDD78387BD8EB74DULL, 0x9C3ACF87338F4CDEULL, 0xEC627F17D7596CE0ULL, 0xA970FF4C9B0FE5A7ULL, 
            0xC79A57A6DE912869ULL, 0x3FD96044C26FA4DBULL, 0x568CD3B8BDE6E154ULL, 0xA8363471E978BF3FULL, 
            0x1AC9F6B0D5895352ULL, 0x396905C19D6AD496ULL, 0x3DDB87093D9CB619ULL, 0x19BB403CBCF8A443ULL, 
            0x4CC79781422B8CDEULL, 0x1E5491E1FBAE3C61ULL, 0x8CD004C4E349651DULL, 0xACBF696C1CEDA72CULL, 
            0x20E1B1B7C256D5AEULL, 0xA4D4BBA82D28B9D0ULL, 0x69F03DD2844F8657ULL, 0x9A86CB0B0C2C2E05ULL
        },
        {
            0xC233E1C867D178FEULL, 0xD2F4011FCD16FC20ULL, 0xAA403DB1AB05F58FULL, 0x965DFD820286F70EULL, 
            0xDA19D62726F7937CULL, 0x58BACDA45576E0C6ULL, 0xE5FC23DD41966C64ULL, 0xE07A6BBD11621969ULL, 
            0x377EE74C600E6B88ULL, 0x1F41F9438EE2B7B7ULL, 0x07E8DE0ECDEED7BDULL, 0xF2F8B14AB9D22E85ULL, 
            0x235FCDE2BA98F5A4ULL, 0x77F2F2920CB30A16ULL, 0xE5760B9E93F063EEULL, 0xFC0792B9E892A117ULL, 
            0xE91ADD27D9E40B59ULL, 0x2C4162AB52337434ULL, 0xA328AAA2A6371416ULL, 0x43F52A71C80B0459ULL, 
            0xE4E6381BB2E43F99ULL, 0xB31EBDA554752383ULL, 0xF193B662712C3CBEULL, 0x5FDD0E463936DCFDULL, 
            0x9F00B311E3D7583EULL, 0x67136DE0C134D7CDULL, 0xCB3019471F5B40D8ULL, 0x1259EB60C2777050ULL, 
            0x01CA560CF2AD56DBULL, 0x9B5A8DBAEBC7E8CEULL, 0xB4ACBA5DA0857A9FULL, 0xDCEF81D028207C74ULL
        },
        {
            0x0F2EFCF898407F7BULL, 0xB7308C809E7EC815ULL, 0x221696CA5C5B8605ULL, 0x66A5DA46AC097460ULL, 
            0x2AFBD4DDB511EA7EULL, 0x087D7F710E346299ULL, 0x5FF1581E2426A96AULL, 0x7A8AC025959225F2ULL, 
            0x4867D6A7151736A2ULL, 0xBF5459C923519461ULL, 0x0AE2C317DDA0BDD6ULL, 0x186C7938D668AC86ULL, 
            0x6D615730C3C7584BULL, 0x07AE54E42917AD3EULL, 0x518BD0364B50756BULL, 0x9CABBCBCDABC9B01ULL, 
            0x759E378BA398DA54ULL, 0xFF920C7CD0094E32ULL, 0x8BE6C1073B651A2DULL, 0xC99BA1AA15ED772EULL, 
            0x07C1D17ED1615F53ULL, 0xA6DBD10FDA692744ULL, 0xBF6371D96A9D83B8ULL, 0x3DDF460E29465783ULL, 
            0xD94CC5A87D130C4AULL, 0xFCC15EAA4F964C68ULL, 0xB5F83BE636DE6996ULL, 0x7ABC276FAD948462ULL, 
            0xE0607E3173FC8529ULL, 0x369B8A43B72D7F1BULL, 0xDF5C16473D2828E1ULL, 0xF709A6FD0C927FACULL
        }
    },
    {
        {
            0x93592D6185764271ULL, 0x27F8287DFBC4DC4BULL, 0x9BE275C2484BE8ACULL, 0x47B96B52D2CFCFC3ULL, 
            0x5422B568AE5209D0ULL, 0x891C3DC285617A70ULL, 0x40AA64D9532AD155ULL, 0xD7266891D129E7A7ULL, 
            0x9179D39448772205ULL, 0x69A292D49DEC8434ULL, 0x8864FC0896B5E824ULL, 0x274C2C6E92414CB1ULL, 
            0x236BED97FCA2C140ULL, 0x89F00FA5B8408A9DULL, 0x061BE5FECBF782CDULL, 0x292AAED02B7AA550ULL, 
            0xDA874A0121C02203ULL, 0xAACE13BA9969B39BULL, 0xD37591BF1BA62D5CULL, 0x671847CBA421C5A5ULL, 
            0x348275BF2DD473C7ULL, 0xF4F1E5B2CD9E13ABULL, 0x6557E11240D7320AULL, 0x54A95E23306BC026ULL, 
            0xB84CCBAA4320AA23ULL, 0xEA5F1B544DCE90F8ULL, 0x048291E3E3D9B143ULL, 0xE37BB90B9B9276A5ULL, 
            0xE5EED91947A33399ULL, 0x45E0163F74E08181ULL, 0x744BF64DE1E8682FULL, 0xC2F43A0612E88AABULL
        },
        {
            0x630D14927268FE74ULL, 0x2DB156E57117C096ULL, 0x41442F028B38CF7FULL, 0xD00E6A861D831499ULL, 
            0x7EE84DDA378FA136ULL, 0x15FBDEAB3F98B227ULL, 0xDF472B2E57906500ULL, 0x2353A81AFD78C5B2ULL, 
            0xCCCAFA8ADBD597ADULL, 0x18F7F70E6885F0E3ULL, 0x6ABECF954FE63446ULL, 0xCCDE48BCD2438236ULL, 
            0xBEFC012F66998EFFULL, 0x81BECFC33F8CB26BULL, 0xE43298C55AF8FE7AULL, 0xF64520873C0AD506ULL, 
            0xCC1D74926F652343ULL, 0x587611F47EE8DEB3ULL, 0xE98E04F13A64FD46ULL, 0x6C7025D0C94299C0ULL, 
            0x7253B27348B148BBULL, 0xFA5C413E0D547748ULL, 0x9F716A47BF14C869ULL, 0x5FBC78C9DDB5FEE9ULL, 
            0xA1EBD0B5C982A47AULL, 0xF4D7B05197A7EA93ULL, 0x22D88DD14C14477DULL, 0xF4F6CF39852B6DD1ULL, 
            0x3C251ED83D9B7862ULL, 0xE6F2251008589FDFULL, 0xB97D969BEBF62937ULL, 0xF08969E2C986920DULL
        },
        {
            0xE4B21D26DA8CB9E9ULL, 0x92FBDAD57DB36CD7ULL, 0xF8E1CF07F47AD10BULL, 0xF9DBB25447051223ULL, 
            0x0C177B4BF4E9627EULL, 0x65F1993A9DB5BBD9ULL, 0xC9CE48000D648547ULL, 0xF07C2CCD5FC0995FULL, 
            0x51483B99DDCE043FULL, 0x17AE923256BE12C9ULL, 0x1FE95B1D33522EACULL, 0x122CB85D89818E02ULL, 
            0xA6590A790400B8CCULL, 0xD97BAB544B663B6BULL, 0x3AB88DE4F08148C7ULL, 0x375E6B7E9F84C4F2ULL, 
            0x5A23B13FEF2A42CBULL, 0x4AFA708DC366257CULL, 0x852B7B91C72F8C6BULL, 0x3B39EA07465612FBULL, 
            0x1F9F0B6B733BF5E9ULL, 0x1133714B23D1451FULL, 0x16896B6F6EE2F09EULL, 0x802D4B611C64AE9DULL, 
            0xA390DBD1F764561DULL, 0xEA20EB8E3C54FFCBULL, 0x243973ED17C2755BULL, 0x3C7154B484D65CADULL, 
            0x8BD6EEF103A417B3ULL, 0xC44E7388CBF6FD30ULL, 0x4D683FF25055FFD7ULL, 0xAAAF8AB5EC98663DULL
        },
        {
            0xF0751B3806C7D828ULL, 0x4934E3E9F258248AULL, 0xA6E6FDEDE26EFED1ULL, 0x831D5087947E849EULL, 
            0x21B2BC434406794CULL, 0x415CD362BEA18434ULL, 0x36A61E2E0A9E9174ULL, 0xB1A8042C93F0180AULL, 
            0x8A31D110149AABD1ULL, 0xC33F49EED676B590ULL, 0x6226B9E227916057ULL, 0x690290BB4D70FD92ULL, 
            0x9B75BD82D1845B74ULL, 0xB9242E9637FD462FULL, 0x3FE9A9C656B68EFDULL, 0xC024BB30A0A2D917ULL, 
            0xC9EB3DADA3EB86DCULL, 0x4E1383507E2D16C9ULL, 0xD2B80E332A849BD5ULL, 0xEB5D9B31F094D69CULL, 
            0x97B3B4D6041E0013ULL, 0xE7D6D75CC1AF66C3ULL, 0x9AD32F4E42E733C3ULL, 0x79BD054F1B065AD6ULL, 
            0xE3F53D41BC77F870ULL, 0xB4A38A561B177C40ULL, 0x7C067ACA2254A4B3ULL, 0x2E32BD1F2DC1D956ULL, 
            0xBB79089D370D2D50ULL, 0x3B0769009DDB1CAFULL, 0x5D653928803E370CULL, 0xDA4C09529570DC7AULL
        },
        {
            0xEE17E767C2BEB041ULL, 0xF98760F1EC38008CULL, 0x39FB6362E50033EDULL, 0xBEE2154A6BC32474ULL, 
            0xE736DF98482A4DDCULL, 0xFCB6BC46AD108563ULL, 0xF7E9C6ACDF66F8E2ULL, 0xC9930820D43DED07ULL, 
            0x6DEBC7DA2AAD5ABCULL, 0xBF33F312A89F63DCULL, 0x6A28E72CBD5FE62BULL, 0x2F66D4B64053E524ULL, 
            0x4A07ED1CB370FDF2ULL, 0xF647DC5C50FAEC04ULL, 0xF22D8523EA6BD2A6ULL, 0x54895BC183BEBC79ULL, 
            0x20C892484275607AULL, 0x600EFAA283F2BB71ULL, 0xDBEEE16508612FC5ULL, 0x18D2999FDDFF6AD1ULL, 
            0x3098DDE3BEA12FD7ULL, 0x521E6F7DD856F49BULL, 0x8CEF37A28C4350E5ULL, 0x3052178870BFAD46ULL, 
            0xD071B9605CBD9417ULL, 0xD8C364E55AA2AEA6ULL, 0x27BC160A08B55FE6ULL, 0xF0C684BBD255B8E8ULL, 
            0xCF2770A8414833B1ULL, 0x46110967910C900FULL, 0xE64A747B7B20FBCFULL, 0x2D7C4DF4C5DB125EULL
        },
        {
            0xA488F700ECBB6D87ULL, 0x17DA907C9D63A137ULL, 0x60F2A278E8239D23ULL, 0xF27D382BD3BBF861ULL, 
            0xFA52871F088B12C3ULL, 0x9ACFF148D1B5AD66ULL, 0x8CD481FD282A51E8ULL, 0x6182FEEA20FE8EE6ULL, 
            0x2B0A3BD50FF722EFULL, 0xB962163AF61CCD54ULL, 0xEBFB0BCDAC700596ULL, 0x8113D5ED0CD53F06ULL, 
            0x712674AEF7268101ULL, 0x106B7D0083713676ULL, 0xCAED792F0825061FULL, 0xC43650F60546B29EULL, 
            0x67D3CBCB04E347AEULL, 0xAA7940ADED09661EULL, 0xAECC0C81A117AD87ULL, 0x4CC41C024B0CF3F3ULL, 
            0x3B3999B5B01A4682ULL, 0x7A12880E3F46F1CAULL, 0x268CED843E48059EULL, 0xE2377B8483B7E933ULL, 
            0xC847AF37752DB07AULL, 0x44E29DFD012C190BULL, 0x77922A5306D090FFULL, 0x80EFD1AFA39DEEEAULL, 
            0x857819A434E6E9B1ULL, 0x439FCA2A03C06D69ULL, 0xAE7CF0BAFED49190ULL, 0x019E0B8D69A3769BULL
        }
    },
    {
        {
            0xCC771CD8CDD78338ULL, 0x6757EBE2ABE59581ULL, 0x29D9EC42F4A0FEEBULL, 0xD8F274EEA46ABBE6ULL, 
            0x4932C492F2D5BC83ULL, 0x881E7104DB38292EULL, 0xF7C7D7283111C78CULL, 0xFAC05739E7DD0BF1ULL, 
            0xCEE4532E808C5667ULL, 0x637010C65BDE7B6CULL, 0x452FDE3A2E678A68ULL, 0xAAA67D86E008B291ULL, 
            0xA89717247323E896ULL, 0xD61F3E193148C075ULL, 0xD3157856EEEDD26BULL, 0xCFE08E59402B762EULL, 
            0xDEB211EB94F9DE83ULL, 0x16CE54EAEC20FB66ULL, 0xE65446B9B5139BA6ULL, 0x3D4316E129F56F0AULL, 
            0x38406CD60FAD7057ULL, 0xAB32ACDC08A224FAULL, 0xC6002F23EF06CF49ULL, 0x37E02FBE909377D7ULL, 
            0xD313EB8336A4F558ULL, 0x4EF64C95A2F71773ULL, 0x66D1DE097F430280ULL, 0x0F2D5A15675F4EE6ULL, 
            0xBD95E36AC84CFBA6ULL, 0xEF284E098ED0E3D9ULL, 0xD15F73799BA94BA6ULL, 0xAEC81A28D5751726ULL
        },
        {
            0x79A1C8D1A87C3276ULL, 0xB7E9B596C18F5EF0ULL, 0x3B0575FF11C6392AULL, 0x0F04BDB0F69D5A57ULL, 
            0xC5838B781D265BFDULL, 0x6F4829D77DEDD2E5ULL, 0xB88FDDD90ACD3171ULL, 0xFB33F4F1C84916BDULL, 
            0x44ED63B130D6D82AULL, 0xEDBDFE9451A445D0ULL, 0x8CECA681FC9C5380ULL, 0xDC4CBF54E52C2282ULL, 
            0xC95C6C5F198F57F9ULL, 0x246010B9F64381BCULL, 0x04BA21AE540DEC95ULL, 0x095FC9CE80191863ULL, 
            0x5AF967802F0E3D16ULL, 0x7BCF0D8AB8604B63ULL, 0x7FD0055396E9F397ULL, 0xD1A4DC7D5D5767B7ULL, 
            0x525E52A85B579631ULL, 0x679EA21023A276E2ULL, 0x624537246DBB125CULL, 0x2390DC942B7B0C7CULL, 
            0x02F986556B7B47E9ULL, 0x08D38EE2DE16AC7FULL, 0x69B9C1A8C3A37B6FULL, 0xC23A1F9463D5F24DULL, 
            0x95109A210DDC62EAULL, 0x945172EE1F22D38EULL, 0x2487EB4A5AF5E343ULL, 0x1997B4F46C096D5EULL
        },
        {
            0x587EF1D9FA4AEA59ULL, 0x366334DFFDCE6F21ULL, 0xC7C96DC083DA879DULL, 0x6B23E4260CE49576ULL, 
            0xAC0C9DB2E60C0051ULL, 0x1A306D73AEF86278ULL, 0x5B308904C85566FAULL, 0x1F746EC1CAFD6542ULL, 
            0x595589DB7A5F82DFULL, 0x64668D935EA82862ULL, 0x6C2A6698E53D2D8AULL, 0xBC12DD35A8D14B47ULL, 
            0x28A46AF1585E5AA8ULL, 0x67029BA703740FFDULL, 0x85E42C560BFF1784ULL, 0x1285CF6463931730ULL, 
            0x70B82D9B03ABDD72ULL, 0x7159A49B2F087C71ULL, 0xDB001A0B433E773EULL, 0x0BD39816D8BF5439ULL, 
            0xEC82E7FF8F278EFEULL, 0x226607B488AF96B7ULL, 0x9916074D081F000DULL, 0x120CB07F8E3ED218ULL, 
            0x89032341038BD1F7ULL, 0x78E0FC8956BF1AFEULL, 0xDC28B3C9FFCB5DA5ULL, 0x809AB4184B779D32ULL, 
            0x217F1BF984F7FDB3ULL, 0xCD1602FBFE5E4C31ULL, 0x76E449F2E1C80FDCULL, 0x41CD1576B7706453ULL
        },
        {
            0x57217F2CE320BFA4ULL, 0x76D3A33AEEE3D56AULL, 0x066F48BE96249FAEULL, 0xB4C87C2F2DBEE117ULL, 
            0xC011F3599327D936ULL, 0xA042E9E501037C52ULL, 0x3FD3C0BFC0DF038AULL, 0xB840167C17D27F62ULL, 
            0x90C7B1EED2278B37ULL, 0x84158BA489A76365ULL, 0xC9A518BCE3505E29ULL, 0x880BC3A319A1B41CULL, 
            0x02ACB7640D5A2544ULL, 0xFD4CF9CFFE00FD99ULL, 0x3540348AF6034A07ULL, 0x2A9604F105FB7C68ULL, 
            0x4D8FFF3108472344ULL, 0xBC09048568897186ULL, 0x6168CFAEE2A8FD93ULL, 0x7EFD958B65B6897CULL, 
            0x53A703FFFB545AD0ULL, 0x7A98D2FA6EB5181BULL, 0x51CC63FEFF522D59ULL, 0x93120BB59B35A977ULL, 
            0xA413F69939FC32F3ULL, 0x6F29B2BEE054CDA8ULL, 0xF484CE2D43769972ULL, 0xB460ABD1774E3593ULL, 
            0xFD0BD4B55EF2C921ULL, 0x6ED4F11D420DB5C3ULL, 0x15BD9BD9A0A32A7AULL, 0x84F32571699CC7CEULL
        },
        {
            0x38016F3EE519A8E4ULL, 0xC100A7325A6D8AC0ULL, 0xD3F655C68D2D04C9ULL, 0x831FB7931B5DF936ULL, 
            0x65B01BDC81CFAE09ULL, 0x11CDF95DD7BEA954ULL, 0x8B94E3A42C87EDA7ULL, 0xF6EDBF1E7DD4774CULL, 
            0x364383DE1583ED7CULL, 0x5F654F9C7257A9B3ULL, 0xC8033A1AC929C966ULL, 0x3A2ADBB3490FC498ULL, 
            0x0E8C0DA6A809D922ULL, 0xCB17F7EC64B4B903ULL, 0xB496A1091D98BAE8ULL, 0x987AFECE49F2F4FDULL, 
            0x451E6DFF73D7E5AEULL, 0x79F15CC89072EFB7ULL, 0xBD0D1F32124CD73AULL, 0x18A13F722D6FBF0AULL, 
            0xABC935B546CF10C6ULL, 0xAA0BFF812E539EE2ULL, 0x2E9A9DA10A9EA971ULL, 0xB780DEC8BB352DEBULL, 
            0xCA8FCFA30A1614F5ULL, 0x0B370C03453B1DD6ULL, 0xFC2D1C261801DB8BULL, 0x2DF6189B989007FAULL, 
            0xBFDE50EAF1D0A1F3ULL, 0xF3FF2460445403B4ULL, 0x648DDAEA35421A89ULL, 0x95BD4AB499CBD696ULL
        },
        {
            0xC10CDB3C7F93843BULL, 0x040D61F67E9B0E8DULL, 0xDCB6753E2A666FE0ULL, 0xFC20D5ACED884F27ULL, 
            0x270FE9E3AD54DFA3ULL, 0xF052156C2D01C945ULL, 0x8752B1DD0423F200ULL, 0x77AD81C08D7B9531ULL, 
            0x102D828DCD6623C6ULL, 0x6AC86715FEB70640ULL, 0xB30AC7117E462A6FULL, 0x0A0746A3C38F4B7FULL, 
            0x0BA9F88D2B293A27ULL, 0x451F00809AB7E124ULL, 0x86C422297D3047E5ULL, 0x745B982455758C87ULL, 
            0xFFA4D94C68717652ULL, 0x7AA4B8A7BBC0E1FDULL, 0x472EB268D2A19E62ULL, 0x206189A7955836EFULL, 
            0xC660E3B988C3C29BULL, 0x71A0CB9896324DFAULL, 0x1C2974A2F84D88BBULL, 0x41CD829E7D856307ULL, 
            0xCBC519FD18287606ULL, 0x5BB0D9F2EF9D2CD8ULL, 0x0149634B06FFE0B0ULL, 0x238AA62E46289058ULL, 
            0xD370A651AF879147ULL, 0x6058FAB0E0A63393ULL, 0x9134FAA913CD3F8CULL, 0xB467A28A00E7D3C2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseGConstants = {
    0xD2A5261F2BA1F719ULL,
    0x6D898144E5EBBBD3ULL,
    0xD430D936FCD60932ULL,
    0xD2A5261F2BA1F719ULL,
    0x6D898144E5EBBBD3ULL,
    0xD430D936FCD60932ULL,
    0x8A50B5152CEEC703ULL,
    0x336C4CBEFD3494ECULL,
    0x10,
    0x06,
    0xB9,
    0xAF,
    0xEB,
    0xA0,
    0x2A,
    0xFC
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseHSalts = {
    {
        {
            0x99F5E388A452E526ULL, 0x40A26D2BF6F6C7E0ULL, 0x29E58C24B2A6AD0AULL, 0xA5EE504EDA4B8FB5ULL, 
            0xC5D068A0628BEC22ULL, 0x6BE95DF2E6C88F46ULL, 0xAFA887E860ACC7A6ULL, 0xAFC36A8CA21FD3E5ULL, 
            0x82B3CC23E919EA9CULL, 0xD4CD1FC54F8B648CULL, 0xB8F7ACCE934045CBULL, 0x287A0EA2C7B5CAB9ULL, 
            0x3F05198357948921ULL, 0xCC13C041744D0C9BULL, 0x0FF333252D61962EULL, 0x65DDF66E3481CFE9ULL, 
            0x8D0B1EC1992B590AULL, 0x4CFB0E006FB01C6BULL, 0x94B6C8265F39F3E5ULL, 0xE2B155387B733217ULL, 
            0x11710E076164F6DBULL, 0xB5D0B0B13F1C886BULL, 0x7BAC1042284362AEULL, 0xCFBB8957B61AAA46ULL, 
            0x7B7E85A8898A834EULL, 0x806359B7C4EFA271ULL, 0x3F9B273A2EF9A925ULL, 0xA7006A9209647EE9ULL, 
            0xF7337013CBF8A46FULL, 0x123ADA4E63E84441ULL, 0xDE68DFBBADD51D0FULL, 0x2E841BB10D5F3237ULL
        },
        {
            0x6FF3CCCFA4B19935ULL, 0x09954E7DC522E322ULL, 0x9B13F5F2A7CC7799ULL, 0x9AA340A713813FD7ULL, 
            0x3C7BBD38A6325074ULL, 0x4C46DF73AC9EB0AFULL, 0x4A7B815F0FFCEA93ULL, 0xACA3563932B5EFB5ULL, 
            0x252CD70E11088CC0ULL, 0xB58E1F8499791640ULL, 0xA426868F728DD4DBULL, 0x540C5F2D07002450ULL, 
            0x449E0332CBE08198ULL, 0x45CEAD589C7FBD37ULL, 0x03D7D90C31633A69ULL, 0x48A566E992C65810ULL, 
            0x2ECFE8E7BD6A0DB7ULL, 0xB58ABE3A34CE5BB0ULL, 0x9E2A19273504F880ULL, 0x674C16023B9FF79EULL, 
            0xCBCDEA4325083110ULL, 0x3602F77E4C89A116ULL, 0x0B0448E46B9FEFB9ULL, 0x71C6F7B498F04AA3ULL, 
            0xB2A597305DFD538CULL, 0x716DEB0DE96D783CULL, 0x0CA0182ACF23713CULL, 0x143C0B8C0F7548DFULL, 
            0x2B29D8F3F383DF6FULL, 0x432C2F52D753473AULL, 0x74FE53E281D097C8ULL, 0x8A9AA31FFF4485E9ULL
        },
        {
            0x1CB0ECDD16928351ULL, 0x970BE1336D7FB7FEULL, 0x087035250B21B768ULL, 0xBE06BC74B45FF2B7ULL, 
            0x8CAD4FC903F46AA2ULL, 0x51BB03722A8894AFULL, 0x31C9FAC3049A483AULL, 0xCBD79980C3784334ULL, 
            0x2ED17D936AADC5FBULL, 0x94F8CD9D7620EAFFULL, 0xA755FBEB8106B5E6ULL, 0x525B1610AD517B2FULL, 
            0x67BAD6835F3C0392ULL, 0x9C45B3CD0C082508ULL, 0x8A8D394B232BAE98ULL, 0x038B3A3815723C2AULL, 
            0x31807855E6649D44ULL, 0x53711AA568383F5EULL, 0xE5FF5A7603415E8BULL, 0x666C7D2EE8EBD934ULL, 
            0x357E5CDB23F9E247ULL, 0xF9600949E5C9C6C8ULL, 0xF0B286AF473CA13DULL, 0x47C0D26A70CC6790ULL, 
            0x28A2F04C50689CBDULL, 0xDAAE3BF57240446AULL, 0xDC580F948BBD8EA2ULL, 0x86620689F98D2AF1ULL, 
            0x3A983D7D894729F6ULL, 0xE82C77B08B57F4AAULL, 0x2AA9EC4054989C51ULL, 0x6F3BE9245FBFBA1AULL
        },
        {
            0xEE731B96E3B3DD39ULL, 0x71F98DAAC185235EULL, 0x3361EB54AC896BBDULL, 0x041C2C3B3361F50FULL, 
            0x4902A9505094864CULL, 0x7ED7CD27A969930CULL, 0x044E1803DA5DFE2CULL, 0xE2DEEB8D67EF7844ULL, 
            0xAD062DF8E22EB7E9ULL, 0x7F3EAF4CA7E9764AULL, 0x9113C0B6DAA1A72EULL, 0x3D572323A83D45BEULL, 
            0xB78FB8C8EBDB14D2ULL, 0xE7D4C243983805ECULL, 0xA00294F3F704F4D7ULL, 0x45FDBBC8B31917C8ULL, 
            0x0E7260DDE925476CULL, 0x77F11D3E9BBADF25ULL, 0x82AD9E764D3C5EC1ULL, 0xD9124F084356C48BULL, 
            0x1DA26949E83B8834ULL, 0xEE14D7EF8E85A3DBULL, 0x2C167E6C91F96DCFULL, 0xEE20F452F50CF263ULL, 
            0xCDD14435D760EAFEULL, 0x959828B68E6DD1BDULL, 0xCD05801505948656ULL, 0x735782DBBFD65B20ULL, 
            0x425C93545EC83F69ULL, 0x86F0AF0A1188F1F6ULL, 0x2F775E682191D456ULL, 0x4AB72F3F077FB93EULL
        },
        {
            0x822C79A51C66B757ULL, 0x2885872DEB7FC394ULL, 0x37CAD3A9A5F14E76ULL, 0x33D8100C9CAABD43ULL, 
            0x929A954C863A5D0DULL, 0x7D274057EDBB3962ULL, 0x12AAEC21036FC89CULL, 0xB70C1B2A8861286BULL, 
            0x642724844420C681ULL, 0xD3217D78A95ECBB8ULL, 0x95F92E7F074ACD5DULL, 0x5678E0BC793244CAULL, 
            0x08FBE332F05CCF16ULL, 0x7B9466C8B518F6D5ULL, 0xD9B058A7D909FBE6ULL, 0x5D7144305782BBB1ULL, 
            0x1900E81E0AB9EC6EULL, 0x05C962EDD95A15F0ULL, 0x7FD17CF943DE785FULL, 0x30A649F53CF9F1DCULL, 
            0x67FB4A8387001BDEULL, 0xF07EF61E7204D5F2ULL, 0x8E11E177150E744AULL, 0x1E856D2FFA77A03AULL, 
            0xCE542B6F0A72AA84ULL, 0x7AAC4BDD51AFFE88ULL, 0xD8A2705B58F413CAULL, 0x0E74551AB9BF8E27ULL, 
            0x94F4DD7C31AFF52AULL, 0xCE6941AEEE6ED378ULL, 0xCE9827F87964DD93ULL, 0x6A31EBBFA79B3717ULL
        },
        {
            0xBE19A6594CF0FF27ULL, 0xA46093315DED9A97ULL, 0xAD086A309A941A84ULL, 0x1C49371AF8AE183EULL, 
            0xD902C6723CEE48CFULL, 0x94EBB1712B2ADE88ULL, 0x239B6F5E557AF422ULL, 0xE4D345AF2158503DULL, 
            0xDC541A71D5D48AC2ULL, 0xF888799F82B3A5B5ULL, 0x88EEC494ECED538DULL, 0xCD143E1B3C4CD429ULL, 
            0x4C0B6E78077D0950ULL, 0x9D167CE6C38C0F75ULL, 0x380C0B75600256AFULL, 0x99F155F985EAB8C7ULL, 
            0x10251C68CAE74827ULL, 0x53A886C6A460729AULL, 0xD3839168BE7E38C9ULL, 0xAAB45A1869A3E796ULL, 
            0x272B5B699C743E98ULL, 0x239A4E1C49A6D6CDULL, 0x1FDF8AA595024772ULL, 0x4E83AD61C49B5E0DULL, 
            0xB115DEFB20C1CCEEULL, 0xEDEAAEA029A873AAULL, 0xA6266EE700D5DA12ULL, 0x775F209AEAC12113ULL, 
            0xFAC912F965257A22ULL, 0x2554FEE5D6DEC775ULL, 0x225C1D7761FDD9E6ULL, 0xB7142D75562CBFE6ULL
        }
    },
    {
        {
            0xFD975C3706CB7012ULL, 0x3CBB3136EEFF11DFULL, 0xB02DC2FAFEEA9ECEULL, 0x9C5B560E24A90A7CULL, 
            0x743F3B45E0CDBA6EULL, 0xC8E59E858670C1B3ULL, 0xBFD5BCF2151BBAF2ULL, 0x7502FC91D24E5A2AULL, 
            0x2673478D0F33C71DULL, 0x64E6EC2D87991182ULL, 0x3541A4FEFE7F4364ULL, 0x9722EB45927A3A77ULL, 
            0x968082145EF6F403ULL, 0xCAEFED1D7821D5A5ULL, 0x075C96B361C1D047ULL, 0x293BD1DE6AA657C7ULL, 
            0x78ACC5379665A7B2ULL, 0xEC8C655CDC5C5A02ULL, 0x8AC7D0DD5CA23A44ULL, 0xB125C3DAB6C1D101ULL, 
            0x671805D8FBF5AD21ULL, 0x3E6AF0A8C1931BFEULL, 0xE4AE77AC5F7D733AULL, 0x2AE0CA7ED73FE9AAULL, 
            0xB96C2A63B6B3C74EULL, 0x6BDC675EC3EC23C8ULL, 0x719C26A511D0BDF1ULL, 0xEEF0A638802F3339ULL, 
            0xA2E8829FBD70E167ULL, 0x4A7C305650455F6AULL, 0xC5F4CDBF4EEFCBF1ULL, 0xE5294A79760978E7ULL
        },
        {
            0xDCBD009E7D9614BDULL, 0x3A0107386DAA48F2ULL, 0xA90D4DB7537A916EULL, 0xD30A0EAD970A9C9DULL, 
            0x7C1B20B2E775E2B1ULL, 0xB1BD0E79D1A2CE97ULL, 0x0DEF545AC0F027FCULL, 0xA0EAD1B9C3FF920CULL, 
            0x36DD2809AFBA9D55ULL, 0xDAE018A6D7519DA5ULL, 0xCD6249F3F01E546DULL, 0x58A6028623347835ULL, 
            0x9DC7B06920578C38ULL, 0x30EC0CFDA3A32556ULL, 0xF11CFFFBF6D8AFD9ULL, 0xCBE2AB2536D33B49ULL, 
            0xDA43290A702DDEA6ULL, 0x7393DD6B4606B2C5ULL, 0x37D295ECCAE549D4ULL, 0x550013CBC1FD796BULL, 
            0xA823BBAE52A4D424ULL, 0x0E2289B13FE9B0EBULL, 0xE7D411058FBAE10DULL, 0x3722864C6C13A871ULL, 
            0xA2EB7CFD6DB043DDULL, 0x6DC094336100203EULL, 0x3586074E2EB9286FULL, 0xB48197ECD6B6A097ULL, 
            0xFDE1ED3D285646ECULL, 0xB5C791DB148CC429ULL, 0x6188B2C79F2A49F1ULL, 0x27F1BAFA71AD5FF4ULL
        },
        {
            0xFEFDF6877229E208ULL, 0xAEBCF175890A20EAULL, 0xD58FE0463BE90D99ULL, 0x1F8EAACFA678377BULL, 
            0xECD0A31A1FC77FE2ULL, 0xC55F8452253A6719ULL, 0xF116A4DBBA69D03DULL, 0x957464678A6EBADEULL, 
            0x6F498CA8636237CFULL, 0xB4F7AD1A42D51AC1ULL, 0xEC7528FFD7CA8BCCULL, 0x6802C758BF1DA142ULL, 
            0x65281D8DAB957305ULL, 0xCCD2D8E6DE2E506EULL, 0x19CE517355D8201AULL, 0x2E772EB6F1B94EA8ULL, 
            0x949384CA80848A66ULL, 0xFABE8B4F2FE8C5C8ULL, 0x9E65127144FBC232ULL, 0x2D3DC69FD978D656ULL, 
            0x87A3AEF818F477EBULL, 0x6670C9B8BC3D1C86ULL, 0xB8E39C6745B8D4C6ULL, 0x84FE5FCBEEBF71ACULL, 
            0x65BC2D68190B7B49ULL, 0x05B7FF8FBB6B6397ULL, 0xB3F2FCFEFF66826DULL, 0xDA6F58E8F4AE7ED7ULL, 
            0xC78DA302133A5536ULL, 0x7771602EB301DE5EULL, 0xB3D8FFCB85235F5EULL, 0x0629E4CCC7AB6321ULL
        },
        {
            0x5ADB340C13CF3CE5ULL, 0x46E774BB035B5320ULL, 0x0D013D29D9346937ULL, 0x696A0DB30354497AULL, 
            0x4259E06A2A31AA53ULL, 0x7EB45AD1FB6453E9ULL, 0x9FE2B3F0BA0E6536ULL, 0x50D608ABB260EE66ULL, 
            0xAA6089B80F14CF24ULL, 0x3802C46EEC33A7E9ULL, 0x7010342118DCFC16ULL, 0xF61C250D321977CCULL, 
            0x21733293F5D14987ULL, 0xE8B140F85793A851ULL, 0x14B0F39D0A886C8FULL, 0x7D9B366B9D1C8CB1ULL, 
            0x46F02C84184BE2CCULL, 0xEA0679414F2D6623ULL, 0x94EA8B448C4CEEB5ULL, 0x6946F499B0BFA7A3ULL, 
            0x589303C8BBFEAA47ULL, 0x234680AB64878315ULL, 0xB6786C94E351E6B5ULL, 0x4B215E3EE1A658D9ULL, 
            0xB99C6AD935B8E780ULL, 0x53674B1C9944026BULL, 0xCDBF9B5C860C853DULL, 0xC8CB51B94B894E25ULL, 
            0x747F4FCCED52A19AULL, 0x2A4545FC81C92EA3ULL, 0x8EAFBF1BF7B008F2ULL, 0xFC9598B1A5582BE4ULL
        },
        {
            0x3971E16549415E78ULL, 0x91C7AB550C743984ULL, 0x0DBABEFED16558E7ULL, 0xA4CA5B53B90937C9ULL, 
            0x55A23B27FABA0CC4ULL, 0x47203E6FBAD08300ULL, 0x27637BB674A4AABCULL, 0x4DB069D9EB9D6019ULL, 
            0xA3ACD3798EBAC82AULL, 0x21725B10F7804A07ULL, 0xFB0B20D31AA1387AULL, 0xEA86E5F1400634BCULL, 
            0x772309AA3EDB8F2AULL, 0xC3F51546209405E5ULL, 0x809A20D397506337ULL, 0x1B57F7772C5A319FULL, 
            0x5CAADDD773959422ULL, 0x5DB2ECC1D1185424ULL, 0x7855F5DCB2D8A4BAULL, 0xE8E91CD70FF293E4ULL, 
            0xABEF528E83088A0DULL, 0x4D012CA0F2BB9B5CULL, 0x714222674338CBC3ULL, 0x251C017039D03BE1ULL, 
            0x5504C85B2EB11C4BULL, 0x00004B69D45B640CULL, 0x42687A31033ED303ULL, 0x45271C06C0BA79C5ULL, 
            0x3CA02947B7EAD837ULL, 0xC9B0C89A2B1B1337ULL, 0x409A534754B68FCFULL, 0x33F89FA3CCD0C979ULL
        },
        {
            0x760B17C99AD061B7ULL, 0x6EBB13D280D4BEBEULL, 0xE843D2064E041345ULL, 0x67D8B857A1833A2BULL, 
            0x8ECA25FB56222A9BULL, 0x6406EEA6CB9868E6ULL, 0xEEF9EEB17F06F8E1ULL, 0x39E6EA2E03CFAAA3ULL, 
            0x74532E3A9E964405ULL, 0x1B7BCDAA6886A750ULL, 0x7AB8768ABDCA06A8ULL, 0x0067AAE381254C64ULL, 
            0x93B5D4D7A7574E75ULL, 0xE13AAA6BAE781D49ULL, 0x3912117C8FC07987ULL, 0x92CC3227275BB79EULL, 
            0x6ECE23E253393949ULL, 0x5E96D1AC4B9A59C2ULL, 0xBACD8D09F8A1AE31ULL, 0x1F822679867BBB30ULL, 
            0x7240D878FDA9204BULL, 0xFB55F78B2A83EAC1ULL, 0xA2AB4C5D318716E9ULL, 0x4445F0191BF30575ULL, 
            0xAA6661E089ECC1B8ULL, 0x6258BD65D06FEE54ULL, 0xE7EA0DCFD03EAF68ULL, 0x571CF7317DBC290FULL, 
            0xFBFE9CC5070AD69FULL, 0x11D57F160BBC5E86ULL, 0x515E34E2B206AAC0ULL, 0x627B5B3274FE70AEULL
        }
    },
    {
        {
            0xE5874E355DA76C24ULL, 0x86867E95B069A32FULL, 0x6CA47E56AAB3E3CEULL, 0xE212B7C8C0111A24ULL, 
            0x65759862324397CDULL, 0xE885EFB5EDFCFFBBULL, 0x52719E7342772EFAULL, 0x5BFEA1D160C7FBA3ULL, 
            0xFB625D215726A129ULL, 0x2CB7F3B3B5F59151ULL, 0x62A8856FA0B09F38ULL, 0x58877EFD50438946ULL, 
            0x0F1F750808C590D2ULL, 0x89713F3DF20C8724ULL, 0x011986AEDB2EE601ULL, 0x2ED5B3F8331D3835ULL, 
            0x121294FEE5526945ULL, 0xF2A12BE61CA7C163ULL, 0x08418728467FA653ULL, 0xC5FA3238995F6FBCULL, 
            0x5773086970DCD0C4ULL, 0xA3F7FE60298A58C8ULL, 0x715595C532BB99C4ULL, 0x51C6EB945E6F222EULL, 
            0x949FA1198FC34E63ULL, 0x5B5CAC9E28E10564ULL, 0x270E6CAA4471C99CULL, 0x488E17D5D95E0D6EULL, 
            0xA5BB9451582D6588ULL, 0x2AC1C93BC235EB91ULL, 0x4EA44300CCB2C884ULL, 0xA6493F66A5E74F9CULL
        },
        {
            0x08EFB7B1F2941076ULL, 0x6AD18D930B0B8AC3ULL, 0xB02DC48E709EA7C9ULL, 0xA9913A563808E6A6ULL, 
            0xB2B7664D71265827ULL, 0x5BBE6B8ABB584B95ULL, 0x7296F134B161F5AEULL, 0x522410715357B2AAULL, 
            0xB3DC6EE1218B202DULL, 0xD1FE49D1EBE2AA44ULL, 0x7960B85B372D6E6CULL, 0xC0F67966B61E7828ULL, 
            0x621D20EFA0366F42ULL, 0x455987EB443038FFULL, 0xAD28F9BD909C07AEULL, 0x5202D4F81B271829ULL, 
            0x81C7A3E2A286C030ULL, 0x515D2BAADE70A79DULL, 0xF381BFD33B4919FDULL, 0x8163092A365F7188ULL, 
            0x5081195695616CE3ULL, 0xEEB9284AB990707FULL, 0xDF7B9AC7581E308BULL, 0xE8D268F4BB30F23EULL, 
            0x0FA84634E1CA9CF4ULL, 0x5BB58016B9445E68ULL, 0x2522975EA11A3910ULL, 0x35DC1F3A300C2A16ULL, 
            0x3EE4B0DB7CDFA218ULL, 0x09610289C298AC78ULL, 0xF656BB09D30E88F6ULL, 0x79A158A456D0631AULL
        },
        {
            0x870F2CE90FE6B2BDULL, 0xA5F9FD4157B45D7EULL, 0xE8E76C2640CF8251ULL, 0xB579286C641B0B8CULL, 
            0x949764AC82597BB7ULL, 0x931B8A2DA2CC2B1AULL, 0x183ACCE6D44B7AEBULL, 0xFFF41EA3A3E85097ULL, 
            0xD6C4CAC46FB75817ULL, 0xED1919792B3E2DA2ULL, 0x0DDC53A142BCAED3ULL, 0xF8CBB093FE9F6243ULL, 
            0x4117622C0C615ED2ULL, 0x595487DA05CC8DB2ULL, 0xE06F3BEBBD285FFEULL, 0xF9A45C245345BBCFULL, 
            0x8B52D406C96399CDULL, 0x4B44080412861803ULL, 0xE43E7BE50083D8B8ULL, 0x2D04BBE03D8179EBULL, 
            0x1D9A3323125EAF43ULL, 0x5126B12A1C937A97ULL, 0x09BE5C2263C7B2F2ULL, 0xC76CD993B8FB3B7EULL, 
            0xD99349B2FE16D905ULL, 0x0E2C5429EDB802C2ULL, 0x91C16DCDCFE53A0AULL, 0x3791922138C1EA53ULL, 
            0x9FE54776C8F41A49ULL, 0xE901FA46611F7457ULL, 0x3A54D27E7D2F8554ULL, 0xEE5D18D7A5AA6492ULL
        },
        {
            0xCA30BB6A03CC5F9BULL, 0xE8FD8E5C8E9EED18ULL, 0x936CA3C9B4FA38F5ULL, 0x30C75CFBC2EE55AEULL, 
            0x5CFEE9627E1BC31EULL, 0xE5578EAE91D8FE3BULL, 0x912A6ADBB64864C9ULL, 0x3E4602DBE76AF7B9ULL, 
            0xF4B3BAD04F489FE2ULL, 0x3D2B43F584849AA7ULL, 0xEE9487A55F6DC4C0ULL, 0x44169182A8845122ULL, 
            0x8625B0F8B7F1662CULL, 0xE6737FD046E62536ULL, 0x890C1EE12A2B235EULL, 0x92BAE7B997BCF167ULL, 
            0x4455CDB72FA94B80ULL, 0x93059BDEA916EC54ULL, 0xC3E0FA72B6FD7E82ULL, 0xF680C4E3D3437D8DULL, 
            0xB3A2088481F2B83CULL, 0x131CC146199130F7ULL, 0x747CF50EA49973ABULL, 0x324EAA5F3A672A5AULL, 
            0x38D6FC4A9F491596ULL, 0xE101E5CD86DFAD05ULL, 0x49FB5CA02EACF792ULL, 0x1B4A59F31DD1E863ULL, 
            0xADDD50A196A4F3E7ULL, 0xF35696CBBD761FE9ULL, 0x0A8D791A845109C8ULL, 0x5CA3F0E4414D2A28ULL
        },
        {
            0x9EAE1EC24833064DULL, 0xB6426298A659E4AEULL, 0x2CA5E309213C69D3ULL, 0x955D4D47E43EC977ULL, 
            0x907577EC8241EC84ULL, 0xC75ED3D1C639DE7EULL, 0x66027E698D4D1C67ULL, 0x4D491D7121768968ULL, 
            0xD64E7E213158F01CULL, 0x70AD1304ED552E14ULL, 0x460B0ED2842B50DEULL, 0xF79FB4FF59C8BC51ULL, 
            0xFB79643A277259CCULL, 0x3147D0C092CBF389ULL, 0x5A4931B7ACE3021DULL, 0x404C10A62E1A3F38ULL, 
            0x994BD832FCD366C7ULL, 0x01AB9A2FE4E43C54ULL, 0xA67EBDA0BD5CFE55ULL, 0xC7B9C099BA8D8475ULL, 
            0x338D50C837895CB7ULL, 0xD8A675863DDA43B2ULL, 0x33B11986F76134A4ULL, 0xD15A428FA47260D0ULL, 
            0x7112A0CC40A0AE34ULL, 0x9F57CB25E3B9CE39ULL, 0x4D75EC19CEE9E326ULL, 0xDE023113036DA740ULL, 
            0x4E5F7FAAB50EACABULL, 0x2A81FF2D286B2F31ULL, 0xA61581719DE6B206ULL, 0xD89662549A0AE1ABULL
        },
        {
            0x04EC0592F389225AULL, 0x76F578030A604D50ULL, 0xE5DB706DAF44EE07ULL, 0xEBE0536B615CA2D8ULL, 
            0x97C87122A9D815B0ULL, 0x9D513A1422D84B4AULL, 0x5C9F7134B92D4352ULL, 0x903F83824163F384ULL, 
            0x88A5B2BBABA237BBULL, 0x988355D1B75288FAULL, 0x35799041A1D44E4FULL, 0xAF9CDB68E24F7454ULL, 
            0xE999BA2436DE299CULL, 0x5978052E0A2A94EEULL, 0x7708214DEB80A98FULL, 0x26CB314CDC02840AULL, 
            0x352FBC22A75F669EULL, 0xB8BC0DA399BFE33FULL, 0xE049B32B63F20CF1ULL, 0x7ED87C8D72573689ULL, 
            0x4EC94F8247B922C3ULL, 0x4AE6E854184EC8D3ULL, 0x6F672F5CA5AE90B2ULL, 0x5DD5D0D23DDA92F1ULL, 
            0xA757E6816C308D52ULL, 0x71CD2F2173544E4BULL, 0xB3A57225F58F844DULL, 0xD3CF7FC24D303919ULL, 
            0x81BD35BD31DA6175ULL, 0x06812FE392F8D7A8ULL, 0xD7D499C1294EE14AULL, 0xEAA750B26D8F8820ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseHConstants = {
    0x219902E8055734AFULL,
    0x0396B4226ACE6A94ULL,
    0xAB27877E78D3E627ULL,
    0x219902E8055734AFULL,
    0x0396B4226ACE6A94ULL,
    0xAB27877E78D3E627ULL,
    0x823D86C4B0BF89E3ULL,
    0x03722E35F96A084EULL,
    0x4C,
    0x34,
    0x93,
    0x90,
    0xAB,
    0xAB,
    0x63,
    0xB9
};

