#include "TwistExpander_WaterPolo.hpp"
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

TwistExpander_WaterPolo::TwistExpander_WaterPolo()
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

void TwistExpander_WaterPolo::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x8883253C7C801D29ULL; std::uint64_t aIngress = 0xDFD73309E4C713B4ULL; std::uint64_t aCarry = 0x9A1DA58FE1CA4154ULL;

    std::uint64_t aWandererA = 0xA5D6FC431F177B66ULL; std::uint64_t aWandererB = 0xF66F87DC0FB1D109ULL; std::uint64_t aWandererC = 0xF400DDF8D249FFF1ULL; std::uint64_t aWandererD = 0xBFAA84705780F8D9ULL;
    std::uint64_t aWandererE = 0xD0A8A039760A1A8CULL; std::uint64_t aWandererF = 0xE9EC3FB468B7A773ULL; std::uint64_t aWandererG = 0x99752C136A1AC2CFULL; std::uint64_t aWandererH = 0xB433CB35A3AC805AULL;
    std::uint64_t aWandererI = 0x8AA669D41C5A71C7ULL; std::uint64_t aWandererJ = 0xEC2948F2B716B2DEULL; std::uint64_t aWandererK = 0xBBE41118FBAFD7E5ULL;

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
        aPrevious = 10011821904759668453U;
        aCarry = 15332513810597446816U;
        aWandererA = 12958252880427708534U;
        aWandererB = 9529454421464650915U;
        aWandererC = 13099526473344216867U;
        aWandererD = 16593970494677440198U;
        aWandererE = 12516160394143103754U;
        aWandererF = 10538181639443166549U;
        aWandererG = 14501055429418186889U;
        aWandererH = 17966802972227950459U;
        aWandererI = 9770584322062931972U;
        aWandererJ = 13630999161366465929U;
        aWandererK = 16765553146145302866U;
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
    TwistExpander_WaterPolo_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_WaterPolo::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xD3F0C21D636CEDBEULL; std::uint64_t aIngress = 0xAFCBB1FFD4DACCAFULL; std::uint64_t aCarry = 0x8D47C2CAB83A4468ULL;

    std::uint64_t aWandererA = 0x863E3B1E63F9179BULL; std::uint64_t aWandererB = 0xABBE85EEE78F0462ULL; std::uint64_t aWandererC = 0xD762F12441865DF2ULL; std::uint64_t aWandererD = 0xE3D78ECB6B1A6568ULL;
    std::uint64_t aWandererE = 0x9854875F6680C16AULL; std::uint64_t aWandererF = 0xA67B982724C70843ULL; std::uint64_t aWandererG = 0xCE5278C250B8B374ULL; std::uint64_t aWandererH = 0xB7DBBBB6FE06C20DULL;
    std::uint64_t aWandererI = 0xAB2F82A678460BB7ULL; std::uint64_t aWandererJ = 0x9FAC0323C93BF088ULL; std::uint64_t aWandererK = 0xA4992DE72E68FBEEULL;

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
        aPrevious = 17167751511199791876U;
        aCarry = 16969725367878222090U;
        aWandererA = 16871041084709164582U;
        aWandererB = 17749689814247671099U;
        aWandererC = 15308338702970166035U;
        aWandererD = 11472209384643583656U;
        aWandererE = 9406023885116913488U;
        aWandererF = 12360699389409444330U;
        aWandererG = 12364344005724330279U;
        aWandererH = 12179998960698618179U;
        aWandererI = 18300734149953351997U;
        aWandererJ = 16434433905670151639U;
        aWandererK = 16296298004926608127U;
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
    TwistExpander_WaterPolo_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_WaterPolo::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA1C6A624F2A31744ULL;
    std::uint64_t aIngress = 0xCF7901776A6E206AULL;
    std::uint64_t aCarry = 0xF03374A59AAC549CULL;

    std::uint64_t aWandererA = 0xEA9B71A2964AAA30ULL;
    std::uint64_t aWandererB = 0xE3BBCB977D942DE7ULL;
    std::uint64_t aWandererC = 0xF8DD605FA08771DBULL;
    std::uint64_t aWandererD = 0x8BD66C60670E7885ULL;
    std::uint64_t aWandererE = 0xE5382216B50C3FF0ULL;
    std::uint64_t aWandererF = 0x8F5E2F1E83AF8013ULL;
    std::uint64_t aWandererG = 0xB69556F91797EA77ULL;
    std::uint64_t aWandererH = 0x97DB55C322795E58ULL;
    std::uint64_t aWandererI = 0xAC76C80751196EF2ULL;
    std::uint64_t aWandererJ = 0xB5A8AF612733B5D0ULL;
    std::uint64_t aWandererK = 0xECD71A9DD6DD5012ULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC, 1);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB, 3);
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
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneH);
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD, 6);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB, 7);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneF);
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
    TwistExpander_WaterPolo_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_WaterPolo::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_WaterPolo::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAC46769D05172F04ULL; std::uint64_t aIngress = 0xA0A6AC9D9D1B1493ULL; std::uint64_t aCarry = 0xF51134307C497364ULL;

    std::uint64_t aWandererA = 0xC471F0FE63C37EDDULL; std::uint64_t aWandererB = 0x913E308055918E7FULL; std::uint64_t aWandererC = 0xB96B6EC7B30B35D9ULL; std::uint64_t aWandererD = 0x94F797F5B939C693ULL;
    std::uint64_t aWandererE = 0xE2C26A7C6272ED70ULL; std::uint64_t aWandererF = 0x9B69EA8A9F4ADD46ULL; std::uint64_t aWandererG = 0xD05E872F52FF756BULL; std::uint64_t aWandererH = 0xD3DC39AC0ADD782EULL;
    std::uint64_t aWandererI = 0x91FCAC3D9A5BB8E6ULL; std::uint64_t aWandererJ = 0xE65C5B96C1196A72ULL; std::uint64_t aWandererK = 0x893DA0D4B7778FCFULL;

    // [seed]
    {
        aPrevious = 12913225063361614411U;
        aCarry = 17738511636160793847U;
        aWandererA = 12943845604289528018U;
        aWandererB = 15049524500019837304U;
        aWandererC = 11961346149339473729U;
        aWandererD = 13240693855302408140U;
        aWandererE = 12513048374733724453U;
        aWandererF = 9960276461167821891U;
        aWandererG = 11304910996846450387U;
        aWandererH = 18097519924227770579U;
        aWandererI = 13087940778073850667U;
        aWandererJ = 9696439961493869190U;
        aWandererK = 15115107097739446957U;
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
    TwistExpander_WaterPolo_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_WaterPolo_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_WaterPolo_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_WaterPolo::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 1, 2 with offsets 8U, 4492U, 7837U, 6967U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4492U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7837U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6967U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 2, 1 with offsets 7470U, 1088U, 2826U, 3990U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7470U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1088U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2826U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3990U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 0, 3 with offsets 4171U, 4603U, 6968U, 3306U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4171U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4603U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6968U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3306U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 3, 0 with offsets 7798U, 2064U, 3411U, 4062U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7798U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2064U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3411U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4062U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 2, 3 with offsets 2039U, 550U, 708U, 364U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 550U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 708U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 364U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 0, 2, 1 with offsets 410U, 1317U, 87U, 159U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 410U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1317U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 87U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 159U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 1, 0, 2 with offsets 1237U, 728U, 1080U, 1400U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1237U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 728U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1080U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1400U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 3, 0, 1 with offsets 205U, 1651U, 2024U, 1493U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1651U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2024U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1493U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1904U, 784U, 747U, 1993U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1904U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 784U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 747U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1993U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_WaterPolo::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 3 with offsets 2400U, 2712U, 2189U, 2351U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2400U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2712U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2189U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2351U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 0 with offsets 3392U, 135U, 1569U, 601U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3392U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 135U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1569U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 601U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 2, 2 with offsets 7582U, 3442U, 2664U, 3624U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7582U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3442U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2664U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3624U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 3, 1 with offsets 257U, 2619U, 5189U, 625U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 257U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2619U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5189U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 625U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 1137U, 1579U, 1507U, 2858U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1137U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1579U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 1507U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2858U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 447U, 1273U, 1298U, 1710U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 447U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1273U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1298U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1710U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1234U, 1780U, 407U, 458U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1234U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 407U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 458U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 318U, 1233U, 1780U, 84U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1233U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 84U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 363U, 203U, 78U, 369U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 203U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 78U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 369U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 1, 2 [0..<W_KEY]
        // offsets: 222U, 1745U, 1343U, 64U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 222U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1745U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1343U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 64U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseASalts = {
    {
        {
            0xE34ADE4D152BB4B4ULL, 0x2A0DCD716715D21DULL, 0x0B039A8859CEA79CULL, 0x2398E01D97ABF8A0ULL, 
            0x45BEB90AD9419A7DULL, 0xEDCAE3D20E5A5844ULL, 0x452FECE03B31E66DULL, 0x7368FE40606F724DULL, 
            0x54357732C07B8FD7ULL, 0xC0368B48C4E1C662ULL, 0x58616EADF1317F46ULL, 0x9B9D584F9FB8CDEBULL, 
            0x83EB7DCD8BFE25EDULL, 0xBAD4B7BB97A4C431ULL, 0x673A2AB2713C3658ULL, 0x8C07045436075212ULL, 
            0xCDD1F747C505E321ULL, 0x4C58921E3E087E27ULL, 0xE39DACD9174F5B73ULL, 0x9C5754EF15855C6AULL, 
            0xBC46D5F7EB562A6AULL, 0x5B6FDCF7AF49A30DULL, 0xFC324B446DD91D39ULL, 0xCC833CF49F989C87ULL, 
            0xF203CE005BA3B4A1ULL, 0xFB78C8CFBBF6A9C7ULL, 0x078B6BE0C85572E3ULL, 0xEDEE151520CF8BD8ULL, 
            0x559E86075ED9882FULL, 0x681743AEA0647CB6ULL, 0x604F738D2F187D1CULL, 0x7E7838BDCC9CC982ULL
        },
        {
            0xD247ED76564409CEULL, 0xA4DACD0579AAD377ULL, 0x5F3B7CBD5C795325ULL, 0x2DDE4A24BBBD9D54ULL, 
            0xE8B51F54846E7AE7ULL, 0x21F464799FB2F9A0ULL, 0x326CE7AEE1FB22C6ULL, 0xBCE5E45C1F07BC86ULL, 
            0xB1A9CA007B0B950EULL, 0x4F3EA9B0B6B3A1EFULL, 0xE4AE8EDD81A043F0ULL, 0x277871C509E8E8EFULL, 
            0xF1D935A6A3A14BD8ULL, 0xF4E5F2304E96F700ULL, 0xA3CEA287558DE492ULL, 0x2CFE8DA83C3EF05AULL, 
            0x4ECA02CF78283E5AULL, 0x654FBF63C3FE790CULL, 0xF9BC33DF6E97C452ULL, 0x93CB0D363C34B548ULL, 
            0x0628274AD232A17BULL, 0x93163F9E52E5A697ULL, 0xD9859F014E7B4AD7ULL, 0xA80EE83B81DCFCA9ULL, 
            0xD106054CBCE817D5ULL, 0xF46B0787870ACDEDULL, 0x1B1B9AE4EF9B2B74ULL, 0x58955BB0340A8F4EULL, 
            0x4602641D607F7BD7ULL, 0x31D6C688CA45CD69ULL, 0xB012181324A02F4EULL, 0xA0B5B928298099CBULL
        },
        {
            0x6CDC111FF77EECADULL, 0xAE37998CA01B1C99ULL, 0x8F3CF7FB7B0A24C0ULL, 0x1238A2A0AEBD9F7CULL, 
            0xF781C5478C875E3AULL, 0xFCC1BA48ED32A763ULL, 0x114235C61E4E42B7ULL, 0xC49C34A6E7FB905DULL, 
            0xCD8296F0DDC7E95EULL, 0x028F1D091FCB9721ULL, 0x3DF166D4428C61E7ULL, 0x2C346645D664DDF1ULL, 
            0xB2C244D1306FEA95ULL, 0xC44059AD65F909C7ULL, 0x9F53C3FF947D2ECFULL, 0x865AEAD030C97651ULL, 
            0x136021BB91B5C788ULL, 0xC381DB2ECD5C3ABAULL, 0x2C4125B3CE8EE8CDULL, 0x89F113DBD1346B52ULL, 
            0xA1E847AD731B3ECEULL, 0x1568E6E682AD52EDULL, 0x622952BDDC328DADULL, 0xCCF3D899D53F1C4FULL, 
            0x01111D358B812EA0ULL, 0xB1147ADAE0710A00ULL, 0xAFF41FF8D58B1F26ULL, 0xE198D3B63205BB67ULL, 
            0xA555E312298C4838ULL, 0x457AE278409B292EULL, 0x23B388F4E82175A4ULL, 0x9E0D9743367F3FFCULL
        },
        {
            0xAECF0E2CA39EF5ACULL, 0xE3407E9DE4912864ULL, 0x84C8B24DCC475018ULL, 0x0348776C22B2A20AULL, 
            0x371212A285C651B0ULL, 0xFB8CCDD0CCC41B9DULL, 0x97737EDAC4A35882ULL, 0xFC6F5A5D9B4799FFULL, 
            0x150D9DBC90C9ACAEULL, 0xC24C4DB5D6DC95EEULL, 0x4F111BE1C7E526AEULL, 0xEB434D5A026FFBF3ULL, 
            0xE227F79B5825E5E9ULL, 0xAD73B51B40BAB5A4ULL, 0x702C470BA53CA2CEULL, 0x1EAA9F70B65DA6B7ULL, 
            0x901517D4DA39AF6FULL, 0x26A92CC6AA52229DULL, 0x3EB75F3F7712C358ULL, 0xE241958CC3FE0E24ULL, 
            0x0FFD000D51BAF4FFULL, 0x8A8AD85CBE801CF8ULL, 0x0531E331DBD680C7ULL, 0x1766579F269BA15EULL, 
            0xCDEBD183D24FCC7DULL, 0xF298C60B6414DDA3ULL, 0x88792424C5479F29ULL, 0x824CE3B4B75D472FULL, 
            0x50E5C4317704072BULL, 0x1D7E33469499778EULL, 0x20972ACB4035B12AULL, 0x8EFE66BEB43F7EC5ULL
        },
        {
            0xFE69D38BB187C123ULL, 0x1A3F938FC5D03FD5ULL, 0x983CCD83A6685456ULL, 0xA56381A87B75758CULL, 
            0xFAD7CA44817F8757ULL, 0x02812BFC2D48B16DULL, 0xF0E8CDA2F3AFF7E6ULL, 0xDAF5E39D4D871F01ULL, 
            0x7A588D0C97941480ULL, 0x57C042AB3F1AEB2CULL, 0x84FC603E589A9FC4ULL, 0xE7AAD9AB76064041ULL, 
            0xA6034E26C2E1037FULL, 0x3BF73341334A6EBEULL, 0x1ED2597925E3E624ULL, 0xB5AABFE753F6205BULL, 
            0x73720708C27792C7ULL, 0xE96819C9C02AE86EULL, 0x8513BE916179E1BDULL, 0x725D2293A44DF627ULL, 
            0xD09A5F61965325E7ULL, 0x1E304C62AD12DEE1ULL, 0x88B36ADE615A80CBULL, 0xE110D160F4BF164BULL, 
            0xEDCDE6037D408F18ULL, 0xBF2362862A037A93ULL, 0xBD1DCC988B1DED69ULL, 0xBC2716E6A751A4C7ULL, 
            0x58A6D9F65F784945ULL, 0x6CAC03C4AF466D31ULL, 0x274A2B143F6F57A3ULL, 0x43F9925F2B79BED7ULL
        },
        {
            0xE4111B823B37FF6CULL, 0x46B04211E1BAB395ULL, 0xEC9ADA76DC7B3E84ULL, 0xA897CA29A3AE16F4ULL, 
            0x511A945FB2F952CBULL, 0xD850B2B95BD016ECULL, 0x756763B4742D489EULL, 0xA91A046440D46F25ULL, 
            0xF6C0F9FEA27A811DULL, 0x3C87492CEFB09960ULL, 0x42689DA372096573ULL, 0x9DEA927D243D3C18ULL, 
            0x2DDA3847BBCE19B0ULL, 0x92FEC54863775213ULL, 0x0D50EB2528F6E42DULL, 0x26C16749A0FF7A1CULL, 
            0x4ED0FE2BE091BC3DULL, 0xC9E42AFB89A9A9DAULL, 0x8E6A891E972004ECULL, 0xE79CBD2D08DA9E7EULL, 
            0x244EAD9104A68578ULL, 0x6EC153973BA57574ULL, 0x60D9DB4955212151ULL, 0x4294D431681B85EDULL, 
            0x7EBCB645F41F4B36ULL, 0x0ECFDC7CF2258EC9ULL, 0x9B4A1AC58886AE6BULL, 0x102603D0F5A72249ULL, 
            0x43E50930D7395833ULL, 0xA28A493C4F746BE7ULL, 0x689337210822B5E0ULL, 0xF522040FFCAD8751ULL
        }
    },
    {
        {
            0xB288AD643A097E40ULL, 0x3AB6F1DED009C899ULL, 0xB56BAACF5702E840ULL, 0x6DCAFE913AB58B7EULL, 
            0x123010AE82718A03ULL, 0xFE5F5BAA61BD654BULL, 0x8C536C9E38DBDB19ULL, 0x7F46408CDB2104F2ULL, 
            0x9190AE404F92C7A5ULL, 0x1E2008ED0D34C939ULL, 0x5339CF04A3BBF86AULL, 0x7B1A481C40979F76ULL, 
            0xB4C8D8F4F005EA72ULL, 0x72BF64A4F1153AE5ULL, 0x3151C60EFF2C9F45ULL, 0x454489E853D31A74ULL, 
            0x8AF31A2F98D797B2ULL, 0x93489C2124612547ULL, 0x816BBF33AD30C47EULL, 0x5EB2AF3376D2AFEEULL, 
            0xD1131789D792C1F8ULL, 0x1DB655FDE504D12DULL, 0x909E245BD424F64AULL, 0x839776F56D2EB499ULL, 
            0x630879834B6704F8ULL, 0x467679838D73DF96ULL, 0xC9DE0006816AD519ULL, 0xA6E356AB44319B8BULL, 
            0x312251D5D8E742A9ULL, 0xE3229ADB96ABB866ULL, 0x752D80632DB58966ULL, 0x34DEB39B36A14FCEULL
        },
        {
            0x2703EFDBCB72F9B7ULL, 0xA569714CAEF77DEDULL, 0x43334716585A3FF9ULL, 0xFE7F08F630C34974ULL, 
            0x568283BFAEEA5A1BULL, 0x5519B12428699686ULL, 0xCCD9D34522DEB5CDULL, 0xB165731A425D97CBULL, 
            0x5E3543E3BE3E2ABEULL, 0xC4BF84E4FC5E3DB5ULL, 0x18BFD51AFFF57C0CULL, 0x938488D5D3111F6DULL, 
            0x2E27AB55F50E2F5AULL, 0xA342171B3E833623ULL, 0xDF5E41266157F131ULL, 0x3909CBA707393CACULL, 
            0x1BE910AC8DBDD0CAULL, 0x345B759CFD53BCB9ULL, 0x8F74CBDD7F5ECA49ULL, 0x6811D82284591CBAULL, 
            0xC19A13F8C6438B9EULL, 0xA9F0C8D448EA6C4DULL, 0x9A1056FEAFDD241AULL, 0x0C985AA526472DE2ULL, 
            0xFAD018D63762F59BULL, 0x09BF578050D4DB8EULL, 0xD5F29CE0E7C7CDA1ULL, 0x6D8A573E9DAAB088ULL, 
            0xF887666C3FE12258ULL, 0xCA411418AA62B7E6ULL, 0xBA9DC0F4B2CF59C8ULL, 0x5E776F34035C7091ULL
        },
        {
            0x445B7F7B04E623FCULL, 0xF35CDA92BB9243F7ULL, 0x7309CEFE13BD9F84ULL, 0xD66DB88C245920A4ULL, 
            0xF8AA35C548E3D980ULL, 0x4C35DF40128CF6B7ULL, 0x41FA657B93737CAEULL, 0xF894DB357B6505F3ULL, 
            0x618FED25C9537E90ULL, 0x58A4C63A8DD9947AULL, 0x77C7D5B755397C32ULL, 0x2E294D05EF05FE4EULL, 
            0xA3B5EEC7F97F5885ULL, 0x44318A0C9E1DC9E4ULL, 0xB28F2FE3090906ECULL, 0x0B7E7EE549684B37ULL, 
            0x69068B5FE9AAFCE7ULL, 0x3A96DD3FA1272EDEULL, 0x1C649ECD1D2B109BULL, 0xC2B1016D78DBE3FEULL, 
            0xBB081B3C017D3855ULL, 0x6C3B6F039A1412ADULL, 0x5D39C80072246894ULL, 0xDC80064684FCC21FULL, 
            0x4939F179DECF3838ULL, 0x797B511CE528B19FULL, 0x7D36377CB85BF322ULL, 0x26174B6847706C76ULL, 
            0x310CF35EE0DF10DCULL, 0x00FC91701B67CDE8ULL, 0xF963D2FCEA63BB9AULL, 0x2A32464C40299419ULL
        },
        {
            0x59BEE0021CA67B01ULL, 0xD61290955C7C13F4ULL, 0x812AE03116D0A292ULL, 0x6B7B77E3BFD09927ULL, 
            0x681889A818490234ULL, 0xB5A9E2E6E3698781ULL, 0x2DADE8201E59AF5AULL, 0x83BCE71BE0F215A4ULL, 
            0x8D68C36EF8183BE2ULL, 0xE960EA970654F7EFULL, 0x66C92F40B2D6E7F9ULL, 0x73555C907E3DB735ULL, 
            0x43030D69A5F40C35ULL, 0xE5E8EF5502E98A1FULL, 0xEA527516127E910BULL, 0xA4EF043D3B8A5437ULL, 
            0x807D1DB4955AE601ULL, 0xBE0AD4C70B585C9CULL, 0xD360A36B548742BEULL, 0xA432AA077474737AULL, 
            0xA7E02EFDBA20FA52ULL, 0x185B7BF4DFB429F9ULL, 0xA573EFF91168C67FULL, 0xD47FD8D3E40C8514ULL, 
            0x2D96E0EF27B62589ULL, 0xB4FEBCA79EABDC24ULL, 0x1701FAA2DB99CCACULL, 0x602E7F5FA232B9CAULL, 
            0x6EAABFA372F26E84ULL, 0xA9EA9E8E4CEC4068ULL, 0x18ECA57DD2027C04ULL, 0x62C1FD34B604F3B7ULL
        },
        {
            0xA8D9FCCB51171B01ULL, 0xF4DCC409F7E1339DULL, 0xFB010B3949E477A4ULL, 0x7A5C76CFD1553CA4ULL, 
            0xD104E906020E6DC2ULL, 0xF8A6279F2155F7CFULL, 0x2A06D303B9A17D13ULL, 0xC6322CE412EB947EULL, 
            0x3411B809539D3644ULL, 0x53C7176CD0FF3EE6ULL, 0x9812360150E2E13BULL, 0x0E7EC8C9342029E6ULL, 
            0xD2DF0B3328A51D55ULL, 0xECF2D2FEAA75009FULL, 0x0A2F6468265532DDULL, 0x4F49CEB69A367C91ULL, 
            0xD5F545DC3C4FF47FULL, 0x1A3B95D2C9A506CCULL, 0x6FF7F47A5931F3BDULL, 0x53B34F782C99F0B4ULL, 
            0x09A4F737C34E138EULL, 0x67826C2E7BFBE399ULL, 0x39B309E40F90D659ULL, 0xADAD276D1958E5BBULL, 
            0x4A1E0A34ECDB57ACULL, 0x2DE6A2C0850FCA7EULL, 0x1C1903FCE9D0545BULL, 0x8597E382C75FF7A9ULL, 
            0x8BEDC03C527FBDBFULL, 0xED27E6FBA22BC362ULL, 0x1447F20D9E59DD10ULL, 0x082C8F39DDE9830BULL
        },
        {
            0x85DB52AD9792B560ULL, 0x812874A6F99DB1B7ULL, 0x84A3E8306AF5C220ULL, 0xE390830598E13463ULL, 
            0x5267AE62AA996D23ULL, 0x175A52092EBFF1E3ULL, 0x2766F94111017E0CULL, 0x53CBC681FF7D08D6ULL, 
            0x517894879FBCF3B7ULL, 0x3EDFC20DBD957781ULL, 0xB8FCDF4D46D731AEULL, 0x6135C3A6685C19B6ULL, 
            0x71799A2681A0CA0CULL, 0x865CDC51F78C01F1ULL, 0xE49C8EAC2D01BC2AULL, 0x477E77636E1EADF5ULL, 
            0x49E6F8550360C3A5ULL, 0x8C2B4FFA4FD20784ULL, 0xA4EC7C09F5813578ULL, 0x8B4E0D49BC47A216ULL, 
            0x826729C7BD6E8DEBULL, 0x468B45309501BF2FULL, 0x34BC3A00ADDE5248ULL, 0x093EB1C50D5C4858ULL, 
            0xB6D72ED723283866ULL, 0x5B4074973DFDA5C2ULL, 0x3C06DF31B7516EE9ULL, 0x9DEDA50AF01D6857ULL, 
            0x44E5EF74ECC6B228ULL, 0x04E95D236AD5BD49ULL, 0x88488EAA3E6E4B1FULL, 0x85A2F3F8D5E29CCDULL
        }
    },
    {
        {
            0x4B42F9A222A730A0ULL, 0xFD0485042EF968A1ULL, 0x83B7666493C340D4ULL, 0x5A74F10E6B4CD8FBULL, 
            0x1CB5D08A2CAC56B5ULL, 0xD3C206510F95A2E1ULL, 0x6CB2059EBA8FF8DFULL, 0xD2C8F80258DF8935ULL, 
            0x9DDB3909384CAB8CULL, 0xCE41183E9ADB21B8ULL, 0xCE81662DBFB38CCBULL, 0x860840ECA1924280ULL, 
            0xA7B3B26BDA469D6DULL, 0x60BBEDA5F25BC430ULL, 0xFB9F4AB8267BA891ULL, 0xA13497802D85E5C1ULL, 
            0xE738088F2C4B6903ULL, 0x84C65039F1DDADCFULL, 0xD5AA6A48502FA21FULL, 0xBEDC308FC27BEB5BULL, 
            0x4C4CC0494C92B52EULL, 0xA5B49D87AF48D269ULL, 0x61B55F292199F884ULL, 0x088CA6C53BE70512ULL, 
            0x80EF24E9CB19E144ULL, 0x6356BF6B9A9A2372ULL, 0x74D7CF6C1649BE8FULL, 0xED0ED6FE249A1C3CULL, 
            0xACE509E7CDB87948ULL, 0xBD320654B3A0EF3EULL, 0x0F0BB825E8FE2F88ULL, 0xA848523CEA6ACD7BULL
        },
        {
            0x91D153B0DFB83204ULL, 0x283A0C7F913DBB22ULL, 0xB10FFE9CBB8E2EE9ULL, 0xBA0AD4D6BEA0262DULL, 
            0x9CC7A0C72458F14DULL, 0x74639C345B59854CULL, 0x85CA1A4625E042BDULL, 0x1B6F3D9A2640A09EULL, 
            0x62621907152A5D16ULL, 0xC4EAC3B6DA8A2165ULL, 0x17E592EB3E8B39D9ULL, 0x6F8D4703413BC81CULL, 
            0x27F3BE7E57900A78ULL, 0xECC23D8B3C4B5F69ULL, 0x352B8FC104B7FA18ULL, 0xA7577FE240C6528CULL, 
            0xCB639D8220DBD10BULL, 0x74D15E9726B2814CULL, 0x6C70F9AA4F5A6877ULL, 0xD258F6510001F067ULL, 
            0x2D94CD98E09DA535ULL, 0x377E51311375D2F1ULL, 0xB9E1E1717D7E0B97ULL, 0xB72DCB6CC9C16F3FULL, 
            0xEAEA21FAE876F13CULL, 0x07E736CB7ECC0186ULL, 0xA37082B4CDDAC7ADULL, 0x3770F1D485C7373FULL, 
            0xCC1EB196FCA483CBULL, 0x07E87002F0394366ULL, 0xB76C13E57EFCAAD1ULL, 0x76D76D6CA0E36566ULL
        },
        {
            0x0D5930AB26175E58ULL, 0xC6B118A2485C5162ULL, 0xB3305D5DA86F2762ULL, 0x1743661232F30469ULL, 
            0x0FDD99BEF9AA3E40ULL, 0x5A4D016DC9E169BAULL, 0x5CCF734ADE74B2B4ULL, 0xEC55EC0CD0CAD6FDULL, 
            0x743377F03971032AULL, 0xE79127479391B67FULL, 0x8EACF99EF1318F88ULL, 0x0E3CB226319699D0ULL, 
            0x35D6AB0473B1ABA3ULL, 0x217A0655A09EBC70ULL, 0x417B90DCD61A0FC9ULL, 0x15FD464B67EC671AULL, 
            0xB4152A36736EDB8CULL, 0xD4159DA557156903ULL, 0x57186479AB5DB00FULL, 0x9FC0BB0E08954B0EULL, 
            0x04873308E0BAC7DCULL, 0x5BFD3AC9D87EBFC9ULL, 0x4685A4ED373D28D0ULL, 0x3BFD10ABD5198FC9ULL, 
            0x5A0A1069ED5BA000ULL, 0x74B65A8B438CA90BULL, 0x64912E56BB1EE292ULL, 0x11EF8564AB99E8A5ULL, 
            0x221F1F339D1FD59FULL, 0xB607D918721D82FFULL, 0x82C0EE80F15D96BEULL, 0x7C37A7A3B280D736ULL
        },
        {
            0xA23806A063FA7B31ULL, 0x618F418407AA4C3BULL, 0xA646E3840A9AA4C0ULL, 0xC0D9B97C259BC543ULL, 
            0xD5671816AE4F5E66ULL, 0x6EE0B4AC9AB8609FULL, 0xA3BA258E1BF07C30ULL, 0xA6AF200D2E611F57ULL, 
            0x71A24E4C50EA4357ULL, 0xE5DCD7B8D1E33F9AULL, 0xAF1E71270DA3A201ULL, 0x5371B98471D29A49ULL, 
            0xA57BA6183FEDE0F6ULL, 0xED019D2D29AE9875ULL, 0xB1C3E31BFFBF27AAULL, 0xC7DADB4C509BEBCAULL, 
            0xB40A50884843199EULL, 0x7EBA90479A734A81ULL, 0x928702A24DA10B0CULL, 0x00587B631C53B90CULL, 
            0xD6918E688724E930ULL, 0x4D74377063C0F918ULL, 0xB7887959CCF62F54ULL, 0x09AE1AAF70BA4F37ULL, 
            0x1985D10A649E06BAULL, 0xFB3081D6C0CCFA38ULL, 0x6F99C713A0C1D858ULL, 0x53B247B44856D815ULL, 
            0xB797EA2178790643ULL, 0x17D43760415E7E3AULL, 0x8A6FAE1A772BE578ULL, 0x785FBF2C3F01AD44ULL
        },
        {
            0xD7283FA1439BF7D1ULL, 0x29EE9E8AEAD38AD2ULL, 0x80FB25927E57FF21ULL, 0x4BB35EC39B33CA99ULL, 
            0x8C45FFC9B638B0CEULL, 0x6D87CEB3308179EBULL, 0x9C3B4AE75C9C7952ULL, 0x6F614D3D4A5FE163ULL, 
            0x9C5E9C8A76DB59EEULL, 0x2F1374F53CF2FA05ULL, 0x047990F2F4BC18B2ULL, 0xE3A5FA0ACD417137ULL, 
            0x4A3F46F42AC014A2ULL, 0xBEDEF51BCCC3827AULL, 0x4E9D0EAC1902720AULL, 0x5A726E59A586BEE6ULL, 
            0x39C6F03A04964980ULL, 0xF6A0EF73602B6F02ULL, 0x44298D32FC329DA6ULL, 0x26D7FECAF4E5A493ULL, 
            0xDA7AF70EB554AAAAULL, 0x8D03B27E7FDCDBF6ULL, 0x60D028B674A323F4ULL, 0x453784FA5ACCD73EULL, 
            0x6B1FD726BA3D6E52ULL, 0x176DCFE36AFAAACFULL, 0xAF285A0C3BA2E738ULL, 0x905D1972C2C82F9BULL, 
            0xD6D90C04F093433FULL, 0x8FED546A48B7F4C9ULL, 0x3A825964CF15CF8FULL, 0x31281E7EF4490A3AULL
        },
        {
            0xA09AB079931732FDULL, 0x7CDBAF60B0507B80ULL, 0xDC40D0FDDE01205FULL, 0x410B090AFBB58E62ULL, 
            0x8C820FE2040C4E21ULL, 0x1EC054E1A5736656ULL, 0x685084E15D366538ULL, 0x20E99DCFE19118E6ULL, 
            0x499D30BCBBACBFD0ULL, 0x5DC9768740CA2544ULL, 0x06818A10DF2B677DULL, 0x76B93EA5B1E0DE2FULL, 
            0x6D1FC7C2177E2A4FULL, 0x3A004B39F7CB89F2ULL, 0x7BFF733612A1FECAULL, 0xDB5768835C3AC470ULL, 
            0xBFDD2C8050BE0DA2ULL, 0xA3EA9DE9E1D9D81BULL, 0x27BBEE3BDEA2BFA4ULL, 0x79DB9C3B5F439913ULL, 
            0x72E7B7A77F36E534ULL, 0xD89C260A08828DD9ULL, 0xB47A4B93474A63B3ULL, 0xF9BB38E84B6352FAULL, 
            0xD339E76A6762D49BULL, 0xA6E47B8247A4A798ULL, 0x766C3956E619F978ULL, 0xFCFC473035ED3CECULL, 
            0x3327469CCDBE2CA4ULL, 0x12DE39D34B0EC716ULL, 0xA70E97494A97B0A1ULL, 0xEA718484FBCFD035ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseAConstants = {
    0xDE56DDA77BF096A4ULL,
    0x86DCC663F1E3A6B9ULL,
    0x34BC5F2287D1D50BULL,
    0xDE56DDA77BF096A4ULL,
    0x86DCC663F1E3A6B9ULL,
    0x34BC5F2287D1D50BULL,
    0x742D18F72E1C16D0ULL,
    0xDA35494DEEAB2A65ULL,
    0xCC,
    0xDD,
    0x8C,
    0x64,
    0x02,
    0x70,
    0xA2,
    0x99
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseBSalts = {
    {
        {
            0x9632220C741AB4A5ULL, 0x0609A3703DFA204CULL, 0x90BAEB3CA17BEBE0ULL, 0x041ECE82CF0BBD29ULL, 
            0xD35DD3423F261F22ULL, 0xFDD0ACF4177A1A4CULL, 0x58A18C5B2429B3B7ULL, 0x9D2FAC2B06106008ULL, 
            0xE1759DAA882831D1ULL, 0xB863C6603D02DF4DULL, 0x479120D260A987BDULL, 0x1EE436AA3995527FULL, 
            0x23C9E8973A812B50ULL, 0x45C9B0C14B2DDD95ULL, 0x74855058040DAB2CULL, 0x2AB48BE4E8106690ULL, 
            0x46457347677BE2DDULL, 0x3F7C9D2182518789ULL, 0xD8922405625238AEULL, 0x9251423F32C609B3ULL, 
            0x8545F6127F833F7BULL, 0x70E3F95377D036BAULL, 0x4A62417A8F190404ULL, 0x007723588F2B4072ULL, 
            0xE549BE2D35D2F94FULL, 0x00CDE4907C870D38ULL, 0xE0EB2D2FEF0DD758ULL, 0xBA96B9D88792EC4EULL, 
            0x39D6A994893F8C47ULL, 0x7570749C7BA49CE6ULL, 0x333BB65D0CB94E12ULL, 0x0424071459DB5568ULL
        },
        {
            0xADFE0896F5F6F070ULL, 0xC860F6C48FD1BA67ULL, 0x6D27167418AD34DDULL, 0x2B36917650DDD9E8ULL, 
            0x4B925F9400300368ULL, 0xEF600404B9013F12ULL, 0x57CBC85801D98D90ULL, 0x4B7D920F46BF8C26ULL, 
            0x704E300AB807FD00ULL, 0x085F3501FAA9B2DEULL, 0xA5B0F71F644F752CULL, 0xC423F00E4F23DA46ULL, 
            0xDDB6D36A9243B0CFULL, 0x90B94DE86BBB9D87ULL, 0x88118B63C22893F3ULL, 0xA86E7C4E4C1F27BBULL, 
            0xB1B20E0FD1628340ULL, 0xC610086ED0DD46AFULL, 0x9CE15F1DFB7B7CF0ULL, 0x974E3C86C7DA4110ULL, 
            0x59FF5EBEFC0C0BADULL, 0x9E3AE29F6E17FEBBULL, 0xFFAB0128356213E7ULL, 0xE1A39CCD1EC7CDF5ULL, 
            0x15A9B4BD52B8AC6CULL, 0x0BBEEB9929965FB2ULL, 0x8C07FC4FFF61DFD6ULL, 0x113F6FFA0C18F2A5ULL, 
            0x15458DCCB78FDA31ULL, 0x07FAAC3F87D532C0ULL, 0x07627B70BA46149BULL, 0x8D1E6094054A855FULL
        },
        {
            0x70A57CE66D8902C1ULL, 0xFD42B88C4B0752A5ULL, 0x79293F526ACC2E9BULL, 0x17D71FC2B9BD7973ULL, 
            0x6D9F3B8BD77449C6ULL, 0x945DA775EEEF1AE5ULL, 0x28161B022ADAF6ACULL, 0x35AFB94C82342B66ULL, 
            0x25CC245E7281599FULL, 0xC84F2CBBF875D02AULL, 0x53F259FB5EEED1D9ULL, 0xB5915FEC81AC2E82ULL, 
            0xA516CC85BCD337F7ULL, 0x523187CCAF49A909ULL, 0x96AED95620148BD2ULL, 0xE543B02FFF5CE570ULL, 
            0x233E493F1F8C73F5ULL, 0x70F28F9FE73E8D20ULL, 0xEEE34F59D15F7E64ULL, 0x8ABAA4B1A13286D7ULL, 
            0xD5CE48218CDD0F93ULL, 0x819EF2ACEEBD8D6DULL, 0x08231CDDA832AD57ULL, 0x51228D2D2F992D48ULL, 
            0x80E20F3EB33C3839ULL, 0x9C0F41FC45377E16ULL, 0x043A07AC9F8CCF48ULL, 0x000329F370E0B2F1ULL, 
            0x320B2821D0E24AC4ULL, 0x708C80FC6988AE5CULL, 0x4D209368BAF613FAULL, 0x3D8558907CD0E691ULL
        },
        {
            0x3DE68A52D4F35041ULL, 0x705C14EFFC4D31A1ULL, 0xC465C770F3DE4CC2ULL, 0xD3B35ACEF6B6C62FULL, 
            0xFEF6A6751DF9C172ULL, 0xC33AD345BFFCD7D8ULL, 0x9B8A1BDA705BA3B8ULL, 0x492127659AAD9645ULL, 
            0x486EE63199E6DBE9ULL, 0x8CA544FBB4388225ULL, 0x35FDE04017DF4D88ULL, 0xD0B02D5574070DABULL, 
            0xC780BB50A1AD2942ULL, 0x551187A948F7DF31ULL, 0x199A2D7D3637E44DULL, 0x5BE275A22B4FC789ULL, 
            0x65F24EAFECC8B395ULL, 0x6D7B566AB5B1725AULL, 0x2738F0BE0ABEBF68ULL, 0x015FC6404A515BD1ULL, 
            0x4141EC93E891A994ULL, 0x0D4405A71785662FULL, 0xD813689E36D34C8DULL, 0x571325F3AB571C41ULL, 
            0xA126C7311D7838EEULL, 0x161A810361957DF1ULL, 0xDDC24D6E1761B49BULL, 0x515E7FF0E29CE7A2ULL, 
            0x27AF6CEB2FA0003AULL, 0xC1D0DFF7F05C5EA4ULL, 0x6EBB99962D13C71AULL, 0xA27862046B19D435ULL
        },
        {
            0xF15C02EDA5801564ULL, 0x2132EB0CA48054DCULL, 0xC7A4875D7BA70307ULL, 0xC94711545FE9549CULL, 
            0x551E8D4A783E33CFULL, 0xEBE7E85779EBF8CFULL, 0x3DA1E68E3CD6DC31ULL, 0x1F221DE8A45999D8ULL, 
            0x78BFEAFAC1089A3DULL, 0x2465DDD5A958BAABULL, 0x52251C360B317B4CULL, 0xAD6D24D7D9DB308FULL, 
            0x98E4153F6415E59AULL, 0x1EF2D7E4CBB2F7D5ULL, 0x5E217446F3FD6696ULL, 0xB23A92413B98B4DEULL, 
            0x2808B777149EF8F7ULL, 0x4A7E9CDBFD1C1DA2ULL, 0x06E38621061252A1ULL, 0x083388B40F6F5B6CULL, 
            0xE534B412DDE82E11ULL, 0x6E30BD9A1B3FF6BAULL, 0x5B6060EEC58692E6ULL, 0xF47246E9FB02EC6FULL, 
            0x29B05E25B664B63BULL, 0x29C242D13BD7D1E5ULL, 0xBC90B2A844EEF4DEULL, 0x160AF0F1C4DDB121ULL, 
            0x241C5312359E8860ULL, 0xAC49791EA2734CFFULL, 0x483AF15D2288AEA8ULL, 0x4F0A5775AAE2BBEFULL
        },
        {
            0x8377ABA6384ACAFBULL, 0xC04B26C12FBA6E12ULL, 0xA1D77C52F91419EAULL, 0xA255FCB89E6BEE08ULL, 
            0x8C3CE6A412369362ULL, 0xFEBC4667601DE246ULL, 0xDACB034E0A781A07ULL, 0x0DDE1E309EB58EDCULL, 
            0x88AE3569F0D60253ULL, 0x3AE369682E7DA2BCULL, 0xDBC43544CB78C470ULL, 0x9BB42A28854C44CAULL, 
            0x98CE1FCFAFAFA223ULL, 0x9856FF456C0C7207ULL, 0x826101C8560BA386ULL, 0xAB35625D78824790ULL, 
            0x647CD7478632E1CEULL, 0xFBCE48AD4D828AC6ULL, 0x947698886602E493ULL, 0x6585F39A701A863DULL, 
            0xF3A6C6514D186A71ULL, 0x8DD06CC798E69AB3ULL, 0xB50E55B445A91751ULL, 0x4FB429868019023CULL, 
            0x113C207B0797B307ULL, 0xFDBA3676BD3C4EADULL, 0x948F49EF72F554CEULL, 0x58F67B186757A3EEULL, 
            0x436912E749BB15A5ULL, 0x6C94A07DD0F86EBCULL, 0xB04921DBD04ECFCFULL, 0xC0C7E2051C6E842AULL
        }
    },
    {
        {
            0xF942FE4DEBC31800ULL, 0x1678A70681D97728ULL, 0x92D90CF2C3F24506ULL, 0x65523A31E1D42D8DULL, 
            0xFAAB166C9A8489E3ULL, 0x242A99477D03E9C9ULL, 0xD8426BD416222302ULL, 0x3F10A14256677228ULL, 
            0x83B63A07141C0557ULL, 0xE31631C24A1CD5B3ULL, 0x0FA4FF9E5C8CE299ULL, 0x67963EDAFE5FD662ULL, 
            0x5B878170894ED44CULL, 0x25E1D8DA9F4B8425ULL, 0xE440779248975987ULL, 0x8364B3136F3F4EB2ULL, 
            0xA83A422FBBFD3803ULL, 0x2D31DA43548E55FAULL, 0xFD0905175755090BULL, 0x36FE68446B60CCBBULL, 
            0x0AF8235F7F49520FULL, 0x9AE43C8EEA6FC1B8ULL, 0x4A50DDC4FA6835E4ULL, 0xB6DE4D6D6CFAC212ULL, 
            0xC19201C1C450287EULL, 0x53578EAF20186D0AULL, 0xA366B07BED82A440ULL, 0xC53ADB65D97FCF0EULL, 
            0x24A6043413DBC5EEULL, 0x873BE9911C13D8E7ULL, 0x6EDA491DB8703BA7ULL, 0x3F08C4DD52FEA6D1ULL
        },
        {
            0xA98E304C1BE293BEULL, 0xF294643DE100FF8BULL, 0x0B1CEE3BD34DF926ULL, 0x32456CAA45F6142BULL, 
            0xB7FC4CE3F7692EC4ULL, 0x96948FF4441C4F5CULL, 0x4418025E7D30F75CULL, 0x869394964CA85436ULL, 
            0x3A347BBA9B5DF6A1ULL, 0x1155F5C9B069C64FULL, 0x3E638A023F9FA46AULL, 0x4BE7739906E9782BULL, 
            0xA0E4B5F590EEFC59ULL, 0x3877C4F2661A8A2FULL, 0x17D5ED11B5C8216FULL, 0x610B8E8FD565D360ULL, 
            0xFFB3C5E758838B49ULL, 0xBEF2A8528957FBD7ULL, 0xC8F9492555FC5A37ULL, 0x3F08179D4B4CABD8ULL, 
            0x7EA870360892E5D5ULL, 0x01F5B81C4D88EB28ULL, 0x672A618CD9DAE552ULL, 0x9FB8812202AD3111ULL, 
            0x7A77D7A4CBF6B900ULL, 0xC394B01B9902F730ULL, 0x0EC0CBC3FC873711ULL, 0xB2EF8FB9EF28CAABULL, 
            0xEE98335A2733DE6CULL, 0xCD53BF81686CAD79ULL, 0xA3D8B48EE3FC5A66ULL, 0x0CB5CB38EEA7085AULL
        },
        {
            0x05003F13709A5914ULL, 0x17DD37C3A863D561ULL, 0x0A684BC23FC2EFD5ULL, 0xE9BCE79B500837A9ULL, 
            0xED11650C4C691716ULL, 0x14C643AEA948F91AULL, 0xD0AE117B69AB793AULL, 0xD20314B4DC8FE794ULL, 
            0xC8941C684D562B97ULL, 0xDD0BFE22CD3F0530ULL, 0xEFB05D9C243B7698ULL, 0x371DEB7C0A48332AULL, 
            0xD13210D4B0522FDEULL, 0x1A59A22FE97AF696ULL, 0xA3DB8A37DEAB3BC2ULL, 0x97417EE7E6E14F07ULL, 
            0x797A7DF365F13F68ULL, 0xDAC2A6C1C62901DAULL, 0x87D3E4DE2C3AE1ADULL, 0xD50C0D21149BEE5FULL, 
            0xCD0D4082B1E26466ULL, 0x5CCC746FEA1003F1ULL, 0xB6D2A7115928CE09ULL, 0x3E555CC25580BBB1ULL, 
            0xEFFFD60610A9C2EDULL, 0x5F8F38C0D894B4F3ULL, 0xF03D70D39C8AE9F8ULL, 0xC5B311FE74F14A4CULL, 
            0x934C9DBEDCD83BF3ULL, 0xAB5A2F3A43EC5A86ULL, 0x3BEE0169F63568A8ULL, 0x0314B8A5088AF015ULL
        },
        {
            0xA00611B2131F96C0ULL, 0xE891EE2B77521E88ULL, 0x74FDB5226504987CULL, 0xED41998D410E7BEFULL, 
            0xAD6F2F630C0246E8ULL, 0x75C890A7BD0F18A4ULL, 0xD641BF7DAEBB33F0ULL, 0x036BB1DF851B7DFEULL, 
            0x9AC73A11214255A4ULL, 0x84B2CB955E2CE4FCULL, 0xAB0F6C1725D44AD8ULL, 0xFF38ACFF588A7EC5ULL, 
            0xA032BD6E137597E9ULL, 0x285F8E185A01125AULL, 0x327D539522BE8BA3ULL, 0xBA7E10C967F348C8ULL, 
            0x7296306487EA42BCULL, 0xA92FFD16AC379AF6ULL, 0xF854D8425E7B2A20ULL, 0xF6D8EF59FE02A42FULL, 
            0x084383394D40E812ULL, 0x99E26C7207A92A5CULL, 0x51BF186A47D4CB02ULL, 0x5CB80F1FCA313A29ULL, 
            0xB83B4692F6DB8F26ULL, 0xC04571873D418FD6ULL, 0x1968ECB78AF070D8ULL, 0x657EDCF9AB814773ULL, 
            0x92905F9C8C0D55E2ULL, 0x25B5FF6829CB06E8ULL, 0x8A066A475DB6A371ULL, 0xB0080C7D8698CBD6ULL
        },
        {
            0x5624633904C23324ULL, 0xA49E1AB060969266ULL, 0xA207CC103592051BULL, 0xEB8D510CA04FCB1DULL, 
            0xBE7D6DF339290513ULL, 0x089A7DD8E1C8214DULL, 0xA41A6501FFA4B304ULL, 0x647656E7190DB26EULL, 
            0x0FDE52E74C900CA2ULL, 0x3B5C370417DF7EB5ULL, 0x3C2A1A7C8FA35EDCULL, 0x42CE6D57F88638E2ULL, 
            0xFF66E872477EE2F2ULL, 0xA073DDEA4081C905ULL, 0x22C2006830A0E4E4ULL, 0xED5B3B9099801EBEULL, 
            0xE00C2A1E2C66A287ULL, 0xF6D5335195EE53E1ULL, 0x6BC3B002CB66741EULL, 0xD9EBC612F9C5CA60ULL, 
            0x0391E1B74895B568ULL, 0x5F629BD535E06FF6ULL, 0x35385A5C5D2F1AB1ULL, 0x18F760D25A8AE175ULL, 
            0x492C352250CF01A1ULL, 0x1DFD7DB0EE4E60DCULL, 0x6AF08D7B25D97DA5ULL, 0x7CA9E1FC89BF86DDULL, 
            0x634E3879DA187E56ULL, 0x4E9C2D79FD373BF8ULL, 0xDEC1E016EEC84454ULL, 0xB9AEBA10A382311EULL
        },
        {
            0x9F557FDF64EE2D60ULL, 0xBC72D3C2D3CF2736ULL, 0x6A3F674697CB14A8ULL, 0xA060B5701C385098ULL, 
            0x9FD1F2215B6230A1ULL, 0x0FFE31A267569B70ULL, 0x51920E2FEA2934F9ULL, 0xED3E171AF9F270CEULL, 
            0x8AECD657D67C0D1DULL, 0xD9C94EFF5671B809ULL, 0x95940DE6A7A996EBULL, 0xC03BE88F72F628C1ULL, 
            0x7E7CA3645CBD5DA5ULL, 0xAF893872D99C323FULL, 0x1C44736514D5DE7BULL, 0xCEB80B26B4FA95B6ULL, 
            0x6F476AA94DEC38E3ULL, 0xC5956964E36F5147ULL, 0x38303936AECA877EULL, 0x0D79937A79005D87ULL, 
            0x82CBEECA0B141A43ULL, 0xCDB9B8924A0CAF0DULL, 0x2B0399823E5B8D93ULL, 0xD870196E5F4F824FULL, 
            0x6F329DA1ACBCD38BULL, 0xB220486CDDF31018ULL, 0x95E521843F79D335ULL, 0xB422D7C9168522F9ULL, 
            0x80062C5B45A50100ULL, 0x95E00983942DE312ULL, 0x9CA8E2C58208DD27ULL, 0xC324992D3F69E4D2ULL
        }
    },
    {
        {
            0x261817D92BD86FB5ULL, 0xAC2D35BF28D82137ULL, 0x5B9EFC9AE6E867AFULL, 0x79DAA05AC74802DCULL, 
            0xDFD82B237A1ED5D4ULL, 0x9D6C7856A09A2CDDULL, 0x1F98EB7C9CD3CAF8ULL, 0x99F5A835E4ED7368ULL, 
            0x6C0F9EB2E5C6EDDCULL, 0x4C31BE6DD96C30DBULL, 0x31E32B39240FA954ULL, 0x3A023CF8774867F1ULL, 
            0x1175373E4A797F84ULL, 0xEDBF0757C81055E6ULL, 0x8C3236335A9FE086ULL, 0x35E8D7EF5DF4B533ULL, 
            0xA7FD57CBB8ECD34AULL, 0xEA8B7716F6FE0BFBULL, 0xA1F47B901F25FBEFULL, 0xBF43F5DD0E0BA71BULL, 
            0x009E46E4FBE22263ULL, 0xBAE21850BC4D5DCFULL, 0xC25EB9CF2AB7ED87ULL, 0x92A39F58FD2981CFULL, 
            0x9C611D867094E713ULL, 0xAEBB5140654B8F29ULL, 0x8AC39CC9210E36D6ULL, 0x87272617544041DEULL, 
            0x9826FBCBC380BD1DULL, 0x1658133CAB72E833ULL, 0x0340F9F2183B2D8AULL, 0x9DB117D219218399ULL
        },
        {
            0x28C3EE85FBC1AD15ULL, 0x9F860E4081E616C7ULL, 0x594A7D49FA601DF4ULL, 0x2D910CE5D8FC8581ULL, 
            0x7E350026358D9565ULL, 0xA62E15A25FE2A49EULL, 0xB2505F00FBAD4565ULL, 0xDC538C5C5999F0C2ULL, 
            0x47185BEA99C28231ULL, 0x824CA76DDE0D44ABULL, 0xBD96534E77B8E19FULL, 0x9E9A9FA2A5C8B7E5ULL, 
            0x3C22288E4788D31AULL, 0x950690C392E87CE0ULL, 0xC65E6AF6A0BB44E8ULL, 0x4658ABCA90C7D928ULL, 
            0x67C595E0ADED69FEULL, 0x913294702E1ECD6FULL, 0x361E32C55731DDB2ULL, 0xCA085C6ADD18A124ULL, 
            0x39C6DE81C319DDA4ULL, 0xF487A66AAE55C2B3ULL, 0xF2D1784CF6A4E9F3ULL, 0xED79755C8FA99915ULL, 
            0x93469E0FD192B47AULL, 0x594847114604D164ULL, 0x11A4745A811DFA5AULL, 0x368BDD70DD4F218CULL, 
            0x34ED924D88AA1A42ULL, 0x2DBDF0F61001D8C5ULL, 0xBF1828E0B58C8487ULL, 0x9FA7F91973A1CEB7ULL
        },
        {
            0x2C084C8400BE639DULL, 0xE43F8C7A32E6AF12ULL, 0x5471C6222260EBCBULL, 0xD218FAF02368076BULL, 
            0xA9DED56CD278CCE9ULL, 0x8444BF301248AC2FULL, 0x3EFDE5AC9725B88DULL, 0xB400F21DDD1C05F7ULL, 
            0x729BDF3772F8D7DBULL, 0x8D4AEECAF868C026ULL, 0xFFABD9CA2DCE0E5DULL, 0x50E8A573C5E40104ULL, 
            0x138E85E7266ADABAULL, 0x2164F7D026021AF6ULL, 0x2982D1E16BD2C73DULL, 0x2B64A712B06843CEULL, 
            0x4B0A47761B3FC256ULL, 0xBA1A3E0434C86EECULL, 0x3DC05F9380EB0CB5ULL, 0x84227F3AFDD310B1ULL, 
            0x955128BCE14BE7A0ULL, 0x9126176D9B55F07EULL, 0x24C5E345C627DC61ULL, 0xBB219DF6A45EA17DULL, 
            0xF4C86720092A1449ULL, 0xAB1B4A1F58B97120ULL, 0x33AF268FCDE9D744ULL, 0xC46DFA3584B9AE1EULL, 
            0x1E7A752BA65F4C57ULL, 0x52843A297212BBEAULL, 0x9F6A4883CE7DD365ULL, 0x325F020FE9613FB8ULL
        },
        {
            0x6C276998FE345A7CULL, 0xFA0E464635EC4D8EULL, 0x0C676C7AAD881728ULL, 0x8BE5F8653DC4BB94ULL, 
            0x427EA45E271084CDULL, 0x822DFAC97EFCEA00ULL, 0xFA099154F4A65224ULL, 0x2D899496E2547708ULL, 
            0xA3D10CC2660B1D39ULL, 0x2BFAD7624C7A9B37ULL, 0x2FB8B6D70DAC211DULL, 0x9D5BB323B7D65890ULL, 
            0xBCC8CF853B04116EULL, 0x3C622A1E55EB49CAULL, 0x057BBF1E470C99C7ULL, 0x98B46C2018928413ULL, 
            0xB7A6ECE1A6F3DC4EULL, 0x0D1E3B776D1F1EBEULL, 0x22ACC8C63181C935ULL, 0x5DB68EB4C52B48A6ULL, 
            0x5F89417D182C1006ULL, 0x92AF558D4E765675ULL, 0x25D675964D8DE7E6ULL, 0xAD37E37ED9F1CAE6ULL, 
            0x033317DE97241460ULL, 0xC0C80F1F9B46BCE8ULL, 0x35ABB41A7246E567ULL, 0xAE9134F8B2986E3EULL, 
            0x7DBE1EEAAA572EFAULL, 0xFB5627917209E376ULL, 0xCA6292A51CFF0BD1ULL, 0xA730890F2423AA97ULL
        },
        {
            0xA8690D60638278E3ULL, 0x2E32A3F23D95B4EEULL, 0x01BEAE0A4CAD55D5ULL, 0xEE148E124B209FD8ULL, 
            0x2C9E978710F4CCBFULL, 0x2843D97BD2E9DEC7ULL, 0xD5BDAC4EE83D6D1EULL, 0x3EC7C424FACCB3B3ULL, 
            0x83988862B6356ECBULL, 0x451F0B6EAB5A5729ULL, 0xB29CC19A43E9BA47ULL, 0x010F194BEEE12681ULL, 
            0x2B22217D8EF12B0BULL, 0x9E6AB9A07E36F793ULL, 0xAC4B8E2A64AC68EDULL, 0x59659A7D77299B73ULL, 
            0x7FEDED3B4D73104BULL, 0xB10B00A939BE3F8EULL, 0x33ACE200CF40A068ULL, 0x4F8399911C79FFDEULL, 
            0xE2E6971C5B42BAA2ULL, 0x1A621FA6886F953AULL, 0x8CD231C5BFF4C613ULL, 0xCC57D1802DB2EF97ULL, 
            0xC092FED921ECF5F8ULL, 0x256A9379E963E735ULL, 0xD212E2377FE5C2B7ULL, 0xDAB39F826DDEC7C9ULL, 
            0x7567CBD2E606F95AULL, 0xF4BB486075087F20ULL, 0xEDDD4B7C3E1938A2ULL, 0xF0FF3BB3119FD03DULL
        },
        {
            0x299A458D0EB4DFFDULL, 0xEA8A3B56CD47F750ULL, 0xB22BE59FD82A7561ULL, 0x3631BF21D7C648D9ULL, 
            0xA95FDF52D5149DA1ULL, 0xE47286C882007F4BULL, 0xC77D5A8A24C902B3ULL, 0x08D42DFC52BB5996ULL, 
            0xAC6BFE8C7082A9E8ULL, 0xBFDDCD4D06CB0CA2ULL, 0x5FF9852882BD5D89ULL, 0x76FD4C6AB6FCFF80ULL, 
            0x0943F8C9282C83AAULL, 0x1E4FCDBC02FC97CFULL, 0x3C0BFA529EADC65DULL, 0x73CF2C777FDD25EFULL, 
            0xF2813816A5E4190CULL, 0x0F2F62186089EA21ULL, 0x4FE62B2176069941ULL, 0xF0A04B21B372D27EULL, 
            0xD06A813CEA5D5AD6ULL, 0x458D51E11DCD711FULL, 0x569A0FA4D90B0EB1ULL, 0x6EB183794B576E45ULL, 
            0xC16068053AB5A751ULL, 0x3619EBD5CF4C23E5ULL, 0x0F43B56C83B121AAULL, 0x451D5B1715E7320FULL, 
            0x54DF9283A78B44B0ULL, 0xB3260076AE2FF8ABULL, 0xAEDF96C8CD0448E2ULL, 0x07FEDA5CEC5CC767ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseBConstants = {
    0xA1880BE688E7E622ULL,
    0x12D7E24FF2D72685ULL,
    0x67BD4CCFAB6B6D9FULL,
    0xA1880BE688E7E622ULL,
    0x12D7E24FF2D72685ULL,
    0x67BD4CCFAB6B6D9FULL,
    0x483A8C35C2F9B677ULL,
    0x1BC0B5C1D7287584ULL,
    0x6B,
    0xBA,
    0xCD,
    0x2B,
    0x27,
    0x1E,
    0x77,
    0x6E
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseCSalts = {
    {
        {
            0x908598608F1228C9ULL, 0xF331B1A0F12A8D0EULL, 0x8483A7828851EAA5ULL, 0xB8A7F95B4893A9E8ULL, 
            0x5B6568BCA954A8FBULL, 0x0FBD0D88A69B7D35ULL, 0xC585734B7D053E17ULL, 0x4FF31554EC18051BULL, 
            0x26FE5D26EFFD192EULL, 0x117539877E9E23C3ULL, 0xA8707BC950DB42A7ULL, 0x8C9C14ED327C9016ULL, 
            0x288C0541493D0135ULL, 0x5565864FE0168CA3ULL, 0xA06CAC351DC3C411ULL, 0x18A98880F407D27DULL, 
            0x8A04A7C2ACC1E35FULL, 0xB4B5085BB1A6E415ULL, 0x1A73C7F6D4911048ULL, 0x449AAC99473818BAULL, 
            0xEC2BD64C6EEC86DAULL, 0x1E1EF2BF71BE2A61ULL, 0xC7CFC6C5E983D728ULL, 0x7D985A1E1303D35FULL, 
            0x0679787CB159E806ULL, 0x6BCDD6089351440AULL, 0xD609B802F52C43D2ULL, 0x5ED769DBB1A5FBDBULL, 
            0x6AD1A3F468AB2365ULL, 0xB7D866CE9790CA2DULL, 0xDF0E99223BE6390BULL, 0x64FE5A229060991CULL
        },
        {
            0x715DA725047B3B90ULL, 0xFA566515A88598A5ULL, 0x1E0C6B0226345090ULL, 0xB33BDC0E7403DD3AULL, 
            0xB64B5FFCFD0F511BULL, 0x5AD0180EB7FE1FF4ULL, 0xC14B0E505189376FULL, 0x63AA30F75CB41CB6ULL, 
            0x38AF89CD5AF12CEEULL, 0xDA27A2C3B2AB3B63ULL, 0xF811451924BA71E6ULL, 0xCBDB4D5C0F894278ULL, 
            0x77C092A76DC85D51ULL, 0xCA8A4614483E4649ULL, 0xD3B5FE89B6EFAA0DULL, 0x9D28502D3D57DB5CULL, 
            0x7211B2DD20661D4BULL, 0x3FAAD3069721A0B8ULL, 0xD4D93A4F532A2DE1ULL, 0xC36EE6DAE448D15EULL, 
            0xD66DA93C2C832D2EULL, 0x7CD9ABE8B116B2C9ULL, 0x478A8C8F23DA3FD9ULL, 0x97C561AF192088BBULL, 
            0xC6CAF9922BA842FAULL, 0x7989F63A8CD732B3ULL, 0x8231E97C4DC5CCABULL, 0x04E3B7BAA9CBA313ULL, 
            0x3127B703C0AB3E67ULL, 0x7574A009554D6394ULL, 0xAD3AB66F7F98B1DEULL, 0x09A0A762925456A2ULL
        },
        {
            0xD4BBBEAED9330951ULL, 0xB99BF4FBBCAC582EULL, 0xC6EB335CA297E6C3ULL, 0xC2D8DF41829434F7ULL, 
            0xF0FAE607B71B4ECBULL, 0x065619B8568AC032ULL, 0x957643F16E733FC7ULL, 0x10D21ECFF4F01722ULL, 
            0x0A388B7FDF65179DULL, 0x058F296488C384ACULL, 0x349683D51625C3FBULL, 0x03FD486D82B4496FULL, 
            0xBCEB336798D8B387ULL, 0xC0E67FF7BB08323AULL, 0xAAAF93AF1D9C75A9ULL, 0x64B8E7A53D2C16C8ULL, 
            0xB9FD940C2510C77EULL, 0x41879A6ECF9BE69FULL, 0xD122A36866F5A4E6ULL, 0x00C2788A78B7FF52ULL, 
            0x86B29147298D61D5ULL, 0x068A50CF7FBCC85DULL, 0xB223D80CC5A7260EULL, 0x2FF17F06FF2B2642ULL, 
            0x5C3E5E443822FAB3ULL, 0xA62CB1C1437F5E45ULL, 0x1FFD8CE9B6A54260ULL, 0xC64C899D5679D1D8ULL, 
            0x61BE8146ACB20F18ULL, 0xCFCE4BD5A505D2E7ULL, 0x083BF3C7D67B1AACULL, 0x550BD6A647BE5CE1ULL
        },
        {
            0x61712193C12515F1ULL, 0x3C34C101A156D405ULL, 0xE27C3FA14D6830F4ULL, 0x9AE751075D5BF928ULL, 
            0x79F134EA1803ABCCULL, 0xF58AA2CEC8183D96ULL, 0xBE75C92CF73700ECULL, 0x46B4F2275D18D392ULL, 
            0x51B3A3ECECF31AC4ULL, 0xD070E2545AFAA4A0ULL, 0xB1B6F380E709A3FEULL, 0xB8327790C1C817BFULL, 
            0x2378E2FE1533EA11ULL, 0x92CD7F4F003C667AULL, 0x67FD4646C1A36E4EULL, 0xCF100476D1BF39CEULL, 
            0x12ADEAF20C53B289ULL, 0x786C0F1C5EF21E2AULL, 0x6604A7CEEE13ED9CULL, 0x9F3C7F727309C32AULL, 
            0x0E886633BCFCB71DULL, 0xBD89860C35BF4335ULL, 0xCE986F5DF6077052ULL, 0x34E972934CE8E904ULL, 
            0xF940457015BAC296ULL, 0xC324905BDF7BEEADULL, 0x05CA176A7F211C08ULL, 0x471BD2AB0EB4E79DULL, 
            0x4F17690CEC1DE3B4ULL, 0xC4D78560CFA389C3ULL, 0x00131D06E54E8B22ULL, 0xDCD86FDB2E0114A9ULL
        },
        {
            0x24E3574DE3C10505ULL, 0x2E086257DC42A1F4ULL, 0xD65FE04A9D79A8BCULL, 0x34C55451D89EA643ULL, 
            0x79B4591274F51452ULL, 0x1E70DB33A5A48E9BULL, 0x33C57AA1379FC5EBULL, 0xFD5C587D95484C2EULL, 
            0x09A213385540C7A8ULL, 0xD1C07AAF6A57545EULL, 0x3AF202C50A1390C8ULL, 0x7DA15062B7FB2B40ULL, 
            0xAF6F57329DDA73DDULL, 0xB52756C1D3C441BCULL, 0x309DE45A456F656BULL, 0xF3E91B7DC46EE4B6ULL, 
            0x43D4952D77F91358ULL, 0xB47FA8E7CA5C7655ULL, 0xD85EE16A5D900141ULL, 0x00918C395C89EC95ULL, 
            0x5E4F7D2CC0436B6BULL, 0x27D512F193335124ULL, 0x8DB5AFC7E30CA7F3ULL, 0xB7AA8DBDF9ED52A4ULL, 
            0x8AE772B2381525F5ULL, 0x5D2B698CE1261CCAULL, 0xE6DAEB382A4BDF18ULL, 0x560020236AB0FBE1ULL, 
            0x0DE925C0B5DD84A4ULL, 0x55867B6A0EC1D713ULL, 0x59A494CC0805806EULL, 0xB33ED43BF1CAAF9DULL
        },
        {
            0x620BF6409A155685ULL, 0xD6C41FC1EAA623EBULL, 0x4C9801957F0C0484ULL, 0x566E2B8BC79E0203ULL, 
            0x352C7AE8D905D003ULL, 0x9107E5427733F881ULL, 0x2D88029C565AD2F4ULL, 0xD683036C9F58478CULL, 
            0x0387180DA6988145ULL, 0x743507522BBB6541ULL, 0x3417C33B06462AE3ULL, 0xBA55430E783E8F21ULL, 
            0xF3D42C982BBFD32BULL, 0x583E35D004847F01ULL, 0x65F2A26665007381ULL, 0x1208F0F769D1FD3AULL, 
            0x558E7FEC1E89D204ULL, 0x0BEC9F8D70A66188ULL, 0x857078F830A8B4EEULL, 0x35FB7C589E8D507FULL, 
            0x0B9A9E32721872B8ULL, 0xB5F72B697896D0E9ULL, 0x8204A05A870AB3A2ULL, 0x0572506A95CE00F0ULL, 
            0x7D33F805B78D2B3AULL, 0x7429AB2AA26DA5CEULL, 0x495D52FE69D75595ULL, 0xE1B9D921C234C73DULL, 
            0x83B14772907C17F8ULL, 0xAA6FD24F34AE71CAULL, 0x667E3B91A6A8ACB7ULL, 0xA434F54119E2D40EULL
        }
    },
    {
        {
            0x9539DE9C2C2BDD07ULL, 0xF7C5C8F9D0127C11ULL, 0x789C6FFE1483FAC0ULL, 0xABD3BADC942C673AULL, 
            0x5BCD58A0644B7613ULL, 0xA8C316E10BBFE92DULL, 0x59F088956D4688D4ULL, 0x5CE98046B85043D0ULL, 
            0x692586FE6D36B1E4ULL, 0x4283F46EF1375A2AULL, 0xF152A19C8205029BULL, 0xA970B3AA8B906345ULL, 
            0x0B85232C548165D8ULL, 0x386713F8B27E65DDULL, 0xDA12DE0732D5AD16ULL, 0x2FB133C563266C75ULL, 
            0x6EE352D80C20430FULL, 0x7FD756B6B9DB4C1DULL, 0xE784BD60CAFC2551ULL, 0xB26556AB3B735257ULL, 
            0xBA8B1E87BB47ED50ULL, 0x276A598312228B28ULL, 0x83743758E6AF4AAFULL, 0xB6760039E8417846ULL, 
            0x456C86E9384A9C47ULL, 0x441343FDDEAFEA55ULL, 0x684B09E8BC253236ULL, 0xC1EE0947D3A29272ULL, 
            0x087EC0432CC9623CULL, 0xBD3D0ACA3ED7CFC4ULL, 0x603934BC97B4D634ULL, 0xFBEFC19560DE1AE0ULL
        },
        {
            0x1FCBE60664575B18ULL, 0xF6E73913F73A8035ULL, 0x8AA45FE59273F86EULL, 0x7418B19D643FC25EULL, 
            0x0DBED53CEB0FE7CEULL, 0x388361C02A494CF2ULL, 0xF421EEAFFD558DCBULL, 0x32273DC14D6551A4ULL, 
            0x883B0142D82FC2EEULL, 0x19D4D2F4D87C71C1ULL, 0x90FA6813796AFA5EULL, 0x4DB448DE5661DADBULL, 
            0x0B9FC81AE7EC897CULL, 0xCDE8BBA34CC0041CULL, 0x535AF8AC6743CF85ULL, 0xB052C23D7AFA1F4CULL, 
            0x833DC40D791C5474ULL, 0x547E92C990135858ULL, 0x136983BB35B50513ULL, 0x2B9D2DD202AD2702ULL, 
            0x303A77DB10E5E877ULL, 0xBF453E958F614E19ULL, 0x2436352F311F4425ULL, 0x3815FD75ED3524EAULL, 
            0xDEE793023DB4C249ULL, 0xEAE8469875BD3FF9ULL, 0x101CF05492C6786DULL, 0x034BCA5AFD116AF2ULL, 
            0x7C16AAEEC992E8F2ULL, 0xD215C8E24D04DDE2ULL, 0xD5A890A8F2A1DAD8ULL, 0xEC0F4CBDBFDAC166ULL
        },
        {
            0x903B160319FFF5F3ULL, 0xF42A7F4DD951A589ULL, 0x939507F93FE85A50ULL, 0xFBB9A513BAB4EBF0ULL, 
            0x244AEBFCCD55FF3BULL, 0x3F2E2547D3A2C018ULL, 0x72AB02471BDC8958ULL, 0x35BA421507C0D215ULL, 
            0xC24CF771393DD2F1ULL, 0xD6950B121D5905E3ULL, 0xC191C1146309ABB7ULL, 0xCEFED318EB49E16EULL, 
            0x2074D1A0D9A4600AULL, 0xBEF5239D83DDE0A1ULL, 0xB70F7226F245ADCAULL, 0xA6EC518DE2BB4FF2ULL, 
            0x2D73A9FD5160AFE7ULL, 0xD94AD79C56E351EFULL, 0x7635B162BFEA37EAULL, 0x2666DFFED0966892ULL, 
            0xEF40839463F65F07ULL, 0x7B9EBBA87EC7B194ULL, 0xFDA55177508885F6ULL, 0x2E83296E4F1B31C6ULL, 
            0x4CFF8A1B4BBAA1A3ULL, 0x014C4CD50B282763ULL, 0x4315CB281856B6BEULL, 0x9E28E8ADBA25B005ULL, 
            0x911DA77C1085DE57ULL, 0xB8D030719196B04CULL, 0xBFF73DBF79335C98ULL, 0xE862779E9B186306ULL
        },
        {
            0x1A9ACA88493499BCULL, 0x30E83DD665C33130ULL, 0xD56A6BE03F6713CCULL, 0x35042E9C7A3008F4ULL, 
            0x0D82AD6F98A806A3ULL, 0xF6EEA40C796854E8ULL, 0x5C3ED58F387D89D6ULL, 0xD0AF9B171043B81FULL, 
            0xB909A17BA4CBD666ULL, 0xC2BF424C4EDA55E0ULL, 0xBDB33005A29CEADEULL, 0xD1720211D92B9CE6ULL, 
            0xBFBE29837695EB2EULL, 0xFCEA3CF37ADBA6F1ULL, 0x95506489FF7A39B7ULL, 0x89DADA90570905B8ULL, 
            0xC5D65004CA2C99EAULL, 0x67F18F695232B877ULL, 0x926081F14BBAFDD8ULL, 0xFE544BCED027D1FCULL, 
            0xA027B87D4415F034ULL, 0x5037A82BA9D2BCF8ULL, 0x78266E6F479AC8AAULL, 0x27C1B1DBE9B8E60CULL, 
            0x5D35C1A4FBAA2F01ULL, 0xB1E91001DD58C9B6ULL, 0xE94C762859EEF1B9ULL, 0x22083B6CFB92CCA6ULL, 
            0xCE5362B228EB5B8DULL, 0xCE9AE61FB9CF109DULL, 0xEE70AE51C7B49F3EULL, 0x56FB023BF891DBE2ULL
        },
        {
            0xC7443B165D9D12E5ULL, 0x7EF59C1676F4E7BBULL, 0x8D9DC669E63043F7ULL, 0x84148F0B03C19BA2ULL, 
            0x4AFD554BECE0F003ULL, 0xC5D061D0952026DAULL, 0x6DC167E5287BB5B0ULL, 0xE6D7048BDB7B54FAULL, 
            0xD5BB1D9A375D6E99ULL, 0x132353CB2C3E1A34ULL, 0x0591191869957163ULL, 0x49B8059F689DF7A8ULL, 
            0xC6445D4B8EC8CF73ULL, 0x7062F72C53C1B9D1ULL, 0x867613D8249B3240ULL, 0xD6A3E8A6FD8538B8ULL, 
            0x3C25207B0903B78EULL, 0x9321C3D29211AD0CULL, 0x18AD3F7A5D3255B2ULL, 0x18551D5EB6E3EF15ULL, 
            0xD483CD6C5042F186ULL, 0xF5775E3F076BD33DULL, 0x483230C1892864B0ULL, 0x8FB0F1C942F4A520ULL, 
            0x53050DA486257987ULL, 0x36824B554892D652ULL, 0x9B560A110B683FECULL, 0x470784106FDA0670ULL, 
            0xFD359382B4CC5C59ULL, 0xE432D7A3D9BC1B2AULL, 0x9A582B3AB1B01FB9ULL, 0x0469BEC4C8F57591ULL
        },
        {
            0x6FF2A95ACCA6EF31ULL, 0xF1002B9F22E372D0ULL, 0xF1560EE53677FD43ULL, 0x38D61018B80F35D4ULL, 
            0xCE93A302D9121F1AULL, 0x9AC49132D75F363BULL, 0x4404B014834061E0ULL, 0xCE021E80B1B164B2ULL, 
            0x06CF14BBC1CDF1DCULL, 0x8A491622D92AAD32ULL, 0xD23362B0660D0DB3ULL, 0x82A7B9698B1F8AE2ULL, 
            0xF74FBBBE7528D511ULL, 0x82887B2E9A80BEE2ULL, 0x06B99CB78FC6620BULL, 0x2962DF7ED0791118ULL, 
            0x571DBC6291D4E930ULL, 0x3E0240E3E5C43519ULL, 0xB40342D547654DDDULL, 0x2BCBE02499E9902DULL, 
            0x18B53F9243FDD123ULL, 0x3A8258D33939C1A7ULL, 0x3DCA0C5F62FA20FAULL, 0x8C6AF39760973F0BULL, 
            0xA994A556A7B6AF60ULL, 0x50B7D3813E1307B8ULL, 0x50BBD6F5C0840F12ULL, 0x0E0CF11250E7E45AULL, 
            0x153FCB6AECE32604ULL, 0x84125B6F1A339B59ULL, 0x0C34FA30AFBE0536ULL, 0x16CEDC36E91D60CEULL
        }
    },
    {
        {
            0x1F546612EA5B1292ULL, 0x5556663CC2419009ULL, 0xF88C6BA427F1C700ULL, 0x3739986AB36772C8ULL, 
            0x4B4668A5B940E54CULL, 0x0A04E8B4363C99C7ULL, 0x01325416CBEDE480ULL, 0xBEFDAB190A72AFF5ULL, 
            0xAAEAFD25C945B244ULL, 0x5CFAEDF679319C19ULL, 0x738E699B11E56478ULL, 0x65D0554198280144ULL, 
            0xEBE6175B0AEFF129ULL, 0x73D5FEC4F73BF247ULL, 0x4523871BCAF58918ULL, 0x0AEB68017E698D08ULL, 
            0x7095366BD9642B9BULL, 0xC78502A08F667EF7ULL, 0x65C5D45DD3F8676DULL, 0x0E1A07CFC63AFC81ULL, 
            0xB05E8820EEF5BB50ULL, 0xCB96ABE37A8F1E89ULL, 0x314F1A60F88DD2A9ULL, 0x004F5CC136B38E1BULL, 
            0x3CA6FADE72DF087DULL, 0x2733C9B80F882D3BULL, 0xBAA573F74CC9386FULL, 0x95FA7DB63D330BE0ULL, 
            0x4C1B437D3C33FD5CULL, 0x192E59830D50A850ULL, 0x39A827B615FD8DC3ULL, 0x6C274984FB7B09FFULL
        },
        {
            0x302E6BBC3273C682ULL, 0x7F9EC19B715805C7ULL, 0xCE4A90F3F7EB21BEULL, 0xF51184D72B7AB42FULL, 
            0xCFE2C499B8E196C1ULL, 0x04C4D8C7802B1F79ULL, 0x9CD420D576D3EF87ULL, 0xD7D00E2B36F0F93EULL, 
            0xADA58409D4E1F1F4ULL, 0xDD5DD2CBA2A95F15ULL, 0xC760F0917E0B939EULL, 0x43D52B619B5ADB7BULL, 
            0x01EFF25AD06944D4ULL, 0xE6D61E815A42BABEULL, 0x731DC971189AAAF3ULL, 0x44045CDAD59BC01FULL, 
            0x4D8C687E7D2D0858ULL, 0xDCAC1C9B0A36E43FULL, 0x50CA8E7EB19A7BA2ULL, 0xD5657C4B26C3044DULL, 
            0x194EE4E5489FD689ULL, 0x7597D26DF24D41D0ULL, 0x3ED69FF880DCBF66ULL, 0x2B3E11924085604FULL, 
            0x015AA23D00D175C9ULL, 0x9E2731D6BD90D2B4ULL, 0xA6F2CD24A0283987ULL, 0x704E618CF31DABF5ULL, 
            0x21045BE33E0AEE5EULL, 0x1C1D6900FD7754A8ULL, 0x025242A49843C741ULL, 0xAE3E5BABBD0344F6ULL
        },
        {
            0x0EB2338F3858FB89ULL, 0x7FC4C02A6BDC3CF7ULL, 0x6DB1CE532EF75821ULL, 0xA019E867D101A8A8ULL, 
            0xF927FE4A1F603C3DULL, 0xFC007BFD5E69A4FAULL, 0x858C4A8A7D5B47B8ULL, 0x93C187E6798BEF8DULL, 
            0x6509D277F9D4DBE2ULL, 0xE605A833129403EFULL, 0xD1B004B2FB638DBEULL, 0xDB9EC2BDD58C0A77ULL, 
            0xEE4E285A23C9674AULL, 0xC2B6526FC7B1629CULL, 0x17CF51A8EE842549ULL, 0xC026EB8F3E38F513ULL, 
            0xBB2F6F4DF8B4E8EAULL, 0x6739C08B7F3BC266ULL, 0xDF880763E1D3DC1DULL, 0x5B2C124FBEDA66CBULL, 
            0xB2B6AB5E6909F2B7ULL, 0x15AF135B8EC93297ULL, 0x86A36AC0DC9D5F05ULL, 0x22DB5A83FCC16510ULL, 
            0x5737ECE2B7D4F51AULL, 0xDE2A4394D5C181F6ULL, 0x6DEEEADB46780E3BULL, 0x5A55BA4BB43D20B5ULL, 
            0x75820AA9584F0A90ULL, 0xBDCA26FDBCE7236EULL, 0x50E1EED36F7DA72FULL, 0x0A8C59EEEED29CFDULL
        },
        {
            0x4B75E49B81BA4928ULL, 0x314FC3C9CA8B32D7ULL, 0x12B18CD59E2A571EULL, 0x2CE7845EBB3DEE2AULL, 
            0xAC43E30FF7076459ULL, 0x3C61B549F482AFA0ULL, 0x45948273DC709FD1ULL, 0x5E325907428A6026ULL, 
            0x703FB7C6FE35DA3EULL, 0x7B0062090C5D6986ULL, 0xCA2EFEF3B67D50B1ULL, 0x75B0ABB70A0748EBULL, 
            0xC0FA6BA8AB7AB877ULL, 0xF64D3B52773F8840ULL, 0xA066DB9A5385873AULL, 0xD11381A39AC42D2FULL, 
            0xE8A5C1391A8FC49CULL, 0xDBDC1AAA59DAB1F8ULL, 0xB3CB354530ADF39DULL, 0x85509C06E38EEA2AULL, 
            0xBB460B6DC5BA62F9ULL, 0x10D472A230F27656ULL, 0xE22CCCCF502BD418ULL, 0x35A222EAA6E11C98ULL, 
            0x0E9CF7C74E8AA3A8ULL, 0x8DC16C324BB1797CULL, 0xEA417211EEB97240ULL, 0xA4DB0BC3058E325BULL, 
            0xC513ACE39B9B613EULL, 0xFC2DE06253DA8E5CULL, 0x6F01D723F5C1648EULL, 0xBD98897A495A232CULL
        },
        {
            0xC4976A450A91E660ULL, 0xC03FC0A2782D99D2ULL, 0x7D48841437D6AEA5ULL, 0x47D86ED75CD92DBEULL, 
            0xB64294A4648309DEULL, 0xD763C8E3561F1F31ULL, 0x935819577D631B2EULL, 0x578A7955C0FB1591ULL, 
            0x06E287D5D16D1C08ULL, 0x4AEAEDBED33EF332ULL, 0xF3918F7C83CA2751ULL, 0xE0686BA76CD4040CULL, 
            0x4FE7685762C68C3AULL, 0xE4A7D9AFA993E1D4ULL, 0xCD1C8970236D1ED2ULL, 0xAF93638B7659EF29ULL, 
            0x33A80338C41C771DULL, 0x0C491E2C077321B3ULL, 0x325BE9864DB247BAULL, 0x020443BD75EF87A4ULL, 
            0x230EAF9CA61A3122ULL, 0x3A23096A1804CC36ULL, 0x7289CBEA82A9281DULL, 0x448101143BBD266FULL, 
            0x126140A66836850EULL, 0xFCA34D1AF6DBFD63ULL, 0x2231AAAAD43A31ECULL, 0xD784A0C146441125ULL, 
            0x867A41E3388C01DAULL, 0xDBB0499EF26D2420ULL, 0x449C0A67DAF2EC6CULL, 0x3EB1A23FC3110B57ULL
        },
        {
            0xC4FCE1083D0642DCULL, 0x306B4D55B971EA3DULL, 0xB637E8B8775A0355ULL, 0xE6682DA735BE0E8EULL, 
            0x545751198B9B1E57ULL, 0x3DC881EBB59C2CE8ULL, 0xE41C883AD216F6E8ULL, 0x338BD224BFC51EFBULL, 
            0x19094C28F091C3C7ULL, 0xC92F85221BED5409ULL, 0x57F6612960CF2441ULL, 0xCC9D60A984685A37ULL, 
            0xD1CCCC897B9954EAULL, 0x3D5EC65CC39BCDA5ULL, 0xDEBA4590C48A00EDULL, 0x7D34833BAB33181BULL, 
            0x185DE6449331C8F5ULL, 0x311C81154B995E67ULL, 0xFF9BCF91C5C8B748ULL, 0x7852540993C53D26ULL, 
            0x292D3634D8E35EEDULL, 0x2621A584C4BA70C6ULL, 0xBAB4A3CBE8DBF844ULL, 0xAAF954952A1CE6CFULL, 
            0x90D85D29B313A1AFULL, 0x7015560D70337CB4ULL, 0xCCCAB2C1DE6F3D45ULL, 0x0EFE0820BD4EF45DULL, 
            0x370947E98BFC7899ULL, 0x1425447DB647798EULL, 0xB90104662DFFC691ULL, 0xCB13D2CF7157C85AULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseCConstants = {
    0x2F249D708383F146ULL,
    0x9D14653CC3F3E2F9ULL,
    0xA5240F8D4A0D6701ULL,
    0x2F249D708383F146ULL,
    0x9D14653CC3F3E2F9ULL,
    0xA5240F8D4A0D6701ULL,
    0x3DFD3A3B88816D55ULL,
    0x23A5067D7D36FD2FULL,
    0x61,
    0x7A,
    0xE0,
    0xEC,
    0xFE,
    0x2B,
    0xE5,
    0x04
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseDSalts = {
    {
        {
            0xBE323C19B74D5C53ULL, 0x03D2A1A88C6B8750ULL, 0xF20B8B36A804AD65ULL, 0xEC0C62D082298534ULL, 
            0x12C20B778353D82CULL, 0xE3887836225D5294ULL, 0x8148CC5A385D67F1ULL, 0x5C4FE1ACE97437A5ULL, 
            0x10AB8AC427995CB4ULL, 0x7A721A7712C22B34ULL, 0x214D1864FCD6F48CULL, 0x65FB70E6BC5D71FAULL, 
            0x2064C715DB0AE585ULL, 0x13CCB2177E15F2CCULL, 0xE5F12AD3249C9473ULL, 0xF123A5D5DD920C41ULL, 
            0xFF01C5B51CD5630CULL, 0x51307FDFBA02A70AULL, 0x4DADF36AEAC69A2CULL, 0x8013A5DC23CDA7E3ULL, 
            0xEEEE57E304679F07ULL, 0x9AF8C0FB32A3C73BULL, 0x1473D6C1E30C8819ULL, 0x112E266A68D2E3D6ULL, 
            0x3AC1E3591BD7E491ULL, 0xD17F3FFC8833C53AULL, 0x0BB5E29729018DA0ULL, 0x540A95A8A2D13976ULL, 
            0xD96B3152656C0C97ULL, 0xAD70A08AB2B79C73ULL, 0xE76E0108C8C995A9ULL, 0x6393593DDBAA56E7ULL
        },
        {
            0x01E3BA7E171C1D1FULL, 0xA84DB37E8B40AD15ULL, 0xC2EADAFF9202CB90ULL, 0x01723254F4CFBE56ULL, 
            0xA8BCC9C7D0C1289AULL, 0x755708E927B3372AULL, 0x882C4B8445602B13ULL, 0x882D5F91F897C91FULL, 
            0xDC5AD0878863CC3FULL, 0x5034EC3FE0D74492ULL, 0xB4151B32FCC15E43ULL, 0xA2D8E0A5BE9DD570ULL, 
            0x926932BE742C13FAULL, 0x8E310B98E3E817F8ULL, 0xF64EF17F6B703541ULL, 0xF94119BE090B5E4FULL, 
            0xFD0B392E268FC05BULL, 0x4C17A91C100857AEULL, 0x8A28B8CE083A9AE3ULL, 0x345823EF636546F4ULL, 
            0x55134C51EC4A590DULL, 0xAC1415CB7DAA10CAULL, 0x71D2CF1882CC73E2ULL, 0x17ED4A4221A266E0ULL, 
            0xF9018CDB81F283EBULL, 0xE5A643BAE859CA1EULL, 0x4F2BB4A4D3D94C9AULL, 0xF1B376BF27198933ULL, 
            0xE5C492A2BE0C3219ULL, 0x2A41EE02F0BAA325ULL, 0xEE415D62AB630DD5ULL, 0x1CA1ECE759DF4644ULL
        },
        {
            0xE9ED7DBD4211FD86ULL, 0x2817EE1C5CA50669ULL, 0x755FC9D43DFAB9B7ULL, 0x0C468CC04491FC0CULL, 
            0x5C471335A263FF3EULL, 0x46F712EE0EC56665ULL, 0x2F1B5EB2AB3A0E9AULL, 0x38A232B2C4F5D73EULL, 
            0xF79D68700956625CULL, 0xBE8AB4420ABA53FBULL, 0x7A47580595500DE6ULL, 0x3F8223B54B951AE3ULL, 
            0x8ECE9FB8EE333235ULL, 0xF6D7BD17C1AC2307ULL, 0x518800C22F01C8A2ULL, 0x6106EDD3269BC1B2ULL, 
            0xA05E6A139D32DCA4ULL, 0x6C9846C3EF75C3FCULL, 0x4E4CCC07C67DFE58ULL, 0xDF3C95E5F98F908EULL, 
            0xC91937A39B7B636CULL, 0xEE11559788F6AE71ULL, 0x168570641A8A5B74ULL, 0x19EF198263D53BFEULL, 
            0xDB0A6379910B0C04ULL, 0x5AD215CECF62F721ULL, 0x45672F953E11531AULL, 0xBD6A967CB02B1FF7ULL, 
            0x6C23CBFB6CC72BD0ULL, 0x5531CAF9DB2FA72BULL, 0xC4BBAE61DC2AD801ULL, 0x543BEBD5B079EE47ULL
        },
        {
            0x1B876CDA82960D56ULL, 0x1E267D9E9CB224E1ULL, 0xDB754468FDDD358AULL, 0x66D854C456564A7FULL, 
            0x3A20F2B8F77769E6ULL, 0xFD8B220183FC4A15ULL, 0xA72254DACFCE53A7ULL, 0x1C6F0CB5E2F6AEA1ULL, 
            0x8C096DF10A43E3DFULL, 0x19C8F9DAAD5FA4EAULL, 0x83E529149885D0A9ULL, 0x8373986FBBF97161ULL, 
            0x77CA5E5AFE247ACDULL, 0x50A24B335A53A4A6ULL, 0x9BF3367DD8A055F8ULL, 0x081D1EA6DFC5D1E9ULL, 
            0xB3E5CC111D26D20CULL, 0xC00D493D8E3477D1ULL, 0x07A37A4AD10511D4ULL, 0x172490F60E6442BCULL, 
            0x522CBD57F2646637ULL, 0x72377DB166C23B78ULL, 0x9B0D54C313B04C0AULL, 0x4AB7E18F944A76EEULL, 
            0x97010A337FAD641BULL, 0xDD4CD72F0EB60D69ULL, 0xBBAF0950FB57682FULL, 0x5B6850660C964D08ULL, 
            0x2E46C54B41AD7C41ULL, 0xD756D9E7B29DF4D6ULL, 0x4E9EC5AA3C057197ULL, 0xBC194950F3F2B13DULL
        },
        {
            0xD1EFF6DA04A7DCB0ULL, 0xC694F0B889F39D56ULL, 0x4F6698F41B628D8DULL, 0xD74D56DFAAD702B5ULL, 
            0xAAC975E278EA5031ULL, 0x14642B7F02CE8DC0ULL, 0x35F75CCE0C76E415ULL, 0xE29A431B092ED33CULL, 
            0x931F9A1CBED64BEEULL, 0x9C1B027349A24C2BULL, 0xB45699C62026931EULL, 0x36209DCF96CE0B5CULL, 
            0x91CD6F50DEBD22A1ULL, 0x47DD7B73B025737AULL, 0x71D60450CF6B0444ULL, 0xE91D6810BDFD02F5ULL, 
            0x0FCAAA9674CDE62CULL, 0x0AA991BD578D8421ULL, 0x5286290E2DD97198ULL, 0xC39362D4B7BEB71CULL, 
            0x674BCA513AA5B109ULL, 0x8BA6CA979FB5CFB6ULL, 0x97237ED1C99A0087ULL, 0x6B81E8FD652F3226ULL, 
            0xDC2E312D68C6E154ULL, 0x82F4E3D84578D877ULL, 0xB343848BFFDCCB67ULL, 0x946A377C3F25B00EULL, 
            0x1A98952D3919762DULL, 0x860337C402488FE7ULL, 0x97EE8062AAACAD82ULL, 0x672782385B6FD4D0ULL
        },
        {
            0x0C37C88B660B89A1ULL, 0x50BEB86B9A17DC36ULL, 0xBEF54EE905B1637FULL, 0x378413A809DA1A7AULL, 
            0xEC3097E123DD33F3ULL, 0xC6B38C72DAC00BD9ULL, 0x62B3B707E0EBF4FCULL, 0xA7CE530F4058C8E0ULL, 
            0x1398597293DBEBF6ULL, 0x2E82A93585FE294BULL, 0x9C1FC66BC1402841ULL, 0xAF9A133AD605DABFULL, 
            0xDAB8E32201675195ULL, 0xC8EAC84A8ED7A14AULL, 0x6F548500F8694DD4ULL, 0x2F5606B30FD8ACC6ULL, 
            0x76202524A1C7F79DULL, 0xFBD25A174DFB3401ULL, 0xFA8BB7C1ECEAD4A8ULL, 0xA6A6AC03719B8CF9ULL, 
            0x8366BE4606305BF6ULL, 0x87EB1BC28E01BB93ULL, 0xCDC9A05563C3282EULL, 0x19EDD7156B87F6B1ULL, 
            0xA244D7821057B691ULL, 0x05A16D5FB89734EFULL, 0xB0F669967C4E3CC0ULL, 0x2406B6563259376EULL, 
            0xAD99B62C47A065ADULL, 0xA9C354087F57CF86ULL, 0xF93A490E6DAA53EAULL, 0xD0FA75F7917164D5ULL
        }
    },
    {
        {
            0x6A50D5A1E6E91A85ULL, 0xE68DDEB5DFA57288ULL, 0x1E206BB73C595F3BULL, 0xADAECA2A370052A3ULL, 
            0xF7E4A6C0430A40FAULL, 0xD1CE00F987FB411EULL, 0xE9108B3F0F5E3F2FULL, 0x0DA7A9618A1B6DDDULL, 
            0x1894A70BC6008FC2ULL, 0x0E08DA1D743D887AULL, 0x85618225806BAD51ULL, 0x947692A85DD24509ULL, 
            0x99EE08DB2F5E6BD8ULL, 0xBEC402F79A3462DFULL, 0x4843663DFAF49FB2ULL, 0x9BB954435DD2757AULL, 
            0x60666D7B8B51874BULL, 0xAEA05C820A30D73EULL, 0x7C90303891647270ULL, 0x3527460FEAF4A9F2ULL, 
            0x017734A4E94B1A98ULL, 0x20115BDA34EE0B82ULL, 0x526A94258B4EFB7BULL, 0xB4723A7A96889781ULL, 
            0x042B73CE4DF5D541ULL, 0x321C337B51A39AAFULL, 0x50A9EAC4EB20E9D1ULL, 0xBE8FC6E407142C61ULL, 
            0x3A73E06469BB4608ULL, 0xF6319F6C46B3B0EAULL, 0xF2CC203C175FA7B2ULL, 0x7B25B390938BFF96ULL
        },
        {
            0xE9F3DA0D5B4982E6ULL, 0x329C69CE82E2D8FCULL, 0xA8E4B3F5605E7899ULL, 0xF041FE50413F5F1BULL, 
            0x1087F904A9952906ULL, 0x7256C95CCE8D0FFFULL, 0x767B272D6C14AE7EULL, 0xB33893716543E9EEULL, 
            0xD427E058581A80E1ULL, 0x21B96D051F5CD4E2ULL, 0xA0CA668EF145FF55ULL, 0x436C2CFECA20C0DCULL, 
            0x7BF2038479A32141ULL, 0x9616D2C75B2C8A2AULL, 0x0AB1F017C7809BB8ULL, 0xE587B7655E4EFA66ULL, 
            0xDDB602622911C89EULL, 0xA6C3FE1DAF373062ULL, 0xFE38386CAA6E9A0AULL, 0xB3E963740E7A96A6ULL, 
            0x162E3BA43C244D1CULL, 0x0F524A8AF279EB02ULL, 0x9BA23A129DE6E15DULL, 0x8C5A6D6F9F9F601FULL, 
            0x87683AD64670AF29ULL, 0x3281920842552364ULL, 0x8F3D9C9C82EAD1EAULL, 0xED0F2AE20CE51860ULL, 
            0xC8E9C602DB9F88FAULL, 0xF6463E0ABD5631F4ULL, 0x65EA166F783B9D5BULL, 0x66A6A85C82548DEBULL
        },
        {
            0x70A0AE4DF6344CF2ULL, 0x2626C405D3EE573DULL, 0x005E9F47EB9C7127ULL, 0xB787AFE224238DDEULL, 
            0xC44B69826152F775ULL, 0x05270EF01A2EA3D5ULL, 0x2C32C45DB2DE0C8BULL, 0x5F4874850805DA01ULL, 
            0xF61E483CB8BB57B4ULL, 0x6B6DD01DEC8709E0ULL, 0x2894D5FBC80BEF47ULL, 0xF951EA1D1B403AF6ULL, 
            0xEA62CFEC21C5DBC5ULL, 0x17CD74A2F4485EDEULL, 0x116295C386FAB88AULL, 0x6E56AD6AB164FF8DULL, 
            0x1F05F3C600507B92ULL, 0xC0DF4B2B6832AE65ULL, 0x6880437F5FD877F2ULL, 0xF37F66E0E7A97879ULL, 
            0x896775A98B1163B2ULL, 0x7EE13F4A24EB131DULL, 0xB936A09A390BF25DULL, 0xFEFFBDE165312388ULL, 
            0xD0B81F6C44323207ULL, 0x62A178837BB9B27BULL, 0x5C63622642C71A8AULL, 0xD253C4C48C8EB09EULL, 
            0x045EEAAEC2CE71ACULL, 0xC13997E7E4D9EF15ULL, 0x103494D40A4B125FULL, 0x5449E169C9CB84D0ULL
        },
        {
            0x4374A4521EBDB159ULL, 0x4702827A29CA8989ULL, 0x86B0D137D0C9E310ULL, 0xECE6ADA34032F87DULL, 
            0x8FCAC04B713BFF7CULL, 0x56434D4C56844102ULL, 0x6FFDAEC9769F28DEULL, 0x97EB685629A2A9E7ULL, 
            0x0ED9E514AA8055DCULL, 0xAD5B5E3F83AA21CCULL, 0x07CEE2241F49BE5EULL, 0xF4A914383BD61231ULL, 
            0x1E5DB009E0EC39A6ULL, 0x52485CE2B9013D30ULL, 0x4F0E48769446F78AULL, 0x0605376E0912B107ULL, 
            0x995263CF0C9C2F27ULL, 0xB5F4E759B493722DULL, 0x1AD104E8D363B922ULL, 0x87F803E9A12C2CACULL, 
            0x24C643214277E51EULL, 0x2B7FC8E2F096D859ULL, 0x1179E73952ACE1FCULL, 0x3C5EC4C994698E5BULL, 
            0x91D9059807595798ULL, 0x1688B3B22F4781CEULL, 0x0ACEEB9C42783FE2ULL, 0xFD09C98ED3B2CE54ULL, 
            0x0BCD21CBA87E2C58ULL, 0xBC17790AE1369188ULL, 0xE856715327B4512EULL, 0x2EBD8665B9BBA30BULL
        },
        {
            0x5951A1DEA5780390ULL, 0x86DD726C120CD9D4ULL, 0x409A32281601C9DCULL, 0x150077EFBA426C2EULL, 
            0xDED5099AAA902D28ULL, 0x19686D308932A0AFULL, 0xC1C4A1D5D87ECAF0ULL, 0xD8C39EE464287784ULL, 
            0x8B3EE0AFFF9A3C72ULL, 0xF3F9154AD9F91940ULL, 0x92BBFEEDB2908281ULL, 0x5A350D844FE7A3E5ULL, 
            0xCFA481C11191984AULL, 0xC63A07FD0E02B7F6ULL, 0xC49E26C4E99F7022ULL, 0xD7FDA70D5CE48E2BULL, 
            0x49B08C8C977B951AULL, 0x927ECAFA06D06A3AULL, 0xF9F0FDDEA8CAD74AULL, 0xCF0F7FB3EA54A0E2ULL, 
            0xDA3D0566090E8748ULL, 0xE09FAF0C78AA38FEULL, 0xBC1836200264861AULL, 0x3053DAB1DFA5ED44ULL, 
            0xCF928F4810CFF922ULL, 0x994AE7B35FD87A6EULL, 0x4A3576BD6F83AEE1ULL, 0xDAE09B75010F08D0ULL, 
            0x009B34C463E5B8E6ULL, 0x069DE712B00BE656ULL, 0xDEB435ADAC373C67ULL, 0x80F7164511AC3A11ULL
        },
        {
            0x9C9D39B1CC35E6F1ULL, 0xCF48F633BF7B816AULL, 0x0F812DEF16912263ULL, 0x3AA87A0363AB632EULL, 
            0xA695D03F62EB76DCULL, 0x452F6B1150160822ULL, 0xA39A3D4A2264D87DULL, 0xBA1385F6F0904973ULL, 
            0xF8A725F405BF317FULL, 0xA22ABEBB2495F5A3ULL, 0x9B6D1D4F92C1B5B5ULL, 0x4B54FBB684173414ULL, 
            0x4A154D36B708465FULL, 0xF913E4E5F499D725ULL, 0xBBDEB512C144ACE2ULL, 0x5129CF32707C23D9ULL, 
            0x93921786944CF838ULL, 0xFD74151BACF1B1D4ULL, 0xEB5E955E3BA9C3C8ULL, 0x420DA7FFF81AC6E2ULL, 
            0x1C29357FA537E3E9ULL, 0x599EE7B48D1055BAULL, 0x80E84D94CD528EC7ULL, 0x398449573104F5CAULL, 
            0x8C8A09FF6CF81DFFULL, 0xB8013FCC0B4B9385ULL, 0x3044ABA5EBB6E819ULL, 0xE8F518BA7B5819C4ULL, 
            0xA9B4FE17F11ECDB8ULL, 0xFEC23BE07746F070ULL, 0x3E317EAE170103EEULL, 0xEC9D46E189C9B8E4ULL
        }
    },
    {
        {
            0x62E375D25A997DD9ULL, 0xFABF103EBCB15ED9ULL, 0xA5734EB2846AEEA0ULL, 0x80E1FFFD5B4B3BBBULL, 
            0xE99CC200A0FFCA2FULL, 0x29CF0D2C2E7AD89BULL, 0x4633697B2E63E220ULL, 0x1711C0C20D9ABC70ULL, 
            0xE1FF71C3FA19C92CULL, 0xBA45B0F42A9DA320ULL, 0xF0FDDD2F07E83355ULL, 0x335300A4A3C19108ULL, 
            0xBE35F8F2EF7C4D0CULL, 0x581B4E8CB660DDAEULL, 0x565C38AAE7FF9055ULL, 0x067298D9BCDC6350ULL, 
            0x60C4DD7DACF0AD5CULL, 0x25D06EC4669F0ABCULL, 0x8421113A3AAE0E96ULL, 0x65492D576BB233C1ULL, 
            0xABFB514D7849DFC8ULL, 0xF3916F93BEBD2D83ULL, 0xB71D664D6CD2B123ULL, 0x5816AFA1CC5E4453ULL, 
            0xDBE1685A9B1DD5BAULL, 0x557ADDBFCF107E9DULL, 0x18BF9C3F16691B73ULL, 0x36ABA3C61251848AULL, 
            0xEBCA93D3F34B5FBBULL, 0x8FDB1F8682FEC439ULL, 0x8C25772B3C678894ULL, 0x69E1DBAAF3885AA2ULL
        },
        {
            0xD29B1B1CE66E3B24ULL, 0xAF838E092192D2F4ULL, 0x9C36ADD3506A5A89ULL, 0x3E8F71EF99C9F377ULL, 
            0x913247A0F2DC7194ULL, 0x419E553BD10456E3ULL, 0xC719ED3D231A55A9ULL, 0x4BDBCE01AA9F43B5ULL, 
            0xF0798C07A48E55D2ULL, 0xFFE171AB6DBDF530ULL, 0x2C8EFCF64345A3E0ULL, 0xB0026DA38A8D5796ULL, 
            0xAABD4C62BD3442C6ULL, 0x7382091C675B7CF9ULL, 0x4BAADC17A6E046ADULL, 0x1D8C986A7A321951ULL, 
            0x8FC9BFFD763F0912ULL, 0x24E9B0DE065BCAB9ULL, 0xA09A6500112726B4ULL, 0xC296E3385814CAB8ULL, 
            0x63247C74F7E2769FULL, 0xE86AE453DAF7D77CULL, 0x1D2A47A22B2DE075ULL, 0x62523B7311CD0359ULL, 
            0x3FA3733DD16C677BULL, 0x9857E5CE4BD3942CULL, 0x9CEBE127A9B8F2A5ULL, 0x289C7E9B45879779ULL, 
            0x323F70894B1C3D86ULL, 0x7D1A1B54BCEDEB04ULL, 0xAD04106E26057265ULL, 0x477512DAA3E2997FULL
        },
        {
            0x334142D2D884810AULL, 0x4A7E487C0CA07E3EULL, 0x8E1D3FB002AF15D1ULL, 0x6049CEEF86C2A856ULL, 
            0x529673EC159E4BD1ULL, 0x22F04472FEF0D234ULL, 0xF25A570A98EF39ECULL, 0x923CF1749F7C7C79ULL, 
            0xF446ABED2BD6F5B4ULL, 0x4AEB6822EC987C95ULL, 0x6BF863D4B4C627F1ULL, 0xAFD803C9151D545DULL, 
            0x937BB1836F75542CULL, 0x6840B68880537E03ULL, 0xDDB15958AD726069ULL, 0x5FE25559D8CB9269ULL, 
            0xB21458BF69FD1505ULL, 0x5470D983F5C35B66ULL, 0x6A43CB2BD936EEF7ULL, 0xF4CF6C40C89F44EAULL, 
            0xB1C6E276013E3265ULL, 0xE7D615130E8AEF58ULL, 0x68938A7FC70A93F4ULL, 0xDFC9304FEC1621E5ULL, 
            0x6E8728913B138006ULL, 0x3DE7CB71621E215BULL, 0x920BA925385AF8DDULL, 0x10F7B8D1670F4C47ULL, 
            0x8C2374AB14DCA181ULL, 0x95667D0A2C57B24BULL, 0xD8EB917C9D56BD58ULL, 0x113AD5BE1CF69619ULL
        },
        {
            0xD163DB8A1AF7BA0BULL, 0xF1D2C9606AEB4C4EULL, 0x802923026E975625ULL, 0x4F9662114E587B8DULL, 
            0x80C9F3EC1A76BE9AULL, 0x789C32310DE23663ULL, 0x2EACEE87C748DB83ULL, 0xC6BAE4CEAB01D72EULL, 
            0x27724EA552FE1916ULL, 0x72564568307C6AE9ULL, 0x016592BB5D8BC7DDULL, 0xE058D0FEBC7014D7ULL, 
            0xEC53BA47D9498770ULL, 0xC367ECF2416D7203ULL, 0x6B207D8782FFC5F5ULL, 0xD5BEABCE57E8E7ACULL, 
            0x40449354D9AC96C5ULL, 0x96AE36AB2CCC2EF7ULL, 0xBF7C2B86F58449D5ULL, 0xBF3238212703233FULL, 
            0x2B111013B74170DDULL, 0xE59F43E16390258AULL, 0x0D7CA02F7DEB1D70ULL, 0x0AA2CDC8EF3514DDULL, 
            0xD886FE8E770CDA9AULL, 0xB8E468F4FDEB1CC4ULL, 0xF199F91CED948C24ULL, 0xB5B4F3AA88E76310ULL, 
            0x140ADF085E7625C5ULL, 0xC8D06DB20FBB5028ULL, 0x7925FAF711E85000ULL, 0xBD13992A01F43DE5ULL
        },
        {
            0xDECAA9473EA12B3BULL, 0xAA5A67A4D32852D1ULL, 0x7019DDF8BCF24853ULL, 0x68C6451A0BA6F7AFULL, 
            0xAA5B98D9F6685B8DULL, 0x3972988CC8595C1DULL, 0xB4A6310141ED1ADFULL, 0x6124A8EF16FE9183ULL, 
            0x6682AA75AF29C708ULL, 0xBBF3DA2976D61CA6ULL, 0xDBCBEB9AA09592ABULL, 0x91B135C8F702AA0EULL, 
            0x2D2D97097CE9A589ULL, 0xFD220C98B96205D9ULL, 0x03F08040D855997FULL, 0xB0B79D4840C61158ULL, 
            0xBFA1C437A125EEEBULL, 0xDEA722C79295876DULL, 0x06754E73A6716E3FULL, 0xCEE90C8C32395112ULL, 
            0x4DDF83AEF60FA6E3ULL, 0xCC81026DE20BE4AEULL, 0xB3D1A463684E68F2ULL, 0xB0768A4C9F6BF439ULL, 
            0xDA1D61107BE0D935ULL, 0x65293EA76847FDF5ULL, 0x48658A4033D5FDACULL, 0xFE079351A7EB8A3DULL, 
            0x7DF9B107B340A777ULL, 0xF6B6FE5EFDE23FE8ULL, 0xAA9BD297669434C6ULL, 0x37009A12297C678AULL
        },
        {
            0x9BC54899FE7F4AA9ULL, 0xAF574EC41DF56253ULL, 0x3931C531C85B253DULL, 0x682E77D69C26556EULL, 
            0x2B4001532D980266ULL, 0x61E2D0CCA48A9816ULL, 0x90A666204CF012FDULL, 0x249776F6F68E2818ULL, 
            0x173FF0ED4824DD45ULL, 0x293EB2BACFADD735ULL, 0x943A9591B72427A9ULL, 0x7FE706815B1F016CULL, 
            0x6E98CF268A89642BULL, 0x09D770B0F1206C46ULL, 0xAF79A8C8FC7F7B8EULL, 0xCE509C86E70AF63AULL, 
            0x6ADC44EFA90C00E3ULL, 0xE9F82B9F251BC4A4ULL, 0x949C04CFDAB0D113ULL, 0x5A0A6AAF0BD6F1AFULL, 
            0x5398CFC81351A5B6ULL, 0xFC2AA4299CC58FFBULL, 0x2C9782269660B16FULL, 0x4D003D6FC31A6CA3ULL, 
            0x014D219A857957E8ULL, 0x4C6C17AF9FA057F7ULL, 0xD8DFFF3F6682BDCDULL, 0x7DC4A704483363D5ULL, 
            0xCA89B5CDC08EBC67ULL, 0x78276C21CB63BA75ULL, 0x6CFA0E91A2F624EDULL, 0xE937AE4FBBBF948DULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseDConstants = {
    0x9A74ECB59DAD7884ULL,
    0x5920C879796447FEULL,
    0x9DD6246FC953767EULL,
    0x9A74ECB59DAD7884ULL,
    0x5920C879796447FEULL,
    0x9DD6246FC953767EULL,
    0x3055FC7111B97FC9ULL,
    0x134150DB79A81470ULL,
    0x4B,
    0x35,
    0xFF,
    0xA7,
    0x03,
    0x0D,
    0xBC,
    0x1B
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseESalts = {
    {
        {
            0x5C636DC9A9034738ULL, 0xEEE03B7511D84383ULL, 0x7DA91F007B195383ULL, 0x1FCFA7BC3E1C31B5ULL, 
            0x3C98CA6017F87E39ULL, 0x0A53D8C31EDAD97EULL, 0x68F2A12BE08B3291ULL, 0x2A20D141456A883DULL, 
            0x91930EE5C2547A57ULL, 0x3745FCE841D94404ULL, 0x64AD9DC90747464BULL, 0xFEAF2FD7E7769EDFULL, 
            0x6CCDDCF2A70CAD1FULL, 0xC5DCEEA1EB13C976ULL, 0x610295E437D348C6ULL, 0xC6DD3E6ABD699C5FULL, 
            0x499504B5AE73EA3CULL, 0xB9F2F35CA30403D0ULL, 0x1CD401B275E5AB79ULL, 0xE6089506658F9DC7ULL, 
            0x7BBD6E1B9C4030E1ULL, 0xE62AA38F880A1FBBULL, 0x2C2CAA2CB22256A6ULL, 0x79D07CE6E10BEBBDULL, 
            0xC66F594DDEB4E5BBULL, 0x0D1735EF74358A72ULL, 0x277BC313E43D91C1ULL, 0x55A5593752E5F5BBULL, 
            0x250D8611C4AD1EEEULL, 0x097D5B2446F9F0DEULL, 0x6D40BD379F1C41E9ULL, 0x75C69CF7B95A46CEULL
        },
        {
            0x38B360234C7945FEULL, 0xFC7C447A248BD567ULL, 0x1977D46A32879224ULL, 0x2477451C3912DDF7ULL, 
            0x8F0A1C8B76CE2335ULL, 0xB737188F83E7D698ULL, 0x13F39DA32C42D4F5ULL, 0x631529ABE341A93FULL, 
            0xD699D4386D8623FEULL, 0x3271EB2A181EC2BEULL, 0x03B7F129C5EBB830ULL, 0x56E84802CD21B2AAULL, 
            0xE64FC85AB4FC5123ULL, 0x2509419CA3D3AE26ULL, 0x0072C1EC0ABBE356ULL, 0x6B90851CE2069CC8ULL, 
            0xEFB9BA6AD124609FULL, 0x3003D58B91E5DA6BULL, 0x5132140B71CB6BBDULL, 0xE975B864E38D9FDCULL, 
            0x2FC0D577D9EAEAADULL, 0xD26F15BA33584ABDULL, 0xC5B63F1F4A2AE93FULL, 0x36DEFD6BE7FC0820ULL, 
            0x4282B61C3AF5E869ULL, 0x8F3990459697FCC0ULL, 0x1613EC0847AAF130ULL, 0x79F41E3235E17476ULL, 
            0x2FA085B8000A2103ULL, 0x195880A74F22091FULL, 0x6ABB5B467F3994B0ULL, 0xF468DA619A27F27CULL
        },
        {
            0x6F579CB89BA8AEFDULL, 0x46305B3742A349EDULL, 0x85B3EAAF24A1AE26ULL, 0x47A423664E3A6175ULL, 
            0x859ED110EF2578FCULL, 0x38A886CEF0B5F495ULL, 0xBF97F4C9C631C320ULL, 0xB793AB75689F0364ULL, 
            0xD89C415BB5B4F8D3ULL, 0xCA1626DCBBFD8FB1ULL, 0x3E043C9C4C722F16ULL, 0x643F098EC5ACC0A4ULL, 
            0x3D85FD745B691170ULL, 0x3578C5226BD09006ULL, 0x2FAF4CA898E5A190ULL, 0xE69A42200273BCFDULL, 
            0x37FF5F3E5A4B87E5ULL, 0x510275DDB70EEE60ULL, 0xAE7538057A18AF7CULL, 0xBF11D45F9C8B3592ULL, 
            0x13B63E59B9A03FD6ULL, 0xA79F3D4BDFA14335ULL, 0xB322259B37395563ULL, 0xA47DAEA33F1AF2D7ULL, 
            0x59F94E64C147D2CAULL, 0x43B9B6F957C75E20ULL, 0x7371EC63D9C4AE67ULL, 0x17352E8E787B671EULL, 
            0xB2A97A78E7318889ULL, 0xC926A10F76F84B35ULL, 0x6A4CDAD1CE992613ULL, 0x7FEE01DF3A73D6D8ULL
        },
        {
            0x5E29EF27DA6A5E87ULL, 0x35919B853B02293BULL, 0x1D4A0C0F7856787DULL, 0x037E6D687297903FULL, 
            0x94BE56A7B6F0DEA4ULL, 0x3FBDCD40719D84F9ULL, 0x82BD07AB5EFE4076ULL, 0x74AC33174384A462ULL, 
            0xB755C8A148BBDD30ULL, 0x380EB34D57CB8CF3ULL, 0x54912FDA9F940B6DULL, 0x41EFBCFF8A0211FEULL, 
            0x572529A55256DE6EULL, 0xEE2D724FF5ACC6E3ULL, 0x290A4DA11CFC9298ULL, 0x3625CDB994F426CAULL, 
            0xF0C608BF1A4263CCULL, 0x3219B7C13FC137BAULL, 0x468AB24B8DE4FC8AULL, 0x2029A8D8AAEB89BFULL, 
            0x11B4912CF5024CB7ULL, 0x178DED8F6C646ADEULL, 0x66364FDE29F1363EULL, 0x04C5679AC1B8D8BEULL, 
            0xD6B9A8DFF18E6663ULL, 0xF29A38704A445E5BULL, 0x22D60B2320441274ULL, 0x62FF3D7B8A529987ULL, 
            0xD848EA3E97B53156ULL, 0x97D668F20E3E19D6ULL, 0xA02FF33A637ABA97ULL, 0x2553A4C443AC4762ULL
        },
        {
            0xD4CBE4CFEA482201ULL, 0x87A6C2BD868A13C0ULL, 0x84D3C243E5B1D6FCULL, 0xD8F7631BEADB6D05ULL, 
            0xBA93186BA2DAFE50ULL, 0x0B1C6D887559E69FULL, 0xF885063BA87F844EULL, 0x4CB28CEEFF5D864AULL, 
            0xF1C9C2455C62663BULL, 0x9A8E57615CFEDAD4ULL, 0x4935841B5CC58924ULL, 0x28EB27487AE7A1D0ULL, 
            0x2F6E4EBE5C91F85CULL, 0x285754CD3AF0EBE5ULL, 0xEC309CA6FB6F00FEULL, 0xA0BF76FFF9E025DDULL, 
            0x415AE329A680082CULL, 0xA96A5A528ABFF58BULL, 0x396653CE344518E1ULL, 0x9B4D656C7EDCE811ULL, 
            0x687BD72EB25BE821ULL, 0xC7D908B3F3B68F17ULL, 0x4131982B944DAF01ULL, 0xC72830786FFDC410ULL, 
            0x7F406E0CA1CFB80FULL, 0xEA0B806D1DA590FDULL, 0x117FE6408E62A4A0ULL, 0xFBFC64621EB97EBDULL, 
            0x582482D89AF4CE1BULL, 0xA6EB20A0C00BC1E6ULL, 0x5FDB08D8F7B02CEEULL, 0x03AE5EB6272A5862ULL
        },
        {
            0xAD74B835CAB01C8EULL, 0xB0B28792A0EB2A8BULL, 0x3D787305316A7045ULL, 0xF131E9B4CD6D59D5ULL, 
            0x2704A676D54D7DE1ULL, 0x56931EDC8072D357ULL, 0x5AEB0547E291C315ULL, 0xAA541D9114271061ULL, 
            0x25AA20DB9118C0BCULL, 0xEA0D406B91894474ULL, 0x7B8DC4C73ADE36FCULL, 0x43CEDE4EAA485C17ULL, 
            0xAD2D296FF7A66A16ULL, 0xD5E6737C51673F8BULL, 0x1649F742DA4CF11BULL, 0x84BB854438A2FE5AULL, 
            0x11CAC6A9EDB266A2ULL, 0x4FF6370CABD0CCE1ULL, 0x1C5B76B99718FC69ULL, 0x0B2ADFE1DD52A13AULL, 
            0x6E3264ABAE2A1EB9ULL, 0x504F43A9091C8D83ULL, 0xC03B6AC847524E4AULL, 0xFD5EB1D3761A5EBBULL, 
            0xCE66BFF136D15238ULL, 0x53AC7101324BF659ULL, 0xAB885DFF66349C8BULL, 0xF65A8C4848E84DDAULL, 
            0x0AA711ED2B960ED3ULL, 0x68A4F1ACC251DE4DULL, 0xF75ECCF44485502AULL, 0x447FEF16560DC2D7ULL
        }
    },
    {
        {
            0x5CCABC09D6BB1511ULL, 0x8852CB9A40A1B422ULL, 0x474DCC66004661E8ULL, 0x272C4C6ECFDD0299ULL, 
            0x7E6977C8D9DD6140ULL, 0x93797D374575ACFFULL, 0x4D995F689DBCEA69ULL, 0x9907C50758F380EAULL, 
            0x76208149EF4E125DULL, 0xBF2AA34376BF822CULL, 0x7AC44693AF8645A6ULL, 0xFAE95CC696A05214ULL, 
            0xB65420E30AB35B7EULL, 0xA55EDD96072336E0ULL, 0xA0714B67C9078307ULL, 0x754B0511EE080FC5ULL, 
            0x99AC249FE51CC42EULL, 0xB567AE21415D915EULL, 0x487580BFBCD8EC2FULL, 0xC7F334083C7F6D22ULL, 
            0x9F9E3211EFE6D06FULL, 0x63CE630E25BA9E7AULL, 0x18C1F9EAAA42F092ULL, 0x9AF368580C648B27ULL, 
            0x598DD1330161C4C8ULL, 0x5E5F6F3F798086D4ULL, 0xC5BB53B3B661B751ULL, 0x0BCBE19A1DF3338BULL, 
            0x88A1BF9B5C303147ULL, 0x01243A337E673FC1ULL, 0xDE0AFB181BD3C67FULL, 0x67ECB362747C2915ULL
        },
        {
            0x1B2E45EC51A08C74ULL, 0x23A8B933EA4C5795ULL, 0x4EFC39D6CBD40CBCULL, 0x90E556634205902DULL, 
            0x528E1A29FDA25F22ULL, 0x69F5EDA40881A0ADULL, 0x9C46A63922077E24ULL, 0x0994B3F8100BB14EULL, 
            0x6AC9C4A2C0810D4CULL, 0x35FDE8FC6F7005D6ULL, 0xE7D0D6B2EA41465FULL, 0xF48CAD7EB0D61A51ULL, 
            0x4D807FE32B642C79ULL, 0xA570EE5892707931ULL, 0xDBC8C7D32A20BA28ULL, 0xC77DE66ED46FD894ULL, 
            0x822B06458F355399ULL, 0x609BEAE043CBCF94ULL, 0x778FA0824CC7CAE5ULL, 0x9A9D85AE3B51EE81ULL, 
            0x9B6F9502A41BB6B7ULL, 0xD6028DA646E98EEDULL, 0x486A599FAC94FA00ULL, 0x7A346A5CC585F9B0ULL, 
            0x762ECD140B55A552ULL, 0xB0C49F72A1E09657ULL, 0xEBCCF34A5AA669D3ULL, 0xB098A7CE744E2E4CULL, 
            0x501BDA178DEFB285ULL, 0xDB213A03EB0F8A4DULL, 0x12440844779FF3A1ULL, 0x4DA649DC14AC371EULL
        },
        {
            0x1D44B0D603DBB946ULL, 0x860303BFEBE05483ULL, 0x6583140CE6F90790ULL, 0xF5E04A3EC63AB897ULL, 
            0xB72FEAE0D93E1121ULL, 0xE9895EBD7824C336ULL, 0x940FE88620D40B77ULL, 0xAD2454025B7569F0ULL, 
            0xB65A583EBD4AA3F2ULL, 0x2D1C0908BD553D9FULL, 0x7FD99FF1A0C8EDA7ULL, 0x2C04764A42E60CB8ULL, 
            0xD09F76DDFAE94D44ULL, 0xC91E195F6E5AC89DULL, 0xE3B483FB1608903CULL, 0xD28F1485B7CCBD80ULL, 
            0x1BD30FBC419AEF74ULL, 0x4DA34AD83E8C0227ULL, 0x2E0E8BAA6A6B859CULL, 0xB979093D8425558EULL, 
            0xC2D7E0362E03ECFDULL, 0x36BA732F9E5B6800ULL, 0xCA9FC5CDF2A0ED66ULL, 0x8E965EEF6F7DC825ULL, 
            0x4AF5887E3F0C050CULL, 0x8623D8C3C68BBCB9ULL, 0x28B4765FE047DF6AULL, 0x725DA97AF12CFBC4ULL, 
            0x234F758CB10D2461ULL, 0x5586A86208DC7443ULL, 0xBE2CD73087A8CCDBULL, 0x04809D879BE5A89AULL
        },
        {
            0x43DCAFE924571B03ULL, 0x4D20A04BCEAB6BF9ULL, 0xD5AC9943771B4836ULL, 0x2A56130648126397ULL, 
            0x4947E1C310740261ULL, 0x232565DF6FD0A047ULL, 0x443230EB400369A6ULL, 0x5009DC40DF842984ULL, 
            0xB7B8227DEA28C895ULL, 0x015D821B98C1625DULL, 0x5A18AFCAFA70BC4DULL, 0x0055FFA7A5007450ULL, 
            0x8349487E9B77456FULL, 0xE906DC93E8DB6170ULL, 0xF04C0DE72E7C78A1ULL, 0x27B5415B4D033577ULL, 
            0x17C6586641861960ULL, 0x77659F0BDC4C6E3CULL, 0x8DA1692ED8FAFCFEULL, 0x8B97F7FD4A8A38B8ULL, 
            0xD06290DA8121C628ULL, 0x0205512EE3E146CDULL, 0x91474766C3769AEEULL, 0x35509A3910BC9CEEULL, 
            0x820251E72E3DCD6AULL, 0x2E635076C073E400ULL, 0x41D59902F7D5A29BULL, 0x4298D1D6A8CAF057ULL, 
            0xE6DAB1B9E8A4B4CAULL, 0xEB75D1CD580E9C32ULL, 0x75E4CA41299F4C99ULL, 0x207E0137F50A8529ULL
        },
        {
            0x86BAE6753647CEADULL, 0x38D51FE756F7E697ULL, 0xF548D71B8134F897ULL, 0xED313E8FDC252F7EULL, 
            0xFB66FC9011AA4AA2ULL, 0x13831162B6966DF9ULL, 0x72B4BF89599685F9ULL, 0x2ED12F88B743C3B3ULL, 
            0x6774D6572C02DB5DULL, 0x25A772516184B799ULL, 0xBC680114EB5C7549ULL, 0xC5FD1EC75743948CULL, 
            0x809A42C8802265E6ULL, 0xD2A845D0EED68BC8ULL, 0x1D3827DFA39DD2D0ULL, 0x8478F8D112BE39BFULL, 
            0xD98E6596A5F0E63FULL, 0x6F4639F9D8043F17ULL, 0xCDA648B0FF607539ULL, 0xF1D6499F8652FE65ULL, 
            0xD7208510274CADA3ULL, 0x9985BCC06B4EAF54ULL, 0x7257EBD6353F6C03ULL, 0x87E9E45745DE2A1FULL, 
            0xF84AC4E4EC7832E8ULL, 0x495AD7C3A46559BFULL, 0x9D113EC99E525874ULL, 0xE296A82A7B05128DULL, 
            0x6A83AA115844D24AULL, 0x7C1A07AC0E4C7C93ULL, 0x5D70653259054007ULL, 0xFA89B0119B459D3DULL
        },
        {
            0xD195A75F9C3C919EULL, 0xF68ADE2271DAF652ULL, 0x31D1F86002750DF4ULL, 0xC8E0D8E3F699F96BULL, 
            0xF01258EFC5B587B1ULL, 0x2256206FFD548BF8ULL, 0x5F34D2974C21B681ULL, 0x7F322C17D388A405ULL, 
            0x959833941EFDC8E1ULL, 0x7B018844AC3F4A6BULL, 0x46364606CD8E0E3EULL, 0xBA984BD1E42B1168ULL, 
            0xC863CF72EA298214ULL, 0xF123F524F4CF2DB7ULL, 0xFEBA25C1ED44783EULL, 0x1A91E63F2AB2F92BULL, 
            0x078EFC154EF43973ULL, 0xF7075F2ADBA382F9ULL, 0x5311FBBD36393892ULL, 0xEC976F9656FFE1A8ULL, 
            0x3BFDE61615A70792ULL, 0x5AD9850B9EF1C5D9ULL, 0x9FDB407CBE8C4E53ULL, 0xF1A81E04774CD81AULL, 
            0xCFFDE5F991C47031ULL, 0xE53C47B1BA1305A7ULL, 0xA6B988A6FA46045BULL, 0x6D9277AB64DE7B2AULL, 
            0xBA8F881C3F43B1BAULL, 0x479A47441D4337D0ULL, 0xEDB477907B3F8958ULL, 0xFE8276DFEDBAC4DCULL
        }
    },
    {
        {
            0x7840835987963CA2ULL, 0x1E7C65BD69EFE5DBULL, 0x7D3260EC53CF68ADULL, 0x0420A452EEDDC167ULL, 
            0xD41A2208E918307CULL, 0x749B4093EE46AC74ULL, 0xC7654B6555256CBCULL, 0x11E6B4D35B24B436ULL, 
            0xD34583E651BF5C32ULL, 0xADD70D6EC9D426C6ULL, 0x3C0AE37A764991E0ULL, 0x33480F6CB0B3E858ULL, 
            0xA511EE1D91FA16A5ULL, 0xA636125EA8D21942ULL, 0x6BBEE5C7EC35124DULL, 0x9E7C5846FC46BBC8ULL, 
            0x6E1AE68F03512F94ULL, 0xB8FD4DC470169AD4ULL, 0xCB11C277BDE28EBFULL, 0xFE2084B48BB0FEC2ULL, 
            0x4E324F1470163BADULL, 0x84169560E4109C8AULL, 0xE9D6B95CB029A332ULL, 0x21E8377D8ABB356BULL, 
            0xD6396D739863850AULL, 0x4546586767F92BA4ULL, 0x855AD9FB7D690016ULL, 0x522534E95361FDC1ULL, 
            0x02E3004A34E90076ULL, 0x0191A23E5F4D4785ULL, 0x7EBF29E821C46F02ULL, 0x097AB6CD7BC44E74ULL
        },
        {
            0x555FF0AC9A1E9DF0ULL, 0x7DFC1740EA11A602ULL, 0x0DEC0E15D784B180ULL, 0xE7129C49ACD089C5ULL, 
            0x2B9FD728EEC54ADBULL, 0xC436CFC51E27FAD4ULL, 0x34CE32CED0B3A2F4ULL, 0x22194F28C84D0473ULL, 
            0x8BB6E5DCD98F1B06ULL, 0x06DEFEB42FC24877ULL, 0x389C297287C1B69CULL, 0x2F6E1926F6DDDEDEULL, 
            0x38CB73344A67F5E4ULL, 0xEFC283B234A95D26ULL, 0xC92C2776706A39D2ULL, 0xE33551C75780CE94ULL, 
            0x5ACA219A30C0443AULL, 0xE67326BF5914D82FULL, 0x62588E04F9B6B6E1ULL, 0x77DCB2965449767BULL, 
            0xF52E93B069C97318ULL, 0xFA15A2028DC5B10AULL, 0x5F7C9EBE9684F648ULL, 0x2730816EF9E4AF39ULL, 
            0x00155D96B71C50B5ULL, 0xF55F68944B18D15AULL, 0x98D3825090F08CB2ULL, 0xA4319D9198E5832FULL, 
            0xD8F1C90BEFB60440ULL, 0xD9193F956F69718EULL, 0xFEA88856FFC5FE04ULL, 0x4A5B9A0142CA0E47ULL
        },
        {
            0xB4615C6006430F37ULL, 0x3FB3B7A7E9E52C8AULL, 0xA95C3637EBFC981FULL, 0x846ABC86B83170A7ULL, 
            0x98F1E4288737D5A6ULL, 0xAE30D84AF25262C8ULL, 0xEFDE3CCB080B8778ULL, 0x5C3F9C55D04C16C2ULL, 
            0x54B341125441CE11ULL, 0x73FAF696209D9E35ULL, 0x78B24C1C89A35868ULL, 0x37B1E6C882A098D1ULL, 
            0xBA0D03D0978901B2ULL, 0xC84581FAA5112A1EULL, 0xAF29293A76CE6CB5ULL, 0x6514792F2379DC17ULL, 
            0x567CAEDE4E53FF9EULL, 0x7BE697382559E52BULL, 0xF957927B294B7561ULL, 0x8FE153D073DFC924ULL, 
            0x68AC99C8912BEC72ULL, 0x68F4FBBB7462A7F1ULL, 0x1EFF1B03CA7C9F98ULL, 0xE9F11E0EBFB6A77BULL, 
            0x1D773ACD388DEEDCULL, 0x19A5C88005431E67ULL, 0x51EF069FCAEC65EBULL, 0x4CEA1E176250DA81ULL, 
            0xC846EB977614A39BULL, 0x9360A487717238C8ULL, 0xD852E6A008BA7C58ULL, 0x2D49E01310F18AA3ULL
        },
        {
            0x30A52100C802EF46ULL, 0xA054368CCCEE7151ULL, 0x3F7EC4CA411E1BCBULL, 0xBD58EF51971D4770ULL, 
            0xBAAC35EF8710C0E4ULL, 0x308E631A81480ECDULL, 0x50A74C0C37F997C9ULL, 0x6FCB403472894458ULL, 
            0x17589F7782A60445ULL, 0x337068E31478B017ULL, 0xBF46C23459C7EDFBULL, 0xD88B5905400DB0B8ULL, 
            0x045556061421EFF5ULL, 0xDA3F181934890FF6ULL, 0xF53E58BF3AF6F447ULL, 0xCA6BDA597FAB64E5ULL, 
            0xA645A908FFDFE873ULL, 0xE932582FCBF0873CULL, 0x1C390E0C70B87294ULL, 0xDF17C9DB8005CD6CULL, 
            0xF4FE2781C723F266ULL, 0x43DC71AE7B813C87ULL, 0xE78FF8E3A4217FA2ULL, 0x79E60B08609FCCEFULL, 
            0x3176451C5CEF4AEBULL, 0xF9E91B8BAB0F7D56ULL, 0x4F984FA8CF56075BULL, 0xE78E44F35DCFBA06ULL, 
            0x9AD0DA2B76975EB5ULL, 0x62C9F53EAA96394EULL, 0xFF5EB2DAA51D9F6CULL, 0x68C0B6CED292F4ECULL
        },
        {
            0x7513BF4CE9ECBA05ULL, 0xEF47811FF03D134DULL, 0x49C2A1430BA80805ULL, 0x6AA5FB1758EC5517ULL, 
            0x52AF9843A8D67359ULL, 0xEA16E7637F2E292AULL, 0xE680D6502D3081E6ULL, 0xF9D68AB8955C5A54ULL, 
            0xFBFC54BCEC2516ABULL, 0xE81767D1CAF05E3BULL, 0x76A53CCDAAB77503ULL, 0x5E573292F01AA820ULL, 
            0xC36287DB06C4A1B6ULL, 0x20BD1E9527112703ULL, 0xD18AF680A1D0A44CULL, 0x127B6929E608F61DULL, 
            0xD1E6A1BF84ABBE0FULL, 0x0BA2A61875155CC0ULL, 0xC18F2C798A2B0FB7ULL, 0x8EEE0AA8E9AC5E1FULL, 
            0x49CC3FA9B3CC726FULL, 0x2B5A45BC4525979CULL, 0x484A5EA6675D839CULL, 0x21EBBDCE2C381CC1ULL, 
            0x8BB93342523273EEULL, 0xA4679ACCF74A9E58ULL, 0xEC550781ACBF5C6BULL, 0x1D836C7CF25B424DULL, 
            0x85D155E1E7770A1FULL, 0x2E99F81777F3BF8BULL, 0x3A31E531919BD75AULL, 0xD8A6AA5BEFC8FBABULL
        },
        {
            0x0B21D6ABFA585C76ULL, 0x380A07D59C9E6B5EULL, 0x7A960F2F4AFAF569ULL, 0x5100DE364D137916ULL, 
            0xB749F102F15B1B72ULL, 0xDE1BD22D89A078CDULL, 0xED14DAE6C526D1FDULL, 0x4B75CA8F10CF8617ULL, 
            0x793C16C2F0B8DFD3ULL, 0xA87475B6FC84D1D1ULL, 0xBC23B57583091B7DULL, 0xEEB25D931F70617BULL, 
            0xA28EB9D75CBFBBE4ULL, 0x3F8393EF38C9C013ULL, 0x5340259707EB68B4ULL, 0xAE6B8E78C2C4C47FULL, 
            0xE3A72B8240DED138ULL, 0x18E815BE433597B3ULL, 0x5020C47CEBD1783DULL, 0x00B1D68DA133BEF7ULL, 
            0x75EA5D4004C6B7A6ULL, 0x92072631413FACABULL, 0xDFFA0662D8218534ULL, 0xBA527FD52D67B0C1ULL, 
            0x17B4B6F478AA3E4BULL, 0x5185750C839C11A2ULL, 0x600424AFE887669DULL, 0xB0BA753A5B5A2AB5ULL, 
            0x56500B5C239F2364ULL, 0x7D283DCD49EF9B00ULL, 0x7CFEBC91A8E8C59DULL, 0xC0CC28916DD643FAULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseEConstants = {
    0x1898522FBBFE2AB6ULL,
    0x78D521862DA49793ULL,
    0xDE3397B0CCFF4EC4ULL,
    0x1898522FBBFE2AB6ULL,
    0x78D521862DA49793ULL,
    0xDE3397B0CCFF4EC4ULL,
    0xEACD0663B20BDAD5ULL,
    0x87A316D5FB90EED2ULL,
    0x8C,
    0x52,
    0x56,
    0x15,
    0xC7,
    0xEE,
    0xB5,
    0xD4
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseFSalts = {
    {
        {
            0xF602D84BD7498908ULL, 0x3BF3EE3C59DB7753ULL, 0xD002A4CA7CFA9B20ULL, 0x7387102A9037A476ULL, 
            0x9866589C49658BBAULL, 0x4709D5A73AD4D475ULL, 0xCC5ED8A7B6241F29ULL, 0xAF2707BAE0DE7587ULL, 
            0x9E415EA5866FDAB7ULL, 0xA9B19EA0C02FDB87ULL, 0x4369505979F74125ULL, 0x57AE5DEB0B01A848ULL, 
            0xEE5A94F59C1C6C27ULL, 0xE8E6D64AF06E7543ULL, 0x48F830058F430566ULL, 0xB261F260BE8DACDEULL, 
            0x4965D9183F97AB00ULL, 0xD981FFEC77281619ULL, 0x3B5415F553BE801BULL, 0x2BB120DCD2926D8DULL, 
            0x9121BC1864264B22ULL, 0xF510F52D414D5CEBULL, 0x249F45FDF6452E9EULL, 0x7E9E2C04C938337DULL, 
            0x92FB4B94FB02FD55ULL, 0x2AC3E800549F1D06ULL, 0x477F8500B586E60AULL, 0xF830EDB74CBA3CF9ULL, 
            0x2986632E303D12B7ULL, 0xCFBD3E9F35CD9A9EULL, 0xBC8A3ACFF7F6EBF7ULL, 0xC170616BB868630AULL
        },
        {
            0x32C940A0B989E7B6ULL, 0xDCC9EF7DA102754CULL, 0x1CD7B104D8EDBDD2ULL, 0x3A3C7E4CEF6F5B7FULL, 
            0x9131336A4440DC1EULL, 0x0B6DDD6904016A59ULL, 0x658084DA514AE94DULL, 0xAC078CE1376F2E88ULL, 
            0x861A1BFA4C1E8A86ULL, 0xA7F7F254F27A55D3ULL, 0x0427064D66A210B8ULL, 0x39B24C5D68EE3615ULL, 
            0x71B7C8459F25888AULL, 0x84946F15ED6EDE97ULL, 0x6CB4495A6FA7CA88ULL, 0xB9E506B2F17B1DAEULL, 
            0x52750837F1092286ULL, 0x74A794A91885A6BEULL, 0x7F0887F571DE3B7BULL, 0x00F1008926212637ULL, 
            0x704AF6BD4DE6F872ULL, 0x25D1FFCB875502F7ULL, 0x0171A92D566C160EULL, 0x4405326313038D85ULL, 
            0xCEEABC8FA3ADC099ULL, 0x618CF3007F0FE01BULL, 0x08DDC93336C9A55AULL, 0x399DA47DB76133E0ULL, 
            0x721903EE0A3D6301ULL, 0xF39773F51153E6C3ULL, 0x9396A2DE6B5DFE0AULL, 0xF56B9E5ACD52AC07ULL
        },
        {
            0xDB2A8AC089B56D3BULL, 0xB867DFEF565D5674ULL, 0x510E21B5ADB2F1DCULL, 0x82F66709702BD7EEULL, 
            0xA1ADC461F51C5792ULL, 0xE3868ECF0F7DF7E9ULL, 0x38CD9AF339768D01ULL, 0x108337EC5099D606ULL, 
            0x3161A516E0024B01ULL, 0x2D12139FC21D103CULL, 0xB3B6E77D7128F0C5ULL, 0xB836A3CCE397B5BEULL, 
            0xF240B38016023384ULL, 0xF304D48D8624A0BCULL, 0x56DF1AB9035838BEULL, 0x0F6AED14662BED21ULL, 
            0x26E2EB22766F95BDULL, 0x10907165D09D5D07ULL, 0x5A274C56757782AFULL, 0x6C08B7506BC3AEE7ULL, 
            0x6ED64D6BB92D87B4ULL, 0x9C8933FACD0D7B8EULL, 0x6B738167236EA197ULL, 0x3CF5E01F8BE836F3ULL, 
            0x42C2E7FCA81CA974ULL, 0x17393F61BD067403ULL, 0x5C7534208614FF67ULL, 0xC83BE7AA7F12A958ULL, 
            0x2C00C07BCDBB0929ULL, 0x3D6E6BFE63EA4256ULL, 0x691F41A27724F82FULL, 0x3AFC6C9D073C7304ULL
        },
        {
            0x8A14A2D3A7CC7338ULL, 0x48C353A41662DC09ULL, 0xA7E324D523748DC4ULL, 0x2DE7CE6A0552374EULL, 
            0xFE2D3E78CC4861D6ULL, 0xB3D2C7BA1777DC4CULL, 0xB1656155A9F3AAF9ULL, 0x37CF6355E1E9CE2EULL, 
            0x8A9CA23414AC0395ULL, 0x2CAC8C43826DC81CULL, 0x82EB13DF71A35A3CULL, 0x941CE50CDD870E55ULL, 
            0xC4EF413336F99F76ULL, 0x3FDC4D45B0CAA10EULL, 0x653ED2E0ADFBBEA3ULL, 0xAECCF54913D4DD9DULL, 
            0x75943AA7A5471401ULL, 0xE5167A340613FC9CULL, 0x76865A94CAE18CEDULL, 0xCE62209061E7480AULL, 
            0xF8177BFCB08E2733ULL, 0x82877C9F7CF0B1D0ULL, 0x5B5C4B73570A3D65ULL, 0xB24DC64810BCB7E1ULL, 
            0x1BE724155A3FDB57ULL, 0x78D97A1282765BC1ULL, 0x284736F1197860CAULL, 0x0ED35FE09F965060ULL, 
            0x6BC1898B65833A4DULL, 0x1B9EA26AE24A9903ULL, 0x39F3DB530F00E635ULL, 0xF4546D207924F328ULL
        },
        {
            0x317A989F84F05F91ULL, 0x5DD12CA74B407F66ULL, 0x89229BED4316526DULL, 0x6A9805B3E0A93E97ULL, 
            0xEA1F8FE11288FD1EULL, 0x441739B5C1AD3F20ULL, 0x10A4F000F1425636ULL, 0xA21402A04A28243DULL, 
            0x0CB0DBB79568F8C4ULL, 0xF87F0EB5D9BCE50DULL, 0x80A6478B84869BA7ULL, 0xEF0D932FFF145925ULL, 
            0xD5765618A384F1D1ULL, 0x835480530C0707F0ULL, 0x9285B979890A013DULL, 0xC05525E1F3EF5412ULL, 
            0x8D59196E3FCF34FEULL, 0xC45922F0F92D6480ULL, 0x2856BEA529C3C979ULL, 0xF914E54D787E8D24ULL, 
            0x59CFFBAEEF9BBC9EULL, 0xE25CD57F527609C8ULL, 0x20EB0607BFE7C9DFULL, 0x4154352185AF11B2ULL, 
            0x92747F23DB692BAAULL, 0x42A7D95CFB1EFEB0ULL, 0xAB32C5AA7D20132AULL, 0x9E854A20D2046775ULL, 
            0xB9A1D6971732A20CULL, 0xF5F12A1A64285B57ULL, 0xE3FD770333EB0530ULL, 0x04550B9611F72C58ULL
        },
        {
            0xD7B8E851DDF5E3F6ULL, 0xB7C61051C2221D04ULL, 0xABB833C987C6FB27ULL, 0xCD7ED7B0ED27D1B5ULL, 
            0x73AF810109DA9F4FULL, 0xCF93F825890DEAEBULL, 0x4F0D5AC281F46F9AULL, 0xD072ACFAA74F4124ULL, 
            0xC7C91C501E383D46ULL, 0x3E03EF52F63B1076ULL, 0xD742EA96AC04FD30ULL, 0x899A4CADFB0ED698ULL, 
            0x9A28E00FBDEE5262ULL, 0x169AAC113D25DB0CULL, 0x37A44CB0847D36E4ULL, 0xD139DD6AA34450E5ULL, 
            0xC6148D06AD752470ULL, 0x36E02E653A684A88ULL, 0x953D9DDBC475BFAEULL, 0xEFE392FC80102F35ULL, 
            0x3391B4E22A33BB8BULL, 0x2D4394B7F80B6151ULL, 0xA61E3B837AA34802ULL, 0xC0E6A7660F872283ULL, 
            0x3B45E4ABF8FDAA66ULL, 0x1A7B243CA4DDCB0DULL, 0x4F6CD7E2A9F8F22AULL, 0x96E9F9DB20BF93E0ULL, 
            0xAF112EFBA41B7FC2ULL, 0xD6FB79A816514F68ULL, 0x164CADBF1E3C5152ULL, 0x7C0977C2D28D8FD3ULL
        }
    },
    {
        {
            0x7F1AA8443E953989ULL, 0x9788099ACF4557A4ULL, 0x56943E727553EAB9ULL, 0xB5101F70E754AE5AULL, 
            0xE717731BD4F21B42ULL, 0x6EF6271A3DDAA4D2ULL, 0xF22082D3B4900CEFULL, 0x4FB7FD0934090ABEULL, 
            0xDC8BAAA753D0C531ULL, 0xF7E92A1D8D8DC915ULL, 0x5CD438DFDC18A13AULL, 0xE27B83F26042590FULL, 
            0xBB4D28BB674BF5A0ULL, 0x3A06008D8EE61DF3ULL, 0x5682F6BC60C44655ULL, 0xB3C8D4A2BB7B8D4AULL, 
            0x238B20E6A52A6A06ULL, 0xCACB37F9157B4C6EULL, 0x8369B7776A907521ULL, 0x11483A6959805EA5ULL, 
            0x9C7537940B59319EULL, 0x7E6236B53AA2E32CULL, 0xD5FE2F0B8EEC8BE8ULL, 0x763E6AFC226876A6ULL, 
            0xAB01295D533E27B0ULL, 0xCF8EC61893E60EEBULL, 0x7C15C833717034E0ULL, 0x72A855C233886E8FULL, 
            0x6805D14099B6FFBCULL, 0x32552D1BA23C6ECCULL, 0xB8AEDB77913430CCULL, 0x2C77EA78A6DA254CULL
        },
        {
            0x7FCB496CA423BBBCULL, 0x54396C857D26EEC5ULL, 0x7C7D58086F0E469FULL, 0x778D0C414E0E883EULL, 
            0x269D43A28050C390ULL, 0xC3597C334E890615ULL, 0xF168447F1C99D157ULL, 0x429C16D461C60A73ULL, 
            0xF3FB7000E2F029D0ULL, 0x09B20FC539A6CA9BULL, 0x2A5BE498265798CDULL, 0x73AB4476B5F75E5AULL, 
            0x9F31B11472BAED6CULL, 0xB8BD63DE68EF1AE9ULL, 0x1206EEEF7D401F14ULL, 0x4DD216BEA97EBE8FULL, 
            0xA6ADB79249B9EE9FULL, 0x177A1C1743CC2CBEULL, 0x80BA0AAAD4E36A3CULL, 0x0414D888B50F2B4EULL, 
            0x6E5B2913847CD250ULL, 0xF770CB90F12B3BDAULL, 0x42954CEEF4FB0602ULL, 0x037BED19F523B15DULL, 
            0xE1B5E51E0C09922BULL, 0x8B5EACAF4A23CEE2ULL, 0x49ADF24541AE1FA5ULL, 0x45F2ECC493ECF5B2ULL, 
            0x3FBEB3AC5B28F422ULL, 0xEC33ED3974053F11ULL, 0xD360524F8AE50C6CULL, 0x73628449E8993E68ULL
        },
        {
            0x52A99B94E963047EULL, 0x15E6FDABE02A9085ULL, 0xFA72443311B340FAULL, 0x9EC7E08143BDEBADULL, 
            0xA877D78B030CB107ULL, 0x8480A2BE525F9FE1ULL, 0x33F8F3F2A985FB7EULL, 0x3C53F062DEA17D51ULL, 
            0xAFB0FFB6D9C2B2D3ULL, 0x36D7BB327C80C904ULL, 0x872491F0691309E8ULL, 0xD4F515DE5354CA36ULL, 
            0x1A23B811A37FB79CULL, 0x57D9F15D3EC7A5D7ULL, 0x100C78CABF90B437ULL, 0xDB178E682D4CE90AULL, 
            0x8E77C32DB4088070ULL, 0xB1602A31FC26D9DEULL, 0x749BFB10036C7325ULL, 0x0EE7FFBD958299CEULL, 
            0x168392E745507496ULL, 0xF43CD28A5D92DE7BULL, 0x38CA9F7598FC6039ULL, 0x96237F87491DF5FFULL, 
            0x224A359885443BDEULL, 0xF01AA8006F19A451ULL, 0x52D34F6B6234F4FDULL, 0x6F7C42AD867E8658ULL, 
            0xE3A0AC93F2BE31E8ULL, 0xD0531C6ADD3BB545ULL, 0x97C9963BAA665100ULL, 0xDADF4133413F8F19ULL
        },
        {
            0x80FF5F5D61295E9CULL, 0x58E5A71030DB225EULL, 0x6C0BC1426A00D797ULL, 0x408DB2BCA6D2F8F4ULL, 
            0x7BCC72D2C33F7EB3ULL, 0xD43668361B9EBDE9ULL, 0x746DF181433A237BULL, 0x77635562909DDD50ULL, 
            0x9455B9478EC18932ULL, 0xC616463AA857B0B3ULL, 0xE791DC060668B7EAULL, 0xDD90F10C5E8EBF87ULL, 
            0xF862FDAFA8FBC91FULL, 0xB6248A7A39DE46B8ULL, 0xB3A682098416FD2CULL, 0x28A361A325E6D9E8ULL, 
            0x9DDE92C76CBD4502ULL, 0x3A4655E6BC992DE1ULL, 0x725A3D3C950971D1ULL, 0x37A1A858744BA9FAULL, 
            0xB556DBCFECC4A4AEULL, 0x74CC41C6D5499C16ULL, 0x64577AAEB7AE9102ULL, 0x5102A8C0E2FC966DULL, 
            0x09F77494E889CF76ULL, 0x9B05B789BE525990ULL, 0x18FEEE6377D61CEFULL, 0x12B71A1E6EB4F4C3ULL, 
            0x56B366CF9DE3FB5BULL, 0x6B68BE61A230FC21ULL, 0x5609A122B485CF75ULL, 0x2F4A59DE8EAE4103ULL
        },
        {
            0x2C1C962ADFF90D22ULL, 0x2F73D18A8E24CB54ULL, 0x12D8F740BEAF1ED4ULL, 0x85626E4DAF0F2C66ULL, 
            0x92C573E7D0007E94ULL, 0x78F884B20B7BAF4DULL, 0xB3042BC6944A0DEAULL, 0x061ABA79997D59E1ULL, 
            0xA77F25FCDCE89766ULL, 0xC24852061EE8E600ULL, 0x7B44572785F21E5CULL, 0xBC8BE35DB22A6D4EULL, 
            0xFEBD7E6B807D2A66ULL, 0x630B04809256D8A6ULL, 0xDEBC60626F4EE274ULL, 0x25A11961C9FCE1D3ULL, 
            0xAF79E3A56DE42BB7ULL, 0x855D6BE5E1D40214ULL, 0x5F41277281F94FB1ULL, 0x22D981190CBF3CCDULL, 
            0x7C0979923C1D88CEULL, 0xC6FCCA2B38DC46B1ULL, 0xBF75BA9F37E40AF7ULL, 0x2C3DD597740979D0ULL, 
            0x80BC05309508F942ULL, 0x3B78D9CB48C5BB56ULL, 0x3B01A228D6553C53ULL, 0xB61E5BD819FDD545ULL, 
            0x3BF4BF3855C9108DULL, 0xD5F4259D45EB57EEULL, 0xC94BDD6236F5920DULL, 0xF68EE0D2BD6D2795ULL
        },
        {
            0x6E5F377CA58B9167ULL, 0x57157E32C2DD9300ULL, 0x8AFA7FFDF8D93D2AULL, 0x706F8839F342FEF2ULL, 
            0xAD26DFED7698C30AULL, 0x8ADC4088B3E16B8FULL, 0x68A59703DD819CEFULL, 0xDD35BEFFE53105E0ULL, 
            0x497FF84FF39B695CULL, 0x9FD0E04359E27E89ULL, 0xB6B6E3913DFC667DULL, 0xF985763B53B6A403ULL, 
            0x9DD9A98B86926F4FULL, 0xB7D837E1529A1D73ULL, 0x7632206C81C342B2ULL, 0xA8D78CEFA6EAB2F3ULL, 
            0x6192847CB3188441ULL, 0xFFD748A70D4EF4CEULL, 0x48975EA190792E57ULL, 0x10617D09014DD4B6ULL, 
            0x52D3D821D9C29E0CULL, 0xBCB832DDE04FC470ULL, 0x0BE7C813A2D509A8ULL, 0x4E8F7025DF9EF508ULL, 
            0xCD924AF2890529A6ULL, 0x8D0E49772F10B12FULL, 0x8908EC5FFE94356EULL, 0x884CE0FC17783346ULL, 
            0x8D686C06EA5B5CE5ULL, 0x40F4AC1FB5B1F2F7ULL, 0xB337DD39E2665F1BULL, 0xD380281DCEFCF357ULL
        }
    },
    {
        {
            0xDBB43A824F816771ULL, 0x24E145A066ABAA4DULL, 0xE1E4D2AE0E64C0CFULL, 0xE0BEEE6888FA79DAULL, 
            0xB13DE5E697450F3CULL, 0xDCEFD72D1E6916A4ULL, 0x8594943EB2F37EA6ULL, 0x1AF67916D3CC107CULL, 
            0xD809B5B541E8B556ULL, 0x9E1D2CB400DE6B38ULL, 0x6F8EB1FF8B2D30ADULL, 0xD054B0BC856C89B8ULL, 
            0x45A9878F70CD1723ULL, 0x6BB31726B570065CULL, 0x3845540F7D77110EULL, 0x3A32A6D30FD2FB30ULL, 
            0x0F47C6F558E530F8ULL, 0x2069E2BAC1B1D6B6ULL, 0x85775FA2EF1A2BF9ULL, 0x29AEE7F3B25B7E02ULL, 
            0x29810AE405A354CBULL, 0x127A717EE036066AULL, 0x50968B7830BF064BULL, 0xD07936D24426A28AULL, 
            0x1D6AD0C76EE55240ULL, 0x700EA90863A2478FULL, 0x3FFDAB0C3BCE759FULL, 0x447FF851E47A3C5DULL, 
            0x554D4AD09FE42E75ULL, 0x2EFB85099EE24CB4ULL, 0xAE523BF9AC43BE85ULL, 0x51FE2D5314B75F87ULL
        },
        {
            0x9F4521F6AA2DC25EULL, 0x10FB8A84843F1E73ULL, 0xFA75FCA612BC5FB2ULL, 0xB28F246D5C7E29F8ULL, 
            0x3E1CE11D0F6E478CULL, 0x58CEA886A87B2396ULL, 0xFE1F1DEAC83FAD01ULL, 0x90696EF9D6B7FB24ULL, 
            0x98312B8C2A25A63AULL, 0x3C2A33BD13BBD59DULL, 0x10E0BFC9AC0A0D63ULL, 0x7CC5CA22AAA6ECD9ULL, 
            0xBDCDFAEB0C0F48CAULL, 0x64EF8CEE88B917F1ULL, 0xC4247F8EAF495A89ULL, 0xD0C686BBD7DC82C6ULL, 
            0xFBFE89A9EDC6A78EULL, 0x6D920DCCB21EAAC3ULL, 0x69244E3EAFEF5798ULL, 0x3F1738A86BE96852ULL, 
            0xAE6E9C8A567DBB9FULL, 0x83F2CC174DF7443FULL, 0xC8FEB9990B3830D8ULL, 0xA7B1673EC625B4A1ULL, 
            0xDF76B7671AFC917EULL, 0x6BDD5B8EBFEE7003ULL, 0xC8004EFB5DDE0DEEULL, 0xF2340855ABFBDCBDULL, 
            0x3C5F5B0907239ED2ULL, 0xD6DAAE401BD767D8ULL, 0x76AA033C0FA66D81ULL, 0xBC065A718EDED2CAULL
        },
        {
            0x59396AFCADC60559ULL, 0xD1CF9CD77CE6AC37ULL, 0x4B2807314BE80BBEULL, 0x016A3C6D30529CB8ULL, 
            0x9A38565C56104F94ULL, 0x06CB012326349D03ULL, 0x25CD46B2274E90D8ULL, 0x7EAC397C15E13A17ULL, 
            0x7C1FAD4ABD2EA5C5ULL, 0x3639631340B4EEDCULL, 0xBDE395BB19438089ULL, 0x295B8B37DA25F67FULL, 
            0xACE7D8AF1DDF5897ULL, 0xD1CF1EED345BA247ULL, 0x5EC88E63C2DC2E20ULL, 0x067B1AC68DCAEDE1ULL, 
            0xB78583E9E3E5FA49ULL, 0x1969A1F8B4F309FCULL, 0xF99FD444B876E210ULL, 0x5D347B9A6C7AEA1EULL, 
            0x050E3F08280991C6ULL, 0x7E7D5791DCAF7CCDULL, 0x9EB8824AEDE8BCC6ULL, 0x9266E42BB692C0D3ULL, 
            0x13DE8C2ADB69A613ULL, 0xA6BB736787945F7EULL, 0x4992E797B65E0EB5ULL, 0xE936FFE91D3F11F8ULL, 
            0xDAD0204E07BA6C42ULL, 0xEF2A833DD7EBD157ULL, 0x51719F4CF2712D4BULL, 0xA47DC1A74F9FB4D6ULL
        },
        {
            0xDAD37FAAB44AFDF5ULL, 0x3FC9AE924C6B8F29ULL, 0x6EF0DB3DFFEB02D4ULL, 0xF0DB3B8B0B5D1D34ULL, 
            0x086B1FF6630678E6ULL, 0xC9128820F085A72FULL, 0x9814B457CCF13150ULL, 0xD2F6D4C27D4E0916ULL, 
            0xFFFAEF2778170EE7ULL, 0x776F3C14BD174DB5ULL, 0xB8C16B40D2DA3BA5ULL, 0xE1B11EFA06261FBFULL, 
            0x908128FB456A04FEULL, 0x502FB918D29DC69FULL, 0x16782E4C2AEC87D2ULL, 0x36B27F08789E9340ULL, 
            0x4732DCECE565C0EDULL, 0x27906C6B1705D452ULL, 0x0C9B8D962BF6628AULL, 0x090706BC271DC084ULL, 
            0xB8A37C5297F7601DULL, 0x7C2012851A941F06ULL, 0x3036AA247BD58A58ULL, 0x9CFFAD59FD71B693ULL, 
            0x21F3C901BE768CFBULL, 0x92E5E61F685E909EULL, 0x13C08BD336E7E118ULL, 0x0EB10D196C8AF972ULL, 
            0x05AED4F2B98D8379ULL, 0x4411EFD977481E2AULL, 0xCE443E2810D2A427ULL, 0x40DF0443708F75E2ULL
        },
        {
            0xA76A980281CA9EF0ULL, 0xAC638C9B369F17F3ULL, 0xC8F56C90FDDB2783ULL, 0x741882CE249E2460ULL, 
            0xAE9550789498D561ULL, 0xA4D45453D06CC821ULL, 0x2A723B56EFCDF837ULL, 0x204F63FB6896684BULL, 
            0x9B56B47791D5EE37ULL, 0xF8BAA6C88A7FB408ULL, 0xF45531310B3FA94DULL, 0x46B4DB73921D10EBULL, 
            0x764700063029F4B8ULL, 0x56C6D5C9880509E4ULL, 0x7138F11B9632AD1CULL, 0x6F0159DCB1EF7494ULL, 
            0x65340E9F6C25B8CDULL, 0xA61068E0024D6347ULL, 0xBD93CAB7C5A8AC84ULL, 0xD1D000B68996FD7DULL, 
            0x2BFBB9E7B716150DULL, 0x1264B2B7D6084A4CULL, 0xD5EF385F9E255F15ULL, 0x0AC86FD18145D543ULL, 
            0x9D512A0D97B7555EULL, 0x8E748FA083DAF3F5ULL, 0x242FFFCAF872FAC5ULL, 0xDD687090BF2105F9ULL, 
            0x42AA7B1962694014ULL, 0x8EE89D468072D5FAULL, 0xED5D6B516673F605ULL, 0x83E0923B94EC1042ULL
        },
        {
            0x373DBAAB687DE3F3ULL, 0x9E5369FC7B03DCBAULL, 0x711FD3263F32EA84ULL, 0xA3786BA83B4BDFAFULL, 
            0x7A83528FD2FA7D64ULL, 0x8BAF7FE8F97984A1ULL, 0xCA2A4BF3E403FB2FULL, 0x6EED760E8C73D625ULL, 
            0x64A9999539769B1FULL, 0x9F9AD6C27D7FC866ULL, 0xB889B982207038FCULL, 0x63E783CEEB6FED4FULL, 
            0x6DB10971D5F98730ULL, 0x9AA4599BCA6C51A2ULL, 0xEEF1F8999973E14BULL, 0x574F953383C50933ULL, 
            0xFD6CD8076B5FC0DBULL, 0xB9E8E4D4A412B464ULL, 0x9E853F3716B7C6B7ULL, 0x1EF49C9769330FF5ULL, 
            0x514C919825EFAABBULL, 0xEDCA019A789852C3ULL, 0x39065875D98C2304ULL, 0x24A57B4A6240CD9EULL, 
            0xD55FB09A2E61A2EFULL, 0xDA4615E6822C98ECULL, 0xFE1C39DC5F29AB38ULL, 0xEA700104BE7B5BAFULL, 
            0x2FA21332F2A69832ULL, 0xB36128ECAE90263BULL, 0x568581B5A5964EC6ULL, 0x36149C4B312CB085ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseFConstants = {
    0xF606127B6CC6064BULL,
    0x7EA322149A938455ULL,
    0xB93DF6801BEF999DULL,
    0xF606127B6CC6064BULL,
    0x7EA322149A938455ULL,
    0xB93DF6801BEF999DULL,
    0x6CD49192780ECCD6ULL,
    0x99378B67AD512A67ULL,
    0xE0,
    0xF5,
    0x48,
    0xE4,
    0xF2,
    0x1B,
    0x1A,
    0x59
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseGSalts = {
    {
        {
            0x130657B32D2ED02BULL, 0x637D3EA28A4A815AULL, 0x6EFBC009CC670A0AULL, 0xBFEDE561B3869ABDULL, 
            0xFE768B13262B7718ULL, 0xFC1E6C3C068EF10CULL, 0xB3CC0CA4EB656099ULL, 0xD76CA28AF49BC585ULL, 
            0x70C002111845105AULL, 0x2F38C3CB30E0EA38ULL, 0xCDD9A3877669082DULL, 0x1594A93D44FA86C5ULL, 
            0x396B8BD74D58AAF3ULL, 0x101EDD0390BA42F3ULL, 0xAE72B2D9AC4B57D2ULL, 0x2DF47432FFDB2F1DULL, 
            0xC29B6A1DDE556952ULL, 0x81C422B5344B2972ULL, 0x7A2F35A9FACBE3F6ULL, 0x79EB3851A70DA17AULL, 
            0x35861679EE55E9E6ULL, 0x493A7A698B30A42CULL, 0x2DB7F1CC76C9338DULL, 0xB8B56ACCEE114996ULL, 
            0x9C90F31DD123D2BFULL, 0xFE5BFCC94BC0CB20ULL, 0x276349DFCA39211DULL, 0x2827EFA9F16D9384ULL, 
            0x203229A3D255B39BULL, 0x392B9321CB5E52B7ULL, 0x7C606BCA4642C003ULL, 0xE27751B21AA33CEEULL
        },
        {
            0x32A76B7457DED686ULL, 0xEEFD5EF9FDCC061AULL, 0x5352438AC5BBD87AULL, 0xABB6BA828D4E26EAULL, 
            0xC9453514E9F725BDULL, 0x175A3319D1494962ULL, 0x259B7461A91BBF13ULL, 0x95AEBEE6756CFB04ULL, 
            0x1D9D20A6E5AC0D8AULL, 0x5B4D9EED1840E489ULL, 0x4BE4E1BA63D34CBAULL, 0xF920E65DCB05DA2AULL, 
            0xF908936A0F4A36D6ULL, 0x789ED923F54606EAULL, 0x5142F045A4542DE1ULL, 0x9A7BA25F17108A38ULL, 
            0xF0D4812103D2F562ULL, 0x9685C0C6F6F51174ULL, 0x89C040C3D38F0F0CULL, 0x958030ADCEE689F5ULL, 
            0x2B660C2B4142CB68ULL, 0x8CF6CF5CE1624FB1ULL, 0x6F5656E2D45681E3ULL, 0xF63BA56E48BFF279ULL, 
            0x650F6703CA077C46ULL, 0xFA783723AE270D9CULL, 0xB06489601A2D939EULL, 0x45ED9AEC36DC4F84ULL, 
            0x208D33E97D343084ULL, 0xA76B31586A6079F2ULL, 0x2B1795251FD96964ULL, 0x948320883A2F0201ULL
        },
        {
            0xCDAEC0AF3EF77EFBULL, 0xD03BC930A5950109ULL, 0x9430A1FC1CA80F5BULL, 0x3EB1A53796C83A70ULL, 
            0xAB9F03EB1545D546ULL, 0x6FCBACE2E07795ABULL, 0x6A131E31E21B1597ULL, 0x13F0297AB97C8416ULL, 
            0x774DF72A1E3C1D3BULL, 0x7D7EFD62571C4C4BULL, 0x8855C26888818C3FULL, 0x2C2B6F7AB9688BC7ULL, 
            0x1ABE8B0EF550296DULL, 0xEBEC40B8E250D969ULL, 0xFB7680369FA599A9ULL, 0x896E666097C97304ULL, 
            0x27B3F7A4B76447F8ULL, 0xAA76A8DEDE5A5F66ULL, 0xA3DBA85DB8421E32ULL, 0xC72DB51324212DEEULL, 
            0x8C3459145168ABB8ULL, 0xF060D9EA6EF65E84ULL, 0x0498E4F49DDF44F1ULL, 0x095FF0FBCA3AD80AULL, 
            0x8F9413CD57C7D0C3ULL, 0x5F91E328971CA387ULL, 0xF4E2E92BC9910400ULL, 0x7F3DCC84B383E278ULL, 
            0x8E5236B1DF3229D5ULL, 0x453AE944B377EB3CULL, 0xCEC51A97046FBE36ULL, 0x9C002C07C797ACC4ULL
        },
        {
            0x351664B03D6B5E2EULL, 0x5CA79EE763E5C242ULL, 0xC8F63D5F4FFDD8BEULL, 0x74D11CA036DC09E4ULL, 
            0x4CF9222D731D2148ULL, 0x9BAD348477527161ULL, 0x9D50E85EDB706CE5ULL, 0x726DD25231C2A747ULL, 
            0x1E0080C286B443D7ULL, 0x625B02FDFD445937ULL, 0x332FE297E2C5A2C0ULL, 0x59C9AB8D486D7914ULL, 
            0x4DDA5C845906CE1AULL, 0xAEE6D260106C3657ULL, 0x564A331DBC59B346ULL, 0x3CD90D4F98CC7EC5ULL, 
            0xAC52516D826D32DFULL, 0xD865B431DD1978DFULL, 0x3A064EFF8DA1F98EULL, 0x8884075DD00B128BULL, 
            0xFE3AAFA8BEF1F7DBULL, 0xE6163E0F54106F34ULL, 0xCD01882DCAFF9F87ULL, 0x58E45792669B2454ULL, 
            0x32C04F2699EADBB8ULL, 0xF56D9D36B365268DULL, 0x1BF111B3FD287CB9ULL, 0x44364AB1747084BAULL, 
            0x1A3E4A315873A9EAULL, 0x94472DCA87ACB7B5ULL, 0xF193561A15D721D2ULL, 0x7077BBFD04C444A7ULL
        },
        {
            0x6F523379A7DC2B21ULL, 0xCA293B749929943DULL, 0x1D65F08FD0C8CFE6ULL, 0xCE6E66FEFCB2E9CFULL, 
            0x2A225B6ED97AE5C2ULL, 0xFB6C9E68391AD8BCULL, 0x806467A10F501EC7ULL, 0xFB2DE65D44C8DC84ULL, 
            0x3F6B264625636D29ULL, 0x0A7ECA97C757E6F6ULL, 0xAB3BFB095D3D3289ULL, 0xBC7AF16ABB45C041ULL, 
            0xC9C05F222BEE1C0EULL, 0x519385F659EFEF16ULL, 0x6D04A8E233CEC4E5ULL, 0x4B0123783990A68FULL, 
            0x59B85D57C17369A6ULL, 0xAD378733E034E0EEULL, 0xCEADB882A5DC00EFULL, 0xA23E012E6A7D49A5ULL, 
            0xDE466EDE3D47A349ULL, 0x9BDCD1D788F8488FULL, 0x1658740497DD6315ULL, 0xB5A9C1A980536F27ULL, 
            0xB0504FE20F18AE45ULL, 0x700DAB1A7DA486D6ULL, 0x32E6A26A02121AFFULL, 0x40F73371501A3E13ULL, 
            0x12BE1056FFE7E375ULL, 0x13BB731C0E831071ULL, 0x9B5CA05742597D63ULL, 0x75CFD3431F868486ULL
        },
        {
            0xF2477B8D5DF1E164ULL, 0x239B2D421AFAA43AULL, 0x1F362944C25C9B2FULL, 0x731B804EFC250EECULL, 
            0x627E6FD7B28EA604ULL, 0xABA8524E31414B62ULL, 0x4BABADD777103A45ULL, 0x361B815E6061ED49ULL, 
            0xAAE8CB238778F481ULL, 0x94FE6E3E797BC9ECULL, 0x7E305E8FA640B99CULL, 0xF3125546E1E3D751ULL, 
            0x53E57D2E57345DCAULL, 0x95BBFCB03438A661ULL, 0x9D9C5F189FA9E085ULL, 0x6A7456659E695FC7ULL, 
            0x1F529A366023E65CULL, 0x0FFE45D88C59ED15ULL, 0x1686940F0BEAB97BULL, 0x45059BF67C99E857ULL, 
            0x1C43CE225A3F7226ULL, 0x0F623F9278AEC5A2ULL, 0x1B9E7C1DC020FFA7ULL, 0x9442783BE515D6F2ULL, 
            0x1DF94CD342CBD323ULL, 0xBC85E8E46B176C9CULL, 0x380E29CB92AB5E7DULL, 0x313D4B43159CD0AFULL, 
            0x2CEC6ABC0C8EDBE5ULL, 0xB14374D159D6DF02ULL, 0xA2D552B48314E13CULL, 0x3FC814C80E7C6D64ULL
        }
    },
    {
        {
            0xB5B0D29BA91BDEE0ULL, 0x675DB8BF75E5CFFFULL, 0x1A7136714F14D83DULL, 0xA3913F89FD7D703FULL, 
            0x698BA41577C69744ULL, 0x2A2AB671BA4AAD60ULL, 0x3DE49FB53EEC7BDFULL, 0xCCC2CE8847E888D6ULL, 
            0xA5A443F6B4A5E0E0ULL, 0x73E25F3CA4484B1CULL, 0xD402648401CCCE55ULL, 0x2C4C2B4BF4ED8F26ULL, 
            0x104F3C041D97CF7AULL, 0xEFE765F20EDEFBAAULL, 0xEFDB3B6B2E89DD6FULL, 0xFEF3E79ADAFD2F23ULL, 
            0x143D3AC9A53CABD3ULL, 0x286C19C1B0E641E4ULL, 0x0624A8C51AA9C3CBULL, 0x6DEB8860E93DA2C4ULL, 
            0x823A4E4B67BABD3AULL, 0xB14602D9EBE12E60ULL, 0x39E922A66AB50F95ULL, 0xACE078C3BFA3EF7DULL, 
            0xCCC324F0F95178FAULL, 0x115A07C0ABD1A017ULL, 0xB5BBAD1ABCBE4CBDULL, 0xD3D148CF4588DFD9ULL, 
            0x22BA47809C30FE19ULL, 0xEA9B3BB027DE70ADULL, 0x2E8E04C95906038EULL, 0x127E3222E66631E7ULL
        },
        {
            0x66F775F3D0804462ULL, 0xC2BF234CB84729BCULL, 0xE34D53E69AF0A8E1ULL, 0xAFE47097535C8A17ULL, 
            0x1DEE9B4CA163F4AFULL, 0xBED65E79B7A53AAEULL, 0x052DCBAAFEF9DD4DULL, 0x9C13872D5244B62DULL, 
            0x0588BF5AC23B6A81ULL, 0x72CCD1CDEBC55BFEULL, 0x8FB7946916B712ACULL, 0xA0EEF5562916252CULL, 
            0xD403DF1804E0F286ULL, 0x1CCF751F073D73F4ULL, 0xD22A38EFFF1F03B2ULL, 0x323A851D26BF6C06ULL, 
            0x73BF61C0F9E94743ULL, 0x16CC3FEF07AC6505ULL, 0x5FB13DC2ADED4114ULL, 0xBACE78C90ECB4924ULL, 
            0x19EF5C3E0CE9A6B2ULL, 0xEE41E195BCB21A0BULL, 0x2F61FF3CB2D4D5D4ULL, 0xB0F5B55AFCEF0D84ULL, 
            0x7D1C184F14AD2F54ULL, 0x51F683B1CAF6992AULL, 0xA31F34412FE246A1ULL, 0xB5290B6C91AA0712ULL, 
            0x3A01DD4A345298CFULL, 0x58D86A511EFF1CBEULL, 0x7D6CC29256EA1699ULL, 0x47129F0E8DAD3BB5ULL
        },
        {
            0x2DCE7DACF478C694ULL, 0x36398C258EE0FAD7ULL, 0xAAB9ABF315000C33ULL, 0x2CFF9C35CEAEDD7AULL, 
            0x100E6FD6A1FE209DULL, 0x7FD456DD7EE1E925ULL, 0x35099BDB93473560ULL, 0xBB96041014D907EBULL, 
            0x99E3324A1067A236ULL, 0xE7CFBA31DC0A3008ULL, 0xDE59840FFEF64C02ULL, 0xE1C57CE3ED227718ULL, 
            0x04C806D1ACC18CB5ULL, 0x4C64D036E293C0F4ULL, 0x947394172C713427ULL, 0x3F893462A1204DC3ULL, 
            0x61641591405D350DULL, 0x95BEA22B556E8670ULL, 0x662326A009658DA5ULL, 0x93AE1C484215549EULL, 
            0x48010EDE32B6B029ULL, 0xB99F930C7ED5A031ULL, 0x5606D6CC681537B2ULL, 0xCB36167356F15488ULL, 
            0xEAC8B753CA8FA19FULL, 0x9C746CD33A0E5526ULL, 0x63FBAC46CDA576AAULL, 0xCD7DA86A95C10570ULL, 
            0x16921376EE16E111ULL, 0xCF97BBBCF18C4C1DULL, 0x13897B43186D5983ULL, 0x02DBBD557C7D3568ULL
        },
        {
            0x7DBE0AB0E5B32D8DULL, 0x9B2CE9415AD3BD0FULL, 0x13C3F419F79E10FBULL, 0x5B2B2D9B9A9C3A71ULL, 
            0xAA176B7704D3FEC8ULL, 0x6B21C6F41EEF1A07ULL, 0x8B5E02FCB9096A8EULL, 0xBBAFB9FDB4D048AFULL, 
            0x72B4755E20F8ED03ULL, 0x54244CD1C287EC7EULL, 0xB766312297CB1C02ULL, 0xC25868D768FE53E9ULL, 
            0xDC58FEDDE4628B95ULL, 0xCB7DC3C5269283E9ULL, 0x0FFEC1BEF7CC556CULL, 0xB9F581A77BF71837ULL, 
            0x9B2CEB9D278D0A0EULL, 0xE4BB2E2A5E64612EULL, 0x991E135EC68E8EA1ULL, 0xA5D13CBF559D7FDFULL, 
            0xE00F951540985ADBULL, 0x1C2FCB9F5D4B9B44ULL, 0x924D1B6F58753303ULL, 0xEEF3AE78F10D8AF1ULL, 
            0xBE2C32EB9F10400EULL, 0x82127D1CE8D5BC6CULL, 0x219A6D02FE365851ULL, 0xEA96D61749ABE649ULL, 
            0x76AE417FFEA22D40ULL, 0xA67492332FFA56EEULL, 0xDB75FBA273C9BB4FULL, 0x271D193CD4433745ULL
        },
        {
            0x806D9DAC43B5858AULL, 0x0445CDC393AE2A13ULL, 0x5B332B1291FD6F35ULL, 0xC3F45FD9C0473CEEULL, 
            0x5B466F53ABD67B24ULL, 0x511F0C625CFBE044ULL, 0xEC3434CD8A73C7F2ULL, 0x4994E00315E249F0ULL, 
            0xA8075CC6741FC6FDULL, 0x44CD5D9B64C44154ULL, 0x0D6C6B21747E0785ULL, 0xC7A114D8C747AA33ULL, 
            0x8E0823F85A2DB0C2ULL, 0xC34B84AB7900AF0CULL, 0x075CA1C3A23731FEULL, 0x88F38889A3E248BFULL, 
            0x2DC684FB94A4ADBFULL, 0x7669B32B65FCBBA3ULL, 0xF77BED4DD1970340ULL, 0xA3C3FAA3B1B404ADULL, 
            0x5BC4363315D8C6C5ULL, 0x79D3F9ADBB71588BULL, 0x2D697FFE8797E956ULL, 0x6C490969F85D17CFULL, 
            0xD84C07B089A89995ULL, 0x8B6B30C9FB796527ULL, 0xDCE2E6B506014E3EULL, 0xDAC1D7A97E0378DEULL, 
            0x527F284D2C45D189ULL, 0xA687A77E8971036BULL, 0xD86EA04FA2A684A9ULL, 0xAFE2A90DCC6B4693ULL
        },
        {
            0x049697E7820CF166ULL, 0x560C7B339B4AAFDFULL, 0xAD92CD4C9CA43FB2ULL, 0x1FA8EE5B17D6F047ULL, 
            0x17A7D5C35E0D2571ULL, 0xD74D3A0B2B64506BULL, 0x1D678522B70DDB3DULL, 0x654806BEC932B6E7ULL, 
            0x893C7CFC466FB59CULL, 0x95550072E959B7D3ULL, 0x493DFE496C1D598EULL, 0xA6F860975EACC384ULL, 
            0x86FC0CC307D6AB1EULL, 0x7C89F026EB8BC5E5ULL, 0x60FEEDDB35085EF3ULL, 0xCBB40B9A70F230B7ULL, 
            0x8691EE472967EEC4ULL, 0xBFFBB017CAB50750ULL, 0x7F0B19DCFF0B3393ULL, 0xAF54579FFBAE81E5ULL, 
            0x7CF654495DEA16CCULL, 0x357A5480AF8B84A6ULL, 0x4C1F3E9F8A4AA334ULL, 0xA6F80365BA424C4BULL, 
            0xDB4CB0A09CA20EF2ULL, 0x6BA05AFB9118D1A3ULL, 0x088E3601529973FAULL, 0x8DA93DC4211F1A0DULL, 
            0x4832D777C2852B15ULL, 0xBAE5CC6FA78853D4ULL, 0x1C0F96608EFBFD1EULL, 0xF21F0C78EF751174ULL
        }
    },
    {
        {
            0xA62BA6FA0EF59821ULL, 0x75605646C46936CCULL, 0xE2024D64FB0EF244ULL, 0x898D2E6A99CCCEDBULL, 
            0x10D7A863697E30FCULL, 0x9EFD8FAA97AFDCCCULL, 0x63D7B0BE394D1BB2ULL, 0xA2682C713F05FD46ULL, 
            0x0C7DD8F4B8ACFBACULL, 0x3D375BC6054C21B9ULL, 0xF7461C5519EF5543ULL, 0xFBB843F0BFED7559ULL, 
            0xA7855E43B464F0C3ULL, 0x1D38ABD8B23B9988ULL, 0xEFE7DE37A571C695ULL, 0x94409BDE36818E19ULL, 
            0x594AE5ECB490BDE6ULL, 0x69191328A4DBFA31ULL, 0xFE99E9F51C02D857ULL, 0x01A9CBD551119432ULL, 
            0x9E84AC7F06683342ULL, 0xF0522A6EEB7BE724ULL, 0xCE6EA291E9A1647AULL, 0x7F34FBE983514445ULL, 
            0x33D7933E88A3C82BULL, 0x7E1B42C60ECBDFB6ULL, 0x5FCFFBE900E545F6ULL, 0x7A79840CD96DFC9BULL, 
            0x400DFE4C9B266154ULL, 0x83C87FB24FDDF6B5ULL, 0xB035866E24FFA2B7ULL, 0x6014605103ED3187ULL
        },
        {
            0xC0895B39894E016EULL, 0x54ED7DAE1281D039ULL, 0x3F119A5D8E7C0694ULL, 0xA1BEC40833169593ULL, 
            0xB6F29318BB313669ULL, 0x61ECCBB5A304DE5FULL, 0x6D3183EC9100AA0CULL, 0x182469EF9D5F6B58ULL, 
            0xB348B290A476D9CAULL, 0x39CEE9BD6230856FULL, 0xC02E9278C060A6E0ULL, 0xCDAE26A32810A17BULL, 
            0xA5147E748C64688BULL, 0x9B7498D218682ECDULL, 0x1102B0680905A854ULL, 0x7C3535DE66B07636ULL, 
            0x8847AE918014E7CCULL, 0x914BA9DF8EB955AEULL, 0xFFC3C42B6D5AB126ULL, 0x8E09C402E8FCD029ULL, 
            0x510871FA6898BE7FULL, 0x965E9503C9EE6BCFULL, 0xBF1201C39B4B5F92ULL, 0x8A56100635459126ULL, 
            0x0284572AE76F349CULL, 0x70BF1CC17EBA68BCULL, 0x7B7A85C07DF004FBULL, 0x9BEF469905A78930ULL, 
            0x81FAD5898EA8090AULL, 0xD9BCBCD77E644243ULL, 0xD15D018DCDA23E8EULL, 0xB485004D0A2C3920ULL
        },
        {
            0x948786DE09945B68ULL, 0xD17A454BE8C2BA07ULL, 0x48D29004F346FE06ULL, 0xCEF3DF5FC595359FULL, 
            0xAA634E29F226955EULL, 0x099960B2F97B705FULL, 0x5D5D60F6E2097E7EULL, 0x3CD3225F59C66864ULL, 
            0x49BA1E2FF8517333ULL, 0xE4015BF453015A27ULL, 0x7500F31D759FC25CULL, 0x69FE89C17FE55346ULL, 
            0x7F4DE9763F2C75F6ULL, 0x4B42DC7547EA7863ULL, 0xADF90A5A193E936DULL, 0xD089996CF123C909ULL, 
            0x4CD9CB983C84B62AULL, 0x6F3DB494C6A627D6ULL, 0x9D78350CA82AA533ULL, 0x7CBE0454F3A7970FULL, 
            0x0030C748DB61AA45ULL, 0x1AB537102DBFE638ULL, 0x41563BE747F78EFEULL, 0x2B83B027CC607E5BULL, 
            0x26DA6B7B91BEBB41ULL, 0xAD9D44D76C2E4429ULL, 0xF5F1971A7F235DC2ULL, 0x9BE94225BCCF88D7ULL, 
            0x619263E78CE47457ULL, 0xE1814D8A954B2E8AULL, 0x8E3AE4E94B503BEDULL, 0x02B23E7E0BDEE8AEULL
        },
        {
            0x08243E5605D06AC6ULL, 0xD6E8DCEA067EB422ULL, 0xC8D1F4C25F25649BULL, 0x7D83D6D5691FE9D5ULL, 
            0x57D5A6C633734414ULL, 0x734541FCD211BED6ULL, 0xFA360F68C5991064ULL, 0xFF9AFBA3E4819A7DULL, 
            0xCB753C03A8ABB433ULL, 0x4B0673CE5580A3EEULL, 0xC6533CF5FC3A8BA7ULL, 0xDCDDC20AD547B815ULL, 
            0xA46C90113E68880CULL, 0x70703823E395BE29ULL, 0x197777FB43A87FB3ULL, 0xCCBD6F8517F8BFD7ULL, 
            0xA95A858AF03466BAULL, 0x5BFA12E12436E322ULL, 0x7793757C9CF9F528ULL, 0x7BF5C42DBD224562ULL, 
            0x6382BD5BB50B1BC4ULL, 0x8AF8F4E4E74B8C05ULL, 0x52BB7D441022E6FAULL, 0xACFAC38565B8A727ULL, 
            0xCCE8B545C7784960ULL, 0x3EC7206C8BA948F2ULL, 0xA2F907CC0DDF8BCBULL, 0x46FF85E2D39D54EDULL, 
            0x6AE378E9D99D3BBFULL, 0xE23949A774BA603BULL, 0xE6ACF295FA45D102ULL, 0x0B64944080DD90D6ULL
        },
        {
            0xEAA4CE18280197F7ULL, 0x29C33AC3C8FB416CULL, 0x55526BA3218B3165ULL, 0x42644A7B951AA91AULL, 
            0x2F1D991823E598E6ULL, 0x200F362A4C054E4AULL, 0xBC2B285249CDC68EULL, 0x56F39C78DEEDE59FULL, 
            0xE6E7EE97041CC63CULL, 0x1C3A6BE0C3578F2FULL, 0x393258071E9641C8ULL, 0x708EF6CE6744734EULL, 
            0xAFB569C186BA03A7ULL, 0x28E589BBDF327DD9ULL, 0x15D4F919EB81A0E5ULL, 0x4012A226A5507795ULL, 
            0x8E66E166D558F1B6ULL, 0xB10CAABBE55C63C1ULL, 0xFA0FCACB58572BDDULL, 0xC8974A1666DD1F9EULL, 
            0x59465F04BF5E6114ULL, 0xBDF765AD2709DFE6ULL, 0xE81209A75856782EULL, 0x88705555FD094055ULL, 
            0x54D571AC2969B16EULL, 0xDB5BF9F3CFBBA663ULL, 0xD4F3D462306C4EE3ULL, 0x5361E7BDD888CEA3ULL, 
            0x1C9EBBE5D0CFCBBAULL, 0xF56AF6FEA7A8E3EAULL, 0xCBC39EC32ADE1A1CULL, 0x159FC46357D725E7ULL
        },
        {
            0xDAEC39356803EF37ULL, 0x7C5D7279B3D5CB8AULL, 0x9C61C241559653ACULL, 0x6EF80E338B9ADD47ULL, 
            0x38D56D6D18470DA0ULL, 0xD45C17CA09FF4656ULL, 0x0A9EA4DCC6848058ULL, 0x4E173BA6BE07A0F5ULL, 
            0x5A5D836FCC1F5629ULL, 0x4A62F1AF4EBF1FBBULL, 0x969C4C19C5F41487ULL, 0xA81D7138B354BD0CULL, 
            0x8C556976B51A1D05ULL, 0xDDE6E94D265F8319ULL, 0x61BAB21D17735DACULL, 0x874D3D6F0E97E5AFULL, 
            0xBC07B83EF8141E10ULL, 0x2E8907C2B6D67495ULL, 0x9C3707AFD43F9550ULL, 0xE9C8DC305C49C52DULL, 
            0x8A4C5B8D2C3030BEULL, 0xF710C46585FD8F6EULL, 0x4EA65A927CC5AF2DULL, 0x98DA6670F5AAC128ULL, 
            0x28A5F61628717226ULL, 0x1D3CCC032EC978A3ULL, 0x4A091ECDC8E5926EULL, 0x2D9CBF855140833EULL, 
            0x4A8B814E6C7913FFULL, 0xBE74EDAD0CEB278BULL, 0x7705D29442817911ULL, 0x54356CAB047003B0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseGConstants = {
    0x4B5D4FFBB30C2F7AULL,
    0x3CB4DB29F37AA914ULL,
    0x02BD64E2B1281CC3ULL,
    0x4B5D4FFBB30C2F7AULL,
    0x3CB4DB29F37AA914ULL,
    0x02BD64E2B1281CC3ULL,
    0x303EAA4DD5A2E3B4ULL,
    0xD07A1CA8E1B2F229ULL,
    0x48,
    0x67,
    0xBA,
    0xBB,
    0x76,
    0x5D,
    0xF8,
    0x72
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseHSalts = {
    {
        {
            0xD1FEE2D7275AF1D4ULL, 0xE496D9DA756372F1ULL, 0x4720B1F9E5BC2052ULL, 0xCB926FDF7BCE1FABULL, 
            0x966BC69E074C9748ULL, 0xBF0D5CCB1126C5E2ULL, 0x18FB2C34FDDF5E89ULL, 0xABA2795E4B087E24ULL, 
            0x5BCB370CD696DB9CULL, 0xD80A619A88E4C2AFULL, 0xD76225E6EF0D0CCEULL, 0xB805079B1F8B9620ULL, 
            0x4752503BE8B92480ULL, 0x03841F4F03C7166DULL, 0x777366992BAD8F6BULL, 0xD66891242748FD3AULL, 
            0x5C85531048E100EEULL, 0x92B8ADAC30A615C7ULL, 0xBC6F2002A6A8DE07ULL, 0xA1E81C55DAB29044ULL, 
            0x12E34BE8F9D198CAULL, 0x74CCA04A4F875663ULL, 0x8CD5A584BC8C5044ULL, 0xEDCC2CA8AC9ED796ULL, 
            0xA917F0BB775B55E9ULL, 0x2C25F01E297C7DEFULL, 0x1D6DD5171085E122ULL, 0x55B205E7897CB9E2ULL, 
            0x7EE973C905D59E7FULL, 0x95EFF9DD1AB574A3ULL, 0xFDFF3A3FCCCF7117ULL, 0xCEE78510203777F6ULL
        },
        {
            0xA8F242713C324076ULL, 0x2A034E1A458DA8AAULL, 0x4F332CA8DD2CBE3EULL, 0x1AC34809BDC0F24CULL, 
            0x68B2DE1675240A81ULL, 0x3BB6452EBADDE211ULL, 0x1DBD1F24F10C3263ULL, 0xE0E9813728A82471ULL, 
            0x65C2A997E2D202EAULL, 0xB91E55A51829D064ULL, 0x7224CBDAEE83EE93ULL, 0xE42DEAC326B7D3C5ULL, 
            0x0DB1BCD3A3AAE06BULL, 0xCB2B8BB2C7F805C1ULL, 0xC47856C5424DDE57ULL, 0x2EE1BBC757D06FC6ULL, 
            0x1AA9897D5F8833B7ULL, 0xC78A82DB0B079E47ULL, 0x03E4C11F0E7CECDAULL, 0xCC93E9024BA59151ULL, 
            0x245A219D6F69FC37ULL, 0x5840A2C017B4B4FBULL, 0xF810B19883BFF24DULL, 0x1BB559E7BF81723BULL, 
            0x142C844412E48E7DULL, 0x797BBB88A2335AEBULL, 0x0FA8019F5E4E75D9ULL, 0x4BA1C2F300366505ULL, 
            0x863C74579C9221DEULL, 0x6B22132D90D9AF86ULL, 0x7328B10F51C0D557ULL, 0x2A89D84A5AE32666ULL
        },
        {
            0xF4FFDA196B54ABC9ULL, 0x745344D23A9B850FULL, 0xB11A8F963662AB0FULL, 0x0C5325DED98205B4ULL, 
            0xCCDC29FF1E9E7D92ULL, 0x53871A0A016F0FC2ULL, 0x6DE25288533259D2ULL, 0x0248934A0B6433DAULL, 
            0x849286D6E92AB928ULL, 0xB3CA31C771286A46ULL, 0x3A03DE9D33A96BF8ULL, 0xB950F1FB000A99B9ULL, 
            0x204BD1F7E142EDF0ULL, 0x14891C074854BF91ULL, 0x5821C54584306EBDULL, 0x5404336D07EB14EFULL, 
            0x04A5DEC974CAF74FULL, 0x719B7ED3C70AC912ULL, 0xAF3ACF7F9F53729BULL, 0x8A7DD3BCB3D58B03ULL, 
            0xBCC34730BC9D6A07ULL, 0xEC21D44246A32D01ULL, 0x0D1A4F70AC9FC00EULL, 0x627F5FDBD17CD4ACULL, 
            0x92AAD7C1C33D2357ULL, 0xF7B6A5833FE77111ULL, 0xC1D12585B6777F35ULL, 0xDED84AE8EF7C11A6ULL, 
            0x57E4B7AA2C018991ULL, 0xA3308D9094D87104ULL, 0x652F2DC1FE093701ULL, 0x2040D2BF8D7CD29FULL
        },
        {
            0xBFF04DF8D4ED448DULL, 0x17EE9D3C9631D59CULL, 0xB07CB3F43D0E1BE2ULL, 0xEA7FB18DF7435B0AULL, 
            0x58450A12339B8F79ULL, 0x4479586ED24A414AULL, 0xAB64B2168D72DF0AULL, 0xF01CFF3252953E95ULL, 
            0x2B69102BD1685C2CULL, 0xCBA9F1B310581902ULL, 0xC61AE8302DD3A48DULL, 0x8E2A6D8C4C8B02D3ULL, 
            0xD218B1980838CD1CULL, 0x271A1F2571BA2515ULL, 0x2F4822BBCFC2CAF9ULL, 0xBBB8B518DB5FB6EBULL, 
            0xC0AEF0B898ECE64FULL, 0x862796BC3EC3E609ULL, 0xCFA2ECFC6B83FE35ULL, 0xA0327FD5ABBB055AULL, 
            0xD1002A3235F7F7BAULL, 0x59FD32E24A9212F6ULL, 0x1DC09E121FB2B665ULL, 0x5F3F58C1605BC33EULL, 
            0x0FBA4AA30009370BULL, 0xC8862B4505C5FDC5ULL, 0xFD62EDDF85B2ACD3ULL, 0x2E0D73CA49EEF64EULL, 
            0x90B9327FF2E6939EULL, 0xBC2138C6232F42EFULL, 0x4C8DF07A65DC283CULL, 0x6842BE13D0CB8C69ULL
        },
        {
            0x647F6D12F5FAE2BEULL, 0x53D4AC40F7C75F04ULL, 0x3589593841E6634EULL, 0xC9C93466A6827923ULL, 
            0x2B7AF08F82BB2665ULL, 0x5B41D342D3913FA3ULL, 0x92D1A5ADE67418B8ULL, 0xAB31DB1E90450253ULL, 
            0xF94E36AA7CA4DE39ULL, 0x250CA91D9310A5ADULL, 0x393745CF61194604ULL, 0x30A659F18F7A0674ULL, 
            0x093C78FC92A6F3C8ULL, 0x5FD94BF2A00BAFFBULL, 0x34BD12B38041ECB2ULL, 0x0B0D5429EAD6EAE2ULL, 
            0x4DA7CDA5B3C2E9BBULL, 0x7D5CE4B675F0B77BULL, 0x6F80130FA0ADA176ULL, 0x64614C1A5559F71CULL, 
            0xCF88C48E6558A9FEULL, 0x1AAF7860513B1D65ULL, 0xFFD9795B189856C2ULL, 0x1BE249846FC7C0FFULL, 
            0x4F25B148A5309416ULL, 0x631EFCB6D19426FEULL, 0x34FE542316704C27ULL, 0x871CAC38CEE1568AULL, 
            0x3E2C4FE09F0AC4BCULL, 0x3F9043ADCBCF4B12ULL, 0x21818E3060AAE19AULL, 0xA086B27060FD45D1ULL
        },
        {
            0xBCE511292B715625ULL, 0xCAF9C10B0C3E33BBULL, 0x3BC4F2255E195356ULL, 0x489CF10AF66D407BULL, 
            0x27C1B7A8DF8B0458ULL, 0x199810E73B156626ULL, 0x86FF46E17A7A1F6EULL, 0xCA662A724B90EC4EULL, 
            0x4A8D61AF672F168CULL, 0xB1E921770B6ED0FBULL, 0xF1DD59251F961522ULL, 0x307CCE87FF5E017CULL, 
            0x3447DF4BFB0C5DE4ULL, 0xA1956B5720FD6627ULL, 0x2DE7008A309AF929ULL, 0x2C085F9A8BFC1CAEULL, 
            0xCE25F89D3B5595B6ULL, 0x058C246C7A70B9B7ULL, 0x9468D84D37C2E26DULL, 0x6D62153B6E0E06EFULL, 
            0x3D9418C0FD886EC4ULL, 0xA956F1B34F17CE3EULL, 0x95471B0600621358ULL, 0xE898D25238B943BCULL, 
            0xBE043EB759794F0DULL, 0xBA610BE3A6B4DB03ULL, 0x65386794848974C4ULL, 0x2BF9E920361BD476ULL, 
            0x8BCF6643955B1E00ULL, 0x227243FA50B3357AULL, 0x3E4409B5828AD2AFULL, 0x9BEA9D6C42AA0039ULL
        }
    },
    {
        {
            0xCA3BF75309A570D3ULL, 0x6E3CA6866BA5CFEEULL, 0xCBF69040510F7DEDULL, 0xF7AFCF367F9B7892ULL, 
            0xEA497F76E9FE2537ULL, 0x97802223A476787EULL, 0xC0888A2AEA7CBFA4ULL, 0xFC28DDDBDD30E27FULL, 
            0xE3D104949FF63B72ULL, 0x91425334F92A378AULL, 0xD2165061236A7317ULL, 0x195797C2A926B734ULL, 
            0x91F029AF8A1F5271ULL, 0x4E3B85F7869F5476ULL, 0xAF241B3CC248994BULL, 0x106862F0569DCFEBULL, 
            0xE60CDB811FB6385DULL, 0xE5C28DA1C11B143CULL, 0x9D0E7E2BF03A3A24ULL, 0xB4D4DAD1858BF830ULL, 
            0x4A29361D1597BF77ULL, 0xED576B03E4B69E2BULL, 0xF754AA9D5D25C9CCULL, 0x33F2E7B1D605C873ULL, 
            0xEADADC79431288ADULL, 0x70F612ED21205B45ULL, 0x16BBB19EB203ED77ULL, 0x549C127C9C3E3F29ULL, 
            0xABFFCEC69143BDF1ULL, 0x1572B8BF5C02FCC3ULL, 0x24BA98304D37D3C2ULL, 0x161B5D71BAD6E02FULL
        },
        {
            0x1ACB520A0C9CC134ULL, 0x076AED0EBCD92315ULL, 0x6A33673096107EB2ULL, 0x401D3129D033BEDCULL, 
            0xFED24DFD5344344CULL, 0xCF9787CD56DD020AULL, 0xDDD6B29A5357596FULL, 0xF987625790D63FCAULL, 
            0x7F7034DA413BD9DCULL, 0x6902DD0CA04082A3ULL, 0x59C7372B775CC4B8ULL, 0x4810EADB7A125C42ULL, 
            0x388430E292E7D57DULL, 0xDFDB1E617B476876ULL, 0xF55781D2AAA8563BULL, 0xC609A5F3464F91EEULL, 
            0x7CC9CCCAF46F2C5FULL, 0x4D9B87073B848CB8ULL, 0xF842537D8C7AF19CULL, 0x680B0499A8A320B4ULL, 
            0x91ECD0BB683CE0ECULL, 0x98C88E3186D3D30CULL, 0x4BBA4158D04F3EF5ULL, 0x72F10E4A381F7375ULL, 
            0x4EF1B4773D2AEC7FULL, 0xC4FF9213798E6826ULL, 0xFC300A58F0AC48F9ULL, 0xCA628696E41C2391ULL, 
            0x0219685DCD47E782ULL, 0x92896BA0AE20EEC9ULL, 0xC8ECB4A90EC6458CULL, 0x7E9FE8F61E26AC10ULL
        },
        {
            0x64FAE1C2D44CAA33ULL, 0x0B1122BE86C75D79ULL, 0xF91839A1CB333A80ULL, 0xCE69C2625513B4F9ULL, 
            0x236A6FE65F83EAF5ULL, 0x977D155940F24A68ULL, 0x2F384DD5FC17D137ULL, 0x16329754380703C2ULL, 
            0x4534BF3B4C1323B8ULL, 0x78301F447A307961ULL, 0x02B3C6E44A4BC384ULL, 0xD91A4CEDB9AEA75AULL, 
            0x5F10F868639BC855ULL, 0x1DFFDDAA9F288BBDULL, 0x7CD3738E5FA4BEDDULL, 0x1A3E3FE482E5C530ULL, 
            0x24DB046EE39006D4ULL, 0xBF2E7C4C67A7B295ULL, 0x893AF519B5375595ULL, 0x2F6FE66B3ACD0C68ULL, 
            0x7491D40F9AA17705ULL, 0x7667061CE60985B2ULL, 0x96B302137016EB2BULL, 0xED2FA31B5F218443ULL, 
            0x185BC00A4BB938CCULL, 0x401B9F0DA48BBCE7ULL, 0xB79E5720A1A9AEE3ULL, 0x0183AF8A52E39036ULL, 
            0xFA4C27095931AAEAULL, 0xDA68100CD5979480ULL, 0x310028652C66552BULL, 0x5ACACC0189FE97F4ULL
        },
        {
            0x4620B5B5034F3777ULL, 0x244B2D1109E6EF15ULL, 0xE9406B94D8A68445ULL, 0xB6AF917F768E8EF2ULL, 
            0xC2470FE9B5871B12ULL, 0xAD43A0A2A566D1E4ULL, 0x25861F5BA9258B48ULL, 0x8B40515D5F0B05A3ULL, 
            0x5B5BA03D338338F0ULL, 0x5965B8C010E432F9ULL, 0xC51BC22EB68AF5C3ULL, 0x04D2C16021A71B79ULL, 
            0x10EE61B7A00A5497ULL, 0xBB8C84BF517B19C4ULL, 0x6545FB5ADB0734D7ULL, 0x94FDE01A96DDE808ULL, 
            0x10FEB05E141EFD50ULL, 0x730AB31B60F456BDULL, 0x7892C360FEB76EBEULL, 0x7AE2099D5275CF83ULL, 
            0x9535996F613BB1BFULL, 0x96D768F426724E83ULL, 0xD008D1E124481C4CULL, 0x2B633EB6427BA915ULL, 
            0xFB8967B3D8D8ECF2ULL, 0xD6B18C5644D9DD78ULL, 0x32528054688A7499ULL, 0x80CA58575E6C8327ULL, 
            0x2B59939256521BB4ULL, 0xCB29F57019021309ULL, 0xA69F318B8D670593ULL, 0x8256C59D78EBB85FULL
        },
        {
            0x9E73857270C530DFULL, 0xCFACB230B61210C1ULL, 0x0D783D13A6E4C754ULL, 0xAFC2A37B95ED061EULL, 
            0x04A5B4A04441420EULL, 0x2CF5508A155BB214ULL, 0x6B45FC9B15395B0FULL, 0x7B3B617D05573824ULL, 
            0x05277BDEE8966EEDULL, 0x95EB574A5F97CE52ULL, 0xB4CBDA3511651A10ULL, 0xB93E353E35A7CA7EULL, 
            0x8E9EB63C30152305ULL, 0x3BB17DD55391C8DAULL, 0x6605A051238A57A2ULL, 0x016B9DC15E30171EULL, 
            0x75F36E9A102D858FULL, 0x6FBAD3C5E8702E0EULL, 0x0080F0EA5167EBF9ULL, 0x154ECE1A5F9C558FULL, 
            0x31DCBF7DB474108AULL, 0x112ACB8340DD16BFULL, 0x407FF885B620D497ULL, 0x0418DD2D3B96C20BULL, 
            0x253B160578B8A17DULL, 0x42B3C70D7CF40EF8ULL, 0xE5812C7DFF27EF65ULL, 0xE84CBF2CFE74C5C7ULL, 
            0x3E8661C0EB384B26ULL, 0x7075EC99F57EC265ULL, 0x46E0590FDFF75330ULL, 0x688668E67FE979CBULL
        },
        {
            0x352DEFBA86439F0BULL, 0xEF4DC02058E869CEULL, 0x18ACC5A7AFD04284ULL, 0xCB329487B8136F84ULL, 
            0xA7554A96C28FF417ULL, 0xCD838B64E02C8092ULL, 0x713AC89FD2BEE347ULL, 0x15087E6EA476D2A6ULL, 
            0x8248814056A4DBEAULL, 0x78C8FEBB0DC82E43ULL, 0xDFB4A4846FDD5EFBULL, 0x7E3474D6A1E9C805ULL, 
            0xA7CE63CA5B14FAC6ULL, 0xD8E362693D3D4A33ULL, 0x5F09A2AA07481FE4ULL, 0x5A17A344159C3B9FULL, 
            0x6129BE98B1AE97A2ULL, 0x2B3A70781E555618ULL, 0x01CDBFB7B2AFE8D6ULL, 0xA42D6AC0060F1836ULL, 
            0x004A2880279E265DULL, 0xFBAF25067FBC96F1ULL, 0xF467216C24E50734ULL, 0x055C0B7B716A3B58ULL, 
            0x2821F537382CE61DULL, 0xCA20F38E80AFEEC2ULL, 0x4B16390885A0DA22ULL, 0xCA067490D2A438F6ULL, 
            0xE2A0F01531D9FD6EULL, 0x1703832E78C3BF00ULL, 0xC06644D78311ABE7ULL, 0xB9DA1C9055038EE4ULL
        }
    },
    {
        {
            0xA1475E8F8BC9A8F3ULL, 0xED8A5474C255AC66ULL, 0x16FE4C80349EC853ULL, 0x8E48B5B66A2ED55CULL, 
            0x2AAA6383F82E61B0ULL, 0xC7248A73480F4F27ULL, 0x1B7CFFB6BE7C6FF1ULL, 0xC7D7BADDEF0143DBULL, 
            0x24C05D40515BE646ULL, 0xACF57153F3FBE93EULL, 0x3C78ECCB5D51D82EULL, 0x11853849F65C9289ULL, 
            0xFCF3899CCFFA064AULL, 0xBAAB5F866201B049ULL, 0xF8E5E505A4FFAAF4ULL, 0x542F75F12A3F4F9BULL, 
            0xE03D296C8819464FULL, 0x975982BBEB0C13E4ULL, 0x9E02E237557586E9ULL, 0x4BE1A3212704FAA6ULL, 
            0x6590975EA58A9B48ULL, 0x5C0E1ADBADD028EEULL, 0xEFF9A34702265438ULL, 0xA9D4F8F32DF26BC1ULL, 
            0x2921278649AEBA57ULL, 0x8B0084A8A82C98CAULL, 0x1BB3B146F8C0ADDBULL, 0x5171F2D017B74FDAULL, 
            0xDA33A7F11E650EA2ULL, 0xC156E5F2C65ED9FEULL, 0xEB1F2D6A8515B1F4ULL, 0x5F550D9346FE9DDDULL
        },
        {
            0x16AD2167EDE8C03FULL, 0xD2B49E5ACEFF3F50ULL, 0xA5F8C7807BDEB6A9ULL, 0xF10E707EE5D28577ULL, 
            0xEB5F23EB33428692ULL, 0xA76762E5D016F935ULL, 0x46B48B68F3CD95C5ULL, 0xD00D827ED6000402ULL, 
            0x5DE6DC0892C6C299ULL, 0x231826059514C218ULL, 0x0DDD66E26D4B96A7ULL, 0x15BED73EB87C5901ULL, 
            0x368C7D381651B329ULL, 0x957CBBE5B8EB3503ULL, 0xE905AE8135BAC7B5ULL, 0x0758BE490A383137ULL, 
            0xE62B93A4777C68BCULL, 0xEB26CEF9E10D1276ULL, 0x86169C347752B66BULL, 0xBC2FB3281B327488ULL, 
            0x380FBD4E673DFD51ULL, 0x34DEAD256C9EAE80ULL, 0x03B5BD58FE3B5AF8ULL, 0xF9BF7DDB23A60E61ULL, 
            0xDE152CD3850E93D5ULL, 0x8DC2FA4E9B7466A7ULL, 0xFC73CF5B0622083AULL, 0x77BCC4E8B2DE0594ULL, 
            0x7142CC3640AFE92CULL, 0xCC31778CD852DA5DULL, 0xB4076737BAE1FE1BULL, 0x85BAA6F759D790A2ULL
        },
        {
            0x83521B4AC029C20BULL, 0xA75F1DC4306046A5ULL, 0xC1C7E2428EF86F4BULL, 0x363EE1FE429A56EBULL, 
            0xC37D48B7F5262872ULL, 0x3229A8B37C45BA05ULL, 0x35EFD2441631E688ULL, 0xC8285B9CD7C9E5A7ULL, 
            0x144D63EA63429FBFULL, 0x0B2B3941015FBF1AULL, 0xA15E91C3BA40CD6DULL, 0x36DA9E4268D239A2ULL, 
            0xE5DAD38B4A0630D4ULL, 0x354D3B1DB062AA7EULL, 0x5A74C69647A18AC3ULL, 0x9C0930447900B380ULL, 
            0x149D5034BCB29E29ULL, 0x0FD42D53FFCE078FULL, 0xFE081E4BD2E6FC4CULL, 0x3B414FAAA62686AAULL, 
            0x681E430FF5FAC20CULL, 0x6CE4C46342F43641ULL, 0xDF7B52E95E15BE5BULL, 0xB0A4831248060AD2ULL, 
            0xEA75EE9130ED98A4ULL, 0x72E9D9746CC1C09AULL, 0x5E4F68AB6A6596A9ULL, 0x5FDDF2C8F5A54CB8ULL, 
            0x3B6B620538C80025ULL, 0x16F1DD77E3129856ULL, 0x6DB7B231BA9A365FULL, 0xA5182C80AE5CFFC7ULL
        },
        {
            0xC43FF9D99EFA2792ULL, 0x9D5675E8FAB7096FULL, 0xACC0B72CAF16274CULL, 0xBE4BA79F3BAA307EULL, 
            0x2E7036D6561AD02FULL, 0x9C3F553BCE2DFEE7ULL, 0xDEB582047D74DD4CULL, 0xDEDF038BFCB82657ULL, 
            0x9C06C07280FAC37EULL, 0xC1D5DEA9F49447C1ULL, 0xBE0FE08E2F11E0CDULL, 0x09A063B09A984CB2ULL, 
            0x76416236114B718AULL, 0x6AF3675AD975976BULL, 0x73DBED24C58F38CBULL, 0xA0BDD4F01841053BULL, 
            0x9C2E1FD8B4918550ULL, 0xB6C3A3753E1FE5DAULL, 0x95F7B79D81446966ULL, 0x1A039F5F52E42C86ULL, 
            0x32AC74DC00B378C6ULL, 0x4314675731F564CFULL, 0x17F82AA7D7B4B28DULL, 0x194C51BA3F43732DULL, 
            0x1A3117696EF9C1E4ULL, 0xCE47075997439EB1ULL, 0x452A047A03B8A59BULL, 0x905B3EF747DB931DULL, 
            0x5F27CEE4499653E9ULL, 0x5D3F08B858985D4BULL, 0x50677A62F17CCA36ULL, 0xE0B1EB8F797302C3ULL
        },
        {
            0x898E3BF720B4D19EULL, 0xBA1CFC92738FED08ULL, 0x0AE064FEF78ED109ULL, 0xE7A4F91AC8274945ULL, 
            0x2DC8D1513907D8DBULL, 0x9EC079BDC81A8A7BULL, 0xBC76FA731E28C8C4ULL, 0x3B7B5667E6A69BC1ULL, 
            0xBA0B7E6415505BD5ULL, 0x984B16B0830BEA60ULL, 0x616BFBA26A4E7433ULL, 0x3511938ECE35F209ULL, 
            0xA0421D5F67A143C2ULL, 0x5B28659FCE79F856ULL, 0x7E7F35BE3A52358AULL, 0x69914FEC5B5E8775ULL, 
            0x096E64B4E0B1A87BULL, 0x8E11D9ACB1CB55F2ULL, 0x1BF75C0DD2D98968ULL, 0x55E92CF3FCDCF0EAULL, 
            0x1CA2D026AE970383ULL, 0x2C000F5690E7AAC9ULL, 0xF0A4DEB7EA00A800ULL, 0xAF0341816FC23FF3ULL, 
            0xC5825A9D513BD818ULL, 0x206ABEE4B307B2F7ULL, 0x9616EC2D9DD5E3C8ULL, 0xE607C9B667797A8AULL, 
            0xF04D28D4C7A97965ULL, 0x0DCC8CFC2A4CCC8EULL, 0x071BB0E6238607D2ULL, 0x843E246AA8E1525FULL
        },
        {
            0xE755A6CD2C4CD143ULL, 0x8BB4D4246497B9D1ULL, 0x4DF1F43E858CA378ULL, 0x09FB5EA33CDDA8BCULL, 
            0x7CD7C4AD1035E869ULL, 0x9AB938B9A0C1FCB3ULL, 0xAE65312CAD123882ULL, 0x4B07D03A3B94B4AAULL, 
            0xAB094F715D5515ABULL, 0xE0D1DD025C5B0E51ULL, 0xE21005AB00D3201FULL, 0x1E71933344960021ULL, 
            0xBD38C2A4738736E6ULL, 0xEC4126F928E25DDAULL, 0x3137CE403FAEE640ULL, 0xF2B32CC2B996D3DEULL, 
            0x1B71301175F6E32CULL, 0x526341C7A91ED10DULL, 0x39F49F43947B4F94ULL, 0x4D5DA45431FF2F08ULL, 
            0x3F9877ACBEABAF9DULL, 0x045E7D1C80AF5652ULL, 0x0E9C7A95F9A355C7ULL, 0x8D10C6AF8F0321CDULL, 
            0x52272A993484B188ULL, 0x8B7F4BDD1C7A7DAAULL, 0x1D7B9A92929D5E9DULL, 0x8CE68C042D1ECC67ULL, 
            0xE46320ED23E6047FULL, 0x6C7F8FC7BA502B14ULL, 0xE7C1BB8B7BC409F3ULL, 0x32662C62E237A015ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseHConstants = {
    0xF56D8CFE6D6B86F4ULL,
    0x15511E2C99DAB7D3ULL,
    0x2C7FA6AA7646942AULL,
    0xF56D8CFE6D6B86F4ULL,
    0x15511E2C99DAB7D3ULL,
    0x2C7FA6AA7646942AULL,
    0xB80A1C18C1BBBA99ULL,
    0xED67088F28108F76ULL,
    0x02,
    0x58,
    0xEB,
    0x28,
    0xA0,
    0x49,
    0xE4,
    0xF2
};

