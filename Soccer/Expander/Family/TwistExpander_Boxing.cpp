#include "TwistExpander_Boxing.hpp"
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

TwistExpander_Boxing::TwistExpander_Boxing()
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

void TwistExpander_Boxing::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xDB4299604425C7E4ULL; std::uint64_t aIngress = 0xA744994CEDDE47A5ULL; std::uint64_t aCarry = 0xD6F2F5AD3F7E7D28ULL;

    std::uint64_t aWandererA = 0xB6F5F16FCE38CF71ULL; std::uint64_t aWandererB = 0xB72F5900B49FBF48ULL; std::uint64_t aWandererC = 0xC4834B1B57A9F426ULL; std::uint64_t aWandererD = 0xA7042EC975D7FBF9ULL;
    std::uint64_t aWandererE = 0xCC28DD794C91DB36ULL; std::uint64_t aWandererF = 0x961FD386F12A94E3ULL; std::uint64_t aWandererG = 0xC4DFDFC0623483F2ULL; std::uint64_t aWandererH = 0x86E0921CF2007E8FULL;
    std::uint64_t aWandererI = 0xF973E91B2138909CULL; std::uint64_t aWandererJ = 0xAA8A9FB9A403D869ULL; std::uint64_t aWandererK = 0xA5D66474FE02962EULL;

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
        aPrevious = 14898081302270665272U;
        aCarry = 16234081413933374894U;
        aWandererA = 13999821848800463108U;
        aWandererB = 9360828788211201729U;
        aWandererC = 15699906084134384116U;
        aWandererD = 11920648942433968135U;
        aWandererE = 13546110066315657468U;
        aWandererF = 14863856379476685006U;
        aWandererG = 9291987296385494490U;
        aWandererH = 14546826397135179824U;
        aWandererI = 10068649239244908338U;
        aWandererJ = 13631917293045003224U;
        aWandererK = 9699452955281214847U;
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
    TwistExpander_Boxing_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Boxing::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x8C0A31585AC25F5DULL; std::uint64_t aIngress = 0x9609A7A00CF70311ULL; std::uint64_t aCarry = 0xB670B2A3773FC300ULL;

    std::uint64_t aWandererA = 0xAFBB4CD5E48D39A4ULL; std::uint64_t aWandererB = 0xBE17C92E3A4C0984ULL; std::uint64_t aWandererC = 0x8A77B6DA245F9635ULL; std::uint64_t aWandererD = 0x8C6DF939CCB40262ULL;
    std::uint64_t aWandererE = 0xC24D77581F6C1B4DULL; std::uint64_t aWandererF = 0xB4E74F3720FF2AA4ULL; std::uint64_t aWandererG = 0xCD4A9355B5CA6E47ULL; std::uint64_t aWandererH = 0xAA1A584BD44DBFE2ULL;
    std::uint64_t aWandererI = 0x9176F510D21D5B2BULL; std::uint64_t aWandererJ = 0x9E30DFD744686E5EULL; std::uint64_t aWandererK = 0x8547A2150EB856EDULL;

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
        aPrevious = 17937216669269380470U;
        aCarry = 17905134824700006522U;
        aWandererA = 17341140461322496121U;
        aWandererB = 15132828461786571932U;
        aWandererC = 11411849868552912557U;
        aWandererD = 15573001335888636248U;
        aWandererE = 12790874810498973943U;
        aWandererF = 15772592118533734647U;
        aWandererG = 17138845247941607325U;
        aWandererH = 12815432152342338786U;
        aWandererI = 15732213626908920099U;
        aWandererJ = 9668363286944071044U;
        aWandererK = 14533864505395196003U;
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
    TwistExpander_Boxing_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Boxing::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEF5DDA766981EC2EULL;
    std::uint64_t aIngress = 0xFEE2E0A412F35541ULL;
    std::uint64_t aCarry = 0x8F1036C9ADED36ADULL;

    std::uint64_t aWandererA = 0xB768A85740F33B96ULL;
    std::uint64_t aWandererB = 0xA86BDD06AF781867ULL;
    std::uint64_t aWandererC = 0xD6FE7B42AB6508F6ULL;
    std::uint64_t aWandererD = 0xE8347EEF2D343637ULL;
    std::uint64_t aWandererE = 0xDEDFD0165DC18CFEULL;
    std::uint64_t aWandererF = 0xD76F187E3EDDE856ULL;
    std::uint64_t aWandererG = 0xC6EE94A16DE16FF9ULL;
    std::uint64_t aWandererH = 0xF55FE6519F54379EULL;
    std::uint64_t aWandererI = 0x88C54EB5CF4E6C5AULL;
    std::uint64_t aWandererJ = 0x8022F1E8B1430A56ULL;
    std::uint64_t aWandererK = 0xF9F615504BF9EBD2ULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA, 1);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD, 2);
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC, 3);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB, 4);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneG);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneF);
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    TwistExpander_Boxing_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Boxing_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Boxing::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Boxing::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x95250242F0517324ULL; std::uint64_t aIngress = 0xA407AC6654D188C6ULL; std::uint64_t aCarry = 0xA15BE2FB19C0F1C7ULL;

    std::uint64_t aWandererA = 0xC9A4105F6D076BDEULL; std::uint64_t aWandererB = 0x98BBCD982380EBC2ULL; std::uint64_t aWandererC = 0xF2CECE87ABFF1848ULL; std::uint64_t aWandererD = 0xB27A4ABFFFB32886ULL;
    std::uint64_t aWandererE = 0xFC36094EA90DDCFEULL; std::uint64_t aWandererF = 0xD96315928D0AF020ULL; std::uint64_t aWandererG = 0xF482D7D352CCF717ULL; std::uint64_t aWandererH = 0xB37F864A4445F692ULL;
    std::uint64_t aWandererI = 0xB6C9108755D877E1ULL; std::uint64_t aWandererJ = 0xEBE7948B5E251E35ULL; std::uint64_t aWandererK = 0x9870A50323508B28ULL;

    // [seed]
    {
        aPrevious = 18195075829412229457U;
        aCarry = 13534370320661573617U;
        aWandererA = 12877322421158112669U;
        aWandererB = 14314341205633232094U;
        aWandererC = 14716426501385915598U;
        aWandererD = 16339578356644496550U;
        aWandererE = 9833575634879118099U;
        aWandererF = 17925196308311762853U;
        aWandererG = 14163292264398776840U;
        aWandererH = 10869669637457906807U;
        aWandererI = 16001696880220841561U;
        aWandererJ = 15727765743697119909U;
        aWandererK = 18302658922578350492U;
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
    TwistExpander_Boxing_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Boxing_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Boxing_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Boxing::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 0, 1 with offsets 5394U, 6771U, 1914U, 1491U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5394U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6771U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1914U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1491U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 3, 2 with offsets 4172U, 1538U, 3309U, 3266U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4172U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1538U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3309U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3266U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 1, 0 with offsets 2268U, 1502U, 5494U, 5728U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2268U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1502U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5494U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5728U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 2, 3 with offsets 6535U, 3354U, 6390U, 4326U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6535U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3354U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6390U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4326U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 2, 3 with offsets 691U, 445U, 138U, 571U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 445U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 571U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 1, 0, 3 with offsets 885U, 399U, 1981U, 982U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 885U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 399U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1981U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 982U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 2, 1, 3 with offsets 2042U, 993U, 882U, 1498U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2042U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 882U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 2, 0 with offsets 1300U, 1920U, 1337U, 198U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1300U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1920U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1337U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 198U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 930U, 1478U, 583U, 1011U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 930U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1478U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 583U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1011U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Boxing::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 2, 3 with offsets 6638U, 6062U, 784U, 1187U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6638U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6062U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 784U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1187U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 0 with offsets 3106U, 1875U, 5124U, 4297U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3106U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1875U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5124U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4297U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 2 with offsets 5483U, 6347U, 4831U, 744U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5483U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6347U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4831U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 744U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 3, 1 with offsets 2465U, 303U, 160U, 6223U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2465U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 303U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 160U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6223U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 6620U, 7381U, 4651U, 41U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 6620U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 7381U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 4651U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 41U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 394U, 1670U, 1888U, 462U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 394U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1670U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1888U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 462U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1733U, 1464U, 549U, 1895U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1733U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1464U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 549U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1895U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 221U, 182U, 1063U, 1575U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 221U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 182U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1063U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1575U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 781U, 657U, 677U, 1738U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 781U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 657U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 677U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1738U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 1, 3 [0..<W_KEY]
        // offsets: 833U, 9U, 1403U, 737U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 833U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 9U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1403U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 737U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseASalts = {
    {
        {
            0xD44764223D2824EAULL, 0x9467976288660A93ULL, 0xA3B66F3DFECFD9C3ULL, 0xE2476C8167C0E832ULL, 
            0x6D0D25F9D33B07C5ULL, 0x757216C08DCC4D12ULL, 0x5A0E893551C0F7B4ULL, 0xE64B0D4089AE03D4ULL, 
            0x0C33736077129223ULL, 0xCCA9144E17C277C1ULL, 0x56AD39D368DDDD57ULL, 0x146BB9EE6FF79313ULL, 
            0xECE760143C6ED1E4ULL, 0x7C95FABE58EAA8BBULL, 0xB9A084CEB2FB7393ULL, 0x3E02CD23B220158AULL, 
            0x582A0AABB08E9DDEULL, 0x338B28F6FE1AD51AULL, 0x7EA55A4E4B69F632ULL, 0x7CCA9F6815281C70ULL, 
            0x2688B4324F4C82E9ULL, 0x931AEE5D6CA0026FULL, 0x5EA3A50DAF2404E3ULL, 0x8968592CE7358F9BULL, 
            0x965DD90A4263329AULL, 0x34EB4248053762C8ULL, 0xF6DBE4A054A492C4ULL, 0x7C7EA1F9434B2FC3ULL, 
            0xBDE075CBDCBEDB20ULL, 0x73FFD07502FB2AC9ULL, 0x1DDFC02BF053A1D5ULL, 0x49E25C64CF062C31ULL
        },
        {
            0x8867F3E0E98F83E5ULL, 0xB8D1EB8318E697C5ULL, 0x452166F3D42D4F23ULL, 0x0772CBC6BBD439BCULL, 
            0x6804CF93220E227EULL, 0x4096B9CFCEE19D46ULL, 0xA23ABF21C152440DULL, 0x46127E5A353C0DE1ULL, 
            0x7DBF19FD006EDAECULL, 0xBBD1D09703C62F4DULL, 0x3FDF351DE5E41E1CULL, 0xA38E0B1A0E29AA98ULL, 
            0x015136CD06966EAFULL, 0x11A2275F9FB4E2E0ULL, 0x777A0F8D477CB4EFULL, 0x16059199C578B19DULL, 
            0xA1AF73FCA7B8BDD3ULL, 0x8BF923F3AE3842F2ULL, 0xDABCD8B1868D6763ULL, 0xBF17B2F234541302ULL, 
            0x9E595DF901F18C79ULL, 0xFDD3D6D068049070ULL, 0x2C391862E088544CULL, 0x92F12DF03CCA4956ULL, 
            0x42865E85F8417AA9ULL, 0x93DD3DB41F0DD62BULL, 0x1B72223D07A00A46ULL, 0x5FC01699ABEFB870ULL, 
            0x6FEEE89700435BF4ULL, 0xEAAC613F412B22B6ULL, 0x78DBEF86A585BBE9ULL, 0x6E4009B80671A0BDULL
        },
        {
            0x07F0C683A6D7D4EDULL, 0xCFD7022904F7FD61ULL, 0xEC4CDC5ABC02A63DULL, 0x5617A3EDD0F08D39ULL, 
            0x6F774AB37D8C350CULL, 0x30C0675F012E02B0ULL, 0x6FC1DB44D02FC72DULL, 0x9EE1E56E0FDBEB8EULL, 
            0xACB312513470DA15ULL, 0x17EDFC562B5D4EF8ULL, 0xCBF4D18CCC083C6FULL, 0xDF75F7FD20DD8A60ULL, 
            0xD2D487FD3A37C61AULL, 0xABF6247DB005578DULL, 0x5BA5F0F464CB2BD6ULL, 0x80F18D11CA9412B7ULL, 
            0xC99D8B9E7A405844ULL, 0x11E826A2EEE56A98ULL, 0xC3329DB4C05B4EE2ULL, 0xBB09130C57D7C34CULL, 
            0x4DD224D99E0EBE9BULL, 0x6A28C38B252E9ABCULL, 0xC1C38676516737E3ULL, 0xD7C8484EAA18CA82ULL, 
            0x482000C52AA6743AULL, 0x713D5625438FFF2FULL, 0x7D39FBAE54BCB781ULL, 0x49DF10F03527892BULL, 
            0xB2261B1E31E2FF9CULL, 0x06718633A461EB66ULL, 0xA356DCE57E41F02AULL, 0xD2B216B0E6E165F7ULL
        },
        {
            0xAC4E9D0586AFF0F5ULL, 0x1635B2A57555E2CDULL, 0x333986FDBA7CCB2BULL, 0x25488EA7C450BAA3ULL, 
            0x327EFA8816B2A41BULL, 0x6DAB45F5EBE455A2ULL, 0x8D2DDC6D8A4990A9ULL, 0x67ACC8E9757272B7ULL, 
            0x52ABA4965B49A4E9ULL, 0x433F5ECBDB80CAF3ULL, 0x9E43A385D9B29CA3ULL, 0x334431E837FC24DFULL, 
            0x786F7C08D3D80865ULL, 0xAFA0BD063D0BFAC1ULL, 0xA6F2CF6035506EB5ULL, 0xAA1A8682D4A74AA1ULL, 
            0xA285886909262824ULL, 0xDD01A7DC516ADFDEULL, 0x465716062379114CULL, 0x5C3B2288A8BE83EFULL, 
            0x810471D3ECF345D0ULL, 0x3D6A831B966BC514ULL, 0xA73AA15A484B1DF5ULL, 0x004FB346BB95C80FULL, 
            0x6F9EDF5285DA8373ULL, 0x557711458E8D12A9ULL, 0xD4A4E6E96AF4955EULL, 0x50A4B73AA12E851DULL, 
            0xD701D8DB762CE8F0ULL, 0x84778D59D0C19D0CULL, 0x9BD356557C501A7DULL, 0xB7E9443548D0A19DULL
        },
        {
            0x04EE85C616C01E2FULL, 0x6C58894D781CE8FEULL, 0xE21DC32D58D3CA8DULL, 0x342329B628A2BBCFULL, 
            0x4163E98585CDD0A8ULL, 0x80D2EF3D79EB7802ULL, 0x9C110F131B7A0F4BULL, 0x0172828CAC887F59ULL, 
            0x08D17553D5767C6EULL, 0x14EC9AB72EC62BE2ULL, 0xCAA773E4286A4451ULL, 0xDE306255409A8E3AULL, 
            0x1D3F4D8475770D94ULL, 0x056487B251AF0554ULL, 0xC379D18FE7933E54ULL, 0x15993DAAF3F52FACULL, 
            0x557F401FCCB157B0ULL, 0x23F32A5776331636ULL, 0x810514EFC119C0F8ULL, 0x21BB35F523B92CE0ULL, 
            0x6030B452A3B69666ULL, 0x86F5FC3C7B77A158ULL, 0x721B921C67AF366CULL, 0x3819FAC245E781E6ULL, 
            0x5EC3826661C1678FULL, 0xC2D0928D3EB8257BULL, 0xA7B051A549FD1FBAULL, 0x4FE991F4248DA692ULL, 
            0x527CE049E4C0F4A7ULL, 0x29E02B45B4B552BBULL, 0x29011FB28CB314D2ULL, 0xAA42D8B7E4D2268DULL
        },
        {
            0x2E1D365B1A940630ULL, 0x37108FB731BBB40EULL, 0xA0275E678566E0D2ULL, 0xC71B132B26F9468FULL, 
            0xFEB572CCF31C1DABULL, 0xAE91D9D23E892B7CULL, 0x28533840FD43EEA0ULL, 0x135F5D4ADC55BFDFULL, 
            0xA496EFA2F41BCAFCULL, 0x77E6B44CF3D0154AULL, 0x0B52A383D8C809FEULL, 0xB4DE1ECC83AE70A8ULL, 
            0x1E16636A5C8719E1ULL, 0x6C76C55B83878EB7ULL, 0x8D8AEEAC02EDB3FAULL, 0x624AA112A434608CULL, 
            0x12726F7746A780C0ULL, 0x3511B5C306FE67A2ULL, 0xE483DA19AE1B743EULL, 0xF2021DBD6A9F72A6ULL, 
            0x9B9E3658AF0CDD51ULL, 0x5286B698BBC52006ULL, 0xA479609DBD2A5BCAULL, 0x34CE9765C6AD8F9BULL, 
            0x0A690ED69A98EAAEULL, 0xDBACE9DE03A8FA0BULL, 0x96C1685401F26E57ULL, 0xE0F674613950EF27ULL, 
            0x9EAFECE30E84D52BULL, 0x489534E7A6AE290EULL, 0xE38DA4FF846850A1ULL, 0xEDD585668984BB74ULL
        }
    },
    {
        {
            0x8842BD03B9D80165ULL, 0x2D116253D42A1FFCULL, 0xD320597E73F02D7EULL, 0x80872C2BB3659B7CULL, 
            0x5FB7DE445FDA9541ULL, 0xA5001A0DCA1F1344ULL, 0x67717F42103AF34DULL, 0x7DDB004BB0BBD9D6ULL, 
            0xC535074E0516734BULL, 0x5EA3A2E9E1D8ADC8ULL, 0xDE972BCE0BB33F08ULL, 0x3B65C3DA84072F0DULL, 
            0x671D2806D016B076ULL, 0xE26178165EC23AC0ULL, 0xF2879C80F0695E23ULL, 0x84C5A47481A37D78ULL, 
            0x95D93B88F4B1E301ULL, 0x03AAF0CE5C8EC507ULL, 0x9338E94D54B910E7ULL, 0x271E2140D925C00DULL, 
            0x0752BC0303D56CA3ULL, 0x088D8B8F7CE2BECCULL, 0x78340CD9362686D3ULL, 0x1D6F2EC8C4F1AE12ULL, 
            0xCAEF46CEBC987978ULL, 0xCEE6B4C9B684A92DULL, 0x669B1DF0CFD89E54ULL, 0xA40149DC6F5F5ACEULL, 
            0x741B1DFD1B594B10ULL, 0x38AF748BFE87ABE6ULL, 0x97F314BC0D6714D5ULL, 0xCB16FE1C01D67657ULL
        },
        {
            0x3CDA2DD04862B4EBULL, 0x5E9D40343FB53ABAULL, 0xF2E2A86CA18871A6ULL, 0x11AA82E1C0B6F188ULL, 
            0x524A4D94ACACA843ULL, 0x439AC7219CED043FULL, 0x624E9298B7C53481ULL, 0xE6B6351605294F7DULL, 
            0x879E13EA498B63C0ULL, 0x45D4407CFAF795C3ULL, 0xEF17387F6B097E9CULL, 0x2B50FFA30CBB19F8ULL, 
            0x640AF442DC89F089ULL, 0xDD17D7D4F28F28C2ULL, 0x7AA91A07501C7081ULL, 0xA3094B2F8660DC8CULL, 
            0x86D246598C8B84F1ULL, 0x238127A5462532D0ULL, 0x789F0C8B047F14E4ULL, 0x123C0FCF22B2EAA7ULL, 
            0xFE945E7D32C2CABEULL, 0x4DE643CFFEFE99D6ULL, 0xC8A47FBC12EA8DA9ULL, 0x76A8E7B2E207116EULL, 
            0x3A75CBBD9231AC5CULL, 0xF5625EEBFD88C5CAULL, 0xEEB2192264C10E19ULL, 0x9FCC908910B19DC1ULL, 
            0x00743780B14110C6ULL, 0x4D72DBC671127F2CULL, 0x24A0AB356BC9C94CULL, 0x0C4555E31DC1FFCEULL
        },
        {
            0x29CBB69198360745ULL, 0xC3444270668893BEULL, 0x2D9D091942510417ULL, 0x12B65E7FE9AD39C6ULL, 
            0x8E40FB94D2227CC7ULL, 0x5CBA8E1E8A1493D1ULL, 0x603EB6A7146EDE51ULL, 0x3E42970293EFF823ULL, 
            0xFA3E24F356D37927ULL, 0xA4C1EB1BFDFF5458ULL, 0xDC1C4F5BF70CC651ULL, 0x281919533FDC9064ULL, 
            0x432F9BC1227EDB2FULL, 0x7FFCB0BAADEEFE00ULL, 0x806251E7D4539C10ULL, 0x6BCADD5E16A06ADCULL, 
            0xDAC6B4AE1ADCDA2AULL, 0x020A7B2AD549F2EDULL, 0xA7AC2F19CD6F126EULL, 0x608D7D01D73200F7ULL, 
            0x9897C7E0D74F8528ULL, 0x4BB4DE3DD4E3C6C4ULL, 0x6DFF8B1AEACD1C2EULL, 0x7590AF8F83D3F8B2ULL, 
            0xE8C66CA7F6868982ULL, 0x32728ABA8ECC50BBULL, 0x7EF23CD3A3F60100ULL, 0x794ED52311AD72FAULL, 
            0xC82CDE32A822B355ULL, 0xA4819C2C87DB2717ULL, 0x40A3F9AE0378A92BULL, 0xB9B4114740AED014ULL
        },
        {
            0xCD718ADA135EA6B9ULL, 0x12EE441B20B2F4F4ULL, 0xAD6E964392C33EEAULL, 0x00569AD6A152A960ULL, 
            0x641595AA3F0FB210ULL, 0x32AA883BC55C4398ULL, 0x9C289D0B6B384046ULL, 0xE36102317BBB59AFULL, 
            0xF79EB8C58C50DE20ULL, 0xB7CF8F299ACC9A88ULL, 0xE2C36C4B07677A75ULL, 0x72832CBA6BD556A2ULL, 
            0x7F83579288B1EA7EULL, 0xD81E15849DC46595ULL, 0x06BBDE25AC1484BCULL, 0xC03799DDB3A8963AULL, 
            0xB85D41973E5701D8ULL, 0x7062188D6E8D5E65ULL, 0x29BD5F620A6EBC4FULL, 0xE55B4C4F855E25EAULL, 
            0xEC377A0C97EDC1D3ULL, 0x4FD6DD809A276051ULL, 0xCD22EEA4BAB552A7ULL, 0x81EA6D2DAC52688CULL, 
            0x32288FE4B193D661ULL, 0x988D638CFD4A0B81ULL, 0xB789A2F14259DB65ULL, 0x20EE0CD03D1E4FDCULL, 
            0xCDBF0F0A75688EAFULL, 0xC4396B3E095A7867ULL, 0xEEF815F33370F0DEULL, 0x0A5DEF50D84B879AULL
        },
        {
            0x242229CD261AB16BULL, 0xFB504EF089F51217ULL, 0x2619912426143096ULL, 0x95C30591A96A6817ULL, 
            0xBD7CAB56F47906FDULL, 0x1C5FBCDFBB606BD9ULL, 0x64FF673CF4F3BFFBULL, 0x727EE90B0830F7C5ULL, 
            0xA479CDD792F1967FULL, 0x37D266D7A4593DF9ULL, 0x59F6758C5E26D176ULL, 0x63A70DB02BC06EAFULL, 
            0x543E9F581B2A688CULL, 0xA26D0A5DA6E55063ULL, 0xED6D74D377FC027AULL, 0x3E3C5CBC46593F0BULL, 
            0x81B5A0EC666C34A0ULL, 0x6CDD0DA4FA066975ULL, 0x95EBD6F39DD8FA6AULL, 0x0FA9BD103E9069B4ULL, 
            0x41E306E6DC23695EULL, 0x2CFA4A81A09F0B9FULL, 0x46A0DE5B176DD36FULL, 0xF370940D2B72C0EBULL, 
            0x23770C04B0D835A3ULL, 0xB9CA410405C2E93AULL, 0x7946E24CEDC7892AULL, 0xEE053DEF09C874DEULL, 
            0x774004D7C9099A43ULL, 0x9E0666887D5C9869ULL, 0x0D051672EF4D5203ULL, 0x9C8560F4BB5A9F25ULL
        },
        {
            0x318E6ADE1236FAFBULL, 0xCD86D91B52746836ULL, 0x8EF34399A8806243ULL, 0xF7DF14A33F3F7366ULL, 
            0x40659943862B1382ULL, 0x39233A4BAEA1DA14ULL, 0xD6A1AE164DB5DD24ULL, 0x25F3147A5376393CULL, 
            0x6D972D9C2C02C81AULL, 0xD24C8251E2977D32ULL, 0xC3E89C131E9B7819ULL, 0x4AEBDB33EBF5E174ULL, 
            0x3785D33398ED2238ULL, 0xD6FA418954EAA591ULL, 0x845DDE59B77C208DULL, 0xDBE28DC7E439D689ULL, 
            0xA3150E79B5CE2271ULL, 0x0F430D7EF0222479ULL, 0x94BD4BC729E9D49DULL, 0x4165D2C1292C4B40ULL, 
            0x0B5DC4772973DECDULL, 0x6F75BC47668D4E46ULL, 0xA14A563C71415369ULL, 0x582D770B8E2AF00FULL, 
            0xAE82E5529F7C08C7ULL, 0x350F8262D8631358ULL, 0x00DDE59DC9C8B747ULL, 0x849E1398D2CF463BULL, 
            0x91DAD06CB5ED4A09ULL, 0x6D0FCD40708E9B10ULL, 0x1933A0C7B272AFB2ULL, 0x6A97705B98E6AE6DULL
        }
    },
    {
        {
            0x80218B26F1EDD4B0ULL, 0xDB5679FB9E5C64E2ULL, 0xA5DEA898F6CA7C3FULL, 0xDA4BED5C9EE132C2ULL, 
            0xB65B9D7D690FFF40ULL, 0xBB2F2DB26BE7E0B2ULL, 0x95B158DDE171A04EULL, 0x6840F6AAFC1B055FULL, 
            0x5E121FFB9B68442FULL, 0xE0BDFCF7F5A4CE2CULL, 0xD0E08B230DEEB031ULL, 0xCD4186895A57F89DULL, 
            0xBA14553B14F89F3AULL, 0x1B7EF0511AEDE634ULL, 0x6D9CE012283C88D2ULL, 0x7FDA5B23F9757308ULL, 
            0x36E5A7C5F126ED2EULL, 0x3E4018190348E557ULL, 0x9645F4E300F5D1B1ULL, 0xC2C8A976AFB56E29ULL, 
            0x3B63BEE3C258EA90ULL, 0x395F21BE839EB96BULL, 0x13C1629FD6B0E42AULL, 0x9D13F9021F1F65AAULL, 
            0x2E6070BED97E1628ULL, 0xCA1C41ECDB01AC82ULL, 0xDD2945882E52E540ULL, 0xAB0AC37985E80B74ULL, 
            0x07FEB7B61049F448ULL, 0x3497BBEB23CBFC1AULL, 0xF7C7263986E9C38FULL, 0x5EC23D5353E2F389ULL
        },
        {
            0xC19DD7264CEB00CDULL, 0xC6F6F76D3DC9F2EAULL, 0x6EA79FFDDC4CFFAEULL, 0xB11526D2D1E036ABULL, 
            0x70C5420D3DAF47A6ULL, 0x0D4D5299E5611D9FULL, 0x07381751F10DF328ULL, 0x6CFF6D0E04202F61ULL, 
            0xD26ADD2F1BD88F2CULL, 0xB419824EADE81B40ULL, 0x6DF2C2E5E41B3F9CULL, 0x9AB2E03AD61B3BDEULL, 
            0x6028AD9FA8F3CA81ULL, 0x0E29EB1C91C6DC74ULL, 0x252459B6826F08E6ULL, 0x32BF2637641411DBULL, 
            0x1B942B51A4128C13ULL, 0xEE88D8BB8F6F4BFFULL, 0xAACE35C4CA63C62EULL, 0xC90838F0F73BB79AULL, 
            0xCED6F61F5ECE2C5CULL, 0x3CE717F887648C52ULL, 0x3410DF0B71BC7D3FULL, 0xB95F0DE6B961DFB0ULL, 
            0xC2F0A1F010BA5565ULL, 0x94E5DFA14F173731ULL, 0xFAE9441A309FBDFBULL, 0x611076FDC886F638ULL, 
            0x08824A2185C0E482ULL, 0xC5C5C055A050C122ULL, 0x7EE45F71A9F38F7FULL, 0x26AEDF442CF24F52ULL
        },
        {
            0x5D6BE731955A2E3DULL, 0x65A4F555CB300826ULL, 0x0C05556781E16CF2ULL, 0x29A04A5BAAB66DD2ULL, 
            0x59983A8B60FC2BEAULL, 0x5A9AAB54428CC78BULL, 0x36839146745952D3ULL, 0xFC8E465882FC7B49ULL, 
            0xEF98D52D001C27EBULL, 0xE3D30487A275B2B1ULL, 0xCA67ED2E82EC0079ULL, 0x100DA8D34DFE5048ULL, 
            0xE735C9D14BF0CA86ULL, 0x21B36F0C9A423733ULL, 0xB30DFAB3D9DB1093ULL, 0x7279D00CD74B7B53ULL, 
            0x5410326399B09719ULL, 0x6663B0BD3D616107ULL, 0xA1A7B3FD4FF41A18ULL, 0x9049FDED9323609CULL, 
            0xB689266660973363ULL, 0x048EDCAC7521626AULL, 0xCBAEF3B9B9C5C755ULL, 0xF5D342E31B1CAC91ULL, 
            0x35C97E9675CA31DEULL, 0xF1436D41E4582D2EULL, 0xBFC15473E5F0B6A1ULL, 0x57721EB916700464ULL, 
            0x4D1A8BCE515D01C7ULL, 0x74F31C4FB13DD312ULL, 0x64715BA6D3A24DCBULL, 0x9F1568815C8F3FC7ULL
        },
        {
            0xB6416AC4A3D2E7C6ULL, 0x902142D05B146737ULL, 0xA46BD8994269C92BULL, 0x9CF663442185A348ULL, 
            0xA2F6CC0F4FF8286DULL, 0x1E8ED876E2D704ABULL, 0x7C379388435FE2E3ULL, 0x05BA188022A7B1A1ULL, 
            0x482F9359CB0E8CB3ULL, 0x4E9E44F511F29709ULL, 0x18844BBE2EE87C51ULL, 0x59A1ECF9C5586B9EULL, 
            0xD26048A0FA034895ULL, 0x351EEE4BB504FFBBULL, 0xD7910AF1E24ECCD6ULL, 0xAB7C9F3C3F424A17ULL, 
            0xDC0308EEC62C5F3BULL, 0x215D2A4C2EF0B6F5ULL, 0x580A0D6C3FC7E3B2ULL, 0xAE6E71665F2A0533ULL, 
            0xA7422E57A2C57CC3ULL, 0xADA559CFA6A89ED5ULL, 0x9B455720F45A7E71ULL, 0x83F813E0B71D1F8DULL, 
            0x5CE4CE9A0C8D006DULL, 0xB391CC37940A274EULL, 0xFF4853A674205633ULL, 0xC0DD6016DE40B136ULL, 
            0x69E2C75F046A5561ULL, 0xD730012C381E0EA4ULL, 0xF13A7F0EAF6622DBULL, 0xAC1BEBF28A4D12B3ULL
        },
        {
            0x8EBB1E535834380FULL, 0x9DAC076955025FB2ULL, 0x7A19A4A16EB8A50DULL, 0x61DA154BDE5AAA2FULL, 
            0x544991890DFD0FA0ULL, 0x62BF375698626723ULL, 0x89CE73A6269E761AULL, 0xAF39359FA798D034ULL, 
            0x23EAE45B1D9793E5ULL, 0x6CBEF389DBE8812BULL, 0x1C918BCB54CE8BB8ULL, 0x84305918EFE9141FULL, 
            0x0A753961C959210AULL, 0x1D32528E2C81B09DULL, 0xED10B930FC808D38ULL, 0x9F56BDA23677647DULL, 
            0x15F4E89B754A048BULL, 0xC152B998E81FAF90ULL, 0xF19AF9349BE52962ULL, 0x6665891CF7BBC675ULL, 
            0xE70CE3C7CBA5FA73ULL, 0x3BB0021CC296F177ULL, 0xCD96408B7F44BF01ULL, 0xDEBE537080816B7BULL, 
            0x6DBC733C23606363ULL, 0x20AD6B3ABF1A2CEBULL, 0xE153AC07E41E76F5ULL, 0x7A2C5A48D56E4F3CULL, 
            0x00D742805CFDD28FULL, 0xE6567DFAE9BE6109ULL, 0x39BD043027876339ULL, 0x3DD0529FF037E0FFULL
        },
        {
            0x10F8F4E3726F0208ULL, 0x2E43179BC8072E4CULL, 0x3EC5F454E99C11DFULL, 0xFEC6D614FB51089FULL, 
            0x313B28E246193BC3ULL, 0xFCB8386BBE3FD99BULL, 0xDEB2C243F605B30EULL, 0x9502949833A2EC13ULL, 
            0x8E371BF5D8EFECD2ULL, 0x611295F4C5CD7F50ULL, 0xDB506A0B17ACCA9CULL, 0x072496ED1150F18FULL, 
            0x39475D7FE2EDECE6ULL, 0x3FA6729B5976C29BULL, 0xC93F12E31ACCCAE9ULL, 0xB0EAC396AA1CAAE6ULL, 
            0x7485CEACFCC04308ULL, 0x17F0AB38B1DB7E16ULL, 0x907C3E1B7AC1B63CULL, 0x6E5DB6CC643BD7CAULL, 
            0xE6E8B07C0415271BULL, 0xFA657EAA8D89386DULL, 0x93805140E7CA0331ULL, 0x98C83766D669E61CULL, 
            0x35B52689A91925ECULL, 0xAA1F1EBD6DCC772FULL, 0xFE62117A3700CE18ULL, 0xF405ABB72EFCC328ULL, 
            0xE67D374E7F140068ULL, 0x4992B95D03FE47ECULL, 0xB256EBA65AE7B7FFULL, 0xC731D1F8C98FA7AFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseAConstants = {
    0x8AE6F31139139DF3ULL,
    0x9BDE0B45FE3AE9B3ULL,
    0x1773638920CA3CBBULL,
    0x8AE6F31139139DF3ULL,
    0x9BDE0B45FE3AE9B3ULL,
    0x1773638920CA3CBBULL,
    0x34202D6A04791790ULL,
    0x970DD3669223E7F4ULL,
    0x68,
    0x4D,
    0xC1,
    0xE7,
    0xEC,
    0xB1,
    0x03,
    0x14
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseBSalts = {
    {
        {
            0xE4A6CBE6EC799432ULL, 0xB317F0F95FBF7B8CULL, 0xA9FBC1D007998629ULL, 0xD670C4D8C1A32596ULL, 
            0x6FB88268EAB08F78ULL, 0xFCEEB0B542027FB4ULL, 0x583BE34AA8047680ULL, 0xCC44628AC6C0D3E7ULL, 
            0x858A5BD65C50C78FULL, 0xF3118AFAD56B4889ULL, 0x1EE4DD985DBEB220ULL, 0xC17DDB4243B940DBULL, 
            0x8E5160640D456DDFULL, 0x27B48362235CAB73ULL, 0x3A775D0D4EB1EE36ULL, 0xE192C6F969BEA354ULL, 
            0x6370D565C73DC6FFULL, 0x6274B205E1F8139AULL, 0x3711E83295087B41ULL, 0xB64A8008E105B26AULL, 
            0xD897DBF43ABC7186ULL, 0x9CABC173DFCCB5E1ULL, 0xBD06DB15078452AFULL, 0xCBCF5C641D9E2B41ULL, 
            0x88E0F636E1B60653ULL, 0xE36BE13C50C90707ULL, 0xD8C6302705E5ACA9ULL, 0xFDB340BB6F0693E7ULL, 
            0x62E489C1A96E7B0EULL, 0xEDABF2F086BC4398ULL, 0xDECA80AEB3E39A68ULL, 0x7AA5CDF4EA1D60E6ULL
        },
        {
            0xFA3C8FCD678DA00FULL, 0x17B8AA24FC856EB6ULL, 0x2ACB8E0C3F725C35ULL, 0xA2B7AD85D486679DULL, 
            0xFB8979434A7F3F22ULL, 0x38834B6EC451BFDAULL, 0x8013C8AC3EE95FD0ULL, 0x28EBC20C410A262CULL, 
            0x1D9F36F1BCDEC34AULL, 0x018C09F6FCE0686AULL, 0x9435EAB0D33420B4ULL, 0x90A67449B0EE2843ULL, 
            0x4292F049FEB75A6BULL, 0x0B863B83AE51FC0CULL, 0x97DEB0654F59A68AULL, 0x7D20C0A788F32599ULL, 
            0xC722D33129B3FA13ULL, 0x0402AFC89C1FD716ULL, 0x96347CF54B20DADAULL, 0x08C8C4A1473B4AB5ULL, 
            0xD8F53933D1604692ULL, 0xEC4026978B4BF305ULL, 0x09D6D3C46252B799ULL, 0xAC9837AD17379990ULL, 
            0xBDF616C8B4F66D52ULL, 0x43FD61FED23C9F22ULL, 0xB511A7F31F894C27ULL, 0x0219C93CAA8D615FULL, 
            0x3D9889E44F8D5F5EULL, 0x72256548E123D7D8ULL, 0x3D1F4FA394551180ULL, 0x7228573556E73DAFULL
        },
        {
            0xD2FEC5BC4CC6387AULL, 0x9B8C632909A8CC4CULL, 0x0381738299095843ULL, 0xF43B4000303C4A15ULL, 
            0x28F3AAD6A07694E7ULL, 0xB91F9B8D18A932DDULL, 0xD3188EAD2C919F1FULL, 0xF548A19F6E94BC4CULL, 
            0x2F0C391F182DA69CULL, 0x2B407D50D7D6F928ULL, 0x1CEF1484CDAAC6D8ULL, 0xD2C1A84740B436BEULL, 
            0xD9069CEB76D49EB6ULL, 0x48C6A6D67C269357ULL, 0x6971E7896EDFFA17ULL, 0x38059F4B547803C9ULL, 
            0xEAD7279F348BF4DCULL, 0xEB55747C81C1D082ULL, 0x96CA819B82BB553DULL, 0x755A949A3396E4FCULL, 
            0x591F7083D3CC8EF3ULL, 0xFA79B368C950E1D8ULL, 0x1DFEFC3504FBBB87ULL, 0xF5ED02995DBD52D0ULL, 
            0x07EB51DD2FF184DFULL, 0xB6F5B248C5CEF9E6ULL, 0x4574876AECFBC004ULL, 0x9355A4872F353BE2ULL, 
            0xDF05D32E5824624FULL, 0xB1211FC0674EC5EFULL, 0xADB53344A6D73BA0ULL, 0xEDBE406286B9D103ULL
        },
        {
            0x7DB5ADCE27A65C39ULL, 0x1953F945875B6CF5ULL, 0x968D0C1AC1B29AA5ULL, 0xEE1329249B561684ULL, 
            0x1DB93181BA28C65EULL, 0x7EC29F65617DA483ULL, 0x0CA7F2B54315875FULL, 0x3092B05C2E26C159ULL, 
            0x4CBA64E6ED684ED7ULL, 0xE73D5FB5E6CDD63AULL, 0x27AC53C273B924BBULL, 0x801BE074FC34FD88ULL, 
            0x112F7A4972F5634AULL, 0x1CCFE445F57D4155ULL, 0xD194D25BDC8A86C6ULL, 0xEA82B2AD0A3508D4ULL, 
            0xE94436BF975A375FULL, 0xD25259A2D0B486ADULL, 0x00335309EAD26C62ULL, 0x85F663163CB152EAULL, 
            0x4EA9596E25975B43ULL, 0x2AF2564AEF20207CULL, 0x465DF57A6A4C233BULL, 0x0AF2B700117158BFULL, 
            0x884B7B9B99AFB3CCULL, 0x74E9B704257C494CULL, 0x8E87AAAD2F1D3519ULL, 0x6FBE515941403E7EULL, 
            0xEC451866B985CB48ULL, 0xD7D07CD9166230D9ULL, 0x8E6737B0ECA6182EULL, 0xB6FAAFFB6A093D08ULL
        },
        {
            0x2A12B033D9406E69ULL, 0x74191059E5846B48ULL, 0xB1ABD2943910C760ULL, 0xC3A9AB0CCDA3A096ULL, 
            0xD33FBA5F8343CEFEULL, 0xC9040679048E2EECULL, 0x0C7CF3EC76104759ULL, 0xEA0FC32B5FA7F40FULL, 
            0x62E023AD03300286ULL, 0xAEC1FF8A2B16EC91ULL, 0x443693D6216F1CF6ULL, 0xE75AECDC4F5C0192ULL, 
            0x38E3B8FD628CDD86ULL, 0x951DB0F1F8F3DE0DULL, 0x5794E637A7061C33ULL, 0x09AFAEFF662248B8ULL, 
            0xCC1385C332D3BA18ULL, 0xC959EFD87EFB31F5ULL, 0x7648D0CAFD092693ULL, 0x6F2D2B5D70F18538ULL, 
            0x5698654B9A6EC408ULL, 0xC1C4E57321059028ULL, 0x62C8A7E984BABBEEULL, 0xC89AC4D996FC180DULL, 
            0xF2FB65314D8190F0ULL, 0xD8311C526A595AB3ULL, 0x5911D62DE0178F52ULL, 0x7B35093B1FC37DD9ULL, 
            0x9E980DFB1BED88D4ULL, 0xAC629001C68404ABULL, 0x6D3F45B6EA69830EULL, 0x5D78034F35ED363BULL
        },
        {
            0xA599FAFD76B8F655ULL, 0xEACD5858BB931AC1ULL, 0xD016A2869711218BULL, 0xCD3D08A15C3E3F93ULL, 
            0x3D5B2B6AA092895CULL, 0xD36E7AD821716225ULL, 0x6DA8BA9A01D5A202ULL, 0x5C0E3B8A8A1C68DDULL, 
            0xFFC07C5E6D3DE687ULL, 0x790F7F5AFF65634DULL, 0x6EB770A61047CB88ULL, 0xC0927B6A9D549380ULL, 
            0xF3D9D66CA5E6A954ULL, 0xBA28EB09D2A44D82ULL, 0x2067CC37916E6645ULL, 0x6D9CF6E19392DB8EULL, 
            0x1D159BDD411B0C5BULL, 0x81FF37B6F75F88F2ULL, 0x169FD849F55995FEULL, 0xEC5C89BD70D5A5D1ULL, 
            0x82B0291451428813ULL, 0x84E64FA68486F0B0ULL, 0x26F3EC12580D1EC1ULL, 0xA3607E502108BCB9ULL, 
            0x7DC191F47E862E34ULL, 0x988944D8BCFA6BCCULL, 0x001C7E1B663E6490ULL, 0xF52AB5FE1FC62F49ULL, 
            0x28C678C2EE4D809BULL, 0x55D3783033E9DC70ULL, 0x68E279FACC0E5080ULL, 0x41058F20479A27F1ULL
        }
    },
    {
        {
            0x6A705243FECCD27AULL, 0x21F0A073652A55CAULL, 0xA74063B6ACE6C2C0ULL, 0x85067745EA5DE4F0ULL, 
            0x77E56ACE692C65DAULL, 0x7BE9F27BBFA38A8DULL, 0x8E36CA468FC40651ULL, 0x2529E2668EC7F1A7ULL, 
            0xC01C2164F33EEE0BULL, 0x0A16B0FA72C65C98ULL, 0xA2FCC268EDD40EEDULL, 0x6041AF138097AFFAULL, 
            0x28F05D686F8D914DULL, 0x168068C76B946134ULL, 0x3485ECD946922855ULL, 0xF5BB0100129B296EULL, 
            0x6093BF18B585C10BULL, 0x556D11608EB6FDB3ULL, 0x8A1C1A49CCFDA13EULL, 0xCC1C88879B2F2920ULL, 
            0xEC76214265F0BDC0ULL, 0x5A670E98DA93FAC1ULL, 0x1EF3DB0661263BB1ULL, 0xBCD9DA7913E0B219ULL, 
            0x082A3B4D0E2D6548ULL, 0x2B0361986D1215ADULL, 0x9D943DC8BF1F5BEFULL, 0x536D94565EFF6F61ULL, 
            0x3FA7127AFDF4F5BEULL, 0x10E71B8DE5E5A078ULL, 0xC6BDB636A5FB3392ULL, 0xA844554641BC199CULL
        },
        {
            0x655624BE553BAA0AULL, 0x5A409C9F65FCAA6BULL, 0x5E028F52EE2F4818ULL, 0x2305A0EC59F60065ULL, 
            0x34CFF6FD5CCBD4A8ULL, 0xC575689B33CC2F37ULL, 0xCB9E1AAD18404658ULL, 0x62728D32979A2CC4ULL, 
            0xF76466D1E0D5CD65ULL, 0x51B11E157800B577ULL, 0xCC3FED8D1B72E1E7ULL, 0x5C4684C2D56B2005ULL, 
            0xEADCD04374AE1A30ULL, 0xE28BB7421CBB73A8ULL, 0x189468790F184CE4ULL, 0x416A8BAB25AF08D7ULL, 
            0xD03D62B2A3A3C125ULL, 0x5826BC2FB2B889B8ULL, 0x7990677F301AC335ULL, 0x58D3B9EDAD822143ULL, 
            0x0D3E20CE30FFDAF1ULL, 0x10555FC4D56AAAAEULL, 0x7E56B916CF3E8B27ULL, 0xC698A6AFF673B8A1ULL, 
            0x22BDC2FE62245206ULL, 0x92B607C259C091AFULL, 0x226FB654931B0441ULL, 0x53ABC95F94ED6BCEULL, 
            0x98D9D0DC7C6BB4BCULL, 0x4E73AEBFAD3A8A0BULL, 0x90474391464F13D4ULL, 0x931F4955BBFD649BULL
        },
        {
            0x105ACD076CABFED8ULL, 0x56223589089F7855ULL, 0x2F822A99EC331D12ULL, 0x16BA18FCABA36685ULL, 
            0x278951333C004E52ULL, 0x9446D0E58F81818FULL, 0x935B2294F476C697ULL, 0x194E3FFC8C06044CULL, 
            0x3549A166C0DDD13EULL, 0x2CA4B0C56229DD63ULL, 0x964B1B271A709E32ULL, 0xD5551BA4C3EF8600ULL, 
            0xD15762A5ED694425ULL, 0x7E02708857C6F071ULL, 0x8721CC21D960B81FULL, 0xF00DECB9716AB533ULL, 
            0x3A9C912459A7F24BULL, 0x3D6F806AF3750656ULL, 0xD23028AEC7700AD9ULL, 0xD84E466A2BFD34DAULL, 
            0x7BDC74AA2BBA12DCULL, 0x699C49F06A19B017ULL, 0xE1B1CF863AF2181EULL, 0xE9DD7AEFCEED848CULL, 
            0x1DA199A33FB1EE38ULL, 0xEAD609EE445AC435ULL, 0x898EDFC1B7206463ULL, 0x933DA0B08B5EE737ULL, 
            0xFAEBD107E2FD6F6FULL, 0xDBEFF63EB28B7E81ULL, 0x9035CE5295AECDE5ULL, 0x51CCF3F316FD6F77ULL
        },
        {
            0x367B03F9D0129DFEULL, 0x43F221922F9FE290ULL, 0x25697F6FCEE9605BULL, 0xBF2560FF12170D7EULL, 
            0x94B7CB7371E4D0E1ULL, 0x26727807041C3CD2ULL, 0x1893A0218D359EDEULL, 0x301100A4D591559DULL, 
            0x1ACA3931818EA639ULL, 0x4B6A191CD26FCDF2ULL, 0x829FC4D2B8D61C31ULL, 0x24D45674210A418BULL, 
            0xAB386280C52B9C4CULL, 0xB5623DCEDB956342ULL, 0x2B22E7DB5E559C97ULL, 0xFC0B1D934F5782ABULL, 
            0x1D33DDEC2C9DCF22ULL, 0xB78DEFC6299F9674ULL, 0xAAF7413865C550C2ULL, 0x98BFDE428EA7D5E9ULL, 
            0x4F56ABDF9DED77D3ULL, 0x17760B3F9BC3957FULL, 0x1410AC45DBBEF054ULL, 0x99796D96948BE0E5ULL, 
            0x34965DFD63703122ULL, 0xB57FB0AA5CF706E8ULL, 0x1AB3A8432FB459E0ULL, 0x15FC4EECD3B8A300ULL, 
            0x9C85B029120DC91CULL, 0xD6D2FCD015AF13E9ULL, 0x63D28EE0AA505920ULL, 0x1B3092798257A294ULL
        },
        {
            0xD07B70E5E32DE18BULL, 0x3D1F3D8248579C01ULL, 0x9CD83B7C0C2DBC30ULL, 0xAB27601E2803512AULL, 
            0x5C9BAC12AEE2148CULL, 0xECAD839EEF53BED1ULL, 0xF334467B032A6D0AULL, 0x23F6BC5964038E4BULL, 
            0x426E0205BFBBA9A4ULL, 0x76BBD4A523800CDAULL, 0xACF2FD17EB9C6FEFULL, 0xBD93E6E0D20DB0D9ULL, 
            0xEBE1C425B95DE09EULL, 0x2962F81883D2F173ULL, 0xCBBEEDB3D77A5597ULL, 0xC18792759ED79EBEULL, 
            0xD85F99940FD9CD30ULL, 0xA7DF290D82318D26ULL, 0xC12F66CD40C65A85ULL, 0x30E25B14D0DD8C4AULL, 
            0x705FD0A1A28F79E1ULL, 0x214D7B1DF80169AFULL, 0xB88A743FA9C5B5A7ULL, 0x79C342350335CEA2ULL, 
            0xAA039B42A814E61BULL, 0x7941F6D0804B21BFULL, 0x2FA690345E4739F1ULL, 0x19793AE7FBCC9A17ULL, 
            0x8AA347DC83F8DEA1ULL, 0x439B031AA173AC80ULL, 0xA271CA978D50FE34ULL, 0x364E94F96795526BULL
        },
        {
            0x7736CCE85681B80AULL, 0xF56E74094380D517ULL, 0xB995DE0054696324ULL, 0x1B9F64B946BB8241ULL, 
            0x446895C9D3F1C395ULL, 0x20129F2CA44FD11AULL, 0x19C5897EBFF7948DULL, 0x76955C703C164571ULL, 
            0x5220B6CD77BA98A1ULL, 0xFBD8A6FAC8461752ULL, 0x97C824B75830CF33ULL, 0x604C9DD89EAB5443ULL, 
            0x01B6FFA7A07C9D37ULL, 0xC18B2DB4AFAF263EULL, 0x50B10884EEBC9DA0ULL, 0x78E11EA337F3B746ULL, 
            0x26855D4D1B190668ULL, 0xB62208E2538C07F2ULL, 0xD4A63A85651D6197ULL, 0x52600414E7983E8FULL, 
            0x2E9D39823AB89E4DULL, 0xFCDC509006AF651BULL, 0xE47A23CBB17AB5BEULL, 0xBDDDD8A409695A7FULL, 
            0x4F12A001FAF2619CULL, 0x9A99BB648DD5C8A2ULL, 0xA726ED92D816421DULL, 0x3D56C19BCA62120BULL, 
            0xC62B636FC83DEE0FULL, 0xC4AD2EF64257BD52ULL, 0x313DDA6F419968D3ULL, 0xFA37FB184675F22EULL
        }
    },
    {
        {
            0x0AE41943524C64ADULL, 0x77FA548F1A10AE91ULL, 0xDCD44854DC3869D8ULL, 0x0F3D8D199271BEC8ULL, 
            0xCDB2CF7CFE434C89ULL, 0x89D9116AE0C78811ULL, 0xAE9435CDE330FE8FULL, 0xC9A8C5F1A3F565C0ULL, 
            0x8DBE65F6866E9025ULL, 0x0A73342512219498ULL, 0x4595E8350FB618D4ULL, 0xC19E0448DD5EDF8AULL, 
            0x3B12C691A41B1D50ULL, 0xA7769B6D54BAF2FDULL, 0x719E9C778139E432ULL, 0xDA96CCF6148BD55DULL, 
            0x90EDF220520A283CULL, 0xC4A93930D573338AULL, 0xBB705BFF1F926CC8ULL, 0xAA8AFD72BE022CC6ULL, 
            0xA65C7F555E15009FULL, 0xBD028FA94DD01EE8ULL, 0x67A21874D637A3E7ULL, 0x566BAE68AF03AFD5ULL, 
            0x7A7810C2D3A36F9FULL, 0xF1BEAAB0BF6B8A73ULL, 0x8C0D700DBEAFFF1FULL, 0x0F954120381BA6DAULL, 
            0x0673A758D3057116ULL, 0x8BB6008155B0397DULL, 0xD86643636ABD8504ULL, 0xBA24639E9A55E71FULL
        },
        {
            0xC9FC2D908609FC11ULL, 0xA203EED6CB335CC4ULL, 0x418C2E517AB83FE4ULL, 0x5C4F9C3E36B1BA78ULL, 
            0x043DD947156E9EC5ULL, 0x433457B5D37C05B9ULL, 0x345385D53A6CDF2FULL, 0xE5B6EC2A936A36A9ULL, 
            0x236ECAC258E64D5FULL, 0xD731BCAFE4A24EC1ULL, 0x36BE9AAD25486DFAULL, 0xCD66EBD827F35B58ULL, 
            0x88962D1A0F6DD637ULL, 0x3E118F987ABBCCE3ULL, 0x0F511F17A4DD78D2ULL, 0x9AB9F92491965A57ULL, 
            0xF74FD5F0916E3E84ULL, 0x99DFE6CDC1D50BC9ULL, 0xD18998075539AC47ULL, 0x0E1F78308AACE013ULL, 
            0x7EAEE3D8F3D7F594ULL, 0xC5E3D741C196C698ULL, 0x4DEC3665E2F71E32ULL, 0x3DCBCCDD867BF230ULL, 
            0xC7D7ECB5C591C9B4ULL, 0x3B0CAE3A57EAF300ULL, 0xDAD79FA79A2D35D2ULL, 0xDB21657A4968B5CEULL, 
            0x0CC60ADACFEC6EFFULL, 0x98A6FF0F031929D3ULL, 0x034B92CB16D675F2ULL, 0x3DF08197101C4DF0ULL
        },
        {
            0x80659794AC578367ULL, 0x5776E83003141E76ULL, 0x40E926A6885F9419ULL, 0xDF0EC01CB6409DDCULL, 
            0x0F35E964FC6BCB6AULL, 0x2C71CFAF08467FEAULL, 0x2BA551FF62F04A52ULL, 0x48C0B3E6719FFE1FULL, 
            0x8E2516E632D18B95ULL, 0x2F0E8988D7BC3469ULL, 0x839BD56A329C3D3BULL, 0xF28D24687C9C5EE7ULL, 
            0x670EEEFB57F657D0ULL, 0xA637F8875A6DCD46ULL, 0xC930D9A79DA89DF9ULL, 0x5FEBE855F2C25EDFULL, 
            0xA41706A03F9FC08BULL, 0x234C85980CE322E1ULL, 0x529F9DC4243140B2ULL, 0x7BFB3D374A1EDB38ULL, 
            0x1D75F5DA8DE691B3ULL, 0xD0F1103321AAAA6BULL, 0x4A2424F38058CB50ULL, 0xAA543A36DCC95D92ULL, 
            0x2AC5250C897C6D0EULL, 0x6C2635E207F67596ULL, 0xA2DB2E4ABE2A3814ULL, 0x525DB3C48E68405DULL, 
            0x5FD49F366BEABA11ULL, 0x6CB7DEF397424374ULL, 0x809D3AD9E80CE649ULL, 0x4AFCA1395DB50714ULL
        },
        {
            0xE5D36F73A3AB823CULL, 0x0A08D8B9BC9D54C2ULL, 0xF8FE736C1AAF1900ULL, 0xB0F51196F30EF773ULL, 
            0x8899A5B3D0B9200BULL, 0x5541626BB1B91E46ULL, 0xC0D4249D1EB351ECULL, 0xE64A84B668AAF676ULL, 
            0x613C5DA1A4201E83ULL, 0x1BC7CDD48E7B00BAULL, 0x17C85A6B8C6D4B71ULL, 0xC5CAB47D4EE9027FULL, 
            0x5E4CF210DE9ABC6DULL, 0x05E9627DF9AFA1C2ULL, 0x40D8CE60B7A5005CULL, 0x52A87EF142313988ULL, 
            0xB384F45E619025B4ULL, 0xF98D87C53D2A0FEEULL, 0xB1F486A0B10D4306ULL, 0xD8FD6BBC04EAE54AULL, 
            0xC1A959E7A6ECD90FULL, 0x1CBF29ADE4AE9816ULL, 0x0CE22EF628F9B2DEULL, 0x334FEAEB7D40A83AULL, 
            0x6C473D0E9F4E9667ULL, 0xD3DBF8B9E43BC599ULL, 0x8EBC06AB6C163EBDULL, 0x5F50CB51A021AC9FULL, 
            0x84340ED4678A47FCULL, 0xB0685EBC600A7826ULL, 0x7F9977F332FB7216ULL, 0xBE1BE408B8061E7CULL
        },
        {
            0x7174DDBD1E5E55D0ULL, 0xDCB6EDECA48E6A90ULL, 0x16AB2B93F5DB0C77ULL, 0x85A88E78A702B34EULL, 
            0x24ECEA52FAFE7AECULL, 0x68B319D79890E95EULL, 0x97E316999B16A922ULL, 0x523C07DB9F5AB373ULL, 
            0xACD65C510516D7CEULL, 0x5372754CA75BD0DAULL, 0x724AC80837886708ULL, 0x7F4F13EEBC08B053ULL, 
            0xCB51D481DE89C970ULL, 0x9348676951AF7736ULL, 0x1DEE159615360692ULL, 0x3E729F5164FD5FA1ULL, 
            0xDD1675BE09AEC997ULL, 0x266FB85CDDAC077AULL, 0x3FEEE11F156117E0ULL, 0x3887A4EFCD5DC7CDULL, 
            0x827009A01AF47322ULL, 0x5C7501B6373CAF99ULL, 0x19C35B807D130A61ULL, 0x9716F9D499F909AEULL, 
            0xD8DD0177CABA3A20ULL, 0xF2C61BB991D0F50FULL, 0x477491BD65222DBEULL, 0x3A77DD979D0BB8EEULL, 
            0xE0F958D37387D17AULL, 0xC741B5A8EFA1AA9DULL, 0xA34108CBDFD35B57ULL, 0x39DC24CA08FAFF36ULL
        },
        {
            0x507724B2EBBC2F0FULL, 0x681736AF0DC1A6B6ULL, 0xAFCD0FE25F1CFDB3ULL, 0x75955A5D9AF6C014ULL, 
            0xD9F9564D11DAF969ULL, 0xA37EEF8EBA6E0F76ULL, 0x404D7B08BC1F321EULL, 0x91E534CAFB2160D4ULL, 
            0x6C9C9ED758C5E711ULL, 0x3B90A650976828C5ULL, 0xDE2B625FF46D92CCULL, 0x00FA3159154B7A87ULL, 
            0xA024319823ECBE84ULL, 0x579E2665F3E85614ULL, 0x24E5C8667BD7675FULL, 0xD4C5A7B104570A44ULL, 
            0x22486BC9D9511E1CULL, 0x1B6BC7D42A44212CULL, 0xF81510814E16380AULL, 0x3A1AD6CF313C8CD2ULL, 
            0xE2824666C7F46808ULL, 0xA087397695BA633DULL, 0xE15A9AD04522DB7BULL, 0xD9F5D693E7DAC48BULL, 
            0xC0DDC3A750FDE2D7ULL, 0x168267D20159465BULL, 0x75646B0D237A09C8ULL, 0xB7139E98FF7700DEULL, 
            0x52592F0FBFE4E956ULL, 0x25192EDCB9FA6830ULL, 0x2F6D90627D9AED45ULL, 0x6B20D53ED957B390ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseBConstants = {
    0x9CF70750D49F70D9ULL,
    0x64481C689A27AF55ULL,
    0x05CCA6F18E3822AEULL,
    0x9CF70750D49F70D9ULL,
    0x64481C689A27AF55ULL,
    0x05CCA6F18E3822AEULL,
    0xDA020A3F5C347802ULL,
    0x23AE5C335248956DULL,
    0x1B,
    0x04,
    0xA4,
    0x1A,
    0x02,
    0x91,
    0xE2,
    0xC6
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseCSalts = {
    {
        {
            0x95B813059FEE335DULL, 0x68DBCB44F5441306ULL, 0x63558C263A5389F5ULL, 0x8A3E92BFC3720306ULL, 
            0x7D2EA0818331C77EULL, 0x9FD567C21BBA6D7CULL, 0xBCB5353983E54CB7ULL, 0x34EC08EB9E4E6D8CULL, 
            0x5296C91FDE1C847DULL, 0xAC280594F38558FDULL, 0x86745834013B72C4ULL, 0x395E5DAA676C1BDEULL, 
            0x8B6217AB7416E857ULL, 0x5AD667E99D3D094AULL, 0x4F8330888F66EDEFULL, 0x4AFEB34DF94E83B0ULL, 
            0x0715D0ED6C263833ULL, 0xF7362BA9AD40F3BBULL, 0xDACEE2D1E6E0FEDAULL, 0x990A75F7F3A5797FULL, 
            0x08AF725D41FC4329ULL, 0xC62FC4D89D7D5005ULL, 0xEC5152EC61FEDC29ULL, 0x460ED23BAE9D9A88ULL, 
            0xBE5270F89BB6342FULL, 0x01A560106FCD3455ULL, 0x1E023D10FE7A06FBULL, 0x1A8A94089DB09194ULL, 
            0xBAC756F284E71F99ULL, 0x422AF218E5C51BAFULL, 0xD659DC3BB9024BB5ULL, 0x0F824A8C9B7BFB53ULL
        },
        {
            0x684DA9F6402AB6B1ULL, 0x50A39081CC8BD1CDULL, 0x6BAD7AF4DB146C7CULL, 0x543CB74288638254ULL, 
            0xEB406DB020BADFD6ULL, 0xBDE192E5EF919173ULL, 0x130FF7295826D128ULL, 0xD420C9D760878FADULL, 
            0xC83959D22A6E7E6DULL, 0x71CD253D98373FD1ULL, 0x546C5DF7FA9AD860ULL, 0xCD04DE0EA7174406ULL, 
            0xED390A59EEDA7BD8ULL, 0x407078A9821D0A37ULL, 0x220E2E57294259B3ULL, 0xF0E776149013E117ULL, 
            0x93827FB63C896CB2ULL, 0x1BE643160CEDD918ULL, 0x5BC38D38DF7ABE6DULL, 0x8CABF2CFDEC96C0AULL, 
            0x97D804504C778A3BULL, 0xE25A5C22F7D0FB08ULL, 0x25AAECF411DB6932ULL, 0x98BAD990F47F9C40ULL, 
            0x909B84F787DBF206ULL, 0xE9C4B06C21D2C667ULL, 0x191CC114F22CC1DEULL, 0xC569D01D55D1F465ULL, 
            0x96E58D7D442CAD09ULL, 0xE18D56AA4D1921DEULL, 0xE964A1D2F23624A3ULL, 0xC6D3BC52B40C4E94ULL
        },
        {
            0x2A444DEADFBBCBD8ULL, 0xC5F0A6633EBA3469ULL, 0xAB131865E47D587EULL, 0x58EA9AD844B647C7ULL, 
            0x81CC1AA2E4982F63ULL, 0xD77DBE44543741B2ULL, 0x07FE438CF52CBD96ULL, 0x02E133A8D5B3A192ULL, 
            0x8DDEAAFEAEEE54E8ULL, 0xA68BF8F07F612D99ULL, 0xF7A2F475E6DF783BULL, 0x1D0582A3E2347611ULL, 
            0x5AEB88B175B688BFULL, 0xF6CF15B452FB1CD3ULL, 0xBE658138F0E39340ULL, 0xD1A5636B02A98A2CULL, 
            0xF28929D76138983DULL, 0xF383F7956F5A193DULL, 0x30464CEBEBD4FDC9ULL, 0x1D8B1A2DB7EFA2A0ULL, 
            0x3F7B08667F3043A5ULL, 0x8AC38B61296205A4ULL, 0xB3D0B55E3F83F8B2ULL, 0xE0C517C27DF37B07ULL, 
            0x670A242C553F1AC8ULL, 0xAC32633F25ABD8B6ULL, 0xDD91E3AB63AC012BULL, 0x3E87C63C674A9C4CULL, 
            0x1C34A1581EFDD2BCULL, 0x4A993D67F0CEA757ULL, 0x1FDF9A4B3F6637D7ULL, 0x27A4D9C74E2634ABULL
        },
        {
            0xD4C1EFB810A0701BULL, 0x994504CD0C145A7EULL, 0x8BB8661262D6E1C8ULL, 0xD5D96F65FBE34D3AULL, 
            0x39F02B690542F23CULL, 0x3747B485FEEC3BFDULL, 0x0537A17995C9A847ULL, 0x1441AC6368C59F69ULL, 
            0x9B2C15C4DB2E1140ULL, 0xB301AFF11324BAE0ULL, 0x8CA6D825DF108242ULL, 0x71383523C6698C4CULL, 
            0x7600A310541972E4ULL, 0x637FC7C7425C8358ULL, 0xA01DCAF36389BFA2ULL, 0xEC89896D91240079ULL, 
            0xD4E7981F5DBC289BULL, 0x09C362A47DBAE73FULL, 0x21BB5848329A0F88ULL, 0x2718190AD7DE23C5ULL, 
            0x00DB66E60AECE644ULL, 0x7DE671ED394FCFBBULL, 0xDF14F4D836E8BA6EULL, 0x1816BDF0705BC129ULL, 
            0x31FA9366B336711EULL, 0x6F15B801FDEA723DULL, 0xDCEE60B2476185BBULL, 0xC5D0BADFB795FE7BULL, 
            0x9D5597F6639143B2ULL, 0x5AE636CD02503C7FULL, 0xCB54A1DB207C59F7ULL, 0x68594C0AB74B75BFULL
        },
        {
            0x233D1A51F070C42AULL, 0xC201385C9C8D3D95ULL, 0xF9C1F8BEF97F4E8FULL, 0x57C64E40808B1367ULL, 
            0x055684E97CBCE893ULL, 0xE33C91B45B4A4BE0ULL, 0x91192C2695370DD5ULL, 0x2D357F4FEC2EF407ULL, 
            0x77C8756BA3A1C1DCULL, 0x5104F491DF3581DDULL, 0x48C8633C6AF24378ULL, 0xA0FD7BC2CA663648ULL, 
            0x576A18AED6B34FD1ULL, 0x8296212889C8E65CULL, 0x5724DF6290DDCA32ULL, 0x99F7F1F2D604692FULL, 
            0x400C0BD747A2B2D2ULL, 0x4D82810293508905ULL, 0x79A3C578B9DA4A48ULL, 0xC0398B05CCD7FCBEULL, 
            0x9F8EDBD4408DB3E5ULL, 0xACB64B267B22311DULL, 0xEB3D13F20EB8BE83ULL, 0xCB50E6F548CBF24BULL, 
            0x1951BDCCABEE6D35ULL, 0x26411C1BC2B6CB57ULL, 0x6D2833FBC54EBFBCULL, 0xB0428D48699D9A35ULL, 
            0x90B35AE051FED0CAULL, 0xECC483511A8A924CULL, 0x8BCBDD34EE371921ULL, 0x472374DB6AFD6E3CULL
        },
        {
            0x862C8F81DB41A3C3ULL, 0x4B1082AACB6A72F5ULL, 0xC2A4F3DADA699CD7ULL, 0xDB8996B6D33AE21EULL, 
            0x70BD362C220BAAD6ULL, 0x4B946C3FFCB6C6AEULL, 0x4A3EC1B8C986C7F4ULL, 0xB81F17DE7B40B52AULL, 
            0x277B61B2E192DF83ULL, 0xFDD59B137D13CBBCULL, 0xAC553989148BBFFDULL, 0x8E0E75DF8D3EF8C3ULL, 
            0x95F6BAD61CAC9D1BULL, 0xD9F7D9EBB7F1414CULL, 0xB302D7F7141FBD24ULL, 0x8235AB1A1B7EA36BULL, 
            0x6419446A43FDA040ULL, 0xF3129750FC5F6CEFULL, 0x16BB117E21468E47ULL, 0xEDA3D069DA8086A6ULL, 
            0xE1DD4ADF60FABBB1ULL, 0x9FD34C358D5B946EULL, 0xD1D1EA1CC0771EDBULL, 0xE36D96F4AAB774B7ULL, 
            0x5A49013C7AE7D423ULL, 0xB2516FF269CE3C53ULL, 0x3C27FA6FDE78B44DULL, 0xC98B3A62047FE27EULL, 
            0xD0EC93D3926435A3ULL, 0xD8B8F23F92AD0846ULL, 0xB7B89FD7ADAA8715ULL, 0x4A7FF2D2FDD68903ULL
        }
    },
    {
        {
            0x2B4F34CBD0ED2992ULL, 0x70CA081351AD2A41ULL, 0x955552BF7998AA48ULL, 0x2A5472B92217AF4FULL, 
            0x9D441A2A9C26EA15ULL, 0x7B30B06BB4ABB6EFULL, 0xD2305568C568DF04ULL, 0xDFD99D766524E5DDULL, 
            0x675083602F273801ULL, 0xFEA94C7CAAB71EB2ULL, 0xF7B6E3C2B5DEB141ULL, 0x199FA0DFC968585BULL, 
            0x3A9D8E2E699B95B6ULL, 0xC8C55D4E2C4736A0ULL, 0xA5E62CE920D83E9CULL, 0x279AEDC7404D1D09ULL, 
            0x9D9A9483D1CFB1CBULL, 0xE5703B46E857DA44ULL, 0x5DBC668399BDD8D1ULL, 0xD46FFCF8AA64CA50ULL, 
            0x3C850B840754C5D7ULL, 0x93381A96890FC423ULL, 0x58496C1A4FAFC669ULL, 0xD689F2948DEB86F8ULL, 
            0x5A99E561833C81C7ULL, 0xDF2F7327BE809648ULL, 0x2BD1F507BF672F06ULL, 0xEA79E5AF0FCA9E9EULL, 
            0x817FB841C3EDEFE2ULL, 0x2EC8F0A4AC2FAD02ULL, 0xDBDD782111E34287ULL, 0xC353C55FE65D1B68ULL
        },
        {
            0xA588DBD6BD662B03ULL, 0xCE5992E36DE6AC87ULL, 0x8F7E147F3A8E72F0ULL, 0xC8112B9F1CD03092ULL, 
            0x6F91082AE61FA86DULL, 0x31F3BA0B671F4AC3ULL, 0xE35295CB3F185B74ULL, 0x44F8DB3BD821E156ULL, 
            0x06DAB7D39BEEBC84ULL, 0x490CBEC125F846EAULL, 0x07A1CF72BFB13A10ULL, 0xABD8724FE0092C92ULL, 
            0xFC7FEE4E74C485C3ULL, 0x04595CAEE34E9C4DULL, 0x4B8ED4B0172FD2EEULL, 0xB5D01DF481384959ULL, 
            0x8BF2311906F0B056ULL, 0x2CE0B72FA8D42EE8ULL, 0x687776FFA617CD31ULL, 0x7B6285776E574537ULL, 
            0xFA22F55484803255ULL, 0xC0972D1912EABCE6ULL, 0x008DD59D447C7749ULL, 0xB7ADE02E5E28610BULL, 
            0xE6BA39B0C8C7EF56ULL, 0x2719475F88DD4079ULL, 0xE5485D704A09F30AULL, 0x100957175C9E90EDULL, 
            0x7D84ECC285C59069ULL, 0x6518F8C341E63189ULL, 0x2FF39E7467F9DE37ULL, 0x71DABB65F5344792ULL
        },
        {
            0xCCD1FE7C6A341A44ULL, 0x78F0F6FE5647BA86ULL, 0xE924831DFCDE4FB1ULL, 0x8ACAF7F191357805ULL, 
            0x7A5AB4B57D8116A3ULL, 0x71C3F3A7D081E56BULL, 0x431BFE4C2775408BULL, 0xF090B54A9288164DULL, 
            0x14FFEA7144BBF34AULL, 0xEF29233000B6ED41ULL, 0x2C596B2FC0E7205BULL, 0xA4B72B7D65B67E2EULL, 
            0xD2359A58140F6F2AULL, 0x4484BF0EEFA94C45ULL, 0x78A9CCF4810DA850ULL, 0x9259461442FC4F7AULL, 
            0x8DBA29738F8B0EF0ULL, 0x19A2FAD3B7F46344ULL, 0xC98087113F3561CAULL, 0x3CA71B18631FA9E6ULL, 
            0x90B58AA6EE171A08ULL, 0x8A84ACDD7A7FCA20ULL, 0x9CC1F35B3E96DBE1ULL, 0xD9B8ACBEA24E3A12ULL, 
            0xA9A78D9958C67489ULL, 0x46C2A309D70575D8ULL, 0x5A8D1D9A081D7B1BULL, 0x87E9D9E0D301F7D5ULL, 
            0x3FE3276E6C1EEB3BULL, 0x47935393647850DDULL, 0x40BDAC2A1B0499DDULL, 0x8B14D71E1B4C3479ULL
        },
        {
            0xAA48B9AC39884893ULL, 0xF4BAC5032E2B2870ULL, 0x7016CA8B529874DBULL, 0xC2480C5B1764787DULL, 
            0x70FC6E8EC535A011ULL, 0x052ACDD3578461FAULL, 0xCEC5C2C4BE5F4D83ULL, 0x0B2D667C9539A978ULL, 
            0xAC790711172708EBULL, 0xCE41B0114801D9CBULL, 0xC5B478B301D3F5B8ULL, 0x3CC3C6DB6CE8E6D2ULL, 
            0xA4789C3C6BBEB676ULL, 0xCD12504082C89FB3ULL, 0x39618A0798C98470ULL, 0xE27046F19D80E6A5ULL, 
            0x871751716BF0771FULL, 0x9010B08821338F72ULL, 0x6EA640CCC59EE24DULL, 0x051CC0228AAA651DULL, 
            0xD9325D4A5363F21BULL, 0xA79BC69F31F28F7CULL, 0x68CE02F391AC077FULL, 0x1A07A2CF41BBFB43ULL, 
            0xB9BD650F70187266ULL, 0x0596DB62F689190FULL, 0x45388E0A50508DDFULL, 0x8C5047478094C6D9ULL, 
            0x52E80A0A9D0F27ACULL, 0xBE0D432F50AF53E0ULL, 0x9C20E49D9CF3FB53ULL, 0x82CFC14718AE2111ULL
        },
        {
            0x4AC35E5463E09C7FULL, 0x20D1BFB122EF50CBULL, 0xC6EB0BFB060EC9FFULL, 0x6370351F4E012ADFULL, 
            0x24CFD6F37F737F76ULL, 0x6114730AC7600E73ULL, 0x7B6A60FC14D1552EULL, 0x7BA67C1E066932A6ULL, 
            0x2EC4D1785BD87E71ULL, 0x30912AAC2AD6B4BAULL, 0xFACBBA52D93537B2ULL, 0x8149398142D1C699ULL, 
            0x65FAF533815B81B9ULL, 0x93573E90FAA0EC0AULL, 0xC6AE6D5CD8B4197EULL, 0x62ADA78CB5ED96E7ULL, 
            0x458C260F5E0142C6ULL, 0x6B700E2940CBF249ULL, 0x66127ECC1815E500ULL, 0x4E23398280816314ULL, 
            0x38C5AEC34C2165C0ULL, 0x8AC487F2D913DBD7ULL, 0x87FEE173E1C1C9E9ULL, 0x3C4537AF3B9B0CCEULL, 
            0xC1F6CFC4B11C7620ULL, 0xC204AE0F1A2E7029ULL, 0x30DCCCF729873DAEULL, 0x329300D6F4FBB73FULL, 
            0x4E90E73D94196717ULL, 0x134833C2674D7EE8ULL, 0x73A1CD3D55DB5B43ULL, 0x390D55493543C756ULL
        },
        {
            0x88D13C0DB9DD285DULL, 0xB95F9299F514BDE6ULL, 0x10C33E35298CB303ULL, 0xBCB950CAEB72B832ULL, 
            0xC37E269F4F79556FULL, 0xF8304E7C42BF0E6FULL, 0x89E9BDF1A22BB74BULL, 0x0D7A2477177E8864ULL, 
            0x6884C266288FE1E0ULL, 0xFDA1A327B1A236A4ULL, 0x5FC84E247FED89C1ULL, 0xFA820A03A5D75CB0ULL, 
            0x593E9CE71A387EB4ULL, 0x0D6B0B213C1B22E2ULL, 0xF850CECD7738AD5EULL, 0xE606361B3CAB9BC8ULL, 
            0x5B7061D4D5B926C4ULL, 0x7F42A0AD4E53E970ULL, 0x6241A9897E58EB99ULL, 0x41316172B11D782AULL, 
            0x68F493227BDA45B5ULL, 0xB181178E76ED76E2ULL, 0x820AFCA102A60994ULL, 0x5A4E3465046DEFFEULL, 
            0x68E9C888FE3D491BULL, 0xE08B852AAE64E197ULL, 0xB8F79C6F4014B3A9ULL, 0x60D7E8571CAE13CEULL, 
            0xFFA330D42F54BB99ULL, 0x281BDF5B4454DCA4ULL, 0xDB320A260CD84F0CULL, 0xD0D8C8D886A96CBAULL
        }
    },
    {
        {
            0x1E78AD28480DAAC4ULL, 0x29DF333A5EFF53FDULL, 0x2088485AC0F81CBCULL, 0x363D87A146E5BE81ULL, 
            0xA3DAC6E2D6603658ULL, 0xC5AFEBEBA772AACDULL, 0x1157C1671C2FC414ULL, 0x04120ED00AB45005ULL, 
            0xE9030EA0626826F7ULL, 0x92464170EECD08DCULL, 0x0EDD9BE013A88A7CULL, 0x88319924F1E87BF1ULL, 
            0x9D350CDD3527A1F7ULL, 0x0E55A3444FA3833FULL, 0x084BA7AB1DDA7AAAULL, 0xE008F4701EEF6A35ULL, 
            0x1AEED2B94E84563AULL, 0x40278D41C3F2DDA1ULL, 0xFFFFF347CFDA9D16ULL, 0x9A8E65CE80B2E176ULL, 
            0xBA1B09AB502C3B00ULL, 0x23B7C59D28CDC524ULL, 0x6F57828635759431ULL, 0x954F7E50A3A60378ULL, 
            0xE4991D6B62C5E728ULL, 0x7EF79C6F966BA822ULL, 0xDB1B9F7347F6F987ULL, 0x984DCF141043F9C9ULL, 
            0x58E09E9DA8C7F1A7ULL, 0x3AC931A5A99168EAULL, 0x80E132812BC70AA4ULL, 0x87C0392F9F2BEA3FULL
        },
        {
            0xC590B42FE72C0E7EULL, 0xE4109D7B44E2E3C2ULL, 0x842ED1E914DE30E0ULL, 0xF060E72918B69BA7ULL, 
            0x5F3900CA7BC126D5ULL, 0x40F7776D9E71F291ULL, 0x232BA162BD7476B1ULL, 0xD3B12DC7CBE4922CULL, 
            0xC131CCA0DC6E65FCULL, 0xDB56694B1D7FC76EULL, 0xA681843D05476046ULL, 0x4B3E465C37D21BC6ULL, 
            0x15502FCF849CDDFDULL, 0xC5ECD038B879F8D9ULL, 0x97DA242E22303DFFULL, 0x5A23DFF61BA498DCULL, 
            0x374431B8D6AAE0E0ULL, 0xC88D82FF3AD417BBULL, 0x43668E2322EE24E6ULL, 0x4B2A8A16E8213BD8ULL, 
            0xE1E740347B14266CULL, 0xD36A8BFAC00D2413ULL, 0x6A007C7536C99AF6ULL, 0xB385D8489BCE6A4FULL, 
            0xCF8DCBC6F9EC54E0ULL, 0x4A9D3AB95548A1EFULL, 0x41BE0B65E53FDAA6ULL, 0xCFEEAECEEC6EEEBCULL, 
            0xCC46E238BF966C54ULL, 0x75B7A76396E66388ULL, 0x2149CC9C874EE808ULL, 0xC7FBDEC08F0F787EULL
        },
        {
            0x42997F93F1CEFEFFULL, 0x815174EB1A00455EULL, 0xD94636B95ABFA095ULL, 0x0F015339CC0B6F8EULL, 
            0x6B0EF85D44BCCD14ULL, 0x8C26F0D5B3AF0163ULL, 0xD59EACED91072F66ULL, 0x5EB5F4CC16B2D1F0ULL, 
            0xBA3E9C7E1E3714CEULL, 0x3A4E57FA568D346AULL, 0xD11B8CD6D1643AEDULL, 0xF5A8D78F2EC6C268ULL, 
            0xB7E6661EE4B738A0ULL, 0xB72604B198E618C1ULL, 0xAB2382806031CC6EULL, 0x7B73488525B1F607ULL, 
            0x39E58B27C41C07A7ULL, 0xC5E36BF6F15A5B76ULL, 0xE7B951099B2511CDULL, 0x2BA39A8C00F3F63EULL, 
            0xFF51C91F47321691ULL, 0xBEF9A587A5A5C914ULL, 0x9C6D696B30527C35ULL, 0xA65193FC40C9B0A7ULL, 
            0xE777B4E90E265B92ULL, 0xFFF17EB2F3E4501FULL, 0xCB2A3A37C63BBFC3ULL, 0x114CFFCF6EEBF053ULL, 
            0x4257A2BBF8CC0F23ULL, 0xBF1D50F2C53B9AB9ULL, 0xA33665C0FB767C05ULL, 0x8845305E26D75D84ULL
        },
        {
            0x41DDE4E2EF86A665ULL, 0xD88BABC0D140B523ULL, 0xED18A52AB389CDA7ULL, 0x59A01C07EF9DBBE7ULL, 
            0xE51423057A839128ULL, 0x79DB42AD31977ED9ULL, 0x114C4C2BFE2DF510ULL, 0xEC168239244B224AULL, 
            0xC07F3D4993404D46ULL, 0xA49E4411267AE6A9ULL, 0x113C4F8F7BE4B86FULL, 0xA0F17E99BE75CDBBULL, 
            0xFE0CB5066430C853ULL, 0xE2338CB4BDE58766ULL, 0x3EBFD6001BBFA46FULL, 0xE3BA26EC46AB4D88ULL, 
            0x838E115BB6AEDA23ULL, 0x30B5722A89BCC700ULL, 0x36622B7FA8579A14ULL, 0x8C34B73611FF2A76ULL, 
            0xA8EE08B105E952D0ULL, 0x73BCD33A6E334D58ULL, 0xE0DC78CF638CBCD2ULL, 0x8EA013F92B4EE9CCULL, 
            0xB88ADE1883622968ULL, 0xD00DA73279EC86DAULL, 0xF3FF6BF7B5B19FF6ULL, 0x63D6BF124CB44C5DULL, 
            0x43FBEC0FA36EE4AEULL, 0x82931DCC827581F5ULL, 0xB04C98D5D8C5010DULL, 0x813A6F20410BB0F7ULL
        },
        {
            0x6640D6618D52B202ULL, 0x8FAABB6128214938ULL, 0x61596A4571A96AEFULL, 0x10E2FD84F7FE92A4ULL, 
            0xE24ADDB447950A74ULL, 0xDF7A7C0F396F388BULL, 0xB4DC3A88A7241321ULL, 0xE30E25B853C45419ULL, 
            0x79A17FDF396322B9ULL, 0x27F4193D405FE7D8ULL, 0x918E37F412F78B2BULL, 0xBFC937C26D589159ULL, 
            0xDD1B1970EDC76C72ULL, 0x9F6CB1118D010E89ULL, 0x7B40F943F1EF1E08ULL, 0x6118D1D4AFDA3578ULL, 
            0xED6F613667497D57ULL, 0x53ACA23A5F01C1C2ULL, 0x34A3EF5FF866FA80ULL, 0x260D0F169FA85747ULL, 
            0x437913F94E22D411ULL, 0xECEA0F9EA0A462ADULL, 0x6175A7213D24195BULL, 0xCE75EF691DA3BF35ULL, 
            0x7410C49673D23578ULL, 0x116E8DB5297DFAECULL, 0xB6A439BDDE965F16ULL, 0x9E61E13040847D85ULL, 
            0x8E92452BD01120ACULL, 0x37AD0A2D329D6FA5ULL, 0x9DE2C5B9613181E5ULL, 0x7128BC8012A1129BULL
        },
        {
            0x2A3C71DE94F1CF20ULL, 0xE5A4049F1EB74580ULL, 0x37D8C2E96A68FACFULL, 0x1884E96AEF8542B5ULL, 
            0xEBAB1F8FFD57C6CCULL, 0x3ACE944A881345B5ULL, 0xB77CAEA93D4EC679ULL, 0x2DBF836BD79A5693ULL, 
            0xD592269C52B6C414ULL, 0x2A23831F6621FA23ULL, 0x254D168E0C8C145FULL, 0x546C399F0E4F91D0ULL, 
            0xCDAA5E8CFFAE811FULL, 0xDC5885D08DA2F246ULL, 0x14BF3384A20DB3ACULL, 0xC47CAABB5824F21DULL, 
            0xAE69B8D0E347EA4BULL, 0xE60C0CE9224DDC01ULL, 0x68168458DB57AAF7ULL, 0x19D5B9D2D5EFB36EULL, 
            0x39EEBA264BBFCDEDULL, 0xB74919F0F18425B5ULL, 0x3B5F7A02D0D6B3EBULL, 0x520C890275E82FE2ULL, 
            0x092D9DC2F5B8E2BBULL, 0x655BF1A59C530029ULL, 0x699F739508C9217FULL, 0x9402C9D5DAF4589FULL, 
            0x51185BCE8BFD0E1BULL, 0x49DF009E123C11F8ULL, 0x5069B7A70B5C8577ULL, 0x04AEEB57BEAEECF3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseCConstants = {
    0x0A2D74CFA1B14005ULL,
    0x6938659F74A42CE2ULL,
    0x1B6CC16B15D529F1ULL,
    0x0A2D74CFA1B14005ULL,
    0x6938659F74A42CE2ULL,
    0x1B6CC16B15D529F1ULL,
    0x000061F347A89D68ULL,
    0xB2D0AB2900D84241ULL,
    0x1A,
    0x52,
    0x60,
    0xFC,
    0x67,
    0x54,
    0x47,
    0xAA
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseDSalts = {
    {
        {
            0x19D849B8295E6B33ULL, 0x77E5FA45D5660546ULL, 0xC7DB0052C75315F4ULL, 0x1B9E6BE34CD2F7EEULL, 
            0xD6A93A898FCA26E4ULL, 0x2761C324FEC594B1ULL, 0x1706FE376408DCBFULL, 0xE8744227D6B5BCA2ULL, 
            0x3BC22DA83519307CULL, 0xEBA7AB3B06913B91ULL, 0xD87CE99B47916A6BULL, 0xBF580605E178AE74ULL, 
            0x7475D6887363C1AEULL, 0x79FF070C6E84F932ULL, 0x042F633197F80FC1ULL, 0xA7BC4B12C53BAA20ULL, 
            0xD16BD36019DE7A6CULL, 0x94CA19461E6AE61BULL, 0x9C499460EAB443AFULL, 0xBBF14E01A5E8D16FULL, 
            0xEC2E11C729E273E4ULL, 0x92D261EBF4B2E032ULL, 0x9D56216D180986B9ULL, 0x454D5213CA7B6FC7ULL, 
            0x6B21118568F07D12ULL, 0x4D75705175CB3F72ULL, 0x9CB382B5E5F268E6ULL, 0xFF8311AEF8097CD3ULL, 
            0x74B45F5DBB1E4765ULL, 0xEE91A3B74311A7D5ULL, 0xF1A137D967B67CEBULL, 0x2BD126260FDEEDF8ULL
        },
        {
            0x8C61CFC8C6ADA1D9ULL, 0xAA538EF7F0DD1296ULL, 0x3FCF4CB2DD785A7BULL, 0x37422962F7807E7BULL, 
            0x16BDEDDAD5C8756EULL, 0xA92C341FF99AB5ADULL, 0xCB031E5938E0EEAFULL, 0x1E676D54E1902B16ULL, 
            0x38B0279C44770BC1ULL, 0xA124D23EF39F8841ULL, 0xF680B953CBCE2FD3ULL, 0xE7614092F68E213CULL, 
            0x09ACF54BF11BF953ULL, 0x901EB9631BDCE65DULL, 0x6BA733C332B70E42ULL, 0xF37D412C9213919FULL, 
            0xC671D0F6B20BB089ULL, 0x0594D0B48A4AA0B9ULL, 0x6839A0D3532EF55FULL, 0x65713AFD2078DBCEULL, 
            0xCE46AB6C3B208212ULL, 0x7AB443CDB8A9DB57ULL, 0x4C4A7237CAA3D069ULL, 0x0B0F7219B510DD2FULL, 
            0x581EF8D16DE78EEDULL, 0x27173EB02340FAAAULL, 0x003815D7EFFC5350ULL, 0x899A47B0B2F1D979ULL, 
            0xC9478E0535EBB979ULL, 0x74D896A6AA9D7FBFULL, 0xE5851577038691C9ULL, 0xC98AD4CF1D2646CAULL
        },
        {
            0x8731947876890F96ULL, 0x00D660A0BAF4DF1FULL, 0xD0959CAB422025D8ULL, 0x0D94FFF103AFB1ECULL, 
            0x12DEEE118DC9D092ULL, 0x0DF28A6E8A269F09ULL, 0x8F8553DC82762F9CULL, 0x59F8C7D5E785757DULL, 
            0x1A0D7F72DAAF9EFAULL, 0x1B93147875CF8233ULL, 0x4EB7D91863BF43DBULL, 0x07217F922A190E90ULL, 
            0xB367DC2C3523A93CULL, 0x79BEF9873D0DE692ULL, 0xA680F1785A5396E6ULL, 0xCDB075869EF11677ULL, 
            0x04299D1D6DE1DCDEULL, 0x79A52DED93BE68FEULL, 0x053F05F1EEE05AB8ULL, 0xEF39FB9FA51CDAE3ULL, 
            0xE6E5C97706C6EFDEULL, 0x25C15D6A725938DEULL, 0x7513029237AE6FE0ULL, 0x837E7DD8169E0E08ULL, 
            0x6A85FDDCF02C16ABULL, 0x48A9F5709CA1B223ULL, 0xC3E9E9A49B0AE518ULL, 0x9F27A87C62BB97ACULL, 
            0x794CC4DF3887B415ULL, 0x44E5FC66B249455AULL, 0x4382C8E9C318EAADULL, 0xBF6AFC6EB05ED04EULL
        },
        {
            0x76C39AA6EF8EFE9BULL, 0xF3004090B5AE3336ULL, 0x9B4FD1DB8F713BABULL, 0x176E8F298B43E8F1ULL, 
            0x8C061781F7A80CCEULL, 0xE314B6A9D1C53AC3ULL, 0xD440C2FB604B0CE4ULL, 0xB8C8F03C36E9F818ULL, 
            0xC5834F0C233AAE7EULL, 0x937FFFDDCD6DAD5AULL, 0x8BEF4B92E5006489ULL, 0xA7ABF9093D6493E8ULL, 
            0x02D9F0D9568670BEULL, 0xF72C12C20AECF70AULL, 0x64AB2195374E68FFULL, 0x5425A444FBCC8A5EULL, 
            0xA750837796B79C41ULL, 0x54C0E18BA1782835ULL, 0xCBB4D8A1F5234D8CULL, 0xE68D52F16C26732AULL, 
            0x862A0ACB3AB1710CULL, 0x743691B2A2858BF2ULL, 0xAD441F03C3E3206EULL, 0x12C3D72E44E835E7ULL, 
            0x3B6C046E91B3CFC8ULL, 0x39AE29195AE71B07ULL, 0x21BE0633AC53C156ULL, 0xF3FFA9E9627C5199ULL, 
            0x4CD44A872B5DD2EFULL, 0x818F778DA9EF8E93ULL, 0xB2FE4E0D7877C57BULL, 0xDD2CBE657329C904ULL
        },
        {
            0xE2B6BBAE5F8E0CFDULL, 0xFB92A95C8DD08DBCULL, 0x04D794BC9A9F9FDFULL, 0x8F3A0BC3E5A8CBC0ULL, 
            0x2D69F48455D89331ULL, 0x0DD8AA0D0017642CULL, 0x9F2300691792D73FULL, 0x733B43148A3FDC56ULL, 
            0xF22EB9C7EF6A34D9ULL, 0xA5B8FAE4B344F683ULL, 0x187627BBBA6E54B7ULL, 0xAA1BBCE3B9603F63ULL, 
            0x5654BAF468828E61ULL, 0x706A395B689D043BULL, 0x8B4449A77F7DE212ULL, 0x10348E607E513449ULL, 
            0xF20B8E662BAEA96BULL, 0x54B3C7EF134F403EULL, 0x8F97D423CB412EE8ULL, 0x70B3EF041A74A594ULL, 
            0x8047BB79565F977CULL, 0xEDC47D5C5F9BD849ULL, 0xFD803AD6946921E3ULL, 0x2ADECBDD32853F33ULL, 
            0xE33D8C49ECBBFB9CULL, 0x5A78A1138B95E7ACULL, 0x12C92425042FC452ULL, 0xFF85A077C67E8153ULL, 
            0x12FB34A08CEC4943ULL, 0xC59705AC24B85B01ULL, 0x5DB80793CD8195E9ULL, 0xE25A73D786DEE896ULL
        },
        {
            0xBEEDE01D2903E789ULL, 0xC08D0092EA29F6E7ULL, 0xFDED07362F5B42D0ULL, 0x2703856948CCFDACULL, 
            0xF46023546AEAE3E7ULL, 0xD98C824CC94FB63CULL, 0x11C22B41E44E1969ULL, 0x280446E3D4DEE4F0ULL, 
            0xEE024BF1DDA44D18ULL, 0x57D419B67131394CULL, 0x7289F1509738D092ULL, 0x56791AD160C65AC0ULL, 
            0xC59B69FBA2CF6AEBULL, 0xBAD1F49A894AB27CULL, 0x49761B6A70ABEBFFULL, 0xEF665DF64DA51D56ULL, 
            0x869CF503BBA706FEULL, 0xBCA1092FA5FA2079ULL, 0x99E2ACAD4E922E8CULL, 0xD2A3D5767DD01DFDULL, 
            0x5A5A7BFD7617A703ULL, 0x9D5043A093F6E021ULL, 0xA9C87771BF343B13ULL, 0x1E0CEB45F5B9592BULL, 
            0xB8745AAD86F3356CULL, 0xDBA84C3E4CEB04F7ULL, 0x35AD59BB5FB5CD26ULL, 0x930FB73EA0BE48A8ULL, 
            0xECA637D1AD95E426ULL, 0xD79EE772F043B38EULL, 0xF754B7D9120E2430ULL, 0xA5A2AD8F0FA00A7CULL
        }
    },
    {
        {
            0xE634330337CF620EULL, 0xC41A40D2985E02ABULL, 0x92490FA513BE5FBDULL, 0x75DA254492E728FBULL, 
            0x9B553D2EBED3606BULL, 0x20CA0939620BDD34ULL, 0x3248BC4BED105028ULL, 0x7B475E4D92B01BF5ULL, 
            0x6C2D1A2301E61C95ULL, 0x8B1B2090A82FFB9EULL, 0x96316EC5476CEA63ULL, 0x94BE4266BAB53D97ULL, 
            0x01F1EEA843C93AFAULL, 0x0DD7DF0CF3BF7F7BULL, 0xFF854DA78FE7A963ULL, 0x388274C5FA3C2506ULL, 
            0x32EF12D3820B8AF3ULL, 0x0F22B1C3C358BE91ULL, 0x6FCB8234CEFB2048ULL, 0xBFA7DB7ECDE27EA6ULL, 
            0x9C09C88493314B40ULL, 0xB3781B2A28E240B9ULL, 0xD38AFE83A2C44C4FULL, 0x2B737E37CE893266ULL, 
            0xF5E31B2CD7A13A9DULL, 0x1571D17D06042F96ULL, 0x26CBB531EBF014E7ULL, 0xA090FDADBCFA20CDULL, 
            0x8303E35242B24DA1ULL, 0xD94C9647F2895BB5ULL, 0xAC614B1CFE4C8692ULL, 0x15CA27FA5D53A851ULL
        },
        {
            0x18E88EB7B8A2A5FEULL, 0x3CFDA13BBD5DE9C4ULL, 0x5AB3A00E0A06D6CEULL, 0x08D5EF385B163AE7ULL, 
            0x25A53D6C71F6309CULL, 0x22F9B502E73436EFULL, 0xD56BAD0FDF255078ULL, 0x4AE112FDF3AA4117ULL, 
            0x0633AA8F10B1B88AULL, 0xFB54CE965317924AULL, 0xCFBCFF49FC33CF41ULL, 0x94176D9B17AAE443ULL, 
            0x634257C0F2087F25ULL, 0xCBED7B0D0B3A943FULL, 0xDC46F6C571227B64ULL, 0xC50627B99DA26240ULL, 
            0x34F715886ADDC49FULL, 0x26A22E05CF206FC4ULL, 0xAE9C345CD5F7F859ULL, 0x72A3DA27FDCD3DA4ULL, 
            0x3101E26EB06153AAULL, 0x8990474CD2F7E2EBULL, 0xF6BF3A0BD3AFCC8CULL, 0x86C025190ABE4231ULL, 
            0xF4D17EDA50C21ACDULL, 0xBDA81F4108EA3356ULL, 0xB944C5D8477D4FB7ULL, 0x27AF1AA147B6387DULL, 
            0xEE9474A972DA2605ULL, 0xB4B7AFDE7A58615DULL, 0x48B916539DADB174ULL, 0x82EF56E2E03B0CD4ULL
        },
        {
            0xBA2C83FC2706BF91ULL, 0xDCB290E1062CACB4ULL, 0x8314B68C98AF8C61ULL, 0x8E44FB333D02614FULL, 
            0x7A140BA7368D4D2EULL, 0x7A292B21423E1BECULL, 0x7632B0BF11FBA9B8ULL, 0xC30C23CEABA1E651ULL, 
            0xF86C7F82DF814C73ULL, 0xE317E00C0D22247EULL, 0x2D4B5801352B4098ULL, 0x3192A82A47B282F2ULL, 
            0xA47D7CF73359672BULL, 0x53FB82E68C1290D6ULL, 0x98BEE93471455E75ULL, 0x805B15D5866FDE85ULL, 
            0x444F78A6A130B065ULL, 0x7993A3964E2EAFCEULL, 0x227864C5DFE0128FULL, 0x82D065D5CB0674A7ULL, 
            0x28624621BE0A13BBULL, 0xDC78CF05C6E21229ULL, 0xCBCFEEAC21D99C3EULL, 0x7063A12ED2BAD9F7ULL, 
            0x9F49750D9248C5E2ULL, 0x5C6ED0EFD5125E49ULL, 0x18EDACE3E1C60FAFULL, 0x6534DBF74DEB8615ULL, 
            0x0271DE8182C82AFBULL, 0x338F6C7A6F223392ULL, 0x5BD9E42D54826532ULL, 0x294AEA748553E680ULL
        },
        {
            0x86D9448FDFD503BBULL, 0x0AFAEC88117F74D8ULL, 0x5F26182B0F9BAD4AULL, 0x1F6A39DD515BDD3BULL, 
            0xFCAB53289074F05DULL, 0x84CE26BB87204DEAULL, 0x22DDAD2BE07B1BB5ULL, 0x17AA53B34B3073B4ULL, 
            0x698B2E372B30EBBAULL, 0xA425063986E6D26AULL, 0xDD11A3DE7E38359AULL, 0xB007B66F0B556BC8ULL, 
            0x7F8E3ACF57895E14ULL, 0xA98814A6A040BEC6ULL, 0x2FE1E7246188F30EULL, 0x09648E44FE7BACC7ULL, 
            0xB72213016D74559BULL, 0x082A5C4F4D81607FULL, 0x97F769368F3030EFULL, 0x1A19A548F51597C6ULL, 
            0xAB85C5FED7E1992AULL, 0x59583912972FFAE4ULL, 0xC147F74DF4BB633FULL, 0x114D06A87BF398AFULL, 
            0xFDF24710AE5EDD08ULL, 0xE1E15114503AF618ULL, 0xA33830D803F5FBA4ULL, 0xC8481C2C8D3A9489ULL, 
            0xBA43C1660022555DULL, 0x271333556252979CULL, 0x1B424787041D103DULL, 0x6118CB93EDF7732EULL
        },
        {
            0x1D994CA976303432ULL, 0x4634790EB83473CFULL, 0x7228AA03144AFC9BULL, 0x5C8F01B5837D717DULL, 
            0x40D60993CF9A711BULL, 0xA0A0121C2A0012CFULL, 0x60A2775C5FB5CE76ULL, 0x64B383476D392F3CULL, 
            0xFD3D6646D615BCDFULL, 0xA1BC36DE6F28E2E8ULL, 0x816B181305D5DD07ULL, 0xDAEFB0872F250B9AULL, 
            0x38CB9CFD4101FB9DULL, 0xDCC4624C3AF08B12ULL, 0x3E55578D49C6ADC5ULL, 0x0184BE20F29558C3ULL, 
            0x1C6AF3B127316060ULL, 0x8E8B76C870797749ULL, 0xBD684692653D028CULL, 0xBD8FE27C0BA3FA83ULL, 
            0x0F6E4950D95F80C1ULL, 0x273D5BA9721707DDULL, 0x2908324D44E1385CULL, 0x1335242CB0B79C68ULL, 
            0x3C2A199F6E012CA3ULL, 0xDB6408BAE394CFB0ULL, 0x14656C68BE02B7EAULL, 0x6E25B1F119EA2DC0ULL, 
            0x96C68706A83FCFC7ULL, 0x724DD4CBB09841C1ULL, 0x5B40365162117936ULL, 0xF8225F4C6A33ABCAULL
        },
        {
            0x383BFEC11DB0084EULL, 0x6194AB5AAD190522ULL, 0xFD7453D396174A84ULL, 0x811FBD1924120CAEULL, 
            0xA83A7D3BB4524D6AULL, 0xD9A4EBD6A43209F6ULL, 0x46B115304F9E1302ULL, 0xEC18553DA3FE0AD0ULL, 
            0x3C176880A2372259ULL, 0x75FCF20F0ADBA5CFULL, 0xA479E54A8EEC118BULL, 0x4A4ACA0541054F37ULL, 
            0x699914B57599470AULL, 0xB402F5BAE215EA37ULL, 0x201CEB34F6E31918ULL, 0x78DFFE65040CE888ULL, 
            0x0583888C84A0EBF7ULL, 0x41F0B15465FA4268ULL, 0xCF41A13695C076FEULL, 0xF11B5FFD81AED186ULL, 
            0x67724AAE33810D63ULL, 0x0FF5DB4CBAD5960BULL, 0xF76349ACA2775D41ULL, 0x1CFD571CCCA28EFBULL, 
            0xB0267B42F6CB7316ULL, 0xFD9F49422B97678CULL, 0xEEE8E43DF7CA3D38ULL, 0x2975634C710DF424ULL, 
            0x0FA19FA6B55DB578ULL, 0x8AC473433222F68EULL, 0x1CB5DB018B310262ULL, 0xE03D6C2344CDBDC4ULL
        }
    },
    {
        {
            0xFFA1A74937831924ULL, 0x378B19F4B59A986EULL, 0xF61D9391BDD7CE85ULL, 0xAA6FE795F87563DDULL, 
            0xD3A533AE06ADB5B9ULL, 0xD08DF5463458241FULL, 0xA82D9745BCE9C16DULL, 0x222476C2BEC3293CULL, 
            0xBCEC6225CC07D263ULL, 0x05D07C1FDC013DB0ULL, 0xBD8886001FEC7DA1ULL, 0x9438DF4EDE65C900ULL, 
            0xAD2735A9EEBEFBABULL, 0x0918630B3A9A1255ULL, 0x8F5D879E7EFF1304ULL, 0x087A92A25742F803ULL, 
            0xC22464779F74A54AULL, 0xE088AAFC5716C311ULL, 0x85E09284873AFD54ULL, 0x2AF86CD96B689D6DULL, 
            0x662C07A17A1FA0A9ULL, 0xC22B484E16B0179CULL, 0x34A50BCCE1B4F461ULL, 0x5EF2E887D908A317ULL, 
            0x8B7B75344EB66D08ULL, 0x85D5065C2627ECF5ULL, 0x4BEF58A2942D968CULL, 0x9DEF2327EC20F776ULL, 
            0xF008778DF728DDAFULL, 0xAA066D56006B8B13ULL, 0x4D12245229F9502DULL, 0x467C88960D317E01ULL
        },
        {
            0x05E9F21F48FD8FE4ULL, 0xB5F20ED80AED939CULL, 0xF3A9DE64B6CFB3A3ULL, 0xC54690571996C1BFULL, 
            0xC24FECEEC9CA85F6ULL, 0xFE85CD4FF03676D8ULL, 0x1F341A9D85DFFC84ULL, 0x3C2B7D16C1FBC602ULL, 
            0x822CB5F728662F91ULL, 0x4ED69B79C01E36CAULL, 0x2C57F37A617C7811ULL, 0x02EB3CEEFA66A8AEULL, 
            0x21E375FC07984FA0ULL, 0xE45F08DF9598AA64ULL, 0xD9D531FA70773F5BULL, 0xF2800BE53E5894D2ULL, 
            0x0D1B63D22A7C0BA0ULL, 0xB7B5F6393A33EC23ULL, 0x657A0668A0C66C79ULL, 0xE595CD6FCFCC12A4ULL, 
            0x958A687F1D1BF66FULL, 0x8D2C88D15A865818ULL, 0xE246F5AFD15DA762ULL, 0x9838B01A6BA45928ULL, 
            0x3D39C06FE571B106ULL, 0x33ED2CECED3D5E34ULL, 0x914502BBCFF75EA2ULL, 0x0ABAE44E0FFB9F08ULL, 
            0x8CA3BC024622BA1FULL, 0x1CF599094E4B4DEFULL, 0xA77178C2C9CBA277ULL, 0x147A8F9E6DCC25FCULL
        },
        {
            0x272F8D43AF3B8FD0ULL, 0xA3DDAC276D6713B3ULL, 0x4885328EA56F90DBULL, 0xD996F094DBC763FDULL, 
            0xDE41FA4DCC943464ULL, 0x8A78E60A3E023985ULL, 0xB10354705BFF6AF6ULL, 0x2DB6FE07365EADD7ULL, 
            0xB242441909F6CB9DULL, 0xA9CA043B023FB2F4ULL, 0x6EBCB55DF3CFBC62ULL, 0xA633E0976409143DULL, 
            0x77162E79DF1B7C57ULL, 0x634BEE4295EC0EA7ULL, 0x25B8CA2F03873512ULL, 0xC44E1756CFD4558CULL, 
            0x871BB3DFD46B11C6ULL, 0xD4D2FE450E65BD02ULL, 0x7112F53AC545550DULL, 0x8E3B3EB2E5B5A735ULL, 
            0x11498FC7AB5052D4ULL, 0x0822FEFAACE0C2B6ULL, 0x9D5F522D8FB9652FULL, 0x3C9AB374838C073DULL, 
            0x712801179454C404ULL, 0x68D8C2F8ED1083F4ULL, 0x0BB62BBB4AB70280ULL, 0x438132CA6082CC1AULL, 
            0x75D23D0671BC30BFULL, 0xBD57D863607D7C73ULL, 0x9A8C5E7E145F82C5ULL, 0xA1DA16D844B18E22ULL
        },
        {
            0xF676DCBF221749CAULL, 0xF006E43E2ADE20C7ULL, 0xD2D173D60BDD963EULL, 0xBAFE16DD3C551CF6ULL, 
            0x81A402ACC894B60FULL, 0x66D63A970D46F5D6ULL, 0xC28D3F36861A0905ULL, 0xBF7BF0ABA02B4078ULL, 
            0x10BAC66A3CA27366ULL, 0x42C6FA7F2BB66724ULL, 0x7DA358CFCED66312ULL, 0x6B3CEBA887B252C0ULL, 
            0x4C3D16E21461E641ULL, 0x10833EB786499AB5ULL, 0x96EBDC5FFDD433E9ULL, 0xDA83809C003E2AD7ULL, 
            0x660ACB6914DAF1C4ULL, 0x4988C14F4DEB70EBULL, 0x49F3C0A8FEEB2A45ULL, 0x9E2B2137565D2407ULL, 
            0x0C6A0D2FF4818F02ULL, 0xFF4037BF44036FCDULL, 0x85888D07A6428C6EULL, 0x7E8EA765324ADFABULL, 
            0x9D4CD1EF77D8706BULL, 0x471D20E5A28A024DULL, 0xC3CCA6BC35CB83DCULL, 0x11F637597B4845FCULL, 
            0x4108676AC36F4D80ULL, 0x28FCCE3AB09F59A2ULL, 0xDE7C90D8A0E6ACD5ULL, 0xFF2677AA58F0AF3CULL
        },
        {
            0xDC226750781AC1DDULL, 0x0CF01C07CCDFD649ULL, 0x1F4E18C6EE5234A4ULL, 0x061D971EF122CC7FULL, 
            0xA8959EF9CFD4839AULL, 0x79ADD2C1C70BE64EULL, 0xA70AA3C732D15AB3ULL, 0x81BFD9820574E1E4ULL, 
            0x3E1DB68804133A56ULL, 0xEDD3ED49DB82796BULL, 0xC86D01A68FC5AE12ULL, 0x7C9244B203DE6697ULL, 
            0xC1CFE169DE3D2475ULL, 0x5771C82AC415E726ULL, 0xC0CEFDCFA45ED7E2ULL, 0x13562285DB95ED9CULL, 
            0x342BE5E46C404EA4ULL, 0xB999E8F4023FAE29ULL, 0xF5B75BEF150ADB5FULL, 0xC132E5F904C78BC0ULL, 
            0x1C7AFC0820F9A5B7ULL, 0xD989A13D794303DAULL, 0x6242BCA483252BFDULL, 0xD223B335E24D4D99ULL, 
            0x1064D9C8A8B12D76ULL, 0xF4E26592FCC667E8ULL, 0xBC6CBF94DEBE9DC8ULL, 0xCF99BFF020F91B2FULL, 
            0x1A8FA53964F8D4F6ULL, 0x1E753B052A6925AFULL, 0xFBF4602FC897DB55ULL, 0xF6DC4DA268176107ULL
        },
        {
            0x1773B4303B722819ULL, 0x46C23E71258216B2ULL, 0x21D495868BBDB99DULL, 0xA6DD37547820DBE0ULL, 
            0xB4E4B7A3C9462E22ULL, 0x53F8A9DBE38CB89BULL, 0xC4E0CF01513B91C3ULL, 0x2494D9B5A56A63ABULL, 
            0x24887E9AE311E3B9ULL, 0x06A7E6E8B67569C1ULL, 0x1221C93EF5D6D323ULL, 0x308F3BE232CF1E44ULL, 
            0x7E5690B4D104C0ECULL, 0x577AFEA10F540A60ULL, 0x37E0801B49AB1C4EULL, 0xB08117E3575A4FF5ULL, 
            0x3733748D54A73321ULL, 0x729626512607F441ULL, 0xC4D2DBCB26BE8A83ULL, 0x026EDB416CDA173BULL, 
            0x36418130676F073DULL, 0x64C125B48B1CA8F6ULL, 0x6C113F23C7F96203ULL, 0x91AAC8D13DBFA472ULL, 
            0xAACA8FA2FB7BE994ULL, 0x92FCA55F579D6EB5ULL, 0x8F41378765DAD888ULL, 0x2AF6C524FD32ABBDULL, 
            0x8E38448EA8C55F7FULL, 0xDB817A4BF0AB6BBEULL, 0x5D247F201A0BA1B6ULL, 0x500FE1AB19149D32ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseDConstants = {
    0x23EDA1EF019A6564ULL,
    0xD714B5B10DF45813ULL,
    0xA84734F243E01F61ULL,
    0x23EDA1EF019A6564ULL,
    0xD714B5B10DF45813ULL,
    0xA84734F243E01F61ULL,
    0x5A0DA2942B2F8735ULL,
    0xD9D4559A625D6B13ULL,
    0x96,
    0x57,
    0xB1,
    0x01,
    0xEF,
    0xF6,
    0x93,
    0x98
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseESalts = {
    {
        {
            0xA989A01F87460C2DULL, 0x60963D594D2E264CULL, 0xCCC63B037C17A0F2ULL, 0x8B7921E44C572A3EULL, 
            0xA91E7D56C0EF9E3AULL, 0x557DCD719DE5CE03ULL, 0xD4A630779FB8DF13ULL, 0x9E3B5705FF5EC08EULL, 
            0x0C34C29FB564E469ULL, 0x91B22ABDF7FD0206ULL, 0xC946EFC4FB426AE1ULL, 0x7D365CFD71CB3E26ULL, 
            0xB718C745245541ECULL, 0x10282A53B53C2740ULL, 0x4952283A4EF04A54ULL, 0x12972DB4CD3FBF22ULL, 
            0x1ABAAF70BE3DA334ULL, 0x1DA8A2D189F5ED23ULL, 0x5CAEFB66868E6925ULL, 0x148487006EC51AB7ULL, 
            0xDB770D2508178A23ULL, 0xFAC29D90C89F770EULL, 0x9CB70ACA11105D7DULL, 0x70AC60482926CC4DULL, 
            0xB2DCD4CE5DE6DF56ULL, 0xED6060E8DBD5595BULL, 0xD14311E60ECBD831ULL, 0x4936C82C4A6CAD81ULL, 
            0x5EEA340DC46782B0ULL, 0xBC5DE99F361A776BULL, 0x207D9FE455A974F6ULL, 0x64E64DA272DFBAE5ULL
        },
        {
            0x2D044FC100297C19ULL, 0x2783492A3960F8A5ULL, 0xB0C56A7740D0FF71ULL, 0x39187AD1C68EF329ULL, 
            0xCAD98E0B7CC3872AULL, 0xA1AFF22297A2C7CBULL, 0x50F774B33094530EULL, 0xBCEC1651630789FCULL, 
            0xCBDDF1E7A45FBF86ULL, 0x336B17E3B8BF1C55ULL, 0x48E139BF32B0A0A9ULL, 0x3220521A9D9A0DD9ULL, 
            0xC9A64E2B2680058AULL, 0x9F3091234DF5345EULL, 0x999F218C922EB430ULL, 0x929EE57D41A07984ULL, 
            0x6365ADE9995C2000ULL, 0x116C95347EF0D1F2ULL, 0xB4F92AD5674831A2ULL, 0xD4CF11FC5EB68293ULL, 
            0x97D52831555761CEULL, 0x9C2AC434B894D1D8ULL, 0x69EDF8F4B627D2C0ULL, 0x6BDD3ABC892AF60CULL, 
            0x5BC92075B09C6D03ULL, 0x8A5C66EF1B99E8AAULL, 0xA45FA2583ADFEAA0ULL, 0x5A07F12B4BD90BE5ULL, 
            0x294E27D199568C7FULL, 0xFCAE0910EE197ECBULL, 0x26E3D130F640C964ULL, 0xF574AAEC91BA847DULL
        },
        {
            0x82C716C626EB507BULL, 0x61E20A773E5BFB25ULL, 0xB6E9CFB7730F4164ULL, 0x100CD7F8462A059EULL, 
            0x962C5C105CA9D2F6ULL, 0x8B2A727062ECD754ULL, 0x1B3EB723F8F79E27ULL, 0x4F0DAADD45BEC1E8ULL, 
            0xD85B8F18B895F91BULL, 0x59915C308F057642ULL, 0x3CE22D0120819935ULL, 0xAB15240AB69A7C21ULL, 
            0xA3E2AD3ECA32F6D0ULL, 0x6B46AA700C324DD5ULL, 0x8A6E0EC0744A99C3ULL, 0x1B72CFD7281A0751ULL, 
            0x35674075CF76DD98ULL, 0xA863E2E9F7F96650ULL, 0x86E529E80C9FD3ACULL, 0xE43672821CBF12AAULL, 
            0x36349D5A063E25B1ULL, 0xE16A40103701C787ULL, 0xC72AA7647E950B9AULL, 0xCF873FCDA7C7F920ULL, 
            0xDFCC5E00E6DF477AULL, 0x91E1DE8CE34F409EULL, 0xFFC18574FE408933ULL, 0xB74E4809E8F92071ULL, 
            0x00707A08DF64D7B9ULL, 0xFCC3BBD4465BA69AULL, 0x966AF219747B14EBULL, 0x0BB48567B57CF096ULL
        },
        {
            0xE7B1704376E14BC6ULL, 0xF5DB7825CFA6C9BAULL, 0x4898587F74BADB1AULL, 0x2E894EF0EB1E9696ULL, 
            0x66A6DF1E84092AEDULL, 0xA81B99AF51399860ULL, 0x15839AE82E7F99F9ULL, 0x5992866C89FF0FC9ULL, 
            0xB5EA7036530650A7ULL, 0x4B259AEFBACD5412ULL, 0xE38009D809E2F0E1ULL, 0xB003595AD8EA36C5ULL, 
            0x658FBBBF5DB5DDD1ULL, 0x7EFB242DAEFA71A3ULL, 0xC685C5D2399541CCULL, 0x01F5AA80419446A2ULL, 
            0xE674BD13F64B5341ULL, 0xF3BC168338DA7762ULL, 0xE2486D58070B6610ULL, 0xF28C787B1EFC5776ULL, 
            0xEE2CA6CE6E04AC6FULL, 0x4237005EFEB05B54ULL, 0x9D16546FFBA3411CULL, 0xD57ABE6AE2C40DC7ULL, 
            0xA7A74320E266B645ULL, 0x559302588B82B83DULL, 0xD72656F156FCA587ULL, 0x667822FEE450848CULL, 
            0xF885D15DF24AA6B8ULL, 0x3E525092C8B3E59CULL, 0x1B98BB3195C11F8EULL, 0x7FC32AC149A065C1ULL
        },
        {
            0xB6E3DE974BCBE93BULL, 0x8B2176BC8D4D24FAULL, 0x0DC2FC012B7E75AAULL, 0xDD40F090BE1B78ECULL, 
            0x5660D27D7BB733BEULL, 0x7EAEC41BBDDFF4BDULL, 0xA12E481E1346F451ULL, 0x5BF5743453C3BFE2ULL, 
            0x920FBE26088267D1ULL, 0x4B087503DAB94A0EULL, 0x73A807958871ADE6ULL, 0xFBEBC38855457F50ULL, 
            0xB8311452581A5CD2ULL, 0x0B756A0EE8EE8472ULL, 0x3F0EFC36D23BE5B2ULL, 0x126B0B6BB74904E6ULL, 
            0xAA44B5E0AD4096DEULL, 0x66D2FDDB9E5430EAULL, 0xC440DD465080EAEDULL, 0x8EF3EA4DFC9D748CULL, 
            0x0277FFD2E27A8058ULL, 0xA9A64C5C7F3EE19EULL, 0x23B0297FA23A2536ULL, 0x802D2C18DB29C06BULL, 
            0xDD926EC33311B319ULL, 0x885CAAD4B63A0A8BULL, 0xCF3E9716074E950CULL, 0x7288FF3C7EC35C79ULL, 
            0xEC46E666EA7C2C84ULL, 0xD866D629E018C018ULL, 0x3E9F27C1D7589E61ULL, 0xE7F2285F15B39A4AULL
        },
        {
            0x48E066692C33F859ULL, 0xF5AB16AD45604B41ULL, 0x77B4B9D82AD5C452ULL, 0x35A816E50D19E4C2ULL, 
            0x4F99FF6AC5A30499ULL, 0xE3648CB9F45A8687ULL, 0x0FAFCFC93AD0BD2BULL, 0x0E101C2F99E5AC63ULL, 
            0xE9F074F7DA158816ULL, 0x695B773C7BE326CEULL, 0xDEB1AAC17692AE3DULL, 0x7E4052243859DB10ULL, 
            0x701812BEC5BCD1DBULL, 0xAA308F01E0372005ULL, 0x2A3EA9A67F2CA1FBULL, 0xC2F3E7BFD7A38A20ULL, 
            0xF6963B6AA4479A71ULL, 0xFE918EF8B7A06B33ULL, 0xD7561C6C57CB0946ULL, 0x151CE46A075279E7ULL, 
            0xCCEF0DB0CDDA7E0DULL, 0xEC20B57308C04CA6ULL, 0x8C475EB13841EA38ULL, 0x7CA3A1BBC491B659ULL, 
            0xF026A3B2BD55AD6EULL, 0xC8A1F6B4C053989FULL, 0x00DA1E088EFB5D45ULL, 0xEFBA3610E1AB1AC6ULL, 
            0xE625309C1E883180ULL, 0x6F126924916B642DULL, 0x903C0A3EBE98B913ULL, 0xE61E1D4B8397AA2CULL
        }
    },
    {
        {
            0xC8E319DAA0852FBBULL, 0xE359B408D9E4CF3CULL, 0xC6AEE26528077AA9ULL, 0xB7AE9EED8A5F35B9ULL, 
            0x2C54146B2CE86628ULL, 0x435E5508AEBD2DD2ULL, 0x8901FB968371523FULL, 0xCF7252DA38EC199FULL, 
            0x76D4EEF698A7FA5FULL, 0x46A914CD473E3105ULL, 0xF710944CF4EA610AULL, 0x05D77857F9903F58ULL, 
            0x192382127612F2D3ULL, 0x75BF82B517BE678EULL, 0xD46EBFD46AF85961ULL, 0x2742F9EBAD41F805ULL, 
            0x5D54B1F1EFC82110ULL, 0xCCAA6AA9FE230ED0ULL, 0xAD4B5932BB2580DFULL, 0x363182B0A075A8AFULL, 
            0x5D13BA79D8BAF05BULL, 0x718D468B72945C44ULL, 0x9F593221DBCF8DD8ULL, 0x58A5AF6524050FE1ULL, 
            0xC2A1FA1AD5F686BCULL, 0xD815DB8442871B86ULL, 0x8018C15E61B53E26ULL, 0xB4B200589FBD0DC4ULL, 
            0xDA877CD6FA000A9FULL, 0x54140DA849DABFD9ULL, 0x40A734C8D44DAAC3ULL, 0xD7DDD2460544B1BAULL
        },
        {
            0x17EE16A86DBFE56EULL, 0x62A908FB89FA2EF7ULL, 0x3E7AA708D934444FULL, 0x1D3745AC2A3DBF45ULL, 
            0x792B603532F84352ULL, 0x17D813353B157D5AULL, 0x9F705E3162D34F54ULL, 0xBDD281B675E5545BULL, 
            0x8BC3B897405F2385ULL, 0x80777D3207CFA361ULL, 0xB91A968325CFAD41ULL, 0x5F459E67925D1CBAULL, 
            0x31EC288CE33C0CD0ULL, 0x40B12669EFCADCF8ULL, 0x173DF44193BBC9DCULL, 0x165F9B92F0B5D34DULL, 
            0xAA3F6D1E9881FA8EULL, 0x9D0B2DA9CF0EE662ULL, 0x6351849AB95DB6B7ULL, 0xA8B95CF0EF1D7B65ULL, 
            0x8E8144CB143B7E95ULL, 0x26B2BA9FFBB125B0ULL, 0x27985AECB049AF9BULL, 0x298408FBA9D09C12ULL, 
            0x97E082113C80EFA0ULL, 0xEDACA426C92BEE82ULL, 0x630841CEE0FD61A1ULL, 0x1F7B10E9FBA68100ULL, 
            0xE17478E0D6668158ULL, 0xCE85E52216D83823ULL, 0x3A0D152B2D97608DULL, 0x1624AF75708F1DA0ULL
        },
        {
            0xAECF3DD841BADB8FULL, 0x0D669FCCA747BB67ULL, 0xC1F9E68FAD6E7341ULL, 0x3DCADBD3862D02AEULL, 
            0x5F65CB3CC8B75EF9ULL, 0xFF265891727FD1A6ULL, 0x76BF134DDDA692BAULL, 0xDA67EB0524F6AA73ULL, 
            0x948E87397DCBDACCULL, 0x6D8FA029DD08F77DULL, 0xEB0CE85172AF2476ULL, 0xC4B6E589E51226F9ULL, 
            0xB1A781C9C32A4C30ULL, 0x278F73F99092B517ULL, 0x0357F2F46D63CFA5ULL, 0x3B14DE9EC40268E2ULL, 
            0x239137EF299FEC93ULL, 0xC4DCB522BAFAB35AULL, 0x65908ED7B9DF8354ULL, 0x1CF674710DCBD2C0ULL, 
            0x30B86D2F22F47F27ULL, 0x9C107AFCF8F0F61AULL, 0x1F6E942ABB4107F5ULL, 0xBA758AADB05896FAULL, 
            0xECE31B04154B2DCCULL, 0x38A6403F3DCBB084ULL, 0x585159F027372A01ULL, 0x07561CEDFF9861F6ULL, 
            0x3DB625A979466242ULL, 0x0071E4FF55E09B53ULL, 0xE03E77773B29A00AULL, 0x8B6A0C867D4C31A4ULL
        },
        {
            0x6B96E95860694C60ULL, 0xB4144F4E10455959ULL, 0x2A6FF204F2A6863BULL, 0xA4469E2CEB29D736ULL, 
            0x876CEED41A6433E5ULL, 0xC9A679FF4039A38BULL, 0xDEE8C7ACCFEE49A4ULL, 0x2F2F4307FEE9FCD5ULL, 
            0x28D2D04F30E4F1C9ULL, 0x5BF6EF5DC2B6BDEDULL, 0x0CF9A734E232BB0EULL, 0x7F227310B4B50253ULL, 
            0xC95AC1A01511B7C8ULL, 0x204BA644E1593A41ULL, 0xC4B014B8B1789411ULL, 0x70C5D5BFB3FF6227ULL, 
            0xB7F000BF9F989661ULL, 0x6348C9C35CD99BBDULL, 0xFFD66C7388508F7EULL, 0xC95A32625C17171BULL, 
            0xD7B654C6ACE5AB18ULL, 0x7E73AE91A346A0D7ULL, 0x99825FDBB9005445ULL, 0x0FD759417B308D22ULL, 
            0xE7A8133110A95B36ULL, 0x139B380A24D5A454ULL, 0x04AD252EB142E0B0ULL, 0x56A12E8046B0704AULL, 
            0xB882D7BA42533692ULL, 0x958DE5FC326758FCULL, 0x221BF573B114D835ULL, 0x274C50245D5D57D3ULL
        },
        {
            0xA07DD1EC4E868107ULL, 0xE2748A7FBE0265A7ULL, 0xB9995257F4773B97ULL, 0x8B0A6981504396A9ULL, 
            0xBC957700A54C672FULL, 0x4526B1D05E237EF7ULL, 0x5B7AB3A48DEC6777ULL, 0xADB9BD555206D6F8ULL, 
            0xEF98348979EF12ABULL, 0x6C65C9A762EF3B88ULL, 0x0823916D4556D26EULL, 0x6BACC408DB0B2F46ULL, 
            0x0C457EC7EC8868F6ULL, 0x2AB6B54C7119038DULL, 0x4D799E8430BBA81EULL, 0x9BB68E90F400E76AULL, 
            0x2FB57F97C4F19DB9ULL, 0x6A62DA4147D5B887ULL, 0x18740C7C5EF8FC2EULL, 0x18BACAC68AEE04A4ULL, 
            0x2E507DDB7E2918FCULL, 0x4646C1AD5E3EDE11ULL, 0xADAEC34456366601ULL, 0xFFB5A720AE38F7FDULL, 
            0x83DDFEFF09FDBA16ULL, 0xF0A8E5B4D96DB47FULL, 0x24AB28558C671633ULL, 0xCAB992D53D33F64EULL, 
            0xA0183D821A410791ULL, 0xFAC7717561BE71ACULL, 0x3B5DAB9A9FDE1C06ULL, 0x1B34B7A22A5650D9ULL
        },
        {
            0x0713687FFD04CEE6ULL, 0xC8576B1E34C1DD69ULL, 0x2A9127CB8927681BULL, 0x3ABABEA777F7E927ULL, 
            0x940C67EC83B9E433ULL, 0xD61B39700F26F0A0ULL, 0xF177E7F9C2B9FBE3ULL, 0xBF9E02DDAA1B1852ULL, 
            0xD989ECA72A970B87ULL, 0x1AC5CDF4B0F13045ULL, 0x1D1729556E18162DULL, 0x27A028026C0B76CBULL, 
            0x72D7819A1D152EFDULL, 0x5F82DEAEE752AFA4ULL, 0x062F16E38916C367ULL, 0x540E9767B8A87EE0ULL, 
            0x35982097CB5158F0ULL, 0x9975F5117E822316ULL, 0x858E3870D408911FULL, 0x637768364AC6739CULL, 
            0xC3D3415108DEBB06ULL, 0x3439E6E4C8CF4193ULL, 0x6DFFDF29126A2B86ULL, 0x1553A875674CECCFULL, 
            0xF0984BE6BF626DCDULL, 0x334AC0F3F7EE5134ULL, 0xCE23EAEBDD6B1B54ULL, 0xCE28B952C00491BBULL, 
            0x3EDD3A8EEA09B478ULL, 0x251CEC5CFE004A6CULL, 0x7372BEB7C1EA2230ULL, 0x2981910D34C13037ULL
        }
    },
    {
        {
            0x37590BCCA1ABA3ADULL, 0xB0BAE98B2F1924D3ULL, 0x6FDB8551A7905457ULL, 0x978709E7169E2F01ULL, 
            0xC8C22862640232A3ULL, 0xC074FBEF40CAAC74ULL, 0x52AA0B7291A3AE08ULL, 0xD03B4F1445E33656ULL, 
            0x9C94F1CFAF05204CULL, 0xBE4CED6EA23D1745ULL, 0xBADC91FBE5870071ULL, 0x3EE23C6890D5780CULL, 
            0xA9187A3677BC2389ULL, 0xD917996C9A0A2471ULL, 0x7181C106B9757394ULL, 0x1E059859506F3210ULL, 
            0x975A05A311F4CEAFULL, 0xB1EF65E6DE2536F7ULL, 0xB40B5B6BEBEBEE29ULL, 0x78B81190EC123350ULL, 
            0x24002195D51FBB51ULL, 0xD774D0CFB9B32586ULL, 0xCCECBC3B507C281AULL, 0x5395A4AB0D8EA8CEULL, 
            0x13C7C027F9F663BDULL, 0x4B826E97794ACFE4ULL, 0x65D3B07B77AD9502ULL, 0x7C966533AEE3247FULL, 
            0xE5D7972B8FBC5497ULL, 0x318318EE4592FB40ULL, 0x5DCED1727F00B500ULL, 0x35A356C0E9D1BEAEULL
        },
        {
            0x5998BC16A626BAE8ULL, 0xDE2D985204C85DE3ULL, 0x8075B6332F6FF86BULL, 0x0BC998C12B49A50CULL, 
            0x68F15704D8075277ULL, 0x940323DE0AC8F1F4ULL, 0xA3BA60367E11CB41ULL, 0x2E7369238D43B9BAULL, 
            0xBEE8D998279BDCA8ULL, 0x3BF153560512A2EAULL, 0x1B35E693A2E1E21AULL, 0x6151A174340D03A7ULL, 
            0x37059A2735B8BDB3ULL, 0x32307B0FCFDBCA10ULL, 0x5900808F462928A3ULL, 0xE62D5F79E64B71BAULL, 
            0x806A03E048CF814FULL, 0x6F0BABDD49D2503BULL, 0x593EE7347FC16E7BULL, 0x1FAC712A14A11560ULL, 
            0x7FA4DE33C26904B8ULL, 0x92BD48C2E9604C21ULL, 0x1BE61C6B8D6147B3ULL, 0xD9580BF510AB2E3DULL, 
            0xAB298D95F8532135ULL, 0x1EAF9424D7BC0273ULL, 0x9402C867A497BB48ULL, 0xF657F0484DBB6469ULL, 
            0xFAFEF5925C0E52AEULL, 0xD6FB41FE5A562D8BULL, 0x1A7BE8B050DAF854ULL, 0x85DDF3460F7F4D83ULL
        },
        {
            0xED93356511BB93FDULL, 0xB28FC0647E8580A7ULL, 0x7CE4F362B0CC712FULL, 0x73853D932674292FULL, 
            0x74C008A1F10CB158ULL, 0x1992C28EA47BB68DULL, 0x6D248D984D70AD54ULL, 0xB1F88B80111E62EEULL, 
            0x810A996CCF2C65CCULL, 0xFB099C6D069CDD94ULL, 0x67D618F4BACFB7CFULL, 0x5CDBAB1A59A117E8ULL, 
            0x7FB256C2B9BD018EULL, 0xADF73365E1A0890AULL, 0x98E96368D540A9CDULL, 0x457EA9B293FBA097ULL, 
            0x71F0EA019FB03B1BULL, 0x2EEE0CF91AD9A567ULL, 0x0A58D4BE1E4E6A92ULL, 0x8D1CCBBB7CD3F829ULL, 
            0x69609B22AECA858DULL, 0x7D8AF2C4978C651DULL, 0xF0F92A631D0DA100ULL, 0x9581999E3D1D6DC4ULL, 
            0x9E9C1684CFF12A6EULL, 0xB77F48997E6CA825ULL, 0x6037C47DC2813A38ULL, 0xF210111DB670BC29ULL, 
            0x7747F9A4110339EEULL, 0x9E2620CA086093BFULL, 0xB0096597F08219B0ULL, 0x8AA39A097997A887ULL
        },
        {
            0xD5D794A5D5D8C33DULL, 0x2AFBE91AE4BDACC2ULL, 0x234B47F090FB6E5DULL, 0x0ECC26E24783637FULL, 
            0x2576EBDBF4961D95ULL, 0x9A1E57B85DEF4EE0ULL, 0xFEBA27CECAEDC16EULL, 0x05E57AA164E624E5ULL, 
            0x6F1D65B255A8D3F6ULL, 0x70FF0D25E4507020ULL, 0xBC9DE203E6098EB7ULL, 0x96C49A0EA77329D3ULL, 
            0xCCE7E9865319043BULL, 0x60C0FF9E311A1981ULL, 0xA2FE309DE1B4B705ULL, 0xFBAB979311CDA6F4ULL, 
            0xE2635FF88AB158EFULL, 0xA06326EF786656F3ULL, 0x1875AD589B47CB9FULL, 0x8126843179413868ULL, 
            0x7D1FA7CD1F25A622ULL, 0xAABBC01E66C2947CULL, 0xA5EA1066542A0379ULL, 0x941EB2A37E25406DULL, 
            0x1DB87E395C4B6A7EULL, 0x809A1219A79645FFULL, 0xA0E0730B4BA00FDBULL, 0x37F105B1D3E6117FULL, 
            0x66DF2D48750217BBULL, 0xB5B5EF5A7A74394EULL, 0x6A04EF6EE7C3020BULL, 0x2BF33708A2E4B656ULL
        },
        {
            0xD6A058F0C2721256ULL, 0xDB7719DDEBFA93AEULL, 0xA3DE1E85E20B5B22ULL, 0xDF9988BE63601AD6ULL, 
            0x6E139D50FB3CD54BULL, 0x2C7FAA0091DD1BD9ULL, 0x89D0AB47CE16C2AFULL, 0x7FE1027D3DD70846ULL, 
            0x01E0F7080DD8BDD7ULL, 0x888420F08D51B1BDULL, 0xAE3617AC0582515AULL, 0x80BB888FC43CED20ULL, 
            0x6721DEF7E9668881ULL, 0xDF04FDC5E5C7CE6FULL, 0x6A19FA98896B8A25ULL, 0xE7B8AAABB25CF76DULL, 
            0x63224771A33050C9ULL, 0x877790AA00531642ULL, 0x9E3499205569AC36ULL, 0x452249EDBCE9C074ULL, 
            0x91C94FDEF07EF63AULL, 0x3C5AFB4B9EF05BBAULL, 0xBC50BFB14A79A5BAULL, 0x9905BE616B518CF5ULL, 
            0x3091932324609DA3ULL, 0xDA35F239B03B684FULL, 0x1F13BA88F8E2C63AULL, 0x2010CBA31DAEB311ULL, 
            0xB64DEB541B857564ULL, 0x797171AD5D1E34B2ULL, 0x6B69F4930468A40AULL, 0x2617DE6453B4059AULL
        },
        {
            0x8ED72815D331249BULL, 0xC80D66103D5C4DB5ULL, 0x34F3A0426B26F147ULL, 0x1F5D70EA79427D8AULL, 
            0x588355D002CE98BCULL, 0xB8D26A0A9422495DULL, 0xC47C9E303119A75BULL, 0xA6E818C45355CDBEULL, 
            0xEBABF895CE146709ULL, 0x5F4858DC41063EC8ULL, 0xEBDE401B09995FA8ULL, 0xE257D4A4AB163C80ULL, 
            0x813940C01E52DB7DULL, 0xDA8B97CF220A8C10ULL, 0x1B773C01D6B5BC7EULL, 0xFE21C8ED1C2AFA52ULL, 
            0x46326F295B025122ULL, 0x08FE1FD790B910B0ULL, 0xE4B71ADCDB71F9B0ULL, 0x331E64825EDF9FE6ULL, 
            0x3B2AF716F1E44A56ULL, 0x4080AC4F1462ED32ULL, 0x8B8BED37F82266BBULL, 0xCAB5E97B5988EA7FULL, 
            0x2E390BD4EBFA66A4ULL, 0xB112CA003FC2B4FEULL, 0xA533B261547C41F3ULL, 0x6F0E84F917C6F18EULL, 
            0xF331EFCD118D28EDULL, 0x26BFE6AF65EAE6A9ULL, 0x016395898C7243A4ULL, 0xEFDCF63815438A2DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseEConstants = {
    0x9A409293D46F4AA6ULL,
    0xC8149B5339361596ULL,
    0x43D830C815C57C00ULL,
    0x9A409293D46F4AA6ULL,
    0xC8149B5339361596ULL,
    0x43D830C815C57C00ULL,
    0xF3990F7889562CACULL,
    0x8395ACD1469BFFF7ULL,
    0xD1,
    0x13,
    0xB9,
    0x08,
    0x3D,
    0x74,
    0x54,
    0x51
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseFSalts = {
    {
        {
            0x4F38F0B13B18F793ULL, 0xD8DC7F7085EB4B83ULL, 0x05E43AA0E576636DULL, 0x3534670D4CE94E34ULL, 
            0x7B39BC1908241850ULL, 0x92720B66DA8CC5F0ULL, 0x37E8A99B19A18079ULL, 0x0397698C2556488DULL, 
            0x0DA8771FA4E2EE19ULL, 0x3DDFA1672353F01FULL, 0x1EBF49CE3D8645D6ULL, 0x3EE6F85F29C9E55FULL, 
            0x89A43463DEC6ED5CULL, 0x816B2F7CE6DF9DBAULL, 0x38CACBB134CF6826ULL, 0xB680E8938FFC5980ULL, 
            0x8A784B41A26FCCBBULL, 0xAC7D3D8CB2403289ULL, 0xE3743C787467F728ULL, 0xBC9B18238EDB9804ULL, 
            0xF0EE498A93A17B34ULL, 0x93E3A3CF295B2A0DULL, 0xA33C5D5BBDDB8AA5ULL, 0x4B572F1A211794ACULL, 
            0xC1CB60821D2AFD87ULL, 0x5AA98599CABCCCC6ULL, 0x03F6E289FFAEF092ULL, 0x313E21465D9BD2D4ULL, 
            0x57FE30CE01B8BDE5ULL, 0x4816B7A577F325C3ULL, 0x5A6AB9F252726816ULL, 0x40AD71DA38E0AAEFULL
        },
        {
            0x788F5CA79B34B2F1ULL, 0xAD012C8E4CE87E5AULL, 0x204E079DDDAD81DEULL, 0x2E80EA5E43523B64ULL, 
            0xC835420D134A75F9ULL, 0xD3518C9636B4BA8FULL, 0x77A041812B93EE32ULL, 0x128C04BE0F93BD8FULL, 
            0xDA79495613628CF5ULL, 0x22061642C564059CULL, 0xD5FA58AC30DB508EULL, 0xDBDBFE7D99463F23ULL, 
            0x89D61372388C479AULL, 0xA7AD113A5ACC2621ULL, 0x8945500B3C1BA4F3ULL, 0xDE6225A686B6FC59ULL, 
            0x615AE1587B0BEE10ULL, 0x0C0502D8FA8502F3ULL, 0xA3C38FD153F2DF76ULL, 0x560C1A9E2C8E2180ULL, 
            0x03C9801D8B750449ULL, 0x81483341BABA4715ULL, 0xF55660F61E2230EDULL, 0xC7B7F7151BA4F29DULL, 
            0x2C51A3F0BF74F7FEULL, 0x96764E63DEBA276FULL, 0x1EFAE8606185183AULL, 0x9B2D61A487DE6AAEULL, 
            0xBFB921C1152EF97FULL, 0x9A205015291437CDULL, 0xCFA16B71ABB43F0CULL, 0x81487CF4C8AE7459ULL
        },
        {
            0xBA49D60BD27963C7ULL, 0x3FB08B12FC42F5FCULL, 0x3493057F64F082A8ULL, 0x5EB1E242126560CDULL, 
            0x46FCDB9931E6EBC8ULL, 0x6D6D29388AEF16C4ULL, 0xEA90C0A539787549ULL, 0xDE5F4D48A6AA1E77ULL, 
            0xD538CA8CB78A6A6DULL, 0xA3FA17ABB2E17F6BULL, 0x3B0398ED3BAFEDEDULL, 0x6DE1B575B1DF64FEULL, 
            0x9DA660AA1BB7B086ULL, 0x217B7F306075E91AULL, 0x2EA62088ECDBB09EULL, 0x3209DB4CBCEEC21DULL, 
            0xE0AA26DBBAFC7F8DULL, 0x15E73381A2EF98D9ULL, 0x07E03D047E3CB315ULL, 0xBC565D3F41286250ULL, 
            0x0F168FCD9A366F9DULL, 0x81E2A4E125D0C6B7ULL, 0xD83CC9AC8FB4AC03ULL, 0xF179E7A25A3DF652ULL, 
            0x18AE80D3DAC211A6ULL, 0x8EB65705C0BDF232ULL, 0x58382AA571701857ULL, 0xB6491F76880EA358ULL, 
            0x4EA0691642B4D277ULL, 0xC8E6156EF6FFEE13ULL, 0xC63043CC58F19C99ULL, 0x80D91AACE42EDEAAULL
        },
        {
            0xC228A42C3FFC4F12ULL, 0x44CD9E2400958422ULL, 0xE61913C1ADABDCBEULL, 0x50602D1798823657ULL, 
            0xE514E878C9D7FD0DULL, 0x094F1EDE6C57356BULL, 0xDBD5B13CA91CA4B2ULL, 0xB1D1D9EF9C663B8EULL, 
            0x95FA43F6F8EB6D4CULL, 0x717BF495DAE0A339ULL, 0xA144A4E1F89E61A6ULL, 0x9368C3264F00F958ULL, 
            0x9AC39727A3B51E1EULL, 0x1E377EBF63D2D4F6ULL, 0xD6EC11E00F9FCFE0ULL, 0xAABC56FAD40C994DULL, 
            0xCBE9F97A542A2292ULL, 0x6290F2E63FD48359ULL, 0xF421DD56FBEEB73BULL, 0x3B1BEC2EBAE1226CULL, 
            0x468E320E09845D64ULL, 0xFF5AE54724A78655ULL, 0xEEBA8AD528B9C871ULL, 0x420A055D21303D65ULL, 
            0xA22D17C4FFF0FB02ULL, 0x82EA22AD7738E1B9ULL, 0x0D4651ABE92C4505ULL, 0x768EDB01F47D6EF7ULL, 
            0x21657C38916E5A53ULL, 0xE876E28D7423BA06ULL, 0x042A06F75CA571EEULL, 0x0B9FD09ED30682A7ULL
        },
        {
            0xD4EADC14EDB4075AULL, 0x76ABBCD992F661F0ULL, 0x64FC37862BC53F30ULL, 0x3FE0B4C58959C16CULL, 
            0x9C4E64D6EE33B00BULL, 0xEE75FDB12CF7551DULL, 0x1721A8BFBCB79ED8ULL, 0x711D5897BFBC89BDULL, 
            0xBDDF28F933905366ULL, 0xE34F1759CE578B22ULL, 0xD669E3E8697AC9E5ULL, 0x8E9D4D21890B1E45ULL, 
            0x04E9D32D47E3ADABULL, 0x926AA0696B85F83FULL, 0xD7F3BD390DF0B390ULL, 0x5E36B2B758079E8DULL, 
            0xAD4F9106F31AF51CULL, 0xF3F7EC6A40657478ULL, 0x1EA439F74639D342ULL, 0xAF68B3DA90994C00ULL, 
            0x9CABE47F42F76E4AULL, 0x87B96B251F702902ULL, 0x05466D23A233DA94ULL, 0x30CF6CB1B861F287ULL, 
            0xE4A96A902F7526D4ULL, 0xF9646E8F25FDBAA8ULL, 0x5E99ADEE30EFF545ULL, 0x8ABF127A0FEC2E2BULL, 
            0xDE5A5DA3AE3E8868ULL, 0xECFE38A4973B20C1ULL, 0xE4F0D7E3543143EAULL, 0x2F46AFC5F51CAF8BULL
        },
        {
            0x454A08918A762E99ULL, 0xED8CCE770B5244CCULL, 0x34E88CCB0EF600D8ULL, 0xCF6EDAFD6E611799ULL, 
            0x733602202036534EULL, 0xA1C3C0BB336C2338ULL, 0x80E0A81DA28EA1C3ULL, 0xEECBD8619DF27548ULL, 
            0x0F4486733E866E58ULL, 0x64DC72608B03FCCEULL, 0xC14B1251CAA8996AULL, 0xFA635E71FB659ABDULL, 
            0xF93BADAB4A0BC652ULL, 0x6C2476472FB8D91EULL, 0xEA5788CCA73B80EEULL, 0x41ADC6F149391B96ULL, 
            0xB7D6C4F625CC36ABULL, 0x3CAF148E1C2D2227ULL, 0x5356766B4C8B1483ULL, 0x2E9D1DDC016E94F0ULL, 
            0xE0AE6D49B4A3BB9AULL, 0x5A92D8AFA69404EEULL, 0x06416AF9248A9498ULL, 0x7EDDFFEE64C1C759ULL, 
            0x9723F7C1210A7F6BULL, 0xB736DBA104AD3119ULL, 0x76204675DB319616ULL, 0xBF28C4A68015E5D4ULL, 
            0xD3E8C26D65C89D0BULL, 0x83236E705E53671FULL, 0xA254FCD4783A200DULL, 0x39CF0505CA2767E6ULL
        }
    },
    {
        {
            0x85F348D2798C6B13ULL, 0xD7269B7046FBB817ULL, 0xD3A8119E8857D2DFULL, 0xA5FC62D38EEACB82ULL, 
            0x281225C704900F4CULL, 0xFECA4693D369D8F7ULL, 0x6BBBCFDAD799E6D8ULL, 0x366C62A656F8D551ULL, 
            0xA51769154721973EULL, 0xD240854878866B34ULL, 0xD38B4DB6516ED63EULL, 0x5B468F892921DFE1ULL, 
            0x39D7A3DDD3C2907FULL, 0xC375963B84CCC3D2ULL, 0x6F4DC7B411A18B3DULL, 0xD1600886D289026CULL, 
            0x8C8B758872C36D22ULL, 0xD9C67BEE6D6A635AULL, 0x7B2F4AFD5D992C47ULL, 0x244C83A1CE31EB67ULL, 
            0x74F702D9C8881A61ULL, 0xE3E57282FAB71BD6ULL, 0x72AFDE6671787D14ULL, 0x7190AC8FF11F8EC5ULL, 
            0x24788D5957BCF588ULL, 0x4569741FE239201BULL, 0x9DBB0307081804B2ULL, 0x3E7FB17FA2F4541CULL, 
            0x7A7F4C6210FC9903ULL, 0xB60A756FDB805398ULL, 0x2BC68DC6875CDB1CULL, 0x57963C5106594786ULL
        },
        {
            0x40A72FA817F00342ULL, 0x5576099226E6736DULL, 0x60764FEB663561BBULL, 0x70434B8D144CCE32ULL, 
            0xF20E8E8ADCF7EF38ULL, 0x4E76E6A3EE84A7BBULL, 0xCB0DFDB1E2245998ULL, 0x214E2B62F6308C6BULL, 
            0x983D57E68AE4DB0DULL, 0x7979AF1A26F97552ULL, 0xCC7543822E0994AAULL, 0x285D91CB08CFFC29ULL, 
            0x50586A5906AA485AULL, 0x005ADBFF2585CDD1ULL, 0xD457BEB32B2683EBULL, 0xEB409CC923F84C0BULL, 
            0x7B790E333A727B0FULL, 0xE0D9AB66B527726EULL, 0x28B499316C35A6F9ULL, 0x1997EBC03B8060B8ULL, 
            0x6A0DE4E77C439090ULL, 0x37B2F673FD783394ULL, 0xE3CD95640327A97BULL, 0xDB40B6A299978332ULL, 
            0x01F44FD904E68690ULL, 0x5777013D88BFC38FULL, 0x38C5E909D7AE051AULL, 0xE9556C98F774168FULL, 
            0x556D3FAAE5E7E80EULL, 0x618DE8A42DDAD72BULL, 0xC37D89406DEB48E8ULL, 0x3D5B4B9AE799C1EFULL
        },
        {
            0xB426D46D4D1071D4ULL, 0x0B8A26E1E1D6F5D8ULL, 0x549FACDDF0269835ULL, 0x4450A01FAAEA5D2CULL, 
            0x4F11EBB8B381083DULL, 0x59094198D48D1FCFULL, 0x71E10F963ABCF500ULL, 0xBA51601568F5596CULL, 
            0x7AFDCA915990EA58ULL, 0x345D2FDE3E0A623BULL, 0xB13B34B812BC84B4ULL, 0x4307570059896C26ULL, 
            0x3127F48A626F80DBULL, 0x3CA1E5BCBA9851FAULL, 0xE0CC06844E6BD913ULL, 0xB26835C39715234EULL, 
            0x974ADCC99EE0BAFDULL, 0x4512B0BC93A718F0ULL, 0x5E6FC2E0AD7D8996ULL, 0xEB06B21DFBCD7CF5ULL, 
            0xA014DEBC8ADA4743ULL, 0x109AB62566593C2DULL, 0x22492B380AAEC67CULL, 0x8B9426C29330D0C4ULL, 
            0x379C41E18A89B1F5ULL, 0x49A0A8910033E971ULL, 0xBAD32970A24F1413ULL, 0xC53F6BD6D1ECA584ULL, 
            0xC31DB5816404AAFCULL, 0x1C89EAF99CB69918ULL, 0x5BB394E5EF4EB987ULL, 0xE8950E74E071D585ULL
        },
        {
            0x9ED0A0D627B2204FULL, 0x28F7F025368C96DCULL, 0xA7371080AA788118ULL, 0x9FB9C61893547623ULL, 
            0x0BF94F88C2E04F0AULL, 0xD792ACF12B8FAD0CULL, 0x380B52B5C50AF081ULL, 0x4AD41E0967897395ULL, 
            0x5DB3410EC0E8F43AULL, 0x339D7DE995C5002EULL, 0x5B37F35BAB1888D1ULL, 0x6C68A75C98CA81A7ULL, 
            0x969DB52B85FD24C4ULL, 0x9F8F9D244F63016AULL, 0xFC3224E6BEFF4061ULL, 0x09949047F65D4FCFULL, 
            0x2F412E94BD281C38ULL, 0x5EC4543D62AB9646ULL, 0xC0CFCCE1681E7957ULL, 0x2228797F3A9B1BE9ULL, 
            0x30961D1BA9CD79A5ULL, 0x9C51CE9CEAF0E3EBULL, 0x8C2DE6B52B36B506ULL, 0x96AC35EE02060838ULL, 
            0xC2E933C8A52B3DB5ULL, 0x91F9F5991264E2F3ULL, 0x02324206FEA0722EULL, 0x2731CC0351EE7A0AULL, 
            0xDE0B7919CFFD5644ULL, 0x10620F5CCC96D26FULL, 0xC216D6FC3C626360ULL, 0x9FF62511CB88395FULL
        },
        {
            0xB3FB15760B38D12CULL, 0x2040B77CBE786104ULL, 0x26AA7034A10241F7ULL, 0x6A289F8CF52F8CFFULL, 
            0x0A2441F854F00839ULL, 0x4C5A8EAAEC356F60ULL, 0x2DC436BEC0E9D027ULL, 0xFCCCD5646450B610ULL, 
            0x3D045A2CBFF2F253ULL, 0x2A3DA88A84D88EC1ULL, 0x6864D12033BD5B78ULL, 0xD53459AC01EBA511ULL, 
            0x548F6F99501696E8ULL, 0xEF8C41342927F160ULL, 0xC10813715153C576ULL, 0x1C0DE91B299B4977ULL, 
            0x679E625B06817D42ULL, 0x6138E8CA62765CABULL, 0xB0B12837532DF3FCULL, 0xFBA964B6D5C7AAE3ULL, 
            0x48827FE67EA87B4AULL, 0xB9321AA6E510014AULL, 0x66BF50D2DE6A4F75ULL, 0xBE3E065232430E87ULL, 
            0xEACE1F649CFCC3E5ULL, 0xDBC11C5E0B0C9C05ULL, 0x805BA740CC2EBC46ULL, 0xD68E04BD355BC2BEULL, 
            0x9EF9F2022FCC56D2ULL, 0xCA271C9AEAA99AB2ULL, 0x43FA5CBD23B37524ULL, 0x54873FE5C1974528ULL
        },
        {
            0xC40FBA494268BC62ULL, 0xD78AFFBC07F30442ULL, 0x352C1C7AA70D6219ULL, 0x318EE9D998811042ULL, 
            0xCA0F545AF95EAC8EULL, 0x66DF5BBE5C85F464ULL, 0xEDE6050543529BA9ULL, 0x361AE388F304023EULL, 
            0x3BAB9B51315BFD33ULL, 0x7A0208ECF7709AF5ULL, 0x93D2876E2738762DULL, 0x4DCE4CCC02091A35ULL, 
            0x6A8BECA79B18CFD4ULL, 0x7EA804907D70E5DDULL, 0x1A8EC6B6C3758B4FULL, 0xF2E577691AB36059ULL, 
            0x3A52A56421DF8035ULL, 0x586F40B1DBEA58EFULL, 0x8192F29CF6119A2EULL, 0x65FF4D9D8A87F1C1ULL, 
            0x51DB0763F910DA1EULL, 0x6179AE6E94B77540ULL, 0x4AEE0132F34EAEE3ULL, 0xDE9D7BBE13E0800EULL, 
            0x844E830B2B9DD3EBULL, 0xBD24184A0EE9F338ULL, 0x038A2619F993252CULL, 0x4380239F3BD45759ULL, 
            0x6E439470EC434681ULL, 0x27E90F3D21599219ULL, 0x023BFA6991D56D8CULL, 0xD1AF955A2D000B48ULL
        }
    },
    {
        {
            0xC8A5109D865D83F1ULL, 0xABDDDD0230B60CB0ULL, 0x21C1C37BB0DACE8EULL, 0xA6C7566D2BE11CB4ULL, 
            0x9A9FF24D2F893829ULL, 0x9B08C2406ACBC7BEULL, 0x02AE4281BAB639CFULL, 0x675C17C5013A0B38ULL, 
            0xA1A2D4121323A1AFULL, 0x07CB65579773015CULL, 0xEB8FE0EDB7F6472DULL, 0xC29703CCE8D9ECECULL, 
            0xE092C661B0242978ULL, 0xF219E59952F58FE0ULL, 0x8A3B5FA9E60DA0AAULL, 0xCFE11AF05B173F8CULL, 
            0xEA890719F2063675ULL, 0x1200DC02F1AEF5B0ULL, 0xE2980CF641403985ULL, 0xF6B8511A7637443BULL, 
            0x7375338B4B107586ULL, 0xFB91D97E90A64F29ULL, 0x762BA1905E4B14B8ULL, 0xD2306384915F84F7ULL, 
            0x3AD7125CF2F1BD88ULL, 0xDCE46309E1EAF472ULL, 0xEE32EA90FB84FDEBULL, 0xA414F43F97C98679ULL, 
            0x9D8806048DC7A7A7ULL, 0xAA185F059ADCF4DBULL, 0x0B1CDDF7B95AAB7CULL, 0x020511D31AEC5195ULL
        },
        {
            0x28A8D3E0F04D4602ULL, 0x3F677FB97E394D31ULL, 0x4A383102A4523C74ULL, 0x19687590D9F54312ULL, 
            0x824FB335F553658DULL, 0x069A948DCE119EF7ULL, 0x303C8E50BF63E66FULL, 0xB9E35285013D04B1ULL, 
            0xCE79247701B77DAEULL, 0x7A7BE0EB1E5CFB80ULL, 0x01B97452F39DE9EAULL, 0x06A2C40AF84AA845ULL, 
            0x0DFE74D401BF676FULL, 0xEC356F0F72F91C72ULL, 0xC94062C1CE58ED8DULL, 0xF41B1FDEB9EB45C1ULL, 
            0xC2090FBA709E7DF7ULL, 0x0994AC871A781241ULL, 0x2B804EE8B4C8E1D3ULL, 0x6F958631D152786FULL, 
            0xFAE70C034D28EB9AULL, 0xA11E41C51ECCFF30ULL, 0x45198F15CA38E670ULL, 0xF64E543FC3F37691ULL, 
            0xFC3F66DEA0E66D4EULL, 0x539C163FFE38624FULL, 0x2F3A9FA1C23F1243ULL, 0x61D448AACC990C3AULL, 
            0x20D1E9DF3CDA37F5ULL, 0xB5466FB351E2101CULL, 0xEE44CCAEF7C2ADD5ULL, 0xF482B09992EB30C0ULL
        },
        {
            0x679ABD1BFD3E93EEULL, 0x129875F33F16565AULL, 0x6B9597C34D151CF2ULL, 0x490493232DAEC5EBULL, 
            0x86B784A66277753EULL, 0xE47F689DA217D04CULL, 0xE371E14527582EC4ULL, 0x9D17C1D61A22AC6AULL, 
            0x8424DFCC077CC5EBULL, 0x29B6C46BE21A491AULL, 0x3B3A416139C3656DULL, 0x6DF2597AB6240F10ULL, 
            0x55C7916553A8D8ECULL, 0x2A12EBE675C5FFBFULL, 0xC9AFC2E9E56A201AULL, 0x72747D9921DDAF35ULL, 
            0xC29D76A77F34F53DULL, 0x849059B065CB1944ULL, 0xDCA8177CBC652F57ULL, 0x1403FD8CAAC44C2DULL, 
            0xC2EB4C3D6B87E2CDULL, 0xA563D3449D953109ULL, 0x70DCF1348898EEC1ULL, 0x0B23318398BB5387ULL, 
            0x430BD35C684268CAULL, 0x036C304F3B4D5261ULL, 0x1688AAE2A9DEFC73ULL, 0x9F6E79DC5ACC44C3ULL, 
            0xAA47D88711750538ULL, 0x5C17D01AAE11C903ULL, 0xAB6B29E864F59B08ULL, 0x1FD6547115694F0CULL
        },
        {
            0xCE5D8AB9589A06E4ULL, 0xBA5CF06E6BD1BA25ULL, 0xC25BC0B2CDFBFCFDULL, 0x631E26763E91B013ULL, 
            0x196EFA2E9A06352FULL, 0x6A1AA2FA23868433ULL, 0x5A2625ECE03DF885ULL, 0xAAB11E1D17401027ULL, 
            0x78538A2ADD0F7935ULL, 0x904E8680989DBED8ULL, 0x6A01E97016FA43B0ULL, 0x4F8E01E36140B76AULL, 
            0x3125194EA3320364ULL, 0x87101906F11B05D1ULL, 0x3AB1D7096B2E1BECULL, 0x356E7B607C3E9A62ULL, 
            0x2D4BA2190E1C071BULL, 0x83A67FE0DF40A5F0ULL, 0x363E447DEC752F66ULL, 0xF8AF6A347E5DAC15ULL, 
            0xDE32B06787088AC9ULL, 0x234B262E46697303ULL, 0xF64170826CE71666ULL, 0x438E802EACD05F0BULL, 
            0xD064E5736488DCDFULL, 0x12F370745A9EABA7ULL, 0x03DB44FF2DCB9A48ULL, 0xD7D5CE56A15E29D2ULL, 
            0xFBDAE738DAD1C85CULL, 0x94E59550CADE6C3FULL, 0x30DFD6184658071EULL, 0x23C5D6338D0E0BE7ULL
        },
        {
            0x6D8688FE186983BBULL, 0x433FF49DAA438BCBULL, 0x3D144E1B658CFE40ULL, 0x2F81E14067573F57ULL, 
            0xEB9889B7B982F41EULL, 0x320F721F1B0B8545ULL, 0x43B1144477C24B46ULL, 0x7F5EA6814BBD1C8AULL, 
            0x76028A135DB6CB40ULL, 0x4994CD652129C54BULL, 0xF353023E68DA7FFDULL, 0xD059015E94FBD8DFULL, 
            0x1B30166F6C754988ULL, 0x7ACBC85140AA6362ULL, 0x6F712FAFEB0C874DULL, 0x36DA460D321B88A9ULL, 
            0xA92EF803F6A8427FULL, 0xD1A428107252B37DULL, 0x6A3132A7D6824DE9ULL, 0x9E690B1BBA17CA1EULL, 
            0x25F3B27EEBC3E928ULL, 0x829EABA480CEB980ULL, 0xEE9528CC71BCFCFFULL, 0xCC43B4E8CB713CC0ULL, 
            0xD7AE26A42855A6B5ULL, 0x2A8297B7C2421319ULL, 0x58E06A838D1BA73BULL, 0x629C1D487CDCB285ULL, 
            0x64BE8DE02459B1FBULL, 0xDDEBABBB20B3307EULL, 0x35D8C2A0C01BD6F1ULL, 0x76C8147F0627EA18ULL
        },
        {
            0x6BC241C7F848B4E5ULL, 0x07B8D3342B213F4EULL, 0xDFC240BCD584374AULL, 0xA64FF513E3B03EB3ULL, 
            0x88E56041A482C771ULL, 0xB03D04D0228629F3ULL, 0xBAECA1ACED255EEDULL, 0x7C97AD1ACCBE18B8ULL, 
            0x4E0D523A220BAF93ULL, 0xAEDFC5075916DCF2ULL, 0x7593D70D7EBB79DAULL, 0xC1EFAF9F282F8BDFULL, 
            0xB8A47DCF4319890EULL, 0xB89B4F52E0276C2EULL, 0x82CDAFD04FA81B90ULL, 0x4F31520747423F80ULL, 
            0x23DFAB60D175BE27ULL, 0xB3D7552AF94122A6ULL, 0xF2DECC2B173CDA30ULL, 0x2D417B238848BEA2ULL, 
            0xC149F660CF1B06E9ULL, 0xFE2622B9B73BF96DULL, 0x4D1A61A7482CA078ULL, 0x0847AF8167B58F85ULL, 
            0x8B21362E618B9B7DULL, 0xCFDD97051CA57F62ULL, 0x4813ADCC30019E66ULL, 0x054E2B9D23E258BFULL, 
            0x660291A48EBC2DB5ULL, 0xB13523BD4F11BF3AULL, 0x8489FABB0DB4641CULL, 0xC393CA27878D06B3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseFConstants = {
    0x53A235AE141EB0F6ULL,
    0xC53FD10A1F92AC09ULL,
    0x356867CCFB7A4217ULL,
    0x53A235AE141EB0F6ULL,
    0xC53FD10A1F92AC09ULL,
    0x356867CCFB7A4217ULL,
    0xA11AFC2BD7756C74ULL,
    0x45A5A81C3C493B7EULL,
    0x79,
    0xA1,
    0x04,
    0x7E,
    0x08,
    0xAA,
    0xD5,
    0x30
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseGSalts = {
    {
        {
            0x3E294A1BA8C36986ULL, 0xBBE793F8C728D675ULL, 0xDE3CFBEF1D7F9DBEULL, 0x280EF83757453E1CULL, 
            0x253F7144F16D3272ULL, 0x322AA7B89E92F54CULL, 0x6D2683E04C24EB77ULL, 0x2B66C34B4A0AB7E2ULL, 
            0x94E58EF658A3359DULL, 0x03320FF1A8E77442ULL, 0xB78BE377B957DF76ULL, 0xA36B04622877F22EULL, 
            0x62A23E806197398BULL, 0x0A7E720EF75B2C3BULL, 0xDCFE23C5C0CE27AFULL, 0x1E063E0B012E77DAULL, 
            0x1E8C62C5AEF1F5AEULL, 0x71AF40E317453C39ULL, 0x5EA12D24A8D71ADCULL, 0x341C689AB050A303ULL, 
            0xEDC2DB25BEE0D428ULL, 0x474F8B9AB0EC91BDULL, 0xF81B89E4079208A9ULL, 0x123BBAB339776FFCULL, 
            0x366153814EBA24D3ULL, 0x28B7417BCBAEBA14ULL, 0xA1C8CC7F767F962FULL, 0x49073BCD3C5205FCULL, 
            0x7F8FB6E1940415B8ULL, 0x3CEE1D106B51EFB6ULL, 0x6BD4162CC6034B48ULL, 0x940BF43D056A93C7ULL
        },
        {
            0xD0F9B3E492EA51EBULL, 0x0B86FD4697E92376ULL, 0x7B08FACC8E4E1DE6ULL, 0x42605483DB5AD6E1ULL, 
            0xD297E443A6988EA1ULL, 0xBFFC4FCCE94E8C32ULL, 0x2BFABF654ACD1FAFULL, 0xF93F7B3C8876FB0AULL, 
            0xE3B8E6604A484D5EULL, 0xA4BD69B46D2D7482ULL, 0xFE11367844D8CC0AULL, 0xE9FCE5EB51635826ULL, 
            0x1F2C8399BFE3568CULL, 0x9E1A5E73EA83B138ULL, 0xDDE00AF327D524EBULL, 0x719161D928A216D6ULL, 
            0x54425A683B20C4C9ULL, 0x0A6AB7113C55915AULL, 0x3B6CC7ADFB146427ULL, 0x3A9A4DC824C6E88BULL, 
            0xEF988AC687B9BE30ULL, 0x8B679727E32AC1ABULL, 0x33722AD3EC7E7D4EULL, 0x093E80F0EFEA3E72ULL, 
            0x76D7131BEB983B32ULL, 0xE4DCAAD2DE39C227ULL, 0x015536E29A5F8486ULL, 0xD08C18A6746C6B4CULL, 
            0x905E1AEA1BB37C8CULL, 0xD175D96D051E558DULL, 0xDB59DDF3CD5A83C7ULL, 0x20A38CFED242F40CULL
        },
        {
            0x6744481C0F664828ULL, 0x22CE8FD12F439DEBULL, 0x0038B5274B99D843ULL, 0xCC86A0BD4A712D90ULL, 
            0xC98A66E2B35F5A95ULL, 0x0B88DCBE5AA3C402ULL, 0x9648538B550542A7ULL, 0xB61E0F4AFE5680FEULL, 
            0xDBC0BFF123039912ULL, 0x95643B0C383347B5ULL, 0xECCE2D7386866D25ULL, 0xBFA73B2BC0073E2DULL, 
            0xA867E69FCF064647ULL, 0xC5F2AA9D473C462EULL, 0x0DE335B9091942E9ULL, 0x81DCC55F1E900321ULL, 
            0xA71DA399FCC5763FULL, 0xDA3F189423323A1BULL, 0xFB63A9AE2196960AULL, 0xA541EF67934844DBULL, 
            0xC6300D5795D41272ULL, 0xC349ACBD19B76A68ULL, 0x3DEAFF9D88E491C1ULL, 0xA9CDF5D7996F42F6ULL, 
            0x615D4A80F11F0313ULL, 0x68244BFEC1A193C7ULL, 0x493704B34374883FULL, 0x3E0B5DF45613D2E4ULL, 
            0x9A560BA939BD9CBDULL, 0xF610605628B4BC76ULL, 0x1AFF9ADA04F7AF51ULL, 0x8F1E0A9CBE0EB495ULL
        },
        {
            0x8DBA9A90CD6CA368ULL, 0xD48536C3376309C6ULL, 0xEB813DD130865767ULL, 0x2DD189E8CF91260FULL, 
            0x863F2D909FFB2A0BULL, 0x78429DFDD77680B8ULL, 0xC64C6F1E97EC4985ULL, 0xB40F69E7BF1475B0ULL, 
            0x55A37CE4B8232388ULL, 0xFF0E18B334B4D4E8ULL, 0xCFFBED8B057C17CBULL, 0x000FA16AB075A2E1ULL, 
            0xA1109F4F7EBBA331ULL, 0x6EB6A331D4CC048AULL, 0xC919FFBB7EA7C7B8ULL, 0xA5EFB62DC5C9A311ULL, 
            0xDC34CBF088C1EEAAULL, 0x4192E2F5C98110FFULL, 0x85451CF3F9E58338ULL, 0x420EE52D5D259B98ULL, 
            0xE018F929C1DF9E15ULL, 0xF82D1B8E836A32ABULL, 0x86C6C784298CC0E1ULL, 0xF25DCE4EFDBF2710ULL, 
            0xE1031B033D0B42F7ULL, 0xACF14D3DDCDBC555ULL, 0xFF1172F3C51B8A50ULL, 0xDF750E3574356254ULL, 
            0x5982B74DB9507B54ULL, 0x9CA9D1283BDE3371ULL, 0x56D020AE9CD4CC37ULL, 0x8ECCC58FD2119E15ULL
        },
        {
            0x271C77E1CB3A8D94ULL, 0x18DF12AB2CEAB6B8ULL, 0xCE1C65DA0F338FA7ULL, 0x018FD173402CA20FULL, 
            0x37827243EE529FA2ULL, 0x1EC4B4B61A0E4C86ULL, 0x858A2785281C238EULL, 0x5EA7D8CBBA468F46ULL, 
            0x4B31D25A09365D42ULL, 0x428304ACE6FB399CULL, 0xFBE592362E07FA23ULL, 0x25782CE5E4A50753ULL, 
            0x6E23503616792146ULL, 0x56CA5CCDF64246D9ULL, 0x1DD6E33B6081BB77ULL, 0xEC05C705EE1CBFC4ULL, 
            0x1044C53997CB607AULL, 0x1FDFAF5602AE45BDULL, 0xAFA6C4C3784159BCULL, 0xCB7B6BCD77585F16ULL, 
            0x9844FBCBF77C8874ULL, 0x9599E14FD2CFC7FFULL, 0x7FA3713445E97392ULL, 0x04C884E9AB1F38B2ULL, 
            0x94B9AAE9B70CF3CDULL, 0x71617D8B3A618920ULL, 0x547029035DEC0FA6ULL, 0x00717ED8D6779670ULL, 
            0x557E42A58FBF9811ULL, 0xF5C3A20BC6D89AB6ULL, 0x00CD712C30D3294AULL, 0x781E03BB02FFC205ULL
        },
        {
            0x6D18C155F81CC9D4ULL, 0xE95CD221CE3BB545ULL, 0x0F5DFA9326642699ULL, 0x905928638C2CD26EULL, 
            0x9ED3EDAD42BB94AFULL, 0xB95529BD64ACF555ULL, 0xE458C52AFEE15805ULL, 0x1AC968D91252FCBEULL, 
            0xCADEBBEBD7EDB74DULL, 0x43E01BF2ADF526C7ULL, 0x85156BC8284DE02FULL, 0x33E97868DCF0C4FAULL, 
            0xC170860549CD5FF4ULL, 0x69C9853D301B4731ULL, 0x3731CFD5B9FEA270ULL, 0x377070EA2F784875ULL, 
            0x7E4A07824D2A5359ULL, 0x30874939F197CEADULL, 0x8D1F0FF9F90FAF99ULL, 0xBB32840830178F17ULL, 
            0x34D97592B2634285ULL, 0x9369843FD3381A7BULL, 0x9788BDD6A2E03F81ULL, 0x3CB1D8000C64E6CFULL, 
            0xC560ACEA7C54A5B7ULL, 0xC5683BBAF607B439ULL, 0xDDA7000BD4856D21ULL, 0xA8E43E60FD0FAB3AULL, 
            0xE5B7ED02BE4FA1E4ULL, 0x1985220C6D32635CULL, 0xC29A5950788BFC0CULL, 0xE0B707010E19B68FULL
        }
    },
    {
        {
            0x2BED4161D67D7624ULL, 0xB5562EF9BE720560ULL, 0x4644B24D842E3A33ULL, 0xB3E9927D295120D0ULL, 
            0xD87E7342AED822C4ULL, 0xC2B9865FFD2D57B6ULL, 0x68800FFB8DF2EBBCULL, 0xA3BD476CF12939E4ULL, 
            0x820814937857A108ULL, 0x7AB4F69366E1DFF6ULL, 0x7B7BF66ECB50CEBBULL, 0xF1C10A64B13BAC5DULL, 
            0x35EA6A11A21168FAULL, 0xEC2A1777269FB6B6ULL, 0x8EE21B7B22D50CCDULL, 0x3C2676096CB110E8ULL, 
            0x37365EF3CECDD22FULL, 0xA16EAB1E5F58D433ULL, 0x131829780D65E5FEULL, 0x3262D0D42D54DB43ULL, 
            0x007F37AD7BB79185ULL, 0x70949E6355799B48ULL, 0x88E2CED8BE790A55ULL, 0xE5C528D3C1F6C790ULL, 
            0x228090E4277C1DF8ULL, 0xAB058DCE6BDB733BULL, 0xDEE442508C426657ULL, 0xD43B2B608DB1BF3AULL, 
            0xD00F5537DB7710EFULL, 0xBC0AAC537F0FD9D1ULL, 0x1775A78C00083F46ULL, 0xFE369F894505AFCDULL
        },
        {
            0x053FC4AF6E2C694CULL, 0xB252A54F6F6419ECULL, 0x70184B5CDDCEE79DULL, 0xB42C9710951E1CFCULL, 
            0x8FA21589F212CA3FULL, 0xA87D74101D495C28ULL, 0xD4B32E1DC46C7EA9ULL, 0xFBC92801FB4C0FE9ULL, 
            0x8A906902084165C1ULL, 0x89A97894E8C3F437ULL, 0xD60971279942FF67ULL, 0xDC5E0FBBC1B96D14ULL, 
            0xFC0AC7233C94E49AULL, 0x475B17BA5353F7DDULL, 0xFEAC31385E0A297EULL, 0x7D6A5AB258BBFAD0ULL, 
            0x84A48E8E065A261FULL, 0xCDCDC43A510000ECULL, 0x5F85BC1FED9FA28AULL, 0x2AC75DD8F2451C5FULL, 
            0x56DE9EBC72119B4CULL, 0x69004E0EA3410ACDULL, 0x2B9FBA22CD427D3FULL, 0x15775E9B177311E3ULL, 
            0x850CEE6D4B89687CULL, 0xDCAAC57DFAC538A0ULL, 0x9E2EB751B66E43BBULL, 0xE849DC104A56A75AULL, 
            0x3595EEAA2E5318B8ULL, 0xDE5BBA0DC28D91D8ULL, 0xBFEE584FFD32E7DCULL, 0x6646F90E2128F80DULL
        },
        {
            0xC8738E3A464BDC0FULL, 0x9A44A062D6ADC0EFULL, 0x242EF4635BF2499EULL, 0xBB894E7EBD8A405FULL, 
            0x14DB16167C186EC4ULL, 0x08C768BC031AB3A3ULL, 0x86B5759B481874FAULL, 0x327AA2511A80C41CULL, 
            0x23DB082FC1AB562DULL, 0x59676AD202C8B98FULL, 0x7592BE4DEDA61AE2ULL, 0x10D7C1C9D6709D9CULL, 
            0x49540A0776EE3158ULL, 0xA27A7E9CCBB263B7ULL, 0x77AA32ABCCC9D575ULL, 0xEF11B679CE6A45F3ULL, 
            0xADB00700A3730105ULL, 0x02C1725AC35B74ABULL, 0x1FBBC41E333396B9ULL, 0x250409010252B311ULL, 
            0x9CFAC965D056BD60ULL, 0xC56FAD221033EEDAULL, 0x2D090EC956D35B8AULL, 0xCEF51070266D7903ULL, 
            0xF785E7001CBB35C1ULL, 0x7C006EC4933FDB8BULL, 0xFD5242D9C1132B7CULL, 0x98046CFCC71B76D7ULL, 
            0x1683A8EF021CCE95ULL, 0xA3562D40EF9AB5A7ULL, 0xEEC4BC9299C5D612ULL, 0xD119F35B104B97FEULL
        },
        {
            0xD6B67E50827CA8DCULL, 0xB966CF3F408BF5A7ULL, 0xE477EDD66756CD9CULL, 0xFBE0A06A7F2C5C8CULL, 
            0xFFE2233152B7A6F1ULL, 0x21970609888C5A8FULL, 0xE5F374E3166B1BACULL, 0xC5BA98A949A6FBA2ULL, 
            0xA5E72DE6E12DA7E8ULL, 0x627D7F822C987EEEULL, 0x4780757136A1E8BDULL, 0xC674B146C2275576ULL, 
            0x78730AB7EFAB355BULL, 0xBFCFF96818ABD6ABULL, 0x4D37579DE8C91B86ULL, 0xE15B23262FE834FEULL, 
            0x3763ADC2972D032AULL, 0x3F76C5F4570F6917ULL, 0xBCE53372375C86E4ULL, 0x93089A93A47E31C6ULL, 
            0x6074F6BFF6C30C1DULL, 0xD066EAA15548CA7EULL, 0xDA4F50B2DC807278ULL, 0xB9DD2BD38C0A1B90ULL, 
            0x9A40F6790A6CB525ULL, 0xCAED8399A1FB2520ULL, 0xF545ABBCF7CD2B58ULL, 0xC6D715C0F7ED7CBDULL, 
            0x5E9972E2212F42B1ULL, 0xBE4D6E84B44E8239ULL, 0x0D4673977FE25E8EULL, 0x262E6AD1820E3773ULL
        },
        {
            0xD711068DE7E68417ULL, 0xD46F968F611ABCA7ULL, 0x3DB3DBC2D1FE55A3ULL, 0x812917F6797BFDBDULL, 
            0xE0E5A3EEFFBCB289ULL, 0x53F97B77D0B4CBB5ULL, 0x78B5A98110B4B48AULL, 0x38A44525EF803E23ULL, 
            0xF47BD0D89654C17FULL, 0x1F460F7B8E181AEEULL, 0xEE4FD116577DDB34ULL, 0xAEEE39C25096FA6EULL, 
            0xE22E4743537EFA9FULL, 0x1BE3C9B866DE9CACULL, 0xE41CBD0BFC78FC41ULL, 0x69A60BAF075299A9ULL, 
            0x0686300D21E9413BULL, 0x15F9F108F247A7D6ULL, 0xE7456D3A9D4DC4F2ULL, 0x03222415400EE8C8ULL, 
            0x2DED405510B39F29ULL, 0x7E6FF8DBEB1897F3ULL, 0x6C5E4896B49F25C8ULL, 0x4B97039EE7671FEFULL, 
            0x7C8FE78709695E4EULL, 0x44DAC65355905534ULL, 0xA1D4CAE902BE326DULL, 0x923ABB18CE8C5F67ULL, 
            0x9FDAE84EB68C3469ULL, 0x6390EAF2BBCA2090ULL, 0x80806AB30C7F35A6ULL, 0x65AB4F0203DE3EEDULL
        },
        {
            0x8CDEC99A7B427CBDULL, 0xA8AB37051B48B392ULL, 0x7706CEC65EA21995ULL, 0xE93E1D209C809706ULL, 
            0x9DF8763DAF576D90ULL, 0x8FDCF2989D871255ULL, 0x81DA789BC2788499ULL, 0x6C3D4B27FB91EAD6ULL, 
            0x06F84C2CE3D74EF5ULL, 0x333BC040A9179DEBULL, 0x14C254F91B378307ULL, 0x1BB1E3B55E2777DEULL, 
            0xDF44F505A8A07538ULL, 0x8856D588510F409EULL, 0x62F8EE2EB60CFE0AULL, 0x846666C7EA11C495ULL, 
            0xC2D855908AB11F29ULL, 0x7CF32326FFBE340BULL, 0x6AC10850A7D6E5B1ULL, 0x0F35AA8C5C741D72ULL, 
            0x096C541ACA21FF50ULL, 0x3744CBE0144A6C55ULL, 0x7090F6EC7FB004CBULL, 0x92ACEC26EE8589FFULL, 
            0xD77C26DD36C19326ULL, 0xA5F7328146FACE74ULL, 0x38B7C31577B2603FULL, 0x62593EBECD33C1D9ULL, 
            0xA837FAAE7E8F5B42ULL, 0x2A8E5CE0B94EE971ULL, 0x9B323CDF838B29D9ULL, 0x2083581BE1B0F0C0ULL
        }
    },
    {
        {
            0xAACD6CC10FF2AE0FULL, 0x14D0B080683D12EAULL, 0xF98ADCD2A68FF1CFULL, 0xC02EC5D4D7890923ULL, 
            0x25C2AA47E33711DDULL, 0x904D044F19CE67ECULL, 0x40A8186DCB5095E4ULL, 0x7E9D69B0016B23EBULL, 
            0xC6A5AB9DC315010AULL, 0x8789DBB07BF3F55EULL, 0xB697EB10F5CFFCFBULL, 0x08E629DA391C4A86ULL, 
            0x3D6FB2FEC4A2342EULL, 0xFAA99B654E7B341DULL, 0x49E84736061F2B4FULL, 0xDAAEFB7E5B3991DCULL, 
            0x73938CE90B798014ULL, 0xC6B2D0B4B974B9DEULL, 0x551BF26FE08B5738ULL, 0x14B7F6165CB707BBULL, 
            0xF0983B66C29988F8ULL, 0x85A80CF3ED6B1386ULL, 0xF6031FC06E9B3EC2ULL, 0x0995FC00F9D30CF8ULL, 
            0x202C35F4B00605E2ULL, 0xAA12D4A4CA11CCDBULL, 0xF4C4CA7CFAB5D425ULL, 0xE2E532F32EC5366BULL, 
            0x55DC007F1C6434AFULL, 0xBCA9003586EAF116ULL, 0x904B849EE5F47FACULL, 0x5A8407076A59AC4DULL
        },
        {
            0xD6813F72B057D9FFULL, 0x83D0B3644170CF0FULL, 0x586140CE7CF23ECDULL, 0x5A8A9F6E37711AC4ULL, 
            0x4340E5A6DE9D0A86ULL, 0xD3AFD35FF8377BBCULL, 0x4C6792815BC7CD64ULL, 0x8D7E5A528BDA9BCEULL, 
            0x81672E5840FE12FFULL, 0xFA85A9C8D7A32BFBULL, 0xEB25D489EA4999ADULL, 0xC4BA1F3CA2A7A86FULL, 
            0xCD37B8E94637206EULL, 0x5EB8A1531C20264AULL, 0xA7350AE2BECAA675ULL, 0xA6D95FFA516F68F2ULL, 
            0x5B16964A93926F2DULL, 0xFC486A83DE1676C3ULL, 0x03FEB9B1C6DE02BDULL, 0xBD156C0D1AD7D6B8ULL, 
            0x9DAA0845B047CAD2ULL, 0x7C0207EBE07453F0ULL, 0x6E30B10EC83C58D5ULL, 0xC4FFBC516583627DULL, 
            0x80C17C95147F1443ULL, 0xC0ECF400D9AF17A5ULL, 0x3F6101E61FF10F7FULL, 0xA9BE940E7073CE06ULL, 
            0x3F9E0A0F940D73F3ULL, 0x3537FF966A9831C3ULL, 0x9D57F43AD80816D4ULL, 0x2F6229A1EC8E243BULL
        },
        {
            0x6B0869E08A683FC6ULL, 0xB8094678397A70F9ULL, 0x5A6401A8E475F4E1ULL, 0x2BB2EC401C41ACD8ULL, 
            0xA1E6CF10EB55ADA5ULL, 0xA0B056062A45EC8FULL, 0xB6620DD1FC5AF65FULL, 0x3C7AA97392C7C0E3ULL, 
            0x49F4EFED1E140C3CULL, 0xB46E52B8F233E1E1ULL, 0xEAE0112D2E988CC3ULL, 0x61DFBB700078F69DULL, 
            0xF94C239C5278A3F4ULL, 0xB7273B2E8AE0838CULL, 0xE0EA217C20A8E43DULL, 0x762C0DBC42298268ULL, 
            0x4DDF8D59EAD24774ULL, 0x157D74517F480659ULL, 0xF2EA0AF27EFB789DULL, 0x33BD22429B3194D9ULL, 
            0x355F8207A69966C3ULL, 0x65494AD212842F87ULL, 0x587E68548103FD57ULL, 0xB69F7AB68A0331C0ULL, 
            0xC0E49588E28D1F8FULL, 0xE56D2555CFA2531CULL, 0x027AD3B5C5CF8088ULL, 0x8E325052B52314BCULL, 
            0x21FF8437DDEE5D63ULL, 0x351E442482FC0DDDULL, 0x303DE92EBB25D798ULL, 0x059DAEC2CD3453A4ULL
        },
        {
            0x7C3E8B43C1E76EF6ULL, 0x82ADD9B7DC52B23DULL, 0x3B83E5B6F83E943AULL, 0x128E4755462204D8ULL, 
            0x65CE626CCD9B4952ULL, 0xAF62BFFA4A2522DEULL, 0x0CC0E6445E7AC19FULL, 0x4770FBB90B0D2C83ULL, 
            0x4B38CDE482676DEFULL, 0xDC2B7E4025839A6EULL, 0x20833343078B3CD4ULL, 0x511E6B8493E5CFB0ULL, 
            0x668EAF80A31DDFA0ULL, 0xB22DDCEB04827C71ULL, 0xF1234D1DF9C74380ULL, 0xB6936DDD044E56C6ULL, 
            0xA613DEDADC9F3285ULL, 0x526A063D23997254ULL, 0x1D5E7EF317E3B95FULL, 0x39671CEC68C763A3ULL, 
            0x3E9B9F82B0CB1A0CULL, 0x08673FE05477C51DULL, 0xD3383603461F7B56ULL, 0xA48ECFDB95A009B3ULL, 
            0xE1E6B352A48B903AULL, 0xD97E060C1B578480ULL, 0xB64F6585B5149D6CULL, 0x1E5105C93B1F0242ULL, 
            0x6474D043557F1D45ULL, 0x1F4A4A41C43A238CULL, 0x332BB9AA53A720A5ULL, 0xE47E9CE076537D55ULL
        },
        {
            0x28F7FD914D9C9B6DULL, 0x3DE486D6990A3EE9ULL, 0x8020B7C82165667BULL, 0xC8DDB042A65718BAULL, 
            0xFDD5D8918AEF237DULL, 0x91D9E6794837EBF2ULL, 0x87921E3F43C369C0ULL, 0x2655EFF68715FD25ULL, 
            0xC5B01A61E960B4EDULL, 0xBDAA394DA1F09B4BULL, 0xF6ED91B560D23D2AULL, 0xDA0D6B0EB5179326ULL, 
            0xBC9880CD4F6B7FE0ULL, 0xA334DEA09A349A7DULL, 0x4D5352AD038CDAB1ULL, 0xEF539EBE455CD69EULL, 
            0x6B938C9AF3495840ULL, 0x4CC9CAA73FC2443DULL, 0x4B0E66F2DEF4C8E0ULL, 0x8191C07653F13640ULL, 
            0x437502629EB8A8DBULL, 0x50660A827F038D78ULL, 0x690BCA6DED8BB6CBULL, 0x642B500AD72CDD26ULL, 
            0xC034C11ACD1D7CD0ULL, 0x9DDBA0C4748455ADULL, 0xAE412AE27CA6161CULL, 0x48E352FCE426A724ULL, 
            0xB01FD1A6F16E3B39ULL, 0xE1D3C0B6A310365DULL, 0x910EFA05195CA84BULL, 0xDEAB842097A19663ULL
        },
        {
            0x1EDDCFE9D17058F2ULL, 0xA19CBF35E525F79CULL, 0x797F02AF618986B6ULL, 0xE58C510B56EE4EF6ULL, 
            0xFBCD3B347D3E2471ULL, 0x662D93F85139F709ULL, 0xFD9FC5F015641507ULL, 0x2C476FB9B9F3464AULL, 
            0x03CA5A8BA039B42CULL, 0xFE66B9C2F98989B0ULL, 0x2038B3B65F38EAA6ULL, 0xC0D559B96D8E9040ULL, 
            0x39FAF17F016A6D91ULL, 0xCDC1DBD0762A0AEFULL, 0xADBE429D5785CF08ULL, 0x03B822F9E06617D3ULL, 
            0x14F10233C9CC6C6CULL, 0x0BE322DFFD2AE81DULL, 0xEDE1DA7A73B08A2BULL, 0xBF815EAFD958D5EBULL, 
            0x4520E790722939A5ULL, 0xA35E13737353D5CEULL, 0xE28B4F34D38F397EULL, 0x693F94E212597E35ULL, 
            0x5168D81066DA27C4ULL, 0x6EAC4F32FE69E7ADULL, 0x6F09E081B625DDE9ULL, 0x782EC13F22EB5A23ULL, 
            0x37F1E9E92EBFB292ULL, 0x895B46FB70B659B9ULL, 0xA7C32240684D6583ULL, 0xAE99E05B0EEDA632ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseGConstants = {
    0x8956BD9F6AC50A84ULL,
    0xC357ECBA55FCC440ULL,
    0xF6F6C2D4085B50F5ULL,
    0x8956BD9F6AC50A84ULL,
    0xC357ECBA55FCC440ULL,
    0xF6F6C2D4085B50F5ULL,
    0x27CD4E02AF588D6CULL,
    0x3139E7E327C87F3DULL,
    0xA9,
    0xA5,
    0xBA,
    0xE3,
    0xBA,
    0x9B,
    0xEB,
    0xC3
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseHSalts = {
    {
        {
            0x066B987E5DA04704ULL, 0xA1BEAC3283EE7D98ULL, 0x03F1CB92B126D6E7ULL, 0xC4F36F5F2F885D95ULL, 
            0xB90AAB8D3CD30F71ULL, 0xD4B2ADADC7BDCB0DULL, 0xACF868D277773532ULL, 0x91462CF3EEB92405ULL, 
            0x881213DE6D737299ULL, 0xA22FB8A599D565CDULL, 0x493406B42B344595ULL, 0x33043C8E445EAC3CULL, 
            0xFD09152C34BB3687ULL, 0x61709BC2A8642AF7ULL, 0xE37BFCD3384FBE9DULL, 0xCD5D5297B88F6BD8ULL, 
            0x1EB9597AFF8D7F28ULL, 0x19AFFD65A3C320D4ULL, 0x4CDFB1C648B67EEFULL, 0xD8FCC26D966C0ECFULL, 
            0xA89369DC10FC39EBULL, 0x2EAD39CE1CB311A7ULL, 0x3B12A5D89ADD9095ULL, 0x8B19461775FA1E90ULL, 
            0x399BF51B8839D90DULL, 0x5090C44AF5C479D5ULL, 0xB6707E26E5355D26ULL, 0x76D67D7D2C271D0BULL, 
            0x7E774D6A7B5BDBA6ULL, 0x7D01366E68C0BA64ULL, 0xFA1420DE0F100C80ULL, 0xF6C0D629C6CC5F87ULL
        },
        {
            0x2A254828A3E8379AULL, 0x00C51EB3F31AAC58ULL, 0xA97C24BA095BEE6BULL, 0x5C2013B9B4308152ULL, 
            0x965F47C78713D4B0ULL, 0x1B97632383AC59EBULL, 0xDADE0DDBFB194600ULL, 0xA8CEA1E6E43C49A1ULL, 
            0x61577D3FC7044CC3ULL, 0xE31DEC9992861E37ULL, 0xA4600339B403A963ULL, 0xC4F25D66CC9B6539ULL, 
            0x324A586577CA9474ULL, 0xD6F7AF58DA47974FULL, 0xF50AEE67735292A8ULL, 0xB50D9FE2AEB69773ULL, 
            0x124393AAE75675FBULL, 0xC835640CBFDB6C17ULL, 0x726FD08F004BBD26ULL, 0x9AB836EACD3B6A57ULL, 
            0x4BE1CACFDE87AAAFULL, 0x765FB94E1955AA01ULL, 0xEFF4E5D396378D35ULL, 0x28B25C3535CC9784ULL, 
            0x2FDF2A31A65C806DULL, 0xBDAAF278F66927FFULL, 0x3F6AA4F6D1373BCBULL, 0x362BB8281A953B82ULL, 
            0xC197C1BA29E36930ULL, 0x81055CA14B51252BULL, 0xDD0BC89DCFE6B878ULL, 0x06DD02B751A8909AULL
        },
        {
            0xE9D206F502F273C1ULL, 0x574F8DD46A97B11CULL, 0xA5D82CEF3C54298EULL, 0x7A7EE84952D38880ULL, 
            0x777128F81A41815FULL, 0xCD6DDB3AD7078977ULL, 0x8619C7EE68E2A691ULL, 0xBDB4DBC1E098852BULL, 
            0x8CC012C3AAAFD692ULL, 0x79BB35A15489FC47ULL, 0x2767489A3E4827E2ULL, 0xF93C453BB69AE899ULL, 
            0x5D3926DBBD01569FULL, 0x957BA13923D08B37ULL, 0x2D288F8EDB7D68D8ULL, 0x0D88BC89D1DEDC02ULL, 
            0xFAA8105BFD769697ULL, 0x6026C4496A9034A2ULL, 0x1C41B87B3BBBDFD7ULL, 0x3B27837B96F62D20ULL, 
            0x2BC841E280683D3CULL, 0x20C0094A324A03C8ULL, 0x9067D3522177E4AFULL, 0x1E86BB9E0185DAB1ULL, 
            0x174D81543CBD779FULL, 0x86F550F1183FFA6BULL, 0x05D06F9CA1D863B1ULL, 0xE2DD955805CF828BULL, 
            0xFC624D1D78448CC4ULL, 0x0ADDD0F917760791ULL, 0x043713D171E981BEULL, 0xDA6FF31E555B4A0AULL
        },
        {
            0x6CA5CBDD650655EDULL, 0x423FB444BD7B7AB7ULL, 0x4CB77FF274EFD0B1ULL, 0xE619A58EC7D0FAAEULL, 
            0x9F15EAAEECC6BC22ULL, 0x8C7EDAA461E9C81CULL, 0x08CD580D5A823B39ULL, 0x985BC33E44F92D8FULL, 
            0x54D98DF349F28CEBULL, 0x1B79B77E04835D17ULL, 0xE03D0F239F5BCC43ULL, 0xC2FA9612BBA51B25ULL, 
            0xEC1175FF4CD1B142ULL, 0x04CBB731DA65F116ULL, 0xF54F2B9F59E5308BULL, 0xE77F97B925666E9DULL, 
            0x5CD38C42C0F4F3CFULL, 0xC4AE18BC3D67DE64ULL, 0x091C012BC6DBF4B8ULL, 0x48F88313D5CCC3FAULL, 
            0xACF0523E8E6B248EULL, 0xE4DACFB3C4876F0EULL, 0x5E8A8EE02F0E3603ULL, 0x9FDD5B924FBDDE0EULL, 
            0x06DC834A37D2843BULL, 0xDF082F695391DB69ULL, 0xCBD09A7AF92AA986ULL, 0x77A3B09B53D7728EULL, 
            0x22D3DED5F3DF5800ULL, 0x423EC3A4340565B3ULL, 0x4230B49CDC47F9F1ULL, 0x0E4835EEACF144BBULL
        },
        {
            0xCA74DB45A2955E36ULL, 0x3158198C7A6D4642ULL, 0x44C6B08B6384221DULL, 0xD7C6F77C9AD70D89ULL, 
            0xB187EF128C226741ULL, 0xB569572A788E9697ULL, 0x8B2E24EC58C98240ULL, 0xAE9DA7D17FECCB8AULL, 
            0x38D3CBC1EDDBA14AULL, 0xEA30FEB1E26875D9ULL, 0x812D041CB33B95E6ULL, 0x6D9ACA7EFBF68A51ULL, 
            0xA041D4683B07D05AULL, 0xF2CFD268C8F45AAAULL, 0xD1F111A65BB12BB8ULL, 0xC30040E1D862137AULL, 
            0x1D44F7DA21C3D756ULL, 0x1A87A19123E7C7D2ULL, 0x5176B78FB724EAB5ULL, 0x817A9384E20CB956ULL, 
            0x5A88E61A89FAEB23ULL, 0x390DD2CF61CA76F1ULL, 0xE5F8B04EC28BFF6BULL, 0x4F6D2146376FF01EULL, 
            0xD9535DD93348F4A5ULL, 0xC63D8D840ED0B996ULL, 0x11BB0D3CE5193AB0ULL, 0x18CFDF39B0E755D7ULL, 
            0x3E181C411A43CE11ULL, 0xC40FD4B6A6650104ULL, 0xAB1F036C3906863AULL, 0x400D23F5EEF52717ULL
        },
        {
            0x91A9F4C0E12E89F5ULL, 0x963AA088A1B9F1E1ULL, 0x0FD65D3111F566A4ULL, 0xFC02D1674335AC22ULL, 
            0x82C1744104AE7BFDULL, 0x24DE9D1AA6EBB630ULL, 0x751F30E0D84D292DULL, 0xAA19D5C824D2645DULL, 
            0x8857CD9FF84DDCF7ULL, 0x0388BC8D343D823CULL, 0x7274651B96164EE6ULL, 0xD423D85B853A3BF6ULL, 
            0x2F70A2AD7E2EDC83ULL, 0xB390B3CC464138DDULL, 0xDF24A87A93D1B748ULL, 0x7735109D16EFED42ULL, 
            0x1ABC779D33D8BE4EULL, 0x7E1D2DFAB0F5F058ULL, 0x62BF28412BF0B4BFULL, 0xE6F9424113654A17ULL, 
            0xD5D94C5ECE6A6B58ULL, 0x3058FE9E3A6271AAULL, 0x880AC900890A4669ULL, 0xE5E6C2BCAE7599B6ULL, 
            0xB38ED3B78C005C08ULL, 0x29A0F6A5606B7756ULL, 0x417810369F51F748ULL, 0x138F8E5EEEA16DACULL, 
            0x9CFEB04C2DEA7D4DULL, 0x0DEE648318ADFEEEULL, 0x330E43F1FEF30401ULL, 0x5DBE2FC98E426551ULL
        }
    },
    {
        {
            0x1E0FE173966EAAA0ULL, 0xBAB13AC93C3B4F39ULL, 0xEE2100F99C5CD6C6ULL, 0x768FDCBA11C2AFC8ULL, 
            0x36C2912F50C57E5BULL, 0x9CD35615C20DE6A5ULL, 0x7E017D9232B27209ULL, 0x8B87900EBA87B7E2ULL, 
            0xDFBA1E188A6B0699ULL, 0x01C06917BE05807CULL, 0xA70E44A8925D21E4ULL, 0x2F5367E3CB408752ULL, 
            0xCE867A194626A6D1ULL, 0xB13F65D1FD8A25DDULL, 0xBD0E19C1E0C92107ULL, 0x4AA6165E491AE58DULL, 
            0xD8A304C175F9F91DULL, 0x40E059F038D60778ULL, 0x028F5DC5CC500FBCULL, 0x7A3035C2337756C6ULL, 
            0x96C2948118988E7EULL, 0xEFA0DFA9CDDFDE3EULL, 0xCD2FB80C50EAA860ULL, 0x24C1DA81D6C463F9ULL, 
            0x6DDC6871CE27D8EDULL, 0x1E62252C3E74111AULL, 0xF788AB2FDF46F69AULL, 0x6B0FE92C215A9AF4ULL, 
            0xB64999D5808A64FFULL, 0xD389A62E7724BD36ULL, 0xB4A2FC333E09BFECULL, 0xCCBB9FF94F1A9517ULL
        },
        {
            0xD06EE46F72E1F148ULL, 0xE0F79EC4E974F3CFULL, 0xE4606441B49C4B49ULL, 0x608C14AC9A1DC7CFULL, 
            0xFEEA708F384363D7ULL, 0x6A7614D56C7A6F2DULL, 0xEF1BD3A6BC24CDF9ULL, 0x2ACC39F4A85D2896ULL, 
            0xC2F6330A03CA9D3DULL, 0xFC5E86E60ABBE000ULL, 0xD6B44363808962A2ULL, 0xF070AF30E23004FFULL, 
            0x7A64CB6C2BFE53E2ULL, 0xE5D23F60D2C52D0CULL, 0x2D12C7B0F0B77769ULL, 0xAD711B8EE72A257EULL, 
            0xACF82D69D3FE5CF1ULL, 0x9362B13464BECC7FULL, 0x547431AF916BCBBAULL, 0x331E39A8E049F077ULL, 
            0x285101221B1F6D93ULL, 0xFEB532705E8425A5ULL, 0x6EE6ED4D69F83871ULL, 0xADDDF374DC369550ULL, 
            0x84A9974E3D4ACBC0ULL, 0x25D8EF96793A6781ULL, 0x1A9EC76298D7FFF2ULL, 0x9FA6C53765D15016ULL, 
            0xFFD9A87E2F657555ULL, 0xC5D1D99077CCC2AFULL, 0x08D0587233AA2447ULL, 0x6B669DCDF36360BAULL
        },
        {
            0x9987E0D3283416EBULL, 0xA9503DE4CB0812B7ULL, 0x070AEE2F8FC17E12ULL, 0x97F2150CCC8F7832ULL, 
            0x3EE0DEC4145DD4B5ULL, 0x158BA409C4B1AFE3ULL, 0x75CBBC2CF41FD721ULL, 0xD57974CEA18525EDULL, 
            0x705EB4CB52EFE869ULL, 0x7CA194DA1FD390FFULL, 0x06BE5B121BB22700ULL, 0xD888C1352B5F0DE5ULL, 
            0x98F7D43844B33512ULL, 0xBAC6E5899E492A38ULL, 0xC4C80C674AB76538ULL, 0x717CFC28A8BEE7C6ULL, 
            0xB69FB747D0E1647AULL, 0xE22D7E8A5ED17591ULL, 0xE108CEE794F4B144ULL, 0xD9A3D51B776B065DULL, 
            0x2DDFF504D41AF8EBULL, 0xB614D948637A8130ULL, 0x0809603685EF376EULL, 0xE05D529EFFE8162BULL, 
            0x3DAFF52A6FB673D3ULL, 0xF7072BE168421EF7ULL, 0xEE61FD2E29323E24ULL, 0xB286234D32D75907ULL, 
            0xAB88477A03CE11CAULL, 0x93D5683BFACE922EULL, 0xD44165AD05483C37ULL, 0x0EFA9CE77E0A39DEULL
        },
        {
            0x8CB3180B47A84854ULL, 0xF8D265B64E5BD4DEULL, 0x7C3186DE25781974ULL, 0x8BE85F5D3FC88FECULL, 
            0xFAE765C6516DD8D9ULL, 0xC9EBEAF92E8F1EA3ULL, 0xC03C14CF78756B66ULL, 0xF4D59FC9FC9E6210ULL, 
            0x6588792EF9AF50ECULL, 0x324F747ED60DCBA8ULL, 0x990BCDE0D4C994C8ULL, 0x4B3800D4659A3DFFULL, 
            0x29E39F962985DBD0ULL, 0x3C49E1B4C943B799ULL, 0x86C6CB0FD2ECE28EULL, 0xBB9DADE23DAFAC36ULL, 
            0xFE0B9329CB4E69EEULL, 0x97D6BFCDECA576E7ULL, 0xC7B491DFB88DDE97ULL, 0x7601D708B70DC679ULL, 
            0xDEF897D19072F575ULL, 0xEAEC54D7C4095C96ULL, 0x73AE626FB590881DULL, 0xCD81D4D1F1F09A3AULL, 
            0xC40B6C85A3AF4B43ULL, 0xD10500EBADB89B36ULL, 0x8A73141004720544ULL, 0x7A1CA9DBCB4727EBULL, 
            0x9DE95850B72C55E7ULL, 0x10533A3496E4F4B5ULL, 0x75B5823A0FA5A999ULL, 0x96D1EA258E34B364ULL
        },
        {
            0x317D480B5CA54484ULL, 0x13BFA981F4AF0502ULL, 0xF6DF1D7CCE35BD8CULL, 0xF5AC139EAFB2048CULL, 
            0x6010582AE911A30EULL, 0xDFE5845114B3B90DULL, 0xDC0A16D1AC73B111ULL, 0x96CBFD80A94496C5ULL, 
            0x0E0BBA3DE7F32FBBULL, 0xDFE3AA6C9DD28163ULL, 0x84FAAAC38D127317ULL, 0x2A08DF10C7AC26FAULL, 
            0x51CCFEC52ECF4983ULL, 0xDEC79B2E4848CAC8ULL, 0x752613D2B4ED439DULL, 0xA3623A7BC9BB2D2AULL, 
            0x8C16FA7DE7C18690ULL, 0xC3CB348A52B2D1EFULL, 0x8C43ADE5FB010033ULL, 0x184812F24C5347D2ULL, 
            0x76A43F78B943C3CCULL, 0x87050D4C61CCC8A1ULL, 0xC407DC602A773366ULL, 0x1EE8E3B126A68468ULL, 
            0x32BF281BF74536EFULL, 0xC4774AC5F25969A0ULL, 0xE1491557E5BFF5F9ULL, 0x3A2CEBD007BDA746ULL, 
            0xD7EAC4A4023875EEULL, 0x46EF3383D3E1A99BULL, 0xBFC8B771902DD216ULL, 0xBDF19E593E0522BAULL
        },
        {
            0x0E121F0784B87EDAULL, 0xA0ABD18803724D12ULL, 0x90DE04F58B425796ULL, 0x08E638C8384E2CCCULL, 
            0xFD24FCB05F548E80ULL, 0x6EBC2E42FC576EFCULL, 0xCAE867AC9569E0A1ULL, 0x78B230188F107A3CULL, 
            0xF582E10FF299A6A6ULL, 0xF5FCAE88A7A888E8ULL, 0xFD32A7A6FB35E3B0ULL, 0xE44919BE6E73EB35ULL, 
            0x80A2EEAB801A4FBFULL, 0xFD2397DD86EFE60DULL, 0xE55BD77599F2B776ULL, 0x97106DB126D4E023ULL, 
            0xE5EFBDC1BA6E8BDCULL, 0x001833486BACF294ULL, 0xA9DBADF7D34EAEAFULL, 0x63A9B1CADDAB1733ULL, 
            0x92447117CE7FF784ULL, 0xFB4FB9FFEEEE8B91ULL, 0xDA41D9CB28C9E7E1ULL, 0x02337233B2CC3C90ULL, 
            0xEF79919CDF134622ULL, 0x53C5A839C7EE0A74ULL, 0x593EE44ABBFAF03EULL, 0x0C734773C609E1CCULL, 
            0x095494CAD8F0A770ULL, 0xF7AEB99DB6E721C3ULL, 0xFD6BB91B23E0BD48ULL, 0x18C65BB5DEAA678EULL
        }
    },
    {
        {
            0x62DB76CC1B54D1CBULL, 0x96AF4C7F351B01AAULL, 0x37D583B94F96CAF0ULL, 0x8C07516E810F32AEULL, 
            0xCF363E50A7B88255ULL, 0x1C0A6B9E5837B8B9ULL, 0x8DD9423677709616ULL, 0xBFF6CC8223D05C21ULL, 
            0xCBBBB52C5389400CULL, 0x2E0B52D9607C53A4ULL, 0x49CECFC293EED764ULL, 0x9602949CE1441487ULL, 
            0xFE82DB49573E444FULL, 0xF4C83C643963FEF2ULL, 0x1347A811B35ED76EULL, 0x30A0B4C1216A2835ULL, 
            0xFF41E2012F8150FCULL, 0xCEF2CC6639CA92E1ULL, 0x6645723DFF3C9253ULL, 0xE2F1B1910BE086DAULL, 
            0xE24D051D1BB36448ULL, 0xAED0D1E02B9B2446ULL, 0x4C7C4EE63AC8226BULL, 0x9047140A610AA43AULL, 
            0x9F3EB55223CD5EB8ULL, 0x05DF2051A87DB00CULL, 0x1B450C817C25E391ULL, 0x05F24AC3B0AAF5B4ULL, 
            0xFFC2E1541B40E5DFULL, 0x8C9F8B833ADF9895ULL, 0x6183938CB3C1D63BULL, 0xA0D0A76A71464C3CULL
        },
        {
            0x2D104CF6AD54FA23ULL, 0x896E872D2A5C343DULL, 0x7E482ED18D09CC3FULL, 0xD7BBEE0ADD714FF5ULL, 
            0x1056DED37732EB8AULL, 0xAA0C13711BFB7BCEULL, 0xDAD72D2EDF581839ULL, 0x6152769772D39246ULL, 
            0xF6576A7C1C67739BULL, 0xB16A2FBD8C3E54BCULL, 0xDA96A10B70709EF1ULL, 0xDF6C8556D9CD7B54ULL, 
            0x5CCCD5222BB47BC8ULL, 0x1F6D5F7262BA2705ULL, 0x0E6B512585ACA389ULL, 0xDA3E8276873A093FULL, 
            0x5CB9CAD2FA958B5CULL, 0x5FEFA8FEB0097C1EULL, 0x50A6B1F2EA5E3102ULL, 0xF8FFDF559FA3A605ULL, 
            0xA8E32DBDB6D319CDULL, 0x92DB173360CF9E6FULL, 0x75BC5E67CA9741BCULL, 0x860FA65DFA681837ULL, 
            0x8F6A5B0DFC7DA992ULL, 0xADDAE09B0C1BCAFBULL, 0x972EB999CED5BE80ULL, 0xB86A2E1BCF379F41ULL, 
            0x499D557C9767ABFBULL, 0xF0CE8B96244B03DEULL, 0x1A224618A0EE47CAULL, 0xFAA496288DF9942BULL
        },
        {
            0xEB6CD7FF626A5AB0ULL, 0x90FD4A7E2520F057ULL, 0x1881863E992803E0ULL, 0x5D89E8769285265AULL, 
            0x54462D0AD95CA8EAULL, 0xA0EF42CFF4C78C25ULL, 0x0866BA2739986EF9ULL, 0x78ED2954E1208E19ULL, 
            0x8F70DF90B07EF636ULL, 0xA81B8233BCA8A6DFULL, 0x11CB5E7660CA924AULL, 0x262B41D0C92E0BCEULL, 
            0x6185F3E693ADE404ULL, 0xC31FD036AEE4F3A9ULL, 0xF098CDD14896A33DULL, 0xFC83088E6F558536ULL, 
            0xE728370EE973F6D6ULL, 0xE5F1AAF4E1584CC7ULL, 0x9EEAB8A044A27AD9ULL, 0xDB1ACE073CE81166ULL, 
            0x61D2640E54F3FD5EULL, 0x9EF30AE1AE5E0EA0ULL, 0xDB434DA807401122ULL, 0x7BD86B5849AFA548ULL, 
            0x9C91C09F6056F367ULL, 0x80A94024FB265607ULL, 0xA3CEBBCDDEB0FDA3ULL, 0xDFB738F60A2F91C7ULL, 
            0x5F333029AABE9CD5ULL, 0xB61432FF651FC7D3ULL, 0x44FD25982922E78FULL, 0x99633243A9AFEC0AULL
        },
        {
            0x10DD21BFAA4735A7ULL, 0x91D59121120764D2ULL, 0x553D82E8A5B7F126ULL, 0x17FAF6DFC5EEEF36ULL, 
            0xE01FABD9F41031D0ULL, 0x28E32BCC6D495C12ULL, 0x6FCC111A880209D9ULL, 0x8869752D87A3C11AULL, 
            0x09D7EE441B081E53ULL, 0x041F192C84FCB691ULL, 0xB5B7CBFD3EA9A4F1ULL, 0x3A98C6704EE049BDULL, 
            0xEB9C1021A7B1D89AULL, 0xD712655F2D1034A8ULL, 0x13AAC2220B948362ULL, 0x0F5BD82AB29FCCBEULL, 
            0x49E8FF0E745B8448ULL, 0x39353A11E9B60A8AULL, 0xE509FA0BE3FCA904ULL, 0x72AC28ACE4A6912AULL, 
            0x3859A25057C03423ULL, 0x80F3E3A1CE0B9F8AULL, 0xEA63258504BE0AD9ULL, 0x0F4E1E51C8FAD24BULL, 
            0xD8A7E410114B97BBULL, 0x9E98CF146CD06106ULL, 0x895E04D840E1987CULL, 0x1E1C01F798138591ULL, 
            0x3814242C5D0EEEF1ULL, 0x21C80F610AC26DCEULL, 0x4F1BE3F063360A41ULL, 0x1205FF9B70A37B68ULL
        },
        {
            0x41B140EAD0BA253EULL, 0xE70857B4292C068EULL, 0x5C7B0888AF560D9DULL, 0x5392367A529523CCULL, 
            0xCC4F8AA5216BF0DAULL, 0x16F868AE8586A574ULL, 0x20B4D39C6A8D0B52ULL, 0x99EAB5D7571132FAULL, 
            0x13487B17A1C8559FULL, 0xCEC252EA8F2EDBECULL, 0xE1F82CAF98976A6FULL, 0x32EA6ECAB1C08AFBULL, 
            0xD084D7481E525E66ULL, 0x19B7416C1D1C2005ULL, 0xA8D096076E470633ULL, 0x755B4E97FB2E3BBDULL, 
            0x445402B59E1C2E06ULL, 0x844668867BBD94EBULL, 0x2215D0882F4C0A51ULL, 0x8A0D75A4A2B467BAULL, 
            0x82789A53B0408538ULL, 0x0640C3DB8A626334ULL, 0xF1DB8D1A0878AC07ULL, 0x4280E5CF3E06DA32ULL, 
            0xF936AF0C097B11CFULL, 0xB6565582CAF24867ULL, 0x56DC5680CC873407ULL, 0xED9A52129B38C073ULL, 
            0xB9E808A5644022F6ULL, 0xFBE4E0D7B3801A9AULL, 0x9640671A2FD9D436ULL, 0xAA1FB6C4279EE0E7ULL
        },
        {
            0x1EB48A294C2ACFA7ULL, 0x8144B2F46A607A72ULL, 0x03D25C0023A3EB07ULL, 0xA5A8877019494DB7ULL, 
            0xC76DCD5D286CA811ULL, 0x07F37462B55B2E24ULL, 0x0D403E5109E7A6BEULL, 0x86CEBF0EAB64D312ULL, 
            0x061CB9A1B3734AECULL, 0x8C4B287363DA09CEULL, 0xF55146D428F6F66DULL, 0x8DA98C63BD2F549EULL, 
            0xB6C740DED5EC5065ULL, 0x4B84965379ED75C7ULL, 0xBD07BA33B151F767ULL, 0xB8D250D975BF915BULL, 
            0xF4699A6882DA09EDULL, 0x388FCA971D0864CFULL, 0xEFC7288B41825AD6ULL, 0xFB1CB209695981CCULL, 
            0x54628CFD60C384CBULL, 0x2C0C0AD516AE0B2BULL, 0xCF0580183292A178ULL, 0x0117CFEBDE4EC6D3ULL, 
            0xE6A9A49F8BAEA924ULL, 0xD8B5C39A7E3C8FF0ULL, 0x8CA155392795C581ULL, 0xF4C5AE8769582D68ULL, 
            0xC05A7748BEAA8725ULL, 0xA39E7EE7771C2ACFULL, 0xA94B8185666D7929ULL, 0x496C501C76155275ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseHConstants = {
    0x1AC3E33EA109E61BULL,
    0x5A76A53B4DA7A006ULL,
    0xF24793CA13B793ECULL,
    0x1AC3E33EA109E61BULL,
    0x5A76A53B4DA7A006ULL,
    0xF24793CA13B793ECULL,
    0xBDF04DE648061DF2ULL,
    0xF73084D2BBDD5831ULL,
    0x0A,
    0xB1,
    0xFB,
    0x6C,
    0x72,
    0xE7,
    0xB7,
    0x14
};

