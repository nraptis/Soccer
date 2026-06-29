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
    std::uint64_t aPrevious = 0xF5F1BD0CEBB9FA78ULL; std::uint64_t aIngress = 0xD8FE3F415D7518DBULL; std::uint64_t aCarry = 0xB3A5629BAECDDC0DULL;

    std::uint64_t aWandererA = 0xCE5B6A86B4AE268DULL; std::uint64_t aWandererB = 0xA549D4E120A0C802ULL; std::uint64_t aWandererC = 0xECFDBCB7E8C8D805ULL; std::uint64_t aWandererD = 0xA90A76294A4780A9ULL;
    std::uint64_t aWandererE = 0x881879684E160383ULL; std::uint64_t aWandererF = 0xCA02F5F1D70061FAULL; std::uint64_t aWandererG = 0x9B37E51620E40063ULL; std::uint64_t aWandererH = 0xA204056DAB0BBC81ULL;
    std::uint64_t aWandererI = 0x920935653BE45E3DULL; std::uint64_t aWandererJ = 0x9C7A0D303F69F62CULL; std::uint64_t aWandererK = 0x84F72C70A2C93543ULL;

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
        aPrevious = 17073707182769327935U;
        aCarry = 16286915414440023941U;
        aWandererA = 18425660177875037656U;
        aWandererB = 14583956521971619359U;
        aWandererC = 17570204723181834497U;
        aWandererD = 11583971870069017342U;
        aWandererE = 15241856924603817299U;
        aWandererF = 11276714266649465686U;
        aWandererG = 10826505051405766938U;
        aWandererH = 18092696257305080350U;
        aWandererI = 15539818258791426861U;
        aWandererJ = 10429948246567557597U;
        aWandererK = 9850025998284983269U;
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
    std::uint64_t aPrevious = 0xD4F7A3EC6ECF5C14ULL; std::uint64_t aIngress = 0xC87396938D87DCEEULL; std::uint64_t aCarry = 0xEC7996512D96C1A9ULL;

    std::uint64_t aWandererA = 0x99EDD42ED28F21B5ULL; std::uint64_t aWandererB = 0x94551444F1DFA338ULL; std::uint64_t aWandererC = 0xFF24DCAB7B2AA9D9ULL; std::uint64_t aWandererD = 0xA495F865166F9240ULL;
    std::uint64_t aWandererE = 0xF55A3BCAA07AB008ULL; std::uint64_t aWandererF = 0xA516CCDA651D9C95ULL; std::uint64_t aWandererG = 0x96E8CF98E7E53E23ULL; std::uint64_t aWandererH = 0xF1C5DA2314E24B97ULL;
    std::uint64_t aWandererI = 0xB4C7DA3552A43431ULL; std::uint64_t aWandererJ = 0xF8396746A80CA25BULL; std::uint64_t aWandererK = 0xE2D27FDF85E0CEECULL;

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
        aPrevious = 12723726255376898441U;
        aCarry = 10049499390035879358U;
        aWandererA = 17703932889207805845U;
        aWandererB = 10573497072476177236U;
        aWandererC = 11557136413246104576U;
        aWandererD = 14844981873814861690U;
        aWandererE = 10894077028402361586U;
        aWandererF = 9976257600803340777U;
        aWandererG = 17062198958923318997U;
        aWandererH = 16553301036246812573U;
        aWandererI = 11518833312731228000U;
        aWandererJ = 17265586843157218719U;
        aWandererK = 16100945831870608920U;
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
    std::uint64_t aPrevious = 0xF53B6D7FA7E72ADCULL;
    std::uint64_t aIngress = 0x87CCCA8C3DCA07DFULL;
    std::uint64_t aCarry = 0xBD096366896C986DULL;

    std::uint64_t aWandererA = 0xD5E0A118EF8948A5ULL;
    std::uint64_t aWandererB = 0xB1A3BD48141EB65BULL;
    std::uint64_t aWandererC = 0xBBC345A0EB4FC160ULL;
    std::uint64_t aWandererD = 0x85BE7966765AD7D5ULL;
    std::uint64_t aWandererE = 0xA7FE67698FDEF98EULL;
    std::uint64_t aWandererF = 0xE6E67E2D147841FBULL;
    std::uint64_t aWandererG = 0xA4C3E49B0B01C0E8ULL;
    std::uint64_t aWandererH = 0xE41FF753030F186EULL;
    std::uint64_t aWandererI = 0xB8D2505A7C8F7ED6ULL;
    std::uint64_t aWandererJ = 0xD91AED997C672034ULL;
    std::uint64_t aWandererK = 0xBD9223CD3E28A28FULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneB);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB, 2);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB, 6);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
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
    std::uint64_t aPrevious = 0xEB9F01CFAE040950ULL; std::uint64_t aIngress = 0xD6D4C83F446BCD7EULL; std::uint64_t aCarry = 0xD5DB0A791D25DB7FULL;

    std::uint64_t aWandererA = 0xF53D01EC0D075FA4ULL; std::uint64_t aWandererB = 0xF04DCA860F67031AULL; std::uint64_t aWandererC = 0x8552C1ED7E48707EULL; std::uint64_t aWandererD = 0x81D57C0521098635ULL;
    std::uint64_t aWandererE = 0xD6D7BF5434DFB265ULL; std::uint64_t aWandererF = 0xC94BDEF280B084D0ULL; std::uint64_t aWandererG = 0x825419BDA4B2A6B2ULL; std::uint64_t aWandererH = 0xAEE4A61016B962B8ULL;
    std::uint64_t aWandererI = 0xF5E5C5A286571FCBULL; std::uint64_t aWandererJ = 0xAF4AB47BE1FA541EULL; std::uint64_t aWandererK = 0xBE81D9C81125F6E1ULL;

    // [seed]
    {
        aPrevious = 17107377482447182837U;
        aCarry = 9434576784188655248U;
        aWandererA = 16000893068733751064U;
        aWandererB = 15289521096270713003U;
        aWandererC = 11627454658224279640U;
        aWandererD = 13231872049907752881U;
        aWandererE = 13786402847270750617U;
        aWandererF = 16716025051008940631U;
        aWandererG = 12494467740823184694U;
        aWandererH = 16304233522009064685U;
        aWandererI = 9246035842412622108U;
        aWandererJ = 9980714535216695156U;
        aWandererK = 13015831821475410142U;
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
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 0, 2 with offsets 2384U, 7402U, 3851U, 3148U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2384U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7402U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3851U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3148U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 3, 0 with offsets 2809U, 3521U, 1381U, 1926U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2809U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3521U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1381U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1926U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 1, 1 with offsets 8107U, 7793U, 6703U, 7754U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8107U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7793U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6703U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7754U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 2, 3 with offsets 5443U, 6408U, 175U, 3409U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5443U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6408U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 175U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3409U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 1, 2 with offsets 1954U, 211U, 432U, 1679U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1954U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 211U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 432U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1679U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 2, 3, 1 with offsets 1704U, 442U, 1197U, 677U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1704U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 442U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1197U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 677U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 0, 2, 1 with offsets 276U, 1654U, 226U, 641U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 276U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1654U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 226U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 641U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 1, 2, 3 with offsets 1988U, 330U, 1558U, 1698U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1988U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1558U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1698U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 920U, 641U, 1530U, 286U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 920U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 641U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1530U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 286U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 2, 1 with offsets 2441U, 5723U, 2384U, 1659U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2441U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5723U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2384U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1659U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 1, 3 with offsets 6013U, 4285U, 4351U, 69U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6013U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4285U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4351U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 69U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 3, 2 with offsets 2689U, 5303U, 5361U, 6054U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2689U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5303U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5361U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6054U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 0 with offsets 7049U, 294U, 7654U, 3421U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7049U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 294U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7654U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3421U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3658U, 5961U, 4706U, 4052U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3658U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5961U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 4706U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4052U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 631U, 1334U, 361U, 76U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 631U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1334U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 361U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 76U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 971U, 197U, 167U, 73U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 197U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 167U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 73U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 707U, 1521U, 1488U, 1099U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 707U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1521U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1099U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 822U, 1880U, 251U, 79U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 822U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1880U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 79U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 0, 1 [0..<W_KEY]
        // offsets: 16U, 825U, 671U, 426U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 16U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 825U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 671U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 426U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseASalts = {
    {
        {
            0x45A0E4D2499ED7C1ULL, 0x88D85A6CBA69F906ULL, 0xA7F31278CD1A5E03ULL, 0x057AC917BF4A77BEULL, 
            0xFF01FFEAC4673F4CULL, 0x6873F53B56D9358BULL, 0xAB4C472569286B60ULL, 0xFD1CCDA92FC25B9FULL, 
            0xB3F003C90A10DCF5ULL, 0x4F9AAE22D126EA10ULL, 0x5C6F2250F9B82BC6ULL, 0x4BFBB0C5AB27B008ULL, 
            0xCE57F4B7AF6F1513ULL, 0xCEFCE41B8B0344B1ULL, 0xBE7AD1E931F0E665ULL, 0x98F5AAE288F655E2ULL, 
            0x10EABBA9B5F33C29ULL, 0xA640E1F77F87BD6FULL, 0x8B28F2AD87381090ULL, 0x079CFEBAC1A727B3ULL, 
            0x7546B07AE0DC62C9ULL, 0xD7E03E3243E178E3ULL, 0x3E8B939646AAF7DBULL, 0x4FF6569C719D6FF5ULL, 
            0x32D4AA2C16384799ULL, 0xFF0E542604F77B53ULL, 0x24672539D783BC26ULL, 0x6EADD8F9765D6919ULL, 
            0x9F8D69A4CE29C664ULL, 0xB7644D1037420217ULL, 0xCEE9C75407B529CDULL, 0xA117DFCFDF31B3F3ULL
        },
        {
            0xD3870CC9D7C9A234ULL, 0xBABC8E12FF10460EULL, 0xD5ECCC29469FE124ULL, 0x7FEFDCA9FB0D4CDDULL, 
            0xD636853E41BA0EF4ULL, 0x283527EAB2638E33ULL, 0x092CAAF78840FDADULL, 0xCC97A25A631AAB51ULL, 
            0x5E638859CADABC7BULL, 0xE42816A4D2879D3EULL, 0x2B9929A94C6FBFB0ULL, 0x7CF249CE4CE7BA20ULL, 
            0x4DBF02891DC81C91ULL, 0x002C1452E5FDDE74ULL, 0xE5620BAAAC7703B8ULL, 0x4AF42F2FE06CDA02ULL, 
            0xC06DA741271276E9ULL, 0x417A1C582B6A70A2ULL, 0xB423E6243481166CULL, 0x760F9B2C8DE81D72ULL, 
            0xC37DDE2216320D82ULL, 0x725A986429838182ULL, 0x3D916C34A54A9F6BULL, 0x3C61E8224A687F76ULL, 
            0x2F7DE7224D77BCC7ULL, 0x04572F756E86D773ULL, 0x172B9A938046A063ULL, 0x041BF0980A107841ULL, 
            0xBD57CD890D31573AULL, 0xD96B7935839D30EFULL, 0x11F89BA52FEBEE05ULL, 0xC8FFD7CA8A395152ULL
        },
        {
            0xB74CF953A3297A82ULL, 0xDE2F3EDE66CB96C8ULL, 0x4FBF82EB8F733E48ULL, 0x0F9DD269C373B332ULL, 
            0xDF9861D57539E355ULL, 0x414EA90FAF2D072BULL, 0xCCDAA7D0D601A608ULL, 0xDAFC9E9861CAC5C8ULL, 
            0x276F0DB1284598E5ULL, 0x80968F59969A96CFULL, 0x9036A927F56391ECULL, 0x989AFA70D296DD82ULL, 
            0xAD8A95AA135B7557ULL, 0x4D1CB36C1B5FBEA8ULL, 0x0841A5F02FA9F47BULL, 0xF531A149FC5F2F73ULL, 
            0x97EF39B7CB43A4A7ULL, 0xA1FB1DC7694E84B9ULL, 0x78497405D6F1E7D9ULL, 0x203F2123466A31C4ULL, 
            0x9C9865444899137BULL, 0x7653ECC7209CF0B1ULL, 0x0D5E0ADEEFE3E93DULL, 0x1DBB4529A3912662ULL, 
            0xF2411CC6C0503011ULL, 0xA7E94410726B7919ULL, 0xA2B95DF55DF4B9B0ULL, 0xA01FEEADDDDD23AFULL, 
            0x64617C0A824EE8B7ULL, 0x2B5DC52A667B4369ULL, 0x0F632490525F86EFULL, 0x52E0605744EC1449ULL
        },
        {
            0xE29235A670391674ULL, 0xE802FD060DCE5296ULL, 0xB44C695B10A85F51ULL, 0x1207ABF9664D93B6ULL, 
            0x0EBB05CE5CB119C5ULL, 0x83006C74F5169269ULL, 0x35FEE4619C7C755FULL, 0xE889177CA9650E73ULL, 
            0xEF654F770E837D6DULL, 0xCECD944DCE630DF3ULL, 0x0DA3AB0A50F8AD76ULL, 0xD03271273AF6BB5AULL, 
            0xCE40263C4DA608DBULL, 0x29834EC11DEEC484ULL, 0xC020730A5C2F63F3ULL, 0x3625051C564C248FULL, 
            0x850D03845B041349ULL, 0xA1CF00132DFCBB82ULL, 0xC2CB8FD5B62804A8ULL, 0xC78038AA9316B4FFULL, 
            0xD30F632265201777ULL, 0x8EF9F80A5BAB3E90ULL, 0x99C7B4A240BD2AB6ULL, 0xB68B484AE2FB4478ULL, 
            0x58368F7E7C97E4EBULL, 0xDB0EE869464B0EAAULL, 0xE3C6456A00589142ULL, 0xB64B632183BCE9A6ULL, 
            0x3D0E30A08E849509ULL, 0xB0D8AC4D2E838DC4ULL, 0x6693EDD2A60D6622ULL, 0x604E5ED2E2EDCDF9ULL
        },
        {
            0x09DC3E60F40CADFBULL, 0x6929EC2DE5A28205ULL, 0x708A0DF8D15982DFULL, 0xA267EEF14AC04DFDULL, 
            0x9E1065B79B4AC357ULL, 0x57F2D64D62AEE84DULL, 0x86C550F82A93E826ULL, 0x696844AF240D00EBULL, 
            0x901F9A50BA81D9FEULL, 0xFF7B142462D27DC2ULL, 0xE782D1D7C559085EULL, 0x06DE408C493AE0ECULL, 
            0x7C7C136CFA5347F1ULL, 0x3D88AEDB7896715FULL, 0x0BF137AC9C8396D3ULL, 0xAB41CBFBA42B5EAAULL, 
            0x500BD264039D9446ULL, 0xE77700E3A0EDFE77ULL, 0xA0E7F48AB7EAB1FEULL, 0xEE0BE0BF11C73AA2ULL, 
            0x7A2A9F83D9F819DFULL, 0x2F90CBCA32E5A57CULL, 0xA5BF4F01963B1B08ULL, 0xF1181477A4A558ABULL, 
            0xCE7C8FE078CB9759ULL, 0x08A2E7AB614CE956ULL, 0x22A881EDB53D56DCULL, 0x5728247AC4C66359ULL, 
            0x18F5531F967E21CDULL, 0x5E1E44C1DA29DB63ULL, 0xF884BF481621D8B8ULL, 0xB6ABEBCA9159B76FULL
        },
        {
            0x9A7BC3A0A4BE1261ULL, 0x98921EA07D28E004ULL, 0x7B583386B95BE3DEULL, 0xCE7F9563000832B1ULL, 
            0x5A301B7E3C64204BULL, 0x16C0C64BECE67AD2ULL, 0xFDF402BD927BE22BULL, 0x94ACBCD42B06DDA9ULL, 
            0x87087A2E6D496BB4ULL, 0x6676BFD827CF3A15ULL, 0xA4497CB2F5CE833DULL, 0x3C05136F66F84FC6ULL, 
            0x3C3E49386EB99047ULL, 0x29EA9C145BE63C61ULL, 0x0DD8D76DDB4EF982ULL, 0xBB530A6099B5C46AULL, 
            0xF1D817A301A63B7CULL, 0x6372BD3C5EDF136FULL, 0xB0576DABD10EB919ULL, 0x2AE59D3E7FE0053CULL, 
            0xC4F793C5062AE272ULL, 0x61A800B29786692EULL, 0x9C8D1C9B3A6C1191ULL, 0x24447D5B0FD712B6ULL, 
            0xD77867823DCD8615ULL, 0xB162F65F3D07CA43ULL, 0x36901F5754E72842ULL, 0x60063E793B444B37ULL, 
            0x53AAE68D12487314ULL, 0x8CC9BC65236A3F20ULL, 0x3CB5DEF32584AB3FULL, 0xD5C4EE14764A0A9EULL
        }
    },
    {
        {
            0xC80674757D179D9FULL, 0x1A1CBEF6720560E1ULL, 0x9F0D889B0DF9E923ULL, 0x4F3E0A3C277674EAULL, 
            0x919989727AFB1798ULL, 0x8596F943B366DF7BULL, 0x0BFCB3723A74D83CULL, 0xD0063EAAAEF2D05BULL, 
            0x57E1623F43D0D4BAULL, 0xE5A6C7DE344EB450ULL, 0xDC9BAAAE63AA5BB1ULL, 0x4F9949047CBEA49CULL, 
            0xDA975685A28D3921ULL, 0xEDC23B9830E5F004ULL, 0x45ADDEC49B1BBD5DULL, 0xB8C8BC2F1D34A32FULL, 
            0xD4C5F883A9070E7AULL, 0x5272659F315E3E45ULL, 0x0E728AC7EA392B22ULL, 0x23F7B6A992A0142EULL, 
            0xFCE55BC0F9843032ULL, 0x63BFCD7C023133FAULL, 0xA1124D67289BD104ULL, 0x3F9CB11DABC26776ULL, 
            0xAD988580A92C5B75ULL, 0xDD36310DA9FF2C2CULL, 0x1FCA9AE33CDB90DAULL, 0x2173961A6DFEEF5AULL, 
            0xD6069DD2A8D9D012ULL, 0x78C63F9BC91CD313ULL, 0xE18D1590D6F94E43ULL, 0x62757B221CA2B2AEULL
        },
        {
            0xA601C93345E0AB7DULL, 0xA4EB9DF6B959A4D5ULL, 0x7BF0D58839E97327ULL, 0x7247A33E9F6A35B4ULL, 
            0x057D77204A182FF2ULL, 0x39C9914BDCB091A5ULL, 0xA3A149F49F7D5C86ULL, 0xF4E038BCC8880065ULL, 
            0xDF31B26D56BFA671ULL, 0x58AEBC60423EE6E0ULL, 0xE3DB4DC24A011F53ULL, 0x165B9C427C755247ULL, 
            0x5F7027FB0A323DB6ULL, 0x5DF30938C266DB56ULL, 0xF22F69DB7EAEA596ULL, 0x746FB5E9C4DE3B3AULL, 
            0x2FFE4D6F2C74F049ULL, 0x5AD0A5623AFFE77FULL, 0x6F2C702EE84D3D42ULL, 0x624C0422B8C96615ULL, 
            0x30610FF03F498CB6ULL, 0x7374919C6D69281CULL, 0x8E39910660FDB6ECULL, 0xE90B537793E072A4ULL, 
            0x02325D896402FDB7ULL, 0x17322B8BD0F59CA3ULL, 0xD5812D4386B94B37ULL, 0xC55DB1122BB0A6D6ULL, 
            0x07E035905EEE842DULL, 0xE4BA81D5645D3DBCULL, 0x0A3FB24493C248CAULL, 0xEF9439CCDEA16523ULL
        },
        {
            0x0DCF40D58CBA21EFULL, 0xFAD46878686B2611ULL, 0xF86570A0C510E086ULL, 0x7B84C9C2843919B9ULL, 
            0xAAB69D639A165505ULL, 0xE64F6F64A2E0E2FAULL, 0xAEDD5A9DB94E4C14ULL, 0xD239A941459CA3B6ULL, 
            0xAC44CF871F91872BULL, 0x7FE06ED245EC067FULL, 0xE07EC41292AF54E0ULL, 0xA62A7EC705D2084DULL, 
            0x00FC3C8DD5DEED1AULL, 0xF8ED62BD68C05C29ULL, 0xA223116608B48855ULL, 0xA78277360E2AEB2FULL, 
            0x6174A116A412A129ULL, 0x5546858A57021A39ULL, 0xD8B71E5282F00592ULL, 0xE59FA5DDEE5FA4CCULL, 
            0xE061C7441281981BULL, 0x7013AD76694DDE13ULL, 0xCD40683C06CDF967ULL, 0xEAD8F15C37B85F05ULL, 
            0x6EDFAEF6733A77C3ULL, 0xE6A0F87910258A8CULL, 0xFE95979960C95FA6ULL, 0x393D55F0C76500F4ULL, 
            0x66217449A318282CULL, 0x772F5814B3720B53ULL, 0x735BCF4B7A4BEC4FULL, 0x1A59D6E62011695AULL
        },
        {
            0x741E935943218767ULL, 0x2E7687738EF42B32ULL, 0x7F8F1772A9D47152ULL, 0x3136EFCB36817D3AULL, 
            0x3066F1923DFBE6B3ULL, 0x7E5F99D7BC4E27BBULL, 0x0D678299E5999499ULL, 0x62C3AD8CD0A4280AULL, 
            0x20E90652D01AE90FULL, 0x86EAF5704C9FF426ULL, 0x6B977279A65C100AULL, 0xA926988AA566770AULL, 
            0x2FA9BD83BCE1A631ULL, 0xADC04C48A55D0ACCULL, 0xBDAB9B4FA610E023ULL, 0x48AD44415F767ABFULL, 
            0xCDDE4DDCC092FC83ULL, 0x7FF722C2098D1235ULL, 0x093010AD5D3DA09CULL, 0x700EBBC888B524C3ULL, 
            0xBCCC2986C634C3D6ULL, 0x62ECF6B806A14A13ULL, 0x942DF65A40ACCC75ULL, 0xEF8BD6514399DC43ULL, 
            0x24A098E07CB5EA50ULL, 0xA124E82F8409CEB6ULL, 0x31E00528AB638930ULL, 0x892A0892822D94EAULL, 
            0x65392D589295DF68ULL, 0x294C4037AAA495F0ULL, 0x84904798562CB08BULL, 0x3DD6CFC4D3F52274ULL
        },
        {
            0x57A9CF9E144E017AULL, 0xD947739AAB14831AULL, 0x629ABEE45AD057F1ULL, 0xB64C8FE91C79FFB5ULL, 
            0x6AAF87A8409D346FULL, 0xDBD4847C5FC98E1DULL, 0xEA3CCBF79C6A83CDULL, 0x4AAE89B9AF00A145ULL, 
            0x8DAC2C21560B80C1ULL, 0x7C32BC585286AF4FULL, 0xB4C239219C88B1B2ULL, 0x2D8BE8E6FF9921E6ULL, 
            0x3CC3C4FAE3B1A90DULL, 0x6351798AA16287CEULL, 0x51EBAFAD40A7F828ULL, 0x19218EEFBFDED7B5ULL, 
            0x53C0EF0CCFA905B4ULL, 0xF443161DD7D89545ULL, 0x8A5CBE21BC3DDBF9ULL, 0xE634570096750B49ULL, 
            0x038EE824A7304AF6ULL, 0xAD5404D25B82D031ULL, 0x37D3ADB4D9EC2FE5ULL, 0x6C9154F9615C62C3ULL, 
            0x6BE0F2FFE0A65865ULL, 0xD84B93749813EB38ULL, 0x1AC245AC884FE706ULL, 0x16937DE93C1D13A7ULL, 
            0xE026929740716AB8ULL, 0x4C115B8537046987ULL, 0x5B09337571935A9DULL, 0x9FA28B92DDE9BAE7ULL
        },
        {
            0x56F93AB4C3CC7095ULL, 0x28AB3315141FC5D6ULL, 0x7303CB7641C9E697ULL, 0x7B4D5265E14405C0ULL, 
            0x2A50C44FFE41F163ULL, 0xF1BB61998B99C4C1ULL, 0xD513D635AD6D0E1EULL, 0xC9FAEB1BECD5EC16ULL, 
            0xF4CBCBFA544326CCULL, 0x543F5364D91B7403ULL, 0xBFC6FACAFD3A7E18ULL, 0xEBF522FBC230F937ULL, 
            0x6FF56B65B9579208ULL, 0x79970BC23253F6A6ULL, 0xE67C92963C5155E6ULL, 0xA10C58A4A96D6626ULL, 
            0x0077205E12CF72D2ULL, 0xD8F3771F7D5A5F49ULL, 0xD180DFEC3F5F22A2ULL, 0x6D020D016D8AB8BFULL, 
            0x3E6F08227434573CULL, 0xE2D230D7D91FFD3CULL, 0x0448C14B0E7D0831ULL, 0xC7594AFFC39A0C78ULL, 
            0xA33E0A6BA2C0F5F1ULL, 0x3F0E0A4C0AB12B4DULL, 0x41462E19EE1E6004ULL, 0x785DBB30C09AE117ULL, 
            0xCF5B527CEC961053ULL, 0xB99E51400CD0C077ULL, 0x50A88F34D7B800E1ULL, 0x4E37CFA4173E8322ULL
        }
    },
    {
        {
            0x94EC3C6CF81CCCD1ULL, 0x7782A6A4D4AA2460ULL, 0x06EC893671BBA32EULL, 0x683AFBADDCD29A87ULL, 
            0x4B202B922AA2FABAULL, 0x212F87EE51DD26D3ULL, 0xE019F79ABE4F37F3ULL, 0xBB744BD55DA89BFEULL, 
            0xEF30F229D4D468FAULL, 0xDE1D05E608308073ULL, 0x57BD2D183EE7EC6DULL, 0xD9DA4036502419B6ULL, 
            0xC7754B5AA5E6A638ULL, 0x85658846995E201BULL, 0x9BF0F7FA3128E0FCULL, 0xC2E6E27A53735C11ULL, 
            0x2F93C30EF3F8805CULL, 0xB915EE04C9D6448AULL, 0xE39198F2163D7F59ULL, 0xB7424357A93D0E4AULL, 
            0xAF5A09177500704BULL, 0xBD746251BD2F891BULL, 0x0663B4A8CFB10895ULL, 0x4422D0680C462424ULL, 
            0x7F69748BEB8935E5ULL, 0xF54D156A4B475C0DULL, 0x85774C18BB73A651ULL, 0x03734407A85C3115ULL, 
            0x520AC7C7A2037467ULL, 0x25AB1E72253340F5ULL, 0xC45F726C46C1D8E1ULL, 0x8A6564DE7BCF4EFCULL
        },
        {
            0x44753227F31D7DDCULL, 0x66E06CD6C41121B8ULL, 0xB057ABC5A500BEA5ULL, 0x28A77C6BA8E2B7A3ULL, 
            0xFD33BB7C607D9F58ULL, 0x3408F68B785CB074ULL, 0x7438BC7AF79F85C0ULL, 0x96280F00B08D934AULL, 
            0x130F7993C88EA734ULL, 0x7CB560601F73340CULL, 0x56239DD7FD29FCE6ULL, 0x483D2B92EA2B90C2ULL, 
            0x5695977C77F5A4B4ULL, 0x9B1A80B88CCFA809ULL, 0xDFD46A0D003A8B35ULL, 0x2466C5F0AEA859BEULL, 
            0x93591FCD8BACC86FULL, 0x74C22A3564C4A4C5ULL, 0x01862AE939E05889ULL, 0x53B949E518981C16ULL, 
            0x0882D0B5FEEF59BBULL, 0xA02F0F394091E95DULL, 0x14CDABEE9A6E24E1ULL, 0xEF510CDD44B0E182ULL, 
            0xED3841C869FED43AULL, 0xAD343D2DC987C0F4ULL, 0x468E31D389B95137ULL, 0x6A2085CC7F963207ULL, 
            0xE1A66DC61D77A450ULL, 0xCB94736E2BAE55B2ULL, 0xD121E5725C596EC7ULL, 0xC0961DA9E6F99B7FULL
        },
        {
            0xEDA627F6D4F9C73CULL, 0x65B4DE8E6DF2741DULL, 0x584640E0EE9A01ADULL, 0x23FD849E63B0C7CBULL, 
            0x51C5FD06C6407482ULL, 0xD98513FF96A10D56ULL, 0x9F5CB3447825807FULL, 0x99795F332E21012FULL, 
            0xD506A3908FFEF784ULL, 0x2FFB08D07760C5ABULL, 0x1372FBBB24B84599ULL, 0x577E75537FB7164FULL, 
            0x0949F5B0F1A4DC23ULL, 0xD94F74612B0DCF73ULL, 0x62C830533400E3AAULL, 0x72881482AFAA8DEDULL, 
            0x7417E2239A4A8DA9ULL, 0x0C9BA9F42FC3B6F9ULL, 0x9DCB2232B42CD18FULL, 0x74639A9D3F09FE05ULL, 
            0xBD327C78B450DA9DULL, 0x79741345AD93AAA1ULL, 0x1BBA0DDC5711BC9DULL, 0x4F77DB7EF0FD5D05ULL, 
            0x1806CC8BA505A0E7ULL, 0xDF08C3C0B051B194ULL, 0x0FE57EB69C0C8FE8ULL, 0x3831AAE98D8D53ABULL, 
            0x6FB6A0B1173B53D1ULL, 0x04099860DC2EF28CULL, 0x9FE03BDCC2406352ULL, 0x41C65914BBF3CBCEULL
        },
        {
            0x62640679C5AF2FF8ULL, 0x727A5E5BE5EB7A6EULL, 0x1E72DFEB343B9628ULL, 0x87837F71583D1B5DULL, 
            0x5F22472FF3FBC209ULL, 0xEF5405DE7BB95439ULL, 0x105B8B194E205EA2ULL, 0x7E48540AC912A991ULL, 
            0xC8CCE136C5EEDD38ULL, 0x48298A7A08464B90ULL, 0x8F7DEF2ED848C5FAULL, 0x95F4B6F60604067EULL, 
            0x981A12DD0126D6E6ULL, 0x2A65994E831798B5ULL, 0x96C071C876E2DB78ULL, 0xFA6C8E11272F2370ULL, 
            0x1AC080342D8DF864ULL, 0x20CB6D563BA05E3EULL, 0x8A7F601CC353CAB4ULL, 0xF48D01399CE8DAFBULL, 
            0x6F77B442ABE838E1ULL, 0xFE9886F70750CD86ULL, 0x6F743E62D3569037ULL, 0xFD6638FFF6C7CADFULL, 
            0x80F0C3A8EFF896CDULL, 0x97A654FF76F2FCFCULL, 0xCB4AE023A37B9292ULL, 0xBA257AB0D9301D28ULL, 
            0x56DF6CC95852CA22ULL, 0x27C0D1ADCBC17AC1ULL, 0x1657A9F22F9CF07EULL, 0x8BBA14252C09B8EAULL
        },
        {
            0x79788AFD7FA15747ULL, 0xBCB5A348FB2A412BULL, 0xD04E5F8011F93CEBULL, 0xC70DC0B2651ED144ULL, 
            0x9C119808BC8E6C79ULL, 0xD0E4EC1561A589C0ULL, 0xE1C7A11DD7F6FB8BULL, 0xC6F61C596641DA2FULL, 
            0x62B296FB85B85CF6ULL, 0x90B58BFA78B547CDULL, 0x20D21ED09A2CE5A9ULL, 0x3AEC9A374B2006A6ULL, 
            0x87E93A3B18B368C7ULL, 0xDE191D43A7E031FFULL, 0x57FB0E574A6CF10CULL, 0x81DED51DFDF22A6BULL, 
            0xD875EB7EFCE3DE35ULL, 0xF25E1A3668B2A35AULL, 0x63F9693D2AAB3393ULL, 0xACEB4F36CBB73EC2ULL, 
            0xAD122365F717393DULL, 0x09B9EFE5EB01BD15ULL, 0x460F9B854E676406ULL, 0x06777E6AE73DBE4BULL, 
            0xF0F2DD29C43083B6ULL, 0xE21BCB9E134FF11CULL, 0x713BCC9984919C50ULL, 0xB11CBF0B12CE0506ULL, 
            0x830BEF08D4FBFD96ULL, 0x073548D7E6DA5F15ULL, 0x26A5F1A873915159ULL, 0x8375EEA4FC425B68ULL
        },
        {
            0xAA7C5DB1EE2E37B2ULL, 0xEBD8A02322B6D26BULL, 0x74423E2F2B8500A6ULL, 0xB4267011E94687A6ULL, 
            0xCE7B53BA779D2DB0ULL, 0x7C5FBDF3A691D42DULL, 0x5A377469035CD10AULL, 0x170D3CF08D4ED8AEULL, 
            0x7D2285B61611C359ULL, 0xF924D6AC2FE85B5CULL, 0x3341C4C1146F7BB4ULL, 0x7B50EA60344E2630ULL, 
            0x4D6E7AA17352BCD1ULL, 0x49FA9449D67A3148ULL, 0x05BB3C5DF66A3D36ULL, 0x590680E4896CB7A4ULL, 
            0x77D9D5F92C7E730EULL, 0x7DFB1E34B264A3F9ULL, 0xDF08A9CAE0E7EBC8ULL, 0x7E3DB6EBE7F7F4CEULL, 
            0xD0EC64F793FC0455ULL, 0x62313624069183D2ULL, 0x5DF96CD6FAABE66FULL, 0x1F0EB1AB4DE286C7ULL, 
            0x8F9CAC97A4847E39ULL, 0xD66C9BE175C66CD5ULL, 0xD55561ED7D31748FULL, 0x8CA79D3960968867ULL, 
            0xF2DC953F32569634ULL, 0xB54E67C4CEF8BF4CULL, 0x00C66E98E20D962BULL, 0x97C721FAA779A3A0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseAConstants = {
    0xE18A88D107D8565BULL,
    0x70A10743CA077513ULL,
    0xEFAF49880D3FD29FULL,
    0xE18A88D107D8565BULL,
    0x70A10743CA077513ULL,
    0xEFAF49880D3FD29FULL,
    0x5711371B2852CEBEULL,
    0xDAE186AEDB0F10A7ULL,
    0x63,
    0xEA,
    0x87,
    0xDF,
    0x80,
    0x61,
    0xFD,
    0xEC
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseBSalts = {
    {
        {
            0xAFE4D8581920284BULL, 0x5BC91D23E4877681ULL, 0x021AC51C042901B7ULL, 0xDF34536B9D5CBE85ULL, 
            0xF42C6C1E537AC9A0ULL, 0x512371E6E58EE530ULL, 0xCE4A3995D7E74467ULL, 0x2E524C4E01CA83A4ULL, 
            0x80015149452C5A47ULL, 0xF6B721DBB5B86888ULL, 0x3DFCB7F27A45CADEULL, 0xE417D8640D3B87BFULL, 
            0x4FC5F825EE198066ULL, 0x99A12845AD85029DULL, 0x9FCA4F55B50AD3E3ULL, 0x0F1FD1D30F4B9D73ULL, 
            0x56B9F19583FD89C5ULL, 0x532D8E0C591235D5ULL, 0xE05E839A2A14AD1CULL, 0x7ECC57075CF7D978ULL, 
            0x80F91DDD9D55262CULL, 0x63CFADC2910DAF7CULL, 0xB81EB46D32DB307AULL, 0x3AA790D22D95EF0EULL, 
            0x2855830A7C33FA17ULL, 0x25CF95CC969D9598ULL, 0x2D9A1671FA317AF2ULL, 0xD53C1858024C0324ULL, 
            0x297EF8470D586BD1ULL, 0x8E0DB19B2AEB453BULL, 0xE4337D7820D0ACFCULL, 0x3579F3782BD78947ULL
        },
        {
            0x336229E1EE1C9903ULL, 0xE6837308B8FBD8A0ULL, 0x54AD50EC4442D97DULL, 0x8C5744DEB9D72809ULL, 
            0x660D8297E17BB87CULL, 0x966AD08079F7358CULL, 0x2CAC676660FAE41EULL, 0xA693284D3F6E0F89ULL, 
            0xB742DF08F753DFEEULL, 0x1828DEC3A6EFDB27ULL, 0xA6638E98C0EDC6D3ULL, 0x55C2641FA89DB60CULL, 
            0xBAF13E49F647AABDULL, 0xE656CD1BD329ACB1ULL, 0xAF2E26D05A25C37AULL, 0xF7BD4790078C8160ULL, 
            0xCBDEC824C8BE2AB3ULL, 0x2E14614E19360EE0ULL, 0x47CF78EAC54FB2F6ULL, 0xBAA7849584084C4BULL, 
            0xF7548B1C4434EB47ULL, 0x82FA5658AD01F51AULL, 0x0F905012BEA4026AULL, 0xAEB3638465463D6EULL, 
            0xE553F586A350ED5CULL, 0x311CA21FCCDF5975ULL, 0x354E2258FB9ADF6CULL, 0x53C457EFBF8FC754ULL, 
            0x5722EEFF4EA5B371ULL, 0xA83CF461948F9C08ULL, 0x97AC18B6EA83727EULL, 0x59A6F0E4AA4438CDULL
        },
        {
            0x1153CE40DC2967CBULL, 0xD6373FD10440344EULL, 0xF269C8332FF576F1ULL, 0x214E2BFF564B6A32ULL, 
            0xCE3665204914EB55ULL, 0x32D3214E527DE5BBULL, 0x5424120D5E850567ULL, 0xA4835970379F54C9ULL, 
            0x2D30C4041861B5B5ULL, 0xA6C6C238EA46CF0AULL, 0x282EF31FE3380A0BULL, 0x7EBE88CA9770DBC9ULL, 
            0x010E6FD7317076AFULL, 0xCD11127F19B22161ULL, 0xECEA1719292267B5ULL, 0x96CD9FD9D3D71401ULL, 
            0x8D3767830BD54D8BULL, 0x68C7AB376178AA97ULL, 0xF2DFA0F6AA5A308AULL, 0x8ADF5E75750D60D6ULL, 
            0xB9CAE919C728F90AULL, 0xC9A04639DD8D966CULL, 0x96714BD24BFEA6B8ULL, 0x82FBFAE64BFC8173ULL, 
            0xF239C80149C168CCULL, 0xBB8692A5021E0E88ULL, 0xDA241DB5B9A94E64ULL, 0xB34FA370FFAA5718ULL, 
            0xDF2EB0BBD710B219ULL, 0x8C4F8051F340A9ACULL, 0xF3E8E0265F6CE23BULL, 0x50699B73D62BD072ULL
        },
        {
            0xC185F176D81B4456ULL, 0xCBEE6842CCFA5019ULL, 0x0D3A27AE73F71E6BULL, 0x21530BE4F9535D90ULL, 
            0x566469A55DB13D27ULL, 0x987D7898EF0092C4ULL, 0x009DDC7F5AB1E7EAULL, 0xA03976AC1254D7ABULL, 
            0x764DFEE794D80C60ULL, 0xFC8F3D96851C3F11ULL, 0x9FA1EC973A1ACD5EULL, 0xC418B5EF3C55DEAAULL, 
            0x81B0BAE5B2F64A5EULL, 0x581CA95897A15E9BULL, 0xECB697C29F33B0AFULL, 0x7CEA29C267D4A349ULL, 
            0x3C2E7ACA78F1AEE5ULL, 0x39530258EA6CDF9CULL, 0x17C773A7B359A0D9ULL, 0xBC86F4845B200F42ULL, 
            0x0E40A13E6681932AULL, 0x39BA150363A3BCA3ULL, 0x23D901D7A2AA671AULL, 0xF1FF4E0F54660C3EULL, 
            0x171633191420FDF9ULL, 0x6596CC41E5C67F08ULL, 0xB1B80ED8435211D7ULL, 0x05390ED44C1F3FF6ULL, 
            0x5155CD0D80E83B46ULL, 0x6CE3A83B46D093BFULL, 0xF9F6C0EA78987D0AULL, 0xEB388A2102267527ULL
        },
        {
            0xAAF7B63811B96647ULL, 0xEE0F26EED6005C7AULL, 0x17731FF19BDB111AULL, 0x37515741F306B614ULL, 
            0x879812BC690B0F5DULL, 0xA5A2DEC5EA616140ULL, 0x3108CCFE8D29F596ULL, 0xD8AC3B8C4B3728BEULL, 
            0x53200515437EB9B5ULL, 0x81A10031884737FCULL, 0x8BE9CFCCA259D360ULL, 0x9CA3A341014F35D1ULL, 
            0x1B55DB1651B1AC4EULL, 0xEE8B7E22192385A3ULL, 0x598C926C5D28B9ADULL, 0xE159AE95D00F940BULL, 
            0xE63BFB379060523AULL, 0x50D76F10BA4CD904ULL, 0xBDBD2D18025D0AC6ULL, 0xD608045D87D742D9ULL, 
            0x21B5C4B3A1C07ACFULL, 0x057666603AF2CA94ULL, 0x16EE94A98706E289ULL, 0x7E076073208D371CULL, 
            0x2B5B9921E94B1190ULL, 0x734641B75D7A0166ULL, 0xE908707079C1FE2CULL, 0x53C50B1CD0BD9F3AULL, 
            0x37735538B3E4CD9AULL, 0xF9FF17A0B03F3D33ULL, 0x595E54788128F1D7ULL, 0xC22318C63805513AULL
        },
        {
            0x7BCFB57F4B25477AULL, 0x567DC6D78242834EULL, 0x1F8B2B9C907563ACULL, 0xA0346E5E0B3721B7ULL, 
            0x9F361AD33C645981ULL, 0x4B5F984F5BD1D17FULL, 0xD154DA05596E3CB5ULL, 0x75CE1E13BEF6D28BULL, 
            0x32D56CE9BBD1F9BFULL, 0x4A2C51E0954B8208ULL, 0x9923AD76A8D2E877ULL, 0x59B6F71C576239B6ULL, 
            0xB996C58410B50908ULL, 0xF2E876E37A66500EULL, 0xB2DB58D08BA3FB09ULL, 0x1363BCE8F878CE20ULL, 
            0x04BBA6BE1F1500B9ULL, 0x6D8D15123CCFB22FULL, 0xFD5FE4C1B8BBED61ULL, 0xFF8A046C92B87D11ULL, 
            0xEE2BA7A82EDDAFEFULL, 0xAE4C6DEBD796C2C5ULL, 0x93987AB165B73E1EULL, 0xDCCD3348C89FA28DULL, 
            0x51DE73E1DC7289EBULL, 0x43B08358B818AD80ULL, 0xD0DC65B759813F83ULL, 0x6DCA5C0A015FFAC8ULL, 
            0x055A498372F93F29ULL, 0xA59509630B3DDDD8ULL, 0xCC38E99E72A532BAULL, 0xE8623B8A2452C766ULL
        }
    },
    {
        {
            0xFCEDFCAE383FD23DULL, 0xEE5A1763689F3CE7ULL, 0xC87BCBDB7AC75D50ULL, 0x15DF20AC856BDC75ULL, 
            0x258112C902338A93ULL, 0x1E2E1333EB680B9AULL, 0x82A481C2B48CF00AULL, 0x5F64E9D3F3AFDA53ULL, 
            0x4155C65300B3E4FCULL, 0xC8D9463F1C31AD1DULL, 0x349192868DDBF60EULL, 0x2AC32BD102A4225AULL, 
            0x350DAE4A89A82F59ULL, 0xBCC53D3C8714504BULL, 0xDE0C57384D9F3FEDULL, 0x4D91D0372B982819ULL, 
            0xB06A2E9C1A1944F3ULL, 0x817B110860DD916AULL, 0x71385DA2F9B48472ULL, 0x0ADDBB36E98487BFULL, 
            0x219398C98F4F8B43ULL, 0x27C91BE0842A589FULL, 0xB341EB04389D572DULL, 0x54FD5AE724D3012CULL, 
            0xA7B5932254C4BCBEULL, 0x72E276812AD3024CULL, 0xC57B9BE01486DD88ULL, 0x9F0542A3FFE854DAULL, 
            0x45952CCB9374ABB9ULL, 0x7C2A713025AB27D6ULL, 0xD838B7F82B460110ULL, 0x892F5B307FC96601ULL
        },
        {
            0x5FE57FDF52FA130FULL, 0x3278AE2B066D4B99ULL, 0x238A39C44D0B1321ULL, 0x2F1183F6F5D49C87ULL, 
            0x8523F119843DC092ULL, 0x692BFA9902207CD7ULL, 0x4A39ACD23E0584EBULL, 0x870D554EAA45A8DBULL, 
            0xCC1D6F969BF8D05FULL, 0x80B4DA82037458F0ULL, 0x4E23AA2BAEE1B86CULL, 0x445A2D8F0C0B9A96ULL, 
            0x504E2EA5B6BDE4E0ULL, 0x883C7B2F3904A072ULL, 0x32380BE10DD9584CULL, 0x5C6BFE1B107683AFULL, 
            0xBF08C97137A249BDULL, 0x9E2497F27FC0EA7AULL, 0xDB6BF1A08CE40C51ULL, 0x18BF52030EF83A4CULL, 
            0x933B380C6E813A48ULL, 0x54A78DB4F38A45BFULL, 0x1174126B0990B027ULL, 0x325FD93993D6AF86ULL, 
            0x0263A0A1B7D1DBC1ULL, 0xF1F8BD7F9ADF84BBULL, 0x9D71982A6EB1E22FULL, 0x22985E1CF70A5EA6ULL, 
            0x7F995483B8C3E9C4ULL, 0x9BE352647F942962ULL, 0xEB468EC2E4060A78ULL, 0x65FBCCD799088A03ULL
        },
        {
            0x80DD5B071A3B8B39ULL, 0xAA791407BA9D17E7ULL, 0x2574D9511D93821AULL, 0x266950D447EABE8BULL, 
            0xE6EA914518FC50D8ULL, 0x74F6DFFACC007391ULL, 0x4C4707586DC55514ULL, 0x652D35853EB1CD90ULL, 
            0xB3CB175DBCFD1302ULL, 0x340FCE22D0A7C620ULL, 0xE4A0ECD298CD58A2ULL, 0x825A79C3DDCA38D2ULL, 
            0x3CD4ED5BE0075787ULL, 0x625F0CFD73BDE41CULL, 0x17696D4AF7C7825BULL, 0x86C027169B314F7DULL, 
            0xCAD6471E04F395FEULL, 0x54C0490522A7B1EDULL, 0x4C907860C33EEC58ULL, 0xD213D59DD1E8F52DULL, 
            0x0F84771D601A19CBULL, 0xAF8315AB3A82F90CULL, 0xB90B088DC069EEA0ULL, 0x77846603627EA71DULL, 
            0x2F0D7B27A4E1764DULL, 0x9E5D53033BD0C5D5ULL, 0xAE9FA499C9EF7743ULL, 0xC8B2AB3E95A5D190ULL, 
            0xF02DB2C56F7EBF2DULL, 0x337C4638F5D40784ULL, 0x684D3DA07B3BB7C1ULL, 0x40F2E8625ADDEC37ULL
        },
        {
            0xA3AC263D21FEEE4FULL, 0x428429A1C9F58F50ULL, 0xD430811A493BF232ULL, 0x61679FB661DB843DULL, 
            0xB547F126D180C13EULL, 0xBB33CC024F8E7A33ULL, 0xD8F0AE3632F92390ULL, 0x0FA8DB3979C66DC6ULL, 
            0xB9ECDDF233B10CB7ULL, 0x446E903356826A73ULL, 0xC0D75D9294320394ULL, 0x50BB412A7E22CFBDULL, 
            0xCB1269A88EA2307BULL, 0x9F319A9CB4CF3F2DULL, 0x8BD9B148A2213FD5ULL, 0xA3B5CE734B3DC656ULL, 
            0x6C519FF2401A8476ULL, 0x366F58929876DE70ULL, 0xA085B9238D666AEAULL, 0xE58A3DA57B43737BULL, 
            0x5CCB1F4BF1977BFFULL, 0x87915CA01C893193ULL, 0x78E7153AC452F592ULL, 0x908B58534B3543B4ULL, 
            0xD68DA99C7339CB87ULL, 0x9217AA871CABBED6ULL, 0x5092DF34459C07D1ULL, 0xF7DA0FB87C4FAF5CULL, 
            0xB662874C18914EE3ULL, 0xF265F26CCF012711ULL, 0xE78ACF58E167209AULL, 0x1EA448EF6A251BAAULL
        },
        {
            0xA671A584D7BEECFDULL, 0xE1B5AC422B9CDAC1ULL, 0x31AC99060CCB7093ULL, 0x2DF3D5C6B4F77959ULL, 
            0x64DC1189C043A0AEULL, 0x6FCBEBD8008557F2ULL, 0x04513B59F3A7005CULL, 0xFFE26B299D2EE947ULL, 
            0x757D0B833051955AULL, 0x967130C0A3C614ECULL, 0xADC8C826D1DEAC9FULL, 0xD25112BF2C96A06AULL, 
            0x3F1EDFB194D3BA08ULL, 0x07AB666F77253757ULL, 0xC39F710265D2B4E3ULL, 0x71D86FC430D6D5F8ULL, 
            0xDEC39E9163398BE5ULL, 0x213CBB70E6D152C9ULL, 0x5C84428EEF189718ULL, 0xBB8CA86556C3DC0AULL, 
            0x97A3BBA6F2F1B0B6ULL, 0x28A846ADDB017A0AULL, 0x90A77FD25C2AA2A5ULL, 0x4C9E0BE862C088AFULL, 
            0x57D2657D2C48936FULL, 0x08FD2D532EAE763DULL, 0x7A5F0CCE46F30CCEULL, 0xEA864443EFCA869AULL, 
            0x97C3C3E8B359EB79ULL, 0x059CCD698607A9FBULL, 0x2B04D91D26363810ULL, 0x008BF396970AB577ULL
        },
        {
            0x0B4E6D676A4F66A2ULL, 0x86A64EABA1072BDBULL, 0x17C4EAEDAE43568CULL, 0x7820C60CDF3BD784ULL, 
            0x0AD391C4DCCF0029ULL, 0x9498CDB421838DF7ULL, 0x6C2836CE2F2AC939ULL, 0x0564EDAF14A8AA6BULL, 
            0xD7CBD642D1BAF3DAULL, 0x23943251A5E61457ULL, 0xF89782CD4B097E9EULL, 0x13F46514D14EC632ULL, 
            0xC70F37675CE415A0ULL, 0x3756E6575A507776ULL, 0x24CE53B16838F345ULL, 0x382631CE35A4E12AULL, 
            0x3475CF225BDAA1DFULL, 0xBFCF01A7BAF5872AULL, 0x1FA79A401934DAFFULL, 0xB0DB7E45829F3439ULL, 
            0x4FAF72E3AFCDAFB5ULL, 0xEAFE19840A2FDCD9ULL, 0xB3F2F0ADCD42B2DBULL, 0xAA5FD26413B798E4ULL, 
            0x031A113A389FA7B6ULL, 0x041DBE4DAEC43B48ULL, 0xF2147D4741DD641CULL, 0xC727CD95A9DB32A0ULL, 
            0xCF595DC055D85C2CULL, 0x23BDCC6AEBF6CB18ULL, 0x9FF6F3A37DB4E78FULL, 0x8C05A7650C61FBB6ULL
        }
    },
    {
        {
            0x2871CC1B57508ECEULL, 0x22C160BA9A93DC4DULL, 0x23A0AA9F4E6BA226ULL, 0xCB14F3BECDEC9A8CULL, 
            0xD37732182845A4E4ULL, 0x24AEEBDAC7D0EDAAULL, 0x928B30001AE9B2B6ULL, 0xEA15B16193667F23ULL, 
            0x5F77816F3670057FULL, 0xF9E268C5217F299DULL, 0xA9F7DFC34B33C0D2ULL, 0x7859623DDC1E2762ULL, 
            0x0C8FEB2F9238F252ULL, 0xE648443512E41644ULL, 0x4EA276E616391EB0ULL, 0x92319AC007B821C8ULL, 
            0x0667A78231D739E2ULL, 0xB7D01E1A41490FC5ULL, 0xB1AA16C28B8074C4ULL, 0xBC23537A2AE03C2FULL, 
            0x56DA1E0867F33F97ULL, 0x9D878BFB9607EF2BULL, 0x80C7ABC08F8AED2BULL, 0x64A891AA631ADB32ULL, 
            0xA99473B9A93789CBULL, 0xEB4AC0F42D5BD634ULL, 0xCC552632DAB042C5ULL, 0x94D0472D87C8C29BULL, 
            0xEDB980F726BB0698ULL, 0x7DD47F099B127984ULL, 0xB806E92C5F8576F7ULL, 0x757588AE1D4E8DC1ULL
        },
        {
            0xE8F68744F7C86130ULL, 0x7824B2E10630DF78ULL, 0xA6187D367560C2F2ULL, 0x417667D4B2FE1529ULL, 
            0x225D81CED68391C9ULL, 0xE032D8F417625F39ULL, 0xF0BDB87C059AA671ULL, 0x43B5E5F13C6B7401ULL, 
            0x5DC72557B4EBD091ULL, 0x92EB381446DDD1D1ULL, 0x74A849CC462D3A99ULL, 0x172773E7BC3A49EAULL, 
            0x99EDC5C0A869F1E4ULL, 0xFAED187D0EDD560FULL, 0xA534935850C5906FULL, 0x90F4DEA28BB82B1DULL, 
            0x2A28F0FA1DFAB506ULL, 0x7243E613E47497A2ULL, 0xF1E927D68B1ABBA9ULL, 0xD3786649C6702E21ULL, 
            0x5CC7F36BC5BA12A7ULL, 0xA9F499683A2B75DEULL, 0x10C4CC4F58986B8CULL, 0xFCCAF1F066900249ULL, 
            0x5B6DFC77720B5924ULL, 0xCD87CC36414F8DAEULL, 0x4003EB0CCC8CB282ULL, 0xF68ABD879A4CFFD0ULL, 
            0xF20F410F3B09AE87ULL, 0x3272E638B885E5C2ULL, 0xF8301B3F0008D25CULL, 0x1A50B294236B3875ULL
        },
        {
            0x2DB2159A5D9F6C31ULL, 0x2742117D5DFE43CEULL, 0x3E56ED0F0F61C30EULL, 0xBD2F6616AE845526ULL, 
            0x3ECDFF10B0965FEDULL, 0x61CC00DFBCFF0B68ULL, 0x51368F93EE02D465ULL, 0x44E22AF8F3EF0C57ULL, 
            0xB8EAE6D75EB7945AULL, 0x6F2018DC8FC5ED35ULL, 0xDC525998B26A7423ULL, 0x6CCC2A4B031BDE43ULL, 
            0x0025669CF22F14C2ULL, 0x713CD87E575079ECULL, 0x2BECEBFE525630C2ULL, 0x6F0DC3709FA8AC69ULL, 
            0x76D039067290B55DULL, 0x0CE5F0285DD9A85AULL, 0x4ED97E1A4B9FD213ULL, 0xE64530D2D0931AA9ULL, 
            0x61D88223678D60DEULL, 0x03969DF81DAAFE77ULL, 0x6A74D2551DE45FC7ULL, 0x9142034E205810D5ULL, 
            0xD7950B72127E4109ULL, 0x753653701F61FE18ULL, 0x563E5384CA73887EULL, 0x979C01A711C873DAULL, 
            0x81A7F5F7B42DE0ADULL, 0x9D5880892B1BF0D1ULL, 0x53F699D64B362566ULL, 0xAC22B48BF52BBB02ULL
        },
        {
            0x5EA1A18CC3467931ULL, 0xE49E84BA70B34EA7ULL, 0x1ED99033AD068C06ULL, 0xEAE6126390B3E030ULL, 
            0x15976EA679A58883ULL, 0x5506C34D06E00081ULL, 0xE49457EDBCF06F0DULL, 0x1AAB787FBCCE2C05ULL, 
            0xC7B9C16AF9FB5B7EULL, 0x5A947409366E6349ULL, 0x3D00B985B71D56CCULL, 0xB3A6A1587BF06433ULL, 
            0x2C6D67542107A0CCULL, 0x16CA8FCADDC90AC1ULL, 0xDE0670E38911DB29ULL, 0x49AABC838129A694ULL, 
            0x5F4EBBF02D2C8B79ULL, 0x7036DB2F1096409DULL, 0xF2F9F5F4A7CA9CBBULL, 0x6EB1B9DF848F2AE6ULL, 
            0x809C90E9B13491A0ULL, 0x66DB876C6DA73820ULL, 0x83DE9546EBFBB1B3ULL, 0xC6681A1958A02800ULL, 
            0x5375CAD08893C44AULL, 0xE3E4909BA98D0659ULL, 0x0848E3BAFC304E88ULL, 0x19E2A6728E7D8198ULL, 
            0x6A1249A9379796BDULL, 0xA8DE240FD62ADD76ULL, 0x8FAA1D39F663AEDFULL, 0x3B49F77967E333DAULL
        },
        {
            0x0395EC44CD833795ULL, 0x7CB4B8AFCBD5E1FCULL, 0x3AF5515E73664935ULL, 0x8D79A53B10AFF1E1ULL, 
            0x09C1800795990CE2ULL, 0x1FC88C809743F529ULL, 0x1A4603DEC4C59565ULL, 0x357E3CE50337811BULL, 
            0x8F4BB5C42A3C5A40ULL, 0x77F3E1004FE78DDBULL, 0x71103D1E6C304E62ULL, 0x955184401804C276ULL, 
            0x383AC1F9E6DF9FE2ULL, 0x402489663D2583A7ULL, 0x756BE99F7553AB97ULL, 0x2F5EDB56B3A57AF5ULL, 
            0xE82466B71BD3C329ULL, 0xEF3484478F2B938DULL, 0xEB56463DF2083D73ULL, 0x5288D5733A5E468AULL, 
            0xE35CDC889243F4FBULL, 0x7AF79B310559A72BULL, 0xC3721E01C8A1C269ULL, 0xE3F89043714B459BULL, 
            0x33A984CD6BEA748BULL, 0x45E951EE73B249B2ULL, 0x006AF09A2385387AULL, 0x1A268E31DEBD35C3ULL, 
            0xCFA32A785A51C5B7ULL, 0xDBF516AEDA9DDB0CULL, 0x6A311CF66A5E3DFAULL, 0xA19DC5B5613D8830ULL
        },
        {
            0x74858A17A1324BB3ULL, 0x369AA76CA196182CULL, 0x92CEE517959C0B0DULL, 0x17CA393B8C6C683EULL, 
            0xC7DEFBB3B0B5ED55ULL, 0x73751326FC88F4E0ULL, 0x2071A3E0AC96FCEEULL, 0xE4D6510D262B52B1ULL, 
            0xEBBF5F0CD11BA865ULL, 0x1B4F12EBDBC3FBB1ULL, 0x420EF7D85E90578FULL, 0x4761E8609A644B40ULL, 
            0x0B2E3361258D7164ULL, 0x68F2C36D185079C8ULL, 0xD3F8ECE0D38DD643ULL, 0x9F88883FEA386C99ULL, 
            0xE79CC3A2EA849312ULL, 0xBD299A3FCEE6DB10ULL, 0xF692D7D10602BCBDULL, 0x39956DBE20107418ULL, 
            0x86C2BBCC68110147ULL, 0xF8AAA170499CDACCULL, 0x493D19FB6384ED74ULL, 0x2C3E3A869AC31B8FULL, 
            0x42F41D979B54944DULL, 0x90EE0F908D920F0DULL, 0xF77B2C1351B737A1ULL, 0x70D57B6774155354ULL, 
            0x90A9A1292B3C3644ULL, 0xE8E4BC2A04B19F79ULL, 0x1DF94F94EFB6D801ULL, 0xF9C2C67B1ACF5144ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseBConstants = {
    0x59CEDBD7E368890AULL,
    0x4F6F7C9BC6A65C23ULL,
    0x3580476725018075ULL,
    0x59CEDBD7E368890AULL,
    0x4F6F7C9BC6A65C23ULL,
    0x3580476725018075ULL,
    0x288C246DBA3FDCC7ULL,
    0xF1ADB5268426C41AULL,
    0xF0,
    0xAC,
    0xBF,
    0x54,
    0x46,
    0x0D,
    0x19,
    0xEE
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseCSalts = {
    {
        {
            0x21E5D191B68A0BC5ULL, 0x5583E664D7B3BAEEULL, 0xADE85477A6BA6F48ULL, 0x9B85B021098A80A2ULL, 
            0x785900D5B6B9DB14ULL, 0xB8C5340B3751FA41ULL, 0xD3F69987B0474B93ULL, 0xB11D4735122F4C16ULL, 
            0xD3F8BA7679755D37ULL, 0xCC8CD96C59756B7FULL, 0xB3276129C0078D47ULL, 0xFA28A85288BF12F5ULL, 
            0xDB10D62D04599942ULL, 0xCC9E6BBB92130DBFULL, 0xCC7C8395BBF6912EULL, 0x2DFB7C54D0CBFF69ULL, 
            0x3B4E7C3478073B30ULL, 0xED0359FE70E80F64ULL, 0x560676725ADF6624ULL, 0xA220232E08DA7D6FULL, 
            0x0568892FF2D7A6F6ULL, 0x88C1973A10C7FF91ULL, 0x47F020561FF704C9ULL, 0xBC31331EC5E86E94ULL, 
            0x8FCBE967F6166D68ULL, 0x5817C76A5BF681A1ULL, 0x0D76F194C4FCD9CCULL, 0x687C71BB7A2F9351ULL, 
            0x5602B9250F57CC3EULL, 0xCD84974359025C0EULL, 0x547320B91CBB6069ULL, 0x430AF9D77F5B6EE8ULL
        },
        {
            0x610E91898D0B3B67ULL, 0x849671CB6A5F936DULL, 0x277BDFBA71C34F55ULL, 0x7995CBEC9055B8E9ULL, 
            0x7E299CBFBE3E9A9FULL, 0x95A7B0EDA4911730ULL, 0x7F8E08F7C02EB1A9ULL, 0x12E484C82CFA8D02ULL, 
            0xFC0CEF477AE3B267ULL, 0xBB2F872C7E4FB755ULL, 0x540B21895092BC25ULL, 0xEDE536779FD614D6ULL, 
            0x3E95B30EDE07C1BCULL, 0x9E06019431A7B9EEULL, 0x533F9C87CCC5BC6CULL, 0xBD142CFCDBC6E3E7ULL, 
            0x0BCFD9AAC0D84A69ULL, 0x8D2871810524ED11ULL, 0x57F99BDC31B6292AULL, 0x7040CE6D3646884BULL, 
            0x4E0B51BA73C24D81ULL, 0x7F0F4996EBA59DCFULL, 0xF4E7E8FBA51048DFULL, 0xC28AEB7D01E2A578ULL, 
            0x7348FB37F175DAEAULL, 0x8ECD2FE3F90E1C32ULL, 0xAF11CCFD09CD98A4ULL, 0x84E46EF31EF6C795ULL, 
            0xC06A8F74D5CFB951ULL, 0x9F55A53C709005A8ULL, 0xEFF096B177D8AF80ULL, 0x64CCDB8A2F23A79DULL
        },
        {
            0x54651B0D62D915BFULL, 0xCECFA5EAFE6FFE46ULL, 0x4A88F4F3667EE8E2ULL, 0x9404D3E9B854F33DULL, 
            0x5553443ADE217284ULL, 0x0F604F770907FF7BULL, 0xD1EFE4A1CB1F5384ULL, 0x357C6AD439FE3D7DULL, 
            0xEA6BD7EE0CFB5344ULL, 0x742EFE5191D904EAULL, 0x9F4E2319F9020A0AULL, 0xF5AF9DEADA600E62ULL, 
            0x44687155E2AF078BULL, 0xDCACB9CF5C59AFC9ULL, 0x0F4D48785A21B68EULL, 0xE0C54D30456F2ACCULL, 
            0xB1C6EA6A9CADE882ULL, 0xE7E688B09BDC7661ULL, 0x5BACF921F05E37DBULL, 0x1EB13BAF7FDB6435ULL, 
            0xB207416799385DDDULL, 0x972D6725B711155EULL, 0x76FB2A5208A261B3ULL, 0x12F0A38FD7C343C6ULL, 
            0xFCB7D4A901B74B7DULL, 0x76E667A0B91E25BBULL, 0xEF95792D348C8C5BULL, 0x330DEFAD876FEAB3ULL, 
            0x6DE5AB11A7C50E37ULL, 0x7473833EED368388ULL, 0x9743B97851D71E71ULL, 0x679608D89FC20FFAULL
        },
        {
            0x951691221D936A5FULL, 0x03FAED08ABD58429ULL, 0x42012668C6C4DDE5ULL, 0xE840F03B1F19A731ULL, 
            0x0B2D9BCA1EC7A93DULL, 0xCF2A39652D452123ULL, 0x70BC9A69EC69A1FEULL, 0x4FB8156A7970913DULL, 
            0x887AFCC038712CBFULL, 0xE240A8EED12D965DULL, 0xFFCCE7039F2F31D3ULL, 0x1DD645867C33C7A8ULL, 
            0xD6EAFAB33A1F16B2ULL, 0x1C8C77D1486073A9ULL, 0x1093A158F8ACB8BFULL, 0xEEE12A3DCC4724A2ULL, 
            0x9AACBB8B8F691DD8ULL, 0x4D60AE7131C7D7FEULL, 0xDA9D91F3360727E5ULL, 0x44286E14CDC6B370ULL, 
            0x50CF1A32B92065DDULL, 0xC826BA9D7ABB2197ULL, 0x161AA715FF25C76FULL, 0x51D8117B4C6F0C22ULL, 
            0x7CD2A3D34FA540C9ULL, 0x20F16B67E0B011A7ULL, 0x2DDB95C80C520E02ULL, 0x48EDBF1620511372ULL, 
            0x142E206AA6011574ULL, 0x40927032807C9DA4ULL, 0x94145ECF17E49DD4ULL, 0xD4EE4B6301E47761ULL
        },
        {
            0x78E6E1A7EA207F93ULL, 0x0F0B92F4080FBE41ULL, 0x27775E2994909DF9ULL, 0x94B9BE39851352DAULL, 
            0x9415EC2A27D3086CULL, 0xE11B618C33AE19D4ULL, 0x182AE070993A0BA0ULL, 0xBF87FFBAC934BEABULL, 
            0x386B6A8D188E9B26ULL, 0x0B8C2B0A1BC8EB3CULL, 0xBF92BBAB14FD39A0ULL, 0x6499749B0B5D1EE0ULL, 
            0xDAC0825B5A846FDAULL, 0xBEA3B7C5A3600F34ULL, 0x2AA2011A8E737A60ULL, 0x59E980A7B2148BF2ULL, 
            0xFEB6C6356C65F294ULL, 0x88186D0C598F108AULL, 0xE28D78693E1C5EEAULL, 0x0A6A0C423FEDB1D8ULL, 
            0x210D217F0EB91171ULL, 0x89DC9C3CE567CEF2ULL, 0xB807354D4D11430EULL, 0xDD1F72F4E913759CULL, 
            0xC824EF173B530D86ULL, 0xB7C5C301CD262EE6ULL, 0x9AAC8AE531EA7D26ULL, 0x895F5121D15CE5DDULL, 
            0x94B9C4CFA1F66720ULL, 0x26EE865303596ACBULL, 0x79F241DF5B6CC945ULL, 0x5EF8D7BC03359BDAULL
        },
        {
            0xA86E9FDEA0CF943FULL, 0xCBE4EA23713868C5ULL, 0x2840D6463F8CAC75ULL, 0xD754976BC8641518ULL, 
            0xF01AFB3BE390B06CULL, 0x14526EDDA9AC9ADAULL, 0xA388AD2E3CA90E9AULL, 0x23126FFAABB1F467ULL, 
            0x6F8FC20B9FD03F16ULL, 0x2C5A197E4D9B2138ULL, 0xE7ECB923ACCECFB0ULL, 0x6AD531A533DDE9F8ULL, 
            0xAEFFAA5487F17E5EULL, 0xE00712B5F3402AACULL, 0x4432B87CECB4B4ECULL, 0x1DDDB62CFAE2B939ULL, 
            0x031D6689551DACA4ULL, 0x88928D0F9CD12893ULL, 0xB25463EA3390D6B7ULL, 0x02781254BD058531ULL, 
            0xF5C98AC6C96540FAULL, 0xA440831E83A46FF3ULL, 0xDF140A9319979A1FULL, 0x3870B54E0F40FB5CULL, 
            0x7926DF250E2971C2ULL, 0xEE0FDDC84BDF1BF5ULL, 0xEC6943B9F38D3890ULL, 0x644D32E6997CAFCEULL, 
            0x80C28F915970766FULL, 0x19E5AC92EC81B528ULL, 0xB9635722BACDC743ULL, 0xC32157B1B3F4614AULL
        }
    },
    {
        {
            0xDF186487A5EFF17DULL, 0x7EBB5C5498AAB027ULL, 0xC54C074625475638ULL, 0x1535E8584F03B7D7ULL, 
            0xAD32D8E041644387ULL, 0x8FC700D769FBF3BFULL, 0x151A877E7C6EE6A6ULL, 0xEDB73C828E39BCD1ULL, 
            0x1C43FBD21D403A09ULL, 0x27DF95C5175FEE8DULL, 0x39B414C06722573BULL, 0x4AB0FDDCBDD6A15CULL, 
            0x1CC689C1CDE249FCULL, 0xB06F17C6CE6C2F90ULL, 0x705A7AB2427F60C8ULL, 0xAC06353C5209FCB6ULL, 
            0xC0D842360EEBAF20ULL, 0x277F55E6B578A529ULL, 0x8178A92EBF2D83C3ULL, 0x99005CB580AB15A5ULL, 
            0x17853A5626B65C0EULL, 0x3E6C537FE5698D1AULL, 0xBC728DE05E355824ULL, 0x876DBB5474F29C5FULL, 
            0xE40A813E5FA6FD02ULL, 0x243BA89AC3E7F016ULL, 0x6E79DDC96CAB45E3ULL, 0x78B4A119449B66F3ULL, 
            0x6C3B2BC4640424A5ULL, 0xAC525758B8E3964FULL, 0x4844D97100BD06A3ULL, 0x95CF1059DF99FE5FULL
        },
        {
            0x883C92C97E11B2FBULL, 0x4A41D49AC5021F7DULL, 0x21338F91AFCA2D8EULL, 0x3F678FF58D844163ULL, 
            0x155D130752A3768BULL, 0x48C5DA2E45A8BDD6ULL, 0x92ED73E16BAFB796ULL, 0x9CF90045D25B86BCULL, 
            0x5FBB82D70123701CULL, 0xECA7324B92480F0BULL, 0xCFD4877B2E6DF50EULL, 0x8CD57D0E9F63FB8BULL, 
            0x0C5B8C3776FFF51CULL, 0x6AA47E2DCCE195F9ULL, 0x44E67B781EA56179ULL, 0x942925C732F65AF5ULL, 
            0x380ADBF81C7997D5ULL, 0xE08DFEF86D10703FULL, 0xF3BE20525401173DULL, 0x3D76E7698D2AAC94ULL, 
            0x00C0B07D94905D36ULL, 0x8AA096FD704FF6B2ULL, 0xC07FECB4356F89BDULL, 0xBD3A3322400858AFULL, 
            0x1589E8FB27BD784AULL, 0xA821D68DDB0273DCULL, 0x3D5A42AEC1BE2B2DULL, 0x86A6E7B4A1591DBAULL, 
            0x11B5DB3CD5AF2E15ULL, 0x92FDACABE8C1B6F0ULL, 0x63B026FBBAF2AB60ULL, 0xC9E59B3B64262A30ULL
        },
        {
            0x2ACC1855060E15DEULL, 0x076D3EB0F7772473ULL, 0xCF3FE73F25EB2CF5ULL, 0x48F676538888462AULL, 
            0x4A81BC1CE7A943E0ULL, 0x407F8C31FFDB7413ULL, 0xD1AB8406B922AC06ULL, 0x2A44546C9B56F80DULL, 
            0x4291B391D4459D3EULL, 0x22650610AB8B0F1EULL, 0xA2433EB28A7B84E7ULL, 0x67F8F8929BC6CF76ULL, 
            0x13E41F2A411BF1A4ULL, 0x99667F61A72755A3ULL, 0x7A15A262806F84D0ULL, 0x72EA3E6264394FEFULL, 
            0x50D7728EBB49ECA9ULL, 0xC006BE5826646C02ULL, 0x036761714C95D4A6ULL, 0xFB98F29BC38C0FDAULL, 
            0x2E3161C000B8D3E0ULL, 0x4178DD6DBB1A4A9AULL, 0x0A873BF258342A10ULL, 0x31866BC22AE948C9ULL, 
            0x7DB52C4B87AA2200ULL, 0x7694BF74A2D23EC0ULL, 0x121382EB3F3BD792ULL, 0x37C240190CCF2301ULL, 
            0x949295D4A67C3AF1ULL, 0x55F9F37B5ED82A92ULL, 0x5626AF7DD6B77696ULL, 0x9A00B1C3040CABE8ULL
        },
        {
            0x1A3556EBD6C8AF03ULL, 0xB3F26B7F1A10F79CULL, 0x687D5BDC239AD5D5ULL, 0xD28CD379628E176AULL, 
            0x9A051DF73DB10F9EULL, 0x58FB1749DDFF433BULL, 0x060A206A5FE796ECULL, 0x5314CBCA77302E1CULL, 
            0xECBAD1C25A7F0C2AULL, 0xEB5DCF3D8BBFD418ULL, 0x710E775AD7D3A6ADULL, 0x74C1A720E1813C00ULL, 
            0xF179452424DEBC3BULL, 0x54EF5FE0D09E21D1ULL, 0xD90193BE06A451EBULL, 0x2120ADDA60C01D39ULL, 
            0xE4BD0074634F0AABULL, 0x729ED8C263543BFBULL, 0x25B86BE8182E6A52ULL, 0x3CC8F41A83690E87ULL, 
            0xF86E4C78C735B825ULL, 0x7632962987D28E8BULL, 0xFD73C2853EA49AF0ULL, 0xD7047DEC61DD1928ULL, 
            0x296CFD01CFE3EDD7ULL, 0xC657FB49D5CC76A5ULL, 0xD342610DB831935EULL, 0x1A1EBCFB540ECD84ULL, 
            0x2AD916B477903B81ULL, 0x344421C443DA058CULL, 0xB1A0697E93B991E1ULL, 0xD1A5ABDCFF2841F2ULL
        },
        {
            0x7B27070F0BB8068BULL, 0xCD0B043A920AD9F6ULL, 0xD861B4471AB9C27EULL, 0x4E8F6380C8F3A1B4ULL, 
            0x183B4E359EB57972ULL, 0x6B86275388B67330ULL, 0x21E58AA7A4F0B8A2ULL, 0x1664649764BFC7A0ULL, 
            0x0DAED07E62C1CB97ULL, 0x22682B7232A57138ULL, 0x5092E91AAB5A5056ULL, 0x7F847E6E4BFAAEC3ULL, 
            0x01AE2569B5640D26ULL, 0xDF621ED59C60027BULL, 0xF286FA7E2ECB4C69ULL, 0x0754DD4A8A8A315DULL, 
            0x4AD0DAE45FD8A158ULL, 0x0071C39010071213ULL, 0xA9FE3271ACB587C1ULL, 0xC3DA97CA1028CA8EULL, 
            0xBE8CC152AE5FAE48ULL, 0x3A352CDF0BD7FCB7ULL, 0x9DF44B183F46B9BDULL, 0xDCE5421E12605FF8ULL, 
            0xCEE357F61F904CD3ULL, 0xEEB5B0C5C088A7E8ULL, 0x6D2C7CD43F6BFDEDULL, 0x0D33B5F6BA80E5B5ULL, 
            0xFC10FA2806A8B6C5ULL, 0x92EAC882F1B9E746ULL, 0x2098A3CFA946DD3EULL, 0x2804530E01F894A6ULL
        },
        {
            0xADFE5541ED95B451ULL, 0x974408F4EE2FDC50ULL, 0x1CD09C155EFFF819ULL, 0x239BB9F610D58C38ULL, 
            0x4A85C92E4BC5EC4FULL, 0x4EE8D18A2CBD510BULL, 0xC20B30FCC733C1BAULL, 0xDE2B32A974D0413BULL, 
            0xAB388C2EE1482A0DULL, 0xC31641C21F2C7361ULL, 0xB49FD82229D92023ULL, 0xB4C1BAC7EA69686FULL, 
            0xF9C84676CC448977ULL, 0x1984FEF37054D045ULL, 0x3004014F2A8B6708ULL, 0xD19C21D6FBA49DC1ULL, 
            0x9F4DF1872908EE8FULL, 0x10F7A541375C9B6AULL, 0xEDAF28BAD5D66FC2ULL, 0xD3659FF485346090ULL, 
            0x5ACD25971D7F4401ULL, 0xD59408DD2F2472A2ULL, 0x06F84D6DD59E9C33ULL, 0x692A1E5263FAA04EULL, 
            0x12A21326C8C32FDCULL, 0xA8FA691D7D492136ULL, 0xA7CC3EDC954328F4ULL, 0x4D73CCE787F16158ULL, 
            0xDCAE81B55916B03DULL, 0xADEA8A884158EE96ULL, 0xC0B64B9522ACA278ULL, 0x80E7826D6B8CEA14ULL
        }
    },
    {
        {
            0x65CA00D664174B51ULL, 0x6E5CCF5A62510497ULL, 0xA05464C2206F0A66ULL, 0xA236D190C95DEB92ULL, 
            0x4B52BDFCCD419843ULL, 0x5D56B1B5B930FAFBULL, 0xA8A93C1C8D51FBEFULL, 0xF1D1D3A13353CAE0ULL, 
            0xD672C76B05EABD2FULL, 0x41D6FE2F307321C5ULL, 0x249FF71079E021D6ULL, 0x9BDE8EE7A90A276AULL, 
            0x0A405458BC1B5D59ULL, 0x8357DE585654E5FCULL, 0xC0BC96FEB66C60DCULL, 0xC5C1CE09347B7B45ULL, 
            0xEB83506385CD8280ULL, 0xFB4686DDC013EC10ULL, 0x5E65D73051654702ULL, 0xFDA79D9205F5F26FULL, 
            0x62F7BD5AEA37AC77ULL, 0x4AF2FE7EDB4ED9AAULL, 0xBFE5378699BE1E49ULL, 0x449D0510101111E1ULL, 
            0x8EB8AA8F2CE47401ULL, 0x8AC30E5281125646ULL, 0xD2A794C5C4F85179ULL, 0x72D148CE23404DAFULL, 
            0x9AD7CB092217E852ULL, 0x707C01332AD56455ULL, 0x683B1232D663B80EULL, 0xABD1D5777E5659C2ULL
        },
        {
            0x0B06470D2030FC8BULL, 0xB0DD15A2CB3E339BULL, 0xBCA47135E76FD120ULL, 0x6FD458C038797087ULL, 
            0xAE09487C17EE593BULL, 0x6EF1B0F3A4F8399EULL, 0xFD02BBEB124444FFULL, 0x609AB49484000B0EULL, 
            0x16CF0EF0C469CB48ULL, 0xEFAB7D66FE2FDD4CULL, 0x462BF7BC5F2C23F8ULL, 0x9606DE594214DC68ULL, 
            0xAD07C7021DE229C4ULL, 0xEE938F9F47E4A386ULL, 0xBE7A6B2C8D3C86A7ULL, 0xAFF89FFA2F86131BULL, 
            0x566D23892A4939A4ULL, 0x670BA3A03736CEA3ULL, 0xBB136E790DBC90C7ULL, 0x81CB567FEAE06CACULL, 
            0x7B0608FF068C6510ULL, 0xAAC8608D681B8520ULL, 0x63059EBC00E5525BULL, 0x83393DC367C12272ULL, 
            0x6B6CE88519F87FCFULL, 0xDF9591BB9466452CULL, 0x623CE7C5E73CE5DDULL, 0xCB538A615AFA5AE1ULL, 
            0xAEDD6E2573C3AF1DULL, 0x27504CC74595412CULL, 0x3C5F9487F064D6A9ULL, 0x40778CD979078079ULL
        },
        {
            0x46E92A72376923D9ULL, 0xFEA64630C3B3B51BULL, 0x6948911E8020050CULL, 0x03D3922344A6C7EDULL, 
            0xFF7C976DD79D6D63ULL, 0xD836685CB1044272ULL, 0xBDAE94CFFBCE9895ULL, 0x4A6826D3C5483B04ULL, 
            0x95915AACC08616AFULL, 0xA308F5CAE8CAB80EULL, 0x8093EF8BB456F826ULL, 0xC1C9A89DC7E92C34ULL, 
            0xA0A469992E9822E4ULL, 0x0CA63052D304AE7BULL, 0x8BF7B399F8FA1C17ULL, 0x1C94050F9ED6984DULL, 
            0xFA522124D8E25B25ULL, 0x0BC7AEE04E5BB7D2ULL, 0xF74DCB033A535ED1ULL, 0x91BD8515707DEFDBULL, 
            0x828491A989C63517ULL, 0xA5BC32D3EAD2C5FCULL, 0xA01D5D1F6E2F681EULL, 0x995BA4BF7CCE834EULL, 
            0x8A84E925A534F345ULL, 0x5B8FA80B9255143FULL, 0xAD529577280C51B6ULL, 0xF8179765EECC5841ULL, 
            0xA89E2AE555FEE6B9ULL, 0xE5D5E87DC1913972ULL, 0x4E7881623301E681ULL, 0xDFAFDDAA1241302AULL
        },
        {
            0x896433D6D9DF7B95ULL, 0x9ECA37249A33936EULL, 0xAD8D19937BA8F440ULL, 0xD5FA6D1412CA31F1ULL, 
            0xD67013DF43496E6FULL, 0x782053D87957C43FULL, 0xF473E9DA6A842F4CULL, 0xF62D0C48656BCD8EULL, 
            0x3D8DE0229ADEF5F7ULL, 0xD92C7F639988B8EAULL, 0x84525B40A3BB50E6ULL, 0x74350F6B24CA7D07ULL, 
            0x0610BD6756DF2C52ULL, 0x9FCDBFFF8A4B32BCULL, 0xCCE680B6D4B07CBBULL, 0x474EC41E807E3E72ULL, 
            0x3B88A894782ED657ULL, 0x67F1E186D5DA8BA8ULL, 0xD2BB7CB959FE2A7FULL, 0x232C1E632B52D453ULL, 
            0x079C4243AB33212CULL, 0x3E8BDDE4956C1CE1ULL, 0xC45D73A934AE9E7FULL, 0xB3669C577500A4CBULL, 
            0xED5E24B8FE288A93ULL, 0x3E0B9CE48DD4BA42ULL, 0x5B8E69E689C408BEULL, 0x58E12B8D29535E65ULL, 
            0x25784A6949027617ULL, 0x702C2FCA633B5D16ULL, 0xE123C59691FDD620ULL, 0x867A55B53FF957CCULL
        },
        {
            0x419889CC1CBCDBAFULL, 0xDF81EE4DDFA4F6EBULL, 0xB539FD1D005C71B6ULL, 0xF89751E3735869BEULL, 
            0x8201A3C863F8E372ULL, 0x6A9F7245A3E4377FULL, 0x21B2A2F85941A9A3ULL, 0x251EC409B87FD544ULL, 
            0x92C9316459B4D83CULL, 0x94DA82733DCEC9EEULL, 0xB6AA81E560782C70ULL, 0xF7E51F297C947CF9ULL, 
            0x4F4BEDA7EB523EDEULL, 0xB9CD527F7DAADDD6ULL, 0x00B96705803D58CEULL, 0xAEF80775BD424BF1ULL, 
            0x59B3E50E022A9D10ULL, 0xCDAF6D43EB6188AAULL, 0xD3F1A0A18E750F51ULL, 0x7583D6D27A8F3BB2ULL, 
            0x9C96F2149C945388ULL, 0x12F7928D38C2B226ULL, 0x747F7C3A381CAEC9ULL, 0x53B8A899E969BCDFULL, 
            0xDAEE0E008A1B14CCULL, 0xDFF1B9CEB63F1C6BULL, 0x9827FACBC78D14ABULL, 0x5A930B18FF8E8209ULL, 
            0x38F8AC2521CE33AFULL, 0x393212FFD3B24564ULL, 0xB8E374231F32AB8AULL, 0xC838AFCA76C15AD7ULL
        },
        {
            0x11CEB9CBBEC5978FULL, 0xC3A75C74DB478D1DULL, 0xAB5FD27F861FD850ULL, 0xD51423A8D3D5F50AULL, 
            0xD4AE0FD554C68EA6ULL, 0x43757A31211AF7E4ULL, 0x6249CDD33D0AE102ULL, 0x6F70C8E1B7F0932CULL, 
            0xD9BEA4DB9211942AULL, 0x0479CE66C5D9F2D9ULL, 0x33BCA90800FFBEB7ULL, 0xC6736476918D676AULL, 
            0x65841576C090E73AULL, 0xD837C6928FAE1855ULL, 0xEAFE8CD8B13EA695ULL, 0x9EE4E030E50FB8D0ULL, 
            0xFB20B4F54B0AF0BAULL, 0x69B07B1995C48E36ULL, 0x277377C53C4BB1F0ULL, 0x37C90E6755B96035ULL, 
            0x244D61C1E929F833ULL, 0x6DBF58DB30E3F606ULL, 0x6B11CBD3F4B52E6FULL, 0x18A6C61613CC17A4ULL, 
            0xEFEDB8C85DE7509AULL, 0xD5F222D3BA35077CULL, 0xDE7DFDBB2E8C34EBULL, 0x944D2421F8628405ULL, 
            0x7229994E5E960814ULL, 0x746107DE6F8B57C6ULL, 0xC0649EB0707231E7ULL, 0xED089F9954697ECEULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseCConstants = {
    0x0F1926F29E60ED02ULL,
    0x3B1979B96683FCBBULL,
    0x859EE457D2B7E46CULL,
    0x0F1926F29E60ED02ULL,
    0x3B1979B96683FCBBULL,
    0x859EE457D2B7E46CULL,
    0xAE85D0533BCFE141ULL,
    0x43232E5C16EB6866ULL,
    0xCB,
    0x49,
    0xA7,
    0x7A,
    0xAB,
    0xA9,
    0xEB,
    0x7D
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseDSalts = {
    {
        {
            0xC482A24048D8A7B8ULL, 0xB24319EDA5777D9CULL, 0xC37A7B11827F9524ULL, 0xDEFA4ED73E5CFC3FULL, 
            0x91B02D09AA71DDA2ULL, 0x0F9097E2ADFEC9AAULL, 0x97AFDFD40D8CE4A1ULL, 0x4F693684D03D3BEFULL, 
            0xD74F24114F6989A2ULL, 0x9DE17BAFF51B2481ULL, 0x32257A1726492BADULL, 0x0CCE74A4ADA37D7CULL, 
            0x2BD22A3163818A51ULL, 0x505E77E5912E3010ULL, 0xF765E44EA22E934DULL, 0xFD75282654A65987ULL, 
            0xA053E3471A079053ULL, 0xF89B19DE1513798BULL, 0x7C0732D8015D4E0DULL, 0x1A78657778631028ULL, 
            0xCC9A87889F0E02C8ULL, 0x759F9198BD0C92E9ULL, 0x7796F53C49880692ULL, 0xC2BBEED33FFA3DACULL, 
            0xD1D01E201A22B49EULL, 0xD62453DDBBF3C067ULL, 0xB722AE6A6D19DEFEULL, 0xFDBB9EA5813F4E10ULL, 
            0x7D52F9B9CBE15882ULL, 0xFDD8DA22297A4CF8ULL, 0xE39E973E0B098FCCULL, 0x3C926DA7E2F90DDAULL
        },
        {
            0xDA033902C93D9A45ULL, 0x29025366170E431DULL, 0x093D0A2AE8FCCFC1ULL, 0x6B61D72834C312AFULL, 
            0x77E336BCCD1ED08AULL, 0xE7574FC416BB0A63ULL, 0xE2DA34531D34D5F0ULL, 0xA1BF306885638BF5ULL, 
            0xBE59D1B081BA6B72ULL, 0xD288091CA134A782ULL, 0x1027DB5C898A58D1ULL, 0xAB34F246836F6198ULL, 
            0x36D584DF5DCE6EA5ULL, 0xA8D5E207BB869D97ULL, 0xC417D69E350B1467ULL, 0x103869345AC81B6AULL, 
            0xE44B0BFADE79E6B2ULL, 0xBDE31A8B7035E249ULL, 0x54FFCA400EF0EE81ULL, 0xD9D07242B3F558B5ULL, 
            0x8A28859A4DC0A51DULL, 0xCD2D17AE8A96A06AULL, 0x57C33FA4025B974AULL, 0x18FDE41E6CB93C1CULL, 
            0xC9EA3CFC0A573138ULL, 0x2D5AF43E29ECB604ULL, 0x5BC5CBCDF0E88EF0ULL, 0x96808792084F76DFULL, 
            0xC8BA004644582FF9ULL, 0x79AF0928FA786511ULL, 0xBA9305CDCBCF7960ULL, 0xFAE8225390849649ULL
        },
        {
            0x32BF1C49A8295794ULL, 0x4E6EEB6E835E875FULL, 0x2E7BD9A2B253C92CULL, 0xC608AB3BD98E440AULL, 
            0x3A1B965912C48D9FULL, 0xE72FB53BE3E79599ULL, 0xD6D3186EC0DEAA2DULL, 0x57E07DDC859692F9ULL, 
            0xF55BA8FE59108E73ULL, 0xDB9873F3B4E1FDE9ULL, 0xBA11DCAFD106116AULL, 0xF43B6848C434C96CULL, 
            0x76507709BA4CCE70ULL, 0x3B4CC1580E515572ULL, 0x812B481A3FDA4B3FULL, 0x66D230EFB8179C8CULL, 
            0x809B51366769ECB5ULL, 0x81CD11DA20043CAEULL, 0xC84D352269929A51ULL, 0xAC1A86BD99E7D471ULL, 
            0xD6E0808954F1E7AEULL, 0x7C62C6A70C6D84CBULL, 0x56848FA1081EBBF0ULL, 0x7A3F5B17D09FECD0ULL, 
            0x63452C2496A9D13AULL, 0x083D14D7C6F66D32ULL, 0xEB78165CCC99B78AULL, 0x601FFAB3CFD4C8C7ULL, 
            0xB947597E3A4496DEULL, 0xD6401E2602F747B3ULL, 0xB3C7A467D66ACD6FULL, 0xB441219CD003F325ULL
        },
        {
            0xFCC9C4EABBE8F301ULL, 0xC3ECC5DF09DC87AEULL, 0x17C9867AB80A7CA7ULL, 0x32784A759C46A5DAULL, 
            0x7ECC8C0756A05F7FULL, 0xEEF03F9097B564C3ULL, 0xCA782A10BFD8C418ULL, 0xB4329D1B7B3D1CEBULL, 
            0x1EDEF0E74EC13254ULL, 0xAD814E71DB3904CCULL, 0xE2DDBC900057A3BEULL, 0x71474C15DF1DD405ULL, 
            0x899F114110277188ULL, 0x470DDBEFB744DDDFULL, 0x112DBF25C3D2A873ULL, 0x88646D63780AD33CULL, 
            0x12309E04F4C5BAC2ULL, 0x02D46634D4E37758ULL, 0x425AF9FF5BD9137AULL, 0x8AF99E97DA1387F9ULL, 
            0xDB8FF222E22736D4ULL, 0x0E0D5B3810061476ULL, 0x19447AFFB80105AEULL, 0x2AFB9D702A46109AULL, 
            0xD54A4BA53E44D94CULL, 0x37AC261F2A0C97C2ULL, 0x1ACA148E0D35444AULL, 0x181AEC07FC9596A5ULL, 
            0xDC4098E339DF5B70ULL, 0xF617E996B0386E3EULL, 0x1ECDC387DE1FC5D0ULL, 0x09ACC8C105337A09ULL
        },
        {
            0x0E233DB1E9D1EB2CULL, 0x2D62132B9D8261C7ULL, 0x759898522646B39FULL, 0x710DF900C060290AULL, 
            0xA2D7F1640282AEC7ULL, 0xF5B16E08B3989C54ULL, 0x6630CD19A406F773ULL, 0x09AA86509F21E6E4ULL, 
            0x2DDD4DEA4CDE4DFCULL, 0x6F520F01AD0BB19EULL, 0xC919688C41C22186ULL, 0xAF0ED6C5EC0192D6ULL, 
            0xE7F51F30C96EBFB5ULL, 0x00BD57202037B578ULL, 0x9EADC0B36A992EE7ULL, 0x016B253A32A1F9B8ULL, 
            0x95E742D7E91329B2ULL, 0xD9460601EECF0214ULL, 0x720AD9A9FDF4EEB9ULL, 0x1CCFFCD011D07508ULL, 
            0x7EBCFE530B33AA9BULL, 0x39A0626AA6E239B7ULL, 0xD965819DC78D7E3AULL, 0xC9BF62A76248B104ULL, 
            0x47C4FB45C11E0FFCULL, 0xFF7AD0F6B4A46C23ULL, 0xDEBB6C376EC20C5DULL, 0xAF384D2D545FFC3AULL, 
            0xE596CA3CD6EDF70BULL, 0x59C58BD7491C3733ULL, 0xC6241BABDEB795DFULL, 0x10A6E04D045259C9ULL
        },
        {
            0x4A48FDA477F6A0EBULL, 0x0E003EB73B17CF85ULL, 0x0BD838A275A15CACULL, 0x2781D7FF74E6A024ULL, 
            0x69B18EDED185710EULL, 0x90DB57D8406E2B83ULL, 0x79DBEFE9AA93F1F2ULL, 0xBD3016744646916FULL, 
            0xB49ED453AD841D14ULL, 0xCA4DC5BE4EB010B4ULL, 0x7762478A9D79183DULL, 0xCE1B808FEFAC996FULL, 
            0xFE28019BBC6A0F8CULL, 0x514AA23ACFF08CBCULL, 0xFF88BC1B2234B570ULL, 0x03ECF09297F15EE0ULL, 
            0x659B92E8B8E5EF62ULL, 0xBFBB28D26BCE81F1ULL, 0x11B7342B3E920374ULL, 0xB1C1A710B8255176ULL, 
            0x7133051FC1ACD1A0ULL, 0x3C05A0D4B861301BULL, 0xF78D60A1EAAC9EF4ULL, 0xD2FD25871DB9F40BULL, 
            0x8BC253FF5DC528C1ULL, 0x447A94DC16017DE4ULL, 0x5463FAA1D826E454ULL, 0x1F065CB57CCE2496ULL, 
            0x855AEA13081DF1D3ULL, 0x6F810F55427067E3ULL, 0xDFC7E45E5FA73C08ULL, 0x670889E153AB53A6ULL
        }
    },
    {
        {
            0xEBE90F17133DE936ULL, 0x119D9D713D36BDC9ULL, 0xDC501950B2A6500BULL, 0x90B9D7468C795D27ULL, 
            0x084F0157CEEFCB8AULL, 0x4C1E74A78F2A24B6ULL, 0x8BA68CDB6FB47E44ULL, 0x4666D89D66D40220ULL, 
            0xA367100617F2C5FDULL, 0x63D03D34C6BD3A01ULL, 0x3DC7D535BB14C99FULL, 0x84D5A2C26EF98FD4ULL, 
            0xB2FA191D3EE8468BULL, 0x895AAAD6F1153EB1ULL, 0x2D79D0A2024B8371ULL, 0xBFA0525706D40167ULL, 
            0xF3337FF717362FB7ULL, 0x0DDEB4033812C414ULL, 0x68D29188456BC114ULL, 0xBFEAEC57E9A55BFAULL, 
            0xCFB8411A50047EE1ULL, 0x4C4A26DF46AD3C8BULL, 0xC77CC7170AAD91B7ULL, 0x3BADA716B3058D18ULL, 
            0x3728E418E980B3E5ULL, 0xB09F97DBD043A09BULL, 0xC6999220745A293CULL, 0x15B1AE23C0F9BBCAULL, 
            0xAF4840FEC5FDB949ULL, 0x8D16E9573E400B9FULL, 0x881AC66B2DBFFE5CULL, 0xB52E21A558C2A7B5ULL
        },
        {
            0x07E878C7C16FF60AULL, 0x7C48B8A6AC2E9A4BULL, 0xC41022F8A69111DFULL, 0x46473D7C4F0A69BDULL, 
            0x5324C13D5CBAFFF2ULL, 0x6574A6DB28FEA6AEULL, 0xB8937F19FD90A432ULL, 0x27C43736764742FFULL, 
            0x3FA82595C518FA8CULL, 0x09C3F3D4F2256F71ULL, 0x8BDAEDA5A23558B3ULL, 0x56750C4E658C0F0FULL, 
            0x082DA70C568400DFULL, 0xD8A12BEC92BCB657ULL, 0x9A130838C1AFC8F9ULL, 0xC246F132A87D5EE7ULL, 
            0x86C379D95E97379AULL, 0x8BDBDB5FDA30915FULL, 0xF7BBD39C1F872F0BULL, 0x4CD2210FEFC90CF0ULL, 
            0x50802785C1035540ULL, 0x15E2840D68605060ULL, 0x629B774BFCEC41EBULL, 0x1D83D233E8565309ULL, 
            0xD087E8C650893CEDULL, 0xB4326F3E3966624AULL, 0xCFEE0BA06430B5A0ULL, 0xA5DAC57D329A107FULL, 
            0xDBAD1DB5715B33C6ULL, 0x2BA84706E6E015EAULL, 0x3ACA1B8C43DE74D3ULL, 0x5518F502023B403AULL
        },
        {
            0x164AB143EC659D24ULL, 0xC18FD988B9B2D6CFULL, 0x1058AB5A05B39011ULL, 0x21E7A5CBC1FFA297ULL, 
            0x0732821B34AE0BE6ULL, 0x69B2F609DD86CD26ULL, 0xC95B6C127B5DA1A9ULL, 0x139C6DE28F83093FULL, 
            0x0A6407A5BC92C624ULL, 0xFE853DAFD7DECC6DULL, 0xF4582DC7C68226A6ULL, 0x144E30EF4EA4B147ULL, 
            0x69BEE84230A3B131ULL, 0xD1C81FDCC159AFBCULL, 0x380158B0BB815CD3ULL, 0xFD1801AD32241C54ULL, 
            0x422933C8F6FAD258ULL, 0x01A5D909A665D95BULL, 0x2E4D9A3F94FF0350ULL, 0x3EFA1AB5424A780CULL, 
            0x546550BE8ECF48FCULL, 0xB75EDD1778CE0017ULL, 0xC255B7B6E55E8BEAULL, 0xBD107194A2D08FE2ULL, 
            0x1F31E4C4CF06D1E8ULL, 0x2AADFC5FEE44968FULL, 0x5EAE6751E4E4A2E9ULL, 0x5139C4514D235977ULL, 
            0x615F48383B888B0DULL, 0x73C9091D03C41DF7ULL, 0x0D03D28B9194C044ULL, 0x0A3C7DE95C783D12ULL
        },
        {
            0x910A10DAABF76A81ULL, 0x804B59235CABE230ULL, 0x5F4946D699A0D2DFULL, 0x040B70879DB27453ULL, 
            0xACEE6A6C05C47E18ULL, 0xC46EFA40461E3AB0ULL, 0xF1206A3566D30348ULL, 0x476825B8387AF188ULL, 
            0xC87AAFF1E2712D61ULL, 0x0B9042B86CF5596FULL, 0xF2FE03A8FFDDAE34ULL, 0xC4FF58CFCF553211ULL, 
            0xDE0D6BF65EF22151ULL, 0xB3FB7B5EC898B4F7ULL, 0x71FE1BCAC59DA37CULL, 0x8F8A8F3B7AA639DBULL, 
            0x89B1D531E4B94A6AULL, 0x94E527E7F902E18BULL, 0xF7C84EC514F6F172ULL, 0xF4747D6A3B4E76FAULL, 
            0x58297DDB1D36DD17ULL, 0x41155717C1C42666ULL, 0x9759DFBC0F30CBD7ULL, 0xB57F7C1551C07806ULL, 
            0x529A5C34F9907DA2ULL, 0x2631E26333C5892AULL, 0xDED0AD80E63D41D8ULL, 0xC58733CC82AD6AB4ULL, 
            0x921BFD642E28BB0EULL, 0x18F4C93E1303B60FULL, 0x1E5C405C5099A027ULL, 0x95BF6818C9947FE2ULL
        },
        {
            0xAD229422FDB86E0EULL, 0xE7CCC5E373B7BA52ULL, 0xEE860E8CFE686338ULL, 0xBF6E94AE374853AAULL, 
            0xB2817B9C82C269B9ULL, 0x7DC2EE91F5AD98CAULL, 0xD640E914479C206EULL, 0x0B317764F2911BA4ULL, 
            0x5EE9F627D750A34EULL, 0xF678C0F5835CD74BULL, 0x67AF8F521691791CULL, 0xFB8738F2684A30CBULL, 
            0xFF6B3377D48F9C33ULL, 0xF136DCD6E3767DC2ULL, 0x8BFB840D1E345FF1ULL, 0xC907C865C0A777A3ULL, 
            0x685E43F58DEC5F16ULL, 0x35352046827029CAULL, 0xE8EBCCF766F804C1ULL, 0xE3C453CAE09D094FULL, 
            0x5B7F8493AC82A45DULL, 0xD22CDE94B21B1993ULL, 0xAC7EE35BD5D1724FULL, 0xE912D583244714FEULL, 
            0x8414D9570B514389ULL, 0x6DA573F1860968D3ULL, 0x2236E86C912E456FULL, 0x4AFB74BF8A179D05ULL, 
            0xC4C90A7FC7BB2C8EULL, 0x954398E7932AC4CCULL, 0xC3785E31621F295FULL, 0x25DEEC1B0DEA0A4CULL
        },
        {
            0xE31650D516987B97ULL, 0xDF29B28F43AF7F5FULL, 0x6C08746DA17C6922ULL, 0x123A0BEB98F656DDULL, 
            0xB509C33D77288934ULL, 0x12A800E0F80D450FULL, 0xDB4B26C79EC10E0AULL, 0xC126CB6910D10F18ULL, 
            0x60F68893C67339DBULL, 0x275C3403B27730CDULL, 0x306E0B431552C8F4ULL, 0x02CDA5B1C10610B9ULL, 
            0xCB4AD86ED50C66FAULL, 0xC25AD81686D0AE68ULL, 0x171B881D723750F4ULL, 0xDCCE38E30423E785ULL, 
            0x76512795FD9C41CDULL, 0xDCA880E3015E8DE5ULL, 0xE900AB7A20E84CFAULL, 0x777DA3BAAFBD189FULL, 
            0xBAD22C30014D8C93ULL, 0x3719C7E70B1DF3F8ULL, 0x26C7A952A7BF0ECDULL, 0xB8D7446C89E09725ULL, 
            0x973FFDCBEC9CFF7CULL, 0x9730C8975AE7644CULL, 0x85E1A984E828B004ULL, 0x0E12BC0695C52BCBULL, 
            0x9EE79F8E45CD613CULL, 0x30DCDA185DE8411CULL, 0x6CB5A3D343229072ULL, 0x0670F8E3D09B411DULL
        }
    },
    {
        {
            0xEB93A15BD447F061ULL, 0xF5D376493A420CDAULL, 0x34937337195F1DECULL, 0x3C9C884B5B8ECE3DULL, 
            0xAA8FF1ED3ACE4370ULL, 0x996EA76150983AFAULL, 0x9839307447CAFA7AULL, 0x5D93E14AD6F20FBEULL, 
            0x5FF1980F394C8B40ULL, 0x274C56BD0EF3F4C6ULL, 0x9E4FD4B24EA2B12FULL, 0x1E97E17742BEE380ULL, 
            0xBE213BD027E8EA56ULL, 0x37DDDF857178545CULL, 0x171143D8503101BDULL, 0xBD94F04F0E8CBF42ULL, 
            0x1307D857B6145A3BULL, 0xCAACC7B4CC3396D9ULL, 0x20F905BDC9673E07ULL, 0xFC10430DBDF18DF8ULL, 
            0x3507111517DF1934ULL, 0x11221593369BCA82ULL, 0xE451EF76337E4EAEULL, 0x78036F97D88C0CBEULL, 
            0x82BF807AF357FB28ULL, 0x4791CD90752F6F83ULL, 0xD24F998405EBF352ULL, 0xD567CE0A69508CDCULL, 
            0x1B1F3527D837559AULL, 0x127A9577E5511352ULL, 0xCDC6415CB785475FULL, 0x464D643F626AD84DULL
        },
        {
            0x8B2855B82EC2D8F7ULL, 0x90B5BF2F24464543ULL, 0xA58DB78D3623F658ULL, 0x3A46383B7FA63B4DULL, 
            0xA916148615A41340ULL, 0x8420575E4DB4ACFDULL, 0xA266EFEA16131912ULL, 0x2B52830CA1CC9E7AULL, 
            0xE37BC0E8DDBBDCB3ULL, 0x62128A038CE5A0F3ULL, 0x206880AF7FADB191ULL, 0xD929DDFFA17EDA50ULL, 
            0x3B899CB6AE9444F6ULL, 0x79E1E751789E2F01ULL, 0xD304A6B0DC63F25EULL, 0x7C863FB3D71C9864ULL, 
            0x0912CE5DBD5C389FULL, 0x9D90485F9DCBA42EULL, 0x71E1CCC2A6C7AE21ULL, 0x1A3EAA624345878CULL, 
            0x49F57CB85A7B0C0CULL, 0xE497C5D9FD45EDE2ULL, 0xA89BF9ED854D396CULL, 0x29EE8FB5DCAEF155ULL, 
            0x2BA317D3027F5A6BULL, 0x8B6AA51C901D8899ULL, 0x2971D8DCC3925DF9ULL, 0x0ECF3D67140C1C8CULL, 
            0x15A02554620E3801ULL, 0x92574981C53B8C40ULL, 0x3C26042EF91870AEULL, 0xE271F53F224B161CULL
        },
        {
            0xAF04782A042C6F9BULL, 0xB53AAC13A18166E3ULL, 0xE7C7C9D246DE357BULL, 0x5399B5B6EF117BDBULL, 
            0x4BF4B7BA7CE89186ULL, 0x3E0CF3B0ED2B8CFDULL, 0x2F1DCCA6D80311B6ULL, 0xB6474ED599528C5CULL, 
            0x03F581784040768BULL, 0xD23070D1C8E0BE7CULL, 0xB30E9342B5366B30ULL, 0x1BBAF69EC7B5FDFEULL, 
            0x29ABE903F5C4E6C0ULL, 0xB661223337E7EC22ULL, 0xADE6A5C199D45E93ULL, 0xD1E0DCDFB825F1C5ULL, 
            0x0C9ECBE4F0415296ULL, 0x5CF0B668BF092B30ULL, 0xD68555A721BC5B9FULL, 0xC3AAF0404251DCE8ULL, 
            0x701C5576A2C9FEA0ULL, 0xF24BB022190D8A24ULL, 0x40188E02F2BD9981ULL, 0xCA7964D424F74903ULL, 
            0x3E0A5AD3EA5F05D1ULL, 0x0F40F44B49727D50ULL, 0xD97A1EA037D14DDDULL, 0x435D631A1272F869ULL, 
            0x1033A591D0065BCDULL, 0x008EEB981260D6B5ULL, 0x2D28D646FA53AFF6ULL, 0xD8B11BE849F3E7F1ULL
        },
        {
            0x4E8E1D4BF3E33417ULL, 0x9D8C5889949EB77DULL, 0x86311597AC3DC848ULL, 0xBE8981F0D0E9C150ULL, 
            0x7A98C4E1C665507AULL, 0x80248C18C597CDE4ULL, 0xFACC331E2EA8E00BULL, 0xCD5D2C08712508B7ULL, 
            0xB5B6D58069610C77ULL, 0xEDB2C533E26AD97EULL, 0xE3A4D06ACDB979FFULL, 0x33883DBFA238E41DULL, 
            0xB7F2DDADDB1AE883ULL, 0xA18333A9441A489DULL, 0xBCD4D73023420361ULL, 0xCE84A93A567793FAULL, 
            0xA6E0D04E24533499ULL, 0x8BC8BB48A302AC4FULL, 0x318704BA4AF69308ULL, 0x77D49F2D5E3BEA67ULL, 
            0x11ECF06FCB56DBC6ULL, 0x3D55A1306622CEA5ULL, 0xB8874E969B674A42ULL, 0x6616D4539179B746ULL, 
            0xCF79082D5FAB7249ULL, 0x422F20EA2713B917ULL, 0x517C6BE29FE2A9EEULL, 0x102D792BBA7232DFULL, 
            0x20D7C661A4836DAEULL, 0xBEDCEB7AC29DD46FULL, 0x491E411A25EC7797ULL, 0x278AACB53B478C33ULL
        },
        {
            0x73B6667F764FFDFCULL, 0xE8DAD0EA140E5A2BULL, 0xA1908A5143673746ULL, 0x350545143E369C7CULL, 
            0x0839B09CB68A087CULL, 0xA84A3D724E40DC4DULL, 0x4BAC79ACE7107248ULL, 0x90D540007FE6563FULL, 
            0xA20E6FA867786F42ULL, 0x6B4FC15FF9F450A2ULL, 0x87EF6459FE4EAC0FULL, 0x40048319BBCAD7DFULL, 
            0xAC8978DC3CA38F27ULL, 0xD44B81358FAD1E01ULL, 0x1BE803AED122CE91ULL, 0x6E0752070DD8102DULL, 
            0x2B1657ADF4E0BD89ULL, 0x28A663DC3CD93940ULL, 0x0A4DEE0B4D58C24BULL, 0x78F14AB0F36DB6B6ULL, 
            0x442FE51722CC31A2ULL, 0x39627BCA5FC8F6F8ULL, 0x692C28F050E42D5EULL, 0xE633B091586C07E3ULL, 
            0xA68D08368E2ABBD7ULL, 0x3F8C3456A533FCB2ULL, 0x9655EC2A8EBF87E6ULL, 0x6E365BB94033BC30ULL, 
            0x2EBEEB0D285916E8ULL, 0x3BF608E20F7FEF8CULL, 0x29A1B557C0B4E73FULL, 0x18EC8A6BFED86D75ULL
        },
        {
            0x93CE116970332BF3ULL, 0xCA22448FE154E937ULL, 0xA2FC1C56A91DED94ULL, 0xA91B149D07D6EFE3ULL, 
            0xECF7D6E91A4B5E48ULL, 0x89DAE7BAB304B896ULL, 0x64E8491182C2EA6EULL, 0x09C0A53FE2D4F18CULL, 
            0x48DD7B441FCD6D13ULL, 0xABA9943EEDA94C77ULL, 0xE1E9E8BEF9F55904ULL, 0xB8926C68BFD13507ULL, 
            0x2DEFBE7AD4E011A8ULL, 0x4146A0ED079AE821ULL, 0xF6C9D1BED903C0EAULL, 0xE5738B7C21873531ULL, 
            0x36BB62B59003EBDAULL, 0xBE5235AD9FAC7B85ULL, 0xE69700B5F55C8F69ULL, 0x2224CADB2C03557EULL, 
            0xC787A633FD89E6DAULL, 0xF3E44BFFF3AECD9DULL, 0x1E450A7165986675ULL, 0xE52A75A4A6486A1AULL, 
            0xA6CEA02F2ED98D1AULL, 0x5D5597B2FD4E6643ULL, 0xEBEAEBE4BE13C8B3ULL, 0x871EF332680D6A53ULL, 
            0xA9BD9AF67A984CC2ULL, 0x7ACAAA761AE8EB65ULL, 0x110AB87D1E4BB541ULL, 0xC4E70466CBDB9C06ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseDConstants = {
    0xA735BA1B659DCB07ULL,
    0xB94DA5096CE888E7ULL,
    0x625EDA22BEE0DB0EULL,
    0xA735BA1B659DCB07ULL,
    0xB94DA5096CE888E7ULL,
    0x625EDA22BEE0DB0EULL,
    0xA2958849FF9F8BF1ULL,
    0xFCAFB85926920C9CULL,
    0x21,
    0x9F,
    0x8D,
    0x85,
    0xFE,
    0xBD,
    0x6B,
    0x3F
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseESalts = {
    {
        {
            0x6413EF7F1DB4BF0FULL, 0x7C502FDD98A31DF2ULL, 0x118F443DA0C3464DULL, 0x9ABC0AD8481A2FC2ULL, 
            0xC3AEE780A1889C35ULL, 0x7E34CC998EC82E0DULL, 0xA8C9FAEA28336B9FULL, 0xD5CE3232368E943EULL, 
            0x643F54C3BD43F895ULL, 0xD8D6515A63F51826ULL, 0x42BA60A5F7B0A7F5ULL, 0x33B99647FDF7B2F4ULL, 
            0x53369E867339DBBFULL, 0xEA062C71F7069094ULL, 0x93F4C72893A235BEULL, 0x17E467BAE2CE03DDULL, 
            0xD7AEE36033AEB7EEULL, 0x7834F6EEC4E75300ULL, 0x45778AB6D3577B89ULL, 0xFD1A3DE8C3C831F1ULL, 
            0x4D4BAFA6F7516185ULL, 0x715CA926A11E8FE8ULL, 0x234E963D643F7D67ULL, 0x7B036179FF021222ULL, 
            0x163D605446F30FAFULL, 0xFB1E8E1559554B18ULL, 0x8A348F708D69DC23ULL, 0x9F8B7EFB35777C55ULL, 
            0x4E8FED07F5A5115BULL, 0x0F56262033CF98FEULL, 0x94D74BEC96AE9119ULL, 0x7D6111AAF6F2E1D2ULL
        },
        {
            0x256C0D4C2127B9F9ULL, 0xEE39902FBA7323B6ULL, 0xF6B33246FF5CFEE7ULL, 0xC3EFE844CBF24959ULL, 
            0xCB7AB9E36C4D7B01ULL, 0x25D28E32FB2D2ED5ULL, 0xBA00798674B4AC67ULL, 0xD02A06BBC2A63801ULL, 
            0x6CB962C5F4E9E517ULL, 0xC9E74F28803B8D00ULL, 0xCB122090811D8ED8ULL, 0xC1F7BE3897CC3926ULL, 
            0xC1150A38E942EEB2ULL, 0x57CDB38EC14AA33BULL, 0x9E9F765A5B7E7850ULL, 0x16138D69975AED7DULL, 
            0xDA2A6C033FFB6E36ULL, 0xE571FFE95814DE62ULL, 0x80E594E07ED22B83ULL, 0x07AA85A74B984E2CULL, 
            0xAB054BB9917C2DB1ULL, 0x224EB3533223DC17ULL, 0x00FB13F5FA3F5D98ULL, 0xE223BD13775B6E16ULL, 
            0x33C16CF484A5D327ULL, 0x85C8F57756E99170ULL, 0x8E709D5A3CEB3481ULL, 0xA34691E406572E43ULL, 
            0x0EE395F41EE0E87AULL, 0xEEC11ACF115A4890ULL, 0x5C1F5D3BACBFCF79ULL, 0xF142746A56EDB73FULL
        },
        {
            0xB50D45E82802C4F0ULL, 0xC936D5F510D544CAULL, 0xC37F3368302759C9ULL, 0xAD6AC54C7E792786ULL, 
            0xFFF6C0FAF7A0CBB9ULL, 0x86D1B2B27C984475ULL, 0xB61B51D9887632C2ULL, 0x2CF29131E304E9A5ULL, 
            0x7600AC19496C4089ULL, 0x4D56FFA5320D927AULL, 0x3F2A88E876D1CC36ULL, 0xD2F83416EC5C9540ULL, 
            0xA5FFEA4CF6E9F2D6ULL, 0x293EE7BF6639D3C2ULL, 0x5062E0D2411464BBULL, 0xFD6D1E7B0CB7B7A3ULL, 
            0x2C99FE6F21D77E91ULL, 0xB7753674A7E93EBAULL, 0x77CFBE641EC66890ULL, 0x22E2610158D8C885ULL, 
            0x339A98A90EFCB045ULL, 0xBB71C98EFE2D241FULL, 0xB57EC7FD5752F906ULL, 0x1B5DF38D0C11486BULL, 
            0x0D0107CCC714FB98ULL, 0x757F266511FEF914ULL, 0x8C98A97E404E9B05ULL, 0xBD24A22113A1CF21ULL, 
            0x7B788C5361E7E92EULL, 0x72840BEDAB925694ULL, 0xBCB5BC4654BC2039ULL, 0xBD6DBBBCB2798A6EULL
        },
        {
            0x759E6F7A336E5592ULL, 0x2578E9E5BE499B70ULL, 0x06785AE2283678A1ULL, 0xF5B1920D22425023ULL, 
            0xC76E4ADABEB7BD22ULL, 0x96B2C076D01C4DBFULL, 0xEEAFF4C79E993327ULL, 0x33537A4C139EA5F1ULL, 
            0x56CB13F6F2DFCDDFULL, 0xF03EC3F405EC21B5ULL, 0xE20546659FD238C5ULL, 0xBE3FEC039AD84DF7ULL, 
            0x36C10E8634B0FBA4ULL, 0xC47D5E7F5B33ABEAULL, 0x447888C086B97BFDULL, 0x4D8A2CB6A1D31E3CULL, 
            0x68628967AAA806EDULL, 0xDA718F531B2762F0ULL, 0xCFF5B435C408AD14ULL, 0xC871022226708A45ULL, 
            0x518583CD3AA0E1C2ULL, 0x2FBCCA806E0D346FULL, 0x4456803E02BE78A2ULL, 0x9DB82ECCD0A8C1E5ULL, 
            0x18CBA9ED6DC7E993ULL, 0xFE193AD378816E75ULL, 0xE6109153AFB00019ULL, 0x84B10518F408DE62ULL, 
            0x6E095A3940FD5443ULL, 0xD5E2CE08606C0DDFULL, 0x526728FDE8192A5AULL, 0x499A10B4FA0093BEULL
        },
        {
            0xB7DCF5E669C8189EULL, 0x3937D1B3C144D0FCULL, 0xB6B4111013967B77ULL, 0x54F8B047CB89E969ULL, 
            0x7F0557BA2F20F718ULL, 0xB2A79C06EBDAF149ULL, 0x8C3D782C04063C5CULL, 0x7208AE3C454F0B9CULL, 
            0xB11CDDA8D8131C23ULL, 0xC48D7CE83475EAB7ULL, 0xAD7AF14086B79AB5ULL, 0xA07943A1114DDDD5ULL, 
            0x46B194689583B0F4ULL, 0x21F79E4DAF63732BULL, 0x96D5B25D736C7B88ULL, 0x49087B27B96D8B46ULL, 
            0xDE014A9C4032BE1CULL, 0x668E7DF2501C2CFEULL, 0x2EF8F0F365A85CAEULL, 0xB950966A7F93D859ULL, 
            0xCE768E18DCCF3605ULL, 0x892582A92887C352ULL, 0x87510F848B118BB4ULL, 0x4ECCE0334C2F4520ULL, 
            0xFB78871C4377544CULL, 0x555C40FFF4054C9AULL, 0x2B9144473EE5E9D1ULL, 0xFA3FADB1228608E2ULL, 
            0xAB094F9A5C5A5957ULL, 0x0E644BD927F79493ULL, 0x006860844338B2C6ULL, 0x3ACB68BCE83FDC1CULL
        },
        {
            0x7146E26E8F2E8EDBULL, 0xD274000A5F04F7FAULL, 0x73FCEA0A421DB8C7ULL, 0x0A112C6CF3295229ULL, 
            0xAA8AEE4EFCBC4EB7ULL, 0x80E2822A1F2284A9ULL, 0x02FAB4C6F1AD0E58ULL, 0xE7186B8C0D93AE75ULL, 
            0x8BC9C86239EC75CCULL, 0x885BC56C31912BB7ULL, 0xCBA6E40E1E932D12ULL, 0xB7D6EF52BFAE575AULL, 
            0x91DB79203A6D8F82ULL, 0x066E6D2723365547ULL, 0xD315EDC6F9FA04EEULL, 0x629357380E6F5C76ULL, 
            0xB714038593C386AEULL, 0x4F5B2F8E7BDE7B32ULL, 0xB008954492586123ULL, 0x13A14CDB368CA58FULL, 
            0x967371C6BC3DE8E1ULL, 0x8B34972066DC51E0ULL, 0x4FE5B408470C7294ULL, 0x1DEB6AE0061D7FEEULL, 
            0x175BA7AE7686D816ULL, 0x84EECEA200CC656AULL, 0x705BC3D778DE2627ULL, 0x3FFB23EB9D292558ULL, 
            0x7FE723D6751D40EBULL, 0x54672CF6B0A8B67DULL, 0xE8100158261955CFULL, 0x323F0A49EFB7B981ULL
        }
    },
    {
        {
            0xCDE372B63440B72FULL, 0x022C7AF32C1C89D8ULL, 0x741BB48FF4D085BEULL, 0x97F4CD6FC95AD4D9ULL, 
            0x2565CFD668E0B98AULL, 0x65C5B4CF7F0B08FCULL, 0x86044ADA17C49BD9ULL, 0xC312F529ACD428ECULL, 
            0x914B11E1EFA1CE2FULL, 0x258CF7DDEF9EF138ULL, 0x062E9E870CFFF6A0ULL, 0xB088624882D21446ULL, 
            0x02AA70FD21660234ULL, 0x56C702EE624C3C26ULL, 0x44D97067EDD6E4F0ULL, 0x3E7E2B5FAA0DD47EULL, 
            0xE425744F140762F1ULL, 0x4CB45CCAE175990CULL, 0x610C1CE74A6485E3ULL, 0x6B8E5C25DD4BEAABULL, 
            0x7BA45536CD19A1E6ULL, 0x2174D0E9040B7879ULL, 0x2B1E4808C0D06E9BULL, 0xC585CFA117256323ULL, 
            0x0BABFF06782B2AA7ULL, 0x4C7153C1F2A0D2BFULL, 0xAD1236F64A2A92F4ULL, 0xC043677DD5BF1BF8ULL, 
            0x31ED311989D183D4ULL, 0xE6C9D3FC135B9147ULL, 0x3323A28B99085DD5ULL, 0x618FF2DD285B28D0ULL
        },
        {
            0x7FF481F3940B3F2EULL, 0x642DE90ACA9D8C32ULL, 0xF16F33C1D5BC4C60ULL, 0x96868A4F50F97271ULL, 
            0x2EC997DBE6F1367FULL, 0x642169E0723270C6ULL, 0x71F31D799E13369DULL, 0x64C5A5D9454613C0ULL, 
            0xFE06B4BD18BD56C4ULL, 0x25A785D20DA647A1ULL, 0x0C9049C485DB5514ULL, 0xA719F014F886B5D7ULL, 
            0xF5BB20B98F92B3B6ULL, 0xBA47D5159404307FULL, 0x36C2631A988EE174ULL, 0x623FEDE88655FD51ULL, 
            0xCD1AB7482C405CB2ULL, 0x3AD3C214112DB944ULL, 0x67D22BECDFA9D4C8ULL, 0x30D05301EB8AED3CULL, 
            0x9A596CEE10B2DBC0ULL, 0xD7DABD35E7754979ULL, 0x1A949337638D91D4ULL, 0xDC1910A4F1FCEAADULL, 
            0x6E897A9E70FDB658ULL, 0xE215FE9885E780BCULL, 0x6ED46E44AC6CDCD7ULL, 0x1EA3D3BBAE12FF60ULL, 
            0x465220C11B9559E1ULL, 0x75416AC0074BAF09ULL, 0xBF0B2B56269A28D0ULL, 0x9A0ED92E192689C9ULL
        },
        {
            0x38AE18F28E45E6B5ULL, 0x65C97A74380D3195ULL, 0x0A8990CDDFBE22DAULL, 0x86BD7F9A89435834ULL, 
            0x0F99F3F32A02D005ULL, 0xB09F1ACE5261CC2EULL, 0x74BF42FF6BDEC88CULL, 0xDC776F5D0EDB0F61ULL, 
            0xA03C286188F76D2BULL, 0xD0116E57E69A9A4DULL, 0x37E9EF57D21C0D38ULL, 0x57BC630A68268CB9ULL, 
            0xF38FC16BD205B3D0ULL, 0xCF4082E01F7D821CULL, 0xB047404896F6A4B7ULL, 0x6FED579325B81A07ULL, 
            0xF3B95EC080A98715ULL, 0xD91AB35E07E19E02ULL, 0x417AF999E30D1233ULL, 0x24ED9D373BAEB75DULL, 
            0x8253292D7158B145ULL, 0x4C0E95F0EB5A1DD9ULL, 0xD4E5457BEA65FDC8ULL, 0x47C49EF2306A4309ULL, 
            0x53C5F041EBBCB88AULL, 0xA9658C44269410B7ULL, 0xC0B87D6CDC0916DAULL, 0x8BB83C4652B8EA37ULL, 
            0x46A5D2EB96480BFBULL, 0x3C77AE914ED65677ULL, 0xB21C76B30BC6B130ULL, 0x2B4D09C0DA90B751ULL
        },
        {
            0x371920FEAC68D38AULL, 0x6BB5A7D42798EE7BULL, 0x1C5C41F730A331C2ULL, 0x88E346304B9C3451ULL, 
            0x9C5DB8F8F51CBFABULL, 0x41F612BC0CB21E42ULL, 0x71FDFA33BC657AA7ULL, 0x4453EB576CE6DDF1ULL, 
            0xD6E250B526FCB86BULL, 0x53A85D319C028FD1ULL, 0x5809B4BD50C5E8A9ULL, 0x001BCCFE22F42FD9ULL, 
            0x0D0CF38DCADA086DULL, 0xF29D562E9F590C8CULL, 0x683A93CA61FF4489ULL, 0x81C1F90CFB7E5042ULL, 
            0x9855DA8D4B82FE63ULL, 0x8C826DFE083F8851ULL, 0xC5F76C1D8547BA43ULL, 0x75774FB57293828DULL, 
            0xF3C07EB41B4ECE93ULL, 0x7F226F5949DB9471ULL, 0xCC63ECC23A2D8AEAULL, 0x0EA43F16DDFD12CBULL, 
            0x7E5F21FA25F67578ULL, 0xCAEBA388F3DC7248ULL, 0xE688DF8A99010584ULL, 0x8DC3CC26911859E2ULL, 
            0xA3DDF5AE8231E189ULL, 0xB14E6EEF8E1EC6C0ULL, 0xC6D1AB3ADC822B63ULL, 0x67B523E2D59BE4ACULL
        },
        {
            0xD649911417367764ULL, 0x1CB3623BB489EF0CULL, 0x41CDACD554FEA5B2ULL, 0x8A734B3FCE57381CULL, 
            0x3CA6CFA838DA7134ULL, 0xAAE395BE359EDBA8ULL, 0x0AD1941C3F7E0BA4ULL, 0x80A4B85826C3B157ULL, 
            0xB253A9C0BC8566D5ULL, 0xBBD2D4FF3F693BF3ULL, 0x80A94E9774D1D1A9ULL, 0xB6799DCD5DEAE93DULL, 
            0x0FBE072B0F105183ULL, 0x5615AECF00C24A62ULL, 0x7C65D91DFD8B997BULL, 0xB0ACE50C5F36A369ULL, 
            0x1141A234C419A566ULL, 0x419561C65F8902B6ULL, 0xE478B841FCE59876ULL, 0xB4C54F1DC1EB76A6ULL, 
            0x0D8BE860455C4F59ULL, 0xDADA7946B10C841BULL, 0xCD0D06766DDFFEFBULL, 0xC135574EE021EF01ULL, 
            0x989F855FD38781D0ULL, 0xDDAF8D6BC91082AAULL, 0xDA9B00DD4FD5C5BDULL, 0xA7A59E19222F6F51ULL, 
            0x7653678511738A48ULL, 0x69F95FEA6E998814ULL, 0x0C74FD32B197C1FDULL, 0xB576C69BE299AEF5ULL
        },
        {
            0x9312FB5DAB97C3B4ULL, 0xDFAE5A400DB93F91ULL, 0x34369332F4949736ULL, 0x8994F6CF258B8292ULL, 
            0x30B8C158C6208C12ULL, 0xBBC7BDC44876CFE2ULL, 0xF315C5B0495EEE15ULL, 0x8AFE9493A7899392ULL, 
            0x1637E9D03C5033BDULL, 0x497C1086BA00954CULL, 0xB5CCD2173E9EEA5EULL, 0x6E7A1DDDE12D9A1DULL, 
            0x98DF43F2DD9B524DULL, 0xD29BA1DA16606D4CULL, 0x59FF71A230AFCFA2ULL, 0x8CD6C29D2EEBD315ULL, 
            0x201CFFD30B65B561ULL, 0x5C1B3E7625B91FD6ULL, 0x4FF46B1814891E61ULL, 0xF51D71037C3C203EULL, 
            0x6F36410B09B9B4ECULL, 0xBEA033288FCBFD10ULL, 0x29C64880891CC5D8ULL, 0xBF70FE470F49B28CULL, 
            0x9ED738EB4CF81BBAULL, 0xF2A87D5893660CAEULL, 0x067AACF8D3794794ULL, 0x3373D3741C28CD9EULL, 
            0x89497953C9294774ULL, 0x4A851B9A06B16CBEULL, 0x4269654C31F959FAULL, 0xFDBEB2E63A2BC1F9ULL
        }
    },
    {
        {
            0x8C0F4D3BACBCA05EULL, 0x2BE30D5BAF422B1BULL, 0x132383E285C93DC3ULL, 0xD00DFD077E4D07CEULL, 
            0x147EA0B0795F8BB0ULL, 0xD923DC4D248ED51DULL, 0x37124331CEB6A254ULL, 0xA8D22FBEAB184495ULL, 
            0xA7B524C967091EF8ULL, 0xBA635D91737A51C7ULL, 0xDB7D38E7DFBB7051ULL, 0xC19E190BED590EAEULL, 
            0xEF4B317CA112C0E4ULL, 0x92CF61CE67AAAD69ULL, 0x011A8F74D0448F36ULL, 0x11DE8A1B234A70ABULL, 
            0xE48B50E642B81A68ULL, 0x8E4CB05DAF311AD3ULL, 0x51F1E4E00414732DULL, 0xF4EC35793D22E2A0ULL, 
            0xD0D490DB98AA0AF8ULL, 0xC7AFB065B7E88CF7ULL, 0x237F62CBE6A06864ULL, 0xD90C69166351B950ULL, 
            0x0B6D2093F90115A6ULL, 0xCFC01FA56E3BDDCEULL, 0x94AF0DA6C333459CULL, 0x8665A86E76E23BC9ULL, 
            0xD72507383E17EB92ULL, 0x1DAE4112FF2B8609ULL, 0x75883DC7701DB281ULL, 0x0DA82BAE8495A8DDULL
        },
        {
            0xCA0B62193BDA85B8ULL, 0x1EC582C00B6151C2ULL, 0xAB9DCF36C28895A0ULL, 0x8F0BC3BF4CE640A5ULL, 
            0x074F572BF9FB7C60ULL, 0xE391C8DA91C16870ULL, 0xD0C164F24766AB7FULL, 0x79FA8DD47CFEB1A6ULL, 
            0xDD48BF7A07F4D3C0ULL, 0xDF8ECA23F05AB96AULL, 0x020589FB346C70DAULL, 0xC0ACD9C483795FECULL, 
            0x5CE963B96042A8D3ULL, 0x16305E291524D661ULL, 0xCBBCDC5C916FABF7ULL, 0xE56192DA290CDFDCULL, 
            0x6DCBFB75510951F8ULL, 0xA1ACF69CC0E1A262ULL, 0x8AA8A8F334EBC9E5ULL, 0x19E78C280C778D0FULL, 
            0xAFB12E7F11384E78ULL, 0x148B849C27640F28ULL, 0x080C9D7086F5ADB7ULL, 0x644F963A2A236129ULL, 
            0xC2331E296850B78DULL, 0x22618CF19D2B0A1CULL, 0x6F6D171C4E3E0583ULL, 0x685D0239DFC3E2D5ULL, 
            0xE7EC60BE5D4EA18DULL, 0x8C367F95FD71E67EULL, 0x8331D7609ED675ADULL, 0xE612B5D3FADDD6CFULL
        },
        {
            0xBE7F500DFC93918CULL, 0xD6AC2B05A2A93D12ULL, 0x37525FCD8923914EULL, 0x342E0CBEF4608477ULL, 
            0x8603A6A7D0EE4952ULL, 0x7E2D4C2B9021B026ULL, 0x3211C67E778B4A0CULL, 0x52AFE8DC4E7924C0ULL, 
            0xE9D3D870511B5500ULL, 0xC8FD32713E17463AULL, 0x0BA7271021C52A7AULL, 0x2535A7CAEE5B91E4ULL, 
            0xC65702FB3BBBD5A9ULL, 0x49F40BABC10A3E54ULL, 0xC5326DFD8D7657CAULL, 0x320EBB4262C5F278ULL, 
            0xE43A3FFECD380BB7ULL, 0x124368DF31808148ULL, 0x4FC5C89A244CF726ULL, 0xF3C9053265919F48ULL, 
            0xACDC00C5D97B542CULL, 0xB4F6C14DDA45BC3FULL, 0x80091C4B5B342490ULL, 0x36BA2CFB9A791511ULL, 
            0xBE23D2CDE05594D8ULL, 0x055868D1B87ADBD6ULL, 0x6E4986FD16A37A89ULL, 0x6D0CC7DA28BFCC67ULL, 
            0xAFD1A408EE78CF77ULL, 0x75DBEBFC17347247ULL, 0xFC5649C7568C7B41ULL, 0xFEA4B35DDD9320B8ULL
        },
        {
            0x93F14601FA362B7EULL, 0x91470B3B649E64BFULL, 0xC2642B9CAB3A0ECDULL, 0x7FE9DBF80D25385EULL, 
            0x9CF52706A2039ABCULL, 0x890AFD0805B1ECE2ULL, 0xC692D198C2BD62BEULL, 0xC29315484F3E058BULL, 
            0x5CC3F5D29F6E860FULL, 0x5384DEE6E97B85B1ULL, 0xEE1607EE282A8807ULL, 0x6DAC5499F152DE82ULL, 
            0x8411E709D8CBDFAAULL, 0x6A27D0C7227896FEULL, 0xE01EE0E64061F950ULL, 0x32923679BFBE93FDULL, 
            0xD16E7DD136CAE741ULL, 0x4F2E534E8DDB0BFEULL, 0x6D701408ABA39DE7ULL, 0x804396749A1135A6ULL, 
            0xC31444084CFF1BE8ULL, 0xDF74430928B50133ULL, 0x36E3C954D55CDFB2ULL, 0x0A47F5D3642BB0FBULL, 
            0x387B738D0D0829DAULL, 0x701358A59E2CEC92ULL, 0xA3A946E79135D38DULL, 0xC825A180D1100272ULL, 
            0x83429CAD9B8E81B7ULL, 0x85734649608E8F6DULL, 0xB60516CCBDDE5318ULL, 0x62ABF061D14B126EULL
        },
        {
            0x2BB606DB922FEB42ULL, 0x99045F4137FCE693ULL, 0x5701594AE7DE604FULL, 0xC75F6AE56D8BD6F0ULL, 
            0xD34F3D9471980F39ULL, 0x263A9C4BDB89C545ULL, 0x0AAEB053A24820B7ULL, 0xFBC3C178846B8DB0ULL, 
            0x15C4E789B012E2DBULL, 0x35C20867D1464B04ULL, 0x388BA09720E33E8DULL, 0x760B98F5F6735014ULL, 
            0xBF8F073C4FE16370ULL, 0x752E9E68BED0155DULL, 0x438E74C7DDD04272ULL, 0xA2E8850419DFAE32ULL, 
            0xE666173BB02A7A53ULL, 0x2633B88E14001F95ULL, 0x7BD757E89E1F5ADDULL, 0x6E5845DD67E24D5CULL, 
            0xF006A9BE0A3569A9ULL, 0x7355A514653741B0ULL, 0xF5CCB07EB5CAE2D9ULL, 0x7D0CE13D15D8A6F0ULL, 
            0x11A5705B29E790CBULL, 0xFB5B71EB1F16AA58ULL, 0x208D5574934CD229ULL, 0x61F53B3DBCE66B9EULL, 
            0xA80AEBE9537B71C1ULL, 0xF38A9DC391F5F8ECULL, 0xB7BB6BFFAD38E572ULL, 0xA3C2ACCD14664517ULL
        },
        {
            0x37FA3573173D6B07ULL, 0x26ABB5532E68E285ULL, 0x0900154D5BB11FCAULL, 0x83D38966A153C16FULL, 
            0xEB4C24C9A63706A4ULL, 0x96FDF7F2461E97ABULL, 0x0C1EDB6132657C2EULL, 0x834797C79F94EBE4ULL, 
            0x962404953D2BF119ULL, 0x460717743BCB4E41ULL, 0xAFE6BAE940E1D0EDULL, 0x4710A4FB7CE44720ULL, 
            0x55D67341DFC8FA31ULL, 0xB52F901B253CA113ULL, 0x8019771A27D40634ULL, 0xBC74C126A8A2830DULL, 
            0xCF928A500BA597C9ULL, 0x8201ACFEB9F64C64ULL, 0x3DD3FF149C315884ULL, 0x46F7980C1388CD41ULL, 
            0xCEC1F78C055A7969ULL, 0x28451AA77CB1645AULL, 0xE9A6890581B1016DULL, 0xE4EE6B388733EB72ULL, 
            0x38A90CFA32776CB6ULL, 0x89792F6A2D773EA2ULL, 0xA5EFFF5BE53A2C81ULL, 0xEF496D09B810937AULL, 
            0x5AC4527C6A17772BULL, 0xA001AFFB97AE56DEULL, 0x56872AC71D9A8FF8ULL, 0x67CB5F77AA6DBB44ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseEConstants = {
    0xD4AD6F6BC11EC25CULL,
    0x1C5E4BC37CE3C27DULL,
    0xE9AA75F2AB453A6AULL,
    0xD4AD6F6BC11EC25CULL,
    0x1C5E4BC37CE3C27DULL,
    0xE9AA75F2AB453A6AULL,
    0xCB4199A2C5F8054DULL,
    0x37EEC920F786CC3FULL,
    0x61,
    0xDA,
    0x71,
    0x4A,
    0x1C,
    0x39,
    0x58,
    0x19
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseFSalts = {
    {
        {
            0xB6A192C867F26BD0ULL, 0x775E19B03836675DULL, 0x89E27A349ED608A2ULL, 0x9E5CB3BA07687D7AULL, 
            0x665333E56A4CF165ULL, 0x63E04674B3A8BA6DULL, 0xE96160DAC1244DF2ULL, 0x29621D3042841FBDULL, 
            0xBEAE704F681C9A86ULL, 0x9C6C847DCAFE6253ULL, 0x04535D09A97C908EULL, 0x5D08B20D99C75700ULL, 
            0x2EC878CF0899EAF4ULL, 0x9E1E78523C962D37ULL, 0x599ECCE085DEF3D3ULL, 0x429EF59A997F0FB7ULL, 
            0x49207BAFC02BA8AEULL, 0xECF89EAE7444A6D0ULL, 0x652A4F7FFF8640B3ULL, 0x4EC95E6DD5ED068AULL, 
            0x564FE66BF18AC0AEULL, 0x57194388558A21F1ULL, 0x0202E54AD26938E8ULL, 0x6486F75A9B8A790DULL, 
            0xE55C0163DFF03212ULL, 0xB8F3A969BF8FF382ULL, 0x2320E7C01E9F7E91ULL, 0xF42F2DBE6A8BC1CCULL, 
            0x6EF4E0BC7176DEE5ULL, 0xB914453A307ED444ULL, 0xF7C9B31E93DBC710ULL, 0xB434D919A3EE1A09ULL
        },
        {
            0xEA908D3A807782EBULL, 0x53D23C98266B29ADULL, 0x3C1A556D3DBEF795ULL, 0x0F156A66ABB176ACULL, 
            0xDC3A3A1FE145018CULL, 0x74754BAB117893B1ULL, 0x29FB4BF51EE71418ULL, 0x36ABE46662464502ULL, 
            0xA7ED5CBE8EF9D000ULL, 0xA90155BAC9F9AD51ULL, 0x8604D0BAE1093CBFULL, 0xFF6845BFC533C588ULL, 
            0xD590690F8CCEC131ULL, 0xB16D0736A5EBFACCULL, 0xAFACD9998472F691ULL, 0x4EA06290F5E43BD5ULL, 
            0x9820CDCA359E8569ULL, 0xB59E6E2CECC27C1DULL, 0xEC6F214744D66621ULL, 0x85498DCE1A2A41B7ULL, 
            0xF3BD70AA0BDD43DEULL, 0x8AE0A30372661426ULL, 0x3F97C05CA02FD3E4ULL, 0x1B1F9E75F3185994ULL, 
            0x5E71A1757B9E9D85ULL, 0x60B724DAE84CC674ULL, 0x25895EECDF9F9169ULL, 0x8D46F4ACB57BACB1ULL, 
            0x236C1C3D74610235ULL, 0xB6290ACEAD141D37ULL, 0xA820BB1800F8D374ULL, 0xC2AB92D0DD6B7A01ULL
        },
        {
            0xBE3B7CCD0217B26CULL, 0x20C0DBD42493D56BULL, 0xC57FB482F8E09F16ULL, 0x19C43125A7DA4D23ULL, 
            0xD0DC337ECD763886ULL, 0x80903F49A4D7BB56ULL, 0x09FFC09D8281F673ULL, 0x7AD66BE6612A85FEULL, 
            0x359E0185389C0F05ULL, 0xE4B50372C0F7FE11ULL, 0x9018F12EDEBE83E1ULL, 0xEA64DB770F0260F4ULL, 
            0xA633D6D4D724E8D6ULL, 0x6D83DF32B8C4D936ULL, 0xF9407E591D1A30F8ULL, 0xFC21C6C2477193FAULL, 
            0x03B3DDED64DC06C4ULL, 0xAA3EF69147B10DDCULL, 0xF2DD44D7B78312AEULL, 0xA7D4D3713505033AULL, 
            0x79165D0E02D30D74ULL, 0xBCA3BF4DF303FA4BULL, 0x3B1693BD7141A953ULL, 0xF359C687E0365551ULL, 
            0xDBF7E9428A3A5D01ULL, 0x88D99CEB2352905BULL, 0x049115BA01870300ULL, 0x684F0C126D660984ULL, 
            0x031B699E5C2D3E4BULL, 0x6C87F850360AF138ULL, 0xD5E32344E420DF6DULL, 0x3F359BCB47F82C84ULL
        },
        {
            0xA3C8DBB1D44A4E4CULL, 0x8E08AFEF3B72FECFULL, 0xDA70E3C0A7367555ULL, 0x831A527CCA9C9DFDULL, 
            0x66117183791AB176ULL, 0xB21473E58B32E9B4ULL, 0xE32FBFDA9D743F8FULL, 0x082AD58BA222AE7AULL, 
            0x720100661C87AAD0ULL, 0xBA3C2B54F6642632ULL, 0x1AE39D7709F3E6BCULL, 0x20DDB578A570E4F7ULL, 
            0x4E48B54557A200C3ULL, 0x3B415340230A7154ULL, 0x115138F9C13AB30AULL, 0x827B1BAB2CCABD7BULL, 
            0x7BCA8505042CABDEULL, 0xC05F459F54131B32ULL, 0x9C6E54A32A4F0D34ULL, 0xA878038B5861D1CDULL, 
            0x9771AD2F47754FE3ULL, 0x891B3950775DB6E4ULL, 0xFF192F7D15C5A9DCULL, 0x67D3E2188B295A85ULL, 
            0xF940D50DABF3CA24ULL, 0x545B90DC7D2699C5ULL, 0xC1B95E08DE14AF9BULL, 0xAD4830C635C6AC0DULL, 
            0x02C224CD9E670EC8ULL, 0x9768FA1E01CF69D0ULL, 0x3AEDC4D385A6D859ULL, 0xD5F6467BDFAF7870ULL
        },
        {
            0xAE3B8816841E1769ULL, 0x174ECC2BCBB51A5AULL, 0xC16539275DF8B25BULL, 0xA0B4138CAC6C4930ULL, 
            0x6FE1981DD7D373F3ULL, 0x585E12607DA4409CULL, 0xBFC93811E1D71872ULL, 0x9AF70AC01640BD3BULL, 
            0x0AD8BF2E2F619B67ULL, 0xF9E16BED113F7E2EULL, 0xF0B25E28EC08AED1ULL, 0x6FE336E2C200F78CULL, 
            0xCDE4AE724A55F1C1ULL, 0x0E7A5CC61B2F4452ULL, 0x235FEC7E198F8213ULL, 0x23F1C19A87DF8B0DULL, 
            0xF6BDF68B04CDCC37ULL, 0x7A80896E9A83E9FEULL, 0xC7559A7BBF006166ULL, 0xA05621BE3553AF2BULL, 
            0xFE93DF73ECF2231AULL, 0x503CA8B00EBCC0F7ULL, 0x37317A3824ECCADFULL, 0x2D6AAF9BFA07D851ULL, 
            0xDA7FC8712B97E168ULL, 0x1C6A6E73E0FD63AFULL, 0x6D654470BB1919F0ULL, 0xFCBFE204AA5E1778ULL, 
            0xD15C65E154111529ULL, 0x41CC1469F8355D2EULL, 0x4763D3B7B9B4B2C0ULL, 0x7860558484943034ULL
        },
        {
            0x308BF993E8DBA042ULL, 0x15EA86895EC2760DULL, 0xEC4C49AB333EC2E9ULL, 0x117CAEF18C87BA33ULL, 
            0xE573E5E0EA7D9B48ULL, 0xC6A177E216E53135ULL, 0xC83E8F4C3DC27B6CULL, 0x7B8219BBACB664DEULL, 
            0xD3643D2984486805ULL, 0x8B4199D76DB2A902ULL, 0xBAC1F380CD90CA60ULL, 0xC02473A3AE270F31ULL, 
            0x2BEABB6EDBAE6ACFULL, 0x89BEDFDD8FBF70BBULL, 0x696A614D38514D0DULL, 0xED70DE875DE2E5F1ULL, 
            0xC470F3C1BAB559F4ULL, 0x897FA77B8CC3FD4BULL, 0x954CBAAC965CBC85ULL, 0x1CBF26F1914CE96EULL, 
            0xF7AA7656A643D102ULL, 0x34B016CDFA82EC40ULL, 0xDC9ADCFB2982A1B8ULL, 0xE71A012C36196A26ULL, 
            0x3C92C9144584BF33ULL, 0x5A08F21CEFCE6429ULL, 0x15B3105131110FACULL, 0x4A77B8320DC973AFULL, 
            0x30F60100543DF959ULL, 0x321F28064881A6C9ULL, 0x0059F3ACB6BADA07ULL, 0x273F97F64D5528E9ULL
        }
    },
    {
        {
            0xD9169830EBA42826ULL, 0x764FAF206EECF78FULL, 0x9B3F856B145CA61DULL, 0x4FC1D26945991723ULL, 
            0xE67ACAD9E34CA274ULL, 0xD26F5CE611EEA36BULL, 0xE26A50B5890CF5F3ULL, 0x034913B8288D025EULL, 
            0x855BDCDFC9C36413ULL, 0xFDA662D74E2099BCULL, 0x2F5632B6A8572F0EULL, 0xF4AE87D0B1B51797ULL, 
            0xC8D1D67E715FE480ULL, 0xE31121622442817BULL, 0xC9901FC785B21645ULL, 0x30CD8453A5E25CDEULL, 
            0x78623D18D40EBBF3ULL, 0x20999B24D8D50CFDULL, 0xBCC03C33417C758EULL, 0x7666DBA7EB814A90ULL, 
            0xDACAE74DFE085902ULL, 0x6F5DBF27D09E6537ULL, 0xBA53D6EADE233518ULL, 0xF8F5139178CDA227ULL, 
            0xF5D5097C4E0BCDD8ULL, 0x545D5BC57A1AFB22ULL, 0xE29B4CD05EF3207AULL, 0x1251C488C5C20E26ULL, 
            0x5097594B1981A424ULL, 0x52D8BF02871EF6BFULL, 0x70AF640DE6D5EDEFULL, 0x5F46E824A0FB3D1DULL
        },
        {
            0x73DBA450052CB47AULL, 0x5C126667694B52D0ULL, 0xE207D3DE450A2431ULL, 0x99601B36F59DCF46ULL, 
            0x76B04D9F3DFDE41FULL, 0x41E4A10AA8E1DCBCULL, 0x91A32B5F8555284EULL, 0xE619698C19218F17ULL, 
            0x3430209AA3463BFAULL, 0xC71504A063C7E748ULL, 0xA3FE74F2F7DAB9D5ULL, 0xBCEF5212437473DEULL, 
            0x1EDFB8B99A77BE11ULL, 0x5EE3544A5D59EDC5ULL, 0xA77480438516119BULL, 0xEAAEFBE24E4AC857ULL, 
            0x71F01AC83685391AULL, 0x41BF1F81971CCDF2ULL, 0x3766F8A54CA5F732ULL, 0x74DD4C86D22E8230ULL, 
            0xB8C1D3E5790ED61CULL, 0xE9E06109668D78C7ULL, 0xD3365A09E266EC45ULL, 0x13EE279436123A0AULL, 
            0xAF651504AA95BC58ULL, 0x9EB2FD4BFDE5BC37ULL, 0x35853373F532135BULL, 0xE1840C328B984011ULL, 
            0x6DD5DC7019921F5DULL, 0x9E0BA4F79A1A9F65ULL, 0x22B891927C2A66EDULL, 0x263059D14BAA2B86ULL
        },
        {
            0x4C4B1637E9F4DAA4ULL, 0xCB729206F4108B34ULL, 0xC44B016A5B3FD15FULL, 0x53E0A1131CADF1A7ULL, 
            0xFB3A4AE45792DBE8ULL, 0xE15C3F055085FEDFULL, 0xBF8B4099BD80A50AULL, 0xE3540BFB54B2B114ULL, 
            0xA25F81DEE2DC0EB2ULL, 0x164BE8CB70E06B2FULL, 0x80E3BDF14ED3461AULL, 0x32A12DA1C1746E3BULL, 
            0x73B7CD2DD49004B7ULL, 0x315184E8C70D033BULL, 0x6BFF75479793D8ACULL, 0x898FA4BACE5BD5C5ULL, 
            0xAFC81A8DB85E808CULL, 0x537A83D71BC26797ULL, 0xE4FC985E7805F24BULL, 0x11F3FA4EA401C8CBULL, 
            0x0EAE4A46A85B0C5EULL, 0x72A722C2886D6778ULL, 0x11A4924D5E69C6FAULL, 0x8372B63ECF24853FULL, 
            0x8AB81A4886E75AE6ULL, 0xC3D0E59525D967BAULL, 0x3D76CF642AB3C67FULL, 0x363607DDEA5DD60CULL, 
            0x0A6E252AA9F386D1ULL, 0x626E66B94C88CB4FULL, 0xCB31E7D29702F1B8ULL, 0x22ED811E3591CFE5ULL
        },
        {
            0x4CE117C1BC0C537CULL, 0x13CAFF86A7B21350ULL, 0xE8192AABE0E6FDCAULL, 0x580A575633ECD588ULL, 
            0x1C211A5491B3223CULL, 0xAC8F970D4DB70B76ULL, 0x5D33B4256CFFAE0EULL, 0x3CE2720AB04F48E4ULL, 
            0xD9E88DC83E853AE0ULL, 0xC9BBF905B8306EE3ULL, 0x11D3ACF920D1C99EULL, 0x26A14FD0F4128200ULL, 
            0x23BE82F327F2B263ULL, 0x6BD01C26E34AA6EFULL, 0xF1A7EB662ADE4A74ULL, 0x6C7C7337992B4321ULL, 
            0xA33C401B1DAD86A2ULL, 0xCE435E910A5BCEFAULL, 0x09600308AF65975FULL, 0x78EBE2CA7821A0EFULL, 
            0x7D39F4D1BBEEE569ULL, 0x607388232A748A72ULL, 0x411BA7617F1CD8D7ULL, 0x59F6214C80B3AEB5ULL, 
            0x1C77D9FA40101111ULL, 0x6D0A32D79F289C5BULL, 0xFB2CED20B1405FD2ULL, 0x74EA4B2DDB607DFAULL, 
            0x89809FD3188485A7ULL, 0xC1C345667A26D4CAULL, 0x64F1E7D1E5BE502EULL, 0xB536C03CBB181AFDULL
        },
        {
            0x3FB5B7B8A540D681ULL, 0xCF0914FB73CB5639ULL, 0x3DE62147C8CE4CDAULL, 0xB5965EBA92827700ULL, 
            0x96F2FC3026FD5443ULL, 0xDC8EFFE04E4CD49CULL, 0x813E0CDDE6341088ULL, 0x9FBC9821E91BC209ULL, 
            0x57FFBFFF602DF8CEULL, 0x9B6814641209681CULL, 0x4FD867445169C628ULL, 0x3E2B1D41B76D1B99ULL, 
            0x2F186179D149BD1EULL, 0xCEFD54AA375FF764ULL, 0xEDCF26F08703F758ULL, 0x415A6051527861E7ULL, 
            0x9106C4802D4AB78FULL, 0x5E525FF9D7E5F2A3ULL, 0x933C14D2FDF8A17CULL, 0x6C264CDC695630EDULL, 
            0xB7EA927BF31DB50FULL, 0x5D6B44BFFC8661B3ULL, 0xC416DA56B5C96B4FULL, 0xADBD8C48119FE1ECULL, 
            0x320CF736CFD9273EULL, 0x39B9B0217EEB2C22ULL, 0xC46669A230E291C7ULL, 0x4D0BE84A5C366DB1ULL, 
            0xCB8D9A80F0EA601AULL, 0x97871F3C7D99DFF6ULL, 0x44B605C54599B069ULL, 0x9B7135189C2152B7ULL
        },
        {
            0x1E645060472CC57AULL, 0x73EE44D05A9D0F59ULL, 0xB66DC709027F24D5ULL, 0x40C5DE9FC6F8F05EULL, 
            0x95716E4229CC8E0DULL, 0x31444B585B1D2B56ULL, 0xEC26004BFC7A1D7CULL, 0x84E2A615A7FEB3D0ULL, 
            0xF8DF3608B3AA03FBULL, 0xC2ABCD1A6E8BC405ULL, 0x5E1D989A13DE0A4AULL, 0x4AB269D2BD2345FEULL, 
            0xDC1F018AE7E1A39CULL, 0x2C71868046C2C4D2ULL, 0xDA21804B75C20B25ULL, 0x1866CC908C151761ULL, 
            0x776726C23228D207ULL, 0x52CCDCEA5939080CULL, 0xCBE1939E2E37B762ULL, 0xA3CB95E8C257336AULL, 
            0x1A954CB39F498E07ULL, 0xB6C41B254A7F609EULL, 0xEB02F6B23F398BFEULL, 0x095278093082CFFAULL, 
            0xEB40C9B0582569DAULL, 0xCD5BA9783ADD88F9ULL, 0x8B5EEAF965CB350EULL, 0x0A602D45C96549CDULL, 
            0x93E55792447A28FCULL, 0x94F6DA64ABBB8626ULL, 0x4558E2007AE8EC6BULL, 0x63345753E8496322ULL
        }
    },
    {
        {
            0x1E23007ADD4A9D5BULL, 0x6BC71C6741EAD5D7ULL, 0x0E4E75F8561673C0ULL, 0xE4D620658D9AB8F5ULL, 
            0xF33BD733940C0ABBULL, 0x3CECE43828DFBF53ULL, 0x7DFCE8BF800C24E4ULL, 0xB8A196D59402E084ULL, 
            0x53AD63B8DC078FD3ULL, 0xD5302E4A40D16BE4ULL, 0xBFA20D6487B0A925ULL, 0x0AEB31187A22D206ULL, 
            0x4D5221A88248DE21ULL, 0xD48865DDAB445B52ULL, 0xA0B0C09925BC0EDCULL, 0x27647FAC6DC3EB8AULL, 
            0xFD45DE4F6A722F86ULL, 0xEA4B3C48CF0552ADULL, 0x309A7B3965A94D77ULL, 0x53468E4A1E71844AULL, 
            0x92EEFA122FA49ABFULL, 0x678D99F91D28D34CULL, 0x86E5D7CF1FD23B24ULL, 0x9E15C8B773CF5286ULL, 
            0x21DFB6850FB28A6AULL, 0xA5CAFD314814A5D0ULL, 0x9CC9798F751F5C96ULL, 0x2829327EF74CA518ULL, 
            0xF9C8267F805E7B75ULL, 0x84D83FCEC2DF115DULL, 0x3D1CF79DA12942D1ULL, 0x69035679F7F5DC73ULL
        },
        {
            0x1EF87D77367A0FBFULL, 0x94C44D00C1653501ULL, 0x11CEDA123E11B050ULL, 0xD9BC1BA478657C3EULL, 
            0xC00281226DD90AE1ULL, 0xFA4A8C6D2E929D94ULL, 0xE4D7FB2A9AB653EEULL, 0x40DBB0E7F04B5E62ULL, 
            0x762ED7CE71A086E9ULL, 0xE62C49C78C456DB1ULL, 0xF000B3DCE6099D03ULL, 0x7830C2855A96E581ULL, 
            0x36A59767BFB0035AULL, 0xA68D87FF6A283C90ULL, 0x40ADD76A6D50BBA5ULL, 0x290A68B4EA4E1E37ULL, 
            0xBAF9530C43ACF34CULL, 0x928E1817C01681BAULL, 0xDF60D5205FF41611ULL, 0x6477D12F96C36918ULL, 
            0xF0E416C19FDB2DE5ULL, 0x165BCA4C3E3AF2F4ULL, 0xE11A8EC68EF6D0F1ULL, 0xC7CFE234F754B48AULL, 
            0x68A5CC56B9836799ULL, 0x6E46FCA676951203ULL, 0x9ED53ECAD1E0A386ULL, 0x3432672C6D811EB3ULL, 
            0x14682F465A73E46FULL, 0x548D4EA6E21DB2ADULL, 0xB916558A720832CBULL, 0xD0AA95C4970A5C87ULL
        },
        {
            0x7189BF6600DFCEFAULL, 0xA3CC995888E3C572ULL, 0x53FBC1D52E7C5503ULL, 0x4448F1A662971259ULL, 
            0x90C294BF37B5C0B9ULL, 0xD216DB8A17B8B7DFULL, 0x80A28110F3F6881CULL, 0xD3DF2AD08A0DFD52ULL, 
            0xCE91BFEEAC93A8A8ULL, 0x8211CC82274B490DULL, 0x3BB57A91C1A5DF52ULL, 0x292742BC7819BBDEULL, 
            0x08CC5D89FEFF1D96ULL, 0x0B36457A44379FC4ULL, 0x32659B9A6F55BA6AULL, 0x95245BF3D7A99105ULL, 
            0x9B5D6A8F03A038DCULL, 0xD49EB1773A146824ULL, 0x4FD30630610C53A0ULL, 0x6D613174FF0317ECULL, 
            0x224FAC6A4F87B6F2ULL, 0x5988D001CF7B47E5ULL, 0x8BAA186E324A04E1ULL, 0x79062CD90F55905BULL, 
            0x1EFF47DB89363A1AULL, 0x1241877C46DE04BEULL, 0x6E2D932D1CDBE8C3ULL, 0xA8A79F55D366425CULL, 
            0xD7CD0A2B6EC463CCULL, 0x4D2D1D4B86512017ULL, 0x05DF41F917635844ULL, 0xB7DC733FBFD1A3E4ULL
        },
        {
            0xF0329F6A1DAB5582ULL, 0xC72AC4782FA29CB4ULL, 0x44F11C24BAB6E0F4ULL, 0x2714217E83C82833ULL, 
            0x29673A13FF9A4B11ULL, 0x256F9279B798A989ULL, 0x1F599DF25F4A2A86ULL, 0xBD63DB6E256733FDULL, 
            0xB2D34E560F8BB29BULL, 0xA4B4F21FE1E4CF06ULL, 0xD2D5FB4C14286661ULL, 0xB2A8251F975ADA2FULL, 
            0x95AB435A3FF21844ULL, 0xFB63634253F344ECULL, 0x95D0DBEC6580B31CULL, 0x2CCCCEF5E6563AB7ULL, 
            0x4083C7A7D158B16CULL, 0xCE8C5D956EA0B23FULL, 0xACAFCBB115729575ULL, 0x532336C44AFCAF9CULL, 
            0x187C87B39CEEFD64ULL, 0x14B5E4DA92E95C58ULL, 0xC4B80109536AF352ULL, 0xCD2CC4A1EA9E3E91ULL, 
            0x37EE791F9CC3D90BULL, 0xAA12DD2E3F40E0AFULL, 0x676A622E80759298ULL, 0x0DC92972C6D499D6ULL, 
            0x1A9ED8BC7638A64CULL, 0x808E720317E7FD72ULL, 0xFC989E0A42994600ULL, 0x4AD625F2780A179FULL
        },
        {
            0x7CB0B115424CAA26ULL, 0x4C5622A58CA85B0DULL, 0xED82391E2E82D6A9ULL, 0x7D7A65BE1AED298FULL, 
            0x311B2FF426E77775ULL, 0x16F4791C035B3DAEULL, 0xA5D2EFEAC03526D1ULL, 0x22D4D948F5AD1769ULL, 
            0xC80B2A1932FE930FULL, 0x5DC22CC2B0059605ULL, 0x693BE9CFEEAF2EF7ULL, 0x999AD6C0047955CBULL, 
            0xCD6495781A4FCD8AULL, 0xC315DB9AACE305F3ULL, 0x7A6F99D2581EF44BULL, 0x97215C6944A0715DULL, 
            0x194BFDF14BAE0DD3ULL, 0x71086553C962F987ULL, 0xB8D67E0D6849E33EULL, 0xAFCB81C12BF5D9D7ULL, 
            0xA414EF685EEF8260ULL, 0xB3EA8D18E4CA1017ULL, 0x116854282BE5D2DDULL, 0x84B8603E875EE006ULL, 
            0xB498FD6424AA9A9FULL, 0x90D1003D29DB4665ULL, 0xD3BD19C8EE463C5DULL, 0x5A63A865D2282FEBULL, 
            0x4DD7C5B9A7719FAAULL, 0xCFB4EBBF568EF845ULL, 0x941931676CD0D0C2ULL, 0x27A0708252F9EC45ULL
        },
        {
            0x94F6AC82EF14ED2DULL, 0xAEFB4B77A15B0219ULL, 0x3D2AB56ABD95DD48ULL, 0x90D7B463C197112FULL, 
            0xB26BD77B2A36C923ULL, 0x788503A82FB7698FULL, 0x4C9456567C32BC1BULL, 0x5C02FE4AE7D24C0EULL, 
            0x8B535D5FDE30FAD9ULL, 0x9768B9396AF2C9CCULL, 0xCDF31A3542E43092ULL, 0xDBAFC1D20407096DULL, 
            0x44537FAC540C3781ULL, 0x8DCE3C2E7B7530BAULL, 0x666F26C7A18090C1ULL, 0x34AE343C91841202ULL, 
            0xFE58BC0ADCF90B0BULL, 0xAAC46EACE7277EA8ULL, 0xEB6471CE01872ADAULL, 0xB3B729CEB56A13F4ULL, 
            0xE6415DEAC866AD14ULL, 0x8BDB57568039B1D7ULL, 0xF9E186C6C963EFFBULL, 0x6D58BF6BF1E52CEBULL, 
            0x7C50739161D9DAF9ULL, 0xD6D6065CED712DF4ULL, 0xB71E81AEA6C1BF59ULL, 0x2EF06B85959CEB1CULL, 
            0x0C66626DE49EE318ULL, 0x9CE8C5EAC0615C52ULL, 0xB8579507D8FECA29ULL, 0xCD596F9648CB9E88ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseFConstants = {
    0x27F8BF454055A162ULL,
    0x40AAE8249A482BAFULL,
    0x59064CEC2D5C653FULL,
    0x27F8BF454055A162ULL,
    0x40AAE8249A482BAFULL,
    0x59064CEC2D5C653FULL,
    0xC6D471CE73DF4B95ULL,
    0xF8B81903788DE3C2ULL,
    0x5B,
    0xC6,
    0xDE,
    0x16,
    0xF5,
    0x32,
    0x3B,
    0x2D
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseGSalts = {
    {
        {
            0x82F65C0C3C186963ULL, 0x33293D7ADA69CE7AULL, 0x0EFF20EE2D0E8624ULL, 0xB172FDFFC6DF2A5CULL, 
            0x47248F21AA2188A9ULL, 0x5709DE276BC6A504ULL, 0xA2B648B74B15A457ULL, 0x6456017546AF7358ULL, 
            0x004A8BA30BD916F4ULL, 0xFADD5638700141E7ULL, 0x42A316958DCE950EULL, 0xB485D185691A2A74ULL, 
            0x372DC927D6732319ULL, 0x049921CC9D77542BULL, 0x9FA645568E0DA4E9ULL, 0x5CBCA930D0F0741CULL, 
            0xDC520B15845AE12DULL, 0xA0967AD3001D3994ULL, 0x7394CAFE28DAEC6EULL, 0x9A02803CC091EE73ULL, 
            0x99C85EA0990F7A2FULL, 0x5DE8C92184CE3B72ULL, 0x21060EA737D1F21FULL, 0xCD3FB798EFAE7019ULL, 
            0xC9219E3C583A7949ULL, 0x5A8DD0A2C157FC49ULL, 0xF4D214EF7D298D99ULL, 0x6B552EF8B2D5616CULL, 
            0xEBB66F42FEAD018AULL, 0x3533729A940132A5ULL, 0x82BE8AA0BB4D2967ULL, 0xFA54ADC9B489A813ULL
        },
        {
            0x1861CF0B161F3137ULL, 0x2C04BF95E24D6B5EULL, 0xA954D3A34F0E062CULL, 0xA35884A4E5A8AB8AULL, 
            0xBD7779FFC9D22C85ULL, 0xF84F900A7A790C0AULL, 0x1938FCB02C7CE017ULL, 0xF60D096C4F79A048ULL, 
            0x47987D3E25DEEA7AULL, 0x49D63EA9441F58F6ULL, 0x488A62FBDDEDF81EULL, 0x861753D49D41C3DBULL, 
            0x60165D9CE19FE9A0ULL, 0x3AD0C5AF5A7C28B5ULL, 0xDB22497770A69FCAULL, 0xA5613827445CFD27ULL, 
            0xF26B72FCE34D2534ULL, 0xB6EA958D45D92472ULL, 0x8F5046FB32A3A142ULL, 0xB4504EC420C2D586ULL, 
            0xF74C482168854747ULL, 0xD9A9AC3E190991B4ULL, 0xE6197B28E1E23589ULL, 0xFEA04A46FFAAE009ULL, 
            0x041B58429FBC3F01ULL, 0xF2E19A611BBA74D7ULL, 0x5590DDECEB542461ULL, 0xF9AB9D848F1CEAF8ULL, 
            0xE5779BED52F9A88AULL, 0x8CC53DDA5C9D8E0DULL, 0x5C7699FF2E9DEF20ULL, 0x81F4F19608F95C4FULL
        },
        {
            0x0C1F68C6207F1C70ULL, 0x683948324E68F667ULL, 0x98F2C83EF39395C1ULL, 0xBAE20D5BE21945DAULL, 
            0xBF45A859AFB11F05ULL, 0x8D16626A3907CD53ULL, 0x8BBFDC6E9BFAECC6ULL, 0x0A83506AB726CE8AULL, 
            0x7BC101E3F7928335ULL, 0xDD17D2EC4A979BD0ULL, 0xCCE39945AA709E8EULL, 0x3349E6D106211707ULL, 
            0xFF42F57771582A71ULL, 0x43AF81E346900A76ULL, 0xA0749AE50C6D4B23ULL, 0x184F94CFDFCBB8BCULL, 
            0x513D4FD83DBC280BULL, 0xA39073B4A09EF59FULL, 0x7E63273DA323A0D7ULL, 0x9A2504E896518FF2ULL, 
            0x3521F6DEFAEF541AULL, 0x71C6CDFEC8A046A7ULL, 0x2F5DF14CFF260EADULL, 0x8EF932C3D014BB8CULL, 
            0x84A3BFB12BA81BC9ULL, 0x213D750118349FA7ULL, 0x2C9248798193DBB0ULL, 0xB6AEE976E0532F56ULL, 
            0x07E68A8E3994B473ULL, 0x2BBEE6A826C52A35ULL, 0xEA355554A432117AULL, 0x9E6C48A49D0E1F1EULL
        },
        {
            0xD263E048A11E9567ULL, 0xADFE33E2A7F51CEDULL, 0xB65A559FCFB79919ULL, 0xD5938B974A114CCBULL, 
            0x1E4F186C8E7BBA03ULL, 0x8A96457ADA688E00ULL, 0x6E8FC09AAF03096FULL, 0x0D7BACBB91C99408ULL, 
            0x67FB610628B6BB6AULL, 0x9601F32077E1A390ULL, 0x3A97CB29AEC22B34ULL, 0x723BF2303F7F1BEFULL, 
            0xB349CA7517F1F036ULL, 0x8490F5AA500035BAULL, 0xFFF666DDADD6CF1AULL, 0x5EFBB9E75DCD8C3CULL, 
            0x9A5F067E7F6069F4ULL, 0x30163AA727853A95ULL, 0x0B234E622AAA6A8AULL, 0x2C64B24CC5289203ULL, 
            0xE21CC7D82E377F18ULL, 0x57A536362886A012ULL, 0xEAB91BB309A0ADB6ULL, 0x705720173330DD62ULL, 
            0x0CF2BFE962CA5528ULL, 0xF8ACC88744817E22ULL, 0x68789EF0A1DEFC6FULL, 0xC2B2AB3E5969EE6AULL, 
            0x0A88A430C85D4658ULL, 0xF23AEC048B7D4E8AULL, 0x54AABD497ECA7358ULL, 0xECBAEA04D64F5F5AULL
        },
        {
            0x5C94A45BAB02F4E0ULL, 0x66B5808220D85F0FULL, 0xDA5E682ECDD03905ULL, 0xAD1B9A9FC54B2D15ULL, 
            0xA17DB8F0B6F34AF0ULL, 0x7D4BBDC623A100F5ULL, 0xFC8FAF2C051DFCCEULL, 0xFCF3F7C8238CB05BULL, 
            0x222D8BA57A61BA58ULL, 0x47C0751E1BE5DCFDULL, 0x51490A90EBD11353ULL, 0x1616AF1001BF38B7ULL, 
            0xBF1AC0C848B587F2ULL, 0xCCB7F40ECB02917AULL, 0xDF4595FFB1B39482ULL, 0x8600349CBC8119D7ULL, 
            0x0EF189D45982FD27ULL, 0x9AF98FFAC86DB66FULL, 0xF239BB828A895FC4ULL, 0xCB7935B1DF6B1AACULL, 
            0xDBB46AF9AF5041D2ULL, 0xE6AB8DDD14C7D5DBULL, 0x796025F60B7E93C4ULL, 0xFB52DC1149120C07ULL, 
            0xE34A4CEED3AFF661ULL, 0xFE51CCA9879EF90BULL, 0xBF73D67A991173FFULL, 0x1B7E940CC6406FFBULL, 
            0xC83EE253B7B4CA82ULL, 0xEF275FF42A6FE39FULL, 0xB8B93814E8078F2CULL, 0xF8D3053FF8B142E3ULL
        },
        {
            0x064764883252CAC3ULL, 0x1215E721ACE69DC8ULL, 0x68BE3525A201DB9BULL, 0x2431C9A3622B8FE7ULL, 
            0x06372BFF1210C205ULL, 0x511ADA906292946DULL, 0x4699D5F1DAC21081ULL, 0x7517E225463859DAULL, 
            0x896236FCC6E11C03ULL, 0x3C0CC434CE9FA834ULL, 0x1648B3C893948FE7ULL, 0xE4289E807626A87BULL, 
            0x2A64CE5786C98293ULL, 0x730F5BEB98E1BA2DULL, 0x75C5978F44B34DB0ULL, 0x5F8E48CD6B8E7203ULL, 
            0x281FC44FB3BDA44BULL, 0xD8A8C7B575333031ULL, 0x36B75DB70A5818BBULL, 0x14849E1214180562ULL, 
            0x49170FB9251E5BE8ULL, 0xE14258E7E3FCD33BULL, 0x9E01CAACC04B3C43ULL, 0x59A47974046520ADULL, 
            0xF00FF48A53580343ULL, 0xD296BA7C17AC8CF6ULL, 0x2C5DF7B487B13BF9ULL, 0x4F458D605C44E6B4ULL, 
            0xF1BBA9D0DA3DB78CULL, 0x4C834E2835103D67ULL, 0x2C243D82048BC808ULL, 0x5826677E66460767ULL
        }
    },
    {
        {
            0xB30E8430C1207B06ULL, 0x1909DD8CFE667A86ULL, 0x693D127DCCC61980ULL, 0xD83E47E257906855ULL, 
            0x89E8F997DCB61DC6ULL, 0x8CEF8D6851FD1FB0ULL, 0x0173AA13B1D3CBF9ULL, 0xD51CDA73BE20DED3ULL, 
            0x20CF2CA662493C48ULL, 0xB0D66FB173651D91ULL, 0xA46F90127C17A34AULL, 0xBF53886AEC425574ULL, 
            0x194816E49A6A9EA3ULL, 0x1846703297C816BDULL, 0x196CEA43C0E46D92ULL, 0xE05CB456B19258E2ULL, 
            0xE59DFF2361395E4FULL, 0xD304895B58CDE96DULL, 0x1A40DD314E347AFAULL, 0xF5E96201E8D2173DULL, 
            0xC8BD6E459F8AD50BULL, 0xE883C53EA330E40DULL, 0xBFD8ED2050CE83E9ULL, 0x4A7069F39EAE8F03ULL, 
            0xA75C5E8C9EFD15DDULL, 0xB6C4B3258B3F63C0ULL, 0xB65073D94869EB28ULL, 0x838626C87A802C38ULL, 
            0xB72A156BC6EB3B9BULL, 0xF2AA936FFE8659C5ULL, 0xAFE5877E58787CD3ULL, 0xE7063CEDA4668019ULL
        },
        {
            0x515A03F8019BCFC8ULL, 0x4C4545E734C51644ULL, 0xAFB033005892A915ULL, 0x2AC3124B8DC20DCAULL, 
            0x91ED09149FD4EFB4ULL, 0x2E0C920DF39C902EULL, 0x569436273B1DF948ULL, 0x847B21738607DECEULL, 
            0x4C376FEB1F3133C9ULL, 0x31411041A1DB8DAEULL, 0xBEB1AAE77F95DD7CULL, 0x69996D61936F9F97ULL, 
            0xB4FC1DFBA9A9ADB7ULL, 0xB272EA8F5374EDFAULL, 0x5BEF7212BE5800D5ULL, 0x736BEA736B5EF91EULL, 
            0xC840298193699B9FULL, 0x1B2A82514F738FECULL, 0x7BAF87C3B0A15DC5ULL, 0xB5B6621F99EB3104ULL, 
            0x15769E1419778C71ULL, 0xD54EEEA85D2395A2ULL, 0x9B51CAB96FAD0FF5ULL, 0x1AB64B6BF8DEC950ULL, 
            0x4F5F264D98544B7BULL, 0x3AEEAE3FCCF71339ULL, 0xBE2E3FC8FEA82A19ULL, 0xFF2C0807A70E8242ULL, 
            0x0449751FED0403DEULL, 0x175FAA070C83CC05ULL, 0xFEFD3B118E958A56ULL, 0xEAF4951094FD83E1ULL
        },
        {
            0x2D3AED87400C209CULL, 0x6503ECF1287D2784ULL, 0xB002720F7DBF98C4ULL, 0xD32325A36AD0560FULL, 
            0xFAAAD4A4E3797A8EULL, 0x58BAAF2CD89DA903ULL, 0xDA8A41D5375EA5F0ULL, 0x02EE487AE75BEAE5ULL, 
            0xBD727BBD2A14096BULL, 0x1F1231C08C8E7E67ULL, 0xFC3998A4E05A7A52ULL, 0x8BAB6081B628F22CULL, 
            0x476ACD4D7B8BF1A0ULL, 0x188752650A52C4BCULL, 0x74F967BDB5B45AC5ULL, 0xE3D81881A491471FULL, 
            0x73A3A5F6B9CE2EB2ULL, 0x40EAB1BECB00FC63ULL, 0x7DB9F6CA426DF88BULL, 0x5BA31E03A4943F50ULL, 
            0xBECC4E025E49D647ULL, 0x47887BEFCBA6246CULL, 0xDF0BD1E10209DFA2ULL, 0x18168C1E96BAADF3ULL, 
            0xB19BF0E96835A657ULL, 0x84C951421EAFDCC4ULL, 0x149B7D2438CCF280ULL, 0xF10B544BB683980EULL, 
            0xCC1A65782A5E4AA0ULL, 0x27DDEDE5724C4308ULL, 0x85AFD7839EA67691ULL, 0x7244E465FA4F2C8EULL
        },
        {
            0x67B345E8C5CD8FAAULL, 0x712BE3C1F133E0FBULL, 0xF4C75C361AB7F2A9ULL, 0xD593E3CA9FFE2BC8ULL, 
            0x1CE9A7D096B2D111ULL, 0x5522C2B721ACD071ULL, 0x6E810710EBF184CBULL, 0x77F3ABDE08EDA216ULL, 
            0xDE1E66FDBA18ACA5ULL, 0xDE175D3CC8338582ULL, 0x761683B00686EE45ULL, 0x1166C468E52DE029ULL, 
            0xA5017619A7C3A645ULL, 0xED7883FC9C32F024ULL, 0x9A967B1BABA05191ULL, 0x8D846BF798734401ULL, 
            0x59178033193B26EAULL, 0x1318686E12BF4B40ULL, 0x6BB90BFCAD0DBDC9ULL, 0x0EB0526661AA7231ULL, 
            0xFFFC68B71515ECA3ULL, 0x3D99A65E1BAB5A3AULL, 0x96E168783C8C206CULL, 0xEEA7AF4DC2B24A22ULL, 
            0x62992A4DA3FD9589ULL, 0x33FDCCBBB78DA711ULL, 0x52D5AF64D55B2853ULL, 0x7981FCC0F5EF67CAULL, 
            0xCC1EB3312B1C03BBULL, 0x53E0D6647A4A32B8ULL, 0xDD781C355D590642ULL, 0x055478A8E71F27FCULL
        },
        {
            0x64BC12620FD08A90ULL, 0xE05396EB14DD6C42ULL, 0x8F5B813049EBF242ULL, 0xF63ACF4C88D00DA5ULL, 
            0xF24B84202DED4C8BULL, 0x425546656B240314ULL, 0xDF4E59B7FB152A46ULL, 0x510CC47E04E05ED7ULL, 
            0x3BFE0251598ED929ULL, 0x1C348B1A47C13609ULL, 0x8194E127E42BCEDEULL, 0xA7750654D5088B22ULL, 
            0x04B2F8469B45ED84ULL, 0xEB5BB12DAC5AF21BULL, 0x8E2749196677A39AULL, 0x98F235A03102BCA7ULL, 
            0x9A745A5553721685ULL, 0xD5928C5D51AA3ADCULL, 0x69AE57EEC52A7130ULL, 0x595A02C05243F8E2ULL, 
            0xBABA7B7246657E71ULL, 0xFE050F3AEE05C0DCULL, 0xE5BDEDD7F49B5532ULL, 0x1286CCD7B5CBB644ULL, 
            0xDD6096C2D7E7424AULL, 0xE0E87B5AFA5F3995ULL, 0xE16CCF97820FFDC7ULL, 0x8D5970FBA6780434ULL, 
            0xB347AA4FDDE1E3F8ULL, 0xBA5C10F5D8CB1619ULL, 0xBB70CAF70759E024ULL, 0xB4042886EBD64AA6ULL
        },
        {
            0xC5492D95717B22E8ULL, 0xEB9E5DA00A492003ULL, 0xF7A70DAD02316861ULL, 0x51A7AAFBC2AB39C3ULL, 
            0x0E8BE7ECEE119D69ULL, 0xC51EC06015190868ULL, 0x23B6EDF087A774FCULL, 0x089FB90C43DA14D7ULL, 
            0xCA0F15BEFFF308A6ULL, 0xA766E91ED3C84A1FULL, 0x1B4CE9125A75E31EULL, 0x02F6010F5CAF1DE5ULL, 
            0x076C2E1E33AA0B54ULL, 0x23D4E8E29B5D761CULL, 0x69C3C6961C2B4B8BULL, 0xB533C61465CED245ULL, 
            0x019DFC3EB637608FULL, 0x079D02DAAA98EC59ULL, 0x6520B078AAB86F53ULL, 0x68D5F2860935BD62ULL, 
            0x5F44F7FD4CF4ABC7ULL, 0x4D451197CD6335F4ULL, 0x34E6AF9A9A1035C7ULL, 0x077B54C23F0A8ACBULL, 
            0xFE36501AEF505C7CULL, 0x3A2936D9C8FFA019ULL, 0x2C6E22738BC02F75ULL, 0xDDF65A91961AB7ECULL, 
            0x1DB67D822F07CD02ULL, 0x7F3E2D102F7A7514ULL, 0x54092F44C5450C90ULL, 0xDD763B3DBACA7FB7ULL
        }
    },
    {
        {
            0xBB1022F597CEE13EULL, 0x515DDB47B0A2D0D6ULL, 0xCDFDFB796ED4E544ULL, 0xCF9B5B7DA46A04EDULL, 
            0xC3A14E2BFBEE74BEULL, 0xEB41FEC2DA2429D5ULL, 0x42CD5A0F75D41103ULL, 0x08E01BF4826C5613ULL, 
            0x12AB8FEFC1A9900DULL, 0x08B7AD3E07E15412ULL, 0xB878E7412FDCB310ULL, 0xF80A08B3F371D456ULL, 
            0xC0583DF3DB0BAA12ULL, 0xD580D661B6B9903DULL, 0x0BB752786DC94AC8ULL, 0xF352348110D19264ULL, 
            0x5DA1DF127D1C4DB0ULL, 0xC33597802C807FC2ULL, 0xBA3E44FB1DC3C9F5ULL, 0x393F842AB16EA2F9ULL, 
            0xE82443A87D758228ULL, 0x3BE951B234BD4A02ULL, 0x23127C0134BE3D2BULL, 0x59A78F6AB755C9B7ULL, 
            0x534A8ACDDC4E16BEULL, 0xCFFE7754EC7E72FBULL, 0x53CCFAA0FE31EAADULL, 0x123F21E53B5E3BECULL, 
            0x14D7F5342E8B919EULL, 0x83328D84901B0963ULL, 0x1E6787E01C9A8EA2ULL, 0x1EBCB35E3C26C1DEULL
        },
        {
            0x36E6EA5B5892D362ULL, 0x78DFC7823E7BAA75ULL, 0xE138724CC9BE1B3AULL, 0x5A133A23E495024FULL, 
            0xA549243BF34921B1ULL, 0x1EBA083464CB7BA2ULL, 0x86AB3FD17DF4CD70ULL, 0x3BA33FA1A8B7A0D7ULL, 
            0x8EE376E24DED53D7ULL, 0x97FB661F00781BEDULL, 0x31D40D7AA72BCC79ULL, 0xF745C2E3A5F0D2E8ULL, 
            0x1D13396522BC8078ULL, 0x2EEE7D97F5D0F513ULL, 0x046D3BAF85D073FFULL, 0x51C61F23AB9BC2C1ULL, 
            0xF4EEF479334BB86EULL, 0x90C0EF9DA8CCF009ULL, 0xF984FE464535DE86ULL, 0xDE83938BC5283484ULL, 
            0x2ACADD97E47CCA53ULL, 0xF00B1FD23C2AC2C2ULL, 0xE323785E613D1215ULL, 0xC78057846B8CBB8BULL, 
            0x9191ADFE978199B0ULL, 0x52915199525A40D4ULL, 0x9436522FA2050F86ULL, 0xABCB22259D7A140BULL, 
            0x28168CB54A568E0DULL, 0xE34B6530F499F09DULL, 0x31F4785B3E50FE7FULL, 0x39F71163DD9D38AFULL
        },
        {
            0x7CAF93EBCB0DB847ULL, 0xD4B199E7D5526093ULL, 0x970D56004DC3B1D5ULL, 0xC4AA4F031B166595ULL, 
            0xE923437A7416C250ULL, 0xE21F6A289A46888AULL, 0xCA64848233E9525FULL, 0x35F641A866C0F1D0ULL, 
            0x5BE1D4979A669A47ULL, 0x3F77DA7CE94EA0F5ULL, 0xC69F18AEC43AAD03ULL, 0x616DFB36D9469AC5ULL, 
            0xFBFFC1CDF8A05E1DULL, 0xF64D6DBA1B922BDCULL, 0x7A9A02A2F45768ADULL, 0xAB0E6348B6BED802ULL, 
            0xFE0F495D2E4A78D1ULL, 0x0B40312D884199F0ULL, 0xA88F72C05C4C2D9EULL, 0x12BD713356DA3142ULL, 
            0xE13A7DE7BF0CFA15ULL, 0x1A8DFBAAD72CA72EULL, 0xAA3116FC70733668ULL, 0x2AB3AA8B403A651BULL, 
            0x4CB3FA45A6A48330ULL, 0x1241E9C0ECD4AAAAULL, 0xA51F53BE5D311C21ULL, 0x5CB8D9BB53D4429BULL, 
            0xF580E1B515627811ULL, 0x2639D8EECC395234ULL, 0xC64303EEC0CDBEC6ULL, 0x89F5BD0C0961699EULL
        },
        {
            0x91CF6D19AEC5B6C5ULL, 0x32AFAECF0EA85AB2ULL, 0xAF6D5F3236DA2441ULL, 0x4787AE6AB607D4F1ULL, 
            0xF4FC9818D84E0640ULL, 0x9C25AE6A7DFFC4A2ULL, 0x38F79BAE749F359DULL, 0x8B61BD8C0AB5BD8EULL, 
            0x71503121A052B58FULL, 0x314E1149B29DBCBFULL, 0xC6A808D8BB86C7E3ULL, 0x63918F745F66DF9CULL, 
            0xC8201A63E36E59FDULL, 0xD07F4B8EC15517ACULL, 0x5465666AD7694A43ULL, 0xDB2A838FAF6C37B6ULL, 
            0x21EE0A8DE6FB74DDULL, 0x6C89874400B70B82ULL, 0xD48D95B9525D30EEULL, 0xFBF0DEC1B17B23A7ULL, 
            0x664996BEA72C5F84ULL, 0xD70B0B06296F625EULL, 0x81FD4B51D2D9FEF6ULL, 0xED5690195CBF6E22ULL, 
            0xB33B8E5CAA7944BAULL, 0x9575ECF12F848B0AULL, 0xCA5C7B6A1A4AF532ULL, 0x51D5D30F3DEA4774ULL, 
            0x292D5D37632B903DULL, 0xA249115907D4F1ADULL, 0xA3FA4C380BFBC0EEULL, 0xB4A4CCF13BE9D403ULL
        },
        {
            0x31CCBE9E63E58431ULL, 0x420673DD7F1AB970ULL, 0x761C26D414C1DC30ULL, 0xD90E2A376F091CE3ULL, 
            0x41BA1C78D7FB7DD7ULL, 0x77487AA2A96A1E07ULL, 0x53AEA1E3825C565CULL, 0xDFC0B303DF05B032ULL, 
            0x7C8EA835D5906EB6ULL, 0x88CC59A7D3F8826BULL, 0x784685D8AFA6F9F1ULL, 0x34FFCFDC69DF6900ULL, 
            0x1103CDC6123D9384ULL, 0xFA384D9803CC55FFULL, 0xA0A9E023AD4E82AFULL, 0x804041B78E08E71FULL, 
            0x4F6A89DD1C3CE4A6ULL, 0xD2944838405C4B1DULL, 0xD3E1E0A8227A89B5ULL, 0xCF6F5B1DD33A4322ULL, 
            0xB069BBE0694AD37AULL, 0xBB53554DD5792AF9ULL, 0x1572351C5920071FULL, 0xF0B1CD29DBFD031EULL, 
            0x8C29B044049659C9ULL, 0x8E33A834822E0FAAULL, 0xDEE2AA01199D042CULL, 0x288789BB6D157018ULL, 
            0x07385C5DDB530488ULL, 0x38F1B9501394A9F5ULL, 0xA98A8F8C7F5D8EB6ULL, 0xC87B5AD7EA002AEEULL
        },
        {
            0x041F6574C62D54CDULL, 0x2A36BBDA153ED385ULL, 0x05D067086C0A1FC3ULL, 0x7F139633EC1600CAULL, 
            0x0E6B5430EBAECD02ULL, 0x3DAA428C2A2DD195ULL, 0xAE83FE70ECB6A3B4ULL, 0xD25AE879D83E8410ULL, 
            0x71AAC888EF5BE13DULL, 0x9CFE3B332866029AULL, 0xE3F8AF9FD991D3CCULL, 0x2174E5E1289113C6ULL, 
            0xA56C71E0FE9C9009ULL, 0x5C7AC5043AB88C8AULL, 0x65C554D27F875D43ULL, 0x3062F32A94F74419ULL, 
            0x0A1FB8BBFAA409F3ULL, 0x6F0342AA58563D8AULL, 0x39AEAD95FEE4AD32ULL, 0xBE026D7ED16001BCULL, 
            0x0FB93389C0A3B2AEULL, 0xCB1B576B3489F372ULL, 0x81EEE43873967ED5ULL, 0x5A34C781E7EC1233ULL, 
            0xDA15B618F724C8C4ULL, 0x3E7391EC406139BAULL, 0xA1B9D94B6F6D63CFULL, 0x86AEE48C0B01EFACULL, 
            0x9F506900A0A8A526ULL, 0xDD30E1FE5C82717FULL, 0x02AAED9D251A496CULL, 0x462158520AEC8335ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseGConstants = {
    0x94DCD33F695D0A66ULL,
    0x7FD61236106A2489ULL,
    0xA8E87B56A0D89AA8ULL,
    0x94DCD33F695D0A66ULL,
    0x7FD61236106A2489ULL,
    0xA8E87B56A0D89AA8ULL,
    0x6D14F979DBD3D8D4ULL,
    0x48500E8AC723039EULL,
    0x92,
    0x5D,
    0x4F,
    0x6B,
    0x2C,
    0x67,
    0x3F,
    0x96
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseHSalts = {
    {
        {
            0x5533B65BDB65D286ULL, 0x42D4519270EEAC85ULL, 0x750DB924FDE49CC8ULL, 0x599785EA0F18BA46ULL, 
            0x4D0BF9574E5E67F0ULL, 0x92F069A8FA42D900ULL, 0x17B4255264A610FBULL, 0xD9D76E819DEC381BULL, 
            0x3976A1274E05CAB8ULL, 0x452752AACBB50748ULL, 0xB4E449A1DD24278EULL, 0x61CFD7923300AA76ULL, 
            0x28579145F281B3E1ULL, 0xA04A135F0B325477ULL, 0x8F7615869EEFD5EBULL, 0x99D66CF0CB88236EULL, 
            0x64B3084F9E00BB36ULL, 0x9CFEA1A8526D3675ULL, 0xA5BE594A856A00B4ULL, 0x3383205172A304E7ULL, 
            0x5700E5625571EFDFULL, 0xA9B63CAC7D7DC36EULL, 0xE6694FB47D311F6DULL, 0x4577E9DC8E93D4BEULL, 
            0x3EE1F5EFFBF3B40AULL, 0x5DBAF4BDF2D5A999ULL, 0x59C8EC57CB8532FEULL, 0xCCB4AC02A6F69A73ULL, 
            0x1362F5DDB17B7AE8ULL, 0x029D0DE855A89CEFULL, 0x045233FF24138A2AULL, 0x46102B9F2B038194ULL
        },
        {
            0xDF888C7368979754ULL, 0x1E4DC950866A7312ULL, 0xF689F934080A8E4EULL, 0x2E850BDFD1CB3530ULL, 
            0x9D62534435F2149BULL, 0xABA869841F55D15DULL, 0xCBFA11831B351FB3ULL, 0x3DF9E7881E9CA37DULL, 
            0xE437536CFF3F8ED2ULL, 0x3269F4E216092F12ULL, 0xF8EB4B82DE318499ULL, 0xED1D39F521B80624ULL, 
            0x82A7226F90887988ULL, 0xDB78326E8BDA94CEULL, 0x4859C49724DEC235ULL, 0x9DA9AE7B7F2DB07EULL, 
            0x7D5FBC83F40ACFC5ULL, 0x9D5A25E298A3423AULL, 0xF89FA16D6C706F84ULL, 0x88BA5AD3194BF50BULL, 
            0x3F1EB7CC17FB5BFAULL, 0xD7FD946918C64F06ULL, 0x908EF92E992F4DDCULL, 0x87B8AC521A246695ULL, 
            0xF03C2EB04593C577ULL, 0x657C17A7F7AF0EC7ULL, 0xAB7643B0FDC816ADULL, 0xB81B3D28EF00E32EULL, 
            0xEED3D6AB372E395FULL, 0x4213DD7291E8FAA2ULL, 0xD5EF7761EAE2D91BULL, 0x54D5DEB3BFA4A984ULL
        },
        {
            0x7EBB9EC09781B6B5ULL, 0x5B2B215D5866B0CFULL, 0xAF80060C74E22A57ULL, 0x361494CC64C79C8DULL, 
            0x9E564F2F239D18DBULL, 0x4812202F9907F6ABULL, 0xF33B67DD25E949F0ULL, 0x83D576D722EA90B4ULL, 
            0xEF02101716D9C18BULL, 0x5D2EB073CAE6051EULL, 0xD2E5C8E3D15EA0FAULL, 0xE7208DBE85BD028EULL, 
            0x4BA750E9A2294A96ULL, 0x2CC4B22B521000CDULL, 0x30077CEDE84A1053ULL, 0x3C0E5EE34955743DULL, 
            0x821FBC217FE46FDDULL, 0x8D61D4E4F982F7EAULL, 0x3BD975C7B34880EEULL, 0x77A4C611925314F1ULL, 
            0x74CFF43D1A97F4CBULL, 0x64BB33E4AF393FC3ULL, 0x97F92BCA5E5BCC37ULL, 0x27927272EB615FDFULL, 
            0xAD388E292EDC3CCAULL, 0x7DE5AB97442021CAULL, 0xE7F801937215CD9CULL, 0x10F82810CCEAF108ULL, 
            0xD1EA3AD9FFBAADF5ULL, 0xCE00B684A8A3216CULL, 0xB106B7D682724C14ULL, 0x863474D63B71B18CULL
        },
        {
            0xFE74C34EE79AEEABULL, 0x39919304204FC4F5ULL, 0x49B623358D5B929BULL, 0xBEA77BDABD0710B6ULL, 
            0x001027B07EE79CD6ULL, 0x2543B52D270AED98ULL, 0x5EDFD80041F47E6DULL, 0x0AAD5DDE452F8BF5ULL, 
            0x4AF7AA2FB6329D60ULL, 0xA15CAA452AA40F3EULL, 0xDB0264EF37E3AC97ULL, 0xC50852D983E71FA5ULL, 
            0x70552FA650DF446CULL, 0x4FBC41A244CCDFC9ULL, 0x5FA9313229E0833CULL, 0x8E85F623B7D4EBBBULL, 
            0x834E26F2D3EB671CULL, 0x23468D3859B2C4E5ULL, 0x8804103A805C922BULL, 0xDA5EEC6C4A381BD2ULL, 
            0x80DB6775D9DB1601ULL, 0xA7082F7F4948D2BEULL, 0x0EF0D0732BE9F45EULL, 0x611FC8DEE47BD4C0ULL, 
            0x28C40F3BDC460924ULL, 0x482C1D7EB045C97BULL, 0xDCA42B571406BCE4ULL, 0x316553FE373DCB44ULL, 
            0xE72332261145D3C0ULL, 0xFBE2D8930712B40CULL, 0x6716D8D462074517ULL, 0xDBB418BA6BD10D31ULL
        },
        {
            0x95DE81AD7BDF6E68ULL, 0x6B916D2ABC9F39A1ULL, 0xBAD7F05431A1D460ULL, 0x0F06B0A7E1FB5459ULL, 
            0x596858E40D6BDA4BULL, 0x18C91B0DC5E13591ULL, 0xA47097B91267D83FULL, 0x0BE6DF0C12677465ULL, 
            0x2290FD5E20861FA6ULL, 0xD1451A06AACB901EULL, 0xECAE885C53E243EEULL, 0x192599855DB87731ULL, 
            0x7ED7B260FEEC7A87ULL, 0x2E75DB2BED02BD46ULL, 0xBA8F72EA5797022CULL, 0xBECA95F2186AAD00ULL, 
            0xC4144F64C3E9934EULL, 0x9BE5C1C56D2FE9ADULL, 0xE27AD98717119077ULL, 0x319F35848F430BB3ULL, 
            0x44434EAFFD72FEC9ULL, 0x40AF43C9AAEC003FULL, 0x0E7BEE71D1E6E61BULL, 0x308A9A010DCC0119ULL, 
            0xBE9C78CFFF6552A7ULL, 0xF491A02085900CA4ULL, 0x56BF75CC1CB6224DULL, 0xDF1D2699029FD3A1ULL, 
            0x89A2F3A39278D9B1ULL, 0xF52514C036B128FDULL, 0xA6DF862D781DCA76ULL, 0xC82B31F05EFAE1A1ULL
        },
        {
            0x6DDC9BE84CB1F07DULL, 0xCD2434E07E75F140ULL, 0x73C9BA254E41994DULL, 0xCBFDA1348DE9A6D4ULL, 
            0x3362E62628C8F66BULL, 0xE9307E68739590FFULL, 0x732E5F4CD27E2C52ULL, 0xEEB574C25803DCC6ULL, 
            0x180B7FE472BD3261ULL, 0xC5AC37CE74205B7AULL, 0x639A49310A6E0856ULL, 0xD096F9CE4D1C9577ULL, 
            0xC64976224A16E8A4ULL, 0x2004E9A1BB62ECD2ULL, 0xE8F14C3DD9ACCBE9ULL, 0x610DB9DE413F21C8ULL, 
            0xACF489E5ACA76C12ULL, 0x99F7F319168818A3ULL, 0x53B537ED3A15FADEULL, 0x76D55EC8EBAD0408ULL, 
            0x0AD30838427290A2ULL, 0xEB96AEF9576610BFULL, 0x5CB6E8DC426AF712ULL, 0x19C9085F1930EF60ULL, 
            0xD5424C0B5AC73D6BULL, 0x853F9C1373B6A044ULL, 0x41997C7BF098DEC7ULL, 0xF8BE4598BDF43502ULL, 
            0x4268022BE617B412ULL, 0xBE6395C009423C3AULL, 0xE3159FF8FD3E96E4ULL, 0x24E178EC94A9BDBBULL
        }
    },
    {
        {
            0x4844809E5F415862ULL, 0x4A33F50CF9C4D155ULL, 0x604972EC879A6A3DULL, 0x27EDC06B84B79131ULL, 
            0xE9DEA2E30E902BECULL, 0xFA9025F96AEF8166ULL, 0x5D96A15D816692AAULL, 0x5CA3218DF1FC7FA7ULL, 
            0x1A1CD18EAAFB2011ULL, 0x84B90177B9E541AFULL, 0x28D5570ABAB3842AULL, 0x51FE1C25D2B79F4AULL, 
            0x8E2B2B054A59959BULL, 0xA1944E2B852EC052ULL, 0x7CE6179F31A2665AULL, 0x9E14887740AE5A46ULL, 
            0x4D36218619409B77ULL, 0xF5EEC3E2A4F1D02FULL, 0xD1156C7B44D3E380ULL, 0xB6B88487EB2957BFULL, 
            0x3D2019110C87BB02ULL, 0x2ED0E3AC5CF02FB1ULL, 0xA20EA603BEA331CDULL, 0x79229F31DBB81B91ULL, 
            0x7E1387DD23F7629EULL, 0xBA3206D845C0122CULL, 0xF3470E73B7DA48FFULL, 0xAEF76CE80062F027ULL, 
            0x66E7B39032D445A6ULL, 0xAB54378263D599E5ULL, 0xB6D6BF7B93223C48ULL, 0xE82E6DF5B5BE68FEULL
        },
        {
            0xF73FD591FFCC85C0ULL, 0xF1F79236CC872EFCULL, 0xEDAF465D4AA9B2E9ULL, 0x9CBD34B898E388F4ULL, 
            0x81EDB933F2A767F6ULL, 0xFE17102560575606ULL, 0xD11B7A5C5234783CULL, 0x041CE4A057C5B5A4ULL, 
            0x8AE802D09267D65EULL, 0x1332060E57CEF869ULL, 0x5801FEE7A632ACC3ULL, 0x647F1E25AC8C0A07ULL, 
            0x08F5A52F5BB293D1ULL, 0x8F30348611866795ULL, 0xD0AF8DCB285163D7ULL, 0x1AB4D053ACC8F308ULL, 
            0x081F11D9723C9618ULL, 0x135F2490B0F7A0D6ULL, 0xD7727139C8C8FE81ULL, 0x92B3220DC4CDAF7FULL, 
            0x36AE816CEFC85B3EULL, 0x0C11E75608BA5BC5ULL, 0xE3287E71491A74FFULL, 0x3657624CF11D4CF0ULL, 
            0xFD31F689DE4BBFC7ULL, 0x2DA0EFEC176AF139ULL, 0x785B7960836B3B5CULL, 0xBCC4766C52C963A9ULL, 
            0x57048A7E1FE7756CULL, 0x48A5434550D94515ULL, 0xD489D362E8159B17ULL, 0xE91BB9EFA160AD53ULL
        },
        {
            0x355FE68168A654F8ULL, 0xA0B9CDD8B03D8E47ULL, 0x8B8DF46DFBD3CC64ULL, 0x45911D25D14D48C4ULL, 
            0x74D241D995C6671EULL, 0xB40C9DD95D54EB25ULL, 0x94F77E0438CDDC57ULL, 0x1E7C612E0A068DA5ULL, 
            0x1A775EDABA9983ADULL, 0xBCD7A567F7FAB9FAULL, 0xD0A64E169E242935ULL, 0x2AE906A881094324ULL, 
            0x2D06DD38AC0B4D7EULL, 0x7507B8FDE9057158ULL, 0xCBB4C5FB3EB846C5ULL, 0x51CE1BE53668D11DULL, 
            0x16FDC9BD8E8F6274ULL, 0x48C0DF8029809DBEULL, 0xC238771A35B02173ULL, 0x76F04D05C11D819DULL, 
            0xD1482FF69C0DCD90ULL, 0x31B713A581D3136BULL, 0x43CE0484EA464E01ULL, 0x464CE4E8596BD64BULL, 
            0xF18E797CFC785067ULL, 0xD49EA8E87468C481ULL, 0xF7C703787708A912ULL, 0x7D43226387E084F9ULL, 
            0xC520F42A5DD02357ULL, 0xF76487FE3B5FA095ULL, 0x10BDF37636A7CB34ULL, 0x2F6317A3454404FCULL
        },
        {
            0xAD221F078FE229FAULL, 0x5EB2CFDEB14ABEA6ULL, 0x92A97E9986381F09ULL, 0x931E40DE9D2267F0ULL, 
            0x806A186B20D183D8ULL, 0x1DC9C633998DE2D0ULL, 0x30768A2976375BB8ULL, 0xF301BFAFB073F554ULL, 
            0x11AFF66DE6FD2021ULL, 0x08A2BC7D17C258C6ULL, 0xFE9309443873F600ULL, 0x9A097008D41C40DDULL, 
            0x0AA704C8A03E213DULL, 0xEB2EAD5AE9A4D103ULL, 0x7DE8C7F08EF5ED3FULL, 0xF65ACC018A0B0960ULL, 
            0x29B8D8E74BD91608ULL, 0xA3398EAE78A73788ULL, 0xB0BA47D961AB6DC5ULL, 0xC2E3AF6CF78DF400ULL, 
            0x01FEA15D2F218999ULL, 0xEAD2018E79557723ULL, 0xF8FEC7AA7EFB32D4ULL, 0xDD919EC179631B3AULL, 
            0x9AD6D65B8FD1DFA8ULL, 0x6828FCF16DB52D74ULL, 0xD991DB45A043E835ULL, 0x09675C2979E97C25ULL, 
            0xF4522E06E12BF01EULL, 0x792F74765B47A9B6ULL, 0xD5C1B2F69CEEFA32ULL, 0x2CCED31B14F169CEULL
        },
        {
            0x902A790EFC78D8BEULL, 0x074DDC0FF18DC2D1ULL, 0x186F3FAB095A3D53ULL, 0xA3B0F6EE13D667A6ULL, 
            0x3A140BBCAB56987DULL, 0xF3BF1339E680D18BULL, 0xBAD3F08FCE6A0F06ULL, 0x78A77C2F53A30D55ULL, 
            0xB9AC9A1DA28F3ACAULL, 0x9F8A457D2A460A50ULL, 0x4233596E2A1D1205ULL, 0x606F92F6EFCC99A9ULL, 
            0x7DA90602C7631B27ULL, 0xD4988F7F35748C08ULL, 0x970BBF4E45D16B23ULL, 0x04F756CF0D9889E5ULL, 
            0x2A47F9931F0D7D7CULL, 0x6422984DDA007DF6ULL, 0x3DF816A983FF4AC2ULL, 0x8B348E36EE1A43FBULL, 
            0x11EC0CFB8AB53EF4ULL, 0x8CE8030B319423C8ULL, 0x82D7433FD07E3203ULL, 0xF329BC14BAF61F7BULL, 
            0x3CAA7CA08D944EFEULL, 0x9E94374BACE3C3EAULL, 0x3AB966FB6719F770ULL, 0x31555830F7646C43ULL, 
            0x8B1B8B5328861C63ULL, 0x0739CC5773EB26B0ULL, 0x6444A14DCC1D503FULL, 0xA192D493A206244DULL
        },
        {
            0x2E27116A9F085410ULL, 0x65ABE67A171D11BCULL, 0x4BCE6A993A31504DULL, 0xBFE3F6094BECFD8EULL, 
            0x6AAA4B64B46BE919ULL, 0x8446A9B0A74F01E3ULL, 0xB2BC978A348A14FCULL, 0x1D99314F0CB6AE09ULL, 
            0xF424616C5E46689AULL, 0x4852F23A86894639ULL, 0xEBEC9F8D3DFFC621ULL, 0x3B452131E5C33A68ULL, 
            0x878CCBC6C044F094ULL, 0x042A0BF921AD182BULL, 0x7CC7B4FF6271A2B6ULL, 0x40F59212B7224ED4ULL, 
            0x09B32751AB20D2E7ULL, 0x6E013CEF7D39306DULL, 0x9713BCBB8C2429A0ULL, 0x80BAE71C76E70560ULL, 
            0xED8EA19E47FAD6CAULL, 0xD3583CA59281A453ULL, 0x16FA1AB64AA3B7C4ULL, 0x0E60D5F2F8E6AD14ULL, 
            0x681A982B7E8BAF73ULL, 0xC8AA3710737EA7B5ULL, 0xC9FC7881AEAFD1B5ULL, 0x337BAB99C85A8B8BULL, 
            0x6C07F65CAAF32753ULL, 0x068A6094E8007833ULL, 0xFB23CE0CF08F3560ULL, 0x0D7779265BC14990ULL
        }
    },
    {
        {
            0x8E18178580B8A007ULL, 0x9FD53B9A844DEE84ULL, 0xC1A428A992559B81ULL, 0x4244EEF37FB5EC33ULL, 
            0x03BB9C4E627976B6ULL, 0x2C2739D68FDF573EULL, 0xD583BD43FB567A16ULL, 0xDD098F18A414AF64ULL, 
            0x6365B341E6AF9A5BULL, 0x16378CAF34AF61CCULL, 0xBB43255B9DB9EF2BULL, 0x3BC241B19100D545ULL, 
            0x044EDDCBB60711D4ULL, 0xE8880D55C3C55E5DULL, 0x167F058EE7BC3A49ULL, 0x9A755005D42762E4ULL, 
            0xD66F5B53F021104FULL, 0x694C1B892E0E7182ULL, 0x6268516E957BD9F4ULL, 0x7130AD1F1BD141D2ULL, 
            0x95221FD137295DD9ULL, 0x13469CFD0BD92212ULL, 0xC5CEE2135C2C0841ULL, 0xAF49CB61B1552B55ULL, 
            0x64BFCCA5E476F93AULL, 0x7BFBFDBB8F150236ULL, 0x3AE6861CBB24CF75ULL, 0xBA2EFBD6B0BE24E4ULL, 
            0x84637D41948E760BULL, 0x804C33AC163E6D5EULL, 0x7CC5B90AA448E444ULL, 0xFD2E4DADBCD39401ULL
        },
        {
            0x7EAD8935E308D8EEULL, 0xB8344DE50D01847EULL, 0x722685F57A40DA0DULL, 0x9530CD65B1EAD5EAULL, 
            0x08B8E78619E7027CULL, 0xD0C6D14EF4E750D4ULL, 0x8FF5A6B429D0F903ULL, 0x0D9CB8A768387C7AULL, 
            0x6631494BB80DB1FFULL, 0x8E6647C69BBD7DC3ULL, 0x7DDE553CD0D9E3BFULL, 0x700F0489294C4EF3ULL, 
            0x445357DEB91589BCULL, 0xD08B4CE6C210DCF5ULL, 0x5DB5DB86C61DDC33ULL, 0xE6F82A6FFE1655CAULL, 
            0x86FD81C34FD023C9ULL, 0xFB5B7ADC794D8EA7ULL, 0x6CFFF67473BDA505ULL, 0x1D482C647F7DC9F7ULL, 
            0x00C6285CFBCCC5FBULL, 0x499791F6052676C9ULL, 0xAA84EF62C5E80B7BULL, 0x5D774D692E363FD9ULL, 
            0x0A911484C6AB954AULL, 0xB97252FC66CA7E7DULL, 0xEA509665F186603FULL, 0x2336F1C1502D548EULL, 
            0x2B9480839A738D3FULL, 0x009D7B6100C615E2ULL, 0xA3911EEBAB4A0330ULL, 0x62CCEDAF6F2D0C9FULL
        },
        {
            0x5B23C7A812FD8C71ULL, 0x497F9382922D99E9ULL, 0x28364354E36E0DF6ULL, 0x8D9E4CF7283BB4A0ULL, 
            0xCD5F5F9ACC8132CFULL, 0x178F2CEE317EB329ULL, 0xB7862534FE86E526ULL, 0xE4EC726288212809ULL, 
            0x660C7D5C20129C3BULL, 0xF0AF4D6373EBD0C9ULL, 0x0A1DF999CA66F8D6ULL, 0x1743E893AABDEFD0ULL, 
            0xBF6A8C978D813B82ULL, 0x903C58E0CA54FD34ULL, 0xB0F10F16BDD6C341ULL, 0x93BE541D296A3B37ULL, 
            0x599A0A71A52368E1ULL, 0x734067C6B955A159ULL, 0x34B5905B34209289ULL, 0xCA81AE8F1B523E13ULL, 
            0x5EBDF9195A93C250ULL, 0x40CF93A8BAE46512ULL, 0x61FFA086FF744320ULL, 0xBE421090D0A70DFBULL, 
            0x47DBE3E26A7499ADULL, 0x56F5E406D5AA4853ULL, 0xAE00B2053390503BULL, 0xBAA2B7FEF9B93802ULL, 
            0xBD555023578FA896ULL, 0x90D2F5D326006A01ULL, 0xB3DF4B48DD8E9DBDULL, 0x13D5D89D2561C663ULL
        },
        {
            0x793800BEA2AD5C25ULL, 0x424A471D44FAD076ULL, 0xD49D2E9399EF352DULL, 0x761FCECA36C4848CULL, 
            0x72D3D94C202CE95FULL, 0xAB983B7D0138E9FFULL, 0xC7A338AC87EFB65DULL, 0xF2E7D3C5FBFBC98FULL, 
            0xD7F2AE3D2D0E5864ULL, 0x1173196F7866F6BEULL, 0xCAFA76BBF517946FULL, 0x517CBDB678C0CC99ULL, 
            0x369B2282ECA88739ULL, 0x371966281B7895B0ULL, 0xDEB5DBF400614E37ULL, 0x0EF9C8F4C8976F97ULL, 
            0x8F624B15A3B3B643ULL, 0x9A65F39A1C3CA13DULL, 0x7EC4AAF88B886574ULL, 0xB3383BD0C4513DD4ULL, 
            0x7F6203312AE4E73BULL, 0x70CDDF0BEFE047E7ULL, 0x27E57C56F48170B2ULL, 0x8EFCDFE684664AA4ULL, 
            0xEE9F82A3D636DB98ULL, 0x061FA59D078F2D07ULL, 0xB275A64199C88DFBULL, 0x76A502228224F348ULL, 
            0x7821B81317064AE9ULL, 0xFE9C8A5C58B33F0EULL, 0x2341E919410BCB02ULL, 0xB546109CBF7824C0ULL
        },
        {
            0x3DAD6D1669437980ULL, 0x2D9020CC6C0F487EULL, 0xC168F5203ED0A795ULL, 0x0AA46EBA99166693ULL, 
            0x3E28F68E83FBD604ULL, 0x58CCB1BFDAC12A36ULL, 0x7AB6E65FB27601D7ULL, 0x9BFAD9FEB5302722ULL, 
            0x4A36460D7970804EULL, 0xBF9F4C97C153D647ULL, 0x772E1112E6993ECBULL, 0xCC9565777E73FB7DULL, 
            0xAD268D037E8B9DC5ULL, 0xC53EB3C6289FC980ULL, 0x29F504CC4E7D8F7AULL, 0xA41A18600E8318F7ULL, 
            0x46055A188D5FB90DULL, 0x5786D2A5C9749265ULL, 0x461781AD770680EBULL, 0x7BDDBFF36CFC4ACAULL, 
            0x2FE899C1BD893C55ULL, 0x0BCC02EC303C01A8ULL, 0x078B379276D42CD8ULL, 0x1953EEEF87BBDC42ULL, 
            0x8613CC0560076498ULL, 0xAF562ED5AC3FA21BULL, 0x7AC48DAB68224FF2ULL, 0x7F9D210C8A6D1F62ULL, 
            0x2F40D9038742BF16ULL, 0x222045811969230DULL, 0xCC8BCDF8723BE912ULL, 0xCE36D84651989453ULL
        },
        {
            0x6790A557281675D0ULL, 0x81E4FCB11FAF5A14ULL, 0xEB3846166365E7F7ULL, 0xAC00DE0BAC3ACC04ULL, 
            0xE084DD0031CF29DEULL, 0xD296FAC62DB145B0ULL, 0x2A4C00CA137EA328ULL, 0xD49BF0E3D14D1C35ULL, 
            0xFF9514AFED14B980ULL, 0xCCE2EA8D06B45D55ULL, 0x9EAB148C61A1FEF1ULL, 0xCF1913472BE84127ULL, 
            0x65BF15D604472EC0ULL, 0x16F0E1260C5711FFULL, 0xBB8C051BF7F0CF69ULL, 0x0F7CF27953D862A1ULL, 
            0x1EEC49236FEC3496ULL, 0x1EB2C66BC9E65E10ULL, 0x5E9927CAE39EBF5BULL, 0x68A96AA7CB24B62AULL, 
            0xE715879EBE4194F4ULL, 0xDA480107365CF8CAULL, 0x490B9AFB8D0719D4ULL, 0xB197FB735D88595AULL, 
            0x1247431A9966E0F0ULL, 0xF5D709554703A351ULL, 0x70CDC897C0F14BBFULL, 0x289FB1EA18B80440ULL, 
            0xB94F9F276B2A4139ULL, 0x81347354D541D2EBULL, 0x95851F8F23478E9DULL, 0x89C7C7EF3878DAC0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseHConstants = {
    0x711365721CC3D430ULL,
    0xDBCF02A334145C57ULL,
    0x9509713246E63113ULL,
    0x711365721CC3D430ULL,
    0xDBCF02A334145C57ULL,
    0x9509713246E63113ULL,
    0xD36A4DABE3F6ADA3ULL,
    0x6235D7EB763B5C03ULL,
    0xE3,
    0x4C,
    0x94,
    0xB0,
    0x19,
    0x78,
    0x96,
    0x50
};

