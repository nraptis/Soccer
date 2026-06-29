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
    std::uint64_t aPrevious = 0xEEB3AF7A2A502311ULL; std::uint64_t aIngress = 0xA3EDB72A1C5A9CB1ULL; std::uint64_t aCarry = 0xA4AE3F71F7353475ULL;

    std::uint64_t aWandererA = 0xA663DBEC708FCE5BULL; std::uint64_t aWandererB = 0xCED61E0520876A6EULL; std::uint64_t aWandererC = 0xE395500328FCB8D8ULL; std::uint64_t aWandererD = 0xC787AE20CCE12506ULL;
    std::uint64_t aWandererE = 0xF07E66D8F84DC7F9ULL; std::uint64_t aWandererF = 0xD02D752FDC771625ULL; std::uint64_t aWandererG = 0xD8361E7645706F91ULL; std::uint64_t aWandererH = 0xCFA349E58C5C9B29ULL;
    std::uint64_t aWandererI = 0xD2FEB53102EFB1D7ULL; std::uint64_t aWandererJ = 0xF7CA5E602AFD4DA9ULL; std::uint64_t aWandererK = 0xFF744F81EB2B713AULL;

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
        aPrevious = 17876405681591787221U;
        aCarry = 16182127571961866153U;
        aWandererA = 9971195298261221747U;
        aWandererB = 11124035479699470171U;
        aWandererC = 10665905119276508953U;
        aWandererD = 12937850380095369597U;
        aWandererE = 11160446163405698145U;
        aWandererF = 18361436606921037918U;
        aWandererG = 10672156627983516043U;
        aWandererH = 18026237942709043521U;
        aWandererI = 10408852265182021235U;
        aWandererJ = 18430772652153705428U;
        aWandererK = 17002085480847922372U;
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
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
    std::uint64_t aPrevious = 0x9DDC5442A3EE4954ULL; std::uint64_t aIngress = 0x94A253F32B1323CAULL; std::uint64_t aCarry = 0xD195DAE68058654EULL;

    std::uint64_t aWandererA = 0xFD67E9E8E3E54AAFULL; std::uint64_t aWandererB = 0xA39A23B96B5689A9ULL; std::uint64_t aWandererC = 0xB5E105DC0FBB1C12ULL; std::uint64_t aWandererD = 0x97F670ABEE206AA9ULL;
    std::uint64_t aWandererE = 0xD85C73C495D1777EULL; std::uint64_t aWandererF = 0xC320223E298C3352ULL; std::uint64_t aWandererG = 0xB771760850E8C4EFULL; std::uint64_t aWandererH = 0xD51983796296FE34ULL;
    std::uint64_t aWandererI = 0xA2A37BB5F9CF93E0ULL; std::uint64_t aWandererJ = 0xDBD25C913E565B51ULL; std::uint64_t aWandererK = 0xD4F2C66166D87DCCULL;

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
        aPrevious = 13703842167086476016U;
        aCarry = 10214907018274626118U;
        aWandererA = 9660568943213127474U;
        aWandererB = 16001283061881149869U;
        aWandererC = 16597308365982533492U;
        aWandererD = 9859576704864952520U;
        aWandererE = 12986215600707003998U;
        aWandererF = 12339442139029291366U;
        aWandererG = 14350955416193925048U;
        aWandererH = 12248361407364652731U;
        aWandererI = 14577919576200788038U;
        aWandererJ = 13211214582350826693U;
        aWandererK = 17938493989706439626U;
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
    std::uint64_t aPrevious = 0xFD391AEA0E4EADA4ULL;
    std::uint64_t aIngress = 0x9500635C99A8B988ULL;
    std::uint64_t aCarry = 0x8A92B645E4BC4AD1ULL;

    std::uint64_t aWandererA = 0xE97E991FE2F1231AULL;
    std::uint64_t aWandererB = 0x92CD02F891ADFB00ULL;
    std::uint64_t aWandererC = 0xCA7638F6F29D1C7BULL;
    std::uint64_t aWandererD = 0xAA23C5944E9C798BULL;
    std::uint64_t aWandererE = 0xFC07422CB8A32BE5ULL;
    std::uint64_t aWandererF = 0xBBD16EF72E5D5A40ULL;
    std::uint64_t aWandererG = 0x9E7F41F1C6A8837EULL;
    std::uint64_t aWandererH = 0xF37B6A443886F469ULL;
    std::uint64_t aWandererI = 0xD172C010798E5042ULL;
    std::uint64_t aWandererJ = 0xF2945CA2C9A9EE0BULL;
    std::uint64_t aWandererK = 0x87C00BDC57DFD72EULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD, 3);
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA, 4);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB, 5);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    // write to: invest_c, invest_d, work_a, work_b, work_c, work_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, invest_a, invest_b, invest_c, invest_d
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
    // write to: fire_a, fire_b, operation_a, operation_b, operation_c, operation_d
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
    // temp storage: snow_a, snow_b, work_c, work_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_c, snow_d, expand_a, expand_b, expand_c, expand_d
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
    // temp storage: invest_a, invest_b, invest_c, invest_d, fire_a, fire_b, fire_c, fire_d
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
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
    std::uint64_t aPrevious = 0xD9F17A6621696343ULL; std::uint64_t aIngress = 0xD580DAC1042FE6F5ULL; std::uint64_t aCarry = 0x82E76CEC067F64ECULL;

    std::uint64_t aWandererA = 0x8295D15D22BC8F21ULL; std::uint64_t aWandererB = 0xBAB9209C2BDEB010ULL; std::uint64_t aWandererC = 0x9CEA274AB4200B18ULL; std::uint64_t aWandererD = 0x9CEB0088BFF35EF2ULL;
    std::uint64_t aWandererE = 0x840BEA97747A318EULL; std::uint64_t aWandererF = 0xFE273ABB51E8385EULL; std::uint64_t aWandererG = 0xE50775DBC5B95B9DULL; std::uint64_t aWandererH = 0xEE894451322B681DULL;
    std::uint64_t aWandererI = 0xF437E4F3FE038C74ULL; std::uint64_t aWandererJ = 0xEFBB006D7EB70871ULL; std::uint64_t aWandererK = 0xEB629769FD60BF67ULL;

    // [seed]
    {
        aPrevious = 10787307867291245293U;
        aCarry = 17592153350399492634U;
        aWandererA = 10391346120476934911U;
        aWandererB = 15042209091907894455U;
        aWandererC = 15822527652021415160U;
        aWandererD = 18228903614429046295U;
        aWandererE = 15166280695915724532U;
        aWandererF = 10877310883347716027U;
        aWandererG = 10303395037945809750U;
        aWandererH = 18363216482119507338U;
        aWandererI = 14317065506417273236U;
        aWandererJ = 9821647020711655944U;
        aWandererK = 16720899058846116985U;
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
        // read from: aOperationLaneA source quarters 3, 2, 1, 0 with offsets 5187U, 468U, 2145U, 6870U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5187U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 468U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2145U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6870U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 3, 1 with offsets 797U, 1684U, 6039U, 7792U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 797U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1684U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6039U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7792U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 0, 3 with offsets 5641U, 347U, 3132U, 3411U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5641U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 347U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3132U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3411U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 2, 2 with offsets 6579U, 1319U, 7303U, 120U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6579U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1319U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7303U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 120U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 3, 2 with offsets 489U, 1473U, 1135U, 1163U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 489U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1473U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1135U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1163U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 1, 2, 3 with offsets 1466U, 1870U, 1796U, 397U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1796U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 397U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 2, 0, 3 with offsets 1429U, 264U, 1272U, 412U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1429U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 264U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1272U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 412U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 0, 2, 1 with offsets 1870U, 240U, 1470U, 303U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1470U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 303U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1211U, 344U, 1786U, 2023U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1211U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 344U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1786U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2023U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 0 with offsets 4396U, 2488U, 3124U, 4288U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4396U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2488U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3124U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4288U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 2, 1 with offsets 2106U, 6651U, 7129U, 5643U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2106U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6651U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7129U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5643U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 1, 2 with offsets 1604U, 3730U, 1804U, 6501U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1604U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3730U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1804U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6501U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 3 with offsets 4196U, 61U, 1965U, 7940U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4196U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 61U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1965U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7940U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 8019U, 5661U, 7919U, 2333U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 8019U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5661U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7919U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2333U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 13U, 1533U, 1386U, 1627U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 13U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1386U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1627U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 793U, 1060U, 1503U, 1010U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 793U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1503U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1010U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 345U, 2001U, 1901U, 249U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 345U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 2001U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1901U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 249U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 767U, 511U, 1020U, 1692U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 767U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 511U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1020U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1692U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 [0..<W_KEY]
        // offsets: 894U, 219U, 1869U, 972U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 894U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 219U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1869U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 972U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseASalts = {
    {
        {
            0xC0FB3A9E47193D4BULL, 0x648C3CF5E4768D90ULL, 0x89CF342350D0E6FCULL, 0xA103C172B3B2B126ULL, 
            0x47DB68890B92DB90ULL, 0x4341BDD96233390EULL, 0x4956C0FA2D7BA332ULL, 0x78344D099A29BFD7ULL, 
            0xF132EF393E8822A5ULL, 0x9C6012C86C99923EULL, 0xE42BF60D60C0E6D1ULL, 0x7EF9200344755394ULL, 
            0x05C9CA6E39B7D31EULL, 0xF5FC318BE7276608ULL, 0x8AF41B9E8B5E1858ULL, 0xE00595DCE1187F12ULL, 
            0x564AD72510281567ULL, 0xDA1CCCEF208A91DEULL, 0xF6CFE91C511FFE53ULL, 0xD8FC1C70E9977693ULL, 
            0x889013A9891D1E02ULL, 0x64C8233CD0A56249ULL, 0x3EF6E2789BA0653DULL, 0xC956960F0D94F563ULL, 
            0xA68FF62B1D6648A2ULL, 0x6A50BD5A6F398D3BULL, 0x7D6E58AF6ED1FDCBULL, 0xC985A10C29B37D1DULL, 
            0xF968802FE3CEF019ULL, 0xCDA53D9BC486A03AULL, 0xF8D4C4238594F999ULL, 0x84841D51F6144A84ULL
        },
        {
            0x605731F86CEC69A9ULL, 0xA80FCB51A89EA080ULL, 0x35FCAE8C6EB213D2ULL, 0x89C664DF498FF1E3ULL, 
            0x788F398C59889385ULL, 0x9F3A3EB8A8B4A9C1ULL, 0x2DF503CA11DAC632ULL, 0x5952D06AF329671FULL, 
            0xD49483BA2592BE2BULL, 0x28E61714278A0DD0ULL, 0xDE2B75730F869D85ULL, 0xCC60956765FB5828ULL, 
            0x82FEAB262F134EE3ULL, 0x8825B38D3E7232B2ULL, 0xE2DCA74284D13AB1ULL, 0x6786A4187814FAD3ULL, 
            0xC0C9EB83A82C787DULL, 0x73CBF96F72D7D7EFULL, 0x28B67004362A61B2ULL, 0xA5B55DDC298B973CULL, 
            0xB406BB1964C4B6B9ULL, 0x7ADDC6145A197AD0ULL, 0x86101543F5312AE8ULL, 0xD51F90F1EDE2650FULL, 
            0x4E96D5C8D29B5681ULL, 0x5E414852E08EAB9FULL, 0xF04A2D70036C4DCFULL, 0x0375D298343DFDE8ULL, 
            0x45714280BBD5F48AULL, 0xDC3F51787F83A066ULL, 0x86444A5CD82872A2ULL, 0x8116599C20F484D7ULL
        },
        {
            0x11A89940CB789D67ULL, 0x692398CB3662C917ULL, 0xA8D7C5329DB679C2ULL, 0x956462C682B6BF74ULL, 
            0xBFFA27A0C6D328BBULL, 0x25B3305D9D5288BEULL, 0x2DD1EF0367022A00ULL, 0x7E725586E2E9F626ULL, 
            0xC58EF061E2DD1909ULL, 0xD59F41B6CCC5AB28ULL, 0x6F302C5D08573245ULL, 0x033021538BD2D651ULL, 
            0x8DDDA17BB114645CULL, 0x6948260BA386E15AULL, 0x31742C7B332ACDC4ULL, 0x3D04D34784852482ULL, 
            0xE0573B4A517A9BB7ULL, 0xD711658C0A442D64ULL, 0x10CDB43653E6EEC6ULL, 0x338DA41945D3114AULL, 
            0x4B06B704AB7B3098ULL, 0x7654F281BD09456DULL, 0x07A8951856FA67D4ULL, 0xA3A8E924D770B84EULL, 
            0x70A268AE89AF718DULL, 0x8F1AF618AB114A33ULL, 0x7C2F07AFAEEB61D5ULL, 0x8AFA106958DB7C75ULL, 
            0x0F2FFABDE6162E88ULL, 0xB72A3FFF96055580ULL, 0x1B9F34224C98AF6CULL, 0x6BC3E17F7A218807ULL
        },
        {
            0x4857EA3539BA58DDULL, 0xD1D4BDE09AD8BDC8ULL, 0xC24057E907D44FEEULL, 0x68350AB0103183C0ULL, 
            0x46A15121506AF1E5ULL, 0xF3E809429C0A7197ULL, 0x2DF97ECFD411BA19ULL, 0x2708F91D45A423A0ULL, 
            0x8CF6E7B630044F07ULL, 0x592F9B9C738BAA92ULL, 0x83EF418243BC0EEFULL, 0xE61B00C9D7B84288ULL, 
            0x965EAF56AA1B9930ULL, 0x7A1D729974CD5811ULL, 0x0655A3A47E31361EULL, 0x3215BB1DFA2513CDULL, 
            0x172A47121095E0A0ULL, 0xBAFB261074D2A65CULL, 0x8824E1701CFC8572ULL, 0xE14D1747BF727A41ULL, 
            0x529A8F4135AA4556ULL, 0xB6E5FE94037618FFULL, 0xF22F2007890125C7ULL, 0x6549B0AF2B6F9C8AULL, 
            0x1EDBB86360FE65D8ULL, 0xD606481DA52A72DFULL, 0x8FD169CA15357D88ULL, 0x9B5451A58D94F575ULL, 
            0x098CB7ED44D8AC4AULL, 0x7DEA23FD300EE7FFULL, 0xABE849E414F249DAULL, 0xE39D0AD3CE06F048ULL
        },
        {
            0x5434000FB359BC83ULL, 0x23C641729CDE9C74ULL, 0x05F809C902B8FB5DULL, 0x5948F1A1C99CFA64ULL, 
            0x764FE6A751924622ULL, 0x78373C8FB3DA8BB5ULL, 0xBDF2F91B1182B534ULL, 0x9326600E3D9B944AULL, 
            0xFAEBBDF726A8E3BFULL, 0xD1E664A5CA88600CULL, 0x4EBEC9DD12523DC1ULL, 0xDF0E26014774FF5AULL, 
            0xF60BF3EB26828EC2ULL, 0x9429C7B5B09ABA8EULL, 0x245683EDB8BA028AULL, 0x68D43767137293FFULL, 
            0xBAFA062EAE92157BULL, 0x1A9A398C4A14803CULL, 0x8BAE9178D7E23861ULL, 0x80DD0EE3A246BDBBULL, 
            0x78E7A01A39E72243ULL, 0xA0C42811F423039AULL, 0x67B58CF9D94F79F1ULL, 0x7BA3EE2041AA7CDEULL, 
            0x0E650A34730C8440ULL, 0x573EF3A7254C4C48ULL, 0x1FF25CD24372AC36ULL, 0xEF70CCE856817247ULL, 
            0xFA7AB45D1ED02FC2ULL, 0xE53E5019C99A4DC8ULL, 0xD57A33E6CE8C764CULL, 0xA7579EFC15256EB8ULL
        },
        {
            0x0A587124D5940739ULL, 0xBBDC1675CFCE06E2ULL, 0xBF08511192818AE1ULL, 0xF9FD3FD620FCD717ULL, 
            0x6CF9409D1F3E969FULL, 0x00CA2DE714B84540ULL, 0x502B54F98CF84062ULL, 0xC2C183837B7B870FULL, 
            0x5F5C27840DA7B7F4ULL, 0xA471797269F97F93ULL, 0x8096DA534DCD7207ULL, 0x97EC0922E2DEB1CCULL, 
            0x89DBB104D0F2B49DULL, 0x7ED7B061AA8239FEULL, 0x17EC39ADB93A293DULL, 0x23E1D40A5AE7D8BCULL, 
            0x34414EC31D8D2A46ULL, 0x526A5B7208FAEC9CULL, 0x657D1EDFE1779635ULL, 0x153D7D19FCF2ADFAULL, 
            0xE8856B18CD920EEBULL, 0x4203E64D54C4457FULL, 0x49144B331DF177F7ULL, 0x9654B229B806E2D3ULL, 
            0x70588CF325C9A9AFULL, 0x46554685A9EEFEEBULL, 0x1B4DEC1E5E536AB4ULL, 0xAF6EB92B59034ACDULL, 
            0x41B43AC30E527A06ULL, 0xA05347294E732DE6ULL, 0xC2FE00B229633B56ULL, 0x9C52540403410A41ULL
        }
    },
    {
        {
            0x023B9E1A50777587ULL, 0xB378EF9E33BAAF33ULL, 0x343C31F8BFBE6E9FULL, 0xB07CE2A8ACDF74F8ULL, 
            0x16FC4B93CD506082ULL, 0x53176F2454A769A1ULL, 0x1855CB2C6EA60F72ULL, 0xAD6340D1927C8A87ULL, 
            0x40D961DA55D5F137ULL, 0xE91EAF18BB48E4B4ULL, 0x3732B0138F09801DULL, 0xB98C6FD091E3011EULL, 
            0xD530734210A5972DULL, 0x0637CBEF3184A71CULL, 0x2AE67ED3185C1888ULL, 0x0B15BAA12B50427BULL, 
            0xEC906C4501EB080DULL, 0x73D3C391D42C9C77ULL, 0xCD576F4A0A4FBC8AULL, 0x0288B214AC046D34ULL, 
            0x622568B5864A41E1ULL, 0x0DA4C5D8D4CB1E07ULL, 0x2F116C72C2465FB3ULL, 0xE139A142ACFAED05ULL, 
            0x47F4C148656F5093ULL, 0x61C85D8DE2D99D18ULL, 0x49FF70696810C168ULL, 0x46059C72257638EFULL, 
            0x746BB90F83177883ULL, 0xAE9CA5F189EA67A8ULL, 0xDB7B4DDA10B06B36ULL, 0xA1110135BCEF5CADULL
        },
        {
            0x6B2064C26E7272FDULL, 0x489439C47CA1C83DULL, 0x5AA8F2B66B3EFCB2ULL, 0xB76D16499816E57FULL, 
            0x1D200A00CA8C6EDDULL, 0x96CF74CB0C884617ULL, 0x52490D544E5C0938ULL, 0x5F777347E0209416ULL, 
            0xBCA5A5A0F9A0E1C6ULL, 0x1E6AF6A4879496F2ULL, 0xF76C6AE9D809DD10ULL, 0x252DFE9E358DEB21ULL, 
            0x2EC863BEECE2535DULL, 0x29A78493063D1D38ULL, 0x9FB75C991E141198ULL, 0x601B06731C4DD774ULL, 
            0x2B2B3BD2006D1A14ULL, 0x9C1EBC10DAE7682FULL, 0x47F1B66C0ABD89EAULL, 0xD114BFACB21D7FD0ULL, 
            0x536C3F5F33E005A0ULL, 0x29003ED77C5D3CE7ULL, 0x5440108D6C258982ULL, 0x8CDF5B71887F828FULL, 
            0x2904E35F6EDA30B6ULL, 0x2E676BEF9ADD93B9ULL, 0x7A062F01F4D3EED5ULL, 0x26F56F28361C6B5BULL, 
            0x25ACC433B2FA10CEULL, 0x02B9A3C356311BA3ULL, 0x65A84F2C7627CCB6ULL, 0xDE9700B445A88864ULL
        },
        {
            0x77171D2EF54A2DECULL, 0x5DD3179F9B42F4C1ULL, 0x73EA474273A4B78CULL, 0xAF616EE9F9FEE934ULL, 
            0x5FC42C899CD0AD3CULL, 0xC2406B02D389D27DULL, 0x7237D1FDF8B861C5ULL, 0xB6D19379C67B8247ULL, 
            0x335559843839B3DEULL, 0x1112922A37C86110ULL, 0x69BF3D4ED9C1B44CULL, 0x294C2759D29975C9ULL, 
            0x82F7E5CB2A45970BULL, 0x0515866C42F57A1FULL, 0x01CBD782124907CBULL, 0x74A84B8F3379D163ULL, 
            0x96774120BFC6B68DULL, 0x120B1400332C203AULL, 0xA3DA08E90934865BULL, 0x6FBAE039BA2CC252ULL, 
            0x50997CFBEF4FD781ULL, 0x81E0D61BA3469752ULL, 0x0E30EF2AB03C670FULL, 0xBF88542C9F559ABEULL, 
            0x62F75A5B9A82EF8EULL, 0xE971F990BF4B8657ULL, 0xEB72AA2C15AFBC63ULL, 0x16E399CAB44B091BULL, 
            0xEB26307431CB880AULL, 0xB0BA6D8182308591ULL, 0x41BA892EA55A6E9AULL, 0x83CD619B65F5C86AULL
        },
        {
            0xA3334D85D3997096ULL, 0x0335CB0819A11EB5ULL, 0x1DFCC507BD4A0937ULL, 0x2169BF9E27B5417DULL, 
            0x31DFDAE0ABB91615ULL, 0xC8F448A8C6AB5666ULL, 0x9E9CD75CF3112D19ULL, 0xF486AD61879BF358ULL, 
            0x57227BDD6AD882C2ULL, 0xA028007A302D4E93ULL, 0x5ECDDBE1ACA5D6CEULL, 0x6C1DE00183BB251AULL, 
            0xED2964ED769829D3ULL, 0x87EBDF6E14BC6C49ULL, 0x298D4CF09A80B3EBULL, 0x1A3F684CEF1E8C2AULL, 
            0x5FD99EA3C13E47F7ULL, 0x0247E485756ABDC6ULL, 0x4BD4F2B3E07724C3ULL, 0x22C326C3D88A4C6DULL, 
            0x67DA7CF0C93F7D53ULL, 0x7A5F1BC0C5D5CA14ULL, 0xCFB66DD962B3009FULL, 0xBB397A99B730506CULL, 
            0x531D259861E7F076ULL, 0x5D4364AF66FFFFA2ULL, 0x2935FC937C3D80D0ULL, 0xA58F70D7A29E801EULL, 
            0xEBB87E2A3FD4F148ULL, 0xD76490B424AE187DULL, 0xE2EEE5374A412200ULL, 0x2A098F2452599911ULL
        },
        {
            0x08DF0E543DF3D52DULL, 0xF9F23D7AAAEA5074ULL, 0x63E01998742E120FULL, 0x09CAC8205524EE02ULL, 
            0xE4B6C25894F5A830ULL, 0x4177F0A708DA63ACULL, 0x06A7F77E60136EB6ULL, 0x6E4D8978BFDD36EEULL, 
            0x870722FFC4260DBBULL, 0xFCA7D1BE94262509ULL, 0xB456BFA95997B74AULL, 0x93B9DA50AB7D174DULL, 
            0xCA4797EDE3CCFF53ULL, 0x2E0869EAE15D3C89ULL, 0x38C34F98F5ECE6E1ULL, 0x7CB4490889B7BA1DULL, 
            0x412092D0AB287237ULL, 0xACD5D1144729B029ULL, 0x3B639A73AC96A42CULL, 0x5B572D47D8E51406ULL, 
            0x020F50D99D7E6578ULL, 0x1BA332033757FD6AULL, 0x054AB63C0202D393ULL, 0xAF5451DF6C21F770ULL, 
            0xE4ABE08EAC014197ULL, 0xD7F563EB833A59ABULL, 0x88C2FD6946201A36ULL, 0x1E2F547BED409A87ULL, 
            0xF2E67875149DC1A5ULL, 0xF2B5C735A81FACB4ULL, 0xFBC220ABE6C5D8EDULL, 0x07CB96F7CCC88846ULL
        },
        {
            0xC85C8C8B9FD2E21BULL, 0xBCAAF6CCB52DA1F6ULL, 0x74A7AE49E72ACAA2ULL, 0x47FA70A11501A829ULL, 
            0x3DA637A103795AD1ULL, 0xAF2FFC3224516129ULL, 0x1CDBBEE1E23A3C84ULL, 0x1C65A03B81A5103FULL, 
            0x2EC043568CD97233ULL, 0x7A7FEDEAFB0179A9ULL, 0xAB1D71801E040543ULL, 0xE9C317730AFBB487ULL, 
            0x5370C2B94F4DC92EULL, 0x09CC2CE70E96FE95ULL, 0xAF0FF97CDF4FF84AULL, 0x37DFD7BE06D01FE8ULL, 
            0x9AE57FA771BEA5C2ULL, 0x95EF00DC55F8A92AULL, 0x9DB2B64D82E52EDBULL, 0x36B580F25D8F7EF5ULL, 
            0x924FB812C3A22636ULL, 0x21D44B4ED1F5BFB3ULL, 0x70B0731EB1B33B1CULL, 0x743EE5AE1128A16AULL, 
            0x49E26A2E31075E8EULL, 0xBA02D766CC17E2A2ULL, 0x3E4A59019FE770A2ULL, 0x5648746A257155EAULL, 
            0xD5894710FC2BF9A1ULL, 0x43B9F3DC3DD38E63ULL, 0xEB638FABBF793F72ULL, 0xFA4898253BA72479ULL
        }
    },
    {
        {
            0x8359A44B16BDBB19ULL, 0x0B1D583D631958F5ULL, 0xF035CD5FBB2FE2FAULL, 0x684ABAE4C439A7EFULL, 
            0x9618681F4CA9219EULL, 0x938E804FDE1088FDULL, 0x159A42E08DA1BE2AULL, 0x00DF07B531C1130BULL, 
            0xCB76CF9966201B3CULL, 0x838710037900A816ULL, 0xA5297A9545EAEA0DULL, 0xBA9B40E414A69060ULL, 
            0xCCF84B5B0EA7FF3DULL, 0x27A9CF822C4312A4ULL, 0x053DEBDF114A372FULL, 0x6C9DD5DDD82AA9BCULL, 
            0x7C08514AF6F9714AULL, 0x950EE8DD04D544DEULL, 0x2F2FC7A6ADD6B6FFULL, 0x0A782064248DC464ULL, 
            0xCC1A41146D76FDEFULL, 0x5305ABCE35957872ULL, 0xBA5E7650ADE86D51ULL, 0x865D5B596F44850BULL, 
            0x20B6A189CEFAFF28ULL, 0xE412B3CA78A6664DULL, 0x9439518422691DD8ULL, 0x3D07AD8995BF30B6ULL, 
            0x20D4B54D927A945FULL, 0x7F5C3F24166524CBULL, 0xE1346F509129C1FAULL, 0x19F1DFCAB7142C40ULL
        },
        {
            0x0A2D375F0E27F4D8ULL, 0xB932901837296186ULL, 0x948C00FA1428431BULL, 0x76BBA74EC8BD18E7ULL, 
            0x61CDF95DF14C163BULL, 0x9EFFE28CCC3CE4DCULL, 0x6C4EDB48A1BB48F6ULL, 0xAA6DF0C1C0205C0EULL, 
            0xC04C305A74B89CC8ULL, 0xCA2A968EB7D260A4ULL, 0x1749429ACADE762AULL, 0x799D7EEF6C7271CCULL, 
            0x9D8E89DEF4BA6334ULL, 0xCA5291D38FCD3504ULL, 0x0DB33DD2DA6EE4C5ULL, 0xC5E6FFCD07F81BC0ULL, 
            0x11E6630EECA31B8DULL, 0xCA2703D16A99EADAULL, 0x715A7B5D83DB7A9BULL, 0x4608EB7DBBBFF2F8ULL, 
            0xA6B64FE7F18A9DC2ULL, 0xCD4BBF101F6C88F6ULL, 0x552BDBB5CA5B8708ULL, 0x2C31151D9CF92836ULL, 
            0xF52CC83803F94EF8ULL, 0xE78AA111B6DEBA1CULL, 0x9FACB9096FE08BF9ULL, 0x2065C0DA6F032E28ULL, 
            0x7D084260F46CA6DFULL, 0xF06EE5A36DC91C36ULL, 0xF5B54B4CCD445367ULL, 0x2C4FB4F6C2517430ULL
        },
        {
            0x55884B493C0084D8ULL, 0x11E5414244A4A363ULL, 0x3088313074BCEF14ULL, 0xE5F9E1D1F24EF5D8ULL, 
            0x76B9871DA89C5CB9ULL, 0xC5988FFDFE7F46AEULL, 0x9540A3BA28DA1809ULL, 0xFDB55270FF2D9674ULL, 
            0xCDC56811F793E407ULL, 0x20C57D614E9A10D0ULL, 0xEB136945B4BC25E1ULL, 0xC0A35ED1701C4DB0ULL, 
            0xF40001F73E79E766ULL, 0xB8C51BD29125DBE6ULL, 0x004B13534E99784AULL, 0xFD2629A1E2AD179EULL, 
            0x8226DDEE387F03D7ULL, 0x297D8E8206489713ULL, 0xFB2612D9270B4013ULL, 0x591CB50BF56A124EULL, 
            0x3E02670E14A50D37ULL, 0xFB662A25D87C93FBULL, 0xBB9E29CD35DEFCA0ULL, 0x98881D96BEBEC318ULL, 
            0x1DBC658CA7F6B344ULL, 0x8367A96EF892203FULL, 0x98080502B84D8C60ULL, 0xF58DE2901AD1558CULL, 
            0x6CDA495DB7AA91F0ULL, 0x9F0FBD739C2B78ABULL, 0x91AF43FA4461CD34ULL, 0x38578B0BBA2E9DE7ULL
        },
        {
            0xAB78E053D945D404ULL, 0x32FD829BD94AB50CULL, 0xD200D34D9AC839BFULL, 0x4A8008AE4C33D4E9ULL, 
            0x47563A6FC953D70DULL, 0x3F19CF0827CF7A8DULL, 0x9A6BD5854919FF08ULL, 0xBB7FE80A4DDF6FB8ULL, 
            0x5BC4546C7C5D4A3DULL, 0xA56277C6ABC9B63EULL, 0x2086D22059229947ULL, 0x7924C0B773398FCBULL, 
            0xF2958C6A801DE1E9ULL, 0x0B68A29159F2EC44ULL, 0x62645FFD8B90319BULL, 0xC7C463FEE77434BBULL, 
            0x663DCE37E58F9F05ULL, 0xF408520A2CD67D85ULL, 0xB532A36404CE86EEULL, 0x1A4270D16A44BC38ULL, 
            0x6C80A933A401EB69ULL, 0x389DA97590309262ULL, 0x023AB5AAF4E6BDB2ULL, 0x95BC698999DF7EA4ULL, 
            0x9BFFF902714D0218ULL, 0xF7E6C5C86055E990ULL, 0xD08C699F7D719C0AULL, 0x47E6E7655C8BDF72ULL, 
            0xE6C6241341AC10B3ULL, 0xC7878EDB5EA0AE99ULL, 0x81A31BD35F96D832ULL, 0xE5441A072F7490CFULL
        },
        {
            0x29901374BC16CA05ULL, 0xC49F199941AE8C9DULL, 0x15CCA8EC2970908DULL, 0x5F81EDCFF65A82F2ULL, 
            0x28CFB6A11A9DEC12ULL, 0x92A0564017BFF1BFULL, 0x5BA7B552EA5B3EC2ULL, 0x53687E00BD9683E6ULL, 
            0x074C6CBEE313CBE6ULL, 0x3AA889C5027A1B93ULL, 0xACCCD5C7A7AE5442ULL, 0xDEB18A4446804029ULL, 
            0xB26D23E423F1310BULL, 0xCE0C0CFFBC7BED27ULL, 0xBC93B4C1D6920946ULL, 0xF484DD7B6BB4BCEAULL, 
            0x44F3C2CCCD407D9FULL, 0xC8025309B5EFB2E0ULL, 0x362A09E3E5E73E15ULL, 0x4570A60264FC717FULL, 
            0x7A988B093111DFC3ULL, 0x1DD38D54E0AA66C1ULL, 0xC07C907A7B0E42ABULL, 0x99779AA89A12EE79ULL, 
            0x25E979D885D7FED6ULL, 0x91300D1026535E6AULL, 0x464373C1CB2AF6DBULL, 0xF6D0D4C411049F8EULL, 
            0x7E3CE4F06334899BULL, 0x03F7AAF5360EFF76ULL, 0x7E29D135245D9052ULL, 0x26DCE95D2BC691E3ULL
        },
        {
            0x1F825E9AC7B233ABULL, 0x80B8BDE11087E1DDULL, 0x71DA0B131A5C9CC6ULL, 0x8716CDC4B49703C5ULL, 
            0x59D331AC7719E8F4ULL, 0x1BEF95567F6D6A5BULL, 0x2E9AE4CCF9F7D0BBULL, 0x85CE4E7B848A5D85ULL, 
            0x2F2B56D03535FA9CULL, 0x9A44826579D14619ULL, 0xAE6347348393D3FDULL, 0x540347C7F11BEE96ULL, 
            0x7CB040ECA27D31A9ULL, 0x9DA74ED0D4A12435ULL, 0x1474690B3E5BDB66ULL, 0xA9EB7D9018454933ULL, 
            0x068BDC406C508A1AULL, 0x0075B9FD3D9AF739ULL, 0xB8089A2C80C234C2ULL, 0x3B5D5B065C59EFE4ULL, 
            0x8D71ED4C57DE7685ULL, 0xC0795749A45DF1ADULL, 0x91A31D357F7BCF95ULL, 0x0C92474D8149BC7FULL, 
            0x4C75F8E9CABE0BEFULL, 0xFF44B40F8163A331ULL, 0x3ED391E790EF4E89ULL, 0x92A1DB76DD061193ULL, 
            0x9870CE3B49070FC4ULL, 0x8E76E5338136F0F4ULL, 0x757FE4358EBDD5CFULL, 0x324EB71103E971A0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseAConstants = {
    0x79907E5ECBCAA2F8ULL,
    0x05ABABC4D0787EE9ULL,
    0x0353FE0D56490784ULL,
    0x79907E5ECBCAA2F8ULL,
    0x05ABABC4D0787EE9ULL,
    0x0353FE0D56490784ULL,
    0x74E926972D5181B5ULL,
    0xBAB46F99A14C699BULL,
    0xC7,
    0x38,
    0x2B,
    0x2A,
    0x59,
    0x62,
    0x84,
    0xF4
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseBSalts = {
    {
        {
            0x7BCAECB64E027ADCULL, 0x68C91D2D69452A7CULL, 0xFDD5F7187D91D399ULL, 0xE09BF988AF090621ULL, 
            0xF0C2DD9BFA20C9AAULL, 0x0F894A42B147FD02ULL, 0x8C5158B779E13892ULL, 0xF2B4B113BE678198ULL, 
            0x4EB79C5D9655D541ULL, 0xAD142976E9446FDEULL, 0xCC662E50C37C6FDDULL, 0x72359E055AEC368CULL, 
            0xBECA5DFE16252174ULL, 0x6D2EEF37CFFB7E23ULL, 0x6962F06E60832A8AULL, 0x1A5872526FB143FFULL, 
            0x3CCB3F80C32F1C0EULL, 0x3B5F92C23DB542CEULL, 0xDDEF162F1191930DULL, 0x0C2597F909BA515CULL, 
            0xE1B3EB7D29E6089DULL, 0xBF76C12FB2CD658CULL, 0x3B7AC4735EDE3500ULL, 0x48E0BF9A762BD36BULL, 
            0x06719FB0C3C4014CULL, 0x0045EE7C3612446CULL, 0x5EEEB55EB3B39237ULL, 0xF2346C68496824FBULL, 
            0x7326A91097400CA1ULL, 0x825E03E7A089AD1EULL, 0x10A73609C7EBCE1FULL, 0x138D0F32F4BA3C1BULL
        },
        {
            0x0068C624AD20E64AULL, 0x9AC2BE25887C36DCULL, 0x646CD363F4608C64ULL, 0x37D801165E00FDA3ULL, 
            0xA5F2FF54447BFCC1ULL, 0xD25775AEF463ED67ULL, 0xC667034CCA2F573CULL, 0x419BA5BFA074F200ULL, 
            0x5F637242BBEF433FULL, 0xC3E5E3203B39D86CULL, 0xA1C1184A57814A4FULL, 0x024E0CD258D3C3BBULL, 
            0xF99E8DC02ADCB05CULL, 0x9DCB0497BC958AA0ULL, 0x36AFDA09BFF725E9ULL, 0x32FC9669FC5EAE6AULL, 
            0x4E6E346C5610836DULL, 0xD291072FE581FE54ULL, 0xF7B90B769DA40149ULL, 0x95F26AED868756BCULL, 
            0x91385A6A53DE8450ULL, 0xAFBBA9964AFFFD71ULL, 0x595EC8FDDA523093ULL, 0x22099B45ABFCF416ULL, 
            0x5B6BE7C39371892AULL, 0x6A37C87D906179C0ULL, 0xFAAD5D3E8F96B3DEULL, 0xFD72DF92928BD751ULL, 
            0x703BE6346FE40B99ULL, 0x9C55A6C291FFDF9CULL, 0xDED5573FDBCEFC97ULL, 0x36585BD1F233ADA5ULL
        },
        {
            0x376D7FE30838970CULL, 0xB14CC93E62C81A5BULL, 0x3907F8354503CD89ULL, 0xF2B117DADC5BA3C2ULL, 
            0xF53E9EAAF4D8DEAAULL, 0x6AEA1D9BC0F578A0ULL, 0x99670BEC08565D54ULL, 0xE016925230ACCEF3ULL, 
            0x992185230582B8D8ULL, 0x20105E7BD6F17F5FULL, 0x7F18F346403006D2ULL, 0x7591231BF8D19384ULL, 
            0x9AF277A596F62D3DULL, 0x0BE8153D35F327C3ULL, 0xF60982FCCE698659ULL, 0x5D771661922B3C2AULL, 
            0xAF267EDB54E6E994ULL, 0x73617F5F062124FCULL, 0xE7E6C86AE32C94C7ULL, 0x004CF109414F9CBDULL, 
            0xB15422D8EB3F80AAULL, 0xE0986F7A10582191ULL, 0x49D215A3ACD6029BULL, 0x3F2E336422F2DB82ULL, 
            0x3AEC1B757355010BULL, 0xB18BBD200C5F5FA7ULL, 0x38FA164A4E3C0A67ULL, 0xD8D7F051D7A9E9D5ULL, 
            0xBB3E092FF2F5A222ULL, 0xE4B0613143D2DE72ULL, 0xEC99AE092043DBCDULL, 0xF6FDD61A442F2F69ULL
        },
        {
            0x58FA2097A6847877ULL, 0x42405C6A1F5D6BA2ULL, 0x2E9757BD55801DFCULL, 0xAECC1A619156BCC1ULL, 
            0xDF2BF644B27FE8E9ULL, 0x87B56739F3FC8E39ULL, 0xC03B7F889D999486ULL, 0xBFC8261C8CB54897ULL, 
            0x4FC7993E12610CE6ULL, 0x2D663B466D0B4A2EULL, 0xD67D2F06989E4CD5ULL, 0xCE2916795F240090ULL, 
            0x28A329D21747DFA9ULL, 0x06F89B97561CF3D9ULL, 0x612D4D66A35585AEULL, 0xC8E55380413701DBULL, 
            0x9C1862348D9B56D8ULL, 0xFE56A349225D6885ULL, 0xC2294070FBE41885ULL, 0x9381C1C70C772D76ULL, 
            0x6029F145C0D20685ULL, 0xE1A185DD46F640BEULL, 0xCE84D71B793FC088ULL, 0x8328BAF7CBC0BA21ULL, 
            0x7D8D9D98601503F4ULL, 0x2EAF475B37AAFC55ULL, 0x9BC7E40FE3E97C5AULL, 0xFF1607743EA576DBULL, 
            0x433BA489CE582342ULL, 0x4A1086ED9FBB14F9ULL, 0x77336D2369A3D89FULL, 0xBD10C60277E043EAULL
        },
        {
            0xFD69DB67E0D7C4AFULL, 0xFEC133CE182E46F3ULL, 0xADF8F1B43320317BULL, 0x9705B859671FECD0ULL, 
            0xE6C79F11A1DFD802ULL, 0x35DA61B88AD27791ULL, 0x693EBC864218C9CAULL, 0xAEAB242CA9E2BF07ULL, 
            0x4CBA43A465BCB9B2ULL, 0x8EF7372587F6962BULL, 0x192504700FF0BCF6ULL, 0x69C235C5A1E200CCULL, 
            0xDCA4CC39601F2C39ULL, 0xEB1B25BF6F02FA72ULL, 0xA2C6F04E91A7BD82ULL, 0x053959E396A1C6A1ULL, 
            0x8119ABA0DB6393ECULL, 0xB2BBB1C6D2FE9B85ULL, 0x2DCFE470D7F172D3ULL, 0x6C5FC76058AABBE1ULL, 
            0xDFF63CA535C3187CULL, 0x53FF1B5272BEC277ULL, 0xCCEFCAD2EE77F792ULL, 0x8429B05D6421E5A5ULL, 
            0x46547F9F66C21BC8ULL, 0xC0964370150105E2ULL, 0xC36CBBD21B2DE4FFULL, 0x0CB9A40ADE569A60ULL, 
            0x3696A32F6D9F005CULL, 0xCE873D2687640D1DULL, 0x4CAFF811D0D7F7D7ULL, 0xC8554A760E8E873DULL
        },
        {
            0xE66F7D8297C64D09ULL, 0x0325BAD4F0E8C29DULL, 0x69F088E94C64545EULL, 0x4C3FE7D86B2653F8ULL, 
            0xC7270CC95278C559ULL, 0x5A29C11556322AA1ULL, 0x0768442127C2992BULL, 0x12C0084945BA3FB0ULL, 
            0xF052EAE1C69EF0BAULL, 0xF402A8A6AA9100ACULL, 0xAEE63B5A3CE65354ULL, 0xC1C56E5D89343BE5ULL, 
            0xB877EF7302916E42ULL, 0x0E67C326C27E4F39ULL, 0x9EABE59C113037B5ULL, 0xC7464CC233772C06ULL, 
            0x10D49FBA9C619945ULL, 0x96097214D7A619EDULL, 0x3AACB15FD400B43CULL, 0x86FB57F4CACDF961ULL, 
            0x0BC97AC1BA22F69CULL, 0x9355A1D6A8DD2792ULL, 0x093ED7CEF550123EULL, 0x251B3681E1813851ULL, 
            0x6085A90F11EBE319ULL, 0xD8EF116B0A299004ULL, 0xC73509069DD70C23ULL, 0x826BCF6D78436DB0ULL, 
            0xA3CB1C8E631E9A02ULL, 0xE86CC001037A8243ULL, 0xFBDE6BB896664DEDULL, 0xC9AC3A550F64DB42ULL
        }
    },
    {
        {
            0xEB059C5971480CC0ULL, 0x9F6193EED7E89DDFULL, 0xDF5561696DFA6CAAULL, 0xBFF89C746AA97CE1ULL, 
            0xDD22602A9A30290AULL, 0x0697210A8D12ACABULL, 0x101CBC3AC779A70FULL, 0x14812359AFB2C3F2ULL, 
            0x5D8AFB00F3D2D839ULL, 0xC78B25A19B7035CCULL, 0xDEC8D43FBC50CEA8ULL, 0x4486F184337B6344ULL, 
            0x4932EF542C443939ULL, 0x036B43693BAB82A6ULL, 0xB06731CAEDAC49C6ULL, 0xB12B9DD04BFA3222ULL, 
            0x1A261BC6A345B2F3ULL, 0x3964738361A5727DULL, 0x836F3BE0C11FA145ULL, 0x309A2CD8C4846F22ULL, 
            0x9649AEFBDF5A926AULL, 0x96C534829A3B330DULL, 0xA6B58A61385520B4ULL, 0xCE18DD0815BF48A0ULL, 
            0x239313D9C3C3CD5EULL, 0x4A5A707DA55CD577ULL, 0x33AD888D180164A6ULL, 0xDC8E240F213CB300ULL, 
            0x9A116A9C5D66C9F4ULL, 0x48211D65C5F439C6ULL, 0x712375DA3A3F5D9CULL, 0x2940838A7CB91C2AULL
        },
        {
            0x2CEC00452A19E319ULL, 0x46ACD74C8863EDA9ULL, 0x4F0D3AB0CA6C5FDBULL, 0x5193461B5DF4E83CULL, 
            0xB4F3DCBBD7349902ULL, 0x2D5DD4E314DEA8FCULL, 0x85A350A233FC0801ULL, 0x6CBD8700FFF454FEULL, 
            0xB47A16530656B69AULL, 0x0348992AC9325720ULL, 0xD8FC07126C999D61ULL, 0x4F241248038EAEF9ULL, 
            0x2D80CBB4F90D1B91ULL, 0x35C4FBEC27DB4304ULL, 0x2ADFA3A7585219B7ULL, 0xF81EB63924C99CFBULL, 
            0xF496160E90349F8DULL, 0xF0C7A8C64AD99297ULL, 0xF16169D6CBBC774DULL, 0x07A97170369B0929ULL, 
            0xB910E828C9741463ULL, 0xB74BD3C11B6DB747ULL, 0x5ED810E6D1E77666ULL, 0x849CB3288D381DFEULL, 
            0xA7BE8880BFA2984DULL, 0xA0DB821A1ACFFD85ULL, 0xE786B162B7F1818AULL, 0x8CEB2C54B89AF7D2ULL, 
            0x9F2D40C3954C3DA2ULL, 0x51B4BBE4CEE0FD91ULL, 0x09ED7785134E7911ULL, 0xEB8BC4BA8A39CCA7ULL
        },
        {
            0x918C53690BE233FDULL, 0xEDC2CA5E43FA6FDFULL, 0x2C2313DF0C1A7535ULL, 0xB20E7BB25EE1572EULL, 
            0x265B25202EA04CADULL, 0xBD61F95B977624C3ULL, 0xD9FBD3C0772E1C89ULL, 0xDE1FFD11E3758008ULL, 
            0xF8BB1E88B39F24CFULL, 0x30FD50BF91786ACCULL, 0xDF3FD4DB9AC13564ULL, 0x8818225CD60C8EBEULL, 
            0x9B69AD5FAF9B4F86ULL, 0xF9B05BABDDBFBD48ULL, 0xB0D80E75EA017C56ULL, 0x9B6BD40489F3CAD6ULL, 
            0x0CD3BA98D104DD1CULL, 0x6945801C19042822ULL, 0xF522C4ABAF99EE2EULL, 0x86E0395417A11101ULL, 
            0x189CF82D5664B2ECULL, 0x0B79DE78D2BA0924ULL, 0x4A5BF1CCF86E2C23ULL, 0x799572FBCCD1A599ULL, 
            0x5F43FB4C35CF5DF3ULL, 0xCC8222AB7F39C2B6ULL, 0xA08FB2518F2FAE27ULL, 0xB9DB87BBED162A33ULL, 
            0x72CDFBFB4866B602ULL, 0x9628CDB0D178D368ULL, 0x850E8D62DDB88343ULL, 0x2018B81A422278BEULL
        },
        {
            0xB4F03D857B4C468AULL, 0x137F706920FEF36EULL, 0x750974FD6C7AEA83ULL, 0xBF7F5107316D78D3ULL, 
            0xE43C09A891C4E6D1ULL, 0xC27F7051398C5CB3ULL, 0x2199E970CE9BF24FULL, 0x25DFD9C695F90746ULL, 
            0x5AB734CA204CB4E0ULL, 0x90A885DB8C317574ULL, 0x2E0C7C8E5E58B577ULL, 0x8D715D4ABF36AF9DULL, 
            0xF0694CBC40649278ULL, 0x634B922793A78D2DULL, 0xC1AE3688396549A5ULL, 0xC66B27DA8D5F9238ULL, 
            0x7FC6154E3B11C006ULL, 0x27BAD9F4A990C43EULL, 0xACFB8C5234E29614ULL, 0xAC576C125EAE85A3ULL, 
            0x84B3CD8960AFC911ULL, 0xFA643C904278D789ULL, 0x9C746044F16141E5ULL, 0xBE0DC9CABA657A5EULL, 
            0x179BE036900197F8ULL, 0xA4334D1F26D9DD4EULL, 0x77CD70739CA280BBULL, 0xF5AC517AFF2CF69DULL, 
            0x17824714AF9942C8ULL, 0x2B94FE9EFB475348ULL, 0xDD1704BD91D8EAB1ULL, 0x75337E3740F88D19ULL
        },
        {
            0x40D8CAD8DF2ABAEFULL, 0x499D4DF207645835ULL, 0xB1D9E13BF7963DFAULL, 0x8601CB7377104FFEULL, 
            0xB127CA8D64908749ULL, 0x3EBB79F2802BE301ULL, 0x98D1636B20927E8EULL, 0xC9C486FC2B680820ULL, 
            0x7D06EDABF50515ECULL, 0xE25D2CE49AFAAE70ULL, 0xF1648689C40BE23AULL, 0x94BDDB5EB3A34E61ULL, 
            0x00783A58D0FD8739ULL, 0xA8ED2FECEC32C168ULL, 0x19B3901BB7180DABULL, 0xC8F0C77B511259D3ULL, 
            0xFBE93275DCE58B30ULL, 0x4EDABDCDB8C79C65ULL, 0x733F1EA9E7D45510ULL, 0xED3238CF833E591DULL, 
            0xA5B50C72927D9D92ULL, 0x021523233F694856ULL, 0x5E08AD6E1FB9687EULL, 0xB5EAA0190C752445ULL, 
            0x19981D6A54819D11ULL, 0x642BFC236714CDE0ULL, 0x4EB04ACFCB93BE8CULL, 0xD1D38D10F4FA2860ULL, 
            0x17CE63FC1544637BULL, 0xB6649AB92BC89D5DULL, 0xFEAB0265B06F2D8DULL, 0xAA52C8E77313A204ULL
        },
        {
            0x74B1EE5816FE2566ULL, 0x5F8C403CD8E3CDC8ULL, 0x1D466C69912492D9ULL, 0xF5F41315E10E9186ULL, 
            0x55CB88477F1732FEULL, 0x8968D89634292171ULL, 0x2692FF488739C6FDULL, 0x2CABA48FFE5E77BAULL, 
            0x500195B8125CECEAULL, 0xAE5AA15959C82CF9ULL, 0x16379EF4AB8BF573ULL, 0xCEA1CA39786697B9ULL, 
            0x7E704F68ED7A7143ULL, 0xE9C9E51C7D40D67FULL, 0x309A6682A63D54DDULL, 0x65B8291D7A334BD9ULL, 
            0x21AE6D4C491F0885ULL, 0xBA6017F41C70118FULL, 0xF3BC61543ED20FDBULL, 0x477F88818E5D1CDBULL, 
            0xC31BC5F630A82BBCULL, 0xD3A93499F058F10EULL, 0x552311D6A9F04640ULL, 0x2C16133031532FA4ULL, 
            0x8AFBD74FFD2C1ACAULL, 0x40C00DF953D868C7ULL, 0xA8FEC63D2A808E7CULL, 0x6403E304257644D9ULL, 
            0x4578A38526E30D94ULL, 0x7CA67F03BD8EF86CULL, 0xE3CC0F40CD319F16ULL, 0xA23DF3547F56DA87ULL
        }
    },
    {
        {
            0x2EE23DF2866FD6EDULL, 0x5FBF8A38B567229FULL, 0x3111C1693B06898AULL, 0x166603F5249DE536ULL, 
            0xD4F50A1514B3D2C6ULL, 0x2DB7DF3F549C0E36ULL, 0x2AD13E65C6FB3A06ULL, 0x2851293AFA91587FULL, 
            0x82EC8480615D0389ULL, 0x4999751A5A459208ULL, 0xA31FB27A615CE332ULL, 0xDDB47BE36506509CULL, 
            0x722B5BEFE4EF0A74ULL, 0x640ACCB787898821ULL, 0x6308FD06CDAAD9C0ULL, 0xA5B16AB6668E698EULL, 
            0x94C385699538368BULL, 0x0842B238EC65525DULL, 0xAF734EDF3DA294D4ULL, 0x8E2FDCB02B86137BULL, 
            0x78AE01CEC4C5EDA4ULL, 0xD448C975994B6127ULL, 0x8B79CBFAD404DF4CULL, 0x08F91154DA36F53EULL, 
            0xE8333C621358E7FEULL, 0xD4D25CB991EFA3EBULL, 0xE62E59368F4C5D6EULL, 0x99FA9372A8573F4FULL, 
            0xA7B72B3F23FAD46FULL, 0x12C3806467839179ULL, 0x0B9052AAC570C746ULL, 0xFBC6B35644BEA405ULL
        },
        {
            0xBCB6C54C2DEBBC49ULL, 0x8E756C2B208EA479ULL, 0xEA7D8D53C8E971F0ULL, 0x6C986F841B12DBE3ULL, 
            0x5F4F4583A8333124ULL, 0xE9268795E1C81F13ULL, 0xE889A30D28A15452ULL, 0x637E20AA22D11BEDULL, 
            0x6072D7F853732599ULL, 0x1709C301FE1C89C2ULL, 0x26FB576F793251D0ULL, 0x772B51D35E6B9D1FULL, 
            0x939F699159B45BCBULL, 0x2AE3BE432E057036ULL, 0xF8D94D4B605876A8ULL, 0xA1F62C0C45B85F00ULL, 
            0xD642233C283E4539ULL, 0xA526579BB2F817ACULL, 0x6D7D351C45429A98ULL, 0xDE230077D11DFC52ULL, 
            0x1099812DA65C7026ULL, 0xB9FD5E0620C4945AULL, 0xCD410DA26E3211CCULL, 0x51638E78852DBB19ULL, 
            0xCEC5E29A31F53AD9ULL, 0x8605F6E0DAF7EBDEULL, 0x3D5D9FB5D87A7D9AULL, 0x61E18A4E9084F8F2ULL, 
            0x1530BF24EA50370DULL, 0x08252F6EB477B168ULL, 0xDDB3CC27D3E19E03ULL, 0x9EF01F8750F602C3ULL
        },
        {
            0xDB46D1A847B639E8ULL, 0xE22F2D328B63CE74ULL, 0xCF27B9470A25B8EDULL, 0xEA124DFEA0434D43ULL, 
            0x23BD72E8AA935AF1ULL, 0x71810B0C27C9490AULL, 0x483DD5B481754F67ULL, 0x2E1DC6894DAD0291ULL, 
            0xAE5A531B14A85032ULL, 0x30B486CCE4345158ULL, 0x0D82A5F9A5628F41ULL, 0xFEA85A4555D42D73ULL, 
            0xB25CC5BB6E8D2B95ULL, 0x312455ADB2D7BC91ULL, 0xD1452C19C1B6B747ULL, 0x5279A8F61E07D8DEULL, 
            0xDF7BFB0EDCA59E29ULL, 0xC3D63A4CBB8D118BULL, 0xC061B3B4CC19615BULL, 0x102ADB371501AFD3ULL, 
            0x8B5E7A0610BDC7EFULL, 0x74CCC23AD5CD7A44ULL, 0x921BDD08FCACC31DULL, 0xE6973E592CFA9019ULL, 
            0x5DDA4ECFB7C70A67ULL, 0x4997FFDFE0DADB08ULL, 0xE83783AF86A293B7ULL, 0x9F573D3E0BBCE809ULL, 
            0x93062600269979E4ULL, 0xE7715199BDCE12B2ULL, 0xFA7AE2397A792F18ULL, 0xAFB59C01AF1BDC3EULL
        },
        {
            0x40E9C6CFC3BF34D2ULL, 0x4116C76C783E9537ULL, 0xC641638D0232BB56ULL, 0x620DE908B908DC75ULL, 
            0xE51DE23E80F494F3ULL, 0xF567F53F602B98DAULL, 0xF35D6354C9C08872ULL, 0x4EE383CBC2F20277ULL, 
            0xCA6B3D21A936CF16ULL, 0xB62FD689ED60B664ULL, 0x1607DF650115B35DULL, 0x7867E74903C29D8EULL, 
            0xDF23FF46CC9E13D4ULL, 0x2B9C6D3C585B5A88ULL, 0x7258EB7D54F1D38CULL, 0x8872377C883124EDULL, 
            0x8DE2EA930EF235A6ULL, 0xB5E149D8241BAD76ULL, 0x184638E631AC6E09ULL, 0x75EB9F4A1501FBA1ULL, 
            0x28AAA98A17ECFBEBULL, 0x9FBBB7EE1612CCEBULL, 0x4564FC4D08786AC9ULL, 0x4FCB1305BCF12965ULL, 
            0xEAD648991C9928B1ULL, 0x427DCD2D219D8D23ULL, 0x7355165D29FD53FFULL, 0xC2F5CAA4EEEEF5C0ULL, 
            0x3B2542B7D3DBA901ULL, 0xB32EEA02012C533DULL, 0x96517B2A2E076592ULL, 0xE56DEFA6D66CEC0FULL
        },
        {
            0xCABE251F094C1974ULL, 0x0835F23878F16A9EULL, 0xBF3AFA59D2FCD524ULL, 0xA3E70B253A293013ULL, 
            0x1784418656C363CAULL, 0x93C02EEFD96B0640ULL, 0x237D398A3AC93CDDULL, 0x9A0C43FDD017F3C0ULL, 
            0x8B4C892812FB830BULL, 0x528891B4C7F8BC81ULL, 0x53CE6A2786036DC1ULL, 0xC3584379CFE0ED71ULL, 
            0x1E9ABDD101622F66ULL, 0x531DEFD4F49AD213ULL, 0xB39E3D82A4FD3830ULL, 0x2E2966B94C452DCBULL, 
            0xFADCE2B4C284BE74ULL, 0x21E35548864631D5ULL, 0xD38B2F6EC7F8EE4FULL, 0xD0440A41C4C8CC70ULL, 
            0x30F4EA327EC0379FULL, 0x2E8402EC9D0A5993ULL, 0x670F75FF95996F4CULL, 0xB2DC549593CFA5BCULL, 
            0x50A371B9D31A8076ULL, 0x796122446C8EBADAULL, 0x0DCC93CABB245DC2ULL, 0x4C2949D90A3F10EFULL, 
            0xFC0C00CB1CD29049ULL, 0xA557574B69D8E3F7ULL, 0x58F1DF5E0DA7D898ULL, 0xF2ADA1E1B457DCADULL
        },
        {
            0x20BAC0897C4D8466ULL, 0x21DC3EC6B50C4CE2ULL, 0xF5B5C26FCD07C30CULL, 0x47794DAFCD25977FULL, 
            0x86B6CF745CAA8F5BULL, 0x271F7D058FBF3B65ULL, 0x4A572BBA0568D911ULL, 0xD23AB4FC122EF192ULL, 
            0xCB9384DE3DED540DULL, 0xC7033AA85D8077C1ULL, 0x44FA49A506868CF9ULL, 0x5E665AE4D16CFD7BULL, 
            0x08CAA9C4DE03274BULL, 0x2E446E2D565C6F86ULL, 0x2403373ABB820796ULL, 0x58F19327AC672B2FULL, 
            0x2D0C4125F8DF9E96ULL, 0x6E1E8355866C8DF9ULL, 0xE22258B8A9A0B7E4ULL, 0xA1396B7202F12F00ULL, 
            0xF1D413BA23C700AFULL, 0xA4B6B7782657258CULL, 0x7EDAFA6ED64CA4B9ULL, 0x2538D3058049819CULL, 
            0xF16A24DAABCC0CAAULL, 0x957A683F8780A6D9ULL, 0xDF51B8C51C2DF948ULL, 0x94D3FDEC109A618FULL, 
            0xE2336971BD74A136ULL, 0xCA87D9B86AB8B76EULL, 0x576F3513C786E941ULL, 0x8866EC59DCCAF3F6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseBConstants = {
    0xEE1E403D4F49B022ULL,
    0x56464414B3A27B88ULL,
    0x911F73D93CF5E8A4ULL,
    0xEE1E403D4F49B022ULL,
    0x56464414B3A27B88ULL,
    0x911F73D93CF5E8A4ULL,
    0x1FC9401889606B8CULL,
    0x6592B6EE3A61009BULL,
    0x0A,
    0xE5,
    0xDA,
    0x85,
    0x3F,
    0x84,
    0xEF,
    0x5F
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseCSalts = {
    {
        {
            0x06333076C929305FULL, 0xA014BF21E749B3E8ULL, 0xB3F32A31A775DAE7ULL, 0xBD75253D3A26F99AULL, 
            0x1660B3E8627A71E5ULL, 0x02192516BD2D85A4ULL, 0x565A2926E7E27309ULL, 0x3C37AE5CC23FE114ULL, 
            0x9A3F5813E1C055D6ULL, 0x35E74F26E2DD5DA9ULL, 0x23485AF578FD7985ULL, 0xBBC798FC77D3556FULL, 
            0x9678CFDD4B80183CULL, 0xEDABFFC20F324180ULL, 0xF1918D4A5BA91BF5ULL, 0x9D50E11BE066A046ULL, 
            0xD39837651C97C8DFULL, 0x8CCF5A2E59258522ULL, 0xED4777DE52B14C38ULL, 0x28D419222C01F346ULL, 
            0x90FF64842D3001FCULL, 0x47EC4E2A5A309743ULL, 0xB0FA4C765B06C13FULL, 0x1B849836AD3B9B54ULL, 
            0xB1AEBB90475D7D6FULL, 0xC6C4FBCEB61E367CULL, 0x9894383FA5E1F477ULL, 0x3125122E44850896ULL, 
            0x94F1D2561743452EULL, 0x714B6BD8AFB62E8DULL, 0x9C66499B2D53979CULL, 0x1BB4459269B06064ULL
        },
        {
            0xD1156F3E40B65EEBULL, 0x8F8435E8A3C41E59ULL, 0xC97B5584E25EB1CBULL, 0xE26B33E6EE01C34AULL, 
            0xC63C6D8CF1321C3BULL, 0xDEBA4388D675948DULL, 0xBB336F4C8F3A12ABULL, 0x3953E106B7EBCB96ULL, 
            0x909231B68505F9B9ULL, 0x79386BF2E0533079ULL, 0xE3730A147138D1D0ULL, 0x8BF26D811CE808EFULL, 
            0xB2F7728EAB10A926ULL, 0xB26598AEC7BAE64FULL, 0x5671C89476F4F838ULL, 0xCB92C9B9FAD9D611ULL, 
            0x05F6F8F5DA57D158ULL, 0x4E27B4DA47682818ULL, 0xE764CA200EF9B047ULL, 0xD4180765F4F31026ULL, 
            0x026E17FD5D915FF1ULL, 0xB5A3CA65590E20A5ULL, 0xD0729C7DD52C75E1ULL, 0x2C1CF0E981741B30ULL, 
            0x29BF37D98AE97EB1ULL, 0x85D95D594513479CULL, 0x7A9697CBB0007078ULL, 0xEEEEEB0965BCA9FCULL, 
            0xA981DE5E1BCD450CULL, 0xE50DED0BC587F88FULL, 0x32D570ABD00424C4ULL, 0xA70CAD8049BDD353ULL
        },
        {
            0x5C283A982FB4B357ULL, 0x446374B5CF9BF6B3ULL, 0x063F35BC664798B0ULL, 0x228B771874E745B8ULL, 
            0x154AE6656982D9CBULL, 0x7737188295CDDF01ULL, 0x6B420CD610442EB2ULL, 0x8F6A1DADECC46E23ULL, 
            0x63D5A7F92D39D166ULL, 0x64761B9EEC8CBA40ULL, 0x2E5C9BE71254FBFEULL, 0xCB3E7D14A8E18B84ULL, 
            0x38E4044968283B5CULL, 0x562FB430DD12C960ULL, 0xC976CB09FCBDFF25ULL, 0x099417E09A81FB11ULL, 
            0x24D87CFF9979EEC8ULL, 0x10B50BE0728BCE21ULL, 0xB9D54BE8F2CE6A9DULL, 0xB287BAC2DF15202DULL, 
            0xEA9DC9ADA5E48248ULL, 0xC246F5E2A4562541ULL, 0x7EBE0797A12A32B1ULL, 0xF817CAC2AEE265B6ULL, 
            0x114B6C7A298E1606ULL, 0x0F01AAE31C3E33B1ULL, 0x64B81A170405CB9AULL, 0x5879D12569B13EC4ULL, 
            0xDDA206330E60B785ULL, 0xF8E06964DA2B82D8ULL, 0x259AF6D7C1C3E911ULL, 0x1AC2E5C782E2B707ULL
        },
        {
            0x2CA3F944C4BF38A6ULL, 0xCDA7CE5FE98C05D7ULL, 0x9F12949800C0D0E3ULL, 0x463A352ACE074327ULL, 
            0xEC9021B3D5882E28ULL, 0xA82334504F99A7A2ULL, 0x7CC006B5C8A6C8FFULL, 0x724F55B30254AAD3ULL, 
            0x9DF6823C4B595FC1ULL, 0xED09F811CEBD7A41ULL, 0xFEB9070F8E0EA1EEULL, 0xC79F17FEEA9BED52ULL, 
            0x640479060730A0D8ULL, 0xC767543C21E47121ULL, 0xA3FDADFD8ECEC007ULL, 0x1224942A5E914071ULL, 
            0x1231B2280AB7692EULL, 0x3637C8FC39E0B785ULL, 0x825343DB7D52215FULL, 0xEC381AF8EFCCBFE2ULL, 
            0xA189CCEE278B1DAEULL, 0x9E60547BFE826A6CULL, 0xD2B6F2BD0ADA102FULL, 0x308187873F310378ULL, 
            0xAC1D3B3C482A725DULL, 0x19D891A1D6A57315ULL, 0x9D80041C09BE9636ULL, 0xED222235AC001A7BULL, 
            0x7859A352F0A2CD3FULL, 0x222C8808E78711FBULL, 0x7C3044C3EECF5800ULL, 0x8AFB6383ED86687DULL
        },
        {
            0xE8A3709297FD36EFULL, 0x7D5BE0A800988AFEULL, 0x6E0B0C77F3643B24ULL, 0xF4B1A55663AE2760ULL, 
            0x22F83800890421D0ULL, 0xE13AFB9F63286A1DULL, 0xE4E645B78D55A02FULL, 0x00496C4B45D2EB23ULL, 
            0x4B3FD9C89E3ABD9DULL, 0xD469AA91BC6881C1ULL, 0x5B072154D3CE5D42ULL, 0xCDA1A56615876974ULL, 
            0xC301217F45DA9780ULL, 0x76C4D2C4F19C4A5DULL, 0xE1560A07BECA2A9BULL, 0x51E631D2D91F0BDAULL, 
            0x071834234A311F7EULL, 0x8CE173DE61EEDC1FULL, 0xA7FAF8F110CE4287ULL, 0x8CDEF6E2C8D7BC0CULL, 
            0x4D691D4F0836F86EULL, 0x5C6F3A3E25C0764AULL, 0xC2B051B475398461ULL, 0xF867F91632498993ULL, 
            0x202449ABD1D77E6DULL, 0x5785100B83AAE893ULL, 0xB869161E80895440ULL, 0x21A412ED0DD01B7AULL, 
            0x522F26FC1AE7421AULL, 0xBF36B5A27A2F3A33ULL, 0x308A6CC836B61F5BULL, 0x21C0315E798F2780ULL
        },
        {
            0xF76781F6DC3C5035ULL, 0x389E3484B6E215E9ULL, 0x5873B35F2DAA6D56ULL, 0x5C911F97A127D50DULL, 
            0x09F97F03401D46B8ULL, 0x72D3A41FAA6ECD53ULL, 0x42F1A1565C56B53AULL, 0x99786A4627B54061ULL, 
            0xE67617E8A56AA1D8ULL, 0xB5F17A5DD0036751ULL, 0x57C133AB70472649ULL, 0x108BA82E0F0B689AULL, 
            0x7E83B8BFDE05DB28ULL, 0xC79CAEDDF246FE68ULL, 0xEE6E630593499F88ULL, 0xD04B0AD69DCDFA77ULL, 
            0x133E2EAC08E9B2C9ULL, 0xC3A3080C598F06B4ULL, 0x97ACC1B46DF4C30AULL, 0xD0A8BA0F0DDB176FULL, 
            0x884B6BD2E652CF08ULL, 0x05627D3B4F6322E3ULL, 0xB84739140324D98CULL, 0x2055FD56338E17B2ULL, 
            0x8EB5F924CAB60E0EULL, 0x9D36DA452431B1A5ULL, 0x0DDA809F69A64DB0ULL, 0xC77334CCD59D41D3ULL, 
            0x08DE9D877E769E35ULL, 0x1742430B382EB749ULL, 0x25A4C87B2EBD7B9EULL, 0x45BCA40E19F9EF61ULL
        }
    },
    {
        {
            0x9C65B370E13A616EULL, 0x8C32859EB156BAFFULL, 0xFB447CE0D0FDD239ULL, 0x8600C94037AC472DULL, 
            0xB2DFDE9A6B50A27CULL, 0xE2A0A41C6A2F351BULL, 0x18EC484C3A638218ULL, 0xCE4D4BA5ADE77B67ULL, 
            0x99F64C8C12D3A0D1ULL, 0x18016E6C2D26278EULL, 0xD1189FAB2989271AULL, 0x1B528CC13F24467CULL, 
            0x0D610C3F27B1121FULL, 0xA1E69998E11D91CEULL, 0xB4DE1D1335F4FECAULL, 0x5D182D1AFF0E27B7ULL, 
            0x6894FCCBB3FA1CD9ULL, 0x843C3F124459E6CBULL, 0xEED4066BA35D545AULL, 0x8682ADCF6010779CULL, 
            0xB16B1C900878398EULL, 0xEDA2B85D944FBC09ULL, 0x499700A3AF541EAEULL, 0x8B2A2A1A04C118E6ULL, 
            0x4BC402E4E37D9F54ULL, 0xE778A9080548DF26ULL, 0x7D2B103928330DA8ULL, 0x9558600696B1FBF0ULL, 
            0xB639685885DD3812ULL, 0xC5DC0DFCA911FE0DULL, 0xEA351CC85F2D4E09ULL, 0x48212FC06D96F715ULL
        },
        {
            0x7FEE536EA05A061AULL, 0x01968EC2B9315435ULL, 0x418F1FC65E779266ULL, 0x9E17BEE75331B268ULL, 
            0xE57971F52CA7185FULL, 0x22EC550921BBC2CFULL, 0xE071369D7BB197B7ULL, 0xD522DE00620B0302ULL, 
            0xD879C131D559463CULL, 0x7156B0A80369624AULL, 0x92F8696DDF36D42EULL, 0xB44E57E09FE3001BULL, 
            0x53D43ED315EFC17AULL, 0x4861BAE2FD5252A7ULL, 0x4762A73F449F7A77ULL, 0x6E8B08D9324FCB67ULL, 
            0x143F37F22545615EULL, 0xA91454CC646868C9ULL, 0x712149995479B832ULL, 0x82934C9AE2CAB6D2ULL, 
            0x7C339BAA23822D2BULL, 0xC198429567CDC527ULL, 0xA475F2D9112E0C93ULL, 0xA33B9C22CC5A8F5AULL, 
            0xD5BC12DF0A57AB63ULL, 0x51D87602F36AC036ULL, 0x1BECE1BEE7DE706BULL, 0x5C2A6273D4CD6CD3ULL, 
            0xE1505841F2CECA3AULL, 0x2516C44604BE4B76ULL, 0x660A9FD4F18EE7C3ULL, 0x51C5DD35190753E8ULL
        },
        {
            0x86E4C27385266538ULL, 0x267FD6A622950FA1ULL, 0x9BE0866DC6F70EFBULL, 0x5711840CC5B9C96FULL, 
            0xD49D42970A6E54FCULL, 0xE6C0C6CBE37DB8CAULL, 0xD8393438FD8CE00BULL, 0xE476489BCC863843ULL, 
            0xB2103FEB8A44C71EULL, 0x7403FE634E7C6CE2ULL, 0x8FABBAFA9CF4392FULL, 0xCA4A0488E2E91803ULL, 
            0x7D7EB504349D7EC6ULL, 0xBC26DDF05962B08AULL, 0x3A90886D2EB2C349ULL, 0xA6E2511121FBD694ULL, 
            0x1F034D4679A02BA2ULL, 0x090DDB10A286E602ULL, 0x999BBE152E74DC71ULL, 0x89C0B31FBA83FE26ULL, 
            0xB37B48848D7FC76AULL, 0xE2922309B6B2B39DULL, 0x0C315EB5F0101D75ULL, 0xB93CB42F2EC64A57ULL, 
            0xFF8882D48D59A040ULL, 0xD048B69049164B82ULL, 0xE3FDC47E23F09AE9ULL, 0xFECAA73AEB57BB2FULL, 
            0xFA6B8789A4A9DF28ULL, 0xC03D6D535584F1C1ULL, 0xA95F032A85F67C2BULL, 0xA42B0734B6D6B87AULL
        },
        {
            0x2EA264DC9DE8AD6BULL, 0x9EBFC47D5BD558EEULL, 0x06D9EC7BB5DA6BFCULL, 0xCEA1DDAAA2EA126CULL, 
            0xC7705E520D506F59ULL, 0x4A8F1AADBC93CF03ULL, 0x150737298FF1D719ULL, 0x380060CBA61CC494ULL, 
            0x67E350F6F6B754BFULL, 0x766B3AB2B8AB17F8ULL, 0xC3C46D42E0A23DD5ULL, 0xEC4AD0A385EE5442ULL, 
            0x70A3239251A21E03ULL, 0x0A0DC65E0F83357AULL, 0x9A2DD402DCE7C60FULL, 0x590053ADE54CE7E6ULL, 
            0x4B568FE64ABF9CB2ULL, 0xC952A071D2017012ULL, 0x54EE6EE7A36299A6ULL, 0x80FEB85D87614590ULL, 
            0x8A9005342E736EEBULL, 0x1FACBD5A295E7610ULL, 0x125F28553C07096AULL, 0xECAC7AFE0023D667ULL, 
            0x518C39A1094E8905ULL, 0x97FF02207AE1100BULL, 0x68F96D43C994692FULL, 0x5808EFE50C47D5BAULL, 
            0xEEB4AD385B0F67B9ULL, 0x7197FB8FF1099CF1ULL, 0x4A1D6130440DF11AULL, 0x2FD1C6958F5D5AE8ULL
        },
        {
            0x10F5863EE94F9D9FULL, 0x278234DB464DC08DULL, 0x179463B3C462894CULL, 0x145A616E4FB95273ULL, 
            0x382E95808247BC9FULL, 0xBC4BDFCBD8BB6FBCULL, 0x9D8BE522EF010478ULL, 0x9CD95161AB2DBD61ULL, 
            0x674E1BDE102C65EDULL, 0x38742A203F7A4D41ULL, 0xD41B45FF2752AB16ULL, 0x1A1F2D0CAFD2FF67ULL, 
            0x3F0E77F56B416408ULL, 0x8AA05E22186624ECULL, 0xC14EA3ED4CA81B2AULL, 0xA0D2204E0AF3D709ULL, 
            0x3B3E101E2780426AULL, 0x9F79B68CEA939607ULL, 0xB19310F559F5280FULL, 0x41AF4E086DBFDCCDULL, 
            0xD5C6D364C9F8311FULL, 0x5E0F3999CCA2113CULL, 0x8C81ED65B20BAA13ULL, 0xC649A143DE6D9CCDULL, 
            0xD447A0C85A9B098CULL, 0xB458478F866C862FULL, 0x17574228097CE026ULL, 0x2BD9A354D90AE3D6ULL, 
            0x71CEF26286E4D232ULL, 0xA8B183AC8B69C141ULL, 0xFDF51B4C0DADBB5AULL, 0xF62DD3A3E298E1A4ULL
        },
        {
            0x20D99833BEF10680ULL, 0xFD49B626E14BA5EEULL, 0xF5777C9EA35A4C01ULL, 0x2E4CBB08CE09D10DULL, 
            0x22D9C51EDD81E160ULL, 0xFC8A77EBEE017076ULL, 0x5455978F09BF5473ULL, 0x32FF1BEB59E97148ULL, 
            0x42D75FB0BCF2D6F6ULL, 0x024292B24A267EEEULL, 0xA35A741B2485708AULL, 0x97EC400E4CF874ABULL, 
            0xDF137318BACB8FACULL, 0x8C10A8F7103F7562ULL, 0x3D5ACE0769EB27BEULL, 0xD3CFB293FAF0561DULL, 
            0x958503676705BC97ULL, 0xCB77AFB5C40BADE9ULL, 0xFA5CD78C8452925FULL, 0x55EDC93593FF0BF5ULL, 
            0xA510BD1F7CBBF138ULL, 0xD54A707E9240E1CBULL, 0x8BAF3033C7DE6C7DULL, 0x1B02432E100046D1ULL, 
            0x47A7EBB86BFFF77EULL, 0xC621041BC7D32C4CULL, 0xBB388517E4B60DDDULL, 0x8E103B175B68EE5FULL, 
            0xD1CEB10F62ABBAEFULL, 0x6866C72CE10A0D6DULL, 0x3094B11678FB7E06ULL, 0xF877AEDFD6882275ULL
        }
    },
    {
        {
            0xD45BA2E70C216366ULL, 0x4D2D7DA687A7C224ULL, 0xAE7E8DB3A9A5BFFDULL, 0x26C4AA6DDBC3C76BULL, 
            0x88F5699C3A5AB948ULL, 0x115B6AC3FD5B3807ULL, 0x2E35170AE8472C60ULL, 0x779164E8CC7BFE60ULL, 
            0x6E6172CC52938996ULL, 0x712D92644BD6F737ULL, 0x50C4F334DF96DEC4ULL, 0x029B6F883F419478ULL, 
            0x873FE0793F24DBF5ULL, 0x6876BA422B542244ULL, 0x542E68683941F788ULL, 0x817D8BE12956060AULL, 
            0xF9E640B7F7C725F9ULL, 0x05788D520EC20407ULL, 0x02D7AEC567711B17ULL, 0xFDF151D2757CBD57ULL, 
            0xB6EA0F95BBC08384ULL, 0x6A4F64957605BC46ULL, 0x1A1076A77ADA24BDULL, 0x38E828DE7F1C8791ULL, 
            0xB8F1CDEC88C753D9ULL, 0xB7519B1C8B772C92ULL, 0xC888966958364FA5ULL, 0xD7C8AB99A926D30BULL, 
            0xA5D9703D848D01F7ULL, 0x263380A4D8752372ULL, 0x590EA660854D7956ULL, 0x2988FD073B2F8261ULL
        },
        {
            0x09BE29CE393D0783ULL, 0x08E8FFBDA2E34A8BULL, 0xFD3607E66FDB06DBULL, 0xF472AF7DB05F7497ULL, 
            0x060329A49E8F751CULL, 0x2135D1D2DF2DBFADULL, 0x189333E74C5AEA8FULL, 0x1D3D3822CD15028CULL, 
            0x65FEFBFFC06D74F4ULL, 0xF1E116C7E3569F08ULL, 0xA932FC3D3F8BA634ULL, 0xB6BF1636584C48BEULL, 
            0x21C925D6B9528158ULL, 0xEC630F34AD939F2BULL, 0x501F976D1EF0D3CCULL, 0xA961E0527E46BA44ULL, 
            0xEFB09CA9BBC2D05DULL, 0xCBFE3EBAADD19516ULL, 0xA43D5DACCF124DC5ULL, 0x661B19FD18B3AC34ULL, 
            0x1F24E501F43C5A95ULL, 0x615A0DF0A9D168D2ULL, 0x35A46D40210EF2C4ULL, 0xB1287BEC445210CDULL, 
            0x84F1B4CFB7598519ULL, 0x293823A2F0FA86C9ULL, 0xD608851E7FE82D45ULL, 0x6A1981F5DECB9B02ULL, 
            0xDE70B6E5568D7845ULL, 0xA28C910823A90008ULL, 0xCA3DDBA6C484C723ULL, 0xA652DD64B40D2550ULL
        },
        {
            0x778C80F2D240C0F9ULL, 0x113616B60D365A2EULL, 0x043C170FAB77AC6CULL, 0xF33BEA06FD022E1DULL, 
            0xEAE5B5FF04954CC8ULL, 0x81201B19698D524BULL, 0x7EE4C68FD576D8A0ULL, 0xC8145DE47F1CD846ULL, 
            0xCD7DF6E53333BC02ULL, 0x63D9A75125C1B440ULL, 0x3584D2DC71A72F41ULL, 0xA66DC22FBAFC4C7AULL, 
            0xCB00E4838C9857D2ULL, 0x56133129EC2E9C00ULL, 0xD9DCEE37C379A31EULL, 0x97F70AC1DEA95214ULL, 
            0xA09162171D8D140FULL, 0x25ECF4FBD8949EA3ULL, 0xFB10A599487F8534ULL, 0xC9BF47E3A024AE66ULL, 
            0xA351424BBF516368ULL, 0x0881583DC693C9AAULL, 0xD22D3E45D8A82BF7ULL, 0xFC7D8A5BD330836DULL, 
            0x7B3505C3D675BF89ULL, 0x347BAA5E364E6972ULL, 0x51988BCC5BC3D49FULL, 0x60DDAAB5C9B9645BULL, 
            0x10815C22D142DC76ULL, 0x056AAE5BDA4DDB1FULL, 0xEB07572D3F01183BULL, 0x0D13550B77F008B1ULL
        },
        {
            0x3823A9C48170B2E5ULL, 0xE8E8FD39126A05E5ULL, 0x3C10E166AEC46CF6ULL, 0xC7D8520BA0CBD055ULL, 
            0x7B6C92C18C679FF4ULL, 0xA87D00921AB447BEULL, 0xCBAE517A7FE9F0FAULL, 0x23C764CB482F481AULL, 
            0x95EBCA12C0F20993ULL, 0x9B1C4170E2C28F12ULL, 0x8763CCF23C103676ULL, 0x446C0D8B8572E351ULL, 
            0xF901B468583A7864ULL, 0x32FC58D1B7291CA5ULL, 0x9B04C32A2AB1AF74ULL, 0x477DCB0EAAD99528ULL, 
            0x65A5DFE60EDD74A6ULL, 0x044C310147AC8465ULL, 0xF91F718788D6128DULL, 0x250BA44929330649ULL, 
            0x55853CB5E617EE3DULL, 0xF9F7634F514329E9ULL, 0x396ABF74BDDE4167ULL, 0xB730FEC9AD072F8AULL, 
            0x1BBE2019EEF63F3FULL, 0xF9F88203A68BB0BDULL, 0x856AF04F63CF6999ULL, 0x27DD6FF6A5EEB472ULL, 
            0xDD09C614AA31E972ULL, 0x47CADBE11A42CECEULL, 0x6E5D3ABB30B47C06ULL, 0xB4AF1F644E6F78A6ULL
        },
        {
            0xBBD993C4E27FD171ULL, 0x4958E3685D2953E5ULL, 0xE36F40CB967F9CFCULL, 0x0CEFD2F32DCB60EBULL, 
            0x24C053782B60F5D9ULL, 0x941E355D2B589376ULL, 0xBF18630A949B7495ULL, 0xF90A6E97DA328A0FULL, 
            0xB075C01EDE20FA4EULL, 0x05EC02047AE679F1ULL, 0x0B5897CF3EC0E34FULL, 0x5C314B9BFBFAEB16ULL, 
            0x55519D94B6DD6336ULL, 0x7DAA36BB667ABC8FULL, 0xC4CDF678EE1661A0ULL, 0xD8616D4FC5DEBA01ULL, 
            0xB9EEEBCD3DEAD844ULL, 0x99573DACD8F484DBULL, 0xCB3BB2322DCF1BCDULL, 0xD461A2CEB794C6E0ULL, 
            0x19EB899146B844B0ULL, 0x611977EF7A950116ULL, 0x7E60ED9DE637CCD1ULL, 0x77ECD3CE52D6E4B7ULL, 
            0x2F05BE300410E66CULL, 0x8BF824A961CBC98DULL, 0x15F971A16FA99A81ULL, 0x9C603AD9E39A0746ULL, 
            0xDAB23B05145A2465ULL, 0xDDE5E32CB37F1C59ULL, 0x5662ACD8FDE6635AULL, 0xF1D69BC1FFC2B982ULL
        },
        {
            0xD10B3192782A46DBULL, 0xBBDD7C0CD038B46FULL, 0xCA3DCD48780931FAULL, 0xBDD21430A4FD1D7DULL, 
            0x8B27C2B0B03D6418ULL, 0x597A5C7C4F0920EFULL, 0x23CF2E6F6C14F762ULL, 0xB141E8F8512761EAULL, 
            0xCD6802AFA8D28B0BULL, 0xE509CF8B44548DCDULL, 0xA552D6D4AA2268B4ULL, 0xF3CFC0C8C75CA457ULL, 
            0x4B0ED30CDE1794DCULL, 0xFE5073BB753B2034ULL, 0xF8ED5F58CB2A42F4ULL, 0x6AA9250BE723A6C2ULL, 
            0xA5793D2A143E48E3ULL, 0x0DF1AB152BDD3067ULL, 0x37C5D180B6BAC75AULL, 0x7E2EE821E9548D5FULL, 
            0xC1DADB28760695ABULL, 0xACDF6218504D5535ULL, 0xD0B76A226A611DFDULL, 0x32FE96A4C079FB50ULL, 
            0x78A14C1F4772A518ULL, 0x931BCEC09CA15C47ULL, 0x8404EC5F211AB42CULL, 0x83FDFA30C803AE6AULL, 
            0xA043C5F01020CFE5ULL, 0x36D682FF239D804DULL, 0x2050826886A847D6ULL, 0x817102349E524A49ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseCConstants = {
    0xDD659A9125A8F6E2ULL,
    0x9D88A54506BB7D48ULL,
    0x8AEAE527F66090D8ULL,
    0xDD659A9125A8F6E2ULL,
    0x9D88A54506BB7D48ULL,
    0x8AEAE527F66090D8ULL,
    0xBD47481F8B7595C0ULL,
    0x4D9459D74CC032B1ULL,
    0x87,
    0xEE,
    0x99,
    0x7B,
    0x47,
    0x9C,
    0xB3,
    0x64
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseDSalts = {
    {
        {
            0xA62AE1153F42B21DULL, 0x9259180032E3909BULL, 0xB7E869E576C58A80ULL, 0xE8F5F22EB6D06354ULL, 
            0x8495C9BC832B2061ULL, 0x0CC6967C6B0BC531ULL, 0xA72DAFE6499576EDULL, 0x77F66FB3DE343492ULL, 
            0xBA77DB26FE64E0D8ULL, 0x3FDCBF96939AFDEDULL, 0xF04DB0382E1AFFA7ULL, 0xFA36CABC8B6435E2ULL, 
            0x54C43F99327EF28FULL, 0xB4078BE50B4CA760ULL, 0xCFFF107F49CED54DULL, 0xFEBF56056D2937C2ULL, 
            0x06227A7DA3929647ULL, 0x04D0FD90B9DE7BB9ULL, 0xB75835A73E64580CULL, 0x3E94BF47B7FCC938ULL, 
            0xC52E5F049AB2769FULL, 0xB2081BA36552A56AULL, 0x39E91667DEB93AFDULL, 0x3453C03AB4793935ULL, 
            0x16EAF7A935B908A3ULL, 0x5963F5E87A1C63DCULL, 0x1A798455F26039FCULL, 0xB9C84AB68FEF63CCULL, 
            0x955E3C0375A4DD85ULL, 0xC379DA62A41EA068ULL, 0xAC37A52064F6D893ULL, 0x3D8ACFE345090A37ULL
        },
        {
            0xAF98F8BA71A0F8AEULL, 0x33947811E977E5C3ULL, 0xF28C7D33FE62B3C4ULL, 0xE03DCF8A4A4BC1B9ULL, 
            0x8E4F28D62299751AULL, 0xB48AD381BE6ACD9CULL, 0x08F828C9DC741D15ULL, 0x402E914823ACD08AULL, 
            0x1E1FCBBD137A60ABULL, 0xCFADD652309DABCEULL, 0xEB408163A9524247ULL, 0x6E3E4D19FB4B2089ULL, 
            0xE4B1D64AA03DEB2DULL, 0x89C36FE55722D06DULL, 0x2475C313E242F949ULL, 0xF5D85FA9BDDC1D86ULL, 
            0x1A477E8A143E6FFFULL, 0x59A72FA1E632C0FAULL, 0xEC9E8B7C69E03074ULL, 0xAE8D5D2A8E998216ULL, 
            0x83938A0F4B9FBED3ULL, 0x17A24E4A5D972438ULL, 0x2B6DB3B168143361ULL, 0x85CC54C0C4C64DD0ULL, 
            0x803C2AA561FC2343ULL, 0xD0EB5132377BF552ULL, 0xA3570B0431A32B44ULL, 0x9DE82B8885FE1AA3ULL, 
            0x767680E5ADF66157ULL, 0xA908EB5ADD281177ULL, 0x9BD7BAC57A65461EULL, 0x4DDF10C82F3789F5ULL
        },
        {
            0x4FBF2F5E5AC0B5AFULL, 0x20D07447A45C92EBULL, 0x0C12F84B40D46983ULL, 0xC6B224A545ABF2FFULL, 
            0xC0DEDCA793264E3FULL, 0xAF9319CBAA788B95ULL, 0xF6668F3EA701D0F3ULL, 0x6C05C61FCA26F129ULL, 
            0x2C55F940EB451E59ULL, 0x65734CD759B764D6ULL, 0x58F9D58D43C757B6ULL, 0x59E13E5FA21AD16FULL, 
            0x31D115DBD0929DDDULL, 0xF969593E91B02F2DULL, 0x026448028EFD3351ULL, 0x178325670123AE2FULL, 
            0x3394B9C5D2B18263ULL, 0x7E9AAC32520823F4ULL, 0x8669AF372C101489ULL, 0xC04691F2ED7B6A18ULL, 
            0x6236CBB9A0F4A89CULL, 0xD4CC824AB4869969ULL, 0xD92639162BD2756BULL, 0x28FD45567E7EDC72ULL, 
            0x23AFB48889DA3A14ULL, 0x41360E64BCE71B89ULL, 0x8DD9ADB9BAA321A6ULL, 0x02E2029C8B985438ULL, 
            0x55BAE56665CEFFDEULL, 0x4190DC4692AE4CA3ULL, 0x68F253D4D5058B55ULL, 0x8A4C8FFF1DE995A5ULL
        },
        {
            0x07D5095EABBD51EBULL, 0x97CD8AA6EF496A8FULL, 0x88FE8497196DFCBFULL, 0xAF40F9781F2699D0ULL, 
            0x4127FC4B04B90D19ULL, 0xCC66B25E9CFD062CULL, 0x3A074EE857072ED4ULL, 0xD736031923B14008ULL, 
            0xBEC37380D3921F95ULL, 0x134D91960631C4F3ULL, 0x2A569AF97907CC07ULL, 0xC42E0E4C1C99EE43ULL, 
            0x1563602D86B24608ULL, 0x7E645798DD488DF0ULL, 0xBDD14B80055D483FULL, 0x0E4EA9300DF50284ULL, 
            0x8D5628C8988CF795ULL, 0x123203E92FAB56ECULL, 0xDCA7486B60A6799AULL, 0x2B73F8E77839CDF8ULL, 
            0x519513B9EA342597ULL, 0x8F62882896200E15ULL, 0x1F6F1B02CCC81F64ULL, 0x00CF9EA69808EF12ULL, 
            0x020138BDB2AD79D0ULL, 0x54804FD49F54D57EULL, 0x4F17BBA54E59A4BDULL, 0x0C3F4BB4C5A72BAFULL, 
            0x01F822F9863E6F5BULL, 0xDCFA8F44571E87DFULL, 0xABFA18C5A7EB3C41ULL, 0x5E4D641B851172B3ULL
        },
        {
            0x4B1A4BDAD239C1C4ULL, 0x10ED4C04D43B51C1ULL, 0x117E1CAD140B5BCCULL, 0x40117A69B7D5893AULL, 
            0x91DF51B7FE67203CULL, 0x137BEE8A25532DCDULL, 0xADDAF8122D6B7169ULL, 0x9BDE6A805B38E8A0ULL, 
            0x95D86BCC2C89CECCULL, 0x74072A441FAF2FEDULL, 0x50725789973573B0ULL, 0xA3E6821609DFDCD9ULL, 
            0x895E9982561593B5ULL, 0x0E6D70B5A8F8DC82ULL, 0x10078D1837A9319FULL, 0x38D759B0676B6006ULL, 
            0x2712D95AFDB5D920ULL, 0x8CB109875491B679ULL, 0x26C71F81EBD5CF3FULL, 0x447C6F268F7F3003ULL, 
            0xDA249B3EB0049DB6ULL, 0xEEE62596DB7C9155ULL, 0x1B67BE1B5A01EDF6ULL, 0xFFE751A403BF3113ULL, 
            0x7F910A0028D2D992ULL, 0x70D9CB7E86535F57ULL, 0xA33B39C85278D878ULL, 0xA24357D19800EC50ULL, 
            0x744E995C92FDEB63ULL, 0x78DAAAC664B97BA1ULL, 0x689F0B0E4B9854A1ULL, 0x08ECD899D98876EAULL
        },
        {
            0x03861838DD603CADULL, 0x21D58EC84D0AC34CULL, 0x87D61B4FF3FA49A4ULL, 0x84AC1260F0DFF20CULL, 
            0xE76507A3CB014112ULL, 0x8BA7CE7492861305ULL, 0xA53E85163686B542ULL, 0x22B8C82634D819D3ULL, 
            0xA02EC928EDE5265BULL, 0x3BEE61B6A190F93AULL, 0x556B982C48516BBAULL, 0x78B637CECC970B96ULL, 
            0x0B96EB15C5443569ULL, 0xE10E3EFECC635A1AULL, 0x76754FA1286DBB95ULL, 0xFF38DFE9B8D1C2F8ULL, 
            0xB9FD2AFEBFAB5F09ULL, 0x6F60089E796D6D17ULL, 0xDD701B9AFE36CC45ULL, 0x0891D864336FE61BULL, 
            0xDE09A749CA86CF74ULL, 0x795DE1A755C80AA8ULL, 0x001EDAA9535A09BDULL, 0xC7F2331AAD8D7F5BULL, 
            0x667C8075424503D1ULL, 0xA211754A8E19FAF1ULL, 0xD3767070577B9E7FULL, 0xED5AEFEA8BBB99A4ULL, 
            0x6F5771AE0EE97496ULL, 0xC7892CE835527007ULL, 0x293E3ED6E1FDB447ULL, 0x27CDF53834DC747CULL
        }
    },
    {
        {
            0xB5C4A95077DE92C6ULL, 0x346E5D89CE4544C6ULL, 0x45C41A1D0C5F8C54ULL, 0x8A3A43522C663AE5ULL, 
            0x334E64390E21E558ULL, 0xC1F500898CE5CC54ULL, 0x2B63759688BA0EA6ULL, 0xE2AE6CB1A53129A5ULL, 
            0x5795F3D90F14F16CULL, 0x25866931F7827A78ULL, 0x5DFB377A652EE2E9ULL, 0xBDF75BF222F56357ULL, 
            0x531E6785FCCD3F6FULL, 0x850963967BEA8F9CULL, 0xAC36375A90324061ULL, 0xCB3FBDA8E34ADF0BULL, 
            0xC060F51328238A07ULL, 0x7B8CC210E3690125ULL, 0xAB141A558F048AE4ULL, 0xB8E314C7E5550606ULL, 
            0x044551273587CBF6ULL, 0x2ABD3AE0D89F3CBBULL, 0x73051983091AE1B6ULL, 0x3A79896FC85EA3C6ULL, 
            0xB3009ED740706FCDULL, 0x9B85DCDFDA325013ULL, 0x24576310662AE89FULL, 0x12726A447DDADDFEULL, 
            0x7E67EC5E2CC44CCCULL, 0x06BF65DE33E4EB1EULL, 0x47026DB33CEAD7F8ULL, 0xE76310D0F4946EAEULL
        },
        {
            0x53BE0E81780A4405ULL, 0x968E2140EA0AC97FULL, 0x9B7EB76AF6C644B8ULL, 0xF56D3C466C069CDEULL, 
            0xD8F13701C85AC9F8ULL, 0x8031A3F2246DA583ULL, 0xF10A0881ABCF3D90ULL, 0x48E54BAB3B8176F3ULL, 
            0x13694779B6860538ULL, 0xA4C5B5BE74213AE9ULL, 0x35BB6017CCE7A4A2ULL, 0x3D2972AD8AEF0669ULL, 
            0x7B4B15B0FC30C1DDULL, 0x850B9A0F73FD3C2CULL, 0x9347734BD3FE99D0ULL, 0xB68C7C2BE03FFC3AULL, 
            0x723C13A26B0F9481ULL, 0xCF32179E883640E9ULL, 0x4FC5381369CD300EULL, 0xA82E392C890DE726ULL, 
            0xE4F94486D1FC5883ULL, 0xA3944DB3BB679E82ULL, 0x627C6F5B6F25CC76ULL, 0x46F8A5F9B008BAB8ULL, 
            0x70575F8B0377D3E4ULL, 0xBC48F8447FAE7AF5ULL, 0xD0202CD0710E3CCDULL, 0xFA24DA0144059DCCULL, 
            0x49DE5A17812C2F78ULL, 0x7959AD28A253E44BULL, 0xDC42BB5CB0CA3A4BULL, 0x2DFFD2CFC8C5660FULL
        },
        {
            0x972AC8DD64D27DE2ULL, 0x11D96BF5E32676F3ULL, 0x6BFA514D2FE643C1ULL, 0xDF18EE47F5E151CAULL, 
            0xB37722C37D45A317ULL, 0xD551AD331FF54FC8ULL, 0x9CF7595F54BF80FFULL, 0xB79ADC4C6E12497DULL, 
            0x62329BECB2451024ULL, 0x295F46C4B22A2531ULL, 0x1BFD6BF11B2E60FEULL, 0x648E18402FDDED26ULL, 
            0xA5930A60E511764EULL, 0x3EE1283C910B41D5ULL, 0xF02174F91D5F79A8ULL, 0x1BC10077DAD36A43ULL, 
            0x15AF776F67E3E8D7ULL, 0xB6583963DA50A405ULL, 0x91FB919C87C0F3A5ULL, 0x6D07176E856C814CULL, 
            0x93BBA5E9C3D1C128ULL, 0xE3BFA611D566C672ULL, 0xCBB4DFF696984F16ULL, 0x01411874EEB338A5ULL, 
            0xD528A7AA1C2388CBULL, 0xC09B4EC9A5C954F9ULL, 0x146C182B24D2F10EULL, 0xB31C928F81DC21ACULL, 
            0x10133BB29E618AAEULL, 0x15E117F9FDCC006AULL, 0xA4A5308B1876EF0CULL, 0x62ED6FD15DB1F42BULL
        },
        {
            0x2B838A935C744787ULL, 0x4DC8FE1E74B439B6ULL, 0xACE91EDE12DDB8E0ULL, 0x5E24EF2B0567DCBFULL, 
            0x72FC899A5DBEBF66ULL, 0x21A65806558B832CULL, 0x9FFEC225370F684AULL, 0x69B6D01C7668E933ULL, 
            0x4688D9D89D47F473ULL, 0x246AC5568360456AULL, 0xF7256B091991AB64ULL, 0x3DB435790D2D4DBAULL, 
            0xA17B55DCC309F6D6ULL, 0x084EAB8DE0D0FE33ULL, 0x362548B9AA505282ULL, 0xD0307F42E196D928ULL, 
            0x5F16B1537B65AB89ULL, 0x882FFA89224931ECULL, 0xC6819878C514FE2AULL, 0xF9ED1FF0C438A236ULL, 
            0xDC3CA9992007722DULL, 0xBCD88577A04CC924ULL, 0x2A834BD1A5D58F2AULL, 0xE64589370787E9B7ULL, 
            0x314AEDB12A3A4EC5ULL, 0x4DD6E05C7CC23C10ULL, 0xDDC7E65A87165C2CULL, 0x1E4882DC1D5D16CDULL, 
            0x9DC49144166ABCF3ULL, 0x726604B29CA06A7EULL, 0x6904B1BFA604928FULL, 0x553B62D7A79B89C2ULL
        },
        {
            0x79404915D0F5DFEFULL, 0xB8A6C44D2BE53BCAULL, 0x647EC08CC161656EULL, 0x873BA44704E51B9DULL, 
            0x7353E289F7A06746ULL, 0x9407ED4948F70E62ULL, 0x674A7C8A47059339ULL, 0xFACB32FD5C6EAC63ULL, 
            0xEC7ED7F74BC964C3ULL, 0xED69C2E9D913CFBFULL, 0xA6AF8A93ABFD6AF7ULL, 0xD9C32171A37B7899ULL, 
            0x5D4725FFED501D73ULL, 0x12E2F9F88CCEBA1BULL, 0x2F0BD62298762EADULL, 0xB0119FCD4C9BFCF3ULL, 
            0x8C7A5C8958D2A132ULL, 0x7ADC1E8489A95346ULL, 0x42AC1F669D471828ULL, 0x2C2E0126AB972DEEULL, 
            0xAA6A21676712B147ULL, 0xFC65E18008464364ULL, 0xF45959B6D5B81366ULL, 0xBB738F83D0D796BCULL, 
            0x5B5587F28C1D5DBFULL, 0xC5F4B60B2B87D1C6ULL, 0x29EA3D23BBA0DC17ULL, 0x546EB4F9F6B86CB6ULL, 
            0x9C8FDEF616053A1EULL, 0xD1F7A1A095221F4DULL, 0x1CB175888D32EF03ULL, 0x2CD226663C12F8B0ULL
        },
        {
            0xD20CB700BFD3EDF4ULL, 0x12021ECADF2D0852ULL, 0x800796B09AD2381DULL, 0xA105A43F238C3FB6ULL, 
            0xE9A2F9E7C983C463ULL, 0x104AACE2A01B55ECULL, 0xE153F413D86019ADULL, 0x396AA0EC97EB96C7ULL, 
            0x688A7A44C22D3A8FULL, 0x57D53A07942AAA97ULL, 0x34E7B6134B514F77ULL, 0x9134A8F47ADE210BULL, 
            0x4709F910DC69766CULL, 0xEB2C44649ADE5627ULL, 0x46CDC0ACF0CEBF92ULL, 0x562A8B697CF11A9FULL, 
            0xF5EF6C9CF07DFFAAULL, 0xA0880930F5B69A5BULL, 0x23F4BCF9629113F3ULL, 0xA816E8C4B7CDF23AULL, 
            0x9FBA0EDF34C40A04ULL, 0x3271041E75B5994DULL, 0x7A7A7F836A3C324CULL, 0xBFE970272CFDA343ULL, 
            0x999ECB899AC3AA24ULL, 0x8B2DA8C9B02A607BULL, 0x0B6DD918E975DAC1ULL, 0x96E74229AB011F8FULL, 
            0x6C359DAF0D26EAAAULL, 0x83C105E853DB7C54ULL, 0x0A906000D7AFD5EEULL, 0x381FE9F58F12651BULL
        }
    },
    {
        {
            0x6CF6CF7642A117D4ULL, 0x10F77092527E1C2EULL, 0xFA2D1658F24B1915ULL, 0x9C615AF1C4CA40BCULL, 
            0xB9DD62B7B94F95F0ULL, 0x8FDFA14718B978ADULL, 0xA45798E8EBEA133BULL, 0x9630DB44DA29424BULL, 
            0xF04FAF85F5CCD2B8ULL, 0xC0590379E00A6E81ULL, 0x5041FCBF685D7A9AULL, 0x64762A6846803FE0ULL, 
            0x7CA52B9D7DB44085ULL, 0x53D29D5390D3A93AULL, 0x089A2538926378D7ULL, 0xFBB1DD0A5613C3FCULL, 
            0xDEBD00B805BE5B42ULL, 0x129B88FF459F1E99ULL, 0x18FEF73C656BCF47ULL, 0x6432F88659E845F7ULL, 
            0xD8D64B50AA827726ULL, 0xC31E84B7439FA4D6ULL, 0xFA189769B32AFEECULL, 0x7C7902117665C364ULL, 
            0xD2142F7BCCCA2051ULL, 0xF65AD29BCA659893ULL, 0xE13CDB2A86AAEF68ULL, 0x52BC146F99A486D5ULL, 
            0x5DEE1324ED28A025ULL, 0x0EADDD47D19EE64EULL, 0x5E2F23E48316EDAAULL, 0x1EB00E631A9BEA74ULL
        },
        {
            0xEE3CA2A028726432ULL, 0xD2A68A256EA69D8AULL, 0xE703491FE8BA8837ULL, 0xF8E9E41DFAE79149ULL, 
            0x68924CC1914FFEF8ULL, 0xBD4A0AD75C7EB7DCULL, 0xDD7139A74862A82FULL, 0x274B97C27B520B68ULL, 
            0xCB6019028EF2FD78ULL, 0x4CDF187AEA16E2FBULL, 0x3B45BCE5301733F7ULL, 0xB747367FC7100207ULL, 
            0x2A020F23C7FB751AULL, 0x8668D804F21EA4D4ULL, 0x05F8D8575A2C6F3CULL, 0xCF9D958B25D757A8ULL, 
            0xC38FF56524200E34ULL, 0x91F72B58F463830AULL, 0xD9E03F2A49C1E309ULL, 0x42203D75DE0F810AULL, 
            0xB94C9853E1553025ULL, 0xB5B2962A97A05392ULL, 0xF632387622FD08B2ULL, 0x3CC5AF931AC00C59ULL, 
            0x10BF9EB962046803ULL, 0x1A849490B136E23DULL, 0xD14FF2646268D677ULL, 0x5E547CD91D1045B9ULL, 
            0x600DFA1C7D204863ULL, 0x4EBDE7D9A53D6CDEULL, 0x825D58824797EBD5ULL, 0xD8A8E58DE78F6F51ULL
        },
        {
            0xAC88D47B0D9C5EAEULL, 0xD27B93024752D1E5ULL, 0x0EC3D60845F59EE0ULL, 0x29C1950559B31672ULL, 
            0xED1A723797B7F8FBULL, 0x16B6B2D3883DCE34ULL, 0xDC0D20F0B9144E05ULL, 0xC059DC5917BC9C5BULL, 
            0x5CCB18EE882BA1C9ULL, 0xDB097F135EB36B4BULL, 0x04B0F973673B61B4ULL, 0xF7BB0C8063386F20ULL, 
            0xBAF39453D118F0FBULL, 0xFF02BE935789B844ULL, 0x339C15CD4A0B91B7ULL, 0x6DB634E916141C90ULL, 
            0x7DC79E8D2184910BULL, 0x6C440FA3CE265C0FULL, 0x0D9167812AFC3BD1ULL, 0x733A9FA3AF0B368BULL, 
            0xECAE75F85CDAB28BULL, 0x5A8BC801CC8BC42DULL, 0x3C65ACB21B321A40ULL, 0xF08D1B32703DA5FAULL, 
            0x250FDFE8032C67EDULL, 0x65C0C1BB0BCCBE2DULL, 0x7AD01F4CEE2571D2ULL, 0xF756C302E422AF2CULL, 
            0xBCBBDE8FE941EC51ULL, 0x5081842E82B7883DULL, 0x09D1058D09F2D84EULL, 0x172865E5E8275599ULL
        },
        {
            0x78A79EABD39922D3ULL, 0x1CD7342C0D4AB4B2ULL, 0x1190BD4C9F011945ULL, 0x1D66369882BE6D5EULL, 
            0x226B1A2E32C477C7ULL, 0x23164AE42B4A1A8EULL, 0xA92D227E66785408ULL, 0x5BF896253A866F50ULL, 
            0x392C7BBAA18C071BULL, 0x536D055437C507D8ULL, 0x68C797C2EBEFEC64ULL, 0x91209293DC9479F5ULL, 
            0xEEAA1EBB95ADE86DULL, 0xFFC0B2C136FE8713ULL, 0xFBA6D83A38D54EE4ULL, 0x5635644718658F53ULL, 
            0x51FF90E4A82A74C4ULL, 0x9FE18DEDB402E876ULL, 0x5003C429E7356AAFULL, 0xBEDA826C87D68BB0ULL, 
            0x08EAF155F845D4E1ULL, 0xF0ACF4D14F6AC4E0ULL, 0x4A1D3D765D2FBA61ULL, 0xF5F6AFEC34D0836CULL, 
            0x7F8F6E4E5B41CBC4ULL, 0x59EE42063104AA66ULL, 0xC9B9894B99978EFCULL, 0xB2044AA2A3D8DC06ULL, 
            0xF8A149A3547F9172ULL, 0xDA0BE25945BAB249ULL, 0xD459003EE880CD8AULL, 0x09F746076ED138CBULL
        },
        {
            0x65CF0237D59129A8ULL, 0x1B31D8A0FCE5A005ULL, 0xF802A359A66549A7ULL, 0x2F74263EEBB73EB9ULL, 
            0xD7BF58B46FB6C464ULL, 0x95DF86FDD83AD960ULL, 0x5DB84BD47B6B4385ULL, 0x7A0177CE1E470F4BULL, 
            0x73B74BD0655E3457ULL, 0xA784EF4CB133152DULL, 0xA89CD5B18FBAB379ULL, 0x333ED7DEABF2D917ULL, 
            0xC82B44C14326F417ULL, 0x0E5843BD875F90C8ULL, 0xFF81039ECDF233D0ULL, 0xED46083A82F3669CULL, 
            0x183796C95605A154ULL, 0xA4993BA8B8A19D31ULL, 0x6860D4DA3E965E54ULL, 0x748283055EDF4D85ULL, 
            0x890971533C0F3A2BULL, 0x8554E7C09FEC0B96ULL, 0xA8D50EE3A5E8B29FULL, 0x50C16A82DFD2DEB0ULL, 
            0x62C24BF0E89054CFULL, 0x572C150356DAB13FULL, 0xADAFF5E93027BE7EULL, 0xF590053F7ADB42CCULL, 
            0x46534DF6A71ABDF1ULL, 0x79A648589AE6B31AULL, 0xACCBA360DE0853CCULL, 0x8C3DA4E975D9F099ULL
        },
        {
            0x41F50D873D0430EEULL, 0xD517BFBA399C5F1CULL, 0xB3837901D9708D75ULL, 0x89082A9859AA24D0ULL, 
            0x3C7D229542AED097ULL, 0x17E6FB5DC47F1220ULL, 0xDA56B86688C20516ULL, 0xB9BF76EB9CD25C67ULL, 
            0x8B59ADB97ABABF7FULL, 0x6C56529C0D173F2BULL, 0xF41FABD79FA29D8AULL, 0xE240C368DF2335FCULL, 
            0x55ECC6A0200C3439ULL, 0xF1E16769279B6814ULL, 0x6EA56DC474E11349ULL, 0x6889555C08911A9BULL, 
            0x651E53DD1469FE8CULL, 0xD1BFA8F9265859A7ULL, 0xC697ABC8AF67E36CULL, 0x2DF7F22772AB99F1ULL, 
            0x460FA0F1FB3461CCULL, 0xFA1C2C1817E5F63BULL, 0x729DEB7D9ACA25A9ULL, 0x3279AA2470B896B1ULL, 
            0xCF97761EB3AF20EBULL, 0x1626036500A85225ULL, 0x046DAD860355DA53ULL, 0xABF26CFD1C9BB4C8ULL, 
            0xA5FA9F1408E2FC74ULL, 0xFBE3263F9760F394ULL, 0xEA91B36AB418A2C7ULL, 0x9F0E33396006E538ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseDConstants = {
    0x8CEDBDFC0A947402ULL,
    0x1C33BBE9FFD14F52ULL,
    0xD6338A372DE27942ULL,
    0x8CEDBDFC0A947402ULL,
    0x1C33BBE9FFD14F52ULL,
    0xD6338A372DE27942ULL,
    0x42E6E5DA74A56200ULL,
    0x78EF17F2D32F36A5ULL,
    0xA8,
    0x6E,
    0x35,
    0x05,
    0x0C,
    0xD7,
    0xD5,
    0x61
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseESalts = {
    {
        {
            0x8E81ECD308ACF711ULL, 0x0A51425F943A12B8ULL, 0x77B3065455A005EBULL, 0x5BE2C1383214D7AFULL, 
            0xA5F8D1A8068AE079ULL, 0x37BC1EE5137240AFULL, 0xFC7379ADA1D56A77ULL, 0x8BBE0467796467CAULL, 
            0xBF6CF2C36D4E04B9ULL, 0x389BE22D599451AAULL, 0x96417B91018DE287ULL, 0xE13853F74DB8E556ULL, 
            0x3324232B422A53A6ULL, 0x7AD7EE8445C85B40ULL, 0xF6272B94EFC80E99ULL, 0x6340D3206D489632ULL, 
            0x57359FC72D3F86BAULL, 0xC8A886EB507FBB7EULL, 0x1F9CF76E69CE24A1ULL, 0x0F02F32323B1AF9EULL, 
            0xB7B9800857248EF7ULL, 0x8E7BEB2615428461ULL, 0x19B66F8CB15234A3ULL, 0xCFC8194BEACA11A7ULL, 
            0x559990A7E5A28285ULL, 0xA1DF1FF4A4E153E4ULL, 0xC222D426D50365E3ULL, 0xCB938B29F1AB387FULL, 
            0x67886D0D787E1677ULL, 0xD5BE65D25676E0F7ULL, 0x444395DD065DA75EULL, 0x60771E55F4020193ULL
        },
        {
            0xD1069D5151FE3742ULL, 0x6BA772E0DFD5DC0AULL, 0x82028BBFC71CA1E7ULL, 0xB27723E0FC5D405FULL, 
            0x5A26507090101CBBULL, 0x9E8E9C24DCD1807BULL, 0xF599E28BBBEEA626ULL, 0x4D58CE338A95131BULL, 
            0x2191C742C7D6AA47ULL, 0x03CF0DB18D292126ULL, 0xED7A79CAF79B4D54ULL, 0x947408AEC2DC6976ULL, 
            0x4775A639C85E84C8ULL, 0x9A9356BB75204683ULL, 0xA8CAEAE901D20C35ULL, 0x37F803AD1A17E595ULL, 
            0xC1090A89846293D0ULL, 0xC5191DD41816E989ULL, 0x032112945488478AULL, 0x1C3C4377DCD218F2ULL, 
            0x50132C12C695F232ULL, 0xC5AA9A731EA404C4ULL, 0xDEEBBED56ED595FDULL, 0x14E23C745524D8DEULL, 
            0x12411097FC9D8E75ULL, 0x8FE519B33CE9A39CULL, 0x371BD891B7FFB272ULL, 0xA8C03635F223E5C0ULL, 
            0xB8544BD1CD6E9990ULL, 0x0A3053C0204B7DBCULL, 0x78F08193EBB95E09ULL, 0x1D3C22B83DAF22DDULL
        },
        {
            0x97A5666B33DEF396ULL, 0x4C75A6396945C5CBULL, 0x38F76C96BEA783B4ULL, 0xC0B2925BECC1D57DULL, 
            0x1AD5CB154C08658EULL, 0xA82D1E46567978B4ULL, 0x5920C4D5FB31EB6BULL, 0x8E2466B8C6570663ULL, 
            0x6E5BA42987B83DB8ULL, 0x6AD3DB8A49A680DDULL, 0x2F536CCB07099F4AULL, 0x7CFC9E58DD99654EULL, 
            0xCA40F5302EEBDDAEULL, 0xDE812DB0AD218733ULL, 0xAC980343161D976BULL, 0x1541F043D49AB5DAULL, 
            0x62564DE548626B71ULL, 0x238437C6E75144D5ULL, 0x88602E4F3C0FD177ULL, 0xE4B30514208E6411ULL, 
            0x567AD9CDD5391FCCULL, 0x4515D26C1E98CBE3ULL, 0x9B8D636D3FCD444DULL, 0xCBF76F2A5AFB588BULL, 
            0xC9EF55EB755E10A6ULL, 0xA551DF64E1A085EAULL, 0x80315E390BCDFED9ULL, 0x839E36EAEEAD66D8ULL, 
            0x58E2A4634DA0B987ULL, 0x1647893989AE72B9ULL, 0xA1F2DD5EFB00160DULL, 0x7F3CE274D181612AULL
        },
        {
            0x9DCB5A493C617159ULL, 0x8A5B86A8435D388FULL, 0x7AFA46BB7D280796ULL, 0x1B3F4554F4E500E7ULL, 
            0x92E2D91D2865D80BULL, 0xB485EBCA91B83CC0ULL, 0x4D702B634A187DCFULL, 0xD63921DD7BF20873ULL, 
            0xF3EE46F027F59DA4ULL, 0x133C69C52B9EF678ULL, 0x989B047ED2510D02ULL, 0x4B1992E426CC7AC5ULL, 
            0xCA290A2DCA2C0D35ULL, 0x13BA43415D092CDBULL, 0x54B19102D9D8510EULL, 0x2A3A8A3A4E11FA2BULL, 
            0x9E5C0F4FECF4D7D0ULL, 0xED6D3E2E1FF7548AULL, 0x2949D6D834D81EBCULL, 0x21129CBE78C3889DULL, 
            0xE384DD92C47E0564ULL, 0x991BAD69A41B6D1CULL, 0xEF3977A3A6C97DF2ULL, 0xF1C104C7944AA8E8ULL, 
            0x3519F7604287C435ULL, 0xF93DF857F3713829ULL, 0x72D477F309B9829FULL, 0xE2CAC76D5F8006AFULL, 
            0xFC6DCB97144ED355ULL, 0x45577B131E49A13FULL, 0x8E29B51A3AF7A83CULL, 0x64D118EDC331AB06ULL
        },
        {
            0xCACFB68910A6060EULL, 0xFBB36CCA43348C0FULL, 0xD711C8B0BB166D0EULL, 0xC6ECD41D513492C2ULL, 
            0x01E62CA7B33C1418ULL, 0x9BD150015C831519ULL, 0x6E70ECEEF0615F6FULL, 0xDA2511868600FAA5ULL, 
            0x2996CBC7E2D6B9BDULL, 0xD71BB94253774797ULL, 0xD7875669DD86A86FULL, 0x3B1BAE37CCA8DECFULL, 
            0xF02E3236E4F5B737ULL, 0x7C2C303578E66FBBULL, 0xFDCABFB5E67C076EULL, 0x9555A38EA1BB8895ULL, 
            0x1377C0515A3D0A37ULL, 0x8A1E6BC5B0D8001CULL, 0xA6F0C3F06F01E2A0ULL, 0x9654B097A2034008ULL, 
            0x028DD25CBFC76D50ULL, 0x5E08B5C60DE99F92ULL, 0x199BCF06347FEA82ULL, 0xE13EEB8F9FADD385ULL, 
            0xEBD892A7BB20F467ULL, 0x33ACFD175B39CAEDULL, 0xDCFE00DE785D9C85ULL, 0x90EC8005C33F3079ULL, 
            0x2758B0BFFD7C4F48ULL, 0x66382A615241FD16ULL, 0x450EFEC520454411ULL, 0x2B93B016A6753EBDULL
        },
        {
            0x7F1CA28A4AEDC84DULL, 0x919F6E088D5412DEULL, 0xEC932B31BB2E1BB6ULL, 0xCB3E7FD1E110DC03ULL, 
            0xCA14BAB6F00E6354ULL, 0x757B300F1B487B63ULL, 0x568A56D31B13366AULL, 0x787F4F5F1C82AEF9ULL, 
            0x8F0B26713328E41CULL, 0xF1E19C6DB8809770ULL, 0x8830CE51CA7C328AULL, 0x7EB6FD4118943DDBULL, 
            0x26D42C6E0A06FB4CULL, 0x8B1AD22C9D7F2447ULL, 0xED8A7CFD7B5794C9ULL, 0xB98E34662F02BAFDULL, 
            0x7C8FD08E78BE4504ULL, 0x6529AB483544BD27ULL, 0x8513411F61430066ULL, 0x0AE4BEB6857A33FAULL, 
            0x3C8E48850081A306ULL, 0x4A175D37EB944D4CULL, 0xB4E20CD0D7F52EB0ULL, 0x05D21E2F230DF0F7ULL, 
            0xAB9A815EAC031CEFULL, 0xAF0C69649FEF0A57ULL, 0xBEC3BC37EB25CCA7ULL, 0xE44E2B263C079519ULL, 
            0x5B373FE19F117BB5ULL, 0x5F42198D9AF03FF5ULL, 0x53BD667170B22D10ULL, 0x1939BCBA59A5C5E6ULL
        }
    },
    {
        {
            0x10F5CC8CFBB750C0ULL, 0x0CAA3A4F3253C85CULL, 0x22DB5296F6AC7FB2ULL, 0x20AD5F3C46EB1835ULL, 
            0x82E2F909B6061310ULL, 0x2D6F37F4AD0F02DFULL, 0xBA9943AF1FCC4509ULL, 0xA5544B4FCFE20ACAULL, 
            0xCCA40884CB8656CCULL, 0x7D54DC0251831F93ULL, 0x130890C143563DADULL, 0x29181E98F166BCCEULL, 
            0xF5FF0FC3619E898CULL, 0x7FE9945162B4AC7FULL, 0xE1520FD48DBF1F2CULL, 0x51ABAF4FC674D21DULL, 
            0x4AD32CCE11B02E33ULL, 0xC726F1D4FD195851ULL, 0x5319C3AA2D3572ADULL, 0xB1E5BF154D95191DULL, 
            0xCBB415080F127BB0ULL, 0x03752BF31F9D68BEULL, 0x8155A029D0BC1458ULL, 0xB235FB5F55FE9FC6ULL, 
            0xC1910B2A72AF9984ULL, 0xB9FBF0D05EFE4DE2ULL, 0x817E13DB3840ABFCULL, 0x1F58C4EFA6AD31FDULL, 
            0x02BDBEAACABF885EULL, 0xAE56B74A755E6223ULL, 0x479349625CD3B3F7ULL, 0xA40BE5E368E36424ULL
        },
        {
            0xFC237045FFF6CB31ULL, 0xE0A43C91B0CB3473ULL, 0x743F877D5F789BE6ULL, 0xFEF18377F9314C29ULL, 
            0xFF606596F52FB527ULL, 0xF3D977CA541C982BULL, 0xD587759F61BF31D9ULL, 0x65C762112BCF7344ULL, 
            0x6E77DD4A27A3E462ULL, 0xF52C4F10F8016AA4ULL, 0xEA5B56B49423E45FULL, 0x3AE7A70CCB333EE9ULL, 
            0x59F019DF8A3C069FULL, 0x9FD105E726C7710CULL, 0xFB70309CA6C272F5ULL, 0x18CA85163358EB12ULL, 
            0x19C20E5A8C1A289AULL, 0x2A3BCE3D4F9249C1ULL, 0xC39B1520C45D3811ULL, 0x5D83592B1708D24DULL, 
            0x0EB2C8B6C9B8583BULL, 0x2A78F353655A8F5DULL, 0x0ACAFCFF7785822BULL, 0x13AB0F2E65CB5DDBULL, 
            0x40365F8AFFE536ABULL, 0x5509C3F7E30CE42AULL, 0x38601A026A5B45E6ULL, 0x2F2EFC608B589C20ULL, 
            0xF4E7A25EB150BF71ULL, 0xB50225E69757634EULL, 0xDBE2F3F8FC7E2C5CULL, 0x6D5ACE80EDD51BC1ULL
        },
        {
            0x2590B286A4303F09ULL, 0x886F1E7BDC928470ULL, 0x4DE3310CD35A4411ULL, 0x44EFDFD9A17BCAF7ULL, 
            0x94EA69A0F4C6B288ULL, 0x0311943AFF29071CULL, 0x3D3F2BFA9EB733A6ULL, 0x6667AC5063188B2AULL, 
            0xD59DC8BDEDF69CFCULL, 0x69AC9580578D76A5ULL, 0x22D9B9CACE5AC051ULL, 0x3B37D57D065C298AULL, 
            0x280938AC8BF34A77ULL, 0x5C02F1BB6AB1400CULL, 0x2DE79E7BA01ED621ULL, 0x7AF0D4FBE0FC15CBULL, 
            0x28B600E373E42330ULL, 0x32BE9DEBB3C6AC34ULL, 0xA4D61EA57581EC08ULL, 0x74A1B1AA55039B0DULL, 
            0x43D3211BA4D1FDD6ULL, 0xE4C0F1DFBD4A1E41ULL, 0x297133AF61BC695FULL, 0x9B5929E4D3800B24ULL, 
            0x9702F007D12E13D1ULL, 0x6735A83D3E851290ULL, 0x288C9937D0E33598ULL, 0x21E77755C77CB1C6ULL, 
            0x6849BAE1D3A1BC23ULL, 0x273E821514E3A801ULL, 0xEEED951386263E23ULL, 0x692617D798E48DBAULL
        },
        {
            0x4B3B8626418841F6ULL, 0x3BE225D8D214E2D0ULL, 0x7D35447194C291ACULL, 0xBA5006229A8948C4ULL, 
            0xBE0034FAA47B66E2ULL, 0x02F4E1A7BEF16815ULL, 0x664F1A62332D815BULL, 0xE6F7347339213EF4ULL, 
            0xBE56F15EF61D30DAULL, 0xBABE093E68401279ULL, 0xBD2336F39AB9D877ULL, 0x5BF4F5D95686862EULL, 
            0x4A2A9B90E003816BULL, 0x640039BA70850D6CULL, 0xF483EC8FEB27668CULL, 0x749BB3D7D085510EULL, 
            0xBAD6460D8E8A71B4ULL, 0x98DF0A4A8DC5A175ULL, 0xB933B169BECCC2C7ULL, 0xE3A227E896ECB410ULL, 
            0x32998AA023CA50BCULL, 0xD5D20EE6E8FC3554ULL, 0x89629915F120E305ULL, 0x16C84E6705DF635CULL, 
            0xF68B785D8309E82EULL, 0x18F5A9D17FE7634CULL, 0xC52D2B4C0045ACE7ULL, 0x1388D89D515DCCD1ULL, 
            0x75B114DE3BB25810ULL, 0x9C4DA4968225067CULL, 0x48AB512BE74D7C1DULL, 0x2C1B55692D97CFE1ULL
        },
        {
            0xF95399DE6B714AE6ULL, 0x4EE06591C3365965ULL, 0xC21000636E41C819ULL, 0xF49CB01B5D813741ULL, 
            0x9A8127B25F2F1860ULL, 0x40CA4429749CF130ULL, 0x383338986208F641ULL, 0x869B682D707703C7ULL, 
            0x6E0CAD6BA413DE2EULL, 0x19B87A52BE842E79ULL, 0x26107D6A31361BCAULL, 0xA697FEDFF52F2DF2ULL, 
            0xD5D0D582FE8C8C4AULL, 0x68F82858D591F731ULL, 0x05EA6B944064E482ULL, 0x2CBF0741035AF41EULL, 
            0x0E2F04CB7C46FAADULL, 0xF0481D078C53EE06ULL, 0x629F638EB4ED9107ULL, 0x4D8D6CB33AB939FCULL, 
            0xAB0D7D1846D58244ULL, 0xF7BF1211FE1BDF23ULL, 0x5CA7DC7AA7ABDADCULL, 0x8837B78A025CE7A4ULL, 
            0x1CE21465A20841F8ULL, 0x47D3218DFDCC029FULL, 0xB288D8B6B0D45AD9ULL, 0x81493D215A5B6438ULL, 
            0x5E79611C53396FDFULL, 0x9EFC2FD161CBFB7BULL, 0x003EF3D4D3C97BA3ULL, 0x5EF62CD8AC0F6417ULL
        },
        {
            0xD9ECB617B1167749ULL, 0x43EBE85B3A18A79CULL, 0x12B2E6E153833D4AULL, 0x660E5A3969FC73E9ULL, 
            0xCED00F3B42521F9DULL, 0x56F2FBF93208918DULL, 0x25981A9DA6BC3D03ULL, 0xBD14CD46EA8F3B29ULL, 
            0x15A4163FCB3E5531ULL, 0xBF08E7ED6C48072DULL, 0xD6C1F727641A2310ULL, 0x51921E0155CEA15CULL, 
            0x0C6ACAE5F1B8CD74ULL, 0x11F389EB20B99B09ULL, 0x364B0B6A81574258ULL, 0x5DD6C2DFEFE492A4ULL, 
            0x50035D8264A640A3ULL, 0x7015120AEC29F9E2ULL, 0xD39FA6B66EA2C24BULL, 0x93EE059C9A20CB38ULL, 
            0x5542207E1940D25DULL, 0x317C56E566979F4BULL, 0xCC71C368ADC851B1ULL, 0x90D1EDE26B070424ULL, 
            0x827623F193657506ULL, 0x715B0755FAE3A5D6ULL, 0xA396C9D4534958D1ULL, 0xACB176400583C229ULL, 
            0x84B331C6F18328B9ULL, 0xF19775C5DF468336ULL, 0x4EF8D545A24F0ECAULL, 0xA553250F7411A911ULL
        }
    },
    {
        {
            0x3AE7349FA89B5DB5ULL, 0x2C88F90CB99528EDULL, 0x5282A8A28A03D9A6ULL, 0x1F3E01D63E42F832ULL, 
            0x7B6752A5336D2058ULL, 0x2794C2E9EBB6335FULL, 0xF7B7E15EF77BCDD3ULL, 0x6389659D28350BA7ULL, 
            0x9924351404CF41FAULL, 0xFFC8580F9354D34BULL, 0x56F10F031FFD5579ULL, 0x6E249FD7A3B802B6ULL, 
            0x600DAC317B6197CCULL, 0xD17C94C35697291AULL, 0xD8F5E601FC4BBCAEULL, 0x75028E2E946B9684ULL, 
            0x1313B3853D9BC56AULL, 0x8BB64319C96A775DULL, 0xE4DD556DE08B455DULL, 0xEDF97496282C28AFULL, 
            0x70C61B14951C49D5ULL, 0x8702CE1C0402F93FULL, 0x25C33084788845DCULL, 0x7F3FF72990EBBC1EULL, 
            0xD26E53D779DC2C2EULL, 0x43C766081B79FA86ULL, 0x1C009BE9AC617F62ULL, 0xFCE6941ABCFA9E59ULL, 
            0x1CB4329F3F1B3D12ULL, 0x80E33DB48FB8B0E3ULL, 0xC061E4CC8A706868ULL, 0x468C2CA72C31552AULL
        },
        {
            0x5C78FBF56DD03CFBULL, 0xEEF467160F451DF0ULL, 0x0F4B4C9C67C7F755ULL, 0x01074116BC3A2CD7ULL, 
            0x32C74182BBACD1B7ULL, 0x7FFD7E36141BD30DULL, 0xE160061499293B46ULL, 0x1A3A0A7412D72C5BULL, 
            0x81550D79B0414FFEULL, 0xBFF25DDD0EBB1B33ULL, 0x636C145707E14F1CULL, 0x1AFB5CF0E99CBD04ULL, 
            0x841BA0FECB0008B8ULL, 0xAA9DAEF56E538A96ULL, 0x71772029C47A5995ULL, 0x1BF6A661347CD0ABULL, 
            0xF25B2BBF97695309ULL, 0xB83D9BF10C3E2B65ULL, 0x3463724A6648776BULL, 0x485EF303787F9D29ULL, 
            0x1A539AFB1D2018A0ULL, 0x5784EF5F26911945ULL, 0xD69258C02EFA1769ULL, 0xC29316FA9596E285ULL, 
            0x68357129D620754FULL, 0x733D5E1AA4C2CC5CULL, 0xF063C1E2D9C2243FULL, 0x4839930A22E148CEULL, 
            0x2CCFAFDA2C8447E7ULL, 0xE7D19517B38DC42CULL, 0x8C420ADA9F2CEBB5ULL, 0xBE641A96EA761995ULL
        },
        {
            0x70BE051AF795E074ULL, 0x9068F0D02DBBC7B7ULL, 0x5DD75F22695A149EULL, 0x1D06AD0DFDF52231ULL, 
            0xEF90B305C0AE4D4BULL, 0xC76D32E1FBF98E5FULL, 0x1E5CE4930418FC46ULL, 0x1538DA521450FD99ULL, 
            0xF7AFF7867E70BE87ULL, 0x0C77449AFBAD6CA2ULL, 0xACC89FFCF55540DEULL, 0xA9561DDB0FD5D3C6ULL, 
            0xD16F821CE9CB0D70ULL, 0xF517963358505900ULL, 0xC18374A53C5FF534ULL, 0xDFA6F08EBF15BFFBULL, 
            0x7460C12EFCB4707AULL, 0x002FD4AFB54DBB03ULL, 0x988CCA5578CE46FFULL, 0x5DA296B5055484FBULL, 
            0xE4447BFCBA66D450ULL, 0x71156CD0DF61C609ULL, 0x7F216A1AFFCD3354ULL, 0x62D99D7C380CF6A2ULL, 
            0xD18DFA2BBEC3A763ULL, 0x53BDA6B4D0377B41ULL, 0x9476E03DB0C39E9FULL, 0xFE2A2348A410A7CEULL, 
            0x7C1814B88A968E79ULL, 0x57F85E2B48630A1FULL, 0x330030330304A911ULL, 0xF02530DA58AC795AULL
        },
        {
            0xF0B4A51FFD28542BULL, 0xA2BBF478CC432700ULL, 0xBAB1AF632DC4BF8BULL, 0xBCCD9975A806C9EAULL, 
            0xEC44641DB1651EC2ULL, 0xF176107AC222E174ULL, 0x4903C840AC855E37ULL, 0xF81DB3DEA6B47C7CULL, 
            0xE75D7CA4B248A90DULL, 0xF3578CDD8FC71CB7ULL, 0x8E84FD02FADDAF04ULL, 0xFE861B1B12D3F75FULL, 
            0x5059ADEA956C593FULL, 0xA4435F84DED7C731ULL, 0x2FF56F1EFA36E6BFULL, 0xCE68EDC429B1FE1AULL, 
            0x664DD538C9A29566ULL, 0x00AD586CC892179DULL, 0x9C4D446A8121EC21ULL, 0xF4C253FCEC4502CAULL, 
            0xDB0838083397B69AULL, 0xB2A111242D4E3FBAULL, 0xADBC6EF215B64607ULL, 0xAEE6919A93848A6AULL, 
            0x4AC5D65A75C1E965ULL, 0xF87A2DF85B529724ULL, 0x0AA283E320DD816FULL, 0x49C7F3131BD55027ULL, 
            0x5BBF31E6D5FEA31AULL, 0xB52E72264C81A6C2ULL, 0xB3EB078DD9140A03ULL, 0x6D9A79FA863D3781ULL
        },
        {
            0x1F04A837C9E612C1ULL, 0x499A5B96E3862B9CULL, 0x22927DB61943DEEBULL, 0x56F7B8AC9F928ECFULL, 
            0x27D311C6B6256275ULL, 0x0B413B8F09A43F7CULL, 0x6134F86D7972EC4EULL, 0x92B13BE05AFD3DB8ULL, 
            0x1B4CC4C66B18910BULL, 0x2BC13AA2D75B9FE9ULL, 0x4154771E4D4EB2B0ULL, 0xFB5F6092E484CF68ULL, 
            0xA2B44B83C9C92DB7ULL, 0x690C16C8686AAB92ULL, 0x2A90616F526D9368ULL, 0x4BF3CB32E94369FBULL, 
            0xF8CF893BDF308A5AULL, 0xE00F33850B2866FBULL, 0x7E65A60A26EBB9B3ULL, 0x5179C612655D447CULL, 
            0x8174C244304371E9ULL, 0x201D32BE977329ADULL, 0x5E0F135E5D0976A8ULL, 0x6E109D570CADEE7DULL, 
            0xEAF35C5FF60BA2F1ULL, 0xA79A37DE342DE2DCULL, 0xD0928973EFE1EAF6ULL, 0xA556C4CC76DB3C5DULL, 
            0xF6695E9C04AF0913ULL, 0xE2C6F4AC01AFF3B0ULL, 0xF857B53D4D83E394ULL, 0xE91E25E24762235EULL
        },
        {
            0x4404746780CB34B6ULL, 0x96FCF81FE873A37CULL, 0x3A9993D7C1E4C657ULL, 0xB9430474FB754518ULL, 
            0xAAAA049FB003986BULL, 0x64C111A9AB65C355ULL, 0x8B677024874855F4ULL, 0x342297C89EB58F47ULL, 
            0x0C6963A962B501F2ULL, 0xBEF992608B72736DULL, 0x9A60ED19EC70FE82ULL, 0x6067732DB5B5F6EBULL, 
            0xC611B522918BA2FBULL, 0x044CE5386A87AC69ULL, 0x994518D7D91DE59AULL, 0x22D01D670D8BD4E2ULL, 
            0xA881DDCFEC6871ACULL, 0xBD5246D7063CC81CULL, 0x624E33C53CF4CDB9ULL, 0x52011A30F67AF7A7ULL, 
            0xD72DB6F4AB628075ULL, 0x97275CD62AB7F1A6ULL, 0xFA2155E31FD141B6ULL, 0xFC094F308AFEF8B4ULL, 
            0x1F3041EFACE47E57ULL, 0x99F5814D617C025BULL, 0xA309FE0DF2F8BAEBULL, 0xF4C61AAC045BC2EFULL, 
            0x6BB6FD6435B1923AULL, 0x7C110B0E275DB789ULL, 0x00307E639C41664EULL, 0xC9632982F992C871ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseEConstants = {
    0x0E8FBA916A517AB5ULL,
    0xC001F2C42A4BFEFFULL,
    0xE71D51A843B6CD66ULL,
    0x0E8FBA916A517AB5ULL,
    0xC001F2C42A4BFEFFULL,
    0xE71D51A843B6CD66ULL,
    0xBA5EF43C9E33CA9BULL,
    0x5819FE83D64C31F4ULL,
    0x39,
    0xBE,
    0x92,
    0xCE,
    0x86,
    0x20,
    0x56,
    0x31
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseFSalts = {
    {
        {
            0x0E68C174A8B58932ULL, 0xF02CC8B1CCDBA100ULL, 0x81B36C4A437D839EULL, 0xE46E4A463C8F9470ULL, 
            0x783086B765DA2416ULL, 0xB7725BA1A81D1417ULL, 0x2306D7F0C75C0DD9ULL, 0x283BCF0AE0A75B5BULL, 
            0x463BCCD86A7E86A2ULL, 0xA0D59228FA367A42ULL, 0xC8ACEC74F82F86D5ULL, 0xC20B87E145A8BC01ULL, 
            0x7DA8D9719C7D8300ULL, 0x72D4F4EF3BF83F3EULL, 0x5AA23587AFAE4D89ULL, 0x1EEC512E3735953EULL, 
            0x49CCDB8D8A2E56F8ULL, 0x45C0C6D40EC0E440ULL, 0x4AF357333FA2AE83ULL, 0xE96A769B76631019ULL, 
            0x11EBFBA7E53153DBULL, 0xA8818920DDDF8063ULL, 0xC98F3AFE5CC0B3FDULL, 0x8FA495F3A7A4184AULL, 
            0x7127728F9C6F9408ULL, 0x0C6000C8175E3B8DULL, 0x4321E96979439362ULL, 0xACEDCA99FA67720AULL, 
            0x261DE61CC3349A2AULL, 0x3FD60FD01B8745EDULL, 0x539F2FD9F4DCBDE1ULL, 0x12BEA6CC9B7B477FULL
        },
        {
            0x54A800CEA4BFC432ULL, 0xA8EC41D0A1733EE7ULL, 0xF34E2D208D29D5CAULL, 0x9A001DB845D80C6EULL, 
            0x11E9FFDDBEA60369ULL, 0xA933D3A485542BE0ULL, 0x0AA312DB70C3E8FFULL, 0x285B2F8D8F4491F5ULL, 
            0x7D29A27AC8F34C2FULL, 0xDC0937095788B5F2ULL, 0x75BF6FD9CDA18D3FULL, 0xBEA4FAEF97D5ABB3ULL, 
            0x7CD1BCE6DC7B5E75ULL, 0x5EA806286DBC77CBULL, 0x1F2B3A07D6765B3DULL, 0x442B574E4AF3E3EAULL, 
            0x104EA4836860B5FEULL, 0x3DB9DD9803161DA4ULL, 0x6FB1AA9783D31A53ULL, 0xBCC64C4EE953B224ULL, 
            0xC075491C3F643529ULL, 0x73E2C18258587B60ULL, 0xF360812EC6879DABULL, 0x407A1749D91A1B33ULL, 
            0x8250BEBDB7DB51B3ULL, 0x239D17FCDDB1AF6CULL, 0x255019E545BA369BULL, 0x4DCA4384B465B27CULL, 
            0x1D68047E04DBFCD7ULL, 0xC6627486EC45EDE1ULL, 0x9FEB6DA08DAB927DULL, 0xC3932379DB06E291ULL
        },
        {
            0xDEF00A671533C5B6ULL, 0xB19B665A938E41B5ULL, 0x3917ED9BCE59AEC6ULL, 0x3FAF3650D761334CULL, 
            0x4DFA81032DEA38F5ULL, 0xB88244A076B1CD9CULL, 0x7F833D008604613CULL, 0xA9B5B986246F6954ULL, 
            0xCEA1CEA8DDC42BE9ULL, 0x44C73D68C0298047ULL, 0x1893C4DF2B5D9F13ULL, 0x75AD2A67E41254EEULL, 
            0xD9CCA6750726CBBEULL, 0x27DEAE2251562A0AULL, 0xD97B875867E956E7ULL, 0x911857EF86F4A1D0ULL, 
            0x5F1E9D5970983CA5ULL, 0x5679D8E695E445CCULL, 0x97A5BD959FADC511ULL, 0xEDD4D02D50827A27ULL, 
            0xABF018531703A48AULL, 0x186777499CEFD4DFULL, 0xA88206F5AB65BE4BULL, 0x2C138BE28EEBD237ULL, 
            0xCBEAB085FA71A122ULL, 0x2E23225A631ED40FULL, 0xBC3A294C04804C81ULL, 0xFB8EA62A3B832F78ULL, 
            0xB9C3977DA4051DBCULL, 0xDDF92E55870855E8ULL, 0x08389D652838AAE7ULL, 0xC0FFCC85C74D6FD0ULL
        },
        {
            0xD3246A57BF1C89DFULL, 0x8A409506C45F1C14ULL, 0x53A12B1CB9370AB3ULL, 0x173DFA9809601230ULL, 
            0x93E08C147BB5794FULL, 0xD520DCF2792F12C7ULL, 0xA21ACCCC5954F5AEULL, 0xFF6C4A65350F8552ULL, 
            0xC37426676CC04D86ULL, 0xDF8CE8CB49EFFF3BULL, 0x932A50FDAE78FF16ULL, 0x2CD25CB4184CD909ULL, 
            0xC924979A6B9912CEULL, 0x326AE393F14ECEE2ULL, 0x71677CF9007876D8ULL, 0x4E340529143C8615ULL, 
            0xD7F5CEA9AD81D7EAULL, 0x142741095754AED8ULL, 0x5914A595B4DA52C2ULL, 0xA926DC2DE204075CULL, 
            0xC74128145F40B6DFULL, 0xBFE42107F01B53D8ULL, 0xD58499E937D5F3EBULL, 0x4FEDB54CD7F4B028ULL, 
            0x62A591AA991F6A17ULL, 0x9E3E149FBA22500BULL, 0x23132BFF1A6EF763ULL, 0xC67D5238B056194FULL, 
            0x16417D3DE773FDE2ULL, 0xD4A348587F9E84DBULL, 0xDD1C2EF4FAFD0C01ULL, 0xAA673ED7CA34B4D1ULL
        },
        {
            0x96457F5AEE138CADULL, 0xCCC641B3D73097ADULL, 0x76558BB6CCC37076ULL, 0x57AD9B065C1B617DULL, 
            0x533A39D06AE20755ULL, 0xFC5A3FBCF227B75AULL, 0x0196BFA9280FF036ULL, 0x8CCF010AD1868A7CULL, 
            0x767DC26581A5B137ULL, 0x40BCEA64699E4B33ULL, 0xD6DC4F36D559BA89ULL, 0x69E53EEBB1E47804ULL, 
            0xF2EDCCE138ACDADCULL, 0x1F7D57E46BC0E5BBULL, 0x134581892B713D97ULL, 0x089224245D9F3B5EULL, 
            0x8E4FB53D3680FE07ULL, 0x57F0303A35434207ULL, 0x62AFE29FF5840E28ULL, 0xDA85235FD5626AFFULL, 
            0x0A55231B10503A35ULL, 0xF30E37EC1E4A6152ULL, 0xBE8DD5A5028FFA79ULL, 0x6FED75F4E2DBEBF2ULL, 
            0x0C88442345D6C0B2ULL, 0xF56A554B08A8BB2FULL, 0x4DD732077F0271BCULL, 0x8BA233D353C3AB8FULL, 
            0x3DCB10635AC3E774ULL, 0xD6CDCA1BB47A6971ULL, 0x4B674DF97443FAACULL, 0x23789300CBDEBC63ULL
        },
        {
            0xAEA1ED7E32777299ULL, 0x1F2FD2D715B0DFFDULL, 0x67DC9604254041C5ULL, 0x9FBAD1EA59F11A09ULL, 
            0x7E266FF62B0DB89CULL, 0x14B9DA587A000E30ULL, 0xAC7F2811636CD3DCULL, 0x3891416E50B1A8B2ULL, 
            0xE4C852F2C4A12FC1ULL, 0xBDFC15FAD66BDA64ULL, 0xE629997B1909F494ULL, 0x3EEBF9F69A3FDCCBULL, 
            0xFBE7E0E814846239ULL, 0x404F4ECA5C855850ULL, 0x00032384899ADB54ULL, 0x95C7940BDAADD9AFULL, 
            0x07C418F0EC018C45ULL, 0x40682037DD21CF4DULL, 0x3A764B3529CDAAE2ULL, 0x11342B3DF2458BA2ULL, 
            0xC9A0D8DBF7FB6553ULL, 0xBD6A24D8C73A0B84ULL, 0x8D90901BBFB3A031ULL, 0xBA74E1292D7D867AULL, 
            0xD8133250DDB1B232ULL, 0xA94B7EB854110884ULL, 0x24929DFEA9FA7C69ULL, 0x59C1A21870CE52C7ULL, 
            0x3E2205AFA592F341ULL, 0x68146B610B977869ULL, 0x32C8BA5F08357A57ULL, 0x46F4CA2AD277C88FULL
        }
    },
    {
        {
            0xCE7CA9D668DCF77AULL, 0x6EAF8AD9DB3E58E7ULL, 0x0BBB01042F2438FDULL, 0x4B82910F90DED208ULL, 
            0xE71B0C74DA0AA175ULL, 0xDDE4E042DAF2D72FULL, 0x814AF8D50DB549E9ULL, 0x0E1581CDC4790F3BULL, 
            0x89477F2FB0AACF15ULL, 0x7394F11B6BBBF56FULL, 0x908B502A8FC81C7EULL, 0x05DECAFAC5FE0A60ULL, 
            0x88CBBAAD53B2D854ULL, 0xEAEDA1AFB3F6F921ULL, 0xDB2B05D88A5BB6D4ULL, 0x5A7D0A8355B852DFULL, 
            0x2B1559E4B3A55AA1ULL, 0x6B706F88BE96A862ULL, 0x769ED1D62F3A2808ULL, 0xC239DFAE54383058ULL, 
            0x56B58605B0BFC58CULL, 0xB43EDA136C6D1354ULL, 0xBCB3A513AC28908BULL, 0x1D8551EE757128E2ULL, 
            0x8170A801061E75C6ULL, 0xC21689205402623AULL, 0x2B2A8B27DD6C13D2ULL, 0xD298E7F50E61A77FULL, 
            0x3F7CD01F5B41414FULL, 0x684F5CB27F937C46ULL, 0xF3D7BB342B7B0987ULL, 0x7961CA83A433A0ADULL
        },
        {
            0x128B6D027BAE35E4ULL, 0xA05BB3025C7310A9ULL, 0x51DD91F4FE1782BAULL, 0xD2F1C97B0F7F8330ULL, 
            0x05D3D28024B2078DULL, 0x0A6393A0DFE56550ULL, 0x305B2BE5E8B51BA8ULL, 0xA6BB2BE19B74F5AAULL, 
            0xFA16B15BA7FB2E21ULL, 0xA1E6579783A554FAULL, 0x8917442E6DE30A25ULL, 0xC673234F03D51A6DULL, 
            0xA063A3918E6E8F13ULL, 0x6134A2D53A808767ULL, 0x3808E2F3348425DEULL, 0x6DAB7316AA129892ULL, 
            0xC338896851B29E02ULL, 0x5CC50A8055DF17D7ULL, 0x86D7466013740192ULL, 0xAE6C36A69341A5C1ULL, 
            0x65BF7F4715D322C3ULL, 0x7C1235CB7EE2FDFBULL, 0xC453676AEF5C4470ULL, 0x9A6A4504E73EF5FFULL, 
            0x774BF3B713107DC2ULL, 0x15AC427736EACA2BULL, 0xA2798A59FB7C723DULL, 0x9F817D50EBF31737ULL, 
            0x52173C478E6F071DULL, 0xBCB12650D6C7C338ULL, 0xADEF89552FE53D9EULL, 0xA763622078269495ULL
        },
        {
            0xB760794FBAB55B79ULL, 0x581F12005AE5F2CAULL, 0xDEC490FD578E1635ULL, 0x8798C7F35744F579ULL, 
            0xA81712275FF18008ULL, 0x7AC2FB9B17089174ULL, 0x3AFC89FE2C3C2BD6ULL, 0x6000E6FC94C734D8ULL, 
            0x2403E5EB3CA6265DULL, 0x44CE80DD5E148578ULL, 0x8376AF2CBA19DCD2ULL, 0x0997B540FF5BA276ULL, 
            0x4E7D28A32533A1A8ULL, 0x94C4377C78019D3BULL, 0x02AA1E7062DA4972ULL, 0xB31F3E118BF18980ULL, 
            0x3DB6B5AAA483A4E2ULL, 0x10EA5A2353252934ULL, 0xDD1131EE6C2775AEULL, 0x4CF1D782EC99F62BULL, 
            0xFF41206CCF8D4678ULL, 0xD67DFAF70D8C3F1EULL, 0x67F3D4F0615CD717ULL, 0x9A0DA7EC1055BD8DULL, 
            0xB0367581F2220F99ULL, 0x35D00473B80125D6ULL, 0xABF9FE8FCA6285F6ULL, 0x8CB3A61090A2EF04ULL, 
            0x6CA46425E3DC1FCEULL, 0x455F9E3426BD1625ULL, 0x22FB8281D8CC23AAULL, 0x2566E0CAB6799525ULL
        },
        {
            0x1857E215072B9A69ULL, 0x1FE468CEC7749DE8ULL, 0xA9A092F8BA0DDF62ULL, 0x3B3904579AE43822ULL, 
            0x17CF3242E4B6C49CULL, 0xE643C6BF6F6C9E42ULL, 0x58038774C3FA1D1EULL, 0xB036E2EB3115C4A4ULL, 
            0x203CE06641E3F364ULL, 0x616C60402A8B22F5ULL, 0xBDDE4A398044CC0FULL, 0x42D6BC3234EC29EAULL, 
            0x012935E336F11E1CULL, 0xC39BF8AC1AD31EA9ULL, 0xF0281B3195FA7DBFULL, 0x1DAA2C41B6FF43A8ULL, 
            0x906762F377066312ULL, 0xBEDAA75EA9038909ULL, 0x83247BA3815CC86AULL, 0x865ED1C0684B4919ULL, 
            0xE1444E234EB2E575ULL, 0xB7571F92AB7BABC3ULL, 0xC8817BF5DF2140ABULL, 0xCBA1E4FCFFB2F4AAULL, 
            0x08705AF38962DAFEULL, 0x644FFD107394A9D7ULL, 0x65F69C8FF1D5E23DULL, 0x00CAA262E2873DF5ULL, 
            0x3558D4746CFBF5C6ULL, 0xA5EDF77BC01B2B48ULL, 0xAE04647376A0E23EULL, 0x597B2F194E1829F4ULL
        },
        {
            0x1FF5885ACBBD6AF9ULL, 0x565100720D121BF5ULL, 0xD473750486585AC4ULL, 0xC949B667023935FFULL, 
            0x3178B8F498119809ULL, 0xF5DC393F9B2148DDULL, 0xD9457DB3561D0C91ULL, 0x2CEB15A68B47EFBBULL, 
            0x36DB7AE95A45E991ULL, 0xB7C88112A1F68968ULL, 0x29D64E6E4A39FC51ULL, 0xB9A18834EEB9B529ULL, 
            0x97D162041D1FBFD1ULL, 0x5C2BB700AC2886BCULL, 0x251FAF6C8CB20981ULL, 0x7D542BF588FE11D7ULL, 
            0x415BBA00DA42150DULL, 0x9A205B61EF75A885ULL, 0x7D7FA953B399BA4EULL, 0x8BE97CE202070185ULL, 
            0xFB0C6C2CC7AB55A1ULL, 0xE1A172812A876F70ULL, 0x1AA88D372468C2EAULL, 0x61E10416CF3727B8ULL, 
            0xCDF2B6043AE2CC73ULL, 0x5BEC44039C25C3BAULL, 0x0F57E0002CDE3BCAULL, 0x03D3D246ABE233D4ULL, 
            0xDD39EFE834A42ABAULL, 0x23EEEA0164297AC8ULL, 0x83A39B2D276A5DE5ULL, 0xDC379041DB292F4CULL
        },
        {
            0x941DC42FAD9F7268ULL, 0x4E6E6A419877EA80ULL, 0xA887CAEDD564522CULL, 0xD0A5B0BFB8C611BCULL, 
            0x835F9C6A1C3F518EULL, 0x8B5FDE58A6ABF83CULL, 0xB5B8E652860BCDFBULL, 0x5BB0E93027868C5AULL, 
            0x28B1E5CA3223413FULL, 0x09B04CF5AFFBE23CULL, 0x08E33A1F2F25C0C3ULL, 0x6B9D47D9E89085E9ULL, 
            0x38A4240D3F998426ULL, 0x5E12FE6DA51EEA01ULL, 0x1862AEBBBB4FCCF2ULL, 0xE8759E6EA546C3FEULL, 
            0x505324DB92B867EFULL, 0x9485D396FA4C65F7ULL, 0x8E51B34C753CEFCEULL, 0x20C76350B287FA81ULL, 
            0x3E2B8A3A6247E34DULL, 0x2F65668EF11F96ABULL, 0x39D6290621373D6DULL, 0x402585CB1007D0F4ULL, 
            0x68504330369A482DULL, 0x1D8B4E264F9DD09CULL, 0x4034A5D524282678ULL, 0xD61FBC0E5D8DD049ULL, 
            0xA2FCC43E4B9A3D2BULL, 0x046F497308015050ULL, 0x3814DAE8F6079535ULL, 0xD020719B5F752C18ULL
        }
    },
    {
        {
            0x86ED91ACF22FBF31ULL, 0x688D2009E7D7A500ULL, 0x0F7BD6C6F7E62430ULL, 0x8813D08960E481E5ULL, 
            0x3C99CBAF5B2BBC98ULL, 0xF70E425BD17F12F6ULL, 0x4C9766B3C6ADFDD4ULL, 0x09744DB073DC5E9FULL, 
            0x7CE06A54F8409C78ULL, 0x91D73D4A3EE5E32FULL, 0x8D60FC86F70E2A0AULL, 0x535FEEB8F95FA895ULL, 
            0x132BC118EDC96E2DULL, 0x35775E2B6D3072F3ULL, 0x1D66032F9A224B68ULL, 0x66D02484810857C1ULL, 
            0x23134F30A7C43CE1ULL, 0x7129E1F9D2D09AC4ULL, 0xC6FFA4ABE401325FULL, 0x6A561EE13515C550ULL, 
            0x17620709895FAFB0ULL, 0xC164C0BD86CFEAA3ULL, 0x5A31A7EB2BB76524ULL, 0x4936DE946B74FF07ULL, 
            0x0E18FF6F0CE22DF4ULL, 0x0CE46F2402D4AD92ULL, 0x571C7B77DD75E203ULL, 0x048748578D162119ULL, 
            0x654BC90BCE55E3E7ULL, 0xC5C5A3D74A552CF3ULL, 0x39B40CA659FC5E8FULL, 0x742EC483B5C1DD4FULL
        },
        {
            0xA2FF3A2B664C699FULL, 0x1E60DB2713B6F290ULL, 0x55C8B37E4AC4A685ULL, 0x84B0AB70877AAF37ULL, 
            0x8609CD6CC107BB42ULL, 0xB477B04E8211B9E1ULL, 0x22B314FCB222F1F6ULL, 0xAFB925C24EF09AB2ULL, 
            0x3E5E208752235F06ULL, 0x2B9F8EB28F64E2C1ULL, 0x4655A35BF556A854ULL, 0x264A80FD0C8A3D1CULL, 
            0x11C7B9B84FFC5E6FULL, 0x4FB0455E9AE0E79FULL, 0xCC03074725F0D826ULL, 0xAA20600224CEB357ULL, 
            0x04286F258CDA2418ULL, 0xD61BCB22A7F126EDULL, 0xBC673F6F42F2D729ULL, 0x0D50C3E0BC7EB9F5ULL, 
            0xD2B6F9D963FE9DB4ULL, 0x3D304CC92398D95EULL, 0x80E1124A6A7834E9ULL, 0x3421FF6FE7A53174ULL, 
            0xAFFC57F7A20DB786ULL, 0x7044CD5DE712D9E5ULL, 0x4905E57003FFE011ULL, 0x28549E27EF34D5F7ULL, 
            0x96B7D3F6E6795D65ULL, 0x27CB99B9CF41902CULL, 0x52B4612D3AD3B5B1ULL, 0x13EE72AD985EDFF4ULL
        },
        {
            0x1B3F2B8F39CDE437ULL, 0xFB96D41C7E7F5F37ULL, 0x940B2989522E2C84ULL, 0x3D8B0FA728DFB48FULL, 
            0x3A7578874F929CC6ULL, 0xEF935652D54A1F81ULL, 0xCDB7A17F8BDA025AULL, 0x97654007005FD6A3ULL, 
            0xC15E9A6D17BC273FULL, 0x1AE8836802AA4BC1ULL, 0xCA2D1A205CD9398EULL, 0xE08590FC5D42CB67ULL, 
            0xB60FE4D7C2AFA1CCULL, 0x6E513905A7B2E3CEULL, 0x430EF66524411D64ULL, 0x912F86ABAA76AF2CULL, 
            0x0D23211FB9CFD4BBULL, 0x851595850988F7CCULL, 0x85341C21A3ACAFFDULL, 0x1733AC54912EB544ULL, 
            0xFD94CFE02657771CULL, 0x00EE416F471ADFA5ULL, 0x341D256CE815FAD3ULL, 0x863AED87D49FD1AFULL, 
            0x94C1771AFB6D479AULL, 0x2399283D205134F8ULL, 0xEC67FE99A88090CCULL, 0x6ED83B5A76923532ULL, 
            0xCD6BECD6A184254EULL, 0x74087717AD1983CBULL, 0x089719C6E9E6FDF7ULL, 0xBA64A76972B3A0A0ULL
        },
        {
            0x231AAF33D28BC368ULL, 0xA401930BAD2F51FFULL, 0x9DF462906C323D02ULL, 0x376C29257903E9F6ULL, 
            0x8CE2EF14428542B2ULL, 0xA137669959363CA1ULL, 0xC031F9921F36D6FAULL, 0xA156FA11989DA7D1ULL, 
            0xE8291E054D75B6F7ULL, 0xD8561AEDB4FE3A04ULL, 0x6413A3FC045D172CULL, 0x91B09B9424D2B424ULL, 
            0x54393EE1AC9CB701ULL, 0x267FCBC4495E4F1AULL, 0x514B632DE9B7A160ULL, 0xD8B5DBD4A8A4C6FFULL, 
            0x1D31D2522C93275FULL, 0x9D0A9E7D423BFABCULL, 0x5C520F07B1F28EA5ULL, 0xEB14A9D06E8D6D12ULL, 
            0xD1EFD35B1FBF3D3FULL, 0x2A22EFA0220CFB7EULL, 0xCC3675FB55BDA6FEULL, 0xF60AF8DE57460819ULL, 
            0x9203ECC44AA68B75ULL, 0x5F4A28E99FFFE103ULL, 0x86F56864E8150B63ULL, 0x3AC37FF6889F7B11ULL, 
            0xEEFFCFAD3041B85DULL, 0xC017C724DD1CF9B2ULL, 0x568DDE99606DD3C2ULL, 0xCBDC2EAB901A8950ULL
        },
        {
            0x5816F2BB79A04EF4ULL, 0x5B1B576ED9EFE02DULL, 0xD89676FEE75B1413ULL, 0x6E83093A09DDB1E3ULL, 
            0x66EE04E4A3134307ULL, 0xFDB06145B649EA54ULL, 0xC1DC7E9AD0CAE30EULL, 0x1D411C11AE81D74AULL, 
            0x9AF945317F0F4971ULL, 0xD966ACBF96B0F3CCULL, 0xF9EDB828E1D2C98DULL, 0x119E5E52012892D5ULL, 
            0xC1955864AAEF418EULL, 0x2DCDE2403556C295ULL, 0xF1C7A85E784AD366ULL, 0x619142F90BC07D73ULL, 
            0x8D900C6DDC94B9C4ULL, 0xDD0A493ABBDBED1AULL, 0x528F3F19B480EFBCULL, 0xAA8E27A88027DB1BULL, 
            0xDEDEDFF5427835F1ULL, 0x343F7E14623432DEULL, 0xC187E73A27622824ULL, 0xF713817ECC842772ULL, 
            0x5E10AFCA8D029875ULL, 0x6CED4809E5C146CCULL, 0x80C70A0C419F8561ULL, 0xA2324689729CB5F6ULL, 
            0xEECA3BAC66ABE90BULL, 0x71B41B1055BCB5DFULL, 0x571361B7E95FAF4CULL, 0x4EFB437E511E3984ULL
        },
        {
            0x798FA9C219B52B78ULL, 0xF7DBD212674CBEAEULL, 0xEB69FBBE78B32BDCULL, 0x648FB688671906C0ULL, 
            0x3D08259E6114FFFEULL, 0x6AD120C24CCD12D2ULL, 0x9CF4DC6A1CA21F65ULL, 0xF0ECCBEC215D7B20ULL, 
            0x03645FE3B5CDD774ULL, 0xB7E5344B9DF5BDD1ULL, 0x5622FF8A4A7E440AULL, 0x12023ABCF333D779ULL, 
            0xA92C4BCA111C29DFULL, 0x66799D576D1B1EACULL, 0xC6C71D102560EC7DULL, 0x8D84857C9F8F10ACULL, 
            0x1FB1AD32C29975F1ULL, 0x993D09E574B43386ULL, 0xC0E178DF37C9F9D0ULL, 0x04CF69AF9ED0769AULL, 
            0x0FD1CF3363D3CDADULL, 0xD7D818AC7429D82FULL, 0x0EF012D2233DABA1ULL, 0xACC588F95D463790ULL, 
            0x91C7CF53345ACA8AULL, 0xA74E0EFAEF9FB2D8ULL, 0x858ED586554FDAEFULL, 0xBFD3E176F2228BA0ULL, 
            0x6EF36BC50AEE7B58ULL, 0x419C43412B0923F7ULL, 0xB80FB8B6F789B486ULL, 0x60081291EDD4B71BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseFConstants = {
    0x11F6154521DAAE17ULL,
    0xC8CB1055C37E35B6ULL,
    0xE8D89886D8D31237ULL,
    0x11F6154521DAAE17ULL,
    0xC8CB1055C37E35B6ULL,
    0xE8D89886D8D31237ULL,
    0x95FD235E75E1F3E8ULL,
    0x8E950C0F722C60F1ULL,
    0xBF,
    0x9D,
    0x31,
    0x4C,
    0x5C,
    0x95,
    0xCE,
    0x65
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseGSalts = {
    {
        {
            0x0461007E5F2F6A32ULL, 0x9CF5039D2DCE1398ULL, 0xFD39C3DBC91CC9CCULL, 0x79C4F0AEFB4505F1ULL, 
            0xB720160500CC73C5ULL, 0x318AF7FC6C469AA9ULL, 0xAFA089472E6F14F6ULL, 0x50E9E46F79E5DC14ULL, 
            0xCB944B78A666E2B1ULL, 0xA057A80B1501AACCULL, 0x0681AE6A26B0E5EDULL, 0x70EB838F394A9585ULL, 
            0x35E342C88FA39372ULL, 0x038B1CD7A5631230ULL, 0xDE7F7955AFF76899ULL, 0x6C1B8B11636A5697ULL, 
            0x0F3B1AF8B7F90BFFULL, 0x3809018196E62219ULL, 0xCAE3395E744B075DULL, 0xBCD7DDB126DE9F64ULL, 
            0xE48D4E66078AFB37ULL, 0x27C6C3A4E24F1CF2ULL, 0xD78FC4E6AA6E73ECULL, 0xD7CA733CD14DB7C2ULL, 
            0x8D11CB75598242A9ULL, 0x8A262191404B4CE5ULL, 0x8E908B2B11B064C2ULL, 0x190ADB70CB8B700FULL, 
            0xAFC5C9D6613ED615ULL, 0xEF678E4AA5685DB9ULL, 0x20DD0D8A1597F55BULL, 0xE72DC6FE47A6123CULL
        },
        {
            0x7A738385E531D8C3ULL, 0xBC1FDD8D365D124AULL, 0xF5F056C5134E2236ULL, 0x2FBE67EEE52A2B34ULL, 
            0x8F1CE3577A357C71ULL, 0x76ED1A14E50821CBULL, 0xF936E6F88AF36B94ULL, 0x3DD7CD26922E0DFEULL, 
            0x531711B5FA213144ULL, 0xBFA7031E35074261ULL, 0x8DCFF7244A5115BAULL, 0x3AC0920FD336A234ULL, 
            0xFA12456256A87DFDULL, 0x39007BF0FF17C77CULL, 0x9A9ACE5F562675A6ULL, 0xBDECB160326F08D9ULL, 
            0xFA86AF530B8C41BFULL, 0x497E6F2588794BA1ULL, 0x23A291475E9B84B3ULL, 0x88118B7D6AACBE14ULL, 
            0x59A809443FD07C45ULL, 0x2E6BE3CA7D473894ULL, 0x4DB602061758BCDEULL, 0x8914F391542A5540ULL, 
            0xA1B929631B588497ULL, 0xE7C2250E28E99C99ULL, 0x7E0FC13EA4D15427ULL, 0x1F2729AB91ED4761ULL, 
            0x0C1DEEC21106740CULL, 0xC8C70ADF91681B32ULL, 0x2C197CF7B0C44796ULL, 0x39A30F687A69B970ULL
        },
        {
            0xCB6A910A6ECA9F49ULL, 0x393CBCC7532D7A18ULL, 0xA7EC39808C7614C6ULL, 0xB46B2E3169ECD962ULL, 
            0x281470776E949B3FULL, 0x587FD76521078776ULL, 0xBCD21D05DD4B354EULL, 0x9727D7367D5F0671ULL, 
            0x58D7C67441520815ULL, 0xA87F9373E2E4652DULL, 0xECA207C1CB4ABE3FULL, 0xF81E8CE7590CA097ULL, 
            0xB65FD00B681E7658ULL, 0xA0A10C8C42566A8CULL, 0x785BEE064508C948ULL, 0x2A7C107C8903DF76ULL, 
            0x56AE697FA98A621BULL, 0x6DE0F751AEF6BE45ULL, 0x2D433824693B4D27ULL, 0xD0E2E2E4469B4248ULL, 
            0xD1FC6A5C5C3A0CC7ULL, 0x0D22744C443261C1ULL, 0x5C7AF6FF40A2CA0EULL, 0xEC78D5004F2DA688ULL, 
            0x8C0DA2C2A7D0A90CULL, 0xAA511501A1063593ULL, 0x1067B1A1722D00AEULL, 0x044FB1359DB91601ULL, 
            0x2EFED8FFCD96F96FULL, 0xEB97A02C3E60E3C6ULL, 0x07718E6DFD5B4079ULL, 0x8A6E3550A891A1C6ULL
        },
        {
            0xB9E8BE16960EC2DBULL, 0xF996A70363954F06ULL, 0x4FAC9104551AE42CULL, 0x3E3E48C6190A6D1DULL, 
            0xE4F078A62A7C2BCCULL, 0x82A632B5FCCABDBFULL, 0x9CC7E67349455E0EULL, 0x8BFABFE2D7EF867FULL, 
            0x0B1184D5BA2212EEULL, 0xF19DC9F5FAA7B0FCULL, 0x6329217EA266E8DAULL, 0x8B0A784D7A9DDF6AULL, 
            0x5B141DAED50F6F17ULL, 0x3BF7E594384C2CE4ULL, 0x3022AEA05528BBD9ULL, 0xACFF907EB41AF4C9ULL, 
            0x433C49FBBA53EAEDULL, 0xD2BBFA9F6A0E2586ULL, 0x3D181E8728C1A314ULL, 0x0818EDD97EF0C1B1ULL, 
            0xBE508DA695716024ULL, 0x9D7F499208493E0DULL, 0xE13D96B481B11846ULL, 0x045F475B11A72E29ULL, 
            0xC1BE3F1813F118AAULL, 0xF934B57E24C22BE0ULL, 0x42B00E3724F33573ULL, 0x371437B995C1A241ULL, 
            0x83E91B3FCF5B7D2CULL, 0x99E51DB942B83F7CULL, 0xC20EE1844DE9BEFCULL, 0x5965746849F63580ULL
        },
        {
            0xDDF714C7523FA494ULL, 0x4A925CEBF41941C5ULL, 0x964AE599A9838990ULL, 0x1562CED5567D4337ULL, 
            0xDF4C2A64D8DF29DEULL, 0x0A1473CA9B463536ULL, 0xFE998BB80E112FD7ULL, 0xC5DDB5C4BD06224CULL, 
            0xB4D968B40D1DB2EBULL, 0xF7F3DEE3519905D6ULL, 0xBA612015C7173A1AULL, 0x08E3D9D1E2A3B82AULL, 
            0xB5CAAA450A951942ULL, 0x1D3ADEF16BBDA1CFULL, 0xA9D09FCD308B37FFULL, 0xF7FD43C39DA335C8ULL, 
            0xC2EF48BBBFABDD8DULL, 0x62957514B907A8F9ULL, 0xCBB9552B0F4E3940ULL, 0x0F1E0E7D80E02F77ULL, 
            0x262CB6C23E5D3053ULL, 0x139499C870CEBD46ULL, 0xACE1CF6A459B97DCULL, 0x4D21E2B50D71B0F6ULL, 
            0xDD8AA79C05393D3FULL, 0xF2660B8E20D8547AULL, 0x9EA80DD32E8CB280ULL, 0x9D075E847D8C6D8CULL, 
            0x5EE35502ECA5AAFBULL, 0x2A863CAE22F821B6ULL, 0xA6A850960AE9DBD3ULL, 0xDE8D0F8424BCCFABULL
        },
        {
            0xC144D958F184FC45ULL, 0x11F9C33878A9AB1CULL, 0xBAFD90B59CFC2863ULL, 0x985B90115D4CB256ULL, 
            0x64C5113F60017846ULL, 0x9A0ACD892FA6871EULL, 0xDF1ABF0AE62D3E77ULL, 0x6D52A1DDC73228B4ULL, 
            0x8E97E70521891C5BULL, 0xDFA883197B303618ULL, 0x860D68949E44E913ULL, 0x15704DCDF9F54401ULL, 
            0xCAF9ABD79951FCA0ULL, 0x73D19DAE9C8FCCD2ULL, 0x6935FA77AA991CAEULL, 0xEF3F930D0F36355AULL, 
            0x4EC0A0C5413C6BA0ULL, 0xC30894EB16BEFB78ULL, 0xDC95123A182F56D4ULL, 0xC8CA3447AD0E93C0ULL, 
            0xEC1747ADDBBCF742ULL, 0x01EB583767CD6340ULL, 0x328570BB694490F3ULL, 0x6A47F59441CE65DEULL, 
            0x8AF8085DF697EA09ULL, 0x4EA5D62A5EA52665ULL, 0x40939043B657CC72ULL, 0x5BC911FE7C5575E7ULL, 
            0x2CC0CCC64C3D23ADULL, 0xB006D875F97770AAULL, 0xFFA6E0A0068C9FE3ULL, 0x3F4454B978558DCFULL
        }
    },
    {
        {
            0xCEF5D59F149FEFACULL, 0xD4DED68C3FB826BCULL, 0x13AF6BD32C26E138ULL, 0xDBA48539F019CE1CULL, 
            0x24C4FD7D60D1B7A8ULL, 0xA84514447AFDDF1AULL, 0xB2CF09E91636D240ULL, 0x487907BE0ECC64ADULL, 
            0x2D9CFC5F60ED469FULL, 0x5391F0C0EBD4913AULL, 0x1F70DF4632271AC4ULL, 0x53BCEAEECAD6D6BDULL, 
            0x500846FDCA81809BULL, 0x6C9EF675C0005A6BULL, 0x11730621E0AFAAB2ULL, 0x46EF21B14781D190ULL, 
            0xF385F553E2BE3B43ULL, 0x1EDE346079CDD938ULL, 0x666A705885C6212CULL, 0x6A8F3B49AD4E1140ULL, 
            0x46F23A1288423707ULL, 0xB463278DBA5E1CD5ULL, 0xC006FE16049880B4ULL, 0xFDFF8BFCCF747A73ULL, 
            0x1C7F855666A680F6ULL, 0x85F5ACD4B33DD556ULL, 0x9250E5F6F3BCD34DULL, 0x124A553D64ACAF16ULL, 
            0x6203B51C3EA081D4ULL, 0x00E2AD4F2064BE18ULL, 0x1258C4548243774DULL, 0xD936CCCF0B0E3DEFULL
        },
        {
            0xD0E0EE124593EE36ULL, 0x2EFB9D5E3C93092AULL, 0x0986DCF972A05565ULL, 0xA6BD1EB58B432058ULL, 
            0x1E1F2705219444D5ULL, 0xAAE2F5752F8F1723ULL, 0x2121EE0A1BB315DEULL, 0x49BCA2DCF1A42410ULL, 
            0x38D211DAAAF64077ULL, 0xE40DDF0B94B4E011ULL, 0xD60EF10C0158AD0AULL, 0xAF2C51070F831439ULL, 
            0xB7999337783DE93CULL, 0x6FE9275A177D3C07ULL, 0x80EE4C386956306EULL, 0xB41209C471034CC4ULL, 
            0xA6239FF667F6E586ULL, 0x8531496ADBE288FFULL, 0x993125234ECF4E32ULL, 0x5BF59CD06C683C8CULL, 
            0xB66B53A423DE7422ULL, 0x611DE09C27AB7214ULL, 0x03304C265CDCD850ULL, 0xA1C1131140D0D177ULL, 
            0xA1AE6D86ABBFF27CULL, 0x5455D93FE0B80F4DULL, 0xE3A7CB0D3F3559AFULL, 0x78DAB795CE79E3DEULL, 
            0x180048D664C36449ULL, 0x9CCE853B1A051464ULL, 0x7BB755BACAB14310ULL, 0x329DA05B4835431AULL
        },
        {
            0x4C2BD997ED9A63E3ULL, 0x6BAEC2F9FD14E099ULL, 0x8FA67CA58325F3CDULL, 0xDB755BF44D901170ULL, 
            0xF7A1216DD5D79084ULL, 0xBD2B67595A68903AULL, 0xF31E48EC41798817ULL, 0x16611BFE3DC0E811ULL, 
            0x3EF2B52ED45F2AF3ULL, 0xAD21801542B5E145ULL, 0xB684821A328C7098ULL, 0xA73BFB9ED84FC506ULL, 
            0x470FC91ABAABBDB7ULL, 0x53F3A58E10B1E034ULL, 0xB2BA9522BB65F7D4ULL, 0x49924D7EDFA500C8ULL, 
            0xEC2646A060390AAFULL, 0x2A96313F0CBBD03BULL, 0x74E1AE9252768EB3ULL, 0x29B739CC85216101ULL, 
            0x4030627ACDE5D2B6ULL, 0x5EB35F442749B07BULL, 0x278C118C83E25F78ULL, 0xFBAF477105C7A58BULL, 
            0x8BC3DF7A9FDAEB86ULL, 0xDE77AC4055BEE11FULL, 0x187B5954AD171FA8ULL, 0xD8D4B9464FD1BEEBULL, 
            0x1AA259E85787ED9DULL, 0xA0D9C384B13E9B04ULL, 0xFEA323A6C0150BCFULL, 0x0760792215528B79ULL
        },
        {
            0x2D3667E8D82C9EA9ULL, 0x94DD0E2ADA7AA18CULL, 0xD36EC5630B43C335ULL, 0x10D9D816A7ADFCB1ULL, 
            0x499CCBB846D41274ULL, 0xF6196FAEA06B9A64ULL, 0xC4C7C919DA6697BEULL, 0x06B1BE96BB0EC231ULL, 
            0xB5A6F0DEE81C6C1CULL, 0xFD746BC1A0329E4FULL, 0xFB6B42A6D4612B31ULL, 0x3C19FA9CAACD1461ULL, 
            0x20F2B728655DC863ULL, 0x3ABA2360B38F639EULL, 0x9B710CBDD55B99DAULL, 0xEC84C356FE167238ULL, 
            0xC973E68790F6680DULL, 0x92888369FC784FBEULL, 0x356CD94CCE4D3A57ULL, 0xAD78B373552F2AF2ULL, 
            0xA5EDED0CD740F156ULL, 0xFC5012E98DC274DCULL, 0xF2D8DDC2B98D7BB4ULL, 0xB1379B4CE3DD17D1ULL, 
            0xA87B1FE2B7CAE5B6ULL, 0xA8AFA71578EBA59BULL, 0xE3CFF90D59DB0470ULL, 0xF95CB6E787BFEDC6ULL, 
            0xF069AC97434D4299ULL, 0x762EEAC4061A44D6ULL, 0x01A09C8DC6085C3DULL, 0x7FA0CCE64C168346ULL
        },
        {
            0x39971521D4604DF3ULL, 0x3BD6BA593DD96069ULL, 0xCB1F66AD9647BDC7ULL, 0x08A8BBF34F7568E5ULL, 
            0x285A33715DE16EF2ULL, 0xD072BB7C75B878F2ULL, 0x0EB9DD08602C44D2ULL, 0xA615E4A003205ECBULL, 
            0x6B38E573A95821EDULL, 0xB37EB6335A6D706DULL, 0xC9F750B4B7ACF7C2ULL, 0x514991C1CCEC82F2ULL, 
            0x45F13551274344D3ULL, 0xBC6F7C22A4987C5FULL, 0x2C1C4A9ED2EA2F3DULL, 0xC4D10BC567110D5DULL, 
            0x3A9AD85DEC653882ULL, 0x12E923BCD43CACB2ULL, 0x8939B3570F3A0FD8ULL, 0x1BAF1DFE4821D293ULL, 
            0x7E6A56E360E2B385ULL, 0xB66F1006F67D2BE3ULL, 0x9DC7BAF986B4898BULL, 0x1D811489C947760AULL, 
            0xDF5324D5B68C13FBULL, 0x27C520EA41A219FBULL, 0x61E79AD1FE5659DFULL, 0x174EE1F9D5169DBBULL, 
            0xAB518B9B0C03454CULL, 0x4ADB85C7D2D9E4BDULL, 0x0E6D00AF856515ADULL, 0xC13117A17748E0C7ULL
        },
        {
            0x10B33FD70FAF2577ULL, 0xF9A6EA0089327436ULL, 0xBE6C91893E743976ULL, 0xD6A7E28A03194E8FULL, 
            0x8F28629472D55C6DULL, 0x208872C5BDE46B13ULL, 0xFE143722621395CFULL, 0x20399EDFAC6422A3ULL, 
            0x3B9383177C030F05ULL, 0x4CF79D2971F49938ULL, 0xEF27D3F5D495B970ULL, 0x12DB34C3ED7AD4CCULL, 
            0xBACA155B9628C59FULL, 0x9BEC19F88A6BBF7AULL, 0x5ECF8EB6A3461493ULL, 0x88C75714CB339106ULL, 
            0x3D28AC394D25C22AULL, 0x84E19BBC944BB85BULL, 0x3716D44ACC10DBFCULL, 0xAF7E41B9B702552EULL, 
            0x8CA1465889D2A84EULL, 0xE1BEA062D5A434B0ULL, 0x6906D4C722F93534ULL, 0xAD33880D6638EA85ULL, 
            0xE58AF45495EA23E8ULL, 0x7274EF1A96260D2BULL, 0x0B0CB07CD0A8929BULL, 0xA9AFEC60599E9A67ULL, 
            0xFD21383AF00AED51ULL, 0x3AEBD5612D761FA0ULL, 0x74E82D10DE6A3823ULL, 0x1228B0FA7A66C9A1ULL
        }
    },
    {
        {
            0x6E016104C15BE861ULL, 0x7A8926B0CDDEF2E7ULL, 0xC973E4C284FB90E4ULL, 0x54351A5520E167B9ULL, 
            0x264EBAA7DA6412B7ULL, 0x512BFE3C3332C5BBULL, 0x032F11EF52A43A9CULL, 0xD2A60367EE4410F5ULL, 
            0xB54F5EB394A48F4FULL, 0x1367B5DC41B877C8ULL, 0xCDF88AA0E40D3E88ULL, 0x1C8BCC6981B4AA2AULL, 
            0x64DC0720C2644101ULL, 0x162E6B51389989E8ULL, 0xA859D4A714597C60ULL, 0xB2A27D8F8DCE0EF3ULL, 
            0xA3ED2BF84987D68AULL, 0x4CD206A9B3EFB429ULL, 0x93A242F3B6B6C47FULL, 0x2F63BA1DA6C1C7BFULL, 
            0x6A966E180733FB67ULL, 0x11F76FBF283D3B0DULL, 0xB0C687C88D667ACAULL, 0x83C476BD6A93E152ULL, 
            0x97BEBBDC3BC81402ULL, 0x52FB3891043F4875ULL, 0xF5D6C2E91AC718EBULL, 0x53F55C6DCEEC647EULL, 
            0xEF91B7EC075509B7ULL, 0x35EC001C907E9544ULL, 0x408CB991E9D89BECULL, 0x0E2FA01429F8140EULL
        },
        {
            0x15AB669CA7919274ULL, 0xDD993408A832F3FBULL, 0xD132BFCC466C3B03ULL, 0x42BE0ECAB1FDD9C1ULL, 
            0xDAF7EBFDF1522FD5ULL, 0x83002036D5C79E36ULL, 0x2D0819AB4322A265ULL, 0xA94A36E0B9A53DE9ULL, 
            0x83D110FBB27F0598ULL, 0xD39975EBF130FF2AULL, 0x263DE997A1A292DCULL, 0xBBD4CCE5B105E925ULL, 
            0x6C1156FFD97CA14BULL, 0x2496F181100D9028ULL, 0xCBCF2DB6119AFE1BULL, 0x34AB498C51E58222ULL, 
            0x2008421CBA548415ULL, 0xB2079B33FA51C9F3ULL, 0x07310A51B1090E92ULL, 0x6BE19989677CDA3AULL, 
            0xA291013FB77F4131ULL, 0x47A10B672CCC5D82ULL, 0x89031E4C77E8AD4EULL, 0x0517F0E578AF001EULL, 
            0xE6991956DEB0961AULL, 0x82207029AEC622ACULL, 0x2806518C03A6BA33ULL, 0x575FDB2E8D5F8AF0ULL, 
            0xEC7911170A19DD9AULL, 0xB3F7655668837534ULL, 0xD2DFB8AA1B92F832ULL, 0xB1F5A7F24E2314DEULL
        },
        {
            0xF3B8E2BB76453A2AULL, 0x657F668D158E78A5ULL, 0x4F7E1E30739D68ADULL, 0xC32FAC8DFC1AEF91ULL, 
            0xA5A6F5D88C21D3A9ULL, 0xB0BB5B45AF3BB8BDULL, 0xB3768170D077A16DULL, 0x022624068ADB2701ULL, 
            0xEFB6E81D0480A202ULL, 0x2879C4C7F5516548ULL, 0x5AF1543A861C20E7ULL, 0x2563AB8FA6AA5664ULL, 
            0x6A9336430BD9FABBULL, 0x8236CDF1D712C636ULL, 0xF94B48DC99B8E371ULL, 0x105C61D1B9D5B08BULL, 
            0xB0B6B73E019FDC55ULL, 0x13925D6D9A03540EULL, 0x4023E57A83946315ULL, 0xFC9700CE774640A3ULL, 
            0xD2DB005E1A464448ULL, 0xB1003107014B6549ULL, 0xFF0E194794ED2DD3ULL, 0x0E967D524B2839BDULL, 
            0xD05631571F7405EBULL, 0x63F06A4DCAF16CE7ULL, 0x534EE1E096414397ULL, 0xE01BF86297DE8F64ULL, 
            0x0E17491A9526AB73ULL, 0x5261408A3E28DB44ULL, 0x774B83E3320DD840ULL, 0x2A562C7F8D3B718BULL
        },
        {
            0xBF829BE641B73026ULL, 0x9D43062BF1F0B97FULL, 0x9699D00926621972ULL, 0x4E959DC0E4ED58E6ULL, 
            0x5ABEEB5166B52055ULL, 0x0405BB04C669E796ULL, 0x08D636B4FB46ED17ULL, 0xD4A16781EEAA0B85ULL, 
            0x591C0B39877D3318ULL, 0x753FF9874A98422CULL, 0x242537DF9302479CULL, 0x2457852A54361F6BULL, 
            0x22F848E0228FEE17ULL, 0xFE21120F6D64D3F0ULL, 0x9EFE6CE9049FCA93ULL, 0x27655A4554C6D903ULL, 
            0x586A72BF97DF3FD9ULL, 0x3509FA135000EC20ULL, 0x32CD00408D5F6F53ULL, 0x2B102C1BB72FED91ULL, 
            0x7D816DE45EA19308ULL, 0x2A4BA28C3201E09EULL, 0x22B66A59F2F286AEULL, 0x6A7B183B08FC2869ULL, 
            0xD9A0C208A4A1B541ULL, 0x6CDC69F6AE04F00DULL, 0xABF7806F5698C262ULL, 0x6E0E202F7446C887ULL, 
            0x62691822BBC4FE74ULL, 0x3B244776580E3601ULL, 0x90E18AA537A79BD6ULL, 0xED9C3EDCA491855FULL
        },
        {
            0x312753D8DB86594DULL, 0xCFDFE1A2B04B2BD4ULL, 0x697B21EE7AEB5943ULL, 0x67F94B588AF374F8ULL, 
            0x6DB8184C37CF57C5ULL, 0x450E4A153D66911BULL, 0x0A972194F7FB123FULL, 0xEAE0926464D2A056ULL, 
            0xDA7C09D504A792A8ULL, 0xD63F350D1E80D3FCULL, 0x78B12C8389CEB32FULL, 0x026A0189BB41E0D5ULL, 
            0x6944ABA09003A10FULL, 0xF786917DABB9694EULL, 0x0B0874A5B8B8B22CULL, 0xBFCDD66D1DC33DBDULL, 
            0xD491E9249F571701ULL, 0x52F62F17C0B16D75ULL, 0xECF4AA80CDDBA660ULL, 0xBAABFC8E6E7DAC0AULL, 
            0xA83B309E82F8E979ULL, 0xA93636C811230F43ULL, 0x36901F4A1124C3D8ULL, 0x360184FD27CCF079ULL, 
            0xD44FC297CC90759FULL, 0xA6CD04FDD44381DEULL, 0xD2028EEC55BCEF85ULL, 0xEF83BCB226461DD7ULL, 
            0x51D201D4864128ABULL, 0xA8C19A5AAEFDCEA4ULL, 0x8790C3604EDFC785ULL, 0x2AD3B96186FDB3A7ULL
        },
        {
            0xEDE99067682F71E6ULL, 0x9753AA465F86193FULL, 0xC17776251A87E7E3ULL, 0xF86FA660E3AEE247ULL, 
            0xD34D64018F136573ULL, 0x946BE8ACC938B14CULL, 0x49536F3E3E1B5868ULL, 0xC638E8A9D417C057ULL, 
            0xAB2AB751616D8341ULL, 0xB8B45F984852FCD8ULL, 0x2C2CF75D9509987CULL, 0x8C384F9E6CAEC4D2ULL, 
            0x389CF477B27B39E5ULL, 0x64EFD4445200478DULL, 0x8122E18533301BCEULL, 0x8CE020A7DC12A3EBULL, 
            0xA1240D1DAAA0EFA3ULL, 0xAD0FEEC2DB1EC790ULL, 0x1846F1BA36E866E4ULL, 0x2B54DD3A499F1BCAULL, 
            0x0E81A01147FCDD3AULL, 0x611A35F6B415B8CCULL, 0xE32CC7EC39CA010DULL, 0xF5D41422D21B533BULL, 
            0x6ED555B23E6304D0ULL, 0xC979581FB80F2BC4ULL, 0xD7710C92E7690CB2ULL, 0x0DEFA2A10D422FA6ULL, 
            0xCEFE8A2A104AF47AULL, 0x4976B6B3771FF158ULL, 0x0BC2658549CE8B42ULL, 0x160E3BB29ABEA8FCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseGConstants = {
    0xAF5F37C55633920DULL,
    0x254677935DEE72D3ULL,
    0xCCC7B856700299A9ULL,
    0xAF5F37C55633920DULL,
    0x254677935DEE72D3ULL,
    0xCCC7B856700299A9ULL,
    0x937688F652029209ULL,
    0x39175BB646C4CBB7ULL,
    0x17,
    0x28,
    0xAE,
    0xED,
    0x2A,
    0x50,
    0x9D,
    0x49
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseHSalts = {
    {
        {
            0xA65EBFBD1B7EB04EULL, 0x87CF2E1BEE387D56ULL, 0xB7EDB18FD4E28486ULL, 0xDFF9E08672C4797BULL, 
            0xED0155CE3E1A111BULL, 0x78C2697629B073B0ULL, 0x663DB239C5D19E80ULL, 0x2DFCA34B1DDA9A47ULL, 
            0x8984BBE45984434EULL, 0x23EC3C7CFC524DB1ULL, 0x1C18B73DEDA497A5ULL, 0x84DB3787E77117ECULL, 
            0x1678B2707994D38DULL, 0x50C20CBF96252FA0ULL, 0x856134520C3104AAULL, 0x05AB14BFE334D3B3ULL, 
            0x7F6DEC18827DE9E9ULL, 0x7A5A93FA06BDD7E6ULL, 0xE8F67C00BFBA8C38ULL, 0xA8C88312163524A0ULL, 
            0x24DA6240DF78931CULL, 0x5D98942FCB3FBF76ULL, 0x202C4C6227ACFF65ULL, 0x1507E909B6C7841BULL, 
            0x52ED6518C5679599ULL, 0xF9FBA2D2D30A4F8BULL, 0x3140112A844DC48EULL, 0x210DCEB713B44AB9ULL, 
            0x575CE0936017258EULL, 0x68010370E405197BULL, 0xB0A783C72E3587A6ULL, 0xD1824F086EB1343AULL
        },
        {
            0x4BCD986441AD2323ULL, 0x8F47A24E2D5F5DB3ULL, 0x6883393F6FE1A6A3ULL, 0xF72215A81BC00219ULL, 
            0xB2A3E30369F4A6C8ULL, 0x5112F899DF5ABE93ULL, 0xF0D7D4C5E14B0BF7ULL, 0x0B6FF0FFA296C2AFULL, 
            0xD1A2198805EB9664ULL, 0x85E2576F63354303ULL, 0xE80D3996B6BA593FULL, 0xF496F58D7A10E014ULL, 
            0x5DFDAFDD84C290B0ULL, 0x7A0E4B490D2281EAULL, 0xD0C06C01B92A0A2FULL, 0x2950DECC28937E3AULL, 
            0x5B5AB837BA8D7CB9ULL, 0x5015B39E4B4C3BE3ULL, 0x9C8163DC9925FA8CULL, 0xF401430187A1198DULL, 
            0x4BE0472D624D3ACFULL, 0x6E4AC199A3C9C480ULL, 0x136E5706722553DFULL, 0xB81885152293D821ULL, 
            0x617F59CEFC01ACB6ULL, 0xEC928FFD935F7DB3ULL, 0x03DF57DD43A8AA38ULL, 0x5A2DF55CD63D1B9EULL, 
            0x90EF3144F5DD51ECULL, 0xEEEE08E231E3DFD3ULL, 0x2164A794EDE7CCC1ULL, 0xFA6D0F83BAAAE85DULL
        },
        {
            0x20C158A5A38F9319ULL, 0xE11B5B1C9FAE0385ULL, 0x85DDF56A9076F430ULL, 0x59F5DBDB7556714AULL, 
            0x9151383B051038B7ULL, 0xC28EFB28981BB3F2ULL, 0xFA5468A35E2167F1ULL, 0x0C007A3DA7A010A6ULL, 
            0xEAAFD2A3877EC798ULL, 0xE45FD30504611810ULL, 0x7E8873A87397558EULL, 0xDD76D7223853FF45ULL, 
            0x2F48EF9F9F45DF9AULL, 0x7B295E4F80890507ULL, 0xDF67C32A9466EDEAULL, 0x914FAE89DF4D4F0CULL, 
            0xFD92BF3D979EE0FEULL, 0x757D9840897C9F9BULL, 0x46EEDD781AAF4DDBULL, 0xC03B467C18F50A5AULL, 
            0x86B32551D59A4A97ULL, 0xAE09BD0D0B58DB3DULL, 0xD3EC383385567E48ULL, 0xB7CF5505EFB960C6ULL, 
            0xE26436FE053237FFULL, 0xAC9DB378CB7F582DULL, 0x6B41C0CDE3604763ULL, 0xEEBD51901E367AEBULL, 
            0x2C7E4DF10064111FULL, 0xA0A482A6447A7BA2ULL, 0x480CCB7728FB6C1BULL, 0x9AEA805984865513ULL
        },
        {
            0xC3B089DF71E01D5DULL, 0x0BEEC3F8B5CD93EEULL, 0xEE4B47E0D8F85238ULL, 0x7F35165A4FF51160ULL, 
            0x30026381FD57455FULL, 0xED69808E84C19313ULL, 0xD4B27A4B99437A66ULL, 0x9314F427BC7C4B3DULL, 
            0x00DC7171F9277148ULL, 0xEFED9AAAA2D26805ULL, 0xA64196E645C5AA02ULL, 0xA5FB8D1CED21F549ULL, 
            0x6F9C9789DADEF77DULL, 0x8657EBA759528535ULL, 0x5586C00558D102DFULL, 0x07CCC0E0864CEBC6ULL, 
            0x1C29FC210B42E205ULL, 0x0716F63C4D6C8704ULL, 0x1FEAD5872F75A6E1ULL, 0x1B429D64F96645BCULL, 
            0xDBC52E6992138912ULL, 0x2426605309BC84B2ULL, 0x7C1936727E6924A7ULL, 0x60C8355045A60F18ULL, 
            0x513740493D60B81DULL, 0x443FB377CB10B631ULL, 0x8F8E1431D9F36DA1ULL, 0x6183473EDA1F10E8ULL, 
            0x20AC46C2B21BCD13ULL, 0xA576A1E9CFB19592ULL, 0x2BDE39FA22A60B8EULL, 0xD778B394B9D0E83CULL
        },
        {
            0x37ADF5658720D000ULL, 0xC0261E69B55E5130ULL, 0x70207A09753BA975ULL, 0x27DF9EE10F2C59C9ULL, 
            0x9E1FB7F02F6E7D63ULL, 0xD3789201CB14977EULL, 0x38155F926E9D111BULL, 0x31E44A311D3591ADULL, 
            0x203ED52E4A54BE1DULL, 0x3792C145880A89F0ULL, 0x264B31275C06A2CAULL, 0xB6E3EAC286E99494ULL, 
            0x1F1E18DE12705BBCULL, 0x7E7D703D1FA3F867ULL, 0xB92D65FE1D7B5C07ULL, 0x2AE77086D5E5758EULL, 
            0x8A12A8ADD7F2975AULL, 0x75E365E8BD818B18ULL, 0x364CAF26A15F010DULL, 0x210BD5E8D7FF221EULL, 
            0xFB6F617861C5CC90ULL, 0x67A18275363927B9ULL, 0xC4B2C58299C6603CULL, 0x8E26F2866366433EULL, 
            0xA9A041797E3FCA30ULL, 0x428233A141700872ULL, 0x898801CA6D2E4468ULL, 0xF96D901DA0599FB8ULL, 
            0x4DB5CAAA457F83A7ULL, 0x80318EDF5961BFBDULL, 0xAD84F26167F48AA8ULL, 0x4AFE0DB88AD65871ULL
        },
        {
            0x3F685D99AFA1291BULL, 0xB3CCB2CFCF624469ULL, 0x7267A45523365A37ULL, 0x9844DEDC3BFAC66BULL, 
            0x9E346106B5842437ULL, 0x24DEF0435A3366F6ULL, 0x6C5D68D407C8A3FAULL, 0x0EA61AEC05C5ED65ULL, 
            0x852852149E68690AULL, 0xE7EB0DE337E4ABC2ULL, 0x2E7307931A4EF8EBULL, 0x02C4BE3128DD76B6ULL, 
            0xBAC1E3429F73FB6FULL, 0x1CC906F2FAA27C05ULL, 0x1EE81262984E01DAULL, 0x80657B015D733067ULL, 
            0x6001F8FD66155E54ULL, 0x57DE5439C9B349F9ULL, 0x24BB863C9B87499DULL, 0x43D814508FC3CC6DULL, 
            0xA67485352E60B803ULL, 0xD8A7AB73AB11DF36ULL, 0x80E78083F79D9615ULL, 0x3EA8123558C78FC1ULL, 
            0x6C13353D65AB8A07ULL, 0xD2FCB8409F905CDBULL, 0x214A98127E4120EDULL, 0xBEB8F1C13CA6A5B4ULL, 
            0x7AFBFC957AD7A65BULL, 0x0653A7B4FA0C4A48ULL, 0xCD27F9AFA3748777ULL, 0xA890FB9842A5CC35ULL
        }
    },
    {
        {
            0x8433AE1076D6894BULL, 0x7726C27759154F76ULL, 0x498E0EEB82F26136ULL, 0xC3BB7FE07B48D539ULL, 
            0xBD36BB49C82926DEULL, 0x430867D5A4E09C65ULL, 0x7B04FFA2091C50C6ULL, 0x9949871F2439F4F5ULL, 
            0xA4B86CF585E24A7BULL, 0xD31E13B828476457ULL, 0x0840A90B437834E3ULL, 0x74B8298B175AD15BULL, 
            0x30E164E8BDE467B4ULL, 0xEFBDEB39B5524F5EULL, 0xB340BBA45534A8E0ULL, 0xE152A10AB59AD323ULL, 
            0xEFC8CDBDD5014AC1ULL, 0x901FCB143AD1AA93ULL, 0x16270746E22438EBULL, 0x1DCF7C6DCC659E1AULL, 
            0x6B37F0BF363914C8ULL, 0x0C256AEE2B134812ULL, 0x878B571775000752ULL, 0x03058ED9784792DFULL, 
            0xD7E9F8432E7CC598ULL, 0x637ED4CF177B51B5ULL, 0xC84174201FE69E4AULL, 0x463C40C4391C169FULL, 
            0x68ED7A785ED68DBEULL, 0x7A97319E7DB076EAULL, 0x5888B903CD7E5C00ULL, 0xCC1E5EC3FFBA5E4BULL
        },
        {
            0x0D2F7A7BB21FB6C1ULL, 0xEA31C1ECF3D932FDULL, 0x4024C4CF725E6158ULL, 0x14272C9AF0FAC933ULL, 
            0xA00E9B00EDF06460ULL, 0x5F1309C40A18172BULL, 0xFCA1C263DAEBBDF4ULL, 0x1E405DDC48C6CF54ULL, 
            0x8355515E73B4A1D7ULL, 0xF2079AAD85AD7124ULL, 0xD36C786D65E6B913ULL, 0xB7926E190667CF4BULL, 
            0xD4333076E92EF607ULL, 0x4D4F94937E0D99FCULL, 0x23AF479923669BA0ULL, 0x0D8A771813CCE0A9ULL, 
            0x5ED8A7BD76DD84EAULL, 0x4CE14CD3ABEB2FFDULL, 0x85658D41EC055EA0ULL, 0xFF7058A3FAC96B26ULL, 
            0x22FAC6D7D26D5030ULL, 0xF387982A625A94E3ULL, 0x07ED5422CBE59A01ULL, 0xE204673B659C1989ULL, 
            0xFB127DF699E3DBDEULL, 0x095F1B757D744D25ULL, 0x51AA7C335E2D29EDULL, 0x4FF33B569138D527ULL, 
            0x82DA40E4C86F2A41ULL, 0xC46C4CA314FE8388ULL, 0xA26B5A2030217DDAULL, 0xC6718336DD28A804ULL
        },
        {
            0xBEAE4AB2A831F906ULL, 0x8DAB1E9145E475D9ULL, 0x52CABC6CF1898952ULL, 0x8B92E52DCCA38A0AULL, 
            0x0BCDB5DD27622F75ULL, 0xA641BDCEE8970123ULL, 0x9E3A1948511039C7ULL, 0x967E919BE2CF0CB8ULL, 
            0x787CAC142C49AF09ULL, 0x062B66F93480166BULL, 0x6F91B9EE5459C324ULL, 0x67577C113334A1BCULL, 
            0x1E3C8121BDB83E99ULL, 0x3CE558094E63D058ULL, 0x80A8979CDF5552CDULL, 0x541D8724FDEE9590ULL, 
            0xCB183FF836B2BFF8ULL, 0x4DF2A8EE23CA24E5ULL, 0x77F9C788AD3CF898ULL, 0xB1FA4B1D2F88D56AULL, 
            0x7288C024697A6CF5ULL, 0x33CE681967F0FD90ULL, 0xE87610F7ACECE02CULL, 0x3CFAC962E1BECCFDULL, 
            0xF99D51547C04F1F1ULL, 0x66B552A4A4C1AAB3ULL, 0x80B71BDCF4BD7E69ULL, 0x661F1FCE9AA0227EULL, 
            0x69CFC538511FE7F0ULL, 0x1C926B3C790F8C3FULL, 0x56CA41C1E113A4CDULL, 0x89E9FC85BFA97DB2ULL
        },
        {
            0xF83666738A394F21ULL, 0x419C0B7C50C3FA02ULL, 0xC7979F7ACF61A210ULL, 0xC38DE8BD96EEB21AULL, 
            0x1F33C41E48514787ULL, 0x58B7AA7D5865E10EULL, 0x5BA75BA70703AAA8ULL, 0xFD59E250ABCFF3C9ULL, 
            0xD1B8E21D53371C15ULL, 0x777B2F78B167B3C4ULL, 0x7912CBE4EF8840D0ULL, 0x145AE23EBD479C90ULL, 
            0x1155321D53AA4269ULL, 0x4583F21BE59229A2ULL, 0x05F1AACB161AFD39ULL, 0xB06EDB865AB0490FULL, 
            0x57FADB7134050C9EULL, 0xE09B115E24FD8F91ULL, 0xE60BADD930025A3FULL, 0x1564DAED1B836DE1ULL, 
            0x5B2AB6256F9545EDULL, 0x27FC86456331E80DULL, 0xAA0F440E6ACD7B69ULL, 0x1B858F7A533959D4ULL, 
            0x86A55AA927BFFCA6ULL, 0x2D8EA1BF2954B212ULL, 0x46F493B4D386C2DBULL, 0xA767E08B6B43FE52ULL, 
            0x150B4D2AA2256646ULL, 0x41CCFF8B7B59519BULL, 0xFA770D15EFA211C2ULL, 0xAF57863B03E1A640ULL
        },
        {
            0x5B8DA4D9D18B3803ULL, 0xCAE8B5B6EB07C7FCULL, 0xE1EC57D3FA292322ULL, 0xD9612EE8E462A5BBULL, 
            0xC1060A810DD47719ULL, 0x42441B611958B0C9ULL, 0x5837D0D572B94358ULL, 0x7CFA6CC9AC03F0F0ULL, 
            0x79745A0BE2F355DBULL, 0x10EBD3A403C940C1ULL, 0x2D97417D59C8A873ULL, 0x9277CD6DB121A9E4ULL, 
            0x477E84CE073ACAFBULL, 0x508AAB7F25150D28ULL, 0xFD749FB5BEBC366EULL, 0xAE6A9D7E9942599CULL, 
            0x1C8BD75ADD6F5C3CULL, 0xB78718EB8BB9F44EULL, 0xFCC5A16FB100A7CAULL, 0x627D822B4FA1DE70ULL, 
            0xCEFBC1476F0C4FA2ULL, 0xB5288984E214D8EFULL, 0xCCFF03959BE01453ULL, 0xDE7B7956A01A5B82ULL, 
            0xF25D99EBAD4EED86ULL, 0xEE1CF1955F157027ULL, 0x412485EB9250CBA1ULL, 0x902BDF00858C16A2ULL, 
            0xD7F0F67A92859E52ULL, 0x488AF58111C92424ULL, 0x858473E1CF6665D0ULL, 0x9FC062ACA19D3AF0ULL
        },
        {
            0x5B433A8002CDB8C4ULL, 0x628D3D087647B37FULL, 0x08EF47988C527588ULL, 0x41DBC8D866DD08AAULL, 
            0xEAA68CF191A680E9ULL, 0x6237807143CD056DULL, 0xB5223A0E0C141EC5ULL, 0xD72268BDB51C873FULL, 
            0x0907C64D647EFCE7ULL, 0x4D4D0AF4A0224B11ULL, 0x2A9DD0AE67DEA9CBULL, 0x4BE2BD90BA41CC2FULL, 
            0x5BC75F494909E5E9ULL, 0xEAFD1F1463C5BF62ULL, 0x3F8A8427B802E989ULL, 0xB2F4EE090D6DA61FULL, 
            0xD3F3688DE388F538ULL, 0x2F669D1A6B936A1DULL, 0x03BC368318AB5763ULL, 0xAB8C938E4DBFE6A4ULL, 
            0x6AA43C2B03726F6BULL, 0xF4E878850B0F1345ULL, 0x32B0D51918B3A177ULL, 0xAEC66F7C45005829ULL, 
            0xF4F3903A8F415408ULL, 0x8AACDF241FD8A8EAULL, 0x1212700A8D0C46A9ULL, 0xFF7982DB9DD7B1D3ULL, 
            0xE62510FE5EF8531DULL, 0xB9B091FE39AEF0F5ULL, 0x340810B22E7FC04EULL, 0x9483DB59A7ED9FEDULL
        }
    },
    {
        {
            0x76427904A06FBE5FULL, 0x367DCA605710D434ULL, 0xDB8115160696FAE0ULL, 0xC658A480D35790BBULL, 
            0x11AA43C0B54EA7C2ULL, 0x0B895F42A4FBF856ULL, 0x491744AE78E1EE53ULL, 0xB6074B0FC8AFF194ULL, 
            0xD8081D1E1065F0F2ULL, 0x9CF2E4F60198F093ULL, 0x98FF02EFA1941AA6ULL, 0x11F3D516E2A81699ULL, 
            0xAAFCC578237AEE79ULL, 0x6D67E646E86B31FFULL, 0x6A61D8B194055791ULL, 0x72AB145653607025ULL, 
            0xE4752B41F78FDFAFULL, 0x830C0E04E40BF4FFULL, 0x086BE70584C07CC5ULL, 0x25EC6BC3D96B8C4EULL, 
            0x929FF26E7EA602A6ULL, 0x2D40D0E36F4EC573ULL, 0xD8D1F7BC549DC275ULL, 0x18C28A4E30ED3444ULL, 
            0x92814833325D6BE3ULL, 0x838B6E8017A4B1ECULL, 0x13D56837EBB54E1FULL, 0x73B351A6E13270E4ULL, 
            0x5CA4ECBB6F7CE6EFULL, 0x35CDA5D30B408D53ULL, 0x5434A1EF08135D6DULL, 0x021C0C57F9D24AADULL
        },
        {
            0xAA6A318700B78030ULL, 0xA4B6F42C2F3F1EDEULL, 0xFFC9942F1F75F021ULL, 0xF36856E044C57F18ULL, 
            0x64C3BE44DCA12EF9ULL, 0x7A158037E330B63AULL, 0xC31F8C7C27C78539ULL, 0x0406975793067F2CULL, 
            0x039D6E86DDA67EF0ULL, 0xAFE6C0843D5946C5ULL, 0x9DF72191D44EA121ULL, 0xECDEB709D8C0FFC5ULL, 
            0x1888DEB44C93FA03ULL, 0xE8F029AD7CCF4DC1ULL, 0x15A168B926F8EA24ULL, 0x6C9FE8E50A449081ULL, 
            0x29C4B9B17A38F6FAULL, 0x950C55EC6A2FB9C9ULL, 0x9CC7AD6E5E672695ULL, 0xD72281F37AE373D8ULL, 
            0x63C06E249D32ECBEULL, 0x15C52F0F7B84B426ULL, 0x1189B12B4965AA33ULL, 0x041C481F91454219ULL, 
            0x912E5A552827187EULL, 0x0AB10C833AB74D25ULL, 0xCDBA74BC1CE8023EULL, 0xA9E4C178B6E73CA9ULL, 
            0xA9665FE05953BD01ULL, 0x36B71A2122DDF64BULL, 0xFB84A6D9F1E78FD4ULL, 0x54BE5A3755642A9CULL
        },
        {
            0x2E5997E6D21C5C0DULL, 0x0DCC8692F603F146ULL, 0x6831909BCDDB5AFFULL, 0x542CED861FA6BC8AULL, 
            0x63E86BD466153109ULL, 0x6406459DCD799D15ULL, 0x48E92B7AA18D152CULL, 0xB780B305DF1EF929ULL, 
            0xE8FF1C0B0BB16470ULL, 0x922A469F832D8A42ULL, 0x35BD71CD4E39777FULL, 0x53ABC0DC87A0D091ULL, 
            0x09DD5311CE7323FAULL, 0xFEEB39F2C6F2B69EULL, 0x84F74920B47AF852ULL, 0x5C4EB453C330FBE0ULL, 
            0x27D383224E9BAD22ULL, 0x32CF04DF46DCE110ULL, 0xCFB4BCAC81984027ULL, 0x2924717D6E40CC31ULL, 
            0xF32988F0AF200538ULL, 0xBE26A7C43CF0788DULL, 0xE77EF73A87C705A4ULL, 0x12A96102F6D83E45ULL, 
            0x3A5E85BB86C21C52ULL, 0x432E4C4945FC8BB1ULL, 0x58AA7B8F654C75F4ULL, 0xCDE95E8CDCF001C4ULL, 
            0x3B0631496EDE1312ULL, 0x101DB4FABA91A0ABULL, 0x54118926EB88F260ULL, 0xD5F5985A6D48FE36ULL
        },
        {
            0x71F2D2056195C180ULL, 0x2AC77115A5ADD1A7ULL, 0x669047DA607E8D66ULL, 0xFBE3D78BA47B3769ULL, 
            0x3ACDACFED22F73AEULL, 0x7029AD777AB549FEULL, 0xE3E402CBAF836A06ULL, 0xC24D8798EC3437AAULL, 
            0x7CA9318C4B4A2243ULL, 0xC283257F75429CE4ULL, 0xD3279C127725836FULL, 0x911F114EE9ECF0CEULL, 
            0x7BA767EDD2134DA8ULL, 0xFBF1E061C251E59BULL, 0x2C1C70781EB74110ULL, 0x9520E6AAA9C68181ULL, 
            0x7031FF86EE4BBA43ULL, 0xC9B899D2263FE72EULL, 0xB5B4CFD957FC22BAULL, 0xBFC6A1BBD4FBAD39ULL, 
            0x24E6C2659376D68CULL, 0xC1A1DF3CC1F394F8ULL, 0xD08137DF6A37D735ULL, 0x729235D5CF0361C6ULL, 
            0x0D8BB3771EE96AD1ULL, 0x4873036DB0F6A35CULL, 0xBC559500C026CCBBULL, 0xBC7C63DAB755DA83ULL, 
            0x26E346AA86F7D5E2ULL, 0x358DE948CAF6990DULL, 0x791F0189FBA426BDULL, 0x825B385AFC4E91E6ULL
        },
        {
            0x458B6ACFF052F6D0ULL, 0x4BCBC5FFBCD740D2ULL, 0x14B8C663D60662DEULL, 0xD1BF91B8CCADB1E0ULL, 
            0x0ADFD6CAFA01147FULL, 0xE926AF0BCB1092DCULL, 0x5DF6B69C6CDFF6E9ULL, 0x8E7443B3C8D43FC0ULL, 
            0x406FE48ACFE254E4ULL, 0xA95C25787258166BULL, 0x19C46B9C71C22240ULL, 0x5F886B0D8C3EEB4BULL, 
            0x3BB72283462F86E0ULL, 0x778CBF900AAF63A2ULL, 0xB3D3C8C34E036882ULL, 0xAE1BBB09503447ECULL, 
            0x400EABD534631656ULL, 0xFB8F92D8ACC6B9FFULL, 0x88FB4FCC6879EC1BULL, 0xC2B18A9CB7FBE53EULL, 
            0x119E8D20CD6696F4ULL, 0xC4C75D191B963574ULL, 0x558467BC6BD2C356ULL, 0x82E32D8FD25453BEULL, 
            0xDD7111BE4FE86A14ULL, 0xB406DDFFF68E8DB9ULL, 0x75ED86A7DE4E878BULL, 0x814D26CC19260A2FULL, 
            0x5D783B34DDC82D9CULL, 0xB83C0349A04175A9ULL, 0x6F2FDEC1F903273AULL, 0xD1C824952D0695E9ULL
        },
        {
            0x6F78B415418A3AABULL, 0x4C56480EE38CF57EULL, 0x91564A78A77FB4DFULL, 0x180D85669FEA9355ULL, 
            0xD378FB50925CA5F5ULL, 0xBB61EAAB608D721AULL, 0xD70FDE1AAE1F9993ULL, 0xBFEBEE79C35E3A9BULL, 
            0xA11ACEF9DD8AB7CBULL, 0x2565DC8820593EC6ULL, 0x6173AFF265687FD3ULL, 0xA98410647ED72C8FULL, 
            0xEE230CBC5C575839ULL, 0xAC2C589BECE9EA77ULL, 0xE215E3DD4CF8B415ULL, 0x413A27241199BC0EULL, 
            0x2774152D2CD989D3ULL, 0x5AF375FA63E4A7FDULL, 0xAD9BFCFC76DC3B92ULL, 0x4F953290F26809AEULL, 
            0xF4C899C005E9A6A2ULL, 0xAD76857A72EA76CBULL, 0x7A3BE444E26FB26DULL, 0x12299578F40220B4ULL, 
            0x13BC2AA843BEA55FULL, 0x0FD307E5EDB1C1CCULL, 0xA5708A6D558E202FULL, 0x74C27E6EF1566633ULL, 
            0xDBC2AF82D360B942ULL, 0xC2F3AAC94E0F2BEDULL, 0xC4042A8B64FEDC4BULL, 0x1590B62BEF119F94ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseHConstants = {
    0xACC1524BBC412320ULL,
    0x36F30521D6D43639ULL,
    0x36B56ADEBD7BCB12ULL,
    0xACC1524BBC412320ULL,
    0x36F30521D6D43639ULL,
    0x36B56ADEBD7BCB12ULL,
    0xD03B6A2EF59FEAF6ULL,
    0xF9B94AE2DDFC8CA0ULL,
    0x79,
    0x5B,
    0xFC,
    0xEE,
    0x2E,
    0x6D,
    0xA1,
    0xFB
};

