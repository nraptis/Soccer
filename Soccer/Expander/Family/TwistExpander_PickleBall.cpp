#include "TwistExpander_PickleBall.hpp"
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

TwistExpander_PickleBall::TwistExpander_PickleBall()
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

void TwistExpander_PickleBall::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xC5A799691AC9B9C1ULL; std::uint64_t aIngress = 0xF0D5156BBDEB3643ULL; std::uint64_t aCarry = 0x88DBE767F87254FCULL;

    std::uint64_t aWandererA = 0xF598FF3F987223C4ULL; std::uint64_t aWandererB = 0x8242874457EBF135ULL; std::uint64_t aWandererC = 0xE0AC398EA9C53D01ULL; std::uint64_t aWandererD = 0xBE8076BA9F50A7AFULL;
    std::uint64_t aWandererE = 0xB8C4468721FD0CC1ULL; std::uint64_t aWandererF = 0xCB9AD075C8C36F68ULL; std::uint64_t aWandererG = 0xC01E3AD62DE1D91BULL; std::uint64_t aWandererH = 0xE6B9138A07C76031ULL;
    std::uint64_t aWandererI = 0xEE7C1D046955FB99ULL; std::uint64_t aWandererJ = 0xE9DE7B2C9B0DAFDFULL; std::uint64_t aWandererK = 0xD25E8DE3608C3AD9ULL;

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
        aPrevious = 11408508658302999573U;
        aCarry = 18100306664723965731U;
        aWandererA = 13074819345231034776U;
        aWandererB = 17634418934896523191U;
        aWandererC = 10483851067191756608U;
        aWandererD = 12225045071516721425U;
        aWandererE = 12300894801123331412U;
        aWandererF = 10898164919602230957U;
        aWandererG = 17898589425819449681U;
        aWandererH = 13536196893135889701U;
        aWandererI = 15572804099691116973U;
        aWandererJ = 12030730363009741541U;
        aWandererK = 13108492035819753581U;
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
    TwistExpander_PickleBall_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_PickleBall::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xFF742757E855277EULL; std::uint64_t aIngress = 0x8B78F06939B323E3ULL; std::uint64_t aCarry = 0xC81F2660737CE682ULL;

    std::uint64_t aWandererA = 0x95F11B1C2EA5618DULL; std::uint64_t aWandererB = 0xB45AEEF703B4A61DULL; std::uint64_t aWandererC = 0xDBFA19121C7DA39FULL; std::uint64_t aWandererD = 0xACEE4376A1F9E135ULL;
    std::uint64_t aWandererE = 0xB20E58711067B0CDULL; std::uint64_t aWandererF = 0xA704291D0FB89FF6ULL; std::uint64_t aWandererG = 0xEEDC5836EDF2D44EULL; std::uint64_t aWandererH = 0xE67EE50CF55DA4D9ULL;
    std::uint64_t aWandererI = 0xEC34B2F3CE0FBB36ULL; std::uint64_t aWandererJ = 0xAC202FDF20C9FABBULL; std::uint64_t aWandererK = 0x98C0C30201376116ULL;

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
        aPrevious = 11752382740933221126U;
        aCarry = 11722284128642173476U;
        aWandererA = 12543444669364772299U;
        aWandererB = 16506566380632058053U;
        aWandererC = 15056377270569014716U;
        aWandererD = 16826391354912087163U;
        aWandererE = 12275933469361032887U;
        aWandererF = 9423535169777114492U;
        aWandererG = 15732652139966761076U;
        aWandererH = 16257073945659682219U;
        aWandererI = 15349371934868886680U;
        aWandererJ = 11707738680818504916U;
        aWandererK = 10921402424871263703U;
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
    TwistExpander_PickleBall_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_PickleBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE86FEB41C962B0EDULL;
    std::uint64_t aIngress = 0xEF44C50B506B2123ULL;
    std::uint64_t aCarry = 0xA2EBE3729D2E271DULL;

    std::uint64_t aWandererA = 0xCB6A46FBAAEBF060ULL;
    std::uint64_t aWandererB = 0xA908442E250236CDULL;
    std::uint64_t aWandererC = 0xA8B1BA9B93EFBED2ULL;
    std::uint64_t aWandererD = 0xEBEAFB0FC5939C4FULL;
    std::uint64_t aWandererE = 0xA48DAB012CAD2285ULL;
    std::uint64_t aWandererF = 0xEAFE55D3FA8160BEULL;
    std::uint64_t aWandererG = 0xD93A1F57865471E1ULL;
    std::uint64_t aWandererH = 0xC7232807541E6872ULL;
    std::uint64_t aWandererI = 0xF7A881F15A6A890AULL;
    std::uint64_t aWandererJ = 0x91DE134CF72EC72AULL;
    std::uint64_t aWandererK = 0xE1E5F58C0591CEE2ULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC, 1);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD, 2);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC, 5);
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD, 6);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistExpander_PickleBall_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_PickleBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_PickleBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBD58488D05152E63ULL; std::uint64_t aIngress = 0xFB13D526E8280B14ULL; std::uint64_t aCarry = 0xED63B449636A57FCULL;

    std::uint64_t aWandererA = 0xE520BCD9F4D7946DULL; std::uint64_t aWandererB = 0xC2E5761D437582A7ULL; std::uint64_t aWandererC = 0xC9724AB31611D613ULL; std::uint64_t aWandererD = 0x9160FB91BDA59C6AULL;
    std::uint64_t aWandererE = 0xEB3F0D40B28438BCULL; std::uint64_t aWandererF = 0xEED42AADF11FB163ULL; std::uint64_t aWandererG = 0xAC177A9C1E6AF635ULL; std::uint64_t aWandererH = 0xFC61926B27810086ULL;
    std::uint64_t aWandererI = 0xD639AF2EDDF2A106ULL; std::uint64_t aWandererJ = 0xE76CAF323B3CD744ULL; std::uint64_t aWandererK = 0xB0B08C0B4E8BE2D9ULL;

    // [seed]
    {
        aPrevious = 12785881212784653186U;
        aCarry = 15372024965333618873U;
        aWandererA = 16151959279273635134U;
        aWandererB = 14366289874220476799U;
        aWandererC = 10762442949607372019U;
        aWandererD = 15169959818334992571U;
        aWandererE = 13038232027634264833U;
        aWandererF = 15686500113323248589U;
        aWandererG = 13860090285023724502U;
        aWandererH = 17833608158174346761U;
        aWandererI = 10149926266119681732U;
        aWandererJ = 16664139329076690379U;
        aWandererK = 15781485987913941856U;
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
    TwistExpander_PickleBall_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_PickleBall_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_PickleBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_PickleBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 2, 3 with offsets 4528U, 7345U, 2267U, 2104U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4528U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7345U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2267U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2104U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 0, 1 with offsets 6761U, 4939U, 1478U, 5592U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6761U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4939U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1478U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5592U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 1, 0 with offsets 7991U, 4746U, 6581U, 146U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7991U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4746U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6581U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 146U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 3, 2 with offsets 1593U, 6813U, 7743U, 2970U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1593U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6813U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7743U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2970U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 2, 1 with offsets 1875U, 1938U, 404U, 1849U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1875U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 404U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1849U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 2, 0, 1 with offsets 1585U, 2042U, 398U, 693U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1585U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2042U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 398U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 693U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 0, 2, 1 with offsets 1341U, 1756U, 1476U, 1232U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1341U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1756U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1476U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1232U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 1, 2, 3 with offsets 27U, 1058U, 230U, 878U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 27U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1058U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 230U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 878U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 751U, 549U, 1195U, 1727U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 751U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 549U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1195U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1727U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_PickleBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 0, 3 with offsets 2543U, 5089U, 316U, 6154U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2543U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5089U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 316U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6154U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 3, 0 with offsets 2769U, 549U, 4432U, 2928U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2769U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 549U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4432U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 1, 2 with offsets 5757U, 1301U, 6648U, 4830U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5757U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1301U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6648U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4830U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 1 with offsets 4911U, 4048U, 4422U, 112U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4911U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4048U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4422U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 112U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 744U, 4930U, 4290U, 1933U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 744U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4930U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 4290U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1933U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 2011U, 1471U, 876U, 720U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 2011U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1471U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 876U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 720U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1262U, 411U, 777U, 198U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1262U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 411U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 777U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 198U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1444U, 813U, 207U, 423U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 207U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 423U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1708U, 1693U, 1607U, 3U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1708U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1693U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1607U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 2, 3 [0..<W_KEY]
        // offsets: 551U, 784U, 1769U, 1601U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 551U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 784U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1769U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1601U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseASalts = {
    {
        {
            0x5146A4008F6786C6ULL, 0xC5132970C6A72CC7ULL, 0xF6BF6003F000D28BULL, 0x2F31409522DA885BULL, 
            0x8DA93D3B04045A2AULL, 0x7FD85DF04B8C23B2ULL, 0x29EF9A4FFD4AFEE6ULL, 0x87B564A6F131DC2FULL, 
            0x46579DDC2C2F6DC4ULL, 0x9750B358555653ACULL, 0x1E8AD099D5E27072ULL, 0x4BF26562CDD7D127ULL, 
            0xE836B9C939771E17ULL, 0x47ADE93B900B43C3ULL, 0x790EF892A829771AULL, 0xCAF9111CB8628C48ULL, 
            0xE6FDD3E1A8FF5A54ULL, 0x0AD3B2EC2A57F0F6ULL, 0xAAA0C0005A1C2B03ULL, 0xF4EDA25A732EAEF9ULL, 
            0x2FCFCCC9A8D11BA4ULL, 0xD5D6677D3DEEFD71ULL, 0xD4917B25ACCCC50CULL, 0xF1BB595D9AA890EBULL, 
            0x73E5BF8B52DEF90BULL, 0x4664813DF2089DCBULL, 0x11012AD9C13ACAB1ULL, 0x43811C9DB53A4620ULL, 
            0x2B348B03CBAC460BULL, 0x7CD838C73EA1058CULL, 0xEA8324EF3260AF1EULL, 0x4402AD68CCC5420EULL
        },
        {
            0xA8FF1F2B8008E86CULL, 0x21C36214011A08BCULL, 0x1BD31576F309AB8CULL, 0x739BFAA9055A8836ULL, 
            0x9969E4357E2A4D49ULL, 0x89D3957DA8AF49F4ULL, 0x75CA7B747F7C3300ULL, 0xBEB00C32183EF907ULL, 
            0x5AA4019808D716C6ULL, 0x7841C28D55A2F370ULL, 0x0E4AC97F465E9F8DULL, 0x8ED4F12BDDD9F2F4ULL, 
            0x90B0C573A6D33E4FULL, 0x6C81D5A57E17755EULL, 0x533D8E1869896ED5ULL, 0xBB049F18F37F3F18ULL, 
            0x676509A04364C384ULL, 0x0C565AA4CB8D7DA3ULL, 0xAEAF3D77167A879EULL, 0x5FF7F6C87FBDEE2CULL, 
            0x0DA7A9F2BD4199D8ULL, 0xDA6EEDFAE110CF35ULL, 0xF74AF60BDC040729ULL, 0xDDCAE8BAB3E09997ULL, 
            0xBF9621C4620019F0ULL, 0x3073CD0AD384E09FULL, 0x66CDF66C7084899EULL, 0x048FE44FFE6D1977ULL, 
            0x9615827D69A1BC85ULL, 0xB1642A1838A19AEFULL, 0x0C494F8A4C239F26ULL, 0x9C626354BEF9951DULL
        },
        {
            0x09D0DFC7AB4D3347ULL, 0x2BC61183E34D5D0EULL, 0x4D415A4A6AEA7B3FULL, 0x2B33EB402E6064B1ULL, 
            0xE59669C1167446A1ULL, 0x955F6402924D884EULL, 0xF7C4450D6A3363FBULL, 0xB3CF88777C97D9B0ULL, 
            0x958ED43083550D6AULL, 0x5B851FA8AB33DB0DULL, 0x568ACBE2E68540D1ULL, 0x15E02FC2A04FDB48ULL, 
            0xEF5E2EA590317DD7ULL, 0x33E140922C776603ULL, 0xD12473BDB4F62811ULL, 0x64A461FFF977CAE4ULL, 
            0x74C49AA3BDD792E8ULL, 0x2F5F336B6353FA29ULL, 0xED425B89DCE159D8ULL, 0x09B2B7906E6A5DAEULL, 
            0x6F8386B3191A8947ULL, 0x780E8FE19DDA4A8CULL, 0x81D25BA1E8FFDDA4ULL, 0xBCE3AD155DE4D93FULL, 
            0x10C4C476345A40AFULL, 0x2D8740BD60995AA7ULL, 0x887C09758A5A1869ULL, 0x00937B0D6F1EADEFULL, 
            0x97DFEDA81FC5675FULL, 0x7A347C8CE438E499ULL, 0x4B4AC9CAF013A7E0ULL, 0x4EE34ACDF7711DDBULL
        },
        {
            0x4FBA48B819466C1AULL, 0x871368C26E442B9FULL, 0x4910E99ED2E8297AULL, 0x5754788CC4645AA9ULL, 
            0x7DE4EA8D803E97F3ULL, 0xBBC2DB8289F51952ULL, 0x704EE4CDAA4DCCEEULL, 0x2D456208EA8641E6ULL, 
            0xF42412807384B23BULL, 0x6A79200499D517CDULL, 0xE311F036377FB018ULL, 0x3EB86F73C013CD40ULL, 
            0xB6D78E280B248C8DULL, 0xB90F2C51D0DC7A12ULL, 0x71BBCA52DE8B2A30ULL, 0x9C7DC47AADFE5FEAULL, 
            0xC76AA7AA744A892FULL, 0x38046076094AF68CULL, 0x38CFF58C5AC30690ULL, 0x70D7383009F11AC0ULL, 
            0x190165018FD70F8BULL, 0xDB241FA871BBB275ULL, 0x28ABCF7921B6F106ULL, 0xCD607CDDF81658CCULL, 
            0x9C41C5988CDE4CCCULL, 0xB87B11564BEB1008ULL, 0x8D497B9506E52BE7ULL, 0x357CE30D2BFB535AULL, 
            0xE8C974DFF4743047ULL, 0x60370690E623E231ULL, 0x85DEBC3446974432ULL, 0x32DBF026E33062DDULL
        },
        {
            0xEC416B4178901CABULL, 0xE45CC63BF74D405AULL, 0xA207FB3C9E971D4EULL, 0x4358760C2F5B771EULL, 
            0xDDF851FC2AE4F644ULL, 0x920F4DA064EDB24AULL, 0xAFDC3D8EA39018B0ULL, 0xDFF1F6F84E124760ULL, 
            0x5F3A8C04C2A889D8ULL, 0x841D6ABE9B68D22BULL, 0x1CA22AEE82802A9EULL, 0xC2ED53ED596DF070ULL, 
            0xCB0508A942B1FAACULL, 0x470DA7E572072D0EULL, 0x662A23A37327D2FAULL, 0x04880A9C3245DF8FULL, 
            0xC9CBE4D5831CA14AULL, 0xC1DD742C4F4A7DC9ULL, 0xF4F95A90885DD7EEULL, 0xBA7977560301D85EULL, 
            0x3B19C504A8FF213AULL, 0x2F03D8A48F3DC954ULL, 0x2AAB9FA637C773FEULL, 0x9DE535CD0724E83DULL, 
            0xC636EC47DBEC19E6ULL, 0xED2E06BF8C324409ULL, 0xFB05087AFD67C069ULL, 0x3A1E51D3CDA9DDB8ULL, 
            0xEBB5A985F89774C3ULL, 0xED569D72F5B7C891ULL, 0xFF8B250EF55BB39DULL, 0xE8AD7EBD5F82DD4DULL
        },
        {
            0x62A85E1644A04A97ULL, 0x73A869F4082E4182ULL, 0x4BCC173E70958A97ULL, 0x0335D8075A4BFC61ULL, 
            0x6D0600C0D662ECB3ULL, 0xB0D2E9B3AE2BC5E2ULL, 0xB20D88DA941AB93AULL, 0x5CE4B2CEAEA36C34ULL, 
            0x4B258958AD43C469ULL, 0x0B416CE6AB0E0FDFULL, 0xE88C856405AA8155ULL, 0xB7C9C54BB5184AC5ULL, 
            0xEF1F4E0949BD9DD6ULL, 0x42AA74DC87461106ULL, 0x4396954E86C5EB2EULL, 0xE72CB38B9158DA4FULL, 
            0x2771B961CCC46F5DULL, 0x9F69608B99D6F581ULL, 0xC65F701455BF7FFCULL, 0xB6AF75AC37B7925AULL, 
            0x045DA69A94C288B8ULL, 0x1363A529BCDF37B3ULL, 0xB78B2DCB426C681EULL, 0xDFF0464C746CA5F9ULL, 
            0xD0A230E13C4745CBULL, 0x54257FF4B9C24934ULL, 0xC1F5736F82070FE2ULL, 0xA63FE8D3FE0BD493ULL, 
            0x6B9B792FB5573E1AULL, 0xD37A33CCBEED443BULL, 0xF65248D2EFEEECF5ULL, 0x6A1348C9372582A2ULL
        }
    },
    {
        {
            0x45F6857AE8B2C637ULL, 0xEB07F6E221401983ULL, 0x854A793B3A6D9921ULL, 0xDC83802BEEDEB5E8ULL, 
            0xA8021073D58D32AFULL, 0x3D897D670672C07EULL, 0x943A7C32D7C7A62EULL, 0x1AF414C4E5E5E855ULL, 
            0x09DA44CC65DC8F39ULL, 0x6F436E35A5D60E42ULL, 0xB1A7E9E6723053B2ULL, 0x2CDE47B12039DF59ULL, 
            0x837D00F3B974CA62ULL, 0x1223D03F4D52D25AULL, 0x3959B2F8175C8024ULL, 0xD67108B5CF51CF79ULL, 
            0xF81848968C10C9BEULL, 0x95B572B16097774DULL, 0x9CD7AAC0F8DA219FULL, 0xBAC511D8505597BCULL, 
            0xB44B6E3B45B52590ULL, 0x139BB943F09B57B5ULL, 0x9625AD895889F4C3ULL, 0x237DADB72FB2AC1CULL, 
            0x45D813732F9CF1FAULL, 0xF284A6BC81F7C8F0ULL, 0x3A71071A78CDBFC7ULL, 0xE44B5B5228FDFF1FULL, 
            0x8C4A8BC5B99091DAULL, 0xBA5FBFF0B04F6520ULL, 0x2783ED05B42A821AULL, 0x18CD06BE1567B415ULL
        },
        {
            0xC20076A9B2273E2FULL, 0xF2A05CA5A016EBC4ULL, 0xC93EBD8005A7EA15ULL, 0x8EF7FDF74B21C6B4ULL, 
            0xD5B9378851E0FACEULL, 0xF9FD40570E44D542ULL, 0xC91B5A7631C6C319ULL, 0x6C521C65FACC730FULL, 
            0x38E81FBF59AB0B44ULL, 0xE717C90CBEEE9C12ULL, 0x7FCC279023DFB0F9ULL, 0xC61CC62DF1ED14DFULL, 
            0x1F2C15710A6A2866ULL, 0x3473FE347DED3504ULL, 0x0E10F3C71084F074ULL, 0x09B9E443D5750EF9ULL, 
            0xB59661545A1A837EULL, 0x9CA6A161636FF4EFULL, 0xFE26340BB1B47C12ULL, 0xAC231D0D8F9C698AULL, 
            0x64765C693F283FECULL, 0xA094F92C136F35CCULL, 0xA001FCAE3C7F55CCULL, 0x600871646A3B45E0ULL, 
            0x30E9B58243A39247ULL, 0xA804CD1D086AC877ULL, 0x686433E830788B6FULL, 0xD0782B4410388BEBULL, 
            0xB7229B985C7F5D19ULL, 0x029018026B4BD474ULL, 0x5AF96036BB82390CULL, 0x1972BC174DCF9841ULL
        },
        {
            0x8F3076AD6848E01BULL, 0x47575C9C5B313A5EULL, 0xB903BF8221EAD6F3ULL, 0x6F1879423219D1E7ULL, 
            0xB6A072370959DE98ULL, 0xC5CA779D15DD7FBDULL, 0x7086F5FDD8447D05ULL, 0x1D6CCDA4260AF070ULL, 
            0x58B6975A93A5ADC8ULL, 0xD19D3F88F1A9576AULL, 0xBB4A823D7A041211ULL, 0xEA83AE635C29EAB9ULL, 
            0xEF67F5C43006CD36ULL, 0xB3C367C6667451BCULL, 0xF70598EC48882D59ULL, 0x9F2E0F835A6B11DFULL, 
            0x894D1F85A56B54C5ULL, 0xDE485B458DE74959ULL, 0x8A674E793EE096CAULL, 0x8721A2AC27D472D9ULL, 
            0x5FD2B63C1F50A1F4ULL, 0xADE5C20191FF2C8FULL, 0x1B27BAE851544E65ULL, 0xCF0DCBC4CB1D4CA2ULL, 
            0x8F55B6095FFBEA89ULL, 0x05F36026023F685AULL, 0x52A3F5047E387570ULL, 0x37EC51CA7BE24B6BULL, 
            0x2CC4A200A1DA6CF4ULL, 0x265DB916C404E4C8ULL, 0x381C9AAAD61E35A2ULL, 0xF403301C824D5CD1ULL
        },
        {
            0x943D7D1B71CC0FB9ULL, 0x9C7AC4BC35651805ULL, 0x5D415CC242BF1113ULL, 0xF899967720A4BF8FULL, 
            0xAE1A5BCDF034C1BAULL, 0xA252ED7EF139E327ULL, 0xC2F069E234AA5C79ULL, 0xF0F5353813ABD375ULL, 
            0x4663F76241B1324FULL, 0x7589564DD47383EAULL, 0x3DEC9351554DB2A4ULL, 0xA4C43B35417FF098ULL, 
            0x8C181D742FA0CEE5ULL, 0xF68868C557E89A91ULL, 0x09B1F78AD582DEF6ULL, 0xD61B6A48D18FB159ULL, 
            0xF7A8982B67A1BA60ULL, 0xD669E8001BC22422ULL, 0x1B7526C043ED1809ULL, 0x68AAD2D48DDD4B23ULL, 
            0x7F5AD958EA2F1745ULL, 0x8F6B9BAC61B34E41ULL, 0x0362E602A6A5D31CULL, 0x18F45204AB1B30EBULL, 
            0x69546D68A1C603C0ULL, 0x12BD25739DCB40E2ULL, 0x96ADAE8802694E9DULL, 0x3F2DF74040E26312ULL, 
            0xC4CDF3FC81AB3F2DULL, 0xA21347B75AD54BE6ULL, 0xE3776690605699FFULL, 0x297F8E55AD62EAB4ULL
        },
        {
            0x26FE18ECE6A0DC03ULL, 0x92F7895B7CFBA1C4ULL, 0xDB9CE48EAC347CBDULL, 0x7AB64FDB262D3589ULL, 
            0xDF9C4243053EF27CULL, 0x0AEC94CF2277518BULL, 0xBD0226D892D494FFULL, 0x6EE90A4433DF0CD9ULL, 
            0x52FD02243A1C746AULL, 0x4472CBB5541534F3ULL, 0x1F85B3F9365ECCE5ULL, 0x9EC8F7B067B651E7ULL, 
            0xF2F8E41510197C7BULL, 0xA40A729503D9C6AEULL, 0x86A37A702714A035ULL, 0xEAE3E5907393D7FFULL, 
            0xD89A4858B503D244ULL, 0xB54D01772D8D4E65ULL, 0x03FFFC4B91821FBCULL, 0x4453A6011DCAE77AULL, 
            0x7F8624D8F7DEB654ULL, 0xCEF220919A24AA82ULL, 0xBF79EDCBE0F58467ULL, 0x507B5E5D8DA3504DULL, 
            0x3F4C5892E9C82398ULL, 0xB28C521318653E74ULL, 0xB075842141E63F9FULL, 0x6FF04EEE269A49B4ULL, 
            0x9AAE50725CA777E5ULL, 0x9450043C579D4CB4ULL, 0x29E4B08BED0DA7C1ULL, 0x54AF27D125D76464ULL
        },
        {
            0xE5CE580CCB0225B6ULL, 0xDC1076825F2C24E7ULL, 0x956CCF78ABC1118AULL, 0x5112F76B1071C636ULL, 
            0x26D207E07855F5E6ULL, 0x47B57653D9AEDDD8ULL, 0xAA650496A63AEB8CULL, 0xC484DDF9D6D2306AULL, 
            0xABDC2369ECAA6A61ULL, 0xFA6D2F8D1FF53992ULL, 0x84A591C5D7E59733ULL, 0xCE9A59E8F53BB524ULL, 
            0x568B44235219B112ULL, 0x10A7D3B3C1F2F041ULL, 0x0692E1DC71A7B043ULL, 0x684FEC5D2BD163ADULL, 
            0x5E9E82689266EDAEULL, 0x1DF2CEA18A946A41ULL, 0xA9BED0CAB982C00BULL, 0x453E2D0861E79C00ULL, 
            0xC02BD463336CAA1CULL, 0x7A6B24BE7BC71132ULL, 0xEAED1B4289EEEDCBULL, 0x0540F9FFD0C4172EULL, 
            0x0BBBB7A6C989A170ULL, 0x1A14FFCBC4CC1E14ULL, 0x21B7661A9A72F35BULL, 0xA36E2E5E5096216DULL, 
            0xC48C48FD07BFC12BULL, 0x926F0C80D830410DULL, 0x1E83116E339EECE8ULL, 0x4614B503CF6FCC2CULL
        }
    },
    {
        {
            0xE78C876C0C784BE3ULL, 0x81632D1608623A3EULL, 0x745A01226A8E756FULL, 0x9C6338897A561C48ULL, 
            0x1505CBE37F7D3060ULL, 0x7A48345EB0F33774ULL, 0xC3C841DA592853BAULL, 0x8F665485C587E16FULL, 
            0x70F359DEB3BFA816ULL, 0x343E8F85E0F124C1ULL, 0x3AAD3D795D3114DEULL, 0x5842D35181F50BDEULL, 
            0x97ABF975878DDBBBULL, 0x779EA698226590D6ULL, 0xEE390D4548C9E4CDULL, 0x5B6A6C4F7F3CE2EFULL, 
            0xD979812C1DF4A07CULL, 0x1ED7955667A70102ULL, 0x49C056730762D681ULL, 0x30EA0A65F26A34A0ULL, 
            0x6ACCF626A8D99407ULL, 0x9EC41D6EEACD27A5ULL, 0x770A632C4C35D027ULL, 0xF83E7D5136360E7AULL, 
            0x8CD2E6643BED3242ULL, 0x176DC113BFCF2459ULL, 0x671CE83FBFF8AF62ULL, 0x890D3082244C0F15ULL, 
            0x64472600C7837C80ULL, 0x0C4300D8DBA8743BULL, 0x376CC3544CA63B87ULL, 0xCC44A2D7E84AEB54ULL
        },
        {
            0x454E2ED2F809A8F9ULL, 0xBC9BC2D301319811ULL, 0x7067122FE3EF7A13ULL, 0xA779B04F946494DEULL, 
            0x8BAB9596AAB97F21ULL, 0x79BB76FFEDE39761ULL, 0x8F2E196C8FE3267FULL, 0x8EEE933AD1F91337ULL, 
            0x59C9E203443BCA70ULL, 0x386D8C33F785DB8FULL, 0x4DAE4F21827A5144ULL, 0xA3F3BD3ACEE0529FULL, 
            0x3E642E98AADFC374ULL, 0x95773213218DB6EDULL, 0x0BBFF4D3FFA0438DULL, 0xE71F379ED9A3D1E9ULL, 
            0x609D2EF1FE99A7B2ULL, 0xE755712ACFC3CCD1ULL, 0xD6BF814102F2FD82ULL, 0x9F3DB847BD3FC66BULL, 
            0x28E161D1B1A0450BULL, 0x3C9504949D81FB41ULL, 0xE7BCDDE3F91F40A2ULL, 0x03C1FCE4A596EF46ULL, 
            0xE329176468D315F8ULL, 0xC4F43E44CC8A2920ULL, 0xA494BC18F48E8690ULL, 0x7629FABB2EEB8350ULL, 
            0x61F4CB9C85FDB89EULL, 0x3634765FB25A2C66ULL, 0x1F7E6FF2F41FA457ULL, 0xD67C9CB9F9CE0F97ULL
        },
        {
            0x59F5CFAFFBDA75BBULL, 0xE8F7BDA336179350ULL, 0x7A3077249B6A1FDFULL, 0x93EFBA996EC277D1ULL, 
            0xC50DA17FF6C601DFULL, 0xFDD9279B93374EE0ULL, 0xA520D8F6756DF5F9ULL, 0x8AD6D60C540885A5ULL, 
            0x6DD4771D4DB51E44ULL, 0x3B0A63B00F5F3D6BULL, 0x6162642EE22EB475ULL, 0xBD9309B3B8D022EBULL, 
            0x7F3116177D826F60ULL, 0x9EAB5AAF9356C9ACULL, 0x562D5995620FC991ULL, 0x516908AFB438A213ULL, 
            0x20DF847BC232D342ULL, 0x6FD313E53F5AAA5CULL, 0x6F107ECC1DF7D7F9ULL, 0x65631D0FB6B2AD46ULL, 
            0xB9CE9AD02A3D4AFDULL, 0x72EC0C39EB31A84AULL, 0x4E094F52D3BA3FB6ULL, 0xAE3FAF0F1AF2A440ULL, 
            0x13E5B8306AED4CB8ULL, 0xC189931378A7FAB7ULL, 0xF55E2CDD0A1CF8EBULL, 0x82FD64DC3C58A3ADULL, 
            0xF4AAC174EC85D702ULL, 0x4EDA17B467FFD370ULL, 0x7746E80B7F7ED7BEULL, 0x0107D990414D29C5ULL
        },
        {
            0x1AA7A22915AB6ADFULL, 0x40BEF624ED179AA8ULL, 0x10AADBE6D8DA569EULL, 0x0137D4E72924EFFCULL, 
            0xDB2792DBFC3B4286ULL, 0x1EA86242AAE498EEULL, 0xC512554329B8FDCEULL, 0x36C946F5DE4EB2DAULL, 
            0xF64F8C7F713B156DULL, 0x1FE55808D2121713ULL, 0x661C0E9F10AA733BULL, 0x21339DA514437EA3ULL, 
            0x33F8B3BC61F9D0DCULL, 0x6A88BA69A1556E8DULL, 0xA80056D8ADC06D80ULL, 0x140D44EA9793FF47ULL, 
            0x342BA0340170EE5EULL, 0x22B2EF58E4E55F20ULL, 0x02B78D23BC9E4E12ULL, 0xE019946CC46020BFULL, 
            0xA6A218ECE34479D6ULL, 0x4E787D5B6DE9B069ULL, 0x7E3CBEBF615632B5ULL, 0x45641881EFA91991ULL, 
            0xCAC98D6E2524C787ULL, 0xEE659AF3F2D97C53ULL, 0xBF9B83CB71617E4FULL, 0xCB0C7E8F7E40DD09ULL, 
            0xDADA7356F2D11046ULL, 0xD0CC47F9E8A2EC13ULL, 0xB98C114EAF699F6CULL, 0xA8579D34DA0C7477ULL
        },
        {
            0x679CACF9E9D54973ULL, 0x6A41C46B943BBA7AULL, 0x613F734BE0EA5D15ULL, 0xB6E415D68EC79512ULL, 
            0x02835902EF71A0A3ULL, 0xA11C97CDAB292D16ULL, 0xEDB098096092A29FULL, 0xC4D51DEE9FE1A3EAULL, 
            0xE9DC2348601BD327ULL, 0xB66E5D012264A718ULL, 0x2D8D8D2221298B0AULL, 0x0851A7D515CF17C7ULL, 
            0x0C30419278F1F3B3ULL, 0xE0A783AF2C5D7F0EULL, 0x4C1E6C0E1947C9A2ULL, 0x44F0370BE34A07CAULL, 
            0xC8D12DD2B78AB90EULL, 0x8EC9AF7F59388B44ULL, 0xB0B20A4FFC375E99ULL, 0x4F3A49562445E9F7ULL, 
            0x09EB5381FC1A55BCULL, 0x4CD25DB708BD16A2ULL, 0x64C4CF8EBA55413BULL, 0x0CD7DD206C864559ULL, 
            0x8879068A1071AB26ULL, 0x3120081628E2DCFDULL, 0x44A482A272B01987ULL, 0x236344D2E3E5C025ULL, 
            0x27FA5461572F3294ULL, 0xF4CF4F4E973A5038ULL, 0x20706DD056050344ULL, 0xA30F7B2C12BBC340ULL
        },
        {
            0x3D12645F292134F5ULL, 0xD31CD87DBAB0F10CULL, 0xA8B088E6AE8E3529ULL, 0x5126391BF22D048CULL, 
            0x4EE737CEEBDFAA89ULL, 0x07BC854DBD2A6B41ULL, 0x304205942DBBD434ULL, 0x0176E7729B5950E1ULL, 
            0x89008017A599C3F5ULL, 0x853B890BE11D03BFULL, 0x7FE6EDDE237BE73AULL, 0x42A4EDB58A0AB180ULL, 
            0xC365C167A5D0CB17ULL, 0x5BE2F72D02B566BBULL, 0xBBFD45B62C5BBDB5ULL, 0xDD65AFDBEDEC1D46ULL, 
            0xAFB6295DAB73EE2CULL, 0x34B23CDB50F6CA76ULL, 0xFDAC09CB3FC1D17AULL, 0xC71150C8FBBB6100ULL, 
            0x4A6D6B92798B7A4EULL, 0x22E6BF5372EC262DULL, 0x49B3218F8B98140DULL, 0x401DCF2A20244435ULL, 
            0xFD400F2399B9FF4CULL, 0x2C639A0C05D6FDACULL, 0x7A3076659C84DD38ULL, 0xA6E0A60EF2594596ULL, 
            0x58E8D49F0BBE3FD3ULL, 0xC6838A8CB7157284ULL, 0xCC7D5A61C6F50980ULL, 0x6DB81F58158121D2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseAConstants = {
    0x7D72E4D9276B6CF9ULL,
    0xFD82BA8BAB8D7C12ULL,
    0x81C2C7C8743696A0ULL,
    0x7D72E4D9276B6CF9ULL,
    0xFD82BA8BAB8D7C12ULL,
    0x81C2C7C8743696A0ULL,
    0xF85D1546B5E48265ULL,
    0xDDC6B88C2E81106BULL,
    0xC7,
    0x42,
    0x41,
    0xE0,
    0xEF,
    0xAD,
    0x59,
    0x3C
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseBSalts = {
    {
        {
            0xEBD52A25EE86E04EULL, 0x6850F4608038A2FEULL, 0x93C72736D6EE317FULL, 0xC05AFA2161547500ULL, 
            0x0AD5E712A6FE7044ULL, 0x0FF65692785F82A4ULL, 0x0D92621C662019C9ULL, 0x4EEC3E7414D0F2D0ULL, 
            0x83C12E0DEDCDFEA1ULL, 0x3705A8126215844DULL, 0x6AA6CF35E167F4EFULL, 0x78A52949E299FF46ULL, 
            0xA263507627494B4BULL, 0x2BAF6F1B65C38C68ULL, 0x73744CFA95BD24B0ULL, 0x6A7E09D5972DBA77ULL, 
            0x7283560937CE39DBULL, 0x3A544C67F9F3A8F4ULL, 0x16FB0FAA0D5FB39FULL, 0x5BBC019454FA89A4ULL, 
            0x8FAE87E1D2BCB881ULL, 0x90E055BBEFA41BF8ULL, 0x5EA4F52B75A881F8ULL, 0xB6C8ADB0DC480E0DULL, 
            0x055FB3F18CE0A169ULL, 0x573D95E91AA1151EULL, 0x9CCAAB05FCA8870EULL, 0x90B95E80A48317D4ULL, 
            0x3F08D5356ECA8E48ULL, 0xC42D108D2D39662FULL, 0xF5124AB2B5345D0AULL, 0x0F9E17A2A3E80663ULL
        },
        {
            0x0A6B55AABDFA41E1ULL, 0xF8170B020656F8C7ULL, 0x155507DF9359E52AULL, 0x17D2F9A9A186D5E4ULL, 
            0x0CBF08B7B61C67C9ULL, 0x75462454F4B0E17EULL, 0x1758D130399EC13EULL, 0xA95C9B4A94CF5B99ULL, 
            0x0884F5D995D82A79ULL, 0xDBD0FA602288A04CULL, 0xED4951C79338B7E7ULL, 0xBFCC8F4F13DBE06CULL, 
            0xC12AA7433E8AC21EULL, 0x91AE408E79860990ULL, 0xB9414D87D8E75C4DULL, 0xC07538694D564F02ULL, 
            0x337508BABBB2B037ULL, 0x713E3A8AAB8C049AULL, 0x7A2D9B2B33F86C9AULL, 0xEA0A6ED714BA8B09ULL, 
            0xA9E972E0E6D7AC04ULL, 0x009401F100359765ULL, 0x7489C729E4771158ULL, 0x9F6B4332DA58FC90ULL, 
            0xC4873D680EDF425BULL, 0x5C1879C35020BE71ULL, 0x4A999B68D213B06FULL, 0x3869901B43A5302DULL, 
            0xA5EC59612894E036ULL, 0x45410CCB7391170AULL, 0x23A8744C4BD5B75AULL, 0x2113D1516F620ABFULL
        },
        {
            0xF920A9F11313DC32ULL, 0xCFFBE1BB74C8E13FULL, 0xDE15B2B5A1D168AAULL, 0x581124A31B9EFD92ULL, 
            0x1446CEF34C4F1B3DULL, 0xA8DE2F34170FF723ULL, 0x6A73B2BF9655647FULL, 0xF28361151B72C74DULL, 
            0x191F8B64BC150240ULL, 0x5CC87E98F44D8869ULL, 0xAD40EFE9E3DD2756ULL, 0xC20CCB8010C75569ULL, 
            0x900A63B2AB977255ULL, 0x4C2480CF2306B373ULL, 0x33CC484251C707EDULL, 0x80AB076467556B8FULL, 
            0xE23D8841387C0FF4ULL, 0xFE1076832313CF2CULL, 0x7E6AF10E9008641FULL, 0x378C5D5B10DBD15FULL, 
            0xDED8517A6FB9A932ULL, 0xFB4DC1FAE2469D43ULL, 0xEBE200A5A7AE1ECCULL, 0xA974321E13D1A8C0ULL, 
            0x55797A0C8B012EECULL, 0x04A8E1AF57152491ULL, 0xD8BF6D065FA23CD5ULL, 0xAE88078D37B50E5EULL, 
            0x428B37041724D261ULL, 0x0AE3731DE3ABB5AEULL, 0xA8D48533C5284B36ULL, 0xDC8D09BAB0BB9E5AULL
        },
        {
            0x101BE7BD7DE29B76ULL, 0x7DD0F1C6C3292714ULL, 0xB288FD4EB4614F33ULL, 0x20C46008DFE9E3E3ULL, 
            0x87799901DB1371E1ULL, 0xC67EE4773542EFC7ULL, 0x31E2586053837E28ULL, 0xBD612A395C4E6695ULL, 
            0xA57FF2B1A8D50BC8ULL, 0x6F226FC5BBAA2D61ULL, 0x41B68FC4A57D356BULL, 0x34407706ACB1A928ULL, 
            0x79C6B4AD7AEAED9EULL, 0x072F27CECE09229DULL, 0xFB5A7A772AFED94BULL, 0x9B86016C9BAC768AULL, 
            0xE8795E3BA1795915ULL, 0x648ECA9B076AFFCEULL, 0x4A5D63EC0BCA9F0AULL, 0x9D17E773C413EA87ULL, 
            0xB3388F193BEB5F34ULL, 0xA9E80EB285BDC0CFULL, 0x91A21EDDFB337D56ULL, 0x84F0FCAF49F6EEF7ULL, 
            0xF9C362F6D1C07136ULL, 0x731FC7DC9C577401ULL, 0xD9D1F6C5CF33AE67ULL, 0x869E30A0BAFE73EEULL, 
            0xEB0BADA75D752394ULL, 0x32D52A3F58210172ULL, 0x500DB1D1ACF63AC6ULL, 0xB0F81E08EC6E1E38ULL
        },
        {
            0x99DDDA02075F3C9BULL, 0xC8FB07927113A257ULL, 0xEDBAE418EA9E3B91ULL, 0xE9FFB9C8EFB49F89ULL, 
            0x1C36BFFFB8E6C505ULL, 0x589A1908BA988C86ULL, 0x35A01E55640E0D8AULL, 0xDC98A947B016B4B1ULL, 
            0x0D05240742B048B5ULL, 0x94A15BCA32CD9F7CULL, 0x1ADCF624C7E0B19FULL, 0xB52F041F3EB2E577ULL, 
            0x3CB0BA5BF7859385ULL, 0xE6D74DFB23F211B0ULL, 0x115CE1FD63D796B4ULL, 0x2526392F70943AF1ULL, 
            0x496C77623D607061ULL, 0xC786F08300C19BFBULL, 0x5D90C28CC8650001ULL, 0x0E76BE5AD15F3FF6ULL, 
            0x4A9DCA9D76C79F51ULL, 0x1C95866AAC686F34ULL, 0xD30CC79012C67DF3ULL, 0xFD997F834F78BD1EULL, 
            0x70EE906E0DC49DC2ULL, 0x284063D508DC74AFULL, 0x710A5A405D3246A9ULL, 0x461A16DFCD8F029CULL, 
            0x94B79E546F25C035ULL, 0x8C543EAFC75DBDE1ULL, 0x47D2E67C467B6171ULL, 0x9E634FB54BCA1AB9ULL
        },
        {
            0x0E165668B4AC31A2ULL, 0x70E53F71B0400747ULL, 0xE465E1F3BCCFCE4AULL, 0xD8C95C432CD881C6ULL, 
            0xE3DB8241563F4260ULL, 0x45EDCCEC97BB5F6CULL, 0x6D5FB57377A8240BULL, 0x955AAC147E2DB3E1ULL, 
            0x524560F957529CD1ULL, 0x1B77831F0626240DULL, 0x430866136B1EFD8FULL, 0xD15C08C029F34631ULL, 
            0x18A490FF370BD73AULL, 0x078D82F193610AF3ULL, 0x23B0D0C7D39C4645ULL, 0x461865E849CCEB9CULL, 
            0x6EC5307191971BA8ULL, 0xA03F2D63EEBF527AULL, 0x7816ADCA175E4F28ULL, 0x651B6B044F3BEEBCULL, 
            0x32120B3F4231D3BEULL, 0x040DDB6712366CB2ULL, 0xE270B7F088A3A5EDULL, 0xF4794432F8F5A985ULL, 
            0x43B9ECBE1994C9ACULL, 0xCDE25A908A0412C0ULL, 0x25EDA68F04674E80ULL, 0x06B6121D41DEFF1BULL, 
            0x7CCA942BD26DFF3CULL, 0xE139E190932BB478ULL, 0xAB93BCF85F6FC721ULL, 0x2A0B78185BC69701ULL
        }
    },
    {
        {
            0xD38D41EE644FE3C3ULL, 0xED6E8D9664155962ULL, 0x91BD7AB474C349B6ULL, 0xEFC50841ED6CD41AULL, 
            0x774F070935D0C177ULL, 0xB5906FEAC52798BBULL, 0x7944327EB2AEFD47ULL, 0xEB1C82F998C0A689ULL, 
            0xF99625F6DA6ECB55ULL, 0x999DD418F8F7E499ULL, 0x2BF48A354B6C05C8ULL, 0x7E918CEE1E2C826BULL, 
            0x87330274AB43164AULL, 0x06DB0F5107A46A2FULL, 0xB635475647B0FCA9ULL, 0x26696F24D5E3C20BULL, 
            0x421DFB0761B79561ULL, 0x7365E026AA6B0603ULL, 0x8520433B40CB0254ULL, 0xAB43E0AF39FF0BC2ULL, 
            0x1E7017F5C5232DF5ULL, 0x5848B8EFDD6C0745ULL, 0x8554F7E4AEB997CDULL, 0xB01A9BD55F81ADDDULL, 
            0xB76BE738A6EEACC1ULL, 0xDE8BF582ACC505ACULL, 0xF98FA6473BC07A29ULL, 0xF5360B6B9C111DAEULL, 
            0x5A2C20E54F8C11B6ULL, 0x6D3DD47170545120ULL, 0xBB19F20CA5A86441ULL, 0x38EBD09E337D906EULL
        },
        {
            0xAC9845A993407F6AULL, 0xD2521CF4D37BE019ULL, 0x8F9767B746EE0DD0ULL, 0xF878ABEB513D8CA3ULL, 
            0xCE136FC3F970270FULL, 0x788419ECCD8FE539ULL, 0xDBE41456A4C924CAULL, 0x5F6CEED8E1B50869ULL, 
            0xE90413FFEC5B4802ULL, 0x6D1F9F476EE2F78AULL, 0xAD51A3AB88AFF3A8ULL, 0x402B59B229D65224ULL, 
            0xFD987D42EA41F1B3ULL, 0x268C3CE18D0C96CBULL, 0xD1401A82A0610A25ULL, 0x87FC9DB5B7250F28ULL, 
            0x4C5974EA71D15AA3ULL, 0x5560C74C2F54C2B4ULL, 0xB83C83E43887D3EBULL, 0x41B09C5BA21975B2ULL, 
            0xAD74E7D7799CFD79ULL, 0xA142FD7C680423B7ULL, 0x1AEC3300C26EFB5CULL, 0x1D4753E6563CD50AULL, 
            0x49DB4659EE0EBA35ULL, 0xF47284802BF2B91DULL, 0x5490DB0338E1B9D5ULL, 0x03AA4B32EB5C3AC6ULL, 
            0xE5C77A77C4B35AA0ULL, 0x1ED8C268A2394BB0ULL, 0xB9773345EC74976EULL, 0x6DA20B1848A7B542ULL
        },
        {
            0x9E83940ABF48CF98ULL, 0x82F74C79C44046DFULL, 0x28A2D968EB7B375CULL, 0xB9CBBD876B193B6FULL, 
            0x51887B8FD3E9408AULL, 0x82F93CC781C24AA4ULL, 0x565BC0342F312D2BULL, 0x0E151D7021AADB00ULL, 
            0xC4FD7DC0F0B7E19DULL, 0x143EA89099AEB9F2ULL, 0x0D5153D3C8ACB849ULL, 0x7AFD905A4C53BF1BULL, 
            0xF27F95317E5D3807ULL, 0xAD38E6703DE27AE3ULL, 0xE4B1393ACA9AFD7DULL, 0x09D00445050688B8ULL, 
            0xFD50914ADCD53B5BULL, 0x7ABF436F43B45FA8ULL, 0x82BBF394F375DC6DULL, 0x58B7609D92A29DBEULL, 
            0x32C09EF6BE9BD874ULL, 0x6A4D3D0E0ABD1C28ULL, 0x1E196C3D86615A93ULL, 0xEA0B934A144178BFULL, 
            0x2DF2CD8483C2954FULL, 0x65EBD8519FFF9224ULL, 0xC0BDAA00A04F7690ULL, 0x587EAF214618DDBFULL, 
            0x31F848CEAF8BD663ULL, 0x0788BAC0288B2121ULL, 0x7E2B26B11C9207B2ULL, 0x480F549C96554C78ULL
        },
        {
            0xFE88F7766102FCE1ULL, 0xAD2064DC8AE50F59ULL, 0xF045B61F4B189F13ULL, 0x40E962D917E7FFE0ULL, 
            0x442F2FB2008E02D0ULL, 0xA30ED88C3F7AFD57ULL, 0x2696D151EF3BDF0BULL, 0x4A4D045792A92718ULL, 
            0x72268213AE4EDC21ULL, 0xD1FE23B114206C4DULL, 0x52666A003297BDC4ULL, 0x701B90B551DDF80DULL, 
            0x080C0DC850E35FDDULL, 0xEA0564A4BFCF5015ULL, 0xF182258C9E98F7F5ULL, 0xD62EE498E4A307BFULL, 
            0xD68176606B347846ULL, 0x7FA0D58B4A6C6AEAULL, 0xC19FFBAB0898BEB2ULL, 0xFB5B2CF63F4F619BULL, 
            0x3303FF56F31FC46EULL, 0xEAB149636FDD9DF9ULL, 0xF389A5F3BB1964A8ULL, 0x9CEBCB0F3B6964D2ULL, 
            0x5DDF8705B4C1E424ULL, 0xE5159324883CD138ULL, 0xA06792B86784A7A6ULL, 0x69AF87D70EBB5F54ULL, 
            0x0D577686E3F6064BULL, 0x17F752E3C7574DFFULL, 0xB629BFBE8E175731ULL, 0x7FE9FB0EFA2B4F6AULL
        },
        {
            0xCCF06F301E6C01D0ULL, 0xF53B7D0F1A3417F0ULL, 0x40729DD131B03BAEULL, 0xFAAF43D61585B719ULL, 
            0x2DB7B638BCEEA343ULL, 0xE63A192F1C8FAC41ULL, 0x4D7DEB8A41665733ULL, 0x1BC15E2284C5E508ULL, 
            0x58A05AA454B5FFAAULL, 0x4C14892AA645C797ULL, 0xF3E5CB1C852E7625ULL, 0x00FDDB33D6AAB3C4ULL, 
            0x9551F18014CB7B00ULL, 0xFB9781E4B878855BULL, 0xDFE25C81AA236A2FULL, 0xF399230F1637EFD9ULL, 
            0x91289BE8B5E74F3FULL, 0x7D4E0902DD21E21EULL, 0xCA7F74366E1ED47CULL, 0x7B43C7244262CFE9ULL, 
            0x3DAC21A0E8C253DCULL, 0x83085C37EF33B0CAULL, 0xFD89C5F3F47245E2ULL, 0x4FAD6D7209ECD827ULL, 
            0x67D91330E3C1D386ULL, 0x326F1FA4C897B352ULL, 0x2ADC4F01BEE18D6FULL, 0x7F74F13152914442ULL, 
            0xB2612276A48FDE03ULL, 0x70DF786D0CCC0F56ULL, 0x51B33AB4EF38E3E4ULL, 0xF8194F99116353F8ULL
        },
        {
            0x94B411EEE50BAC79ULL, 0xE0406A34E2A29469ULL, 0xD770AF6437C1442EULL, 0xBC3A5436DA9639DCULL, 
            0xEB918926F81F6F8BULL, 0x6FB18880E748378FULL, 0x43EFB9C6830EAD73ULL, 0x6C6A18AB2C7B6FEAULL, 
            0xA51EB4AC49A2578EULL, 0x3EC7E4F0ABBFA62BULL, 0x51B1371B788E03D8ULL, 0xB62664A8A1248DA8ULL, 
            0xEB16F63DD417D3ADULL, 0x23636D22FA751785ULL, 0xB7B0D9DAFDC4349CULL, 0xECE49AA5130DE300ULL, 
            0xEF076A3D236D7CCBULL, 0x1306A760E8B8227FULL, 0xFCA31D19C7BB1EE1ULL, 0x0432B6C2413D69F3ULL, 
            0x89EFC174E719A7C7ULL, 0x18D0C146C7ECAF75ULL, 0x73A37076B6467B8AULL, 0xE1150D8BAB9ACD57ULL, 
            0x2428BF53191FD11BULL, 0xFC708E6A4F130BBAULL, 0x2E5ECAD72946D44CULL, 0x66FBA83EF29CEED5ULL, 
            0xF3CA35DA8155D7ECULL, 0x4AB60C443F8D743BULL, 0x168F15602CB0DE83ULL, 0x727D031F1EC6D904ULL
        }
    },
    {
        {
            0x8483245AB09C6E93ULL, 0x7CEF15D5E6032C22ULL, 0xD7F06D59B5792926ULL, 0x91CB56CB66210D16ULL, 
            0xB0E118275F8C91C9ULL, 0x425E83640B677803ULL, 0x0DB563FFDE2F22C5ULL, 0xD68560B61AB9DF7BULL, 
            0x2B6BC416F8CE21C1ULL, 0xCF96D1CF3F00CD0DULL, 0x99927B0F37EF85F4ULL, 0xE2AAFA3F8A90FC73ULL, 
            0x8209DA4683A10A0EULL, 0x317A2A7B669A5AC5ULL, 0x1FF8E42222CAE80CULL, 0xA271F9A7E062D8C5ULL, 
            0xFF3445375268E1CCULL, 0x9EB19F7CA712E38AULL, 0x4D07FBD3FF51CA18ULL, 0xA0AE0CB5D11A3C54ULL, 
            0x4476AF59B0772B3CULL, 0x27505967CC162784ULL, 0x46F2D0F3C6601AA9ULL, 0x08B5B6F21EF2C01DULL, 
            0x4F1B8AF305A3D75CULL, 0x877263F032C26274ULL, 0xD6969A1756FAC643ULL, 0x5AE1CA9534FC845FULL, 
            0x8B10F90DC12C21C1ULL, 0x29DF0CEE76CBC91BULL, 0x39F73576DAFB9E13ULL, 0xB6C7B55605823507ULL
        },
        {
            0x1A1BA398012CF08EULL, 0xEA236EB8625A5BB4ULL, 0x7A49D99D7540F46DULL, 0x536CBC47A1D4A52DULL, 
            0x1BE38FD23BD91079ULL, 0xD539622664A27A9FULL, 0x419D6C7F62439253ULL, 0x18118457D60C47AFULL, 
            0x347230868D293C90ULL, 0x7560C7A736D13FEEULL, 0x570F49B7AE30BBB6ULL, 0x490D70383A6BA3E8ULL, 
            0xF99E9C2DA117F3A0ULL, 0x48ED39BD57AF48CEULL, 0x926A69B125E24BD8ULL, 0xE3323C4C64DCBA70ULL, 
            0x659B934A57800DE5ULL, 0xDF5EECDE3EEF859FULL, 0x5879B4782056DB4AULL, 0xBF3074F54EED6C8AULL, 
            0x9AD52B0382015F98ULL, 0xE35CA21199DBE0CEULL, 0xF78E36B901785A1AULL, 0x22B80534EACB27F6ULL, 
            0x5C2DC421C2B11F52ULL, 0xB2701E41C9A8846FULL, 0x4F836474E2353217ULL, 0x32D60FE3582A27EEULL, 
            0xCAC0714D53CA29D1ULL, 0xB41E047F9921BAC0ULL, 0x4AE426F0F6E24434ULL, 0x5E59AF7DAC9C1708ULL
        },
        {
            0xA7A3D46C93DB7F1AULL, 0x5D5D057A07AFE870ULL, 0xAFFDFD65C212EB86ULL, 0x718080202C709BEBULL, 
            0x8BC4335D0AE0472CULL, 0x1E9773A5DCF7F0F4ULL, 0x2E8510E9C47CA269ULL, 0x5EA9E057CA1F3022ULL, 
            0x4BB3FB981CA94E46ULL, 0xF030B2A7CC0FA079ULL, 0xAF180F70F920B89CULL, 0x1EE025D539CFF33CULL, 
            0xAEBBFDEB32C3D466ULL, 0xD5EF9C41E388E17FULL, 0x0D321CE93F38514BULL, 0x9A3DD443ADB976D2ULL, 
            0x54BE364D9878CFF8ULL, 0x4A55B598B25A6D76ULL, 0xB481DEDD25A21F38ULL, 0x9A3D033CC4E6DA2BULL, 
            0x236DB538A390B24EULL, 0x8CC9B95A4A70EC79ULL, 0x1E02A92933762F79ULL, 0xF4216D4C7C24AECFULL, 
            0x687F6997F1ADF54BULL, 0x58E74FDA26802A5DULL, 0xB448DCC5CB6D1BD6ULL, 0xD8013655D9E7E146ULL, 
            0x667709CE2E27DB8BULL, 0x58591820D4293408ULL, 0xD04F053CCADDDD50ULL, 0x4C27551852859934ULL
        },
        {
            0x6963E0C9EC14F2BEULL, 0x51DEF30338F6AF99ULL, 0xB46C8EFC2E6F1BABULL, 0xB9281401CBB66A9DULL, 
            0xD546015FE09B64CFULL, 0x1FF4EED244F67282ULL, 0xA3209B802C97B2D5ULL, 0xB9111C8589B47B49ULL, 
            0xCFF136B55E605629ULL, 0xB3A1511EA9D35F42ULL, 0xBCD53880969DE9F8ULL, 0x3D7278C6232A744DULL, 
            0xB903729D5B336B27ULL, 0x704E928BF6E77B56ULL, 0x226E3B8270B593D7ULL, 0x9728BFE4C68B9F79ULL, 
            0xB52F5790AB5CBD20ULL, 0xED63F5AA6E7E6BD5ULL, 0xE8E9E6DF9969B7B4ULL, 0xDB77B1FB97DF1590ULL, 
            0x97A3342E19FC24F7ULL, 0x1A4A9A349F1DCE04ULL, 0xF92D527F4A9B7102ULL, 0x0803840FAAA3ADA8ULL, 
            0x633BFB36A3F8D242ULL, 0x4AAA0AAF59458CD7ULL, 0x3EFA899FBA9F8EEAULL, 0x28F81BCB766C8E5AULL, 
            0x11B6787F2CE0F8C7ULL, 0x592217FF10D7845BULL, 0xC4924DF446F7227AULL, 0x2C064CC5F12E8307ULL
        },
        {
            0x244670A06C3A0A36ULL, 0xE1D3B1071ACE6F86ULL, 0xBE498A39E733A8C5ULL, 0xCE3A488E3AA2195EULL, 
            0x42083BE4C1B6319BULL, 0x83F7A3FE8559475EULL, 0x47C9399A1B288791ULL, 0xB478117C75737615ULL, 
            0x680299D551064112ULL, 0x4320B98EBA6AFCD5ULL, 0x170CC387C0749D94ULL, 0x3BE867D76F31AF34ULL, 
            0x7CA5C1168F58608EULL, 0x6EAAAE163BDE1DF8ULL, 0x14C47616384D2650ULL, 0xDA65AB6A1D2B272FULL, 
            0xC6B5D8B6B92D853AULL, 0x9F3A0647110FBFF6ULL, 0x7A08055F2F5EF2DAULL, 0xDEE2E4F17D0041AFULL, 
            0x8F6FF89CD95FD96BULL, 0xA155794C7A24665AULL, 0x25BEEFB4DCF831D7ULL, 0x64679592CDA4B16FULL, 
            0xFF2DCAD8072C1AA9ULL, 0x8E9A69D58F84D012ULL, 0xCF53995B31753FCBULL, 0x433F4E74E0C4BE42ULL, 
            0xE708323ECAA4C767ULL, 0xD8AD92641A5F53C5ULL, 0x6F64F463DF843BBBULL, 0xE3C07A642E77BBE9ULL
        },
        {
            0x91555184DCD0BE8EULL, 0x210567B6659CAE6BULL, 0x2E50733A983F85C4ULL, 0xEC21A214CC567F43ULL, 
            0x1BC89945684FFC09ULL, 0xDC6B70FFE2F37910ULL, 0x7B9ACBD9C1BA3C07ULL, 0x4E31D0A3662578E0ULL, 
            0x0A24827082AA949FULL, 0x8A0C57F987550EF5ULL, 0x84B13B444AB36F61ULL, 0xA0E9E2B30F914C11ULL, 
            0x5379164B11BC6317ULL, 0xDD75CAC80CC05995ULL, 0x68C0ED42F49DA2D9ULL, 0x4AA94B60FEF63FA6ULL, 
            0x37D116CCCB928A24ULL, 0xC22C96C535040983ULL, 0x10E1149367A1D3BFULL, 0x502A311311D90021ULL, 
            0x9A951806B99CF7CFULL, 0x2D4F01F6875E0A30ULL, 0x6D97FA336B5F52F6ULL, 0x9D716FFD4D5E3DBCULL, 
            0x5148D0510CDA3318ULL, 0x6BEF83BF220FB137ULL, 0x6B10358F1E099763ULL, 0xB8A35137A7248760ULL, 
            0xFE6677DE8DB2BB97ULL, 0x19C131693C6A01ACULL, 0x36AD2C7D0CBB72C7ULL, 0x0887D42991587E57ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseBConstants = {
    0x5FB980CB77240F0CULL,
    0xDBAF919152DEC078ULL,
    0x082DA932A3F47D8CULL,
    0x5FB980CB77240F0CULL,
    0xDBAF919152DEC078ULL,
    0x082DA932A3F47D8CULL,
    0xF6062F637C3D7D40ULL,
    0x498ED99CF0FE365AULL,
    0x73,
    0x8C,
    0xE9,
    0x83,
    0x70,
    0xB4,
    0xD1,
    0xFC
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseCSalts = {
    {
        {
            0xEA64B6681A28FFCCULL, 0x85352B0A848196D9ULL, 0x5C0D59B8A6DFEDCAULL, 0x539B328143DE7F03ULL, 
            0x360F93277B1AA651ULL, 0x4A826E28D17B9386ULL, 0x0EF727F642507E55ULL, 0x3B889657D023F261ULL, 
            0x888B96B615ADC5D1ULL, 0x1A091D1FBBF1B3A5ULL, 0xAF08F32531B353A1ULL, 0xA55D745443866554ULL, 
            0xD9CCBED141087C9AULL, 0xA411DB3122743E57ULL, 0x0D609A57D69E860EULL, 0xED1467570B4710DAULL, 
            0xC932617E268359DCULL, 0x3DF8EA30FCBA27F5ULL, 0x98C40EF944C31857ULL, 0xE7F501054938E052ULL, 
            0xF99E75CC649CD695ULL, 0x1110A1831BDFCE98ULL, 0x4AC83BB5FFDFCDC8ULL, 0x4AAE59BE7FDBDAB4ULL, 
            0x3D55DDE4CB29D723ULL, 0x5D8D6AD538118D05ULL, 0x9BB7901FDAA28E33ULL, 0x57E10F489F1E2C9CULL, 
            0x4269996FB7831210ULL, 0x77A8A162C27D306BULL, 0x16EC069B4D1A7272ULL, 0xF6BF1321695A1A04ULL
        },
        {
            0x337A103D91734EECULL, 0x918A0B87C0DD6E44ULL, 0xB27C9EDD21D22CDDULL, 0xEBBE9D92D39244BEULL, 
            0x92D5D1C7448566BEULL, 0x89A1FB3A7CC197BFULL, 0x09EA14754EEDF87CULL, 0xA41FEB0976BAD1B6ULL, 
            0xBCEDA51977037C8BULL, 0x0513AA129C0A2687ULL, 0x68D966D04859E34FULL, 0xB745051C00858753ULL, 
            0x96E274E9301AFF51ULL, 0x859BE5C2AF0DC6C1ULL, 0x4E16366340A98190ULL, 0x42C574B4D845B26EULL, 
            0xE124DD27C9A16AFAULL, 0x706908AA3AFD9FDDULL, 0x44EA6E31673174A6ULL, 0x7C24BCCA8BB5251EULL, 
            0xED65E954732E4A0CULL, 0xB0EE05E6149A4616ULL, 0x83D4D3AF60B61E50ULL, 0x2A9558098F8F17A8ULL, 
            0x8FFA7698F08A5786ULL, 0x9FF748C2DC858822ULL, 0xB950B0D8845322A9ULL, 0x5F3D7A3B6DE5A740ULL, 
            0xF37E824F21F476F4ULL, 0xBD4055425148C4F1ULL, 0xC0C543D293217C90ULL, 0x67A72AB77A9814F8ULL
        },
        {
            0xD629189F7268C5A5ULL, 0x913E831280D71D5DULL, 0xEF922642640D3CC0ULL, 0xEA36A70B027DA6B5ULL, 
            0x111F10F02EC0665CULL, 0x75C4FE8F1C76C781ULL, 0xF139DDCD3584F3D0ULL, 0x9720EE804606C80CULL, 
            0x4A7F175654F47E8FULL, 0xE6B685555D7D5588ULL, 0xF37AF131A913C28EULL, 0x88D26419C86F6042ULL, 
            0x965223CD557C8356ULL, 0x2C68BD4E7A3C502AULL, 0x58A7069D831A736EULL, 0x9D7BFEC12D7CAC27ULL, 
            0xD24C71FFD662476AULL, 0x7BBC48D82D35F479ULL, 0x8C5133365ACF61FBULL, 0xDF97B2CFCC5CF031ULL, 
            0xB7293365494D1F30ULL, 0x259B1DC20938FA4CULL, 0xF0B4FC733B824B49ULL, 0x9EC9373CE2ED58DEULL, 
            0x94095E433E5D347EULL, 0x9C06235B303213ABULL, 0x76FD1A0A6E320BA5ULL, 0x0FA60A986E065393ULL, 
            0xCCB18FF7F353B3AEULL, 0x967F21C350BD68B6ULL, 0x67E4DC9552D659ACULL, 0x70FEA72C6FA7B956ULL
        },
        {
            0x1669966EEE71996EULL, 0xB2B1D3AA0E6A9D36ULL, 0x5EB9515C2D45DE0EULL, 0x48D55FF65E8C1012ULL, 
            0x7FC87BD311A5A4FFULL, 0xBF138032A3C6E635ULL, 0x6CEA26D425D83691ULL, 0x32DF88713968B486ULL, 
            0x2204857D42A28B07ULL, 0xE37EFDF4D7767DF7ULL, 0x495635E73074D683ULL, 0xCD8822F27E2F8F80ULL, 
            0x349D870FB6DEC4C3ULL, 0xEEE36B269F3D1217ULL, 0x2880D511AA4BEE2EULL, 0x43D3E361A14CE7DBULL, 
            0x033DCFB671DAB772ULL, 0x98E0F372E0884822ULL, 0x01666C20A97A3430ULL, 0x4D325367987C2696ULL, 
            0x92FF53E6AD7C1DE7ULL, 0xE8700C10F73C192BULL, 0x01AAE3F933341185ULL, 0xF1EC356998C8FE6BULL, 
            0xB67DCBC2CD248C1DULL, 0x69A0BC63CFFD5FA3ULL, 0x9AD2E226D99F9084ULL, 0x25103D90A9446B76ULL, 
            0x40B325B289529492ULL, 0x8755207E351E9BFAULL, 0x30FD95249F117669ULL, 0x38BE8F623D2856A3ULL
        },
        {
            0x72266C4F7AE35FECULL, 0x8204E077858F0B53ULL, 0xF6328E09927C9530ULL, 0xF4293F26931BFDFCULL, 
            0x1C8558244662EA77ULL, 0xF5688ACDFA6D8E00ULL, 0xEA7B18196786F51AULL, 0xF001C184001D0543ULL, 
            0x8A16198DD5B4D46CULL, 0xF8FCD8CE18704382ULL, 0x2D37D4B2C45112C4ULL, 0x6AEC22FBBEA72065ULL, 
            0xCFD2B5CBA41333A9ULL, 0xA23E9B4AD76B41F1ULL, 0x794B2E249F0837DFULL, 0xA9DE85F7EA263A7AULL, 
            0xFC27C533C3D15694ULL, 0x2F232265BE540A41ULL, 0x64E652D04779D0C3ULL, 0x8ADA5F9F11C63239ULL, 
            0xD5BF52ABE8EF63D7ULL, 0x3DE880A2B0724673ULL, 0x722213781F388074ULL, 0xA51C6266C6B729BEULL, 
            0x8B460EFF4690D7A8ULL, 0x238862DB41D9EF5EULL, 0x9A88645FE1AE88AEULL, 0xF73F45C8721489B3ULL, 
            0xF16B3E1F28C4E3A3ULL, 0xD0B58E03A8057418ULL, 0x1E241AE46929EBB4ULL, 0x435D40E0427E8417ULL
        },
        {
            0xCE2B7CFB9698221AULL, 0x0976C92EF25BC9C3ULL, 0x86DBDACAE80217ABULL, 0x6DD83F9C76CF0A4FULL, 
            0xD5C057678EEBA42CULL, 0x22A17CACDA033652ULL, 0x0DE7E5860C277740ULL, 0x5838C83B06FF0F76ULL, 
            0x5F73E8546AD756D6ULL, 0x9ADA3AAE51DD24BBULL, 0x6053037DA4FC4B0FULL, 0x90126B13C4E3000BULL, 
            0xCCCD4077CFE750A2ULL, 0x30FF1F498050CED4ULL, 0x0398639D05C96EBDULL, 0x65757C8BF27BBC7DULL, 
            0xADD64D49DF5C2C52ULL, 0x16E6C2AACC2762B5ULL, 0xD58E814A6691C045ULL, 0xAB5383ED1D6656C7ULL, 
            0x934F7D86F39ED28EULL, 0x9A0ECA77119DE3CEULL, 0x0644B765597F603AULL, 0x3EFA41E3DCB55CECULL, 
            0x7DD5416745BB2305ULL, 0x9974AC872709345CULL, 0xBBCE00E6D298A00BULL, 0x74CABBCA74220F8FULL, 
            0x627E4475DA3BA39DULL, 0x69613166BB72F062ULL, 0xBE355F7D03396D43ULL, 0x472F26B153868135ULL
        }
    },
    {
        {
            0xBBD407CB44A6BE6CULL, 0xBA261C7E536CB862ULL, 0xE9175E7A8ACDEE6AULL, 0xA014CD13FB3808F1ULL, 
            0x2F2F9B16F9E9177AULL, 0x0E660307D857FF43ULL, 0x2A47FD7C1C278E18ULL, 0x6274A047336B4FF0ULL, 
            0xB59B87C9BA519BA7ULL, 0x73ABFEFC8091D948ULL, 0x4C17CCE886A52B0EULL, 0x8040C8CACE00CB25ULL, 
            0xF5B1CF7B8760B552ULL, 0xAB1413E6791CAE5AULL, 0x4DA1886D8513A3B9ULL, 0x39D261046C668A1EULL, 
            0x317687D26B89C5E3ULL, 0x75AAD223053C3F3AULL, 0xFF8A5956F9010C40ULL, 0xFA972D102A14D838ULL, 
            0x533067F0369EF8D0ULL, 0x43096AEB34C41B21ULL, 0xADDDCC94D7CD7B0EULL, 0x1645FD096C4FA29DULL, 
            0xB18B668AB7FB457DULL, 0xBFE7FA3B7CE38C0BULL, 0xC3FA77803368B348ULL, 0x19581E5471E039FDULL, 
            0xA5011EA7E7391E3FULL, 0x14899BDA71E01A5FULL, 0x1D367B453C9BF1F3ULL, 0xDD408FDFACD71C17ULL
        },
        {
            0xC10A04C6FF47E5C4ULL, 0x3AD420898586986EULL, 0xFABD66B358FD38E0ULL, 0x154A4D35AF377F20ULL, 
            0xB62C86BC61F1B91CULL, 0x9C582117B39A19F7ULL, 0x7DEB8B444A69E6EFULL, 0x8E9F22CCC688F4BBULL, 
            0x7AC272373BC5A626ULL, 0x4F132498710A4395ULL, 0x2FEF6BEEE3C652F1ULL, 0x6EA8EEF7963DB754ULL, 
            0x05BB7B71C8A91B3CULL, 0xE3B7AA918D837994ULL, 0x884756E5ED687886ULL, 0xD0B7021A7BAEE312ULL, 
            0x1716EC8E329D7D8CULL, 0x59DF0CABD87222D8ULL, 0xBB275B415D8F8EB8ULL, 0x8366C9E18E26DFFBULL, 
            0x607856788F45A553ULL, 0x0CF9EC3AA6C64010ULL, 0x1FA3E60A102D46A7ULL, 0x0C216A5C68582E62ULL, 
            0x7F09409FE7053569ULL, 0x18411A9535266359ULL, 0x4D927733A43B9C79ULL, 0x44AF4C2F430DB3A4ULL, 
            0x12822AE9116BB473ULL, 0xBE86162DE54EEE07ULL, 0x25682D0254E22A0EULL, 0x314FF9289F0FCEC2ULL
        },
        {
            0xFD1DD9C5AE3ECC37ULL, 0xA83818C09E752A90ULL, 0xE4007625E33486D6ULL, 0xF1ED4A1369151E4BULL, 
            0xCC677B1ACECAE524ULL, 0x64C78E9A1FDE2ED2ULL, 0x474A1B6B7FF63D26ULL, 0x7B644C5B6FEBCF65ULL, 
            0x73F904E9E909ACD0ULL, 0x6F9006F772CE093BULL, 0x01C3108DC760872DULL, 0x1AB0C3C51080FB2CULL, 
            0x09CE171CE6D476C9ULL, 0xA168FB0C46D8BBFBULL, 0x5241D3A64F27C701ULL, 0x79AA595CB3AEE18FULL, 
            0xD80DA94CC1D23424ULL, 0x63CEA697B871BC96ULL, 0x3D35BEDA1DD8F28DULL, 0x43E559120D590415ULL, 
            0x05E2260BB5BC5447ULL, 0x0F7FF2C00B496314ULL, 0x1EB19922110E6C7DULL, 0x048D2385953A118AULL, 
            0x5F62D4845A350727ULL, 0x182A12A2F7F449A4ULL, 0xFEE277BCFE0F38D9ULL, 0xDE1B661557B1A4F8ULL, 
            0x23A45C6E7E94F20BULL, 0x9FD8859422A03944ULL, 0x462CF7054DEBE7A4ULL, 0x72DB6FA2C42CFB83ULL
        },
        {
            0xDA56DECAC27EBFE5ULL, 0x2EDCF54A84F8AF99ULL, 0xE27E50B87212E65CULL, 0x13CD3265B1E8B2A3ULL, 
            0xA989F172E149EE95ULL, 0xF2EFE913862D9973ULL, 0xD28C781BFDA2575CULL, 0x52DFB40B16E36E92ULL, 
            0x98B1C5DAD60F2F90ULL, 0x2629DA63EAB16182ULL, 0x9C9DFE9235CDF767ULL, 0x7AC8200CAFDF2231ULL, 
            0x74158DE61D3BDEDCULL, 0xDAFA4CF83BCF4D4AULL, 0x13E0BFFC278F79A3ULL, 0xDB67C5FB185AFDBEULL, 
            0xB75C85C94B849342ULL, 0xB7E0572CDAE32EE5ULL, 0x12ECF6C61D3F3D87ULL, 0x6340FF0DBD09F53AULL, 
            0xC8B3A289984F1593ULL, 0x1B91C69188E7304FULL, 0x55434CDCF45D9959ULL, 0xE6AFEB9CCC53EFB6ULL, 
            0xF5318448BDFB0A83ULL, 0xC75C8133614692BDULL, 0x80C457536F3303F7ULL, 0x89B34BA87C52E510ULL, 
            0x7E8C322887093C79ULL, 0x2FDCD07053AF70FDULL, 0x2841266FCF6FB511ULL, 0xC223FD42CBC29E75ULL
        },
        {
            0x011CF4CB05A61C8CULL, 0xAF1F607EB46DD8F7ULL, 0xAB4E46D0286D1078ULL, 0x7FB6C59BE3699A6BULL, 
            0x117A127C2C53EB6AULL, 0xEE7D139BCED48E36ULL, 0xD5F7B84ECC417BE5ULL, 0x94F8A897E68DE502ULL, 
            0xF0B3AEA9F901E094ULL, 0x94D0E96B0021E2C1ULL, 0x789D499F4D2DD99FULL, 0xAD69F9A3300BE115ULL, 
            0x6636B017F1790DE2ULL, 0x6253BE9EF07D7EECULL, 0xFC51E3997AD58662ULL, 0x7FB46F8665182348ULL, 
            0xCA47735C5BD139A4ULL, 0xAFABAD418FBCACFAULL, 0x097DFD75D10315D6ULL, 0x9BBA05B00AD52269ULL, 
            0xDD7369ECA092A76BULL, 0x2AFD8774E4D44418ULL, 0x6E6930243E708F55ULL, 0x2068666AF3DE5B3AULL, 
            0x34381D71748A8573ULL, 0xFA2CAB078C41B2DEULL, 0xD1B044157B30791AULL, 0xA179D3721C0FAF1DULL, 
            0x8D37BA3E6013DBCFULL, 0x4A5579B21E302521ULL, 0x8BAC29EA448C9525ULL, 0x96556A6F3BF169B6ULL
        },
        {
            0xCEDC63093EFFD75DULL, 0x5C9D1ADB6A1319B7ULL, 0x61F4863E1531C867ULL, 0xACC9F087DF8F157DULL, 
            0xFA2C63EFEFAA452FULL, 0xE1C42C3AFD91CAACULL, 0xA27A0D6F3B6B6E8CULL, 0x5064736FCBF022C6ULL, 
            0x10E341E082B09B3AULL, 0x9AD57309D0DC56A8ULL, 0xA0248C4C6463EEE1ULL, 0xC77CB1DED84EE2DCULL, 
            0x773746CEB29375F5ULL, 0x6E44774A1BF621A5ULL, 0x17A230D8746BBCCAULL, 0x1CA3E493D7FFEA9FULL, 
            0x0ECD46C550557D9EULL, 0x4337795E7F78BA83ULL, 0xC248E70432053651ULL, 0xC49B262AB3DB7092ULL, 
            0x527E97927067449FULL, 0x7D258A142B32D4D1ULL, 0xC0EDF2C3BDE4D4A0ULL, 0x613358B9521DB18BULL, 
            0xD742F660AFD8CB89ULL, 0x7261D4CBD86947FCULL, 0x1D557BBAF6AB482CULL, 0x84772DFF851D9E4DULL, 
            0x12D812E04E9FA6A7ULL, 0xF8DC11D1F34B7E1BULL, 0x4ED2F260EB91381EULL, 0x695692D3BAA03D20ULL
        }
    },
    {
        {
            0x9C5896FE768F5BA0ULL, 0x772811DD67A84F0DULL, 0x563D975A1AF954F8ULL, 0x19E06792FFBDDF74ULL, 
            0xEABC2D9AB0E2BCA3ULL, 0x31BCF8E7B99F9C94ULL, 0x5D2FDA78B6F6ABAEULL, 0x3DA16CFD39DAAF9DULL, 
            0x026BB5DB26A9BB34ULL, 0x844FE446364007B4ULL, 0x22D4E05201F26243ULL, 0xF6C38075F9CA2A4AULL, 
            0xF9169F7853463455ULL, 0x6FB087AD345BA1DDULL, 0x4229C0E29A40AB95ULL, 0x8F9FED02F6D80E6DULL, 
            0x9580DA69B068AEBCULL, 0xFAA09793F0F066EEULL, 0x9A31C89C6D34356FULL, 0xBDCFC494E6C3D12DULL, 
            0xB6419DF66A6EE01EULL, 0x8574BB3E634825CAULL, 0x0C7D5E6F52D6C55EULL, 0xC912A48B357ED7F3ULL, 
            0x0BE83CFE8DC1D1B5ULL, 0x61077C7224686231ULL, 0x98D8CD65D65C9F47ULL, 0x231E2789C4F7D745ULL, 
            0x2329AF621973350DULL, 0x5C2C4DFFB6F95E62ULL, 0xA92332A62AF33377ULL, 0xE523994BC7C7BF17ULL
        },
        {
            0xE89C485FAE70C641ULL, 0xF72206B952E59CC1ULL, 0x264928EB0E1B9FA4ULL, 0xFC79400C22DA5288ULL, 
            0x9C4026544B0C0486ULL, 0xDAA9794BA9C9EE63ULL, 0xAA90A9928CEBAEDCULL, 0x0E7C5A9390688E35ULL, 
            0x37532F653945B6BCULL, 0x6218C0E2BFCA0C28ULL, 0xF9238B1032506FD7ULL, 0xDD029B2246FA4FD2ULL, 
            0x5E070607A1E073A9ULL, 0x23E273A0027ADDF7ULL, 0x8A9AA272BA24C578ULL, 0x8A43AECDC1E22E2DULL, 
            0x3B87C4A91293FC02ULL, 0xC9F7B01D422C60FEULL, 0xE881B17B552AB09EULL, 0xD0D9733050AD8946ULL, 
            0x5F0387B91B200C4EULL, 0xC9A29EFA969EBDDBULL, 0x35D675BBC1ADBF7DULL, 0xAFB6752CB8DAA920ULL, 
            0x2FD1009EA245FDD8ULL, 0x2EEE9A790CF243D5ULL, 0x3BA2E0D58F4B65C9ULL, 0xA766BD40AFF1A8B2ULL, 
            0xBCC15F745A892BE0ULL, 0xAFE6CE9C09E36901ULL, 0x8F93C493D1F56D7FULL, 0x6BB07866E6AD1364ULL
        },
        {
            0x6A36C6824E3F5A3AULL, 0x24FEB0692518EE65ULL, 0x13666B2B022FD631ULL, 0x6783301DC9E62608ULL, 
            0x40D55EF4D74DF42DULL, 0x82C92BA4F1E30963ULL, 0x9C79B21FE60EEC22ULL, 0x5D5DE4FAE8CB6A3EULL, 
            0x9DDE99194D2FA84CULL, 0xB32DE65A4A7015A7ULL, 0xF3B5D9314E115085ULL, 0x7FF8A2549836302FULL, 
            0x402ED5C592731D83ULL, 0xBD81137C14DF9F6EULL, 0xF3DB21B80AA9C6C8ULL, 0x0B43D3FE70D23BCAULL, 
            0x8C0D5E479C113ECCULL, 0xD3064786D9700538ULL, 0x0EEF350F2C12E697ULL, 0xF9E0317250CFFA1BULL, 
            0x83509BE83EA531F4ULL, 0x8987363C066BCB6BULL, 0xC380F42770A5E97EULL, 0x42E86BA869FEFE7BULL, 
            0xAFB17C7EEDD10299ULL, 0xC4D558DADC00FA27ULL, 0x4F1243FFB9619DBBULL, 0xD53466A54E3878E0ULL, 
            0x26195EBECCE1391EULL, 0x175601C7F96B2DB9ULL, 0x77DE37B497258271ULL, 0xDA3F1D5D23C250DEULL
        },
        {
            0x547B241D92168366ULL, 0xA2FDCD611898541BULL, 0x31AE2973249BC697ULL, 0x22CB32583795B336ULL, 
            0x6B590BF72F46A386ULL, 0x2D73350AB11F1228ULL, 0xC53BFA36006A7AD5ULL, 0xEBE09218A7BD8251ULL, 
            0xE7454047969256BEULL, 0x3D62439776550038ULL, 0xE5FECC02A30D1EA7ULL, 0x8BAA66B49E73F47EULL, 
            0x111FB1E36D9504B1ULL, 0x45BD8AF67C9036BBULL, 0xC835225F590BA401ULL, 0x987E39DF0AF21118ULL, 
            0x0E3EEB5A801B4731ULL, 0xAE601E8DEC39B9A8ULL, 0x9B3479594D2ECD6FULL, 0x1BB909B13BEC5F94ULL, 
            0x8920EA5372A9C8A3ULL, 0x431CC269134A83DEULL, 0xF67E65E92AF4D291ULL, 0x059685EA5DE217E3ULL, 
            0x240CA331B9C3A0E5ULL, 0x47AAF6CFA9182C63ULL, 0x5B7A1C9CC1A56CE1ULL, 0x6A74A13673BE70C1ULL, 
            0xF64123294D56CCD0ULL, 0xB0FDC069FC587EA7ULL, 0x7704DBE2CBF72413ULL, 0x00CCDE3BBEBF9846ULL
        },
        {
            0xA89654A09A307E1EULL, 0x498498B3A4A5F4DAULL, 0x48DC2F28A2B496CCULL, 0xC7D6F79D4596DF2FULL, 
            0x5433D0E3B56BBD1CULL, 0x46F3D9C0C4CBCA8BULL, 0x38E068B8E1852A51ULL, 0xA0BA45EC27D06FF4ULL, 
            0x3D56059A7690EC0CULL, 0x23B18E216FDA89ACULL, 0xC40C058488788999ULL, 0x03DF0AB3A6B9E16EULL, 
            0xD7F20DF06B80CC88ULL, 0x529FC26803175E45ULL, 0x5C3E8E02AC09F545ULL, 0x257D8083FC9D21C9ULL, 
            0xA9C1AC974A084724ULL, 0xFB4A09566AEE1611ULL, 0x6DC255F4B3D79371ULL, 0xF9AE0197B2EE95B9ULL, 
            0x7CD80C1809E8AE81ULL, 0x64E7C4223A8A97D6ULL, 0x66E7F28B908F21C6ULL, 0xFC84308E6DFF24F3ULL, 
            0x08C33C69A03124A5ULL, 0x5EE4ADBF7E3A96FBULL, 0xEE9B1221066BBA65ULL, 0x1DA50BFB966AAEBFULL, 
            0xB2E75B98649A49E4ULL, 0x7DD015FF5FDEA38FULL, 0x77797449B5FB4D73ULL, 0x22E7AC8B29C63649ULL
        },
        {
            0xB456C9189E48C7CEULL, 0xBF72B5E627396D27ULL, 0x391F391837442ECCULL, 0xB48AC347788B0558ULL, 
            0x9AE3EE38D3825582ULL, 0xDA8340B3D804ACB0ULL, 0xB05F4A61E614F27DULL, 0x783C6D291FB7E7C0ULL, 
            0x1786D38C481B5B9CULL, 0xD1FB220A67FC0100ULL, 0x1EDABEAAEB858905ULL, 0xF8CBD28C88B484C7ULL, 
            0x860C0227F6F08727ULL, 0x1172D4F601D4CC50ULL, 0xFB7721D55732B653ULL, 0xE24A8E849219C1B8ULL, 
            0xF9EF55E40B664385ULL, 0x2DC6EEE5FE0B2348ULL, 0x86CDD5EB664D5197ULL, 0x53E174EF3EB4AE28ULL, 
            0xD648EEE667A3D113ULL, 0xADEC797013635DF3ULL, 0x5399327189BDC458ULL, 0xBB7437A8832271CBULL, 
            0x37D0F57B6F31805EULL, 0xA729BB2C4D04DB7BULL, 0x2472693871EA46C5ULL, 0x217F96712D8892B6ULL, 
            0x15F1F78BE9088E3FULL, 0xA075D505B2DF19C0ULL, 0x4A7C7F44387D99FDULL, 0xB874527D017AE81CULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseCConstants = {
    0x264487AFCC5A627EULL,
    0xEC1449BF36F67381ULL,
    0xEE57842C7EEA4023ULL,
    0x264487AFCC5A627EULL,
    0xEC1449BF36F67381ULL,
    0xEE57842C7EEA4023ULL,
    0xAD4A632BC5AB96AEULL,
    0x5481F55BC20B6B4AULL,
    0x11,
    0x9F,
    0x3F,
    0xC3,
    0xD2,
    0x6D,
    0x6A,
    0x91
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseDSalts = {
    {
        {
            0xDFDDF0F012619BBEULL, 0xF09A6E316D21472AULL, 0xF4F8BEC92D3FEFD9ULL, 0xD6F3C2C2D6C5C82AULL, 
            0x6604D4C13280289DULL, 0x5A8DBE3DB6DB0593ULL, 0x37250A0F77A28F13ULL, 0xB8FE76F374341B4AULL, 
            0xE53AC907CD8B1948ULL, 0x062BF9128E469AD5ULL, 0x546DF70F7F025D86ULL, 0x4064A2B7971F5FF0ULL, 
            0x581F8AFD5C1256FDULL, 0x1329CD3E3FF32629ULL, 0x583DD0FF159B3CBFULL, 0x9A345172DA63DCC1ULL, 
            0xCA11CC5CE64BB061ULL, 0x91DF47BA589426BBULL, 0x3DDB3ED13305868EULL, 0x7875425784A7F198ULL, 
            0x15E49AA83A4D2D1DULL, 0x224068E31F0BAFAAULL, 0xF8D1139FE190242BULL, 0x229BC1F29CC9C55EULL, 
            0x5E198169AF85E679ULL, 0xA359DCB957111C0CULL, 0x8A602808D8A8938AULL, 0x7DE196560BE5D9E5ULL, 
            0x315BC99A2A869D95ULL, 0xC14C2D29DCA3226AULL, 0xE68CCE6CBCF81C93ULL, 0x63E9D06A5EA5BBD2ULL
        },
        {
            0x29088BF37B76D272ULL, 0x863D14841F24146AULL, 0xC69757D59B68600AULL, 0x52F88024683C8908ULL, 
            0xC1A240F0C580717DULL, 0x99C9D30082F45814ULL, 0x09AE28C67AA4B90AULL, 0x1C26B83AFC00BF72ULL, 
            0x86C0FE5B2C3A8AEBULL, 0x64C9EC7CB7D20DD3ULL, 0x3E733CF29FF40452ULL, 0x67D566F57FC8AE7DULL, 
            0xAC5AE712F95D8FB1ULL, 0x5E3A3F418350AC74ULL, 0x60E397D777F937CFULL, 0x3B5D8756E2343A90ULL, 
            0x6B2C26FD16234F2EULL, 0xC038F8CE423B37A7ULL, 0x6585062C9AED194EULL, 0x306E2EF5B427B06FULL, 
            0x41FFDBD3D2AD6134ULL, 0xF21653F7C1584785ULL, 0x5A94E2BBBA7D017AULL, 0xDA7EFEF7199E8CDAULL, 
            0xB8CF351234A754C4ULL, 0xC3418CDB8E5D2BC3ULL, 0x79DD5C75376404E6ULL, 0xFD32852E7CCA6E89ULL, 
            0x646D8E42770F81A6ULL, 0xB76B9CBCD01D40EDULL, 0x750C776B176BEE6AULL, 0x4EBBAFD7FD86EB03ULL
        },
        {
            0x5580AA60A9D51814ULL, 0x6E32FC6A451FDDD0ULL, 0x6A7292D4F6406396ULL, 0x4E75D7EF723AA46DULL, 
            0x416294AEEF641247ULL, 0x2A9A9756B451F985ULL, 0xFA22126AC93EED31ULL, 0x06108F2A3A7A088DULL, 
            0x915F3A4F5C78EB28ULL, 0xC7B3E393997EFA59ULL, 0x1B2AB3F6D809AD9FULL, 0x7B918F7E649B50ADULL, 
            0x830F70949D51275AULL, 0xDEBDCB6BAF3C3A3FULL, 0x470003BC17BA06ADULL, 0x8F8B2FA2A8CFF15FULL, 
            0xA6329625D95027ADULL, 0x395EA4FA2D13876DULL, 0x816CE63EB39E44CAULL, 0x5EA2FE67A372D720ULL, 
            0x75DC4276FFC30D75ULL, 0x82F70014594463E6ULL, 0x2C892617032640B8ULL, 0xBFC889DA6193E595ULL, 
            0x0C93350C546E5DE9ULL, 0x99AD90B8D0FB42B4ULL, 0x15FD36A231DBC864ULL, 0x281930525E58E339ULL, 
            0xE58F3679D8230D9EULL, 0xF78AA45545318F01ULL, 0xAC6D456943CED364ULL, 0xE04A266F8363C95FULL
        },
        {
            0x2F6D90938AE2D4C1ULL, 0xDD17F5CDCE99B4DFULL, 0x300B37DDFEBA678FULL, 0x1AEE639B7F23943BULL, 
            0x89DE2BD4287D3350ULL, 0xAB70E28FF53200EBULL, 0xE07A67ACD9BAB75FULL, 0x247F6D756C80D0A3ULL, 
            0x6657E774154D0F7FULL, 0x5D28621D66E23259ULL, 0x4D419C8A0C0E96F2ULL, 0xB96136A8535E712AULL, 
            0x308A35D7EF228B5AULL, 0xD8BE353832569E2AULL, 0x3DF08322A1375AD6ULL, 0xD7AE8C6DFBE73D03ULL, 
            0x087C7C5FB51B3915ULL, 0xFFC49E164125AC53ULL, 0xE6E3DEC42ED42E4DULL, 0x4669D1E6E83E35D4ULL, 
            0x05DC570991A6273BULL, 0x0FDC6CE9399272DCULL, 0x0B63B6675E64829AULL, 0xD27C5973974AB798ULL, 
            0xECEF827F217DEA0BULL, 0xB7521D3983CD3123ULL, 0xD52A552BE38C903AULL, 0xA4753B6D61D903F0ULL, 
            0x7242EC52BF92F771ULL, 0x64D979E536B2B744ULL, 0x221F5F19D2C23878ULL, 0xE2D690D59D1343B9ULL
        },
        {
            0x096BB150D16FA058ULL, 0xC523B84254B227AFULL, 0xF937754AE1394B54ULL, 0x5DE2B558C946763BULL, 
            0x1381DAB84C6DCD36ULL, 0x7DFC55D877CE589AULL, 0x97FA72E2F34A84E4ULL, 0x9D9E048F9D3B09A3ULL, 
            0x1F1747A25DDA1293ULL, 0xA4D4825BB49DDEB7ULL, 0xB456E96FC75BD2BAULL, 0x6B0B588C26F6AAA5ULL, 
            0xDF79CDAD705E8459ULL, 0xAA21E03CC8535B96ULL, 0xD6290B85826C3469ULL, 0x7B99CD084A8CB24FULL, 
            0x7480865911A06539ULL, 0x67F7B92AA02183EEULL, 0x7F39707012805C36ULL, 0x0331C32B0A14D06AULL, 
            0x514DC62EA69662EAULL, 0xAFD6BDC088AA41AAULL, 0x4BE516A90089D596ULL, 0x8D77D93AC74AD3B4ULL, 
            0xAAD4FB2660DE3982ULL, 0xFFA2E8731AB502FDULL, 0x7D8A82317671B727ULL, 0xBDFEDBFAF623D6CCULL, 
            0x0AC00D6E199B50EAULL, 0x95A8AD314CCC2F9EULL, 0x2B589EF2FA0E2E41ULL, 0x6505A57BC4B2FBDDULL
        },
        {
            0xA5BC644775C04C98ULL, 0x0F9CA96BCEE8E4C7ULL, 0xFD7BBB0334976B88ULL, 0x76DF4BB94A0CFADDULL, 
            0x456CFA4FC1ED9807ULL, 0xF9826454FAA7CDDEULL, 0xD01F7D57DDE56778ULL, 0x6B4EF791DADF2C49ULL, 
            0x82505560F45EEA12ULL, 0x8D8C4CEE34ABF3C0ULL, 0x64C51657689D13E3ULL, 0xE01987886E7D2D47ULL, 
            0x2A9EBCD68A4F1079ULL, 0x1891A3EF4C0D8481ULL, 0xC3EB020C6A030575ULL, 0xE0335480CC135807ULL, 
            0x0BF38891E13290A7ULL, 0x296A9C05BDDF6292ULL, 0x386554F7616486EAULL, 0x014C55ECEBD668D7ULL, 
            0x48A513396CE28AAFULL, 0x2FE82C2A5142B3F2ULL, 0xE1456705336AFD80ULL, 0x9B5DE5A15A127259ULL, 
            0x28B5523C879A7138ULL, 0x389DE37564A26F9BULL, 0x234CF98379A022BDULL, 0x6593F0209E655A24ULL, 
            0x49D3CCEC2594737CULL, 0x2D2ADBF75C5D38AAULL, 0x5034C34502682BA2ULL, 0xD05D3900FA87E911ULL
        }
    },
    {
        {
            0x42F2CFA91C4E2C50ULL, 0xD75D25894031B635ULL, 0x4E9DA08E3D04575AULL, 0x4DE3009D60AD8AB9ULL, 
            0x589D4EAD02B8DF20ULL, 0xC53A740BB50A358CULL, 0xD243C7F5A410D65CULL, 0xAA42F9F4E8826C1CULL, 
            0x431C6756841C42A7ULL, 0xEE6E4382119EBCADULL, 0x0B8EB04503F84AC5ULL, 0x29DE2F0F84357B67ULL, 
            0x50B6B94958B5E84AULL, 0x4AFB946088A4BF9BULL, 0x6DF8AC16262EBACAULL, 0xA4BBFDDFD9179629ULL, 
            0x790F6454F7C1CC88ULL, 0xD6F19C71D0BEFF81ULL, 0x1929318175137E53ULL, 0x21EE20AC7AF6A0A4ULL, 
            0xD4B159550992F7D4ULL, 0xD982DDA901F4ED7DULL, 0xDACB3001BCBBFCEAULL, 0x906D68BF16F54303ULL, 
            0x8740152218D7CF28ULL, 0x5646E3E36ECEF1E5ULL, 0x3AA3E949A2871F1CULL, 0x8DCBE4C1D123AFCCULL, 
            0x5BC1481C817F9B86ULL, 0xF85134557FD47218ULL, 0xDC297BB501363DCFULL, 0xBAA1D8AF58747EBAULL
        },
        {
            0xE458F434B2FE6EC4ULL, 0x28F5DC624B9AEB09ULL, 0xE087B768C3AF67FEULL, 0x2DBBAA75587C37BEULL, 
            0x772071E10F239700ULL, 0xB0197192FEA64403ULL, 0x5F0C246055D32841ULL, 0xEF6D85CBD514E644ULL, 
            0xC3DD50279D4D8FC8ULL, 0xF9534FD48D10290EULL, 0x71F33F95861BF7F3ULL, 0x4C06A31A832FEF64ULL, 
            0x8144BD8E55453D79ULL, 0x8E49A0CE4193BF3CULL, 0x2FC0FB130C6BE4A7ULL, 0xA8B7925DACEB1B86ULL, 
            0xCCA5FAAAEC63FB53ULL, 0x5DA3CFB6864C7FB9ULL, 0x41172F095BD1F782ULL, 0xB3C582649C7B57E4ULL, 
            0xA341B29D57AEA20DULL, 0xD6CCA20F1866FFB7ULL, 0xDBCD32AAB029D395ULL, 0x47C6DB71F60BB827ULL, 
            0x7BCCDC5D61182BDDULL, 0xBCB924BD9A4EDD6CULL, 0x500F7B3F8348B7C4ULL, 0x53BA40901880CEE3ULL, 
            0x78751CC4C8C3BE82ULL, 0x4637CA5B4FCC87F1ULL, 0xD698A56D83BCEFCEULL, 0x3EEA1098CE77CFA0ULL
        },
        {
            0x80A9D4D2B7B14757ULL, 0xE01F27DC2EC7F954ULL, 0xAEA3865F15172288ULL, 0x04E5D4A497786916ULL, 
            0x1E277A84D3BF0749ULL, 0xF139DA8E5B34725AULL, 0x57D56E55DCB20279ULL, 0xAFD116E231538932ULL, 
            0x0B6BA5EEF3A106BAULL, 0xAC2D95AB3CDC8A20ULL, 0xB12CA10DEDC94261ULL, 0x6AD1F35D118B14A4ULL, 
            0xECAA18A1FDED1D1FULL, 0xD0F554865014EE89ULL, 0xA597CF9FA70761A8ULL, 0xC45F3A807BB79A59ULL, 
            0x740F2B51CC6DC9DAULL, 0x5A078C9B56817B34ULL, 0x0D5A4455A51B5647ULL, 0xBDD3D4E6EC439C51ULL, 
            0x8202448252713A53ULL, 0x0E5E4A33E75A851CULL, 0x45350319E695ADB6ULL, 0xBA5BAE8D8229A5BFULL, 
            0xC6E47362D4C36FF3ULL, 0xC09BAF9DA7217B3FULL, 0x090198CF11A37CB4ULL, 0x2D2080DD9BA78D23ULL, 
            0xFC22F76517AE3280ULL, 0xF71327D262DA371CULL, 0x4737DCCE10B4BCCFULL, 0x04A0C4E342C9C8CFULL
        },
        {
            0x04429F695ED41120ULL, 0x0452341EB6D2551EULL, 0xFF13E02DF247E13EULL, 0x08E67F2B91EB9E67ULL, 
            0xC4E81CBE0D06CAE7ULL, 0x1901A0867D00C97AULL, 0x51650726300A8FC1ULL, 0xA2DB94FB0E453D30ULL, 
            0x5E53AC7D3FB583CFULL, 0x2EBE5E58F19E76E6ULL, 0x1A38CA1D1A795F9BULL, 0xBBA4FC9B628216B1ULL, 
            0x810DABE208EAB527ULL, 0xF1FA4CAB2C282DE9ULL, 0x7411AA5BBE32239EULL, 0x5F13248D8E6B236CULL, 
            0xC5BF064EB3004D01ULL, 0x0E8E15E6F1BF444CULL, 0x29F22E325DEDA2DCULL, 0xC20568A4248939CDULL, 
            0x0919584F1C9DEA0CULL, 0x62C06BADAD1E5EBAULL, 0x9113530EB67D6BC0ULL, 0xC5400DAC71C1482DULL, 
            0x074D58BD21639312ULL, 0xADFAFE3DEE7DAF7FULL, 0x0B46FB8C1EBAE95EULL, 0xB155FA479B4C9C27ULL, 
            0x840FB87E9E4ACEBAULL, 0x1172F44BDF30BA56ULL, 0x7FB5B140F47BCF15ULL, 0x05BD8ADBCB3DA377ULL
        },
        {
            0xDFE51D5F57B4A97EULL, 0x472D3E9C08CD0AEDULL, 0x46E2911CFAFBA289ULL, 0xF31F31DBBD366903ULL, 
            0x36217E7B67680FBEULL, 0x3BEEC75033F59DE0ULL, 0x9EF6E15C105B4723ULL, 0x9854A409C89AEDD1ULL, 
            0xB5369500D13E6085ULL, 0x863D7E0B06FB8997ULL, 0xDD790AB2DAEAD351ULL, 0x6E7044D6928983E2ULL, 
            0x9EB8C3F9455AC791ULL, 0xCBD942D9CE839F7FULL, 0xC48193B619E75C15ULL, 0x15E601983C4F7787ULL, 
            0xC0F0E836322C6996ULL, 0x26444B6624D77335ULL, 0xEA1D8DAEDB6748C3ULL, 0x99F146168E38C411ULL, 
            0x18E1D9C4A5424196ULL, 0x43FB6A7AE5ADF3A9ULL, 0x5E10A5685A85C36FULL, 0x784ABA5A6BE539ACULL, 
            0x41B63C5D36F114A9ULL, 0x6F8E25A3E5EDDF7BULL, 0xC28F5C0C71AF5A8CULL, 0x9B270F276658F3BDULL, 
            0xC10AFB9EA2EB38DAULL, 0x1115AFE4FFF34921ULL, 0xD08435681E65F324ULL, 0x387C83FB974E00F8ULL
        },
        {
            0x2DAB2B52E8BDF2B1ULL, 0x076FCDCC7B8D3AACULL, 0x3892A662CE375697ULL, 0xDB9284C4F075339DULL, 
            0x8FBF4868A8C522BAULL, 0x75D18940519FFDB1ULL, 0x778E0CAEB2DD0C29ULL, 0x5B335CD37DE93FB0ULL, 
            0x37D01134F298A209ULL, 0xE59C669F1007D187ULL, 0x910F5DFD2C32483BULL, 0xA71FC1E42F1304B6ULL, 
            0x21F7F2279A90D855ULL, 0x26143F413B65FF5AULL, 0xF1EDE5EE2D700575ULL, 0x502461585A3E020CULL, 
            0xA5F1363A7A3231E8ULL, 0xCD7DD9D0DA0A167FULL, 0x6A5966826E100F78ULL, 0x71AAA3E6E1BCED0BULL, 
            0x671F4B3F79C5B0E9ULL, 0xDCA6CE871B4243C5ULL, 0x541660DF78759331ULL, 0xB88D02CD773B4DBBULL, 
            0xD2E4ED85C7008A5DULL, 0x8A4067558D201E15ULL, 0xB3AE3F0BFEA69003ULL, 0x902CCBEF3A945189ULL, 
            0x51B815E902E0C682ULL, 0xC11A09F89979F9D2ULL, 0xA93E67146E3E4987ULL, 0x1D91FCD5230D09A3ULL
        }
    },
    {
        {
            0xB89024643FD36FF3ULL, 0xE9365F0BAB93D310ULL, 0x2D53A03F326A08A8ULL, 0x4932A84655B7EC0EULL, 
            0xDCD5BCC3431B7068ULL, 0xE19B1E9F3910D1FEULL, 0xACA87C3F268D040AULL, 0x8A673739F943A309ULL, 
            0x61F6472C87FC123BULL, 0x187CEAA6AB51C468ULL, 0x370F66E54ABCD9D3ULL, 0x4DABE26F97445DCBULL, 
            0x240C886B4EED1658ULL, 0xA3C2BAF4562CB215ULL, 0x94BFD982D924EF71ULL, 0x8E090C7041A2F6CBULL, 
            0xDD4BB6A6F6D9BDD5ULL, 0x00D7C3196E6843F1ULL, 0x7E8AB129256B8850ULL, 0xFD649CE0407B9507ULL, 
            0x57A5A22DAE306D20ULL, 0xBA9C10F0CFC39420ULL, 0x61EBDB025E782D70ULL, 0x6247686B5C12E095ULL, 
            0x31E7FF4F2E156EB3ULL, 0xB13CEEC43A5AA2D6ULL, 0xF102B19F241835C6ULL, 0x69DFDF00EF521453ULL, 
            0x5D9D203C63107629ULL, 0xCA0A45DA599BAB35ULL, 0x8959113CCFE1EB26ULL, 0x9D35512CB18D27DBULL
        },
        {
            0x40CC60353A80C714ULL, 0x4ABC91B93F00B12AULL, 0x098D66E3931519B4ULL, 0x553D0122B67B4007ULL, 
            0x9327CD187A7DB2A6ULL, 0xAA0A8D2EA1A07815ULL, 0x2D165626206C32C6ULL, 0xBA8EB21E032AA8CFULL, 
            0x244EA1F0FD9EB619ULL, 0xB58238DC6CA44D34ULL, 0x06143CB212D068FBULL, 0x2DD3667074EF0AA1ULL, 
            0x39C1E1DDA005F3A7ULL, 0xCC2DA693BF89C3A6ULL, 0xE61E11D089C51B6FULL, 0x7B9F00C831885513ULL, 
            0x7EC08F1155C90172ULL, 0x4B8F54139DA4F33EULL, 0x5920F8BD5E47CE16ULL, 0xB49675645622F023ULL, 
            0xE9587A5E0A833CE8ULL, 0x304220041C9E15B5ULL, 0x57C61BB7F4F017CCULL, 0xEF6540693CDC5CF0ULL, 
            0x7AB2BE382263C14EULL, 0x25B6DAAD41176937ULL, 0x89F05D90DC4EA162ULL, 0xB74D5778321C09AFULL, 
            0x27A1DE0B61BD9F77ULL, 0xADA52125042A51ECULL, 0xF889E63A062E0310ULL, 0x545562617F4F0E0CULL
        },
        {
            0xF537291D8E2F3D18ULL, 0xC6A8A8B247EAAD65ULL, 0x6CD6B43EC43CE079ULL, 0xC2A227C96E99D6D8ULL, 
            0xC6F7321571689097ULL, 0x127A01DC82FD1916ULL, 0x93788140A0A4FE6AULL, 0xD25B973BD8FFB7EDULL, 
            0x269FED903FF87734ULL, 0x0AD564580466F40AULL, 0xA6318313E2AF8B90ULL, 0x6B9A4533CB143B4FULL, 
            0x478FDC55FFD5C195ULL, 0x13DDC5D43CC81A92ULL, 0x269DE976A7D1FE5FULL, 0xFA247A19132CC10DULL, 
            0xA269706FB11EEFF4ULL, 0x942D29C52C16E017ULL, 0x0A708EB6F2D19A78ULL, 0x030938377C175410ULL, 
            0x6F9F6A430DFCAD7DULL, 0x78906AEA7168A8D2ULL, 0xEA81D64DB3020DA9ULL, 0x9D8704A164C4913FULL, 
            0xA49BE69EDEF0EBA7ULL, 0xFB0CC16A14449D49ULL, 0xB5A2041642E82478ULL, 0xB5C93C0F41F7F768ULL, 
            0x4641193327AC4942ULL, 0x57E8104BF3B01DFBULL, 0x308C8F92FF86F863ULL, 0xD2B7D83D87AFFB03ULL
        },
        {
            0x4A972054D3DFAF50ULL, 0x2693AB3C805086E9ULL, 0x4A69EECCD5F3A6C4ULL, 0x9ECBDD91C679AB86ULL, 
            0xCF41F7802D82949AULL, 0x451DDE718C520555ULL, 0x5817A3D395DBE669ULL, 0xC43C5AB1C537DDC7ULL, 
            0xDF3190B02311E8CFULL, 0x22192A96D5F04D2BULL, 0x8E9ACCED9C293AA3ULL, 0x31E06FA1D4B24B0AULL, 
            0x96610DE9A2DCC831ULL, 0x57E4671119A4D7DEULL, 0x9B22D5D94B74C589ULL, 0x730B384FDA790987ULL, 
            0x32FEF3DEC4FE35E6ULL, 0x23945299EE0FF05DULL, 0x4D5B41EB78C17A44ULL, 0x6236A828D2F04063ULL, 
            0x744980965D5F18BAULL, 0xE084FD753B2577FDULL, 0xB11A4807EED6FA54ULL, 0x7DBF823C0170605DULL, 
            0x1F3D206CAF5F2E6EULL, 0x3043E84D461AB53AULL, 0x5541D2A6AD6CB0A9ULL, 0x07015FE5BDFF7BA5ULL, 
            0x7FDCF127DCC8E719ULL, 0xD0F55FD86E2D1868ULL, 0x995D4014B9EDEE1FULL, 0xFE8D84ADF8E9AB02ULL
        },
        {
            0x66D98ABF62E74A90ULL, 0x1F32C3EE185D0C58ULL, 0x7C4FA51881C38179ULL, 0x60573FD3046C0130ULL, 
            0x8FC997B3B1C698A4ULL, 0x7F475AE1E4F08CFBULL, 0x93A2B4AD9F29CDF2ULL, 0x56889CBD157F5709ULL, 
            0x3EA328C1D7B78B6DULL, 0x84461519A57D0158ULL, 0xFB4F1C4AB70AF3D9ULL, 0xA00335B8CA123DA6ULL, 
            0x39A3FD14E4E350E7ULL, 0x40C7DEC9A9B75E12ULL, 0x0B88F6A03A60FD68ULL, 0x6252997F09D8C082ULL, 
            0xE8A7B30A49D7A499ULL, 0x9F6AD2222F64A418ULL, 0x75048557EC5DA970ULL, 0x855CF18F6872EA47ULL, 
            0x2A6854A11CDB8CFBULL, 0x7A687734A7758668ULL, 0x9ACD6E19237A07E7ULL, 0x3E4EF70AD8FBCB7FULL, 
            0x16EE67C024628612ULL, 0xEDA9DBB3FE33CDB2ULL, 0x1F5C728E0B00B655ULL, 0x94AAC879BB8470D0ULL, 
            0xA2DAF9FBA220A9E9ULL, 0x89C7CD61889A66B4ULL, 0xDA1A725CD7F2E696ULL, 0xB32E96FB3D332976ULL
        },
        {
            0x9B300C0942E3FECFULL, 0xE10379ED86B8E85EULL, 0x643B1692B66ED6CDULL, 0x269159A4603019B9ULL, 
            0x899E9D63CFB97896ULL, 0x6D243DAB695CD1FCULL, 0xA439EB574F111684ULL, 0xA66D0EA00B755315ULL, 
            0xC23FBD5487AB8A45ULL, 0x8C7DCFE9753D4AAEULL, 0x3329B1AA33A4A886ULL, 0xA31DC209FD2C14B0ULL, 
            0x63CAC26CEE853A4CULL, 0x88EB505A4636387DULL, 0x1CF1074D675F4C25ULL, 0xE2F116E3E3C2AC64ULL, 
            0xFE842486D9666A0DULL, 0x3A988A4A4CC1E05FULL, 0xC0874424681E1FA4ULL, 0x60A38B0732A2B5ACULL, 
            0x9994E731EA5DF5B8ULL, 0x8FF680581C9B1A8CULL, 0x268D27EABC7EC7D4ULL, 0xA8A9950FB3413E18ULL, 
            0x421053969C47E315ULL, 0x09891E7DC25B8F41ULL, 0x33492A04323C4A20ULL, 0x56433E75D3972276ULL, 
            0x159B2AAE8B06A270ULL, 0xAE327D2D21DBE01BULL, 0x43764BDB379D24CEULL, 0x0BD6E9537C897AA4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseDConstants = {
    0x7D13925CFFDB82C7ULL,
    0x182AAB98EC9A23E4ULL,
    0x32AE157B9B1C3DB1ULL,
    0x7D13925CFFDB82C7ULL,
    0x182AAB98EC9A23E4ULL,
    0x32AE157B9B1C3DB1ULL,
    0x5543112EA8807806ULL,
    0x5BD05356BC54B505ULL,
    0xF2,
    0x1A,
    0x3C,
    0xC9,
    0xCC,
    0x0D,
    0x51,
    0xA0
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseESalts = {
    {
        {
            0xD35097A73685BA68ULL, 0x6ACF49EFA6D9D0A3ULL, 0x75F186D5DB903C47ULL, 0xB239A39258727FBFULL, 
            0xF6CD69F5BC7C6B70ULL, 0xEA1A2EB3835DE4DDULL, 0x81E5C0D089EFFF9EULL, 0xF625FD7B9E03B4BAULL, 
            0x0B927CEEC22D1137ULL, 0xADB780DD436F966BULL, 0x6D79415F1F4ADD53ULL, 0x9054A0B105473074ULL, 
            0x1197911712A8715CULL, 0x56014C0BD8F3E5FAULL, 0x4A568D37A833828AULL, 0x4C35E708A2E4A042ULL, 
            0x613431BB5D9E8738ULL, 0x5E661C1DE31BFE91ULL, 0xD83B0144739CE2AEULL, 0x9DB5E503DA3FD68CULL, 
            0xFBF6588F8A4F1BC0ULL, 0xFC79B679A12AACCBULL, 0xCF3F1CB7DCB005E9ULL, 0x15A216A0B47C5C3EULL, 
            0xC4AF11F590BEDE6BULL, 0x4A9989EDCA5D9E23ULL, 0xE0B649872FCE3A06ULL, 0x1EA003BB2647AF07ULL, 
            0x82A9B0D267F57C36ULL, 0x3988A2AC55EAC706ULL, 0xFA92B522F9297E29ULL, 0xF876E5F7D5650D59ULL
        },
        {
            0x6D8233EB8164CEA9ULL, 0x1EF3CE17E9AF5A22ULL, 0x0D27D366B04905A6ULL, 0xBA59D8A3DA1E4994ULL, 
            0xB996ADCAD39A9751ULL, 0xCD04094849EF6343ULL, 0x537F2A791A17ED28ULL, 0x75CB1DAD372D71E2ULL, 
            0xA965E74DFFFD3EB2ULL, 0xB8BFEDC2362F4908ULL, 0x18B23AB41D7E6CF4ULL, 0x7CFC2B8EF11DF952ULL, 
            0x050DADDCBCE2858CULL, 0xCACC5FCACF11BA02ULL, 0x0DAB57FAF6469AD0ULL, 0xD9EC100F81907886ULL, 
            0x275884DBDB9A5605ULL, 0x5F982B4CA7265507ULL, 0xDD04C4980EEA2C5BULL, 0xF4F4AD74AFD70C0AULL, 
            0xFCE916CA81A3AE70ULL, 0xDFE79402EF119039ULL, 0x21A4435550B4F99FULL, 0xFF58719A30C3A4E1ULL, 
            0xD01594E8897AD403ULL, 0xE60D6F68F70E05A8ULL, 0xE0F3DA9AA4AAA9A7ULL, 0x6C3BE2038D079057ULL, 
            0xEE7B898DBBAA9288ULL, 0x3E262D8C854195F7ULL, 0x773DC5435D903673ULL, 0x3E509A98B83BC29DULL
        },
        {
            0x9CDEB77529EFEBF5ULL, 0x2CCBAF7AA5C278B4ULL, 0x186EC7476E79EC34ULL, 0xEF9CDA2FC6F8BCC8ULL, 
            0x8B1ECAFB30485DE6ULL, 0xC7FB164C8491026AULL, 0x6444B70EFAE6ABBEULL, 0xF7D79C1F561310D6ULL, 
            0x6EED5CFB173E1A9AULL, 0xE9347C6874B434EEULL, 0x4651C5193D95EE6BULL, 0x33B60A1FCE530431ULL, 
            0x57ABAE6FA52C1F42ULL, 0x686BF3D7C9C089E8ULL, 0x46118851C8B23DEEULL, 0x7E2A6DA6B828822BULL, 
            0x351C69F8AE09844FULL, 0x76A11132FC42B763ULL, 0x8EAD715F99032097ULL, 0x09DA359F6BE78959ULL, 
            0xBFA7AA53D67979A0ULL, 0xD447B3B0610280AAULL, 0xEF21AB8F05D2C41DULL, 0x620EADD08D53217EULL, 
            0x26D5CB90E013A7A5ULL, 0x6232F8400D54CC6AULL, 0x2F4FDEDA2EBA60F9ULL, 0x7E0D703CC8BE5B42ULL, 
            0xB87BA9256E506154ULL, 0x267F5B7925DE99FCULL, 0x1D0A6ADC12793806ULL, 0x74441BC62BF31745ULL
        },
        {
            0x5B9B3258E25C036DULL, 0x46333368ED1FB705ULL, 0xA8DA684858D5687BULL, 0x54DB185083D64684ULL, 
            0xE1A6ADC4EED6BA32ULL, 0x1BAFAD6E84CE2727ULL, 0x2C75F72277215022ULL, 0x4ED49C4426972039ULL, 
            0x86BE89E6581FCDCFULL, 0x16341A5CC0FA4DD0ULL, 0xABD3CE487AA848D8ULL, 0x345C51C443F67A49ULL, 
            0x306CD9BE16E7BB2CULL, 0xD3FE2F58F9C1F0FEULL, 0x31E0025BAD663AABULL, 0x7410101357A60B7EULL, 
            0xD588F2EF2F76C74EULL, 0x63C6D24C7E75B51AULL, 0xBD190B6145A100B1ULL, 0xD769F485D77F4441ULL, 
            0x7764825237D693ECULL, 0x4FC0C642066212BEULL, 0x3EDCC21CA3DC7836ULL, 0x82DCA17FB0360E80ULL, 
            0x084FAFC2DC0EEF2FULL, 0xA5D84DE67F4E161AULL, 0x1A1B5035AA34B0B5ULL, 0x1FBC917AB736C676ULL, 
            0x7D7A238A1CB54EEDULL, 0x6FDDAE5753EE6997ULL, 0x933F41AA0E54BA33ULL, 0x859271DBA92ADB2BULL
        },
        {
            0xAF551F0291EEEE13ULL, 0x425BA7A9760428E3ULL, 0x62ACEC1F20755611ULL, 0xBA82F4A53342361CULL, 
            0x39DDF1BFA4C580D1ULL, 0xBEF39E0F2B2FF832ULL, 0xDB96C6F7A867F628ULL, 0x5AA5AC9635CFF3A9ULL, 
            0xBF9322C010CCF7E2ULL, 0xE775E8BEB12AB885ULL, 0xD6F605232E603185ULL, 0x918278AACC64341AULL, 
            0x60D85E631D187776ULL, 0xC7544EDCFE30A53BULL, 0xAD0706C8795388D6ULL, 0x3A940BB0FEA788B7ULL, 
            0xF587CA1C17E0D6A7ULL, 0xC639F5D292D6DB44ULL, 0x7C6B357C225918B9ULL, 0x43D0397F0537E14CULL, 
            0xDD50B01EFC2AC06FULL, 0xB1F3CD2817564C90ULL, 0x48661C5EF86A67A9ULL, 0x26670C631D8B809FULL, 
            0xB256F4A8D59B42EFULL, 0xCC329451DDAF064CULL, 0xC11D923A38A2CF3CULL, 0xD9D42A1E8555D2F0ULL, 
            0xEF40BD9C3B65F661ULL, 0x0811CA0F5149381FULL, 0xD93A267812434241ULL, 0xC6BA378296C281F3ULL
        },
        {
            0x1C96CB5074D9051DULL, 0x998E703D15B678C9ULL, 0x121AF3167875FDBDULL, 0xCD3EE355E01615C1ULL, 
            0x4530737C6A6F17B0ULL, 0xD5AC464C90E5D5E0ULL, 0xD99542826B272614ULL, 0x31A4E8D39EAC40CBULL, 
            0xB052B61762D7ECE3ULL, 0x722AC0316AC10F43ULL, 0x65971BC5425D8272ULL, 0x86CD7629C45F54E1ULL, 
            0x1F2A40D03AAB7134ULL, 0x736FD143AA13399CULL, 0x4BAA167F441F3EE4ULL, 0x17648B2349452272ULL, 
            0x47D105FEA099A628ULL, 0xEF5DF4F7AA476E9EULL, 0xBD2E08FC7C58E00FULL, 0xCFCD4441B0BC5BAEULL, 
            0x97590F52CBC0D327ULL, 0x7E3B05A328402018ULL, 0x7F3273A07FCC5A98ULL, 0x3CF27F129EF741FFULL, 
            0xD702D7B9B7D75E03ULL, 0xAC43CC16CEEAB92AULL, 0x80764584BC539AD0ULL, 0x7B23E79A3C1BB6ABULL, 
            0x839F3B362607A961ULL, 0x974FE02B19CEFE1AULL, 0x6480BDDFB54D93D0ULL, 0x40036C8EED87F0B9ULL
        }
    },
    {
        {
            0xAB72787F09C5F2C7ULL, 0x670607BD32100A11ULL, 0x1B4829AFDE806F02ULL, 0x224C6FE4D3139C5AULL, 
            0xCD7E64BDDB0BE09CULL, 0x86C783BD76C28165ULL, 0x80FD6FDF1273772DULL, 0xFC0651F20B746992ULL, 
            0x7FABAAB321BAC9F2ULL, 0x6847D02ACA0F59D2ULL, 0x91A56792833538F4ULL, 0xB7DA6D6A4336C268ULL, 
            0xF7BFC0803B7C6764ULL, 0x6CA93702606807E6ULL, 0x1507474B617DE812ULL, 0x8DB98EC9B57F7BFEULL, 
            0xADCEC845E318131FULL, 0xA18E8DD453B23678ULL, 0x849A7645A56F9B6EULL, 0xE1EE54532FEDA662ULL, 
            0xD3D5B54C7CFE4F3FULL, 0x65B7FD0CADB430DDULL, 0x3089F69042079DCDULL, 0x1AA5D141225889C5ULL, 
            0x1C7814A747E59BC8ULL, 0x6D821D048C770EC2ULL, 0x64E459BD2129CB4AULL, 0xFC8411EE95CDD740ULL, 
            0xD8F5C85EA1369E2CULL, 0x6E2DE378B2C79CC3ULL, 0xE38F81ED729B36D7ULL, 0xDD716D6204290FC2ULL
        },
        {
            0x3AFAE24C79D80211ULL, 0x8E431921471B94A3ULL, 0x531FCF5AFA8E1EE9ULL, 0x009200C6E806CBF6ULL, 
            0xEE98CEBABB73BA55ULL, 0x235AAB7A9F74DC57ULL, 0xB80C42C36EC8692FULL, 0x2A6E1C3E9A94CB15ULL, 
            0x6DB1ED3CF9A5A175ULL, 0x550BB4C750B07E17ULL, 0x2115BC5D88FA506CULL, 0xBB40DDC63DEACC38ULL, 
            0x9EEBCABD6FB352E0ULL, 0x2E449473C0D1CACEULL, 0x949E985B202D828AULL, 0x129C86260150CCBBULL, 
            0xFEF30AC0B9848136ULL, 0xC7AB3CE89C21AA4AULL, 0xFC547E66E9E3C2CCULL, 0x3F28952DC618C469ULL, 
            0x8762B24843F06266ULL, 0xAFCFD6564926FAB6ULL, 0x8401B9C0CA48610BULL, 0x433388A14DE516B0ULL, 
            0x5B5157DDC8B49FF7ULL, 0x5281EA5B523857EDULL, 0xDEF127A093211144ULL, 0xA2D379EAC0D13D17ULL, 
            0x52D7595717D3A98FULL, 0xCAE5A456C771B55FULL, 0xB5D1AAFB058865B8ULL, 0x71D4ED8D4933A14EULL
        },
        {
            0xC2D64FD32F715966ULL, 0x9C2DEA6A14924FF6ULL, 0x9D9FFFB3E721916CULL, 0xEEF8634AE3BA1A46ULL, 
            0xB2FC8AAA855D9B41ULL, 0x367A8EA70E7D8AB0ULL, 0x2F213E8E721DF19CULL, 0xB5A0C472A8FC2205ULL, 
            0x81050C48BEFFA6CBULL, 0xE43D02732788A4C9ULL, 0xF5CD2DAEA1488EA5ULL, 0x691F8FED9E501F54ULL, 
            0x7536E9A6C77BC947ULL, 0x2B1E6CD7BF28A571ULL, 0x35D7F66D219E49A9ULL, 0xEB35FA4EDEF0F975ULL, 
            0x9F0E9E2D43050F44ULL, 0x911F3964CDAA6583ULL, 0x060EF3AD1D5A4042ULL, 0x3DA1B5B6FA1B731CULL, 
            0xE73895D90644676BULL, 0xE7AB6407177C2823ULL, 0x92F3E38B7890080BULL, 0xD32AEA4443CEE20EULL, 
            0xA7EF5E1DD83BD452ULL, 0x1416EFFC3032AE58ULL, 0xABC9D429E0395C81ULL, 0xEA3050B8AFCE402AULL, 
            0xA7620B5146BCB7A6ULL, 0x002E0A56A83D3B7EULL, 0x4A732D59E78853F4ULL, 0x128ABC8838BF446AULL
        },
        {
            0x98EA2336F02617A5ULL, 0x812B6FB3F32CCDEEULL, 0x6E8AA2EE1D9189C2ULL, 0x2DA369ABEB9D0DA1ULL, 
            0x663264142BFF996CULL, 0x4C972DEF9849C1C1ULL, 0xA664C0627DEA68EEULL, 0x2055CB2BA37CA750ULL, 
            0x0E1F77F65072A5F9ULL, 0x6CB6F0C2E1A9B9D8ULL, 0x06436E432CB56151ULL, 0x4B3A5DFE6A37AEF4ULL, 
            0x02BBCC3355296C8EULL, 0xADA27007F7066737ULL, 0xFF111E807DF38DDEULL, 0x46BCF9B13F13716AULL, 
            0x68E1E24B14DDF639ULL, 0xFA70EBFD6B817785ULL, 0x8744942109B754C2ULL, 0x578153BAFE4795C0ULL, 
            0x950EE3ED770080DAULL, 0xC3A88A8C851FA92AULL, 0x82FE47971BA70513ULL, 0x976FEF4FEE0999FCULL, 
            0x6C7244B52A3C624AULL, 0xD82DE96A29E57FD2ULL, 0x60851C52828E7243ULL, 0x9F6D4E7DFC72C265ULL, 
            0x14C7F8D3FB45188CULL, 0xB5B6552CDE7408EFULL, 0x06E087DBFA4B60D2ULL, 0xCE8FFD8FA1F8857BULL
        },
        {
            0x6AE492D4E05C9131ULL, 0xAD3B9D784EC81608ULL, 0x8070AAFB465C0D50ULL, 0x56223B6E0ED8BA8EULL, 
            0x16D9113A1E115E16ULL, 0x0677D1121292522DULL, 0xA8516290714D2D39ULL, 0xD4C4211B18E16C8CULL, 
            0x07C8F2BEA3A5A763ULL, 0x8227F27F61E312CBULL, 0xC9D588CAEBCAE8A1ULL, 0x3FD93CCAAD43AD15ULL, 
            0xFB048FE5BC621481ULL, 0x365809887AE4D93AULL, 0xE09979610F6C2ED9ULL, 0xC4AD31A4133F7BD5ULL, 
            0x39F1ECEAD51B655CULL, 0x0705E7DEED480FE2ULL, 0xAFDFDDE96D1DEF70ULL, 0xE5CF0A99F982139AULL, 
            0x65EEAAFFA7D05E34ULL, 0x02B178EA722AD51BULL, 0x7B7FE6F76C3E545EULL, 0xB9646A0B38561F94ULL, 
            0xA92F538B7FE88FBCULL, 0x62F8655158614E33ULL, 0x525B6CB0D0A97566ULL, 0x18A0CF373D883C89ULL, 
            0x9D54050B37048881ULL, 0x1E11E90E4F54CA9FULL, 0x8DE39E8352AC7737ULL, 0x46FE7D52F633CCF4ULL
        },
        {
            0xE62077010DEBC4BEULL, 0x35366BE25A55031DULL, 0x156FBA635852B5E2ULL, 0xE8BF737BF010AC33ULL, 
            0x4B5184773AF3E010ULL, 0xB4BBE3E56C4CD7C7ULL, 0xCE2272E2F7FE0429ULL, 0xE6458442E7D7B1D9ULL, 
            0x038984000D2FDD19ULL, 0x6B4E35B179E1BF10ULL, 0x4AE285225947115FULL, 0x62246303CD072654ULL, 
            0x36AEAC8BF531904AULL, 0x03F3E805ACC1112EULL, 0xD9E5A18B2B1F607BULL, 0xE2773A871AF94532ULL, 
            0x8035A5B6F6D748D1ULL, 0x7231658F566E46F0ULL, 0x27D6BB3F6E53CAEDULL, 0xF352F2B46913F4B4ULL, 
            0x190C81517E051C3DULL, 0xE48BA2B1F57E5E2AULL, 0x14758EE8B9C858F6ULL, 0xD8626BFAEAA94B3DULL, 
            0x3B6F6DA7FD5D4383ULL, 0x414D45648061411CULL, 0xB5B6A153410D3865ULL, 0xD5F659F64CA054E3ULL, 
            0xB4B7A16E13F07E80ULL, 0xD79805A1DEC48B29ULL, 0xDE2B6C1AFF939AA8ULL, 0xE4833D5B9B4F4DCEULL
        }
    },
    {
        {
            0xF7B12103C1156B84ULL, 0x873273C10C265286ULL, 0xEEA2E2B874E00429ULL, 0x553FCA62C85F338EULL, 
            0x4079FFA7DE8094B2ULL, 0x6386E081D6DA995EULL, 0x56B07D7E56887E52ULL, 0xA7E51C5FABE4091BULL, 
            0x0F68B1B3D4193104ULL, 0xBC5E2F798D16F593ULL, 0xE5C4F6A9F1929B41ULL, 0xD3A44E2AC85BC11CULL, 
            0x2212F9330EF4C084ULL, 0x78034F89D8B69263ULL, 0x5E503A5EC74A5C2BULL, 0x947F0C8A2E975A8AULL, 
            0x0BC2FCF3C5807E8EULL, 0x571C3A1239FFE3D3ULL, 0x02805F3988556542ULL, 0x34919C76F290A86CULL, 
            0x03DDE7B13E6B99BAULL, 0x2ABAF57E326C68E9ULL, 0x078BCFAC518EA083ULL, 0x36A53855E369E4DEULL, 
            0x233454BF47D62376ULL, 0x23F6655C8EB4D259ULL, 0x99E8C65E8019CAD8ULL, 0xB87B70FBEF26C600ULL, 
            0x841878B77F83B112ULL, 0xFEB3C9D4E97CF804ULL, 0xD7649E02A1E96C88ULL, 0x754AC3770DD0968FULL
        },
        {
            0x752CA340A85EBA27ULL, 0xBD576240A132E5A2ULL, 0x04D906E185524E44ULL, 0x32A0DFEB89D61A24ULL, 
            0x1A1F68A699BA6C0BULL, 0x7AF7288DA65A534FULL, 0x353B924F611A1EB7ULL, 0xF39604A017CEAD7BULL, 
            0x4F19581B9BBD0265ULL, 0xCA600BE297F52D4BULL, 0x3710CCAB5FA880A5ULL, 0xD450E1039059105FULL, 
            0xFCADAB0E69712B93ULL, 0x21B3F9199CF3A8BCULL, 0x6503E163B453587DULL, 0x2F965A3E71E27FFFULL, 
            0xDBA749041D3FF49EULL, 0xCE950DB51BD51B1DULL, 0x7AFAF281A202F371ULL, 0x17EBC6AA6ADFDFC9ULL, 
            0x7FB686C793F51403ULL, 0x27B3F8CAD9D358FBULL, 0xAFA34B0D372BD137ULL, 0x47476D12AA64AA80ULL, 
            0xA8976DE549E78FD7ULL, 0x5B1C820725BE4228ULL, 0xA543A2266C55EB0AULL, 0x204738353255D09CULL, 
            0x6FABEC6F9CAED0DAULL, 0x78C7994BE8C3EA23ULL, 0x8C9B12E9B78A6CA6ULL, 0x5A6BD2BFDDBCE495ULL
        },
        {
            0xAFA7126B9AB2E38DULL, 0x53FC62106860034AULL, 0x5DC456F2539C4BFAULL, 0xAE836757AA2B4677ULL, 
            0xE4FD934DDB4DB9F4ULL, 0x01685B6386654198ULL, 0x4A01B94F58DE8EC9ULL, 0x7942AACBBD556BA3ULL, 
            0xD4D804835807EA3CULL, 0x5C60B168509D60DEULL, 0x12A3B13F343F6D7EULL, 0xEA3E1C11E4162E8BULL, 
            0xCC83ECADA8065E88ULL, 0x15B6897EACF94D89ULL, 0xD6A85B1BC0C0F100ULL, 0x95AF2CFD62967A42ULL, 
            0x4F8A274A94C11AD5ULL, 0x5790702B6B1E381FULL, 0xE2CEFE614BA7BD75ULL, 0xEFE90C8567E6A610ULL, 
            0x864292B6D18A2A6EULL, 0xCCDBAC46C4AFC4F4ULL, 0x71028208EAF187D0ULL, 0x04C41D26491F68B2ULL, 
            0xA1D194204A6C666DULL, 0xF894AAC8A852C770ULL, 0xE1AFEB52FAB1C26BULL, 0x9C15085C6018FCF5ULL, 
            0x2121EA66FF0D6A3AULL, 0x03F19476344068BDULL, 0xB4BAA9B172FEDFBCULL, 0x2CD2850EB74A86D7ULL
        },
        {
            0x09E5C85677F42DCCULL, 0xE78ABF74B1655595ULL, 0x2ADE50F9FB736C9DULL, 0x68ABBADC9F601C6DULL, 
            0x7721889C60930505ULL, 0x8107323BE48B2977ULL, 0xACCB2978CC2B603EULL, 0x1325FAE5C06C40CDULL, 
            0xCFBA7C100F8AE9C3ULL, 0x26A6A5EFC89B79FEULL, 0xD8ED7113452AEE5EULL, 0x41B4EFD4A91EA9ACULL, 
            0x47EEB92CBD1E0B97ULL, 0x138BB8922B3FA54EULL, 0x7A9D84BF8BF9CA60ULL, 0xD4DB38B3BF151DEAULL, 
            0x4316D10CFB3340ADULL, 0x959CB984F03EB196ULL, 0x7B28AA681F7F111CULL, 0xE7DFC6E04AFB0025ULL, 
            0xBD4D3DFA0637E53AULL, 0x09054A258BCAFFEDULL, 0xE330B91E4EEDF7FBULL, 0xA444857654C6F5BBULL, 
            0xD64CDF3282A719ADULL, 0x75E7DB2A51B8B299ULL, 0xE322B6B5492B6BF4ULL, 0x904C58B33A47C744ULL, 
            0xF61DE506E73CC331ULL, 0x5099A7FA8C636EDAULL, 0x72FB1052E9C1A5D3ULL, 0x5764351078B3943BULL
        },
        {
            0xCEE38C6D983642F9ULL, 0x40F052D9EBE425A5ULL, 0x5D7E247DC713F76DULL, 0x25523F684E377248ULL, 
            0xE08FDDDD8D4C0109ULL, 0xAF2E42CC2594AC38ULL, 0x77371B5C2E7AB269ULL, 0xCBBFFD36FB6A4051ULL, 
            0x609448E0D020984CULL, 0x636BAB4BC4E10A1CULL, 0x74611BE82DB2A016ULL, 0x12C1C9B8D97F6E7FULL, 
            0x9664ABEEC83AF97BULL, 0x31E75DDE3E64224DULL, 0x0DC395EBCBBD1829ULL, 0x78E2DAE2C26E269EULL, 
            0x49569EA0B76BC7DCULL, 0xFF63297E537DAB64ULL, 0x4A7A5875B4BAF32AULL, 0xFDE738F43CB4333BULL, 
            0x944292B2B6CD17B1ULL, 0x8521F083C75B9DCAULL, 0x810A7732DE01F8CCULL, 0x8595631783282D2EULL, 
            0x02A72E54A5D758FAULL, 0x6878D9D3444671D6ULL, 0xE815E3E279E48E33ULL, 0x949138513671EC26ULL, 
            0x9E63B3CB60E5ED7CULL, 0x8F8379CAC5074A6DULL, 0x9A6B936D8513C126ULL, 0xA14DCFB0B2823801ULL
        },
        {
            0x3268CED0D66F2AD8ULL, 0xA8095385B79C4AB1ULL, 0xEEB2C056C63034AAULL, 0x83A2C6C98F2C3704ULL, 
            0x439AB7BFF078FFF5ULL, 0x2E18577F02F4E8B9ULL, 0x3B62222B5A17DE4FULL, 0xEEE3530949204145ULL, 
            0x694DFF45EEB7CFA0ULL, 0x16E44FB748D16EBAULL, 0xC29B8785D5E4C163ULL, 0x46E6A181DB21A923ULL, 
            0xD69159178E95AC98ULL, 0x2D693CC93F92A5ADULL, 0x821BAF9D3BC33EAAULL, 0x82E9CF5D8773FFC6ULL, 
            0x562BF31EA4C32F5AULL, 0x8134C3E3CDFFCE85ULL, 0xF02A234F698E5203ULL, 0x13A4E810862CE03FULL, 
            0x2D09D7740FEE00D5ULL, 0xD0653757D42B6192ULL, 0x72B378B4278F5965ULL, 0x4DBEA4C4882E67A9ULL, 
            0xC6D504E59D7D35AAULL, 0x0DB642AE84BCE1D4ULL, 0x20279A793E1CD4B6ULL, 0x56386876CEB54212ULL, 
            0xA6550C18578467D3ULL, 0xBC7E7B4685C1A5ABULL, 0x72E0CEC5E91298CFULL, 0x6E3226B9294868FDULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseEConstants = {
    0x4663E971152CBA7BULL,
    0x08AD19E4EA0BABAFULL,
    0x42F2A348E53838C8ULL,
    0x4663E971152CBA7BULL,
    0x08AD19E4EA0BABAFULL,
    0x42F2A348E53838C8ULL,
    0xB32B30F167B2C91DULL,
    0x5DEA2D6CA9FBB264ULL,
    0xCF,
    0xD4,
    0x50,
    0xAA,
    0x78,
    0x39,
    0x15,
    0x54
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseFSalts = {
    {
        {
            0xAB691A5DDE4D6CDDULL, 0x892A1CBF5E331DD4ULL, 0xF227352747FCB73DULL, 0x359CDA5197E3DD16ULL, 
            0x92F791210E318D88ULL, 0x69BCEAFD65A7EEA5ULL, 0x17465C9C116FF752ULL, 0xACD578D7F5A39E2DULL, 
            0x170C7B1486D1950DULL, 0x5B4922C72B78E354ULL, 0x180D9A0E96C0115DULL, 0x15B2B1C8E92C8CFFULL, 
            0x45967D364BFF9132ULL, 0x9DD729D531448AA9ULL, 0x48B7816F7C5FC66BULL, 0x847B88B4A222FBDCULL, 
            0x00A4A577C5E1FF69ULL, 0xA965E96DF1DBE047ULL, 0xC3A6EF8E8EA2A72DULL, 0x13FAF5896B9C4853ULL, 
            0x5D6CB82E0550C8D6ULL, 0xC897BC39D29623D1ULL, 0x7B71BB160171D90AULL, 0xECBF5564C4E35824ULL, 
            0xB40D733BB247B7BAULL, 0xA9B59E3E8FAEAFE0ULL, 0x7762ECB8CD85BDC4ULL, 0xD1FB589E889E1F59ULL, 
            0x18B393BB1224EEDEULL, 0x9010E01212A89D5AULL, 0xE2478884BAD714B3ULL, 0x5806D51686DA300FULL
        },
        {
            0xF6E40AF3E84EFC5FULL, 0x4C6AA8E127B4533AULL, 0xC781AD358188FDAEULL, 0x5C55B7F9196F4749ULL, 
            0x96B029044AE65300ULL, 0xE645C4F1F3E3B3E5ULL, 0x343BD1CC0F2F70A4ULL, 0x1DB3930A8FFC49B5ULL, 
            0x6DC6416FFAB76700ULL, 0xEB2D601619FFDDD9ULL, 0x463EC4125A87DFB6ULL, 0xD6ECA942CCD34521ULL, 
            0x56C3BBA033FB29DAULL, 0x03E00FD232BDA2C8ULL, 0x4CC59526E3FA6CFBULL, 0x172AD4E78BE36A1CULL, 
            0x2C8D775196000E92ULL, 0x9F193C59941EB7A4ULL, 0xBC7DBDB937513365ULL, 0x090E44643E8EA6BBULL, 
            0xA3767764C4A20C8BULL, 0xAF2494CC2C9275E2ULL, 0x07E569CF46B6897CULL, 0xAE2C4E90DCEE23F0ULL, 
            0x5778CF1741FCCD00ULL, 0x624AE10AD85C5F04ULL, 0x360FE6B6CE4C5018ULL, 0x8026CA26763B0F1AULL, 
            0x926517D9569F6380ULL, 0xFAF875EE24E4EF60ULL, 0xE4A6D43A4703A6E7ULL, 0xEED38D503BD6B138ULL
        },
        {
            0xFDD7E616D2170EBBULL, 0xF4A34247FF82DBA9ULL, 0x1FC4D6753242CA57ULL, 0x82C086DA8963F214ULL, 
            0x3CA8299DC5831FDCULL, 0x7C1288E2A21AB3D5ULL, 0x67D790A4E51FD000ULL, 0x7A1A5673A25BDDF6ULL, 
            0x14DC4B4E0ED84215ULL, 0xA729B98D4451E224ULL, 0x79A8E94CD032517EULL, 0x08A2D8364C623FF3ULL, 
            0x738D8F7E17FDB7BBULL, 0x7EAC36B5BDA193F4ULL, 0x93218388B3AC21C3ULL, 0xDE13BE3D6AD3C74FULL, 
            0x3DBB8B59BAFA6BCEULL, 0x58704BA22CBA36B7ULL, 0xBF8911EF9942537DULL, 0x2C9987876DD3C6C8ULL, 
            0x2AB0841BBCBFBC6EULL, 0x9229800734A59D93ULL, 0xD925F33D5A366BC9ULL, 0xDCB060018D4D6589ULL, 
            0x99AD8B53E63150C1ULL, 0x46408CC561511872ULL, 0x2AC335F76765168CULL, 0xC839434D73D9328EULL, 
            0x242686159E2A91DAULL, 0xF641F462DAA1EB95ULL, 0x63F6805D262FA006ULL, 0x3C94688A0B0BADE1ULL
        },
        {
            0x597F2684A10837E5ULL, 0x63163B1D3D4A4C0EULL, 0x2AA14BE1619E4EB8ULL, 0x795582261ACAA94DULL, 
            0x2B94583FE3E38CE9ULL, 0xE45FCA1C8CDCF585ULL, 0x9FD1933C7F282FCDULL, 0x69C0C3419AE47928ULL, 
            0x015AD8B2DDF21E26ULL, 0xCEFF074966AEE642ULL, 0xB37038E8A638759CULL, 0xFC60CEA6670C95ABULL, 
            0xEDBAEECCC8E13046ULL, 0x76179315A48E1EAEULL, 0xAE3A1618370BC258ULL, 0x5E66D884A27FB18BULL, 
            0x580BA2B781B72824ULL, 0xE2E84DFD073107D4ULL, 0x6CC9EE3BE37123CCULL, 0xAAB6D8510A040773ULL, 
            0x0FE1404F450F5910ULL, 0x10BCBBEF87117FA8ULL, 0x401D0C5833F50728ULL, 0x4FF6392F25341155ULL, 
            0x2946EA0FB7A6EC6FULL, 0xA47784A9D14F7A87ULL, 0x12E18CCAF5C16283ULL, 0x85FE1D1781F3A912ULL, 
            0xE38097E87D1E5B05ULL, 0x02D7401A5ECDFE28ULL, 0x5D6964BEFB6CE0A2ULL, 0x2D03E6ADC7361965ULL
        },
        {
            0xCF444D01ED783FDAULL, 0xD6717B3ECE8A75ACULL, 0x3D50D652E5C46A6AULL, 0xD297DC853E1EACB8ULL, 
            0x8AD53F40904454B4ULL, 0xBE7CA73BF187A3BFULL, 0xA0D3858BBCD302DDULL, 0xE64F0BF029086F1BULL, 
            0xA3FE697C0696E57FULL, 0x35DB6B5E3FB93D85ULL, 0x24A0A6E016A003E1ULL, 0xB7FEB030C467941BULL, 
            0x1AA38E6A5A70553DULL, 0x59F7BFF478502202ULL, 0xE747277E419C2E6AULL, 0x7ACEE7191C8AE141ULL, 
            0x7840AF3191D9AAE6ULL, 0x92FE8B30A59CCA53ULL, 0x98821D442361E9AFULL, 0x130D1CF4CAE33A8AULL, 
            0xF571CE32815332CDULL, 0x1FB2870A6AA0C026ULL, 0x0CE4BC53824B806AULL, 0x4B82BDD481B484D5ULL, 
            0x580D9C016945CBDEULL, 0x625341763F4BFFB7ULL, 0x016AC6FD8440B200ULL, 0x166A243B21717313ULL, 
            0x276EB52E9A2DF3F4ULL, 0x2141FC01DACC8F6CULL, 0xB593BE785A320717ULL, 0x01C4D7CF3D0E3804ULL
        },
        {
            0x8286F1B574839E94ULL, 0x05AA2795B7C21CF9ULL, 0xF14052E0E85480EEULL, 0x9CC43D4EBB53E369ULL, 
            0xF19555CCC8C16A74ULL, 0x36965F59EA0CCB87ULL, 0x27BC685FD269CE79ULL, 0xBC54DF0BD903B0D8ULL, 
            0x850C2F534CC1151BULL, 0xA46D714217388645ULL, 0xDD78FF45E11F6602ULL, 0x473FC987B17B84BEULL, 
            0x8F1B075A83E862B8ULL, 0xEAFF1BCC91EC146CULL, 0x692D3C530518C992ULL, 0x3E896E6A028BD274ULL, 
            0xA1A030C336B3B603ULL, 0x4FF02E638676479DULL, 0xD72A8D51ACA13AAAULL, 0x760412EAEA2F2AF7ULL, 
            0x479D3771B1997C36ULL, 0x5668DB2529B1D86CULL, 0xA825FB5597EA0A5BULL, 0x6482ACC2DB999122ULL, 
            0x3E3EEF09747DEA1CULL, 0xC7C24D78743BCCE6ULL, 0x4A34A0616AD4A532ULL, 0xC6ADAB767ECD8870ULL, 
            0xAC11503E823807FBULL, 0xD2170D92A6BBA071ULL, 0xB101240DBCA5B70EULL, 0xC7AA2BECF2847BC4ULL
        }
    },
    {
        {
            0x04AF73E91AD874C9ULL, 0xD007C30182D96A3BULL, 0xA248C956C01135BAULL, 0xE22935C8E472E484ULL, 
            0xB94ED8DB1AB0385CULL, 0x6D9B1C60F5F1FCD2ULL, 0x955FB9F6CC3973A6ULL, 0x3A339C85921AA44EULL, 
            0xD4CA4B6C349439A2ULL, 0xFCFB6AA5229B46BBULL, 0xEBE74883BA72B081ULL, 0x2845F9104F222A7AULL, 
            0x85B2ACF53D3D46A4ULL, 0x16E05A6A6D80CCB7ULL, 0xDF00DDEF0B58692DULL, 0x1FAC2AD1635CF85CULL, 
            0x8386324F8613BC7AULL, 0x8B54B4D63A6F44DEULL, 0xF6E3CA662A5E6B7BULL, 0xB5B0D99AB08F4F62ULL, 
            0x756C1AD1C2A48174ULL, 0xE75A240356FD8824ULL, 0xA7E7CBD7E6756750ULL, 0xFD49400525EF4FBFULL, 
            0x348A2DAB69EB4463ULL, 0x75F182923116312FULL, 0x35D579501AB6586DULL, 0xF0BA620C655338CBULL, 
            0x8B4E0ADBB62A3F3EULL, 0x46D8984B5D47B00AULL, 0xF16DE5C84B924FC5ULL, 0xBC1ADFEDBD19E374ULL
        },
        {
            0x26420FD0FAFE9D67ULL, 0x6F56B250D40FE53EULL, 0xB43D1CF3DE22D786ULL, 0xEF44EC15FCD97233ULL, 
            0xDC9097B21531131CULL, 0xEE0802B161BA3C97ULL, 0x6DAD9EFD1BA23505ULL, 0x311ABEB6566DC302ULL, 
            0x9B9D42FFA8F506F9ULL, 0xA1708BBDA3ABE6DDULL, 0x9117E02409929C28ULL, 0xA30425BDA1400AF2ULL, 
            0xC42B859E8EFE0E8DULL, 0xE78B548401724173ULL, 0x09092FA150410863ULL, 0x6E6EE1A6BAA01C68ULL, 
            0x86260418DDEAD685ULL, 0x280C562E1E1193F0ULL, 0xF934A6E52D99E73EULL, 0x4084AAC5ABE2ADF3ULL, 
            0x3921541C7461604CULL, 0xF6C620487D508B02ULL, 0x4643CF5C1B4FD7F7ULL, 0x69D488CA5095B234ULL, 
            0xC2926CD8499DB57FULL, 0x1AEC13698ABDA227ULL, 0x1C426973DAEB60BFULL, 0x8FC5A7B01A1279A2ULL, 
            0x370CA6DDD7BE6AA9ULL, 0x5106EDB5A10ECF9CULL, 0x7D1181C063D0D05DULL, 0xEE6E900B72A3C043ULL
        },
        {
            0x6E7DDBCD00345581ULL, 0x54478E8D11D8A12CULL, 0xA3232BCA436D2A24ULL, 0x00C28E09252D3D9CULL, 
            0x3C323FDD09160BC9ULL, 0x462A6DA6C29C4964ULL, 0x8DF85B78C6358C59ULL, 0x3BEF3C96CB0F1905ULL, 
            0xC9161A4529B17253ULL, 0x9CEB5CEB8D90F102ULL, 0xF18FB06002469737ULL, 0x2929C41702E81482ULL, 
            0x300CE4777A06F60DULL, 0x4F8A13CFF3362DB3ULL, 0xC8652E46F7202889ULL, 0xD0B5A4B64561A94CULL, 
            0x1854DEC49C2A9FBFULL, 0xEA84DB5330E27927ULL, 0x8ED9D1FDDD34A84DULL, 0x6106771D5DF94A81ULL, 
            0x63DD3831B9C1A301ULL, 0xA7740FFC25F9D080ULL, 0x7CE2DA71CC1F4E1AULL, 0xA5EE0297B3E9E00EULL, 
            0x02DEBA331ECABD6BULL, 0xECB30C92AA68EA78ULL, 0x7DCD236A22202C75ULL, 0x2D26E9865237FDB6ULL, 
            0x6054DFA38D84F44EULL, 0xD91D56E85940112DULL, 0x55D8D27BF0AC137FULL, 0x00F17D7DAAC4284FULL
        },
        {
            0xFE3BD7C6CE2F960CULL, 0xAB561FCF9D18F2D0ULL, 0xD9DF6E89A053B564ULL, 0xE0E53B397A2EE2BCULL, 
            0x0DB5DB7DCCA84AB9ULL, 0xF871B1FC232C64D6ULL, 0xC4B6F680AE0A8A71ULL, 0xA7C760469238E61EULL, 
            0xC5988DD34E861866ULL, 0x9BF6B80736AB7F36ULL, 0x58A0091C6F6AB33EULL, 0xA369D76C4E542925ULL, 
            0xF62C1816E15BFB8CULL, 0x8EBC3FF1D5CB3C5CULL, 0x6B3CCDB38C2EE0EDULL, 0xEF37934E8FE95887ULL, 
            0xC90517C3ADD0A585ULL, 0x01A8E548235CFCDEULL, 0x2D965ED95B123934ULL, 0xF7CFA35CB8F1D9AAULL, 
            0xF59DDEA5D6BD4AC8ULL, 0x3506CC21C572078EULL, 0x740EFFC4EE876FE3ULL, 0xE9160B7033E2E312ULL, 
            0xD510D9BF474D0AD3ULL, 0xF41AC9B29826FAD1ULL, 0x482B3C193D50598DULL, 0xC0EA66CBA993F87FULL, 
            0x6FE36079F36320F5ULL, 0xC41A026401F8B446ULL, 0xF23ABA88A979EAA0ULL, 0x53E5CF52A0DE3237ULL
        },
        {
            0xB78A0F70DA19D453ULL, 0x753DEA8046C081FEULL, 0x72008F78F6F6E830ULL, 0x8C6DAE3DD17D4240ULL, 
            0x8696710C05862C59ULL, 0x171984DE0125DE76ULL, 0x1F083914AEB734B7ULL, 0xD35EFC5E430010D0ULL, 
            0x39E4B82771985EBDULL, 0x8A3E4B056BDDFB75ULL, 0x0DB9A2EB4C9F9B79ULL, 0xE8E409393084EB4BULL, 
            0xC9E10FD1C9F6EFD4ULL, 0xF5CE96BFB2472ECDULL, 0x32083D6CE5F9EF05ULL, 0xF40000FA52D13B24ULL, 
            0xD6FD9915E0E83132ULL, 0x98FB6F8C105B1951ULL, 0xC94B021C0891D71CULL, 0xC51E4887C9048B2DULL, 
            0x21A68CA69EC1BFE5ULL, 0x4AA317E64B32B251ULL, 0x3564DF1AA7C16A01ULL, 0x0AF46AE4ECA87631ULL, 
            0xFBC469ED48C3128CULL, 0x4C48174A8A3D893BULL, 0xC14A49E7F3356D65ULL, 0x29B1D96FE0CE3260ULL, 
            0xD7EE551F308BAB35ULL, 0x570163BB9DCF7129ULL, 0xEF76A30C865EFA78ULL, 0x1F87A948BA5C4BD3ULL
        },
        {
            0x8A8E3FC49323ABCAULL, 0x49BDDA53BDCF4051ULL, 0x42C1ABF0454A5852ULL, 0x6BFCD7BB1EFDD63BULL, 
            0xBE897A702C77A794ULL, 0x01370A92FE42EFD3ULL, 0x093669A1AD8BAB91ULL, 0xF45F0F962377BE46ULL, 
            0xC47ADA861ECA73ADULL, 0xB5B237CE342A1D55ULL, 0xDA42466938EF8289ULL, 0x73020032F2895703ULL, 
            0x4C7655E3E4B68933ULL, 0xF902D1EDDA6CA80BULL, 0x2C78966053B9E431ULL, 0x795B85142DB7CE49ULL, 
            0x274BF0E8B621E137ULL, 0x635DB1ABFD5158EEULL, 0x2C2BEACF99C4B023ULL, 0x54410D2441225B5BULL, 
            0xE81B2F1A16F6528AULL, 0x018260378E4E7BBCULL, 0xF277D27D17C170FFULL, 0x6F26C20DD3FCE73DULL, 
            0x9FF3402CBA6705E5ULL, 0x7DC45AB9A9520B05ULL, 0x06C4DAEBCE85B4B5ULL, 0x6D91F8CCBE09FC27ULL, 
            0x5DB8F9A0F288131BULL, 0x764F6E6A1C086EC6ULL, 0x1E947D5E49CB34B5ULL, 0xF87BE47FA49D18C0ULL
        }
    },
    {
        {
            0xAC2F27195993C18FULL, 0x4022C83DE3C6E829ULL, 0xB82D09D9114751A6ULL, 0x5EB21567F99EB67BULL, 
            0x2FC853E314A5BA0AULL, 0x31026F9EB872D4B9ULL, 0x004775477C03DBF6ULL, 0x670D00636A9B2DB0ULL, 
            0x34F36C5A0D748CBDULL, 0xEB8DB1A6BAA7013EULL, 0x85E3A03D88B8B3BBULL, 0xC5CA2AB38CE433D7ULL, 
            0x04AF503029A7155AULL, 0x32BF8BDEE92A97E6ULL, 0x96149819FD32FEA6ULL, 0x85D83387469061A0ULL, 
            0x9FD65D6E01CE62D8ULL, 0x2D38A0B63963FFA3ULL, 0xE3040E3606623723ULL, 0x0D8AC5E438F53F90ULL, 
            0x069A3B1A50507400ULL, 0xDCF39E5893AC3430ULL, 0xBBD5F0ACF2F65E9BULL, 0x562A9AFD03409A5DULL, 
            0x611835B536AE9CB7ULL, 0x9612E3C6F82B818AULL, 0x18D1F562E5062BB2ULL, 0x1EFBE09EB3C37A09ULL, 
            0x6E1C2D07A90E91B7ULL, 0xB3502B631FF7E3B3ULL, 0x7A7A9C2A4E806B9DULL, 0xE2E36E8EEDBE7975ULL
        },
        {
            0x776CD692E2201811ULL, 0xEB36F9572AE5899CULL, 0xF102060308206732ULL, 0x37BD9B068360C01DULL, 
            0x45AE55F0CD556F6CULL, 0x366DEB174A1E59F6ULL, 0xA500C0737AF47D37ULL, 0x029B5A3C8C65DEA6ULL, 
            0xBC2DBA0918BE1213ULL, 0x4B7191AF587C7487ULL, 0xC6CB7F8203A35813ULL, 0x70A889BE1963DD54ULL, 
            0x3BF6A24CA677B30EULL, 0x3B5CCFB26D0DBD27ULL, 0x9D385072F83F486EULL, 0x8ED1B370DC81CD2EULL, 
            0x4E5BE567FF563F46ULL, 0xAACDA5330986AA0BULL, 0x7D3A3D5A3B1A63BAULL, 0xBC562304BAF6882BULL, 
            0xC3123B80E0761184ULL, 0xFDAC34C179879D66ULL, 0x5450F89231D87A4AULL, 0xAE99E90B7F43E3F5ULL, 
            0x98D205261F5A9411ULL, 0x3A11C6189FBFA391ULL, 0xDD18D31A257CA827ULL, 0x7A61359FC9DD6638ULL, 
            0x680246B1C8EF718EULL, 0x45CD29B6EF6582C8ULL, 0x75E88DFA3A8BFBADULL, 0x09CDB9AB94DF8784ULL
        },
        {
            0x4FA292EDD7AF4398ULL, 0xE2215E2FE2172749ULL, 0x2085A55C3122CC41ULL, 0x7E31BB172786F795ULL, 
            0x76DC731BA2ED922DULL, 0x033C2AF9CDE460D8ULL, 0xB1ACF653242DF330ULL, 0x60E3AB34ACCFD16CULL, 
            0x3EDC8D4BD5B82D1CULL, 0xA673CA6A78F7CB7FULL, 0xCD93F7AA6CEF5DAEULL, 0x69DBAB7D67C637ECULL, 
            0xCAEBAC755499A71BULL, 0xF7ED94FDFFDFBF8DULL, 0x88ADF593F2F2ABB9ULL, 0x3BFEA51B2F04DED5ULL, 
            0x467424974A064592ULL, 0xAA519B4753D6FC12ULL, 0x41602CBB5A36CADDULL, 0x0C80FA2F2E381550ULL, 
            0xEB60DCBC76910F3EULL, 0x50EC4D0348126964ULL, 0xAB46F9FCD9B5B91CULL, 0x80513E189E6487F3ULL, 
            0xBBC707AC627E120BULL, 0x2286110D38A5AECEULL, 0x957D7FA6198E74AEULL, 0x3128FB79F25BA4A6ULL, 
            0xE66D536032797AE3ULL, 0xF64C226759A896CBULL, 0x06E458D6D5599EFDULL, 0xA4AF6151B6BF9628ULL
        },
        {
            0x4BD45686E27BC5A0ULL, 0x436BC98772FCF89FULL, 0x1D1EB5C8E67C7A19ULL, 0x332155159E885883ULL, 
            0x1692C81991095B86ULL, 0xE5244E62A27F6053ULL, 0xFEE20B7830B2A311ULL, 0xB842E881B9B66DB6ULL, 
            0xE8B393A8A286DF08ULL, 0x369D3456F6F447A7ULL, 0xA2401D49846A229AULL, 0x425A21F7EE1BB6FBULL, 
            0xC7E187134AFE3E43ULL, 0x60B47DE585A821C3ULL, 0x8C5716ADD9CB131EULL, 0x1853BE637993CCCDULL, 
            0xAD0B0F8C21D9463DULL, 0x1659A73B287DF277ULL, 0xAD9383FD535D091DULL, 0x8900C10E5462F1C4ULL, 
            0x6DA64CC9BC1A34D6ULL, 0xB8EF09D4CD793233ULL, 0x2749831CE3C14207ULL, 0x9FDBC73FFF8FC4E0ULL, 
            0x6DDEE85D0DE92219ULL, 0x5F6CAAC3F2360E1EULL, 0x2E437029FF8DA380ULL, 0x602B09ED1B5835ABULL, 
            0x8629BC60FC46C4B5ULL, 0x792BF0E246EE1A2CULL, 0x88C68B222366BED1ULL, 0x5CE42D06F143FC4EULL
        },
        {
            0x67EE5872FA234958ULL, 0xED3EEDADFBA4093AULL, 0x8959ABFF0FB2A12BULL, 0x7BB55266F1AA0D12ULL, 
            0x5CDE689E9741D6D6ULL, 0xC7D6C03606E108DCULL, 0x058FB89720ABB0BEULL, 0x9BA37A8DB2C3484FULL, 
            0x89F0EF2D0F11C116ULL, 0x856F3D0CE7969613ULL, 0xC43C045349CFC9DAULL, 0xC10B79BA77404B5EULL, 
            0xDE2F645209047E01ULL, 0x89F68E6F991FF891ULL, 0x079F8C36EEBDA208ULL, 0x9A2A0AC8F876E515ULL, 
            0x437BD19DA65E2FD2ULL, 0x03A70958202F63D7ULL, 0x6084E72CE4C658A6ULL, 0x2B7A2F69578BB1EEULL, 
            0xE4ED44A38695A23CULL, 0xC8C3BFCE03631F26ULL, 0x55DD30617AA2FE79ULL, 0xE81192CD92CAC709ULL, 
            0x51CA8DCFFEA3AB95ULL, 0xF331711804004EF1ULL, 0xA4F85AC6E617912CULL, 0xAE1C51F6EB4F0A9AULL, 
            0x40A08F1B81D3D65DULL, 0x84536BCC07DCE345ULL, 0x1CC6DDE7B994D7F0ULL, 0x7DB6511745A20F78ULL
        },
        {
            0xE6605917E8DF8940ULL, 0x14080E21D32B56FBULL, 0x717473752DE03F2CULL, 0xB1EB72811E119B69ULL, 
            0xD72CF19C9E210146ULL, 0xF955770F04B95475ULL, 0x669377BFC1666283ULL, 0xE2913AB5D70B5748ULL, 
            0x7F77E9729DBBF6F2ULL, 0xA3933C6060214A54ULL, 0xFEA14ABE37F932CFULL, 0x551F7FDF1819B0FDULL, 
            0xAF79980680559498ULL, 0xA01FB42D37A5DC2DULL, 0x54B1CDA3E70B676EULL, 0xEB119DD0C8B8086BULL, 
            0x5B4D9CD97C8189B1ULL, 0x157CD345CAC17AACULL, 0xB2FCF77BD7B0DAB3ULL, 0xE2096599C3332FC8ULL, 
            0xE54BB7B528116FF1ULL, 0xE973F2BBDC37E802ULL, 0x5F793A7E53EC4D9FULL, 0x1B42F7888B685B15ULL, 
            0x2C8EABBB02C181DAULL, 0x9420E88B22CF1A36ULL, 0xB71A3C7CCA51B323ULL, 0x7941CDE2A18006F1ULL, 
            0x69A7E81D00C065FDULL, 0xC367B7EBFCA893E1ULL, 0x39C849494EBF7CBCULL, 0x9A9F03CAF67C7046ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseFConstants = {
    0x59067B5D1A8FC18FULL,
    0x24A3CAAE526A5950ULL,
    0xF262324B0B0B0BD3ULL,
    0x59067B5D1A8FC18FULL,
    0x24A3CAAE526A5950ULL,
    0xF262324B0B0B0BD3ULL,
    0xA28DDF4D946F2931ULL,
    0x7F7385EAFD3CBF44ULL,
    0x14,
    0xF4,
    0x5C,
    0x23,
    0x35,
    0x04,
    0x67,
    0x7E
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseGSalts = {
    {
        {
            0xCA320186FD11BE75ULL, 0x666D484EB56ED9FEULL, 0x67D7792AED1A2B19ULL, 0xA64CF2FA00A8646FULL, 
            0x5FCF6C545FC5134DULL, 0x852D5DEDC1588445ULL, 0xF7D53FE12A9F891DULL, 0x20179337563155FAULL, 
            0xFD1C4B22586D2467ULL, 0x4BE666E564E5EC52ULL, 0x99C879BCD06998B4ULL, 0x6EF364AF7CF036CDULL, 
            0x0BFA0B88F447CCF5ULL, 0xA95B4DA386E5D92FULL, 0x4D57816451A9E448ULL, 0x35919ED5F6C35FDFULL, 
            0x01D3262A9E594AB4ULL, 0xAFDD5D3BFAD55137ULL, 0x5E1C06C5DCF2CC75ULL, 0x804FCD4238D72A34ULL, 
            0xD70BD0E009E33754ULL, 0x7CA3DFAB3C4F5CABULL, 0x094B4202D672BD7AULL, 0x9123688F2C3C1CC9ULL, 
            0x8DFFC20ECB1AF9A7ULL, 0x092351C5C6C00C9EULL, 0x42A2FFA43047373FULL, 0x9D7D4204B2F08FF3ULL, 
            0x180FD022532CE619ULL, 0x567D2635262D41E1ULL, 0xFC5EC0F7F8D27963ULL, 0x847CE15FC9C56C04ULL
        },
        {
            0xCDB79CF74BF046C7ULL, 0xE58C6A1EB1EC7A12ULL, 0x21788377A66F43ADULL, 0x0C93200E6C58E184ULL, 
            0x7FFB0B83678D7F17ULL, 0x8035FEF500FBABB6ULL, 0x2DB013A268F66F38ULL, 0xFD9F220946B2ADA6ULL, 
            0x7497A8F2D6F5F088ULL, 0xAB0357B140726775ULL, 0xC67FFF2A0F15982CULL, 0xA6A5DE26EDF260A6ULL, 
            0x0F6010801B2CC917ULL, 0xF65D1BBFCBA31D63ULL, 0x1B09B939D8BB6D1CULL, 0xEA8F76AD3344085FULL, 
            0x397CA41A2FE3D7CBULL, 0x1A2F536F1AC47FDCULL, 0x1BFEBE494E46888DULL, 0xC0F5A3AD777EB197ULL, 
            0x9D200907C7C72210ULL, 0x9FCF8C7EFA97A148ULL, 0xF63389F49D9F2AE2ULL, 0x140249EB12E9F88FULL, 
            0x5A7DBC2D5C337A0CULL, 0x6906F319C48E544EULL, 0x808228EA3D270E94ULL, 0x1A1BDEC63550C8F1ULL, 
            0x64E54AFE7D0A390FULL, 0x159061A68EB37452ULL, 0xEA526838BD918E5EULL, 0x0DEA4E003C0FCA63ULL
        },
        {
            0xD5F6843F902DD9D9ULL, 0x4BF2C16AB285C7BFULL, 0x2D17D25C465A4540ULL, 0x60BE85D74B8D6C00ULL, 
            0x7FCA8986965667F5ULL, 0xCEE1679FDA847468ULL, 0xF82BFBAE192D3538ULL, 0xA33E5C3E670F46BCULL, 
            0xB7D896A3DFB5B024ULL, 0xBCC64E3C2B89DAB6ULL, 0x2F5ABA9720A1AA5DULL, 0xF9C8393E133F16F9ULL, 
            0x071980EF490646B3ULL, 0xB9795543FC2D6ED1ULL, 0x4A73F3D15C79DC85ULL, 0x7C378449F9036BCAULL, 
            0x29661401C749E89FULL, 0xC78ABC8FE94D5505ULL, 0xCE415ECE0B5D5F45ULL, 0xAC6F477365BC5F14ULL, 
            0x39BB9FE28A28B4A0ULL, 0x0CE850F950046CC6ULL, 0xF111CAFF4755378AULL, 0x99D96E327E4D0196ULL, 
            0xC81056475D22324DULL, 0x959FFD8F74685A70ULL, 0xECE738AB29F63995ULL, 0x0F28D9B69947128DULL, 
            0x02E7749DB9E44E66ULL, 0x341A926A3BCEFBD3ULL, 0x6B3605C1D420FA38ULL, 0x17F61E113D78CA6CULL
        },
        {
            0xC33FE4070006BBD0ULL, 0xA4A948AE504C060DULL, 0xAF681C219D8E9285ULL, 0xFAAE6CD6C743254FULL, 
            0xDD5B24A9C881C697ULL, 0xC3CDCDFB2A3B8605ULL, 0x8277D1EBF0DDC2E4ULL, 0x2DD51F42BA2065C6ULL, 
            0xED8B88F9C9C28029ULL, 0x33A2979544DA1D7CULL, 0x7BDFF98F995C55DCULL, 0x27CBD5D27D7E05E8ULL, 
            0x15589EBFB6C20D35ULL, 0x54C2A1EB2D0CD0F6ULL, 0xAA835425D6EEED4DULL, 0x4B94C3C4CA69EEC2ULL, 
            0x3F9E9FB4FDE98A94ULL, 0x95BE8443BA9BC4DFULL, 0x4705607B245E0A80ULL, 0xE6983B7F3912DE3EULL, 
            0x8743572ADD41C42FULL, 0x0788F2DB21A87367ULL, 0x684167A52501F5BAULL, 0x60EA9C3881B5B39CULL, 
            0xE635CC7267742C9BULL, 0x22B041F893E9BC08ULL, 0x5F95B581CE99A2A1ULL, 0x929AAC6FF8444B97ULL, 
            0x8AA276D223479253ULL, 0x354C09DBFC6456B5ULL, 0x6D6444FA7795428AULL, 0x833CDCBD74B4CC95ULL
        },
        {
            0xA7DC4EE17DB13888ULL, 0x656D41B87DE6BEDBULL, 0x044D34D3DC4BBC6BULL, 0x8459152842D2313EULL, 
            0xF9A32F4F8FB265B6ULL, 0x74C02E0B677754C7ULL, 0xDD51A09D81907ED1ULL, 0x88887C6412544B9FULL, 
            0x555278044D98E35FULL, 0x6AE3F34D6A2F6565ULL, 0x0D24146F6B616806ULL, 0x0390A17195B98C43ULL, 
            0xB3362101687D2050ULL, 0x06A63AFBFF3EFD63ULL, 0x92DEEB6AFD00E52FULL, 0x888B55621F494374ULL, 
            0x2F0C211B8D761475ULL, 0xEDA0EC124B80391AULL, 0x7FB05DD2BA1B1A0FULL, 0xB90F7BBF21A2F64DULL, 
            0xC01A6DBB11304291ULL, 0x551135B45B12D439ULL, 0xD5CFBC2BE62C9A11ULL, 0x264546A694BD7ACCULL, 
            0xA9EB317343EF0594ULL, 0xF9455EBC5BE16607ULL, 0x1F0EFA72F60155B8ULL, 0x57B12CD2F9B6DBA2ULL, 
            0x3440941E5DB8254DULL, 0x9C2059FCA17DA682ULL, 0x04D6BCE6F7EC0DF8ULL, 0xD8B17B4FDB9EB472ULL
        },
        {
            0x48E84FAB2687EB5EULL, 0xAEFD0DCD01625F23ULL, 0x8E20499424D354B0ULL, 0xD33634106DD03939ULL, 
            0x059E71310544A9E0ULL, 0xFADD771E8D5ED082ULL, 0xD143D9D58718E7E6ULL, 0x8FF441ED2975EC63ULL, 
            0xCA65C1C7F3A281AFULL, 0x6B1BF98AD90EBBC9ULL, 0xBC58F629003972ECULL, 0xE50E7F2FFC1AE74FULL, 
            0xAAE995C78A3C829EULL, 0xC0267ABBEFFEAC5DULL, 0x139A1C814FB006BAULL, 0x3001BE8CBA759FEFULL, 
            0x011B6612A11FF8AFULL, 0xB579740A7151FD70ULL, 0xAD1B0F8243CC4F55ULL, 0x41C9C6633D1B1843ULL, 
            0x35E4FD58278AAE8DULL, 0xFFE0D238AAD05E35ULL, 0xE696447DDB33B4E2ULL, 0xFDFFFCC5EFDA8252ULL, 
            0x7DF0A36A615A64A4ULL, 0xA7E567C238660FD0ULL, 0x05EC2BC0CAF307BCULL, 0x9A8C1562E0E2225FULL, 
            0xEF5F8B4DED1840F1ULL, 0x75E2449E8C28A786ULL, 0x7EF2D315B95C603DULL, 0xBD6AD4895023AB36ULL
        }
    },
    {
        {
            0x22BFFB4020EBB006ULL, 0x9829266DF569B110ULL, 0x8230F8B4749645CDULL, 0xEEEE78BD9095A533ULL, 
            0x2DC099F944F93A44ULL, 0x02FEA82034132B17ULL, 0xF775621FAE74684FULL, 0xDB7A0298EBDAB4DFULL, 
            0xD76C233E44E0F14AULL, 0x2CFE3EA741CC881CULL, 0x0AEB21F09467AE8FULL, 0x71E5B5A2F1BF02EEULL, 
            0x6D5C2C8E8C3ECDDAULL, 0xA0802DF9E27420D1ULL, 0x28F4E9130A8649B6ULL, 0x2E761AE099644417ULL, 
            0xFCF099202435A3D8ULL, 0x629CFE0D65A018C7ULL, 0x805BD855970B9A41ULL, 0x50E7F357EF9F5273ULL, 
            0xFA2FF115181B54BDULL, 0x0D27CB7A08A72A30ULL, 0xD8B1E781BEA50B9AULL, 0x7D35712C2FF4C752ULL, 
            0x4BF302B133ABF1ABULL, 0x6B0863702EB80AB8ULL, 0x05D4DA1EF51BBAE6ULL, 0x1E0875EF7C6C5CD7ULL, 
            0xB6D07ACA37C3A46EULL, 0xA8823A92D6D6BD9BULL, 0x3D0AC47B007B1C3FULL, 0xA82E4D6C99274549ULL
        },
        {
            0x454B99A53E347241ULL, 0x5580C9E9A66C9B47ULL, 0x13A4050531FEBB23ULL, 0xB729AF8CAAB565E2ULL, 
            0x0A8A7B37F2CB8D0EULL, 0x03B4AC3FD11E0EB6ULL, 0x9FB2B6A0E7020B42ULL, 0x5596C7EB0BACC718ULL, 
            0x9F1108652D6C0019ULL, 0xAFB0190B2FD58260ULL, 0x671447A6E2929553ULL, 0x5A5D40708DC79512ULL, 
            0x5D0DF4A16F21739DULL, 0x048F341D676E8174ULL, 0x6F15D6B2CEC65752ULL, 0xCD7B2497834D4D29ULL, 
            0xEA241E2C443C581DULL, 0x8F9E56E312D80648ULL, 0xEA14FCA0BAEB3D52ULL, 0xDCA74E16ACA699CFULL, 
            0xBEDE7DA7B5D4BB15ULL, 0xE4649169940F605AULL, 0x8286E2F08D343E97ULL, 0xAEB99E08D5623DBDULL, 
            0x3E22044692EC260DULL, 0xA7CA7E04821D504EULL, 0x9FAEDE10697BF1FCULL, 0x093ABEE6FCB8768FULL, 
            0x96C0CF66F467DE81ULL, 0x690D240299A55C50ULL, 0xBB700DF6EDB7BAF3ULL, 0x1D5B7EF2A232EE2DULL
        },
        {
            0xEC73F9A499DA57B2ULL, 0xD6755186ECA2257AULL, 0x7A65C3817319BC69ULL, 0xAFA039F7712D2A19ULL, 
            0xC26761296ACAC8F6ULL, 0x13A6C99A31A48D99ULL, 0x65E392955777BDACULL, 0xC6370C63BD80D575ULL, 
            0x467599BD510601EEULL, 0xFE200133ACC4AF9BULL, 0xA93114A92CCE4A78ULL, 0x5572BC239F3D7881ULL, 
            0x55D4845FC11C8EF8ULL, 0x8FABB933929FD8E1ULL, 0xC71A0B98DACE14ABULL, 0x1B8FCFF8C703DE3BULL, 
            0x3F749A6F77B93AEEULL, 0x38CD2D54E10AC0F4ULL, 0xAA577A279F8C512DULL, 0x13DCE46934900DFFULL, 
            0x3D1C6CA057C4E141ULL, 0xE4252E0EF552168FULL, 0xAD29BC2F776D793DULL, 0x8CC996CEDA16F081ULL, 
            0xFFBDFFD5F23E3B14ULL, 0xFB11CC4FFA63FB4CULL, 0x2724BD3952531527ULL, 0x2A8B26EB93805AE4ULL, 
            0xD59D30F9A6C8AF29ULL, 0x62A9D1573FC3D0DAULL, 0x70C2066ADA8D04CBULL, 0xFDDABE0B06A14D70ULL
        },
        {
            0xBBA25404077A55B5ULL, 0x793F68E94BD14429ULL, 0x1C3481D9BA52D8C6ULL, 0x885F2CC9C84411F0ULL, 
            0x1D4F3159CA3ADA21ULL, 0xBE3872AE52C341D9ULL, 0xD865F26BC464C23DULL, 0x89D8C164574BC030ULL, 
            0xE1CABCE3A11EB7EFULL, 0x7D6A5077AC4B71A6ULL, 0x048B19DB1CB59BB3ULL, 0xB957837EF44C213BULL, 
            0xA72E1CDCD5BDF3EDULL, 0xDA23C5C8D25428B8ULL, 0xA1B4F301CC171E03ULL, 0x73433574EABC72A8ULL, 
            0xCECD2CED7460E555ULL, 0xA0EE5B2107DB196EULL, 0x93547728C9E3C886ULL, 0x0DF7275D1BEBA954ULL, 
            0xCD272B1A6D163B5DULL, 0xC0C394E71D9DA44FULL, 0xA3BCB796BCD20270ULL, 0x190364D06B70155CULL, 
            0x0BC35AB2CCDC014FULL, 0x59E721167AC1B3B2ULL, 0xD054C508D7E9BA28ULL, 0x7E2FA86A20E3F9D2ULL, 
            0xD469734411CD55ADULL, 0xC59919B7E3B7D65EULL, 0x7CCA1D39FA2F4803ULL, 0x1483561559762795ULL
        },
        {
            0x0B840DE38B5738EFULL, 0xCAB6F209DEDD7634ULL, 0xD7770529949DF4CBULL, 0x0A02763E2CB1585CULL, 
            0xA4E56FEAE937ADC8ULL, 0x5252FB440A629F9EULL, 0x42704FBA98968098ULL, 0x4A7898C4588FC0B2ULL, 
            0x2A3F3C0FE1B88255ULL, 0x192AE7B9AAE662B6ULL, 0xC1A504D326E71F10ULL, 0x203E250B1DBADE82ULL, 
            0xDDDE52620DB0FAC3ULL, 0xCD6B352061226DA2ULL, 0x4BBB94416524554CULL, 0x2E699FFE9530B487ULL, 
            0x96B5F6C847210C86ULL, 0xF55E74CD1BBD7F62ULL, 0xA80DD88D373BB36DULL, 0x18223EBB76210138ULL, 
            0x35A3DC9D2ADD59C0ULL, 0x33A87B8F8E5B61D4ULL, 0xCAAAD92D683C7C13ULL, 0xE058B4A48033A6EAULL, 
            0xC3854716012108D6ULL, 0x028AA4955EB6F9C9ULL, 0x5037E5B092711B44ULL, 0x2412BC8FAD66CE9AULL, 
            0xCB0BD7A37A7987E4ULL, 0xB5BBC9657D75D747ULL, 0x4314739598416501ULL, 0x5FEFA8DC9835839AULL
        },
        {
            0x1818A88980096B63ULL, 0x1B04FF896B6ADEABULL, 0xCD09B92B96997B24ULL, 0x2C2BB64E2A1F4D77ULL, 
            0x3BE9CC1277738060ULL, 0xB504D3B81ACDBAF6ULL, 0x8D545C8727D3A235ULL, 0xA19ACBAF1D85B5FBULL, 
            0xB0E6CA51500C74DCULL, 0x90C8AA92FFA197ADULL, 0x5E26085C94E50057ULL, 0xF5A1A16582A55370ULL, 
            0x7A1E5774F68547D3ULL, 0x685594574890A209ULL, 0x221F1DD17A91FD1DULL, 0x102152A850ADE0F6ULL, 
            0xAA8C163E3EEE2720ULL, 0x5D268FF8EA1E4747ULL, 0x64E071A3050DE2F9ULL, 0x6E03633795743D07ULL, 
            0x1DBA0E9B6EF83FE3ULL, 0xACAF5F8CB8584330ULL, 0x979B2A3BE53C7D3FULL, 0xB2B550DDD456FCADULL, 
            0x363B37EC1DC4BB84ULL, 0xB8E98B5E5AC16495ULL, 0xDF9A4AD983F3DD5CULL, 0x4DF57129E6A8CBAFULL, 
            0x8C303F445AC66FE4ULL, 0xCA486F770CB11BB9ULL, 0xA5322229549711FFULL, 0x8A2218D86EC35656ULL
        }
    },
    {
        {
            0x94E513DBA17C3FDCULL, 0xD0EA9122FE00B4C2ULL, 0x468DB45086F0EA5BULL, 0x85480437B338EBADULL, 
            0xAECBBD82C638A3DDULL, 0x44FCDB12F7DA68F2ULL, 0x86B2B204D4C14B2DULL, 0xEEDADAE81ED29672ULL, 
            0x638E72723DB40412ULL, 0xB362A801D8F72CEBULL, 0x63085EF0CF50A3F1ULL, 0x4B83787EB9E6EF92ULL, 
            0x99AE9EC97C8D7B95ULL, 0x09905067AD162966ULL, 0xE9EF525005E08C97ULL, 0x4F4F1B5F2AF24487ULL, 
            0x3FC386F0A4A7D73AULL, 0xEC8DA00844735D3EULL, 0x30FF48574BCDE5FBULL, 0xF4A8FF28F8D058AEULL, 
            0x4C44F7A3EC6BCAECULL, 0x96E7BD32DAA6B4FDULL, 0x7289D430C65472A3ULL, 0xB063DD39484DC130ULL, 
            0x19FBF8D308BDE10EULL, 0x31C2142072041E07ULL, 0xA0D11A6DFDC5A7A7ULL, 0xC540A98FE9BCA474ULL, 
            0x51F5551CD3EE3E51ULL, 0x9E6BD9413EC3FC62ULL, 0x6F70AAF239AA19C6ULL, 0xBD7C457A9D35E715ULL
        },
        {
            0x73E9D03A7EBEE735ULL, 0x8563D0546EA37FF1ULL, 0xA6EF6B0FCD99B5F1ULL, 0x1DADB18912511BB4ULL, 
            0xFC828B781258D537ULL, 0x3517BD3A1E5F81B7ULL, 0x9360DB1DE3873BD4ULL, 0xE7789F69D0AF6E82ULL, 
            0x62E40B03914E9A2EULL, 0x4DCB91686A08EDCCULL, 0x7D2324B765290A8CULL, 0xBF4F0A573685A205ULL, 
            0x83DB9EA7BC9EACCAULL, 0x5DF0D4717B28BFCBULL, 0x0A8B6FEB3B7910C6ULL, 0x995B860092F98189ULL, 
            0xE9C9CBFF18D097CCULL, 0x5A98A6951DB065B9ULL, 0x9D538312F0FCCD9CULL, 0x71AB5AB8D9074C4AULL, 
            0x4521B6394D1EC147ULL, 0x63C3A3424FDA60E5ULL, 0x23327F688BD15922ULL, 0x63BC62F529A9C4BBULL, 
            0x2A55A4EFCDEEB28BULL, 0x4FB09D223203D96CULL, 0xF7C57C49919AA6CEULL, 0x50E31D954E0EB7B8ULL, 
            0x66997DBC1EF6F774ULL, 0x4151E16C01709A67ULL, 0xB7F7F6FD678A552FULL, 0xBA4B1BC2F8AF3A7BULL
        },
        {
            0x3AF47BF4DFE4EBD3ULL, 0x72A6D48516021DBEULL, 0x98396FE39C6D456FULL, 0x079C675D27522C10ULL, 
            0x3A66A95639246665ULL, 0xC4AFEC10BE5B70BEULL, 0xAE56BB27E5A94405ULL, 0x185E8CEFB4F6D543ULL, 
            0xFD40F35F33FB8F63ULL, 0xD76072EFF432C1D3ULL, 0x4E93D1CD16CC5A29ULL, 0x64F089FD17191B12ULL, 
            0x800A0A8617DFA766ULL, 0x665D9DD7E34D6613ULL, 0x70E78C4B14DCC6D3ULL, 0xD2FCBCA1B350C961ULL, 
            0x2A010117A07CE79DULL, 0x8CFBEB6CDB4CB068ULL, 0x6647D8F686CC9B30ULL, 0x8B3EEA1F2D9FD51CULL, 
            0xD090F7BAF2A870D3ULL, 0xE3BF8247C38F90B1ULL, 0xABEF2A245DD68814ULL, 0x53D512DC51AA3A38ULL, 
            0x1D6BCA908A654DF9ULL, 0xFC042916344AB5A1ULL, 0xB50CC381FFF96AD7ULL, 0xC0F0151633A2F156ULL, 
            0xEE4A802594FB69B9ULL, 0x31E51BE9C0289DEFULL, 0x194D0A988F0B2854ULL, 0xF99D84CF61F1A5ECULL
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
            0xC95574B2A712ADFDULL, 0xA2120549D67558EEULL, 0x810F10DFAAC9FD02ULL, 0x65B5C5C76A32C448ULL, 
            0x9A1D013BB4E2EC8DULL, 0xA95C5996EDCFB85FULL, 0x560737130DA13493ULL, 0x2C1AFFA35DB7CD8AULL, 
            0x8BF30452E64E1522ULL, 0xDBD6CDB066C6E2E3ULL, 0xCB01AFE75FEADA02ULL, 0xFC9B4F92F4915ED3ULL, 
            0xE865B6D80E01DBA6ULL, 0x29FA86DEE448F5BDULL, 0xD68275912E1778C4ULL, 0x71788C55AE5C9A9CULL, 
            0x72FAF025077A7A25ULL, 0x98BA10071D2B8926ULL, 0x36C8D1DE39DBB7E7ULL, 0x27924E463624EDA5ULL, 
            0xA509D0E060DB0581ULL, 0x1BF83763BA2997F0ULL, 0x57814F4AC57D9F8FULL, 0x1374AC5433F8AE5FULL, 
            0x45B83D6C3927CA27ULL, 0x34691DFB45AB30D8ULL, 0xE8DEDCB3B54BB1C7ULL, 0x05B25C66CB7FA17BULL, 
            0xAC507A264DFA80BAULL, 0x8CA12B30E0D1BF9CULL, 0xC57E2C10F8F81B1FULL, 0x175BBD4596D44E4DULL
        },
        {
            0x712586D49C571E26ULL, 0x78D793A6BCD6B6D6ULL, 0xF2780F2B4FEC45BCULL, 0xEF7EBD6882D19B67ULL, 
            0xA58F356320B7C684ULL, 0x164B62611020DBE4ULL, 0xD3062497B852EFDCULL, 0x5EA4B059CC607A13ULL, 
            0xF578240831D41CB1ULL, 0x9E7D7BD3387DB93EULL, 0x139F2859317C1767ULL, 0x0E4002F6994EAB03ULL, 
            0x70B5FB39431064C2ULL, 0xA43A098EC6C195B4ULL, 0xEBE08CFB6E7C4A23ULL, 0x866C70CA98EA361DULL, 
            0xBE6724EAA0C622C7ULL, 0x19D6D024DCF5550EULL, 0x21B4AF5102DBDC2BULL, 0x389DCD0F173A643DULL, 
            0x4FA09B21E7FC8149ULL, 0x732C8025E5FE78BFULL, 0xCCDA26D424E61F63ULL, 0x1066DB98B7AD0661ULL, 
            0x544BFF0E9594DB60ULL, 0x5570F25F2B7A9E70ULL, 0x5585419A161BD06BULL, 0x629317AD5A83841EULL, 
            0xD83A66ED7D693CDEULL, 0x9934700AD139F60BULL, 0x93E919CB02BDFBACULL, 0x5105FFD614C98633ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseGConstants = {
    0x997669135F8932B5ULL,
    0x1C155320293F25E6ULL,
    0x575C6FB6F362ED77ULL,
    0x997669135F8932B5ULL,
    0x1C155320293F25E6ULL,
    0x575C6FB6F362ED77ULL,
    0x396E772DEA68E33EULL,
    0xC25E8000D52AF3FEULL,
    0xDC,
    0x5A,
    0x68,
    0x55,
    0x48,
    0x8D,
    0x92,
    0xF6
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseHSalts = {
    {
        {
            0x751035E045D802CCULL, 0x341EFCA2A7E7F43DULL, 0xC60E5DC35E6E3BC0ULL, 0x7C6EF04CAECFCC97ULL, 
            0xD97129967EF69C4AULL, 0x9D51C600F0BF7BA5ULL, 0xB32BEA9DAF53D86BULL, 0xDAF864C30D6630F7ULL, 
            0x52C24DD69DC8E0D3ULL, 0xF01C63729FAB54BAULL, 0x2EB9ED9D22582879ULL, 0xF10CE7D3450EFBE0ULL, 
            0xFD848D748A455B47ULL, 0xCAA7049D9F62EA5BULL, 0x6F37F344FD98E415ULL, 0x7135004415A09361ULL, 
            0x258D6A65CBE6C785ULL, 0x04F6A886490B8564ULL, 0xACC60187EB2FD395ULL, 0xB04E4BE8F8CFEECDULL, 
            0x2F54EDBB77B627DCULL, 0xF08F7C711DB15779ULL, 0x6F5F1099C20F9BE8ULL, 0xF66928865E7E72A9ULL, 
            0x4FDF14E3240149F7ULL, 0x284DC1F33207B92FULL, 0x869415353830EC9AULL, 0x68100A2649745956ULL, 
            0x0E3155808A9C6B9EULL, 0x7C05CB13EF142E69ULL, 0xCCD2EC643BDFD810ULL, 0xAC6893A4093D96E0ULL
        },
        {
            0x3B71F071923F0220ULL, 0x4BF7320B77AD4C26ULL, 0xB0472227F0E9AA8EULL, 0x9D1C68D0308C2311ULL, 
            0x68BC9D38255E17A0ULL, 0x4F5099659C9A974CULL, 0x066F148FE43869A8ULL, 0xA892FC9C9431EED2ULL, 
            0x3224AB2D3DBB6C4EULL, 0x11F6A3EE28647E11ULL, 0xC65A02ADEB0F5DDDULL, 0xEE384B9988ADAE1DULL, 
            0xD48FF6C936DFFE4CULL, 0xCFC9B862805CA010ULL, 0x48B4B0A2A7577C80ULL, 0x13CD185206F8D32DULL, 
            0x7D5B8B2C23D50365ULL, 0xEE72F5FC48892C68ULL, 0xBAF203C9FE39A567ULL, 0xB0A5598C5D34A3ADULL, 
            0x8E073AAB0BDA8AEAULL, 0x0FD57AD715567DE2ULL, 0xEDE173D237EF550AULL, 0x768D6CCF6567D151ULL, 
            0x4315842FB3477053ULL, 0xA62E41287784ED13ULL, 0x97C3F98301DF0A73ULL, 0x6048F4D681F27F8CULL, 
            0x0B4E80B0635A585FULL, 0xED5F7F7EBC85A043ULL, 0xE05A5E9EEF69F9A3ULL, 0xC18EEEAA53CC560CULL
        },
        {
            0x04A8D99755A8AD22ULL, 0xD3DC2A04F7FF6C64ULL, 0x2D79C7CF96157DBDULL, 0x281329D73638A80CULL, 
            0xB91383ED5A0FE02CULL, 0x28833103E3C0D99DULL, 0x1090441D059F3108ULL, 0x701E7CE48FAFCBB6ULL, 
            0xBBCDCCC8137B2A9EULL, 0x74C5B6EE7AB4CC94ULL, 0xC9C84F0F2DAB62AAULL, 0x383A2D6B987168ABULL, 
            0x58EF42BD4B8265EEULL, 0x26D6F53FAB1B42FBULL, 0xBEC5E60D51B1CDABULL, 0x5F7479DD2D7C3C09ULL, 
            0x8F0A44E067F3BBCEULL, 0x1941F1DD7CFCEE31ULL, 0xD97B78BE839ECBBDULL, 0xAC63436F5219128AULL, 
            0x1A116DC065DDBB55ULL, 0xFCFC09A25ACADB73ULL, 0xEB156449E1AC032BULL, 0x767796C177E03C8BULL, 
            0xD3D3DDBBEFCE3C4AULL, 0x1BB9BEC6043A0B41ULL, 0x35449E47782E31D6ULL, 0x0F9F8E1E8887AE14ULL, 
            0x2FF9E2DFEB7C66CBULL, 0x7B20D1A1A7AB9F26ULL, 0x7CAA90536B879A96ULL, 0x578915B81148DF63ULL
        },
        {
            0x540DBEE0C5184337ULL, 0xDDEF95B43B220AD6ULL, 0x33115E1455EAD8A1ULL, 0xEAB18F3B3D6E0E3CULL, 
            0x1D976CB98B0CF0F9ULL, 0xCB8F4CAB28948A59ULL, 0xE69C5FA300CB97EBULL, 0x75464C50306B3AF0ULL, 
            0x961A9C92FEC759A0ULL, 0xD63A3C34DDEDC657ULL, 0x08D5135F006E038AULL, 0xDD001CADB504A390ULL, 
            0xDBB840BB5C5AA9B2ULL, 0x06DC064F3C42EC70ULL, 0x15E8D1BDA0451B9BULL, 0x4E3ECF0FF08AD690ULL, 
            0x52C57514AA904903ULL, 0x65FD8B3016FDD843ULL, 0x4A2BA921AE3D51CBULL, 0xF06423E02057416AULL, 
            0x98D101D78225A36BULL, 0xA5283488F343D415ULL, 0xA9C3F565153BB83CULL, 0xF315E2C7FC18BCA9ULL, 
            0x741C6B44409DD79CULL, 0xFB1A50A63CBDD034ULL, 0xEF2858B7AF96A0CAULL, 0x2BFE1362BA25DD5EULL, 
            0x3CE94253CA711A2BULL, 0x0ED1D78CC07828C7ULL, 0xDE8E1D2D68139426ULL, 0xF1C1BFE167214DF3ULL
        },
        {
            0x6D1C36DB7449CEE8ULL, 0x7DF9E8F0D8958EB0ULL, 0x7290ED8659A93EBAULL, 0x380FC7FDED2FECD1ULL, 
            0x64EF92F8BD74514DULL, 0xBDD6EEE7885B87B0ULL, 0xD48AC7F9BEEAC09CULL, 0x3261C9472A1AB4E6ULL, 
            0x91793CC80E085348ULL, 0xB21B2F9EB59355DFULL, 0x5C61319057E0B107ULL, 0x7D5377DC1FE1E57FULL, 
            0x98B029D5F169E37CULL, 0x5AA4CA3BC6539E5EULL, 0x6975E87CD1F2E912ULL, 0x9F33898B299B67FBULL, 
            0x05758BEF20F6E54BULL, 0x8CB1EF97C6BF3FF9ULL, 0xADCD3E2890BEE948ULL, 0xD17C901001260F89ULL, 
            0xEFF31CF7CA54B521ULL, 0x3C865C4EB2A23921ULL, 0x1083AE423C6AD662ULL, 0xEB3522E0B4720B43ULL, 
            0xA46E3EBA3C47F76DULL, 0x827AE70BD6705A4DULL, 0x7C688283D5CA023CULL, 0x8CA9E1FA975E87CEULL, 
            0xC19BBC1B7F64AC05ULL, 0x44D970D12A750A74ULL, 0x48C89B59AFF2C9B1ULL, 0x64F70D1735CCE100ULL
        },
        {
            0x4D9D9E832C135C02ULL, 0x6C2774B2A5F5CABFULL, 0x234041E89C4AC715ULL, 0xF56170D450C22A60ULL, 
            0x9360AF405A7355FFULL, 0x8D57BFB85224D29AULL, 0xD13BC3E7268BD613ULL, 0xB88F3843FE44DF2AULL, 
            0xCC756AB002AE77ACULL, 0x67597EA33B766E0AULL, 0xC7F7F4F4B8921C1FULL, 0xBDCBB5599C9DF426ULL, 
            0x4D9407DAD5DB062BULL, 0x191250A0413A209CULL, 0x8996EAA489F65FB0ULL, 0xC62904245664D2ABULL, 
            0xC69C67EB2E49427DULL, 0x68A4BBF72CDA18FBULL, 0x4381CEBD0913626DULL, 0x6EFE6CC473D74523ULL, 
            0xDD93FA5EE6941AEAULL, 0x08A5890B280D69AFULL, 0x65E9ADC5BFDEB2D8ULL, 0x3DE4FF086662205FULL, 
            0xE39133FD3CD22A68ULL, 0xB69EC559DBD9AAA2ULL, 0x6231556704598B96ULL, 0x2CA79EA1E79E0E23ULL, 
            0xA692734EDA879CA5ULL, 0x05BD482FCF510C5BULL, 0xF50B4C1187C0D012ULL, 0x71CCE4A21192A4CCULL
        }
    },
    {
        {
            0x061239C394CA0AB4ULL, 0x4DB9ACBBD5C6961AULL, 0xE192F8006C7E21C0ULL, 0xF2206F947AAD957FULL, 
            0xF549638E6C0CAAE8ULL, 0xF7F553ABAB8DF5B0ULL, 0x1E78A88B89CC5B92ULL, 0xB8769125A5956CD1ULL, 
            0xA2F1CCCEE6C89654ULL, 0x8E884C193D998985ULL, 0xA18B8C334B5608B0ULL, 0xE99B860BA5993176ULL, 
            0xFE4C4DCA403E7CCCULL, 0x3DA35F0B2C0F7CA8ULL, 0x49F7B1E10665C0FDULL, 0x96D1E46C3060DD07ULL, 
            0x91E58E97190C6318ULL, 0x0B40DE94F95B7A31ULL, 0x8A758075DAEE3BE4ULL, 0xDB654D38EF0F2B9BULL, 
            0x1D2A8067E06CD286ULL, 0x2BCF6C57D579E5ECULL, 0xF486DB2E1D67C9F1ULL, 0xA593F609EAEDFD00ULL, 
            0x2FB9AAEB9BBC8DC8ULL, 0x15121A565A7C775FULL, 0xA0F92A849201B407ULL, 0xC1E7E9A9035DDE79ULL, 
            0xDD8FA436876E4E7BULL, 0x02E571EA5025918DULL, 0x921F0003C742E6E4ULL, 0xE008345611849214ULL
        },
        {
            0x028BE6716B64563FULL, 0xB5FA4E3E7946479EULL, 0x34B5445818FE5D71ULL, 0xCF450C7504BB76ECULL, 
            0x7DAC26346ECCE06BULL, 0xAB3D3B7BF3B277CEULL, 0xCA657AD9FA7C12DDULL, 0x10CD18DB2F2BEC84ULL, 
            0xE6E9D61B84B46676ULL, 0x9859CD03A70BD497ULL, 0x2DD765B6C011886CULL, 0x145D802BAA72E738ULL, 
            0xB75B74D268B351F7ULL, 0x7D36D0A1130CF558ULL, 0x6B21ECBA735DDC12ULL, 0x09588F7B29FC3374ULL, 
            0x7A758077AD1C4E1DULL, 0x520E48C890917726ULL, 0x70EAA874F0FC46F5ULL, 0x2563E6B66F228C8AULL, 
            0x3BB95B2DB8580DA5ULL, 0xBC745F9747B4FA85ULL, 0x85B81CE8C34C481AULL, 0x2B41F704D81EF78CULL, 
            0x13F09BCFD8926D0CULL, 0x160F38E26B32C130ULL, 0x162A756D814E274AULL, 0xB781C512ED8814B5ULL, 
            0x29F64D133E9AFBEEULL, 0xDC71ACCCCFC2307EULL, 0xAD51D844A75EA62AULL, 0x4C6F47BAECEC3129ULL
        },
        {
            0x208DAD9BF71EB307ULL, 0x0F5CD226546D9D89ULL, 0x4953431EADCF465BULL, 0x848BD711818CBFBDULL, 
            0x4F8E2F0CCF72DAEEULL, 0xD78FF350BFD1BEDAULL, 0xD056CC8E64A97AE3ULL, 0xCA538C45DCEE7247ULL, 
            0x783F0A4AE7465A43ULL, 0x17205AA267A61C52ULL, 0xDAB8D9A016880D63ULL, 0xB9B7E9A97B8B33FFULL, 
            0x11780C67CD7A83E4ULL, 0x17E422B4AC01CE8FULL, 0x364AA740DCF00FA0ULL, 0xCFC8448E67C032BFULL, 
            0x88A1CBBEA156DF0BULL, 0xB7E70F248D38DFE8ULL, 0x89F29861EB45CBBDULL, 0x68DCBEF400C23A04ULL, 
            0x7155DB96E54985CBULL, 0x950827C894ABF38FULL, 0xA60260F70B0186F1ULL, 0x6021E3134041ABE1ULL, 
            0x206F824BF2DB605BULL, 0xC22B6747316649A3ULL, 0x808ADE7CA1D892D4ULL, 0x26BCEFE3FC752316ULL, 
            0xEB06BB0880E1C716ULL, 0xBC87A8CAED0007B4ULL, 0x0A33915AF49CDEB5ULL, 0x46F5347F00257BF3ULL
        },
        {
            0x31D30C678A0D5816ULL, 0x432426299D3C44ADULL, 0xE4C28992A149A640ULL, 0xAC011D0E66396233ULL, 
            0x6B285F7A60A28400ULL, 0x8C3F6327C397ED6FULL, 0x8768D013F3DC37F9ULL, 0xDEEEC74C4C661822ULL, 
            0x8D6CEE23B1F39B5FULL, 0x42E6003439AD3085ULL, 0x7056BB1CB0F70A4CULL, 0xFA97E9B33525385EULL, 
            0x19501296B0472F3EULL, 0x1E6EBC62FFE8CF37ULL, 0x08C87DB8483DAE69ULL, 0x6F7405B867BD63D4ULL, 
            0xBC11F46BF384C332ULL, 0x29259EB57C0CCB22ULL, 0xF9DAF7F3EE0A9483ULL, 0x9F272994712E06C6ULL, 
            0xEEEA83BCB01D21F6ULL, 0x38F6A704D943CFD4ULL, 0x4595AB8023F09AF3ULL, 0x5A2F87D0B37D6430ULL, 
            0x63752C18CD113344ULL, 0x6E4FDC7626C9A1C1ULL, 0x588D194197C0EA40ULL, 0x0DDC9D19518117CEULL, 
            0x38CC845004DA377EULL, 0x84605E3DCAED826BULL, 0x4EC7AA1C7BF3B61BULL, 0x137BF03DCC0B763CULL
        },
        {
            0x903582DE6C057F53ULL, 0x24D260440D116366ULL, 0x9A891C406BEDDED7ULL, 0xC15A4E0C186438ADULL, 
            0x7267B24FA4FDBA88ULL, 0xC3F97EE80C2E5CF9ULL, 0x5FA752EFF8009394ULL, 0x048005315984B894ULL, 
            0x95B1C2840CC8045DULL, 0xB641F16BF4B3921FULL, 0x6B7325687E7160FFULL, 0x7D682A22051A4572ULL, 
            0x64E4E39424964E69ULL, 0xCDAFF08CE3C68FF8ULL, 0xA98DA56CD0885B07ULL, 0x49815DFC5FB3AB04ULL, 
            0x23FAE29F8E1DC6DCULL, 0x2D13789734C499E2ULL, 0x2C76F2AB941B0AD7ULL, 0x662457DA2198982BULL, 
            0x348270169D4585C9ULL, 0x126D3A1FA19DD409ULL, 0x95D6B287CE20F2BFULL, 0xB43DF07CAD4ACCB5ULL, 
            0x1F2D45D17813D858ULL, 0x1D51334AB6987374ULL, 0x08A113C73F14C0BCULL, 0x9167E6185CFEC3BCULL, 
            0xE5ECF106155FC742ULL, 0xAEBF916F7ABA2DCDULL, 0x936C1FFC1C98E6C6ULL, 0x247CF6295245E808ULL
        },
        {
            0x61445792267B8B09ULL, 0x0E0A3BF2D9484B11ULL, 0x3D92284E60FD9520ULL, 0xD6B0BD50DF8E2AB6ULL, 
            0x93B4428CE6BACD0DULL, 0xF3E623782A886C39ULL, 0x5217F1C6EE0CBD48ULL, 0x63B5C3DBD1F90669ULL, 
            0x504042C1ED1CD973ULL, 0xE832ABCE63EAC856ULL, 0xC0CC3B56D46CC6CFULL, 0x370714EB6C52E9C2ULL, 
            0x036BA8C4C881B6F5ULL, 0xE945B758ABAD9D33ULL, 0x2C677287F991B5ACULL, 0xE494EEFA254FB61EULL, 
            0x5A6285592F813A09ULL, 0xAFDECF0946236E70ULL, 0xEF330BFEC6DDA98CULL, 0x7AC035CA4C69B82BULL, 
            0xCE841A62DAEA4AD9ULL, 0x2E546B75769ADF63ULL, 0xCB00B8BA9FE29277ULL, 0x0AB9A9E620E3F099ULL, 
            0x1926C1174593FFB1ULL, 0xC3DF319CDAEFB1C6ULL, 0xC2DE1CD482E2165EULL, 0x1215CF9F87EA1199ULL, 
            0x047D63F2D295A8CFULL, 0x5C7927663CB8F6D6ULL, 0xD628DF41AD674A72ULL, 0x99054531C9183FA1ULL
        }
    },
    {
        {
            0xADAF1DA1C6B581C8ULL, 0x23BC572278154439ULL, 0x138C1DB5460965FCULL, 0xC582E2FD46479CC1ULL, 
            0x0576E8DAF2F19CC4ULL, 0xB16ACE0E14861AD5ULL, 0x9A253463BD05FE71ULL, 0xC88E47D1F4B88F65ULL, 
            0xB82156A3C2DB3608ULL, 0x10C80A1E6752F630ULL, 0xF08D37490EE978BFULL, 0x755DF58D84D713E4ULL, 
            0x1B9F6FBA60A558CFULL, 0x145B739309503050ULL, 0x91622047F467E4F5ULL, 0x9421DEA318278BBDULL, 
            0x9E39AE1E33D0761CULL, 0xFF0F568A5172050CULL, 0x8EF3795C76756CC4ULL, 0x5C68FEC232273CE7ULL, 
            0x57CB0DED8B6D20B6ULL, 0x6705C569901270D5ULL, 0x73549ADE181AC954ULL, 0xE06B08067DDE7620ULL, 
            0xF8C174DCAEDC0918ULL, 0x5EF63B4107461CD8ULL, 0xE34FBB0208FE683AULL, 0x2E4C983DB7F3F1FAULL, 
            0xAF1DA1381993814BULL, 0x68B43049ED4EBF93ULL, 0xB8A49E2A6E4C26B3ULL, 0x2859E982AAFE5BA2ULL
        },
        {
            0xB8AB9C1E01490530ULL, 0xB4E1A62AC6882DB2ULL, 0x982CF73B2AE8B438ULL, 0xA662B893B0749195ULL, 
            0xBCE75941964D9912ULL, 0x0529D84EB9EF5AA0ULL, 0x40E3FD657752508AULL, 0x450CCAFAE48EEB23ULL, 
            0xE9DE18C8FAA7833AULL, 0x2832FC96EC8EDBE9ULL, 0x8F2BA893C4D029B8ULL, 0x867B067E62538EA1ULL, 
            0xA601CD2FC35FFC2BULL, 0xDD59F4EB02C91829ULL, 0xF8E10EBC1D06390DULL, 0xE02FCCAF78D30623ULL, 
            0x2A52010A52CA60CDULL, 0xC12A046989B577B8ULL, 0xD1342F1A036E66C7ULL, 0xBF544CB1B53C3943ULL, 
            0x4C44C664B3D3BE0DULL, 0x31318CEB83A37394ULL, 0xD1D4E0A9BECBAF96ULL, 0x58BD312824B6D68CULL, 
            0x2A12DFBC58373C0AULL, 0xB5745652775F1DC0ULL, 0xA6A1109CA3D54EDBULL, 0x534EC9838CAC642AULL, 
            0xD9741071119466D9ULL, 0xD2133F7688AB04DDULL, 0x2D3B8D7A26CD445AULL, 0x7DF6FB28BEFA162BULL
        },
        {
            0xEE60356FA213E619ULL, 0x838D83300E74A621ULL, 0xFF087140960993E7ULL, 0x410949C61B422E0CULL, 
            0x2932975D2C02912EULL, 0xF331C99210D36246ULL, 0xE8361ED9F97EE35AULL, 0x24D54B3A0743BF3DULL, 
            0xF25E2705CC370F19ULL, 0xAD4ED8FFF52D96BCULL, 0xF4507191EEE6A04EULL, 0xCD8706E0F7CFEDD0ULL, 
            0xBD7BCE431884B8F2ULL, 0x8C7F876861EEFDF0ULL, 0x95E90A5418A153B7ULL, 0xF29DC286DF6FAB59ULL, 
            0x36BFF635F31973DDULL, 0x21CD516810950166ULL, 0x700B17783D4C576BULL, 0x4E3DC40EBE2BEB79ULL, 
            0xF675CE40BFD9FD4FULL, 0xF30A216532FD6BD4ULL, 0x1E524B0AC43A1F53ULL, 0x686E29FAE27776EFULL, 
            0x75BC908AEB201D44ULL, 0xFCA5600E05967C73ULL, 0x8D8C1E891176DDACULL, 0x943F525FB985CF33ULL, 
            0x2B16CBEB3EA74641ULL, 0xDD1A33077906CA9EULL, 0xFB008EC5D45B1F80ULL, 0xFF22A2E0EAE9C831ULL
        },
        {
            0x0C50F3D64CB00361ULL, 0xA642EA2C0AE6B1EFULL, 0xE9BA2A46EA5C0C39ULL, 0x57D17F7711B06C1BULL, 
            0x06BE1537FC5F98D8ULL, 0x60DE3F8E9C298E2CULL, 0x38BF8BC1D4BFAF84ULL, 0x20B4650848D2896DULL, 
            0xA491870C58B0525BULL, 0xBDDF5DDCAFDA2769ULL, 0x93CC313B8EEAE622ULL, 0xD5CADED53E24EF0AULL, 
            0x344C6A1AEEA6C797ULL, 0xFFFF7D30DA0187A9ULL, 0x637F4A648662640BULL, 0xF8632A088B5ABA0EULL, 
            0x5FA54B3045F6EAF0ULL, 0xA8A1E37265F13793ULL, 0x88939CDABE647683ULL, 0x50A4AA029C1F2701ULL, 
            0x2D55786FE1D63735ULL, 0xBAEABF67DBDE71D6ULL, 0x467CBB73A3E356FCULL, 0xA37D737795CE6DECULL, 
            0x05CB10EE9A9E3E59ULL, 0x619EA01DB01D2FC7ULL, 0x25887880643932C7ULL, 0xBF1350AACEFD5453ULL, 
            0xC41A69B01CC1E2E9ULL, 0x7C86C5597C67252BULL, 0x214FCB41F8A9C509ULL, 0x1825C3D631E17A8DULL
        },
        {
            0x81B08D87240B2AE4ULL, 0xBCDD735298A14618ULL, 0x16ECE9697B0933F7ULL, 0x62270C16C9631352ULL, 
            0xD14A7125E41C6BE1ULL, 0x7C023E219DD6E226ULL, 0x7EAB3074ADB99291ULL, 0xF60E99C52E989C06ULL, 
            0xE436EE42FD772032ULL, 0x7BA62027A94DAB04ULL, 0x5690021EA76E2B07ULL, 0x695EEB39A46DE063ULL, 
            0xD14246A3EADAE350ULL, 0xF39BE2FDDDDA0BCFULL, 0xBA770C02CE230AADULL, 0xF263396EC54F5AD3ULL, 
            0xBC7A330D177FDEA0ULL, 0x5C9CDA18209BF358ULL, 0x3F0D300E66634B45ULL, 0xFC97CA16B923263DULL, 
            0xFBF73AB7944B8AFAULL, 0xEB16F464B25F8589ULL, 0xE1998A549D8ECBD2ULL, 0xC6F1C6ABD6AC0EF0ULL, 
            0x7386A2187754E859ULL, 0xE9355AB064656F32ULL, 0xCBE77D444CAC0CE8ULL, 0xE2DB010D98464CDBULL, 
            0xB77B5D0851ECB34BULL, 0x39AC7E1BFD8C216CULL, 0xC0083908CAA722D7ULL, 0xFDDC84CB05E32CC9ULL
        },
        {
            0xF47E2F9E655030D2ULL, 0x3EAF850E7F37EF1AULL, 0x42CDA873BC116453ULL, 0x3465F816ECD50B95ULL, 
            0x191018965C396074ULL, 0xA2F643B7AA5685AAULL, 0xDC2A5368EA5CCCD5ULL, 0x5069FB71B4060DA8ULL, 
            0xEC66E59D359B0C08ULL, 0xCE250BA4348A806AULL, 0xEC09D03984FD5029ULL, 0xCA3FAE9675F56A01ULL, 
            0xA07AF54BF2BE5C97ULL, 0xAA7E9CDE2C39CF02ULL, 0xC3D5B053BFBCB31EULL, 0xFC0053E1743282F9ULL, 
            0x8727DCD6C7040762ULL, 0x9D5272C65E039D7BULL, 0xED6095A0FFCC6DBEULL, 0xA60CD94BDCB61381ULL, 
            0xCD2360271A5260E2ULL, 0x3B54A08F979B716FULL, 0x99E5CD28B6C0651DULL, 0x8C9BC9A80DCE5DECULL, 
            0x1DA6363BF1DA2DA5ULL, 0xFD0D07491BF5DEA4ULL, 0x5C667B5E1EA6790CULL, 0x1E9C3F68EF4E3149ULL, 
            0xFD48B5FB058A9FA0ULL, 0x1D2D0A2D19DF9C71ULL, 0xBE52AD033E4BAD55ULL, 0x9CA1A76161D75347ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseHConstants = {
    0x65FC729CB3E24652ULL,
    0xCD0EC08D3AD39136ULL,
    0xC64EDFD9740718F3ULL,
    0x65FC729CB3E24652ULL,
    0xCD0EC08D3AD39136ULL,
    0xC64EDFD9740718F3ULL,
    0x98DF786DDB535271ULL,
    0xD4DD8A57B3533953ULL,
    0x83,
    0x45,
    0x4E,
    0xD3,
    0xE3,
    0x5E,
    0x96,
    0x91
};

