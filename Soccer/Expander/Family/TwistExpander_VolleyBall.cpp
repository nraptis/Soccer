#include "TwistExpander_VolleyBall.hpp"
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

TwistExpander_VolleyBall::TwistExpander_VolleyBall()
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

void TwistExpander_VolleyBall::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xEA627033E46EFA37ULL; std::uint64_t aIngress = 0x9A9EA572B6C12055ULL; std::uint64_t aCarry = 0x8F709CFB45C41530ULL;

    std::uint64_t aWandererA = 0xE60BF8EA7CEE78B1ULL; std::uint64_t aWandererB = 0x8DF673746B5F4FAAULL; std::uint64_t aWandererC = 0xAFB1495392A466D6ULL; std::uint64_t aWandererD = 0xFBB4AC9DD3080E8EULL;
    std::uint64_t aWandererE = 0xEDAB6E4A92A9487FULL; std::uint64_t aWandererF = 0xF30A83D416F8D95FULL; std::uint64_t aWandererG = 0xD6C827B80A1C3D04ULL; std::uint64_t aWandererH = 0xB2456CF80289D9D4ULL;
    std::uint64_t aWandererI = 0xB69F3B779176F9A0ULL; std::uint64_t aWandererJ = 0xF8A7DE62F618EE53ULL; std::uint64_t aWandererK = 0xA2AEA1CB77141799ULL;

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
        aPrevious = 17830868263528452128U;
        aCarry = 9309101323241778154U;
        aWandererA = 14787456898506985398U;
        aWandererB = 15779578779953726175U;
        aWandererC = 16604040273778515120U;
        aWandererD = 13363712976491011823U;
        aWandererE = 16725144447097174583U;
        aWandererF = 17453809224344868563U;
        aWandererG = 17289163772965077922U;
        aWandererH = 13129007402089712364U;
        aWandererI = 10663024441703322133U;
        aWandererJ = 11704350594734202941U;
        aWandererK = 14102552144490334810U;
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
    TwistExpander_VolleyBall_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_VolleyBall::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xEE8181C0386DDD38ULL; std::uint64_t aIngress = 0xF7D71A67D1B41F21ULL; std::uint64_t aCarry = 0xEAC83EB211EDFF9EULL;

    std::uint64_t aWandererA = 0x9CDAFB44BD68BB9AULL; std::uint64_t aWandererB = 0xB0807533FCC01D2FULL; std::uint64_t aWandererC = 0x86FE146F71A30BDDULL; std::uint64_t aWandererD = 0xB7E292681AF005E9ULL;
    std::uint64_t aWandererE = 0xD3318CCB34D18D54ULL; std::uint64_t aWandererF = 0x82F47C8F549C466FULL; std::uint64_t aWandererG = 0xE741BE227B77EA53ULL; std::uint64_t aWandererH = 0xBF886A755411E3ABULL;
    std::uint64_t aWandererI = 0x95B987E641BF0AC5ULL; std::uint64_t aWandererJ = 0xC786F41CB0E6F538ULL; std::uint64_t aWandererK = 0x8184EEEF0ED5FD26ULL;

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
        aPrevious = 9736118039137060161U;
        aCarry = 13093184670824477744U;
        aWandererA = 12424698382836008990U;
        aWandererB = 10443653010934511448U;
        aWandererC = 17383508715265522764U;
        aWandererD = 13458169178893093472U;
        aWandererE = 13062156083011631945U;
        aWandererF = 14278620143048577773U;
        aWandererG = 11909535510391080532U;
        aWandererH = 14919186958905543307U;
        aWandererI = 15575503004494731539U;
        aWandererJ = 11102965550201011514U;
        aWandererK = 13936233256913278946U;
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
    TwistExpander_VolleyBall_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_VolleyBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x86F3F2527C4F03B7ULL;
    std::uint64_t aIngress = 0xB4A006C9445C6621ULL;
    std::uint64_t aCarry = 0xFAB88394A19B620BULL;

    std::uint64_t aWandererA = 0xF836123C327FFFBCULL;
    std::uint64_t aWandererB = 0x8416D8785836925CULL;
    std::uint64_t aWandererC = 0xD8513C7E7C3D3CF9ULL;
    std::uint64_t aWandererD = 0xC4C988CEA6B05E65ULL;
    std::uint64_t aWandererE = 0xCF182FB75D968A6BULL;
    std::uint64_t aWandererF = 0xEA5A20C9D56729BEULL;
    std::uint64_t aWandererG = 0xB568B2407DD96E5EULL;
    std::uint64_t aWandererH = 0xDD1D9E1152E750F8ULL;
    std::uint64_t aWandererI = 0x9C79896E4CED7600ULL;
    std::uint64_t aWandererJ = 0x9BA3082B1561633FULL;
    std::uint64_t aWandererK = 0xA99C602255E2FC2FULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneC);
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
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneH);
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD, 3);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA, 4);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC, 6);
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD, 7);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistExpander_VolleyBall_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_VolleyBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_VolleyBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9049BDA8DB80732AULL; std::uint64_t aIngress = 0xE25B055C2A1BCACBULL; std::uint64_t aCarry = 0xDC7559A715E87D32ULL;

    std::uint64_t aWandererA = 0xD8098CFCDE085738ULL; std::uint64_t aWandererB = 0xB88DBDE6521E183EULL; std::uint64_t aWandererC = 0xB404B1CB02FCC6B4ULL; std::uint64_t aWandererD = 0xC501B73DAEF9841DULL;
    std::uint64_t aWandererE = 0xC680B0298290CFE3ULL; std::uint64_t aWandererF = 0xFF8250E1ED457E54ULL; std::uint64_t aWandererG = 0xF64B432D4F967595ULL; std::uint64_t aWandererH = 0x9707961B51800EB0ULL;
    std::uint64_t aWandererI = 0xFFFC7BBB594904E1ULL; std::uint64_t aWandererJ = 0x988F4EF1990559D4ULL; std::uint64_t aWandererK = 0xAE72E6FF3848A558ULL;

    // [seed]
    {
        aPrevious = 17918862957828032226U;
        aCarry = 9891901246176697683U;
        aWandererA = 16027044271402494527U;
        aWandererB = 16408811427891389949U;
        aWandererC = 13126733356909220162U;
        aWandererD = 11081540856020384355U;
        aWandererE = 16409527023523134426U;
        aWandererF = 10572237345997483112U;
        aWandererG = 13297267103056968867U;
        aWandererH = 18299563895246811648U;
        aWandererI = 10020367542114692803U;
        aWandererJ = 13721039162886281774U;
        aWandererK = 16899202772791896011U;
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
    TwistExpander_VolleyBall_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_VolleyBall_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_VolleyBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_VolleyBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 0, 3 with offsets 1425U, 936U, 3843U, 1612U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1425U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 936U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3843U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1612U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 1, 0 with offsets 5299U, 805U, 7066U, 1466U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5299U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 805U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7066U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1466U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 3, 2 with offsets 7554U, 604U, 5396U, 837U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7554U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 604U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5396U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 837U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 2, 1 with offsets 4397U, 2777U, 190U, 2141U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4397U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2777U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 190U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2141U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 3, 2 with offsets 362U, 1371U, 1283U, 984U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 362U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1371U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1283U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 984U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 2, 3, 0 with offsets 1744U, 1737U, 683U, 1140U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1744U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1737U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 683U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1140U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 1, 3, 0 with offsets 1526U, 903U, 291U, 1155U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1526U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 291U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1155U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 2, 3, 1 with offsets 794U, 964U, 553U, 224U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 794U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 964U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 553U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 224U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1195U, 1888U, 455U, 57U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1195U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1888U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 455U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 57U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_VolleyBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 3, 1 with offsets 4943U, 6658U, 1717U, 6510U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4943U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6658U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1717U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6510U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 2, 3 with offsets 2071U, 6889U, 4295U, 38U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2071U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6889U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4295U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 38U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 0 with offsets 6063U, 2198U, 4348U, 1190U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6063U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2198U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4348U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1190U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 1, 2 with offsets 3628U, 4296U, 2392U, 4131U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3628U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4296U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2392U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4131U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5676U, 2498U, 5634U, 4621U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5676U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 2498U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5634U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4621U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1526U, 840U, 1297U, 182U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1526U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 840U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1297U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 182U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 875U, 196U, 728U, 1555U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 875U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 196U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 728U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1555U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1833U, 203U, 698U, 1816U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1833U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 203U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 698U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1816U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1134U, 1372U, 1803U, 240U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1134U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1372U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 3, 2 [0..<W_KEY]
        // offsets: 1338U, 1527U, 850U, 1272U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1338U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1527U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 850U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1272U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseASalts = {
    {
        {
            0x2CDD5658011C72CCULL, 0xBD63E3084951F2F2ULL, 0x2D4FA43A446C60F3ULL, 0xE8F45B201C19F860ULL, 
            0xAA49303DEC78D792ULL, 0x87B9B24FCD075362ULL, 0x1AAF6885AFE21C93ULL, 0xD8472CBE10AAB341ULL, 
            0x9636043DCDF05081ULL, 0xE9F17E0386159B43ULL, 0xCAD0ACC266535A97ULL, 0x35DC5502475766CFULL, 
            0x6267BB5FF8C78E07ULL, 0x9541FF2EE799A21DULL, 0xBCFB4EED9A13AA7CULL, 0xEE585A6E1A20F169ULL, 
            0xD857F15B24EA1489ULL, 0x8D3DC0499B300954ULL, 0x089C12F5DC250D31ULL, 0x7C43836078872BEAULL, 
            0x3E54A4722269DF46ULL, 0xBB27453EB99048F2ULL, 0x4678B4E7739970DBULL, 0xA350BE1A15172C7AULL, 
            0xD7E102EB3CA35893ULL, 0xCAE93EB9DC194A9BULL, 0xD953EEF096B485DBULL, 0x2ECE12B034B88E4DULL, 
            0x795A4BC0ACA3910BULL, 0x69939B4E2FDA30B1ULL, 0x17227A8D5FDB7E82ULL, 0xA7C64173837E14E1ULL
        },
        {
            0x1391B2ED45C94C4BULL, 0x295D1E38BF27DC21ULL, 0x7BE23EDE16B9636AULL, 0xC5437CD32A3D3F00ULL, 
            0xF16D6CC14477E55EULL, 0x63A621318FC38F1BULL, 0xC4C4479B1C9BF1F6ULL, 0x4A592070A1357B71ULL, 
            0x32E0EDBA4BFB07E8ULL, 0xFBEC1F68E3E0BC22ULL, 0xA36A90F571CDC2FEULL, 0xAD53B779B46E2475ULL, 
            0x05CB6078EDDF6FA8ULL, 0x7349296E644B26E1ULL, 0x8B6167B241E10A00ULL, 0x1903B71C71E9416DULL, 
            0xD2DF6C55DC20F521ULL, 0x0ED7A58DDBEA0EBBULL, 0x309C55377A5139CFULL, 0x7A7CD6C36AF4968AULL, 
            0xAEF755492F35AF94ULL, 0xCB37AFD35FBAF8CEULL, 0xA2DA60416547CD33ULL, 0xA412143F88035847ULL, 
            0x4DCA905D65089F8CULL, 0xF4D310DAD2A0DE41ULL, 0x130A23AF4AB8878CULL, 0xF0BDBE2E9C1932FAULL, 
            0x5A0B7AF0DE77AD63ULL, 0xD87E847506DEA950ULL, 0xFAF57CCF9281E8DFULL, 0xF543FB728A2259CAULL
        },
        {
            0x10BF4B7FCF5EE455ULL, 0x4014EAAE62A84D74ULL, 0xEA42BEEE0D4A3826ULL, 0xCC03D6073C5D1351ULL, 
            0x40C478CDED08AD90ULL, 0xE7EFF8D12D4787FBULL, 0xD8DFDC0721CA1C88ULL, 0x4AB6414DDFC22CE4ULL, 
            0xD723DA3E98613CA0ULL, 0x66230954BB222BD4ULL, 0xC789296638F30382ULL, 0x96D0646A740210A6ULL, 
            0x4922CBA455DEF849ULL, 0x795BD040B7269D18ULL, 0xEC12705568369676ULL, 0x12D2525063D9729EULL, 
            0x27CBEB1BE1E11ABDULL, 0x1A0E8947F1EBE144ULL, 0x3D6E38C4D4DF527EULL, 0x2AFA70C31BBBC705ULL, 
            0x0FDF0058F66ED555ULL, 0x957C65F6D36EC0C4ULL, 0xC3382050D730741DULL, 0x592D541746EDFD43ULL, 
            0x91359AA7E6F32C80ULL, 0x2F07FEC1BB64B535ULL, 0xA5D958E6032CB322ULL, 0xF2183F34FE9BFF2AULL, 
            0xAF68F5B4ADCC4810ULL, 0x53027C72ABC53904ULL, 0xEB37BD0C2ED39798ULL, 0x16C471A7A3B850DEULL
        },
        {
            0xF6F3C24FBEFD812EULL, 0xA6555B6CDE99E8BFULL, 0x06C0E09BAC9E9FF2ULL, 0xF26DC39924679251ULL, 
            0x4D9E0556D360FCABULL, 0x8A4FA3C3350DFCA9ULL, 0x1D4208D56C8C369EULL, 0xAAEA878BD200D1C1ULL, 
            0xCDF0D5FB9247DBE2ULL, 0x4854B6EE4EC5337EULL, 0x754E3E1EA3FBB54EULL, 0x58FD7F32DFCAC9A9ULL, 
            0x30C4EC208F028DEBULL, 0xB302F9320ED66130ULL, 0x75C22382C234C7C3ULL, 0xD5E7805AE8647B61ULL, 
            0x85639B172C3C1514ULL, 0x4B155EF8295C89F7ULL, 0x324DA59AC2601C24ULL, 0x1AE1CB5AD9046812ULL, 
            0x00FBA3117E8FCC3CULL, 0x11EEDC0A8C5D0965ULL, 0x7EAC3280474878BAULL, 0xD1C96F76DF216805ULL, 
            0xC530399FEDF4BF17ULL, 0x7CC6D525CBC5B4C9ULL, 0x6F8084E59BED0446ULL, 0x6EE63E2A5038612EULL, 
            0x7C76131F4354C062ULL, 0x6F6D519C59831D1EULL, 0xDB1232714AF99769ULL, 0xA10566D1490DA8FFULL
        },
        {
            0x36F40132B4AE2AFDULL, 0x0656698BFAB642D5ULL, 0x9DBE03FD7DCF7C81ULL, 0x7402AABCCC173A15ULL, 
            0x9FB735A7448AF153ULL, 0x03641A7D668E822BULL, 0xA6311C0859338C82ULL, 0xFE585FB9A86A9FA5ULL, 
            0x5B73EA9180E61CBCULL, 0x7580EE955E69C7F2ULL, 0x7ACA9FFA476C2072ULL, 0x79FBB3C669903A34ULL, 
            0x38F899C7A25ED9BDULL, 0x481FE94E5134B728ULL, 0x283B488303A09FA4ULL, 0xCC11BDA709BA7ED6ULL, 
            0x348892E211D3133FULL, 0xF0378111CA04A139ULL, 0x33C99CD0FBBCF39EULL, 0x582EF2583670E5C5ULL, 
            0x9176F1296C74DEABULL, 0x228B42A295B4D9FFULL, 0x18E1F3B0F305C06DULL, 0x89642E105AC832B2ULL, 
            0x1B6F379E90A53D1BULL, 0xB923AAA1E78D193FULL, 0x583B17B5663CD42AULL, 0x662B3087B803E832ULL, 
            0xE8314544120DBCB5ULL, 0xE2F39EC40AB6C8D9ULL, 0x49B8A58AFBE34895ULL, 0x6F34D5EE1504CE18ULL
        },
        {
            0xD57ED5B3254328C3ULL, 0x52B1F17F8B63F378ULL, 0x8163AEFCCF0D35FDULL, 0xCCA8670F2B35C875ULL, 
            0x1D715E05930B456BULL, 0x660E76234DA7025EULL, 0x2D6F682C65842DB0ULL, 0xC2B725FD4F1A6C57ULL, 
            0xF8787B698200DF91ULL, 0x91663F5B4C56C78CULL, 0xDBFEB95E431FA580ULL, 0x165EA81C1B1E6A74ULL, 
            0x8EFA8332E04F41E6ULL, 0xA6EFA75810ED8430ULL, 0xCF92D8E84DAD74BEULL, 0x9B941D7003738A50ULL, 
            0x200D54BDADC85E76ULL, 0x4F66C0CFC267139CULL, 0x48281D8819FE0BEFULL, 0x5CB618550BD702DCULL, 
            0x92475452D2ECB455ULL, 0xA98A8F379CF6E130ULL, 0x3FD1AF6D70D61CB2ULL, 0x2ECE73C26517FF7AULL, 
            0x1CDA7A33A3D50DA6ULL, 0x59404BE21BC3914AULL, 0x4AD5F0E12F613890ULL, 0x0EDE85864578DD35ULL, 
            0x00F1890419076BA0ULL, 0x18D3537A8B8E4F27ULL, 0xB3BD33BFBCB9EB52ULL, 0x538071CC46097112ULL
        }
    },
    {
        {
            0x41C814363B687183ULL, 0xC6BD13E5A880887AULL, 0x6D94C91C2DFCEC70ULL, 0x89416363C3F0CEA2ULL, 
            0x7AA77D3D03500ACCULL, 0x1B9C1C3BCC64BF94ULL, 0xD0DE345EEDB11912ULL, 0xDF585755CFF71435ULL, 
            0x4C6D56BD9916CBA4ULL, 0xDF156E00923A13BDULL, 0x889252243E828033ULL, 0x38FDF798BB61187DULL, 
            0x20047EECE7DC779AULL, 0x838E8A0D93F09C46ULL, 0x5292AC5A76E53A1DULL, 0x4C985BEA9846DFF3ULL, 
            0xF12C17C644C81E0FULL, 0xBD51D1B0E9E97D78ULL, 0x71AB073C58519212ULL, 0x7A7D10A34526BD62ULL, 
            0x2EE481E0CC6FBE35ULL, 0x3BF8A607EC45AF25ULL, 0xCBF5E7811F557DC8ULL, 0x1DB4E687724D9B50ULL, 
            0x9040E0968AA8BAB6ULL, 0xE98D3A900290BBEBULL, 0xE3841A8749EA375EULL, 0x80ED7CA5CEA955A6ULL, 
            0xB342A28375720868ULL, 0x9B4466D59356084EULL, 0x371DBA154834816EULL, 0x4945EA5116C0AD49ULL
        },
        {
            0x38838EB0F4E4E8D6ULL, 0xDF61607E50D6E16DULL, 0x59B7FC764348A788ULL, 0x74CAB413F5B2B775ULL, 
            0x59A38563F400BF2CULL, 0x274C5E2AD6D1AB97ULL, 0x6472140F71BD7799ULL, 0xE24804952EEF9C77ULL, 
            0xFAD6CCA4CF026D5AULL, 0xCFDA25E682C8E85BULL, 0x15037FC8F3CCC3E8ULL, 0x9AA310969EBC1A1AULL, 
            0x3726168DE4B15832ULL, 0x533B54FD69E798BEULL, 0x8C76EF8F298CA7DDULL, 0x303C0A8A27783429ULL, 
            0x3DEDA97CC4B5E1E3ULL, 0x7A1607EC2A2EA557ULL, 0xFB902653B9CB7E8DULL, 0xCB8ECE0E96B76857ULL, 
            0x841D39968C042220ULL, 0x0B7B0B0B5214848BULL, 0x29098085F367B0C6ULL, 0xB339B333C9F2D0E0ULL, 
            0x21EFB5B8AB878709ULL, 0x175ECB13417243C0ULL, 0x7788E307A796B54CULL, 0xA42241C417A6D70EULL, 
            0x8C98948A426B961CULL, 0x02C0CDC134DD6824ULL, 0xCF1FED27CE109A37ULL, 0x2C6C0E7AA8DF886BULL
        },
        {
            0x1B441D3EE712B091ULL, 0x879AFE1322042347ULL, 0x0E7820333DDAF6E0ULL, 0x19C1FA11AACCF6CEULL, 
            0xC7F1463E4ED22734ULL, 0xE61BE83ACFCA6A7EULL, 0x10B1EE20F9816C1FULL, 0xB998DE1C4CA9C5BFULL, 
            0xEB67377AB873CCBCULL, 0x4170294072486750ULL, 0xD4A83F8D243C2BF2ULL, 0x28F0FBAD43B3C048ULL, 
            0x8893D5011D1FD4C4ULL, 0x8BAC35A757E21FC9ULL, 0x0FB3BA98C969D8ABULL, 0x4CECF8B6011905B7ULL, 
            0x479ED869C091D6DDULL, 0xC21F7E8FD818F475ULL, 0x3894EEF5D37B8C84ULL, 0xD941E2C502712762ULL, 
            0xCAD534C36368C608ULL, 0xF8C1FF8EA4E6EA8DULL, 0xC4E3C79FD426E05CULL, 0x4185386D962E6FDCULL, 
            0xAB5C17AA20158B23ULL, 0x5CB6AC46B1248E2CULL, 0x10EEC185EF0157B4ULL, 0x740796B99D4A94EEULL, 
            0x694B82C000E9E0FBULL, 0x9D99352F29BAD1DDULL, 0x32DE4FE94A80E83DULL, 0x94AA99AC9FF116E3ULL
        },
        {
            0xC207F0998C85F08CULL, 0x06B4AA10CEC3021AULL, 0xF98168291634E1EEULL, 0x91927BFC01273893ULL, 
            0xA0CBBA94226F23A8ULL, 0xB422AA8E3B3A08CEULL, 0xD599E22C722C1D08ULL, 0x74AEACDDE1543434ULL, 
            0xEB921221E027E0C5ULL, 0xAA262BBB2A5A7F59ULL, 0xB580B14FFC581FE7ULL, 0x423C2165FC3B56FFULL, 
            0x16143CA899E3F12EULL, 0x4A82122FE6343760ULL, 0x084EADF5772E4C35ULL, 0xC74F431A78300299ULL, 
            0xF15F6E49C10C9C77ULL, 0x16EB08AA23C1A4D3ULL, 0xEEF2BFC6213ED88CULL, 0x90E6A07CA2EC8DB6ULL, 
            0xDF053DF14BF10C1CULL, 0xEAD334771C66090CULL, 0x481D8274F67F1912ULL, 0x5305A7C245BAFA1CULL, 
            0x27DB57A713A1C4EAULL, 0x473AF67F792F3F5CULL, 0x1797E9452C90715BULL, 0x5B767F5318BE864FULL, 
            0xE9CFDE0FA6002B27ULL, 0x941BFE6AD0E12231ULL, 0xC659BA872815F924ULL, 0xBACB8FE68D521027ULL
        },
        {
            0x48C1419BD415B510ULL, 0xEBBAD3750BAF28B3ULL, 0x60A54D3D7B569449ULL, 0x7C2ECA35841036B0ULL, 
            0xA6E1016E6AD28720ULL, 0xEC29E51949DBED81ULL, 0x575A21C98D60C7A1ULL, 0xFCF2015E632CA6A0ULL, 
            0x3F9577A12531D93AULL, 0xCC44FF13FDC67FBDULL, 0x465C88B443259FDEULL, 0x1FA51C6F951A3647ULL, 
            0x040731C63C2C20BFULL, 0x08A1B1A9DDAB6265ULL, 0xA68083FED153E85CULL, 0xC3F41B922A8C33B4ULL, 
            0x4A9810565BF63984ULL, 0x470D824EA6ABAF16ULL, 0x0B1FFA39B452934AULL, 0x170C874AF308BB75ULL, 
            0xCC40085B7E9DF993ULL, 0x78ACEFBDAF6C1E68ULL, 0x30848A7C14952914ULL, 0x62DDAE498E777BE3ULL, 
            0xC5199C2DDFBDC756ULL, 0x2B558ED8DF661E27ULL, 0xF4CEEB36127BA998ULL, 0x75CC10FDDA5E7F84ULL, 
            0xBF9F6F0FB74414C2ULL, 0x2198042EE87550E9ULL, 0x33DB6E5038AC069BULL, 0x5DD8137A5D2A10D5ULL
        },
        {
            0xD78CE6BBCDEDA4DBULL, 0xEDDDB9E80CFF01ECULL, 0xE911ED1E1599BBF1ULL, 0x018A8C6959A0DEB7ULL, 
            0x4ED00C8EC36E9865ULL, 0x6E3A013DBA6801C7ULL, 0x34FC9B118BF3D278ULL, 0x5DD71AB2270D4F31ULL, 
            0xB6885F2185C22F3BULL, 0x8B42BFD9895B6863ULL, 0x675E6AB64ADD72BAULL, 0xF74A9656AF8EE375ULL, 
            0x9773977AB42F9901ULL, 0x40C1F5A3141E7904ULL, 0x66BCAC89CE1C45E5ULL, 0xC6544027E8FC9405ULL, 
            0x8D7CC6B5444521BBULL, 0x5490C7A9AD4B1802ULL, 0x42A8EE5802716398ULL, 0xFF740912FD0CEE71ULL, 
            0x2DAC2117489F8B2CULL, 0xFBC0D21D1902ACE5ULL, 0xA49F9D6E14FC8667ULL, 0x67B39AE4A01125B4ULL, 
            0xF9B596F1B9BFDFF7ULL, 0x96595EA142184A3FULL, 0xB8AB7B16129DA26CULL, 0x2EAEE7A42007B89AULL, 
            0xE855B7657A6033F5ULL, 0xB84CA716BCC131B1ULL, 0xA4F30CDDD66E209AULL, 0x742634D3B86F2A4BULL
        }
    },
    {
        {
            0x376E9F2FC2E6D882ULL, 0xD116C102EDB9C1AAULL, 0xB6CD679528101AB1ULL, 0xB6445C6D58E90419ULL, 
            0x5F8F256641C31C5AULL, 0x78B04A6E985D3E60ULL, 0x9A05309B47B3721AULL, 0xDE5CD0A4337D67F6ULL, 
            0x4A8EDB3C82BAC87AULL, 0xC5819B4A448FE41CULL, 0x887F0A1A6F91C851ULL, 0xFAFB49A0F4DB3BB2ULL, 
            0xE220776C74B03479ULL, 0x2BF964256AE854EDULL, 0x572C874ED9A12219ULL, 0xB10687D609C95860ULL, 
            0x3CEC086A3B723549ULL, 0x327EC519F954AA35ULL, 0xD71CB8F2D7566D0BULL, 0x5BF4D8883C48160BULL, 
            0x43FC4A9D01781762ULL, 0xB28E774441755997ULL, 0x59B891C2AB3B3039ULL, 0x7A3A751F92DD7C90ULL, 
            0xFE9AFCEE3C03A9F3ULL, 0x24A1BD20E2DF8C4BULL, 0xAD0B64528DE95527ULL, 0x06F6F49CCFE3BD8BULL, 
            0x9B5CF332FA72D687ULL, 0xEC57650A69B3B978ULL, 0xD0847E7A55C9A229ULL, 0xD5DA5F9D22ACD663ULL
        },
        {
            0xBBE88AAF51AB00E8ULL, 0x989F7D140C0EF272ULL, 0x12CDD4EC7F1BB8AAULL, 0xF0FE2B798FF17E91ULL, 
            0xA69D4B508299CC1FULL, 0xA321B6644B0D5279ULL, 0xA0988EE75722176DULL, 0x0B1DEDA96BB52777ULL, 
            0x3972085F811C605CULL, 0xEFA5BC1440C86E54ULL, 0xAC19E193F0707514ULL, 0xCF57FD18D9111BE9ULL, 
            0x421AD2C0C1F202B1ULL, 0x44CB4FB8101C23A6ULL, 0x419A5E76CA84A826ULL, 0x2A9579CAD568DFA2ULL, 
            0x25805DA85D4831C2ULL, 0xA483E29706BC5C91ULL, 0x8B1E4942AA5CB06BULL, 0xD569039616EA299AULL, 
            0xCC82F063EF4FDE40ULL, 0xF3EB0CA9AD64CF55ULL, 0x88C5C9604D06760DULL, 0x2DD3F0AA08F76496ULL, 
            0x6BCD348D793A1217ULL, 0x2C545D0D9E9A4455ULL, 0x6EDAADE9C4FE3B99ULL, 0x9C6E4662E8258492ULL, 
            0x3C69F8F3A4135C57ULL, 0xDAF1A12FB3AE39DDULL, 0x1198EC0C77246694ULL, 0x72067337032B758EULL
        },
        {
            0x49C9EED5E32EE00AULL, 0xD7BFF38B276B14E3ULL, 0x1E6B8AF114DC37C9ULL, 0x4428BF89E867A6F9ULL, 
            0xCE228FD9B503FA73ULL, 0xBCC5A50ECF0DCDDDULL, 0xD2B975FDB4E5B3BFULL, 0x34D6E8AD848C626FULL, 
            0xDB82BB0190A2AEB6ULL, 0x809C5450E730D3BEULL, 0x35D049647DD4E1CCULL, 0x7D05BE51AF77B3D0ULL, 
            0x56316138567293F6ULL, 0xDC3E7BC14FB921B4ULL, 0xA46C3959E67FF658ULL, 0xB072AD7B7DBA3F20ULL, 
            0x120E89CAC2CD72E7ULL, 0xE4B214FD7DC60C80ULL, 0xC54BBE8AFFBAF6C4ULL, 0x88C51645D73F0A36ULL, 
            0x8E67346992B522DFULL, 0xDC0EDBEC734FEAF7ULL, 0xACF1C8C8F9CC7B61ULL, 0xCFCF04045647C8F0ULL, 
            0xF76C8742F0FE6298ULL, 0x690DD78E43AAE2E1ULL, 0xAD8E876CED219B07ULL, 0xDEB7830A09F0CA42ULL, 
            0xA750F0428B6B8160ULL, 0x59293FA27936B347ULL, 0x38E71AA4AE21E33AULL, 0xE7D37E687F8D55F9ULL
        },
        {
            0x8CEC9A55A8E52AD9ULL, 0x313E57B3B2AB666CULL, 0x1DF398C2A72D7AF4ULL, 0x28196FF9C71F6970ULL, 
            0x64A8C1077ABCC196ULL, 0xDF7C8EE4C1F6F0F7ULL, 0x13F159AFFA0F27BEULL, 0x9B6B8BFB7DB23981ULL, 
            0x0A01648598E1E555ULL, 0xB31B50BA3CA1BF70ULL, 0xCDE3E811E9C0EF60ULL, 0x4BE8ADD6F8866FFCULL, 
            0x28606B9207D62AF0ULL, 0xF56387E7EFDBBB03ULL, 0x5E0D6AB4B47B3017ULL, 0xCF2D75E401F69EC0ULL, 
            0xD088834AFB9B86A7ULL, 0x1E5FF451CFECBBC3ULL, 0x1EEE3A26008A9673ULL, 0x7F54D4538219C36EULL, 
            0x791A5358B5E262B4ULL, 0x788EA115EA592748ULL, 0x61676DA51B583C87ULL, 0x0E4E76D503739FF5ULL, 
            0x674114418F95F6C5ULL, 0x322218B6098528A8ULL, 0x70CCCBF93E2B7CACULL, 0xBA5141A451FF2A65ULL, 
            0x774E6210C26D1EECULL, 0xF423E296FAEAB909ULL, 0xA0CFAA4626C24B38ULL, 0xDB8E1777DB69908FULL
        },
        {
            0x0613ACA6B5DD380BULL, 0x30AD98EDA104F7FDULL, 0xBF3BA37DF468DFC2ULL, 0x3F0C6EF53649DA56ULL, 
            0x54B1B6F414946F18ULL, 0x40B23F3110ACABE4ULL, 0x5B1D719C1E2412BAULL, 0x13853C6CB72FA50EULL, 
            0xBDC7C0B1237105F6ULL, 0x3590FCD88E857B31ULL, 0x929F5AD2C1D5561DULL, 0x2BD30A18E8DA7029ULL, 
            0x1F247E5FE7C1449BULL, 0xD12B6003613F3D6EULL, 0x5389C01C5BBFEC71ULL, 0x07CB13F7E3181364ULL, 
            0xE4105D33AC83FA3DULL, 0xB536D04998BD1887ULL, 0x59B602A200E06F1AULL, 0x7772215A93750C40ULL, 
            0x281F966B8D89AF62ULL, 0x39269B63CE222F65ULL, 0x7E38C1C625B026B4ULL, 0x3D7A541126810D78ULL, 
            0xB9C06A91D23FDAD8ULL, 0xE689E9455E787053ULL, 0x53D46AE0BCA8E7BBULL, 0x7AB9AA8094135C80ULL, 
            0x8AFBEBF03DEA1230ULL, 0x533BC592131951B3ULL, 0xA17146436A33F222ULL, 0x93ECCAF755C7978BULL
        },
        {
            0x096B2385B2B77F1CULL, 0x53CEA3AB30A87635ULL, 0xFF53B82E7CD550ADULL, 0x193621657A796F6CULL, 
            0x5DF551B236128D1FULL, 0xD1A26DD5D9D270AEULL, 0x72BF3AA71632DE41ULL, 0xD092C31E7DD2F333ULL, 
            0x801F852401AC04CBULL, 0x2ACCE6C4883FD211ULL, 0x444BA0CB99453A79ULL, 0x49A5921BAE856DB1ULL, 
            0xCA3BD4AF40AAAF0AULL, 0x2CB4A3B7F72E213FULL, 0xEE1E379EA4EB73AEULL, 0xF9AEB827483CC4B9ULL, 
            0xCC833C9D0F48D07DULL, 0x3D76A17A091C73CEULL, 0xA41523828802A29BULL, 0x661CAF8F5E46B799ULL, 
            0x6993EDCCBF484902ULL, 0xD1A3B2D2B6EDCA7AULL, 0xA0AB16243FF5B5D0ULL, 0xA60AD1FC4F51D7CEULL, 
            0x0F4DB86F5AE09284ULL, 0x5EEA0171256F2E52ULL, 0x346B0A9D367745D5ULL, 0x1CF404D3AA3B5A2CULL, 
            0xB2AB336E4A2B8280ULL, 0xAF5E46BBC09AB8C9ULL, 0xD123028AD9E4CD0BULL, 0x3FA015A0877FB4C3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseAConstants = {
    0x4E3C1E19C282C525ULL,
    0x62C1C39F0361804FULL,
    0x15338CC83A73BD9FULL,
    0x4E3C1E19C282C525ULL,
    0x62C1C39F0361804FULL,
    0x15338CC83A73BD9FULL,
    0x4EFD922C99644E27ULL,
    0xBCA81481580DE8BDULL,
    0xCB,
    0xF2,
    0x8D,
    0x9B,
    0x7F,
    0x2E,
    0x9F,
    0x84
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseBSalts = {
    {
        {
            0x76829FFFF080E1EBULL, 0x56CD24AF89DE357AULL, 0x6D6DA0184AF12597ULL, 0x95B100C9D44AF98AULL, 
            0x94EDDE408DAD7A57ULL, 0xB56AF5D2B8EDB7E7ULL, 0x9A0850B064E370B0ULL, 0x1B3588838208B39AULL, 
            0xBE494B3272E78841ULL, 0xF9243915D5084F86ULL, 0xAE1BF4E59985281AULL, 0x7C57E5A4BAFECA51ULL, 
            0xF6A30AD3B100F9E2ULL, 0xF28ED62C8F408A07ULL, 0x1B071B933FAEABF6ULL, 0xCD9BA484746C3E23ULL, 
            0xB4824388454D49CAULL, 0xD125D1D020223FA6ULL, 0x6D15477A60C41F7DULL, 0x72903C251AE7F71BULL, 
            0xE96242D0D4991293ULL, 0x30B850553032FA1AULL, 0x19D0F4498BF797CCULL, 0x8A8D86ED46EBBB96ULL, 
            0xDBCAE9A88289FAC4ULL, 0x82BA2F983853E750ULL, 0x9B503EA941D23BF3ULL, 0x88E1BC5AA3D2B80BULL, 
            0x8F71542CF3F2D2A6ULL, 0x191E8F2E1A27863CULL, 0x9CD6C93068D59239ULL, 0x76731CF5B679C6A9ULL
        },
        {
            0x1BE8586EBF9E69BCULL, 0xFD8EF38F95748076ULL, 0x39DA32F4750FDDB9ULL, 0xCF4C67E6F3E1F3A6ULL, 
            0xB35B8E0C37C205DEULL, 0x4AFB1E986B0B68F4ULL, 0x0F80CDF24EFBC748ULL, 0xE0DA859C79312C72ULL, 
            0xAE7067635881BE09ULL, 0xD792AD0DE465C663ULL, 0xFB26A6FD9ED0797BULL, 0x3B4D414029A7FE21ULL, 
            0x97B87B824A09199BULL, 0x61E58A4FC3B73AF6ULL, 0x9E87728AB016654AULL, 0xC3C96034DC9028D1ULL, 
            0x08668CEB079849E1ULL, 0x854A40BDD332DDA0ULL, 0xB7605737E3B9E3F8ULL, 0x39D5377C2DB8BFD3ULL, 
            0x1A0EBC5B7C66EB1AULL, 0xB574253B1EC8DDABULL, 0xE8AEF7BCF67E303AULL, 0x0A23BFAA816CCDE6ULL, 
            0xA598FAB4EA444676ULL, 0xABCCE32DB6C03BE4ULL, 0xF92E75592E629B83ULL, 0x9C81C8271EAB2246ULL, 
            0x2DEA4247581AC1C0ULL, 0x7FC0524AAFF632CBULL, 0x09451D7C1B3C2F28ULL, 0x652760E70ED757B5ULL
        },
        {
            0xB8884D8861B8AD5BULL, 0x654D1101F9F281A8ULL, 0x8B38C6BD460F00C2ULL, 0x2DC9337A92AB69A9ULL, 
            0xC66CE98D781532BFULL, 0x189200073417F3B7ULL, 0x5C1B3F216A3416ADULL, 0xA212259BC8283823ULL, 
            0x0DDB7B33D43944A7ULL, 0x74C0FF9AC9C16D01ULL, 0x3CE45D7B94394B3DULL, 0xEBEBF801A82B1AB6ULL, 
            0xB2E5437154BF9280ULL, 0x59F6D2F72FC1B2E6ULL, 0x27F79E33D6246E6CULL, 0xEE979B30D53689E2ULL, 
            0xFF860AE83E2C3267ULL, 0x6D2E5D7A8155FAADULL, 0x834CC7AB0ACA6F1DULL, 0xD973B208B5019800ULL, 
            0x325BDB77C04C13FDULL, 0xE364C006F6EC8C47ULL, 0x964DCD7E14DB3EA7ULL, 0x09DD0DC1B5E2A40AULL, 
            0xB539746FD286F93BULL, 0x20DCE4B6543EABF4ULL, 0xC6065DBDF8055B4EULL, 0xF64CDFA0766EC59EULL, 
            0x87A8576BCFC12BC9ULL, 0x0D9D03F66AF6BD7EULL, 0xBC0E630C7C4E5803ULL, 0xA75203783B628E20ULL
        },
        {
            0x2F4A976A32A33F6BULL, 0x7076995A17913D26ULL, 0x2F7A8AE98FDDF13CULL, 0x3BE8EFF4011EC963ULL, 
            0x1A4764898A66BF09ULL, 0xEEB299970C91E007ULL, 0x712C8C35F5D12806ULL, 0x04D359BB87F7BBE1ULL, 
            0x3C20B50D61009E8BULL, 0xFDB460F41D5414DAULL, 0xF548A368B7F8D949ULL, 0x281F2798B3BF3E16ULL, 
            0xC245F3607037B81DULL, 0xAC36EB8363A614C5ULL, 0x828081FC583CDFDDULL, 0xDC6E35CFCE404F26ULL, 
            0x737C0E6CC2EF9A8EULL, 0x8CCB917D72A2E2FFULL, 0x32FF4A085C920239ULL, 0xC8934D4DCA18D4CFULL, 
            0xF703A041F942C342ULL, 0x12AA1B93D0B4CB5CULL, 0x480026E8126A8B85ULL, 0xEEABCD2738B792D5ULL, 
            0xF9B09F653172517FULL, 0xAE090A3DC87FF52FULL, 0xE8F01796A10206B9ULL, 0xBFD34FB066F269FCULL, 
            0x71599D9B7E1637F5ULL, 0xE66496F7A1478F1CULL, 0x53EC026FF0A5A11AULL, 0xAEE220F99709CB7CULL
        },
        {
            0x33B253FD9038E500ULL, 0x885458D4CFD161C3ULL, 0x7A7E762CCDB95A75ULL, 0xEA21117C9B48E615ULL, 
            0x0AE7DEAAD1CE3ADAULL, 0x87C6176AA8B7DE33ULL, 0x9E7E05EDE2624057ULL, 0x3DF063498DF92CB4ULL, 
            0xD7486BF9B316D3BAULL, 0x68A566A7CBB4AA9CULL, 0x2E9CCB8F8235C6A4ULL, 0x5C0C11A0FF155BE0ULL, 
            0x3DBFF6F8D5B64857ULL, 0xAFBD9F70864FBB32ULL, 0x7DB19BA5911A5F44ULL, 0x4294F47149FE6F74ULL, 
            0x9AFFA0358E070C4FULL, 0x02233630D8B449E7ULL, 0x4533AE4D16EEA4C6ULL, 0x3D4FD10C9F462344ULL, 
            0x3D8E94CC93BEEEFDULL, 0x7D11EA5AFFC75B86ULL, 0xFB84DE8FFBD52B20ULL, 0x2AA5ABF789326B23ULL, 
            0x5021D579AB2C5B31ULL, 0x9F2F1DDDD7FF09F8ULL, 0x6C4A02D8D0359905ULL, 0xE78C27D18CC7F727ULL, 
            0x08003885A66938C4ULL, 0x067D097CF361E1C1ULL, 0xB61726EB2090840BULL, 0x01379B8F1128DD42ULL
        },
        {
            0x190A3D5180EC4165ULL, 0x08C247BD8879D3D0ULL, 0xBEDA98F497DABFF8ULL, 0x3B37CDA6D66D3CDBULL, 
            0x0A553682051FD25FULL, 0xD0C9E0CDCA2DFD8BULL, 0xE613E8F1081F1606ULL, 0x9F934773F6638C1CULL, 
            0xC100763526D208BCULL, 0x9942D8562C1E2632ULL, 0x4977BA7F45253AE8ULL, 0x62CB5F9A4FDD45D8ULL, 
            0x14DD198FCDC6D7A7ULL, 0xFF656245035B8E42ULL, 0x48493CBC5BE68F97ULL, 0xBDA2B00C579101C3ULL, 
            0xEDFA38FD583CE2B4ULL, 0xF0986D22F78BC5B3ULL, 0x3C6EBC8572EA96BAULL, 0xAE3C4DF662B95713ULL, 
            0x848C3B83E694C951ULL, 0x6E3D426B1118B7B8ULL, 0x5EF57401667B0E82ULL, 0x23D5C74787DA3C1FULL, 
            0xF5D740A0BC37A2AEULL, 0x046EEC2FDEDE4DFFULL, 0xC686CC8ABBB52F19ULL, 0xF91BEF237C61F717ULL, 
            0x04B0A434C59E505EULL, 0x2B23EAB200F24CA4ULL, 0x5273DC7FE3F7C007ULL, 0xE43783EC70B46019ULL
        }
    },
    {
        {
            0x8496BBC26DE11BDFULL, 0xE3A2396B1833158EULL, 0xCC5CF4BAC0301966ULL, 0xA78AFEB967456DB6ULL, 
            0xFA6E6B151310CDA7ULL, 0xC222C366EC220836ULL, 0x8FD9A467DE36D156ULL, 0x43EE4046D6A674B6ULL, 
            0x5702B8E98560E2C5ULL, 0x5A479B2952034B35ULL, 0x9592812AA61D5052ULL, 0x505A353AA72F852FULL, 
            0x1C216EC32B13D0D4ULL, 0x464E749D0B00B8FDULL, 0xD8B6F106A76422D4ULL, 0x7AF2B587F430A1DFULL, 
            0x59142E5476DDA721ULL, 0xD3F7C14AE7513E70ULL, 0x5E84D9E3902EA2A5ULL, 0xD7F36B771EA8B7D6ULL, 
            0x904DCBAC6D86FD14ULL, 0x9F520DA8A9CAC841ULL, 0x6445A4BCA3CDEB61ULL, 0x06221D4A1A446280ULL, 
            0xE4D53EAED81F4947ULL, 0xA49DA3ABE17C5701ULL, 0x8856D1EFC91ED0E1ULL, 0x2EC93928D26EC7C0ULL, 
            0xBE3417E452625FB5ULL, 0xAC6EA452E51568A0ULL, 0x75BA68F3A50B9C9EULL, 0x30EBD732B062B872ULL
        },
        {
            0xEE78D50AC82217B8ULL, 0x8C83D34A7FDBF90DULL, 0x76FBAC84BBAB12F9ULL, 0xD1F7C94C7971F5CAULL, 
            0xAB60749D40F2B807ULL, 0x594F701993D83C17ULL, 0x60DBDB89E6865CB8ULL, 0x1F1B35CE2EFF271DULL, 
            0x19B94F4A7724C092ULL, 0xE145B282BF7C44CBULL, 0x4D26E609B1D9847CULL, 0xFFDCB8F84E055696ULL, 
            0xC8FE51EABE15C46EULL, 0xB6ECB5132590FAE3ULL, 0xBEE8509065A0D0BCULL, 0x6F40CF2C9F679856ULL, 
            0x4B744C6F623937FFULL, 0x9FC1BB7B6399240DULL, 0x5A75F106BC04D2D1ULL, 0x250B34DB31B4F7E4ULL, 
            0xC40850B6D0FDA72CULL, 0x01117E43426FC916ULL, 0x687B1CBF9D99EE1DULL, 0x17387EF93C711985ULL, 
            0x953A4338D1F909CAULL, 0x70E67E1A83E1884BULL, 0xBFF38B5C2AC5D9E7ULL, 0xFB34A21A0BF8F7B8ULL, 
            0xECAE5881706B7192ULL, 0x26EE906F936735A9ULL, 0x23373F155D807056ULL, 0xFFD8C013EA364114ULL
        },
        {
            0xBC7EEB573C08EB75ULL, 0x6CBE853958791714ULL, 0x9079D5FA796F0706ULL, 0x381416DD141B108DULL, 
            0x35DE9FBDFAE05CB7ULL, 0x9890883EA435AA02ULL, 0xD5BA96DECEB1395BULL, 0x8FC7B7B11CCA486AULL, 
            0x607975F73B38534FULL, 0x50B3AC5A9B90936CULL, 0xCC7FBFD8129659B5ULL, 0x0822501745332B6DULL, 
            0xCE6F40C8CE507A6FULL, 0x2C7525ADE9628510ULL, 0x486A626D1900B418ULL, 0x588970B219E7B31FULL, 
            0x5C4C794BA69AD09DULL, 0x843F8E6A87652CCCULL, 0x1228520A227516BAULL, 0xA180ADA992971502ULL, 
            0xF66238B7E7E7A711ULL, 0xD7F218FBB8B1D904ULL, 0xB3175A459FE24CB4ULL, 0x529570D0A56B73DFULL, 
            0xD5995792ADDBDA36ULL, 0x81C3B1C51B096F0DULL, 0xCDF489F5BB55EB44ULL, 0xEDBD86D0566F2D70ULL, 
            0x19605DB9EC26D426ULL, 0x1850D87E4C7F8861ULL, 0xCEF2E5C9C4B37535ULL, 0x517130A3C6621D2EULL
        },
        {
            0xCEFC6C42DF9D95CCULL, 0xD05689DD52E54641ULL, 0xA08B8FF482BFF581ULL, 0x90AE28F26C8863D1ULL, 
            0xB4210D33E09FAF9BULL, 0x9E399B203B50A230ULL, 0x92E1DF076156EDE6ULL, 0xF2B48836DAB24423ULL, 
            0xF0FCA4F472C2C1B1ULL, 0x47620E3D57ACF057ULL, 0x88DB10B13B9A9EF8ULL, 0xDCBE7E60B9B4E3D0ULL, 
            0xF6523B716F07732FULL, 0xED8E360A24A4D2A7ULL, 0xE4680FDC82E5C5EBULL, 0x17AC3596039A9AAEULL, 
            0xB32E0A3DC2B51DFCULL, 0x8D12A01ED88BE587ULL, 0xED4E814B3E5545FFULL, 0x55904EB520BC5872ULL, 
            0x5987FA057D629BC7ULL, 0x0B0EBA80CA563572ULL, 0xBB1C70E26C6BC8CBULL, 0xD3F387CEDBF2A371ULL, 
            0x338FE366D510313CULL, 0xF255B554D1EC2F68ULL, 0x76EB3C6E7B78B143ULL, 0x75660E453EDDEDA5ULL, 
            0xB52A4D45C308902AULL, 0x63478E681C8431A3ULL, 0xC1C1DEF7F19B82ACULL, 0x7F593E7C5B7FD8DBULL
        },
        {
            0x1D7221B83DE91D5AULL, 0x8BD3D011A05C0472ULL, 0xB7C582EF354BB6EFULL, 0x5314F65ADF31F952ULL, 
            0x3298609A3C75E4B7ULL, 0xC5A7E6839CF59F23ULL, 0xB0D8C7C0F19C339AULL, 0x90A799087F6F3129ULL, 
            0x2B3F54035FAC5150ULL, 0x4799AF6C0465CA5CULL, 0x2659425D7B8606F7ULL, 0xAB458346B3E95CFFULL, 
            0xDC5C716B0F7DF5FBULL, 0x6CEF942EB0CDE6F7ULL, 0x5C870DFC26012BF4ULL, 0x69257BDEE3CFC644ULL, 
            0x05B60BB9677FD43DULL, 0xCCBD348B23327EE0ULL, 0x35724BA98BFE6081ULL, 0x356D15EF6D88EED0ULL, 
            0xD0372C44640680D3ULL, 0x9987B4B78B85D65DULL, 0x62F02B244B01CFC3ULL, 0x9EE74286F6AAC723ULL, 
            0xED076F6BBBEFA971ULL, 0x30E6BCE8B82223D7ULL, 0x73A626582472C2C0ULL, 0x6A8A3D7D6BBB875BULL, 
            0xA2F6B7D61C0EEA35ULL, 0x0E42B75F1A81CD96ULL, 0x274139F37EDD4B9BULL, 0x4E584B8FA20334F1ULL
        },
        {
            0x23B4DBE1AE5B1840ULL, 0x988B4FE3AAFD34D4ULL, 0xF809E8894FCE36EFULL, 0x2C2453179F79300AULL, 
            0xF83A64FA43904463ULL, 0xBDB661BA4BB0F71FULL, 0xB03F536E7D7CA02CULL, 0x72C493FAF9283805ULL, 
            0xA79AD34B5B08267CULL, 0xBAE0DC41A4FB85ADULL, 0x8C6AB66FFDE6C44EULL, 0xE052C536E1146405ULL, 
            0xA5147E6072880D4BULL, 0x4D65291C2DF813CBULL, 0xD0D2649109B2C742ULL, 0x6B630D6A041E7CD3ULL, 
            0x8B02F86CF0F5FD6AULL, 0x49B51204EA700ED4ULL, 0x2DB821F1B1770DEAULL, 0x85E6AF331BD06D3EULL, 
            0xC7A17466F9607140ULL, 0x764105F4B705D3FEULL, 0xB40085A2C4B2E083ULL, 0x995138213299252CULL, 
            0x50CA43949208411CULL, 0x934A25795C2014CFULL, 0x8F7A4BBFD5543E64ULL, 0xD7037EE0F8A8CAC5ULL, 
            0xF730247AAA141DAAULL, 0x241BEC02BD5EF00DULL, 0x5C4A2AA0B0D0A434ULL, 0x228F2C1D8D565087ULL
        }
    },
    {
        {
            0x909B5FA3AC7B0687ULL, 0xF16EAF076ACB998FULL, 0xEAFA2A6A94AEDA95ULL, 0xD19BE94B9AB3391CULL, 
            0x72D8662D3617EB93ULL, 0x7A786405559A1589ULL, 0x42922A13DC43A92DULL, 0xAFE53B1247D4DBB3ULL, 
            0xB5772B1BE58DF0C5ULL, 0xA8732A8E50A81E82ULL, 0x6C3CE514B103F6EBULL, 0xE2BFDFC38EB54A31ULL, 
            0x0BBD21B67F2F5E98ULL, 0xB56858C4E2FB9BF3ULL, 0xB42D92695AFD31CDULL, 0xAC6C52D648571463ULL, 
            0x3118B17BD8E6815FULL, 0x6FE5DB4BF16B7DD6ULL, 0x928BB4436BCDE612ULL, 0x3EB1C96F56E88CBDULL, 
            0x8B4989ED11AC067EULL, 0x8D6D9200C6AEE455ULL, 0x96F1661160992FD3ULL, 0x91556B0D9824358AULL, 
            0x04FCF58D3A54B048ULL, 0x859826563CB38364ULL, 0xFB3DDFBF40EFDDCEULL, 0x66E8B80B6D9D9902ULL, 
            0xEDFDD770A849B134ULL, 0x4E3FC7D8EDC2F62DULL, 0x1D5F3C2957B2E63AULL, 0xBF57914B549B4636ULL
        },
        {
            0x936B95CE2FEBA712ULL, 0xB66F5CBC5CD7C75CULL, 0x0863269CED5A96A7ULL, 0xF53A3716C52FB73DULL, 
            0x6D2B29CBF33AF8FDULL, 0x1919304A861DC8BDULL, 0xF79BE4957050BF48ULL, 0x63B0108C367428DFULL, 
            0xEAA421B57BC5297AULL, 0xE5231484AFD16572ULL, 0x8B6A6C8339965368ULL, 0x8290FCF9185AF2D5ULL, 
            0xB1475DD33E4ED534ULL, 0x0BA748281011B15DULL, 0x418275FF735AB03DULL, 0x1E5034A824221BB2ULL, 
            0x5119C2EDDBEE5AE3ULL, 0xC4EF33FC2EB403A6ULL, 0xDA1D7F1373FCACE5ULL, 0xD6A9C7BA285B7229ULL, 
            0x85E286B90B246869ULL, 0x81151B01E1BB5AA1ULL, 0x0CC25630A4BFC871ULL, 0x102B8D26F6A049C6ULL, 
            0x20CC7CF4B3E86F23ULL, 0x66A81F88766CEAF2ULL, 0x9AB33D91BF75AEF1ULL, 0xF9BA4BF4F217F6ABULL, 
            0x4015C0FCB60242B6ULL, 0x6E15F6964DC98A42ULL, 0x5A2CEDC739F0A982ULL, 0xD59CEA7D8413CF67ULL
        },
        {
            0x54D10BF95EB8C97FULL, 0x6477F0DD454029F7ULL, 0x11FDAE4A142FE97AULL, 0x1A71D8FA346ECB09ULL, 
            0x59575F1B3C3A0806ULL, 0x7F2940002BF07B9BULL, 0xE3D05494CD032CE8ULL, 0x44951C1BD44E8492ULL, 
            0x37638BB61DFDA3FBULL, 0x5C0032BAF1572DA0ULL, 0x7BD83AD268B9DDCAULL, 0xC2F302EE583A184EULL, 
            0x2D2D0470B72A7801ULL, 0x0AD03D02E0ADA09CULL, 0xB5840932CE66803AULL, 0x1A779495D5C0AB92ULL, 
            0xAD4A479960F56F1DULL, 0x0DAF772D2BB1A06DULL, 0x42999C13812D2EEFULL, 0xBBA98D73E1C0B3BAULL, 
            0x132CAE067ECC0E01ULL, 0xFB4FB0016D8D0636ULL, 0x75E00E4AE52E1B7FULL, 0xC0A961A6F00144A9ULL, 
            0x33BAE86C0658FD48ULL, 0x0970EF9C58CED944ULL, 0xAA16D4C2BD4A8761ULL, 0x8DE0AE17858D9AF3ULL, 
            0xFCADD3E9EBCC1E09ULL, 0xAE6145D1D3D746F7ULL, 0x871FBFDF1D3A263AULL, 0x2237ECB383B88A86ULL
        },
        {
            0x00228A675440010EULL, 0x0BE9207CBD3F6D5CULL, 0xD2F32FE3B0E0041AULL, 0x88D6355DF61F3E27ULL, 
            0x0F70DBDFC360CC28ULL, 0x49A5F345FC5D5F32ULL, 0xFAE1AB04E93CE36EULL, 0x8E98A23A618ECA18ULL, 
            0x32A52707888D1924ULL, 0x6F12BFCEB20CE44BULL, 0x18299FCA552D3A79ULL, 0xA9A0505F7E92B93DULL, 
            0x14358636436616FBULL, 0xFFE9078E19D7A0D6ULL, 0x0F70FA80E1FC48FCULL, 0xFDD7661C04D2CF18ULL, 
            0x8331975D390042CBULL, 0x7D09BCA8DCBF6A44ULL, 0x42F1F38F21BFC8EEULL, 0x1E8049D298904496ULL, 
            0x949E706FDDC02FD5ULL, 0x6097FD427B65B0E7ULL, 0xC69F2B8817175FF7ULL, 0xAD0D6B68ACB1081EULL, 
            0x765163F6E7CB296CULL, 0x4E8842E27ECFD94FULL, 0x7BB5B7BE53597696ULL, 0x400AD872C38CA77AULL, 
            0x55AA0242FBC15FC5ULL, 0xEE07EC0B582BFFEDULL, 0x2C18B9EF0D94930EULL, 0xDA396CF63FDB9FB3ULL
        },
        {
            0xA089271290174527ULL, 0x68953904E18CDCA3ULL, 0x5C10B955CDFA00D8ULL, 0x6E5F5ABCFA148FEFULL, 
            0x9400404063390420ULL, 0x5F018A09E98EA049ULL, 0xFA2293F41EA78DE5ULL, 0xC9C277111B501CAAULL, 
            0x681FF933F0CA4BF8ULL, 0x0F25B294CC369411ULL, 0x7376380F746D81F4ULL, 0x0A30663C2B53FD84ULL, 
            0xF08493C24FC0003BULL, 0x62855DB174133952ULL, 0xC603D4DED3B9E49DULL, 0xF1B325702D5E2147ULL, 
            0x994B907B74EE56CFULL, 0x92899B8FA8DC5F28ULL, 0x760FA698B23507FCULL, 0x5EC076492B025213ULL, 
            0xF542D71BA660233EULL, 0x264F13881C18EEFBULL, 0xACCF8B779C711137ULL, 0xFB8C240489A0C4E0ULL, 
            0xCFF4F42DC8783656ULL, 0xEE132AB6C6869BFAULL, 0x54AD9CA4D9BB92B2ULL, 0xA6D017CE717DDA9FULL, 
            0x5CE11E16020A414BULL, 0x6051F4EF921A845DULL, 0xB87080A4073E42B1ULL, 0xC52AEEBF6F3B3FE1ULL
        },
        {
            0xE53E20C9218749E9ULL, 0x9C3AEF60ADEB6289ULL, 0x43BB4DBF297E8E78ULL, 0xA993F91E34B1E003ULL, 
            0xA307D3627C5DAF19ULL, 0xDE3C93CCD9986906ULL, 0x936C428B3F38B600ULL, 0xB80AAC4E1E20D8ABULL, 
            0x16B16E7CF4139394ULL, 0xC1945E7389D1E661ULL, 0xBD5C8BD4EEDBCADBULL, 0xB5AFF4FB67DAEF64ULL, 
            0x5E750B6EC864BA0FULL, 0xEF2F606B264CCD4FULL, 0x54B984E14ED98214ULL, 0x90F0B79E0803CA27ULL, 
            0x319612F0C52C2716ULL, 0x0555C7F5F93DC2BAULL, 0x3376AB82E4EB4585ULL, 0x3AAE23209235E692ULL, 
            0xF32A1E3813A6D695ULL, 0x872E1731149C0648ULL, 0x6321BBA67D449C37ULL, 0xB29DE20473ABF025ULL, 
            0x484B8698F84E60A4ULL, 0x8B103FBE5F5B340FULL, 0x4B7EF80EFC1DD75AULL, 0xB2C26B4B312B6D16ULL, 
            0x75FD0454388AAB12ULL, 0x395F2DA1A71B5BE8ULL, 0x01A48D482F79B071ULL, 0x43CB30EC171E7B3AULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseBConstants = {
    0x551B5207EB30468CULL,
    0x933916BCD32D311CULL,
    0x18C2F405F9EABE43ULL,
    0x551B5207EB30468CULL,
    0x933916BCD32D311CULL,
    0x18C2F405F9EABE43ULL,
    0x8E4445DD39FBF73DULL,
    0x03252AB406743B0BULL,
    0x94,
    0xD6,
    0xE3,
    0x85,
    0x53,
    0xDF,
    0xBC,
    0x57
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseCSalts = {
    {
        {
            0xD749CAA43ABFC353ULL, 0xC23A28A6B3A60761ULL, 0xB217EA6300F935D3ULL, 0x466DD35137D3C6C7ULL, 
            0x71D9C145D766DE42ULL, 0x8F5852BC3B1C5F2AULL, 0x5A6111FD18C9FD2BULL, 0xA6E073CC10C5DE57ULL, 
            0x711081A8E3CBA7D2ULL, 0x168B2F61F43D09FFULL, 0x9E1D1160CDABEE77ULL, 0x90603A5D821D5A88ULL, 
            0x656FB715B98CBA4BULL, 0x8FF0D6A7FF95FABCULL, 0xEFA2A2BBD13DD87FULL, 0x2F03101764DCDB8AULL, 
            0xD1EE2D2C34546528ULL, 0xE83151D1A7C45A8AULL, 0xDE928016939149A8ULL, 0xF86FCB172870D088ULL, 
            0xAAD000458F7D0F31ULL, 0xC266FD732FEBF9FCULL, 0xFC818BFB1C991C37ULL, 0xA2BEC37C2433907AULL, 
            0xC16239432D9F8181ULL, 0x7AF5F9D2D9C2E389ULL, 0xBFD22F281A24A2A7ULL, 0xEF75F87E1D70550AULL, 
            0x7CACBFD764C2136CULL, 0xE3D7B7CBA4D76397ULL, 0xA3448AB61C384828ULL, 0x271E99B391028E02ULL
        },
        {
            0xA334F94D29932385ULL, 0x60F5BE9904A6B967ULL, 0x165EB35A84F65A05ULL, 0xF124049FE59BA894ULL, 
            0x87CDC77EBED36F82ULL, 0x57825C822C25396AULL, 0xC4C049C731684B6BULL, 0xF8685EF4411D236EULL, 
            0x70ABA2079B97A94AULL, 0x907D0566B3D28E76ULL, 0x607BE98FDFCF51F0ULL, 0xE6FF370AF8369DDDULL, 
            0xFD6C1457151DB64EULL, 0x7F1A99034B8329D7ULL, 0x972192F33094B4D0ULL, 0x13E9B581D60C89CFULL, 
            0x68BFEFBBCDB82A1DULL, 0x1182355DA4805A90ULL, 0xF979E39456B1E090ULL, 0x4924525F7AE47A11ULL, 
            0x2307D82FD96AB5A7ULL, 0x240A33F1A602958EULL, 0xC47617B8F0B59CF9ULL, 0x263D9C2FC51C1711ULL, 
            0x654BE315FD07C70FULL, 0x6305E46EBC9AE029ULL, 0xD0DE8BDB8B429AD7ULL, 0x8F916950194233CCULL, 
            0x807ABD4D42491207ULL, 0xE11A5A71FD5CF0D0ULL, 0x66D8B99A5119F4FCULL, 0x2BEEC3406C0D88A9ULL
        },
        {
            0xEC6386C6A0A3BC4EULL, 0x49F5A8F3F9981C71ULL, 0x24E2E60CE500DF4EULL, 0x9055F80CF42F75F9ULL, 
            0xA13DC409BB058C6AULL, 0x3A4CBBAA5F0403D7ULL, 0xACAF7DD73A07CAFFULL, 0x1E9C2AF437F64AF4ULL, 
            0x06918324D2DD2B8BULL, 0x82895D1A506238F9ULL, 0xC2CDAC20328C51C5ULL, 0xB51653FF64469FCDULL, 
            0xA054FDB1678C7163ULL, 0x6C1ABDDFDF7FFEDEULL, 0x3DA43EC5B97DCBD7ULL, 0x884B6189CD34F68BULL, 
            0x5E60C9C17512B751ULL, 0x9BC82C828F518EF8ULL, 0x06C18613810F3C2FULL, 0x559F9A11B1B44E0FULL, 
            0xA4D5B21858A28780ULL, 0x824E11D79C10A96EULL, 0x92F2960249C715EBULL, 0x31B7C0BE5F5D62D3ULL, 
            0x4CE809C6B5A4D9B0ULL, 0x10FB000EA4617AA1ULL, 0xFB724DC6C7DB1C2FULL, 0x8A44D11EC103E58CULL, 
            0xEA56C7240B8EF59AULL, 0xBB6BACEB1B63BFA4ULL, 0x33555990907F715FULL, 0xB507031B1671A9A1ULL
        },
        {
            0xCD17F1E210600F1AULL, 0x7F92B3F48915C29AULL, 0xB4EFD9ED04923ED6ULL, 0x308ED429DB96B86DULL, 
            0xC091C7478CEA7D9AULL, 0xD319EB76E007F090ULL, 0x2C2BFD22F3F6D8D6ULL, 0xDC60F729B1A5424EULL, 
            0xF8AFF78DDAE483B0ULL, 0xC9092F12FB2FE81AULL, 0x94A504744566D6F8ULL, 0xFB5F8DFF09191229ULL, 
            0xE5A4F9E476E01CF1ULL, 0x421A9AD3CECFDF7CULL, 0xDDA111B5B995C456ULL, 0x32DADF0731623E71ULL, 
            0x76C0B6594C1467B0ULL, 0xF1420187899F2FCFULL, 0x26E2D45BF18FEFB8ULL, 0x0D2152029E135B56ULL, 
            0x2CEB207AFDF3D2D2ULL, 0xF188F297AED83DADULL, 0xD89515BE5D3F1944ULL, 0xE838047AD9E26FE0ULL, 
            0x6D8C765A1E29D71EULL, 0x63CCCC4416B17A34ULL, 0x389E44E60EF75ABAULL, 0x0AEAB2BA724D5D0AULL, 
            0xE7C75E8BD0DA3747ULL, 0x5EF77A198CDA5699ULL, 0xB31E566DDCAD7603ULL, 0xF6D507F8DB416BB2ULL
        },
        {
            0x2D6A1B59078C6FABULL, 0x1FD67222D7E1A446ULL, 0xD4349DFA5AD4199EULL, 0xF1EF586FDC2182A7ULL, 
            0x72FF7E3C4375FFECULL, 0xB730F80C4930EC18ULL, 0x58F94818AEA9D327ULL, 0x187F82D7A71FB737ULL, 
            0xE9FE715B5E8830D1ULL, 0x74E3D9975FBE6292ULL, 0x582ACD25749441DAULL, 0x1D9603B63640F475ULL, 
            0x0DE84BA99AE9598DULL, 0xBC8477A46DC4C4B9ULL, 0xE68FF085499C1B19ULL, 0xF368E762264AA1B1ULL, 
            0xBBCBD071173E84E9ULL, 0x4F02B24FBA2FA1D9ULL, 0x1818A3844614B33EULL, 0xB1340CCBFB23EB2DULL, 
            0x024472840A10EB03ULL, 0xD48E31312C027A38ULL, 0xEDEB75EA36EFBD02ULL, 0xF81666E39E0FAF9AULL, 
            0xB64301A2CC606ACBULL, 0xAEF24517EA4307A8ULL, 0xFC73097D31A09C97ULL, 0x0A23F1F9A2025803ULL, 
            0x9D7CE3FBAD588828ULL, 0xDAF8A9C468DDACD5ULL, 0x9580729FEE00B5E0ULL, 0x42C69A9E516DA241ULL
        },
        {
            0x4FF17C486E769DAAULL, 0x70B8193033EFE642ULL, 0x190CBF2E830A777DULL, 0x0B701F8AEB63FFE0ULL, 
            0x59D01406E366D816ULL, 0xF3FE95A289C50517ULL, 0xDE2A4B5753F57FEFULL, 0x77CB3CCB04212B42ULL, 
            0x4B20C6C17DB1F5A9ULL, 0x6A3834DC47F15108ULL, 0xECB752602551CB86ULL, 0xA7CC0D539F2C56E2ULL, 
            0x81197FF1C9101971ULL, 0xC81A15C61542A15DULL, 0x1EDB4C05A14F7AB1ULL, 0xADF7A3DC9162EA8AULL, 
            0xA2712F0B00AC25FFULL, 0xF63968EFF0DB6C30ULL, 0x02B98FEB6A03B20EULL, 0x0879135C1DE0F22FULL, 
            0xD624A3154D695B0BULL, 0x37EAB5EA6D6A1C54ULL, 0x3488441714EE20B8ULL, 0x994B1F9ECF607432ULL, 
            0x80149EC7BCA3688CULL, 0xAC1B86EDDFD43A0CULL, 0xFAFDD992B7FD70A9ULL, 0x4A2550827004B43CULL, 
            0xD20EE5F31271636CULL, 0x5AE0668313CC4CA4ULL, 0x33FA8BD605BD8A27ULL, 0x03A002F30E65E7EFULL
        }
    },
    {
        {
            0x5B91D491E7C79ADFULL, 0x2E67988B7C6F2204ULL, 0xECF09D66971F7E35ULL, 0xCE80D83BB88C8DC6ULL, 
            0x220E7734F94F1961ULL, 0x1CDE8B2F0195FA0AULL, 0x11A7CC4E81BF64EBULL, 0x9CFDEA87A726E585ULL, 
            0xA2A0C6BFA375C563ULL, 0x65BEA74E1AD63895ULL, 0x8D98A3FFED5D6D4EULL, 0xA827CAD114320371ULL, 
            0x3659013171FE09CBULL, 0x5A0B729AAA6BDF36ULL, 0x1CE99237151D602FULL, 0xA6920CA422BE78C9ULL, 
            0xDA6FE769B35A3D84ULL, 0xC9F1C378D95AEB89ULL, 0x90DCCD29E141F25BULL, 0x904D674A85D17F9DULL, 
            0x0402E32469EE357BULL, 0x9569D0A6CC9E11E9ULL, 0x3A6A3553DD328E64ULL, 0x393389FF22667727ULL, 
            0x90BB565C1BB26737ULL, 0xC30781FB821D6FE1ULL, 0x65D55B82D80EF03DULL, 0xE7C6BF0E7C5EF0CCULL, 
            0x6A687AA2ABD16264ULL, 0x4A8284341186BD66ULL, 0x4180BBC0BCD3AD00ULL, 0xC0477F0F8B17EA19ULL
        },
        {
            0xAFE8FC503C6A1AA0ULL, 0x0B2E207856F62038ULL, 0xD3344BD98FCD97D1ULL, 0x8891B0F97325EA07ULL, 
            0x948EE7B0B957ACDAULL, 0xF939C210700E2E79ULL, 0xBECEA89239B02C1CULL, 0xC30CF890AC666A2CULL, 
            0xC1D35312FBEAB32AULL, 0x17D70DD49DF8C20EULL, 0x3844FC9728B926CEULL, 0x66C61F256048498BULL, 
            0x2D9F81B233900C83ULL, 0x71AA89DA648066E4ULL, 0x6EA1393285861403ULL, 0xD66D9A1863062E72ULL, 
            0xC57DE5BA80E7BD64ULL, 0xA6FA123B27C83363ULL, 0x6BF56ABE27ACF03AULL, 0xEDDD5CF5380316FDULL, 
            0xD5D7ACCE9D8DAB94ULL, 0x3A0356A54BA06721ULL, 0x90F818CC9F0BC614ULL, 0xD69BA0B9EEC098F0ULL, 
            0xD9D4BBF3A3FF9AC0ULL, 0x86E7DA4B743D971BULL, 0x875579F716D6EA07ULL, 0xAB8A506618CDC1CAULL, 
            0xB4BC72F0387833A4ULL, 0xF2700BE46C5C7553ULL, 0xDB1B65A4B3078228ULL, 0x9D6BB18E3628D412ULL
        },
        {
            0xBEA5E28365483CC6ULL, 0x6501B76D006A5B32ULL, 0x29843561BF1FFE18ULL, 0xBC698185BCD6237FULL, 
            0x8A62809CEC1EEE85ULL, 0x223D3285188BD130ULL, 0x33890920B80A37E2ULL, 0x27FF6C5A539D10DFULL, 
            0x1D250C81B1948C71ULL, 0x99E7D41CE3A0D485ULL, 0xFC10122063516FB9ULL, 0x9B40FF50597254AEULL, 
            0xE993C5B3BAD75AE5ULL, 0x50C8EBD25BA23E52ULL, 0xF2BCDC58F5C6155AULL, 0xD41C0896BB705270ULL, 
            0x58B781A966A9684EULL, 0x4D1359C18AA2B583ULL, 0xC246065E046414DDULL, 0x7BB0F2C12A936903ULL, 
            0x9B2FF7A3D2544C9FULL, 0xCD690D4475CBC883ULL, 0xC7BCD7AE7262D579ULL, 0x6086327E04041D11ULL, 
            0xD92BB5B09DAE7FB9ULL, 0x3EB3C5006F09B5C0ULL, 0x5578BC65432422F6ULL, 0xAC4D8CBB2ED3673DULL, 
            0xAAC936E37C57D76EULL, 0x3E835E73F3DC5501ULL, 0x30225B3ED3DF0259ULL, 0xF0CDF6910CFB99FCULL
        },
        {
            0xE57FFE038916857EULL, 0x79E53754B0CEC117ULL, 0x6E28435916D3ABC3ULL, 0xA4AC8D2FE9B13304ULL, 
            0xE18F1C015EE2027AULL, 0x3FB8026603263234ULL, 0xE6F9B41D3188618CULL, 0xD4C4AD975AFC6BF8ULL, 
            0xD5E09FBA7CA7BC88ULL, 0x6E789BEEC868DCD0ULL, 0xD886CF27E90E54B3ULL, 0xC413C67D05BDCA2EULL, 
            0x1849A5F8D7FCA8ECULL, 0x8AADB3AEDC65D664ULL, 0x0415F6C8F70C510DULL, 0x13CB8502946420FEULL, 
            0xB923F1E9A97816E1ULL, 0xD3A8671366958CF8ULL, 0xCC60E840A61EAA6AULL, 0x14FCA2472022CFEAULL, 
            0x4ED9BAEFB6B72B40ULL, 0x2173DE93841DFF64ULL, 0x7F7EF8A490286A58ULL, 0x3129B4DE90C9CAC6ULL, 
            0x8EC4BB3E87FA449EULL, 0x108733DD4D2F8748ULL, 0xBE9CE47CACF8047CULL, 0x60351032825A9AF1ULL, 
            0x3ECF2454C81FA93EULL, 0xD18CCC6C086A7FC1ULL, 0x36F6C470E4D90BF7ULL, 0xC1B43879D166D0CAULL
        },
        {
            0x86C98ED5C11E971EULL, 0xD24CF014D7B1F5A0ULL, 0x6E66CA86AD975619ULL, 0xBF46AB5463C8AA3CULL, 
            0xB25E6AB9132443B8ULL, 0xE524EB75370DB67DULL, 0x72931150B9294506ULL, 0x74227866E8C46F33ULL, 
            0x27449DA3B82F642FULL, 0x6BD66D182BAD12C4ULL, 0x806D506D68903618ULL, 0x2EF75AFB198F74A6ULL, 
            0x22510538B0BEC72FULL, 0xCE2EC63D1E44E95BULL, 0x77F2B62A6D50D009ULL, 0xCD21FA4C63D1F05CULL, 
            0x02B35E9EF8F27FC8ULL, 0xBF6CAC939B9C295FULL, 0xA612562AF217B178ULL, 0xF57B9DBE42AA3F31ULL, 
            0xA08DF7C613A6631FULL, 0x97F911B129CE0291ULL, 0xA68AF56B1E98ABF5ULL, 0xB5368D5ECFA84E82ULL, 
            0xE5E2E78D676116B1ULL, 0x4D6F6F45AF32F795ULL, 0x9B38AC35C936E994ULL, 0x8C1FEC324985E942ULL, 
            0x3567D4710DB66DBCULL, 0x7EA482B13FEE6993ULL, 0x1C66C9DE9B03539FULL, 0xB24218C73AE7C371ULL
        },
        {
            0xA59F7095E3AD5D9FULL, 0xE125CBA17D8A4B2AULL, 0x12A01BA075CBB87AULL, 0x3D941A088842BDE0ULL, 
            0x132E564EE6257675ULL, 0x04FE3EF85773815FULL, 0x8B76119D0D68C1BDULL, 0x17C2772796DA310AULL, 
            0x5B346569894752D4ULL, 0x5BFC42EA0E1982D0ULL, 0x3564ABE258A7F771ULL, 0x26ECBCA609E096E5ULL, 
            0xE2D5687C81F4B0EAULL, 0xBEF0AC7B3A00523AULL, 0x6D22A27410C4E577ULL, 0x0AC6724062238F02ULL, 
            0x45CA3647234C0D3AULL, 0x3DEEBA1D9C1B79E1ULL, 0x2F9EF48F929D0739ULL, 0x08073EADA0383B2CULL, 
            0xC01F519784E0BF84ULL, 0x6EB24FDBC483A1FCULL, 0xA3E9920D3B6E5B70ULL, 0xADAED0AB8B4383A0ULL, 
            0xFD8C62746E676CF1ULL, 0x739C01FF55C26E8BULL, 0x521374A92E5BACC1ULL, 0xC817085765751D29ULL, 
            0xD57363D113EF4EB9ULL, 0xD63A7DC41F96E7BFULL, 0x6F4E4D19E586CA5EULL, 0x663078863573AB69ULL
        }
    },
    {
        {
            0xBC3442838F156D69ULL, 0xB4E0C25A60B66669ULL, 0x35BD76B886D6F74FULL, 0x396200968644EF7EULL, 
            0xFB92D8C3815FAC27ULL, 0x7A7412D20A22FFBCULL, 0x940B35D6CC3FE763ULL, 0xF1A52870A0BF4237ULL, 
            0x2B71F4C705396405ULL, 0x3CFE956B3158E3EFULL, 0xF2EFC091896AA8D0ULL, 0x7355BCB3A11D214FULL, 
            0xA482FE408FA37371ULL, 0x40ED3078FF6F895EULL, 0x98F51D1A5A87C0BCULL, 0x5D567F29C9DDD371ULL, 
            0x927697E4CBF8B0C9ULL, 0x130BE205E301CA7CULL, 0x0C7ADF323065FAE2ULL, 0x97660BEB994BE4ADULL, 
            0x10461A93B43BA131ULL, 0x16C5D086E41331FCULL, 0xFFD30E4121FEE43DULL, 0x141C5554391392C3ULL, 
            0x015D6E08FADD1C93ULL, 0xDF013F4558FDB0B2ULL, 0xAF917E9E880ECACFULL, 0x5997C7D17BAE0C47ULL, 
            0x27BB775D20087932ULL, 0x6E809D23DDBD39B1ULL, 0xC1FF238968D0C5E2ULL, 0xD269D760E534DD71ULL
        },
        {
            0x4A04F4D8F34EE85AULL, 0x8B3C977C24C7E902ULL, 0x8F92AE3B308B0B3BULL, 0x068EB5606CA9DBB7ULL, 
            0xC017109AC02C3679ULL, 0xA217A64D723C3F52ULL, 0x9984D9B5981A4579ULL, 0xCBC70D0D8EB5A37CULL, 
            0x07511D5A6BD2F234ULL, 0xD2A01939496F4497ULL, 0xF8EAD451CF492C61ULL, 0x6ADA6F4C957BE198ULL, 
            0x7ADE6684ED1857FAULL, 0xB27ED20BB77C8EA3ULL, 0x0C28E25B82CEDF1FULL, 0xF78B2DB7438AD796ULL, 
            0x22361347DBE492D9ULL, 0x91D94BAEEF37BB82ULL, 0xEEC0F8D8053E5FB4ULL, 0x7D26A070C0FBF1DAULL, 
            0x49269C5B3CBB142DULL, 0x890324CBD050A518ULL, 0xF1AACFA9417D22A4ULL, 0xC541EAF6C4B6E126ULL, 
            0x271A519240ECEDCFULL, 0x11C16EFC431AD833ULL, 0x68F25562E345C5F0ULL, 0x3229245D2176EAE6ULL, 
            0x460CE97CC9ABC672ULL, 0xF06FBB2671D836E2ULL, 0xB9BE5F1F6FAD8657ULL, 0x82DFA3D8FAB21A2DULL
        },
        {
            0xF8C03BBE41F0C1A7ULL, 0xB5062FA248B194BDULL, 0xDA8106A2D1C480D6ULL, 0x67C89445870B88DEULL, 
            0xE2C41945400D07E5ULL, 0x02B560104FB76018ULL, 0x9B6F2E4E647531FEULL, 0xB5A8B148895EAE70ULL, 
            0x37774C51FBF10545ULL, 0x07C339C2F41C5182ULL, 0x1B7280D74641086CULL, 0xAA415C9440550221ULL, 
            0x2DCE3892222952FBULL, 0xE8522A1BA5C8B08DULL, 0xD9C7564F163083C0ULL, 0x2F400873204F3CA1ULL, 
            0xEA1EC75D692E519AULL, 0x652AAA6C3BD318E0ULL, 0xA2F59427F5C5E290ULL, 0xB0E288CFFA2C1AB2ULL, 
            0x0065E73E8EE424AFULL, 0x99AA2350416F2F8DULL, 0x52236E6C528E8BE2ULL, 0xAF86FDE1C4EB919DULL, 
            0x3BAC38E82CE1472DULL, 0x24B30B695D99745AULL, 0x7740BD9CAC724CBAULL, 0x0A5E040B8596513EULL, 
            0x7581E4A5D9027E1DULL, 0x68222183E508517CULL, 0x789B0082345669FDULL, 0x999DE43DCB8CE050ULL
        },
        {
            0xEE2A0BAF7694349FULL, 0xCDB739F94FD2D560ULL, 0xDB40B392549D89A5ULL, 0xEA2DD38A9E535752ULL, 
            0x5AC2FC335107D5F3ULL, 0x19226E832BF4E7CBULL, 0x35ABA50314DBD15FULL, 0x06235BFE981C70B5ULL, 
            0x2F3AF6EF8652DDC4ULL, 0xB0FC756851ECF8C4ULL, 0x2A413998FD555470ULL, 0x1A0E50D6BEA531D7ULL, 
            0x7F36D63CBFFA3D50ULL, 0xE178AD9CDF93CB87ULL, 0x52C938CBDAB264D8ULL, 0xA1DB6C693E091872ULL, 
            0xDE7DD63FEDEBBFEFULL, 0x5E8F864B8254BAAFULL, 0x7EE7D6A76733138DULL, 0xAD6290464D6445C4ULL, 
            0xBFC299806265B105ULL, 0x1E2A95F9FD62D80CULL, 0xF75C71140266C15DULL, 0xCD68DE111EA9F151ULL, 
            0x0E71C281EDE134ACULL, 0xAC29211C1724845BULL, 0x77B93788FEE7B42BULL, 0xBB891A458635E48CULL, 
            0xAC9A8C8783EF2738ULL, 0xEF87DD5F81B52BEBULL, 0xF25BD2EF59E37832ULL, 0x1902AEDAC2938E5EULL
        },
        {
            0x819245EF38158518ULL, 0x3D96927543E348B0ULL, 0xF9F5E97878E04D76ULL, 0xB16A493FDF9EB030ULL, 
            0x3DD6ECFCD8055778ULL, 0xC6D966B5B6639376ULL, 0xC00D39A0B5CF05B3ULL, 0x3C0E8CF2724D7878ULL, 
            0x23716C6576CC7FE8ULL, 0x77572F7067F09F68ULL, 0x3759292A73A7C2D6ULL, 0x7612B333B96ED8D8ULL, 
            0x5464A28BD65FFCA8ULL, 0x4767DD741579D855ULL, 0xDC84C8D6A22CD079ULL, 0x3900D7B77D19ABEDULL, 
            0x6FFCF1CA93A31C36ULL, 0x50A5C88CCC6F37A1ULL, 0x2823BCA1EC3617C4ULL, 0xFCE52B7F3B095750ULL, 
            0x6D4C171E27B31B3EULL, 0xE9D3A6977259B98CULL, 0xB987BC1D60A5F49BULL, 0xFF637AF5B433A6B7ULL, 
            0x0EBED39BB5607ACAULL, 0x58033591F6996C1FULL, 0xE0F0C61B2C92C7D8ULL, 0x9433B282E403953BULL, 
            0x25BC4C34325B172BULL, 0xF23CA156DA680077ULL, 0x08D813D563ED6A16ULL, 0xEFF4D13B0232AEEFULL
        },
        {
            0xD40E2051B9667554ULL, 0x0F5193FD6EBA160FULL, 0x6F0BCC1061641052ULL, 0x81C837E8824AC28DULL, 
            0x16340001B03CB53CULL, 0x3D1AAF432ACA4470ULL, 0x71B72CA77631ED5FULL, 0x184B8C595AB6AC10ULL, 
            0x0ED4240E53949167ULL, 0x25E437758F7F6F1CULL, 0xC62BC291B050018EULL, 0x90586AB7EF4DF44FULL, 
            0xA3BB7B3037B2355EULL, 0x86D02382324B3BB8ULL, 0x98E766BD4D4036F9ULL, 0xF75D17042390226FULL, 
            0xE3366DBCEF41729AULL, 0x08352B6F6B405F2BULL, 0x9B8F441F3A51D44BULL, 0xED3BC369C47EAE4EULL, 
            0xC69E2FC2ED41FD7CULL, 0x63511EFAFCE5470FULL, 0x3E4B3452061E095BULL, 0x017DA7B9E2F3895CULL, 
            0x2AFDD7EAC0CDC6B5ULL, 0xF89D0C720AD62F9BULL, 0xF5F5B36A53EB08C6ULL, 0x2AF127D9DC17C202ULL, 
            0xE492107EC20B384BULL, 0x0B96834855BDB4A5ULL, 0xEC30C06DA82F7B4EULL, 0x24976F2E0CB600EEULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseCConstants = {
    0xB68E33F5C9E4DD8CULL,
    0x05EB381EA0A62E9CULL,
    0xC443927A3C91E210ULL,
    0xB68E33F5C9E4DD8CULL,
    0x05EB381EA0A62E9CULL,
    0xC443927A3C91E210ULL,
    0xE4D16CE48689BA86ULL,
    0x8246FC41A11148EEULL,
    0x4A,
    0x03,
    0x37,
    0x65,
    0x38,
    0xEC,
    0x58,
    0xE5
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseDSalts = {
    {
        {
            0xCA52667F9E1E2EBAULL, 0x27BAB8020D1EF23EULL, 0xA0105F2FE2279412ULL, 0xA308E2A65AC890FAULL, 
            0xA4FD40FA76344124ULL, 0x4DD523FC11782C0FULL, 0xE70E63CAB35EE036ULL, 0xB03E2652F2FBE060ULL, 
            0xB09FAAD767F319DDULL, 0xFAF069F310421F6EULL, 0xA186A1C099AE60C1ULL, 0x51C48435D7597EFBULL, 
            0x148BE334BA619788ULL, 0xC87D56FB07A53015ULL, 0xABF7EA1E4C72F57EULL, 0x25ECF46CEC1EA253ULL, 
            0x38B977B76E03220AULL, 0x34A0EA565E75CC37ULL, 0xBAF7930B14E32CC8ULL, 0x714E6DEDB313AC92ULL, 
            0xE927E5F7A857EA93ULL, 0x3684904A8ABEF3D8ULL, 0x9132071C1C41A753ULL, 0x3EA367B19FF3ED93ULL, 
            0xF672FA3B4FB8DCA7ULL, 0xAA32F1BA5D0379F5ULL, 0x39D3655F25D858C9ULL, 0xD4F026FCF7B19AADULL, 
            0x05674C9EA32C6289ULL, 0xA33310F7A4177060ULL, 0x23DCE8B7F80D3792ULL, 0xD2D64DF013324FC9ULL
        },
        {
            0x9D680AA5537B8508ULL, 0x26123780F267EE25ULL, 0x65EFDE1CE0AE1094ULL, 0xBB65461A729279E8ULL, 
            0xE14F4FC9E42685A1ULL, 0x38642D3DBF49A076ULL, 0xA5A1FF98A9B2C87BULL, 0xAE369B4DFA0B4FD9ULL, 
            0x9B0908FF41694A21ULL, 0xB88AC7935469E7D7ULL, 0xC474EF5168F23BC2ULL, 0x9A0223EC5DEFF481ULL, 
            0xF10412EB303B5FFCULL, 0x7D23F988CD797F3CULL, 0xA5FF0E19C6E44FB6ULL, 0x696595D189EAE634ULL, 
            0x3013BFDE6FB85439ULL, 0x50560A287D9AFE48ULL, 0x68949CDA9BF9F437ULL, 0x223A428BA5361EAEULL, 
            0xED57679986D0D344ULL, 0x09172AC0AB987A04ULL, 0xC3770D3ADE5F6F53ULL, 0x61E4F526CDD974DCULL, 
            0x75042CE80A1D9FCBULL, 0x86CD376600ED3EF7ULL, 0xA78F8878019D8EF9ULL, 0xDA19F66D5B4C66E8ULL, 
            0x0E53D7E8BF3EB0FEULL, 0x6B378BAA81152E85ULL, 0x0CB1DF763797ADB0ULL, 0x913BCB3F7ADDCAA4ULL
        },
        {
            0x8E6A5E815AEC9F58ULL, 0x6129555E458A2B8AULL, 0x8E7129A6754CC1D7ULL, 0xFE9E1B126E3CC0EEULL, 
            0x284917A0A0DF9057ULL, 0x19F775347141FE6FULL, 0x05106F3DF32B5FF3ULL, 0xEFB7B4792C347825ULL, 
            0x09FD701DBB8A4236ULL, 0xBF46A6B08CB8ADD1ULL, 0x011B623DA33C0448ULL, 0xBCE5323482EF236FULL, 
            0x900D55516DB2EB60ULL, 0xD3F19518ED5624ABULL, 0x507FC95A910E851FULL, 0xE1EC6C87F57A7832ULL, 
            0xB129FE694FA9F7BEULL, 0x32A3BBFCA6E8E3F8ULL, 0xBC378839BE2C2D5FULL, 0xDC064B33966557FBULL, 
            0x47F3A366632912D0ULL, 0xD23844D7EA38F37DULL, 0x573FDC266527B7FFULL, 0x1525254EDDCC49CDULL, 
            0x4B06D46ED989DF67ULL, 0xCD382C16413E877CULL, 0x358672B28F69E608ULL, 0x3BD4DC2BCB5E8A12ULL, 
            0x0575D843B9DE9206ULL, 0xE999AFE09C44AC80ULL, 0x0CAEE4ECFB1322E2ULL, 0xA21854335009B5C8ULL
        },
        {
            0x9A0968E59A88C8C9ULL, 0xF68A12915A6231F9ULL, 0xE661EE992E5D9158ULL, 0x750083FA3D344A92ULL, 
            0x5F4BC6D4EB67A0E6ULL, 0x2CBDE7A9C0FCF8C4ULL, 0x61D9B1B958EF2467ULL, 0x808EB9F9BE13A5A5ULL, 
            0x4D408235A1BEFBEFULL, 0xB57794E8031BB769ULL, 0x108119CC02A0873FULL, 0xCE693D15291A4D2DULL, 
            0xBD1013F3876BD607ULL, 0xE24DD74BEBD4AD4DULL, 0x273B5B622213C6F7ULL, 0x2D3033B5B8EE42B4ULL, 
            0xA6C17821D3F768B0ULL, 0x9C289A1FCFC13D2AULL, 0xC315E703C666190BULL, 0xC42DC173D800AC99ULL, 
            0x672112AC39416EFDULL, 0x8A3DB3A724F98D2FULL, 0x6594F2F18098F5ECULL, 0xCC3005E158DB14D4ULL, 
            0x0914D07A0ED7D4BAULL, 0x4BB56BDE11E3F595ULL, 0xEE39FA2D2070A3A5ULL, 0x2C0EE644D7CB1184ULL, 
            0xA7DFC64ED05D3C90ULL, 0xFE61501B57D002CEULL, 0x9E00E127A16A33AEULL, 0x44567EC43F599E21ULL
        },
        {
            0xD1D1BC962F5C7FFBULL, 0x162D71A64C18A351ULL, 0xA41A7B235D64110FULL, 0xE9C53C4B30DCA776ULL, 
            0x404C96628F55ED2FULL, 0x7FB2B64C0B145CA1ULL, 0xBF60632B2AABFEF5ULL, 0x05FFA606F3703C9FULL, 
            0x13861792972B71A7ULL, 0xB18E7225045C2113ULL, 0x5E2D7180E463F370ULL, 0xF00CD7C87386D208ULL, 
            0xEA0D308F35E6CBFCULL, 0x3D225D0EC6B845EDULL, 0x8923988ED16D031FULL, 0x9DDEE4CB1E4E17CDULL, 
            0x3B3924AFB1E75178ULL, 0xA907E73B602806D7ULL, 0x5E9016E6201D7A41ULL, 0xE347CB59CC903512ULL, 
            0x909B1A747F3E5177ULL, 0x6B1D6DE0A05ED028ULL, 0xF12E3C73BAA6713EULL, 0xBA1E607D6F7AA691ULL, 
            0x08CED00E930836A3ULL, 0xA8C31D15F297A1A5ULL, 0xC7D7E35D48FADE4DULL, 0xA8986CA63C74E75DULL, 
            0xF82F00630BC73054ULL, 0xF4355B7B3B510A46ULL, 0xF61568F1E4933E2AULL, 0x8FFA5A1105DD7D7CULL
        },
        {
            0x5D8414646B1852EFULL, 0x9D03EC63F7CC68B2ULL, 0xDD1062CD7BC6D9EDULL, 0x1724D38D7659A1A6ULL, 
            0x9251F3F7329B0867ULL, 0x5125FB4F45F3B7A9ULL, 0x234B283B4FAFB9CCULL, 0xEF4B4C9D70DE2306ULL, 
            0x0D81E022B2559B43ULL, 0x2046DDEF499488A2ULL, 0xE596AC3F37F19EC5ULL, 0x9937DFC5B8CB9AACULL, 
            0x3E8165B45DC794E7ULL, 0x58D8C6F2CE6DBE29ULL, 0x61BBDD2297AD6C98ULL, 0xFFCCFFF0E3CC927FULL, 
            0x8AE819A56450F934ULL, 0x45C496B1F0C5E2A2ULL, 0x0D2C2B04D3C50B85ULL, 0x207B4E3FD95A1AD1ULL, 
            0x94F790F85CAA5EA1ULL, 0xD04EA83FA56D1A33ULL, 0xBB657C79906F6BD4ULL, 0xD8B4077EE9553159ULL, 
            0x3B8CAE00E6715FD1ULL, 0xDCE9FD805C917E77ULL, 0x46603B5283799AFFULL, 0x7E78D210486A4A00ULL, 
            0xD2616D2E9162D03DULL, 0xFD57179EBC067461ULL, 0xBA7E4C60425F1113ULL, 0x450BA7E939F5FEE7ULL
        }
    },
    {
        {
            0x11F88257C6EDDCF2ULL, 0xEC87C805CE1E361CULL, 0x187C592658E98A10ULL, 0x2FE5B8F8B970BEE3ULL, 
            0x4A6247BC3CF21031ULL, 0xFC019AD38E4A4F8BULL, 0x322566833A9F2369ULL, 0x9656B029D251EB3CULL, 
            0x09854A2924DA6B87ULL, 0xA0E22FF345E0AFC4ULL, 0x17B88C7F248AD683ULL, 0xC95C2FB092545A2EULL, 
            0xCE3DFE4741DC3DC0ULL, 0xA7A4CF07F69E23AEULL, 0xF9A508FC39C77252ULL, 0xB149700AB7E16A8DULL, 
            0xA3FFE9FB69E8F087ULL, 0x55AAF37DA10106BAULL, 0x1F45E649AAC62C89ULL, 0x7D151C077F42B238ULL, 
            0xFFC757BA315E2B65ULL, 0xE1B909F223E0A43BULL, 0xD77A38CEB65117ACULL, 0x55EED04737620211ULL, 
            0xD9129CA7EAA0650BULL, 0x5D29128A8F387D05ULL, 0x48FB94A91E42867BULL, 0x194FBAFEF990B80FULL, 
            0x392EF0B97989EC68ULL, 0x80F8251DF1F42B50ULL, 0x89D48BBB1CDBCD56ULL, 0x1D52D59A73DE5ADDULL
        },
        {
            0x921B67DF88E2F7C3ULL, 0xEF99F0942999A8CAULL, 0x54D3D60A6FE9785BULL, 0xBF3C7ED9EE9020C0ULL, 
            0x25C0BBAFFC435468ULL, 0x6D2D69682ED34DD1ULL, 0x6E84C08784B0D473ULL, 0x1E6C28CCC3704A9DULL, 
            0x0558045E680E3AFEULL, 0x57F900CFFF466E53ULL, 0x04E5851C364D3499ULL, 0x0013DCE1A6A47B66ULL, 
            0x5644629ADF01003AULL, 0xAE67215E0D5346F3ULL, 0x709CD5C8DE34D422ULL, 0x23144EB0CE67865EULL, 
            0xF827A8C03CA0C962ULL, 0xB46AA95FF9E043B5ULL, 0xFC44752729B855D7ULL, 0x5F8B65EB8E5F6813ULL, 
            0x2D052697651C5A27ULL, 0xF6462C70921110E2ULL, 0x9E9F4F8B7A33FD1EULL, 0xB369A074FA61296AULL, 
            0xB3AABCF3C064032CULL, 0x6A16D94D64B77551ULL, 0x217F9BD26EFB5C4DULL, 0x314410F5B0DD13C6ULL, 
            0xECD5513F4024347BULL, 0x8F10AA8A5AB6D2ABULL, 0x1A1F2FF9C59F7946ULL, 0x15556D5E90C60694ULL
        },
        {
            0xC5298B09A927AA7AULL, 0x930805675D869678ULL, 0x5F6F90ED1D9511F6ULL, 0xFE777FD2249D2D8AULL, 
            0xE5FD0D1685C6175AULL, 0xD3B6E709926885E8ULL, 0x2D72743C485C6AACULL, 0x4BB3F19FFB162806ULL, 
            0xD0CA37F9DF353F7CULL, 0xBF076DF76E3E14E3ULL, 0x196817D04658F44EULL, 0xE0EC97AD88887227ULL, 
            0x2D11EC493F559C0BULL, 0x8C05419AA04EF680ULL, 0x4D99B4CC5C0924F7ULL, 0x98922C9BB84A6FFAULL, 
            0xDEDFC147CDB06DA9ULL, 0x67C1EE04F283914BULL, 0x1AB9A3CE7409FA59ULL, 0xA90DA0F5837513F7ULL, 
            0xBEC678C9D4032809ULL, 0xEF20794B1D2FA3D8ULL, 0x571EC8109EA93FEBULL, 0xAFF0AC9D565496A9ULL, 
            0xEEBCB293E5B0DE4BULL, 0x8974E2A2A6BCC330ULL, 0x6E1AD4392A40C467ULL, 0x6E1414750AB1151EULL, 
            0x2BF19EE61250B91EULL, 0x4DE5F59F6AA5D63DULL, 0x45045C0FD80CC603ULL, 0x8EB3B8ECCBF46FCAULL
        },
        {
            0x60B0BCBB402002F0ULL, 0x5058508F22B1EC00ULL, 0xA12FF20E7256807CULL, 0x89C541385A62C1B7ULL, 
            0x95919D162F1D24EFULL, 0x6CE5654B10C0161CULL, 0xF20F7DC1DED0D046ULL, 0x37BEAA20536D9F09ULL, 
            0x8ACC72169B0B86C2ULL, 0xBAA4345726C4BD26ULL, 0x03FF547874525E8EULL, 0x5EC7B5DAD9DFA8DBULL, 
            0xEEEE9D281F2D90CCULL, 0xC1E9799B969E56FBULL, 0x37361A61B8173FDFULL, 0x1AE225325F61315CULL, 
            0x31A12C69A3918972ULL, 0xECD4BEBBB2A7E49CULL, 0x3C7212119E402174ULL, 0x572FA3B8C5AEA321ULL, 
            0xD7155EB6738DB33CULL, 0xA9C4C2C59BE0064FULL, 0xDB934F32AF9C962EULL, 0x986BE3B63A128C35ULL, 
            0x9D9C73EC4BD176D3ULL, 0x0994F9FC9952D08EULL, 0xE1B995197D8B7637ULL, 0x9BE06D2729ADD9F8ULL, 
            0x8DC533CBDF1FF162ULL, 0xD4806BCD03168EE9ULL, 0xD3D9637BA8EC05F8ULL, 0x24CE43932428E3DEULL
        },
        {
            0xD292DF57A8AD443DULL, 0x914D61A841B6545AULL, 0xD23BEF663F1E2817ULL, 0x59566849F95BDD9EULL, 
            0x4C60E7A2F17F7F99ULL, 0x6A062F62496B545BULL, 0x0E3DA4F1B77B4E5EULL, 0xE821C617A983352AULL, 
            0x95CCD6EEA9857B1EULL, 0xF759D1198087837AULL, 0x270CDFFAFB9E6429ULL, 0xAC8476A992A36DEAULL, 
            0xA31EF5A7814A0065ULL, 0x1388DB3F32921666ULL, 0xB417832593E04B9CULL, 0xAC0B6D2568A0CDCEULL, 
            0x088E3DC431FE384BULL, 0x9BE040146B183527ULL, 0xE8C25372485AAC5CULL, 0x608EBCA192E43409ULL, 
            0x36CF29E49F3BE0E2ULL, 0x2E5300276C33753BULL, 0xE2142465E7ACA1C4ULL, 0x22E7367A797C45CBULL, 
            0xF9BDC24290F6820FULL, 0xB5F47E623E0BA86BULL, 0x7DF8923B34E69045ULL, 0x8E069374010043C1ULL, 
            0x0E680F81239154ABULL, 0x68E492FA5F5159F3ULL, 0xA5847CBA709D1A6DULL, 0x224A999E5ECB0DB7ULL
        },
        {
            0xFDC6C4C8724A82A0ULL, 0x210E1DB77BE3195DULL, 0x4FE5CC89B343DA48ULL, 0xEC263884112B88F4ULL, 
            0x3B30726FB72A211BULL, 0x8DDD75935DB25AC9ULL, 0xEA0FFFE14C293D98ULL, 0x9865BECEB4B8C39DULL, 
            0x110A83B13F808480ULL, 0x4DBD862D81C8F960ULL, 0x518CF9C850D0FAC8ULL, 0x2384DCC77F8576F4ULL, 
            0x3CCE20E57A5B6D32ULL, 0xB7584F43F2905891ULL, 0xE2C6F8F49FD7BED3ULL, 0x88B074D0FB4F65D8ULL, 
            0xC5E4228113FF67D0ULL, 0x56A73AAE59F61257ULL, 0x2E74B88E7BA5C4C7ULL, 0x01BD853C097CE4EFULL, 
            0x46498A7B2F4F7A50ULL, 0xCAA89904560A78D7ULL, 0xED89D4DC75CFEB9FULL, 0xA096F7723F61494CULL, 
            0xA371ACED7FF6F650ULL, 0xB347865923D17FB4ULL, 0x0D31C9020E98B627ULL, 0x794EE4EAD20B5024ULL, 
            0x472E913B4A13B0A4ULL, 0x738472A0715C7081ULL, 0xFF9DB26CB4C63F2EULL, 0x0B790F99F7563F1EULL
        }
    },
    {
        {
            0x962C4215A329DC06ULL, 0x660467F744A43EADULL, 0xB8531133B4DFBA51ULL, 0x0D6CD264A8148C6FULL, 
            0x6BE40179864F8E3BULL, 0x6FEEED90A640B5C5ULL, 0x1773D65C3817884CULL, 0xDE79A4098868FF90ULL, 
            0x59FC02B8D3B0D31DULL, 0xA19201ABA072EFEFULL, 0xFC9AED2AEDF938CEULL, 0xD80F867D3E1D8D5DULL, 
            0xBD6BED55D01ACEF9ULL, 0x8A30C04E828C147AULL, 0x6C273D64F6030BC7ULL, 0x1B1121C5DA79FFF4ULL, 
            0x127DCAE90DCF3384ULL, 0xBE5A1D942604A65AULL, 0x38B9916067D821DFULL, 0x6C5D7AE9607ECE14ULL, 
            0x00EF5F63E85E42C2ULL, 0x88515AEBBD228D09ULL, 0x1C8F2F7DAE336EE3ULL, 0xF0CC7BD291CE79CCULL, 
            0x926E33BBB457A272ULL, 0x6F58AB19B8B695FEULL, 0xC25CC553D8521CBAULL, 0xC59F2D470683B237ULL, 
            0x80197937C75CF5B5ULL, 0x3ED18BE22143A110ULL, 0x5B17D48C7B0624DFULL, 0xAF1D39B9C4A6987CULL
        },
        {
            0x91CC5925652A9C1AULL, 0x24B4AE6324E8FA08ULL, 0xBECEF59476C683A7ULL, 0xDFFC6DE0C83393C6ULL, 
            0x03F5BA73C4EE033BULL, 0xE3343768BF35119DULL, 0x7F2B581A624FB3CAULL, 0x8DE17501C63A61DAULL, 
            0xB8C9BAA7F25170FDULL, 0x8D54E3AB45C9CBB3ULL, 0x3E95FE7F71AF2826ULL, 0xA3C8B679DD12B535ULL, 
            0xE6E0CC4098764CC4ULL, 0x13EC564B69292C36ULL, 0x8BCF49EFF91741D4ULL, 0x468638C419757427ULL, 
            0x32CDF5C1B7A4E98BULL, 0x4D532D607C3DB0B7ULL, 0xE17465B2280C962BULL, 0x1D118325EDCDA60AULL, 
            0x54A324D43EC3B89CULL, 0xE819268F22B33948ULL, 0xB229F2C2EBB2493AULL, 0x35F6C16298788A1EULL, 
            0x01E732723A34FC85ULL, 0x38946DADE2F401F4ULL, 0x53DF7323F870B9C6ULL, 0x213CAE0FEE23282FULL, 
            0xC9D42636A216E62AULL, 0x309445150C141BD4ULL, 0x6B247DAAFF5E133FULL, 0xE27AD6D581770E1AULL
        },
        {
            0xDF18E41A03B8F3FFULL, 0x946626789C1BF6B7ULL, 0xB1F3F007BEBEBBC0ULL, 0x5720D11248E7D9EAULL, 
            0x30809584E4A51FE7ULL, 0xBE7E97AB66B6D714ULL, 0x970610144775F1AAULL, 0x9CE45356B982CDA7ULL, 
            0xBF3D94C48FCCC171ULL, 0x2B45731919D70631ULL, 0x39E69B23B7249AA5ULL, 0x04F06EBF2DA6C97BULL, 
            0x1F5DA7FE930DF5EAULL, 0xBC3024643F7E7731ULL, 0x645BBA4E9BA2AAD5ULL, 0xF1DDC1C1D3D086A5ULL, 
            0xBB82B669F7A0E51AULL, 0x4F5F7F4B09ABD657ULL, 0x5C5E1F30AB9014B1ULL, 0x54402E410B118B0FULL, 
            0x6E3022E1FD48E699ULL, 0xBD36CA610506A8FCULL, 0xCD177AC86ECF8790ULL, 0xA5746A815D163D43ULL, 
            0xDA77C5910E1C0D96ULL, 0x2DF943FE508A9638ULL, 0x9E825A6864F2117BULL, 0xA5343585530458CCULL, 
            0xD4C5510864CA2FDFULL, 0x3C1088955997A7FFULL, 0x281863624186DA12ULL, 0x65817B5D4429FA8CULL
        },
        {
            0x62992565EF836BBCULL, 0x1543E7ED6D658521ULL, 0xD66E408A10F95419ULL, 0x34CDA79D7728FC64ULL, 
            0x4C1129BE9127454BULL, 0xCF3046503F171E78ULL, 0x52FF716403BF2C24ULL, 0x242CBFA9027C1E3FULL, 
            0xC33D0B623920A567ULL, 0x1055004525117E0CULL, 0x4F1D8E73C9AE8D44ULL, 0x4D1DFA886F4D0344ULL, 
            0xDFD6BC7CF73CA353ULL, 0x66D7E03F75DE7660ULL, 0x454957A132C41162ULL, 0xC45C1FE941986F22ULL, 
            0x9A6A5ADFEA2316C2ULL, 0x3A0C2EC011AC9228ULL, 0x5660E9D54985DB2EULL, 0xA496AC27DD100920ULL, 
            0x734338957F589B0CULL, 0x3ECC11C42FCD3C08ULL, 0x194826B875AC2756ULL, 0x9068A3EE94668F93ULL, 
            0x3E6DECA08F9B53F5ULL, 0xF3A94E7B4F834EB4ULL, 0x9677086A4A733B3EULL, 0xE25798C3FE00F70CULL, 
            0xB0ED623C2653B0C0ULL, 0x870F08942433B48DULL, 0xC5325768EF5B8AACULL, 0x9754305EEFE4F54DULL
        },
        {
            0xF3B17D2572E15B7DULL, 0x05AF6076300F02DEULL, 0x5B76B76AA1E9DC7FULL, 0xD2112FC7E004B940ULL, 
            0x84964A3BBEB2FFDCULL, 0x3D40076BE84BC318ULL, 0x37146365DCAACF8FULL, 0xB7199B1AB1ED9401ULL, 
            0xCACB3B6C242071CFULL, 0xE0A766A6E0B3148CULL, 0xA4208FF918B94540ULL, 0x4F17B0AB6C198C29ULL, 
            0x93532A53D7FD8571ULL, 0xA208E03511F25375ULL, 0x59D1886EFDDA27E6ULL, 0xFE43B44C936CF605ULL, 
            0x2E6F64522E26EF11ULL, 0x1ED764DEB17D635AULL, 0x7C908C1522C7240CULL, 0x7DC6EDDC63357DE9ULL, 
            0x483F5740CDD0346DULL, 0x8FB757224A69DB3BULL, 0xCC16F98C47F010FDULL, 0x87509A8737629178ULL, 
            0xF978C47020B07806ULL, 0x185296AA14A21AE8ULL, 0x26A7FAA9B97DAA04ULL, 0xFE6807A7161C1FE5ULL, 
            0xB795DBA1F4DD7064ULL, 0xAE99D2D1C914CA85ULL, 0x5565A22EB37929BFULL, 0x59BFE994286B2866ULL
        },
        {
            0xF9B05F5D82342004ULL, 0xB7118AF7B5757F14ULL, 0x087355F30EDADABCULL, 0x29308D8776C8C875ULL, 
            0x6E9409F5FE93D373ULL, 0xDADDB84EA7ACBC6EULL, 0x660DC0F621C47506ULL, 0xB62A6106C8147575ULL, 
            0xC57D16314155290DULL, 0xAE72C15735EF1AF3ULL, 0x3B5CD1ADF6570A70ULL, 0x130B4CB9C016DD81ULL, 
            0x9DD3135D30F26BFDULL, 0x9BF32355E40E62EDULL, 0x9E6FE9DA2EFFBDF4ULL, 0x37F07874CA30FD38ULL, 
            0x890FCC529CFEBCC6ULL, 0x83800330403D7757ULL, 0x0CFC4E292D67840BULL, 0x9E724E9657F345E2ULL, 
            0x21864998DBDB994CULL, 0x7F9271DAF6391C20ULL, 0xAC395FDA3C25EB2CULL, 0x5DF5F36FDA9D0269ULL, 
            0x56F6D281E7929322ULL, 0xC734362032597536ULL, 0xDECE7709C2A8FB14ULL, 0x7A4AC1378DE8D5CAULL, 
            0x8B097A41C2A62288ULL, 0x886E929EC2EC1439ULL, 0x7774BA06724BF1D3ULL, 0x434F5F4BABD981C1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseDConstants = {
    0xF88EC115A38DC443ULL,
    0xE7311D24E04706CAULL,
    0x57B817CFEAF127E3ULL,
    0xF88EC115A38DC443ULL,
    0xE7311D24E04706CAULL,
    0x57B817CFEAF127E3ULL,
    0x320449C0984A846BULL,
    0xD408123B65B727B3ULL,
    0xFD,
    0xB8,
    0x24,
    0x2D,
    0x04,
    0xF9,
    0x82,
    0xB1
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseESalts = {
    {
        {
            0x419E819C7DC676AEULL, 0x2696C94F6EFE26C5ULL, 0xD2542E8A73325FE0ULL, 0x40A8D6F3DF90A714ULL, 
            0xC0969306AD765D26ULL, 0x34256F9E2B027DAEULL, 0xA3875C7C2F4B92BAULL, 0x6E551711CD62C523ULL, 
            0x228317D09FD2A05DULL, 0x347FA96B3ACF6751ULL, 0x059E628B5EE5B9D2ULL, 0x5DE3395B9D13266AULL, 
            0x8E4E21AB8146E45EULL, 0x493F3506BEFD3856ULL, 0x2A735500DA0B360AULL, 0x6129EE60BACE135BULL, 
            0x960375F81B19F0F4ULL, 0x3626E06EB2CED5FFULL, 0x15AA16E36D5B01A2ULL, 0xD1B757DFB2FB26C7ULL, 
            0x230168C1CC6280E8ULL, 0xC4481E19A56464B7ULL, 0x6C3DA39C478ED7C1ULL, 0x86882151E36CBEF3ULL, 
            0x2F4E0A54DB892771ULL, 0xA9D1DA216D892C77ULL, 0xAFC6E368A270DA7DULL, 0x9503596DD79E6D25ULL, 
            0xEC1E04B8070D4083ULL, 0x803A7CA94A145F48ULL, 0xF9EC47E6E96A9ACDULL, 0x905829CF58276A95ULL
        },
        {
            0x0725E29D790ADEEAULL, 0x930F131C54A90F49ULL, 0x74FFD0771693625EULL, 0x3E890F7AA0EE2E77ULL, 
            0xA32ED180457B3435ULL, 0x6CEBCF4D07608776ULL, 0xFE7BEEB1904016D9ULL, 0xC9936CE0775FBC02ULL, 
            0xFF3E5F12B8461F90ULL, 0x7E01E4AEDC72BFCBULL, 0x4FD158E0D523BB55ULL, 0x6AC3C325C37D197CULL, 
            0xDE738E324FB66D93ULL, 0x254B042795D812EEULL, 0xB71AD22B7397774EULL, 0xCCE4CD44D78C7280ULL, 
            0xF33A16BC4936788EULL, 0x172689C4AC62C7E6ULL, 0x023B6FB30D723B38ULL, 0x10265A7D55C0093EULL, 
            0x2C51FE8EEB5E0A35ULL, 0x16AC8B28B211C25EULL, 0x54EA4FACFAE9695FULL, 0x072C7F370963C1E4ULL, 
            0x24A6EAC4B2A63434ULL, 0x44513EF06CB011A8ULL, 0xBB8FC4189779295EULL, 0x3E4FC848F1CDA05FULL, 
            0x8EC13E3FE58FEAE4ULL, 0xDA7F64C0A56FA9FFULL, 0xC42B8D81BBDDB571ULL, 0x0D343E5E7C9678D1ULL
        },
        {
            0xB0FCFF9847ECFDDCULL, 0xB5152E11F1BA263CULL, 0x0D9DB3A3B8692C55ULL, 0x47B54EC56ABE07C4ULL, 
            0x1EA7A4E60D13E47FULL, 0xF34C2EF85D167BDBULL, 0xA812671B526294F3ULL, 0x19549E0AC85C8F59ULL, 
            0x8C1AAD5F43F27778ULL, 0xCCAD8E1B2F176F71ULL, 0xE96CBF67A1C8039EULL, 0x18BFCD5A08EA70B7ULL, 
            0x185F2B2D385CC438ULL, 0x0578DD1272EB74E8ULL, 0x9261A5E76AD19622ULL, 0x71273DCFA91C9D63ULL, 
            0x3A6A6B90A9E838C2ULL, 0x6629E4E6E3BAFD71ULL, 0xE76B05871ED3F393ULL, 0x3FEDA8DF28AA0C5EULL, 
            0xECAF76983CD35556ULL, 0x00E33976CF821291ULL, 0x7B6A1722B41859F9ULL, 0x4936ACD0D91C78E5ULL, 
            0x7B08E32E3E3E7B0EULL, 0x15588AE56C01386EULL, 0xA2E7246B9BEE5EF9ULL, 0xB8093495505657E0ULL, 
            0x5E07949005BDD686ULL, 0xDFDAEDB2553A057AULL, 0xB47F2DAAB6140F90ULL, 0x564FB422EB9ADC0CULL
        },
        {
            0x0FA253B97A8057F7ULL, 0xE3A6F3A00027B0DFULL, 0xA93B177102E79FA8ULL, 0x862520A2FF889913ULL, 
            0xB89969054FE2B782ULL, 0x90481C98DDCE0DFCULL, 0x7635E585BC47BEC4ULL, 0x6493D06E4B3A77AAULL, 
            0x73C9883F44D442F4ULL, 0xD0A2E89086A1E735ULL, 0xF449AFA978688D35ULL, 0xDB7AA0C3536EA4D7ULL, 
            0x0548B7A9797C5EFDULL, 0x444F6761B0FAC379ULL, 0x32CCDDFA562B0DFCULL, 0x21B1D061D4BA3628ULL, 
            0xD0E4500072348370ULL, 0x97E9FFE0377E3063ULL, 0x311EB5A88CE68F20ULL, 0xA2E2BFB49378F19AULL, 
            0x3BEBDD5CE5837846ULL, 0x6C5903028B46DDB8ULL, 0x53C7CE2CDF88DE8FULL, 0x24A5BEFFB867CDB6ULL, 
            0x568D0037723CCE63ULL, 0x7B743111C2E83C8FULL, 0x34D857BB477CC3BDULL, 0x4313DE54E839557EULL, 
            0xA1C169D380238334ULL, 0xD9CA3AB9C913EFDEULL, 0xEA74BB729504AFD1ULL, 0xD156F523A731011CULL
        },
        {
            0xFB1CE232B94C83DEULL, 0xAE28C81082A82FE8ULL, 0x8C0D5B9F83CEE5BDULL, 0x287005B6E9528BE5ULL, 
            0xD57D34F72BAE3583ULL, 0x6BFF1E134CB73429ULL, 0xF5277DCD8763270CULL, 0xE9F8C7405DD1B3F9ULL, 
            0x28627DAB6CD748DBULL, 0x0A6A1098E22E7E88ULL, 0xE256960B0BD01C0EULL, 0xAE6385FB3C0CDDA2ULL, 
            0xF6181FC82CBE0CB9ULL, 0x7C912E3EEBC28027ULL, 0x976FDCAF762AF4E3ULL, 0x5D4127C023A46B87ULL, 
            0xD2897BE06DD31619ULL, 0x67E932665D8990B9ULL, 0x48745A1E1310117DULL, 0x8A5B62A37F4D86E6ULL, 
            0x760BC8F605C39405ULL, 0x3278E56E9FCA76E8ULL, 0x44100A208F070A87ULL, 0x1BAF207CE16C8FD6ULL, 
            0xCA849CD2DADF1CD5ULL, 0xB4841F8E3CAD6BCBULL, 0x9A007F160E12A205ULL, 0xB285BEB732A98904ULL, 
            0xFFA1C675096EE1DCULL, 0x235D978450D66894ULL, 0x170BBFE914BBCA3FULL, 0x977502B1833ACAC4ULL
        },
        {
            0x1A2FAEA6439D5A85ULL, 0x4F3F24669C29545FULL, 0x3D7373549131C15CULL, 0x8E67A7AE127F7D6DULL, 
            0xE40A1470CE7E2FCBULL, 0x2D196E5EB61A4323ULL, 0x4F538F12E6B92D31ULL, 0xBFB47CA5C62EC1C8ULL, 
            0x3608B703C882E676ULL, 0x95F4B12F5145B960ULL, 0x47B9CD3F3F4174F5ULL, 0x496DC94DAF2650BAULL, 
            0x04840CFF8FA7904BULL, 0x290860CF3862A585ULL, 0x266A25FABDA5E41CULL, 0xF6209654F431B7EFULL, 
            0x57877581AE172189ULL, 0xDE86BC7997487FF6ULL, 0xDAC215CF78BBF6AEULL, 0x8FE6429F40691B96ULL, 
            0x09A5BB4131B04A22ULL, 0x9771D828E0B46225ULL, 0x97B095B2B619ADCAULL, 0x9E461F042BAF49B1ULL, 
            0x8AE2EC3E0202FBC7ULL, 0x433D376EF5FCD12EULL, 0x3B6335649E02F6F7ULL, 0xB196B1BA09269D33ULL, 
            0xCCD1D01636EE7C35ULL, 0xB737F00E8359C376ULL, 0xBF62AFDE92B477FEULL, 0x765D1B88A10F86F5ULL
        }
    },
    {
        {
            0x911AA143B6B91360ULL, 0xC44CF842641FF351ULL, 0x799E5914E171AAA2ULL, 0x4375346A6C0C8AE8ULL, 
            0xA16C71D8FA14EE3AULL, 0x9425F4DEEC414C95ULL, 0x13960C84E4242BE9ULL, 0x91C10712D7B502DCULL, 
            0x36121FBBDA98E2E0ULL, 0xA6E6FDC6ECA84919ULL, 0xA248A15E0EE19762ULL, 0x81A65653CF5E4829ULL, 
            0x1EB4A89EAF3AE11CULL, 0xF30C87D724272249ULL, 0xBB780A9E73B2622FULL, 0x694E64D662160D04ULL, 
            0x2A222F532D871353ULL, 0xAD4A82F72E66C8A4ULL, 0x20FEDB9790078604ULL, 0xFC150CE3F458242DULL, 
            0xF5CC15452434D020ULL, 0xFC965D4E3BC4914FULL, 0x32A0B3606CCD93A1ULL, 0x5CE55DA3F1D9411BULL, 
            0x17E2E5FBC4D628A7ULL, 0x4C522BC60FBD2942ULL, 0x71B267BA6CDABB2DULL, 0xA7374D208B61EBF1ULL, 
            0x092562537E3C039FULL, 0x806CC4C4B7946D76ULL, 0xA3968A56C77167AFULL, 0xE0844057848A6F2EULL
        },
        {
            0x043B89E0F659F8D7ULL, 0x282B00C3F6C714B8ULL, 0xF82CFF8475ADAAE8ULL, 0xE7F3667FAFFC2F77ULL, 
            0x8749E762079F7801ULL, 0xE50A752D78AEBBB3ULL, 0x3BFCA7D6142EA7E5ULL, 0xA2C76C35C3FAB715ULL, 
            0x319F5CAE1A468960ULL, 0x1E35EB7002205DCAULL, 0x316304DEA57B0C06ULL, 0x977B779155C5239AULL, 
            0xCA36DAB7EBAFA6EEULL, 0x63332EB88DA0A054ULL, 0x90A1655658B8BE82ULL, 0x0A6E103772C0E22FULL, 
            0xB73317B5248EE6FCULL, 0x398E63FADEFC2DE8ULL, 0x9472930D9AD5AB6BULL, 0x045423C59DA78EB5ULL, 
            0x308A2D7C3030C82AULL, 0x62ACA18CEC4DC812ULL, 0x6E0CBAE8A4ABEF79ULL, 0x4045D832E3FD743EULL, 
            0x538AB5F1CBC46323ULL, 0xD29D43BE1C99590AULL, 0xADB96A9F8670675AULL, 0x228BB4F8E458CFF8ULL, 
            0xB20F5538FE9D0FB6ULL, 0x6471CCEBD051D335ULL, 0x4C9700EB87DC82E6ULL, 0xD4564C80CCA3DEA4ULL
        },
        {
            0xA050235A630A856AULL, 0x55A7624E68AB6B26ULL, 0x558A3C95FD001686ULL, 0xAA8D8C949DCD5679ULL, 
            0x7C51E62A08332D09ULL, 0x9FCC8EABA1BC7C2FULL, 0xBB5CD7AFB8A29792ULL, 0x1FEA848E4BA807A3ULL, 
            0x4DAC5500C0DBC7F4ULL, 0x8B73165990F05D83ULL, 0xF872210BD44380EFULL, 0x5F61DB6283018B87ULL, 
            0x255740AAA95B231FULL, 0x28DDB83573F48C0DULL, 0x32ED35DC33893153ULL, 0xE1EA756CD2F40E57ULL, 
            0xE771F17ECC80576DULL, 0x21023100BB017D6CULL, 0x7554322514BA8464ULL, 0xAC52D2882FC1189BULL, 
            0x31E334AD5FDD0A28ULL, 0xB5195EBDFDAE9A95ULL, 0x2787A144B4B42FA3ULL, 0x89C061F35C844CB8ULL, 
            0x0991CA7E186D4155ULL, 0x5A404E93F7C8BF19ULL, 0x9ACEAF4D8F9E8828ULL, 0xD2E298FD304F2850ULL, 
            0x8E7EA096B79A1499ULL, 0xADBF2782A3E8B744ULL, 0xE336DE2C7E816BDAULL, 0x520621FCAAAC79C7ULL
        },
        {
            0x1DA0175C0C643817ULL, 0x4CB23CE518B755A0ULL, 0xFF5ED73DBE7E8F9FULL, 0x6BA216EC642B95C4ULL, 
            0x7AFD2AD11B52555FULL, 0x283ECA9AF5941B94ULL, 0xBA411A14F505AE3CULL, 0x891D3C0E416CF0EAULL, 
            0xEBE7F03E679D31E8ULL, 0x27A77B367DDB16B0ULL, 0xBEFFAF8D1D3A0648ULL, 0xB2A51CA7340AF05BULL, 
            0xD27CC6AB97C77F7DULL, 0x14A6CAC20ACBCBCEULL, 0x6FAC7F0906246D2FULL, 0xA6B71BDB47DA717BULL, 
            0xA6D504DA01B0719EULL, 0xF77E0528198B9FBDULL, 0xB4C10758ECE3F200ULL, 0xC0B0F53FDE0A1526ULL, 
            0x83DC4A73BC032952ULL, 0x43278082E1B2D145ULL, 0xAD4FE9B7951DF806ULL, 0x4B410BF071F16BEBULL, 
            0x40F82FD1F573D5E2ULL, 0x5ED950E407DA235AULL, 0x21FC1B869F8B5074ULL, 0x876082D9DE9A4585ULL, 
            0x6E21C887ACEE8016ULL, 0x36B7CF754C31CF52ULL, 0x33BC1AC998E844FEULL, 0x550202DD416A38F7ULL
        },
        {
            0xBF9BF609BF59B9FBULL, 0x4C81593C67940A08ULL, 0xFAB82AEC1488C5EBULL, 0xBD422F844E88FBEFULL, 
            0x5873CF33544029C2ULL, 0x8EA46985FFFB1F18ULL, 0x39B03A19B49D0F74ULL, 0x25F5F9134005E320ULL, 
            0x04A5A557FEFB2394ULL, 0x1075DE49A0DD50F0ULL, 0xAC26F56FDD401527ULL, 0xA443A8E32D08717FULL, 
            0x83936CCD973369D3ULL, 0xFC1AEAEF0FC00FC6ULL, 0xA36D7E359DDE640BULL, 0x96AFFA727B813BFFULL, 
            0x195B394D06EAE3EBULL, 0xE05D2EE5F95052AEULL, 0xEFFBF7D932F8CF84ULL, 0x8FB735113830C612ULL, 
            0xDCF851213217F078ULL, 0x9EA3ECDFFA6A3B20ULL, 0xE7B981475A1BA064ULL, 0x05FE9DF7D74BBB93ULL, 
            0x3F6352CB9073D9C3ULL, 0xB56627924E546383ULL, 0x3E7282D1029B14C8ULL, 0x624A46C13F7A35DEULL, 
            0xF946C8F05FE78D80ULL, 0x0183F7B70D2BF55FULL, 0xE3C86843022C7F7DULL, 0xCD33B8A5C0D784DDULL
        },
        {
            0x7D49BE4924F4F6ECULL, 0x3EBAA5DD3CD9BE98ULL, 0xA9BB40D6ADD21993ULL, 0x068E6F9A3CB13183ULL, 
            0xE67A21E75DCE828AULL, 0xFFD77D9FE5F52410ULL, 0x5F921D1A079D7A11ULL, 0x119B48A2BD29AF65ULL, 
            0x444E1E91FAA1BFE0ULL, 0xE1DB0252F62D14D5ULL, 0x7CB12AB180A960CFULL, 0x4DC6D149B923EE4EULL, 
            0xD7FB4D08DF13A82DULL, 0xD46752BA9238DEB3ULL, 0xBC9743524D98528CULL, 0xFD5E2064AB0AE41EULL, 
            0x8D01BDDB0B0D16B6ULL, 0xC8FEAAC136D0B0ECULL, 0x3E875A5F77D70F19ULL, 0x7D6360B5B0659AFAULL, 
            0x0184DCC8D566F281ULL, 0x4AB7ED25504DF613ULL, 0x6975E6F732251ADEULL, 0xC06462D22DDD5DF4ULL, 
            0xF83310DCACC20AAEULL, 0xD21024ECE267C178ULL, 0x70C8640B71717B34ULL, 0xB279089526E28985ULL, 
            0xC176D2E096872C8BULL, 0xD3F3B8901FA57406ULL, 0x7D71FA308BF002D0ULL, 0x4EFFE4C24E9BFCF0ULL
        }
    },
    {
        {
            0xF45DFFEED8D563B3ULL, 0xD83B0068F428DF55ULL, 0x619F31799FF2497DULL, 0xA33A2C5DC25E2B4DULL, 
            0x8CCD223DC9E2DDF4ULL, 0x39FBAD439EE1BC70ULL, 0xC564992FAC4875D1ULL, 0x0E0BF3C799728EFBULL, 
            0x6E2B5A9C45F9E2D4ULL, 0xF3491EFAB5AAF181ULL, 0x9FAEE7F2041B4EEEULL, 0x4D00F2D292EF58C3ULL, 
            0x9C5B7BE95C2A60EAULL, 0x388DFD96CBE1E160ULL, 0x28C7D2A0C8D8053DULL, 0x8FAB7D93DF03973FULL, 
            0xB5DD45330D768534ULL, 0x5028E1BB09A15445ULL, 0x15389F7CE007BCE7ULL, 0xD2882CD97F9D0F52ULL, 
            0x7958CCAD610541E3ULL, 0xD0919AEB15460016ULL, 0x5D37B353455CBC42ULL, 0x7DFEEC9AF3F7D6CDULL, 
            0xF87C8BE08905F782ULL, 0xE89829B1D3E04145ULL, 0xD0E72846C3BBBC5BULL, 0x04266ACB6D577104ULL, 
            0x15319BF4F306C90EULL, 0x8533EE246E5F2803ULL, 0xA1E61FE71790ED6DULL, 0x1EB1985D1D7FB12AULL
        },
        {
            0x0F0A71F88BD0DCC5ULL, 0x221CBFC6F6D60635ULL, 0x3356C667B7E9898CULL, 0xF1E107A92F473D38ULL, 
            0x97AE3AF26D3AA7E7ULL, 0x6CCF907E020C58FFULL, 0x0BDFCFC2E9482167ULL, 0x0DE230E395EED131ULL, 
            0xD909E8A8F1D2A981ULL, 0xEA7E11D65D1E381DULL, 0x396F61AB870E5F5BULL, 0xF5A8CBB089D4B1C3ULL, 
            0x60C2834D6C96EC12ULL, 0x77654526E30EF4DFULL, 0x0A4787A98EB8C98AULL, 0xBB72217B2A530D64ULL, 
            0x7D7BE2DA53B719CEULL, 0xC178A8958C18FF16ULL, 0xB17DCD11F31E937AULL, 0x038BC3950B0A9EBDULL, 
            0xFB920049D169A077ULL, 0xBCC343C9BB3BFEADULL, 0x037ED6BE0E66C7F4ULL, 0x2D47D9337597B60EULL, 
            0x213586746B589592ULL, 0xC9C75E2E73DB9639ULL, 0xF41AC4E4AB759A26ULL, 0x2A401275FCA054C1ULL, 
            0xF8251CAB4729F168ULL, 0xBCD8F9BAFCB88CE0ULL, 0xE2AFF8B9FF77835BULL, 0x56000FAA644040CCULL
        },
        {
            0xF2592A0ABDEA51EEULL, 0x41D6C52826BB8C6BULL, 0x8A5DEE7DD64BB0D4ULL, 0x57F208891EDF9935ULL, 
            0x77E5B2BF42CFB1F1ULL, 0xA3D74FAB08F8AE85ULL, 0x90428E2D3B62B6F8ULL, 0x2E8A7EEC39F73094ULL, 
            0x268EAC1EF2096641ULL, 0xF0B6C0AFF497F3ADULL, 0x64C30685AE8014E9ULL, 0x62EA614166C6C865ULL, 
            0xA0A93A7F86B03658ULL, 0xDC0A962EB0E9AD8AULL, 0x9CA26F067843BF5CULL, 0x27F3E822FD1C36FCULL, 
            0x858B7DBCF4D70094ULL, 0x5D79D93C33E1D2A2ULL, 0x109F0DD34C198F81ULL, 0xDAE15B5CEF7C24E0ULL, 
            0x361EB89527044B01ULL, 0xA24A782E91958B34ULL, 0xE47F6504C737025BULL, 0xEBC385C91F481760ULL, 
            0x2B35AD068EA85D22ULL, 0x20764351C22A2750ULL, 0x03CD0F2B2689CBE7ULL, 0x87D394745A16A0D5ULL, 
            0x46C1DF699DC244C4ULL, 0xE70BB6C0A983ADA6ULL, 0xD6CF65FFC59399F2ULL, 0x650EDF7AF0AFA5F9ULL
        },
        {
            0xD4964161327071A3ULL, 0xCBB469B6B6C83790ULL, 0x05532999BE70584CULL, 0x32056AEDD6F1095DULL, 
            0xD4F6A6F747ED9AD3ULL, 0x1CE1131AC4B2703EULL, 0xEF9D759C0C611CD5ULL, 0x5780797CDCDB4759ULL, 
            0x8DE771520E86523AULL, 0xB5C97603C5D62EDBULL, 0x1B3DE631F40C8D83ULL, 0x8B30C08E389E8185ULL, 
            0x905FF7BD36B4338EULL, 0x3304FA95A66CA524ULL, 0xB492014F6F071D24ULL, 0x607C94FE2C40F502ULL, 
            0x0F0DDF896046FEABULL, 0x0D4777CFAAD60CBDULL, 0x872876622F07AC1AULL, 0x9FE6FFD567170371ULL, 
            0xEBB39894A55D7BECULL, 0x93A95DF6FFD0083BULL, 0x06A137A4D672217FULL, 0x06A48A8BB03E1C71ULL, 
            0xB11107AFDAAEB2E5ULL, 0xAADD0E62157ED652ULL, 0x85F155E4ED551216ULL, 0xDBEF9625E58D724AULL, 
            0x522FE81A2D942625ULL, 0x123FD05164AAD147ULL, 0x7CD9B608B9D6BC48ULL, 0x5DEE596DEC870BDEULL
        },
        {
            0xD20215D58F3456F2ULL, 0x1838B4E06E466EBEULL, 0x7F9DF4E47D3866B6ULL, 0xCCDFBF3D7EACD23EULL, 
            0xAABFD668B75F6591ULL, 0xB69600F33E15AC2DULL, 0x275906DAA64500A6ULL, 0xB5E9B6F66C24F40DULL, 
            0x01D80ACEEF10010CULL, 0x160D5D4F5E975981ULL, 0xAD6A6F5156FCE15FULL, 0x5AFA45FE43678794ULL, 
            0x797FC99A13699A53ULL, 0xFF85F96F27537C69ULL, 0xC52DAF7AB63A3476ULL, 0x2E94C3854E51649BULL, 
            0x1AC16F3FBB4D5E29ULL, 0xF35F35B90C5B6516ULL, 0xB34021099C5DCBC4ULL, 0xAC00F63C9C5402E3ULL, 
            0x4A3D1D0444A065E6ULL, 0xB04C335827B41DB4ULL, 0xD448D9693B99996FULL, 0x1311EDBE99728C78ULL, 
            0x69B2EA27D53BC4F1ULL, 0x14E38EBAB64CA378ULL, 0x8F4818C310A93CDEULL, 0xB867223E44269E26ULL, 
            0xF7AEBFE0EEF63B9AULL, 0xE1942660DBE2C7E4ULL, 0x6D99BE493F16A4F8ULL, 0x17277142BDC6D073ULL
        },
        {
            0xEAA71EB1DBB57077ULL, 0xBB8B008999AF703DULL, 0x2DCAFFFF43709654ULL, 0x794200D0786F63CAULL, 
            0x02265EA2B9212BC9ULL, 0x7B3AEF596D875FA8ULL, 0x1F5ED7BADEF426F2ULL, 0x9554186755766D87ULL, 
            0x298C22D7AE8AC29EULL, 0xCEA61D3A52F6039EULL, 0xEC4CB595B874642EULL, 0xC2F462E52FAC7DC6ULL, 
            0x9A90CB3CA5A43392ULL, 0xCC67FFD254AC4E77ULL, 0x7AA2C8E952BEF2E7ULL, 0xF5F868518FAA8579ULL, 
            0xB9A4325DC8A760FDULL, 0x62A00EFB5A73CA15ULL, 0x60BE80D994C3B28FULL, 0xA172262F1CCE3D45ULL, 
            0x8178765DC5325C1DULL, 0x75E4A12BBD6AEE85ULL, 0xDDDD800C99D659D2ULL, 0xFF0C5FB8C34ED7F2ULL, 
            0xAAADE18D6983BB92ULL, 0xD9F2903E3B7EAADDULL, 0xE7D187E99DB84E13ULL, 0x23E8E5773EF247FDULL, 
            0x8E2858AFECFDCA5EULL, 0x39C0D3B522C17680ULL, 0xC6A9C7339D0A520EULL, 0xDB059731919BFFFAULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseEConstants = {
    0x2EB15ED211534A9CULL,
    0x17CAD3F4D41BD0A7ULL,
    0x85C03356F28D4E89ULL,
    0x2EB15ED211534A9CULL,
    0x17CAD3F4D41BD0A7ULL,
    0x85C03356F28D4E89ULL,
    0x90B0D16C9127FD3AULL,
    0x67558D4754B7FD67ULL,
    0x98,
    0xD2,
    0x2F,
    0x0A,
    0x14,
    0x6C,
    0x06,
    0x9A
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseFSalts = {
    {
        {
            0x07CD95C2307ACCDFULL, 0xB63EA7A2473C2D65ULL, 0x57C5406E372A24DDULL, 0xE600C99B4F2E4803ULL, 
            0x76D7B2857825694EULL, 0xEACD2F7402DF061DULL, 0xB93064B8A6121228ULL, 0xE780A0E46C9313F9ULL, 
            0x30AFE2F1C43ADD8EULL, 0xF67C9D63BC47F67AULL, 0xBBE29902F28FD18EULL, 0xADF1CE432F922ABDULL, 
            0x84631C7306086A84ULL, 0xB5A13AC9B10BE2D5ULL, 0xA8F4DC3FFF30FC37ULL, 0x1F96F199BC758F42ULL, 
            0x840E80C267381594ULL, 0x00A057677169697BULL, 0xCBF5E356C4CDDBBCULL, 0xAEE971305E057A78ULL, 
            0x37ED62BAD32C6BB5ULL, 0x176735E68BE12460ULL, 0xE61B00A3E6FD0D11ULL, 0x9B9C5C84CCDC5EA8ULL, 
            0x8920D4842761C684ULL, 0x715051AA2157D23DULL, 0xB74D85A876DC448FULL, 0xBA2E4663B7C3382AULL, 
            0x3E2D6042496B95BBULL, 0x91C7B2EFEEF1D37AULL, 0x71937612B2C86792ULL, 0x1B43AF1143598F37ULL
        },
        {
            0x497320E0AA69E4FBULL, 0xE018DC0ED5E3CAA3ULL, 0x858EA3EEB2B928BDULL, 0xB6C18A39A691CD9AULL, 
            0xAFA2C92276370E1AULL, 0xD55B6815553C98C8ULL, 0xE351A9F4023A460EULL, 0x561508109394FBAFULL, 
            0x1A548F75FB5DB070ULL, 0xBE6C3E71531B97C9ULL, 0x0980B143174B65F0ULL, 0x2F2583195FBC8907ULL, 
            0x5C16F858461FAE25ULL, 0x16C75391E10B4FB2ULL, 0x826154D608C3044AULL, 0xF64744358B0FA10CULL, 
            0x032FA81320074055ULL, 0x7F9DD62DAACA7E6DULL, 0x2E23FBC0E2D99EC6ULL, 0xC221992C32200BCAULL, 
            0x4F64D97B960E4737ULL, 0x8DC7707947C4375DULL, 0xE423F516B59A0536ULL, 0x88E5A7BDE6BAD0A2ULL, 
            0x630133703F688819ULL, 0x1A9C89317E29A732ULL, 0x57597BFC472E202FULL, 0x49F4AEEC23BBFCA1ULL, 
            0xFA8A33CD4533255AULL, 0x89CC9B9169F2DE87ULL, 0xD83E28C83344A369ULL, 0xE5B42A3413269B8BULL
        },
        {
            0x4E0390AA656973CAULL, 0xE9142E34AD9EE20BULL, 0x764507D438C7BB66ULL, 0x2E8875B8D633BBA8ULL, 
            0xC44E7BA15A65BBE6ULL, 0xBB0162A06C12908DULL, 0x7C80DBE0F0A91CD0ULL, 0xC2BDDC46B7981EC9ULL, 
            0x3DECB069EB1C6028ULL, 0xB4CFEEC14884695BULL, 0xECA34740446D7E96ULL, 0x896DF136444E7418ULL, 
            0xB638AEEE92255CADULL, 0x6ED7ED0AB5341932ULL, 0x4BB8F5E268976368ULL, 0xF92701D9F8AA2CF9ULL, 
            0xF28AFA988ED7FA94ULL, 0x448E561FE60E4713ULL, 0x78B3F3320AB435D0ULL, 0xE3B6B3C1703C937EULL, 
            0x608E69BA1E4CF38BULL, 0x0050456A61A599B4ULL, 0x40040441859C5190ULL, 0x001115E3A6307A27ULL, 
            0x05B24053A6D5FB23ULL, 0x5DA6E83079900C35ULL, 0x609F998A083E1FF5ULL, 0x59592F04E13FABDEULL, 
            0x23263A4A391AF801ULL, 0xB57A8F6BA6F9AE96ULL, 0xD371896E38FE34ACULL, 0x3B6339AC373BC560ULL
        },
        {
            0xE405110481BFCAD3ULL, 0xFD503ECCAF6B1CCEULL, 0x7F938B7A90C82D0CULL, 0x38D897A6AE81EC8BULL, 
            0xF4781F4D8B4A439AULL, 0xB7B7EA32B92E0043ULL, 0x3C997543A745C406ULL, 0x93EB475FD79EE00DULL, 
            0xCEF0FEA6D66B4195ULL, 0x95C4B86CAFCB7F3BULL, 0xE93FFE0159F1E414ULL, 0xB22983D965690673ULL, 
            0xB44F880F484307FEULL, 0xFD1A11444CB9DDB7ULL, 0x9A331D3E800B24A4ULL, 0x9CB9B2BFF559BFE5ULL, 
            0x3F5F48D17D675865ULL, 0xB625D7B30C99B11EULL, 0x88BF49F2F556F264ULL, 0x8DCD0D69AAF3F0EFULL, 
            0x63DE75AF88AD0248ULL, 0x6A18EE3B1CF97B59ULL, 0x7A6BB4D6F5F06B8EULL, 0x21A9D05FC86767DEULL, 
            0x80FBCDD3C31B046EULL, 0x148B857829D02941ULL, 0x08E093936F009227ULL, 0xFF1FCD801BEA9B20ULL, 
            0x21BCD6E9A52A8F46ULL, 0xBB28F9AB69BDD302ULL, 0x4B0F75B5F06019A0ULL, 0x78CDCC15382F10DCULL
        },
        {
            0x887C7257A9678DECULL, 0x15D2255F8C3D1828ULL, 0xDA40A9B6AB6D4219ULL, 0xDAD0C1FF0B3A3C8AULL, 
            0x7A7236502317F274ULL, 0xA88F7A4BB1D16F14ULL, 0x7AA54A3102A3A7D1ULL, 0x76F2CCA68EBBA6F4ULL, 
            0xD93DE6AACE30FEF8ULL, 0xA4F3F195AC941309ULL, 0xA51CCB015BA5B569ULL, 0x46CD5278E7D6E382ULL, 
            0xE8B97ABF9962CC7FULL, 0x9D28F069AABAD167ULL, 0x16FE2D41BFFD9AE3ULL, 0xCB1D62B39ED3385EULL, 
            0x9F0160A53282486CULL, 0x042F03CF6D8CFC24ULL, 0x93AA81556742A4E3ULL, 0x125B8EB69D49CFF3ULL, 
            0x74815B6336EAA327ULL, 0xE4DBDC5C1A26A972ULL, 0x227245ED7AF4B4E8ULL, 0xDFB70CF9F73E46E4ULL, 
            0xEAF80ECE7C7BC93BULL, 0x7C07485951DD4A1AULL, 0x1BA797FFCFD17DD7ULL, 0x3516632DF32E5FB5ULL, 
            0xA744E2A6C58E7B3CULL, 0x2A389886D6A7707EULL, 0x5124614DBB0602DDULL, 0x5E47B138A60FBDEDULL
        },
        {
            0x881B42331C5F05E6ULL, 0x93FBF418ECA253D0ULL, 0x44DE71A7692CECF3ULL, 0xEF7B86EF4BB80487ULL, 
            0xE03BCEA51B5BAAFAULL, 0x07605470A23F5272ULL, 0xC2A328C008DD7941ULL, 0x86907CCA0BCF74FEULL, 
            0x004D09E42864C394ULL, 0x8F4A1B0D73DFF1ABULL, 0x7E913D921C8AC569ULL, 0x4C9AFC7229987BD3ULL, 
            0x35E9BC61187F7AF3ULL, 0xC447759EB7703122ULL, 0x62827815E33225F6ULL, 0x5F34792B17C07BB0ULL, 
            0xA8FB66F1828F774FULL, 0xF4F5C9448CDD06E6ULL, 0xD27163DC7FDA8902ULL, 0x68731FE0BB601DB1ULL, 
            0x6B1BF3E6C9518454ULL, 0x14D1DE9A1EF55CF5ULL, 0xE6D6862A7FDEEE86ULL, 0x69AB2C09A29A2B7DULL, 
            0x2421C31FFC6F3231ULL, 0x156CDA4E053BA954ULL, 0x5CFB782B9D291611ULL, 0x5E108C7644423C58ULL, 
            0xBF8E8C7D17306164ULL, 0x27AF43959502C727ULL, 0x78C81A63779D8E1DULL, 0xB641176FE4289030ULL
        }
    },
    {
        {
            0x8AEC84A8BC21E816ULL, 0xC8CB3245BDFA67D1ULL, 0xA090CB2FFAB65079ULL, 0x396487CD71901DA0ULL, 
            0xD60A9A5C57C03A33ULL, 0x35C5B119E395FCC2ULL, 0x4824027E47693813ULL, 0xA4EDF56807A93F16ULL, 
            0xB3A522C2F56D2036ULL, 0x690226FC7BA7D7E6ULL, 0x27C8A370D812E586ULL, 0x343A9BD381D56289ULL, 
            0x76BBFB12ACBA3834ULL, 0x9B96AB035A406E44ULL, 0x68E75BE219E42049ULL, 0x772C05351CDB99ECULL, 
            0x116B64E424A88FD5ULL, 0x80ACFC479521D1FAULL, 0xFF52FE8F48EF265AULL, 0x3F3852C5E39D2978ULL, 
            0x4923766B791D342AULL, 0xCAF596081F0ED770ULL, 0x13522EE00CD7BD6CULL, 0xDEF4A6FADBEF4248ULL, 
            0x54604F2186066D63ULL, 0xF19A418F704C11B9ULL, 0x143CFCF17DFF6881ULL, 0x58A71EA6230759D2ULL, 
            0xE6377EDDF483928BULL, 0x99CA64A54722FD61ULL, 0x12583B292FD32F70ULL, 0x00759339AAB11944ULL
        },
        {
            0x1B74D6977EE1B5D7ULL, 0x3BEE00A936ABB5E2ULL, 0x263039E78EA42EF8ULL, 0x349AC08495D3F69AULL, 
            0xDB417233CC21F976ULL, 0xA25D747455208B00ULL, 0x7D9DC081C8351394ULL, 0xE8BBE5EA13E04365ULL, 
            0xB8E82F56EF602040ULL, 0xC3F639B3C53CBAD4ULL, 0xA2AC64BD89CCFB76ULL, 0xC968AB49D69292C4ULL, 
            0x609C1B2BFF9D9859ULL, 0x8BBA90907B30B45DULL, 0x45563CBAE2C2BCA1ULL, 0xDE4659C03BDA91A5ULL, 
            0x3672BE99B955A2B5ULL, 0x2FAC0501FB54AA9EULL, 0x3B3014D4025D66EDULL, 0x96EAFEB56FD94B4EULL, 
            0x7BE51257F829AD1AULL, 0x65D37169EA607A68ULL, 0x664BF8ED3BCD67F4ULL, 0x136D9E2CE87256E0ULL, 
            0x309A1E68E0C3A275ULL, 0x0410DE0D13289885ULL, 0x8D06B90AA2C6FCCAULL, 0x694AB7BAEF9F3B2BULL, 
            0x5D265660333FE246ULL, 0x5327FC1E3A7B3016ULL, 0xBFAB648DD5E15CE8ULL, 0xC9FD50C3DF6A1DA6ULL
        },
        {
            0x0985A03D3C64D5B7ULL, 0xFA9E0FA03D55D200ULL, 0x99DEE71904BF11C7ULL, 0xCE02B871E50B736DULL, 
            0xCC99FB717581FCF4ULL, 0x2BA23644D67B87BCULL, 0x362A5DE85079AE9EULL, 0xA732AA2FC91DEC6DULL, 
            0x7C1CEED23CA98027ULL, 0x66C7454BF723F5B8ULL, 0x458A171681672D46ULL, 0x5F7D0E7017D3F3C3ULL, 
            0xF31F0ABBC0D9A278ULL, 0xEA5F5F775F6B55D5ULL, 0x8E7C37CE922C3B8CULL, 0x7AB806151133DA81ULL, 
            0x02EFEA9D6A5788BFULL, 0x19D42490E72654F5ULL, 0x31E83F00850C2AF3ULL, 0xA9D922B94F3E840EULL, 
            0xCF3D4A229ABE8827ULL, 0x31F270C5649371A0ULL, 0x9D006AF34A6D94DAULL, 0x570D575EE8740D0BULL, 
            0x16696D28D42B59D5ULL, 0x4AF18E64DA0EB3D0ULL, 0x08F3D3D8AD565FD8ULL, 0x5E51F6905AF5C055ULL, 
            0x0DC7FA5A54452138ULL, 0x4C3FB975A058BAD7ULL, 0x9E3710FBD941D2FFULL, 0xDD14185965CDC6C5ULL
        },
        {
            0xE56049BE688406E5ULL, 0x3ABC26DCD21B5273ULL, 0xF40AA318C7E1255BULL, 0x65A6034F7EDB57A9ULL, 
            0x936FB9CFF82B358CULL, 0x2E37E323DD8397BBULL, 0xA3D211A25EA822DBULL, 0x18B4BE31E803F655ULL, 
            0x20C02F44BEEACE9BULL, 0x11F17384BA93A8B9ULL, 0xA00CD2BE2EDCE43EULL, 0x030CFAE334E69DA3ULL, 
            0xBDBA5264908254C4ULL, 0x65E3490EC41F7C61ULL, 0xAA3B4932051968DBULL, 0xB9BD462F37B2FAEAULL, 
            0x3D73755201DC9BB7ULL, 0x03C13ED5D25ECFFFULL, 0xB52029C9C7AFD94CULL, 0x5BEB6A468D76CB13ULL, 
            0x7EE0D61E4A2A2618ULL, 0xE610651EF855C321ULL, 0x4910CA2FF1EF342DULL, 0x5553131CBB7B7E01ULL, 
            0xB6CA22A018E7E109ULL, 0x055A2E5C66D7EECCULL, 0xDC8B16318A8B3128ULL, 0x26BBE3563E773464ULL, 
            0x797FF768D1E02BC3ULL, 0x680C26F999D68FDAULL, 0x422E80C4B03E7F3EULL, 0xC8E2863AC3E55869ULL
        },
        {
            0xDD3F7FC2B509643CULL, 0x78AC0C1F473CA8B3ULL, 0xA022EFDF58F46943ULL, 0x0F7F86E0E00EC334ULL, 
            0x7F745D185199B2E0ULL, 0x5A595A334F8CB9EEULL, 0xC9DEA31F3CAE4E93ULL, 0x6983E106B58235E8ULL, 
            0x9E5470C38A66EDDCULL, 0xC663B55254D1D7C5ULL, 0x7D85999366C63E01ULL, 0x18D378FDD8D97D64ULL, 
            0xD75FECA9792E927CULL, 0xB47D6AEA4C84AD21ULL, 0x2D132F9275BDFC90ULL, 0xB3EB69870F0884F8ULL, 
            0xDD852C88ACF08AB4ULL, 0xBBAC67BEFC36B367ULL, 0xA7F5A01E3D92AFEFULL, 0x70972EF4874D9F46ULL, 
            0x68C000AFBFC19161ULL, 0xCC6785FB03009D97ULL, 0x41D69D55A6667839ULL, 0x06D4B7D9F64A7944ULL, 
            0x233E01A38E201112ULL, 0x06A4A08E5940E8D2ULL, 0xB611A3389B347D08ULL, 0x9779D662C06F410DULL, 
            0xB434940870B351DAULL, 0xF3504752C31246C6ULL, 0xDFB7FB174EB494A0ULL, 0xF84959D665EB5A95ULL
        },
        {
            0xEBA56A710EB20D85ULL, 0xFC3F9C002F77C065ULL, 0x5CC5001B7130BBCFULL, 0xCF8106682F92F508ULL, 
            0xB7B9B2DBF91175D1ULL, 0x79E3039F0CF1175DULL, 0x592CD58D299C3121ULL, 0xD26F5D2CA73E2386ULL, 
            0x30C250BE13CA976BULL, 0x5A3FC369E950BC29ULL, 0xD4A672ADB9117B57ULL, 0x92EB87CEA572BFEBULL, 
            0x0F69E34560D0C7F6ULL, 0x3B9DDAB55B1AB4B3ULL, 0x5DBB7FD7C222D740ULL, 0x4A53BF628E308C27ULL, 
            0x6BA94E7AE7AB0EF2ULL, 0x9C245ACFFF7BF7A6ULL, 0xBD79CA990525E8BDULL, 0xD7A84103CCF34B8AULL, 
            0x16CC8C7CF2BB3C8EULL, 0xECD823C7EBB8456FULL, 0x2705007A42F2CB03ULL, 0xD62446F2883F0EE0ULL, 
            0x316EA8B2888ACE93ULL, 0xF2EBBABA2CD3D2F6ULL, 0xC733056881E3761AULL, 0x60F249D11C18C576ULL, 
            0x710017A54912D43DULL, 0x6BABDC3385A396CEULL, 0xC2903904497F73AFULL, 0x5451EF8E4FF73300ULL
        }
    },
    {
        {
            0xCFC3FEE32E462D8FULL, 0x8E44536B3381BEB8ULL, 0x9A97310EFED1BE5CULL, 0xA752A36E0ABE0D63ULL, 
            0x59FAC40CB1A5CCC7ULL, 0x6282EF255E64309DULL, 0xFE53259F0372E059ULL, 0x6CA39C4098B8101BULL, 
            0x06199C12C243612AULL, 0x7F0EDB2055C9618CULL, 0xFB97B162D81DC628ULL, 0x2497686B40C24496ULL, 
            0xAA044BE8938278A1ULL, 0xD401A49CBAFEA3A9ULL, 0x8DBFAE1B83F81752ULL, 0x0E7C3255AF7A19A4ULL, 
            0x8AB0EC9A387E268AULL, 0x6E0F4A17A2860321ULL, 0x0AD18FF7A0219D60ULL, 0x31FFF60F653AD5C1ULL, 
            0xDF0ACEA77D72CB5AULL, 0xBCBCDE3A11A90724ULL, 0xCEC0C315CEE8E6C1ULL, 0x50CAF56BC47949B1ULL, 
            0xC506AFA572BC4E69ULL, 0xFB4EC125EFB1C9BCULL, 0xECE5F7B29A448EBFULL, 0x33892BCB9B8DC9ADULL, 
            0x1F49BE223EFAED04ULL, 0x31462E6358447757ULL, 0xE9AA24F5A2C6CBB4ULL, 0xBFA5A36FB865CDF7ULL
        },
        {
            0xB607684EBFB66043ULL, 0x5DB4F7A0A2B29A53ULL, 0x7E542DBF5E4ECC4AULL, 0x65D196DCEA7872ADULL, 
            0x79F0B3ACBFF92DD3ULL, 0xA752B75479A82A29ULL, 0xD944437E41767B87ULL, 0x4F9988F7904B3148ULL, 
            0x0BBC289C7BB55A78ULL, 0x7F57F27C8958F96CULL, 0x9D9D7A3AE48D630AULL, 0x0C5B3D7B838F3B46ULL, 
            0xC8B07701EA9E6B8BULL, 0x70212C1B53ED3D73ULL, 0x4DFD3F001499AB53ULL, 0x877A567D2156CD0BULL, 
            0xCD5748127DDA22CEULL, 0xDCA506217F37F183ULL, 0x25AA28FB19FDC761ULL, 0xC27164CB667B5801ULL, 
            0x9F587BE458292FB6ULL, 0xBFA9212852DCFAF9ULL, 0xA233363CDE08A81AULL, 0x78C392CFB17D7617ULL, 
            0x4B5824B9D59EF1CDULL, 0x61464D2170379350ULL, 0x558C8B6C5B2B4F02ULL, 0x43D7F705B9817546ULL, 
            0x489326DCBD7EAE39ULL, 0xB2C8DBD981C0B227ULL, 0x49C6C4E033FC848CULL, 0x1673240E4A2CAAEDULL
        },
        {
            0xF016AADD060D1FBBULL, 0x5CD1BE83276F7757ULL, 0x60ED14C7289FCAEBULL, 0xA71DCDBDE86415A1ULL, 
            0x1BCC262B51A945E6ULL, 0x5D0E6649ABB74B50ULL, 0xD48409D2CFE495B3ULL, 0x19C5A4E855B9BA96ULL, 
            0x89C7E460AB3EE550ULL, 0x4AB794811431FE99ULL, 0xA0FD93A986C97B8AULL, 0xA507E7A309DD8882ULL, 
            0xEE7AA07A129D613CULL, 0x31DB49A7FB00B1ABULL, 0xA3510F9290968BD5ULL, 0x19C753F3DF5D2052ULL, 
            0xAD62751EB11B07F7ULL, 0x83565720C6ED3E2AULL, 0x329A8C2F8D22C42AULL, 0xCA7CBE8CAE723E9FULL, 
            0xA54A68F34CFD24D5ULL, 0x8BD8124FB958D9E8ULL, 0xBB54EB431741F8C6ULL, 0x4BCACE0735A8097AULL, 
            0xC57206491C35DE00ULL, 0xE527AEAA6F78B678ULL, 0x485EFC45E8ABB3ECULL, 0xE4EACA3C13AC3DF1ULL, 
            0x5C6D4FA52340A134ULL, 0xD1876366CC756212ULL, 0xEA11B188181F89F5ULL, 0x7F090A704CB4347AULL
        },
        {
            0x181485B25913D16CULL, 0xF364151FE7F30D2BULL, 0xDFB0C01A63657272ULL, 0x5740E5A3399791D4ULL, 
            0x7D61B3D278036B96ULL, 0xDED9DD4C13139767ULL, 0x3ACF9E7880EFF728ULL, 0x15C48D12D82B5197ULL, 
            0x817D32C23805185DULL, 0x382B0200FC55EB21ULL, 0x81A8360E384ECE73ULL, 0xE253A7A717EE1037ULL, 
            0x068ACFFE7E106667ULL, 0x22F66D9F1F784401ULL, 0x56ECAE6ABCCC9E07ULL, 0xC0CED51192FF8C30ULL, 
            0xD5FAFA933C8E49ABULL, 0xEA53FA9B33C6D108ULL, 0x98DEED0DB88D9BC0ULL, 0x9CBAA40B96BB2AC1ULL, 
            0xAA385477973ADB62ULL, 0x8241682E92DC8BF0ULL, 0x816E59A8AFF9E800ULL, 0x4D85F9A2E659264EULL, 
            0xD3BD4613CA8458F4ULL, 0x0A03CB330EEBCD20ULL, 0xF9365CF62C852386ULL, 0xFEDD495EA16CA162ULL, 
            0xFED54A4845886DB7ULL, 0xEF57A0479DE26D37ULL, 0xF0803E01FD482FB2ULL, 0xF7542D243C6CFDCEULL
        },
        {
            0x34947A53E805702FULL, 0xEFBAF475838FB07AULL, 0x96721C57ADF652CDULL, 0x4E35327E1ABD3F0EULL, 
            0x0BD03E41FF68229EULL, 0x65C04EB4F5A3CB28ULL, 0xE942903848104E41ULL, 0xFE959E01B511AA3FULL, 
            0xBA28694251F01055ULL, 0x30D9F37D737DF32DULL, 0x43AEE2C0E0A932BBULL, 0x16838E53F2FAAA6AULL, 
            0xF12D554E121E53BAULL, 0x57CDAE9B04EB2EB6ULL, 0x800C7BCF731A0236ULL, 0x44A0BBB7E37CF5B5ULL, 
            0x3D610F56C1C580BDULL, 0x8F37349F7E81AB07ULL, 0x94838B529AC69DB0ULL, 0xFC066A343CBD9ACBULL, 
            0x4FF3CF1720973A38ULL, 0xC61D782873ADC556ULL, 0x99DB297244810F52ULL, 0x74FE40CAA288513CULL, 
            0x5EC2073911EEBB1FULL, 0x6FC978102131AA50ULL, 0xAED6899B10190A14ULL, 0xD5281B3ADA310405ULL, 
            0xA15F7A72A32B600FULL, 0x33DCFA7DBB730453ULL, 0xE38A97C3CA19FFCCULL, 0xEE95D0FF501DC129ULL
        },
        {
            0xF725B2F3967BCA17ULL, 0xA75E6144C3DFD7B9ULL, 0x2A6D7B00D5473636ULL, 0x08C3B3ECC46EE76EULL, 
            0x1E484A6F09EC503CULL, 0xF6979469C66EC9ABULL, 0xCFDA108F7F12CD7EULL, 0x2E3BBFF626B560CDULL, 
            0xE7DA959282B49A64ULL, 0x77B44EC9802A4D6CULL, 0x16A7799938FF9A37ULL, 0xFA4F979C56B51321ULL, 
            0x8F0953DDD44CBDB2ULL, 0x60744D739F10B235ULL, 0x6DAF1B226C4E3AC5ULL, 0x4C1B2C1BAE56BB60ULL, 
            0x29B772BE086999C1ULL, 0x1B89428F8CC1F40AULL, 0xFABE1D867F761566ULL, 0x39FB32C20CC6EF9AULL, 
            0x64E2BFCB23319D35ULL, 0x1CA1C8C646256382ULL, 0xB0D804E5C4CAF21BULL, 0x077A16761BD23A1BULL, 
            0x7BC4FC5FC07466ECULL, 0x9CFB585E21E951AFULL, 0x5A7A8BB87A1F4B6DULL, 0x04B44951DD0696DBULL, 
            0xAF909A5F5F2E8F7FULL, 0x6C4BDF9EFA641AD9ULL, 0xAFD8F2B23FB40EF1ULL, 0x4B6D5BF1B5874751ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseFConstants = {
    0x8A9540E3ECD99B2EULL,
    0x091C8219E2AB3BD2ULL,
    0xD7C8D90712670C4BULL,
    0x8A9540E3ECD99B2EULL,
    0x091C8219E2AB3BD2ULL,
    0xD7C8D90712670C4BULL,
    0x059C15831912189FULL,
    0xDAB3C517EFF88AFBULL,
    0xAB,
    0xCF,
    0x8A,
    0x0C,
    0x0B,
    0x54,
    0xF4,
    0xE1
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseGSalts = {
    {
        {
            0x478A4735552BAA14ULL, 0xEC4905DE42E2B83EULL, 0xBD1BDF9A21D4622BULL, 0x72FC364914A71028ULL, 
            0x3FDFBF0C58EF1F6CULL, 0x11D33786A23128A7ULL, 0x494D18176415CB48ULL, 0x9B109CCD4A99A819ULL, 
            0x99B1A01B2FF65D4CULL, 0x10B16A89710E5A41ULL, 0xF56C12C6A5B7C8C4ULL, 0xFAE3102DE36BD4E0ULL, 
            0x835DA76F313F456BULL, 0x8C55419347272603ULL, 0xC57363E19F232BD5ULL, 0x1B86CD03E47523E9ULL, 
            0xDC6F98D9FF288E5DULL, 0xFFD1D0285F3140B2ULL, 0x2F2530F0BD14361EULL, 0xB1FC915EBF4836FAULL, 
            0x01FDE31DD7FE529CULL, 0xBDB1A6605E8C6582ULL, 0x2DAD43F816FDE423ULL, 0x4C5E37E415D32F3CULL, 
            0x6F650E97B1CED75EULL, 0xED32CADA9903D8AEULL, 0x8DBA712D953FCDD3ULL, 0x37F1E16FD276951EULL, 
            0xC181871868C86976ULL, 0xF11719EEFBF64AC8ULL, 0xF5579B2CE4DA7E68ULL, 0xE427DAB7D10EB62EULL
        },
        {
            0xF4B3E3FE09502459ULL, 0x83D3116A5D396FB0ULL, 0x8241964170D68EB8ULL, 0xB549710CC81AFBC8ULL, 
            0x8A8809F64256ED82ULL, 0x8C8B7B9C5FD24D83ULL, 0x517FB1387B07D589ULL, 0x13C9768E5857BF59ULL, 
            0x296B18C520FB4194ULL, 0x3657CD5C1A9D1221ULL, 0xF18993FA42B34737ULL, 0x221E2F5D78EDBB47ULL, 
            0x67AE1BABF020F760ULL, 0x82667B1115272748ULL, 0x30CF8085659CE9D8ULL, 0x9F306AE6ECCDD99FULL, 
            0x6064E44C90388995ULL, 0x388FFAB11AEFB5FDULL, 0x231D17C83216CCD8ULL, 0xC0D0130776F9AB8CULL, 
            0xC2FAFC4323188C10ULL, 0xDBC321F04D30366BULL, 0x537EEA590BD03BA7ULL, 0xB99AB66B5A69630DULL, 
            0xB5901E40F73345AFULL, 0x72E22EE41199A800ULL, 0x56FBF9D4BAF9972EULL, 0x618D929E16FBEBB0ULL, 
            0x4D777651938CB2DBULL, 0x3BB43677983A5AF2ULL, 0xAE7B64604E180664ULL, 0xA1FD34B1E6050282ULL
        },
        {
            0x7EB3EA97A8E6BD2DULL, 0xE52EA1E5DFAF034EULL, 0x56D5F78CFD3A88BCULL, 0x5994DA4E85C790B8ULL, 
            0xA18671802133A871ULL, 0x458E845AA24051A2ULL, 0x3BAC1C9C3238CBADULL, 0x901464CF5B6B0233ULL, 
            0x8AC3A8CB71579FE6ULL, 0x4D87509421714BC4ULL, 0x97A998C2EBB0B71AULL, 0x6F3F9E57DC5528B7ULL, 
            0xE73DF31A67310304ULL, 0xA187CEEE20F25B46ULL, 0x1CB3753D90EEA74CULL, 0x73BFC558972C3674ULL, 
            0x58E6C889A6B33EB2ULL, 0x6F3D7BFCAA9F80D8ULL, 0x43DC46B0D4FD57E3ULL, 0x428404C5EEC4B39CULL, 
            0x32D6F96F1E755BD3ULL, 0x77E15A6175DBD757ULL, 0x60F6BDBA08ED2130ULL, 0xA5168517D09684E3ULL, 
            0xF707F0C52469F577ULL, 0x61BA827B9C81A7C3ULL, 0xD37CF02B4E00085AULL, 0xCFAF06DA9491AF26ULL, 
            0x00E9C4C8E1AC9492ULL, 0x44F106CA55E7A5B4ULL, 0x98AF0791C5E750BBULL, 0x34AA57D4E8935A5AULL
        },
        {
            0xE4867C41E4102B8CULL, 0xA1DBC989813B21DFULL, 0xF1CF86DD3B231223ULL, 0x0E504F529D132A24ULL, 
            0xC93EF17E7FF9A5B5ULL, 0xC4D18DDA934BACA7ULL, 0xAD689506360494C0ULL, 0x2B01BD2936D6ADA6ULL, 
            0x5586E644E2CBFB76ULL, 0x71A6CCDB7DF4FDEFULL, 0xF971B044B3992F76ULL, 0xD0339FA2A824F416ULL, 
            0x96F2F3593BA31427ULL, 0xDDE1EF280F70FF69ULL, 0x014875B97377B116ULL, 0x83F5EBE5DCE9D0BFULL, 
            0xF0CE5A57C8C7A749ULL, 0x3CFCCC35BF239694ULL, 0xE42BB5C44912E246ULL, 0xB115C2C04D4A2784ULL, 
            0x5E3AA976234A355FULL, 0x681E46FCA1C67703ULL, 0x1AAB13DB34FB4AA2ULL, 0x5640C28B058C5FC5ULL, 
            0x5A97171EF4295FCFULL, 0xCA2C42B97106E310ULL, 0x004FD413F431A9D4ULL, 0x4FF70C666A5308F7ULL, 
            0xC33FB17AC6320CA1ULL, 0xEF7FDE8FAC84E432ULL, 0x9BD04B8F3B806A8BULL, 0x6A87FA5DC2BE4AA6ULL
        },
        {
            0x56AF0A1763460374ULL, 0x2BD96BC6D42520EEULL, 0x1E6F3070F56B1FAFULL, 0x0F042BA6A3DD99C2ULL, 
            0xCB5698C6E008907AULL, 0xE830C742A42B8503ULL, 0xFFCDD80AF5803C3AULL, 0x5853749DB127B7A6ULL, 
            0xF7AD00A59B2A1873ULL, 0x4EFBC28F07F68F38ULL, 0xA3B32637F1B26F36ULL, 0x5B7170E815A3EAF3ULL, 
            0xA5B4E14C3915D737ULL, 0x05C90AA5485725C1ULL, 0xB958AA231ECB3591ULL, 0x2672F7679A725BFCULL, 
            0x9D457725A8775311ULL, 0x1F45FA2EAB07B43DULL, 0x49C5F9446C7BA15EULL, 0xA1D1E6220216E0DDULL, 
            0x10DA6A0A8DEFB411ULL, 0x940F9B7B36A95354ULL, 0x5DFD39022769920EULL, 0x5BF7F52A1289BF62ULL, 
            0xCB133A2DF03A5827ULL, 0x17C7D494AA73D7EEULL, 0x5DF17B4EAB332897ULL, 0x9BF106EBA400FDEFULL, 
            0x1199BC89ECFB8F41ULL, 0x913877DC04451F11ULL, 0x8E678D4A9381642DULL, 0xA21F0E27781D1E44ULL
        },
        {
            0x356926114F809498ULL, 0x150EFC2597DFDFBBULL, 0x71CE60D86D9BA90CULL, 0xAD440596293094E7ULL, 
            0x1620B4A39ACDD79CULL, 0xC3EB64F2E5332795ULL, 0xB9DC4E4250981A6DULL, 0xF12735C0E137B7A9ULL, 
            0x95A1655793FF3A93ULL, 0x7DA6A864DC2E680FULL, 0x0B8FF689A336CF3DULL, 0xE5B0A9D1300373D1ULL, 
            0x9F0672E39FE48E56ULL, 0x238ECE0A9AB5F2C3ULL, 0xF8748F1D62F79035ULL, 0x419847AD04BD5161ULL, 
            0xBC61B0C5D8804090ULL, 0xAA39C7800C2855AEULL, 0xF7AF576F7D3E9709ULL, 0x35E4AFC34B295334ULL, 
            0x37AEFCD94B25CD90ULL, 0x05D2F04CF6454CACULL, 0xA5AEE9590DA9A3E7ULL, 0x74D38563A9EB0E65ULL, 
            0x00A3207DFCB2FBDEULL, 0x8AC3D563C328D04DULL, 0xF7F0FD826D8BD370ULL, 0xE00BF8E650ADCC02ULL, 
            0x8F81B845346840D7ULL, 0x043978469E2624F4ULL, 0xB21B775CE6D3C561ULL, 0x4A2D930041F83139ULL
        }
    },
    {
        {
            0xF00EEC998A51D438ULL, 0xBF0AA8770825D448ULL, 0xA606AFDEC1219DFBULL, 0x71D5C101D419C7FDULL, 
            0x3EE8985B8C82A097ULL, 0xB838B3B3BD908615ULL, 0xF133C8FE053813A8ULL, 0xA52BD60E0B0AE7AAULL, 
            0x27775EAAA55E9E3FULL, 0xDA72432162E7FCA0ULL, 0x9BFD4E9848C163F3ULL, 0x4B7A42AE2061650FULL, 
            0x143C5A4DD7A18C79ULL, 0x7AB1D8D7914F460BULL, 0x432A2148CF050B7AULL, 0x8B5B47643D6C27A5ULL, 
            0x2DC3A2D3A6C94DEBULL, 0x98CA45D4EDC0E7CBULL, 0x381A4906DE0AA6FBULL, 0xACB393DC601601DCULL, 
            0x46B608D21A15311DULL, 0x9434BC3392F1BA04ULL, 0x8F12E013EE43EE67ULL, 0xF7F72C5CF7B11DB0ULL, 
            0x861292B0117C184EULL, 0x75FF717F6FA57703ULL, 0x38E44DB81B3B7759ULL, 0xFC9470309A6E8561ULL, 
            0x73F24F9589F379B1ULL, 0x86600BDFD8149843ULL, 0x16854D0ED9E4E701ULL, 0x005DF4C5D0124B79ULL
        },
        {
            0x54CA5A270E0A2E91ULL, 0xCF1C45C92950108EULL, 0x05A89225AD69865DULL, 0x2786224C5F693FC6ULL, 
            0x7C880EDB95DDE225ULL, 0xFC4B08759E5F87FFULL, 0x97F117D47F313D86ULL, 0xBD7FD9B9E31B0EE2ULL, 
            0x6B048207C34D8A5AULL, 0x8BBF81A9CC2380D5ULL, 0xA9ADDE4E89738F1CULL, 0x3D3F8293EC62A101ULL, 
            0xB3BB67417C509F06ULL, 0xCD0188F2F6B699A1ULL, 0xF2371761E38B991AULL, 0x02D727EBD2FDDEC0ULL, 
            0x143B334416FF3CDBULL, 0x933FB1E0AD7A86BDULL, 0x99F0EE67F3CF6EFFULL, 0x4A1E797F15A8B519ULL, 
            0x6C2F7FFE931DF7A1ULL, 0x7FCAC5448336DA5CULL, 0xCB10AF23992F0E4AULL, 0x1E7D326AB90F52ABULL, 
            0xAB14AB61F04F6DFEULL, 0xF2BD687217422620ULL, 0x50627ACE63C9D0A9ULL, 0xE072C92C7ADA7AE2ULL, 
            0xFA879506232F4926ULL, 0x378659F328ADFE2BULL, 0x74852F5E2310132EULL, 0x2BF1E5F538ED3EC7ULL
        },
        {
            0xEEEAF5AF1D9C325BULL, 0x2E9A60AC0BC501A8ULL, 0xB1D520A0A5336CA2ULL, 0x0E2CF402520418CFULL, 
            0x28AE83DAB5F2907FULL, 0x62A1EFAC658AE9BCULL, 0x53C85C71B2B961ADULL, 0xFCDE3FE87421E9B0ULL, 
            0x78BABFB73D45E274ULL, 0xF735114AD19B932CULL, 0x4C8EF914D164CCD7ULL, 0xF7FE07887EE08464ULL, 
            0x3C54BBC9B89C4F3DULL, 0xF651BF3F74B470C7ULL, 0x1197417BE58C6F91ULL, 0x03BB913D7C193423ULL, 
            0x2CF716F276457BC5ULL, 0x940E07234A54B2FFULL, 0xC9F6D5F5D2EF0CEEULL, 0x9A3254D19AF1CD25ULL, 
            0xEFFB9BC95E375040ULL, 0x2401ED827AE12043ULL, 0xA275A01A740FD6F0ULL, 0xA4A925A23D6B836FULL, 
            0x262F34506C8A7B80ULL, 0x2BE18341A063827EULL, 0xCD6A39828F6BF414ULL, 0x1366843AB07F6CCFULL, 
            0x6BD3D24A0D103233ULL, 0xBA93E262494790F2ULL, 0x01EFB6727E5AF99EULL, 0x2FF66B00C0BE26EBULL
        },
        {
            0x1BE8B24C8A3729EBULL, 0x057FD17C0B279934ULL, 0xB30EAEA6D5458DDEULL, 0x8A8E8124A713DF57ULL, 
            0xC2159392EF9C1B1FULL, 0xFB9EA7BCF7E84565ULL, 0x1B86038AB0F3D73DULL, 0x642CED4DC19A9875ULL, 
            0x5A20A8BFBD18D4B4ULL, 0x6544C73F05BB8BFEULL, 0xD932BBCF6BCA2543ULL, 0x21480FC4F12BB0C0ULL, 
            0x6408EB9662549A5AULL, 0x6E8C16FB80415480ULL, 0xC8C31DE6D5E7D2D2ULL, 0x6DACBB78BE2B94DEULL, 
            0xF356C4D9C46A1D4CULL, 0x1587B5610E4848A7ULL, 0x1B8974AD507FBB7FULL, 0xDCC74D9B150544C4ULL, 
            0x162D348F52FAB7B1ULL, 0x176A971DA4BE24DCULL, 0xA071F7E259F88DD7ULL, 0x7D9A0861B01DBF74ULL, 
            0xD1F95C48B418B3A1ULL, 0x6450AACA5292F9F7ULL, 0x8398BC96C5FBAB5EULL, 0x36EC8C6C209D208AULL, 
            0x48BF47F3170C278EULL, 0x4B5B0D7EFED266FBULL, 0x87A69EABD5D5D0BEULL, 0x5CB654F3B73BD17FULL
        },
        {
            0xBFE911C9C394F647ULL, 0x477320A37502BE76ULL, 0xD9A3D041E97A00E8ULL, 0x2E35B966EF38E4BBULL, 
            0x845923D483AE9449ULL, 0x3B3996C57C9F4728ULL, 0xF6F768B592772967ULL, 0xE9D61886AEFFB75DULL, 
            0x6DC6CA02199F13E3ULL, 0xE83536B367B43F58ULL, 0xA89FA74EAF210511ULL, 0x1775E51378EAC115ULL, 
            0x6DF0ED57F7E3AE91ULL, 0x07FECBA427B0A39EULL, 0x74F396A78D0D981DULL, 0x4F5D1234E10802C2ULL, 
            0x3F6EDB6D57B302C3ULL, 0xED327401C21CB879ULL, 0xB72D553500D1747FULL, 0x41A565BB1137AD5EULL, 
            0x11A2493F158B4547ULL, 0x4030232FF833F5D8ULL, 0xD6ECF93F1257903CULL, 0xBA5191A83D1A6542ULL, 
            0xFEF63F92D6295868ULL, 0xFD2C430FCB07BB32ULL, 0xCB8936AD47A1F0A7ULL, 0x35BA4E3930F4A306ULL, 
            0x5410727D52BD8927ULL, 0xDB880F71A2DCE90CULL, 0xF3E83B6B8635C888ULL, 0xF8F2052A34D87B01ULL
        },
        {
            0xF7543CE1B2AAFDBAULL, 0x34EAF4D449E0342AULL, 0x54B9EB9870CE6D7BULL, 0xEDDCAF0150BEDA26ULL, 
            0x7AF375FAD3AA6BF8ULL, 0xEA2829D8AD72F1C7ULL, 0xC13A23B288B0B098ULL, 0x801664357C79F8D5ULL, 
            0xCE47F5ED9F6CDE81ULL, 0x4B9C79A6675E9798ULL, 0x4731345C98DAC0CBULL, 0x4FE01D4900E9EA98ULL, 
            0x1D3B2C50B363359AULL, 0x2BBAAD01FD3538EBULL, 0xC4791C9888CAA53FULL, 0x48847B6FB71713A1ULL, 
            0x4C1F83654923A3C5ULL, 0x1CF7B295E9679B51ULL, 0x759364FCF4683D0EULL, 0x9E605FE462597550ULL, 
            0x15773D0ED86806DBULL, 0x77AAC70CEB11FD68ULL, 0xF7F1EF5EC9BBC478ULL, 0x5F55282FE8A35129ULL, 
            0xFAE81B129517E10FULL, 0x7586F371930D5868ULL, 0xC4B4C5747FBC2A91ULL, 0xD91259909901DA21ULL, 
            0x59865412B53B40C1ULL, 0xB13C36A57B390512ULL, 0xBA94C9FF9400E19FULL, 0x876B5A663A234C8AULL
        }
    },
    {
        {
            0x475311D314AC8F00ULL, 0x2751296D4EFD647EULL, 0xE97141EBF5C01439ULL, 0x263AD175FA7CADA9ULL, 
            0xD2874FD30E1AA6DCULL, 0xDD9D61BDDDA9BB2FULL, 0xE54168645B4DE54FULL, 0x29515CCFB21002B6ULL, 
            0xDAEC150C7655BBFDULL, 0x1141099558480F55ULL, 0xD387AF1A19DAB36DULL, 0xE643B4D70C3ED4EDULL, 
            0x0A72C8F10DC59F6CULL, 0x8D4F7C432100C415ULL, 0xDBACD4F320936C0BULL, 0xFEF3821ED756F82EULL, 
            0x474473B027859D40ULL, 0xFA295233F781A108ULL, 0xE94CFA5BC79084EEULL, 0x818F2CA19D354EC4ULL, 
            0xAFA197479F014478ULL, 0x25DC1AD78303C5F1ULL, 0xE6401D70829E77C1ULL, 0xDA4D9ACCC7427331ULL, 
            0x86A79AF8824D2A45ULL, 0x53BE9295C6F0F8F1ULL, 0xFFA794242A75EE30ULL, 0xCAFACEFFD77DDB6DULL, 
            0x16491FBB9178A6AFULL, 0xE263804B00A24684ULL, 0xDBEB65C874E68476ULL, 0x34F32163E94E614FULL
        },
        {
            0x100A4EBDA960E9CBULL, 0x913B7F82EEEB3EDFULL, 0x7E6B218C5D1B865CULL, 0x8826CC19BA12C06AULL, 
            0x716D656B866FC2CAULL, 0x72FA3AAE5E085D9FULL, 0x753B46B001EF313AULL, 0x9DDFB0E80BDF40E3ULL, 
            0xE888799113F60123ULL, 0x43C6762E2BA4A3F3ULL, 0xACF924B453411908ULL, 0x6AE943D42D146F14ULL, 
            0x42A6738367BF6767ULL, 0x95FB2BD451A3301DULL, 0x2851F6A5DE5F4EEBULL, 0x4DA53825F012D4F2ULL, 
            0xAF326888BDACB493ULL, 0x43E2EFDF385E5E1EULL, 0x5B96591C3CD4E7D5ULL, 0x1DFFF5EC18A94233ULL, 
            0x966CDA3412BE6002ULL, 0x9A4FAF341B54C905ULL, 0x92C771E94D95BA5BULL, 0xADF94ED7744B5F0FULL, 
            0x118FD66A526E17DDULL, 0x00B3FC17BCFC2491ULL, 0x4085F68CBDED0DEBULL, 0xB704303DB655971AULL, 
            0x9A04B255DE63B4B3ULL, 0x84C53DFDBEB1884CULL, 0xB002841F063F15DAULL, 0xE9A6C0EC6053F1BBULL
        },
        {
            0x4C793F2BCEFB4B85ULL, 0x856CC36963E4F586ULL, 0xB0229929854EA03DULL, 0xAB3676A12B93F2B5ULL, 
            0x915E74EED5BFBC57ULL, 0x5C61525DE1AA00C8ULL, 0xBA562601E8C63E69ULL, 0x8075EF2A1081F607ULL, 
            0x8AEBA79F4090A8FDULL, 0x060B5B5C0E5A6D26ULL, 0xE377B306BC615690ULL, 0xA6D05785B03B3AACULL, 
            0x794EF3F9AA85983DULL, 0x372B81DE137B0578ULL, 0x064593A6786C7AC2ULL, 0xF5827C15ED3B1E64ULL, 
            0xF676EE311F807A99ULL, 0x70D8DF0CA11A1237ULL, 0xE29B52E0B631E8C0ULL, 0x8DABAA918057CD7CULL, 
            0xF39C97BE97A0C4EFULL, 0x987FAB320660B9EFULL, 0xE70B899A1E52826DULL, 0x6C3FF3C78CC82A24ULL, 
            0x7D5175690ABF24CFULL, 0x408E661658C59B37ULL, 0x8B0CE17DA6C5E0F8ULL, 0xEBB96C7149B48A7AULL, 
            0x183E9AA5FF6C1FB6ULL, 0x449CA632FD6467E1ULL, 0xD8356E10EF8D86CBULL, 0x4224F733DC07DC8FULL
        },
        {
            0xF1C045015F8B41C0ULL, 0xCFAEBC37A25A9DEBULL, 0xF38025C619E9353BULL, 0x91B23ECCFCCDF5CEULL, 
            0x92C17922C7953314ULL, 0x39CA452C648BBDBBULL, 0xD6B22B8341AF5101ULL, 0x2F19CF87A7A43C37ULL, 
            0xBB99D3F286C9D635ULL, 0xF9DF364AC1A9D7F7ULL, 0xCC7C3EFD1DC668D2ULL, 0x3AF039FA902C1F3DULL, 
            0xFAC0CB7C578264D5ULL, 0xA0D90C2BB1A7FD1DULL, 0x6BF1BFB4062C302BULL, 0x00B6D95643D9EA8BULL, 
            0xF273D289D8889F8EULL, 0x04CADDEA03E0D4BFULL, 0x07E87EF26D007466ULL, 0x4B179B76BE5DEE3DULL, 
            0xF0BFF02C99FDFF7AULL, 0x377924FC18532BD3ULL, 0xF4927EA4D9A7C87CULL, 0xD3D080123F02E8B8ULL, 
            0x5F52F53D5BAD4DA6ULL, 0x112632D1F068DD37ULL, 0x89756896B0D4E91EULL, 0x549F280EC00ECBD9ULL, 
            0x45B94CDF2D6E375FULL, 0x2F626DE55FFFB51BULL, 0xB7FAD8377BC2D6FEULL, 0x9FDB3BB4E789537BULL
        },
        {
            0xABF71A33A720AE39ULL, 0x9A5A58735CAADA6FULL, 0x2F6EE4741CCB652DULL, 0x20AF3C66D6CD8CF6ULL, 
            0xFBC6CA52AF95C68FULL, 0xF1DAE1DEEE9371A8ULL, 0xD0FE7C999BDE3FE7ULL, 0xC78D3564D00836AFULL, 
            0x0F3FD9B2881D6DF5ULL, 0x77B721DA8EDF6C78ULL, 0x64A032A9F00CE04DULL, 0x5F6AD66DE714560BULL, 
            0xAEC23F7667F76939ULL, 0x17C62012BFE18B3EULL, 0x98A99B19175F23B5ULL, 0x34C0E949E80BE0D3ULL, 
            0xFDEFB411BB6716B2ULL, 0x5BBF99D5F0E66F53ULL, 0x1B6383AC101CBCD1ULL, 0x55B3890C67D28A28ULL, 
            0x6DB9C1024C389F4DULL, 0x655A6B9CD24823EAULL, 0x6FD963ED39C6D2D7ULL, 0xD605AB949E108CA1ULL, 
            0xF551B977480C79FDULL, 0x57223FE4120EAFAEULL, 0x7C4462191342B17EULL, 0x6EA9ECB49F3E3599ULL, 
            0x7DE20841CAE35B8EULL, 0x9D43E72742E01477ULL, 0x25E0A01507DAE00BULL, 0x774A5D51D3B6285FULL
        },
        {
            0xE47AB623A2BD7EACULL, 0xD21B2671293579E7ULL, 0xE032084CFB2732B2ULL, 0xB03ECEF9996FCAECULL, 
            0x38D24AA88B65A617ULL, 0xAE3986412C7C8AF1ULL, 0x4782D0545C198928ULL, 0xD81DB60948D59371ULL, 
            0xE583031AC6741143ULL, 0x5EF145D058674C9EULL, 0x121ACBCD2B70C685ULL, 0x1EDF218C2057D211ULL, 
            0x63852C307E6A5A11ULL, 0xF0BA50452CCDB143ULL, 0x9214F8F04A9C3032ULL, 0x3781F74313EACDFFULL, 
            0x52B3ED934AB2B18CULL, 0x3F2DC513FD302852ULL, 0x45C9D5EA01E445CDULL, 0xD7B9DA70D3902E71ULL, 
            0x68B339F8248C098EULL, 0xC04A246DD83DC2A4ULL, 0xB6FEABDBCA78F469ULL, 0xCD366CD48BF4510DULL, 
            0x73F8196C447AF5A6ULL, 0xB824B0002073A75AULL, 0xEAEAB873813D3000ULL, 0x2C4299B35F5625BDULL, 
            0x8CB1AD25F5D51918ULL, 0x4453E52D345F3EFBULL, 0xFF68120C133028B5ULL, 0x44FA0AAFAB319871ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseGConstants = {
    0xF26C6ADBFCD84FEAULL,
    0xDEA4E7AD238F2B22ULL,
    0xF0EC6C5F6B8332E5ULL,
    0xF26C6ADBFCD84FEAULL,
    0xDEA4E7AD238F2B22ULL,
    0xF0EC6C5F6B8332E5ULL,
    0x62F9F43B64C90680ULL,
    0xE5261C3364C783E9ULL,
    0x0F,
    0xD2,
    0x08,
    0x4C,
    0x30,
    0x2C,
    0xF3,
    0x1F
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseHSalts = {
    {
        {
            0x8145C801C192D54FULL, 0x31114C07C57144F8ULL, 0xC4474C717AE403AEULL, 0xAFB4B7CB704CABA0ULL, 
            0xD3C45767DE28091FULL, 0xA2DCB8D8C09C4F3BULL, 0x26957E2B115CEBE1ULL, 0xDC937429BE2D223BULL, 
            0x68F79EA9C04E99ABULL, 0xC48CB35ED73D4F40ULL, 0x4494082C50B897B9ULL, 0x840F9305575D3789ULL, 
            0x1B911603230719F7ULL, 0x2792D5D6D5C92763ULL, 0x6538E8BBFD4041A4ULL, 0x882948908AC0F5A9ULL, 
            0x0F99293501EB29BEULL, 0xEFFDC65DA6161BACULL, 0xB6EDB16320CD700FULL, 0x29B4D4F24C9115B1ULL, 
            0x04E8EB2561EAD3D8ULL, 0x76E383447B7732BDULL, 0xA871786F276A46CDULL, 0x79FF8D1ABB15931CULL, 
            0x91124AB129B09747ULL, 0x1B7C44A10A834F65ULL, 0x5FB454E27EE64D4CULL, 0x5C65EEEE2AF7525EULL, 
            0x0F6BD03EBA4EE1BDULL, 0x09D7E8B006F47B01ULL, 0xD64A7A39665DA931ULL, 0xB14DC6976F1DD4CDULL
        },
        {
            0x59033FDB071FF3CFULL, 0x173DE330A832CF9CULL, 0x1C40602582B5FB13ULL, 0x3F4D045DD5E4A5D4ULL, 
            0xC5B44C2EE64C086BULL, 0x2BA30FC35C3DFBC6ULL, 0x124A527067DC8C5FULL, 0x0CAAC7D92A3204B8ULL, 
            0xDB7EF6A50400AEF6ULL, 0x4D4D9FDEB7F4DE80ULL, 0x33BFB430DB68E932ULL, 0xCD98FF1E1905268EULL, 
            0x036CFD5F47F94AA6ULL, 0x805A2B8EEE71E179ULL, 0x3CF6754BBBA013DCULL, 0x902786137CBC8DE2ULL, 
            0xC88BC4FAA1CE5090ULL, 0x2DBF6727F1323745ULL, 0x379EE8D1EBDCB13FULL, 0x6A0EFB4161EB981AULL, 
            0x7A69A10225ABF67AULL, 0xBDE1EF06FE824ED6ULL, 0x07F631962C7B9ADCULL, 0x975287C9F29870B3ULL, 
            0x668754F925AE68CFULL, 0x80A5E7C3C7ED762FULL, 0x12EDA0FA6F5251DCULL, 0x255972438A2A852AULL, 
            0x5338056DDE3A59A0ULL, 0x08D99E03279E6472ULL, 0x152756CE30C1F10BULL, 0x559815A87B3B23B0ULL
        },
        {
            0x7C65DC157793DBE3ULL, 0x0838B588CFB79B39ULL, 0x9AE71E380E189A18ULL, 0x6AC5A24676169C1FULL, 
            0xDF9B1C4B27312F9DULL, 0x2FEF25E26B76886DULL, 0x5B62172A291F4CE9ULL, 0x1AC0DE4A00FB621AULL, 
            0x85040093E31F7C66ULL, 0x3EDFF08C830B0C6EULL, 0xF0C6399B4F114507ULL, 0x95207836257D61ABULL, 
            0x1C2292F4160BEC1FULL, 0x9C7C0592D33EC75AULL, 0xC31B233A02785B49ULL, 0x0AA491F09C7705C6ULL, 
            0xB2173A1884E1F0D0ULL, 0xBCC7A9E744D4CB98ULL, 0xF78B7292FE46C859ULL, 0x6A9291371F055565ULL, 
            0x0018379FFCEB388AULL, 0x70DBAB34119969F0ULL, 0x3C5DD37FA51115CEULL, 0xEAE12D9B2E56BD0AULL, 
            0xAAEE91DD0AB37092ULL, 0x3034E5B6934AFA64ULL, 0xB694450387F55862ULL, 0x80052EE832ACE045ULL, 
            0x96E33C00501DE631ULL, 0xEBEDB02279ECD127ULL, 0x2139D5AD222F395EULL, 0x85DDC35492BF7270ULL
        },
        {
            0x7EB2DDFE27C58F45ULL, 0x458AB0216E2D2A41ULL, 0xD433E09744F5E18FULL, 0x8E6EE4149463DAFCULL, 
            0x02A62C09229F966AULL, 0x20AB7C57F8F8D93FULL, 0x033B1508071F847CULL, 0xF01659BB6B541A13ULL, 
            0x7B50AA81C8C96BBCULL, 0x6EE975CF56A643A9ULL, 0x464415AD718C44E1ULL, 0xB27FBA298E8EBC4FULL, 
            0xD594B34C6B3CB232ULL, 0x6231A7B36ACF2D93ULL, 0x59EF4D7B1F7A5A39ULL, 0x19509F5518BA2FDAULL, 
            0x084A203796E78D10ULL, 0x09EBD4CCCB2B64BEULL, 0x834ED09B10600421ULL, 0x6DBD1A7DD9EC04A6ULL, 
            0xB8B0CBCF05AF24FDULL, 0xBF0B3573B0DE4699ULL, 0xEDDEA3C3EC8B87DDULL, 0xC868BA6935007339ULL, 
            0x054330C48E673EE1ULL, 0x95356EA2658EA0ECULL, 0xA2B9E5398FDDCAFCULL, 0x734F6529C4B9217DULL, 
            0xD538C38E995970F3ULL, 0xE66C6F527C939D63ULL, 0x69DDF5201CBCF0F0ULL, 0x62C261C4BB9FBE64ULL
        },
        {
            0x0099C923134A3A2EULL, 0xBB52E00528CA86FAULL, 0xFBC6CA1F08270F39ULL, 0x6F54FF4C172DE8B7ULL, 
            0x6855C749F6031C17ULL, 0x76D87B6833A51C2EULL, 0x5044B0DED69D4E9DULL, 0xE9032870250FB4F0ULL, 
            0x1809B9D9C47043C5ULL, 0xB6FAADF10E583992ULL, 0xD4434E7F16F1A100ULL, 0xAB490922DF31C7D1ULL, 
            0x4A82F03ECB27B9BDULL, 0x884B9AA432C4B132ULL, 0xA816F6CD976E643CULL, 0x40BBEA785A2CE302ULL, 
            0x64C4D52B9E4527A7ULL, 0x65CB4D3D2975284BULL, 0xC5ECAE9EDF3F7BF1ULL, 0x3F2DBDF04E428CBBULL, 
            0x9E62422474C9DA5CULL, 0x1BA7CB4EF3B2E768ULL, 0x2ABE956C1C93CB55ULL, 0xE66949163C02C795ULL, 
            0xDB30902EA22D0574ULL, 0x2E24D6BEBF0337CAULL, 0xF409C53DD7A73FE0ULL, 0x3E89DE152AAA1C8EULL, 
            0xAD522C584DC4A37BULL, 0x4C576A36AF354768ULL, 0x470343A4686974CEULL, 0xBD38AA9C0BFE2ACFULL
        },
        {
            0x88BB035AB7723E23ULL, 0x46DBC47FC2A57C8CULL, 0xBC1E81A42094E88AULL, 0xF68344841E452C9AULL, 
            0x4C983026AE315DC5ULL, 0xD2A4E4081FEF7A0FULL, 0x45BE257D95BF0C8DULL, 0x48798751F1753C38ULL, 
            0x93A968D84A1066CBULL, 0xC84E839465D8BE40ULL, 0xC443260DD7337BC1ULL, 0xAFBF8C456A6C38DBULL, 
            0xDDAD2D26722B2E8CULL, 0x758208C3C35E0B01ULL, 0x4DDF10001CAF75DAULL, 0x359CEBB7F10A78ABULL, 
            0x2767A7BFCA7A8A12ULL, 0xCCC8CB49546DC64EULL, 0x1C17C7F47A0A12DFULL, 0xEB104696A71CAF06ULL, 
            0xED8291FC2E12197BULL, 0x569C2C8DC3FDEA17ULL, 0xB231EF40663CF5F1ULL, 0x73B64879817466B5ULL, 
            0xC7479F3BA18F48AAULL, 0x2A575B523978ACB0ULL, 0x636C04A03F70D8BAULL, 0x9ADCEB241F26C6F0ULL, 
            0x76C346A6C5EA8860ULL, 0x89EEFA60610A9E0DULL, 0x9EC73B56E2C873CFULL, 0xC025EE1C72978F93ULL
        }
    },
    {
        {
            0x2870C2E677650033ULL, 0x8EE6BE4F05F96725ULL, 0x172E592EE8B67F57ULL, 0xB97F68BDC623DA90ULL, 
            0xE117D00182489A2EULL, 0x2BA7D8A501534BE9ULL, 0x9518AA7FEFEA0F13ULL, 0xCBE3155F2E17CEF2ULL, 
            0x4A0859780A80C1A5ULL, 0x650748F6D848C843ULL, 0xF446C30761ECE41CULL, 0xDB0C24E026FA5782ULL, 
            0xAC70AB8008012F82ULL, 0xC15C499F56AD0E1BULL, 0x471F7B0982030A9EULL, 0x47E9CD958B646616ULL, 
            0xA7EB58BF6B325F6BULL, 0x4FDE98C86CB92F5AULL, 0x05368D1FE8ECA23BULL, 0xE6CA4183305E9417ULL, 
            0x7F6D53027C918BFCULL, 0x32F496441B12EC30ULL, 0x823B1BC17E9F7614ULL, 0x3B48C2570AF19722ULL, 
            0x218FB184BE1CB4EDULL, 0xFC9B2F16059D9FC9ULL, 0xA3C62DF07C9F66F0ULL, 0x8BE082D2B133559CULL, 
            0x1D9E8320AA5DEC4CULL, 0x3FE40A4267BBC29CULL, 0x51D8626EB6EE179FULL, 0x5DCCF1CFDDA05EBBULL
        },
        {
            0x1C54E4D0921BD645ULL, 0xC8402F9E0005634AULL, 0xF6DB5061B6B04EE5ULL, 0x751D6CD733FC9001ULL, 
            0x37FA797211F27F01ULL, 0x01C871710AF4AEB7ULL, 0x9A76BC6F62034C2FULL, 0xA7E457B675DB6C5BULL, 
            0xBF1CD14CC1E58D92ULL, 0xF37C3B9D918ED025ULL, 0x012D069B15A55B62ULL, 0xA50F74016851C127ULL, 
            0x40B5DD5AED551A94ULL, 0x276407B7BBC72A7CULL, 0x41D42ED263DD008AULL, 0x136BA4EBE348A861ULL, 
            0x6067B653F658DCCCULL, 0x5C448E19738A62D9ULL, 0x40DED8D2FBCCE113ULL, 0x099DD639FEAC5684ULL, 
            0xC10F2AF5E38A9DEFULL, 0xC6CA60A58B3DC8EFULL, 0xC2C256C21E1A6AE0ULL, 0xFAB85DA81D334BE8ULL, 
            0x669126E338BEDA6CULL, 0xA5B63815CA70BBCDULL, 0xEC09D62D3BF6CFD0ULL, 0xA22835492C300C47ULL, 
            0xC8D05609444F9B12ULL, 0x626CF248119C89A8ULL, 0xA4A5E35BCE366BDBULL, 0xAE139D55F74BE298ULL
        },
        {
            0xFB2A80C06269311BULL, 0xAC2608ECC06FEC51ULL, 0x8763E506B2356A64ULL, 0xD12249F9049DAB3DULL, 
            0x7BCCDBC35C1344FCULL, 0x0CC9F5B3DC54D452ULL, 0x969CE00A20C23317ULL, 0x2CD637D982666EFDULL, 
            0xBB3822B47EC41C1DULL, 0xAECC26E60CD683FBULL, 0x51B4B9B74F71BA37ULL, 0x4FB957C8B8DC396BULL, 
            0x7326FED9562DC5CBULL, 0x43F0DF5B5CEB326EULL, 0xF4A2D35AA8ABBEFDULL, 0x93C5BDD3EBC9F6E0ULL, 
            0xE3BECDDDC3D26E18ULL, 0xA8220B6E653D1745ULL, 0xCA8B2373048153B7ULL, 0x057DE0B782E95821ULL, 
            0x8AB438AB7968AF7FULL, 0xE0838A68D24C8BE6ULL, 0xF7F233BC566048BDULL, 0x99719FC42F917E2AULL, 
            0x841DC97060ADBC87ULL, 0x035931A27A4086D8ULL, 0xCAD227CE81AD05B0ULL, 0xB32035F87E8A63A9ULL, 
            0x3CA6E505BC79F43AULL, 0x5515D9AD7772714FULL, 0xFDD38E96DC6A656FULL, 0xE613C366E81CBB97ULL
        },
        {
            0x754BB3EB8DFF78D9ULL, 0xB4FB3CF06377AF7AULL, 0xAEB84B7D5A5D812EULL, 0x7FB2B97755EE1F2DULL, 
            0xB05917C34F6350DDULL, 0x5D40D5F31352ECE7ULL, 0x1D099DE919F78E9FULL, 0x180B776AE3006F14ULL, 
            0xF589379B594FAE56ULL, 0xC435BFFF92C547D1ULL, 0x1466D10A2F18A11EULL, 0x517AEAFD5ABFC776ULL, 
            0x8D4AF250F6A2BECFULL, 0x64388FE7B7895544ULL, 0x37CEBF346B3E0BD0ULL, 0xE52AA97544E8EBE3ULL, 
            0x6E073A6E5AD9C000ULL, 0x8FCC874678640A13ULL, 0xDA0DF5D9D7517947ULL, 0xBE449E32765B07B5ULL, 
            0xA53EE1A37ABA3C93ULL, 0xA3FCFD39A5B0D492ULL, 0x02556627852AC438ULL, 0x6F510696B2EAE8C3ULL, 
            0x0D488B09C19AB484ULL, 0x5E37C1A91071AE73ULL, 0x6E6CC82F0AD1CE66ULL, 0xF901085E7CEB7202ULL, 
            0x8B0D70C17918B543ULL, 0xC596B89352467DDEULL, 0x2DFDCB6DC18F59A3ULL, 0xF194BD3AFDA54A5BULL
        },
        {
            0x888FBA6838AD95FCULL, 0x0D5159022A9D12DDULL, 0x9D34D6F6566872ACULL, 0xC512611F5C029868ULL, 
            0x7600CFDA6DEBE5A3ULL, 0xC6082583DB6455BDULL, 0x5AFC52398E34401BULL, 0x6189CEC2CA848FEDULL, 
            0x681A9BC0E20144C5ULL, 0x93B050039A74EB42ULL, 0xE9A034BF464F38ECULL, 0xDCD8BCAAA0E2A7D1ULL, 
            0x6A6E1FFB66897C8AULL, 0x34AAC0ED0C6DC8A8ULL, 0xD8788741B00DD396ULL, 0x73A8DCB281644239ULL, 
            0x888AD25C9FC4C480ULL, 0x3A652C5CEDAB4628ULL, 0x6F2297AAD4CA8CEDULL, 0xA286EA8EAD044FD8ULL, 
            0x52DBA22E7C5C18F4ULL, 0x2DF77E6651A4F817ULL, 0x2438B01FCFFAC003ULL, 0x0501B27B1D1244FDULL, 
            0x3CC281F1F227377FULL, 0xB08E37F64867E036ULL, 0xD0C38B5FF0BC6FFCULL, 0xAF510D3BE39F6B88ULL, 
            0xE3F9348CCFFD43BBULL, 0xF73FBA5BE31A4BC9ULL, 0x2CC92D6D0CD05FBCULL, 0x158EB946A19FEB3CULL
        },
        {
            0x890C0E1EB867B563ULL, 0x6F1141D624C2E3E6ULL, 0x0C2CA94CCFDEE440ULL, 0x26ED46D9CBCEDB81ULL, 
            0xF15EBA59E8F9747DULL, 0x7B0A83A783B97450ULL, 0x6A0B59049556A0CEULL, 0x7FF1BBE2973C2503ULL, 
            0xE289868226E09E12ULL, 0x89AADC281AEB08ADULL, 0x27FE11C182A6087EULL, 0xBAA22D6512A77B54ULL, 
            0xF73E6612A089F7F5ULL, 0xFB13F3AE2DE379DFULL, 0x0D684CE3F9465485ULL, 0xD58E9B5725D99859ULL, 
            0xED4187C066941AE5ULL, 0xE872FD1B588BCA41ULL, 0xA646F2AEDDE28850ULL, 0x7ACEA5297EF01BADULL, 
            0x21B8417C79109CA5ULL, 0x1ADE40C6DEBB6B03ULL, 0xE50FD2771BBCD17FULL, 0xEB21226C01922BABULL, 
            0x8F9489642E320C91ULL, 0x929656911406D423ULL, 0xB2EAFC1530D889A5ULL, 0xD5CD89923FBC48EBULL, 
            0xE46B7B96EA235B5CULL, 0xA1754EB230AD3FC0ULL, 0x8CC8F92017979E25ULL, 0xD21CBDE6399F7530ULL
        }
    },
    {
        {
            0xC2077F0EDF0845A0ULL, 0x57B191309BD39683ULL, 0x8F1EF9A416CDF8B0ULL, 0xC3CC1F7B877E6B77ULL, 
            0x81669532DB6C3707ULL, 0x2E9971DE9B7D2291ULL, 0x25C6F18A29B8F80CULL, 0xDDFCF9A2333DC616ULL, 
            0x389BC0D3FC99E3F4ULL, 0x5383F75FD97F3664ULL, 0x7140FF75014E6C67ULL, 0x4BB0F12A31481D99ULL, 
            0xA6B0F093E9E746B2ULL, 0xE0FE9653C877195AULL, 0xFB464A1B18B41E57ULL, 0x4561BAEF442D0054ULL, 
            0x0ABA2F3899D858A4ULL, 0x34816274AFFEB62EULL, 0xFF60C45FAC87280EULL, 0xCCD9F85C68668358ULL, 
            0x2A05C8A58145C511ULL, 0xF44992DC08C005A9ULL, 0x13F0542BD547F6ACULL, 0x9B64ED91F97F76C6ULL, 
            0x708F6245E86A8037ULL, 0x899DD8BC803683FEULL, 0x9D55B8B7598C514BULL, 0x98C5D664F262A4DBULL, 
            0x454140795EB01233ULL, 0x22E608526C783D02ULL, 0x4542C25075424BE4ULL, 0x9F2EE55B1B08B6D5ULL
        },
        {
            0x0C5223214DB39B5FULL, 0x7A8C73324C90010CULL, 0xAA072B2C9D6BA197ULL, 0x866EC63E8BD4CD46ULL, 
            0x6220541350BD2194ULL, 0xF36E15581E0EC8D6ULL, 0x99D4B6FBB8FDA439ULL, 0xBCBEB6D1B3F5EB2BULL, 
            0x1AD784ACDE41CDE6ULL, 0x1119550175D83EA6ULL, 0x257CB7D00E20BB75ULL, 0x6B4FA60ADBA2AF37ULL, 
            0x93819AF99A885B05ULL, 0x9AB6B201AD7F905CULL, 0x013B094C326F8FB1ULL, 0x65D34BB41C0158AAULL, 
            0x782A3048EF536B2DULL, 0x4EEE7F7A2DD1A2B2ULL, 0xB0C31DE146CE9338ULL, 0x62FEC9C05E7CB742ULL, 
            0x5B351BC5C419127CULL, 0x10A8DA29040345BAULL, 0xBE8119F2E1F223C0ULL, 0xA8C373AAA2EF1310ULL, 
            0x968AB5FB73C51218ULL, 0xFACC4C0A4C55B990ULL, 0x372C835CBD3F75DCULL, 0xA0C0EC28AB5E1E48ULL, 
            0xB1EF156BB810F4B9ULL, 0xB16C606C8BD0A2D3ULL, 0xD3FE363593C09505ULL, 0xE9B95F3FE2FAEDFEULL
        },
        {
            0x802D717090EFF6BCULL, 0xCB9173308C4F76E1ULL, 0x2F2F9EC74CB164C1ULL, 0x514D74AEF19BEFF7ULL, 
            0xB3BCB31A80FFEEBFULL, 0x40C829D079ADCA3AULL, 0x9EE558BA2B17FEF8ULL, 0xE299D2907D11E6B5ULL, 
            0x1A423D2B62CBDE0EULL, 0x20C9E71E36EC94C7ULL, 0x926E9EA01D84AAE2ULL, 0x3FDCFA8BA0C559B3ULL, 
            0xB90DCFCA8CE23AABULL, 0xA882FBD9EC64B5BCULL, 0x6C9D1FE8BEF41591ULL, 0x4B1FA436A66D7AE2ULL, 
            0xD4F4EB7F44283786ULL, 0x1CB229FB305F7882ULL, 0xBFE3E8356F9DE603ULL, 0x36E5EB1CDFC1BC5CULL, 
            0x0E82C81077B5AE70ULL, 0x90FB6863AE97BEEAULL, 0x117F8119CFFA92D7ULL, 0x9B84E235268DD398ULL, 
            0x8DE70720B4FB6923ULL, 0x1E94334B2BCE5E7CULL, 0x8FA07F388148C09EULL, 0xB6798C8B66095AD2ULL, 
            0x94157D5DA069A0C5ULL, 0x0926A7CB7102A4A9ULL, 0x8AC59106F11AF92FULL, 0x2D677EA3E1F1A3A3ULL
        },
        {
            0x0DCE87D64B3D5121ULL, 0x227F5C18F9194C1DULL, 0x903528FB660B2466ULL, 0x7E2702E3013CCFE8ULL, 
            0x0C574068426F51F7ULL, 0x7D03A766434692D1ULL, 0xE812889DBEA63369ULL, 0x6DE5F42A176F2ADEULL, 
            0xEA175BD0B7B41110ULL, 0xB8FB1CC3857858D4ULL, 0x5C8EC01850F4A8C3ULL, 0x7154D29BF6CB0299ULL, 
            0xACCC3A41591ED27BULL, 0x4B9302A48191AE32ULL, 0x1B4EC2BDBBD6D807ULL, 0xB0CDA932CB4C9681ULL, 
            0xBFBAFCB9E96805A2ULL, 0x9AB6516154C8D07DULL, 0x3112143DCAFC8A62ULL, 0xA83BA252FECFB666ULL, 
            0x41AB12A027BF1B09ULL, 0x4A1B6E6F79842D94ULL, 0x61741E52D14C6240ULL, 0xF0257A91023E64BCULL, 
            0xB418A6C009F64E0EULL, 0xDA6AAEFD32C6B4D6ULL, 0x0D2D596DC2EDD937ULL, 0x30BEE48B10AB0CE5ULL, 
            0x6BD83D832FF5602FULL, 0x35C73AAE1560636FULL, 0xA65559A51B5AA43DULL, 0xDFE8AB7896A24DEDULL
        },
        {
            0xDB91C903920222D3ULL, 0x8FA5B9C7FDFB1A96ULL, 0x5373AEC4F19606D4ULL, 0xA63A04F472A2C7F0ULL, 
            0x7BB61DE974D17E71ULL, 0xBB498E9D906A66F9ULL, 0x157B3FE72D5DBE67ULL, 0x52586E4599C4254FULL, 
            0x55875A9C008CF66AULL, 0x24DF18DC546B6F94ULL, 0x05AD5795F9BCA516ULL, 0xE010B0D6BA4ABA7AULL, 
            0xCAB894B3D8554A39ULL, 0xE1CCC34EFEDEB865ULL, 0x29FCFF93F0D16A6DULL, 0x447CB7B799A9D156ULL, 
            0xAAB6278DC4CD5D9FULL, 0x454F02C6A78600BFULL, 0x758821371C316E6AULL, 0x0EDD28814CC938BCULL, 
            0xBEC2E392BC8E2FB4ULL, 0x4C7E510456FC6CBCULL, 0x433FCB89A537F583ULL, 0x6675F74C42E2E0B3ULL, 
            0xEDAF487C6EB4A28CULL, 0xB0BC0EE2E887D061ULL, 0xF1B25358CA5C7FA1ULL, 0x2BE8836971A9768BULL, 
            0xE1A553A2D010A9C1ULL, 0x0EE38EF960E47A5CULL, 0xC89D781EAF8DEEF7ULL, 0x9A3B7D99B7D50523ULL
        },
        {
            0x9C5FB6AF598436CDULL, 0x5A3E69F71A5948D8ULL, 0xEC9DA36CFDC9DC5AULL, 0xE016C65A27515DEEULL, 
            0x74F4F37ED8BE6E89ULL, 0x4F5F2DF8FA59EA21ULL, 0x18F2B0896770BF70ULL, 0xC996D63085C67C07ULL, 
            0xA1BE69AD8DC9B26BULL, 0x67F96AF1E05669A6ULL, 0xD101E8CEF9223442ULL, 0x2B3E5C4D3B377799ULL, 
            0xBE344B62C9CF05ECULL, 0x2F0FA3181AB607A5ULL, 0x515B15B38839C2FFULL, 0xC06AE5025BEBB176ULL, 
            0x0AA2108A95B7028DULL, 0xE2B560CB5B8BBA01ULL, 0x2EFBC66815B3B635ULL, 0x09756273E89B090DULL, 
            0x71AAF100B0BDC715ULL, 0x45532C18EA4CDB57ULL, 0xE3529B4828782EC3ULL, 0x41C12A071A65DD17ULL, 
            0xD82C23DC0FB2E53FULL, 0xFA21D1A6B9250A4CULL, 0xEDA9479642F5C232ULL, 0x75DC60B8B971CEF1ULL, 
            0xEA31004300BACCE7ULL, 0x4821F40307A4C6D4ULL, 0x4481345A5D7F811EULL, 0x2530A3B0FCF1B984ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseHConstants = {
    0xD3F2119A516C832FULL,
    0xDCC666347A31C522ULL,
    0x236C9968A86D946AULL,
    0xD3F2119A516C832FULL,
    0xDCC666347A31C522ULL,
    0x236C9968A86D946AULL,
    0xD4FA9F4BC11DE40AULL,
    0xEEBC7B2DDA8AB7F5ULL,
    0x97,
    0x64,
    0xA1,
    0x59,
    0xFF,
    0x21,
    0x93,
    0x94
};

