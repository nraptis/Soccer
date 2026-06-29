#include "TwistExpander_Lacrosse.hpp"
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

TwistExpander_Lacrosse::TwistExpander_Lacrosse()
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

void TwistExpander_Lacrosse::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xA9F4246FF37757D6ULL; std::uint64_t aIngress = 0x8C84E333E1C0803DULL; std::uint64_t aCarry = 0x91EC1344FB5405F7ULL;

    std::uint64_t aWandererA = 0xAD157FAD4DA52CF1ULL; std::uint64_t aWandererB = 0xBA81FC4BE96B8F6CULL; std::uint64_t aWandererC = 0xAD1E8F554DF748B6ULL; std::uint64_t aWandererD = 0x9F54C0DAB69D1C0DULL;
    std::uint64_t aWandererE = 0xCD97A5D3D0002BEFULL; std::uint64_t aWandererF = 0xE5A2DD372404B69AULL; std::uint64_t aWandererG = 0xED2CB33A650C3BF4ULL; std::uint64_t aWandererH = 0xDA33627C8D450593ULL;
    std::uint64_t aWandererI = 0xA20345489EAE5010ULL; std::uint64_t aWandererJ = 0xEE1C14F0F4112C7CULL; std::uint64_t aWandererK = 0xF4FECB3AB553BC5AULL;

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
        aPrevious = 11963565222396686900U;
        aCarry = 12653886767403108629U;
        aWandererA = 10718746309862759745U;
        aWandererB = 13432718853279010307U;
        aWandererC = 9912466214387946088U;
        aWandererD = 14237313885652195509U;
        aWandererE = 10098576492005268060U;
        aWandererF = 17612619623723384613U;
        aWandererG = 14946731876104199283U;
        aWandererH = 15803738584639066137U;
        aWandererI = 16870817461527904273U;
        aWandererJ = 12241879303776403673U;
        aWandererK = 18039494321249331716U;
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
    TwistExpander_Lacrosse_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Lacrosse::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x9E126C6A53CA1CF8ULL; std::uint64_t aIngress = 0xA65FA22982F428A4ULL; std::uint64_t aCarry = 0xB67095538099BF1EULL;

    std::uint64_t aWandererA = 0x82B5A482AC4443F7ULL; std::uint64_t aWandererB = 0xC02D7F690A1240DDULL; std::uint64_t aWandererC = 0xD956992A6D1BCC46ULL; std::uint64_t aWandererD = 0x8A93130DD0F690FDULL;
    std::uint64_t aWandererE = 0x890C3ADAAC02EE00ULL; std::uint64_t aWandererF = 0xBA5C0BE1F324DAC0ULL; std::uint64_t aWandererG = 0xC41A4AD3ADFEA728ULL; std::uint64_t aWandererH = 0xA71F4B355B97F71AULL;
    std::uint64_t aWandererI = 0xC03AF45209C9232BULL; std::uint64_t aWandererJ = 0xC9B4EDFBC67C2B19ULL; std::uint64_t aWandererK = 0x9D6E996326F8425CULL;

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
        aPrevious = 11477212192264380992U;
        aCarry = 17878966123451722582U;
        aWandererA = 15011124238736112913U;
        aWandererB = 12577124388964734147U;
        aWandererC = 10292217343329927912U;
        aWandererD = 13531848922099239488U;
        aWandererE = 16434724258457641406U;
        aWandererF = 14060237894494720673U;
        aWandererG = 18041520300017978562U;
        aWandererH = 13502564347690940374U;
        aWandererI = 12529721662483038224U;
        aWandererJ = 9752856732991257744U;
        aWandererK = 10376234397408879634U;
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
    TwistExpander_Lacrosse_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Lacrosse::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB164564F4BF27FAFULL;
    std::uint64_t aIngress = 0xC9764B4676DEB63CULL;
    std::uint64_t aCarry = 0xA6FF891ADE027BEFULL;

    std::uint64_t aWandererA = 0x8203F7EAD65DAE0DULL;
    std::uint64_t aWandererB = 0xBCB3968D4C057103ULL;
    std::uint64_t aWandererC = 0xDDE713E4F3A7BF47ULL;
    std::uint64_t aWandererD = 0xCDABF6819124C2AAULL;
    std::uint64_t aWandererE = 0xB7D0E4FA8B6017D0ULL;
    std::uint64_t aWandererF = 0xD62A93A098F5C167ULL;
    std::uint64_t aWandererG = 0x87AE4EDEDDC81828ULL;
    std::uint64_t aWandererH = 0xE569DDB66F9D8F59ULL;
    std::uint64_t aWandererI = 0xFEED04FB588B99D4ULL;
    std::uint64_t aWandererJ = 0xA914834A47F64A45ULL;
    std::uint64_t aWandererK = 0xB0BC53B9AAE1E640ULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA, 1);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD, 2);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneB);
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneH);
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA, 5);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD, 6);
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
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Lacrosse::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Lacrosse::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC8D1F7CC9A28F492ULL; std::uint64_t aIngress = 0xC5FF93DA7B7D4A83ULL; std::uint64_t aCarry = 0x9BF86E0768944830ULL;

    std::uint64_t aWandererA = 0x8E5CF523EE4E44E4ULL; std::uint64_t aWandererB = 0xE1176EEE70E0A860ULL; std::uint64_t aWandererC = 0xEF52489D6D524DCBULL; std::uint64_t aWandererD = 0x9029516CE7191560ULL;
    std::uint64_t aWandererE = 0xB408B263B12FA98DULL; std::uint64_t aWandererF = 0x851950E3A388FFEFULL; std::uint64_t aWandererG = 0xF440B7084A0BF46AULL; std::uint64_t aWandererH = 0xE6D6DEC01C5CF835ULL;
    std::uint64_t aWandererI = 0xF9504FB3750A806CULL; std::uint64_t aWandererJ = 0xCADE5F936FAEE0CCULL; std::uint64_t aWandererK = 0x8031356F1B426A39ULL;

    // [seed]
    {
        aPrevious = 13303811772337930404U;
        aCarry = 16589737864239646508U;
        aWandererA = 15368795746608166399U;
        aWandererB = 13489429736976646022U;
        aWandererC = 10354479254994351229U;
        aWandererD = 12548464579024967248U;
        aWandererE = 17302686405015960759U;
        aWandererF = 18184528582218587964U;
        aWandererG = 9904191682810462455U;
        aWandererH = 12915618527041481410U;
        aWandererI = 12808831257918687049U;
        aWandererJ = 11575638540669373917U;
        aWandererK = 10620929906621205280U;
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
    TwistExpander_Lacrosse_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Lacrosse_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Lacrosse_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Lacrosse::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 1, 0 with offsets 4621U, 5686U, 3364U, 698U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4621U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5686U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3364U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 698U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 3, 1 with offsets 7054U, 6045U, 1510U, 5814U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7054U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6045U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1510U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5814U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 2, 3 with offsets 4145U, 4381U, 3575U, 1281U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4145U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4381U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3575U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1281U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 0, 2 with offsets 8143U, 4921U, 8088U, 7676U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8143U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4921U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8088U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7676U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 2, 0 with offsets 353U, 657U, 1661U, 322U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 353U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 657U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1661U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 322U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 3, 2, 1 with offsets 1273U, 1802U, 1133U, 1525U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1273U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1802U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1133U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1525U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 2, 3, 0 with offsets 1304U, 1898U, 734U, 1828U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1304U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1898U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 734U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1828U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 1, 2, 3 with offsets 1228U, 870U, 781U, 653U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1228U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 781U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 653U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 827U, 653U, 1468U, 390U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 827U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 653U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1468U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 390U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Lacrosse::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 1, 0 with offsets 1031U, 6820U, 3242U, 7759U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1031U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6820U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3242U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7759U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 2 with offsets 813U, 7261U, 4323U, 834U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 813U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7261U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4323U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 834U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 2, 3 with offsets 274U, 1627U, 6606U, 2529U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 274U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1627U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6606U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2529U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 3, 1 with offsets 7289U, 7110U, 4222U, 6211U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7289U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7110U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4222U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6211U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5262U, 8110U, 7408U, 6372U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5262U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 8110U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7408U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 6372U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 52U, 1200U, 752U, 1416U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 52U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1200U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 752U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1416U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1745U, 128U, 551U, 80U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1745U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 128U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 551U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 80U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1230U, 1722U, 1216U, 719U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1230U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1722U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1216U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 719U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 458U, 755U, 2U, 463U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 458U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 755U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 463U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 0, 1, 3 [0..<W_KEY]
        // offsets: 1088U, 450U, 131U, 1886U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1088U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 450U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 131U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1886U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseASalts = {
    {
        {
            0xEC90E06CC68B8524ULL, 0xCB95FCBD564869D2ULL, 0xE0A2A01D02B97926ULL, 0xBB6277603ECA0761ULL, 
            0x61772FF80A163971ULL, 0xAA530D174AC61EEFULL, 0x564A8036229037A8ULL, 0xF34875915055F1F4ULL, 
            0xB57DE6D6083D9C6EULL, 0x6D63DB948B7EC645ULL, 0x09BFF47BF6B21620ULL, 0xD9DEF74B8B8E0C58ULL, 
            0x9F33C230CDFBA2D8ULL, 0xAA777E0D2A624DE9ULL, 0x74088A424EAC796AULL, 0x4D7FF0F71C71DD8AULL, 
            0x4D9B57427E49FAF3ULL, 0x216016DEBAA686DCULL, 0x0005A41BF0D669D7ULL, 0xBD6CB2BED9D19E0FULL, 
            0x3A7351C3387667A8ULL, 0x3585438D519A17ECULL, 0xC653B416151F64A6ULL, 0xFBBD08118C1EBE33ULL, 
            0xCFFC53E8B1846B71ULL, 0x7397195D8586F5D2ULL, 0x232BE5B3C800E7BDULL, 0x2E49E29877008396ULL, 
            0xE81369EA24C19801ULL, 0x52DA249BCEF921B2ULL, 0x76DCB1B3CF93B949ULL, 0x36E278A0A5609AC4ULL
        },
        {
            0x952107613A8964E4ULL, 0x99224F6937E10167ULL, 0x699CADD6EC5AEC5EULL, 0x0657FB15E0D7956EULL, 
            0x1E98E92D5E5CABB2ULL, 0xCAB9E03D7CB356B4ULL, 0x19B48ACEC84C53BAULL, 0x7F0982E4E89D7340ULL, 
            0xA3EC20CD7521CA21ULL, 0x060E61AD50E37AA0ULL, 0x0C062BBCF96302E8ULL, 0x0A33B32A80CDCAA3ULL, 
            0xD915C4AEBC710C71ULL, 0xA6612EFF9EBBB701ULL, 0x1050166683FDFC6EULL, 0x43883D387D0EB569ULL, 
            0x90C3747A377C806CULL, 0x4EDD3BB5F2989B9AULL, 0x0B88C0E48E7DCACBULL, 0x1B9CF00FC7C58696ULL, 
            0xAD2985F4F7DB2E1BULL, 0xE652C76D9411CAC3ULL, 0xE380177B838770CFULL, 0x3400D535E39A1970ULL, 
            0x965B3FFB82528A58ULL, 0xAD507BCBFB4C1700ULL, 0x4429F8398988CCF4ULL, 0xB2EE8237C59F30A8ULL, 
            0xA8F9DFBD1FBAFC62ULL, 0x1E64E054D4EEE723ULL, 0x7E4F5330A6520EEDULL, 0xD1160DEAD2586380ULL
        },
        {
            0x7DBDF453845676D4ULL, 0xCDBE39F4724BA8C5ULL, 0x4EFA54B27E973266ULL, 0x92D22943194F29C2ULL, 
            0x9851C7BEE79FD648ULL, 0xEC2B3420180F960AULL, 0xCCAED7F585BD6224ULL, 0x4A752DABC1998147ULL, 
            0x5B020DBC3F742074ULL, 0xCCE995D62FAF720DULL, 0xC225558053B36BCCULL, 0x5B2F5112A25A1701ULL, 
            0x1249B711A1787DBDULL, 0x629C28F46A89B824ULL, 0x703D171FFB590B89ULL, 0xF12B684A7251CBA4ULL, 
            0x77669DAF1F360073ULL, 0xB6045EEACFFF2B49ULL, 0x6F3E741C7DADEDA4ULL, 0xE6CD11C06964F709ULL, 
            0xF47E8855DA321815ULL, 0x7984D6EB6A1DE926ULL, 0x4EA952007468B634ULL, 0x18A5B5BEBA8C24DFULL, 
            0x9993BEAEA4416940ULL, 0xB46B6D0D2DC80C44ULL, 0xA7950C2B3BD3F592ULL, 0x1EEB8DEA99C05B0DULL, 
            0x93B1B6D47810CD52ULL, 0x4106CA74377F9879ULL, 0xCC5EACCBA886CFC0ULL, 0x7B231A97F24BB8A5ULL
        },
        {
            0x182F4573A35CA789ULL, 0x9B7933276ED735DCULL, 0xA6C3214D0FD790FEULL, 0x5052E0A0CC28F897ULL, 
            0xBC0656015E4A4F6AULL, 0xB47B1D2A7CB82735ULL, 0xF6DF8B977B8250F4ULL, 0xB94EED64CAA3CAC9ULL, 
            0x8D4D0F2B5F6E6767ULL, 0x2E2FBBFB8E366FB0ULL, 0xAA82957594550EE8ULL, 0x1424455C81499313ULL, 
            0x88C09084F93A84CBULL, 0xF7E3D915EDF5F0A3ULL, 0x7A10C3D8488F1DDBULL, 0x078151A3F127BFAAULL, 
            0x3A41300ACD6F6513ULL, 0x64AE57D7FD689A02ULL, 0x470ED9654D1CCE97ULL, 0xA191E00F7F6E4361ULL, 
            0x9656D0AEECBE4201ULL, 0x4EC60FE9B96F044BULL, 0x4AAE6C5098BC2406ULL, 0x94D83DBB5BC6A088ULL, 
            0x5D319F56167FA6CCULL, 0xA98539192391EC97ULL, 0xE170D52CDFDE56B3ULL, 0x83F35CFFECD5F55DULL, 
            0xED59139D5E3E52D7ULL, 0x97640B35FF32758DULL, 0x0B6F121FA43D0E70ULL, 0x79D7B8E9CB1C89B1ULL
        },
        {
            0x8A7124D7D90C62C9ULL, 0x5A8E1EF3BAAB1077ULL, 0x5566651A582BC9BDULL, 0x08E51545633DCD04ULL, 
            0xB5E1C511DBFB302DULL, 0xB5B4AF15B3BA9AB2ULL, 0xCDC7EE400813BC16ULL, 0x3214CE0C06917E9BULL, 
            0xCD66C330764E8A1CULL, 0x649E67BDED115F6EULL, 0x1DBF54FFBD62602DULL, 0xD404D8D5253570FFULL, 
            0x199AB8C884BF5687ULL, 0x2A4EC7C3622E4BFDULL, 0x9707A97BA7A50C1AULL, 0xD4834F8225A044FEULL, 
            0x26E7DF66134B88A9ULL, 0x39B14EB6FFDA65B3ULL, 0x066EA98C5C43C7FCULL, 0x00EF2F0371115DABULL, 
            0x5CC0F2023A9129ACULL, 0xBC8275F8E16E8459ULL, 0x9F1337D32493C18EULL, 0x5FDD0A783D3EA551ULL, 
            0x6F77FA7E6EDAA9D2ULL, 0x43E8DE6721F53F3CULL, 0x161F0D1745147044ULL, 0x8414A2B8A3B25954ULL, 
            0xD70F27DE016CA595ULL, 0x7B494380D26F0765ULL, 0x4038EF6BD0853585ULL, 0x11246FC48F34927EULL
        },
        {
            0x40A8619454E43B54ULL, 0x8912E78C5C7D4B07ULL, 0x84065F7E9F61BAFFULL, 0x839286EC79EC31F9ULL, 
            0xF5A79DDA7BFA5A14ULL, 0xD64586E747E75BDAULL, 0x31FF6D05A89A0FD5ULL, 0x8464ED4EA5817C88ULL, 
            0x2402CFCBB614314FULL, 0xA4FDEA530E9C5B10ULL, 0xDCBC36466DA8E70AULL, 0xC2DDDA3FDD82DBC0ULL, 
            0x16ECB77B53BA2396ULL, 0x80F53234DB833756ULL, 0x3CBC3F231162940CULL, 0xB1A6A35C076C897BULL, 
            0x49DA27531CEF0FCCULL, 0xA1F82CD85569ED94ULL, 0x610A1AF76A8E5742ULL, 0xD12E37DD6987429DULL, 
            0xB9AD7325C9BF254BULL, 0xBDEAB9B8670F3A28ULL, 0xD0725258E09B1CFEULL, 0xE5FC02F819DE26EEULL, 
            0xE219F82BC5B8CDDBULL, 0x3FD3C5F1B8482442ULL, 0xCE1808890EA39FF4ULL, 0x0610E987DC4432C5ULL, 
            0x5988AFEE63FD3F5FULL, 0x6A976CBDAE1CE38AULL, 0x674BB03173151E89ULL, 0xC581EA98E6C71915ULL
        }
    },
    {
        {
            0x91C6630884725AC8ULL, 0xD0A6F03EB9A76084ULL, 0x548C203D0FC45536ULL, 0xEA1CF71941FA9F28ULL, 
            0xCA9EAE63F23CDCAAULL, 0xDA862D1F3E318C14ULL, 0x0FAAF22F7678C030ULL, 0x27C176BBE73A7411ULL, 
            0x4A0920B02456A5B5ULL, 0x90BD1EF859D6F2BBULL, 0xF68DDD859122BAF8ULL, 0xADB44483A71D2D2CULL, 
            0xFDDBD47F8D5D4D26ULL, 0xC447BB1C52355DACULL, 0x2FD5C6DB6C366BF5ULL, 0xB15AB03AB7792EABULL, 
            0x950754A095519E98ULL, 0x9AB8566AA4965A10ULL, 0xE6D0D60954CAFBDAULL, 0x70F40E36F407B5F5ULL, 
            0x331C11C683190A95ULL, 0x209E74A958121D77ULL, 0xA353110C179D8B6CULL, 0xE736C2BA01E5382DULL, 
            0x5930B3B2C2A199EEULL, 0xAEEE4A4A374EBF34ULL, 0xB16540F5A28972EFULL, 0x42C57418C556DC18ULL, 
            0x16C4E57A09D5A6D9ULL, 0x9A6A881E1E78DAA5ULL, 0xABB6EE3B0DF31B6BULL, 0x5EE3DDB3EE6E0FF8ULL
        },
        {
            0x3E4A972A64854B65ULL, 0xE6497E0CB28D6D7FULL, 0x8435068F1997CF88ULL, 0x09A1F2D849196DA4ULL, 
            0xE0FD329B5944FE0BULL, 0x23F6BF906D9A1918ULL, 0x6907EB6C97ED416EULL, 0x0FF42991D0CB50AEULL, 
            0x20D16311FB0627A9ULL, 0x70264012AF604900ULL, 0xBD7AA98D6B8CAF73ULL, 0x0A42638C63CBFE8DULL, 
            0xF47B1A896C1EEDA1ULL, 0x8D4CAEA81D55B636ULL, 0x8162D39C684563CEULL, 0x2E1B5108F1796CDCULL, 
            0xE4ADF52B52451398ULL, 0x91CD30B81FED3ED7ULL, 0xD70DD8D32386C670ULL, 0x4059C6232B1A5910ULL, 
            0xAC122280F82AE52FULL, 0xCA5CB0909C60ED78ULL, 0xC87AD5573671DA66ULL, 0x5CDD25B388915FE1ULL, 
            0x4D566211057F145DULL, 0x62496BD91EAAEF7DULL, 0xAC807EB466C2D085ULL, 0xF3D408150F910303ULL, 
            0xF997836246CD8729ULL, 0xABECBD23A92749D1ULL, 0x4D2CBD6422B0DB28ULL, 0x3AAA14262DD2E0ECULL
        },
        {
            0xDEDBDA3EAA7D5389ULL, 0x67DAADA97A567FFAULL, 0xE1CFD85EB43AD999ULL, 0xB278329B2B1898B4ULL, 
            0x987BB3DB544B2F70ULL, 0x1756586481CF2B16ULL, 0xBAF5E43B581AD8D8ULL, 0xCCB4A807780D8D6BULL, 
            0x3AF717B1F2FBB7ECULL, 0x2C0F1E7A4414A8B3ULL, 0x23FDA377B789113EULL, 0x8024F699EA3C86EFULL, 
            0xA3FA5D22AC55ADA2ULL, 0x3E169E00A0BA6C5BULL, 0x5FDC2806CB462A59ULL, 0x93CAE06864EE03ACULL, 
            0x3B037AD1D3C54DC6ULL, 0x1E078649A531D7D9ULL, 0xB16E25E99F2C6A7BULL, 0x96630D006850CE0FULL, 
            0x615D2118BE729B12ULL, 0xAE3F31743EEB2A60ULL, 0xF853C99687DEF4C3ULL, 0x34E15546F969B3FFULL, 
            0x2AE7DBE8A201211BULL, 0x36C03B4E643EFAC4ULL, 0xA72A87497C898709ULL, 0xE4162754C8CBCCA5ULL, 
            0x37F7ABFCF18A60DEULL, 0xAE63BA9952F7B1B7ULL, 0x9991F8C142D5ED78ULL, 0x731F97A572163187ULL
        },
        {
            0x9714C698178E8AFFULL, 0x63B096241C6D09FCULL, 0xE8643ECC487CA500ULL, 0xD0CE977B5788DDE3ULL, 
            0x038A464ACBD8A7EDULL, 0x417A5BE306635B7CULL, 0x3CAA3DFCF823D639ULL, 0x1EE59351A16FFA64ULL, 
            0x8CEE9B4003276311ULL, 0x4ABCB696B50BDBB9ULL, 0xC3F90648070C6A86ULL, 0xD01DED211AE06C8CULL, 
            0x052A41C03B314CF6ULL, 0x59D4969A60FE3C0FULL, 0xDFCCF5A3D5C1ADF8ULL, 0x98DC9D978CC6FB96ULL, 
            0x6AF3202DB7F1B849ULL, 0xBDCC291EAF8C92AAULL, 0x10D1AF7B85FBB66AULL, 0xED22736362F36A80ULL, 
            0xAB35D024E9C42DF6ULL, 0xBC5BEE286B239132ULL, 0x5D8B52E92203C018ULL, 0x81EBC44F48A195F1ULL, 
            0x4C8B24233297CCE7ULL, 0x7F175701A2461650ULL, 0xEEC0D11208664A6AULL, 0xD9C4433F51086C69ULL, 
            0x91152A6B5C324087ULL, 0x7E59C34312C2601AULL, 0x1490AAC46456D96AULL, 0x12AF88C3AE9B946DULL
        },
        {
            0xDA64219B4C289AFDULL, 0x1E888A6F8C15AEFBULL, 0x24DA65634DE94C3AULL, 0x09A3CDBF7F525BF9ULL, 
            0xEB01687753CCBB2EULL, 0xCA37920FD0B98610ULL, 0x7AF2155378E8BD7DULL, 0xFBF79F4CEF2D8262ULL, 
            0xE070F609064EBABCULL, 0x0C69D154795C1C77ULL, 0x096D2E5A4FB1CAE2ULL, 0x6C755051F8F76C11ULL, 
            0xBC49849E067A1822ULL, 0x94D579482302CFFFULL, 0x6140FEF65B0F1F62ULL, 0x9D8E2DF5C8C093A1ULL, 
            0x20C4E2E3C79E735AULL, 0x3B358D8F382DF914ULL, 0x62BB3EE3DB4D088CULL, 0xF2E09130472914C8ULL, 
            0x85ACC973CBFFCE56ULL, 0x9DBC14B63BCFCB8CULL, 0x4412C52C2E23CF8AULL, 0x5AE6B96C84FB915FULL, 
            0x05743C5BD3E34DFDULL, 0x230DB0B2DAF448C4ULL, 0x038EB117A978B3C6ULL, 0xE614B2BFDB66B799ULL, 
            0x99BFA7D54F869C34ULL, 0x6EEAB35D59451C5AULL, 0x7040C5F66E04306AULL, 0x4DE8040D4175C8A9ULL
        },
        {
            0xB390F4206FA57986ULL, 0x13633D39782E5AB3ULL, 0xABDF281550148929ULL, 0x339E3B7E8FCB1821ULL, 
            0x9EB6DF0855115803ULL, 0x20046A6CD8FF8064ULL, 0x785B758D4B2F1E62ULL, 0x8DB3C94D00DF65C9ULL, 
            0xC68E88280E6A5D0AULL, 0x56672B133A28ED00ULL, 0xA9E1627CFF7F2D9EULL, 0x49B497B982BF3980ULL, 
            0x60838A1ACA76D372ULL, 0x803CBA0808B34B2BULL, 0xE5334CC78E0A1643ULL, 0x869345DDF23DC65EULL, 
            0x052714F4432F88ADULL, 0x45664CEEEFC587A5ULL, 0xA77FB10715D8DDE1ULL, 0xAC8A0CDCAA132891ULL, 
            0xD4B5833ADC3F303AULL, 0xDBE29640B54CB954ULL, 0xC5E259776181D3E8ULL, 0x47D84024CE854CACULL, 
            0xAAC4449303B1F207ULL, 0x2264FEEE03EBEBB4ULL, 0x556C5FDFD22F8EADULL, 0x3436FB290983A3F4ULL, 
            0x1FB4946AFC141CBCULL, 0x0BC31783F1D42DC7ULL, 0xA6F997C1224C7D2DULL, 0xB26A8FB38D4A81ABULL
        }
    },
    {
        {
            0x71F0077F15993618ULL, 0x2153B3220B357CF2ULL, 0x56A680C0BEAD87D3ULL, 0x48826993FE24E6A6ULL, 
            0x7F54659F23946B50ULL, 0xD912356A6820563AULL, 0xE89D1540EC02768FULL, 0xE00300A9528EC763ULL, 
            0x9805F6113F0E71CFULL, 0xCCBD45012689416EULL, 0xE87099B731E200FFULL, 0x0044BAA47224C6A8ULL, 
            0x1608497FFD37B42DULL, 0xB5A907B1EC357CE8ULL, 0xED4C4EC0B3D8B1FFULL, 0x9D163C8C64755BA2ULL, 
            0x9227B6BD137B1F2AULL, 0xC5611110068A7839ULL, 0x78278EFDE218C4FCULL, 0x775D9A7A9B5761A7ULL, 
            0x0E8B9C3FA8595AC1ULL, 0xD88B8359D50EC39FULL, 0x8260FAEF9DDE3E05ULL, 0xCD28B0650931DA71ULL, 
            0xA3ECF0E3ACC9A2D4ULL, 0x4C55868773C81F9CULL, 0x1337AAB2217DA3C2ULL, 0xB75B6767BEC66FE7ULL, 
            0xFF438E6953A49C90ULL, 0x3E3260721B3268D7ULL, 0x09376C5B7C2D234EULL, 0x77F7894279F0EE88ULL
        },
        {
            0x82AC4BC1DF4ECE05ULL, 0xA180ED04AC262C02ULL, 0x8943CA0B4B1CAA21ULL, 0xB52AD19440BF547DULL, 
            0xB831697D05835539ULL, 0x7EEFB72430E0438CULL, 0x9FFDB63D5D186E91ULL, 0x8CE002A6D47CF997ULL, 
            0x72681483E3A367D7ULL, 0xFAC2FE95E43198C7ULL, 0x47339AD3E75A5B3EULL, 0x16C12AC6AEA3235DULL, 
            0xB6AFCEA67F921DF9ULL, 0x8A6DC57824BE943FULL, 0x68CB565DBD9E217FULL, 0x1196D2825A1881E3ULL, 
            0x4CA6FCF535A0420EULL, 0x53FA60F62A3DB139ULL, 0xA78EAC648D137E67ULL, 0x98101B92D1BD8885ULL, 
            0x33E5B342215B44DDULL, 0x6254F826442D01BFULL, 0x72B7034B889F0FCBULL, 0x8FCEDC4F6DA56EF7ULL, 
            0x69B2C85AC07B689DULL, 0xE5E7BE94229CAB94ULL, 0xAC9940A0427C77E5ULL, 0xD69812481FCC2063ULL, 
            0xA6B6AEE27D9FB940ULL, 0x52495BF217731D1FULL, 0x3465655E30B0C166ULL, 0x0C1C9EF34CE4D877ULL
        },
        {
            0xAF11287B285EF209ULL, 0x13F62FFCB8FED241ULL, 0x358FE9972CFC7BDEULL, 0xC02C6718C9766E0EULL, 
            0xECE9ED614C8962A4ULL, 0x20B5B5364B725B5FULL, 0x53474834D80A6E67ULL, 0x296D21EF346838C9ULL, 
            0xA7FD0954D5AB5DA7ULL, 0xB7DD1FFB0ABDC495ULL, 0xE8EFD8D089AAE173ULL, 0xC7F9CCDA640B6471ULL, 
            0x6A30F37C6D62ABBFULL, 0x8738E9281F7481E7ULL, 0x55B673880C5AD92EULL, 0xFEA32E1DE4C6A715ULL, 
            0x69B95C1B1FA30321ULL, 0x9CE9FDA25DC3554FULL, 0xD09F1BB3F0F2EC69ULL, 0xADE8B6D67054EECEULL, 
            0x565B856348A92DBEULL, 0x2F8AE5352E79F3CDULL, 0x4AB339EB01EF9014ULL, 0xB73C1C3D79AD1FD3ULL, 
            0x59E6426F9D339293ULL, 0x49E7BA8BB1BBE9A2ULL, 0x6FA664D307B5243CULL, 0x732C7586BB6EB202ULL, 
            0x51AA5005532790DAULL, 0xC0E422E1C36F7BB6ULL, 0xFD16268A007F44E2ULL, 0xE1632C46E87C4153ULL
        },
        {
            0x33427F6E73E7774BULL, 0xA4B03DE25B2EBA3CULL, 0xFFA47ED136344A76ULL, 0xFEA0FB06DCC05E8CULL, 
            0xC2735070153C5068ULL, 0xC949C9F71564FFA9ULL, 0x8DF620E68E72EF1BULL, 0x39956FF4C0A255D1ULL, 
            0x56A235530B05B76EULL, 0x8C3A98BED24D7581ULL, 0x326C2DFA5C933F02ULL, 0xFD0250486BFC9167ULL, 
            0x96C4FB118C304B89ULL, 0x05CE7268438AF21EULL, 0x79C63385EB3930E8ULL, 0xDBC5511B83EE43D7ULL, 
            0x886FB77E4FD3C5C9ULL, 0x61DFF00ADB53399CULL, 0x0B74AAE2685778F6ULL, 0x024DA723954ABBDFULL, 
            0x50EA21958E6468EEULL, 0xAE80DE9AA80F26D5ULL, 0xB6A4061285F13DE5ULL, 0x6D5B6162A42CCF4BULL, 
            0x02C1822EB7C4AEAFULL, 0xE330460BD282555AULL, 0x9320FC8F4ED687A6ULL, 0x46D030CAACCF24D6ULL, 
            0x243A4F4151C93872ULL, 0xF2BA57EEA4950ED6ULL, 0x83E487EDD9F1BC9DULL, 0xB7660CBADC0193DBULL
        },
        {
            0x51FC38171757A3A5ULL, 0xD9E37392A03C36D2ULL, 0x841208AD493892A6ULL, 0xA96CCD6DFB91392CULL, 
            0x0248FC626D563071ULL, 0x85A4A4CED11092F7ULL, 0x16EDC8076493F169ULL, 0xB9E6A06F75DD17BAULL, 
            0xA1196B3D33454D88ULL, 0x6AB9ED9019BE7C6AULL, 0x1F690D35C644AA9CULL, 0xE5AB08FCCB7D8B4FULL, 
            0xCA3FC9B4A3FEA507ULL, 0xBA1F120175486423ULL, 0xA0A56C42E6CA03A7ULL, 0xE09BD939EE7923B7ULL, 
            0xAD4700EFB259CCFCULL, 0x73614AFD2986DD6DULL, 0xE6DAF80958A9AE19ULL, 0x78BA3279CEF053CFULL, 
            0x6ED704FECE88632CULL, 0xD5C7620C3F16F8BAULL, 0x3D8B01132D01DA81ULL, 0x81C47C1F57D89BA0ULL, 
            0x2A18784584EBFEF6ULL, 0xFAEC73EBDD0AA5CAULL, 0x103B0345F74DFE51ULL, 0x1FA4F86D26EA4C0AULL, 
            0x0BB7A7DFF39E3A99ULL, 0xFFEB90327AACCF6FULL, 0xC80D89E6C392F007ULL, 0x5D03D329F77A2027ULL
        },
        {
            0xD2BF2475063B8B3AULL, 0xAB5FD380C4482B43ULL, 0xDF47B5839D093A08ULL, 0x64CD892E71F5E5ECULL, 
            0x9BAA6C80DE21441FULL, 0xBE204CBA9930305FULL, 0x5224A89AFC0156DBULL, 0x55CA67C172701027ULL, 
            0x06810C99274BB456ULL, 0xF5EE54D837DD9B0AULL, 0x8FB25E2BB751B926ULL, 0x474B081E1D969337ULL, 
            0x30954C88ABC66C65ULL, 0xA1D9BD5175B6BACDULL, 0x03942E426EA81307ULL, 0xCE5EC6655E9E7C3AULL, 
            0x0E6BD38EBB73512DULL, 0xECE3B7AF683EC444ULL, 0x581928C3C23318E1ULL, 0x432BAD07FA575F2DULL, 
            0x0C24AE8AE09E61ADULL, 0x748538F076221396ULL, 0xFFCF5BA0B04A3279ULL, 0x03A48B689382FCB9ULL, 
            0x84DF3C7637A4BA9DULL, 0x547ACD5BB63E1F61ULL, 0x84FD358503A77337ULL, 0x4A3CC6510415252AULL, 
            0xB6DB874EAB5B7885ULL, 0xB549871169C67521ULL, 0xF7AE718D93E506E6ULL, 0xB7961D2B11D44157ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseAConstants = {
    0x4699A054F8886A9BULL,
    0x44F6F595DD450BEFULL,
    0xEE86E86469A4D951ULL,
    0x4699A054F8886A9BULL,
    0x44F6F595DD450BEFULL,
    0xEE86E86469A4D951ULL,
    0x5C7CF7D92B73E6E7ULL,
    0xB13F092D7EC41FE7ULL,
    0x5C,
    0xFA,
    0x22,
    0xF7,
    0x6E,
    0x62,
    0xF6,
    0xB4
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseBSalts = {
    {
        {
            0xF8A974525A9AA355ULL, 0x32BBE0707E05A438ULL, 0x8E7313FEA677CDFAULL, 0xF144B80528C2F24CULL, 
            0xD2CB31EAAC12D7C9ULL, 0x58C7FD807A5E2C19ULL, 0x82740871A8AB5552ULL, 0x05608375EDC19AE1ULL, 
            0x079A6315DD0FE3EBULL, 0x276DDE5079990723ULL, 0x02153C84EC22ED31ULL, 0x72AFD98BEB023D10ULL, 
            0x3DEDBD6C30F6E5EEULL, 0x688770879D12AEA4ULL, 0xACC6B9FFE653903BULL, 0xFAE9EA03460E62A9ULL, 
            0x42BE7561DB01C5AAULL, 0xF0A0A387F782E0D3ULL, 0x3182211491034FF5ULL, 0xCD87F7252AB83F5CULL, 
            0xB76D694C16F38BEDULL, 0xF1194C983E70457CULL, 0x04B245E19941CBFEULL, 0x9B1A43F7FC4105DFULL, 
            0xA28156208F4495A1ULL, 0x17E7A2D958672821ULL, 0xEBAA805CF6144CB0ULL, 0xE1763201B567CCCFULL, 
            0x4F3C2D07BCDEDA42ULL, 0x56F9B51001C8CCDFULL, 0x1DA4FE7AFF42F20CULL, 0x8EE8A4BF9D28A9E6ULL
        },
        {
            0xB360A9C424E60222ULL, 0xE7971FBAC5E9AA44ULL, 0x14A5BF936EAFE546ULL, 0x360D239E756B88D2ULL, 
            0x2F4C259416C0230EULL, 0xA6CB9057FEA33761ULL, 0xE0D613861EDC883FULL, 0x05E13B5F4B2C7C29ULL, 
            0xA42EAA49FA9FF19CULL, 0x5CBCBD49435DE867ULL, 0x172BAA4D3A07FC4FULL, 0xCDD5B1B03EAAD0D7ULL, 
            0xE98784D4829A3E8EULL, 0x00AE6179F8557C88ULL, 0x3F92A586813224ACULL, 0xAAA72A368A203493ULL, 
            0x4BA456ABC69CF562ULL, 0xF9DC674656F887A2ULL, 0xC8D67268C1BD07FDULL, 0x3AF4B828AC84CF94ULL, 
            0x1454A0C3F9E45FE0ULL, 0xC3428E865C15A05FULL, 0x519F98B7F83CF47DULL, 0x254D19E36F6288EDULL, 
            0xE140E6ADB56A1758ULL, 0xACB23862A94D0B06ULL, 0x0EEFF172B0DB9364ULL, 0xADF0E0E2B78E977AULL, 
            0xD8CF530DE398A742ULL, 0x14E594B292EB392BULL, 0xC7016946E81B8DCFULL, 0x87661EECE1A4BC06ULL
        },
        {
            0x0A3B57563417649AULL, 0xAC51927C76FA9CE5ULL, 0x5F38F6F859FF17B2ULL, 0x6794CA8A96CFC5DCULL, 
            0xF5B784CFAF0D07F8ULL, 0xC66AD053472D76B2ULL, 0xECC2A1FDD94376D8ULL, 0x03AA3229D3DCC45DULL, 
            0xBDE36B0F2F29F321ULL, 0x85BC380C248F5DFCULL, 0x8CE4FFC36DC34904ULL, 0x13D0BB914FC58A2BULL, 
            0x27605DC26B68FE72ULL, 0xDFFF7DB725F1FCF0ULL, 0x4C377FF494538FCAULL, 0xC2307D5B6195C445ULL, 
            0xBA40370D1B3FC8C8ULL, 0x6AD79802FDF535EBULL, 0x36797E206B1BD066ULL, 0xB45536A97A3D8B6AULL, 
            0x458D6C94A525DFA5ULL, 0x36F155870D32154AULL, 0xCD5E6987343B7BC9ULL, 0x0ECEC6C6A0E99659ULL, 
            0x5A3BFFED55CF74B6ULL, 0xCDDABD5F51106F73ULL, 0xA32D4FDDDB4186F1ULL, 0x0B175899231CD248ULL, 
            0x884F03240E87CEA3ULL, 0xB584D84E50F64396ULL, 0x0E8F8E75EC9A3109ULL, 0xFC1B0BBEF108DFE8ULL
        },
        {
            0xA818D745808F1510ULL, 0x3DB29FC3C1F927EFULL, 0xB8CF28A552FC5FDDULL, 0x64798BFD3E374E89ULL, 
            0xB044C1483B5E659EULL, 0x3AE6EC2BFB7E82FCULL, 0x51FB70AFAA3DC966ULL, 0xDE3F39EA4CAF60AFULL, 
            0xB35B86162E8EA4BAULL, 0x02E617B357E36891ULL, 0x5A72844E089E0444ULL, 0xD3B2D072408BBA13ULL, 
            0x106F2DE9A891431FULL, 0xBFDE375838D31A3FULL, 0x0287E4ED5145A666ULL, 0xAC5D207AAF03B4EAULL, 
            0x1C3663560F19CE1FULL, 0xED5872D9C2322DEEULL, 0xACB211A2D82BF188ULL, 0x12A76B862B02833AULL, 
            0x586D2083EB9EBD20ULL, 0x7852DB75B29CC8FBULL, 0x738613BF33BC934DULL, 0x3E20149E8E68DE11ULL, 
            0x9779033E149EF929ULL, 0xA6679BD847247A4BULL, 0x88DAB03258E43E4CULL, 0xAE40FB019EECFBDBULL, 
            0x503E55862139B264ULL, 0xFA0ACB31D591B9A8ULL, 0xED27F7DA904F317CULL, 0x230DFB189F688DEEULL
        },
        {
            0x5CF034D2996E7F21ULL, 0x3EAD688F974BE309ULL, 0xB4E756022556A798ULL, 0x04C4CC26190CDB4CULL, 
            0xAACA612B19311406ULL, 0x048C1566A3D424A1ULL, 0x6E6BCDE86A3BB3F2ULL, 0x1C41360E00465B8DULL, 
            0x515D2FECFE7B3547ULL, 0x122C8B8427DB0304ULL, 0x7083C4B1B711B34DULL, 0xBF68A56EF27576A4ULL, 
            0x9BB249065E1E3E0EULL, 0xCD15FC1FDD12754FULL, 0x82685AF56B5C0F58ULL, 0x32E5E6E0D3EE14E8ULL, 
            0x58A5294B120567BEULL, 0x913382BAD4EE7802ULL, 0xE50E3CE1EA5D2770ULL, 0xB52978B8ADA54FE2ULL, 
            0x91F20D5E5A9E63B7ULL, 0x180B1FBA2F3FF768ULL, 0x928B775323554852ULL, 0xE57D40F453DD1FF0ULL, 
            0x23ABEFCFB1DDE331ULL, 0xF3C51721973E8E47ULL, 0x0DFD673686A9F809ULL, 0x653427C558612AD3ULL, 
            0x86A8B947679E9F4CULL, 0x33F515048593F2E2ULL, 0x9B5796245E06D98FULL, 0x28C4B4883D013912ULL
        },
        {
            0x3DACF4D11CB7B788ULL, 0x69C49709B6CFA968ULL, 0x85BC93533A400544ULL, 0xAD7D93E3D40D353CULL, 
            0xEF1D831A4362A5F6ULL, 0xFEC4A619C03CEC42ULL, 0xC2CF2B9EF9811E9CULL, 0x6B9FEC7EDBD07B2DULL, 
            0xB51E8A0F07A3BE5CULL, 0xB8BA6350D7DF1D70ULL, 0x9A96C0D00B2A7020ULL, 0xED91F6B1B524E035ULL, 
            0xDF270D6C1ED0996AULL, 0x605731EDB5C51690ULL, 0xA1B2B73B22D925B8ULL, 0xA4371A90525364BEULL, 
            0x04E2600B971CF1E5ULL, 0x2E92695EBCAFC706ULL, 0x2EF86A32DF28952BULL, 0x4D2F3DF9FE4D70DAULL, 
            0x91E356F6A85EAAD3ULL, 0x3562793AF05DAF5FULL, 0xE91F2247AEA50E2CULL, 0xC826DBE4C224B3F9ULL, 
            0xD1BE73C954AF083DULL, 0x7D3525B22F5E4692ULL, 0xDAA535B3292451B4ULL, 0x39447A70F401251CULL, 
            0xA8D1717CC4F7E641ULL, 0xC5A616B5CAB934BBULL, 0x845E99B0C166625FULL, 0x96FB1349C9A7DB67ULL
        }
    },
    {
        {
            0x82C6A959E41A536BULL, 0xB1377BF49C255882ULL, 0xBC81ED002A00DA2DULL, 0x45B6C7F4AEB1E64FULL, 
            0x36CBCCB41B8B013DULL, 0x7E4230525C2C2D82ULL, 0xA38CB1DD5666DA5FULL, 0xA6502EFEBC5886CFULL, 
            0xD47A4D992DC74C9FULL, 0x7239B966DC8DB18FULL, 0x542D3C9726F768F8ULL, 0x905E4821BC1F94A3ULL, 
            0x5F673C1F8B619EC1ULL, 0x133468BA6B864D5BULL, 0xCCDE738A9C0D0140ULL, 0x17704F39E59096FCULL, 
            0x66DC2BC5561011C6ULL, 0x8FCFB0725D572822ULL, 0xEFC1D9FA5B1452CEULL, 0xC3DAB45F5FFF4BCDULL, 
            0x0E1CD97004D4F39BULL, 0x1C31BB8DF325C3A9ULL, 0xB0444C76B68BCC34ULL, 0x626FED300B18BC39ULL, 
            0x117B43720C42B5D6ULL, 0x594D3CAE696B3D8EULL, 0xC70BB3B2400EF00BULL, 0x08227ADD0F437773ULL, 
            0xB56160A4475244EFULL, 0x2992B89B47B54C56ULL, 0x685ED91154279BC4ULL, 0xA05425EE0F5466E8ULL
        },
        {
            0xE5DAFA1FA1276689ULL, 0x5ACA8AE76FABD5C8ULL, 0xF5488792EEEE5F9DULL, 0xAED6D09CA050054BULL, 
            0xB3969B0E95B47532ULL, 0x8B14EEBD4905B91EULL, 0x49B590FDA79FC757ULL, 0x00D5BC44F60E5EFFULL, 
            0x4D627FF729B0DD29ULL, 0xEE34849AEE468AB8ULL, 0xF53A361A1FAC0473ULL, 0xFDE0CCAC956D4BADULL, 
            0xD019AE0A951821C9ULL, 0x855126FC034782F6ULL, 0xBEADA5025E9DEB85ULL, 0x2D0D35FF9F0C7FC1ULL, 
            0x95C913C8410E3C33ULL, 0xEEFA62BF4F99C385ULL, 0xD1A4BA50E7C2B851ULL, 0x77C9CD79015F7766ULL, 
            0x4AD4A90C75A937D7ULL, 0x6C7FCF80750913F6ULL, 0xA978591BF9D1FA69ULL, 0x30944C8A3685B21DULL, 
            0xC6BDA9870F659A82ULL, 0x80C93B89EC542BF9ULL, 0x7B14B32ADA3C7CC3ULL, 0x4C5B420F4B0EA4B0ULL, 
            0xA977607B83512AFDULL, 0xFB4C9D4ECE868781ULL, 0xF60CBC2232064035ULL, 0x945D465D05900C0DULL
        },
        {
            0x0161E977D657BA8DULL, 0x6697456B18510C83ULL, 0x7641B8EFA57E1F30ULL, 0xFB006A77F7C17E36ULL, 
            0x926D51CE17100C10ULL, 0x22A4E320C34AC376ULL, 0x474D411004C299BFULL, 0xFA5E4956447817ABULL, 
            0x4E571A8DE426BC86ULL, 0x1089BEBA1059E069ULL, 0xE79DF5EDAF8452ECULL, 0xBCE5EEA6DFFF5404ULL, 
            0x36FE2B5020E9B349ULL, 0x4FD4C998BA0DA93BULL, 0x1F5C8B17C1196D84ULL, 0x6178A8B7EC1DD3C0ULL, 
            0x24B9A5118E37896BULL, 0x3C1D629F3F92F606ULL, 0x645FCF5E7FFBABDAULL, 0xBCCDCAEB7ED10975ULL, 
            0x0D87CD03FE7F2C40ULL, 0x5B7D94B227C95B70ULL, 0xA0A97FCD50950CE1ULL, 0xB91EA5D4E1825AE8ULL, 
            0x995EB78C9B8BC335ULL, 0xF6160E7990F5EB3FULL, 0x0191DEA7BD5648B0ULL, 0x2EE8F26E49AA48A8ULL, 
            0x335AB14BDF6D0405ULL, 0x6202FED99F08FC25ULL, 0xBFB01CDE2DB8F62AULL, 0xF9D2E1D99CA94C1FULL
        },
        {
            0x3D918E3B94AC37C7ULL, 0xFFC240E328F6DE94ULL, 0x4D7CC153193ED33DULL, 0x057434D01CC16854ULL, 
            0xA11EAC47ECFF957AULL, 0x27B1CCF49B96DCD6ULL, 0x750CDDB7046EFAECULL, 0xA3B958CF55FBFFEFULL, 
            0xE5C59E4CCC40DF1AULL, 0xE0F44EC9843D7757ULL, 0xDDE7689285FB46D2ULL, 0xB93BEE6DF0DDA14DULL, 
            0xCA2576EBF6541BD3ULL, 0x1511B144199B4CCAULL, 0xDDCDE684D03BAAC0ULL, 0xE3BE94C450E5A0B8ULL, 
            0xB349FFBDB59DAC60ULL, 0x9182668BDFDBE412ULL, 0x70236F9DF278BD7DULL, 0xF65CC6C2A431C6B2ULL, 
            0x05A9D0A19128CE9EULL, 0xF8EE5D4EDD5B2463ULL, 0x00987ABE4F6FC7C0ULL, 0x3E133C80F118E348ULL, 
            0xE7A3528FB679C361ULL, 0x4CE95A98A8188535ULL, 0x42F4EF15159506E3ULL, 0xD79E858799DF3585ULL, 
            0x5200AD4C73112D2DULL, 0x248D70841F77ABFDULL, 0x1E81315E1EF80F70ULL, 0x86EFB88025156C4CULL
        },
        {
            0x23F1DB0E4A871E3AULL, 0xD4E219EC67E93165ULL, 0x571E4DC6B217701EULL, 0xA7F10D8B84C4C926ULL, 
            0xA7F5CF42B3587BBEULL, 0xA46303ACC7E9C88DULL, 0x43D7AFB44D074AABULL, 0xCE7403F7A4BD4EE1ULL, 
            0xE981C312C633A06AULL, 0xCDB8BD870F6B5CACULL, 0xFDE72F576BF5AD24ULL, 0x4A8CCFEA995E8557ULL, 
            0xFB25194B9711F94FULL, 0x42E69FFEBCBAB102ULL, 0x7301085387867794ULL, 0x93246A5DCDC85F39ULL, 
            0x7AA63757E7BF52BEULL, 0x39EF069F2D43962FULL, 0xF6E8DEB7ECDDC2A9ULL, 0xB69376F9C492C136ULL, 
            0xF8F8FA51B84BB141ULL, 0x97D8FDE475ADFF79ULL, 0x0A23F278B082D176ULL, 0xEACC6F079A04E571ULL, 
            0x1CA5661F9A1CC6DCULL, 0xB5E4891DA6461238ULL, 0x17BC05C88DB17F47ULL, 0x1D53F9E9BC209042ULL, 
            0x2DD2B207A880D8BBULL, 0xA0D35F4A18E924B2ULL, 0xD6D201910F1B1FD6ULL, 0x1E018034D8691E45ULL
        },
        {
            0xAF7A83E52B608864ULL, 0xD85D38CC18264653ULL, 0x5BD1B1A82987D5BAULL, 0x15F3A52421C3A2B1ULL, 
            0x1206E1532C4585EFULL, 0xFCDC7082A252DBA2ULL, 0x8E1B714AC0CFF116ULL, 0x1AC4A006501D1EE5ULL, 
            0xAA4F99D3F6F08EDDULL, 0x4F1E273E9A1C7D7FULL, 0xFE9F61C0895723D7ULL, 0x00D7008C23C54A50ULL, 
            0x850FEC04F4D50B80ULL, 0x7BCC38C9551A94A5ULL, 0x0CDD5016DB5DD7CFULL, 0x070FC3CA8C416BF1ULL, 
            0x012C47C9FC151297ULL, 0x17376437109840C7ULL, 0x361302CC07D20A87ULL, 0xFD11C9A9215E8A61ULL, 
            0x2AB13730A50E92C5ULL, 0x594CBE2ED9DE9CFFULL, 0x7DEC099F6341EB4DULL, 0x82EDA269EDAF3893ULL, 
            0xD139AED267269FFEULL, 0xFF12E50A88EE0326ULL, 0xF7B96717608BEE56ULL, 0x5AED15AA4F665ACCULL, 
            0x4988477FAAA24AE9ULL, 0xC78BA5D70DE1310EULL, 0x918F6001FB67A327ULL, 0x0439AF36485B365FULL
        }
    },
    {
        {
            0x83EBF417B4ACB2D3ULL, 0x8A081EC975B6317BULL, 0x2ED0FF7CB1948673ULL, 0xBD236F9CF17D20B5ULL, 
            0x954C8C81BF87B27CULL, 0x53BDF968AC7C0C78ULL, 0x236C6F1DD2CFCF7FULL, 0xF84E0229A358452EULL, 
            0xA3597A9DA085CDC5ULL, 0x2F7D9493F08D73BDULL, 0x925DCBA34F8985ADULL, 0x1C32CA4B31466E20ULL, 
            0x1E5A9DB4281E7D0AULL, 0xB4C3F01992FFE557ULL, 0x505FD1420459A847ULL, 0xEBD527C4B3C297A8ULL, 
            0xDDF0B0B7C0691791ULL, 0x00DAA5F95C441A46ULL, 0x5F7E88704E50130AULL, 0xF10DDF0819EFD1B0ULL, 
            0x8939E334B5DB0CEAULL, 0x78A7FE0540585B7DULL, 0xF71DD680A6544FEFULL, 0x9B194E2EBB265FDBULL, 
            0xF7E8AED2635B3F48ULL, 0x9F275CCBEB970C17ULL, 0xAB2D3DC39E693706ULL, 0x5CC70548968E1A24ULL, 
            0x4CBAC3346DFD8BA9ULL, 0xAFE009E779BFDA18ULL, 0xB2DE1C6425B1396AULL, 0xF6924A3278A1A83DULL
        },
        {
            0x769187DD13E7C470ULL, 0x33553EF63EEBF214ULL, 0xBD37A7535B0AAC10ULL, 0x772163DB094CFDE5ULL, 
            0x92AA9ABB10050A2FULL, 0xEBE56C908F47F48FULL, 0x7AF558532C44418CULL, 0xF83D80EC25DD1E63ULL, 
            0x5C288729557B42D4ULL, 0x8AEE48A83EF43CAFULL, 0x7FCB7E631FE1BDE5ULL, 0xBF4EEDF645BCDB81ULL, 
            0xB32A6746D7C21002ULL, 0x346859198BA09B50ULL, 0xDEBFA79343E56867ULL, 0x02F8FD2319D48205ULL, 
            0xB16C1313372619CCULL, 0x37349A0C9A5B5013ULL, 0xB53B3B04D0AAEC49ULL, 0x962FCF05E5F98BAFULL, 
            0x6BE98AE8B40B514DULL, 0x43A3854FFF6B17A1ULL, 0xCB9DF977DB55803FULL, 0x75396588E35C6AA1ULL, 
            0xED85491042D88332ULL, 0x8434E1CE11C3AD62ULL, 0x37CEEA320B858195ULL, 0x49E2267E1611020CULL, 
            0xBE480534F9AB7D0FULL, 0x41C8370E80F2E51BULL, 0xB1E1A15C20431325ULL, 0x11873BEB4AA297F6ULL
        },
        {
            0xCCE36CED0898638CULL, 0xEC927315CD4A5631ULL, 0x042AC8C9B7BB868AULL, 0x3DAC0F55C29E3679ULL, 
            0x8DB7CD33BFE9E207ULL, 0xAD0F17C2D7533DA7ULL, 0xF4E39C5044213A73ULL, 0xA94986A94B944F33ULL, 
            0xFC4CBC4D43D57773ULL, 0x26FB4DFCDBB75D57ULL, 0xF44F3108FE7C194CULL, 0x350401BADF32D32BULL, 
            0x8FD976FADB0C1904ULL, 0x7F7A74EC82D1D68FULL, 0x0253A359B9312113ULL, 0x5675313621B4D5B7ULL, 
            0x5FBA1DBE2991F20AULL, 0xCAF2DF63E5C53264ULL, 0xBCD322010788EFC4ULL, 0x17E873CFA9B763E3ULL, 
            0x9DA952A4037B95FBULL, 0x560D64B69EEF6F57ULL, 0x3211FBEBFD8BEBFCULL, 0xFA4C6AC4465CE20AULL, 
            0x475B8AB0A24FB4F3ULL, 0x388E893D4DE00796ULL, 0xCF49686E344437E5ULL, 0x4C364CF3AB473E9EULL, 
            0x43F711008FEE03A2ULL, 0x2A03AA9D3C2F70B1ULL, 0xCF467A94D9833011ULL, 0x3B6EC415D85E83C7ULL
        },
        {
            0xCCB4B303E9EABA13ULL, 0xD3C8F08F3C003DB0ULL, 0xC3E0CAA0B361E7DDULL, 0xFE405F5935991541ULL, 
            0xBAA06A310F118300ULL, 0x035677D1FD343588ULL, 0x67154112BCFEDC18ULL, 0x60403CF30A9D6C30ULL, 
            0x6372B7775F51047AULL, 0x65461A00442A583DULL, 0xA7230BE6F3D88061ULL, 0x85D965E10E848191ULL, 
            0xFB258CC4844A67F5ULL, 0xA37E58B0E2C9DD40ULL, 0x701013055B657C3FULL, 0xADA66207E8A1700DULL, 
            0x7765E1AF50D004C1ULL, 0xA6A7A64A49AAF751ULL, 0x9446EB64608E3E3FULL, 0xFA73B966580FD918ULL, 
            0x8197D6C5B334B819ULL, 0x281C16C1917A0EFFULL, 0xF01334D2DC1D8159ULL, 0xF366A472D82F5CB0ULL, 
            0x92B8BC55D795CE28ULL, 0x10BC42C552B336A1ULL, 0x06AD356A8E4B435DULL, 0x143D6A2C6F1475AAULL, 
            0xA3A80BCFB455D433ULL, 0xB4D6C8D162727179ULL, 0x02FB730F7D6EE59FULL, 0x0E92853BDFD8524BULL
        },
        {
            0x249B8C5459DC5D06ULL, 0x6BA6FCDD427409FAULL, 0x15D1D6F5A47F895EULL, 0x0BFD033DBA6BC385ULL, 
            0xD1B68EC1C70AF464ULL, 0x3EAD6B1B043591C5ULL, 0xC93987289E9EA250ULL, 0x173A3F0CF21230E1ULL, 
            0x666F2CA911FEB2DDULL, 0x05688B8F9A5E7792ULL, 0xADE0629D076F9F8AULL, 0xB8B4B3BCFAAEC803ULL, 
            0xAE1450E3D7C6368AULL, 0xD21A7491D0635164ULL, 0x7E551AC56BF6567BULL, 0xD9B9D3645ED94CDCULL, 
            0x9FEEB688F294E169ULL, 0x9F7F145B78457CDAULL, 0x11040C92BDB93621ULL, 0x4245F3991C893247ULL, 
            0xAFF681F91873B33DULL, 0xEB47598F8CD86409ULL, 0x52077E8FF9923FF7ULL, 0xFD9E03F9739573B7ULL, 
            0x1C4CB801022C8B6EULL, 0x744ECD375FF0F53FULL, 0x0443C938CDEC905FULL, 0x96D9F49144DE7B0CULL, 
            0x4860EAE6179DE98EULL, 0xDFBF84B1B9144F0EULL, 0xCC28883251D2D9EFULL, 0x421EC5712B8E4B05ULL
        },
        {
            0x8CB6E3B444BEB257ULL, 0x858DC215D840FA87ULL, 0x0FE529121900EBAEULL, 0xA5F5EA9179CF4BE0ULL, 
            0x9ABC83AF9C3DDB12ULL, 0xC18EBDEE08F5AA6AULL, 0xE13A37D34419779DULL, 0x30310E0752B36F8BULL, 
            0xBA5A60CA710BB939ULL, 0x9599006124DFC795ULL, 0xDFB755364789F68FULL, 0x7BE250515B24E1E7ULL, 
            0x150174548D6DEA93ULL, 0x9862E6280B3E60DAULL, 0xACFBD6DE1BBBD045ULL, 0xD62897206A702189ULL, 
            0xD8D51EBE7684F0A6ULL, 0x01B33EA298B555B2ULL, 0x163BAD3DE4647291ULL, 0x9806D05B0EE46F36ULL, 
            0x5C0E88BBF704158FULL, 0x6C0380A2631C1241ULL, 0x6D28DD359666273DULL, 0x67EFC02043434EC0ULL, 
            0xB1D1FDC3E8155B31ULL, 0xEDF307AAF061FBBFULL, 0x5775613EEC1F60D6ULL, 0x1B402BEB70141359ULL, 
            0x62A1ACB5050EC47DULL, 0xEC8E97B867176F6FULL, 0xFC59A41F011C2BF1ULL, 0x4E526D62FF5FFE69ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseBConstants = {
    0xE3A21FB20E0685BFULL,
    0x60EBCCD9A74EE70DULL,
    0xD53B733EA7AD5CB5ULL,
    0xE3A21FB20E0685BFULL,
    0x60EBCCD9A74EE70DULL,
    0xD53B733EA7AD5CB5ULL,
    0xD7F1A184ED842475ULL,
    0x6C298CAD39E3B79DULL,
    0xF3,
    0xDD,
    0x40,
    0xD6,
    0xFC,
    0x60,
    0x6A,
    0x7A
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseCSalts = {
    {
        {
            0x5685F978B2E06829ULL, 0x986353198010F19EULL, 0xEE910241285F4B55ULL, 0xE8E70BCDEDE2831FULL, 
            0xA3FABC323798A79EULL, 0x3DD2F80AE21B5D7EULL, 0x767E614DAB2DB774ULL, 0xAF25F6A68B192E90ULL, 
            0x97036D15798F10D8ULL, 0x3C3EFF76F20FF652ULL, 0x84EC79EBDAA7521DULL, 0xC21A4F9C9655D2B6ULL, 
            0x20FA76ED5BA68D5BULL, 0x33F67A5BDEBD0C8DULL, 0xAE9190C06C3C9BEEULL, 0xE9D44D6A513278ABULL, 
            0xD7B93C09A8F98558ULL, 0x65ED5134FE00732DULL, 0xE569D31C00CEC77EULL, 0x6E6929BF403AC507ULL, 
            0x227974E8BD4FA25EULL, 0xD7BD02A25BF8D10EULL, 0xA625A7BF3FF35F72ULL, 0xBA696E045C4FD635ULL, 
            0xAE68B553CFC099D1ULL, 0x866C095F20058512ULL, 0xB4A134022C979CB4ULL, 0xDF984FAF35D014EEULL, 
            0x2A9387741A25FF9CULL, 0xDA6F3D07A81F41DFULL, 0x4AC87564B18FE6C2ULL, 0x05A9B6F379360CA3ULL
        },
        {
            0xD2B205146EB71D12ULL, 0xA56F50B618EA256FULL, 0x4DF7917C79347619ULL, 0x64CCE1D9EBB680BFULL, 
            0x216B3D393202BF46ULL, 0xCB7CB3A8FF2751B9ULL, 0x5D2502F82D3941FCULL, 0x9CDA45927FDFC6A4ULL, 
            0x1DC467DA38AC9E2CULL, 0x2F84E63613B8A4F1ULL, 0xBC02BE89B83B3EFAULL, 0x0A69AB62D37AEEC9ULL, 
            0xEA57D60B98C0AE38ULL, 0xB5103AA8E2F13222ULL, 0x8B6A72CB322502ACULL, 0x22CE5E5864ADE1C4ULL, 
            0xE50B60F953E81F40ULL, 0xC7BF9BA6A7AE91E4ULL, 0xAB26ADD4046B06F8ULL, 0x0D008582E2F1FA08ULL, 
            0xC0DD1FE8E58D304EULL, 0xA1AAAFE4B6F230DDULL, 0x0900EE2645A49337ULL, 0x15C74FD69B88CA2DULL, 
            0x9C0AC7BF65EAAC18ULL, 0x6B84E7599F18E45BULL, 0xCC15E79F46C9F427ULL, 0x2BA9A56BA7B5C967ULL, 
            0x81278B57BCA91F88ULL, 0xCF051C4FA7A4204DULL, 0x1148F4C8FBAEE224ULL, 0x023D87E07159F10EULL
        },
        {
            0x0D988BC007D3F698ULL, 0x72A8F56C3CB95ED9ULL, 0x7B72357944CA8131ULL, 0x5F05B9F30A942EE6ULL, 
            0x4D047095C646E6B3ULL, 0x9D2BFBC46FC9B040ULL, 0xF609279AEE523232ULL, 0xA407C0821AD50ED0ULL, 
            0xC82563A062B214C7ULL, 0x2A2418B4CE52E725ULL, 0x3EC87A279FD5BE6CULL, 0xE4B63B65BB1E0B0DULL, 
            0xFF7227E5443512A5ULL, 0x13A6AAD75042DADDULL, 0x1512197B40DABF53ULL, 0x422DF9787D3757BEULL, 
            0x35B547179500CA15ULL, 0x7549C2AEACD3FF81ULL, 0x9D1A5B53E1AEABE5ULL, 0x43CAD844E0BE5B7EULL, 
            0x1BAE671EDFBC08C8ULL, 0xC1589FED9A710002ULL, 0x5B9ECF42671E0637ULL, 0x00A63B62E243D877ULL, 
            0x3EE6C1908DED09E4ULL, 0xED644515794AA31EULL, 0x7159078F8AD7F5C0ULL, 0xB1A912F322DC069CULL, 
            0x3CF942F87F299176ULL, 0x8909F940282DD5BDULL, 0xAE929DF20D241FD1ULL, 0xE0589399EB12D986ULL
        },
        {
            0x781BB1F3D9B52519ULL, 0xD87C63B3B59AC045ULL, 0x61039EFD77D8D0B3ULL, 0xE0F4AC518A90043AULL, 
            0x9650F336ACD988ADULL, 0xD0D50C9E47D8DC74ULL, 0x99BC5424E317A603ULL, 0x7D7A9B7D4D567BE8ULL, 
            0x1542D288A99ED53CULL, 0xD5D0A04C9C6426CCULL, 0x277D2525EBCEF002ULL, 0x630B9B3AC1161189ULL, 
            0x4C74425B943D3B2EULL, 0x14ED1A772E700DFFULL, 0xF8CDED5AA8A9524AULL, 0x21C8C651E03D12C5ULL, 
            0x3B31B1DA363965A2ULL, 0xAB20AA3EB753C53AULL, 0x8D513DBEA2517F35ULL, 0xD3DE0D0DE25C995DULL, 
            0xC802A70922D06318ULL, 0x8969E34E0347D352ULL, 0xA5BEB0F1752AB828ULL, 0xC7AB3657C5BEC90AULL, 
            0xA1DACA8B8D9877B2ULL, 0x745E48946B3EA1C2ULL, 0x9DA30BC86AF8D3D5ULL, 0x1C4C3DC4F865315BULL, 
            0xDBB74638371DCD95ULL, 0xE62EAB58D60A7019ULL, 0x62DF7A1E585D8B28ULL, 0x5008E69C9031C007ULL
        },
        {
            0xBAE5BFD8BB88C7E2ULL, 0x79764FE720443D5CULL, 0xFB8DAEE348A36694ULL, 0xC406F51F40C34956ULL, 
            0xA122E15EDBE3C03BULL, 0x0DA007029553EB22ULL, 0xD84B21BE20C4AADCULL, 0xAC95BEABAABFF3A7ULL, 
            0xADF0D818844F439BULL, 0xA0057E39B8B1C7EBULL, 0xA475E8829FEDEDB6ULL, 0xD5E8B4DF7C1D02FDULL, 
            0x6A3029EC37E24FDDULL, 0x6CC8E5A0C239036DULL, 0x71CF3901693700BCULL, 0x130D3A6D67D9A9A2ULL, 
            0x5E85AE9BCB601673ULL, 0xA69D52A1F8E4126FULL, 0xD2F6D7F53B0AB285ULL, 0x7054AC505D0236C8ULL, 
            0x9930A60267F48582ULL, 0xB4F0A386FEB476BCULL, 0x4DC4233E603B3602ULL, 0x69F335A705950846ULL, 
            0x64B3378FAADC4664ULL, 0xC90B7D8EF09B0727ULL, 0x20BA1C35CE5C7CF9ULL, 0x1E8ED31BDF51E00EULL, 
            0x26853E8802AD2C01ULL, 0xE94B2DED91A3A917ULL, 0x00A6162E6DB3B72FULL, 0x5C478B2FBB54043CULL
        },
        {
            0xBA4E60E0DAC57651ULL, 0x8D5A44DA128EFBC2ULL, 0x5231E951EFF618CAULL, 0xF59DD391076685D1ULL, 
            0x2F83FB1D519E17ABULL, 0x52BDC678325952B0ULL, 0x17950D9375BA5BEFULL, 0x4ABAF10A8CBD8A1FULL, 
            0xE9D19C1C692C3928ULL, 0x7F7BC66C275AFDF2ULL, 0xBF0614BD7BB8913EULL, 0x374B9BFB6A592BB3ULL, 
            0x058954661A4DDC90ULL, 0x4F014561B5BA25FAULL, 0x421DA02F2F03DDDEULL, 0x82DA42E69E7288A4ULL, 
            0x8987117CAB56C19FULL, 0x1C56B3F72ADAF1B5ULL, 0x9260628990233741ULL, 0xA5CCCFF6F767331CULL, 
            0xC609439F1D67FE80ULL, 0xD45431B5B9FADA2DULL, 0xE0B361A138E47755ULL, 0xBEF346C3F1838B75ULL, 
            0xD4F885821624D98AULL, 0x331DE5E8B09AF609ULL, 0x06B4F5C0812B9860ULL, 0x080183F4BF26734AULL, 
            0x1F6D187F3FC36228ULL, 0x7DE562765FDF3032ULL, 0x838B80028E68645EULL, 0xE2DA33D78AF69D84ULL
        }
    },
    {
        {
            0xD9E87D066D871CC2ULL, 0xBF4844F4A8348C4DULL, 0x15B21F4A1FE790F3ULL, 0xD803BDA7A847CBA8ULL, 
            0xAC204CA70FE00CC0ULL, 0x4D9E78E1B25E347CULL, 0xDC674D7F9DB84CE3ULL, 0x1ECA6210A7C66DD1ULL, 
            0x787EFFF88CF108A7ULL, 0x21E305B2D7D5BEC9ULL, 0xB3256344A08301E7ULL, 0x2B9406B738BD996FULL, 
            0x4AE2AD6C29C8B540ULL, 0xC48B74A4118F6A83ULL, 0xE4E3BFDCEF21DC7AULL, 0x0CEE6AE668FD717FULL, 
            0x6ABE85F3F3E523E6ULL, 0xD9C6C7C3E8FD09C8ULL, 0xF055519FB6E815FBULL, 0xCA58618770E99F86ULL, 
            0x8433BF5C50780453ULL, 0x5A0DAE00AA198EF1ULL, 0x6E843E59434D4AC0ULL, 0x4B63583F072D8548ULL, 
            0xA61B26BBCA8AC8BCULL, 0x4781096BA67F2B8FULL, 0x4184E39B331F90C0ULL, 0x7D251F940D82B44DULL, 
            0x1DCBB3E9679E8D66ULL, 0x14E22ED0D0579E3CULL, 0x1D7BBD1E3A0AE744ULL, 0x064370940C15155AULL
        },
        {
            0x911AE2C656935C05ULL, 0xFD0CE8497F1115F4ULL, 0xB62087DFBD42E138ULL, 0x446A6608FB044253ULL, 
            0x9137D646FA5E5878ULL, 0x3E6B20B2F347004EULL, 0x9F9B4E14772A6C27ULL, 0x6A032C198CF5DF17ULL, 
            0x211627BE9EB10194ULL, 0x900A82171ABE9CB0ULL, 0xB95489C2CFD9032FULL, 0xC653301E7B4F0D86ULL, 
            0xD157390AAB082125ULL, 0x4DFBCB5319EC8AACULL, 0x8E729F489C704545ULL, 0x08588BF62D8E8D32ULL, 
            0xB6C700FD4B702D3FULL, 0xB29CEF90C6DC0E59ULL, 0xBE4AB6E861B4A3D9ULL, 0x7C13C1D64255BF34ULL, 
            0x62E1D67BBFDC9F33ULL, 0x935B030FB8E2C326ULL, 0xC0D538F5A86E2D56ULL, 0x577A86561B751459ULL, 
            0xC5A37AAE1299F573ULL, 0x5FF98363D404390AULL, 0xFB68523032E5273EULL, 0x687BD6ABBE4C9B5FULL, 
            0x2F4CF57DBB815570ULL, 0x49DA9F69E8C2CE98ULL, 0x2D354FF416F28DBCULL, 0x76B5EDAFA12FCF33ULL
        },
        {
            0x965816059941952AULL, 0xC948E47F6BF1FB20ULL, 0x6B23F17A77735A17ULL, 0xFBB53418DEC5F1EAULL, 
            0xEA79DF47AF058FF0ULL, 0x581A9C80CF1E2FCBULL, 0x049EEBF4BA293054ULL, 0xFD8C13DC7F54CF81ULL, 
            0x74FA8DCF72F2F03BULL, 0xE3469383DBBA5403ULL, 0xC31AB83288F54C40ULL, 0x71076C7D2F42D5C2ULL, 
            0x5D6B877DCB925D5DULL, 0xCAE03B2F5BE55B45ULL, 0x948283C441B60637ULL, 0x4F5A2540FED0F137ULL, 
            0x93217F763253DEDCULL, 0x411446C43D6F53F4ULL, 0x177F62BF909A525DULL, 0x454FAFDEE08AAFC0ULL, 
            0x5D170E1D7572D4D7ULL, 0x9F16AFB0B2E3F803ULL, 0x006C468957C275F0ULL, 0xD917F1138FA4AD35ULL, 
            0xA8CC2A603FA8FF0EULL, 0xC630EEFABF620B61ULL, 0x8CCD49E719F6BABAULL, 0x13186F6A1AC5E5A8ULL, 
            0x3FBE875C9505BCF3ULL, 0x498288D94901242BULL, 0x24092A7078710390ULL, 0xFDA37C5E6C90F3E1ULL
        },
        {
            0xA6B1625C6B4418CCULL, 0xE5DE7C1F0B9D0C2BULL, 0xCA283D8BD47E6265ULL, 0xC1FE3513ED6A21B7ULL, 
            0xFEBC81D1A93D43F8ULL, 0xAE6DB9B08E1484E5ULL, 0x0E8917021FDFB21FULL, 0xBD49920AD6A6FB9CULL, 
            0xA9A1D9E3B2B193E6ULL, 0x1D80FD26548639EAULL, 0x6D6865A81B5AF6AEULL, 0x50707E5814669F69ULL, 
            0xAB831D654D9BCFD1ULL, 0x7E7F7E4F07D9DDAEULL, 0xADA4B59FF6919196ULL, 0x462582A5E819DF49ULL, 
            0x198CD3F253A2C8E1ULL, 0x0E0F5066AD47F739ULL, 0x8CC47BFCB0100298ULL, 0x26D42C53F1B439E7ULL, 
            0xA9941486B355631BULL, 0xCB0AFF81586EAEC5ULL, 0x14F32E83BA28CFE7ULL, 0xFC763D3154D500ACULL, 
            0x76F9499783A3F775ULL, 0x7AB9D42FA10A042FULL, 0xA6EB8D2EBE8A71E1ULL, 0xB0384D3567E02DAAULL, 
            0x0A448C4C4ACCB3C9ULL, 0x1B7926DF89E1260BULL, 0x0D7178C42DF6AE94ULL, 0x8E8CD0B5FF83BFFAULL
        },
        {
            0x029F9A6538E57CDAULL, 0x284019D12309E2CDULL, 0xAA5BDDE91CD108E3ULL, 0x1CA5FCF253F1A004ULL, 
            0x63DD465A18EACC80ULL, 0x1BF4989F92F24A8CULL, 0xF3804B9C7B0DAC51ULL, 0xCDCD04CE0B8B0154ULL, 
            0xFF5FCC5AB99FC1F7ULL, 0x2DDC28159CDD0C49ULL, 0x9A6E4E49D221E0A9ULL, 0x29FE1B05687B4387ULL, 
            0xD5B7376AE35B0876ULL, 0x2A525CF36C0AEA01ULL, 0x34A0836FD9A6953AULL, 0x891B4489DD252A47ULL, 
            0xC08963D3E532A3AEULL, 0x871C45E85CEC6718ULL, 0x0BD7E8BF56FF7879ULL, 0x8966DF6917BFD745ULL, 
            0x80194FC23141396FULL, 0x898AD33CB95A498AULL, 0xA60B20B2663D69ACULL, 0x75A99B654E31AB45ULL, 
            0xD9442FCBD8BD077AULL, 0xE12AEAFD38388388ULL, 0xD64F342890340212ULL, 0x8947DA8C803DFD4EULL, 
            0x8938FA9FD1D10B7DULL, 0x1993DAD9201BDEC7ULL, 0xD3950D49294DD279ULL, 0xFBFC342AAD3E949BULL
        },
        {
            0x193EFFAE1350E7C4ULL, 0xBDBA0A2F9A529DDEULL, 0xD20EE4CFA2B1570DULL, 0x43B0B75A3C29C8F7ULL, 
            0x149308ADE1978E1DULL, 0xD81D7293CE8F3735ULL, 0xF4AD0F35D197F530ULL, 0x7697F283491A8208ULL, 
            0x6ED29161E999BE0AULL, 0x1A940022470302F1ULL, 0x5F25A2DC4263C745ULL, 0x3D52C56010FE648AULL, 
            0x980CD6C625062752ULL, 0x5199CD28C2D3F897ULL, 0xC4C020492E1AF6E6ULL, 0x7D2AE2AD356719AAULL, 
            0x301D024814FF436DULL, 0xD3347CF5B02E89F0ULL, 0x4D36209D43D7DBC7ULL, 0x75374C585CF94E4BULL, 
            0xC2108570BFE5A1A2ULL, 0x956854EBB0ECA967ULL, 0x9C871666DDDCBB24ULL, 0x2BF7B1624E2204C1ULL, 
            0x78EC052F6591E762ULL, 0x0C8577C6EADAEA56ULL, 0x9EFF8FB544A329C1ULL, 0xE2DAE8EFCF00EBF4ULL, 
            0x8C7D2AC1DD0C7FB8ULL, 0xAD44F2AC6AC9A965ULL, 0xDBAE31570624BECDULL, 0xAE59AD70CB6503C8ULL
        }
    },
    {
        {
            0x4C693B37C441510CULL, 0xF60401667273184EULL, 0xA6CD9D0BCF740EB6ULL, 0xD1BE6BDD9E10275BULL, 
            0xFC4E2FD4A7C5E7E4ULL, 0xD997BBCD81D72F9CULL, 0xF26E23D62A8678C1ULL, 0x8FB873BD08BC034FULL, 
            0x7DE402C458337A6EULL, 0x271E9AD921B47891ULL, 0x060405207B181AFCULL, 0x1442E02B0D7F5EF9ULL, 
            0x188B6EA34F596BA1ULL, 0xC8AFC9027E5D3ACFULL, 0xE65EA56F096245E1ULL, 0xE4ABEE269B8B419BULL, 
            0xD4B755A84A74B822ULL, 0xAE8FB67BD698BF73ULL, 0xC70392B0D59AB978ULL, 0x4D1AD7F8172F1988ULL, 
            0x18F25B3745E51C97ULL, 0xFE51966FDCC5E815ULL, 0x1F9C9B9A9BFD5C18ULL, 0x329CA5C61035CF84ULL, 
            0xEC3C5127F9FFD09CULL, 0x9CD70F6FB6F08A45ULL, 0x8B1D09DA49329F11ULL, 0x491E7C511CCB09C8ULL, 
            0x78B6FC68BD4AA775ULL, 0xB95D14E9BFDBE55BULL, 0xE4DEC642AD4EEAB3ULL, 0x84A91FA184053A0EULL
        },
        {
            0x132722F323FDDD0CULL, 0xDB3839020CF1CBC0ULL, 0x66D5F4B93475D675ULL, 0x783AA6136273DC17ULL, 
            0x9E8AEBEE20A89EDDULL, 0x6ABC0FD215329E44ULL, 0xB6A9BF39A0335D7DULL, 0x8DC980C135A0C8DBULL, 
            0xEAAE37BFEECAC1D4ULL, 0xB1F56998C87B9AB1ULL, 0x50A76321AE961E03ULL, 0xF162F58867820E81ULL, 
            0xE77F075CB20E5D60ULL, 0x270A0C41B34B3B0AULL, 0x0E6413A2B7678ABBULL, 0xB9803B8FF1359490ULL, 
            0xB6F40637875E8CF6ULL, 0x623734963221ED07ULL, 0x0CF3F5591D68D898ULL, 0xF66329257AD14A7EULL, 
            0xDC66FD505A29CAF2ULL, 0x87BDEA6EE9479442ULL, 0xB088164D6F1C4C45ULL, 0x4A40F1CCA8C26E00ULL, 
            0x8AEA86D023993769ULL, 0x1286DBA5CD46117AULL, 0x4949ADF1928106CEULL, 0xF29A0CCBFC2A0E7DULL, 
            0x42ADE64953045B91ULL, 0x8E1338B624393C2BULL, 0xA4FE34AC973E872DULL, 0x7D6EBB8474F44797ULL
        },
        {
            0xE1E3068E6BDCD99EULL, 0x82E38F6EA47EA1B2ULL, 0x3D2109138A6F0B33ULL, 0xEA04A6903BF647CAULL, 
            0xD98CAD2B912F8688ULL, 0x5231DAF198144429ULL, 0x7F9E61313948A60AULL, 0x135C28E8279EE343ULL, 
            0xE5E0F3C4B2113192ULL, 0xA2A5F3D8485864D1ULL, 0xE7A5FFC1A3AD0BD7ULL, 0x18E2ED2ED5E1456DULL, 
            0x883277DFE5C73A63ULL, 0xA063C6807B2856DDULL, 0xEA1A0586D5915EE5ULL, 0xC26512F4656B53C5ULL, 
            0x71C2538DB8321B78ULL, 0xEB3F1E4F0506560DULL, 0x18D658F6318C4C5CULL, 0x93522AB7C7CE4116ULL, 
            0xA26D63FBF015DDBCULL, 0xCF7B64940C045FD7ULL, 0x7D0ACC82C0C296A2ULL, 0x8CC1C65863251C7CULL, 
            0x216C398165FC655FULL, 0x30D4F46FF28EC7BFULL, 0xC888CAE017564BB5ULL, 0x340CCD896393AB27ULL, 
            0x1960FF0A7C504B9DULL, 0x551C6467A2D8545BULL, 0xAC7380139CB2D53AULL, 0x0AEFF46DBF8BF21AULL
        },
        {
            0xC8D9E7C0EB7891D4ULL, 0x3907FAB5EA07BFFFULL, 0x9A4EEBF87AB1E52CULL, 0xA3CB4643442BB9C3ULL, 
            0x2AB333990080C562ULL, 0xA808198BD68F77C8ULL, 0x10E00F94896074CDULL, 0x3456F8CE126E6AEBULL, 
            0x5EF730147305A6E1ULL, 0xF206C20FD1DCE776ULL, 0x7EA4F1B46FEB1E83ULL, 0xA67D5DD43DAF4310ULL, 
            0x37B0193672F75EB6ULL, 0x526D9283BF97E898ULL, 0x907DB4B0D837D0B5ULL, 0x86817147A31BF186ULL, 
            0x7F8F8384AE591110ULL, 0xC9FFEFEC063068F1ULL, 0xC4BB43552365172BULL, 0x4101EDA333E7E4A6ULL, 
            0x7D3118CCA7CE931EULL, 0x595F76B6A2E019D2ULL, 0x1128F5B1156212F8ULL, 0xFFF88ED228142F00ULL, 
            0xABCDE2F854E0B434ULL, 0x0726573F89D01F89ULL, 0xFBB2B71CA2214220ULL, 0xE55F176D193B7EE3ULL, 
            0xAA9A705F1FC2EBC2ULL, 0x28BC34C7DDB7E4B6ULL, 0x08E26EE4C121E6F3ULL, 0xEEAE75905437ED17ULL
        },
        {
            0x5F58D10206624885ULL, 0x3B387E4D6A5C08B0ULL, 0x616593EB1FD45151ULL, 0x13C23333B46520BCULL, 
            0x4C04664676355237ULL, 0x85CE08AB89B3D631ULL, 0x71635BD2703DD4AAULL, 0xEEBBD66124990EF8ULL, 
            0x193DF33D12DDEC76ULL, 0x9B9931FD055162DFULL, 0x55940728FB754B8BULL, 0x37EB47A8B59FE331ULL, 
            0x1E5E727B9014D736ULL, 0x36C87A4081E040CDULL, 0x62AC312D34C59284ULL, 0x026C997438D144A1ULL, 
            0xCB7BD2022D42DD69ULL, 0x2CC4CD17FA95D9C8ULL, 0x8547041EF2F5F0D2ULL, 0x6943074549579F88ULL, 
            0x15AACFDC55F1BD45ULL, 0xA8FB576F35CB4A1CULL, 0x0C56F056C9DE4034ULL, 0x7FBA3FDF3C1844A6ULL, 
            0x59AF7BF1F343B6E9ULL, 0x3F08214302462740ULL, 0xA4937E3CAD133171ULL, 0x2183BE57FF60EBC0ULL, 
            0x04F3C1681D243E92ULL, 0xB7B6FF44A913A41BULL, 0xEF2E6BC2F01E7FADULL, 0xD2F5B8465A44820EULL
        },
        {
            0x13AC72EB2A8D1CE7ULL, 0x031388452C465348ULL, 0x351C42F5514E40A8ULL, 0x3FA457CC375A0074ULL, 
            0xC73E1EF80BB8A8D6ULL, 0xFE59C6C8BBEC0614ULL, 0x7F696BC7014DB408ULL, 0x6F171E1D3831B1B0ULL, 
            0xB9AEFE41DD8430C7ULL, 0xC680E7D007D0E9F1ULL, 0xFB0C2BAD2911DE1AULL, 0x79AC143E5A2E83B0ULL, 
            0x15FF6612F9B26FB5ULL, 0x7AD94BB261D09738ULL, 0xB41B9DA1F806B236ULL, 0x9F8C3469A19F5490ULL, 
            0x16D65040B9361853ULL, 0xDB67065F0765A15EULL, 0x30A0B686BC782603ULL, 0x622C166B1064605AULL, 
            0x564AA24BA9E721DEULL, 0x510072BC26D77A18ULL, 0xA09C31A7086DEC61ULL, 0x18EF17DF2B4747EAULL, 
            0x8EA1396CD2BAB2ECULL, 0x6F68EFFB6D43EE23ULL, 0xDD564B6075A032DEULL, 0x4134C40E2D89405CULL, 
            0xFA84EB3CE9B8E106ULL, 0x12B54AA0AC51D966ULL, 0x67DD7F299EC59870ULL, 0xDD290161278EA0BDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseCConstants = {
    0x73B2AB6EEE0CEF17ULL,
    0x3769175F75EE2F5FULL,
    0xD6C58F0EABBE8F08ULL,
    0x73B2AB6EEE0CEF17ULL,
    0x3769175F75EE2F5FULL,
    0xD6C58F0EABBE8F08ULL,
    0x57D5A63F69E18CC8ULL,
    0xCC617EE5366C8F4DULL,
    0x59,
    0x1E,
    0xBB,
    0xF4,
    0x50,
    0x01,
    0xE7,
    0x91
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseDSalts = {
    {
        {
            0xA5DCB48EDF5C2BC1ULL, 0xBB6467A6C572322FULL, 0x0DC442E89B525C01ULL, 0x5F58A1B215E6DD38ULL, 
            0x6367DF3176613F81ULL, 0x5AAD1A0936458075ULL, 0xFA87C8D1183C2561ULL, 0x74233B516FB44059ULL, 
            0x4CC4B2E382E11BD3ULL, 0xD69D0F084FBD0FB2ULL, 0x8053FFB87A65CE15ULL, 0xD1EFD287CE044D2AULL, 
            0xB8C37D808C057556ULL, 0x46BFBF97C82F1FECULL, 0x43AC41E82B97249DULL, 0x1F2552C228AEA490ULL, 
            0x0B7C0E443675C083ULL, 0x487CE8FBDA667FD2ULL, 0x75DD8FCAA7CC0E8AULL, 0x8F06CC305FF312D1ULL, 
            0x42A9F6825F4607C7ULL, 0xBFCA0CF65CD6BA52ULL, 0xBDC758977F7F3762ULL, 0xE382908375C381FFULL, 
            0xEEC1D357B14FBBB0ULL, 0x9ABF42677B040C51ULL, 0xCF26DF4ECD7CE82CULL, 0x5050E97B6598E1D0ULL, 
            0x47074FF29EF855EEULL, 0xD2F5806E648422CCULL, 0xB52D76018016B088ULL, 0x9E3406F79CBC4473ULL
        },
        {
            0x0CED0514465F98A5ULL, 0x2B2226E89F9F283EULL, 0x1F74825DECBB6F1BULL, 0xF87DA6AD38B79FEAULL, 
            0x6A31E36BABB844B1ULL, 0x6E689856C1B6FC20ULL, 0x8E152EB93CA0BD66ULL, 0xC3C5E55D46F85090ULL, 
            0x28BC6D4E91E497D0ULL, 0x897E6E76577983D5ULL, 0x951F0C6E767C110FULL, 0x3DDEF6966E223E2FULL, 
            0xED5D31FB365F71A8ULL, 0xEC902820A6B1FA4FULL, 0xBFE0AE568D00970AULL, 0x92B3325AE2271303ULL, 
            0x07131AF1BB36398EULL, 0x919EEC425A08928EULL, 0xC43FB16A0F98E7CFULL, 0x3B9C44F7A51E0A02ULL, 
            0x333479AE87B756FEULL, 0x57FD954F7A3E1FE6ULL, 0x95CECB88EEF111B5ULL, 0x5679703D6545AA5EULL, 
            0x31CE5387CB7CEAFEULL, 0xD2637C27BD2A3260ULL, 0x12177A496D754C0BULL, 0x86BF4990969F2626ULL, 
            0x4EA6F71993F4431AULL, 0x653F96BA56878783ULL, 0xFFEC0C7B4E206A36ULL, 0x79CB2C67049D3587ULL
        },
        {
            0xD6CB800CC5350826ULL, 0x36F2E0D30BCF08BDULL, 0x55990ADB72FC398CULL, 0x230F6BA71C2F2358ULL, 
            0x8157B537D1F65187ULL, 0xD43B9190BB7568AAULL, 0xDE5AE76CF3F2787EULL, 0x6E91CF71E386558FULL, 
            0x661EFD7E8F6F5D58ULL, 0xEFA04F71F475B0B8ULL, 0x315727DDCECEEB5EULL, 0xD575869E66B0B8C8ULL, 
            0x13B276D64860EB13ULL, 0x5E6553465B095865ULL, 0x88D1693A422FCB56ULL, 0x213A595F557B5D3AULL, 
            0x6239A99D65BE2F15ULL, 0x2E1878EBF97B2634ULL, 0x1F758C1547615BD7ULL, 0x7BCA5F641222DBFCULL, 
            0x960679F9B5CFA286ULL, 0x2052F2CF5712535BULL, 0x86C6C0E7752318C6ULL, 0x859F419500A316B6ULL, 
            0xD8670DF5C2198B24ULL, 0x852B56893EAA8B3BULL, 0xC3CE5C7B33672BEAULL, 0x8760150290230146ULL, 
            0x584FD1AEACFA5CE9ULL, 0xF644251FE9EE1A8CULL, 0x2BD6B979D91F9428ULL, 0x85C71A407E22B102ULL
        },
        {
            0x1DDD2C00C60AB4B6ULL, 0xB78C337783F8D6A8ULL, 0xBF1B70BF29E1B8B0ULL, 0x951882152B091276ULL, 
            0x45971139C21D82BFULL, 0xF3CEEFCF00AB2AF2ULL, 0xB6AC88A0AFDEF2ADULL, 0x8AF8B8B1F5D7787AULL, 
            0x1EF47A4DB3CDA96FULL, 0x260495449DE229ACULL, 0xC7922A6B635E7F3BULL, 0xACE6BFB12CECB713ULL, 
            0xC1A84FE3107BD59AULL, 0xC31A2202CB5C6726ULL, 0x2FCA978A4EB05C18ULL, 0x29F32A682F369DD7ULL, 
            0x099F8C7F5A28667DULL, 0x40233D730AE108A0ULL, 0x45581CF7BE783860ULL, 0xE369B09418D42DADULL, 
            0xA5A751FF9217587AULL, 0x8CD4123871AE5C3DULL, 0x2B06D321D13EC99BULL, 0x75DC9EDCA4D674C6ULL, 
            0x77C8CE731DAF8430ULL, 0x39FB159AB357D4A5ULL, 0xDAAB67EC09F73C62ULL, 0x4E5F06A748370639ULL, 
            0x7400E38ED8CFD46FULL, 0x7945CB62391EE892ULL, 0x4F056AB4119FE94BULL, 0xB2FEA29D95EA3F98ULL
        },
        {
            0xF1D87A7E691A53BAULL, 0x1AE6946EA8D15FABULL, 0x9C6450F68561AFFCULL, 0x1EA941F5FCE63665ULL, 
            0x906922F72CBA2833ULL, 0x28570D68BAA0F60EULL, 0x0A9CCEF222B35C96ULL, 0xDB25BF751EC1CD3FULL, 
            0x54F4F09241DD5A8BULL, 0x1A9282BC3E1363F0ULL, 0xA0289D33C5EBCBE0ULL, 0x5E2F065C66DD4CE0ULL, 
            0x39EB34C717009DF4ULL, 0x801C92060559D08CULL, 0x2AFB6076278178AEULL, 0x673AFB8E760A99FFULL, 
            0x5DC4AFF02C719D79ULL, 0x77EB9F4DC5B4E146ULL, 0xA25E545EA0AE1D6FULL, 0x64F8E2EE18146EA0ULL, 
            0x991C2D55D6BB54EAULL, 0xBB3979236B1906D8ULL, 0xE2A0D6AE0689D709ULL, 0x978B71E0130DA794ULL, 
            0xED8F8955D01153BDULL, 0x64D7B45BE763C669ULL, 0x60DFE9299A65812EULL, 0xE5EB7CBD3C5FF67BULL, 
            0x34F6B53A82617111ULL, 0xEED25FFE49533F02ULL, 0x0D2BD2D74E401D2FULL, 0x6E0CF96DFD73B6FBULL
        },
        {
            0x6010284A38BB0EE7ULL, 0x025E5F14C442AFF3ULL, 0x709E993A84FBB476ULL, 0x92B78A2D0C1AA69BULL, 
            0x712BBEAFDE74A5A0ULL, 0x4715012D5F768C49ULL, 0xF5F23E9DB2E46346ULL, 0xA8B8EAF631A0EFC2ULL, 
            0x8B00623469220C24ULL, 0x2839BE2E087361D2ULL, 0x4A55A19D288D932CULL, 0xB495BA5A10B8D5C1ULL, 
            0xEED8219718DCE74AULL, 0x8E022EFCF3664D34ULL, 0xE99028FD1F41640EULL, 0xE791DEFBAAAEDE3EULL, 
            0xBECD43398191877EULL, 0x39C6792D66B8E0DEULL, 0xA2F1C4D58D6A6C26ULL, 0x89C215B474ADFE77ULL, 
            0xA242FBDF47DA0E64ULL, 0xB5C73B0C5282D04FULL, 0x9D24558574A97B20ULL, 0xB1DD5A2832E2C1FCULL, 
            0x1CD7BDE9594DC894ULL, 0xD804377A160322BCULL, 0xD9CE84CC77BA2AAFULL, 0x2A5EC853EF1E59BFULL, 
            0x473277A8E4DFD6C3ULL, 0x890573F706E44460ULL, 0x93E113665BA8B0E3ULL, 0xE964F2E070B28F1DULL
        }
    },
    {
        {
            0x03C0E7482D45C551ULL, 0xB4B8FFA189E42DE4ULL, 0x472915EE8AAAE290ULL, 0xAC55480267558686ULL, 
            0xB5586ABEC5F94F0FULL, 0x04665EE403337ECBULL, 0x38630AF7E1F44469ULL, 0xC9BAA29BC293E6DCULL, 
            0xB29586BA34F1A0B6ULL, 0x1F65223E0DB7C76DULL, 0xBB199BC16F08ADA3ULL, 0x3C0E2D22E18B2663ULL, 
            0xBF13257CD9FE30ACULL, 0xB6B4CDDD0A3362C4ULL, 0x0FC6DF6C98BB0AADULL, 0x46C0887E492380E1ULL, 
            0x0F01C8B3DECC03F9ULL, 0xE69A22AB70C4509BULL, 0xC820F9AD4D0EBBC8ULL, 0x3F8937DAECD034D5ULL, 
            0xEFBE2E8005657999ULL, 0x9118C924CD17FBF7ULL, 0xB8D5355F4D820635ULL, 0x5388E09F67986E52ULL, 
            0x0A73F088E8241E41ULL, 0x23936F036033E6CFULL, 0x09AD91C64E553B39ULL, 0xBF0351C22D059FC2ULL, 
            0x818AB19738FDCAE2ULL, 0x9A30E153B994B7C4ULL, 0xCABFB70D61B5BEA0ULL, 0x5CAEA069D024C7C4ULL
        },
        {
            0xBA1E10C79AD4E0D1ULL, 0x15112ADF9C6D9A68ULL, 0x0073602B6E26C3E1ULL, 0x08BAC7C306722827ULL, 
            0xD5C19441E05C9AB8ULL, 0x492219076FB279D0ULL, 0xA91A7F02089BDBF1ULL, 0x58DD8D9F5503CA9CULL, 
            0xF2352F94EAEE2F36ULL, 0x93F167529979D480ULL, 0xB60EBADC2E874C0BULL, 0xB02006B18079EC66ULL, 
            0x4D09EAB30EC7F7BEULL, 0x2E09DAF2321195DCULL, 0x15427BD8C364C613ULL, 0x69B76D12EB74E7B9ULL, 
            0x4A46D46616F06131ULL, 0xA527A8F5194BAA2CULL, 0x30B572F44F87843BULL, 0x1FF2F0C0C871E7E5ULL, 
            0x1BA27948555BB98CULL, 0x2F8A20FD385B4867ULL, 0xEEECBCDCEED6980CULL, 0x1C76749CB330C659ULL, 
            0x4DAADA61F6E5E8E8ULL, 0xA01B6288253DF8C9ULL, 0x0E0063F5072BE04EULL, 0x0539D5094BD2C5A4ULL, 
            0x62B45BAF25688731ULL, 0x4685B8FBF7F693C2ULL, 0xE36BAD48D09EB6C9ULL, 0xE410BBC25B80C4E6ULL
        },
        {
            0x8A046C39E184FA8FULL, 0x9EEA9E2F78ED30EEULL, 0xE4CA751876EC0778ULL, 0x37A5D0ADC2884339ULL, 
            0x6C32A308E0658577ULL, 0x0497604A7598FE30ULL, 0xD0DA55A58414550DULL, 0x9FB4243CBB2462A5ULL, 
            0xB90BB2CD170B7310ULL, 0xE2D70C11A8A53F98ULL, 0x976F447ECD252BAEULL, 0x9AEC400CEC191F90ULL, 
            0x05E131AC754C45EAULL, 0xD7F4D9699B554D93ULL, 0x5B3DFDA697BE42FFULL, 0x50CE1271E82E4874ULL, 
            0x50FCB90E92E3A957ULL, 0x4A61B7224F3F8EE5ULL, 0xB0E37E09F30F90BFULL, 0xFA4D3C241C4C8A5AULL, 
            0xC7DE85B8B301330CULL, 0x34A6F0EB75CAE2BEULL, 0x121B62A47907D612ULL, 0xE561D0EBE3B47987ULL, 
            0xDD8E2423A14F8C54ULL, 0x02D8A6C53267125AULL, 0x2CC46F2AB4254A49ULL, 0xFB16575E2841AFE4ULL, 
            0x2121576F2B6910E2ULL, 0xBCB3258B00A36C21ULL, 0x313CEDF1A4BAF8E8ULL, 0x2192DFDCF38AAB05ULL
        },
        {
            0x65A28F961C402A3EULL, 0x384464A20D91C647ULL, 0x837F3847AFFF4669ULL, 0x978867435C42FCB6ULL, 
            0xAD2A3790D6F9C0A7ULL, 0xFB7490709F69DCA1ULL, 0xE818CDF30AB20C44ULL, 0x9AC140E2BE672789ULL, 
            0x7714A1E1ECF7A423ULL, 0x91024BBC56D7919EULL, 0xE594C476A70C899CULL, 0x27E0873D2C6A16C3ULL, 
            0xDE043ECAE1A3F679ULL, 0x94C5339D9649F684ULL, 0x0780E49F2E600926ULL, 0x7859D0E6B6C57816ULL, 
            0xA45D548B363605DDULL, 0x05DC68CD7049D24CULL, 0xCF1D60F422975E08ULL, 0x985C84D9EB59F5CBULL, 
            0x4AC3FF95AE4528ECULL, 0x5F62F24D60D76877ULL, 0xB233528CD3EC1DC1ULL, 0x0A3F7B1F7E056AC6ULL, 
            0xD0EBCF2F36257C3BULL, 0xDB7E40112613F9FDULL, 0xDA1BF904F0C2002AULL, 0x9E24C730F72485F3ULL, 
            0xE60C74BB2A9A1C79ULL, 0xC35B7E77555CB4AFULL, 0xB02D995B7DF30F73ULL, 0xB49BDE17FE957145ULL
        },
        {
            0x0DB6460445A1D8E8ULL, 0x0DDE9545B94324A3ULL, 0x2467BF741746843EULL, 0xC50695A18B3637AAULL, 
            0x917F28EA88172BBEULL, 0x3994600C7744AA6BULL, 0x4C75AAA51E863EB6ULL, 0xA42E7D4FCE86BF9DULL, 
            0xBE50101443AE2528ULL, 0x75D09381131F44DAULL, 0x5C6A5133F04D5F3AULL, 0xD41F604CE42CA530ULL, 
            0xEB0AA15FE62E8C71ULL, 0x80C5CA0891830380ULL, 0x5C849AE26BC22E97ULL, 0x553785EC1B4868F8ULL, 
            0x88928F3C86D0E248ULL, 0xE0568F7E701ABBD4ULL, 0xC5488F25D769BD0FULL, 0x11FA6BB31338C91EULL, 
            0x33EF47B7FC631101ULL, 0xF0F7250E7B45F3C6ULL, 0x4D45122752308256ULL, 0xEBD03D9AD384F9FAULL, 
            0xA8B919064CAE196EULL, 0xB3111ACA44BE814BULL, 0x1C834B4F17157160ULL, 0x9D9E643B2D1CAA80ULL, 
            0xF927BAF315D68506ULL, 0x581F45E1D91C6691ULL, 0xA0A451AF4409AA75ULL, 0x2CEF6DB096765864ULL
        },
        {
            0x9AFD846EEFA7F12FULL, 0xC70B7425E2B8CB1AULL, 0x780545A19A6D811EULL, 0xBB6C35CCE26EF96BULL, 
            0x37BFD588C1DAD639ULL, 0xF4FC5B867CB40218ULL, 0x91E460976FDD3272ULL, 0x58A2F4C0FC35A59AULL, 
            0xAAEE781A70EF1559ULL, 0xBD31223429F5FEF8ULL, 0xF9D50AC0908FCABAULL, 0x19598C6F54CE8803ULL, 
            0x71C440AB11AB4D3FULL, 0x5D1D89F5FD8A5516ULL, 0xDDA0A2F1D410F0EAULL, 0x99A1129D90E97ACAULL, 
            0xC7595FE182509667ULL, 0xE666F2D9B4F41A97ULL, 0x94F92209B51FFCE6ULL, 0xC06E43765D54D38CULL, 
            0xC0D828CEB9476898ULL, 0x3FB61FE8D0F069AAULL, 0x73B101C1CD1786A6ULL, 0xB519A54EB45C0047ULL, 
            0x6C82637038E0050CULL, 0x96CB824B03A140AFULL, 0x621D5D55239C53ABULL, 0x7E94B26D9ABBD0A0ULL, 
            0xA8953FE7F05EC88FULL, 0x71250D774CD835DBULL, 0xE2EC7AB826D27EBCULL, 0x056441E147C80C45ULL
        }
    },
    {
        {
            0x32AE9ECDEFA7D1BBULL, 0xE8E5FE97662D3260ULL, 0xAC3007DA94D93B74ULL, 0x892BBFEEF3EAE0B2ULL, 
            0x9CF44CB2E471128AULL, 0x1182D9D9886FF2D2ULL, 0xF5E3DA1D37616F03ULL, 0x26D4F7353B39D52CULL, 
            0x8C4A05857902D6C1ULL, 0x90C580D0BA0B0308ULL, 0x794E55FE6D6A298AULL, 0xF254727669DA856BULL, 
            0x7E821C46B25354E7ULL, 0x149C9F500A1C4501ULL, 0x4AEAAAFA8D64FC67ULL, 0x6F9A22D903195EE6ULL, 
            0x083BBF06AF6D2C54ULL, 0xCB19721F854D60ECULL, 0xF1F25B11CAD0D1FCULL, 0x38224FC08E331D11ULL, 
            0x8C75542335E1FA03ULL, 0x5233E9F138016045ULL, 0x2F5A3BB8EF0F59A8ULL, 0xF3B426C95B3849DAULL, 
            0xD02A5ED1B0896BFDULL, 0x25AFBB21BAD9568CULL, 0xA43FFE210047378CULL, 0x8F74FA45A560F51EULL, 
            0xFC8AD68A645F6E04ULL, 0x7BE84B9AD784E85FULL, 0x5EA8F09573B3FF82ULL, 0x2EDDD1F82C70EAEBULL
        },
        {
            0x083AB4E92173572BULL, 0xC7CD09CDECAE4770ULL, 0x5CE092FC527FDA76ULL, 0xCE6275815F6809AEULL, 
            0x204AD9595CC915BEULL, 0xBE096FD70EA6F508ULL, 0x09E6D3CB5DA0A6B5ULL, 0x9678C7C33F3EE1A2ULL, 
            0x1C33EE95475A6E8FULL, 0x61EAA14CDFED0D9FULL, 0x3A26246A658D7447ULL, 0xEE34F248B5942465ULL, 
            0xD26B10D8817E28F8ULL, 0x3A5733847750EAABULL, 0xFC455B6CC7EEB71FULL, 0x614FFA6D01AAC28EULL, 
            0x5989BED470B33EA4ULL, 0x8A13B6DFC5AF57DBULL, 0x9D0D7A65A9BC578AULL, 0x5D4C751B6A0BDD98ULL, 
            0x5342830A61AF7E3CULL, 0xD99819DC38843D90ULL, 0x7E078C9D1420C56EULL, 0xAF05C2AD7549C816ULL, 
            0x6201EC08CBAEB468ULL, 0x1613316A95AE61D0ULL, 0xE645A65D1BB9F64BULL, 0xBFFAEA1A160077A7ULL, 
            0xC4C79AEBF8D347DFULL, 0xA9153AE02E40CF96ULL, 0x9ECF8F7B6071D5D1ULL, 0x761217CB800128A2ULL
        },
        {
            0x085F660F4D378256ULL, 0xCAEE0BE43C1BB90CULL, 0x95B88CC473B36D19ULL, 0x1DD93FCDF8B67208ULL, 
            0x1660074E8DD32847ULL, 0x8CBB277D5E1A2681ULL, 0x5D1D3EC14CDE5350ULL, 0x1FAFDD2F14864957ULL, 
            0xA0A1CA286081F9BAULL, 0xEB229F98840015BAULL, 0x73C9077612DA9861ULL, 0x8BC64EEBB4BD74D2ULL, 
            0x371B2E91A52BE5EDULL, 0xC81FCBD2671715D5ULL, 0x84C974D4CB75B056ULL, 0xC9BC2B091348BD6AULL, 
            0x9544C536B436A64BULL, 0x1CCA7417B3E80E48ULL, 0x35A79F33EFD8F935ULL, 0x3E10C6273DFAC578ULL, 
            0x5C01023B01B7C956ULL, 0x248557D6237F7019ULL, 0xDE2CA3EB1DBB04FBULL, 0xBAA4E63FD8F64FE9ULL, 
            0x52972DA110C9968FULL, 0x42296B593827959DULL, 0x696A050A1FE3A37EULL, 0x758BD5980615F348ULL, 
            0x1158315387ABEA0EULL, 0x9DB5AB584482ECC0ULL, 0x1DBFAB9B3CFDB702ULL, 0xE17D38219AFEAC4AULL
        },
        {
            0xA6B4113CF7ECD959ULL, 0x0E937442881651C6ULL, 0x1465BB21A3F92802ULL, 0xA3AB4719A7082258ULL, 
            0x4DD738C3BFD2828EULL, 0x86E45AB5B71A455BULL, 0x798B8CC98ADB05A8ULL, 0x767090E084F2D327ULL, 
            0xB8CA4DAE26413A21ULL, 0x5BEAE9041A719777ULL, 0x1AAF161EB10CBAFEULL, 0x11EFCF31D4E6738BULL, 
            0x207B70C40862DE35ULL, 0x1710BEC91FF1AE87ULL, 0x3D1DAA401F5DC343ULL, 0xEBFA9CD70D22FAB5ULL, 
            0x114A0C6F126D4BAAULL, 0x1E695ADD2FCDDCAAULL, 0x34D52ED2824C35A8ULL, 0x51353F38C9D2A853ULL, 
            0x91CF266E51F899C9ULL, 0x31B6DD23BF97D129ULL, 0x0BEF143888B4F6EDULL, 0xD8E8F2320060FE62ULL, 
            0x1892FD6186BEBBC3ULL, 0x75572FB0041D66BAULL, 0xF0288554D4714ED1ULL, 0x401EC5428737F456ULL, 
            0x75137457E008FA37ULL, 0xB1963F67FFA4B62DULL, 0x22F161B0450D2C71ULL, 0x74CDE674F57FEDA6ULL
        },
        {
            0xD0B7523D71B90C12ULL, 0xACD531A5054A229EULL, 0x60358E4EDE12544DULL, 0x2F372FD35FEF5FC0ULL, 
            0x1EAC917C572C432AULL, 0xB7F4E256AE68C575ULL, 0x15C53C76FAAC5541ULL, 0xAC25094ED4AF9EDBULL, 
            0x3D3DC5195D540471ULL, 0xBA104511C5AA2562ULL, 0x7FDD4393A4C01F16ULL, 0x912517EC7C1682C8ULL, 
            0x422F0EA4963D4262ULL, 0x080E2613D6CA5425ULL, 0xAA8F7284BEEB106CULL, 0xBAEA08A7562FEB18ULL, 
            0x8D331A23EE5556ECULL, 0x8211E35614BE2BA1ULL, 0x4D6C78A1396F31A6ULL, 0x0306A5E70AEC637FULL, 
            0x80F447229B13779FULL, 0x63653C1F1096E58FULL, 0xEB77C39AF2DFDBC4ULL, 0x571951C635BC7FCFULL, 
            0x06469A47560B47FDULL, 0xB95677139CA6E898ULL, 0x4441783AB24445E4ULL, 0x9E4FD03CA5E5D3D4ULL, 
            0xD89D96C1043B88BCULL, 0xF309679C745EAA55ULL, 0x0E84AB960BA242CCULL, 0x79B0C98BF33E5DD3ULL
        },
        {
            0xD3F89E2AAB8889A6ULL, 0x3D2BF6D97FDEE0E1ULL, 0x6EB9301E1FB7F391ULL, 0x255F9A9C5E9E20EAULL, 
            0x7F1192199C9BABA8ULL, 0x20C39C213DDFD443ULL, 0x73725E6DDCA84149ULL, 0xC002E66CC4556728ULL, 
            0x9C5AF5A20E4C9421ULL, 0xE130D3D07D0F85A9ULL, 0x0CCB6C7D7B57CE9BULL, 0x75C0BBCDDDCDA614ULL, 
            0x580A24542752FEF5ULL, 0x090E1B8FDBD9BE2BULL, 0x6A994E99BDDD1280ULL, 0x302EC4A518B9C092ULL, 
            0x2C3D4C77E0E42DB1ULL, 0xDEBB790BCC9E2E38ULL, 0x74C2FA3B5593E325ULL, 0xEF8FFCA3B6F330FFULL, 
            0xDAB7A42EB3E36624ULL, 0x3D4312C87FC4491DULL, 0x0EF9A581EC06E6D1ULL, 0xE2062981D95DACABULL, 
            0xDCFBC4DC5B10AC0BULL, 0x50FFD8DEFE878976ULL, 0xD752A733320A0B82ULL, 0xBC43F5A500B078D5ULL, 
            0x012436EF6D3F4D3FULL, 0x5DD12F6EE74122EAULL, 0xC14FE1BE069CC42CULL, 0x6B1181105669651EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseDConstants = {
    0x78B5AD7D1F6488A8ULL,
    0x8B89769AE44F5452ULL,
    0xD25A4F5C716B9BF4ULL,
    0x78B5AD7D1F6488A8ULL,
    0x8B89769AE44F5452ULL,
    0xD25A4F5C716B9BF4ULL,
    0x3535B8DB8E738903ULL,
    0xC97360788776C8A1ULL,
    0xD5,
    0x2D,
    0x2E,
    0x9F,
    0xFC,
    0x77,
    0xB0,
    0xC9
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseESalts = {
    {
        {
            0x7BF832ACA8FC7E7CULL, 0xE5ACAA6B7B2D2035ULL, 0x684C28780715411BULL, 0x6CEE692A7E707725ULL, 
            0xBF4CE28CBD76D036ULL, 0x05B6F9B4447D9FB8ULL, 0x76E9DA031511F040ULL, 0x2A3630D5CED00253ULL, 
            0x3FF269E079C170EFULL, 0x70F66A946D02D3F7ULL, 0xC11F0E2CC6543287ULL, 0x76890BEB728AF9B4ULL, 
            0xB7071A1C199F3A76ULL, 0x0E331C186A0799FDULL, 0x9F2FAE6E61716BE7ULL, 0x2C282F5BA9B79DA6ULL, 
            0x16D8C9506F732244ULL, 0x08B7AE857EB8D810ULL, 0x0EDF2A63A6E6260CULL, 0xDA2B2C4784D25D16ULL, 
            0x622F7B8DCC22F3F8ULL, 0x0652104EFE0A0BF6ULL, 0xA7577E566974E774ULL, 0xCFD681DDBF74F0A0ULL, 
            0x02470DA1C979DD18ULL, 0x4250D73747B334BBULL, 0x9B8B4B1AC3A55B20ULL, 0x7950A77FAAE39E2FULL, 
            0x71A49B2C8F21FF49ULL, 0x9FA5F021CE0BD7FCULL, 0xB1E060A83F7B9A7CULL, 0x95DE626B9FDA0184ULL
        },
        {
            0xCFA4059109F7F701ULL, 0x9269E693C9704FEDULL, 0x2F206F41433A1ABBULL, 0x76AF0B59DD845444ULL, 
            0xDDC088A836986FACULL, 0x959ED6006FF9B9A2ULL, 0x77B9F329305DABD4ULL, 0x640F14B40EB1FE6DULL, 
            0x4A89222AEA212E0DULL, 0xC501EE064B99463BULL, 0x4F288CEE8EC257C9ULL, 0x7B45C550F1AA2D3BULL, 
            0xBFADA7AA2304E41DULL, 0xAF05B192E9CB6543ULL, 0xA980AB33B0C1D36DULL, 0xA8BA70A3549311BCULL, 
            0x419746D461D13C99ULL, 0x2D0D3D5F8454170EULL, 0x666261C6E2C1BA0BULL, 0x50EA60069B8E55A5ULL, 
            0x06C0C9BC1EE9BA42ULL, 0x1929E2E0DB130400ULL, 0xE248DBAAD289D952ULL, 0xB7C302C2E6DCCC50ULL, 
            0x616B0055BE381C61ULL, 0xEADFFD2A945842CAULL, 0x9560EAF6FC793650ULL, 0x43E1395455462110ULL, 
            0x44B4E091BD97E39DULL, 0x01CF8365BF3AA1BDULL, 0xA2CFF8BCAA83677BULL, 0x2B4EAB6DF3065B0BULL
        },
        {
            0x58025F05DA83EBB9ULL, 0x7D77ABA49F72945FULL, 0x7A64B5D90680FF94ULL, 0x054485F3D040EEC1ULL, 
            0x91C331F47EAEFBA6ULL, 0xA5B9DD02D03851CCULL, 0x34D50A675A5E09AAULL, 0xF2B801E40735F23BULL, 
            0x1033BA09F9167EFDULL, 0xDABD5CBCC4838E31ULL, 0xF0BFAAF0BA0C765BULL, 0xAB27E8394777D63FULL, 
            0x28A347EF5BFC3537ULL, 0x9603BAEABFBCA495ULL, 0x9C1210F9E7010423ULL, 0x6B0184DA16B64A36ULL, 
            0x9DAE0506A2F28A67ULL, 0xA4A0BCF912DBD603ULL, 0x41259E28E91A2E32ULL, 0x6E0589F93321E9BFULL, 
            0x64D8174321D00EC0ULL, 0x464757EEAD174AD6ULL, 0xABCECBA02FB7D513ULL, 0x770D705B5CB7B173ULL, 
            0x125B3A27DF384CEEULL, 0xF8FF45FA0541A1DEULL, 0x9437BD2A44A0C0E1ULL, 0x7CC7D913FB066880ULL, 
            0xE7EDF14FA1E85241ULL, 0x9ADAF5F9E100F58AULL, 0x412F086193D51043ULL, 0x7F0C370622C49337ULL
        },
        {
            0x9B02EAD9F84CBDD7ULL, 0x326B8092ECE54BA1ULL, 0xFC41F76552D3A6A2ULL, 0x28423759A47D5B87ULL, 
            0x85B3EAEC95377F2AULL, 0xD6C556FE2AC1F352ULL, 0x3EDA673584F4E123ULL, 0x21DD407ECAD3F04DULL, 
            0x558DEE2B7A7D22A1ULL, 0xE77C5108AC76DA6EULL, 0x9D6AC5B4F5576F15ULL, 0x44DEE27E6924273EULL, 
            0x9241DDE872810319ULL, 0x29ACD8551C1E06C6ULL, 0xB40EE4C39A789FB3ULL, 0x9D673C6A3605E151ULL, 
            0xC9BBAF519C66DCAEULL, 0x54DF20338AAADDFEULL, 0x3F31A2D7DE51F9D0ULL, 0xA703CDDCC3016BFEULL, 
            0x260CCC266836B0B9ULL, 0x14692F31E808CBE2ULL, 0xDB2D761715899ECEULL, 0x835EA2DDA92378F0ULL, 
            0xE3E9F2F03AA737BFULL, 0x7EDE78869D01E3A3ULL, 0xAAB9CADDE9C8779FULL, 0xF0A93B9F9ED4DF1BULL, 
            0xD9870E81CDF74C40ULL, 0x666B482C5688F878ULL, 0x5761DC7D8F259103ULL, 0x157AD5C2E8BF265AULL
        },
        {
            0x4A3D94DE1E38D0E1ULL, 0xA4D258B45868A489ULL, 0x30A26FC160D2428AULL, 0xBBEB2F748B55A530ULL, 
            0x30C53C9CA9D8B40DULL, 0x37D45CA52E95D400ULL, 0x068071D17D7FAA89ULL, 0x787E08E9D7463EDCULL, 
            0xA1A6B0DE8B1F72ADULL, 0xB32FFC2C86EFBB45ULL, 0x046C7568834CF82BULL, 0xA69F883E0430C4B5ULL, 
            0xD79AA78D5A3DDF13ULL, 0xE2C6C3A56F35FB99ULL, 0xD2D82F3D1E29E6BDULL, 0xE7A7AA4000F3C11DULL, 
            0x0C57F22887964BB5ULL, 0x3744E59328EBEBD3ULL, 0x87740F806D2B4518ULL, 0xF59D3E2CD2D7C7E1ULL, 
            0x88C342E0842A10F4ULL, 0x0D5DC0527667BA14ULL, 0x68E31056B3FD9B4FULL, 0x80E491D340FD35DBULL, 
            0x4F8419CAAE1F7B46ULL, 0x9C35C281A2F69140ULL, 0x1C64BBFE47AE0394ULL, 0xFD9A530DB31A9BBCULL, 
            0x1D286DA7E5707E25ULL, 0x452D2459B3B38D64ULL, 0x26D166C1854F2BF6ULL, 0x21B65FDC06FE11FAULL
        },
        {
            0xBB82F1E328F413AAULL, 0x547B63072F33591EULL, 0x916136E5BC3AA473ULL, 0xE1C810E112919234ULL, 
            0x69DCE40B7ED2CF8FULL, 0xABA0DB562B023456ULL, 0x0C048C950D0BA4ABULL, 0xC287A07EE437124EULL, 
            0x02958CC25AEE3E8DULL, 0x9D6A860C4F2EC0A7ULL, 0x79C6A339AF2AD716ULL, 0x8763661658FA88B6ULL, 
            0xB1C58327D1187024ULL, 0x73CB83EF3C895876ULL, 0xF89747873C407D80ULL, 0xF55CF48FB4076199ULL, 
            0xA19933462241B6CEULL, 0x5380C86B39E4D631ULL, 0x05CD75D8BE841B67ULL, 0x6592768E6A2213E9ULL, 
            0xB556AE7539FC970EULL, 0xBD5D36A51B799112ULL, 0xB5C7CE68959A6E2BULL, 0x8F77A38DC4DEFE6DULL, 
            0x48C67972272D6C84ULL, 0x22D331D0E0CEA55DULL, 0xED2FD44D8DE36A77ULL, 0x864465ED4DBAC0BEULL, 
            0x4335DFB7BE76ED80ULL, 0x857C2CDB8474979BULL, 0xE2DD11817547EC84ULL, 0xE242ACB672C74876ULL
        }
    },
    {
        {
            0x9481AA7E4DF6E981ULL, 0x77045E911752FB9DULL, 0x1B6C60CCC129A848ULL, 0x7D3024CC0EEEE1E1ULL, 
            0xDAE60E04A8BF97EEULL, 0x6F20151839B01031ULL, 0xD5AEE82C20271CC0ULL, 0x7A2CC2431F12E524ULL, 
            0x5853DCE2A7067C9DULL, 0x605629467A03DD26ULL, 0x969073AC068E2E7BULL, 0x6EC0502BCA1A0219ULL, 
            0x1E2DD351600A2DC2ULL, 0xC3E8CF063D56394EULL, 0x2BE54F1BE3732689ULL, 0x8FFB9B2D88EC17DDULL, 
            0xFCC705F8D3103B5CULL, 0x00F5AD7978CC1732ULL, 0x8C857E834D480D48ULL, 0x6C4A1C71B19750F6ULL, 
            0xA43B52616125FCDFULL, 0x45136D6168358467ULL, 0x280B24B8AEEB528EULL, 0x83E40AFF8455253CULL, 
            0x380A913924C44EEBULL, 0x7F4B6A6F74D763B6ULL, 0xAB65D03B1E9FE945ULL, 0x2F3F29E0BF415F98ULL, 
            0x4A6B1EB20958D6F5ULL, 0xECAF626982C60807ULL, 0xAD0306DAB28E9F87ULL, 0x13C3238871C40F19ULL
        },
        {
            0x76FA5C4E83002C6AULL, 0xCA5B473F18CA0780ULL, 0x11F6447BA59E398EULL, 0x9793C1CF8F2D0DB2ULL, 
            0x09F9239D7ADDBBEBULL, 0x5EC9BC69FD69656CULL, 0x508B3BE553A88B94ULL, 0x602D3430647C337AULL, 
            0x5BE4ACA8B3291615ULL, 0xABFBA32D524881E6ULL, 0xE8F38DD18ED5B74CULL, 0x8DE3CFDFB8FE4D9DULL, 
            0x922CA8265148F335ULL, 0x0BD9311D3896AA5AULL, 0xF2D03825DD05D5FBULL, 0xE965EE06792A912DULL, 
            0xFAAE6212ACBA34B6ULL, 0xD750E201942BA110ULL, 0x16D4575FA92B31C0ULL, 0x1AE7CEB5D70D388CULL, 
            0x7EBFB66ABA3C4798ULL, 0x69F1759DFEA24746ULL, 0x5BDE911A349D8F60ULL, 0x0507C76B81848EF7ULL, 
            0xFB55C2FADB845C53ULL, 0xFD21A08FE17F5832ULL, 0x072D82AF394DC1CEULL, 0x9152EC7CC5CD3B84ULL, 
            0x1CA433398D8B16C8ULL, 0x133A6C51EBC237A9ULL, 0xF474011328255CFEULL, 0xE13A58C779772216ULL
        },
        {
            0x77A73D3B143023C2ULL, 0x65B7790FB2135BD2ULL, 0xA858223FE763017BULL, 0xB6915E18A76EE4FFULL, 
            0x60E9910AC9247EB8ULL, 0x6317F78D1063D573ULL, 0xA2DDB35A8C24DD67ULL, 0x6EA33B71D950DC7AULL, 
            0x736E67B4DF6AB79EULL, 0x8B0310BCD96F0CC4ULL, 0x524C7CA7424CED8FULL, 0xDEC2609ED3BFDA1CULL, 
            0x1C2E6A954C279679ULL, 0xCB2F557597BC6A9DULL, 0x4C9D29675CE851FFULL, 0xA62EF44565A100FCULL, 
            0xB9AA5B49D4CF5694ULL, 0x1A418F6537ABD587ULL, 0xF6E869907FD908EFULL, 0xE1632A44910E7D4FULL, 
            0xA4F99D0CD142E976ULL, 0x817B8B5A69AD7EC9ULL, 0xF55A36D6D8F34B72ULL, 0xE07265B426E2FF33ULL, 
            0x5B4A5F2DDA4CE7B7ULL, 0xD861F7018D771542ULL, 0x01A36ECAB7925293ULL, 0x694C03B858C06ADCULL, 
            0xD547D9791CFA23B3ULL, 0x1EB9DE725E393879ULL, 0x77B12CBD0C21B530ULL, 0x31D95137DED017F5ULL
        },
        {
            0x3E912D543E4C8142ULL, 0xA10F685622FB4FE4ULL, 0xB37A2B33DA570702ULL, 0xADFC87AB063111EEULL, 
            0x1F36D5D82D16BB8BULL, 0x9FB9EFCF6C7E0297ULL, 0xD1508D289734144AULL, 0xA637114D6531842CULL, 
            0xCE4A4460526001F5ULL, 0x31B9D3C2E25B0B3BULL, 0x2446A0193213D228ULL, 0x33C1F5BF379DA287ULL, 
            0xA6C7F67136CF0ED5ULL, 0x036C26AE431C2006ULL, 0x7732C7DD7CA76703ULL, 0xA086C9D5CA3C8D35ULL, 
            0xBCC0A123A6ABE6DCULL, 0xCBA0C520936D6E61ULL, 0xBB5BBED730D7D7D7ULL, 0xF28F38465DB553B9ULL, 
            0x0F3316F5AE20FE5AULL, 0xCD57C03187EBD55DULL, 0xC69D429DCF7CF843ULL, 0x6587F469E9207C7BULL, 
            0xE650F9FA6D586AF0ULL, 0x7EEE216072A09EA1ULL, 0x58E405425EA0553EULL, 0x9C8C19EFBCEF552EULL, 
            0xC0CC989D861D5E53ULL, 0x77C601BBF9484727ULL, 0xD4F10ECAB746A002ULL, 0x426ABFC7A98B09A2ULL
        },
        {
            0xAED47169C00529A4ULL, 0x280860DDA0FE92ADULL, 0xE3667DB3C4F4A5BAULL, 0xDC9A0DBC349093E1ULL, 
            0xEC22600EC10E5A15ULL, 0x88EA800BA04F36BBULL, 0x55B4BEEEBD181403ULL, 0x09863CC4115795A5ULL, 
            0x167A20EBC40D08EEULL, 0x2D29C3F10A0CE743ULL, 0xBB0BB96AD4396AFEULL, 0xE3BA09D7E36099CCULL, 
            0xE3A6995E5F69C799ULL, 0x33644E4625BB87E5ULL, 0x31D7B181A9B1AD7DULL, 0x89AF18E17D370B9EULL, 
            0x8B54BF9CE7984389ULL, 0x7119F3633DF0C954ULL, 0xA60557ECADDE54E5ULL, 0xCBB0F0907AF2F054ULL, 
            0x494DBA493C27F4B8ULL, 0x2CAE237F49257989ULL, 0x3146465BA036A2B0ULL, 0xEAD565518F6A1330ULL, 
            0x80CC7C5D2CB0FED9ULL, 0xC3E02EF2102D7FDDULL, 0xCF2D8AA6486F3C2FULL, 0x91CE8AFAF209F4DAULL, 
            0x17E0A077D6DF82D6ULL, 0x01110BE159F02AE0ULL, 0x9E207BCEF36C64CCULL, 0xFC1FFD54BCF8141BULL
        },
        {
            0xA6E44F0E5400A1BDULL, 0xDCAB3EF6AE8A5314ULL, 0xFC3C848571209FAEULL, 0xAC784AEBC0FC8B73ULL, 
            0x71ED0225C685C3BBULL, 0xA77D30E3FA4E91DDULL, 0x5C416B1BC213D51EULL, 0x055820CCC18F5B3BULL, 
            0x6B7EF6C7BE142591ULL, 0x31AA4C40773E0195ULL, 0xF9315DE78149E3B0ULL, 0x35FFCB1564AB4D79ULL, 
            0x65E35C256D427ED7ULL, 0xE0F2E2B448B88E8CULL, 0x3F9008931EA36FD2ULL, 0xC3B3299D6B1D3BECULL, 
            0x73604397A69DE4F4ULL, 0x00DB9ECBA6CC8043ULL, 0xFA76F185FC97E277ULL, 0xA65644E552850E9AULL, 
            0xBD6970EA2841191CULL, 0x8D027664587FFB7AULL, 0x6C692AD38A7FEEFEULL, 0xBB953D9855B1F7D0ULL, 
            0xF35B321697E42637ULL, 0xE835A69AACAA9A45ULL, 0x2CC8DB6AFD8FED58ULL, 0x029CFB2EDACEFC67ULL, 
            0xB9E55AEC0A04EC53ULL, 0xEB417B80D6BC5AEDULL, 0x933B601204371D83ULL, 0x061D02CA507E8BAEULL
        }
    },
    {
        {
            0xAF550F254FCB12A7ULL, 0xD530667CB290A537ULL, 0x9C4943F9BA53B088ULL, 0xC33FCC46FA470F99ULL, 
            0x87FEED6224CCF1F1ULL, 0x0352C99D50A984FFULL, 0xCA4B4A5AF1193D8AULL, 0xAD296B65F89C40C6ULL, 
            0x540BCAC71510DE57ULL, 0x680D87309A412ABAULL, 0xEFB39F3A53CAE90CULL, 0xDFF9004B485EE0DBULL, 
            0x399EA9B0D8327A05ULL, 0xAFFDC3122D63653EULL, 0xB01612C2CE46A4CFULL, 0x817C05866B8DB884ULL, 
            0x79E42284471D64CAULL, 0x92DEDF0021E4CC5AULL, 0x3F93E0329B352767ULL, 0xF2F05FCE0B3DDDE0ULL, 
            0xB685F0EC440F5BBFULL, 0xE4E99E72F426F29EULL, 0x2434D52D38F859ABULL, 0x1AD920E0C1138155ULL, 
            0xCB2D2F6A9DEE8D92ULL, 0x8193A99CF24CBC1CULL, 0x6225057AA43B83CCULL, 0x1EB1DFEB6D1C73EAULL, 
            0x51783A54C0FA6670ULL, 0x66D8E9E1E910D8F2ULL, 0xA5B30000E5A5E35CULL, 0x2CE43753A6FF19F8ULL
        },
        {
            0x70CA8CD63C24FE16ULL, 0x10A0BE90C04BE47BULL, 0x994DB0576D41145FULL, 0x34310B4915EED161ULL, 
            0xA3D306AC195F3CEBULL, 0x9DC19DC7D2C8959CULL, 0xAEC06F4413B32018ULL, 0xEB9D06B32AB4CCC0ULL, 
            0xF9BC238CCE416081ULL, 0xD24FB3D55BE7BDF5ULL, 0xBE73CFAD5B910E03ULL, 0x5F9F9B83D0C9D29EULL, 
            0xF9157E368D830FE1ULL, 0xE0E4B2ACC33AADCDULL, 0x5011D273E19200A3ULL, 0xA3C53F625F10C112ULL, 
            0x33D3857050EE135EULL, 0x2713A4C3B35DF35FULL, 0x8BC5E8C6264A998BULL, 0x1F625DADBAB83C4AULL, 
            0x7DBFC042666F0574ULL, 0x9A045CC53B617689ULL, 0xEE6714C664E57F97ULL, 0x2242676C79262A53ULL, 
            0x2E63A9CBDCFE7D67ULL, 0x6946F29A03A9AFFCULL, 0x17F38BE4BF3B757BULL, 0x0AAF49E72F8E9C5EULL, 
            0x9E6168B3728D17F4ULL, 0x18023FDC28D4539BULL, 0x9EA5BD3090C3F174ULL, 0xAACFAEDA4F1DC274ULL
        },
        {
            0x3F3DF598D4129953ULL, 0x5F0F01A7A57944D4ULL, 0xDC38D1A263985DB3ULL, 0xD6063B772FFE28FBULL, 
            0x8F8D3B19D2C318D1ULL, 0xC8D06C242AF94A4AULL, 0x7B8B6BA6C31BBD10ULL, 0x376B82D64CBAB11CULL, 
            0x2FCDEB279B5B40A3ULL, 0xFEA14D0C5B4CFD58ULL, 0xECD8C0B462B0BB62ULL, 0x0D9DAC0722B35067ULL, 
            0xADD758C5DF1FEA25ULL, 0x7E9FCA344FCBB4AEULL, 0xD96A085EB40E8744ULL, 0xD7224DB6E1D4BF6FULL, 
            0xE7FBF3C6B796DC9CULL, 0x941813F26A020FEFULL, 0x3AC3907581B0AC10ULL, 0x7C25146DF67C0C12ULL, 
            0x0696CF07842E04F8ULL, 0xEFD019431C90AF8BULL, 0x70283C70F33453A4ULL, 0xA8B163CFCB7F0412ULL, 
            0x91FBF4BB1026D6B7ULL, 0x4706759B69E3C165ULL, 0xCED6EADB3F1DCB68ULL, 0x9ADF649AB62C6AD8ULL, 
            0x6795E0A55E691C45ULL, 0xDD0FCE0B82A281E3ULL, 0xAF560254EF615D0CULL, 0x6D684AB6C808FC5BULL
        },
        {
            0x6F1C57358E0C281EULL, 0x642E3158E70FA8F7ULL, 0x12CEDB6043E5F695ULL, 0xA5FA0815AD7E6966ULL, 
            0xFFEECB8310162946ULL, 0x46B32C58E6265D5EULL, 0xA66ED51DBDD589CCULL, 0x205EB3487F6839D2ULL, 
            0x2DE9E67814E23CF6ULL, 0xF21801B0170E9507ULL, 0x0770AF04892DABDAULL, 0x29A1B7A3C116BF1CULL, 
            0xC4190A525ED6E44AULL, 0x9538EEFC33DF480FULL, 0xCDFE00B288329798ULL, 0x88A964F75B351147ULL, 
            0xAE37DB7839076C9DULL, 0xB231511F3526446AULL, 0xD27E28B26E28059FULL, 0x058B8B46D5B6D3E9ULL, 
            0xE10628CA2D72D54CULL, 0x541D47BE0B8E1959ULL, 0x6B4FC395D3906A98ULL, 0xA0860F9B5CC2681DULL, 
            0x6E6349B86E4968FFULL, 0x743AC359793B96A7ULL, 0xFE86F9B9D4BEE3AAULL, 0x759AE0FDDB7BA8A5ULL, 
            0x180DFE28E6BEB301ULL, 0x196869ECBC2C9A65ULL, 0x551CBDED10251060ULL, 0x77DC88784D19FE47ULL
        },
        {
            0x4E9F115E4F60E61DULL, 0x317B6657FE57E861ULL, 0xE0B0266DA5BDCBBAULL, 0xA4D867C6D4FB064BULL, 
            0x5019103FC2D0C4F3ULL, 0x757DF6D54076AEE1ULL, 0x78BBB53D4405B7B6ULL, 0xF1D0892F70134BC6ULL, 
            0x91FCD26C99C65196ULL, 0xFCA7902F124CC5E0ULL, 0xC7956438E13044ACULL, 0x3B90482A7FA010AFULL, 
            0x56CE93D21233A372ULL, 0xA3D86F3AB3968A6EULL, 0xC0A9F1BDCA64BF88ULL, 0xDC85F74B94E753DFULL, 
            0x7603E88980D29BEDULL, 0x8EBDCD7836CC7F59ULL, 0xEDF4F56D92265B4EULL, 0xEF638963B1A8E956ULL, 
            0xBC874F87D3CD7824ULL, 0xCC39148D6D79179DULL, 0xFD9AA872F95F6B59ULL, 0x90DC09DAE62784EFULL, 
            0x683437308051D0BEULL, 0x039A41B985067ED7ULL, 0x0AD18D006949A3FDULL, 0x34556C4162F38259ULL, 
            0xD281300D38DB5D2EULL, 0x39B13EB4718208A9ULL, 0x51DF7BD553588A2EULL, 0x7B18F574F7067C13ULL
        },
        {
            0x8483F23FA4E73992ULL, 0xCBD2CF757BA118CAULL, 0x8DC28422E5324E43ULL, 0xF5CC56E502345F0CULL, 
            0x88CEC53F55FB78C2ULL, 0x338A21AD419BE59BULL, 0xCC14142D623CD9EEULL, 0xDCB0054E8E9C2966ULL, 
            0x41203B7D0449B708ULL, 0x6375D720B82F5624ULL, 0x809FDE15CC555DA8ULL, 0x3E4B6EAD4E8B9C85ULL, 
            0x86BEFADD105A448FULL, 0x7DFD4D8BD59AB250ULL, 0xFFC4E3D5861B2FC1ULL, 0xA35E3011D4715A21ULL, 
            0x299C9134164E89B5ULL, 0x1E5F492A9369C248ULL, 0x27D5983D8444D28BULL, 0x21A61FBA2DF52A4DULL, 
            0x6FB3F497E8AE1857ULL, 0x97D095060B944904ULL, 0xFE5BB04630B72339ULL, 0xE938BAE416E6F88BULL, 
            0x6962DB725DF45EA2ULL, 0xE04970A8C7EB7751ULL, 0xF9CE98959921EBABULL, 0xF64231ADBF17230CULL, 
            0x79E2F7DAC1887F37ULL, 0xD5B9817D75254486ULL, 0xCAE6318F2B65A157ULL, 0xBD5F896C77E5CE7DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseEConstants = {
    0xD0BAADC74EA169FCULL,
    0xAB0298E290616293ULL,
    0x290DC2DAE34FA338ULL,
    0xD0BAADC74EA169FCULL,
    0xAB0298E290616293ULL,
    0x290DC2DAE34FA338ULL,
    0xD69D27C82A9AAA9EULL,
    0x81754702B1AB0FC6ULL,
    0xFB,
    0xEA,
    0xC9,
    0x03,
    0xDB,
    0x27,
    0xE9,
    0x1B
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseFSalts = {
    {
        {
            0xFC0D0CCC7030F060ULL, 0x71B0034B2DCF4EADULL, 0x82E0DA0D7976D1BEULL, 0xD42DEE632B704C06ULL, 
            0x6697AD7788A1935CULL, 0x26563765E1B55FB3ULL, 0x25A4B219E6837238ULL, 0xE238F00E07EADC9CULL, 
            0xBE89B6F26FCBE04CULL, 0x1533A0D2FD3F535EULL, 0x1ACB7394B0B9D615ULL, 0xC5D5287F7D0C1964ULL, 
            0x4F82FA18F3241977ULL, 0x69697DA694A3ECB9ULL, 0xA2705EB5605AE1FEULL, 0xBADE7192E023CD26ULL, 
            0x72A3369E1402AE21ULL, 0x9BD4F1644C9DE083ULL, 0x4677856ECFFF93E7ULL, 0xADD489E450A394CDULL, 
            0x47AECB687CFADE79ULL, 0xB1644832CD93DE15ULL, 0x07DA96424F0AEE8AULL, 0x5A6A7C1C05CFD2E4ULL, 
            0xCA12D00830A2DB74ULL, 0x0DECD461298AF79DULL, 0x70142CD31B4E8582ULL, 0x2E81C510C7A1BA3BULL, 
            0xA9B729AFFF3F3DB3ULL, 0x7A14F4B2F3374DADULL, 0x8B622B435F8E0698ULL, 0x5B5FBED7897602A6ULL
        },
        {
            0x850E0969744A5487ULL, 0xCC905342452D8CFBULL, 0x4F8DC9DBA8A71098ULL, 0x55FC0BEFD1D2AD32ULL, 
            0xB4DF4D8A214AF970ULL, 0x644C8F394861B584ULL, 0x1E66BC40B1CF35C8ULL, 0xC69C0CB108BC0884ULL, 
            0xB7C530ED6071ACEEULL, 0x285CE3512AAA10F3ULL, 0x27B0F55B730968B0ULL, 0x9D3C45D4E51ED0D3ULL, 
            0xCD006FD2537B9EFBULL, 0xEC0421E492DC6BD6ULL, 0x9FAFFED626DD3189ULL, 0xC3E8F603402B3E92ULL, 
            0x0028AF7ACAE505F0ULL, 0x4D04441267408A79ULL, 0xB64EFE5CBA5D007BULL, 0x7B96670BCC95167AULL, 
            0x1F9EDD61A5638EACULL, 0x3E5F7E53CF6C73B3ULL, 0x9B656E616DB2D852ULL, 0x2280A03BF7C8D0C5ULL, 
            0x3A09A86E10CB29C0ULL, 0x7069D4D45BE9D832ULL, 0x90A1F8C25E41574CULL, 0x72EAE42514007AE4ULL, 
            0xE2382B85179721A7ULL, 0x523405834EEEF5B7ULL, 0x01B73D076441F88FULL, 0x423077D90F16FA44ULL
        },
        {
            0x199DAE47BD92ED20ULL, 0x3A39F6B7A5A0A878ULL, 0x12927A5D08551A2DULL, 0x3DF8E7E5B6747721ULL, 
            0x60415BD45DF69E3DULL, 0x6A1B2633251BBBD4ULL, 0xA30D643AB02182A1ULL, 0x96670C9D45268E46ULL, 
            0x0A433D661A9A6A0EULL, 0x13EB0EA49E21083CULL, 0xAC5C11CA5609D436ULL, 0x3EE78804B44A2963ULL, 
            0xB847792D4DBBB83DULL, 0xAE278009C6ABE029ULL, 0x710E2FEFB4400566ULL, 0x6C3EA12FD87A6D7AULL, 
            0x0B87E0EEAE194AE0ULL, 0xC77E54D94D7F1F86ULL, 0xE1C612E1931DC771ULL, 0xFAE2247052405DCEULL, 
            0x8AFC535D518B27B9ULL, 0x39A13DC6DC1E15A8ULL, 0xB37FDBF524E05D75ULL, 0x4DBFB73E779CF27CULL, 
            0x2864649BCA205CE0ULL, 0x137D02DBFD338B8FULL, 0x842E492CB736CBD0ULL, 0x21454C011B472C21ULL, 
            0xBF35135AC271E8E7ULL, 0x3E7EC0D77F896457ULL, 0x1AA72CE84D0CF402ULL, 0xE419FC272B872B7BULL
        },
        {
            0x16F24902443BC49EULL, 0x33FF18244076334BULL, 0x79C70932BCBA11E0ULL, 0x21CFD389AD981116ULL, 
            0x59CC593768B11157ULL, 0x8AA59E29EC5F7ABDULL, 0x320E9ED556FEB60EULL, 0x245B28691D61A25BULL, 
            0x4E71C721FA3DB805ULL, 0x334117E500D670B0ULL, 0x10B94B4FD536555DULL, 0x1C38D66666EBA536ULL, 
            0x0B883E18D4FD819EULL, 0xD2AAC8474C16BA07ULL, 0x5096D954183CA087ULL, 0xEB0B50A53B894F52ULL, 
            0x9B00FAD3495B15C9ULL, 0x5BB4C351A2A8300FULL, 0xA611CE4D02248EF2ULL, 0x79252DA8049794D7ULL, 
            0x62C280BC98F82A54ULL, 0xB4D83C9226BD72CCULL, 0x8C40F7B98B3AA93FULL, 0xBB0AA4146940179CULL, 
            0x7F99632A783FC5C1ULL, 0x2EEF6D6F6526021AULL, 0x233D9240F343CEE3ULL, 0xECFBD2328BE6736BULL, 
            0x9D34C9C0B659A358ULL, 0x1C93C68C5CE282DCULL, 0xAD01FC80BD968F72ULL, 0xB916E4D4C6E4D357ULL
        },
        {
            0x2277E5F8B6BB0F43ULL, 0xAD204BD5267BB489ULL, 0x61AD8D39F1EF25D2ULL, 0xD2764D11C165215FULL, 
            0x83E48ABB27AE256AULL, 0x54FCE3C85304BBACULL, 0x57114ADDBB394DA7ULL, 0xCD06DAD6C366E1D1ULL, 
            0xD0E1D41ED1BCF2C4ULL, 0xEE50B4620D2EFD34ULL, 0x98F16EE46CFF4BE8ULL, 0x0F892159CFF14498ULL, 
            0xC3A45DDBCF8B5F31ULL, 0x9AAD9E158FA713C5ULL, 0xD479CC18ED7A8424ULL, 0xDB1873D3D57A839AULL, 
            0x7836C0CCBB33489DULL, 0xA4F7133ACC6FAC8EULL, 0xA15B64D842B3ED44ULL, 0xE42B1EF8A744A972ULL, 
            0x8BDA436CEA18D93AULL, 0x9A383272A670A2ECULL, 0x63D346F9B9950766ULL, 0xC4074FA8FB341CCAULL, 
            0xE0E5918495FFF4CDULL, 0x0251FD3A398A8F1DULL, 0xD36A9FE89D40C43CULL, 0x085BDB149C4543F8ULL, 
            0xDFB1B61696270003ULL, 0x1546735A1E090A0FULL, 0x8563E49833132126ULL, 0x02F0430D03357923ULL
        },
        {
            0x968507C48E6074DFULL, 0x82D3843D5AFAC73EULL, 0x778F9C0AC11BFEFBULL, 0x3C29AB4C26DBB2D4ULL, 
            0x664CD717573495B0ULL, 0x82E75455B0ADA5BEULL, 0xED0C702D81292528ULL, 0x9B168ED235D554E2ULL, 
            0xF66F15B094ADE943ULL, 0x032FD689B15C325FULL, 0x9FDBC5A0818F0E0CULL, 0xEB512D7350A83C74ULL, 
            0x254453B776C1A8F6ULL, 0xC9AAC9702EE17AF0ULL, 0x970C43DC08B97437ULL, 0x6CB747BFBEF6AD9DULL, 
            0xBA0A71FAC4B1C19BULL, 0x4400823B393F0700ULL, 0x925ECEA6428B7094ULL, 0x00A6C80B8D1F4DF1ULL, 
            0x1E371A81B4944D40ULL, 0x68C6485C3D85EC13ULL, 0xF6EDDED8B7D1FC71ULL, 0xAB0FCF4518514CCBULL, 
            0x7895B4D9CBEFF215ULL, 0x148538615699900AULL, 0x1F2745215ED63028ULL, 0xE465EC85C727E536ULL, 
            0x94A712D5E096D86CULL, 0xCDFE4C37627127E3ULL, 0x344E2CF637367C3AULL, 0xF900D270EE39DE23ULL
        }
    },
    {
        {
            0x7E67F2CA7F030D1CULL, 0x313482610EADE7C0ULL, 0xDD79FF7A5639704DULL, 0xEC638D3CCF98298EULL, 
            0x09B45DA8A7E1DD1EULL, 0xA726D3D3514B0AC0ULL, 0xEB3BFB56ADCEBDCEULL, 0x720CC4C93C0EE074ULL, 
            0x73130EA89FE28198ULL, 0x1309D43206EC8D28ULL, 0x2EDB4ADEDACEF678ULL, 0xA2DF97E4C6B623D3ULL, 
            0xE95A86FB0492136AULL, 0xD44B1AA2509278D9ULL, 0xFDBC307950840849ULL, 0x5988C40F3897160DULL, 
            0xEC9CF5499234178CULL, 0x8D728E1C65A22AC5ULL, 0xFE008E9340BC0EDFULL, 0x5487D80E8A83BE2BULL, 
            0x8F301C1E034620C6ULL, 0x066808DF4A70D998ULL, 0x8C3886AD93A103E9ULL, 0x8354D291BF3B7DCBULL, 
            0xB782FD4480DBD004ULL, 0x4C25548CA10352F3ULL, 0xDF8AB60488F48E40ULL, 0xE2E9BD58126EE228ULL, 
            0x8528E83353F1D491ULL, 0x264298B8939AA435ULL, 0x66CDC52331A087E2ULL, 0xBAD43B67CB74C8DDULL
        },
        {
            0x77BDCA8363FDC5ABULL, 0xBF000BFCAB285196ULL, 0xEA549ACB80C3E23DULL, 0xB9DBBAEC40A327DBULL, 
            0xBC46EAAE003AA40AULL, 0x444505C1A7F431A6ULL, 0xE15390AF257A4391ULL, 0x466CB854ED94DD7FULL, 
            0xD440C8B1BA702CFFULL, 0xCA1A036F2B5B737DULL, 0x8519FB5908895F81ULL, 0xBA1627C48CCEA730ULL, 
            0x14488037330F3BE5ULL, 0x53336E8D087612FEULL, 0x5A9D16DF2FA64722ULL, 0xC5758432C5BBF94FULL, 
            0x7CAB5F50348F6D90ULL, 0xC7C344C3914FDAA9ULL, 0xCD5001D3647F09E6ULL, 0x0BE562A281843C95ULL, 
            0x4D05668E51C9F080ULL, 0x8E9395E409F5C23DULL, 0xE60F7474269282C1ULL, 0xAF12413FEB1D6799ULL, 
            0x33A98C2043EB8217ULL, 0x238C5F9D9340A7FAULL, 0xB0D15E6A9279292DULL, 0x509CC37034DDF431ULL, 
            0x01144820E6191976ULL, 0x834DCF32188C2AE2ULL, 0x127CFDE8CB07B35BULL, 0x56BD8BC05F397786ULL
        },
        {
            0x17D0F3FAF00900D3ULL, 0xB660CFD3F9A7FCCDULL, 0xCA53470BD83905B5ULL, 0xF14BE1D6CF0AEE76ULL, 
            0x30A3B0E8640B4EC0ULL, 0xF23B20967B15D464ULL, 0x2BAF826884A1C24FULL, 0x4939FA5618A2320FULL, 
            0x9D82B339BEF71B5AULL, 0xAEACB98E34BD5BE7ULL, 0x5E8A001DBFF6B767ULL, 0xA17E7FCEE7462C98ULL, 
            0x11FFBFD623A49B95ULL, 0xDD74C46FF5EAE71BULL, 0x35C45DB2C6B2CBB6ULL, 0x78C14238BFB89570ULL, 
            0x962F83CACA87E35EULL, 0xCA5B823758BDA767ULL, 0x97DF3F76E23E12E2ULL, 0x5171DABF4D6CF895ULL, 
            0x89F311281C3C2EF8ULL, 0xF181C14740329EB1ULL, 0x6979742C81DFFE4DULL, 0x98002B4DABF32AF0ULL, 
            0x90FFA33246342F61ULL, 0xB53578CE5D7B12A3ULL, 0x4B18C9B5DC5564FCULL, 0xCFB992D74739834AULL, 
            0x13E71876D3867F93ULL, 0xB64297E8AE78ED05ULL, 0x01DE5EE60185F6DAULL, 0x25145AF86F519B05ULL
        },
        {
            0xE33C4E24669D5EEFULL, 0x7CC0596187BBBB4EULL, 0xF48652AB2DE9F096ULL, 0xE61706196A71ACC1ULL, 
            0x3C05F70BB0698A56ULL, 0x31D9CA50D8B9758DULL, 0x47FDF4632A09B20CULL, 0xC322F67B6A261A0DULL, 
            0x6A3450D8D62C28EDULL, 0x87A021468E873417ULL, 0xC81BD66C7717A10BULL, 0x7B27F196E5E0FC2FULL, 
            0xD7FB8D4482382247ULL, 0x5F03976D6D613AB4ULL, 0x090B576FE9823B10ULL, 0x0A2AA8B607B7130AULL, 
            0x6485AE01B70F0910ULL, 0xA769E61D9B1AE446ULL, 0x017B8066D8F9A51CULL, 0x25D52576D7DC0BA7ULL, 
            0x3BB5EB1935920AFDULL, 0x4F69DA8F022FA2BAULL, 0x784207D6CD4DD252ULL, 0x4D8CA22E10F8EB25ULL, 
            0xE8D6DF761D9A50F3ULL, 0x080E16E8FD0CD012ULL, 0x60FC0795A3C3F79BULL, 0x7B42AB70F720D42DULL, 
            0x573F6737B058733AULL, 0x75A770A72356C9DFULL, 0x540F6C352C2E5559ULL, 0xA21919E1F368B782ULL
        },
        {
            0x9CE1F1FF6720FEECULL, 0x5D958ABCF9FAEE58ULL, 0x97AC03645A917D27ULL, 0x3964DE9F542F6659ULL, 
            0xADAD6AA4E7AE1264ULL, 0x0B31E25EBBD1951EULL, 0xDA241A5AEF38A4BFULL, 0x5D7C3475ACDD66DFULL, 
            0x969D4FE74EECD364ULL, 0x15E3F15DEEAD82F1ULL, 0x1732701712F9919FULL, 0x631884A5422989E5ULL, 
            0x99AE8D66892D9B2BULL, 0x47C73FF43753B712ULL, 0x75AB539CFABB5D41ULL, 0xB6ECA7AF61F69389ULL, 
            0x177C8F3C7A83FC3FULL, 0x5F1832869349CF07ULL, 0x0433905640FCCB16ULL, 0x16B81055E565A828ULL, 
            0xD242A81B15F494B9ULL, 0xF51DBDABEFBC2CC5ULL, 0xF99A044326BA120AULL, 0x1AA1F121FF7C2138ULL, 
            0x0E71182371BDFD92ULL, 0x27791220EE582D84ULL, 0xD41BC06FB1E379EAULL, 0x2056C0ADAA6E31D4ULL, 
            0xD9C0D75AD00A68CEULL, 0xA756BC7EDA5D33CFULL, 0xA9BEBE8E164659D9ULL, 0x9ABB3BBE4DB15FE5ULL
        },
        {
            0xEC9204C539E35873ULL, 0xE750EA5685ED3337ULL, 0x7724770DF0C37AE1ULL, 0x1EE63C4A5FA5B939ULL, 
            0x0D294A2DBF448FA7ULL, 0x3A427D5ED905A0B4ULL, 0x6443CD03279B1264ULL, 0x5E2FDA452A6541D9ULL, 
            0x875A53E732F77292ULL, 0xA6AA3ABB8D7A9175ULL, 0xA877095901197621ULL, 0xDE52C7C2AFA2287BULL, 
            0x29CDA4FF0004DF30ULL, 0x0A63C0082B442E74ULL, 0x06CEBD0C1171C2A5ULL, 0x294530518630854AULL, 
            0x0F5B78CD90051059ULL, 0xC4CCE073CF5C429FULL, 0x583BF5449F6E8B54ULL, 0xCF8FCD29B37B2AEDULL, 
            0x1B70BAD07F27AE2BULL, 0x5052FEDAD0527BA9ULL, 0x0DDBDCDBE2B1ECBCULL, 0xF0AFBAAEF115385FULL, 
            0x39B6B033E2D11DB5ULL, 0x04938F9B47643A00ULL, 0xBCE6CC85F684CA9CULL, 0x29A34B83BFB26DE9ULL, 
            0x378C6F7B9F81621BULL, 0x2DC40DFC6260EBB2ULL, 0x121280AA4FB88488ULL, 0xB64FA97446B9BE00ULL
        }
    },
    {
        {
            0xEED893F6E74A64FEULL, 0x9DE2E03CADEA041DULL, 0x3CDB6E90B359D7D7ULL, 0xE3F18D7536CB12BCULL, 
            0xC25A92E4F8A71EB2ULL, 0x81A8AD7ACD588CBFULL, 0x7AF0F21E3908A96FULL, 0x837F5DE068E2A91EULL, 
            0xF2320A6F1045B3EEULL, 0xF9DDD54B4351B46BULL, 0x1D836D0F857F32B4ULL, 0x0CB57A119F1F1FF4ULL, 
            0xEE2701D10AA16FD3ULL, 0x7453BC95F578462AULL, 0xF8C6DE7A78A0BF64ULL, 0xBC796ED5D4B57641ULL, 
            0x4BFF19620C638BBEULL, 0x4BE8E158B643AF0EULL, 0xC36424EB0DCBCD62ULL, 0xB3F95C0DC26C7B4FULL, 
            0x25422F6FC8C88D5CULL, 0x0BCB81AD6ADA95FEULL, 0xA9408DED37159937ULL, 0xBC50576641B5E896ULL, 
            0xE6656F74B859FC70ULL, 0x10E6E6719B808737ULL, 0xD616368DE640EAB8ULL, 0x44D12D2D73D39F38ULL, 
            0xD314A6720A46A429ULL, 0x343E1F3AF9531CEEULL, 0x6C504C1B6DBE85BBULL, 0x031DB0EFEF8943F1ULL
        },
        {
            0x60A2D2E37EFF102AULL, 0x7BA1A916FFC1A7D5ULL, 0x40B37A541760F1E2ULL, 0x8F9C852AC219DC14ULL, 
            0x52970BB8FB1820E6ULL, 0xDF9DC687820EEC4EULL, 0xB10314E5FF31C75CULL, 0xE03F4CA03581DD26ULL, 
            0x0CED52C733AC1CC8ULL, 0x2B3143B9437DADE7ULL, 0x198BC612C34FB33DULL, 0x377090B6848D0A6FULL, 
            0x60BA430E15B307CDULL, 0x6A89A88BE11584AEULL, 0xA97CBAD8B9561A4CULL, 0xBB12D1EDDAB21124ULL, 
            0x811B6C0CAFF76556ULL, 0xBBA2CBE2A40D4C06ULL, 0xA662EB26FE420347ULL, 0x795D3D37F628153FULL, 
            0x932454987C9D40BEULL, 0x81BEE01658344628ULL, 0x441B080D97953407ULL, 0xC6CAAE74DFCA11A8ULL, 
            0xEFEC69EB7697F0B2ULL, 0xDCA4A8397DA4AE69ULL, 0xF0D6FEE498928095ULL, 0x088E8707E4A4D94EULL, 
            0x3B6DA73D8141F212ULL, 0x3DF82C00301428C5ULL, 0x10BAEB453431BE4BULL, 0x68E8AF4700A15C17ULL
        },
        {
            0x6933729CC4575BB3ULL, 0x89B04605BB07CAF8ULL, 0x59FBB145A8700680ULL, 0x7E9C66DFE63ECD58ULL, 
            0xBB6156E46CF0A489ULL, 0x4DDD72365156E553ULL, 0xC9D652CB6A032034ULL, 0x23896E4952EDA8FBULL, 
            0x5FE8A26D7609D575ULL, 0xE7E71999FF9152F5ULL, 0xC11E020E82A46B05ULL, 0xDDE7159279DE6A45ULL, 
            0x9B5D6D75AE01D616ULL, 0xA2C4F5D04033DC49ULL, 0x8D8EFAFA9AE6F625ULL, 0x9EBA37C6B643C4B9ULL, 
            0xA66BCCDB0C6E247CULL, 0xFB991B2C37A8E4C7ULL, 0xA811650F519E3CD4ULL, 0x4C7752BE3BF059B3ULL, 
            0xAA5E91C1B1830AFFULL, 0x926521D5D15F6686ULL, 0xC1A4EC20F76E428EULL, 0x5C5BCF4041BC367BULL, 
            0xEEF17033C73546D0ULL, 0x700BE9F7FA2B730BULL, 0x56E3FDF43EF16A25ULL, 0xAFE76264CA1C3E5FULL, 
            0x8E6187BB471ED57AULL, 0x6140BF0848DCC6FBULL, 0x21F17337C14EF807ULL, 0xB28E235B37E6CF19ULL
        },
        {
            0xF478840287474480ULL, 0x965E6B0FE68101DAULL, 0x9322691BB0DEAF9FULL, 0xC5F00290F2F94A39ULL, 
            0x672E03EDD6EA552AULL, 0x359913862CC6E703ULL, 0xE2B7590E948C9F14ULL, 0xADED77117F4C7403ULL, 
            0xC1306D8821171023ULL, 0x25D0362E145C02E0ULL, 0xAB44DC677FE1F9EFULL, 0x5F1B979C7EDAF09EULL, 
            0x5DFB4F2A10C6FA86ULL, 0xC05BE909957FD296ULL, 0xC4010344168A8C6CULL, 0x2234F300CE9C63E0ULL, 
            0xC0D3DCEC4ABA6E86ULL, 0xF2B28DA0FDDB5D73ULL, 0x63A943B3F8E2E9BDULL, 0x6616B8470F644B0AULL, 
            0xB9881D508807824CULL, 0xB9C98A16FC9408B1ULL, 0x16025DC4930024C0ULL, 0x06E83C1C6EBEF840ULL, 
            0x0AFB483440758A8CULL, 0x3F2F6441C3AB58AAULL, 0xB75845E847B22B51ULL, 0xA804C6540C638EE1ULL, 
            0xBB69BF1D682D6981ULL, 0x6278E7CCE2D5EE3EULL, 0x95DB7432D6913CFEULL, 0x0F26DA98713C3EE4ULL
        },
        {
            0x515C607F89DCB70AULL, 0xFC3B8D4B4251A086ULL, 0xC62B8EA0CC8A9E32ULL, 0x7EB4F0207408A73EULL, 
            0xE13EA8D9647AE4C0ULL, 0x10310402ABD15A70ULL, 0xFE5627A209158457ULL, 0x570C7DC2DBB5DFD5ULL, 
            0xF854D52C3EE64089ULL, 0x934FAFE2A39E0D62ULL, 0x9486E5038FCBBCC4ULL, 0x146CC59E9C89CA9FULL, 
            0xF52FAE4750407730ULL, 0x82F5257810059522ULL, 0xD90C8AF7DDFF1A3CULL, 0x25B395E1757320C1ULL, 
            0xC596639A37D96D4AULL, 0xE5EB79031280C6E2ULL, 0xAD6B38A726DCDF2DULL, 0x48A4375F3E0F03BCULL, 
            0x599AEDD5F7462682ULL, 0x3D3599EC337EC253ULL, 0x3710B9C53F2A101DULL, 0xEC11634AF387B397ULL, 
            0xBABEAEC45C51404BULL, 0xF385266FFE9B2855ULL, 0x83BF6DEDE5D9B2E9ULL, 0xE15F9B5A114D72E3ULL, 
            0xFE621F71E5EFC9DEULL, 0x4529CE42B6EB48A1ULL, 0x50250FBB883A9FB8ULL, 0x7B523C693F37806DULL
        },
        {
            0xA9759B68EA049275ULL, 0x60605A27FA59570EULL, 0x4C67818C08571F46ULL, 0x4273DB4F8CEDAB7CULL, 
            0xBF17E7FF32B2DCA3ULL, 0xB1D85C628F68A051ULL, 0x350DFF22B232ADA1ULL, 0x4E28708A2F597129ULL, 
            0x49BA4532580CF456ULL, 0xB486C8488A18E9B5ULL, 0x4D2BCE0972F3D916ULL, 0x6C9FA940D12AE632ULL, 
            0x196CC88C99F637F3ULL, 0x757B053B687682C0ULL, 0x01AA345B2685BBC1ULL, 0xA09C388FB9960EF2ULL, 
            0x22BF9BCC4F523D21ULL, 0x5BA2711B5BB7E1D5ULL, 0x7E8B2F7ADF5CEDACULL, 0x5C5B04CF12DDC438ULL, 
            0x00C95407210D4A83ULL, 0xD7F3DABF7F852839ULL, 0x446C96C90BDE1DB7ULL, 0x42547E28DEE4BA61ULL, 
            0x7CC110BA4EB08F37ULL, 0x6EF5F054B1A65013ULL, 0x8B8116E7BA297297ULL, 0x41971D27F06572BEULL, 
            0x1399F70727A80F3FULL, 0x8B313D2A33091CA3ULL, 0x99A4E0F4251E190BULL, 0xC923AC1BDC8278D7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseFConstants = {
    0x27862AC7E4A9AC95ULL,
    0x35564FA6225553A6ULL,
    0x511939376DC02434ULL,
    0x27862AC7E4A9AC95ULL,
    0x35564FA6225553A6ULL,
    0x511939376DC02434ULL,
    0xD725D475FBD6C4C0ULL,
    0x874E8D2957D5E28CULL,
    0x32,
    0x53,
    0xA2,
    0x3D,
    0xCB,
    0x91,
    0x6A,
    0xC4
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseGSalts = {
    {
        {
            0x205F34E7257F332DULL, 0xD43E7A6A7B54EC02ULL, 0x197208294D99D3F6ULL, 0x219995723EE32761ULL, 
            0xB33B630686621F77ULL, 0xB3A196915DA076A2ULL, 0xBF0B50F6CF0D3B7BULL, 0x7D67711596432693ULL, 
            0x957EEB736F1773E3ULL, 0xCF8446D538C51262ULL, 0xD3F0535480F9E604ULL, 0xEF8035AC8D33D6FDULL, 
            0x3177723ECC934E8DULL, 0x34C664A7AB035391ULL, 0x130A09479C3589A7ULL, 0xDAE6D6D2A9359B76ULL, 
            0xBE45828D6B463118ULL, 0x6670EBA21986B23FULL, 0x8BC22A1C50EA078FULL, 0x62CB853ACB9FED54ULL, 
            0x8C8BDA1000284A37ULL, 0x47002179D110B472ULL, 0xF187DF587BB2BAC8ULL, 0xC7EF3113B084ED9FULL, 
            0x71797C784AB623F8ULL, 0xA44E5CD1377C5119ULL, 0xBCBA3156E2EAAB19ULL, 0x8AB3163C5832306FULL, 
            0x59929489CF90C5A3ULL, 0xD8369C7B7FD0F738ULL, 0x3E45DFAEB9BAEB72ULL, 0xEBBE1418A4FB0AE7ULL
        },
        {
            0x4ED420C369C033D5ULL, 0x40F02AE0A2DEF5A3ULL, 0x485A90AB48672B71ULL, 0xF67CAC3FDBB53CACULL, 
            0x75A2E9AD111EAD48ULL, 0xB9F2FD6E74A4280EULL, 0x65E50F2BA7247E2BULL, 0xCD8A913376CC570CULL, 
            0xC6FC175BEC18643CULL, 0x796E9ABCE2477D3DULL, 0x689E19F41D1CDC1BULL, 0xF68D23EF5AA0DDC1ULL, 
            0x60D355D88DEEFEEBULL, 0x340733AEE3982325ULL, 0x931BE1B805D28822ULL, 0xEA7D7B3CFF31C401ULL, 
            0x29030CFF69B9C6ECULL, 0xAF0E955A944427D0ULL, 0x77916E44611EFBBCULL, 0x7785324E7D234371ULL, 
            0xF94B0040864BF7B7ULL, 0x4BDE7E008421CCF1ULL, 0xF222981831D0C92BULL, 0x2565B8558EFD1D19ULL, 
            0xF8728079700ECB87ULL, 0x5BF3CA115A26B082ULL, 0x6EA61EAFC82F3962ULL, 0xCD652EF131A61BD4ULL, 
            0xC6917D6555C270C4ULL, 0x04E605BAD70F7DDCULL, 0x7A2CF7EA688732FDULL, 0xBD1101B5B11020D6ULL
        },
        {
            0x1D04791B767192BDULL, 0xDB8DD89E4719C587ULL, 0x7EF933C70BEA1D4CULL, 0x97B42A60F38EDA46ULL, 
            0x8EBFDF5ECA4D0EE5ULL, 0xD62CC9CE47D6F9D8ULL, 0x56440F242F1302AAULL, 0x2DE006D4252259C9ULL, 
            0xD6E2A2F99A7DCFC0ULL, 0xBD3F0D3CA1A0EE3FULL, 0x8FBE0D3470F94BB7ULL, 0x8CBDB7B39A91E849ULL, 
            0x631F7E2B059E966DULL, 0x813277185584BC52ULL, 0x4C263078A2E5C2A8ULL, 0x57B660D27BB2A4DCULL, 
            0x6ECFC0A98EAC6275ULL, 0x39BE948D4013254FULL, 0xC26E0E2142A00A45ULL, 0x6902C8FA3602DC3FULL, 
            0xC6D5C2FDB93426C9ULL, 0x1718792F4447447EULL, 0xA050524571119792ULL, 0xC0BBCE0A16F59F1FULL, 
            0x681245457A9708FCULL, 0x83A105243B73DAC2ULL, 0x18BC69C1DEA518B5ULL, 0x3DE0972C43C1E327ULL, 
            0xA5EAA179F19A4CB9ULL, 0xC0BB9010B55829A1ULL, 0x30F418CE97A65762ULL, 0x7C3A59F361A4FB93ULL
        },
        {
            0xFABD0220D57B6FD3ULL, 0x93CFF4237CF7D76FULL, 0x734B88F4D2C1D203ULL, 0xF963553E7F70D304ULL, 
            0xFE2CDD0A9B204A74ULL, 0x5B859B828D393AB7ULL, 0xEF8EBEF8AB9D9189ULL, 0xCFC58E70317D9FDEULL, 
            0xDA954940FBB810EAULL, 0x53FE6ED6ABB612E3ULL, 0xF86F08AE9AB14813ULL, 0x920CAB1933BAC904ULL, 
            0xBB5B37EAB81FE2ECULL, 0x4625E23969277CE9ULL, 0x821E90E5615F6909ULL, 0x2811CD22796F0E73ULL, 
            0xE55B89C084456AC5ULL, 0x3B686B1CDB70D966ULL, 0xEF2FFCC2B9CEFC57ULL, 0x00F3CB3D3CC34EB8ULL, 
            0xE18E0B33928ACE93ULL, 0xE323445D8F06F822ULL, 0x74623ADA5EFD0C14ULL, 0x16684F0D523634EBULL, 
            0x4A5373B8C154C80FULL, 0x550359C71692E680ULL, 0x765F9EC68600CF45ULL, 0x3005333625D1EB74ULL, 
            0x0055617107FC78DAULL, 0x9B111F67D82EA03CULL, 0xC6863E73842CC387ULL, 0xF909A775620E9634ULL
        },
        {
            0xDAD2EA2B48D3C94CULL, 0x9A9EE8254F70BBB4ULL, 0xC3B0E5E3E5908C07ULL, 0xC4FDA07B60212B9CULL, 
            0x956486559F4AF5D7ULL, 0x9D246456D4528E10ULL, 0xF975E9976986D51AULL, 0xCE527EE34BEF21D7ULL, 
            0x204A30DF55F8F592ULL, 0xA4DF8934B0F8F8D9ULL, 0xF8063E866A5A55FFULL, 0xDE375E511D09F213ULL, 
            0x6ED244D7A73E3A85ULL, 0xA4F1F86B99BAD940ULL, 0x531623BBDF8B1DFAULL, 0xF53DC3FB0234083EULL, 
            0xF9CAE757B5609857ULL, 0xCC1C56D580502D2AULL, 0x638011C2757B8CFAULL, 0xDAB91736CED2C56AULL, 
            0x12A9D644FB9FD0B3ULL, 0x87CA7C4B6C3492BBULL, 0x2DCB58976FCB7AB5ULL, 0xE45F7154A621CE48ULL, 
            0x04310B47B4BDF03BULL, 0x768877DB49E8A095ULL, 0x4AF6C55F55076A55ULL, 0xEB48C0FCF419573CULL, 
            0x6BE6C0938769645AULL, 0x4293284CDD2EB668ULL, 0x600A2CB85E95C253ULL, 0x5285648109DBE8C4ULL
        },
        {
            0x774E307CD347C65AULL, 0xB3C8A26D1983E213ULL, 0x2B1059ADB0A5B4A5ULL, 0xCC7971DA22FF538AULL, 
            0x7EF2AAC625BF08DDULL, 0x4682BD7C8923FE35ULL, 0xD10C93F057BB4F73ULL, 0x4D2AC24CEF09C8F3ULL, 
            0x0B4BCFF9C313F352ULL, 0x6EE7CEEFD5E2ED5AULL, 0xB2E7D04E911F8FCFULL, 0x3F8E226B3C0BA2A3ULL, 
            0x1154422D2D0F7C17ULL, 0x5A7C19DF7C3AB871ULL, 0xBAC6CFCE4052745CULL, 0x14229DE0C79DC57AULL, 
            0xAFEF48572F44724BULL, 0x00E415EDC8A1412DULL, 0x8F40E7E955C2693DULL, 0xB10FA0D88AD2A98EULL, 
            0x04F6BE5732747F03ULL, 0x77B9E24C7EC36A91ULL, 0xD1B55E6F2D6FE57AULL, 0x2493A9D4876EAEEDULL, 
            0xC546E2DC8D5EE164ULL, 0x5588BE23235A28E1ULL, 0x7BF8D3E6A1738515ULL, 0x22A2F17A2A39BE5AULL, 
            0xE338E282DBAB4D2BULL, 0x320555A05289F661ULL, 0x1CE86BF311FD30CEULL, 0xC135007348168B5CULL
        }
    },
    {
        {
            0x10BC81BB28ED78FDULL, 0xD00F98A167810FB7ULL, 0x07030BDA985147E4ULL, 0xB4BD55DA84CA0449ULL, 
            0x161A96F3845F65F5ULL, 0x4259D5945D5186A8ULL, 0x3C1413507F6F27C8ULL, 0x9987DF2931B69FABULL, 
            0xC6D7DCCA822533C1ULL, 0x98FBABE0DC4D0AA1ULL, 0xB6F84099629E25ECULL, 0xE7EF5D30EE56EC5DULL, 
            0x6B368A4772FC5F64ULL, 0xABCB76C8B36AF542ULL, 0xB48142C336505647ULL, 0xD5A9FF277396A6A0ULL, 
            0xBCD97DA88D8D339DULL, 0xFA39100AAAC97CEBULL, 0x276A26C615415F64ULL, 0x4FA7EF65E95EBE50ULL, 
            0xB486B9614E6F43DAULL, 0xB36EE0E944F03F5AULL, 0x6EABC8D16E33BCD8ULL, 0x764C59DF3270FE1DULL, 
            0xE6EA92DAA8F09BC5ULL, 0xF9B286291A5BA64EULL, 0x0149DE58541E3485ULL, 0xC4457B48F3739BA7ULL, 
            0x30D5284FAD161487ULL, 0x106D47DD31F08B47ULL, 0xD16D91D69DD6358CULL, 0x0A4D2471B19E41A7ULL
        },
        {
            0xDC76AD5ECE828986ULL, 0xAD11C1A98303287AULL, 0xD7F515904B77FD25ULL, 0x598ADC7F9FA419A6ULL, 
            0xDB0AC58D2843B2CFULL, 0x8E49157003EFFD98ULL, 0xFB25F38B5C60DBC6ULL, 0xEB924A3520C27E06ULL, 
            0xDCE2ED0E1B2C2E65ULL, 0x2D5CEF38CB57B5D4ULL, 0xC57426A02251B4EEULL, 0x0F6F50F87D8B2198ULL, 
            0x96B114A5970BAFE8ULL, 0x8ED18519E8C67F7BULL, 0xA4FF1B9FD5B31414ULL, 0xF3408BB1386D0609ULL, 
            0x4355224CEF268476ULL, 0xE5E7130B016D7A16ULL, 0x5FF9ED46688703CEULL, 0xBF6A01CB99D7766AULL, 
            0x922C8CE3468275A6ULL, 0x7E057370FF16A737ULL, 0x57955F0ED46B86C0ULL, 0x8BA7C379D75609F6ULL, 
            0x9E849E8D419B5114ULL, 0x0845E0B954864DF8ULL, 0xC8945B4570C85B80ULL, 0x093B9DEB212E6906ULL, 
            0x9302502EC7BA44A6ULL, 0xF08B6AD006F254E4ULL, 0xF1D6F2719A9F1379ULL, 0x12CBB2FE6540A65EULL
        },
        {
            0xCCA52DBC3EAA03B3ULL, 0x27B7132C746EFC2AULL, 0x92C97823C81F5AC4ULL, 0x79B04BB33782777EULL, 
            0x624AD5C7F2ECD3F6ULL, 0x899720D17EBCE47AULL, 0x8096A7873695F787ULL, 0xD2DEA6B9E4B81882ULL, 
            0x0DA4809E3E588B62ULL, 0x5B2A5F6F3974B29BULL, 0x35ADEE7555CB846BULL, 0x3C7BA1545BB69D32ULL, 
            0x16DFAD8484CADE9BULL, 0x3C39B1700E57FEAEULL, 0xE5FCD3B50E2F053AULL, 0x98DF6EFD55E9CA59ULL, 
            0xC3261B4350596BC6ULL, 0x8B576ABC3344EBF4ULL, 0xFEC00BE3BD9BAF40ULL, 0x45A9354D8CC064EBULL, 
            0xB31D2E76D0A53B63ULL, 0x45C2AB09F2279DB9ULL, 0xB9B3E36268E6870CULL, 0x72E349E3174F6753ULL, 
            0x0C8924DC8FE0F229ULL, 0x7FE81C6069B90A7AULL, 0xE550C9464CBBCA05ULL, 0xE09DD18751A85823ULL, 
            0x75A2DE298C5AC183ULL, 0x063BB476BEF34891ULL, 0x514BCB51C54136DBULL, 0xF82BFA84D83D8823ULL
        },
        {
            0xEA666C7EC54228E8ULL, 0x14EC3B38A874A61CULL, 0x04016BA9BB5BDA9DULL, 0x165F95F43B7DAE3EULL, 
            0xBC4DE81BD394466CULL, 0x7A0E976DDE90B6E2ULL, 0x42B5232864D399D0ULL, 0x1A38501C6E50B241ULL, 
            0x30980361E7733EACULL, 0xFEEAFE5884DBE117ULL, 0xD545C0FC1E63BDD3ULL, 0x2B611699F087B92CULL, 
            0xCB62090831DCE742ULL, 0x8DB6FD43E39C8E6EULL, 0xF331394AC820DDD7ULL, 0x417B3B89DA182029ULL, 
            0x46734472D0B8E66AULL, 0x878DD8543034CF86ULL, 0x57893678CC3EF5D2ULL, 0x6EBFF0B0BF2260DBULL, 
            0xAEE9B26561ECBD69ULL, 0x853FF2AE14066294ULL, 0x44C6D8DE504983C6ULL, 0x080F56AD4286EAE7ULL, 
            0xBA9EA4BAB856C5AAULL, 0xE9591BD9200430FEULL, 0x0B33CC8E12C15CD4ULL, 0x045839AE297D8460ULL, 
            0x2ED91A3C535BD502ULL, 0x4483737697EA20BDULL, 0xC5A547FDAEEA2C11ULL, 0xBB08BCD76C6BA4E5ULL
        },
        {
            0x281628839AF1E6D0ULL, 0xEF379E5ADED2D0D5ULL, 0x0FCBD551532BE32CULL, 0xEC2F491C50B5723AULL, 
            0x65A29C094BCFA9FCULL, 0x195F9EC2384113B9ULL, 0xA95E89FE0CFED9BCULL, 0x6746BC4886C4397BULL, 
            0x6EC1A35FD6997036ULL, 0xD4A7E98450D0B897ULL, 0xFC1BB129DF289499ULL, 0x59C63B43D0EC7617ULL, 
            0x63051F0125E59D56ULL, 0x2219DFDB5237FB49ULL, 0xF13117A9B22F8329ULL, 0x778A3D0AECA590C6ULL, 
            0xDA1431674590EF18ULL, 0x87C7268D9135956EULL, 0x51614B8432945051ULL, 0x7CB0F81768299E57ULL, 
            0x22535872639B319AULL, 0xB6275F98AFFB1BDDULL, 0xF5101E414A3C449BULL, 0xE9120173B64096E5ULL, 
            0x319BAB43BF28C063ULL, 0xF386328CCB27A97DULL, 0x867E976ADEE3FD01ULL, 0x522365A89568904FULL, 
            0x51B7493978D2C9E9ULL, 0x238B3529AC600B4FULL, 0xD2910DB91AA39AF8ULL, 0xA21E246D5E6DF25EULL
        },
        {
            0x1DDDD464934B2BFDULL, 0x7341150DC0B70558ULL, 0xAB924D30F9096A46ULL, 0x1C02C2C85533FE85ULL, 
            0x484139380D47A6EEULL, 0xED9CB0990382E9C9ULL, 0xD934263D66E5BAC5ULL, 0x25EA6D7DA833A63BULL, 
            0x1016B619E9D0EFEBULL, 0x0EE4234DAA3BD59BULL, 0x9968ECD98F184B07ULL, 0xE486CFEF3DF00B2CULL, 
            0x17A287850F353B2BULL, 0x26AEBFB551F61718ULL, 0x5BC5B1B34E512CB9ULL, 0x5EC61A74600BCE23ULL, 
            0xDE53E53E5D9AE214ULL, 0x882D51FD316412A8ULL, 0xEF5069F0CD6C2000ULL, 0x0B4B4C527DC0CB6EULL, 
            0x195CAAA1C0B78AA0ULL, 0xD34465B1B1EC5759ULL, 0xE73B8B1BD4A32672ULL, 0x97F5C818B70220A1ULL, 
            0xADE70F041F9C4E46ULL, 0x7BBFD4062BECBE19ULL, 0x5E141FE1532C4F9EULL, 0xFBEEC53A3D240C37ULL, 
            0xA3D97B30688C1BAAULL, 0x806A5EBFA56EF9D6ULL, 0xEF38D93A46A8DE6DULL, 0x4B6112D17DE62B05ULL
        }
    },
    {
        {
            0xB363AF16F8A2CCB6ULL, 0xB83CFCAF9C3C892CULL, 0xC49C4936C7E18381ULL, 0xF86CA395A535973CULL, 
            0x420505172C38C114ULL, 0xC9AC66D95F33ED27ULL, 0x1200632AD61CB580ULL, 0x517EAF40FA71D5B6ULL, 
            0x01FA7AFA1D420D7AULL, 0x36120344DFA3BAC5ULL, 0xDDB216343D0F7751ULL, 0x72F90FFD074ABCFCULL, 
            0x93FF244FA1F86B83ULL, 0xB12CC6D172BB4D46ULL, 0x7DEC8688CF2E2E54ULL, 0x2BE26D86B756B618ULL, 
            0x01BFCDC0017DA19BULL, 0x814640E7AAA52993ULL, 0x1B7211AC4F0F8DA1ULL, 0x791F6D6C85C37031ULL, 
            0x49CB0D24D6BAF540ULL, 0xBB1EB5AADAC12E51ULL, 0xC545A1C89B3B6E49ULL, 0xC13AC4B32E288899ULL, 
            0x3CFA67541B645F63ULL, 0x7A6B6270C7146DE2ULL, 0x180B6EDF87A3BD08ULL, 0x4058C4D687BF3683ULL, 
            0xB358F2FDE2238BD6ULL, 0x9BF3A8D29B969993ULL, 0xEE7FEFFC1DD3036EULL, 0x00989BDA9CEEA0A1ULL
        },
        {
            0xF894F534B740DCAFULL, 0x19D251A426455FAFULL, 0x5EFE653A1D4B209BULL, 0xBE80801B694E8231ULL, 
            0x360A30F018E6A34DULL, 0xBE9716108C49A037ULL, 0x1B83195C3076A94DULL, 0x65885D6B25D51117ULL, 
            0xA6415F8236B10EF9ULL, 0xD40B330A14E36C92ULL, 0x4B8BEDA3582EC387ULL, 0x9C2884257B70B91EULL, 
            0x519CBE5757B65EFFULL, 0x5CCAFE3C21E0DB87ULL, 0x5F74C28E13D628BFULL, 0x5DDD21967CD76A97ULL, 
            0xF3C0CE137D849895ULL, 0x861AB48915607D1FULL, 0x11AE096B49736646ULL, 0x971BEE0A35E4F492ULL, 
            0xEC80CB437E41835AULL, 0x792D7F0CC49F1618ULL, 0x9633F25ADBC340FCULL, 0x20B6CCDA6E010A87ULL, 
            0xCEE9424449939733ULL, 0x420E22C05C7856C7ULL, 0x42C1E0F66F79592CULL, 0x774D016CF0CD8881ULL, 
            0xEC03EE7AE1BD2417ULL, 0xBE52AD3DC6B756B8ULL, 0x30666A6CAAF9F9D1ULL, 0xB388122EAB0F969AULL
        },
        {
            0x57F874804365913DULL, 0x68A561E95628AF7FULL, 0xAFCF401480436F24ULL, 0x3EE1BBEDF29592D4ULL, 
            0xDD7BCD80CE87CCCEULL, 0x3D4D1AE9CD278C1EULL, 0x1B5347873A411DFDULL, 0xD7166D01A3EC04E6ULL, 
            0x8FD9002BE96D8DB4ULL, 0x896A3FA113C19993ULL, 0x32C4F06EB74D6E20ULL, 0xA7FD2C9E57500896ULL, 
            0x9C0CED34CCD24276ULL, 0xE0593D93098CE166ULL, 0x8FC113C445951139ULL, 0xEF213745B931CC57ULL, 
            0x9BCEE7EACE3F47B7ULL, 0x32C4529B47907A95ULL, 0xBECD64C311347F78ULL, 0x174519F06513FED3ULL, 
            0x46D30937A74FB8CAULL, 0xFD7BAC5A3BDDDBD6ULL, 0x36DBE40B983CEC09ULL, 0x14B6C9819573C497ULL, 
            0x841F2AB83E072D03ULL, 0x4D1BFD381EFB1B80ULL, 0x2B5FA14B818246DBULL, 0x6D25E4EA529A560BULL, 
            0x1088BBA46404F0B7ULL, 0x842C7C928D551140ULL, 0xEFE36C85E58A8232ULL, 0x2BA725F397C71F36ULL
        },
        {
            0x0C3BA4B7DE09D7D0ULL, 0x4D978262AC3C2577ULL, 0xD77E5DFA40FBBFEBULL, 0x9B8640BBBDC48248ULL, 
            0x99990C552FD7F68EULL, 0x528097BF305D8036ULL, 0xA15F4C4061C7E71EULL, 0x7A640D58C1DA6B85ULL, 
            0x75F9A26B1E97BA9FULL, 0x2C35BC9B8ACEAB26ULL, 0x87DEC355E381FB59ULL, 0xE567FF1FA041D6C9ULL, 
            0x4EE316C19D362725ULL, 0xC32B40E695702D7CULL, 0x5F6700C3368CC3BBULL, 0x66A231F0CEEE9FE3ULL, 
            0x86A5956FA5470FDDULL, 0x7265F150F3F984B8ULL, 0xEB0C602C58BA5853ULL, 0x5987321D7045935BULL, 
            0x87589FF2BF670D86ULL, 0xB3FF0C964D661293ULL, 0x923F45F4BF0168CAULL, 0x4D7DCB23E3532A42ULL, 
            0x0C976E2C51870027ULL, 0xE96BDDCE586ABE07ULL, 0xAC1BAB3152440A18ULL, 0xC5E0E4F6883FE47CULL, 
            0x78DCA08466183EA2ULL, 0x8BDF33A7F38F7D27ULL, 0xB5F1403EE497E4C8ULL, 0x00653FF7EF566D9BULL
        },
        {
            0x8F98CF2B5516DF1EULL, 0x6A98EEF60A5DB0F2ULL, 0xA53F7D2E0061466CULL, 0x3C51632EBE557AC9ULL, 
            0xB8A85B5471ECF9A2ULL, 0x9F2194A3CD56F4C6ULL, 0x559F483E0B91BD24ULL, 0x39FF91F7A454FCBCULL, 
            0xDEF2C3C89FB5C55CULL, 0xAB2EAE18EAFCB44DULL, 0x962AC416795FCEC0ULL, 0x5B2A12FFA7AB42B3ULL, 
            0x8405CAA44903EE7BULL, 0x43ACB158CE6E2BB1ULL, 0x87E99669EEEC39BBULL, 0x5CA783D8DC583EDAULL, 
            0xD2E1E69C2DCD1F51ULL, 0x7B6C2E3E3FFC8E05ULL, 0x7BB8E151EAD8FEB6ULL, 0x6C8580EC3A77DD0BULL, 
            0xCDCF68E1E48F9ACAULL, 0x12E5236A6E1651B1ULL, 0x6FED9603FE7745DBULL, 0x17CD0CE77D50F59BULL, 
            0x77C5AAFBA099AC92ULL, 0xC88207CC0C5D9CBFULL, 0x191BF70F72A1E707ULL, 0x04A4DE193C1BED4AULL, 
            0x54F1F2F3AFC0146DULL, 0xD5404508F59BF055ULL, 0x40E58BF256B014B2ULL, 0xF9FA8DDF8C1C6CE3ULL
        },
        {
            0x3BA079A5213A9906ULL, 0x442475870034CA57ULL, 0xCE693738CC0F3A3FULL, 0x8339880F7C456A0AULL, 
            0xD435A6093D4AEFC9ULL, 0xA942689E73FA5139ULL, 0xE3544F7FC56263A0ULL, 0xC0575EBEC0EF7C6CULL, 
            0x5B47196F3C478E7AULL, 0x15931A6472393C94ULL, 0x1A951118A3FB9DD8ULL, 0xC1B9B77483060398ULL, 
            0x50A5C8482F045801ULL, 0xD3EB41E046375734ULL, 0xFA06B5A57602DEA6ULL, 0xD2E11BBC4A06E385ULL, 
            0xFCEAA55957ECDDB1ULL, 0xEFD2F39616DC141FULL, 0x308C64062B4E3B8DULL, 0x323178ACD61F2BF5ULL, 
            0x867142484549A787ULL, 0xDB1E0C374F1CAA94ULL, 0x89FFAE7A729D9323ULL, 0x1D2B9E7DB88B7A23ULL, 
            0xEF37F5155B141C40ULL, 0x8C05EE5EAA13B02FULL, 0xCCCB20459666D6A5ULL, 0x26FA024075A91503ULL, 
            0x4BB0692274B3A462ULL, 0x227AA0B84E9EE51AULL, 0xC37FA66C42EFAA71ULL, 0x8C259861ACA6AB55ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseGConstants = {
    0xEF608C704C478E17ULL,
    0x448E4A5B3E3D25AEULL,
    0xB35798008557DF9DULL,
    0xEF608C704C478E17ULL,
    0x448E4A5B3E3D25AEULL,
    0xB35798008557DF9DULL,
    0xEB398A67F6D1B751ULL,
    0xF9A8053E6570954AULL,
    0xDB,
    0xDD,
    0x65,
    0x6D,
    0xF6,
    0xFD,
    0x02,
    0xDD
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseHSalts = {
    {
        {
            0x10B40DADDFE37C97ULL, 0xBDA1963F3FFA3FE1ULL, 0x9458C0428E468260ULL, 0xD92F7E09B71F27AEULL, 
            0xB7F45632D08B2B9BULL, 0xAFDD9C06AF5FF861ULL, 0x67C99ABB9D47A0C7ULL, 0x4F98FDB26E6BF79EULL, 
            0xBDB9A472C1905150ULL, 0x662BFFB727FC71EDULL, 0x89BDEE1C83C94104ULL, 0x65F11BA80BC9D2D2ULL, 
            0x1970F436DB102041ULL, 0xB649127BF01923F2ULL, 0xDDBB6A82A53466FBULL, 0x9BC5D152B2429F7BULL, 
            0x361BAD32E097603AULL, 0xC3092E480D49C8D9ULL, 0x19AC7629E3A0321AULL, 0xC1B8563A3680D730ULL, 
            0x8BF5DFBE2987C818ULL, 0x6DD7198B794A640BULL, 0xC67D3463023D3389ULL, 0xA63CAF83972B46FBULL, 
            0xD8F3FC10D2BBB18CULL, 0xA0A01FE2C85A6134ULL, 0x6079C3A3A076CDC8ULL, 0x82D93E31E9007433ULL, 
            0xBBA0E7836ACE791BULL, 0xBA05D49857057D0AULL, 0xEAE76171F154D026ULL, 0x1420316973FCE0EAULL
        },
        {
            0xC141D34537B0C751ULL, 0x3CCBA44E932777A8ULL, 0x673CD7345D1A74F8ULL, 0xA631BD45327F1938ULL, 
            0xEC38ACBA3B6E8DD8ULL, 0x9603572210B4B935ULL, 0x79D9A2166E8CCAABULL, 0x8A6622D1C16E75BDULL, 
            0xA5C607DBCCD4F998ULL, 0x7244A0CE3B2787F0ULL, 0x4084529C9ED14B0DULL, 0x4248B590589141B5ULL, 
            0x05D8D65A10DFA85AULL, 0xFC19A07EAB957439ULL, 0x78A1C47F290E90B9ULL, 0x5D548596130F3EC0ULL, 
            0x547D3D5095C74F5CULL, 0xA631A649E6886E84ULL, 0x87256798DDE7448BULL, 0xED35C1B274778F76ULL, 
            0xB9EEBD3CE27FC999ULL, 0xE0620BF09C5CBA1FULL, 0x2C356D41E2479E4CULL, 0x10FD0438AD1C6849ULL, 
            0x9E65D138362920F6ULL, 0xF17981FF75E8574BULL, 0x1943719924DAE1EAULL, 0x6E73FC494AB3D013ULL, 
            0x96E0C0FD713E75FFULL, 0xB56E8DB56693250CULL, 0xF2452DE7109E1B75ULL, 0x61FC8F3D80A098EDULL
        },
        {
            0x78967477806E3C1FULL, 0x2F9B4B2B443C77D1ULL, 0xA247688BBB4B08B2ULL, 0xC5195F76D7012E91ULL, 
            0x9946AE40F7785E18ULL, 0xC6AC883C82A20998ULL, 0x0F15AA0165A5D266ULL, 0x9E977112736BCA14ULL, 
            0x8F6ABD59095AB9A6ULL, 0xF01749F4E4F531E1ULL, 0xE2A3091ACD4D2DAFULL, 0xF2EF2EA1331136CBULL, 
            0xD9DCEF0D9224C281ULL, 0x9724AC61B5D74D66ULL, 0x227B567B904D1AD1ULL, 0x523BA582C894FA9DULL, 
            0x2151E101FEC086BFULL, 0x93C46319DD979EE2ULL, 0xAFFFEDCABAC5C996ULL, 0x64561A3DA9D9319CULL, 
            0x0D1D17E3752E540AULL, 0x60911636BBA2F732ULL, 0x8BEB70227DBF78A1ULL, 0x6CF96F2A473EC9F7ULL, 
            0xCF011122A2F9A375ULL, 0xF84AD7953757C781ULL, 0x9AEFC303C64BD6F5ULL, 0x10DCB1FDCE1617A0ULL, 
            0xE53562D1E70202CAULL, 0x6415CA425A09240EULL, 0x1C705D1BB4DADA3AULL, 0x8150817B7AA6F3D7ULL
        },
        {
            0x9C8F12559BC94AA4ULL, 0x364A849D7D3FEF65ULL, 0x41C9E6ECFCDA31CFULL, 0x3B4F996062ABA6BCULL, 
            0xF7F11293FEBF26C5ULL, 0x0E56CDDC561166D6ULL, 0x8895144532F45C4FULL, 0xB1E2248CDFEC1C14ULL, 
            0x1B084E4F441AFF0DULL, 0x08110BF39DCC6F63ULL, 0xB46204B73EF60963ULL, 0x1A46F7060AC8A699ULL, 
            0xE3E68877C8483471ULL, 0x5A67FEF1128ABB6AULL, 0xF37B789476FFB04CULL, 0x3CACDE4E2D68F8CDULL, 
            0x83C585B3D6819A74ULL, 0xF10B4BAC2C3C664EULL, 0xB1671460B8F48953ULL, 0xAB3EEA14882FD2D8ULL, 
            0x37946F8F21E8B26BULL, 0xD8BE7E4E9A423592ULL, 0x6EE252BDDAB1314BULL, 0x8E77924640FA3181ULL, 
            0x8D669558DF146C69ULL, 0x83764A5EB9530BC2ULL, 0x1616C3B00A35F791ULL, 0xDB36D33599B99EFDULL, 
            0x2A89E919C8C14F0EULL, 0x01F818690292CDDAULL, 0xE635205A744496DFULL, 0xD6B4AB6295A63466ULL
        },
        {
            0x6DB28C96C79083F1ULL, 0x17FB4449A4691F9BULL, 0x9DE7973DFBD13746ULL, 0xB3A27032DA58E215ULL, 
            0xF7F4A264FAC5B341ULL, 0xBC170A97002DFBF2ULL, 0x62E0D7EBE49C9BF7ULL, 0xB2D546F954512A8CULL, 
            0x4099F213E6361829ULL, 0x0D0135D86360BFF3ULL, 0x689ABE1169D8CD9DULL, 0x0A04B566B2F9D9C6ULL, 
            0xCE7CB74ED0B0DECCULL, 0x94FD1574FA3E588EULL, 0xBDA1876043B1E2A4ULL, 0x69BA4A10C795BCE1ULL, 
            0x5DCBFA9801992C40ULL, 0xE72180A4AE4E9AE7ULL, 0x7684773806F44815ULL, 0xD9F193C70D505B93ULL, 
            0x448ED514F50228AEULL, 0x0753D36FE96B3619ULL, 0x59EDE9AE02E39CECULL, 0x52342322E25E0E60ULL, 
            0x53FF8F035E54AC8DULL, 0x0340F3839E1D4733ULL, 0xE90DE154E170EBF9ULL, 0x0FB528879FF92FCEULL, 
            0xDCD74524B82DF539ULL, 0x8D2BC4006B5BE11CULL, 0x22AFD1D9503DF498ULL, 0x5BFF0AF82B28D64EULL
        },
        {
            0x95B262F97F6EDCB0ULL, 0x11ED3E105DD9D188ULL, 0xFD394B65057BDA94ULL, 0xC91300CB28A87922ULL, 
            0x47908ED01127E49BULL, 0xBD0249362A75E036ULL, 0x2B679C26F34813F7ULL, 0x0D3C4FA736C454CAULL, 
            0x5F21B6CE8FA8425FULL, 0x2FB243B8DA4D1B6EULL, 0xCA12D2BC5A71714AULL, 0x4F426DF5A81AFFDEULL, 
            0x23D48898DE6E86CAULL, 0x4716724777D49321ULL, 0x187E929C85A3EECBULL, 0xAC2F201A8023AD0AULL, 
            0x91A24077B7EC0694ULL, 0x8C2CC4619279948AULL, 0xFC301686D311AC50ULL, 0xF8D886E3B779E113ULL, 
            0xC14335B35ED3BEBFULL, 0x0F32ACAE06D054ACULL, 0x69E2F6C431727324ULL, 0xD65065C1BCB78A0FULL, 
            0xEAFB6507CD431D00ULL, 0x902A5CD09C83AF3FULL, 0x4C32267B0223ED8DULL, 0x4BD02755D5D2C4A7ULL, 
            0x3C633B6891E9DC0FULL, 0xB436DB5A248DA763ULL, 0xF9CFD29ED4494E8FULL, 0x0C90ACAF80A03351ULL
        }
    },
    {
        {
            0x5286BDA8BDC6BCD4ULL, 0x973EE2C0CA72C592ULL, 0xD836773920BFD764ULL, 0x00FA298A4924C246ULL, 
            0x54164FD2A6745A0EULL, 0xCA3160F31C890E0BULL, 0x69E7EFB0EBB12459ULL, 0x9603B05813BA3663ULL, 
            0x6384A95803161852ULL, 0x0A33286809058806ULL, 0x4D2DC0782171F46CULL, 0x59AEF2D9D0A3039AULL, 
            0x39843A537DC2AA0AULL, 0x02B80129A168DA34ULL, 0xD02A5EF319E8D98FULL, 0x582FBB06C9EBF09BULL, 
            0x47434E0A2842326EULL, 0x01D6C803B768B80DULL, 0xD4F791357082B223ULL, 0x263697B96E6E3B9FULL, 
            0xDCFCEAA1FE49BFFCULL, 0x03D5757FEBB3AEF6ULL, 0x9F7BEECE41062B58ULL, 0xF9676F5A4BCBB0A5ULL, 
            0xF420D6E26A8149ADULL, 0x9CD0A5CE81A5E52CULL, 0x0551EBB0A8DD9948ULL, 0x30B8290C08312E94ULL, 
            0xFDBCC36DFEEC40F2ULL, 0x933D6BE75F6C9069ULL, 0x4C6417C3820CEBAFULL, 0x2AAFDDD7E975EAF2ULL
        },
        {
            0x7DC8AB914696ACDCULL, 0x639DEB176A723A04ULL, 0x6630DC07E418527CULL, 0x1B4993E7058EA0C5ULL, 
            0xA84D8232B632E8D2ULL, 0x17F0C08FBE7D37E3ULL, 0x7D56C87D3A1CF217ULL, 0x58FA302E67AE1EE6ULL, 
            0xAD4067DB3DFE5FA9ULL, 0x865E2110BF0B85A4ULL, 0x749351D849B49768ULL, 0x6488C3EAF8BA44BEULL, 
            0xE1E91631F0ACC664ULL, 0x9805AB9428020023ULL, 0x57B0B1A0003D5496ULL, 0x7775296EAAB05EBAULL, 
            0x4DA7EE1117304DE7ULL, 0xD2CADCEFBE61D331ULL, 0x962995C8E804A919ULL, 0x167DD38A0DA52DBBULL, 
            0x24008D5A0F8D0836ULL, 0x513782813D136C95ULL, 0x14EA268AAA02EA8DULL, 0xF270BC44BDDB3E9AULL, 
            0x23147B63741CC4FEULL, 0x2AB8663B58E7D195ULL, 0xD9C42A762815BEE5ULL, 0x3048257544E7A7FBULL, 
            0x9D3C7C66644CFBB9ULL, 0x13F259196950CC18ULL, 0x2FF1055BF36EB6EEULL, 0x9CFFC2924D3D5DE3ULL
        },
        {
            0x86F6A73B284DF79EULL, 0xF0D218C46C32FF9CULL, 0x436CEE1E31E8BB14ULL, 0x712E8067C56F9F3FULL, 
            0x460999CC78327EEEULL, 0xE686EC30D842DC8EULL, 0x9CA0B1587CBE7FA0ULL, 0x95D0CD224DA466DEULL, 
            0x1CCC392F595D366DULL, 0x3BE50D80C0A0C016ULL, 0x4669D4F8BBF66014ULL, 0xE43661E64DA2B0D1ULL, 
            0x17793706104EA3CEULL, 0x3A6BF6610799B2E0ULL, 0xD1426CC70A5C5544ULL, 0x9A0016C531BC2C99ULL, 
            0x189A714EAE6BBB38ULL, 0xC36E4F418FA951B9ULL, 0x73F3681A8747D0FAULL, 0xB2B65ADF06F41199ULL, 
            0xABCD0F68111C33B8ULL, 0xBAEFCC8B7D90D975ULL, 0x39E9B0D33434067DULL, 0xDE6BCEEE883D4EA4ULL, 
            0x9DDD1EF98C6C97F5ULL, 0x2674B596935DCD4EULL, 0x1575A2245786AB1BULL, 0xFF10651C8E4682C2ULL, 
            0x46DAEC3364EDE770ULL, 0x4948F70A24A1468EULL, 0xAD92326FEB17237FULL, 0xA856794998C53D68ULL
        },
        {
            0x8F1FBF0AD83E6686ULL, 0xEE601A73450E0E18ULL, 0xE47C73C19B9967FEULL, 0x168BCA2BDDEE06D9ULL, 
            0x1373E74E9A6F077AULL, 0x7A1CEEF0185FD5D8ULL, 0x850CD6B526BFD5FFULL, 0xDF9ADEE2A11D945CULL, 
            0x7847C41DDCCEE354ULL, 0x0C291E09BD10C0F8ULL, 0x1E16CF3F7C296FC6ULL, 0x547FB2EF2A0A81FEULL, 
            0xFCC3DEDA6DA87B11ULL, 0x8CEDAF3F2624C187ULL, 0x20E0DD4EB752D717ULL, 0x1CB5A4B90E5228F0ULL, 
            0x7F39A0B5B4EC6F11ULL, 0x45E39192C6B27081ULL, 0x9431EB1CC3082393ULL, 0x701EF325BF7B507CULL, 
            0xA98BF22276DE01EFULL, 0x4DAD1E08120854C0ULL, 0xCF254358C9C734F0ULL, 0xD4F095BEEF286BD1ULL, 
            0x3E48C56BC073073DULL, 0xB06F54550163557FULL, 0x7121165877D9A4C7ULL, 0x6477A6B21489E9BBULL, 
            0x45524EB839C21A37ULL, 0x92783B686CC8E2A2ULL, 0x2DAF7C916A5BF624ULL, 0x0D6F487A7FFE243FULL
        },
        {
            0xB170F7796FD46079ULL, 0x694F7A801469C251ULL, 0xE7319A7A482BD8DDULL, 0x8EB979BA675F39B7ULL, 
            0x20A60DC1B1C8E6BBULL, 0x5A9B2BC7E270EB7EULL, 0x745B8A6D47C398DDULL, 0x09D40A9BC02EF815ULL, 
            0x9D64F65428E3DECEULL, 0x9168F7D3FBC01316ULL, 0xD6631CB52ABC86AEULL, 0x9AAF2B33618A5B1BULL, 
            0xC63E9A304FAAF6F9ULL, 0x1683AFE7A53FA7C4ULL, 0xCEB4B2F98EAAB2E0ULL, 0x6CB6278DE2512633ULL, 
            0xA9D73813A5E30909ULL, 0x5BC6C738754FD168ULL, 0x1310314CCB3FD345ULL, 0xF4E22B19B53229C4ULL, 
            0xD4AA5B325C63FB12ULL, 0x60527908484958F8ULL, 0x14FDD4815B8E0060ULL, 0x208398A5041F3460ULL, 
            0x5A35A7B8F5774FA2ULL, 0x6763329FDAEC8CE3ULL, 0xB77BC0A6AA8C042EULL, 0x4D38F303F79DF600ULL, 
            0xC830B07142BAD659ULL, 0xB29751B4CDB9359BULL, 0x2D619A0C23F96E1DULL, 0x1CECD21824285688ULL
        },
        {
            0x0B9602A1B414258FULL, 0x1353CC610F89B7A7ULL, 0x05D5511599A13129ULL, 0x5B0E555770290A01ULL, 
            0x9FEB34430A99997FULL, 0x041791387A8AB743ULL, 0x8986E7A75F96D639ULL, 0x78A59C19E82534A6ULL, 
            0xFCD3C27FB9F972D7ULL, 0x1C301E0A7D72A974ULL, 0x231F327FC946FB83ULL, 0xE3E4FD4671BFA8EAULL, 
            0x47E6598AC852CEEFULL, 0xC95DB000705ADA58ULL, 0x820477562957E42BULL, 0x27C0784D71FF143BULL, 
            0xCC3371945CC83E0CULL, 0x1E63DE1C95E3106AULL, 0x27B776C1AF9E29FCULL, 0x54B7CFBE5FF4F8A5ULL, 
            0xF9732EE4C686F203ULL, 0xDDAADFB3F0DA7021ULL, 0xBB857561BCBC0EDBULL, 0x9E6B9CFDC31DFA4AULL, 
            0xB8C36B6BA62BB02BULL, 0x9C3DF5515CAD1773ULL, 0x28E75A2553A482CDULL, 0x56946EC342E3B236ULL, 
            0x37C7FDE8877C991BULL, 0xCD9250A0F1EB1C56ULL, 0xBE40322B6939F0D0ULL, 0xA36853AA21F40EF6ULL
        }
    },
    {
        {
            0x369EE7C7A41FF66DULL, 0x067D6167FE38F9C2ULL, 0x391206815FD31145ULL, 0x608FDBA7FF423CE6ULL, 
            0x79D39A3D424EA2FDULL, 0xACF2EFA97AA31242ULL, 0x528E66D2D9D67F18ULL, 0xC188F43A928C4731ULL, 
            0x91B80E662DA02BFCULL, 0xB1A7B7698F4ACAB7ULL, 0x36A16B1DD7566235ULL, 0xBE8B6D9D2612F0C7ULL, 
            0xE5229E3B29C87DABULL, 0x127C3C86F04F340FULL, 0xA21ACB3C69F3DAC3ULL, 0x5B13D454ED7655C7ULL, 
            0x7B013DC5084CEEF3ULL, 0x453F21E55B7D0A4DULL, 0xAEB8AD75A99E1451ULL, 0x01D84949FCF669A9ULL, 
            0x8CB1C6A5185E8F49ULL, 0xA8F600565EB2053CULL, 0x463D8569C95C2BFEULL, 0xE2E5D35CBB9EC760ULL, 
            0xCDEC774CF28B18D2ULL, 0xBB26AADBD9BD9265ULL, 0x54E45813F4175855ULL, 0x3384F7B6D7CE2C16ULL, 
            0xAA0036BD1175BFA9ULL, 0x9926F9AB92C0F17DULL, 0x103901DAC96B9766ULL, 0x6E4A4FA2EE257838ULL
        },
        {
            0x4430F62EC57F4DE9ULL, 0x11DB45C2BD0D497AULL, 0x4DE2819B4217BE7DULL, 0xAD208AB2A199C4BBULL, 
            0x42989ECF119391B7ULL, 0x90AF52F15E3B67B5ULL, 0x5DE5BA387E51AA9FULL, 0xCBC2497C5B4D7B39ULL, 
            0xBCB38006EC815242ULL, 0x7B37D17918BCF235ULL, 0xA7AC83CAACAA9AF9ULL, 0x0CC60C1D4B12FA5AULL, 
            0x51450F180F58FC82ULL, 0x2C63FAA7F8C99E21ULL, 0xD8E65163EDA7740FULL, 0xDD34F8D3E50483A7ULL, 
            0x154AFC87B375A84EULL, 0x3EE7856E9A9F779BULL, 0x635262C367377C68ULL, 0xE5F5195711767646ULL, 
            0xDD18A5850998EDA5ULL, 0xC031F358583CA49DULL, 0x8D5C1B7377EBA5EDULL, 0xE99E2D1B04C0898AULL, 
            0x39EF431AB8F2AC7DULL, 0x0A85A0DC798C04B6ULL, 0x43EE9104CAA5B6D5ULL, 0xD4C73F67B5278244ULL, 
            0x40DB71A9E4B3604FULL, 0x688F90A46F946AD6ULL, 0x86A311B859BED728ULL, 0xD86CD9F0E08F0782ULL
        },
        {
            0xDD16B75EF8A01872ULL, 0xF9AEFCDC78D1D133ULL, 0xA05B3DED0CEDFEC4ULL, 0x72E902356F924668ULL, 
            0x5FC56C1B1F2A1747ULL, 0x948D60F91FD2DC5AULL, 0xEA5F27118DE41078ULL, 0xEFBF5C128EDEB64DULL, 
            0xD6B9D9D0944AD6DAULL, 0x0E6EE645DFE2C358ULL, 0xDC213A6E020E4BB8ULL, 0xF973A4B702455193ULL, 
            0x277DA89E21E6326AULL, 0xE06BBCF406316E05ULL, 0x7814DFE43F6CE7F0ULL, 0x54CD1E8F35E3B117ULL, 
            0xF77936B6510B90C9ULL, 0x9770B48D37B23190ULL, 0xD8F3B9A7869EDBEAULL, 0x0A557CEA1AFDB834ULL, 
            0xA1DE588A0218C1B2ULL, 0x645028363BED9F89ULL, 0xD8709895F14107C0ULL, 0xCA5B60C4824820B7ULL, 
            0xAF1326904BBB3C2AULL, 0x1B12103DD976688CULL, 0x88E32AFE2B127468ULL, 0xBABEEF497C50A20AULL, 
            0x21B6AC7029A4639DULL, 0xE71EA5A0C47847FDULL, 0x95D8EDBDCAE3D91AULL, 0xB187E1194CA39964ULL
        },
        {
            0xAC7C903824BF5019ULL, 0xE9B8DA974F3745EAULL, 0x12B6796462C4BEF1ULL, 0xD077037F560920BEULL, 
            0x51BF7BADCAEAE4E1ULL, 0x714CFE73D83C63EFULL, 0xDB2D9E40EE63D4CAULL, 0x6C34D40DE762CF91ULL, 
            0x280F81884EE14701ULL, 0x5A248FE76C56E26CULL, 0x94E92CCA926D8267ULL, 0x81E70D330C41A8E2ULL, 
            0xD3A184737D6AF1F8ULL, 0xF7EB357D1854ABA0ULL, 0x7B05A6D17CF4268FULL, 0x3B4068195E6D9114ULL, 
            0xA756782ECBFA7D5AULL, 0x968E381295466A8CULL, 0xCF782D0CB6E5730AULL, 0x6EC429FD2052C83EULL, 
            0x6B520ACA8BA3957AULL, 0xFD18D3D90FD6321CULL, 0x8AD62549402AA2B8ULL, 0xA3A7BF0AC17A2894ULL, 
            0xD156E65996EFBE76ULL, 0x00952D112B107D0CULL, 0x74B311DD788E5496ULL, 0x52754A8579D67257ULL, 
            0xD29433F8F83DE534ULL, 0x2D0F01955018015AULL, 0xB1A81A6F354CFF81ULL, 0xCE41C69CFA69B4D3ULL
        },
        {
            0x3A5EF7248239EB95ULL, 0x1D2A7AFB9EA541D6ULL, 0xFCCD78EFD796B3F3ULL, 0xACF5DACC32684112ULL, 
            0x71B5F878352C54DAULL, 0x73FBA3F24741DC30ULL, 0x433A84D0743A5897ULL, 0x3E05E37A96D5F821ULL, 
            0xBEB9F6FB903D5100ULL, 0xED6257B82054E443ULL, 0x314ABDB7EAB4F6A5ULL, 0xA9B499376FE9E33DULL, 
            0xBEAB7593B56B4F01ULL, 0x8483EE8EA6758157ULL, 0x676AFBEEBCFA2387ULL, 0x02872065FAC69C91ULL, 
            0xED9F5F57704B6F3DULL, 0xA5C618053DE6AFE5ULL, 0x68C30E50F8169A6CULL, 0xA27F8A1517273AA9ULL, 
            0x1B628F5123E7D651ULL, 0xB1D1738B791A3FFFULL, 0xFDC6666D3E6D8137ULL, 0xEF2B6E592F008F92ULL, 
            0xE6DD470FB39C49DCULL, 0x7CC697B1D0A7C031ULL, 0xAE7BC51B857C3BF2ULL, 0xD8C4F2E3FA41AD70ULL, 
            0x6BD1C42FEA5FCCD2ULL, 0xE72F37077CE4489CULL, 0xB14FA818A3A980D3ULL, 0x70F0CD3DC385F830ULL
        },
        {
            0xCEA12A6167ABC7CFULL, 0x8BDF0C34D5468D7EULL, 0xE1F12873FAAA1D9AULL, 0xA224DB87BF3BC947ULL, 
            0xF656368813615105ULL, 0x8031F8CA1641D360ULL, 0x83BA3751AEBAF850ULL, 0xF01F22F58ED1C4F7ULL, 
            0x5A3E3434624317D4ULL, 0x860C54223751A986ULL, 0x0070055FB1B4E440ULL, 0x1D23472DB59E4BD0ULL, 
            0x1D8405D5FF38481CULL, 0x05BCB7B73C12C7E1ULL, 0x6C06E918F01C78BBULL, 0x045CEEF7C62C50D7ULL, 
            0xA3CAA68FA6CB6ED0ULL, 0xE1695DF799917A7EULL, 0xC49905BEAA00C051ULL, 0x0CC265482B0AB483ULL, 
            0xB0143C734D0A7101ULL, 0xEFCF6D8081883821ULL, 0xE51275078C533FECULL, 0x697192699138CA4AULL, 
            0xA0CC2D4719814D09ULL, 0x1E335887AAA87558ULL, 0xB504216F7B8FBBB9ULL, 0xDFB90E650C1C876AULL, 
            0xB27C9FFAA7144226ULL, 0xEC08673D822A504BULL, 0x1B362A470BBEADAAULL, 0xCB45863379146F7DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseHConstants = {
    0x2DB52E5E6797A95CULL,
    0xF11918AB079C8D32ULL,
    0x85565F6A1F4FF250ULL,
    0x2DB52E5E6797A95CULL,
    0xF11918AB079C8D32ULL,
    0x85565F6A1F4FF250ULL,
    0x70124FFD2F4E3877ULL,
    0x15960A6FDCE9FA1FULL,
    0x70,
    0x4E,
    0x39,
    0x73,
    0x13,
    0x94,
    0x5F,
    0x1D
};

