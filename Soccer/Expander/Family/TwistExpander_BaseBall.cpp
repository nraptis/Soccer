#include "TwistExpander_BaseBall.hpp"
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

TwistExpander_BaseBall::TwistExpander_BaseBall()
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

void TwistExpander_BaseBall::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x9E289A88936209FCULL; std::uint64_t aIngress = 0xC695C2CC66C1A90AULL; std::uint64_t aCarry = 0xFD44FBE0656CF9F1ULL;

    std::uint64_t aWandererA = 0xFF24353AD5EBAD32ULL; std::uint64_t aWandererB = 0xD072BEBDF889E20EULL; std::uint64_t aWandererC = 0xCF6708B4FAE2F510ULL; std::uint64_t aWandererD = 0xE90B615743D3422FULL;
    std::uint64_t aWandererE = 0xC275C474A7CD90ECULL; std::uint64_t aWandererF = 0xDA6DDBECC42F24E5ULL; std::uint64_t aWandererG = 0xB57C38A04CDAE440ULL; std::uint64_t aWandererH = 0xA9D64D595F80E1E3ULL;
    std::uint64_t aWandererI = 0xD8F712AAE87C29E0ULL; std::uint64_t aWandererJ = 0xB883D722CEBA11F8ULL; std::uint64_t aWandererK = 0xAC38BF6006174707ULL;

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
        aPrevious = 10543893929071268269U;
        aCarry = 12789271265399007876U;
        aWandererA = 14013850298905940033U;
        aWandererB = 13705482132142479312U;
        aWandererC = 13461649301638548050U;
        aWandererD = 13040942097085720729U;
        aWandererE = 11590788709510498655U;
        aWandererF = 9632897031098909050U;
        aWandererG = 16130902437739916902U;
        aWandererH = 10863750798753593591U;
        aWandererI = 15091311904403122261U;
        aWandererJ = 10650970970477152883U;
        aWandererK = 11103457275978491968U;
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
    TwistExpander_BaseBall_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_BaseBall::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xC5D96CCF21C139F2ULL; std::uint64_t aIngress = 0x98696CE21DF466CEULL; std::uint64_t aCarry = 0xCCB4C606DD02C55AULL;

    std::uint64_t aWandererA = 0xB56D21446A83A914ULL; std::uint64_t aWandererB = 0xFCCA7F1A47EEA45DULL; std::uint64_t aWandererC = 0x8EB4A7AC1ABEAD69ULL; std::uint64_t aWandererD = 0xFACAD7D8EACF8A1DULL;
    std::uint64_t aWandererE = 0xF56339DDA0F8992DULL; std::uint64_t aWandererF = 0x9D959328343D3564ULL; std::uint64_t aWandererG = 0xB3281BBD8ACAC9CFULL; std::uint64_t aWandererH = 0xCBF7E35FE34AE1B4ULL;
    std::uint64_t aWandererI = 0x834A1D07166A2268ULL; std::uint64_t aWandererJ = 0xC6B862F176C670EBULL; std::uint64_t aWandererK = 0xB2B385CB0A984592ULL;

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
        aPrevious = 16877484015708493279U;
        aCarry = 13686230646307414501U;
        aWandererA = 18136375924300059456U;
        aWandererB = 13551020356147180246U;
        aWandererC = 13024291710815768035U;
        aWandererD = 14422308082058650149U;
        aWandererE = 13206295958680529427U;
        aWandererF = 11083862840963606514U;
        aWandererG = 9899519991318750311U;
        aWandererH = 17253741814420427119U;
        aWandererI = 14813750081212595348U;
        aWandererJ = 12365637431515589447U;
        aWandererK = 17780033133355328610U;
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
    TwistExpander_BaseBall_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_BaseBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x864FA82787DE4C7CULL;
    std::uint64_t aIngress = 0xD2EF4C29097532A8ULL;
    std::uint64_t aCarry = 0xF52643DD48130291ULL;

    std::uint64_t aWandererA = 0xA71ADBF9EF18EF28ULL;
    std::uint64_t aWandererB = 0xF7D5DDD7946931B6ULL;
    std::uint64_t aWandererC = 0xEF08F0CD73B7E026ULL;
    std::uint64_t aWandererD = 0x80E2DC273968B3B1ULL;
    std::uint64_t aWandererE = 0xDB0D54D1B367DE77ULL;
    std::uint64_t aWandererF = 0x966A1FE1D0CFFA4EULL;
    std::uint64_t aWandererG = 0x90DE814AC27AB491ULL;
    std::uint64_t aWandererH = 0xD4F61995D556309AULL;
    std::uint64_t aWandererI = 0xDB2DC2D016E7842AULL;
    std::uint64_t aWandererJ = 0x91059E1863156986ULL;
    std::uint64_t aWandererK = 0xAD70FC162E29C31BULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA, 1);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC, 3);
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
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneE);
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneD);
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC, 7);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    TwistExpander_BaseBall_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_BaseBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_BaseBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x942CC157C0ABE751ULL; std::uint64_t aIngress = 0xF3D9FF000F20DA9AULL; std::uint64_t aCarry = 0xDF7E030FDFAF4CFCULL;

    std::uint64_t aWandererA = 0xE6917222A9BFD5EFULL; std::uint64_t aWandererB = 0xCAB2EF8B58AAA9F2ULL; std::uint64_t aWandererC = 0xD7A7C4307657CFEAULL; std::uint64_t aWandererD = 0x804DA86267EEF83EULL;
    std::uint64_t aWandererE = 0xB649BF8E12863A67ULL; std::uint64_t aWandererF = 0x95A379C15CE1ABD1ULL; std::uint64_t aWandererG = 0x9B1999DE5FA10745ULL; std::uint64_t aWandererH = 0xF987A7D7D6607DDDULL;
    std::uint64_t aWandererI = 0xA892388DF02D9ABEULL; std::uint64_t aWandererJ = 0x97B5E9031C907B03ULL; std::uint64_t aWandererK = 0x8994A2B5EEC61E80ULL;

    // [seed]
    {
        aPrevious = 13986149239606091162U;
        aCarry = 12944696176040111307U;
        aWandererA = 11857032076046201392U;
        aWandererB = 12301345799649142131U;
        aWandererC = 15208187812873368783U;
        aWandererD = 17359303876312839868U;
        aWandererE = 15091311886081150275U;
        aWandererF = 12545487418294200293U;
        aWandererG = 17048117366260436604U;
        aWandererH = 18429953641196516049U;
        aWandererI = 17209579645711117712U;
        aWandererJ = 15402883062495248460U;
        aWandererK = 10367493962527001309U;
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
    TwistExpander_BaseBall_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_BaseBall_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_BaseBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_BaseBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 3, 0 with offsets 5802U, 6950U, 6059U, 1524U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5802U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6950U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6059U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1524U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 2, 1 with offsets 576U, 2787U, 6817U, 1441U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 576U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2787U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6817U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1441U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 0, 2 with offsets 7516U, 4332U, 7746U, 5282U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7516U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4332U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7746U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5282U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 1, 3 with offsets 1081U, 5601U, 3346U, 5404U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1081U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5601U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3346U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5404U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 3, 0 with offsets 652U, 994U, 658U, 1695U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 652U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 658U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1695U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 2, 1, 0 with offsets 2036U, 60U, 1987U, 697U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2036U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 60U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1987U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 697U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 2, 3, 1 with offsets 1864U, 1999U, 1426U, 2014U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1864U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1999U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1426U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2014U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 3, 1, 2 with offsets 1371U, 1545U, 299U, 535U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1371U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1545U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 299U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 535U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1678U, 6U, 1045U, 16U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1678U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 6U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1045U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 16U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_BaseBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 1, 3 with offsets 4938U, 5085U, 5528U, 2461U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4938U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5085U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5528U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2461U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 3, 2 with offsets 4014U, 1068U, 1350U, 507U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4014U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1068U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1350U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 507U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 0, 1 with offsets 1390U, 5787U, 2177U, 3207U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1390U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5787U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2177U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3207U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 0 with offsets 7159U, 5576U, 981U, 4993U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5576U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 981U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4993U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 94U, 6510U, 6294U, 5083U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 94U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6510U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6294U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5083U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1858U, 1098U, 1953U, 1130U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1858U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1098U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1953U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1130U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 827U, 318U, 1513U, 979U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 827U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1513U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 979U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1259U, 1389U, 937U, 101U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1259U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1389U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 937U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 101U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 539U, 1827U, 338U, 7U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 539U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1827U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 338U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 7U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 0, 3 [0..<W_KEY]
        // offsets: 1150U, 317U, 1259U, 2006U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 317U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1259U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2006U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseASalts = {
    {
        {
            0xC1A8BE25B8294075ULL, 0xD84FF83C6B57A688ULL, 0xBAD11DBF389EC3F6ULL, 0x3E23C3FD71E44EDFULL, 
            0x004D2AC14784CCFDULL, 0x5B05B0E5C38102FAULL, 0x9504C40E48731D0AULL, 0xCE46F234B04C3717ULL, 
            0xA1672FED16505D0AULL, 0xC7CF762C3D3ADBC5ULL, 0xE76EC7E21C294569ULL, 0xDCCA251E377D7B2EULL, 
            0xF545B0295E50DFC0ULL, 0xC17BF795E2B7A997ULL, 0x35C7D9A3471E730EULL, 0xC95A661878A8F9D3ULL, 
            0x9A1147DA40164096ULL, 0x7501B83BF22AC42CULL, 0x4229C2E176C8F37EULL, 0x4905C026C39A8D1BULL, 
            0xC8231CC784132CA5ULL, 0x11592B7719D762C6ULL, 0x3FEE6C27525DAE94ULL, 0xEEC6E24E8866681FULL, 
            0x62F21F994482D874ULL, 0x9BF8D74B73B4693CULL, 0x88E8B9E8170D3A41ULL, 0x967E09FBFFF240B6ULL, 
            0xF4E1292B76CC8B1DULL, 0x69954E7E24422552ULL, 0x7B66C5CFDAEB8397ULL, 0x0A271A0792DA9755ULL
        },
        {
            0x9C177186E439F556ULL, 0x9730597351031AB3ULL, 0x49F14B993F0332CCULL, 0xF28E536B807D6F09ULL, 
            0x6F9B60143093586DULL, 0x8005C22E7A223F27ULL, 0xBDB4AE3411EBB766ULL, 0x8F76C16A15E51518ULL, 
            0x604A7F09A8B69037ULL, 0xA0ED9B50AFCDCC79ULL, 0x4D2B78298AF3AFE6ULL, 0x4DE64CDC9DE73BA2ULL, 
            0xAD2A7D118DFDC8B5ULL, 0x690EEFC2C47BA8E5ULL, 0x4460C8D87FCF447BULL, 0xBB39CF4D59488939ULL, 
            0x73634D2FFE2EF250ULL, 0x7C3F4011F8891E16ULL, 0x070EA9DA5E8886ECULL, 0xB500E0119D426ACCULL, 
            0xA567D2A3667F62EDULL, 0x7BFC2DCCB481F6A4ULL, 0xCD7CAEBA0107E826ULL, 0x2B43FD779671C030ULL, 
            0x2C5D5F7E77B79BCDULL, 0x3F1796A93D810E82ULL, 0x13C3D54A6E7C82FCULL, 0x29D447FF5A8614CFULL, 
            0x25790F78258E97AAULL, 0x4089438D50ABCAF4ULL, 0x8FE7EA2BC36B9879ULL, 0x55896121F564FCCEULL
        },
        {
            0xF92D78FC693223C3ULL, 0xBCC85690DF6DAE28ULL, 0xA953ED29BC530C47ULL, 0xE70ACB954DFAF05CULL, 
            0xB1D701317077EC9BULL, 0x3421D2F8E30090C8ULL, 0x56D3BCED8EA5308BULL, 0xADC789771E365D5DULL, 
            0x7ACA612CBF469B08ULL, 0x5D4399E61D31778BULL, 0x42EDB7071F608D89ULL, 0xFCA72CA02FAA5204ULL, 
            0xFF58CC9C187448AFULL, 0x05863BD6A5DD6ECFULL, 0x91D85C007D35EC06ULL, 0xD28324955A639387ULL, 
            0x8450E586A6C04902ULL, 0xDB21AB48B3A6BCBFULL, 0x2235075B0D305C09ULL, 0x1AEA08B41A386268ULL, 
            0x2F1BD60F786577D9ULL, 0x1A39A59882F4FBECULL, 0x0E34AAD1709A79D0ULL, 0xA487083F88D9C64CULL, 
            0x6E3A6A1022C89E6AULL, 0xA9E2B85E7FBDF12CULL, 0x547FA2793787E0EFULL, 0x7685EBF1ADA2D0C9ULL, 
            0x099B05FBACFADE82ULL, 0xAF5B7D23493401B5ULL, 0xDBB208D268AF2154ULL, 0x2E6570AE70CD283AULL
        },
        {
            0xECA79C8EE2402026ULL, 0xA75FB15F15120010ULL, 0x2D9A8EE40E2A2E74ULL, 0x058ED0DABEA396E9ULL, 
            0x02511279E310FB22ULL, 0x7BAE03D9B7561A11ULL, 0x6A91A095C9B97322ULL, 0x361F02008584C00EULL, 
            0x192EA3C44C4AD512ULL, 0xD85F66A29EE91167ULL, 0x8B99CD458A6287D0ULL, 0x50940C754424910BULL, 
            0xE05DC90CEAC6F1CBULL, 0x0DEC30FE224D1B97ULL, 0xA34868C81C3FD283ULL, 0xE08936D73E76AB84ULL, 
            0x8CE04F301D107EC8ULL, 0x77DFFBF0664D3C9BULL, 0x8B4284F82A41048DULL, 0xF6A65169D99D9444ULL, 
            0x13129310ECAC83A4ULL, 0x797EB33A96B8755FULL, 0xD683DC5EDADFDCABULL, 0x147DF40573568C52ULL, 
            0x0CD69CD5A6AC6EA6ULL, 0x745270FBF9F129F7ULL, 0xDE984BD452226072ULL, 0xB3EF94040A96CE7BULL, 
            0xABDF4673F3DF6494ULL, 0xFE48CCF0AC92C66FULL, 0xE77B1B3C25804A93ULL, 0xD7CA75468C9204BCULL
        },
        {
            0x80889589FB449198ULL, 0x2A0AF52876997ECCULL, 0x52D7BA16C7CEE1C4ULL, 0x1EDF90327BA9AA7BULL, 
            0x22E808B1F103D98DULL, 0xDFC996A54E3641BDULL, 0xC984F186F4E399ACULL, 0xE324CA6440CFF8AAULL, 
            0xC6F63B06D237353DULL, 0x418692F96CC8E4CFULL, 0x66A605E2834BAA2DULL, 0x3BF603457701DCE4ULL, 
            0xBEAE39D37BF34050ULL, 0x076EF1711E9A564EULL, 0xF024BF5EC0F844FFULL, 0xE4C71D12839C180AULL, 
            0x567524EDA8956D00ULL, 0x6F5D8F017C4C5DE7ULL, 0x86F813EC1E3532D0ULL, 0x0D3423A779818A76ULL, 
            0x69A08B1A5CA32F00ULL, 0x2BE321C4132BA29BULL, 0x9354936A284A58D0ULL, 0x0603EC550B456510ULL, 
            0x10DD91193111D71DULL, 0xE7099D93BA5DE481ULL, 0x310AAA7E7DA12A01ULL, 0x7D739FBE392C9CBFULL, 
            0x1E0C731FCDFE7FF3ULL, 0xE6CBF2978DD70B6EULL, 0x15EC622E84D85798ULL, 0x3890A236AD43061CULL
        },
        {
            0x03A7DCCC8F27C958ULL, 0x3C1A778BFF8E85C1ULL, 0xA663123B7342D517ULL, 0xFC89F38A127E19D1ULL, 
            0x85F058BC8B823BB1ULL, 0x5C4A75FB9DA220BCULL, 0xC3559F03E916B86DULL, 0x1AC50631C8D67121ULL, 
            0x4C552E314B5E0D34ULL, 0x4D65BB13E0CC7996ULL, 0xC9AC92336B83C8BCULL, 0x8B3065E6F3053415ULL, 
            0xD589FAA993908C6FULL, 0x11E6223FBAC2FA84ULL, 0xB41859DA82CB9E21ULL, 0x61D5718D6B45A112ULL, 
            0x12528308715E556AULL, 0xC90B7FC305AEBD0AULL, 0x9B6B7211513F37D9ULL, 0xF8A8AB6C92BCE5E4ULL, 
            0xA5419B9FEF098C0CULL, 0xB6947C819F173D6EULL, 0x6F2710B1095395CFULL, 0x8DB7382525F67E52ULL, 
            0xBC4E850A248B3C3DULL, 0xA7676F4001C4388BULL, 0x554320327A3EE8F0ULL, 0xA04556CE6CB81582ULL, 
            0x7C46222AB30EA68FULL, 0x49DC5F7B89FBF791ULL, 0x7B6766656C72ACA8ULL, 0x0DCFE47D3E577E99ULL
        }
    },
    {
        {
            0xAEC60600332D37D7ULL, 0x867AF07BA4F6E041ULL, 0x0E2BF559687FF8D0ULL, 0xE2195B8E593A4AADULL, 
            0x6185AE6CF87B5E7FULL, 0x1111955817CC6E3DULL, 0x47253CFE6C75884CULL, 0x3AA5AC4D152D8C4CULL, 
            0x774DE57BD7C52CD5ULL, 0xC9805C9162F5F414ULL, 0x21D6A8AFADDC574EULL, 0xFBCDFF514AB907F9ULL, 
            0x22DE35D1C081D9F5ULL, 0x76D90B35CFCF388CULL, 0x8070B591E4352F76ULL, 0xA34A03DABC77C591ULL, 
            0xF50C7D82693F973CULL, 0x2878D25AE8965493ULL, 0x8EDED3A152EDE170ULL, 0x271D98C31CCFC12AULL, 
            0x61AA708D91CBFBBAULL, 0x327AF4412D75C8D0ULL, 0x3AC6CA123CB2FAB0ULL, 0xBD5273F2D8A74106ULL, 
            0x8B7C8CF27EFC2EABULL, 0xC22BC11CEBA1FA7BULL, 0x2AC70B87CEC12507ULL, 0x82AB1FF19A2E5B45ULL, 
            0xAB8D6268B29CFACBULL, 0xBDE187B07B5F4AA6ULL, 0x70519CAFEB1B032FULL, 0x1BECB7310022651BULL
        },
        {
            0xD9997349D155FFB3ULL, 0xD84303EB184688CCULL, 0xE85BA196C4EC7FEEULL, 0x0F9F6F998628F5F2ULL, 
            0x47079F91C617D676ULL, 0x08B7151577DC6584ULL, 0x885CCA827730A26BULL, 0xF0CC1A36623B898AULL, 
            0xDD8A2795BDC8F7CAULL, 0x8B5DAD60A2826FDBULL, 0x5419DBDC30796827ULL, 0x3E3D1BB24DA93A51ULL, 
            0xC6DF804F5A6E29F4ULL, 0x23E04DAA47A1030DULL, 0x3515BCFF1398A1E8ULL, 0xAA573EF86BAC8F06ULL, 
            0x8DD033AAC49F4BCFULL, 0x4081014C6BFF0A80ULL, 0x98E26F5128E18732ULL, 0xD85D879773DBA6A5ULL, 
            0x4DF960D2C1EBC204ULL, 0x54AF926D6B47BF47ULL, 0x18FBBE6530E95443ULL, 0xCC3B686F7871AACDULL, 
            0xDDBDEA16CC3C2271ULL, 0x89BD5211321D7C43ULL, 0xDFD58A71921D2D1AULL, 0xC539A14381848F44ULL, 
            0xB349175867DE4227ULL, 0x7BF18B6349004FA2ULL, 0x2169145C929F6270ULL, 0x0333DE74E360FE0CULL
        },
        {
            0x1B972E971A0903FBULL, 0xAF37CED5DD7758DAULL, 0xFF90258D6898BF80ULL, 0xDDBA45C537092DCBULL, 
            0x556BD42AF1CADB94ULL, 0x87FFBF812088EAAFULL, 0xF920F01FF7E0E6CEULL, 0xCB0E792324BE811BULL, 
            0x28A9808668C033EDULL, 0xCC8A81EE01E3FC46ULL, 0x741C684CE3DE55DAULL, 0x399E1E45A6B35033ULL, 
            0xE99F8533FFE204DCULL, 0xAAC4F419225A2916ULL, 0x507629B8FE09EFF1ULL, 0x5078D33C868CAAADULL, 
            0xB53E6C766971CB9AULL, 0xF9F8CC0583D50993ULL, 0x1523DC40C0DEACC5ULL, 0x5CA78D9AAEAB7653ULL, 
            0xD34D243FFB0FDA97ULL, 0x569A2DBF1D8BE6CDULL, 0x71A90170F3167FA1ULL, 0xABB7B3931072C953ULL, 
            0x41E87B1C3A618E83ULL, 0x40071AFE26223508ULL, 0x8317E862636873F7ULL, 0x5CE81D66871B2F18ULL, 
            0xB48D2FE5A55A8D04ULL, 0x4AE56E832E6E515EULL, 0x27990EC2499EF35CULL, 0xCF894D117CBB2F50ULL
        },
        {
            0x8D0604A0EA30D041ULL, 0xF9F67D2FD5277D24ULL, 0x9E5F6AA2FAE83287ULL, 0x4448DD72DCF1DC69ULL, 
            0x0EDCF7228C9F2B70ULL, 0xFEE993E5D1EA8C6BULL, 0x89D3161F4CA8D7DAULL, 0xCF63B2521F7E154BULL, 
            0xACC17D26B86625C2ULL, 0xEA83B009F221C937ULL, 0x7BD6E93DD8D1576FULL, 0x03FB374A438A7C4FULL, 
            0x42AE50542FA5B011ULL, 0x7D1A40AA798821E4ULL, 0x70B5DF83D51A4982ULL, 0x5F387618AC638C0BULL, 
            0xBC892817E5EFC233ULL, 0xB2624C9587A66C1FULL, 0x0609249BF413E5A0ULL, 0x627D9CE38C586BBCULL, 
            0x0C174328439C7BBCULL, 0x5DF39D346B8A43ADULL, 0x7BB4F4779FBBA556ULL, 0xB73B24B348BCD2BFULL, 
            0xFE24A47D7D6F2038ULL, 0x267DEB1F3356FA2DULL, 0x6B5DA0FC4014970FULL, 0xA1542AF4AE5FDAC6ULL, 
            0x9E74C15FC496F819ULL, 0x5E84829D15973697ULL, 0x77126D5857E654BEULL, 0x46241DA590660BDBULL
        },
        {
            0xB460C403047BB335ULL, 0xB9CCACFAB9D5829CULL, 0x8590B7C1D13A597AULL, 0x32FEE37FA564FDE0ULL, 
            0x55D85D8FCC57956EULL, 0x7D45665CD635031EULL, 0x2CE40F6DE9B2189EULL, 0xFE562D6D970A5755ULL, 
            0xE78A77199D813542ULL, 0xE8738E7BC025D074ULL, 0xC0C69180F1AE7F2FULL, 0x917F23F313058D1AULL, 
            0x20DB438921E13E04ULL, 0x9D13132A4726E3EFULL, 0xCEA9DB3C8743F665ULL, 0xA86BCD19FCEEF761ULL, 
            0x7C0D21C0F199AE8AULL, 0x91C2368AB1C08426ULL, 0x21E5AF8257324E18ULL, 0xB33864EF41370EF4ULL, 
            0x6C7698671DFC8A96ULL, 0x3A675AE727827C9AULL, 0xE7D541F2E017ECE2ULL, 0xF7AA499477DBBF70ULL, 
            0x34AD239E78DF4B28ULL, 0x1FA4A84B84717281ULL, 0xA6122FA30B60A37CULL, 0x6A5AC5E81F047F36ULL, 
            0x2634EB1912472401ULL, 0x5DF928F94E0E48CAULL, 0xED4F466334F4FB6AULL, 0xA12E62ED0D28DECEULL
        },
        {
            0x5D96F3B13E418B74ULL, 0xB2320C054609442BULL, 0x466A5683F726347BULL, 0x2AAD7927FE8CC91FULL, 
            0x2053638431CE75DCULL, 0x541F37A28D355D54ULL, 0x3F77E0F4DAD1C86FULL, 0x6B60BA71C85665D9ULL, 
            0xCD4AC692B58F4C78ULL, 0x3746CB1B4A9C4946ULL, 0x223F86962FBA709CULL, 0x371A1287E02A7990ULL, 
            0x4940C4CDAB844D03ULL, 0x679C8B4233A18078ULL, 0x832FE86632421531ULL, 0x9064D8F5790C68C3ULL, 
            0x985F3F3695116506ULL, 0xAECE814D8DE1CDDDULL, 0x9CCBBCFFCA0DEB8CULL, 0xFF6BEEC00DCD5817ULL, 
            0xB78B33E11592A716ULL, 0x1C377BB044A42E13ULL, 0x611533CE2139C83BULL, 0x0CE0DBB8B7C751DBULL, 
            0x0DF41DB2E097AB05ULL, 0x06CC30FF5F385BFCULL, 0x28515E3F43A476B8ULL, 0x6C4704B7F874C2C6ULL, 
            0x0D985FD030782593ULL, 0xB6350112A1D2D26AULL, 0x7409B8EA42D839EAULL, 0x64FE12395C1BE373ULL
        }
    },
    {
        {
            0x4811FBD575584929ULL, 0x63C2E7106D54CA74ULL, 0x0E7A64B2D5985C16ULL, 0x065399825F9ED369ULL, 
            0xC2C428643120724DULL, 0xE957934692E2DA2AULL, 0x023655BF6256B531ULL, 0x49D7A1529C74C69DULL, 
            0x3ADA471D9F3B91B6ULL, 0xDF1D6C05476D8CEFULL, 0xA1FD760A94FABECBULL, 0x69B96B69E02253F4ULL, 
            0x4F8F3E90268B42A3ULL, 0x13C07F3F1DAE872EULL, 0x7B95E6334F82EAD6ULL, 0xA10733945D8E791EULL, 
            0x191F096D56710A07ULL, 0x4BBA796E3B2D9B75ULL, 0x3BEF2BA8608538C6ULL, 0xB93918C73775EE27ULL, 
            0xB54B31285E29E41DULL, 0xFA0DA139E501C84BULL, 0x7613737F503BB90FULL, 0x93C0F2111F331CA7ULL, 
            0x241EBB55C8DD7C82ULL, 0x4ECCCBAE6E76CB74ULL, 0x8CBEBEC86A089873ULL, 0x69F41338C2621231ULL, 
            0xA871AA3A3AF43A8BULL, 0x10AF2FF8C35996DEULL, 0xBBE56D528D280421ULL, 0x6F32675A518C97A3ULL
        },
        {
            0x1EA68BED838E0BDEULL, 0x0E95626FB45134C0ULL, 0x47B08A7109C987A9ULL, 0x4DC79D3EEC5A2422ULL, 
            0xECA67D2DB0EE93B1ULL, 0xC4A1555735521838ULL, 0x1D0586279DE8F8A9ULL, 0x59351AF85ED2E82EULL, 
            0x204CDD7A5805326DULL, 0x1727F483BF6BFAA8ULL, 0x00438F5E630D1844ULL, 0x7F5B4290C56BF56AULL, 
            0x2FF12078A7EFC4B5ULL, 0x59729D9A155D6EBFULL, 0xA10D655D26346D38ULL, 0x99C924A72A8422B4ULL, 
            0xA872B4EA83CAAD59ULL, 0x68216D449C27B8CAULL, 0xF7F830CB3AB9178AULL, 0xA6A85831F41AAF9CULL, 
            0xDC650EC61A8F4C96ULL, 0x132DAECA0D2B68E2ULL, 0x5200E906A98C0FCDULL, 0x529973180554959CULL, 
            0xE76896BAF8978E71ULL, 0x5AB9455CE1C12B49ULL, 0xC9EC77D432D343DDULL, 0x84A059FE4FC83C35ULL, 
            0x20458D6C1E511487ULL, 0x8C745D507D012999ULL, 0xDCCD07B4742C1664ULL, 0xD843CD332CC73C43ULL
        },
        {
            0xD673C7259F4B7B3AULL, 0xAC31CD3ED4E7202AULL, 0xE83D84E5290A943BULL, 0x7A0955DC39AFA541ULL, 
            0x7817FA8786966118ULL, 0x5E2FAA990C32DD31ULL, 0xCE7D593669ED110BULL, 0xD1B090CFC7AACCDAULL, 
            0xBDF0F961D14B126EULL, 0x6578D40DD06B2932ULL, 0xA45488878F6523D1ULL, 0x209719778F553A65ULL, 
            0x88D0E7EB1062576AULL, 0x768F9AF7F6CCD904ULL, 0xDCD2017373942E12ULL, 0x6038E99F5D39120FULL, 
            0xE1F8ED8F5A994D09ULL, 0x05380D494ED96EFAULL, 0x2A51B14EEF1E1648ULL, 0xC21ADC27AF282ADCULL, 
            0x6A992C165D4E6D57ULL, 0xF7DE5E29ABA99248ULL, 0x0F4A994F18A7CF8EULL, 0xB15F496006453766ULL, 
            0x4A7F17D292325CC0ULL, 0xF2BBCB74A64433E5ULL, 0x40D3400678BA8A78ULL, 0xFC4AF348D04D0459ULL, 
            0xD5E536CC0C431924ULL, 0x6D3ACF4B1B12FC1EULL, 0x2A0AF9D6B6B8822EULL, 0x911A808E689D4607ULL
        },
        {
            0xFEA50000A4746157ULL, 0x7A9298F720E5E54CULL, 0x32714E6AA15F1495ULL, 0x4C81229D0B5FD1B9ULL, 
            0x3D2148AF0E3CCCFAULL, 0x38E9847B7CEEBF3CULL, 0xBF84648C7836CBBCULL, 0xFCA493293785AC68ULL, 
            0x02D4F6758DEB3146ULL, 0x9C006C102C914BABULL, 0x6217ABFCFB92E0B0ULL, 0x5DE82A158664E2F0ULL, 
            0x8CDDA19B7DA23807ULL, 0x6ABE42845CF02DB0ULL, 0xD2BD73443A58C106ULL, 0xD6764E5909C6BAC9ULL, 
            0x2B80DD392B6D17FDULL, 0xFFA51331A65368F6ULL, 0xC01510008FC15487ULL, 0x8CF922813ECDB881ULL, 
            0xA329BAD961F31DCCULL, 0xFBA2455F4223EEF3ULL, 0xA33BC4DCE1F78DCFULL, 0x23C850923093FAE3ULL, 
            0x2970FFD4D0341A82ULL, 0x71EEB1B68479DD54ULL, 0xBF7F7F38E181E0FAULL, 0xA65455F88809CF01ULL, 
            0x5B47618F8131E694ULL, 0xE420C82F36B15252ULL, 0x5B19DDD9A0254AA1ULL, 0xAB29736369F94639ULL
        },
        {
            0xFF501D1E946C178BULL, 0x9864F2B95227BA0DULL, 0xAE94053E383119E2ULL, 0xE3F22D3D2A8C26D0ULL, 
            0x4A7993FA7AB530D8ULL, 0x13DD9A94BD869C19ULL, 0x386A02AD579A92D5ULL, 0xDDCBD7F2B635B427ULL, 
            0x115A8A97157CB178ULL, 0x06ECB0ECE2B4F1A6ULL, 0xDF4CE3E8DAD347EBULL, 0x43F54F2754E2635BULL, 
            0xD3377225F929A859ULL, 0x4C096A13B7AB864EULL, 0x665E5207E9C8AC04ULL, 0x5D78E8F023A0E91BULL, 
            0xB5543A574648CD7AULL, 0x1735AA38822DB2D4ULL, 0x8A61A35FA8F8AD9AULL, 0x79EA772F7F0A4BD5ULL, 
            0x11B91F6F618E3A04ULL, 0xD4830047F44CC691ULL, 0x90D23E10683C4E63ULL, 0x71D4D3D82EBED2ABULL, 
            0x08F080C0B3FB0933ULL, 0xA90A50044D31D47EULL, 0x7046AF14206CC949ULL, 0x9DF35D40D79A1163ULL, 
            0xBC08AD27481E4708ULL, 0xC540E78B6AF20075ULL, 0xCA4030CF5EE23E59ULL, 0x13129E6ECE41B45BULL
        },
        {
            0x3925BCA8AB14D346ULL, 0xE6F99F1D64408769ULL, 0x654C6DA4DFC49E2CULL, 0xE622563C535DAFE8ULL, 
            0x9E2E83E4A373F295ULL, 0x23B03331D9E56913ULL, 0x869AA1CE887026CFULL, 0x4C38607096393ABFULL, 
            0x0E9388F9AA093324ULL, 0xC59E9C9ADD30BE97ULL, 0xB91C28E0644177D9ULL, 0x32A53F2547297770ULL, 
            0x7F1A8E0171B39BACULL, 0xE229BF05115A455AULL, 0x5B8D9A623473E186ULL, 0x644D9B0A85E1B017ULL, 
            0xF856BF1B20B3F399ULL, 0xEFCBA5B3AE1AEC40ULL, 0xD4006165C3D61765ULL, 0x2AC936AEA5D593C0ULL, 
            0x68ADB3D0AA3F3EB4ULL, 0x5DFE336173875F49ULL, 0xC51B04EB628D12EAULL, 0x2649B44D964FEDC0ULL, 
            0x8562D192AFDFD666ULL, 0x0153D1436765CB5AULL, 0xD85989A21ADD3821ULL, 0x994C58E071CFD8DEULL, 
            0x2C425584B52E71CEULL, 0xB0C1035D7E73A399ULL, 0x350A35A167653E71ULL, 0x9F03A23835B77E03ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseAConstants = {
    0x5A32EB3573E00396ULL,
    0x7F884E54FDAC0CA4ULL,
    0x55201501EC888BB7ULL,
    0x5A32EB3573E00396ULL,
    0x7F884E54FDAC0CA4ULL,
    0x55201501EC888BB7ULL,
    0xF31F9D58DB2AA59AULL,
    0xC6270D8DAB03CF92ULL,
    0x8A,
    0x5A,
    0xA4,
    0xF6,
    0x33,
    0xA1,
    0x10,
    0xF9
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseBSalts = {
    {
        {
            0xAF5657DE760C632AULL, 0x093733504E60E564ULL, 0xFEC38F78A230A72DULL, 0xD4D30C02768ADDE2ULL, 
            0x56F962BBE2D70687ULL, 0x4B35673557952E99ULL, 0x45C5148D4D0C026FULL, 0x7AD3F7632DBCAF6AULL, 
            0x4AA73C20F35513F6ULL, 0x5784CEA2EE989471ULL, 0x4413F84607324AC9ULL, 0x0B6F88FEA1CE4B1BULL, 
            0x9C993FC72F488366ULL, 0x467569CF785DA159ULL, 0xE8B36C087F185C01ULL, 0x99C9750EB672F66DULL, 
            0xA85F2D56AE563FF4ULL, 0xC4DBEAC59979AC93ULL, 0xCA6F3B3C0818E364ULL, 0x6D84E974C2BA4725ULL, 
            0xF14E91FC711A6BFAULL, 0x633F4E65FCB18514ULL, 0xCF33207E894A4D71ULL, 0xEDC9DA80AC0AC2BCULL, 
            0xB758A8529795BA41ULL, 0xEE3DAF7D69E8AD15ULL, 0xDC1CB0C56D496AFBULL, 0xBCDDE63C72D81293ULL, 
            0x59173944A15AA686ULL, 0x315ED7CE333F8DCFULL, 0xA8CB602F797D6DB3ULL, 0xF6B31117C8FD0617ULL
        },
        {
            0x286FAE7E10C73431ULL, 0x19B84231F24C1E0FULL, 0x8B4C445EB2637DD2ULL, 0x64E681313DCF66E7ULL, 
            0xAC2F2DA1DA018049ULL, 0x4F6EC6F35AD5CC76ULL, 0x6FA0CDCD695F23C5ULL, 0xFFF2989AC0751A47ULL, 
            0x265AC98B09D9385BULL, 0x4F95312B0A9027FEULL, 0xCF4CBC35B5E04A52ULL, 0xAA476EAA7B50DFFDULL, 
            0x6AFD3239404738BCULL, 0xB071CECC833684E6ULL, 0x02CC0170125E8D2FULL, 0x04E74FE783B736E6ULL, 
            0xEE948A47AD457338ULL, 0x1255FC0BF5BFC7DCULL, 0x1F4FB0B3CA009AD3ULL, 0xE42FB78453FC5358ULL, 
            0xAE87E6B055BF8F5AULL, 0x899A7ED23B2C9AD0ULL, 0x85E0084B17DFAB98ULL, 0x9607246A18E084BAULL, 
            0xC30101AE10A5C3A2ULL, 0xD28C92F6C80AD30DULL, 0xF1BC3C0471F197C7ULL, 0x61CCEA1324F8901BULL, 
            0xA6C74DF5C25049FBULL, 0xEB1A5B6B5AB20523ULL, 0x81310BCBB7FC8373ULL, 0x38711446BB5F4C94ULL
        },
        {
            0x170A148DFA0275D6ULL, 0x770E183189532B15ULL, 0x6B7FED8C6EDB451DULL, 0x47901FDEFD878E06ULL, 
            0x9680DB81A431E9EEULL, 0x0DFA9F18082C38CDULL, 0xC8CCC5C6159917BAULL, 0x61EC618D2D0BDDF5ULL, 
            0x5844D994B0CD665FULL, 0x26FCB16565095B65ULL, 0xE8ECDA0FCB0D9C1EULL, 0x0A7E59C5CD6C93CAULL, 
            0x4D31C026935AB9BBULL, 0xC746628B79C5C1E5ULL, 0x2A989D28A5AC5271ULL, 0xD230FCBE805F800AULL, 
            0x983F676C198CF654ULL, 0xCCE547FBEB5608A7ULL, 0xAF0E8E89608F50C0ULL, 0x1A09F043E57AD67AULL, 
            0x7D2D701C1F18C5C9ULL, 0x4FB418DAA8818752ULL, 0xCF54A35C100940F0ULL, 0xAAFE365D9B219567ULL, 
            0x8A4F750D0E78C320ULL, 0x0698E62CEBBB9BC7ULL, 0x145C3E5342DB7797ULL, 0xE206577F17F23A26ULL, 
            0x4CAC50472F51DF03ULL, 0x86445EF7C76C4A6EULL, 0xCFBE04DB99E7B5E3ULL, 0x923962EB8F77C3AEULL
        },
        {
            0xA82180EB1A4C2E41ULL, 0x17A7C9E5DB76DAF2ULL, 0x61358E67565D4007ULL, 0xC7172DF9922215F3ULL, 
            0xC4A9D48152A99E7FULL, 0xE0C557C95BB78E96ULL, 0x9A23B8BF9BB34937ULL, 0x578EF33483C9A42AULL, 
            0x19CFBEE1D7B0363EULL, 0x5D4257E984A11839ULL, 0x938BE42C63E53F21ULL, 0x88D43E58F7089CA1ULL, 
            0xFB5F135530DDCA32ULL, 0x79C4824B0A3779C9ULL, 0xD76A217A043BDDB7ULL, 0x9404989F5EFB427AULL, 
            0x10C04252FF7A2967ULL, 0x775E2B5A001FA8D5ULL, 0x050FD53EFE84EDE6ULL, 0x89839F031A9400F5ULL, 
            0xE3CA5593100F6FDDULL, 0x97D7C9F3B9C98237ULL, 0x659158A9FF0831FBULL, 0xB6D924EF66C3742AULL, 
            0x500857F855A56C10ULL, 0x89B77CDBA22B0BFBULL, 0x56A9491CE67C6194ULL, 0xDDEF4ABA8B527240ULL, 
            0x1F56879DDF40D0BBULL, 0xC1D3724C9DCA505AULL, 0xADA04F792DAEC1D0ULL, 0xE574B91B050CB6B9ULL
        },
        {
            0xD98771188933F6A6ULL, 0x0B14758606942571ULL, 0x42F94A49A4AB7718ULL, 0xF345E26A4D15B14BULL, 
            0xBF34D4E2613AEC01ULL, 0x0E6AF8AC49ECB827ULL, 0xD0BA7C43A3933930ULL, 0xAE2F8755439AB4E0ULL, 
            0x14723DF4068BDEADULL, 0xF9D85AA9C95EC01BULL, 0xEFE82D6309823801ULL, 0x1603F01C584C62F7ULL, 
            0x5F3A5A43413F9A28ULL, 0x861508811172E7A9ULL, 0x8717DEDB7018EB6DULL, 0x9592BB718787AC7EULL, 
            0xF8E8469A543A21DFULL, 0x511961AA9BD73F07ULL, 0xF27BEDBA546AEFEEULL, 0x0DB84A1670A2A406ULL, 
            0xFA6A5FD8A7C34B18ULL, 0x66851554086CD7E6ULL, 0x213105DE66321C84ULL, 0xB20E6B08257635CDULL, 
            0x75475B6E728BC13DULL, 0xDC9560E15D946400ULL, 0x49AFAF02A7FEE108ULL, 0x5A1FF3B0DB117AE3ULL, 
            0xE7F633E937764266ULL, 0xA8E53EBBD8816660ULL, 0x9E4F7EE654450536ULL, 0xF69A85D06CB18EA7ULL
        },
        {
            0x90B68EDB53464373ULL, 0xB00993B7EE0CEE99ULL, 0x5A6A8D11B9D540DFULL, 0xF3099A6FF3C1E238ULL, 
            0x5ACE243236878CAEULL, 0x8205499002DB8158ULL, 0xC5B9149B0CE240C9ULL, 0x4D789FF1207B5235ULL, 
            0xF83B4E07D3E5F041ULL, 0xC33C5BBEEA58E79EULL, 0xAB282C1902756ED8ULL, 0x3917CB347D5DF12DULL, 
            0x158B1CFC015B9F14ULL, 0x6622D53A43DD6CEDULL, 0x671C8A53F26D0124ULL, 0xA37E4991449806C2ULL, 
            0x6F3B8EFA1540B37FULL, 0x15F833A466A73CF2ULL, 0x184A73E7A9556F11ULL, 0x7E9799D9F5234A0FULL, 
            0x549AD04AB7774D98ULL, 0xBD74777E4D200782ULL, 0x6BEAC848B1458635ULL, 0x812E46424385BAE5ULL, 
            0x8719D3F1B70F3B26ULL, 0x55DCFCFEB369ADDBULL, 0x4BDF911E789DEA6BULL, 0xCE238AA8A3D99095ULL, 
            0x348A56C55057F139ULL, 0x9FFE181C4C7866DFULL, 0x988C270A9DC25279ULL, 0xBD3133DB33121618ULL
        }
    },
    {
        {
            0xB2F05B7AB8687DA5ULL, 0xFB68BCAFCD7892A9ULL, 0x054EA3D1E9244243ULL, 0xDABA701EFFCC9373ULL, 
            0xE968C8893CD5937AULL, 0xB5AEAC7C57ACD677ULL, 0x27942152E442808DULL, 0x7AE6C74344EF12C3ULL, 
            0x5D85576916CDD57BULL, 0x132F5328FEBD73EAULL, 0x0ED1EA658108016EULL, 0x7B90F8319AB8127AULL, 
            0x06E227BF0C0DA6A7ULL, 0xCC111A31DF65E87FULL, 0xDEAAB1D638840EFEULL, 0x1A1A5342CAC659C0ULL, 
            0x282D3EA7BB07847AULL, 0x17E7C4D600D69D74ULL, 0x13C0BA92C1B63BA2ULL, 0xA4DFEE8D4E6DCC69ULL, 
            0xBFE825BA35EB8E40ULL, 0x4251B14A3CA775FFULL, 0xCE5449EBDFF76211ULL, 0x561C5615EF0657FDULL, 
            0xB8F6A0CCAE4515DEULL, 0x70C2E309FE7A2A87ULL, 0x9E70324C835E2B8FULL, 0xF73E8A7FDCDBBE06ULL, 
            0x90EC4067E54F7F02ULL, 0xD6E4287B425408EFULL, 0xD15CBABCAA70FBCDULL, 0x48652190EE0A9080ULL
        },
        {
            0xBF301E3AC6947496ULL, 0x2EA13F5B7269A1E2ULL, 0x2891DC5C06119BBDULL, 0x99CDAB7973464653ULL, 
            0x344635EE5739F242ULL, 0x7914EE090AB8C536ULL, 0x2AAC592ED6709DF1ULL, 0xDD0839217BDE69EFULL, 
            0x69EB64A68E98EF63ULL, 0xD34D153A63C609BFULL, 0x0C35C8D6EE99EB24ULL, 0xA42021AE98D0BD39ULL, 
            0xEF494E2DFF83F0D6ULL, 0x24B431B7CFB15FC1ULL, 0xFB46E456C442C82EULL, 0x43787E4705528BC6ULL, 
            0x3BF44525F2FF307DULL, 0x202D4D4ADF57BD4AULL, 0x617D5E546B950CB1ULL, 0x67FCC371A673F59BULL, 
            0x652C23EBA26A9F3DULL, 0x2A289A3B4CB18593ULL, 0x7A3200C8274B9971ULL, 0xF447D8993398D843ULL, 
            0xB8DC559D353868EFULL, 0xC3ABF3010C3F1B06ULL, 0xBDA9E4BD7058A64AULL, 0x4792273CF6AB9FFBULL, 
            0xAB1B4F8F677EBF72ULL, 0x9D071696B888E66DULL, 0xC30CBB114C46111CULL, 0x04715D23266EE7BEULL
        },
        {
            0xF44D216242C0DDBFULL, 0xA2618F1A3B38270BULL, 0x6D88C02FE60135CAULL, 0x7FF5668304E5B663ULL, 
            0x926E5FA2B28B5609ULL, 0x2692DEDDFDE62EFCULL, 0x8581D4FC580D5AC8ULL, 0x94938E43C5807D41ULL, 
            0x964495C3675141F5ULL, 0xD227B140A8720062ULL, 0xE5B6F6AE43E388ABULL, 0xB6FF019A23783F68ULL, 
            0x1441370E8485625FULL, 0x4B56E419135F0594ULL, 0x365401486350EF41ULL, 0x4904A32363C74E6DULL, 
            0xD840D93E7D7C4A57ULL, 0x3E2DBBCD6F961085ULL, 0x8CC6C767E7EDC449ULL, 0x691EF2A34EFFFF6CULL, 
            0x24820AA9B8F683F0ULL, 0xFD3D93023223BE8EULL, 0x9BFB4737A172B733ULL, 0x8055490B1A4E33E6ULL, 
            0xA8DA8E18D87B06FFULL, 0xA3E6B8559ABB3100ULL, 0x583E3EE8D1812952ULL, 0xDCBB3A27FFB717BBULL, 
            0x65B7881FD0781104ULL, 0x413184647707CD04ULL, 0xA70B919E50693286ULL, 0x30A11859435EE6EAULL
        },
        {
            0x799C87BE42FD60CFULL, 0x7D18DADB8004C366ULL, 0x12CF07F5FD8FBCC4ULL, 0xB018B26922503D3CULL, 
            0x053F987E0414559EULL, 0x873E6F06AE78344AULL, 0x77452A7F284F8473ULL, 0x1A3F9B58D23CF176ULL, 
            0xCC093F33E715A693ULL, 0x0F0D1A91994A5438ULL, 0xE5EFE89563131976ULL, 0x101D384F20188F93ULL, 
            0x5E8235A4ECAF560BULL, 0xE6AAA9D0144023EEULL, 0x2E01EB8F3F827317ULL, 0xE2DC086BCD9DB686ULL, 
            0x2FF39274D6D82128ULL, 0xEDC9E154F45F8FFEULL, 0x8A7E72A5634FA987ULL, 0xE5DAB41948AB9789ULL, 
            0xA2DCC59B54259F40ULL, 0x38DBE27C8AEDF7BCULL, 0x7264F7E13202EC55ULL, 0x1E086948673A61E8ULL, 
            0x15747DDFCA4CEAC3ULL, 0x610CB67340064AF9ULL, 0x2083217B6B7E65D7ULL, 0x7A52D8D384423015ULL, 
            0xB51F5385FAB6A1E7ULL, 0x2610518ACD6E804CULL, 0x10FE0294E25A9D8BULL, 0xF3EDC0073CBADB08ULL
        },
        {
            0x01DF32BA9CA27389ULL, 0x061686CEC7D9C135ULL, 0x810EE0A3718C28A1ULL, 0xFBC844A0537A17C0ULL, 
            0x3A12901EC6A1BAD6ULL, 0x7EF1F831B3E6A7CFULL, 0xC3442C1DEE081BACULL, 0x37EA501462B870CBULL, 
            0x3E7C626CE9E9F303ULL, 0xE4C0C748D7BC6165ULL, 0x75CA4F5A9B45A26FULL, 0xE806A214342F3E97ULL, 
            0x7858D87069A2678DULL, 0x7649A8EE53369839ULL, 0x7D83AE3FC3A86FB9ULL, 0x6F090500307853EFULL, 
            0x2B9676C87718BF41ULL, 0x5E48C57B6E56B4CBULL, 0xD12738E29378E662ULL, 0xBBB94F3577BFBFABULL, 
            0x64756DF2D0AECAEAULL, 0x72CA4C5BD057EDD7ULL, 0x3768D40B665EA484ULL, 0x73DD90EDFCC926E1ULL, 
            0xE4AFF6B9A7A2B263ULL, 0x21AA1F9B5C4FE188ULL, 0x4F886F11727F7909ULL, 0x7FC6080A266E8901ULL, 
            0xFB87997F9D985033ULL, 0xAEE1F071A372D538ULL, 0x03BED5FCC0B9C78FULL, 0x1B6471E63405460DULL
        },
        {
            0xFF595B23CB8051DCULL, 0x7BEE2F5727592D53ULL, 0x1FA81F55B6152B0DULL, 0xCF74B02CF4B78DBEULL, 
            0x2987B2EFABC41667ULL, 0xAA7C7DB32828A6D3ULL, 0x85032192EE4608E4ULL, 0x0CFF71B0149F9B0BULL, 
            0xACFB0F63C341BA3AULL, 0xE9714FE1F4891FA2ULL, 0x324C9BAE7CCE4F1BULL, 0x993FD0555FF2235CULL, 
            0x10F04DB3DA9B06E4ULL, 0xCEEF810879717A62ULL, 0x75349C0D7D931D31ULL, 0xBAC201C3A3696B98ULL, 
            0xA3B531A988D957BEULL, 0x9E6326720BDF60C7ULL, 0x7D446AFDEDC7903DULL, 0xE72DE6B2BAC78045ULL, 
            0x8AE3A891B5F67D19ULL, 0xEFE336A4D0999E17ULL, 0xD48723886FE3F906ULL, 0x751E7039616CDC17ULL, 
            0x55B7FFDA114B44A5ULL, 0x67CF2D9D80DB27E2ULL, 0x02343E39EEC0B214ULL, 0x414699BC89E7475CULL, 
            0xF1735A8BFF9E9627ULL, 0xAC1B61BAF774C778ULL, 0xB53FB9FA4432175FULL, 0x7B3E9559DA826C45ULL
        }
    },
    {
        {
            0xBFCB4F6DE243BDF9ULL, 0x0CE2409C0CD9DA18ULL, 0x84F305EFD69920D1ULL, 0xD335FF5D07D6E124ULL, 
            0x50241E0E09AB31C2ULL, 0x5B6FA71CECB1EE6DULL, 0xC794C3C8A8DC43C8ULL, 0x9DDCD2BFC1CA16ABULL, 
            0xED8CB7CC7A838400ULL, 0xBB7B2EC682C87C3FULL, 0xE46523F11B063C6BULL, 0x019A4261F586C211ULL, 
            0xA8491081A3CD3553ULL, 0xC444598204D83E06ULL, 0xBC483F512BE839F2ULL, 0x2C7295AE8B468AAFULL, 
            0x0919042C6E7B8018ULL, 0x6A3981D4ED8A5672ULL, 0xE7EE5ABA124D4B3DULL, 0xC175125BE89B3E4AULL, 
            0xC4418EA0A761F52CULL, 0xC2ABFC04DF26E101ULL, 0xB5832C1A8A92C02FULL, 0xEAF97770CEA8D828ULL, 
            0xD3B8FCFBD7993445ULL, 0x1C1A06025D3FF65CULL, 0x6263DEBA07A05F3BULL, 0x0C996EEB621F9A25ULL, 
            0x5CEABA1C1DE69830ULL, 0x586083BC7512BD8BULL, 0xC617844A4DCD365FULL, 0x981F091C0FCBF84DULL
        },
        {
            0x7576F1CB2FEDCA69ULL, 0xC196D16F238CECA2ULL, 0x94595EC37DF085CFULL, 0x0B26ECE160BB04E4ULL, 
            0x63CF9E5F14F0365DULL, 0x6CE2006638338D36ULL, 0x26704E5C2B242E83ULL, 0x0DB362B3884DBA0DULL, 
            0xD05F400FB2E70289ULL, 0xFB4E908930B81DAFULL, 0xF9239A7D0F8AB0E7ULL, 0xC336F060075BE7F5ULL, 
            0xD62A97FC707CE0F9ULL, 0x198763E6206C0F7CULL, 0xDFB7FC04246CF6CBULL, 0x4DDB1D9119557C49ULL, 
            0xB64E414C437542B5ULL, 0xDCDC91A077F8ACEEULL, 0x83FF0AE84276E191ULL, 0x6B9D95C740EA7236ULL, 
            0x217CB8197D0F66ACULL, 0x0B4F707128C5146FULL, 0x1D1EA83667F1221DULL, 0xAE6A50F2B99FAB14ULL, 
            0xFE2522E8297FCE60ULL, 0xFCC2CA510E7146B5ULL, 0x23BD9B4386C05FF6ULL, 0x2AF9A2D381C08792ULL, 
            0x0AAFDB54A24D6D0DULL, 0xFF419EB2AECC65CBULL, 0xFE1F2A500490B651ULL, 0x84FA30C4206719F1ULL
        },
        {
            0x8B8D0F1CEC7E7DDDULL, 0x3AFC87DB14149FE7ULL, 0xAAB074D80C2AF426ULL, 0x1205998EA675303FULL, 
            0x2D89358E80E2734FULL, 0xBA9EDA40EF64A5A9ULL, 0x749484581DE94AE9ULL, 0x918CD4288575E40CULL, 
            0x00401F8C268A65B2ULL, 0xDF60F9E34BF9C69DULL, 0xB1B1C03FE8F891DEULL, 0xA4E2D47203C50E19ULL, 
            0x64F02949566E2988ULL, 0x12D2ABA9C0D315A6ULL, 0xD2CEDFC683EAFF60ULL, 0x921FE5EBCDD03447ULL, 
            0x5EA79DD83C203329ULL, 0xEE5A9D1046D465BDULL, 0xA4DF214270269B6AULL, 0x9A00E8A978F560DBULL, 
            0x99D11AD5AB5019D3ULL, 0xF697280427044EFEULL, 0x4FEE21DED9F80BE3ULL, 0x8D05FFFC0BF06C56ULL, 
            0xC9B76DECA4CF20A5ULL, 0xBA2A83B9A48ABAB0ULL, 0xB1459432534BF10CULL, 0x4337D7F9C9EC2F62ULL, 
            0x0218B86E72DD7F7EULL, 0x1FEC31B11FFCC76FULL, 0x6FFD53A3A8F1B1C3ULL, 0xF876040082A34E01ULL
        },
        {
            0x7DA8AA4DB1FDC6B6ULL, 0xD6DF0C678691404BULL, 0xC19B08077CEF4188ULL, 0xDB93F4F402D3100BULL, 
            0x1D2FD437E5AD9EDAULL, 0x45D6AD3683F15FA2ULL, 0x8A91B86CE1E3AF4BULL, 0x7DA36A4A0C254382ULL, 
            0x8650820953D0D485ULL, 0xC8BF57CAE85FBD7FULL, 0x65336B9103A08CD0ULL, 0x76D8A2E4ABA2E570ULL, 
            0x63395FD50516E200ULL, 0x230676E146DF1C32ULL, 0x2F4C8E6AEFEA422EULL, 0x49804813133C976AULL, 
            0x48B5538BBFF9BD59ULL, 0x773A76BD59505489ULL, 0x0E21432012DA867DULL, 0x5F1249AA30868FC7ULL, 
            0xB2AABE519D5A8685ULL, 0x3672BCB10EC5F75CULL, 0xCD22C6648DC2774BULL, 0x33EA6F0B5BCEAF60ULL, 
            0xFF60D94A8B6563EDULL, 0xF562E4299B77E0B7ULL, 0x9B2779A2AF278FCDULL, 0x6EE6093D2FC5870FULL, 
            0x28661B8222F870CEULL, 0x6594BF3936821AF7ULL, 0x19AC3377A3D2E4F0ULL, 0xFD81A1301CB6987AULL
        },
        {
            0x1F1F46D217F6F1D8ULL, 0x3DC3E288EF08E1A0ULL, 0xB53389384A2D58B8ULL, 0x32DBEA2C06165728ULL, 
            0x475C185D0D6279CAULL, 0x44F5CE9A68E9F86BULL, 0xD326F7F4354F381BULL, 0xA85B9758BDEE8F89ULL, 
            0x9D15D43A25C50059ULL, 0x121A4B4C3BA0C6CDULL, 0xC4284EF7B03F08EAULL, 0x35ADAFF6C0610CAFULL, 
            0x753BE7549A648D96ULL, 0x7ECC8740207FBF9CULL, 0xB30CD83DDA14782CULL, 0xC870F85AAF8B0E59ULL, 
            0x16ACCA73E2B14B24ULL, 0xEEB6D4C02CBEAEA1ULL, 0x36A2CD0EBEB87157ULL, 0x1251BA7DF35B587DULL, 
            0x945BAED84D5E0D57ULL, 0x1226278F43894D48ULL, 0x6FE941A986AFAE81ULL, 0x3CA59EA4CD51730DULL, 
            0x87E360B672E49862ULL, 0x0CB4F9EE98E12369ULL, 0x7E000DF2D73CD081ULL, 0x3AF1525B796D32CFULL, 
            0x02C27582385EEE3AULL, 0xF6211847A0557CFDULL, 0x9F69F6075BB9B83FULL, 0x1A28DA42365FA1DFULL
        },
        {
            0x1CC301D2AD4FF953ULL, 0x5589E5EEEAB617DFULL, 0x8A2F2F33872DBF5BULL, 0xD790048EC7093843ULL, 
            0x2E4D88B7FDA7A35EULL, 0x4342ABA75CB1DEE7ULL, 0xED35B18FF772201AULL, 0x93FE35CF7495EA62ULL, 
            0xA1B0F92602A15A1AULL, 0x430043206DBAAF7FULL, 0x19DD5C3D568040FFULL, 0x62C7F1B9CD56C150ULL, 
            0xE8784349AD1DBFF8ULL, 0x4424F42D05EBB1C3ULL, 0xD6D091FB9A6720A3ULL, 0x311B6D3152393F33ULL, 
            0x5672FAC49D846550ULL, 0xFBF7FB7E78C21555ULL, 0xB9485F8C47CA3885ULL, 0x2C900D0081137B96ULL, 
            0x7156C6BE43C62F8BULL, 0xF445201F6EE38A54ULL, 0x4CC430335FEE7FD4ULL, 0xA0E7089239F965A5ULL, 
            0xB8E0BC077053EC6EULL, 0xA38A6CA121559C75ULL, 0x99DF79BFC6A5D360ULL, 0x9F54E83B933E37C7ULL, 
            0x971AE5CA2EE752CDULL, 0xC7A17B4B6A4C14E5ULL, 0x53C223BF2AC6A06EULL, 0x16467756CDAFF73CULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseBConstants = {
    0xFDCE04CB3FDB7C3AULL,
    0xEB29AB5280174FC9ULL,
    0xCE054C560356E211ULL,
    0xFDCE04CB3FDB7C3AULL,
    0xEB29AB5280174FC9ULL,
    0xCE054C560356E211ULL,
    0x04A1A4732F9387B6ULL,
    0x75887994DDCFCE72ULL,
    0xD7,
    0x20,
    0x5F,
    0x40,
    0x79,
    0x88,
    0xD0,
    0x1A
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseCSalts = {
    {
        {
            0x8EE23C81B6388220ULL, 0xC4B2B2C95B20625BULL, 0xC4EA404D6710B82BULL, 0x8B207C85D31BE1C2ULL, 
            0x0D7E0607A31C5EA6ULL, 0x5B55ECFF8F4B2545ULL, 0xC640BF7AEE2A8171ULL, 0x6BC8B57243D5E9C7ULL, 
            0xD34B93642CEF3366ULL, 0xC2259F9051A02C51ULL, 0x21BFBC016E007402ULL, 0xD5F1270E59817D6DULL, 
            0x470BF2011CF7DF32ULL, 0x312B65EE4EA31896ULL, 0xF576A346F03A4D18ULL, 0x2366A08C858EF86FULL, 
            0xEB69C7F0B556D3B2ULL, 0xC47D4716527DE60EULL, 0x748DDCB6FC0E1404ULL, 0x6053ED78A9015198ULL, 
            0xA54948BBC2682810ULL, 0xD761E54CC4827372ULL, 0xFF4B0F59D6D6E275ULL, 0xC65F8E0A35A82F51ULL, 
            0x25238170D3E3156AULL, 0xADB2EB996F7AF51CULL, 0xB34F0900BAB20B91ULL, 0x366C7D05FFA25DD0ULL, 
            0x99F5C618B711C2C6ULL, 0x1382157617CE5235ULL, 0xDC519468BC30CFAEULL, 0x134CAA265B1D4B61ULL
        },
        {
            0xD6CC050D929E7528ULL, 0xCBEACBAF158E2D4FULL, 0x8D9BA4A3C2035BEEULL, 0xFB6AB22C77945A4DULL, 
            0x7B6CF85696F56843ULL, 0x7D4675D1C20ED6E7ULL, 0xC0CAB5BF5FB534B1ULL, 0xB1FCADA470EE44FFULL, 
            0x4684334D2F3F49C3ULL, 0xB92471D77E2B235BULL, 0xC6CB1EEDBF78F959ULL, 0xD154A5D84DDF6295ULL, 
            0x1DF6C4B549F934F1ULL, 0xF7920806DA41F870ULL, 0x286A432789AE4975ULL, 0x85D22791D4CFE36FULL, 
            0x2CB92407BB74B349ULL, 0x7F9D9D43008BD347ULL, 0xF7FEC5328A12D5F7ULL, 0x2313CDA17961CDA2ULL, 
            0x7B8BAF83DFC61930ULL, 0xB18992FF48AC72EDULL, 0x6E8B63D52BE76678ULL, 0x346B19082C3A83DAULL, 
            0xDD8B99448EF952C7ULL, 0xF65167B0AE6C97F3ULL, 0xE7F2258D449EC13AULL, 0xB820C05F3011E692ULL, 
            0x45CA5284BFA30B0EULL, 0x3BE62AC7AEFB766DULL, 0x231D215F7C4C16BDULL, 0xD357418F99BEEC71ULL
        },
        {
            0x6239BB31984B3E8CULL, 0x27325E8A394A24A2ULL, 0x63687106EA5025C4ULL, 0xA46502102EC44CBBULL, 
            0xEC7D53F6BF0843F3ULL, 0xBA4EA3F457D44BB8ULL, 0xF1D870FCA51582C3ULL, 0xDE156F9488F88A42ULL, 
            0xD89FFAB922EE6D36ULL, 0x0F38D659760A0AFFULL, 0x3DEB52CC8CC0A2ABULL, 0xA632921538BDD773ULL, 
            0x0358DC7BB00AF49CULL, 0x499EA5A869E06250ULL, 0x5243859E5FFFDCAEULL, 0x1D0E3268C30AC1CBULL, 
            0xC74B30D5AC314F24ULL, 0x4836E68DE6C3FC98ULL, 0x6818CCB05C0C2C4CULL, 0x7452130999675B76ULL, 
            0xAAEB6840E6EA9B1FULL, 0x87D6629D301AB270ULL, 0x0F749C311AB2134EULL, 0x8B71799B0AD30B31ULL, 
            0x5AAD472F4CF8CA74ULL, 0xBA3B3D4F7737B03BULL, 0xCC68592934119BE9ULL, 0x8B90A6BAC9826573ULL, 
            0x2399BB51D9EA7FD8ULL, 0xB3A60BE2168DB7C5ULL, 0xC7B28FE49DBA6020ULL, 0xA97F22AD13AEFB36ULL
        },
        {
            0xB5851CF992872828ULL, 0xA348C8F1EB3FD0C2ULL, 0x0A7410E72369F6B5ULL, 0xF7F9987F805FCB2FULL, 
            0x32746E3E70D6D065ULL, 0x5DF0213028CAD353ULL, 0xF53D06E8C54698B3ULL, 0x685EC48FEDE1A0A1ULL, 
            0xDE9FCD5AE91A4069ULL, 0xA5DCFD475A8C0504ULL, 0x41FF6977058A6313ULL, 0xDFA9E085AA3B3BC8ULL, 
            0x900E4B11A99890B1ULL, 0xBA6D4BF20AC3F545ULL, 0x4FBB6C2E2700A85BULL, 0x849AB99279D062D2ULL, 
            0x776BE8D88A8FC142ULL, 0x5A83344D3F8231E4ULL, 0x5F1EDE858501F0EAULL, 0x7A44830054EDAC38ULL, 
            0xB117478FD25CE01BULL, 0xF1405F5793ACDF00ULL, 0x122BF9C9FA41CD6AULL, 0x3CE825D372446238ULL, 
            0xE6DCFE727CD7C082ULL, 0xC7C9A2FA86E1B9F4ULL, 0xE97BE89434CD6493ULL, 0x498DA6BB260553A5ULL, 
            0xFEF2D608D778596AULL, 0x1A4A888E3090A5B3ULL, 0xB34F03D16E86084DULL, 0x328ACA4F61F0A585ULL
        },
        {
            0x310C9F80721E188FULL, 0xB79923ADA7147F58ULL, 0xA6450EDC8CEC1B63ULL, 0xC1AC072C26315CDFULL, 
            0x239750483796971AULL, 0x6BC22C3E97832632ULL, 0x54C28946E06A821BULL, 0xD3BAED20C04E074FULL, 
            0x79CF1193B07F91FFULL, 0x4930B8455401C7CCULL, 0x8EDDDC4ADC526E5EULL, 0xC01B0F521E83E5C8ULL, 
            0xE8068BC8A8E0854DULL, 0xE968D0F17C4CB292ULL, 0x910653BF7D817BEDULL, 0x9FFE9C403C53264DULL, 
            0xC87D8FA64C422613ULL, 0xE49631D8FE6D462DULL, 0x7058EA3A4E13EFFCULL, 0x30FBDEFCC3043C83ULL, 
            0x6D156045DE1C2503ULL, 0x36DD1A6C0F393E86ULL, 0x7A8B9332246079E8ULL, 0xB5FBFD014B9F5AA8ULL, 
            0x869A08B79A975E01ULL, 0x322C7724FA0BE444ULL, 0x4975D2F3A268A76EULL, 0x36515E378FD22EDFULL, 
            0x820AE1A8600A9572ULL, 0x62F0E797F733B3E0ULL, 0x9A63C9AA961C9E51ULL, 0xB62F59759903F2F0ULL
        },
        {
            0xCE3E54B506F4A753ULL, 0xFBC584042CFEBDF5ULL, 0xA30022AABA29B3E5ULL, 0xDD30203628DF8D16ULL, 
            0x07ABDEFBBA901CB2ULL, 0x58F36E2D6DCE0ABDULL, 0x1E0A880F504C9581ULL, 0x7198180492081F08ULL, 
            0x1A95F834890183EAULL, 0xAB649B91DC302473ULL, 0xE8EBD0D23CA0F7D9ULL, 0x1D2C97E854759D83ULL, 
            0x7414B29387BAD97EULL, 0x3C05D0B3761565FFULL, 0x62E0CDEE6649046BULL, 0x3BC0577522F5C72CULL, 
            0xA60114F2B8807A59ULL, 0xAA58108B1BA9C4F3ULL, 0xD06573FBB4850A55ULL, 0x5A13E16689810E20ULL, 
            0x6497C47C843AC664ULL, 0x3F5B04A0483E599AULL, 0xFEB8B466A36896DAULL, 0x8D7706075BF2CA2EULL, 
            0xACD3CAD567C342A7ULL, 0x796BB81C3C0F1D03ULL, 0x0FCD98B6F487788BULL, 0xC9C34F5099A436B6ULL, 
            0x5BBDF72C359B4645ULL, 0xCEAD2C6EBEC94440ULL, 0xE55431D25B10706AULL, 0xE1736AD1C1D42B4BULL
        }
    },
    {
        {
            0xEDBD4D8654F06199ULL, 0x080206FEC980C625ULL, 0xEE5864066C66A443ULL, 0x8DD2234B9C100B16ULL, 
            0xDA907E8C6BB00F2CULL, 0x65EB9164EE8AE995ULL, 0x9D1CC64A54AD1241ULL, 0x5B5A4C7DA1E47979ULL, 
            0xAA9B833B1D0CAEE4ULL, 0x38CD1AEA36F318E2ULL, 0x20BC5082E0EEB98CULL, 0x209D8E7730C38861ULL, 
            0xC7AF676DD92F44D2ULL, 0x561E9935D9F72A8FULL, 0xA1AD9D54A6E8D1D1ULL, 0x2C0425B1F9A32A3AULL, 
            0x93DEE13EA0522920ULL, 0x870B36F4910FF1CFULL, 0x6F6E779325DEA9A5ULL, 0x8E605F2A9C7B54FAULL, 
            0x4CE60DF4FF62D252ULL, 0x7983CD2A8FB65EB0ULL, 0x089E68E0848F90D9ULL, 0x48B048D82123B8B3ULL, 
            0xC20021512FE7A63BULL, 0xF227B43834BE8E2BULL, 0x0CC2DECE28C941A6ULL, 0xC2A7AEA79E85032DULL, 
            0xA566323E79223795ULL, 0xC46D5A657E721A97ULL, 0x2CD4D1F5B81E9103ULL, 0x2C3F2445484FF238ULL
        },
        {
            0x869E015722481677ULL, 0xB09D7A22A7DC3F69ULL, 0x01D57145AACC372EULL, 0x637EDD9F663CA1F7ULL, 
            0xA906022F046A4C0FULL, 0x951548FCEFC3AEBAULL, 0xE977B0072DC24A67ULL, 0x5590EA54A4EADC9EULL, 
            0xB6EB4F4777C5D216ULL, 0xABF360DB71C30B8DULL, 0xBB1033CBCE14CB1FULL, 0xACF50D44F2EDBC31ULL, 
            0xCE1EF4D1A2FBB19DULL, 0x9B84587F310F7B29ULL, 0xBE05249594F4DA44ULL, 0x8827600B47F767BAULL, 
            0xDD236FCE0AA45F73ULL, 0x98E7269A1966C462ULL, 0x1397EBC90DDDA244ULL, 0xCC3E688E5F44F953ULL, 
            0x671A9E65224A4762ULL, 0x2209B2B9AC78242BULL, 0xFE477D37A42B25E2ULL, 0x3A8B669D62422DFBULL, 
            0xB72334EA28525ECDULL, 0xF9D9099F2C6E795EULL, 0x48CB8630DCAF84A0ULL, 0xA36A9AD4B1C9EE8DULL, 
            0x424684809B6EF4BCULL, 0x7D1FB4D41F42DC0FULL, 0xDD186BAF10CAED68ULL, 0xF57DC3883434A5C7ULL
        },
        {
            0x92295AE1DB43DC4AULL, 0x9DB66D3A79D4B7A3ULL, 0xEAF765B087F33142ULL, 0x6C2DE4DA5204AC08ULL, 
            0x51CC1A4B084AB676ULL, 0x765112B51B5CC007ULL, 0x8867F7D3D0A512D4ULL, 0x7E2BEF2AB1F67281ULL, 
            0x7E48D2D009291DB0ULL, 0xFDDDC0901577AFC2ULL, 0x4107CF9CBC3B622CULL, 0x2CB9D5018B6D6419ULL, 
            0x93670F6979A232ACULL, 0x59362868B21A3594ULL, 0xB009A1F6999A5486ULL, 0x5C8481042A8BA518ULL, 
            0xC033EEC1F8D439CDULL, 0x773F4D630168AF51ULL, 0x2B74459FC0A02617ULL, 0x02D69CE942314812ULL, 
            0x8E3D7CD99120284CULL, 0x785E02BE8E7AF8B7ULL, 0x67CD20895492A83DULL, 0x8C3195CCE457FBC5ULL, 
            0x6E1F63E5B96B87FEULL, 0x98CF11DF0914AC0AULL, 0xC3BF57073F232263ULL, 0x5EFEE5B7CE86BE2FULL, 
            0xF6F967988C698DE6ULL, 0x8C4284F79502707BULL, 0xEF40201F5C98678CULL, 0xD173908314DE8AAFULL
        },
        {
            0xB6C8FCD79366217CULL, 0xCC8E9EE8008E8959ULL, 0x0F5CB1E499A3F3BBULL, 0x6ACEFFB80E9E4FADULL, 
            0xCBEFA64FD718A8F4ULL, 0x07CABDF36BD630FDULL, 0x48285AEB16BD63FFULL, 0x3EC54EB608BEA868ULL, 
            0x147BB2FDF43B9744ULL, 0x42BDCAD9FD682E09ULL, 0x582BA3C8BE1D1EC1ULL, 0xDA60743EBFA5D6B8ULL, 
            0xBDCAE16ED06126A5ULL, 0xFCDFFD98FB4E4BCBULL, 0xCB82F263249EF492ULL, 0x5AD4AEA9BF9ED194ULL, 
            0xFF45853CE0109554ULL, 0x6FA55FB20E1CA1F3ULL, 0xA390F0AA8A46ABE7ULL, 0x03133FA57EA5229EULL, 
            0xE72B3BF51F68BA1CULL, 0xAFD763332900B820ULL, 0x112C17BAB48EAEC4ULL, 0x4B412F81A0F0EC03ULL, 
            0x1E8E6DD8CD812D81ULL, 0xA34C93D72C092C93ULL, 0x81EFD878461A6E7DULL, 0x81A20BE3F4D2FEDDULL, 
            0xD2051DB8E3A83DB6ULL, 0x81CCF42C97A26060ULL, 0xAD4157E181025481ULL, 0x8A405B53CA34B249ULL
        },
        {
            0x4D43743DF1BC6882ULL, 0x52DABFC5DEA2B94EULL, 0x4493AFB6556C7FA3ULL, 0x7615B5F7929A207EULL, 
            0xBF1724EE6FD895C2ULL, 0xF7AE78A0A8E8237FULL, 0xBBDCCFDA54522D76ULL, 0x8067142A625A55E6ULL, 
            0xFFEE04FC03614C5FULL, 0x7944BE674C53AF54ULL, 0x2AFB8A4F756DC6B8ULL, 0x668E1C19BA67DCA6ULL, 
            0xF687B41A280110B8ULL, 0x58EF04DD028BFC7DULL, 0xB4EF9A00D3BA3F29ULL, 0x72F87AD6B1F0F016ULL, 
            0x72383A84F5173BA1ULL, 0x11A84596A3B96860ULL, 0xBD8E29A7F78B836BULL, 0x175D6F101396895CULL, 
            0x60F27346BF23CE91ULL, 0x2712C9C3922CC431ULL, 0x6F26F1C162074DA8ULL, 0x3A76A226EC934BC2ULL, 
            0x7F0F6BDA92354486ULL, 0x254786112B582EA7ULL, 0x88D529C68709426CULL, 0x5C7E195F47B466DDULL, 
            0x5F0D0F9A386109B5ULL, 0x63F3B5DCD599A26AULL, 0x1429C1816B12BF52ULL, 0x8A8790A8A7B4965DULL
        },
        {
            0xB672CAFF7E60D649ULL, 0x1778B3DA6251A373ULL, 0xC5CC135C526EC5D6ULL, 0x8904149ED0D95244ULL, 
            0x58725FF22FF045D6ULL, 0xA7F7F2168F69A1CCULL, 0x9F449DFE5E08FC61ULL, 0x9EC122459C7AE6D6ULL, 
            0xCC1FCBE45BFD9C85ULL, 0xAA28C3AAB46D3BB0ULL, 0xC06F5125631BED4DULL, 0x0E6D09A3FB2A4205ULL, 
            0xCE9CB861FA12F97FULL, 0x5C4A2289E282052BULL, 0xB595BF1003F4797AULL, 0xD028147ADC099EDDULL, 
            0x40A3B184167212F2ULL, 0x352C3BEE75094F72ULL, 0x294D5F676886FB79ULL, 0x0311DFA37E84C02BULL, 
            0xB89CD7ADD30DAD1CULL, 0x1258C5AC41DABDFEULL, 0xDD1AE85610BA78BDULL, 0x2586EBB5886BEF9CULL, 
            0xF9AC3B0A5180BB9CULL, 0x4AA95EF4E9C97D60ULL, 0xEE89E7A6F9307A7AULL, 0x8608E3B39DAF77ABULL, 
            0x1BB11DE7012CE308ULL, 0x387BA39C42870964ULL, 0x464542BF3A37C019ULL, 0xDC0B06252124E290ULL
        }
    },
    {
        {
            0xBD062FA7BEC36479ULL, 0x6482353C58C87984ULL, 0xB7C783610D5732AAULL, 0xD01B546544E380DFULL, 
            0x181A58841B1BE263ULL, 0xF0CD9FFF93B03422ULL, 0x00B57511DAA30F54ULL, 0x9F5BD4A934177638ULL, 
            0x011957A7A84EF5C1ULL, 0x8AB743BB181F8835ULL, 0x12C22962C8A2E82FULL, 0x462A84F7C0E05173ULL, 
            0xFA21525F0A8C3929ULL, 0x669E5810F88E4850ULL, 0xB6A7F2825EDC86A4ULL, 0x63340381DE6786F8ULL, 
            0x8B2915CA99A18A28ULL, 0xD96CE663CBA70662ULL, 0x38FC9A49A620514FULL, 0x485A81F4D3E1A372ULL, 
            0xB5251182EEB99175ULL, 0xEFEDE52C2CC57B40ULL, 0xDD8BF4CBE8A6C621ULL, 0x2217ECD62803E4CCULL, 
            0x8FBABE7F0E9AEA6BULL, 0xA5B4B3190ADF08D7ULL, 0xD6CB4C2AD9990EFBULL, 0x5CC4A9F3A18818F3ULL, 
            0x799C0B9763D0FE55ULL, 0x5301945F15740AE8ULL, 0x3BF955AE1DA2E11CULL, 0x461F35C782F40636ULL
        },
        {
            0xD826E54590C8F5FDULL, 0x1FE0677BB38C37AAULL, 0xEB9B2F5296707606ULL, 0x55F1EF41791FD382ULL, 
            0x4A0BA24DF59FD9D7ULL, 0xC9BE2013FCC4431BULL, 0xF0EC4F9566D4ACD1ULL, 0xB92CBFA743E0C2B8ULL, 
            0x2A33909DCA4A3B58ULL, 0x01AD7B619C7583A0ULL, 0xEBD3A6CF0C256E94ULL, 0x67170FDE3E3083A6ULL, 
            0x0AB9A917732D74C1ULL, 0x75CD97EFBBC44DCEULL, 0x1DBBA869BA1F474EULL, 0x01384E97389CC3E5ULL, 
            0x6DD932EA22348811ULL, 0xC5DA4DC5CB7C2860ULL, 0x36E7FB8A573AE536ULL, 0x305CFB6BEC4AF7E2ULL, 
            0x79541E03E58FD981ULL, 0x4624CDE1D84FF2B9ULL, 0x057D46F2477DF371ULL, 0x13F83AC074163298ULL, 
            0xE8EE5D40D992B4DCULL, 0x9589034DDAA6AA65ULL, 0xB9F56601A8DE159DULL, 0x3053F716C9FC868FULL, 
            0x0B03FF8CD4E80C0AULL, 0xA32C1614A2069E78ULL, 0xF315C8F1C222BAECULL, 0x035E7D5CEB92ECDAULL
        },
        {
            0x7695FD179BAD4220ULL, 0x89BBFF7E56EEDA28ULL, 0x7BB62F51CFDD7EC2ULL, 0x3514774DEA0CE6A2ULL, 
            0x6F60AA4CDA43C5FDULL, 0xE374E9E6B555866DULL, 0xFA0A473D6476DB46ULL, 0x065F0DF221759996ULL, 
            0x0A4089786038F3A4ULL, 0x6E9AA28C95552BFFULL, 0xF0C4E03C2D7743C6ULL, 0xDB2003A68BE5D937ULL, 
            0x174AED0A54AB6FB0ULL, 0xE5B0663748842D8BULL, 0xBC873E37504C36A6ULL, 0x8919D7C4151E71D8ULL, 
            0x95490E2287438C43ULL, 0x53E54341558717FDULL, 0xC0889BD819628D77ULL, 0xA6958405A8349E9FULL, 
            0xA4ACDDF7E4C3C64DULL, 0x93F95C59A97E4B93ULL, 0x8392B6633C3458E9ULL, 0xB55737C3C7AC4214ULL, 
            0xC4F3BFAE1036812CULL, 0x758779A50787B184ULL, 0x6CACB2B80D32F265ULL, 0x65EEE595B69DD649ULL, 
            0x23F523CCBB938A47ULL, 0x058AB406196DC15BULL, 0x3488E33BE21AC4F5ULL, 0x3C67E3E1FB917942ULL
        },
        {
            0x3027571BA7DF94CBULL, 0x8C429824437C38FBULL, 0x7ED5F2C0C10D17FDULL, 0x24FDCCCA759B9F98ULL, 
            0x0513BE07390F2846ULL, 0xB98000ED2A5AF03BULL, 0x9B73982F0A7C84BCULL, 0x3C9C162EFB87848AULL, 
            0x738FDD68005EDF6CULL, 0xF98B716D0239C5E2ULL, 0x974AF600BDC18914ULL, 0x1A3218CB745DC3CDULL, 
            0x51F5471890939CF2ULL, 0xDB5673509895BFC1ULL, 0xF4D6044E065BC252ULL, 0x15DBE23835DD8876ULL, 
            0x315D02DBAA0B600AULL, 0xE33615E54E9563E1ULL, 0x63F5DC0F1C970C4DULL, 0xCE6C3963A50BC4F6ULL, 
            0x4D6B2C9B4E377A2BULL, 0x43649266477A868BULL, 0x851F34A1AD6DBA33ULL, 0x0533D255D1BE4CA0ULL, 
            0xB3590C7248971C6CULL, 0x233274C06989E26FULL, 0xA3E6BBE550A7D60AULL, 0x85A0DE846C89AE68ULL, 
            0x032361DA8D2C8D64ULL, 0x78A937F9C4D1FF00ULL, 0x67C7936FD528EF25ULL, 0xA7EFFD87A99F5107ULL
        },
        {
            0xC82382E3346369C9ULL, 0x1915F1DCDD4A9B20ULL, 0x06BE130DB97AF751ULL, 0x12EE95599E03AC81ULL, 
            0xBB6861634D24B295ULL, 0x8C813246FB48F3A1ULL, 0x8AB2139941A06733ULL, 0x2C3B6715A76391E1ULL, 
            0x11EFF35DBC0E1D9DULL, 0x1BED64B80AF5D999ULL, 0x62D6FA795848F7D7ULL, 0x06CAD45D8DB510F5ULL, 
            0x46A77199CA34B545ULL, 0xBE0DB83D579386C8ULL, 0x77B8084D86D4769EULL, 0x4F9F70940B493AB3ULL, 
            0x2A8EC1E30F918F96ULL, 0x1F4AC827A47416CAULL, 0x5387A25F54B49558ULL, 0x5C682F001B578D22ULL, 
            0x7907F83282FAA002ULL, 0x8233256D40E56CFFULL, 0xC9C16C8D609F7629ULL, 0x1F09C79188993008ULL, 
            0x51D36D762EFD69BCULL, 0x083F17F647678062ULL, 0x5C4E47C62AAFF4E4ULL, 0xE1DBA7D651420EB8ULL, 
            0xCFAFE7B997116582ULL, 0x882299A57A583626ULL, 0xF17356CBC151CF41ULL, 0x906CD5F06457224EULL
        },
        {
            0x1850A94E407E17F9ULL, 0x0AFDE40C5E25CD8FULL, 0x339E46B9DD4A85B0ULL, 0x49D5C171C69141D6ULL, 
            0x6DAEC79B6A45F5C7ULL, 0x33AC13053CB93829ULL, 0x87EEED8F7B99D549ULL, 0x14AB62B5FF825D47ULL, 
            0x1CA18906952544FCULL, 0x698A811D7FBD7901ULL, 0x03F6CB405E77E7C0ULL, 0x199A936ED2D5969DULL, 
            0x4D2D3BB46314A675ULL, 0x6D3FEF61E221238AULL, 0x9AB47A15846CA161ULL, 0xD7F07B6807A0F15BULL, 
            0xC77AAA660C6327ECULL, 0x34DC4A829C596BC4ULL, 0xB756E3F370B19ADFULL, 0x8E50554AE0944978ULL, 
            0xD6B68C66CD2852BFULL, 0xCE34EEF94B0032F3ULL, 0xC056EE4520DAF934ULL, 0xE87AA9884A86FA56ULL, 
            0xF139903EDE1461A8ULL, 0x3D2FF98235EBF64BULL, 0x697C39659A3BAB05ULL, 0x959A9E5DE5037802ULL, 
            0xDE2A9A66EA8DEED3ULL, 0xDFD17395F0915DDAULL, 0x559B0B2BA1262A75ULL, 0x2E3A7197D9A0ABCEULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseCConstants = {
    0x338B15C58C880EE3ULL,
    0xE953E3F47D7FA9A1ULL,
    0x1F20E90722A72544ULL,
    0x338B15C58C880EE3ULL,
    0xE953E3F47D7FA9A1ULL,
    0x1F20E90722A72544ULL,
    0x5AF30657F3758E96ULL,
    0x60AAA3F8BB1BA8E4ULL,
    0x49,
    0x30,
    0x5B,
    0x1C,
    0x96,
    0x7E,
    0x62,
    0xA6
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseDSalts = {
    {
        {
            0xC8062B4938C44C14ULL, 0xECEA2D8E1C402072ULL, 0xB56385306A7735F6ULL, 0x074BAA8AF62BE8D5ULL, 
            0x48D780724E12DFC6ULL, 0xA96548B8C34CD4A6ULL, 0xB0297E45EE5170A7ULL, 0x5D79722BEF6C20D3ULL, 
            0x7697BD9D8D7A4F2AULL, 0xC8BC321E3E5DD6E8ULL, 0x0DAF9940202217A5ULL, 0x71324406454B380BULL, 
            0x7B9FA90B504B2056ULL, 0x108D3131CDBD2815ULL, 0x7F91392FBBD7C3EEULL, 0xD010CA329EC13AD2ULL, 
            0x43712A0C30B5C3BEULL, 0xB8F7BC9085834BECULL, 0x07D411ABE5EF1381ULL, 0x54A64D2B05E40B25ULL, 
            0xFF397A2A7D9FAF0FULL, 0x5208B83FB2831C1EULL, 0xD7526DFC8F68E34EULL, 0x05A9453D07D67A60ULL, 
            0x0B6D121429DBAD7EULL, 0xE368E83C93094EE9ULL, 0x9730176CCCD7E97DULL, 0x15DA05CC8FE7F1BAULL, 
            0xD098811561A7E181ULL, 0x2B388395213ABD9EULL, 0x9FDD5C3B4CFB6312ULL, 0x108E7172FF44F7E7ULL
        },
        {
            0x65C4569C0A25A054ULL, 0xDCEBB194B5A7ABEAULL, 0xEFACF0242207A5D7ULL, 0x6AED5C467E6B5A9EULL, 
            0x4B4D37A4A461965CULL, 0x93E73479ADCF222FULL, 0x9A4CA2BAFE6E9F62ULL, 0x4E3D02F06006F46BULL, 
            0x18B5E70AC9D4F01DULL, 0x68F0B546F12F054FULL, 0x4324AAFF89C34269ULL, 0x49FF43C8896D759BULL, 
            0xEEF62E425530D9DCULL, 0x7BE96BC70BE7B306ULL, 0x9D571036A488FBA2ULL, 0x512987174B13350EULL, 
            0xE581A6F18178D318ULL, 0x5ACEB8CE4E1EF6BBULL, 0xC64FE492B6E5B71CULL, 0x8CE7F60112968C4AULL, 
            0x6D3D7038058BFF7AULL, 0xD43C034DBA68482CULL, 0xF15FA58C5AFB9FA8ULL, 0x0D5738EE5D175557ULL, 
            0xC5B6720E9E38EA00ULL, 0xDECACF878C5DC76CULL, 0xBDE5577BD36554E4ULL, 0xA378ADEA2A22CB8FULL, 
            0x9E5370DC2F3213DCULL, 0x6F6991ABFF76F667ULL, 0x285B0C2423AF5B66ULL, 0xD87A4112C322DE81ULL
        },
        {
            0x79E666BBB8E4727EULL, 0xFB03A3D496765927ULL, 0xCEB625783D127271ULL, 0xD2EDC9A0B0051702ULL, 
            0xD399EAE457F3BABFULL, 0x9B97FF125FD69298ULL, 0xD6DD8B597286EEB6ULL, 0x117621B318049372ULL, 
            0xC0F74B15252B5B14ULL, 0xDA5E58241B39F43FULL, 0xCCA2E2DE16D995E4ULL, 0x445838BEF50205AFULL, 
            0xC842FA2047ACDBE2ULL, 0x0039378B011032F1ULL, 0x302B4493E12C50E8ULL, 0x7FE06DCD5D8021AFULL, 
            0x1EBFEEE3EAF6B39BULL, 0x12D401CF982D8853ULL, 0xA733A423BABB05C5ULL, 0x08771F626AE57D97ULL, 
            0xCC32275E2FE8C653ULL, 0xB0F82B74C987091AULL, 0x5A8EBCB19BAEC018ULL, 0x688F1025FA5C547EULL, 
            0x0AD3B2BA2C3F572FULL, 0xC663E0BC8E58679CULL, 0x38C5084DBC469122ULL, 0xFBC495F12DCBE1E9ULL, 
            0x7D4B6901CB5CDEB3ULL, 0xE8541F7B1D3B4085ULL, 0xF3C7F5E7AC1ABC5AULL, 0x9DEF99BAEEB60D8BULL
        },
        {
            0x1C94A475F398F48BULL, 0xEEDD6A926A557FEAULL, 0xB13A6FC05B56993AULL, 0x76BD57DDD99D1E1FULL, 
            0x5BA9F84AD42299D3ULL, 0x41975FBDB44E8788ULL, 0x31430FB66DF717C3ULL, 0x657C6AA4B452D2B1ULL, 
            0x13F3A4B6BA48F438ULL, 0x556D85BFBBFA70F7ULL, 0x2CB1CCF93BB40A8AULL, 0x76F1223FA932E65DULL, 
            0xE866ACB88661B30CULL, 0xE0171A72C9E99459ULL, 0x948F005EC17A7225ULL, 0xCF9FC137E28E33D7ULL, 
            0x4B3D91F108116870ULL, 0x731967DE10ECF38FULL, 0x7E7EC40F8E0D4209ULL, 0x2ED48A15FA220045ULL, 
            0x8F5EDF16C8677770ULL, 0xD02DCFA9019A32EFULL, 0x867DFC22375DB5E8ULL, 0x7209D94EFD7C8799ULL, 
            0x10EACD09E5FCAC90ULL, 0xF0BBA1709B2884B0ULL, 0xE484980F1D5A1BC4ULL, 0xC4D955EDCC301461ULL, 
            0x95FE09B3A6712CFEULL, 0xEA2FD169479AB887ULL, 0x54C53DF7204FDFE0ULL, 0x7D9E66B96645828EULL
        },
        {
            0x69349F5708308C56ULL, 0xB4E68A3D19B93E31ULL, 0x02B28B86243A93C4ULL, 0x9D771ADE5768D2B8ULL, 
            0x5B69A814AACCD9DCULL, 0x8B185FBB45EFC1FAULL, 0x3C8B008CB5C75CDCULL, 0x6D4A38D05437DE37ULL, 
            0x9F66AA70A6AFE3D7ULL, 0x13622DE8319280E6ULL, 0xAB7F40277B28B33CULL, 0xD6BB05034ED927BCULL, 
            0xD9F4719D504DACCCULL, 0x046C598DB8D75DD7ULL, 0xD364AD715B95E9B7ULL, 0x03ABFD0706A3A55EULL, 
            0x1787CEC524BE722BULL, 0x22D8E8584A164232ULL, 0x852146A3F265BBFEULL, 0x178070BBB77BBB62ULL, 
            0x76C75939AAA3C3CDULL, 0xB9900974B7BC07F6ULL, 0xCBEBE5907E98DC7BULL, 0xA6178CE35059D4C2ULL, 
            0x33CA8B56A1D9DF02ULL, 0x8704C10DDDEA8E52ULL, 0x5C4EF3964872316CULL, 0x67E05679DD68BA41ULL, 
            0xA023BC40F2DF072AULL, 0x090D861E2E26A4DCULL, 0xF81E806DF24CF6F7ULL, 0xC9BA3347C0254CC4ULL
        },
        {
            0x25FF94E884459FFAULL, 0xD49C409D895FB824ULL, 0xD882F3F2FD150B7DULL, 0x4F96314F6B858287ULL, 
            0x80767C07210FED43ULL, 0xF9E8004B8D8C4291ULL, 0x431C00A1A449A27CULL, 0xFEA8DD6FEA53A1ADULL, 
            0x92385E3137E243FFULL, 0xDFF69E3F33BBF712ULL, 0x07A6A2CAC77557DCULL, 0x4F87052733C2EA80ULL, 
            0x19E9E44FFA94F165ULL, 0xE88D2CAAE023B717ULL, 0xD9CBCD8BCF9186B4ULL, 0x18D764DF125F04E2ULL, 
            0xC36B7A935597DB2CULL, 0xD8EEFB5B01FC68ADULL, 0x4C3E4965C3A4DCAFULL, 0x152752ABD4CD467CULL, 
            0x0391A56BDA89CB42ULL, 0x2A03FFCC021BB0A4ULL, 0x5B82062612181B42ULL, 0x32024820EE2F4669ULL, 
            0x1DE0D6EBB17417C6ULL, 0xA800EC11C2384E7EULL, 0xB52725248C074224ULL, 0xA3FE7A9250F3E5E0ULL, 
            0x7E7CF7244C8C91E4ULL, 0xCC3EA363BA9C0628ULL, 0x79F11B88736F5D04ULL, 0x4AEDAFA60F49DBCBULL
        }
    },
    {
        {
            0xBD7013A2D3B4DD8DULL, 0xE4A213C1CA77554CULL, 0x17335FCDA9FACB9AULL, 0xC79668082AEE7FA7ULL, 
            0x71A543DEC150B02DULL, 0x1F08C26290A14734ULL, 0x364889039EDB05C3ULL, 0x2A4CA4512E5FC213ULL, 
            0x80095C80AB925086ULL, 0x395A4E8878D15CEFULL, 0x7AE4A4917762BED5ULL, 0x2268E432CDDD4A1FULL, 
            0xDC12CFED6C4C0202ULL, 0xA5CD825FB1EC4BC0ULL, 0x75A6F770442C7E44ULL, 0x1E151A8983462264ULL, 
            0xA80B42FA9539F2BFULL, 0x05B37ED99516E258ULL, 0x168DB6EF29EAD769ULL, 0xF4EF8D579750A3BFULL, 
            0x66678C8F2FFCF816ULL, 0xEBD592D284973F1DULL, 0x620E3C8E87062E15ULL, 0xFEF74053CEAB1823ULL, 
            0x8DA8A188829DEB0DULL, 0x931965D171437D88ULL, 0xA87BADC4CB9A5B27ULL, 0xD19F40D17AD33E46ULL, 
            0xF10B082CFEB0CC72ULL, 0x9037C2976FBF7709ULL, 0xCC0757AD5B01AF87ULL, 0xC7F1154E10A20A72ULL
        },
        {
            0x55AC8BAABCAF3429ULL, 0x75EA34296A11B92EULL, 0x0BE9950A50B2504BULL, 0x694D7961E3533115ULL, 
            0x4DA1E663F25CC913ULL, 0xD5B65FA96C88BB66ULL, 0x573A95D1C0E4C024ULL, 0xDD1EEA3AD211CAD5ULL, 
            0x271EB3CF7F550D92ULL, 0xFBB400EB0D7FF88FULL, 0x9409AE24DB2A13DDULL, 0x94CE87615613A398ULL, 
            0xFE25B05520EF496CULL, 0x367E3EB9B06FECFDULL, 0xAA222A6E8D0FE24CULL, 0x96B0F1C5DFCC4981ULL, 
            0xAB0CA8C3891A53CEULL, 0x9A2CBC0A24586AA3ULL, 0x96BE2B0E206ABE8FULL, 0xA8A773EB8352B243ULL, 
            0xBE6F453EFE443D9AULL, 0xB480981EE50E1D57ULL, 0xAE5962ADF30FC2BBULL, 0x07B13E4FF9B6F9DAULL, 
            0xEE2FF61147F8B727ULL, 0x0504AAE87AB8C9DFULL, 0x7B1BC20176510388ULL, 0xD9D951703E6CCC10ULL, 
            0x9D64AD136A6D2293ULL, 0x9E8B9CF75F50D769ULL, 0xA909C7E9E0CDDA6CULL, 0x8C41043F035A6003ULL
        },
        {
            0x6467B2AB289DC89CULL, 0x07724303E91DE780ULL, 0x1AC1F5FD91513763ULL, 0x40921A484444DCEBULL, 
            0xB00672C452E58C8AULL, 0xC9873386921DFA8EULL, 0x905BF33F32E9C032ULL, 0x55743578D8B0296EULL, 
            0x13D9EDF368A1F746ULL, 0x3E9717C6F18421FEULL, 0x050E43A50CB387D3ULL, 0x9B40AC1617FEAA7FULL, 
            0x51E8779B3190B0AFULL, 0x695A9A207F9F35E1ULL, 0x25D7B5C6231F5E71ULL, 0x63D7CAD3E07C75FEULL, 
            0x9585084609ECC9DAULL, 0x7A1B99698DA7ACAAULL, 0xFF11406CE771CBC6ULL, 0x3251B6D9A4B8CD2AULL, 
            0x1B3C49F817C30E44ULL, 0x7767B83C0A43AF47ULL, 0x30ADF8B733E336B4ULL, 0xE90C7DEC88AC5FB9ULL, 
            0xD6E445C6DFDEA943ULL, 0xCCD95695FDC75C72ULL, 0x58312AA55E071E7FULL, 0xDF5F27B0A6A3B76FULL, 
            0x722CE1550E598C77ULL, 0xF56BEC7F559A8907ULL, 0x6BDC84938479BE9CULL, 0xADA73F5AFC498749ULL
        },
        {
            0xD5B7019B8F1BDF17ULL, 0x9348610B1719414FULL, 0xE3D481F1AA5276D2ULL, 0x81607FB9BD6FF7C6ULL, 
            0x183C57BFEE551007ULL, 0x386FA9BDAB5FAD0BULL, 0x7108BE78FFFC9EF5ULL, 0x9E104A37B5DFF5CFULL, 
            0xEF8BB8195F569840ULL, 0xF28027ECC03CCFC2ULL, 0x35AA5A0DC82CE4BCULL, 0x3FE7EC1C5F5EBFAAULL, 
            0x1EB668D3CE4C0D34ULL, 0x36EBCA38A1191530ULL, 0xB48CC273F1EDD2A2ULL, 0xB66D3922B551CFA9ULL, 
            0xED21C9117A1DA9A6ULL, 0xD6EBA373539579B3ULL, 0x5A77E46C131A8546ULL, 0x6D32EB9ECF322F93ULL, 
            0x86976CA6EF9D483EULL, 0xC289B9DA248EF055ULL, 0x7FEB089E885B52BBULL, 0xBD48FDF4A1E702E3ULL, 
            0x0AD3994509CAF632ULL, 0xF8C509815E3EF8EAULL, 0xB55E1C903F4520B8ULL, 0x3D9C52DD5DC587A9ULL, 
            0x54B0D3A5FFCEEDFFULL, 0x5BBE5FEC51A6F2CDULL, 0xF4F666B5FBDB6DF5ULL, 0x7F57A5B7B2A4102CULL
        },
        {
            0xF5AB9DA99AB83423ULL, 0x86D5F040EB0C0376ULL, 0x3D3E61D1F949A408ULL, 0x4BAD74F1CA9BBA89ULL, 
            0x7C248835CA4D2679ULL, 0x0E41EEB99F51EA58ULL, 0x07185446382E5859ULL, 0x9CC52C069A4EC0CDULL, 
            0x2CE0A86BD882CCEEULL, 0xBD3F8E0497347F4FULL, 0xCC32B849B4EA6E13ULL, 0x9991597048C1A510ULL, 
            0xD84C6B5A2CC19A28ULL, 0x8175539DF2A070ADULL, 0xD47D91C1FCC42B41ULL, 0x4A0C69A2EE69531BULL, 
            0x740F6179F505A07DULL, 0xE54BFABA353D2588ULL, 0xC95AA0143A69C5A9ULL, 0xE522F8B0FE497E74ULL, 
            0x8F130B21698EF6C3ULL, 0x6F96BF7A1FD19260ULL, 0x5DB3551BE6A334E7ULL, 0x46D340EFA6F51197ULL, 
            0x9C54BDEE4DAE608CULL, 0x3D4F37E9521A5A9DULL, 0x0DD6DF55D9050218ULL, 0xA1FB33C1EF4ADDE9ULL, 
            0x2BC02CCF459AB707ULL, 0xB6A2143EE7CDDD7FULL, 0xFADB0D42049F0CC6ULL, 0x76E85492D3BD48B7ULL
        },
        {
            0x1D07AF4DA12E86A9ULL, 0x7768D82167EA7333ULL, 0x88E81A744C4EC462ULL, 0xD0745FFA823DB473ULL, 
            0x4BF810F930FC0B62ULL, 0x55E243133ECA60FBULL, 0x66062C34935C2E20ULL, 0x850302C24874918EULL, 
            0x937870904D595480ULL, 0xCBB1A03208ABACBCULL, 0xBAA96EBE52964BABULL, 0x7C4FDF09C5725F0FULL, 
            0x8B4A047DF09064D9ULL, 0x2F19F43A19DCFAC7ULL, 0x140EFF156BA97EA5ULL, 0x59BAA7844E7F30FCULL, 
            0xEEFE23D09F04E0FDULL, 0x9ADB2E5C2CD33226ULL, 0x3EBB31E369BC8DAAULL, 0xE60C5501A5538C9AULL, 
            0x5E47994E02D33562ULL, 0x5A9CA96CA4448E61ULL, 0xD1A408242DB9076AULL, 0x3E348ACBCF806129ULL, 
            0x7D3762A5EAC21345ULL, 0xCA2CF6E723E93C9EULL, 0x2377B3320C3AEF60ULL, 0xDA99AB9BFACB4E91ULL, 
            0xA07C6CDCE5BADD22ULL, 0xBE1FC53273AC09CDULL, 0xBEC1672DFE4382F8ULL, 0xB3C15FDF864A8BDEULL
        }
    },
    {
        {
            0x0788327A1D59BD2AULL, 0x2278725285B1B558ULL, 0x62C92F17AB739501ULL, 0x083B7231C99EAF87ULL, 
            0x15B61D814E9E6191ULL, 0x5635B4F6B9FF2EB1ULL, 0x7F3978217400817CULL, 0xEA351F1BF4BF1193ULL, 
            0xDFD1FD68B9E965C9ULL, 0x02072F7DE5C61776ULL, 0x4520E490602DD351ULL, 0x55E277DC3F69EC60ULL, 
            0xB94F102E7C38B8E9ULL, 0xFC0755AA392A7FEFULL, 0xA3BB5B7E5EC432B4ULL, 0x364650135DC8A96AULL, 
            0x3725963ABDF7F6A2ULL, 0x958E5C9E67BEFBC7ULL, 0x8C2D68C6CD3FA691ULL, 0x3C20CDDFA6454F5AULL, 
            0xE9E5C0DC09FF316DULL, 0x491640D1AEC40D6CULL, 0x72876289E97EE268ULL, 0x5E2D3A56ABFDBE6CULL, 
            0xD61B9C18C2540376ULL, 0x8136587069406325ULL, 0xF19FEA15AB6F80ABULL, 0xC8873966CB82003CULL, 
            0x7077E96F25C2C3FDULL, 0x68808D10FD06A1A2ULL, 0xCEC2D13C24F377B4ULL, 0x22ED7C0BE4FC82BAULL
        },
        {
            0x550539B37A65EFB6ULL, 0x0186ED2C68AA5BEAULL, 0x95BADB733D19C493ULL, 0xD869DF75A025A345ULL, 
            0x9A126FEC14E8400AULL, 0x32D98AC40A9B7945ULL, 0xE8A26873DA5D49B8ULL, 0xE36F56F06B1F45C4ULL, 
            0xDCC6933FC52D79B3ULL, 0xA9929B71B93F2099ULL, 0x1B7982ECA344F80BULL, 0x8D3844FC6E376906ULL, 
            0xFE37FBC8305064B9ULL, 0x7AA4B4A2CFB5B0B6ULL, 0xE66A36DFF994B178ULL, 0x9265FFC9215E0C79ULL, 
            0xCA149A4BA6677CD2ULL, 0x245A03BDDFD9071CULL, 0xE134FE6619B7140EULL, 0x00E89AB761CE09E5ULL, 
            0x2BE45F4D35B86FDEULL, 0xF9CC26DA852F88EFULL, 0xF1B5E57284E7EC6BULL, 0x03623B329262309BULL, 
            0xA791A7D6A34E4A36ULL, 0x4A86768A004C264DULL, 0x0D9F1849EE4EA2D7ULL, 0x2F972F980C3325E8ULL, 
            0xACBA28B70DCF1E32ULL, 0x79FF81D3A359A8D1ULL, 0xA75AA0450CF74098ULL, 0x457DADA0F4EF223EULL
        },
        {
            0xB57453AF5A79DF40ULL, 0x454B04113AE475FBULL, 0x1191338D9B8039C1ULL, 0x94534879E1D3EF77ULL, 
            0xDD0A659FBDF38E8FULL, 0x3F4FE0F3C04ED777ULL, 0xAFE2FBBF3173C9BCULL, 0x6601AE23FA9D0C97ULL, 
            0xAFB3BBE4C41D2302ULL, 0x8D740EC7FADF3EFDULL, 0x3FDF410668DA8149ULL, 0x8ED5C9D92C58706DULL, 
            0x6163806C8E04C168ULL, 0x8EF14B0A3710CDB7ULL, 0xD6D165EB6EAA34CFULL, 0xDA00567FA14D12F6ULL, 
            0xE9BC856FB0A1E506ULL, 0xF6A9B52DF17836B7ULL, 0xC75A1B18FF6B7C22ULL, 0xA9EE239CBD3BB7BCULL, 
            0xFC2620E7DC2CBA2BULL, 0x8911AC19CE1981F1ULL, 0x4D7F68AAE2300FB9ULL, 0xEAC7453227612C1DULL, 
            0x909043894DCC48D1ULL, 0xBE5D211484C4CC0CULL, 0x2493CAD96B980F0EULL, 0x26CFB95DB7E14AC3ULL, 
            0xEFA128B9DBFDC877ULL, 0x621055BC5B5DCC83ULL, 0xAE016EBBC3CF5EB9ULL, 0x84BF3AC127FB4EB6ULL
        },
        {
            0x1CDD7D450C385BB8ULL, 0x71D41187D2153D69ULL, 0x3983B9C0F70B4F9FULL, 0xF45DB253E46FBF71ULL, 
            0x14C125A35EF05A8AULL, 0xA6F27DF1EFD4CAC4ULL, 0x8D660BB4364BBCF2ULL, 0x793DA4533344263EULL, 
            0x5595BB55CDBFB4F7ULL, 0x1AFE2F7E11D98FE8ULL, 0xA679776B8EE6101BULL, 0x31211D98047CD854ULL, 
            0x456B6E1AE53EEAD1ULL, 0x0D08649101DC3B47ULL, 0xB2BBCBBA3F3C63C2ULL, 0xCEC1F3EDEDD6DB8DULL, 
            0x25968D7C6E1539CEULL, 0xA1DF47AFFA41C845ULL, 0xE5FE79E5477BD898ULL, 0xB11F39F1727E5BC3ULL, 
            0xD2E66D4DC857D42CULL, 0x9E3FF01DD5A25ACCULL, 0xDA07F22C3F15199FULL, 0x2780B1DCB8B531AAULL, 
            0xDC4E548D7FA2E397ULL, 0xBF4C3B6B7B3C7E27ULL, 0xF880940BBB435A10ULL, 0x20DAF5B9F3BE2A25ULL, 
            0xDEAED12E67E6826BULL, 0x2FEF55465453F641ULL, 0xC5745CD9B219F2E3ULL, 0x743F46B177877CB3ULL
        },
        {
            0x55620F4FFC06EB5BULL, 0xB10E387A27EBEBE5ULL, 0x6C78B72F1C520206ULL, 0x4FFE93DCABA7C2BCULL, 
            0x5102B4C0491D7136ULL, 0x40A8E037CC257B6BULL, 0x6C4FD38B97726559ULL, 0x4F262787A5548917ULL, 
            0x836AB592C3A2863AULL, 0xC099DF7E5A1F452FULL, 0xAE9E113B637A85CBULL, 0x57750B482BF99344ULL, 
            0x427FB81EA7AD9582ULL, 0x6884F0186C094ED5ULL, 0xC9167ADC10373BF8ULL, 0x8C4DD18D20058458ULL, 
            0x0CD05E557DF75C75ULL, 0x59CDEFC8FE7E5533ULL, 0x85D1F75688EAD0D9ULL, 0x12F6BF134453D2B0ULL, 
            0xC6100EBCAB6CA24CULL, 0xED766C507D388505ULL, 0x3A1EB49EC8A1BFCBULL, 0xE174CA504CCD42B2ULL, 
            0x32C82C286F1EA171ULL, 0xC197D3005B50DD74ULL, 0xD30905429F0C8FF4ULL, 0x805443DCF0F36E6FULL, 
            0x6E9103486FA0E4D7ULL, 0x7B2362D412CD5BEBULL, 0xBEF3D11498677FE7ULL, 0x0A2D884B0E3FD563ULL
        },
        {
            0xCB01204D3B71B0A8ULL, 0x94ACEA9F21B90E66ULL, 0xCB366B2906926183ULL, 0x4CB18534E0350962ULL, 
            0xB4F4F0B544B2265AULL, 0x510C4289E5CD8C0DULL, 0xD318572BA47BF492ULL, 0xD79B720D3E374B55ULL, 
            0x204F685A343E2747ULL, 0x0D63372E2BC209B1ULL, 0xEF611DED6B60664EULL, 0x36E3B7CBFB0E01FDULL, 
            0x18C69F5402452182ULL, 0xD3EAE31DC8BDE3FAULL, 0xA6F82B60E5F82B8AULL, 0x89D55A5CAD7729F9ULL, 
            0xD1FAC9603E9A5FC8ULL, 0x899FE0676063B943ULL, 0xE16CFBE1CB0CD88DULL, 0x2AE6EDB28DF7A123ULL, 
            0xCEA6FEAFB2BE89E7ULL, 0xDF22E92D2E670CFAULL, 0xDB93C61ACBAF68C7ULL, 0x8CE8F308DB8198FEULL, 
            0x1BB45ED47E911636ULL, 0xA4FFCDBE960B99D4ULL, 0x4F1E54926D157AFCULL, 0x32262B2C408D55F8ULL, 
            0xF8F78858AC283D0AULL, 0x144FCD22925620F2ULL, 0xEE0A3541B867A5A6ULL, 0x8756EF46199A92DFULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseDConstants = {
    0xF53C355CEC854A8DULL,
    0x86B2FFE868244ECCULL,
    0xE276997A98D0326CULL,
    0xF53C355CEC854A8DULL,
    0x86B2FFE868244ECCULL,
    0xE276997A98D0326CULL,
    0xD0B32AC6523D2F7EULL,
    0xCE70BF390DF6F17FULL,
    0x8A,
    0x42,
    0xB8,
    0xC7,
    0x75,
    0x94,
    0x14,
    0x83
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseESalts = {
    {
        {
            0x26F58CA30C5B0096ULL, 0xE568C39A43C0580CULL, 0x4B49608842B92B93ULL, 0xCDE0E673AB3A3068ULL, 
            0x350778D2344A51C9ULL, 0xFE2E4F01F21FFE19ULL, 0x8C50496D6B7234B0ULL, 0x8952948B16C39DB0ULL, 
            0xC428F0FC88E1A7CCULL, 0x0760C04EBF1BBDA4ULL, 0x751AF4E8A5EAC082ULL, 0xC7835808570CC11DULL, 
            0xE415B58D4485B198ULL, 0xA1794DAF4A7BBE76ULL, 0x62B1DDF238F4FC3DULL, 0x8D644C3907FC0B30ULL, 
            0xDC8E2B83F6665326ULL, 0xF33CEA79F9C0D84AULL, 0xE3AA87619D76FE7BULL, 0x582094BF240307D2ULL, 
            0xAAF994D57AAF66E9ULL, 0x8C0D8355051FBFAFULL, 0xF562B66448F94F1DULL, 0xADA03424E619F047ULL, 
            0x1CE77AD051B18CCEULL, 0x2BA8E68B4ADDF4FAULL, 0xE3C6694F0BDBC0B9ULL, 0x3D02A3F3A538BD30ULL, 
            0x5915B365FC54B4CBULL, 0x9577DADA362C6711ULL, 0xA1DA0E8C46279146ULL, 0x0CB41EF561096F03ULL
        },
        {
            0xAE4F5EF15949835BULL, 0x11E6BF73D6E21048ULL, 0x643DCCF8E3E463A5ULL, 0x92FE626627164334ULL, 
            0xD624553B8D82738EULL, 0xD3E329BF168C5F40ULL, 0xAF55B63240B8413DULL, 0x6FE7E8B39E1F8294ULL, 
            0x1E07FD69F6E698E6ULL, 0x3F1B3A66CF27E2DDULL, 0x33A62B2009CEA57EULL, 0x6EBD6446C84A6263ULL, 
            0xC84C42C88FDCEDC0ULL, 0x6E3CAE88B9278E8DULL, 0x1D65C6C6E4BEA668ULL, 0x45EF71B30CF2B0F7ULL, 
            0x6EDC69368315761AULL, 0x4B584BBC75C72AE8ULL, 0xD6118BB1DD9647ADULL, 0xE0490DF23504A59CULL, 
            0xD0C084F00375BCB3ULL, 0x62A00DDD2B7883D8ULL, 0xA786444991A08D69ULL, 0x1E1CB13588B85DCAULL, 
            0xC362D7545C503A59ULL, 0x6CDBAE6C304257B4ULL, 0xB32599B8F156B4A8ULL, 0x5ECA79CE1C284725ULL, 
            0x23E1515671EE7349ULL, 0x32C57493560C985FULL, 0xA18E9F99B3B75139ULL, 0x741866B66DFB41BDULL
        },
        {
            0x593E775EB30FFE77ULL, 0xD1CA75BE1847F51BULL, 0xDA804D3962CAA3EBULL, 0xEA3A2AC02D4DBB85ULL, 
            0x948B80C4E27E6CD4ULL, 0x778C2EA92E3F7CF6ULL, 0xA323C76A66B381EFULL, 0xCABE1B2E8D8ED0D9ULL, 
            0x2E2745089A1FE8FFULL, 0x4DABEBD2E2A4B73AULL, 0xE6D736AFC4B4A799ULL, 0xC8AEA516F18C3BA9ULL, 
            0x81E07D24019F475CULL, 0x5C4130B959E25BE3ULL, 0xF25262E5E9C7A3A4ULL, 0x9EB4AA1FA4D9A77CULL, 
            0xFE86539D4123BA47ULL, 0x8CC9E60FAFDD3722ULL, 0xC4D53E381045C6F3ULL, 0x44027E3DCE3AF26BULL, 
            0x1A889AFE00AC4F65ULL, 0xB802EAA7BFE40F76ULL, 0x0CD8E35172E6B119ULL, 0xC63F6A2849DDA645ULL, 
            0x1FB76C8DCFD48F9CULL, 0x2C5ACBAFAEF8D3F6ULL, 0x40FBBC7DEFA68530ULL, 0x4BA1989362C1A740ULL, 
            0xF568E20FC0DA5C52ULL, 0x70CB22BB8F75610BULL, 0x56F4D7A253FE465FULL, 0x4DD47784296C2679ULL
        },
        {
            0x5B9A4740A4A79ACEULL, 0x74C81BDD63D7CDCEULL, 0x8D4C1D5D68FE62B7ULL, 0x11D15CE789467BE1ULL, 
            0x5D99145B93646F61ULL, 0xF5E095FC972D223AULL, 0x2A4F3EFA83D6F0FEULL, 0x30FBA55826B7D8B2ULL, 
            0xCAFC63B69DE6F5B6ULL, 0x04DF324F5CCB19F7ULL, 0xD84A79188CF33C3EULL, 0xF7155E05E2FAF13CULL, 
            0x1785E9E88664BA90ULL, 0xB5CC164D3BEA66DCULL, 0x86B109A5E78AEF1CULL, 0xDECF0429D9EFBCBBULL, 
            0xA74688A786E8F1BDULL, 0xFDA0A97B13EB57BDULL, 0x7ADE73EE4A18C8A7ULL, 0x31BA59BBD9B92772ULL, 
            0x1384B00247026DF0ULL, 0x3552F4AFFC383061ULL, 0xCFF63CF307AC2E52ULL, 0xA1CB6AB26E707CBDULL, 
            0x24F86C53395A2DFCULL, 0xF351039F8D57D79CULL, 0xF6AAB52C7CEB4784ULL, 0x96DABD29EE434EB4ULL, 
            0x2F2DF2155557BBF9ULL, 0x1615E15AF8698B4DULL, 0xADD7B42F485A3CC1ULL, 0x774E134B353787D3ULL
        },
        {
            0x51C863D919D17192ULL, 0x5D16E794F98993F4ULL, 0x09FA1301775F4815ULL, 0xB9B1DC4EF2F2C507ULL, 
            0xBF0E80E56873CB81ULL, 0x9B388755218ECCC1ULL, 0xD6CA27DC1521D479ULL, 0xDCC91CCE32B1C78BULL, 
            0xEE03F23AA7D3706BULL, 0x41FFC1D8B468AF44ULL, 0xF9669CE71A9EA1BDULL, 0x5A32FC3FC106E817ULL, 
            0x3BDD785EF05CDF91ULL, 0xA8A007610D05EF53ULL, 0x4BC14F55595406FFULL, 0x2FCEE760DC439813ULL, 
            0x69A10AB43E127CC1ULL, 0x1DE0C07F01595E91ULL, 0x4A9B4B9910E99722ULL, 0xB97F0C7E1549D10CULL, 
            0x0CA7A9BA36A3787DULL, 0x9CD249904F570D34ULL, 0x4F8B147075178715ULL, 0xDE6DF2FECA2A33BDULL, 
            0x1936EA5EABF900C8ULL, 0xF668CF124BA3BE57ULL, 0x7C0D8C5CEE5A3399ULL, 0xDEE04C53815F7CACULL, 
            0x760CFA93D6A2186CULL, 0x1FAF6A17FC2B8918ULL, 0x0211C73AC43756DAULL, 0xC80E43C9E5798BBDULL
        },
        {
            0x972C229D227C105AULL, 0x43C9DE7AF1CEA10EULL, 0xB37A5C8BEBA70796ULL, 0x40BDB95898EF28BFULL, 
            0xD8A7C30AE5FC0A8CULL, 0x183BD3A045BFDA04ULL, 0xF958D3830317D4DDULL, 0xC610AE87FD96754FULL, 
            0x18E1131C23BB6EBBULL, 0x0C16ACEFA8ECC732ULL, 0x09E4427CCAB643D8ULL, 0xF99543909889DEABULL, 
            0x2EC856AAC0CF81EAULL, 0x3BE508EABB005FD4ULL, 0xD70D1A96D691D8ACULL, 0x8C05E4F5DFF5C0A1ULL, 
            0x198A9C26BA7E3532ULL, 0x767EB8D1559578E1ULL, 0x458375E716C89D54ULL, 0x83BA9C1BF5047DAEULL, 
            0xFA342F653072EAB9ULL, 0x59531047B6DC0FB5ULL, 0x82B98C9060E91B8BULL, 0x8CA3990C3CB28B01ULL, 
            0x059D170FEE8317DDULL, 0x81E4F5A936238F2BULL, 0xA5CB01014231E9C7ULL, 0xBB9C8081024AFB83ULL, 
            0x68950CCFB057BCA5ULL, 0xF4D6B32C43527A29ULL, 0x7A7E549B63A8685EULL, 0x49F1CF5AA741140CULL
        }
    },
    {
        {
            0xE8DB216C947C03FEULL, 0x27EFDB1652F170FAULL, 0xC0BC72AF98CC97DAULL, 0x5C5E3C43F33ED0EEULL, 
            0xEAC2FFBC40B4A4C3ULL, 0xF28FA75CD144DD92ULL, 0x295FF5BFCFB7FD23ULL, 0x043DC27EA7C1B071ULL, 
            0xC57DC2F261196540ULL, 0x1817C4DDA789B7A1ULL, 0x5549981E54ED845FULL, 0x09F9E8364EB8B30AULL, 
            0x1E8044C093D483D0ULL, 0x4FACA438B74EF3B6ULL, 0x7EB4A0070AD54F94ULL, 0xBC4FA6C02BF70459ULL, 
            0xE6FBA4911E6278F8ULL, 0x2F5C27A5CFE2B1C2ULL, 0x486A162D09EA4659ULL, 0x0342AE5594F0F8BEULL, 
            0x34993C3AE2451832ULL, 0x35591C01580C3399ULL, 0xEDDE3DD7D58320DBULL, 0xF1842405CF89C350ULL, 
            0xB5098825D6036C6FULL, 0x5DA5C160EBFD638BULL, 0x6C58A47E3E6FBFB6ULL, 0xF8CB17069BE13552ULL, 
            0x2497DE7D764B4B74ULL, 0x288EBB920612A0CBULL, 0xB05DB9A7CE843420ULL, 0x5D7F5048A426935EULL
        },
        {
            0x577B7061BE313E2FULL, 0x7A976405269D4B81ULL, 0x474266367FE941D2ULL, 0x0F1E918C087CC739ULL, 
            0x23BE8AFA0F589373ULL, 0x53E25F16563CDE8BULL, 0x14EBEDD5EB6AC2BEULL, 0x8702C1EA4B8DF2C3ULL, 
            0xD43490C180F7D3D2ULL, 0x360EDCF547079AFCULL, 0xADC916D7F86F19CFULL, 0x66AEFA9C3BB455B4ULL, 
            0x78FEC9E68C8BF364ULL, 0x0F99234F6EE502AFULL, 0x4B7DB6047CA26387ULL, 0xBCEE138F94AEA202ULL, 
            0x44222E56548B2646ULL, 0x1F9766615CF401F1ULL, 0xFA4CA3143CBE2D7EULL, 0x7C978D77C126B76FULL, 
            0x98B9549A00E1444BULL, 0xB75D1CECDDB381F2ULL, 0xC3DDB4039840D834ULL, 0x46423FD620CDE3DCULL, 
            0x2318FDB4DC9FA47BULL, 0x323B7BFF72FCF110ULL, 0xEC54BA89F4D85134ULL, 0xB4BA61D364166CECULL, 
            0xC27AA946FE39A18BULL, 0x8B67B98B14D14775ULL, 0x6419147D7D1556FAULL, 0x32D64236657C116AULL
        },
        {
            0x673D8FA887324977ULL, 0x81B526F2904FE7D8ULL, 0x910903362E70FA8DULL, 0x8E292BF719E12FF2ULL, 
            0x207022FE1EEE4452ULL, 0x0B1D477E3BC80A26ULL, 0x4D44AEFBEA555321ULL, 0x8361705BEBDC7CB5ULL, 
            0x6D95EE66D0C81FF4ULL, 0x659BB1C5D13FC956ULL, 0xA32FE5D8AA10637FULL, 0xD7156C6D960AEFBFULL, 
            0x31B5E5BF60AEAC7CULL, 0xA1E65B4DCB694DDBULL, 0xE2C4A83714EDD5E4ULL, 0xA76FFBC1A7B2537BULL, 
            0xF501F7C445D031ACULL, 0xBD730F4815EE1606ULL, 0xED4F307CFD68371DULL, 0x271E1E7E65A96F0AULL, 
            0x1B219564D39AF490ULL, 0x206248E81DFB1397ULL, 0x5F4D018A645B72AFULL, 0xE3AD5A20CA1F22AEULL, 
            0x609057891AA37734ULL, 0xF92EB139681D34EAULL, 0x80A220E231516B39ULL, 0x8996FA3910ACAF63ULL, 
            0xDABF9EB5F50E935BULL, 0xAFCFB88F792EFE5BULL, 0xBFCC33FBD4676217ULL, 0xC1798C597F016B30ULL
        },
        {
            0xC80F19CA675D57B4ULL, 0x71B7171FC17DD312ULL, 0xB055DACFB3977B08ULL, 0x6D11B5096EC4C9D7ULL, 
            0x8C9AF53DF3F78331ULL, 0x7940CFF69B954750ULL, 0xBA33E744A43D7A56ULL, 0x264F555B6FF8F806ULL, 
            0xA4FB1CC63C671524ULL, 0x58FB26F99780AC9DULL, 0x0642B8A0289CCBB1ULL, 0x1D0D4B7F73C08B8BULL, 
            0x83E3A6A132D82F0BULL, 0x00FF1832516A053EULL, 0x0A42F90BB43CCF21ULL, 0xEA89031A8F11E3B7ULL, 
            0x7548B70FD716B0EBULL, 0x75A24542797ADB63ULL, 0x65FA9D7BD2B42693ULL, 0x39023F04165141B9ULL, 
            0xEC6BB70944BC1F6CULL, 0x57E538EF2129F7F5ULL, 0x090479EE86EB645AULL, 0xC50272E8318FFB37ULL, 
            0x4803785502A83096ULL, 0x82FAF2EDEBD02403ULL, 0x3BC69ECB2D188F29ULL, 0xE42D1C84CDD4A8C7ULL, 
            0x8941E4F79A12B6BCULL, 0x813114CBA1358F69ULL, 0x5F612F00001A63BEULL, 0x448F6B848B8A1C31ULL
        },
        {
            0xD38EDD01D5118005ULL, 0x5092359EA2D1273FULL, 0xE81CE7D320B31ACEULL, 0x14AD09D130A1B11CULL, 
            0x483319B09A68534FULL, 0xCC14CF57A8FCFCE6ULL, 0x96E0EF1347B1B02AULL, 0x253FB3E9E5A71ED9ULL, 
            0x415B9E6A5F7BA8F9ULL, 0x7C2383995EF95B14ULL, 0x787B667C77D9C48FULL, 0x6FB4222BC82FE8C0ULL, 
            0x012C12105AF0EE90ULL, 0x651AE4F69E1AE056ULL, 0xF8670E7DBA3CA7A2ULL, 0x3A1368ADE679774DULL, 
            0x986D0CECE06E8CA3ULL, 0x60C44196C50C6CB8ULL, 0xE9668B284F8FE0D6ULL, 0x17638807925D713AULL, 
            0x7E1FE1BFC2544D23ULL, 0x495791BB71EBDDEAULL, 0x001A86CB1D2F17D8ULL, 0x650CCE3A3C48D93AULL, 
            0x8DC65BCF20AED6EBULL, 0x60B2364883568630ULL, 0x4FC8ED66722D033FULL, 0x565ABF9C5CF57C5BULL, 
            0xAA339B1D55EAB3EEULL, 0x446B588F25976572ULL, 0xA21871608E8EADFAULL, 0x35A4642C2F026C88ULL
        },
        {
            0x7267743090077265ULL, 0xD3C255A25BDF7CE4ULL, 0xF99304A5E091A6FFULL, 0xF4050723C462D4FAULL, 
            0xC9329354F44E514BULL, 0xF1D0898F0FC7DA55ULL, 0x8E62D02CA488CB78ULL, 0xEC5FE38E19691393ULL, 
            0xE07DA54144C652F9ULL, 0x785086AE6215D75FULL, 0x1A9734693A63B00CULL, 0xB9BC52E7D3D895E6ULL, 
            0xD7C56ED55FAAF2F1ULL, 0xFA146E090B864658ULL, 0xD09840DA4BC75B4EULL, 0xD02159F95B09F603ULL, 
            0x5ADC2F083A1576C4ULL, 0x5601C7A65976BAEBULL, 0xD94A7C810D0941E2ULL, 0x72DCB1FC09735388ULL, 
            0x9A0877A76C9E9B3EULL, 0xFEF30F52136ECF63ULL, 0xE18F6D81370E03EFULL, 0x392117C59161EBADULL, 
            0x7CA791DB16ABE0CBULL, 0x88D190165D166522ULL, 0x2696DCCAA21738C6ULL, 0xFA0E89A3491600E7ULL, 
            0x701CD8236582F1DBULL, 0xEC8FC0F26524AD88ULL, 0x4C2D6CC1C3336FC8ULL, 0x09B7EEB9EE95BEA3ULL
        }
    },
    {
        {
            0xFA0A975A40706368ULL, 0x68DDF7B0AE66C8E3ULL, 0x39BAE3E56D63AB5FULL, 0x846F2AF41AF6EDDBULL, 
            0x4021720B6F9093FEULL, 0xD49447140F6D5953ULL, 0x19B34BF7D80BF0CEULL, 0xB8C3B2E65AAB3712ULL, 
            0x1C66546FA9F85643ULL, 0xBD49939D2D790B31ULL, 0x7ADA38847DF5EE99ULL, 0xB70810C575BB96D5ULL, 
            0x9459D603D272252AULL, 0x3A4C0CD907C89289ULL, 0x52B69B91BF9AFC01ULL, 0xAD19E54868848278ULL, 
            0xA6019DD825B78DE1ULL, 0xBB84B78CC52D5369ULL, 0xB1FF7B95470CBA46ULL, 0xD5FEED44E83519BDULL, 
            0x89D120C63DEE66BBULL, 0x8FCEB151EF7A31F4ULL, 0xECADF2EA92B55752ULL, 0x7689EAD86E154BC4ULL, 
            0x626525D04CD39F8AULL, 0x9E97BD9783FBA842ULL, 0x2D0A7A27BC30F751ULL, 0x118661CF5A016DCBULL, 
            0xEFDF5DC0C8DF5DD5ULL, 0x787F0F992028CECBULL, 0x3C3E9DBD2196DBFEULL, 0x81FD3C12B72636D4ULL
        },
        {
            0xC6A8038DF43D3E19ULL, 0x04DB2418360E1796ULL, 0x6A43D32416DFAD77ULL, 0x5E7A0E6FF597744EULL, 
            0xE4AED09825C0DFFEULL, 0xC8DF5C4DBC9A5B68ULL, 0x5676F84A3BFA37BBULL, 0xE267C008D63E7799ULL, 
            0x41C05C03D82D9CA2ULL, 0x38C1D54AED29F0BEULL, 0x3047DEC0C2DCF4C5ULL, 0x16E18D61ED27B753ULL, 
            0x717F635D2E376EDCULL, 0xD0AFA07AF1F8B90FULL, 0x7186183673251AA5ULL, 0x350B9DE552A7CCA1ULL, 
            0x4E352C6D2C91555DULL, 0xD8EB135B15C230D8ULL, 0x4D246FA1A5153DFFULL, 0x10EF07A1DDC79E25ULL, 
            0xA4DA80B2BEA25682ULL, 0xD5877BE6EC75689DULL, 0x1D8A5D5CDF45FAC0ULL, 0x0B94366CCA6EB3C0ULL, 
            0x8A7E01F71A9BE235ULL, 0x1FA17D57BB92E1E3ULL, 0xA651E83AEF257669ULL, 0x1DEDC8D6523A32F7ULL, 
            0x5A7B2930504DF018ULL, 0xAA123DE06A90E056ULL, 0x7C57B1DEC24AABBEULL, 0xA0F622375D9DDEE7ULL
        },
        {
            0x67022D2B680C5CB3ULL, 0x6EAC8F8D0DC512C8ULL, 0x89F8A883607A3534ULL, 0x5F009540D840B735ULL, 
            0x73D480D038865C27ULL, 0xD3D0599456CA64D4ULL, 0xE366F7CF33EEB2C3ULL, 0x77FE2FB3F615A54DULL, 
            0xBDD7268C55EAB1F4ULL, 0x00D182361F4FDEB1ULL, 0xEEE52B4ABA3BC654ULL, 0x909B3F0BC511E3E4ULL, 
            0x4D93AE64AAA0003FULL, 0x79FD7640D2F2F353ULL, 0xCF85EBEFF4662952ULL, 0x698F97A5130E8EE3ULL, 
            0x40CFA80A331BBF48ULL, 0x95A7BDC5BFF291D5ULL, 0xD77CCE935CD18606ULL, 0x35F87A60D648CFABULL, 
            0x7953B5A6B0B389D7ULL, 0x6FDB2CCA0FB23D56ULL, 0x56A490E39F97410AULL, 0x34403836AE3A1F45ULL, 
            0x5DEAD0EC1F43D12FULL, 0xACC71A3E26B043C7ULL, 0x653FF5D9813CC3C8ULL, 0x69FFC02CAA2188BCULL, 
            0x94E335D3ECB5A065ULL, 0xB8B2C710DBF1446AULL, 0x4B54321D3D6BF875ULL, 0x617D104AD99BB7BDULL
        },
        {
            0x6AC8848103E83FCCULL, 0x2A32CDA7E7C2C6D0ULL, 0x00239DFA416A7E67ULL, 0x5F738FF01ED609BFULL, 
            0x42525E80AC8462A7ULL, 0x8D5E265FCCBB8B53ULL, 0xDBFDB414843FF695ULL, 0xDF3492CC313CD856ULL, 
            0x2C09D70985C27B0EULL, 0xC5375DDC47F28261ULL, 0x47136D2DDBB26E65ULL, 0x35B6CA7C73D6F156ULL, 
            0x4515FBE3597A2C21ULL, 0xF99D5713B2AEAA6BULL, 0x07FADE23DB9FD327ULL, 0x1FD99FB0994048DDULL, 
            0xD250F9572EDF0F6DULL, 0x2611BA49CBEF9D3DULL, 0xAFEC2D8CCB251980ULL, 0xE2E01CE1A9777139ULL, 
            0x3F9E0F5FD2543AF1ULL, 0x7BA8E89411AD637FULL, 0x9D29F8BF09D42A65ULL, 0xC1EA3288E3E0202CULL, 
            0xE179AFDB1CB90958ULL, 0xEC74A70516F099BBULL, 0x2C71D5E75F4024AFULL, 0x3BEF148927325256ULL, 
            0x441AD2EAC639959AULL, 0x8DA855F980162468ULL, 0x3434C22AC6245271ULL, 0xFDA6DCCD1428829FULL
        },
        {
            0x6D965D777D651B5FULL, 0x300B8631D32EB94CULL, 0xF043B3B4431506D0ULL, 0x10C80B9C855150DDULL, 
            0x822C6887C286EFBFULL, 0xF086E560CCDAC432ULL, 0xC9058A9499B6F309ULL, 0xD2257AE1B6C659DBULL, 
            0xC1C6C5FD3184EC0EULL, 0x947C4E7AAF18A4CDULL, 0xD384D66E9AC55EE5ULL, 0xB89F767CFA057179ULL, 
            0x5FC18BAABD1D5175ULL, 0xC3A844B6FB64A280ULL, 0xD44D1C66C2C863F9ULL, 0x13B5AFFC686DADBDULL, 
            0x6A51B0FF64D5E2A7ULL, 0xFDE8179D79AE6213ULL, 0x90ED8A998ED48448ULL, 0xC9CEB7452079C41FULL, 
            0xD12F8CD1CF50242FULL, 0x3C4398CA8564744DULL, 0xB29F59CDC94E5C80ULL, 0xF80C38DE78F00CAEULL, 
            0xAAA9E17F4A4DA724ULL, 0xFF46912D158CCEE9ULL, 0x6B09B4C2CF777FEAULL, 0x48BB758D836DF94DULL, 
            0x7C55F6BB8EF1DF42ULL, 0x22FED72EF0429807ULL, 0xC51DA0D5F5F71C22ULL, 0x32C23E7E8271E3BDULL
        },
        {
            0x1727DFA10222A414ULL, 0x11B23C252D33684BULL, 0x6B5E41C8C58BAB81ULL, 0xD7ED209DCD98B291ULL, 
            0xA1CBFD953C0124F3ULL, 0x7D53D037B3BC57ABULL, 0xD848FF8337A40471ULL, 0x7D043A4F023F3C55ULL, 
            0xEC9C0CF95535A26BULL, 0x43A32AD6367C0D30ULL, 0xF1B166352F2F5579ULL, 0x4C41C1E1AC1D967EULL, 
            0xB8B0A571F631D96AULL, 0x2971651E773FB8FBULL, 0x95DAB50604B61CACULL, 0xCFA8165ACE0A0DC3ULL, 
            0xA4E463CE465A0173ULL, 0x622E049AFF881FCDULL, 0x1C73CDF9F9742D1EULL, 0x588BB6108D56EB79ULL, 
            0xAD53F8B7006E8BBAULL, 0xC1C5E3F495561AD2ULL, 0x0848FDE3EE36F409ULL, 0xDB68671626583A4CULL, 
            0xA04253F81D1151E4ULL, 0x20B1D67FC9602ACDULL, 0x3D887450486B03FDULL, 0xBF7AA2AF3B2BD054ULL, 
            0xA5CAE12790863FFCULL, 0x18CCCA77781B62A1ULL, 0x4AD32F6C7C224921ULL, 0x4E1E5200E6406102ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseEConstants = {
    0x4996C8F4D30ACF7BULL,
    0xC0195A700514155CULL,
    0xAC357EF82B0E423AULL,
    0x4996C8F4D30ACF7BULL,
    0xC0195A700514155CULL,
    0xAC357EF82B0E423AULL,
    0x879EE5270AAA3D06ULL,
    0x279B09B3C6EDFBAAULL,
    0x57,
    0x7D,
    0x84,
    0x9B,
    0x11,
    0xC9,
    0xB6,
    0xDA
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseFSalts = {
    {
        {
            0x21F8D1E3EB688873ULL, 0xBA1E996E1F9AABE5ULL, 0x3E52E23DDE27D992ULL, 0x476B4641A9FEB1B6ULL, 
            0xD3603450B7860330ULL, 0x8C37929BDDAC3213ULL, 0xB3FBB2D1B8171737ULL, 0xC792B80EC1B43586ULL, 
            0x500373454BFD7B43ULL, 0xCBF0FF4191D94F27ULL, 0xCCF387BC7B732E14ULL, 0x6F777721C069AFD0ULL, 
            0x5AD0B93FD3C0AB34ULL, 0x02AD181D65C04E92ULL, 0x833F22057B357380ULL, 0x96E25A83C0ED018FULL, 
            0xC1F604BEAC1339EEULL, 0x0AEC7C6FE16C09A1ULL, 0x4302ED87B50AA414ULL, 0x5D3B25E62EF4ACD8ULL, 
            0x59A7923A59C4F93BULL, 0x48C222E2B017B318ULL, 0xFCC49BB08AD446FEULL, 0x1DEAC075E5DD141AULL, 
            0x60FB8B1E182F61C3ULL, 0x2D816D762983EB67ULL, 0x00625FD8A112AD4EULL, 0x97D1D7937056C128ULL, 
            0xF0BAC9ED26CF8E18ULL, 0xA9E1B4C81B82D09EULL, 0x55A78ED39E389387ULL, 0xE76A767292B51D10ULL
        },
        {
            0xB2705F9E9A0FEE63ULL, 0xC014E3E25D20AFF7ULL, 0x90610A7906B9A025ULL, 0x1475D94921BC6214ULL, 
            0xA077916A7DEAFD39ULL, 0xF606E82FED14D80AULL, 0x1E42AA804D46C097ULL, 0x3DD7C7EDAE423DEEULL, 
            0x755A2D9FDF928AC6ULL, 0x240DACAD2F037BF8ULL, 0xBE02D4EF89BE58E9ULL, 0xC08CF519D58717D4ULL, 
            0xB5DAFEB4F95B42C0ULL, 0x6FBAEC22C156A0EDULL, 0x11F564EEB9F82EF6ULL, 0xD98F33D96AFC278EULL, 
            0x2FF61315AFA097C0ULL, 0x5D45F7A3FBF7B6EAULL, 0x84887610B31245BCULL, 0xE376D1C52695F997ULL, 
            0x060E46A8FDC0378CULL, 0x46CC75D329742E76ULL, 0xA58EE6022AE10196ULL, 0x9530C3C55950DBB7ULL, 
            0x2563328C8178C631ULL, 0x7599527920386EE4ULL, 0xD45C22929836F527ULL, 0x07EDD7CF96A76729ULL, 
            0x9C24D9C0864DC575ULL, 0xC4158AFEFFA5A9CDULL, 0x4CA80BCF5B0CF906ULL, 0x469ACF3B8968B64AULL
        },
        {
            0x1843E8EB394F5269ULL, 0xA15FF20A27409B91ULL, 0x37BAA307874AE066ULL, 0x913AF05770FC9D16ULL, 
            0x6DA28464649B33A3ULL, 0x24BB609A6F540314ULL, 0x1FE6A477ED76EA5EULL, 0x3E1A33622E609B56ULL, 
            0xA84CFA1BBE550DF5ULL, 0xA8923EB7B6CECA61ULL, 0xE1C03B7C1F17FBEBULL, 0xB3EE1D9929189CAAULL, 
            0x67B799DB9B2D46CBULL, 0x8E5CF077F11ED606ULL, 0x6FC40F22AEAF6238ULL, 0x21B04D727AF3A7F2ULL, 
            0x14BF542B99BEA71CULL, 0x6CF0A95EE7F77472ULL, 0xA52E56F166DB8306ULL, 0xA30586B212E8D62AULL, 
            0x95836FFA140AAE03ULL, 0x1ED65E0F45A2ACCAULL, 0xCDFCB0EA30D4CC63ULL, 0x514B2C3B3958E8E6ULL, 
            0x111202A1A4FEB648ULL, 0x500BD602B4CCB1A1ULL, 0xEF35350EF15C3428ULL, 0xA2FAC8A512A23F12ULL, 
            0x77B09C4197FD654BULL, 0xC7FBB5F203365BD5ULL, 0xCF35EE7F1ADFB19DULL, 0x8F214DDB8A2E44BFULL
        },
        {
            0xA812EF660CF5179CULL, 0xA91ED7A2D034C379ULL, 0xD7E3567EF3339122ULL, 0xA6DF858A108E2904ULL, 
            0xAE5BD51E1D7323F2ULL, 0xFB23AFA121DA3071ULL, 0xF08F930A25B4A614ULL, 0xABE962780C02FC9AULL, 
            0x18BD7172FC06A6D5ULL, 0x80DF6627957DFAA5ULL, 0x4AAFE300BD9D3BEEULL, 0x62AF5270B39F7B48ULL, 
            0xC21692B985FD80E2ULL, 0x8B127ED1A3952A64ULL, 0x110C00EF8DC98EBFULL, 0x6912306D86AB06BCULL, 
            0xDBDFC81F90C7C1F6ULL, 0x25702ACCED7C9DEEULL, 0x857FA0B8B804E52AULL, 0x444C3D6750B6843EULL, 
            0x2827B3C6916CB782ULL, 0x6F4B1B6C7660581DULL, 0x2861E39F652E23FFULL, 0xCD03791B75D9B551ULL, 
            0x42CD62BB468F0DF5ULL, 0x8B31D9F864D7628FULL, 0xB32B18F383655430ULL, 0x6B6E57730304158CULL, 
            0x8341CFC1B8D00A16ULL, 0xBB73D04C93645AF2ULL, 0x04E348C74DEA2D20ULL, 0xDBA834A42C91A70AULL
        },
        {
            0xB76B6CF41D0E0DEDULL, 0x61418C62EF01E17AULL, 0xE6EECC4471D51401ULL, 0x5A20506395EB5644ULL, 
            0x827D684ADAAA0AC6ULL, 0xE924A26517AFB7D5ULL, 0x0023872CA36B04C6ULL, 0xCFCD319AC7547E64ULL, 
            0xFA09210B87452962ULL, 0x7ACFBB7008E066BDULL, 0xFBD82B40EEB1625CULL, 0xAF24574B01C78E69ULL, 
            0xD5C6D868F1E55AE7ULL, 0xC7809A6867C8A1F8ULL, 0x93028633866330B9ULL, 0x58182D78EE3B8E8FULL, 
            0x4006A2BDED838047ULL, 0xC3D6F77EA8D070A9ULL, 0xB745D8B25CF482BBULL, 0x5857929079427A2FULL, 
            0x0CFE3BEA9734498AULL, 0x92DF6D0817D00729ULL, 0x050B55572F61AA33ULL, 0xD0047285225538D8ULL, 
            0x6B79BE2201FE35E7ULL, 0x732D2CB957CDFF8AULL, 0x89619BE15440F887ULL, 0xA48A5DCF45C996CFULL, 
            0x56405A8BFBE8661DULL, 0x8E522626C5C10A3CULL, 0x618729F6D888941DULL, 0x884FC761D2133BF9ULL
        },
        {
            0x09717FC09C373146ULL, 0x123E9B3102990E09ULL, 0x3DB07119A693C5A2ULL, 0x0CF1C91A8F8445CAULL, 
            0x46F3BC456C45FB19ULL, 0xE5B55A60609C44F6ULL, 0xBA6296E8FD932EE2ULL, 0x0DB050F7AAEB9E78ULL, 
            0xAB7F674B0067E76BULL, 0xE558D78F392A67DBULL, 0x174637B98FD22387ULL, 0xE16CA9EBE19A2CCDULL, 
            0xE21F9D1C7263888EULL, 0x6353CF59B816BF4FULL, 0x401FB7BA674815D6ULL, 0x7187B86C6F073D5FULL, 
            0x003C26F66D84AD99ULL, 0xECDF33CF1438B52CULL, 0xDE62A20EF4437AF9ULL, 0x074ACA2F34C8A10FULL, 
            0x08BCF67222F8B0F1ULL, 0x4DC194D81E9BA36BULL, 0xA6BB02E94290CCBBULL, 0x618B186EDB784492ULL, 
            0x155D0DDA2734E26CULL, 0xAEE6D7E20AABFE5EULL, 0xD7F915573D32AE7EULL, 0x15B68671CC323BD9ULL, 
            0x36CC07133A27A041ULL, 0x2A491095D02E9592ULL, 0x9798B8800506A4D7ULL, 0xFC09D83272E0046BULL
        }
    },
    {
        {
            0xE9DEFC8F106F2583ULL, 0xA4B618DFBF1AA52EULL, 0x1A0AFE73A4A06EFBULL, 0xC46EC055F68478A2ULL, 
            0xA2D518801B804561ULL, 0xB56909AC8DE45E00ULL, 0x95607B9BC5B94A5AULL, 0x46CFFB50F79FAC6EULL, 
            0x9438DBD3A27010BDULL, 0xA957DA4911BEA5BFULL, 0x965C779FDA4CEEFFULL, 0x2D1269C40B0406BFULL, 
            0x2851639DDAA6F4C3ULL, 0xB1B0F1E5F9F7EC31ULL, 0x9A3CF3C3818ED31CULL, 0xA616734357EF0777ULL, 
            0x202C7B2B5374D0B1ULL, 0x65BAD842F5F4ED29ULL, 0x0FBE36E9042AE266ULL, 0xCC18A50D361E3528ULL, 
            0x89C1731A41265ACAULL, 0x9BC976986359B5C0ULL, 0x2D28AD4F7A574235ULL, 0x28A00B95E06C937EULL, 
            0x551C57DDBC427BB8ULL, 0xAF2BE1D64BA82A5AULL, 0x5D1CDCACCD491325ULL, 0x54D993D7E2D351D1ULL, 
            0x2FE46107DFDDC045ULL, 0xA2EA5F118F0549F1ULL, 0x55AF4224B6FBF7D8ULL, 0xD8D4720407B052FBULL
        },
        {
            0xEC14D3B53796B763ULL, 0xEAA9F90034CC0F19ULL, 0x760382A9638509E9ULL, 0x6B883F1339AA469BULL, 
            0xC1AF63C18758A240ULL, 0x45ECDA7C934138CFULL, 0x943BD0A21868AAA4ULL, 0x4529D63CBDF166D4ULL, 
            0x23632D0309B3F70AULL, 0x58C029A8D1E23ABFULL, 0x252FFFF4091477B3ULL, 0xA7BD83D2100C2C71ULL, 
            0x76688699BFA53A65ULL, 0xAFF8BED0F0BE1489ULL, 0xB9850F3341B62EA3ULL, 0xE1304C6445771BC3ULL, 
            0x96E179790A23F3AAULL, 0xC11919C6E06C609CULL, 0x79C51F28E8080972ULL, 0xE1FD58CB7CDBF76FULL, 
            0x4A9CD4961B8D89ECULL, 0xECB3FD72F62802CDULL, 0xFFD7DC7237795563ULL, 0x2ADAD37BCBE7ECB0ULL, 
            0x81C99D15BF705F5CULL, 0x1A80F608A8565CA5ULL, 0x9B597BEA408B88E5ULL, 0xF95B79607F65A7D3ULL, 
            0xBE6398BB25AD924DULL, 0x98ACCF4A89599DD5ULL, 0xF97482089247E6C3ULL, 0x4D7EFA8A1059B30EULL
        },
        {
            0x10CCDFF6EE507F0AULL, 0x33FB9DBC00502579ULL, 0x04C0206EA0819121ULL, 0xC15089863BE423F4ULL, 
            0x6E9BDFA264E8928FULL, 0x6EE935429F43DE49ULL, 0x9B74EBE0B7782F9FULL, 0x3E9F7D96F6C19C17ULL, 
            0x09E6D075075DA8EEULL, 0x85B2B44541A74E93ULL, 0x2F57A02153801DF6ULL, 0x82D875A804E94363ULL, 
            0x6941539CCDB20B37ULL, 0x84F45208FF247631ULL, 0xDDEFF52796C1E10DULL, 0x9ED5C0155A6EA73EULL, 
            0x4D0C86E5E45CDE18ULL, 0x8235A5CF294E80C4ULL, 0xB3D0059B8D5571F2ULL, 0x84D503D3D661513CULL, 
            0x3E646D07D257AD1FULL, 0xA5C32D9F53ADD796ULL, 0xA0E18E5BFCF7F18DULL, 0x8B5874AAF6BD5655ULL, 
            0x96D40D1C24ACDC96ULL, 0xFDC6C088764C0F02ULL, 0x684D4737D0A4687FULL, 0xB055118046BC8D17ULL, 
            0x72072683B4E16CBDULL, 0x26B81121BC64C597ULL, 0x36AACE83007C95D0ULL, 0x13CC817472D32DADULL
        },
        {
            0xE56F7389C0A84B5BULL, 0x66886DC04F33525DULL, 0x610855A52154A692ULL, 0x0072EA80851C6045ULL, 
            0x95E29A542C0DE000ULL, 0xE80380D6E62E4EBBULL, 0xF19C2C0D9B79B396ULL, 0x75DC96D69867A219ULL, 
            0x8B73B575FFA53EE5ULL, 0x08DB70DEC8A0E8ECULL, 0x017E6766582DEFA1ULL, 0x47008B5AE8F290B5ULL, 
            0xBB3AC7FF1B67D32BULL, 0xAF4DBAD9082A2F9BULL, 0x4FB4E672CDCDAFC0ULL, 0xE070F01337EAB40CULL, 
            0xEF666A14C1E5CFDFULL, 0xD8C7CA6CD03EA56EULL, 0x96C903A28DB6C296ULL, 0x5B41C51325974ECFULL, 
            0x8C9446745A3D9C18ULL, 0xBB5885151DDC25D3ULL, 0xD4727B5643EDF55DULL, 0xC296DCF732135697ULL, 
            0x08B8516A8AF2FCFAULL, 0x026F9F286740E116ULL, 0x93A385830E07C8FBULL, 0x8B63D8C51A9A1CB6ULL, 
            0x4CB4D960B138ED95ULL, 0x1C88878A2F9F52E1ULL, 0x416CB7233ED60DB9ULL, 0x6938EB727458BA74ULL
        },
        {
            0xF3A388C0F6B8EF6BULL, 0xE382BECE1FD4248FULL, 0x7BE813B63A61E196ULL, 0x1C70947637551545ULL, 
            0xF10301BA19CE7293ULL, 0xC55A1DE06EDF715FULL, 0xF517871B568EF2F1ULL, 0xBE7934FC2F205FC9ULL, 
            0x0A6D70392B17044EULL, 0xEE6C35059384783EULL, 0x69B7B7116FFD5951ULL, 0xB42477ABDCB9CDFAULL, 
            0x5916A73C7FBC064BULL, 0x9183673162E6B664ULL, 0x9ED1CF3EF977CC43ULL, 0x3F58C3E4D570A0E7ULL, 
            0x9B9A762297B058B3ULL, 0xB45CB7D9FE0CA406ULL, 0x76EBC08646308201ULL, 0x0FBA7EB890D278D9ULL, 
            0xD6C5161881A8D582ULL, 0x1B10AF02ABF089A1ULL, 0x7755B317C1ED18BFULL, 0xFEA9199414B98234ULL, 
            0xDECCFC16227B9963ULL, 0x06E1C02D99253071ULL, 0x92FDE6E3D87E390AULL, 0xE7B71BD104A66887ULL, 
            0x2E505763BB1C750BULL, 0xEFBC604DC7A63374ULL, 0x798FE0125D38F1A9ULL, 0x5A4C1F9CADDB0C23ULL
        },
        {
            0xEF18886D2B70994BULL, 0x1A35D83318758541ULL, 0xF0A1BB7960BADE9DULL, 0x5A818056D3777C25ULL, 
            0xB1BC7DDC049136ADULL, 0xCA8CC652CDDF836DULL, 0xB12C6470472D489BULL, 0x19687F085E80C116ULL, 
            0x5E950885283B00FBULL, 0xF89CEE945CB009D6ULL, 0x9673FC4D887CE8E9ULL, 0x63CBBDF5F9044EBDULL, 
            0xD87597A25021ACEBULL, 0xEAE605B1B57EDDCDULL, 0xECC11623BF380346ULL, 0xFD8F7610C8903F9AULL, 
            0x5D63EB797EA3FBF4ULL, 0xB66BED7F1D7FB8DFULL, 0xD7194D0E1211B9A3ULL, 0x93B382F85A074A75ULL, 
            0x5860F8D2A157D74EULL, 0x8007C5BA57CD2F56ULL, 0xEF9271C909051CC6ULL, 0x9E618DC64FBE0312ULL, 
            0x7411D8E56424051AULL, 0xF3508E942B91660DULL, 0x2CBA333947A7B77AULL, 0x99D07D56E2FED12DULL, 
            0xE329C15A25E5AA80ULL, 0xB8818A18BAF509ACULL, 0x1D68A68749886694ULL, 0x682647F759E6A462ULL
        }
    },
    {
        {
            0x30DF5601E015EBCCULL, 0xF7BA34151BB88FFBULL, 0x80D99485900D23C5ULL, 0x2B460FC8A483BD68ULL, 
            0x4BD47269A2E591D4ULL, 0x094FD6FE382C11FAULL, 0x88BBDE1CF7B94194ULL, 0xB7DECF5E18CF77A5ULL, 
            0xF92DF98A0D1016A7ULL, 0xA5B366AB1CA2EE5AULL, 0x6BEF3AE0045B60A3ULL, 0x222FAD0B7A672B48ULL, 
            0x2AA6875E35DE2141ULL, 0x8022006422246894ULL, 0xD270BFA4C3FFCD63ULL, 0x466C5AD510EF9AC1ULL, 
            0x6B3DB92D3AC235E5ULL, 0x6008CE1EEBBACEEEULL, 0xE0682A469B5FF65CULL, 0x398AEB19D69EF432ULL, 
            0x2B049F92B54E8563ULL, 0x7D8BA0527399DBB4ULL, 0xC422013670B111A8ULL, 0xAE77F741DD24038CULL, 
            0xD82072541D2B916DULL, 0x3FCACFA4581A7C0DULL, 0x0F696B9C01943C26ULL, 0x2B8A69B4546E24B3ULL, 
            0xA032B52AAA7AA52EULL, 0x401DD6CE95D83E2CULL, 0xB5302364C7D305C6ULL, 0x262484EE5BDAC906ULL
        },
        {
            0x08E58003CB7E3335ULL, 0xFC9744D908809E2CULL, 0x1A01704FA116572FULL, 0xEE5FD8A62F43461FULL, 
            0x444BBCFA0C74744AULL, 0xFC1F3BEC0C1CA9FCULL, 0x70A189E80955F9C8ULL, 0xF309A8AE9CA99600ULL, 
            0xEC86485C06F63B43ULL, 0xF120C1FF9D289090ULL, 0x891D12736880D4B2ULL, 0x784D2A93A4BB2E7DULL, 
            0x769A3F068C9043B6ULL, 0x1ABC61776F3A5FD5ULL, 0x0B9063360047C0EAULL, 0xEC0C7838E47DC040ULL, 
            0xC029C26AFD949BA6ULL, 0x5CDA292E0D56CB1EULL, 0xA8CE8E5925C573C1ULL, 0xF08FF1CF718BEAA7ULL, 
            0x3D14F006CC14FC6CULL, 0xFDEA539C26E58579ULL, 0x0B253B35948F4A25ULL, 0xD68F6FF06BA1ECC1ULL, 
            0x2FCFDA5D77E0A802ULL, 0x0722367320203BAFULL, 0x44DF76985969E2A6ULL, 0xAFC6615DECEB4AA0ULL, 
            0xFEBADB409F5BCDECULL, 0xCA26D1537895EE88ULL, 0x76817BC5E310C161ULL, 0x0FDB79A19813683FULL
        },
        {
            0x0512316B4055F5ABULL, 0xAF26947CD8E120F0ULL, 0x9A8AD99ED33CA5EFULL, 0xCBE9102F968E0868ULL, 
            0x436D6597D3709540ULL, 0xC8245F47DD398E68ULL, 0x6E789BB9EFE9D270ULL, 0x841CEF604F80E051ULL, 
            0x8CA94F555FF104D8ULL, 0xE6F0CCEACC8B76FDULL, 0x638AE63FEC715DC1ULL, 0x31956993B9229AC2ULL, 
            0x2E7E5CA19E47FFEFULL, 0xD3CE88FF11F652D3ULL, 0x3FE738CD85EF3C4DULL, 0x27CC1E86C972FD18ULL, 
            0xACD96800291F923AULL, 0x15572628AB8A1A47ULL, 0x2515D8D41E79AAE2ULL, 0xC3F2CDF2AF56AE42ULL, 
            0x9DE864BF2F75D116ULL, 0x6B1AA23C96FBC9F0ULL, 0x198B7CAAED0500D8ULL, 0x731A86741FC6AE20ULL, 
            0x30CDEA6D585D1BD1ULL, 0x60354030A69BDC1CULL, 0xCCF48FF0BF37172EULL, 0xD13ECE19778E0C92ULL, 
            0x14709E9DBAF0AD0FULL, 0x0EAF06F28DF6AD46ULL, 0x9EF59B52290E9F08ULL, 0x2343870AD5EC653FULL
        },
        {
            0x8A8B43D2234D14D7ULL, 0x50771A53DDA8566FULL, 0xCC641F640C215A9FULL, 0x34C762EC540B9EB7ULL, 
            0x215EAD6901F23B21ULL, 0x92169688149C3814ULL, 0x599C852403386C3CULL, 0x5F3EE9E8FFBB0D6EULL, 
            0xC585916C9FA23CB1ULL, 0x88CAE5DF846479FDULL, 0x0E962AD96E2F228BULL, 0x3481525869FFC918ULL, 
            0x9C456995068F7873ULL, 0x8E22769D17EF6592ULL, 0x3DFDB05C4602D323ULL, 0x5DDAF889C6309CC3ULL, 
            0x4D5D9D39ED55666EULL, 0xF11EA4ACC0A731E2ULL, 0x2904B5DDFCC95521ULL, 0xAFADC2AE29FC19AAULL, 
            0x7D96B985A18D4511ULL, 0x00B505F012EFF0AAULL, 0xAEEEB4D890BF1523ULL, 0xB44208BF9C5C85A6ULL, 
            0x40F3C159F4E7459EULL, 0x1A6BB342DE7423B9ULL, 0x8716959A8EF345C7ULL, 0xC7729AB02AAE0C0DULL, 
            0x5D042A3CCF3F915DULL, 0xCEC71603F4E6EE90ULL, 0xE277817342BEAF17ULL, 0x7855768676C32A08ULL
        },
        {
            0x8B676622FD4A46CAULL, 0x084783F9035EF54BULL, 0xC518C4E8F65B899AULL, 0x522C93BD9DEE4328ULL, 
            0x78DDF795B8A25FC7ULL, 0x07B8CBF20F96B94DULL, 0x8B5884ACE7E0D30BULL, 0x688134E4757E7E0AULL, 
            0x4A4C989320C76565ULL, 0x39EB1EAAC9C699A8ULL, 0xEEBB17E0306FD191ULL, 0x986FDFFF965FF653ULL, 
            0xAD3BA8C948BA7CE0ULL, 0x4EA9F0469DB3A192ULL, 0xAC855D1C480D5498ULL, 0x18C77DDF6F98B471ULL, 
            0x9CD657E538C9D2F1ULL, 0x0AF8F57B6516D55EULL, 0xC66DAF674D0B6412ULL, 0xD4C983DA2DA064BDULL, 
            0x1A027D78E7ACA361ULL, 0xE19E7C844A8AA779ULL, 0x176230D517327460ULL, 0xF1FBE1085DE839B0ULL, 
            0x1E98E0EE9CE5FD98ULL, 0x360AB647C04EE7F4ULL, 0xDB667B5AC161334AULL, 0x8FAADF5C1C9E0E13ULL, 
            0x139BE185F7B3978FULL, 0x4A6A28478CE00F35ULL, 0x4195A31886983CCCULL, 0x4D4E3825CBC027B1ULL
        },
        {
            0x7668AEB2D256B56FULL, 0x634CAEAD078C5692ULL, 0xB632FAA9DC9411E7ULL, 0x775CAA588632F03EULL, 
            0x1958C87D81A5924DULL, 0x8E0388EBAE332463ULL, 0x1E0E3DB0ED4732CFULL, 0x558AFB4830145DCDULL, 
            0x8397AFC162018649ULL, 0x5500FB09396C1340ULL, 0xEF4038A6BD6A97E9ULL, 0x8A8A5825206828B3ULL, 
            0x82F82735574F9088ULL, 0x91507A7841EDFA9DULL, 0x1260FEFD44CF836BULL, 0x3FE182775405D362ULL, 
            0xC2427D73D97ABCADULL, 0x50FE6C1065093F25ULL, 0xF1DD144794A01555ULL, 0x1F5652BD3FE20CE3ULL, 
            0x3325F2CCEA11234CULL, 0x92767255B2A1FCBEULL, 0x621DDD7EE9FD77CDULL, 0x2ABD909D11F8F11FULL, 
            0x2F4EA52054FB3FFFULL, 0xE047C5D730EB42A2ULL, 0x5B249ABE05A44015ULL, 0x0CFC02FDB7596ED5ULL, 
            0xE4F8DF4863657404ULL, 0x3DB48C09DA7E733EULL, 0x6DD0136E92610C15ULL, 0x656C4DE2EAF99F60ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseFConstants = {
    0xE92558D82EBCCF3DULL,
    0xCB0D153BA7561733ULL,
    0x4DB185C4914C9BB8ULL,
    0xE92558D82EBCCF3DULL,
    0xCB0D153BA7561733ULL,
    0x4DB185C4914C9BB8ULL,
    0x22DC25392FD3BC75ULL,
    0x7C537F29DCADD9A1ULL,
    0xA3,
    0x31,
    0xF6,
    0x38,
    0x92,
    0xA8,
    0x6A,
    0xC3
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseGSalts = {
    {
        {
            0xE92BD5DC8071694FULL, 0x6EE2664D4EA3C587ULL, 0x45CFC4CD96824655ULL, 0x9393623F66951ACFULL, 
            0xB20240A7A0053B3BULL, 0xA928B56A7E2699C4ULL, 0x080F473EC64D9250ULL, 0x4E2B29B3F972FA08ULL, 
            0x9647D45052C08D95ULL, 0x0AEF9086790AA59CULL, 0x15ADE77FBD5420E3ULL, 0xE818F3E3EE90E9D3ULL, 
            0xBF6387F97C269BDFULL, 0xDBF9A37A2DCF7111ULL, 0x43F1208BD8BE5A14ULL, 0xFFAF882B1D5C18CDULL, 
            0x8E94B0BA63376C78ULL, 0x063DAD72E0EBA7C4ULL, 0xABDCE4555FE7E23AULL, 0x77D2DB96682B967AULL, 
            0x40309773C1BF0958ULL, 0x834FAAC7BCEA4583ULL, 0x19B5E95A11330AA7ULL, 0x1B291C72BEB810FBULL, 
            0x1A6B6A17DAA5A9CAULL, 0x53F3524444AEBF42ULL, 0x6CBA39084E100C28ULL, 0xE2CF5287199AF782ULL, 
            0x6A172207D1698A4AULL, 0x2CD89798136DCD27ULL, 0x3DA013309284EC20ULL, 0xA6836B45F102D54CULL
        },
        {
            0x209BE45EB5EC9BDCULL, 0x399499AC171E3915ULL, 0x529908D6DF24A371ULL, 0xF003AFC622119713ULL, 
            0xBDB11646EDFE16EDULL, 0xD8611E50A03D2D37ULL, 0x66D504CBAF21FF32ULL, 0xF0D9DB0BEA709A2AULL, 
            0xA9CBA2FCAC1118DCULL, 0xBA0DE42ABAE710AEULL, 0x100912C170DCB7DFULL, 0x4ACFF3A722D6E4CDULL, 
            0x2A8145A4AD61CB73ULL, 0xB6DE9289923A7AB2ULL, 0x95EE6C69074EC987ULL, 0x8F989429E2C672AFULL, 
            0x6C2F417FC277BD93ULL, 0xAAF422835F53D3BAULL, 0x3AB9671F1EA9A149ULL, 0x3387AFE8B5B2BB69ULL, 
            0x68F1553B2265770EULL, 0x68CC965EC45409FFULL, 0x7C3FFE42596A668BULL, 0x7DDD9F60CFC8CF3AULL, 
            0x3FE2E39B9EAECDB8ULL, 0xC290591C8378833CULL, 0x79EEC8C26AC23684ULL, 0x0D61DB90CF7C27FBULL, 
            0xC5893A530DDF6320ULL, 0x1B6121B64C0A6E06ULL, 0xFA9F5C33B6808264ULL, 0x10AE0C745D49E09DULL
        },
        {
            0xD58C0B43DA409C8EULL, 0xB87DB2A6B585D3F7ULL, 0x10DD8E423C08E31EULL, 0xFC5127AD8CA8F43EULL, 
            0xC278705B186571C5ULL, 0x8E5EB35144F6FFBAULL, 0x46B2F431018DF2C7ULL, 0x948759B4EE5BBD11ULL, 
            0xCC7B3EB0307F921DULL, 0x2F92A2B95CD89D04ULL, 0x63D351058D943E53ULL, 0x24EE7A62B588D5D4ULL, 
            0x62C9C546FE2FA5CBULL, 0xADD4704BB1F4D4C8ULL, 0x26BA5D6C85C1234AULL, 0x31551D97D3C4E059ULL, 
            0xB6EC63A64BD244B9ULL, 0xE7976498673D31D6ULL, 0x8C230BBFF2DC97B7ULL, 0x9928F125DF7D9762ULL, 
            0xC392C781661C3C10ULL, 0xE424EAB6B5F812A4ULL, 0xA519838D28003AF3ULL, 0xA180B23F543CDBC1ULL, 
            0xECEED0E1E4CCDF8BULL, 0xA13815154B06A68DULL, 0xD018B9B970E8DAFAULL, 0x60B7F519312D586DULL, 
            0x63AB8D7985C0FC2EULL, 0xF8570854FF32DE85ULL, 0x240EEA41F03AE444ULL, 0xCA55CC024423652AULL
        },
        {
            0xE1649AAC33014F22ULL, 0x62DDC0F67A15A0DFULL, 0x2DA2100613BCCE8DULL, 0x52AFC188FDB9F862ULL, 
            0x88CBAD1A9553EC1DULL, 0x1E3193C9108A2626ULL, 0x6DF42B052D08CD1EULL, 0x813851ED6AA7A546ULL, 
            0x88F70EEAFAE3C8E9ULL, 0x803BBB99394F30C5ULL, 0x8584A0EF140EF5AEULL, 0xF4E17B0655354DD2ULL, 
            0x745CEA49FAC8C275ULL, 0x9740AF8F89639E1CULL, 0x2A5A2CF8637CF7F9ULL, 0x6BE83A7DB49EC599ULL, 
            0xCD8AA53AC890D44EULL, 0x2CAD60A74FD4451DULL, 0x4813C74C73A2AFD7ULL, 0xBC6C24C6B5DD6FE4ULL, 
            0x49EE2B5FF8E518DCULL, 0x14170D3C04CADB39ULL, 0xB071FF14814F098CULL, 0x81592A20166E91D3ULL, 
            0x5B647950786E1404ULL, 0x7AB74ED5A8B7C930ULL, 0x5923BC8569937AB8ULL, 0xA567BC36950709E9ULL, 
            0x1214326B2523AF7DULL, 0x0D98977335B8D1FBULL, 0xA4A885AAD45275FEULL, 0xDFA489AFB17748CDULL
        },
        {
            0x4B8BE8F108D12E95ULL, 0x9DA62086A334EC47ULL, 0xA0EC59608D9A14D2ULL, 0x8A087F0CE6D64BD5ULL, 
            0x6C9783C530DEA6FAULL, 0xE86AF1EA6768F270ULL, 0xE3DDC805264428BBULL, 0xCB549E2A1F212AA8ULL, 
            0x314D329DC7D54788ULL, 0x61514F7413D72489ULL, 0x9ECEF46D02645A49ULL, 0xB36D16FBE3CBC05FULL, 
            0x6CD836DF85229163ULL, 0xB79FD24D13D833D8ULL, 0x2B28A480F9AB5C29ULL, 0x391C9D749663954BULL, 
            0xCD3F6911398D3B40ULL, 0x0170A19D83B360C6ULL, 0x52187088048FD39CULL, 0x874EB67356291681ULL, 
            0x7B6B819C1304CA34ULL, 0xFFCEB20AF77AE3FFULL, 0xD45A30D212CC6777ULL, 0x81027728E57D9036ULL, 
            0xCB63A28458DE9FABULL, 0xCECD990BA072383DULL, 0x885B06CD8732585CULL, 0x8EA6800147A89F94ULL, 
            0x502B7B47FFB6F2C9ULL, 0x384C01A11EB53366ULL, 0xACC28DA8C27DF2DAULL, 0xEF25A2BEA1096022ULL
        },
        {
            0xCBCD8BC1C09C1853ULL, 0xF4A3169FD7CA1B48ULL, 0xEF53C3D0A4F81307ULL, 0x5538C4CA2A8A8534ULL, 
            0x0E3EB5938E4E1374ULL, 0xE090A788E505E075ULL, 0xDA4C1E65D2160253ULL, 0x1E31072015F5E203ULL, 
            0xB7B67B793362A2A8ULL, 0xFDE80E41623F6C05ULL, 0x175EAA00301B525BULL, 0xED34552C5B2C1503ULL, 
            0x68B9187C5C86C422ULL, 0x6E0B807BE419C965ULL, 0xEDA4D313A6FDC191ULL, 0x1CE4713732C006D9ULL, 
            0xCB7694E398CBBE92ULL, 0x04D6269291AB3E1EULL, 0xF2291CA610002E9EULL, 0x3FEF49E9520EA212ULL, 
            0x265B28E9D999D9A5ULL, 0x84B6CAEF3708AC53ULL, 0x3825168874C7FE04ULL, 0x1689EEAE7E7AECF4ULL, 
            0xA74A30583A849D93ULL, 0x1A94BFACC9D620BCULL, 0xA7BFDA9AE855A18AULL, 0x3E03A28AE4AB2FDEULL, 
            0x7A567A08C4F426F8ULL, 0x98CDE7F19B263750ULL, 0x74B264C3D8A0B6CCULL, 0xAAFDCBB64664A8F1ULL
        }
    },
    {
        {
            0x6F0D8D16E9CEC097ULL, 0xC2174F87F7874AE2ULL, 0x2672AC9EC6D9589BULL, 0xCCC59AEA94CC43F5ULL, 
            0x194B2B17CCAA6CA0ULL, 0xE829A4A0C7825A44ULL, 0x4F83310B56E2C0EEULL, 0x7E8583AC764E69D8ULL, 
            0xCA0F7DBF154391A4ULL, 0x8E6CAE0260B32951ULL, 0x07D3667D19036EC4ULL, 0xB31CA8AD640D6045ULL, 
            0x0EE177C75B90643DULL, 0x2BBD32CA97390468ULL, 0x92C5EC71207DE01BULL, 0xA8CBFD0ED253D39EULL, 
            0x9B84EA93C2CEB016ULL, 0xE57AA1954412FD8CULL, 0x24BE894E31414236ULL, 0x5647748CDC030D86ULL, 
            0x62F99364755DDE85ULL, 0xCECF97F90A7D0771ULL, 0x9AA36A3CBABD0A48ULL, 0xC6052144E10D779DULL, 
            0x9886890470341FACULL, 0x1D4B4413CF6659AEULL, 0xB505D88DEC56605DULL, 0xE43B5B2B3CAF3B95ULL, 
            0x5B54A229CA2A1F1FULL, 0xF983438052A547AFULL, 0x2AA2A453E9C28B64ULL, 0x2483745417662BC4ULL
        },
        {
            0x8D00C672E338DB59ULL, 0x2C832A8CEDFB940FULL, 0x2D414E95410517ECULL, 0x6AD9A21B672893AAULL, 
            0x444F79842BE4DEB9ULL, 0x3BE901740E15FB7BULL, 0x47D72261747106BDULL, 0x17C51459D083D1A7ULL, 
            0x20832B1694768A26ULL, 0x1BA60C0C54DCD0FAULL, 0x445CA1E616AFD2D1ULL, 0x4C56726B4DDA4561ULL, 
            0xB11147C281F776B4ULL, 0x9D6D092E4F93F024ULL, 0x5B939CCEA6A04F3DULL, 0x66B007A90B05B637ULL, 
            0x28CB2F62BB065B37ULL, 0x9461F3C65BC8282DULL, 0x1E4CC69E06BAD2FCULL, 0x581559C9CD5EC1F1ULL, 
            0x0C5AA3E320B4CDC8ULL, 0xC400C1A99FD653B9ULL, 0x21F41469F0B321C3ULL, 0xDEEABFB116551B02ULL, 
            0x08D5C0EA69AF24A1ULL, 0x8E768860E1595274ULL, 0xFE9822697A31587AULL, 0xE7935D86807B07EEULL, 
            0xA83173D4A9562C4EULL, 0xD4831CB822AE72B1ULL, 0xE7515C446180A7CCULL, 0xE0A2AD2E5F9A2263ULL
        },
        {
            0xF505A2642731F364ULL, 0x49CC5559D9F0243CULL, 0x567B762486DAB2E1ULL, 0xD8316AD952F7010EULL, 
            0x79191E993EFCA066ULL, 0x82047B6023B5F90EULL, 0x28728AFBCE10B71CULL, 0xDE6BFDF6C4499AADULL, 
            0x9F83E50A8DE71D10ULL, 0x775242821F772BD9ULL, 0xE387CAE022D5F493ULL, 0xCB871861D3E267C3ULL, 
            0x643B34CBF21803ABULL, 0xA4412908C54FE310ULL, 0xA65C486133CE19ADULL, 0x7F5B0409B38B6FF6ULL, 
            0x0F2FAD77E093DA24ULL, 0x31D6254765EBCBC7ULL, 0x47FFFA8094216425ULL, 0x26F8C56CA3643BF4ULL, 
            0xC593EF11B54581BDULL, 0xA6B0E7EA6C6C7DD6ULL, 0xD5C6557D4DC88433ULL, 0xB6DA166C859196E3ULL, 
            0xE7F857E3E89D2BB1ULL, 0xB769E56EC9B41CF0ULL, 0x5280252E3D2BD3DEULL, 0xD9C37DD00F399956ULL, 
            0xD5C94492A66A4750ULL, 0xACC2B01329EFF186ULL, 0x21AFF2EA845D75FCULL, 0x606049E04BBF14CAULL
        },
        {
            0x69BD9FA0A3B15265ULL, 0xF5DFE58658E5754CULL, 0x3E7F466EC65CBF96ULL, 0x846DA05D9236B5CFULL, 
            0x57225CAAA1D2EA5EULL, 0x5E7E7E358EEC9B85ULL, 0x51AACB95A208C5E2ULL, 0xC7C8DC44847F3468ULL, 
            0xA1B95B07051F518AULL, 0xBBDCB473D89C752FULL, 0xB226ED2F54AC976EULL, 0x20746D9B0B0EFD40ULL, 
            0xF140996E06A86629ULL, 0x83FB4A8B1BB63ED2ULL, 0xA001A6E5DA696072ULL, 0x7DACDDC216EA8E9EULL, 
            0x88265AB86E3A7CC2ULL, 0xBAD900385775F491ULL, 0x4F8460202DF29946ULL, 0x9E38C2E2DDCDF0C8ULL, 
            0x4B595B9881A4FF5EULL, 0xF0E88588C114B48BULL, 0xC5C06F717F614D61ULL, 0x0AFA70926F71F318ULL, 
            0x06AB4C979CD514EDULL, 0xF1D8D262400F2E3DULL, 0xB39770E9EECF2C01ULL, 0x267211625B565468ULL, 
            0x5489A16642E7A35EULL, 0xEF4C1A0F7755F7ABULL, 0x94EE077B341E16A9ULL, 0x2B95B35D6CF53257ULL
        },
        {
            0x9984F96BED344DCCULL, 0x7B01B9B18B617F0DULL, 0x3AF9B4812218F67EULL, 0x4FEF7CC30C60D69AULL, 
            0x2E75FABBC7F05239ULL, 0xCF368BC869790129ULL, 0x99EB785630A69834ULL, 0x4010591430982095ULL, 
            0xCA9760678E3A861BULL, 0x6329BBDF7A25ABD9ULL, 0x3166D45A7173A846ULL, 0x9F7EFE9FB22AF61CULL, 
            0x4074BA0CA0E3DA65ULL, 0x5B36D74BB4A11CF6ULL, 0x4C42BE58DF9BEF2DULL, 0x71330EC529585B6FULL, 
            0x0450C8C14B25E7A7ULL, 0xC3FB17ACF98F8106ULL, 0xE4DA530C28980530ULL, 0x9D81EC729839B53CULL, 
            0xF3858393023EC2E7ULL, 0x35F3D4683D183395ULL, 0x1C491EFF5CF554C4ULL, 0xC7F81EEBD85CC713ULL, 
            0x04369E4A356437C9ULL, 0x9BB45CA2CB356EF6ULL, 0x036DF4A7BC3259C8ULL, 0x73F9A390EF1371CFULL, 
            0x0660ACE3531641E2ULL, 0xAEBCDAC9B3CCEB6FULL, 0xA020F1E69E446FA8ULL, 0xD770347D38B532C5ULL
        },
        {
            0xDA477F6DF5AA991BULL, 0xB26E0B8C3CB76592ULL, 0xA30949BD21A7163CULL, 0xB82C5EB05D8B5ECAULL, 
            0x6474DF50A1704619ULL, 0x8F1458A7C56E6363ULL, 0x9194F0D4D592FA47ULL, 0x1DB1634B78FB8354ULL, 
            0xC47ABF19CEE428B0ULL, 0x5A4722B4943AD749ULL, 0x367B67B29579062BULL, 0x7647D5A2FAF633AFULL, 
            0x4F93E499F0AC5FFCULL, 0xE84DFB9246D90948ULL, 0x03DC07E75244C535ULL, 0xE754E0275AE01231ULL, 
            0xB592D4D60FC68532ULL, 0xA9695536159880DBULL, 0x2D6886557BD894DDULL, 0x85BFC7E972D7A573ULL, 
            0xCF277B0409F435B5ULL, 0x7E764B0777CD2B6FULL, 0x7892B41B9989B717ULL, 0xCCCCA967DCD0F714ULL, 
            0x7C0CC51FA5F83815ULL, 0xDD3D065E5E91E6B8ULL, 0xCBDCFF657F4CB84BULL, 0x0AED3F231BBC1A4FULL, 
            0x3F34057A84A62A1CULL, 0xBE77B3EACB883B22ULL, 0x872A4C585ABC9985ULL, 0x8D3B71E168C99E20ULL
        }
    },
    {
        {
            0x57E378FB0C97EB1AULL, 0x4A1654B2436EBFD9ULL, 0xFCEEF577396D6C9CULL, 0xF19BCE38F9EA229DULL, 
            0xC1F1F232D3456251ULL, 0x0C796D942FA8500CULL, 0x712D5F9294B51315ULL, 0x622B59010DAD0F5CULL, 
            0x5F646704EEE1C332ULL, 0xF2B434E4B257996DULL, 0x005750CAB774AF56ULL, 0xAE80C38B2773FD96ULL, 
            0x7169734BF0E57DF1ULL, 0x5B9B072AF96F05A5ULL, 0x77999C2DE60D1959ULL, 0x9D110F81B1E889F1ULL, 
            0x16C61AA85556E989ULL, 0x16461D7999379E9EULL, 0x2BBB74E234B52CE9ULL, 0xE3EAD2A39A95472AULL, 
            0xBE697FA06D45917DULL, 0x36A62ED93013B8C9ULL, 0x05C36D834AD2F2DDULL, 0x00DF487D9C739FC1ULL, 
            0xC54C29B8827588C6ULL, 0xF8A7CAF7C1C977EFULL, 0x95C18618CFF1C218ULL, 0xA622491581C661BEULL, 
            0x8418E072E747E646ULL, 0xB1CE3B1178E824FDULL, 0xB28955AECBD05821ULL, 0xFEF9E2A21B5DF3CAULL
        },
        {
            0xAFC30874468D53B2ULL, 0x611242324134E187ULL, 0x56DE06F364D30146ULL, 0x62073F03A9755627ULL, 
            0xEA3B503BAB5CA173ULL, 0x1F67B6C2A8BCB794ULL, 0xF69D2E6D87778614ULL, 0x4CD8CB2FFC140AD2ULL, 
            0x45B3C4567D25D5A9ULL, 0x4F9DB2D033C7191BULL, 0x0A5CFB89AFEAE67DULL, 0x72F6B3F86EE29493ULL, 
            0x4D8C658DF904DF4EULL, 0xDB3F0DB935589303ULL, 0x082931B8675BC462ULL, 0x7383C90C1DE80847ULL, 
            0xDB769B12B1E51AC8ULL, 0x353863709D2CC16FULL, 0xA664AF8D1502627DULL, 0x52E92DC89BA9AA7BULL, 
            0xE55843B41BA08B83ULL, 0xC02EA364B7178DC1ULL, 0xFF3D5D1EA1D9C3EFULL, 0xE7A540DF176B2D2CULL, 
            0xDC231AFB611B7904ULL, 0x9C111851F068C6C9ULL, 0x4C04C6DB76122B1FULL, 0xC73452D64E0A11A8ULL, 
            0x7C1C267D5D4F2E96ULL, 0xC66A8D25C21C84FEULL, 0x734361B7A21C41E1ULL, 0x0B4B55B7C996E4C4ULL
        },
        {
            0xAFBB91B4D4E06B2CULL, 0x6D1D8DC44EEE2B10ULL, 0x620C35B76E273EE3ULL, 0xEFB78BFA21656DADULL, 
            0xF62132EC82F6BAA3ULL, 0xC9E2C3A7B257198EULL, 0x420ADB5E73ED214FULL, 0x8367D872781D1962ULL, 
            0x5E03510CCD4A3B21ULL, 0xD6A900C62CAB014BULL, 0xE3F2C64ACB7B54E8ULL, 0x2DDF5B93A46D1AB1ULL, 
            0x784FE639F89EDA12ULL, 0xEC3DB753820692C3ULL, 0x2AEBC109E41414B9ULL, 0xA6EF24B48E0E44DCULL, 
            0x5B94A6275DF72075ULL, 0xF66C6190956A2233ULL, 0x7C2C842E96CD6594ULL, 0xB551181CCCDC9D9FULL, 
            0xA1F5F600DF0F6545ULL, 0x2F5BB9E27E36AE56ULL, 0x66A79C95A0575F78ULL, 0x2A51DD43E2B72DDEULL, 
            0x85FCC3D7ACB9E209ULL, 0x2ECB092BC8038E5AULL, 0xB49A9CBBDABDEC2AULL, 0xF9657D813E05529EULL, 
            0xAE0640901181355FULL, 0x0C9A4EA79234B307ULL, 0x8970686AB3963D08ULL, 0xB214343E5AFCF3B8ULL
        },
        {
            0xFFE00F53EED11F68ULL, 0x20BDAF46B37C3062ULL, 0x986EA7E2755F440BULL, 0xCD062ACDD216D703ULL, 
            0x274C02850DBB2140ULL, 0x34DCB76641567541ULL, 0xC614CB6A8500EBB8ULL, 0x8EA3023B4C72A015ULL, 
            0x25F29B4E779122CBULL, 0xB1A55D59CF27D3C7ULL, 0x739FB47E6BF861D3ULL, 0x8A0B46C0156284EFULL, 
            0x02F88756FA8ADDD9ULL, 0xC3694F763C39D7AAULL, 0x70ADB124F7487C0FULL, 0x59D77D0E98214AF7ULL, 
            0x8B8FAAC26B72FDA6ULL, 0x4B5E3E894530100AULL, 0x0BD89D4FEB18890FULL, 0x112D537AEA7DA61BULL, 
            0xED8806BD6AD51ADCULL, 0x1FB2D39C64BBF791ULL, 0x1610F71C0F9C092CULL, 0x840A3E40642D84ACULL, 
            0x546841B46C889A94ULL, 0xAD15C2678B6476E2ULL, 0xBD169C5C2FE84F55ULL, 0xBBDE83B834AA8530ULL, 
            0x20BA87F4EE6A3E15ULL, 0xAD0AF3EB3F484201ULL, 0x83FDD414F708029CULL, 0xE7C399D8636FA3DAULL
        },
        {
            0x631FC2CDE30BDEFEULL, 0x93CA704E91A52310ULL, 0x1C3FA0922E5ACF2EULL, 0x4E7B020E5D7F19F3ULL, 
            0xCF5747B5C1A46C72ULL, 0x4CDFFC73843EAA44ULL, 0xDABDC0804F1F8FE1ULL, 0x6E2A13EDD7928821ULL, 
            0x5880EE7112E806F6ULL, 0xBF9ADD2AF286F014ULL, 0xDF40C76B72C93946ULL, 0xB2FF0C6ECD3B3A00ULL, 
            0x91EBD35C01804833ULL, 0xC72C8BC0E23A6C19ULL, 0x7B74531E031B7CD9ULL, 0xD8CF9273B229E36EULL, 
            0x10F68AF35E27F31AULL, 0x374EC241F7924E8AULL, 0x5214FFC28CECDF8EULL, 0x962F9ACF9C0E0BCFULL, 
            0x82D56A830FBB4499ULL, 0x5A8497FC7A38216BULL, 0x5412BC2068172EB3ULL, 0xD524782563D43D0BULL, 
            0x55E46C674FE2B8BEULL, 0xD5440A8D2EB16BB7ULL, 0x74A0AED45EE84722ULL, 0x515ED695E03C50E0ULL, 
            0x3D90789B829249BFULL, 0x1A05801C112FB976ULL, 0xF1BEA1E78AC26F56ULL, 0xE66CC8E745694978ULL
        },
        {
            0xA6F963755C163448ULL, 0x4228F123BBE456A3ULL, 0x9B4DBDEC2435D254ULL, 0x5D5BCBA63ADB08FAULL, 
            0x48C5C866904E6007ULL, 0x4A8611EB6DC8F0C2ULL, 0x0B41250F8237D259ULL, 0x5B251DCF286897CAULL, 
            0x81440EDEA0D53832ULL, 0x637A1DBB58137105ULL, 0x489C1468AFBD75EEULL, 0x84C717A43FEE4B5FULL, 
            0xEA8042FB1F1A815CULL, 0x927E6BB041858D53ULL, 0x882C6C2512721CC7ULL, 0x73A40FC5E935C5C6ULL, 
            0xF90C1D90E4DBBBC6ULL, 0xDE77773109DABE63ULL, 0xBCF6A0E12794D3AFULL, 0x40A5B66F7E658DC1ULL, 
            0xD1FCAB756EB1A391ULL, 0x70E5545E3C91ED48ULL, 0x527D9751E98F261DULL, 0xE401BA0BA6016E4AULL, 
            0xCFF1D8D97C6EC384ULL, 0x9F8A97FE3A56C1C5ULL, 0xED058AE5E23FBDD6ULL, 0xD663E5D7988D5DA7ULL, 
            0xD63A378140B354C6ULL, 0x468D0321D3DEA3D2ULL, 0xAE1F451D41E4E897ULL, 0x1D9F9D895E47E22DULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseGConstants = {
    0x529747DBBEEE9DFCULL,
    0x230AE852298E38E3ULL,
    0x0245B80C0390D5CFULL,
    0x529747DBBEEE9DFCULL,
    0x230AE852298E38E3ULL,
    0x0245B80C0390D5CFULL,
    0xA3E9C23B079A600CULL,
    0xFAC6103319EAD881ULL,
    0xE8,
    0x23,
    0xFA,
    0x13,
    0x36,
    0x75,
    0x9D,
    0xCD
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseHSalts = {
    {
        {
            0x0C7855CC6E0DCB9EULL, 0x8B5A983CE198BECAULL, 0x5C477FDB59800FC6ULL, 0x4B1AA37D5C94C7D2ULL, 
            0x63AF86665CE3CC79ULL, 0x68F57B534421F5DBULL, 0x5E2C84731633CCEEULL, 0x2A70BA6932B5BA80ULL, 
            0x1AE2736831930EFCULL, 0xBFF008D143D13761ULL, 0xFB153585B7437244ULL, 0xA5A72F8D2EC87AB0ULL, 
            0xE02D55C80B0A7DF5ULL, 0xBB149DF60130EDF4ULL, 0x35C4DCB22EF06870ULL, 0xE258D46BDFAA9086ULL, 
            0x0B329062D042E8A8ULL, 0xED19871DD5A56D24ULL, 0x4C0958EE91AE889AULL, 0x7AA5BFB9938C9BECULL, 
            0xC6FB43D65E235725ULL, 0xE6E78481EFE50097ULL, 0xB1C994F13CE0FDEEULL, 0x7E3508CBAA5F5E1BULL, 
            0xBB35AC36CBFA7462ULL, 0xC034CECDFA59E873ULL, 0x7A2B96450117F299ULL, 0xF3356116D49FBB6AULL, 
            0x9358B7FFAB626F10ULL, 0x86CB7066F416EA67ULL, 0x9779A6EAF21A5DBCULL, 0x439D97F1EB1FC1A1ULL
        },
        {
            0xB0D52BF517CD4FF1ULL, 0xA39426ADD828DD88ULL, 0x300496A04542A9B1ULL, 0xA2BB48E696DA31C6ULL, 
            0xD32BAE5BF45584CDULL, 0x19AE848F65A3D01CULL, 0x921586EFBE15BBA5ULL, 0x409BB2660178788CULL, 
            0x3091B862B64099E2ULL, 0xD70E096AE38E442AULL, 0x3CEDB7000D04E056ULL, 0x00951AB0A8A65B1FULL, 
            0x228AA2C2315EF89CULL, 0xCDFCEC943CA5BDF4ULL, 0x01DCA30F95EAEDDFULL, 0x291849A590ACFA45ULL, 
            0x475E4A3AE06FB673ULL, 0x72864ADDB62F69B1ULL, 0xF056950B234CB158ULL, 0xCF60013420E7DF9FULL, 
            0xA36DAE93BB6AA559ULL, 0x46B149772459CEE2ULL, 0x49E15389EA281440ULL, 0x45A6671E62424975ULL, 
            0x62033E4AAD68FDD6ULL, 0x4F37728114E52E47ULL, 0x25EA7D1EA580E499ULL, 0x77470657D7213918ULL, 
            0x5E2DD768768BDD0EULL, 0xB7756358AB569A2EULL, 0x8192F74DEF124957ULL, 0x3BC78FA8FE0440CEULL
        },
        {
            0x3E1735D10677EF71ULL, 0x79233284077CE0CCULL, 0xB474362635173369ULL, 0xF3A5A73788CEB8D1ULL, 
            0x58AA075C0AB01D82ULL, 0x88C2A91B4D530770ULL, 0x21B7769AB2C357FEULL, 0xF8852C1F2C90143DULL, 
            0xC5382F3A0B5C119FULL, 0xD02737404D65B854ULL, 0x94AAA5E186591C26ULL, 0x2431CA50DA072D7DULL, 
            0xB95ABF75D27F94D5ULL, 0x83E8257B4BAE3C5EULL, 0xC3229C380176B56DULL, 0xD18623E2FE05C65DULL, 
            0xA058F71473B07C90ULL, 0x15DDEE8823DBA247ULL, 0x59CDB0ACFAB6E244ULL, 0xBDA3257855F14104ULL, 
            0x695B6CC449890DC3ULL, 0x9E9688B3E4B96129ULL, 0x760E54FCFBBE6653ULL, 0x5961370EAEECCEC1ULL, 
            0x99C047F80FE78B6FULL, 0x5CADFBD235582FF7ULL, 0x1BF0F570E2E5130CULL, 0xE1C194861D5BB44BULL, 
            0xED7E52F66774BFD8ULL, 0xEC77B889D266B7E2ULL, 0x6D4C5775E5F0923BULL, 0x5A62679B84D991E5ULL
        },
        {
            0xF6C999F8951FE4D5ULL, 0x03B8B88F6A46937DULL, 0xB99F2B3EF05B2D0FULL, 0x06B34D4307E41AC7ULL, 
            0x1C6B791DC5D0F55EULL, 0x89C83870DD10E1FBULL, 0xD4B83AE2B6E3F47AULL, 0xA4B6570BA9C29D55ULL, 
            0xA5C9F5E76E4E4A9DULL, 0xBF00EB084CE55514ULL, 0xF8BB595675B00B5EULL, 0xDA84C2DDDDCCCBBAULL, 
            0x329DDCC009E0C54AULL, 0xE683FBE7902E3E6FULL, 0x3508CDE429A805ABULL, 0x16F317394B699400ULL, 
            0x9ECD60783E2D4F6DULL, 0xBF780FB77FAF4609ULL, 0x172B035297D00C6CULL, 0xC2301573CA75D368ULL, 
            0x556DB6765A01C2DAULL, 0xE5A39ECF2EB8F4D6ULL, 0xA4AEC5C3C996CC0CULL, 0x2DC05890A3D68D51ULL, 
            0xF56DB5D335FA6C50ULL, 0x49A3CF9BF1299C1FULL, 0xDF012F100B641751ULL, 0xABE488946126A828ULL, 
            0x26BA92F12808CBA3ULL, 0x3A2203E461261F38ULL, 0x5F89437FD56B63B1ULL, 0xEA3DD52ADF40FE0BULL
        },
        {
            0x3F22D8BA33B1BF5BULL, 0x38D74028D2570E02ULL, 0xE694AD267A93E0F0ULL, 0x098DA141330A66FDULL, 
            0x710CBE0B0B8D3DD9ULL, 0x6F5EE039F820C23FULL, 0x550AB34DB7DE4CA1ULL, 0x34F48C0B3D2EF4FDULL, 
            0xF217F8FE56EB19E0ULL, 0xD2C8C9220560C639ULL, 0x2692457B69F13F78ULL, 0x7D05E82B3134A3DFULL, 
            0x76E0BD4C0353E629ULL, 0x60C2196756CC7822ULL, 0x634DD6F0E1F331CDULL, 0x4A6A5B283A7ECD97ULL, 
            0xCD2C5E4949220C03ULL, 0xF9DCDFE7D9CCE454ULL, 0x9353480F908520C1ULL, 0xBEF3812C20B87FA7ULL, 
            0x2B39D4593EBAF61BULL, 0x23F4E42CC99C1128ULL, 0x75577081B0A0321AULL, 0xEE6EF1496984C703ULL, 
            0x84B7613E884E686DULL, 0xF863576CC7E9335EULL, 0x83FF1C3E5C04347BULL, 0x8CC1C4250EDE72CCULL, 
            0x75AE237FD7E53C54ULL, 0x323D7F1946D61D65ULL, 0x3E4EAED8B763DBD1ULL, 0xE773E5E6D562D019ULL
        },
        {
            0xB6E72D53F0256495ULL, 0xCFBF01F76391AFA7ULL, 0x150854D650EB88E0ULL, 0x970DF430BFA50518ULL, 
            0x232428E8B83A6D9AULL, 0xE34B05A9A3546594ULL, 0x9EC04A8F66D8518AULL, 0xAFED41AB1CD5E490ULL, 
            0x7C2AECF4FE681503ULL, 0x3B5F4DA3AEF417E2ULL, 0x23F1B2478DC1C045ULL, 0x5101D7E390286F3CULL, 
            0x8FB3C340E76D0CFBULL, 0x130C083CFC305C6FULL, 0x706619E13B5B1470ULL, 0xF598AF811DA6C19CULL, 
            0x70B0BDAC9686EBDFULL, 0xD63F41B5930355BFULL, 0x8164ADE2F99B6777ULL, 0xC72BE166D717C825ULL, 
            0xEE7C6F2AAE0D2B14ULL, 0x2FDB2F8E64DE4A71ULL, 0x61D50D4D49B8E85EULL, 0x80F8812F20EA1B4CULL, 
            0x4E26B6E1D1525BCBULL, 0xC4F63F33B531AB85ULL, 0x4C7C29495B9762A5ULL, 0xE647A1CC0EAC14A5ULL, 
            0xEECE6D90FBC56D6DULL, 0x82CE9FE9A3153F51ULL, 0xB5D2CE784BE1D217ULL, 0x5E812EB09DA924A9ULL
        }
    },
    {
        {
            0xE46362D898E5D539ULL, 0xB44332A21226DD85ULL, 0x6955BBCDD4E90CECULL, 0xB51E337B9CB0FD7EULL, 
            0xC6B41E598B18FDAFULL, 0x26C82F4784375A1AULL, 0xA29AE8B87FA40726ULL, 0xAAA13ACE8A839314ULL, 
            0x02B39F520282AC95ULL, 0x281CC62A975FEBBBULL, 0x84E9A5D1872946D4ULL, 0xDB3F080FEE79A999ULL, 
            0x9465F38004041077ULL, 0xD6B728F44BC78B8CULL, 0xE7609BE726D03EBEULL, 0x8A4ED300165E20F6ULL, 
            0xD522D05907444BF0ULL, 0xBA20B4989E2CA807ULL, 0xB7ABD72CC1F1DB80ULL, 0xDE04E16D6C73F5AFULL, 
            0xB01733FCB97D0563ULL, 0x9AB247D255D44DC7ULL, 0x4B2337462728E669ULL, 0x4AA31743CCBE07F6ULL, 
            0x42BDE5F45F6B65F0ULL, 0x111687716D72C2A6ULL, 0xDCCB4D74A1363639ULL, 0x05F7536749B7821BULL, 
            0xF7BDBCC8EC2FD1ABULL, 0xF9E38B33B5BF8EBCULL, 0x71E62F20B16F5348ULL, 0x1F4C60C00C840C45ULL
        },
        {
            0x4FB70F71F0249F1CULL, 0xA95FD2FDA3BC9AB6ULL, 0x24EE4FB6EAEDF34FULL, 0xC8AD90495F88A07AULL, 
            0xA56CECE4948A67F3ULL, 0x15CAE08BA8FD9118ULL, 0x328945AD0321D01AULL, 0x56D83034F35E94ECULL, 
            0xC5C63F5CDF1D6615ULL, 0xE508D93618330226ULL, 0x62BDC3D739521316ULL, 0xEA52C6A1A056FA9EULL, 
            0x5EFF6BBF27C861E2ULL, 0x0D98D766B1AB5EB0ULL, 0x42CA2833ECC10958ULL, 0xFDAABEF0CA6AC2C3ULL, 
            0xA9B24F272EE1302FULL, 0x30E8F87A754C79EFULL, 0x16049F62376B106EULL, 0xCE4A7E6DAC84D9D0ULL, 
            0x49C52096998958B4ULL, 0xCE1A898D2F23951FULL, 0xCC8BA6ED1A5324F1ULL, 0x11D77CA234E4714BULL, 
            0x2FAFAB3B6673F218ULL, 0x8C6AB3D5FE556AF2ULL, 0x549924406C9A59AFULL, 0x985594D6629FAF79ULL, 
            0x2F982A7016677234ULL, 0x576123F5ABC10B80ULL, 0x5FBFFAEA31F708D6ULL, 0x01FEEA4D76A5CD01ULL
        },
        {
            0xD61DA66698B73535ULL, 0xF1989E1207091457ULL, 0xCD7D1CCAA5942236ULL, 0x86D9880C3ACE99FFULL, 
            0xD0E865684C69B7F1ULL, 0x23DB4D023E7AB52DULL, 0x5F213751CD5B1A12ULL, 0x3E3BA077A19E6BD4ULL, 
            0x7E18875DA9BD6B3DULL, 0x154F37B6B8ED6C9FULL, 0xA28777C8E9954382ULL, 0xB9BA259DC2251197ULL, 
            0xD284B92B806A8E4DULL, 0xFA1308178DAA6954ULL, 0xA32F0104F3454A59ULL, 0xB60D49946B46627BULL, 
            0xE369126D515BAFAAULL, 0xAC71CAA91E8BD3B1ULL, 0x47A480FF9128071FULL, 0xF0BDC0F66A6BF302ULL, 
            0x46EBD971268DE73DULL, 0x7B05031F644E7305ULL, 0x38636A664B44DE0DULL, 0x797343797EC65B58ULL, 
            0xF251F8BE41562D28ULL, 0x9AAE7FE3E57EA6CDULL, 0x371E79AEB82174FBULL, 0x4FD9B46F4CC7BEB7ULL, 
            0xFEB64ED5B679B488ULL, 0xE08988F0C9FDC63CULL, 0xCA0B31757710392CULL, 0x559DC00D845E70E9ULL
        },
        {
            0xA50446BDB462F5A4ULL, 0xBED041BE5B2D04ECULL, 0xB1A906808A33BED2ULL, 0x9D2F2176B39E0DA0ULL, 
            0xBC845D03920024DBULL, 0x56EAD1C48277F7C2ULL, 0x8B6AA41C0FA84ABEULL, 0xCEA189B56589C913ULL, 
            0xDAE15E53EEC569B8ULL, 0x9861AB9492316D1CULL, 0x311DEFAA835BE543ULL, 0x2B7A8FB4111E1D23ULL, 
            0x62891F27A8E80FBFULL, 0xC0E2E5D16A743CE2ULL, 0xC46A45AC74EFA11DULL, 0x5A8D48D4F28E6F80ULL, 
            0xAFB48AF4AFF121FCULL, 0x810985A953F5EDC7ULL, 0xB3A8CD0C693A4C25ULL, 0xC3EE9CCB4DD9F0A1ULL, 
            0x4A9B5D9E4566D76CULL, 0x7CECD44DEAD39B43ULL, 0xDE531D6087C38170ULL, 0x79C2632E229BCE6DULL, 
            0x7A064CF19AA62A1EULL, 0xAD0060DA3AFE061EULL, 0x08895025AC6C2C41ULL, 0x1B861DDDD5C9D24DULL, 
            0x7562D0BA9C068F98ULL, 0x3F48046F8FA71BF8ULL, 0xFC82C0D55072A6A1ULL, 0x66267085526BE9ECULL
        },
        {
            0xB63BB11416930FA1ULL, 0x81C8622399801B45ULL, 0x43356001B15A79B0ULL, 0x3FBEAEC8F4D04A40ULL, 
            0x0D4A6EAC17D8A1AAULL, 0x6B46B6B86726BE2CULL, 0xBC06FB8DF41DC6C6ULL, 0x04457EF479F8FAFDULL, 
            0xB3F261D74BE823C4ULL, 0x17512FF26D847D5AULL, 0x99CC08EB2545B08EULL, 0xE21F126AB9800FE5ULL, 
            0xFADA9452F05427D8ULL, 0xA7F03C85191EDD27ULL, 0x79D35F01E5ED85BBULL, 0x5C2C7CFCBBFA2905ULL, 
            0x0391C2C2227315C6ULL, 0xA233A1324ADB5816ULL, 0x417EA62867E750B1ULL, 0x3D5BFA682A3F6AE9ULL, 
            0x5B418A5DD80BCD49ULL, 0xA337364777411E37ULL, 0xFD696A7FC60CADA5ULL, 0xA95D6CF4B43DB3CBULL, 
            0xA57CDB1510F0E852ULL, 0x9C6E723E2FF0343FULL, 0x99A471E086074265ULL, 0x6967376886268E70ULL, 
            0x4A809B2F188AC581ULL, 0x66658BB1E562EB96ULL, 0xDCF74D54E2A456EFULL, 0xE2A27F2D432CD08AULL
        },
        {
            0xDF24D05C549AD27BULL, 0x53D3E0512DD49517ULL, 0x3FA4589D1B7FA11BULL, 0x8D88386BB7554D1EULL, 
            0x7C002DFF0148C093ULL, 0xDF3B69B70E138647ULL, 0x9EE8CFF8CD3C1142ULL, 0xB3C8861E3E41200EULL, 
            0x0E4EE831AC185587ULL, 0xA188AC49E91E5629ULL, 0x1942BE1361A5F66BULL, 0x34DBE3A216E53A89ULL, 
            0x7F1BC86C08C71E53ULL, 0xECD5ACB401B71E2FULL, 0x039B1B645E175B71ULL, 0x0C965C35C5896B8FULL, 
            0xBB70B32C034D1189ULL, 0x47F00F79CD7D6EF5ULL, 0x02B3A639D6A4C112ULL, 0xC6302F1D0282E9D2ULL, 
            0xA14498452A6ACFEBULL, 0xEB74F0E1F1FAA80BULL, 0x3F0BC8823281D669ULL, 0xB1A5D7F4FBA1C2D8ULL, 
            0x792FEBF8D545DC33ULL, 0xD3112FD57CC46AE6ULL, 0x6D15398D6ED8747AULL, 0xC28B85F477347254ULL, 
            0x8E927CFA8C5644E3ULL, 0xEE1B81C39FD75071ULL, 0xE3EB949B138E647EULL, 0x22A1C905C00D125EULL
        }
    },
    {
        {
            0xE1433DA7CED6DD28ULL, 0xB435CD10E0E2FF2AULL, 0x6D22CCF50C51EB2CULL, 0x77DCF1D3A0C72DEBULL, 
            0xD8DF96C18FA60E44ULL, 0xE132D30F38C7DED4ULL, 0xF9B3EB64F0CCC1A8ULL, 0x1EF815DE94B54653ULL, 
            0x0723FDCBCBE1DD10ULL, 0xF5084B799989EF72ULL, 0x53CB97B6EAC27E1BULL, 0x521FB8F03E37A08BULL, 
            0x2CFFC4E7A873D810ULL, 0x2FE605CCE10EA362ULL, 0x650D228ADCDC3217ULL, 0xEBDC4501CBD66F86ULL, 
            0x41F718B24400A1DFULL, 0x62845E873C5C860EULL, 0xF229BFE07ED2EBB7ULL, 0x117FF77B28DCA15DULL, 
            0xEE2E41B5137E2FECULL, 0xCB8E634F1BF8E57AULL, 0x4319FB21757B1789ULL, 0xB8F0DF5CAD5EE144ULL, 
            0x18167E3A7F50A54EULL, 0xFD6339A9BFF9C997ULL, 0x57DBC0E2AC635FE5ULL, 0x0C64E75636CFF84CULL, 
            0x089C78C37F83A7F3ULL, 0x6B9710749DDB55B8ULL, 0x4BDC01D74AA78A59ULL, 0xBE22DF2B1C23134CULL
        },
        {
            0xDD73219F4FF32D40ULL, 0x98E6AC92092BBF12ULL, 0x232CB2BDB82B1278ULL, 0x49731EBF4863F82FULL, 
            0xAFB747CABB8F01FAULL, 0xF9FF9EBFCCBBD1E3ULL, 0x94D0F9AE9DDC2C21ULL, 0x888ED53167CCD285ULL, 
            0x00E930C9FDE407D2ULL, 0x3B9246B88B35573BULL, 0x403E80521113EEFBULL, 0x05D829E59EFF3BF9ULL, 
            0xBEAAC307FE720A04ULL, 0x8C21AB664051FC40ULL, 0xEAB79439FAC0FD89ULL, 0xDCBCD555C64AB8E9ULL, 
            0xED14B7334202ACDDULL, 0xCAAF74866CAE390AULL, 0x5C3EDA19329208F9ULL, 0x62EA66BD4085ADC1ULL, 
            0x46CD5B3995E9699EULL, 0x1D743A1CEC5EFCE5ULL, 0xDEAE08AF5ECDAA36ULL, 0x70A001648A89C348ULL, 
            0xD708126EABD4F49DULL, 0x0A589C93090615C3ULL, 0x4D8D62D172F2C587ULL, 0x15FAA86E31598536ULL, 
            0x8D0B3FEA6A73C5EBULL, 0x2C46BD610995D703ULL, 0x280B29974493E2A1ULL, 0x6BC7C01FA4FC5DDAULL
        },
        {
            0xD1C0ECEE3B65C691ULL, 0x2E1409B153C5C955ULL, 0x31D9BBD496472B4DULL, 0x3D6AD77EA8DDF7EFULL, 
            0x2FF6B271B54AEADDULL, 0x6A41754563D881D3ULL, 0xBBA2303B10B21872ULL, 0x3A68CF8B13782EB2ULL, 
            0x4A7526C28B9F29CFULL, 0x8F3327313021081AULL, 0xCB7BD97B89434FDCULL, 0x05B528D9F9D240E9ULL, 
            0x1E9398BD5BAA0E86ULL, 0x5112B5BA494A320BULL, 0x4DDE6953EFE0D2F0ULL, 0x613C9E51AE8FA0A9ULL, 
            0x0408A1FC7DE92F06ULL, 0xABBEFAF904CF4994ULL, 0x9361A63B97670143ULL, 0x3E75E17BE6DCE942ULL, 
            0x7DE9F57DF5C4D370ULL, 0x98D1CEC9BAF9D6CFULL, 0xDF42865524D9D547ULL, 0xA8AC236570CFD15FULL, 
            0x3CECA6EE3CF7E73EULL, 0x72AD4DCC2F7F4362ULL, 0xABB94DC1E42EB79DULL, 0x249ECCA84405EFE8ULL, 
            0x039978DA8D0AD291ULL, 0xE994588A62696410ULL, 0x7D5A4060C23FABABULL, 0xDEECB3089D611248ULL
        },
        {
            0x6996E5473943DFCEULL, 0x23B134BCBB95D140ULL, 0x3643762935CBCF42ULL, 0xCCDE9130F9128D1BULL, 
            0xF85CE0376530D075ULL, 0x9FA26A1505A30F2DULL, 0xCECBF70F2B8CD06FULL, 0x5DF45ECEB28B9840ULL, 
            0xDCEAF7FE733FEDA1ULL, 0x4331372407ACC4D1ULL, 0x53FA028DCEAC97E7ULL, 0x35339A3AFF0082DDULL, 
            0x3B48A2CA2CC9C5B4ULL, 0x2D85C91D2227119EULL, 0x6CE4385812315FDBULL, 0x73CAFD811F8F77BDULL, 
            0xE1C7ECCC28225D32ULL, 0xFBD66F5488611007ULL, 0x78848B75FF6325A7ULL, 0xE90F4A0E4178272FULL, 
            0x7009C2E6A6AA8754ULL, 0xCEA93BBBCEB33571ULL, 0x6336224A630E6C9FULL, 0xCC1ECD6AE554D9E6ULL, 
            0x9E9BDEFCE35F6861ULL, 0x38CD287F2663CF0EULL, 0xFCFB77AD87BF4D25ULL, 0x5FB0D5BBAFC1540DULL, 
            0xA23369456B2B6365ULL, 0xEAB94BF0DC1EF26CULL, 0xBCE15D53213AF025ULL, 0x79037C3A6A985031ULL
        },
        {
            0x5ED65774F1682089ULL, 0xB18C4EE89265A6C0ULL, 0xD842F830F4C8301DULL, 0x4C3D812970B24419ULL, 
            0x43D70A0E0363D9CEULL, 0x9470A2591A0808EEULL, 0x27A184A096871741ULL, 0x510A0B7DFD49FFDFULL, 
            0xB264EEAD34F35C6EULL, 0x071CF1130A85333BULL, 0x0C75FD41E7010501ULL, 0x84DE533B9646FFB4ULL, 
            0xF6836F19AE791F4BULL, 0x0619EF0D69B08B47ULL, 0x14338DBAA351C1D5ULL, 0x5D5DB4B3E2966E33ULL, 
            0x5B4886F6029887B9ULL, 0x2D6030D57290E56FULL, 0x74F439E68D20E3FCULL, 0x80DD017C98DA1720ULL, 
            0xD057529F51C33417ULL, 0x18673BBDBE151FC2ULL, 0x176D4B2CE77BBFD4ULL, 0xD4E4A7F365E2F4A7ULL, 
            0xD8C06F71F232E8ECULL, 0xA20BD65711C535D7ULL, 0xDFED6A593684EF2AULL, 0x09CD53BADDC9F635ULL, 
            0x116B47DC2B622DF0ULL, 0x0A9B0856833050E0ULL, 0x84BBAFD5DBCD6484ULL, 0x40A1B9A9D2F41BFDULL
        },
        {
            0x11352FCEA112D5B0ULL, 0xBCD945B9BC4D8DE5ULL, 0xD8C1B7C3E7170BFBULL, 0x9CF282082809A01FULL, 
            0x295013392848DC5EULL, 0x3F8AB1C6E8B0AF88ULL, 0xADB59D3F15AB0FF0ULL, 0xD347F78C7B663166ULL, 
            0x4DBF1836F4F987EEULL, 0xF0005B199575EF68ULL, 0xBFF94296662F7064ULL, 0xD462BFEC02A04957ULL, 
            0x3EF8962DB1F50F49ULL, 0xD35669C88E01CDB2ULL, 0x3C0111EEF2C38604ULL, 0x0BEECBB4E44871A9ULL, 
            0xDD594C7E749CAFF9ULL, 0x667230F02947F823ULL, 0x48BD5743478886BCULL, 0xB22E547558E4C612ULL, 
            0x49A79721221E8424ULL, 0xB9168D08D444A73DULL, 0x71312B7FD316E704ULL, 0x30D4C06367E217DEULL, 
            0x27FC10EAA3B46C60ULL, 0x99936B6620CE5F69ULL, 0x5EB0FB07E3193F4AULL, 0x4240BCC5E6C55952ULL, 
            0x22F673CBE9B030CFULL, 0xBF8E490BC4292E4CULL, 0x02FE3C74704F993EULL, 0x7B44F00533555519ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseHConstants = {
    0xB5587A5665575E1FULL,
    0x4A794A9F603108FAULL,
    0xC4DD55B62F72566AULL,
    0xB5587A5665575E1FULL,
    0x4A794A9F603108FAULL,
    0xC4DD55B62F72566AULL,
    0xE2610FE7C1C50BC4ULL,
    0x65E1A6A1CDB143EEULL,
    0xF1,
    0x71,
    0xEF,
    0x87,
    0xCD,
    0xEF,
    0x24,
    0xF3
};

