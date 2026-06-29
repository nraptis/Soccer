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
    std::uint64_t aPrevious = 0xA1052D9D867F8A58ULL; std::uint64_t aIngress = 0xCD312D236180A91EULL; std::uint64_t aCarry = 0x8332D5CEA8B18209ULL;

    std::uint64_t aWandererA = 0xCF1381ECBC3653BDULL; std::uint64_t aWandererB = 0xBEA96D093C1F182FULL; std::uint64_t aWandererC = 0xC25B3509FA65FD90ULL; std::uint64_t aWandererD = 0xD5C462CD90D90B73ULL;
    std::uint64_t aWandererE = 0xFF30D0FC8D58C1C2ULL; std::uint64_t aWandererF = 0xB8DCF647D5F7FA34ULL; std::uint64_t aWandererG = 0xC0A4B0CE520C79AAULL; std::uint64_t aWandererH = 0xF5B193F5B828C0FFULL;
    std::uint64_t aWandererI = 0xDC8C526DE9F5B66CULL; std::uint64_t aWandererJ = 0xCE5790594028D1FEULL; std::uint64_t aWandererK = 0xD46C58253DC5A9F0ULL;

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
        aPrevious = 12770059729198368369U;
        aCarry = 16628955891222878531U;
        aWandererA = 10426111928247150714U;
        aWandererB = 15577717650270453772U;
        aWandererC = 18251409256756291665U;
        aWandererD = 17158993351737703611U;
        aWandererE = 14006882832767470464U;
        aWandererF = 12018985466117822368U;
        aWandererG = 11364870225206687582U;
        aWandererH = 17443743738755345345U;
        aWandererI = 10455363119646784611U;
        aWandererJ = 15976425283883874726U;
        aWandererK = 13844841620440514024U;
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
    std::uint64_t aPrevious = 0xF95082B7CE1FC2B7ULL; std::uint64_t aIngress = 0xFA718D67075CBCF4ULL; std::uint64_t aCarry = 0xB8E808A09AACB773ULL;

    std::uint64_t aWandererA = 0xA858DEDFD9972D1AULL; std::uint64_t aWandererB = 0xE1BEF27620D94FCDULL; std::uint64_t aWandererC = 0xBFD5012108634804ULL; std::uint64_t aWandererD = 0xE640E67DD492F711ULL;
    std::uint64_t aWandererE = 0xD572CB805E9E9F44ULL; std::uint64_t aWandererF = 0xEA4E19E2E3171EE9ULL; std::uint64_t aWandererG = 0xD5F0B38378975F02ULL; std::uint64_t aWandererH = 0xC76E7FC0D8135EF0ULL;
    std::uint64_t aWandererI = 0x98D1D00BE0DADF27ULL; std::uint64_t aWandererJ = 0x8D7E3DBAF6E22CD0ULL; std::uint64_t aWandererK = 0xCE6554B5038D5081ULL;

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
        aPrevious = 12837403062794422705U;
        aCarry = 9691925166121126973U;
        aWandererA = 13912171358616309015U;
        aWandererB = 13588829871664071080U;
        aWandererC = 15423212703160074603U;
        aWandererD = 17418853494588142847U;
        aWandererE = 17801015517599467719U;
        aWandererF = 13458168869960659439U;
        aWandererG = 13128046367623268683U;
        aWandererH = 11769798140057223116U;
        aWandererI = 12462020435832100817U;
        aWandererJ = 10400852332061196797U;
        aWandererK = 18308731999995233432U;
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
    std::uint64_t aPrevious = 0x862BC4AA8CB3ACA4ULL;
    std::uint64_t aIngress = 0xA3F69095429BAA41ULL;
    std::uint64_t aCarry = 0xAF66E84DC45F0AE4ULL;

    std::uint64_t aWandererA = 0x8FD2A6E544115812ULL;
    std::uint64_t aWandererB = 0xE287E7B5942721ACULL;
    std::uint64_t aWandererC = 0xD26CCDA508360EDEULL;
    std::uint64_t aWandererD = 0x8CF1E3F28C0A500BULL;
    std::uint64_t aWandererE = 0xD2892C6641A0F527ULL;
    std::uint64_t aWandererF = 0xFB6A49558A65DB3CULL;
    std::uint64_t aWandererG = 0xB9D46DF4EA17FDFFULL;
    std::uint64_t aWandererH = 0xEDBB2842AEA578ACULL;
    std::uint64_t aWandererI = 0xC65C17A0111DF736ULL;
    std::uint64_t aWandererJ = 0xB5D2DC0A97689FF7ULL;
    std::uint64_t aWandererK = 0xB72B77AECC546627ULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
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
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB, 1);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD, 3);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA, 4);
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB, 5);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC, 6);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD, 7);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
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
    std::uint64_t aPrevious = 0xB7492AE9069A4966ULL; std::uint64_t aIngress = 0xC28A1D84857B8CF7ULL; std::uint64_t aCarry = 0x9B87C14BD97E3308ULL;

    std::uint64_t aWandererA = 0xEA8ECF84F93F203CULL; std::uint64_t aWandererB = 0xFC8D035CB218A0FAULL; std::uint64_t aWandererC = 0xE9C919F02B488F4DULL; std::uint64_t aWandererD = 0xF0A5B4E38E96BA40ULL;
    std::uint64_t aWandererE = 0xF770779B007CD6B0ULL; std::uint64_t aWandererF = 0x87B83CEB778CB212ULL; std::uint64_t aWandererG = 0xFCF97C1B69ABC52CULL; std::uint64_t aWandererH = 0x831473E2BC82994BULL;
    std::uint64_t aWandererI = 0xD9E3FA902AF6EDD6ULL; std::uint64_t aWandererJ = 0xB3B6F2AB52947E6DULL; std::uint64_t aWandererK = 0xBC66C2534A4A28E0ULL;

    // [seed]
    {
        aPrevious = 12953976627814732601U;
        aCarry = 15984303897755015467U;
        aWandererA = 17886726634581614030U;
        aWandererB = 15728472009875915679U;
        aWandererC = 14875336248873550384U;
        aWandererD = 17536308598864088594U;
        aWandererE = 9683586286478278790U;
        aWandererF = 12697360408317384079U;
        aWandererG = 17913544613889938248U;
        aWandererH = 18122147278352343515U;
        aWandererI = 17527516661713955530U;
        aWandererJ = 16250237741005484840U;
        aWandererK = 15346986298754713306U;
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
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 3, 1 with offsets 477U, 4439U, 6714U, 4390U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 477U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4439U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6714U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4390U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 2, 3 with offsets 6816U, 2313U, 5234U, 4881U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6816U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2313U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5234U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4881U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 0, 0 with offsets 3837U, 534U, 1206U, 4393U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3837U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 534U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1206U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4393U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 2 with offsets 2994U, 1801U, 3836U, 156U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2994U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1801U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3836U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 156U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 2, 3 with offsets 2041U, 1654U, 259U, 351U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2041U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1654U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 259U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 351U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 2, 3, 0 with offsets 428U, 611U, 1254U, 1683U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 428U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1254U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1683U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 2, 0, 3 with offsets 1825U, 1126U, 754U, 474U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1126U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 754U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 474U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 0, 1, 3 with offsets 1049U, 704U, 42U, 1568U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1049U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 704U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 42U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1568U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1952U, 517U, 742U, 1097U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1952U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 517U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 742U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1097U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 2, 3 with offsets 4886U, 5608U, 1514U, 2204U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4886U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5608U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1514U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2204U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 1 with offsets 7190U, 293U, 1375U, 628U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7190U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 293U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1375U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 628U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 1, 2 with offsets 1182U, 4550U, 2660U, 3774U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1182U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4550U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2660U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3774U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 3, 0 with offsets 7847U, 2691U, 2831U, 3374U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7847U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2691U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2831U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3374U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 18U, 4975U, 3282U, 4997U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 18U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4975U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 3282U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4997U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 2042U, 987U, 448U, 380U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 2042U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 987U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 448U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 380U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1797U, 165U, 948U, 1990U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1797U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 165U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1990U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 568U, 1483U, 1297U, 594U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 568U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1483U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1297U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 594U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 532U, 261U, 1103U, 1842U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 532U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 261U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1103U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1842U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 0, 2 [0..<W_KEY]
        // offsets: 305U, 1345U, 714U, 532U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 305U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1345U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 714U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 532U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseASalts = {
    {
        {
            0x6C198DF1DE9E20B1ULL, 0x2FDC36AE1FAAF389ULL, 0xC6DA1B98F7227546ULL, 0xB29CF00603D8972FULL, 
            0x13DD3B8051DA8268ULL, 0xC87D511E0ADFAAEDULL, 0xAD7F89BD868AC639ULL, 0x41CF8CE3460AA40AULL, 
            0x2752C08076E7716FULL, 0x90E57450E828BE22ULL, 0x128D725F5CF71EB5ULL, 0x3D31519A2B1DDB3FULL, 
            0x52C16D5F74E9845CULL, 0x5267D2C39B8FAE54ULL, 0x50F1445BE20DB69DULL, 0xD3CBF200D9E8490FULL, 
            0xE6D23206859E595CULL, 0xC541D7D094B800F3ULL, 0xAD184664F79DA8ADULL, 0xB4FA6920027792FDULL, 
            0x670CCA56DA3AA578ULL, 0xBAD4E473FBA4A70EULL, 0x540B8EB6635C74E4ULL, 0x7DDDAC5770304FFFULL, 
            0xCFCDD55621A5FD60ULL, 0x732E9D6A49FFE6F2ULL, 0x82951C962E66FAADULL, 0x173A57748466A07DULL, 
            0x0A69D100F5F728CDULL, 0x5ABB57B4EEE8398FULL, 0xAF43031BF18EC679ULL, 0x7369888CA327F408ULL
        },
        {
            0xF3DDCA9A8A68E1C9ULL, 0xC0C67F4E16F6EA4FULL, 0x7E7411EDE72C093DULL, 0xE1DD5BB6497503F3ULL, 
            0x02CA9E9B2A96D3BDULL, 0x832821ED8E84A465ULL, 0x8A5BA9DA44E3EACBULL, 0x5C61F2DC3F43022AULL, 
            0x0058FB45169109CDULL, 0x638787CEAC0A4FB0ULL, 0x9FD1D8A4529235B4ULL, 0xC7DC047F83AE9738ULL, 
            0x4363F405E983A686ULL, 0xEF7593210EBDC47BULL, 0x9708D4F871AA0040ULL, 0x01D88B2617AD6E40ULL, 
            0xBCF5CDDC06FC9089ULL, 0x611C4920D55D2D19ULL, 0x054D8002BB147B53ULL, 0x66EAE65503758C7CULL, 
            0xBFB86397640CFC57ULL, 0x78F0E3A1B194A4CDULL, 0xD6EAE4F356B6C18BULL, 0x40F8D4F78274DD4BULL, 
            0x9BD91418EF12F89BULL, 0x805C783252EE5FA8ULL, 0x0DAEA5A4EACC94C1ULL, 0xC2EC5ABCCD2F4E9CULL, 
            0x6EC8E78E12BADC3BULL, 0xE9E39444DD673B8DULL, 0x038B00115900F5ACULL, 0x3325582BAB212E0CULL
        },
        {
            0x261E7CC55784495EULL, 0x676F8A1D20D1A4EDULL, 0xF7A3B245BFD844B3ULL, 0xFC47380A7B83D937ULL, 
            0x92647B9CD5EF5919ULL, 0xD77A52ABED3DA35FULL, 0x6FD5D2BA6E30BBA2ULL, 0x64899BD89CBC9C89ULL, 
            0x94BE8CE062DFBF96ULL, 0xA730A65F58006359ULL, 0x3958468B3E6FEC65ULL, 0x9C2447BCA80C78D1ULL, 
            0xB94145B7BDE0E5E6ULL, 0x4AE715869491A968ULL, 0x18B649718A68BDDAULL, 0x647197785DE23A71ULL, 
            0xE299B73C0AE739F5ULL, 0xC05855FF47EE1691ULL, 0xA2F2DC8E3F3B9294ULL, 0x8582362127B16B7EULL, 
            0x5BE80F9509E2145AULL, 0x90200C90EFEC07EDULL, 0x84FF165A0E664514ULL, 0x0BDC3C0EF3C87181ULL, 
            0xEE4ECC46D060646EULL, 0xBD5FD5713A24A004ULL, 0xBF720D9F04064719ULL, 0x54408F0ECB2511CBULL, 
            0x55C4B52665B4C3A7ULL, 0x52092ADD61C15D77ULL, 0x7F72A7A7F7D4DA53ULL, 0x2C88D4025CBEF53EULL
        },
        {
            0xB8A1AA182BF3C575ULL, 0xF7731B055B981C6BULL, 0x6E78FAB606D8FB97ULL, 0x0E4FAD73E8C41F22ULL, 
            0x6B56A23A18CEEE2CULL, 0xE04D782759714294ULL, 0xC5A16628495976FFULL, 0xDB8A84B63E48F98BULL, 
            0x7ED6ACA9748A561EULL, 0xE4BCBEA091DAA3C9ULL, 0x395316EBDDACC3E7ULL, 0x48F65E41CD62DEC1ULL, 
            0x4B3122941422620AULL, 0xA7CA0953D3CEAE89ULL, 0x0B512C56E2FB2A33ULL, 0x2E902AB5F6E128FAULL, 
            0xFFDC8FD8437C91E1ULL, 0x168FE7E71766E6C4ULL, 0x37CA456C3B96E00AULL, 0x5A5EDB9482D8A956ULL, 
            0x68B3A1584C0DBC30ULL, 0x4D94B0D15AD1857EULL, 0x3DFB74FB81A021F4ULL, 0x2408BFF2337DD681ULL, 
            0x8CA1E0B4F9BD958DULL, 0x5A6CD893C7F51D4DULL, 0x2C64FB282ED97C80ULL, 0x9F64C2FB1530A171ULL, 
            0x7C2D83E927398B21ULL, 0x7349F6E3C4D62947ULL, 0xB7ED1E3666CA344DULL, 0x738E6DD1D27E60C2ULL
        },
        {
            0x833F03A253C2DE2BULL, 0x6BE264938E36CEFCULL, 0x8690FF3E8F590FBAULL, 0xDD4E53A4FF725017ULL, 
            0x5F62B676B9283432ULL, 0x0635C326C3D7AD76ULL, 0x9EF7338680385612ULL, 0x29D31243A3007993ULL, 
            0xD64397E3A55ABEB3ULL, 0xA4E6AABBAE24945CULL, 0x3314F981CDDE76BFULL, 0x7B57C5EB02F48E40ULL, 
            0xDFBC62CC82119867ULL, 0x33E7FDC7C6415AB1ULL, 0xEDF1DBBE654913AAULL, 0x97F010771DF8700AULL, 
            0xD9B5BE9AB0C75225ULL, 0x78AE7E1581190DA1ULL, 0xABE8B3A37513C9D8ULL, 0xAF4AC0CFA514D118ULL, 
            0xFD75D63CB6719524ULL, 0x7E2556A311E2F0B2ULL, 0xBABC8B1B432D9A8EULL, 0xEE16B8F493DBCB48ULL, 
            0x293B30BD402DC39BULL, 0x8683FDEA2026C323ULL, 0xA9F9518A76169328ULL, 0x7D51DCAB1CB78C59ULL, 
            0x47417D3A1BE8D8DBULL, 0x72AF3C64AD8AD13EULL, 0x04F1BF5A4748EE29ULL, 0xB21CB9F9BC128128ULL
        },
        {
            0x2B653246B1E5E8B7ULL, 0x227B77288B1B9FDEULL, 0x9791AD94582D227EULL, 0x2C5380FEA225AB7AULL, 
            0xB70C98D084DF9205ULL, 0xB1E79F736A8A14D9ULL, 0x7C20058750ABB46FULL, 0x42058D6992E39A03ULL, 
            0x87E2E981D35BE90EULL, 0xA3D39BC83FAE1149ULL, 0x734E5F52D8E8E7A9ULL, 0xB8F3D5821D72E583ULL, 
            0xE2BF7D821CEB4D4DULL, 0x47F93A5E43B28E62ULL, 0x0AA4B0F0E0D9592DULL, 0x4DE95373182FC14CULL, 
            0x4AD08AB0A664ADA6ULL, 0x5957CDDA7FDD97C7ULL, 0x1DA1B60FDA6EA4C4ULL, 0xAE4D49052A58165DULL, 
            0x32C13E808018FD0AULL, 0x98039A51EFE53B36ULL, 0xF89243934A3AA335ULL, 0x9E5C162A84825902ULL, 
            0x472B4B81893B7FB5ULL, 0x5EFAA2EC4CC9813EULL, 0x7858250478D1F667ULL, 0xBE9F823DC250699BULL, 
            0x9CC7573790A61346ULL, 0x950E895CEBF259BDULL, 0x5DF68246EC1A9199ULL, 0x915793BCC84961DBULL
        }
    },
    {
        {
            0xFA8AF43CA5BED22DULL, 0x7CCFBE0D101E2281ULL, 0x49A8C7CA3FDD835AULL, 0x414F3F2645142D03ULL, 
            0x3BB5288F6875CC5BULL, 0xF6F160A72E4F5313ULL, 0x13A91DDA5B440AD5ULL, 0x4DDCC2C0A088999BULL, 
            0x86597555076169DEULL, 0x4667A380C79330C0ULL, 0xBD6D43E9E1B302DDULL, 0x76F190DE4B54B374ULL, 
            0xBEA775439656F33DULL, 0xADA5A5A3ABC501DCULL, 0xFDC8D55B8C3B725DULL, 0xEDE4C84317EC06E2ULL, 
            0xB7A06CAE73B718FEULL, 0xEC154CAE415F29FFULL, 0x54FF23D904951D38ULL, 0x4EBB74568642DC11ULL, 
            0x982C02426B904FFEULL, 0x32D912E34C8E39DCULL, 0x5C34E015003BE5C1ULL, 0x022C080D6C3B323EULL, 
            0x07771DA3BB03E394ULL, 0xEFCDAEF41DA38C9DULL, 0xD7C070B288CF01F7ULL, 0xF1D658B9A8F867B0ULL, 
            0x754EC6B0BCDE055CULL, 0xCC2B8759FC30E157ULL, 0xD5B5462CABD8AB79ULL, 0xDDEF370EF89D89C3ULL
        },
        {
            0xDF94379FCDEC6FD1ULL, 0x38A87B76C683EAB3ULL, 0x8267A27CF98ECC72ULL, 0x04EC7FC90F6F4BBAULL, 
            0xC3EF8F615B3E7C0EULL, 0x6FF829FC40D33BC0ULL, 0x3C1104439ECD68E3ULL, 0x58E90537EC2D83D9ULL, 
            0xA332552DDFC8799BULL, 0xD82EA4A3CC0894F9ULL, 0x8C4596B7D88883D3ULL, 0x12DA47A8D80E2A64ULL, 
            0x2C3101DA71799CCCULL, 0x365E4DC59C5588EEULL, 0x33B5A36F1ADF39F1ULL, 0x837CBF523BDE340EULL, 
            0xCBFAF8EEDB6BEF0CULL, 0x8282B7E9C5CF1F6DULL, 0x0D35BED9CC9DF1C0ULL, 0x30EAA9833FEA0D00ULL, 
            0x21D636348B64C5DBULL, 0x2C6D6B610AC60CF9ULL, 0xE173DD8A317BE7A0ULL, 0x1153BAEF3D0B1DB0ULL, 
            0xA5560CDC6C6741FDULL, 0xBA708F89B0E4DE7DULL, 0xEB5208AFBF8A12F2ULL, 0xC5CE0DBFC4D4B33AULL, 
            0x559FFA62F576521AULL, 0x0379E103CCCAFA58ULL, 0xAA6591E1271C1C29ULL, 0x64C6F89F60D69D99ULL
        },
        {
            0xCFE04A092F99CEA4ULL, 0xACD9D339DCF49FD0ULL, 0x89A294CFB1AB1511ULL, 0x7DD5A947F15EE31EULL, 
            0xAA2E0785C9424222ULL, 0x48BB2C286506D2C1ULL, 0x2D6FC2EAD2285296ULL, 0x1D8A91B63E04DE62ULL, 
            0x4D97C35F3D266E51ULL, 0xEBB84CE3CE6BC61EULL, 0x853CE3F602D4DF64ULL, 0x7AB8639299DED61FULL, 
            0x4569CC261772E060ULL, 0x22339D9A3B6717E0ULL, 0xD750EF46356CD855ULL, 0xDC7A19762D74C03BULL, 
            0xB46C1C67554F9807ULL, 0xA761A18E19C2E1E5ULL, 0x8AF0B3F923EE2ADDULL, 0x340B78ECE2659E51ULL, 
            0x6A0E2989ABB94462ULL, 0x053ED49BA135B878ULL, 0x156D32BB66FCE6D9ULL, 0x864AF1FDEA339D2DULL, 
            0xAA0EBBA2BD1188EAULL, 0x88782506FFDC79B9ULL, 0xA914D79975D8463BULL, 0xC1B46147A3F46B32ULL, 
            0x634E313851C39AA8ULL, 0x4638CB94EFC92314ULL, 0x3336713B00EF2768ULL, 0x5C20125C5742FB18ULL
        },
        {
            0x4B66C89F8505592BULL, 0x6E133A45F926044EULL, 0x0A117A8A750E45E7ULL, 0x9C07EB324167F125ULL, 
            0x7D01CF4FE7A7BD52ULL, 0x40C6B3A9EC30115DULL, 0xF3B59C7659E618DDULL, 0x9E648CFFB0293FA3ULL, 
            0x43DB69250A1E7897ULL, 0x2FBDC89CFC77BEDEULL, 0x7C2E067BE44C4110ULL, 0x36E708154D11D424ULL, 
            0x236CFD215B8AD097ULL, 0xE0A026EA75DC04B5ULL, 0x023E23857B9E5D5DULL, 0xF25BA020550BC067ULL, 
            0xAFBFB8B1CC454A0FULL, 0xC1DD294AB83E052BULL, 0x79FB574CABFB81CAULL, 0xAD3D7B7CDA9AE490ULL, 
            0x025B31066EFD3AD4ULL, 0x7DAC34179FCD9725ULL, 0xBA9379A59EA4B2BCULL, 0x7A77D948238E1B14ULL, 
            0x3C7041033C487936ULL, 0x87C7DBDD98FFBF27ULL, 0xA0B7923632FFE827ULL, 0x3264FB5FC92E892DULL, 
            0xC3C918FD5CE04E7CULL, 0x872ABA7C4FDB9357ULL, 0xF8781E6E5CAAC2BDULL, 0x068207FC7E3AC19CULL
        },
        {
            0xBAC991AB4FF41862ULL, 0x8C8B3B64D9E910E4ULL, 0x742942BE71061729ULL, 0xC79D143BDF3ADFA2ULL, 
            0xB113042A291F2C7BULL, 0xDBE0DDCD41A341A4ULL, 0x9EE83B5DED3A34FEULL, 0xC864C8C52459D06FULL, 
            0x9925E443D8E2DAF9ULL, 0x87B30A75F0374BD4ULL, 0x55DD3C6CAD7D42C0ULL, 0x8E42242E7399A715ULL, 
            0x2F7A559EFD482E52ULL, 0x9ACAE09C18B46212ULL, 0xE0F3F268187E7E34ULL, 0xA324B160B7E61F36ULL, 
            0x141E83559A514804ULL, 0x9B904F6E0E2A5B0AULL, 0x9B8327F0887511C1ULL, 0xDB091631A1D8A1B8ULL, 
            0x96F1529F77CBBD19ULL, 0x74656C6FFDDBBCAEULL, 0x03BA22E8C0376398ULL, 0x0262BF15231E8268ULL, 
            0xACBE2317DDAF7B82ULL, 0x6863E89C026088B1ULL, 0x41D6FDBC44CE24B1ULL, 0x4444A768CA148EB6ULL, 
            0xC758B7EAFA6A8535ULL, 0xC6E5065AB2E0FF2DULL, 0x6138F5A298F2E5DBULL, 0x5AEF1AE96D205805ULL
        },
        {
            0xA9BF2FA6ACAC7FB1ULL, 0xCF2D1A3DACEDE878ULL, 0x1B4798BE44CBC79AULL, 0x4CD59C5085F3B856ULL, 
            0x8CFF01453E8C7804ULL, 0x3D6CBB029E43EC58ULL, 0x5CB958BCAE9E44FDULL, 0xA398EE2B318F5C3EULL, 
            0x4F6B8535F84A94D1ULL, 0x7CDD3FE1C850D91DULL, 0xFA6FA67F94E81E4EULL, 0x1DAA0D52C4C09AA3ULL, 
            0x68C71CE78E300D32ULL, 0xC3767E48EC675716ULL, 0x2288F2BB3AD6B88EULL, 0x3F5DA72172AA27FBULL, 
            0x195791D68A49957CULL, 0x90C7AF7DF0CE12CCULL, 0x23B4BF1EDCE33AACULL, 0x19044536F9153F7FULL, 
            0xF3DE20CB40350FD4ULL, 0x954671BDF298C22FULL, 0x800F3621AB6E1F51ULL, 0x5FFC9DB01FB389DDULL, 
            0x44987521DF987CC1ULL, 0x1CF10FDACD82049BULL, 0x8EA4CAA22DAB7707ULL, 0xA6AA63E4EE04049EULL, 
            0x3E3CD4FA01CCE82BULL, 0x85410460DD9DCB33ULL, 0x4E49EC156587744CULL, 0xC2184F88C2E71612ULL
        }
    },
    {
        {
            0xA766B7A2F47F11AFULL, 0x42F76228D91142A4ULL, 0xBBFAA0904DA1F450ULL, 0x3BB9F6FC5042CDE1ULL, 
            0xBDAE62D7A14DA560ULL, 0xEEE6813ADCBEE545ULL, 0x320F7930B20A3880ULL, 0x00D43BCC81DA31BCULL, 
            0x31A8F65D5B253D9FULL, 0x8897EA1A247D468DULL, 0xB9556131B7DA0C7BULL, 0xF35E38071941ADFCULL, 
            0x165B79BDA9224AFEULL, 0x9242B2D79FA75A8AULL, 0xF215D94B83D92DCFULL, 0x7DC5D73042A13A1AULL, 
            0x235FB4A0A50635A5ULL, 0x6DDEE7C4853D7147ULL, 0x4D904DC2A7A2EB9CULL, 0x77AE51EE5D247158ULL, 
            0xDC8BB4B24E2A11CCULL, 0x9CAFA0116986ACB4ULL, 0xFED0BDCBD8E6D860ULL, 0x24370BF311C80DFFULL, 
            0x43B3D6A3A47EC7D4ULL, 0xFA075F11842338E0ULL, 0xD7D6CC9DE729953FULL, 0x724E94B899E097EDULL, 
            0xEA9C3BDA54C5A644ULL, 0x50D165D4C7657048ULL, 0x2E4B671C74308ADEULL, 0xD61E5F91D9DCDF4EULL
        },
        {
            0xBCE234685D75B4D8ULL, 0x863CAB1A4C367203ULL, 0x36B53521F09B820AULL, 0xFEA015EDBC1E2947ULL, 
            0x55BC8209B6A124D6ULL, 0x43C85DC053631BFBULL, 0xB215A9DF7910FE42ULL, 0x9F51AB17D0599D5FULL, 
            0x2C5C11FD1581C1CFULL, 0x99674FA7BCA3CA73ULL, 0xB9FE8AF5B4057D11ULL, 0x1CF2F0887B95F366ULL, 
            0x2F5D7D5E11CFA483ULL, 0x6E8064249F8CAF4AULL, 0x9011D510A9EA63DBULL, 0x8C0423DA694E40AFULL, 
            0x23C4FD2163B3EB6CULL, 0x757015B345BB7A98ULL, 0xAA47E5273BF9E9FCULL, 0xE765689B70E3B83FULL, 
            0xCB43C2A4D1A6FBDDULL, 0xE8A2F2674F8A83E3ULL, 0x1F0EE45A2A97DD88ULL, 0x5272FABCCDF886DEULL, 
            0xC9D851508F05C979ULL, 0xD954B04016C60018ULL, 0x3F5220E6B7AC2774ULL, 0xAAABD641B9779690ULL, 
            0xBF66A716E80AD4CCULL, 0x0A04A11DB4A93B71ULL, 0x6CD64A9259DCA388ULL, 0x3C7982D3CFEA8494ULL
        },
        {
            0x02599871B07E416CULL, 0xFB1ABB750B3D8AE9ULL, 0x449BF014DA8C2495ULL, 0x451CFBD7D0D5D908ULL, 
            0x376893658EB8987EULL, 0x1197E721CB37507AULL, 0xF83B2998FA2E8907ULL, 0x3BD252EE0CAAE72EULL, 
            0xC0C11E2FA819F9E8ULL, 0x528786153D97DB0AULL, 0x91A5A7CD71DE0960ULL, 0x640243C1D123D4F8ULL, 
            0x89E05216349C6535ULL, 0x7DE52D32E2E7CD54ULL, 0x6CDFE2567E5A90CDULL, 0x04F09C7BAA355AFBULL, 
            0xFEB4EDDEA5FDC556ULL, 0x7986FE2F1F227C9AULL, 0xE36163F4D16267FDULL, 0x36D4FEDC36C4FA2EULL, 
            0x978C3F708F5E5DBEULL, 0xC1F0DDF60589BCEFULL, 0x32952EB41F04878AULL, 0x4173B3F181337233ULL, 
            0x3E3441ED292D951FULL, 0x585191E32A630EF4ULL, 0xF0BD5AE031D97553ULL, 0x086291F5704F116BULL, 
            0x3AD3B753AA7723A9ULL, 0xF31A62125221DD19ULL, 0x6F812F6DEF3EAF61ULL, 0x653AC3A3FF0F4C32ULL
        },
        {
            0x830C11C25F6831C6ULL, 0xEB57D1EA616ACFCAULL, 0x21042A23DB784422ULL, 0xD07FF8B12CF6ABA1ULL, 
            0xA2D95266E878E57BULL, 0x03914ADE357364C5ULL, 0x72412F34443D1FB9ULL, 0xD9D39173516542C9ULL, 
            0x709819339D810D31ULL, 0x1D523B7EAB5B2FCCULL, 0xAC516282584F21FDULL, 0x4D1B9B1255FD47CEULL, 
            0x39805E560B93F1D3ULL, 0x60A6426DCF2C2DEFULL, 0xD52A464CEDE3BA57ULL, 0x2948E78E3695B9A1ULL, 
            0xD24563CFDF8BD5E1ULL, 0x5FE29DD8161BADBBULL, 0xBD47DD5E1AB5F462ULL, 0xC5B66AA1B2E0E95AULL, 
            0xAA2830222896A58AULL, 0xF4CB762EA6F9BCF6ULL, 0xFE308105A874CD36ULL, 0x390F40C9643D6353ULL, 
            0x4ADEF6A9F9976F16ULL, 0x8D938FD2F496AB41ULL, 0x69DFE809BA5327BDULL, 0x4CDC337D8C5E8CB5ULL, 
            0x1C657A2B065AF085ULL, 0x7A719D1C379573F5ULL, 0xC06EA118E4ED3CB0ULL, 0xCC1F05313108D1B8ULL
        },
        {
            0xF64914C917FA8186ULL, 0xC857241EA66466D0ULL, 0x5E6E6E67673C9225ULL, 0x514FDF472A0F0E4BULL, 
            0xEE7F54C46A4A8661ULL, 0x56A7CAF727102237ULL, 0x45BA5589264D3F3FULL, 0x6E4AD6EAF24D7A28ULL, 
            0xFC5B45389C537BBCULL, 0xA2FAE7D4470FD60DULL, 0x49639592C41FE401ULL, 0xE763AB6E5BD53DE4ULL, 
            0x85B783807ACB0E46ULL, 0x9F18E1058E80957CULL, 0x5737F27AA06BFF0DULL, 0x410B5C5C0BA70A78ULL, 
            0x4B8398C57AFEE232ULL, 0x28ACCEEEAF293F76ULL, 0x6CB0A7AC640AFD27ULL, 0xFA169350BA291000ULL, 
            0x8DFB28F75EDDD659ULL, 0x5038BEEC624A02DAULL, 0xF4890A149F317B34ULL, 0x164980B328F8B348ULL, 
            0xB03E8F1C06EE07A3ULL, 0x09AE4EA38CD958DEULL, 0xC04B7E72697F72BCULL, 0x66DFCB3317F31D9BULL, 
            0xC574F14A7FB25AA6ULL, 0x722B8D55FA5F13D1ULL, 0x972841B59C2C5D2AULL, 0x68BF66B4D5A50D50ULL
        },
        {
            0x7CEAD55EF7ECBCBBULL, 0x615DD8ECF05D8DA2ULL, 0xAED40A2687A89D6BULL, 0x0577DEA500E4E4BBULL, 
            0xDF42224D00FEEFDBULL, 0x8FC293A319CF9D02ULL, 0x790FFE8B582C9CAFULL, 0x254E752E1FF1D77BULL, 
            0xAD1040C145C8F0C6ULL, 0x7C550B8D05FFAFD7ULL, 0x5F75BC767EBF981BULL, 0x08B916C674D44CDDULL, 
            0x23B84533B3FE8570ULL, 0x3E537394EC2127EFULL, 0x7421037B5ED284B9ULL, 0xB27E7A81702D42EBULL, 
            0xF9D06274833A0F66ULL, 0x4A72C77B97BEC965ULL, 0x8A052BB0EB8C8B03ULL, 0xDD6CA5D6091F5877ULL, 
            0x3885ED340263E769ULL, 0x380E2D7B51DCB613ULL, 0x24D47E1D70ACA1F5ULL, 0xD45C3C241CB3EEC2ULL, 
            0xFFC8CD297925566DULL, 0x7F137515A511A9E1ULL, 0x860C80C0F43C61E4ULL, 0x96413F913C53BF18ULL, 
            0x66CDFEACCC26B12CULL, 0x991709553BE15D89ULL, 0x22F62720A5C57A0BULL, 0xFEDA391B58A1B98EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseAConstants = {
    0x577F390827C70185ULL,
    0x1DC24377191B3EABULL,
    0x7F4DA34C57965C51ULL,
    0x577F390827C70185ULL,
    0x1DC24377191B3EABULL,
    0x7F4DA34C57965C51ULL,
    0x2C0A9A2B3C886249ULL,
    0x5E0A5065F477E38CULL,
    0x05,
    0x92,
    0x0C,
    0xF1,
    0x68,
    0x0C,
    0x8D,
    0x42
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseBSalts = {
    {
        {
            0x4D36795DA985CC4AULL, 0x78D7227385994DF3ULL, 0x9D2B2388F8A09D6DULL, 0x805396C5F90DAE20ULL, 
            0x99A749E2F697C49BULL, 0x4EFDDD13490E5D89ULL, 0xACD0FF306E399CF3ULL, 0xF8F9FD514AB34EADULL, 
            0xEB50DD6D278D0A7FULL, 0xE4243809BC86648EULL, 0x384D6B91F33FD320ULL, 0xCA654282533A3D7EULL, 
            0xB6C164A484866E49ULL, 0x16D75C212F0482EBULL, 0xF73A4B80885539CAULL, 0x9B0AA6C39B49F962ULL, 
            0xFC9585AB655C8EA7ULL, 0x4A37C615E169D77AULL, 0xB1E543D0D2ABB440ULL, 0x413E75AF980AC196ULL, 
            0x38BBA2C9074D3C3CULL, 0x6E3A4411CAAB7A5CULL, 0x252F0FA41454DB90ULL, 0xFDCF7BE29F2EC8B2ULL, 
            0x1CB3CFB5E3D76739ULL, 0x99B4B1F79F241A25ULL, 0x0B628EB9AAEACE87ULL, 0xAA2BB69DB0686D44ULL, 
            0x349D4AD8A5FDB427ULL, 0x82E251E8EB3769FBULL, 0xBC8B3ECD10A9AB31ULL, 0x520875EE020E5D33ULL
        },
        {
            0x5D002D3AB08E7BE7ULL, 0xCFB7E28118F29C1EULL, 0x471D65A7F9F9C012ULL, 0x691B80FF1AD95B89ULL, 
            0xE1850EFEA0DA39ABULL, 0xFCA4F0A51813D8BDULL, 0xC3154553B3BB9DCDULL, 0xC603377C49E5D1A4ULL, 
            0xE2FD88B87DEDA111ULL, 0x848E9FF626361DAFULL, 0xFF14E4B80C1CD83AULL, 0xE4A4B5687FA21480ULL, 
            0xDA53D5A1E9460B67ULL, 0x1E4AD1C45286AE63ULL, 0xDF835B965DFFE413ULL, 0x0BCF4D0E16C431C5ULL, 
            0x70E756BAFBD2C31FULL, 0xEDCB3D4C26BAC832ULL, 0x51AAA1C4D4B3A87FULL, 0x221167E6962F231DULL, 
            0x104592F4EA51B103ULL, 0x03A7D94EAB5C7F01ULL, 0xE40A95009C3BAB7CULL, 0xCB47969178039601ULL, 
            0xAAC12CCDE371F44FULL, 0xA860AAF04292A4E6ULL, 0x4B76901BA51740CFULL, 0x0FC233393B668EB2ULL, 
            0x2177A64394CEE1D4ULL, 0x34BC5BD5BE1D0CF1ULL, 0x17C9E2500071AC00ULL, 0xE3188BF02172C824ULL
        },
        {
            0x550E60CA8E04E707ULL, 0xE2B75CEEE34955B4ULL, 0xDE322A0B0C6854B8ULL, 0x93A7FF2CA7B41B92ULL, 
            0x5D9B953CA6AFCF7FULL, 0x648CBB1C36D29F05ULL, 0xB3EB7BE56EB4E783ULL, 0x82E735647F1C65FFULL, 
            0xB9CD593F01E2E953ULL, 0xFCEBA43AF4CBA5A9ULL, 0x0EC304C16ECE0FE2ULL, 0xB16B8F952ABAE241ULL, 
            0xF01D94B10E1E319CULL, 0x0FE966D46173C993ULL, 0xC6FE492BF7AA1D47ULL, 0x58EA7A3959B483B4ULL, 
            0xEEE364C95AA0C5E0ULL, 0xE764168349F086F3ULL, 0xF1E83E3FBF5CBAAFULL, 0xB88B5FEECC312129ULL, 
            0xAD7FD72A6B2A3CDDULL, 0xAEEF8AF4C5BE432BULL, 0xD8D041A53B372EFEULL, 0xA1DF6DB68DC17243ULL, 
            0xD1528FD140FFB92EULL, 0x4B129B5BDDE0803FULL, 0xA2AF42F0082C9328ULL, 0xB6F108177576CE86ULL, 
            0x1E1D5F3004FE4767ULL, 0xA6703A62A8F07A11ULL, 0x914162BCB42EA599ULL, 0x1FA86232E72CD732ULL
        },
        {
            0x51DA6AA721EA872BULL, 0x1D5EB8DCA859434FULL, 0x67F93341FC898A99ULL, 0xA9E93B055BFB4D3DULL, 
            0x828FD74780B5FFBAULL, 0xCA147694E0F63E54ULL, 0x77AB11428DBF5C70ULL, 0x37D47620798A6925ULL, 
            0x59D8BD23882C784EULL, 0x4A7DCC6759124ECAULL, 0x99A5D6E7EA5B9F7AULL, 0x17EF9577FC949534ULL, 
            0x0B17F27458FA6BC5ULL, 0xF4A6E6012C60FB68ULL, 0xA908BA5BE25CC461ULL, 0x7EF90DD646443604ULL, 
            0x64A89DBAAD5684F5ULL, 0xA46E34B73AAF1F9EULL, 0x045B0BAB15A1F04AULL, 0xDEAAEDB6D1A3B518ULL, 
            0xB373B7EDA37A2CA0ULL, 0xE9D5E94E7A0B8281ULL, 0xA1710837C6394D3AULL, 0x9B5D98365D3DA554ULL, 
            0x4AD56E0AB35B7700ULL, 0x5B01E341A4E083BEULL, 0x1F3AC445A3167BCAULL, 0xC7A9C7FEB2276DABULL, 
            0xCA2B8915B222FA1FULL, 0x0E0662326547C356ULL, 0xDDA0B03FD0B9BCE3ULL, 0x4FB7259268427B1AULL
        },
        {
            0xC88D9F69F0DC82F4ULL, 0x6C8E124B019E5C10ULL, 0x004D489493C5E309ULL, 0x6A99355C28C11C30ULL, 
            0x3405AA5A7A1D8A6CULL, 0x7647B5AE2DF1BB1BULL, 0xB7ACA0AA0EE18029ULL, 0x05ABE2342910A964ULL, 
            0x8B2F0C9B5FD4AC8AULL, 0x5475F6C13A0BA59DULL, 0x02F3810CA8A96864ULL, 0x4D9A71D9487B59FAULL, 
            0xE02E20475FEF9C7DULL, 0x0C0FD7EFE5138EC2ULL, 0xBE75D881E3FB943DULL, 0x0BF658F177A8E844ULL, 
            0xFA43491947C8A5D0ULL, 0x60C57E9FB05F8659ULL, 0x6BADCF1EC9308388ULL, 0xC938BD65F575EE88ULL, 
            0x8665C0DA1CB88E17ULL, 0x10E7B30990E4280FULL, 0xB1AD5F5120DBC53DULL, 0x0D398E111E5E7B1AULL, 
            0xC6682CDDDA412979ULL, 0x73616F136E0865D3ULL, 0x73FE69BDE9648DA5ULL, 0x4AD14FFEE24A7F2CULL, 
            0x80F323D1A55DD25AULL, 0xBFCC151412EE1F17ULL, 0xABE5E74DD5971229ULL, 0xFE420E3EC3373D28ULL
        },
        {
            0x873ED1E972936047ULL, 0x3CFE9CADDB2C60DEULL, 0x3963FA4487E64E5EULL, 0x2DEEFA407E8495E9ULL, 
            0x4663C947C88D0374ULL, 0x8A5371B6ECDA3C1EULL, 0x2C0DCEAE3F28503AULL, 0xB8695E13F4B511A0ULL, 
            0xFDE72FFAB398D21EULL, 0x4CF855D7C97895E1ULL, 0x56121AFA9FD838DAULL, 0x9DF71470FB41F8F5ULL, 
            0xB50EA706E918A6D6ULL, 0xFEE0DC99EFAC31F1ULL, 0xD4E3352682F34551ULL, 0x3071CBE3F6F94C53ULL, 
            0xBB138C1B65627318ULL, 0x7B8EE302B2DE37AAULL, 0x52D7A6E53B0D5FEBULL, 0x3534980CD81A9141ULL, 
            0xC0DB8DA7FDA42EB0ULL, 0xDABC35E5E4F2957DULL, 0x0724A6DE5C63FE66ULL, 0x28A61E93F1F6EB72ULL, 
            0xE74E12266D347C44ULL, 0xA6929974F37DB371ULL, 0x8608ACAAA1B55878ULL, 0x445C574925684E99ULL, 
            0x38EB748D74B7063FULL, 0x9070B43AF1DFB8CCULL, 0x6A8DFD26C3DF05A0ULL, 0x80F479DBB6960669ULL
        }
    },
    {
        {
            0x25EFE3182F99EF61ULL, 0x3C046B5BEFA719B2ULL, 0x226366681B300890ULL, 0x3F9B9A8A3DC15BD2ULL, 
            0xE711FDC50996087DULL, 0x2BDD39E5C20E2652ULL, 0x5DE0B2F1C3EED170ULL, 0x437463021B5C03EBULL, 
            0xC49A542C316CD2C3ULL, 0x26C0E464DA7777A9ULL, 0x292A2D92D7EEA471ULL, 0x828E168BE423DC37ULL, 
            0xACC7E003B1365886ULL, 0x46C030ED4CD70449ULL, 0x0D84CE57D0B756E0ULL, 0x6A303B6BAA975A6AULL, 
            0x4F07850ABD63E33AULL, 0x0877DFEFFDC92469ULL, 0x58E9E84A4BF338C1ULL, 0xD20847EAB4E1E456ULL, 
            0x0C37EF8FF4979B5AULL, 0xF1FF2857BB887763ULL, 0xCE66B69FA69C0536ULL, 0xCC297CE491130D48ULL, 
            0x2FA96757947B69FFULL, 0xED65F44564C761E8ULL, 0x88F299EC01B4E840ULL, 0x69FB608D46D041C8ULL, 
            0x10D65A222345D441ULL, 0xC537858A7228A7EBULL, 0x555124E53C6D6FC4ULL, 0x69B0B89D033064DDULL
        },
        {
            0xD49BEAD1F94F4F14ULL, 0xD576EA2A7DAD9E8DULL, 0x59289D0B7A86C44FULL, 0x8552217B84A562CFULL, 
            0x0198FC90646F4392ULL, 0xA3E9CF25CEAB02CBULL, 0x3E89EBC0EFB425EBULL, 0x8B81882172BC5AA0ULL, 
            0x9643FDB1DC7CE547ULL, 0x5A1F0C63BF0A7BCEULL, 0x062AAEAB2C6A38A3ULL, 0x8079AAFC89295C07ULL, 
            0x030F13993BC236F1ULL, 0x78CFB4D8EA82E9B7ULL, 0xC53AD88E90A94359ULL, 0xB6E2DCAAC7AF76A8ULL, 
            0x97510B958505B02CULL, 0x13D2BCD91A165A6FULL, 0xED72B588199B8FFBULL, 0x26FA138EC44FE05EULL, 
            0xD319FD6847887837ULL, 0x658D4244703251E7ULL, 0x93DB60240E5354F1ULL, 0x28E66C50B461923AULL, 
            0xF7FEE4EAEA12D049ULL, 0x7B073C09F4F45174ULL, 0x60E83F7A64365972ULL, 0xB4FFEE896662EBB9ULL, 
            0xC5D6C2E0FA97427AULL, 0x3B6B8FC8B9942B13ULL, 0x038353BC64DEEA09ULL, 0x25B3EF2344C11491ULL
        },
        {
            0x2FCCFD9C200AAB09ULL, 0x7C041B5F9A5B8DC6ULL, 0x7E83A872B4F65CE5ULL, 0x647F8FCDB11D9541ULL, 
            0x9EB8A40976FD5A3EULL, 0x547EC9743954C97AULL, 0xA9A41D7D64A709EDULL, 0xDC8F32AA9F56B5DCULL, 
            0x4D7EDF5BC285EBBCULL, 0xFACA8371CFAA87A7ULL, 0x32CF99D8CB5355CCULL, 0xA069296543D4B6B1ULL, 
            0x92B9D76B687E9895ULL, 0x03D8AC285C2DDD99ULL, 0x454DDE8E2F0FF4CCULL, 0xDD69B21DA8CCFFA9ULL, 
            0xBA049925A1A19BADULL, 0x3476EF0898B45192ULL, 0xBF35F555A8EF2EBDULL, 0xF2CEBD38C91D896DULL, 
            0x69EC16E5E7880394ULL, 0x410B761B2133D980ULL, 0xC1C04F488C83C04BULL, 0x4B048D730A6BC955ULL, 
            0xD8243FE8CAA3F22EULL, 0x290F4A515226FC8AULL, 0x518CBD7A31F5F2A9ULL, 0x3DCFB93A02DB1C8BULL, 
            0x302C04A1ED01AEADULL, 0x925A31C8BA2F1D25ULL, 0x7A0F5D420005397FULL, 0x8D051D9282BC1EC5ULL
        },
        {
            0x6B5888313EC6217FULL, 0xD1870DB5A55724B6ULL, 0x989C707B47C6CC21ULL, 0x310B21BCC88CB2A7ULL, 
            0x22BBC4182A8D76EFULL, 0xDEB3E1DFD33FF786ULL, 0x0F194941E2E7F551ULL, 0xB1B1F0550AA4824DULL, 
            0x3071FB203E0F2E85ULL, 0x82762A8153395F97ULL, 0xD4B78F100CBAE3D4ULL, 0x3C5035ECA0016803ULL, 
            0xBCBDED820AF4FFD5ULL, 0xE2CB425199AF243EULL, 0x545C683E76899687ULL, 0x16579586E50F16DCULL, 
            0xF4A63A5E956FDBCFULL, 0x2E65DE582E4FA1FCULL, 0xF3E45AA196A0ECEFULL, 0x8F1E9AF81EA7D5FAULL, 
            0xBC94B70315220A49ULL, 0xD9DD6D21E37D28BCULL, 0xB2C21BBE1239FCFAULL, 0xF38BBC69171BE7F5ULL, 
            0xD8B05BF9AAC362ABULL, 0x83F115D97337191FULL, 0x5E803EC2B13670A7ULL, 0x52D4F01E8303A5A1ULL, 
            0x8B93DB689C835038ULL, 0xA07A62B8674151B2ULL, 0x64751B06D80140BCULL, 0xDD15F0A9F63B0DACULL
        },
        {
            0x9714BB844E63F299ULL, 0x0C21FF67F4F56215ULL, 0xC395EFB10D5A23ABULL, 0x3E3E1C1841C3E509ULL, 
            0x45AE56CB81363276ULL, 0xC63EAD18AEADD80EULL, 0xB15B3BFF1C576096ULL, 0x1C21D70D5C608C43ULL, 
            0x370EEB9765809ADDULL, 0x8423AD0B87371E8EULL, 0x3FC72771C0248EC6ULL, 0xDB1B3AEF15EEE385ULL, 
            0x64DD77E4401E0C64ULL, 0xB7356B72A2DE6169ULL, 0xDF64404920BA0941ULL, 0x9D717C7D1BC5D071ULL, 
            0x264C8F5B680AB239ULL, 0x8C39ABC400529955ULL, 0x079BBFB87D01265CULL, 0x39592779CF22AC14ULL, 
            0xDFA1550CC7BA8548ULL, 0x1ADC605FE059705DULL, 0x975641667A0464C8ULL, 0x9EA31A04FF0EEBC4ULL, 
            0x2D2C2D1855DA6447ULL, 0x3E846408CB842C7FULL, 0xEACFAA53FAA75E09ULL, 0x5C5C91B38A5F8603ULL, 
            0x7C2957895979FE1EULL, 0x052CEEE243290B49ULL, 0x6E18FC1CA8CB2786ULL, 0x48EDBDC32C55B6B5ULL
        },
        {
            0xEEAAA22A62D20348ULL, 0x03805D6EA5E37E04ULL, 0x99E958D5E3824AE7ULL, 0xFB18918CE4DA2210ULL, 
            0xB1E0366BD5EAFE70ULL, 0x5581ADF10F33EC58ULL, 0x768468F53589671AULL, 0x2D2A8A37B38D7602ULL, 
            0x3B63FC9572BAFEB2ULL, 0x565A7CD15B250ECFULL, 0xC29B0B7C8A67A5DBULL, 0x8188C919862B9818ULL, 
            0xA4255EA4F4D29F8CULL, 0x693850FEE9573AF4ULL, 0xF8336EECA6BF3746ULL, 0xA43ACDA8BAC16E7EULL, 
            0xE721676632236843ULL, 0x6B47B6D098161DBDULL, 0xE0F7C0154546FF04ULL, 0x6CCCE63D3446B6F3ULL, 
            0xF7049904706D8012ULL, 0xD0A6EA58CDEFF183ULL, 0x7F97731996D2636EULL, 0xF8CB77C3D20F598FULL, 
            0xD4935BA5391B8DABULL, 0xB28F19DBE9184667ULL, 0x6ADBA14433DB2472ULL, 0xA88A53357C2823A1ULL, 
            0x97B29CE5DB4D762BULL, 0x9E890F3FE1CF458AULL, 0x9CCD15B3A23F720BULL, 0xFE8365FFD1861B54ULL
        }
    },
    {
        {
            0x866AFD4CA53F751CULL, 0x2D1D128D191D27BDULL, 0x1ED9AF24BC0B5057ULL, 0xB5F38FCC81CE3B32ULL, 
            0xB76590AE7D4BB1C2ULL, 0x0F28D84FFAB78442ULL, 0x4F937CEBA9E77E3BULL, 0xDBE0B8D3AAD10EDBULL, 
            0x1C92276C7977C47DULL, 0xC0B59EB1ADFE6839ULL, 0x3E950C6044420440ULL, 0xBB4C3E8321C42B94ULL, 
            0xC239CCAE768EC7B4ULL, 0x4ADA5D561B3AF961ULL, 0xCBFDC00727662ACAULL, 0x5BABA9BA9F771D2EULL, 
            0x5F3A9565F1662090ULL, 0x54D066D17D110BF2ULL, 0xD0BD703EBD43CF69ULL, 0xB29A2C8DA3D67A71ULL, 
            0xFF94A7206CCB1B28ULL, 0x9D2DDD17E0501628ULL, 0xF76FB1C1894B07B5ULL, 0x4621767B44FB70B8ULL, 
            0x6B087CFDF3E97E63ULL, 0x0C336F05D65E9E08ULL, 0xB3350E32115781A3ULL, 0xFB9ACE8EEC6E426AULL, 
            0x1E60F43B534EC671ULL, 0xD34CFA8E9A20ABEFULL, 0xE39A54F77D860090ULL, 0x344DF80E056C4FE6ULL
        },
        {
            0x398842AD727649D8ULL, 0xA236A1A2ECF0C573ULL, 0x2B2C221E2801ACDEULL, 0x25014E56CC03C443ULL, 
            0x2BCE0D0CD95DE062ULL, 0xA387BE5B45437B9CULL, 0x6FC9776103BD4F11ULL, 0xA1B31F3122E26B5AULL, 
            0xC7DA3953038FF88DULL, 0xDF7FABAA7617B5E7ULL, 0xDE7ECD32A8F23046ULL, 0xA8AA7FEC5575D695ULL, 
            0xCAEEEE83325B2343ULL, 0xB8B11BB314AA8C03ULL, 0x999D82917B49B603ULL, 0xA09BD6D80D6BCDBEULL, 
            0xA56076A47574773BULL, 0x963A008268909304ULL, 0xAD2BBC78B71D693AULL, 0x9928D0D806080628ULL, 
            0x4AD7AC56C49A7114ULL, 0xD77D717F656F51DCULL, 0xE9B7EEA7EA9DB608ULL, 0xDBD32D73A3F4B254ULL, 
            0xED85E7B6701380D0ULL, 0xEB52E880A469400DULL, 0xED96812DD02FFDDDULL, 0x7D7ECF537F0C9C97ULL, 
            0x3DF48AABB40377F1ULL, 0x2C5FB385CC585BFFULL, 0x76B8478EB1A715E3ULL, 0xBCB7DA826F3DD19EULL
        },
        {
            0x1566690B8C01DBEEULL, 0x5FC8F9C27C9E99B3ULL, 0x967D321D85FBF719ULL, 0xC83FD14C2C2E501BULL, 
            0xE2522E83A7E494ECULL, 0x45AB94749489284FULL, 0x448A07FC9FD4A593ULL, 0xD010DD462B42E01EULL, 
            0x53F7400B5B365895ULL, 0xE7F91FB4C3902341ULL, 0x25FF5207A5E8D8F7ULL, 0xAEA5C898506B4F74ULL, 
            0x1AAA7EEE6FFB0CDAULL, 0x82CDC5562EF16372ULL, 0xAA82CF73392D47ADULL, 0xA46B85ACD2B52123ULL, 
            0x5E452B7400EF1A3AULL, 0x0A03EF09FD31A198ULL, 0x81AE4DE66C5B0DB8ULL, 0x06063EFF5AD8F959ULL, 
            0xE6E3D1E1383C928FULL, 0x5C722697A3792BDFULL, 0x6974AC1FEDB7570CULL, 0xBA3D05E57526ADA5ULL, 
            0xAFC179581715FF9FULL, 0x32C019144BD8DBC7ULL, 0xC33948FC63E39F11ULL, 0x786CDE03849CFF41ULL, 
            0x451DAEB6CC8C7A3EULL, 0xA9DEAE952C735F93ULL, 0x6A4A3248520E470DULL, 0xBCB1A07B856A747DULL
        },
        {
            0xA14595113B6F9AE3ULL, 0x3732E57D03329E7DULL, 0xFC51355204710731ULL, 0xBF48DCA1110D19FFULL, 
            0x10557AB71F6E6F7FULL, 0x150EF4012E269653ULL, 0x2CAC488842AF0428ULL, 0xA08DFDC157AEF58BULL, 
            0xE285BCD87EFF87FAULL, 0xD3E97BCA9BEDFBEAULL, 0x11FDBDEE74A3E928ULL, 0x8248EEA1A629AFEEULL, 
            0x677DF61BD7E60CCBULL, 0x57346C026C112C4EULL, 0x26150B363F2D4103ULL, 0x8B47C531F52F926BULL, 
            0x40F19D2C486D88EBULL, 0xC49ABDF8052A2563ULL, 0xC7DFD1C295733403ULL, 0xF19168B49CD398B0ULL, 
            0x41C5FC99B9BF9BD1ULL, 0xE1EC050A369DA529ULL, 0x144E37415A1E7C62ULL, 0xF4820292806E7F50ULL, 
            0x14EBDA79F9CA1BA5ULL, 0xB38F0002913B3520ULL, 0xFE4D99B57928CC25ULL, 0x62876068DB00666BULL, 
            0xEBCE6B059AF3CF3AULL, 0x5FF9AD566BF8C140ULL, 0xADD9D9D06BB2065DULL, 0x3D8E17F80386321FULL
        },
        {
            0x047893AA99C3F832ULL, 0xD79B11C0C4BED42DULL, 0xDD3CAAF357A6DA70ULL, 0xD5BA83E5AE4AFA69ULL, 
            0xC5211801FFA2DDE4ULL, 0x7BD1B179659D8D77ULL, 0x3E19D8618D28D8A0ULL, 0xFF3FFE7F6928E953ULL, 
            0xCEC3B817A91EF5E9ULL, 0x5E45065C649D1CBFULL, 0x07EF0709736FD976ULL, 0x915F4DF6E489D17AULL, 
            0x610CF3F6D0A54792ULL, 0x84AC4CB1C755D9B3ULL, 0x4E889984837EF880ULL, 0x79895A2E7906DB5CULL, 
            0x28E1A8D9B03FEC52ULL, 0xBF9CB62082B25ECBULL, 0x852D9DDC130F3F76ULL, 0x0E9435B6AF8280B1ULL, 
            0x8DA473CF559CB837ULL, 0xA33513333BF02C10ULL, 0x0A955FB63981EE57ULL, 0x60BD495C7624C94FULL, 
            0x35CD73B74A01DD33ULL, 0x3D6BA6E6EF228BF5ULL, 0x78BBE80481BCCC64ULL, 0xA040874C4593A347ULL, 
            0x11958EDEF65B7A56ULL, 0xD2D232C4A67B3AC3ULL, 0x4B753B2B7E23CC9FULL, 0xAC32BC67B7C73C6BULL
        },
        {
            0x9E35153DAFE02B7AULL, 0x8EC65B9725E1BBA5ULL, 0xFAE6F3162D916919ULL, 0x7CE7A3A0A2D15638ULL, 
            0xEA9FF66B9617E9EFULL, 0x5D8ADE3939EB21A2ULL, 0x5BE9E925482772CAULL, 0x962FEC3592BFBBA6ULL, 
            0x350C457A3DED873EULL, 0xEA5E22C17EBB25CAULL, 0xD2EC721112D66F7AULL, 0x3F2CA3C6B9FBB6CBULL, 
            0xA6A22F6A7DAD3042ULL, 0x0C486F9E8612C966ULL, 0xBA351C20149BBEF3ULL, 0xAC36BA8D21BCE0D1ULL, 
            0x8C63D3D58C65199FULL, 0x46BCA9BBA1AF7466ULL, 0xB29B0B2214A9334CULL, 0x37C55ED43118F69FULL, 
            0xF9089BE5D50CAC47ULL, 0xF875CA14B01FF39DULL, 0xD5D7FA23F05D4B87ULL, 0x66C51A22981DFC55ULL, 
            0x71CA8723E35B514EULL, 0xC5B292F9641D2679ULL, 0xB0EA596EA7B7C10EULL, 0x3D6BEA2CB521A644ULL, 
            0x139B9808902C106CULL, 0x9237621B584E3072ULL, 0xC993CC22416069BFULL, 0x6D1666265C63E7C3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseBConstants = {
    0x319B80C347FBD1CEULL,
    0x07BFA5DD75D4A9F6ULL,
    0x8D049232DE4D8989ULL,
    0x319B80C347FBD1CEULL,
    0x07BFA5DD75D4A9F6ULL,
    0x8D049232DE4D8989ULL,
    0x64AA8A5494E0782BULL,
    0x1BA9669154593154ULL,
    0xB6,
    0x7E,
    0x3F,
    0xE2,
    0x91,
    0x64,
    0xB5,
    0xD0
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseCSalts = {
    {
        {
            0x65F945B5BF0534B9ULL, 0x90E1E73E95E0EE5CULL, 0x66E3BC7B46A8D7EEULL, 0x4734C447B6745B86ULL, 
            0x22BBAB20300CE047ULL, 0x866D2E2B3836B40AULL, 0x17006F40F59A9DAAULL, 0xDF1E15DB7F9DF0FDULL, 
            0xA1196451765C783FULL, 0x10CA72562C34920AULL, 0x7BD0C56041FC6CAFULL, 0xEC4D914612110AD5ULL, 
            0x6AE6173187C8B9E3ULL, 0x8764B0C662F23D76ULL, 0x8BC6E82D4DF7DB3CULL, 0x298D5D9126693459ULL, 
            0x0AECF6BA30BB671CULL, 0x20DB5810EFD1D60CULL, 0x0D1921259313C0B4ULL, 0xDACBFD1CC0C7531DULL, 
            0x8F2E2C17F6A9F717ULL, 0x92BC06F8745A1563ULL, 0xA710E3884C03D3D1ULL, 0x01060713C2E347D0ULL, 
            0x48874D19CF6F1F12ULL, 0x9F86F0E75D4647ACULL, 0x9C9D5A6DA6DF5A21ULL, 0x3D825AD7F74D304CULL, 
            0x183EA0A295A7D9AEULL, 0x486DE362F254A2BFULL, 0x6D39BFA50F0B2EF3ULL, 0x0852882ED5AD48E4ULL
        },
        {
            0x374090639A2742B0ULL, 0xFEE217DF425BC079ULL, 0x3EE23DDB66568B8EULL, 0xA7A68329C59A04D6ULL, 
            0xBE41EFAF61E08EDDULL, 0x88D835CD09E5B13FULL, 0xEEA3C5D519C608F8ULL, 0x67033D55A65B6310ULL, 
            0xC798F74AF420EF83ULL, 0xF79A047DBCEFE9C0ULL, 0x70BAAE60FB927FD3ULL, 0x1CE224818C23CFF4ULL, 
            0xF8476C4C381B1057ULL, 0x6BC3C57BCA9A2BEBULL, 0xC65C9B161A8BCD08ULL, 0x18E3B40DF2536D41ULL, 
            0x5F54D14B3749AA21ULL, 0x6A413F5130A952C6ULL, 0x64169786DEE6BCCFULL, 0xC2F80FBA780676FEULL, 
            0xBBDAA1C5A7ED9E4BULL, 0x777CAFC230B1A4E7ULL, 0x51ACF6E508E0BCE1ULL, 0x869C049765A82522ULL, 
            0x8E897DE81C38828EULL, 0xB28A54088B247F95ULL, 0x9088A4501C9C5659ULL, 0xDFD68747FBE1F053ULL, 
            0x58315273A49B29CDULL, 0xAAB0461A29D0478AULL, 0xE1323900A535507CULL, 0x1EC25BB407D6A9AAULL
        },
        {
            0xF02755BF51DA38B5ULL, 0xED75C8E51AB4B897ULL, 0x294E40BD229A55ECULL, 0x5D77C85521931134ULL, 
            0xB39F2F8F5FD06717ULL, 0xFA7FC98E288AD92DULL, 0xB34415800B05FBD7ULL, 0x9E87F5D3A08BC21AULL, 
            0x1C254C3358929489ULL, 0x92B237A47FEE65F2ULL, 0x2F24036032BDD4B2ULL, 0xB78E11885C4939C5ULL, 
            0xA130F916F7C49BC8ULL, 0xB0CFDB4535455E53ULL, 0xF811FFA0711B7870ULL, 0xB84D01538D4DACA2ULL, 
            0xC47DFABB55CD06A1ULL, 0xC15C1ED8C1AD3A97ULL, 0x4A5A198FB7FED520ULL, 0x00A0F69B171C4E54ULL, 
            0x4C5E20BC6DB5A8D8ULL, 0xA596753A6095F85FULL, 0x6D37A37CC1C468DBULL, 0x4FB4590DD9576789ULL, 
            0xA090BA0E89E9C6C5ULL, 0x475C35E661A7C097ULL, 0x60A49395A8AFD84BULL, 0x84479595AD614793ULL, 
            0x0CA3A4ADA61BFBAEULL, 0xAA91B70B988A38CEULL, 0x1BE4F531FD9B3337ULL, 0xF754EBEE6DBCA463ULL
        },
        {
            0xDE117D3BE5F247CDULL, 0x7F68AB8F9F599055ULL, 0x241022F537CD8ED0ULL, 0xE6A1014C3F5BC6EEULL, 
            0x288AE61ED40740BEULL, 0xB657413973372E40ULL, 0xB37D730C13AEE513ULL, 0xC3B9F3CF13862DCAULL, 
            0xA5B95C0E09F9425DULL, 0x9A3F0B28C6E6185DULL, 0x7CF8C46361B8116AULL, 0x98F43450FF286AD2ULL, 
            0xE57EB2F50CFC8CB1ULL, 0xF5017878B46DC73AULL, 0x5B6EF14229A032DAULL, 0x69B14E343AE5C400ULL, 
            0xEF18EB8CBC281478ULL, 0x2F27A38D9E54E058ULL, 0xF247ADA91DA4D2ABULL, 0x25A176CD653FB4DFULL, 
            0xCBC4C61797BD18DEULL, 0x6F8E41E03998DEDBULL, 0x97D5854F2DAA8FBDULL, 0xE91E5F16C3EC4189ULL, 
            0x184C99226D9223ACULL, 0xC32317A662A65F56ULL, 0xFE42FE2325B2519BULL, 0x373FA2AE3E12FE11ULL, 
            0xB3BE1F2120853792ULL, 0x9C175473867C8955ULL, 0xB0F6CDEDBA1D646FULL, 0xC6E2CFF2DDBC4796ULL
        },
        {
            0x16EBDBFC52564CAAULL, 0xD748C8B418AF1ECDULL, 0xE5E1AF2A38CAA6DDULL, 0x56FE4E0EC4B5B8C9ULL, 
            0xC245515DA1F07F37ULL, 0x78802E4770ACB5FEULL, 0xA22AEF56217489F4ULL, 0x3972D4B44F9509E0ULL, 
            0xE7D7604FA083E31BULL, 0xEBDA1CD944678702ULL, 0x119895F2419E04C9ULL, 0x5074FB7DE65E66F0ULL, 
            0xF89FA705EBED1439ULL, 0x1B11E95C54C558B9ULL, 0xF6868D657A4219BAULL, 0x7E9BD3CE510FBE27ULL, 
            0x1B4922159CF32B8EULL, 0x2A3AC0313D3ADC07ULL, 0x47044A8DF7DBC336ULL, 0xA20D0F77C4A4F850ULL, 
            0x2FCD3022E9E8005BULL, 0xFB11F7708DA8BF25ULL, 0xCE164B464EFCA476ULL, 0x17A52C904A26D1FBULL, 
            0x6BA3B85AF7EA67C7ULL, 0x4BCB72DA9FEEB541ULL, 0x0792EFB377331641ULL, 0x866AD006069CF25AULL, 
            0xACC764C8A5907B51ULL, 0x2A40F5E25C35F322ULL, 0xE4874750C2ADCFC9ULL, 0x8C1D6EC333C95B35ULL
        },
        {
            0x8244AAB28BAE6804ULL, 0xF0DC2F761C0CBAA5ULL, 0x32AC420B27B56154ULL, 0xBAD47F84EB03B557ULL, 
            0xE6F3282A1A5E8FBAULL, 0xCC06F8D025A2CA60ULL, 0xE7A6301EC2A1902EULL, 0x731DF8113DC39D94ULL, 
            0x8D9B11861FDDFEFBULL, 0xE48BDC7069196990ULL, 0x86CEDFF89BC9A9DAULL, 0x7DC72FA351BC2D61ULL, 
            0xA6B74706D8BE998BULL, 0x3657945A87D57A19ULL, 0xB572E1599E5DD744ULL, 0x5FBF748693747A22ULL, 
            0x474EEEDC95C99C76ULL, 0x4955E162BAD19280ULL, 0x59655F1081E30C7BULL, 0x99CBE4862C575067ULL, 
            0xEDA609EDC81C1DEBULL, 0x73B4F8F8A68CF8BEULL, 0xA2C0AE70BE0208F6ULL, 0xA6D6C94209A7515FULL, 
            0x65FA041D00FEF0C8ULL, 0x3BCCB912034CB7DFULL, 0x00F0C0D140268B7AULL, 0xB502B415D24312DEULL, 
            0x9BC850106A11B847ULL, 0xF846E6D50709F099ULL, 0x4125CEE91E2D0D5FULL, 0xD94C1BF4F8C857E1ULL
        }
    },
    {
        {
            0x7E6430CE54C98A14ULL, 0xE360C8501FADC91DULL, 0xD789F39F48E8385EULL, 0x8CAC8A6F33A36488ULL, 
            0x0C643A2FEA1B5BCDULL, 0x00400231A49F762AULL, 0x8F2FCA045DCBD388ULL, 0x875BAF6658124E9EULL, 
            0xA42C6ADF4C598D1AULL, 0x4735DCBE4078C0CBULL, 0xDBF3FF6FF7CB6F6DULL, 0x0616B6002FDDCB8BULL, 
            0x6892990487AD2670ULL, 0x31256EB71013454EULL, 0xE229C019497E8C2EULL, 0xA635C596759E279CULL, 
            0xB14E84DC6CB693D9ULL, 0x76C1229B607E93AFULL, 0x28953CF6BF9BC9CEULL, 0x414F4943AAD4C3F4ULL, 
            0x0AB17CB2AE6C434BULL, 0x0C3817754CEE983AULL, 0x9406BE4C0C31EBBBULL, 0xFD07C30F827BF7D6ULL, 
            0x2615DBE2A20F032DULL, 0x9CB10E06C0D0A9AAULL, 0x1EC8854260BB2148ULL, 0x183623F134A9AD83ULL, 
            0x2126A229F351BBF1ULL, 0xE29E6C091F207077ULL, 0x7F4F8E3F23954794ULL, 0xE4ADE1F3861B3220ULL
        },
        {
            0x0A4CE02FB13C5CE5ULL, 0xEF7F4D5DE308BE95ULL, 0x751DAEE2F282AA64ULL, 0xEF10C70194C85E99ULL, 
            0x5505D3CBAD31CC44ULL, 0xDF71C67EDBBBB7BEULL, 0xC867DA979BF58DCEULL, 0x90BF149F7C00C4EFULL, 
            0x026989DCBAF54930ULL, 0x36C960628F74EB0BULL, 0x0560F6A70769598EULL, 0x554D517973AFC84CULL, 
            0x8BD5B2AD724280A5ULL, 0x4BAA70895C269127ULL, 0x6B75B32216D21AB8ULL, 0xCA758C21FD55C22EULL, 
            0xA7773F73538C3E01ULL, 0x6E689087E3A694EDULL, 0xF8FD24D723F1B8FAULL, 0x62EA2AB59F46EBB1ULL, 
            0x60DBE416A43ACEB3ULL, 0x5547780FB9308896ULL, 0xC00AF36E09961581ULL, 0x204EF711DE27B991ULL, 
            0x3BF8A0EE3ECDC07EULL, 0xEC1F57AB5972C553ULL, 0x139601B47EEFCBCFULL, 0x9068E4F0E311A87CULL, 
            0x40CB5B7277DFAD33ULL, 0x50AE83D1EB0E99FEULL, 0xD585E162C0865322ULL, 0x3AA7D6FFCA396287ULL
        },
        {
            0x747392B837FC4D6FULL, 0x0EA89D046EB527E7ULL, 0x0CF27E2DE306748CULL, 0xC268261B3BDA5F87ULL, 
            0x844ABB0988B664FFULL, 0x28B3630F67F818F4ULL, 0x88710C79F452BE24ULL, 0x6EA4F2BF9CEBCDF6ULL, 
            0xB6C838A0D91FA33FULL, 0x5F2AB5775BDE6D64ULL, 0xDC835DD2391B4DA9ULL, 0x612BFADEA6E1C488ULL, 
            0x171A1AC23DA8DE64ULL, 0x401255BFA7E54155ULL, 0x2371DC2483650E44ULL, 0x6EF1C8DF205AF4BBULL, 
            0x8E9A33A0DDF59F72ULL, 0x635FBEDC914038AEULL, 0xF261A74553979A11ULL, 0x98AA75BEA8B0D22EULL, 
            0x94378AD6EC7DD531ULL, 0x681AFF70F1849ABCULL, 0xFFFC98E24E54D13AULL, 0x172F5F0C2FDF5D5CULL, 
            0xDA9BA4F8E5EF071AULL, 0x0E30622CBF27AF96ULL, 0x60C91C5D019A08B0ULL, 0xB00FE5C8EAB84A14ULL, 
            0x97602C668A5B9EBBULL, 0x8F7E8DBD48D1D08BULL, 0x183B0D5DE67DBFBAULL, 0xC38B5B1211F4E543ULL
        },
        {
            0xEA104E02B68F6929ULL, 0x39CD97F47193B90BULL, 0x61F5235FD86B9847ULL, 0xDDE27A80A2A4F30AULL, 
            0xFDE8EEAF47E8E106ULL, 0x23E53DAEB9E5C6E0ULL, 0xA19EEDB3AC78FCAFULL, 0x672218422942D433ULL, 
            0xDF0CFAEA85769EA9ULL, 0xF269915F55327FB5ULL, 0x7F75AF794777D12FULL, 0x31816AC793BBB032ULL, 
            0x716548D0061FB1FFULL, 0xA5B0662B60DE7E01ULL, 0x74FD09832DD48D67ULL, 0x125C099D9AAA9184ULL, 
            0x10B80D256ACB76CAULL, 0xDF77E8775939DB08ULL, 0x30F94BC5326FA04FULL, 0x5554035E0A811012ULL, 
            0x205F890D0A637DB2ULL, 0x5B591DA8DC613D7CULL, 0x96D891B7FB20BC93ULL, 0x743885DC91BC75BDULL, 
            0xCC93DD98EFBB9DE5ULL, 0x73CF07D3F1DFAE0FULL, 0x0C74FEBBD2608A54ULL, 0x5B2CF3F7C386C3E6ULL, 
            0x567F24DC6358E280ULL, 0x22369B1A807D82EFULL, 0xE24994A0F1BAE794ULL, 0xDCE33BE674EBB1B6ULL
        },
        {
            0xCF7000F68D4DF85EULL, 0x3F18AB67D59C0F62ULL, 0x8B2F5B0BF894CDC9ULL, 0x2482131E5C3443C4ULL, 
            0xF59BCC6F620F6C64ULL, 0x26BECEB086C591CBULL, 0x99C3C1DCDA15891EULL, 0xC4AE8ED957BC7563ULL, 
            0xAC5F69DD9B4F4318ULL, 0xABAE3799608B31E2ULL, 0xF1907E480B905CA2ULL, 0x9ADD7D7D7574ECF1ULL, 
            0x71751BB968E69BBCULL, 0x26AFF67EB23B8EF5ULL, 0x3D1C58FD49333294ULL, 0xE1A924D6B066DD04ULL, 
            0xEB15BBF681306CE9ULL, 0x4F672932B98E8A72ULL, 0x1B17C4C4A320EF8EULL, 0xDE3CD650BFEB6B57ULL, 
            0x56E091A950560615ULL, 0x183094CAF6C04593ULL, 0x6233FC187B9FA8AEULL, 0x3DE0C03E35E31FA2ULL, 
            0x14469DCC3CC0B8FDULL, 0xAC81A987A9F7B1C6ULL, 0x5102E76B7E5104BEULL, 0xC238335B3F52F743ULL, 
            0x8DCA790ED3993EDBULL, 0x5D42259163A46BD2ULL, 0x37205CF97BA52FF9ULL, 0x362D81B5BD281414ULL
        },
        {
            0x3409533A0EE9D723ULL, 0x398CAAA9E7BAF6F9ULL, 0xB32A97ED06FDEE53ULL, 0x6A42C535EB018AD1ULL, 
            0x4574A9D0AC93B1ADULL, 0x3A97241671948ECCULL, 0xB9F62D438E9DA199ULL, 0x49DD3C31337940F8ULL, 
            0x8BDB7D8494A4199BULL, 0x735D1D332929EEEBULL, 0x79E440FEA95A3BB6ULL, 0x8A762FB8195B92EFULL, 
            0x2D22DE40526C56D7ULL, 0x2C0AE6D56D012C7EULL, 0xA3666B28B5E54243ULL, 0x3232BEDC7CB30713ULL, 
            0xA81B90B45AC0B4B0ULL, 0x456BB90144DBE83DULL, 0x491D1DCBC62B14DCULL, 0x546627187A5B1DD0ULL, 
            0x1D03A3478FAD33ACULL, 0xB5245D131A3CD077ULL, 0x78B9E560CFA01F5CULL, 0xBA4C521AABFF9E50ULL, 
            0x540E7CF7C9FFD0CCULL, 0x62FF01379FC1F9BEULL, 0x7C49A1A96E66CDC9ULL, 0x9D66A010890A1092ULL, 
            0x5DA1009C0BF57A6BULL, 0x0844530F9D1B0148ULL, 0x014F7ABC4A9C2865ULL, 0x6BB337379BBCBC30ULL
        }
    },
    {
        {
            0xB10AC52F66F8E39FULL, 0xBC38E4D6485B6B32ULL, 0x56CEE74E487E7D1EULL, 0xFEBBBF9236B6AB96ULL, 
            0xA44C6D9AD6A4F93BULL, 0x2EE7AF34430E2731ULL, 0xF70F408CA92D7FFFULL, 0x8B10B89C35352B98ULL, 
            0x38C025F201A1AF39ULL, 0x085478B15CDBD000ULL, 0xC22C4B6EA4AE504EULL, 0xFA9DEDF855203E2AULL, 
            0xBB47577C91E56AA0ULL, 0x34F8AD5B94E0B78DULL, 0x9D67352253DA7046ULL, 0xC7E686B0EF7D128CULL, 
            0x2A3792B3419FE0B1ULL, 0x83DB2C17BCAE324AULL, 0x1790448DAFD43DB5ULL, 0xB2243B220FD34F2DULL, 
            0x19BDB73B1EB4389DULL, 0x06A4E00E26DA590FULL, 0xAFD5B104791824DEULL, 0x76079B11BB1CCD96ULL, 
            0xED95AD6026053275ULL, 0x44C91DC45CD343E5ULL, 0x57DC10BEA8B9F035ULL, 0x368BECF78E71854BULL, 
            0xDF5B67897E9A900FULL, 0x507D09F6A591F45CULL, 0xA74ACC15AE65DF32ULL, 0x5BFD91EC0FF2EF47ULL
        },
        {
            0x6D35A327897D8EC6ULL, 0x06F14E3148BEA50FULL, 0x371A57BD8909590FULL, 0x6BF59802793A5F03ULL, 
            0xD899CD586BE222CDULL, 0xF8FABB5917734631ULL, 0x93C6521D22751C3FULL, 0x3ED02C9F8642B823ULL, 
            0xDAAD399B6468D213ULL, 0xDBF3EBC15C168F08ULL, 0x6E1387637095F291ULL, 0xDC500FB36283FCF9ULL, 
            0x6C8C53EE513A3C0CULL, 0x75774F8EE9ED4A72ULL, 0x2A618E2BBCECC47BULL, 0x8303C783E2B8E553ULL, 
            0xC1BF0D0EB110D438ULL, 0xA35B80639B8C9A09ULL, 0x12F9118B94AA0B1BULL, 0x1DFFF7F4FD302A7EULL, 
            0x03EE1E85D3BF02B8ULL, 0xEA98453B7ED5A692ULL, 0x23DE081BB055BACCULL, 0xF6C5904C95853A88ULL, 
            0x58B7FA868CA3F693ULL, 0x1C5D38CD3430E1DDULL, 0x9D37B7F5698750DCULL, 0x8E04AFEFE9719F18ULL, 
            0xF7B5F937D71D3FFAULL, 0x34C6F6C62F7750F8ULL, 0x54FEAC6A305B56CBULL, 0xAD3E6F513D090434ULL
        },
        {
            0xAA89810AD1BBB062ULL, 0x7373F27424D4F058ULL, 0x8E3E8DEB83E5C063ULL, 0xFC38658EEC25CCE2ULL, 
            0x669872C08A3B954CULL, 0x840F025325369CF8ULL, 0xF54D3B59439B286AULL, 0xB78F5BD4F9BE0EB5ULL, 
            0x6862375F763674EAULL, 0xD24B4BFFA4C57353ULL, 0x2E709A065D4E0243ULL, 0xCAEC0920AE7AD776ULL, 
            0x15538947C6BBBCE1ULL, 0x214AA4A1533D60EBULL, 0xF285116071C52EBAULL, 0x8CAD20F9BE74C52AULL, 
            0xC284E517DB218730ULL, 0xA96292FDF23A695DULL, 0xC5AE225B1478E24CULL, 0x902B21AF92CC9B09ULL, 
            0x9040217490B0D752ULL, 0x2AD92CB96EB70B47ULL, 0x75692FA2250328F7ULL, 0xECF47CF3BCCF16ACULL, 
            0x37BC413E7F7672EAULL, 0xBA3889114F77F307ULL, 0xD445E1DC2B02D464ULL, 0x25AA785AC9BAAAC0ULL, 
            0xA544B87517EC87EFULL, 0xDD821D5A47B7737BULL, 0x313569E67CEDA83FULL, 0xE6B99C4FFAC3AC69ULL
        },
        {
            0x2A83E82F31C48C1AULL, 0xB886DCDF67D4518FULL, 0x157182DFA08B47CDULL, 0xFE54A9B01F1D792FULL, 
            0x1D147BDD02730743ULL, 0x3E4CECD81FCC42B3ULL, 0xBFEF06A19998D0B8ULL, 0xCD9EF9ADC5A4213AULL, 
            0xD19332F6B348F12BULL, 0x01A310B7871074E6ULL, 0x1D31519F721601DFULL, 0x87DC3EAC5756CFB3ULL, 
            0xDC9F622184CE6870ULL, 0xA99698BE0861F23BULL, 0x55327ABEAE109819ULL, 0x4563CB3FF4BCFFE6ULL, 
            0xC68A8DDAB5FDD1B0ULL, 0x8E06E946E66221C9ULL, 0xAD0A180C6DA9256FULL, 0xDCAB778CBDA31631ULL, 
            0xFE0C3B98FC2619BAULL, 0xD53F9E378907A29EULL, 0xD5FFAEFF5BD3BE51ULL, 0x00E8FE49B2A6EC76ULL, 
            0x39002EE337E3DDA5ULL, 0x3B495510537AE13DULL, 0x5E6EFD4B588CED80ULL, 0xDC1E1ED298279093ULL, 
            0xA285076EB137FCE4ULL, 0xE9A993844603A351ULL, 0x9349D5C3E49F3AA5ULL, 0x71BE123E2D0B6957ULL
        },
        {
            0x69316F5E9E3F6DADULL, 0x37EF04ECC559D9EFULL, 0x9F9212069BB0A876ULL, 0x1FEBB7ADC87B792DULL, 
            0x00C670566583D558ULL, 0x54DC1BAA8F554741ULL, 0x213D43F2D94A76A9ULL, 0x8F47CD019D7A5995ULL, 
            0xF886B4C402ADD2E5ULL, 0x63B4EEA4807B572CULL, 0xF95745355729659AULL, 0x76704EE6267D9FCAULL, 
            0xBDF5C88E2EAC3723ULL, 0xEEADCD2F4726710CULL, 0xB1ABCBC6A571B822ULL, 0xB80B302791B5C75AULL, 
            0x4941D6527A98839BULL, 0x98D35910034A3A69ULL, 0x7D2B750A2B0A71C2ULL, 0x3A16CF0E682CDB14ULL, 
            0xD165A9F594D3CC11ULL, 0x0048785F84EE9031ULL, 0x0C240D357CAE4A53ULL, 0x26818DA925583864ULL, 
            0xB486A4E9D6A38FC7ULL, 0x501AC816480FCD0BULL, 0xC9D243906D04D394ULL, 0xDAD6BF76E6EDDB96ULL, 
            0xAF23DF2716593E91ULL, 0x76D7FC05B275C251ULL, 0x24CAC37C63E1B31AULL, 0x1E2EBD7C8184114FULL
        },
        {
            0x32E209FA0AC2759EULL, 0xDB55E88ACA08FEC2ULL, 0x42B2F4F45AFA1E1BULL, 0x4EDBF56D18D87E04ULL, 
            0xBB6C637A9FEDC4CDULL, 0x498A64BD4A8047ECULL, 0x72A3292D6EE377A3ULL, 0x659BC52815201F33ULL, 
            0x0DA9326F55744841ULL, 0x7F0CE065F74435A2ULL, 0xC608434773F333FAULL, 0xE37E09715156ED79ULL, 
            0x0160E2032795AA15ULL, 0xF755E3F1387F4200ULL, 0x860F0E52A2B13EACULL, 0x0D3C4E75A8AAECDFULL, 
            0x2C67CA280E4F971CULL, 0x14ACC68E61E12F69ULL, 0xAE96A628A7B85CABULL, 0xA4A7254150E796B9ULL, 
            0x5C5A0206D555C363ULL, 0xB4D82F9A1E0287A8ULL, 0xB7EC4BEC428340B9ULL, 0x51AD480B6C4494AEULL, 
            0x7D528804AEDCF483ULL, 0xE35153E54AF433DFULL, 0x91BE95F799472114ULL, 0x0233BB6E99DB706AULL, 
            0x78A3B230708C8019ULL, 0x40F392023214B0EAULL, 0xB5FC3C466D707D47ULL, 0x4BF6A1359961D81EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseCConstants = {
    0x7F69CF7F811C5B73ULL,
    0x6C58C1970694799FULL,
    0x0E91893E92E4556EULL,
    0x7F69CF7F811C5B73ULL,
    0x6C58C1970694799FULL,
    0x0E91893E92E4556EULL,
    0x59D938F20195B605ULL,
    0xF69EE83F3ADB890BULL,
    0x12,
    0xBF,
    0x0B,
    0xE4,
    0x77,
    0xC0,
    0x3F,
    0xAB
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseDSalts = {
    {
        {
            0xAFDC52C7ADF172B5ULL, 0x3B64CEC894A54D2DULL, 0x107ABA8EC0C2D8D4ULL, 0xAD5A5E506A3EDE5CULL, 
            0x67946DF9E5367B73ULL, 0x016DCFAE3F2600C2ULL, 0x08BEC048C16D3F37ULL, 0x21D0013C6433D12DULL, 
            0x8579D68A64BABDCEULL, 0x39E351FF34C532E1ULL, 0x650CA5380ABFAD39ULL, 0x8B829B4B909CA77EULL, 
            0xAAA9543984739EBCULL, 0xDD29F1C4CADDF66CULL, 0xE3B7087FAA419A12ULL, 0x406DEA476D189E88ULL, 
            0x2B5128795AF98205ULL, 0x9BAD3C6442DBCB4DULL, 0x9D04148E3EE22CFBULL, 0x9150F66F106D5D43ULL, 
            0xF672166AA40C7175ULL, 0xEE101D0F1DE67813ULL, 0x4248EFC5C6595460ULL, 0x48E724F6CCA64FF8ULL, 
            0x814ED84ECCC4F635ULL, 0xF978F1A8827A7478ULL, 0x466BAC2CC7603337ULL, 0x97CB9F639D96A446ULL, 
            0x067860C12EF31F6AULL, 0xB32DC4389CA5CD1BULL, 0x1F922A67971C7D94ULL, 0x47BA80C090BCD64FULL
        },
        {
            0xF59DF91696E0BD72ULL, 0x4BBAA5FAC194A704ULL, 0x4DD3EEE969E13036ULL, 0x50BA4AA0A7F0ACCFULL, 
            0xD125D9398D97C257ULL, 0x43DC83F91044FEC8ULL, 0x4DD282E79DAFB9E7ULL, 0xCCF76281F0181E9CULL, 
            0xA2E270A098438951ULL, 0x05ADBBA32F10F302ULL, 0x7DB58D106AA0B5F7ULL, 0x37D6D298F1052639ULL, 
            0x53BD8EA41A62D9F3ULL, 0x249B5546C4DCEAE1ULL, 0x04F800E54C4AF2D8ULL, 0x41BF35F616417E2BULL, 
            0xC732B0A890AF90FAULL, 0x6AA0C8EC5B7C8646ULL, 0x0CF79CCCF6BBFC34ULL, 0xC1709E53825267E9ULL, 
            0x356217C9B27249CAULL, 0x57E16B73CB9F0AD9ULL, 0x15B2B6A877D01803ULL, 0x7A0BEBE9F3616E83ULL, 
            0x3152EB46A30C31ADULL, 0xE3A3F28D6181A3F6ULL, 0x80FDF250A633658EULL, 0x5E36DD239D5E2886ULL, 
            0xA062BC127D33F730ULL, 0x1C281CC334656374ULL, 0x192478C490BF6CF5ULL, 0xD8D0F67566AD5CE5ULL
        },
        {
            0x0CD8867572D483E8ULL, 0x35F9742DE8B86148ULL, 0x4B0051546CD65B7BULL, 0x99C868AFC502AE83ULL, 
            0xB98AEBA1A75ECB65ULL, 0x458E3732890031C0ULL, 0xD7AB6036860D40E9ULL, 0x0F0B51B62934BC9BULL, 
            0x88DF9283B66BDA6DULL, 0xB082E76B07F44575ULL, 0x4E2FA436ACDA1B42ULL, 0x0063FDCDF44C7FEEULL, 
            0x467BDBE7C589C879ULL, 0xBA3C48273FA5EBB4ULL, 0x2F1D5C8DF504862BULL, 0xA2D1F1A4AB2C050BULL, 
            0x54C15C1A09D119F0ULL, 0xD21525CDBCD0A94AULL, 0x30853365EB2982FAULL, 0xBE589329FBB37CB1ULL, 
            0xED738EDD1A6C5F9BULL, 0x86B1C5BD3C747FD0ULL, 0x819F2A35314EA980ULL, 0x1442823F5BC353C3ULL, 
            0x745F44349E1A5897ULL, 0xE9F5DDBC934CB434ULL, 0xE535792A15D2C96DULL, 0x0081AFC8226D2545ULL, 
            0xBFED8287EA9F8308ULL, 0xD995F627C79BFDEBULL, 0x18C8A71552D10A05ULL, 0x7DA7E29549C8A35AULL
        },
        {
            0x37824BDCE2D15A4DULL, 0x6DEF2F89FB912894ULL, 0xCC8E9815DF3CB90BULL, 0xABD1ECC1165E4B77ULL, 
            0xA862D8E1C62C623DULL, 0x96E5B45D61F4C9A2ULL, 0xD4A6EAD5839A7492ULL, 0x1AA5DF267F2647F6ULL, 
            0x3EC756B68A273890ULL, 0xCAFA8ABD24F1CDBFULL, 0xE1D85F67098BB790ULL, 0x51577DE21D1B67B7ULL, 
            0x841C019DCFB126E7ULL, 0xB87C2FE1DFFDCA8BULL, 0xD921E2B3221BB080ULL, 0x0C585BB0951E918EULL, 
            0x85DECC5F24651124ULL, 0x37643CC553EED602ULL, 0x698491224F4CCCA4ULL, 0x5E487C215E32C8C8ULL, 
            0xE52BBF9232F5901EULL, 0x8A964D27236B1447ULL, 0xAA7C18768B678718ULL, 0xFF48E1DED151FB2DULL, 
            0x1E1C313FC0A40A82ULL, 0x38ED3BB02615A1DDULL, 0x4057DAEF6D7072B9ULL, 0x66BD7C5210D3C033ULL, 
            0xA3DC36CBED25F9B5ULL, 0x204CA915BD1B3C89ULL, 0xB05BE20578B24354ULL, 0xCE02A9B806705371ULL
        },
        {
            0xCA417CACE82A9928ULL, 0xCE5EFAC9F667B1CBULL, 0x98542B9711BCCFFDULL, 0x7E4DA7807558A8AEULL, 
            0xB8A3B44CEFA6D696ULL, 0x233DE90899CCFBC0ULL, 0x8DD58F2E1326EC4EULL, 0x065AAF17F83E5029ULL, 
            0x0A8C2C323601069FULL, 0x58329CD3CE236BB8ULL, 0x9351C862DCCDEB00ULL, 0xBC1AB5E0D36CC098ULL, 
            0x442F529A7088F352ULL, 0x1876CC00C1DEA0C1ULL, 0xDDAABD48FBA34102ULL, 0xB76E2CE151390816ULL, 
            0x3362C5210946D656ULL, 0x0518341BC1298C88ULL, 0x8A5440CAC2F261CAULL, 0x22B17E28AADC362AULL, 
            0xFB62196C34DC7035ULL, 0x4D9A80B82925E82FULL, 0x3611756EA42B8F42ULL, 0x758BDF2B09A49397ULL, 
            0x55C8D3BA90107DB3ULL, 0x42C25194512539D2ULL, 0x973A91D3755AFEEBULL, 0xE0C2347722F16FD8ULL, 
            0x2D8FDAFF9A192438ULL, 0xC0D8F8FA7B74AFF6ULL, 0x66618DC8DE590302ULL, 0x0894D0808BC689DFULL
        },
        {
            0x7E44528454EDD406ULL, 0x05B0678BA6851959ULL, 0x7466E5BEB64BD0CDULL, 0x3BC491A64F8DC3B4ULL, 
            0x9625633CBA7F0A25ULL, 0x25B7BA96C5226F06ULL, 0x7CFC3DF5BD369AEDULL, 0xD5D4B4F72376B206ULL, 
            0x7C6F8BAED3935F91ULL, 0x0F8EB8EB7A744FD8ULL, 0xCFCFD445393D5D8DULL, 0xD0BFE2141D13C2C0ULL, 
            0xE4802843E29EF8D1ULL, 0x2B6D48DC0EDC1509ULL, 0xB7F3E24556D35A6BULL, 0x55C982145B298438ULL, 
            0x66B89EF9DC7908F8ULL, 0x326A1588BFCF9D38ULL, 0xCAB96AD7EA7FC3D1ULL, 0xAC19DD886FFF84DEULL, 
            0xEB9A8719F9C3C453ULL, 0x841DE046F462D06EULL, 0x1FEC1E01CC1ADF23ULL, 0xDE426AEF3F68CC0FULL, 
            0xC064AB054557FCD4ULL, 0xA5B3276DF00C098EULL, 0xA1274B94FF8C02FCULL, 0xAE70A343F6978F39ULL, 
            0x97A6F0754379FE3DULL, 0x9ADDB1A67A5E1B33ULL, 0x59A43A6935E11152ULL, 0x89FFBF75C19D5ADEULL
        }
    },
    {
        {
            0x0F8AB8C38D8E362DULL, 0xE7057999032584C6ULL, 0xA7E5EB38DCB84D08ULL, 0x4AE33C5638121385ULL, 
            0x758AD09E4A2C844EULL, 0xD7F3A80E65E8333EULL, 0x5B96627AC9D3A3FEULL, 0xBD57AD040B514AEFULL, 
            0xE8F50506955D94ECULL, 0x4352DFD9FE7D76B2ULL, 0xF9DA59A9C9ECFC2FULL, 0xC74FEB148CA2F8A0ULL, 
            0x5FBFF79F20427FE6ULL, 0x8DD492ADAB9850FBULL, 0x783F77CB9F38A5D1ULL, 0xC7836286226D359AULL, 
            0xB79719BB0951E11EULL, 0xC76675993F238B87ULL, 0xD2C902104D62A3CFULL, 0xE4F7A20DBF988DDAULL, 
            0xAFB8B743C9493EFAULL, 0x40DAE27BFE8B85B7ULL, 0x835309F608C9C4D8ULL, 0xB003D042E6C9C311ULL, 
            0xD614DF639C341C19ULL, 0x8131C37AE2571BD5ULL, 0xC772C78AED7CC7C7ULL, 0x8BD67C145D7B6541ULL, 
            0xD4403D846AADF88EULL, 0x803B7AAAB0425422ULL, 0xD96E2CFA1AB92935ULL, 0x9343213C2F3B96CFULL
        },
        {
            0x79573C41A787A266ULL, 0xDA10418D7C02EB72ULL, 0xAAFCAD75CC2424DAULL, 0xDDFFE2D7621C5B97ULL, 
            0x0BDB042B31C2D19AULL, 0xFEE9A47B18B7548AULL, 0xB3E2F22FB75FA045ULL, 0x59BD9C44D5715A36ULL, 
            0x196DE3C429AE514BULL, 0x03262A106555D8D1ULL, 0x100780A68A6C1195ULL, 0x617C3325A8B626B3ULL, 
            0x89B68C63FAF9EA6EULL, 0x379AFE5D151C8D72ULL, 0xA145F34A1B16A5BCULL, 0x7B62CA6C63FD2E5FULL, 
            0xE2837817F0432747ULL, 0x5C89822873464B1DULL, 0xCC3282E78882FA4FULL, 0x94588D73E3902235ULL, 
            0xB7664CACBB207BDAULL, 0x7B12E0A99AA6BD1CULL, 0x7620198EF490D372ULL, 0x80319AECEB33220FULL, 
            0x9AC8A721F8280615ULL, 0x2E147C09C16E14C0ULL, 0x649BB03CA40DAE3DULL, 0xB48284010A8E4966ULL, 
            0xD84204C335966550ULL, 0xF13D7B8377BEDE45ULL, 0xB98DE90E0189BA3FULL, 0x11A899F0899F30B7ULL
        },
        {
            0x0B5BA3438C21D4A1ULL, 0x64AD4F8F785CDFAFULL, 0x2D833DAC67A49972ULL, 0x9C22611CED1FC472ULL, 
            0xBBB1E037F445D922ULL, 0x05F701415A0D1383ULL, 0x1B9C882E326FB9C7ULL, 0xDFE0EAC24233AB37ULL, 
            0xDB93067E3A5E0DF3ULL, 0x000A770EC1C3A585ULL, 0xB7A8012CB1406124ULL, 0x78C4C0C67A893F13ULL, 
            0x8CA2A043ED5CC59DULL, 0xB3E149C486390BC7ULL, 0xAD6BD2057B3666A2ULL, 0xA0C406396DA3DC70ULL, 
            0x39B7EADA64EC2162ULL, 0x8F1597AA80E17534ULL, 0x6E220D6F9BCC3535ULL, 0xC909CEAE0CF34F76ULL, 
            0x4CA20B871B9C1C9DULL, 0x047200D69EA8A37DULL, 0x17E7348C37C36C08ULL, 0xD2B70BFCD5EA7BCAULL, 
            0x797034EB3539544BULL, 0x8D20B60349845E50ULL, 0x178FFFD1D4AFF1C6ULL, 0x28CD8890B66F9837ULL, 
            0xEE0CA810DEDF1498ULL, 0xF755C2DF5CC51937ULL, 0x30CDEB619D7EC8ECULL, 0xCDAD852681D2967CULL
        },
        {
            0xC2D57C7724B658E9ULL, 0x2E8104EB7B4F7308ULL, 0x1560DE89C73DEF68ULL, 0x01EC0545F7EB8A94ULL, 
            0xEB5480138E04C8AFULL, 0xA26D27D4A2D6811EULL, 0xBA492F7A792D2F70ULL, 0x5EB93D2A525119E1ULL, 
            0x42A08F7E7A98E5E2ULL, 0xC3D3DF0D7799D1C3ULL, 0x81EC53ABE439266DULL, 0x3695ACA8E716EE47ULL, 
            0x863CE9BC0628349FULL, 0x6A17EB9E2CD74A15ULL, 0xF22157F76D445A86ULL, 0xF1A55C7317F5A0B5ULL, 
            0xA6F3A7CAD8478981ULL, 0x2F99D85D1B558B70ULL, 0x00A88BCC1754C933ULL, 0x608F6B824E0F8AD7ULL, 
            0x8445D424E9D51F9CULL, 0x2D0082325E9B009EULL, 0xF444E09F63E83183ULL, 0x6D9766FEC11043CBULL, 
            0x9C5795FD9CBD9C6BULL, 0xE37CCA8A2CE22177ULL, 0xC00B173F45C7E45EULL, 0x14775D03E7A98A24ULL, 
            0xEC504F137125DECDULL, 0xA8031C2A4E61CAB4ULL, 0xB7CAFA289E1DEB94ULL, 0x5F68422AFD59E7BDULL
        },
        {
            0x0258B3267B104EE7ULL, 0xBF7DEAB9D8DB9ECEULL, 0x0C8452A10B479C1FULL, 0xD44073DECD4EA0FAULL, 
            0xCF57CA6B39A860A6ULL, 0x3A13C935B32EF8EEULL, 0x91804269D554E84EULL, 0xD93094B50645F269ULL, 
            0x70FE6E940A64C65FULL, 0x48DFAEFC145930C3ULL, 0x487AEEE6AC39A028ULL, 0xA21F96709CECCBE4ULL, 
            0x2CBEF35A63BC7787ULL, 0x63CC46975DE633F8ULL, 0x9A02B2268D417F53ULL, 0x116806446BF2AC88ULL, 
            0x30FF8ACEAFB572B6ULL, 0x3B4C92D1EB75664DULL, 0x5C1E046095F6629FULL, 0xDFDB953EAA005691ULL, 
            0xFFF94214CF53A094ULL, 0x624DB80B33D940A5ULL, 0x4BE50AD46A49A0A1ULL, 0x04E3F0DFF8C14B33ULL, 
            0x7094FF5FFA30ACA1ULL, 0xF72A2193FE5D12CEULL, 0xFE228C0E672F39BDULL, 0xC71D7F3930CB1CDDULL, 
            0x9FD8641B9FC95C3CULL, 0xA95C858C3398CCCAULL, 0x21EDCFFB8281D01EULL, 0xE66C9E753A204BDCULL
        },
        {
            0x37C128FA8F3C3465ULL, 0x68C39F45B5B7C9CDULL, 0x3A6E0901B2ECD433ULL, 0x3333AFA748758266ULL, 
            0x953277D2FE692CAFULL, 0xB4C79D65029D4FAFULL, 0x3132F9BA73DA44B0ULL, 0x585357DFEE23B560ULL, 
            0x187AD63F7F0C804EULL, 0xD8FAC2AFA82252D0ULL, 0x2AA6EBE6A2ACA8F0ULL, 0x151CED58A9577370ULL, 
            0x9985CE3DC384290AULL, 0xDD48AC7D0D993E0AULL, 0xEB571B262438A4ADULL, 0xB44C7D5396E1308EULL, 
            0x27F34477CA819361ULL, 0x274FE8D35A6CDAC5ULL, 0x3C88F4B4EC8B547FULL, 0xDA92D9747DA057C7ULL, 
            0xB7D8FF848EE8B1D4ULL, 0xA766A47CCCEDBA67ULL, 0x87208784E0FDCFF8ULL, 0x510D14C20DDB42BDULL, 
            0xEB1B3FBC12A2068DULL, 0x29B7F011E16E87CCULL, 0x98F4B7AA00A456A3ULL, 0xE6B42DE910BFC830ULL, 
            0x44B35D0CC8A8686CULL, 0xA3986953B8249770ULL, 0xD1989AF8720F38ADULL, 0xC9FF1DFE6AFEFCD2ULL
        }
    },
    {
        {
            0x336121D1E7654557ULL, 0x1377EBF187417E35ULL, 0x26812BE22E3FDC32ULL, 0xAC4DAC22D079559AULL, 
            0x86CAE570357AF3FBULL, 0x8CC369CF1B230A7DULL, 0x5B959D8262C1B1CFULL, 0xC38BB4AF63891E84ULL, 
            0x9BFCA5CF210CD7CBULL, 0xC4F16BF1F518CF89ULL, 0xE43DEAC4250BAE54ULL, 0x3DC6F688B63592AFULL, 
            0x3061FABC7912BC44ULL, 0xD2C498C522601A69ULL, 0x94BE5104A42678C3ULL, 0xF0E02AF158FBBFCEULL, 
            0x4B8EC83D68482E4CULL, 0xCC986AACF315C45BULL, 0x115C1A2174A2E5CCULL, 0x98C8C5E7C394B715ULL, 
            0x102E4C833C3249F2ULL, 0x39E926A50F17872BULL, 0x961A5D3837DE692CULL, 0x7F0AE244133019C1ULL, 
            0xD488FFA1CFB3F77AULL, 0x8359CECA4CB43B4FULL, 0x76F4CCA5CA32003EULL, 0x530E9E842A644755ULL, 
            0xE373D3143A578DB4ULL, 0x783FC8EFDD024B2EULL, 0x11487C915785BAA2ULL, 0x01F4F44227BFC687ULL
        },
        {
            0x8E52DCB94F4D8134ULL, 0x47E078548F48A923ULL, 0x08F18D58FF169EA3ULL, 0x232819E1DE146D13ULL, 
            0x607ECEC7C8996083ULL, 0x775667E4C534E33EULL, 0xD4F012779F30A89AULL, 0xC58D24D747F7FFAEULL, 
            0x8BCA8787916A947EULL, 0x605A1C34CE13C76FULL, 0xC324EF78BAD884D8ULL, 0xFA87D4B0C18E32CAULL, 
            0xF1386AD9C1B8CA51ULL, 0xC466602D55C65C10ULL, 0x12CC0988F6A5C71FULL, 0xD6089035E0414C4BULL, 
            0x7B16710F565DA1AEULL, 0x03EB755CA391A86EULL, 0xF055938E217DA9FAULL, 0xD92509E5E44A74A7ULL, 
            0x97C81F6F9BC8694DULL, 0xAB1C6D189B4E9C15ULL, 0xD8235F63384C352BULL, 0x23DE2725A0B650FEULL, 
            0x38C74DEC89D65C5BULL, 0x1DE93968856940F9ULL, 0xD3674831093DFF74ULL, 0x0B079EB043773C4DULL, 
            0x73683E51DA67BCECULL, 0x10E8185213415A4BULL, 0x6C32C63A0FAD5E4CULL, 0xB091329270E56845ULL
        },
        {
            0xF684D25239B80564ULL, 0xE7C288C6078C3C76ULL, 0xDF28758EE3950B6CULL, 0x6EC850DF30B40CE1ULL, 
            0x9D13AEE57DC38006ULL, 0xEBED30340DA2EDEDULL, 0xD64ADA991C54B277ULL, 0xBF991E598EA43799ULL, 
            0x277DA27ECEB8784CULL, 0x4BEDB907C301F3C0ULL, 0xCB48BD21DA57E5BEULL, 0xFAD10530A322043DULL, 
            0x695E20B761ADC7E7ULL, 0x88A3B180673B6869ULL, 0x96F3379E7563E1BBULL, 0xB72D724CEF6EA2CEULL, 
            0xA4A1EE9216694D63ULL, 0x3E58E5A4FB1A4AF8ULL, 0x8194E51C0574E367ULL, 0x2B07B2A980815E45ULL, 
            0x271961848BF4D2D9ULL, 0x7A119ACC6A9F0779ULL, 0x71EE615E32BB015FULL, 0xAF748483DA339F7EULL, 
            0x99A7716FBFCD51C1ULL, 0x80243C2D9E4E3EC8ULL, 0x00DDDB68B20AC49CULL, 0x66863443AA3C67CCULL, 
            0x96A9592F4F795CB5ULL, 0xDEF882F08E3705C2ULL, 0x2E97F3539F75439CULL, 0x0D0E91F5220543E0ULL
        },
        {
            0x7D0EDC9F9548334AULL, 0xD37A944DC821E59BULL, 0xBCA7230E417AADCBULL, 0xF4A9EBB807526BE4ULL, 
            0x8FC088BC5B38287AULL, 0x4DC99F61EE78A055ULL, 0x981BABA924868E1BULL, 0x3315BF92961F50B8ULL, 
            0x534F9CB70B9B16AAULL, 0x34280575E9F50AC1ULL, 0x304EA5B3D01E6E2FULL, 0x3971D0660656DB48ULL, 
            0x6F2983E1F0EFA588ULL, 0xC5F701C5222E135EULL, 0xCD3A919A02ADC3AFULL, 0x17BA778A7023826BULL, 
            0xB3215D405B588A3BULL, 0xD03761FC1C6C7CBEULL, 0xB3DCC269757DB351ULL, 0xD7704BC5157D5DDBULL, 
            0x2EC49891E823C4CAULL, 0x463EF54498B37C60ULL, 0xFC551147C0228434ULL, 0xBA2A27B60D25DC7EULL, 
            0x911BB95FD4970339ULL, 0x878EFD86D71CAEE7ULL, 0x53321F8513F63460ULL, 0xD6740A4BD3585B60ULL, 
            0xD2326190FAC08EBEULL, 0xC4356D73FCEE3334ULL, 0x07837B161797D665ULL, 0x04071D5247025C49ULL
        },
        {
            0x173945AAB1535F4DULL, 0x870BF7F919CD970EULL, 0x22C37C95BAAF02AAULL, 0x9A8A2C8A7E470F23ULL, 
            0xD0E88057A77C0F0AULL, 0xE28B4DA1F4FF81CEULL, 0x7D2FA0059E3679DDULL, 0x8CCB1D9E3C3B7EDEULL, 
            0x90BF66A74BF36D2CULL, 0x44B482855BF4755DULL, 0x20CB49306616BE9DULL, 0x4D6003663B9214EDULL, 
            0x324C021DA80BC5B6ULL, 0x6ACD8A1E3E77E086ULL, 0x981FA65EB06162CBULL, 0xBE3C64499795E4E3ULL, 
            0x48425E0FE98F600EULL, 0x39B3E6587019A95AULL, 0x98961C9C7358F948ULL, 0x4163B3B6B138E3F4ULL, 
            0xFBFDF97955B6F60AULL, 0x6550897DAEE11ADDULL, 0x8DBCB001A7B5BA0BULL, 0x7FFFAEBDB6E1A958ULL, 
            0x4A163A1655A4B63DULL, 0x048385A8A0E72FE9ULL, 0x62A16833A231667EULL, 0xD49C4A307F15CFBFULL, 
            0x03AD91C44B1F176BULL, 0xF347FFFD84C3B6CDULL, 0xC182377DDB14BB58ULL, 0x3362F6F734ED9440ULL
        },
        {
            0xD0F15BC5F3F2ED29ULL, 0xA99CED6A21737FE9ULL, 0x04B050B97BB0C820ULL, 0x43A8F4122E0EF475ULL, 
            0x3772AF6BEFAE75BBULL, 0x3EDB6553427615F7ULL, 0xBE7315D524413DA8ULL, 0x2844CFD73E7906EEULL, 
            0x9DA3054BD6C3A528ULL, 0x08CA531161692779ULL, 0xAE62336C2718EC0EULL, 0x12C02772B3375AF4ULL, 
            0x18681E4D0CB1E505ULL, 0x4ABB8CD178EB7F1EULL, 0x136599C5ABEAB9A9ULL, 0xCC9E4EEA0D295D01ULL, 
            0x81ECA4117110A587ULL, 0xAE839FEE7F87799AULL, 0x9D3434029B4B41E6ULL, 0x8135253CB6BFBD73ULL, 
            0x559B0B06DC7AB5B5ULL, 0xB5A244EA8F00DD90ULL, 0x40E41440B0342B87ULL, 0x9845C8EFB054DC61ULL, 
            0xD34651FFE5F2107BULL, 0x2483E9198F85F73AULL, 0xEE006FE87FE91A73ULL, 0xFB7D248AE073636FULL, 
            0xEFF6EC7EB8D465B9ULL, 0x529F3385AA350F00ULL, 0xF36EDB862FD709F4ULL, 0x71268F887D3F9CB8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseDConstants = {
    0x560303534D2ECFF8ULL,
    0xF987E05C438E8B4DULL,
    0x9F606D1D6C8D79A0ULL,
    0x560303534D2ECFF8ULL,
    0xF987E05C438E8B4DULL,
    0x9F606D1D6C8D79A0ULL,
    0x34D3878467CFFDB9ULL,
    0x66C55D3B9D84EDADULL,
    0xF5,
    0x76,
    0x1A,
    0xBA,
    0x06,
    0x48,
    0x36,
    0x66
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseESalts = {
    {
        {
            0x33B385AC2814C207ULL, 0xC70DE4809E5CA177ULL, 0xF00774A66F806D8AULL, 0xEA095E918B53C4E9ULL, 
            0x375A94F5177DDE1EULL, 0x730F0A4A5202D92CULL, 0x77AB91EB5EFB3466ULL, 0x0C5E10EBCFFCA91BULL, 
            0x724B435B803BFD19ULL, 0x53AC6D0338E6B5F9ULL, 0x5CF58EEC66AF8035ULL, 0x8CBFD56207F5A797ULL, 
            0xFD4CB9238EA1831CULL, 0x9F8C3C2427915860ULL, 0xCFEDB51557AA254CULL, 0x147E0D36EF3D8721ULL, 
            0xF4F13DAA90A69C75ULL, 0x41BAB5C18FB8AB1EULL, 0x8A13D97D528E64AEULL, 0xD05607CEFCAA9160ULL, 
            0x090AF61604E92F90ULL, 0x83910A4EB5A3EF8DULL, 0x1FF96D07D761697BULL, 0x0B175D72AA924E1BULL, 
            0x5C725BEA43EFB3E6ULL, 0xE14FE047F1DB00FBULL, 0x2D7C46A50A240C4CULL, 0x1C27CE12A3ECB785ULL, 
            0xA6D7709DAC0E4B3DULL, 0xB315E727D172D401ULL, 0x60AB7A8D55058526ULL, 0xC961F6B627F945B5ULL
        },
        {
            0xE539BEEC6406B117ULL, 0xB404BFF897F787D5ULL, 0x1759330EF286BE05ULL, 0x7BA7AAA0B6EF5E26ULL, 
            0x354960B96553FA7BULL, 0x933B8859817FA761ULL, 0x9930D75DA8722ECBULL, 0x8948D9A24BD1355DULL, 
            0xFD7DCD643B6E6F0BULL, 0xC34F1E587969CD50ULL, 0xA5E8D4A18E980C45ULL, 0x4CC2C208B60B8795ULL, 
            0x46FC49A0C5DACC6EULL, 0x4BD226C632B20D48ULL, 0x6DCEF51E1865BF2EULL, 0xE326C028495FC913ULL, 
            0xFABB3098C59BEB0DULL, 0x0EA29B92AE266E75ULL, 0xA8F3FCA76A6091C7ULL, 0x258011CD30783CB0ULL, 
            0x66D507B1B203E837ULL, 0x414E130811BFAF1DULL, 0xB7657EBD2B2891EEULL, 0x19B03CD56D3AB289ULL, 
            0xA892EB62B47A1D11ULL, 0xD2386F74ACFDDFB7ULL, 0x4A977956E88C5352ULL, 0x9F3ACE85FFA757BDULL, 
            0x7A35625E9E1BEBD8ULL, 0xFBEBA31DA23A47F4ULL, 0xFCC24AF5609257D2ULL, 0x2145786AF3840511ULL
        },
        {
            0xDC39BEAB3036D256ULL, 0x3AC01DFB84C75CDCULL, 0xC6893C55063951B9ULL, 0x84F894E8F86E09CCULL, 
            0xAC01F23BCED1C1D0ULL, 0xBE53D567BA9DE2C9ULL, 0x473B3205E5AE60C3ULL, 0xD252C9726DAAFE2CULL, 
            0x6535FAB5A75A8DAAULL, 0xC30002F381B28FC8ULL, 0x2C1687D54477E5C0ULL, 0xA7061F66004C770EULL, 
            0xCB098DCE82403BE7ULL, 0x275FAB8649254274ULL, 0x3FF29E7786D9BBC7ULL, 0xB826D9222225D81BULL, 
            0x4705400B7E8A4D90ULL, 0xAE0852B7E196E942ULL, 0xD362645279BED631ULL, 0x8F7CCC60966DF292ULL, 
            0xA504383C0B686D2BULL, 0x1B3068690915E2A2ULL, 0x5BE4CA3F64CDBC1CULL, 0x5FF3D65CF70FFE36ULL, 
            0x35909A1E511E998CULL, 0xB9CAB2DD4F8EC166ULL, 0x27A22331673FF5B7ULL, 0xB17B67FF915C3794ULL, 
            0xFDD9461D4FC769ADULL, 0x4C1C18FD4A45D2F6ULL, 0x4046748B5F8C28D8ULL, 0xCD5860E3D8A95B8BULL
        },
        {
            0xB5F410C964940633ULL, 0x8807503232CE6D94ULL, 0xE83E0911315C4B47ULL, 0xCCBB9FF962AC99AEULL, 
            0x60F0816BA081461EULL, 0xE0FE9B3E88F11597ULL, 0x1A6D4EE427FBDCBBULL, 0x4E6707176FEA6205ULL, 
            0xAB2155525FC77AC4ULL, 0xB08F0DB585B4F9B2ULL, 0x0BABF0E1153114F2ULL, 0x80A98540305A83B7ULL, 
            0x97F0A7C51353F01CULL, 0xACC09B0E9FD02685ULL, 0x1BE047F56F32E50DULL, 0x15ABE5DA12CAC5CBULL, 
            0xF2FC5B3B1D2578A1ULL, 0x086DE9BC740D9A0DULL, 0x08D5F78B32661693ULL, 0x365F1946E1AA0E34ULL, 
            0xCEDF1653B34189DDULL, 0x792FA21B73366B4EULL, 0xE2ACB3C259A53340ULL, 0xD4A9DADAEBEF51BCULL, 
            0x5831D6703C1C0918ULL, 0xEA93905E96332239ULL, 0x0BD1AEA42A800E0EULL, 0xA950B80C3A6B6A18ULL, 
            0xEA9AF69D7DCF62ECULL, 0xB9D6C187BD4672A4ULL, 0x6A21AD2962A404CBULL, 0x124B6C211011F287ULL
        },
        {
            0x3D84FDB3A7C34CF0ULL, 0xAE759C57BAF6E880ULL, 0x159414DBF61CC52CULL, 0x184006DB75929CB3ULL, 
            0x5A321CAC1C3DCE38ULL, 0x1EC8630A73AD417CULL, 0x21DFB1425E839DBCULL, 0x378941C54D0E50F9ULL, 
            0x9224040D3BA73D5AULL, 0x513B55ACF40BCE6AULL, 0x837B04D8C9909C37ULL, 0xBBFE2A4D91B70167ULL, 
            0xE40081B676B1965EULL, 0x236AEAA22A561DB4ULL, 0xE5AD1E4BD6EDA7D1ULL, 0x0E32283FEB64893CULL, 
            0x3D48087EC6DB9336ULL, 0x361F60C75A327F0DULL, 0x25BA0539BE30B5A1ULL, 0x9B91244ECD7474A2ULL, 
            0x0A98D0E8DC272D3FULL, 0x33917DFDB707806FULL, 0xAAB4408CA00D4FC1ULL, 0xBB30162F6B4D46E8ULL, 
            0x06860FD13506B0DEULL, 0x835D9CB1B0693E04ULL, 0x03C88E55BC5664DFULL, 0x643A27FA383B1892ULL, 
            0xCE7FF5C57CBD1985ULL, 0x510965C6EDB7067AULL, 0x0DD5DDC40407C2B1ULL, 0x30FAA2557CD3E7E6ULL
        },
        {
            0x27C433D539BF47ACULL, 0xA598A9EFF77CFC61ULL, 0xFDEB551518FF2D35ULL, 0xE9C4560780487236ULL, 
            0x627FB5F445A069E5ULL, 0x7B3701371BA17001ULL, 0x5C3C804BBDA8727BULL, 0x730DC5298526BA8EULL, 
            0x8B573B11FF4E44E5ULL, 0x4BB789C7DC27246EULL, 0xD1B69FFF79F74B87ULL, 0xAE7E5883D065E11BULL, 
            0xD8401236B06A649AULL, 0x6557298907891C7AULL, 0x30EF87643D05E56FULL, 0xECBAADF1E9274F81ULL, 
            0x885066754E265432ULL, 0xFE6B7C63C3C36B56ULL, 0xD65CFE7DA1CBBA02ULL, 0x311989CBF8BF46BAULL, 
            0x6D84A8420EC4E0E2ULL, 0x89DEC410AE52A677ULL, 0x888A22265D5D3E59ULL, 0x0720BA6542C3767EULL, 
            0x0760BC21C115D7B4ULL, 0x58F44EA7FADB9A0DULL, 0xCEC8A1DA0041B336ULL, 0x39B5F130F82B020FULL, 
            0x658A8D8C28ED21D4ULL, 0x9B8018F76E4DE001ULL, 0x7BF2E9D751EB5E39ULL, 0xD52B61B708F885A4ULL
        }
    },
    {
        {
            0x2DCA016606324703ULL, 0x66F61393118A14E9ULL, 0x03B0AEC16A9EF0C4ULL, 0x48CAB5FF36DB4805ULL, 
            0xEE0FA08CE3F67351ULL, 0x9F891FA449B28744ULL, 0xA031445EDB899AD1ULL, 0xEF3F7B25C1613BD9ULL, 
            0x07C37792C6CE4DE9ULL, 0xEA92B6C266EC5B70ULL, 0x89F85AA2EF6D7B21ULL, 0xB2F17B22A7905785ULL, 
            0xF951452523576701ULL, 0x5E98824DCC68F9E7ULL, 0x8387FD0535133E9AULL, 0x77B700A39B5E71DBULL, 
            0xBB1466605BCA32FEULL, 0x3C986B21C58BCC57ULL, 0xE1BBE90B3A10D820ULL, 0x187990198C5D4031ULL, 
            0x6F64627849A1B21BULL, 0xF7E025E8935DDEEFULL, 0x2D4C7EE67CC6AB9CULL, 0xC5BE01B4E86FBFF9ULL, 
            0xEE0F932818FA75F0ULL, 0xDE8ABFD93101B6E8ULL, 0xADD2BCE44D016059ULL, 0x564FA032B15D786AULL, 
            0x0A6B44E6E7A69384ULL, 0x0CF335BE80ED3048ULL, 0x96A33228D99F6D92ULL, 0xDBCF699D56972259ULL
        },
        {
            0x3FEDD870C4E76FDEULL, 0x25BDD014A5587ABCULL, 0x474E2209184BC7B5ULL, 0xDBB82C1A222B0F30ULL, 
            0x56FD1ACC09581C45ULL, 0x86237E74A1EA8D04ULL, 0x117C27E868342C86ULL, 0x4EFE642351D28A96ULL, 
            0x10186785BA974E7EULL, 0x3BC99C5A9EEAFDD6ULL, 0x890564C4864D4ABFULL, 0x6689B40E048208B3ULL, 
            0xE5072D8F89663D6FULL, 0x58630131149D6A2DULL, 0x602D0D085F1BB2E4ULL, 0x055DB084E4A1B658ULL, 
            0x0C25D3E0230B0293ULL, 0x4D83920A71710E83ULL, 0xBC2CDD62E81F65C3ULL, 0xC2C367CC9F6A6BE9ULL, 
            0x58E3A8A70608A213ULL, 0xD94EFAD2FE899C76ULL, 0xCEA04BBBAB995302ULL, 0xDD78E0C7665D15B0ULL, 
            0x9A8677924F922B8AULL, 0xEBF04F4C763BC6F1ULL, 0x38E940723F4624A1ULL, 0x108D6A366C45EE41ULL, 
            0x4582ABF0E129A8AFULL, 0xCD51735E47F54E4DULL, 0x884C5907854AAE0BULL, 0x66EF6897D710A3B5ULL
        },
        {
            0x50D91D50D3CC257FULL, 0x71F3D1C9B133C6ACULL, 0xEE1704D5814FEC5BULL, 0xAF7F9219823A044BULL, 
            0x1088DEBB1CA9A499ULL, 0x72C25F167B2C01E7ULL, 0xB3E6ECBB6121D887ULL, 0xE51A7BA2EDBF142DULL, 
            0x00DF38F37DD59D8FULL, 0xB960D6DD7E239C77ULL, 0x5EF83C7D7FE2908CULL, 0xB06C80E7EF2F4873ULL, 
            0x1B9600EB42A88E0FULL, 0x7C700A4B23D4AB90ULL, 0xE1EEE2F31023C92BULL, 0x5946BDA975E2E434ULL, 
            0x337CF7DCA442A273ULL, 0xB08961A52B7A277BULL, 0x8D405B6DF61F4D77ULL, 0xF1600E1F5B87F219ULL, 
            0xFD89AF81CB507CF5ULL, 0xCBF161A59E0A7549ULL, 0xB04BF90F701E30B2ULL, 0x4817FB7085C228D3ULL, 
            0x63153250A4B2BAF4ULL, 0xA3078A95C2B3A742ULL, 0x78E7BCB371475369ULL, 0x08BCAB77A90B8B1CULL, 
            0x9F84459ED34021C4ULL, 0x4AAEF97BECC5F156ULL, 0xC61E47F7A75ED632ULL, 0x05F726E000F00E50ULL
        },
        {
            0x347DEB8FB3B275B9ULL, 0xF69B00AFF3EF3C97ULL, 0x5576D6C32947F15AULL, 0x8F2E9A4AECEFA053ULL, 
            0xDC87C95CC4C3E37FULL, 0x04270E8160326158ULL, 0x0CD01AA012CAD15CULL, 0x97577A6ECBD8E2F2ULL, 
            0x9BFB53FF36EE8152ULL, 0x0E77C6D9A83D00A2ULL, 0x88321D018416A859ULL, 0x478BB3FCDB194AACULL, 
            0xB5E760F6B9A61E79ULL, 0xAA0AFB41FA823204ULL, 0x18E8FEB09E8E390BULL, 0x8F1B6187B4EB4DFCULL, 
            0x89826F82734FF98CULL, 0x5680445BAE6DA05DULL, 0x1241C6AEA7FAE94FULL, 0xBFA8727B571DC636ULL, 
            0x8327FF0799D803D9ULL, 0x199C7B7322FC134DULL, 0xB026B26F61ED32FBULL, 0x12A8BE4E228FD82FULL, 
            0xD7D790213E4F02FFULL, 0x2923347D5F27F148ULL, 0xCBE874022FB178C5ULL, 0xB2213A5040D78923ULL, 
            0x533A12F36712A297ULL, 0x952C7E684CE74EF5ULL, 0xEC775CD79BC4E6EFULL, 0xE81290112027639BULL
        },
        {
            0x0DB9EA641B6DC146ULL, 0x7A5715D18817B6FDULL, 0xC4CFDFC2CC6CBCF3ULL, 0x4A0B6152878F7CC7ULL, 
            0xDEEA29EC4251AECAULL, 0x27399AE28E44832EULL, 0x859F047444B33B51ULL, 0xC8D43CE05EF04E9CULL, 
            0x8BD802460C8032A9ULL, 0x71141F40C13DEAF2ULL, 0x905BA99C94522077ULL, 0x47AAF0855BBD636DULL, 
            0x75742DB094AA4638ULL, 0xEE6EC46A5D7E6AF9ULL, 0x026B2E467E1903ADULL, 0x011C3AB943DB647AULL, 
            0x5AC53401B9C74DC0ULL, 0x2D894E27FC8CF275ULL, 0x6F98FB624ED3CB4FULL, 0xC0F3B4F47FECACFEULL, 
            0x14644DA79A31901CULL, 0xAA691BFD0A9ACE5DULL, 0x802DC901B029B241ULL, 0x61DF1C827AD4FECDULL, 
            0x89A38A946274B97DULL, 0x19735E72CE45E23FULL, 0x9354E031C4E9004FULL, 0x31CEE7FC1761DB1EULL, 
            0x7A00EBF812538D04ULL, 0xC18A80CFEE7DCCE0ULL, 0xB4F464DE44090D0FULL, 0x33D8D8A020C715BBULL
        },
        {
            0xCA6452F814449137ULL, 0xF6DCA33F604FCDD8ULL, 0xB9F2E40B15FA3016ULL, 0xA704D4A8B420A8DCULL, 
            0x9B876ED21B71E078ULL, 0x537ED325063AE4E1ULL, 0x6CBD8B58A4052165ULL, 0xC9C4369F9F512D17ULL, 
            0x1C03A98473558624ULL, 0x5AA483A044B43A85ULL, 0x9105956A9EF015A7ULL, 0xF8119331AB00219CULL, 
            0x7B01D353C6B14EA5ULL, 0x779A38B18472FAFCULL, 0xC9693FCAE378F1B8ULL, 0x395DE6D8FF178B78ULL, 
            0x5CF2929329955F8DULL, 0xE7886C6B1799F4D8ULL, 0xCFBE4D2D41FF7F48ULL, 0x2B114C1AD7D3E455ULL, 
            0x955C11F4194CEDBDULL, 0x1F08C3F0167915C3ULL, 0x801FCA9FA130D08EULL, 0x67C4B54B53834302ULL, 
            0x43F6C33B27A16350ULL, 0x33CECDE9096F1798ULL, 0x70C0ED7D525977F8ULL, 0xD54664D5C0C1197BULL, 
            0x53A2F6A4A2D9B25EULL, 0x2BD0FA9558379BB1ULL, 0x94242E90D70C0C60ULL, 0xF2877351BAFA45B1ULL
        }
    },
    {
        {
            0xE7ED695C1154B58DULL, 0x2F755E0D9C0806A3ULL, 0xC1C73BF19BEAFC68ULL, 0x2D38E17C342956B7ULL, 
            0x0C6718DBD29D5B14ULL, 0x75FEA85F37FF155CULL, 0x438E9CA74F444B65ULL, 0x81B9DC4B93C61097ULL, 
            0x8F158FC0F508F185ULL, 0x9504ECF6BB123BC5ULL, 0xBBAAC89E76634C22ULL, 0x6A7169F1A1160E1BULL, 
            0x0058951996E75F90ULL, 0x1D6CDF62302913F2ULL, 0x5D5FD14F11A2A036ULL, 0x34574116AFE17D08ULL, 
            0x74F1E72BEE996CACULL, 0x1A765EBDD76C3984ULL, 0x5ADB56A6DADDA012ULL, 0xD809A14B6FE9BEDDULL, 
            0xEC5A59609972AB1DULL, 0x52CA20918BCD736EULL, 0x9AC2A8BCCC8FF4F4ULL, 0xA30C2F39BA7197CFULL, 
            0xD6026999EBE3884AULL, 0xD5A32356378F7CE4ULL, 0x7D2ACD25FB26B7E5ULL, 0x8818FD79E454AA43ULL, 
            0x3ECE74D3FA67905BULL, 0x02919E879685B7A0ULL, 0x94FDC981B61A8B56ULL, 0x2E6F601CACE65A4DULL
        },
        {
            0x17C6FBF3EAD87496ULL, 0xD7AC26B65C074EB0ULL, 0x813DC926D87A4B64ULL, 0x671CD14D5D128DB0ULL, 
            0x61CDFBC6F316AF64ULL, 0x0F1F14BD62A5F613ULL, 0xF96A91B293AA034EULL, 0x6235ED720305019DULL, 
            0xA526527BB82CD12DULL, 0xB59E7BF30BA164EEULL, 0x3CF13B2AFEADD597ULL, 0xE3EA0C72BC434625ULL, 
            0x2F1B06432D9F16E0ULL, 0x027F483F9DE50A4BULL, 0xACBB06F2B522C19FULL, 0x591FD4B7ECD1436DULL, 
            0x1B736455D302BA39ULL, 0xA0E2E9E3412373C8ULL, 0x3B039099D17D9861ULL, 0x7FCE6EC973B137A2ULL, 
            0xE23C30302A413DAEULL, 0x010BEAB8E5FD51E4ULL, 0x3307054E99C7FA1CULL, 0x8C870D422458B44CULL, 
            0xD216E7D4E269A338ULL, 0x5F6B8868F42D571FULL, 0xE09A2D8A05A6D7D4ULL, 0xFEDBCA0A0B106554ULL, 
            0xC9C618BD261A8953ULL, 0x2B97458F85881152ULL, 0xC471FD46A8270BBDULL, 0x0BAA8D7BE698AE21ULL
        },
        {
            0x99995B08EB79099EULL, 0x887641C788715630ULL, 0x9A48398A92F5223AULL, 0x24C1807CDACFB1FAULL, 
            0xDF606CFA70DA43E0ULL, 0x6ECF479836DB4EB9ULL, 0xF0B08356FDD13801ULL, 0xD6200B7804DBB458ULL, 
            0x6FA93529E7071469ULL, 0xDBC9DA37915478DEULL, 0x905EF7CEAD65F68BULL, 0xCB7E2D8D5F58E248ULL, 
            0xD0F99C519DAE9F14ULL, 0x0F496AA1A9585E99ULL, 0x73FF391DAE624472ULL, 0xFDD18136C45619E0ULL, 
            0xB1ABA4859BE854D9ULL, 0x885C03DA4A59BAFCULL, 0xE6909A5E950A91B2ULL, 0xB72C314E8EB81B54ULL, 
            0xBBAA0071D60D0213ULL, 0x44F0E1733F3115D9ULL, 0xACB970AEB3108D9DULL, 0xA566974C6ECA13E8ULL, 
            0x737B69A7AC9EE099ULL, 0x6A924B43F81E98AFULL, 0x23CE8BDCA248E079ULL, 0x52EA44E3542056BEULL, 
            0xF8F3D0AEFDAAB7A1ULL, 0x6587908BBCA016FCULL, 0x73D8E64D5487A658ULL, 0x0CDE95A39BF99C8EULL
        },
        {
            0xBCF151001A70168DULL, 0x0BCE6FCE5C6F7B4EULL, 0xFD6E146A78721561ULL, 0xFE270ACD93534972ULL, 
            0x65DA3CB886D37384ULL, 0xEEF6018449F00A23ULL, 0x6ED78F71790F0A8AULL, 0xC97AAE18A3E1E6B6ULL, 
            0x70DE370B2DB68C4DULL, 0x6F69BC09DD4C0536ULL, 0xEF92380B1496C983ULL, 0x3A5B1ECF57D35885ULL, 
            0x48593D7E8C0BE392ULL, 0xFACFB08D3A342E2AULL, 0xFA6CD9E4DCD0961DULL, 0x367997CE5363EF96ULL, 
            0x60CF846FD0A15B8FULL, 0xA79613593068ACCEULL, 0xAEA3AC81768D9456ULL, 0x79889CA0E5BF30B4ULL, 
            0x986296DA0EE8ABFCULL, 0xE6C88DD468F7E531ULL, 0xE785D01D75B7FBF2ULL, 0x89CD1F84C41251DEULL, 
            0x5BC893D7906A4C67ULL, 0x8778FEB031E84C8FULL, 0xBDE072A4746B9E66ULL, 0x59FCC20F581C2F32ULL, 
            0x87E2B4A197C621A0ULL, 0x13B067D9597C9F5AULL, 0x4C4D774E07E45845ULL, 0xD2754ADD06036714ULL
        },
        {
            0x90F1F430DB84611FULL, 0xDC37EDCB36DCAB41ULL, 0xB88CE0C8F1958D70ULL, 0x82D5B3B6ACCE1F47ULL, 
            0x7E6AC117E035B4F1ULL, 0x5886FD1AC946EAF7ULL, 0xCDFCE9A1F95013DBULL, 0x3BD08A4F56F0A06BULL, 
            0x0B603223902BB3A9ULL, 0x6ECD2F55439A84BDULL, 0xB94D4946141A3B6EULL, 0xBE3546B570D597E5ULL, 
            0xA9D410AD8B84C864ULL, 0xBD4DE17FF7D945C1ULL, 0x8D0AE346F0507196ULL, 0xC688119E979B13F7ULL, 
            0xEB01875876F0D9F4ULL, 0x35489BB91CDF8BEAULL, 0x625313F3C83BD7F2ULL, 0x2C27713A7BA4E0EEULL, 
            0x122C7224FE7D8642ULL, 0x9396F7A4D1171944ULL, 0xA683BA64A61A9D6EULL, 0xC7A4F6AEA482BD6EULL, 
            0xEA3BE53C573666CEULL, 0xCF6A945330689420ULL, 0xFFE84F9F68DF4BAEULL, 0xA0012597D0BDC785ULL, 
            0x53845B8F097B8A92ULL, 0xCE527B9BDC102740ULL, 0x2037E7414C16A3D3ULL, 0xB0217D72C19E4234ULL
        },
        {
            0x056A50D0B6CED789ULL, 0xD22719CB9554303CULL, 0x11542639E83CDCB9ULL, 0x0C6FF527231E42A8ULL, 
            0xBEBE2115E32D472AULL, 0x781E13B63B1A0155ULL, 0xEDB9A180B0F9E484ULL, 0x1B5444450A62F478ULL, 
            0xF1714E9FC5715014ULL, 0xBA2A14DFB59B6E85ULL, 0x5BE9062F0A20EE4AULL, 0xD0147A5418CE2E1CULL, 
            0x2E080459559C5DAEULL, 0x2A35AFD7B88E7CF7ULL, 0x89751A72780CF2ABULL, 0x22286C9AC57025A6ULL, 
            0x3DB7A103BDD672BEULL, 0x3516E583A90DA504ULL, 0x623676AABB6F1F86ULL, 0x36549B94946ED429ULL, 
            0x2A5E558E7CC61FA0ULL, 0x6C7348D7B217DD87ULL, 0x47D11C48F6C72527ULL, 0xCDCFBBB6A170563DULL, 
            0xA1F936B9F1A1B269ULL, 0x9059F389D41FF120ULL, 0xA6CFF0F7389A6414ULL, 0x4584147605D42B1CULL, 
            0x8891F8D92C92C742ULL, 0xECCDD1BBED602AB0ULL, 0x8314014FDD8D8E85ULL, 0x5BD18D16F18E1B57ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseEConstants = {
    0x4248062E87F7FAC6ULL,
    0x057D3624CBD4CCE8ULL,
    0x0DEB53B00E0EFE29ULL,
    0x4248062E87F7FAC6ULL,
    0x057D3624CBD4CCE8ULL,
    0x0DEB53B00E0EFE29ULL,
    0x11C5D320252CF669ULL,
    0x45FB8F42EFCD771BULL,
    0xDD,
    0xC5,
    0x12,
    0xB9,
    0x82,
    0x27,
    0x3A,
    0xD5
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseFSalts = {
    {
        {
            0x954291918CE593B5ULL, 0xDFAC207E1AD17227ULL, 0x0FEC2E6BBC29B9CAULL, 0x78BBB487F08F4CA2ULL, 
            0x57BBD35BCD1C5875ULL, 0x4E5FBC2815063D54ULL, 0x440764C6DBDF754CULL, 0x2D8D92EC1DA6C735ULL, 
            0x961012BBFC5F4F07ULL, 0xA9A6133EDE522BBDULL, 0x8362A20F1D45B5E2ULL, 0xEDB0ADFE1B4407DAULL, 
            0xFA23D23EF6E25CD7ULL, 0xE3A3C9A2911BA014ULL, 0x22261103B1E288C7ULL, 0x3F7A61AAC4134172ULL, 
            0x624276201D6ACCB7ULL, 0xB5CF406DB512C000ULL, 0x5FBD442AE33C15B0ULL, 0xFDCAD123926881B9ULL, 
            0x78B1D0741D4812E3ULL, 0xAED1F985F118D647ULL, 0xA6745A9E79CB3627ULL, 0x675FB70B2165CEACULL, 
            0xC7F04C7F60FDED24ULL, 0xBD2140DFD1A1C77EULL, 0x74CB1D8A522DB888ULL, 0x0CA90AF45AB343F5ULL, 
            0x99597E50D55F2EC7ULL, 0x2B35E42C5E5E8F56ULL, 0x1BE104DCD9BACE79ULL, 0x664724B93110D216ULL
        },
        {
            0xF5A16D4714572D94ULL, 0xE7EEB1B6C2EC0E93ULL, 0x01D3069B8E5F8018ULL, 0x34584D075F44762EULL, 
            0x96E7BDD34B1C6008ULL, 0x61A18007BB079AB1ULL, 0xAD3080AEB7B3F9CDULL, 0xA96E90C1F1C81ED8ULL, 
            0x20DA6EF2A0A40BDAULL, 0x91EFC6CE71D080DAULL, 0xEE3487517D1600DFULL, 0xA34C93B93EA4EEA9ULL, 
            0x8BBD34FF172E1F34ULL, 0x42B76C2824F3C163ULL, 0xA09FFE0716705395ULL, 0x5873FA0359C3A724ULL, 
            0x19DDEB256EC32DC6ULL, 0xCC0686E9DB74169AULL, 0x6CAA5ECBB6F81DC0ULL, 0x04346B457D28FAF6ULL, 
            0x0317BBC71F753CEEULL, 0xD7EC0C1489C79D95ULL, 0xD888E28BDA797FF5ULL, 0xD249666127D1F6AFULL, 
            0x567191B9D7ACB792ULL, 0x7A271CB8CB0BA1C4ULL, 0xA3364547B837D324ULL, 0x0BA85A81FF8005C7ULL, 
            0x930A599ECDD04CFEULL, 0xF2595637F6C0DB64ULL, 0xBDD61B2DCE447144ULL, 0xA63FE2736A45EBF9ULL
        },
        {
            0x7B4401017A7FA29DULL, 0xF4D5322D3FA7BA35ULL, 0x35786E58AB66DB7BULL, 0x6ED34999403FF8A3ULL, 
            0x60252326B17C629EULL, 0xEB39E6233BE4857DULL, 0x54CB583C4D00EC75ULL, 0x8B5CAA9F40BCE942ULL, 
            0x2D55C011B00D8F27ULL, 0x2E9C7F30B708E136ULL, 0xFBA026E560CC48D2ULL, 0xA808018C782E3EFEULL, 
            0xA25522F23825FB67ULL, 0x5C858B22E9956857ULL, 0x0087EAF27140E476ULL, 0xC4456DC21207371BULL, 
            0x06CE47F8977E9478ULL, 0x73C9000A11FF2F1EULL, 0x2B93E5219CF5AB87ULL, 0x9AF1601EEF4AF7FEULL, 
            0x2A90842000220719ULL, 0xFF27BBFDCC9BE38DULL, 0x0CDA0D0B71553E64ULL, 0xAD15891C36EEF314ULL, 
            0xF89856BAF5F60E0DULL, 0x6A5F522F48840216ULL, 0x202CADF06080DBC4ULL, 0x7E27E4AF02CE8829ULL, 
            0xB9323D4DCEC1400DULL, 0xA8AF47BEA8758140ULL, 0xF2E6DC2557540E66ULL, 0xD15E75BA895F3B45ULL
        },
        {
            0x09BEB02A91F3B986ULL, 0xF7F2393C717B0E7EULL, 0x6955227FFC07FA47ULL, 0x31C59511007E1C10ULL, 
            0xDA695AE30ED41C5EULL, 0x239EE374E6782D29ULL, 0x421A207F2061D54DULL, 0x0F933FC0AC3EF686ULL, 
            0x611CD8565C7266E7ULL, 0x29F75359EC52845AULL, 0x2B8ABFDC84CACEA8ULL, 0x1C9B6D04D2774424ULL, 
            0x84E2212A295A1025ULL, 0x998B24A48B54B60BULL, 0xCF0BBC008313A5E3ULL, 0xA3CDF90DC0ED3D4FULL, 
            0x871D3F24EBD1395CULL, 0x64ACE486F91AE0CCULL, 0x7CA91ADA4F9A1272ULL, 0xF8B999D3401AB590ULL, 
            0x4343C446FF30C766ULL, 0xEFA7BC428E78CE07ULL, 0x0581378B3BC4A0BAULL, 0x2BFA30DA9B4BA8F1ULL, 
            0xD0EF46D0C46ED17EULL, 0x4F93220BDEDFE9CBULL, 0xFE14FADEB8E1BBD6ULL, 0x361670B1C67840C6ULL, 
            0x95EBAE2658193E00ULL, 0x4ECCAD362BACC5EAULL, 0x24F58D10D211D166ULL, 0x4CE7329422A22AABULL
        },
        {
            0x15CB1BF2D0D6D5B0ULL, 0xFB70B53095599BCEULL, 0x3486680950D32F24ULL, 0x70D1D431BED1EBB4ULL, 
            0xBDDD9FA2536EE2C1ULL, 0x70509ADDD3E94947ULL, 0x0FCA1FF84422C6C0ULL, 0xEA055075A39A356CULL, 
            0x2DF115051C082AA2ULL, 0xB49D082F0BE46C06ULL, 0x9F686799D408D9B2ULL, 0xB8240BA234AE7ABEULL, 
            0xEA8739E8955BE6A0ULL, 0x3EAC51FCFE2DF8F2ULL, 0xB572B40872910D85ULL, 0xA17B477E098FE1A6ULL, 
            0xB395E71D8FEBE0CAULL, 0x68CDFB0AE39DB45EULL, 0xB91F45C4116DB50BULL, 0xC907E10D4DD6CC64ULL, 
            0xA9DF674A552FEED4ULL, 0x4CD63265B5ABFCBEULL, 0xBC513DDC4C67A55EULL, 0x1DFDA247BB54AB08ULL, 
            0xC26B1A63ABA5AA86ULL, 0xE0EABAABA411917EULL, 0x567D800E03FA5C5CULL, 0x9B6B43AC2B583427ULL, 
            0x88940B6EF7EE78DAULL, 0xBC28E55EEB792912ULL, 0xE94363268382A274ULL, 0x6B259285660892B8ULL
        },
        {
            0x06E09A35A291ACACULL, 0x68ECC780FD0A96F1ULL, 0x207ADE77C17D403DULL, 0xAFDE87377376A3BEULL, 
            0x41CA91019D95DA24ULL, 0x1BFEDC43CFE6FC63ULL, 0xAE6AC37A683EFC96ULL, 0x7279C2194A28F2ECULL, 
            0x0F6C0A45A9693D3EULL, 0x805E15A72538E54EULL, 0xBB41974ACA01AE8BULL, 0x5E8333317B841CD1ULL, 
            0xA8FE500D31161533ULL, 0x085137FF8C8F6D23ULL, 0x8A8C454A6F1C020FULL, 0xB5C00534222DE84DULL, 
            0xE1CA4BD02687E40AULL, 0xD04EFC12DE85AF86ULL, 0xD0EF2D54F00C5582ULL, 0x8AA52BF3FA81B6E4ULL, 
            0xDCC1D1527C0DA94DULL, 0xE7A241DF141EB936ULL, 0x416F16901E855EF4ULL, 0xE24D8560699CCE23ULL, 
            0xE62409182C092579ULL, 0x339FDF80A0546067ULL, 0xA61DEFCB42ECE33AULL, 0x51FCA1AE9E30776EULL, 
            0xB871E6FCCB16356FULL, 0x59F7CBCE7BD30AA1ULL, 0xE7A0C8060B4ED896ULL, 0x365296788823EB0AULL
        }
    },
    {
        {
            0x2010802CE3A2EBFAULL, 0x28A8193B7AA36CF4ULL, 0xBC584851DAA3AD9DULL, 0x37CCE5CF23CFB8C2ULL, 
            0x4905ECDB292CFD3DULL, 0xB80B2A31B7D568F0ULL, 0xEA4C3018566FDEDBULL, 0x5BF068E046DACB4CULL, 
            0x4327A54C44582FC9ULL, 0xB6997F5E79561A04ULL, 0x2F737C529AEBCC3CULL, 0xD4D6808F9B3CF051ULL, 
            0x6F3DE99ECDEA869EULL, 0xF28C0F37D204A36CULL, 0xA007F523FE6C24C0ULL, 0x06AF8FB2526867ECULL, 
            0x8A8E01D2102ECE6FULL, 0x729857BEB56977DEULL, 0xEEF76C9CF0FDEC6FULL, 0x37A6B737799FD566ULL, 
            0x898D020DAADA8470ULL, 0x95C20929BE25EFFCULL, 0x61CB653B8F219917ULL, 0xFCF6336EAE1A0D84ULL, 
            0x733BDAD77D6DBA72ULL, 0xA7F05330C68ECF76ULL, 0x7E538C59878FA578ULL, 0x3777199D833A99FCULL, 
            0x9E840924F92A6E3DULL, 0xD813E6DFF15527ECULL, 0xA9E2F2844729FB3DULL, 0x29B82DE03635C8FAULL
        },
        {
            0x57D9701ECA0F903AULL, 0x158B66DB7FEFF33AULL, 0x78DEA1F373B4BD5EULL, 0xEC8C5235CB9AAEB1ULL, 
            0xCCC46D1014550729ULL, 0x118195DA3F273F8DULL, 0xDC96942490DD00C5ULL, 0x25EF98A19093A23EULL, 
            0x9608CA6103DBDA18ULL, 0x871A7D3761EAD29CULL, 0x10DFD9A5320ED85CULL, 0xAA01A12C7E5D7E8DULL, 
            0x647125BDB7683F83ULL, 0xF64CCA87002EAF45ULL, 0xE7DB47C3FF70E880ULL, 0x253BFC4FF6869E8DULL, 
            0xD3F26FCDE286616DULL, 0x2AC2A694BF00E09CULL, 0x237B73933FD385E1ULL, 0x1A8AD6FBF335426CULL, 
            0xB21E8CBD22B69E72ULL, 0x37461C0B7E62BDA4ULL, 0xDF243D80F335B04EULL, 0xBC918332208DF2D2ULL, 
            0x9B40C358941E4138ULL, 0xEF0D85FCE22EAC51ULL, 0x1324AAE5E89E3818ULL, 0x26C7B7D9739A9BEDULL, 
            0x6CD0F413553C9FD5ULL, 0xEE97B1A84BF80226ULL, 0x39C16D13A477316EULL, 0x5805FCC9E6F85728ULL
        },
        {
            0x08CF24689C90D56AULL, 0x796F38A9AC751CF8ULL, 0x4AC7EF2B9DE9DF40ULL, 0x0FFFCA800736E0C4ULL, 
            0x6DED1D230741FE44ULL, 0x8E213C20C7407E2CULL, 0x44E7861BC1764082ULL, 0x2556AACF850C3949ULL, 
            0xB11EF5D7DF3079E5ULL, 0x9A5CC1A5FBF6C900ULL, 0x1A80A1E7CF4E9B6DULL, 0x7B0478F3FD207865ULL, 
            0x3862F704CB6442EEULL, 0x3DECE5F396E55BE1ULL, 0x6FD1943FCD228C9CULL, 0xFC58A06E2E24A768ULL, 
            0x213AEAD4F01EF849ULL, 0x8D85B7C3EC4D0CFBULL, 0x3A76A502C5AA772BULL, 0x623820AD0CB73F19ULL, 
            0x2A9B7E393CABDD9EULL, 0x1E3EABA0C18A2CC6ULL, 0x3EC1F2CCD053C605ULL, 0x2EB89EF7BA143500ULL, 
            0x2ADE8DDFC1AE85E1ULL, 0x8A392272481A57EBULL, 0x6989D5A0FFB43A09ULL, 0x47CCE663B5B07874ULL, 
            0x61498C044F200C47ULL, 0x08AC0AA1D8423E57ULL, 0x2C5D74D777FB9741ULL, 0x94113B14BEDD5063ULL
        },
        {
            0xA6D2B7E99B206769ULL, 0xEB034E5E03A417F1ULL, 0x57CB64490242735AULL, 0x3C56B90F665FFA08ULL, 
            0x68785A61173CCCB8ULL, 0x17095746BA23524CULL, 0xD9EA81CB9591C845ULL, 0x63D870D1CDD9FF34ULL, 
            0x1802202AF2D30DFAULL, 0xE9870A8EF03BE611ULL, 0xC34008DEF69FFF30ULL, 0xF3543761F81E986AULL, 
            0x377B585901EE38CCULL, 0xB2A9853F19EC145AULL, 0xBDFD672C1995430CULL, 0x7B642266DAE68CC8ULL, 
            0x4C18E09F7501BB2EULL, 0xED394F6C0684AF9AULL, 0xBC7A40FA9CE45CBEULL, 0xC0370B2CD887B360ULL, 
            0x2CD4706BA542F412ULL, 0xC93B2CA49724B0F2ULL, 0x7D15C42EC8B23346ULL, 0x8FF80235207E3EB6ULL, 
            0x9004BDEA57F70A90ULL, 0x13CF4774EB9B461EULL, 0x58167F86954825F0ULL, 0xE0D2C0A132D9E013ULL, 
            0x59896226E0939218ULL, 0x5649ABB894B191A1ULL, 0x7768A4035D138588ULL, 0xCC259A1CEF479427ULL
        },
        {
            0xD396B365A721BF13ULL, 0x8744BBC633891CE0ULL, 0x0855467FB9794BECULL, 0xA3AFAD1AB56CCD26ULL, 
            0x41B5E424AD520670ULL, 0x383099D0773B191EULL, 0x8DA6B488DDFAAB20ULL, 0x72D0D1EDF776B2C9ULL, 
            0xB31EFAA763E6429CULL, 0x99423895C3B73A44ULL, 0x2C482D08585EDF56ULL, 0x93DF25D7CC157476ULL, 
            0x2D54A2EF6E91DAC0ULL, 0x5C192DB9449DF21CULL, 0x17927C66DDA2FA17ULL, 0xFBEAC60EC01ADDFBULL, 
            0x7B466E0728F841B4ULL, 0x9F0D050BA250B17EULL, 0x3369635CFD4EB91DULL, 0x5AF12D91CAD2D3F4ULL, 
            0xE5F2F8149A9E0533ULL, 0xF32F07326C0665DAULL, 0xD6423E9552912D56ULL, 0xB938B686E9F8DE39ULL, 
            0x733DDA1DBFD8BF98ULL, 0x4A7DFAC1624BA95AULL, 0x2D3089F31006B50FULL, 0x3C01857410E9FF8DULL, 
            0xF403088DD9C8B4ECULL, 0x107BCBE3226BCD39ULL, 0xB0118325D10A5517ULL, 0x1913B46ACB1EB52CULL
        },
        {
            0x23246C0F645671AAULL, 0x131E01F012ED928DULL, 0x05D55FCEF5F403F6ULL, 0xCAEF2F6756A10747ULL, 
            0x8E660B46911091ADULL, 0x4411252CA3192399ULL, 0xEE649530A6F96570ULL, 0xD026ACC653BB4FF3ULL, 
            0x38087DA6C05D9ED1ULL, 0x85F884946B86ABFEULL, 0xE413EA040DA2CBD3ULL, 0xCF658DEC13DEFE6BULL, 
            0xE7C2364F07F82CD5ULL, 0xFB955C5FDEC5F323ULL, 0x67D77F680809FB10ULL, 0xE15B996628D28452ULL, 
            0xF57578089C5C9AABULL, 0xE92E4ACD18E669ACULL, 0x689537E9DAC18B34ULL, 0x3CDA2A29A8267494ULL, 
            0x622287A3493B5230ULL, 0xE193AE877B019BC0ULL, 0xD7B514C7F9EC188AULL, 0xF2DE279D4E7CBBB3ULL, 
            0x1050E73A319E8FF1ULL, 0x04363E8251616466ULL, 0x515F878BDD285454ULL, 0x2F8739B5D28F527CULL, 
            0x5800B823685C9631ULL, 0x403A0FBB0C6DFF08ULL, 0x62F1D4D83E63F2B4ULL, 0x28727623C6D4B0FDULL
        }
    },
    {
        {
            0xDD8427228146C159ULL, 0x9C73EB5F407D0BB5ULL, 0xCF89D94B334B399CULL, 0x56594DFAD91709C0ULL, 
            0xFC2B2DE19CD3CAF2ULL, 0x67E88FF8B4F5A72DULL, 0xBDD7CF2426A65725ULL, 0x4761590EC90708E5ULL, 
            0xDB59F4BE3D59C840ULL, 0x74E54261F333D719ULL, 0x35B365D6AF906B29ULL, 0x633B505714075D06ULL, 
            0xC72CA1B64DF84E59ULL, 0xB4BE3728FE813B6FULL, 0xCEA0C35233B2F3D8ULL, 0x9AAEFD57E037C13AULL, 
            0x5FF70E48B086E56DULL, 0x4A8C043BA79CED54ULL, 0x3BF0C4425F83BB1FULL, 0xDCE8E1F64FBEC0F4ULL, 
            0x1511A7A0B4D9FB06ULL, 0x4F3FF5087B6E89ADULL, 0x2C53E52D6F301239ULL, 0x3D2C2991EF96CEFAULL, 
            0xA249E8A875CABDD0ULL, 0x75981F62FA140232ULL, 0xBF03A55625D2B53DULL, 0x3AB5BA1DA7F535E7ULL, 
            0x16CD24004E84683FULL, 0xA6E52E22BBDF85C8ULL, 0xB3F1E92F010E4CD4ULL, 0x1498747DA388F7B0ULL
        },
        {
            0x41A2F64FE664134DULL, 0x67458F21F3DC79E4ULL, 0x7E4EBDEE7C7536B4ULL, 0x8BA5AD5E3A8EC7E5ULL, 
            0x7B716C0DB8CC6C23ULL, 0x41F95C71D51D7935ULL, 0x2480AE07C72B245DULL, 0x14DBA858136962ACULL, 
            0x8DF8C17346C5A9D1ULL, 0xF9C9EBD4B464D33CULL, 0x1BB0BE8A574AD8D4ULL, 0x83323131741B8595ULL, 
            0xE53FB0E64243D847ULL, 0x96EB4F6829F24964ULL, 0xD0B97304B8064CC5ULL, 0x1A6D62AAC5C0C2F9ULL, 
            0xD0D4464898F8E9E1ULL, 0x7D59E19417DAC706ULL, 0x96F79E67F38DCFF0ULL, 0x76E97CAFAC62C6E4ULL, 
            0x33C82006E367BCF5ULL, 0x05ED425B56C2357CULL, 0x5D71D21BD3CB578FULL, 0xD9C28B84790BBCCEULL, 
            0x082CD5D25DA1823CULL, 0xD6190044DA62F638ULL, 0xECE38F9FDCE0E5FAULL, 0x4C614C86838D2A34ULL, 
            0xB53E36DFB73E2194ULL, 0x930A3C6E74464C73ULL, 0x16D74B96C2EE9117ULL, 0x696253FC75EEE9BDULL
        },
        {
            0x8D048994AE78784CULL, 0x1C469D7BF63E5578ULL, 0xA77A648495D3A254ULL, 0x04702A68F44DC74DULL, 
            0x1124C41D9F2E4F03ULL, 0x0FC889A356505942ULL, 0x6541A421484C471BULL, 0x4B102EAE245A045BULL, 
            0xA4DD3655E0732CC5ULL, 0xC4674B97B0D3BAD3ULL, 0xE13B04133B3C8BC0ULL, 0x19233D4D1ACD5487ULL, 
            0xA8310FDF47805605ULL, 0xC799E53B3136935AULL, 0x365061D61B94587BULL, 0x4743A9BE7E4D5B47ULL, 
            0x241D5BEB076B25B1ULL, 0xACFFAF02173BAC8FULL, 0x367821EE892FC571ULL, 0xC30FF675991BD707ULL, 
            0xC1118AF500732D8AULL, 0x19CF2E0833BD0F6CULL, 0x76DEC43127EF3F37ULL, 0x7036D44E8D030444ULL, 
            0x8B76D200C38B745AULL, 0x480FEBDBF455A39DULL, 0xAF5F6A15E84EF15DULL, 0xE95CA986D1038BB5ULL, 
            0x3FDDD760297FC704ULL, 0x883DE87383EC7689ULL, 0x0E2B0F423A5286B9ULL, 0x7046A0D650F768B5ULL
        },
        {
            0xE18456323A04DD85ULL, 0x3EF776F892D3B7C2ULL, 0xD510641D9445AC15ULL, 0x4304760A075098DEULL, 
            0x13EC9177CBDDA5D3ULL, 0x64AAA54B1B532F53ULL, 0xE11DB2306DE60BE5ULL, 0xD1BA0BE7BC4D3D44ULL, 
            0x1BA49EBF6EA19A9CULL, 0xDEDE486D4244D9B9ULL, 0x3F2381A017995659ULL, 0x6E71005719BD55C1ULL, 
            0xF6A34EF50C06B52EULL, 0xF1A606E369711207ULL, 0xB11C7D0EA2A0FA6BULL, 0xC7DE89B82C22306EULL, 
            0xD8E96A4C236F1B41ULL, 0xAC9214BC363C40E7ULL, 0xCF286072C1CA7667ULL, 0x24736E6D9D712495ULL, 
            0xB09BAD4DCAF9D5CAULL, 0xEBBD2BAED010F915ULL, 0x5745A0B9E57CD4CFULL, 0x715181107086B235ULL, 
            0x6B1B5E0612485601ULL, 0xE09AC555518BF6A0ULL, 0x2EA70B5065C2A4A6ULL, 0xA74575B8B724F870ULL, 
            0x3D63ACE7954C75A7ULL, 0x2467DB3AECB399DFULL, 0x8C470FF16A293EB2ULL, 0xDD0ED076B56D76E3ULL
        },
        {
            0x271E80E966C5E4A2ULL, 0x3ACBBEBEBE33A43BULL, 0x277497157F7C9DE1ULL, 0xD0DC59D458B7DBEDULL, 
            0x40CD097FE63EA5FDULL, 0xD2D9131D1F94C775ULL, 0x2362143EA03A5E73ULL, 0x0E853E47C50A9165ULL, 
            0xB482EF3BAE7462EDULL, 0x1C2F3A9719CB865BULL, 0x709BB30BBE3B73ADULL, 0x96A07FEA3C971766ULL, 
            0x30E0FC3CDFBFB942ULL, 0x035973E7EFDB5C51ULL, 0x0356661C567AF00FULL, 0x8853B6DBEE3416A6ULL, 
            0xB1407CE1CE683966ULL, 0x62C0FECB3BD7A61DULL, 0x0B1117015C34BCB5ULL, 0xA56BFE2E80260B86ULL, 
            0xCD44E89B27597881ULL, 0xD8DC23CAD93FEF3EULL, 0x99B06D91B2059D94ULL, 0x1B7DB5C4ADC1E9DFULL, 
            0xAE6C376FD2364CE4ULL, 0xA0F9E05EEC15F1B4ULL, 0x0223928CFB4C8F4EULL, 0xB7B85756DF1F7268ULL, 
            0xED212B98E16BF300ULL, 0xEA263801786FA39DULL, 0x9BF12481626267BDULL, 0xA992C727BD5CD284ULL
        },
        {
            0x82F71BD3B922440EULL, 0x78FD6A998A4F7012ULL, 0x9837831C6E1317DBULL, 0xD2BF5145E302A0BEULL, 
            0xF4EE001D35C964D6ULL, 0x0C1BC505FCE5AF09ULL, 0x0B8739573CE4273EULL, 0x4B05FFE0F3BDD30EULL, 
            0xCFC9B0AFB70F771CULL, 0xD07A04A8306A592FULL, 0xCAE2F55FC1252188ULL, 0xA4FA344ED42C6B46ULL, 
            0xD6039017A9C8134BULL, 0xB6C2DCAA73C8D3E8ULL, 0x23A2A27F97A90291ULL, 0x4CC42B68AC00C32CULL, 
            0xEF644A9CAF7F9CF5ULL, 0xFB800CE54BF7A911ULL, 0xB44CF900F30F8DFAULL, 0xC46576A59A279359ULL, 
            0xC5678436F1549815ULL, 0xAEF922BE394FE3F8ULL, 0x84366006A53E3087ULL, 0xF38DA4792A0311F9ULL, 
            0x162D66A17EC624D3ULL, 0xFD7186B0583144EFULL, 0xFE79C30063B81432ULL, 0x3E86E2DB8106390EULL, 
            0x666D3611B78AF4D9ULL, 0x1A904C5C39D4D7DAULL, 0x1549E11B04E33A61ULL, 0xD5E3CEF108EDF452ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseFConstants = {
    0x0351EE20960DB039ULL,
    0x20D59B754A3B0C1BULL,
    0xF4652C06AE865BFFULL,
    0x0351EE20960DB039ULL,
    0x20D59B754A3B0C1BULL,
    0xF4652C06AE865BFFULL,
    0x8F667CF62FBC0F99ULL,
    0xBFB34DCD12ED1DA6ULL,
    0x83,
    0x89,
    0xF0,
    0xED,
    0x12,
    0x6B,
    0x8A,
    0xC6
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseGSalts = {
    {
        {
            0xEA04A921ECD838A6ULL, 0x302589EE798E1A36ULL, 0xBF532417E7213D6EULL, 0xCCAC5D5D2D23B586ULL, 
            0x3AEA86837D809172ULL, 0x10E0067E39E4A22DULL, 0x5131D54A81EB25A2ULL, 0x2270DFEA3347B99BULL, 
            0x5563B8F9F6154B66ULL, 0x4726C5C105DDA7D5ULL, 0x066E661CD6BD206BULL, 0x21D6FB9531F8864FULL, 
            0x20A3715D68896E48ULL, 0xA289BD0A71B66406ULL, 0xE5D28B28188E79C2ULL, 0x8EB9A6B7299E084CULL, 
            0xAA2CF65A3D3AC7A5ULL, 0x76B9EEAAC644FD20ULL, 0x759D60CD59E9F12AULL, 0x689046B3B38C8379ULL, 
            0x26EEDDECB549318EULL, 0xCB6B53E7BDC6F2D4ULL, 0xC190D4A6C2A6B869ULL, 0x3BF1E4B86D090609ULL, 
            0x3EF79E03D988591DULL, 0x58F93EEAEF0FAFB6ULL, 0x4408DFF07DED039BULL, 0xE675A4435AC14D99ULL, 
            0x466210A4B497F54DULL, 0x48D8FC6EE2BA64A3ULL, 0xBF38A97C31146585ULL, 0x81D7B59253848E0BULL
        },
        {
            0xF089C89194394353ULL, 0x179601054364CAEBULL, 0x6584A1FE51FB4857ULL, 0xF155A81DD5DE981CULL, 
            0x452EE3E9F6C5E099ULL, 0x9E08C4FD151EE06DULL, 0x302B6047DEF73B8AULL, 0x9A0B57884875D225ULL, 
            0x116510507BE936F6ULL, 0xA9E4CCD992EF93E2ULL, 0x8FECD24C0FC08E95ULL, 0x7ED7BE79E7EE1347ULL, 
            0x41B57457DDDC76FFULL, 0xA71C6DB9D68709E9ULL, 0x47757CCD1266F0C5ULL, 0x86450135CE56C96CULL, 
            0x75FBDAACE1F34AB4ULL, 0xBC1115D9062547E5ULL, 0x36C9CCD668B81C5CULL, 0x41BB11B7F58C9444ULL, 
            0x194DAA5D5872AF59ULL, 0x5705E3123620E4A1ULL, 0xE1EC812CDF46AF14ULL, 0x3BDAAE7D7F76D3DAULL, 
            0xB9EC8AA88A8DA391ULL, 0x5A69B2CFD24C5C44ULL, 0x7DA58FEF60941F71ULL, 0xFE2018D1B0EA3238ULL, 
            0xBF8D5346A05E2169ULL, 0x901E48CB5AC3B91FULL, 0x5EBEBE4389A9706AULL, 0xA636ACEEA9F3F4CCULL
        },
        {
            0xF5AA9C00A1186343ULL, 0xFB6D6A16A8BD02A9ULL, 0xC72C118E560D861FULL, 0xC1B9C2EC87B1B020ULL, 
            0x6B3A8C0A3A3F87A6ULL, 0x9DDADE0A86BEB522ULL, 0xD5E3A209B6A92CD3ULL, 0x67CA7E904DE4FA17ULL, 
            0xBEB54719296FAD3FULL, 0xC4EA21BB402C8517ULL, 0xA6619F614F9CEFBCULL, 0xAD92E170B606957CULL, 
            0xF43BDFB99A151CCAULL, 0xCDCD6F803F38255CULL, 0xD138F96F96C5332FULL, 0x91EA8DBBBF722DA7ULL, 
            0x684D6626A245E9F4ULL, 0xE15DABADE976E243ULL, 0x1617C92DC545A8B9ULL, 0xD3FA6537EB9E064CULL, 
            0x66DA5CFDF99B461CULL, 0xF993BA6FDCDE7340ULL, 0xCEB3476B0763FFB3ULL, 0x5D272F58A852F56EULL, 
            0x1084E6F6877A7696ULL, 0x8B6A623384B27CC7ULL, 0xAD93A3DCEE7C4BE3ULL, 0x73B0B8F6561DCEBDULL, 
            0xB0F23166A3F8910CULL, 0x11C4D97ECF1A6C00ULL, 0x51C6E20A1A1DC93CULL, 0x0480F39749FCCB0BULL
        },
        {
            0x5CA75008B5CDF5DFULL, 0xBA7644694F961048ULL, 0xA2E7899CE8CC4C6AULL, 0x71FEB0541C47E9C1ULL, 
            0xA4A50DBC621B5217ULL, 0x3D7A2C5FE9F23034ULL, 0x2815CB339567B2A0ULL, 0xDC8AC5C25EB5B861ULL, 
            0x2355D0304A4FDC7EULL, 0xFF04570DA26FA6E3ULL, 0x973D4FEFC7C32EC9ULL, 0x4127E4BB3F0EAC1FULL, 
            0x9D6F113292B3392BULL, 0x42F9D125DB56C616ULL, 0x451A6E94F86D1F5DULL, 0x362FED15ED8D737AULL, 
            0xA364723DB9652D22ULL, 0xE238D4C260E41851ULL, 0xBC3987BAEB125053ULL, 0x018F9CCEA9041F24ULL, 
            0x2939911C3C5A3122ULL, 0x479429758031E746ULL, 0x321407AEBFFDC5B4ULL, 0x7E6B7BF4A4C99285ULL, 
            0x5EEF2659991C933DULL, 0x3F18A1A4F05592F1ULL, 0x1FD8FE716A0E5F27ULL, 0xD44F40ED7B39AC29ULL, 
            0x15B45CC49B396C03ULL, 0x66B384754B98E46DULL, 0x858ACDAC6B0CF682ULL, 0x42501F2C86E786BCULL
        },
        {
            0xA2B1FBC37635DCF0ULL, 0xBF8D1A2F5EDB6490ULL, 0x8A05779A106C30C2ULL, 0xD14469E66AABD845ULL, 
            0xC9D92CF155CD4CB5ULL, 0x21B276550799F7C1ULL, 0x257C82744B68F7DBULL, 0x9AB5B09BF70E1D1BULL, 
            0x13F2062AC2C43087ULL, 0xAD0ABC9B08D0F127ULL, 0x2C5830D6CF576D76ULL, 0x5839A2423B91BEE8ULL, 
            0xC68C793E58FFCDDFULL, 0x1D71568C1C1EE25FULL, 0x3F037B7030AC5EB7ULL, 0xADB9AEDA20455B88ULL, 
            0xBEFD8E509FFC6018ULL, 0x2FECD8BB5C2231A9ULL, 0x3D7A471580F997F2ULL, 0x1DFE1408551B652BULL, 
            0x26A8B666305D7629ULL, 0x7EE40312B267B758ULL, 0x5C36795B0E5E0457ULL, 0x7426001039043EB0ULL, 
            0x3860EADA4A26CA1EULL, 0x386DED2E11F26431ULL, 0xBCB3A73E621A21BCULL, 0xF22527F36B7A16C4ULL, 
            0x9579C7F6F56EF2A7ULL, 0x1EA7E43BFC344ADFULL, 0x98D9824A96984A5DULL, 0xD3C760DF1880E116ULL
        },
        {
            0x69FB62A13061B6EEULL, 0xF34ADB5C71FFE5AFULL, 0xDE809A6C5F9AC50AULL, 0x1DCEDDB9E2AFA8EEULL, 
            0x4D00BC39777BE87DULL, 0xCE1AAB2D8678FFA1ULL, 0x1A49B2F4B47A3E61ULL, 0xD5E7F47DECC7D0E0ULL, 
            0x5093534666A43E4FULL, 0x622830CDAFC6B330ULL, 0x6FA8B49D8D495051ULL, 0xD31905D1B9BDB515ULL, 
            0x77AED22701672D96ULL, 0xB2E4227F393945A6ULL, 0x64172EE5BC2F8236ULL, 0x4B54DF5ED338F218ULL, 
            0x318423BCEB30608CULL, 0xE578D53F89BE8515ULL, 0xA1626D2409C45382ULL, 0xA93EE7EA5442E46FULL, 
            0x8274DB5A3609CF79ULL, 0xB597AB3EBD6CE181ULL, 0xFA4E2D352CC4E4FBULL, 0x7CA74D127FF82C55ULL, 
            0x0E93D11BB93320A7ULL, 0x5C13892CD011FD8DULL, 0x22E2ECB095C70C53ULL, 0x3530B1838C63559AULL, 
            0x1783D4FB37B644B8ULL, 0x6CA69A62C1BF8A82ULL, 0x7896D15CA0948F31ULL, 0xD8F996B156BBAA67ULL
        }
    },
    {
        {
            0xBA1B133A3FBE841AULL, 0x007F7FF528256C94ULL, 0x4E9F40187F4D6912ULL, 0xCEB58BEAB41B22CCULL, 
            0x86C734EDB88F25CEULL, 0x3DE9A364087F1063ULL, 0xB463C7E4E5B5F2A3ULL, 0x599DC6C8A41758DFULL, 
            0x28A105918BA65A8AULL, 0x45AE1F755FD22759ULL, 0x63C40510F9CE65BDULL, 0x0CB0A1C85161B807ULL, 
            0xA10CF43597273EA8ULL, 0xE53334F777A0CB34ULL, 0x3649E37A3F9E0D07ULL, 0x492FA3C192C1325EULL, 
            0xDEE88BE9501CF70FULL, 0xB507E33361B64A7BULL, 0xB1CDAF06E20E0454ULL, 0xFD9829A6AA6E274CULL, 
            0xD00B2FDCAC0C69CDULL, 0xE7333A319EC884E5ULL, 0x143D52FC656E5F0FULL, 0x93049B683C9F742FULL, 
            0xA8DFC26B757CE0E7ULL, 0xB39A6A213D6F8B0AULL, 0x7A42523369ED5B98ULL, 0x4E14B0C2BD03375DULL, 
            0x747A2A7338F4CDE7ULL, 0xA0EF118058A83A43ULL, 0x2A5F789AAEE702F5ULL, 0x03BBDD635F8FFD8CULL
        },
        {
            0x4DBBFF7B3A78F22EULL, 0xBB58DCB7EE62D80FULL, 0xE38EB51728A0E937ULL, 0xD0C4DA7B26360BB3ULL, 
            0x91A30A99566AA097ULL, 0x08D8051D5DABE991ULL, 0x25E412FB523AB65DULL, 0x2FB35429EEB12FB8ULL, 
            0xF86656222DB65A6EULL, 0x6B375860474BB795ULL, 0x285C0562866FE8FDULL, 0x85D6C51D8D1E8A55ULL, 
            0x9B6B64A839AD227BULL, 0x57DEEE2FA6E15751ULL, 0x52FB937391A21155ULL, 0xE9D3926DBAA58BB1ULL, 
            0x1432FEFEF99916D7ULL, 0x2AE8F659E4B4A37BULL, 0xA3EE504BC546FA5BULL, 0x7EA6E8C4764EC214ULL, 
            0xD54C2176D479F68EULL, 0x9B17FE8FB9A2E9CBULL, 0xD7AD220E4D7DC52DULL, 0xF3D9D951F5D0FC09ULL, 
            0x4192F163EBAFF361ULL, 0xF037C27D582FD76EULL, 0x264C2598363CDF1EULL, 0xC230AAC258F99DB0ULL, 
            0xBE7DD78C41E98424ULL, 0xD180DFA16A095BE2ULL, 0xE7F064C311936426ULL, 0xAAB1DA0B9B6A9B86ULL
        },
        {
            0x8830D55631E2786DULL, 0x323B49A79114BD26ULL, 0x615BEBB8FEFC97E9ULL, 0x2AEAFBC5EC9A71BAULL, 
            0x8990AFE2052F0C5FULL, 0xC89CF19EA99F878AULL, 0xE3E66595644A8267ULL, 0x18C298E58BD1EE82ULL, 
            0x941E8730870ADF6EULL, 0xC2ED160422D5BB6FULL, 0x1B42BF760259FCC2ULL, 0x9ADA752318A65F8FULL, 
            0x37D6A4BC5BB5CADDULL, 0x6FEBBEAA8D063A8DULL, 0xF4DB1D4BA3A6C9E3ULL, 0x7E6C5191D4216BD5ULL, 
            0x0239894FF881E1D9ULL, 0xE948AA442049B8D8ULL, 0xE832B97FB3AD5616ULL, 0x45A3C6780F9FF441ULL, 
            0x7A64E0B007177A3FULL, 0x273393BD38D2D0A4ULL, 0x89C1412D87559165ULL, 0xCB1AA08BFB37071DULL, 
            0x05732FFDD96BB5CDULL, 0x6E70A4958C9F23AAULL, 0xC477EB0F91A3BAD3ULL, 0x6B4EBB78782913F5ULL, 
            0xE0A610E9F903CD04ULL, 0xE13E3BA7A7282772ULL, 0x8CF86F810C6EE849ULL, 0x3FB0283768724E34ULL
        },
        {
            0xA1983F59FEEAE783ULL, 0xD82659FC5520D372ULL, 0x2FC4F2457211C011ULL, 0x96A1FF4BB0DC90E7ULL, 
            0xB98BAFDC946F4ADCULL, 0x893F13AFD1F2A1ADULL, 0xABD8D0DD5A7E632AULL, 0x23E16C117730285DULL, 
            0x6408372C79C3277EULL, 0x8A5474F8A125D8B2ULL, 0x8BB0FD9440D439A0ULL, 0xE3BA5C3FADB63101ULL, 
            0x96518164CD10EB48ULL, 0xD22154A35BB5EE57ULL, 0xEDC0043901CCCA85ULL, 0xDBDB3D2574BD6AD8ULL, 
            0xC5C41525D2B28ED1ULL, 0x64EF06ABADA594AAULL, 0x836C3870F66FFDB3ULL, 0x210EE6F81A1A0D4FULL, 
            0x00F62C28B43A915AULL, 0x0F14C351800E58CEULL, 0xF7CD826F2A816BCDULL, 0xEEFE4A9B635091E0ULL, 
            0x8A98A8B7774D40EAULL, 0xDFB23D415B27283BULL, 0xD9F30B6500329985ULL, 0x278C820E4CD8EB59ULL, 
            0x48FAA1D1C1F4074EULL, 0x12F6EC92BE0BAA9EULL, 0x61AF19CF8D291A98ULL, 0x4628C34A6D9E0F1AULL
        },
        {
            0x76A00A50366FDA6DULL, 0x91FFF5C871640692ULL, 0xD5EACE15851F5634ULL, 0xCC3DAEA38A556010ULL, 
            0x35208D314D392AF2ULL, 0xEE2F954FB92F7529ULL, 0xD84D30F6F1ED6366ULL, 0x66315F914058D898ULL, 
            0x9B38F72BB247E702ULL, 0xB6D857E9A3D37045ULL, 0x85C53ED097574AC7ULL, 0x43E2CE026E3A28DAULL, 
            0x8B51F7F9BF2044B6ULL, 0x709D0AE5986E9923ULL, 0x4A8F9BA2B9388CD1ULL, 0x62BC45E8BEECBAFEULL, 
            0xBCE0A9F2E9F478DFULL, 0xEC64BE8102668D27ULL, 0x45C300D6C300078EULL, 0x3B7C0326801F6433ULL, 
            0xC9F6432684F9717CULL, 0x3521650C9E8AAC3FULL, 0xF8ECDB7D855DA691ULL, 0x600A07A1CB427197ULL, 
            0xF32AA77904BD911DULL, 0x8E4796F139A62475ULL, 0x0EE289DC616626A6ULL, 0x24ECB1D87FE961C7ULL, 
            0xF637ED8B17C7E8BAULL, 0x0DFBFF455F3C52D6ULL, 0x8D5F305B61007F4DULL, 0x59A39C1DCF4D3039ULL
        },
        {
            0xE9004E8B47F3DBE7ULL, 0x904307A35BB51D64ULL, 0xFE5F4F71A2D3F418ULL, 0x20F66150B3955C84ULL, 
            0x89860E514E54CE63ULL, 0xEDB59909485EDFB4ULL, 0x6404A5D4D6008B92ULL, 0x9CED3FFD342EC31AULL, 
            0xAB21F62203CFC107ULL, 0xD79AE301DD37EFF7ULL, 0x0A08822B7C58C987ULL, 0x5EEB8064B47AC5EBULL, 
            0xA14113DF72327137ULL, 0x1083DDB46234011AULL, 0xA18D36FC482A2D1AULL, 0x6A28FCD91BF4B5A5ULL, 
            0x3A81CE536325DBD1ULL, 0xFC556EDD8681D2E4ULL, 0xF9B450F2946233A3ULL, 0xCAB213E843B998ECULL, 
            0xFD479DEB7FBE5B55ULL, 0xAA5C628CB7FEB1E1ULL, 0x8E20E24772485210ULL, 0xE99B4B6C0AA51273ULL, 
            0x9BA7A81C94771AA7ULL, 0xBDB899EB33FAC03BULL, 0xA5831379D27C1745ULL, 0xE241F3EE46C685F1ULL, 
            0x87E2189C586BD55CULL, 0xBC1EFD9C6B75BF28ULL, 0x084B8BC3B5C0F9EAULL, 0x26A6E43023C55873ULL
        }
    },
    {
        {
            0x32E3566A09B48357ULL, 0xDA99D23B1D3FCEB9ULL, 0x0813AF589C8C8EA4ULL, 0x098A99D9F75C41D6ULL, 
            0x5394D5F7E28B4A3BULL, 0x651FEA7AA77AA2CFULL, 0xC262521E72C9624AULL, 0x41A91EDC87F61718ULL, 
            0xF2E0F4C70F77F04DULL, 0x6FE59195CA2B47C4ULL, 0x30F7B798473A6E55ULL, 0x759F5F338730C42CULL, 
            0xCA85179913F17422ULL, 0x64AA400972F9A4F2ULL, 0xF5C91706FA6A48A5ULL, 0xCA4BB9E32B1B5C51ULL, 
            0x8AA5BD3DA821E400ULL, 0x68F2186E156D7D77ULL, 0xE6FC0FC59E5D04B4ULL, 0x0D0CEB9FEF9EBB95ULL, 
            0x88F6326EE797FF29ULL, 0x510B7F8E0FC19E36ULL, 0x72517870330B84FBULL, 0xE7F847987A20EC74ULL, 
            0x506293D537375E9FULL, 0x29EF9E2C8366752FULL, 0xDF0FAFA6BE8611E3ULL, 0x7EAC8BEBA49D5ACEULL, 
            0x728F52F12E28C3F8ULL, 0x43F4334088B6060EULL, 0xAC7C59AABF32036EULL, 0xB0A8CD0C9A80751DULL
        },
        {
            0xD95A91B4E820D8E5ULL, 0x8406504EF88F4324ULL, 0x762DDA76DEBD1093ULL, 0x1614C8918852B135ULL, 
            0xC3C344FBE84233E9ULL, 0x665085A5734309CDULL, 0x1C5F2571EDFA2051ULL, 0xA2679B3D1275C8FBULL, 
            0x65D9705D52D1DA63ULL, 0xCA4A3613DF40EDE1ULL, 0xAEE3835CD02AB6B0ULL, 0x74B5E6688D576755ULL, 
            0xC72C200E0CA2D069ULL, 0xF3094226511AD00DULL, 0x987B06A17A3256D3ULL, 0x52960BD58268393DULL, 
            0xE4C0BA6EF08C6F2DULL, 0x09CC8FF6F6E507EEULL, 0xF6AB430D183632E0ULL, 0x9D42C00A7076E40FULL, 
            0xC52F0D6DA3F383FBULL, 0xA85C7EEDEF2DF109ULL, 0x410D9B15C057C3A6ULL, 0x5BF906667C779624ULL, 
            0x8EC2A42086D09E16ULL, 0x148EAC755616C343ULL, 0x3DFB01C10FDED366ULL, 0x2C7741D299EEC629ULL, 
            0x432FEECD967AAB59ULL, 0xF33FC74183EC77CCULL, 0x4F1674FD323DBBC3ULL, 0xEAF710213CE76261ULL
        },
        {
            0x6453005AD9D78F17ULL, 0xD10A5BC88F6E7574ULL, 0x3B6D32FEBEE374F4ULL, 0x0C6341D84A4BC7D7ULL, 
            0x063DB83EB67598F5ULL, 0x96ADF6C21D367773ULL, 0xCF30CCA0599D81C1ULL, 0xB917FEE1DAC54F7BULL, 
            0x43FFC874D025F0E4ULL, 0xCF89FF27C11F1CBEULL, 0xCE6D5330F98F1559ULL, 0xC2727FA88ACE0F28ULL, 
            0xF29528DE47BD6ED3ULL, 0xCA48056AD8BB3DCBULL, 0xFB38489D644E5188ULL, 0x72290F35AD227E27ULL, 
            0x1563ED43D73801EEULL, 0x6BB172DF04B71CEAULL, 0x9F31CD0C02DD507BULL, 0xF82FFA4BA9D8BAFBULL, 
            0x97CA2ECA53F2051EULL, 0xE2727BD499833225ULL, 0xABCDA2F136A57F53ULL, 0x65EDF5E06A30FDFFULL, 
            0xCC3EC741E679A477ULL, 0x8CEB4CC8A8ADF00FULL, 0x3A1D540B79F9F78FULL, 0x6FFCE47E090953B1ULL, 
            0xED53E2C05251E2BAULL, 0x391FF1D6B783BC33ULL, 0x6B5EE91D4D6B7AEEULL, 0xDAE02717D775CCFEULL
        },
        {
            0x3259950837D4BFF5ULL, 0x7AB8943CB6B8C191ULL, 0xE8C641C99B989ADFULL, 0x91F2A02786CA562CULL, 
            0x95F77E3DFF032E2CULL, 0x0598ED33062CA8A1ULL, 0x7BD3F39DCD15BD0AULL, 0x23C3AEE16141DA10ULL, 
            0x2F563F99C4B35995ULL, 0xC6827CFB61AFEC01ULL, 0x2D2AE12424CBE210ULL, 0x07C70ECD8F074664ULL, 
            0x27400C3BB6D9D498ULL, 0xAADC6BC8C1F7DA13ULL, 0x473BE014875476DEULL, 0x2A2211E97A0935B7ULL, 
            0xFEDDAE2C6939F790ULL, 0xE33748EEF55B17D0ULL, 0xBE27FF1398096BE1ULL, 0x838B0B6E5D3F14A0ULL, 
            0x40D09DCC4F997055ULL, 0x49D055D1BF941F7DULL, 0x0069F9D314AAE70CULL, 0xB491B647E5ED5747ULL, 
            0x8ABC2828B0EC11CFULL, 0xF492299302F24616ULL, 0x3F7341A5BC51C5BFULL, 0xFD23755D659F3557ULL, 
            0xD7BD25E0EEE46D2FULL, 0xA7811D0F4F42568BULL, 0x29674EFA19278228ULL, 0xF6A57F1CB0AECE4CULL
        },
        {
            0x0D2CAF90B464084AULL, 0x04B4261DAC551984ULL, 0x5E2B48F8A229CBEAULL, 0xBC04830FC960561DULL, 
            0xBC23DF6AF9E90921ULL, 0x12535CD52617561CULL, 0xADB0F54BAE82E377ULL, 0x8A1C1A755ACA3759ULL, 
            0x7FCC68CF973BB1A2ULL, 0xD049AB5063251D1CULL, 0x18E68AF6C256BA27ULL, 0xDE85C3DA76694E01ULL, 
            0x0C7B14DD011AA565ULL, 0xE811801B946A1452ULL, 0x9655356D923A3335ULL, 0x5FC79F9B6B0075A2ULL, 
            0x5F2418B848D4ED4DULL, 0x5683009A2900648FULL, 0xC8DC1C7B6CDDD584ULL, 0xE49D3BC542611769ULL, 
            0x9C9B8D92EB0542BAULL, 0xC07045BB14118D74ULL, 0x0197602BDC134027ULL, 0x73F5A7369AF597B3ULL, 
            0x510E212928587CCCULL, 0x30242AB326F37F22ULL, 0xF01C21FAB1ADFE20ULL, 0xC5B13086EFAF0ECEULL, 
            0xF43C136951074950ULL, 0x2CDB16F719A45574ULL, 0x7732A11AF9454B27ULL, 0x0F162D09FF0D73C1ULL
        },
        {
            0x13A62C497CFF5EF9ULL, 0x38116CDCCC958E9BULL, 0x041E32C89308E465ULL, 0x77F7D49D4A5FF0A6ULL, 
            0x0D98ABE592B3BC13ULL, 0x34F67F1395F6D612ULL, 0xDFFF51CDC41D3597ULL, 0x9F0C71191A0349BAULL, 
            0x61B57786677765DAULL, 0x45C59FAA5F6CAA56ULL, 0xA955FD287B92EDC4ULL, 0xB355BF73FE3D54F5ULL, 
            0x9F261DDB9C95523BULL, 0xF1947BD9517C1C64ULL, 0xCCDA35EF199B7E40ULL, 0x45079F303274CC59ULL, 
            0x26084EE8E505362FULL, 0x18821B3EDF943E99ULL, 0x1A0F4EB52CF13760ULL, 0x385B63F8B2A67106ULL, 
            0x77D6A9AAA035E85DULL, 0x1501D84914187725ULL, 0x4C8979D17FD9DA7BULL, 0x09817A3630503A47ULL, 
            0x7246277CDB4484EBULL, 0x4C3FEAF508D82B01ULL, 0x07E7B8969C2249E5ULL, 0x3723C0BFA175AB33ULL, 
            0x0513DD0B283D427CULL, 0x411B27D0571CE653ULL, 0x27D53EEB640CD042ULL, 0x0DBB0F62D6691F08ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseGConstants = {
    0x8455567D65185579ULL,
    0x5EE497AD41E8B70EULL,
    0xD74C777E30AE849AULL,
    0x8455567D65185579ULL,
    0x5EE497AD41E8B70EULL,
    0xD74C777E30AE849AULL,
    0x94A3C6980DE6A104ULL,
    0xE531F2A7A52E4BE6ULL,
    0x85,
    0xFC,
    0xD5,
    0x1F,
    0x7B,
    0xD4,
    0x92,
    0x6D
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseHSalts = {
    {
        {
            0xF52D84A01BD796D2ULL, 0x0C507C2B06015EC0ULL, 0x2D958697FA7C3666ULL, 0x78B42E1A663F0A65ULL, 
            0xE8F0777CD326CBABULL, 0x1E865C953E36EC93ULL, 0x4AE1EF37C0DC0296ULL, 0xC8481F4A553B6F24ULL, 
            0xCF0FEF8240746E39ULL, 0x19F39759FD4AE703ULL, 0xDC5C46E3FEADFF2DULL, 0x7C3F29634636B18DULL, 
            0x2BAFA71334DBBB54ULL, 0x8BBC44BEB49E6DB0ULL, 0x2491C9793DD09FA3ULL, 0x7916B9B8DA842AB2ULL, 
            0xB0CD2107CFD001AAULL, 0xA76329EF754F0DB6ULL, 0xD770729661C6AA66ULL, 0xE9194C28FD4407DDULL, 
            0xB2E48EB967F2E84FULL, 0xA017A57477E6DE2FULL, 0xC024056F2A5BF472ULL, 0xC5D14FE3F6423BD4ULL, 
            0xD5056067B1D26D3FULL, 0x86A4C681179BE50AULL, 0x07C4D54D95B69613ULL, 0xF4A066BF33042618ULL, 
            0xB06A0EBA29C27051ULL, 0xC93B489360937FD7ULL, 0x89E8580BF171A6BBULL, 0xE61C7835C5B1AEAFULL
        },
        {
            0xF85EE9B5E6D464AEULL, 0xBE2C7F91243CA776ULL, 0x31D21903FB63584EULL, 0x0E0A5F5E80FDC666ULL, 
            0x231956F4835C1A08ULL, 0x1AE3BBA41355ABBFULL, 0x8D068D89C602322AULL, 0x1A0BD0FC0F6517C8ULL, 
            0xD61ECE22FD502436ULL, 0xD6F5DE8B1E9D2773ULL, 0x21FEB64BB73B89D7ULL, 0x06BA883422D53DC3ULL, 
            0x1C607319FF9C3055ULL, 0x3BF215C0C814A705ULL, 0xC6B82F4FF3BB4F60ULL, 0x9D3A6AB3211C74DFULL, 
            0xF365B64BF992E18AULL, 0x9FED96DD26C4023DULL, 0xF1FAAB830A56A954ULL, 0x5CACC682C5B4324AULL, 
            0xFDC0D2194FD4862EULL, 0x7A72369D6CAE664DULL, 0xB5855656CB512B6BULL, 0xB4BFC97361637C85ULL, 
            0xCE83314478810C29ULL, 0xB99870BDF7AA7A53ULL, 0xBA6D6929F5B2FB33ULL, 0x9FC790316042D237ULL, 
            0xA123AADBD0BB2B2FULL, 0xB3ECDBD02F388232ULL, 0x4F177DAADD01A29FULL, 0xD4D7BF663E36F4AFULL
        },
        {
            0xA2E948B8E24C938EULL, 0x4FA3D247A385AEB4ULL, 0x09F6D702EE3879D6ULL, 0x68584E32F9828468ULL, 
            0xFC26CD9B06DCD417ULL, 0x29C609E2FDB9CDB2ULL, 0x58727EF42AB5A360ULL, 0x8EDB18D6C5EFF847ULL, 
            0xB9C7BF343E7A2BEAULL, 0x85280B370DD0F43EULL, 0x5C6C3C664B21B5D7ULL, 0xA3DF61E0F3677BE7ULL, 
            0xCD016D7A675AB7FDULL, 0x38B2F467DABFDEF0ULL, 0x5EF2AED785CF1CD4ULL, 0xA4ABBB40620AED13ULL, 
            0xAE8D2DE067E985EDULL, 0xF931A135BF4B11DFULL, 0x83DF6481A8D9B52EULL, 0xFC6090A4A6C4A7DFULL, 
            0x63ECAFFF9FF40F6BULL, 0xB964CA7BE59B934DULL, 0x98FF757BB30BCD8AULL, 0xB3F8DB0695F9D73DULL, 
            0xF0F2A7DE623A38B6ULL, 0x38012C3CA2F3A929ULL, 0x5569867A1B17D993ULL, 0xE212BF1CCC519DDFULL, 
            0xE4AA01A6D5ED56BDULL, 0x126A0510832647E2ULL, 0x8389D6801E114542ULL, 0xB35417B0DEBD9A0CULL
        },
        {
            0xA0FC917A49AF7D8CULL, 0xD61A5A86DDF78017ULL, 0xBC904D1F35605695ULL, 0x2B29ADD8D0D2F6C6ULL, 
            0x0F53012662A7E951ULL, 0x14FDB6E405CD5381ULL, 0x3356C06EEFCAAB11ULL, 0xDF08241577576DE1ULL, 
            0x745FD9DA7DDB24ECULL, 0xBEF1E90FF05AB72BULL, 0x7F9A38892888F39EULL, 0xA7FDF3BB17AE13C9ULL, 
            0xE46064ECADD1FB05ULL, 0x24DF8F363F1FA258ULL, 0x651905F5C1E6D178ULL, 0xFB95C340721F10B1ULL, 
            0xA0716A3065FE1AFDULL, 0xDC6244EE5735C67BULL, 0xC1D6B588D4BE97C2ULL, 0x1BD626D35D8EB93CULL, 
            0x7FE1F36E42D7DEDFULL, 0x2A25E3FD198C6117ULL, 0x8B45F7751136BBBAULL, 0x108347E13CC8CAABULL, 
            0xF0EFAF31CC66FDD8ULL, 0x61516EC58E4502E9ULL, 0x67BD4B2019E724FEULL, 0x67FB5D3E5BF67F4FULL, 
            0xF55F2F2C874E7400ULL, 0xFBBA7D59F647F9BCULL, 0xDE7599A3AA7C3266ULL, 0xBBF6A81419B7F59CULL
        },
        {
            0xA614117F2A754E45ULL, 0x98EF7FE2FCA747F8ULL, 0x6F7AB1F495EFEF3EULL, 0xBFFA08F384CA8306ULL, 
            0x723A13E29D7C29A6ULL, 0x274ADF38313E3DE5ULL, 0xB5FE2F45CE5804CAULL, 0x2AF35530AF59DEB4ULL, 
            0x57276972637A4D89ULL, 0x4BFCB6EA3922A5F9ULL, 0xC28DF72FC5577368ULL, 0xC2191FA2CEF25F6FULL, 
            0xB4B6596245888EBCULL, 0xF387E8A8C32D62DBULL, 0xE1FF8B1FB27E0FB7ULL, 0x1810D567723ADE8BULL, 
            0x61E15802BE34A986ULL, 0x3282BACD9F83831CULL, 0xB35439AB0F6B3CA2ULL, 0xFD7D75BF8C2DCCF7ULL, 
            0xE2FF20F805F71616ULL, 0x23E4FE42F919D74EULL, 0x4598715EB9A43AC5ULL, 0xB44502B3B1FDDC52ULL, 
            0x89E5C37B68379D42ULL, 0x9607F5AE63AB638DULL, 0x60D3776878E5B678ULL, 0x8C8C15E1F064FD5FULL, 
            0x5592E64734C947E2ULL, 0x8196199944F01E03ULL, 0x176B90C3A55DBCD1ULL, 0x83424B0F96E511DFULL
        },
        {
            0x14373F2ECEFE47A1ULL, 0xF3E163AB3547EDECULL, 0x796831F87365FD9BULL, 0xD6CBD3D2D60AAC25ULL, 
            0x2FD379F9B998AD35ULL, 0xE316A7160DD5D033ULL, 0xB9F5BEC4E70E451CULL, 0x47B5C216CDCF548AULL, 
            0x322B9F618C4291BBULL, 0x15DDBA7D40328D8EULL, 0xC03535BFA29B7127ULL, 0x3825EFCDF58CB65FULL, 
            0x8250343449F7F8D3ULL, 0xD88624FD2853D4ECULL, 0x97CBE0AEED2AB160ULL, 0x827B90D5644885E5ULL, 
            0x27598CA0DD455591ULL, 0x59125B7904464033ULL, 0xF2CA7A2261765026ULL, 0xFB3E41E422DD336FULL, 
            0x7F23209D4E55F948ULL, 0x4F4E39C69E437D1BULL, 0x9CE112099B8779FDULL, 0x127190D51A0B96EEULL, 
            0x59828A038211A30BULL, 0x9241ABB25386940AULL, 0xDCA36A212C48D0B5ULL, 0x53706A8E7C4CC9F6ULL, 
            0xE359BB2E117D9B27ULL, 0x6769DCF091D02E3AULL, 0xD5C6890F5378A532ULL, 0x6B72EB73839C4F7CULL
        }
    },
    {
        {
            0xD90C41700341E878ULL, 0x6B4357C0108A6027ULL, 0xD0488071B3C69ADFULL, 0xC12894239F332A5FULL, 
            0x66A04D82C5A34AAFULL, 0x869AE778B3106F9CULL, 0x43262B9B5102AC95ULL, 0x0F460C84C97C5B80ULL, 
            0x7D908D25ADEB1354ULL, 0x7961FE72DCA07E8EULL, 0x9E52E8A00642780CULL, 0x6729EDAC65500F2EULL, 
            0xB4C3AA0042A3815CULL, 0x3BE633E8815C009CULL, 0x4D08DB7BA756DD24ULL, 0x559383F06B4D013DULL, 
            0xF7217FB96B3734FBULL, 0x11E89F8DA0649554ULL, 0x06BE471AB0843889ULL, 0x7321D8989997E1EEULL, 
            0xA707AE5596078DBEULL, 0x77DB123971B797AFULL, 0x5C88922AEA6EF08CULL, 0x507C3C7181BA3F0BULL, 
            0x3D48897D5264B1E9ULL, 0x46EAB77A8B9296F8ULL, 0x5297AD87D35960A4ULL, 0xAC36AD57629C8704ULL, 
            0x2C4F353EE0E0C02FULL, 0x8055DEC9D8381F9DULL, 0x9A5554BCE5CED7C7ULL, 0xBCDBF6669FC0A6BFULL
        },
        {
            0x78589ACE32F843DAULL, 0xCD9542CF05D987F1ULL, 0xC615435404E19E4CULL, 0x52A74427FD4692ACULL, 
            0x1E6C8004FBBB32E7ULL, 0x9DB8E6513A16ADCCULL, 0xB66CF000050009EBULL, 0x70B9DA4B24DCBB7EULL, 
            0x0E62656C9416EF0EULL, 0x99AE4CE8A7F4D242ULL, 0x9EEC71E7491AAAA7ULL, 0xD9B1F8007C389D17ULL, 
            0xD0A6340FAE52A3F0ULL, 0xD222C4821F8C8F93ULL, 0x8E103B4CD56D73E1ULL, 0x0740B9A5DBA51D7AULL, 
            0x3CC2A3F78567EA15ULL, 0xED4F89970E6F2BECULL, 0x039230B8410DB773ULL, 0x9DD5364D3FE79F78ULL, 
            0x717202724621F1A0ULL, 0x1141A3CB8AF89E8CULL, 0x41C20F6299CA0707ULL, 0x0428621E7CC916AAULL, 
            0xDF75B41C24110902ULL, 0xA138E2244514BFBCULL, 0x03A54F067D52BE94ULL, 0x0F50BF5CB6EC5DD2ULL, 
            0x82858286B1555C76ULL, 0x23EC48308DD1AA9AULL, 0x31274FB22204D634ULL, 0x31839E9A7A676DFBULL
        },
        {
            0xC9860C49F6C07D6EULL, 0x3C03F78E8667158BULL, 0xC6A16D573E1537BCULL, 0xF9C588A1F5C78306ULL, 
            0xEAAC5045F77557C8ULL, 0xCAA351BC925A3C03ULL, 0xC137B875B985E64FULL, 0xE573A4662B5D6442ULL, 
            0x4E59EEBC878A00D0ULL, 0x857EE69670F16063ULL, 0xE81440FEC15188D5ULL, 0xE442BC19F095B88BULL, 
            0x7CB59AB70634D682ULL, 0xA1824751329E9BC5ULL, 0x56C65C15E7ECE4E4ULL, 0x526318E83A5B97FDULL, 
            0x0496CBB7833D4FBCULL, 0xC4CA3960289571A4ULL, 0xDC706A6741D06F2AULL, 0xF80EAE2B6481D723ULL, 
            0xF26FFEEAE6C881FBULL, 0xA8307BA627DEE2B8ULL, 0x43C46940DFF4A7BEULL, 0x06906A853A22DC7CULL, 
            0x8925426EED7288C7ULL, 0x0088F9BBF43EBD9EULL, 0xB6BD7CAE8F487FBAULL, 0x6A29EBA39410923CULL, 
            0xA084631CFBF279CDULL, 0xD94388E430E55088ULL, 0x37F6C185DAF0ACDAULL, 0x52738C6FD94CACA4ULL
        },
        {
            0x2131253143C7B91AULL, 0xD93BC8664C7DDC47ULL, 0xA305F6E6B66B4804ULL, 0x07D5947113280255ULL, 
            0xB3D759A8C0B0768DULL, 0x78539048068FCE27ULL, 0x7E3D9CCA0B5AF585ULL, 0xBD949DF4BDCFEB80ULL, 
            0x9C323331990194A5ULL, 0x249D73D3F5EB63B8ULL, 0x94D020402ADBC42FULL, 0x04B7D7996CE34FFCULL, 
            0x1C9EF0FF3224A84EULL, 0xD6DB388FE2A226FBULL, 0x032182F6BC986FB9ULL, 0xFE06CD201DBE1B9FULL, 
            0xB00F9C9F4C5B04D8ULL, 0xA0BF8966B1807B7AULL, 0xE312F35ADC5B86E9ULL, 0x9187FC5D03EC3B80ULL, 
            0x48B1C5A4B5BE5FC5ULL, 0x420B3E471BDD02B8ULL, 0xEFB4CEC40380DCA4ULL, 0xA05CA8F71DA0478DULL, 
            0x1F4E35A6D6307389ULL, 0xDFA014CB179A073FULL, 0xE76B74E8702141D0ULL, 0xC7E9347C370FB535ULL, 
            0x7E4664A380507F36ULL, 0x2FAAE50F5428B066ULL, 0xA09A8A6C59352913ULL, 0x98AB414C4AF2E316ULL
        },
        {
            0xE649561851F756DDULL, 0x415761D0D4EF4EA1ULL, 0xE929C28D0B8B1D6AULL, 0xF38F9D598B09DD88ULL, 
            0xDBFB4CA76A17F3F7ULL, 0xB066A9CEF0EB34CFULL, 0x804D5EA69F32252BULL, 0xEB50037CF9BF2CA8ULL, 
            0x58CE9E06B5C46849ULL, 0xB35BC04F1388F1CCULL, 0xBBE939CE35F65B84ULL, 0xEDCA3D86E82F7BA7ULL, 
            0x84EF9EA48DEB0D05ULL, 0x3A5529B03C67214FULL, 0x40B3350150FE8BDBULL, 0x3AF53E6B67A57E69ULL, 
            0x1D6D6EFB64AF993FULL, 0x2F13045AC7219C83ULL, 0xAE126C49EC9A2B68ULL, 0xB2CAE87468AD4835ULL, 
            0xB47BB8F18525D65EULL, 0x989CE2A0E829FCF4ULL, 0x1C0DF0E4FEC62BB4ULL, 0xB4E36B5CD3B0380EULL, 
            0x7F7509ED6D183473ULL, 0xBB2798622B87140AULL, 0x79E815CE17265550ULL, 0x20DEBAB426430335ULL, 
            0x1860FEB530A17C4CULL, 0xA7493152CBDF5FC0ULL, 0x7129AF9024CF2266ULL, 0xC9D1DBB93FFCE4EDULL
        },
        {
            0x5C90A8B8B1AFCB10ULL, 0x6189755BEE5308BAULL, 0x14478C169E12AA37ULL, 0xAB17D02ED0F5B96AULL, 
            0x1C596409FE566078ULL, 0xDD3FC7CF31EA668EULL, 0x3199BE74FBA9B5EAULL, 0xDF32F8B297A7B9A0ULL, 
            0x7F94BB3B0D341A50ULL, 0x2032E0D782C1687FULL, 0x84269C2CA31F7DCEULL, 0x8D73C29CFD86BE71ULL, 
            0x5FB5EDF4D3EE796AULL, 0x60DAEBD18AA69FCBULL, 0x70389301D263A24BULL, 0xDB7B8913FEEBEE24ULL, 
            0x4785FDF32A7DFB17ULL, 0x243B40B6658B0B37ULL, 0x74CDF349DFF1639BULL, 0x13D757C8B3C217B8ULL, 
            0x5E50FF2C7294B1F3ULL, 0x9B2FCE59152178BBULL, 0xFDBF9FE823102396ULL, 0x16E6AF7348E82203ULL, 
            0x683BAF252D3B90BBULL, 0x7AE3CAD1AE0AD6BEULL, 0x21D4639A8C8B1CD5ULL, 0xC4766F25C5D1BA38ULL, 
            0xA79090300CA29EF3ULL, 0xC3AC44843558F7BBULL, 0xFA41FB04BE018413ULL, 0x62F4C7BDD4FDF95EULL
        }
    },
    {
        {
            0x6738736E583279A4ULL, 0x785474035B831BA3ULL, 0x518E0BF2E3D6DE07ULL, 0x94E8929FE4C12A10ULL, 
            0xCDF9D5A5BDE3446CULL, 0x9EF4A832798C4890ULL, 0xDCFBB398D3711A0AULL, 0xFC0C3EB3DDA619BEULL, 
            0x693D7AAF610A7FA4ULL, 0xE2EEF23AB94A6C0EULL, 0x53E50C3260372389ULL, 0xADB0B1F9CB809BB7ULL, 
            0xBB5681B10D656B8BULL, 0x4405795CB8FA171DULL, 0x95E4F0F400F064A1ULL, 0x4C254D1360E50EC1ULL, 
            0x11A6C116F81A5224ULL, 0x22E6A1EDDCD54EE5ULL, 0xB2619E2B9C0D1CDFULL, 0x9057E17906FD43FFULL, 
            0xECEE7B880B4CCF9BULL, 0xFF9618D975E6B3FCULL, 0x0512B3B4080ADD8FULL, 0x3434D4051FD08A63ULL, 
            0xC4C7012BAAEE367EULL, 0x2976A13E4A2C6582ULL, 0x19B84CF26821E542ULL, 0x0F27A8E0757D7FE5ULL, 
            0x6514EACDBE3D56BAULL, 0x54659D4FAAA003DDULL, 0x2E3338F0677934DFULL, 0xB201A0C8E50C9F5AULL
        },
        {
            0x96CE89897BB2028EULL, 0xD473446FA0F309A7ULL, 0x3389CF32A797639DULL, 0x991D4B6357C2180BULL, 
            0x724892EC40C85ED8ULL, 0xDC243FF9E8B4D958ULL, 0x78E4F59447F70C13ULL, 0xF49A048E4B2C64F2ULL, 
            0x618467EBC0427544ULL, 0x5E62DCC09C306EF3ULL, 0x7014D8D625A6F336ULL, 0x337ABCCD9601C0A1ULL, 
            0x65F442205551E9ABULL, 0x03CF2BC9FD66E2ACULL, 0x6A86B0936A8FBD2DULL, 0xA742C3153E2E19E3ULL, 
            0xA1A1F3A834C2B8A3ULL, 0x35A6E3A327D5455CULL, 0xB188965C45ED1573ULL, 0x1F321D5DBDD2D4FCULL, 
            0xD2A48AA52ED3E05BULL, 0x38018FE9114BDBADULL, 0x7E75A13A49931DEDULL, 0x3953E9FB5686AFE7ULL, 
            0x362C4452940CA916ULL, 0xDFC507529ACEAF07ULL, 0x4C01892E93A4637AULL, 0x0C00119C53381C56ULL, 
            0xA55EECD5FB4AEEDCULL, 0x808D148E4E760CE1ULL, 0x885B13AD862777ADULL, 0x38ECA86E5E64F554ULL
        },
        {
            0xD3B75D71E05F6D64ULL, 0x9D6754BDF6253BC7ULL, 0xF0C9E94B7EABD39FULL, 0x4F1BFFE6A445F2A9ULL, 
            0xB1C14B9C0059F665ULL, 0xDEF4AA0215EAD3F8ULL, 0x274F520A53FACF32ULL, 0x5E8360BBDD73E036ULL, 
            0x9D58EFA74E6BF297ULL, 0x76B592BA73D8CE34ULL, 0x83862C7B2230EB59ULL, 0x303015E177A43C05ULL, 
            0x1506202E7C4C7DFFULL, 0x02F44C1F595546F4ULL, 0x811ED1209E4F1720ULL, 0xCB1EF9FCC417E9F6ULL, 
            0xF4F2011775079FE5ULL, 0x00E0F79C2297DE90ULL, 0x62E0AACA80A43398ULL, 0x6CE27B67A29AE29EULL, 
            0x5EADC9F6556F41C6ULL, 0x4677A6A3C39E1137ULL, 0xB8BB4A603332BC0BULL, 0x3234FD8527DBEC5CULL, 
            0x38083B99C95ECBD4ULL, 0x815B72166B419918ULL, 0xF5FFB223DC867208ULL, 0x5C0629EE854373BDULL, 
            0x44D54D33C5E03729ULL, 0xE847A930ED122233ULL, 0xFB68C8622097D421ULL, 0x0E65168FD9ADE84BULL
        },
        {
            0x146DAC728E69767DULL, 0x5B0DAAE0E08470FBULL, 0xA8C288E451442EFBULL, 0x348296C6D6AC4C98ULL, 
            0xD33D1B9374E95203ULL, 0x57F96E0571FE6625ULL, 0xDF4D583E9DF6B867ULL, 0x08C3C30F7ABF7CC0ULL, 
            0xFB86F5FAA2BB37F5ULL, 0xE4D79BC8DAE09881ULL, 0x20110AFD4AE27794ULL, 0x335E871466489CB9ULL, 
            0x171104814D355EA2ULL, 0x1795AAD36B1585B4ULL, 0xBA078C282E54E1D9ULL, 0xDB6698D35E13C0E0ULL, 
            0x0CED5950850769F9ULL, 0x2BA48019766FFB5BULL, 0xAD182E247C16F6EEULL, 0x3956BCE1C5741978ULL, 
            0x9C80945E82210ED2ULL, 0x3F7856CDEC537240ULL, 0xADA71093D04A9586ULL, 0xB2E9D3FEE76559F9ULL, 
            0xF9ACDF3C235AA603ULL, 0xADB7B7050E8199C1ULL, 0x179257BBCE1AA117ULL, 0x3A35D93EF2BC20CCULL, 
            0xFE7C939B4BAE2486ULL, 0x8A9C26A82218D12EULL, 0x7E83707C4263D023ULL, 0xB62D29BCD032087FULL
        },
        {
            0xA7BF39AC60DF9ED1ULL, 0xE8BB9B084CC39F4DULL, 0x7DD03EAD7BD06B38ULL, 0x67F04BB59296D2D8ULL, 
            0x5BB39471F2C8085EULL, 0x23D0E67B8F89E205ULL, 0x2EE910783EA756C1ULL, 0x9FC2D832D8E07632ULL, 
            0x4D9359E494AF6075ULL, 0x67D980FBA93D965BULL, 0xB4F6EC08B4552889ULL, 0xCE93AD02A5764B59ULL, 
            0xAD91015037D7B602ULL, 0xF4089627F39F7CCBULL, 0xF4411C10F4E46F12ULL, 0xE48BB37958AF87DEULL, 
            0x4BB4834E23ECAE05ULL, 0x0293C57F0D75899EULL, 0xDC519A82FDCF5BECULL, 0x3B5E085CB07E3E94ULL, 
            0x96AE4A3B9DD2E8FFULL, 0x6490B03E85C63EBDULL, 0x6C8D8922A75729F9ULL, 0xD8F1B23889D77C12ULL, 
            0x2090F8056B8025E8ULL, 0xEBAFE1AF06FB4C6AULL, 0x9704B0947A0D91FFULL, 0xB59D6813604C0A26ULL, 
            0xD03449FBB83C4BF3ULL, 0x5C89A83FD501F437ULL, 0x6CEA5B635F515819ULL, 0x348DCA3B6B179100ULL
        },
        {
            0xA1C5B6AE36C3A836ULL, 0x9228F49367D2F191ULL, 0xAD9C61F769D4B80AULL, 0x50D1114B0566C524ULL, 
            0xB53658E8EA175DCBULL, 0xB8D1A6377B1046BDULL, 0x018082890F49CC3CULL, 0xBD0E73BA3E8AA6FCULL, 
            0x741275A09712A9E6ULL, 0xAA2C3B433710103EULL, 0x229F598E6C0EF16FULL, 0x3A220FBE722C557CULL, 
            0xFE94123D8D69C9F6ULL, 0x1A3EF880C9CF4B04ULL, 0xF53E4634281E73F7ULL, 0xE421E281AC1E3E9DULL, 
            0x57F44303DF14FA7CULL, 0xC13475A2470F20A8ULL, 0x231295C14719CFD8ULL, 0x081531DD58648810ULL, 
            0x304DF8B5B1AE3892ULL, 0x2F650381B4560888ULL, 0x509A1CC5D60116CCULL, 0x81500A3AB386512DULL, 
            0x986944CE2902B7B9ULL, 0x66715E700B6AF7F4ULL, 0x47AC431935761F35ULL, 0x91E90A2D025A67A3ULL, 
            0x7777F4500ABD56CEULL, 0x79DA7370D1600711ULL, 0xBA2597BF7B66A7F5ULL, 0xD78B26EF04AB03F2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseHConstants = {
    0xC8D423786D41990AULL,
    0xA43133F6A5528859ULL,
    0xC39CD831F762FC5EULL,
    0xC8D423786D41990AULL,
    0xA43133F6A5528859ULL,
    0xC39CD831F762FC5EULL,
    0x8AC6FBE5040C17EBULL,
    0x3A0C590EA473C999ULL,
    0x89,
    0x16,
    0x71,
    0xDD,
    0x0F,
    0xF3,
    0xAD,
    0x4B
};

