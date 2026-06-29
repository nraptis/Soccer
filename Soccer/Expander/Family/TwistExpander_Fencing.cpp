#include "TwistExpander_Fencing.hpp"
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

TwistExpander_Fencing::TwistExpander_Fencing()
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

void TwistExpander_Fencing::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xB38FBBDAB0B607E5ULL; std::uint64_t aIngress = 0x91C5AB0AD918A87CULL; std::uint64_t aCarry = 0xA0B87BBF0E527EB4ULL;

    std::uint64_t aWandererA = 0xD3F04ABAD4EA2476ULL; std::uint64_t aWandererB = 0xCEE662E64322214AULL; std::uint64_t aWandererC = 0xF94BE1AABA56FA4BULL; std::uint64_t aWandererD = 0xE1FA2BC2CFE8397EULL;
    std::uint64_t aWandererE = 0xFBEB9DA8C9F8D0ACULL; std::uint64_t aWandererF = 0x85513F0744B862F9ULL; std::uint64_t aWandererG = 0xCF87F800007640B1ULL; std::uint64_t aWandererH = 0x92310D775AC1A2B7ULL;
    std::uint64_t aWandererI = 0xAAAF31F8E83B4D84ULL; std::uint64_t aWandererJ = 0xE9E4101206DFFBA2ULL; std::uint64_t aWandererK = 0xC9752AB3CFFFD956ULL;

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
        aPrevious = 14862752082063188629U;
        aCarry = 12936508728108190084U;
        aWandererA = 11659562603448475188U;
        aWandererB = 14042318550614451507U;
        aWandererC = 18350306955746630534U;
        aWandererD = 12648343433826758838U;
        aWandererE = 9308052089553598101U;
        aWandererF = 14516679731247126243U;
        aWandererG = 9377656935845580191U;
        aWandererH = 12140509127884412119U;
        aWandererI = 12240479662090268798U;
        aWandererJ = 12487800511214691427U;
        aWandererK = 12030902476941626312U;
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
    TwistExpander_Fencing_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Fencing::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xA3248B5CD2ED29ECULL; std::uint64_t aIngress = 0x9780D0C4C120F88DULL; std::uint64_t aCarry = 0x874DAAF2BA972961ULL;

    std::uint64_t aWandererA = 0xB0011B19D8D98450ULL; std::uint64_t aWandererB = 0xD6BD3FBFACEE46D1ULL; std::uint64_t aWandererC = 0xB7324193144B7D3EULL; std::uint64_t aWandererD = 0x86C7D6D6AD0F241BULL;
    std::uint64_t aWandererE = 0xB5C1A8E992A6105CULL; std::uint64_t aWandererF = 0xEA63799CFF149D34ULL; std::uint64_t aWandererG = 0x9B4CC165D609FE0DULL; std::uint64_t aWandererH = 0x9B60359E224A3F6AULL;
    std::uint64_t aWandererI = 0xB76C34AE49A3A205ULL; std::uint64_t aWandererJ = 0x9E80C3521C0C529EULL; std::uint64_t aWandererK = 0xE8DDEE738EEB5DC2ULL;

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
        aPrevious = 13135176752601921830U;
        aCarry = 13577317721866411519U;
        aWandererA = 13331689183652482427U;
        aWandererB = 15562205209929440152U;
        aWandererC = 14474171183882273963U;
        aWandererD = 11778729417367224986U;
        aWandererE = 12016794857052040280U;
        aWandererF = 14819876827021373872U;
        aWandererG = 18287310019323263423U;
        aWandererH = 17452804588851548483U;
        aWandererI = 17072559458090996052U;
        aWandererJ = 16601214589734155569U;
        aWandererK = 13122626969038046446U;
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
    TwistExpander_Fencing_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Fencing::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBCDFCB6334E70502ULL;
    std::uint64_t aIngress = 0xFD678E5D48D4FCA1ULL;
    std::uint64_t aCarry = 0xCB37D4B5CD579D7AULL;

    std::uint64_t aWandererA = 0xA12F0FEFA7B0AB3EULL;
    std::uint64_t aWandererB = 0xC0D458409F8297B5ULL;
    std::uint64_t aWandererC = 0x8890FF263AE806F2ULL;
    std::uint64_t aWandererD = 0xFD457285996DA91AULL;
    std::uint64_t aWandererE = 0xF094F21CEA43C4DEULL;
    std::uint64_t aWandererF = 0xCEDBBDDA6B57C60CULL;
    std::uint64_t aWandererG = 0x9E3BF365C09D2727ULL;
    std::uint64_t aWandererH = 0xB088C35037035065ULL;
    std::uint64_t aWandererI = 0xE904E103C8A9AE0CULL;
    std::uint64_t aWandererJ = 0xA563232EDE6D0F4DULL;
    std::uint64_t aWandererK = 0x8AC5E6755965B647ULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC, 0);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneD);
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA, 3);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB, 5);
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
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD, 6);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneH);
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
    TwistExpander_Fencing_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Fencing_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Fencing::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Fencing::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBA0F430EAF4C9B78ULL; std::uint64_t aIngress = 0x8F35DF1670AB3D2EULL; std::uint64_t aCarry = 0xF9F9410E7C2B22FCULL;

    std::uint64_t aWandererA = 0x9C7C8EC8174D657EULL; std::uint64_t aWandererB = 0x95218432531D669BULL; std::uint64_t aWandererC = 0xCB6B55941D819CEBULL; std::uint64_t aWandererD = 0x85CE4E0D261C33ADULL;
    std::uint64_t aWandererE = 0xD921168E07A2D086ULL; std::uint64_t aWandererF = 0x9972F4BDF933645AULL; std::uint64_t aWandererG = 0xE4B37200CC03C8E4ULL; std::uint64_t aWandererH = 0x9A9F5A4A59426BC1ULL;
    std::uint64_t aWandererI = 0x9D477C1725873540ULL; std::uint64_t aWandererJ = 0xD1C2C9B0289997CEULL; std::uint64_t aWandererK = 0xB859E9456AD831F2ULL;

    // [seed]
    {
        aPrevious = 18104175359586158664U;
        aCarry = 9978559973217412305U;
        aWandererA = 11911126144495825624U;
        aWandererB = 12307640454577172553U;
        aWandererC = 16793379422576731663U;
        aWandererD = 15959582866975419792U;
        aWandererE = 9590470437230324380U;
        aWandererF = 14340386360774625583U;
        aWandererG = 11805290508464771360U;
        aWandererH = 13862948742041490616U;
        aWandererI = 15964238289045860899U;
        aWandererJ = 12931883181392572877U;
        aWandererK = 15008179205029828615U;
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
    TwistExpander_Fencing_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Fencing_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Fencing_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Fencing::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 3, 0 with offsets 6027U, 3823U, 5214U, 1236U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6027U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3823U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5214U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1236U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 2, 3 with offsets 4842U, 7263U, 396U, 5653U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4842U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7263U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 396U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5653U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 1, 2 with offsets 3628U, 593U, 779U, 3928U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3628U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 593U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 779U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3928U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 0, 1 with offsets 3314U, 5069U, 7249U, 2790U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3314U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5069U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2790U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 0, 1 with offsets 2008U, 1674U, 1786U, 823U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2008U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1674U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1786U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 823U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 1, 0, 2 with offsets 777U, 15U, 456U, 618U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 777U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 15U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 456U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 618U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 0, 1, 2 with offsets 756U, 957U, 1340U, 1509U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 756U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 957U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1340U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1509U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 1, 0, 3 with offsets 5U, 748U, 2027U, 13U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 748U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2027U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 13U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1861U, 1276U, 560U, 1475U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1861U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1276U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 560U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1475U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Fencing::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 2, 3 with offsets 4686U, 7242U, 1803U, 6223U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4686U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7242U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1803U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6223U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 0, 0 with offsets 2257U, 7072U, 5941U, 6571U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2257U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7072U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5941U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6571U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 1 with offsets 6049U, 4434U, 6392U, 589U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6049U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4434U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6392U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 589U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 1, 2 with offsets 4044U, 1176U, 1196U, 7437U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4044U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1176U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1196U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7437U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5485U, 6985U, 6706U, 3152U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5485U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6985U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6706U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3152U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1180U, 1671U, 1528U, 1102U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1180U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1671U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1528U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1102U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 2017U, 377U, 1432U, 799U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 2017U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 377U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1432U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 799U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 463U, 932U, 1513U, 1565U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 463U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 932U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1513U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1565U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1508U, 1425U, 769U, 828U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1508U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1425U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 769U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 828U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 [0..<W_KEY]
        // offsets: 1158U, 201U, 1969U, 1824U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1158U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 201U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1969U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1824U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseASalts = {
    {
        {
            0x516EA098ED1EB88CULL, 0x5A04DAB6384FAF9BULL, 0x54B43F25A4A3C579ULL, 0x1DD7BF144F85A90AULL, 
            0x45AF78881DF4A317ULL, 0xCC8C684A20D96364ULL, 0x4E93A7F5A40AD128ULL, 0x8234F06EAACB36BDULL, 
            0xA2AF9B1A53B6CCB7ULL, 0xC4CD09F5E9786DDDULL, 0xF442B9B711FD4460ULL, 0x1C6BC0A442DBACCFULL, 
            0x05E03DF4F457ECC8ULL, 0x63BAD0C333B8DB71ULL, 0x2C877066E62AAC25ULL, 0xEE009F6D9F9C7274ULL, 
            0xE9603A5A8D0A03E3ULL, 0xE5A1AEECADB43CC0ULL, 0x838E1CE1F26752BAULL, 0x8CF76DB27CAE3799ULL, 
            0x86C4C8F0D55AF0D7ULL, 0xD58B2ACAAF55CAD8ULL, 0x8DFDDD7A95389B5EULL, 0x981167FB8CB91846ULL, 
            0x3FCFA4ED09538340ULL, 0x0CB7992A14703C43ULL, 0x2180042CB949A0E9ULL, 0xF0F6DEE953A34286ULL, 
            0xC017BDFBE97A104EULL, 0xE5D7FDF568D85B46ULL, 0x4C9CDE063EDA58C2ULL, 0x657CB035AD37EF1EULL
        },
        {
            0x5212CE43A462D5BDULL, 0x02648995AB7540CCULL, 0xEC5D377B07D9A9ACULL, 0x8C308473D8B7DC93ULL, 
            0xBBBA5743C34EF9F9ULL, 0xB92971CBE474A09AULL, 0x046F30E27705D7C0ULL, 0xCDE409B84CEC63B3ULL, 
            0x4E076577E18DB43FULL, 0x52C0585C650D79D8ULL, 0x0C2D07377B182433ULL, 0x0C75D45C14E91ED7ULL, 
            0xD5CCBC81074E98DCULL, 0xEECDC30994D5C1EEULL, 0x5E3F96AB9005E9D3ULL, 0x8ED606A9A82A18E8ULL, 
            0x043BD84126FE842CULL, 0x10B43D06BCF3A857ULL, 0x62F02B1171FAD8A2ULL, 0x4AAE922F0F48B83DULL, 
            0x2672A01C52EEFBBDULL, 0x451455C1FC8DF4EDULL, 0x87AE974112ECC9A6ULL, 0x102978C47521CBF9ULL, 
            0x31688FF5B5336FEFULL, 0xA730310D894B06A0ULL, 0x44423DEA4B1BFAE9ULL, 0x0A12B15F13431139ULL, 
            0x5681453C42DE5356ULL, 0x171D992B7C185ACEULL, 0xF085581CDD52C378ULL, 0xDD0646AECE97FBDEULL
        },
        {
            0xF4E9A002E93B4F28ULL, 0x897DCDAE634F40CEULL, 0x4E27AA31B15F9F7BULL, 0x61E663CD2DE88CC3ULL, 
            0x434DE622B2A11D05ULL, 0xF4C8AABFAD2F8A7FULL, 0x53EC60B483E4C44CULL, 0xA0C96DFB103841BBULL, 
            0x45A104306F5DD81EULL, 0xD029430BEC739DF0ULL, 0xDCF23A35051A72A7ULL, 0x612574EFA1F21AF8ULL, 
            0xFC1191058F4A1EBCULL, 0xE16B8EBE77171672ULL, 0xFAAF493B2F173057ULL, 0x349BD6B84D63364FULL, 
            0x87784569D4B0D2C6ULL, 0x0D6D087F69CE6785ULL, 0xC16351FDC86F5A0FULL, 0x959FBA3497E19CBEULL, 
            0x6845350C067805E9ULL, 0x46258E38627E2D81ULL, 0x8AA797AF7E257BDBULL, 0x1DDC65960AB12146ULL, 
            0x4E2BA1DCF3CFC5BAULL, 0xBAEBEBB6BAB1D483ULL, 0x2B252EC866B3CD7CULL, 0x81E12FC19898A8C7ULL, 
            0x7B8CF0B816509DF5ULL, 0xAB500E5CB69EC7C6ULL, 0xD9AEB89A337C4358ULL, 0x8CA658497CCD2DCBULL
        },
        {
            0x46006576222141DEULL, 0xD31DEDEDF7C99AEAULL, 0x63B9E3F3E6AE0321ULL, 0xF9FA3287D3EEF974ULL, 
            0xE55B748D542A23B7ULL, 0x2727CF36493078E8ULL, 0x36E52D324928C1BCULL, 0xCE6CB4DBAABDB04BULL, 
            0x7A1A7B55032BF5F0ULL, 0xE34F2F89D4354068ULL, 0x67C1D628643B838AULL, 0x30D29C72058CF74AULL, 
            0x31B60CD2353F9E7BULL, 0x1BAB9B9F0EE46ED3ULL, 0x3C186520A5FFAD6FULL, 0x21A712F0F5BFFFFEULL, 
            0xDC10A65C8A2E2D37ULL, 0xD0AAAEAA4A095A46ULL, 0x660F0413202BEE22ULL, 0x89435BB036A02514ULL, 
            0x27BA0F21F1303066ULL, 0x23518E32D0093A4FULL, 0x0E0B6EDD65A5C840ULL, 0x178417DB4FFC1942ULL, 
            0x0E4CF089719DC96FULL, 0x1448AF84BF4E74BAULL, 0x1D86587A8F935BFFULL, 0xDC3E4A8FF856CA3DULL, 
            0x05B03F921E83B1A6ULL, 0x19974218E570EA8EULL, 0xCF03426BD5D4DCCAULL, 0xE788B54C6B5E1DE5ULL
        },
        {
            0x2E2D555E4D95AEFAULL, 0xD54343AE018A6C96ULL, 0x3BC27E1E7BD8A5A9ULL, 0x118591485430F82CULL, 
            0x2C37F1A218CC7D8DULL, 0xFA6CA2385B86BE44ULL, 0x8009CF28A522C87AULL, 0xBBB2F73FE0316F6CULL, 
            0xA98D86773ED93957ULL, 0xCE40B42DD1E4E41BULL, 0x9B04418B16293854ULL, 0xD0B6589E27B83742ULL, 
            0xEEE599935141C1DEULL, 0x76F1F9A167B071F6ULL, 0x15BD06A6E1AD0AAFULL, 0xB8A35F9F5C4B392FULL, 
            0xDB0A32312208131BULL, 0x78EC04BFE572EC73ULL, 0xDA71AAECB01F5AF3ULL, 0x7DAF7294FE0A2DCEULL, 
            0x48916B8D9259BAC5ULL, 0xFF4AB3D5D3BBD160ULL, 0xFADA2500C8349A61ULL, 0x5CF5DE1F3F5F3C45ULL, 
            0xB5632555045BDF05ULL, 0x1DD97F1D35D5438EULL, 0x1E8CB4583DCA06EAULL, 0xC63055512365E24AULL, 
            0x5448FAD11C5A5EE9ULL, 0xE6382DCDCFAB6A9AULL, 0x0D4169E7BFB6D3F8ULL, 0xE262453B80A1F3BBULL
        },
        {
            0x33065232EE8CAD45ULL, 0xF1695FE09A860B1BULL, 0x974297D8A5F9566AULL, 0x092C361739B2DE97ULL, 
            0x7B17A5E0219A6968ULL, 0xAA9B7F977E74FC3EULL, 0x2EEBA4334A977FDFULL, 0x4911CBD557531B59ULL, 
            0xAA3266CC2E3322B6ULL, 0xB3761229522D95D4ULL, 0x5583607524860B93ULL, 0xB4F32C0E6A4E0DC7ULL, 
            0x12384B72241A5C67ULL, 0xEB0B42F2E4C22DCDULL, 0x80C4EA270A700C74ULL, 0xCD334765437DC00FULL, 
            0x0B7D732DF9471D68ULL, 0x3B6DBCB250EB3A90ULL, 0x687AB11BB9E51D0AULL, 0x0FF6A38875A1D50EULL, 
            0x7B1E105A7A873F27ULL, 0x4BFD73D84C285703ULL, 0x8440B01FED2DFDD3ULL, 0x2FD7637D8E2D94ADULL, 
            0x08DA0DE9E5775D37ULL, 0xA6EF2CEADB882E1FULL, 0xA0896A1092C4F3F0ULL, 0x8FF52D76878C5FFBULL, 
            0xCA7FA14A4779B4DAULL, 0x364F8412842176C6ULL, 0x1A8478E1EE1A7D6BULL, 0xD42C26AB45EAB5A4ULL
        }
    },
    {
        {
            0x8AD0887DD6EBEDE7ULL, 0x542C83D551029A1DULL, 0x74805D39338B74EEULL, 0x072038600BAE1FB6ULL, 
            0xD9E72630B6A470ADULL, 0x06F7B52E13951C49ULL, 0x656CA9C679570DF9ULL, 0xC55C9EBBCCC70D81ULL, 
            0x88F64F24354B90E3ULL, 0x924DBEA41260F0E0ULL, 0xCAD844D961135D55ULL, 0x6E5B60A8C3013114ULL, 
            0x77F98B1F90B14335ULL, 0x00F1921E868746FEULL, 0x121FDDE0710B8067ULL, 0x6F04687D0D6169D8ULL, 
            0x5AE8AD9288228909ULL, 0xF6C6B6E5671CC069ULL, 0xD724FE504B2DCA87ULL, 0xD63B422528DCFBE9ULL, 
            0x627AE4886E85975FULL, 0x39763F14B85F2D4DULL, 0x64E70DDBD3311F08ULL, 0x84A163FF303CA14AULL, 
            0x10694C07ADCA7B8BULL, 0x0680ACF5D5E48DC4ULL, 0xE0AF563F25B6DE30ULL, 0xD55B27DE2CDDBBB4ULL, 
            0x5286BC8C63751D80ULL, 0xD9C93787ACD60F1AULL, 0x9BA297B26FC8F88AULL, 0xEB2156ED88A2290DULL
        },
        {
            0x686297BEAB06B4A5ULL, 0x0E82494643BDD337ULL, 0xB5E03CB7461BCD1AULL, 0x280C7909CB2E90F7ULL, 
            0xCD2453765D57F1DFULL, 0x707FA9CCDA821B7CULL, 0xDC9E0B82A94F069EULL, 0xEE523D1F4860BB6FULL, 
            0xBB09A58EA55644D9ULL, 0x4C5710255C1B0176ULL, 0x1CD8A250CC04BC12ULL, 0x01FFE0E2FD48AABCULL, 
            0x2B929D5D90ED912DULL, 0x70DE7BCC7C3D2148ULL, 0xEDA3C8AC0710C711ULL, 0x3D696B29420CADE9ULL, 
            0x94AE5F60EEC8D19BULL, 0xDFD15DD66416A011ULL, 0xEC8B7AA5C4B4D094ULL, 0xE3B1C5F0573E00B5ULL, 
            0x27A87A3DC9C4FC5DULL, 0x6F70710657B8D3A3ULL, 0xFE73FCE1F02F5461ULL, 0x18071CD8C741C56CULL, 
            0xCAB0317CF52F5BC0ULL, 0x6E2374D74C60C816ULL, 0x2BA9DA3939640632ULL, 0xCC803951CE8C9444ULL, 
            0x01F06DB44177FF62ULL, 0x7C4A236B1ACCACEAULL, 0x9A1E424E52EE9AF6ULL, 0x3D7D08AAFC34A00BULL
        },
        {
            0x3F2BD63D38ED9B75ULL, 0x7B890B6ED006E5EDULL, 0xAD718EA34DA74BBCULL, 0x7D6AECD1D91751E3ULL, 
            0xA5B65FEE2845C803ULL, 0x8FA6EEC02AB98653ULL, 0x1DA0E2EDB33A255BULL, 0x7AAB01EA0B9C5E03ULL, 
            0x97BE73C9A0479675ULL, 0xCB51179F05477C9DULL, 0x1B073C7441822FB6ULL, 0xC65472069E31275FULL, 
            0xD5FE435235AABA36ULL, 0x35BA05A6D3AE5CC4ULL, 0x9738843056396328ULL, 0x36E98D341BE7F1F7ULL, 
            0xD26B056C909C30C0ULL, 0x532648AADC445739ULL, 0xA5C93D4F7BB0CB81ULL, 0xC9A707B4D817E8F8ULL, 
            0x09AEDF2FD47B8978ULL, 0xB8C93B90AE3910BBULL, 0x525DC43B5ADFD947ULL, 0xECA7EC4071D1542EULL, 
            0x5D149BCBC2671D4FULL, 0x80236ECABF065E19ULL, 0x4CDEF0BEEB65EACBULL, 0xBD78B27ED83E10A7ULL, 
            0xAAD4B4D7BE7AC761ULL, 0xB7DAE6C8A7FC0AF2ULL, 0xD56615F65A506F3EULL, 0xC6CB13086841595CULL
        },
        {
            0x1978FEBB132B479FULL, 0xE6BB0FEF6E3F9FC9ULL, 0x052DEE67BA2DD6B8ULL, 0xABD8D8978EFB7BA6ULL, 
            0x3527A52DED37D870ULL, 0x399ADF2036BFDF5AULL, 0xD1B1463680B09B14ULL, 0xF7A97AEAF63A4A9CULL, 
            0x12B3F574C109FE35ULL, 0xA577A8869C280E5FULL, 0x0392E89303FBD73FULL, 0x25DF30163D1B8282ULL, 
            0xB0255EFB0717206CULL, 0xEDF2C70723E33ED2ULL, 0xF62607E4E30EAA34ULL, 0xF5B0D2B2BBC447D8ULL, 
            0xA94A2A3216C28692ULL, 0xCEDEC54BD228F9E0ULL, 0x44413BB2B677CF0AULL, 0x7FA528FDE4E99EEBULL, 
            0x7C89BA5AC1B74C95ULL, 0x962AF24066D175D5ULL, 0xD45158EC999E401CULL, 0xE066999EEBD617F2ULL, 
            0xD680EE7338FDA82BULL, 0x69AD2125395A8676ULL, 0xC98F85E9B814026FULL, 0xEF826C8038B8D01DULL, 
            0x3847C4D0A0F5CA32ULL, 0x94F85185C5E75588ULL, 0x56FBAB3801663C97ULL, 0x4DF45E5FA054747EULL
        },
        {
            0xA8B2447E2DDF312CULL, 0x39F516CF9B3F66ECULL, 0xFD194055425926AAULL, 0x173D950FFC89DA45ULL, 
            0xE1A0E983DD5E6207ULL, 0x939384054B3D2E43ULL, 0x545EA9695A8AB122ULL, 0xF1D37A2A9BD2F9C5ULL, 
            0x1F24F3577A231A43ULL, 0x5159EA59E5159037ULL, 0xF9CF425B953AEEB0ULL, 0x623F675E98016A93ULL, 
            0x4E32D89B90A2C40BULL, 0x70F326DF41C29FCAULL, 0x24544CF81E11AD79ULL, 0x500349796E20EF08ULL, 
            0x99E5115C0B96CE4FULL, 0x9D22F62121526BD7ULL, 0x1D55A7BFC760FED7ULL, 0x3A24E03BDFCA16C7ULL, 
            0x7AFA2C59120CE70EULL, 0x4B5DB267D373459BULL, 0xEA4A5B5127728F64ULL, 0xE602357E733CF28FULL, 
            0xFB874579974E8FC9ULL, 0x41B6F88088B9F843ULL, 0xA508A1CD008EA5ADULL, 0xAB5C2BCBB327194EULL, 
            0x27593AD9470563E8ULL, 0x8B2EA39A141EE0B5ULL, 0xEB1DDE489A524565ULL, 0x9DA1488912B2D366ULL
        },
        {
            0x42982C4DB9C2FF80ULL, 0xC32D334F5186B89DULL, 0x93CFB2B261D114E1ULL, 0x77355B3BB25BD34AULL, 
            0xDB0DF7B7644C1729ULL, 0xD40B9E19D4F8799AULL, 0x6550BF8591375AEEULL, 0xC2289CC9A651D7A1ULL, 
            0x237751EB777993ABULL, 0x7465EE0EEFC26985ULL, 0xEEC0D9F03426CEAFULL, 0x7EB62DBBFE6EE79BULL, 
            0xA19319CFB6F782C4ULL, 0x7E97C6B3DC429B58ULL, 0xAB0EF24CDA3BA2F4ULL, 0xAD081375C1AD2187ULL, 
            0xEB79D3E526240C67ULL, 0x1C44351708453876ULL, 0x5548D51C0A61B3A7ULL, 0x71D127A0C5C05117ULL, 
            0x703268326E2C3186ULL, 0xD5CE841EDADDF5C9ULL, 0xAC5A3BA99AC5B894ULL, 0x81D84C2483E62A58ULL, 
            0x69F68EAAD534665CULL, 0x6B9F9A9E770EFE0EULL, 0xE2854935F4036686ULL, 0x59B5BE72B166B14FULL, 
            0x081DB732CFB7BED7ULL, 0xF09968328B572069ULL, 0x9EC63927CEADFAA8ULL, 0xA55D75BCCC201C1EULL
        }
    },
    {
        {
            0x7E11314D5C270217ULL, 0x6944E2BF151CC779ULL, 0xF14B2C45D6BA0142ULL, 0xCC325C5609DEDE20ULL, 
            0x75FC93EA4C18588FULL, 0x19A22730F35FDDAFULL, 0x1F6CB32B8A19DA93ULL, 0x2355AA642DF15BCCULL, 
            0xFAD1B6CA4B5AD4F9ULL, 0x2D07E0F4373DAE24ULL, 0x8B410211F62BBED0ULL, 0xDF3E3396ED4E5E99ULL, 
            0x5CE6D905B4890DB0ULL, 0x339B3F2F65D75190ULL, 0x069BE12772E2ECC2ULL, 0x9446614E0AC8914AULL, 
            0x0B79EFD14CDD3B19ULL, 0x64838241303E9B92ULL, 0xB142F0E2D906B883ULL, 0xFDAA701FA3F39476ULL, 
            0x50C289DBE0ED066FULL, 0x81BFDD5060EE7C55ULL, 0xB651277ADADA10E1ULL, 0x0CFABBA13BC300B4ULL, 
            0x1E38ECB35F3DB8D7ULL, 0x30E65F6DE134A265ULL, 0xE6EE05E6961B50BBULL, 0xBD7BA68072EE1C78ULL, 
            0x7D13CA771D0E8E73ULL, 0x2616597CC9375D48ULL, 0x499CC9255725589CULL, 0x08760C471534E530ULL
        },
        {
            0xB97DECAEAC76BE4AULL, 0xC4F7D72EA497EBDCULL, 0x9131D1232A18DEE8ULL, 0xD2E1AB6308820CB5ULL, 
            0x4DA86152367EA1F6ULL, 0x252BBD3673C0AA80ULL, 0xEB91F4D54F3E746BULL, 0xB601722123871DEEULL, 
            0xAD8EF2B010B862ABULL, 0xADABD19D5B42C1B2ULL, 0x7A4B8729CE7FBA60ULL, 0x24BAC9174948BD22ULL, 
            0x697BE9C9219EFBFEULL, 0x39C5B8EC3232F81BULL, 0xA4980C82C24721DEULL, 0x2BC5E60A2D31CBFCULL, 
            0x2D4BE74DAAD8142FULL, 0xEA2B8BA8AAB075F3ULL, 0x13CC5D021EB28EEBULL, 0x78FA2B0EB8B4302EULL, 
            0xE9F6E629B2AFE4EEULL, 0xE1FA6BFD3A3238D0ULL, 0x41A2BBDA367D642FULL, 0x8BAC7E5C9B16FBF6ULL, 
            0x2A5B5E4170F4DCB5ULL, 0x0522CB8960D1B9B7ULL, 0x73F932CE1FD203BFULL, 0xC55CA78B61F0811EULL, 
            0x81F1E0F8D127DDEFULL, 0x2AB90379AEA0D510ULL, 0xA2C3DA5A520046FCULL, 0x0B233C4C4D56695FULL
        },
        {
            0x335E44A0E8B8E4E6ULL, 0x92AC439098B3BA25ULL, 0xA7B940FA416CBDA3ULL, 0xC5182E97598C2EB0ULL, 
            0x91B099F7898A1208ULL, 0xB8656FB5189A622DULL, 0x0E2415153CD20AB3ULL, 0xEE480F37B1E7ECDBULL, 
            0x1267C5112EDFF506ULL, 0xAA60E2358791F13DULL, 0x8D24EFE414207F47ULL, 0x6850BE79CB32DC1DULL, 
            0x3FD46011578783FEULL, 0x4A041C79C45B56B7ULL, 0xB9F2A30A2035E916ULL, 0xF837CE723CD44629ULL, 
            0xE7F670FF556DF6AEULL, 0x0CBF69B7D9DF7662ULL, 0xC7D1F0E259A7C43BULL, 0x5D66B00E0A4CDB5FULL, 
            0x1CF1658FB2AA9AECULL, 0x1F2CE6F61F74C542ULL, 0x182457226048F2EAULL, 0x4D6A2774B4C57070ULL, 
            0x906FF2C13A26AACEULL, 0xC8F3EBAAC792BB4DULL, 0x3DF0B9F890C4E10CULL, 0x83B41418FB5AAD82ULL, 
            0x38E977F426F8E58DULL, 0x89260A3E12D255CEULL, 0x5A87D2236972DA71ULL, 0x47197CD2CC601398ULL
        },
        {
            0xE92F17297A695713ULL, 0x7958FA29BCFED3A0ULL, 0x48659D3D5E2947E4ULL, 0x39441D66FDB99E9AULL, 
            0xBC3BC91F3F3A99F2ULL, 0x61001316324D6FA3ULL, 0xFBCB349C926D0515ULL, 0x0E83599AF5A845ECULL, 
            0x6D11D293725D2FD9ULL, 0xEC3CB0BA2310BF66ULL, 0x59E1368615E8CD28ULL, 0xB1B09EDFE6FE49C2ULL, 
            0x108DF50BBCAA1C8AULL, 0x901EA5F516DE3FF0ULL, 0xEB74C2AC10CDC958ULL, 0x480DF5F7C86EFAE7ULL, 
            0xD575BA2D4BE14A45ULL, 0x4719BE01086F62A3ULL, 0x65DE76C19410412EULL, 0xC0D2D6BCDD65355FULL, 
            0x21E4DAE8030CC908ULL, 0x132D61CFF88D8082ULL, 0x1FF800FB710E15AEULL, 0xF564FE674245DADBULL, 
            0x5B0EDF194ABDD1BBULL, 0xB882219740C756EBULL, 0x4A619183BE4C4908ULL, 0xCFD37D38B86A7BACULL, 
            0x160D8E964F7DDB23ULL, 0x3FFE5D2080F7C2F2ULL, 0xDBB3FF629D7ED75EULL, 0x8EBD952C3A8E0FC8ULL
        },
        {
            0x67DE116E65CBCA68ULL, 0xEA85CD420A1DB53BULL, 0x34957BDD9E80EE94ULL, 0x118B91A02343EE4FULL, 
            0xD921DB27BB5076DAULL, 0xF96D9E35F4CEFF64ULL, 0x8066E2B6C1B903BBULL, 0xF39FE2C828BC6A49ULL, 
            0xE1DBD06D5AFC7986ULL, 0xE0200A568F4DBB0EULL, 0xD70C73248C02B2F1ULL, 0xA2ABC02305AD8EDBULL, 
            0x0E058C2CA5609D94ULL, 0x5F63861423853A9FULL, 0x34AD804C8DCE70E5ULL, 0x4C3CB933302716C3ULL, 
            0xDEFAC10485D3F248ULL, 0x22C7FFEBC7212F65ULL, 0x2630E922CBAE2204ULL, 0x857845E868488202ULL, 
            0xF81A1FB3F0E89F61ULL, 0xAF57DA1A23478D10ULL, 0xE9C174BE668238E1ULL, 0x86DB85AEADA1D241ULL, 
            0xFECFEC953527A6A3ULL, 0x32F5F5184DA9D8D1ULL, 0x2AB054C577AE6B53ULL, 0x68F2C19FD30A99EBULL, 
            0x93BFCF5BA9C9C0C5ULL, 0xE0D4F0E0FAAF3B29ULL, 0xFDEF6ACC861CEA19ULL, 0x47761505FBBFC62CULL
        },
        {
            0x991360ECF0862346ULL, 0x323CAD0ABFA78E2BULL, 0x3B4EB2BB8B32DCC0ULL, 0xDD2E0DF338F9316FULL, 
            0x0399BB5135C3E37EULL, 0xEE4D87CBC69D00DAULL, 0xF172B6B46FFC77FEULL, 0x14E8C8E8FF6F7CE1ULL, 
            0x21F5F1D2FA840CBCULL, 0xED2C0820E2D8A177ULL, 0xE70D2D459FB01454ULL, 0xFEBA3650A02148E7ULL, 
            0x2C52E2DABC81BF00ULL, 0x48F1A3CE7900C28EULL, 0x35B10EA1D3121CAFULL, 0x5E868C6434F1F540ULL, 
            0x94419D5B3A651F82ULL, 0x2903F66E326550C8ULL, 0xE3ED6922D7DBA378ULL, 0xDC19C0A93CF8D8CFULL, 
            0x942323F6BCA6AAE7ULL, 0xC4FA57E489B62C5CULL, 0x6408E17500C0A599ULL, 0xAE6A42D18AF57273ULL, 
            0x4D4E8CBE3D13A887ULL, 0x65D607146BB74A1CULL, 0x45C623B554FD04ACULL, 0x1D2A60E50798AB1DULL, 
            0x2F7D08568A5F7238ULL, 0x2DC278B5B9F87372ULL, 0x8B5D0890DF2720FEULL, 0x86D1021E4660D718ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseAConstants = {
    0x4CEF69E375D4DDE4ULL,
    0xADA7014316FDA4DFULL,
    0x8474F553D7FABA29ULL,
    0x4CEF69E375D4DDE4ULL,
    0xADA7014316FDA4DFULL,
    0x8474F553D7FABA29ULL,
    0xD5264CB57569400AULL,
    0x36B56189A69AA13AULL,
    0xCC,
    0x65,
    0xE3,
    0x36,
    0xE6,
    0x3A,
    0x8B,
    0x93
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseBSalts = {
    {
        {
            0x84673A5CA301661BULL, 0xB9FA7ABD435C2BA7ULL, 0x4E95920F0FA2C450ULL, 0x3388A56D6B68872EULL, 
            0xCCA9CA7BFEAB21E5ULL, 0xBF972DB6AC53B4C7ULL, 0x9EE993DDAC8FB83FULL, 0x2B684541FC1472E8ULL, 
            0x12C284BAEB83BA96ULL, 0x7A6FB80C42C9E896ULL, 0x2773E8414CD41DEDULL, 0x515D1D650CA3B16AULL, 
            0x12A1D16A5C574DDEULL, 0x780750D32D51CCF3ULL, 0xE9530EC544CB1B4AULL, 0x8BEF6ADE3AE0B557ULL, 
            0x12C4A4D4527D68DCULL, 0xF5D901060FFB7223ULL, 0x71ED5638061AAC66ULL, 0xF54A999CDB7ED733ULL, 
            0x9CCA8A2DC7B52D0DULL, 0xC4DCB8FE0E4F4736ULL, 0x528F4657C7A07EF3ULL, 0x14C65A1B4695A023ULL, 
            0x539C715825C49437ULL, 0x6AA3EE7D6FCA734CULL, 0xC46AD759B9C020C3ULL, 0xAAA61DA6B846E957ULL, 
            0xFABB241974B0B506ULL, 0x27E0AB570E826A67ULL, 0xF4C3DD708D769A45ULL, 0x0530CBBE0E6CA11AULL
        },
        {
            0x137A4BA98AE1DFD1ULL, 0x9C310D8FF0694723ULL, 0x1B20BD1B311EE898ULL, 0xF2CCDE5B4DD1CD10ULL, 
            0xBA3D64660F2AAC18ULL, 0xA40A33183B023D7DULL, 0x3F88B9DEA9A4A03BULL, 0x18F351D4A37C5472ULL, 
            0xADD96DF2ED47DECBULL, 0xC556ED121FD869C8ULL, 0x3D1C1109EBEFD7CAULL, 0x9CAFEF2BF4E3CB49ULL, 
            0xD55FD519A41942B9ULL, 0x47B680CE923125FAULL, 0xD05ABD475F757FE6ULL, 0x973BEDE951652EC9ULL, 
            0xB3AA820CDBA975D5ULL, 0x7410C448CD6B6158ULL, 0xB7C142BAEAE621DCULL, 0x9C4E2B42BAE2BD09ULL, 
            0x031B530DB18E1C96ULL, 0x6B09F1203074C7A2ULL, 0x01C01A7338AD93BEULL, 0xD63D4CC35A8FC78DULL, 
            0x719E0ACDEEBB0410ULL, 0x6B538F8CF6E462B2ULL, 0xF03670B605B2AC55ULL, 0xA06E6DE323120BB8ULL, 
            0x166B57DF9811D513ULL, 0x64A52983A1670252ULL, 0x3D0C2C84F857AB10ULL, 0x089AD3461C4D8114ULL
        },
        {
            0x7899B3D547E98598ULL, 0x1519D5C93532A5A8ULL, 0x5ED051FCA43B8C72ULL, 0x0CCE302B6EB061E9ULL, 
            0x29581188B3A485B5ULL, 0xAD1C838F960DC783ULL, 0x60EA4491B3C79E9AULL, 0x97B5E280C6D6D54FULL, 
            0x62EB3DE88955B7A7ULL, 0x6CB010ED04E004A1ULL, 0x3BB6084A5B05D0AEULL, 0xF253968852149ECBULL, 
            0x81D1C5231D6456BAULL, 0x599EF5C64EC73D49ULL, 0xCE6500458BB30310ULL, 0x5FAAD5D7A38767B5ULL, 
            0x8F2EFC56F8BC4F3BULL, 0x6C3CCD9BD551B279ULL, 0xFE9E47795F7886C0ULL, 0x9E9F6A903E7B60D6ULL, 
            0xA2C64FFE656FF5D1ULL, 0x00C4EBDED7A0EA0EULL, 0xBC31ACF028F5BC64ULL, 0x458BE3AA49EFEA6BULL, 
            0x08A7D8F5C63177D6ULL, 0xA9EC96562BC02DB7ULL, 0x26D5EC07CF8ABC26ULL, 0xEB7BD765C92A8EA7ULL, 
            0xC9873D9F9249FF7BULL, 0x3752F3158603F81BULL, 0x567E79430B8F3E6CULL, 0xBDAEA75E98A29AAEULL
        },
        {
            0xB61CA0CEFEB20E94ULL, 0x888047D4B97513EAULL, 0x754829E84A557BEEULL, 0x30DC9DE77C2C9AD7ULL, 
            0x694A2047F7192062ULL, 0xF4EC553574DA47C7ULL, 0x9FB0393A71BE0164ULL, 0x375EF5BB4D826532ULL, 
            0x944847AC44401433ULL, 0x1B2FD01934061B6DULL, 0xE64135039D2672B8ULL, 0xD1B30022CD70FFDFULL, 
            0x39F752F9BE1D2F63ULL, 0x7047425AC3693B56ULL, 0xB8FE8D1AC608839DULL, 0x67B9E5A9F8DD5747ULL, 
            0x4590159D6A241707ULL, 0xE54807BA03EC880DULL, 0x8E0DD02236A8EAF6ULL, 0x16440050473A282BULL, 
            0xB0C53DACF22729A5ULL, 0xAAF02736479E5C83ULL, 0xB3CB6E0A13482A25ULL, 0xA1E69760BC01DAFDULL, 
            0x8BE8B0ED96FA22B2ULL, 0xAD71D7735C51B605ULL, 0x93A5A40153596FF2ULL, 0xF6CBC8350775EE3FULL, 
            0xAB99CF06147D5423ULL, 0x44F84621B9AF3B79ULL, 0x7EC569ABE35AA5CFULL, 0xA3264A85C5F07598ULL
        },
        {
            0xE643B1D68CF3A893ULL, 0x4A5812D7B4D423FAULL, 0x5D3FCEB46E870A3BULL, 0xFCEC40E544759900ULL, 
            0x0865A2EDE2098D03ULL, 0x4C9B1A8E8AC88CC7ULL, 0x3E551E4B7502F810ULL, 0x318546D149350072ULL, 
            0xE8045DE552D10710ULL, 0x8AF15435124640EFULL, 0x43EEC99C5DC35981ULL, 0xF1DD3692460ABCC8ULL, 
            0xD19E55F581AA4A57ULL, 0xA0040C65E3E317B5ULL, 0xB703DE2D3751949FULL, 0xCEAF346AC89C8C79ULL, 
            0x73997F00C71EC583ULL, 0x4B6C4F22D48E0094ULL, 0x51525D2753CEE043ULL, 0x148EDA325FAB7E9BULL, 
            0x1F9BCC754E47F3FCULL, 0x538FEA91F1FA3CE8ULL, 0xB70DBF9553598DD2ULL, 0xDC65222450C5631BULL, 
            0x095A123D5533B852ULL, 0x1FFE674FF556D3A7ULL, 0xCA0797472FC352DAULL, 0x971A046BA7242C90ULL, 
            0xCFD0344523B957B1ULL, 0x13E8E5DE925E9483ULL, 0x65DAFA57017A4084ULL, 0x2CD897455CDF3A51ULL
        },
        {
            0xFCDC604C226017E9ULL, 0x31AEEBFA40854330ULL, 0x9502769DF9B2A791ULL, 0x5C8469DAD6EF91EFULL, 
            0x7E68318CFCA4B911ULL, 0x04CCC92116D191DEULL, 0x562EC037169C09F7ULL, 0xEB858DAAC93D43A2ULL, 
            0xF3ACE5FC9B7635F3ULL, 0x955A6F397E3F16E4ULL, 0xF8E34DB869D98C62ULL, 0x0B868E4827EA7B0CULL, 
            0x45A605862B16A9CBULL, 0x173A3936FFA3892EULL, 0xA41C8C8C1142442DULL, 0x2632E4EE0407044AULL, 
            0x036FE5431BF2D118ULL, 0x237DA26906C6AFEBULL, 0xAF49B12BE49E33ABULL, 0x1240F452153A62E3ULL, 
            0x29128F46CC87FF1AULL, 0xAB6C4E24986758FEULL, 0x803B1C683FC7FAB5ULL, 0x9E4E335E278C6737ULL, 
            0x7F653DB268186844ULL, 0x7C80A43FE50C011CULL, 0xCD8E37B79AB9523BULL, 0x5450A5FFDE94CBFBULL, 
            0x891C180D22CEAFA4ULL, 0xC1E850E0F591FFA5ULL, 0x188102EDB002CBD5ULL, 0x872D5871756946FCULL
        }
    },
    {
        {
            0xD906A554C0823BACULL, 0xEC58BD2A7C365CE8ULL, 0x196FD48D4367E304ULL, 0x40EF013B5E161B0BULL, 
            0xFE11F0DE48C4B820ULL, 0x0F105D2AA9D523FEULL, 0x142478ACFFFEEBAEULL, 0x6AFD009AC3BC68D3ULL, 
            0xCD8979DFC44FFFA4ULL, 0x3837EDB34BD8B9D0ULL, 0x6DA9446FFC5A4743ULL, 0x1B1FDFD80D8D2D44ULL, 
            0x57D98E6B5A90E79DULL, 0x3373E2FBACBDD16CULL, 0x26495EC0DD93168AULL, 0xA559AFE01C8E1340ULL, 
            0xF8DF15DA85B24EB2ULL, 0xD3F23DC55D4DF54FULL, 0xAA474A272DB6E894ULL, 0x652FB77547A1186DULL, 
            0xEBC0510D0BC1E526ULL, 0xD1B275E6710238B0ULL, 0x1FF230B5F8EFA5D6ULL, 0x9E711CDDBF1DBF6EULL, 
            0x7550CB65C53FF0DFULL, 0xEF7DB7A141D7701BULL, 0xCDBB24FE1FFFCAE2ULL, 0xC02A6868BAEEEAF0ULL, 
            0x196440F5360BE26CULL, 0x9A1F8058A40D3995ULL, 0xF67CEEB47BA0A4B4ULL, 0xD2F908B78C6EA66DULL
        },
        {
            0x7A74E0BA5DC165CDULL, 0x4ED79CC0674C7C34ULL, 0x255091F6238BCC8DULL, 0xF66BFBB044A4A693ULL, 
            0x9FFEBDAA44BFDA45ULL, 0x4AF0C618D7BAECD8ULL, 0x0B2EB9C59962E782ULL, 0x360894F48933B207ULL, 
            0x2E4019257E31FD82ULL, 0xB9B95B72060E78FEULL, 0x567BAC716F90755FULL, 0x5BDF392163EB5DFBULL, 
            0x7A7384F9112015C1ULL, 0xCD4344AED9BD4861ULL, 0x9058E75F66BCA652ULL, 0x74121388A9C819EDULL, 
            0x5BB13AB7FB5390F8ULL, 0xFA59DA39CE311C31ULL, 0x7824D8B02CB865D1ULL, 0x12E338DD92DBA0BFULL, 
            0x3EBD189DC26CEABEULL, 0x8133CAC3BF20D640ULL, 0x61041EBD6B678449ULL, 0x598F5FC51A01F322ULL, 
            0x360949EB66C3EF1FULL, 0x89C063959CE5CBB4ULL, 0x71B5C56251C1C3E9ULL, 0x9397AA58C3340224ULL, 
            0x8E4A772E9DD1331DULL, 0x8E29329838824CF5ULL, 0x5CC9BB44702A5492ULL, 0xB9BD8B109EBD385CULL
        },
        {
            0xAF3939E8BA92CA73ULL, 0x84F290CE841878BBULL, 0xB6270D8DEFF94155ULL, 0x07DF5E02403A5095ULL, 
            0x39878A675535DCBDULL, 0x9E946AF3F290C3BEULL, 0x4BF2743CFDD5A188ULL, 0xBD957019844C2F01ULL, 
            0xD9813E916707AA5FULL, 0x43A5797A3F1F67D5ULL, 0xC9F53CB5790705DEULL, 0x1D13FE70A0C15374ULL, 
            0x30BA3D1229F7B3BDULL, 0x6341D02EDFA8BD87ULL, 0x90417D60235667BAULL, 0x4B2CCD0107C4756CULL, 
            0x96CBF98D3A7D6E41ULL, 0x4EE8BA5C478FE34DULL, 0x982A2A5D470294FBULL, 0x060315CDBE1A48C6ULL, 
            0x51DDD4A257DDE1DEULL, 0x7725B289BEAFA0BDULL, 0xE84705DF15632B52ULL, 0x70B8DB8386CEEA43ULL, 
            0x36F9A203B2C20576ULL, 0x375EF19353194330ULL, 0xFF7AB33EDE9C825EULL, 0x7AB63D28BF4E6E1CULL, 
            0xDCD99FCAB20633EDULL, 0x5CD92BF429344DC0ULL, 0x91D307911E0B44F4ULL, 0x87DD6FBA04E14653ULL
        },
        {
            0x8007931D00B49EBDULL, 0x28662FEF15B3AE2AULL, 0x74F8F6763282A9ADULL, 0x7B85FB948CF98A9FULL, 
            0x297A80BB6D96B765ULL, 0x0565D435B4DF9673ULL, 0x329BF4DB6FE590A4ULL, 0x4E14AC2113A43F81ULL, 
            0x068978D1CAB2D3FDULL, 0x68F1112DE63BFF19ULL, 0x378A4FA1F63EA52AULL, 0x3349C282A711A232ULL, 
            0x50D51A7D32CA29C1ULL, 0x8962D9C6B5FDBC2AULL, 0xA9843BE21B3ADAA8ULL, 0xD5D2F426332ED6DDULL, 
            0xA681C7A47A6A6698ULL, 0xC211D62F67E1E009ULL, 0xD9FAB9E074687790ULL, 0xB62EA1AD52D48F8DULL, 
            0x090F6B8861568FF3ULL, 0xC4C14F70EE209945ULL, 0xA139DEE57A437CD0ULL, 0x0D3414641535CAD5ULL, 
            0xF0248E454A8AE4B3ULL, 0x78E49E8E094B0C8EULL, 0xF66B0B0060833C14ULL, 0xC40F6F11ABEBBE7EULL, 
            0x9E3D8D6D99F383F1ULL, 0x227D8765CDDFEA77ULL, 0x333DD7C71FF0A21EULL, 0xD4B6C03183D09138ULL
        },
        {
            0xE8B7AB721EDFAB2BULL, 0x9F2D0606B7BB325DULL, 0x36CEF0308D6F3E4FULL, 0x376E7FB600313786ULL, 
            0x0FB087E55F81EDFAULL, 0x2A777F9CB1B442A1ULL, 0x5C2EFC971C3B1B2DULL, 0xFABF9D03673679A5ULL, 
            0xBD9AD81D7BFAF137ULL, 0x2DF4DFF5C5BE2F06ULL, 0x7156371F9716CA75ULL, 0x4131DC2A97D4CD43ULL, 
            0x978B1D671DFA256DULL, 0x11E32D826A242B94ULL, 0x9929860165F09823ULL, 0x5F7E2C36205FF8DCULL, 
            0xEFE58EBFAE1601ADULL, 0x043B7BEA82BF282AULL, 0x19960571A37A6FF7ULL, 0xA24BE4E533201F75ULL, 
            0x6B64D9FD23B4004EULL, 0xAB826D30C4FD453DULL, 0xE4FBF68C54855360ULL, 0x70095042792F28E1ULL, 
            0xA290B991428C7A72ULL, 0x7313A35BFEE831BEULL, 0x692C49C85281F243ULL, 0x3E71CFAFEDC3650CULL, 
            0x6921361E687461ADULL, 0x91DA04E4ABA38937ULL, 0xCD7C177B8D4C4D31ULL, 0x176FAE2B703DAA38ULL
        },
        {
            0x3E3A0A0445D74428ULL, 0x45ED6F3851500888ULL, 0xF8D8EE26B8E34859ULL, 0xEB9B1DACC9857BF2ULL, 
            0x2A836C2E6F79D14FULL, 0x897EC205ADBFEBFCULL, 0xC035DE0C5081DEE8ULL, 0x040B81BA9624BAA5ULL, 
            0x5786D8478E67F177ULL, 0x9F81C9F15A4B7D70ULL, 0x92F391C22AAD2A7CULL, 0xC5B6C7C9F7F30414ULL, 
            0xBC3EB71EE331F934ULL, 0xAAF6704DFCCB6724ULL, 0xF5A0BB725F0545E3ULL, 0x093DBD75F10C683AULL, 
            0xED5615A1F0FE7F51ULL, 0x578FCE871264968FULL, 0x41E758DF33A1DCCAULL, 0x84391B4E47F7F0DFULL, 
            0xA685675C5D60BE31ULL, 0xC97B438DBE7A9215ULL, 0x1AC13B38390BCDDDULL, 0xB8DB211033363629ULL, 
            0x16E73A215F8C7373ULL, 0xE2345A6A34FFCEDEULL, 0xCB8E1695D4131D06ULL, 0xB78C62E750DAABB1ULL, 
            0xB336D97244E22F9CULL, 0x4F571EC8467A5C9FULL, 0x33F5978A94B53B9DULL, 0x97440953E78A7C99ULL
        }
    },
    {
        {
            0x8FDE2BFFD5C35703ULL, 0x38E93F3F03F59C90ULL, 0xFC901AE7DC6692A8ULL, 0x3864D7C80A8DEB29ULL, 
            0x4C527742AC969639ULL, 0x3B45CA95D00757C4ULL, 0x984696B729805ADAULL, 0xF685AE27D64B2752ULL, 
            0xA414BF215704102AULL, 0xD2FFFEF109E510C7ULL, 0x455DD5EF88C0F627ULL, 0x4202DD5C8335555EULL, 
            0x6E3066CD5AC2C69BULL, 0xD83B65A8D0956290ULL, 0xD11881A0A5ADC1E4ULL, 0x17A606F5431B2147ULL, 
            0xCA7C8285EB3F8090ULL, 0x8B965DB235526C94ULL, 0xD010CFFF54B028F2ULL, 0xAD97CCC38E730A1DULL, 
            0x679609922852C6C4ULL, 0xB4C3C6433C82B5D3ULL, 0x0769EA13DBE70711ULL, 0x34BCA5AF187FC239ULL, 
            0x02416D181306458BULL, 0xA0D3D04F1EED9865ULL, 0xA8A33EC7B4667873ULL, 0xE84836B5EA720271ULL, 
            0x0352420551DA45CAULL, 0x35649AA4174BFF91ULL, 0x6CAEEBC3089839F7ULL, 0x4985C07A72AFD155ULL
        },
        {
            0xC2BB8DD67F02D67CULL, 0xCD01D7E282BA55AEULL, 0x5AAEA5749182F617ULL, 0xAA1F102C258A86ECULL, 
            0xF360056F9B812213ULL, 0x327722F60D1D0868ULL, 0x93543DE82CC29128ULL, 0x6F8CF9A8ECBA766FULL, 
            0xC2226DD35D8B90B4ULL, 0x6AF3833131546715ULL, 0xD2B94382C50A5CDBULL, 0xF861A3EBA3369E37ULL, 
            0xE7474F62A69ED97AULL, 0x70CE5764CF62BD3AULL, 0xE018FC8CFA85B1ECULL, 0x0A342CCF402AB9E2ULL, 
            0x6151DE5458FCBC03ULL, 0xE5DB7122F349CAD4ULL, 0x7C870B69C3A78CDBULL, 0x90A4020DA4C24873ULL, 
            0xA6FB9C9A0987D83DULL, 0xCC581905FC45CDA5ULL, 0x3F3C0D4B519775B5ULL, 0xBD783E47B017A2E7ULL, 
            0x76BC0423684320F2ULL, 0x310974A6EA3188BDULL, 0x9D496894C6174ADBULL, 0x7D4658F89F899164ULL, 
            0xF06A86EF85E847CDULL, 0x3714ABD669734F99ULL, 0xCDABAAFA7A60A261ULL, 0x13A0BAC4ACC22613ULL
        },
        {
            0x6B6CB9B8BF82FA5FULL, 0x351E9B1A4E2EA978ULL, 0x7B7923D314FD9D17ULL, 0xFAC417198F840855ULL, 
            0x8AD25121A765E4A1ULL, 0xDA5D96033B7FDFE9ULL, 0xA386FDEBBAB2604BULL, 0xA2E69E0F8141801EULL, 
            0x45DF2D79D97B76C2ULL, 0xF351F63A09A2EAB2ULL, 0x3A453808A775AE58ULL, 0x1DD18FECC7EDB802ULL, 
            0xB8C13F592F66B51BULL, 0x4A85DAC2D7DEF848ULL, 0x56BDB5194694B3BCULL, 0x66C7356FC797B131ULL, 
            0x309635D32E91A883ULL, 0x57422A318765FD90ULL, 0x56750760D3311987ULL, 0x12F5F7F6411FCB6EULL, 
            0x68E70E689995E2EBULL, 0x1625AF3641E6FF47ULL, 0xBD0A1540A9C16485ULL, 0x58F1E9D3BB03D8ADULL, 
            0xAF83A683EE6256ABULL, 0x29C5438BB3047E82ULL, 0x8470F7717A712140ULL, 0xF4A8CC9F4C485167ULL, 
            0x1DD9254CEC25FF0EULL, 0x5EE7F315DB96F5CEULL, 0x6006133D08017C2AULL, 0x00E00E1E721C5D08ULL
        },
        {
            0xF2A88EE049C202B5ULL, 0xAD2E910DB586F90DULL, 0x71E07D90D3E0DC32ULL, 0x43195011D383D048ULL, 
            0xC357DD4780334527ULL, 0xFB5141E1C16F4F31ULL, 0x672A9B22B197EA33ULL, 0x5B8AB72F489FE352ULL, 
            0x991656E00998E8DDULL, 0x4A92A1A7F4464770ULL, 0xA80E06C8083DBD60ULL, 0x6B77F23E4159D953ULL, 
            0xF9099704E1723FA6ULL, 0x481171E19E385F6AULL, 0x0B826DF9712D00FDULL, 0xC1859F7332A4D006ULL, 
            0x60DFFE99B43405E7ULL, 0x58B70A884B8A7DAEULL, 0x5AE96C89A793D93BULL, 0xB878472A94C905E8ULL, 
            0x9EB95E08BDAD612EULL, 0xB301E89DBC9287B7ULL, 0x7F5B65A80B86CF30ULL, 0xD6844F483FC51D7BULL, 
            0xAD56E13F04B4A3CEULL, 0xCB91D7EE296EDB43ULL, 0xBB62B51B7940CCA3ULL, 0xBDDC5F7332D774C7ULL, 
            0xEFCD6B98F8990790ULL, 0x8C05CD6476E3B6D5ULL, 0x0EF1655E0206DF80ULL, 0x159BC48F8CBFEEBEULL
        },
        {
            0x761D92A46313BC03ULL, 0xCDD51EA99AC2E315ULL, 0x2F3CD24898E2B0DEULL, 0x14D43A304634796CULL, 
            0xEF213BDAB208005DULL, 0xE866EE0741B64548ULL, 0xC021C50E6FE8A45DULL, 0x1CE8D6705E5DDED3ULL, 
            0x63E0304898240712ULL, 0xDC80042E60F06C8CULL, 0x6CE8E4C4D37D8529ULL, 0x30E5DA996AB36B6DULL, 
            0x94C54EB809DFDEF2ULL, 0x6086ED3A5AC4B582ULL, 0x4F4695C0381318F2ULL, 0xAF24906072EFB482ULL, 
            0x08B553F67BC7C0B1ULL, 0xF770BC1D7B25295AULL, 0x7557571862AC90F7ULL, 0x23116A226F02AA9EULL, 
            0x78C7304F79316333ULL, 0xD2C2CD19B0579CE7ULL, 0x432809E534C524BDULL, 0xDF037CD22A37CE52ULL, 
            0xD3A31A9F569DB7CAULL, 0xA59DA7A279F044D7ULL, 0xD88E8B3169BFBC34ULL, 0x43B165DA0BAE3BEDULL, 
            0x445374F10E499A02ULL, 0x64044C24D9C2922AULL, 0x3D5B67DDD1D639B6ULL, 0x9D94E9A8CA2AAD7EULL
        },
        {
            0x19B263FE47A71CC1ULL, 0x36D953531E797867ULL, 0x2FFF694187CF506DULL, 0xCC23F34145285A54ULL, 
            0xCA5FF542EA87B9D2ULL, 0x99E8E4478B3A84FFULL, 0xF828F77A13A66731ULL, 0x6D0F3E6326B18B51ULL, 
            0x31BF4042E6EA2DB9ULL, 0x75BB740461684F29ULL, 0xADEEAD940FD75569ULL, 0xFA456B2025CD16B6ULL, 
            0x3D4D38F93F786E59ULL, 0x9D3821CE7D509C58ULL, 0x734B952E45AA7131ULL, 0x6625EA294A88A3ADULL, 
            0xCD5AB3212C08D9E4ULL, 0x2CE115F3C82D1857ULL, 0x559D3833DE46DF0EULL, 0x82E504D512E50D23ULL, 
            0x248DE982C7688DB7ULL, 0x868B74B9574AEEE1ULL, 0x2BC91B7C90D3D46FULL, 0xE54D9CED9C525AADULL, 
            0x25DE6909B3DB5C55ULL, 0x05AC5F3AEEFE3F4FULL, 0x2883601A583E93C7ULL, 0xDE04F0480D0BFB09ULL, 
            0x848766EA24983531ULL, 0x7A40D884DA97BFD4ULL, 0x3BB1712AA3177C4DULL, 0x34E93AE0084C0C98ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseBConstants = {
    0xAFB2E705B98376D9ULL,
    0x345FC4DD17702C99ULL,
    0xA1F2E85E15828E46ULL,
    0xAFB2E705B98376D9ULL,
    0x345FC4DD17702C99ULL,
    0xA1F2E85E15828E46ULL,
    0x6180CF01080A2456ULL,
    0x30A8FA45012FE2D6ULL,
    0x5D,
    0xB4,
    0xDA,
    0xAE,
    0xAE,
    0x07,
    0x45,
    0x2E
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseCSalts = {
    {
        {
            0x465121D369568C42ULL, 0x316092F706AF50D3ULL, 0x918F95EA08EE8B54ULL, 0x4974A249B9D172E9ULL, 
            0x7539CBE6E049C4E9ULL, 0x375CED7406554212ULL, 0x9413CB651702C1E4ULL, 0x819034F5DCE82D15ULL, 
            0x49155CEE7ED354E7ULL, 0x4695EC9C2E761B77ULL, 0xE65ADBE4E2D9B60CULL, 0x182689B883AE5C1AULL, 
            0x07020B6B5FC3E8F5ULL, 0x0082E4D490285455ULL, 0xD89D3EAAACE1AE40ULL, 0xF7F1CB250BF7AB9BULL, 
            0x7AC2D01046FA4A53ULL, 0x90521AB02AF1159BULL, 0xCC3A5F5C85ABC18AULL, 0xD25D81FFEF6BE5C9ULL, 
            0x487E14825CB6BEF4ULL, 0xCF63ACB5FCF0CE7BULL, 0x89A6B9A5CFA2C8C6ULL, 0x6FFB7D02AE02846DULL, 
            0x4ED314C53D620743ULL, 0x45C116B63FE109EDULL, 0xF1C1FD9D68C54E32ULL, 0xFB5453A7DE28CA4AULL, 
            0xEADE3BC504A0B89AULL, 0x54D208D15679E638ULL, 0xCE5E84F423DF3912ULL, 0x4A9B6C35EBA2BDBFULL
        },
        {
            0x5BA154128D54431CULL, 0x0392360467B2C350ULL, 0x1930CDFF24F02AA1ULL, 0xE869EAE89645AE75ULL, 
            0x310D30E687060173ULL, 0x2F00DCD488DDF05EULL, 0x0ADFBD68841FBC77ULL, 0x36C9599AB870F020ULL, 
            0x4F9B442AA976B9AFULL, 0x84EB7C8EE8B6061EULL, 0xC3283F2622ABF041ULL, 0xA3A5261C222AD1ABULL, 
            0xB3FC919D3F51E65BULL, 0x9E21053A61E5DB37ULL, 0xBD144A40E47440B6ULL, 0x823E59E8078F5F30ULL, 
            0x1DBF95E1FB306292ULL, 0x4E4E15D04B26618CULL, 0xFB35AAA0D17F0AE5ULL, 0xA0B08A4EA976796CULL, 
            0x2D7732CE862EE0DAULL, 0x006E1A19BB17F485ULL, 0x846328F6AA6C5C53ULL, 0x26656DA32A5624D6ULL, 
            0x9EFC96438BC6A86BULL, 0x1B61F25B16F4C814ULL, 0xB84E30DA029111E1ULL, 0x44F1EF61CEF240C6ULL, 
            0xCBC5DBBFC8556E1BULL, 0x184F829A34162614ULL, 0x37BC17E108D5453DULL, 0x1B4EF560D580F492ULL
        },
        {
            0xA6A7E7CDC399633CULL, 0x0E389DF10A56C84CULL, 0xDDE0BEC92CBCD141ULL, 0x60C57D06CA3ACDC6ULL, 
            0x07AC302EB337FC57ULL, 0x79D5A5E89606093BULL, 0xB29768E5DE4ABAA8ULL, 0x1BDA1215A1C752ADULL, 
            0xCFB1A15EC72449E6ULL, 0x2E54DA49217EAB79ULL, 0x26FFB54037B037BDULL, 0xAE995B5DB1284679ULL, 
            0x61A40E207FBD47E2ULL, 0x3EE7737010D40C1FULL, 0x2C856597399A8489ULL, 0x626FBC6A2963FEA9ULL, 
            0x057A2304CC19A49EULL, 0xEC611ED6D3DC008EULL, 0x0ADF24F7301E1AFDULL, 0x4730B2D01EDBA6F5ULL, 
            0x6A7A94EB2F3D783AULL, 0xABCB8DA0472149FCULL, 0x2AB3F88BF22A7929ULL, 0xC858F4FBC95EF5C1ULL, 
            0x3CF7F562C55F15E6ULL, 0xE68AF07E47B21189ULL, 0xD8A1EFC4BDD07565ULL, 0x511449C8C4D6153EULL, 
            0x036E67CF85F15145ULL, 0x14C73D78589B2A29ULL, 0xC4FD106555F30496ULL, 0xADA2597F553DE43CULL
        },
        {
            0xA982C733C18FA6F7ULL, 0x5C144F8830265A62ULL, 0x548336839EB9D0F1ULL, 0x5806D90F67232DF8ULL, 
            0xB71A7A24658C947EULL, 0xE6E2091611D44D32ULL, 0x9D1D97DF664E198CULL, 0x702068D524BA82C0ULL, 
            0xF20FB7823C9C2052ULL, 0x62233FE51D364574ULL, 0x43FDF5AEC0B319DFULL, 0x677B46336E9498BCULL, 
            0xE7506FE1B1A4B1E3ULL, 0x6ACB16445C348618ULL, 0x0D7E40D2BAE22909ULL, 0x565D3E76CE58B371ULL, 
            0x42C60A0EC32C2723ULL, 0x21CDDE69CD24064EULL, 0xEF9A67B9A59CABB1ULL, 0x64CD2E89A1A4AE2AULL, 
            0xE635380A59CF7196ULL, 0xD23BCB512FA9443CULL, 0xBCC520CB5E08E734ULL, 0x10DB5B2BD55C474BULL, 
            0x4A1C8B9CD6D5DF12ULL, 0x33B451EE4C64D64FULL, 0x345FE499B74125F9ULL, 0x4C0AB4B84A38B627ULL, 
            0x84DFA96033A597E5ULL, 0x36F56FCB912E3D85ULL, 0xD4088A684FEDFFA8ULL, 0xB3FAE3DDDC22E1E3ULL
        },
        {
            0xE5F2D741319EE455ULL, 0x7895C7B630855F14ULL, 0xA31659C933989135ULL, 0x5E701867BEBEE0B8ULL, 
            0x146A22BCBC20E663ULL, 0x33B63164B12F6BABULL, 0xF36922FA45747D7EULL, 0x39CDACA7A1F4B0EBULL, 
            0x2A3831FC8110A9D8ULL, 0x9E72A625AB3ACC05ULL, 0x70BE31FA331503DBULL, 0xEDB12ECC4FAAE017ULL, 
            0xCAD8AE5A28DC1BA4ULL, 0xB0857BA668D9A420ULL, 0x6DDF831023A6B09BULL, 0xCF648D5B630F1427ULL, 
            0x9DECE407A5F56885ULL, 0x46AD00A27E7CF80DULL, 0x971DF3775F9DDB02ULL, 0xA3740D9512FA7518ULL, 
            0xFFEE3A01EB917E2CULL, 0x2A87FC8EFE6853A2ULL, 0x1BF45353E8793B2DULL, 0x100FB102776A860DULL, 
            0x321D6B731C4E8310ULL, 0xFBC0A6F62D0FAF6BULL, 0xD414D2BAECC3A9B8ULL, 0x49CDB10561E3D4EAULL, 
            0xA2A9ED87CCFCD1D3ULL, 0xFB6074B5D76B38B0ULL, 0xE16A8EFD9BA5420AULL, 0x7BCEC7C37428F377ULL
        },
        {
            0x7D4E8C328604BDD7ULL, 0x69ADFB9B1DD8DD0EULL, 0x7B06F817C227A0E1ULL, 0x60529B636FB10A72ULL, 
            0x581FCE42FFE551ACULL, 0xD1906CBD0A854A14ULL, 0x5E586DCF1323E4CDULL, 0xB0D560B2FD02205BULL, 
            0x7662708B7DF8D646ULL, 0xAC8536481F75145FULL, 0x8157E62E4DBCEF04ULL, 0x58A238D06E3554DBULL, 
            0x0821B9DDEB6EAE49ULL, 0xF3B283B5DAE3EA21ULL, 0xE5358CB6444DE9BAULL, 0x8DC6A9AA6E5623F1ULL, 
            0x98810B88F8CA272DULL, 0xEC4BAFE7631386F6ULL, 0xEDF281C040DDBB60ULL, 0x59150824C8FD2843ULL, 
            0xBEE05C847821837CULL, 0x5363F6C63CDA3951ULL, 0x8AF14F2DBEAA139EULL, 0x4D8DE0430AA6603CULL, 
            0x125801A8E2B3B1BDULL, 0x85B6D1718EEFCA75ULL, 0x740786458E50DC89ULL, 0xB8200A66CD0A9AA4ULL, 
            0xD66C739765CA2F06ULL, 0x3D783C3E30907C1EULL, 0x488AFA00E8904B70ULL, 0x486C0951281FAD9EULL
        }
    },
    {
        {
            0x967EF44BE9DE9330ULL, 0x861F90D770F130FFULL, 0x810B20EAEF1FA097ULL, 0x54BCB8A0A9A7755FULL, 
            0xEBC315A268577C4BULL, 0x34ECEE9812CAF08FULL, 0xDF28FDBD89E0FDCBULL, 0x7F7747156E8D3305ULL, 
            0x4073A04E486A484AULL, 0xA59201E9AE0CB295ULL, 0x94C6AA659932ECAFULL, 0x891E44B0E9AB7421ULL, 
            0x96620EA4D83EE5C4ULL, 0x29D4BE8F37C9F560ULL, 0x3416789A746A339AULL, 0x3AD6732DABBDA9DBULL, 
            0x615F5637664C00BCULL, 0xCAFB3A1A42D514F1ULL, 0x51B91F5DD4629994ULL, 0xE1D28A7C9B817212ULL, 
            0xE8088DF8C0DA6B2EULL, 0x25CD9E92A1721D7EULL, 0x86616593CF6A4220ULL, 0xF3444C7B41BC7591ULL, 
            0x65EF8116A5970060ULL, 0x3BAF07C0C7AD6F68ULL, 0xC9838B5512EC7502ULL, 0x8FCD55EAF3F89DDAULL, 
            0x1A940AD2058D3735ULL, 0x85A900D7EDE8656AULL, 0x7F1C332CEC64A626ULL, 0xD3F31849DE390BC0ULL
        },
        {
            0xC91A62FDA48F2C96ULL, 0xFC31243E345B1B85ULL, 0xACEB2ABBF724EE15ULL, 0x0D5C13ADA7C8E68FULL, 
            0x24DA01FD963B7ED4ULL, 0x768C0A91D267E051ULL, 0xA4D73F0D989AD369ULL, 0x55B46848A1716B03ULL, 
            0x07BCD765804BAD0EULL, 0xDB1660BB3C4F1EE9ULL, 0x35FD189EF6AEEA6CULL, 0xAF3249691997CA05ULL, 
            0x73BA27B15D79E8C2ULL, 0xF27207B7DE334527ULL, 0x8EE86117230EBCDFULL, 0x3B981EB1D0ADC8A0ULL, 
            0x7C8B5CC8366F1D0DULL, 0x446608C212E2622FULL, 0xD105CF4D00558955ULL, 0x76CD49BE5321DFB7ULL, 
            0x27AC3DC1532D4E5EULL, 0x939D5161B5B1CFF7ULL, 0x27EF8E27E3BB0D28ULL, 0xFDA89212E545E5DFULL, 
            0x5A76F19AF232C729ULL, 0x494BE4F08F00922EULL, 0xF3EC144B6BAE4AC0ULL, 0xF5EAE04AF81FB15BULL, 
            0xBFF8A42565658FA5ULL, 0x91E48200F12E1E21ULL, 0x543272370EB58521ULL, 0x4FD12435C9FD267AULL
        },
        {
            0x2CA096235F3B22EFULL, 0x8C65716A24D37310ULL, 0x417A4CE5F9F0ED3EULL, 0xABE4BF81BC701C49ULL, 
            0xC5A5DCF4A1A0DA74ULL, 0xF1B8EE34CBA54616ULL, 0x43CA37FE2FF433D4ULL, 0x788BCE880B8D63F3ULL, 
            0xE69D63A4FEDF0D71ULL, 0xB0326A78768EE3A2ULL, 0x5AFEB300084BB050ULL, 0x7DD4895A5CB2D6ACULL, 
            0xC7B75D5C0AC837C7ULL, 0x4DA89AE8A249A42FULL, 0xB72363C9571730ABULL, 0x4CACB5BF11AF9F54ULL, 
            0x4ACD68FE1099EE9BULL, 0x443FC2990FF63E00ULL, 0xEF20B186766B4CD9ULL, 0x3193D2F308033180ULL, 
            0x771BB54DCCB93F85ULL, 0x0F71CC9FCD2748FBULL, 0xC3F7FC40D0A6CF06ULL, 0x862E1F20FDBA5DA4ULL, 
            0xAD949D17DCBADC75ULL, 0x3A0DCB1F5203559EULL, 0xF50E2C3E24233E76ULL, 0x37F34FC21C2F3682ULL, 
            0x5DAD12B28EF0BAE8ULL, 0x970ACF007A93EB92ULL, 0xC43B45A804B35399ULL, 0x8AD2696496F816C1ULL
        },
        {
            0x157C28894460F0F5ULL, 0xCC82C89861EBB26AULL, 0x06047D0DE853999AULL, 0xFA60FAA440E28A37ULL, 
            0x98F5EC092D96B355ULL, 0xBFC93880E92B203AULL, 0x08F56FDA0BFB113BULL, 0x0C249918B285EEE3ULL, 
            0x8724B68E1E15833CULL, 0x023A71F97CE7591FULL, 0xCCFDD976F98F15F6ULL, 0xCDB1402BE57CB968ULL, 
            0x8DF9FE2C8588E17CULL, 0x798A1BF755110330ULL, 0xC4FDD8CAA006B1EAULL, 0xE12BCDBDDF3A70AEULL, 
            0x52C37C0797541CB6ULL, 0xE8B8FB92F5BE45F4ULL, 0xC9B3B5656FF4DDA1ULL, 0x6B73528F696BD6EDULL, 
            0x00B455A480C5224BULL, 0x52854A2340B34DF1ULL, 0x6DD3DEB4C10492AAULL, 0xAC67E9D3FCDAC1B9ULL, 
            0x6E28009AABB55026ULL, 0xD6DB957F0D771499ULL, 0xAAECB7F5AED29AEEULL, 0x6F1137EE38244B30ULL, 
            0x8AF8918358F9C42DULL, 0xD61A3F732CF2D7BDULL, 0x5778EE34B32996DEULL, 0x92206550AEF0FEEFULL
        },
        {
            0xD40405A9D44B8C93ULL, 0xD2DC2099ACC6A503ULL, 0xCEE56719BE240EB6ULL, 0x0027342166642D09ULL, 
            0x8D2B22797EDA0507ULL, 0x5713F0214A597D6FULL, 0xD83F73E365955BB0ULL, 0x104B3B007A2504DFULL, 
            0x2BC90B327C732D9FULL, 0xCC79BDBA6AF9E709ULL, 0xC6233E255E65C2DEULL, 0xF8EF158FA5428766ULL, 
            0xC787F1078AF95EAFULL, 0x1D8525E6C963FE65ULL, 0xB5D2AB890F3FD2D9ULL, 0xFA9811ACD5071626ULL, 
            0xE9D281491023782AULL, 0xBDFE07D067353073ULL, 0x9535652A0967662FULL, 0x9E9E3A7862F80496ULL, 
            0x429D79281E688787ULL, 0x1E74E84E36A1FAD1ULL, 0xC8F6BCBCEB19CAA7ULL, 0x780C6C28695B834FULL, 
            0xC36B9E3902234228ULL, 0xA5E2EFE4488A013AULL, 0x49501101D0604A57ULL, 0xCC7D9CA1A54C517DULL, 
            0xD3DBD2CC5983A131ULL, 0x67F0568D06911DE0ULL, 0x1C4293A543A4602CULL, 0x97661134C9F1D07FULL
        },
        {
            0x99EB186BEFAF81CBULL, 0x24E709B6832DCAFCULL, 0x6AA76D1C47C16FC7ULL, 0x1C3EE8E143B9A902ULL, 
            0xCD44DC0B9ECDAEA7ULL, 0x2332D7125DA5BED6ULL, 0x318C0910D5063E4AULL, 0xD60478C1DB4E996EULL, 
            0xB72FFA1E9203B8B6ULL, 0xCD0027D6949AD621ULL, 0xDC59E38505F61A1EULL, 0xCE9B0695E1840559ULL, 
            0x0282D9A36D48D9F1ULL, 0xE9A7A1EEC15A1229ULL, 0x079187E119E44C83ULL, 0x188985EF5F1CD5FEULL, 
            0x8DFAA9D52E38171EULL, 0x851301C69F5B26C3ULL, 0xCE5EC78BD9C7FC9FULL, 0xD0977234B1E9E2EEULL, 
            0x6B81C67AE4B56247ULL, 0x9A333BB91FD80907ULL, 0x550F07A5648DC593ULL, 0xFE1CD18B21FD8546ULL, 
            0x66F9A425D760FDB7ULL, 0xB5EC497BDD092445ULL, 0x59C79C3AE920B2D4ULL, 0x1B085E5D06694C0CULL, 
            0xC77E537D27989939ULL, 0x2A0499FB8A591188ULL, 0xB741C3E1B7ED7CF8ULL, 0xC89E79BF65A5CD43ULL
        }
    },
    {
        {
            0x0DE324F0B6422F3FULL, 0x89490DA98407D451ULL, 0x6B5945305B623600ULL, 0xC493F20E4CBFE5B5ULL, 
            0x27E2A529BB8C02ADULL, 0xE10CFF0993DF835BULL, 0x354B2C27732A07E2ULL, 0x9B9A36531A126AFBULL, 
            0x3AFF56F81E83BE89ULL, 0xF91602DBDD52A581ULL, 0x9FC531EC23DE253CULL, 0x956BC50A7A96C490ULL, 
            0x32CA2E303DA99ED0ULL, 0xCD4C8799414BC73AULL, 0xD9F40A0B1548EC19ULL, 0x9D96083AD230B1F6ULL, 
            0x44D0CCA0DD2DF031ULL, 0x1D42235B90F5360CULL, 0xEEC4CE4BBA3861ACULL, 0x6C5A9F36231C3031ULL, 
            0x0C38FFB288030B16ULL, 0xFC4EDB3B38230876ULL, 0x8E59B92D77C1E3EAULL, 0x8C7F74BE56F06B39ULL, 
            0x4BCBFDB215D511C5ULL, 0xCA12ED3F0128EA58ULL, 0x3838013B1EBF0C2FULL, 0x40C8FB394BDBBCE1ULL, 
            0x363A3310AFE8DFDDULL, 0xAA0A42E0C9A9821AULL, 0x0612DD5315F65A56ULL, 0xA480BB70728EEC92ULL
        },
        {
            0x55C580FC8231A65FULL, 0xB9DD448B843B2B1FULL, 0x322FD08DD6AE853AULL, 0x74DB1E920A5B7684ULL, 
            0x151032E28D80DF8BULL, 0x3883A94332F96D43ULL, 0x1E77342C3041D008ULL, 0x24D19404E42748AEULL, 
            0x1FD44850D7DAA34FULL, 0x21F50D481F2FE370ULL, 0x0B43C1F79A6E0F64ULL, 0xBFF6DD4F8FC8F07CULL, 
            0xB6B3B7DD48C7500EULL, 0x29374366E5BAFBE8ULL, 0x986712EF7427F720ULL, 0xF8A79E284C207268ULL, 
            0x9E55D0D2A451EBB9ULL, 0x2841D21277148A27ULL, 0x9BCD7BB538FD8513ULL, 0xA2CED282E6B0D672ULL, 
            0x56382564067AF296ULL, 0x1EA232E3CECD7C0DULL, 0x74D522E53920926AULL, 0x9ADC5DD7AC95EC98ULL, 
            0x67F5BD50674C87B7ULL, 0x5B3895F4A93EB044ULL, 0xACD9390ABE30F256ULL, 0xE9C4CB8FF8303AB6ULL, 
            0x6DC4FA53F2DC9A5DULL, 0xDA9408F512671544ULL, 0x9F637DB4B18D84FCULL, 0xC774F2AF0B5A3DB1ULL
        },
        {
            0x8E2DA6997D7D9C64ULL, 0x7ACEBB8D1E4FB473ULL, 0x962AECB064B00069ULL, 0x9851A2C86FEACEE4ULL, 
            0x90A22A0EA630760CULL, 0x45B6C7EE07B4A295ULL, 0x55B7CF3ED9E83C12ULL, 0xC657EF78BC268477ULL, 
            0x337C993D7DE7F38EULL, 0x138E8D9D9363B9EFULL, 0xBFCBF8E000054215ULL, 0x7DC11321B0B9043AULL, 
            0xA3491B52FB51B8ACULL, 0x0D9BAA39B9F91FDAULL, 0xA86C4AB8067BC703ULL, 0xCF98022181DB7BF6ULL, 
            0x9AEA9803D1578758ULL, 0xFCEC4676D7F1FC66ULL, 0x738696D6329275C5ULL, 0xBA2079E79D52FA2EULL, 
            0xDE15805268A0A33CULL, 0x86ECA9E091913CF1ULL, 0x499E5E8F6C374ABCULL, 0xE873FC67F38F0856ULL, 
            0x90D51CEA6A0CFA15ULL, 0xDAAB0E28E22E0E99ULL, 0x85A2656FF76F763AULL, 0x83F45979EF8DA63BULL, 
            0xAE2363059576578CULL, 0x5CAE006852CBBAE2ULL, 0xC5C70818B7CA0C51ULL, 0x603D315AF9CC201AULL
        },
        {
            0x4BF8C1F3FA4210EAULL, 0x0495D9A79C839A0EULL, 0xDB07F770A8532891ULL, 0x52CE156623306F8EULL, 
            0xF75377B432BC7E6FULL, 0xDA8F5BA6E9C15D24ULL, 0x23A3BB4D7BD60F33ULL, 0xF02A185B1AA2BEF6ULL, 
            0x2B18DCA134498F07ULL, 0x50A139C0928ADFB6ULL, 0x1C58A275D5E39F1CULL, 0xF5BFED9BD5EA8A17ULL, 
            0xF4B23A3A30DB6207ULL, 0xDAC16AE8A471EF35ULL, 0xFAD5DD6721D90C56ULL, 0x921FD33225105FA7ULL, 
            0x804E0F0461E9749BULL, 0x862EEA08A6747CF9ULL, 0x45C07F1EB3E7DE68ULL, 0x4E5CD85930F39B60ULL, 
            0x1EAC20D2E284C942ULL, 0x6AC3662ADF6FC6E6ULL, 0x9D0873D509F74F88ULL, 0xA79BE0FAEAA0E409ULL, 
            0x4C9E56FDAC295E97ULL, 0x4ABA9100546B7AF7ULL, 0x4D191703AA6A89E5ULL, 0xAD769FD630B1C578ULL, 
            0x86A45834D0045904ULL, 0xBD34D1DDD17ED6E0ULL, 0x39EFC1781953A0C7ULL, 0xAA981425264C40ADULL
        },
        {
            0xF44C718094771D1FULL, 0x576D06BE2D98329AULL, 0xE48CA6F588478446ULL, 0x468CD322C158DBE9ULL, 
            0x91B8D6FB5E30DF67ULL, 0x61DA2DD1259C2E08ULL, 0x805AF61C42405150ULL, 0x1484FEF2399CEAECULL, 
            0x36326368B66DC4ACULL, 0x30C496133367D99FULL, 0x4AE1FD4FBED80C38ULL, 0x35916E401133D32EULL, 
            0x18779D4F1DD43628ULL, 0xD840AD62CBA7E135ULL, 0xDE5ADECDB33F7B3DULL, 0x323B16CD917E37A8ULL, 
            0xB64D57DDD6FFEF43ULL, 0x36E6A83DADD68A35ULL, 0x40A568DED12A7623ULL, 0x040D8DB74CB6268AULL, 
            0xFCFFD3DA0FBFF3F0ULL, 0x767275C31F894DB2ULL, 0x8F9229A563508359ULL, 0x9BD90F8FBBABD1FEULL, 
            0x03B43C3A1D02A657ULL, 0xBF01E6A0E073DE69ULL, 0x3204708C4EA7E5B6ULL, 0xEA84A71E4660BC9DULL, 
            0x3C5DFA01A0CC1030ULL, 0x7469727829ABD458ULL, 0x1E2DF02FE10C41EEULL, 0xA51EAD097BB4D269ULL
        },
        {
            0x40599C05FA0E15CFULL, 0x9C80B56CC0ECBA95ULL, 0x96989701D8DF710DULL, 0x12CF141CAA110349ULL, 
            0xA4849E30150A5383ULL, 0x9C5CD522F50255BCULL, 0xA32DD6FCEA1DC244ULL, 0x0B7EC4DABF49564FULL, 
            0x919AAF45F81357F8ULL, 0xED480C576A97F2E2ULL, 0x3C8AAA17EF4E2E1EULL, 0x2B500508BD79285FULL, 
            0xF0E548B6AE3AA420ULL, 0xDDE37F3AA75AB02DULL, 0x1814A5836FFEA985ULL, 0x171E6259AE99847EULL, 
            0xD2BC0B9B0DA180DCULL, 0xB4E31F5012A622BBULL, 0xA47848CAD74E1E3CULL, 0xB985445B49FB9AC9ULL, 
            0x901F75F53474671EULL, 0xE038D3F164DFE644ULL, 0xDBE9E2E6EFDA7173ULL, 0xD83094322D868470ULL, 
            0xD4DF9E28C1D0DFCFULL, 0x89D0007530121257ULL, 0x0B11301C50BDDA39ULL, 0x1DECE4E4734A5CF3ULL, 
            0x724E6179056664ADULL, 0xE6CDC38015F032E2ULL, 0xD502F94404267B7BULL, 0xD8C7C9CB80B40DE0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseCConstants = {
    0xF75F1B5EF63B4C86ULL,
    0xFFBF76E6A8C81F44ULL,
    0xAF8EB86C206A0A02ULL,
    0xF75F1B5EF63B4C86ULL,
    0xFFBF76E6A8C81F44ULL,
    0xAF8EB86C206A0A02ULL,
    0xDEFF6429406442D1ULL,
    0x0B67CCD2369206EFULL,
    0x92,
    0x51,
    0x0A,
    0xCF,
    0xEF,
    0x9E,
    0x58,
    0xB8
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseDSalts = {
    {
        {
            0xF55A75C2AE4AF66AULL, 0xCA0BB3BDB1D7B613ULL, 0xF0605F1DD7557B93ULL, 0xF9A2D2550298D37FULL, 
            0x472A6FDCA5CB3B8DULL, 0xCC0ED283EF75D2A9ULL, 0x18EC377E11BCC2EDULL, 0x5E0DB4CDABE0C945ULL, 
            0x831F2E9358F74EA7ULL, 0xD9D1086D10172C97ULL, 0x4D4234874F181FEDULL, 0x17470469AEB077F5ULL, 
            0x9E58615D8F7C7C54ULL, 0xBA94D5E162A3625FULL, 0x6B3280214F013F18ULL, 0xE8BC401DAFE3701CULL, 
            0x940CD34A56662F14ULL, 0x84EEDF6B765EDF4CULL, 0x030E661BF4FAB5E0ULL, 0xA3F2F22AE5F05A9EULL, 
            0xB61F33D5BA3B7AC0ULL, 0x535A07BF46F7438BULL, 0x6273918AF7618016ULL, 0x3E2E1FD54702724CULL, 
            0x3888DC3A9AFAACBDULL, 0x0C492F0BEB021291ULL, 0x26371A26314B32ABULL, 0x5469C4BAC992BA6DULL, 
            0x8D2176838618CB04ULL, 0x49007005182664BFULL, 0x348A747210F13157ULL, 0xF4E75DB45227A405ULL
        },
        {
            0xF44B00C18213486AULL, 0xF75E41CCE4094AD9ULL, 0xE4E273E16EFD2BC4ULL, 0xB1F2131006AC1052ULL, 
            0xB7C022B0E23914BBULL, 0x6BC2E259E29395C8ULL, 0xF358638C7F1567AFULL, 0x9E379510455D763DULL, 
            0x7D48C8C683E15CE5ULL, 0x509BA9303684C030ULL, 0x571DCC98B49AD2AEULL, 0x55AA6CCC1B86A723ULL, 
            0x1CD63D94426B85F2ULL, 0x939DDC3EBE6B12CFULL, 0x653241B238CAA17AULL, 0xE7DCE9FEB5024B49ULL, 
            0x42309A33FDA433A5ULL, 0x4D60AE8F014A2146ULL, 0xC41BF5F8C58C88A4ULL, 0x1E468C3ABAB2D01FULL, 
            0xD61EC5BABDFE3F66ULL, 0x7702F583CD447FA1ULL, 0xE619BC0E2B007192ULL, 0xD5961B15EE349090ULL, 
            0x2FCBEB9FF65DF91FULL, 0x278D020A97F4F3D4ULL, 0xB1C0093C19618A78ULL, 0x5A2C553A3F66935EULL, 
            0xD90003199A2B3EFCULL, 0x460A829780695D1DULL, 0xBD4A5511F1D42CFFULL, 0x1EABD3CB6F375598ULL
        },
        {
            0x3E661E2CA41F3F91ULL, 0x371D8793AA9C8A8FULL, 0x4980E1853620106FULL, 0xDD91CBE9AD48F740ULL, 
            0x5405900A1AE31D98ULL, 0xAD69C89B774B0811ULL, 0xC3CDB569CB478B7BULL, 0x7AFDC1F241B45239ULL, 
            0x8BF79886AC3694A5ULL, 0xD06A6C736FE0B522ULL, 0xAC52E09F24ADAC2FULL, 0x660E3FCFC24158FFULL, 
            0x7472690D32CCE4C0ULL, 0xD735B531CF59B635ULL, 0xCC666D28A31C18A7ULL, 0x8B60CA5CFAE02083ULL, 
            0x913B097229BA5116ULL, 0x8B00346C109C7792ULL, 0x445E85C9B2EE9DB3ULL, 0x8012DDDD362B7F15ULL, 
            0xBAF98EE76A7DD3CCULL, 0x4AE09499CF5E41C8ULL, 0x2437E71FDE532B9CULL, 0x27185B34CB33234DULL, 
            0x17D69C991968412BULL, 0x038660EA75D32705ULL, 0x586ED08B21BA87DFULL, 0x85E3EB46F05294FEULL, 
            0xFEEC5F7191559A9AULL, 0xD6664900BD6C14FCULL, 0x87FDDF290EE1C9C1ULL, 0xA3B2603A57A2022EULL
        },
        {
            0x9CA0EB50BEBABBE3ULL, 0x912A712FB2B1A61FULL, 0x25E4B4E4FAC4885DULL, 0xC3FE1BC1C710209CULL, 
            0xADE19CEBFAFED122ULL, 0x50AC6C89301CBDB9ULL, 0x8AC3DD761B3C50A6ULL, 0x85CFC6DF7D06AC5EULL, 
            0x9112025CE627E060ULL, 0x17CD0AA400189409ULL, 0x27B5A4B4247A224CULL, 0xEB2234A6BA2AF4F6ULL, 
            0xA579DFB71B6A8F5CULL, 0xD12032B8EC0AD5A3ULL, 0xCC2385E2112C9CDCULL, 0x979DE94C2785EEDBULL, 
            0xCAF730DF229A58FCULL, 0x7A590E606D0D0703ULL, 0xEB28B31A7AC58766ULL, 0x22EAAA9F66BAFA02ULL, 
            0x007CF15586DD8DB0ULL, 0xA73EAA3F94CCD48CULL, 0x9E4B56EECF2BA40FULL, 0x2F81C828FCA3F579ULL, 
            0x0F8A788E5C3C171CULL, 0x68234B83712AB9B5ULL, 0xEC965DB8EB61209CULL, 0x49CB8FF417896C27ULL, 
            0xFA180002910A8C08ULL, 0x3C13B872DBCDDB9DULL, 0x97D4C0F16AFA0B6FULL, 0x64FB154017B00ABEULL
        },
        {
            0x43A5B5E2842F2653ULL, 0xF5D655249C75225FULL, 0x98E7C52C59C9341CULL, 0xF7DFF04A234B88F0ULL, 
            0x3C770890AB064705ULL, 0xC352F9BA2B45665EULL, 0x497991A505DB63ABULL, 0x9C35AEFD05B5CAD3ULL, 
            0x650570BF1E179173ULL, 0x0D119F40393FD86DULL, 0xAAED1AE035EE4697ULL, 0x2215B432D957BCAFULL, 
            0xB6558C05F7FE6344ULL, 0x8BA7E0BA420FCF34ULL, 0x3F2EADC8786AEFF0ULL, 0xFDD677F090EFDE52ULL, 
            0x7C61E86B84B9A35CULL, 0x695F565BC99599D7ULL, 0x838538CDBB61C7C3ULL, 0xE4A226A787BC9B26ULL, 
            0x3BD119225E470790ULL, 0x08A58E909F32FC56ULL, 0xF4DD93BD90A54B8BULL, 0x7449BCB23D511B56ULL, 
            0x0E2812004C9E74A5ULL, 0x7A76294ACF01C65FULL, 0x471804AEDB7334D8ULL, 0x1D2FC200592A48B5ULL, 
            0xB6FA7D0A6A1A1D8AULL, 0x7AFDB572E26718D4ULL, 0xC0B947DBDFAB2CBBULL, 0x7067ABC4809908CCULL
        },
        {
            0x3A12DD90C6AB6FB4ULL, 0x485F707AA06381E4ULL, 0x786970992967007AULL, 0xF8FEC8BDE9DCA62DULL, 
            0xA080870B621220A2ULL, 0xB0C8C2A5D98FDF1FULL, 0x170914283B4B49C1ULL, 0xA40D1AC99BED8947ULL, 
            0x4525857715A8669DULL, 0x4038A4D8689D1CD0ULL, 0x17AA84D27B22A183ULL, 0xF2E2E4609F475535ULL, 
            0x7F08F93A1481543CULL, 0x8EE5239C643F2CF9ULL, 0x87734D4833300FEDULL, 0x820B5C6307EEF8E4ULL, 
            0xC2AC740CAEB1B4B5ULL, 0xE80ED6368B9AA8EEULL, 0xD716089BA8DFFE4FULL, 0x2BE1AA676EF1BE74ULL, 
            0x88F295CC4699B000ULL, 0x58073839652D59CCULL, 0x786CDA5E63D804C0ULL, 0x40616C928F75354BULL, 
            0x972178E65032ECEBULL, 0xD46C82330B1926E7ULL, 0xCD2F6862A295B6DFULL, 0x718AFF0E15C00BEBULL, 
            0xA1261A573BAF3E86ULL, 0x5C67C0045BBA411EULL, 0x1EF5D740F27B3401ULL, 0x85875F1246A408E2ULL
        }
    },
    {
        {
            0x94E202D735B3722BULL, 0x866810CD64075396ULL, 0x2BFAA3191970A00FULL, 0x605F2E824AA0FD02ULL, 
            0xDDA840E179D7F129ULL, 0x7159D22116FF25CEULL, 0x9AF7DA79E627DB29ULL, 0x78AD3C7A289879B8ULL, 
            0x19141FCA05CA7EB9ULL, 0x4F5166B9DC5544B3ULL, 0x32D6157CFF44F77EULL, 0x8985CD74C72A6476ULL, 
            0xE3B398DA6C4789E2ULL, 0x8BA0E812B56C0100ULL, 0x4434551074B06EEBULL, 0x98761506AC382C7BULL, 
            0xE606A79D217226A5ULL, 0x614AC64443DDADF0ULL, 0x13C9F2C799BB1E3AULL, 0x86B4B76939358CFBULL, 
            0x180EE3AB9F76EE18ULL, 0x500F0DB4ADD72995ULL, 0xC3BD8576234D0086ULL, 0xF8D4309553D290FDULL, 
            0xA67F6BBACA09FB65ULL, 0x8769026057B78C45ULL, 0x80B50F869BC20274ULL, 0x350B309FA3351908ULL, 
            0x39DDAD5465D06633ULL, 0x831D068F13692C64ULL, 0xD8522E6DCDD96A03ULL, 0x74B446EECC84E974ULL
        },
        {
            0x834DE02275FC3AF9ULL, 0x3D7BCEF24F089976ULL, 0x854BF7649E5E3407ULL, 0xB618362FBF10290BULL, 
            0xB513C7CC871BCDE9ULL, 0xA5FEC42B62A2AC8BULL, 0x22E4F6DF7BF376D6ULL, 0xDB61B19D680282F7ULL, 
            0x6AF05F1A39B26964ULL, 0x3C23872B9C36F490ULL, 0x107570DC46D80F7CULL, 0x4AD5EEF224EF9288ULL, 
            0xA5C8C0CE2DD32163ULL, 0x697C8ADE3164483DULL, 0x7152C3D8AC77CCB1ULL, 0x955A1EFB9866D95EULL, 
            0xCCC9422004E2FA73ULL, 0xCA990C94E07816D7ULL, 0x7157D81D049ABB4FULL, 0x0C30591B4414F7B3ULL, 
            0x936D50256C38A91BULL, 0x70C675D2884551A4ULL, 0x5639438D687209A9ULL, 0x4B27F0D8D7775807ULL, 
            0xF8299390507CA704ULL, 0x7C464FD379C92C3CULL, 0x26592620DB84B47CULL, 0x347F04912FBAA353ULL, 
            0x6B608F565B6F3B2EULL, 0x721C25B8A87C3BF4ULL, 0xA0586210C673CA3DULL, 0xF8147ED3FA22AA4CULL
        },
        {
            0xE73FA26DE602C21CULL, 0x88B105D8A28CE55DULL, 0xA7A5BE498ED58EA9ULL, 0x72C691DCE0037C07ULL, 
            0x15B3F7C2545A52D1ULL, 0xE500A0BFBFD73DB7ULL, 0x5EC13A0510104374ULL, 0xB9071EE115FE6BDBULL, 
            0xA23FB35CDEA2F7AFULL, 0xF4EBE56208D521DDULL, 0x41F3FDA5BE9FE1DBULL, 0x0AEEA3AF1897309DULL, 
            0xCB764F38F1BF1045ULL, 0x1C3F58D73A4E5F76ULL, 0x9733B2AD22EE2C3DULL, 0x8E9ADA5A6C2DE8B4ULL, 
            0x6940974417617D12ULL, 0xC205380A57D5389BULL, 0x1982762B302D9416ULL, 0x3FEDFF1479348BA5ULL, 
            0x54771B84BB849B18ULL, 0x54F20A0861457334ULL, 0x6609BF4F304127F9ULL, 0xCD624C8AE3A42F32ULL, 
            0x571FB10247F24E62ULL, 0x0F7BEAC6CE8A2120ULL, 0x59A18A7A5D4EE928ULL, 0xE54436FB6D354CAFULL, 
            0xE5ED84033D88D237ULL, 0x4A155B542F1454AFULL, 0x381E529ABC543985ULL, 0x2960A25A23B6C940ULL
        },
        {
            0x13BB7D187C540210ULL, 0xC7CDF16D9B760144ULL, 0x609F1B977AC202A7ULL, 0x2E51ED38556AEA29ULL, 
            0x6BB5D34C8242154FULL, 0xF0059D4E6C33509FULL, 0x8226E82A3F9B9930ULL, 0xD98C188A73052E62ULL, 
            0x379D65F8047E08FBULL, 0x82816488274C784AULL, 0x1FC2A90FA65B756AULL, 0x181F5AD0681D3483ULL, 
            0x015003BB9F4B2D88ULL, 0x2B287741EACA859CULL, 0x304F25118BB84C90ULL, 0xF890062CBAA7430BULL, 
            0xFA53B11F9BEA2988ULL, 0x9AB3AA5465E064CAULL, 0x0B07A57158960CB9ULL, 0x0E05F5D91B186C27ULL, 
            0x50E7AECFCCDB2EA8ULL, 0x879F556B2DE51643ULL, 0xF9F798FB492FC9B2ULL, 0x942B9F9FED1A0CF2ULL, 
            0xE31828AB60C45396ULL, 0xBC6CE746252382ABULL, 0x108B62B336BD4D80ULL, 0x02BC7C53F3F648C5ULL, 
            0x2A00F53A33FE2EA3ULL, 0x5827D2CC678D037FULL, 0xB10E449B58CD19FFULL, 0x866D1B25AE8897AEULL
        },
        {
            0x7B2D742451D337C4ULL, 0x3816CD3737BFBD24ULL, 0x6E4CE3AA3F7032EBULL, 0xD3E202543A007606ULL, 
            0xA71C786D10FD79E3ULL, 0x622525D9270B1CF5ULL, 0x66C2A054A8E8FFE2ULL, 0xDB6853521264B22AULL, 
            0x8B40341F5603F00DULL, 0xB6BEE2ADFA3D36C4ULL, 0x23F6EB3E7E2920EBULL, 0xA9F30C3ABAD8D9BFULL, 
            0xF315AAEC73F2D3A1ULL, 0x8328B0430E253EC2ULL, 0xECBABB727B09DCC5ULL, 0xCEF7338CA3CE1F2BULL, 
            0x973F97A78609B9A7ULL, 0xF444A4756766E260ULL, 0x3DCB81D97442F438ULL, 0x4769F23DAF0BF28CULL, 
            0xEE01D6E73246C4E9ULL, 0x59BA65219ACCB40BULL, 0x4105546333C43BF5ULL, 0x211571BAE5E8625CULL, 
            0x286ED55BD2BC2D73ULL, 0xE626CF3C898732F5ULL, 0x7FD1C606524A468CULL, 0x6081EBDFE1255FB2ULL, 
            0x0F84CBBED34A06E0ULL, 0x62424C6B50D67057ULL, 0x7C68E55707BA4781ULL, 0x5639C2FF310345A1ULL
        },
        {
            0x798FCFC7DE760FF0ULL, 0x8851265D856C5453ULL, 0x73F41CBF6AA95C3DULL, 0x9666771E14980C85ULL, 
            0xC759CED809A17170ULL, 0x9A9B9EADF6AE82ACULL, 0x082D3194C4CD1670ULL, 0xF74771A27793D6B5ULL, 
            0xE2E7E9097DC9A468ULL, 0x534A56A351635D91ULL, 0xEB4997765F25333DULL, 0x4387603407EF514DULL, 
            0xE03A1B501745E699ULL, 0xEE050E17FEDE49FFULL, 0x4EDFFBD1B6E521CBULL, 0x1EF2F9E1ED5676AAULL, 
            0xC19DF298D68AF3ECULL, 0x7298112B3D4FB47BULL, 0x49E51E7EECB0047DULL, 0xBB52E745E9ACD559ULL, 
            0xC38390E542E13C81ULL, 0x1832F03457F4BEA7ULL, 0xDC359059CFA2A6B5ULL, 0x48C42322168458B2ULL, 
            0x621F74AB7E253D43ULL, 0x270EA4D445AE1DE5ULL, 0x32EC5736ACD8FF19ULL, 0xB1D8402D64103221ULL, 
            0xB63BA99B0EF849BCULL, 0xCA6A68651A46D43DULL, 0xBBE7ACEB86F662C4ULL, 0x6FCF4C053D18DD71ULL
        }
    },
    {
        {
            0x62D34E7381AB6D22ULL, 0x92DC2B19A09CA9F3ULL, 0xA3C49CE4F94EF371ULL, 0x06EB33040FAE6677ULL, 
            0xCC6278B32A0577BEULL, 0x103FA050578EB3DDULL, 0xB62D437CDDE8F84BULL, 0xE34B3909D36164D9ULL, 
            0xC77F477737BE3847ULL, 0xB4CABB702EF98EE9ULL, 0x722D8F1D25B1F21DULL, 0x9708529A941426F6ULL, 
            0xC4AD03AE1C3F4A52ULL, 0x299BA5861D5E1E39ULL, 0x5B8614AD56314F2BULL, 0x7042D1D78D51D5EEULL, 
            0x1474420143C1946FULL, 0x6596CAE76DC427E2ULL, 0x218E68AC901C6C4DULL, 0xE1D1F23B1514FBFFULL, 
            0x734911E7BCC31F7CULL, 0xA12D295B9A3C337CULL, 0x94D3C66CBA3D15DFULL, 0x920B95324469F72AULL, 
            0x43C02F5FAF8C0463ULL, 0x7AD194CCAF4AB6D0ULL, 0x4BA73FCCCAEF0DA0ULL, 0x1FF3067E4E3D1035ULL, 
            0xCDC63E0E5E59FAB6ULL, 0x3FF29E570F4A79ADULL, 0x713B5CB0637C9AFBULL, 0x766B9FBEDAF0BF33ULL
        },
        {
            0x958D2700DCC9098EULL, 0x1C12E334427843C1ULL, 0xA9FEBEC652E25D15ULL, 0x800F1DFD79B35625ULL, 
            0xF71B2508A6F5D258ULL, 0x5BE27B8AC0F36E8EULL, 0x358C4B6741EAE5AAULL, 0x1DADA0A690BA6D72ULL, 
            0xD3820BA1E21FFB96ULL, 0x8DE9EBE6D04D5F74ULL, 0x44FE01105828D9E4ULL, 0x63802A5AF52235B5ULL, 
            0x863180ABB0575E12ULL, 0x3C3B894BA6713171ULL, 0x6058A5B11D80D95EULL, 0xC056AA1E031EE4C0ULL, 
            0xD3B01EC869407852ULL, 0xCD06F58E176A9AE9ULL, 0xDACE57EC72F38CDFULL, 0x031CB80C18FC71EBULL, 
            0x2827C785DFC7CC77ULL, 0x0369366005DB13FCULL, 0x14A3D8BA2D495D1BULL, 0x6D0A501A3D9CA4CDULL, 
            0x31D090A0668605C8ULL, 0xC3D218135AD11889ULL, 0xD044877CBE235CFDULL, 0xF0FEBC805F329D5AULL, 
            0x1F84E806CA9F58C5ULL, 0xC94685D3ABC82904ULL, 0x4B09BA57077B440AULL, 0xF40E6253D0AEBB5EULL
        },
        {
            0x1098693132E923C0ULL, 0x3048E4D5F729E366ULL, 0xF26A631F462BBF33ULL, 0xB88B2536085D114DULL, 
            0x3DBDBDE3CFEFD24DULL, 0x9A7DC04C082FA707ULL, 0x1E4A6D477D95B911ULL, 0xE78B74C793E2B440ULL, 
            0x5EFADF8478444F11ULL, 0xC6A4614D7D786643ULL, 0xFEBC86E6FF80F86FULL, 0xB968F0685A3B8988ULL, 
            0x7FB4EB26F10AD720ULL, 0xA1ECF4229ED31CFFULL, 0xB970B0C5113DC5FDULL, 0x9A8B90A5426FFEEFULL, 
            0xCC5B57D1395CB582ULL, 0x0F9935002C7E6476ULL, 0x089C2175A6D50F4CULL, 0x187024D7624618DFULL, 
            0x9DD6B140AF9C2937ULL, 0x618E959B1515AE18ULL, 0x45613961E0A04495ULL, 0x743AF4AF483B49DAULL, 
            0x4454E4FBB83C606EULL, 0xBA28A6557487D16DULL, 0x33EA704EEC1BF1D3ULL, 0x11924097941E3517ULL, 
            0xC2D44F1EF9801636ULL, 0x710359E19155F388ULL, 0x864BB461408F2B47ULL, 0x8A92CF534A201B78ULL
        },
        {
            0x58A893B6AE0BEB10ULL, 0x76E9D80DB11E14CAULL, 0x715BB5835C90E047ULL, 0x7E9072B47AED334BULL, 
            0x19193B2C6335C77CULL, 0xD6EA0E0BB4D41EA0ULL, 0x1F711BD49113A45BULL, 0x95A31AA2128C08BEULL, 
            0xC65AB02C02F0EB1DULL, 0xC5C25B22082B4D09ULL, 0x1224E89BC3A0DEFCULL, 0x2D9CF660096949A4ULL, 
            0x0C3D70E0D09CF617ULL, 0xEA332EF956F3047BULL, 0x464F51BB9FBACD9EULL, 0x6E0917D0E84466CAULL, 
            0x4BB884B5F9AE9AE4ULL, 0xA97FB974B174AC78ULL, 0xFA05397CEC8ABFDDULL, 0xFA841350164C893DULL, 
            0x76808DCB0FB84987ULL, 0x68FE99248DE954ECULL, 0xF13B1712606ADCCAULL, 0xA7A7AE91A5EA8854ULL, 
            0x1A1717D993503045ULL, 0xA09EC24EC0639328ULL, 0xE2C09F17C92BF4BDULL, 0x42461F70F98E09B3ULL, 
            0xB0DE87643219B495ULL, 0xD1FE3087D5972514ULL, 0xFF73EA048995C3C6ULL, 0x301FBF78C4BCE803ULL
        },
        {
            0xC0C3783D0CB1BD7DULL, 0xD66916351A9F84D1ULL, 0x2966F07D64EE3C44ULL, 0xA6D8343DFF9FFC5DULL, 
            0xB8A77BA782E5193BULL, 0xF2D04C5203A72DE7ULL, 0xC11DFD620CD7E632ULL, 0x4B44A333F94EA7A2ULL, 
            0x778CAACC9FB274FCULL, 0x010303914FE0F7C6ULL, 0x937BD8B499AE996DULL, 0xDCC0C607BEB7294DULL, 
            0xE6F06C0E76CB1C7BULL, 0x87AE3F5D9E880167ULL, 0x3AE64FE56EAC9462ULL, 0xF3B5DF9A0FEEB9ECULL, 
            0x0A14114420DCC4F9ULL, 0x498A9000D63DA35AULL, 0x80391D74D26DEEDFULL, 0xC2EEDC5E8B2C844DULL, 
            0x29E71A519D1E7ED9ULL, 0x5995F6E17B670C92ULL, 0x7B4F3A068308A233ULL, 0xA55D7C280E8D9EBEULL, 
            0x6234CA0A11257537ULL, 0x769343FBB2DD881BULL, 0x3DAAC1A6FC46755CULL, 0x01E1C1E889A94459ULL, 
            0x2683A81E484A07B9ULL, 0x42E56A6EC250CF41ULL, 0xA5F6072D9AFA8EC1ULL, 0x101D09414C1A6954ULL
        },
        {
            0xA6B01565789F1D90ULL, 0xE50EC2D83FEA41E2ULL, 0x97EC5BE82B6C98BBULL, 0x920E2428390C911AULL, 
            0xD6952A549DDE8C58ULL, 0x7AC731EDC8BA00F2ULL, 0xFAF7D0B65EE52EA0ULL, 0x6A4DAF350E258002ULL, 
            0x8D99B6DA5E1EF8B5ULL, 0xEFE601CDF9147E4BULL, 0xF7826C05F4C7EF2CULL, 0xFD7868420AE16499ULL, 
            0xFC746C1803188525ULL, 0x67ED7F59E2BA6ACDULL, 0x8B1EA44CB148C16AULL, 0x205F569D529893CEULL, 
            0x01E5870C81EE9E6AULL, 0xE8DF3B426AE89E56ULL, 0x1FF5069F37E88CBCULL, 0xF6B6B4C6419DEFD7ULL, 
            0xBB1EE4AEC639B9BBULL, 0x63701EB206442E20ULL, 0x5C2E96CFBE0B1ED7ULL, 0xF354D5809ADA5595ULL, 
            0x22576EB61E1271ADULL, 0x1C9423E7B6FCF336ULL, 0x57DB7F40D9436736ULL, 0x8A20033C65061262ULL, 
            0xF3016D459D7B83FEULL, 0x57FDE95A213294AEULL, 0x4EBED498BCC0317CULL, 0x439F74297B26936BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseDConstants = {
    0x7E4C1196338EAEC8ULL,
    0xF2D0E9BE7C5FD6D5ULL,
    0xADAC8D5D5A1A6573ULL,
    0x7E4C1196338EAEC8ULL,
    0xF2D0E9BE7C5FD6D5ULL,
    0xADAC8D5D5A1A6573ULL,
    0x6012F3C6783348A6ULL,
    0x7457A33F5168A8E2ULL,
    0x3B,
    0x18,
    0x40,
    0x21,
    0x4C,
    0xC8,
    0x99,
    0x1A
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseESalts = {
    {
        {
            0x324D08E649257542ULL, 0x54B3105F42C51469ULL, 0x0084F988752FAA8BULL, 0x057BF613F46FB0AEULL, 
            0x7CFFB39D6D0F92CDULL, 0x6346C965937A9FFBULL, 0x6FA3D86B846F5C14ULL, 0x0E0CBEC8FFEE2116ULL, 
            0xC67ACCA0A13ED3E0ULL, 0xDCC53CE7265E718DULL, 0x8F1B7A945100F704ULL, 0x320645B4AE0D39C7ULL, 
            0x03E35B86E51F3F59ULL, 0x305C1FC37C5CBC60ULL, 0xF9F83FD6998D5CABULL, 0x2B9F089C829DA142ULL, 
            0x03327DCDA716B1BBULL, 0xC280A05B2ABC175AULL, 0xA06887A162B0D321ULL, 0xA4A295577DFE10ABULL, 
            0x764B7423C1F19BEDULL, 0xA2037342918620CCULL, 0xB3FEDAC918B1E8FBULL, 0x5A2225CBAE9EAA07ULL, 
            0x2CCCBDE62A5CE294ULL, 0xE441901CE5B4B243ULL, 0xBF24005BE26F7CF9ULL, 0x9B762D5B5FA6E5D7ULL, 
            0x756A28C35C7D18C1ULL, 0xCF1D10E236A2D600ULL, 0x8A8C248E547D5D74ULL, 0x889C772DC9CB5BA4ULL
        },
        {
            0xDB7E282491B37E4DULL, 0xC6E414EFB3879B0AULL, 0xEB08DBE7C5168FB2ULL, 0x9D6ED79C4FA20A3DULL, 
            0xA1CF8CE3D3E1D407ULL, 0xE966012C869ED097ULL, 0x7F7E0F0214C2E2F2ULL, 0xEB9A298128236ECDULL, 
            0x870CF67F8E1D38C0ULL, 0x35279CC216B3B68AULL, 0xD78A13E3F0F0ACDCULL, 0x9D240C15A99948DEULL, 
            0x56DA01CB889CC3C5ULL, 0xA86A516A083D8787ULL, 0xB7AD41884C104FD0ULL, 0x2DB150504219325EULL, 
            0xA8535643D3DDD821ULL, 0x4E9F760301878256ULL, 0xA6D79C020061C440ULL, 0xE6A8127A425355D2ULL, 
            0x35ED5815E77394E9ULL, 0x760462CE12A585FCULL, 0x9C9370E112358E8EULL, 0xDA7B91A5EE8DA8D9ULL, 
            0x4096EE110036BEE8ULL, 0x0CFFE90634A3C54FULL, 0x9B34D391224F4A1AULL, 0xFFC8876A85E3165EULL, 
            0x6AD08CE7A0A8A79FULL, 0x0704E7F28649472FULL, 0x4B66770C2C03AB0FULL, 0x681DE34D3E887867ULL
        },
        {
            0xB26E52D9E23A7252ULL, 0x13D4287A9E102519ULL, 0x4F1878539B5AB00EULL, 0x5D1DDE1AC3CA7021ULL, 
            0x9EBC049F59BBD796ULL, 0x0F417C874E263940ULL, 0x64F965ACAC9F43CDULL, 0xA3695F2309360500ULL, 
            0x5F7D2D7C68B4D981ULL, 0xD462FE861EDE93DFULL, 0xB89C9D6EB50D5504ULL, 0x325EC07B6B856FC9ULL, 
            0xD709118238AFCD06ULL, 0x7250BDB832D3A7DCULL, 0xFFA7F12D9B38295BULL, 0x3EC9C6B4FBF22500ULL, 
            0x9E925C3041CF60BAULL, 0xA9CC644461FB0B23ULL, 0x405ED66316293847ULL, 0xC49CFF82777D7CEDULL, 
            0x7CF9168C80BCD1B7ULL, 0x95D4DF4A0D0B7259ULL, 0x25A82046DB36E5B3ULL, 0x4BB8409F6AC74B31ULL, 
            0xCCB63B904B2AEE3EULL, 0xAC9A6415375ACF5AULL, 0x8B5259C9F93A378FULL, 0x687154C644517DE9ULL, 
            0x4688828F481CA044ULL, 0x9E45AAAFC8352901ULL, 0xC2A8E10F9C8D1157ULL, 0xA7FEA6337046AF75ULL
        },
        {
            0xDD22D7E97CF55733ULL, 0x4BAD604B0D016F8DULL, 0xA330781FFC0A6BDAULL, 0xFF844F0E840C6926ULL, 
            0x77B1C5F6946957B6ULL, 0x20CD8F5EA75AA96EULL, 0x0B10080360C2A446ULL, 0xF841BCAAF7DE7A93ULL, 
            0x2C6B2D865FD10150ULL, 0xF630859F430C7A9BULL, 0x83E8BAA2FF40E5B7ULL, 0xFFBD7A2B577DD8F8ULL, 
            0xCACE93E9063BE3A4ULL, 0x6D08CF2674F03F76ULL, 0x8602DFDA75F586C9ULL, 0xE04BF256262DA348ULL, 
            0x772D1DB22B5C59B6ULL, 0xBF416C876DBAB3A9ULL, 0xAE01F79319DB39C6ULL, 0x040F3E32E66C91DDULL, 
            0x735A452E3944DF7BULL, 0x4D092AB0957E2CA3ULL, 0xBBFC701EED7C0F43ULL, 0xCFB3AB87ED334A68ULL, 
            0xB7206C18CFA56FD8ULL, 0x5F823B2694BB0AE8ULL, 0x9675BF7C5C9D66DAULL, 0xB154A8CE629326CBULL, 
            0x33EA56CDADB34B57ULL, 0x7381C0535481A7E2ULL, 0x8739BA49911286DEULL, 0xE7F17873568B2E88ULL
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
            0x20E1D5C31E26EDFDULL, 0xB465B1BD22577EA9ULL, 0x08B5A6A0847EBE0CULL, 0x87046B0336D17AB1ULL, 
            0xBC3503ABE09D3489ULL, 0x74595C8FB92B4C3CULL, 0x8AC0D1C525CC055AULL, 0xDA76ADB912AD52EFULL, 
            0x518C9DDD2A361224ULL, 0xF9FAD82F9CED955AULL, 0xF68A886F5A3AB1C8ULL, 0xD4352629CF77A5C8ULL, 
            0xFF2C9AC8488BF61FULL, 0x49BE7136E1621BDFULL, 0x583218B04996FF2DULL, 0x31E7FF0BD48E435AULL, 
            0x5A3DAAA5B07AD7FBULL, 0x298C156B3FAF098BULL, 0xF051639C99EE8D33ULL, 0xEEE3BCAC8413B68EULL, 
            0x6E6BE52EC596587DULL, 0x453346229944F231ULL, 0x088A9822DA4BA67EULL, 0x0DF1B25A4ADB0F20ULL, 
            0x43C02C547D3DCBFDULL, 0x27B596D67EDC788CULL, 0x94CB7C4E1C13DBE7ULL, 0xF5C60900E76AE95CULL, 
            0x6B2069DAF750617BULL, 0x0BE729607CE09760ULL, 0x30AD29F089F47D76ULL, 0xA9D024D0729D7F82ULL
        }
    },
    {
        {
            0x1B70C1A1BC8A9ED8ULL, 0xF85AF1FC459EA407ULL, 0xF36D1DD79299B57CULL, 0x41B330F2875AA4BDULL, 
            0xDBC44236170FDAF0ULL, 0x182C523C1AAF7A04ULL, 0x440E852CFA6B3CEBULL, 0xC15E3C4E5A4E624EULL, 
            0xEC4C579DFEA0F45FULL, 0x1E8EBC505EBD29FEULL, 0x99FE277156DAF31AULL, 0x40134FC2EC42FB63ULL, 
            0x659810AC29F1D098ULL, 0x9758F40A80D99F8FULL, 0x9B4DA0E46ABAC65CULL, 0x5D00102A056C79E5ULL, 
            0x7A3F059AE452557BULL, 0x46615F2D01042004ULL, 0x31EE12620BA6222EULL, 0xDE03326D37E48389ULL, 
            0x605A4AC6CE211FD7ULL, 0x6C9464D23C36C9B8ULL, 0xFED6CAAD9CB84DB8ULL, 0x1A010D1808BC8F1BULL, 
            0x50407EAF7ED72AC0ULL, 0xC4B437DF16C78ED7ULL, 0x1B57F105956D96EAULL, 0x39C4BE8865672E99ULL, 
            0x80F32F575A67AC58ULL, 0xF31E521E32C2F73FULL, 0x300C3C3FCB286C9EULL, 0x808107DF05473465ULL
        },
        {
            0x9842C5EED52ABB65ULL, 0x3B0F9A4DACA60248ULL, 0xFEEDA7563263BCD8ULL, 0xCF82E558E9B4B344ULL, 
            0xC6B45D4EED250BCEULL, 0x9626F3DA87D6CA9EULL, 0xA4C076F77EEC51B8ULL, 0xB1777FBF3BECE40AULL, 
            0x773D76AB3B50599FULL, 0x76CA870CB14BB287ULL, 0xDF90CAA9D87FA1EEULL, 0x0A77B37E057D6657ULL, 
            0x5E6085966F3A5998ULL, 0xF8A626A7E20D36CAULL, 0x5DAA1FD3B7C29EBFULL, 0x1D1F39D0BBB61DF9ULL, 
            0x2D615A1E78FC9B66ULL, 0x402D5044774278B3ULL, 0x04104EBC5A87FE55ULL, 0xF5F78FDDF2D17BD9ULL, 
            0xB679483367DF7B9CULL, 0xE069EBAC4B4FFDE2ULL, 0xB3650E055BF33E47ULL, 0xFCB44A45799341C7ULL, 
            0x4A8D67D1392B74BCULL, 0x1B5A3CFEC3D99B1DULL, 0x278B4D9CDF458BFFULL, 0xB61BC9DFC8806F3BULL, 
            0x9208E74B0E207676ULL, 0x0857E2236FA792DBULL, 0x59CDD6250D24767DULL, 0x72D4A37A779E14C6ULL
        },
        {
            0xB97C1CEC71244502ULL, 0x09FEE4AD8A9534F9ULL, 0xB975AD91F5908897ULL, 0x75003CAE77AE7853ULL, 
            0x639982527F5E5696ULL, 0x57646ACC47C54FBFULL, 0x41600C82EFFBC4FCULL, 0x70A2703C707CB90AULL, 
            0xB306433966DB1622ULL, 0xCC83680CB25BB294ULL, 0x0EBBD3D1FE06B1DEULL, 0x00F92038D6659337ULL, 
            0xAA582F75A9F8B787ULL, 0x914F3A23056E4A4AULL, 0x5F34303F3A18B13FULL, 0xDCA6C64C150F780CULL, 
            0xFC68C1DF47C013E3ULL, 0x324BD0B055DBCBFBULL, 0x392B5B068D965D20ULL, 0x29294836A43EF49FULL, 
            0x0A60771F23AC45BBULL, 0x74B16E3199DDAB98ULL, 0xB9E802868408345FULL, 0xC4EFC98ED0733C67ULL, 
            0x19F96F37B8ECA905ULL, 0xC2529D2AE75EB5BBULL, 0xAF0CB5B45F27C841ULL, 0x27859A8E298D0C5FULL, 
            0x84572F5C76EF21C1ULL, 0xC2B80A6DE61D4C34ULL, 0x80472CA256D176A1ULL, 0x47A39645EF7BC76BULL
        },
        {
            0x88ED4D89CFC64A53ULL, 0xF2850E962F440A9DULL, 0x2B275482C0F4C8EEULL, 0x39F06AB9FC300FE3ULL, 
            0x3E6FDEF496B87A73ULL, 0x18ABA6EBD551970FULL, 0xE0BBC9E4F74B2037ULL, 0x73354F4F487947ECULL, 
            0xD85A13334A9EA052ULL, 0xDCBBB09D2FDDEA66ULL, 0x47F8822D9F606FC7ULL, 0x205574C063FDAB30ULL, 
            0xF3C8155672B12B4AULL, 0x3C55205021C781F5ULL, 0x33996FD624DB6A29ULL, 0xD5270B76AB13E3BBULL, 
            0x6165F9CF4754AC99ULL, 0xB61A0DE16C520797ULL, 0x49884DF311AF19D7ULL, 0x10109F95C11C4FA1ULL, 
            0xD8B9E3A2E4DCCA72ULL, 0xF8DBFC32A359A4DBULL, 0x5B0AED99A23E801DULL, 0xB7DF00222CD5DAF7ULL, 
            0x0554512AB58335EBULL, 0xF1F6D5A5C9549ECDULL, 0x999096AB33C15FE4ULL, 0x3C0C753A35F05396ULL, 
            0xBE8F236CC21EB2C2ULL, 0x8F44AE05419CE3BBULL, 0xBC0503CE54CF5E7BULL, 0x63043947BED37AF7ULL
        },
        {
            0xFFA820699A509C9CULL, 0x941CCBCC9755BB0FULL, 0x2A6DC1545A76EB6BULL, 0x44B037C144C719F3ULL, 
            0xD5D2CCC34976D714ULL, 0x2D1248C761AA931EULL, 0x9DDB1118921A7B03ULL, 0xD362C86EA4EA178CULL, 
            0x05488B6F1A7D31C1ULL, 0xA52114A668CB8101ULL, 0x9ED44486302A2562ULL, 0x6B36F64576C55900ULL, 
            0x30249EA6B418F24FULL, 0x2FB298CE870DE007ULL, 0x8EBBA72AD15350F7ULL, 0x1DD7528D537313FDULL, 
            0xEB610A20E6A97E67ULL, 0xA52D21AD24C07A46ULL, 0x22A59DF6C7168B59ULL, 0xAC9CEC2980157FF0ULL, 
            0x6C2A9834A7DDB4D1ULL, 0x5B7C1EE613C61408ULL, 0x7A29C8CC23C6D433ULL, 0x1089FCC00648D58FULL, 
            0xA2F104E56F5644D2ULL, 0xBA7D4BF3894A2934ULL, 0xD1462DA719C55696ULL, 0xD4E68D04F92D7E81ULL, 
            0x73905243A8B5ADC3ULL, 0xC2F7505F3088FF21ULL, 0x206B61101DD525DBULL, 0x235455E5E1945FBDULL
        },
        {
            0x6A46256DE8764476ULL, 0xA9BA6F7113C4837FULL, 0x5E9BA78FE0AB9C86ULL, 0x348CA09C3B8844EDULL, 
            0xD898B97F9766180EULL, 0x1EAA5BFD3C5BAC9AULL, 0xD96D804F266F6E19ULL, 0xA9079994CBB31A12ULL, 
            0xD6B9B2B3AB297C9EULL, 0xE4AE4783FCC5DB8AULL, 0x6A01A80D22CB3ED1ULL, 0x63C99122F310FE40ULL, 
            0xD9851A558390F0FBULL, 0xC586D8A7A61DDFE8ULL, 0xE01D6AF8E536FF00ULL, 0x7ED73C3151A6B1CDULL, 
            0xA1393A1D63660E74ULL, 0x885631D6E1D80220ULL, 0x8714CBCADAF3B04AULL, 0x7B40107EC028E0F0ULL, 
            0x6E76788B35A2DC03ULL, 0xB92B6BCD648D8B5AULL, 0xC005D0DAE39F4176ULL, 0x0DAC88C49ED8065FULL, 
            0xF5DCE842863263B4ULL, 0x66BB6027A104106DULL, 0x6E25B45545314290ULL, 0x69C057F9DC268070ULL, 
            0x47FEBCDF50F3AA5AULL, 0x7B424BB4CE5707AEULL, 0x911EFCAF85913BCFULL, 0x137EE42085BBDC50ULL
        }
    },
    {
        {
            0xC9D742D84BA2B1D9ULL, 0xC968751D2D5AFD6DULL, 0xBA46BDFFDC6BC8B9ULL, 0x1F463A8C37353D48ULL, 
            0xAAF72FEB4316B864ULL, 0x8D9EB57B35EA5EB1ULL, 0xE55791A779306AB1ULL, 0xC5484A64C49B348AULL, 
            0x578AFDDE4B0639C7ULL, 0x4F13302B553724E7ULL, 0xDEE0BB2459125BA9ULL, 0x9872485B318B80C5ULL, 
            0x6E87A712F9F5AC55ULL, 0x4FD9DB8503EC2FC6ULL, 0x9384E4D91C0350BEULL, 0x77C7393E2157069AULL, 
            0xF29C2D13B3B3EBB4ULL, 0x5F6D395058D6B0C0ULL, 0xD245DCADC97B9D72ULL, 0x18D625717C4EC0C2ULL, 
            0xD4314B807F060826ULL, 0x05CFCEEAF9573280ULL, 0x1E853402DA4148E9ULL, 0x877447C92E7838DAULL, 
            0x038C066C53A3DCC3ULL, 0x11F47C0B1F461335ULL, 0x77BB3EAAB5CC87A1ULL, 0x0AEBF265D9F71ECCULL, 
            0x912ECC5F363A18E3ULL, 0x697469CE523D1BC6ULL, 0x88D42ACA56E0D45FULL, 0x60DE2E628EAD4BA5ULL
        },
        {
            0x95C8873166A36F1FULL, 0x2E84279606EEE991ULL, 0xD4D14DFCC194F121ULL, 0x5325A6DCD380849AULL, 
            0x2DA033CEDA999521ULL, 0x64FE5DAF84E4320FULL, 0x6F2585F38DDBF0A3ULL, 0x8042807A7ACD4E90ULL, 
            0x92588E474539286FULL, 0x76BFE2D654E3F0D8ULL, 0xDFAD25E0FCED1697ULL, 0x1F7B5B005EB319F1ULL, 
            0x91B624779CF9786CULL, 0x4197E029A8581D9FULL, 0x26597FE81B6E47ACULL, 0xC008D1F6115C3205ULL, 
            0xCD33ED8EB453DF56ULL, 0x24E7A190AC42D101ULL, 0x06C6795D35773F64ULL, 0xF01528F9CA2C85ABULL, 
            0x3CA8F7CBB314AE39ULL, 0x1A6EB0EECB6B2E84ULL, 0x5DFA772DB46B98F0ULL, 0xB9D71C8EB8E1120DULL, 
            0x3700D705A1C5F189ULL, 0xC2EFF5FE0A4426CAULL, 0x01B248ACEEA716DDULL, 0x150D8EED27BB313EULL, 
            0xFA1F3AF3CBEE0100ULL, 0xA3236113BAEE78DDULL, 0xA312EDB984791DEFULL, 0x3DC7AF1984F9EC74ULL
        },
        {
            0x0BCBC44DD0331AA0ULL, 0x15BD99987E58B14EULL, 0x700D62067B984B33ULL, 0x599172897FA0C116ULL, 
            0x891A17EDA34514E2ULL, 0x008E94931D21B30DULL, 0x9331BAC2BCB5BD3EULL, 0xAAC2678DAABE92D2ULL, 
            0x4A551B5B1F704769ULL, 0x131F96A55C796980ULL, 0x2BBB0B99C4142339ULL, 0xC13CECBE1267175DULL, 
            0x3D1E3E1D8759BABFULL, 0xDC18A7B3407D546CULL, 0x50F8ACF21D7F43A9ULL, 0xC227A488F1DAE6F7ULL, 
            0x81755F63E56C0A96ULL, 0x5075877B9618D20CULL, 0x433804D2538D9B65ULL, 0x57D58F209DCA645CULL, 
            0xE80934CB54471BF1ULL, 0x5FE78D843B82CAB1ULL, 0x63834CFF365896C7ULL, 0x24918BBC562C8B1BULL, 
            0xFBB09B902072ACD6ULL, 0x9422D11F3738FF34ULL, 0x02366997DEE93CDEULL, 0x88BFBAEA76040E4BULL, 
            0x420F8A7490FECE46ULL, 0x53DA7DCC06DAB1C4ULL, 0x91A44EA59C61E9EFULL, 0x92BC37EADA9E7B2EULL
        },
        {
            0x36D63E12C9FB77BFULL, 0xDB8BDC639C5B8A5EULL, 0xD90F48E5B87CFD23ULL, 0xABBD59277A93225FULL, 
            0x943E953CBF7953D4ULL, 0x6027CBAEF4DFF466ULL, 0xE970295629B75C94ULL, 0xD8A5D0A43175D5C2ULL, 
            0x9E2476D9D7604CF8ULL, 0x97F7BA980DF898BBULL, 0x6664A57A3A7677E8ULL, 0xFF2605C3B0753369ULL, 
            0x64FFEAEBDA4B1DE6ULL, 0xD69B6F599B0A1BB0ULL, 0x84C6D42C7E03DECDULL, 0x49796B70C7977C58ULL, 
            0x46EA37694EEF565FULL, 0x93E0C6AF5DD03113ULL, 0xCFECBDA6A3917999ULL, 0x064413ECCED8CFB9ULL, 
            0x78846A8A0966BBC7ULL, 0xC65EA41047F754D2ULL, 0x7E0104B575BA0E7BULL, 0xD3D1B17BE21C270DULL, 
            0xD86665DF645DDC2DULL, 0x2009532FD9A8CF19ULL, 0x559429CA14A4EC2FULL, 0x2996F9671CD62F6BULL, 
            0x10ADE2D26CD7E739ULL, 0x1AE060471F11924CULL, 0xA509FA2F0937979BULL, 0x6480C8F99413E252ULL
        },
        {
            0xEF4C97D49687F012ULL, 0xD7C241F8EAB8DC03ULL, 0xEB0CF033E1FA1903ULL, 0x19FE3C9A8458FA6CULL, 
            0xB93069C06AAC74A8ULL, 0x7818B448291DEE4CULL, 0xCB44B2D9990AD9D8ULL, 0x3E785EDF82496DE1ULL, 
            0xD567501B16E657C3ULL, 0x421643B971589549ULL, 0xDD3F670AF65770B9ULL, 0x4F4D5E51B60CC481ULL, 
            0xC4F4DB54620EC6B7ULL, 0xF2FB94FF03F4FFCDULL, 0xD3039A72543641A5ULL, 0xC8A2ACE0BCD4EE68ULL, 
            0x4239B65D316AB6D4ULL, 0x32D25FABCD0C60D6ULL, 0xFF0ED0301F95F75FULL, 0xA1F27ED0C76C8445ULL, 
            0xE5EDC26319705F08ULL, 0x84843B22223E1633ULL, 0x015D9314A7BED548ULL, 0x4F80BCF4A344F6FDULL, 
            0x02E9D3FA90DCFF63ULL, 0x29C197333BCEB277ULL, 0xC91B9D643262DD9CULL, 0x2E04C7746CAC14BCULL, 
            0x89314BB5DDF08109ULL, 0xC905A9E1EEC824B3ULL, 0x2E3B0B66765DFA4AULL, 0xBDCC74D56D17979BULL
        },
        {
            0x35B65BF5C6D99518ULL, 0x2D41FF88DEBAA066ULL, 0x28BDBD43C972D99CULL, 0x7A4EDEAF6E04E133ULL, 
            0xFCA307FEFFAAC8DFULL, 0x271BF21AC4DFF0B9ULL, 0xDA76669CE7D89AF6ULL, 0x02AB1A68D5B3E572ULL, 
            0x7D60A5B8BDCC25A2ULL, 0xD62CF517E451BFC3ULL, 0x6CAAB39A61C58E22ULL, 0xF5403EC0C4AD8D67ULL, 
            0xDD215F556683F379ULL, 0x11F38A8DD8EA8609ULL, 0xFFF7AC60973B8199ULL, 0x9966C8601911423FULL, 
            0x12D2EB2085F523FCULL, 0x9190B9685F0CD191ULL, 0xC5EF31F69F7169BEULL, 0x955C312E423C712AULL, 
            0xE0647874FAB56C34ULL, 0x1042A8DA81A03715ULL, 0x3CC7B4FA5A5EA810ULL, 0x33E13338425FE29DULL, 
            0x170FE8AF3103FBD9ULL, 0x1A270216057DA4B8ULL, 0x840BC36600FF99DBULL, 0x18F0B655B14DE41DULL, 
            0xFDFCA2EB79D947E4ULL, 0x0A38A47AE76BDE09ULL, 0x44C11741C36C914CULL, 0x16B5FDAA5E5014B8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseEConstants = {
    0xBEF7630527748A69ULL,
    0x2DF3762381CE64BAULL,
    0x9E4536CBA44E44F1ULL,
    0xBEF7630527748A69ULL,
    0x2DF3762381CE64BAULL,
    0x9E4536CBA44E44F1ULL,
    0x92E0E8C15596FB16ULL,
    0xF763D489FD1193E6ULL,
    0xC2,
    0xFA,
    0x42,
    0xBE,
    0x24,
    0x1C,
    0x5C,
    0x95
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseFSalts = {
    {
        {
            0x241EA3B8CB583B16ULL, 0xAF934A9FCFF1D95EULL, 0xA008B61A58F3FAA7ULL, 0xA30DB2B5D6AB0827ULL, 
            0x6DA1731DA801C334ULL, 0x10149FDAC0FF2B06ULL, 0x00431BD836440E52ULL, 0x66512895990DCAD8ULL, 
            0x6EE1EF0B71E61A7EULL, 0xCB88EC1256AC935BULL, 0x29A2A846C8DB5C08ULL, 0xF96C90B43B7B5445ULL, 
            0x2C896A37622DA814ULL, 0x4A1959A6034BDCBCULL, 0x3CFD7E3C9E2B8F63ULL, 0x0811C7D8A444764FULL, 
            0xD3422F82CE77F886ULL, 0xBC62DBA6C6B36614ULL, 0xE373AF429969DDCDULL, 0x1D945ED319B30E75ULL, 
            0x4EBB2D35772732C1ULL, 0x0C1EC066D9D232E4ULL, 0xD544F577E4E2D7DCULL, 0x2E062A81C5D828D5ULL, 
            0x52F33093B20BFB17ULL, 0x471901701DB07F98ULL, 0xB7A4923FD6DB2E7AULL, 0x04D727C5E2A85F87ULL, 
            0x1BF39C760E1F3F7BULL, 0x280DF274AE45E0D3ULL, 0x7BB71BF81540E915ULL, 0x22F9C8C80B7B3D35ULL
        },
        {
            0xA55A1C5578270CEDULL, 0x80EFBE6E8216277BULL, 0x9D64B7636770F144ULL, 0xE02079E4CDFCEA17ULL, 
            0x8EFC3879B93F2BEBULL, 0xCEED7922B55FC1C3ULL, 0xC7B9E49405FB788CULL, 0x7C2A8B81D74030CCULL, 
            0x1DD2636C1BD08390ULL, 0x5481883934262CE8ULL, 0xBA582C69FC6EB2EDULL, 0xB90C942C9A1B1B39ULL, 
            0x668AE30B36F219C4ULL, 0x97EFF720D594E273ULL, 0xDD042F811FCF7187ULL, 0x514648265E650091ULL, 
            0xDFF59262CED42EF7ULL, 0x3D3F74C90FDFB2FBULL, 0xD7A89F5309EEED5BULL, 0xBECC73C256569163ULL, 
            0xA1BED9CCFB0E0DBBULL, 0xD98993A227C8872EULL, 0xD0ABE8FE2E2A0CAFULL, 0xD9AAAADD9970C484ULL, 
            0x9A173F1257352D77ULL, 0x7B396BA77D5CC758ULL, 0x231D07C249CF1B7EULL, 0xC50534687C5AFBD4ULL, 
            0xAE118BB7550D2AA1ULL, 0x7421E74E2961B3C2ULL, 0x72631987C43BDA05ULL, 0xE23394FB576B38A0ULL
        },
        {
            0x8ED5069512FFBB97ULL, 0x66CC416BF04BE4B1ULL, 0x673C93789D4E67E9ULL, 0xE5F1A199D9F755D1ULL, 
            0x339CC64E0A21A7CAULL, 0xD36BECF916860701ULL, 0x663F6E741EA19F6DULL, 0xC0B8BC1566F7831EULL, 
            0xA95030E94FA55864ULL, 0xD9E470FCEDCEA05BULL, 0xD58EAC903CA9B62EULL, 0x7649398068293D24ULL, 
            0x9534076213E81AE5ULL, 0xF1D552677F262158ULL, 0x0819C641B77FC004ULL, 0xE36B809AF4230258ULL, 
            0xED795227BDBE368CULL, 0x51F4B99979D82FE3ULL, 0xA3B5C31E39BAE4E3ULL, 0xEC5F6BFB5727C591ULL, 
            0xC79FA87AF7223672ULL, 0x5EB562FF9EEB32A9ULL, 0x76B7FA7A7CD103D3ULL, 0x1C850D6511175CFDULL, 
            0x4132E111E3C42583ULL, 0xC34443BDA148D67AULL, 0x056B390FCC004567ULL, 0x6EFDC1C953E39EC0ULL, 
            0x4DA09CA9DE6CFD4AULL, 0x4E1C362115C393B5ULL, 0xDC9AB0A41F66375DULL, 0xD6BC0D8436A10333ULL
        },
        {
            0xC01198A7493D9220ULL, 0x53DE82D8EA3FB40DULL, 0x0B1C637EED0504B6ULL, 0x13D2BBAED44AD910ULL, 
            0xAD1BC9E0FB9DB4ABULL, 0x12B73F95BBC982D6ULL, 0x6C92927E29335C09ULL, 0x846B21FB533E630CULL, 
            0x81DC5302AA4A7C18ULL, 0x6BB5755D0464FEEAULL, 0x6B10EAD604F3FBAAULL, 0xE3786C5DB7DB9A67ULL, 
            0x1AA7BF32C6FFA5D4ULL, 0x004CA83DCE2A8E12ULL, 0x7244BFC6A9143FDEULL, 0x434A5807186E5E12ULL, 
            0xA273A45378FD7528ULL, 0xB26A8888D72B1DDCULL, 0x39B0DE83424F5900ULL, 0xEECB2A9F5CFA2C47ULL, 
            0xC5D31443A271375CULL, 0x4D8D2B0CE51DAEC0ULL, 0x2BC78779EBD8467CULL, 0x2ACAF7D7419A5DE6ULL, 
            0x5469DCB27ECB4E62ULL, 0xDA10CFC0D1BFD2DCULL, 0xFCD0BFD89374C91AULL, 0x4D0EB5525F237FA7ULL, 
            0xA857B12F1F426F59ULL, 0x8EB2CBF342BE6A08ULL, 0xA697B74A2B425C3FULL, 0x1BB422468124BAC6ULL
        },
        {
            0x5571983323248553ULL, 0xDABA693F87D73C89ULL, 0xC21F88D8E9980CB4ULL, 0xB1AE54D302954220ULL, 
            0x4D2A15D4EF55FE57ULL, 0x2DEFCEFAFAC31730ULL, 0xD5430C0FB9EA7283ULL, 0x68F10D3F04BB6E7FULL, 
            0x6A9E846694A811B5ULL, 0x63F473981A1F06FEULL, 0x2DD1A7342C3FAFFEULL, 0xE8C902924865391BULL, 
            0x32FE2CB008F3BD38ULL, 0x45B42B38E29CE299ULL, 0x1B9D0EFC453809AEULL, 0xD920854E63A50B7FULL, 
            0xC80532E003F0C564ULL, 0x7504897B59121831ULL, 0x644D5794A44F5230ULL, 0xCDB9013BC358B793ULL, 
            0x4CF247B278CBD7B7ULL, 0x55883EB266E7DECEULL, 0xA61A0B5655F74603ULL, 0x7ABB6A9A61BD98EAULL, 
            0x3C6336A1F13F2DCAULL, 0x5F55EC26BDE21357ULL, 0x0BE64D35D7CB5ED1ULL, 0xBA886B55BB318D46ULL, 
            0x4FE5CDC0C00F503FULL, 0x9CD8AC5364449D1CULL, 0x07D33401D638B617ULL, 0x4DD37A8B71AEF653ULL
        },
        {
            0xA99E5791A3E08282ULL, 0xD6ABBBF98DEB4835ULL, 0x6C68EB791DC3EF06ULL, 0x8B9513DFEB03E7A9ULL, 
            0xB7DCF1B3ACB99086ULL, 0xE65E776069752841ULL, 0x6829DDAF8A279596ULL, 0x002DD96518A4BFD5ULL, 
            0xD7E00E243EA11A7AULL, 0x0A239F83F73443B9ULL, 0xDAAEEDA262F41700ULL, 0x68E4EF830CB426B1ULL, 
            0x9092328C12D39072ULL, 0xB01B2EB581F4C505ULL, 0xC6FC3C06D31EF09FULL, 0x3054F911E2734803ULL, 
            0x12E0B7A4AA524054ULL, 0xCA2CD75FE2942AEBULL, 0xA1DBFEC6E02C6452ULL, 0xC06FEC0AC925CE57ULL, 
            0x1F482D67893AF1BCULL, 0x36BF6DC58594E6DCULL, 0x2F3F2347684CEB67ULL, 0x2F8B6B570161EC5CULL, 
            0xFAC7A77678099EC7ULL, 0x3A126876116386FFULL, 0x1139DDEE22B36865ULL, 0x5E5D36A1304F1701ULL, 
            0x7F2729011D56B2CDULL, 0x16975D8FB9DB559EULL, 0x2943FAA0D5B7113EULL, 0xC8C57243FB5B5AB5ULL
        }
    },
    {
        {
            0xFFCDFCF027E59882ULL, 0x4F70CEA94DEC1D86ULL, 0xC314A6F323A33F64ULL, 0xB812486E64659367ULL, 
            0xB63FBBB7B4AE1098ULL, 0x82B163595628D0CFULL, 0xFA69F3E3C56F538CULL, 0x339385B0A2E9B0D0ULL, 
            0xB1C0C06A20635DC8ULL, 0xF5696A58BF48FBC6ULL, 0x2567B54B31F0F5FCULL, 0x0B439B3A189DC2B1ULL, 
            0xE2F7AA3BAC7DECBCULL, 0x67A8019BD8AA7DF6ULL, 0x4494A791B93BBC68ULL, 0x660E0E241FC92965ULL, 
            0x91D7B45F1F697457ULL, 0xCA0F49E6299E081DULL, 0x9DE0D0F62E622759ULL, 0x18EB8D3FCC85275BULL, 
            0xA360751ACB955034ULL, 0x13FB56F6AE6F33D9ULL, 0xC06631C877132AD9ULL, 0x354F74B271E2AFBDULL, 
            0xED8D976C24A08B83ULL, 0xA9C0FF6E9311563FULL, 0x3FA6BE41B74F3CDFULL, 0xD421B20E1CE61489ULL, 
            0xD9F0CE6F82960EB8ULL, 0xD05F407EA9A5F73CULL, 0x73F4BA81800E73AEULL, 0x9357DF3FB31D6DD2ULL
        },
        {
            0x52CAADF84FB89604ULL, 0x430018D188077254ULL, 0x1CB774EFEB71FFD7ULL, 0x7F7D9A44AF8CE0B0ULL, 
            0x31376FEB41C75402ULL, 0x8C3673625B0E5442ULL, 0xCCFA1953210F6BBBULL, 0xA24D7A0C2ED44974ULL, 
            0xD8BCA42970DA8840ULL, 0xC8A3F0427F782EFDULL, 0xD0C43B46D531FCBFULL, 0x16CA59661D0ED11FULL, 
            0x77951EED283F7419ULL, 0xB8787DA55F0DF6F7ULL, 0xFD448E0518C4D53BULL, 0xB2FAB452BB9E0DD1ULL, 
            0xDBF7DED1791761B7ULL, 0x2DF873EF25F169FDULL, 0x1CDAD7529348F24FULL, 0xBDF07C24552CE8DDULL, 
            0x46572C093BE72D1FULL, 0xFDC45EF7F827AE42ULL, 0x1AAFA0FD55E61A1DULL, 0x644691C53150BA51ULL, 
            0xF9DF7C67C8A338CDULL, 0x68D1325C954EDBC5ULL, 0x7EF9FBA632D71CBDULL, 0xA68F3368DB46F519ULL, 
            0xD2DA7468A4B55485ULL, 0xDFF643CE56A08670ULL, 0x18A7EC0C0ECB8599ULL, 0xC682C9D8587EF101ULL
        },
        {
            0xCB3455665F608DDBULL, 0x55BF9C408C61058CULL, 0x2779D5F8BFB81670ULL, 0x4E2398A46AAB2DD5ULL, 
            0x7D56B0AA8B95C081ULL, 0xEDE8D624BF2EFD42ULL, 0x715B31CB9DF1CB3FULL, 0x48BC3FA039A12DE7ULL, 
            0xA3E60ADFAF346F7DULL, 0xA1A7C5BEB166F2EDULL, 0x3C97BD74D8384394ULL, 0x1EDECF51572C0B9BULL, 
            0x8CE335D3C09BAC05ULL, 0xFF4CF5618C9CEE6DULL, 0xDB6B43F947D0AAE4ULL, 0x2785E5A1188B9CBDULL, 
            0x28B03B3B361705D3ULL, 0x301C0FFC8F0EDEB4ULL, 0x4B1FC3CE1733D50DULL, 0x97AC1348D79D56BAULL, 
            0x4F1035122AD96E85ULL, 0xBC2AAB531F60D99FULL, 0x69152CE55FEDEE1BULL, 0xC5EEEF76D987B8E6ULL, 
            0xFBB08B4B44687904ULL, 0xE067B91319EDC8F3ULL, 0xA387832026CDB509ULL, 0x04B049EE5A6E1C7AULL, 
            0x5A7E005965EE3579ULL, 0xF270FCE80F9253DDULL, 0xC90FFCA3CF1F1AA3ULL, 0x84E2EE8548DDB596ULL
        },
        {
            0x1CC2841EB7416285ULL, 0x48B2A84C6AB43E20ULL, 0x53A9838DFBDEE2B0ULL, 0xC979E8410ECA389BULL, 
            0x9786EA41FC5FF58EULL, 0x9E5296697F0A7F73ULL, 0xE8F035EBE9D613A8ULL, 0x3704FEDDECB4B3FDULL, 
            0x7E5BBF977E05E43EULL, 0x61D72A7FBFB05313ULL, 0x88E2F2E5FC01790EULL, 0xD789BF284259EE6AULL, 
            0xAB550B1EC98107AAULL, 0xF6A3FD0B57ABE35BULL, 0x5CF8298214D0149EULL, 0x6491733CEB95CABFULL, 
            0xC3ADB9713EDD5103ULL, 0x9A1B5F4089171DD2ULL, 0x6CB1F2F05D8CDB1CULL, 0xCD95A66A140C2B7AULL, 
            0x676866F980849AF8ULL, 0x21757C46353B9EF2ULL, 0x303BF18734CE1F40ULL, 0x9C729F074E65200EULL, 
            0x3A842B77D2E4A7A3ULL, 0xFD7B92AD3E818412ULL, 0x4DAC2AB09EDAF23AULL, 0x1A4ADD5565E4D6E8ULL, 
            0x2FBAE884340C353DULL, 0x5D887D9341DEACE1ULL, 0x836158587298C0E3ULL, 0x36A7E9E5960D3445ULL
        },
        {
            0x1D92E437E3E4B33DULL, 0x8F13E138E1EF8C8AULL, 0xEB5EB6B93A07EF72ULL, 0x7841109D4A6FF4B2ULL, 
            0x9A087C81FDA656B2ULL, 0x76A2DF403F1CF97CULL, 0x504366EC21FCB402ULL, 0x4BEB15C522CA5F75ULL, 
            0xC066A6B0AA0D52B6ULL, 0xC86DC75E7CA6BC19ULL, 0xEFA8E1EE47FD14A0ULL, 0x52B53B9108933F09ULL, 
            0xC35F5D19EA08234EULL, 0xBAEC14238D953252ULL, 0xA208421372BDEE1DULL, 0xB5936FF246771432ULL, 
            0xBE5AC2308D6B6318ULL, 0xA1C16CEAB0C1CA43ULL, 0xF03A2A02A76B75A6ULL, 0x09F1B6506EF09363ULL, 
            0x07A04838DB7C113EULL, 0xD46C7AF9FF96A3F5ULL, 0x3D6961C74E95170EULL, 0x53EE2849A9918CE6ULL, 
            0x6C6E0AD35A149C69ULL, 0xBA3A7397F532367CULL, 0x9B1A0A5B4AB77ADCULL, 0xA365F7A7033F9772ULL, 
            0xDBBB718A32AA84F7ULL, 0xE27EC77ACE9F04A6ULL, 0xD1FDA1E9735D5176ULL, 0xADC6FF08220D3A55ULL
        },
        {
            0x194A7D49A6520905ULL, 0xF8C046E46AEC6194ULL, 0x28DE762CB7F67251ULL, 0x7A54760B7A90981DULL, 
            0x08F39E1B1115B424ULL, 0x428029E4C757D816ULL, 0xA1FB87343A68BA12ULL, 0x796F71BE7F8B56DEULL, 
            0x216752A6EB22E35CULL, 0xAEDE583B6A3E0033ULL, 0x965038CED0E2D0A3ULL, 0x5F3B496EB74BC793ULL, 
            0xDB2719BEC871C377ULL, 0x185C9471F9A5F0D2ULL, 0xA0E51E52412F795AULL, 0x407C663118ACBA16ULL, 
            0xE0BFC4B0FDB5B27DULL, 0x8579CC71F870D7B4ULL, 0xB37BBC3E18CCD4A1ULL, 0xFDEF71A563435DD8ULL, 
            0xC327AD060CFC84F0ULL, 0xC7D2ED4EFC083B56ULL, 0x3E29F15E549C8187ULL, 0x7C1AA69F2BF94A10ULL, 
            0x064AA9385926417BULL, 0xD1548C9C8357361BULL, 0xB24C63EADF519DC7ULL, 0xE46AEF3BC178A551ULL, 
            0x0943457FAE516D4FULL, 0x3F6AAC5A4028D1A2ULL, 0xB74194CD21700917ULL, 0xC20ED5A6E13CF38CULL
        }
    },
    {
        {
            0xBC1FB9CDE4616D5DULL, 0xD515459911A89AF9ULL, 0xB2619AEB67D66052ULL, 0xA0CC049A786CE0F5ULL, 
            0x6A9CC46F6FDCA254ULL, 0x4EAFAA4B78052A6BULL, 0xE16540D93CB9823DULL, 0xB457EE57AFAF0431ULL, 
            0x463ABE6795F912F0ULL, 0x6715FD87CBB54AFBULL, 0x051833085DDBC0B8ULL, 0x5D9115FE8890C5DFULL, 
            0x816C873FCCC03E6BULL, 0x4DE4202D4126C772ULL, 0x4057C8BB285FD1EEULL, 0x592FAE0BCEDB27ADULL, 
            0x85B7B530AE972036ULL, 0x65C766F52AAF8A63ULL, 0x894510412FAD6063ULL, 0x9D3C1FB61C92C8AEULL, 
            0xA1C353E2FE13D043ULL, 0x9CC78B7231223077ULL, 0x6E34E7DAFDC37271ULL, 0x5DF29BCDAA4FFC01ULL, 
            0x46A9C0F5DAD007B4ULL, 0x5733AC899F972A17ULL, 0xCE076AB843CF5037ULL, 0x3ABECCCF8C04FE62ULL, 
            0xFA6A5446E5CD3F0AULL, 0xC51C6C8D16045035ULL, 0x1653FF68542BDFA2ULL, 0x5BF8365B0EF92143ULL
        },
        {
            0xCB12199A00F08836ULL, 0xB6B8CFFA271F356DULL, 0x7ACABC6707ECB0E3ULL, 0x4847225CB3EB9EA7ULL, 
            0x2F826ACC2935C92FULL, 0x963B289DAA9CD2EFULL, 0x97553ECB51186456ULL, 0x7A50DD740869B62AULL, 
            0xF8AA1E8CAEE5C2F2ULL, 0x5A9108F1D124F109ULL, 0x419FF8AB70DB3804ULL, 0xB0AE9D0B135CC778ULL, 
            0x18C284C55F95B526ULL, 0x271B415EC47CB332ULL, 0x2DD05129338F54E2ULL, 0xE0940A3B20A5FDC4ULL, 
            0xE18ED998B9263D68ULL, 0x1371E1059C32E2A9ULL, 0x62DC89D039D890AFULL, 0xDD55A49192006993ULL, 
            0x30B3E3DE321B4F53ULL, 0xF74EB9DAC89CE929ULL, 0x05601EBAB8583CBBULL, 0x74E2B21B2BCE5B40ULL, 
            0xC95D9477724F864DULL, 0x1D42783A91D9422DULL, 0x97AEF6877863C897ULL, 0x912E7BC882349BF0ULL, 
            0x2A7B906B5CA28C36ULL, 0xFC90F9FC43D53B84ULL, 0x1B500DC4B88E5598ULL, 0xCCA12DF251759FFCULL
        },
        {
            0x21DA078B53B9C8B9ULL, 0x8C090259C4BF320FULL, 0x4B0604C27E37C9D0ULL, 0xDE3B4A9289F3AD95ULL, 
            0xB4220595EBF4D782ULL, 0x7126775A50C0DDB9ULL, 0xC2D81A8D9A04E102ULL, 0xF8837315CA47C4E2ULL, 
            0xDD0E0E0F2C8ECB97ULL, 0xD501ABC4EE483D44ULL, 0x7CB2D9AE9F91A1E8ULL, 0xE39A70CF4E960110ULL, 
            0xFBC7F7CD81979727ULL, 0xE4A8443CEEDC3974ULL, 0xF1F841E19BB1AF0EULL, 0xA7675876BDE0FAB5ULL, 
            0x4F46D0E7B3CC5574ULL, 0x153D6CD95D76594CULL, 0x726C2D8ED12F3835ULL, 0x86B135EAEB827146ULL, 
            0xAD69725200D3956CULL, 0xFC2BD31033EC3713ULL, 0xED77C760689B1DE3ULL, 0x6A5CD84ADB238FA0ULL, 
            0xFD0ECD88584F04B6ULL, 0xC8B5CEFAB73CFC43ULL, 0x3E2D7DB4F1C2B386ULL, 0x4353238746FFBB1CULL, 
            0xEE2F0795A2E7B4F1ULL, 0x356F81347428320DULL, 0x21739E20E23BA4E6ULL, 0xF1B8EDD545FB88B5ULL
        },
        {
            0xE84892EC1A67FDC6ULL, 0x7971F7289530D33CULL, 0x5408F50E5E53CBD5ULL, 0xB0D808D0E63FC225ULL, 
            0xB4B3E6917B74A8C2ULL, 0x066880F82F1774C1ULL, 0xCA664B428F3BF4CCULL, 0x33B555E3A846DD83ULL, 
            0x9F159EE280A92E8CULL, 0xE83B79EB80056A6EULL, 0x80FA057891CD8CC1ULL, 0x5219212CD7D144E5ULL, 
            0x85A17D3407929C49ULL, 0x8DF2CDF14B5B3901ULL, 0xFFD06386900FAC61ULL, 0x2963BF0E6494A62BULL, 
            0x744F2E500BFE66A9ULL, 0x7F5D219F533A9F81ULL, 0x083DB7F87F5689FAULL, 0x3CC39644F3C435DDULL, 
            0xD80402475893866BULL, 0x327A7707245C9833ULL, 0xED2320F7DFA214F5ULL, 0x03CE39F940F0C96EULL, 
            0x17BABED39F19B1C7ULL, 0x8EB35659C1B79366ULL, 0x964C57269DFF7F02ULL, 0x1B37BA5E5360B566ULL, 
            0xFF448DAD2EA36559ULL, 0xC4476AB19414D9E3ULL, 0x6245B07E6E4EBE6CULL, 0x6BBF0BB38084F785ULL
        },
        {
            0xFD7EDD7E89007327ULL, 0x22991D624A23D195ULL, 0xAF30AFD7B4AF34F6ULL, 0x91DF90F79F75F75EULL, 
            0xC969B013CA347480ULL, 0xE1F7C24FD7EFD9CEULL, 0x14F7DC1C95063A27ULL, 0xDA40D768C07A761BULL, 
            0xA2335B9D6323B764ULL, 0x55C966470B958E0EULL, 0x1E0665E4CD6E0655ULL, 0xE43D559FE0D16F14ULL, 
            0x0CC314011A306FAEULL, 0x05D434779550BF98ULL, 0x522DF71D9CAE1CF9ULL, 0xF680396743B0882CULL, 
            0xD1C40EBDF935649EULL, 0x446A5ABF3A5AB1D6ULL, 0x70437FFD7C073342ULL, 0xFFD173A99FFCF54BULL, 
            0x16EB6BEBD2C61BAFULL, 0xF3F800A0832BCB9AULL, 0x01204E0CF4DEFFF2ULL, 0x08919BB6382685DFULL, 
            0xDE296C6AA4ACF35BULL, 0x337E4F4DF50FBCD8ULL, 0xD45366F44B00BB47ULL, 0x623D369A959BA66CULL, 
            0xC23AA9F95258187BULL, 0x8DF3AA4ADAF47B9EULL, 0xC617F87C0234C35BULL, 0xEEC00B375A61ECD0ULL
        },
        {
            0x4D4F3B966D325BDAULL, 0xB22C3CED2DE8A359ULL, 0xDEB2A3F7F9029E61ULL, 0x94A275930C1A782CULL, 
            0x8C236D59D0902CFBULL, 0xF5B44416F8BC6A63ULL, 0x5FFF797DB121EE13ULL, 0xA391D2EC862B8803ULL, 
            0xC88C4B492532A169ULL, 0x6D85CB656E52F427ULL, 0xBBCC5E027EAC046EULL, 0xA4A3BD5940620D21ULL, 
            0x9D82465A0AAAEAFDULL, 0x1C0B3CB8DECAAFDEULL, 0x63CC929144CA67F3ULL, 0xE30ED152042C3BCAULL, 
            0x681523535E91AE23ULL, 0x69BB458F86344D29ULL, 0x8C77B11CD6BD75F0ULL, 0x0742809EBABC16D5ULL, 
            0xC873A8496797A81AULL, 0x3F3C09BAAD0CD48EULL, 0x4776218E79032EBEULL, 0x0B7E6F92896CD3D6ULL, 
            0x65B5BC39749731C4ULL, 0xFB3390C8F8B7A490ULL, 0x2252F4BCF81240D1ULL, 0x5D20D30E0D079CC1ULL, 
            0x88458AC2D2057ABCULL, 0xAAF7F293A465C152ULL, 0x556E83CA81B367E1ULL, 0x7C3749E6E582713DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseFConstants = {
    0x8640058363AE1749ULL,
    0x3F3D75743C02AD91ULL,
    0xC8702D8AA18DE845ULL,
    0x8640058363AE1749ULL,
    0x3F3D75743C02AD91ULL,
    0xC8702D8AA18DE845ULL,
    0x6CE9C97B59011B38ULL,
    0x842CABE22C9A2D48ULL,
    0x3F,
    0x8A,
    0x7C,
    0x1E,
    0x34,
    0xB4,
    0x2E,
    0x54
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseGSalts = {
    {
        {
            0xA89148F6179F4AF9ULL, 0x1B095BD3B0DCB2FEULL, 0xF4E8E660849AE07CULL, 0xC712562A3B20A30BULL, 
            0x645AF3AC723A66C6ULL, 0x8E8929D3926DA772ULL, 0x6322AAF99FAB5CF8ULL, 0xABA9D612E456A7C6ULL, 
            0x20D437811EED05CFULL, 0x974739716DFEAE46ULL, 0x742D33B79D176E2BULL, 0x5C905406D0CF98F4ULL, 
            0x1297628C7C1C9C70ULL, 0x4A40E732EB362591ULL, 0xA63D55A4999762FCULL, 0x4680016B5997B863ULL, 
            0xACF704936168C489ULL, 0x4E476CFBC8817A88ULL, 0xEF49DCB8E8C98899ULL, 0x69D1E69A1A7B7D24ULL, 
            0xFEC6F65345EA8E27ULL, 0x139F27A8234A2615ULL, 0x476B3DCF94160F8AULL, 0x0B72226E41062CF7ULL, 
            0x1AFB187855BE37FAULL, 0x2202CDFAA6CBFE8EULL, 0x64B08789AF0F1588ULL, 0xD72A0DA0BE59936DULL, 
            0x59678B9F0007F994ULL, 0x777E3378A54CBF25ULL, 0x6EF1A20B04BBED61ULL, 0x2191EA1ECF853770ULL
        },
        {
            0xA8A8B2B3E0B1B877ULL, 0xE560F73BEF6CDFA5ULL, 0x1315A8A18A78DAA7ULL, 0x5DCB51FE55506655ULL, 
            0xBB14E88DC8EEC16BULL, 0xBD3A66BE171850E2ULL, 0x2BDD1FF8220A3ECFULL, 0x871093C3E32F2A9EULL, 
            0xF4B9D3348914F924ULL, 0x21619FF5892810F9ULL, 0x80FBD0003A739AD6ULL, 0x1C0ACD23E646DAB2ULL, 
            0x4BBA6369B2C1C66EULL, 0x12394F9F0EE9FDD2ULL, 0xA72CD96B9AEB34DDULL, 0xB3C7D1E479F5B06BULL, 
            0x4E13C7CABF3D40FCULL, 0xE0EF3714118940C4ULL, 0x00D6E397EF5E623FULL, 0x4542149FFF1A8BFDULL, 
            0x2921E0D7D651C5A7ULL, 0x1BE85C87138D372FULL, 0x977F2525200480D0ULL, 0x268CBE6C7F5350ECULL, 
            0x7EC1C8C622A51F46ULL, 0x2E67C8B550082ED5ULL, 0x11329752140FD4F6ULL, 0xDE8565811829DEACULL, 
            0xCDDCF0D248587A87ULL, 0x80E26A7F19B52A7EULL, 0x821741407D47F491ULL, 0x89778103C7C8CD12ULL
        },
        {
            0xAAC01A4B361C0D8EULL, 0xCCCBCD7807C3504AULL, 0x227B6A7A616580A8ULL, 0x9843179490C3DBC0ULL, 
            0xE6EBACBFC68D9F53ULL, 0x3FB5F679F0BBF25FULL, 0x86D66FA0FE5A7BE5ULL, 0x158F84E8B5C493D7ULL, 
            0x448B5A6713C8ABDAULL, 0xB817AAB64552D367ULL, 0xE127D4B67073E4F2ULL, 0x63880530E1C4F706ULL, 
            0xDF1EDA4F2D41BA3BULL, 0xEC633482E54C9265ULL, 0xB6F7C512F48A7AA4ULL, 0x4F689B9E1215FAC4ULL, 
            0xD119D295076D0799ULL, 0xA3477812BAEC96FEULL, 0xF5EFD590C754D3C9ULL, 0x60EA347871215CCBULL, 
            0x99F0AE3E1E71284AULL, 0xEBCF4CFA0EEF2540ULL, 0x14149C066E9B624EULL, 0x01B035E60839041DULL, 
            0x5770C78B683FFF2AULL, 0x4800B3A860B36E9EULL, 0x59E1F937FF4DB1F1ULL, 0x8FB8C70FAD990446ULL, 
            0x2D892C0915D9E1DDULL, 0x6BB50046E18179D3ULL, 0x1E14999B9DC23D1EULL, 0xC852F1D24A4B6CB4ULL
        },
        {
            0x8F67776A685F464CULL, 0xACEDFFE7F760D385ULL, 0x7A3FF31AC8EE160BULL, 0x46ED624E705EC1B0ULL, 
            0xB91978366B6BCB82ULL, 0x4D18080221FB4DBFULL, 0xCD7C53FBD6AFBF2CULL, 0x985E84B3E55670FFULL, 
            0xEC43F91F2EB6FBB6ULL, 0x5ABC4B917B0731FCULL, 0x7825E26F225B83C7ULL, 0xB76A7C9132A617F2ULL, 
            0xA071338C1829ACF3ULL, 0x2A70927208361F0AULL, 0x20083BD4F651D915ULL, 0xD014A9EBB1D56982ULL, 
            0x06DC649F7ABA68B0ULL, 0x0BCDDF4CB000B5A1ULL, 0x6634C3FCB050FDFDULL, 0x74F4D6F5C2AA29A3ULL, 
            0x0EBFCD88885CF7A2ULL, 0xC0FD35971493FFB0ULL, 0xC92EA225EEFCA75EULL, 0x5A4AF218441EC4E0ULL, 
            0x97227F3D330422FAULL, 0x0A5507C28F12FC4DULL, 0x43F0B474E0E8DDF0ULL, 0x0E9CA18E35C9BB3AULL, 
            0x8500CA723B83B53EULL, 0x495F623F3A84523EULL, 0x3E80C4E8871E69F4ULL, 0xEF6F77BE01E76EAAULL
        },
        {
            0xEA5937AD5325A9F7ULL, 0xDAFD8936B5E837BCULL, 0xEE5DAACB22C18474ULL, 0xA8DB3A44080D578DULL, 
            0x2CE7D079FC0B5EA6ULL, 0xEFC6CFFD5B08BF7FULL, 0x8EB8686CA576267CULL, 0x6917E6CA58557043ULL, 
            0xAE66AE2BEFADEADBULL, 0xB32DC29FB5E51545ULL, 0x9F04E3A94DC22A5CULL, 0x6F7D61D7CFEF3463ULL, 
            0xA783169D85222951ULL, 0x8F2BCF8E8BC3BA8BULL, 0x7B9832878D4673BBULL, 0x9BCDE42E343FD0DAULL, 
            0xB59647AC9FECFA14ULL, 0xDDC7BF75C3440353ULL, 0x2AE025D98036B898ULL, 0xFE748F9BEA0E9166ULL, 
            0x0A2A715A487D2604ULL, 0x5CC6CD5A96A6C274ULL, 0xC806C534C75354A9ULL, 0xCF203893A8E16FD8ULL, 
            0x6C8BF8A4CF1848DDULL, 0xABB13CEF31689701ULL, 0xA738AAC9735D4C11ULL, 0xC75B0D54773C23A4ULL, 
            0x61578040394BA9ECULL, 0xBA96FA1E60F6D5E2ULL, 0xFBD131584A02C804ULL, 0x4A62491F2926A180ULL
        },
        {
            0x50952D1B1D0D3562ULL, 0x8E100BD7E274DF4BULL, 0xF37613A1D8992DFBULL, 0x046E206DEF6D540AULL, 
            0xAD354D2B7E57D07CULL, 0x819745F239EB6724ULL, 0x15DEE1354CDD2A1FULL, 0x14AD2D37364C7996ULL, 
            0x2CD056BEADEC869BULL, 0x1778779F25722298ULL, 0x9B387060E8A16007ULL, 0xF9B725842D63C480ULL, 
            0x268F053FA79A6F98ULL, 0xE420D029298EAEF3ULL, 0xFDB97285F26A2440ULL, 0x2DFDE08750D1C07CULL, 
            0x0DBD1D775AFBADACULL, 0x703C60F33A15A85FULL, 0x400F557002233AB1ULL, 0xA8AD26240F2E28FDULL, 
            0xF71970AC22074491ULL, 0x840DD4EA32553F69ULL, 0x6F564BA81545404AULL, 0x9879639F0A50653CULL, 
            0xF2FBF98A40272A1BULL, 0x9167E3B762F0B962ULL, 0xF5F3EE42E2A1084DULL, 0x74B522BD53DD99DBULL, 
            0x9FAC6CC353D5CD27ULL, 0xBA798810358BF275ULL, 0x91E4C87FAC3F0133ULL, 0x3C249F75814B493AULL
        }
    },
    {
        {
            0x8473C3BB2F4CCE58ULL, 0x630F83F659EBB057ULL, 0x22E74EFD891D4BDFULL, 0x1CE184AE09A2621CULL, 
            0x6EB3A20249F22DCCULL, 0x3CC95EDA717BFD6EULL, 0xB39B83DCF9B29DEFULL, 0x68DFC544B3964937ULL, 
            0xACE0FBB8A8ECF883ULL, 0x8405E31B9DA9A936ULL, 0x9DAB736C68FB8256ULL, 0x6E9F3FFA96BCC76EULL, 
            0xF7AE56F96CED9C4AULL, 0x3D0658002799E0E1ULL, 0x28FBB583E37F543CULL, 0x3AC924DC4D6BFA1AULL, 
            0xC85527085AA3BE89ULL, 0xF84385CF55809B7BULL, 0x4922C81634BFA531ULL, 0x3D93692E41DDC97FULL, 
            0xB6614E238BFDD368ULL, 0x99B2118C78E70E02ULL, 0x3C868847AF061455ULL, 0x42DA86625DC786CDULL, 
            0x20EE1015ED5D1108ULL, 0xB090E05C406BD474ULL, 0xD790EBB5B1DD5DBDULL, 0x742EF2A5F37ADC4CULL, 
            0xD0FD7735C84BA95FULL, 0xEEAC41B599C40389ULL, 0x8F6CC32825EE0178ULL, 0x4BA2E530E8189702ULL
        },
        {
            0x92B93A2B1C3AE575ULL, 0x8149AEDA705E1C18ULL, 0x992692B5088D2AADULL, 0xE94D620050B571D6ULL, 
            0x11D9D8FDB84B0EAFULL, 0x6541C25E24F84E98ULL, 0xDCD2E6E957C59D54ULL, 0x8F2A7E48635575B0ULL, 
            0xE2026523D30D7166ULL, 0x7D577D0B9470EC0CULL, 0xACA61E7B9CA844BFULL, 0xE2F6E616CB9DF922ULL, 
            0x01A064C15F9FCF9BULL, 0xC3A81CFAA169DC8BULL, 0x514D79CD3A416F50ULL, 0xBF05861DC13688EAULL, 
            0xCA098439AF4064C6ULL, 0x61CD5CA00948E85CULL, 0x59B9360268B225F5ULL, 0xA2850DFE5D2669B7ULL, 
            0x2A614F1E7896BF5CULL, 0x28E89D9F3E742669ULL, 0xF1F9F6F0D543ED71ULL, 0x359CEB6FA3016771ULL, 
            0x89EABC2C2319F5AFULL, 0xD06ED1C37D1B229EULL, 0x0BB4C9D25832AFF7ULL, 0x5D7F36226B019FDAULL, 
            0x2A7FFEC5FC1CA71AULL, 0xBF4F87AAFD7DC554ULL, 0xBF9CF215943C2569ULL, 0x644E4A5D19A5A2EAULL
        },
        {
            0x8F7E8B7E2A74068CULL, 0x5E849190F6C00F1BULL, 0xE1CE7A09A7F5D4BDULL, 0x1C85F1F144ABB25CULL, 
            0xF4415A9CEDA58F4DULL, 0x0F13C3B321C9A12DULL, 0x1BA8DF6BF933233FULL, 0x521372D7CB463053ULL, 
            0x8D105B332F172576ULL, 0x26FAF102EEDC139BULL, 0xF7E280A3A89E746BULL, 0x0D0FE726238D99B6ULL, 
            0xFB9B79F821721576ULL, 0xED280CE2AA57A138ULL, 0x2CE94FDCC59D6078ULL, 0x5D473B937483C571ULL, 
            0xEE4975A3D0485949ULL, 0xC9D367527407A38FULL, 0x89C71E631A119323ULL, 0x68854CCB166D0E71ULL, 
            0x1A72050733D1AE37ULL, 0x420258B994EB59A3ULL, 0x45B9D2788AF6A962ULL, 0x5AB59583F2562F78ULL, 
            0xE69B44FD3CDDEA2BULL, 0x9C1EF8D507BAC25EULL, 0xBE67A4F4B4418200ULL, 0x9B6B44067FC4D099ULL, 
            0xDAD2BB1D2A3DECF4ULL, 0x4B80A73D1FF435C4ULL, 0xFDD7A29FDB24BA55ULL, 0x1F58EDDE36C0064CULL
        },
        {
            0xB5FB8E1D23518252ULL, 0x3053DB54E3A4FB24ULL, 0xC8CBC9F75DCB4102ULL, 0x172059F9B8C7E895ULL, 
            0xA698616AB2805822ULL, 0xB640C7825293D89EULL, 0xCE49C9CEE3C95331ULL, 0xE2D78EA5C66EA1C9ULL, 
            0xCF55084EF32B19DAULL, 0xDE97CD715BF53E59ULL, 0x85AFA885C069AE28ULL, 0x4455D0F0D2D4D72AULL, 
            0xE669DF3B6AE3F41FULL, 0x49706493E08B2DB8ULL, 0x61265D58613D0078ULL, 0x8569F10B213853BAULL, 
            0x5EA63ACF36516721ULL, 0xA0BB0B821C87036AULL, 0x1BDC28C4F370929FULL, 0x89EA13478DB5B221ULL, 
            0xCEFF29D6F33B39ABULL, 0x772BAB833CDDF09AULL, 0x60FC3F6F3A7B6A72ULL, 0x3E8951C7708A470AULL, 
            0x8DEB484F51343F45ULL, 0xCA52E90A0382D5A8ULL, 0x1F07C145AAC728C1ULL, 0xFCFD79B805BFCB15ULL, 
            0x2AFD4BF48D79F692ULL, 0xBAA1833FFC352895ULL, 0xD74DCB9D1811DF21ULL, 0x1508B78FFC495F81ULL
        },
        {
            0x301C595C1191560FULL, 0x59537ED9FD2571A9ULL, 0x0202BF4E16B2996CULL, 0x0A1C30E1C7BA68BCULL, 
            0x07A46D090358E9F3ULL, 0xF4082A5CAB07E9CBULL, 0xFF5CF0919A2FB341ULL, 0x71DBFF2F03E7AFD6ULL, 
            0xC27C149F4BCB81D8ULL, 0x24172B54D539A76BULL, 0x027BC07F15168DD8ULL, 0x3C5A31AAD4C0DC3EULL, 
            0x01D1CAEAB64025ACULL, 0x7BC306713E355908ULL, 0x00C0098A654EF3A0ULL, 0x3CB7F7FDC1B265D4ULL, 
            0x84E5658F7B963F7CULL, 0xC6E326EF8CF3C968ULL, 0x056C52B4734AC9F5ULL, 0x3E7AC8E8C7DF20BEULL, 
            0xD03C6C7676473840ULL, 0x180C273C0D1F4020ULL, 0x54D3DDFF84F22F9DULL, 0x66236AF9924CCAC3ULL, 
            0xF171E4A096829137ULL, 0xEC45945F7FD4FA06ULL, 0x92379BF7FBCEF7F0ULL, 0x6E43A1454A749C47ULL, 
            0x3EE17BEC53F9941FULL, 0x844DD0BF47C6FE88ULL, 0xB857575C5B09F61FULL, 0x5F86D078B0F09384ULL
        },
        {
            0x7522F7F9811F6FD0ULL, 0xDF48866353311683ULL, 0x124BA78D74972745ULL, 0x91A3AFE87B577A4CULL, 
            0x4F283A632A598457ULL, 0x54016E796472DCC2ULL, 0xC627AC758236913BULL, 0x47A1D4C796749B66ULL, 
            0xD619C3D1FE746393ULL, 0x1286F9335A776695ULL, 0x7F2C467D75D795F1ULL, 0xD7B4A8CEB73A586DULL, 
            0xA6A41B82A8316F77ULL, 0xBF43C1C2E2041CA4ULL, 0xFCF8920DBB7B4DAFULL, 0xC10BA20CD8DF919CULL, 
            0x70D6206E9F11ED22ULL, 0xCFFF9B6FE197A730ULL, 0x3A5789B7E7145C10ULL, 0xF9A8F7BCEED17B34ULL, 
            0xDA90F1A1C602117BULL, 0xBD9E0D297BAD0E7DULL, 0x8A256FE4F945E49BULL, 0xAE4778FB7835E3CBULL, 
            0x1F478A1B354E0053ULL, 0x355E7D8EF415637AULL, 0x994AEAD213AA94CDULL, 0x527A385B219907B5ULL, 
            0xA38761AD119D81CBULL, 0xBF609A48F5E1B745ULL, 0xB7D0F174D85DF9FAULL, 0xF3EEDDA73CF21DFDULL
        }
    },
    {
        {
            0xA9E5C75134C427DCULL, 0x4C46BA61D5CFD3EBULL, 0xA2AD2A80D4975AD9ULL, 0xEC2D17ED80378F8BULL, 
            0x62C580B2E3EB8765ULL, 0x616D860C67E48FA1ULL, 0x999A36F22B86E4D4ULL, 0x78640B4F2C0AE40FULL, 
            0xFF868F342EF15FB1ULL, 0x45CD611DCEBC3A45ULL, 0xC22A9188B5CE581EULL, 0xA70CE8A3F4D74A77ULL, 
            0x74A329BA7D100EACULL, 0xA8D7F90B97018EA9ULL, 0x77C0A67A9B75216BULL, 0x1971F697D5535D04ULL, 
            0x9C1BBB65F095B57FULL, 0x662075010AA05BEFULL, 0x5AD46A537F399D64ULL, 0x5FCAFE2892833E84ULL, 
            0x9E368934AB0884CFULL, 0x1442C89BD49272A0ULL, 0x03E759B01661A587ULL, 0x13DC592494C9A9A6ULL, 
            0x78BFC3D4E314FAAFULL, 0x5B54C8DC9D723989ULL, 0xCAEA86BA337CAA02ULL, 0xD077A940E5118B86ULL, 
            0x68CC32853E28E34FULL, 0xB3CD49C06A31CC00ULL, 0xA85E64C1950A4641ULL, 0xBC73140C2885522FULL
        },
        {
            0x8BF1BC6A8681C76BULL, 0x55D33A579BA56314ULL, 0x2F3B769FA0A9BC09ULL, 0x5E8D2D8984279A73ULL, 
            0x20D6556C929044EEULL, 0x502EA4C64E68701BULL, 0x963E030CEB20F5A5ULL, 0x8D921887BA1FAA33ULL, 
            0xB6D2D8B41C2BFABDULL, 0x07A90128CD1D9F59ULL, 0x31FAEEC960C04E47ULL, 0xEF9F824CB0DB0A96ULL, 
            0x398539FE06A30F68ULL, 0x458E0236A5AA9FE1ULL, 0x84D2558843D3EA7EULL, 0x5A029DD05F5AEB4EULL, 
            0x73B0620C07475850ULL, 0x20172D1004279642ULL, 0x41FF0EA13BE993B7ULL, 0xD51F3BF24DAD4F6FULL, 
            0x327089E55DA07190ULL, 0x8F628BC22769A427ULL, 0x21B35EE244F394C3ULL, 0x3FA827F5B3313D99ULL, 
            0x32B391AF5FE940E8ULL, 0x3FF06E7EB02AD447ULL, 0xFE53AE276E926BFBULL, 0x674B98EB9D5E7DC9ULL, 
            0xA8EEDB6209F5DA93ULL, 0xBB7F665A61E6091CULL, 0x599C82C913893C18ULL, 0x32D34811DC0F9711ULL
        },
        {
            0x06670E50DEB6B3C9ULL, 0x5DEC255A42D661E8ULL, 0x51D0FB9BA0E3F625ULL, 0x0D85A5BA3177D4A9ULL, 
            0x200DE86E292D0DE8ULL, 0xAC5E67ED2419C43CULL, 0x3286F2FECBD70BB1ULL, 0x2E69C4D74F6857CEULL, 
            0x1A8B35AA180E376AULL, 0x742F6966215BE6EAULL, 0x8A7591C66E884F32ULL, 0xE9D68F40EE32F796ULL, 
            0x8256466399B20EDCULL, 0xFA9DF6167D01587CULL, 0x78C2336E2F21B89CULL, 0x9A81A4C77F61BA17ULL, 
            0x6AF0BC614167C279ULL, 0x26D662CBEB6D871CULL, 0x9048429400B5D587ULL, 0x6D30FC655B2A3A02ULL, 
            0x7AF2D6647504C33FULL, 0x0523AB40EEB4F5C6ULL, 0xADFA1861D300496BULL, 0x5AD9253B2AE31954ULL, 
            0xB646650F2952C546ULL, 0xDBF420BE46DC4FACULL, 0x88882374185C1F68ULL, 0x5F61D5C3F2DF30A7ULL, 
            0x591553751EDCC5ACULL, 0x8A860BC3251C5365ULL, 0x3F60480D5AED0E28ULL, 0x49A797851CBC84A4ULL
        },
        {
            0x80196C6E5D8A2D7AULL, 0x7CC849C85E24B3ABULL, 0x4F04149AD7BFAD1EULL, 0x29D7F32B97E11A8DULL, 
            0x7BB190FC8BD02A4DULL, 0xCCEE10C1510527A9ULL, 0x077504A94D05D0E3ULL, 0x5198F636785A6F1BULL, 
            0xAD47457C4FE846C4ULL, 0x41647C2FFC1023ADULL, 0x06E80EA79E024B17ULL, 0x3476476B0D6BD139ULL, 
            0xABD2D0643841A0AFULL, 0xF04A135FA99A13E3ULL, 0x1F98AAECDA210691ULL, 0xB3EB46955F8075BBULL, 
            0x118582BB5FC67BBFULL, 0x4C66504F1BDA9011ULL, 0x7F4801FECA904FF3ULL, 0x24995FF8F0E9B054ULL, 
            0xFE958D5480B480A3ULL, 0x20F541891CB6651FULL, 0xACE6BC979BFF1A53ULL, 0xB583F64659BB9EA2ULL, 
            0x5B9DB4D2DE098AE1ULL, 0x8563F7CA0183970AULL, 0x34525A2FD6EDCA52ULL, 0x4D07B5810E29CE26ULL, 
            0x54469E42EF43F229ULL, 0xDC46EE50ACEDDC22ULL, 0x10DB67D4221E5196ULL, 0x69D58EF63E903777ULL
        },
        {
            0x56BD6EFBBBF526F6ULL, 0x11CBE261908657B4ULL, 0x3CFE3D61DD514520ULL, 0xFC7BDE61150115F9ULL, 
            0xF5FFB32F3E9C4DC1ULL, 0x97DB3F58ED2F5866ULL, 0x8F247F053C762F0EULL, 0x557913ECF8A48422ULL, 
            0x1F4CB490A496B914ULL, 0xB87292A32A403A99ULL, 0x45E57EB84E4A15EBULL, 0xBB29D16A09CF4B50ULL, 
            0x03508B4A868AD444ULL, 0x005EEACDDF3036BCULL, 0xD219CAA25C3ECBCDULL, 0xDFD43BB62025C3B4ULL, 
            0xBA28685ADA1FC5A2ULL, 0x5A564C6E4393C4E0ULL, 0xBEF4690AB8D43F36ULL, 0x484571AA1EBA1A37ULL, 
            0xB7053A3C7910ECCBULL, 0xB98E06EB31648058ULL, 0x80424119FBAE7153ULL, 0x32851C775C47EC57ULL, 
            0xDEB61A3C121A1D4AULL, 0x3EA3314833DB67C5ULL, 0x386D51DCD9FCC074ULL, 0x7C76335DCF633D66ULL, 
            0xD0AF906A41BEA27AULL, 0x65A9C3F1DECB77EBULL, 0x6593E265DB3BBA77ULL, 0x924A8163A9C26517ULL
        },
        {
            0xEB7FA7FA17DC9F6EULL, 0x391E3FBA503D5841ULL, 0x456F9381E07D0280ULL, 0x24171D779F963E4BULL, 
            0x07E2684D958250EDULL, 0x7D52BC8389432835ULL, 0xD6DE4AABCBFC9D14ULL, 0x2D4A392D4DEB0D3FULL, 
            0x989AF43DDD104F07ULL, 0xF0C6BB54DF36C56AULL, 0xF7BD14667A554BADULL, 0x4D34CB83475CADFDULL, 
            0xA336BB1B75D43697ULL, 0x8B11BBD14B75D730ULL, 0x08F41F6B88B2CB1CULL, 0x1B8EAFE5E0F3E63BULL, 
            0x2F0EF990C960281EULL, 0x20BA384C88885323ULL, 0x405BB3CB6D5CBC0CULL, 0x85C9B381A83CDBDDULL, 
            0x94C0BE17A4C830FCULL, 0x6D9383F28DC16DE3ULL, 0xD08F8CB8DAD73657ULL, 0xD2883C18BFC49E02ULL, 
            0x4721EC6340DE56CEULL, 0x27EBAA9EC04B3B32ULL, 0x6F24BE6EF7A65D34ULL, 0x9B53F9A3C6265EECULL, 
            0x0CDD13F774F8F142ULL, 0x1217DE35483A51CFULL, 0xC11D9FA79B0C1E2EULL, 0x155E90CB693690D1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseGConstants = {
    0xB9D2F82A604CB5CCULL,
    0x5CB142BFCAD1D9B3ULL,
    0xD9A7C03C8D99DEC8ULL,
    0xB9D2F82A604CB5CCULL,
    0x5CB142BFCAD1D9B3ULL,
    0xD9A7C03C8D99DEC8ULL,
    0x3E7B6A44B9E7AB0DULL,
    0x2DCE1113ADC455E0ULL,
    0xE6,
    0xF9,
    0x41,
    0x07,
    0x3B,
    0x83,
    0xD9,
    0x1C
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseHSalts = {
    {
        {
            0x048CCF4CE51F0A33ULL, 0x6B16ADA0A27497C0ULL, 0x953009C486E382CAULL, 0x39F34B6AA6448394ULL, 
            0x48CF047FE8DA638EULL, 0x090BC36431884E09ULL, 0x95693F520430E868ULL, 0x30999D27B4ABF8B2ULL, 
            0x711F51608E036C3FULL, 0xDBE37E3911E7B4FEULL, 0x549159B6E86CA2DEULL, 0xEF544CB85C340526ULL, 
            0x2483079A962CDB87ULL, 0xE22A74F28F856FDAULL, 0x607A85EABB4CB6D4ULL, 0xB2E518366571B481ULL, 
            0x21D0E881D6E65A1AULL, 0x14614A9BA956A1F6ULL, 0xD9FB3A8EE5C0FDDCULL, 0xC9BB4A6ACDD7A1B2ULL, 
            0x89EE002A523DEBF2ULL, 0x42DF804848D210ECULL, 0xEE15FB71D03C0259ULL, 0xF4A23211644E4AA5ULL, 
            0xF1771956558C2BF8ULL, 0x87E8B5E9AD3B56DFULL, 0xD3F667CF87C3111FULL, 0xF5B49545FA2D687FULL, 
            0xF36CC2F8D246C9E1ULL, 0x03408A96FEE33980ULL, 0xB18F45CB3B0CBC06ULL, 0x2E4614AD109BE033ULL
        },
        {
            0xCC9CB7F99AC176F2ULL, 0x7F01B4A435DCD08FULL, 0x5F52A339271C740FULL, 0x399F64D262434272ULL, 
            0xEB1E120AAF3127D7ULL, 0xC15D272C0D303B75ULL, 0xC07545D8AC255D40ULL, 0x4E8EA22E9A378E6EULL, 
            0xA6817382FC76BC94ULL, 0xCDC2CEFACB764E71ULL, 0x87533E610B67D0F6ULL, 0x14247343CAA15A9EULL, 
            0x5442F897B32A0D55ULL, 0x7002928BE5B0996EULL, 0x65BDC62515F682E5ULL, 0x1A18E170B6438797ULL, 
            0xC093F78A67CAFF12ULL, 0xFF01E27F78EA04A0ULL, 0xE161FEB89E89B09DULL, 0xBF292EF6756AA60AULL, 
            0x0430B4206BAA66D4ULL, 0x141519E6F1FC70A0ULL, 0x7117622BC7E99FE4ULL, 0x2E5A0B5D9D7C24F5ULL, 
            0xDC4DBB67720CCC21ULL, 0x0AFE1C294B2B4FE9ULL, 0x89034EEBFEF427F5ULL, 0xC99669BCB43F8029ULL, 
            0x6F319C061B2D0B94ULL, 0xD7E2B15E2F485479ULL, 0x2733CCE9AE963EE2ULL, 0x2F62E726BEC9FE35ULL
        },
        {
            0xAE7E88C7535BA5AAULL, 0x8448E8896D46666BULL, 0x9ABD25EE972C05B5ULL, 0xFD9CB221E46A6381ULL, 
            0xCD440E70899E00F0ULL, 0xEF26E623E19FAF34ULL, 0xE450AB1CFC64CB32ULL, 0x82B7BB87ADCF2284ULL, 
            0xBFC60452B310B68AULL, 0x08C92C738B140DDBULL, 0x71CE1CAFCA72661BULL, 0x86CC59610C3E7F38ULL, 
            0xF24972176BD802D9ULL, 0x1DA2565338095F66ULL, 0x9981C233CFBA76CAULL, 0x5607B4101101A27EULL, 
            0xFA159D9785C8D9D6ULL, 0x27747AE678AAB6D9ULL, 0xD6240BED1656A024ULL, 0x28058093E4735B72ULL, 
            0x4BCD4666A2E79C9AULL, 0x8E0356A71885BC87ULL, 0xE6260595C1BFF010ULL, 0x1E473AAEF237A816ULL, 
            0xECB4074F1E30A8AAULL, 0xE55B64F2B42316DAULL, 0x4761A11FE56B0EADULL, 0x02A7CF354F4C4599ULL, 
            0x09514D2264AA7931ULL, 0xA41061FB138B594DULL, 0xBC2E47ED9AFA7A9FULL, 0x84336EFCD108EFE1ULL
        },
        {
            0x77AC913721EE2296ULL, 0x9C61BBEAC2E18055ULL, 0x131BA21AFF81F4D6ULL, 0x4EAA33C01A419519ULL, 
            0x06BA7BC482FCD5B7ULL, 0x63CEA7B480E85D20ULL, 0x5847C17CD073720EULL, 0xA38A26250681ADEFULL, 
            0xB4801F181AB4AD84ULL, 0xF410BCE2D79EA2D8ULL, 0x320C98122F6F10D3ULL, 0xE2BB469AAA4CCC6BULL, 
            0x12C2FA3677789AB4ULL, 0xD9C8896AC92FC6FDULL, 0x299488D9FFB7805BULL, 0xB0CD1E5A645F2B32ULL, 
            0xD282BA44FB67ADDBULL, 0x20BA50489868D1F7ULL, 0x3B8603D2D20758E8ULL, 0x0890464E1CF796B3ULL, 
            0xE8CD483299BA5813ULL, 0xC7B1797365322879ULL, 0x94C78028CEAA7E74ULL, 0xB050CAE3F0244906ULL, 
            0x6F3CF741358BBEF9ULL, 0x07ACE091677C0E53ULL, 0x6BFA7C92FEA3A029ULL, 0xBBC08CCDAC91A6E8ULL, 
            0xC8698C1670A5966CULL, 0xFF5D3397BF878D9AULL, 0x96BBD9169A148E92ULL, 0xA17A6FBCBE352CCCULL
        },
        {
            0x44BA54BF120FE975ULL, 0xAF14F0EC9B30EE68ULL, 0x0DF73B9DC55556F8ULL, 0xADDDE3ABCFD201D9ULL, 
            0xCB20F30CA8CCE400ULL, 0xA29743F6B47CAD37ULL, 0xE3A9CE8758961471ULL, 0x03A62E8D4248BF24ULL, 
            0x5EF3E8DF4E29292DULL, 0x84200BD9A875AF86ULL, 0x6235DFB3CCC9E8FCULL, 0xC2CE077D50F8682BULL, 
            0x10A9104C6639030EULL, 0xDFB0BEF78F5A82E0ULL, 0x389C9D881C0409BAULL, 0x0D522E6EC3867311ULL, 
            0xDC7FD334A9421AB3ULL, 0x17741A10FA9B0215ULL, 0x02B14B8B609A8AFCULL, 0x840CBF46557CCFB0ULL, 
            0x97185E030DB0F130ULL, 0x3C6149A5C79A01E1ULL, 0x9138829FE9B38D53ULL, 0x3B6B8E19CE5C6C83ULL, 
            0xA6A0AA6E6A72390EULL, 0x50D7A43FBC7023D2ULL, 0x0F9E791C713338B8ULL, 0x13D5F9928AC7F33AULL, 
            0x331AD936BB4E6BB1ULL, 0x82033FF2EB46B28BULL, 0xCA1F901641D0F3ABULL, 0xF4FFFC999CC5DFADULL
        },
        {
            0x5AEF2ACCFFD32B11ULL, 0x10540E4A71F9D2EAULL, 0x00764947E61818DFULL, 0x77A167126ADB91CEULL, 
            0xF578078BE3849204ULL, 0x6E76CFC44CE98DCEULL, 0xF3727D2B7E7749D7ULL, 0x196C5C27DD89C222ULL, 
            0x86BA04C08E6107CCULL, 0x7FD4161CDEA932B6ULL, 0x3DB1A6FFCF965C78ULL, 0x83772F6B41DD8576ULL, 
            0xF52DEF1E8733D415ULL, 0x89CB7FAE8A755F4FULL, 0x40B35CCEBFBF88F2ULL, 0x7A6D8445FA6166C2ULL, 
            0x439E1F5D8C8DEB1FULL, 0x30BB1127205AE360ULL, 0x70BD7BDB0A93113DULL, 0xF2F1846B84BFF041ULL, 
            0xEF8C7B8AC33B8130ULL, 0xE53C912D14D2E670ULL, 0x6395AFA1E829B362ULL, 0x08E39B47AB3219B1ULL, 
            0x4B303D71180997DFULL, 0x3F23DE10D5E85324ULL, 0x44378CFA7BBDD912ULL, 0xF7A5F9C75A46A6E9ULL, 
            0x91DFC00E3E5D6383ULL, 0xA56409DE09D9AF92ULL, 0xDBD77DA3E2DFBA5CULL, 0x4AAFF2B1C7A7E620ULL
        }
    },
    {
        {
            0x6551543945F531AAULL, 0xB20D1390002F5D79ULL, 0xF7217468B8B53C12ULL, 0x82B4C5667C058D42ULL, 
            0xCA35256BD8F3B60AULL, 0x77F212AD6A3A8E7FULL, 0x1F0F3A7AD9D247F7ULL, 0x85B1E7195EFC43C3ULL, 
            0xC6B91DEE4FD85D62ULL, 0x7FD02F2E28559B80ULL, 0x5B70C8BF2F1273CFULL, 0x8AEBB111068EBAC8ULL, 
            0x3C593B7506F9EBBAULL, 0xFCA1444161477BEFULL, 0x554298DD0E473A6AULL, 0x88BF37E08AA70610ULL, 
            0xDE1270838D5735E3ULL, 0xB9FD52F83C1DA1F5ULL, 0xC51EEDDB77FB3618ULL, 0xBBF277F6DDA2AA1DULL, 
            0xCEB1555E64ECB512ULL, 0x65956D30FCF295F4ULL, 0xBD8881449188A459ULL, 0xE35A6067E78F5342ULL, 
            0x5AAEC5C89A52C021ULL, 0x773201BB6759D95FULL, 0x1401980DDD271B0EULL, 0x59F6C42A8A972A00ULL, 
            0x58DC767E0BEF5B77ULL, 0xE59AAD922AE13FBEULL, 0x1A9EF9C5365141DBULL, 0x12C84C79773C9280ULL
        },
        {
            0xB367D0F98917D5C8ULL, 0x2D3748C0E50C2D50ULL, 0x429AD7892BCB80E5ULL, 0x7662F042A933B46DULL, 
            0xB8DCAF3BCE104D1CULL, 0x48A3041216914079ULL, 0xE2A2F9FE9256EFE2ULL, 0xEB01EBA0AAB06B7CULL, 
            0xB0D00DB15238C725ULL, 0x93790B73985E22DFULL, 0x22907BDB54571169ULL, 0xDC245621E8A00D7DULL, 
            0xFD5E44FF9B9CAC31ULL, 0xAC48BEFB20409FDDULL, 0xEC9DFA7B83719726ULL, 0x2019C348B6EE1790ULL, 
            0xC19DC4DE69BE433EULL, 0xE875249B9C332AEAULL, 0x5EAF5F5B0A40C2CDULL, 0x1A24C2A489846D8BULL, 
            0x9CED39FEBE89D47AULL, 0x30DD944AA2C9D8C3ULL, 0x9C7C422DC1AB4E19ULL, 0x8E26C14607186F83ULL, 
            0x0CF797CCD5CF5170ULL, 0xA4D3B3682FEDAF54ULL, 0x3FB2DD9315AF9D79ULL, 0xAAA37B37483F8303ULL, 
            0x1FBC849FDB22B444ULL, 0xCF613F5A49F793EDULL, 0xD0F0CED4D43868A0ULL, 0xEF79FFCBAED2E7F3ULL
        },
        {
            0x2EB53D7F1346429EULL, 0x921C2DB9F295C78EULL, 0xF2458F9099992718ULL, 0x4478A8C934CF5C6DULL, 
            0xA2F98687A1A4947AULL, 0x18C6FFB274D27E6FULL, 0x3E6DD7154DAF9B7DULL, 0x2284E78F2CE0F545ULL, 
            0xFF27918BC070CDE9ULL, 0x64D3E4155CC68D35ULL, 0xBDF2DBDDBA55D0E8ULL, 0xD6841D1FBA9F17AAULL, 
            0xCE60FB9519B0487FULL, 0x8C80C3BAD189DFF9ULL, 0x2F6C13594BDA226DULL, 0xE447E8D0C65A1961ULL, 
            0xC29F4279E33FB727ULL, 0x630315105ACDC201ULL, 0xA21C2746B9D7144BULL, 0xD039CE038AB927F5ULL, 
            0x489672DBEBD7DFDAULL, 0x760E8A758EB97131ULL, 0xAB0C31EAC593F0E7ULL, 0x97BD10E12A6A0301ULL, 
            0x7AEDCCDDA4973178ULL, 0xAAD7EE47584FC811ULL, 0x996F735E42C04DD5ULL, 0xD523A6094253A006ULL, 
            0x2B6C8395A4B6ABF4ULL, 0x98D60199A6204A22ULL, 0x6A35AC9EEB9D98FAULL, 0xCC0DC16F363E7800ULL
        },
        {
            0xCEDA47A5F45CC9E9ULL, 0x86D7F97F059CA0B8ULL, 0xE7FB5667DA5A111CULL, 0xC724352FAF95CF4AULL, 
            0xD7B5060F7D5432BDULL, 0x45FD8F04341A333DULL, 0x71F97841B9825E0FULL, 0xFBA0E6F575B7D519ULL, 
            0xABE6F383612078C3ULL, 0x561B8DB7337E15EFULL, 0x40BEFF30F072F921ULL, 0x41BBD0A3F3DFFE32ULL, 
            0x4CE426B1A4E8DD7EULL, 0x0E66FBE310D6FFE4ULL, 0xC8A0EF6A31D25BF6ULL, 0xA91EB2C79D0BD31AULL, 
            0xEF175EE049948024ULL, 0xBEEF5C735FE7F116ULL, 0xA5B8BC2AF0DFDC44ULL, 0x196E154445293C5FULL, 
            0x8AA2D22AD8F943DDULL, 0xC857E6FF351DF3F4ULL, 0x765F3D00BD85DAC7ULL, 0x37E7D4860D12BE3EULL, 
            0x1DCAFD4CF20853DAULL, 0x0245E1ECC2CADF57ULL, 0x5B2D061370C8721BULL, 0xA278D3B6F60A5C61ULL, 
            0x9E00E178456D0ACAULL, 0x17ADE8D9B9077ABFULL, 0xD845225914D8CC2EULL, 0xB9934F12831B4308ULL
        },
        {
            0xF00071B8AA6CAB5BULL, 0x0203CE863E96570BULL, 0x182C9A5B794E14E9ULL, 0x05B822BB3A1AE9AFULL, 
            0x4FB6A60D69A7A4CCULL, 0x59E43A0A200616C4ULL, 0x3CF4E1E13A0BC7B9ULL, 0x0CB072C5E1EECCE4ULL, 
            0x997C4BD30206FED2ULL, 0xA515008656B90FCEULL, 0x6834195107B56C9DULL, 0x27D36C6AD42DF5BFULL, 
            0x00C54D757E1CE497ULL, 0x2D8BDEB01F56BB5AULL, 0xEF97724AA906CF29ULL, 0xE38864554AB0688DULL, 
            0xE2A4CEDCF0F536DFULL, 0x75ED343E28325D3AULL, 0xDDF14FD726E71722ULL, 0x103EAB1A0598001BULL, 
            0x5ACAE0DAD65988A8ULL, 0xC459342F55E65BA7ULL, 0x05A7DE6003DBA1B8ULL, 0x28E789DD5A92DA1EULL, 
            0xF7AEA15A4A37B320ULL, 0x06DA1F97848E53C0ULL, 0x65215E78932EAE97ULL, 0x4050BEE65A637E25ULL, 
            0xB80CDBB5A6C0FE36ULL, 0x440EC03E3B137D35ULL, 0x38EA350AC262301AULL, 0x178DB879A3E0E7E8ULL
        },
        {
            0x87715C0580CABA17ULL, 0x4F26BFBC7632BB6BULL, 0x21F5D22ACC81B442ULL, 0x8E3F250D03D3AC32ULL, 
            0xC8EFE52057AEAA13ULL, 0xE06CD59D508AB739ULL, 0x979C64E40ED7ACC9ULL, 0x4D6F2129E1EB96D2ULL, 
            0xE697AD07EBBE04C4ULL, 0x3E2F41745B1047A2ULL, 0xDD6F113A4268901CULL, 0xB67D2DC82215622BULL, 
            0xC5D3141BFD909CD6ULL, 0x80E24597622C7701ULL, 0x55F77AFFFDBFE85EULL, 0x2073A0CD9B854746ULL, 
            0x779B35DBEBDB61FFULL, 0x544102ABAB718500ULL, 0x34F7047152C672A8ULL, 0x9427DAB5FCAF284CULL, 
            0xBC8EEA7A91911CA5ULL, 0x00E93BC573DAE000ULL, 0x993DD417A6A521CFULL, 0x052BFB0F3BA4A7F3ULL, 
            0x978D313BD6525381ULL, 0x715DDE7A4EED9431ULL, 0xB0998FDCCB228AECULL, 0x09530D0716DC9AC3ULL, 
            0x6098A2493ECE357FULL, 0xACC8756746D8735FULL, 0x06CC14A352F2E7BDULL, 0x783C82EDE9E23D11ULL
        }
    },
    {
        {
            0xA2E963CA2D8107C8ULL, 0xE45F24E4B028700CULL, 0x52DD3984FF8B6234ULL, 0xE615C3529188515AULL, 
            0xB5C8838C0FC72CE8ULL, 0x476AF4FA44EE4159ULL, 0x1577F9173554FBDDULL, 0x31D46F6DB705954FULL, 
            0xA82B97472B4EB5F0ULL, 0x2D7253397C013CDFULL, 0xA838B0A25A48223BULL, 0x70CA2E7A88C0A267ULL, 
            0x6A42FE0BC1ABFFEDULL, 0x7D9F2C768D96C266ULL, 0x366E95DD7D7047C8ULL, 0x9CDEB6E4BCDC34CCULL, 
            0xCD579C13966F5951ULL, 0x8CB8FDDB175A4977ULL, 0x2AA0A40DD9CCD51AULL, 0xAEE2EF1632CFAC15ULL, 
            0x25AED1E81EA77605ULL, 0xCC5B364BCE0C8F60ULL, 0x30ECEF17E8E37443ULL, 0xFFC79937058C9038ULL, 
            0xE65991545EAED81AULL, 0xB24DC37EEBB194FBULL, 0xA5A4881E4711B839ULL, 0x395E1CD49DE5B8E4ULL, 
            0x6A79E84E1460CA15ULL, 0xA43D8645A3AD727EULL, 0x55AB64E0CC56B5BCULL, 0x601AD873D3AD13EFULL
        },
        {
            0x60148C6E1EF72C6CULL, 0xAD7BE96F5094D74DULL, 0xBE30829AC564A61EULL, 0xE2A6E05F3DEEF011ULL, 
            0x06C8427ECF0AF80BULL, 0x3B2A01D179FECEFFULL, 0x865F63A000F5AA01ULL, 0x4BC8F8D68207E497ULL, 
            0x939E981E50BEC7F5ULL, 0x3E41A76AF83CB54EULL, 0xF7909D21A545C373ULL, 0x1B08C578F10342A9ULL, 
            0xE5B5E091ABF44577ULL, 0xA244969A0409634AULL, 0x0CA2B6AA2D5C6513ULL, 0x65074637A518B092ULL, 
            0x9C792113DBA21D94ULL, 0x9588982FE4488EFDULL, 0xBC3F5861FCB60465ULL, 0xC47A4E4354E1D699ULL, 
            0xDCC2FF593F1C24CFULL, 0x4DCEB090E39A8A95ULL, 0x9A8BB889B0CD8173ULL, 0xFAC186204C62F7DEULL, 
            0x44C2F06E5EB64FAEULL, 0xBBB9144EDBFD231EULL, 0x58A052D6D0DB0BF5ULL, 0x661E48D206FB5EF8ULL, 
            0x97186338E27FB4CBULL, 0x1008D351C2652983ULL, 0x547A7E3BE0962581ULL, 0x1076BB07070B527BULL
        },
        {
            0x070905D08923CC52ULL, 0x6436A4A2CC6F1503ULL, 0xCF30C9BDCDDAC0EEULL, 0x2A66EA4E4168E6D5ULL, 
            0x565588D66465791AULL, 0xAA319D6BD44BF975ULL, 0xDEF4D05A284A6C5EULL, 0x1ED9424ACB4DFE7BULL, 
            0x69B157D444F0593BULL, 0x5EA128F5310EE79EULL, 0xE80821C1153B0D28ULL, 0x21B71A98B49C146EULL, 
            0x05144AEEC4F00B96ULL, 0x5ACA5C54259663A3ULL, 0x1F0CDAD9B838E62EULL, 0x70F46B4E9A0A26E9ULL, 
            0x6B796D4C79275E36ULL, 0xAD6F8098855869F9ULL, 0x2E9AD62CC701C216ULL, 0x14B6A07DB206CB77ULL, 
            0x0AB447B5982DC6F9ULL, 0x20B4C632D6B2A6BBULL, 0x21B2FC48C2D5258DULL, 0x1F1958576EDDD08DULL, 
            0x710BF497C17C16B9ULL, 0x887A6532B5A4ACA2ULL, 0xC3B2365414452ABDULL, 0x3594E4C5281DEAA1ULL, 
            0xD5897CC18057305DULL, 0x6CD677D3BF07595CULL, 0x03A57879931B17B5ULL, 0x63A85E306B8B785AULL
        },
        {
            0x385F4D935A61D001ULL, 0x7E4DB8D207E751C2ULL, 0x2246D18BD007B357ULL, 0x37F5AAA77F5F429FULL, 
            0x81997A90A94442F3ULL, 0x751B84FBB97457AEULL, 0xFBF2262C81B1AFFEULL, 0x7E918F297AEFC0A7ULL, 
            0x9993684E5AFE5E1EULL, 0x632BF2AE56392240ULL, 0x0F2A7A5F891426D7ULL, 0x7D1D3B29CAD48587ULL, 
            0x47AA50815E056966ULL, 0xCCB3C7AB9CE12155ULL, 0x2205CD7A56F6947DULL, 0xCCA42B99018F8267ULL, 
            0x5F21E68FB17F2436ULL, 0x680144B836925DBBULL, 0xA0DB662F810FB3D5ULL, 0x2F676A2986B594C1ULL, 
            0x63322A87E464AD41ULL, 0x48FE5DF5E6456473ULL, 0xDCD9DF7003C70898ULL, 0x06BFE8E949C21327ULL, 
            0x85CB538A5B6321B9ULL, 0xA21ED2D0D9E8C98DULL, 0x808D08E1C9D96D31ULL, 0x93D969FB1F79A1BAULL, 
            0x7523F21A78DB8917ULL, 0xE9DDBEE2149106DAULL, 0xF8644B0CB3672264ULL, 0x056F36482ADC7964ULL
        },
        {
            0xC9B8C118F9182878ULL, 0xE19D8B5850900E8FULL, 0xE32B53F73C927CF9ULL, 0x905B59853BCE246EULL, 
            0x5036EEA61E485C34ULL, 0xEE2AA926E16D550AULL, 0xC4106367968C5057ULL, 0xA64770B2F5A48659ULL, 
            0xF7C381603E994BC7ULL, 0xAA275F39043CD0B7ULL, 0x105F1511F168604DULL, 0x26386C85B3C50EA8ULL, 
            0x7B2B672206E726F0ULL, 0x5A3219D8D8CB2F37ULL, 0x6BD8AB453EF60FABULL, 0xC418F8CE859BCF1CULL, 
            0xC4EE17C1E7689594ULL, 0x140D833E7CB63970ULL, 0x73901662B454238EULL, 0x6F7A6B0C3E8BA9B9ULL, 
            0x45734E5D1C244C6BULL, 0xCE115AEF97DEEA24ULL, 0x00930B8367FB119DULL, 0x2A89353A516AC522ULL, 
            0x4EE9B7DB3E7B3505ULL, 0x3C19A3DDC9464B2BULL, 0x7CD52B38EA71F035ULL, 0x349C16AB91902D22ULL, 
            0x20463E8D3C212417ULL, 0xA9FE469DB69A0CD5ULL, 0xB62B12F234A6E88FULL, 0x480923BB1FCAFC04ULL
        },
        {
            0x580A64EB938A6AE7ULL, 0xD4BCA2B60DAB75F9ULL, 0xA2B7EFAD515952E8ULL, 0x662FADB1A3415ED1ULL, 
            0x8951E42849B63C90ULL, 0x6D888B1FEA99CC05ULL, 0x48EFE679E1001709ULL, 0x0335AC0631A69029ULL, 
            0xBE82FDC353917AEFULL, 0xDD7BA267500BF23EULL, 0x22C996556D1BACFCULL, 0x35554C83B514AA6CULL, 
            0xA1CA4ECA01359EDDULL, 0x2FFE83DA84A8A27FULL, 0xB441DFCAE14FCC85ULL, 0x38F51B63CBF53507ULL, 
            0x74EA989BFC3EF143ULL, 0x06EA9C613B09E896ULL, 0xE987684B8D7955EBULL, 0x6C5BE07608D9A10BULL, 
            0xDD4F2488FC55DEB8ULL, 0x282F83E6C9CE9D09ULL, 0x14593DCA907E26FEULL, 0x74F30A0013A2C2CCULL, 
            0xDD0F315992CAB00DULL, 0xCDBBF4D3EFE446B8ULL, 0xDA3F6B57D0464D9BULL, 0xB69CDB134589B3D9ULL, 
            0x83B88510C6B84CA8ULL, 0xCDC3EBCB22A55094ULL, 0x684135378E87EE96ULL, 0xF832008D3F631EA9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseHConstants = {
    0xDED613FE4A3EC82FULL,
    0x685F0AF44F79C131ULL,
    0x0FEC349A41BE4C96ULL,
    0xDED613FE4A3EC82FULL,
    0x685F0AF44F79C131ULL,
    0x0FEC349A41BE4C96ULL,
    0xB19AFE0685833D0BULL,
    0x08F2DC97354DBA1EULL,
    0x4D,
    0x22,
    0xD0,
    0x98,
    0xB7,
    0xAB,
    0x84,
    0x4B
};

