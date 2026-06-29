#include "TwistExpander_FootBall.hpp"
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

TwistExpander_FootBall::TwistExpander_FootBall()
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

void TwistExpander_FootBall::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x8FD7EBE945802D1FULL; std::uint64_t aIngress = 0x950C6BB3FB01582DULL; std::uint64_t aCarry = 0x847D86AEF9C7A7FFULL;

    std::uint64_t aWandererA = 0x8CEA80FC0B863ABEULL; std::uint64_t aWandererB = 0xA2BA07368A17AA1AULL; std::uint64_t aWandererC = 0xD0C565207AC504EFULL; std::uint64_t aWandererD = 0xCD248B58C40CC38EULL;
    std::uint64_t aWandererE = 0x8F2377D3CB11B0F2ULL; std::uint64_t aWandererF = 0xF3F53C129B5B9086ULL; std::uint64_t aWandererG = 0xA0B8D6902B438B88ULL; std::uint64_t aWandererH = 0x96C51629ADB549EEULL;
    std::uint64_t aWandererI = 0xEFCD4A6B71DB848FULL; std::uint64_t aWandererJ = 0xEF5F080C01E3704BULL; std::uint64_t aWandererK = 0xBF7E0B3A80C1D2DEULL;

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
        aPrevious = 12465955273488855529U;
        aCarry = 15421509388776635367U;
        aWandererA = 12033515536556632132U;
        aWandererB = 16077250043701162103U;
        aWandererC = 14672992865810161797U;
        aWandererD = 14910383428207751732U;
        aWandererE = 10318150545737535065U;
        aWandererF = 16579980774623301244U;
        aWandererG = 13185046745120345300U;
        aWandererH = 12976394755237099585U;
        aWandererI = 12538982301171578686U;
        aWandererJ = 12197668985951487281U;
        aWandererK = 13479239777644448516U;
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
    TwistExpander_FootBall_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_FootBall_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_FootBall_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_FootBall_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_FootBall::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xA4EC53C574F8B30EULL; std::uint64_t aIngress = 0xD1617B2E46A608FDULL; std::uint64_t aCarry = 0xD6B41D410F470B4EULL;

    std::uint64_t aWandererA = 0xC92AE42AE011A6CCULL; std::uint64_t aWandererB = 0xBCC76955E1512422ULL; std::uint64_t aWandererC = 0x8D57BE73D7112EB9ULL; std::uint64_t aWandererD = 0xF5E81EA27A93DBA0ULL;
    std::uint64_t aWandererE = 0x865D445038761F49ULL; std::uint64_t aWandererF = 0xA3F20212249C81C7ULL; std::uint64_t aWandererG = 0xACBE11BB691E5ABBULL; std::uint64_t aWandererH = 0x92304F8FAA1FD896ULL;
    std::uint64_t aWandererI = 0xAA3B110B60E55D93ULL; std::uint64_t aWandererJ = 0x93F3904020C7B74BULL; std::uint64_t aWandererK = 0xE420D196CAAFBB34ULL;

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
        aPrevious = 9359090818088479143U;
        aCarry = 10269641392277136577U;
        aWandererA = 13798109093246869801U;
        aWandererB = 10515971939358338289U;
        aWandererC = 15038577052898607239U;
        aWandererD = 13565721707944999908U;
        aWandererE = 16283388368245644970U;
        aWandererF = 11922315045979131529U;
        aWandererG = 11028383331598314359U;
        aWandererH = 16269968718920679460U;
        aWandererI = 10400712902044355810U;
        aWandererJ = 16769412485182834233U;
        aWandererK = 12677336799657157305U;
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
    TwistExpander_FootBall_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_FootBall_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_FootBall_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_FootBall_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_FootBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB02B4625D4204614ULL;
    std::uint64_t aIngress = 0xD575E856CF78529EULL;
    std::uint64_t aCarry = 0xFA4337D4741DD3EEULL;

    std::uint64_t aWandererA = 0x97F6C16CE172BC1BULL;
    std::uint64_t aWandererB = 0xA9011CE128D3B594ULL;
    std::uint64_t aWandererC = 0x8F5CE14BC95D9C6BULL;
    std::uint64_t aWandererD = 0x8A3B2A77396646DAULL;
    std::uint64_t aWandererE = 0xD04BAA6E5FBE069DULL;
    std::uint64_t aWandererF = 0x94C7A7B5A6C05CCDULL;
    std::uint64_t aWandererG = 0xE3B1734B6C2BFDF1ULL;
    std::uint64_t aWandererH = 0x80B18CB7E3CA8C6AULL;
    std::uint64_t aWandererI = 0x8CF9CDFF68A81EC9ULL;
    std::uint64_t aWandererJ = 0xF74A329B34CE1049ULL;
    std::uint64_t aWandererK = 0xDE0F31561B80780BULL;

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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC, 1);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneF);
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC, 5);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
    TwistExpander_FootBall_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_FootBall_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_FootBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_FootBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_FootBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF870FB43AD5AA3DAULL; std::uint64_t aIngress = 0xFE521ED94CAD1345ULL; std::uint64_t aCarry = 0xE601B936B443DB22ULL;

    std::uint64_t aWandererA = 0xBA737C37AAD7C89FULL; std::uint64_t aWandererB = 0xBF32C7181B2F5F16ULL; std::uint64_t aWandererC = 0xF327BE8D9267906FULL; std::uint64_t aWandererD = 0xD24CCC9C2A0C60F9ULL;
    std::uint64_t aWandererE = 0xA55CE896ACCA7066ULL; std::uint64_t aWandererF = 0xCBAC2CED26B727BBULL; std::uint64_t aWandererG = 0xC65B9D143F0D1D94ULL; std::uint64_t aWandererH = 0xC0B34B6F98E4C914ULL;
    std::uint64_t aWandererI = 0xC71F9355BCFAACA9ULL; std::uint64_t aWandererJ = 0xA4B8ED8E91EE62BFULL; std::uint64_t aWandererK = 0xE03D91B4A56467B3ULL;

    // [seed]
    {
        aPrevious = 12787913696262317052U;
        aCarry = 12175007732240298593U;
        aWandererA = 17795963818729573736U;
        aWandererB = 17089994525047200581U;
        aWandererC = 14893071839201265783U;
        aWandererD = 11985001695595817105U;
        aWandererE = 16079733448138478750U;
        aWandererF = 16095890518055855896U;
        aWandererG = 10435199024102790375U;
        aWandererH = 14055033388193676851U;
        aWandererI = 12898102696946031769U;
        aWandererJ = 9731208300557448454U;
        aWandererK = 14318017051602207404U;
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
    TwistExpander_FootBall_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_FootBall_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_FootBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_FootBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 1, 0 with offsets 3678U, 3775U, 3292U, 4349U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3678U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3775U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3292U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4349U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 0, 2 with offsets 4001U, 7108U, 4364U, 3301U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4001U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7108U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4364U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3301U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 2, 3 with offsets 4060U, 4296U, 7115U, 1515U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4060U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4296U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7115U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1515U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 3, 1 with offsets 4499U, 7672U, 5305U, 5841U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4499U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7672U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5305U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5841U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 1, 3 with offsets 1520U, 593U, 601U, 1599U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 593U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 601U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1599U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 2, 3, 0 with offsets 1008U, 62U, 1675U, 1610U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1008U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 62U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1675U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 0, 2, 3 with offsets 207U, 577U, 672U, 1257U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 207U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 577U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 672U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1257U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 2, 1, 3 with offsets 878U, 646U, 840U, 290U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 878U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 646U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 840U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 290U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 740U, 1614U, 1449U, 278U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 740U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1614U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1449U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 278U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_FootBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 2, 0 with offsets 438U, 6298U, 1163U, 7654U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 438U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6298U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1163U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7654U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 1 with offsets 4493U, 2131U, 2447U, 4053U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4493U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2131U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2447U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4053U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 0, 2 with offsets 2220U, 6270U, 7706U, 7012U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2220U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6270U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7706U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7012U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 3 with offsets 2482U, 3539U, 2822U, 4278U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2482U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3539U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2822U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4278U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7103U, 1730U, 2929U, 1661U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7103U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1730U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2929U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1661U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 817U, 995U, 1932U, 1393U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 817U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 995U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1932U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1393U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1090U, 1617U, 2038U, 850U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1090U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1617U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 2038U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 850U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 2000U, 1779U, 874U, 504U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 2000U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1779U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 874U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 504U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 531U, 1122U, 1652U, 829U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 531U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1122U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1652U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 829U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 2, 3 [0..<W_KEY]
        // offsets: 239U, 870U, 740U, 146U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 239U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 740U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 146U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseASalts = {
    {
        {
            0x81936A2CBD5680ADULL, 0xDFFFD3231ECDA42AULL, 0xACF8A9125CDD5053ULL, 0x8528ECCC418B3231ULL, 
            0xA0C9A109C5853C0DULL, 0x21F54BFD9112A987ULL, 0xC437DDF2BC939AF9ULL, 0x0EAE5AA7C45B12FDULL, 
            0x7DE7BE3D3AEA1BE6ULL, 0x144F60F8BB6AED5AULL, 0x7D678168754B42D0ULL, 0x1A38D745951249ADULL, 
            0xE67DB302BF59A2FBULL, 0x0839CE1DFC9C2CACULL, 0x5E23A550C5EB731AULL, 0x047007A640FDD0A1ULL, 
            0x72EB9305450C4382ULL, 0x7AF81487D980951DULL, 0x727A1DF608AA6667ULL, 0xFCC6FA2BA10D0A64ULL, 
            0x02EFCA8C1AF16282ULL, 0xDEDEEF93F65F6B5BULL, 0xBFE03297D879648DULL, 0xE6BC6AC25286EEC8ULL, 
            0x8025831090BE3FADULL, 0xF0657EB95085015EULL, 0x4E0AF9948F3DDA3FULL, 0xB044E392ECAAFC98ULL, 
            0x723D0B19977B1F9EULL, 0xEF42F1677B9AFF29ULL, 0x5AFC47CF0B6A2C0DULL, 0x04F6996E10A5A401ULL
        },
        {
            0x5DD00E917DBD2D75ULL, 0x8CA19309D95400BFULL, 0x09C97E3E8974C448ULL, 0x62809633092FD407ULL, 
            0x1FBB51D3991187BDULL, 0x08599F2E63A81024ULL, 0x39F05D45B52BB6C7ULL, 0x64B0B6FAF557638FULL, 
            0x9AFA8EB2C0BE5FF5ULL, 0x71E93A9FEAAD6561ULL, 0x108B0AF6F741148CULL, 0xEE1EAC6BFC9F3983ULL, 
            0x1429DD8F748393FFULL, 0x4492CA8313FD9130ULL, 0x45531E69E6A9CD54ULL, 0x4D89CA084B721B64ULL, 
            0x3053500AB0412C3DULL, 0x7C28D923E51F8C09ULL, 0xFCB27DE828E05754ULL, 0x7604E7F03401F6EAULL, 
            0x0236ACF12682AE42ULL, 0x2BD3F41A9E9C7AD6ULL, 0x99B4A4825B912032ULL, 0x2AC8B7E77FEB0FDDULL, 
            0x52EF4B2086FF8273ULL, 0x6C4FEF6E48539814ULL, 0xF052FD83A7509D39ULL, 0xB2D19934B34EA9E0ULL, 
            0x6A67EB9C718C3D83ULL, 0x822A2608BF1F28D7ULL, 0x61862328CF5C3977ULL, 0xDBE8431CE1299BC2ULL
        },
        {
            0xBE68F4D2B33C7E82ULL, 0x4AAFF2F91BEA5F9EULL, 0x6C9B0517B533D3A0ULL, 0x4ADDCA6AC5A27722ULL, 
            0x4C7673C415C361B1ULL, 0x372F2A2CA1135B19ULL, 0xF272F44D0D019ABEULL, 0xA925563BE3EB1AACULL, 
            0xB2023633C6E97645ULL, 0x25E0EFD7CDB1D32EULL, 0x24FBF834D02D240DULL, 0xAA038272F4282E75ULL, 
            0x90D9D6988C005AFFULL, 0x2C052C4FC6663BC5ULL, 0xDAC619F308A8EA3DULL, 0x56E0F8BAD6DAEA5AULL, 
            0xF13FA3E46C3298A8ULL, 0x4FC319FD77B67440ULL, 0xF578AEC942E4A2A8ULL, 0x614C39DC3D2668E0ULL, 
            0xD8333794A7E3B1F3ULL, 0x8D3978E4DED94B6FULL, 0x4F418D17DDBB2025ULL, 0x7C0D170B5B2ACD11ULL, 
            0x9F8CA9956FE9AB14ULL, 0x86DF7AC8A9603FCCULL, 0x6C3E8FFE0ACAD5B6ULL, 0xB9CF5F331A247E43ULL, 
            0x15F623D31F3E3E7CULL, 0x0F128AC6A8DD97C9ULL, 0x86BDDADBE769A579ULL, 0x481CDB3CA10E0155ULL
        },
        {
            0xD315972C439BBA87ULL, 0x205C7CAF6D5FDD93ULL, 0x0B1EE37AD666F6ECULL, 0xB217A16B7D25FE59ULL, 
            0x8359DCDFE6C75827ULL, 0xACCDB722D7C28023ULL, 0xE2AF7F9702F11BD8ULL, 0xB1DC6F3A3A0304D8ULL, 
            0xF2047993152BB568ULL, 0x5B2123DA10627A8EULL, 0x483574E254414DE0ULL, 0x2DCC785942015B9BULL, 
            0x1BD8070A2ABBFA97ULL, 0xE711F76A14295566ULL, 0x9993D3A9B6030D34ULL, 0xC2A8AF630D7356C0ULL, 
            0xD1EB4489A64D9B15ULL, 0x23A996B0A56BAE96ULL, 0xF89927D122D6E688ULL, 0x0116AAAAF7F71EF7ULL, 
            0x57D226CA8423F459ULL, 0x5350BFC5CF5C3245ULL, 0x1D1C878D061F681AULL, 0x47DBF3CD592C581FULL, 
            0xA40A4387957B0A8AULL, 0x5C48FB15831E19CAULL, 0xAB6681D30C62D07BULL, 0xBF6F0408CFAF7FF1ULL, 
            0x08061763A6915A62ULL, 0xAD43785E2C98D8E2ULL, 0x83E6251F2D63F6C6ULL, 0xFF67D95559E71108ULL
        },
        {
            0xA3DE9A4A3212BAE7ULL, 0x3885C9D180B3ED25ULL, 0xD8EF5A5C448D79DFULL, 0xAB1DAC4224AD2AAFULL, 
            0x328C4039F902A548ULL, 0xC8464BD014844506ULL, 0xAADA3EA35F55DF64ULL, 0xED3DB749350058DCULL, 
            0xB3DD5C61A183B05CULL, 0x98A0651BAC8C0FDEULL, 0x168633D1D5BF5B42ULL, 0x08850E03B920A73FULL, 
            0xD9C69BB2D91660E2ULL, 0xAD7744E5CE0A4476ULL, 0x15582962FA54CFCDULL, 0xA7AF0167E64C76CFULL, 
            0x9A1FECB2005886A0ULL, 0x3A0DB6765D1DDE98ULL, 0xBDD80189B56908F4ULL, 0xBADF1660EDBD0619ULL, 
            0xF16961464B365AC2ULL, 0x941F1808C83FE5EAULL, 0xBF9809011558A442ULL, 0xBAB360FBF35ABA48ULL, 
            0x14162DEE8538E7B3ULL, 0x259609B6012E29ABULL, 0xA5A0EF717D7B320AULL, 0x59B64A2B304FCCDFULL, 
            0xCD8EA81C7EE2F5B9ULL, 0x299A337B33FFA3B2ULL, 0xC8D1CFFD2B9E5D44ULL, 0xF234FFB139B58FFBULL
        },
        {
            0xABF5E3EB5B6D99B1ULL, 0x78996FAE1539883DULL, 0x1CE385A53A42604EULL, 0xB8395DB0A154F61EULL, 
            0xB03F000162F6B68DULL, 0xEE36C875890EC66CULL, 0xD088E06299E19544ULL, 0xB253069CCC1DBB9DULL, 
            0xCF1B092A7DACDB14ULL, 0xE235A9AEC38D75A6ULL, 0x7F954262DF47B4A6ULL, 0xB85398E8AD61C5D2ULL, 
            0xC86C4CB3E78F482CULL, 0xEED5102BDF70F7A2ULL, 0x16C05305E37AD543ULL, 0xCE05F9182311ACCAULL, 
            0x2A28F72C9081E80DULL, 0xA692A85CBFC21E9DULL, 0x8DD96CC4A0030B19ULL, 0x317852076189F3A0ULL, 
            0xAFCD6A188025E8D8ULL, 0xC3D51CEA4670DE20ULL, 0x94C34A644B7A8DB6ULL, 0x5CAA733806E49E71ULL, 
            0x5CFAED6ACE4F30EEULL, 0xD27520AC448C4840ULL, 0x5EF67BAEFB14D96BULL, 0xC66FE589F1C15BEEULL, 
            0xE477536C2B276002ULL, 0xB085F1D4BBBEE95CULL, 0xE071085CAD50216BULL, 0x738BBBC8818DC253ULL
        }
    },
    {
        {
            0x4C8742C2FBD7BB03ULL, 0x7BBEB8D419799CCDULL, 0xD4022618372C394AULL, 0x49D2D68669F38789ULL, 
            0xB0411D657BE57DA9ULL, 0x4771CE34AD52005BULL, 0x38469670E8CE4E42ULL, 0xAF75EAB2EA60D14DULL, 
            0x58C2C87209A034E0ULL, 0x2D2B5B773630A488ULL, 0xCAC643AAC16C6CB3ULL, 0x3758AAE50B9E03D5ULL, 
            0xE288C32C1D4156C5ULL, 0x7C7BDFBA34EE760AULL, 0x3BCDD476426F59A1ULL, 0xE12C1CFCFA386171ULL, 
            0x4FF651BEA4FF09C7ULL, 0x0128F806BECD2E5BULL, 0xC35B119E8D40EF88ULL, 0x74EF9F66D27A785EULL, 
            0xE30C519F2B8133AFULL, 0x13CAC6A3C421E9C0ULL, 0xB6485DCABD02ED41ULL, 0x431F3376C91B9627ULL, 
            0xEA28C12CC1C41A36ULL, 0xAE2472E09D76723AULL, 0xF237F7FF227B0C58ULL, 0x831EABDA6BE66F6CULL, 
            0xCCC1ED57B12DA2DCULL, 0xFE0A953EF4C044ABULL, 0xE658C2A58FB3CF6CULL, 0x5C302777DEEDA9E3ULL
        },
        {
            0xBCE59EE8F7B916DCULL, 0x5E652F62E6077796ULL, 0x1FA70048D73DFA89ULL, 0x461EAF29EB926E1AULL, 
            0xA7504A9C724536B4ULL, 0x2543AA8830BD6D11ULL, 0xEC7A90A72DE708E6ULL, 0xD4CABD67362E2D71ULL, 
            0x950C77DF77B855DBULL, 0x632D0C355AA4DF79ULL, 0x5CF0812919DAD4E8ULL, 0xD914F396F63DCE3EULL, 
            0x1C45CCAB7847CD9CULL, 0x845CCEE4CBBD98A5ULL, 0xB1CE0981C3068EF2ULL, 0x195A42E8CCA38A3BULL, 
            0x0BF12064695B3B64ULL, 0x44E4CBF9FBA6F5E0ULL, 0xCEEFC086FF6FE410ULL, 0x68B25DC38FD3566FULL, 
            0x543CD7131BF2E3A1ULL, 0xF241746B98CADECBULL, 0xD80AF986DD694361ULL, 0x728A30D8C19AC9E5ULL, 
            0x1227BFD03B80A8F4ULL, 0xB6CE70955DA76A2FULL, 0xF9B7A024C1B76329ULL, 0x0983352F4480B7CFULL, 
            0xD30B54AEB2786B06ULL, 0x0E58BA93A9424124ULL, 0x83E1300351244B09ULL, 0x75E6AA943B93E9FCULL
        },
        {
            0x4CDE8251B1B56997ULL, 0xF49EAFD8DF135CA5ULL, 0x8E279455C03FDC34ULL, 0x00EB9EDC08D9E570ULL, 
            0xF2AA42F0C974DADFULL, 0xE009EA2915CA5A33ULL, 0x76651D1EEA2C6DF9ULL, 0xC1B212E765DE13CCULL, 
            0x780D2B6E86E02147ULL, 0xD35D434D12E4163BULL, 0x845C78ABBE20FE5AULL, 0xBC62C8A7AC76417EULL, 
            0x1C19A9DA55744CB4ULL, 0xE504B2ECC3033586ULL, 0x8097C5881B829048ULL, 0x244569369F230CCBULL, 
            0x2A04C82128FC67FDULL, 0xE41930A1F3EE34F8ULL, 0x3C5E06A387F917DAULL, 0x961E356ADD0A2DC4ULL, 
            0x39008626BC7A8CFAULL, 0xE84185B3AD8D6157ULL, 0x3601E391B506FF70ULL, 0x70157812053CFFBAULL, 
            0xB9D32845DEC315BCULL, 0x637514ED44D7657DULL, 0xEDA8C82B30969215ULL, 0x06AE7C7F256FCD3CULL, 
            0x9D2AFAC89146BCA6ULL, 0x04038F126CF9C6CDULL, 0x00B645F5835EA6E7ULL, 0xF2B64492A2A344F9ULL
        },
        {
            0x81E2AD6EF2E05E44ULL, 0x705AFFB810F624ECULL, 0x4857011769544148ULL, 0x21E5FDA511F7E21BULL, 
            0x153A4CD221EF4C95ULL, 0x28FD311F082AC12BULL, 0xCC5575F039005BEFULL, 0xBBB36730D497EFE3ULL, 
            0xD60234D3AEF67242ULL, 0x281831D4CE30077EULL, 0x65973A6EEF6695E4ULL, 0xC32FB291EB833E49ULL, 
            0x3F37928A626553E6ULL, 0xCD3021DD0A30FDA8ULL, 0xF67C5E14AF46AAC9ULL, 0x8D34047F76DE7941ULL, 
            0x11AEC349F18E140DULL, 0x382CA4E7C94FA0D1ULL, 0xA5EE8A977757B550ULL, 0x43FFC3539A6DC71BULL, 
            0x1CCE40D3661559E7ULL, 0x399D233B15E9F692ULL, 0x97A54AF7FECB6938ULL, 0xF5BC47CB1148F117ULL, 
            0x18F211AC34554477ULL, 0xD55746EB62FD95CDULL, 0x78CE3BC8FC842E88ULL, 0xC641696D0CC2B4A4ULL, 
            0x2D5DFDD04D2BB106ULL, 0xD986A7E2D1B5D1F2ULL, 0xB991A094D122B9CDULL, 0xF91E6C43EBB24149ULL
        },
        {
            0xE0D12E451AA47DCEULL, 0xAC23BBCA9B06F034ULL, 0xFB12C9C5C3E62D8AULL, 0x86E1F2448F40D036ULL, 
            0x7DFFE9DA1E46D2B0ULL, 0x6211BE5538365E36ULL, 0x3BB4EA767A0B3CAFULL, 0x071F68D47557167BULL, 
            0xBE1F6769B326BFFCULL, 0x15FB72C9495B259AULL, 0x8865B504BA69FEC1ULL, 0x9A2DCD5DA6695B36ULL, 
            0xD81F1A2016AFB1DFULL, 0xC97115F647BE48E3ULL, 0xA1E29BA70B0AFBE3ULL, 0x5153327256AF665DULL, 
            0x8F1AA7264FCCD163ULL, 0x7D936922675617AAULL, 0x9FD66358E185AF87ULL, 0xEAE945CC59C0E642ULL, 
            0x002D2206991AF6B1ULL, 0x65DE7F8D7BDB04C0ULL, 0x07CF4143A6BE2592ULL, 0xEF1F3CE665FC9D96ULL, 
            0xAC292734DF383AB6ULL, 0x9F0716ADA2276730ULL, 0xA063D5CFBC350812ULL, 0x64F200DFB44CBC73ULL, 
            0x8A9E414261EDD317ULL, 0xDFCEA4C45E2AE091ULL, 0x6AC31E6F170C104EULL, 0xB22268E5C1F7235CULL
        },
        {
            0xAACE28F275E52256ULL, 0xA7BD19372A3D7194ULL, 0x6C9F5E4597361F2FULL, 0x3E85A7E89BECAC7AULL, 
            0xEBDFB5C306177315ULL, 0x8AC64638E48BD05FULL, 0x3E82F88B79E7252BULL, 0xD8CC2E9AC58F1B10ULL, 
            0x17DF2408D8255361ULL, 0xB6C76B95F5803E28ULL, 0x59ED7039AD613126ULL, 0x170929FABD72CD30ULL, 
            0xF6E0868E3D3F705FULL, 0xB566E547C57C2636ULL, 0xBC8DF776B2BA9084ULL, 0xEECC221889E555CEULL, 
            0x77661A727CC7A867ULL, 0x52F8AEF8311CF8E3ULL, 0x9B49EB10D7012C5DULL, 0xEBB67843588E5D6FULL, 
            0xD17710E58F92A134ULL, 0xCE031EE1D11DB210ULL, 0x0C638E312650C0D3ULL, 0xF2132EB4FB12DC9DULL, 
            0x99A81B672DE37C54ULL, 0xD65AEB83C0681F42ULL, 0x55EF9011E9D7C9A4ULL, 0xB10848370ACAD17AULL, 
            0x43D8E8FC1F791317ULL, 0x2D3874C99A4B13F2ULL, 0xAAD9C1B3DCED4585ULL, 0xA94E7FC61884CF94ULL
        }
    },
    {
        {
            0x8846A63FAAA972A7ULL, 0x429A77C5B09CF570ULL, 0x2E862EBEFE070C7EULL, 0xA6D65C82EBF68531ULL, 
            0x21C13456858530EBULL, 0x86760F54106498F5ULL, 0xB965E5A7E542F6B7ULL, 0x6CA3D0070DBE1E4EULL, 
            0x7189622CB8F681ECULL, 0xB6C4D76545CF7962ULL, 0xCAA115ECFC244FBEULL, 0x779D5B0F2033000BULL, 
            0xDA780BD7B21F158EULL, 0xD40D7E4FFE6E96EDULL, 0xE1ED783C4A12B57FULL, 0x3682BFED69924871ULL, 
            0x2E720A0E5F75C7F7ULL, 0x931C18CF7E637A4BULL, 0x4C7F0D847C127FD2ULL, 0x67229B39CC7594A4ULL, 
            0xBC24B78FB3BB9436ULL, 0xF4B4B2325ABBCA7DULL, 0x7211F20F9FF576B4ULL, 0x6AC194307B962B8AULL, 
            0x3C1915C583031528ULL, 0x7E4FF049AE755F66ULL, 0xD9903F94CD60E269ULL, 0x1397C72EF4FD915CULL, 
            0x0C5E6B7FB1427AA3ULL, 0x2310FA1A90D14386ULL, 0x87BEA7A7FEA7B7CEULL, 0xCECECC05A91C4D99ULL
        },
        {
            0x19D45C99F3B27AF9ULL, 0xF6C848DD1CF075F3ULL, 0x527F90EB6DA06AB5ULL, 0x5399FA2845972DDCULL, 
            0xF914F28A3EB52CDFULL, 0x85D2633525574303ULL, 0xE4F5F0F2A1385A00ULL, 0x70FEC37C6E547C57ULL, 
            0x0E4160BD23B8A6FBULL, 0x67B3F2B60CD90EB8ULL, 0xCED5569E39B5196AULL, 0x5DD39C768E29AD29ULL, 
            0xD0F0EAC8BD2B25A1ULL, 0x9E675FA686ECF65AULL, 0x910FE5434D94C171ULL, 0x69A82DA52BA35728ULL, 
            0x32BC2347DEBECA86ULL, 0x9CEFF0EBCCC6190FULL, 0x092302D23B726895ULL, 0x35DF7AE7BB6E5F5AULL, 
            0x4A4DAD167FBFE07FULL, 0x231CC9736AB36C33ULL, 0x863E4D00BEDDDBD5ULL, 0xD45E60CC5084B84BULL, 
            0x34968A005759C520ULL, 0x83A4FB16BFDD165FULL, 0xBCD7686F22B5671AULL, 0xE21660E09CF1EA04ULL, 
            0xA0A94AB278B7CD59ULL, 0xAF2D33B834772163ULL, 0x9A54BCB39C696E70ULL, 0xCF1D3E3B6F5F0989ULL
        },
        {
            0xC358DC08FFF51103ULL, 0x3DAE18C631F3D081ULL, 0x0E6C207690EF250EULL, 0x15BF96A96C212E75ULL, 
            0xF4FE146429B2FC21ULL, 0xB281A5E38B740702ULL, 0xAA60617235DDA283ULL, 0x713BEF287E93075DULL, 
            0x307C18121DAF71A0ULL, 0xA31A85D7FA7CFA53ULL, 0x46F6018A476B6481ULL, 0x3BA05B98EC16856AULL, 
            0xB4299DF0A0090C4BULL, 0x38DBEDD495B46BCDULL, 0x34EC14E7C3882E8EULL, 0x320A11A38EC9778EULL, 
            0xE03D348180A704E3ULL, 0x0AD29A2AF5E12DA8ULL, 0x8A35AB55D4FC05FBULL, 0x16A8C2F6D48A3283ULL, 
            0x038C039345073E75ULL, 0xD64F02909DAFADFEULL, 0x2014E4EC88F46BAFULL, 0x09902B5E07C4D385ULL, 
            0xFC27383FA3712AC3ULL, 0x1B2DBBF4DAD0344BULL, 0xFD9B79C44E9777DCULL, 0xA096E1CAA4B54712ULL, 
            0x3996B437E1B68CF5ULL, 0x5512C845F2E53EEFULL, 0xB4528AED97B7C3CFULL, 0xBC42D1790CF4E640ULL
        },
        {
            0x9FC7C22D878555BFULL, 0x831D3CE6E2C5860BULL, 0xDAED2D0DA6BACE67ULL, 0xB261C98B20ECDF58ULL, 
            0x861242D3AD23EC0EULL, 0x1063BF7F9EFFB3A2ULL, 0x4E3103EC35C8689AULL, 0x57ACA9360ED34FB6ULL, 
            0xEAB4128AF2DC0213ULL, 0xECED6E75594B1275ULL, 0xE57B0A0E8FC908B7ULL, 0xE72673C318E54937ULL, 
            0x969389260E4CAEB5ULL, 0xCA38AD5A42BC7632ULL, 0xE0C7E08A6A09B913ULL, 0x6EC94038AE5FBB0EULL, 
            0x0E30B9FB35E4E8FBULL, 0x08F6413B39BE87CBULL, 0x26C8B955CF754FF4ULL, 0xAEE7A8FB5A51054FULL, 
            0x83CEEA1C786CF376ULL, 0xD919B83A08E1FEE7ULL, 0x6D0F95F2DEFD6CDFULL, 0x1B7CC0791B0644BCULL, 
            0x56213EB57632C4F3ULL, 0x989F1BFB623F4449ULL, 0x859EAE5354633904ULL, 0x3F8F8B5BAD8E7CBDULL, 
            0xA1654DB3226D026DULL, 0x4D07E14C8179E91DULL, 0x8C0872E7A076961AULL, 0x4E75CBA597551BDBULL
        },
        {
            0x23E3C5B87D4BE6C0ULL, 0x301AD123256E1C2DULL, 0xCBE67286303B96F6ULL, 0x208ED5BF7E899713ULL, 
            0x3722CF73174A0E23ULL, 0x97E868633C241929ULL, 0xA17059A9F27B0072ULL, 0xC27BE0E826EEE4B8ULL, 
            0xB01685D2CAE4EDCDULL, 0x1429331B830C4DCFULL, 0xAD2F62C5422B3E3AULL, 0x274F2EE4FD0C1188ULL, 
            0xF874F9825DDF95BEULL, 0x31A92304EA675438ULL, 0x8A300FB26D3C3AE8ULL, 0x9651FD81383A08DAULL, 
            0x9A5FCFC82A0BB6F4ULL, 0xE37992B265ACF66AULL, 0x4A49D6EC7D093774ULL, 0x3172F1F84D022C8DULL, 
            0x80FEC3E1D2A80F25ULL, 0xF2DC47E46843E617ULL, 0xB4A2C3B34F603358ULL, 0x53BAE210987A508AULL, 
            0x16BB08B9171826E3ULL, 0x02434579AE901D5DULL, 0x33E31EDFF0AF66ECULL, 0x80375B8FFA1FA064ULL, 
            0x8AA9DB86F14B0AA0ULL, 0x8F25C42720108A9BULL, 0x617324B4804C91FBULL, 0x557DE9D77E116341ULL
        },
        {
            0xA49AA5A57526B6A5ULL, 0x39D08504A5B7396EULL, 0xA5E0065CD3D6595EULL, 0xC7BA3107A1AA8E90ULL, 
            0x17B9361A5BDFCB9EULL, 0xD88B74350AB0BEC8ULL, 0x9C6DE52DE66527E5ULL, 0xD996CAD7FD84CD99ULL, 
            0xB5F7803672F2AD0FULL, 0x4B1683145AC07753ULL, 0x4356374F4C3A9A25ULL, 0xF2C3FBF236AEB99BULL, 
            0x7B10727949DFE72EULL, 0x02508975C4FBCDC0ULL, 0xDD5CC98A31361354ULL, 0x9F914861AD8166D7ULL, 
            0xD515BA0350C9BF80ULL, 0x2712F9F47D0CE19EULL, 0x9E6C57279BFF467EULL, 0xAC9CC61EF2ABB5C3ULL, 
            0xC19EEEA5157CBA6EULL, 0x945280A87C6D42F8ULL, 0xBFD3A814B0C2FD7FULL, 0xDD8151EE90528C30ULL, 
            0xB6FEFF39F0A8DCA4ULL, 0xAF6A7995FD4134C8ULL, 0x3C7C69A62801EB2AULL, 0x309C81269D1E6EA7ULL, 
            0xA2BAFF232C448002ULL, 0x75CF77BE4BB1C627ULL, 0x93EB4800D62BC16AULL, 0x781083FD466B266DULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseAConstants = {
    0xC907FCFD0821F6F9ULL,
    0x2A00BA3D66084284ULL,
    0x6B50BEE8F4AFBDBBULL,
    0xC907FCFD0821F6F9ULL,
    0x2A00BA3D66084284ULL,
    0x6B50BEE8F4AFBDBBULL,
    0x74EB9CA9798053FCULL,
    0xD971BD27DEE92E21ULL,
    0xFD,
    0xE8,
    0x77,
    0x8F,
    0x1B,
    0x10,
    0xA1,
    0xFB
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseBSalts = {
    {
        {
            0xED5E58367119B33EULL, 0xCB0BF935615A3709ULL, 0x19A424555705B627ULL, 0x61FFAA6392C0107EULL, 
            0x69AEFEA59064E410ULL, 0xC3F86D62D5D2A58BULL, 0x797D5026CB3B85E0ULL, 0xDEB8770D9EE4D4AAULL, 
            0xD4776D2570E47697ULL, 0xD51019910920917CULL, 0x1975A882EA3C9F35ULL, 0xEFF618A4C1447B02ULL, 
            0x2C2A269247B93EDFULL, 0x9E52059E77BD451CULL, 0x4337DF8C551EC47FULL, 0x4E72953B39F41585ULL, 
            0x734D0D076AFE8110ULL, 0xD10B044B40DC6B03ULL, 0x5BCEF25535E3EF2CULL, 0xCDB4D4D6FC651DC4ULL, 
            0x105165892718DB34ULL, 0xAE2692EEDAA1BDE4ULL, 0x0E3671CD51927CBAULL, 0x344DF90DC47271A8ULL, 
            0xD0E028AF3E39A713ULL, 0x43DAC0278A494A14ULL, 0x4E3F9A92526C2A42ULL, 0xF208C067F45A2E04ULL, 
            0x97E3D0FF80DFEDC5ULL, 0xA36F40EAFB6E344AULL, 0xF22B36DF888F82C3ULL, 0x4175CD81898CC1DCULL
        },
        {
            0x3DA1D66D7229BC1DULL, 0xB8253DF9910C04EAULL, 0x045968C3B608C44CULL, 0x6F726998FF773070ULL, 
            0xBD1750CAB872A6EBULL, 0xFFB2962F3C066771ULL, 0xE872604E2E86C20BULL, 0x0C2D7D281311C8D1ULL, 
            0xAEFA9F49B02A08CEULL, 0xBEB7F5A8D5EAA33CULL, 0xCCA766EBAF7434C0ULL, 0x6FAA49283D222710ULL, 
            0xF6EA373E5C6BCEC7ULL, 0x918680A33D9C419FULL, 0xDDD48E92D2DBDB29ULL, 0x96865005B0EFD142ULL, 
            0x05AE962E876E3BF0ULL, 0xEE5039623D8DE24CULL, 0xA306926A130BD915ULL, 0x80862E45159CF69CULL, 
            0xE8289521D665A65EULL, 0x7B9B1FA76C1354CBULL, 0x7282556918E259B4ULL, 0x2F5B200A91DF1566ULL, 
            0x290A8A8046846BA2ULL, 0x3DE2F74A50F0E780ULL, 0xD256A701A7AD537DULL, 0x929CBF5CACA180CEULL, 
            0x940CCA95E30C46E4ULL, 0xF5E6DB7D62DE16AAULL, 0x37E549D5A80C1302ULL, 0x07781DBB7FE11ABFULL
        },
        {
            0x385D2967386D67CDULL, 0x1D06EB15F431A361ULL, 0xC8EDB5510FA98E97ULL, 0x53734D9E2058910BULL, 
            0xB1406990B3163BE6ULL, 0x9ADEA5C73107E745ULL, 0x046D1AE655D147E4ULL, 0x6BA2C6FEFEB34A3CULL, 
            0x958E26695AB72118ULL, 0x9DE5B8AB16EF1F06ULL, 0xACD7A13F600C1D37ULL, 0x89D9F773FBA13C00ULL, 
            0x58C821437951879FULL, 0x93F0E09F62F6E8FEULL, 0x27F36B0D74D52535ULL, 0xA0523D5FDA94A53AULL, 
            0xB1E304504FBF1A30ULL, 0x28F8F9B3ACFC40DEULL, 0x733AD740D1C2FF87ULL, 0x5D7D921D47BB066DULL, 
            0x9B1530793A9306B0ULL, 0x882B324A4695AB53ULL, 0x607AF7B39969795DULL, 0x72309B3761F7C9EAULL, 
            0xDBA9C8634262D597ULL, 0x56B67F12B4E42D21ULL, 0x3BC24C0D22DF3D77ULL, 0x8193567C3D0E3370ULL, 
            0x6360864869DA20B8ULL, 0x062606A0339C549DULL, 0x452815D32F9ED24EULL, 0xFB08A7CCDC7A173CULL
        },
        {
            0xED904D64E593CF43ULL, 0x302AC84019135D55ULL, 0xFD91B70639C60564ULL, 0xC7F901F6C3DAA171ULL, 
            0xA07D8E8BEF8B1C82ULL, 0xF9266B48E2EDA10CULL, 0x8F8D0A970E10C23FULL, 0x225B9D389917219BULL, 
            0x0D6B370F09EED6FEULL, 0x1F7239094C00D58EULL, 0xD8E36DC87F9D2D6EULL, 0x43F04343E6E27C5EULL, 
            0xDE6C2A545E7742E8ULL, 0xB7C02AAB9EAD001AULL, 0x24DF92D4F29B1DF5ULL, 0x7C8B8E95F06EA388ULL, 
            0x3F8110B7A1F53CECULL, 0x028C59B02695BE10ULL, 0x6A1D6C6737C39EBCULL, 0x579FA98AB13BCEFAULL, 
            0x6F2A122F60CB5D47ULL, 0x91407B12C8B650BEULL, 0x612BC2DFC542C7C0ULL, 0x3D929A8A068D3724ULL, 
            0xEC932A0F36E7BC29ULL, 0x6CB50A3E3226D14DULL, 0x955F66B6443094D3ULL, 0x0117669B744F5404ULL, 
            0x6AD32A60BB9CB021ULL, 0xC2645D8A26B8568BULL, 0x7DAB3D28F5C08864ULL, 0xFFB33728D7CA59C7ULL
        },
        {
            0x37D8DFB7FA311AE5ULL, 0x3FEF0EA09E509D73ULL, 0x194261875EB06E04ULL, 0x3202ABE6E8483666ULL, 
            0x8A8BC29C7CC212E4ULL, 0x3F29E1B90FDF6453ULL, 0x4EF99AE700977178ULL, 0x6535BA65EF4D51DCULL, 
            0xEDC7A6DE3E2FA421ULL, 0x4C6464C89C8D4F15ULL, 0x8725FDCDADCD4544ULL, 0xA39D4BF6AC659E79ULL, 
            0x208542DA4E8DF3E2ULL, 0xB9C3DEB0B3EDC37CULL, 0xA2021ABBC594C526ULL, 0x0DF72215AE355FEAULL, 
            0x858BE926DD1634F7ULL, 0xF16EB239E327946DULL, 0xD9FA88A0EA0E15F8ULL, 0x7E2F5CC3CDEC5FAAULL, 
            0x180132756F399713ULL, 0x41CE3FBF7DC2B473ULL, 0xFF1AA39C68F5EB88ULL, 0x5BACFE582A7FCEC8ULL, 
            0x16364C38B8C7A314ULL, 0xF2C3D0CD8FE90EA4ULL, 0x05C97774D23660E9ULL, 0x92FAA8D538D2CB99ULL, 
            0xA5FEB2008EA5976CULL, 0xD05B2080C47EE636ULL, 0xE43263D2B175EB8AULL, 0x1361EDC4E7023C7EULL
        },
        {
            0xC719BAB9F18171FBULL, 0x53069343649B77BCULL, 0xEB45DCAEA754604AULL, 0xE894ED1CA22D4DA0ULL, 
            0x15324EB6724E046DULL, 0x970ED86AE2A03281ULL, 0xC08A46BE05834260ULL, 0x8A67C62C1B93839EULL, 
            0x9107D45D1B88570EULL, 0xAA0C875F46071E57ULL, 0x8B882D78E507C90BULL, 0xA7E5E9A3D73AD2CDULL, 
            0x70AF292FE193B66EULL, 0x44E275CD66DDB352ULL, 0x3D4DAB69624BA87FULL, 0x13F61B95D3A9E068ULL, 
            0x61DD3F3C8CBBD1F2ULL, 0x875E8C20CF9B69A1ULL, 0xA3FD35F52719AD17ULL, 0x9987B8C3AF356CDAULL, 
            0xE68B7B272981C69CULL, 0xEFF34F6F7B3362C2ULL, 0x7F7E43E2270A3BD2ULL, 0xC493AB0FB1A11C8BULL, 
            0x7354145C294E2B0FULL, 0xCEA5F0CA9683FA9BULL, 0xEF9340E04EF58A69ULL, 0xA3E708D06045CCA8ULL, 
            0x7CB8617F6321792BULL, 0xD18FD4E72FF2D1A5ULL, 0x480E0313CEBCD5DEULL, 0x73F90C387E6B6D7DULL
        }
    },
    {
        {
            0xD1688524E2D1066CULL, 0xB460227971500FFEULL, 0x801F9FB7CE1BC253ULL, 0x27DC51A1871A08ECULL, 
            0x56C7B8AB9644E3F7ULL, 0x17EEFE2AFA718C77ULL, 0x4C4321BB7FB8D427ULL, 0x6EFD7444A89CD6B7ULL, 
            0xF0B4BDC7A24A2CB2ULL, 0x0CFC09A39C973A2FULL, 0x63B537BCDE353A7BULL, 0x0972FC2FD59F858DULL, 
            0xB8E77A9BDBEFA375ULL, 0xC5C6C8B1F0A72BA7ULL, 0x8287B0C7C6EEA250ULL, 0x8156DB2DCFB1F4FAULL, 
            0x559D2C222987EC22ULL, 0x4482EB6EF2C4FA9CULL, 0x2D1CD2A3714583B1ULL, 0x85034A745AB339A2ULL, 
            0xA8F18A55438375A2ULL, 0xDE8AB90A27F9D596ULL, 0x09673E54EB192F48ULL, 0xD3EEADE4757D9975ULL, 
            0xBB32269C1911E422ULL, 0x14DC6A309F446E62ULL, 0xD95CE44032727816ULL, 0x5A5C24DEE90F625DULL, 
            0xD1156B421983EC90ULL, 0x7CCD9177E213592DULL, 0x26CFBE59AAF82A0BULL, 0xCE2F0CECE71F4A4CULL
        },
        {
            0x190B9EF8183E84A9ULL, 0xDC11C4C9173EB75BULL, 0x8F2C1B807601DA3FULL, 0xF2CBC9ECB9318E2CULL, 
            0x95DFF472E0C3E918ULL, 0xE2C8D351D63FFE47ULL, 0x27C08136762A7F9AULL, 0x6127185D00E6EDE6ULL, 
            0x9C7A56CD980D7C3AULL, 0x7503916DB6D9CF68ULL, 0x96EDDE97BAE72CA8ULL, 0x50A400CAD228619FULL, 
            0x92C5164F142B9529ULL, 0x365F7DF00440D00BULL, 0x12229290FB7C0845ULL, 0xDC6510287243D2E9ULL, 
            0x1F4CAE47B2F7BBF6ULL, 0xC014DF8786B59D87ULL, 0x10244B0E9684BF46ULL, 0x929A16B216DD30A1ULL, 
            0xF03DE8FCF79A38F2ULL, 0x6CB0B20E18EE1983ULL, 0x6E025FCC11B3BFABULL, 0x8D540E166678BACCULL, 
            0x3FF48CCCC3D7540DULL, 0x7E6541A7FB387F28ULL, 0x370EC483213E0F99ULL, 0x3161E7C023A4647BULL, 
            0xF6ED4E13CED51501ULL, 0xDD8EFDA61AD574DEULL, 0x1E62E46BF01E042EULL, 0x8AF730E3B8F5B8F2ULL
        },
        {
            0xCDCAABA3DC94D3C8ULL, 0x229CE4C9C4F40085ULL, 0x7B2E60B4A92B0638ULL, 0x56BE78FE32E426B0ULL, 
            0x28F15276444ED998ULL, 0x4187CB486A6C70C0ULL, 0xB9249758EE6F73D2ULL, 0x72D45AA658BD8CBAULL, 
            0xB41899F6C09A4659ULL, 0xF594039C519001EBULL, 0xCDA4CE03157EF8C9ULL, 0xBD6798402A5A5436ULL, 
            0x7AAB11C693CF880EULL, 0x74A53FC526C071BFULL, 0xBE056D4E477AA002ULL, 0xF225B7DDE1431FB1ULL, 
            0x056EEDFC99139262ULL, 0xD1DD0FAEA323F891ULL, 0x6FDD41A9C1B9F2E4ULL, 0x3C070F0AA2BCE1BBULL, 
            0xDF32CD124F712793ULL, 0x8CF90B9405CBB8E9ULL, 0x5D9A0095CFC48D8BULL, 0x61F2AE618C76E9A8ULL, 
            0x9035B8C556254DD5ULL, 0xD0458E3D2DC364A9ULL, 0x8A035A92CCA7F634ULL, 0x52E69BE026A39B10ULL, 
            0xDA9BE4590E75D797ULL, 0xB30FA84F5CBCE823ULL, 0x24AAC18F69DD939FULL, 0xC8A0E339B95C9BB2ULL
        },
        {
            0xD3FF8CC08116881AULL, 0x95A58DA2F44092BBULL, 0x6DAADBAB25C87A1DULL, 0xE98A7CB73AA47D1BULL, 
            0xA15709F16BA85767ULL, 0x1861CCB50C077039ULL, 0x247DC43651B76852ULL, 0xB123589A4C977044ULL, 
            0x9CFC0E147795F01AULL, 0x20BBD97832AFD931ULL, 0x0BA294AF31ED4867ULL, 0x32C6D642DA50B828ULL, 
            0xD92E2A6922AFCCBEULL, 0xA4A98F257065FF40ULL, 0xF40D1D95A9A1D2F9ULL, 0x18F538A1A184EBC8ULL, 
            0x5D3481341DA314FCULL, 0xA1B2386DCDA96A18ULL, 0x6CFE56B867CCC48EULL, 0xA12C557CB1A0ABC2ULL, 
            0xD9575E796E2AFC82ULL, 0x977E2B195EE47484ULL, 0x24C0680730D48151ULL, 0x53D277853401E47BULL, 
            0xEE5937ED54E82A4CULL, 0xC8EAE7BAB9196721ULL, 0xB7CA1158312E7E2BULL, 0x0950F015FEE46B92ULL, 
            0x62BB36BB80F707BBULL, 0x05C71B986F529BE6ULL, 0x6E7F42FA091EBDFDULL, 0xEE607AEAC136C85BULL
        },
        {
            0x01D9D5E1D133A5E5ULL, 0xBDD72C66800C8D8FULL, 0x8C3DA0B278970A17ULL, 0x42F896DEDD6DD6F4ULL, 
            0x520FA05AFF12CE6CULL, 0xABDED0996A80C7A7ULL, 0x8FF13471018DC5A1ULL, 0xDD8550A5430BED3CULL, 
            0xD8B83ED69231797AULL, 0x287181EEC4D741FCULL, 0x1FEC4D7EEE0E3EDAULL, 0x3147382236923D16ULL, 
            0x60E9FBC9B4DFE9B4ULL, 0x741E614B71B82BC0ULL, 0xFF7122A47FE162C3ULL, 0x0416D4936BACE5B0ULL, 
            0xEA6379A237D5468AULL, 0x7D58DBA44E5EE981ULL, 0xFE5C724D93D0FDD1ULL, 0xB69EE2C3A14D6E31ULL, 
            0x70A34C6AF5D4C193ULL, 0x75F5F7A4C3536FCAULL, 0x6EF78DC843D2F954ULL, 0xA91E74C35229196AULL, 
            0x706589ADEA3236BBULL, 0x8C7003CF99533E6DULL, 0xA2D5104AC88D217CULL, 0x4FE9D8A2D9831269ULL, 
            0x965B0E98F11063FEULL, 0x90671E63142FF4DAULL, 0x850EAE0E27162315ULL, 0x10351AC3825EF3C6ULL
        },
        {
            0x784DF136ED0F67A8ULL, 0x35DC8B8CAE574928ULL, 0xAD45F22E130E5587ULL, 0xDC3F383557E708AAULL, 
            0xF809848962EAF809ULL, 0x0FB4DFC085A6AB1DULL, 0x5F737CFD28F1D95EULL, 0x25603A5C154BD85EULL, 
            0x6FF3D6C28F9082F9ULL, 0x033B885AA7F8C471ULL, 0x12AE4F72BB2BB6DCULL, 0xB318BAFF4505AB66ULL, 
            0xD6218F9534802E8DULL, 0x4CC36FCFA565C8A7ULL, 0xC9E4CC6BB2A7C9FDULL, 0x776E8648E146E770ULL, 
            0x6831BFB7841365B9ULL, 0x77D9A6BF0490F5A9ULL, 0x8DF5317140796F6AULL, 0x619711FC3D7C7B72ULL, 
            0xF6B855C3D0ADCA42ULL, 0x7291E9DE65BDDD9BULL, 0x7AEC97903AB03BD9ULL, 0x3562509D324FE49EULL, 
            0x781A8DF806C3A308ULL, 0x12A20A60F85399CDULL, 0x77BC63CD27642ECEULL, 0xF354817D2D924A22ULL, 
            0xDEC6C1BD620ED281ULL, 0x3BAEF8B7647BAE74ULL, 0x4E7A173B124B5731ULL, 0xDB063AE687B1E8FFULL
        }
    },
    {
        {
            0x5A293499AABE0374ULL, 0xA1BD116FE16B0F29ULL, 0x5673D63D6CEE58F5ULL, 0xA6508442D6023E39ULL, 
            0xBCE9A1357982BB57ULL, 0x953E6B9F5605FE50ULL, 0x450327A3780D6A16ULL, 0x265D1C8DB4C3A46FULL, 
            0x2C95D1CEF591FF15ULL, 0x9134A2CF5AFA3B86ULL, 0xF5BFBADFFA426BBCULL, 0x2B6EED6103E99E9DULL, 
            0x2FC843E0D20BB5A3ULL, 0x61717DEB99496BF7ULL, 0x4FE0381DDF17B300ULL, 0xDDC0E4918503063AULL, 
            0x288E3A1F407D7F0DULL, 0x2224D2C28BD5252AULL, 0xB190BC363BF1EFD3ULL, 0xD6FC56FEC3B0CF38ULL, 
            0x233B54E605C0A50EULL, 0xD69A1C927B4D1381ULL, 0x826C538313CA1FEFULL, 0x5D8EABA4E3EE7F57ULL, 
            0x86AF98FB9618B6AAULL, 0xE585DE73EC7DDD1EULL, 0x82B08220827DEBEBULL, 0x7C136DC3F1FBDE21ULL, 
            0x2578FABB6A7DA2EDULL, 0x643E36E56385204EULL, 0xD2964CF7C85D17DDULL, 0xB5E1BF4501F87679ULL
        },
        {
            0xD02DF978C0FF7A48ULL, 0x70883B607BE1EE41ULL, 0x00ACE5C596BC18C6ULL, 0x78AF116B86C8C226ULL, 
            0xAC7331E516B835C8ULL, 0xC8BE71F89FBE8375ULL, 0xBB588D6ECEF37B27ULL, 0xC51CE5BC1F684C84ULL, 
            0xF76BB24F5D97606AULL, 0xEB9B91BF2345D8A7ULL, 0x722DE5AF6034599BULL, 0xA24E331D088A2B75ULL, 
            0x5006C84C25B8ECC4ULL, 0x0D627A1C3F17F7BBULL, 0xB87C8B6DC6A99F92ULL, 0x04CE61F11EC00CDCULL, 
            0xD4643349EE6CF997ULL, 0x02023ECD5E94C70EULL, 0x76B694B0C4B1BF49ULL, 0x6C11AA67A93E3946ULL, 
            0x8315D16C77C387EEULL, 0xFA381390918B06D5ULL, 0x3C4D8F0FCA59B836ULL, 0x90378B591545A33BULL, 
            0xFD1E59584FE1E0DAULL, 0x660CAAE374B5728EULL, 0xF99816F563EEB281ULL, 0x798BA6679E0974F7ULL, 
            0x1A6212FFFE0FC049ULL, 0x77DD3126F2559A63ULL, 0x1DB5E8F3BB8019A9ULL, 0x1905A7E56003531EULL
        },
        {
            0x67D10C56B6ECC706ULL, 0x6088D5C0DB51A458ULL, 0x0DC3C0F43148591FULL, 0xDB5F091826F861C0ULL, 
            0x3726383AD1324935ULL, 0x3D13BD7156C02F0FULL, 0x0D7EA8460817010EULL, 0xB44968D563E6B9D0ULL, 
            0x8323FF17528E6282ULL, 0x6BB45371F8B57DCAULL, 0x2B0688E0B49AFFDEULL, 0x0EADC5EE23463F4FULL, 
            0xFBBC592BB48B8403ULL, 0x302C202AB93B87A3ULL, 0x82E1206E64E744C4ULL, 0x754D675BF7E55141ULL, 
            0x2507404D31163726ULL, 0x975E51261EC5D30DULL, 0xAAC7D28341384EBBULL, 0x20980EE22ADE5BD8ULL, 
            0x334F50E3214D8D45ULL, 0x4840C122E6270096ULL, 0x7E6507522FAEF6A9ULL, 0x522F0FCBFBB0E484ULL, 
            0x1140DE7402363E59ULL, 0x4734A8AECC3864ADULL, 0x34CBA8F25AA2BC59ULL, 0x508831B28F8C21F5ULL, 
            0xAD23B060FA85656DULL, 0xE9843843407F5DCAULL, 0xF2594D3A2D87F35FULL, 0x179BB8BCE0DD1BA1ULL
        },
        {
            0x6BD64AB2D4C153ECULL, 0x6EA6A2958B62BABCULL, 0x6FD87C8FFB1A8280ULL, 0x27BB0B9010846A98ULL, 
            0x2F998AA0A5A3BCEAULL, 0x0A945B5F3B5BA632ULL, 0xA28F1404EE8FCAA6ULL, 0x7864F33066386DA2ULL, 
            0x001C90D1633215C4ULL, 0x6F34F0A478E7AB26ULL, 0x4D4733AB85E8DA0AULL, 0x27E3FDF4AAAFC75DULL, 
            0xA89C3B4EEBE300BAULL, 0x89FDE94741220877ULL, 0x74E9C111EB7846D5ULL, 0x11060A0443331513ULL, 
            0xDE0C3A33B53E8A30ULL, 0xEF5C5322B1D70E9BULL, 0x60FFD44C2FFF445BULL, 0xF6E61A4BE27DE320ULL, 
            0xBFEEC2DF82CE213AULL, 0x1E7432193D0457CBULL, 0xE3E3FF9CCDB7D2C6ULL, 0x59DB5DBBC755EF87ULL, 
            0x5A0C5834269831C1ULL, 0x183D56F2BA1637C9ULL, 0x6170BBF1FD851909ULL, 0x629B863D6CFE9778ULL, 
            0xB8DD925E8D9C1A43ULL, 0xC506664170E731C1ULL, 0x3725414279D5A8BCULL, 0x12B5D1B736FB6837ULL
        },
        {
            0x4E67A9E67672F8BDULL, 0x71194B60854700D0ULL, 0x317F19B1D3324804ULL, 0xADEDA8C38645EFFFULL, 
            0x0EACDB1116753E03ULL, 0x387D0D80C6005588ULL, 0x5DAF0D5D0B84454EULL, 0x444B3890ADF04304ULL, 
            0x2FCFB7B168004E4FULL, 0x572965DFC2981C7AULL, 0xDF4FB8732E782233ULL, 0x8CFE215E9195D88AULL, 
            0xE704DE7C16425D4AULL, 0x570EA2C3CE40BB1AULL, 0xB74D52BAF00B7370ULL, 0x9A29393D0B10DD4CULL, 
            0x479B02C8C3D6134AULL, 0x751AE615C9571DF9ULL, 0xAC4698C7AF3E20F7ULL, 0x482635F18AA5882EULL, 
            0x88E8AD4CEF369834ULL, 0xD51D4729B5F248FBULL, 0xF98F0A871DF92414ULL, 0xD7A1C7EE966E1562ULL, 
            0x75CAEDB50FC53163ULL, 0x84935E0E881F72FEULL, 0xC8BBDF5612FA78C7ULL, 0x6F8F06EC2AABDBE6ULL, 
            0x4B8E2447720854F6ULL, 0x6037796FD37D2FEEULL, 0x302BDEFCEA969C3FULL, 0xB12E30A87A53886FULL
        },
        {
            0x96661D32298044CFULL, 0x7F0FBFA3EF728276ULL, 0xF6D87A0F29E95FD1ULL, 0x7D19403E56C521ACULL, 
            0x005ABA3662974AAFULL, 0xA3E1ACB690AA129CULL, 0x35EB9B5BB623EF1DULL, 0xFC07834E170AC09AULL, 
            0xC5D660B25101B5BDULL, 0x34B2A25FA1D91950ULL, 0x1CF606A136045034ULL, 0x51370445E774112AULL, 
            0x807D3E5771017CCAULL, 0x96908E9BC0DB1D50ULL, 0xA190D092BADBA889ULL, 0x91756C9E0A50EDA6ULL, 
            0xDFDEBAAE55707858ULL, 0xE0D5F27E06B24575ULL, 0x366F42562C75D3BFULL, 0x5F41E777A0F40AD7ULL, 
            0xCB546BFFBAEA25B0ULL, 0x13DA9E02231EC07BULL, 0xEB614B84F3E354FEULL, 0x540DEE40832300F2ULL, 
            0xF1687873A8E356E1ULL, 0xC46882A45A8FF2EDULL, 0x16ABF7ED08C7611DULL, 0x1288EA728ADBC945ULL, 
            0x242FAA31C944DD27ULL, 0xD838A3E1A8404E63ULL, 0xD48EEA4452CFCC3FULL, 0xE28E9C9DDF3959D2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseBConstants = {
    0x5C0A6679EF01B3AFULL,
    0x11BBB29C69B7A3CAULL,
    0x581684DA6FD57C36ULL,
    0x5C0A6679EF01B3AFULL,
    0x11BBB29C69B7A3CAULL,
    0x581684DA6FD57C36ULL,
    0x21DB4B59E8A775FAULL,
    0x0983D5947F419E63ULL,
    0x5E,
    0xB8,
    0xF5,
    0x79,
    0x67,
    0xAB,
    0xA6,
    0xFE
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseCSalts = {
    {
        {
            0x12860D186ECC3F2CULL, 0x3FF6E27A133D8CAFULL, 0x960D2C22A257A4ABULL, 0x14DC81612B462D96ULL, 
            0x948C35B1DC591240ULL, 0x91C6371EAF066211ULL, 0xD459B6E150C16C38ULL, 0xB4EF50509588270CULL, 
            0x51C3D420D96F8174ULL, 0xC1338DC1250965F9ULL, 0xCB714B78C94E354CULL, 0xF1B8A61B48354FDCULL, 
            0x8FF7ECD4B1CC2C66ULL, 0xD7490394ED52F5BFULL, 0x7CA5796460AEEDE7ULL, 0x1D05147B0A8D5D3FULL, 
            0x00FBF3409B4D12AEULL, 0xB67F7C4CC88E6DF2ULL, 0x24420C3435560FBEULL, 0xF733CCD55C6BA0EBULL, 
            0xB73A724DC4BAE82FULL, 0xEDB3BA8BBFEF99CBULL, 0x20F1B6A41E567B02ULL, 0x61A28C201B419E05ULL, 
            0xF3F956E78190CD27ULL, 0x0304A315C99F2ECCULL, 0xB1ACFF537A7AB9D0ULL, 0xA156666B8F2ABA55ULL, 
            0x75F9BD6FAD09E24BULL, 0x187F1B705EF6B8D5ULL, 0x20EB2D6BC5866ADCULL, 0xC3B8C997AA7A1C5EULL
        },
        {
            0x153AC184F69B4C7EULL, 0xC71D61A0B5B6F8C2ULL, 0x9723B83C4EB46C44ULL, 0xD496AB166348EFFAULL, 
            0x6936CFBFEA49E27EULL, 0xD57E743941FDADF8ULL, 0x64AC03D710C89C83ULL, 0x88E3135D5E3A427BULL, 
            0x85CB352DD0304CC9ULL, 0x417C70231A2C91C1ULL, 0xC69254B3692102BEULL, 0xCBC6D90F8A8A3C73ULL, 
            0x881DF201A8E17C96ULL, 0x57EF83EDE6183386ULL, 0x7FF2FB492A6CBD1FULL, 0x85D75FF8CA89C7DFULL, 
            0x0D4B541685E7E289ULL, 0xAA4C0372C15863BCULL, 0x4CEC362869E2757FULL, 0x00499660069F559DULL, 
            0xFD32432B8FFBCA62ULL, 0x29F4D79F994D36FAULL, 0xFF4F55AE77D35F97ULL, 0x9F102548D8067E16ULL, 
            0x3272B593AD0999E6ULL, 0x7AFCBF4959126DE3ULL, 0x471CB8558AFAAB0FULL, 0xECE6DD75A01AFEFEULL, 
            0x3C7D2ED1F46C8979ULL, 0xE53373AD60985588ULL, 0x31DD13A8CB57A563ULL, 0x277F2228BE16CCE0ULL
        },
        {
            0x9F77F8F868EE82D1ULL, 0xFF430ED28B13B6B8ULL, 0xAD7375711C88459BULL, 0x4BB35EBA13DE5584ULL, 
            0xB46EB064884F1B88ULL, 0x84BB83418AF6BAFEULL, 0x43A1DD51255502C3ULL, 0x4584354E4ADB752BULL, 
            0x9F80757C059FD415ULL, 0xADF5056B524F05B5ULL, 0xDBF698551A9B433DULL, 0x5987DDB62FBCEC3DULL, 
            0x5521819CB3B6138BULL, 0x7104452290404073ULL, 0xBAC40737447F913DULL, 0xCB8C4AAF86969AB9ULL, 
            0x5FECBD728E455E11ULL, 0x1FF7DF3DE99CCE7DULL, 0xA9968C6BD103A241ULL, 0x9CFBCFA54C518D69ULL, 
            0xA897CAEF2F4ED054ULL, 0x79A43160864CF2CAULL, 0x95391448C3F8AAF0ULL, 0xE02C640846781C74ULL, 
            0x54D78382C803CB07ULL, 0x245DD345DE57F328ULL, 0xFF62CCD253E82E10ULL, 0x8094049C15769F8FULL, 
            0x74495CC59B7DA811ULL, 0x27FC29D8CA246DE3ULL, 0x260568F1328792CDULL, 0xBC08A2028F0603C3ULL
        },
        {
            0xE2CDC2675E6EAA86ULL, 0x959BAAB0B9F403A4ULL, 0x15C8B99542A14E1EULL, 0x791C94E474230311ULL, 
            0xB3994A2CE64390FCULL, 0xCF1E22971CB6BE45ULL, 0x7A1522C0744AC38CULL, 0x25F946029B66B28BULL, 
            0x1D94A4ABC3574F06ULL, 0xB5B015060FE830E3ULL, 0xE3E0AC839594D6E8ULL, 0x6F1F67EBE565737AULL, 
            0xC776DACF31597B82ULL, 0x2BBD9E270266CA9DULL, 0x2C02ACA3B55DA52EULL, 0xE20FAD1DE856A7E9ULL, 
            0xC3FBB554ADCA291BULL, 0x8306ED760FCFFA87ULL, 0x03BBBAAE6C0C09F2ULL, 0x02021C52DE2877FDULL, 
            0x765CFFEF84FA4D36ULL, 0x68BDA4A43EB2F38BULL, 0x1E2A506635735371ULL, 0xCF69A4D9BB6A586DULL, 
            0xA7DFE3B343012209ULL, 0x030B76BECC5A9973ULL, 0xB552269BB35CF133ULL, 0x4B7D2793AB0DB2A5ULL, 
            0xA8042664DC431F57ULL, 0xC6547EF8A929EB82ULL, 0xCCD632CB755AF310ULL, 0x813ACA353F8D58A7ULL
        },
        {
            0x7E4FD40DA52B9B08ULL, 0xFE295BBAFF6982C9ULL, 0x1390665F7A82DDA5ULL, 0xDCCDF376DF084A2BULL, 
            0xC51168A9BB455911ULL, 0x821A6A3147E807D1ULL, 0x7CF0AECA1BF6EFFAULL, 0xF3264A6E0844762FULL, 
            0xEF071906B43BD0E3ULL, 0xA7F96F7B17657634ULL, 0x0B030A2CBF07BF04ULL, 0x9E9960A4CBF343D6ULL, 
            0x24CE37D206C9C6B0ULL, 0x68477208B8DD80C2ULL, 0xA616A1C8F89D580DULL, 0xCCFFC7E46169DE20ULL, 
            0x39FD6123FC58B5C7ULL, 0x5485363BFB9EFA42ULL, 0xC38C1EF8D96EDC76ULL, 0xFD0CF4DC989C3684ULL, 
            0x34155383A49E4179ULL, 0x563D0ADC92719BEDULL, 0x0897446B5A3CF59FULL, 0x2938B5DAA65EBEA1ULL, 
            0x8AA02ACAB76AA813ULL, 0x1233680894ED4AFCULL, 0xDC90031E16AC1477ULL, 0x144BBDB0037643CCULL, 
            0x9A09DCCE0664635EULL, 0x7BB054DFB88D7141ULL, 0xB59297FEC022988FULL, 0xAD1618794A3BE64AULL
        },
        {
            0x37E168AD7C10B9A8ULL, 0x6822D8D674D78291ULL, 0x815586318B09A892ULL, 0xFF39CD78DD990B3CULL, 
            0xAC32146C5F82A596ULL, 0x1AC9921BABC48CB3ULL, 0x93A946A01FCFFE41ULL, 0x5D4598D110EAC7EEULL, 
            0x7C7630B15AA221C7ULL, 0xE673A98F3F19FD07ULL, 0x25941481575E218EULL, 0x08A2AB29B55BD9EEULL, 
            0xC7BF83829E81A3A1ULL, 0xAE62EE82ABB5D26DULL, 0xAE4B524A2C750A7FULL, 0xC1CCC8B56366362FULL, 
            0xF3FA4103A6E34D84ULL, 0xBC38D204773CF018ULL, 0x0FB6DEEE07DF4F75ULL, 0xEE4CF7660F3B265AULL, 
            0xF3D571E3B2FB9A11ULL, 0xE3C3F58931B23663ULL, 0xE9931709CC2A43CFULL, 0x419C917027F20EC8ULL, 
            0x915806463DEEF6BFULL, 0x18B50A42A251B0D6ULL, 0x9A6C4F901A8D06A5ULL, 0x2103FB36700528C7ULL, 
            0xC454AA76EDD0BB5BULL, 0xB2F3ACD62528C435ULL, 0x0A8971C7C3DB5C65ULL, 0x9523640B21CC3344ULL
        }
    },
    {
        {
            0xBE0ED95D96966CA0ULL, 0x680814A7C3262373ULL, 0x264621D599F603A5ULL, 0x76366AD855ED725DULL, 
            0x47646D53237021C9ULL, 0x1274E2076F269913ULL, 0xDEC38BE93EC1E76EULL, 0x7E62250070BD9063ULL, 
            0xBEF19173963CD836ULL, 0x0381F7BA55D96087ULL, 0x3B3701129A1994E2ULL, 0x13741CBE827B45B5ULL, 
            0xE6328BF2ED1D13BBULL, 0x0FFFA1E13C5DB54CULL, 0x2CB0F69275019E4BULL, 0x2DA62F1A16ADF2B9ULL, 
            0xC9EED177026ACA49ULL, 0x8526338DE0E5094DULL, 0xE1EEED1B3520FAB8ULL, 0x3C73ACD3DE8F6E5CULL, 
            0x323D87D90503891DULL, 0x2CAD6034B431FFD5ULL, 0xC5B555DA52EB9530ULL, 0x8CE9B8DEF0716B7AULL, 
            0x852C3496E8EB3428ULL, 0x8814F4E5A14F4AFDULL, 0x475C1A965AE8BCACULL, 0x35F78F7AF1C4C5C1ULL, 
            0xB1148AFCCFD85DE6ULL, 0x503AEC2C72F456F6ULL, 0x20D4262168209F6FULL, 0x4A5B0C045AC9D9F3ULL
        },
        {
            0xCB7D1C933E9D8A07ULL, 0x59E2CA5B3FC40F2FULL, 0x856700146B0E4668ULL, 0x70DF21A62D6AB866ULL, 
            0x90BFDC2CD7F8F355ULL, 0x55562F89A881344DULL, 0x804187C64C84EFFAULL, 0x2712532FE91383D1ULL, 
            0xC314F13B14BB7DFAULL, 0x03297360D7FB83B3ULL, 0x5498F0AFEE3DE348ULL, 0x5E85CB11B6C7FA42ULL, 
            0xE364E41EA44A5C21ULL, 0x4113BD67B329FAABULL, 0x5C1BA28844F8FB3AULL, 0x29D3C48A14F1940CULL, 
            0x96ABE6302767A6B5ULL, 0x285C5578D6C3E622ULL, 0xCCC334552917979FULL, 0x3AE1689245D698C2ULL, 
            0x98359A4446ADEEDEULL, 0x0A6639BCA523799FULL, 0xE740B6BF68FB2C7DULL, 0x70FF42BA713F8776ULL, 
            0xA7605232C7717FF7ULL, 0x4BFD5D77176E85B0ULL, 0xEEF6C04592E454F0ULL, 0xBFBF2489C599A4C6ULL, 
            0xB32D482A15BDB2E4ULL, 0xF33201B006CB8EC4ULL, 0xFA8038C31958D78EULL, 0xDBF26D03EA78DDD9ULL
        },
        {
            0x8578E8D4B26E565CULL, 0xA107C2A6E7B34D49ULL, 0x16B05E79FD861EEAULL, 0x69A674795449FBEBULL, 
            0xC39BEDA15E88C661ULL, 0x85A773FC6B82F2F9ULL, 0x633CB1B60BF8822FULL, 0x11AC4CFF991F2D68ULL, 
            0xEA1CEE564FA3A617ULL, 0x380BA0DBB50E7A61ULL, 0x094FF60E62727A29ULL, 0x18728D81FD817F14ULL, 
            0x9A4B72FC04BD696EULL, 0xF8813ACBD7849404ULL, 0x534B65B358DA36FBULL, 0x2D47B9316E00AB71ULL, 
            0x380711B67ABBA55DULL, 0x95F528D78538840EULL, 0x076CD8F584B4CADFULL, 0xE93D4C2B06B63715ULL, 
            0x6651D6898D98DEC0ULL, 0x5E04F662FF69A467ULL, 0xF54852C585B62E6BULL, 0xD1E498FDEC2EA6CAULL, 
            0x84B1049C3E6DAEA2ULL, 0x2C4C5FFACBFF2A86ULL, 0x8FDE069045224665ULL, 0xDBD04CEA778239DBULL, 
            0xDA6CC916DB95A6A3ULL, 0xDAD01C2DFB5310A1ULL, 0xF9767FBF79B4D877ULL, 0xF73BF0E99EAC7CB4ULL
        },
        {
            0x82D5D4F0B557B89AULL, 0x944C1AB32057F0A8ULL, 0xB2D31EFFB6AD88ACULL, 0xC79C82D3C9A493F8ULL, 
            0x1C07804B31C6A478ULL, 0x11B9D0D887E9ECDEULL, 0x8B1682287D8659E9ULL, 0x1BCE02F50833DB98ULL, 
            0x5A20CA79D8C7219EULL, 0xBC31B1264793D041ULL, 0x223C3BBDF81846DCULL, 0x068379634CB5B502ULL, 
            0xF5F285AE69B60DB3ULL, 0x50E56B5C1ED069F1ULL, 0x0F44869C4AEEB8A9ULL, 0x076929BBD50066F7ULL, 
            0x5B657973078CB0ACULL, 0x1792B8B63F001C15ULL, 0xCBDA198ABD8B752CULL, 0x75D3302B8F4214FFULL, 
            0xB211EF581503E0B1ULL, 0x94BD8EB5A28ED6C4ULL, 0x3FEE98D7648D6112ULL, 0xF558E6188C9CE017ULL, 
            0x17C1217C0AA5ADFBULL, 0xA0662A86A041DB10ULL, 0xF5BA1AC7DABD7DF6ULL, 0x893978E97B60A6E4ULL, 
            0xC86D5F3D4A9E6FABULL, 0x62878BC4D8804CD8ULL, 0x2B5914B3B35E0653ULL, 0x2A5D575427F7962FULL
        },
        {
            0xE0EE0A3B120394D0ULL, 0x047C5DBBEE2B9418ULL, 0xF2AE2BE534C58E50ULL, 0xCD7D71692B4FED03ULL, 
            0x6B91781D3BB62056ULL, 0x32B0B4EA1F82A44EULL, 0x6192E87294367AF7ULL, 0x53EFBD1F07C8A8A9ULL, 
            0x65079C250DF7CE0BULL, 0x3346FE35A7AEB1AAULL, 0x7327B7D4DE3B309AULL, 0x19D7FFAD875BA9EAULL, 
            0x14A552823A47974EULL, 0xEB41E6505476ABCAULL, 0x613BE5D6EBCCCD0CULL, 0x8F1B1EC05DCA0D40ULL, 
            0x02BD8EE8CC6E7BF3ULL, 0x840CB3EFA61F34D2ULL, 0x21CE16CC13CE89FDULL, 0x7CCC2936B0EB7406ULL, 
            0x4A36C4790DA4E9E3ULL, 0x23CB0FF9969B0FABULL, 0x6C2FD07C4C95094FULL, 0xAF6B5279DBB2CEF7ULL, 
            0xFF2C49ED1E892DE6ULL, 0x4663C9C7FEABFF93ULL, 0xB4A7354460091E22ULL, 0xC47BBF930296E604ULL, 
            0xD38B601921C98992ULL, 0x6FF16E8D42A8E0AEULL, 0x4E11B74D254FAA96ULL, 0xEA3C90D00C34BE7BULL
        },
        {
            0x58483E37808F86D7ULL, 0x84D14FC72105E286ULL, 0x0F0088911038DF4CULL, 0xCCD3E41FE48D2A89ULL, 
            0xDF36426A058FD773ULL, 0x3DE02FB687E1544DULL, 0xE5AEC97B9D5703A2ULL, 0xCD602614FC83035FULL, 
            0x5763AC1C4512C2C0ULL, 0x0A62F39EFF259966ULL, 0xC7F3A9EA1CEC90D1ULL, 0xC192CE625D6F892DULL, 
            0x874E7BD7A061EC66ULL, 0x60DDABAB93C1F677ULL, 0xF352A8F6DCAE7B10ULL, 0xF0564387ADD009B3ULL, 
            0x3F60173F1A6EAD85ULL, 0x9A16EC99D9DA6E12ULL, 0xB66DF8F0F2F09CA0ULL, 0x124593600B490E1DULL, 
            0x73E383AAC9A6D136ULL, 0x50BE85A4198FC94CULL, 0xAD7DB6E85B4B3048ULL, 0x9093AF7D1338AC07ULL, 
            0xA2661A691C4147F2ULL, 0xB62BE1990274B209ULL, 0x955ACD381273E90EULL, 0x57014A360482DF2EULL, 
            0x4B9003AD5E3FB953ULL, 0x91D88282E8DF32BCULL, 0xF01CB864BCA1C148ULL, 0x915B1AAA5AD117CEULL
        }
    },
    {
        {
            0x873B8AF5107279C0ULL, 0x102114C0BDE6A038ULL, 0x4A210C9FDDF47145ULL, 0x263A557728FA98E6ULL, 
            0xFAEE45DE1494B683ULL, 0x271A81265741B911ULL, 0x78BC38DCD634A21BULL, 0x5FF91BB28EE3A1ABULL, 
            0x62B3F6DE18C27538ULL, 0x43A54E5C0F2F6D79ULL, 0xCDCF7C88C44D9173ULL, 0xF3A9155424BD6B30ULL, 
            0xAC160F13985152BAULL, 0xB1FBFEA0E9DF78CDULL, 0xAA4ED54980BA989CULL, 0x945532E3CC9712C1ULL, 
            0xED1D886ABEC3B4CAULL, 0xF84A08B5052CE3D9ULL, 0x04023C638BA8A4B9ULL, 0xB9D09D90EA7FB31EULL, 
            0xBE9D06B4DA2A7617ULL, 0x10542409CBF11D2EULL, 0xD3318058891E89C8ULL, 0x8046C57A9B768F0DULL, 
            0x06AF509203BF4948ULL, 0x6DDCB6FE185BAD94ULL, 0xFD94E7FD976A4F20ULL, 0x200E84B4BF37C012ULL, 
            0xFD0CA05BFC1BFDADULL, 0x076F1AA0B4C36698ULL, 0x1AB697F0FBC2E4ABULL, 0x5F13223E6D7009B4ULL
        },
        {
            0xCDB14EA5E7D34FDFULL, 0x12746E9AADFDDDB5ULL, 0x3C5FA4F7B009A279ULL, 0x8A37482302F75752ULL, 
            0x354B76FECE913DC5ULL, 0xFE1FC11517804D7AULL, 0x6E184D9153D63F44ULL, 0x49EF0BFA4A1192DFULL, 
            0x8EFCA28DCC0D212BULL, 0xA0436B18844D5BD8ULL, 0x7409287DFDB0939EULL, 0xED877E6025E677C2ULL, 
            0x7055EC85A656F549ULL, 0x0F9623463AD5ACFDULL, 0x098ADEC14506AF0FULL, 0xD8E3C0B331E810ACULL, 
            0x5D8AFAB9D63AD1EAULL, 0x38BF261E049F1764ULL, 0xCE5D9FA04AF858A1ULL, 0x25DA19309AC54B29ULL, 
            0x363CF6E77A34C542ULL, 0x1A0D5E2FD9555B7FULL, 0x4998B83633AF1AA7ULL, 0xCCB0B98F749654BFULL, 
            0xBF9080D999D02621ULL, 0x23AC9B63EDE195D4ULL, 0x12FB4AD29E10D591ULL, 0x4EEE3815B78691BEULL, 
            0x32EDF76D1FCDD08CULL, 0x83DEAF22BF2706C7ULL, 0x0D193F8DB23F99C9ULL, 0xD6F46910DA3F2792ULL
        },
        {
            0x0A734B3E5DF393BBULL, 0x9A0F3C31CBFF1227ULL, 0x7D6DB5F9091006C8ULL, 0x62BAE4520D38288CULL, 
            0x64502A20B410C5E7ULL, 0xB82B65C15DF0806EULL, 0x80FC934C8FB29235ULL, 0x91912A3A7EF6908BULL, 
            0x497A1AE66BDE59FFULL, 0xB9D207753F6306BEULL, 0x4455A33BDDB853BCULL, 0x4194EDEFF9B6AE5DULL, 
            0xA5CD73D4A532BB11ULL, 0x3A865B4E465614AEULL, 0x9BCA7A1BA5D0678AULL, 0x0C19F9DA3CCB6C6AULL, 
            0xC504C6A2467A7EDCULL, 0x62455E8504515C73ULL, 0xCE579680545670C4ULL, 0x56F31101C8D72799ULL, 
            0xCC5F301AE289D420ULL, 0x2D79913024052DBEULL, 0xD9E2F447CF47C5C0ULL, 0x08E4AF1E9E726697ULL, 
            0xE1E62C9170218CBEULL, 0xA4EF4A99E7786359ULL, 0xC40F78E64CAB5E02ULL, 0x2BF38AF060B8DE15ULL, 
            0x8F5E1192E1467AC8ULL, 0x61B33AB9EA57EA0BULL, 0x16E306DD68B504D1ULL, 0x39020EEB09A1B6D3ULL
        },
        {
            0x7EAF02FAAB93DA80ULL, 0x3155DA4ED96B258CULL, 0x5E1FA50D5EA9ED4DULL, 0x7CD30E65A48A2195ULL, 
            0xF50A3B0BC36140EDULL, 0x3F0E14956EA158F9ULL, 0x3E779541889B5CA5ULL, 0xEA6851CCB180616EULL, 
            0x526F5C0D9B63B81FULL, 0x08F1E87EF914C986ULL, 0x6615AE353B5C7967ULL, 0xCE45D760A286300BULL, 
            0xFD9898A94819A1A3ULL, 0xD09833F6C9FE298CULL, 0xAC7455C6322BF3D9ULL, 0x9CE02D1D2A1B8A8EULL, 
            0xFA95BB8DFA391E84ULL, 0x9D2A0802D03F7441ULL, 0xD44B56ED5310F095ULL, 0x4A642E08166E19BBULL, 
            0x5E8C6B1EBD645E32ULL, 0xA6DBF9E9127F1175ULL, 0xF3E0561342B59DF5ULL, 0x5D016CA79C215D5CULL, 
            0xA84F76E1D2174795ULL, 0xFE7B74A677B7A1FCULL, 0x4C4FB1152AA56871ULL, 0x4E4FC9FD59DE7EFAULL, 
            0x1E9887112E6B0719ULL, 0x7F30543B567008C2ULL, 0x1F64D384ED55DDADULL, 0x43C0A2A9BBA455C6ULL
        },
        {
            0x702D977076F6F3C1ULL, 0x175A3CC9237A5700ULL, 0x8C92EE14C3ACCC7CULL, 0x871E14B5078E60A8ULL, 
            0xECC7E168D07F9A89ULL, 0x757845A303E53E1EULL, 0xE6AC29FEB6E32A56ULL, 0x03659DDC925FF6F9ULL, 
            0x1121F077C3859047ULL, 0x5FD8620ABAE35CE0ULL, 0x1EEFD91D998011F6ULL, 0xDE0A4ADD04399AE4ULL, 
            0xA8F232A85366C786ULL, 0xEC88CA6677A34376ULL, 0x46B15003E9D644D3ULL, 0x0D9836B261FE568CULL, 
            0x9FD168046ACE5CD9ULL, 0x5390330B91C9C5D7ULL, 0x253ABA2E3867A378ULL, 0xAD4FC7C986633E81ULL, 
            0x3014B103C9A4C54EULL, 0xA017C05BE9266E04ULL, 0xDF78BE8FE2CAC227ULL, 0x74DD17199A2BDF4EULL, 
            0x2F8033FD973161C6ULL, 0x2163370BA9710421ULL, 0x342A5269ABE9594BULL, 0x77B517813554DD54ULL, 
            0xC2605266AE4D4BCCULL, 0xDFA2E9BC54891B26ULL, 0xB097D38038A5CA08ULL, 0x3B09AA12F82FD80EULL
        },
        {
            0x39EFA2BFDDE9F044ULL, 0x94E5C05D0A4A1D17ULL, 0x3AC822BD53C656D9ULL, 0x77BC6D453F941CFCULL, 
            0x80347FCEB1C681BEULL, 0x65504E82A13C7235ULL, 0xF1D9051BCBA1CAB7ULL, 0xC5E5304FB686B2BAULL, 
            0x2D3DFBAAA82E9FECULL, 0x99CE383BDC8A21F3ULL, 0xD4C28F29E8EEB26BULL, 0xD91C5CC457DDC63DULL, 
            0x04B698349FBADE5FULL, 0x59870B35CBEED5B8ULL, 0xD3827BCA1CC8B260ULL, 0xB713FF25C58C902DULL, 
            0x9AC42C35DA2ADB36ULL, 0x0DBE73D0A576F54AULL, 0x625959F1449B228DULL, 0xEA0C2EBE1B3A809BULL, 
            0x89AED2783BE3D31BULL, 0x2956BFC9D717238CULL, 0x4FD5D7D53A8FE86FULL, 0x393FC867E1067804ULL, 
            0x0E83FC6621EACD7AULL, 0xA95929D57B9816C3ULL, 0xC5A6F656F6B155FAULL, 0x9700C71AA75C92C0ULL, 
            0xCEE64622681D5ECAULL, 0x4980E62BDD8DE5A3ULL, 0xF3A38AEDF65E2963ULL, 0xE653D7D3A4F78305ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseCConstants = {
    0x6BA912853C4BC745ULL,
    0xD47270267BA67E36ULL,
    0xE4F82335667136FAULL,
    0x6BA912853C4BC745ULL,
    0xD47270267BA67E36ULL,
    0xE4F82335667136FAULL,
    0xC6B1233788F567D6ULL,
    0xD90AE3513F922AB4ULL,
    0x94,
    0x8A,
    0xC9,
    0xB3,
    0xB9,
    0x1A,
    0x68,
    0x59
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseDSalts = {
    {
        {
            0xEE5211A64EEA8D90ULL, 0xACFBB07FEAA1989AULL, 0x0DE5B8950C295F6CULL, 0x0FAAA6935ED39B60ULL, 
            0x0B0C7A33ADEED879ULL, 0x9FE5DF1378EFE610ULL, 0xE5D36918150F4ADBULL, 0x81BBF12091F12704ULL, 
            0x41116BC42748FE73ULL, 0x391B1A33243899ADULL, 0x0C1F2F9714D1C66FULL, 0x62E093C295BC20E6ULL, 
            0xAB295B5B7BB0BBA7ULL, 0x3B235785EA10B1B8ULL, 0xF3BF564938967510ULL, 0xA0217D2FAD0AF09DULL, 
            0xB11C880D8E8DACA4ULL, 0x1033D1F3F20CA9D4ULL, 0x383E99C19F2D615BULL, 0x8EB98FD562C613DAULL, 
            0xDC7EDF0AE90D0E3AULL, 0x666BFCC7CD2EEB35ULL, 0xEC2E3946FE585732ULL, 0xA651D54190B2A86AULL, 
            0x1BEBAA05A4439E9BULL, 0xE8B82EC3F1DA22BAULL, 0x9E94F400C199F5ACULL, 0x9D59C78B3D86762EULL, 
            0xB2570A0C6E7CF470ULL, 0x44F12173D3574131ULL, 0xEA2248AC3D0A93AEULL, 0x8CE83A59120174DFULL
        },
        {
            0x253819A170FD6CA6ULL, 0x24534459E4BE7844ULL, 0xF419338A62DCE881ULL, 0x2FEF92EC8D4C827AULL, 
            0x89854B0A15AD460EULL, 0xBB077999DB815654ULL, 0x5043EB699BE69913ULL, 0xD402F0857E49F5C8ULL, 
            0x8BFF8641E3DAE89EULL, 0x468AC960CE5064B7ULL, 0x07F3D1CE63C2D23CULL, 0xFB06B0431C85806CULL, 
            0xC2E11308856B2A9FULL, 0x528FB86E50AC8851ULL, 0x7EE6498772AB38B6ULL, 0xD716045DE026796CULL, 
            0xB840756A7787F2CBULL, 0xD0C9A976C5A7EBE2ULL, 0x7015143A9EC8E290ULL, 0x28A106B0ACCEFF33ULL, 
            0x619442905286DDA9ULL, 0xB6A1188EC00666B3ULL, 0x1CDFB7F0EEA0034BULL, 0x71825589C0D2D8F2ULL, 
            0xF2962837DA17859DULL, 0xE1518E67FEDD34FEULL, 0xC45D335B8CA28DBBULL, 0x1C957812F9B28487ULL, 
            0xFA91C838F9F0EF1EULL, 0xF543E31A59545266ULL, 0x0DCC687C45F3B3F3ULL, 0x8C0472B05D7588ACULL
        },
        {
            0x821DB6658853F3DCULL, 0x6D9212225634B05BULL, 0x07F04A93B817C333ULL, 0x50EC883FD184CA85ULL, 
            0x7E6B8F98099F7C12ULL, 0x7377D846BC201972ULL, 0x3D964E346656304BULL, 0xC0CC3D3B405756CDULL, 
            0x205B81164C7F0A59ULL, 0x0CA78B072E5E0D8BULL, 0xFDD2DF4E93E94EF9ULL, 0x16D049277354E9FFULL, 
            0xBD28C140A374B488ULL, 0x7B2B45C824EBC77DULL, 0x1E0B24A5EE36969CULL, 0x31718978FBF6D2FCULL, 
            0x5D2E11A0F3F97A0FULL, 0x734627F20F1C5E5CULL, 0x3F401C45DC110D50ULL, 0xD403E7A561684CEAULL, 
            0xB0D06DB434CC0236ULL, 0x68DEFA838AD6F81BULL, 0x4E09B502D027AF9FULL, 0xFBA1F02A7BF17DB4ULL, 
            0x5F530579E2569C13ULL, 0x33DE83F2CFB0A289ULL, 0x24EB1AE704F2B3E0ULL, 0x1530EA985E529D81ULL, 
            0x4D898F8A2BA6B7EFULL, 0x7D144E45498E6E1EULL, 0x20D295E3D0B0F5FBULL, 0x31014ED25186F4D1ULL
        },
        {
            0xDA71E17B2DB51149ULL, 0x6722A04FCA1BAE70ULL, 0x3FB2CCCD41914BC7ULL, 0x0D658BD032B4F32EULL, 
            0x2382C8800FC0B039ULL, 0x2628E889CB9DD0A9ULL, 0x4C339F557D5A7AFBULL, 0x8CF6BD407FD420D9ULL, 
            0x9335E0C3C80EE16CULL, 0x169A9C1CB276D4B5ULL, 0xFEA5A4113C72426FULL, 0xF735C19F678CEF71ULL, 
            0xC1CD9C62938961EAULL, 0xEF20AB50B664516BULL, 0x8650EF82441994D5ULL, 0x16A8669AC44C4524ULL, 
            0x67B9CEFA3901B96AULL, 0xB78CFE22BC72DBDDULL, 0x7D62C106C17C8715ULL, 0x2FC02410256D0231ULL, 
            0xD964F75598A7A2EBULL, 0x742D1BFF8AA2F75FULL, 0xB34441CFED401283ULL, 0x7F2DE8421EA53962ULL, 
            0x8E8F9F8387BD79B9ULL, 0x0BADD0F2FE2F46BCULL, 0x342A086F247CB8D7ULL, 0xADDC8E5658EDDECBULL, 
            0xDF9BDB475908F71CULL, 0xC2E3733185D19277ULL, 0x7B229AC984372B8AULL, 0xCFA69B2FEDD2754CULL
        },
        {
            0x8BC02A3FBAE02C59ULL, 0x8096F0D480D210E7ULL, 0x0F2FF52063BD15F1ULL, 0xA3F1E54769179DACULL, 
            0xACD23A85469753BDULL, 0x9C8B87BF15D2E7A8ULL, 0x492AD45F9956C3B4ULL, 0x21DFAEEA6D93FBD0ULL, 
            0x2FFEB82E201E4BCBULL, 0x16932739B0B96D11ULL, 0xC6B9ADFD13CE6090ULL, 0x9FA0A806A667831AULL, 
            0xE3A5E73D8BBC258EULL, 0xCBF5DFE0588D2503ULL, 0xB82DEE3011F9CAC4ULL, 0x83283DB6D73E5189ULL, 
            0x0F7BA4B5E76708F4ULL, 0x40A8DC32F91A7819ULL, 0x2A923B67ACCFD98FULL, 0xDA776B139398A7CEULL, 
            0xA9E7FE1D526E7AB5ULL, 0x2EBB4AEA48CF3BEDULL, 0xFFAADD8C47978B74ULL, 0x6C1AFD5E689E9F03ULL, 
            0xD9588B1CDBECB7E3ULL, 0xC889AC725B2E7E1CULL, 0xBA8F0839FBBA170BULL, 0xB0BF39CA3FA62827ULL, 
            0x12C899EC4D7D649BULL, 0x68A7A7C409C2C336ULL, 0xEA088C4AFDBDCBE3ULL, 0x3584D3329439BF7FULL
        },
        {
            0xACA69522E5BD7C93ULL, 0xB670AADBA5A965ACULL, 0x08A5D83D43D13371ULL, 0xC7622B427A052F3FULL, 
            0xBF79F0829A37AA0CULL, 0x6B4948A136F6EF2EULL, 0x43D40223E78C6C71ULL, 0x58BB117C5066EBD3ULL, 
            0x2E8187766491E7A8ULL, 0xB18EFF883C44BA44ULL, 0xD73B647C88A7B341ULL, 0xCFB17FB48A73CAEDULL, 
            0xFD992180A95210F2ULL, 0x38B30CF0F8797C44ULL, 0xC4936A8EAF9E6A54ULL, 0xF275953B080F881BULL, 
            0x7FE260C8FC3A0B21ULL, 0xCD6A510C2541D7A4ULL, 0x39C00C4E745BE554ULL, 0x7EDBB0E5A1EFBCDEULL, 
            0x2FC4B59506B36104ULL, 0xB6A16430357F3E3FULL, 0x750812F96114848CULL, 0xDA8691961423AE4CULL, 
            0x7B0575793EFA8F48ULL, 0xD016B03A1E62F258ULL, 0x223ABEC406343EB2ULL, 0xE4362E9240E89646ULL, 
            0x83E13E951AB79B01ULL, 0x8B08940A538F56B1ULL, 0xAC02E3CAD57EAAC8ULL, 0xA1454150ECC0A9B4ULL
        }
    },
    {
        {
            0x3256E9C0D1F35B2CULL, 0xFDA2EA1954D26048ULL, 0x7A8E0878A19A7307ULL, 0xA5A485EB0A336F1BULL, 
            0x7B3686FE850530BFULL, 0x68756052A1BB03E1ULL, 0xCF0926D5DC4FA91CULL, 0x53C59395B5D1105AULL, 
            0x8DBA4936A033EB5CULL, 0x773326373E99E70CULL, 0x32D6224F6E78709AULL, 0xB01CA69CEFE6E281ULL, 
            0x881780234588B06AULL, 0x489E710651F366C5ULL, 0xB1F127D3DA131249ULL, 0x79E438F624FE00B6ULL, 
            0x56F3BF39B7FC6486ULL, 0x4BFEA45235E4FE0FULL, 0x880050154D253F89ULL, 0xDE9AACD06559C9AFULL, 
            0xEA12B2CA4B78ACF4ULL, 0x180EBD1A3241A926ULL, 0x7150ACFC4FBF0D7BULL, 0xB007EAA91871A565ULL, 
            0xA4EF929BB2F14576ULL, 0xC5AFFCFED7CB6421ULL, 0x61E5782FE2173F70ULL, 0x8ED42C85BE8FFED8ULL, 
            0x65C03AA5E548379FULL, 0xDE977B26E942B28FULL, 0xEDB368B48708F0FBULL, 0xBB5CA11D01637E04ULL
        },
        {
            0x3615BE9B925E6BE2ULL, 0xB0AD9CEB79389B2FULL, 0x53B50CCC1D089B90ULL, 0x230E6D543E64D8F8ULL, 
            0x89E4630448FBD5DBULL, 0x97F51E0EBA342653ULL, 0x28A51EF6565F150EULL, 0xDF35006611394B16ULL, 
            0x9E53D899754C252CULL, 0x2766AF1889B55F5AULL, 0x1CEA18DEC162742AULL, 0x52745CD7D3151FA3ULL, 
            0x1EC6E80D705B949DULL, 0x914FDAA25BDF47B3ULL, 0x49AD628F6D9C6061ULL, 0x266BD8CBB8794497ULL, 
            0xE5BE9E11F29A2BAEULL, 0x4980B1A2C9B03C81ULL, 0x1F64EE156FD6DAA6ULL, 0xB503ED4DC23250A0ULL, 
            0xE45E91783AD1F39BULL, 0xC583B530DEF4858AULL, 0x3B0FCD75EF69EE7AULL, 0xAB2D6DBEC43997A5ULL, 
            0x9628BE8914D74A30ULL, 0x074DA85DEADEEE00ULL, 0x99FD91D1269423D0ULL, 0x4A71B9090B69CC71ULL, 
            0x38294D0C60EC9F7CULL, 0x47B3D4E9887D3C7DULL, 0x5D8AB2725FDE9363ULL, 0x75719EAEACF3CE35ULL
        },
        {
            0xD8F6BBC63614171CULL, 0x7137D2B02426B80EULL, 0x32FF473DD6FEFA6BULL, 0x44C76ED440F7367EULL, 
            0x72950ACE33B136CAULL, 0xDEB68510F0F912FBULL, 0x2662F40F8B96E55EULL, 0xC364467EF568E844ULL, 
            0x3CCC989ABDDB6ED5ULL, 0x2FD471F33D33DDD8ULL, 0xFC077953B1C933CCULL, 0x21DAB21AAE7852D6ULL, 
            0x25352CC1444905E0ULL, 0x0DCA9727598E1784ULL, 0xA8CAFB1D9D41C866ULL, 0x00FEA4891D791BB2ULL, 
            0x9309A28E3F1DD665ULL, 0xE515E622E45C2853ULL, 0x319A256556CB0ADDULL, 0x30C571F51DBD7932ULL, 
            0xA22FF609C53896FBULL, 0x88A362F88F649685ULL, 0xA08AA88C904738DDULL, 0x714CAB50E6BC169AULL, 
            0x3B94AC40F45B0B78ULL, 0xFA6CFBFEBB30E68FULL, 0x1DBF4334C671BCF5ULL, 0xA6774FA38501F539ULL, 
            0x19A0ACC1E3043B50ULL, 0x43FE28AE83BC7BCDULL, 0xBEE95659B6B51832ULL, 0x53472D00254999EAULL
        },
        {
            0x5FD5DAB6E7D68816ULL, 0x31F0EED1CA5687E5ULL, 0x053467E77D8A48EDULL, 0x46631DA08B922256ULL, 
            0x742A3D6ACE99AF04ULL, 0x6398D0D7DCC65697ULL, 0x5B72B39A9700B414ULL, 0x3425C59067C830B4ULL, 
            0x1BFD9571EDAED6B2ULL, 0x22C80FBDBAC4642DULL, 0x70769C9066B31F34ULL, 0xE1609ECEEB72D907ULL, 
            0xB3D26CD399DAA705ULL, 0x01CB4ABEDD82C6D4ULL, 0xF0657579F4118422ULL, 0xB32A6905B97479A1ULL, 
            0x55CDDEEB5D8A131CULL, 0xDE6FF0A2A028B9F2ULL, 0xE6AF0301EBF50B05ULL, 0xBBF90A481478865EULL, 
            0x00D1DD8776D210CFULL, 0x1129F1413D66E817ULL, 0xD99F079C8CF66AD6ULL, 0x568858FE1FAD93F4ULL, 
            0x7F4F0B50B6CF4107ULL, 0x96904F8F9C7853E0ULL, 0x5FC0B75F2D28D84BULL, 0x76E4946C79083510ULL, 
            0x4C8FA7363DD095AEULL, 0x08A0CA1ABEB44CBCULL, 0xD421E73069D90F5CULL, 0xD9C548B9DA00114BULL
        },
        {
            0xFD5ACDAD08801390ULL, 0x7608ED0E14D7EFC0ULL, 0x2506346514245D63ULL, 0xB79F243D814D0E42ULL, 
            0x00FD714015209F36ULL, 0x21C7CAC5D39C9DF7ULL, 0x48B1824ECF97AD4DULL, 0xE34A8DB9E7DA2978ULL, 
            0xC31AD1C0214EAD07ULL, 0x00B3AD7E023A1628ULL, 0x63364A048D3DE686ULL, 0xA8E2507E22C621E4ULL, 
            0xAEB0665BEB4AFF08ULL, 0xD7766C05E130B0F4ULL, 0x131C41620D524452ULL, 0xBD9D68EF34BDEF14ULL, 
            0x0EE823FEB45B7798ULL, 0xDA7DC24DAEF92809ULL, 0x4306B7487EDAA8F3ULL, 0x8B8087E0C12D1292ULL, 
            0xD9E4AD3014B595BEULL, 0x04C779136FE4F942ULL, 0x30C848766EC404A3ULL, 0xE201D30EE7310C42ULL, 
            0x2AB56C106244DC93ULL, 0x3411B8C2218BD404ULL, 0xAA3AC3ACE42EC3E2ULL, 0x8EAD172DCC7FC837ULL, 
            0xA633CB26B834004CULL, 0x1AD8BF71F1870E27ULL, 0xE247BD690F9CB88AULL, 0xAD207014176B38FDULL
        },
        {
            0x05A93171FB8C81D9ULL, 0xBCB9246F0AA500A7ULL, 0xC36E0E0E77D0F1F5ULL, 0x3974641AAB086E6CULL, 
            0x1ABA6495E92585C4ULL, 0x3ADCC0DDAD23C20EULL, 0xBE4A95A27D108B01ULL, 0x67204D0C1F06D9BEULL, 
            0xD1F0F7C2C54890D3ULL, 0x4563FFF988C362F8ULL, 0x3EAB6E666FD88CF0ULL, 0xBDFB4C82BAE803B5ULL, 
            0xA907017F2A761CEAULL, 0xE6F67189D5FFF509ULL, 0xE53CE9C442C765BFULL, 0x52B718D2D06D3380ULL, 
            0xA060EB562B90B13EULL, 0x4991D55CE3FC9374ULL, 0xCAC96A9D7FAA9E26ULL, 0x361EE731C432D25DULL, 
            0x255FCFF88B0C6FACULL, 0x247A2DE2DF8605BCULL, 0xA67E26C01FE92392ULL, 0xD0786624F6FEF667ULL, 
            0x03A590154043DF35ULL, 0xAFB3FF3B343B9EDBULL, 0xBA9DECDD86D25A11ULL, 0x2DBA54C59D51CCFAULL, 
            0x38C387F67E3163F3ULL, 0x49E600837BCC0A70ULL, 0x74B0FAA067BD6BABULL, 0x48E59F712A51C5E3ULL
        }
    },
    {
        {
            0x3723E3194C76267EULL, 0x1D42ED4B49EBADA3ULL, 0x77E0F046858F2A22ULL, 0xC004AAACBCED10B0ULL, 
            0x5A55A5129EE3C562ULL, 0xED50BB8E0D626952ULL, 0xB559ABF28711D30FULL, 0x49565DFA29A83E9DULL, 
            0x021E7336E085F199ULL, 0x43A627EA63996A18ULL, 0xB74C4EE41D452D53ULL, 0x730B71F288B9424CULL, 
            0x00E0FCA9913568B4ULL, 0x0D9F1BEECDED9BD8ULL, 0xED53E0D6F9E2B5C4ULL, 0xD18BCA7759C3C371ULL, 
            0x90EF487BD643A687ULL, 0x52F18FBE606E9D00ULL, 0xB8676DF6B9899338ULL, 0xA77075EC7A10EB71ULL, 
            0x0FFBD9FDE764CA80ULL, 0x164D09BFA242CE6BULL, 0x2AFCABC163F55592ULL, 0xE62C455E5294C598ULL, 
            0xA101B36CD8BA7775ULL, 0x4985BC58B5B2422BULL, 0x7F90EC657B2AE3F1ULL, 0xEE1685324118602AULL, 
            0x39A7CC5CB9A128E2ULL, 0x1A76DDE5347C5C6EULL, 0xFE11F2E1C89A5E29ULL, 0x8FBBFB1FC0B12B7DULL
        },
        {
            0xE246049D18F8F86AULL, 0x6A5ED7DE01A157B3ULL, 0x49B3C3ED66476261ULL, 0xAEEC47019F011E7AULL, 
            0x4BCDBA9FBBBE4CC3ULL, 0x0DCCB82C5BD4BA70ULL, 0x301E92EFDF81147FULL, 0x8F7CB95CF8FBDD4EULL, 
            0xDE67D8F0B7ED857BULL, 0x4C659D7984166616ULL, 0x41CE8759477ABF00ULL, 0x049736B46FAF2CB3ULL, 
            0x147C25C36E199321ULL, 0x52A7DC807A60C464ULL, 0xBE26330D9B6F8290ULL, 0xA0B90D293716D47EULL, 
            0xB2DDBFDE127CD9C5ULL, 0xB70C48324F4561F7ULL, 0x81AD3ECACFA8DD78ULL, 0x4088C5D4E622A455ULL, 
            0x2E06616903299EECULL, 0x9C73F87D46CF3891ULL, 0x1B15D772DFED5C87ULL, 0xEDBA2ED4B8CF42F8ULL, 
            0x919C69C4BE85C651ULL, 0x52FE819C05DF105CULL, 0xA95C95E251B93211ULL, 0x387E665EE54B6E87ULL, 
            0x7C17B206013EC94AULL, 0x3D041A8285217375ULL, 0x80141FE8D4E32AC5ULL, 0xBD80A3BD0694CED1ULL
        },
        {
            0xB86E40ABD7105A1BULL, 0x57F7CD10D1E54845ULL, 0x6CF841AF2D565881ULL, 0x19F7578077AFCD40ULL, 
            0xEBF0B54A9EE67C93ULL, 0x40532843F022A462ULL, 0x13DBC6CEE8598963ULL, 0x903CEE616525083DULL, 
            0x2323FB234C9FA546ULL, 0x25A963402B19E72EULL, 0xC555EEC89F8C3AF5ULL, 0x08D00A5E88F0356EULL, 
            0xFF47C7AAE1561AD1ULL, 0x837EBCFE2802A1D0ULL, 0x4A8455911BE13C04ULL, 0x89133DE61210F2BCULL, 
            0xCC955C0A312F2BA9ULL, 0x02EF8F1D00DBB42BULL, 0x392424300E826C33ULL, 0xCF3696DA580B4920ULL, 
            0x8FAF5F7BE4C4FDA9ULL, 0xCA34ACF2DE61D09EULL, 0xCAF2C127AE315443ULL, 0xA542A66D5DDB32DBULL, 
            0x0CD43CDB1182E9CBULL, 0x513573A73F252A13ULL, 0x84CACE725884C25BULL, 0x5DB7BF50FE59F1AEULL, 
            0x31940844CD2F3836ULL, 0x8C92B7B6F1B17441ULL, 0x2DF183C8B93CD7C4ULL, 0xDA6D2A7EE6C61234ULL
        },
        {
            0x6B1BD8415827E4C1ULL, 0xB555A33ED319E428ULL, 0x1B865138FD0F23EFULL, 0x64A10163D6F72EC2ULL, 
            0x36372128D9FD585CULL, 0x3439D83A857152A5ULL, 0x7769B2DACC42EA41ULL, 0x7F529B0A7CC4BE4EULL, 
            0xB11D405586F7EC4EULL, 0xABA6ECB88D9ED798ULL, 0x0127B561BF61D60CULL, 0x3D78C01EF6E35078ULL, 
            0x386959B87D661DD1ULL, 0x5102B8E52309B994ULL, 0x1C420A50A30E524EULL, 0x272B8246D5DB2262ULL, 
            0x6896A402A572F1F9ULL, 0xE2F34FA40CDD6869ULL, 0xB131C716818E2C33ULL, 0x1513238FEE4E2051ULL, 
            0x856499032613FD4DULL, 0x15E59DF665BA4C59ULL, 0xCAF52B5E901A7184ULL, 0xD20036B46A4AB252ULL, 
            0x0777922DF3BB6231ULL, 0x9D3615045283C204ULL, 0x2CB15646C7D9DD46ULL, 0xDCC8A47AEA7A124DULL, 
            0x297339EACA2B6B3EULL, 0x6054BB5B8A6EAF08ULL, 0xC117AF1BFD9786B1ULL, 0x585E6BB79B564EE0ULL
        },
        {
            0xF5FC1D24774143B4ULL, 0xF84DDFED8888C053ULL, 0xEE3E7BCB5F10C8DEULL, 0xC547A22CCB0B9269ULL, 
            0x23F9A1304E73505CULL, 0xA7A6AF6B1DF79472ULL, 0x24F6B196C75E640BULL, 0xA35D78F96E568D4FULL, 
            0x1CE7E0EB13FA6114ULL, 0xBFDCCF883BCA02D9ULL, 0x74C49E6D6DD4D171ULL, 0x8DCC29E469F4397AULL, 
            0x18F181A6F4C7A38CULL, 0xEFE71CA62FDAD02FULL, 0xAECA3CDB649F7754ULL, 0xA014D5DABBBE4F54ULL, 
            0x0217F1D73801B55BULL, 0x42CC4ACD2D57AA78ULL, 0xDF6B77E68F7A73EAULL, 0x9D7EA173D8EEBD92ULL, 
            0xBAA3D7341B1CA5A4ULL, 0x94AC56C780775616ULL, 0xE9F07E42A5DBDC8EULL, 0x765ABBA271F4667CULL, 
            0xE7512566C4F5F124ULL, 0xE26707D5531680CCULL, 0xB923F80380AD0F05ULL, 0x52DB9DE92BBD0A04ULL, 
            0xC2CA47B611438405ULL, 0xD426080C6CD0B16BULL, 0xBDFE7ECC9F3AE240ULL, 0x37C5BC7BA89ACF89ULL
        },
        {
            0x96E96D662CDA112DULL, 0xE4706B141B652303ULL, 0x0D9E7C278ACEBCF7ULL, 0x984BA9494ADD55F4ULL, 
            0x93C60598849622ABULL, 0xE0CC39C97DC6860FULL, 0xF0AB2AFE1C549C2DULL, 0xBF48B79F56C0A2A1ULL, 
            0x59C143417D4E64B8ULL, 0xD2FEFE24AED68347ULL, 0x77A594D586814219ULL, 0x90837B0A4626D917ULL, 
            0x5D697ADC7B36901CULL, 0x4CC82E7AC3C89F4FULL, 0xAAA4413519248287ULL, 0x265C31066B5EA1BAULL, 
            0x0CBCAE4A4147DD4DULL, 0xA48603B2EEFB8CD8ULL, 0x73FF2CE1C87DD804ULL, 0xCD2FDAC7C54F9D14ULL, 
            0xDDEB14639A18E590ULL, 0x5B84CC1C2CD809CDULL, 0x1BEE56BDDCE8B1A3ULL, 0xBF8C7B28544C2F77ULL, 
            0x851C4EC6657D9677ULL, 0x9A96B57CB52E9EF1ULL, 0x1307010D58C67411ULL, 0xEFF1F2D375600D2FULL, 
            0xDC418BE6C7539644ULL, 0x24D92831EDB2D573ULL, 0x224EEFAC5E6A78C7ULL, 0x487E683DACEDC995ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseDConstants = {
    0x43328F9B5E93E123ULL,
    0x823F36550B58F413ULL,
    0xEC4ADBFCFA7FC515ULL,
    0x43328F9B5E93E123ULL,
    0x823F36550B58F413ULL,
    0xEC4ADBFCFA7FC515ULL,
    0x26EA7D898CD5ED31ULL,
    0x03458CB58A52669AULL,
    0xCB,
    0x61,
    0x4D,
    0xC9,
    0x96,
    0x94,
    0xB5,
    0x6B
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseESalts = {
    {
        {
            0xFD86C3BD80C135DEULL, 0x291BB5A332F3B3C4ULL, 0xA877FCD9C055678EULL, 0x588A10E43963CA75ULL, 
            0x88486F9A5A083D9FULL, 0xCF59B3A9ABD761F7ULL, 0x98619CF0AECFDA01ULL, 0x6C046931D7192F09ULL, 
            0x7445C039BF016C8AULL, 0x53555C42534F84D4ULL, 0xFEADA42865A512ECULL, 0xCC2FA4F8973E4B9FULL, 
            0xB2CB091B2D6B554DULL, 0xE16E011FC6599BACULL, 0x5072B18F14173E92ULL, 0xAAA3254EE3671075ULL, 
            0x156914BE2CFF5363ULL, 0x76D1DF13B1C16476ULL, 0xF140ED62CFE62F3DULL, 0xA612134279F2190CULL, 
            0xA76A9C87ACD6F40DULL, 0x800E3DBCC78C22C5ULL, 0xEC249A485F8B5371ULL, 0x58314C75FF5D9DCAULL, 
            0x32285943CF3E819DULL, 0xC0805BB8E85EFA03ULL, 0x1D0218BE8F6FEE9AULL, 0x9289F4220A87FA7DULL, 
            0x3414E7BA86237094ULL, 0x064354032637E3EBULL, 0xA989F922364F94AEULL, 0x9A9BD10245BF8880ULL
        },
        {
            0xF31C9411970B0696ULL, 0xF8AE991BC741A78FULL, 0x175A03036561BD46ULL, 0xD1BAFECA4CE7F4EAULL, 
            0x9D854A386873C90EULL, 0xF63FADFE65956076ULL, 0xAF036EAF37864046ULL, 0x357EB872A71F9689ULL, 
            0x2008640901A694D4ULL, 0xB9D657A35D1BDBCFULL, 0x5CCEECB0F05830B2ULL, 0x07412A976FDC3486ULL, 
            0x5E8D939766FCD0D9ULL, 0xA6987FEDA7AC21F2ULL, 0x016B6029333A35C4ULL, 0x1E60AD99E000154FULL, 
            0x93CE356E7F4B89C7ULL, 0x270C25FC1BB8A8E9ULL, 0xEAD6AC01A1AC9986ULL, 0x1418879E11CE3DE0ULL, 
            0x4226B08DA8908AA1ULL, 0xD65E5F83BD2F8D0CULL, 0x783640A9755023B1ULL, 0xD327691A41848253ULL, 
            0x91D2495A5272C760ULL, 0xE9DA13CD84A113E1ULL, 0xBEECE4327D9093DBULL, 0x459DF6B4BC756425ULL, 
            0xC9062887A6403FC6ULL, 0xB78066C2DCAC830EULL, 0xF69661C3A480AB24ULL, 0x3487A3B2C70BC6C6ULL
        },
        {
            0xF8F8B4B3BA96444EULL, 0x6155AC99E53E2328ULL, 0x9A8FBA856437D7E9ULL, 0x4013F8CB3FAC720CULL, 
            0x286FFD54769ABACEULL, 0x5BB3367A9A949382ULL, 0x0DF2488F2FA6FCECULL, 0x70EEC41C2472FC24ULL, 
            0xD6ACBC4D64E78804ULL, 0xA6EF675C91C12078ULL, 0xB86D5FEE29A4521BULL, 0xD871ABC0135DB238ULL, 
            0x5D45B29AEB3A4345ULL, 0x5A8BA04B23E50998ULL, 0xEC07FC28D6B438A7ULL, 0xDBF628D552A14DC2ULL, 
            0xF33E15DF11134923ULL, 0x8CC74A5510043AC7ULL, 0x6462C6BF8CC570CFULL, 0x1C4842ABC508A11BULL, 
            0xBBC0E4F75ED4B4C6ULL, 0x4C5433A1AB69D876ULL, 0x1321D58B90EA20B8ULL, 0x132722AC7EF8DEA1ULL, 
            0xF4D124FC474A8ACDULL, 0x5A074CC119D82AA3ULL, 0xC8EC183857339AB9ULL, 0x0C7BE6FFF6803D41ULL, 
            0x3725DE9D419CEF30ULL, 0x31AD7BDB0FDB75D1ULL, 0x9ED39DAF04E621A4ULL, 0xC32F3740B2301908ULL
        },
        {
            0xF37012722A11D99FULL, 0xD954E62817423564ULL, 0xBFF6E4FBF63121A0ULL, 0x0C1620F8B89C1B57ULL, 
            0x26C459102509D9F0ULL, 0x0E3F6D5E053FEF3CULL, 0x679236857391A09AULL, 0x6CCF4B4C15615819ULL, 
            0x86CDF52AD75F074BULL, 0xC0E0A078932C0BD5ULL, 0xEB70043D40299D03ULL, 0x93C657A0FEB48BBFULL, 
            0x1B36B059FC629265ULL, 0x0C04EF3B562DF38BULL, 0x7D7BD0AD25DCC6B3ULL, 0x75C76DDFC5A4BA54ULL, 
            0xD4ABAB7B0810FC3CULL, 0x1F348A4929664310ULL, 0x056F59AA5A1E45DBULL, 0xD4DA5F751D6BF5E5ULL, 
            0x6BA5F9BA68FC6C10ULL, 0x56CD57445C93835FULL, 0xD5E58C78432DD88CULL, 0xD997A43A51D5F765ULL, 
            0xD144F8A484810422ULL, 0xF42F85EE861E1FE3ULL, 0x7AFD74CD93E15B84ULL, 0xE337710B0CEEA106ULL, 
            0xA5D615647FA8E4FCULL, 0x4D87363DDEC0421EULL, 0x359295A3840DD413ULL, 0xB9979362E231B922ULL
        },
        {
            0x726D0442EF1980E0ULL, 0xA69C84C6C37D1A17ULL, 0xCE4F45C99A12BFF3ULL, 0x39049FE111D60B51ULL, 
            0x8D30C00C46CA96E6ULL, 0x9BACB768D750C52EULL, 0x152C7901B5EB076BULL, 0xA2BDDF94C76DE166ULL, 
            0x43D089E6B17BF73DULL, 0x7F0C4FDE72B55C35ULL, 0x08F11DB0059AB06EULL, 0x92351DFDC36EDF19ULL, 
            0x147932DB7299BFABULL, 0x337745F943ED029BULL, 0x9458D1E309DC2F1AULL, 0xB267EB8BA1D6FD77ULL, 
            0xE8EA14898B17367CULL, 0xF3EF988585CC8DEAULL, 0x84BF65EFDA4758CCULL, 0xE01DC3E1BD232A7BULL, 
            0x3A5A6578A328E118ULL, 0x4724357D184D4C5AULL, 0x0F8CBEBEF2E9301BULL, 0x9E86EA92A30A22EBULL, 
            0xEF6AB53A88AD2075ULL, 0xF103A043013A335BULL, 0x28D9E3B6CD3BE1BAULL, 0xD018306D3BE1EC5BULL, 
            0x23863880706AF405ULL, 0xD9D6C3553D701A3CULL, 0x6538CD01D8CFB60AULL, 0xD48D2A376B448FBDULL
        },
        {
            0x04F03FDF9CCD916EULL, 0x6B32317F46853D41ULL, 0xF56AFF3A250DAA18ULL, 0xCD9887B19996CBC4ULL, 
            0xB1348C43EFB89D43ULL, 0xA6D851F57DF201D0ULL, 0x137954CDA4D7E9EDULL, 0xE9F8D53D58581836ULL, 
            0x59AD5F4AAB33C24BULL, 0x97541345E147F9DAULL, 0xD6AA77F06E0E8BBBULL, 0x7F689EB158353A0FULL, 
            0x8317C334695D7D6FULL, 0x24D73FDC5E14B7E4ULL, 0xEE8CE933C5EE89F7ULL, 0x4DC01A1EB85D21EBULL, 
            0x24956D26909249DFULL, 0x27418BCBF4374D7CULL, 0xFC3631D0DB22B6E3ULL, 0xA7499F808FBFABA9ULL, 
            0x6157C6E164C64F62ULL, 0x66D6B0A93466335DULL, 0x8FF571AE1DA59118ULL, 0x90E98152E427AABAULL, 
            0xA30FA2A199924610ULL, 0xB609D596F92182EFULL, 0xFBD0BA764A7A1FC7ULL, 0xEA8B1F464E23A961ULL, 
            0x208B9C0F5A0664CCULL, 0x91BE17C6652A7292ULL, 0x094DEB12759C298BULL, 0x3714B07EDFD1B920ULL
        }
    },
    {
        {
            0x6392E560118F95E8ULL, 0x4640B77D0A2BBF09ULL, 0x92160FF0035C8173ULL, 0x82C44B14A65CFA48ULL, 
            0x9038BBE37ADC67C3ULL, 0x7A99907D5F8C7F0EULL, 0x4ED52100DFFA0469ULL, 0xF6C40DA99DE1DCEDULL, 
            0x251031A6C2079474ULL, 0xC87FFCAA582388C5ULL, 0x287EAD4E664E8938ULL, 0xE90735DD3F39D142ULL, 
            0x1354E3F32AED245EULL, 0x287412510F6D2B6AULL, 0x890D4C80C25A2E36ULL, 0x360A573463D945A1ULL, 
            0x7923FB741A76DBF3ULL, 0x22031D111D0661D9ULL, 0x3D9B1BFBDDC74958ULL, 0x01150CA8E41B5039ULL, 
            0x999955EC73BB1811ULL, 0x73C681EF1CD6621FULL, 0xBFD757BC103BC345ULL, 0x1E12C14C68CAE598ULL, 
            0x33AEE58D15151F74ULL, 0x62F6407B514F90D5ULL, 0xB8724934C1473CD9ULL, 0xBE72E69D0CF4A04BULL, 
            0x04DA6DC26F6347F9ULL, 0x0E3CC42B469892C4ULL, 0xBF6544DA39EA3C66ULL, 0x5F3E0B7670DBD418ULL
        },
        {
            0x08BB1A2AFB326114ULL, 0x3F5F41BDA44609BFULL, 0x8245A9832966CA20ULL, 0xF930B2CA42DBE2ADULL, 
            0x1007288537051934ULL, 0x94E3A55823CB00D3ULL, 0x0E5AD3CB21481196ULL, 0x83924FAAFD85ED11ULL, 
            0xF56D91064BF3CB22ULL, 0x8E81C95A198B5EECULL, 0x422E6EF101E0786CULL, 0x60BBA5AF853E3CF8ULL, 
            0xEC6627EBB2BC858DULL, 0x0ABA3DE7FC7D302BULL, 0x324E4D96918230D5ULL, 0xB88053FB84373F42ULL, 
            0x965BECEEA51B3D8DULL, 0x0A02DE304BEC2ED4ULL, 0x19D2A8574A966427ULL, 0x06D352A77B464E88ULL, 
            0x2DDB7D77D4F0C328ULL, 0x98EB2D5346F2EE8CULL, 0xA0781E94947ED710ULL, 0x8284255E2AB7A182ULL, 
            0x5696B90EA6B90CFEULL, 0x6D97A7E99D5BBB5AULL, 0xD5445E4CCAF9DADBULL, 0x46E9E64A56E30B6BULL, 
            0x9915FA06B125E9DEULL, 0xEC29FC2FF3D8EF48ULL, 0xAA9B15B0B3541408ULL, 0x8871497E452CE512ULL
        },
        {
            0x4C27A1008D727600ULL, 0xA3D61B4C8EBEAE23ULL, 0x71AC3C2FD7E1ACB1ULL, 0x6058C09D63AB5CF2ULL, 
            0xF50C73B6B5E27FDDULL, 0x3F2ACF5C41B63CE0ULL, 0x8BE916EE6B4FC978ULL, 0x18248E3E5CCCB85DULL, 
            0x3EA751DF7083CD70ULL, 0x9E1E1ED121324733ULL, 0x4F763DF10270344AULL, 0x9F87A15064AE65FCULL, 
            0xC9628AA0C354E7CBULL, 0xA34FA35F20DD2A73ULL, 0x1834C27FEF436B4DULL, 0xBF98505304B58B40ULL, 
            0xA47F8A32C500A17AULL, 0x69766AFD926316C6ULL, 0x7E35197E3192AA5FULL, 0xADEE18820C1D955CULL, 
            0x442F8D2EEA0E1820ULL, 0x4CBADA08D6FF88B8ULL, 0x03805645834B62F0ULL, 0x79DB852C95447BD5ULL, 
            0x81269997AC8FBF09ULL, 0x8FD00942D4CBE540ULL, 0x276929CCC0E0F08EULL, 0xBF1996A8B52BD741ULL, 
            0xCFFBD6A7DCDAA10DULL, 0x490FCA0B86A2E1A7ULL, 0xA3FB0C938F7C924DULL, 0xE68F4D741C55F137ULL
        },
        {
            0x585726874148DBA4ULL, 0x0DD5ECE766DD61CCULL, 0xEE80C47E97DF697EULL, 0x7D04463FAF5DDFBFULL, 
            0xB0F9244C79D48F9CULL, 0x514E6CAEB5F7F09AULL, 0xFDE91EC671208DE4ULL, 0xFD481FE8A636F385ULL, 
            0x7880968761AE14CAULL, 0x609701E7FF52B455ULL, 0x67B1D5C70D0AFC2AULL, 0x2AE9F573196C0DE5ULL, 
            0xA2B9380A40C30407ULL, 0x4543BC082ED4084AULL, 0xDD0A7574838B96E7ULL, 0xD8B8DA1E2F968191ULL, 
            0x66FEE2821B8ADB86ULL, 0x57028CAC1E1242E9ULL, 0xE1E693B2BC3A9647ULL, 0xF81CD3753D1FBD3AULL, 
            0xDBFDA654F13C5F2DULL, 0x6CFAAE362D8E8F70ULL, 0x6FBE8E7271382FF9ULL, 0x908C3CA714A6BF72ULL, 
            0x100FC2F0BF391C0EULL, 0xCC291B98362BDC92ULL, 0x981C297D20E1E4A8ULL, 0x77A216C646C8F761ULL, 
            0x28ACEC96E65AB1C6ULL, 0xB2E6048A67772EDEULL, 0x7B27E06608DB599FULL, 0x67243CE2DC879292ULL
        },
        {
            0xB9C5EB72F202FD44ULL, 0x4D50B9E65B6077FAULL, 0xCB6D98595AEBD105ULL, 0x525431E3ADBAD1F0ULL, 
            0xC51EED3526C76693ULL, 0x9822567F6AF94228ULL, 0x9E24D76828C50B9DULL, 0x48A98A00D82F0ABFULL, 
            0xD03AA0C8EDA6D545ULL, 0x43FBDD20EA487809ULL, 0xCACC11B390ECDE61ULL, 0xD72865D32F3CEC64ULL, 
            0x0D6CE11FF3AB9800ULL, 0x61FC99185AC8C106ULL, 0x04F45D409253B483ULL, 0x150A19D3477ED1A0ULL, 
            0x9EF98272914E4DAAULL, 0x8495FE0F38389519ULL, 0xAD2BCAEDA0C5E930ULL, 0xCC8DD94D0D02635BULL, 
            0xD4DD848C8A8894BAULL, 0x446AB3F93E621137ULL, 0x2A00E5210A9B9A7BULL, 0xE73D5C013F1E3EAEULL, 
            0xA93C7F24EE85EC87ULL, 0xFD557BB3173D493AULL, 0xCBA736CF989170D4ULL, 0x0BC89ECDACD6F88FULL, 
            0xAD987550F98335F5ULL, 0x8208CC74EC053B95ULL, 0x76747E78AB83C0D4ULL, 0x37F5802DE370AB3FULL
        },
        {
            0xDB412BF05E220AF5ULL, 0x64B8A8701AB4BA9FULL, 0xE1A13277DEB4132AULL, 0xF8BCFA06FC275163ULL, 
            0x7B9F50702B52C650ULL, 0x2B2D74EA67E2CFA1ULL, 0x555BC0F5764BB4EBULL, 0x78BD3028006CDDFFULL, 
            0x4023CEB54F6A460AULL, 0x0623996F66E79693ULL, 0x804C906702F13806ULL, 0xC66E848D0984BC35ULL, 
            0x85D117A0D376E84BULL, 0xE7359B2108F7BEB1ULL, 0x156598EB7D23A6EBULL, 0xDFF5AD5087186E8FULL, 
            0xA0B1BA776967EA3FULL, 0x8670A5B789723D56ULL, 0xECB0EABD02F087AFULL, 0xC94C7A4520133863ULL, 
            0xE45E5653E41E38CDULL, 0xEF38CEBF31D466B6ULL, 0xFFCB58D97FAD38C7ULL, 0xF707876A0CDAEBA8ULL, 
            0x20722A5B8BACC6CEULL, 0x452859771A8C8891ULL, 0x687DE221FD08013AULL, 0xBDC4A8222DC1C073ULL, 
            0x926ED1AD3FEF8305ULL, 0x6459070396ABC225ULL, 0x41E33978FA6EC37DULL, 0x8B189D45744E52A4ULL
        }
    },
    {
        {
            0x557B8EC6444299D6ULL, 0x64ECF88B95CA64D0ULL, 0xC745CDCE5C646ECBULL, 0xABFFD24A7F444D01ULL, 
            0x167F122EA6F97E58ULL, 0x61BD6A40880CF741ULL, 0xDD3B0FA391FBC593ULL, 0xC1BB8B9DB2EBD152ULL, 
            0xDE60999143AAFCDCULL, 0xAE1765E58A4CC525ULL, 0x966598B490548141ULL, 0xD1691A9BCC71E9B1ULL, 
            0xBEB2D36A6D15748DULL, 0xE124E58967F4369AULL, 0x23009500A4E08B00ULL, 0x43074BC6F4FFDF8EULL, 
            0xC058D35679570C40ULL, 0xFD7BCAB3021F6779ULL, 0xBDB16B58D39E69C1ULL, 0x144B4E5FBEFF5DF3ULL, 
            0x6A0550C7F5F2B4FBULL, 0x6D8717F99F2823A8ULL, 0x93CF8BB00592A67AULL, 0x03B3ECEAB3558A28ULL, 
            0x03BCF468BF0F2823ULL, 0x5D65B13B587F4EC6ULL, 0x0B910C24B7C10231ULL, 0x5DAD920189C79E15ULL, 
            0xC4AACC19C2679D13ULL, 0xC19922BB571C61CEULL, 0xC8400A3C5B359236ULL, 0xC5E9BE4BEFA51F69ULL
        },
        {
            0x05BCCEAA752D0D1BULL, 0xF0BFC3851F915465ULL, 0xEF701B1AB113B98DULL, 0x591E72C3E093461BULL, 
            0x8641F2175918DAAAULL, 0x0D672DDE239A799EULL, 0xA9D5A247E613E2E2ULL, 0xDCABED081235B2EEULL, 
            0xD663CB27802667FCULL, 0x738234C16AC2DB1CULL, 0x7DD99E6C29BD502EULL, 0xC9686196057D0B6BULL, 
            0xB21A8FFBCFD2E6E7ULL, 0x29CE313DA3C1D8BEULL, 0xB966172D0C87DFEDULL, 0x3860AC52044FEAF4ULL, 
            0xC67E425272F3C4B8ULL, 0x54624791D7F1F9EAULL, 0x6FD7EAB37A9579F2ULL, 0xB4C1E720C2C0A632ULL, 
            0xC3D469DC4D84FCFDULL, 0x79396D35175274BAULL, 0xD7B375D27436D46EULL, 0x4F56288479C3EEA0ULL, 
            0x86146BAF54DD4D80ULL, 0x441ED1347FAABB97ULL, 0x78797F231FC9C947ULL, 0xE39FC8440F2C8CD5ULL, 
            0x40309CAEFE6BD009ULL, 0x7137ED3929FD0D4EULL, 0xA94003B00D1855B6ULL, 0xA77BAE7F458BFBFFULL
        },
        {
            0xB9C0A10BABBB4EB6ULL, 0x710D09BF36350AE3ULL, 0x5806CC8DD78ECD70ULL, 0x03CEE4741FAC0BA6ULL, 
            0x5BE14E32FC170B62ULL, 0x5259A5E1EED16F48ULL, 0xCD89AFA64D4B52FFULL, 0x75F830354F11EF49ULL, 
            0xD8878F605632759BULL, 0x26466EE86D311010ULL, 0xA484C9D33762B804ULL, 0xC8A7B98312A39842ULL, 
            0xEF6B07B1C5285407ULL, 0xB185242138304D5AULL, 0x62D03490C1C9C33AULL, 0x234678CB21992253ULL, 
            0x4C1307CE97017FA5ULL, 0x28F621A904BE66D5ULL, 0x67989253ED4E2C7BULL, 0x3B816AA569D23523ULL, 
            0x24C71D65AE24B9DDULL, 0x52E30D9AEFA88607ULL, 0xA6D1FE2AB493B306ULL, 0x1BE54BCA4C7915E3ULL, 
            0xB309186F3580DED2ULL, 0xEA3200B8A45469C3ULL, 0x9B2004EB1684790CULL, 0x9FF17C915A0882AEULL, 
            0x39DDE2E1D6338748ULL, 0x22E942BFF29CC7FCULL, 0xF00E513784CCF809ULL, 0x2CB028E0C3D9D75FULL
        },
        {
            0x4CEBCFCA4A20A71EULL, 0xFE150C1827BCBE6AULL, 0x2D1741AB17EF24AEULL, 0x84AD29300B6A4BB1ULL, 
            0xE28C457B56719F97ULL, 0xBBB69B3FFBC29278ULL, 0xC9C37347AC3D1E03ULL, 0x15F3589725CBF360ULL, 
            0x664CD9CE508D2BF7ULL, 0x0D73B1640DF585EEULL, 0xA39A8BEC17A6C80AULL, 0x1CCD3D0CE41B78A1ULL, 
            0x0409A86F29B6A23FULL, 0xD37F3711E1725019ULL, 0x530CD7B924A9CD65ULL, 0x170CE5D895EC7AD6ULL, 
            0xABAF33BE70C4322FULL, 0xE0C1F719A94DC51DULL, 0xFDB85EC0B2B72438ULL, 0xF934014F90B36EA3ULL, 
            0x33DED9A731A22542ULL, 0x314C9393926628EAULL, 0x425F61F2DFF44901ULL, 0xDD1EBA76D28E1D4DULL, 
            0x199BDDE799339DC7ULL, 0x5AC312778276363DULL, 0x7249339550AEF429ULL, 0x25E3497C3CCB2185ULL, 
            0x9276DCF5C01E8799ULL, 0xFEBA042BA31BEBD9ULL, 0x65DA9695267F3E8BULL, 0xE18ED54CCF6A56DFULL
        },
        {
            0x2E98FF050EADDB98ULL, 0x63E956BB379560FDULL, 0xAB1BCB09D53F3BBFULL, 0x87BCB34CF11779A8ULL, 
            0x3E533DF0B3D9EA05ULL, 0x6FA3BF6535575D90ULL, 0xAC6D65FF3E49F569ULL, 0x3F1219622085638CULL, 
            0x1B38914B1B7D16FAULL, 0x2CE13C50C1395BF0ULL, 0x29C0FDE0A56403F8ULL, 0x3FBEE1E12BB40519ULL, 
            0x440BAFDAE3F4EC5BULL, 0xE1E770217897D739ULL, 0x5881ECB55EFFA987ULL, 0xCE2ED366DEA55C99ULL, 
            0x6131C3C9E52613CCULL, 0xECCC762A9F911FCCULL, 0x3B876D1C7A9157D5ULL, 0xA80899394A144880ULL, 
            0x20293586085F6D61ULL, 0x24E68A1ED2CB0CB5ULL, 0x48FA4F64599F4B5FULL, 0x8B41627B17EEFB1FULL, 
            0x775B66DD0C0FC851ULL, 0x0EBA99CB7CE9E8D6ULL, 0xC7B92195809156E9ULL, 0x26EB2FD05E1EFE38ULL, 
            0x94C02560CB11C20FULL, 0x33F693D14C62500AULL, 0xEF912939B5EEE09BULL, 0xF86B0D23EF16B458ULL
        },
        {
            0xA8967A639A4CE906ULL, 0xFD6CBE2B3263AAB4ULL, 0x967AA85845BE2A9FULL, 0xD7A04B057B966F73ULL, 
            0x06B906D88DCA2CEDULL, 0xB91A08C96D733AB0ULL, 0x4080A763CF95B5CDULL, 0x835C74BB0DEAD6DAULL, 
            0xDB19A3646731BCABULL, 0x5A13313DFE64BB88ULL, 0xDF8CBAAFDE975563ULL, 0x818DB6A998493202ULL, 
            0x63AB5B5893A6C399ULL, 0x06535BD87CB517CFULL, 0xEBD204BC676D787AULL, 0x3A256E8D011B63B0ULL, 
            0xF7B66AEC4C6CF97AULL, 0xE294C1340CB84218ULL, 0xB5170B62E0DE24C7ULL, 0xD6D0EC633C6E43BEULL, 
            0x5040DA89426A371CULL, 0xF0494722CE0A4939ULL, 0x321B8327AEE6F695ULL, 0x9488937DDA499F68ULL, 
            0xD4D014578E262B74ULL, 0xB7048FB75C62C9A8ULL, 0x7F27FE1F9EAAD6C9ULL, 0x3D8D2BBD7281A949ULL, 
            0x8A1CB4B3723A31B7ULL, 0x6F810BD999566049ULL, 0x999967BF42E220C5ULL, 0x4026A69E61F42B9DULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseEConstants = {
    0x8C66A12D3CE49A92ULL,
    0x811A35F7F9629864ULL,
    0x423E4E189A126F76ULL,
    0x8C66A12D3CE49A92ULL,
    0x811A35F7F9629864ULL,
    0x423E4E189A126F76ULL,
    0x803F80627A59E988ULL,
    0x0AB7B5D32A07316AULL,
    0xF9,
    0xAD,
    0xA3,
    0x14,
    0x56,
    0xFB,
    0x84,
    0x10
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseFSalts = {
    {
        {
            0x4278D96556BBB1D3ULL, 0x8F566A64E89BA612ULL, 0x50250C8ABB0701CDULL, 0xECD2C12943ABE44EULL, 
            0x17F98FFD62313922ULL, 0x0A116611C33D1ADEULL, 0x3993F299B136BCC6ULL, 0xC91702953A188353ULL, 
            0xA4F7E88481AB5EA5ULL, 0x8BAE4E239FA0A71DULL, 0xDBCC269DA85E8042ULL, 0x08BF758A04980F48ULL, 
            0x47C6CA3B1241737AULL, 0x2D158CC6A9F4E759ULL, 0xED581B49D0D8A4ABULL, 0x8F21A3285D316640ULL, 
            0xFECE9A3A7D847E5CULL, 0x1A5B1F20DA7E7893ULL, 0x4243627AC169E030ULL, 0x6280B09CC5164AB1ULL, 
            0xFF128558705FE4FBULL, 0xD8F7E1BCC79B8AD1ULL, 0xC5F401CB08627EBDULL, 0x08043F1644830158ULL, 
            0xB08F302F9368AA2CULL, 0x60BDA36363FD34B0ULL, 0x439BCC7ADF1555EEULL, 0xC7923943AB6B7EE5ULL, 
            0xD0336B83CD4F867FULL, 0x405AAF014E2325A7ULL, 0x2D2CC3BFFDB9647EULL, 0x557FAEC772C17D68ULL
        },
        {
            0xF3C3D0B108867876ULL, 0x8602D0BCD47D6577ULL, 0x3D2618AF6355E85BULL, 0x510DD3F5CCDB4119ULL, 
            0x82278601221BC534ULL, 0x580DD3E3BAA6E70EULL, 0x14EF10D8A0EFF957ULL, 0xB6DB0BFD7D07A278ULL, 
            0xB90852F029CF9532ULL, 0x696344238515132CULL, 0x1A4778E51A765286ULL, 0xEBABD24E513CFE04ULL, 
            0x8F91DC06B0AEEB06ULL, 0x9860F64CD1E4D891ULL, 0x5DDAFD2DF97479FCULL, 0x7C612B4D71FB862CULL, 
            0x6DC514158DF3C54BULL, 0xD5D2A36A9F3890A7ULL, 0xE6C36A3EA1122E52ULL, 0xC597220B8751BAB1ULL, 
            0x798302C6CD1D087BULL, 0x85B390A773185854ULL, 0x811F012C92D1F6A3ULL, 0x06B3003CF97A4EAFULL, 
            0xBB8E1511D04EF88EULL, 0x4A09D34B4BB2368AULL, 0x4582A66119E868BFULL, 0xF729475DFF2EB356ULL, 
            0xAE43222F6D6158C3ULL, 0x02089B3FD8A1F1F3ULL, 0xD61F9554D86A156DULL, 0xB3244B75131783E1ULL
        },
        {
            0xEACB949E2FEDC6B2ULL, 0xB18780DA6E2EB5A6ULL, 0x1D27293B331D3C67ULL, 0xD0AE01DB3635F024ULL, 
            0x0099D8D0813B0E67ULL, 0xC875F7A4F48CD50EULL, 0xF9DB444230570F00ULL, 0x83D2D8B67AB08698ULL, 
            0x31F22ACFBEFB9388ULL, 0xFC8FAAE5AA977962ULL, 0xE115BF865E0F571CULL, 0x6B887670D6E9187DULL, 
            0x416C82F9F7BB9AF5ULL, 0x0F04DE99E9DA8BE7ULL, 0x71F6A9A5BDD23FA8ULL, 0xFADB3F924DCE0994ULL, 
            0x318CDC3D9CF869C2ULL, 0xB836D240E0DFF40BULL, 0x19AD866885F9C62DULL, 0x02C387F77A470A3DULL, 
            0x00B69D6FA8B51122ULL, 0x24D0B164F89B1DC8ULL, 0xF55A46EBECB0B15FULL, 0x9C686082ABEFE2B5ULL, 
            0x81F96A3AF5D70C90ULL, 0x50560B805947A8B8ULL, 0xC3A9FED4D56855C8ULL, 0x33B661AAE6C92E0BULL, 
            0x9CF0A6F1F8A9F340ULL, 0x7CDB2EE9FCAD8F6FULL, 0x926D820A1E9C9955ULL, 0xF2DBCB8512158A44ULL
        },
        {
            0x5149A2F9E2B6E51FULL, 0x62CE98E13E397F98ULL, 0xD11B05A817B8D4B5ULL, 0x63AB0F0442CA8CAEULL, 
            0x547F3805D9B7CB57ULL, 0xCB8785432453515AULL, 0xC5D097713D7DE52EULL, 0x5BCFD1FB7EAF1F5CULL, 
            0x5740AF7D8DD2D0BCULL, 0x329A6E7314C94229ULL, 0x872D7C4B71B51B58ULL, 0x93B8B4B899B21C29ULL, 
            0x2A56DD7CCF07B8F1ULL, 0x5AF3D7940F592F95ULL, 0x9D2114F1BE7203E2ULL, 0x738BA9F47F73A3B0ULL, 
            0x3C3F9398CEB7CD5FULL, 0xF059758EF331046AULL, 0x85B2B09075D958E0ULL, 0x2DECA722A42589A6ULL, 
            0x1C7C2E6DCD262BB9ULL, 0x83D45C17783548E6ULL, 0x5B41081DA7A9AD4DULL, 0x1B2F30A07A6AB174ULL, 
            0xE0C3E54E468A07A1ULL, 0x94B0D891BD4266F0ULL, 0x11CCFDEAED020C6CULL, 0x2BF414BEC22F06E7ULL, 
            0xFE31E27E64BDD087ULL, 0x1DF99D6C2FF15E7CULL, 0xB07C9DAA64E6BDC9ULL, 0xE58226063355DB3DULL
        },
        {
            0x40267FC8F039BDD9ULL, 0x87AE516B118E88B0ULL, 0x49CE16605B39FA2BULL, 0x4EFC82B3D67CF42DULL, 
            0x93B86AC7B85A8861ULL, 0x8BFF1B851DA145ABULL, 0xDF1EAD94FBF9AF7EULL, 0x34AB73E4B89A0A72ULL, 
            0xF959753ED0B86C08ULL, 0x7F62A8434DA8392CULL, 0xB7248076B6B3ECA0ULL, 0xF3597B131935722FULL, 
            0x4F18BC8A449CFD30ULL, 0x8FCABAB3D8D7A5E4ULL, 0x59671626074903FAULL, 0x7251594240DEEE48ULL, 
            0x10D6127191C6EA3DULL, 0x515E28C53CF1C404ULL, 0x15C8928CD110D8DDULL, 0x3A819EC45F720F10ULL, 
            0x91830E7934CC43CEULL, 0xFABA92648D62FA5FULL, 0x5DF9CA3CE86F8BD3ULL, 0x49351E803B05D665ULL, 
            0xCB5FFB9D24121880ULL, 0x1192F886A33E241EULL, 0xD06F8E702353C7ECULL, 0xC752E7DAFFDDFAC1ULL, 
            0x55389F490A6C7E05ULL, 0xB4880B255224ED9CULL, 0xF2EBF72207A9A48FULL, 0xBACFBC3BC3AB4BBFULL
        },
        {
            0xE717FE0DF0A328FEULL, 0x92E19E458D9C187CULL, 0x5866C5DFFA832B0BULL, 0x1C0A0EA477C14DF8ULL, 
            0xBE0C88D964693DE3ULL, 0x303E427CAD410251ULL, 0xBBEFAA71612F2087ULL, 0xA21D585B3289618AULL, 
            0x3BE63F183B8E270CULL, 0x7D5D68910791CCBEULL, 0x51C43B5595F13D0EULL, 0x7AEB96C89DD98E0AULL, 
            0x36DD28E73C9DB0F6ULL, 0x619D69059877F0D5ULL, 0x639DD0DB9411C47DULL, 0x3D1D15D386E653AAULL, 
            0xA3C54C66E1CFE1BAULL, 0x3783839ECFDA5EE7ULL, 0x728DD8675CBF1827ULL, 0xC5A9FF366181B9A1ULL, 
            0xC74DA862FB4DB8F2ULL, 0xDE35FCCF558C01C6ULL, 0x35E191A37C51616BULL, 0xC70B40C239B2AA4BULL, 
            0xCDC22AC347CB6C22ULL, 0x53D921F2725995D6ULL, 0x7DE471F56C26D172ULL, 0x1DA34DD31FB21E0FULL, 
            0xCE548C5D792D36DCULL, 0x9EC613AE07951195ULL, 0xE41E0C8D5EE8C32CULL, 0x76AD6088F2D2A9E6ULL
        }
    },
    {
        {
            0x014C01CF4627FDCDULL, 0x523B6F66DDD65453ULL, 0xD96448B1B5928145ULL, 0x911B2FCEB798BBE3ULL, 
            0x7F371557755790EAULL, 0x16B690761C5B6B56ULL, 0x09F391C222176747ULL, 0x27C4D76ABC948857ULL, 
            0xABC18DF7B307E6CBULL, 0x538644048D8C4A54ULL, 0xAAC679846069AE15ULL, 0x977D6369100A1A46ULL, 
            0xDD77062B6C9CDC66ULL, 0x3850ADE146760685ULL, 0x2BDABCDBFC0B0E47ULL, 0x3C2DC7140D9B1F90ULL, 
            0xEE798C1F137F9A5DULL, 0x705415C952D77B3DULL, 0x993BE963A5D0CBB4ULL, 0x14B8376259F932B2ULL, 
            0xFAB8523C6DEC57E2ULL, 0x1E4F58CC1A1145B4ULL, 0x93129320485A2005ULL, 0xCB8FF8BD589E08F4ULL, 
            0x2FE000FBD37CE133ULL, 0x79F1CEC801E48D7AULL, 0x3C0675B4C72D2560ULL, 0xAB6F64A6C2BCD999ULL, 
            0x5E77F713386BD210ULL, 0xCEC5B040A8DDDA7AULL, 0x7B331661CB7EF663ULL, 0x6546AFD6BA542F2DULL
        },
        {
            0xF7D3A7CCA6909232ULL, 0x5C544B47D6778C5AULL, 0x7FAA8B3EDF0490AAULL, 0x69B0E8B4445FB6D3ULL, 
            0x46C9A3E964153626ULL, 0xD8B29421A769ED9BULL, 0x96B2EE5D8FEFB7EAULL, 0x4A0DFBB64B98D780ULL, 
            0xF0A7E889120AEE8CULL, 0x01FEEEB0D2DFC726ULL, 0xE76E903EA8FE4FF2ULL, 0x5FB6A0EF5598B7BCULL, 
            0x62BBCC2AAB142538ULL, 0x69CC5A577601F058ULL, 0x0B5CE384AE2C65CFULL, 0xB015295057E89AA9ULL, 
            0x27D52490E90CC537ULL, 0x48CC4B8EAE108491ULL, 0xA4556444FE5C34B8ULL, 0xAA375959C5629F54ULL, 
            0x2769F7CD8F9BC042ULL, 0x5CB91E3FF751DA19ULL, 0x7800DF95F905A419ULL, 0x71B89911E7E9D419ULL, 
            0x68C1B85BA451A20AULL, 0x7CE76A8F2496B60FULL, 0xB3B20B00AC493D91ULL, 0x5E94FA3D220E26F4ULL, 
            0x7F9AEA3E0A9043C6ULL, 0x8CB0C9F7707E3C97ULL, 0x18B121FA3B5AAEA7ULL, 0x27036AEFCAEF2067ULL
        },
        {
            0x7AC1F3D75CF76881ULL, 0xF325D915B4456447ULL, 0x7B02120448052026ULL, 0x40D5F7A49CDFEE78ULL, 
            0x1EEE9C521224FEE7ULL, 0x4411F52542FCD512ULL, 0x29293E6A9DAE2A9AULL, 0x20EB2A0DB26E3159ULL, 
            0x401980EBAB036B87ULL, 0x2B02EC2FD32F0A91ULL, 0x4268F2A14B8B4C72ULL, 0x669F797F8AE03F5CULL, 
            0xAD15EF571DD86AD1ULL, 0xEBB115543DAAB556ULL, 0x5A4D64BECEF0A712ULL, 0x520294411ACA32E2ULL, 
            0xA25F87DA16FDB4B9ULL, 0x46F25AFC539E5206ULL, 0x01552406479D4985ULL, 0x90F07A7A15950F52ULL, 
            0x6ABD3EB9D2239E7AULL, 0x4156B2B50F29C629ULL, 0xC0E664795073B39FULL, 0x983362C4B1536E70ULL, 
            0x10F96F9440D3203FULL, 0xD2CF0BC51FD26DB7ULL, 0x0647E77C7169BE39ULL, 0xF78CBA698F4B1FA0ULL, 
            0x3C697EF7DA72EADCULL, 0xF571486E5117997CULL, 0x5BA83821DFADF286ULL, 0x6FD3AE7652123897ULL
        },
        {
            0xD0179C9FE3448042ULL, 0x738DD2908DF353A3ULL, 0x967A1A8F29F37C48ULL, 0x9E395CD2E30D83E7ULL, 
            0x96E5F2B0A55CD59AULL, 0x1D6E2FC313EE02FBULL, 0xB4BCAE85FCCFBB26ULL, 0xE016CA80A8D01489ULL, 
            0x2188FE82541FD733ULL, 0xE4367B5BBB95C979ULL, 0x0A6C8130CBD60A6EULL, 0x02F15F6740B64965ULL, 
            0xDB826A0C0DB766FEULL, 0x01B24EF7F9A4F974ULL, 0xF30A1B0ACF6832DCULL, 0xDBA78DF6E495875FULL, 
            0x315814A577894C81ULL, 0x1581A79889758330ULL, 0x33F06154F81F9B51ULL, 0x3BF5A24A77D16186ULL, 
            0xCE532D07BBC345B8ULL, 0x018331EA4D491239ULL, 0x6F019E55AD370CCEULL, 0xFFF8BACEF6E38BAEULL, 
            0x820CDB48952C3B4BULL, 0x828D4FC6F65870F7ULL, 0xAAAA2505BEEA6273ULL, 0x8B45B26FD24A8E10ULL, 
            0x58F08C5DF262BB8BULL, 0x994DF6525266D152ULL, 0x7F2F9C94E4ACD706ULL, 0x5E89F8131D3D38D2ULL
        },
        {
            0x89C8918A68ED77F7ULL, 0x3B47F74BCA8BB2F9ULL, 0xBA67D912C73EC3C7ULL, 0x8347133038B85236ULL, 
            0x626848B8FAD3FFC3ULL, 0x6D235D2CDB02B002ULL, 0x53771775B3D77800ULL, 0x8DF8C89DD3EC3B7FULL, 
            0x80489400B37CEA84ULL, 0xF7687AF0076963A2ULL, 0xC9673FE6108435FAULL, 0x7056B1016661C30AULL, 
            0x46F4BD7AE0DFE083ULL, 0x1B3D3A41AA241AABULL, 0x5F1958FF82092E8DULL, 0x6BA7CEFE301A7ED4ULL, 
            0x121FC4B20374D32FULL, 0x53D8A6FC93902303ULL, 0xE9D31083298C4A78ULL, 0x9578A2785AFC955EULL, 
            0xB48814F81C04307AULL, 0x0F04DCC67C8DBA5BULL, 0x2C7B41CF27E16170ULL, 0x3ACBB7C234391EC1ULL, 
            0x37E0366CA2E3F660ULL, 0xB3DAA595B39A9557ULL, 0xBD4BCFF893C5CE62ULL, 0xF8E091BE7EE81E69ULL, 
            0xEDD51652F5E0AA8BULL, 0x0FDC265569415418ULL, 0x86534811FF4D84D8ULL, 0xCA2DDF97572D7079ULL
        },
        {
            0x8824A473BC7DA12CULL, 0x3625E7F17BD0CA0CULL, 0xA6281277EB899E25ULL, 0xED8A65072FB78780ULL, 
            0xA41436B1977A5584ULL, 0x916AFEDC45BE66FDULL, 0x50F482F1E475565AULL, 0x323BD636B057567DULL, 
            0x8A0451240D568308ULL, 0x7C4150788A250080ULL, 0xC6A1C22057AACB43ULL, 0x0C466B8091478681ULL, 
            0x5E5A8978FB101F88ULL, 0x59CB130604152616ULL, 0x7A35E10E25E58586ULL, 0xCED6625CECDF61A7ULL, 
            0xFA464F623A04C111ULL, 0x73D8A93601EE48AEULL, 0x249A0E8938474F5CULL, 0x1EF9EC5B031ADEC7ULL, 
            0x40BC9B42097D1230ULL, 0x1B90DDDCD79D73BDULL, 0x3CE148491FFBACBFULL, 0xB54AD84FCE7BB054ULL, 
            0x186D299C0DB5E6BDULL, 0x1BCA19F1BD5C3A5AULL, 0x82F2F138D8F8C721ULL, 0x43713BAD7CDDFDABULL, 
            0xC953BF9631262095ULL, 0xFFA01C46C9F77C1CULL, 0x4493B671E41FA823ULL, 0x8973039AB719F1AEULL
        }
    },
    {
        {
            0xD026F03509BCA200ULL, 0x1392FB027A57F3C4ULL, 0xE486CA64ADEDDA49ULL, 0xF48A43FFDB0C9B84ULL, 
            0x82BCAA857A7F9488ULL, 0xEAF3DE332FE161F7ULL, 0xE07C30FD16206D7EULL, 0xE26F41B2481823DBULL, 
            0xA8ED198910DBA78FULL, 0x593C1CB08E79B1C9ULL, 0xA7A85B698BEE6E13ULL, 0x64DBD2FA3A3E374EULL, 
            0x771CB8FCA5ED8776ULL, 0x02E2101FF09394F2ULL, 0x82DF74E264E68E40ULL, 0x217288B3318B22BFULL, 
            0xDEBEFCE0A663015CULL, 0x8782BCDADD090466ULL, 0xC7A5BFFCD7FBAF44ULL, 0xC27A53EA6639FEA6ULL, 
            0x22B97C1B1E76DF5AULL, 0xDCC3768D02F3671DULL, 0xFA6DC5622342A5C7ULL, 0xEA39DA801CDBC85DULL, 
            0xA086E7A7E4BCF6A4ULL, 0xBF5261627590DC9FULL, 0xCCDD5F36F0D62211ULL, 0xA9F389B30ECDCD92ULL, 
            0x17C423CF1D20DEF3ULL, 0x44FEDC922BC793D5ULL, 0x75024F26A1CAC963ULL, 0xBD7C917ACF5227A2ULL
        },
        {
            0x6AB8D8D68E044E93ULL, 0x92127D9513519D19ULL, 0x7BDA99A46E306CAEULL, 0x171086EF32EEE3B4ULL, 
            0xEDD7E3D52C23232DULL, 0xC040E80CE15EE580ULL, 0xA5A77886556C2EF4ULL, 0x221B170CC643DC72ULL, 
            0x1963BA69C9671181ULL, 0x7E2CFBB771C85CB0ULL, 0x91A8FF704BA20B24ULL, 0x233E3301B03D4EE8ULL, 
            0xEC391823F2A38123ULL, 0x0D701DFC5756A414ULL, 0x7A36F8FE7251C4C8ULL, 0x10D61BAE2247528AULL, 
            0xC34FBF9B32D30989ULL, 0x1239DF3653293470ULL, 0xEA9B74229B75ADD1ULL, 0x655ECC30A01920A7ULL, 
            0x705363741C1F63DAULL, 0x76F7579821950D7FULL, 0xAFD0DF3E47439282ULL, 0x83EA87E10FD0546AULL, 
            0xE77C62F1E0D6C125ULL, 0xBD7DE69CDF85E577ULL, 0x03132A10890DE2A7ULL, 0x763F1D842FD60BBFULL, 
            0x2B00496F4C02B63CULL, 0xFEFB50C484996DECULL, 0x7A8BDA6CCE70E237ULL, 0x8FD19ABDA9767771ULL
        },
        {
            0xDDBC7946BB1F674AULL, 0x9DD684EEBF79CC98ULL, 0x6B7FB59C51779AEAULL, 0xC73851FBF7C45343ULL, 
            0x5B3E0C1EE16D323DULL, 0x6B663740FCEFCF87ULL, 0x81E15D08EA2D10CEULL, 0x1094619E5742EDDBULL, 
            0xA49860B78AEAC4F2ULL, 0xE613E550763F4CEBULL, 0xD8267AE4A0CC7090ULL, 0x722047AA46C645F2ULL, 
            0x9B417877141B5CFEULL, 0x69288DDC596B852CULL, 0xA307927CE0510459ULL, 0xF5F9656C12DA9D95ULL, 
            0x6F29C3F3EEBD7993ULL, 0x95D0615BA64CCC29ULL, 0x23000F0C2E94FDB9ULL, 0x707CF294CA1A0F6EULL, 
            0x4534625973170D1FULL, 0x06C883F3C43B2E7DULL, 0xDA65DD81DC3392F7ULL, 0x5EF29012B1D09F1EULL, 
            0x1CEB3C3CFB2D72DCULL, 0x979AF69758E8FEC7ULL, 0xD42947144D953A75ULL, 0xEDEB0F0AB3ECCCC4ULL, 
            0x12B6F2E4784A241DULL, 0x0C8B2A4D544C23A7ULL, 0x4D241378A243B9D8ULL, 0x03A6C15C5015C0E3ULL
        },
        {
            0xEA3FA64218D61E9DULL, 0x8D5147353727E431ULL, 0x95203346BDF2CF7DULL, 0x814BE70FA27BA62EULL, 
            0x5C434A3F6C1050F9ULL, 0x8FDFD5B518E165F8ULL, 0x30EFAE16C5C3621DULL, 0x59C5C7F782BC3DEDULL, 
            0x896DA7D556B693AEULL, 0x5D224A59A746F9EBULL, 0xCCDD273C5A3F3C14ULL, 0x3A7E47A836CF39E3ULL, 
            0x3C45CB90B5ABC144ULL, 0xF8D3FE40E4DF30B1ULL, 0x3A99D3F19766C7E6ULL, 0x585D803F6AD1CA59ULL, 
            0xEAE18CE6AA25C24EULL, 0x58156E0811251881ULL, 0x4BEBAC16385C935CULL, 0x337963CC84171AF5ULL, 
            0xC046F205574D0526ULL, 0x5D86ACB03655D587ULL, 0x42D807A593650581ULL, 0x83AE32F7426FAA0EULL, 
            0x2436DDD7A74981BCULL, 0x80C01E971ACAFCABULL, 0x195CBA110223B0E5ULL, 0x8AE46800ECD5CA41ULL, 
            0xF042D871D1E69BF3ULL, 0x8A4E4AE18F8216CBULL, 0xBF2B8E1F79DF1EE7ULL, 0x2172C00988E20E33ULL
        },
        {
            0xF4E4EA170F2C2E5CULL, 0x5C3EC86FF93FC3FCULL, 0xFAE3BFE319099141ULL, 0x34FEE6FF696FDDB6ULL, 
            0x20A105CEB872FFB5ULL, 0xE55826DB66E4A9F9ULL, 0x3671D7B4FFF15B23ULL, 0xE051EE35D53994E9ULL, 
            0xB8A7570C338FE322ULL, 0xD94C727CF0A1E939ULL, 0xB7FA0339BACDE48FULL, 0x0D6ECFEF9DF0B61EULL, 
            0x5F066CBD37BECA4BULL, 0x41B761908DDB93AAULL, 0x97921F89DB63BD3AULL, 0x6ED197AF35731DF0ULL, 
            0xD2AD3ABB478101B0ULL, 0xC5BEA5B6AE37D687ULL, 0x752FA6A9B080B983ULL, 0x2D1D031263988766ULL, 
            0x2C8F27D99F55E647ULL, 0x5A89CC33E75F9E5FULL, 0x6184CA63E8D2E348ULL, 0x630ACDEECAE6F37AULL, 
            0x2B7942ECC148583AULL, 0xFDDC372E61136A31ULL, 0x79FF25C9D30323D0ULL, 0x058148DAC7C324A0ULL, 
            0xC46CA23CE31BBCA7ULL, 0x6424653C57501567ULL, 0x1F13A4BE0D2D3EDCULL, 0x66E7C2491A354E70ULL
        },
        {
            0x19D77A07D65FACAFULL, 0xA26441AD57378FCAULL, 0xEA8106317A55D134ULL, 0x870408C2E17AA837ULL, 
            0xEB739589A2AB83A7ULL, 0xF436352BAD7CCB50ULL, 0x5F848AF54E4FF3D2ULL, 0x06F94E38CCFBC753ULL, 
            0x5CDCF52DFCE092CAULL, 0x20DB1DB4175D6D46ULL, 0x68A003587962F680ULL, 0xB3F1DD025A1AC50BULL, 
            0xFCBA966591A4554DULL, 0x4CD26073EC46CBF0ULL, 0x5AE63FA2E81E0588ULL, 0x05D84A1611FC7375ULL, 
            0xE0DDCF2B4BF820F8ULL, 0x81BB84FCC9A1C27DULL, 0x6B3C6839FB39EF76ULL, 0x35B1DFC1E40BA581ULL, 
            0x90FC638A4FA57AB5ULL, 0xD542256F5F97ECA2ULL, 0x37E2660E9E9E190AULL, 0x377B04E2E564F2B2ULL, 
            0xB4DF84D744BB8959ULL, 0xB8B0677B6A119684ULL, 0x052C84EF2A21FC1CULL, 0x04678342AC589879ULL, 
            0x87D9FFD86E7DE40BULL, 0x595AA396D5F1EEEFULL, 0x0B447309A1EC6164ULL, 0x1B89B46F39053AB2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseFConstants = {
    0x6260469375155ABFULL,
    0x638C9B22589F50E4ULL,
    0xB11449EFBD6489D8ULL,
    0x6260469375155ABFULL,
    0x638C9B22589F50E4ULL,
    0xB11449EFBD6489D8ULL,
    0xDE4D7D6F6D1220F9ULL,
    0x3B235F2DF9D2CF2AULL,
    0xFB,
    0x47,
    0x90,
    0x76,
    0x74,
    0xFB,
    0xC7,
    0x78
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseGSalts = {
    {
        {
            0xC03CEBFB246157C5ULL, 0x959A9347915A490BULL, 0x8FAB260E1B3A3C8BULL, 0x78D9A59BED86F435ULL, 
            0x50BE06BA52903C00ULL, 0x94F41D8C496B33CEULL, 0xFC4B1AEDCA52C462ULL, 0xFD64C533B9E5076DULL, 
            0x2532E2F88A09194BULL, 0x5AF0D115E36A0092ULL, 0x997A2FEDFEEBC232ULL, 0x5B427EB941741AB8ULL, 
            0x65A17171A6F18C2FULL, 0xB28B01C27DA779FDULL, 0x2803EDA02485093BULL, 0x23C545044D915944ULL, 
            0x59AC9B81EC778FEAULL, 0x6C363118F967F716ULL, 0xFFBFFAC84E42F78DULL, 0xC629A6567D654087ULL, 
            0x403A696037829946ULL, 0xEC9B6FF9F13F2BC9ULL, 0x4132D8EA044A40EEULL, 0xDF0129A7ABDAE265ULL, 
            0x2ABDB555D8BBDF9EULL, 0x8934BAE07B5BCF5FULL, 0x763253EF1E0B260FULL, 0x09AD20170AAAE107ULL, 
            0xD0CFA95D917C42C9ULL, 0xDEC79ABB38CE2F64ULL, 0x3FD55CB517B48D12ULL, 0x0F3992097DBD9BDDULL
        },
        {
            0x05F7B9E75FE181A4ULL, 0xE1E7E9FBE6022C8DULL, 0xC459CC05A71D45DFULL, 0x6E852E56FFCBA238ULL, 
            0x0FE9AF6FEA3F30FCULL, 0x231C859257FF4B97ULL, 0x4290F4E871ACC51FULL, 0xF12A33D0C19519AEULL, 
            0x9ADEE0A11211FC9FULL, 0x963C7D4442259AB0ULL, 0x90CF104509C50C94ULL, 0x33E671E25E48B95FULL, 
            0x051BD33C6A92C25AULL, 0x19002C35A39676A8ULL, 0xD8DE40F99511C56FULL, 0x71DE6447D817435EULL, 
            0x231F09BD3C0BEA0EULL, 0x9E45552FCCA608F7ULL, 0xA2BADF9130D26C16ULL, 0x1FB5753ED15C1AA7ULL, 
            0xE1A6ED02CAF0F855ULL, 0x82898A996004F1FFULL, 0x439E8A31251FCEC1ULL, 0x4E1A6FA1C31CAB67ULL, 
            0x94AABFD03C4B4D4AULL, 0xF9260DE3DAB6C892ULL, 0x6534B351140936F7ULL, 0xE95437A9C15288B5ULL, 
            0x295B6E162BF387C6ULL, 0x1BD8B07DD1C18465ULL, 0x8BDD20531DDE977FULL, 0xF7458FE9E6000B59ULL
        },
        {
            0xBA0554AAED5DC12FULL, 0xB559342E71CD0E7DULL, 0x9965966354CD35DFULL, 0x00FD40FE38891EB4ULL, 
            0x5B399B44A7DB2D6DULL, 0xE8D0DED9B41F8F17ULL, 0xCBED8D79416ECF01ULL, 0xE361C04E96BFD118ULL, 
            0x00A0354AE7CC63F3ULL, 0x616EEFB86C2877ECULL, 0x91D2A418A0D945C1ULL, 0x24FFE98812D23F6CULL, 
            0xBF146576ECB7ED53ULL, 0xFE6B3B8CCB7D85EDULL, 0xF0272DD38EFB24AAULL, 0x181F44B4D5BD0667ULL, 
            0x0EA5E43B57432452ULL, 0xC810F6B4116FC2D9ULL, 0x36978801AC5F66F1ULL, 0xCEC77DF9A431471AULL, 
            0xBBD8513D413AA081ULL, 0xAC5F7380AD38940AULL, 0x7112663403147859ULL, 0xB4C62ED256FD6458ULL, 
            0x1338FA1396C11186ULL, 0xED0E32AB8D5BEE42ULL, 0x36127D5A7C277E87ULL, 0x35BA35F6496C8D0DULL, 
            0x3B345C482D1D1E99ULL, 0xCAAFD6CF92BA1476ULL, 0x60A984C47554A348ULL, 0x2290ECD1A8BABC2CULL
        },
        {
            0x80ED868FB2A75B13ULL, 0x6AA076B05C2098CBULL, 0x84D1FA4F57F1190CULL, 0x8197FCE0D64BC1CFULL, 
            0x16B40DA7528D7C28ULL, 0x8F03C1B60FD43026ULL, 0xAC3DF0CAE1861919ULL, 0x5AC2F6529CA0B55BULL, 
            0xDCAAE0DFA8E3D27FULL, 0x5565E69751FBBD31ULL, 0x2D7EE2AFDFD07D8FULL, 0x196599AA22DF6CF8ULL, 
            0x6E4559BBEFCE5D91ULL, 0xD6F75D4DFF64FA53ULL, 0xE492BE2915CA0E29ULL, 0x25DF7C871395EEA0ULL, 
            0x77B50EF8BECF99AAULL, 0x0512044E8F698007ULL, 0x567146C53C82A0E4ULL, 0x36DF6425A05738DCULL, 
            0x95EB06A4E16B5682ULL, 0x4AED22B5310CE537ULL, 0x2BED40D1379959B5ULL, 0xCA52A682542E890EULL, 
            0x1D57E3223B32DC63ULL, 0x83CB5A725EAD899FULL, 0x5B7DB97B6B5FE0E5ULL, 0x3499CE3F3FE6B5FEULL, 
            0x729C4D5197B01DB1ULL, 0xCBDFD8EAF6F34672ULL, 0x828F498D0D371204ULL, 0x0654E4A27BCFEA25ULL
        },
        {
            0x279CE40FCFAA7397ULL, 0x4DA2AA948C58B954ULL, 0xB67D773BFC48657AULL, 0xFF8F14857EB58B73ULL, 
            0x3B3E5262DF346128ULL, 0x372E6241367AD9BEULL, 0x29B1EFA54E3A5A80ULL, 0xBAA1010DA976AF47ULL, 
            0xB992DDA42D0308F6ULL, 0x4DC865C1AC9C4D83ULL, 0xA12E4ADC8AFE62F0ULL, 0x5EFBD8167FA4E6A1ULL, 
            0xB01CE5300513BE59ULL, 0xD0E7BDFBBA3B70E2ULL, 0x6BEBBBEE1B2DAFDEULL, 0x6A97B85045831080ULL, 
            0x87E14C8E0268B8ABULL, 0x137228F4171F2F7AULL, 0xBF0F2F67AC96F106ULL, 0x9BD61C5B75EF31D1ULL, 
            0x00F07FC4C32D4568ULL, 0x2EA22B7CA0D7CDE5ULL, 0xAC348BF079DC75FCULL, 0x5232CC04165F3418ULL, 
            0x1260AAE80E1A19C9ULL, 0x4B4845FB38E5EC46ULL, 0xDB39A27CD5A40954ULL, 0x582A4552EB5288E1ULL, 
            0x45800458001E7BE5ULL, 0x59BDA929F22FBB9EULL, 0x3338788AA6D37548ULL, 0x971BAF3EC942C8E2ULL
        },
        {
            0xDC6DEE594D0CD95AULL, 0xFC0627AF4EC57FF2ULL, 0x64C341D94B4EA02EULL, 0x41011C3DB0F7EFC1ULL, 
            0xD18F5B3980B31211ULL, 0x705B9FD357512302ULL, 0x5A198DAE7139DC29ULL, 0x3FE2857075AD1B20ULL, 
            0xD9AC578E83C12FE0ULL, 0xBF3D1655101DA971ULL, 0x347D4AC78F4C3319ULL, 0x4C94BFC444402DB9ULL, 
            0x3D38E8787D054570ULL, 0x05B1FD5269C81FEBULL, 0xBEC115394FC46DD2ULL, 0x92722C72C086B0AFULL, 
            0x27B7DF097FDA3C44ULL, 0xB3DE1087FFA8A738ULL, 0x17560D0E365DA0ECULL, 0x0DE74BB2654A0023ULL, 
            0x56D2936F090A080AULL, 0x76C5A13E0B9834E2ULL, 0xA93CA95EA5317732ULL, 0x4600C7706F82C3ABULL, 
            0xA1D340E296D31BBCULL, 0x99CF2EB9268D97D7ULL, 0xE0BF5D40E18094F8ULL, 0x7F21D09C9F4B4829ULL, 
            0xD71F024A0535F3EDULL, 0xE37ECC33EFED7AF7ULL, 0x4A23BE32A40FED0EULL, 0x711253D5AA4EC3CCULL
        }
    },
    {
        {
            0x1107D2365C747366ULL, 0x810EE3EDF35F909CULL, 0x18E20A153A28A416ULL, 0x18146D42ED6BBE4AULL, 
            0x0B69AF1791DD780DULL, 0x4D5F1427228D8263ULL, 0xA4C1ADA4164B6713ULL, 0xD430FD7C000BE418ULL, 
            0x71652EEB8C7ED801ULL, 0xE9A889F00362D44EULL, 0x40A700180345E7A7ULL, 0x389BB16DCF805B0BULL, 
            0x63BD2DB2008D967AULL, 0xFB8A0D87A1D70187ULL, 0x5C785AA3D2BBD7C5ULL, 0xB50754AD3DF4A45DULL, 
            0x0111DA946A24857EULL, 0xDB7FB210F28CB0E6ULL, 0x1D1ED49E7093AEC0ULL, 0x852918D8EBF7FC31ULL, 
            0xC74FD91ECAAAFEE5ULL, 0xDA441497577E5996ULL, 0x1EBEB6C1FADDA79FULL, 0xFE266FB561B12FA3ULL, 
            0x47AA127E7D1BC654ULL, 0x254ED15B5998C986ULL, 0xB62C5B33F75AB407ULL, 0xC7142055F3EDA67BULL, 
            0x25946D42CCAC8C84ULL, 0xB9B0D5764F78F22CULL, 0x1B9D99DD61B81361ULL, 0x3122B11A0F960B7CULL
        },
        {
            0x04B3391F60E8D2D0ULL, 0xDE2B4018D6FBB9C0ULL, 0xB332C63D631CFDEFULL, 0x55079A8895FD99C2ULL, 
            0x6FF4BE7395D09237ULL, 0xCD87DD0F33C119B7ULL, 0xCA4C213A69733957ULL, 0xDFF917FC4878F534ULL, 
            0x565841A84C40301EULL, 0x72A4DA3D121F0993ULL, 0x81608D6829CE3834ULL, 0xD3B06A841891FA76ULL, 
            0xD71813710674CD03ULL, 0x06E93724538CFA4CULL, 0x149B9DDC6039B769ULL, 0x48A213F571ACAD89ULL, 
            0x828E9E162C5E1764ULL, 0x6AAE8F246AC175B2ULL, 0xA39A034D8DA356E2ULL, 0x2BC42286599CB5DBULL, 
            0x83BD01E88308922CULL, 0x5BAC04903B02DA3AULL, 0x3EA77056A7A20E27ULL, 0xB353B1619E818B7BULL, 
            0x1350F12F3287FE85ULL, 0x14840B354F285566ULL, 0x774D5719F99E6FC1ULL, 0x6D7622C1332FE17AULL, 
            0xC6688DEE6A73212FULL, 0x9BB1CED23970F9E9ULL, 0x24BAC752E3A631DCULL, 0x76E0090E19EDDA36ULL
        },
        {
            0xF1A4211B6265F787ULL, 0x74BCDAA7F3824CA1ULL, 0x6D325EB5633711E2ULL, 0x11F46187490B35D7ULL, 
            0x5D7346E25B53D77CULL, 0x0E7C14526CEA30D8ULL, 0x0D36B0EC0BA06155ULL, 0x0878274A4AE452DAULL, 
            0xA60C62F78593C805ULL, 0xCC39C32E407FBD35ULL, 0xF41D76624F0B6470ULL, 0x6228E19FFC740C8FULL, 
            0x96E3F4554241144DULL, 0xAD3F2B3183896027ULL, 0xA97BDF46EF51113EULL, 0x2A3768909D543FFCULL, 
            0x4A0D30469D373644ULL, 0xC348AC1AAA6FAB21ULL, 0x8A91047431759DB9ULL, 0x882D8E04093CED12ULL, 
            0x5578C81876755DBFULL, 0x16D9926FC2FB2061ULL, 0x0E35D67C9E9CF0DAULL, 0xDBBEB0CB0FAB0329ULL, 
            0xA7AB91741C7D7752ULL, 0xA8A203C87E77DB2EULL, 0x8CC7BCC7D9B6C826ULL, 0x89DA05CE0598593BULL, 
            0xC6886C936F8E3B5CULL, 0xFB440995E0A19520ULL, 0xEA4AE051E898803EULL, 0x309B9B15D44D5377ULL
        },
        {
            0x3C59D2A3C1C0B8B9ULL, 0xFDF3F886B5CB0A4DULL, 0x6179C635587A317EULL, 0x4A57A8CC5957B4ECULL, 
            0xBE2A5D56F4DAFCC6ULL, 0x75FAB40129302E1EULL, 0x3AC26326839C5DA3ULL, 0x7F3420B53590F27AULL, 
            0x02F3C5B1D34E97B6ULL, 0x6077A0D1CFB666EDULL, 0xB0F3855195190C27ULL, 0xBD7BEA30D5B83EF5ULL, 
            0x83DA001F358B1554ULL, 0xA8F2886E19BE5D68ULL, 0x8F85F77E3A739384ULL, 0x00556925E3B1C1F9ULL, 
            0x6009319E8E5F85B4ULL, 0xD4EBBEF1733851DBULL, 0x20003C60D5794D71ULL, 0xCAB97A997991F193ULL, 
            0xBEB4386AA454F595ULL, 0xE47C1B8FC5AA55E5ULL, 0xD0DB86FDB67AE259ULL, 0x3AC877B9F2822FD4ULL, 
            0x470911BEFEB3C2AFULL, 0x06CD7A2FA0D14C40ULL, 0xA3087E6F0D5C29E9ULL, 0xBB7FF437CC1F3383ULL, 
            0xB4FCD70B4C53619BULL, 0x6C14DF8070C66DF2ULL, 0x224EB739BCF706B1ULL, 0x5C802AD6AA62E453ULL
        },
        {
            0x7424C18BBBB9B16DULL, 0x8D9153CA8143AAF9ULL, 0x0C496E924CD1A303ULL, 0x01C1A2413F0173D8ULL, 
            0x99227CFC9B1CEADBULL, 0x88D323C8AFA13C6CULL, 0xDEA4B99E4574A270ULL, 0x589821D5A8DC655BULL, 
            0x8CBE6D4ABB58F297ULL, 0x21E691F5D9304323ULL, 0x2204223808DA9EA4ULL, 0xD5F1A98279627871ULL, 
            0x312EE2294BF41549ULL, 0x3A62D529FC8EE7A8ULL, 0x6BA09FD850EF1D19ULL, 0xDF44CF0509C3CE28ULL, 
            0xB56BD12B43386EC1ULL, 0x2122E485E5D9B979ULL, 0xF0BAD79F5349C3EBULL, 0xE721D3C48B8E844CULL, 
            0x742ED193C8DB207AULL, 0x935028AC3D2E3AF2ULL, 0x6043FAD048ED2217ULL, 0xD4F7440D8105807CULL, 
            0xC10BCCEDF1CBF6A0ULL, 0xCE05DFE07322E641ULL, 0x95150E685E663539ULL, 0x069EF4E5034F473BULL, 
            0xCF1AA2C9E93E2555ULL, 0x44940923D1FA3AECULL, 0xFE7DFA1789949C0CULL, 0x6D44EA05279157B4ULL
        },
        {
            0x6A38A9A54E27A241ULL, 0x3CDA6E17C6F9E06CULL, 0xFE01862D64E1399CULL, 0x013917E55AA4D759ULL, 
            0x9571BBA8E1A872D4ULL, 0x39960E8B89DD5178ULL, 0x6849739869872FDBULL, 0xB4F98E7D6E9DF13BULL, 
            0x763A588EA84D4DC0ULL, 0xA25556091E644761ULL, 0x15284E003744342AULL, 0xF486EC607E07E498ULL, 
            0xED86707CC76A486CULL, 0x95B59F3170F50C99ULL, 0x3AB06E7B7213A03FULL, 0x1021D0E6E7ACAFF2ULL, 
            0xE8DF66F50964273BULL, 0x5E3AA8EC89C022F3ULL, 0x1D4A7C6E55F33269ULL, 0x7B592BA51E7688C7ULL, 
            0xC0BE8CD76C4346D6ULL, 0x971F160CC1E937CCULL, 0x152EAF2144EA9406ULL, 0x7146C9A01B0615B5ULL, 
            0x1457D97ADB1003CDULL, 0xAAE6DCAF4935C79EULL, 0x1382B56CCE678F93ULL, 0xCF601BCC091A8E53ULL, 
            0x3190C45CA5FA7062ULL, 0x9AE6D684134910EAULL, 0x3B727E0F91B6C2AAULL, 0x3521B2C852C8506EULL
        }
    },
    {
        {
            0x018A23CADAB51FD9ULL, 0xABA814AF9443A5F4ULL, 0x1325AB99F6E37B7EULL, 0x9505A32A7EB527AAULL, 
            0xE27708369C537D35ULL, 0x82F650E4E878164AULL, 0xED7467E0001AA2C8ULL, 0x9C620675C5F2D261ULL, 
            0xBDC93194E65CB8A9ULL, 0xE0D1AC1932A04B06ULL, 0xB7F32D496615F74FULL, 0x47F5A75C69FFA2BAULL, 
            0xD4438C439B5907BBULL, 0xFE389BC625E23193ULL, 0xE66D124D5EE403FFULL, 0xB3199959E712CC3BULL, 
            0x29B225476053D504ULL, 0x55D27E8EEC93657AULL, 0xCBCD3E8CD1AA0024ULL, 0xA75AA038E69D1581ULL, 
            0x875234F8A8AB87FCULL, 0x07BA34D09FBF954EULL, 0xB0BFD029D4EFF25FULL, 0xE37728B614C052FCULL, 
            0xC20505D4AB55B289ULL, 0x0D753D3B3B5DCD5BULL, 0x8FBB59C735B9FFB9ULL, 0x4F057DBF666B964BULL, 
            0x064A7B0C547A5E4FULL, 0x6B712021689C18A5ULL, 0x0C3758539D5D6F08ULL, 0x5DF32BA53BCF020DULL
        },
        {
            0xAC35CC390A835C8FULL, 0x39B8DFB3CD12197CULL, 0xFABBA2BBAEC318B9ULL, 0x3F1097CB833F8894ULL, 
            0xE037D7F93A9036E0ULL, 0xDB172E3127E85D80ULL, 0xF5552BF01FCAE1CDULL, 0x41219C1AE5B5DB7CULL, 
            0x3D4C8C5D3EE751F5ULL, 0xC895C9FE3294FE69ULL, 0xA2841604CFF6466DULL, 0xF54137B472BBDFE8ULL, 
            0x2C3E49124BEB757CULL, 0xB1FDDD18003135A8ULL, 0xD6E97616BE166AF0ULL, 0x09056BE5AC9EC20EULL, 
            0x5D6F6AED70E91D77ULL, 0xF839E11172EDA43BULL, 0xBD3A7F175687B9C7ULL, 0xBE0F248506FDC945ULL, 
            0x0F9BBF44B576B3C5ULL, 0x2C20692CD956370CULL, 0x66F40BADCC079CA8ULL, 0xBA48AFDC7A15C007ULL, 
            0x8E32A40D77FB714AULL, 0x1128F6B2D7FA7F2CULL, 0xBAB1E6DC8058FE96ULL, 0xDC127ECF010E4D57ULL, 
            0x0F54D1CFD152CFA3ULL, 0xA5D8A56C3B336389ULL, 0x1B1D50312462FAC8ULL, 0xCF925608DAFF13C1ULL
        },
        {
            0xCCA2287E8BA244CCULL, 0x4B6C12E334E186BDULL, 0x9D5C9598DE1E9897ULL, 0xA0CB23D646E74791ULL, 
            0xCDFC3637FD1A1A8DULL, 0xD491BFB298782ADDULL, 0xC9B20C577C7B498DULL, 0x32A4698C9A0E0E23ULL, 
            0x0BE4F47921933EFEULL, 0x56B667E7CED9EE1EULL, 0xC040B152347C4F16ULL, 0x9D5AD88133E534FBULL, 
            0xB439C281691777DFULL, 0x52750BFAB4832AFBULL, 0x5B9B4E5F25B72F71ULL, 0x4A3F19FDCE148A6AULL, 
            0xF2F2C0BFEC0E8A09ULL, 0x13167660D9B63BBDULL, 0x6DEC63F5411F9E5CULL, 0x72CE33138A8F1677ULL, 
            0x27665EDFC472E89AULL, 0xC0EA98ED4C11051FULL, 0xD92BC97810B8A5BEULL, 0x4378E0446DDA1469ULL, 
            0xC3F85B3D2E65ED38ULL, 0xE6FCD1974BB901BCULL, 0x83312554F7AD8D83ULL, 0x1D7E8CBD1ECC697BULL, 
            0x0762C8468BBEC919ULL, 0xC022F68B0F0BF507ULL, 0xE3AE6A9E86FE0599ULL, 0x2958BA7D979B2886ULL
        },
        {
            0xA904D2E78DBAAFACULL, 0x4CD3650DFC42C7FAULL, 0x928AA3FF1E381448ULL, 0xB009677A7D677C8CULL, 
            0x1A7D6EDDAF37273EULL, 0x637B2153668E313AULL, 0x34337B1217B8E12DULL, 0xB1A87D01B5AAE0F2ULL, 
            0x3D4D826346D5AD40ULL, 0x45E80D08E68520C3ULL, 0xEEDC2A271FE9794EULL, 0x25B091CE457463EDULL, 
            0xD1CD2A3CBE2A3206ULL, 0x80304D643BE1D22EULL, 0x80040552CEFC7554ULL, 0x958591D92F7C4F41ULL, 
            0x89758B50C6A95B9AULL, 0xC670B1D94176B6E0ULL, 0x3E0C3095AAEFD3DBULL, 0x0305AD9712A6F609ULL, 
            0x3DC24F1886877CD2ULL, 0xA102D22D0B2BD05CULL, 0x5699628FB6F46042ULL, 0xF908546C7C9F037BULL, 
            0x7DB08A61BA470CA0ULL, 0x7C63364404D40339ULL, 0x267F39B2185D2A43ULL, 0x72191B853F138AF5ULL, 
            0x426463FD4FC23EAAULL, 0x8CBC14074E2408ABULL, 0x7ED225B52C069CDDULL, 0x481C727CC94BF95DULL
        },
        {
            0xA11B7EF3512959B8ULL, 0xF72CECF1A7B9FA90ULL, 0x73AC1FC4D9BB22EDULL, 0x98662EA4C0331802ULL, 
            0xAD350837E09EBA7EULL, 0x2E9456588B715A11ULL, 0x94C28AE357E9D9D8ULL, 0x3DBF7AF835F0B19BULL, 
            0x651C4B73515684F0ULL, 0x1A87530346C54573ULL, 0x9DD72730DC562DB1ULL, 0x0DB3F9833759B490ULL, 
            0x081B9ED50754A522ULL, 0x896002B21FFBAD10ULL, 0xAE15055123B584B7ULL, 0x213315CC4F9BD174ULL, 
            0x975586D555BD4A5BULL, 0x6B12876CA6650620ULL, 0x49E248559719CCC1ULL, 0x9FEDCEEB1BAD06A7ULL, 
            0xE2EA874D8C1208EDULL, 0x5F113AB9B683F8FAULL, 0xA149813AEE605A2EULL, 0x875BD7FC5309A166ULL, 
            0x37AEA2C2CCA0DF11ULL, 0xBBB9B081DE2E0BCBULL, 0x8CB5A63EED932A14ULL, 0x141B85892E45031CULL, 
            0x537CEAC67C4D0D22ULL, 0x0359D3F0A63A2298ULL, 0x418EED3A50917A31ULL, 0x3DF5F62F25B16A34ULL
        },
        {
            0x47B31B267B4549BCULL, 0x71576D8B0EAD45ABULL, 0x1B9B89B5CA0B9F23ULL, 0x59A47F6229A37888ULL, 
            0xEB3C985B13912A97ULL, 0x429AAC5C2CBE936AULL, 0xDEBDA8B727ABA562ULL, 0xF80903E23D4F616DULL, 
            0xB8C3C8973D7D4496ULL, 0x7218F9BB4534E213ULL, 0xC031168E7F24A3CFULL, 0xC7D25F9996B9C032ULL, 
            0x3779072936AB424DULL, 0x9675181325F7782CULL, 0x708016E602F9327DULL, 0x9815246A1A9A4084ULL, 
            0x0986BEBE4EB861C9ULL, 0xAC0843B3F37F4645ULL, 0xE341AA175944D76DULL, 0x6B31BF889901B2D1ULL, 
            0x7E929988210ACFB4ULL, 0x69EB7AE237FC7C01ULL, 0xB38D724AEB5CE8B0ULL, 0x3A99D87D55EDE39EULL, 
            0x39DFAF82CF25CE3EULL, 0xAAB1443AA5ECF289ULL, 0x15116B6AE99E97DAULL, 0x663D87F32D900D98ULL, 
            0x3EC410BCB369CBE9ULL, 0x5CBB234ADC6897ECULL, 0x3F6C2395AFC61EB8ULL, 0x2005DC9EC6F06105ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseGConstants = {
    0xAF7D82923BAFF3FDULL,
    0x822A7C143DD2060BULL,
    0xCDA4E71F1B7C9BB5ULL,
    0xAF7D82923BAFF3FDULL,
    0x822A7C143DD2060BULL,
    0xCDA4E71F1B7C9BB5ULL,
    0x5B9BEF7709B23C33ULL,
    0x965F6117C0566E0CULL,
    0x9D,
    0xC1,
    0xE9,
    0xCE,
    0x4B,
    0xE8,
    0xAA,
    0xE5
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseHSalts = {
    {
        {
            0x6B36CE6990AAD53AULL, 0x5CFF956DA8CDC6C6ULL, 0x82A55DC8A9D90431ULL, 0x87F4C8510FE839ADULL, 
            0x6A57A37C048DC393ULL, 0x6BCCA454556234ECULL, 0xE84B63C0B7A876D3ULL, 0x6CC14DDF55D47459ULL, 
            0xE29017D51797C1E6ULL, 0xC843540B25E22F79ULL, 0x666BD91871B3F4A2ULL, 0x678F8708A6E0BE00ULL, 
            0x73F8FB244010AAC8ULL, 0x079866E8D6C30D67ULL, 0x1CBFE0A0E2BC1C1DULL, 0x20D44EFD89E5D527ULL, 
            0x42057E942355D610ULL, 0x41C2F2D314BF1BCFULL, 0x11BF5C7F9465A3C6ULL, 0xFF8421CFED729923ULL, 
            0x657D266D7452EA24ULL, 0xC70E9A076A44BF16ULL, 0x38882B8044DC74D8ULL, 0xCF6902CD1F55E4E9ULL, 
            0x54DC4315F838F3B9ULL, 0xB117DDE25D4FE129ULL, 0xDCE7C6F41FDFE2A8ULL, 0x6FA7CB131740E7B5ULL, 
            0xC3D0040E500A9110ULL, 0x50163D323F459BFDULL, 0x111C9F7F7BDF2AC7ULL, 0xDFFEF12FDD2853DCULL
        },
        {
            0xD6E37611E6E52433ULL, 0x70A1330B55FE5139ULL, 0x1B5ED062AA283ADEULL, 0x2FECDBB1DB402961ULL, 
            0x622ED143C05DC478ULL, 0x9148FD8A7FF2D5A6ULL, 0xD8CABB920F1D1EA6ULL, 0x31EE7B88FA831D48ULL, 
            0xFC674F5CB6B46105ULL, 0xDC5B3EA2EC1D581CULL, 0x1FD205F4BE3360A6ULL, 0x09E005485A1B0429ULL, 
            0xB0321FEB01C50FC3ULL, 0x4627CE37BA6F3D5DULL, 0x891B2B8763662545ULL, 0xB8FBD9E1EA88008AULL, 
            0xED328EDD94E52301ULL, 0x9CCC98357FBA462BULL, 0x3EC33E6054BAC12AULL, 0x8B2DDE4F4C45CC61ULL, 
            0x139C87C92F230EDCULL, 0x62CA73D1302DD026ULL, 0xA9816F8F8A5EC107ULL, 0x4ED2E1516764E05BULL, 
            0x1999F12C01C6DA1EULL, 0x2FF7B08022456962ULL, 0x0CC94378CD2B77BBULL, 0xA80EED87F8F8952FULL, 
            0xA398F87B1FD2D9EDULL, 0x556573E368A77849ULL, 0xCABF9909737542F7ULL, 0xE5E717C758311C4EULL
        },
        {
            0x3B6B79DE7F33185DULL, 0x922E667167B56359ULL, 0x0D0B42351E83355DULL, 0xF62968914040FAF4ULL, 
            0xEBBF6891B61913A6ULL, 0xA73530D1D6D56E52ULL, 0xF05BB6B4A83E1C45ULL, 0xAD702FD3F4E5001FULL, 
            0xFEEF955B288BE2BCULL, 0xAF1EA879C5CC4F44ULL, 0x9162B2999A0BC2FCULL, 0xC524BD02FBEA9EF0ULL, 
            0x1F2111BFBBE0ABA4ULL, 0x5632CF9CA5933E6FULL, 0x0BDB402153C258C5ULL, 0xAD31A634FC7D8AE0ULL, 
            0x894E1373D6ADEDC0ULL, 0x3508F7DB771065A5ULL, 0x523DB0C18D52F370ULL, 0x785D498E9577DF24ULL, 
            0x102F452521DA3C49ULL, 0xFB3D7AC7BBFF52A4ULL, 0x8ED09C5CE480CBA4ULL, 0x830A68CF6D1C857AULL, 
            0xFA2BF18779290736ULL, 0x3DFE17B9EC9556F7ULL, 0x8FEF28FB0B4666CEULL, 0x492C33AFB52BB946ULL, 
            0xCFBFD8248B1A3745ULL, 0xEDBF273F4A581894ULL, 0x243D42B953A5172FULL, 0x406ADD7F2D5E6206ULL
        },
        {
            0xECA52D1AADD2AA5DULL, 0x5022F9FD0D43009FULL, 0x77B964CF3E9AEF59ULL, 0x33AF6E365F0268B9ULL, 
            0xD58070ACF7C5DA8AULL, 0xD802C66835C9A6F8ULL, 0x9FC0D2AF79BC5E79ULL, 0x30A3F77A065C0372ULL, 
            0xD87028C0F6FFEB4CULL, 0xE8388C36734AA4CBULL, 0x02DC6D438A40A8B7ULL, 0x152344718016D7BEULL, 
            0x2B5A22566DC352ECULL, 0x270DE76ACD1BF29AULL, 0x1FB3B1F02C4C8140ULL, 0x27620C01BE395F07ULL, 
            0x451DFD101C2DE4A3ULL, 0x3FD62677D625E8ADULL, 0x192378DB47800DD7ULL, 0x4D893CCB9ABDF4F5ULL, 
            0x89711D1B82F39E16ULL, 0xCA9C5F540663770EULL, 0xCD8495F108464FBCULL, 0x40435C92FEE114B5ULL, 
            0xA2150214017C9ACBULL, 0x14BDB9FFAFF6B299ULL, 0x36FAB264ED1BC388ULL, 0xCEF9D5F438FD880BULL, 
            0xCDA76383446C082FULL, 0x405D35BF31978F08ULL, 0xB390CEC4ADC30228ULL, 0xCE4B25A4286549F4ULL
        },
        {
            0x6D3E851C6BD76363ULL, 0xACEF340E88A6B992ULL, 0x8A4FE165E2DCE42FULL, 0xB40B2A1BCF490F53ULL, 
            0x471B6BCE5A447844ULL, 0xD9D3AE34381B28BCULL, 0x5593ABB15A4E4B8CULL, 0xCF67A72F506A036CULL, 
            0x71ABDE001A08FA3CULL, 0x90F6FD71C73C486CULL, 0x367DD788C707B02DULL, 0x9E89CC77EE023950ULL, 
            0x8BC272736C2FD987ULL, 0x9B3BB0DAD2BA1964ULL, 0xA9FF7724D2C16FC6ULL, 0xB354FB7CBCA97394ULL, 
            0x17E73D433B54F7DAULL, 0x81D19116361C0B35ULL, 0x9AFD77C7D4B4F24AULL, 0xD7A69EB2568FEF74ULL, 
            0xC454BBAEC6E08019ULL, 0x6833674CC5F78117ULL, 0x79E7DB9D2025030CULL, 0xC324ACDB529E4072ULL, 
            0x3120010950C5CAB0ULL, 0x8FFB286D7053EBCAULL, 0xBDA7C4F6D3EA0B87ULL, 0x77E6DF6ACF7A9944ULL, 
            0x73D4BB5C3FCE9009ULL, 0xB5ED4040F137FBA3ULL, 0xF307E241BEBEBC83ULL, 0x6A6E4228581ACB87ULL
        },
        {
            0x9AA943174B4DFAECULL, 0xF53C6448180935DAULL, 0xCDB93FC0F8C5B3C7ULL, 0xAC3C4FFAC26B3CD0ULL, 
            0x40ECDFF829C2D567ULL, 0xD75F18CBB9E7A1D6ULL, 0x5B31382F6A186A0DULL, 0x4E0596887E49FDC5ULL, 
            0x8BE9B353650EEA56ULL, 0x17EE37B326B47C8BULL, 0xFAE343D58F836B04ULL, 0x25B22251919DC0B8ULL, 
            0x91F9A4E2BCFE691DULL, 0xC548AB55BF0E2366ULL, 0x125AEC839D76189BULL, 0x295029F43E3E19E4ULL, 
            0xC79692AE5B58774DULL, 0x6E45AAF2E1A12DBEULL, 0x032B36CB365DF4C8ULL, 0x401D4343AC6384F5ULL, 
            0x00C4118E08B06C97ULL, 0xA943FBC220197C1DULL, 0x2465105EC2B25B23ULL, 0x2D340ED4B10FDCDBULL, 
            0x36B3770640609A91ULL, 0x94D0EF54A2832BA3ULL, 0xE291778431599F9DULL, 0x0868A00C38A3294BULL, 
            0x25B8412408AB9F7DULL, 0x16AD0F40E413915AULL, 0x644508F68E3F19B8ULL, 0xDE5A0DD70102F9CFULL
        }
    },
    {
        {
            0x88E27D5AC7A66B4FULL, 0x869ECFA1F7D622DEULL, 0x94EAC117B14EAD58ULL, 0x0FB27BD471A7EC98ULL, 
            0xEDBCE4C769CDE6F6ULL, 0x820E74BF89AB3734ULL, 0xF1FC40F07F15A127ULL, 0x1D6A706A6946EEB7ULL, 
            0x60D17AE3E4BC565DULL, 0x6B60053067C79D58ULL, 0x89211339EA50FBB1ULL, 0x99A1ADB866A45BA8ULL, 
            0x313BCDE363DECB0EULL, 0x0B749DD67EC6FB5FULL, 0x4F47CFA3CCEBA68DULL, 0x16C34CB05A46B6F7ULL, 
            0xACF3ADC15CA406B8ULL, 0x88C0A60A73D39C90ULL, 0xB1116A6312DCD180ULL, 0x9A1C35D372F1CBBBULL, 
            0x81AF2CEDDFFFE133ULL, 0x3A2C3CDD01096FD4ULL, 0x00F4616D1BDE6275ULL, 0x3B944704EAE2D5DAULL, 
            0x497850D47D17F6DBULL, 0xE50B1A2E1B040A64ULL, 0x71CE1592EA1C2171ULL, 0xA8294EE6C46E46DBULL, 
            0x83F2DCF952D04563ULL, 0x903522810BBFFA28ULL, 0xCFCF1350DFB65041ULL, 0x5F48724F6EE7BE45ULL
        },
        {
            0x4E5162E1F7033F50ULL, 0xF5D1058F4A7D09B2ULL, 0xDE669D3B48F4A042ULL, 0xF39E98F5DC4DBEA6ULL, 
            0x103A2A928FFDD080ULL, 0x55DD28736BCDF0D6ULL, 0xEE866B2822DBE3AAULL, 0x2D8E95C411E70E2FULL, 
            0x825740A0EE34E685ULL, 0x6BE0C09585A1DF06ULL, 0xB8BC2399089A5205ULL, 0x8E0EDB6B31D2FA40ULL, 
            0xAA023F5576F26ABEULL, 0xEE8DA2417341C502ULL, 0xCD0AA246D9F64603ULL, 0x0C6D5B277A05EB36ULL, 
            0x959116A583F731BFULL, 0x94D929E8DD9AC9BFULL, 0x85E61E44674A05E5ULL, 0xF49984A7EFD55134ULL, 
            0xD786AA94BF28D137ULL, 0x0377F215CF71FD1CULL, 0x70EA04CFD53A877CULL, 0x4C0BE722915EFEABULL, 
            0x5C8FC1E8ABF84636ULL, 0x82F28C9105CB14E6ULL, 0xA3221E79275FE900ULL, 0x08F7BA93346149DDULL, 
            0xED3255F44AD09A3CULL, 0xF94F12A0EF3CF811ULL, 0x836773B2067E8F61ULL, 0x22D8B14B3328194BULL
        },
        {
            0x7AED066D303E5C92ULL, 0x1A03FFA21AB4E3F8ULL, 0xD09006DA7866FD5BULL, 0x42C59E617C406F73ULL, 
            0xBA2346A7FD3151CBULL, 0x86937AD242CE2862ULL, 0x9F21CABACC459F2CULL, 0x13EDCD092B266797ULL, 
            0xBC9699D8665B57EAULL, 0x0868DA681391CB55ULL, 0x3222EB350A333650ULL, 0x9B52BCBABF413D7AULL, 
            0xC5AC288104BE4B6FULL, 0x69317E6E8FFAAEA6ULL, 0x63CD7AFA20337D36ULL, 0xEC9B2A46CBB2DFCCULL, 
            0xF7DE48FA9C9D0C9BULL, 0xF95CAAD17170EB90ULL, 0x9A196974B365FB12ULL, 0x7F550CA5BFFCF0C3ULL, 
            0xE692ED452AA344C8ULL, 0xD6AA8CD43C1EB805ULL, 0xBFA60D12429A18A6ULL, 0x1FC122FB2A3E0B10ULL, 
            0xA4ED3D00152B24ACULL, 0xAACEF00AF5C9EF38ULL, 0xDA6744D3F60658B9ULL, 0x3005E80FBCD0B486ULL, 
            0x2FA9C178B9B6BC00ULL, 0x489C0AFBF13800E0ULL, 0x84FB691AF9C5B04AULL, 0x90AAD51AEB5BF8ABULL
        },
        {
            0xBE4C2C8C677503B2ULL, 0xB2245F8C7D76FB6EULL, 0xD053A9880EF2787EULL, 0x7F7A2C85AE999031ULL, 
            0x2BC631AE16225F31ULL, 0xB9272BA4E66B9254ULL, 0x4ECA8C344DD5E4B0ULL, 0x10479E04759C8894ULL, 
            0x3BFDC1B12EFFAE80ULL, 0x71577254983AD44EULL, 0x3521B53D2B136AA9ULL, 0x7C3910D26D6408FDULL, 
            0xAE55FF0A34EEFD58ULL, 0x0DEC71FF899F3E71ULL, 0x8D58ADDEB260ADCBULL, 0xE3DCFDAD97AC8ED7ULL, 
            0xE05D8E602299527EULL, 0x6B5DCBD0EA7BDE0DULL, 0x2D87E6414A1B6FC0ULL, 0x0A57A5EFC1FCA735ULL, 
            0xC0CDEC63922D6120ULL, 0xCBB85DB0CA96E8CBULL, 0x8A75FD44792A15C0ULL, 0x69EB8B7220134A05ULL, 
            0x09C92A6147B799BEULL, 0x47F574B438578C98ULL, 0x328F328F9170FDA3ULL, 0x244B3BAF045C676AULL, 
            0x020A3E688B359737ULL, 0xAE09B9BE4EB92D96ULL, 0xEF7CA4DE4D6FE66FULL, 0x4D0C30B63FA6BDCAULL
        },
        {
            0xA1E5094C59B99D4BULL, 0x67903A30029BA4D6ULL, 0xCF147C16C9370EE7ULL, 0x46550F13E2F209DBULL, 
            0xB6FABB2B95269C73ULL, 0xDF15224D43F5029EULL, 0x13F15A322667BDD5ULL, 0x8F1B71073F73C8B6ULL, 
            0x07664E9FA1FFD3EBULL, 0x3D4D670F75627CB9ULL, 0xFEA99730C5FB3AD5ULL, 0x7E87B3A000F71384ULL, 
            0xA8EEDF0599A69C1CULL, 0xC3466D584DEEC194ULL, 0x0E2FFDF924DE0EEAULL, 0xF65D0640E2E4F613ULL, 
            0x610AF7FF77A508DFULL, 0xE56B0F96F79B6681ULL, 0xC97DFEB568A75A9DULL, 0x349736420C8A3B43ULL, 
            0x6C213AA9CC10687FULL, 0xCEB35356BDA21626ULL, 0x0D6394980605CF59ULL, 0x36BE4DABD47C5CEAULL, 
            0x1A989C78A747B244ULL, 0x8827AFF6D89D5BCCULL, 0xE33753DCB60788F4ULL, 0xA476AF389E41A081ULL, 
            0xAD751163BB46657CULL, 0x6F75591AC3CB683DULL, 0xB601B1971410FBCEULL, 0x4F6770D9E236BF5CULL
        },
        {
            0x3DD41798757A7839ULL, 0xAC2E58C70018D8A6ULL, 0xF5AB3F94F618501BULL, 0xA20DDFF179E90494ULL, 
            0x058D845A166F9202ULL, 0xFEAC66D07D94E9ADULL, 0xA5635C6B5A8A3076ULL, 0xA844CA44F81BFE1CULL, 
            0x8226EBCA7A273673ULL, 0xD031DE95CEBD5A8DULL, 0xD5ED28AC2D19E9DCULL, 0x0B73CA0FDE5EEB08ULL, 
            0xE56BB9E9E762DCC0ULL, 0x5B22C2440ADB95AAULL, 0x25B073991335E614ULL, 0x48D031125EBC89D7ULL, 
            0xB70A13ADA7C231E1ULL, 0xC2401BF8F3A26087ULL, 0x042BBB6F69CE4A83ULL, 0x9907861BEE99BB25ULL, 
            0xC302D33D3E84D109ULL, 0x9D555D30AAE7347BULL, 0xA05529BFD8C1E09EULL, 0xAEC24B5D2554DCACULL, 
            0xB9D5F76298B01196ULL, 0x28D2516D9D4D62EFULL, 0xC08A00DE3F8061C7ULL, 0xB0F226D7DF0AFFD2ULL, 
            0xE459E55C2BDEA291ULL, 0x233C8AE09E490EBBULL, 0xA4D44F8A4661CE68ULL, 0x37BC3EDEEAAF3A73ULL
        }
    },
    {
        {
            0xE320829ECFD10824ULL, 0x59F8B538CB4BB877ULL, 0x257C239D0AFFE59DULL, 0xDC5FBD94F98505FAULL, 
            0x934534BE3A8AE74FULL, 0x092FB82056B94D12ULL, 0xA5DAA1EEAEBED372ULL, 0xC030BE0E01B76611ULL, 
            0x476F3363E5346224ULL, 0xB2168CDE4507CF44ULL, 0x54C515FA1AAA0536ULL, 0x93444A28A01FB9D8ULL, 
            0x3D5F4817B1CB9B47ULL, 0x1FC87888BE7307BAULL, 0x6974EA056FE5E915ULL, 0x4759C57DC78C015DULL, 
            0x0250AC30CD61C122ULL, 0x1B4FA8FFEA00DFB0ULL, 0xC319A559D4FA6BFFULL, 0x99E8B69A12830C36ULL, 
            0x835AAA68083148ABULL, 0xE02D63983355753AULL, 0x0BCA980667A0A4A8ULL, 0x9F610011ABD47F41ULL, 
            0xFDEFB4E5A5F85EF6ULL, 0x329B27865F73B05CULL, 0xAED5D4D940F166F2ULL, 0x209C1D70B699A1EDULL, 
            0xE75A98C88E35F0C0ULL, 0xB65755F4165CBE31ULL, 0x0A3E1721CD15FF18ULL, 0x65E6231D197C0F95ULL
        },
        {
            0x425E05E9D4A52DCFULL, 0x05E819AC53DADCC1ULL, 0xCD472A193DEBD3D2ULL, 0xD976E92EB2DB6ECFULL, 
            0xCA60FDBCC8976FF9ULL, 0xA37B8FD47A2B7712ULL, 0x63825E25860CAA4DULL, 0x60F0B8DA88211A95ULL, 
            0x4CC22B344B7BDC26ULL, 0xA24341225DFCDE34ULL, 0x0947C28938782DEBULL, 0x0B0FED0FF48C5BDFULL, 
            0xC9281D84B5F2EFFBULL, 0x946F79A9B1B5437EULL, 0xE47640A5426B1222ULL, 0x476BF0013754E920ULL, 
            0xD1F48DCEAD141AD9ULL, 0xEDD8980F6090A98CULL, 0x853E1CDBD1125C0BULL, 0xE7031FA9C2E3402EULL, 
            0x1F1B33BDB404C2D3ULL, 0x629C198E5827EC49ULL, 0xC905B310680156B3ULL, 0x16B68E6BDF77E181ULL, 
            0xB50BF4F1410765D9ULL, 0x7AFE1685B6B1CD55ULL, 0x03267BE5E3DDEBCEULL, 0x44D821436F65199FULL, 
            0xA85D0D88C022AD07ULL, 0xEBDED77CF2F0532BULL, 0xC5983898B7C212DAULL, 0xF1CE5383B8674A18ULL
        },
        {
            0x232A284CDD3B5EFBULL, 0x1C3DF7F77195C7DBULL, 0xE055B081F848C5D0ULL, 0x4ABCF8C6ED038E57ULL, 
            0xEF9D9E591322B47EULL, 0x25123788E107BD86ULL, 0x8519682BF89EEB9EULL, 0x47929EF812787798ULL, 
            0x62B469A01A9ABC36ULL, 0x4F83520A3469AD2AULL, 0xB9523FA62D749811ULL, 0x660BF41B1D2BD92CULL, 
            0x1C613359905154C6ULL, 0xEF2B0922A4718008ULL, 0x2F6D47318400CDBCULL, 0x007F27F8B982681DULL, 
            0x1CF3E92F67AD157DULL, 0x87A67C9049FB57ABULL, 0xD4F8B99099EC2AD8ULL, 0x9585BEEA64767597ULL, 
            0x4AAA53A281FCA18BULL, 0x7C12A3E8A06E7968ULL, 0xA8315A9371141F04ULL, 0x92FFE3E49E3A1718ULL, 
            0x8418C29A3EDA6B6EULL, 0xE65E6301B79820C0ULL, 0xE2DFBC8DCC0E316BULL, 0x1EE6CE19A74E97FAULL, 
            0x0F590ADEBB1E0F92ULL, 0x6CEF1A7E399B44A9ULL, 0xAFEBDEBD0D80091EULL, 0xF7C4284ADBDB01C1ULL
        },
        {
            0x1BBB8BB3AD81CA59ULL, 0xF61FE2466552A8C5ULL, 0x63D6B3C35CD57FDFULL, 0x76B28CEA7A423DA3ULL, 
            0xF93F5FF9402AE01CULL, 0x591BFA3F7A079329ULL, 0x617BBF2788CEFD82ULL, 0x2FC0A17B5757A723ULL, 
            0x3514020DB853714AULL, 0xCCA3DF43CBB410E4ULL, 0xF7F6D4A40A16FBB9ULL, 0x826A264CC2A1FE84ULL, 
            0xEF3A30CDDD0E9236ULL, 0xE8449B2C71E3956BULL, 0xCC416D3399DD4CE9ULL, 0x001ABE79FDE4A68AULL, 
            0x7CC2791AE8E9AF5CULL, 0xD56EFB55FE7DCFEEULL, 0xD1EBB9F56065E1D9ULL, 0x5895673A3D807DBEULL, 
            0x4CCDF24AA36724AAULL, 0x5C3A226DC1B7B7C5ULL, 0xBF1041B4A0EDCCBBULL, 0x9CE4439FBD5B5260ULL, 
            0xEE5A236EC40401C0ULL, 0x04EB36EB3B7686CBULL, 0xFB0D53D96A189EA1ULL, 0x30941CD92410758DULL, 
            0x5634767281EF12DFULL, 0xF970F97C29AD971AULL, 0xE34E4F0EFF213B1AULL, 0xDDDE31A61E331EE6ULL
        },
        {
            0xC6B0549FE7E5EBB0ULL, 0xE29BAFD0A8EBE971ULL, 0x579F1837FD48B1F7ULL, 0x48FB5A21FA9AE971ULL, 
            0x300A8241FEF881ABULL, 0x5F049197F8B03B4CULL, 0xEC5515A8860571A1ULL, 0x061686C2E25A108BULL, 
            0xB86E5DAB2B5CF260ULL, 0xD58375C0ACF7A2E4ULL, 0x42B587CD9248239BULL, 0x8DE188465EEC72F2ULL, 
            0xF183182313AF4EBEULL, 0x5EED74DC292CE941ULL, 0x29D361EBCEBAD35FULL, 0x48E80EBDD20CEC62ULL, 
            0x229726E0E9939528ULL, 0xEE47DCF3C41DA82BULL, 0x93FDBC62C0D95260ULL, 0x7ED106670F38C194ULL, 
            0x372D1D653552FD29ULL, 0xB8CA503FEA9A9EF3ULL, 0xB85560E82770C2EDULL, 0x0C8F947E53E2CFB2ULL, 
            0xFCC021820C791D9CULL, 0x5DF3430D28EDB184ULL, 0x728FC04A42DCCE9FULL, 0x11939C57C653BF5DULL, 
            0x5E589E8C0043CF1AULL, 0x85A2A708B1E940F1ULL, 0x610195BA8D35E023ULL, 0x9055209251B87067ULL
        },
        {
            0x1BB4B098C4B33FDFULL, 0xABB9FED3FBAD7056ULL, 0x96BAB725BC5A9D2AULL, 0x3BB95DF7EC5932CEULL, 
            0xC1EB23ED4C6291B4ULL, 0x8554ABDD5FD5D4EAULL, 0xC0E3249A41EEBFCAULL, 0x32DBE416100CA39CULL, 
            0x9FD9C89342927A2AULL, 0x0C809DAC5EA30542ULL, 0x60455B898C0AE42BULL, 0xFB33E2C42ECC134BULL, 
            0xE29E628E54D3C79FULL, 0x20343089581D7078ULL, 0xCAEDEAD7947D27D2ULL, 0xE52DA9D3B591795CULL, 
            0x5852AD4D12B78A9DULL, 0x53A4CDD366934528ULL, 0xC459FB621E22B98EULL, 0xD46EB4654138340CULL, 
            0xB138C6E9A7AA0A80ULL, 0xCCDB256A95307071ULL, 0xF612C514762B717AULL, 0xA40186340974BC01ULL, 
            0x6682D57A0FB2C1E5ULL, 0x5AE4A056C7B4756FULL, 0xDB9F4B65B583C8E4ULL, 0xD0208D3E3ACD2D29ULL, 
            0xE5D083513FC1E13BULL, 0xEA0DBF4FFB567878ULL, 0xE7F0FEF4607FE485ULL, 0xF832CF44198D8B00ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseHConstants = {
    0x050FBBC6FF3B96E8ULL,
    0x37E02688D1E4AE5AULL,
    0x95EEE53E0348A34CULL,
    0x050FBBC6FF3B96E8ULL,
    0x37E02688D1E4AE5AULL,
    0x95EEE53E0348A34CULL,
    0xF4D530584125F63FULL,
    0x5078BFDA30633E3DULL,
    0xE9,
    0xFB,
    0x53,
    0xE8,
    0x54,
    0x7F,
    0x14,
    0x78
};

