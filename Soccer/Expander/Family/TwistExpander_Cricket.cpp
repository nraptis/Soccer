#include "TwistExpander_Cricket.hpp"
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

TwistExpander_Cricket::TwistExpander_Cricket()
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

void TwistExpander_Cricket::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xF441883D5C9A32A7ULL; std::uint64_t aIngress = 0xD59A80AFDE2E79FCULL; std::uint64_t aCarry = 0xB4B394018CFECC3EULL;

    std::uint64_t aWandererA = 0x8D21F8692F0E1FABULL; std::uint64_t aWandererB = 0xCA067C44F8C30DB6ULL; std::uint64_t aWandererC = 0xF3342CB517B1C4F4ULL; std::uint64_t aWandererD = 0x8A8185D5F672171DULL;
    std::uint64_t aWandererE = 0x8B8953BD474E924FULL; std::uint64_t aWandererF = 0xD61262524A515BC6ULL; std::uint64_t aWandererG = 0xD1F7674E39F75909ULL; std::uint64_t aWandererH = 0xAC64C04A1DE2F517ULL;
    std::uint64_t aWandererI = 0xE5C42A1EC8992D58ULL; std::uint64_t aWandererJ = 0xB82DD89B68F61EC1ULL; std::uint64_t aWandererK = 0xA6C83B55DAE905A6ULL;

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
        aPrevious = 18405753954094868570U;
        aCarry = 11518959762995621316U;
        aWandererA = 15685626957156815435U;
        aWandererB = 14175232232606369669U;
        aWandererC = 12729589767922055380U;
        aWandererD = 16283723756226722779U;
        aWandererE = 15042492134086434829U;
        aWandererF = 13220156628407585835U;
        aWandererG = 15080552596449287724U;
        aWandererH = 16875305369759239925U;
        aWandererI = 14452659959674826605U;
        aWandererJ = 15875445997286767698U;
        aWandererK = 9439465450778046406U;
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
    TwistExpander_Cricket_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Cricket::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xB9B761121182D768ULL; std::uint64_t aIngress = 0xA67CBFF18D1B09EEULL; std::uint64_t aCarry = 0xD7D6569A2E17D538ULL;

    std::uint64_t aWandererA = 0xD25EF46605D6E4B5ULL; std::uint64_t aWandererB = 0xDDD4C032CA0EB0F5ULL; std::uint64_t aWandererC = 0x9C6449876B65A483ULL; std::uint64_t aWandererD = 0xB3A3444AC2191411ULL;
    std::uint64_t aWandererE = 0xF9D210B1CD84E2D1ULL; std::uint64_t aWandererF = 0xA79BFB273116F10AULL; std::uint64_t aWandererG = 0x8874D9D12960F519ULL; std::uint64_t aWandererH = 0xFDC2BF660E774C7AULL;
    std::uint64_t aWandererI = 0xC2440800B12A75C3ULL; std::uint64_t aWandererJ = 0xC9785BF191C1372BULL; std::uint64_t aWandererK = 0xD727C3F12606C0D0ULL;

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
        aPrevious = 11425159501349629437U;
        aCarry = 9263272900934744218U;
        aWandererA = 16425635971604721415U;
        aWandererB = 10105013428159344121U;
        aWandererC = 10543807298402410809U;
        aWandererD = 11350678329707467789U;
        aWandererE = 12982043870989400657U;
        aWandererF = 11623124669060539401U;
        aWandererG = 11534069389391177920U;
        aWandererH = 17850210660681841900U;
        aWandererI = 15208065560865525319U;
        aWandererJ = 10479287148371931159U;
        aWandererK = 17505016833763557814U;
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
    TwistExpander_Cricket_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Cricket::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA152C460BC292E99ULL;
    std::uint64_t aIngress = 0xD8E585AE3F2A44E5ULL;
    std::uint64_t aCarry = 0xA8D0D8B98AFD7722ULL;

    std::uint64_t aWandererA = 0xEDB174B2291A67ABULL;
    std::uint64_t aWandererB = 0xBA73168A096F7BA5ULL;
    std::uint64_t aWandererC = 0x90579BDC806ED7C7ULL;
    std::uint64_t aWandererD = 0xC12CC98358E3E2CDULL;
    std::uint64_t aWandererE = 0xFA947124AE1CE250ULL;
    std::uint64_t aWandererF = 0xC134CB71D3FFB04FULL;
    std::uint64_t aWandererG = 0x8024EE5B9093C276ULL;
    std::uint64_t aWandererH = 0x9C5C8128CE52EA96ULL;
    std::uint64_t aWandererI = 0x852DC337528E48E7ULL;
    std::uint64_t aWandererJ = 0xF784F05D6C3B9A8FULL;
    std::uint64_t aWandererK = 0xFBDADA015D43F1E0ULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneE);
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA, 2);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC, 3);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA, 6);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC, 7);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    TwistExpander_Cricket_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Cricket_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Cricket::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Cricket::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA3A3F65026E5084AULL; std::uint64_t aIngress = 0x98636B199A6A15C7ULL; std::uint64_t aCarry = 0xFA8A5616C235F5A4ULL;

    std::uint64_t aWandererA = 0x950652A22A2AE497ULL; std::uint64_t aWandererB = 0xE40DECB45909D812ULL; std::uint64_t aWandererC = 0x9C80991FA71E2E2DULL; std::uint64_t aWandererD = 0xBEAE5B7A08655746ULL;
    std::uint64_t aWandererE = 0x82F8B908FA4A7FDFULL; std::uint64_t aWandererF = 0xF9653A34B010D524ULL; std::uint64_t aWandererG = 0x9BA1D3E0B54229A0ULL; std::uint64_t aWandererH = 0xF005E57B7A47193DULL;
    std::uint64_t aWandererI = 0xEC760CB43B0D7B38ULL; std::uint64_t aWandererJ = 0xB714E1E2E4B3090BULL; std::uint64_t aWandererK = 0xF77BE071C139FF59ULL;

    // [seed]
    {
        aPrevious = 15112883156856114534U;
        aCarry = 16735559104450201767U;
        aWandererA = 11939672893481524394U;
        aWandererB = 14123695473087494442U;
        aWandererC = 13392930290791328023U;
        aWandererD = 17930810492018302798U;
        aWandererE = 13207458686940209655U;
        aWandererF = 16705789947798281083U;
        aWandererG = 10348893723092839421U;
        aWandererH = 9237898786865798024U;
        aWandererI = 9684559542682533542U;
        aWandererJ = 10732106104276056299U;
        aWandererK = 13000769431289473659U;
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
    TwistExpander_Cricket_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Cricket_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Cricket_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Cricket::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 1, 0, 0, 3 with offsets 4151U, 7091U, 5539U, 2854U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4151U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7091U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5539U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2854U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 3, 1 with offsets 6207U, 28U, 3795U, 3059U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6207U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 28U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3795U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3059U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 1, 2 with offsets 7336U, 5246U, 235U, 7251U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7336U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5246U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 235U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7251U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 2, 0 with offsets 4482U, 305U, 3488U, 7880U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4482U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 305U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3488U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7880U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 2, 0 with offsets 1428U, 1445U, 1246U, 1247U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1428U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1445U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1246U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1247U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 3, 1, 0 with offsets 1778U, 547U, 1828U, 1599U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1778U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 547U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1828U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1599U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 2, 1, 0 with offsets 510U, 2031U, 1029U, 1233U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 510U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2031U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1029U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1233U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 2, 0 with offsets 1630U, 1205U, 185U, 1897U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1630U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1205U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 185U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1897U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1690U, 988U, 752U, 1044U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1690U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 988U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 752U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1044U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Cricket::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 3 with offsets 5290U, 7371U, 5319U, 67U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5290U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7371U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5319U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 67U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 0 with offsets 1822U, 7151U, 3788U, 2362U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1822U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7151U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3788U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2362U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 0, 1 with offsets 118U, 2504U, 3524U, 4105U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 118U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2504U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3524U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4105U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 2 with offsets 7176U, 7022U, 5657U, 590U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7176U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7022U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5657U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 590U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4445U, 1811U, 255U, 7830U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4445U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1811U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 255U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 7830U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1263U, 2045U, 1890U, 686U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 2045U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1890U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 686U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1648U, 168U, 302U, 726U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1648U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 168U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 302U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 726U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1831U, 1994U, 1487U, 928U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1831U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1994U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1487U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 928U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 603U, 1647U, 371U, 1517U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 603U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1647U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 371U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1517U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 0, 1, 3 [0..<W_KEY]
        // offsets: 1275U, 562U, 383U, 193U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1275U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 562U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 383U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 193U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseASalts = {
    {
        {
            0xD03B74BB7EDE2E2DULL, 0x7EBD408CED4F0CFBULL, 0x0E1DBB49A9992B64ULL, 0x9CFF7B72D4B9A063ULL, 
            0x9DCE4AB4053AEA35ULL, 0x016C2F4DD3776DEAULL, 0xE946673D0FB368E2ULL, 0xD62E377D865AA377ULL, 
            0x9EE50BFF43ADA4F3ULL, 0xE85C536186147900ULL, 0x1C39BB7012A88C6CULL, 0x413EB84096769E3FULL, 
            0x029F365397E3E6D9ULL, 0xACF4059F1A945BCDULL, 0x5CB160B2DC5BAC7FULL, 0x34A9102F3A19F519ULL, 
            0x10F21B0386AAE6B6ULL, 0xEC5F7881C4706AE8ULL, 0x7650EF6CA2A80A3CULL, 0x2AFE03CC102E222CULL, 
            0x7EC47BB859374469ULL, 0xE20A9E4F53887C93ULL, 0x0EF3674A93632C78ULL, 0xFBDCF50111A357B0ULL, 
            0x393D24C0BDADC6AEULL, 0xE300C808668E59D5ULL, 0xD66354AC0EC5EC50ULL, 0xC27FBDF13CCC2613ULL, 
            0x16E03F09AD1DDAD9ULL, 0x95E1AB212D3BD576ULL, 0x6F3A3C5C618F2E4EULL, 0x227B7F6DF2E1D830ULL
        },
        {
            0xE48DAD21269900A0ULL, 0x2C35972BB04BEE4BULL, 0x8A1E9B79F25109CAULL, 0xB38DFF7D3C8B5EFAULL, 
            0x6B8851676CA2C702ULL, 0xE05A72677761A1E8ULL, 0x392F78B0307BB1D4ULL, 0x56FB9541B245D558ULL, 
            0x76AFC4E3BFCE092DULL, 0xE0D38F7F4DFCC8AEULL, 0x6312A025B35B9B5AULL, 0x07B7060D9D997DB0ULL, 
            0xECE31568324BAC13ULL, 0x91268B800482464EULL, 0x6F5424140A9FB9FCULL, 0x1128B68AE8DCC4C8ULL, 
            0xD918D27E523A2AC0ULL, 0xCA87B69613FBE8D5ULL, 0x2656DC622803DF71ULL, 0x4846F154204A029CULL, 
            0x73EBC431F181CFDAULL, 0x5E1113D64DCB9C6CULL, 0x6777A88838553E2DULL, 0xB603D81FBAB39EDBULL, 
            0x501410AA53AAC9C0ULL, 0xE5607142C0DDD0BBULL, 0x7E2F86D9901A5409ULL, 0x1665B7CC7401E3E7ULL, 
            0x531ED1088A1FF9D0ULL, 0x9114C19416F110FBULL, 0x95418F9BA7D64FC1ULL, 0xDF2518B45654C70AULL
        },
        {
            0x66CFCD90CFB5E2FEULL, 0x3AD5755942FD227BULL, 0xF7EEA6B0CBE52AF3ULL, 0x7966CB4A44D11E42ULL, 
            0x3258F1EF18668A21ULL, 0x8006DF6D5E9D3A3BULL, 0x573C37A48A43DD8CULL, 0x102C68B285B62A93ULL, 
            0xDF16530E57E0375CULL, 0xDD542A0F89BB4E60ULL, 0x5D3414CEA4E39639ULL, 0xB76A795D717DF2F6ULL, 
            0x9D8FD9F2BF656B57ULL, 0x34C8A2A46A3DE8ACULL, 0xB9AFDD19EA193A22ULL, 0xDAEA0AF57E91B4F1ULL, 
            0xA00547EBF72A3B45ULL, 0x560EAE8B84EC3D62ULL, 0xCDD382752D3F5FA8ULL, 0x13D7445156401194ULL, 
            0xE1EAA13B2EE7B486ULL, 0x956CE27CB861BA25ULL, 0x9C9D05E5529BB180ULL, 0x657B8A3C83A82054ULL, 
            0x405E832F8AA1D921ULL, 0x83CFCC2F8F5C5E56ULL, 0x8272BFAC9966BEBAULL, 0xEE7D90071B05B650ULL, 
            0xC08E65772A51D5CEULL, 0x6FEC32E581E6C32CULL, 0xE0AB1B4894E56407ULL, 0x4D0A53B9348F639FULL
        },
        {
            0xB2D8177C4FFB5965ULL, 0xEAE600531ABAE89EULL, 0x55C6C882DA3BB445ULL, 0x697E1671BCD6EDDCULL, 
            0x7160658A90436FBFULL, 0x4A66A9A732439A70ULL, 0xB3E1DAD2CC1451C2ULL, 0xC88402A2A1F409ACULL, 
            0xD625FB3FED7E7E97ULL, 0x7A09E415B77572ACULL, 0x83EC2FCBDD6DCF11ULL, 0x902082EEF1A4CB2CULL, 
            0x0F23F322C70A9465ULL, 0x024D246CD84BE61CULL, 0x5DAA78ED6E57D02AULL, 0x46CBD029209D41CCULL, 
            0x14EAB0549080C151ULL, 0x32420C5EA3C518CFULL, 0x79FE24FD993362FCULL, 0x54EE896D5F887D0BULL, 
            0x5C20917E1F43F140ULL, 0xC99A6C6486B75699ULL, 0xD12FC27B3E308F6AULL, 0x4842E86F54B1EA7EULL, 
            0x90B9D1A61EEA5C2FULL, 0xE6F623C95DA1CF92ULL, 0x3AE287C3AB8C2507ULL, 0x5AAD51E633B8DC20ULL, 
            0x90841F4E100FA871ULL, 0x0EB64CDE119F0B01ULL, 0x45C7FED433ADAEC6ULL, 0x9CAA86D6587B27D6ULL
        },
        {
            0x79403286030CE2B3ULL, 0x99AD1A4202CD8F2FULL, 0xAC4EBE3CD3E47EE5ULL, 0x5FD9B294FFCB8C9AULL, 
            0x0325373AB20A3EC4ULL, 0xAEEF35012FB21D4AULL, 0x1B29B605D6A477AAULL, 0xF46FCB91D7222FBEULL, 
            0x3DB84D9F1FCCADBFULL, 0xFF281AB499542B8AULL, 0x5BE220C4BCF8E17AULL, 0xEA3709FFDB84EAF8ULL, 
            0xDBB8211D5B49346AULL, 0xE875BDEA0DF20465ULL, 0xC4E8761819675291ULL, 0x9CBF4C5AAFC4A369ULL, 
            0x10A59CC59796B6BFULL, 0x57161393E0DAF545ULL, 0x745049BEB0A31F21ULL, 0x67EACE53D86B201DULL, 
            0x540F7AED51207D4BULL, 0x75CD8F45E813F100ULL, 0xB94D46B55C9D0605ULL, 0x0111C5289CB861BAULL, 
            0xA337F65FB0CCD2ABULL, 0xAD8FF9846A9C666BULL, 0xCD5ED4EB3AF93EB9ULL, 0x470620DD1EC6BBF0ULL, 
            0xBB2AD831F2DADB74ULL, 0xACE9C54BF87E6481ULL, 0x59ABFCCFCA6EC0ADULL, 0x55BBCB70C2301D65ULL
        },
        {
            0xDBE95EC98A764A46ULL, 0x1EF56491603D9699ULL, 0xB23FD5858336A275ULL, 0xD4CF2093D5B68CBCULL, 
            0x47707B77BD933857ULL, 0x866864229442936CULL, 0x8D9C385D39404D7FULL, 0x1F711003BD84699CULL, 
            0x5E670F87B0ADBC4BULL, 0x70D5019C377A906FULL, 0x2282C5D3E9D78089ULL, 0xEE01B2F6110AB188ULL, 
            0x4196649A054DCE4AULL, 0x9879AAD4A32217F7ULL, 0x6EC1C6AC0C70B792ULL, 0xFDFB3CF3B1D45C41ULL, 
            0x603876085AD4891EULL, 0x6F921DAC0804855DULL, 0x4773CDD9C7AE0A27ULL, 0x211188CCB8398969ULL, 
            0x7F5A8BCCBEAD1683ULL, 0xB6433DD07F714D44ULL, 0xF7145A1B99E973EAULL, 0xF4C02435C62A131CULL, 
            0x0D27971B8AFD4666ULL, 0x9142828B22287C23ULL, 0xE8ED2802310F069FULL, 0xF531F2E0BAB0AC6CULL, 
            0x4BE81FCD56C4E1FDULL, 0x064C06F05F977DB2ULL, 0x9BB43D080A526342ULL, 0x9D99C712AC39293CULL
        }
    },
    {
        {
            0x289BF3F9DCF25C67ULL, 0x22CE5414C695E02FULL, 0xBD05ECCA3437424EULL, 0x004B214E1687CA63ULL, 
            0x8953C9ABA28A5589ULL, 0x0100408EDA46823CULL, 0x1B50F78F4A99C5D9ULL, 0x22E30CEF63ACD1F7ULL, 
            0x34EF58AC893E5D2EULL, 0x4D6F8001C56C0E92ULL, 0xC5357E09611AF695ULL, 0x16D006805E8B2E2FULL, 
            0xD37016F17A3EE9F6ULL, 0x5FD2BC2204775D8CULL, 0x6723C1D62BC79471ULL, 0xB87E5D5D2E818BB0ULL, 
            0xEDC208A143C39D99ULL, 0x9D88810E88C22583ULL, 0x299224E077842665ULL, 0xEE80CDD044ED91E7ULL, 
            0x26B5649B679F9BA4ULL, 0xFD041337A7149731ULL, 0x3C317C99E45D1527ULL, 0xACED835716CA23F8ULL, 
            0x710DDF784F721893ULL, 0xF57AEE4521CA1387ULL, 0x4DF7ABE18121A85FULL, 0xF8FE3808EBE3291CULL, 
            0x1BA2B5D3665922A2ULL, 0xC2AC2514BC920AEBULL, 0xBFFA77800965B836ULL, 0xBAF6AE994AF63EF7ULL
        },
        {
            0x54A6AB73623ED931ULL, 0x5DBB0CD86A89BC9CULL, 0xCB4C0FCA98CBCC8DULL, 0x96AC287074AF6D39ULL, 
            0xA754ED07BAB1CAACULL, 0x595EBB9C96CE4658ULL, 0x904048441622E6E7ULL, 0xBD1A2F96E437C8B1ULL, 
            0x61C2E4C07399E2A6ULL, 0xB08A102FFCAEA7CAULL, 0x09711D45E98E23C2ULL, 0xAEA4AED9ED1610B3ULL, 
            0xD4A948F8A5A3152AULL, 0x8DD43C6513152FB4ULL, 0x3EE12DB2FD7F9E8EULL, 0x4FC1A6D18C3C40E6ULL, 
            0xFD5831E830B84386ULL, 0xADBE2E79D9F84DE4ULL, 0xC60A7513FC6E090BULL, 0xED38441CF08108EAULL, 
            0xE397BEF215E65E96ULL, 0x624968E23AA08827ULL, 0xB52C2DEE76E75C23ULL, 0xF7F9B23015622E73ULL, 
            0x477D9BD871D9B0C0ULL, 0x586143B4ABF2CD01ULL, 0x2722B7A29A59A671ULL, 0xC388BA1DA411056EULL, 
            0xB83FFFF207AC9B2DULL, 0xEC4BA6F37735D78DULL, 0x3E714093E7285CAFULL, 0xD393BF29BDC3C65AULL
        },
        {
            0x151DF9450E57A13DULL, 0xEBBFD0C4CAC16822ULL, 0xE5BE9AF2EC74CC7EULL, 0x8150575D8162C53AULL, 
            0x1FF22ABDC37BAECAULL, 0xCA317409482AB320ULL, 0x1B5A4694FEDC5542ULL, 0xCBEFBA90BDE455BAULL, 
            0x6E3B965F16B54F27ULL, 0x25D5A92B601AD7F1ULL, 0x034764E19AC2AE77ULL, 0x1BE2C3C759022BC6ULL, 
            0x2B930FDFA99757AFULL, 0x1F15A389E0DE1FD9ULL, 0xF21D9CE6F9529CC5ULL, 0xD50C6B3E3EFE24E9ULL, 
            0x54C9518605EE26E3ULL, 0x8F4802B09D50614BULL, 0xDAC8F7157B2230DCULL, 0x5100CA567ECD211CULL, 
            0x372B765EF1DDA26BULL, 0xAE185801603AFD29ULL, 0x0F3ADB51AD887FADULL, 0xC35E316ECE4AA87AULL, 
            0xCD71D9A0117ECC1AULL, 0xE87A7E467285F2A7ULL, 0x23713E94C6D8934AULL, 0x1AA3DBB9DCCF77BAULL, 
            0xA3F3E725449DF47CULL, 0x51F09EF30EEE8975ULL, 0x841EA9D0D8FF3391ULL, 0xEB6094351752CD43ULL
        },
        {
            0xEE9C4F9FC69E7201ULL, 0x211C63B7E91054E2ULL, 0xE3E6865E3821056EULL, 0x9FF18663CD397798ULL, 
            0x6E11545371CD50B0ULL, 0x423D4A840246C1E1ULL, 0x62BD94B92732A5B6ULL, 0xBD93616D8601D3AEULL, 
            0x09BCFA54CD34040CULL, 0xE0F2EC22B3466F04ULL, 0x6F4ECB9A35B2115FULL, 0x03D3BC6FF0442E17ULL, 
            0x3DF305DD221892AAULL, 0x75BBFFEB7A5B9137ULL, 0xF499739E917FDEE6ULL, 0x66A07AA9338A3E20ULL, 
            0xC41187BD9BD034EAULL, 0x99BA323D9496310BULL, 0xC0A95BAD09707968ULL, 0xD728445032DF94A0ULL, 
            0x4556593C5DF8A3FBULL, 0x851EF604BBA3993CULL, 0x755B5606F1B14B7BULL, 0x416E9122C69D4DD7ULL, 
            0x9891C113E8C8B0BAULL, 0xD9803FDAF92BD368ULL, 0x6D642FEA71117BB9ULL, 0x33628EB9CAE104CCULL, 
            0x7ACE773D760AD719ULL, 0xBC3B26A7BC37A929ULL, 0x761077E35DFA38C3ULL, 0xD338350E5FCE88B6ULL
        },
        {
            0x5181ECFED6E15EF7ULL, 0xA6652FEB3B370104ULL, 0xB6823435764F5446ULL, 0xCF5A3A062F733CE6ULL, 
            0xF42DD4E499889475ULL, 0xB2431CB133AEE523ULL, 0xCC3C9208F20D729FULL, 0x6C2254BD989CAD8DULL, 
            0x53EA36198E136802ULL, 0x6C33C708ED9FC165ULL, 0x05EBC6753BC9A9A3ULL, 0xBAB6463DEA964BE2ULL, 
            0x6EEED923D0373C80ULL, 0xA1BABCEE75BB6DF7ULL, 0x871A02AE5F745034ULL, 0xBDB1E7B81437FC70ULL, 
            0x21075F8B7841D2CEULL, 0x412F1A8151327D0EULL, 0x59905D51C1DDC724ULL, 0x66D0CD4B05916881ULL, 
            0x6CEB21D860DE7234ULL, 0xF5D180291476D04CULL, 0x8DD8D4B1FED1826AULL, 0xE5C05FAE93F8B4B6ULL, 
            0x50FBC49CE88313ECULL, 0xDA60575D48453061ULL, 0x7691398175C83D75ULL, 0x622A840FA5EE7520ULL, 
            0xAB0D9EBC0E87A280ULL, 0x5C6A112A96DA681EULL, 0xDE13B199BD92390CULL, 0xACC6853976B3D974ULL
        },
        {
            0x1174B9C01F30953BULL, 0xFED74892A9668009ULL, 0x896C0F7318236BBBULL, 0x2C794325605329D7ULL, 
            0xDFF78DDA85953CD5ULL, 0x62F9E80D1BDB8C3EULL, 0x7798178BF4BC2EECULL, 0x901F1879AD12A4EBULL, 
            0x6905ACDA18665215ULL, 0x148EECA8CEF2B6C2ULL, 0x53017C7EBB2FFA94ULL, 0x596797C43872E4B4ULL, 
            0xA97E986626B55117ULL, 0x43864D7CFE172648ULL, 0x4E2629212E8ECF22ULL, 0x7EF72376CB6E83AAULL, 
            0x1FA3CCEE3DAD870CULL, 0xEA75414E32546193ULL, 0x11708AEB27BBBFE9ULL, 0x2E2EB7361404284CULL, 
            0x1E14A6FED367D6E1ULL, 0x49FD43A932CE04AFULL, 0xE0E04EA68D92DE05ULL, 0x8A628AE34AD4516AULL, 
            0xFBED63EDAF8EBB0CULL, 0xF2123B926DCCDE15ULL, 0x1576623353A8AA9DULL, 0xDEF5499E2D610526ULL, 
            0x6252C58E02B54E40ULL, 0x84456F4EC68B7609ULL, 0x8AD968273A1073C8ULL, 0x3639C3A3EB375D2CULL
        }
    },
    {
        {
            0xEB787DDCCFB42C2EULL, 0xE0752E0914EF3003ULL, 0xB5795F06AA6E8BD9ULL, 0xFBED553F40A43831ULL, 
            0x7C56E889E3DF75F8ULL, 0x64BF0980EA7337E8ULL, 0xA6492804B9719ED4ULL, 0xCCB868CEF44BDE30ULL, 
            0xB7C5342E42845586ULL, 0xD758D3BED8A8329DULL, 0xBBA3877F0B7A4FE2ULL, 0xBF588FFDAD80A9BDULL, 
            0xDA92342E23AB713EULL, 0xEC793E6184D3A72AULL, 0x4B58E28778828A43ULL, 0xAE1ED0C60705D5BEULL, 
            0x9307BDAF6DF8838BULL, 0x5F68C00863B9192EULL, 0xEEC2E530766DC8F8ULL, 0xF4533F3501B29C1AULL, 
            0x1E5BDEDD86FDBABAULL, 0x103D064C446579F6ULL, 0x06FF24F425C18F7DULL, 0xA92FDA9C064478B0ULL, 
            0x10A4C75596AFA50CULL, 0xFC000F4F009BC8C9ULL, 0x054E02D170EF6D4BULL, 0x12EEAD34D895296AULL, 
            0xAAC2689A98208664ULL, 0x833185D69FC3EFEEULL, 0x1A88E05FC32E7725ULL, 0x5D8B001EF91E4D9CULL
        },
        {
            0xE78D8CAF6D5A90CCULL, 0xDBA04F0B816593E4ULL, 0xBE9DCA5012E276B6ULL, 0x52EE5CE5C5D6D6A8ULL, 
            0x235E16814842CE5DULL, 0xC4262D26C502CAA0ULL, 0x4A250440372C5EECULL, 0x38513CB66D4DBAF1ULL, 
            0x93FC6AC749A77432ULL, 0x9B8509B489DE7F61ULL, 0xC8829E24855F0089ULL, 0x176D6348B2B06E09ULL, 
            0x65822060102A56BBULL, 0x74226C546717A4EDULL, 0xE16F2C79253DE2ADULL, 0x1AA03F85EC742656ULL, 
            0x5A07C5ADB6FD3919ULL, 0xC306FF660BA91C54ULL, 0x3363935371D58773ULL, 0x4396EF969C39CEA5ULL, 
            0xB9692C2724E4B5F2ULL, 0xBC289D4C311C73F7ULL, 0x7A898380DC05EF1CULL, 0xD9FB37FABEC003D2ULL, 
            0x47D8873A58E20F52ULL, 0xA79E9E40833E3333ULL, 0x5506020C43F7BFFFULL, 0x63467CD3B50C3DA7ULL, 
            0x10D5A88B261B249CULL, 0x906CFE5CAA972B03ULL, 0x4CFE879F2E75EC27ULL, 0xCA41CB604210FC96ULL
        },
        {
            0xE18C4EA3BCD3013AULL, 0x4AD823FB0F4E544BULL, 0x2C49C0628C0F8001ULL, 0x3C4C4FE305B5EFB4ULL, 
            0x15769C331DE4DFE4ULL, 0x5961B125AF044BECULL, 0x1469BE2AD9AF31CDULL, 0x35A996857CD780C3ULL, 
            0x3F048CF5BE88C341ULL, 0xC39051F1DC453725ULL, 0xAAE8651C728406E8ULL, 0xD22BBCD04BACA91DULL, 
            0x57673A1211254197ULL, 0xF44EB9CF8FF51A57ULL, 0x28388FACA2765E99ULL, 0x742345A9C2B674D7ULL, 
            0xBA54D8D3D307E6E3ULL, 0x24E4DE5D0A7CE9F5ULL, 0xEE51618B4F09CE1EULL, 0x61013C553CFE4EDAULL, 
            0x0C3E3CCE74F7886EULL, 0x22DC140F6CF286A7ULL, 0xE14C10BF70384DD9ULL, 0x0D94CF1B17C231ABULL, 
            0xE0A7B80820DA4B86ULL, 0x387B4327FA3771E8ULL, 0xC3561C8D45609330ULL, 0x7845ED1BCF154890ULL, 
            0x0DE1C29E770F4FD0ULL, 0x00E8193144F77B36ULL, 0x97D84F50672C5FF8ULL, 0xB3C684E43ACA2872ULL
        },
        {
            0x70DEB8C2BCAB51CEULL, 0x3542B6BB5A570568ULL, 0x128FDC284090EF0CULL, 0xD3B26A91C64BCF52ULL, 
            0x9289AB18EAA1666BULL, 0xE9068DFECCD1D017ULL, 0xB517D6949F673222ULL, 0x480C8815D3066A29ULL, 
            0xD6DBFF5E47AFA791ULL, 0xAF80B4401BFCB7FDULL, 0x3EB266A1A769FD90ULL, 0xF13CD526FB1A7DC4ULL, 
            0xB33144A3261D190BULL, 0xD01CD580505B4328ULL, 0x6C16A3BCAE805E6AULL, 0xA1FD18B1E30E201FULL, 
            0x076F0E385F8001D8ULL, 0x5DF1EBF6B2E1B42EULL, 0x766F065E821689F6ULL, 0xB1525DC868D3CF97ULL, 
            0xE023EA9A222661E9ULL, 0x178F48D0D532ED5BULL, 0xFB1EE084EA76A0F7ULL, 0xDE0D3555E910EF64ULL, 
            0x750BDBB32F3C0AE6ULL, 0x3DE1255A74831D3BULL, 0xE733193C2ED07299ULL, 0x405C076E210AEDE8ULL, 
            0x883516F714AE032DULL, 0xEB4526F172692FB3ULL, 0x785605D8A4BD8981ULL, 0xA44F6B033EA37A51ULL
        },
        {
            0x79B7D203B7111F7FULL, 0x47A20A9106E557CBULL, 0xD5438CF0C0124682ULL, 0x2FF16662E000BF4EULL, 
            0x59D2605AA02C1D9DULL, 0xF1484EDF2A913EFAULL, 0x5E99E9153F98D4E3ULL, 0xCC9DDCA7BBC4887AULL, 
            0x4739B828B5B0A23BULL, 0x417B48A941EC787EULL, 0x71390EF392E6CB4AULL, 0x10341516B0AB1629ULL, 
            0xDA62F63577EA1BC6ULL, 0x40892B4BE866493FULL, 0xA2435EABFDFDD128ULL, 0x2151E466C6E5C8B8ULL, 
            0x3B11CCA9214C97B9ULL, 0x79C74363CA68403DULL, 0x6F4EB6873A20D79DULL, 0xB36E2071BD07A47FULL, 
            0x03B81A367F67A60EULL, 0xBDABAAFC3CB0E23AULL, 0xDB364BB4AAA92C6FULL, 0x2342EE8CF24C07ECULL, 
            0xC6C216A2E642EEA6ULL, 0xE6A08083239C659DULL, 0xEAB14CD7D432ED2CULL, 0x06680BEED4170F77ULL, 
            0x130F20D29D631DBCULL, 0x2F352479AB0A9215ULL, 0xAD7502C46830B029ULL, 0x613EB984F59BA05CULL
        },
        {
            0x0FE401E3691F5E9BULL, 0xC249F77501220B7CULL, 0x1A58995470BC20D3ULL, 0x9A2591E73B34C0FFULL, 
            0x8472ED49D87E099EULL, 0x9B8F4DD48A6BE4B7ULL, 0xF658B979E05162D9ULL, 0xCCF86472B9D6EF78ULL, 
            0x8E3B66E8AB383C6AULL, 0xF596DB246F0C8B67ULL, 0x52CE4123A8BED84BULL, 0x314961910B74D393ULL, 
            0x06865C0C9D4F06EAULL, 0x211EB21666391609ULL, 0x2BAF9D0E45C5FEE2ULL, 0xC1319B513E128793ULL, 
            0x5C252584441C1646ULL, 0x0B6BB4CAEABC4C65ULL, 0x8F6482F359104619ULL, 0x380C1A7E8DBEAE82ULL, 
            0x6F3A984D82DAE9DEULL, 0x557A434A86558CDFULL, 0x6D9D8A5F7F07B3AFULL, 0x5CC02B86AD9FFBFDULL, 
            0x29D79BBAC14829DDULL, 0xC06A9E1253D9A7CFULL, 0x2EA1F9EFB99E71A9ULL, 0x9884DAF159EB4794ULL, 
            0x783435EE33EA5EFFULL, 0xDEFD71A026F3CB09ULL, 0x9409CC7D9777BD0DULL, 0xF3E061D07ADC6322ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseAConstants = {
    0xBC66F4DE120C1C42ULL,
    0x6C71161A6EFF7159ULL,
    0xCF29D7B8EFCE50E1ULL,
    0xBC66F4DE120C1C42ULL,
    0x6C71161A6EFF7159ULL,
    0xCF29D7B8EFCE50E1ULL,
    0xCF5D2010A5D9A489ULL,
    0x1ECF4C7ED924EB90ULL,
    0x68,
    0x12,
    0x39,
    0x23,
    0xD2,
    0xE4,
    0x89,
    0x92
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseBSalts = {
    {
        {
            0xEB9E1EEC71D1CC5FULL, 0xE5FFB79F46B85A46ULL, 0x83F4974BE673CEF2ULL, 0x5807034D90167B37ULL, 
            0x4F769246669201A8ULL, 0x9B199CC79884A92AULL, 0xF094EDC4C5E3E77CULL, 0x5B88B10189128E69ULL, 
            0xCBF59C177D80E8C1ULL, 0x59C2B8C2F64F3DEEULL, 0x7DDAF5D0C1626EBEULL, 0xF4C28603B67DA9FEULL, 
            0xC2F1D11C8C2C8FCEULL, 0xA99999369E6FF208ULL, 0x239F3EAD9A446E63ULL, 0x5957F9A7A40F2C1CULL, 
            0x023410CDF7057A4FULL, 0xC7580E6B7559470DULL, 0x44013CA220CBEEFDULL, 0x627348A18F2DE453ULL, 
            0x1E2C2E28DDA26E68ULL, 0xFAA7FEBCBE5B6F62ULL, 0xF496E44516A2AE75ULL, 0xE5BBDE21FA4F7F17ULL, 
            0x630DDEB542D3E36BULL, 0x3DBEFF41A7872A2FULL, 0x3FDD69BFCF540605ULL, 0xB02080D274BE56F4ULL, 
            0x84A412A1C2D7110FULL, 0xBDAAED395F883D96ULL, 0x17B02F2E71291AD7ULL, 0xC9937560ECD81203ULL
        },
        {
            0x260926A41CC52E39ULL, 0x2CE35A7621721DF8ULL, 0x2CCC313C10B9137BULL, 0x4B89EEF555EEA659ULL, 
            0x2293E2F195EA7AF1ULL, 0xF4895F109DE9642BULL, 0x55B2333663D25558ULL, 0x9F724D8BC9087C9CULL, 
            0x4470749FCD74568CULL, 0x8296E25683DDEFA0ULL, 0x6CD5A03375596349ULL, 0x5E314C41ECD83BA8ULL, 
            0x29D462722E93550CULL, 0x59CC6EE5CA6EA8D6ULL, 0xC3F444352F8C47A4ULL, 0xA9B73D666A2185BAULL, 
            0x9F6B404107B25540ULL, 0xC5E4D21C0E85E617ULL, 0x14EC17E73780911EULL, 0xFBE287DDA50FD7F6ULL, 
            0x4865A64C4492D872ULL, 0xEB6D0C21E6E34A03ULL, 0xB02620901AC5A650ULL, 0xFAB8BD14BABC013CULL, 
            0x0E369600A8FF5485ULL, 0xE58E8FF11F0303DAULL, 0x865E9465C475F560ULL, 0x2B0065A6AF1F2D36ULL, 
            0xB4FCA75F27F45F40ULL, 0x089C26810DD6ED95ULL, 0x22898BBB0AF86003ULL, 0x7FB71046A059E464ULL
        },
        {
            0xFAC33CB467DE7654ULL, 0xBA140F41013A032DULL, 0x1C37D12F72BA41FDULL, 0xCA4FA1287CDCB012ULL, 
            0x60B75B9A1E4901DBULL, 0x1C57B60B5E2C2775ULL, 0x1766FE209105F59CULL, 0xB9BC94B0EFF7B723ULL, 
            0x2E9498557C17D8D3ULL, 0x728D5DF0A32FAD13ULL, 0x7C4D5BCDE714DA0BULL, 0x7D6113B4A4D85638ULL, 
            0xFB62CD3BEF759ED3ULL, 0x9AD3588314E45B13ULL, 0xDD9247172640D008ULL, 0x6D89E60B5E875439ULL, 
            0xA6E2F48D0C7C2527ULL, 0xF7EE0A4BFDAC8D52ULL, 0xC46866E5C348EF43ULL, 0xAE1FE748FDDC26E5ULL, 
            0x56A45696C5E48839ULL, 0x2536E059C44DDC32ULL, 0x7BBD30FE652A1F49ULL, 0x4BA8991B5E0309F7ULL, 
            0x34799893C32597A4ULL, 0x03718BE1F9F54282ULL, 0xB14EBA186B19136AULL, 0x3A6CF789A282D357ULL, 
            0x7A7059F3F6656ECCULL, 0xD3A9F73F44D3DFFCULL, 0x77E71FE858F75F48ULL, 0xA42220CF4AAA2147ULL
        },
        {
            0x9459D0F50DC26CA7ULL, 0x67728BB1A22F7483ULL, 0x64340B7ADCADF33CULL, 0x15A1D9AE7D6C64BCULL, 
            0x9FB1A39A2FF351D7ULL, 0x4F2753876B328363ULL, 0x9917BAB3B71AB01BULL, 0xC1D1DAA3FBAD5022ULL, 
            0x246B50A040381AD4ULL, 0xD86EAD7792B1E2B3ULL, 0xF3947299B8BD36F4ULL, 0xB4CB04E5E76C16CCULL, 
            0x5BDBE35FE620B50CULL, 0xCBE5616CF395C9E9ULL, 0x05E0A5C5B8320990ULL, 0x894621F57C34471BULL, 
            0x20277A7512C85C4FULL, 0x271ABE9FDE0DCFEBULL, 0xCD22A372E20FED1EULL, 0x1B9EB78ED18015EEULL, 
            0x36C6AD24E1174095ULL, 0xCDA755E80F41F50BULL, 0x10FEBE57F0874925ULL, 0x570ED3E7F4EDC880ULL, 
            0x7A69AE5AEFD60D0AULL, 0xCA37DB72EE3F79BEULL, 0xAD1EE348415B275CULL, 0xD22181211F73B767ULL, 
            0xF2B90EF1CE3E0523ULL, 0xE762BF72003D7ED8ULL, 0x1D0DEF87BDEC6170ULL, 0x73D4E364758990CBULL
        },
        {
            0x5108490E3D6CD576ULL, 0x484B74FD634E1C5EULL, 0xBE80D79DBC049ED4ULL, 0xD6AED2494C905F67ULL, 
            0x2F7AE22C59EBE78DULL, 0x03B7034D463BDEBCULL, 0xC5762FDA1941133CULL, 0xAB54D5B2147180FEULL, 
            0xE6E49581E1881CF7ULL, 0x505C5B614289B4F7ULL, 0x05A7E5B0C8C19CC1ULL, 0x8E72EBDD1607337BULL, 
            0x3E5352B6EFE23528ULL, 0x3A6230F0AF3C28C1ULL, 0x18758687F80F6905ULL, 0xBD84A1F46ED5467FULL, 
            0x067E3A967B205148ULL, 0x2B6DA9CA207240D7ULL, 0x9C08BDA08C7B1772ULL, 0x0802E3453EABC3D8ULL, 
            0x2E72CB445BA23FAAULL, 0x60E60C2B080A94E0ULL, 0x90391906EF43E8FEULL, 0x48FED6AD202B7E5CULL, 
            0x3C1ECFB1CD683C0BULL, 0x7A66AFB9C32562A7ULL, 0xCD877FA7DE1EDAECULL, 0x140F14DD8F2E5ED8ULL, 
            0x302114B7538A273BULL, 0x450DC22FA3CBB5F4ULL, 0x07C30B8653D9677FULL, 0x680D10BB5D84981AULL
        },
        {
            0x9AB7CDBCC4C28847ULL, 0x35C1E43433CD77C3ULL, 0x4FE7C67D9CCCD605ULL, 0x5C482F77F008963AULL, 
            0x8986FE408F8B80B4ULL, 0xD2AE5C9FB2FD1424ULL, 0x6EC4BC84890749BDULL, 0xE7F4CB254D9F27B4ULL, 
            0xB33F20596454A5A6ULL, 0x4B0372D88ECDDC3FULL, 0x49F94F12DD8D9529ULL, 0x6699F1F60C87A401ULL, 
            0x501AF1DCE937CDE2ULL, 0x1830EA6AE7C3E0DFULL, 0x45B5BE98BA6C1D5AULL, 0x1F0B59D6F02D3A45ULL, 
            0x5A89B6496DA4F4B4ULL, 0xE0F11FC99080D702ULL, 0xFECFB2AC601C5996ULL, 0x3CB37E205F7CC2C9ULL, 
            0x3208F5B7E76BC34EULL, 0x8687CF1388B6BCBEULL, 0x827190AF0E4DE1FCULL, 0xCB3069AC71C3485BULL, 
            0xF83DEE78CE88B519ULL, 0x89EFBB9D29B740EEULL, 0x99DFA7B4DB9B3C68ULL, 0x31C44290E1752912ULL, 
            0xCECFE8D4668DE3C1ULL, 0xCBB8F09FCC5B7785ULL, 0x0F8DE63B7DE67080ULL, 0x9701630B2D18A513ULL
        }
    },
    {
        {
            0x4A594D96ED410B0AULL, 0xA2B4FC5B742DDCC9ULL, 0x5F10106C102D6257ULL, 0x134594B37DEB5560ULL, 
            0xC91B549EAF46B9B3ULL, 0xA4B882102D4170B0ULL, 0x1E7E2A052740D0A9ULL, 0x749C1D30B80B673EULL, 
            0x830707093C0EC158ULL, 0x6722A190DD6BBEFDULL, 0x56619402D0368642ULL, 0xFC7FC986F1FCAB12ULL, 
            0x95AA16691DE0DDC4ULL, 0x5B43082597F20632ULL, 0x24F7287ED77FEBF3ULL, 0x1AE64EF97488048AULL, 
            0xADA600D4CC4CA93DULL, 0x7FCEA39A51D39E70ULL, 0x9B73D350461C9105ULL, 0xA1CC3B596CC2E259ULL, 
            0x50279FC892B871FBULL, 0x263E1F8F18D5A207ULL, 0xC5D9EF660C7965E7ULL, 0xEBE011F2E29C09D6ULL, 
            0x3311AC84DC3632E7ULL, 0xB31E61837BD845D9ULL, 0xEEBCC5DFE150A7A4ULL, 0x09DB9DE331D9087EULL, 
            0x2C56301C5C8B4203ULL, 0x7A27FE0CD77F7209ULL, 0x61975DD39B15716EULL, 0x82E87A63BD4889B5ULL
        },
        {
            0x05AA6BF9AD9F1BE5ULL, 0xA0CC433697F52C57ULL, 0xC043D5A79636D6AFULL, 0xE5F9C703DB5F6403ULL, 
            0x4EE99A82531CADBCULL, 0x94EA0866DDE5F390ULL, 0xD940ED7829348F34ULL, 0x35488898A45F6619ULL, 
            0xD315B141FA92D547ULL, 0x43DE570B94DC985DULL, 0x775575C0FC77C34BULL, 0x6F9F4F61989D4209ULL, 
            0xBDBA3FD420257642ULL, 0x9861284CD3299E60ULL, 0x2C6799BADCC8250FULL, 0x942444EA5C887C6AULL, 
            0x649AA8F3FFCDD1ECULL, 0x569035E85AC09A1BULL, 0x3C5E97760B9B6DB7ULL, 0x4D65B2EA3FBCEF39ULL, 
            0xB0FA47E492F841B4ULL, 0xF80233573D011AB2ULL, 0x546768300B4BB535ULL, 0xB89BC579497DD530ULL, 
            0x731AF18F0D159BE1ULL, 0xDD32521E75A1BFFCULL, 0xE721B740E2F66239ULL, 0x7B9A6500C796B7A9ULL, 
            0x49768F6776A3ADA8ULL, 0xCC1869645E9A295DULL, 0x5B6F81FD18F3ACF5ULL, 0x7914689AD53598EAULL
        },
        {
            0x962566DDBC40A35BULL, 0x39DA85EFB204CF80ULL, 0xE22BE764A7033734ULL, 0x1996CD2378539602ULL, 
            0xFE978F8281378272ULL, 0x04F4D61C1906E5B7ULL, 0x665724B15D6E73A2ULL, 0x474665D9863034A9ULL, 
            0x353DE9AB59FD4CF8ULL, 0x02C484796CC2F739ULL, 0xCF66093BC747C007ULL, 0x9AFC6F24A45CB0B5ULL, 
            0xC6EA78D3309E0DE6ULL, 0x6719B5F86E649B6CULL, 0x4A394C2D3167E872ULL, 0xBEB289F1F653FB62ULL, 
            0x89B5F31B175286FAULL, 0xEC2DBB516F7A39B0ULL, 0x6F51CABF64721CBCULL, 0xE77E3D8745DCB83CULL, 
            0x0DC98350552A1E27ULL, 0x9BA1B91ACEE51240ULL, 0xCDCB2EA52E580AF4ULL, 0xB443319807AFB1A5ULL, 
            0x979BA87B670A2581ULL, 0xD507028A3D618BECULL, 0x4349BCEA99CADA6DULL, 0xD525E9E90AC1CD2BULL, 
            0x886A2927744C42CBULL, 0xC2E2D8630203E231ULL, 0x3EFA2A9780AF23CFULL, 0x6D9A663A5E4A0E87ULL
        },
        {
            0x69128F851B30C3ACULL, 0xB95A946055179274ULL, 0x74CF4C48DA128C31ULL, 0x6D1CC0EBBE9CFBA5ULL, 
            0xAC2943DD0CB56361ULL, 0x284C3D8AC0F8E9CAULL, 0x5761773FDE3A2A1BULL, 0x45F76A40C703D5CAULL, 
            0x768E08D345C4420BULL, 0xF3B8BFAA8F9EF2DEULL, 0xE3057E25743A6B6DULL, 0x5F91172F91E12BD6ULL, 
            0x633F8BFB00F1C37CULL, 0x7750160B86D7D92FULL, 0x3C28DA03B00B1BB5ULL, 0x3BD81C52287A56C6ULL, 
            0x0C2141F6ED1FEB20ULL, 0x4F733DA5BFBDC939ULL, 0xFC4A8A0A61C639EBULL, 0x4987751C662A420FULL, 
            0x756C12C204EA4DC8ULL, 0x6695F704C8421C42ULL, 0xFA14579D7D622BAFULL, 0xFC26A30099E633D1ULL, 
            0x05055DCC9DA08F89ULL, 0xF1FE3897A536B572ULL, 0xF14692930BD3B58AULL, 0xC5303E58EB7227E2ULL, 
            0xE9FAFC57C5EAE814ULL, 0x0BA4DBCD764DD66DULL, 0x181C6B84EC344E14ULL, 0x608EA658E70EDCEFULL
        },
        {
            0x3CBDC8BC46822BF1ULL, 0x4ACED809B45CD74AULL, 0x300B75160A2145ACULL, 0x5A4338C2D5947C52ULL, 
            0x6194E5F474EE4829ULL, 0x6E0BD00CB52139FDULL, 0xFE82D9826EA09D8DULL, 0x74312E3A16AB4394ULL, 
            0x5730FEB7BC8F8BB7ULL, 0x62DD19D9571A4F7CULL, 0xF07C3E4BE38A861FULL, 0x89F95C95551428BEULL, 
            0x2D1DAC9374E6A972ULL, 0x6FD5413A0839E231ULL, 0x0F865A170E79A172ULL, 0xEE62950F7A63318BULL, 
            0x4229CBE811D6BA36ULL, 0xB717A16159EFDDF2ULL, 0x99A8702FF6339ACAULL, 0x7E1EB695B002F5D2ULL, 
            0x1C569D5FC4A0781FULL, 0xC729D6B65EED39EFULL, 0xE405276863E69B0CULL, 0x05E2981786035803ULL, 
            0x439D244F7BAAF92AULL, 0xC3B5B06CA037FC38ULL, 0x9212CA742141A437ULL, 0x09BBE0877EA9B21BULL, 
            0xC08DC4BC8480EB7CULL, 0xFA8F4922E7E1A4ECULL, 0x6BB4A996087C3D77ULL, 0xC80E5059299B4BAAULL
        },
        {
            0x3F68DC998DE74249ULL, 0x8DB891E22442E727ULL, 0xDD2BBADD9D730BB9ULL, 0xF638B6487A2509BBULL, 
            0x77AF0BECFD7765F6ULL, 0x2163E36B2BBD8A18ULL, 0x33EDF27DBBC56194ULL, 0x247C5E66F0223B29ULL, 
            0x2CD86AD2844D2DC5ULL, 0x3682AD66B013B812ULL, 0x3BF3DF19EF4CE2B7ULL, 0x02C5380160F02E89ULL, 
            0x5DFD54507C633AD9ULL, 0x9FB26A9245250798ULL, 0xFC7D7A7DA29478D2ULL, 0x916BAFF5B7CDD42DULL, 
            0x2680F26673F2DE66ULL, 0x4A849E2528B31A10ULL, 0x6EF8866310356F81ULL, 0xA208E38841CD8DB8ULL, 
            0xEC4AB7BA8AF5821CULL, 0x1BD97885AE77762BULL, 0xBCC544176AAE9A1FULL, 0x949A321F2B4700F0ULL, 
            0x38E164A7A22C5DDFULL, 0x04B19BD1A4F222D2ULL, 0x50C11E6B2472BFE7ULL, 0x8BF52BC319E17B7CULL, 
            0xE630A13A08AE7546ULL, 0xF163D8CE769B66CFULL, 0xC20B08CA96B4BB75ULL, 0x61E679FF08A94A21ULL
        }
    },
    {
        {
            0x9B3487E6594CA081ULL, 0x7EE5614A29BCD5A0ULL, 0x0747E7C29BC850C0ULL, 0x473D9D3AA28D6692ULL, 
            0xC42CF95F29786AEAULL, 0xEBDE0694F590D1ABULL, 0x402E8FD40C3C0529ULL, 0x3BCF65FBBC4B0B96ULL, 
            0xD8DF370ABA119866ULL, 0x90C7AB4F25CC9AEEULL, 0xDD505093124415D7ULL, 0xBB86F55843E1DD72ULL, 
            0x3CFBB971946481C5ULL, 0xE11A11E8C2D12A14ULL, 0x69E371FF2D96280AULL, 0x598AB8138D9EE68FULL, 
            0xEAF73622A32BAC02ULL, 0x3F843AC9B1A5DBEFULL, 0x169DBB78AF952BD3ULL, 0x91591BF5C581A594ULL, 
            0x1099D7CC04AD3CC7ULL, 0xFDCAD4A06209DCEEULL, 0x60E267553CBD7F66ULL, 0xFB6629A75A298EA9ULL, 
            0x2A14121895E14B88ULL, 0x707350B13F788AB5ULL, 0x7C5CAED719D45ED1ULL, 0x8461291E251CF0A4ULL, 
            0x545BE0593CCF2E26ULL, 0x12326C071471409CULL, 0x6B06165486E66CB9ULL, 0x0512A3F049689FD0ULL
        },
        {
            0xB81FE77AAF87A8EFULL, 0xBBBB2F23F11862B6ULL, 0x49309A0126BCA055ULL, 0xFE46D3B41D31545DULL, 
            0x384AE77EB2B2C356ULL, 0x8DE825F2DFADCABBULL, 0x10371CD671947FF9ULL, 0xFC76235E5D4C2542ULL, 
            0x690C85A236C2850BULL, 0xEF2E45E5E946A983ULL, 0xED597F940913B24FULL, 0x11AAC8AEBC6FC79DULL, 
            0x23F4B42D381D4C48ULL, 0xAEBD208B1515C2D3ULL, 0xCC84700A3AB43384ULL, 0x08538A9747DA8788ULL, 
            0x7C4D553514D6D80FULL, 0xD4BE99667A8F64C9ULL, 0x961E5F6C25206734ULL, 0xCA5890DB4D8F8B6BULL, 
            0xD093273ADA93C37DULL, 0x930656DC14279CD6ULL, 0xAC7DCA1AF1B7E2DFULL, 0xCEABA246315FFE2FULL, 
            0x65E4DA9DC9BB8F40ULL, 0xE45E9B8050CCD00DULL, 0xEC9FD1203DDE88AEULL, 0x88FAB3DAF9566B51ULL, 
            0x54AD72503652C492ULL, 0x71337FEEDC8D64A1ULL, 0x45D3FBBB8C9FC91DULL, 0xC4A76B5F2247D05EULL
        },
        {
            0x022BB48333662E7DULL, 0xC072D183484B6CE9ULL, 0x1658159F9B499480ULL, 0x9D88A84F6D29A989ULL, 
            0x55DAB7970F4E9C7BULL, 0xD8B1C8EF25A6609AULL, 0x2A0A131364CB05F4ULL, 0x2C28B75E8DCE05A9ULL, 
            0x0AB0814F89C6DAD1ULL, 0x1B734D09EF914061ULL, 0xD72341406CE83807ULL, 0xA998C923F9FC588DULL, 
            0x3D1D45AB1F48CA20ULL, 0xBC4FF32AB6133181ULL, 0x90652291568CDB12ULL, 0xD22E7CA0B6315DA2ULL, 
            0xD39FE7FABCE94460ULL, 0x4D8C3A6C386E3C68ULL, 0x056FDE36D1E66911ULL, 0x91803DD13D55A588ULL, 
            0xF95B149E61071195ULL, 0x6856424E00C7696EULL, 0xB035413C2218DD5AULL, 0x737062375FF92AFDULL, 
            0x1FB37919D336CBB1ULL, 0x74D7C407B12DEE73ULL, 0xB605069488C45954ULL, 0x7E28FCAF0D463C86ULL, 
            0x8F4B07B8043D7B4CULL, 0xF222EF3BA76D12A7ULL, 0x217BF43A80C98D64ULL, 0x017AA8C05168D823ULL
        },
        {
            0x6658D74CB3401113ULL, 0xEFFE0E873CE7D205ULL, 0x0B21EE6BED8B6940ULL, 0xF2E072CF9282FD32ULL, 
            0x4F20FC7AC3B06180ULL, 0x0D1DD0479510FE6BULL, 0x138AF9E3CDD48B51ULL, 0x7D8BC3A0356EA856ULL, 
            0xFBD348E87608855AULL, 0x38CADCDB4849353EULL, 0x1809E92AE7C60EE5ULL, 0x36D68229163C5844ULL, 
            0x2DD2B9061A8D44EAULL, 0x74DDD62C21FFB97DULL, 0x94A2429138E00D5CULL, 0xA9E9EFFB8873A6ACULL, 
            0x4F57CD2D06C7C780ULL, 0x3C03B9E767BBAB0AULL, 0xC90F8F39FB0B7146ULL, 0x7918EB8829754335ULL, 
            0xDFCB482726A046E6ULL, 0xDE457F74E6897032ULL, 0x46DA60A05E94C233ULL, 0x1641D8C60AE79EDAULL, 
            0xF429000F6747B587ULL, 0xA399A0DA27FA004FULL, 0x6146A9C9832DF4FFULL, 0x79F2C162234771F3ULL, 
            0x7ED0FF8994BF68E8ULL, 0x251F11FEDB3E7FDCULL, 0x6F5B0E7C25650663ULL, 0x745E8C62B4F269CFULL
        },
        {
            0xA52D7CEE7A842A26ULL, 0xCBB0BDBFA8FAEEE0ULL, 0xC136F25B321E578AULL, 0xD0341A789845ED33ULL, 
            0x03A16B426CBA474BULL, 0xD19503A914D3CE18ULL, 0x9E033A01CCC36D26ULL, 0xD32F7F825ABE945EULL, 
            0x45BBA9D05FBA4234ULL, 0xC37B141344DD327EULL, 0x62F43823BE93E1A7ULL, 0xA116C2E7564ACCA3ULL, 
            0xBCB813B96EDEE3A4ULL, 0xDA3217081F9C9A54ULL, 0x8AB8D83F56D8671BULL, 0x47F72514A33ADFD9ULL, 
            0x86CEAA4598835EFEULL, 0x337D10804DBB12A9ULL, 0xC59ECD3D555DB9CDULL, 0x5F0488FDD819A007ULL, 
            0x52372139F52344C6ULL, 0x3834BEE1860954D7ULL, 0xED06831A03B9C7A6ULL, 0x68BF06F495E32D08ULL, 
            0x585E60149B8907C6ULL, 0xBB521226179A78EEULL, 0xA9A35170D48418A7ULL, 0x37031E333A69A7A7ULL, 
            0xC34D2575593B87B5ULL, 0xD20C258246C4FDECULL, 0xF9DB48CE2B24B04BULL, 0xC4239BB1812203C7ULL
        },
        {
            0xEC788FB88E2B94B6ULL, 0x2C176B4C38FC7E06ULL, 0x56671F8AD7B44A59ULL, 0x5B497DB83A1427F1ULL, 
            0x9693B85559115B18ULL, 0x09C347A5F6618F36ULL, 0xFF5671F0B9355C45ULL, 0x7BABED8951BF9845ULL, 
            0x7A7FD15AC6752EE6ULL, 0xC59D34E86FA43433ULL, 0x2B2E6BC9A895D041ULL, 0xEB8FBE22226387D2ULL, 
            0x7D29B2535B750D51ULL, 0x68B91A68CE5A4C9FULL, 0x4C4331E9C04A6002ULL, 0x0092E5B7972089D2ULL, 
            0x7EBF84D0337B6089ULL, 0x2792260F5415E509ULL, 0x316D98B058ED284FULL, 0xDE4C67CC12CCEE80ULL, 
            0xBB81AEDAB4A12731ULL, 0x30BF3B6DA222E97DULL, 0xAD0EDFC85BEEE819ULL, 0x56378917E232A32EULL, 
            0xB8F0087B2E76A836ULL, 0x3BD9EAB07768495EULL, 0x7DA73623292DF853ULL, 0x80E2711B87FEEB2EULL, 
            0xEC6295CA1CB22349ULL, 0xC5AB9CC557401342ULL, 0x5457E9F5F3394310ULL, 0x5847798C582F3B92ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseBConstants = {
    0x29CCB5C803401473ULL,
    0xA121142A3C01066FULL,
    0xBA08355C48318F3EULL,
    0x29CCB5C803401473ULL,
    0xA121142A3C01066FULL,
    0xBA08355C48318F3EULL,
    0x0F8A5BC0E9C79371ULL,
    0xBA6596ED44AFEF7FULL,
    0x96,
    0x4A,
    0x23,
    0x17,
    0xD0,
    0xC6,
    0x5E,
    0x63
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseCSalts = {
    {
        {
            0x4675B4C608FA1FE9ULL, 0xF6D2FDE9649B8973ULL, 0x7DF2F34B71E94339ULL, 0xBA40160ED79CAF83ULL, 
            0xD54D0F4755A09D87ULL, 0x60BF9B2DA91483FAULL, 0xB56E77A38B680377ULL, 0xEA44DC995CB172AEULL, 
            0x4C364794B309543DULL, 0xB6F23988551D8CE1ULL, 0xF873C3B42A8C5119ULL, 0x8F0E18AA115F3E2AULL, 
            0x149EF7689D221832ULL, 0xF25EABF2574732A3ULL, 0xAFF4722F156DEFC0ULL, 0x23101989CD4A587FULL, 
            0x08E6437EDAAD5D44ULL, 0x38EA2CF3799C951BULL, 0x89EDC8D9E431FF74ULL, 0xD2D37C8C3BB84811ULL, 
            0xAC286D39628FCB21ULL, 0xF9290840E59BCD8CULL, 0x2E5068CEF38BC533ULL, 0x72F244D482F4212FULL, 
            0x64364284D41E1B73ULL, 0xEFCA3E22F75EE64DULL, 0xDFDB33C66200B712ULL, 0x013E1202CFEAE250ULL, 
            0x5AA3F35C36F0C527ULL, 0x14420E7CE90F8B36ULL, 0x5389302C09BF441CULL, 0xD7BFD5703C516705ULL
        },
        {
            0x6C385F84DEC7EF20ULL, 0x6F1CB2B4B5FF921FULL, 0xB94B3837AB727EC9ULL, 0x4140A004379761CFULL, 
            0xE14DCE6D58C468A6ULL, 0x316475D4781D4785ULL, 0xD8CE23358D695835ULL, 0xCDED3BADF6B39EC5ULL, 
            0x392295BFF67EB3D2ULL, 0x50270824D11B7C6FULL, 0xFCD5141D143CCF98ULL, 0xD38381179E619F96ULL, 
            0xECB26F088F8C58D6ULL, 0x28B166AF1F713228ULL, 0xCEBCEBF797DDFF29ULL, 0x74D8158A77AFEE32ULL, 
            0xC9CAEEA2AA705D06ULL, 0xCF5D0FEC97F5E22BULL, 0xDACE2E64B1E64DC3ULL, 0x9B63637E1714BE25ULL, 
            0xC9EA9AFA02D4300FULL, 0x7BBD0784D4A580B9ULL, 0x756DFFB261355096ULL, 0x2C7F21CE76E71465ULL, 
            0xAE35C5B413539CD3ULL, 0x1A8F348D59B3BDAEULL, 0x05B7A3292782780FULL, 0x5009C4DD8B6434BFULL, 
            0x2409CCC9F20F23B1ULL, 0xC6FD5128F295E7B9ULL, 0x943C7DB1295809F6ULL, 0xE8C2580D207082D9ULL
        },
        {
            0xC330E339C36BDC73ULL, 0xECB1AE963361764DULL, 0xB7105DC8623D3FF4ULL, 0xD3FD29F081742657ULL, 
            0xD6527720B3715B73ULL, 0xD5F844DDFA91F826ULL, 0x2644BF051804CB30ULL, 0x119DF7A34EF013BBULL, 
            0x3E4BE8937625F95EULL, 0x8BCB1B73B9443755ULL, 0xA3D1024E0C293773ULL, 0x55721B6A7595B851ULL, 
            0x074FF5DD8FFBFAE7ULL, 0xCEBE9AFEA5CB3B87ULL, 0xBEEF3C91CD202266ULL, 0xFA82079C8AFDFF8DULL, 
            0xCBFE87BA35CCDD96ULL, 0x5F3A981B3D08EAA6ULL, 0x408AA2C0A9ADD26EULL, 0x50AAABDE83978F44ULL, 
            0xDBA9FD32630E8117ULL, 0xAEE918B7405D14FFULL, 0xE494B3E98C8840D8ULL, 0x95AB5BB846A6CF94ULL, 
            0xEE50305FBE4A83E5ULL, 0x052BB3A54FABD1F4ULL, 0xE6CAEB1C23A4C224ULL, 0x28977320FAA8FCDFULL, 
            0x974D2097C370626CULL, 0xC412FC616ED3779DULL, 0xA232A8299AD61F5DULL, 0xEB12EAAFE30280EAULL
        },
        {
            0x12306A4E224BFF79ULL, 0x57B77171DC90E4BBULL, 0xCDF6D1F0BB7DF806ULL, 0xBFF6665FD674807EULL, 
            0x63AC7ED9CF7B7617ULL, 0xCE0521B0FEDA67FDULL, 0x76229AFE0BE28FBFULL, 0x72461D2DC78ADDD3ULL, 
            0x3F8F17DE53CB59DBULL, 0xBBFD475441200876ULL, 0xAFE1ADC6701F1B1FULL, 0xEC883371AC1F20AAULL, 
            0x8E08C0BC59701CAAULL, 0x00FA436470DE117EULL, 0xEDBAFA482217C386ULL, 0x1D416A7FC43677E5ULL, 
            0x2D28791D1F4DB2BBULL, 0x8C34AD779A162A0EULL, 0x8A919D9B5211C600ULL, 0x856A8D76DCA977C8ULL, 
            0x4C12D07FDE016776ULL, 0x7B11C0D4CC2418B2ULL, 0x7B5363A67B4F3966ULL, 0x3C00C1C095256159ULL, 
            0x9FA49084275E3674ULL, 0xA2E58A51D5C47174ULL, 0x14B8CCFE1800ABDFULL, 0xF1EF1D7B9C192364ULL, 
            0x161D272C521542B4ULL, 0x6AAFC48A26AC3372ULL, 0xF749B27E765A8F1DULL, 0x773D9860DD3520F6ULL
        },
        {
            0xA45B5A5276109356ULL, 0xD84F47E7F58F6F12ULL, 0xB0EC8A96CB145D6FULL, 0x8F4C39D3D2AA2E4CULL, 
            0x77BE300BED9ACFB1ULL, 0xC9FC0D2ECBEBD119ULL, 0x260F0DD9B78C8F3EULL, 0x29A6DF10223A0208ULL, 
            0x3768821865171AE3ULL, 0x87E5706B806BE93EULL, 0x0912F8645C1FB27BULL, 0xDCF66A18004136BAULL, 
            0x8B7FEEA0B63089D6ULL, 0x87BDDB0004D48F60ULL, 0xBFAB040F3E5F82E0ULL, 0xAE17FCF0E3914AB3ULL, 
            0x4517F9851F24BCE5ULL, 0xE2F5BFD5974C3511ULL, 0xA00EB2A05800CBE7ULL, 0xBAC0837BF58D5D50ULL, 
            0xE7F673610D187235ULL, 0xE4F18FD628F96741ULL, 0x38D32495132F4D1DULL, 0xB3431CDBADA6245DULL, 
            0x570FC8A1F4E9AC26ULL, 0x2FC2970E3E73F3CAULL, 0x7F059FC35B633A93ULL, 0x1D94E7E975586801ULL, 
            0xA450C6C2A7CC5E4EULL, 0x28C06DF47668DE1AULL, 0x2C7DFAEA16E007E4ULL, 0x0AE3CB14838469A1ULL
        },
        {
            0xDC7A0F767433CB71ULL, 0x60BF30A17BEE6841ULL, 0x544D520C93DF72BBULL, 0x1C7079979F0B6A48ULL, 
            0xD01EBFBC599F5662ULL, 0xA93BD059D0A8DBCEULL, 0x7DDDB5F3C9705814ULL, 0xD0DB7CE3BDFE1492ULL, 
            0xC31C6E5F6C388B12ULL, 0xD0706D56795FE561ULL, 0xE2F0FF33D1CE8A55ULL, 0x367D02A2D04E04C8ULL, 
            0xF94EE392147B9508ULL, 0xC65DF4D2E8E43916ULL, 0x0030D4870FA3CCFBULL, 0xF5C0794FA86BD102ULL, 
            0xD80481DAD4DBAA95ULL, 0x76F70D6C402E2751ULL, 0x8CD52DC9662C0C0FULL, 0xEE75FF13EF6E4380ULL, 
            0xF5EEBAD6678B2ACCULL, 0x4B2EF9311327F701ULL, 0x3DAC367EA62CC21EULL, 0xF5A2B5CF15C2312CULL, 
            0x2CC9555C6B6976B3ULL, 0x17FDA1AFA245C06EULL, 0x1FC8598628C5D9ADULL, 0x20C3374554CC63EDULL, 
            0x9FFB3133AD00FA7DULL, 0xE5FF80539CF6AD5EULL, 0xFF06F948246D6529ULL, 0xC3D75568D4054E9AULL
        }
    },
    {
        {
            0x4B010D1A90B7FAFBULL, 0x8C26C202914375E0ULL, 0xDF970989707E5D06ULL, 0xA8527DA89C1B7482ULL, 
            0xC9BD67FB6C883DC9ULL, 0x574054810AEC4ABCULL, 0x9F96BC37500B79D2ULL, 0x78999A8B831BF5DBULL, 
            0x9E8A269779A7BDD0ULL, 0x3D2BB189BB0662A6ULL, 0x769AB0C2F44B7AB8ULL, 0x2FCA3F60AE66276AULL, 
            0x23DFC3B549518BD8ULL, 0x607088137955469FULL, 0xF301B8506CBD42F9ULL, 0xD7A8A03578386211ULL, 
            0x3D9BBCB57154DCA5ULL, 0xC555D4B06C9F5E99ULL, 0x6395416160CD532DULL, 0x5395FD2CB8E7D5C8ULL, 
            0x7742E8668A3B6399ULL, 0x79EC8C7465654D68ULL, 0x530C5A24073C303AULL, 0xDEB7D27D9F53157EULL, 
            0xCBFA5AA6FFAB50BEULL, 0x57AEBD9097EC721BULL, 0x3D9FB139639DFE2CULL, 0xA004490138506256ULL, 
            0xFFE19F7777B738B9ULL, 0x4A9AA86926DC8EA0ULL, 0x02229675F2905EDBULL, 0x3A1D28C8E038B2DAULL
        },
        {
            0xD9C9443CD58A32CBULL, 0x68C060C4DCC94750ULL, 0xC2AF2B685EC9887BULL, 0xB6ABB84E2AAB98D1ULL, 
            0x4A12B33116E1F325ULL, 0x9372F14447D978E5ULL, 0xE26B63449A99C5D3ULL, 0x2EEA2C5C6E888BD9ULL, 
            0xAAC6DECD6D88B5DAULL, 0x424C69D4BA0AB712ULL, 0x5075AF66E2FE43D3ULL, 0x8F3C194DD4AE3435ULL, 
            0xFF85F8B1B39D42B9ULL, 0xED4A481C7BE8BF59ULL, 0x37BF5C855FC650FDULL, 0x231FD1A6EB1EB01AULL, 
            0x4F146E965662E3B8ULL, 0xF9D132B9F63A67BEULL, 0x841DF575FD75D0CAULL, 0xCDD7D41031D81D1BULL, 
            0xEDD5A4FE0C21324CULL, 0xCB363E7323651893ULL, 0x807F1F161211BE9FULL, 0xF833E79877D3B8AFULL, 
            0x3E8AB221DC8CEAE8ULL, 0x50F701C20FE4DE68ULL, 0x06D53E77704B6AC3ULL, 0x17E8FB66272BFE51ULL, 
            0x3C584C4FF8FBB2C9ULL, 0x6C4700AC6B64832EULL, 0xF9E2CCF200ABCC49ULL, 0x64ACB4CA744A179CULL
        },
        {
            0x6038817649A20BA8ULL, 0x6D25264209349F88ULL, 0x1016CBFC98134403ULL, 0x10FC2FE2172F782BULL, 
            0x371D2CC0AEBDED0CULL, 0x796D133DF230CB53ULL, 0xB7F076FAC92F4530ULL, 0x12B28380CDDF8231ULL, 
            0x6252C261F29588B3ULL, 0x5B4453F6691A8ACAULL, 0xF9E8B1164F834A9CULL, 0x468E9F4FF017066EULL, 
            0x77124E2C62F1A88BULL, 0x7D3104C0ACA6121AULL, 0xA3D03FC4BB41DF99ULL, 0x9A043B5F52A132DFULL, 
            0x38B5106C7814FE16ULL, 0x86192C4A8BC9C96FULL, 0xA2AF57986DF4DDFCULL, 0xE39A31BE6E76D7BEULL, 
            0xD964571B58BED331ULL, 0x46C1F9618ACEEBBAULL, 0x64858734303AB28AULL, 0x2556323E10615DC2ULL, 
            0x110FD9A181E43AB4ULL, 0x91461BE9BA2E026BULL, 0x35DBD2E1CA3F027FULL, 0x9003BFC1168CEE7FULL, 
            0x2A325DDBAD798CA6ULL, 0xE3328E7B1F589A1AULL, 0x9A9EDFDBDE375F76ULL, 0xB532444515AD7D8BULL
        },
        {
            0xDD8398D9958778CEULL, 0x9F94F8FD771F40DEULL, 0x480AFFF2206CE8D7ULL, 0x347087DAA8C84F87ULL, 
            0x908056941D0E3332ULL, 0x7DB7454825ED693AULL, 0xE00DDC93B6E28339ULL, 0xD890E40358046A69ULL, 
            0xB41D83359F37A344ULL, 0x52408B40C992970CULL, 0x886C0CA6AB8EA278ULL, 0x88C0FCE3F3D8473AULL, 
            0x64FEF83651B065BCULL, 0x6C25E00A7DD29C5EULL, 0xF92F8F3DF7C12011ULL, 0xB4D2066DFD50ED8CULL, 
            0xC94DF62334C75B96ULL, 0x0FDAD8D70E8455BBULL, 0x900180F1B3D463B5ULL, 0x40025329AD7B0CBCULL, 
            0x618E314BDB26C9B9ULL, 0x6A74D6EBC8EAA6E6ULL, 0x73D59014F091BB8DULL, 0xDEF8E20602F6E505ULL, 
            0xAB78EFEE83950CCFULL, 0x290994CE762C52FCULL, 0x9E48093EF6C4910FULL, 0xFEBAC7BCEA79E81EULL, 
            0x023B2C951D66097DULL, 0x3BF6177857ED9511ULL, 0xB3E192432E7CB9CDULL, 0x459A00CD64C7314FULL
        },
        {
            0xE5AB11E9783081CDULL, 0x61499D47F094B037ULL, 0x583C0430C9BCCA6AULL, 0xA090795597BC2091ULL, 
            0x6D20A94EC29DD5D7ULL, 0xE4ED58683701B0F3ULL, 0x8DEA026551504272ULL, 0xD3615815C8A404CFULL, 
            0xA3F6370F14AC9E33ULL, 0x118556271F4E48EAULL, 0xDEFFBBB1D200DE55ULL, 0x39B5DF7BAE703199ULL, 
            0x20413D9CDA251AA4ULL, 0x71DC8B3AED845E50ULL, 0x673985BBD42ED153ULL, 0xC3272CD4D7E123A5ULL, 
            0xE7CD9A3C76C4AB29ULL, 0xD8F6918F88A6A88EULL, 0x191725568C8E2625ULL, 0xA6285EA7F111EF50ULL, 
            0x1F9907DFF9D7DC34ULL, 0xC43035FFDBF45703ULL, 0xFCAEBC8CE07919B7ULL, 0x7A77E60E0A117E81ULL, 
            0x753698445CE68E08ULL, 0xB0A237A6FE832804ULL, 0x6A5FD0728281BB1FULL, 0xFC389B78FD9DE27BULL, 
            0x1A5D2DA775A1C73FULL, 0x1804BA1C846EA501ULL, 0xDF2B5AAEC421FA9FULL, 0x7FAAB4C5A601CE85ULL
        },
        {
            0x0EF473EDDFC12DF9ULL, 0xDA3F358380B8DBCDULL, 0x7C1F4CA876972BBDULL, 0x2D5E42ED7F0AC9B3ULL, 
            0x38B3BDB91A77286CULL, 0xCA0D2CCBFF2DD430ULL, 0xAC5012A0365FFA4CULL, 0x609A6884A6EF2443ULL, 
            0x5FDA1D91A6FC6BA7ULL, 0x6A117B997D2593D7ULL, 0x90F7F1CAADFDF33FULL, 0x7DD243D5D8ADD761ULL, 
            0x1B4AD59EC7F7E8B0ULL, 0x1A33ABE7357764CCULL, 0xB24694723A1FC2F0ULL, 0x5D90FB4C9EBEC8ADULL, 
            0xE908A2A482797BE1ULL, 0x8971E8504B22B181ULL, 0xAE60BF97F123B702ULL, 0x810BBB8A70CAC193ULL, 
            0x1E7FDEF54B9DDA2EULL, 0x2DDC402D92C7345AULL, 0x2355FFE335D2B7E6ULL, 0x3EA2D876301B6EEAULL, 
            0x7487AC94B200C983ULL, 0xE2045C262DED40A1ULL, 0xD779B6CB667353F9ULL, 0x7BBE35EBC8417763ULL, 
            0x71FF2E38E826E0A5ULL, 0xBE88A46C59119294ULL, 0x905A2A7B177F4D7AULL, 0x65BBAB097A1CBDECULL
        }
    },
    {
        {
            0x1DCEAB5B0E06A2BAULL, 0xA4B767F282FDFFCEULL, 0x0D0C93F52344E710ULL, 0x6FF55D520E3100B3ULL, 
            0x6CF70178C9773957ULL, 0x118190CF1A6B2D72ULL, 0xE97E823FFA845561ULL, 0x873D362A9373E8C2ULL, 
            0x3D977B083DB4C3E7ULL, 0x741CA1703EC45238ULL, 0x31BD03A1EA7F12BAULL, 0xC950562207131191ULL, 
            0x13B187EC1E1CC1C1ULL, 0xF0BD6F5BAAF28B39ULL, 0x2CBFD46B33909A54ULL, 0x81881D2FAE68C56BULL, 
            0x7898FFAA4C870A62ULL, 0x8F6445F3B3BBE530ULL, 0x2E6D40DB755D4050ULL, 0x619846EA58BF3C3BULL, 
            0x18F40DE1137012B5ULL, 0xF45C74E00D82925BULL, 0x03AAEC57DFB5710EULL, 0xF9D2ED6776ABBCF8ULL, 
            0xA122120D85EAFFA5ULL, 0x246DD33ADFC74084ULL, 0x515956BB81436BBAULL, 0xB8651256B6AFDD90ULL, 
            0xE040A42D31E58C7AULL, 0xFB7B7ADDDF4CF00DULL, 0x5BF2460A866D01D6ULL, 0x53034104D3CDEC46ULL
        },
        {
            0xF134642FA5DED2F8ULL, 0x51CE2F459F46D423ULL, 0x0CFA4600CB5600FCULL, 0x67B752524A17C5C1ULL, 
            0xC1A7140E20D4D51DULL, 0x7302944FA58D468CULL, 0x4B9DD1A3FC860C7DULL, 0xF87C608D10DE0EEFULL, 
            0x91E8D782FBFDA5B4ULL, 0xF9577C5D67A879FFULL, 0x59FE49284FD831FEULL, 0x41C3D76EBA6780EDULL, 
            0xCA5360B32571B759ULL, 0x60F3C0BF85D48C24ULL, 0xB078434A3CB83D92ULL, 0x558080DCF57A42DFULL, 
            0x1B8C203C9B3BDC71ULL, 0x4D84C211DA658B7BULL, 0xC8BD00122CBA048EULL, 0x68F90E4D95BC0BE1ULL, 
            0x312F08F661D7DE51ULL, 0xE8B598701F380D86ULL, 0xDC351A7597EA6207ULL, 0xB7008F6BCDB001E7ULL, 
            0x0FCD939AC5930B8BULL, 0xE9A9F29C459A6661ULL, 0x1B4428F8077A888DULL, 0x27B1F51F9915DFA6ULL, 
            0xFFD2FC455B2E7C1CULL, 0xF15C0CB19B06D340ULL, 0xCF3C2B654BB8DC78ULL, 0xA3EBD50A97219311ULL
        },
        {
            0xD3DD14ECD1B32D85ULL, 0x95AB3D1D9916964AULL, 0x650FA04D51086BF8ULL, 0x9818C2C4C3C44C74ULL, 
            0xE058D69AB41050A6ULL, 0x8EF2B62DDF466EAEULL, 0x8E2ACA6A3A4FA14BULL, 0x38F6279582E69032ULL, 
            0x20E212BCD88AAD6FULL, 0xD68B52A58F866BCFULL, 0xA71C814FB7CCEDC5ULL, 0x3B8AA95DA29F4EC4ULL, 
            0x58765F7792AE3873ULL, 0xDD66A34E1AEA0D10ULL, 0xB68B162C481C8D49ULL, 0xACD7A7BD6F275DDFULL, 
            0x46C981DEF5D2B02BULL, 0x98BFB842E25F96E2ULL, 0x826E6710AA2589DAULL, 0x3E16A12AA20D3074ULL, 
            0x336342374D4A3F62ULL, 0x346D02C5D7656D5BULL, 0x19E0321C28D1DFA1ULL, 0x6F2C587E197654CDULL, 
            0xEDBD0B9D9758BDBBULL, 0xB63756AE16915263ULL, 0x56D3B57CEDA4EA4DULL, 0x7C9757CA527E5824ULL, 
            0xE51D1624BBD55EC7ULL, 0x1600010F1B338F13ULL, 0xB9E48167069D2005ULL, 0x6E4F08D81DF49D34ULL
        },
        {
            0x12E0FFFC5A4DF703ULL, 0xF7C253139A2DDAFAULL, 0x074BDAE632E87DD0ULL, 0x763EE55F6A3FBE78ULL, 
            0x6313765E44486AD9ULL, 0x075D338F186A3159ULL, 0xB707D60852369A5FULL, 0x64664F74C10E5067ULL, 
            0x9C549BC1E354D311ULL, 0xDEA9EF9F68438299ULL, 0xBFDB7022A7A9EDFAULL, 0xC83B6F0239EBCE3FULL, 
            0x541FAC9DFAA85B59ULL, 0x6CE45461C3EBEC4EULL, 0x4B05920E18D20230ULL, 0xD674E5221A2969ADULL, 
            0xC1956E15BB1DB289ULL, 0x73E990973E37019AULL, 0x063040774DD36038ULL, 0x7401B32667D5D5E9ULL, 
            0x9F5281D22A475262ULL, 0xC5EE9CD420F05CADULL, 0x3AF33E2F3B255E7DULL, 0xFFB485D81CD6B997ULL, 
            0x4CFB2D9163A3E1F7ULL, 0xF0B068A90C831D9EULL, 0x1E391676C74DEE96ULL, 0x7B837E9374D7FE31ULL, 
            0x91BA12BB4A354C76ULL, 0xEBAE46FDE3DC75B4ULL, 0xBE88258A23E79D14ULL, 0xD8AD592CAC747DA4ULL
        },
        {
            0xFC09FB005BF5DC6EULL, 0x95A82FD0DF6FAA66ULL, 0x1E7101CC30B88627ULL, 0x2FFF1513FB1E7DB5ULL, 
            0xDC0155D5094D69F6ULL, 0x063C16B69EAED739ULL, 0x0E1DA801D3A51FF2ULL, 0xE7661ADC03F3B98CULL, 
            0x76610E9F8CCBD755ULL, 0xC8E2E61C8A49B0F1ULL, 0x560AB6B0F5B1A050ULL, 0x482B9BBC25440799ULL, 
            0x15D0B1A068653294ULL, 0x5BE732A524E0D490ULL, 0x729282A537393A8BULL, 0x94C4062DAB8AA981ULL, 
            0xC12A2E14BB219F78ULL, 0x5D29A759102352F9ULL, 0x27BF100F12EBCA8AULL, 0x755BD4BF43A8D0A1ULL, 
            0x6B5F06E8B2778E67ULL, 0x3FDA5D4F07F6F7E8ULL, 0x7FBFC2ACFB25E7E5ULL, 0x4FDF6C5EBB7ECB94ULL, 
            0x6FE7DFBF74AAB5F0ULL, 0xE1156BE7B2C78019ULL, 0x98492626CC062279ULL, 0xED56455449194D20ULL, 
            0x7B8517DBACBE2694ULL, 0xE472626565236553ULL, 0x8C4198A703664ED8ULL, 0x113253794A3B3177ULL
        },
        {
            0xD11D7168D8138AC4ULL, 0xEC8376804B78DAB4ULL, 0x28EB8B6325AB3930ULL, 0xEF28B2BF45EEC873ULL, 
            0x8F747D49857D5FD6ULL, 0x5C985E72768D54BDULL, 0x9CD1089366D9AC82ULL, 0x05495FDFFD94474AULL, 
            0x39572FC8213CDF7FULL, 0xC6245C57A390ADECULL, 0x1EB669079FF90857ULL, 0x1EF597C5FBD5DE6FULL, 
            0xEBCFB4E62940ABD8ULL, 0xCF905332C8BF20FCULL, 0x635BA16DA6AE6AA2ULL, 0xA46249D7988A225CULL, 
            0x86BA8FBC5C459E69ULL, 0xD6FD6A9F9B09F8CCULL, 0xEABEB4F183A167CDULL, 0x9C15500CFBBB886EULL, 
            0xE54495A8700FB9EFULL, 0x980EC757B897C2F1ULL, 0x816CE3EC5EF7196AULL, 0x272474D717B17E96ULL, 
            0xCBBD539B980AA4C2ULL, 0xA2EEE1A2C831A57FULL, 0x3E1735F944AE283DULL, 0xACF887C935A99E73ULL, 
            0xA87E0C0757DB81F1ULL, 0xC432941A63109978ULL, 0x9274556B3F1DDFE2ULL, 0x013870988548A10EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseCConstants = {
    0xB5D430C36FD4F189ULL,
    0xAD728A962C31B52BULL,
    0x8D72DE0D321C2746ULL,
    0xB5D430C36FD4F189ULL,
    0xAD728A962C31B52BULL,
    0x8D72DE0D321C2746ULL,
    0x044909DD9AED7773ULL,
    0xFE74E3DAB5BC97BCULL,
    0x4F,
    0x6D,
    0xF8,
    0xDA,
    0xDE,
    0x7B,
    0x8D,
    0x9A
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseDSalts = {
    {
        {
            0x49E45D64C4CCE13EULL, 0xF6B92D972498150EULL, 0xAED90D1BE9F049FFULL, 0xD734172220D37E60ULL, 
            0x986EF2477D01F7A7ULL, 0xD5D99A94830DED2EULL, 0x18814342D4E9EFCDULL, 0x2353D852865CC857ULL, 
            0x99ADC2F56A6D67DBULL, 0x4C4C03B6C9F62CFFULL, 0xC9B6C086FFE2BAE1ULL, 0x9AEE731BCE771940ULL, 
            0x73EAB6A3AD63DCD7ULL, 0x8285732DE74C0DEBULL, 0xE19A0CFCA9EB3084ULL, 0xDE27C0D68D1BE71AULL, 
            0x4B29DF6380FA7C41ULL, 0x3F599F394183C49BULL, 0x0295EF5F60730E26ULL, 0x913A7CFB3FFA7D80ULL, 
            0x6F1393464413FC0BULL, 0x96A8F39AA71B84B3ULL, 0x02FD6822DA274B69ULL, 0x4204CBA6F084F9E2ULL, 
            0xC52349CC3444EBCBULL, 0x4C8C9D9EFC93BF28ULL, 0x83C2CD4C18D1F605ULL, 0xCE175235280DBF13ULL, 
            0x3415D020256D9F4CULL, 0xED5CD0242990781FULL, 0x9C878329C13E37E0ULL, 0xF104BFE49F4F11DDULL
        },
        {
            0xC77FCABC305F48D2ULL, 0x6891BEDBD8E6698DULL, 0x55EEBB38D19AB408ULL, 0x1DA1B52CEC90CEA1ULL, 
            0x28EFFA30A64DB575ULL, 0x82FCBF556DEE99A5ULL, 0xBD136DCAE53D36C0ULL, 0x960609E150E7FAE7ULL, 
            0x031B22DEB1355955ULL, 0xB567032366B2F02AULL, 0xE20C92A9997FE7A2ULL, 0xAC360C3DDFD65459ULL, 
            0xD0881B0B24E9DEA7ULL, 0xE2BD28D29C031690ULL, 0xFD005199F6070BB3ULL, 0xC85DC27986D9DA30ULL, 
            0x046256A333EDC517ULL, 0x4BB43C2A590632D6ULL, 0x5553FC8F38769094ULL, 0xBB2362C5DF02F434ULL, 
            0xA498D7055B9011B5ULL, 0xDABC6605E621BEFEULL, 0xEE730A8E5F1D830CULL, 0xE7EDE56680A92390ULL, 
            0x4B3A33B19454CD74ULL, 0x86A76AB0C35D492AULL, 0xD26EDC86537F8E27ULL, 0x72FFEC2A00E0DB87ULL, 
            0x569341450E91D8F5ULL, 0xDBEFA296FCAC220DULL, 0x104F0A830E454837ULL, 0x1713EAFC629B6C1AULL
        },
        {
            0x3EFB8277128EE69BULL, 0x5598A02460CE33B6ULL, 0xA3AC6DFCCA99C448ULL, 0xD49EF2C2F66BE17FULL, 
            0x7F18226C2E4593EFULL, 0xBF49EDC6A8FFCADAULL, 0x1928E224B60B879BULL, 0x44A114F5E96E6475ULL, 
            0xFCF6DD4A8A02A168ULL, 0xDCA65B207A936DE7ULL, 0xA1C459719DC0B6BEULL, 0x8AE0D6F4B620478CULL, 
            0x0AB77120E5CAEE39ULL, 0x2C2B12AFE1F665DEULL, 0xE22C9B7289271198ULL, 0xDEAB99E1E4A74D28ULL, 
            0x885E0BC11755C6F7ULL, 0x26F73C1CCD98D1C7ULL, 0x5311BCFC5C846213ULL, 0x1586F517EE51490AULL, 
            0x0D28BC7E50DAD0FCULL, 0x309FA6E3EA82BD37ULL, 0x04B4119EFF32B3E1ULL, 0xD70DF889D4C9EE27ULL, 
            0xF0871FE6D3A91BD4ULL, 0xB8845347DA469566ULL, 0x08821E834A0D07AEULL, 0x2E4245196032C28BULL, 
            0xB12D3292C5D950F1ULL, 0xA1D51DAC302EC951ULL, 0xDD95421693EDB967ULL, 0xB5010A3D0E107A96ULL
        },
        {
            0xC42B56F78110FB97ULL, 0xAB2C6C3E1AAD0DCEULL, 0xF56643EE6253675DULL, 0x0392D81EA5ABFE14ULL, 
            0x93CF9933CAF4567AULL, 0x00D800D6980B3A02ULL, 0x53D1922BFB8997DEULL, 0x1845484092ADAB38ULL, 
            0x72CE4F50F83FC950ULL, 0xB00F99D18A7285CEULL, 0xDF8DBDADB47C66ECULL, 0xC6C810F88C561DF5ULL, 
            0xB9B031F04AD7BA4DULL, 0xEDF6746F77274D17ULL, 0x1C552AC9C5C9D981ULL, 0xC2E1C547D57E2839ULL, 
            0x1FD89E4C40CA476BULL, 0xF2260D4D5453505BULL, 0x13E75A94EDEFE54EULL, 0x111AA04218894762ULL, 
            0xBE0032680DC76EA2ULL, 0x6B21F31B6EC1C4FFULL, 0x2BE8EA49B73443CDULL, 0xEE6B515BEC33C7D5ULL, 
            0xBE3555D92245E80AULL, 0xB2656E120C0BCEC9ULL, 0xF4783459941D0FC5ULL, 0x2F6402AD779CF0C3ULL, 
            0x6D6DB12878C4355AULL, 0x499AA17E5E73FA2EULL, 0xC2F73B40E377F75CULL, 0x3E8BA1042246D3B9ULL
        },
        {
            0xFF2F033D19123A9FULL, 0x9C908DA7FFAD8D62ULL, 0x92A71AFCE72D1357ULL, 0x25C733AFA5C02782ULL, 
            0x7BB99E3C8108F64EULL, 0x025D97A5549AA2CDULL, 0xA6C136038E686961ULL, 0x114E90DE52A1DA1DULL, 
            0xB7C4B6953E50523EULL, 0xBA52A5140F5127C7ULL, 0x6AC7851518CD607DULL, 0xC26CAC5D116CE690ULL, 
            0x23D2A8EF30017FC3ULL, 0xDD89B6F21FAFB35DULL, 0x7BDF796444E2593DULL, 0xDA286BF3CFD2D5F5ULL, 
            0xBE3A0945F198F33DULL, 0x76A5EC70D0C2BC37ULL, 0x68F43C4EDCDA8C3FULL, 0x8893E2994BBAABEFULL, 
            0x6E9E2C29356D0BA6ULL, 0xE706607AFC816680ULL, 0xDA7C60F2F5CBCF2EULL, 0x7503131AC00D338AULL, 
            0x95D71358B5A51690ULL, 0x8596A67BDB3C9355ULL, 0x70578D0C1279CE9CULL, 0x7388FE1F498C7D76ULL, 
            0xCA11A9C4AF636E97ULL, 0xC13C7F050A0B4BE8ULL, 0xBD9C368A0952F59FULL, 0x3B1521853EA15870ULL
        },
        {
            0x2515A007EC322361ULL, 0xA20D1602F337142AULL, 0x85C045D365EFF425ULL, 0x750E804DA47DA5FEULL, 
            0x34E070E59C5C1B30ULL, 0x68F3680D09561CE2ULL, 0x6B323FCA5CF7BE55ULL, 0xD5296D4C2BB1E57EULL, 
            0x0457BBB106700EC9ULL, 0x30A1678BD4367D46ULL, 0x09BBA44CE36B6099ULL, 0xF0D02821C4811F68ULL, 
            0x89B4DA51E9400162ULL, 0xDE3B05A495148816ULL, 0xEA09A724DE1EC6A3ULL, 0x6FFA84C9C444DB13ULL, 
            0xA322AD53AE0A301FULL, 0xBAC60DC6580BE1ABULL, 0xB7E95E3A32302C6BULL, 0x1196729711F33732ULL, 
            0xCCDDCB79011A424FULL, 0x32AE957298785066ULL, 0xA32B6E30484DAC15ULL, 0x19F159C63132E39CULL, 
            0xBBE1E974E12162DDULL, 0x0DB97260414FA036ULL, 0xA569EE3FFEF96EA1ULL, 0x759E815DB3A513F1ULL, 
            0x6C03FDE1B151245BULL, 0x0836F21C571F361FULL, 0x8C65F64EE11E165AULL, 0x6E24A8FE0A48A93FULL
        }
    },
    {
        {
            0x86319CDE946FD9AFULL, 0xFD6AFE03210CD7EBULL, 0x1EB0D7EBBCDD7704ULL, 0x8A6383E7F7BA5752ULL, 
            0x1F2D30E7857BB78DULL, 0x9D7C9FE6539912D1ULL, 0xC7F45EB0221C78A4ULL, 0xC3EE7261EDC556DAULL, 
            0x5FF72A68BAA5277FULL, 0x4C4634C8D06C64B4ULL, 0x2B439F367B60E2CBULL, 0xF35B5E1D53EBB62EULL, 
            0x974A6E9C7820F804ULL, 0x0B5B22DFABCEC800ULL, 0x628C3102F47E4041ULL, 0xCE4E6ABFDF35B6BFULL, 
            0x0D9136CC2F47BE33ULL, 0x53233B0C2FE26046ULL, 0xA5CCAE07091C6761ULL, 0x98673CBB03CDDA39ULL, 
            0x78CBA2EB2D316935ULL, 0x285C323E4D584A7FULL, 0x996F99348A7A5072ULL, 0xED11D22D3CF91BC5ULL, 
            0x5A32F66BC050EB1FULL, 0xBF97CDFE42ACEA41ULL, 0x25D13118B06C6BC4ULL, 0xD6909193D63A6C47ULL, 
            0x5A25C2A9BACC5292ULL, 0xA0D65A851511AC92ULL, 0x7337DF2BA8985FFCULL, 0x070E7AD0480B4D30ULL
        },
        {
            0x02D940A50A765D7BULL, 0xE64CA760914B5677ULL, 0xB5BDE1079965F524ULL, 0xE47AFE5C33FB1678ULL, 
            0x72751EEB68480533ULL, 0x34D633B66F50A740ULL, 0x2B7DD425BED9673DULL, 0xACBEC3A0D99FF0D3ULL, 
            0x599CFEEADB431989ULL, 0xEC7950A6A7C1A951ULL, 0x8137CCD3377331FFULL, 0x483FE286965497B1ULL, 
            0xCB3C9058E2430459ULL, 0x8E6307DDA11107FAULL, 0xDA515DE3FACFD549ULL, 0xF3B24C8C426BE596ULL, 
            0x41E82F5E9AC02737ULL, 0xB230A9F6B0007C76ULL, 0x8F3C4FE6F611000BULL, 0xF9920FD29D6AE65BULL, 
            0xC474E60B047EE6B1ULL, 0x9525C3C8E9C1DD1DULL, 0x414075E292939310ULL, 0xBB48E0CE99844B25ULL, 
            0xE13A63D478BE7691ULL, 0x851B0DA02EE19974ULL, 0x706696CFF71A74C8ULL, 0x0455C0CE13CF8878ULL, 
            0x4BFEB5EF52326C6EULL, 0xDF4445AC203C3863ULL, 0x20217BF935E2DBDAULL, 0x020485E4E81517E8ULL
        },
        {
            0xFDE94D96659D58C0ULL, 0xC12B5107E59A2E9AULL, 0xFCA9511D829D8C48ULL, 0xBAE72D552E9AB1DAULL, 
            0x31E0E916EAB434F8ULL, 0xE140A1C0FF36634DULL, 0xF9EEEF4728955180ULL, 0x1D4CBF18BBC3CEA7ULL, 
            0x85EC0EEECD8E6B87ULL, 0xAEB12FF356D92783ULL, 0xD6509A9BA35034F5ULL, 0x21DCF9DD35E74554ULL, 
            0x015E8317C7307B02ULL, 0x3B85728539B23918ULL, 0xDA931979A02044C3ULL, 0xF9142ADA55FEFA5EULL, 
            0xBB7B696F4B4F1BCFULL, 0xB9AE7151B9C8C8BAULL, 0x7B02D9B481306E9AULL, 0xB33EC7437AD9841DULL, 
            0xEE82642F233FB926ULL, 0xB576C43CEAADA76FULL, 0x39B3B7315A7A0009ULL, 0xC2C27963C5F18B45ULL, 
            0xE6CB46FB70B43B26ULL, 0x2E6B2EA852A22E1CULL, 0x6C45811663856144ULL, 0x346D56C569B86D9CULL, 
            0xDC7FE5A059C8844CULL, 0xBBDB796121ACF344ULL, 0x3705BE1F76054EDAULL, 0x53D662DA5DBF04A6ULL
        },
        {
            0x5659D2801050E92DULL, 0x67BE55CFDB8DB0A8ULL, 0xC5087ED91091BB4EULL, 0xD1C28031977CC158ULL, 
            0xD8E7135A5A9577BAULL, 0x5639DA05A5F1AF38ULL, 0x44E1AA25128BBF27ULL, 0xF1E017E2E1CC9053ULL, 
            0xBE04E493458B0D74ULL, 0x2F42126D757C236FULL, 0x5D0D9DEA72C24203ULL, 0x96575D0B0D49B040ULL, 
            0x06D05CB1498B7855ULL, 0x295B58B33CDBD07FULL, 0x67F177D4613C4DEEULL, 0xA6EC89431AB82424ULL, 
            0x932D0EAD81FBC261ULL, 0xD5BA0AB0DFC37A82ULL, 0xAE26166AD54D0B3FULL, 0xCECECC0A8F93BE0FULL, 
            0xF9C53FFA6648615AULL, 0xF974C464BAB06CF9ULL, 0x68B8944E3521C207ULL, 0xEC5B6ABC875D2BAFULL, 
            0x0115D351ECC83F5FULL, 0x05AB4644A293D48AULL, 0xB283BBA3616C46F7ULL, 0x2D1FD97671D6D340ULL, 
            0x74D8284802A8A20FULL, 0x176B10D08AE76DE7ULL, 0x5D7FA734E83B90AAULL, 0xBE1FA38EA7A5CEDFULL
        },
        {
            0x78DC9B2C02928489ULL, 0x73653673DE5F8A35ULL, 0x0CB2AB312300EA5FULL, 0xA53C7057A2BE7204ULL, 
            0x036870D3C7B125A9ULL, 0x1A839049D22DBDCAULL, 0x154A07B508C9CFD5ULL, 0xEF752F9F2805DB00ULL, 
            0x0E1A27A902131A4DULL, 0x0F9671B313649057ULL, 0xAEAC0D58458968FEULL, 0x286CFF2A8A8CC700ULL, 
            0x6687C2783AD0F636ULL, 0xACD8CCDD2DB00FFBULL, 0xE2104666444B9B49ULL, 0xEFCB6D6840DE5B1CULL, 
            0x567C73199BE9389AULL, 0xFEC1A89B3E536FFEULL, 0x328B4F34B37E8F60ULL, 0x4CCE408A8F232BF2ULL, 
            0xD492F6816B9ECF87ULL, 0x657464C40FF2364EULL, 0xA4A753BB83F5BE7BULL, 0x89740572E9425D77ULL, 
            0x8D4DD7B1507BCFD5ULL, 0x4DD977EE2B552018ULL, 0x39CC3FF44C4AAD24ULL, 0xE8E4CBF2F25AAF66ULL, 
            0xA86A9585599DFE0DULL, 0xA42DFFC808970B91ULL, 0x2B817ADE9A057FB3ULL, 0x3B398773A4C57895ULL
        },
        {
            0xC0025A1E6D09F79DULL, 0xE93244708E86E0FFULL, 0x3E8DF97836CF9A85ULL, 0x9754F6B9666965BCULL, 
            0xA9AEF3E6578BA991ULL, 0xACBC4CC7305879A4ULL, 0xA9B5E052D02B570FULL, 0x483689691466CFBFULL, 
            0x1C100D32206F16ADULL, 0x766ECCC195D432B1ULL, 0xA75AF900A2A7B1C6ULL, 0x08F409DDEA918391ULL, 
            0x12FA57EE82B150C9ULL, 0xFAB7EB5C16339931ULL, 0x2C18632323784DD2ULL, 0x0AA28E29A44268D5ULL, 
            0x6F42349B43027D13ULL, 0x1131E7CAC787E618ULL, 0x70160D6C5A51ABA7ULL, 0x931CE694A2FCE8B3ULL, 
            0xC65E7D54D6F35A4BULL, 0xA6A51232AFF6A266ULL, 0x6B1C30CAC7BDC9D4ULL, 0xEFAA578D4C23196BULL, 
            0x4DF811A473C52C11ULL, 0x6A6D8F83D6C1D8DDULL, 0xC01E5F76FCCBA9D7ULL, 0xA46426ADA1C9619FULL, 
            0x7F0F7C5CC3756583ULL, 0x165507E803070D20ULL, 0xE4D0D05C79214622ULL, 0xEB759193D257A726ULL
        }
    },
    {
        {
            0xA8138C6C84632035ULL, 0x3737943B720FBAF8ULL, 0xB359DEC204F653A0ULL, 0x6879AABF8EC098E4ULL, 
            0xB7CD711F450A4180ULL, 0xC6269C5622CCF8D0ULL, 0x97C03E2FB02BF1E0ULL, 0x5BD02A17C9F43066ULL, 
            0xA4863139EF02B359ULL, 0x73958D208FD4E5D9ULL, 0x797D361BD67C3F15ULL, 0xA063F74F9220489AULL, 
            0xFED1A438765E2560ULL, 0xBD0901F96C42589CULL, 0xE3C212379F0C2650ULL, 0x98290C2BB71567A8ULL, 
            0x32D3C0BD2CD908BBULL, 0x60A3CE98081FB360ULL, 0xC1E721E55884106CULL, 0x17C937B6E4764232ULL, 
            0x4E88966EF13AF776ULL, 0xAA74961B8E7605BDULL, 0x245104CA160C7D56ULL, 0xC60E74DEF85275E3ULL, 
            0x53D193E2803092A3ULL, 0x59748423DF9F1012ULL, 0xD5DB7DDC3395684EULL, 0x0932E6F2E2B7C6EEULL, 
            0xEA53C1AB0080F0FBULL, 0x6EACF3EDA1D0C352ULL, 0x87B7C8E630FF5B28ULL, 0xF3B570291F4BCE5BULL
        },
        {
            0xAAAD46948E4B6B79ULL, 0x28DD7519E4599796ULL, 0x32064E987F568FC4ULL, 0x75B541B277C4BFD7ULL, 
            0x43803533639BD9D9ULL, 0xA5932A00B43EC0C8ULL, 0xA580B1EF17532F8FULL, 0x39B8D6665F1CC18BULL, 
            0xF0A0C039578157D5ULL, 0x699A4F92B2E0B981ULL, 0xF718996D7E23FF7AULL, 0x4F0789F92D90A53CULL, 
            0xA4B63BCFE904A9B8ULL, 0xA7266D7213C83756ULL, 0x76045C333A6C1CE7ULL, 0xB28929C9F7B54C29ULL, 
            0x10C96C87FF9E9C19ULL, 0xBB81E7F31D1A8B92ULL, 0x5CC4EA159DCC0005ULL, 0x9D2985ED37B74EF5ULL, 
            0x70BF5FD40F80AA73ULL, 0xA06E05D3C619BBD9ULL, 0xB8B609C5CBC5C3A5ULL, 0xD5FBFB4CDC8B6D4FULL, 
            0x1CBB5555A7D2077AULL, 0x488C63349A02B39CULL, 0xD8EFE6AA13AD0494ULL, 0xDB4B57F2CD7674E5ULL, 
            0x7CF26F3A00A00B15ULL, 0xFDC5373535301315ULL, 0x448348D5FA537098ULL, 0xC43D562A3A46CAD4ULL
        },
        {
            0xEBB4C57FDC2F264EULL, 0x117FAB2CC3B1C3C0ULL, 0x8C0C657F27D9F17DULL, 0xF4E742BE47DCC1C4ULL, 
            0x1DC1D7C1185A4A16ULL, 0xBB95B4727D787DB4ULL, 0x21E60CC3DA648A32ULL, 0x580FAB006D3AA11AULL, 
            0x8709707CA430577DULL, 0x4788B60B903BFF4BULL, 0xC4288BD74DC04C1AULL, 0x2613C43FB50E0D1DULL, 
            0xE7A5A7E271086A31ULL, 0x9809438F022A41F1ULL, 0x09E64A7ACD849D9FULL, 0x0998BD49FBE6B435ULL, 
            0x1A5F5D1A066C9130ULL, 0x006F894730E53329ULL, 0xAAEF7B046044BE7FULL, 0x727EA96899A07A67ULL, 
            0xCD879F9C0A2BD239ULL, 0x71B650FB2A715227ULL, 0xB9A44479CD3D5598ULL, 0xD6A874392D80EB68ULL, 
            0xF8CFC953CD1B2155ULL, 0xFB94287D144939A4ULL, 0x0E75E2BE0215ECB5ULL, 0x28139AB2EC215E35ULL, 
            0x43E6F34F03E2CE9AULL, 0xD314E46B538ECA66ULL, 0x414B22D0DDB4F061ULL, 0xE3A0CEE964615900ULL
        },
        {
            0x892398A1F06F8D72ULL, 0x0CD6BCAF24B0BF19ULL, 0x86478A399616820CULL, 0x9ACE01F93BBB1AB6ULL, 
            0x2668FB9CA8302C10ULL, 0xA8BFDAB9012BA955ULL, 0x7FBDD1B636AE336EULL, 0x5EE1A3494D398B5DULL, 
            0x74357538C6272027ULL, 0xE988C6C63274FE94ULL, 0x0E387D2E43569703ULL, 0x85F5970A0D92DC5EULL, 
            0xD68065AF60B4AA40ULL, 0xCDFAE46509B82569ULL, 0xBC04CF35ED2D3569ULL, 0x25F817EC369CA016ULL, 
            0x7F7BEE2637EC5F54ULL, 0x3D60EB7EAC1ED489ULL, 0x826ED6286A4BBFE6ULL, 0xFC047EBC369CDFDFULL, 
            0xFDC97A3CCAA4198EULL, 0x1436E0CF3616A95EULL, 0x380EB8AFD048E48DULL, 0x5B468F9A985DA3FDULL, 
            0xBE676FECA9A69775ULL, 0x8F5B273BA4BDC982ULL, 0x2FDAE16F2ECB9109ULL, 0x8B3E2F912CF0B9ADULL, 
            0xE5C027BB27347642ULL, 0x5A8F51B7D0468E3EULL, 0xC9563DFF403E33D9ULL, 0xE3B2FB1397DD6732ULL
        },
        {
            0x6B399AE2EFF9F772ULL, 0x58A7D1FB4C80618CULL, 0x6B50623DD5A2FBB1ULL, 0x1A95EE8D513E4992ULL, 
            0xF73FE45EF647E407ULL, 0xA2054471FD13855AULL, 0x8D486590EA9F8C34ULL, 0x499079705EDC617DULL, 
            0x72C54D617D11481EULL, 0x7F382E9E72FE405CULL, 0xB9CE91442C27538EULL, 0x253AAEB82BF3112BULL, 
            0x06ABC5DB45257192ULL, 0x52C805A74E5D74E1ULL, 0x1DED7B8E39CA6243ULL, 0xD788595E2C030F59ULL, 
            0xFF2325CB22DC60CBULL, 0xC5C9C3BFA15F07F7ULL, 0x58FC1C828B0A9232ULL, 0x59BE38D5CADCFF24ULL, 
            0x26A55FFE4DEBB740ULL, 0x5BD4F53B409FE6BFULL, 0xDF5E6EF771C88A41ULL, 0x1E1319A1DD4760BFULL, 
            0xFAAB22DA8AF8573DULL, 0x9EF0FBBA50CD30F8ULL, 0x2B8BF440B7866B17ULL, 0x10E6ACE8C6038203ULL, 
            0x31F4360C211D549EULL, 0xB353FDA6ED45790BULL, 0xB786284EF61FC203ULL, 0xA88286920B63214BULL
        },
        {
            0xDFE4F799BF124A2DULL, 0x9D77D90120B8474AULL, 0xAC8FB533E08E8552ULL, 0x64DE3FDF761D094FULL, 
            0x8BE3E21AEF103C0CULL, 0xBB4D269CE4786C4AULL, 0xF2BCB64B17668888ULL, 0xEC922ED7E3B1814DULL, 
            0xBEB16016C538DC7BULL, 0x0A18FF67FDC72043ULL, 0xCB4027B7EB1B1E18ULL, 0x3455FD398054E6B6ULL, 
            0x053668CD786937A6ULL, 0x90198A6DB1495488ULL, 0x8D883FE3D713ADFDULL, 0x0F159A19B46C868EULL, 
            0xE4F1921620F12E0DULL, 0x4778D788481CBB5EULL, 0x4955FCBBC735F9BAULL, 0x515C42C21D05709AULL, 
            0xD12BEAC8CFC68E72ULL, 0x0FF710D5A258E3F8ULL, 0xF84B7815B1FE6D96ULL, 0x807D868D9DFB5323ULL, 
            0x8C068B3099497610ULL, 0x76BB737314F5D760ULL, 0xF67D66692D77B40BULL, 0xF91358F512AFE2D1ULL, 
            0x74CACDBB7EA35C6CULL, 0xEA00336A108C39FFULL, 0x50E914F25CEF88BFULL, 0x0568D901F9D0DF02ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseDConstants = {
    0x91AC156A411853A9ULL,
    0x482D1A5FA83E17E2ULL,
    0x97677080F889C315ULL,
    0x91AC156A411853A9ULL,
    0x482D1A5FA83E17E2ULL,
    0x97677080F889C315ULL,
    0x7CA6FB23D10F6588ULL,
    0x3881FFB73FE9867CULL,
    0xBB,
    0xD1,
    0x14,
    0x61,
    0x1D,
    0x0A,
    0xC5,
    0xDB
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseESalts = {
    {
        {
            0x53C451890F08F65AULL, 0x6343E8A157F5B81FULL, 0x11395C566AFBD269ULL, 0x259BD79BA834E654ULL, 
            0xDA4400104F6E9B0DULL, 0x67C3551989778983ULL, 0x46B47558B758C1FEULL, 0x274B46CA1F969106ULL, 
            0xA1CDA9F9DD663326ULL, 0x799C4006497235E7ULL, 0x003CCBA2948110B3ULL, 0xB471CD4C765F4B6DULL, 
            0x194A1C781016884EULL, 0x4153CCD5B17A9767ULL, 0x261399DDC3024E14ULL, 0x2828EDCEF381229CULL, 
            0xEA093A2BBD784B8EULL, 0x0F2BAF87E1643E0DULL, 0x376A7F1A783C6D92ULL, 0x1773114853CDA66BULL, 
            0x8479467F8ABA1DFBULL, 0x55038A53508BA9B2ULL, 0x78FDDCE7E69E136CULL, 0x19A3B60CA76A0011ULL, 
            0xC10179CD527F8F47ULL, 0x9995DE007B4A55E1ULL, 0x8948BC3EC9083A3FULL, 0xD2DBD92E94F82C90ULL, 
            0x79156CFCD5EF7E7AULL, 0xA0DCB74158AAD23AULL, 0xE6C3F0EFBAC1A922ULL, 0x61135FC8D6B7560DULL
        },
        {
            0xBFCD226EADB8B100ULL, 0x1889819F8B199568ULL, 0xD08F8FFD407EA28CULL, 0x03285223952CD808ULL, 
            0x1A745EF32CC865BCULL, 0xE4020D509C579296ULL, 0xDC829DF962285ED0ULL, 0xC31C3D41AA0A5478ULL, 
            0x5BB37A80AB5E676DULL, 0xC9C954FB085F907DULL, 0x8FBA83EE4136EEF6ULL, 0xEF4F458824E815E0ULL, 
            0x03434DBDEB859B8CULL, 0x75CD31285975EA73ULL, 0xFFDCED3C667A51B8ULL, 0x0C92FC481846FA08ULL, 
            0xB4E7BCC9081BEFA4ULL, 0xA5481C597DE3F9ACULL, 0xCDC2882C0950CCB1ULL, 0x04B215F7E06387F1ULL, 
            0x5200F1F39DA7A2C9ULL, 0x803E105C4407A1F5ULL, 0x6A8B4C4D90BB9AB0ULL, 0x8E734ED10938F4FDULL, 
            0x6E2D7D52D0758EE3ULL, 0x716F16DCE56EBE73ULL, 0xFFAD33E13FAB8440ULL, 0xE582118D858BFBA7ULL, 
            0xA0639F0921D7E2FCULL, 0x7A769B78C43085FAULL, 0x6EDDE725B78C9BFDULL, 0xF00736B0A8B38162ULL
        },
        {
            0xCBED79F682FC6164ULL, 0x1FC894CB088141FBULL, 0x9EB88001FE82AE11ULL, 0xB273EF7FA2E6ABF8ULL, 
            0x6833B98E43A924E3ULL, 0x97BB9621BD3F0AB8ULL, 0x467AC0FD0D333DE0ULL, 0x41F866060E8886DBULL, 
            0x41C0D07B1419331AULL, 0x914916E454527770ULL, 0x61D65646F35A00FFULL, 0x85427813E8092EC9ULL, 
            0xED9638C2C59DE065ULL, 0xDE6709DECC5301BEULL, 0x0B978B111D7F8345ULL, 0x68A4F4A5B5EC7127ULL, 
            0xF78F8D8755CA3DCFULL, 0x6381532FAFDEB90DULL, 0x495B7824DD36C388ULL, 0xD9F6685D68DC0F1AULL, 
            0x288F869E0CB51C30ULL, 0x207E906CF5F0FC33ULL, 0xE076FAC75E65B8F9ULL, 0x97E68CF1971AB255ULL, 
            0x5E72542D58C9372BULL, 0xC1B535B0C4D6450FULL, 0x8B475720EFE475A5ULL, 0xBAD61BF11DDEBB41ULL, 
            0x21708723C29454E7ULL, 0xA54A725D5AEEC1C4ULL, 0x259ED659B4AAA330ULL, 0x157C1FDC90D7E7EEULL
        },
        {
            0x5027C09CF339C7DDULL, 0x9F7EC4F9210D1944ULL, 0x1157EA014BBFD822ULL, 0x1B31333F84E627E1ULL, 
            0x087B3C2F7FD05030ULL, 0x8A1DF0438FDA9CDAULL, 0x8C3EEBB892EF3BAEULL, 0x1C3DB7E8B16F6EF7ULL, 
            0xCA195DBA4904772FULL, 0xB6228B452246764EULL, 0x7A29F0DBAA792ACAULL, 0x857A90DC7E7E60CEULL, 
            0x423AEA945B90F623ULL, 0x206D5D4A691ECFDAULL, 0xECFF70E2C9818B8FULL, 0x1E3F87E614356B68ULL, 
            0x21B3D36F8CDA3015ULL, 0x1ED63CCEA56D4F3AULL, 0x0FD2AE16BBFDD778ULL, 0xEF0EF6DE7FA94F0EULL, 
            0x953FCE544E4A4586ULL, 0x3AD7FCB185AC5BDEULL, 0x55798C4B8D100759ULL, 0x331F45C4AD6DE847ULL, 
            0xC7962E407420F38CULL, 0x0798383072E56BE1ULL, 0xEACDDBBB580DD4FEULL, 0xE7EBF90ED3D90CCEULL, 
            0xD1C1907D1BD81B71ULL, 0x06C1C30EA39FB676ULL, 0x0B55F53EBE77B238ULL, 0x60B8D2D51E7F2E0EULL
        },
        {
            0x53B5BBF74831B86FULL, 0x5751DE45A237626CULL, 0x28495E3BE195D231ULL, 0xA94351E571E2E530ULL, 
            0x81D5041DA865548DULL, 0x83D9A2E407DCD43EULL, 0x8BB71FD64AE618EDULL, 0x1D39561A1D307BB3ULL, 
            0x3EC1A6A2A9C291EDULL, 0x99F330D05F7D1C6CULL, 0xFB031740990E6BC8ULL, 0x397144A023897794ULL, 
            0x6ADBC8529AEC41C0ULL, 0x478FDF53A26AFAECULL, 0x86993B41DE10C7ADULL, 0x4E3D14982A1D02ABULL, 
            0xC2E5DE11AF3EACAAULL, 0x607E018F059A0E84ULL, 0xDAEB1A3BB1498271ULL, 0x54E956A09E07785BULL, 
            0x0E7A47F7FAAB3624ULL, 0xB1B4CB6A537C9546ULL, 0x2E1B8BE2053EEED9ULL, 0x8B0388E801206F67ULL, 
            0x2EFE3BE9D818FE7EULL, 0x97690985ABB00265ULL, 0x867C10F29ADD3785ULL, 0xB452151CD244E99BULL, 
            0xF0C6D64C6C81449EULL, 0x29FEFA88D4A4295DULL, 0xFBB37C118E204C62ULL, 0x823DFF7B65DD7F53ULL
        },
        {
            0x25A783C1D08AEE35ULL, 0xF040F1122987956CULL, 0xA055739E8F110CD7ULL, 0xC9EB12456E9E3DA8ULL, 
            0x1A0CBCEB3AA43DBFULL, 0x0F43B5344676EF45ULL, 0x99A6B6A7E825E607ULL, 0x1ABC54940976BF8CULL, 
            0x5BAA48B80648B9E9ULL, 0xD4B6853FC83E5E0DULL, 0x340310E238B35D3DULL, 0x6BBF3503F55E727FULL, 
            0x8BACC8D489A80346ULL, 0x3A2761FD81842114ULL, 0xC2EC5C4CB2793C6FULL, 0xFCB52FC1AFA85A08ULL, 
            0x750114A2CB85B447ULL, 0x2E715EFCC36FE14CULL, 0xA1B55808B7A11BD9ULL, 0xC2F033EB9FD2872FULL, 
            0x41BB1B2F9A067DDEULL, 0xAA963EB5231CA341ULL, 0xD08D51BA18147EA1ULL, 0x42C92E85434BB2C1ULL, 
            0x6EC64C4AA4E95587ULL, 0x54813B4FEA425889ULL, 0xF1B92F4F667534D5ULL, 0xB424258B38120CE7ULL, 
            0xAB8317E4F4B3D49AULL, 0x47EB385D47322B21ULL, 0xFF856DD7207EFB2EULL, 0x7F70F0BD88C09D96ULL
        }
    },
    {
        {
            0x45C535EF9D6002AEULL, 0xE5C70E2D16B05E97ULL, 0xDD0B77E3F915DDDBULL, 0x43B01152CA88D20CULL, 
            0x99128F19D7DED1F3ULL, 0xFDEFF2E6CCBA6259ULL, 0x1EFA328FC7E03707ULL, 0xAA485072EE54C7DAULL, 
            0x50044A98B9C1D913ULL, 0x15784AE593225DE8ULL, 0x5EFFB0CEDC523537ULL, 0x3F1504B8B8634394ULL, 
            0xE3E57771C1A5D6FCULL, 0xE27B857F0EA9F561ULL, 0x23054CB6C612D552ULL, 0x2719EA69ACE56546ULL, 
            0x58D313AE5D44BB96ULL, 0x7C2E0D20549AD7D3ULL, 0x14C4A6B09F9C4A23ULL, 0x5DED6B5E38EF2284ULL, 
            0xD570D923E87AEF02ULL, 0x4BAEC2095E4509ADULL, 0x6AF0C816A4282831ULL, 0x05E543DB1A78C23AULL, 
            0xECF875E67D421F6BULL, 0xFF47E811A1D690A9ULL, 0x896807BE4C062E42ULL, 0xB57AD4B59959640CULL, 
            0xDB6DA46D338A7597ULL, 0x856E317EBBD74113ULL, 0x55BADF65F4AA987CULL, 0x300C9397AF02ADEDULL
        },
        {
            0x2D358D9323723B60ULL, 0x00878BF333A30C4DULL, 0x921F7633CA8ADE3BULL, 0x8511A80A218BD726ULL, 
            0xA14A1E2C7F58094AULL, 0xA8B12691559897EFULL, 0x7A524FB901B8E09AULL, 0x2129326B933A3080ULL, 
            0xD34FBB137ADE3080ULL, 0xEA3C006E92AAA94BULL, 0xFA3C8C028241B605ULL, 0x95CD88075ACE4811ULL, 
            0xFFC4B91325C0E145ULL, 0xF88DA94FA320EA49ULL, 0x5DDAF2E6C5090534ULL, 0xD9D3E5142B771DECULL, 
            0x46F3A9C94B480919ULL, 0xF1151E40BCD6E6ACULL, 0xD2765FA63D15E497ULL, 0x5186C7EF74CC3EA9ULL, 
            0xD27AAC9FE0339723ULL, 0x4C2573BF9BF6FD0EULL, 0x9D29DBFC51A20E32ULL, 0xB251A9D50222619FULL, 
            0xD9184DC125D05254ULL, 0xAC29F6B75A0CE063ULL, 0x38191F48015BC59BULL, 0xA8D650F59A7F5A47ULL, 
            0x685332F4F6D7D76DULL, 0xD130267BFE28C0A4ULL, 0xDA5ECE65E207958CULL, 0xFC0EC78D99D14292ULL
        },
        {
            0x9A6A80948DAF6CB0ULL, 0xE1E68D18350BE129ULL, 0xF1055BBCD5D00981ULL, 0x829B8E5499CF276CULL, 
            0x112D6BAA08A0D0EDULL, 0x0A4EAAF1AB776FFFULL, 0xE400A28427A29C77ULL, 0xA0937E51ED2F9E41ULL, 
            0x66C04E5CB1DEDDC6ULL, 0x491CBF7C6A99C159ULL, 0x563F57EE19DDDBBFULL, 0xC31423C5DCB1D373ULL, 
            0xD836D741B605772CULL, 0x3FF33F19569B5AF0ULL, 0xD8185FE14C2CB954ULL, 0x20819A03ADC06B05ULL, 
            0x7596AA14BD8DCAC9ULL, 0x5FAA44B42B59E95CULL, 0x8C5762C840D25782ULL, 0x9A0799ED700CAF4DULL, 
            0xB99D50576D82B92FULL, 0x70D3F0F76CA19DD1ULL, 0x2BE1E01E8F4714D7ULL, 0xEB2A97EBE1238C0BULL, 
            0x32AD561110FE023BULL, 0x1397BF33ABC96406ULL, 0x209C4304219E42AEULL, 0xBFCC131B116C6A17ULL, 
            0x7A40B381F872B05BULL, 0xB6955653F2E8E7F9ULL, 0x7CA3535C8E773771ULL, 0xED601B5355B6D666ULL
        },
        {
            0x177ABBC8A98DE7FCULL, 0xD38AB479C3E48083ULL, 0x386281FD378BDDC4ULL, 0x1A8E2F5A726B04BDULL, 
            0x448C4FE65C9F3125ULL, 0xF3CE4BAB5665A1D7ULL, 0x190B314B55F5E6D0ULL, 0xD1A63AE1BE3DE1EAULL, 
            0xBD2612544AB244B7ULL, 0xB5137AF655C8CAA8ULL, 0x38C5D39739D86D27ULL, 0xA0239FDD87086287ULL, 
            0x80A01D5E3EEA7100ULL, 0xDD5C8AB95335818AULL, 0x30499064E4FF33C8ULL, 0xE97704650E8CC0D6ULL, 
            0x14A260AF389CADDDULL, 0xE128E94337F1E9F5ULL, 0x69A9B0DD27F427DCULL, 0x7BC2D17AE28813EEULL, 
            0x3F01AA80E8207D68ULL, 0x84992963159EEAD5ULL, 0xA0AA7B4AB46880CBULL, 0xE99AE47A725295ABULL, 
            0xA5EA063EF63A58DAULL, 0x4C54F590897A444FULL, 0x6BE24AC304791422ULL, 0x613C08FEA6938BF3ULL, 
            0xD1DA347EECE865FDULL, 0xDB7F609EF03DB258ULL, 0x3FAEFAB1A578189FULL, 0x3AE72407A1D1C749ULL
        },
        {
            0x45828C3B0DBDB459ULL, 0x2E524C9F712CBD12ULL, 0xE48D9EEC6E9C9093ULL, 0xF6F9B221DE0F9E66ULL, 
            0x498BF7ADFA2CF526ULL, 0x5545150034918B5FULL, 0x75029D8F346D3C5DULL, 0x9826F66827042F9BULL, 
            0xEDA20CE1E18CB9FFULL, 0xBB5D35447A1518D3ULL, 0xFD6948F550793FECULL, 0x2516E6731907A6D9ULL, 
            0x70292166E39F8CFBULL, 0x6F8590CD5067343BULL, 0xDD620E161E7E8B7CULL, 0x6A32AB589334C4AAULL, 
            0xD4778DFDB1BDB9B6ULL, 0x8971709E00EDA331ULL, 0x8010A4F02F6AFF94ULL, 0x1AD65D1630EE536EULL, 
            0xBCB9E93F5A222CB0ULL, 0x3DBF14B3AE4CE554ULL, 0x2F674CAA53C39521ULL, 0x5793660F8BD03A48ULL, 
            0x00C4654853B7C970ULL, 0x1B1F475F4D24D9D1ULL, 0x2F03D499172FE677ULL, 0x1583079A83CC8FF1ULL, 
            0xEB1B5F0E9F811CD5ULL, 0x2870B0FE119D553DULL, 0x0084E914AF0BAA43ULL, 0x98E799AD02574E7BULL
        },
        {
            0x9AF6BF661C717B51ULL, 0x82096106A0828D1AULL, 0x7F6DDE227A0EC5BEULL, 0xB194F8CB38ADFC7AULL, 
            0x6E62D2BE8A248A26ULL, 0x52F44CD376FAB831ULL, 0xAFCCEFFA25C0B871ULL, 0x49AF65D79857C832ULL, 
            0xADCFD13A9AE9E50BULL, 0x62DB9A46DEC8C175ULL, 0x8FB03163B71B4DC7ULL, 0x573B4141B3A0AB9EULL, 
            0xE4E9B1372590402AULL, 0x98DA764AF8ABFCFDULL, 0xD6B07332D00C43F7ULL, 0xAB5994CB61D0D8F3ULL, 
            0x15AC83E8AC00049CULL, 0x5224FA3918565D09ULL, 0x3A4D7D7BEE433C1BULL, 0xB8660D103433E3E7ULL, 
            0x02D7994B51EB7D16ULL, 0x1734FED8C5CB563CULL, 0xA56777D394D2F786ULL, 0x4EDC95C4DF79B482ULL, 
            0x0355C57D19384165ULL, 0x178918A51211514DULL, 0x30668D723E1E6E62ULL, 0xA355F3BC576E8CD9ULL, 
            0x5A1D2024008C93CAULL, 0x8B250CC2468BBA07ULL, 0x75DA5D260DF72BCFULL, 0x7A0550F27DAD3DABULL
        }
    },
    {
        {
            0x9BE6EBDDE98D7D1DULL, 0x9E42F1DBDB6BF8B1ULL, 0xED325A79A6842E63ULL, 0x7E6C5367477B3E24ULL, 
            0x3639D9FD96645707ULL, 0x0620980181313430ULL, 0xD8F27F5659890602ULL, 0x8D76AE90896338CCULL, 
            0x5DE0B66742699E7FULL, 0xB762EEC3ADF86AC1ULL, 0x202A5D7003583A53ULL, 0x386BD244EAD6A6B5ULL, 
            0x14CF69EC3918E838ULL, 0x5211350E7CF8A282ULL, 0x5EDDF91CA444AAE6ULL, 0x747546CC0DAC1B5DULL, 
            0x1989D6041EC9465BULL, 0x4027081D36B29771ULL, 0x051C037A0285A161ULL, 0x98ED1E32A162E0E0ULL, 
            0x3D73C8EB446B4023ULL, 0xC7F708BDF631088CULL, 0x7FC99FED4F159876ULL, 0x700ADA771F435317ULL, 
            0x01039D52CC2423BEULL, 0x1D8D54EF99FE9C20ULL, 0x92A9755C11DA35FCULL, 0x54013F19AB9D0149ULL, 
            0xEF3D3E159A9A8EE5ULL, 0x391E93AF0E05436FULL, 0x96C270BAFC5644D0ULL, 0x357CE286500D579BULL
        },
        {
            0x61D2CA636E768261ULL, 0x0788018E4F3615DAULL, 0xF618AF08E2B460D9ULL, 0x8DEB7B412F20FDA0ULL, 
            0xD821E6A5A046E78FULL, 0x424CFD06DC3A952AULL, 0x884AC2AEB6EC2362ULL, 0xC82BF3356C165B44ULL, 
            0xC5AEBDFC508CA58FULL, 0xDF5BB6AF6CAAD71FULL, 0x0EFDBBC2D94903BAULL, 0xB17919679827A1E1ULL, 
            0xA99506FABAE0A07CULL, 0x304119A1095C3A2BULL, 0x2358E2047F896F2BULL, 0x6144EAE51126772FULL, 
            0x71967367C46CA561ULL, 0xD6363C0584B3D3B7ULL, 0x3619A5F9EC362241ULL, 0x7778B7DF7956E4E7ULL, 
            0xD96F77F7F001E6BAULL, 0x3380B5ECEED1174DULL, 0xE0D6E0477DDB7566ULL, 0xAB8D56ED06B9A568ULL, 
            0xB0EE9C67E46FBE21ULL, 0x3E1E3BFECAD771EAULL, 0xF919C998FAEF6E37ULL, 0x6D5B3A25926C00AAULL, 
            0x99EA2D732163FCF4ULL, 0xF1F2281CE4297C92ULL, 0x378EB5298A623F49ULL, 0xF74EFAFA242D99A2ULL
        },
        {
            0x6BFC91FADEF10F0FULL, 0xE187A90921086363ULL, 0x92E8953BAF5C2AECULL, 0x0EAAB1C70D7EAD55ULL, 
            0xF01D586C168033DAULL, 0x0350CA4B11148C15ULL, 0xD0A2B572035B3655ULL, 0xEF59698A19622DC0ULL, 
            0xB1DA5C6D79AD82F1ULL, 0x47CB639ED83F8FE6ULL, 0xC2643B92E053E2EDULL, 0x3D8F08455F40B768ULL, 
            0xB9D446E1C8DF5334ULL, 0x85603AC30E66F8B8ULL, 0x8984C188B4AE6290ULL, 0xDAA277AEB6F4A3DCULL, 
            0x38E2B1846C863A64ULL, 0xB4B399025E1ED042ULL, 0x061F812730645AB4ULL, 0x536E45DE4846A878ULL, 
            0xAF689E37B151DF9FULL, 0x77913C3D53E38ACCULL, 0xAC58B56CF2979DB0ULL, 0xF25D333C88E2355EULL, 
            0xD5C886DEDD7A40DBULL, 0x1AA755550BE3513FULL, 0xA8317450A51803B8ULL, 0x5CE062D8661C52CEULL, 
            0x25BF1349A0F9192DULL, 0x2239A8807FB2D6A7ULL, 0x060CAEEA20D2A49AULL, 0xC1C4E2206D66D0AFULL
        },
        {
            0x627664BC9B815B30ULL, 0x6DC6375F2E22493DULL, 0xD973DE4C9933344EULL, 0x53C19EF69F20F8C8ULL, 
            0x47128BC1264A4953ULL, 0xF1EE203F226A688BULL, 0x7C48F18639B6D662ULL, 0xBADF3B8878D5EA77ULL, 
            0x848E122B5B15ED8EULL, 0x09B6467CDFE56E2CULL, 0xCA9A2576C33E57AFULL, 0x6E55CDE05B7225D4ULL, 
            0x29A8DD61917012E0ULL, 0x88F4B8A4BCD1E433ULL, 0xE5107CDF21826336ULL, 0x8EBFF8F0439DEC3FULL, 
            0x5680DAC62D45DCD3ULL, 0x04AB35FEB364A5AEULL, 0x8557BA74723158E2ULL, 0xF43374AE181385B0ULL, 
            0x98C0926C3151FC91ULL, 0x6517F9ACCC75BA29ULL, 0xBDC42509B11840BCULL, 0xF66D06731432694DULL, 
            0xD0C3EBBDEE24FEDBULL, 0x87B847ABE2AEF087ULL, 0x3D9BED6A4888DAE4ULL, 0x26999846A293E74FULL, 
            0xCF41EA494D900A61ULL, 0x21105C3DD9C09908ULL, 0x6E53E1F43B161BFAULL, 0xF509620F895634F2ULL
        },
        {
            0x005FC80249DB7466ULL, 0x88B7ECC428D632E2ULL, 0xEA47D698ED34A5ACULL, 0xDEB6F238B53C836DULL, 
            0xA4099C19875304D2ULL, 0xF7ACC4EE67955DDBULL, 0xEB8765F5093B9195ULL, 0x42D99D66F4B04236ULL, 
            0xE03AFE8BE97EF1A3ULL, 0x85E1F47784FD1B4EULL, 0x3F996EEDB0DCF960ULL, 0x7A52A6045EC33C9AULL, 
            0x34A431735C61CA14ULL, 0xD693F488B3BA1F85ULL, 0x68B227ABD00FA5FCULL, 0xE31E840ECC1EECFAULL, 
            0x65E7BE2623EE04AEULL, 0x571CF2096A8081C1ULL, 0xAEDD672EFBB52EE6ULL, 0xABFF1B9C43D8384BULL, 
            0x69D4A27D7CFFEF33ULL, 0x864E70A2C256B8A1ULL, 0xB72B77BAF0E4A015ULL, 0x1A75694083E40FE9ULL, 
            0xAFB817F54EE51278ULL, 0x4AE0C8D5FE2DB48DULL, 0xB8F0BE13EFD93770ULL, 0x3D1AE389757D7EFAULL, 
            0xE83D06C9A26D4EC4ULL, 0x3C63D0359C326D4AULL, 0x261669B6058D5443ULL, 0xB5485401E2E2BF73ULL
        },
        {
            0xD759503E91F54964ULL, 0x75B14FCE70422F87ULL, 0x47B2FA1776BB01FCULL, 0x720F69EF1D0196F3ULL, 
            0xC9E4673965EBA3A2ULL, 0x858C6F810477E0DCULL, 0x76F58923277431C7ULL, 0x2EA7C524F090F9FEULL, 
            0x234714FBA281941EULL, 0x2833C536384D25D0ULL, 0x7EB18C79389B671FULL, 0x2B9A359AD7F93905ULL, 
            0x78C23064CB90823AULL, 0x0E6B18C6D91A4CD8ULL, 0xDC29131303081CB4ULL, 0x7341019ED56DBA3FULL, 
            0x876715CE8BE60BBEULL, 0x6B331BEBE11CA846ULL, 0x978D9316D0B35B9FULL, 0x5430CC056123768DULL, 
            0xC69C10C806055F46ULL, 0x155D0D19C8035B5BULL, 0x6F7F582AC8765797ULL, 0xFDA69F70819F6820ULL, 
            0xD3463B69074E6220ULL, 0xF5AAB1D5B1E72BB6ULL, 0xA39AEEBE9237E58FULL, 0x75B2A718EE13FD0AULL, 
            0xBD2FF5D4D11CDC2AULL, 0x2BD828B12599943CULL, 0x734D502A8C7B15D5ULL, 0x3EE56180F883F861ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseEConstants = {
    0x8038DCB4D3149FA0ULL,
    0xF29FDDF67CC37AF6ULL,
    0x8B6A043A3F5CF867ULL,
    0x8038DCB4D3149FA0ULL,
    0xF29FDDF67CC37AF6ULL,
    0x8B6A043A3F5CF867ULL,
    0x6FE9110C73AAB518ULL,
    0xF78D0B0E5BB2B0D1ULL,
    0x3C,
    0xFF,
    0x76,
    0x81,
    0x72,
    0xED,
    0xF0,
    0x11
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseFSalts = {
    {
        {
            0x005C0C4828417119ULL, 0x92F16700817B0726ULL, 0xEFEA7BBF23CEEF98ULL, 0xAF63F10EDBE62161ULL, 
            0x5A21181CB396F6E8ULL, 0xFF0C0AEC5AE793D9ULL, 0xEE4108E637B23EB2ULL, 0xCB84991095FECEABULL, 
            0x4E463F4B7FF2CF9CULL, 0x4E9CF810F78F1D10ULL, 0xDA59F4A58C2266AFULL, 0x9BBBF2B279211135ULL, 
            0xECD3957E88495953ULL, 0x9F6EEC9399787DCCULL, 0x7A94BC167DE9BD55ULL, 0x65B4784E7E8D459BULL, 
            0x3C5D5B39DD499368ULL, 0xF54C9588465B882AULL, 0x99791B01ACBF096AULL, 0x1789B41E6010CDCCULL, 
            0x7FCBA3C816B7E6BCULL, 0x0A8B46D4FC155819ULL, 0x665D3B0789DEAE0CULL, 0x2A6522C2B354515EULL, 
            0x9C7BDA08AEAAD86DULL, 0x22FCC97450A1851CULL, 0x7526EC593CAE389DULL, 0x978DDF24A2D034E9ULL, 
            0x8AFA8B6D7B134D8DULL, 0x8D46D6BE74E9890FULL, 0x66076024223DFF3CULL, 0xB43234618CFDE893ULL
        },
        {
            0xC770EB614009CC2EULL, 0xD0160122F1625DE6ULL, 0x3AA98E16E3AD5B01ULL, 0xDF759A2734B99627ULL, 
            0x5CD722F775E69C06ULL, 0xFB51AABC43DC2120ULL, 0xA04CECCA83358B6AULL, 0xE8C39F9BE2E363EDULL, 
            0xF9339E3FCB0683C6ULL, 0xCD7D6E896C71DE34ULL, 0xC506872D1E1C52D4ULL, 0x9BE240142A243E7DULL, 
            0x4C77516984494B19ULL, 0x5284D49CC00938B7ULL, 0xACEBDF60A6C3EE19ULL, 0x6EF2A7FC3D1C83DCULL, 
            0x9F4AC308455DB2B9ULL, 0xEFC9E49FCBFFD66EULL, 0x35BE80F26F9DA5E1ULL, 0x039A5F30C793B408ULL, 
            0xEFBF9096FF9D44F6ULL, 0xC786ECCC520087EEULL, 0xF61255897BC9E679ULL, 0x680F345CEDBCA680ULL, 
            0x801A9BB2ED9995EBULL, 0xF40531C96BA21DFAULL, 0xC5FE788352B1F36BULL, 0x9B8EC65D2F932847ULL, 
            0xF0DE50C8687348E2ULL, 0x54A36218BBE38FDCULL, 0x37CB89FD7909F135ULL, 0x9FAA736CCA6D8EA0ULL
        },
        {
            0x9EA7C88900DE9045ULL, 0xBA8025E84B958F13ULL, 0x78AC2A4322150F4BULL, 0xB8436EAE37934773ULL, 
            0xFFB39CB63B8292F2ULL, 0x85E87CD87F0A0049ULL, 0xADC1C819B3557A50ULL, 0xB8F49D4AF8B0C5CBULL, 
            0x08CEA876D93854E1ULL, 0x2AE558F55D04DFF7ULL, 0xF505BF5B2E4BC704ULL, 0xE54E93A10704C255ULL, 
            0xC06A1BE751F234AEULL, 0xD75D87DE8932E0A9ULL, 0x565F82CB699B5B7DULL, 0xC4B835BC41FC05E9ULL, 
            0xD0B25CA9BC42E471ULL, 0x45FB52EEF2807323ULL, 0x839D8DB35AC13D8FULL, 0xD4BDD5BE780DF7BBULL, 
            0x7AA61055993FF8C6ULL, 0xC704D2F8CF3FA9B8ULL, 0x70827FE07FCE0A44ULL, 0x70EE306271F82C7FULL, 
            0x78CF1CCDBDC97A69ULL, 0x7C2892FBE7C76744ULL, 0x962334452CBD5AC6ULL, 0x031593B154607DCDULL, 
            0x8838D11964D36505ULL, 0x4A5413EE3F5C7481ULL, 0x61979E6CA74AEE10ULL, 0x187679BD09E7646CULL
        },
        {
            0x20CFB50862D8DFF5ULL, 0xAD2B5FE75303B2E7ULL, 0xC2FA49D4D950165FULL, 0xC44CC952C5D7564CULL, 
            0x1AF3CBE5F18682EDULL, 0x51400D50A3395DD0ULL, 0x61CB978D7CD3DAD2ULL, 0x36F559EC876B7CA6ULL, 
            0xB7077FD2A8C3BEC2ULL, 0x92703ACCE65D05DEULL, 0xB379E644477790E4ULL, 0xF5145904CB05A2F1ULL, 
            0x2F7F7D9592DD50C9ULL, 0x61C709EF91CE6A46ULL, 0xA38F919A33FB334AULL, 0x77D17FAD0A41C575ULL, 
            0xFFBE186C78436F19ULL, 0xC62CCE82040F1F08ULL, 0x03B42DA2E36AE593ULL, 0xE7FB5ED428A0BDE1ULL, 
            0xB5E442691EADABC0ULL, 0x4462261E978A28ECULL, 0xF9DA1DC7946AD78EULL, 0xDCC15E8027BDF38BULL, 
            0x19DEBC85B1EBAFBFULL, 0xCFD9C977E719AD8DULL, 0xF3F2455401506A4FULL, 0xD75291D91387B55AULL, 
            0xD1F80F5F0EE86BF8ULL, 0xA59428C705F9E19AULL, 0xA37DD0DE5F0C0963ULL, 0xE089E79EAFA0EE98ULL
        },
        {
            0xCA358D1611A37A6BULL, 0x7B6642F9547DAC0CULL, 0xFFA4BDC2607427AEULL, 0x1C13BC3727D557ACULL, 
            0x83F1D482D2DA86BDULL, 0x6E99C0D63C7A16CFULL, 0x7CA3AFA17D4D66C8ULL, 0x116E81AEB79F1A11ULL, 
            0x8DC8D6C3D5B07D17ULL, 0x37F7E89C5225A747ULL, 0xA438869429296BCDULL, 0x3CAF536ECF2C0FBDULL, 
            0x0EEC141C97C9F108ULL, 0x6F04F3B6861A477CULL, 0x33E5E2FF3C719611ULL, 0x2618CA60C1994B3CULL, 
            0x8E31B567870477B6ULL, 0x33838677E1009E24ULL, 0x2892342773E1B82BULL, 0xD43181FDAF5FA979ULL, 
            0xE49369AD9E9ECB7DULL, 0x966EB3213A9A26D4ULL, 0x84C945BF6C659B8CULL, 0xA81D87EF41503AD5ULL, 
            0xEB300F24D06AE3DCULL, 0x94591572051E6BEDULL, 0x18501B8C5F5E836CULL, 0xE6FE4C1E8436ADE5ULL, 
            0xECDD97685A78858BULL, 0x0180EBFCDABE8253ULL, 0xE9C78EFCFEA8D605ULL, 0x2CEA9C6A2E53784BULL
        },
        {
            0x5980B7676B0A263BULL, 0xFFE479F1E2AF65B2ULL, 0x390E5835989470F2ULL, 0xDA642567B192103BULL, 
            0x940EA85B03E6D97FULL, 0x9F88D2EB8EBECB3DULL, 0x4B89C41D9241E07FULL, 0xA4660C68C914B1D6ULL, 
            0x605D589AC6DBC04BULL, 0xA8D5CBE42EB186A7ULL, 0x78A3C357C8A82A40ULL, 0x1E1063637B6C0268ULL, 
            0x418F8B18F9CBCB03ULL, 0xB1009425C3DAD059ULL, 0x36DE36C4103CC3E3ULL, 0xC08A821213A4FB51ULL, 
            0x0F9E2B6C050A3557ULL, 0xA958856A26531D48ULL, 0x63B0247AF8A696D9ULL, 0xF5E7C341E447B8A5ULL, 
            0x9F3D23FD26E12C79ULL, 0x6B4405662247E762ULL, 0x6589B609E96FFB74ULL, 0xE374F3480F667E7DULL, 
            0x301B554A2924352BULL, 0x38E3F7A98FBEA095ULL, 0xDA31926BB4A2AC78ULL, 0x404F2026B1C473CBULL, 
            0xD85F362861118DB6ULL, 0x2D1EFE3D8DC5DC7EULL, 0x3FB26F005274933FULL, 0x9282231BFD41FD27ULL
        }
    },
    {
        {
            0x55D32FE4AC405815ULL, 0x7B7464BAEE1A7548ULL, 0x1D0332DC8B01683DULL, 0x123479B6FB729590ULL, 
            0xBBE736DA7BE8FE7DULL, 0x76E86E72E3FF1ED8ULL, 0x55A1E35B68616ABBULL, 0x0CEE3CEC43D910E2ULL, 
            0x6A83D4D264F9CE8CULL, 0xC14AFF037A830674ULL, 0xF7369164D48F581EULL, 0x6732E609200B4684ULL, 
            0x88CDBE7DA50B3ECBULL, 0x546D5FB25C25F7EBULL, 0x36B6221ECD60779AULL, 0xED51CA6332B6E90BULL, 
            0xB27C6E4600979AD8ULL, 0x12F5E7CE412129C2ULL, 0x69A1131821E6B6CFULL, 0x4D502AA2E7ADDD62ULL, 
            0x18D730FE403B79E6ULL, 0x42D4655E591C085FULL, 0x95BEF5C89183FE69ULL, 0x4F32B6CBC40143C2ULL, 
            0x34DB8F0682AE2430ULL, 0xCA43E445066B4444ULL, 0xCCB79F4767DC2DAAULL, 0xF73B6154228A4746ULL, 
            0x919DC17F38DF9BD9ULL, 0x3C66FC14F95121D4ULL, 0xD9245AFFBE4C7676ULL, 0x29BC24CBA675A27EULL
        },
        {
            0xB7CACAD626754848ULL, 0xAE033D4DF73E6A88ULL, 0xA0BCC93EF66D2052ULL, 0x08278E891EE46966ULL, 
            0x2120DF692CCB25A9ULL, 0x28D4B43B1FE90CC0ULL, 0x49E14D8E56C1FC46ULL, 0x52749295A75FC006ULL, 
            0x384567C8A0DCA619ULL, 0x81EA566B2C5D55C7ULL, 0x0E71DE3605ED1B1EULL, 0xEBB6C67834FB82E9ULL, 
            0x28F04E4CC7BD0B64ULL, 0x32AB98A93267955FULL, 0xDE88D273B00297F5ULL, 0x188010E23E604BF9ULL, 
            0x46606966048F8CA5ULL, 0xD3167317DC87C12BULL, 0x8A1CA88A2D401D60ULL, 0x828504013C11762BULL, 
            0xD001C30CEDB35EACULL, 0x2347C259BD923328ULL, 0x54BC025F41EE4387ULL, 0x555B37BECC8359FFULL, 
            0x02E1980FA450E16EULL, 0x56F5DD991C7CD48CULL, 0x0C3F08E8C761C6E7ULL, 0x51F6D61F02188A59ULL, 
            0x64A321DF76F8FBCEULL, 0xAEEEFAB11BDFF206ULL, 0xC45CE38F904A357FULL, 0x85C5E37E63DC779EULL
        },
        {
            0x3B8AD59C8C5D0164ULL, 0x09669F21FD1FCBBCULL, 0xAD042D7AE8E13A98ULL, 0xF0EAD6E9F772B182ULL, 
            0x466163B638DDD28BULL, 0x4DF80736C764124FULL, 0xF2480EEF6338617CULL, 0x5034FC27AA8C7372ULL, 
            0x753629B8226128C0ULL, 0xC10CA2BC09CCD898ULL, 0xECE570B38E60D635ULL, 0x05735CFE6172DCBCULL, 
            0x8EA7F359CD096148ULL, 0x3707DA1876C19784ULL, 0xB829EC23724F72FAULL, 0xE6F48D53BE1B6B92ULL, 
            0x4C82C63DF10BCEBCULL, 0x0A771B6F39F211F2ULL, 0x301DA6BDDDF73CBFULL, 0xCAC2A15EEEE9B0ADULL, 
            0x7DF536B5409424A3ULL, 0x2BAC75C9BF7D3023ULL, 0xE928E0AF07794625ULL, 0x75EDE22C4C6A87E1ULL, 
            0x9C654DFE1AB6548BULL, 0x4745DC66830AE27EULL, 0x61C0D46C8ACDF43AULL, 0xA3FEB92C599252C5ULL, 
            0x49C261421A915F06ULL, 0xBF34B4E53BFED24CULL, 0x93A9A8B4CB40D33AULL, 0xED77EAC282248B00ULL
        },
        {
            0x90A28459447122A1ULL, 0xB9830758E8F10E74ULL, 0x3AE339995CFD379AULL, 0xEBA4C6F17360290FULL, 
            0x5E23841739C6821BULL, 0xC9AB6333765CEFD0ULL, 0x11184064636BD93EULL, 0xA552F834CF6231ACULL, 
            0x7875FA754B0D10E9ULL, 0xCE4B5C8E5FADE42AULL, 0x3B34DE14ABC5AF6BULL, 0x1B194C9F2207A77EULL, 
            0x3FC08ED1BD8D71C8ULL, 0x8090890DFDF8C68FULL, 0xCCD95D85E6005E5DULL, 0xDECEE2F39238ECD2ULL, 
            0x01ED59420A91A6C2ULL, 0x353C3DA0F67D1293ULL, 0xB6456602FF220211ULL, 0xF7063D7BF441B0F5ULL, 
            0x099266CBFA62CB32ULL, 0xE215F629ABCA2339ULL, 0x033F6DCAB32960C6ULL, 0xD3548E3A2DF8259CULL, 
            0x4E21139FC4CC1359ULL, 0xF61A22652BBDDDA1ULL, 0x73B714CE47E915E2ULL, 0xF88A3493C33BC3C6ULL, 
            0xE66B791C74DA5E36ULL, 0x37E65F2A7642EC58ULL, 0x0D11FB9B4E54F4C9ULL, 0x1039756AF1B437AFULL
        },
        {
            0x9EAB893DDA60883DULL, 0xD6B0FCA54BD6009DULL, 0xA176D10AF7100E54ULL, 0xB2ED8DA8773D5E65ULL, 
            0xA10BFC048478090AULL, 0xCF3C81A5ED67BB6AULL, 0xE962A49684EDACC3ULL, 0xF394BB6868D4625DULL, 
            0x37424CF20D6C07BCULL, 0xDCDCBEB2CA037579ULL, 0x34F9863BFF7FA511ULL, 0x7DF0971B963318FFULL, 
            0x26312554B60E6DC3ULL, 0x638F0971F7F7834DULL, 0xCE04D8796A8736A0ULL, 0xB09EF0CE92A25BADULL, 
            0x60419FFCF46B720EULL, 0x7291A6CB5FD952B0ULL, 0x7ACDC7DBDB83D1D5ULL, 0x5D04746C89FF62E9ULL, 
            0x32C4085132BFB2ACULL, 0x459C4C41FDA3656AULL, 0x4DA39EA6A6749D3FULL, 0xD7256181A61854B5ULL, 
            0x4005A5CA2C65CBA1ULL, 0x70A109BDA865FCD0ULL, 0x9D5D6F9611AC0B52ULL, 0x8DC9DD07E806FBB1ULL, 
            0xAE8549FE67113086ULL, 0xF4066E56CC07DF4AULL, 0x4F5153F5722F6BB7ULL, 0xD840F31A8160E06AULL
        },
        {
            0xB4B52BDD85B30C02ULL, 0x6A85830F16A80DECULL, 0xA511A3A2751B03A3ULL, 0x846C6EEE6CBC3DA6ULL, 
            0x7CE13942BC192277ULL, 0x01F37321D714470AULL, 0x31E3D1CB97817BB7ULL, 0xB797318B059FC696ULL, 
            0x46E58743E994E1B5ULL, 0xEB16102B203CAC45ULL, 0x625C8911774F2199ULL, 0x399F20A869307175ULL, 
            0xCB952F991628A33FULL, 0x0CE5FC8A97A73F85ULL, 0x500B75FC6E5840CFULL, 0x5FFBD83047471EDCULL, 
            0xC5AB89ABFAD3FCC4ULL, 0xFB5D9AAE9F8DF975ULL, 0x2D577DF8E433BCD5ULL, 0xF035687C359B441FULL, 
            0x4C5BC7FE697DA22CULL, 0x247992D0069BE6B8ULL, 0x8A61EDC55A244045ULL, 0x8669890C6ACA9A1CULL, 
            0x5EED3C66EAB3B6CFULL, 0x6D98258F01836900ULL, 0x4E211E0C942CB432ULL, 0x9F6438BC27D6A56BULL, 
            0x2C31BDED14583D29ULL, 0x5767209FDE0A1AA4ULL, 0x90BF2AD0313CFE95ULL, 0xD663F9629115BAF4ULL
        }
    },
    {
        {
            0xE60F034EF3B3F7AFULL, 0xC6A194EF866E66C8ULL, 0x33BCBD17644309A5ULL, 0x3F83F4AE741C959AULL, 
            0xCEAD4C8DD0C45F25ULL, 0x7CE6B4CDD1109512ULL, 0xEE8382C09F596AA0ULL, 0x331FC074F63646CFULL, 
            0x56AE8E585648FDC1ULL, 0xE05CB75DF1AF3E76ULL, 0xD7FF421093DECE5AULL, 0x36BDA2005F526EDBULL, 
            0x0B9D132A89A43925ULL, 0x415DF22086E47547ULL, 0x453FD3CD32A7AACBULL, 0x8D360F67C715DCF3ULL, 
            0x725A9F57DBA1A0F0ULL, 0xDCF57E8CA2012B2AULL, 0x9AC314231909B503ULL, 0xCFB7E85B8B144B58ULL, 
            0x1496BCB57319CD74ULL, 0x05E27B7EDD49D34BULL, 0x2F2B9A7AD589A257ULL, 0x8D58CB1143E89DDDULL, 
            0xA5CC919D2FE87043ULL, 0x3DF2F04EA766F6B9ULL, 0x04A2E19996936788ULL, 0x64CAF2D6C33E5D76ULL, 
            0x63B7F82E32B1F3D5ULL, 0xB6BD081C78DF55AFULL, 0x845292094A16EF5EULL, 0xA1105AFFEB1CECAFULL
        },
        {
            0x9CCB332534FAD12CULL, 0xF4B51C7F62E1469BULL, 0xC040CC5A1E671146ULL, 0xEFB1F6763A772F22ULL, 
            0x1CA753755E3DE799ULL, 0x019FCBA8F938F11BULL, 0x6F85DE20440CFDD0ULL, 0x641B447E908F839DULL, 
            0x67106D1D8C466F31ULL, 0x7FF144DB9CE4F606ULL, 0x61E99EADA348E9DFULL, 0x466CDC564CB8A574ULL, 
            0x9448550A09CEB08CULL, 0x01154D197D65521EULL, 0xDE66BEDDDF89FF2EULL, 0xC4052AC591480E4DULL, 
            0xCF5BA6283F97613FULL, 0xEDFA747B922A4123ULL, 0x5DDE87CC3AC002FEULL, 0x0DB167543351BFC7ULL, 
            0x67D317CB9097E1DFULL, 0x103F65B4A362AD54ULL, 0x2E5CB3BC6C29268BULL, 0xB6F9132C599C196CULL, 
            0x64BA682AAC37BD1BULL, 0x9B7684183DCC12F4ULL, 0xA1B67ACE7D9EFF48ULL, 0x2F183086FE17DEE8ULL, 
            0x8B746A4CD8C42425ULL, 0x9B9D8F6C451BF1A3ULL, 0xB89E02893FCFC1BEULL, 0x71E3732C13EDAF10ULL
        },
        {
            0x80E2D631B2381004ULL, 0xB834FB3E8AB2C609ULL, 0x64141DC6B1D9C865ULL, 0xAFFD1249700D3E40ULL, 
            0x5E36305844433FF1ULL, 0x8AC3066710573657ULL, 0x32E35BB22B1977ADULL, 0xC9699928E870C982ULL, 
            0x4ED03511ACB7B683ULL, 0xC66B2EB2D6E10684ULL, 0xA8A811586C97826FULL, 0x179EFC6450C56B5EULL, 
            0x0ED1CAA294985218ULL, 0xEDB94FF4F3695F21ULL, 0xE78441858C884677ULL, 0xB8B3D1A6048521A8ULL, 
            0xB50073076DC7EB37ULL, 0xC8DC12CAEFB98643ULL, 0x6211FD39E27997E8ULL, 0x0D813412D9F18323ULL, 
            0xDAE79BC4B2FD220BULL, 0x21F13695C388FC29ULL, 0x7487D048CA90DE29ULL, 0x8B0372C1AE6FCC18ULL, 
            0xA6208FE5FE6DE712ULL, 0x6FEB39EBFFB75FAFULL, 0x1481E9E2829906E9ULL, 0x46656930FF94AFB7ULL, 
            0x7539D9E21A5ABE68ULL, 0x093CD0E3518218A7ULL, 0x9A5A1EE9B727EC2CULL, 0x48719607A93F6849ULL
        },
        {
            0x14710B9607A2091BULL, 0x0A15DF0F4FC8385DULL, 0x874E3E76B0A80875ULL, 0x329D434514F43676ULL, 
            0x049B78E8D0160CE7ULL, 0xBFAF630A54ECBD12ULL, 0xBBEE3E9ACFF4DDAEULL, 0x4F1FAA36E2DDDA88ULL, 
            0xE43FD6C2F687FD77ULL, 0xCF2150F69DAB8871ULL, 0x346C25D6F54EC6F4ULL, 0x72DDF891003B55C1ULL, 
            0x80401DA21AC5199AULL, 0x07479EC82FFBC9D8ULL, 0xA0149B333389CAB0ULL, 0x4A66585114C73383ULL, 
            0x02B14A9281F81869ULL, 0x6E7F2D5F62789708ULL, 0x1FF76D3094383A3BULL, 0x2BF1D78F2452D0CCULL, 
            0x90DD40C2EBD4B8C7ULL, 0x0385DB5B37B8E0D4ULL, 0xC9224C155420ED4EULL, 0x833E9EE0CFE86336ULL, 
            0xE2D9F36C73AA5274ULL, 0xA8ACB642E9FA68BCULL, 0xF114179C0F6028F5ULL, 0x0DD53145A4E96718ULL, 
            0x6B25349F8AADA2BDULL, 0xBDC8ACCC35E9DBB4ULL, 0x4C11837A568AA7B0ULL, 0x06A3A94FD5DDCA65ULL
        },
        {
            0x31603B43D7889906ULL, 0x59EAF4677A1F2E92ULL, 0xDB1BD684576D150AULL, 0x82150063178A9AD7ULL, 
            0x060DF349A57A302EULL, 0xD07A75507BFC5280ULL, 0x5A0C8B446070D48CULL, 0x0A4C84EEA7C5D9DDULL, 
            0x7112D985F59AF075ULL, 0x5475988AD830FDD4ULL, 0xC1B0BC9B4457C58CULL, 0x58AFF4A5813F0F9EULL, 
            0xD93DC0041B8B1A34ULL, 0x45A85DB00FAC8F32ULL, 0x2A01E2DF51599C8DULL, 0x1134B6CED77A232BULL, 
            0x50D91337F9BF46AFULL, 0x6915AF094200E2E0ULL, 0xB569111502466515ULL, 0x47E0EA7976393E84ULL, 
            0xF2678864A3B69F3BULL, 0x3E9BFED71B1E08B3ULL, 0x7C913BAF6E6A6EA5ULL, 0xAF8B6AB62D0D53AEULL, 
            0x5DD04DAC57508ADAULL, 0x44CC92AA2913D45CULL, 0x07146B5C858F0488ULL, 0x2ECC94AC15721085ULL, 
            0xB1BACA34EF309C3BULL, 0x360F667E03649A14ULL, 0x9DB4C95CFB7E1E16ULL, 0x147D205994B12ABBULL
        },
        {
            0x61E787EBC73C00E5ULL, 0x559FA87C1D07BD75ULL, 0x6F97D2CE129EB9F6ULL, 0x285AC8D42E20ED9BULL, 
            0xB00253BCD6F2BB16ULL, 0x3518FA5E04578357ULL, 0x78C3EF922A1F4D93ULL, 0xD32A94DC8E8BA1C0ULL, 
            0x47F1C3AA873D7CEFULL, 0x5D281F855F894EAEULL, 0x9BDEF9AD8775F491ULL, 0xA6027EBFCC885E82ULL, 
            0x7F505630A3257DFAULL, 0xDB7C592D9E6CFC5BULL, 0xE2545BE1F324513EULL, 0x58EE41ED0892D058ULL, 
            0xD602B32C6B4C017BULL, 0x33A65685198E9AB9ULL, 0x6AB8F1E61F871039ULL, 0x6F3F4578A68ED6D0ULL, 
            0x6DC4116D9B01DE0FULL, 0xD87C9727E7C4ACE6ULL, 0x1E1200A5D5DC0681ULL, 0x6B930C162429FDCAULL, 
            0x345D2B401B1EA2E7ULL, 0x62FC63661B2B04F4ULL, 0xE4435F9D43CDFA92ULL, 0xAEB9960331FC8D80ULL, 
            0xBFC347A2DF536611ULL, 0xDA3F13DFED2D7BEEULL, 0x44F82C3400855696ULL, 0x3B05DEC9F10D996AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseFConstants = {
    0x401A111BF9E77FF7ULL,
    0x2A6F0D4E73513CCFULL,
    0x74CFD3719E5E0215ULL,
    0x401A111BF9E77FF7ULL,
    0x2A6F0D4E73513CCFULL,
    0x74CFD3719E5E0215ULL,
    0xB94E4B015907B1BAULL,
    0x3E29D19B4D1436F4ULL,
    0x18,
    0x5C,
    0x5D,
    0x97,
    0x43,
    0xDC,
    0xB9,
    0x8E
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseGSalts = {
    {
        {
            0xD157929F9CF53426ULL, 0xF844C46859454EABULL, 0x96DB572275530477ULL, 0xF139EF8C4D551539ULL, 
            0x6B35A535A4AE79B2ULL, 0x62D89F4590D41A08ULL, 0xD73C10101C186D7FULL, 0x103156F340664491ULL, 
            0x76EB8A2EF7F7A8BAULL, 0x748EFF6450AAF831ULL, 0x78FBCBA61A26912CULL, 0x46F391E6BAC85D20ULL, 
            0x99DF39B3CD7E6851ULL, 0x34B68BD27E330D0BULL, 0x1DF14F409E785498ULL, 0x9FDFE65D131F69C7ULL, 
            0x217825FF0F355755ULL, 0xF186CA797DC60D53ULL, 0x49497F124ACE21B0ULL, 0x12697EE0388D66EBULL, 
            0x954CC5C37E4D5834ULL, 0xC538C8F32AD51D78ULL, 0xB088CFA738A0AF06ULL, 0x4CE7D55D14C0B3D1ULL, 
            0x34C6E3573DB8D991ULL, 0x048F6F42CC26B414ULL, 0x645EAC6C52C9C69AULL, 0xAEEFBF6A7207FD1CULL, 
            0x239355C475B2E068ULL, 0x88058C3B00A8919AULL, 0x52D3169374A30642ULL, 0xD5E2C97C5A8966EEULL
        },
        {
            0xC88F44CF3B7AB3FBULL, 0x60255A17D8AA20FFULL, 0xCD39119021B6574FULL, 0x5794CE3EFCD21013ULL, 
            0xFA6EDE828E9DE015ULL, 0xAE70A9CC350E3CEFULL, 0x980B0D5886AF85EEULL, 0x3A190988D1A4E851ULL, 
            0x7C68D5966910F86AULL, 0x2CE95D823737A4D2ULL, 0x278A00E7346EE205ULL, 0xEF6CC815E9D01D9DULL, 
            0x3485F7DC9E1E6186ULL, 0xA2F62D8488AB48F9ULL, 0x1D10878708490660ULL, 0x00B351571A5A1BF2ULL, 
            0x241494E0CA59C5A3ULL, 0x3CFC956C452CC587ULL, 0xF2AEC1E65053B5A4ULL, 0x2FDD104D907FFBFDULL, 
            0xEE1931ACFF3A9BB0ULL, 0x440AE413C76F8F73ULL, 0x6322B5A442F0581EULL, 0xE2AB0C1005560EACULL, 
            0xE6193C9A1D3C624FULL, 0xA72616EFBC66B50CULL, 0x705FF7C399864B5EULL, 0xE47DC1E76ADBD29BULL, 
            0x9CC5BFB23E382A72ULL, 0x372A0EF42C32D77AULL, 0x9DEDE91696BD0442ULL, 0x98F5863E656DE1BEULL
        },
        {
            0xAA34F0ACFDBDD9C7ULL, 0x88C9B48321BA8E53ULL, 0xAEEA2CBA839D8F70ULL, 0x1E151194A4464BDAULL, 
            0x3A7291834E0001B2ULL, 0x70A02728571E781AULL, 0xFAA36A4E3A5665F5ULL, 0x7A177D5130F729C9ULL, 
            0x2A07E678441044B5ULL, 0xB6AAAA284BE4C0B7ULL, 0x6FBC388736A30AD5ULL, 0x5D5C5E1184775256ULL, 
            0xB053A626FDB239B6ULL, 0x0AE9F51904015AB0ULL, 0x0D9D7616A257AF5AULL, 0xCEFFC284F7B286C2ULL, 
            0x851DACE5B4C59575ULL, 0x7AD6F6AFEDD7E9EFULL, 0x3C49E2ECE85E4F6BULL, 0x63A7478FE198FCA0ULL, 
            0x622E187B6A30D7CEULL, 0xAE2CEDF03C1D8B05ULL, 0xC7CA21B8FCF3B8AAULL, 0xFF0CB1A2EB9D2595ULL, 
            0x06E80880F1F3E1C1ULL, 0xF7C690507A71AEE7ULL, 0xE91AFAB649E601E4ULL, 0x1EF3B6DE52264258ULL, 
            0xAEDDA8E9280EE6C1ULL, 0xA16D8DBEDDB350AEULL, 0x36859BAB47452FA6ULL, 0xBCB43752FA65189FULL
        },
        {
            0x47F9ADEE47B3406FULL, 0x8DCFC5E746994CE9ULL, 0xD4F781C0A5B123B6ULL, 0xE880C5D1ABE39755ULL, 
            0xDB6AFBB24ADD51F9ULL, 0x45FD5F9AFAD41EAFULL, 0x0B1F54156A35F531ULL, 0xD0FF6BC8267D3B82ULL, 
            0x41A45E25CBF9AF59ULL, 0x82CE8E7A9F1AEA8AULL, 0x68BD675D2DA07427ULL, 0x02864E5BCF26829DULL, 
            0x8B7B2BC66228DEDEULL, 0xA6BF0EAD86D79C8DULL, 0xF27C80A58526D11AULL, 0xCB2A8520555B0C07ULL, 
            0x4C2BD82E30AA690DULL, 0x7946F93F1E2247DDULL, 0x9040BCE7BAD00360ULL, 0xC22B61DDB18D434BULL, 
            0x98623EC25E1A808DULL, 0x113BC1BBBA20CD85ULL, 0xCA08651288419FBDULL, 0x1A8EBDD4A12C7927ULL, 
            0x4AEB123F6E19DA5EULL, 0x9F7427D90A5095AEULL, 0x4CB141D5C0B1CAA6ULL, 0x89476339A6468391ULL, 
            0xA03FB834A14AA31FULL, 0x163D5660116ADF59ULL, 0xF4CE050EF75A61C9ULL, 0xC3C26495483FC1A3ULL
        },
        {
            0x4172CD4468863D9AULL, 0x56E4710D5585BC90ULL, 0xFEE4DBF812F5EF12ULL, 0x0092E7F063114E40ULL, 
            0x7F81D67E6AE572ADULL, 0xFCDA50154C39AB2CULL, 0xEEFF0D2C92C82D47ULL, 0xD9B9E54AE7DBE404ULL, 
            0x3D91E73B895EA397ULL, 0x6EE3102BD136C44CULL, 0x807D4F1D1BF4D432ULL, 0x6CF1C76852264DFDULL, 
            0xC3444210D2FB419DULL, 0xDC8E260FCFA1BF84ULL, 0xAD5D809B4CF4741BULL, 0xCD90547BC88CA6C0ULL, 
            0xAAA342D21F830E0CULL, 0x42C1A032CF7E33EAULL, 0xDE9807E03B56A1EBULL, 0xB6055E0CBC3022AFULL, 
            0xB5C63A9155E53DA1ULL, 0xC48955EAF971CC9EULL, 0xC8295B29413FB712ULL, 0x68F03CD169231CDEULL, 
            0x6BFF36A7BA7F7BD6ULL, 0x3400030523C0C532ULL, 0xCB34786B7E671C21ULL, 0xFD6372DCE931BB70ULL, 
            0x0AA4961972B9AE49ULL, 0xDF7340AF08E42EF7ULL, 0x29AB9C503E3A5EC1ULL, 0xDC065EA42F980A71ULL
        },
        {
            0x2852D97F3DE20542ULL, 0x133DC561A8F1BEF6ULL, 0xA5AD388AD7FBE375ULL, 0x078661DE48AF6048ULL, 
            0x529159BD3825FA24ULL, 0x84E3CB78B8781932ULL, 0x8C27713B7610E810ULL, 0x3E44BAE3A913CA31ULL, 
            0xFF05F6CC44FB1F07ULL, 0x3415FDCDE4E6D386ULL, 0x77EAED5E80E4E386ULL, 0xDC108568DC5B2BFCULL, 
            0xA016708F869802D3ULL, 0x40AA0245D9E31CB1ULL, 0x4865A886A6F7118FULL, 0x14DC72394C27C495ULL, 
            0x3A44C77574333507ULL, 0x6666B6DA66401C98ULL, 0x2269CEE13382F606ULL, 0x077B189691B12E2BULL, 
            0xA5EAADC7E62EECB0ULL, 0x7435E198A36455B4ULL, 0xAF7C8706EF5595ABULL, 0xD076A9F9F31271C5ULL, 
            0xA3A6DA4A3ADA4480ULL, 0xE04D69615A3B19A2ULL, 0xEC9B4B3130011C08ULL, 0x6D1CE2DD872B5BB0ULL, 
            0x7972C13FD93B1CF6ULL, 0x9819218A6F2ECBDDULL, 0x0514ED5D2262C319ULL, 0xD46E16634FFA428CULL
        }
    },
    {
        {
            0xFCFB2B24F6F441FFULL, 0x3557DA1543850656ULL, 0xCB6DBC4A30F310A9ULL, 0x24F715D335B6E827ULL, 
            0x56E3313B2D81FC57ULL, 0x6D457005653949C9ULL, 0xDE96DB5AA316B11CULL, 0x66F4A710BA1A4DF1ULL, 
            0x4934956BA6BEC296ULL, 0x17D543AAA19E67E5ULL, 0xA04CAA96A497F8FCULL, 0x671DEDDBCD766864ULL, 
            0x011F331CAC8197BEULL, 0x6EDA746A171D82A0ULL, 0xBC8869B42E4B4292ULL, 0x934FCDB0C5E70840ULL, 
            0x98BEC6F5D74CBA64ULL, 0x99235BDAA1B81CD0ULL, 0xE87752436C91E731ULL, 0x734657D040F449D7ULL, 
            0xF534FAB8B61B9B5DULL, 0xCCE2CF8F35EC7908ULL, 0xCCE1217D06CD0B63ULL, 0x802C1AEE7D8EBC49ULL, 
            0xAC1B3850FC959AAAULL, 0xD149D806C8E6532EULL, 0x34757A3F04689F36ULL, 0xDFE19379D6DC7C1EULL, 
            0xBDEFB4CE7398E1EDULL, 0x335FC8FFF16450DFULL, 0x8FDACC7C0E7DB93DULL, 0x99C4357C160FA9CBULL
        },
        {
            0x4C6C7FD228A3CEC8ULL, 0x361BAF2CBB13646EULL, 0x6D2352DE97F7C070ULL, 0x5C27EE954A57E913ULL, 
            0x3E65B2154A55407CULL, 0x8A8488CA270D775DULL, 0xA89155809883461EULL, 0xCA95B75F2579AC84ULL, 
            0x0396DE1D060AD419ULL, 0x6C35CFB8DD1140FBULL, 0xC921F0DC8270C4CDULL, 0x7C7293EC30C7DF12ULL, 
            0x8B93AAECCD237560ULL, 0x72DF57A6FC7EE2C2ULL, 0x6687AC14F54C3A21ULL, 0xD489F3FF07F08F81ULL, 
            0xA0B833E8963FC8C0ULL, 0x8E9DDF22A5FB463CULL, 0xC99BCCC1490F7877ULL, 0xACC6BFB080A2A2FEULL, 
            0xB35BA55E35E5B474ULL, 0x3F7CE60D0F32C6C0ULL, 0xA984E0704813FF3DULL, 0x565371BC8B547D4BULL, 
            0x0D188E7E079B3596ULL, 0x21294279A2FD2BA5ULL, 0x42D3515402B8397DULL, 0x58CF77BDB7D7B10AULL, 
            0x90FCC669661F0B4CULL, 0xDDFB2B84D74EA3B7ULL, 0x0B4D719598A1B7D2ULL, 0xE6D48AB2D155F3E1ULL
        },
        {
            0xA59677FCAFC666D2ULL, 0x580A7F8C6A5F7F55ULL, 0x12259B7A3A1F3DD4ULL, 0xB5FA7F20FD7C8CBCULL, 
            0x928552D5A4D98D9AULL, 0x76DC87DCB5FB20EDULL, 0x38A317B74FAEBFE5ULL, 0xA3FFDEA43810C220ULL, 
            0xBF9F2097B14D588CULL, 0x9F83B1E3AF06C8D0ULL, 0x37A6DEE33DBE6020ULL, 0x120AD6CE8997A8C1ULL, 
            0x9B5D89D94D0A0803ULL, 0x7EB1B7D71A3A5160ULL, 0x8C29ADA0AAC201A8ULL, 0x237E005F7DC775D8ULL, 
            0x25C5C4C48146DC9BULL, 0x8B1E4D1B01E76B28ULL, 0xA7F55980A8C14B55ULL, 0xA6D761F3E4B67252ULL, 
            0x676A1DEAD31990E0ULL, 0x764687FB9DBD2FC7ULL, 0xF0C9735BB7B2D89FULL, 0x0AD7C1C9C8D93F36ULL, 
            0xB7FD1DC55DDB65F0ULL, 0xFCFF4BC569C533AAULL, 0x7C7CBCC2EB87E591ULL, 0x7B1E174CB6883B06ULL, 
            0x69072C9196A11E95ULL, 0x7CF80671492717A5ULL, 0x116F438DF5AFA9F4ULL, 0x36F51DBA1E58F982ULL
        },
        {
            0xE313343311A56930ULL, 0x01A7D84C61AE963BULL, 0x1FAEEE6096164110ULL, 0xF649CB17B90EC92DULL, 
            0xBB014BBDED67722AULL, 0xA2B21D78ECD8FC91ULL, 0x7A3C94AC43D4AA4EULL, 0x6FE49DE80635DF87ULL, 
            0x53F4D7BFE51AAD34ULL, 0x5FD69D350CC9392AULL, 0xE7E9590E0B9943A6ULL, 0xCB250EA7A53B5BFEULL, 
            0x37F9A0473C603FBAULL, 0xF544516692F7858DULL, 0x78C817B5655498D5ULL, 0x86950F3FADF9691BULL, 
            0xF0A46C96996C86A8ULL, 0x8D00024AF6FC6AB2ULL, 0x5C71AF02E7417F4FULL, 0x00A062034908BD92ULL, 
            0x263F01C02BE6AE13ULL, 0xF4C06BBF380B03B1ULL, 0xC8C9D3EFEF2DA701ULL, 0x9C1EEE005C14C23DULL, 
            0xD7D1A29983459B56ULL, 0x4AAF33368F0B67B0ULL, 0xD368D3F83CE77905ULL, 0x38E7138D25672462ULL, 
            0xEF9A38A7EC47DDF1ULL, 0x361B084C386B5B40ULL, 0xD7E18C1DBF2E6F33ULL, 0x46C0E412F8394F0BULL
        },
        {
            0x062675C358ABD2F8ULL, 0x7D44B2FB71D7C3F7ULL, 0x2B28A64416DC4FEEULL, 0x4E26646004B2A4A4ULL, 
            0x0AA2E71E5A550149ULL, 0x389615A7120B8C02ULL, 0xBE9AF84F048E5F79ULL, 0xCBA0197E745ECEF0ULL, 
            0x12A83E89F4B15722ULL, 0x6BA0439EC64834EBULL, 0xCECDFC087394C477ULL, 0x7A40A474805F28B0ULL, 
            0x6FE559E1C7F253B7ULL, 0x31999C998176D918ULL, 0xF21FDECF0E0CB1CDULL, 0x928E4CD8A6696D79ULL, 
            0x7C51C7AB07640C49ULL, 0x7C95156501ED0770ULL, 0xCF7A83A49888D713ULL, 0x723FEBC21E953D47ULL, 
            0xE193479F00833E70ULL, 0x4F34FA4026E06B6CULL, 0x43A0B4BB865E3C92ULL, 0xF614C12C44500569ULL, 
            0x19D1C599C9156B78ULL, 0x4F730B890A08F5AAULL, 0x48ADB4477F221726ULL, 0x902EC9F5245FD388ULL, 
            0xE803EA59A656B07EULL, 0xECE9AD2D8B4EE665ULL, 0x58739011B130507DULL, 0x88780F2178F241CBULL
        },
        {
            0x889A6BE1439F1930ULL, 0xCDF610DF26B9670BULL, 0xF23AEF0B9C4364A7ULL, 0x1A519378455E36F1ULL, 
            0xAB6CF8C00C5A0395ULL, 0x69C732D9E91291EEULL, 0xA26324C90AEEA12DULL, 0x0EDE5A02400A2F8DULL, 
            0x7CF168836B3B585FULL, 0x14970F08B0781C2BULL, 0xB863E87E58245169ULL, 0x1745A3F8B3B58D1CULL, 
            0x194B6A5839903A62ULL, 0x61FE8A982D90212CULL, 0xAC7D420B6B4F3537ULL, 0xF44957BFD264A3C3ULL, 
            0xF06E7A2164D64737ULL, 0x66EE1E15ED0597CBULL, 0x985F1D6D08309783ULL, 0x770C27F51BAF19B3ULL, 
            0x1C01B71F649A1F06ULL, 0x1BBB9BB4D10CD092ULL, 0x5C8D4CED9846EEF9ULL, 0x5BA4174F2101ECBEULL, 
            0xAC5F3AB992754040ULL, 0x7BC0DB9F1757BCAFULL, 0xE66D769D77302CC0ULL, 0xB7E0965F4669F460ULL, 
            0x36CE11D34EE0289BULL, 0xC5A623448999B5D4ULL, 0x6478B6770BB3D30FULL, 0x15F3DACE80E3B93CULL
        }
    },
    {
        {
            0xD8EF8E2DE58DE717ULL, 0xEC81986B11B8FA68ULL, 0xC9C00A9F4D092544ULL, 0xB56DC45A322FB44FULL, 
            0x012E10C77B981725ULL, 0x5180ADAA12B45BD4ULL, 0x56DFDD9BD2AAA3B3ULL, 0x8238EFF8DC30EAD0ULL, 
            0x6B539B6A8E2781FBULL, 0x326A80726518B1A5ULL, 0x189BA22B7DC2CABFULL, 0x8885EBC3B85F51EEULL, 
            0x34FBA9970807769FULL, 0x1BCA1C07795ED4DEULL, 0x9D31AD8BC2A009E4ULL, 0x6046347CAAE2908AULL, 
            0xF27543C22BB12EBFULL, 0xB937E84D572C5A42ULL, 0xDFDBEBC3BC8BC097ULL, 0xF050DDBE14741EE8ULL, 
            0xAF74B06EAEF7D55AULL, 0x301E83766DFFDEEDULL, 0xAFDBB3E0745DBB4CULL, 0x2D0BABDBF52CDBFFULL, 
            0x435F6FE3DC3910F5ULL, 0x9E8FEDC3F0516CAAULL, 0xA7178D70D9EC7915ULL, 0x76662D2F35D1AAA8ULL, 
            0xFA2511649D778739ULL, 0x8D1326064CCF9D91ULL, 0x8971A328E21F7F94ULL, 0x17781F4E953D5D51ULL
        },
        {
            0xB34973E127D05CDFULL, 0xDFD872BA1429509AULL, 0xEB9E7CCA4923AA92ULL, 0xF3C5D822BF41183DULL, 
            0x6252F7A3E6173E1AULL, 0x7F26F2A6F7AA785DULL, 0x2BC41F0E4847AF54ULL, 0x6FDE3C64F3760026ULL, 
            0x5B8D7E805B2C9559ULL, 0x46CAD77A3F944CA2ULL, 0xA15D1FB4AA9E36A3ULL, 0x57463FC225C8122CULL, 
            0x54E4BDDDBEF2B491ULL, 0x431092E06577DA67ULL, 0xE0AA3F720C9394C2ULL, 0xBBCC6147348C5DB2ULL, 
            0x60E93B24163564FBULL, 0x8A6B1BFD46AABA57ULL, 0xE1C6C3209837F3C1ULL, 0xEBC5F9E3280B8991ULL, 
            0x7975714E8A8DB6AFULL, 0x98C901A9720537FDULL, 0xA5FF8FD847D20B63ULL, 0x0B8D747C9827D621ULL, 
            0x6C014F7F6A2296D5ULL, 0x96ED467018DE9009ULL, 0xE4D0EE196C0D7236ULL, 0x2926719D1E574804ULL, 
            0x65F38BBEBF9403D3ULL, 0x923BD5920696F0CDULL, 0xF724EE921125E33BULL, 0x3EB436655D11A8D0ULL
        },
        {
            0x616F0929C55A0EFEULL, 0x66CA627A8A5261A5ULL, 0x2A0247FF1E97F895ULL, 0x00D7D3B2CF45A313ULL, 
            0xF20A8C3A0FCE4D33ULL, 0xA0F8F461F745BD8BULL, 0xFE102394A7DB25BCULL, 0xA3142302DEFC60C4ULL, 
            0x3FE6D569E79AD317ULL, 0x534C2A8BD4DC87A4ULL, 0xC89A9EEBC6FA1947ULL, 0x4624873FD86795E3ULL, 
            0xB02DBE23750FB5E1ULL, 0xE87330C25A3443FDULL, 0x68384B59E6737099ULL, 0x7F288F167386A419ULL, 
            0x4C06DCDCCFC13DCDULL, 0x739465D80760E41AULL, 0xFC6586F474BA7710ULL, 0xE2B066A5D624F414ULL, 
            0x368634D9002D4225ULL, 0x34FDEECAA13A67F9ULL, 0xE30896E6E3807EDCULL, 0x0880D12F676D65BEULL, 
            0xC694172B684CC91AULL, 0x042410C2E4CAD6B5ULL, 0xBEE5E68943AFE42DULL, 0x4AB047D77D4BE3D5ULL, 
            0xECBAD6737B33CD9FULL, 0x05FE24E6AF76EADCULL, 0x9FCDFD66E100EC14ULL, 0x068846FC69813983ULL
        },
        {
            0x8F26B6ED9C965B3FULL, 0xF392B7456D53E425ULL, 0x3CBCF36C79367F56ULL, 0x94ED805C6E3F37AAULL, 
            0x988937D37FCFCE4CULL, 0x2CBFC2A219F416C3ULL, 0x990DADD37EECA76EULL, 0x3C2185FB552A5FEBULL, 
            0x612185F754C2BF58ULL, 0x9C636357226BD121ULL, 0x99A9588821B79BE1ULL, 0x3E1996713199CE15ULL, 
            0xFFA0E0B3DC7ADC6DULL, 0x97C38350A1C907C5ULL, 0x9FCDB69AFDEA1529ULL, 0x667B2B258B952A58ULL, 
            0x5D064C9F75B4016FULL, 0x23FE65D892FF72BDULL, 0x506A199DC998C0E9ULL, 0xA84C54D73E9A2251ULL, 
            0x8A25B8B53AB9617AULL, 0x2DB5CCB06DE916A3ULL, 0xB0F3390E497EBEF3ULL, 0xCCF06E34B61E961AULL, 
            0x614CC4DB05126551ULL, 0xB42FA98927A9209CULL, 0xD1758CDF4852C6EFULL, 0x09165A015347B792ULL, 
            0x4F2700FD0B514D0AULL, 0x56BAA6C0B0788A15ULL, 0x2E09BB13B46F761FULL, 0xB9380B31966B970FULL
        },
        {
            0xA6F00DA79459C6EBULL, 0x3193F632C893A042ULL, 0x82F1C77FD0988ACAULL, 0x8C5B4CE9655CADE0ULL, 
            0xABCC52148ED0096BULL, 0x05E133D9B3F68E6EULL, 0x2605E14DDECD4EBDULL, 0xCC148708872101CEULL, 
            0x69B166F29220BC1FULL, 0x669FA4B96790FF3EULL, 0x815D3468DFE161CDULL, 0xAD174E822E061A93ULL, 
            0x1594CEF6BA1BB74EULL, 0xF7935285262A6D16ULL, 0xC1DBBCE5ED633507ULL, 0xEF2A0F009E4EAFDDULL, 
            0xE38EE44A16489C9AULL, 0x23E9B2F47C43092CULL, 0x3D46E945CE200E26ULL, 0xA98DC7FB8E1D35DBULL, 
            0xD4427821B14CBA4BULL, 0x81D36C7D770C4EFDULL, 0x771E182D4E786175ULL, 0x8FF8DF613C8D4E03ULL, 
            0x19BA4FB7B737654FULL, 0x0EDC8331C9A70A3FULL, 0x8A3C89F470BF6037ULL, 0x1EB56A12C56B023CULL, 
            0x1B3BD034DEC1E850ULL, 0xEB9CC019682170D5ULL, 0x55F928A4ECE4F908ULL, 0xC824B86B8C211CE2ULL
        },
        {
            0xE2EC43D7096CE86BULL, 0x05FEEDC9DF706549ULL, 0xB5617AE72489D2B2ULL, 0x268AE21A8A37B995ULL, 
            0x0C8C63C9C2506CF0ULL, 0xFCFDA434D6D5C721ULL, 0xEE7B20C0134A515DULL, 0x1149A03F6E2794E1ULL, 
            0xC56D32B9AA5E0B15ULL, 0x53979C34CAECBCE7ULL, 0x95923025514DB42EULL, 0x2B0F06C61E17EA8DULL, 
            0xD87A7F3547E48781ULL, 0x23419EA17EFC919DULL, 0xF7485E2F7A460872ULL, 0xF19F77F630E2DDFFULL, 
            0x9DA4903381B52AFBULL, 0xF64404301E7A7761ULL, 0x8F1FDAEE50A6A06AULL, 0x14A189FA9F0EDB56ULL, 
            0xBF0FBAF86A5998E1ULL, 0x04FAB4892347E463ULL, 0xA955F7F1B496662AULL, 0xAB5FBF96341137FFULL, 
            0x801BFE4BDA93F6E1ULL, 0x49AF259C54D4CB87ULL, 0x477EBD89C0795A36ULL, 0x909872DEDCD088D5ULL, 
            0x7A605073D4FBC767ULL, 0x4748B287D3B787F5ULL, 0x53F6EA58C5CA1408ULL, 0xE8E9A785EF7F6C7DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseGConstants = {
    0xFC5B4608E009BC91ULL,
    0x89460F0009A88007ULL,
    0x37D2B9C5EE3C4B84ULL,
    0xFC5B4608E009BC91ULL,
    0x89460F0009A88007ULL,
    0x37D2B9C5EE3C4B84ULL,
    0xCC17D72CE7EFA7B9ULL,
    0x942BABD7DA41108BULL,
    0xB3,
    0xEF,
    0x2A,
    0xC9,
    0xDC,
    0x4C,
    0xD8,
    0x2B
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseHSalts = {
    {
        {
            0x006F2A0CB8555C21ULL, 0xDE4BE8A2C1497954ULL, 0xE4FCE05DE634CF12ULL, 0xD9EC3D84D01C399CULL, 
            0xBD11174E1EC900A2ULL, 0x424FA6BAEFE11FE5ULL, 0xF16C08C7DEBC0B02ULL, 0xC71AB7AC36B9FA7FULL, 
            0x81AC491E07650C21ULL, 0x9A7406C2DE0F8127ULL, 0xB995282F12BBB859ULL, 0x793A430E6FA78452ULL, 
            0x8778C3B43F38CF2BULL, 0x707102AEA49BFD54ULL, 0x89B7814E7C73FB1CULL, 0xFA81D3C78A5836F6ULL, 
            0x3E8C082ABD17E002ULL, 0xF259B58F08FBC3B7ULL, 0xE8EB5946F0A0E719ULL, 0x18E293A0891FBF68ULL, 
            0x2AFC4F4BAB9F742AULL, 0xC9BBC44063101998ULL, 0x55DFAFD715D6BE80ULL, 0xA41EB9202823EB72ULL, 
            0xA7B4452783C3CEF7ULL, 0xE94190B4FC03EC30ULL, 0xB34DB3157A04E39CULL, 0xCF7722C0A7F2C06FULL, 
            0x5F79BFB8085F9648ULL, 0xD8C1EEBA96891E7EULL, 0x67DB2CAD1BDDBCEDULL, 0xFA99742FC3654FB6ULL
        },
        {
            0x1720DF5FCE7112DEULL, 0xF151E6C03B985EEDULL, 0x2B50DE6E8B94109AULL, 0xC576133481F1E334ULL, 
            0x2F17B48D70CA3219ULL, 0x59ACD58A3816BE2BULL, 0x1B8DFA72B608BFF4ULL, 0xE686D92CF7B3CADAULL, 
            0x350AE38F5D4175C3ULL, 0x7CC4871AA3C1D8F6ULL, 0x328120A1E844E255ULL, 0x1D209CA9B2CD0C0EULL, 
            0x1ACAC2CDFB4E2676ULL, 0x0589BC897C89B7E2ULL, 0x4E71D9A29055FE14ULL, 0x0F7D4C11D453D70BULL, 
            0x31A59128D9CDEA9DULL, 0xBF289AF21DC042CCULL, 0x05D9BD692D97CD29ULL, 0xC5A41DAC8CA5D4F7ULL, 
            0x47B9D3587BC011B8ULL, 0x6CDC5A8B7FAEB315ULL, 0x5DBB42C6A48C804BULL, 0xC04EC0C926DBA990ULL, 
            0x452729FA346E06D6ULL, 0x147497916361E717ULL, 0x287C0489AC5C7CCFULL, 0x3DB6F1E8CB84027DULL, 
            0x3F1E4F3DD0639EA9ULL, 0x220D02A7C850F203ULL, 0x150C6F1C9432FC0FULL, 0x62F4C36E9E70BEB2ULL
        },
        {
            0x163CBF73112195FDULL, 0x28F3F3B68E240911ULL, 0x438103F07FC09640ULL, 0xE87C2FC2EA3DB6D1ULL, 
            0xFE603DEE5C6FD6F1ULL, 0xD6CEF5B6B6DBB1DCULL, 0x6C28D5E8CF98A219ULL, 0xE6B10535674A4D21ULL, 
            0x80427BA2ADD72837ULL, 0x362CEC513EF5FBD0ULL, 0x3353B128C25792C6ULL, 0xDB03E3A797568CC6ULL, 
            0x204217CC41A1C40FULL, 0x50A79ABEB5C98835ULL, 0xC144BBAC8284FCF9ULL, 0x54745BFFCCD7A8F7ULL, 
            0x690E57497E619EAFULL, 0x94B182E7C7519E1CULL, 0xC46FC8F46116408FULL, 0xDCB4EE71D9870DB2ULL, 
            0x15019328DEDA4FE5ULL, 0x54EEEA0CE6803956ULL, 0x4343371FA225B041ULL, 0x9AB268250584E300ULL, 
            0xE62E22F2FDEE7014ULL, 0xD7514EA0AB206A61ULL, 0xFCBF8DD18A229864ULL, 0x4450FBECCCCDF554ULL, 
            0xA0E6B729C17F8D4FULL, 0x1CCDB4790F012DC7ULL, 0x9FF5B51E32D333D9ULL, 0xCF1B2E9DFF7DF218ULL
        },
        {
            0xC08889D027FAEE04ULL, 0x3FC7A4E16B67BC65ULL, 0xC07CBDC0BD65DF71ULL, 0x0BC3DD6C000F159DULL, 
            0xCE9D1A69CE519ECEULL, 0x680A4FDEC7A5A64DULL, 0xCE405637376F8194ULL, 0xD11B81DA4A01E31FULL, 
            0xF3E2206996944192ULL, 0xC227521271D8DCC6ULL, 0xCD92E7D596696FA7ULL, 0xCE1E24EC78F5A725ULL, 
            0xD7B5AD3FFC8694DBULL, 0x761FEA7295DA1ED4ULL, 0xF7A541EC135562E7ULL, 0x0A0464E9E44A781FULL, 
            0x72F256D3D6323A69ULL, 0x24E8E669E6706D18ULL, 0xA3F93B0D751CD552ULL, 0xC69CE828166ACF67ULL, 
            0x65F0DDA7660C3AFCULL, 0x575BD802FE473785ULL, 0xCD20E41B9B8F2FF3ULL, 0xFB65465D32629468ULL, 
            0xE7D23650B6A28580ULL, 0xB0CE576D849BD2B5ULL, 0x9521566A69048896ULL, 0x86D9141AB3EAE8CAULL, 
            0x60692D05F46C7BEBULL, 0x9760B9E4446EC1DAULL, 0xF0180C63144B0974ULL, 0x5FCAE4B8C5B885CAULL
        },
        {
            0xDE998A035F29CD21ULL, 0xC002F92766949E82ULL, 0x1CD57BAEE021B32CULL, 0xB73B25B476E923B8ULL, 
            0x22D204A7E833EFA3ULL, 0xFF0015B8DD9266CDULL, 0xD9CAE1B471A9B0A3ULL, 0x316739B96D3083FFULL, 
            0xC8B3E445A9DADA3FULL, 0x81285A95D66DB98BULL, 0xFC92FBCC3B303081ULL, 0xBA4F181C1E7A198AULL, 
            0xE6CFF3B4A8F15ABDULL, 0x9317EA658C6AF27EULL, 0x96CE6AC3D19905D1ULL, 0xFBAAF34E6A75F6B6ULL, 
            0x778F0B6EF8C48E79ULL, 0x108466D3340D6FD6ULL, 0x1390947B52E60C7CULL, 0x21195DB42FA2DD43ULL, 
            0xC9F2045926B8A62FULL, 0xB3B747236C83D7EBULL, 0x9BCAB4E66DF0AC98ULL, 0xACD6EF9A3ACCE87DULL, 
            0x2A49B998D4A0F644ULL, 0xBA2D2DD594F2971CULL, 0x24C8DEFE464D9F85ULL, 0xEE66C1885F6A525EULL, 
            0xCD7D110C97A4B58CULL, 0x44D8683C0F10942AULL, 0xBD8A28A5379FC616ULL, 0x00DD710739ABDEB1ULL
        },
        {
            0x4BA0FA07F7745A9DULL, 0xA4AA1FB953858647ULL, 0x2D9D0DE04DD36081ULL, 0x8D484A30FCE01E45ULL, 
            0xA4774309BE087A24ULL, 0x1AA0B7B1F0745CB4ULL, 0x54852BF7BC41AF13ULL, 0x305A7D0FCD73E6A8ULL, 
            0x3EA5CD0366299970ULL, 0xF21F1CE9ED2E5AB3ULL, 0xE5E42EE7D8EB6EE5ULL, 0xB9085ABF09A502DFULL, 
            0x7D36D5740C21A6B2ULL, 0xF37EF7254BDA5363ULL, 0xA07C3154E471BFEDULL, 0x2E3C6D04E383191EULL, 
            0xAFB753F910A98AB1ULL, 0xF740C351F2B793EBULL, 0x1CED1B0D8F641A6DULL, 0xE064112FA17AAF4BULL, 
            0x400E6EEE923CF877ULL, 0xF5F5CD83AED5BF0AULL, 0x85DAE6D1FA0CC715ULL, 0x3CC870DE0D3487B0ULL, 
            0x4EC9A7C51AE9697DULL, 0xB909AD7805511A65ULL, 0x840A2900734C6EFAULL, 0xEC2D46564AD0B403ULL, 
            0x8BA6B8FC01049B92ULL, 0x7E7132A1B50F5CDBULL, 0x96CBB8839D698AF6ULL, 0x290DC9742670B69AULL
        }
    },
    {
        {
            0x8607C8596895808DULL, 0x0E9D16ADC9CB8EA0ULL, 0xDF841AFC7E791DF0ULL, 0x2C80109475A72615ULL, 
            0xCCE46B8371F03590ULL, 0x0393BED87419E6CDULL, 0xB7CE4A2DDAC68025ULL, 0xF83A15488929C99BULL, 
            0x2F33EC6D8C43CB44ULL, 0xB8E4AFE9C254B27DULL, 0x7AD96F833929EDB5ULL, 0x51B8D4BA198800AFULL, 
            0x28749E0EC3C84A0DULL, 0xCF1BE288803DBE44ULL, 0x1297F8200D544A53ULL, 0x9DC10B3242682D7EULL, 
            0x963A127A78264F41ULL, 0x1952ECDE593FE9F9ULL, 0x56A1446E9D6C6703ULL, 0x81C9E4E7C9082ED5ULL, 
            0x8939F8FFC01FA766ULL, 0x598EF54EF8A76D65ULL, 0x4CC6A92E2BB369CEULL, 0x7A8E4F6A85E00C7FULL, 
            0xFD88CC20D42CDD24ULL, 0xB0705B8DE6E1A0FEULL, 0xAEC230C24B1B7310ULL, 0xD8AE1E78B7E1252CULL, 
            0xA56BFA614A7214C4ULL, 0x9E020094CA0D5388ULL, 0xE7B2EC94B1EF1896ULL, 0x812F60E4D93D2BCAULL
        },
        {
            0xD00859A3C0FD2586ULL, 0x6175CBE7FD4E6A0AULL, 0x903D39EC227DB405ULL, 0xC8F8D2672104DC29ULL, 
            0xE890871BAFF1C696ULL, 0xEF3ED298612FEEC3ULL, 0x05C4CF0EE20731E8ULL, 0xDC726552A35591FDULL, 
            0xD47C6FBE06AC660EULL, 0x2915A587CC083BA0ULL, 0x579073DAAD522FC3ULL, 0xAFB90C6B6BEBABC3ULL, 
            0xC88E0A030B9B8CEAULL, 0x78AC00B771C2DEC3ULL, 0xA7CCAE75ED2957E4ULL, 0x849839E987FAF400ULL, 
            0x7447D2689606DD94ULL, 0x7021DCF588D73AC5ULL, 0x51EDDD4961455A91ULL, 0xFA2BB0A01056EFA8ULL, 
            0x1C2233FD04B15E71ULL, 0x199220625C13383EULL, 0x2AC990F891FBD5EDULL, 0xF530D44929D05935ULL, 
            0x3ED0EE1F0F2B0D55ULL, 0x16C79057CD0B0779ULL, 0x3C6409E8854FBF45ULL, 0xD7F8E38DA1E53FE1ULL, 
            0x12329B227C837447ULL, 0x6438226B0ABAB46BULL, 0x26B9F28EBE366250ULL, 0x255F9FC8EEEACEDCULL
        },
        {
            0x589302F8077484B0ULL, 0xF4FE22942CE8F53FULL, 0x7391576B1178E068ULL, 0xB4B4014EC9ADACFBULL, 
            0x2335E412C18C9867ULL, 0x9D0541E055A8F20FULL, 0x4CBC6FB98381C739ULL, 0x07DF37F327F6F9D4ULL, 
            0x7C372C2479C2F898ULL, 0x12DE0AD3C1CDD816ULL, 0xBB7D48510A5E0FFCULL, 0x82205B45BEA6A85EULL, 
            0x1791EF1D0AA0016CULL, 0xC89F8124790F6A1BULL, 0x92548893FC52D306ULL, 0x3423015EEAF130FBULL, 
            0xAA7CB2C4B4A8358DULL, 0x177BA93664963CD7ULL, 0x7CBBA2DF7BBEB40CULL, 0x7D3CC37414957907ULL, 
            0xA9C9EDDDF9299EC2ULL, 0x99029033A5881C24ULL, 0x098BB9342CF768ECULL, 0x7E7A1B570E3F04A2ULL, 
            0xCB1B5C522988ABB3ULL, 0x638F24847DA6168CULL, 0x9E425A82BCC06418ULL, 0xD2316B08CBA0161EULL, 
            0x9C085516A5B09A4AULL, 0x0A3C51226D2683A1ULL, 0xD639F045FB70D2ACULL, 0x495D2B738F6EADDCULL
        },
        {
            0x5A26BC9B2D16841CULL, 0x66E642B375B591C1ULL, 0x34F08DF0B00C2725ULL, 0xC38B393E7260CA0EULL, 
            0xB5F3AF9B3E811C0BULL, 0xAE70C8C5918E61C3ULL, 0xCCBEC10E5A523214ULL, 0x7EAD60C3BD3DB93CULL, 
            0x1152008DA7DF3030ULL, 0x1A58332D8AD7C83DULL, 0xB6E12E180CAB2B6CULL, 0xD5EAA29A765CAEBFULL, 
            0x1566489D58FBAA19ULL, 0x60143EF2D3AE7E82ULL, 0x2BD4F9E880BB327CULL, 0x004B7C4B96EE66EEULL, 
            0x4CB5CC30102F5BCDULL, 0x684D33CBA3AD9DF3ULL, 0x119EEB9C2428C85DULL, 0x15DA1F990D8BEA88ULL, 
            0x7F9A86B5D14418C6ULL, 0xC5679EB33AD2914CULL, 0xC147F6C18C402410ULL, 0xB24CF8EC08E3B4A8ULL, 
            0x9CE9CEB69DDE49EFULL, 0xE004157F622EF116ULL, 0x4DAF356D1A3A4E4AULL, 0x7BA7B5CC436D6FFAULL, 
            0x5F3DAF8F39A6603CULL, 0x580D832A2D890D0FULL, 0x597702956C59EE5FULL, 0x1151FFD973078582ULL
        },
        {
            0x12E254CF32242350ULL, 0x7B216A9479501F4FULL, 0x8E1FBD21B43306B8ULL, 0x25A06304D3E41913ULL, 
            0x1C18B2662F9D5F77ULL, 0x8867F417B4EDC6B2ULL, 0xC29281754DE5432FULL, 0xC2CA9D337F841B16ULL, 
            0x8CC8EDCB9A433182ULL, 0x974298DF01130E56ULL, 0xB1F80AD38B2B64CFULL, 0x733DC6E38671EC9DULL, 
            0xD1A286D3434A75FFULL, 0x099254009C13B500ULL, 0xE4CFEA1FEACF7577ULL, 0x8A7CB0EA6DFAA726ULL, 
            0x33D036E1A60F6613ULL, 0x483F99820D05AF32ULL, 0x911D795A1897650EULL, 0xCE1854F4973CF542ULL, 
            0xF6C2ED2943A45F3FULL, 0xEE1F02CEAE1B3F66ULL, 0x5C28DA6F4ADEEFE1ULL, 0x13DA27E4D77CF439ULL, 
            0x08AB9B83405700C9ULL, 0x9CA699A313A8FC9EULL, 0x6F1E0D7C96E328E6ULL, 0xA1B66F002D6127C8ULL, 
            0x8D487B807D43F5D1ULL, 0x8143FB898E81BA55ULL, 0x952A55C550929684ULL, 0xC64D47D12DB91981ULL
        },
        {
            0xF73D8B225D17B9AEULL, 0xEBB1671EDD932FF8ULL, 0xA903366885C82A87ULL, 0xFE954C4981B3CA9DULL, 
            0xB84306E1F7FE8CD1ULL, 0x5EC04EF06E326AAAULL, 0x26AC44CAD2037B6CULL, 0xBCE2512003E3066EULL, 
            0xDAC57AF102B0B22BULL, 0xA0BB62A0CEA5F083ULL, 0xCEB51D2129EE73DAULL, 0x84914ECA2A8F6809ULL, 
            0x0D2BC5600CB2F28DULL, 0x24ED149B773555FBULL, 0x7A5CA0A2175A126AULL, 0x17C941EBF1F53D83ULL, 
            0x3BF60AF3FB4F5E84ULL, 0x1B7042113B67DB81ULL, 0x49C2E3977C9CB151ULL, 0xD8AC596CF692A80FULL, 
            0x05DECB742CEB044BULL, 0x5BA9E8DEF8962413ULL, 0x00E03A9F93A1F544ULL, 0xBC8A04D76C8BD0C0ULL, 
            0xBD7E06929525D05BULL, 0x872205FFF733BFC8ULL, 0xF62490D40ECF8F49ULL, 0x3CE5F7E3A1570ABFULL, 
            0x4F126FDA6D9F2CCAULL, 0xB2964B8EED0802E9ULL, 0x209B0C2FCCD1840FULL, 0xDB84EA0A10F420D1ULL
        }
    },
    {
        {
            0xFAA5C7D978B7B8D9ULL, 0x6EDC16FBAF009625ULL, 0xBFD182AEC28D0905ULL, 0x6250EA721457CB0DULL, 
            0x6D34754F3F24203BULL, 0xF59F79DEBD9BD64CULL, 0xCDB71D06A66606DFULL, 0xB97564DFB1FEBAFEULL, 
            0xD1647E455F39ECB9ULL, 0x71B35511F6EEB6F9ULL, 0xA255784AE7E9CF8EULL, 0xBCE565F872B58852ULL, 
            0x18F2E88ADB97D563ULL, 0xD21C7C37213DF192ULL, 0xF8E916CA217D3AB3ULL, 0x0E934EBBE24971CFULL, 
            0x0441D9033E66E2FDULL, 0x64893B16BDC0EAA0ULL, 0x57529877B2D8C199ULL, 0xA293305F8B14C794ULL, 
            0x717C2AA6690F96FAULL, 0x5237D5D591E0C1C9ULL, 0x2A6BEF42D8EAEE7FULL, 0x8AD815EE7205955EULL, 
            0x4B2A84C145212A68ULL, 0xFC52D5566EA30AD6ULL, 0x5812E3472D838448ULL, 0x5A93C684885813D4ULL, 
            0x07BB4C92444296ADULL, 0x668A1EF8C9B05032ULL, 0x41E82CF996E733BAULL, 0x27B60EBD03E152D9ULL
        },
        {
            0x460BE383569246D3ULL, 0xE6F98B4AC94EC0DBULL, 0x7327D13F09F3F676ULL, 0x670F4FE8108B24AFULL, 
            0x4FF35DAF75DE5728ULL, 0xBCCB4E0433C56264ULL, 0xC18469690F8E0394ULL, 0x802DCF507E7A6DE9ULL, 
            0x8AC2097E1F1EADFCULL, 0x9D397C205762FCD6ULL, 0x0C346DFD95EB87D2ULL, 0xF02F4F7C62B1A48AULL, 
            0xF06CECC267E4691FULL, 0x050A1FF4355ADDD2ULL, 0x78C8A8312F6E1FF3ULL, 0x796C84B367D8BE35ULL, 
            0xD427B3B4DB500FCEULL, 0xDC6A5FDDF10DDC79ULL, 0x4325B02B795B1558ULL, 0xE3DD5A05D8BDDB54ULL, 
            0xF7F0F5ED40105D3EULL, 0x0A8DF43A9075267EULL, 0x9FF5BE843A825C83ULL, 0x0B42031F7A3526B7ULL, 
            0x5AC32F10F8B11EEFULL, 0xB50F994EFE28600DULL, 0x17B159300A937015ULL, 0xEA742BEB6E563B0CULL, 
            0xEB487BE3620322CDULL, 0x2B905F4E4084FA86ULL, 0x15CD81F2EAF9B7A0ULL, 0xD0017DBD6C49B612ULL
        },
        {
            0x607B932AEFB9711EULL, 0xAA6EA6421A357191ULL, 0x1E2802AD3B4DA0C4ULL, 0x5DFBC37821145EF0ULL, 
            0x7A80F010AF83E2EAULL, 0x4428FDFFD2809DDBULL, 0x29A089CF009C7601ULL, 0x8B76CF88495AA4FCULL, 
            0xEBD39E87995E83A4ULL, 0x6DE3E21CEA714A39ULL, 0xFF6A303C5B99FFEFULL, 0xD97BA2F3CBD15C94ULL, 
            0x2226A3B5015323A9ULL, 0xE1EBF9E7E528B78CULL, 0x08E268F106426AA3ULL, 0x81A9285E52816860ULL, 
            0xC813CF94D55076D7ULL, 0xF5D5D609324BD524ULL, 0x7B6BB90CE76BC428ULL, 0x761F1CD13AD6780FULL, 
            0xADF5548D680373EBULL, 0xE5A6307325870199ULL, 0xBE0EEDE4419C4962ULL, 0xAD91C2A57F3765C1ULL, 
            0x08DA7ADC4C3C6C2CULL, 0x541ECDD51879B5CDULL, 0xEF6D282D680AF2C3ULL, 0x870B03C14F346C7BULL, 
            0x6B276E07A38C5CA1ULL, 0x4652FC2E42F322C9ULL, 0xD52B5817570E870DULL, 0xB190EC82A3F2D8B4ULL
        },
        {
            0x037DF15B958940A3ULL, 0x27CE1F14BF07C225ULL, 0xFE0F82D495638705ULL, 0x5A6493165F610A9FULL, 
            0xF5B18F592A0C0852ULL, 0x74684DA602CA8B33ULL, 0xBE3F64CD74ECEA75ULL, 0xEC7E3C9699681FB4ULL, 
            0x41407C6FDFEDAE35ULL, 0x1441D0A27993B72BULL, 0x7D267E18223B4330ULL, 0xCAAA6A304E6AAF20ULL, 
            0x415726997A397794ULL, 0xEE939AC00909F466ULL, 0xD360BB3908758B6DULL, 0xE1A2D50826E048D0ULL, 
            0xC3A0EEA91E4DBE13ULL, 0x3DADEE1ECD4F6D60ULL, 0xF1D23A3C7959A646ULL, 0x9C818BFDFA6FF644ULL, 
            0x0B4202DE08ABCA19ULL, 0xC9F8AC818CF0B104ULL, 0xF8121288745423EEULL, 0xD30C7144C59E1B54ULL, 
            0x262BB0DA922CA4C1ULL, 0xBA2398C2AD63DCA1ULL, 0x7BC54F40CC9BBA85ULL, 0x24A9ED13F1E29715ULL, 
            0x84A63EC2EDCD5860ULL, 0x03D077D13FDE952EULL, 0x8D068DBE299F12B2ULL, 0x37BBBD491CB585DDULL
        },
        {
            0xBCB3F2397AE37F0FULL, 0xC0FC723C56BBF285ULL, 0x4478EAF69F9C7E4AULL, 0x4833DBAEACF5B100ULL, 
            0xC188049032F1FF43ULL, 0x9611FD321091C08FULL, 0x5A81CBD2E04D285BULL, 0x871B09F8BC7D89E0ULL, 
            0x7AD534A91B2A60A5ULL, 0x2D89C23DAFD27401ULL, 0xF66B3F5F66C28BD8ULL, 0x5BE10ACE1E3452CBULL, 
            0x8237C7459E57DD48ULL, 0x4218707FCAA82904ULL, 0x18CDBCC06A4EEBD4ULL, 0x6D3FB31F462551DAULL, 
            0x86A5780A6BB7D098ULL, 0xDD654A164113A3D5ULL, 0x78BF65B53734696BULL, 0xF72993F05D041030ULL, 
            0x478B5366919AEFD7ULL, 0x2E952A93E8B1CBB6ULL, 0x4C1B7DDAB46FDF2DULL, 0xB911C56A1A77051CULL, 
            0x217216B0A2DCFAD0ULL, 0xE042EB96F52E198AULL, 0x90271ADCCA05E8A3ULL, 0x8B5C44DD4524ADE1ULL, 
            0x6AEB880F4A186EDEULL, 0x3DC6357258CC5AFDULL, 0x99DFACCDE8AF2535ULL, 0x0BCAF7D8A595F214ULL
        },
        {
            0x1909EA030406B5E0ULL, 0x77E6EAE1E1312193ULL, 0xD4340177BEA1AEF0ULL, 0x0317C70606C7E3E9ULL, 
            0x44C5FA9330EF77FAULL, 0x0933F8A5663EDE3FULL, 0x093A39ADA81B5C7FULL, 0x44A178B94BA69E94ULL, 
            0xB29E4913E6E6029AULL, 0x83B849584290ED3DULL, 0x3AAE1CD5EB3E7CB3ULL, 0xFC05F6CB79100F4DULL, 
            0xD4EABF76D790DA3FULL, 0x7D89AD1B11F3E907ULL, 0xE37032AF5B186EF8ULL, 0x7679F346EAE0A170ULL, 
            0xAFA16FB1C38D7BF8ULL, 0xC894CC2A107FE198ULL, 0x9D764C632D8A5E85ULL, 0x09C94675B674FBCAULL, 
            0xC010225356925E35ULL, 0x64857EEB8A31656BULL, 0x6CAB0B29D81B7C22ULL, 0x35347688426C42C6ULL, 
            0x00C3621F9DD73A8AULL, 0x67DF3AF7C105FADCULL, 0xC1050C2C54ED224CULL, 0xD86B367F290BC200ULL, 
            0x69BBBC0652985C54ULL, 0x66B082718FA0CFABULL, 0x77015B88815A021BULL, 0x22220C72E34D161AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseHConstants = {
    0x45CC87D2DC65DBFFULL,
    0x758FCD47ABF0FFADULL,
    0x8E4877A6D6E9D534ULL,
    0x45CC87D2DC65DBFFULL,
    0x758FCD47ABF0FFADULL,
    0x8E4877A6D6E9D534ULL,
    0x2B11645B26C01DC1ULL,
    0xF4118775488EF019ULL,
    0x1E,
    0x3F,
    0x48,
    0xD7,
    0x22,
    0x9E,
    0x3E,
    0xA1
};

