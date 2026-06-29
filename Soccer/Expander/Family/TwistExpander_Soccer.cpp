#include "TwistExpander_Soccer.hpp"
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

TwistExpander_Soccer::TwistExpander_Soccer()
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

void TwistExpander_Soccer::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x966495721154F1CAULL; std::uint64_t aIngress = 0x8C0F60AF1FA1D5CFULL; std::uint64_t aCarry = 0xF6645394D491D771ULL;

    std::uint64_t aWandererA = 0xB8D4AF5241733D25ULL; std::uint64_t aWandererB = 0xED66DC3A0DCBC51DULL; std::uint64_t aWandererC = 0xCF952FE2AAABAA6BULL; std::uint64_t aWandererD = 0x9508528F29BB084DULL;
    std::uint64_t aWandererE = 0xB170E3F6EECB72C3ULL; std::uint64_t aWandererF = 0x81EF2DEF4DF02B30ULL; std::uint64_t aWandererG = 0x9AA4358AE56EC02DULL; std::uint64_t aWandererH = 0xE82614C8E8AC6A41ULL;
    std::uint64_t aWandererI = 0xA735D219B0A1F0ECULL; std::uint64_t aWandererJ = 0xCD9069EC6DA44547ULL; std::uint64_t aWandererK = 0x80DBC8A7E93A8947ULL;

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
        aPrevious = 15427298916032097719U;
        aCarry = 16869128211550530281U;
        aWandererA = 12692685539992537475U;
        aWandererB = 17650324155641789697U;
        aWandererC = 17860740143380819243U;
        aWandererD = 14972983689479605813U;
        aWandererE = 14199543711725757064U;
        aWandererF = 13815828262043007100U;
        aWandererG = 13537518051586625280U;
        aWandererH = 9583497663386783581U;
        aWandererI = 13548419922761026197U;
        aWandererJ = 12718269072907729829U;
        aWandererK = 9680083619243612063U;
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
    TwistExpander_Soccer_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Soccer_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Soccer_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Soccer_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Soccer::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xAB9893AEAFC4A877ULL; std::uint64_t aIngress = 0xF11745C52AC5077EULL; std::uint64_t aCarry = 0x876A25BEB4389886ULL;

    std::uint64_t aWandererA = 0xD49A6187E3F13CCEULL; std::uint64_t aWandererB = 0xA028B7637904BF43ULL; std::uint64_t aWandererC = 0x9A733F807A1DB877ULL; std::uint64_t aWandererD = 0xCFC78A80D8ED532BULL;
    std::uint64_t aWandererE = 0xB6B3A26F82636398ULL; std::uint64_t aWandererF = 0xB456213F127AA0CCULL; std::uint64_t aWandererG = 0x9330E1F38AE69942ULL; std::uint64_t aWandererH = 0x8356BCA75E00F339ULL;
    std::uint64_t aWandererI = 0xC25398843C867B61ULL; std::uint64_t aWandererJ = 0xE39C4F5CA8BA5C8CULL; std::uint64_t aWandererK = 0xE40BA37894EE06A1ULL;

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
        aPrevious = 15946683331520215153U;
        aCarry = 14938235848491577861U;
        aWandererA = 10830580669088948636U;
        aWandererB = 14552571683568968752U;
        aWandererC = 15946056455326132542U;
        aWandererD = 12307747677419523775U;
        aWandererE = 12013910456007987414U;
        aWandererF = 14954106959823425365U;
        aWandererG = 15507215368329103704U;
        aWandererH = 11780258794852440349U;
        aWandererI = 18233689873326296578U;
        aWandererJ = 10595595372643228412U;
        aWandererK = 9399644275875532125U;
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
    TwistExpander_Soccer_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Soccer_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Soccer_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Soccer_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Soccer::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEE686D5C26C7D6A7ULL;
    std::uint64_t aIngress = 0x9D14D9C446ED88F7ULL;
    std::uint64_t aCarry = 0xD6AE2E4A032E480DULL;

    std::uint64_t aWandererA = 0xB4D3BC5EAC698297ULL;
    std::uint64_t aWandererB = 0x9F543ACD2E69E914ULL;
    std::uint64_t aWandererC = 0xB13F16FFB431684FULL;
    std::uint64_t aWandererD = 0xF63B7AB74DFA3A99ULL;
    std::uint64_t aWandererE = 0xC82C65F6BFDB50F7ULL;
    std::uint64_t aWandererF = 0xB4A1BDD4EA9C3EE5ULL;
    std::uint64_t aWandererG = 0xD160FBBBD3B962BEULL;
    std::uint64_t aWandererH = 0x8E4E36E1DF6E537DULL;
    std::uint64_t aWandererI = 0xFA09CC4C85AAFF14ULL;
    std::uint64_t aWandererJ = 0xB15DF78605E9B833ULL;
    std::uint64_t aWandererK = 0x8FEB992AA9816715ULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC, 0);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneB);
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneH);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneC);
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneF);
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    std::memset(pWorkSpace->mOperationLaneA, 0, S_BLOCK);
    std::memset(pWorkSpace->mOperationLaneB, 0, S_BLOCK);
    std::memset(pWorkSpace->mOperationLaneC, 0, S_BLOCK);
    std::memset(pWorkSpace->mOperationLaneD, 0, S_BLOCK);

    std::memset(pWorkSpace->mWorkLaneA, 0, S_BLOCK);
    std::memset(pWorkSpace->mWorkLaneB, 0, S_BLOCK);
    std::memset(pWorkSpace->mWorkLaneC, 0, S_BLOCK);
    std::memset(pWorkSpace->mWorkLaneD, 0, S_BLOCK);

    std::memset(pWorkSpace->mExpansionLaneA, 0, S_BLOCK);
    std::memset(pWorkSpace->mExpansionLaneB, 0, S_BLOCK);
    std::memset(pWorkSpace->mExpansionLaneC, 0, S_BLOCK);
    std::memset(pWorkSpace->mExpansionLaneD, 0, S_BLOCK);

    std::memset(pWorkSpace->mFireLaneA, 0, S_BLOCK);
    std::memset(pWorkSpace->mFireLaneB, 0, S_BLOCK);
    std::memset(pWorkSpace->mFireLaneC, 0, S_BLOCK);
    std::memset(pWorkSpace->mFireLaneD, 0, S_BLOCK);

    std::memset(pWorkSpace->mSnowLaneA, 0, S_BLOCK);
    std::memset(pWorkSpace->mSnowLaneB, 0, S_BLOCK);
    std::memset(pWorkSpace->mSnowLaneC, 0, S_BLOCK);
    std::memset(pWorkSpace->mSnowLaneD, 0, S_BLOCK);

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
    TwistExpander_Soccer_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Soccer_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Soccer_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Soccer_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Soccer_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Soccer_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Soccer_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Soccer_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Soccer_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Soccer::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Soccer::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x98E81887AC73DC0FULL; std::uint64_t aIngress = 0x864686EE1B064B78ULL; std::uint64_t aCarry = 0x99A61D2FA2D39AFEULL;

    std::uint64_t aWandererA = 0xD4E22E89FF972F87ULL; std::uint64_t aWandererB = 0xF8B919C7B990A3D9ULL; std::uint64_t aWandererC = 0xF366E1DD3C65B2B3ULL; std::uint64_t aWandererD = 0xC4DD05A63218BFB0ULL;
    std::uint64_t aWandererE = 0xBC542AC926E0E5BBULL; std::uint64_t aWandererF = 0xF83300E764D385B1ULL; std::uint64_t aWandererG = 0xC7B46DC696E2DC2AULL; std::uint64_t aWandererH = 0xDB47EC5EEAA9A9CBULL;
    std::uint64_t aWandererI = 0xE97656ECB2892A12ULL; std::uint64_t aWandererJ = 0xE0B23771EF09E85FULL; std::uint64_t aWandererK = 0xFC0061D84A3B93ACULL;

    // [seed]
    {
        aPrevious = 14609407906165924530U;
        aCarry = 17708406949200924404U;
        aWandererA = 18027498672495227979U;
        aWandererB = 14386428952525885847U;
        aWandererC = 14807413803769313806U;
        aWandererD = 18014113278409278658U;
        aWandererE = 9595448509518356104U;
        aWandererF = 11799755409415170919U;
        aWandererG = 17164648671387728261U;
        aWandererH = 15364630124754373962U;
        aWandererI = 13609102157917519577U;
        aWandererJ = 9457294981610334624U;
        aWandererK = 16319886367616952992U;
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
    TwistExpander_Soccer_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Soccer_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Soccer_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Soccer_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Soccer_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Soccer::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 2, 3 with offsets 1005U, 629U, 4027U, 6945U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1005U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 629U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4027U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6945U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 1, 2 with offsets 3523U, 2081U, 660U, 7522U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3523U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2081U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 660U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7522U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 0, 0 with offsets 5141U, 5261U, 756U, 2469U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5141U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5261U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 756U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2469U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 3, 1 with offsets 2743U, 954U, 909U, 6515U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2743U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 954U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 909U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6515U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 1, 0, 2 with offsets 294U, 937U, 2035U, 731U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 294U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 937U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2035U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 731U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 0, 3, 1 with offsets 1034U, 983U, 1962U, 104U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1034U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 983U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1962U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 104U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 3, 0, 2 with offsets 755U, 504U, 279U, 177U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 755U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 504U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 279U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 177U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 1, 2, 3 with offsets 1944U, 961U, 1752U, 830U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1944U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 961U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1752U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 830U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1953U, 884U, 88U, 1372U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1953U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 884U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 88U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1372U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Soccer::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 1, 3 with offsets 795U, 617U, 3430U, 7219U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 795U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 617U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3430U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7219U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 1 with offsets 4983U, 5781U, 1426U, 2186U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4983U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5781U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1426U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2186U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 3, 2 with offsets 6078U, 1118U, 5995U, 5074U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6078U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1118U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5995U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5074U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 2, 0 with offsets 1892U, 4705U, 1044U, 4595U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1892U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4705U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1044U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4595U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3579U, 6724U, 952U, 5501U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3579U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6724U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 952U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5501U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 989U, 1449U, 751U, 109U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 989U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1449U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 751U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 109U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 80U, 420U, 1168U, 789U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 80U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 420U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1168U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 789U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1273U, 716U, 1796U, 2015U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1273U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 716U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1796U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 2015U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1106U, 1848U, 85U, 1476U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 85U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1476U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 1, 2 [0..<W_KEY]
        // offsets: 502U, 1549U, 527U, 1715U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 502U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1549U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 527U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1715U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseASalts = {
    {
        {
            0xABE4D856D5488DB9ULL, 0x5A8790292D459EB7ULL, 0x6F4E3D5D8A7B787BULL, 0x2BEC8762DDA75F22ULL, 
            0xE0C386648D0329E0ULL, 0xB53EE063A94BAA18ULL, 0xA486380DEAADF3CBULL, 0x5AD59FDE7C22754EULL, 
            0x192CEE355525B88FULL, 0x0FA923F829D9841EULL, 0xA8EECF81D831A09AULL, 0x902DC3108A457499ULL, 
            0x6066001FAE729EC8ULL, 0xEC6EB3111D347CD9ULL, 0x4001CE3E75E98CB7ULL, 0x7444A6C44CA0F474ULL, 
            0xD032391451D3A493ULL, 0x8DB481543646ECA4ULL, 0xF68A2AA7FF82A617ULL, 0x7823B3B7981494EEULL, 
            0x8AC1EECB55847B84ULL, 0x61D9D8C040E243A5ULL, 0x9E2D4F40786E3130ULL, 0x971ADD609E62BE9BULL, 
            0x861C0ED5FC7ECA8BULL, 0x918253B5C18D6A70ULL, 0x73F94E67F170A798ULL, 0xD7C1035137E6349DULL, 
            0xC0C565328A6C621EULL, 0x9A8702D99A759B9EULL, 0x72B1232B8D5D7D4CULL, 0x1A29C6CE1D0B766FULL
        },
        {
            0x4087405CEA83BE86ULL, 0x1EAE5EB941D8FF3EULL, 0xF6D5D4ABDE4406A1ULL, 0xBB46046648C891DBULL, 
            0x752A0E362F68E472ULL, 0x8911681D56B28F32ULL, 0x4E808478C511149AULL, 0x66ED4F0DA63DE07CULL, 
            0xFC08E3DAF1AEF065ULL, 0x6A139C0B7CC68D33ULL, 0x755D3B4FC73B5B95ULL, 0x273520A69102930AULL, 
            0xFFC6A8F7A5B3B74CULL, 0x269E2963D4C1AFF2ULL, 0xE00437FBA1FAAF6DULL, 0x7C588849F3C76781ULL, 
            0xEDDCBDDE2A96D517ULL, 0x95A20B200C3AB4AEULL, 0xE0992AAC02F2CACAULL, 0x7FDDA34C54720BD0ULL, 
            0xEC96A0DFEA17050FULL, 0x7D06BB594E4C6DF5ULL, 0xA165229CB200102EULL, 0x39B328A0D06566BEULL, 
            0x260CDE643D33E3A5ULL, 0x6BD7EFCF7E94DE24ULL, 0x07661BC04C116310ULL, 0x39CE9EF8F7A955B4ULL, 
            0x55B4D1357D77E55BULL, 0xD4D0DEC96503F2F6ULL, 0x6D15BF19DEC3AFE4ULL, 0x2171C4C68AC0192DULL
        },
        {
            0xE425591437003BFDULL, 0xF59C7D8A9EF24D89ULL, 0x7709C39A53D24BA5ULL, 0x3A304B52B37EE372ULL, 
            0x2C1DB0E536EB9E01ULL, 0x348D5359D07BF392ULL, 0xC64A41D7DBF4079FULL, 0x4A4A0B0A662EEB4AULL, 
            0x6CF80E5C7CC68847ULL, 0x03077CC42597E267ULL, 0xE490CA95D560B395ULL, 0x8F1993D594E985C1ULL, 
            0xA5F948E4D14C0615ULL, 0x893DDB8D82D4C466ULL, 0x1147F09DDEA8B293ULL, 0x34463D8AF5CD2AE3ULL, 
            0x5832A13D9F54D48EULL, 0x7832204788A4848CULL, 0xEDEB6E96F2D2301DULL, 0xB6F1D424536AAB64ULL, 
            0x0C78C9482E008240ULL, 0x4C3C82FC17E96F3BULL, 0x93AF616750549DA7ULL, 0x38CCFEF19D5C59A9ULL, 
            0x30D75B8F64A5EB94ULL, 0x39C4F26A9AB52B13ULL, 0xAC09BBA82C957546ULL, 0xD3C9F6B0FC4680EDULL, 
            0x5F782E8A72162CDEULL, 0x5C4B6CE45D7F674BULL, 0x31C14047C5F190F8ULL, 0xB85EEF426E7144F5ULL
        },
        {
            0xEB1E8BB0592B6EF9ULL, 0x4752B913898BAABBULL, 0x54C99861349BB8C3ULL, 0x604ABE41B7B82D76ULL, 
            0x4A8BB6F63F367CB8ULL, 0xC121C18C918B3604ULL, 0x4EB90BB55EE66B7DULL, 0x38F2D28CD57DC7CDULL, 
            0x34836EA80082C650ULL, 0x9B93A375BECA3CCFULL, 0x51811EF55640F887ULL, 0x32C985012F51D1DAULL, 
            0xE74F45023BA4EC7EULL, 0x7F7F5F87C7A56685ULL, 0x4B0D970CB02F8DCDULL, 0xAF5E8098552ED00FULL, 
            0x56FB3155E8188C60ULL, 0xDED4F78CE4507C80ULL, 0x7FD54D4204327CDCULL, 0x383C99A2FDB40722ULL, 
            0xB602925E6FFEAAFBULL, 0x20AFB0717C4EEAC0ULL, 0x07CB4F9384C57E70ULL, 0x49E1CAF8423EDE37ULL, 
            0xE2D9F0A8A799454AULL, 0x3F287E9A125EE5FFULL, 0xA716A6AE90BE586CULL, 0x0C9B6E00E524A207ULL, 
            0xA2F75B0ADACACF9FULL, 0x8799DFCE2A2E04ADULL, 0xA9B3CD9680F9589FULL, 0xBEFC58382C548191ULL
        },
        {
            0x272E7ED5A2F2BD91ULL, 0xD91D0554BBB3B9ABULL, 0x567D8E28D8ECA9E8ULL, 0xDCBE5F4F61E8D8CCULL, 
            0xA0B204E94B7B05E3ULL, 0x39DF73353B235019ULL, 0xB942E6B367E34FC6ULL, 0x31857B761ED96DEEULL, 
            0xE9F769B2893D4D96ULL, 0xDC9783A112BC03EFULL, 0xA0D84EA830483AD6ULL, 0xE6682B761AE254C1ULL, 
            0x1DA40058CE68B23BULL, 0x25325BBB09F2F012ULL, 0x090B85AC07ABA882ULL, 0xAE045E4E2CBBA896ULL, 
            0xB9205919EFF10B63ULL, 0xBE06A92E3130A1E7ULL, 0x21749615133E4B69ULL, 0x4043F992816D1EF2ULL, 
            0x8F016DB4E65BDB73ULL, 0xFAD1554F41946F9DULL, 0xD6123382DFB4A897ULL, 0xE4F6334CDA943118ULL, 
            0x0720CEE2F43D12C6ULL, 0xE0798FF0CA6C44D3ULL, 0xA19F9F3D140CA312ULL, 0x8DAB3E735D08DE4EULL, 
            0x051434B7E57FDF77ULL, 0x7F99F05BBBDBBE41ULL, 0xA5A211B88F9847DAULL, 0x75AAD0C4F81B1CA0ULL
        },
        {
            0x3D86CBFF54EE5F81ULL, 0x293F74B565B0115AULL, 0x430FB63A3CAFF78DULL, 0xD1408CCFBE902125ULL, 
            0x15E659BBCD9FA057ULL, 0x4E5FAB8A672B6D2DULL, 0xD61578D76E35486DULL, 0x4F2065613B1274D6ULL, 
            0x0B171DEB777D1728ULL, 0x091BD9B5B6927246ULL, 0x4EEB44F63DBB8D48ULL, 0x3010A83308AAE915ULL, 
            0x521D1D75E28C1F63ULL, 0x1776D58D1750A5B4ULL, 0x5AC6174BE757F7ECULL, 0x66FDC22026E8C029ULL, 
            0x524854B8ADEB67C1ULL, 0x059557F99609937EULL, 0x68CA9BDE2480FFFCULL, 0xE4F6CB38A1458661ULL, 
            0x479255992303F0F7ULL, 0xCAC393A6EBA6D372ULL, 0x77B702E59F7D5104ULL, 0xC582FA58F1311E32ULL, 
            0xCB0497A3B6954936ULL, 0x6158C74A06BC7AB7ULL, 0xC29903E7D2588EB8ULL, 0x5457BC7E6DBAECADULL, 
            0xA96C7810A44ED7AAULL, 0xA8D34301CF4262B8ULL, 0xD96A139CC1AF2660ULL, 0xCC4324508C540C75ULL
        }
    },
    {
        {
            0xDBF75E3227A772DAULL, 0xE03BC74F0B54A07BULL, 0x3C84B54A490C8F19ULL, 0x8A9D83B64C0E1F02ULL, 
            0x0AD83F7721D6239BULL, 0x5FD380ECD5A1B975ULL, 0x6F5DD3593370D5AFULL, 0xDB5393233E3B88D1ULL, 
            0xF8A8CDA428D4EE4CULL, 0x3BC94E1A9C55857AULL, 0x53BC8C3CC9EB2421ULL, 0x17A57AA09BBFE284ULL, 
            0x6AE2F8250E2BF344ULL, 0x4010D49ED95160C5ULL, 0xB013F024B353ABCAULL, 0x501B4B15E20144E5ULL, 
            0x872360383AB91AD3ULL, 0x60C8ECAD83162D2CULL, 0x67C08BAF88DBFFB5ULL, 0xDE54784FFA92431BULL, 
            0x5620F982BA141FC3ULL, 0x9F1467EEBADDB120ULL, 0xFA2F57F4EA8E98C0ULL, 0x7E988357C07149FDULL, 
            0xA83A45E5D7F55277ULL, 0x6EE25E2AB5927CB6ULL, 0xA261865E1B665B14ULL, 0x6A14AA44BBEB86F6ULL, 
            0x979BDE80B652E30CULL, 0x2FEBF08D01F643B8ULL, 0x49B03B69D4F9538CULL, 0x51393A06D0DBD078ULL
        },
        {
            0x1987D4C2BA12F2B7ULL, 0xAAEF92C1921E8FA1ULL, 0x251B5948482FB646ULL, 0xDEA3DDFD02A3C1A9ULL, 
            0x6BA4EC3AF6DF785DULL, 0xFADD2718F7CA8E77ULL, 0x8C6B15D06D549DD8ULL, 0xB46DD299B11B39E9ULL, 
            0x1776DDC59997B3F6ULL, 0x5565C7EA6A7ED7A6ULL, 0x4ED2F64AEB87AD0EULL, 0x6E3D55359B9A7316ULL, 
            0x480731D39219563CULL, 0x8B4394885C95B26DULL, 0x21B0093CF7AD5082ULL, 0x4FC659860BBEB341ULL, 
            0xA9DA8A2D0AB7594CULL, 0x5FCF6140677A6F79ULL, 0xC7EA20506A332F42ULL, 0x0FE5E50C0B0A228CULL, 
            0xF59008A63AB6BC7DULL, 0xA2CDDC23AD191D6EULL, 0x143451119B729963ULL, 0x1C404C6E963AC0A8ULL, 
            0x2D0485B3430A3ABDULL, 0xC56782588B15CBAEULL, 0x2DE2331F4EB595BCULL, 0xD93EB4F12181ACE2ULL, 
            0x177DF2314DFA694AULL, 0xFD50BF68374BE64DULL, 0x1321FB433A5E44A2ULL, 0x77A8A06310DC9609ULL
        },
        {
            0x0B0F6B317C1CD1EEULL, 0x7CFFD2B5B7A7165DULL, 0xF2B35E7D667E9304ULL, 0x55D06EDE5D60A4BCULL, 
            0x8DEBB84360E3B550ULL, 0xFAAE3B1CD71D035FULL, 0x26053955F1B79B1FULL, 0x9219FD1DA97B9A22ULL, 
            0xA4F55AFDF51BF5A3ULL, 0x34DA350AF72E7D9CULL, 0x32D5591737AC235CULL, 0x09AC0E449732A185ULL, 
            0x259122946FECCBBEULL, 0x76388EB6D11220EEULL, 0xD70E53509FF0067CULL, 0x042D4E65B610731AULL, 
            0x324BE66DA70BD2D9ULL, 0x8EDE143C152167BBULL, 0x3236EB94CACBB33EULL, 0x07E3CDA9D6905E11ULL, 
            0xC7A7CB79AF19D56BULL, 0x579446C9CFD1DB7DULL, 0xC941FDDA0758E0A8ULL, 0x50CCA2DF1A2C38C6ULL, 
            0x04FB7F81C4D07180ULL, 0xB731ABC8DBFE8786ULL, 0x0D24F6C8B878B593ULL, 0x68700C1764456EBAULL, 
            0x4990D29E81FBECB1ULL, 0x9680A12080573FF8ULL, 0x2C3548826B7D23DCULL, 0x9DC527891E4A3D0CULL
        },
        {
            0x27C6B355DD08F8FDULL, 0xC1813931E815084FULL, 0xECFF35BB3AD641F3ULL, 0x3E89E48A77C882AAULL, 
            0xB175A35A6D992CB8ULL, 0xDE565CE92769C6B7ULL, 0x862A81DA85F38BAFULL, 0x79211A5B0EA60670ULL, 
            0xE23562AC0451976EULL, 0x987652169AA1D72CULL, 0xA2CBE0B6C7B25560ULL, 0xD238C05732E51E11ULL, 
            0x928338BB00C51DBCULL, 0x134A19FB5394B395ULL, 0x6AF0782268DDF420ULL, 0x647B3985A227510BULL, 
            0xC0D4FE4FB93DFF73ULL, 0xBBB823330233ABEDULL, 0x03A63DBB63726141ULL, 0xC27837B978B517A3ULL, 
            0x6DCB04CD2DB83D72ULL, 0x6FB9FD055FCCCC2EULL, 0xCF97334B017CEB92ULL, 0x02544AABFAF4C3F2ULL, 
            0xEB99DFAF34BFECC7ULL, 0x6F4CC7E6A399577CULL, 0x5489A17136819A65ULL, 0x347135CCE3189EC5ULL, 
            0xD0FFA5D736E30338ULL, 0x3C18E7E423211D99ULL, 0xF27C437B922D3778ULL, 0x19D6176F69213C44ULL
        },
        {
            0x1D66D0B0B7BDE3FCULL, 0xFA202637B9595A6CULL, 0x8434AB5F33738657ULL, 0xF8E50985F9540A79ULL, 
            0x55A3D5B3948E2597ULL, 0xC2EF5FC8D6B64E56ULL, 0xEBE19AFA6B862290ULL, 0x9025B327F60C7000ULL, 
            0xAB2E3D5F1738FAE3ULL, 0xA630ADFB19AEFB31ULL, 0x3267DC0C63AB9EF7ULL, 0x5D6E564815ED71A6ULL, 
            0x3BE883E158746BEFULL, 0xE03751BFFD2CC3FCULL, 0x42F38F4B14237067ULL, 0x259E69A86C4C6318ULL, 
            0x32AACCF71FCA6914ULL, 0x1F2EDDCE2329BA68ULL, 0x8CD2F8F0FA476DBDULL, 0xC0F892564F4EA31EULL, 
            0x28CE9CBE33618947ULL, 0x4C3F939C75871919ULL, 0xDCB9861F61F09416ULL, 0x90397CF2C11A1922ULL, 
            0x57A1106BC94F859CULL, 0x3CD953869E9B3FEAULL, 0xB3304FD71086CA60ULL, 0x5850294221B2259BULL, 
            0x3FC261505A4EAA13ULL, 0x6D7F49B3C78FDE32ULL, 0x69884C3829C92BD8ULL, 0x7B3811BD72D4C2B8ULL
        },
        {
            0x7B7C5A940F81F332ULL, 0x6FFF7D2988E76B5DULL, 0xC6D6BDD7F431DD08ULL, 0x2688A6BACFF40616ULL, 
            0x7F02B292E5DBBC67ULL, 0x733F1E3A266E77DAULL, 0xAFF6B3646ED4751EULL, 0xA8D97DB55DAA46A1ULL, 
            0xEC82464F00E7A344ULL, 0xCCC3F3BB02688044ULL, 0xC119B3D775DE5EB7ULL, 0x4F23CD75CFDFF83CULL, 
            0x28C184A383CD4F70ULL, 0x23A1538E67A27D27ULL, 0x894F07AA5A0D4B5AULL, 0x641E51981996CA0DULL, 
            0xEF6B3DEA11BE9FE2ULL, 0x74CAC85FAE460FEAULL, 0xD64EAF5BAB148D6DULL, 0x3C5408C3A6ABF14FULL, 
            0x429CBD1EA2414486ULL, 0x1EF298BA8CA4F357ULL, 0xBC6246F7C6B12635ULL, 0x74DF8D15EAE9116BULL, 
            0x71C3D1F229ED8475ULL, 0xDD34ECEBB1B36417ULL, 0xF3B51714EF516CE8ULL, 0x491B75629C9E68B4ULL, 
            0x8CD247DC68A7D224ULL, 0xC6D951BAC7B18D76ULL, 0x885B84559C88C1C2ULL, 0x667DE7F8762785DAULL
        }
    },
    {
        {
            0xA33764099515F484ULL, 0xCA9E0F5C93D171F8ULL, 0xB790E8B2AEAE2712ULL, 0x7E505A954BAD9FEDULL, 
            0x4EEA187749F7A5F8ULL, 0x9396B7305686294CULL, 0x0D0126F3EF43DC20ULL, 0xEC04CC98B67BDAEBULL, 
            0x3066EFDDBA888564ULL, 0x631B62B7CEE85CE1ULL, 0x175C05F6F880FD81ULL, 0x0C015F6318650D18ULL, 
            0x5297B39AC868F438ULL, 0x3A2FC0C2626E7671ULL, 0x9225ECAE5F9BD265ULL, 0xA5ED34C1D2505F75ULL, 
            0x056536EC775FB64FULL, 0x0155B73D3F3CA3FBULL, 0xF12CB20D347B67BAULL, 0xB924CF0F5A237102ULL, 
            0xDCBE6E904A8F1BF0ULL, 0x98224FA77DA76F58ULL, 0xAE1DFDDA42E85B1AULL, 0x3526276F073D21E8ULL, 
            0x2D1C9ACE0237ACE9ULL, 0xA8132D2D03F0CDB4ULL, 0xEA985DD92193B606ULL, 0x1C1349D0C803FCCFULL, 
            0x86EB88DA285C0FFBULL, 0xFEFF0CE1ED9EF66EULL, 0x1A05BDDE302B5F6DULL, 0xFF087558061F0A50ULL
        },
        {
            0x5B7EB7C8AD42B245ULL, 0x3A48B26A7BFF87E4ULL, 0x0838F53F03A1EE0DULL, 0xD2E900FFA128F2E7ULL, 
            0x29CF61FA0EB2E28DULL, 0x83B456C917F677D2ULL, 0x3357B19F59914A3CULL, 0x52F26D0D3F1E1E12ULL, 
            0x684E9CD3890E0FEEULL, 0xFF5ECCF1B87AE5BAULL, 0x483E43E2C573FBA4ULL, 0xBA40141C35B52CCDULL, 
            0x91158C564425B973ULL, 0x9F5C246FC938496FULL, 0x84684564839C06BBULL, 0x5E1597E29B8CE32AULL, 
            0x3E5422DCF7EACC78ULL, 0x1FB200150E169071ULL, 0x93B53FDAB01026F7ULL, 0x92B90EF044F0039AULL, 
            0xF754080BC4405C98ULL, 0xE59D624EA8DFA00FULL, 0x974D9DBA8D899343ULL, 0x0D6606B309B34603ULL, 
            0x6A641445B3542A33ULL, 0xF76F646348C07F30ULL, 0xA248FE281282DB66ULL, 0x8DCA6719B5649B05ULL, 
            0x56E6538ED1087C97ULL, 0x55C3F6A062C7C01FULL, 0x1AF59182516D169AULL, 0xE5750B9E603BDF5CULL
        },
        {
            0x0BABC439522A841CULL, 0x63521F4DDB1FA449ULL, 0xEC422CC964DC5CADULL, 0xDFA2904774CFD1B0ULL, 
            0xB2CD0539659AEEBAULL, 0x5483CD1BFC2562BFULL, 0xB2187B63F4396AA4ULL, 0xECF89046FDD1B014ULL, 
            0xCAB57C0C522AC5ABULL, 0x38C9F1C08C237CC7ULL, 0xE8EEF5DBAEE46D5BULL, 0x594D74926B398953ULL, 
            0x046638484E5D1280ULL, 0xC7F223223F855ED1ULL, 0x7BCE1E20FEF39FCDULL, 0xB65C3CBEC0F0A120ULL, 
            0xD60B3F546A138A2FULL, 0xA4210A02876BC6D8ULL, 0x386B378A8866825DULL, 0x3FF6CE3D93FFCE9BULL, 
            0xA0A0702221EE71E5ULL, 0xCF6AA0F3F333E39DULL, 0xEDB0D7F6451BE766ULL, 0x044F67D8F0613227ULL, 
            0xCC037A29D372FC39ULL, 0x3D34333ACF062B87ULL, 0xAF0F0411C8738D93ULL, 0x4D8072982D012923ULL, 
            0xA9DAA66EA9FE706DULL, 0x2EFB66422AD72FFEULL, 0x2AC3CD450EFC9137ULL, 0xD0EA1C2B711DFA2FULL
        },
        {
            0x41F44B06C3322394ULL, 0x82D6D8F342EF6EACULL, 0x0E5C6A2D73DA260EULL, 0x86329B642F475663ULL, 
            0xB8BEAEF99D7AA558ULL, 0x1DDB5EC5FF4D52CAULL, 0x27A86E20A955F2DAULL, 0x058B7DEBFFADE368ULL, 
            0x13C4410D3A8AC4CBULL, 0xE6A5A94BC80E93AFULL, 0xD47CCAE88B9EFAACULL, 0xA2A5B4788AFA0542ULL, 
            0xAD2231BAE8B61BFAULL, 0x83064E188FC6AED8ULL, 0x75D2DB9EE0B34D29ULL, 0x140769126FF5DE11ULL, 
            0x6462DC2389EFDA51ULL, 0xD9D8CD8E7412BBD0ULL, 0x979FF93F940885AAULL, 0x5632F472769394EFULL, 
            0xEC71F6E9B2DCEEEBULL, 0x6EB956C892E29D69ULL, 0x2A101939733E2B2FULL, 0xB3543BBC9B7B39CBULL, 
            0x01231CEECADE9C7EULL, 0xBFA7FC428767AE77ULL, 0xB7B9B2EA911D8FFAULL, 0xC4A5001275A9D388ULL, 
            0x64298BFD2AEE6355ULL, 0x563771AAB560863FULL, 0xAF590964A50B7E92ULL, 0xF11ADE632EE48FA8ULL
        },
        {
            0x08D9DD17F37E3E4EULL, 0x4E5F410C8CD01C1CULL, 0x3D21BE3504819F0BULL, 0x1DB5818CF5E8282AULL, 
            0xBFA50B9A22EC0C8CULL, 0x5BDB7BC3170D31CFULL, 0xB6BEE70CF4261680ULL, 0x53468F16C4F7071FULL, 
            0xECD0DF7093BF6E90ULL, 0x218CDB233E3F5417ULL, 0xC7523814ED8EFC2FULL, 0x6F916E68C1F5D89BULL, 
            0x0914A0F02028E510ULL, 0xE040E03285386A7EULL, 0x234C4682181CB84EULL, 0xDB080FAC7310EEC3ULL, 
            0x7B94D5DD0981E59FULL, 0xDEDF1B6DD7A6E33BULL, 0x33EEB832CD073287ULL, 0x68B0021F03A2CC16ULL, 
            0x69812771F673BF83ULL, 0x958E398AE6C932FDULL, 0xD33F2A24B556E76CULL, 0x104F68BEE35912EDULL, 
            0x437F5059A9769D5AULL, 0x23CDCFB0B13000E5ULL, 0xC51939A75732E41FULL, 0x2D205EF0BC15C863ULL, 
            0x7E5242A373B3B7C8ULL, 0x6EE8B1ABFE12638BULL, 0xCD2F8AD72A3E60BCULL, 0x4897E5E103430A01ULL
        },
        {
            0x89FF41F0587718F4ULL, 0xBE99E6CBCCA44DCCULL, 0xE72A687D513175E7ULL, 0x7AAE6289968877D7ULL, 
            0xB2EF91FD93C51D6EULL, 0xED75E438A22C87A8ULL, 0xF195E7094762A129ULL, 0x0305E7AAA85EF912ULL, 
            0x945355A3D540B071ULL, 0xBEF641A857A553CAULL, 0x3601306885CBD672ULL, 0x5FAAF969B703FCC0ULL, 
            0xB9B6ACCDC5937929ULL, 0x3AD47EF014A25A6EULL, 0xED0236A43F2E1564ULL, 0x5BAEC4C3A6CCC242ULL, 
            0x498304DF899A5FE2ULL, 0xF05AE0390EBABDEAULL, 0x872E063C9871ECF7ULL, 0xE5ACB34B85633639ULL, 
            0xC721826EBF0EDE7CULL, 0x6F4CF83C2D306DBFULL, 0x2680F502F33680F0ULL, 0x7E6AFB3C6CCDBA49ULL, 
            0x72AC49D26F246744ULL, 0x4DB75EFFC9633C3CULL, 0xF4E1083371570446ULL, 0xA09993114536C7BDULL, 
            0x6E06B6D42A59B7B5ULL, 0xC8B150033EDA223CULL, 0xCCDF6A19FD888FE9ULL, 0x218EBD382F822F44ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseAConstants = {
    0x88E3E9BD202E37E4ULL,
    0x6954BC6D8EF5028BULL,
    0x61CD7D15500E5B59ULL,
    0x88E3E9BD202E37E4ULL,
    0x6954BC6D8EF5028BULL,
    0x61CD7D15500E5B59ULL,
    0x7F669621DD8A6F50ULL,
    0x8DB06DCA0635BA54ULL,
    0x3B,
    0x8E,
    0x7C,
    0x75,
    0x3B,
    0xE8,
    0xB9,
    0xEC
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseBSalts = {
    {
        {
            0xBCCF613247852204ULL, 0x27B41ECAAD1A045AULL, 0xA37F3639DED8147EULL, 0x0539B45CEAD4F4B2ULL, 
            0xF153B08BB4702642ULL, 0x9DDB02B15BF1BFE9ULL, 0xC3D6A358E8820709ULL, 0xD39456FEBD73BB5EULL, 
            0xF5D95A6D973ACC10ULL, 0x82C6B780D3BD6B36ULL, 0x76CE874618A501C8ULL, 0xA7D3B12E48CF9E75ULL, 
            0x61B2764FF56B0D97ULL, 0xE5033ACDB0CA6DFAULL, 0x39F8C7ACF0B04C62ULL, 0x50E7538DD4034756ULL, 
            0x1EAAE203186E8BD3ULL, 0x488A055524C57C43ULL, 0x7DD9B6465221F120ULL, 0xA1406F33C4DB0B2FULL, 
            0x7C4A5CC79A71F073ULL, 0x8A657130C8D77354ULL, 0x4BB04D8FEACB32BFULL, 0x30D194644CF69291ULL, 
            0xBB062D4974E14D02ULL, 0x63F6F3147C7ABEA1ULL, 0xDE20E0B41AB2A66DULL, 0x0B5DC54AA68D02C2ULL, 
            0x4EA197E96617D574ULL, 0x2D9C7475FF85BB8DULL, 0x72FF002FDE838C4BULL, 0xCC4A43F45C756C15ULL
        },
        {
            0x0EEA5A551CF4EE67ULL, 0x5A84603CBF7EDE8BULL, 0x75F424CA508010DAULL, 0xF9729AABBFCA5F28ULL, 
            0x9CB2015EB35ED0D9ULL, 0xD6BB090B7CCD3AABULL, 0x82EDA1BF61B21429ULL, 0xD979E1B56677B552ULL, 
            0xB88B9AAA9A5465B9ULL, 0x32AF682D424C464FULL, 0x253C44AB398913AFULL, 0xEF6D4CBA4271F0A0ULL, 
            0x627FAE9064828B81ULL, 0x8D013520C5B031C9ULL, 0x6B5A27EFB2E6A9FDULL, 0xEF1EEEE5C5D549EFULL, 
            0x6D0A797219FB9458ULL, 0xD4351FFDDA7C4454ULL, 0xA402B17BBB267095ULL, 0x23D95E7F7AB9D8B8ULL, 
            0x8591391D4891723EULL, 0x6E394C805130F11AULL, 0x86834D57D7F5A4C1ULL, 0xC945EBFB78361893ULL, 
            0x814357B8A06F5B00ULL, 0xB5B1E2091DA329A7ULL, 0xD1FE076EF9294994ULL, 0x9E2CB15FEE92F90CULL, 
            0x5035F2DCC8F160A5ULL, 0x2BDAD4481D8F10FDULL, 0xD9ABD7808777F655ULL, 0xF6AABBDF46788CDBULL
        },
        {
            0x043123F86CF54A02ULL, 0x6526A79F0B28E261ULL, 0x5683B2C5A36957C3ULL, 0x037005453952BA14ULL, 
            0xE2F00D7EBEB9B2CEULL, 0x22B110FF804F2311ULL, 0xBDCCE7657981F55BULL, 0xA6995085E53ECED2ULL, 
            0x170C8579B0F41ADAULL, 0x247E171D854DCBD2ULL, 0xEA5175F106BBFCA0ULL, 0x97D129B7A400DE15ULL, 
            0x65783F63A6D843F7ULL, 0x93468916F6A87EBFULL, 0x1D8DD2A8824A5D4FULL, 0x9760F912731440F1ULL, 
            0x08B049E8532E45B2ULL, 0xDD10B0E2E06E7C22ULL, 0x2528F00F6964344EULL, 0x172D964B0B8E2E8FULL, 
            0xB73F5B1168174521ULL, 0xC728F4F7C616A5F0ULL, 0x951F47607BA9A581ULL, 0xE99D4FA8EBA025ADULL, 
            0xE39FDCD42F5F5E44ULL, 0x72FB14FD7C61DEC8ULL, 0xFE59F4610ED592F7ULL, 0xCD4820D57C62ED9BULL, 
            0x6A49EC90F441BC24ULL, 0xE33FCACB3B66A0E1ULL, 0xE56F167B538AE148ULL, 0x1E76886B7BBA5F9DULL
        },
        {
            0x1091D65090D887C2ULL, 0x317851DB7A974239ULL, 0x4D3BD5C761039C84ULL, 0xEC0431B307AA3F71ULL, 
            0x857EFE7CB1A017D1ULL, 0x4925A310617C297CULL, 0xB894663B41C01C4BULL, 0xB8CFE50FABBDABB0ULL, 
            0x2FCF57CD67794E05ULL, 0xFDE4A41074DFED8DULL, 0x5A31CFB9A3118DBFULL, 0xA884BFD0C100E879ULL, 
            0xAAEA65679DFFA7E7ULL, 0x1B2DE1329DD52148ULL, 0xFFB80531AC9B631AULL, 0xA8972B6561968643ULL, 
            0xDF6F5349D6C8ABADULL, 0x60CAF0E718BD2F91ULL, 0xF447ADE9DBB3882FULL, 0x4C306148B3078F8BULL, 
            0xF0338AC937E3C3BFULL, 0x51C00969F2305B99ULL, 0xB2FA651A0B89E356ULL, 0xE875E6B6129C8878ULL, 
            0xBC150F90F299CF81ULL, 0xDEAC5ADFB56486A1ULL, 0xC0049199FE8AA4AAULL, 0x670A5E4E00242F90ULL, 
            0x81A785C78449393CULL, 0x557C620B8D591061ULL, 0xD1B072485EB6DA01ULL, 0x4CF6CF07421717EEULL
        },
        {
            0x1DC50F4990C51FB2ULL, 0x44D350B853C7FF64ULL, 0x305216ABC81C7E01ULL, 0xC51E4570EBE4FC2DULL, 
            0xE91C2DC5E9143F4EULL, 0xF9CB89C6FB25B245ULL, 0xD152CC0B34E3D179ULL, 0x73BB07D962561AC1ULL, 
            0x30B6D67B0A952EE7ULL, 0x455F0BEEB6DC5E0DULL, 0xFB2CD9707432D909ULL, 0xF0DC197DABE4246CULL, 
            0xE5203CA3580BF160ULL, 0x1B6DD8DB889B51CBULL, 0xDC77712A1A11F2D2ULL, 0xC923A03CEF01EB1FULL, 
            0x9E9CD702646D0797ULL, 0x4ED4573E5E0AF852ULL, 0x6196DEEE6C188F3EULL, 0xA9E133850D83F6C2ULL, 
            0xFB217DCC461F7FBDULL, 0xA8E0B05BAABC2B7AULL, 0x28F313505B83132FULL, 0x2C51E27347D590DDULL, 
            0x33006A77E90B7C57ULL, 0xBB712AFF2B0B94BEULL, 0x020971E702B5C919ULL, 0xA7369672B54A2401ULL, 
            0x019386268C669B68ULL, 0xC0A46253C699D6FEULL, 0xCA5100881F368BE4ULL, 0x9CA2B6DAF97827C2ULL
        },
        {
            0x5604FA3E910C9D67ULL, 0x08BD740F23227D2BULL, 0xDEBF65CB4868F406ULL, 0xEFD7375EBC6C6248ULL, 
            0xFEBA56C4EB94182BULL, 0xA5B9DDFBEA64E2BEULL, 0xA3477E2A02822A23ULL, 0xD48FE6F40B911A48ULL, 
            0x74E5047A5B890F16ULL, 0x7A4E6BDCBCEAC8C9ULL, 0x39E89EEACF745815ULL, 0x5C3425563074BF04ULL, 
            0xA002B5BB175C82ACULL, 0x4769489F61D2BEF5ULL, 0x928AF5B9CA518456ULL, 0x991B2E13476DB942ULL, 
            0x3688698A0545CCE0ULL, 0xDD83D1B85CB97360ULL, 0x9DCC89B20CAA91EEULL, 0x38494E80DC19FDCFULL, 
            0x2737F33ADA6DF28CULL, 0xB9C0F05CA3DC6BA6ULL, 0xF0FC026B18794145ULL, 0x519A013F7AB90386ULL, 
            0x48180FB0D84E8B74ULL, 0x26CF766F6A5B7527ULL, 0xCA5F00DC548BE001ULL, 0x3CF97903065769DDULL, 
            0xD843EA7A6771C1C4ULL, 0x1137393F4F1D23BCULL, 0x6683F6BD6519E1EFULL, 0x15F3F8E6D7D2DA63ULL
        }
    },
    {
        {
            0xFCFD252F8EACF172ULL, 0x6BA0A793143F8B99ULL, 0xE96AFB3DFEADF0FAULL, 0xC4BAD802993EDF5BULL, 
            0x541440803955BC9CULL, 0xED8D6A23B5C28F50ULL, 0x0F0318DA04DFC06EULL, 0x54A7B0B130298505ULL, 
            0xF24AF29667F1DDC4ULL, 0x3F25A023B724509BULL, 0xE4A267028D8EDBFEULL, 0x1711832E9050C850ULL, 
            0xC8A7A8EA220C2D3BULL, 0x01C918078112B250ULL, 0x4AAD9F20C7FF6D91ULL, 0x6F7B245BFA67A683ULL, 
            0x7EEE4099C99AEE4FULL, 0x629921AE7AFBE230ULL, 0x269104CDADCCC1EDULL, 0xF793185640E3CAE4ULL, 
            0xF98CC31317216EDAULL, 0xB746C3389577B0DEULL, 0xAB281D3D21E32333ULL, 0x1E176B186BDC363CULL, 
            0xF81F172D30CD5687ULL, 0x8FF784EE47970857ULL, 0xFB5BAE8AB2428732ULL, 0x5B850C4AE6FA41A4ULL, 
            0xC3A3DB5434E4DE85ULL, 0xF7CE6145B380BD24ULL, 0x39FEAE0C7BEA092EULL, 0xC51BD38AEBEF11BEULL
        },
        {
            0xBD40F50956118B2AULL, 0x826B91B675DE1D05ULL, 0x4B372AC618D306BBULL, 0x0BA203DB5EA791F5ULL, 
            0xB01DCD9D7BEB5202ULL, 0x99C44E55D4B3431BULL, 0x5CD9B337A784E287ULL, 0x75B771C7EC2C8E0FULL, 
            0xCBD0B86EAF8C23E9ULL, 0x5BFAA52B1BBD282FULL, 0x78E228671045D8E1ULL, 0x983CE022F86BBB28ULL, 
            0xCDD230F7791EEF55ULL, 0x69A661B8FDE108A6ULL, 0x7EBAA4D944867DD5ULL, 0x2D31579275ED0F83ULL, 
            0xA0B9BD81F9196E3AULL, 0x51870B5108C60497ULL, 0x9C0BA2B3262CB1E7ULL, 0x3A4AA41BA3138C19ULL, 
            0x927C18B4D9269316ULL, 0xFDCA728EF9AD3258ULL, 0x2DE87530428E37D9ULL, 0xEF8163C04A63D530ULL, 
            0x1D70C973634E7555ULL, 0xB36A187BD367F0B3ULL, 0xCF629A48E1AEE080ULL, 0x254D03D8ADC0588FULL, 
            0x5E2DD221C8672AA1ULL, 0xEE60D5852907345FULL, 0xA86AED3BB705E2F8ULL, 0xD421A7491FB9D6A6ULL
        },
        {
            0xA7B8729E511851FFULL, 0x5507E4FF44281620ULL, 0xDF3E88E23D171990ULL, 0xB050B9A6253E634AULL, 
            0x71EA84BCD0C7F11FULL, 0xDFF0DAC424EDA06FULL, 0xE4D460EA7D5848F4ULL, 0x285B0D1DF3584E6BULL, 
            0x9448DC8D895F2FABULL, 0xCA0CF3CA9181881DULL, 0x1ED44957D5F23F02ULL, 0x7AF1EE7091230604ULL, 
            0xB8C16AC3B424314AULL, 0x3EF4F5EBBD627F4EULL, 0x4E7531C8801E4D51ULL, 0xD1F682613F283D50ULL, 
            0x99FF097A3A413133ULL, 0x9C55DE8B68BCD285ULL, 0x3C0ADB782609958DULL, 0xCBA61C9AD40A0905ULL, 
            0x0FEB63A85BFC7844ULL, 0xB0BD900FA59A2829ULL, 0x025B2A499D4986C4ULL, 0x717E864BEA1F68A7ULL, 
            0x5994314F3DABEBD8ULL, 0x6D4727EAC316A701ULL, 0x8921532D7B63B364ULL, 0xBE75EAA9D5E75636ULL, 
            0x8E744A9F8A3EA14AULL, 0x54DFD542E438E272ULL, 0xBC59697FCA067024ULL, 0x38C5B3D96058D826ULL
        },
        {
            0x0BDF73BD73966B67ULL, 0xF98E18436AD49D00ULL, 0x75FA34C7B8E9A515ULL, 0x07326C3FB0BCCBD7ULL, 
            0xB1902BF11727DC3CULL, 0x4CB8F762FDC5919BULL, 0xED489129858F4492ULL, 0x05E25AEDDC65BB91ULL, 
            0xD694FB7B68B52E71ULL, 0x5788136FDA523BE9ULL, 0x855F40CACDD160B4ULL, 0x9C938A4F63B035A8ULL, 
            0xFFEDA0B5A5E8864FULL, 0x2E54344E8C27E6F3ULL, 0xDC3FC9A5520FD0C5ULL, 0x621A006746EDD8F6ULL, 
            0x328647CBCFF62594ULL, 0xB9F18A495C567D98ULL, 0x736F4EECA7082C0DULL, 0xA46CA9E51763245BULL, 
            0x15534315A9B69496ULL, 0xA98DD55723AF07C0ULL, 0x8EA988ED1F007CFAULL, 0x501EF189632502FEULL, 
            0xD1775A050C66D362ULL, 0x8978270F60D44434ULL, 0x5AACE84FF65342BFULL, 0x706F85D9A7996F83ULL, 
            0xC96586CAB569EED4ULL, 0x3560B0E0F8F30B3BULL, 0x8946C27669A3A9CBULL, 0xA236CB89DBD0D21FULL
        },
        {
            0xBB64C17941DC2284ULL, 0xB5008A95BE093C92ULL, 0xB669C6486B455219ULL, 0xCEA4D3978BAD58F6ULL, 
            0xDEFA9559DB62AFB0ULL, 0x4FC6EC47FD9B1BA5ULL, 0x5497E784B5F35FA8ULL, 0xDCB34AB1744C15F2ULL, 
            0x2D519899D4670134ULL, 0x8057B032E68E37DDULL, 0xAF36C3B44A8FBCE4ULL, 0xBE30A3C6AB0DC408ULL, 
            0xE4AEF25C9E74B698ULL, 0x5C4DF7A3C0FAB7FAULL, 0x2A0102D0760DD58CULL, 0xA3E75C9640721797ULL, 
            0xE17A77C151FABFF3ULL, 0xCB292F24F5630821ULL, 0x9917EFBCDA477538ULL, 0xC739F1BD372BE594ULL, 
            0xEEEC74468F9E0DF2ULL, 0x515ABF2FC76D93D8ULL, 0x2BF7393471AE1A69ULL, 0x7C07F0CD2AC35334ULL, 
            0x1919EE4F0CC16CB6ULL, 0x0CC4D35A7916FD3DULL, 0x56AB6DB912E3E480ULL, 0x202F69C3B0FAD691ULL, 
            0x2C90753A13F560D8ULL, 0x57E43B9DF7A619B9ULL, 0x251064A0627A6823ULL, 0x650FEEE9E827943DULL
        },
        {
            0xB955C9E352BA6BFBULL, 0xEB38C9893F887045ULL, 0x87431ECEB9D174EFULL, 0xEBA57632BFF4166DULL, 
            0xEE1041E3674F996AULL, 0xF8940DC819BE9E2AULL, 0x5693239A289A28F2ULL, 0x707E34C8AB06A76DULL, 
            0x3F92214B414DE10BULL, 0x9F1EDC3C436F4766ULL, 0xC90C1B6F52AA4890ULL, 0x098AF92CBDA4C8AAULL, 
            0x98B36AE4890E045FULL, 0x192F14769B42DBB5ULL, 0x67181DC7FC28C1AAULL, 0xB981E7AF054BB37BULL, 
            0x8EF786E696E3119FULL, 0xB708863D8C0238A3ULL, 0xD451A85766D99AD3ULL, 0x73984DB324482215ULL, 
            0x772BAD1AAD71AD89ULL, 0xEA3EABC363219A84ULL, 0x3EC716E01DB8AA92ULL, 0x595CEAF683EBBC15ULL, 
            0x9627E22AD40D0F5EULL, 0x58D3CAD4806EE6C7ULL, 0xCEACE3CFCE503210ULL, 0x5800846F5F7643A4ULL, 
            0x013FF462DBEEF11FULL, 0x36E46D038E4C4A33ULL, 0x32C965746FD05E1BULL, 0x72194C90186CC5F4ULL
        }
    },
    {
        {
            0x2AFF7842877C4CB7ULL, 0x1CCC524804CCC4A2ULL, 0xA47EC878503EF4B4ULL, 0x1B0E7EB42517F636ULL, 
            0x57C25565B4B08C60ULL, 0x78915D3F666E1F74ULL, 0xE96B8455FA7A9070ULL, 0xF7E91B4D3FF7CA18ULL, 
            0xC454E82E9C769A34ULL, 0x9148BD3B73E6B767ULL, 0x35BDC7F9541F9E28ULL, 0xF106AEF074CEB1DFULL, 
            0x20C8EF8F3DC87645ULL, 0xDA7CD8234A7DE402ULL, 0x168C2D42BEC6F8C2ULL, 0xA527C37B4A2F35A9ULL, 
            0xD86C9AC7FC794ABBULL, 0xF7590F1856F48640ULL, 0xB9726E2BDBFEC2B4ULL, 0x48EAD6764CE7F330ULL, 
            0xDA84D19FDC7D20BAULL, 0xA504C944E8EC87FEULL, 0x061F42F92E9EE3FDULL, 0x7CCFD7E9D638B69EULL, 
            0x53DE0593900DD79EULL, 0x7D5591FEE456A5A6ULL, 0x0AF2239A10F4EC05ULL, 0xFB31A2E531F3BCCDULL, 
            0xCD17FF71390C5B00ULL, 0x53B728229E821C5CULL, 0xB854DB11C9A24933ULL, 0x5737FA502DF83EA6ULL
        },
        {
            0x733B4F24D8BD3E97ULL, 0xFBB291C49C914D53ULL, 0x6B5D53E2A9C08CBAULL, 0x1F84E9DE92532B76ULL, 
            0x7AEC5D7EDF189B0BULL, 0xAD279BCFAA4C70D5ULL, 0x29D2E6DDF3ACC95FULL, 0xEA9A11BC6065EC31ULL, 
            0x6D8ED9EC1BE06E90ULL, 0xF54E8A73B624783DULL, 0x880880975A6D6637ULL, 0xBEC7DFF861F8489AULL, 
            0x0C50B29EA4F09821ULL, 0xBED25FD04AABCE0CULL, 0x704603597BEF5ABCULL, 0x837699DF4A9FC03CULL, 
            0xE56EA1867E3B58D7ULL, 0x545FE7E07124899EULL, 0xF8E0877F7499691DULL, 0xE02A2D6B87C0EA5AULL, 
            0x70AAC39379733AAEULL, 0x794AF53F17486312ULL, 0x299F7BFDE089ADDBULL, 0xA4F8B49171C79EEDULL, 
            0x2AC6AD335D417777ULL, 0x5C85D09C516076E4ULL, 0x41C113261B357683ULL, 0x72175C1C4E1BFA83ULL, 
            0xB23B59ED4148ADF3ULL, 0x2B0EFBF9642610FBULL, 0xEB10F0899B845DD3ULL, 0xA7FA72CFA09F6C0BULL
        },
        {
            0x652BD590770655F6ULL, 0x38DC07AAFB30B170ULL, 0xF2CCEE0A024201ABULL, 0xA65A528F5E562B3DULL, 
            0xB003555C819EA268ULL, 0x02EDD9C87B2EFA24ULL, 0xB8088AF528BBE0DDULL, 0x25275A3B2B9C4F59ULL, 
            0xA292C92188991E7CULL, 0x10C56BF3C37F6A5AULL, 0xF7EC7876EF15CE5BULL, 0x8523CC99325CED24ULL, 
            0x09434ADDE6E8EB43ULL, 0x44D5FE1CD023BA47ULL, 0xB9080E55AEBC088BULL, 0x0298BD64F406B9AEULL, 
            0x351F162194ABA5B3ULL, 0x2BD7CD4B219E6792ULL, 0x08088ABE7D7027AFULL, 0xDDD19B1D5A9F5DA7ULL, 
            0xCA0735FC838CACF2ULL, 0xA6C8290F07533615ULL, 0x73B862FE9EAB9C06ULL, 0x39011BACBFB5C606ULL, 
            0xC4FDAED76FBED7F0ULL, 0x731BD6B7054BC899ULL, 0x1E2724FF0EE65BE0ULL, 0x5D55237EEBE63BD4ULL, 
            0xB57D0A24C5368914ULL, 0x27E92D786A32EF3BULL, 0xCF6E7521832CA20FULL, 0xA2C0AD710601A2A2ULL
        },
        {
            0x281D0D6D6560A800ULL, 0x19F24781FAC839A7ULL, 0xBAFD17A4A24CD69CULL, 0x634C36DEF846CCF4ULL, 
            0x3EA8DF0C6F4F5A10ULL, 0x197FD6F3B8FD732DULL, 0xA02EB8ADD545027FULL, 0xFACFB42CFFA6459EULL, 
            0x3C855673DD059198ULL, 0x30B88D673E44B289ULL, 0x9B3DD495A67E69FDULL, 0x71FB0401B306978DULL, 
            0x123CC6BEB2D7F86AULL, 0x747CC034DC5E5034ULL, 0xBB7AE388D141A81EULL, 0xC83A154147BEBAE3ULL, 
            0x91CF7050011A350EULL, 0x36D14344345B260FULL, 0xDCB2A662346F805DULL, 0x8F8A98B3B1E0C25BULL, 
            0x82890DA412250856ULL, 0xB2F1360EB4FDBB8EULL, 0x25D2C32294464890ULL, 0x41DDAFD1C16AD83BULL, 
            0x771E52E8FFEB4F88ULL, 0x02C8F5CEB79EC2CFULL, 0xC4CCE5B25D57A7CDULL, 0x78B574F5DC48D471ULL, 
            0x5A74943D747F46A2ULL, 0x3BDA1D19BB517198ULL, 0xAC75DD72FFEAAFB4ULL, 0xD8D15A4AC6B6A6C1ULL
        },
        {
            0x9DE7334E86410AE8ULL, 0x7767AC34A4E59210ULL, 0x46BBACBC0E1DAE0EULL, 0x288FAF20BA6D500FULL, 
            0x8926EE41AD737BE5ULL, 0x7C83A0011B2FEC6EULL, 0x9DA8F4C2D873E3E7ULL, 0x68D3678BC7BC929BULL, 
            0xE31388DF638D1ED5ULL, 0x8127E0750B7CBCACULL, 0x52352607265E4AB0ULL, 0x3B8DBED71A8A328FULL, 
            0x7BE70AA4DF035221ULL, 0x624D646431C466D7ULL, 0xDEF621901E9940ACULL, 0x48A6088A6B4F07E5ULL, 
            0xAADA1EBF685483D8ULL, 0x759B378F7F9E06FAULL, 0xC52E846E800E0122ULL, 0xF0019CF4B56028F2ULL, 
            0xD05814556220CF90ULL, 0xA07B98B1533322D8ULL, 0x73EFD136C5A02CD0ULL, 0xC45430A008BE408EULL, 
            0x302E62E08180BBFEULL, 0xA8610E78CA87D0CFULL, 0xC026713B9E717BA9ULL, 0x10AF752D65953B23ULL, 
            0x434755E05B71FDF3ULL, 0xBEBF729FB6D60CC1ULL, 0x29A4474E4A1F5BFDULL, 0x24C9085312DA4E33ULL
        },
        {
            0x5E087D23039C9455ULL, 0xD3BFEAB2F58C6B17ULL, 0x945FC895FA8A972DULL, 0x943232F91578669FULL, 
            0xEFBEE02CC1F9FE43ULL, 0x0054EEC299613297ULL, 0x3066198AAF9646CDULL, 0x6FDD4A646F2432E5ULL, 
            0xC4C745F96C3770ECULL, 0xD3E5095825CB1D57ULL, 0x164FDF4936A747D2ULL, 0x226142874573F78EULL, 
            0x309572363E51BF58ULL, 0x603F4B11E2428F02ULL, 0xD7BA3F50204C1550ULL, 0xD9835C21697E70A6ULL, 
            0x00C4A5B09B10A586ULL, 0xA99EB63612668A87ULL, 0xE1C25EC19790CF43ULL, 0x5A6F62E31BDC87E4ULL, 
            0x3299AC50AA0489EFULL, 0x073826797AC295CDULL, 0x93DB6BE667ECE32CULL, 0xAD8FA2452FB8D7C8ULL, 
            0x21367611A21F1AFDULL, 0xDB0B0B05B0A6A3D1ULL, 0x864776615EC59B3BULL, 0xA33ABB106EDCCBBAULL, 
            0x4F9BC037389DFA9AULL, 0x5323E480FD7582B8ULL, 0x5153BF99A2A5D6C5ULL, 0x0A7388079950F119ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseBConstants = {
    0xCC08A32B5CAA8889ULL,
    0x89820C7FE6214E6AULL,
    0x727E2B6121038675ULL,
    0xCC08A32B5CAA8889ULL,
    0x89820C7FE6214E6AULL,
    0x727E2B6121038675ULL,
    0x348B1508672FA464ULL,
    0xE348F757953C3A01ULL,
    0xB4,
    0xEE,
    0xD5,
    0x87,
    0xF1,
    0x08,
    0x4D,
    0xD3
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseCSalts = {
    {
        {
            0xE1734EA33D565329ULL, 0xEA94514A907640FDULL, 0x6BA4405B557EF685ULL, 0xDF4F8C2055EA5DE4ULL, 
            0xD6897EC18BF41E1BULL, 0x6C177B91C503D43FULL, 0x285101C6850F3CC8ULL, 0x3050E73EEA5AEA91ULL, 
            0x0D9F4ED6B6ECCDE5ULL, 0x4249D2A71E0361B4ULL, 0x402062817253AE46ULL, 0x6500B302B48483CBULL, 
            0x3D44BEED9DC1204EULL, 0x7E15125DB7F1A939ULL, 0xCC438D057154EA1AULL, 0xE46D500F158DA3B4ULL, 
            0x7D22FC09FE828156ULL, 0xE79E22B26B7744C3ULL, 0xF8D440AFF4CDFAFEULL, 0x2C2225A995193F3FULL, 
            0x29264E27D8621227ULL, 0x073C8E3245B267A4ULL, 0x056D862B9D799853ULL, 0xF112830671D4996DULL, 
            0x030DB81AD90CAB55ULL, 0x6A0E193EC1A3ACE8ULL, 0xF07242FB661AE577ULL, 0x6280A26CB3BD45DCULL, 
            0xC20470604AA42F98ULL, 0x01D8F073C62FEBC0ULL, 0xB24D845445A909E4ULL, 0x32451BFFEBF78650ULL
        },
        {
            0x2D27CE4372ACC39DULL, 0xDA0B4E1A453A0C2BULL, 0x32A530A86298F16BULL, 0x8EFF0041C157F5C6ULL, 
            0x71725F2F76BC116BULL, 0x833BE7C06E4DC23BULL, 0xD468A8BBFDA55949ULL, 0x41032DF1B765D7FBULL, 
            0xF7E6134879434366ULL, 0x60929440E4624F35ULL, 0xCDCA3903BC82D6EEULL, 0x68D94A4D4AD3CDE6ULL, 
            0x75DB42D032B87AF0ULL, 0xD26B83724FD69AF4ULL, 0xE34B3CD4A5A54CDFULL, 0x907931F32A932983ULL, 
            0xB12A60D7618C482CULL, 0x608B73CC298194BCULL, 0x0B4D4CD62A93923EULL, 0x0046CD30B5466878ULL, 
            0xDE50098C15B392C1ULL, 0x28B39870A2D58341ULL, 0xCEA098EDDAA3E90EULL, 0xCA2D5AC443083D18ULL, 
            0xA2074AC2665CB5DAULL, 0x467ED47E0BF302DFULL, 0xEC3C8764268090D0ULL, 0xEEF910CDDEF75875ULL, 
            0xCAAF850CAB40B1BEULL, 0xB0A9E49036119843ULL, 0xA13DE59CD36499F2ULL, 0xF43A37C34F6CE838ULL
        },
        {
            0x0A8B0F93EB267698ULL, 0xDCD12A1638334699ULL, 0x2D441C8F2262AFA7ULL, 0x435CFB0E1388BE8CULL, 
            0x9B5685561493730FULL, 0xD84C77161D59492EULL, 0xD8020A6C4BA49AB2ULL, 0x169E20A3F1B9A697ULL, 
            0x0978B92DBC04A9A7ULL, 0xBF46949DAE9C294DULL, 0xD4C3BE7C563DDCB0ULL, 0xF163232F33ABD225ULL, 
            0x36060F519EDC113AULL, 0xF3E9B7DCE320F110ULL, 0x9B3F5E8871BD0DC0ULL, 0x3A754C766C8E9F72ULL, 
            0x8443F1F8DA382A6BULL, 0x24C6D119E6CAD53DULL, 0x92650FC1B7FF5898ULL, 0x24216F302870F991ULL, 
            0xD9BD5219E2788F9DULL, 0x45B8AAE2F4C2AE9AULL, 0x4D4DF6C9EBE922E6ULL, 0xDDD734E45305DBBBULL, 
            0x278D218DDF6ABBCEULL, 0x03372EDA4143BFB0ULL, 0x2341BD59B4CA3A38ULL, 0x8B5BDD85A84995FAULL, 
            0xE7318EC4691DB6B3ULL, 0xE921DB05D510412EULL, 0x99C89C0E434CD5A4ULL, 0x04CF2955FC520D01ULL
        },
        {
            0x9485F2697AF6B04CULL, 0xEF19DFA992A043A0ULL, 0xFBE317B135F10490ULL, 0x08C5ED3639C333C2ULL, 
            0xFBE5D731783C5E5AULL, 0xCE852946D31B3526ULL, 0xCAF66E8D04CBCEA8ULL, 0x01DC2D788C112500ULL, 
            0xAFD48F2318A6E35AULL, 0xF8CC9DE4AAC21EA6ULL, 0x5179FF1EB828EAF2ULL, 0xDF30BB4376BE796BULL, 
            0x407E3964933ABF67ULL, 0xDC696E66ED85A2F3ULL, 0x2EE3CCA18822F00AULL, 0x35625B5CCE4FDADCULL, 
            0x8C4DE6943A15C321ULL, 0x9884313E5D314745ULL, 0x62B58266B21DA29BULL, 0x7FB3F572A182030CULL, 
            0x5062B6D9A0D0AD99ULL, 0x5C5DE78F9CB6C303ULL, 0xF00A7617637E96B6ULL, 0xB84D8099E9082ABAULL, 
            0xAD475A506A4F0939ULL, 0xCC7D92E3940A5AD5ULL, 0x6962A6F998D3E1C8ULL, 0xB2047BABDF5F4B26ULL, 
            0x44A57BC4AE15D3C1ULL, 0x432F61A09BCFD30FULL, 0x73D698B50BE9C9A6ULL, 0xC36B41B2614003CAULL
        },
        {
            0xCC160F5B89786BD6ULL, 0xE33D05C357D804F1ULL, 0x8CC7B294BF0CC2C6ULL, 0xCF7D01EC3CD2EB4AULL, 
            0x9C3FE74599D0F7FFULL, 0x7687C7E0ECABD225ULL, 0xF506F2AF9DAE9087ULL, 0x395BA008EF6E3234ULL, 
            0xBA7619BBC692EC06ULL, 0x211F32980C89C435ULL, 0xE162807AADCC4A90ULL, 0xD7004AAC4A7C9CB0ULL, 
            0x06CAFCF8DF5C2013ULL, 0x3AB88D5C32CEF61BULL, 0xE6F1193AA61637E3ULL, 0x4AC058983404EC8EULL, 
            0x06F951C05439A21BULL, 0x9927A9A6A0EDF7AAULL, 0xC0BCA3F482484FC4ULL, 0xDDFB28C869B61554ULL, 
            0xECD85BE1FD8645DDULL, 0x184A82436936DB42ULL, 0x4A2E2FA3D27EDABDULL, 0x03B6ABD647DEE246ULL, 
            0x6F62FC0DFE6237ACULL, 0x25E5FD0C8C20CF9DULL, 0x95E4EDBEDA25F38CULL, 0xEDA80AFC50F21994ULL, 
            0x20ECB4B244BBF339ULL, 0x3B696C4F4CA2BC63ULL, 0x3043669412525645ULL, 0x6D5402B0534C3EC0ULL
        },
        {
            0xD0191B3BFF07A405ULL, 0xF0572E7E939A56ACULL, 0x15C85C587B4CD190ULL, 0xA60B52444E38D2AEULL, 
            0xA3A661CE548364E9ULL, 0xAC10ECF79119A9A9ULL, 0xFE5F178BABE14E68ULL, 0x11F3ADE9FDBCA62AULL, 
            0xE6FF507B8315FFE3ULL, 0x2DF8C3AED75D2473ULL, 0x0B9E6C53B7B8CE61ULL, 0x0C54B20679407D4BULL, 
            0xD86E9B38748BB2EBULL, 0x29279D56C190F842ULL, 0xC07423EB62D4B7F1ULL, 0x06902F2C3AD46BA9ULL, 
            0xFB2BC38893D2B1ECULL, 0x4685D0C6E43AE16EULL, 0x9EE0B726E863AB8EULL, 0x5E42F7D404797686ULL, 
            0x67E457C99AB1E425ULL, 0x9437B4714BD90AA0ULL, 0x8E4A8D5E3C496D69ULL, 0x79CA64612C9CF83AULL, 
            0xEECCA06A621F4FA5ULL, 0x1F4A20AC72640313ULL, 0xA1379DFE4979D61BULL, 0xD578FF333315792BULL, 
            0x12677D056FC89000ULL, 0xA399D8BF7BA98423ULL, 0x2553FADDB6209897ULL, 0x679212E511EEAFDAULL
        }
    },
    {
        {
            0xCFA75B92A42426C5ULL, 0xC1BEF84CF4DC174CULL, 0xEA388A71DB5D3514ULL, 0x4972BD3BB10D62B5ULL, 
            0x003089F1EB8F1909ULL, 0xEFE90A6F67F05C17ULL, 0x16A4629239778AB8ULL, 0x83DB2CDDAE3DBC56ULL, 
            0xF91EC4919589EA89ULL, 0xAC8C643723052A5BULL, 0x9DD922DF9314032AULL, 0x29E4932460EF2FDAULL, 
            0xE1A46EA57C7BC156ULL, 0xB641676A8A31A9C0ULL, 0x62408D9BE45179E5ULL, 0x0DA40FDDAF7B75E0ULL, 
            0xCFB77C77BC847230ULL, 0xE67844A3E52C845AULL, 0x9B191CE2BBCE8C6EULL, 0x0370985C0D5BE79BULL, 
            0x73DF5CCDACC3024CULL, 0x0710B4215D1AD286ULL, 0xB3AB1B21DA84B6E7ULL, 0x9254046127311E60ULL, 
            0xB2EA22ACE3DCE71EULL, 0x56D9B3267D4A8732ULL, 0xD1596A033B10C6AEULL, 0xD103549CC8775C20ULL, 
            0xD1F29405D3E2EE19ULL, 0x6AA61ADF638E906FULL, 0xBAEE1E9E9220F2FFULL, 0x774C38F801B2E4DFULL
        },
        {
            0x462C0048C624E880ULL, 0xA5C7AF2D4605F6E0ULL, 0x8E9B2B1C990D9537ULL, 0x7047189A3336145CULL, 
            0xF9DEB17E26493183ULL, 0xBC601C247B95ECF5ULL, 0x4901D24138B63088ULL, 0x0B03B180A991E6EAULL, 
            0x4B56DFCA1DC6CE8EULL, 0x5A2EF74308EA2564ULL, 0xE3BC247AB134DCF3ULL, 0x55DBF748540068A9ULL, 
            0x60C3E9A1A707121EULL, 0x7CC418E223841DF5ULL, 0xBA48D3BFEDCB416FULL, 0x8E45B5998631E6F2ULL, 
            0x1AED9E08B4E71D8DULL, 0xAD67C3A734C73DACULL, 0x2761992F25EDAC9EULL, 0x40F73CE9F6C86BBBULL, 
            0xDB6D97CB0E89BE46ULL, 0x4A2CFC3EF86D4996ULL, 0x56CD24B82F5ADFCAULL, 0xFE09B3B2859E4479ULL, 
            0x208EA36D67CD53ADULL, 0x48DAF13501DEBCA6ULL, 0x3DA774696499547CULL, 0x027EC37712DD7D02ULL, 
            0x6D816F7C795352DBULL, 0xCF9BAF6D97046BF7ULL, 0xA1180CA06E1E06DAULL, 0x87DFBCEB8FC3FD2FULL
        },
        {
            0xD7E3CFFC372ED338ULL, 0x97A3D4FDE5F28877ULL, 0xADFF49BBBF3577D7ULL, 0x5764BA8B4F8B9B54ULL, 
            0x91CE16C7819935B0ULL, 0xBE0DB783613C02C8ULL, 0xE842062E91F0E994ULL, 0xE77C0F7D3D3C8B95ULL, 
            0x373483F26067B725ULL, 0x6EC346D947536BFCULL, 0x3637E9D30E7A6C6BULL, 0x7843D3F6EC0433EDULL, 
            0x910D3658522BD2D8ULL, 0x51B89712BC3CD498ULL, 0xF7D4B50F899A72DDULL, 0x532C474F4D143E2DULL, 
            0x826847C67D17BFFFULL, 0xFF8BF4E65048DDDEULL, 0x8CB9528420FFED4AULL, 0xF12CDE4687073373ULL, 
            0x7633D1B3AD9C1BE1ULL, 0x03E238F0F6BB2435ULL, 0x1BD0CD7721C81ADAULL, 0xACA6BC0050568AF2ULL, 
            0xC805BA31850A5C88ULL, 0xA51AC8B1794D1D98ULL, 0x20F1F9B8E24DDFA2ULL, 0xDB524DEE114F92E5ULL, 
            0x76F1D5EE6C28062EULL, 0x9C8FE0223410ED59ULL, 0x5399E55687F95A8AULL, 0xE9DE3F9B55A99BAEULL
        },
        {
            0xF91422BFD184357AULL, 0x5C07BAB20E8328D9ULL, 0xE27D77BBFDD7704CULL, 0x85C0FB16A2ECDB28ULL, 
            0x94098F1D21013F37ULL, 0x4F32D06D887C0295ULL, 0x3FC27A67799AA45BULL, 0xF5C4AF785B612D13ULL, 
            0x9CE04FF8CD2436D6ULL, 0x1DBA26825A304CF4ULL, 0x0AB72FC67723D99BULL, 0x5D54D85882578508ULL, 
            0x3ED0FAE3D3102DEFULL, 0xAC5C567DC6F6FD7DULL, 0x2C260F04CDE8925FULL, 0x92CA2B2C1F01E196ULL, 
            0x0F1EF1DC7907DC32ULL, 0x0657252B17864E45ULL, 0xDABEF251EEF291DFULL, 0x166959C3B37F1F0EULL, 
            0xB150C8DE6531C864ULL, 0x502182483476BA7BULL, 0xD31E3D4A1712AE8AULL, 0x5517456A9B4D2B16ULL, 
            0xD76BAE7015C86BECULL, 0x8D3E29898E04587FULL, 0x79876EDA6F316457ULL, 0x4953FB71D2AF7DA9ULL, 
            0xC3475E8B47C580FAULL, 0x3611966B0D795223ULL, 0x31C76E54BD23F11CULL, 0x6BD853494F3FB2BDULL
        },
        {
            0x60179257ED569103ULL, 0xA3E87548596B3EC7ULL, 0xF70F9F8D2369B5F3ULL, 0xF069AA2FFA00961BULL, 
            0x226E67B6F1C343B1ULL, 0xB24BA95AF4A2A711ULL, 0x0A69DE301E919951ULL, 0x1AA90CADADB60C39ULL, 
            0xEF013F7F80C9CFA5ULL, 0x1E4E93EFD48C3A1CULL, 0x3468402F542D43CDULL, 0xE04E090A1D94DF9AULL, 
            0xB56116042B72E77CULL, 0x3280A7E079100817ULL, 0xB337B17C826B91EAULL, 0x4629EB20CB9AE14FULL, 
            0x7E418574DFFE3619ULL, 0xB5B30AF13B0B8910ULL, 0xA4B3EAE752480E47ULL, 0xD226BE66551AE357ULL, 
            0x0A2ACB619C391A63ULL, 0x97031405B2359ECBULL, 0xC88407BBCB8F7DE1ULL, 0x205EE0F7461B94A6ULL, 
            0x583F31DBBEB58B55ULL, 0x4B9B27E0FBEF74AEULL, 0x7B9A1DE9D4D67ABDULL, 0xF87514A0A5067A8AULL, 
            0x94BDD635DA84F4A6ULL, 0x339514D121C97A6DULL, 0x06ED4BD2F932B128ULL, 0x37FD0EAFE1CEA78DULL
        },
        {
            0x17FB66987AB4A8C0ULL, 0x4EE3D31A7EF8A45FULL, 0xA27B9B46D2E33714ULL, 0xC4F14DF8AEB32E8CULL, 
            0xA508517E257DF61DULL, 0x9D4EA7EC6F9B7A38ULL, 0xD01C62E34D67A31BULL, 0xCB3BA5781AAFC03DULL, 
            0x0DD587CFF3D68BA2ULL, 0x7A94F2B9A7D75835ULL, 0x7300731C34283669ULL, 0x0E0CAEADA7C0AF9FULL, 
            0xC0779C58678D608FULL, 0xFBFB671C76AD5220ULL, 0x334D80028C4D5EF6ULL, 0x5690E21B27970642ULL, 
            0x5504203F02344376ULL, 0x85269E4E334319D1ULL, 0xE51187492D9DD5DBULL, 0x6969DCAA7AB16CB9ULL, 
            0x38A3913AB8B311CCULL, 0x664C4C8B1B7F1093ULL, 0x07E47782BC07A684ULL, 0x85CAD8B3D2D433BAULL, 
            0x83D54121404A7CE2ULL, 0x1A828B9AAC1274B0ULL, 0xE7514D454D8BA077ULL, 0x3B603EDA6CC02CB8ULL, 
            0xB5EB522048D42E59ULL, 0xC1E1974492D6CBCEULL, 0x067865654F622267ULL, 0x89ADC6AA97F4298CULL
        }
    },
    {
        {
            0xB6E7346FCA91C3B6ULL, 0xE54DA76F4868CDB2ULL, 0x2995C52E08150BD2ULL, 0xD7E67A1EB1B2BA59ULL, 
            0x0003E5D0E7E6AFA8ULL, 0xA9BA304BD75C6BB6ULL, 0xD772F155DBE7DA6FULL, 0xBBB1D1BC4DECE816ULL, 
            0x6EF932057E737C46ULL, 0xD4794CD95E07069DULL, 0x6885EB44B8CAAD86ULL, 0x6A1EC3E12DE75706ULL, 
            0x43FA0626147EFAE4ULL, 0xED8D0386B63C4076ULL, 0xADF2E9DCAD9BFA44ULL, 0x1DAAC9E454013350ULL, 
            0x627DB02F9FD8F6B3ULL, 0x00A8BB6ACB82626DULL, 0x0D78E63FB681BD96ULL, 0x2EBC6D326B448FA0ULL, 
            0x32133A72D051C76BULL, 0x1B26956D0D1323A1ULL, 0x4A4D27F7BE2E9673ULL, 0x3AD61E6AEA2586E1ULL, 
            0xBF726343AC80007DULL, 0x6CA2C18B4CCBCF95ULL, 0x5B20B18A2286FEC4ULL, 0xC173319D62956F4BULL, 
            0x8E99D8848AD4065AULL, 0x1D694D1783371900ULL, 0x704FB3A9FDBE81EFULL, 0xEC018D72127F8217ULL
        },
        {
            0x08EFB43BBF3E6BF1ULL, 0x091021D6DE38F19AULL, 0xD4E5AD2B11C18C5EULL, 0xE7439413D48D1B45ULL, 
            0x83110D37FFAD1B92ULL, 0xA001D820623D0806ULL, 0x5D31A9EF44A0F36DULL, 0xE372283A80FCD548ULL, 
            0x7C25E54BC6893055ULL, 0xEA8E3897F9EDB57AULL, 0x80675815E929B6E0ULL, 0xC38F503A61CA3673ULL, 
            0x55550F32B23FFFA0ULL, 0x4EE69D2D2FFEBEC5ULL, 0xC6F33852988BC025ULL, 0x8DE9396F9E0F39BFULL, 
            0xFC42375E4A5528D8ULL, 0xE1CFAD2B9FCD1B6DULL, 0x75C03D5549DC5D87ULL, 0x73DE7E951ABE746EULL, 
            0xF318D29C1D687A58ULL, 0xD9C4FD2080D8AAF3ULL, 0x90BE6ED4C33CB441ULL, 0xC574FA4EA007E6EBULL, 
            0x26C40CD61D8C60EFULL, 0xA8E69AC14C8C3964ULL, 0x2931309E609FCB8CULL, 0x4D78FC52CDFBEC0DULL, 
            0xC5FE149A7D921223ULL, 0x70994864350DEE9DULL, 0x36CC9C8BD1111D5CULL, 0x4657F858FF70C3D1ULL
        },
        {
            0x01DFABC5794EE6F3ULL, 0xF82C5B54C300C9ADULL, 0xDE6A6F9602D0E512ULL, 0x5CD418AC859FD00AULL, 
            0xD2D143FAFA639090ULL, 0x2E60372852472411ULL, 0xC30E0EE5DE8E4A3FULL, 0xFF349B194AE9C82BULL, 
            0xE3C8F1D6FE69F501ULL, 0xA332434C69AADF68ULL, 0xB152A7FFE4D4D03CULL, 0xB3B0419B3B2EE0AEULL, 
            0x7255603AC580A4A3ULL, 0xF76FA2AF636705CCULL, 0x936248418C8A4926ULL, 0x6400A103F6DA0369ULL, 
            0x1FA8C198A80D96FCULL, 0x92B034256DE6C7F4ULL, 0x462DB909629D48D2ULL, 0x61F0BCA591A0A210ULL, 
            0xAD44E1655F1784F3ULL, 0xEA8A8B2BF6DE4AFEULL, 0xA41D9FD22D99B083ULL, 0x8BFD2D7BB4F23488ULL, 
            0xB875CF6D07717BE8ULL, 0x3288C9353B84F27DULL, 0x83E995233EA4CF3DULL, 0xD9CB0DACFBD8950CULL, 
            0x17127FACC465BE70ULL, 0x93810825BC1CADB1ULL, 0x5F8F1D475DDDC358ULL, 0x52A10975C4F73036ULL
        },
        {
            0xEF0F2496DF925F89ULL, 0x90203A09B01AEF7EULL, 0x23E8A39A0C31306FULL, 0x70D29DD5EA301F58ULL, 
            0xD51165D75AFDF080ULL, 0x998DFA8979C6B5EBULL, 0xFBBAA47A5A0B06A9ULL, 0xF102312DF4041384ULL, 
            0xA579E320F79EEE7EULL, 0xBAA0B2A8142C4546ULL, 0x2D67814F766D90C9ULL, 0xC193AB1EF8141EB5ULL, 
            0x9E4C626AB4D5928CULL, 0xD20729A3644FA695ULL, 0x168CCCCF740B655EULL, 0xE89A4E1B8FE7C442ULL, 
            0x0B52F76ADB3FC50AULL, 0x352F3EC8AF5B6937ULL, 0x2AA1C0C26D6D7B3CULL, 0x206A3DA9BB972D95ULL, 
            0x1BC55FA9AF1C345CULL, 0xDAC1A6F1160DF7A4ULL, 0x523BE5FD1B72AB56ULL, 0x3178B3CB174AB9A6ULL, 
            0x54595A41A02E3156ULL, 0xDD90F9C01B28C70EULL, 0x2634F7A69B0EA535ULL, 0x35B37CEF4D10EC51ULL, 
            0xE5DAE7478557579BULL, 0x2F86C2218CF90F76ULL, 0x9B239243CE7EB3C3ULL, 0xF670D83D4B7015E0ULL
        },
        {
            0x6911D17D71895E23ULL, 0x79B739EAC0F93B0EULL, 0x0B92A61B6F541B54ULL, 0x05A00D5E66DCBB22ULL, 
            0xE24D02FE1353C925ULL, 0xA609BF1BAB20EE10ULL, 0xC7AAF6E83A28B75EULL, 0x2E07A2F89CDFC3DBULL, 
            0x8FECB7DFA342F541ULL, 0x8A5BEBBBE7C521ABULL, 0x70BBC36BB378EC96ULL, 0x80DE52A07B7F6619ULL, 
            0x28AF22FF29CC2FFEULL, 0x1AC4E1A129C6E66EULL, 0x9EA1151F2DBB8E4AULL, 0xC5189DE1E606C5E2ULL, 
            0x18C0872703DB3399ULL, 0x0FFFF3E2DC65A5DDULL, 0x051E21C72819BB4BULL, 0x586B8AA6DE232A56ULL, 
            0xDCF504510D657287ULL, 0xEADFC460E9F94C57ULL, 0x3F0AF4500A52473EULL, 0x4929D53BCAEBB60AULL, 
            0x0AD84C70A8E76DCBULL, 0x5C6423825C32394AULL, 0x97C0D212CB61FABEULL, 0xE6231B973E3EB973ULL, 
            0x39EAF9E80C3180ECULL, 0xC678B749D1866FBEULL, 0x7C8A3B0FB4DDB9F8ULL, 0x38C94D01BC9A66FAULL
        },
        {
            0xA0671738EFA46F38ULL, 0x3123324115BD44D6ULL, 0x6BAE408804E1C09DULL, 0x0D52671BE31A3E1CULL, 
            0xB6FBFC9B0165A409ULL, 0x1937096F65D44A04ULL, 0x8CBF6FD9D82345F2ULL, 0x7911A231E797D9B8ULL, 
            0xFD430E522FF3A038ULL, 0x7BC8529AB24C396FULL, 0x2927E8EADDF11E3BULL, 0x81B35030B0B52B0DULL, 
            0xC1A4A210FB5B3F53ULL, 0x9DB6103497B386DAULL, 0x7117189EDB31CCD3ULL, 0x3D5F5EF9A2F783F8ULL, 
            0x556AEABFE22BA039ULL, 0x01747D34549E9BEBULL, 0xA00FE68B6DE4C15DULL, 0x779A66DC619F9400ULL, 
            0x10CFDF18FD5295D6ULL, 0x0ED4E25FA3C5F523ULL, 0xE340BEFCEEB208F6ULL, 0xDBDD1AB51A1F634DULL, 
            0xA4229A53AF136040ULL, 0x3844E9815067A130ULL, 0x4981655A764D8D1FULL, 0xA8E174BCC7360AD4ULL, 
            0xDD23BDBB320C2CEBULL, 0x0F174CB33A9E7BCAULL, 0x1BF79BCB566B0629ULL, 0xFB24B1ADF26C4228ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseCConstants = {
    0xB7BD2693FEC0EBDFULL,
    0x3C0B66F1D225F710ULL,
    0x10DD905574DD8750ULL,
    0xB7BD2693FEC0EBDFULL,
    0x3C0B66F1D225F710ULL,
    0x10DD905574DD8750ULL,
    0xE5C9E970439BA2CBULL,
    0x69FEC6AC8AED644CULL,
    0x90,
    0xA7,
    0x4F,
    0x26,
    0x42,
    0x16,
    0x48,
    0xA7
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseDSalts = {
    {
        {
            0x6D1886C0EE8B5FE0ULL, 0x00C08CB36A02D29DULL, 0x63AA8EFB5AD9C1DCULL, 0x07217726E47E7716ULL, 
            0x678A8C3E51AD3E82ULL, 0x0E8FFDBD41A831D3ULL, 0xA201DAAD639F25D0ULL, 0x603E84434FFF2585ULL, 
            0x62CE9AABDAFD4E7DULL, 0x0A4F8A2F73BE51B6ULL, 0x2DCCF742DA10E692ULL, 0x1E67C4FB5ED4B0E8ULL, 
            0xC55E1E70E889E872ULL, 0x1BA27BBA8048C69FULL, 0x3FD20D54D16A0493ULL, 0xBB5DC3E71C832120ULL, 
            0xF7177705225103FCULL, 0xBABB1240A7D28EBDULL, 0xD0AC8A3646C851BAULL, 0xAF471E3E3902D24EULL, 
            0xDCB6CC3FA7FA595CULL, 0xCF9EBDCB951E2D0FULL, 0x69EBB554553F42CFULL, 0x49CA75DDEF13A536ULL, 
            0x7A9EE9A9EAF39177ULL, 0xD50577E329C413EDULL, 0x94089ED4DF44ED5CULL, 0xC18D339E4EF3F10AULL, 
            0xAB180C0931D296A1ULL, 0x79E2BF68D1D64C54ULL, 0x035928D17D960EB1ULL, 0x39CAE84971DB0EF7ULL
        },
        {
            0x6A25B3DF9E67D568ULL, 0x955ECDEFE9F91060ULL, 0xFF48D4BD270CC28BULL, 0x2605DEC09B108AFBULL, 
            0x050EEABA597BD3D8ULL, 0xB2D88639053C71F8ULL, 0x96FD9C77C1D920ACULL, 0x1A10F2ABE1431256ULL, 
            0x989BF7C2755358E1ULL, 0x6CB7FEB28F655976ULL, 0xE674E4C464C14BD0ULL, 0xBA6E026B7CCB4A1CULL, 
            0xE89B96AEEF1A704EULL, 0xEBEF3C4F4EA0AF3EULL, 0xE955A7024D1DA351ULL, 0x6CF81AD9C5949231ULL, 
            0xC3D0EE7F4DB7697AULL, 0x98A8DA1A2BE6A967ULL, 0xFD3B853D20E195BAULL, 0xFB002012C9F1F2CAULL, 
            0xCB70B6DDA766A9B8ULL, 0xAEDD61046DD0386AULL, 0x939AD949C06FC3D7ULL, 0x2284E02581C0EA2EULL, 
            0xEA40A139E71F0B32ULL, 0xB56A6CF979AC77EFULL, 0x043C94F6F57E1F85ULL, 0x0724F51742FCB4E4ULL, 
            0x837C37F4CAB86761ULL, 0x4D6E8E64506A872AULL, 0x777CF318DCBEF58FULL, 0xC23A2777E1F04D85ULL
        },
        {
            0x9A973445218CB057ULL, 0x598074FF6A54BAD0ULL, 0xE86F4ADD754FE88BULL, 0xFC238158FC7F5446ULL, 
            0x60CAAD864441A79CULL, 0xD2E7F0DBEFBD9D0DULL, 0xB7BDB3976C794B80ULL, 0x8B7227003314C63DULL, 
            0x791DC45F6E6EB061ULL, 0xD947CEA824BE277DULL, 0x9E6A673DCEF26624ULL, 0x3DB56F43F916C512ULL, 
            0x880AE7E16D5ADBD3ULL, 0x4A01CD1AF06B1E10ULL, 0x13DA8093C3D32C08ULL, 0x5081BAF39DD5C3DDULL, 
            0xAE41A20B04332371ULL, 0xEEEC61858086CCF3ULL, 0x800F327DD4160903ULL, 0xD49AFE45218E261EULL, 
            0x992F79E2EC37FBF8ULL, 0x2515C22285EC36D4ULL, 0x759E790CA289151CULL, 0xB7DEE26120C0382EULL, 
            0xFE26954BFA1D5D73ULL, 0x212274E3013925D7ULL, 0x97D3B1DD0743FFA0ULL, 0xD2C46C0B79A8B364ULL, 
            0xC49559EBC02A0572ULL, 0x9252E452A12DC5F3ULL, 0x77205B931FD4CE9FULL, 0x797D73EC07DB392EULL
        },
        {
            0x4B477C46DF54FA9EULL, 0x25649EB4C3F975D6ULL, 0xCD6F6D3A2C2C8CEBULL, 0xAAA510C9308C788AULL, 
            0x6AEA950F1C52D428ULL, 0x80AD65622317C275ULL, 0x223DDD92E5C5FF99ULL, 0x8A22178C545E73ACULL, 
            0x739A1B19DD508C52ULL, 0x575E4C7ACF211D4DULL, 0x446DD2849B0DD6ACULL, 0x86CA432B029B5453ULL, 
            0x5AE3CADB7C35FE3CULL, 0x34B764892C52A14CULL, 0x5CAB5D34FB97ECE7ULL, 0x7083BE02869723D4ULL, 
            0x8C8BCCB229EE2DF6ULL, 0xCF4C5CF92885BE23ULL, 0x655A76409EDD5942ULL, 0x57F03D30B1ABA21FULL, 
            0x6656499F6DCFC2F6ULL, 0x11EE38697D5CD689ULL, 0xBF04393AC4CA74D7ULL, 0x0EAC52FF499450B4ULL, 
            0x907AAB8346A90E4DULL, 0x77303EF151792E43ULL, 0xAB248375BCF35144ULL, 0x1BF25B265A16E0ADULL, 
            0xB34D74F747890862ULL, 0x3DF4453103E0CA6DULL, 0x31D97FCFC7314C8BULL, 0x04D185D7D85CAA2EULL
        },
        {
            0xC81720F88F744144ULL, 0xC497403D520C32F8ULL, 0xBD987BE894988308ULL, 0x9AABF4E88CCFBE20ULL, 
            0x089D9E4EDA61D336ULL, 0x8A35DD8833A6F4BAULL, 0x9D121C719FFFBF58ULL, 0xF96CB33032AB0D9CULL, 
            0xEAF2C45E8A780A05ULL, 0x8A7682F6E1AB63BBULL, 0xC2520CBD9AA03A04ULL, 0x754538A5A87FF3B9ULL, 
            0x1E5D123D78276412ULL, 0x0057DFC0AF8B99D1ULL, 0x9600F1CDD5778EF3ULL, 0x683D2AA7FC7734DFULL, 
            0x217DCFE861A8823CULL, 0x9E4198BAAC786AD5ULL, 0xF22D9F58BC53D237ULL, 0xA268D42E209DB20FULL, 
            0xA99ECF305CC4D935ULL, 0xC7853B8D09382E83ULL, 0x97058A5ACF1F9103ULL, 0x7FCCA33A43502D52ULL, 
            0xDD6902FEBBAC15FAULL, 0x1706FFF4C3CB0E60ULL, 0x3AB40D2AD719102EULL, 0x820CE309031128BCULL, 
            0x5CBCEF8777368256ULL, 0xDB07698E2CB28567ULL, 0x924A602F11CB71CFULL, 0xF72236EFD37647BAULL
        },
        {
            0x2A6FFFCE7A52922FULL, 0xFBB2C303FCCAC0E7ULL, 0x8816A300295F08F3ULL, 0x76D180890C9012E6ULL, 
            0x3D3D5962EA0F5DBAULL, 0xAF0A2933D4E5DB6CULL, 0x9A2B5521FB9DE98DULL, 0x6EF9D9BE56832486ULL, 
            0x4D9F89BAAAE93B7EULL, 0x4672F6BEEC88E305ULL, 0x6835E67B78F1D7A2ULL, 0x22379753F2AE4F32ULL, 
            0xB1BE3799A33716FBULL, 0x6422A496C35BFEA7ULL, 0x6444A7675C16915BULL, 0x57151D4C334DEACAULL, 
            0xE9CC38C0A0BA9482ULL, 0x8E748EA789221728ULL, 0x00550E4602366E6AULL, 0x66A263605EAB8D34ULL, 
            0x42E8D8AFF9248837ULL, 0x34AEDAC14B32DB50ULL, 0xD2203650F0AB0896ULL, 0x4E0963249D531B1BULL, 
            0x06AE9BA55D624D9AULL, 0xE63F808D12C3F8FEULL, 0x68FFFC2D1D06785FULL, 0xC17A85A1882648ECULL, 
            0x1D20259B9C277CAAULL, 0x5398A5ADA4CCC277ULL, 0x0C6F0F668D8D99BCULL, 0xFCE8BC6A67119CF6ULL
        }
    },
    {
        {
            0x69A335E3CC456912ULL, 0x7999C2CB9EF96022ULL, 0x7D0A7044A9BDEA04ULL, 0xC1AFE03B7A756C3CULL, 
            0xEED7358294DD211DULL, 0xFF9FEE17EEBF2824ULL, 0x6BD89DE3DC46AE3EULL, 0xA7E3DDDD5BC24155ULL, 
            0x7B1C3E0BBB465B7DULL, 0x56148F7AB4C8DC41ULL, 0x0A4F00828704729DULL, 0xF43ED346CBB67F23ULL, 
            0x0CC486C4ACF3E4C9ULL, 0x270ACA6E686A9C5EULL, 0x0B1D0E5D007BCF36ULL, 0x7E64A7E589334DB7ULL, 
            0xA6AF0661BB2B5D6EULL, 0x33529C04AE5F27DDULL, 0x0ED0CC1ED60F4F51ULL, 0x80D1C0C3667E863EULL, 
            0xC6FFF114BE027F4CULL, 0x26D2A20440D52AF0ULL, 0xD576F7206CD93CA3ULL, 0x54BA816253EFEFD7ULL, 
            0xB9825B8E8E3DDAD2ULL, 0xFBE2F0A8F49B07E4ULL, 0x2D4552978DA2F141ULL, 0x5844AD80311B3852ULL, 
            0xA8628D1186936F29ULL, 0x31BB8036854A4C83ULL, 0xF881C27677FBFD9DULL, 0xBE0E2057E9BC9AF5ULL
        },
        {
            0xF11DA02C54142F3AULL, 0x9F05A74CDA54FA74ULL, 0x22C48105A31ACE64ULL, 0x1B652BD5C11EDD1DULL, 
            0xF67BBA1715169D57ULL, 0xEFEC573719069329ULL, 0x624E16F7F226C928ULL, 0x66A331BD589C4587ULL, 
            0x14543ABE936998B0ULL, 0x1FDAA5CD456C85B3ULL, 0xF5426324C784A092ULL, 0x42132E66A5A924B1ULL, 
            0x18B14A1160FF407AULL, 0xA30DDB61500B443FULL, 0xA323E29560BA361DULL, 0xC19BF53DFD7D70F9ULL, 
            0x9989062135DA5D40ULL, 0xF718EA307CD69627ULL, 0x52564672BA3E5AF4ULL, 0x5D353506A665E496ULL, 
            0x02D6EFEE6EC5A546ULL, 0xF3E28DF13036E9FAULL, 0x72807A1B385BEA05ULL, 0xD75EC3C5C2C9B846ULL, 
            0x773E142D0990926CULL, 0xB66AA4C2C36ABF51ULL, 0x48021C1821A1F181ULL, 0x145F660494AF0814ULL, 
            0x4AC78E2D062AEB32ULL, 0x73CA28365FDE3DD5ULL, 0x39D337D1C1213F98ULL, 0x2C3F123ECE837A82ULL
        },
        {
            0x4F8D87F5E0D4C42FULL, 0xC82001A007477CCEULL, 0xE569DBAF06C90792ULL, 0xE879D03BF22A1E0EULL, 
            0x40A3793E388BB409ULL, 0x8FB848C2417BBDCAULL, 0x87975C4AB5BB87B2ULL, 0x522ADA7C58286EF0ULL, 
            0x075624766605EE50ULL, 0x76B96F93B04AF5AEULL, 0x5CA894E2DD4A8BFBULL, 0x5AD35AD7A9AEB8B1ULL, 
            0x1AC44BDAC67DF3DDULL, 0x267F2F34BFBECEBAULL, 0xF787D284CDE76DF4ULL, 0x6F24B6EC1AFF722CULL, 
            0x7DDC835D3912B837ULL, 0xED3C038837CF426AULL, 0x565B39307B74AB35ULL, 0x777DF2DE92990AEAULL, 
            0x67FB73DDF2C4E3CFULL, 0x297EE4E620249A48ULL, 0xBD26E8B0AA641419ULL, 0x0484B947E9F71587ULL, 
            0x8B7FD94396791D79ULL, 0x15A8E5DD8B54C108ULL, 0x2CC384029264EC5DULL, 0x1AE9839C6806E5A9ULL, 
            0x15090F11AF89774BULL, 0x880CDDE8B16C97A4ULL, 0x84EE70AEEC50170DULL, 0x6C139DAACE74D578ULL
        },
        {
            0x13A70173474703C0ULL, 0x78AA8BF2A6C48AD4ULL, 0xD294B04D25B0B476ULL, 0x7DB4FB5F485D2F3BULL, 
            0xE95C425EC9298F04ULL, 0x39643320394F4E3BULL, 0xD8EE5CFF6475881AULL, 0x0919E946373CDAF6ULL, 
            0xEB2F42B07E68FD05ULL, 0xE7165C4E03298298ULL, 0xF8D8D7BF23036DFBULL, 0x982A17AEBA0B5FE2ULL, 
            0xFDC5EAE54968E336ULL, 0xAE500B4CD69E519FULL, 0x3FA610F449A49504ULL, 0x27156821CF46E0E1ULL, 
            0xE8A88F5175F9905EULL, 0x87B41CACFDE77794ULL, 0xFF89E0A6B11C15E7ULL, 0x0FE4C9114CA7CED6ULL, 
            0xBFF302F3EC16ABB1ULL, 0xA4BC32DF49F0CDFFULL, 0x2386133E7E55D5BEULL, 0x87102A722B341F54ULL, 
            0x6BDF2808675578D1ULL, 0xF2D17597E64EF2C1ULL, 0x0938151EE0D34ED8ULL, 0xBDCD26A98545587FULL, 
            0xDC95779EEA3D7F31ULL, 0xA92D7C1E96081F2AULL, 0x40DE7CF7E4515AC6ULL, 0xFFD137DE93BDF0B1ULL
        },
        {
            0x6B1164EE579B3184ULL, 0x781999B763E0CA4CULL, 0xC505229209C058ACULL, 0x605F6D71582698B3ULL, 
            0xE6792CDBEE887935ULL, 0x37D73E777FD69565ULL, 0x45543A05DE9AA328ULL, 0x778F4B467C9F9D3AULL, 
            0x13D3321BA2A0B32FULL, 0x54EB9D9938318178ULL, 0xA2B7546060BE3C4CULL, 0xB5E9CA72BAE6CE57ULL, 
            0xB75C070AAC6D2759ULL, 0x0B489333134BC50AULL, 0xC81A488606689AA9ULL, 0x2F842CEB1380BA92ULL, 
            0x522FED0E927E3D03ULL, 0xBA229B5E72C6EA96ULL, 0x8E3E5FE10CC01E10ULL, 0x8F87A63AFFD248F2ULL, 
            0xABAEE5894D28DA6AULL, 0xD41AF04A366564D7ULL, 0x457292DD878D9CA8ULL, 0xED3A8B72D2E761EDULL, 
            0x92D6C22DFED61566ULL, 0x454EF64543BE3A09ULL, 0x909F5DB42F909E54ULL, 0xA8EA913736FB19DDULL, 
            0x9050472DBC86D248ULL, 0xA012E2C903BF63F8ULL, 0x52F8C552EB6D987CULL, 0x52B7CF0233AE6E3FULL
        },
        {
            0x6B891EC2B37159A2ULL, 0x8C4D427AAE7E6DD9ULL, 0x78A421A84717958FULL, 0xBD372C7253D1517DULL, 
            0xB3BD1C6717FCAA94ULL, 0xD3067B8AC47EB16CULL, 0x96931C884E9F3024ULL, 0xD06EFF28FB12B563ULL, 
            0x5CF9B193811B4C46ULL, 0x9C9AF13CDDA02A17ULL, 0x0260FC308A37DD0FULL, 0x8CBEF8F1B404FE40ULL, 
            0x7728E1637C9D5813ULL, 0x6E37A1B8C1722B9EULL, 0xEA1E03798370AECAULL, 0x1F144F0CDD1EF429ULL, 
            0xAE49DC174BB2E964ULL, 0xA7EC98555133822EULL, 0x805AB007A68E17D3ULL, 0x7ADEBC8DA847C62AULL, 
            0xCB3AFE6E5B61CB46ULL, 0xE10B9B74A0818062ULL, 0x782C594A3F283008ULL, 0x82836C3C8D7A8182ULL, 
            0x696A10518C1732BDULL, 0x1B437B38BC119534ULL, 0xC19A0771D1C322DEULL, 0xD0115ABFBE2725FFULL, 
            0x432D37514D0D0B3BULL, 0xA35A8A85A1EBD9E2ULL, 0xB9EA3C6B0A1D58E5ULL, 0xF372C460C5D71DC0ULL
        }
    },
    {
        {
            0xE80584A90CA6F01DULL, 0xB9971CA4A494ED8BULL, 0x3FF1C9218E274AA6ULL, 0x179DC0781F135CD7ULL, 
            0xF8CC3C6D8DFF3051ULL, 0x097FAC817DE4522EULL, 0xB8707CB5C25F94B8ULL, 0xE2B71585874220FAULL, 
            0xEBD12030888AFD87ULL, 0x50EB3CC9B08CF449ULL, 0x2FA171250D06FDADULL, 0x6260607488882DFDULL, 
            0x6616EAA1D23B8CE4ULL, 0xB7C33A4739167062ULL, 0xB986D4203EE7A5BCULL, 0xED81366FB8AA9176ULL, 
            0x4F5265FB33226189ULL, 0x5508D44432825503ULL, 0x457D74CE95195478ULL, 0x16A68BDB551FA717ULL, 
            0x23B788E87C595DF2ULL, 0x83897CC647DD7411ULL, 0x92EB956AAAA62DF9ULL, 0x3D0D2D720830DD72ULL, 
            0x905E771C8BE8CFCEULL, 0xAFF2FB9A2EFB6A69ULL, 0xB862C098402C6BABULL, 0xE5A598A39998CDA1ULL, 
            0x2EF4AD5103CBD946ULL, 0xC03416B92381E860ULL, 0x7F04C85E76790A45ULL, 0x9DA4F90C1A1ED526ULL
        },
        {
            0x64E6CF37D68F3FE8ULL, 0x0B461BB6751EA366ULL, 0x02DB8A4345EADECAULL, 0x8E63C2AB86CDB3FAULL, 
            0x7DFCF5A8BF6CC26FULL, 0x6DC0C454580B0B0DULL, 0x55EB522496865FCDULL, 0xE94BA1A056DD9AE3ULL, 
            0xB088A55D43C4E1CAULL, 0x66A16F0FD2986451ULL, 0x83BBFF52D80EE745ULL, 0x6EEE256DA74C4BB9ULL, 
            0xC38D17379287494AULL, 0x8071DAE93D0F0B19ULL, 0x8FF3057A713AC25DULL, 0x67E0511F3C0C5AE3ULL, 
            0xA617D69E2CD1FAFCULL, 0xD9292AF8D0DD04AFULL, 0x81F432C7D56895BAULL, 0xD8AD7DC56062D414ULL, 
            0xAB764D4A66E8E6DAULL, 0xDA5C8B637D6FF0FDULL, 0x3EF36AF3EEF82CFFULL, 0xB2796FF3717B8356ULL, 
            0x7504FF7AF660AB76ULL, 0xF73F60DC51F87721ULL, 0xF3B8A4F60E1645F3ULL, 0x2E0383502ED05FECULL, 
            0x5DE6ED3C684C1FEFULL, 0x71533AB03449C593ULL, 0xCBA3C0387100CB62ULL, 0xDB65FAE838A3286BULL
        },
        {
            0xA8CAD1A1AA096E64ULL, 0x3769B314626CF52CULL, 0xA376066F99709CD9ULL, 0x500C971A05993EB6ULL, 
            0xA1B8CE884B4D19BCULL, 0x8142BDC5C423D56AULL, 0x0DE3F506FE6F32D6ULL, 0x21D0984F2F48EDA3ULL, 
            0x2D50528C8B4952ABULL, 0xA7C3C13956199729ULL, 0x1B128A83EA288466ULL, 0x19CCFC17BBD2102EULL, 
            0xB4EC62458739D9DCULL, 0x7928B62BB7157CF1ULL, 0x665ACA8A3F086401ULL, 0xEDF5EE4CFC5221F7ULL, 
            0xF0E5824637869C0DULL, 0xC3D8A216E9857E01ULL, 0x20A95C8AEFAB1821ULL, 0x53E2FEF1ADA9BDFCULL, 
            0xDBA2AE77601359B4ULL, 0x22D9A37E6BB57FC1ULL, 0x55BB9169CB53CFA9ULL, 0x537406392563CEB2ULL, 
            0xA09F325528844F63ULL, 0xBED3BDDB9F46C86DULL, 0xD5B536B3D666B4F5ULL, 0x5E0C8D6278E367A2ULL, 
            0x2357BB4614A250CCULL, 0x48A80D8063345A19ULL, 0x230CC5E5B5F7F752ULL, 0x049063ED0665340DULL
        },
        {
            0x36564BDEC635D862ULL, 0xB51A5CB282D1D870ULL, 0x03B2113FEA8679F7ULL, 0x7FEB15038D1AA60DULL, 
            0xBC247CF555CAC84DULL, 0xD56A1A3B837C4D31ULL, 0xB017136338AA541FULL, 0x5657BC674F73A27BULL, 
            0xE6FCA42D0758C6F3ULL, 0x513D24754EE19714ULL, 0x0B2A4095C9CB8265ULL, 0xFFF4A1665E3CA43EULL, 
            0xDCC002A118398430ULL, 0xD51197F60B86A6D9ULL, 0x6643277F4FC6A0B8ULL, 0x72861760FD62E846ULL, 
            0x8507D9B5185472FBULL, 0x65DBF6417DA79E4CULL, 0x36D7BB6AC05E1A90ULL, 0x5C7210AB78D64656ULL, 
            0x50A4CF722BB563C3ULL, 0x276717B5B302A9CBULL, 0x1390DCD337D420A1ULL, 0xB75518C5BD3B8B3CULL, 
            0x2E2DB563C18115B9ULL, 0x33CD54E5B67542F2ULL, 0x740A72A90C8C02E8ULL, 0x4FD31EAC3D6D5822ULL, 
            0x09C1DDDC959D6813ULL, 0xC6A115E9034472D8ULL, 0xA7EEE0BC4B29E7FFULL, 0x7B68790D0E24A0A2ULL
        },
        {
            0xA7E954E62B4D0D4FULL, 0x8BD377E515F1530EULL, 0x59F58D287B7EFE01ULL, 0xA1D377B67764D986ULL, 
            0x974E30111A84759EULL, 0x9EA5E2A48A789A46ULL, 0x8968D0B123908C24ULL, 0xB126BBC9C860EC02ULL, 
            0x4945AF146B0C881CULL, 0xB74ABCC0904CD5C6ULL, 0x4E205EDE3F27B2FEULL, 0x3F2460A54F908D8BULL, 
            0x7C072887776B8507ULL, 0xD3E8730B91D7B92FULL, 0xFD77701ECAF14920ULL, 0xAE5706C926BDEE69ULL, 
            0x403E7A01666F0025ULL, 0xF25086BFF2455500ULL, 0x0E21E71F9D9E4E76ULL, 0xDB56251C5F297DE1ULL, 
            0xA5D882D8BAED0EE1ULL, 0x9E24F33DC6379181ULL, 0xF5FDE9F790014C6CULL, 0x96C5E404954F57AEULL, 
            0x5B37E77FDF3D503BULL, 0x2FD1E7C183B38F49ULL, 0xC56A7D8B3D3550B5ULL, 0x7245CC597A42C250ULL, 
            0x71A26AFEC4AC97D2ULL, 0x6706DA3ED73171A8ULL, 0xB8894DDDD8D42C7AULL, 0x90B8EE191050D8C5ULL
        },
        {
            0x8167B7AC1F9E91A8ULL, 0x565064313B6172A8ULL, 0x6A03B0B8CE20D3B0ULL, 0x14EEEF63142F264EULL, 
            0xCB33708BE8C78DC6ULL, 0xFBE8D81623821EDFULL, 0x0B22F4025BFA7445ULL, 0xF8D351B04062B7A5ULL, 
            0x1B16055B3DCBBE72ULL, 0xC95872462EFE17BFULL, 0xEB13E0BFC60AE04DULL, 0x9162ECBA2588A4D4ULL, 
            0xE5D5DC1B773BF8B6ULL, 0x2B97D2F1FB5F1E46ULL, 0x8304715F76AF319DULL, 0xBE5ED60E4BDA102EULL, 
            0x23500CDAD81A2F9AULL, 0x1D3DE2FB2AC33915ULL, 0xA0C931E22DEDEB60ULL, 0xDDA8ED499E81C316ULL, 
            0x932D74FDFE596665ULL, 0x3F2067C898888AF8ULL, 0xEC9F0361FD558259ULL, 0xCCD7F4D6CC10D4E4ULL, 
            0x6F9B072C4BDAA653ULL, 0x34B8804A960C18F8ULL, 0x6A9282D13CF43306ULL, 0x336C71FB74C97637ULL, 
            0x93501220EC443E6DULL, 0xB4634882145E889AULL, 0x8B018C8D4A323466ULL, 0xE0FCB2F377EC8425ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseDConstants = {
    0x4C876DB4C64CA657ULL,
    0x5EBBB577F5625C27ULL,
    0x158D694FCD03E724ULL,
    0x4C876DB4C64CA657ULL,
    0x5EBBB577F5625C27ULL,
    0x158D694FCD03E724ULL,
    0xB859354A96182DE5ULL,
    0x93301635AC42E0BCULL,
    0x73,
    0xEB,
    0x27,
    0x0D,
    0x72,
    0x45,
    0x4E,
    0xF8
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseESalts = {
    {
        {
            0xD5E0E4E49BB2E955ULL, 0xE99A059C89B7843FULL, 0x278AB4508B85C1DAULL, 0xFBBC2F83F9920607ULL, 
            0xBDC1558ECF8DDF96ULL, 0x0608AD6050F0EF82ULL, 0xED8747BB942ACC34ULL, 0xD3137D6F705BFC74ULL, 
            0x11F0ABA3C96195C9ULL, 0x9A16C9350999A9D8ULL, 0x26E6C7CCE7A242E2ULL, 0x2CDEC598EACB7C9FULL, 
            0xF95AAB89554A0B8BULL, 0x6EE7F8F8E0E1C58DULL, 0x05FB363EAD01376EULL, 0xC2EB22F57F3216B1ULL, 
            0x7EAD382717359C3BULL, 0x65B87FC168BEFA80ULL, 0xC16EF6204638AA06ULL, 0xE55BD1D66EEFDE36ULL, 
            0xB37FEB32339E5C3AULL, 0x9740C26179CF642BULL, 0x78A8A8DC69D6C2D1ULL, 0x2C1F0FCD44864372ULL, 
            0x31E31DB0FC532214ULL, 0x903E2FB501A61517ULL, 0x5A62819F6010B0FDULL, 0x3033092524FD9CCDULL, 
            0xFA6ABAFD034DF9ADULL, 0xAE62D049911E6CBEULL, 0xDDCE7AD3DBF8DD83ULL, 0x394FEEFB5195AAD5ULL
        },
        {
            0x83C7E376BB5BCE8BULL, 0x43336E98FB8BD38FULL, 0x00BBEA846203833DULL, 0x76A48ACB3666CB98ULL, 
            0x85043760A45C3789ULL, 0x26588395E945C83EULL, 0x622811E9E2C169E2ULL, 0x307450854EE4D8EAULL, 
            0x8123779E9AB0360CULL, 0x6EB2F65551A3C6A5ULL, 0x96F45A4E45018319ULL, 0x48A8C2AFED02B045ULL, 
            0x715EABA64E4D50FEULL, 0x187163BC487C2E4AULL, 0x8CF5EDCFB940CD91ULL, 0x809DC41781CE611CULL, 
            0xDBF94F706446ED6FULL, 0x03BB1069A4EE5557ULL, 0xD3A99823F4EF684EULL, 0x6476E299CFF9C188ULL, 
            0xDB089CB17B101912ULL, 0x4BDD9833E1AAC9FEULL, 0x0EFA11710BC5731BULL, 0x2548A2CF1A871812ULL, 
            0x220262BBC747006FULL, 0x3EEFFA05A3699B4DULL, 0xEBA1B2FF6CA5017FULL, 0x718B2A780970B5D4ULL, 
            0x5C865C5F6ABE80D1ULL, 0xEF4F46D0181A7AF0ULL, 0x755DAB976D4847F8ULL, 0xCD0144CD96EBD99CULL
        },
        {
            0x653CFFF0E0A66A59ULL, 0x749DE669ED8709D1ULL, 0xD0A10B0165BDE68EULL, 0x4E9EC3BE687744DAULL, 
            0x146C818EC882A9E8ULL, 0xAE38B6AF5A7FFE96ULL, 0xD1808C6C8108DFAFULL, 0x8DF84C72823DD043ULL, 
            0x8EF723309E6FAD47ULL, 0x68C20858BCEE909EULL, 0x151E62EBB74DF815ULL, 0xC3B395F62904C98AULL, 
            0xC1039B9892E2A168ULL, 0x0ECB1DB25DE5A5BCULL, 0xFEDEC08D60760B8DULL, 0xB70DFB6E2B44E9A0ULL, 
            0x3502E00B14CE9A92ULL, 0x04FB3C6B409D442EULL, 0xE840E864574061BCULL, 0x0E2AEFB0F1EB869BULL, 
            0x4D8DBC6F38F6E1CBULL, 0x1CECCF2C730BE193ULL, 0x6725D87D4D61AF56ULL, 0x492876D1A8E8C29FULL, 
            0x4FE5267CBBC059C2ULL, 0x641E14EB8C49FFD9ULL, 0xE81AB477C1314A6CULL, 0xE5CDE6257EB27D6DULL, 
            0x1B0168A64F357541ULL, 0xA5D22A419682704AULL, 0x5EC669AA6EE493B1ULL, 0x8583C3E3F178565FULL
        },
        {
            0xE4CB284277183B9CULL, 0x8296AE6319407449ULL, 0x5C374C8C23109B88ULL, 0x4B9D0DF1244F5791ULL, 
            0x63DC33C64962ADE0ULL, 0x20C3CFCDEF79F672ULL, 0xC6C9219D710A204DULL, 0x3C312CA27317BC04ULL, 
            0x594D9A8F36C9ED2DULL, 0x541C848E8A51F14DULL, 0xA80605D1141E9447ULL, 0x82F588C3D395279DULL, 
            0xC2125107DA60611DULL, 0x1553519B454031A1ULL, 0xA0567C165A39C021ULL, 0x986CF930B437760BULL, 
            0x6F2E9BFDF0B909BFULL, 0x168F52EE48994728ULL, 0x7AFF0DAD0FF76913ULL, 0x4DFCD3F724B8DD33ULL, 
            0x14D7C72FCCC618A4ULL, 0xA75CF470F9BE7097ULL, 0xB4619CF86AA282F3ULL, 0xEE9FDD6A0C17F0F3ULL, 
            0x706A10D56AE26280ULL, 0x37D08D839D4B76A7ULL, 0xE3461B80337899A6ULL, 0xCBDFA2F1F001B8F6ULL, 
            0xDE853CF585151780ULL, 0xC1E945685103891FULL, 0xBC5A345D5332064DULL, 0x969B2144FF067BD3ULL
        },
        {
            0x1DC30AC66578A0F8ULL, 0xC7C0FAA592E20584ULL, 0xCFE6711729CD888BULL, 0x87273C262365A729ULL, 
            0x33F6475A45568E11ULL, 0x4DCEB7066687FF9AULL, 0x9E62C13D6914BF05ULL, 0x3B44346903860101ULL, 
            0x821C63BB60A08D20ULL, 0xA5F857C29B138884ULL, 0xE364F6FA48704F0EULL, 0x67BB3E679486F563ULL, 
            0xB22490B0AF907E70ULL, 0x0BE116B972737176ULL, 0x8746241FB2471EFDULL, 0x471EBC3F47E581ADULL, 
            0x4FD5D8B02121AFFBULL, 0xBD464B1781C99CA9ULL, 0x5466CF035C079C3EULL, 0x0DFAD8CD56A14E98ULL, 
            0xAC2A822B4BBAC3CDULL, 0xE2EEB8E7D5D70629ULL, 0xC3580DCA1B4F0D30ULL, 0x68B84F421953C473ULL, 
            0xF740F0D25D209C73ULL, 0x4978D17FBFC9E214ULL, 0xEA739CA231BA6AB9ULL, 0x1ABFE50035A823C5ULL, 
            0x34EEB501A5DC3150ULL, 0xAB2623D9A71C779AULL, 0x28BC5B9D395E15ABULL, 0xEC9EAEBB66FB61C4ULL
        },
        {
            0xCAC2D1DA6DCE4A90ULL, 0xF8C1E9476B0D92D7ULL, 0xBE7010CA6D14F572ULL, 0x297473F9C241AA0CULL, 
            0x3DF1B6BBB8CD8D3DULL, 0x6284E3C48E3491DBULL, 0x14A7DAB8DC903D27ULL, 0xC5EC6CA47F25D8A1ULL, 
            0x8C076190522D085DULL, 0xD1D94B4E424BFB1DULL, 0x5E5917A17BA44483ULL, 0x60F4F6A16920B4BEULL, 
            0x792E12B3E2164E21ULL, 0xA55232235DE1F62EULL, 0x7D99B3D022FC4491ULL, 0x1E47CD42F70FBD0FULL, 
            0x7AC61EE251EA0BE3ULL, 0x5059359277F844F3ULL, 0x2E5088FDA9D07483ULL, 0x334A19D75832D2BAULL, 
            0xD21B3E587C7D6ECDULL, 0xBED56C6D294CFA54ULL, 0x302EA2EF4D81DFADULL, 0xE16267608EB240B7ULL, 
            0xDCB348F541F1FFA6ULL, 0x108D80626721550AULL, 0xD48BDD26015BBBF0ULL, 0x6B60BF8BD5F2748FULL, 
            0x9AA305A6642F7F34ULL, 0xF67754FF7026A4A3ULL, 0xE7B1A13BF4CF2B08ULL, 0xEEEDD9AED09643E2ULL
        }
    },
    {
        {
            0xCFF43BE749C83DECULL, 0x1A5E33D052102986ULL, 0xAD332425CF3350DBULL, 0x4B8EAC12883A9737ULL, 
            0xB4C48BEC07EDA617ULL, 0x9189EB6E6496E200ULL, 0xFF28F800A7A7F9ACULL, 0xD1220D587640CAC5ULL, 
            0x8FEE005618CD6210ULL, 0x7E79257C986B4693ULL, 0x732D9FB6D59299D5ULL, 0x12916A20F007CF8DULL, 
            0xE61CE29321307F76ULL, 0xB20EE03CD8176143ULL, 0x4E3D8CB6A303187BULL, 0xD2F1437FF1855A1DULL, 
            0x59623B7C5C298290ULL, 0xEF6B217D29BCC7E0ULL, 0xD544B41008A37688ULL, 0x1F70F02893C5F8F0ULL, 
            0x7EDAE8C44EB8F2BAULL, 0xE45184AE7C8346E4ULL, 0xBDC2C4BE9AC3F7E8ULL, 0x1009EF0814195EFEULL, 
            0x831639C55A64FC3CULL, 0xBC3BF61DC6124589ULL, 0x86C106B55F56D841ULL, 0xD196EE589B956F3CULL, 
            0xE7A46A9D95B921B7ULL, 0xD92ED0D99C538159ULL, 0x9D8076EAD26EB3D2ULL, 0xAD3734A78C20EAC9ULL
        },
        {
            0xA21D6256744CAE39ULL, 0x066C112AF8CFEFD3ULL, 0xADC47434515F9C89ULL, 0x14589C866782BE07ULL, 
            0x36E98525F8CDC2CFULL, 0xFBD5D90C9DE35626ULL, 0xD5A3D04366BC5F89ULL, 0x613ED7F3A3307926ULL, 
            0x88987ADC93BECBB7ULL, 0xF141B052AC3AE29CULL, 0xDE442F9A7D7744B7ULL, 0x5029E4DF7F5A3CE2ULL, 
            0xDF3271E36FC3A334ULL, 0xEFAD14527FF4D35DULL, 0x8EC61B2BC5A9AB11ULL, 0xC430E0ED2E531883ULL, 
            0x3544E21E758F2FBDULL, 0x616B2402F7A0D4DBULL, 0xCEE0067522317081ULL, 0xF8687F269E63A911ULL, 
            0x57417C2EA29966BCULL, 0x1B45B4AE25A1EC34ULL, 0x34D878D5F9AB8D3BULL, 0xB4112DA2D1675434ULL, 
            0x520662A9F2A3CCB9ULL, 0xC0F3BD575E66B3D4ULL, 0xB9A2B1C0ED8AD7DBULL, 0x3E3CAC9B84C03B02ULL, 
            0x993E1C8F5137483AULL, 0xD00F8245ACEBFA8FULL, 0x4A59CAF4F209755EULL, 0x053481FE9F4A95AAULL
        },
        {
            0x7AA3F7C2F98C4B66ULL, 0xCB6B994824E8C282ULL, 0xD06B27DF5B85247EULL, 0x75E2DF93564DEA54ULL, 
            0xBF060403E2C2EDA8ULL, 0x115E294E7A25F53FULL, 0x316FF822EDA86FD1ULL, 0xC3240B02C35C56F0ULL, 
            0xE355109F696C7281ULL, 0x102C1A1DF409E61AULL, 0x2DCD5C4FF9807FA4ULL, 0xC85960F56E4E9CFFULL, 
            0xCC87D0EAE123ACD5ULL, 0x74AA1D8A50CEDEFEULL, 0xDD7A206481082111ULL, 0x2039ECA5E4460FA2ULL, 
            0xD26FC3C36EF75D2BULL, 0x2CF0217E178FB54AULL, 0xF3FE420748676925ULL, 0x4897EA294E0DB025ULL, 
            0x414E69331614B08AULL, 0x62EF8120D74C1490ULL, 0xCCF81F33EBF836C0ULL, 0x874D914E3B43F152ULL, 
            0x03148020DED564CFULL, 0xFBB16FA875774B20ULL, 0x237E1B76164E9362ULL, 0x39121C10D64CEE35ULL, 
            0x7B27C832C408E400ULL, 0xEDDBC75814FB817FULL, 0xA7AA0D220C5B96F0ULL, 0x2167E328340ECBE6ULL
        },
        {
            0xFA6BBFBB7518E4DAULL, 0x61C0BBD6FF6C81EEULL, 0xE37B22C8AD73B612ULL, 0xFFAD43193E448537ULL, 
            0x99F2A3DC86BFAF63ULL, 0x13529CE7CA94BAB9ULL, 0xDA0D1A43F0A37DBFULL, 0x8DF9DD72C42BEE82ULL, 
            0x7821BE4DA6850A34ULL, 0x401214A632A90C5BULL, 0xB1DC8D7FDF3159E3ULL, 0xC965F12741403ABEULL, 
            0x51E1BF7B3B8B6A12ULL, 0x06898BE02E877A93ULL, 0xEC0F30BCCF329FF4ULL, 0x05FA975A3008AAFFULL, 
            0xCE3D6790047B0DC0ULL, 0x759A06C75A71EA32ULL, 0x35110271B3CC6629ULL, 0x9E06C596697A0DDCULL, 
            0xA5C365F0B6533907ULL, 0x45DF57C9C017C043ULL, 0xAC17D4EA1970AB3BULL, 0x9E595BFE491E53D9ULL, 
            0x5B213596D4067344ULL, 0x6859EEC55ED07517ULL, 0x6CBC879531B5B8DEULL, 0x68AC74C272808B94ULL, 
            0x304518B4E8BF623BULL, 0xC848909A887D7FCEULL, 0x7B1239B796041402ULL, 0x484C4C7C6F8927E6ULL
        },
        {
            0xA319AD6B03A9B196ULL, 0x448491616CF661CDULL, 0xAFFC57807F3047BCULL, 0xF155118EFB5D4A00ULL, 
            0x8ADB3AEFBADD699FULL, 0xDF434AC0DCE41D2FULL, 0x94960D67B6FDD11EULL, 0xC9263A35946A3C9CULL, 
            0x04D9F03742F8D2D7ULL, 0x3BF1B745EDCD4C69ULL, 0xC3A213CF572E569EULL, 0xEBA3C8968BFEE480ULL, 
            0xFCFB298C4DB4B844ULL, 0xA697E20D013C4E2AULL, 0x6569C1FD9A623EE5ULL, 0xABDFA717DDF1D204ULL, 
            0x26437A7DDC0DABD8ULL, 0xDA0F0D14B2FE6EF8ULL, 0xF6F898F2B5FD92AEULL, 0x0BF04E5B019EF242ULL, 
            0x59741BDA45BF28A2ULL, 0x7CCDC0CC824B722DULL, 0xE168737629F00204ULL, 0x8469D206DC5DDD55ULL, 
            0xA487DEB1C6457CBEULL, 0x89C48E82852C7D1FULL, 0x72273E7F0952C6E9ULL, 0xACD8CF2C0550797EULL, 
            0x75432DD4B183EA83ULL, 0x9FE182666F4E1B0FULL, 0xE3E020CE43AFB374ULL, 0xC000EF5F752AF9AAULL
        },
        {
            0xAADCE109B70763D0ULL, 0x2DF587267710C348ULL, 0x7FA1ABB9EB6701F6ULL, 0x4585ECE88ADC24E6ULL, 
            0xA434022F76B4A90EULL, 0xB8CB3254BCA7511BULL, 0x7F3F21B6294D3595ULL, 0xB985EA1CCB7586E5ULL, 
            0xB149C479ACF0627AULL, 0xB95A82F14434B5B5ULL, 0x2CD2DECD0CF53028ULL, 0xE27BECBFEC24E249ULL, 
            0xF9E63C688C484BD0ULL, 0x47FC9C755A33BCD9ULL, 0xB3FFB5159A4E31C6ULL, 0x8F7BD7A30DF861D5ULL, 
            0xE2542FBF0BF536EBULL, 0x66A74B618FC35D26ULL, 0x402306A2CC08B9BBULL, 0xCBC4E5AAD126B0B3ULL, 
            0x78CD42B2ECAC115EULL, 0x7DFD919AD35BF06BULL, 0x2C7B97B0486C35AEULL, 0x380BCD2136462DC5ULL, 
            0x1FB79CAD98B2EEA1ULL, 0xAA7E3F627EF676AEULL, 0xB2D9094AC182F207ULL, 0xA891A7B9AB6A3B56ULL, 
            0xB7938CAB74FE28D7ULL, 0x0087AFBEAB1D5AE0ULL, 0xE40B538A58768ABDULL, 0xFA6DC30184E8F81AULL
        }
    },
    {
        {
            0xDB32474CD431BC63ULL, 0x3E80A59E3C6EF54AULL, 0x72395A70E62B876EULL, 0x4A4EA37CF794B328ULL, 
            0xCF62F9CC02F76A6FULL, 0x4043FAF46111CD0AULL, 0xDC171DB1121F8156ULL, 0x55C365BC2F737697ULL, 
            0xDA5BA8D19E4DC7DCULL, 0x51345687FEFDC36FULL, 0x1F440F85BC3679ACULL, 0x1C1F48BCEC6DF287ULL, 
            0x49C68333986B82DBULL, 0x450B2B91F1EE1434ULL, 0xE5A68DCE75586CB3ULL, 0x9AA272F8DB2C018EULL, 
            0x01D8589D480B0419ULL, 0x84B60D70145DC757ULL, 0x8C4400EFECF8228CULL, 0xFA54050E6EB9BE93ULL, 
            0x372F9FC6666E20A5ULL, 0x3844E10AF129DDA7ULL, 0xC53F01F93E745C83ULL, 0xD88796CFEAE17BCAULL, 
            0xC72A6AA260E85D4CULL, 0x72DF2054617BF404ULL, 0xA8F3D5E344CFDE15ULL, 0xF456B3EA072DDAE2ULL, 
            0x1192E75D530B66ABULL, 0x69AB9A4C0CA74261ULL, 0x34FEF3AD72FCAA03ULL, 0xD20620894F591A62ULL
        },
        {
            0xF0E92E5F2BF1D7B8ULL, 0xC4D6FD05901FC237ULL, 0xB54FF65EEBA8AE1AULL, 0xB214979B3EFD33B2ULL, 
            0x967965A907D454FEULL, 0x5C97C2B81DFF0F92ULL, 0x0738A0517C15C759ULL, 0x2B1C51FE107EB305ULL, 
            0xB3EFCF5B3AF78328ULL, 0xC558679D57AFF75FULL, 0x8A70A4A1D97230D6ULL, 0xA6FAAD2FF56A823FULL, 
            0xCE3AFB78193FFA27ULL, 0xB3E1B59AD294713CULL, 0xB5395E4A86BCCD26ULL, 0x901BFBB323AD18A5ULL, 
            0xA0AE89C5E747C763ULL, 0x8D6D72E7731B4306ULL, 0x4F744A9C73E42A6EULL, 0xB62B6FBB028E0AC9ULL, 
            0x7D4C0D26E9A5C19FULL, 0x2E91AEE3F8E1BF8EULL, 0x80BB153B42B574C6ULL, 0xB81742FE416F5B55ULL, 
            0x3A0CA4E67CD2C69DULL, 0x99FD679F92906903ULL, 0xC45E653DF8F217ADULL, 0x921E7CFC0CCA5E3BULL, 
            0x64039E1C7016CD2FULL, 0x503F335EA171F9B3ULL, 0x54D2AEFD9C7A6B5CULL, 0x38B3CC381DC5AF5EULL
        },
        {
            0x9870113EDB8DE6DDULL, 0x4E23AB2E977745EAULL, 0xFC4C6528A24F7CC3ULL, 0xFE9E55F79B6880CFULL, 
            0x980D8531DE75C4CEULL, 0x6A068F0461167AAAULL, 0x88C6D68243AE911AULL, 0x1FFD34A3E12D285EULL, 
            0xB4AE9A87E4DB089BULL, 0xDED6D897C6C69744ULL, 0xE4EE8700A0B8260BULL, 0xBD9A0F5B2B14F130ULL, 
            0xC01C2826B82917D8ULL, 0xB391547FB4AF2290ULL, 0x6F3265CD1D7A398EULL, 0x35B62449EE60ED33ULL, 
            0x7686BBC9741F62A6ULL, 0x93EDB7C198FDE4D6ULL, 0x0FCACD9BBD9D0A8FULL, 0xD4A12BB1BC310A5BULL, 
            0x0216D091A7FF9EA0ULL, 0x8FD999781003254AULL, 0xAC8F9CBCE01D9409ULL, 0xCE3289395FE43877ULL, 
            0xDBDE841BF9652391ULL, 0xB0E825872E655EAEULL, 0x9C319F015274A7E7ULL, 0x935198032A6FEBDFULL, 
            0x79278311E0CB873BULL, 0xB459E1944C35BCFDULL, 0xA6A1C4707270B8C7ULL, 0x9C9C0B198F8F94D0ULL
        },
        {
            0x8ADE7B2F29F09BCBULL, 0x902346AE2AA21F42ULL, 0x352C35009FC2AB42ULL, 0xD685CDE6F881445AULL, 
            0xE2B3CF50B065B942ULL, 0x307B311C9BFEF88AULL, 0x66482448D14FDBC3ULL, 0xFCA871343D874930ULL, 
            0xD277D6F74C5D7369ULL, 0xC8352FD596E6FA6BULL, 0xC1C6947D0043977EULL, 0x23B13C7829044E41ULL, 
            0x0D49E037F6C4C72BULL, 0x7DA3D1D06C5AB37FULL, 0xCD8FE7CAAA8AD09EULL, 0x6924313248973BE8ULL, 
            0xAC96DDD7969A55DEULL, 0xBBF43372C77F59BFULL, 0x1EA57456E3C59CF8ULL, 0xF390D9D295DABBB0ULL, 
            0xE188E75B811C5A1CULL, 0xE2B9A403DB87F1D3ULL, 0x9F52820E40CAC03DULL, 0x7ADEC6B2F554C7A7ULL, 
            0x64EF4D1BAE1984CCULL, 0xA906E530C8FB0489ULL, 0x0CE7D03560C163C5ULL, 0x1272B8DD1F3A2EBAULL, 
            0xED6F6E6AD4F852DFULL, 0x617296F0C27226DBULL, 0xD820B5D4933F7335ULL, 0x9FF0C088467611C1ULL
        },
        {
            0xE7351DEDEFF4FADFULL, 0xD6B897BFBBAB199FULL, 0x7AA57276D170112DULL, 0xC25941BC9A121F59ULL, 
            0x0F0CCEBB5FDD9A71ULL, 0xF8E8E9BBCD9A58DEULL, 0xD772058356055559ULL, 0xD94D2D29E61CDBC2ULL, 
            0x36B636F9BCE393E0ULL, 0xE2E6FC59C37FB207ULL, 0xB867A423DB46217CULL, 0xD4D60C4CAA46CE78ULL, 
            0x430CDF94FFF83FAFULL, 0xE3579AAA62BDFBB9ULL, 0xB3866AE71B64C06BULL, 0xD6338A6B80394871ULL, 
            0xE9A335F1E667408FULL, 0x536709C6BD2B9208ULL, 0x7887437116D0C86BULL, 0xE337D91C525CB9E2ULL, 
            0x997A901787B5336CULL, 0x808ACAEE049EF108ULL, 0xD3012CDC0752293BULL, 0x742D8554DC6C9AF3ULL, 
            0x08A0C45384E261D7ULL, 0xFAFEFD102367EDD4ULL, 0xF44B704C252D0851ULL, 0xE3839B2B65FF24B4ULL, 
            0xE520C13FB9F5D965ULL, 0x387C1454AD80C0B9ULL, 0x722AD077B7D00435ULL, 0xD5007A6E21BC1E14ULL
        },
        {
            0x0DC2A1ECDB40B172ULL, 0x098443FAF313B3B8ULL, 0x916757810C73B930ULL, 0xDC1B35A2AED2CCB2ULL, 
            0x4965FDE2EC661BFAULL, 0xD189F2F30ADE7321ULL, 0x54DDBD246006295FULL, 0xD0EF4D956A8285B8ULL, 
            0x13D0624C778D70EAULL, 0x5B2EC4967DAC3F7CULL, 0x42DA99FC3B176671ULL, 0x60EDC4C4FCDB4729ULL, 
            0x20AC837CE9283975ULL, 0x2560B33371E68454ULL, 0xA71B4EF07A6B7175ULL, 0x789A5AAF4B36D119ULL, 
            0xF32E0A0D20BAC835ULL, 0x4737FF9B0E41371EULL, 0xFDE0BED5AEDE0330ULL, 0x405358E7CABEE3E4ULL, 
            0x3700DDD3D5EA2CDEULL, 0x100B5E84B8C11D38ULL, 0xA374BC74B3868E10ULL, 0xD60C5F2A98F25ECBULL, 
            0xD89B22C4A8CEF69DULL, 0x34858E8CEFA0E775ULL, 0xFD1456F08E472FBDULL, 0x4E70D8AFD2AB70E0ULL, 
            0x46BFD9CE86A2CE02ULL, 0x79158AD2397762F4ULL, 0xB2CF15950F2F14B5ULL, 0x37B04DB0FF8DBBCCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseEConstants = {
    0xC6E24133853F603CULL,
    0xF1567DCAE216195BULL,
    0x566561858D8378EFULL,
    0xC6E24133853F603CULL,
    0xF1567DCAE216195BULL,
    0x566561858D8378EFULL,
    0xD65CE6E552362456ULL,
    0xC39D1CBA72E11052ULL,
    0xE1,
    0x05,
    0xF1,
    0x39,
    0xA8,
    0xCF,
    0x1A,
    0x16
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseFSalts = {
    {
        {
            0x6274CF6BEA3292D6ULL, 0x93853568508500F8ULL, 0xAD7296660BD8FA64ULL, 0xABFD57B9B86F74B8ULL, 
            0x7086AA95BE345BD7ULL, 0x45CDE37EA375EE2EULL, 0x41260C9ADCC67210ULL, 0xD45A9BBC4084F62FULL, 
            0x4B9742EC6D747500ULL, 0x9A559EDE9F094322ULL, 0x1BA197F8293EE05CULL, 0x93349E54D158FD6CULL, 
            0x690FEFFEDFF57D80ULL, 0x036F520EB3AAFE88ULL, 0xA409B47A44071FC9ULL, 0xDDD154E2855728D6ULL, 
            0x6850F29401461255ULL, 0x97E6F0188252F09BULL, 0x795F562336325132ULL, 0x0E568E9B71415070ULL, 
            0x82598C46EE2B06EDULL, 0x36D8CE33C06FF4D7ULL, 0x0FB39C9C5F4AA6A7ULL, 0x944D897865326865ULL, 
            0x596BCD366CA16F30ULL, 0x2AC287DED1F6214FULL, 0x8268FBF317193567ULL, 0xFBA80DB58A39BCB4ULL, 
            0xAAA2FAF74818728EULL, 0x317A3A4992FDC29AULL, 0x1C8380038B1B911BULL, 0x081C5E5E61A514BCULL
        },
        {
            0xD5416172F058FE03ULL, 0x81A13663FD79648BULL, 0x84E66D7CC7ABE10FULL, 0x87D04D159F7B2D74ULL, 
            0xB508C6173FA1A4ADULL, 0x3CEACD615EA88A32ULL, 0xBDB72F49A7542634ULL, 0x9B1867DE0234741EULL, 
            0xEB1DE25BE59F456DULL, 0x536BD10188843731ULL, 0xA14C3498923987C9ULL, 0x61814C6F3073B1A4ULL, 
            0x0892DDFDF5B96A61ULL, 0x18353CCBA316C512ULL, 0x9E663094733AF623ULL, 0xBDFBDFF597E159A5ULL, 
            0x43D8AD254FBAB602ULL, 0xB0B64FBA9006FB0EULL, 0x989F0C55DDF62525ULL, 0x2BC1058277A2C335ULL, 
            0xDD7DECB1BC336F87ULL, 0x6C544D2D24F445CAULL, 0xCF955C059D1C329DULL, 0xB5438B26F915A61DULL, 
            0x213E1D9ACF2B7DCEULL, 0x87ED0DA11E7B7F9DULL, 0xB610E3BB73C70844ULL, 0xAB9C43BCF3B1D471ULL, 
            0x4C3F19F8703F6424ULL, 0x639CBBFB621B61FDULL, 0x50997F758AFEB68BULL, 0x434EEA5DF98497FCULL
        },
        {
            0xE14B0CBE084F76ABULL, 0xCDDE8136C27A807EULL, 0x30BEABD5793E7C45ULL, 0xB6E2C57FF1C3E4B9ULL, 
            0x223E6BEE47ABDE57ULL, 0x5F82E66424E2C4DAULL, 0xB98F428ACD0BFE11ULL, 0x2EFC7E45C17AD3AAULL, 
            0x3732A550498BEF6EULL, 0x1116E8ED7342A77DULL, 0x7D59DBB149E3BB1CULL, 0x122A84A0A7CF496AULL, 
            0xE65505695E2F67FAULL, 0x7610CEFD6C15CD2EULL, 0x80E0CCED88EFD2F6ULL, 0x92DDC387FF3693C1ULL, 
            0xF610432ABCB5080FULL, 0xDA3F7BDC1782E3CFULL, 0xE0FB575837CAF785ULL, 0xE1F5FFD98B4A99CAULL, 
            0xF424860A7D2E2B0DULL, 0xA68DB33A8CA5570BULL, 0xC2277168366A9F28ULL, 0x43F5BE42AE62DFC4ULL, 
            0x2222C52050204ABCULL, 0x71737A8BE4E92789ULL, 0xD02D80A8CE500EE0ULL, 0x3B8CF71B3A473F0DULL, 
            0x3E454780A1F1EA45ULL, 0x0A8BCC3E84EE0E58ULL, 0x3AF5D9B667FDE800ULL, 0xBEB3BA31005AC07BULL
        },
        {
            0xE6532977D0DE21C2ULL, 0x4017D242C3361E90ULL, 0x3B87F0C9365854E7ULL, 0x42E76C86C348C71BULL, 
            0x3852B6E1C7E6A729ULL, 0xBB4FF42B340DFB21ULL, 0x7A35DF7C0542127EULL, 0x7DD4786E0833D410ULL, 
            0xDB2E013EBC3C4A93ULL, 0x749C7B72F3E89301ULL, 0x5388E4E727C8D696ULL, 0xEBBBC448941E1614ULL, 
            0x0340BA7AB8462DB1ULL, 0x5855EBD83BB21217ULL, 0x5E6F6CB4AC145386ULL, 0x85BC16E448680DC3ULL, 
            0xF2E3E82D7FED9EFDULL, 0x425989834E44E530ULL, 0x48022B2EABD36378ULL, 0x8E06F5DAE449BA32ULL, 
            0x9AFFD76184157508ULL, 0x9B55C74151BFBD55ULL, 0x86911E24D034402AULL, 0xF60BC9044FA8CFD3ULL, 
            0xEF23501DC2464EB4ULL, 0x09603C022BA4FB04ULL, 0xA72E6800ED1B57B0ULL, 0x3FB527BCBBDD5CEBULL, 
            0x973293CF2ECA76F3ULL, 0xF0093B55B9BB16A2ULL, 0x5F851A8AA2D02D59ULL, 0x0448CFFC2DA65FDDULL
        },
        {
            0x93001844F1AA0EE0ULL, 0xDD0AA2ACBEAC6A38ULL, 0x81E869945ABEE85AULL, 0x917EA567AAA708A3ULL, 
            0x3D252E15EBC3537EULL, 0x1449E80AB7ACD407ULL, 0x4C915E2C7E56069BULL, 0x048538247E51B04DULL, 
            0x3622373977278BAEULL, 0x3D75FAB2740B3EDFULL, 0x5E99141835FDEF81ULL, 0xA9CC9FE8FD0A9E18ULL, 
            0xF98CEAD061EA7026ULL, 0xE8381003172012C1ULL, 0xFEE360B9CBE40985ULL, 0x6D70174455017756ULL, 
            0xFC082C0BD9BBB08DULL, 0x887299FE1388C3CDULL, 0x787B8A850A3D520EULL, 0xD7DE36C963CCB72FULL, 
            0x64D33F1EBDDFA8D5ULL, 0xB9205E35B65609A3ULL, 0xEEBFA33EF18FE713ULL, 0x0CE538F1196B8A83ULL, 
            0x748D378173475959ULL, 0x9D9285156744A62AULL, 0x4245F1CAA1F27F33ULL, 0x607816491288E535ULL, 
            0xFB2166153C12B28BULL, 0x5A9059FC2E0A5851ULL, 0xD71AF87CD4D64463ULL, 0x90723C2C1F06A54FULL
        },
        {
            0xE8F23E4FE7871884ULL, 0xA60AF7FE79150A5CULL, 0x10863C4DA5D83786ULL, 0x5454A83E8A8FC345ULL, 
            0x06362581A929EA5AULL, 0xA69988E81430A606ULL, 0xEA7CF8E70922F670ULL, 0x83C35C033EAEB3F2ULL, 
            0x93D0474F3F95ECC2ULL, 0x706E8196666D15D9ULL, 0x7865C98F3733D4F4ULL, 0x1BE854653F380449ULL, 
            0x648093A87339CCCCULL, 0x46A35A87435DDCC6ULL, 0x48B25874F7410EA2ULL, 0xCF278ED51398733AULL, 
            0x764CE545C5022F70ULL, 0xAC9906B07AD07C91ULL, 0xFDA168BD4404044FULL, 0x0E637F2B2AC5EDF6ULL, 
            0xC82A24AB979EE3F4ULL, 0x9D60EA5C9A49E1E9ULL, 0x7EB497E020A9C40DULL, 0x2BDE6DA82442D1C3ULL, 
            0xF5B9F2AA554AFB79ULL, 0x9ECABC2346AE7E73ULL, 0xEBCAC08DC697DB5CULL, 0x22847816BDCBD2C1ULL, 
            0x44763A1A5BDD201DULL, 0xC5DD479F2B0C381FULL, 0x263617C0DD31539CULL, 0xBDE15C487177B6BEULL
        }
    },
    {
        {
            0xB7A5F0886D28AC1BULL, 0x37264C6A528975E5ULL, 0xEBAFEB9C4C672819ULL, 0xCC482A3645C38BE2ULL, 
            0x4E72A5E328800754ULL, 0x2BDC8D25BA4529E1ULL, 0x8E306562A59AEAB6ULL, 0x244C1EB20D3A1CA3ULL, 
            0x457DA379EDC02AF6ULL, 0x66B3DE5C738A0709ULL, 0x9F35D658EEE36FCEULL, 0x5D396546F727B0BCULL, 
            0x444FF23F25289533ULL, 0x89C458F689E7F3A9ULL, 0xA256D439269A6200ULL, 0xD4E20B8C7F137C4AULL, 
            0xE570D85A9D3FEFA7ULL, 0x91BCE65F2F9B22D9ULL, 0xA54EFB90FAD2F791ULL, 0xDDCB89A623AA6060ULL, 
            0x285589CB1586D42AULL, 0x4F099D3BE2CDDFA6ULL, 0x33B39991266694CAULL, 0xA08AF4FB5D15A96EULL, 
            0x1159A2DDE37ADBAEULL, 0x829FEC7EA95A29A3ULL, 0xC268700325FEC6FDULL, 0xEA80662DD86ABFF8ULL, 
            0xE53BF26C316713B2ULL, 0x807110819FE59CD1ULL, 0xC39876E3695B5FF0ULL, 0x8348F53673B1CC2EULL
        },
        {
            0x4EF4870E1E33B964ULL, 0x7148A6D8A99DCC63ULL, 0x642775562DDF7179ULL, 0x533E98C1E7207E27ULL, 
            0x6DD45A6146899F7CULL, 0xC0912D2909FFA784ULL, 0x70373AF7A2A79B2BULL, 0x5E5AB62073E5AE4AULL, 
            0x4195134DE06AC86AULL, 0x8DC3A47C85F9AFFFULL, 0x177EC5192A984305ULL, 0x2AD5BA03D0EEADBCULL, 
            0xD9175B97E9AE35F1ULL, 0xE1AEB85D0703C759ULL, 0x1000C7DE0510420CULL, 0x129E8490D9E19B0AULL, 
            0x540EF38E1C375C67ULL, 0x71F99B3512E055BEULL, 0xC00AC9864E2943B0ULL, 0xECE4105BAEDAF0E6ULL, 
            0x44610713A349245DULL, 0xDA6838B13A80907CULL, 0x45CBCBFA74C704CAULL, 0x4B2D80BF52C91629ULL, 
            0x864F535F23AE8BAEULL, 0x971A2BE4EFDF7AE8ULL, 0xDBCB4822436A366AULL, 0xCBB28A52B1BBA4A1ULL, 
            0x78C8F71D0CB14D2BULL, 0x72CD6BCC90ACC894ULL, 0x95FEFB0C805B65A5ULL, 0x19374276C651D31AULL
        },
        {
            0xC240AB51D394F491ULL, 0xFE32A331930A9AEFULL, 0x8B9B0DE9DB476B03ULL, 0xA2B4E447E071B93DULL, 
            0xFE7253A9F6405DBCULL, 0xD351971BFCB0112BULL, 0x5822524AA3443195ULL, 0x3297312DF32C8CBFULL, 
            0xE69398EAE036402CULL, 0x570A1240F9D47F0FULL, 0x9E69F910E6E7697BULL, 0xFA8AF9048203E761ULL, 
            0x91A3C6B121EC66B2ULL, 0x52FAF23C3E93B27DULL, 0x4FF0921DFA122036ULL, 0x97394D51095652A2ULL, 
            0xF6D2A00527DF5D58ULL, 0x866275DCAA5E5BC7ULL, 0x4E430B2E339DABCBULL, 0x6A14DA84FCA86A79ULL, 
            0xB01B112D8D9D7212ULL, 0xFB70704D608C2002ULL, 0x55405FF1072465A6ULL, 0x0CC68E5E4DB9C2DBULL, 
            0x830AD8B147E927D9ULL, 0x5948412C090DB454ULL, 0xC442893F95AAC4A2ULL, 0xD344AAFE22D5A9CEULL, 
            0x892B88A5A4657586ULL, 0xCDF746AC592374EAULL, 0xD5C34AC57EF1D047ULL, 0xDC132FFDF531609FULL
        },
        {
            0x8D8336D13B8220DFULL, 0x9F391A47321853BFULL, 0x4F510F6895889619ULL, 0x86D5D1E8C5692CDDULL, 
            0x7FDECB4941D702FBULL, 0x12E63E1CDBC827E1ULL, 0x1AC45BF43CF28E65ULL, 0x3BF3FEE454DC2FAFULL, 
            0x11FC62B689DF37ADULL, 0x3C3EE353482A29AAULL, 0xD83C45979644DB65ULL, 0x14F3AD5D090E398AULL, 
            0x805DB06E637CAC79ULL, 0x4D3FF843FC6B2A2FULL, 0x9AD1A368A9B1EF20ULL, 0xF687E05C64CB07BDULL, 
            0x70BB0195B8DBB621ULL, 0xD6EB8075B6E5E00FULL, 0x5157E939A679EF6BULL, 0xA091996915684741ULL, 
            0x48BA9AFFEDF1B01FULL, 0xAB1C34BBF7C3B8F9ULL, 0x6E5DD7B66D708AB9ULL, 0x95A7E56D909FDD12ULL, 
            0x25352B85E523AC84ULL, 0xF3CA5532A338F356ULL, 0x50E735EF5C6936BAULL, 0xED53EC3A8BEEFE9FULL, 
            0xCE4ECDBDF91B9680ULL, 0x2DB49B6560994C7FULL, 0xFCDC038356303901ULL, 0x553CD292EAB6859CULL
        },
        {
            0x2E1A5397A1960745ULL, 0xBB2D7DA9AB9E1B7BULL, 0xA7579591B853C1E6ULL, 0x79802D91CF936DF4ULL, 
            0x025331D0B6A5D3B1ULL, 0xD5DF4BCC952E3723ULL, 0xC41514EB5413886FULL, 0xF548AA3A1621BDD6ULL, 
            0x5C3874BCABAED0E6ULL, 0x85A2EB6C43E6C498ULL, 0xE0A49021037D0921ULL, 0xA62B2EDF493036B0ULL, 
            0x386EB3A5F1E88880ULL, 0xD8EBBC6134B1B16FULL, 0x468C7001D7324BA8ULL, 0x1547658BB5A6E524ULL, 
            0x1ADCB684B319C2B4ULL, 0x2CDF8DCFF52C5EFDULL, 0x7487A30674F6F35EULL, 0xA2814001F7DCD247ULL, 
            0x7D07237C8749A0C9ULL, 0x9839ED390EA5EA16ULL, 0x57BC2B6CC9866645ULL, 0xDD1293AAAF592A09ULL, 
            0xCD7397737F947EA3ULL, 0x0F16E056611F061FULL, 0x661989DD4BF65F8EULL, 0xDEAE8FD13FFD0A0BULL, 
            0x2729A900E9B9D12DULL, 0x3220A7EF6950AFBFULL, 0xEE69AF5246D30A72ULL, 0x1F08E5927EF3C5BDULL
        },
        {
            0xEA62DDB3ED3A9A9AULL, 0x020A625BEA7A2384ULL, 0xEF192F1D45581918ULL, 0xCDAB4962EF76C0FBULL, 
            0xFE68BC5E1FB34CCCULL, 0xA3BFA213E6542D4FULL, 0x765433FF6B4F6CA5ULL, 0x6A773ABF73BCF0BEULL, 
            0x375D1D30683D0E34ULL, 0x5B16B33E03D7E06EULL, 0xA8AB02635588F020ULL, 0x41E439C8763A523CULL, 
            0x4CFAB6DBCFF3AE1EULL, 0x5BE92BD42E6A30C0ULL, 0x95914230B6AC063FULL, 0xE8514DDAD82775A0ULL, 
            0xCB1827C4675DB776ULL, 0x1DC04735F14E065CULL, 0xAE9E0B1BC8DCFA00ULL, 0xB35A856666EC47CCULL, 
            0x7DB35DD4A1888603ULL, 0x1F06316D3B7E4633ULL, 0x6F838BC6F3DF9E3BULL, 0x051956EB6DDA09C4ULL, 
            0xB1F0DF653910F8D0ULL, 0x61F17A5F7E53FE4FULL, 0x3CAB7FAD342A26EEULL, 0xE29B76EB89EB44F6ULL, 
            0xF43EAD4763F46B2BULL, 0xCE6DEF76637CB35FULL, 0x85289F8DAF923405ULL, 0x8C891A8EA24E233BULL
        }
    },
    {
        {
            0x8CF89BECC6193AF9ULL, 0x32A8E57A7ED4C74BULL, 0xD158190766257C4EULL, 0xC3791F3BC43D4429ULL, 
            0x41DB0E4A653F288BULL, 0x4E818DBF827BEF72ULL, 0x163F4AAA9F28181DULL, 0xCF5DD3A2372F7B50ULL, 
            0x58D5B3662553FCE1ULL, 0xC5CF10D5F15594CDULL, 0xD8EA72BD801C0CC6ULL, 0x4FD6D6B2F8E8FE63ULL, 
            0x4863C5FA7F175D48ULL, 0x9F036CC00779F94EULL, 0xE8EBCDA36D2AC1F0ULL, 0x127B5CCE93024D17ULL, 
            0x164D7C638BF0AB8EULL, 0xAF28FACC4D74567DULL, 0x2048A3C4B40903F4ULL, 0xBAAA6CBC1045D216ULL, 
            0xBF1DBAF2AD81CE39ULL, 0x0A555C65A7B4DBD3ULL, 0x15C5FF8DE41155C0ULL, 0xA7629F8B43255B1CULL, 
            0xCE0A725162E11F6FULL, 0x312CA003B96049FDULL, 0xFE0F767CBCFA3C15ULL, 0x5177337A8B44DA38ULL, 
            0x86D980FB38FDDFEFULL, 0xDFF4C3360279E648ULL, 0x89D64DF3D3A37841ULL, 0x211DF3C9803179CEULL
        },
        {
            0x22696B9A895F6D7BULL, 0x748790683D2571F4ULL, 0x98063674FCAE0349ULL, 0xEEE77E7FCB8DDFD9ULL, 
            0xECB23F971E7982CDULL, 0x54BDA6F21DCBBAB5ULL, 0x75C94A03A3822984ULL, 0x141CB9E284E10534ULL, 
            0xC5B35AC9B70F7F9BULL, 0x340ED03A6ED19E41ULL, 0x6E1F360840F015CEULL, 0x89D3B9C4E3787183ULL, 
            0x76DDA8317CB71BADULL, 0xE1C32AC749CC3967ULL, 0xC7AE9158BBFD087AULL, 0xE6166BFD74FE4BDDULL, 
            0x1E0301C4116F2313ULL, 0xC61209ED7C037850ULL, 0xC407B846C5D1AA3BULL, 0x056F70D3B4EEE037ULL, 
            0xA2AA5DB721792650ULL, 0xBE67897B5EB3EC24ULL, 0x7F383BECBFC0300EULL, 0x86789E76EBDBE980ULL, 
            0xE534BD6EC9DC3D68ULL, 0xFADDB3424D420BA5ULL, 0xE899911F9D730BA6ULL, 0x81E56E1A9E5423BDULL, 
            0xEF1AF9248B18BEFCULL, 0xD28B3C87B4641EBCULL, 0x2307692B51DDE45DULL, 0x0EE5792FA81C96E7ULL
        },
        {
            0x0CAD6E6BA96DFD81ULL, 0x4130B2E45F75C2D4ULL, 0x33073435464B4B19ULL, 0xDEE62711660F53C3ULL, 
            0x600A5DE773790C51ULL, 0x92B35F6B2DCC63EDULL, 0xBDF6219CB8C94113ULL, 0xC452CCC9EF78CA10ULL, 
            0x7B60D775F55E88B2ULL, 0xC249338F26962CBAULL, 0xF74D162DA17B5E1EULL, 0xF50DE148649205E7ULL, 
            0x156027C8C6473D72ULL, 0x7576D6A18C3CD367ULL, 0x32B5CB98068D7334ULL, 0x9C90C8BDD9245B35ULL, 
            0x5BFB69972CFCC169ULL, 0xD7A297EC194FC98EULL, 0x428F3792685B8B5BULL, 0xC2DEE4A10F65C4ACULL, 
            0x32398CAE4A719E87ULL, 0x32A168DD143A745EULL, 0x2303D966691E6435ULL, 0xE2F226BC00BFA4F2ULL, 
            0x5246C3063613B83AULL, 0xB7764F162ADFEA9FULL, 0xC21F4C00F9793F6EULL, 0x7C85E681D9F97961ULL, 
            0x41E50BB043655866ULL, 0x23672AFD6A475118ULL, 0xEBDD6CF31DB7D0D4ULL, 0xC4B3E5ADA70B286BULL
        },
        {
            0xDDD339F85563B5E3ULL, 0xDFF31720F1E2629FULL, 0x0D0CA3F24937062BULL, 0x455752010706E073ULL, 
            0xD0B748775FA53BDFULL, 0xE10B3BD36E1939A6ULL, 0x55C19B47DC4E0F05ULL, 0x6044E5A82D77280EULL, 
            0xA689070AE43316B7ULL, 0x5D9B6E6686CF25B8ULL, 0x784344D9E2D65C10ULL, 0x3545056CFC02383AULL, 
            0x38F5D27CF4412951ULL, 0x6B4CD6D9FABB5E3BULL, 0xA8208666C10103A3ULL, 0xE2BECEB1A35011E2ULL, 
            0xB5C7CABEC30C41CCULL, 0x78398549C59CD528ULL, 0xCE5A92B48E56CDA1ULL, 0x658CCB10F2B085C9ULL, 
            0x3B69A37CAED4F557ULL, 0xBECE8BFE1CD495DBULL, 0xC0BC864C7009FF00ULL, 0x5DE7D62D9D0FEBDDULL, 
            0xDDFF15EDFD193980ULL, 0xFFD2430156CEB40FULL, 0xB7C96250EBA1A3BDULL, 0x64AA0B6B9A66992CULL, 
            0x264A11BCFD0C4695ULL, 0xE85518CFD5053E57ULL, 0x146D353F02F78497ULL, 0xDF8C387691AB6B41ULL
        },
        {
            0x2960E50CCD8A2494ULL, 0x22D585E5BF154B03ULL, 0xC9CD2CA5BBB2FB8DULL, 0x1CB6247132E88A38ULL, 
            0xF1CE12CE6F36AA97ULL, 0x7E139356C5A63E19ULL, 0xA8F892BE46B4FF84ULL, 0x4B6D8A4EF0455C2FULL, 
            0x42E87D734A3DF200ULL, 0xAEC47A21E0614273ULL, 0xA1B64B94EC8F37B3ULL, 0xC10833569E9484E4ULL, 
            0xEF3DDE3E027B1890ULL, 0x094534BBC51DA32BULL, 0x69C5C0AF80DB8FB4ULL, 0x75FFC1D465641E29ULL, 
            0xE13CB4B0BCB3983FULL, 0xFFEEEF99DFE1B532ULL, 0x44B434EE0A33AE0BULL, 0xEC8B9C586769EDBAULL, 
            0xD3656B626EE59686ULL, 0xAB035D2B0766CBB4ULL, 0x586812B1C2353EF4ULL, 0x69917BAC445A6E7BULL, 
            0xA181DFEAA43E382FULL, 0x4652300EBE3F6395ULL, 0xE89C2E8959F51790ULL, 0x750DAFF11A397C2FULL, 
            0xABC0BAC116266D36ULL, 0xBEA880843FE487D4ULL, 0xA9EFE6F707500F0AULL, 0xC8E99941939B239BULL
        },
        {
            0xFE81CCA33CE0419BULL, 0x816DA7A4116FEBF6ULL, 0x59A860071BA14187ULL, 0x48AB282B7CD733F1ULL, 
            0x9521D148A31E2391ULL, 0x0AB12095A77884A8ULL, 0x9E0CD0CBD2BDABA7ULL, 0x0F340BB8BEC06018ULL, 
            0xD169D229062BE4E9ULL, 0xD705AAD6776E9DBFULL, 0xBC8B5525CAEEDC4EULL, 0x4705755BFD00A755ULL, 
            0x776049DAD96BBA10ULL, 0x7700F843CBAF5519ULL, 0x5F793E066FB92F3AULL, 0x530666798105693DULL, 
            0x047B5CE67962A920ULL, 0x2C1B639132DFD6F8ULL, 0xC4EC02167147922AULL, 0xD469B0C32979F931ULL, 
            0x8DF29B8F923767F3ULL, 0x7BBA0196814B9D6EULL, 0xEE125D0401BDA2BBULL, 0xC68F5284CEE65B33ULL, 
            0xC7B7D992BEA1494AULL, 0x6D41AB6D96256E36ULL, 0xAD53D5DB5FB770A0ULL, 0xA1851238C1BCEC18ULL, 
            0x8ACDDC327109D7F4ULL, 0x2194EF83EA0E941FULL, 0x6194D79D9AADB6FEULL, 0x156271FFF7637B17ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseFConstants = {
    0xBC6C37A4E3D560F2ULL,
    0xBFBFD53BDAA3681DULL,
    0xC0A49C8BD14E6634ULL,
    0xBC6C37A4E3D560F2ULL,
    0xBFBFD53BDAA3681DULL,
    0xC0A49C8BD14E6634ULL,
    0xB488DD8FA6ED7082ULL,
    0x907F31FBD8198689ULL,
    0xB9,
    0x5C,
    0xF7,
    0xF6,
    0xF5,
    0x4D,
    0x68,
    0x59
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseGSalts = {
    {
        {
            0x6EFBF59811093F8FULL, 0x858A96490A44D50FULL, 0xCC20BB85C293F0CCULL, 0x2D775E02BB8AFFFBULL, 
            0x42289E419119D468ULL, 0xEC0520D31D0BB188ULL, 0x7EEACC9113278174ULL, 0xD397726377DD6A34ULL, 
            0x63236EB9C90AD732ULL, 0x4461B7EB0193B69CULL, 0x505C1A3D4C929AF4ULL, 0xE5043C5D23037CD5ULL, 
            0xE9657F3E4D27F11FULL, 0xF05F734936CFE84BULL, 0xC2F29210240D0950ULL, 0x58583E86D0F1177DULL, 
            0x1B83477B30CAF139ULL, 0xE966EE841C97DB41ULL, 0x6C4C9CEC5CBB5D33ULL, 0x0934E691169082F5ULL, 
            0x8D5FF69E2292910AULL, 0xF51677759CFEDDBEULL, 0x78D444D9CAC5AD62ULL, 0x03CB3DB0B9EAC80CULL, 
            0x07B9320240D2AE78ULL, 0x2C3CFD460A9A9C7BULL, 0x0394E9A863319B26ULL, 0xD1086DB2511F39F8ULL, 
            0x2D1B4E79CC91B637ULL, 0x035946F7A0A0A9F8ULL, 0xB132A7BC66AA9D21ULL, 0x97A4A5F7B83E082FULL
        },
        {
            0x20A67B12E981FE2DULL, 0x217379254D285EF7ULL, 0xE3FC223482E7EB6CULL, 0xBF900BAD156CF27BULL, 
            0xDD7C51AC7A8862BDULL, 0xE89EA3E727CB8E70ULL, 0x25451ECCF4B70AA2ULL, 0x9B10EA3001A6920DULL, 
            0x3AD63EA60E5AC9FFULL, 0x7C4C81A139913A4AULL, 0x86BC37DEC1558A28ULL, 0x7A2EB3FD8BCF7389ULL, 
            0x4A51711DC15AD22DULL, 0x89659A8BB1ACE4F0ULL, 0x5A49D211B7E2E3BFULL, 0x24623F2461E6B64EULL, 
            0x017C8A9310D59064ULL, 0x64DA48A345B06B6BULL, 0x46E802838264AFD8ULL, 0x25F8AC6E934BB0DFULL, 
            0x83EDEF9E6AF97EC2ULL, 0x0BADD7E32869432CULL, 0x96D40A92FA0D6168ULL, 0xB1BE5FEBB40A2571ULL, 
            0xF62A92691349DBBFULL, 0xE971EFDA68B52034ULL, 0x66F781458D152830ULL, 0x332D2A1CF015E75EULL, 
            0x4E5CE1068AB2293AULL, 0xE3DF556E377A2E55ULL, 0x19E7766AE1A4DA4DULL, 0x80D1B3DE95AC74CFULL
        },
        {
            0x80AD653497BFE6EAULL, 0x8293F6F268DA9C4EULL, 0xEF93BAE6EDD19073ULL, 0xB432868A52126C06ULL, 
            0x6A06AE682B045835ULL, 0x0F26406EF5062F41ULL, 0xEAA0D3D9F7234EA5ULL, 0x14E58623D17FAFA2ULL, 
            0xD7C1D11197D2DE1FULL, 0x9139788CFD923161ULL, 0x165DA1BDCF327E46ULL, 0x6BD20674431FC4C4ULL, 
            0xB325185E114A4F12ULL, 0xADC5FE5C19CC5FC0ULL, 0xA8E1CFD7FFC401CEULL, 0x90A1376C45CE9E9BULL, 
            0xC318F4941257BB43ULL, 0x98B73B581E3478DFULL, 0x21100695F81A53A2ULL, 0x1C9E3AC9105C8966ULL, 
            0x8A8F670E4A70EA8CULL, 0x64DECE0C1A3C1306ULL, 0xBC77FCA656F84DFAULL, 0x412A0C18BA130E4EULL, 
            0x2B19479F0440BECFULL, 0xC579045C86055690ULL, 0x8A6A969BDB95DD3FULL, 0xEDD1DF6652BE7BB3ULL, 
            0x65CCBDB9E4013353ULL, 0x031F9C66F87A401FULL, 0x8AB035DED8008AB7ULL, 0xEEB922525CB1A78BULL
        },
        {
            0x3939AB1FC0363332ULL, 0x324CB75E69EA620AULL, 0xF7CDE800FF54BA65ULL, 0x3151930DE5464EE1ULL, 
            0xD276D5B89083C95AULL, 0x5824D179B53BF455ULL, 0xE3A5B5203BA29A70ULL, 0xB0C0DC8DCDDED8F2ULL, 
            0x0D6070E56F42028AULL, 0xAE82BD54C302731DULL, 0x7FCE6B75EFCEBA7AULL, 0x8092D007E293FB14ULL, 
            0x4219DB45D2EBD07DULL, 0x695F95EF0445E8E7ULL, 0xEDAE290C17F71A12ULL, 0xB3EF160EFBFA8FA2ULL, 
            0x79A723839826614AULL, 0x6FE2A7A5F8138548ULL, 0x41F0860CE3C22780ULL, 0x55E1FE6F6143916DULL, 
            0xD922FC1B816A3519ULL, 0xB94C47CCE9DF3B73ULL, 0x944BC5A53C4B6AB7ULL, 0x19313C7E3D338E0AULL, 
            0x0B7F61C78F1A6B3AULL, 0xCE212C5933FEB721ULL, 0x87A8828954D991CCULL, 0x5262A3B0C8348E10ULL, 
            0x1A4FF409B9325A9CULL, 0xAABC091F854D4317ULL, 0x68B9CA3ABD11AE68ULL, 0x70865523FA37ECE3ULL
        },
        {
            0x95BBF2908BA034DAULL, 0x282616A26EAD1E57ULL, 0xFAA9CE22A535311AULL, 0x0E8BEAD5BCE5FE24ULL, 
            0x9E823C078A8FC04BULL, 0x9F934136E9A90251ULL, 0x5486C803B3AB27D6ULL, 0x822B1D1FD7767682ULL, 
            0x310B1A514E58B4BEULL, 0x8194C8C2DE70FAD7ULL, 0x1F1F76210D64D7D4ULL, 0xEDD4DA5728A17B22ULL, 
            0x38349B53F5922D97ULL, 0x09787697E9D966D1ULL, 0xD7B69D1467526761ULL, 0x0500568156F2BABAULL, 
            0x181D53D9CEF05AC6ULL, 0x13859796969C4794ULL, 0xA4C202F56C09561BULL, 0xB71CB1EA75C0380BULL, 
            0xC8CEC223BEF04066ULL, 0x8DB7B4514427150FULL, 0xE95067D4F303577DULL, 0x946BD844616A43ABULL, 
            0x48B4E78F316B3128ULL, 0xCEE43AC7F3D6D871ULL, 0x324592B4841C9A6EULL, 0xB596A0BAEA64A924ULL, 
            0xA40E8FAC8A78C0D5ULL, 0xAD366B78D4CBD1B6ULL, 0xF40166857856B68DULL, 0xD76EF0AD2D6B51FFULL
        },
        {
            0xEBBF50D511840B98ULL, 0x3683A497AE790A98ULL, 0x7FA7A490DB66041BULL, 0xF2B14E284435A2DDULL, 
            0x57D6E4C4C8E54F27ULL, 0x62F5087EB9E48830ULL, 0x5D9A5DF9BDD81106ULL, 0x37A2E7A04E18DD9DULL, 
            0x3705FA40546DE325ULL, 0xD5C344E59C897052ULL, 0x263BE05B926187EEULL, 0x86149D7CE4BEAC1FULL, 
            0xC32F46B7B26860CCULL, 0xF1490F33D62CC7E7ULL, 0xD5DE82D2A5A55168ULL, 0x71947CA7C77E20D6ULL, 
            0x8165A3882ED63B56ULL, 0x17D1AD3B4E0DAD09ULL, 0xE66551B2B55B8218ULL, 0xF0C9499FF5CD20A2ULL, 
            0x3D37E6304308D186ULL, 0x386707AD7803694DULL, 0x24454CE3BDBE2ED7ULL, 0xEB11336C0BB0399CULL, 
            0xA9710C0A98CF9D14ULL, 0xF0514624F1103A56ULL, 0x39B73FB2AC437BECULL, 0x9BE5926EC4B2F121ULL, 
            0x1718837E99D90E5CULL, 0x3CC23287B3C26DBDULL, 0xEEFDA772CD87A9E3ULL, 0xF6C6D4B96AFCCC26ULL
        }
    },
    {
        {
            0xFB79F51CC45D73FAULL, 0x090A1ED961A447F8ULL, 0x6F02C908A22A9223ULL, 0xDCBDEC20E7F588DAULL, 
            0xA967D6FD0F0A5BF5ULL, 0x5D896DF36DB52E85ULL, 0x0059D848C99239C0ULL, 0x6486987AA118266FULL, 
            0xCEACA0E76C36BDC7ULL, 0x05A5E205EB850D90ULL, 0xB0FA9D2CE8AA03E5ULL, 0xE9985C4E2FB7A18AULL, 
            0x087EB529B3A5DF8CULL, 0x80B7F9D503FC8900ULL, 0x8690CADBDF339FF9ULL, 0x9ECF9270353A6185ULL, 
            0x95B43213B1495D46ULL, 0xE104AA80F24D2DD5ULL, 0x7669796F7B9DE93FULL, 0x6C44727A3474178FULL, 
            0x7F823CC08B507934ULL, 0x15330CC20060C7DEULL, 0xDA7654BD3F86F8A1ULL, 0x2E7432B241FC49EDULL, 
            0x37A74A9DDFE1FB83ULL, 0x6525EAE088B57CE6ULL, 0xDC9F73B9644AE4BCULL, 0xA764C031EB93038CULL, 
            0x26B4D079A1378F32ULL, 0x19DDCB0756A0C368ULL, 0xB51F04DB031F6993ULL, 0x0C27454404BEC09BULL
        },
        {
            0xC2D2B5E0D33BE1F0ULL, 0xB9E3473C68B7EBB8ULL, 0x168BA313AEDC0DB4ULL, 0x00D04216AF63B4F3ULL, 
            0x2D1B57AD0ED3694CULL, 0xCBE89BD7C422990AULL, 0x3EDBEF9FDEE51473ULL, 0x5E7ABDA27C74527EULL, 
            0x31B058D8943BDDA6ULL, 0x7B8C08465F018FB8ULL, 0x3A0AF68F4F82C8E4ULL, 0x4B5DA3A1F7ECDC65ULL, 
            0x6CA245448A029B31ULL, 0x807667A0560182A4ULL, 0xDDE64D9A9DC7B1EBULL, 0x1DE8A9583908D9CBULL, 
            0x7EC442E567567D29ULL, 0xFE3125D691B52540ULL, 0xFD76ACDA1A965B93ULL, 0xF61ECCCF498D8E15ULL, 
            0xB9BE75A1C84985EAULL, 0x40932E412E0B1DE3ULL, 0x098B1DDCD24739F2ULL, 0x219EF41B091F9DA0ULL, 
            0xB4CB131038293D71ULL, 0x1E0DA9A350DAC920ULL, 0x3D437ADB017FE570ULL, 0xC0AAD19706EA0250ULL, 
            0x717CC0F228AB35EDULL, 0x7964CB9D13CBBEF3ULL, 0x4B277591AEF4802DULL, 0x64D0BF33FCC0F753ULL
        },
        {
            0x8BC2F43785E3DD90ULL, 0x2454CFA4E5A951A2ULL, 0x575DBC7185794D90ULL, 0x7815034ACD2D54E4ULL, 
            0x51E9152D2631F5E2ULL, 0x8D76E32A51396C26ULL, 0xB15023545CC9013EULL, 0xEB23F3E26C052426ULL, 
            0xFCCC2B0871398ADBULL, 0x0C8F0433DCEAB9C4ULL, 0xDDA811842176581CULL, 0xC1E937E4F5E44EBDULL, 
            0xDC3ADF1C3EA1C989ULL, 0xCA8F9BCCE65B6990ULL, 0xDDC6699174576DD6ULL, 0xDB454DC8F4224533ULL, 
            0xD4B3A8ADCC1FA48EULL, 0x5F6096917A596D05ULL, 0x239BE91F7DD2F88CULL, 0x330AB4AFBDF82011ULL, 
            0x829CBC8B3A5CA6F4ULL, 0x14E1BB11A6C7921FULL, 0x83226ADE28C5C511ULL, 0x6498A2835A043E60ULL, 
            0x28103D4735997B66ULL, 0x244CB6EA89B1CE82ULL, 0x011560BD9675C0E3ULL, 0xB38DA99121E92224ULL, 
            0x12F53C316C2DF9CBULL, 0x0962344ACE4A3E89ULL, 0xBCAFECD9C294A01BULL, 0x602E83D358E04C55ULL
        },
        {
            0xDFC16A8A3D0CEA64ULL, 0x721A0E2F0A659450ULL, 0x8CF9E26831147AF3ULL, 0x4F631BC90470542AULL, 
            0xF81677573E365178ULL, 0x0D308E63AC2337C8ULL, 0x0F452055A6799DCEULL, 0x9FF8DA803D22A543ULL, 
            0x46684FB8825C4F31ULL, 0xE1BB530F5F512C1DULL, 0x78557D3D15A57B74ULL, 0x672240EEB1C768EFULL, 
            0x0A1AE699FCE26093ULL, 0xFE2D47A6C384EFC1ULL, 0xF248905A8630AFAFULL, 0xFCC306D63D1D47DBULL, 
            0xBA82476F0301F73EULL, 0xC3698E5CF8335221ULL, 0xE511449E4FAAC9A3ULL, 0x21AD30A141E798D4ULL, 
            0xEDCA220102B352B7ULL, 0x50372A3CE6C5F1E6ULL, 0xB0BB648BEDB561FCULL, 0x863D7E84E12B9571ULL, 
            0x8D142FAB2DA4ECB8ULL, 0x82DBA289DF6DDCF1ULL, 0x17604E715DD00504ULL, 0x77271BAED92D3885ULL, 
            0x30EBD3D1A9C3ABDFULL, 0xC90FED3F61D73564ULL, 0x3C598A16DA483AA2ULL, 0xC6C871784148508BULL
        },
        {
            0x27B2D5B41401348EULL, 0x0F7382201535D338ULL, 0xF82877DF4897D7CCULL, 0x245A2835DDAC47C6ULL, 
            0x4472E97BD3F13EA7ULL, 0xED29CCCB9AADD4CCULL, 0x227A1FD60C87A8EAULL, 0x061F63B268DBB112ULL, 
            0x40856F8F8E8B2181ULL, 0x73AD15456ED0AC86ULL, 0xF755CD1CDA1D81FAULL, 0x19131C0C3B286464ULL, 
            0x3F5DE29CB4922E69ULL, 0x590F65233818580FULL, 0x503B08D248899180ULL, 0xF6ACC696235E7EADULL, 
            0xD3F4573797F20130ULL, 0x12A4236E95A8F4AAULL, 0x3BCA5F8AF5D562B9ULL, 0x22EDB884572AB223ULL, 
            0xEAC3E4A76F7EBDAAULL, 0xCE3B469C91437337ULL, 0x210C25D0580A386EULL, 0xFB88D854CAEF9011ULL, 
            0xE23D296EE18FCB71ULL, 0x548C3C55C0E94A82ULL, 0xAD2C9DBC4842F9C8ULL, 0x774971A87F547AA3ULL, 
            0x10976F22D6BBE341ULL, 0x8070281850CCDBC3ULL, 0xE822C0F1D022F277ULL, 0xDDC2E7D2827CB45DULL
        },
        {
            0x0A93895607DE7A32ULL, 0xC8C07FA464C00F48ULL, 0xE0918CDC4C64D161ULL, 0x0A5D1BA23A8C61C1ULL, 
            0xFCBE730C01AC8EDFULL, 0x6C6C4BF982413F39ULL, 0x434C58ABF1DD9120ULL, 0x535415016FCB3540ULL, 
            0x38DC85389F8249B8ULL, 0xEC2A86F5E28A9B8AULL, 0xD466E16B6EE3182FULL, 0x9D968C6EF5BCF7AFULL, 
            0xED0283FF087053CBULL, 0xA76BED5C4562CE8DULL, 0x3F7756B86486148CULL, 0x772E38797C183823ULL, 
            0x788981711BF51119ULL, 0x52B6327658BA8A3BULL, 0x91A1A0EF1141D89AULL, 0x41241FC021847339ULL, 
            0x5FDCAFBE9652C9AFULL, 0x723730E2E8766BC4ULL, 0x24CF6424760265B8ULL, 0xFFB5CA095D57C26EULL, 
            0x195F84D0B4ACF8DAULL, 0x1E44EC1AB0543E9CULL, 0x75CB9EA4C9442685ULL, 0x19C5395C66A24FEEULL, 
            0x240A5B7C0F77C1B2ULL, 0xA70DA347C56AC9AAULL, 0x16FE779107AD72BCULL, 0xBB4ED73979C53F4AULL
        }
    },
    {
        {
            0x2E7B6607636E34DBULL, 0xB24471E1AB2D8B60ULL, 0xBB57C06254347DEFULL, 0xEC0A31858FCB1EE4ULL, 
            0xCED50495F0C5717AULL, 0x6DE3C901C7AE5D12ULL, 0x2D3561383C9061E1ULL, 0xB677984479ECB41AULL, 
            0x3C41104680F7E93AULL, 0xCC09A00C35233793ULL, 0xA9014D32C7B6ABC3ULL, 0x057C62805A7A9CBEULL, 
            0xA44573A79714888DULL, 0x72D5569F1D3BA48FULL, 0x0C6763B2F9F14C24ULL, 0xCFD0738AB7DEAF77ULL, 
            0x8AE2C2207F4D6673ULL, 0x3FFB0D4C2459BD8DULL, 0x62A07653C3EA37E0ULL, 0x42E7D427AA4FCDE9ULL, 
            0x454AA4CF01421530ULL, 0xC016383B43C6DA2DULL, 0xC43BF409AD3D63D9ULL, 0x531B59F5794F85E4ULL, 
            0xD7FD78817E6F5DEBULL, 0x5BBE809B3E2566FAULL, 0x2C843B94D3582EB8ULL, 0x406DBFB4737840EAULL, 
            0xA3BE6943E4750877ULL, 0x8D572DF3FECDA4A2ULL, 0x94CC6E8F33691173ULL, 0xCCFBA04252ABDC90ULL
        },
        {
            0xD11D3CDCBCE311A7ULL, 0xFB883494EEDDCF5AULL, 0xD229B05D0F9B51EAULL, 0x4E04CB634589F0E5ULL, 
            0xBA5E662E480BC63BULL, 0xDF45030E5EF6120DULL, 0x26D836D12923B34DULL, 0xBDAD758DE1FC3DA7ULL, 
            0xB58C0D69F0EB87F1ULL, 0xDD40C9C4A66B1157ULL, 0xFECE0FC34DDBDFFCULL, 0x51F84E67530379B8ULL, 
            0xF15752C13576CFE7ULL, 0xCB4C7054031D32E2ULL, 0xA71E5A4C15305140ULL, 0xA433243190314E0BULL, 
            0xCAB61FC9020B1CEBULL, 0xF728E2EF8FFF265BULL, 0xD47DE8728BF51168ULL, 0x6006416789A1C326ULL, 
            0x52993C528D1EAFDDULL, 0xD3B2F70B94F37A5BULL, 0x01DA2B1ABD9A584BULL, 0xAB34103113B5245EULL, 
            0xA3C089C309622903ULL, 0xD7C4D770C7DAE412ULL, 0x1FF5BDE3BA6692B3ULL, 0x8E5945ECA3F30C7FULL, 
            0x576F2DF28F59D4D8ULL, 0x20A3353A64A97A64ULL, 0x553E4E03EA5EC474ULL, 0x9243CF60A2FC5511ULL
        },
        {
            0xF5855B407A8F12D0ULL, 0x482FBC56DC03DC3FULL, 0x23F5F8CCF0EEBD58ULL, 0x84B23452F779C420ULL, 
            0x12C9921750F40F94ULL, 0xADEA29C568FD5B5CULL, 0xE0CEB50A647AF026ULL, 0x996AB93AB0A622D4ULL, 
            0x9EFEAABAE0544FD5ULL, 0xEEA49DE0326ADC15ULL, 0x53B2CE2F428154B4ULL, 0x9704A00D79B96F2BULL, 
            0x3808634CFB554CB6ULL, 0xE66E46329FA829C6ULL, 0x251A4A8BA1D3C6C2ULL, 0x7ED5D225B681A810ULL, 
            0x723B1BCD47A3B6B2ULL, 0x0296EADB4282FD42ULL, 0xD35C40D273B55068ULL, 0x5A7EDB644E483E56ULL, 
            0x1E0D0FE2630BC479ULL, 0x6EBFB5BA70C58455ULL, 0xAB60590A60117031ULL, 0x46454D314D5B1C32ULL, 
            0x9B7E8068AAFC451AULL, 0xB6F2AA9ECCFC9D8FULL, 0xB262B877A364607EULL, 0xD5BCF0F8F9B6E2FEULL, 
            0x372DB17FD2751CD2ULL, 0x128532B381F72B81ULL, 0x96DEE1BA5798929BULL, 0xC58D3EAB9DE164E4ULL
        },
        {
            0xC32E5885E8A857ABULL, 0x2E7B6A156D5F5F4EULL, 0x890E6406E0FC5EE5ULL, 0xC3EA18E6DB305ADDULL, 
            0xC372A87BC5BC106FULL, 0x6DACA92DDF74748CULL, 0x214F7A951308DE7EULL, 0x4F1CC2C1A9196A36ULL, 
            0xDE2F5D0F19D87BAEULL, 0x6371F208251EFFC0ULL, 0x689AE419FCB76D67ULL, 0x55E79B835E511542ULL, 
            0xC0B15D63B0006617ULL, 0x64118E0502CAAF16ULL, 0xE50CF061C0E45257ULL, 0xBA56D621960B2D92ULL, 
            0x974D17E10A686B64ULL, 0x7D0582A9A3A6AC90ULL, 0xB70B9AD8341BEB8EULL, 0xEF5EEA480704FC8EULL, 
            0x8ACF3B1428861726ULL, 0xCFE240D8D88D459FULL, 0xB5106E1A48CCC5E9ULL, 0x48FBCF4711333F74ULL, 
            0xDE2358F974D62A32ULL, 0x2FEABBB99CF2CF67ULL, 0xA9E524B663B8CB22ULL, 0x4A1BF08F3CE5B4B9ULL, 
            0x2704955439ECD65DULL, 0x808FDC4446A25C0BULL, 0xD58698C1F728CE7FULL, 0x59B994077AA1C349ULL
        },
        {
            0xEDD5AEC2337CF7C7ULL, 0x7272812CE5BA335EULL, 0xE609F9F1FD3F96A7ULL, 0x73D7CD03840A418EULL, 
            0xEC59682BFE5A8D9CULL, 0x718CCD4C144C08DAULL, 0x6132CBA2A5C16236ULL, 0x2C2351E7ADFC9154ULL, 
            0xEBCB08496DBAF2C1ULL, 0xFD0D9BBAC1F2EB26ULL, 0xAB4D3955913D8733ULL, 0x0A7EDE891EFFAE3BULL, 
            0x5131AD5FC935B87CULL, 0xB3C7E4C2CA2A58C6ULL, 0xE5C3D39BF88A01DBULL, 0xD0F8B441156F7E6EULL, 
            0x81CD7B8E60FC2C4DULL, 0x359C680D6A12E22CULL, 0xC4FA8C45DF5D2DF6ULL, 0x2E63EE859B604B2EULL, 
            0x581A402ABB9277C0ULL, 0xD3C9CCA15D62F620ULL, 0x1873718EF6A5707BULL, 0x083975F285970C9AULL, 
            0x142C7E65CCFF200AULL, 0x052CEA1A4C40833FULL, 0xCB5EB961AA0C0DDDULL, 0x4BCDFC0A242CB9C3ULL, 
            0xB3F392286E1BB040ULL, 0x50FB7F70B2829204ULL, 0x942CAFDC5C125D62ULL, 0x33AD0A5A25C576E8ULL
        },
        {
            0x3EDB5EBEFF360907ULL, 0x8BF392A4FEC12143ULL, 0x883338D37E4499F1ULL, 0x1D3356E83BC3CB21ULL, 
            0x413E3ACFF276651CULL, 0x4F9964932157F949ULL, 0x29D520112A9EF834ULL, 0xE81D4FCA36290388ULL, 
            0x86FE9168DC6E09D0ULL, 0x3317C57B263FD1E3ULL, 0x0A4349B9A2E6E46EULL, 0x7F3538B134B2B608ULL, 
            0xF18030508DA94026ULL, 0x04B0195FD372AD98ULL, 0xCAFE2C70D44BAE66ULL, 0xC620D46F91A72B11ULL, 
            0x2ED66818EBF895C6ULL, 0xA85BA1C4C7730033ULL, 0xE5E95A9524749EBFULL, 0x536FCE526C6B242EULL, 
            0x89F365D54A16C468ULL, 0x46A5CBDDEF957474ULL, 0xC0D9FB274BEA1EA0ULL, 0x52D86DE9E04543CFULL, 
            0xAFFF8F89B9F48F5AULL, 0x3464ED8BCC1C3B2BULL, 0xCAC4E7E1B2A06656ULL, 0xCEAE9C0F2FED614EULL, 
            0x2DFE5064DC235ED5ULL, 0x3377605154B67149ULL, 0xB951ED06D935CF60ULL, 0xB98B4DC20C1F48A6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseGConstants = {
    0xB68DE9D7E1BDDFA1ULL,
    0x885B4372A40FE42AULL,
    0x73A7225D3FAEDD4CULL,
    0xB68DE9D7E1BDDFA1ULL,
    0x885B4372A40FE42AULL,
    0x73A7225D3FAEDD4CULL,
    0x76BE1AB48E145DB7ULL,
    0xFA059F0BE159F95FULL,
    0x61,
    0xC5,
    0xD9,
    0x2E,
    0x57,
    0x0D,
    0x1F,
    0x43
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseHSalts = {
    {
        {
            0x235C279A7B92DA70ULL, 0x6AF47C6BA82D8AE9ULL, 0x46F9476F929D995EULL, 0x1A53FEB9DD4A62DEULL, 
            0xF864570BED1298EDULL, 0x52FE7E6AD5086282ULL, 0x330B9F00E1C4D8CDULL, 0x8507E06B001624B2ULL, 
            0x13462CC689629CECULL, 0x5FD374975B8929B8ULL, 0x849602143E609146ULL, 0x3E2EC83CF03B49E1ULL, 
            0x6C2E285D72F211C2ULL, 0x7D6BDDF581D86523ULL, 0xBE72AD2A2F52F48DULL, 0xC0616A6654E5CD66ULL, 
            0x5A6AF45CE8CC4DFAULL, 0x0AAA56976B750E09ULL, 0x283EEF3E5B16299BULL, 0xADE9D8F9C63AEBAEULL, 
            0x6AD5D9D356D26F80ULL, 0xAA8C6F328A2E48F2ULL, 0x381DA9B15AEF0227ULL, 0x1A7D669DCCDC4658ULL, 
            0x974A930460B08762ULL, 0xBFB31CDB518476D6ULL, 0x05D4C62F72418D08ULL, 0x43737FAF5480EA34ULL, 
            0x291E7A5AE2C59096ULL, 0x44FB3A632FC354C5ULL, 0xD0B233FFA383FC62ULL, 0x1F8A2108BD47D829ULL
        },
        {
            0xD2DC6C6437E15AE7ULL, 0x05059EA8E98C36D8ULL, 0x31DD4D7AD60D710AULL, 0xA04B84B77A848687ULL, 
            0x5B2D29B3EA5B8D89ULL, 0x746A3AEFBEB49FFAULL, 0x260E8713F2C4554FULL, 0xE4E7AAB8ABE4F71CULL, 
            0x304F14D86D5D3B99ULL, 0x281FEE48C94BD368ULL, 0xDD709F0BEE9385F2ULL, 0x584D69B7F6E5AE9AULL, 
            0x635C3FCE6C5294E1ULL, 0x37AF1206C267CDC1ULL, 0xEED30F339DE9EEDFULL, 0x354220356137710EULL, 
            0x07FFEB8F7A2DA522ULL, 0x20BFF645CB3500D6ULL, 0x52F482D81B07D729ULL, 0x15DF56FCD310CD98ULL, 
            0xAFBE58DA1E037183ULL, 0x5B50D7A3E3D967ABULL, 0xF96FD3A343F727D4ULL, 0x20098EB1EAFA18E4ULL, 
            0x2E05FD352267B8BAULL, 0x846FA1C7275BC03CULL, 0x558A79ECD5D67B2DULL, 0x4D44A0D46526A76BULL, 
            0xEB1B27D080C50376ULL, 0x3055591694280456ULL, 0x37EE1DDA366212D9ULL, 0x958CC161BC8A0870ULL
        },
        {
            0xF4D23B74376456AEULL, 0xA393945CF8A19141ULL, 0x792E451227CFBB5AULL, 0x2799E29A04877F93ULL, 
            0xD2F2FF36464CB0A2ULL, 0x00F68EAE0240AC56ULL, 0xE60E165247055CF2ULL, 0x0AA886E5639FE697ULL, 
            0xBD6EE1E9B7D76E0EULL, 0x47E245575CD8DF29ULL, 0x2FE086A8B67EC4BDULL, 0x3954177F92D7DA22ULL, 
            0x839329B610D2E01AULL, 0x782502E7E911C5C1ULL, 0x7E115480C6726710ULL, 0x161431307C6B8E1CULL, 
            0x2CA655828A991C1FULL, 0xE5DA3BD1EC7CE4A4ULL, 0xB7ADCA3120026858ULL, 0xFB9C5533DEA5CCBDULL, 
            0x8AB165E98B299B70ULL, 0x7EFA4344C6BE7A87ULL, 0xF1B141118B968B70ULL, 0x76E519366C2BFFDCULL, 
            0xA8A43A74C1B5B952ULL, 0x7187E557FEDA5116ULL, 0xC02590C9EEBBDC80ULL, 0x7D52A13343B0C8F1ULL, 
            0xD2D23C1CC732A0DFULL, 0xAD9DD36C6ABDF9ABULL, 0x9F21458DE3415EA9ULL, 0xC1D8BAA6FFE6DE70ULL
        },
        {
            0x8CCEFEAA08B94CB2ULL, 0xFB18E3AE4E6F0762ULL, 0x93F38AFD2682B7BAULL, 0x0C23A248D8562ADFULL, 
            0xB22E52DC945F5896ULL, 0xC85356770E1D1952ULL, 0xACD1D16DCA87CD50ULL, 0x7D9657DAEE3ADDC9ULL, 
            0x5767493A767DCE50ULL, 0x715654A9E6CA7BE9ULL, 0xBF3AF85AD89FBC5DULL, 0x7342FB4E6C2232EAULL, 
            0x0A0E8AB9ADBC41B1ULL, 0xD860BD68147B6D5AULL, 0xBD138911F4B2FE29ULL, 0xCF9F798D6FF27A57ULL, 
            0x1EFB90B49C74F5F1ULL, 0x7EDF2C6D484C600AULL, 0xA5E65A04D1FB4D4BULL, 0x4D3BF26E5060923FULL, 
            0xC64485EC70EE6B24ULL, 0x00C93425CA656B4CULL, 0x446157F79571B882ULL, 0x5DE4615D2246E805ULL, 
            0x6926EF7C22993894ULL, 0x6A9C1942B529C2DAULL, 0x02474F951C0E557EULL, 0xF42FC8640C834CB0ULL, 
            0x6E658FC7682F26A8ULL, 0x6B7A25EE978430CFULL, 0x20CA1768B07A7A34ULL, 0x43AE001F9A5BB5A7ULL
        },
        {
            0x3C294B2876FADD10ULL, 0x7043706472C54A46ULL, 0x859D7CA9FC013616ULL, 0x774186904A217D45ULL, 
            0xD825DBC9A3D3FC65ULL, 0xE842C1401657D0F1ULL, 0xA30EFD985F8CFA43ULL, 0x7F942BD9647BDF9DULL, 
            0xE531B63FFF4CB0D3ULL, 0x17C76C96EB8B6B0AULL, 0x8FD8DBF3DA06A9FAULL, 0x40CFF965E2B94F6EULL, 
            0x6F246840F4460484ULL, 0x775CFB109C0DD0F6ULL, 0xC97DD8BFB4EF0B82ULL, 0x8DABB7F7891C84F6ULL, 
            0xB3AA1788E9D3EF4BULL, 0x9EA6E56D1585111EULL, 0x8FE5831B5CEF1DF4ULL, 0x1B8EAF8D47FEB28FULL, 
            0xCC94728D8A4EDC9DULL, 0x968A5E3A58288F51ULL, 0xFD3D0A3DE0B9FDB8ULL, 0x176350B5BA4BDD29ULL, 
            0x008DCD0CBA5CF577ULL, 0x360F2AFC6B440492ULL, 0x4F48324173AE4AA3ULL, 0x84C75214D85E4248ULL, 
            0x1571B34391F0D6DEULL, 0x093A6897E7828BF9ULL, 0xB5EF00D0211D683CULL, 0x85E02AAF2B038B2EULL
        },
        {
            0x67EE7EB4439A7574ULL, 0xE27611958419DBB8ULL, 0x337007C4C7B1062AULL, 0xFF3C2E31AD34E9ABULL, 
            0x878E8CE67EEA1750ULL, 0xD5AF4C06F485EE15ULL, 0x3EBDE29C540E2C08ULL, 0x1B9CE8775C3AAF5DULL, 
            0x072D2911C74C8E7FULL, 0x0E0927870A4272B6ULL, 0xF15EF2842BF76F69ULL, 0x00D7AD0267EE1F25ULL, 
            0x6621E6B8D247C605ULL, 0xE3C7ACD6AE940C39ULL, 0x01C965776241D08CULL, 0xDA71EC7F3DC3579CULL, 
            0x844AB9D436BD257DULL, 0x12D3365E4FC47621ULL, 0xC78D1F62C1D6FBDEULL, 0x2B11AF6C6C9F6D4AULL, 
            0x9C38845127570164ULL, 0xFA566425AEC2C94DULL, 0x2C7E09C5B2925F17ULL, 0x7B8F71BBB7B00F45ULL, 
            0x670DDA58DC2F58ABULL, 0x9E0C39CEF173DDB4ULL, 0x336B842A91010A64ULL, 0x9EC28B173995BE56ULL, 
            0xB0DA49489DF11D71ULL, 0x10E563758648701EULL, 0x9DDB5BB3A80E8211ULL, 0x80EB51B32511E20AULL
        }
    },
    {
        {
            0x714704AAF804D80DULL, 0xD0354793D02CB1AFULL, 0x7E4F926DA40ABC44ULL, 0x2DB6EF69C77DC4DFULL, 
            0xCE97B6C8E9C27D43ULL, 0x623301FFBBA76F3CULL, 0x77FA5EF5FD040383ULL, 0xC6D2D6C41551400EULL, 
            0x27FDECC51F3E6BE3ULL, 0xE438C949CDA7AB7DULL, 0x79301A6127826BBBULL, 0x91206838302C1B17ULL, 
            0xA193F944A01FE8FBULL, 0xDD68B55E113320D8ULL, 0x0E542830E7F51773ULL, 0x261992DA43D4343FULL, 
            0x4E426F5778AEA7D1ULL, 0x0FD322AB915D1355ULL, 0x881DF70275D5CCFCULL, 0xA016125424BEC590ULL, 
            0xC27E148E65C353C5ULL, 0x213CAC948678D424ULL, 0x8C897CC8F470E155ULL, 0xBF5F2FA614EB3C0AULL, 
            0x7C19DE711DE8445BULL, 0x1E6A26FAD3E6CBC3ULL, 0x9AF577DAC7DBB423ULL, 0x1AE3B475AE6C7150ULL, 
            0xA97CE6989FAC4EFAULL, 0x05149B84F91CC642ULL, 0xB117C181CAE26299ULL, 0x99E5331259883552ULL
        },
        {
            0x99ED48725A443E17ULL, 0x318AC0B6030199E1ULL, 0xF1E8A3E128DD1BE0ULL, 0x299B2C34CD066DB6ULL, 
            0x0413049FDD5F77B0ULL, 0x8A9311F674C77774ULL, 0x3D6AAE5F8EDDD15EULL, 0x2DFEECB011B8D525ULL, 
            0x9DF20A4E377006FFULL, 0x848D39797FF956CEULL, 0x74A743F885A09743ULL, 0x307A9BF3E356C193ULL, 
            0x9DD62836CF031B23ULL, 0x2DB53951D3C17C25ULL, 0x773D0DB7B3B01D83ULL, 0xE900C1B9F17C9F0FULL, 
            0x4010E8D8E48CA025ULL, 0xC690BABA50E6DFF4ULL, 0xA881A4A36BBCC8CEULL, 0xF99A8955E26775F1ULL, 
            0x6406C8ACA4D84D9BULL, 0xD70754381C98B99DULL, 0x58AC30EC5954CF1BULL, 0xE23DDAE6240CE148ULL, 
            0xD306758BD7BF8440ULL, 0x7D8193F4FEB48161ULL, 0xFC8C8104FBF14909ULL, 0x4993FCDB23067F85ULL, 
            0x61BD7D15344373E3ULL, 0x6F1652CC0F589DD6ULL, 0x00B9CCEC679AAFF1ULL, 0x61AD6F4A73E6B4D5ULL
        },
        {
            0x506BEA9D5E9AEAACULL, 0xBE1089C385E2883CULL, 0x0E3D72ED1CADD4BFULL, 0xDA654D4A225047EBULL, 
            0xB330F49D0AC60A22ULL, 0xB90D78A97CA8E33DULL, 0xD182C42C26D070B9ULL, 0x36587DC4E9CD6890ULL, 
            0x3792C2A100EF462CULL, 0xC6B8536526C83EFFULL, 0x5DD554A670115CFFULL, 0xA557A8E8E3B49E24ULL, 
            0x2D335B4788151341ULL, 0x4F8B7CA7210BADCAULL, 0x68708EE6C0660F9EULL, 0x3EECB32D9060F45BULL, 
            0xD3C04626FB0F945EULL, 0x3A1B623F3DF8716BULL, 0x4B263A49CA0CE9A3ULL, 0x4FACEF7CC584B854ULL, 
            0x943E0F534FE614C6ULL, 0x3AD4497386CA763BULL, 0xABA4D467036382C7ULL, 0x20BE91B61AB5BDCCULL, 
            0x427CBF5A69CE6E54ULL, 0x46FAAFEA46FC5223ULL, 0x608489EFAE689F53ULL, 0xC5B959E58812CB66ULL, 
            0xF05AB34BC65572F7ULL, 0xCB51F10E3BCCE4DEULL, 0xC6C5906E0C8AF44EULL, 0xD2F25F87796CF44EULL
        },
        {
            0x9CEF6A9F79414204ULL, 0x08E83A15F46E6BCFULL, 0x4945DFBDC15D2949ULL, 0xAB9462B570894BCBULL, 
            0x6FA09F6CEDD783BBULL, 0x01BBE6F27D241006ULL, 0x0AEF8EC8B85592DEULL, 0xC8381D1BA6C28212ULL, 
            0xFABF1FC058D4ADB8ULL, 0xE971C03D47186DE3ULL, 0xE802F353C443AFF9ULL, 0xCDA0B7D166A18ACFULL, 
            0x8619BEADFA7263B7ULL, 0x13DD0370BFB8B5F7ULL, 0xE3400B52599EFCD9ULL, 0x195C5D6070E03F2FULL, 
            0x4753D2B1380266D3ULL, 0x627A8FD64AE75480ULL, 0x6939FFCB9E56C712ULL, 0xE6C1A1F2F38A2047ULL, 
            0x2CAA670F8DC3DCD8ULL, 0xD62252ABF2D0CFCAULL, 0xD48814ECBDA06AB0ULL, 0x2017B67680BE7075ULL, 
            0xB071A66900DE2872ULL, 0x3D5ECA3E0AE1DF63ULL, 0x76C1462CC74943A3ULL, 0x42450F66775C1D89ULL, 
            0x53C9AD01F663FB82ULL, 0x1BE00F929A11E661ULL, 0xA1948EA6FD71EF93ULL, 0x07D7DC9FF051C54BULL
        },
        {
            0xC925FAA92EF4D904ULL, 0x297CD4C286EEC0C8ULL, 0x707A941D2F9E2DECULL, 0x87F001701A7AB5DDULL, 
            0xDA221441A76DF2D1ULL, 0x85A131E3F17F8110ULL, 0x59427AA67A175A88ULL, 0xBA6087EE221EEA46ULL, 
            0x648FF2ECABF6006BULL, 0x9B3EA2989103C51BULL, 0xE3395CEC073260C9ULL, 0x7D5191422D1B607FULL, 
            0x72C405347BB01B96ULL, 0x9411FCE96411098AULL, 0x799F548E210BAA06ULL, 0x8F004CC9D22B5CC8ULL, 
            0xDB882420202F93A5ULL, 0xEB6EAB54FB94E658ULL, 0x1BDB3C8FBD4B684EULL, 0x42180BDF601C167AULL, 
            0x91F809E067817382ULL, 0xEECE5D752051DD1BULL, 0x749A9BECB57F0271ULL, 0x10FBD961694245CCULL, 
            0xDD1F55CD6D63D120ULL, 0xF0F2F3327B99E8FDULL, 0x3B41CB44AE6AAD2BULL, 0x798B3D342FD0F38BULL, 
            0x0647416214E95206ULL, 0xA1FF958E0865C9FAULL, 0x3A792B05C1C20255ULL, 0x5512832B4DE7E5ADULL
        },
        {
            0x43E2B94A892817CBULL, 0xA4C8022E61C10F63ULL, 0x016B656561253A57ULL, 0x36E35C97F00E7847ULL, 
            0xAD0E6B317169E228ULL, 0x90C7871F45E5B5F4ULL, 0xD9F3591D50A2F1A4ULL, 0xE4892BFA96AAB5A5ULL, 
            0xE976A9E4810B7CE4ULL, 0xFD62F19733928853ULL, 0x953C914BC2CFE55CULL, 0xF4EB4DADCF3ECE0BULL, 
            0xF9B2B7B39C17BAACULL, 0x079BCD845CC1792AULL, 0xAFEA1C54D8540192ULL, 0x272C0B013C166935ULL, 
            0x5C0B5DF31D63A48DULL, 0xEA3552BBA455D315ULL, 0xEFCE684957565EC7ULL, 0x89042035F4C8408CULL, 
            0xCEC36BBD61626ED6ULL, 0x2CC57DB39184A427ULL, 0xF69B172A31E1803EULL, 0x558A9208AC3FCB90ULL, 
            0x6A1FC44634880445ULL, 0x4CDCAF697889E515ULL, 0x0B7ABC30967E445FULL, 0x45023B04C8E59338ULL, 
            0x9D3084919C2DB78AULL, 0x21C6B97009D8D492ULL, 0x3F2729EAB6ADF21EULL, 0x27CB61856FA66544ULL
        }
    },
    {
        {
            0x5312AC531DBD321AULL, 0x4953C7BEC845D9A9ULL, 0x3A34BEC43D61235AULL, 0x9951AA532FFCB050ULL, 
            0x268A51894FAF06EFULL, 0x92551CC9E0E0A140ULL, 0x09ED635B81ADD3BDULL, 0x6F766E713461BA9DULL, 
            0x5863A112DD1AB456ULL, 0x1D201CC124EE6CD7ULL, 0xF7D81651477CF8E4ULL, 0xAD762DE0081B600DULL, 
            0xBE76F04424B50F56ULL, 0x6DE88E253C5570B0ULL, 0xCF5AE3066413FEC0ULL, 0x8B4ABD48894E4029ULL, 
            0xEAE8B0DDADC9C59BULL, 0x6F1429C42C77A40CULL, 0x7FFCD1CE4F3893BAULL, 0x5EDBA2066B3CECABULL, 
            0x91CF647DD46F99DCULL, 0xE60E5BB8AF7F9978ULL, 0x6790B9E87F347539ULL, 0x2DCA71EC161A7524ULL, 
            0x1CE1E7D0D6188EB7ULL, 0xB20FAFDC8B1AE9E1ULL, 0x2313575371A1C7D7ULL, 0x20150F58A12E36DBULL, 
            0x1DA76E63BB3D552AULL, 0xCAEBA6D4F3097977ULL, 0x8F18A784249DC448ULL, 0x81B37884719D57FEULL
        },
        {
            0xA62630743BF90971ULL, 0xE4BB551108E22283ULL, 0x8EA44C48FF15F294ULL, 0xA8BB3DEC73354A56ULL, 
            0x34AD60E2DCDA804DULL, 0x46D7029BBF45A9B7ULL, 0xE19E2794406F682BULL, 0xB7101A59A27D8D06ULL, 
            0x498CB4E771F4DA86ULL, 0xD1AA58F29BE82785ULL, 0xA0B13F3DDB9227BDULL, 0x404DA65F34755B63ULL, 
            0x7407C55DC6AF6F7CULL, 0xA16286CDCF000384ULL, 0xADABB0561847A46BULL, 0x1FEAF4BC539123FDULL, 
            0x46D8E1B6522FB076ULL, 0xDCEFC7352629E7B5ULL, 0xCAA12BBFFABD1738ULL, 0x4C2FB94CE0865039ULL, 
            0xAAF27ED10C9311C6ULL, 0x852803E776F5E778ULL, 0xAAC9CA26600E6F5DULL, 0x63E2CA78DC1B6772ULL, 
            0x384E477C1A36218EULL, 0x9C83408C448C3CF6ULL, 0x3E710B1FCEFC44A7ULL, 0xECAC6D88BF1937BCULL, 
            0x2CA656C7CB8E2BEEULL, 0x00082D2124297076ULL, 0x199B60985259C192ULL, 0xC955CDD196D65C02ULL
        },
        {
            0x89E9118B7D9AEC20ULL, 0x1CEB01D1AAB47BD7ULL, 0xBF2C74A77655BF5BULL, 0xC14921F8550BD869ULL, 
            0x4F7FC9F7384EFC92ULL, 0x8E66F69A30390D6BULL, 0x47B737C1CEFABF06ULL, 0x0E26BC56C7C6B3D4ULL, 
            0x946035CCBED300C5ULL, 0x3DBA63C0E698E4FDULL, 0x7BA76F4B193B3C60ULL, 0x282956A18485A635ULL, 
            0x98F3F0C8D7473BF1ULL, 0x3903CA406D8A4830ULL, 0x24C7EA7752C0930CULL, 0x761C7E39BE68B223ULL, 
            0x0F1A92EC2A0215DBULL, 0xA55B34DB24ED36E9ULL, 0x89A78E2617ED6950ULL, 0x011D36544B7A3F19ULL, 
            0x49064BDED53B5879ULL, 0x59882488B9D079A5ULL, 0x002EFD5CF7EF4DD3ULL, 0x188195A6A24E9436ULL, 
            0x2237C6A59D9EA91FULL, 0x4EDE8589AC14363AULL, 0x9D237279AFC31CD9ULL, 0xFA71C876BBF162F2ULL, 
            0x1485C3165050BD44ULL, 0x2D30A6F2AFC57515ULL, 0xAB55E84A1FAD4AB0ULL, 0xCC268EBD728BFD76ULL
        },
        {
            0xBC126AF068488283ULL, 0xB9EBEDEF8A6B7544ULL, 0x4503F64BA7102DABULL, 0x9AF274D679887814ULL, 
            0x9DCACBA6EE01658BULL, 0x428C1EB5FF028713ULL, 0x4BB3F8CBAB809AAEULL, 0xDE5F286C2AD49452ULL, 
            0x5C4F2E52FC3F903AULL, 0x9162675D65934CD3ULL, 0xBD98E93E78C3753FULL, 0x5B3F22FA1F1F22B0ULL, 
            0xC8828C3A479A7D6FULL, 0x4B84B2D0C73FE7D5ULL, 0x6D883AA9BE22EFA0ULL, 0xA3245C45A3CA4A42ULL, 
            0xF35076C4345F0A19ULL, 0x7D9CBB119C33111CULL, 0x0243E6F9E0917864ULL, 0xF971FB68E02D264BULL, 
            0xAD42AEAFD55AD910ULL, 0xA2C01A56B4F7AB8BULL, 0xDD6C3A7DF69E7F72ULL, 0x5B3A2B5B59B62F33ULL, 
            0x1FC0E77E8FCE8362ULL, 0x151D6FB350E03E77ULL, 0xCD92ADF3C077B9D8ULL, 0x818DFCE693293795ULL, 
            0x45A60945C303B486ULL, 0x60A543AAC3650B68ULL, 0x0A5DECEA1E5CC816ULL, 0x3AAD11D510887B0FULL
        },
        {
            0x5F952B29846DE9BBULL, 0x26E5F3B915F669F1ULL, 0x2A8C3702C4BDF8A2ULL, 0x7698FCC73CBB7703ULL, 
            0x26612B99BD4C21CEULL, 0x3B1CF7CAE4FDDE5FULL, 0x3340A4D703801710ULL, 0xD7493BFF8B5E4D76ULL, 
            0xA11D0D1A255F270EULL, 0x52FECE00004DBF3AULL, 0x1F68722A0DDEC028ULL, 0xBBF7F0FCFDA8459AULL, 
            0x38973108626F27D8ULL, 0xBEDF9C4E85B8223DULL, 0x9448FCC5EB590E7FULL, 0xB4CD04B4DF36B5ABULL, 
            0xD187B50A3AF40E5CULL, 0xA9185227A4EADFD1ULL, 0x434BAF2E3F1A9591ULL, 0x05AD0E15CE400D84ULL, 
            0xDA57C82BC4324F17ULL, 0x4B74013705494FBDULL, 0xB61FE45861F63FD6ULL, 0xEC50AACA0629C6A2ULL, 
            0x612471AC61876C95ULL, 0xC40BEF874A0BD958ULL, 0x2E77EE4F6CB89B4BULL, 0xA7C1EE116F4D8B23ULL, 
            0x118E42D6513630C3ULL, 0xDE9919121FB3BD49ULL, 0xC5306C60718082FFULL, 0xE7B0479A926FA0E9ULL
        },
        {
            0xE13C157323898957ULL, 0xC4130B6C053F815EULL, 0xA96FBB6356077C77ULL, 0xE8E6853EEEF136C6ULL, 
            0x1B7E80DC48BDF4E9ULL, 0xE0FBD6446DE6F380ULL, 0x735E47BE41E3A8F8ULL, 0x2C68BAF0FC14D874ULL, 
            0xB6D37CD62AF4149CULL, 0x0DF1BAA9D78F66C9ULL, 0x8AA854C8C2FCFC75ULL, 0x303FF220F4835296ULL, 
            0x80FD3A560B7BDFCFULL, 0x05E27CC32D75AB53ULL, 0x3DA97A64C64885FCULL, 0x34A41637148837C8ULL, 
            0x77E5F8B8CADBD692ULL, 0xA422437EA21557EAULL, 0x725C3C1C67F2F4A4ULL, 0x10D7342F7A711075ULL, 
            0xC418968F5D390906ULL, 0xEDB3D3B8D685AB19ULL, 0xA7B3A515E63CE543ULL, 0x6AE5945B926EA0CDULL, 
            0xAD9F41DEF1C57D11ULL, 0x88C18B463AECF1AAULL, 0xBF8CA364531AFB7AULL, 0x893E6FA9B91D08A2ULL, 
            0xA94F6BE41D6CA4F6ULL, 0x008236E1DFC7A59BULL, 0x88FFC7C789604F09ULL, 0x6B0675C2E163BE99ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseHConstants = {
    0x70510751BB175F18ULL,
    0x16FD14F18544C28FULL,
    0x09243678A37B1E13ULL,
    0x70510751BB175F18ULL,
    0x16FD14F18544C28FULL,
    0x09243678A37B1E13ULL,
    0x7468288C0813F416ULL,
    0xE412701C8710A0E5ULL,
    0x6F,
    0xB6,
    0x85,
    0x65,
    0xC5,
    0x22,
    0xC6,
    0x98
};

